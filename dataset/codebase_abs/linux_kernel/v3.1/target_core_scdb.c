void F_1 (
unsigned long long V_1 ,
T_1 V_2 ,
unsigned char * V_3 )
{
V_3 [ 1 ] = ( V_1 >> 16 ) & 0x1f ;
V_3 [ 2 ] = ( V_1 >> 8 ) & 0xff ;
V_3 [ 3 ] = V_1 & 0xff ;
V_3 [ 4 ] = V_2 & 0xff ;
}
void F_2 (
unsigned long long V_1 ,
T_1 V_2 ,
unsigned char * V_3 )
{
F_3 ( V_1 , & V_3 [ 2 ] ) ;
F_4 ( V_2 , & V_3 [ 7 ] ) ;
}
void F_5 (
unsigned long long V_1 ,
T_1 V_2 ,
unsigned char * V_3 )
{
F_3 ( V_1 , & V_3 [ 2 ] ) ;
F_3 ( V_2 , & V_3 [ 6 ] ) ;
}
void F_6 (
unsigned long long V_1 ,
T_1 V_2 ,
unsigned char * V_3 )
{
F_7 ( V_1 , & V_3 [ 2 ] ) ;
F_3 ( V_2 , & V_3 [ 10 ] ) ;
}
void F_8 (
unsigned long long V_1 ,
T_1 V_2 ,
unsigned char * V_3 )
{
F_7 ( V_1 , & V_3 [ 12 ] ) ;
F_3 ( V_2 , & V_3 [ 28 ] ) ;
}
