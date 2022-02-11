static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
return F_2 ( V_2 -> V_5 , V_2 -> V_6 -> V_7 + V_3 , V_4 ) ;
}
static int F_3 ( struct V_1 * V_2 , int V_3 , int V_4 , T_1 V_8 )
{
return F_4 ( V_2 -> V_5 , V_2 -> V_6 -> V_7 + V_3 ,
V_4 , V_8 ) ;
}
static char * F_5 ( struct V_9 * V_10 , int V_7 )
{
int V_11 ;
V_11 = F_2 ( V_10 , V_7 + F_6 ( 0 ) , 0x03 ) ;
if ( V_11 >= 0 ) {
V_11 &= 0xfff0 ;
if ( V_11 == 0x0600 )
return L_1 ;
}
return NULL ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_12 ;
int V_11 ;
for ( V_12 = 0 ; V_12 < 6 ; V_12 ++ ) {
V_11 = F_8 ( F_6 ( V_12 ) , 0x04 ) ;
F_9 ( F_6 ( V_12 ) , 0x04 , V_11 & 0xfffc ) ;
}
F_10 ( 2 ) ;
F_9 ( V_13 , 0x0a , 0xa130 ) ;
for ( V_12 = 0 ; V_12 < 1000 ; V_12 ++ ) {
V_11 = F_8 ( V_13 , 0x00 ) ;
if ( ( V_11 & 0x8000 ) == 0x0000 )
break;
F_10 ( 1 ) ;
}
if ( V_12 == 1000 )
return - V_14 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
F_9 ( V_13 , 0x04 , 0x0800 ) ;
F_9 ( V_13 , 0x0a , 0x2130 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , int V_15 )
{
int V_3 = F_6 ( V_15 ) ;
F_9 ( V_3 , 0x04 , F_13 ( V_2 , V_15 ) ? 0x4103 : 0x0003 ) ;
F_9 ( V_3 , 0x06 ,
( ( V_15 & 0xf ) << 12 ) |
( F_13 ( V_2 , V_15 ) ?
V_2 -> V_16 :
( 1 << V_2 -> V_17 -> V_18 ) ) ) ;
F_9 ( V_3 , 0x0b , 1 << V_15 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_12 ;
int V_11 ;
V_11 = F_7 ( V_2 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_11 ( V_2 ) ;
if ( V_11 < 0 )
return V_11 ;
for ( V_12 = 0 ; V_12 < 6 ; V_12 ++ ) {
V_11 = F_12 ( V_2 , V_12 ) ;
if ( V_11 < 0 )
return V_11 ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , T_2 * V_3 )
{
F_9 ( V_13 , 0x01 , ( V_3 [ 0 ] << 8 ) | V_3 [ 1 ] ) ;
F_9 ( V_13 , 0x02 , ( V_3 [ 2 ] << 8 ) | V_3 [ 3 ] ) ;
F_9 ( V_13 , 0x03 , ( V_3 [ 4 ] << 8 ) | V_3 [ 5 ] ) ;
return 0 ;
}
static int F_16 ( int V_19 )
{
if ( V_19 >= 0 && V_19 <= 5 )
return V_19 ;
return - 1 ;
}
static int F_17 ( struct V_1 * V_2 , int V_19 , int V_20 )
{
int V_3 ;
V_3 = F_16 ( V_19 ) ;
if ( V_3 == - 1 )
return 0xffff ;
return F_1 ( V_2 , V_3 , V_20 ) ;
}
static int
F_18 ( struct V_1 * V_2 , int V_19 , int V_20 , T_1 V_8 )
{
int V_3 ;
V_3 = F_16 ( V_19 ) ;
if ( V_3 == - 1 )
return 0xffff ;
return F_3 ( V_2 , V_3 , V_20 , V_8 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_21 ; V_12 ++ ) {
struct V_22 * V_23 ;
int V_24 ( V_25 ) ;
int V_26 ;
int V_27 ;
int V_28 ;
int V_29 ;
V_23 = V_2 -> V_30 [ V_12 ] ;
if ( V_23 == NULL )
continue;
V_26 = 0 ;
if ( V_23 -> V_31 & V_32 ) {
V_25 = F_1 ( V_2 , F_6 ( V_12 ) , 0x00 ) ;
if ( V_25 < 0 )
continue;
V_26 = ! ! ( V_25 & 0x1000 ) ;
}
if ( ! V_26 ) {
if ( F_20 ( V_23 ) ) {
F_21 ( V_33 L_2 , V_23 -> V_34 ) ;
F_22 ( V_23 ) ;
}
continue;
}
V_27 = ( V_25 & 0x0100 ) ? 100 : 10 ;
V_28 = ( V_25 & 0x0200 ) ? 1 : 0 ;
V_29 = ( ( V_25 & 0xc000 ) == 0xc000 ) ? 1 : 0 ;
if ( ! F_20 ( V_23 ) ) {
F_21 ( V_33 L_3
L_4 , V_23 -> V_34 ,
V_27 , V_28 ? L_5 : L_6 ,
V_29 ? L_7 : L_8 ) ;
F_23 ( V_23 ) ;
}
}
}
static int T_3 F_24 ( void )
{
F_25 ( & V_35 ) ;
return 0 ;
}
static void T_4 F_26 ( void )
{
F_27 ( & V_35 ) ;
}
