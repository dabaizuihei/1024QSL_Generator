#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <limits>
#include <fstream>
#include <filesystem>

class QSLCard {
private:
    std::string myCallSign;
    std::string toCallSign;
    std::string dateTimeUTC;
    std::string qth;
    double frequency;
    double power;
    std::string equipment;
    std::string antenna;
    std::string mode;
    std::string signalReport;

public:
    QSLCard(const std::string& toCall) {
        myCallSign = "BH3HTA";
        toCallSign = toCall;
        dateTimeUTC = getCurrentDateTimeUTC();
        qth = "ON50UU (呼和浩特)"; // 梅登海格网格定位
        frequency = 2.4; // GHz
        power = 50; // W
        equipment = "Thinkpad";
        antenna = "Router default 2.4G/5G Antenna";
        mode = "TCP/IP";
        signalReport = "59";
    }

    // 获取当前UTC时间
    std::string getCurrentDateTimeUTC() {
        time_t now = time(0);
        tm* gmtm = gmtime(&now);
        
        char buffer[80];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M UTC", gmtm);
        return std::string(buffer);
    }

    // 检查是否是全球任意时区的10月24日
    bool isProgrammersDay() {
        time_t now = time(0);
        
        // 检查UTC时间
        tm* gmtm = gmtime(&now);
        bool isUTC1024 = (gmtm->tm_mon + 1 == 10 && gmtm->tm_mday == 24);
        
        // 检查本地时间
        tm* ltm = localtime(&now);
        bool isLocal1024 = (ltm->tm_mon + 1 == 10 && ltm->tm_mday == 24);
        
        return isUTC1024 || isLocal1024;
    }

    // 将呼号转换为大写
    static std::string formatCallSign(const std::string& callSign) {
        std::string result = callSign;
        std::transform(result.begin(), result.end(), result.begin(), ::toupper);
        return result;
    }

    // 显示简化的EYEBALL QSO标记 - 横着的方形印章样式
    void displayEyeballQSO(std::ostream& os = std::cout) {
        os << "  ╔══════════════════╗" << std::endl;
        os << "  ║   EYEBALL QSO    ║" << std::endl;
        os << "  ╚══════════════════╝" << std::endl;
    }

    // 显示两行式的Hello World ASCII艺术
    void displayHelloWorld(std::ostream& os = std::cout) {
        os << "8   8                                " << std::endl;
        os << "8   8 eeee e     e     eeeee  " << std::endl;
        os << "8eee8 8    8     8     8  88  " << std::endl;
        os << "88  8 8eee 8e    8e    8   8  " << std::endl;
        os << "88  8 88   88    88    8   8  " << std::endl;
        os << "88  8 88ee 88eee 88eee 8eee8  " << std::endl;
        os << std::endl;
        os << "8   8  8                          8  " << std::endl;
        os << "8   8  8 eeeee eeeee  e     eeeee 88 " << std::endl;
        os << "8e  8  8 8  88 8   8  8     8   8 88 " << std::endl;
        os << "88  8  8 8   8 8eee8e 8e    8e  8 88 " << std::endl;
        os << "88  8  8 8   8 88   8 88    88  8    " << std::endl;
        os << "88ee8ee8 8eee8 88   8 88eee 88ee8 88 " << std::endl;
    }

    // 显示VY 73 ASCII艺术
    void displayVY73(std::ostream& os = std::cout) {
        os << ":::     ::: :::   :::      :::::::::::  ::::::::  ::: " << std::endl;
        os << ":+:     :+: :+:   :+:      :+:     :+: :+:    :+: :+: " << std::endl;
        os << "+:+     +:+  +:+ +:+              +:+         +:+ +:+ " << std::endl;
        os << "+#+     +:+   +#++:              +#+       +#++:  +#+ " << std::endl;
        os << " +#+   +#+     +#+              +#+           +#+ +#+ " << std::endl;
        os << "  #+#+#+#      #+#             #+#     #+#    #+#     " << std::endl;
        os << "    ###        ###             ###      ########  ### " << std::endl;
    }

    // 显示QSL卡片的所有信息
    void generateCard(std::ostream& os = std::cout) {
        os << "\n==================================================" << std::endl;
        os << "          BH3HTA 1024纪念QSL卡片" << std::endl;
        os << "==================================================" << std::endl;
        
        // 显示EYEBALL QSO标记
        displayEyeballQSO(os);
        os << std::endl;
        
        os << std::left << std::setw(20) << "From:" << myCallSign << std::endl;
        os << std::left << std::setw(20) << "To:" << toCallSign << std::endl;
        os << std::left << std::setw(20) << "通联时间:" << dateTimeUTC << std::endl;
        os << std::left << std::setw(20) << "QTH:" << qth << std::endl;
        os << std::left << std::setw(20) << "频率:" << "2.4GHz/5GHz" << std::endl;
        os << std::left << std::setw(20) << "功率:" << power << "W" << std::endl;
        os << std::left << std::setw(20) << "模式:" << mode << std::endl;
        os << std::left << std::setw(20) << "信号报告:" << signalReport << std::endl;
        
        os << "--------------------------------------------------" << std::endl;
        os << "                设备信息" << std::endl;
        os << "--------------------------------------------------" << std::endl;
        os << std::left << std::setw(15) << "设备:" << equipment << std::endl;
        os << std::left << std::setw(15) << "天线:" << antenna << std::endl;
        os << std::left << std::setw(15) << "编程语言:" << "C++" << std::endl;
        os << std::left << std::setw(15) << "操作系统:" << "Linux" << std::endl;
        
        os << "--------------------------------------------------" << std::endl;
        os << "            来自BH3HTA的双重祝福" << std::endl;
        os << "--------------------------------------------------" << std::endl;
        
        // 显示Hello World ASCII艺术
        displayHelloWorld(os);
        os << std::endl;
        
        os << "愿代码无BUG，信号永畅通！" << std::endl;
        os << "在数字世界与电波世界中自由穿梭！" << std::endl;
        os << "Happy 1024!" << std::endl;
        
        // 显示VY 73 ASCII艺术
        os << std::endl;
        displayVY73(os);
        
        os << "==================================================" << std::endl;
    }
    
    // 保存QSL卡片到文件
    bool saveToFile(const std::string& filename) {
        std::ofstream file(filename);
        if (!file.is_open()) {
            return false;
        }
        
        generateCard(file);
        file.close();
        return true;
    }
};

int main() {
    std::cout << "BH3HTA 1024纪念QSL生成器" << std::endl;
    std::cout << "正在初始化验证系统..." << std::endl;
    
    // 创建临时卡片对象用于日期验证
    QSLCard tempCard("TEMP");
    
    // 检查是否是10月24日
    if (!tempCard.isProgrammersDay()) {
        // 获取当前UTC时间用于提示
        time_t now = time(0);
        tm* gmtm = gmtime(&now);
        char buffer[80];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M UTC", gmtm);
        
        std::cout << "\n==================================================" << std::endl;
        std::cout << "       抱歉，当前不是1024程序员节！" << std::endl;
        std::cout << "       当前UTC时间: " << buffer << std::endl;
        std::cout << "       请在10月24日（任何时区）运行此程序生成QSL卡片。" << std::endl;
        std::cout << "==================================================" << std::endl;
        
        // 按任意键退出
        std::cout << "\n按任意键退出..." << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
        return 0;
    }
    
    // 获取对方呼号并格式化为大写
    std::string toCallSign;
    std::cout << "请输入您的呼号: ";
    std::cin >> toCallSign;
    toCallSign = QSLCard::formatCallSign(toCallSign);
    
    std::cout << "\n正在生成1024纪念QSL卡片..." << std::endl;
    
    // 创建QSL卡片对象
    QSLCard myQSL(toCallSign);
    
    // 生成卡片到控制台
    myQSL.generateCard();
    
    // 获取当前工作目录并生成文件名
    std::filesystem::path currentPath = std::filesystem::current_path();
    std::string filename = "1024QSL To " + toCallSign + ".txt";
    std::filesystem::path fullPath = currentPath / filename;
    
    // 保存卡片到文件
    if (myQSL.saveToFile(fullPath.string())) {
        std::cout << "\nQSL卡片生成完成！" << std::endl;
        std::cout << "已生成文件: " << fullPath.string() << std::endl;
        std::cout << "文件保存在程序所在目录，您可以自行打印。" << std::endl;
    } else {
        std::cout << "\nQSL卡片生成完成！" << std::endl;
        std::cout << "但无法保存到文件，请检查目录权限。" << std::endl;
    }
    
    // 按任意键退出
    std::cout << "\n按任意键退出..." << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    
    return 0;
}