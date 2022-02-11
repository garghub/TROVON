static char * F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
V_4 = F_2 ( V_2 , V_3 , F_3 ( 0 ) , 0x03 ) ;
if ( V_4 >= 0 ) {
V_4 &= 0xfff0 ;
if ( V_4 == V_5 )
return L_1 ;
if ( V_4 == V_6 )
return L_2 ;
if ( V_4 == V_7 )
return L_3 ;
}
return NULL ;
}
static int F_4 ( struct V_8 * V_9 )
{
int V_10 ;
int V_4 ;
for ( V_10 = 0 ; V_10 < 11 ; V_10 ++ ) {
V_4 = F_5 ( F_3 ( V_10 ) , 0x04 ) ;
F_6 ( F_3 ( V_10 ) , 0x04 , V_4 & 0xfffc ) ;
}
F_7 ( 2 ) ;
F_6 ( V_11 , 0x04 , 0xc400 ) ;
for ( V_10 = 0 ; V_10 < 1000 ; V_10 ++ ) {
V_4 = F_5 ( V_11 , 0x00 ) ;
if ( ( V_4 & 0xc800 ) == 0xc800 )
break;
F_7 ( 1 ) ;
}
if ( V_10 == 1000 )
return - V_12 ;
return 0 ;
}
static int F_8 ( struct V_8 * V_9 )
{
int V_4 ;
int V_10 ;
F_6 ( V_11 , 0x04 , 0x4400 ) ;
F_6 ( V_11 , 0x0a , 0x0148 ) ;
V_4 = F_9 ( V_9 ) ;
if ( V_4 < 0 )
return V_4 ;
F_6 ( V_11 , 0x19 , 0x8100 ) ;
F_6 ( V_11 , 0x1a , ( F_10 ( V_9 ) * 0x1100 ) | 0x00f0 ) ;
F_6 ( V_11 , 0x1c , 0xe000 | ( V_9 -> V_13 & 0x1f ) ) ;
F_6 ( V_14 , 0x03 , 0xffff ) ;
F_6 ( V_14 , 0x05 , 0x00ff ) ;
for ( V_10 = 0 ; V_10 < 32 ; V_10 ++ ) {
int V_15 ;
V_15 = 0x1f ;
if ( V_10 != V_9 -> V_13 && V_10 < V_9 -> V_16 -> V_17 -> V_18 )
V_15 = V_9 -> V_17 -> V_19 [ V_10 ] & 0x1f ;
F_6 ( V_14 , 0x06 , 0x8000 | ( V_10 << 8 ) | V_15 ) ;
}
for ( V_10 = 0 ; V_10 < 8 ; V_10 ++ )
F_6 ( V_14 , 0x07 , 0x8000 | ( V_10 << 12 ) | 0x7ff ) ;
for ( V_10 = 0 ; V_10 < 16 ; V_10 ++ )
F_6 ( V_14 , 0x08 , 0x8000 | ( V_10 << 11 ) ) ;
F_6 ( V_14 , 0x0f , 0x00ff ) ;
return 0 ;
}
static int F_11 ( struct V_8 * V_9 , int V_20 )
{
struct V_21 * V_22 = ( void * ) ( V_9 + 1 ) ;
int V_23 = F_3 ( V_20 ) ;
T_1 V_24 ;
if ( F_12 ( V_9 , V_20 ) || V_9 -> V_25 & ( 1 << V_20 ) )
if ( V_22 -> V_26 == V_5 )
F_6 ( V_23 , 0x01 , 0x003d ) ;
else
F_6 ( V_23 , 0x01 , 0x003e ) ;
else
F_6 ( V_23 , 0x01 , 0x0003 ) ;
V_24 = 0x0433 ;
if ( V_20 == F_10 ( V_9 ) ) {
V_24 |= 0x0104 ;
if ( V_22 -> V_26 == V_5 )
V_24 |= 0x0008 ;
}
if ( V_9 -> V_25 & ( 1 << V_20 ) )
V_24 |= 0x0100 ;
F_6 ( V_23 , 0x04 , V_24 ) ;
F_6 ( V_23 , 0x05 , F_12 ( V_9 , V_20 ) ? 0x8000 : 0x0000 ) ;
V_24 = ( V_20 & 0xf ) << 12 ;
if ( F_12 ( V_9 , V_20 ) )
V_24 |= V_9 -> V_27 ;
else
V_24 |= 1 << F_10 ( V_9 ) ;
F_6 ( V_23 , 0x06 , V_24 ) ;
F_6 ( V_23 , 0x07 , 0x0000 ) ;
if ( V_22 -> V_26 == V_5 )
F_6 ( V_23 , 0x08 , 0x0080 ) ;
else {
V_24 = 0x0080 | F_10 ( V_9 ) ;
if ( V_20 == F_10 ( V_9 ) )
V_24 |= 0x0040 ;
F_6 ( V_23 , 0x08 , V_24 ) ;
}
F_6 ( V_23 , 0x09 , 0x0000 ) ;
F_6 ( V_23 , 0x0a , 0x0000 ) ;
F_6 ( V_23 , 0x0b , 1 << V_20 ) ;
F_6 ( V_23 , 0x18 , 0x3210 ) ;
F_6 ( V_23 , 0x19 , 0x7654 ) ;
return 0 ;
}
static int F_13 ( struct V_8 * V_9 )
{
struct V_21 * V_22 = ( void * ) ( V_9 + 1 ) ;
int V_10 ;
int V_4 ;
F_14 ( & V_22 -> V_28 ) ;
F_15 ( V_9 ) ;
F_14 ( & V_22 -> V_29 ) ;
V_22 -> V_26 = F_5 ( F_3 ( 0 ) , 0x03 ) & 0xfff0 ;
V_4 = F_4 ( V_9 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_8 ( V_9 ) ;
if ( V_4 < 0 )
return V_4 ;
for ( V_10 = 0 ; V_10 < 11 ; V_10 ++ ) {
V_4 = F_11 ( V_9 , V_10 ) ;
if ( V_4 < 0 )
return V_4 ;
}
return 0 ;
}
static int F_16 ( int V_30 )
{
if ( V_30 >= 0 && V_30 <= 11 )
return V_30 ;
return - 1 ;
}
static int
F_17 ( struct V_8 * V_9 , int V_30 , int V_31 )
{
int V_23 = F_16 ( V_30 ) ;
return F_18 ( V_9 , V_23 , V_31 ) ;
}
static int
F_19 ( struct V_8 * V_9 ,
int V_30 , int V_31 , T_1 V_24 )
{
int V_23 = F_16 ( V_30 ) ;
return F_20 ( V_9 , V_23 , V_31 , V_24 ) ;
}
static void
F_21 ( struct V_8 * V_9 , int V_30 , T_2 * V_32 )
{
F_22 ( V_9 , F_23 ( V_33 ) ,
V_33 , V_30 , V_32 ) ;
}
static void
F_24 ( struct V_8 * V_9 ,
int V_30 , T_3 * V_32 )
{
F_25 ( V_9 , F_23 ( V_33 ) ,
V_33 , V_30 , V_32 ) ;
}
static int F_26 ( struct V_8 * V_9 )
{
return F_23 ( V_33 ) ;
}
static int T_4 F_27 ( void )
{
F_28 ( & V_34 ) ;
return 0 ;
}
static void T_5 F_29 ( void )
{
F_30 ( & V_34 ) ;
}
