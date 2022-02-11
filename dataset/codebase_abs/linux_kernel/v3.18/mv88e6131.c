static char * F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 ;
if ( V_5 == NULL )
return NULL ;
V_6 = F_3 ( V_5 , V_3 , F_4 ( 0 ) , 0x03 ) ;
if ( V_6 >= 0 ) {
V_6 &= 0xfff0 ;
if ( V_6 == V_7 )
return L_1 ;
if ( V_6 == V_8 )
return L_2 ;
if ( V_6 == V_9 )
return L_3 ;
}
return NULL ;
}
static int F_5 ( struct V_10 * V_11 )
{
int V_12 ;
int V_6 ;
unsigned long V_13 ;
for ( V_12 = 0 ; V_12 < 11 ; V_12 ++ ) {
V_6 = F_6 ( F_4 ( V_12 ) , 0x04 ) ;
F_7 ( F_4 ( V_12 ) , 0x04 , V_6 & 0xfffc ) ;
}
F_8 ( 2000 , 4000 ) ;
F_7 ( V_14 , 0x04 , 0xc400 ) ;
V_13 = V_15 + 1 * V_16 ;
while ( F_9 ( V_15 , V_13 ) ) {
V_6 = F_6 ( V_14 , 0x00 ) ;
if ( ( V_6 & 0xc800 ) == 0xc800 )
break;
F_8 ( 1000 , 2000 ) ;
}
if ( F_10 ( V_15 , V_13 ) )
return - V_17 ;
return 0 ;
}
static int F_11 ( struct V_10 * V_11 )
{
int V_6 ;
int V_12 ;
F_7 ( V_14 , 0x04 , 0x4400 ) ;
F_7 ( V_14 , 0x0a , 0x0148 ) ;
V_6 = F_12 ( V_11 ) ;
if ( V_6 < 0 )
return V_6 ;
F_7 ( V_14 , 0x19 , 0x8100 ) ;
F_7 ( V_14 , 0x1a , ( F_13 ( V_11 ) * 0x1100 ) | 0x00f0 ) ;
if ( V_11 -> V_18 -> V_19 -> V_20 > 1 )
F_7 ( V_14 , 0x1c , 0xf000 | ( V_11 -> V_21 & 0x1f ) ) ;
else
F_7 ( V_14 , 0x1c , 0xe000 | ( V_11 -> V_21 & 0x1f ) ) ;
F_7 ( V_22 , 0x03 , 0xffff ) ;
F_7 ( V_22 , 0x05 , 0x00ff ) ;
for ( V_12 = 0 ; V_12 < 32 ; V_12 ++ ) {
int V_23 ;
V_23 = 0x1f ;
if ( V_12 != V_11 -> V_21 && V_12 < V_11 -> V_18 -> V_19 -> V_20 )
V_23 = V_11 -> V_19 -> V_24 [ V_12 ] & 0x1f ;
F_7 ( V_22 , 0x06 , 0x8000 | ( V_12 << 8 ) | V_23 ) ;
}
for ( V_12 = 0 ; V_12 < 8 ; V_12 ++ )
F_7 ( V_22 , 0x07 , 0x8000 | ( V_12 << 12 ) | 0x7ff ) ;
for ( V_12 = 0 ; V_12 < 16 ; V_12 ++ )
F_7 ( V_22 , 0x08 , 0x8000 | ( V_12 << 11 ) ) ;
F_7 ( V_22 , 0x0f , 0x00ff ) ;
return 0 ;
}
static int F_14 ( struct V_10 * V_11 , int V_25 )
{
struct V_26 * V_27 = F_15 ( V_11 ) ;
int V_28 = F_4 ( V_25 ) ;
T_1 V_29 ;
if ( F_16 ( V_11 , V_25 ) || V_11 -> V_30 & ( 1 << V_25 ) )
if ( V_27 -> V_31 == V_7 )
F_7 ( V_28 , 0x01 , 0x003d ) ;
else
F_7 ( V_28 , 0x01 , 0x003e ) ;
else
F_7 ( V_28 , 0x01 , 0x0003 ) ;
V_29 = 0x0433 ;
if ( V_25 == F_13 ( V_11 ) ) {
V_29 |= 0x0104 ;
if ( V_27 -> V_31 == V_7 )
V_29 |= 0x0008 ;
}
if ( V_11 -> V_30 & ( 1 << V_25 ) )
V_29 |= 0x0100 ;
F_7 ( V_28 , 0x04 , V_29 ) ;
F_7 ( V_28 , 0x05 , F_16 ( V_11 , V_25 ) ? 0x8000 : 0x0000 ) ;
V_29 = ( V_25 & 0xf ) << 12 ;
if ( F_16 ( V_11 , V_25 ) )
V_29 |= V_11 -> V_32 ;
else
V_29 |= 1 << F_13 ( V_11 ) ;
F_7 ( V_28 , 0x06 , V_29 ) ;
F_7 ( V_28 , 0x07 , 0x0000 ) ;
if ( V_27 -> V_31 == V_7 )
F_7 ( V_28 , 0x08 , 0x0080 ) ;
else {
V_29 = 0x0080 | F_13 ( V_11 ) ;
if ( V_25 == F_13 ( V_11 ) )
V_29 |= 0x0040 ;
F_7 ( V_28 , 0x08 , V_29 ) ;
}
F_7 ( V_28 , 0x09 , 0x0000 ) ;
F_7 ( V_28 , 0x0a , 0x0000 ) ;
F_7 ( V_28 , 0x0b , 1 << V_25 ) ;
F_7 ( V_28 , 0x18 , 0x3210 ) ;
F_7 ( V_28 , 0x19 , 0x7654 ) ;
return 0 ;
}
static int F_17 ( struct V_10 * V_11 )
{
struct V_26 * V_27 = F_15 ( V_11 ) ;
int V_12 ;
int V_6 ;
F_18 ( & V_27 -> V_33 ) ;
F_19 ( V_11 ) ;
F_18 ( & V_27 -> V_34 ) ;
V_27 -> V_31 = F_6 ( F_4 ( 0 ) , 0x03 ) & 0xfff0 ;
V_6 = F_5 ( V_11 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_11 ( V_11 ) ;
if ( V_6 < 0 )
return V_6 ;
for ( V_12 = 0 ; V_12 < 11 ; V_12 ++ ) {
V_6 = F_14 ( V_11 , V_12 ) ;
if ( V_6 < 0 )
return V_6 ;
}
return 0 ;
}
static int F_20 ( int V_35 )
{
if ( V_35 >= 0 && V_35 <= 11 )
return V_35 ;
return - 1 ;
}
static int
F_21 ( struct V_10 * V_11 , int V_35 , int V_36 )
{
int V_28 = F_20 ( V_35 ) ;
return F_22 ( V_11 , V_28 , V_36 ) ;
}
static int
F_23 ( struct V_10 * V_11 ,
int V_35 , int V_36 , T_1 V_29 )
{
int V_28 = F_20 ( V_35 ) ;
return F_24 ( V_11 , V_28 , V_36 , V_29 ) ;
}
static void
F_25 ( struct V_10 * V_11 , int V_35 , T_2 * V_37 )
{
F_26 ( V_11 , F_27 ( V_38 ) ,
V_38 , V_35 , V_37 ) ;
}
static void
F_28 ( struct V_10 * V_11 ,
int V_35 , T_3 * V_37 )
{
F_29 ( V_11 , F_27 ( V_38 ) ,
V_38 , V_35 , V_37 ) ;
}
static int F_30 ( struct V_10 * V_11 )
{
return F_27 ( V_38 ) ;
}
