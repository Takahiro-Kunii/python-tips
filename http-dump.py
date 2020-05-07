import http.server as SimpleHTTPServer
import socketserver as SocketServer

class GetHandler(SimpleHTTPServer.SimpleHTTPRequestHandler):

    def do_GET(self):
        print('GET=>')
        print(self.headers)
        print('requestline=>')
        print(self.requestline)
        super().do_GET()
    
    def do_HEAD(self):
        print('HEAD=>')
        print(self.headers)
        print('requestline=>')
        print(self.requestline)
        super().do_HEAD()

httpd = SocketServer.TCPServer(("", 8000), GetHandler)
httpd.serve_forever()

#   python http-dump.p
# で起動。終了したければControl-C
# 動きっぱなしになるので、別のターイナルウィンドウから以下を実行。
#   curl -X GET 'http://localhost:8000/test?a=1&b=2'
#   curl -I 'http://localhost:8000/test?a=1&b=2'