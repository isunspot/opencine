#ifndef PLAYBACKPRESENTER_H
#define PLAYBACKPRESENTER_H

#include "Core/Context.h"

#include <Context.h>
#include <QObject>
#include <QTimer>

class PlaybackPresenter : public QObject
{
    Q_OBJECT

public:
    PlaybackPresenter(OCContext* context);
    ~PlaybackPresenter();

    void Play();
    void Pause();
    void Stop();

    void NextFrame();
    void PrevFrame();

    void SetFrame(unsigned int frame);

private:
    OCContext* _context;

    unsigned int _currentFrame;

    QTimer _timer;

signals:
    void SessionChanged(OCSession* session);
    void FrameChanged(unsigned int frameNumber/*, ImageData*/);

private slots:
    //void UpdateViews();
    void OnSessionChanged(OCSession* session);
};



#endif //PLAYBACKPRESENTER_H