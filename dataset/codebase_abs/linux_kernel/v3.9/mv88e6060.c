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
unsigned long V_13 ;
for ( V_12 = 0 ; V_12 < 6 ; V_12 ++ ) {
V_11 = F_8 ( F_6 ( V_12 ) , 0x04 ) ;
F_9 ( F_6 ( V_12 ) , 0x04 , V_11 & 0xfffc ) ;
}
F_10 ( 2000 , 4000 ) ;
F_9 ( V_14 , 0x0a , 0xa130 ) ;
V_13 = V_15 + 1 * V_16 ;
while ( F_11 ( V_15 , V_13 ) ) {
V_11 = F_8 ( V_14 , 0x00 ) ;
if ( ( V_11 & 0x8000 ) == 0x0000 )
break;
F_10 ( 1000 , 2000 ) ;
}
if ( F_12 ( V_15 , V_13 ) )
return - V_17 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
F_9 ( V_14 , 0x04 , 0x0800 ) ;
F_9 ( V_14 , 0x0a , 0x2130 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , int V_18 )
{
int V_3 = F_6 ( V_18 ) ;
F_9 ( V_3 , 0x04 , F_15 ( V_2 , V_18 ) ? 0x4103 : 0x0003 ) ;
F_9 ( V_3 , 0x06 ,
( ( V_18 & 0xf ) << 12 ) |
( F_15 ( V_2 , V_18 ) ?
V_2 -> V_19 :
( 1 << V_2 -> V_20 -> V_21 ) ) ) ;
F_9 ( V_3 , 0x0b , 1 << V_18 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_12 ;
int V_11 ;
V_11 = F_7 ( V_2 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_13 ( V_2 ) ;
if ( V_11 < 0 )
return V_11 ;
for ( V_12 = 0 ; V_12 < 6 ; V_12 ++ ) {
V_11 = F_14 ( V_2 , V_12 ) ;
if ( V_11 < 0 )
return V_11 ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , T_2 * V_3 )
{
F_9 ( V_14 , 0x01 , ( V_3 [ 0 ] << 8 ) | V_3 [ 1 ] ) ;
F_9 ( V_14 , 0x02 , ( V_3 [ 2 ] << 8 ) | V_3 [ 3 ] ) ;
F_9 ( V_14 , 0x03 , ( V_3 [ 4 ] << 8 ) | V_3 [ 5 ] ) ;
return 0 ;
}
static int F_18 ( int V_22 )
{
if ( V_22 >= 0 && V_22 <= 5 )
return V_22 ;
return - 1 ;
}
static int F_19 ( struct V_1 * V_2 , int V_22 , int V_23 )
{
int V_3 ;
V_3 = F_18 ( V_22 ) ;
if ( V_3 == - 1 )
return 0xffff ;
return F_1 ( V_2 , V_3 , V_23 ) ;
}
static int
F_20 ( struct V_1 * V_2 , int V_22 , int V_23 , T_1 V_8 )
{
int V_3 ;
V_3 = F_18 ( V_22 ) ;
if ( V_3 == - 1 )
return 0xffff ;
return F_3 ( V_2 , V_3 , V_23 , V_8 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_24 ; V_12 ++ ) {
struct V_25 * V_26 ;
int V_27 ( V_28 ) ;
int V_29 ;
int V_30 ;
int V_31 ;
int V_32 ;
V_26 = V_2 -> V_33 [ V_12 ] ;
if ( V_26 == NULL )
continue;
V_29 = 0 ;
if ( V_26 -> V_34 & V_35 ) {
V_28 = F_1 ( V_2 , F_6 ( V_12 ) , 0x00 ) ;
if ( V_28 < 0 )
continue;
V_29 = ! ! ( V_28 & 0x1000 ) ;
}
if ( ! V_29 ) {
if ( F_22 ( V_26 ) ) {
F_23 ( V_26 , L_2 ) ;
F_24 ( V_26 ) ;
}
continue;
}
V_30 = ( V_28 & 0x0100 ) ? 100 : 10 ;
V_31 = ( V_28 & 0x0200 ) ? 1 : 0 ;
V_32 = ( ( V_28 & 0xc000 ) == 0xc000 ) ? 1 : 0 ;
if ( ! F_22 ( V_26 ) ) {
F_23 ( V_26 ,
L_3 ,
V_30 ,
V_31 ? L_4 : L_5 ,
V_32 ? L_6 : L_7 ) ;
F_25 ( V_26 ) ;
}
}
}
static int T_3 F_26 ( void )
{
F_27 ( & V_36 ) ;
return 0 ;
}
static void T_4 F_28 ( void )
{
F_29 ( & V_36 ) ;
}
