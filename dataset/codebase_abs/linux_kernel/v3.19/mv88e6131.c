static char * F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 ;
if ( V_5 == NULL )
return NULL ;
V_6 = F_3 ( V_5 , V_3 , F_4 ( 0 ) , 0x03 ) ;
if ( V_6 >= 0 ) {
int V_7 = V_6 & 0xfff0 ;
if ( V_7 == V_8 )
return L_1 ;
if ( V_7 == V_9 )
return L_2 ;
if ( V_6 == V_10 )
return L_3 ;
if ( V_7 == V_11 )
return L_4 ;
}
return NULL ;
}
static int F_5 ( struct V_12 * V_13 )
{
int V_14 ;
int V_6 ;
unsigned long V_15 ;
for ( V_14 = 0 ; V_14 < 11 ; V_14 ++ ) {
V_6 = F_6 ( F_4 ( V_14 ) , 0x04 ) ;
F_7 ( F_4 ( V_14 ) , 0x04 , V_6 & 0xfffc ) ;
}
F_8 ( 2000 , 4000 ) ;
F_7 ( V_16 , 0x04 , 0xc400 ) ;
V_15 = V_17 + 1 * V_18 ;
while ( F_9 ( V_17 , V_15 ) ) {
V_6 = F_6 ( V_16 , 0x00 ) ;
if ( ( V_6 & 0xc800 ) == 0xc800 )
break;
F_8 ( 1000 , 2000 ) ;
}
if ( F_10 ( V_17 , V_15 ) )
return - V_19 ;
return 0 ;
}
static int F_11 ( struct V_12 * V_13 )
{
int V_6 ;
int V_14 ;
F_7 ( V_16 , 0x04 , 0x4400 ) ;
F_7 ( V_16 , 0x0a , 0x0148 ) ;
V_6 = F_12 ( V_13 ) ;
if ( V_6 < 0 )
return V_6 ;
F_7 ( V_16 , 0x19 , 0x8100 ) ;
F_7 ( V_16 , 0x1a , ( F_13 ( V_13 ) * 0x1100 ) | 0x00f0 ) ;
if ( V_13 -> V_20 -> V_21 -> V_22 > 1 )
F_7 ( V_16 , 0x1c , 0xf000 | ( V_13 -> V_23 & 0x1f ) ) ;
else
F_7 ( V_16 , 0x1c , 0xe000 | ( V_13 -> V_23 & 0x1f ) ) ;
F_7 ( V_24 , 0x03 , 0xffff ) ;
F_7 ( V_24 , 0x05 , 0x00ff ) ;
for ( V_14 = 0 ; V_14 < 32 ; V_14 ++ ) {
int V_25 ;
V_25 = 0x1f ;
if ( V_14 != V_13 -> V_23 && V_14 < V_13 -> V_20 -> V_21 -> V_22 )
V_25 = V_13 -> V_21 -> V_26 [ V_14 ] & 0x1f ;
F_7 ( V_24 , 0x06 , 0x8000 | ( V_14 << 8 ) | V_25 ) ;
}
for ( V_14 = 0 ; V_14 < 8 ; V_14 ++ )
F_7 ( V_24 , 0x07 , 0x8000 | ( V_14 << 12 ) | 0x7ff ) ;
for ( V_14 = 0 ; V_14 < 16 ; V_14 ++ )
F_7 ( V_24 , 0x08 , 0x8000 | ( V_14 << 11 ) ) ;
F_7 ( V_24 , 0x0f , 0x00ff ) ;
return 0 ;
}
static int F_14 ( struct V_12 * V_13 , int V_27 )
{
struct V_28 * V_29 = F_15 ( V_13 ) ;
int V_30 = F_4 ( V_27 ) ;
T_1 V_31 ;
if ( F_16 ( V_13 , V_27 ) || V_13 -> V_32 & ( 1 << V_27 ) )
if ( V_29 -> V_33 == V_8 )
F_7 ( V_30 , 0x01 , 0x003d ) ;
else
F_7 ( V_30 , 0x01 , 0x003e ) ;
else
F_7 ( V_30 , 0x01 , 0x0003 ) ;
V_31 = 0x0433 ;
if ( V_27 == F_13 ( V_13 ) ) {
V_31 |= 0x0104 ;
if ( V_29 -> V_33 == V_8 )
V_31 |= 0x0008 ;
}
if ( V_13 -> V_32 & ( 1 << V_27 ) )
V_31 |= 0x0100 ;
F_7 ( V_30 , 0x04 , V_31 ) ;
F_7 ( V_30 , 0x05 , F_16 ( V_13 , V_27 ) ? 0x8000 : 0x0000 ) ;
V_31 = ( V_27 & 0xf ) << 12 ;
if ( F_16 ( V_13 , V_27 ) )
V_31 |= V_13 -> V_34 ;
else
V_31 |= 1 << F_13 ( V_13 ) ;
F_7 ( V_30 , 0x06 , V_31 ) ;
F_7 ( V_30 , 0x07 , 0x0000 ) ;
if ( V_29 -> V_33 == V_8 )
F_7 ( V_30 , 0x08 , 0x0080 ) ;
else {
V_31 = 0x0080 | F_13 ( V_13 ) ;
if ( V_27 == F_13 ( V_13 ) )
V_31 |= 0x0040 ;
F_7 ( V_30 , 0x08 , V_31 ) ;
}
F_7 ( V_30 , 0x09 , 0x0000 ) ;
F_7 ( V_30 , 0x0a , 0x0000 ) ;
F_7 ( V_30 , 0x0b , 1 << V_27 ) ;
F_7 ( V_30 , 0x18 , 0x3210 ) ;
F_7 ( V_30 , 0x19 , 0x7654 ) ;
return 0 ;
}
static int F_17 ( struct V_12 * V_13 )
{
struct V_28 * V_29 = F_15 ( V_13 ) ;
int V_14 ;
int V_6 ;
F_18 ( & V_29 -> V_35 ) ;
F_19 ( V_13 ) ;
F_18 ( & V_29 -> V_36 ) ;
V_29 -> V_33 = F_6 ( F_4 ( 0 ) , 0x03 ) & 0xfff0 ;
V_6 = F_5 ( V_13 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_11 ( V_13 ) ;
if ( V_6 < 0 )
return V_6 ;
for ( V_14 = 0 ; V_14 < 11 ; V_14 ++ ) {
V_6 = F_14 ( V_13 , V_14 ) ;
if ( V_6 < 0 )
return V_6 ;
}
return 0 ;
}
static int F_20 ( int V_37 )
{
if ( V_37 >= 0 && V_37 <= 11 )
return V_37 ;
return - 1 ;
}
static int
F_21 ( struct V_12 * V_13 , int V_37 , int V_38 )
{
int V_30 = F_20 ( V_37 ) ;
return F_22 ( V_13 , V_30 , V_38 ) ;
}
static int
F_23 ( struct V_12 * V_13 ,
int V_37 , int V_38 , T_1 V_31 )
{
int V_30 = F_20 ( V_37 ) ;
return F_24 ( V_13 , V_30 , V_38 , V_31 ) ;
}
static void
F_25 ( struct V_12 * V_13 , int V_37 , T_2 * V_39 )
{
F_26 ( V_13 , F_27 ( V_40 ) ,
V_40 , V_37 , V_39 ) ;
}
static void
F_28 ( struct V_12 * V_13 ,
int V_37 , T_3 * V_39 )
{
F_29 ( V_13 , F_27 ( V_40 ) ,
V_40 , V_37 , V_39 ) ;
}
static int F_30 ( struct V_12 * V_13 )
{
return F_27 ( V_40 ) ;
}
