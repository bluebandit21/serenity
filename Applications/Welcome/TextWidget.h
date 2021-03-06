/*
 * Copyright (c) 2018-2020, Andreas Kling <kling@serenityos.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#include <AK/String.h>
#include <AK/Vector.h>
#include <LibGUI/Frame.h>
#include <LibGfx/TextAlignment.h>

class TextWidget : public GUI::Frame {
    C_OBJECT(TextWidget)
public:
    explicit TextWidget(GUI::Widget* parent = nullptr);
    TextWidget(const StringView& text, GUI::Widget* parent = nullptr);
    virtual ~TextWidget() override;

    String text() const { return m_text; }
    void set_text(const StringView&);

    Gfx::TextAlignment text_alignment() const { return m_text_alignment; }
    void set_text_alignment(Gfx::TextAlignment text_alignment) { m_text_alignment = text_alignment; }

    bool should_wrap() const { return m_should_wrap; }
    void set_should_wrap(bool should_wrap) { m_should_wrap = should_wrap; }

    int line_height() const { return m_line_height; }
    void set_line_height(int line_height) { m_line_height = line_height; }

    void wrap_and_set_height();

private:
    virtual void paint_event(GUI::PaintEvent&) override;
    virtual void resize_event(GUI::ResizeEvent&) override;

    String m_text;
    Vector<String> m_lines;
    Gfx::TextAlignment m_text_alignment { Gfx::TextAlignment::Center };
    bool m_should_wrap { false };
    int m_line_height { 0 };
};
