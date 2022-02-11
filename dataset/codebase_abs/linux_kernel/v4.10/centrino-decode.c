static int F_1 ( unsigned int V_1 , unsigned int V_2 ,
unsigned int * V_3 , unsigned int * V_4 )
{
int V_5 ;
char V_6 [ 20 ] ;
unsigned long long V_7 ;
int V_8 = - 1 ;
* V_3 = * V_4 = 0 ;
if ( V_1 > V_9 )
goto V_10;
sprintf ( V_6 , L_1 , V_1 ) ;
V_5 = F_2 ( V_6 , V_11 ) ;
if ( V_5 < 0 )
goto V_10;
if ( F_3 ( V_5 , V_2 , V_12 ) == - 1 )
goto V_13;
if ( F_4 ( V_5 , & V_7 , 8 ) != 8 )
goto V_13;
* V_3 = ( V_14 ) ( V_7 & 0xffffffffull ) ;
* V_4 = ( V_14 ) ( V_7 >> 32 & 0xffffffffull ) ;
V_8 = 0 ;
V_13:
F_5 ( V_5 ) ;
V_10:
return V_8 ;
}
static void F_6 ( unsigned int V_2 )
{
unsigned int V_15 ;
unsigned int V_16 ;
V_15 = ( ( V_2 >> 8 ) & 0xFF ) ;
V_16 = ( ( ( V_2 & 0xFF ) * 16 ) + 700 ) ;
printf ( L_2 , V_2 , V_15 , V_16 ) ;
}
static int F_7 ( unsigned int V_1 )
{
unsigned int V_3 , V_4 ;
int V_17 ;
V_17 = F_1 ( V_1 , V_18 , & V_3 , & V_4 ) ;
if ( V_17 ) {
printf ( L_3 , V_1 ) ;
printf ( L_4 ) ;
printf ( L_5 ) ;
return 1 ;
}
F_6 ( V_3 ) ;
return 0 ;
}
int main ( int V_19 , char * * V_20 )
{
unsigned int V_1 , V_21 = 0 ;
if ( V_19 < 2 )
V_1 = 0 ;
else {
V_1 = strtoul ( V_20 [ 1 ] , NULL , 0 ) ;
if ( V_1 >= V_9 )
V_21 = 1 ;
}
if ( V_21 )
F_6 ( V_1 ) ;
else
F_7 ( V_1 ) ;
return 0 ;
}
