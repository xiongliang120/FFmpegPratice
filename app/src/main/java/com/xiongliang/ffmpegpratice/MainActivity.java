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

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        decodeAudioButton = findViewById(R.id.decodeAudioButton);
        devodeVideoButton = findViewById(R.id.decodeVideoButton);
        decodeAudioButton.setOnClickListener(clickListener);
        devodeVideoButton.setOnClickListener(clickListener);
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
