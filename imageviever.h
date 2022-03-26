#ifndef IMAGEVIEVER_H
#define IMAGEVIEVER_H

#include <QMainWindow>
#include <QLabel>
#include <QScrollArea>
#include <QImage>
#include <QFileDialog>
#include <QMenu>
#include <QMenuBar>
#include <QPixmap>
#include <QVBoxLayout>
#include <QPrintDialog>
#include <QPrinter>
#include <QPainter>


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

    QLabel* imageLabel;
    QImage* currentImage;

    QString openedFilePath;

    QScrollArea * scrollArea;


private slots:
    void openImage();
    void saveAs();
    void print();
};
#endif // IMAGEVIEVER_H
