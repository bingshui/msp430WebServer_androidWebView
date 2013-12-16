package com.lofter.bingshui;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;
import android.webkit.WebView;
import android.widget.Button;
import android.widget.EditText;

public class MainActivity extends Activity {
	private Button open = null;
	private Button close = null;
	private WebView webView = null;
	static final String urlOne = "http://192.168.0.15/123456/3";
	static final String urlTwo = "http://192.168.0.15/123456/2";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        this.open = (Button) super.findViewById(R.id.open);         
        this.close = (Button) super.findViewById(R.id.close);
        this.webView = (WebView) super.findViewById(R.id.webView);
        webView.setBackgroundColor(0);
        this.open.setOnClickListener(new OpenOnClickListener());  
        this.close.setOnClickListener(new CloseOnClickListener()); 
    }

    private class OpenOnClickListener implements OnClickListener{

		@Override
		public void onClick(View v) {
			// TODO Auto-generated method stub
			MainActivity.this.webView.loadUrl(urlOne);
			
		}
    }
    
    private class CloseOnClickListener implements OnClickListener{

		@Override
		public void onClick(View v) {
			// TODO Auto-generated method stub
			MainActivity.this.webView.loadUrl(urlTwo);
			
		}	
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.main, menu);
        return true;
    }
    
}
