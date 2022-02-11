static char * F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
V_4 = F_2 ( V_2 , V_3 , F_3 ( 0 ) , 0x03 ) ;
if ( V_4 >= 0 ) {
if ( V_4 == 0x1212 )
return L_1 ;
if ( V_4 == 0x1213 )
return L_2 ;
if ( ( V_4 & 0xfff0 ) == 0x1210 )
return L_3 ;
if ( V_4 == 0x1612 )
return L_4 ;
if ( V_4 == 0x1613 )
return L_5 ;
if ( ( V_4 & 0xfff0 ) == 0x1610 )
return L_6 ;
if ( V_4 == 0x1652 )
return L_7 ;
if ( V_4 == 0x1653 )
return L_8 ;
if ( ( V_4 & 0xfff0 ) == 0x1650 )
return L_9 ;
}
return NULL ;
}
static int F_4 ( struct V_5 * V_6 )
{
int V_7 ;
int V_4 ;
for ( V_7 = 0 ; V_7 < 8 ; V_7 ++ ) {
V_4 = F_5 ( F_3 ( V_7 ) , 0x04 ) ;
F_6 ( F_3 ( V_7 ) , 0x04 , V_4 & 0xfffc ) ;
}
F_7 ( 2 ) ;
F_6 ( V_8 , 0x04 , 0xc400 ) ;
for ( V_7 = 0 ; V_7 < 1000 ; V_7 ++ ) {
V_4 = F_5 ( V_8 , 0x00 ) ;
if ( ( V_4 & 0xc800 ) == 0xc800 )
break;
F_7 ( 1 ) ;
}
if ( V_7 == 1000 )
return - V_9 ;
return 0 ;
}
static int F_8 ( struct V_5 * V_6 )
{
int V_4 ;
int V_7 ;
F_6 ( V_8 , 0x04 , 0x0000 ) ;
F_6 ( V_8 , 0x0a , 0x0148 ) ;
V_4 = F_9 ( V_6 ) ;
if ( V_4 < 0 )
return V_4 ;
F_6 ( V_8 , 0x1a , ( F_10 ( V_6 ) * 0x1110 ) ) ;
F_6 ( V_8 , 0x1c , V_6 -> V_10 & 0x1f ) ;
F_6 ( V_11 , 0x02 , 0xffff ) ;
F_6 ( V_11 , 0x03 , 0xffff ) ;
F_6 ( V_11 , 0x05 , 0x00ff ) ;
for ( V_7 = 0 ; V_7 < 32 ; V_7 ++ ) {
int V_12 ;
V_12 = 0x1f ;
if ( V_7 != V_6 -> V_10 && V_7 < V_6 -> V_13 -> V_14 -> V_15 )
V_12 = V_6 -> V_14 -> V_16 [ V_7 ] & 0x1f ;
F_6 ( V_11 , 0x06 , 0x8000 | ( V_7 << 8 ) | V_12 ) ;
}
for ( V_7 = 0 ; V_7 < 8 ; V_7 ++ )
F_6 ( V_11 , 0x07 , 0x8000 | ( V_7 << 12 ) | 0xff ) ;
for ( V_7 = 0 ; V_7 < 16 ; V_7 ++ )
F_6 ( V_11 , 0x08 , 0x8000 | ( V_7 << 11 ) ) ;
for ( V_7 = 0 ; V_7 < 6 ; V_7 ++ )
F_6 ( V_11 , 0x09 , 0x9000 | ( V_7 << 8 ) ) ;
F_6 ( V_11 , 0x0b , 0x9000 ) ;
for ( V_7 = 0 ; V_7 < 16 ; V_7 ++ )
F_6 ( V_11 , 0x0f , 0x8000 | ( V_7 << 8 ) ) ;
return 0 ;
}
static int F_11 ( struct V_5 * V_6 , int V_17 )
{
int V_18 = F_3 ( V_17 ) ;
T_1 V_19 ;
if ( F_12 ( V_6 , V_17 ) || V_6 -> V_20 & ( 1 << V_17 ) )
F_6 ( V_18 , 0x01 , 0x003e ) ;
else
F_6 ( V_18 , 0x01 , 0x0003 ) ;
F_6 ( V_18 , 0x02 , 0x0000 ) ;
V_19 = 0x0433 ;
if ( F_12 ( V_6 , V_17 ) ) {
if ( V_6 -> V_13 -> V_21 == F_13 ( V_22 ) )
V_19 |= 0x3300 ;
else
V_19 |= 0x0100 ;
}
if ( V_6 -> V_20 & ( 1 << V_17 ) )
V_19 |= 0x0100 ;
if ( V_17 == F_10 ( V_6 ) )
V_19 |= 0x000c ;
F_6 ( V_18 , 0x04 , V_19 ) ;
F_6 ( V_18 , 0x05 , F_12 ( V_6 , V_17 ) ? 0x8000 : 0x0000 ) ;
V_19 = ( V_17 & 0xf ) << 12 ;
if ( F_12 ( V_6 , V_17 ) )
V_19 |= V_6 -> V_23 ;
else
V_19 |= 1 << F_10 ( V_6 ) ;
F_6 ( V_18 , 0x06 , V_19 ) ;
F_6 ( V_18 , 0x07 , 0x0000 ) ;
F_6 ( V_18 , 0x08 , 0x2080 ) ;
F_6 ( V_18 , 0x09 , 0x0001 ) ;
F_6 ( V_18 , 0x0a , 0x0000 ) ;
F_6 ( V_18 , 0x0b , 1 << V_17 ) ;
F_6 ( V_18 , 0x0c , 0x0000 ) ;
F_6 ( V_18 , 0x0d , 0x0000 ) ;
F_6 ( V_18 , 0x0f , V_22 ) ;
F_6 ( V_18 , 0x18 , 0x3210 ) ;
F_6 ( V_18 , 0x19 , 0x7654 ) ;
return 0 ;
}
static int F_14 ( struct V_5 * V_6 )
{
struct V_24 * V_25 = ( void * ) ( V_6 + 1 ) ;
int V_7 ;
int V_4 ;
F_15 ( & V_25 -> V_26 ) ;
F_15 ( & V_25 -> V_27 ) ;
V_4 = F_4 ( V_6 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_8 ( V_6 ) ;
if ( V_4 < 0 )
return V_4 ;
for ( V_7 = 0 ; V_7 < 6 ; V_7 ++ ) {
V_4 = F_11 ( V_6 , V_7 ) ;
if ( V_4 < 0 )
return V_4 ;
}
return 0 ;
}
static int F_16 ( int V_28 )
{
if ( V_28 >= 0 && V_28 <= 4 )
return V_28 ;
return - 1 ;
}
static int
F_17 ( struct V_5 * V_6 , int V_28 , int V_29 )
{
int V_18 = F_16 ( V_28 ) ;
return F_18 ( V_6 , V_18 , V_29 ) ;
}
static int
F_19 ( struct V_5 * V_6 ,
int V_28 , int V_29 , T_1 V_19 )
{
int V_18 = F_16 ( V_28 ) ;
return F_20 ( V_6 , V_18 , V_29 , V_19 ) ;
}
static void
F_21 ( struct V_5 * V_6 , int V_28 , T_2 * V_30 )
{
F_22 ( V_6 , F_23 ( V_31 ) ,
V_31 , V_28 , V_30 ) ;
}
static void
F_24 ( struct V_5 * V_6 ,
int V_28 , T_3 * V_30 )
{
F_25 ( V_6 , F_23 ( V_31 ) ,
V_31 , V_28 , V_30 ) ;
}
static int F_26 ( struct V_5 * V_6 )
{
return F_23 ( V_31 ) ;
}
