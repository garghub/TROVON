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
case 11289600 :
case 12000000 :
case 12288000 :
case 16934400 :
case 18432000 :
V_8 -> V_42 = V_55 ;
break;
default:
return - V_24 ;
}
F_22 ( & V_6 -> V_58 ) ;
return 0 ;
}
static int F_23 ( struct V_38 * V_53 ,
unsigned int V_59 )
{
struct V_5 * V_6 = V_53 -> V_6 ;
T_1 V_40 = 0 ;
switch ( V_59 & V_60 ) {
case V_61 :
V_40 |= 0x0040 ;
break;
case V_62 :
break;
default:
return - V_24 ;
}
switch ( V_59 & V_63 ) {
case V_64 :
V_40 |= 0x0002 ;
break;
case V_65 :
break;
case V_66 :
V_40 |= 0x0001 ;
break;
case V_67 :
V_40 |= 0x0003 ;
break;
case V_68 :
V_40 |= 0x0013 ;
break;
default:
return - V_24 ;
}
switch ( V_59 & V_69 ) {
case V_70 :
break;
case V_71 :
V_40 |= 0x0090 ;
break;
case V_72 :
V_40 |= 0x0080 ;
break;
case V_73 :
V_40 |= 0x0010 ;
break;
default:
return - V_24 ;
}
F_18 ( V_6 , V_41 , V_40 ) ;
return 0 ;
}
static int F_24 ( struct V_5 * V_6 ,
enum V_74 V_75 )
{
struct V_7 * V_8 = F_4 ( V_6 ) ;
int V_23 ;
T_1 V_3 ;
switch ( V_75 ) {
case V_76 :
break;
case V_77 :
break;
case V_78 :
if ( V_6 -> V_58 . V_79 == V_80 ) {
V_23 = F_25 ( F_5 ( V_8 -> V_81 ) ,
V_8 -> V_81 ) ;
if ( V_23 != 0 )
return V_23 ;
F_26 ( V_8 -> V_82 ) ;
}
V_3 = F_16 ( V_6 , V_83 ) & 0xff7f ;
F_18 ( V_6 , V_83 , V_3 | 0x0040 ) ;
break;
case V_80 :
F_18 ( V_6 , V_83 , 0xffff ) ;
F_27 ( F_5 ( V_8 -> V_81 ) ,
V_8 -> V_81 ) ;
F_28 ( V_8 -> V_82 ) ;
break;
}
V_6 -> V_58 . V_79 = V_75 ;
return 0 ;
}
static int F_29 ( struct V_5 * V_6 )
{
F_24 ( V_6 , V_80 ) ;
return 0 ;
}
static int F_30 ( struct V_5 * V_6 )
{
F_24 ( V_6 , V_78 ) ;
return 0 ;
}
static int F_31 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_4 ( V_6 ) ;
int V_23 = 0 , V_10 ;
V_6 -> V_84 = V_8 -> V_82 ;
V_23 = F_32 ( V_6 , 7 , 9 , V_85 ) ;
if ( V_23 < 0 ) {
F_33 ( V_6 -> V_2 , L_2 , V_23 ) ;
return V_23 ;
}
for ( V_10 = 0 ; V_10 < F_5 ( V_8 -> V_81 ) ; V_10 ++ )
V_8 -> V_81 [ V_10 ] . V_86 = V_87 [ V_10 ] ;
V_23 = F_34 ( V_6 -> V_2 , F_5 ( V_8 -> V_81 ) ,
V_8 -> V_81 ) ;
if ( V_23 != 0 ) {
F_33 ( V_6 -> V_2 , L_3 , V_23 ) ;
return V_23 ;
}
V_23 = F_25 ( F_5 ( V_8 -> V_81 ) ,
V_8 -> V_81 ) ;
if ( V_23 != 0 ) {
F_33 ( V_6 -> V_2 , L_4 , V_23 ) ;
goto V_88;
}
V_23 = F_35 ( V_6 ) ;
if ( V_23 < 0 ) {
F_33 ( V_6 -> V_2 , L_5 , V_23 ) ;
goto V_89;
}
F_24 ( V_6 , V_78 ) ;
F_7 ( V_6 , V_90 , 0x100 , 0 ) ;
F_7 ( V_6 , V_91 , 0x100 , 0 ) ;
F_7 ( V_6 , V_92 , 0x100 , 0 ) ;
F_7 ( V_6 , V_93 , 0x100 , 0 ) ;
F_7 ( V_6 , V_94 , 0x8 , 0 ) ;
F_27 ( F_5 ( V_8 -> V_81 ) , V_8 -> V_81 ) ;
return 0 ;
V_89:
F_27 ( F_5 ( V_8 -> V_81 ) , V_8 -> V_81 ) ;
V_88:
F_36 ( F_5 ( V_8 -> V_81 ) , V_8 -> V_81 ) ;
return V_23 ;
}
static int F_37 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_4 ( V_6 ) ;
F_24 ( V_6 , V_80 ) ;
F_27 ( F_5 ( V_8 -> V_81 ) , V_8 -> V_81 ) ;
F_36 ( F_5 ( V_8 -> V_81 ) , V_8 -> V_81 ) ;
return 0 ;
}
static int F_38 ( struct V_95 * V_96 )
{
struct V_7 * V_8 ;
int V_23 ;
V_8 = F_39 ( & V_96 -> V_2 , sizeof( struct V_7 ) ,
V_97 ) ;
if ( V_8 == NULL )
return - V_98 ;
V_8 -> V_82 = F_40 ( V_96 , & V_99 ) ;
if ( F_41 ( V_8 -> V_82 ) ) {
V_23 = F_42 ( V_8 -> V_82 ) ;
F_33 ( & V_96 -> V_2 , L_6 ,
V_23 ) ;
return V_23 ;
}
F_43 ( V_96 , V_8 ) ;
V_23 = F_44 ( & V_96 -> V_2 ,
& V_100 , & V_101 , 1 ) ;
if ( V_23 != 0 ) {
F_33 ( & V_96 -> V_2 , L_7 , V_23 ) ;
return V_23 ;
}
return 0 ;
}
static int F_45 ( struct V_95 * V_96 )
{
F_46 ( & V_96 -> V_2 ) ;
return 0 ;
}
static int F_47 ( struct V_102 * V_103 ,
const struct V_104 * V_105 )
{
struct V_7 * V_8 ;
int V_23 ;
V_8 = F_39 ( & V_103 -> V_2 , sizeof( struct V_7 ) ,
V_97 ) ;
if ( V_8 == NULL )
return - V_98 ;
V_8 -> V_82 = F_48 ( V_103 , & V_99 ) ;
if ( F_41 ( V_8 -> V_82 ) ) {
V_23 = F_42 ( V_8 -> V_82 ) ;
F_33 ( & V_103 -> V_2 , L_6 ,
V_23 ) ;
return V_23 ;
}
F_49 ( V_103 , V_8 ) ;
V_23 = F_44 ( & V_103 -> V_2 ,
& V_100 , & V_101 , 1 ) ;
if ( V_23 != 0 ) {
F_33 ( & V_103 -> V_2 , L_7 , V_23 ) ;
return V_23 ;
}
return 0 ;
}
static int F_50 ( struct V_102 * V_106 )
{
F_46 ( & V_106 -> V_2 ) ;
return 0 ;
}
static int T_2 F_51 ( void )
{
int V_23 = 0 ;
#if F_52 ( V_107 ) || F_52 ( V_108 )
V_23 = F_53 ( & V_109 ) ;
if ( V_23 != 0 ) {
F_54 ( V_110 L_8 ,
V_23 ) ;
}
#endif
#if F_52 ( V_111 )
V_23 = F_55 ( & V_112 ) ;
if ( V_23 != 0 ) {
F_54 ( V_110 L_9 ,
V_23 ) ;
}
#endif
return V_23 ;
}
static void T_3 F_56 ( void )
{
#if F_52 ( V_107 ) || F_52 ( V_108 )
F_57 ( & V_109 ) ;
#endif
#if F_52 ( V_111 )
F_58 ( & V_112 ) ;
#endif
}
