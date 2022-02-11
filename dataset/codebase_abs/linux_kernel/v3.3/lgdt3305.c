static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
int V_5 ;
T_2 V_6 [] = { V_3 >> 8 , V_3 & 0xff , V_4 } ;
struct V_7 V_8 = {
. V_9 = V_2 -> V_10 -> V_11 , . V_12 = 0 ,
. V_6 = V_6 , . V_13 = 3 ,
} ;
F_2 ( L_1 , V_3 , V_4 ) ;
V_5 = F_3 ( V_2 -> V_14 , & V_8 , 1 ) ;
if ( V_5 != 1 ) {
F_4 ( L_2 ,
V_8 . V_6 [ 0 ] , V_8 . V_6 [ 1 ] , V_8 . V_6 [ 2 ] , V_5 ) ;
if ( V_5 < 0 )
return V_5 ;
else
return - V_15 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 )
{
int V_5 ;
T_2 V_16 [] = { V_3 >> 8 , V_3 & 0xff } ;
struct V_7 V_8 [] = {
{ . V_9 = V_2 -> V_10 -> V_11 ,
. V_12 = 0 , . V_6 = V_16 , . V_13 = 2 } ,
{ . V_9 = V_2 -> V_10 -> V_11 ,
. V_12 = V_17 , . V_6 = V_4 , . V_13 = 1 } ,
} ;
F_2 ( L_3 , V_3 ) ;
V_5 = F_3 ( V_2 -> V_14 , V_8 , 2 ) ;
if ( V_5 != 2 ) {
F_4 ( L_4 ,
V_2 -> V_10 -> V_11 , V_3 , V_5 ) ;
if ( V_5 < 0 )
return V_5 ;
else
return - V_15 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
T_1 V_3 , int V_18 , int V_19 )
{
T_2 V_4 ;
int V_5 ;
F_2 ( L_5 , V_3 , V_18 , V_19 ) ;
V_5 = F_5 ( V_2 , V_3 , & V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_4 &= ~ ( 1 << V_18 ) ;
V_4 |= ( V_19 & 1 ) << V_18 ;
V_5 = F_1 ( V_2 , V_3 , V_4 ) ;
V_20:
return V_5 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_21 * V_22 , int V_13 )
{
int V_23 , V_5 ;
F_2 ( L_6 , V_13 ) ;
for ( V_23 = 0 ; V_23 < V_13 - 1 ; V_23 ++ ) {
V_5 = F_1 ( V_2 , V_22 [ V_23 ] . V_3 , V_22 [ V_23 ] . V_4 ) ;
if ( F_7 ( V_5 ) )
return V_5 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_5 ;
F_10 ( L_7 ) ;
V_5 = F_6 ( V_2 , V_24 , 0 , 0 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
F_11 ( 20 ) ;
V_5 = F_6 ( V_2 , V_24 , 0 , 1 ) ;
V_20:
return V_5 ;
}
static inline int F_12 ( struct V_1 * V_2 ,
enum F_12 V_25 )
{
F_10 ( L_8 , V_25 ) ;
return F_6 ( V_2 , V_26 , 5 , V_25 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
enum V_27 V_28 ,
enum V_29 V_30 )
{
T_2 V_4 ;
int V_5 ;
F_10 ( L_9 , V_28 , V_30 ) ;
V_5 = F_5 ( V_2 , V_26 , & V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_4 &= ~ 0x09 ;
if ( V_28 )
V_4 |= 0x08 ;
if ( V_30 )
V_4 |= 0x01 ;
V_5 = F_1 ( V_2 , V_26 , V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_9 ( V_2 ) ;
V_20:
return V_5 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
T_2 V_33 ;
int V_5 ;
F_10 ( L_7 ) ;
V_5 = F_5 ( V_2 , V_34 , & V_33 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_33 &= ~ 0x03 ;
switch ( V_32 -> V_35 ) {
case V_36 :
V_33 |= 0x03 ;
break;
case V_37 :
V_33 |= 0x00 ;
break;
case V_38 :
V_33 |= 0x01 ;
break;
default:
return - V_39 ;
}
V_5 = F_1 ( V_2 , V_34 , V_33 ) ;
V_20:
return V_5 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
int V_4 ;
switch ( V_32 -> V_35 ) {
case V_36 :
V_4 = 0 ;
break;
case V_37 :
case V_38 :
V_4 = 1 ;
break;
default:
return - V_39 ;
}
F_10 ( L_10 , V_4 ) ;
return F_6 ( V_2 , 0x043f , 2 , V_4 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
T_1 V_40 ;
switch ( V_32 -> V_35 ) {
case V_36 :
V_40 = 0x32c4 ;
break;
case V_37 :
V_40 = 0x2a00 ;
break;
case V_38 :
V_40 = 0x2a80 ;
break;
default:
return - V_39 ;
}
F_10 ( L_11 , V_40 ) ;
F_1 ( V_2 , V_41 , V_40 >> 8 ) ;
F_1 ( V_2 , V_42 , V_40 & 0xff ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
T_1 V_43 , V_44 , V_45 ;
switch ( V_32 -> V_35 ) {
case V_36 :
V_45 = 0x04c0 ;
V_44 = 0x8000 ;
V_43 = 0x8000 ;
break;
case V_37 :
case V_38 :
V_45 = 0x046b ;
V_44 = 0x8889 ;
if ( V_2 -> V_10 -> V_46 == V_47 )
V_43 = 0x6666 ;
else
V_43 = 0x8888 ;
break;
default:
return - V_39 ;
}
if ( V_2 -> V_10 -> V_48 ) {
F_10 ( L_12 , V_45 , V_44 ) ;
F_1 ( V_2 , V_49 ,
V_45 >> 8 ) ;
F_1 ( V_2 , V_50 ,
V_45 & 0xff ) ;
F_1 ( V_2 , V_51 ,
V_44 >> 8 ) ;
F_1 ( V_2 , V_52 ,
V_44 & 0xff ) ;
} else {
F_10 ( L_13 , V_43 ) ;
F_1 ( V_2 , V_53 , V_43 >> 8 ) ;
F_1 ( V_2 , V_54 , V_43 & 0xff ) ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
int V_55 , V_56 ;
switch ( V_32 -> V_35 ) {
case V_36 :
V_55 = 0 ;
V_56 = 0 ;
break;
case V_37 :
case V_38 :
V_55 = 1 ;
V_56 = 1 ;
break;
default:
return - V_39 ;
}
F_10 ( L_14 , V_55 , V_56 ) ;
switch ( V_2 -> V_10 -> V_46 ) {
case V_47 :
F_1 ( V_2 , 0x0314 , 0xe1 | V_55 << 1 ) ;
F_6 ( V_2 , 0x030e , 2 , V_56 ) ;
break;
case V_57 :
F_1 ( V_2 , V_58 , 0xe1 | V_55 << 1 ) ;
F_6 ( V_2 , V_59 , 2 , V_56 ) ;
break;
default:
return - V_39 ;
}
return F_17 ( V_2 , V_32 ) ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
T_1 V_60 = 0 ;
switch ( V_32 -> V_35 ) {
case V_36 :
if ( V_2 -> V_10 -> V_61 )
V_60 = V_2 -> V_10 -> V_61 ;
break;
case V_37 :
if ( V_2 -> V_10 -> V_62 )
V_60 = V_2 -> V_10 -> V_62 ;
break;
case V_38 :
if ( V_2 -> V_10 -> V_63 )
V_60 = V_2 -> V_10 -> V_63 ;
break;
default:
return - V_39 ;
}
if ( V_60 ) {
F_10 ( L_15 , V_60 ) ;
F_6 ( V_2 , V_59 , 3 , 1 ) ;
F_1 ( V_2 , V_64 ,
0xff & ( V_60 >> 8 ) ) ;
F_1 ( V_2 , V_65 ,
0xff & ( V_60 >> 0 ) ) ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_31 * V_32 ,
int V_66 )
{
int V_5 ;
F_10 ( L_8 , V_66 ) ;
switch ( V_32 -> V_35 ) {
case V_36 :
V_5 = F_1 ( V_2 , V_67 ,
V_66 ? 0xf9 : 0x79 ) ;
break;
case V_37 :
case V_38 :
V_5 = F_1 ( V_2 , V_68 ,
V_66 ? 0xfd : 0xff ) ;
break;
default:
V_5 = - V_39 ;
}
return V_5 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
T_1 V_69 ;
T_2 V_70 , V_71 , V_72 , V_73 ;
T_3 V_74 ;
switch ( V_32 -> V_35 ) {
case V_36 :
V_69 = V_2 -> V_10 -> V_75 ;
break;
case V_37 :
case V_38 :
V_69 = V_2 -> V_10 -> V_76 ;
break;
default:
return - V_39 ;
}
V_74 = V_69 / 10 ;
switch ( V_32 -> V_35 ) {
case V_36 :
V_74 <<= 24 ;
F_22 ( V_74 , 625 ) ;
break;
case V_37 :
case V_38 :
V_74 <<= 28 ;
F_22 ( V_74 , 625 ) ;
break;
default:
return - V_39 ;
}
V_70 = ( V_74 >> 24 ) & 0x3f ;
V_70 |= 0x40 ;
V_71 = ( V_74 >> 16 ) & 0xff ;
V_72 = ( V_74 >> 8 ) & 0xff ;
V_73 = V_74 & 0xff ;
F_1 ( V_2 , V_77 , V_70 ) ;
F_1 ( V_2 , V_78 , V_71 ) ;
F_1 ( V_2 , V_79 , V_72 ) ;
F_1 ( V_2 , V_80 , V_73 ) ;
F_10 ( L_16 ,
V_69 , V_70 , V_71 , V_72 , V_73 ) ;
return 0 ;
}
static int F_23 ( struct V_81 * V_82 , int V_83 )
{
struct V_1 * V_2 = V_82 -> V_84 ;
if ( V_2 -> V_10 -> V_85 )
return 0 ;
F_10 ( L_8 , V_83 ) ;
return F_6 ( V_2 , V_86 , 5 ,
V_83 ? 0 : 1 ) ;
}
static int F_24 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = V_82 -> V_84 ;
T_2 V_87 , V_88 ;
F_10 ( L_7 ) ;
V_87 = F_25 ( V_2 , V_24 ) ;
V_88 = F_25 ( V_2 , V_89 ) ;
V_87 &= ~ 0x01 ;
V_87 |= 0x02 ;
V_87 |= 0x04 ;
V_88 &= ~ 0x01 ;
V_88 &= ~ 0x02 ;
F_1 ( V_2 , V_24 , V_87 ) ;
F_1 ( V_2 , V_89 , V_88 ) ;
return 0 ;
}
static int F_26 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = V_82 -> V_84 ;
int V_5 ;
static struct V_21 V_90 [] = {
{ . V_3 = V_34 , . V_4 = 0x03 , } ,
{ . V_3 = 0x000d , . V_4 = 0x02 , } ,
{ . V_3 = 0x000e , . V_4 = 0x02 , } ,
{ . V_3 = V_41 , . V_4 = 0x32 , } ,
{ . V_3 = V_42 , . V_4 = 0xc4 , } ,
{ . V_3 = V_77 , . V_4 = 0x00 , } ,
{ . V_3 = V_78 , . V_4 = 0x00 , } ,
{ . V_3 = V_79 , . V_4 = 0x00 , } ,
{ . V_3 = V_80 , . V_4 = 0x00 , } ,
{ . V_3 = V_67 , . V_4 = 0xf9 , } ,
{ . V_3 = 0x0112 , . V_4 = 0x17 , } ,
{ . V_3 = 0x0113 , . V_4 = 0x15 , } ,
{ . V_3 = 0x0114 , . V_4 = 0x18 , } ,
{ . V_3 = 0x0115 , . V_4 = 0xff , } ,
{ . V_3 = 0x0116 , . V_4 = 0x3c , } ,
{ . V_3 = 0x0214 , . V_4 = 0x67 , } ,
{ . V_3 = 0x0424 , . V_4 = 0x8d , } ,
{ . V_3 = 0x0427 , . V_4 = 0x12 , } ,
{ . V_3 = 0x0428 , . V_4 = 0x4f , } ,
{ . V_3 = V_53 , . V_4 = 0x80 , } ,
{ . V_3 = V_54 , . V_4 = 0x00 , } ,
{ . V_3 = 0x030a , . V_4 = 0x08 , } ,
{ . V_3 = 0x030b , . V_4 = 0x9b , } ,
{ . V_3 = 0x030d , . V_4 = 0x00 , } ,
{ . V_3 = 0x030e , . V_4 = 0x1c , } ,
{ . V_3 = 0x0314 , . V_4 = 0xe1 , } ,
{ . V_3 = 0x000d , . V_4 = 0x82 , } ,
{ . V_3 = V_26 , . V_4 = 0x5b , } ,
{ . V_3 = V_26 , . V_4 = 0x5b , } ,
} ;
static struct V_21 V_91 [] = {
{ . V_3 = V_34 , . V_4 = 0x03 , } ,
{ . V_3 = V_86 , . V_4 = 0xb0 , } ,
{ . V_3 = V_24 , . V_4 = 0x01 , } ,
{ . V_3 = V_92 , . V_4 = 0x6f , } ,
{ . V_3 = V_89 , . V_4 = 0x03 , } ,
{ . V_3 = V_41 , . V_4 = 0x32 , } ,
{ . V_3 = V_42 , . V_4 = 0xc4 , } ,
{ . V_3 = V_77 , . V_4 = 0x00 , } ,
{ . V_3 = V_78 , . V_4 = 0x00 , } ,
{ . V_3 = V_79 , . V_4 = 0x00 , } ,
{ . V_3 = V_80 , . V_4 = 0x00 , } ,
{ . V_3 = V_67 , . V_4 = 0x79 , } ,
{ . V_3 = V_64 , . V_4 = 0x32 , } ,
{ . V_3 = V_65 , . V_4 = 0xc4 , } ,
{ . V_3 = V_49 , . V_4 = 0x0d , } ,
{ . V_3 = V_50 , . V_4 = 0x30 , } ,
{ . V_3 = V_51 , . V_4 = 0x80 , } ,
{ . V_3 = V_52 , . V_4 = 0x00 , } ,
{ . V_3 = V_53 , . V_4 = 0x80 , } ,
{ . V_3 = V_54 , . V_4 = 0x00 , } ,
{ . V_3 = V_59 , . V_4 = 0x30 , } ,
{ . V_3 = V_58 , . V_4 = 0x61 , } ,
{ . V_3 = V_68 , . V_4 = 0xff , } ,
{ . V_3 = V_26 , . V_4 = 0x1b , } ,
} ;
F_10 ( L_7 ) ;
switch ( V_2 -> V_10 -> V_46 ) {
case V_47 :
V_5 = F_8 ( V_2 , V_90 ,
F_27 ( V_90 ) ) ;
break;
case V_57 :
V_5 = F_8 ( V_2 , V_91 ,
F_27 ( V_91 ) ) ;
break;
default:
V_5 = - V_39 ;
}
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_9 ( V_2 ) ;
V_20:
return V_5 ;
}
static int F_28 ( struct V_81 * V_82 )
{
struct V_31 * V_32 = & V_82 -> V_93 ;
struct V_1 * V_2 = V_82 -> V_84 ;
int V_5 ;
F_10 ( L_17 , V_32 -> V_94 , V_32 -> V_35 ) ;
if ( V_82 -> V_95 . V_96 . V_97 ) {
V_5 = V_82 -> V_95 . V_96 . V_97 ( V_82 ) ;
if ( V_82 -> V_95 . V_98 )
V_82 -> V_95 . V_98 ( V_82 , 0 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_2 -> V_99 = V_32 -> V_94 ;
}
V_5 = F_14 ( V_2 , V_32 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_16 ( V_2 , V_32 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_18 ( V_2 , V_32 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
switch ( V_32 -> V_35 ) {
case V_36 :
F_1 ( V_2 , 0x030d , 0x00 ) ;
F_1 ( V_2 , V_77 , 0x4f ) ;
F_1 ( V_2 , V_78 , 0x0c ) ;
F_1 ( V_2 , V_79 , 0xac ) ;
F_1 ( V_2 , V_80 , 0xba ) ;
break;
case V_37 :
case V_38 :
F_1 ( V_2 , 0x030d , 0x14 ) ;
V_5 = F_21 ( V_2 , V_32 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
break;
default:
return - V_39 ;
}
V_5 = F_20 ( V_2 , V_32 ,
V_2 -> V_10 -> V_100
? 1 : 0 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_2 -> V_101 = V_32 -> V_35 ;
V_5 = F_12 ( V_2 , V_2 -> V_10 -> V_102 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_13 ( V_2 ,
V_2 -> V_10 -> V_103 ,
V_2 -> V_10 -> V_104 ) ;
V_20:
return V_5 ;
}
static int F_29 ( struct V_81 * V_82 )
{
struct V_31 * V_32 = & V_82 -> V_93 ;
struct V_1 * V_2 = V_82 -> V_84 ;
int V_5 ;
F_10 ( L_17 , V_32 -> V_94 , V_32 -> V_35 ) ;
if ( V_82 -> V_95 . V_96 . V_97 ) {
V_5 = V_82 -> V_95 . V_96 . V_97 ( V_82 ) ;
if ( V_82 -> V_95 . V_98 )
V_82 -> V_95 . V_98 ( V_82 , 0 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_2 -> V_99 = V_32 -> V_94 ;
}
V_5 = F_14 ( V_2 , V_32 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_16 ( V_2 , V_32 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_19 ( V_2 , V_32 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_18 ( V_2 , V_32 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_1 ( V_2 , V_92 , 0x2f ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_6 ( V_2 , V_77 , 6 , 1 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_21 ( V_2 , V_32 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_20 ( V_2 , V_32 ,
V_2 -> V_10 -> V_100
? 1 : 0 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_15 ( V_2 , V_32 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_2 -> V_101 = V_32 -> V_35 ;
V_5 = F_12 ( V_2 , V_2 -> V_10 -> V_102 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_13 ( V_2 ,
V_2 -> V_10 -> V_103 ,
V_2 -> V_10 -> V_104 ) ;
V_20:
return V_5 ;
}
static int F_30 ( struct V_81 * V_82 )
{
struct V_31 * V_32 = & V_82 -> V_93 ;
struct V_1 * V_2 = V_82 -> V_84 ;
F_10 ( L_7 ) ;
V_32 -> V_35 = V_2 -> V_101 ;
V_32 -> V_94 = V_2 -> V_99 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
int * V_105 )
{
T_2 V_4 ;
int V_5 ;
char * V_106 = L_18 ;
* V_105 = 0 ;
V_5 = F_5 ( V_2 , V_107 , & V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
switch ( V_2 -> V_101 ) {
case V_38 :
case V_37 :
if ( V_4 & ( 1 << 1 ) )
* V_105 = 1 ;
switch ( V_4 & 0x07 ) {
case 0 :
V_106 = L_19 ;
break;
case 4 :
V_106 = L_20 ;
break;
case 6 :
V_106 = L_21 ;
break;
case 7 :
V_106 = L_22 ;
break;
default:
V_106 = L_23 ;
break;
}
break;
case V_36 :
if ( V_4 & ( 1 << 7 ) ) {
* V_105 = 1 ;
V_106 = L_24 ;
}
break;
default:
V_5 = - V_39 ;
}
F_10 ( L_25 , * V_105 , V_106 ) ;
V_20:
return V_5 ;
}
static int F_32 ( struct V_1 * V_2 ,
int * V_105 )
{
T_2 V_4 ;
int V_5 , V_108 , V_109 , V_110 ;
* V_105 = 0 ;
switch ( V_2 -> V_101 ) {
case V_38 :
case V_37 :
V_5 = F_5 ( V_2 ,
V_111 , & V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_108 = ( V_4 & ( 1 << 0 ) ) ? 1 : 0 ;
V_109 = ( V_4 & ( 1 << 2 ) ) ? 1 : 0 ;
V_110 = ( V_4 & ( 1 << 3 ) ) ? 1 : 0 ;
* V_105 = V_108 && V_109 && V_110 ;
F_10 ( L_26 , * V_105 ,
V_108 ? L_27 : L_18 ,
V_109 ? L_28 : L_18 ,
V_110 ? L_29 : L_18 ) ;
break;
case V_36 :
default:
V_5 = - V_39 ;
}
V_20:
return V_5 ;
}
static int F_33 ( struct V_81 * V_82 , T_4 * V_112 )
{
struct V_1 * V_2 = V_82 -> V_84 ;
T_2 V_4 ;
int V_5 , signal , V_113 , V_114 , V_115 ,
V_116 , V_109 , V_117 ;
* V_112 = 0 ;
V_5 = F_5 ( V_2 , V_118 , & V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
signal = ( V_4 & ( 1 << 4 ) ) ? 1 : 0 ;
V_113 = ( V_4 & ( 1 << 3 ) ) ? 0 : 1 ;
V_117 = ( V_4 & ( 1 << 2 ) ) ? 1 : 0 ;
V_114 = ( V_4 & ( 1 << 1 ) ) ? 1 : 0 ;
V_115 = ( V_4 & ( 1 << 0 ) ) ? 1 : 0 ;
F_10 ( L_30 ,
signal ? L_31 : L_18 ,
V_113 ? L_32 : L_18 ,
V_117 ? L_33 : L_18 ,
V_114 ? L_34 : L_18 ,
V_115 ? L_35 : L_18 ) ;
V_5 = F_31 ( V_2 , & V_116 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
if ( signal )
* V_112 |= V_119 ;
if ( V_116 )
* V_112 |= V_120 ;
if ( V_114 )
* V_112 |= V_121 ;
if ( V_117 )
* V_112 |= V_122 ;
switch ( V_2 -> V_101 ) {
case V_38 :
case V_37 :
if ( ( ( V_47 == V_2 -> V_10 -> V_46 ) ) && ( V_116 ) )
* V_112 |= V_119 ;
V_5 = F_32 ( V_2 , & V_109 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
if ( V_109 )
* V_112 |= V_123 ;
break;
case V_36 :
if ( V_113 )
* V_112 |= V_123 ;
break;
default:
V_5 = - V_39 ;
}
V_20:
return V_5 ;
}
static T_5 F_34 ( T_5 V_124 , T_5 V_125 )
{
if ( V_124 == 0 )
return 0 ;
V_124 = F_35 ( V_124 ) ;
if ( V_124 > V_125 ) {
return 0 ;
}
return 10 * ( V_125 - V_124 ) ;
}
static int F_36 ( struct V_81 * V_82 , T_1 * V_126 )
{
struct V_1 * V_2 = V_82 -> V_84 ;
T_5 V_127 ;
T_5 V_125 ;
switch ( V_2 -> V_101 ) {
case V_36 :
#ifdef F_37
V_127 = ( ( F_25 ( V_2 , V_128 ) & 0x07 ) << 16 ) |
( F_25 ( V_2 , V_129 ) << 8 ) |
( F_25 ( V_2 , V_130 ) & 0xff ) ;
V_125 = 73957994 ;
#else
V_127 = ( ( F_25 ( V_2 , V_131 ) & 0x0f ) << 16 ) |
( F_25 ( V_2 , V_132 ) << 8 ) |
( F_25 ( V_2 , V_133 ) & 0xff ) ;
V_125 = 73957994 ;
#endif
break;
case V_37 :
case V_38 :
V_127 = ( F_25 ( V_2 , V_134 ) << 8 ) |
( F_25 ( V_2 , V_135 ) & 0xff ) ;
V_125 = ( V_2 -> V_101 == V_37 ) ?
97939837 : 98026066 ;
break;
default:
return - V_39 ;
}
V_2 -> V_126 = F_34 ( V_127 , V_125 ) ;
* V_126 = ( V_2 -> V_126 / ( ( 1 << 24 ) / 10 ) ) ;
F_10 ( L_36 , V_127 ,
V_2 -> V_126 >> 24 , ( ( ( V_2 -> V_126 >> 8 ) & 0xffff ) * 100 ) >> 16 ) ;
return 0 ;
}
static int F_38 ( struct V_81 * V_82 ,
T_1 * V_136 )
{
struct V_1 * V_2 = V_82 -> V_84 ;
T_1 V_126 ;
int V_5 ;
* V_136 = 0 ;
V_5 = V_82 -> V_95 . V_137 ( V_82 , & V_126 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
if ( V_2 -> V_126 >= 8960 * 0x10000 )
* V_136 = 0xffff ;
else
* V_136 = V_2 -> V_126 / 8960 ;
V_20:
return V_5 ;
}
static int F_39 ( struct V_81 * V_82 , T_5 * V_138 )
{
* V_138 = 0 ;
return 0 ;
}
static int F_40 ( struct V_81 * V_82 , T_5 * V_139 )
{
struct V_1 * V_2 = V_82 -> V_84 ;
* V_139 =
( F_25 ( V_2 , V_140 ) << 8 ) |
( F_25 ( V_2 , V_141 ) & 0xff ) ;
return 0 ;
}
static int F_41 ( struct V_81 * V_82 ,
struct V_142
* V_143 )
{
V_143 -> V_144 = 500 ;
F_10 ( L_7 ) ;
return 0 ;
}
static void F_42 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = V_82 -> V_84 ;
F_10 ( L_7 ) ;
F_43 ( V_2 ) ;
}
struct V_81 * F_44 ( const struct V_145 * V_146 ,
struct V_147 * V_14 )
{
struct V_1 * V_2 = NULL ;
int V_5 ;
T_2 V_4 ;
F_10 ( L_37 ,
V_14 ? F_45 ( V_14 ) : 0 ,
V_146 ? V_146 -> V_11 : 0 ) ;
V_2 = F_46 ( sizeof( struct V_1 ) , V_148 ) ;
if ( V_2 == NULL )
goto V_20;
V_2 -> V_10 = V_146 ;
V_2 -> V_14 = V_14 ;
switch ( V_146 -> V_46 ) {
case V_47 :
memcpy ( & V_2 -> V_149 . V_95 , & V_150 ,
sizeof( struct V_151 ) ) ;
break;
case V_57 :
memcpy ( & V_2 -> V_149 . V_95 , & V_152 ,
sizeof( struct V_151 ) ) ;
break;
default:
goto V_20;
}
V_2 -> V_149 . V_84 = V_2 ;
V_5 = F_5 ( V_2 , V_86 , & V_4 ) ;
if ( ( F_7 ( V_5 ) ) | ( V_4 == 0 ) )
goto V_20;
V_5 = F_1 ( V_2 , 0x0808 , 0x80 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_5 ( V_2 , 0x0808 , & V_4 ) ;
if ( ( F_7 ( V_5 ) ) | ( V_4 != 0x80 ) )
goto V_20;
V_5 = F_1 ( V_2 , 0x0808 , 0x00 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_2 -> V_99 = - 1 ;
V_2 -> V_101 = - 1 ;
return & V_2 -> V_149 ;
V_20:
F_47 ( L_38 ,
V_146 -> V_46 ? L_39 : L_40 ) ;
F_43 ( V_2 ) ;
return NULL ;
}
