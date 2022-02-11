static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_4 * V_5 , T_1 V_6 ,
T_1 V_7 , T_1 V_8 , void * V_9 , int V_10 , int V_11 )
{
struct V_12 * V_13 = V_5 -> V_14 ;
int V_15 = 5000 ;
if ( V_11 ) {
return F_4 ( V_13 -> V_16 ,
F_5 ( V_13 -> V_16 , 0 ) , V_6 ,
V_17 | V_18 | V_19 ,
V_7 , V_8 , V_9 , V_10 , V_15 ) ;
} else {
return F_4 ( V_13 -> V_16 ,
F_6 ( V_13 -> V_16 , 0 ) , V_6 ,
V_17 | V_18 ,
V_7 , V_8 , V_9 , V_10 , V_15 ) ;
}
}
static int F_7 ( struct V_20 * V_21 , T_2 V_22 , T_2 V_7 )
{
struct V_4 * V_5 = F_8 ( V_21 -> V_23 ) ;
struct V_12 * V_13 ;
int V_24 ;
int V_25 = V_21 -> V_26 << 1 ;
T_2 * V_27 ;
if ( V_5 == NULL )
return - V_28 ;
if ( V_5 -> V_29 == V_30 )
return - V_31 ;
V_27 = F_9 ( 16 , V_32 ) ;
if ( V_27 == NULL )
return - V_33 ;
V_13 = V_5 -> V_14 ;
if ( F_10 ( & V_13 -> V_34 ) != 0 ) {
F_11 ( V_35 L_1 ) ;
F_12 ( V_27 ) ;
return - V_36 ;
}
V_24 = F_3 ( V_5 , 0x55 , V_25 ,
( V_22 << 8 | V_7 ) ,
V_27 ,
16 , 1 ) ;
F_13 ( & V_13 -> V_34 ) ;
F_12 ( V_27 ) ;
return V_24 ;
}
static int F_14 ( struct V_20 * V_21 , T_1 V_26 , T_1 V_37 )
{
struct V_4 * V_5 = F_8 ( V_21 -> V_23 ) ;
struct V_12 * V_13 ;
int V_24 ;
T_2 * V_27 ;
struct V_1 * V_38 = F_15 ( V_21 ) ;
if ( V_5 == NULL )
return - V_28 ;
if ( V_5 -> V_29 == V_30 )
return - V_31 ;
V_27 = F_9 ( 16 , V_32 ) ;
if ( V_27 == NULL )
return - V_33 ;
memset ( V_27 , 0xcd , 6 ) ;
V_13 = V_5 -> V_14 ;
if ( F_10 ( & V_13 -> V_34 ) != 0 ) {
F_11 ( V_35 L_1 ) ;
F_12 ( V_27 ) ;
return - V_36 ;
}
V_24 = F_3 ( V_5 , 0x57 , V_26 , V_37 , V_27 , 16 , 1 ) ;
F_13 ( & V_13 -> V_34 ) ;
if ( V_24 < 0 ) {
F_12 ( V_27 ) ;
return V_24 ;
}
if ( V_27 [ 0 ] == 0 ) {
unsigned int V_39 , V_40 ;
V_39 = ( V_27 [ 4 ] << 8 ) + V_27 [ 5 ] ;
V_40 = ( V_27 [ 2 ] << 8 ) + V_27 [ 3 ] ;
F_12 ( V_27 ) ;
if ( V_40 != V_37 ) {
F_11 ( V_35 L_2 ,
V_40 , V_37 ) ;
return - V_41 ;
}
if ( V_39 != V_26 ) {
F_11 ( V_35 L_3 ,
V_39 , V_26 ) ;
return - V_41 ;
}
} else {
F_12 ( V_27 ) ;
return - V_41 ;
}
if ( V_26 == 0x12b )
V_38 -> V_42 = V_37 ;
return 0 ;
}
static int F_16 ( struct V_20 * V_21 , T_1 V_26 , T_1 * V_37 )
{
struct V_4 * V_5 = F_8 ( V_21 -> V_23 ) ;
struct V_12 * V_13 ;
int V_24 ;
T_2 * V_27 ;
if ( V_5 == NULL )
return - V_28 ;
if ( V_5 -> V_29 == V_30 )
return - V_31 ;
V_27 = F_9 ( 16 , V_32 ) ;
if ( V_27 == NULL )
return - V_33 ;
memset ( V_27 , 0xcd , 6 ) ;
V_13 = V_5 -> V_14 ;
if ( F_10 ( & V_13 -> V_34 ) != 0 ) {
F_11 ( V_35 L_1 ) ;
F_12 ( V_27 ) ;
return - V_36 ;
}
V_24 = F_3 ( V_5 , 0x58 , V_26 , 0 , V_27 , 16 , 1 ) ;
F_13 ( & V_13 -> V_34 ) ;
if ( V_24 < 0 ) {
F_12 ( V_27 ) ;
return V_24 ;
}
* V_37 = ( V_27 [ 0 ] << 8 ) | V_27 [ 1 ] ;
F_12 ( V_27 ) ;
return 0 ;
}
static int F_17 ( struct V_20 * V_21 , T_2 * V_43 )
{
int V_44 ;
for ( V_44 = 0 ; ! ( ( V_43 [ V_44 ] == 0x00 ) && ( V_43 [ V_44 + 1 ] == 0x00 ) ) ; V_44 += 2 ) {
if ( F_7 ( V_21 , V_43 [ V_44 ] , V_43 [ V_44 + 1 ] ) < 0 ) {
F_11 ( V_35 L_4 ) ;
return - 1 ;
}
}
return 0 ;
}
static int F_18 ( struct V_20 * V_21 , T_1 * V_43 )
{
int V_44 ;
for ( V_44 = 0 ; ! ( ( V_43 [ V_44 ] == 0x00 ) && ( V_43 [ V_44 + 1 ] == 0x00 ) ) ; V_44 += 2 ) {
if ( F_14 ( V_21 , V_43 [ V_44 ] , V_43 [ V_44 + 1 ] ) < 0 ) {
F_11 ( V_35 L_5 ) ;
return - 1 ;
}
}
return 0 ;
}
static int F_19 ( struct V_2 * V_3 , T_3 V_45 , T_3 V_46 ,
T_3 V_47 )
{
struct V_1 * V_48 = F_1 ( V_3 ) ;
struct V_20 * V_21 = F_20 ( V_3 ) ;
int V_49 ;
V_49 = ( V_48 -> V_50 == V_51 ) ? 0x01 : 0x00 ;
if ( V_45 == 0 ) {
F_14 ( V_21 , 0x20 , 0x020 | V_49 ) ;
F_14 ( V_21 , 0x21 , 0x662 ) ;
F_14 ( V_21 , 0x140 , 0x060 ) ;
} else if ( V_45 == 1 ) {
F_14 ( V_21 , 0x20 , 0x040 | V_49 ) ;
F_14 ( V_21 , 0x21 , 0x666 ) ;
F_14 ( V_21 , 0x140 , 0x060 ) ;
} else {
return - V_52 ;
}
V_48 -> V_45 = V_45 ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 , T_4 V_53 )
{
struct V_1 * V_48 = F_1 ( V_3 ) ;
struct V_20 * V_21 = F_20 ( V_3 ) ;
T_1 V_54 ;
V_54 = ( V_48 -> V_45 == 1 ) ? 0x040 : 0x020 ;
switch ( V_53 ) {
case V_51 :
F_18 ( V_21 , V_55 ) ;
F_14 ( V_21 , 0x20 , V_54 | 1 ) ;
break;
case V_56 :
F_18 ( V_21 , V_55 ) ;
F_18 ( V_21 , V_57 ) ;
F_14 ( V_21 , 0x20 , V_54 ) ;
break;
default:
return - V_52 ;
}
V_48 -> V_50 = V_53 ;
return 0 ;
}
static int F_22 ( struct V_2 * V_3 , struct V_58 * V_59 )
{
switch ( V_59 -> V_60 ) {
case V_61 :
return F_23 ( V_59 , 0 , 100 , 1 , 50 ) ;
case V_62 :
return F_23 ( V_59 , 0 , 100 , 1 , 50 ) ;
case V_63 :
return F_23 ( V_59 , 0 , 100 , 1 , 50 ) ;
case V_64 :
return F_23 ( V_59 , - 50 , 50 , 1 , 0 ) ;
default:
return - V_52 ;
}
return 0 ;
}
static int F_24 ( struct V_2 * V_3 , struct V_65 * V_66 )
{
struct V_1 * V_48 = F_1 ( V_3 ) ;
struct V_20 * V_21 = F_20 ( V_3 ) ;
int V_67 ;
T_1 V_68 ;
switch ( V_66 -> V_60 ) {
case V_61 :
if ( V_66 -> V_7 > 100 )
V_48 -> V_69 = 100 ;
else if ( V_66 -> V_7 < 0 )
V_48 -> V_69 = 0 ;
else
V_48 -> V_69 = V_66 -> V_7 ;
V_67 = ( V_48 -> V_69 - 50 ) * 255 / 100 ;
F_16 ( V_21 , V_70 , & V_68 ) ;
F_14 ( V_21 , V_70 ,
V_67 | ( V_68 & ~ 0xff ) ) ;
F_16 ( V_21 , V_71 , & V_68 ) ;
F_14 ( V_21 , V_71 ,
V_67 | ( V_68 & ~ 0xff ) ) ;
F_14 ( V_21 , 0x140 , 0x60 ) ;
break;
case V_62 :
if ( V_66 -> V_7 > 100 )
V_48 -> V_72 = 100 ;
else if ( V_66 -> V_7 < 0 )
V_48 -> V_72 = 0 ;
else
V_48 -> V_72 = V_66 -> V_7 ;
V_67 = V_48 -> V_72 * 0x40 / 100 ;
if ( V_67 > 0x3f )
V_67 = 0x3f ;
F_16 ( V_21 , V_73 , & V_68 ) ;
F_14 ( V_21 , V_73 ,
V_67 | ( V_68 & ~ 0x3f ) ) ;
F_16 ( V_21 , V_74 , & V_68 ) ;
F_14 ( V_21 , V_74 ,
V_67 | ( V_68 & ~ 0x3f ) ) ;
F_14 ( V_21 , 0x140 , 0x60 ) ;
break;
case V_63 :
if ( V_66 -> V_7 > 100 )
V_48 -> V_75 = 100 ;
else if ( V_66 -> V_7 < 0 )
V_48 -> V_75 = 0 ;
else
V_48 -> V_75 = V_66 -> V_7 ;
V_67 = V_48 -> V_75 * 4140 / 100 ;
if ( V_67 > 4094 )
V_67 = 4094 ;
F_14 ( V_21 , V_76 , V_67 ) ;
break;
case V_64 :
if ( V_66 -> V_7 > 50 )
V_48 -> V_77 = 50 ;
else if ( V_66 -> V_7 < - 50 )
V_48 -> V_77 = - 50 ;
else
V_48 -> V_77 = V_66 -> V_7 ;
V_67 = V_48 -> V_77 * 280 / 50 ;
F_14 ( V_21 , V_78 , V_67 ) ;
break;
default:
return - V_52 ;
}
return 0 ;
}
static int F_25 ( struct V_2 * V_3 , struct V_65 * V_66 )
{
struct V_1 * V_48 = F_1 ( V_3 ) ;
switch ( V_66 -> V_60 ) {
case V_61 :
V_66 -> V_7 = V_48 -> V_69 ;
break;
case V_62 :
V_66 -> V_7 = V_48 -> V_72 ;
break;
case V_63 :
V_66 -> V_7 = V_48 -> V_75 ;
break;
case V_64 :
V_66 -> V_7 = V_48 -> V_77 ;
break;
default:
return - V_52 ;
}
return 0 ;
}
static int F_26 ( struct V_2 * V_3 ,
struct V_79 * V_80 )
{
struct V_1 * V_48 = F_1 ( V_3 ) ;
struct V_20 * V_21 = F_20 ( V_3 ) ;
if ( V_80 -> V_81 < 640 ) {
F_14 ( V_21 , 0x12b , V_48 -> V_42 | 0x400 ) ;
F_14 ( V_21 , 0x140 , 0x060 ) ;
} else {
F_14 ( V_21 , 0x12b , V_48 -> V_42 & ~ 0x400 ) ;
F_14 ( V_21 , 0x140 , 0x060 ) ;
}
return 0 ;
}
static int F_27 ( struct V_2 * V_3 , T_3 V_45 , T_3 V_46 ,
T_3 V_47 )
{
struct V_1 * V_48 = F_1 ( V_3 ) ;
switch ( V_45 ) {
case 0 :
F_7 ( V_48 -> V_82 , 0x08 , 0x02 ) ;
break;
case 1 :
F_7 ( V_48 -> V_82 , 0x08 , 0x04 ) ;
break;
case 2 :
F_7 ( V_48 -> V_82 , 0x08 , 0x05 ) ;
break;
default:
return - V_52 ;
}
V_48 -> V_83 = V_45 ;
return 0 ;
}
static int F_28 ( struct V_2 * V_3 )
{
struct V_1 * V_48 = F_1 ( V_3 ) ;
F_29 ( V_3 , L_6 , V_48 -> V_50 == V_51 ? L_7 :
V_48 -> V_50 == V_56 ? L_8 :
V_48 -> V_50 == V_84 ? L_9 :
L_10 ) ;
F_29 ( V_3 , L_11 , V_48 -> V_45 == 0 ? L_12 :
V_48 -> V_45 == 1 ? L_13 :
L_14 ) ;
F_29 ( V_3 , L_15 , V_48 -> V_69 ) ;
F_29 ( V_3 , L_16 , V_48 -> V_72 ) ;
F_29 ( V_3 , L_17 , V_48 -> V_75 ) ;
F_29 ( V_3 , L_18 , V_48 -> V_77 ) ; return 0 ;
F_29 ( V_3 , L_19 , V_48 -> V_83 == 0 ? L_20 :
V_48 -> V_83 == 1 ? L_21 :
V_48 -> V_83 == 2 ? L_22 :
L_14 ) ;
return 0 ;
}
static int F_30 ( struct V_20 * V_21 ,
const struct V_85 * V_60 )
{
struct V_20 * V_82 ;
struct V_86 * V_23 = V_21 -> V_23 ;
struct V_1 * V_48 ;
struct V_2 * V_3 ;
T_2 * V_87 ;
struct V_4 * V_5 = F_8 ( V_23 ) ;
struct V_12 * V_13 = V_5 -> V_14 ;
V_82 = F_31 ( V_23 , V_88 >> 1 ) ;
if ( V_82 == NULL )
return - V_33 ;
V_48 = F_32 ( sizeof( struct V_1 ) , V_32 ) ;
if ( V_48 == NULL ) {
F_33 ( V_82 ) ;
return - V_33 ;
}
V_3 = & V_48 -> V_3 ;
F_34 ( V_3 , V_21 , & V_89 ) ;
F_29 ( V_3 , L_23 ,
L_24 , V_21 -> V_26 , V_21 -> V_23 -> V_90 ) ;
V_48 -> V_50 = V_51 ;
V_48 -> V_69 = 50 ;
V_48 -> V_72 = 50 ;
V_48 -> V_75 = 50 ;
V_48 -> V_77 = 0 ;
V_48 -> V_82 = V_82 ;
if ( F_17 ( V_82 , V_91 ) < 0 ) {
F_11 ( V_92
L_25 ) ;
F_33 ( V_82 ) ;
F_12 ( V_48 ) ;
return 0 ;
}
if ( F_17 ( V_21 , V_93 ) < 0 ) {
F_11 ( V_92
L_26 ) ;
F_33 ( V_82 ) ;
F_12 ( V_48 ) ;
return 0 ;
}
if ( F_18 ( V_21 , V_55 ) < 0 ) {
F_11 ( V_92
L_26 ) ;
F_33 ( V_82 ) ;
F_12 ( V_48 ) ;
return 0 ;
}
F_14 ( V_21 , 0x20 , 0x020 | 1 ) ;
F_14 ( V_21 , 0x21 , 0x662 ) ;
F_14 ( V_21 , 0x140 , 0x060 ) ;
V_48 -> V_83 = 0 ;
F_7 ( V_21 , 0x08 , 0x02 ) ;
if ( F_10 ( & V_13 -> V_34 ) == 0 ) {
V_87 = F_9 ( 16 , V_32 ) ;
if ( V_87 != NULL ) {
int V_24 ;
V_24 = F_3 ( V_5 , 0x41 , 0 , 0 ,
V_87 , 16 , 1 ) ;
if ( V_24 > 0 ) {
T_2 V_94 ;
V_87 [ 0 ] = 0 ;
V_94 = 1 << 5 ;
V_87 [ 0 ] &= ~ V_94 ;
V_87 [ 1 ] |= V_94 ;
F_3 ( V_5 , 0x40 , 0 ,
( V_87 [ 1 ] << 8 )
+ V_87 [ 1 ] ,
V_87 , 16 , 0 ) ;
}
F_12 ( V_87 ) ;
}
F_13 ( & V_13 -> V_34 ) ;
}
F_29 ( V_3 , L_27 ) ;
return 0 ;
}
static int F_35 ( struct V_20 * V_21 )
{
struct V_2 * V_3 = F_15 ( V_21 ) ;
F_36 ( V_3 ) ;
F_12 ( F_1 ( V_3 ) ) ;
return 0 ;
}
static T_5 int F_37 ( void )
{
return F_38 ( & V_95 ) ;
}
static T_6 void F_39 ( void )
{
F_40 ( & V_95 ) ;
}
