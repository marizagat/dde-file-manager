#ifndef FILEITEM_H
#define FILEITEM_H

#include <QLabel>
#include "progressline.h"

QT_BEGIN_NAMESPACE
class QTextEdit;
class QGraphicsOpacityEffect;
QT_END_NAMESPACE

class FileIconItem : public QFrame
{
    Q_OBJECT

    Q_PROPERTY(QColor borderColor READ borderColor WRITE setBorderColor NOTIFY borderColorChanged)

public:
    explicit FileIconItem(QWidget *parent = 0);

    void setOpacity(qreal opacity);

    QSize sizeHint() const Q_DECL_OVERRIDE;

    inline QLabel* getIconLabel() const
    { return icon; }
    inline QTextEdit* getTextEdit() const
    { return edit; }
    inline ProgressLine* getProgressLine()
    { return progressLine; }

    QColor borderColor() const;

public slots:
    void setBorderColor(QColor borderColor);

signals:
    void inputFocusOut();
    void borderColorChanged(QColor borderColor);

protected:
    bool event(QEvent *ee) Q_DECL_OVERRIDE;
    bool eventFilter(QObject *obj, QEvent *ee) Q_DECL_OVERRIDE;

private:
    void updateEditorGeometry();
    void updateStyleSheet();

    bool canDeferredDelete = true;
    QLabel *icon;
    QTextEdit *edit;
    ProgressLine* progressLine;
    QGraphicsOpacityEffect *opacityEffect = Q_NULLPTR;
    QColor m_borderColor;

    friend class DIconItemDelegate;
    friend class DFileView;
    friend class DFileViewHelper;
};

#endif // FILEITEM_H
