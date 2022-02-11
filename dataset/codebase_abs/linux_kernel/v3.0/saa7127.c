static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_5 * V_6 = F_4 ( V_3 ) ;
return F_5 ( V_6 , V_4 ) ;
}
static int F_6 ( struct V_2 * V_3 , T_1 V_4 , T_1 V_7 )
{
struct V_5 * V_6 = F_4 ( V_3 ) ;
int V_8 ;
for ( V_8 = 0 ; V_8 < 3 ; V_8 ++ ) {
if ( F_7 ( V_6 , V_4 , V_7 ) == 0 )
return 0 ;
}
F_8 ( V_3 , L_1 ) ;
return - 1 ;
}
static int F_9 ( struct V_2 * V_3 ,
const struct V_9 * V_10 )
{
while ( V_10 -> V_4 != 0 ) {
F_6 ( V_3 , V_10 -> V_4 , V_10 -> V_11 ) ;
V_10 ++ ;
}
return 0 ;
}
static int F_10 ( struct V_2 * V_3 , const struct V_12 * V_13 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
int V_15 = ( V_13 -> line != 0 ) ;
if ( V_15 && ( V_13 -> V_16 != 0 || V_13 -> line != 16 ) )
return - V_17 ;
if ( V_14 -> V_18 != V_15 ) {
F_11 ( 1 , V_19 , V_3 , L_2 , V_15 ? L_3 : L_4 ) ;
F_6 ( V_3 , 0x54 , V_15 << 7 ) ;
V_14 -> V_18 = V_15 ;
}
if ( ! V_15 )
return 0 ;
V_14 -> V_20 [ 0 ] = V_13 -> V_13 [ 2 ] ;
V_14 -> V_20 [ 1 ] = V_13 -> V_13 [ 8 ] ;
V_14 -> V_20 [ 2 ] = V_13 -> V_13 [ 9 ] ;
V_14 -> V_20 [ 3 ] = V_13 -> V_13 [ 10 ] ;
V_14 -> V_20 [ 4 ] = V_13 -> V_13 [ 11 ] ;
F_11 ( 1 , V_19 , V_3 , L_5 ,
V_14 -> V_20 [ 0 ] , V_14 -> V_20 [ 1 ] ,
V_14 -> V_20 [ 2 ] , V_14 -> V_20 [ 3 ] ,
V_14 -> V_20 [ 4 ] ) ;
F_6 ( V_3 , 0x55 , V_14 -> V_20 [ 0 ] ) ;
F_6 ( V_3 , 0x56 , V_14 -> V_20 [ 1 ] ) ;
F_6 ( V_3 , 0x57 , V_14 -> V_20 [ 2 ] ) ;
F_6 ( V_3 , 0x58 , V_14 -> V_20 [ 3 ] ) ;
F_6 ( V_3 , 0x59 , V_14 -> V_20 [ 4 ] ) ;
return 0 ;
}
static int F_12 ( struct V_2 * V_3 , const struct V_12 * V_13 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
T_2 V_21 = V_13 -> V_13 [ 1 ] << 8 | V_13 -> V_13 [ 0 ] ;
int V_15 = ( V_13 -> line != 0 ) ;
if ( V_15 && ( V_13 -> V_16 != 0 || V_13 -> line != 21 ) )
return - V_17 ;
if ( V_14 -> V_22 != V_15 ) {
F_11 ( 1 , V_19 , V_3 ,
L_6 , V_15 ? L_3 : L_4 ) ;
F_6 ( V_3 , V_23 ,
( V_14 -> V_24 << 7 ) | ( V_15 << 6 ) | 0x11 ) ;
V_14 -> V_22 = V_15 ;
}
if ( ! V_15 )
return 0 ;
F_11 ( 2 , V_19 , V_3 , L_7 , V_21 ) ;
F_6 ( V_3 , V_25 , V_21 & 0xff ) ;
F_6 ( V_3 , V_26 , V_21 >> 8 ) ;
V_14 -> V_27 = V_21 ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 , const struct V_12 * V_13 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
T_2 V_28 = V_13 -> V_13 [ 1 ] << 8 | V_13 -> V_13 [ 0 ] ;
int V_15 = ( V_13 -> line != 0 ) ;
if ( V_15 && ( V_13 -> V_16 != 1 || V_13 -> line != 21 ) )
return - V_17 ;
if ( V_14 -> V_24 != V_15 ) {
F_11 ( 1 , V_19 , V_3 , L_8 , V_15 ? L_3 : L_4 ) ;
F_6 ( V_3 , V_23 ,
( V_15 << 7 ) | ( V_14 -> V_22 << 6 ) | 0x11 ) ;
V_14 -> V_24 = V_15 ;
}
if ( ! V_15 )
return 0 ;
F_11 ( 2 , V_19 , V_3 , L_9 , V_28 ) ;
F_6 ( V_3 , V_29 , V_28 & 0xff ) ;
F_6 ( V_3 , V_30 , V_28 >> 8 ) ;
V_14 -> V_31 = V_28 ;
return 0 ;
}
static int F_14 ( struct V_2 * V_3 , const struct V_12 * V_13 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
int V_15 = ( V_13 -> line != 0 ) ;
if ( V_15 && ( V_13 -> V_16 != 0 || V_13 -> line != 23 ) )
return - V_17 ;
if ( V_14 -> V_32 != V_15 ) {
F_11 ( 1 , V_19 , V_3 , L_10 , V_15 ? L_3 : L_4 ) ;
F_6 ( V_3 , 0x27 , V_15 << 7 ) ;
V_14 -> V_32 = V_15 ;
}
if ( ! V_15 )
return 0 ;
F_6 ( V_3 , 0x26 , V_13 -> V_13 [ 0 ] ) ;
F_6 ( V_3 , 0x27 , 0x80 | ( V_13 -> V_13 [ 1 ] & 0x3f ) ) ;
F_11 ( 1 , V_19 , V_3 ,
L_11 , V_33 [ V_13 -> V_13 [ 0 ] & 0xf ] ) ;
V_14 -> V_34 = ( V_13 -> V_13 [ 1 ] & 0x3f ) << 8 | V_13 -> V_13 [ 0 ] ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 , int V_15 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
if ( V_15 ) {
F_11 ( 1 , V_19 , V_3 , L_12 ) ;
F_6 ( V_3 , 0x2d , V_14 -> V_35 ) ;
F_6 ( V_3 , 0x61 , V_14 -> V_36 ) ;
} else {
F_11 ( 1 , V_19 , V_3 , L_13 ) ;
F_6 ( V_3 , 0x2d , ( V_14 -> V_35 & 0xf0 ) ) ;
F_6 ( V_3 , 0x61 , ( V_14 -> V_36 | 0xc0 ) ) ;
}
V_14 -> V_37 = V_15 ;
return 0 ;
}
static int F_16 ( struct V_2 * V_3 , T_3 V_38 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
const struct V_9 * V_39 ;
if ( V_38 & V_40 ) {
F_11 ( 1 , V_19 , V_3 , L_14 ) ;
V_39 = V_41 ;
V_14 -> V_36 = V_42 ;
} else if ( V_14 -> V_43 == V_44 &&
( V_38 & V_45 ) &&
! ( V_38 & ( V_46 & ~ V_45 ) ) ) {
F_11 ( 1 , V_19 , V_3 ,
L_15 ) ;
V_39 = V_47 ;
V_14 -> V_36 = V_48 ;
} else {
F_11 ( 1 , V_19 , V_3 , L_16 ) ;
V_39 = V_49 ;
V_14 -> V_36 = V_50 ;
}
F_9 ( V_3 , V_39 ) ;
V_14 -> V_38 = V_38 ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 , int V_51 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
switch ( V_51 ) {
case V_52 :
V_14 -> V_35 = 0x0f ;
V_14 -> V_53 = 0x13 ;
break;
case V_54 :
if ( V_14 -> V_43 == V_44 )
V_14 -> V_35 = 0x20 ;
else
V_14 -> V_35 = 0x08 ;
V_14 -> V_53 = 0x13 ;
break;
case V_55 :
if ( V_14 -> V_43 == V_44 )
V_14 -> V_35 = 0x18 ;
else
V_14 -> V_35 = 0xff ;
V_14 -> V_53 = 0x13 ;
break;
case V_56 :
V_14 -> V_35 = 0x4f ;
V_14 -> V_53 = 0x0b ;
break;
case V_57 :
V_14 -> V_35 = 0x0f ;
V_14 -> V_53 = 0x0b ;
break;
case V_58 :
if ( V_14 -> V_43 == V_44 )
V_14 -> V_35 = 0x38 ;
else
V_14 -> V_35 = 0xbf ;
V_14 -> V_53 = 0x13 ;
break;
default:
return - V_17 ;
}
F_11 ( 1 , V_19 , V_3 ,
L_17 , V_59 [ V_51 ] ) ;
F_6 ( V_3 , 0x2d , V_14 -> V_35 ) ;
F_6 ( V_3 , 0x3a , V_14 -> V_53 | V_14 -> V_60 ) ;
V_14 -> V_61 = V_51 ;
return 0 ;
}
static int F_18 ( struct V_2 * V_3 , int V_62 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
switch ( V_62 ) {
case V_63 :
F_11 ( 1 , V_19 , V_3 , L_18 ) ;
V_14 -> V_60 = 0 ;
break;
case V_64 :
F_11 ( 1 , V_19 , V_3 , L_19 ) ;
V_14 -> V_60 = 0x80 ;
break;
default:
return - V_17 ;
}
F_6 ( V_3 , 0x3a , V_14 -> V_53 | V_14 -> V_60 ) ;
V_14 -> V_65 = V_62 ;
return 0 ;
}
static int F_19 ( struct V_2 * V_3 , T_3 V_38 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
if ( V_14 -> V_38 == V_38 )
return 0 ;
return F_16 ( V_3 , V_38 ) ;
}
static int F_20 ( struct V_2 * V_3 ,
T_4 V_62 , T_4 V_51 , T_4 V_66 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
int V_67 = 0 ;
if ( V_14 -> V_65 != V_62 )
V_67 = F_18 ( V_3 , V_62 ) ;
if ( V_67 == 0 && V_14 -> V_61 != V_51 )
V_67 = F_17 ( V_3 , V_51 ) ;
return V_67 ;
}
static int F_21 ( struct V_2 * V_3 , int V_15 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
if ( V_14 -> V_37 == V_15 )
return 0 ;
return F_15 ( V_3 , V_15 ) ;
}
static int F_22 ( struct V_2 * V_3 , struct V_68 * V_69 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
memset ( V_69 , 0 , sizeof( * V_69 ) ) ;
if ( V_14 -> V_18 )
V_69 -> V_70 [ 0 ] [ 16 ] = V_71 ;
if ( V_14 -> V_32 )
V_69 -> V_70 [ 0 ] [ 23 ] = V_72 ;
if ( V_14 -> V_22 ) {
V_69 -> V_70 [ 0 ] [ 21 ] = V_73 ;
V_69 -> V_70 [ 1 ] [ 21 ] = V_73 ;
}
V_69 -> V_74 =
( V_14 -> V_18 ? V_71 : 0 ) |
( V_14 -> V_32 ? V_72 : 0 ) |
( V_14 -> V_22 ? V_73 : 0 ) ;
return 0 ;
}
static int F_23 ( struct V_2 * V_3 , const struct V_12 * V_13 )
{
switch ( V_13 -> V_75 ) {
case V_72 :
return F_14 ( V_3 , V_13 ) ;
case V_71 :
return F_10 ( V_3 , V_13 ) ;
case V_73 :
if ( V_13 -> V_16 == 0 )
return F_12 ( V_3 , V_13 ) ;
return F_13 ( V_3 , V_13 ) ;
default:
return - V_17 ;
}
return 0 ;
}
static int F_24 ( struct V_2 * V_3 , struct V_76 * V_4 )
{
struct V_5 * V_6 = F_4 ( V_3 ) ;
if ( ! F_25 ( V_6 , & V_4 -> V_77 ) )
return - V_17 ;
if ( ! F_26 ( V_78 ) )
return - V_79 ;
V_4 -> V_7 = F_3 ( V_3 , V_4 -> V_4 & 0xff ) ;
V_4 -> V_80 = 1 ;
return 0 ;
}
static int F_27 ( struct V_2 * V_3 , struct V_76 * V_4 )
{
struct V_5 * V_6 = F_4 ( V_3 ) ;
if ( ! F_25 ( V_6 , & V_4 -> V_77 ) )
return - V_17 ;
if ( ! F_26 ( V_78 ) )
return - V_79 ;
F_6 ( V_3 , V_4 -> V_4 & 0xff , V_4 -> V_7 & 0xff ) ;
return 0 ;
}
static int F_28 ( struct V_2 * V_3 , struct V_81 * V_82 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
struct V_5 * V_6 = F_4 ( V_3 ) ;
return F_29 ( V_6 , V_82 , V_14 -> V_43 , 0 ) ;
}
static int F_30 ( struct V_2 * V_3 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
F_31 ( V_3 , L_20 , ( V_14 -> V_38 & V_40 ) ? L_21 : L_22 ) ;
F_31 ( V_3 , L_23 , V_14 -> V_65 ? L_24 : L_25 ) ;
F_31 ( V_3 , L_26 , V_14 -> V_37 ?
V_59 [ V_14 -> V_61 ] : L_27 ) ;
F_31 ( V_3 , L_28 , V_14 -> V_32 ?
V_33 [ V_14 -> V_34 ] : L_27 ) ;
F_31 ( V_3 , L_29 , V_14 -> V_18 ? L_30 : L_27 ) ;
F_31 ( V_3 , L_31 , V_14 -> V_22 ? L_30 : L_27 ) ;
return 0 ;
}
static int F_32 ( struct V_5 * V_6 ,
const struct V_83 * V_75 )
{
struct V_1 * V_14 ;
struct V_2 * V_3 ;
struct V_12 V_84 = { 0 , 0 , 0 , 0 } ;
if ( ! F_33 ( V_6 -> V_85 , V_86 ) )
return - V_87 ;
F_34 ( 1 , V_19 , V_6 , L_32 ,
V_6 -> V_88 << 1 ) ;
V_14 = F_35 ( sizeof( struct V_1 ) , V_89 ) ;
if ( V_14 == NULL )
return - V_90 ;
V_3 = & V_14 -> V_3 ;
F_36 ( V_3 , V_6 , & V_91 ) ;
if ( ( F_3 ( V_3 , 0 ) & 0xe4 ) != 0 ||
( F_3 ( V_3 , 0x29 ) & 0x3f ) != 0x1d ) {
F_11 ( 1 , V_19 , V_3 , L_33 ) ;
F_37 ( V_14 ) ;
return - V_92 ;
}
if ( V_75 -> V_93 ) {
V_14 -> V_43 = V_75 -> V_93 ;
} else {
int V_94 ;
V_94 = F_3 ( V_3 , V_95 ) ;
F_6 ( V_3 , V_95 , 0xaa ) ;
if ( F_3 ( V_3 , V_95 ) == 0xaa ) {
F_6 ( V_3 , V_95 ,
V_94 ) ;
V_14 -> V_43 = V_44 ;
F_38 ( V_6 -> V_96 , L_34 , V_97 ) ;
} else {
V_14 -> V_43 = V_98 ;
F_38 ( V_6 -> V_96 , L_35 , V_97 ) ;
}
}
F_31 ( V_3 , L_36 , V_6 -> V_96 ,
V_6 -> V_88 << 1 , V_6 -> V_85 -> V_96 ) ;
F_11 ( 1 , V_19 , V_3 , L_37 ) ;
F_9 ( V_3 , V_99 ) ;
F_16 ( V_3 , V_100 ) ;
F_17 ( V_3 , V_58 ) ;
F_10 ( V_3 , & V_84 ) ;
F_14 ( V_3 , & V_84 ) ;
F_12 ( V_3 , & V_84 ) ;
F_13 ( V_3 , & V_84 ) ;
if ( V_101 == 1 )
F_18 ( V_3 , V_64 ) ;
else
F_18 ( V_3 , V_63 ) ;
F_15 ( V_3 , 1 ) ;
if ( V_14 -> V_43 == V_44 )
F_9 ( V_3 , V_102 ) ;
return 0 ;
}
static int F_39 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = F_40 ( V_6 ) ;
F_41 ( V_3 ) ;
F_15 ( V_3 , 0 ) ;
F_37 ( F_1 ( V_3 ) ) ;
return 0 ;
}
static T_5 int F_42 ( void )
{
return F_43 ( & V_103 ) ;
}
static T_6 void F_44 ( void )
{
F_45 ( & V_103 ) ;
}
