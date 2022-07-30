import java.util.*;
import java.net.*;
public class InetAddressTest {
    public static void main(String[] args) throws Exception{
        InetAddress address = InetAddress.getLocalHost();
        System.out.println("local " + address.getHostName());
        System.out.println("IPaddress " + address.getHostAddress());
        byte[] bytes = address.getAddress();
        System.out.println("arrayIPaddress " + Arrays.toString(bytes));
        System.out.println("InetAddressObject " + address);
    }
}