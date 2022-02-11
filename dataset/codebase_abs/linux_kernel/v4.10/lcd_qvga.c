static void F_1 ( void )
{
F_2 ( V_1 , 0 ) ;
F_3 ( 2 ) ;
F_2 ( V_1 , 1 ) ;
F_3 ( 1 ) ;
}
static unsigned long F_4 ( unsigned short V_2 )
{
unsigned long V_3 , V_4 ;
V_3 = ( V_2 << 1 | 0x00000001 ) & 0x000001FF ;
V_4 = ( V_2 << 2 | 0x00000200 ) & 0x0003FE00 ;
return V_3 | V_4 ;
}
static void F_5 ( void * V_5 ,
struct V_6 * V_7 ,
unsigned short V_8 , unsigned short V_2 )
{
V_7 -> V_9 ( V_5 , F_4 ( V_8 << 8 | V_2 ) ) ;
}
static void F_6 ( void * V_5 ,
struct V_6 * V_7 ,
unsigned short V_8 , unsigned short V_2 )
{
V_7 -> V_9 ( V_5 , F_4 ( V_8 ) ) ;
V_7 -> V_10 ( V_5 , F_4 ( V_2 ) ) ;
}
static unsigned long F_7 ( void * V_5 ,
struct V_6 * V_7 ,
unsigned short V_8 )
{
unsigned long V_2 ;
V_7 -> V_9 ( V_5 , F_4 ( V_8 ) ) ;
V_2 = V_7 -> V_11 ( V_5 ) ;
return ( ( V_2 >> 1 ) & 0xff ) | ( ( V_2 >> 2 ) & 0xff00 ) ;
}
static void F_8 ( void * V_5 ,
struct V_6 * V_7 ,
unsigned short const * V_2 , int V_12 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 += 2 )
F_6 ( V_5 , V_7 , V_2 [ V_13 ] , V_2 [ V_13 + 1 ] ) ;
}
int F_9 ( void * V_14 , struct V_6 * V_15 )
{
unsigned long V_16 = 320 ;
unsigned long V_17 = 240 ;
int V_18 ;
F_1 () ;
F_8 ( V_14 , V_15 , V_19 , F_10 ( V_19 ) ) ;
if ( F_7 ( V_14 , V_15 , 0 ) != 0x1505 )
return - V_20 ;
F_11 ( L_1 ) ;
F_8 ( V_14 , V_15 , V_19 , F_10 ( V_19 ) ) ;
F_6 ( V_14 , V_15 , 0x00A4 , 0x0001 ) ;
F_3 ( 10 ) ;
F_8 ( V_14 , V_15 , V_21 , F_10 ( V_21 ) ) ;
F_3 ( 100 ) ;
F_8 ( V_14 , V_15 , V_22 , F_10 ( V_22 ) ) ;
F_6 ( V_14 , V_15 , 0x0050 , 0xef - ( V_17 - 1 ) ) ;
F_6 ( V_14 , V_15 , 0x0051 , 0x00ef ) ;
F_6 ( V_14 , V_15 , 0x0052 , 0x0000 ) ;
F_6 ( V_14 , V_15 , 0x0053 , V_16 - 1 ) ;
F_8 ( V_14 , V_15 , V_23 , F_10 ( V_23 ) ) ;
F_3 ( 10 ) ;
F_8 ( V_14 , V_15 , V_24 , F_10 ( V_24 ) ) ;
F_3 ( 40 ) ;
F_6 ( V_14 , V_15 , 0x0020 , 0x0000 ) ;
F_6 ( V_14 , V_15 , 0x0021 , 0x0000 ) ;
for ( V_18 = 0 ; V_18 < ( V_16 * 256 ) ; V_18 ++ )
F_6 ( V_14 , V_15 , 0x0022 , 0x0000 ) ;
F_6 ( V_14 , V_15 , 0x0020 , 0x0000 ) ;
F_6 ( V_14 , V_15 , 0x0021 , 0x0000 ) ;
F_6 ( V_14 , V_15 , 0x0007 , 0x0173 ) ;
F_3 ( 40 ) ;
F_5 ( V_14 , V_15 , 0x00 , 0x22 ) ;
F_3 ( 100 ) ;
return 0 ;
}
