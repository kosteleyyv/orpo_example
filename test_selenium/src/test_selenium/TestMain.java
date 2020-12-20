package test_selenium;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.firefox.FirefoxDriver;
import org.openqa.selenium.support.ui.ExpectedCondition;
import org.openqa.selenium.support.ui.WebDriverWait;

public class TestMain  {
    public static void main(String[] args) {
        // Создаем экземпляр WebDriver
        // Следует отметить что скрипт работает с интерфейсом,
        // а не с реализацией.
    	
    	System.setProperty("webdriver.gecko.driver", "C:\\Users\\User\\eclipse-workspace\\test_selenium\\geckodriver.exe");
    	
        WebDriver driver = new FirefoxDriver();

        // Открываем гугл, используя драйвер
        driver.get("http://www.google.com");

        // Находим элемент по атрибуту name
        WebElement element = driver.findElement(By.name("q"));

        // Вводим текст
        element.sendKeys("тусур з-37");

        // Отправляем форму, при этом дравер сам определит, как отправить форму по элементу
        element.submit();

        // Проверяем заголовок страницы
        System.out.println("Page title is: " + driver.getTitle());
        
        // Ждем загрузки страницы с таймаутом в 10 секунд
        (new WebDriverWait(driver, 10)).until(new ExpectedCondition<Boolean>() {
            public Boolean apply(WebDriver d) {
                return d.getTitle().toLowerCase().startsWith("тусур з-37");
            }
        });
        
        // Ожидаем увидеть: "тусур з-37- Google Search"
        System.out.println("Page title is: " + driver.getTitle());
        
        
        try {
        	System.out.println("Sleep 10 sec....");
			Thread.sleep(10000);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
        // Закрываем браузер
        driver.quit();
    }
}
