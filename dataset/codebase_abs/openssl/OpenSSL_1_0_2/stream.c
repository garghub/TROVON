main ()
{
fprintf ( V_1 , L_1 ) ;
F_1 () ;
fprintf ( V_1 , L_2 ) ;
F_2 () ;
}
int F_2 ()
{
T_1 V_2 ;
T_2 V_3 , V_4 ;
int V_5 ;
static char * V_6 = L_3 ;
static char * V_7 = L_4 ;
static char * V_8 = L_5 ;
unsigned char V_9 [ 100 ] ;
int V_10 ;
F_3 ( ( T_2 * ) V_6 , V_2 ) ;
V_5 = 0 ;
memset ( V_3 , 0 , 8 ) ;
F_4 ( V_7 , V_9 , 26 , V_2 , ( T_2 * ) V_3 , & V_5 , 1 ) ;
for ( V_10 = 0 ; V_10 < 26 ; V_10 ++ )
fprintf ( V_1 , L_6 , V_9 [ V_10 ] ) ;
fprintf ( V_1 , L_7 ) ;
V_5 = 0 ;
memset ( V_3 , 0 , 8 ) ;
F_4 ( V_8 , V_9 , 26 , V_2 , ( T_2 * ) V_3 , & V_5 , 1 ) ;
for ( V_10 = 0 ; V_10 < 26 ; V_10 ++ )
fprintf ( V_1 , L_6 , V_9 [ V_10 ] ) ;
fprintf ( V_1 , L_7 ) ;
}
int F_1 ()
{
static char * V_6 = L_8 ;
T_3 V_4 ;
unsigned char V_11 [ 100 ] , V_9 [ 100 ] ;
int V_10 ;
F_5 ( & V_4 , 16 , V_6 ) ;
V_11 [ 0 ] = '\0' ;
strcpy ( V_11 , L_4 ) ;
F_6 ( V_4 , 26 , V_11 , V_9 ) ;
for ( V_10 = 0 ; V_10 < 26 ; V_10 ++ )
fprintf ( V_1 , L_6 , V_9 [ V_10 ] ) ;
fprintf ( V_1 , L_7 ) ;
F_5 ( & V_4 , 16 , V_6 ) ;
V_11 [ 0 ] = '\0' ;
strcpy ( V_11 , L_5 ) ;
F_6 ( V_4 , 26 , V_11 , V_9 ) ;
for ( V_10 = 0 ; V_10 < 26 ; V_10 ++ )
fprintf ( V_1 , L_6 , V_9 [ V_10 ] ) ;
fprintf ( V_1 , L_7 ) ;
}
