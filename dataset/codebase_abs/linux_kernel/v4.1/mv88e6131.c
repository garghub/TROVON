static char * F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 ;
if ( V_5 == NULL )
return NULL ;
V_6 = F_3 ( V_5 , V_3 , F_4 ( 0 ) , V_7 ) ;
if ( V_6 >= 0 ) {
int V_8 = V_6 & 0xfff0 ;
if ( V_8 == V_9 )
return L_1 ;
if ( V_8 == V_10 )
return L_2 ;
if ( V_6 == V_11 )
return L_3 ;
if ( V_8 == V_12 )
return L_4 ;
}
return NULL ;
}
static int F_5 ( struct V_13 * V_14 )
{
int V_6 ;
int V_15 ;
F_6 ( V_16 , 0x04 , 0x4400 ) ;
F_6 ( V_16 , 0x0a , 0x0148 ) ;
V_6 = F_7 ( V_14 ) ;
if ( V_6 < 0 )
return V_6 ;
F_6 ( V_16 , 0x19 , 0x8100 ) ;
F_6 ( V_16 , 0x1a , ( F_8 ( V_14 ) * 0x1100 ) | 0x00f0 ) ;
if ( V_14 -> V_17 -> V_18 -> V_19 > 1 )
F_6 ( V_16 , 0x1c , 0xf000 | ( V_14 -> V_20 & 0x1f ) ) ;
else
F_6 ( V_16 , 0x1c , 0xe000 | ( V_14 -> V_20 & 0x1f ) ) ;
F_6 ( V_21 , 0x03 , 0xffff ) ;
F_6 ( V_21 , 0x05 , 0x00ff ) ;
for ( V_15 = 0 ; V_15 < 32 ; V_15 ++ ) {
int V_22 ;
V_22 = 0x1f ;
if ( V_14 -> V_18 -> V_23 &&
V_15 != V_14 -> V_20 && V_15 < V_14 -> V_17 -> V_18 -> V_19 )
V_22 = V_14 -> V_18 -> V_23 [ V_15 ] & 0x1f ;
F_6 ( V_21 , 0x06 , 0x8000 | ( V_15 << 8 ) | V_22 ) ;
}
for ( V_15 = 0 ; V_15 < 8 ; V_15 ++ )
F_6 ( V_21 , 0x07 , 0x8000 | ( V_15 << 12 ) | 0x7ff ) ;
for ( V_15 = 0 ; V_15 < 16 ; V_15 ++ )
F_6 ( V_21 , 0x08 , 0x8000 | ( V_15 << 11 ) ) ;
F_6 ( V_21 , 0x0f , 0x00ff ) ;
return 0 ;
}
static int F_9 ( struct V_13 * V_14 , int V_24 )
{
struct V_25 * V_26 = F_10 ( V_14 ) ;
int V_27 = F_4 ( V_24 ) ;
T_1 V_28 ;
if ( F_11 ( V_14 , V_24 ) || V_14 -> V_29 & ( 1 << V_24 ) )
if ( V_26 -> V_30 == V_9 )
F_6 ( V_27 , 0x01 , 0x003d ) ;
else
F_6 ( V_27 , 0x01 , 0x003e ) ;
else
F_6 ( V_27 , 0x01 , 0x0003 ) ;
V_28 = 0x0433 ;
if ( V_24 == F_8 ( V_14 ) ) {
V_28 |= 0x0104 ;
if ( V_26 -> V_30 == V_9 )
V_28 |= 0x0008 ;
}
if ( V_14 -> V_29 & ( 1 << V_24 ) )
V_28 |= 0x0100 ;
F_6 ( V_27 , 0x04 , V_28 ) ;
if ( V_26 -> V_30 == V_9 )
F_6 ( V_27 , 0x08 , 0x0080 ) ;
else {
V_28 = 0x0080 | F_8 ( V_14 ) ;
if ( V_24 == F_8 ( V_14 ) )
V_28 |= 0x0040 ;
F_6 ( V_27 , 0x08 , V_28 ) ;
}
F_6 ( V_27 , 0x09 , 0x0000 ) ;
F_6 ( V_27 , 0x0a , 0x0000 ) ;
F_6 ( V_27 , 0x0b , 1 << V_24 ) ;
F_6 ( V_27 , 0x18 , 0x3210 ) ;
F_6 ( V_27 , 0x19 , 0x7654 ) ;
return F_12 ( V_14 , V_24 ) ;
}
static int F_13 ( struct V_13 * V_14 )
{
struct V_25 * V_26 = F_10 ( V_14 ) ;
int V_15 ;
int V_6 ;
V_6 = F_14 ( V_14 ) ;
if ( V_6 < 0 )
return V_6 ;
F_15 ( V_14 ) ;
switch ( V_26 -> V_30 ) {
case V_9 :
V_26 -> V_31 = 10 ;
break;
case V_10 :
V_26 -> V_31 = 11 ;
break;
case V_12 :
case V_11 :
V_26 -> V_31 = 8 ;
break;
default:
return - V_32 ;
}
V_6 = F_16 ( V_14 , false ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_5 ( V_14 ) ;
if ( V_6 < 0 )
return V_6 ;
for ( V_15 = 0 ; V_15 < V_26 -> V_31 ; V_15 ++ ) {
V_6 = F_9 ( V_14 , V_15 ) ;
if ( V_6 < 0 )
return V_6 ;
}
return 0 ;
}
static int F_17 ( struct V_13 * V_14 , int V_33 )
{
struct V_25 * V_26 = F_10 ( V_14 ) ;
if ( V_33 >= 0 && V_33 < V_26 -> V_31 )
return V_33 ;
return - V_34 ;
}
static int
F_18 ( struct V_13 * V_14 , int V_33 , int V_35 )
{
int V_27 = F_17 ( V_14 , V_33 ) ;
if ( V_27 < 0 )
return V_27 ;
return F_19 ( V_14 , V_27 , V_35 ) ;
}
static int
F_20 ( struct V_13 * V_14 ,
int V_33 , int V_35 , T_1 V_28 )
{
int V_27 = F_17 ( V_14 , V_33 ) ;
if ( V_27 < 0 )
return V_27 ;
return F_21 ( V_14 , V_27 , V_35 , V_28 ) ;
}
