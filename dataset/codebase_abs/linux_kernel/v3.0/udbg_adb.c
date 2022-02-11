static inline void F_1 ( void )
{
#ifdef F_2
if ( V_1 == V_2 )
F_3 () ;
#endif
#ifdef F_4
if ( V_1 == V_3 )
F_5 () ;
#endif
}
static int F_6 ( void )
{
int V_4 , V_5 , V_6 ;
V_7 = 1 ;
for (; ; ) {
V_8 = - 1 ;
V_5 = 0 ;
V_6 = 0 ;
V_4 = - 1 ;
do {
if ( -- V_5 < 0 ) {
V_6 = 1 - V_6 ;
F_7 ( V_6 ? 0xdb : 0x20 ) ;
F_7 ( '\b' ) ;
V_5 = 200000 ;
}
F_1 () ;
if ( V_9 )
V_4 = V_9 () ;
} while ( V_4 == - 1 && V_8 == - 1 );
if ( V_6 )
F_8 ( L_1 ) ;
if ( V_4 != - 1 )
return V_4 ;
V_4 = V_8 ;
if ( ( V_4 & 0x7f ) == 0x38 || ( V_4 & 0x7f ) == 0x7b ) {
V_10 = ( V_4 & 0x80 ) == 0 ;
continue;
}
if ( V_4 >= 0x80 )
continue;
V_4 = ( V_10 ? V_11 : V_12 ) [ V_4 ] ;
if ( V_4 != 0 )
break;
}
V_7 = 0 ;
return V_4 ;
}
static int F_9 ( void )
{
#ifdef F_10
if ( V_13 && V_1 != V_14 )
return F_6 () ;
#endif
if ( V_15 )
return V_15 () ;
return - 1 ;
}
static int F_11 ( void )
{
F_1 () ;
if ( V_9 )
return V_9 () ;
return - 1 ;
}
static void F_12 ( char V_16 )
{
#ifdef F_10
if ( V_13 )
F_7 ( V_16 ) ;
#endif
if ( V_17 )
return V_17 ( V_16 ) ;
}
void T_1 F_13 ( void )
{
#ifdef F_10
if ( F_14 ( 1 ) == 0 ) {
V_13 = 1 ;
V_18 = F_12 ;
}
#endif
}
int T_1 F_15 ( int V_19 )
{
struct V_20 * V_21 ;
V_17 = V_18 ;
V_15 = V_22 ;
V_9 = V_23 ;
if ( V_17 == F_12 )
V_17 = NULL ;
#ifdef F_10
if ( V_17 == F_7 )
V_17 = NULL ;
#endif
V_18 = F_12 ;
V_22 = F_9 ;
V_23 = F_11 ;
#ifdef F_10
if ( F_14 ( V_19 ) == 0 )
V_13 = 1 ;
#endif
for ( V_21 = NULL ; ( V_21 = F_16 ( V_21 , L_2 ) ) != NULL ; ) {
struct V_20 * V_24 = F_17 ( V_21 ) ;
int V_25 = ( V_24 && strcmp ( V_24 -> type , L_3 ) == 0 ) ;
F_18 ( V_24 ) ;
if ( V_25 )
break;
}
if ( V_21 == NULL )
return - V_26 ;
F_18 ( V_21 ) ;
#ifdef F_2
if ( F_19 () )
V_1 = V_2 ;
#endif
#ifdef F_4
if ( F_20 () )
V_1 = V_3 ;
#endif
if ( V_1 == V_14 )
return - V_26 ;
return 0 ;
}
