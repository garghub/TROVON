static int F_1 ( unsigned int V_1 , unsigned int V_2 )
{
unsigned int V_3 , V_4 = ( 1 << V_1 ) ;
F_2 ( L_1 , V_5 , V_1 , V_2 ) ;
if ( V_2 >= 2 || ! ( V_4 & V_6 [ V_2 ] ) )
return - V_7 ;
V_3 = F_3 ( V_8 + V_9 + V_2 * 4 ) ;
V_3 &= ~ ( V_4 | ( V_4 << 4 ) ) ;
F_4 ( V_3 , V_8 + V_9 + V_2 * 4 ) ;
return 0 ;
}
static int F_5 ( unsigned int V_2 )
{
unsigned int V_3 ;
F_2 ( L_2 , V_5 , V_2 ) ;
if ( V_2 >= 2 )
return - V_7 ;
V_3 = F_3 ( V_8 + V_9 + V_2 * 4 ) ;
V_3 &= ~ ( 1 << 8 ) ;
V_3 |= V_6 [ V_2 ] ;
F_4 ( V_3 , V_8 + V_9 + V_2 * 4 ) ;
return 0 ;
}
static void F_6 ( unsigned int V_1 , unsigned int V_2 )
{
unsigned int V_3 ;
F_2 ( L_1 , V_5 , V_1 , V_2 ) ;
F_7 ( V_2 >= 2 || ! ( ( 1 << V_1 ) & V_6 [ V_2 ] ) ) ;
V_3 = F_3 ( V_8 + V_9 + V_2 * 4 ) ;
V_3 |= ( 1 << V_1 ) ;
F_4 ( V_3 , V_8 + V_9 + V_2 * 4 ) ;
}
static void F_8 ( unsigned int V_2 )
{
unsigned int V_3 ;
F_2 ( L_2 , V_5 , V_2 ) ;
F_7 ( V_2 >= 2 ) ;
V_3 = F_3 ( V_8 + V_9 + V_2 * 4 ) ;
V_3 |= ( 1 << 8 ) ;
F_4 ( V_3 , V_8 + V_9 + V_2 * 4 ) ;
}
static void F_9 ( void )
{
F_10 ( V_10 ) ;
}
static void F_11 ( void )
{
F_10 ( V_11 ) ;
F_12 ( F_13 () ) ;
}
static int T_1 F_14 ( void )
{
struct V_12 * V_13 ;
unsigned int V_14 ;
int V_15 ;
if ( ! F_15 () )
return - V_16 ;
V_13 = F_16 ( NULL , NULL , L_3 ) ;
if ( ! V_13 )
return - V_16 ;
V_8 = F_17 ( V_13 , 0 ) ;
if ( ! V_8 )
return - V_17 ;
V_14 = F_3 ( V_8 + V_18 ) ;
V_6 [ 0 ] = ( 1 << ( ( ( V_14 >> 16 ) >> ( 0 << 2 ) ) & 0xf ) ) - 1 ;
V_6 [ 1 ] = ( 1 << ( ( ( V_14 >> 16 ) >> ( 1 << 2 ) ) & 0xf ) ) - 1 ;
V_15 = F_18 ( & V_19 ) ;
if ( ! V_15 )
V_15 = F_19 ( V_20 ) ;
if ( V_15 ) {
F_20 ( V_8 ) ;
return V_15 ;
}
F_21 ( L_4 ) ;
F_22 ( F_23 ( V_21 ) ) ;
return 0 ;
}
