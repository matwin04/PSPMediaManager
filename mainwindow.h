#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableView>
#include <QString>
#include <QSqlDatabase>
namespace Ui {
class mainWindow;
}

class mainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainWindow(QWidget *parent = nullptr);
    ~mainWindow();

private:
    Ui::mainWindow *ui;
    QSqlDatabase db;
    static QString pspMediaFolder;

    void setupDatabase();
    void createMediaFolder();
    void executeSql(const QString &filePath);
    void addFolder(const QString &folderName);
    void loadTableData(const QString &tableName,QTableView *tableView);
};

#endif // MAINWINDOW_H
