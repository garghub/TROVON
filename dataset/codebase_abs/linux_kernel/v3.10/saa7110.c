static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_2 * F_3 ( struct V_4 * V_5 )
{
return & F_2 ( V_5 -> V_6 , struct V_1 , V_7 ) -> V_3 ;
}
static int F_4 ( struct V_2 * V_3 , T_1 V_8 , T_1 V_9 )
{
struct V_10 * V_11 = F_5 ( V_3 ) ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
V_12 -> V_8 [ V_8 ] = V_9 ;
return F_6 ( V_11 , V_8 , V_9 ) ;
}
static int F_7 ( struct V_2 * V_3 , const T_1 * V_13 , unsigned int V_14 )
{
struct V_10 * V_11 = F_5 ( V_3 ) ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
int V_15 = - 1 ;
T_1 V_8 = * V_13 ;
if ( V_8 + ( V_14 - 1 ) > V_16 )
return V_15 ;
if ( F_8 ( V_11 -> V_17 , V_18 ) ) {
V_15 = F_9 ( V_11 , V_13 , V_14 ) ;
memcpy ( V_12 -> V_8 + V_8 , V_13 + 1 , V_14 - 1 ) ;
} else {
for ( ++ V_13 , -- V_14 ; V_14 ; V_14 -- ) {
V_15 = F_4 ( V_3 , V_8 ++ , * V_13 ++ ) ;
if ( V_15 < 0 )
break;
}
}
return V_15 ;
}
static inline int F_10 ( struct V_2 * V_3 )
{
struct V_10 * V_11 = F_5 ( V_3 ) ;
return F_11 ( V_11 ) ;
}
static int F_12 ( struct V_2 * V_3 , int V_19 )
{
static const unsigned char V_20 [ 9 ] [ 8 ] = {
{ V_21 , 0xD9 , 0x17 , 0x40 , 0x03 ,
0x44 , 0x75 , 0x16 } ,
{ V_21 , 0xD8 , 0x17 , 0x40 , 0x03 ,
0x44 , 0x75 , 0x16 } ,
{ V_21 , 0xBA , 0x07 , 0x91 , 0x03 ,
0x60 , 0xB5 , 0x05 } ,
{ V_21 , 0xB8 , 0x07 , 0x91 , 0x03 ,
0x60 , 0xB5 , 0x05 } ,
{ V_21 , 0x7C , 0x07 , 0xD2 , 0x83 ,
0x60 , 0xB5 , 0x03 } ,
{ V_21 , 0x78 , 0x07 , 0xD2 , 0x83 ,
0x60 , 0xB5 , 0x03 } ,
{ V_22 , 0x59 , 0x17 , 0x42 , 0xA3 ,
0x44 , 0x75 , 0x12 } ,
{ V_22 , 0x9A , 0x17 , 0xB1 , 0x13 ,
0x60 , 0xB5 , 0x14 } ,
{ V_22 , 0x3C , 0x27 , 0xC1 , 0x23 ,
0x44 , 0x75 , 0x21 }
} ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
const unsigned char * V_23 = V_20 [ V_19 ] ;
F_4 ( V_3 , 0x06 , V_23 [ 0 ] ) ;
F_4 ( V_3 , 0x20 , V_23 [ 1 ] ) ;
F_4 ( V_3 , 0x21 , V_23 [ 2 ] ) ;
F_4 ( V_3 , 0x22 , V_23 [ 3 ] ) ;
F_4 ( V_3 , 0x2C , V_23 [ 4 ] ) ;
F_4 ( V_3 , 0x30 , V_23 [ 5 ] ) ;
F_4 ( V_3 , 0x31 , V_23 [ 6 ] ) ;
F_4 ( V_3 , 0x21 , V_23 [ 7 ] ) ;
V_12 -> V_24 = V_19 ;
return 0 ;
}
static T_2 F_13 ( struct V_2 * V_3 )
{
F_14 ( V_25 ) ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
int V_26 ;
F_7 ( V_3 , V_27 , sizeof( V_27 ) ) ;
F_12 ( V_3 , V_12 -> V_24 ) ;
F_15 ( & V_12 -> V_28 , & V_25 , V_29 ) ;
F_16 ( F_17 ( 250 ) ) ;
F_18 ( & V_12 -> V_28 , & V_25 ) ;
V_26 = F_10 ( V_3 ) ;
if ( V_26 & 0x40 ) {
F_19 ( 1 , V_30 , V_3 , L_1 , V_26 ) ;
return V_12 -> V_31 ;
}
if ( ( V_26 & 3 ) == 0 ) {
F_4 ( V_3 , 0x06 , 0x83 ) ;
if ( V_26 & 0x20 ) {
F_19 ( 1 , V_30 , V_3 , L_2 , V_26 ) ;
return V_32 ;
}
F_19 ( 1 , V_30 , V_3 , L_3 , V_26 ) ;
return V_33 ;
}
if ( V_26 & 0x20 ) {
F_19 ( 1 , V_30 , V_3 , L_4 , V_26 ) ;
F_4 ( V_3 , 0x0D , 0x86 ) ;
F_4 ( V_3 , 0x0F , 0x50 ) ;
F_4 ( V_3 , 0x11 , 0x2C ) ;
return V_32 ;
}
F_4 ( V_3 , 0x0D , 0x86 ) ;
F_4 ( V_3 , 0x0F , 0x10 ) ;
F_4 ( V_3 , 0x11 , 0x59 ) ;
F_15 ( & V_12 -> V_28 , & V_25 , V_29 ) ;
F_16 ( F_17 ( 250 ) ) ;
F_18 ( & V_12 -> V_28 , & V_25 ) ;
V_26 = F_10 ( V_3 ) ;
if ( ( V_26 & 0x03 ) == 0x01 ) {
F_19 ( 1 , V_30 , V_3 , L_5 , V_26 ) ;
F_4 ( V_3 , 0x0D , 0x87 ) ;
return V_34 ;
}
F_19 ( 1 , V_30 , V_3 , L_6 , V_26 ) ;
return V_33 ;
}
static int F_20 ( struct V_2 * V_3 , T_3 * V_35 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
int V_36 = V_37 ;
int V_26 = F_10 ( V_3 ) ;
F_19 ( 1 , V_30 , V_3 , L_7 ,
V_26 , ( unsigned long long ) V_12 -> V_31 ) ;
if ( ! ( V_26 & 0x40 ) )
V_36 = 0 ;
if ( ! ( V_26 & 0x03 ) )
V_36 |= V_38 ;
* V_35 = V_36 ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 , T_2 * V_39 )
{
* ( T_2 * ) V_39 = F_13 ( V_3 ) ;
return 0 ;
}
static int F_22 ( struct V_2 * V_3 , T_2 V_39 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
if ( V_12 -> V_31 != V_39 ) {
V_12 -> V_31 = V_39 ;
if ( V_39 & V_32 ) {
F_4 ( V_3 , 0x0D , 0x86 ) ;
F_4 ( V_3 , 0x0F , 0x50 ) ;
F_4 ( V_3 , 0x11 , 0x2C ) ;
F_19 ( 1 , V_30 , V_3 , L_8 ) ;
} else if ( V_39 & V_33 ) {
F_4 ( V_3 , 0x0D , 0x86 ) ;
F_4 ( V_3 , 0x0F , 0x10 ) ;
F_4 ( V_3 , 0x11 , 0x59 ) ;
F_19 ( 1 , V_30 , V_3 , L_9 ) ;
} else if ( V_39 & V_34 ) {
F_4 ( V_3 , 0x0D , 0x87 ) ;
F_4 ( V_3 , 0x0F , 0x10 ) ;
F_4 ( V_3 , 0x11 , 0x59 ) ;
F_19 ( 1 , V_30 , V_3 , L_10 ) ;
} else {
return - V_40 ;
}
}
return 0 ;
}
static int F_23 ( struct V_2 * V_3 ,
T_3 V_24 , T_3 V_41 , T_3 V_42 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
if ( V_24 >= V_43 ) {
F_19 ( 1 , V_30 , V_3 , L_11 , V_24 ) ;
return - V_40 ;
}
if ( V_12 -> V_24 != V_24 ) {
F_12 ( V_3 , V_24 ) ;
F_19 ( 1 , V_30 , V_3 , L_12 , V_24 ) ;
}
return 0 ;
}
static int F_24 ( struct V_2 * V_3 , int V_44 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
if ( V_12 -> V_44 != V_44 ) {
V_12 -> V_44 = V_44 ;
F_4 ( V_3 , 0x0E , V_44 ? 0x18 : 0x80 ) ;
F_19 ( 1 , V_30 , V_3 , L_13 , V_44 ? L_14 : L_15 ) ;
}
return 0 ;
}
static int F_25 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
switch ( V_5 -> V_45 ) {
case V_46 :
F_4 ( V_3 , 0x19 , V_5 -> V_47 ) ;
break;
case V_48 :
F_4 ( V_3 , 0x13 , V_5 -> V_47 ) ;
break;
case V_49 :
F_4 ( V_3 , 0x12 , V_5 -> V_47 ) ;
break;
case V_50 :
F_4 ( V_3 , 0x07 , V_5 -> V_47 ) ;
break;
default:
return - V_40 ;
}
return 0 ;
}
static int F_26 ( struct V_2 * V_3 , struct V_51 * V_52 )
{
struct V_10 * V_11 = F_5 ( V_3 ) ;
return F_27 ( V_11 , V_52 , V_53 , 0 ) ;
}
static int F_28 ( struct V_10 * V_11 ,
const struct V_54 * V_45 )
{
struct V_1 * V_12 ;
struct V_2 * V_3 ;
int V_55 ;
if ( ! F_8 ( V_11 -> V_17 ,
V_56 | V_57 ) )
return - V_58 ;
F_29 ( V_11 , L_16 ,
V_11 -> V_59 << 1 , V_11 -> V_17 -> V_60 ) ;
V_12 = F_30 ( sizeof( struct V_1 ) , V_61 ) ;
if ( ! V_12 )
return - V_62 ;
V_3 = & V_12 -> V_3 ;
F_31 ( V_3 , V_11 , & V_63 ) ;
V_12 -> V_31 = V_33 ;
V_12 -> V_24 = 0 ;
V_12 -> V_44 = 1 ;
F_32 ( & V_12 -> V_7 , 2 ) ;
F_33 ( & V_12 -> V_7 , & V_64 ,
V_46 , 0 , 255 , 1 , 128 ) ;
F_33 ( & V_12 -> V_7 , & V_64 ,
V_48 , 0 , 127 , 1 , 64 ) ;
F_33 ( & V_12 -> V_7 , & V_64 ,
V_49 , 0 , 127 , 1 , 64 ) ;
F_33 ( & V_12 -> V_7 , & V_64 ,
V_50 , - 128 , 127 , 1 , 0 ) ;
V_3 -> V_65 = & V_12 -> V_7 ;
if ( V_12 -> V_7 . error ) {
int V_66 = V_12 -> V_7 . error ;
F_34 ( & V_12 -> V_7 ) ;
F_35 ( V_12 ) ;
return V_66 ;
}
F_36 ( & V_12 -> V_7 ) ;
F_37 ( & V_12 -> V_28 ) ;
V_55 = F_7 ( V_3 , V_27 , sizeof( V_27 ) ) ;
if ( V_55 < 0 ) {
F_19 ( 1 , V_30 , V_3 , L_17 , V_55 ) ;
} else {
int V_67 , V_26 ;
F_4 ( V_3 , 0x21 , 0x10 ) ;
F_4 ( V_3 , 0x0e , 0x18 ) ;
F_4 ( V_3 , 0x0D , 0x04 ) ;
V_67 = F_10 ( V_3 ) ;
F_4 ( V_3 , 0x0D , 0x06 ) ;
V_26 = F_10 ( V_3 ) ;
F_19 ( 1 , V_30 , V_3 , L_18 ,
V_67 , V_26 ) ;
F_4 ( V_3 , 0x0D , 0x86 ) ;
F_4 ( V_3 , 0x0F , 0x10 ) ;
F_4 ( V_3 , 0x11 , 0x59 ) ;
}
return 0 ;
}
static int F_38 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = F_39 ( V_11 ) ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
F_40 ( V_3 ) ;
F_34 ( & V_12 -> V_7 ) ;
F_35 ( V_12 ) ;
return 0 ;
}
