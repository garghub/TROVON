static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
unsigned int V_4 ;
unsigned short V_5 ;
int V_6 = V_2 -> V_6 ;
V_4 = V_7 + ( ( V_8 [ V_6 - 16 ] & 0xf0 ) >> 3 ) ;
V_3 = ( V_8 [ V_6 - 16 ] & 0x0f ) * 4 ;
V_5 = ~ ( 0x000f << V_3 ) ;
V_5 &= F_2 ( V_4 ) ;
F_3 ( V_5 , V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
int V_3 ;
unsigned int V_4 ;
unsigned short V_5 ;
int V_6 = V_2 -> V_6 ;
V_4 = V_7 + ( ( V_8 [ V_6 - 16 ] & 0xf0 ) >> 3 ) ;
V_3 = ( V_8 [ V_6 - 16 ] & 0x0f ) * 4 ;
V_5 = ~ ( 0x000f << V_3 ) ;
V_5 &= F_2 ( V_4 ) ;
V_5 |= 1 << V_3 ;
F_3 ( V_5 , V_4 ) ;
}
static T_1 int F_5 ( struct V_9 * V_10 , unsigned int V_11 ,
T_2 V_12 )
{
F_6 ( V_11 , & V_13 , V_14 ) ;
return 0 ;
}
static int T_1 F_7 ( struct V_15 * V_16 ,
struct V_15 * V_17 )
{
struct V_9 * V_18 ;
int V_19 ;
V_20 = F_8 ( V_16 , 0 ) ;
F_9 ( ! V_20 ) ;
for ( V_19 = 0 ; V_19 <= 'k' - 'a' ; V_19 ++ )
F_3 ( 0x0000 , V_7 + ( V_19 * 2 ) ) ;
V_18 = F_10 ( V_16 , V_21 , & V_22 , NULL ) ;
F_9 ( ! V_18 ) ;
F_11 ( V_18 ) ;
return 0 ;
}
