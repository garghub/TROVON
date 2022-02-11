static char * F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 ;
if ( V_5 == NULL )
return NULL ;
V_6 = F_3 ( V_5 , V_3 , F_4 ( 0 ) , V_7 ) ;
if ( V_6 >= 0 ) {
if ( V_6 == V_8 )
return L_1 ;
if ( V_6 == V_9 )
return L_2 ;
if ( ( V_6 & 0xfff0 ) == V_10 )
return L_3 ;
if ( V_6 == V_11 )
return L_4 ;
if ( V_6 == V_12 )
return L_5 ;
if ( ( V_6 & 0xfff0 ) == V_13 )
return L_6 ;
if ( V_6 == V_14 )
return L_7 ;
if ( V_6 == V_15 )
return L_8 ;
if ( ( V_6 & 0xfff0 ) == V_16 )
return L_9 ;
}
return NULL ;
}
static int F_5 ( struct V_17 * V_18 )
{
int V_6 ;
int V_19 ;
F_6 ( V_20 , 0x04 , 0x0000 ) ;
F_6 ( V_20 , 0x0a , 0x0148 ) ;
V_6 = F_7 ( V_18 ) ;
if ( V_6 < 0 )
return V_6 ;
F_6 ( V_20 , 0x1a , ( F_8 ( V_18 ) * 0x1110 ) ) ;
F_6 ( V_20 , 0x1c , V_18 -> V_21 & 0x1f ) ;
F_6 ( V_22 , 0x02 , 0xffff ) ;
F_6 ( V_22 , 0x03 , 0xffff ) ;
F_6 ( V_22 , 0x05 , 0x00ff ) ;
for ( V_19 = 0 ; V_19 < 32 ; V_19 ++ ) {
int V_23 ;
V_23 = 0x1f ;
if ( V_19 != V_18 -> V_21 && V_19 < V_18 -> V_24 -> V_25 -> V_26 )
V_23 = V_18 -> V_25 -> V_27 [ V_19 ] & 0x1f ;
F_6 ( V_22 , 0x06 , 0x8000 | ( V_19 << 8 ) | V_23 ) ;
}
for ( V_19 = 0 ; V_19 < 8 ; V_19 ++ )
F_6 ( V_22 , 0x07 , 0x8000 | ( V_19 << 12 ) | 0xff ) ;
for ( V_19 = 0 ; V_19 < 16 ; V_19 ++ )
F_6 ( V_22 , 0x08 , 0x8000 | ( V_19 << 11 ) ) ;
for ( V_19 = 0 ; V_19 < 6 ; V_19 ++ )
F_6 ( V_22 , 0x09 , 0x9000 | ( V_19 << 8 ) ) ;
F_6 ( V_22 , 0x0b , 0x9000 ) ;
for ( V_19 = 0 ; V_19 < 16 ; V_19 ++ )
F_6 ( V_22 , 0x0f , 0x8000 | ( V_19 << 8 ) ) ;
return 0 ;
}
static int F_9 ( struct V_17 * V_18 , int V_28 )
{
int V_29 = F_4 ( V_28 ) ;
T_1 V_30 ;
if ( F_10 ( V_18 , V_28 ) || V_18 -> V_31 & ( 1 << V_28 ) )
F_6 ( V_29 , 0x01 , 0x003e ) ;
else
F_6 ( V_29 , 0x01 , 0x0003 ) ;
F_6 ( V_29 , 0x02 , 0x0000 ) ;
V_30 = 0x0433 ;
if ( F_10 ( V_18 , V_28 ) ) {
if ( V_18 -> V_24 -> V_32 == V_33 )
V_30 |= 0x3300 ;
else
V_30 |= 0x0100 ;
}
if ( V_18 -> V_31 & ( 1 << V_28 ) )
V_30 |= 0x0100 ;
if ( V_28 == F_8 ( V_18 ) )
V_30 |= 0x000c ;
F_6 ( V_29 , 0x04 , V_30 ) ;
F_6 ( V_29 , 0x08 , 0x2080 ) ;
F_6 ( V_29 , 0x09 , 0x0001 ) ;
F_6 ( V_29 , 0x0a , 0x0000 ) ;
F_6 ( V_29 , 0x0b , 1 << V_28 ) ;
F_6 ( V_29 , 0x0c , 0x0000 ) ;
F_6 ( V_29 , 0x0d , 0x0000 ) ;
F_6 ( V_29 , 0x0f , V_34 ) ;
F_6 ( V_29 , 0x18 , 0x3210 ) ;
F_6 ( V_29 , 0x19 , 0x7654 ) ;
return F_11 ( V_18 , V_28 ) ;
}
static int F_12 ( struct V_17 * V_18 )
{
struct V_35 * V_36 = F_13 ( V_18 ) ;
int V_19 ;
int V_6 ;
V_6 = F_14 ( V_18 ) ;
if ( V_6 < 0 )
return V_6 ;
switch ( V_36 -> V_37 ) {
case V_10 :
V_36 -> V_38 = 3 ;
break;
case V_13 :
case V_16 :
V_36 -> V_38 = 6 ;
break;
default:
return - V_39 ;
}
V_6 = F_15 ( V_18 , false ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_5 ( V_18 ) ;
if ( V_6 < 0 )
return V_6 ;
for ( V_19 = 0 ; V_19 < V_36 -> V_38 ; V_19 ++ ) {
V_6 = F_9 ( V_18 , V_19 ) ;
if ( V_6 < 0 )
return V_6 ;
}
return 0 ;
}
