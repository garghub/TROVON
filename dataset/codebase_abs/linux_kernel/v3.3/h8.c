static void F_1 ( int V_1 )
{
T_1 V_2 ;
do {
V_2 = F_2 ( V_3 + V_4 ) ;
} while ( ( V_2 & V_5 ) != V_5 );
F_3 ( V_1 , V_3 + V_6 ) ;
}
static int F_4 ( void )
{
T_1 V_2 ;
do {
V_2 = F_2 ( V_3 + V_4 ) ;
} while ( ( V_2 & V_7 ) != V_7 );
return F_2 ( V_3 + V_8 ) ;
}
static void F_5 ( const char * V_9 , int V_10 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_10 ; V_11 ++ ) {
F_1 ( V_9 [ V_11 ] ) ;
F_4 () ;
}
F_1 ( '\r' ) ;
F_1 ( '\n' ) ;
}
static void F_6 ( const char * V_12 , int V_10 )
{
F_7 () ;
F_5 ( V_12 , V_10 ) ;
for (; ; )
continue;
}
void F_8 ( char * V_12 )
{
static const char V_13 [] = L_1 ;
( void ) V_12 ;
F_6 ( V_13 , sizeof( V_13 ) - 1 ) ;
}
void F_9 ( void )
{
static const char V_14 [] = L_2 ;
F_6 ( V_14 , sizeof( V_14 ) - 1 ) ;
}
static void T_2 * F_10 ( void )
{
struct V_15 * V_16 ;
struct V_15 * V_17 ;
struct V_18 * V_19 ;
void T_2 * V_20 = NULL ;
V_16 = F_11 ( L_3 ) ;
if ( V_16 == NULL )
return NULL ;
V_19 = F_12 ( V_16 , L_4 , NULL ) ;
if ( V_19 == NULL )
goto V_21;
V_17 = F_11 ( V_19 -> V_22 ) ;
if ( V_17 == NULL )
goto V_21;
V_20 = F_13 ( V_17 , 0 ) ;
F_14 ( V_17 ) ;
F_15 ( V_17 ) ;
V_21:
F_15 ( V_16 ) ;
return V_20 ;
}
void T_3 F_16 ( void )
{
V_3 = F_10 () ;
if ( V_3 == NULL ) {
F_17 ( L_5 ) ;
V_3 = F_18 ( 0xffc0008000ULL , 0x100 ) ;
}
}
