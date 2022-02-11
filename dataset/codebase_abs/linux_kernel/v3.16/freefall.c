static int F_1 ( char * V_1 )
{
char V_2 [ 64 ] ;
if ( strlen ( V_1 ) <= 5 || strncmp ( V_1 , L_1 , 5 ) != 0 )
return - V_3 ;
strncpy ( V_2 , V_1 + 5 , sizeof( V_2 ) - 1 ) ;
strncpy ( V_4 , V_1 , sizeof( V_4 ) - 1 ) ;
snprintf ( V_5 , sizeof( V_5 ) - 1 ,
L_2 , V_2 ) ;
return 0 ;
}
static int F_2 ( void )
{
int V_6 = F_3 ( V_5 , V_7 ) ;
if ( V_6 < 0 ) {
perror ( V_5 ) ;
return 0 ;
}
F_4 ( V_6 ) ;
return 1 ;
}
static void F_5 ( char * V_8 , int V_9 )
{
char V_10 [ 1024 ] ;
int V_6 = F_3 ( V_8 , V_11 ) ;
if ( V_6 < 0 ) {
perror ( L_3 ) ;
exit ( 1 ) ;
}
sprintf ( V_10 , L_4 , V_9 ) ;
if ( F_6 ( V_6 , V_10 , strlen ( V_10 ) ) != strlen ( V_10 ) ) {
perror ( L_5 ) ;
exit ( 1 ) ;
}
F_4 ( V_6 ) ;
}
static void F_7 ( int V_12 )
{
if ( V_13 )
return;
F_5 ( L_6 , V_12 ) ;
}
static void F_8 ( int V_14 )
{
const char * V_15 = ( V_14 == 0 ) ? L_7 : L_8 ;
F_5 ( V_5 , V_14 * 1000 ) ;
F_9 ( V_16 , L_9 , V_15 , V_4 ) ;
}
static int F_10 ( void )
{
return 1 ;
}
static int F_11 ( void )
{
return 1 ;
}
static void F_12 ( int V_17 )
{
F_8 ( 0 ) ;
F_7 ( 0 ) ;
}
int main ( int V_18 , char * * V_19 )
{
int V_6 , V_20 ;
struct V_21 V_22 ;
struct V_23 V_24 ;
if ( V_18 == 1 )
V_20 = F_1 ( L_10 ) ;
else if ( V_18 == 2 )
V_20 = F_1 ( V_19 [ 1 ] ) ;
else
V_20 = - V_3 ;
if ( V_20 || ! F_2 () ) {
fprintf ( V_25 , L_11 ,
V_19 [ 0 ] ) ;
exit ( 1 ) ;
}
V_6 = F_3 ( L_12 , V_7 ) ;
if ( V_6 < 0 ) {
perror ( L_12 ) ;
return V_26 ;
}
if ( V_21 ( L_6 , & V_22 ) )
V_13 = 1 ;
if ( F_13 ( 0 , 0 ) != 0 ) {
perror ( L_13 ) ;
return V_26 ;
}
F_14 ( V_27 , V_28 | V_29 | V_30 , V_31 ) ;
V_24 . V_32 = F_15 ( V_33 ) ;
F_16 ( 0 , V_33 , & V_24 ) ;
F_17 ( V_34 | V_35 ) ;
signal ( V_36 , F_12 ) ;
for (; ; ) {
unsigned char V_37 ;
V_20 = F_18 ( V_6 , & V_37 , sizeof( V_37 ) ) ;
F_19 ( 0 ) ;
if ( ( V_20 == - 1 ) && ( V_38 == V_39 ) ) {
continue;
}
if ( V_20 != sizeof( V_37 ) ) {
perror ( L_14 ) ;
break;
}
F_8 ( 21 ) ;
F_7 ( 1 ) ;
if ( 1 || F_10 () || F_11 () )
F_19 ( 2 ) ;
else
F_19 ( 20 ) ;
}
F_20 () ;
F_4 ( V_6 ) ;
return V_40 ;
}
