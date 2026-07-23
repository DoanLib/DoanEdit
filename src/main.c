#include <dn/shared.h>
#include <dn/main.h>
#include <dn/app.h>
#include <dn/system.h>
#include <dn/raster.h>

// == APPLICATION =========================================================== //

typedef struct DnAppEdit {
  DnApp app;
  DnRasterTexture texture;
} DnEditApp;

bool DnAppEdit_Init(DnApp* app) {
  DnEditApp* editApp = (DnEditApp*)app;
  DN_ASSERT(editApp);

  i32 windowWidth = DnSysWindow_GetWidth(app->window);
  i32 windowHeight = DnSysWindow_GetHeight(app->window);
  if (!DnRasterTexture_Init(&editApp->texture, windowWidth, windowHeight)) {
    return false;
  }

  return true;
}

void DnAppEdit_Deinit(DnApp* app) {
  DnEditApp* editApp = (DnEditApp*)app;
  DN_ASSERT(editApp);

  DnRasterTexture_Deinit(&editApp->texture);
}

void DnAppEdit_Update(DnApp* app, f32 deltaTime) {
  DN_UNUSED(deltaTime);

  DnEditApp* editApp = (DnEditApp*)app;
  DN_ASSERT(editApp);
  DN_UNUSED(editApp);
}

void DnAppEdit_Render(DnApp* app, f32 alphaTime) {
  DN_UNUSED(alphaTime);

  DnEditApp* editApp = (DnEditApp*)app;
  DN_ASSERT(editApp);
  DN_UNUSED(editApp);
}

void DnAppEdit_OnResize(DnApp* app, i32 width, i32 height) {
  DN_UNUSED(app);
  DN_UNUSED(width);
  DN_UNUSED(height);
}

void DnAppEdit_OnClose(DnApp* app, bool* close) {
  DN_UNUSED(app);
  DN_UNUSED(close);
}

// == MAIN ================================================================== //

DN_DEFINE_MAIN_ENTRY() {
  DnEditApp editApp = {
    .app = {
      .init = DnAppEdit_Init,
      .deinit = DnAppEdit_Deinit,
      .update = DnAppEdit_Update,
      .render = DnAppEdit_Render,
      .onResize = DnAppEdit_OnResize,
      .onClose = DnAppEdit_OnClose,
    },
  };

  DnAppConfig config = {
    .windowTitle = DN_STR_VIEW_LITERAL("DoanEdit"),
    .windowWidth = 1024,
    .windowHeight = 576,
  };

  return DnApp_Run(&editApp.app, &config);
}
