#include <iostream>
#include <cmath>

using namespace std;

// Nokta sınıfı
class Nokta {
private:
    double x, y;

public:
    // Parametresiz yapıcı
    Nokta() : x(0), y(0) {}

    // Tek parametreli yapıcı
    Nokta(double val) : x(val), y(val) {}

    // İki parametreli yapıcı
    Nokta(double xVal, double yVal) : x(xVal), y(yVal) {}

    // Başka bir noktanın kopyasıyla yapılandırıcı
    Nokta(const Nokta &other) : x(other.x), y(other.y) {}

    // Başka bir nokta ve ofset ile yapılandırıcı
    Nokta(const Nokta &other, double offset_x, double offset_y)
        : x(other.x + offset_x), y(other.y + offset_y) {}

    // Getter ve setter metotları
    double getX() const { return x; }
    void setX(double val) { x = val; }

    double getY() const { return y; }
    void setY(double val) { y = val; }

    void set(double xVal, double yVal) {
        x = xVal;
        y = yVal;
    }

    // x ve y koordinatlarını aynı anda değiştiren metot
    void set(double val) {
        x = val;
        y = val;
    }

    // toString metodu
    string toString() const {
        return "(" + to_string(x) + ", " + to_string(y) + ")";
    }

    // ekrana koordinatları yazdıran metot
    void yazdir() const {
        cout << toString() << endl;
    }
};

// DogruParcasi sınıfı
class DogruParcasi {
private:
    Nokta p1, p2;

public:
    // İki uç noktalı yapıcı
    DogruParcasi(const Nokta &point1, const Nokta &point2)
        : p1(point1), p2(point2) {}

    // Başka bir DogruParcasi'nin kopyasıyla yapılandırıcı
    DogruParcasi(const DogruParcasi &other)
        : p1(other.p1), p2(other.p2) {}

    // Nokta, uzunluk ve eğim alarak yapılandırıcı
    DogruParcasi(const Nokta &center, double length, double slope) {
        // İlgili hesaplamaları yapın ve p1, p2'yi ayarlayın
    }

    // Getter ve setter metotları
    const Nokta& getP1() const { return p1; }
    void setP1(const Nokta &point) { p1 = point; }

    const Nokta& getP2() const { return p2; }
    void setP2(const Nokta &point) { p2 = point; }

    // uzunluk metodu
    double uzunluk() const {
        // Uzunluğu hesaplayın ve döndürün
        return sqrt(pow(p2.getX() - p1.getX(), 2) + pow(p2.getY() - p1.getY(), 2));
    }

    // ortaNokta metodu
    Nokta ortaNokta() const {
        // Orta noktayı hesaplayın ve döndürün
        double ortaX = (p1.getX() + p2.getX()) / 2;
        double ortaY = (p1.getY() + p2.getY()) / 2;
        return Nokta(ortaX, ortaY);
    }

    // toString metodu
    string toString() const {
        return p1.toString() + " -> " + p2.toString();
    }

    // ekrana yazdıran metot
    void yazdir() const {
        cout << toString() << endl;
    }
};

// Daire sınıfı
class Daire {
private:
    Nokta merkez;
    double yaricap;

public:
    // Merkez ve yarıçaplı yapıcı
    Daire(const Nokta &center, double radius)
        : merkez(center), yaricap(radius) {}

    // Başka bir Daire'nin kopyasıyla yapılandırıcı
    Daire(const Daire &other)
        : merkez(other.merkez), yaricap(other.yaricap) {}

    // Başka bir Daire, reel pozitif x değeri alarak yapılandırıcı
    Daire(const Daire &other, double x)
        : merkez(other.merkez), yaricap(other.yaricap * x) {}

    // alan metodu
    double alan() const {
        // Alanı hesaplayın ve döndürün
        return M_PI * pow(yaricap, 2);
    }

    // cevre metodu
    double cevre() const {
        // Çevreyi hesaplayın ve döndürün
        return 2 * M_PI * yaricap;
    }

    // kesisim metodu
    int kesisim(const Daire &other) const {
        // Kesişim durumunu kontrol edin ve sonucu döndürün (0, 1 veya 2)
        double uzaklik = sqrt(pow(other.merkez.getX() - merkez.getX(), 2) +
                              pow(other.merkez.getY() - merkez.getY(), 2));

        if (uzaklik == 0 && yaricap == other.yaricap) {
            // Daireler birbirine eşit
            return 0;
        } else if (uzaklik < abs(yaricap - other.yaricap)) {
            // Bir daire diğerini içeriyor
            return 1;
        } else if (uzaklik == abs(yaricap - other.yaricap)) {
            // Daireler birbirine değiyor
            return 1;
        } else if (uzaklik < yaricap + other.yaricap) {
            // Daireler kesişiyor
            return 2;
        } else {
            // Daireler birbirinden uzak
            return 2;
        }
    }

    // toString metodu
    string toString() const {
        return "Merkez: " + merkez.toString() + ", Yarıçap: " + to_string(yaricap);
    }

    // ekrana yazdıran metot
    void yazdir() const {
        cout << toString() << endl;
    }
};

// Ucgen sınıfı
class Ucgen {
private:
    Nokta nokta1, nokta2, nokta3;

public:
    // Üç noktalı yapıcı
    Ucgen(const Nokta &point1, const Nokta &point2, const Nokta &point3)
        : nokta1(point1), nokta2(point2), nokta3(point3) {}

    // Getter ve setter metotları
    const Nokta& getNokta1() const { return nokta1; }
    void setNokta1(const Nokta &point) { nokta1 = point; }

    const Nokta& getNokta2() const { return nokta2; }
    void setNokta2(const Nokta &point) { nokta2 = point; }

    const Nokta& getNokta3() const { return nokta3; }
    void setNokta3(const Nokta &point) { nokta3 = point; }

    // toString metodu
    string toString() const {
        return "Üçgen; " + nokta1.toString() + ", " + nokta2.toString() + ", " + nokta3.toString();
    }

    // alan metodu
    double alan() const {
        // Alanı hesaplayın ve döndürün
        return abs((nokta1.getX() * (nokta2.getY() - nokta3.getY()) +
                    nokta2.getX() * (nokta3.getY() - nokta1.getY()) +
                    nokta3.getX() * (nokta1.getY() - nokta2.getY())) / 2);
    }

    // cevre metodu
    double cevre() const {
        // Çevreyi hesaplayın ve döndürün
        DogruParcasi dp1(nokta1, nokta2);
        DogruParcasi dp2(nokta2, nokta3);
        DogruParcasi dp3(nokta3, nokta1);
        return dp1.uzunluk() + dp2.uzunluk() + dp3.uzunluk();
    }

    // acilar metodu
    double* acilar() const {
        // Açıları hesaplayın ve döndürün (örneğin, bir double dizisi olarak)
        double a = sqrt(pow(nokta2.getX() - nokta3.getX(), 2) + pow(nokta2.getY() - nokta3.getY(), 2));
        double b = sqrt(pow(nokta3.getX() - nokta1.getX(), 2) + pow(nokta3.getY() - nokta1.getY(), 2));
        double c = sqrt(pow(nokta1.getX() - nokta2.getX(), 2) + pow(nokta1.getY() - nokta2.getY(), 2));

        double *angles = new double[3];

        angles[0] = acos((b*b + c*c - a*a) / (2*b*c)) * 180 / M_PI;
        angles[1] = acos((a*a + c*c - b*b) / (2*a*c)) * 180 / M_PI;
        angles[2] = acos((a*a + b*b - c*c) / (2*a*b)) * 180 / M_PI;

        return angles;
    }
};

// Test kodu
int main() {
    setlocale(LC_ALL, "Turkish");

    // Nokta sınıfı için test
    cout << "NOKTA SINIFI İÇİN TEST ÇIKTILARI:" << endl;
    Nokta n1;
    Nokta n2(5);
    Nokta n3(3, 4);
    Nokta n4(n3);
    Nokta n5(n3, 1, -1);

    cout << "Oluşturulan 5 noktanın x ve y değerleri:" << endl;
    n1.yazdir();
    n2.yazdir();
    n3.yazdir();
    n4.yazdir();
    n5.yazdir();

    cout << "1. ve 2. noktaların güncel x ve y değerleri:" << endl;
    n1.setX(10);
    n1.yazdir();
    n2.set(25, 30);
    n2.yazdir();

    // DogruParcasi sınıfı için test
    cout << endl << "DOGRUPARCASI SINIFI İÇİN TEST SONUÇLARI:" << endl;
    Nokta n11;
    Nokta n21(3, 4);
    DogruParcasi dp(n11, n21);
    DogruParcasi dp2(dp);
    DogruParcasi dp3(n21, 10, 45);

    cout << "Oluşturulan 3 doğru parçasının başlangıç ve bitiş noktaları:" << endl;
    dp.yazdir();
    dp2.yazdir();
    dp3.yazdir();

    cout << "2. doğru parçasının başlangıç ve bitiş noktaları:" << endl;
    dp2.setP1(Nokta());
    dp2.yazdir();

    cout << "1. doğru parçası için uzunluk değeri: " << dp.uzunluk() << endl;
    cout << "1. doğru parçası içib orta nokta: " << dp.ortaNokta().toString() << endl;

    // Daire sınıfı için test
    cout << endl << "DAIRE SINIFI İÇİN TEST SONUÇLARI:" << endl;
    Nokta merkez1(0, 0);
    Daire d1(merkez1, 5);
    Daire d2(d1);
    Daire d3(d2, 3);

    cout << "Daire 1: ";
    d1.yazdir();
    cout << "Alan: " << d1.alan() << ", Çevre: " << d1.cevre() << endl;

    cout << "Daire 2: ";
    d2.yazdir();
    cout << "Alan: " << d2.alan() << ", Çevre: " << d2.cevre() << endl;

    cout << "Daire 3: ";
    d3.yazdir();
    cout << "Alan: " << d3.alan() << ", Çevre: " << d3.cevre() << endl;

    cout << "Daire 1 ve Daire 2 Kesişim Durumu: " << d1.kesisim(d2) << endl;
    cout << "Daire 1 ve Daire 3 Kesişim Durumu: " << d1.kesisim(d3) << endl;

    // Ucgen sınıfı için test
    cout << endl << "UCGEN SINIFI İÇİN TEST SONUÇLARI:" << endl;
    Ucgen ucgen(Nokta(0, 0), Nokta(4, 0), Nokta(0, 3));

    cout << ucgen.toString() << endl;
    cout << "Alan: " << ucgen.alan() << endl;
    cout << "Çevre: " << ucgen.cevre() << endl;

    double *acilar = ucgen.acilar();
    cout << "Açılar: " << acilar[0] << ", " << acilar[1] << ", " << acilar[2] << endl;


    return 0;
}
