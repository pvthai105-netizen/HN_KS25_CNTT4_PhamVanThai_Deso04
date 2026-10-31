#include<stdio.h>
#include<string.h>
#define MAX_SIZE 50

typedef struct {
    int maHang;
    char tenHang[50];
    int soLuong;
    float donGia;
}Product;

int searchIndex(Product ds[], int currentLength, int maHang){
    int i;
    for (i = 0; i < currentLength; i++)
    {
        if(ds[i].maHang == maHang){
            return currentLength;
        }
    }
    return -1;
    
}

int addProduct(Product ds[], int currentLength){
    if(currentLength >= MAX_SIZE){
        printf("Danh sach da day\n");
        return currentLength;
    }
    getchar();
    Product product;
    printf("Nhap ma can them: ");
    scanf("%d", &product.maHang);
    if(searchIndex(ds, currentLength, product.maHang) != -1){
        printf("Ma mat hang da ton tai\n");
        return currentLength;
    }
    getchar();
    printf("Nhap ten hang: ");
    fgets(product.tenHang, sizeof(product.tenHang), stdin);
    product.tenHang[strcspn(product.tenHang, "\n")] = '\0';
    
    do
    {
        printf("Nhap so luong: ");
        scanf("%d", &product.soLuong);
        if (product.soLuong<0)
        {
            printf("So luong khong the am \n");
        }
    } while (product.soLuong<0);
    
    do
    {
        printf("Nhap don gia: ");
        scanf("%f", &product.donGia);
        if(product.donGia <= 0){
            printf("Don gia khong hop le\n");
        }
    } while (product.donGia <= 0);
    
    ds[currentLength] = product;
    currentLength++;
    printf("Them mat hang thanh cong\n");
    return currentLength;
}

void display(Product ds[], int currentLength){
    if (currentLength == 0)
    {
        printf("Danh sach da day");
        return;
    }
    int i; 
    printf("%-5s | %-40.40s | %-10s | %-12s | %-15s\n",
    "Ma", "Ten mat hang", "So luong", "Don gia", "Thanh tien");
    for (i = 0; i < currentLength; i++)
    {
        printf("%-5d | %-40.40s | %-10d | %-12.0f | %-15.0f\n",
        ds[i].maHang,
        ds[i].tenHang,
        ds[i].soLuong,
        ds[i].donGia,
        ds[i].soLuong * ds[i].donGia);
    }
}

void updateProduct(Product ds[], int currentLength){
    if (currentLength ==  0)
    {
        printf("Danh sach trong\n");
        return;
    }
    int maHang, timvt;
    printf("Nhap ma hang can cap nhat: ");
    scanf("%d", &maHang);
    timvt = searchIndex(ds, currentLength, maHang);
    if(timvt == -1){
        printf("Khong tim thay mat hang\n");
        return;
    }
    getchar();
    printf("Nhap ten hang: ");
    fgets(ds[timvt].tenHang, sizeof(ds[timvt].tenHang), stdin);
    ds[timvt].tenHang[strcspn(ds[timvt].tenHang, "\n")] = '\0';
    
    do
    {
        printf("Nhap so luong: ");
        scanf("%d", &ds[timvt].soLuong);
        if (ds[timvt].soLuong<0)
        {
            printf("So luong khong the am \n");
        }
    } while (ds[timvt].soLuong<0);
    
    do
    {
        printf("Nhap don gia: ");
        scanf("%f", &ds[timvt].donGia);
        if (ds[timvt].donGia <= 0)
        {
            printf("Don gia khong hop le\n");
        }
    } while (ds[timvt].donGia <= 0);
    printf("Cap nhat thanh cong\n");
}

int deleteProduct(Product ds[], int currentLength){
    if (currentLength ==  0)
    {
        printf("Danh sach trong\n");
        return currentLength;
    }
    int maHang, timvt, i;
    printf("Nhap ma hang can xoa: ");
    scanf("%d", &maHang);
    timvt = searchIndex(ds, currentLength, maHang);
    if(timvt == -1){
        printf("Khong tim thay mat hang\n");
        return currentLength ;
    }
    for (i = timvt; i < currentLength - 1; i++)
    {
        ds[i] = ds[i+1];
    }
    currentLength--;
    printf("Xoa thanh cong\n");
    return currentLength;
}

void searchProduct(Product ds[], int currentLenght){
    if (currentLenght == 0)
    {
        printf("Danh sach rong\n");
        return;
    }
    int i;
    char tenHang[50];
    int found = 0;
    printf("Nhap ten hang can tim: ");
    fgets(tenHang, sizeof(tenHang), stdin);
    tenHang[strcspn(tenHang, "\n")] = '\0';

    for (i = 0; i < currentLenght; i++)
    {
        if(strcmp(ds[i].tenHang, tenHang) == 0){
            printf("- Ma: %d, Ten hang: %s, So luong: %d, Don gia: %.0f, Thanh tien: %.0f\n",
            ds[i].maHang, ds[i].tenHang, ds[i].soLuong, ds[i].donGia, ds[i].soLuong * ds[i].donGia);
            found = 1;
        }
    }
    if (!found)
    {
        printf("Khong tim thay mat hang\n");
    }
}


void reportProduct(Product ds[], int currentLength){
    if(currentLength == 0){
        printf("Danh sach rong\n");
        return;
    }
    float tongTien = 0;
    int vtMax = 0;
    int dshet = 0, i;
    for (i = 0; i < currentLength; i++)
    {
        tongTien += ds[i].donGia * ds[i].soLuong;
        if (ds[i].soLuong < 5) dshet++;
        if (ds[vtMax].donGia * ds[vtMax].soLuong < ds[i].donGia * ds[i].soLuong)
        {
            vtMax = i;
        }
    }
    printf("Tong tien: %.0f\n", tongTien);
    printf("San pham sap het: %d\n", dshet);
    printf("San pham co thanh tien lon nhat: %s\n", ds[vtMax].tenHang);
}

int main(void){
    Product ds[MAX_SIZE];
    int currentLength = 0;
    int choice;
    do
    {
        printf("===== QUAN LY MAT HANG =====\n");
        printf("1. Them mot mat hang\n");
        printf("2. Hien thi danh sach mat hang\n");
        printf("3. Cap nhat mat hang theo ma\n");
        printf("4. Xoa mat hang theo ma\n"); 
        printf("5. Tim mat hang theo ten\n");
        printf("6. Thong ke kho hang\n");
        printf("0.Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);
        if(choice >= 2 && choice <= 6 && currentLength == 0){
            printf("Danh sach rong\n");
            continue;
        }
        switch (choice)
        {
        case 1:
            currentLength = addProduct(ds, currentLength);
            break;
        case 2:
            display(ds, currentLength);
            break;
        case 3:
            updateProduct(ds, currentLength);
            break;
        case 4:
            currentLength = deleteProduct(ds, currentLength);
            break;
        case 5:
            searchProduct(ds, currentLength);
            break;
        case 6:
            printf("Bao cao san pham\n");
            reportProduct(ds, currentLength);
            break;
        case 0:
            printf("Tam biet!\n\n");
            break;
        default:
            printf("Lua chon khong hop le!\n");
            break;
        }
    } while (choice != 0);
    return 0;
}