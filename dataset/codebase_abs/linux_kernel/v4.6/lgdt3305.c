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
static int F_13 ( struct V_1 * V_2 )
{
T_2 V_4 ;
int V_5 ;
enum V_27 V_28 = V_2 -> V_10 -> V_29 ;
enum V_30 V_25 = V_2 -> V_10 -> V_31 ;
enum V_32 V_33 = V_2 -> V_10 -> V_34 ;
F_10 ( L_9 , V_28 , V_33 ) ;
V_5 = F_5 ( V_2 , V_26 , & V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_4 &= ~ 0x09 ;
if ( V_28 )
V_4 |= 0x08 ;
if ( V_25 )
V_4 |= 0x40 ;
if ( V_33 )
V_4 |= 0x01 ;
V_5 = F_1 ( V_2 , V_26 , V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_9 ( V_2 ) ;
V_20:
return V_5 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
T_2 V_37 ;
int V_5 ;
F_10 ( L_7 ) ;
V_5 = F_5 ( V_2 , V_38 , & V_37 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_37 &= ~ 0x03 ;
switch ( V_36 -> V_39 ) {
case V_40 :
V_37 |= 0x03 ;
break;
case V_41 :
V_37 |= 0x00 ;
break;
case V_42 :
V_37 |= 0x01 ;
break;
default:
return - V_43 ;
}
V_5 = F_1 ( V_2 , V_38 , V_37 ) ;
V_20:
return V_5 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
int V_4 ;
switch ( V_36 -> V_39 ) {
case V_40 :
V_4 = 0 ;
break;
case V_41 :
case V_42 :
V_4 = 1 ;
break;
default:
return - V_43 ;
}
F_10 ( L_10 , V_4 ) ;
return F_6 ( V_2 , 0x043f , 2 , V_4 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
T_1 V_44 ;
switch ( V_36 -> V_39 ) {
case V_40 :
V_44 = 0x32c4 ;
break;
case V_41 :
V_44 = 0x2a00 ;
break;
case V_42 :
V_44 = 0x2a80 ;
break;
default:
return - V_43 ;
}
F_10 ( L_11 , V_44 ) ;
F_1 ( V_2 , V_45 , V_44 >> 8 ) ;
F_1 ( V_2 , V_46 , V_44 & 0xff ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
T_1 V_47 , V_48 , V_49 ;
switch ( V_36 -> V_39 ) {
case V_40 :
V_49 = 0x04c0 ;
V_48 = 0x8000 ;
V_47 = 0x8000 ;
break;
case V_41 :
case V_42 :
V_49 = 0x046b ;
V_48 = 0x8889 ;
if ( V_2 -> V_10 -> V_50 == V_51 )
V_47 = 0x6666 ;
else
V_47 = 0x8888 ;
break;
default:
return - V_43 ;
}
if ( V_2 -> V_10 -> V_52 ) {
F_10 ( L_12 , V_49 , V_48 ) ;
F_1 ( V_2 , V_53 ,
V_49 >> 8 ) ;
F_1 ( V_2 , V_54 ,
V_49 & 0xff ) ;
F_1 ( V_2 , V_55 ,
V_48 >> 8 ) ;
F_1 ( V_2 , V_56 ,
V_48 & 0xff ) ;
} else {
F_10 ( L_13 , V_47 ) ;
F_1 ( V_2 , V_57 , V_47 >> 8 ) ;
F_1 ( V_2 , V_58 , V_47 & 0xff ) ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
int V_59 , V_60 ;
switch ( V_36 -> V_39 ) {
case V_40 :
V_59 = 0 ;
V_60 = 0 ;
break;
case V_41 :
case V_42 :
V_59 = 1 ;
V_60 = 1 ;
break;
default:
return - V_43 ;
}
F_10 ( L_14 , V_59 , V_60 ) ;
switch ( V_2 -> V_10 -> V_50 ) {
case V_51 :
F_1 ( V_2 , 0x0314 , 0xe1 | V_59 << 1 ) ;
F_6 ( V_2 , 0x030e , 2 , V_60 ) ;
break;
case V_61 :
F_1 ( V_2 , V_62 , 0xe1 | V_59 << 1 ) ;
F_6 ( V_2 , V_63 , 2 , V_60 ) ;
break;
default:
return - V_43 ;
}
return F_17 ( V_2 , V_36 ) ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
T_1 V_64 = 0 ;
switch ( V_36 -> V_39 ) {
case V_40 :
if ( V_2 -> V_10 -> V_65 )
V_64 = V_2 -> V_10 -> V_65 ;
break;
case V_41 :
if ( V_2 -> V_10 -> V_66 )
V_64 = V_2 -> V_10 -> V_66 ;
break;
case V_42 :
if ( V_2 -> V_10 -> V_67 )
V_64 = V_2 -> V_10 -> V_67 ;
break;
default:
return - V_43 ;
}
if ( V_64 ) {
F_10 ( L_15 , V_64 ) ;
F_6 ( V_2 , V_63 , 3 , 1 ) ;
F_1 ( V_2 , V_68 ,
0xff & ( V_64 >> 8 ) ) ;
F_1 ( V_2 , V_69 ,
0xff & ( V_64 >> 0 ) ) ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_35 * V_36 ,
int V_70 )
{
int V_5 ;
F_10 ( L_8 , V_70 ) ;
switch ( V_36 -> V_39 ) {
case V_40 :
V_5 = F_1 ( V_2 , V_71 ,
V_70 ? 0xf9 : 0x79 ) ;
break;
case V_41 :
case V_42 :
V_5 = F_1 ( V_2 , V_72 ,
V_70 ? 0xfd : 0xff ) ;
break;
default:
V_5 = - V_43 ;
}
return V_5 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
T_1 V_73 ;
T_2 V_74 , V_75 , V_76 , V_77 ;
T_3 V_78 ;
switch ( V_36 -> V_39 ) {
case V_40 :
V_73 = V_2 -> V_10 -> V_79 ;
break;
case V_41 :
case V_42 :
V_73 = V_2 -> V_10 -> V_80 ;
break;
default:
return - V_43 ;
}
V_78 = V_73 / 10 ;
switch ( V_36 -> V_39 ) {
case V_40 :
V_78 <<= 24 ;
F_22 ( V_78 , 625 ) ;
break;
case V_41 :
case V_42 :
V_78 <<= 28 ;
F_22 ( V_78 , 625 ) ;
break;
default:
return - V_43 ;
}
V_74 = ( V_78 >> 24 ) & 0x3f ;
V_74 |= 0x40 ;
V_75 = ( V_78 >> 16 ) & 0xff ;
V_76 = ( V_78 >> 8 ) & 0xff ;
V_77 = V_78 & 0xff ;
F_1 ( V_2 , V_81 , V_74 ) ;
F_1 ( V_2 , V_82 , V_75 ) ;
F_1 ( V_2 , V_83 , V_76 ) ;
F_1 ( V_2 , V_84 , V_77 ) ;
F_10 ( L_16 ,
V_73 , V_74 , V_75 , V_76 , V_77 ) ;
return 0 ;
}
static int F_23 ( struct V_85 * V_86 , int V_87 )
{
struct V_1 * V_2 = V_86 -> V_88 ;
if ( V_2 -> V_10 -> V_89 )
return 0 ;
F_10 ( L_8 , V_87 ) ;
return F_6 ( V_2 , V_90 , 5 ,
V_87 ? 0 : 1 ) ;
}
static int F_24 ( struct V_85 * V_86 )
{
struct V_1 * V_2 = V_86 -> V_88 ;
T_2 V_91 , V_92 ;
F_10 ( L_7 ) ;
V_91 = F_25 ( V_2 , V_24 ) ;
V_92 = F_25 ( V_2 , V_93 ) ;
V_91 &= ~ 0x01 ;
V_91 |= 0x02 ;
V_91 |= 0x04 ;
V_92 &= ~ 0x01 ;
V_92 &= ~ 0x02 ;
F_1 ( V_2 , V_24 , V_91 ) ;
F_1 ( V_2 , V_93 , V_92 ) ;
return 0 ;
}
static int F_26 ( struct V_85 * V_86 )
{
struct V_1 * V_2 = V_86 -> V_88 ;
int V_5 ;
static struct V_21 V_94 [] = {
{ . V_3 = V_38 , . V_4 = 0x03 , } ,
{ . V_3 = 0x000d , . V_4 = 0x02 , } ,
{ . V_3 = 0x000e , . V_4 = 0x02 , } ,
{ . V_3 = V_45 , . V_4 = 0x32 , } ,
{ . V_3 = V_46 , . V_4 = 0xc4 , } ,
{ . V_3 = V_81 , . V_4 = 0x00 , } ,
{ . V_3 = V_82 , . V_4 = 0x00 , } ,
{ . V_3 = V_83 , . V_4 = 0x00 , } ,
{ . V_3 = V_84 , . V_4 = 0x00 , } ,
{ . V_3 = V_71 , . V_4 = 0xf9 , } ,
{ . V_3 = 0x0112 , . V_4 = 0x17 , } ,
{ . V_3 = 0x0113 , . V_4 = 0x15 , } ,
{ . V_3 = 0x0114 , . V_4 = 0x18 , } ,
{ . V_3 = 0x0115 , . V_4 = 0xff , } ,
{ . V_3 = 0x0116 , . V_4 = 0x3c , } ,
{ . V_3 = 0x0214 , . V_4 = 0x67 , } ,
{ . V_3 = 0x0424 , . V_4 = 0x8d , } ,
{ . V_3 = 0x0427 , . V_4 = 0x12 , } ,
{ . V_3 = 0x0428 , . V_4 = 0x4f , } ,
{ . V_3 = V_57 , . V_4 = 0x80 , } ,
{ . V_3 = V_58 , . V_4 = 0x00 , } ,
{ . V_3 = 0x030a , . V_4 = 0x08 , } ,
{ . V_3 = 0x030b , . V_4 = 0x9b , } ,
{ . V_3 = 0x030d , . V_4 = 0x00 , } ,
{ . V_3 = 0x030e , . V_4 = 0x1c , } ,
{ . V_3 = 0x0314 , . V_4 = 0xe1 , } ,
{ . V_3 = 0x000d , . V_4 = 0x82 , } ,
{ . V_3 = V_26 , . V_4 = 0x5b , } ,
{ . V_3 = V_26 , . V_4 = 0x5b , } ,
} ;
static struct V_21 V_95 [] = {
{ . V_3 = V_38 , . V_4 = 0x03 , } ,
{ . V_3 = V_90 , . V_4 = 0xb0 , } ,
{ . V_3 = V_24 , . V_4 = 0x01 , } ,
{ . V_3 = V_96 , . V_4 = 0x6f , } ,
{ . V_3 = V_93 , . V_4 = 0x03 , } ,
{ . V_3 = V_45 , . V_4 = 0x32 , } ,
{ . V_3 = V_46 , . V_4 = 0xc4 , } ,
{ . V_3 = V_81 , . V_4 = 0x00 , } ,
{ . V_3 = V_82 , . V_4 = 0x00 , } ,
{ . V_3 = V_83 , . V_4 = 0x00 , } ,
{ . V_3 = V_84 , . V_4 = 0x00 , } ,
{ . V_3 = V_71 , . V_4 = 0x79 , } ,
{ . V_3 = V_68 , . V_4 = 0x32 , } ,
{ . V_3 = V_69 , . V_4 = 0xc4 , } ,
{ . V_3 = V_53 , . V_4 = 0x0d , } ,
{ . V_3 = V_54 , . V_4 = 0x30 , } ,
{ . V_3 = V_55 , . V_4 = 0x80 , } ,
{ . V_3 = V_56 , . V_4 = 0x00 , } ,
{ . V_3 = V_57 , . V_4 = 0x80 , } ,
{ . V_3 = V_58 , . V_4 = 0x00 , } ,
{ . V_3 = V_63 , . V_4 = 0x30 , } ,
{ . V_3 = V_62 , . V_4 = 0x61 , } ,
{ . V_3 = V_72 , . V_4 = 0xff , } ,
{ . V_3 = V_26 , . V_4 = 0x1b , } ,
} ;
F_10 ( L_7 ) ;
switch ( V_2 -> V_10 -> V_50 ) {
case V_51 :
V_5 = F_8 ( V_2 , V_94 ,
F_27 ( V_94 ) ) ;
break;
case V_61 :
V_5 = F_8 ( V_2 , V_95 ,
F_27 ( V_95 ) ) ;
break;
default:
V_5 = - V_43 ;
}
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_9 ( V_2 ) ;
V_20:
return V_5 ;
}
static int F_28 ( struct V_85 * V_86 )
{
struct V_35 * V_36 = & V_86 -> V_97 ;
struct V_1 * V_2 = V_86 -> V_88 ;
int V_5 ;
F_10 ( L_17 , V_36 -> V_98 , V_36 -> V_39 ) ;
if ( V_86 -> V_99 . V_100 . V_101 ) {
V_5 = V_86 -> V_99 . V_100 . V_101 ( V_86 ) ;
if ( V_86 -> V_99 . V_102 )
V_86 -> V_99 . V_102 ( V_86 , 0 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_2 -> V_103 = V_36 -> V_98 ;
}
V_5 = F_14 ( V_2 , V_36 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_16 ( V_2 , V_36 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_18 ( V_2 , V_36 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
switch ( V_36 -> V_39 ) {
case V_40 :
F_1 ( V_2 , 0x030d , 0x00 ) ;
F_1 ( V_2 , V_81 , 0x4f ) ;
F_1 ( V_2 , V_82 , 0x0c ) ;
F_1 ( V_2 , V_83 , 0xac ) ;
F_1 ( V_2 , V_84 , 0xba ) ;
break;
case V_41 :
case V_42 :
F_1 ( V_2 , 0x030d , 0x14 ) ;
V_5 = F_21 ( V_2 , V_36 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
break;
default:
return - V_43 ;
}
V_5 = F_20 ( V_2 , V_36 ,
V_2 -> V_10 -> V_104
? 1 : 0 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_2 -> V_105 = V_36 -> V_39 ;
V_5 = F_12 ( V_2 , V_2 -> V_10 -> V_106 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_13 ( V_2 ) ;
V_20:
return V_5 ;
}
static int F_29 ( struct V_85 * V_86 )
{
struct V_35 * V_36 = & V_86 -> V_97 ;
struct V_1 * V_2 = V_86 -> V_88 ;
int V_5 ;
F_10 ( L_17 , V_36 -> V_98 , V_36 -> V_39 ) ;
if ( V_86 -> V_99 . V_100 . V_101 ) {
V_5 = V_86 -> V_99 . V_100 . V_101 ( V_86 ) ;
if ( V_86 -> V_99 . V_102 )
V_86 -> V_99 . V_102 ( V_86 , 0 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_2 -> V_103 = V_36 -> V_98 ;
}
V_5 = F_14 ( V_2 , V_36 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_16 ( V_2 , V_36 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_19 ( V_2 , V_36 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_18 ( V_2 , V_36 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_1 ( V_2 , V_96 , 0x2f ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_6 ( V_2 , V_81 , 6 , 1 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_21 ( V_2 , V_36 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_20 ( V_2 , V_36 ,
V_2 -> V_10 -> V_104
? 1 : 0 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_15 ( V_2 , V_36 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_2 -> V_105 = V_36 -> V_39 ;
V_5 = F_12 ( V_2 , V_2 -> V_10 -> V_106 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_13 ( V_2 ) ;
V_20:
return V_5 ;
}
static int F_30 ( struct V_85 * V_86 ,
struct V_35 * V_36 )
{
struct V_1 * V_2 = V_86 -> V_88 ;
F_10 ( L_7 ) ;
V_36 -> V_39 = V_2 -> V_105 ;
V_36 -> V_98 = V_2 -> V_103 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
int * V_107 )
{
T_2 V_4 ;
int V_5 ;
char * V_108 = L_18 ;
* V_107 = 0 ;
V_5 = F_5 ( V_2 , V_109 , & V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
switch ( V_2 -> V_105 ) {
case V_42 :
case V_41 :
if ( V_4 & ( 1 << 1 ) )
* V_107 = 1 ;
switch ( V_4 & 0x07 ) {
case 0 :
V_108 = L_19 ;
break;
case 4 :
V_108 = L_20 ;
break;
case 6 :
V_108 = L_21 ;
break;
case 7 :
V_108 = L_22 ;
break;
default:
V_108 = L_23 ;
break;
}
break;
case V_40 :
if ( V_4 & ( 1 << 7 ) ) {
* V_107 = 1 ;
V_108 = L_24 ;
}
break;
default:
V_5 = - V_43 ;
}
F_10 ( L_25 , * V_107 , V_108 ) ;
V_20:
return V_5 ;
}
static int F_32 ( struct V_1 * V_2 ,
int * V_107 )
{
T_2 V_4 ;
int V_5 , V_110 , V_111 , V_112 ;
* V_107 = 0 ;
switch ( V_2 -> V_105 ) {
case V_42 :
case V_41 :
V_5 = F_5 ( V_2 ,
V_113 , & V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_110 = ( V_4 & ( 1 << 0 ) ) ? 1 : 0 ;
V_111 = ( V_4 & ( 1 << 2 ) ) ? 1 : 0 ;
V_112 = ( V_4 & ( 1 << 3 ) ) ? 1 : 0 ;
* V_107 = V_110 && V_111 && V_112 ;
F_10 ( L_26 , * V_107 ,
V_110 ? L_27 : L_18 ,
V_111 ? L_28 : L_18 ,
V_112 ? L_29 : L_18 ) ;
break;
case V_40 :
default:
V_5 = - V_43 ;
}
V_20:
return V_5 ;
}
static int F_33 ( struct V_85 * V_86 , enum V_114 * V_115 )
{
struct V_1 * V_2 = V_86 -> V_88 ;
T_2 V_4 ;
int V_5 , signal , V_116 , V_117 , V_118 ,
V_119 , V_111 , V_120 ;
* V_115 = 0 ;
V_5 = F_5 ( V_2 , V_121 , & V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
signal = ( V_4 & ( 1 << 4 ) ) ? 1 : 0 ;
V_116 = ( V_4 & ( 1 << 3 ) ) ? 0 : 1 ;
V_120 = ( V_4 & ( 1 << 2 ) ) ? 1 : 0 ;
V_117 = ( V_4 & ( 1 << 1 ) ) ? 1 : 0 ;
V_118 = ( V_4 & ( 1 << 0 ) ) ? 1 : 0 ;
F_10 ( L_30 ,
signal ? L_31 : L_18 ,
V_116 ? L_32 : L_18 ,
V_120 ? L_33 : L_18 ,
V_117 ? L_34 : L_18 ,
V_118 ? L_35 : L_18 ) ;
V_5 = F_31 ( V_2 , & V_119 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
if ( signal )
* V_115 |= V_122 ;
if ( V_119 )
* V_115 |= V_123 ;
if ( V_117 )
* V_115 |= V_124 ;
if ( V_120 )
* V_115 |= V_125 ;
switch ( V_2 -> V_105 ) {
case V_42 :
case V_41 :
if ( ( ( V_51 == V_2 -> V_10 -> V_50 ) ) && ( V_119 ) )
* V_115 |= V_122 ;
V_5 = F_32 ( V_2 , & V_111 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
if ( V_111 )
* V_115 |= V_126 ;
break;
case V_40 :
if ( V_116 )
* V_115 |= V_126 ;
break;
default:
V_5 = - V_43 ;
}
V_20:
return V_5 ;
}
static T_4 F_34 ( T_4 V_127 , T_4 V_128 )
{
if ( V_127 == 0 )
return 0 ;
V_127 = F_35 ( V_127 ) ;
if ( V_127 > V_128 ) {
return 0 ;
}
return 10 * ( V_128 - V_127 ) ;
}
static int F_36 ( struct V_85 * V_86 , T_1 * V_129 )
{
struct V_1 * V_2 = V_86 -> V_88 ;
T_4 V_130 ;
T_4 V_128 ;
switch ( V_2 -> V_105 ) {
case V_40 :
#ifdef F_37
V_130 = ( ( F_25 ( V_2 , V_131 ) & 0x07 ) << 16 ) |
( F_25 ( V_2 , V_132 ) << 8 ) |
( F_25 ( V_2 , V_133 ) & 0xff ) ;
V_128 = 73957994 ;
#else
V_130 = ( ( F_25 ( V_2 , V_134 ) & 0x0f ) << 16 ) |
( F_25 ( V_2 , V_135 ) << 8 ) |
( F_25 ( V_2 , V_136 ) & 0xff ) ;
V_128 = 73957994 ;
#endif
break;
case V_41 :
case V_42 :
V_130 = ( F_25 ( V_2 , V_137 ) << 8 ) |
( F_25 ( V_2 , V_138 ) & 0xff ) ;
V_128 = ( V_2 -> V_105 == V_41 ) ?
97939837 : 98026066 ;
break;
default:
return - V_43 ;
}
V_2 -> V_129 = F_34 ( V_130 , V_128 ) ;
* V_129 = ( V_2 -> V_129 / ( ( 1 << 24 ) / 10 ) ) ;
F_10 ( L_36 , V_130 ,
V_2 -> V_129 >> 24 , ( ( ( V_2 -> V_129 >> 8 ) & 0xffff ) * 100 ) >> 16 ) ;
return 0 ;
}
static int F_38 ( struct V_85 * V_86 ,
T_1 * V_139 )
{
struct V_1 * V_2 = V_86 -> V_88 ;
T_1 V_129 ;
int V_5 ;
* V_139 = 0 ;
V_5 = V_86 -> V_99 . V_140 ( V_86 , & V_129 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
if ( V_2 -> V_129 >= 8960 * 0x10000 )
* V_139 = 0xffff ;
else
* V_139 = V_2 -> V_129 / 8960 ;
V_20:
return V_5 ;
}
static int F_39 ( struct V_85 * V_86 , T_4 * V_141 )
{
* V_141 = 0 ;
return 0 ;
}
static int F_40 ( struct V_85 * V_86 , T_4 * V_142 )
{
struct V_1 * V_2 = V_86 -> V_88 ;
* V_142 =
( F_25 ( V_2 , V_143 ) << 8 ) |
( F_25 ( V_2 , V_144 ) & 0xff ) ;
return 0 ;
}
static int F_41 ( struct V_85 * V_86 ,
struct V_145
* V_146 )
{
V_146 -> V_147 = 500 ;
F_10 ( L_7 ) ;
return 0 ;
}
static void F_42 ( struct V_85 * V_86 )
{
struct V_1 * V_2 = V_86 -> V_88 ;
F_10 ( L_7 ) ;
F_43 ( V_2 ) ;
}
struct V_85 * F_44 ( const struct V_148 * V_149 ,
struct V_150 * V_14 )
{
struct V_1 * V_2 = NULL ;
int V_5 ;
T_2 V_4 ;
F_10 ( L_37 ,
V_14 ? F_45 ( V_14 ) : 0 ,
V_149 ? V_149 -> V_11 : 0 ) ;
V_2 = F_46 ( sizeof( struct V_1 ) , V_151 ) ;
if ( V_2 == NULL )
goto V_20;
V_2 -> V_10 = V_149 ;
V_2 -> V_14 = V_14 ;
switch ( V_149 -> V_50 ) {
case V_51 :
memcpy ( & V_2 -> V_152 . V_99 , & V_153 ,
sizeof( struct V_154 ) ) ;
break;
case V_61 :
memcpy ( & V_2 -> V_152 . V_99 , & V_155 ,
sizeof( struct V_154 ) ) ;
break;
default:
goto V_20;
}
V_2 -> V_152 . V_88 = V_2 ;
V_5 = F_5 ( V_2 , V_90 , & V_4 ) ;
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
V_2 -> V_103 = - 1 ;
V_2 -> V_105 = - 1 ;
return & V_2 -> V_152 ;
V_20:
F_47 ( L_38 ,
V_149 -> V_50 ? L_39 : L_40 ) ;
F_43 ( V_2 ) ;
return NULL ;
}
