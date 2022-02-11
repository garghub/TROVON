void F_1 ( void )
{
const char * V_1 ;
int line ;
if ( F_2 () == 0 )
return;
while ( F_3 ( & V_1 , & line ) ) {}
}
static void F_4 ( T_1 * V_2 )
{
char V_3 [ 200 ] ;
if ( ! V_4 ) {
V_4 = F_5 ( V_5 , L_1 ) ;
F_6 ( ! V_4 , L_2 , V_5 ) ;
}
F_7 ( F_8 ( V_2 ) , V_3 , sizeof( V_3 ) ) ;
F_6 ( ! F_9 ( V_4 , V_2 ) , L_2 , V_5 ) ;
if ( V_6 )
fprintf ( V_7 , L_3 , V_3 ) ;
}
int main ( int V_8 , char * * V_9 )
{
char * V_10 ;
F_10 () ;
F_11 () ;
F_12 () ;
V_6 = atoi ( getenv ( L_4 ) ? : L_5 ) ;
V_11 = getenv ( L_6 ) ;
if ( V_8 != 3 )
F_13 () ;
V_10 = V_9 [ 1 ] ;
V_5 = V_9 [ 2 ] ;
if ( ! V_10 [ 0 ] ) {
T_2 * V_12 = fopen ( V_5 , L_1 ) ;
F_6 ( ! V_12 , L_2 , V_5 ) ;
fclose ( V_12 ) ;
exit ( 0 ) ;
} else if ( ! strncmp ( V_10 , L_7 , 7 ) ) {
T_3 * V_13 ;
struct {
const char * V_14 ;
T_1 * V_15 ;
} V_16 ;
V_16 . V_14 = V_10 ;
V_16 . V_15 = NULL ;
F_14 () ;
F_1 () ;
V_13 = F_15 ( L_8 ) ;
F_6 ( ! V_13 , L_9 ) ;
if ( F_16 ( V_13 ) )
F_1 () ;
else
F_6 ( 1 , L_10 ) ;
if ( V_11 )
F_6 ( ! F_17 ( V_13 , L_11 , V_11 , 0 ) , L_12 ) ;
F_18 ( V_13 , L_13 , 0 , & V_16 , NULL , 1 ) ;
F_6 ( ! V_16 . V_15 , L_14 ) ;
F_4 ( V_16 . V_15 ) ;
} else {
T_4 * V_17 ;
T_1 * V_2 ;
V_17 = F_5 ( V_10 , L_15 ) ;
F_6 ( ! V_17 , L_2 , V_10 ) ;
while ( 1 ) {
V_2 = F_19 ( V_17 , NULL , NULL , NULL ) ;
if ( V_4 && ! V_2 ) {
unsigned long V_18 = F_20 () ;
if ( F_21 ( V_18 ) == V_19 &&
F_22 ( V_18 ) == V_20 ) {
F_12 () ;
break;
}
}
F_6 ( ! V_2 , L_2 , V_10 ) ;
F_4 ( V_2 ) ;
}
}
F_23 ( V_4 ) ;
return 0 ;
}
