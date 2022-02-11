static unsigned long F_1 ( struct V_1 * V_1 )
{
int V_2 = F_2 ( V_3 ) & 0x0007 ;
return V_1 -> V_4 -> V_5 / V_6 [ V_2 ] ;
}
static inline int F_3 ( struct V_1 * V_1 , unsigned long V_5 )
{
int V_7 = V_1 -> V_4 -> V_5 / V_5 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < F_4 ( V_6 ) ; V_8 ++ )
if ( V_6 [ V_8 ] == V_7 )
return V_9 [ V_8 ] ;
return 5 ;
}
static unsigned long F_5 ( struct V_1 * V_1 )
{
int V_2 = ( F_2 ( V_3 ) >> 3 ) & 0x0007 ;
return V_1 -> V_4 -> V_5 / V_6 [ V_2 ] ;
}
static void F_6 ( struct V_1 * V_1 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < F_4 ( V_6 ) ; V_8 ++ ) {
int V_7 = V_6 [ V_8 ] ;
if ( V_1 -> V_10 -> V_11 ( V_1 , V_1 -> V_4 -> V_5 / V_7 ) == 0 )
break;
}
F_7 ( V_8 == F_4 ( V_6 ) ) ;
}
static unsigned long F_8 ( struct V_1 * V_1 )
{
int V_2 = ( F_2 ( V_3 ) >> 6 ) & 0x0007 ;
return V_1 -> V_4 -> V_5 / V_6 [ V_2 ] ;
}
static int F_9 ( struct V_1 * V_1 , unsigned long V_5 )
{
struct V_1 * V_12 = F_10 ( NULL , L_1 ) ;
unsigned long V_13 = F_11 ( V_12 ) ;
F_12 ( V_12 ) ;
if ( V_5 > V_13 )
return 1 ;
if ( V_5 > 66000000 )
return 1 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_1 , unsigned long V_5 )
{
unsigned long V_14 ;
unsigned int V_15 ;
if ( F_9 ( V_1 , V_5 ) != 0 )
return - V_16 ;
V_15 = F_3 ( V_1 , V_5 ) ;
V_14 = F_2 ( V_3 ) ;
V_14 &= ~ ( 0x0007 << 6 ) ;
V_14 |= V_15 << 6 ;
F_14 ( V_14 , V_3 ) ;
V_1 -> V_5 = V_1 -> V_4 -> V_5 / V_6 [ V_15 ] ;
return 0 ;
}
int T_1 F_15 ( void )
{
struct V_1 * V_1 ;
int V_8 , V_17 = 0 ;
F_16 () ;
V_1 = F_10 ( NULL , L_2 ) ;
for ( V_8 = 0 ; V_8 < F_4 ( V_18 ) ; V_8 ++ ) {
struct V_1 * V_19 = V_18 [ V_8 ] ;
V_19 -> V_4 = V_1 ;
V_17 |= F_17 ( V_19 ) ;
}
F_12 ( V_1 ) ;
F_18 ( V_20 , F_4 ( V_20 ) ) ;
return V_17 ;
}
