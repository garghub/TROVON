static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return V_3 == V_4 ;
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
return V_3 <= V_4 ;
}
static int F_3 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_4 ( V_6 ) ;
int V_9 , V_10 , V_11 ;
if ( V_8 -> V_12 ) {
V_11 = 1 ;
for ( V_10 = 2 ; V_10 < F_5 ( V_13 ) ; V_10 ++ ) {
if ( abs ( V_13 [ V_10 ] - V_8 -> V_14 ) <
abs ( V_13 [ V_11 ] - V_8 -> V_14 ) )
V_11 = V_10 ;
}
V_9 = V_11 << 1 ;
} else {
V_11 = 0 ;
V_9 = 0 ;
}
F_6 ( V_6 -> V_2 , L_1 ,
V_11 , V_13 [ V_11 ] ) ;
return F_7 ( V_6 , V_15 , 0x6 , V_9 ) ;
}
static int F_8 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_5 * V_6 = F_9 ( V_17 ) ;
struct V_7 * V_8 = F_4 ( V_6 ) ;
V_19 -> V_20 . V_21 . V_22 [ 0 ] = V_8 -> V_12 ;
return 0 ;
}
static int F_10 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_5 * V_6 = F_9 ( V_17 ) ;
struct V_7 * V_8 = F_4 ( V_6 ) ;
int V_12 = V_19 -> V_20 . V_21 . V_22 [ 0 ] ;
int V_23 = 0 ;
if ( V_12 > 1 )
return - V_24 ;
F_11 ( & V_6 -> V_25 ) ;
if ( V_8 -> V_12 != V_12 ) {
V_8 -> V_12 = V_12 ;
F_3 ( V_6 ) ;
V_23 = 1 ;
}
F_12 ( & V_6 -> V_25 ) ;
return V_23 ;
}
static int F_13 ( struct V_26 * V_27 ,
struct V_26 * V_28 )
{
struct V_7 * V_8 = F_4 ( V_27 -> V_6 ) ;
return V_8 -> V_29 == V_30 ;
}
static inline int F_14 ( int V_31 , int V_32 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < F_5 ( V_33 ) ; V_10 ++ ) {
if ( V_33 [ V_10 ] . V_32 == V_32 && V_33 [ V_10 ] . V_31 == V_31 )
return V_10 ;
}
return 0 ;
}
static int F_15 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
struct V_38 * V_39 )
{
struct V_5 * V_6 = V_39 -> V_6 ;
struct V_7 * V_8 = F_4 ( V_6 ) ;
T_1 V_40 = F_16 ( V_6 , V_41 ) & 0xfff3 ;
int V_10 = F_14 ( V_8 -> V_42 , F_17 ( V_37 ) ) ;
T_1 V_43 = ( V_33 [ V_10 ] . V_44 << 2 ) |
( V_33 [ V_10 ] . V_45 << 1 ) | V_33 [ V_10 ] . V_46 ;
V_8 -> V_14 = F_17 ( V_37 ) ;
F_18 ( V_6 , V_47 , V_43 ) ;
switch ( F_19 ( V_37 ) ) {
case V_48 :
break;
case V_49 :
V_40 |= 0x0004 ;
break;
case V_50 :
V_40 |= 0x0008 ;
break;
}
F_3 ( V_6 ) ;
F_18 ( V_6 , V_41 , V_40 ) ;
return 0 ;
}
static int F_20 ( struct V_38 * V_39 , int V_51 )
{
struct V_5 * V_6 = V_39 -> V_6 ;
T_1 V_52 = F_16 ( V_6 , V_15 ) & 0xfff7 ;
if ( V_51 )
F_18 ( V_6 , V_15 , V_52 | 0x8 ) ;
else
F_18 ( V_6 , V_15 , V_52 ) ;
return 0 ;
}
static int F_21 ( struct V_38 * V_53 ,
int V_54 , unsigned int V_55 , int V_56 )
{
struct V_5 * V_6 = V_53 -> V_6 ;
struct V_7 * V_8 = F_4 ( V_6 ) ;
switch ( V_54 ) {
case V_30 :
case V_57 :
V_8 -> V_29 = V_54 ;
break;
default:
return - V_24 ;
}
switch ( V_55 ) {
case 0 :
V_8 -> V_58 = NULL ;
break;
case 12000000 :
V_8 -> V_58 = & V_59 ;
break;
case 12288000 :
case 18432000 :
V_8 -> V_58 = & V_60 ;
break;
case 16934400 :
case 11289600 :
V_8 -> V_58 = & V_61 ;
break;
default:
return - V_24 ;
}
V_8 -> V_42 = V_55 ;
F_22 ( & V_6 -> V_62 ) ;
return 0 ;
}
static int F_23 ( struct V_38 * V_53 ,
unsigned int V_63 )
{
struct V_5 * V_6 = V_53 -> V_6 ;
T_1 V_40 = 0 ;
switch ( V_63 & V_64 ) {
case V_65 :
V_40 |= 0x0040 ;
break;
case V_66 :
break;
default:
return - V_24 ;
}
switch ( V_63 & V_67 ) {
case V_68 :
V_40 |= 0x0002 ;
break;
case V_69 :
break;
case V_70 :
V_40 |= 0x0001 ;
break;
case V_71 :
V_40 |= 0x0013 ;
break;
case V_72 :
V_40 |= 0x0003 ;
break;
default:
return - V_24 ;
}
switch ( V_63 & V_73 ) {
case V_74 :
break;
case V_75 :
V_40 |= 0x0090 ;
break;
case V_76 :
V_40 |= 0x0080 ;
break;
case V_77 :
V_40 |= 0x0010 ;
break;
default:
return - V_24 ;
}
F_18 ( V_6 , V_41 , V_40 ) ;
return 0 ;
}
static int F_24 ( struct V_5 * V_6 ,
enum V_78 V_79 )
{
struct V_7 * V_8 = F_4 ( V_6 ) ;
int V_23 ;
T_1 V_3 ;
switch ( V_79 ) {
case V_80 :
break;
case V_81 :
break;
case V_82 :
if ( V_6 -> V_62 . V_83 == V_84 ) {
V_23 = F_25 ( F_5 ( V_8 -> V_85 ) ,
V_8 -> V_85 ) ;
if ( V_23 != 0 )
return V_23 ;
F_26 ( V_8 -> V_86 ) ;
}
V_3 = F_16 ( V_6 , V_87 ) & 0xff7f ;
F_18 ( V_6 , V_87 , V_3 | 0x0040 ) ;
break;
case V_84 :
F_18 ( V_6 , V_87 , 0xffff ) ;
F_27 ( F_5 ( V_8 -> V_85 ) ,
V_8 -> V_85 ) ;
F_28 ( V_8 -> V_86 ) ;
break;
}
V_6 -> V_62 . V_83 = V_79 ;
return 0 ;
}
static int F_29 ( struct V_34 * V_35 ,
struct V_38 * V_39 )
{
struct V_7 * V_8 = F_4 ( V_39 -> V_6 ) ;
if ( V_8 -> V_58 )
F_30 ( V_35 -> V_88 , 0 ,
V_89 ,
V_8 -> V_58 ) ;
return 0 ;
}
static int F_31 ( struct V_5 * V_6 )
{
F_24 ( V_6 , V_84 ) ;
return 0 ;
}
static int F_32 ( struct V_5 * V_6 )
{
F_24 ( V_6 , V_82 ) ;
return 0 ;
}
static int F_33 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_4 ( V_6 ) ;
int V_23 = 0 , V_10 ;
V_6 -> V_90 = V_8 -> V_86 ;
V_23 = F_34 ( V_6 , 7 , 9 , V_91 ) ;
if ( V_23 < 0 ) {
F_35 ( V_6 -> V_2 , L_2 , V_23 ) ;
return V_23 ;
}
for ( V_10 = 0 ; V_10 < F_5 ( V_8 -> V_85 ) ; V_10 ++ )
V_8 -> V_85 [ V_10 ] . V_92 = V_93 [ V_10 ] ;
V_23 = F_36 ( V_6 -> V_2 , F_5 ( V_8 -> V_85 ) ,
V_8 -> V_85 ) ;
if ( V_23 != 0 ) {
F_35 ( V_6 -> V_2 , L_3 , V_23 ) ;
return V_23 ;
}
V_23 = F_25 ( F_5 ( V_8 -> V_85 ) ,
V_8 -> V_85 ) ;
if ( V_23 != 0 ) {
F_35 ( V_6 -> V_2 , L_4 , V_23 ) ;
goto V_94;
}
V_23 = F_37 ( V_6 ) ;
if ( V_23 < 0 ) {
F_35 ( V_6 -> V_2 , L_5 , V_23 ) ;
goto V_95;
}
F_24 ( V_6 , V_82 ) ;
F_7 ( V_6 , V_96 , 0x100 , 0 ) ;
F_7 ( V_6 , V_97 , 0x100 , 0 ) ;
F_7 ( V_6 , V_98 , 0x100 , 0 ) ;
F_7 ( V_6 , V_99 , 0x100 , 0 ) ;
F_7 ( V_6 , V_100 , 0x8 , 0 ) ;
F_27 ( F_5 ( V_8 -> V_85 ) , V_8 -> V_85 ) ;
return 0 ;
V_95:
F_27 ( F_5 ( V_8 -> V_85 ) , V_8 -> V_85 ) ;
V_94:
F_38 ( F_5 ( V_8 -> V_85 ) , V_8 -> V_85 ) ;
return V_23 ;
}
static int F_39 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_4 ( V_6 ) ;
F_24 ( V_6 , V_84 ) ;
F_27 ( F_5 ( V_8 -> V_85 ) , V_8 -> V_85 ) ;
F_38 ( F_5 ( V_8 -> V_85 ) , V_8 -> V_85 ) ;
return 0 ;
}
static int F_40 ( struct V_101 * V_102 )
{
struct V_7 * V_8 ;
int V_23 ;
V_8 = F_41 ( & V_102 -> V_2 , sizeof( struct V_7 ) ,
V_103 ) ;
if ( V_8 == NULL )
return - V_104 ;
V_8 -> V_86 = F_42 ( V_102 , & V_105 ) ;
if ( F_43 ( V_8 -> V_86 ) ) {
V_23 = F_44 ( V_8 -> V_86 ) ;
F_35 ( & V_102 -> V_2 , L_6 ,
V_23 ) ;
return V_23 ;
}
F_45 ( V_102 , V_8 ) ;
V_23 = F_46 ( & V_102 -> V_2 ,
& V_106 , & V_107 , 1 ) ;
if ( V_23 != 0 ) {
F_35 ( & V_102 -> V_2 , L_7 , V_23 ) ;
return V_23 ;
}
return 0 ;
}
static int F_47 ( struct V_101 * V_102 )
{
F_48 ( & V_102 -> V_2 ) ;
return 0 ;
}
static int F_49 ( struct V_108 * V_109 ,
const struct V_110 * V_111 )
{
struct V_7 * V_8 ;
int V_23 ;
V_8 = F_41 ( & V_109 -> V_2 , sizeof( struct V_7 ) ,
V_103 ) ;
if ( V_8 == NULL )
return - V_104 ;
V_8 -> V_86 = F_50 ( V_109 , & V_105 ) ;
if ( F_43 ( V_8 -> V_86 ) ) {
V_23 = F_44 ( V_8 -> V_86 ) ;
F_35 ( & V_109 -> V_2 , L_6 ,
V_23 ) ;
return V_23 ;
}
F_51 ( V_109 , V_8 ) ;
V_23 = F_46 ( & V_109 -> V_2 ,
& V_106 , & V_107 , 1 ) ;
if ( V_23 != 0 ) {
F_35 ( & V_109 -> V_2 , L_7 , V_23 ) ;
return V_23 ;
}
return 0 ;
}
static int F_52 ( struct V_108 * V_112 )
{
F_48 ( & V_112 -> V_2 ) ;
return 0 ;
}
static int T_2 F_53 ( void )
{
int V_23 = 0 ;
#if F_54 ( V_113 )
V_23 = F_55 ( & V_114 ) ;
if ( V_23 != 0 ) {
F_56 ( V_115 L_8 ,
V_23 ) ;
}
#endif
#if F_57 ( V_116 )
V_23 = F_58 ( & V_117 ) ;
if ( V_23 != 0 ) {
F_56 ( V_115 L_9 ,
V_23 ) ;
}
#endif
return V_23 ;
}
static void T_3 F_59 ( void )
{
#if F_54 ( V_113 )
F_60 ( & V_114 ) ;
#endif
#if F_57 ( V_116 )
F_61 ( & V_117 ) ;
#endif
}
