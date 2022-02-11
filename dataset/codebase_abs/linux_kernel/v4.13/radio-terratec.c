static struct V_1 * F_1 ( void )
{
return F_2 ( sizeof( struct V_1 ) , V_2 ) ;
}
static int F_3 ( struct V_1 * V_3 , bool V_4 , int V_5 )
{
int V_6 ;
if ( V_4 )
V_5 = 0 ;
V_5 = V_5 + ( V_5 * 32 ) ;
for ( V_6 = 0 ; V_6 < 8 ; V_6 ++ ) {
if ( V_5 & ( 0x80 >> V_6 ) )
F_4 ( 0x80 , V_3 -> V_7 + 1 ) ;
else
F_4 ( 0x00 , V_3 -> V_7 + 1 ) ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_3 , T_1 V_8 )
{
int V_6 ;
int V_9 ;
int V_10 ;
long V_11 ;
unsigned char V_12 [ 25 ] ;
V_8 = V_8 / 160 ;
memset ( V_12 , 0 , sizeof( V_12 ) ) ;
V_11 = V_8 * 10 + 10700 ;
V_6 = 13 ;
V_9 = 10 ;
V_10 = 102400 ;
while ( V_11 != 0 ) {
if ( V_11 % V_10 == V_11 )
V_12 [ V_6 ] = 0 ;
else {
V_12 [ V_6 ] = 1 ;
V_11 = V_11 - V_10 ;
}
V_6 -- ;
V_9 -- ;
V_10 = V_10 / 2 ;
}
for ( V_6 = 24 ; V_6 > - 1 ; V_6 -- ) {
if ( V_12 [ V_6 ] == 1 ) {
F_4 ( V_13 | V_14 , V_3 -> V_7 ) ;
F_4 ( V_13 | V_14 | V_15 , V_3 -> V_7 ) ;
F_4 ( V_13 | V_14 , V_3 -> V_7 ) ;
} else {
F_4 ( V_13 | 0x00 , V_3 -> V_7 ) ;
F_4 ( V_13 | 0x00 | V_15 , V_3 -> V_7 ) ;
}
}
F_4 ( 0x00 , V_3 -> V_7 ) ;
return 0 ;
}
static T_1 F_6 ( struct V_1 * V_3 )
{
return ( F_7 ( V_3 -> V_7 ) & 2 ) ? 0 : 0xffff ;
}
static int T_2 F_8 ( void )
{
return F_9 ( & V_16 . V_17 , 1 ) ;
}
static void T_3 F_10 ( void )
{
F_11 ( & V_16 . V_17 ) ;
}
