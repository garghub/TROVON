int F_1 ( char * V_1 )
{
char V_2 [ 64 ] ;
if ( strlen ( V_1 ) <= 5 || strncmp ( V_1 , L_1 , 5 ) != 0 )
return - V_3 ;
strncpy ( V_2 , V_1 + 5 , sizeof( V_2 ) ) ;
snprintf ( V_4 , sizeof( V_4 ) ,
L_2 , V_2 ) ;
return 0 ;
}
int F_2 ( void )
{
int V_5 = F_3 ( V_4 , V_6 ) ;
if ( V_5 < 0 ) {
perror ( V_4 ) ;
return 0 ;
}
F_4 ( V_5 ) ;
return 1 ;
}
void F_5 ( char * V_7 , int V_8 )
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
void F_7 ( int V_11 )
{
F_5 ( L_6 , V_11 ) ;
}
void F_8 ( int V_12 )
{
F_5 ( V_4 , V_12 * 1000 ) ;
}
int F_9 ( void )
{
}
int F_10 ( void )
{
}
void F_11 ( void )
{
F_8 ( 0 ) ;
F_7 ( 0 ) ;
}
int main ( int V_13 , char * * V_14 )
{
int V_5 , V_15 ;
struct V_16 V_17 ;
if ( V_13 == 1 )
V_15 = F_1 ( L_7 ) ;
else if ( V_13 == 2 )
V_15 = F_1 ( V_14 [ 1 ] ) ;
else
V_15 = - V_3 ;
if ( V_15 || ! F_2 () ) {
fprintf ( V_18 , L_8 ,
V_14 [ 0 ] ) ;
exit ( 1 ) ;
}
V_5 = F_3 ( L_9 , V_6 ) ;
if ( V_5 < 0 ) {
perror ( L_9 ) ;
return V_19 ;
}
F_12 ( 0 , 0 ) ;
V_17 . V_20 = F_13 ( V_21 ) ;
F_14 ( 0 , V_21 , & V_17 ) ;
F_15 ( V_22 | V_23 ) ;
signal ( V_24 , F_11 ) ;
for (; ; ) {
unsigned char V_25 ;
V_15 = F_16 ( V_5 , & V_25 , sizeof( V_25 ) ) ;
F_17 ( 0 ) ;
if ( ( V_15 == - 1 ) && ( V_26 == V_27 ) ) {
continue;
}
if ( V_15 != sizeof( V_25 ) ) {
perror ( L_10 ) ;
break;
}
F_8 ( 21 ) ;
F_7 ( 1 ) ;
if ( 1 || F_9 () || F_10 () )
F_17 ( 2 ) ;
else
F_17 ( 20 ) ;
}
F_4 ( V_5 ) ;
return V_28 ;
}
