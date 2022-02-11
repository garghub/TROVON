static int F_1 ( char * V_1 )
{
if ( strlen ( V_1 ) <= 5 || strncmp ( V_1 , L_1 , 5 ) != 0 )
return - V_2 ;
strncpy ( V_3 , V_1 , sizeof( V_3 ) - 1 ) ;
snprintf ( V_4 , sizeof( V_4 ) - 1 ,
L_2 , V_1 + 5 ) ;
return 0 ;
}
static int F_2 ( void )
{
int V_5 = F_3 ( V_4 , V_6 ) ;
if ( V_5 < 0 ) {
perror ( V_4 ) ;
return 0 ;
}
F_4 ( V_5 ) ;
return 1 ;
}
static void F_5 ( char * V_7 , int V_8 )
{
char V_9 [ 1024 ] ;
int V_5 = F_3 ( V_7 , V_10 ) ;
if ( V_5 < 0 ) {
perror ( L_3 ) ;
exit ( 1 ) ;
}
sprintf ( V_9 , L_4 , V_8 ) ;
if ( F_6 ( V_5 , V_9 , strlen ( V_9 ) ) != strlen ( V_9 ) ) {
perror ( L_5 ) ;
exit ( 1 ) ;
}
F_4 ( V_5 ) ;
}
static void F_7 ( int V_11 )
{
if ( V_12 )
return;
F_5 ( L_6 , V_11 ) ;
}
static void F_8 ( int V_13 )
{
const char * V_14 = ( V_13 == 0 ) ? L_7 : L_8 ;
F_5 ( V_4 , V_13 * 1000 ) ;
F_9 ( V_15 , L_9 , V_14 , V_3 ) ;
}
static int F_10 ( void )
{
return 1 ;
}
static int F_11 ( void )
{
return 1 ;
}
static void F_12 ( int V_16 )
{
F_8 ( 0 ) ;
F_7 ( 0 ) ;
}
int main ( int V_17 , char * * V_18 )
{
int V_5 , V_19 ;
struct V_20 V_21 ;
struct V_22 V_23 ;
if ( V_17 == 1 )
V_19 = F_1 ( L_10 ) ;
else if ( V_17 == 2 )
V_19 = F_1 ( V_18 [ 1 ] ) ;
else
V_19 = - V_2 ;
if ( V_19 || ! F_2 () ) {
fprintf ( V_24 , L_11 ,
V_18 [ 0 ] ) ;
exit ( 1 ) ;
}
V_5 = F_3 ( L_12 , V_6 ) ;
if ( V_5 < 0 ) {
perror ( L_12 ) ;
return V_25 ;
}
if ( V_20 ( L_6 , & V_21 ) )
V_12 = 1 ;
if ( F_13 ( 0 , 0 ) != 0 ) {
perror ( L_13 ) ;
return V_25 ;
}
F_14 ( V_26 , V_27 | V_28 | V_29 , V_30 ) ;
V_23 . V_31 = F_15 ( V_32 ) ;
F_16 ( 0 , V_32 , & V_23 ) ;
F_17 ( V_33 | V_34 ) ;
signal ( V_35 , F_12 ) ;
for (; ; ) {
unsigned char V_36 ;
V_19 = F_18 ( V_5 , & V_36 , sizeof( V_36 ) ) ;
F_19 ( 0 ) ;
if ( ( V_19 == - 1 ) && ( V_37 == V_38 ) ) {
continue;
}
if ( V_19 != sizeof( V_36 ) ) {
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
F_4 ( V_5 ) ;
return V_39 ;
}
