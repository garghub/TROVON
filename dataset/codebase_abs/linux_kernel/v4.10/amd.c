static void
F_1 ( unsigned int V_1 , unsigned long * V_2 ,
unsigned long * V_3 , T_1 * type )
{
unsigned long V_4 , V_5 ;
F_2 ( V_6 , V_4 , V_5 ) ;
if ( V_1 == 1 )
V_4 = V_5 ;
* V_2 = ( V_4 & 0xFFFE0000 ) >> V_7 ;
* type = 0 ;
if ( V_4 & 1 )
* type = V_8 ;
if ( V_4 & 2 )
* type = V_9 ;
if ( ! ( V_4 & 3 ) ) {
* V_3 = 0 ;
return;
}
V_4 = ( ~ V_4 ) & 0x1FFFC ;
* V_3 = ( V_4 + 4 ) << ( 15 - V_7 ) ;
}
static void
F_3 ( unsigned int V_1 , unsigned long V_2 , unsigned long V_3 , T_1 type )
{
T_2 V_10 [ 2 ] ;
F_2 ( V_6 , V_10 [ 0 ] , V_10 [ 1 ] ) ;
if ( V_3 == 0 ) {
V_10 [ V_1 ] = 0 ;
} else {
V_10 [ V_1 ] = ( - V_3 >> ( 15 - V_7 ) & 0x0001FFFC )
| ( V_2 << V_7 ) | ( type + 1 ) ;
}
F_4 () ;
F_5 ( V_6 , V_10 [ 0 ] , V_10 [ 1 ] ) ;
}
static int
F_6 ( unsigned long V_2 , unsigned long V_3 , unsigned int type )
{
if ( type > V_9 || V_3 < ( 1 << ( 17 - V_7 ) )
|| ( V_3 & ~ ( V_3 - 1 ) ) - V_3 || ( V_2 & ( V_3 - 1 ) ) )
return - V_11 ;
return 0 ;
}
int T_3 F_7 ( void )
{
F_8 ( & V_12 ) ;
return 0 ;
}
