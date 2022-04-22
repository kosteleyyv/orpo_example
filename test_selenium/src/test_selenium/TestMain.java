package test_selenium;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.firefox.FirefoxDriver;
import org.openqa.selenium.support.ui.ExpectedCondition;
import org.openqa.selenium.support.ui.WebDriverWait;

public class TestMain  {
    public static void main(String[] args) {
        // ������� ��������� WebDriver
        // ������� �������� ��� ������ �������� � �����������,
        // � �� � �����������.
    	
    	System.setProperty("webdriver.gecko.driver", "D:\\1\\��������\\����\\geckodriver.exe");
    	
    	//������ � ������� ���� ���� �� ��������
    	//https://github.com/mozilla/geckodriver/releases
    	
        WebDriver driver = new FirefoxDriver();

        // ��������� ����, ��������� �������
        driver.get("http://www.google.com");

        // ������� ������� �� �������� name
        WebElement element = driver.findElement(By.name("q"));

        // ������ �����
        element.sendKeys("����� �-38");

        // ���������� �����, ��� ���� ������ ��� ���������, ��� ��������� ����� �� ��������
        element.submit();

        // ��������� ��������� ��������
        System.out.println("Page title is: " + driver.getTitle());
        
        // ���� �������� �������� � ��������� � 10 ������
        (new WebDriverWait(driver, 10)).until(new ExpectedCondition<Boolean>() {
            public Boolean apply(WebDriver d) {
                return d.getTitle().toLowerCase().startsWith("����� �-38");
            }
        });
        
        // ������� �������: "����� �-37- Google Search"
        System.out.println("Page title is: " + driver.getTitle());
        
        
        try {
        	System.out.println("Sleep 10 sec....");
			Thread.sleep(10000);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
        // ��������� �������
        driver.quit();
        
        //java -jar ourjar.jar
    }
}
