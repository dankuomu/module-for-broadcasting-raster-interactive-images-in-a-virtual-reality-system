// VRMouseClient.h
#pragma once

#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <system_error>
#include <memory>
#include <mutex>

#pragma comment(lib, "ws2_32.lib")

class VRMouseClient {
public:
    VRMouseClient();
    ~VRMouseClient();

    // �������� ����������� � �����������
    bool SendImage(const std::string& imageData);

    // ����������� � ������� ����������
    bool Connect(const std::string& host, int port);

    // �������� ������� ����
    bool SendMouseEvent(const std::string& eventType, int x, int y);

    // �������� �����������
    bool IsConnected() const;

    // �������� ����������
    void Disconnect();

private:
    SOCKET m_socket;
    mutable std::recursive_mutex m_socketMutex;
    bool m_connected;

    // ������������� Winsock
    static void InitWinsock();

    // ������� Winsock
    static void CleanupWinsock();

    // ���������� ������� �������� ������
    bool SendData(const std::string& data);
};