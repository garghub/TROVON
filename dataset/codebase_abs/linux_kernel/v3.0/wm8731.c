static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 , V_6 , V_7 ;
if ( V_4 -> V_8 ) {
V_7 = 1 ;
for ( V_6 = 2 ; V_6 < F_3 ( V_9 ) ; V_6 ++ ) {
if ( abs ( V_9 [ V_6 ] - V_4 -> V_10 ) <
abs ( V_9 [ V_7 ] - V_4 -> V_10 ) )
V_7 = V_6 ;
}
V_5 = V_7 << 1 ;
} else {
V_7 = 0 ;
V_5 = 0 ;
}
F_4 ( V_2 -> V_11 , L_1 ,
V_7 , V_9 [ V_7 ] ) ;
return F_5 ( V_2 , V_12 , 0x6 , V_5 ) ;
}
static int F_6 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
struct V_1 * V_2 = F_7 ( V_14 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_16 -> V_17 . V_18 . V_19 [ 0 ] = V_4 -> V_8 ;
return 0 ;
}
static int F_8 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
struct V_1 * V_2 = F_7 ( V_14 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_8 = V_16 -> V_17 . V_18 . V_19 [ 0 ] ;
int V_20 = 0 ;
if ( V_8 > 1 )
return - V_21 ;
F_9 ( & V_2 -> V_22 ) ;
if ( V_4 -> V_8 != V_8 ) {
V_4 -> V_8 = V_8 ;
F_1 ( V_2 ) ;
V_20 = 1 ;
}
F_10 ( & V_2 -> V_22 ) ;
return V_20 ;
}
static int F_11 ( struct V_23 * V_24 ,
struct V_23 * V_25 )
{
struct V_3 * V_4 = F_2 ( V_24 -> V_2 ) ;
return V_4 -> V_26 == V_27 ;
}
static inline int F_12 ( int V_28 , int V_29 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < F_3 ( V_30 ) ; V_6 ++ ) {
if ( V_30 [ V_6 ] . V_29 == V_29 && V_30 [ V_6 ] . V_28 == V_28 )
return V_6 ;
}
return 0 ;
}
static int F_13 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_1 * V_2 = V_36 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_37 = F_14 ( V_2 , V_38 ) & 0xfff3 ;
int V_6 = F_12 ( V_4 -> V_39 , F_15 ( V_34 ) ) ;
T_1 V_40 = ( V_30 [ V_6 ] . V_41 << 2 ) |
( V_30 [ V_6 ] . V_42 << 1 ) | V_30 [ V_6 ] . V_43 ;
V_4 -> V_10 = F_15 ( V_34 ) ;
F_16 ( V_2 , V_44 , V_40 ) ;
switch ( F_17 ( V_34 ) ) {
case V_45 :
break;
case V_46 :
V_37 |= 0x0004 ;
break;
case V_47 :
V_37 |= 0x0008 ;
break;
}
F_1 ( V_2 ) ;
F_16 ( V_2 , V_38 , V_37 ) ;
return 0 ;
}
static int F_18 ( struct V_35 * V_36 , int V_48 )
{
struct V_1 * V_2 = V_36 -> V_2 ;
T_1 V_49 = F_14 ( V_2 , V_12 ) & 0xfff7 ;
if ( V_48 )
F_16 ( V_2 , V_12 , V_49 | 0x8 ) ;
else
F_16 ( V_2 , V_12 , V_49 ) ;
return 0 ;
}
static int F_19 ( struct V_35 * V_50 ,
int V_51 , unsigned int V_52 , int V_53 )
{
struct V_1 * V_2 = V_50 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_51 ) {
case V_27 :
case V_54 :
V_4 -> V_26 = V_51 ;
break;
default:
return - V_21 ;
}
switch ( V_52 ) {
case 11289600 :
case 12000000 :
case 12288000 :
case 16934400 :
case 18432000 :
V_4 -> V_39 = V_52 ;
break;
default:
return - V_21 ;
}
F_20 ( & V_2 -> V_55 ) ;
return 0 ;
}
static int F_21 ( struct V_35 * V_50 ,
unsigned int V_56 )
{
struct V_1 * V_2 = V_50 -> V_2 ;
T_1 V_37 = 0 ;
switch ( V_56 & V_57 ) {
case V_58 :
V_37 |= 0x0040 ;
break;
case V_59 :
break;
default:
return - V_21 ;
}
switch ( V_56 & V_60 ) {
case V_61 :
V_37 |= 0x0002 ;
break;
case V_62 :
break;
case V_63 :
V_37 |= 0x0001 ;
break;
case V_64 :
V_37 |= 0x0003 ;
break;
case V_65 :
V_37 |= 0x0013 ;
break;
default:
return - V_21 ;
}
switch ( V_56 & V_66 ) {
case V_67 :
break;
case V_68 :
V_37 |= 0x0090 ;
break;
case V_69 :
V_37 |= 0x0080 ;
break;
case V_70 :
V_37 |= 0x0010 ;
break;
default:
return - V_21 ;
}
F_16 ( V_2 , V_38 , V_37 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
enum V_71 V_72 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_6 , V_20 ;
T_2 V_73 [ 2 ] ;
T_1 * V_74 = V_2 -> V_75 ;
T_1 V_76 ;
switch ( V_72 ) {
case V_77 :
break;
case V_78 :
break;
case V_79 :
if ( V_2 -> V_55 . V_80 == V_81 ) {
V_20 = F_23 ( F_3 ( V_4 -> V_82 ) ,
V_4 -> V_82 ) ;
if ( V_20 != 0 )
return V_20 ;
for ( V_6 = 0 ; V_6 < F_3 ( V_83 ) ; V_6 ++ ) {
if ( V_74 [ V_6 ] == V_83 [ V_6 ] )
continue;
V_73 [ 0 ] = ( V_6 << 1 ) | ( ( V_74 [ V_6 ] >> 8 )
& 0x0001 ) ;
V_73 [ 1 ] = V_74 [ V_6 ] & 0x00ff ;
V_2 -> V_84 ( V_2 -> V_85 , V_73 , 2 ) ;
}
}
V_76 = F_14 ( V_2 , V_86 ) & 0xff7f ;
F_16 ( V_2 , V_86 , V_76 | 0x0040 ) ;
break;
case V_81 :
F_16 ( V_2 , V_86 , 0xffff ) ;
F_24 ( F_3 ( V_4 -> V_82 ) ,
V_4 -> V_82 ) ;
break;
}
V_2 -> V_55 . V_80 = V_72 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , T_3 V_87 )
{
F_22 ( V_2 , V_81 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_79 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_20 = 0 , V_6 ;
V_20 = F_28 ( V_2 , 7 , 9 , V_4 -> V_88 ) ;
if ( V_20 < 0 ) {
F_29 ( V_2 -> V_11 , L_2 , V_20 ) ;
return V_20 ;
}
for ( V_6 = 0 ; V_6 < F_3 ( V_4 -> V_82 ) ; V_6 ++ )
V_4 -> V_82 [ V_6 ] . V_89 = V_90 [ V_6 ] ;
V_20 = F_30 ( V_2 -> V_11 , F_3 ( V_4 -> V_82 ) ,
V_4 -> V_82 ) ;
if ( V_20 != 0 ) {
F_29 ( V_2 -> V_11 , L_3 , V_20 ) ;
return V_20 ;
}
V_20 = F_23 ( F_3 ( V_4 -> V_82 ) ,
V_4 -> V_82 ) ;
if ( V_20 != 0 ) {
F_29 ( V_2 -> V_11 , L_4 , V_20 ) ;
goto V_91;
}
V_20 = F_31 ( V_2 ) ;
if ( V_20 < 0 ) {
F_29 ( V_2 -> V_11 , L_5 , V_20 ) ;
goto V_92;
}
F_22 ( V_2 , V_79 ) ;
F_5 ( V_2 , V_93 , 0x100 , 0 ) ;
F_5 ( V_2 , V_94 , 0x100 , 0 ) ;
F_5 ( V_2 , V_95 , 0x100 , 0 ) ;
F_5 ( V_2 , V_96 , 0x100 , 0 ) ;
F_5 ( V_2 , V_97 , 0x8 , 0 ) ;
F_32 ( V_2 , V_98 ,
F_3 ( V_98 ) ) ;
F_24 ( F_3 ( V_4 -> V_82 ) , V_4 -> V_82 ) ;
return 0 ;
V_92:
F_24 ( F_3 ( V_4 -> V_82 ) , V_4 -> V_82 ) ;
V_91:
F_33 ( F_3 ( V_4 -> V_82 ) , V_4 -> V_82 ) ;
return V_20 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_22 ( V_2 , V_81 ) ;
F_24 ( F_3 ( V_4 -> V_82 ) , V_4 -> V_82 ) ;
F_33 ( F_3 ( V_4 -> V_82 ) , V_4 -> V_82 ) ;
return 0 ;
}
static int T_4 F_35 ( struct V_99 * V_100 )
{
struct V_3 * V_4 ;
int V_20 ;
V_4 = F_36 ( sizeof( struct V_3 ) , V_101 ) ;
if ( V_4 == NULL )
return - V_102 ;
V_4 -> V_88 = V_103 ;
F_37 ( V_100 , V_4 ) ;
V_20 = F_38 ( & V_100 -> V_11 ,
& V_104 , & V_105 , 1 ) ;
if ( V_20 < 0 )
F_39 ( V_4 ) ;
return V_20 ;
}
static int T_5 F_40 ( struct V_99 * V_100 )
{
F_41 ( & V_100 -> V_11 ) ;
F_39 ( F_42 ( V_100 ) ) ;
return 0 ;
}
static T_4 int F_43 ( struct V_106 * V_107 ,
const struct V_108 * V_109 )
{
struct V_3 * V_4 ;
int V_20 ;
V_4 = F_36 ( sizeof( struct V_3 ) , V_101 ) ;
if ( V_4 == NULL )
return - V_102 ;
F_44 ( V_107 , V_4 ) ;
V_4 -> V_88 = V_110 ;
V_20 = F_38 ( & V_107 -> V_11 ,
& V_104 , & V_105 , 1 ) ;
if ( V_20 < 0 )
F_39 ( V_4 ) ;
return V_20 ;
}
static T_5 int F_45 ( struct V_106 * V_111 )
{
F_41 ( & V_111 -> V_11 ) ;
F_39 ( F_46 ( V_111 ) ) ;
return 0 ;
}
static int T_6 F_47 ( void )
{
int V_20 = 0 ;
#if F_48 ( V_112 ) || F_48 ( V_113 )
V_20 = F_49 ( & V_114 ) ;
if ( V_20 != 0 ) {
F_50 ( V_115 L_6 ,
V_20 ) ;
}
#endif
#if F_48 ( V_116 )
V_20 = F_51 ( & V_117 ) ;
if ( V_20 != 0 ) {
F_50 ( V_115 L_7 ,
V_20 ) ;
}
#endif
return V_20 ;
}
static void T_7 F_52 ( void )
{
#if F_48 ( V_112 ) || F_48 ( V_113 )
F_53 ( & V_114 ) ;
#endif
#if F_48 ( V_116 )
F_54 ( & V_117 ) ;
#endif
}
