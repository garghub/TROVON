void F_1 ( int V_1 )
{
T_1 V_2 ;
V_2 = F_2 ( V_3 ) ;
F_3 ( V_2 | ( 0x1 << V_1 ) , V_3 ) ;
}
void F_4 ( int V_1 )
{
T_1 V_2 ;
V_2 = F_2 ( V_3 ) ;
F_3 ( V_2 & ~ ( 0x1 << V_1 ) , V_3 ) ;
}
void F_5 ( unsigned int V_4 )
{
T_1 V_2 ;
V_2 = F_2 ( V_3 ) ;
V_2 |= V_4 ;
F_3 ( V_2 , V_3 ) ;
}
void F_1 ( int V_1 )
{
T_2 V_2 ;
V_2 = F_6 ( V_3 ) ;
F_7 ( V_2 | ( 0x1 << V_1 ) , V_3 ) ;
}
void F_4 ( int V_1 )
{
T_2 V_2 ;
V_2 = F_6 ( V_3 ) ;
F_7 ( V_2 & ~ ( 0x1 << V_1 ) , V_3 ) ;
}
void F_5 ( unsigned int V_4 )
{
T_2 V_2 ;
V_2 = F_6 ( V_3 ) ;
V_2 |= V_4 ;
F_7 ( V_2 , V_3 ) ;
}
void F_8 ( int V_5 )
{
#ifdef F_9
if ( ( V_5 >= V_6 ) && ( V_5 <= V_7 ) ) {
T_3 V_8 ;
V_8 = F_10 ( F_9 ) ;
V_8 |= ( 0x1 << ( V_5 - V_6 + 1 ) ) ;
F_11 ( V_8 , F_9 ) ;
}
#endif
}
static void F_12 ( struct V_9 * V_10 )
{
if ( V_11 [ V_10 -> V_5 ] )
F_1 ( V_11 [ V_10 -> V_5 ] ) ;
}
static void F_13 ( struct V_9 * V_10 )
{
if ( V_11 [ V_10 -> V_5 ] )
F_4 ( V_11 [ V_10 -> V_5 ] ) ;
}
static int F_14 ( struct V_9 * V_10 , unsigned int type )
{
return 0 ;
}
void T_4 F_15 ( void )
{
int V_5 ;
F_5 ( 0xffffffff ) ;
for ( V_5 = 0 ; ( V_5 < V_12 ) ; V_5 ++ ) {
F_16 ( V_5 , & V_13 ) ;
F_17 ( V_5 , V_14 ) ;
F_18 ( V_5 , V_15 ) ;
}
}
