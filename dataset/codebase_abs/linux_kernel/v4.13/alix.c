static void T_1 F_1 ( void )
{
F_2 ( V_1 , F_3 ( V_1 ) ) ;
}
static bool T_1 F_4 ( unsigned long V_2 ,
const char * V_3 ,
T_2 V_4 )
{
const T_2 V_5 = V_6 ;
const char * V_7 ;
const char * V_8 ;
const char * V_9 ;
char V_10 [ 64 ] ;
if ( V_11 ) {
F_5 ( V_12 L_1
L_2 ,
V_13 ) ;
return true ;
}
V_7 = F_6 ( V_2 ) ;
V_8 = V_7 + V_5 - ( V_4 + 2 ) ;
for ( V_9 = V_7 ; V_9 < V_8 ; V_9 ++ ) {
const char * V_14 ;
char * V_15 ;
if ( memcmp ( V_9 , V_3 , V_4 ) != 0 )
continue;
memcpy ( V_10 , V_9 , sizeof( V_10 ) ) ;
V_15 = strchr ( V_10 , '\0' ) ;
if ( V_15 )
* V_15 = ' ' ;
V_15 = strchr ( V_10 , '\r' ) ;
if ( V_15 )
* V_15 = '\0' ;
V_14 = V_9 + V_4 ;
if ( ( V_14 [ 0 ] == '2' || V_14 [ 0 ] == '3' || V_14 [ 0 ] == '6' ) ) {
F_5 ( V_16
L_3 ,
V_13 , V_10 ) ;
return true ;
}
}
return false ;
}
static bool T_1 F_7 ( void )
{
const char * V_17 , * V_18 ;
V_17 = F_8 ( V_19 ) ;
if ( ! V_17 || strcmp ( V_17 , L_4 ) )
return false ;
V_18 = F_8 ( V_20 ) ;
if ( ! V_18 || ( strcmp ( V_18 , L_5 ) && strcmp ( V_18 , L_6 ) ) )
return false ;
F_5 ( V_16 L_7 ,
V_13 , V_17 , V_18 ) ;
return true ;
}
static int T_1 F_9 ( void )
{
const char V_21 [] = L_8 ;
const char V_22 [] = L_9 ;
if ( ! F_10 () )
return 0 ;
if ( F_4 ( V_23 , V_21 , sizeof( V_21 ) - 1 ) ||
F_4 ( V_24 , V_22 , sizeof( V_22 ) - 1 ) ||
F_7 () )
F_1 () ;
return 0 ;
}
