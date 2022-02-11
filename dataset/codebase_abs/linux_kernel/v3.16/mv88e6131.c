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
unsigned long V_11 ;
for ( V_10 = 0 ; V_10 < 11 ; V_10 ++ ) {
V_4 = F_5 ( F_3 ( V_10 ) , 0x04 ) ;
F_6 ( F_3 ( V_10 ) , 0x04 , V_4 & 0xfffc ) ;
}
F_7 ( 2000 , 4000 ) ;
F_6 ( V_12 , 0x04 , 0xc400 ) ;
V_11 = V_13 + 1 * V_14 ;
while ( F_8 ( V_13 , V_11 ) ) {
V_4 = F_5 ( V_12 , 0x00 ) ;
if ( ( V_4 & 0xc800 ) == 0xc800 )
break;
F_7 ( 1000 , 2000 ) ;
}
if ( F_9 ( V_13 , V_11 ) )
return - V_15 ;
return 0 ;
}
static int F_10 ( struct V_8 * V_9 )
{
int V_4 ;
int V_10 ;
F_6 ( V_12 , 0x04 , 0x4400 ) ;
F_6 ( V_12 , 0x0a , 0x0148 ) ;
V_4 = F_11 ( V_9 ) ;
if ( V_4 < 0 )
return V_4 ;
F_6 ( V_12 , 0x19 , 0x8100 ) ;
F_6 ( V_12 , 0x1a , ( F_12 ( V_9 ) * 0x1100 ) | 0x00f0 ) ;
if ( V_9 -> V_16 -> V_17 -> V_18 > 1 )
F_6 ( V_12 , 0x1c , 0xf000 | ( V_9 -> V_19 & 0x1f ) ) ;
else
F_6 ( V_12 , 0x1c , 0xe000 | ( V_9 -> V_19 & 0x1f ) ) ;
F_6 ( V_20 , 0x03 , 0xffff ) ;
F_6 ( V_20 , 0x05 , 0x00ff ) ;
for ( V_10 = 0 ; V_10 < 32 ; V_10 ++ ) {
int V_21 ;
V_21 = 0x1f ;
if ( V_10 != V_9 -> V_19 && V_10 < V_9 -> V_16 -> V_17 -> V_18 )
V_21 = V_9 -> V_17 -> V_22 [ V_10 ] & 0x1f ;
F_6 ( V_20 , 0x06 , 0x8000 | ( V_10 << 8 ) | V_21 ) ;
}
for ( V_10 = 0 ; V_10 < 8 ; V_10 ++ )
F_6 ( V_20 , 0x07 , 0x8000 | ( V_10 << 12 ) | 0x7ff ) ;
for ( V_10 = 0 ; V_10 < 16 ; V_10 ++ )
F_6 ( V_20 , 0x08 , 0x8000 | ( V_10 << 11 ) ) ;
F_6 ( V_20 , 0x0f , 0x00ff ) ;
return 0 ;
}
static int F_13 ( struct V_8 * V_9 , int V_23 )
{
struct V_24 * V_25 = F_14 ( V_9 ) ;
int V_26 = F_3 ( V_23 ) ;
T_1 V_27 ;
if ( F_15 ( V_9 , V_23 ) || V_9 -> V_28 & ( 1 << V_23 ) )
if ( V_25 -> V_29 == V_5 )
F_6 ( V_26 , 0x01 , 0x003d ) ;
else
F_6 ( V_26 , 0x01 , 0x003e ) ;
else
F_6 ( V_26 , 0x01 , 0x0003 ) ;
V_27 = 0x0433 ;
if ( V_23 == F_12 ( V_9 ) ) {
V_27 |= 0x0104 ;
if ( V_25 -> V_29 == V_5 )
V_27 |= 0x0008 ;
}
if ( V_9 -> V_28 & ( 1 << V_23 ) )
V_27 |= 0x0100 ;
F_6 ( V_26 , 0x04 , V_27 ) ;
F_6 ( V_26 , 0x05 , F_15 ( V_9 , V_23 ) ? 0x8000 : 0x0000 ) ;
V_27 = ( V_23 & 0xf ) << 12 ;
if ( F_15 ( V_9 , V_23 ) )
V_27 |= V_9 -> V_30 ;
else
V_27 |= 1 << F_12 ( V_9 ) ;
F_6 ( V_26 , 0x06 , V_27 ) ;
F_6 ( V_26 , 0x07 , 0x0000 ) ;
if ( V_25 -> V_29 == V_5 )
F_6 ( V_26 , 0x08 , 0x0080 ) ;
else {
V_27 = 0x0080 | F_12 ( V_9 ) ;
if ( V_23 == F_12 ( V_9 ) )
V_27 |= 0x0040 ;
F_6 ( V_26 , 0x08 , V_27 ) ;
}
F_6 ( V_26 , 0x09 , 0x0000 ) ;
F_6 ( V_26 , 0x0a , 0x0000 ) ;
F_6 ( V_26 , 0x0b , 1 << V_23 ) ;
F_6 ( V_26 , 0x18 , 0x3210 ) ;
F_6 ( V_26 , 0x19 , 0x7654 ) ;
return 0 ;
}
static int F_16 ( struct V_8 * V_9 )
{
struct V_24 * V_25 = F_14 ( V_9 ) ;
int V_10 ;
int V_4 ;
F_17 ( & V_25 -> V_31 ) ;
F_18 ( V_9 ) ;
F_17 ( & V_25 -> V_32 ) ;
V_25 -> V_29 = F_5 ( F_3 ( 0 ) , 0x03 ) & 0xfff0 ;
V_4 = F_4 ( V_9 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_10 ( V_9 ) ;
if ( V_4 < 0 )
return V_4 ;
for ( V_10 = 0 ; V_10 < 11 ; V_10 ++ ) {
V_4 = F_13 ( V_9 , V_10 ) ;
if ( V_4 < 0 )
return V_4 ;
}
return 0 ;
}
static int F_19 ( int V_33 )
{
if ( V_33 >= 0 && V_33 <= 11 )
return V_33 ;
return - 1 ;
}
static int
F_20 ( struct V_8 * V_9 , int V_33 , int V_34 )
{
int V_26 = F_19 ( V_33 ) ;
return F_21 ( V_9 , V_26 , V_34 ) ;
}
static int
F_22 ( struct V_8 * V_9 ,
int V_33 , int V_34 , T_1 V_27 )
{
int V_26 = F_19 ( V_33 ) ;
return F_23 ( V_9 , V_26 , V_34 , V_27 ) ;
}
static void
F_24 ( struct V_8 * V_9 , int V_33 , T_2 * V_35 )
{
F_25 ( V_9 , F_26 ( V_36 ) ,
V_36 , V_33 , V_35 ) ;
}
static void
F_27 ( struct V_8 * V_9 ,
int V_33 , T_3 * V_35 )
{
F_28 ( V_9 , F_26 ( V_36 ) ,
V_36 , V_33 , V_35 ) ;
}
static int F_29 ( struct V_8 * V_9 )
{
return F_26 ( V_36 ) ;
}
