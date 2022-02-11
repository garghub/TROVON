static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 ) ;
if ( V_6 == NULL )
return - V_8 ;
return F_3 ( V_6 , V_2 -> V_9 -> V_10 + V_3 , V_4 ) ;
}
static int F_4 ( struct V_1 * V_2 , int V_3 , int V_4 , T_1 V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 ) ;
if ( V_6 == NULL )
return - V_8 ;
return F_5 ( V_6 , V_2 -> V_9 -> V_10 + V_3 , V_4 , V_11 ) ;
}
static char * F_6 ( struct V_12 * V_13 , int V_10 )
{
struct V_5 * V_6 = F_2 ( V_13 ) ;
int V_14 ;
if ( V_6 == NULL )
return NULL ;
V_14 = F_3 ( V_6 , V_10 + F_7 ( 0 ) , 0x03 ) ;
if ( V_14 >= 0 ) {
V_14 &= 0xfff0 ;
if ( V_14 == 0x0600 )
return L_1 ;
}
return NULL ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_15 ;
int V_14 ;
unsigned long V_16 ;
for ( V_15 = 0 ; V_15 < 6 ; V_15 ++ ) {
V_14 = F_9 ( F_7 ( V_15 ) , 0x04 ) ;
F_10 ( F_7 ( V_15 ) , 0x04 , V_14 & 0xfffc ) ;
}
F_11 ( 2000 , 4000 ) ;
F_10 ( V_17 , 0x0a , 0xa130 ) ;
V_16 = V_18 + 1 * V_19 ;
while ( F_12 ( V_18 , V_16 ) ) {
V_14 = F_9 ( V_17 , 0x00 ) ;
if ( ( V_14 & 0x8000 ) == 0x0000 )
break;
F_11 ( 1000 , 2000 ) ;
}
if ( F_13 ( V_18 , V_16 ) )
return - V_20 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
F_10 ( V_17 , 0x04 , 0x0800 ) ;
F_10 ( V_17 , 0x0a , 0x2130 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , int V_21 )
{
int V_3 = F_7 ( V_21 ) ;
F_10 ( V_3 , 0x04 , F_16 ( V_2 , V_21 ) ? 0x4103 : 0x0003 ) ;
F_10 ( V_3 , 0x06 ,
( ( V_21 & 0xf ) << 12 ) |
( F_16 ( V_2 , V_21 ) ?
V_2 -> V_22 :
( 1 << V_2 -> V_23 -> V_24 ) ) ) ;
F_10 ( V_3 , 0x0b , 1 << V_21 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_15 ;
int V_14 ;
V_14 = F_8 ( V_2 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_14 ( V_2 ) ;
if ( V_14 < 0 )
return V_14 ;
for ( V_15 = 0 ; V_15 < 6 ; V_15 ++ ) {
V_14 = F_15 ( V_2 , V_15 ) ;
if ( V_14 < 0 )
return V_14 ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , T_2 * V_3 )
{
F_10 ( V_17 , 0x01 , ( V_3 [ 0 ] << 8 ) | V_3 [ 1 ] ) ;
F_10 ( V_17 , 0x02 , ( V_3 [ 2 ] << 8 ) | V_3 [ 3 ] ) ;
F_10 ( V_17 , 0x03 , ( V_3 [ 4 ] << 8 ) | V_3 [ 5 ] ) ;
return 0 ;
}
static int F_19 ( int V_25 )
{
if ( V_25 >= 0 && V_25 <= 5 )
return V_25 ;
return - 1 ;
}
static int F_20 ( struct V_1 * V_2 , int V_25 , int V_26 )
{
int V_3 ;
V_3 = F_19 ( V_25 ) ;
if ( V_3 == - 1 )
return 0xffff ;
return F_1 ( V_2 , V_3 , V_26 ) ;
}
static int
F_21 ( struct V_1 * V_2 , int V_25 , int V_26 , T_1 V_11 )
{
int V_3 ;
V_3 = F_19 ( V_25 ) ;
if ( V_3 == - 1 )
return 0xffff ;
return F_4 ( V_2 , V_3 , V_26 , V_11 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < V_27 ; V_15 ++ ) {
struct V_28 * V_29 ;
int V_30 ( V_31 ) ;
int V_32 ;
int V_33 ;
int V_34 ;
int V_35 ;
V_29 = V_2 -> V_36 [ V_15 ] ;
if ( V_29 == NULL )
continue;
V_32 = 0 ;
if ( V_29 -> V_37 & V_38 ) {
V_31 = F_1 ( V_2 , F_7 ( V_15 ) , 0x00 ) ;
if ( V_31 < 0 )
continue;
V_32 = ! ! ( V_31 & 0x1000 ) ;
}
if ( ! V_32 ) {
if ( F_23 ( V_29 ) ) {
F_24 ( V_29 , L_2 ) ;
F_25 ( V_29 ) ;
}
continue;
}
V_33 = ( V_31 & 0x0100 ) ? 100 : 10 ;
V_34 = ( V_31 & 0x0200 ) ? 1 : 0 ;
V_35 = ( ( V_31 & 0xc000 ) == 0xc000 ) ? 1 : 0 ;
if ( ! F_23 ( V_29 ) ) {
F_24 ( V_29 ,
L_3 ,
V_33 ,
V_34 ? L_4 : L_5 ,
V_35 ? L_6 : L_7 ) ;
F_26 ( V_29 ) ;
}
}
}
static int T_3 F_27 ( void )
{
F_28 ( & V_39 ) ;
return 0 ;
}
static void T_4 F_29 ( void )
{
F_30 ( & V_39 ) ;
}
