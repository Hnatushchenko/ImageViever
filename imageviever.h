#ifndef IMAGEVIEVER_H
#define IMAGEVIEVER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ImageViever; }
QT_END_NAMESPACE

class ImageViever : public QMainWindow
{
    Q_OBJECT

public:
    ImageViever(QWidget *parent = nullptr);
    ~ImageViever();

private:
    Ui::ImageViever *ui;
};
#endif // IMAGEVIEVER_H
