public class SocketServer {
    public static void main(String[] args) throws IOException {

        ServerSocket serverSocket = new ServerSocket(12345);
        InetAddress address = InetAddress.getLocalHost();
        String ip = address.getHostAddress();
        Socket socket = null;

        System.out.println("~~~service was actions. ~~~\nip:" + ip);
        socket = serverSocket.accept();

        InputStream is=null;
        InputStreamReader isr=null;
        BufferedReader br=null;
        OutputStream os=null;
        PrintWriter pw=null;
        is = socket.getInputStream();
        isr = new InputStreamReader(is,"UTF-8");
        br = new BufferedReader(isr);
        String info = null;
        while((info=br.readLine())!=null){
            System.out.println("clientsend:    " + info);
        }
        socket.shutdownInput();
        socket.close();
    }
}