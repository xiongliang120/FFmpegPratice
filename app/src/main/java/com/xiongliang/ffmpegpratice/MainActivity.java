package com.xiongliang.ffmpegpratice;

import android.Manifest;
import android.content.pm.PackageManager;
import android.support.v4.app.ActivityCompat;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    static {
        System.loadLibrary("ffmpegpratice");
    }


    private static final int REQUEST_EXTERNAL_STORAGE = 1;
    private static String[] PERMISSIONS_STORAGE = {
            "android.permission.READ_EXTERNAL_STORAGE",
            "android.permission.WRITE_EXTERNAL_STORAGE" };

    private Button decodeAudioButton;
    private Button devodeVideoButton;
    private Button demuxAndDecode;
    private Button muxing;
    private Button demuxing;
    private Button metadata;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        decodeAudioButton = findViewById(R.id.decodeAudioButton);
        devodeVideoButton = findViewById(R.id.decodeVideoButton);
        demuxAndDecode = findViewById(R.id.demuxAndDecode);
        muxing = findViewById(R.id.muxing);
        demuxing = findViewById(R.id.demuxing);
        metadata = findViewById(R.id.metadata);
        decodeAudioButton.setOnClickListener(clickListener);
        devodeVideoButton.setOnClickListener(clickListener);
        demuxAndDecode.setOnClickListener(clickListener);
        muxing.setOnClickListener(clickListener);
        demuxing.setOnClickListener(clickListener);
        metadata.setOnClickListener(clickListener);
        checkPermission();

    }


    private View.OnClickListener clickListener = new View.OnClickListener() {
        @Override
        public void onClick(View view) {
            int id = view.getId();
            switch (id){
                case R.id.decodeAudioButton:
                    decodeAudio();
                    break;
                case R.id.decodeVideoButton:
                    decodeVideo();
                    break;
                case R.id.demuxAndDecode:
                    demuxAndDecode();
                    break;
                case R.id.muxing:
                    muxing();
                     break;
                case R.id.demuxing:
                    demuxing();
                    break;
                case R.id.metadata:
                    metadata();
                    break;
                default:
                    break;
            }
        }
    };


    public void decodeAudio(){
        DecodeAudio decodeAudio = new DecodeAudio();
        decodeAudio.devodeAudio("/sdcard/001.mp3","/sdcard/test.pcm");
    }

    public void decodeVideo(){
        DecodeVideo decodeVideo = new DecodeVideo();
        decodeVideo.devodeVideo("/sdcard/001.mp3","/sdcard/test.yuv");
    }

    public void demuxAndDecode(){
        DemuxAndDecode demuxAndDecode = new DemuxAndDecode();
        demuxAndDecode.demuxAndDecode("/sdcard/11.mp4","/sdcard/11.yuv","/sdcard/11.pcm");
    }

    public void muxing(){
        Muxing muxing = new Muxing();
        muxing.muxing("/sdcard/22.mp3","sdcard/22.h264","/sdcard/22.mp4");
    }

    public void demuxing(){
        Demuxing demuxing = new Demuxing();
        demuxing.demuxing("/sdcard/11.mp4","/sdcard/33.h264","/sdcard/33/mp3");
    }

    public void metadata(){
        Metadata metadata = new Metadata();
        metadata.metadata("/sdcard/test.mp4");
    }



    //读写权限
    private void checkPermission() {
        int permission = ActivityCompat.checkSelfPermission(this,
                Manifest.permission.WRITE_EXTERNAL_STORAGE);

        if (permission != PackageManager.PERMISSION_GRANTED) {
            // We don't have permission so prompt the user
            ActivityCompat.requestPermissions(this, PERMISSIONS_STORAGE,
                    REQUEST_EXTERNAL_STORAGE);
        }
    }


}
