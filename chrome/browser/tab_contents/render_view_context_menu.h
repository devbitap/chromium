// Copyright (c) 2006-2008 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_RENDERER_HOST_RENDER_VIEW_CONTEXT_MENU_H_
#define CHROME_BROWSER_RENDERER_HOST_RENDER_VIEW_CONTEXT_MENU_H_

#include "chrome/views/menu.h"
#include "webkit/glue/context_node_types.h"

class Profile;

class RenderViewContextMenu : public Menu {
 public:
  RenderViewContextMenu(
      Menu::Delegate* delegate,
      HWND owner,
      ContextNode node,
      const std::wstring& misspelled_word,
      const std::vector<std::wstring>& misspelled_word_suggestions,
      Profile* profile);

  virtual ~RenderViewContextMenu();

 private:
  void InitMenu(ContextNode node);
  void AppendDeveloperItems();
  void AppendLinkItems();
  void AppendImageItems();
  void AppendPageItems();
  void AppendFrameItems();
  void AppendCopyItem();
  void AppendEditableItems();
  void AppendSearchProvider();

  std::wstring misspelled_word_;
  std::vector<std::wstring> misspelled_word_suggestions_;
  Profile* profile_;
  Menu* spellchecker_sub_menu_;

  DISALLOW_COPY_AND_ASSIGN(RenderViewContextMenu);
};

#endif  // CHROME_BROWSER_RENDERER_HOST_RENDER_VIEW_CONTEXT_MENU_H_

