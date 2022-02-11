static unsigned long F_1 ( void * V_1 ,
struct V_2 * V_3 )
{
return V_3 -> V_4 ( V_1 ) ;
}
static void F_2 ( void * V_1 ,
struct V_2 * V_3 ,
int V_5 , unsigned long V_6 )
{
if ( V_5 )
V_3 -> V_7 ( V_1 , V_6 ) ;
else
V_3 -> V_8 ( V_1 , V_6 ) ;
}
static void V_7 ( void * V_1 ,
struct V_2 * V_3 ,
unsigned char const * V_9 , int V_10 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_10 ; V_5 ++ )
F_2 ( V_1 , V_3 , 1 , V_9 [ V_5 ] ) ;
}
static unsigned long F_3 ( void * V_1 ,
struct V_2 * V_3 )
{
unsigned long V_11 ;
F_2 ( V_1 , V_3 , 0 , 0xb0 ) ;
F_2 ( V_1 , V_3 , 1 , 0x00 ) ;
F_2 ( V_1 , V_3 , 0 , 0xb1 ) ;
F_2 ( V_1 , V_3 , 1 , 0x00 ) ;
F_2 ( V_1 , V_3 , 0 , 0xbf ) ;
F_4 ( 50 ) ;
F_1 ( V_1 , V_3 ) ;
V_11 = ( ( F_1 ( V_1 , V_3 ) & 0xff ) << 24 ) ;
V_11 |= ( ( F_1 ( V_1 , V_3 ) & 0xff ) << 16 ) ;
V_11 |= ( ( F_1 ( V_1 , V_3 ) & 0xff ) << 8 ) ;
V_11 |= ( F_1 ( V_1 , V_3 ) & 0xff ) ;
return V_11 ;
}
static void F_5 ( void * V_1 ,
struct V_2 * V_3 )
{
F_2 ( V_1 , V_3 , 0 , 0x2c ) ;
}
static void F_6 ( void * V_1 ,
struct V_2 * V_3 )
{
int V_5 ;
F_5 ( V_1 , V_3 ) ;
for ( V_5 = 0 ; V_5 < ( 240 * 400 ) ; V_5 ++ )
F_2 ( V_1 , V_3 , 1 , 0x00 ) ;
}
static void F_7 ( void * V_1 ,
struct V_2 * V_3 )
{
F_2 ( V_1 , V_3 , 0 , 0xb0 ) ;
F_2 ( V_1 , V_3 , 1 , 0x00 ) ;
F_2 ( V_1 , V_3 , 0 , 0xb1 ) ;
F_2 ( V_1 , V_3 , 1 , 0x00 ) ;
F_2 ( V_1 , V_3 , 0 , 0xb3 ) ;
V_7 ( V_1 , V_3 , V_12 , F_8 ( V_12 ) ) ;
F_2 ( V_1 , V_3 , 0 , 0xb4 ) ;
F_2 ( V_1 , V_3 , 1 , 0x00 ) ;
F_2 ( V_1 , V_3 , 0 , 0xc0 ) ;
V_7 ( V_1 , V_3 , V_13 , F_8 ( V_13 ) ) ;
F_2 ( V_1 , V_3 , 0 , 0xc1 ) ;
V_7 ( V_1 , V_3 , V_14 , F_8 ( V_14 ) ) ;
F_2 ( V_1 , V_3 , 0 , 0xc2 ) ;
V_7 ( V_1 , V_3 , V_14 , F_8 ( V_14 ) ) ;
F_2 ( V_1 , V_3 , 0 , 0xc3 ) ;
V_7 ( V_1 , V_3 , V_14 , F_8 ( V_14 ) ) ;
F_2 ( V_1 , V_3 , 0 , 0xc4 ) ;
V_7 ( V_1 , V_3 , V_15 , F_8 ( V_15 ) ) ;
F_2 ( V_1 , V_3 , 0 , 0xc8 ) ;
V_7 ( V_1 , V_3 , V_16 , F_8 ( V_16 ) ) ;
F_2 ( V_1 , V_3 , 0 , 0xc9 ) ;
V_7 ( V_1 , V_3 , V_16 , F_8 ( V_16 ) ) ;
F_2 ( V_1 , V_3 , 0 , 0xca ) ;
V_7 ( V_1 , V_3 , V_16 , F_8 ( V_16 ) ) ;
F_2 ( V_1 , V_3 , 0 , 0xd0 ) ;
V_7 ( V_1 , V_3 , V_17 , F_8 ( V_17 ) ) ;
F_2 ( V_1 , V_3 , 0 , 0xd1 ) ;
F_2 ( V_1 , V_3 , 1 , 0x00 ) ;
F_2 ( V_1 , V_3 , 1 , 0x0f ) ;
F_2 ( V_1 , V_3 , 1 , 0x02 ) ;
F_2 ( V_1 , V_3 , 0 , 0xd2 ) ;
F_2 ( V_1 , V_3 , 1 , 0x63 ) ;
F_2 ( V_1 , V_3 , 1 , 0x24 ) ;
F_2 ( V_1 , V_3 , 0 , 0xd3 ) ;
F_2 ( V_1 , V_3 , 1 , 0x63 ) ;
F_2 ( V_1 , V_3 , 1 , 0x24 ) ;
F_2 ( V_1 , V_3 , 0 , 0xd4 ) ;
F_2 ( V_1 , V_3 , 1 , 0x63 ) ;
F_2 ( V_1 , V_3 , 1 , 0x24 ) ;
F_2 ( V_1 , V_3 , 0 , 0xd8 ) ;
F_2 ( V_1 , V_3 , 1 , 0x77 ) ;
F_2 ( V_1 , V_3 , 1 , 0x77 ) ;
F_2 ( V_1 , V_3 , 0 , 0x35 ) ;
F_2 ( V_1 , V_3 , 1 , 0x00 ) ;
F_2 ( V_1 , V_3 , 0 , 0x44 ) ;
F_2 ( V_1 , V_3 , 1 , 0x00 ) ;
F_2 ( V_1 , V_3 , 1 , 0x00 ) ;
F_2 ( V_1 , V_3 , 0 , 0x2a ) ;
F_2 ( V_1 , V_3 , 1 , 0x00 ) ;
F_2 ( V_1 , V_3 , 1 , 0x00 ) ;
F_2 ( V_1 , V_3 , 1 , 0x00 ) ;
F_2 ( V_1 , V_3 , 1 , 0xef ) ;
F_2 ( V_1 , V_3 , 0 , 0x2b ) ;
F_2 ( V_1 , V_3 , 1 , 0x00 ) ;
F_2 ( V_1 , V_3 , 1 , 0x00 ) ;
F_2 ( V_1 , V_3 , 1 , 0x01 ) ;
F_2 ( V_1 , V_3 , 1 , 0x8f ) ;
F_2 ( V_1 , V_3 , 0 , 0x11 ) ;
F_4 ( 120 ) ;
F_6 ( V_1 , V_3 ) ;
F_2 ( V_1 , V_3 , 0 , 0x29 ) ;
F_4 ( 1 ) ;
F_5 ( V_1 , V_3 ) ;
}
int F_9 ( void * V_1 , struct V_2 * V_3 )
{
F_10 ( V_18 , 0 ) ;
F_10 ( V_19 , 0 ) ;
F_10 ( V_18 , 1 ) ;
F_11 ( 1100 ) ;
F_10 ( V_19 , 1 ) ;
F_11 ( 10 ) ;
F_10 ( V_18 , 0 ) ;
F_4 ( 20 ) ;
if ( F_3 ( V_1 , V_3 ) != 0x01221517 )
return - V_20 ;
F_12 ( L_1 ) ;
F_7 ( V_1 , V_3 ) ;
return 0 ;
}
void F_13 ( void * V_1 , struct V_2 * V_3 )
{
F_5 ( V_1 , V_3 ) ;
}
