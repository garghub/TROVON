static unsigned long F_1 ( void )
{
T_1 V_1 = F_2 ( V_2 + V_3 ) ;
return F_3 ( V_1 , 24000000 ) ;
}
static unsigned long F_4 ( void )
{
T_1 V_1 = F_2 ( V_2 + V_4 ) ;
return F_3 ( V_1 , 24000000 ) ;
}
unsigned long F_5 ( struct V_5 * V_5 )
{
unsigned long V_6 = F_6 ( V_2 + V_7 ) ;
unsigned long V_8 = F_1 () ;
if ( V_6 & ( 1 << 14 ) )
V_8 = ( V_8 * 3 ) >> 2 ;
return V_8 / ( ( V_6 >> 30 ) + 1 ) ;
}
static unsigned long F_7 ( struct V_5 * V_5 )
{
unsigned long V_6 = F_6 ( V_2 + V_7 ) ;
return F_5 ( NULL ) / ( ( ( V_6 >> 28 ) & 0x3 ) + 1 ) ;
}
static unsigned long F_8 ( struct V_5 * V_5 )
{
return F_7 ( NULL ) >> 1 ;
}
static unsigned long F_9 ( int V_9 )
{
unsigned long V_10 = ( V_9 & 0x3 ) * 8 ;
unsigned long V_11 = V_9 & ~ 0x3 ;
unsigned long V_12 = ( F_6 ( V_2 + V_13 + V_11 ) >> V_10 ) & 0x3f ;
unsigned long V_14 ;
if ( F_6 ( V_2 + 0x64 ) & ( 1 << V_9 ) )
V_14 = F_4 () ;
else
V_14 = F_7 ( NULL ) ;
return V_14 / ( V_12 + 1 ) ;
}
static unsigned long F_10 ( struct V_5 * V_5 )
{
return F_9 ( 15 ) ;
}
static unsigned long F_11 ( struct V_5 * V_5 )
{
return F_9 ( 14 ) ;
}
static unsigned long F_12 ( struct V_5 * V_5 )
{
return F_9 ( 13 ) ;
}
static unsigned long F_13 ( struct V_5 * V_5 )
{
return F_9 ( 6 ) ;
}
static unsigned long F_14 ( struct V_5 * V_5 )
{
return F_9 ( 8 ) ;
}
static unsigned long F_15 ( struct V_5 * V_5 )
{
return F_9 ( 5 ) ;
}
static unsigned long F_16 ( struct V_5 * V_5 )
{
return F_9 ( 7 ) ;
}
static unsigned long F_17 ( struct V_5 * V_5 )
{
return F_9 ( 3 ) ;
}
static unsigned long F_18 ( struct V_5 * V_5 )
{
return F_9 ( 4 ) ;
}
static unsigned long F_19 ( struct V_5 * V_5 )
{
return F_9 ( 0 ) ;
}
static unsigned long F_20 ( struct V_5 * V_5 )
{
unsigned long V_6 = F_6 ( V_2 + V_7 ) ;
unsigned long V_8 = F_4 () ;
return ( V_6 & ( 1 << 23 ) ) ? 0 : V_8 / ( ( 0x3F & ( V_6 >> 16 ) ) + 1 ) ;
}
static int F_21 ( struct V_5 * V_5 )
{
T_2 V_11 ;
V_11 = F_2 ( V_5 -> V_15 ) ;
V_11 |= 1 << V_5 -> V_16 ;
F_22 ( V_11 , V_5 -> V_15 ) ;
return 0 ;
}
static void F_23 ( struct V_5 * V_5 )
{
T_2 V_11 ;
V_11 = F_2 ( V_5 -> V_15 ) ;
V_11 &= ~ ( 1 << V_5 -> V_16 ) ;
F_22 ( V_11 , V_5 -> V_15 ) ;
}
int T_3 F_24 ( void )
{
F_25 ( V_17 , F_26 ( V_17 ) ) ;
F_22 ( ( 1 << 19 ) , V_2 + V_18 ) ;
F_22 ( ( 0xf << 16 ) | ( 3 << 26 ) , V_2 + V_19 ) ;
F_22 ( ( 1 << 5 ) , V_2 + V_20 ) ;
#if F_27 ( V_21 ) && ! F_27 ( V_22 )
F_28 ( & V_23 ) ;
#endif
F_22 ( F_2 ( V_2 + 0x64 ) | ( 1 << 7 ) | ( 1 << 0 ) ,
V_2 + 0x64 ) ;
F_22 ( F_2 ( V_2 + 0x64 ) & ~ ( 1 << 5 ) , V_2 + 0x64 ) ;
F_28 ( & V_24 ) ;
F_29 ( L_1 , F_30 () ) ;
F_31 ( & V_24 ) ;
F_32 ( & V_25 , F_33 ( V_26 ) , 54 ) ;
return 0 ;
}
