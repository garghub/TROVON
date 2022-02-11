static int T_1 F_1 ( void )
{
char V_1 [ 100 ] ;
unsigned int V_2 ;
unsigned int V_3 ;
struct { unsigned char V_1 [ 6 ] ; } V_4 = { L_1 } ;
F_2 ( V_5 L_2 ) ;
F_3 ( & V_6 , & V_4 , sizeof( V_4 ) ) ;
F_2 ( V_5 L_3 , F_4 ( & V_6 ) ) ;
for ( V_2 = 0 ; V_2 < 10 ; V_2 ++ ) {
memset ( V_1 , 'a' + V_2 , V_2 + 1 ) ;
F_3 ( & V_6 , V_1 , V_2 + 1 ) ;
}
F_2 ( V_5 L_4 ) ;
F_5 ( & V_6 ) ;
F_2 ( V_5 L_5 , F_6 ( & V_6 ) ) ;
V_3 = F_7 ( & V_6 , V_1 , sizeof( V_1 ) ) ;
if ( V_3 )
F_2 ( V_5 L_6 , V_3 , V_1 ) ;
V_2 = 0 ;
while ( ! F_8 ( & V_6 ) ) {
V_3 = F_9 ( & V_6 , V_1 , sizeof( V_1 ) ) ;
V_1 [ V_3 ] = '\0' ;
F_2 ( V_5 L_7 , V_3 , V_1 ) ;
if ( strcmp ( V_1 , V_7 [ V_2 ++ ] ) ) {
F_2 ( V_8 L_8 ) ;
return - V_9 ;
}
}
if ( V_2 != F_10 ( V_7 ) ) {
F_2 ( V_8 L_9 ) ;
return - V_9 ;
}
F_2 ( V_5 L_10 ) ;
return 0 ;
}
static T_2 F_11 ( struct V_10 * V_10 , const char T_3 * V_1 ,
T_4 V_11 , T_5 * V_12 )
{
int V_3 ;
unsigned int V_13 ;
if ( F_12 ( & V_14 ) )
return - V_15 ;
V_3 = F_13 ( & V_6 , V_1 , V_11 , & V_13 ) ;
F_14 ( & V_14 ) ;
return V_3 ? V_3 : V_13 ;
}
static T_2 F_15 ( struct V_10 * V_10 , char T_3 * V_1 ,
T_4 V_11 , T_5 * V_12 )
{
int V_3 ;
unsigned int V_13 ;
if ( F_12 ( & V_16 ) )
return - V_15 ;
V_3 = F_16 ( & V_6 , V_1 , V_11 , & V_13 ) ;
F_14 ( & V_16 ) ;
return V_3 ? V_3 : V_13 ;
}
static int T_1 F_17 ( void )
{
#ifdef F_18
int V_3 ;
V_3 = F_19 ( & V_6 , V_17 , V_18 ) ;
if ( V_3 ) {
F_2 ( V_19 L_11 ) ;
return V_3 ;
}
#else
F_20 ( V_6 ) ;
#endif
if ( F_1 () < 0 ) {
#ifdef F_18
F_21 ( & V_6 ) ;
#endif
return - V_9 ;
}
if ( F_22 ( V_20 , 0 , NULL , & V_21 ) == NULL ) {
#ifdef F_18
F_21 ( & V_6 ) ;
#endif
return - V_22 ;
}
return 0 ;
}
static void T_6 F_23 ( void )
{
F_24 ( V_20 , NULL ) ;
#ifdef F_18
F_21 ( & V_6 ) ;
#endif
}
