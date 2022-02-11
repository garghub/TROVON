static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
return true ;
default:
return false ;
}
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_6 ... V_7 :
case V_8 ... V_9 :
return true ;
default:
return false ;
}
}
static int F_3 ( struct V_10 * V_11 ,
struct V_12 * V_13 , int V_14 )
{
struct V_15 * V_16 = F_4 ( V_11 -> V_17 ) ;
struct V_18 * V_19 = F_5 ( V_16 ) ;
switch ( V_14 ) {
case V_20 :
V_19 -> V_21 = 150 ;
break;
default:
F_6 ( L_1 , V_14 ) ;
}
return 0 ;
}
static int F_7 ( struct V_10 * V_11 ,
struct V_12 * V_13 , int V_14 )
{
struct V_15 * V_16 = F_4 ( V_11 -> V_17 ) ;
struct V_18 * V_19 = F_5 ( V_16 ) ;
switch ( V_14 ) {
case V_20 :
if ( V_19 -> V_21 < 50 )
V_19 -> V_21 = 50 ;
break;
default:
F_6 ( L_1 , V_14 ) ;
}
return 0 ;
}
static int F_8 ( struct V_10 * V_11 ,
struct V_12 * V_13 , int V_14 )
{
struct V_15 * V_16 = F_4 ( V_11 -> V_17 ) ;
struct V_18 * V_19 = F_5 ( V_16 ) ;
switch ( V_14 ) {
case V_20 :
if ( V_19 -> V_21 < 30 )
V_19 -> V_21 = 30 ;
break;
default:
F_6 ( L_1 , V_14 ) ;
}
return 0 ;
}
static int F_9 ( int V_22 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < F_10 ( V_24 ) ; V_23 ++ ) {
if ( V_24 [ V_23 ] . V_22 == V_22 )
return V_23 ;
}
return - V_25 ;
}
static int F_11 ( int V_26 , int V_27 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < F_10 ( V_28 ) ; V_23 ++ ) {
if ( V_28 [ V_23 ] . V_26 == V_26 &&
V_28 [ V_23 ] . V_27 == V_27 )
return V_23 ;
}
return - V_25 ;
}
static int F_12 ( struct V_29 * V_30 , unsigned int V_31 )
{
struct V_15 * V_16 = V_30 -> V_16 ;
struct V_18 * V_19 = F_5 ( V_16 ) ;
int V_32 ;
T_1 V_26 = 0 ;
T_2 V_33 = 0 ;
V_32 = F_9 ( V_31 ) ;
if ( V_32 < 0 )
return V_32 ;
V_26 = V_24 [ V_32 ] . V_22 /
V_24 [ V_32 ] . V_34 ;
F_13 ( V_16 -> V_2 , L_2 ,
V_19 -> V_35 + 1 , V_24 [ V_32 ] . V_22 ,
V_26 ) ;
V_33 = ( V_19 -> V_35 << 4 ) |
( V_24 [ V_32 ] . V_36 << 1 ) ;
F_14 ( V_16 , V_37 , V_33 ) ;
V_19 -> V_38 = V_32 ;
V_19 -> V_26 = V_26 ;
return 0 ;
}
static int F_15 ( struct V_29 * V_30 ,
int V_39 , unsigned int V_31 , int V_40 )
{
struct V_15 * V_16 = V_30 -> V_16 ;
struct V_18 * V_19 = F_5 ( V_16 ) ;
switch ( V_39 ) {
case V_41 :
break;
case V_42 :
break;
default:
return - V_25 ;
}
if ( ( F_12 ( V_30 , V_31 ) ) < 0 ) {
F_16 ( V_16 -> V_2 , L_3 ,
V_30 -> V_43 ) ;
return - V_25 ;
}
V_19 -> V_35 = V_39 ;
return 0 ;
}
static int F_17 ( struct V_29 * V_44 , unsigned int V_45 )
{
struct V_15 * V_16 = V_44 -> V_16 ;
struct V_18 * V_19 = F_5 ( V_16 ) ;
T_2 V_46 = V_44 -> V_46 ;
unsigned int V_47 , V_48 ;
T_2 V_49 , V_50 ;
V_49 = F_18 ( V_16 , F_19 ( V_46 ) ) ;
V_50 = F_18 ( V_16 , F_20 ( V_46 ) ) ;
switch ( V_45 & V_51 ) {
case V_52 :
V_50 |= V_53 ;
break;
case V_54 :
V_50 &= ~ V_53 ;
break;
default:
return - V_25 ;
}
V_48 = ( V_45 & V_55 ) ;
V_47 = ( V_45 & V_56 ) ;
switch ( V_48 ) {
case V_57 :
V_49 &= ~ V_58 ;
break;
case V_59 :
case V_60 :
if ( V_50 & V_53 ) {
F_16 ( V_16 -> V_2 ,
L_4 ) ;
return - V_25 ;
}
if ( V_46 == V_61 ) {
F_16 ( V_16 -> V_2 ,
L_5 ) ;
return - V_25 ;
}
V_49 |= V_58 ;
break;
default:
return - V_25 ;
}
if ( V_49 & V_58 ) {
V_49 &= ~ ( V_62 | V_63 ) ;
switch ( V_48 ) {
case V_60 :
if ( V_47 == V_64 )
V_49 |= V_65 ;
if ( V_47 == V_66 )
V_49 |= V_67 ;
break;
case V_59 :
if ( V_47 == V_64 )
V_49 |= V_67 ;
break;
default:
return - V_25 ;
}
}
V_19 -> V_68 [ V_46 ] . V_49 = V_49 ;
V_19 -> V_68 [ V_46 ] . V_50 = V_50 ;
return 0 ;
}
static unsigned int F_21 ( T_1 V_69 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < F_10 ( V_70 ) ; V_23 ++ ) {
if ( V_70 [ V_23 ] == V_69 )
return V_23 + 1 ;
}
return 0 ;
}
static void F_22 ( struct V_15 * V_16 , int V_46 , int V_27 )
{
T_2 V_71 = 0 ;
if ( V_27 > 0 )
V_71 = F_21 ( V_27 ) ;
switch ( V_46 ) {
case V_72 :
F_23 ( V_16 , V_73 , 0x0f , V_71 ) ;
break;
case V_61 :
F_23 ( V_16 , V_74 , 0x3c , V_71 << 2 ) ;
break;
case V_75 :
F_23 ( V_16 , V_73 , 0xf0 , V_71 << 4 ) ;
break;
default:
break;
}
}
static int F_24 ( struct V_76 * V_77 ,
struct V_78 * V_79 ,
struct V_29 * V_30 )
{
struct V_15 * V_16 = V_30 -> V_16 ;
struct V_18 * V_19 = F_5 ( V_16 ) ;
int V_46 = V_30 -> V_46 ;
int V_80 ;
int V_27 = F_25 ( V_79 ) ;
if ( V_19 -> V_68 [ V_46 ] . V_50 & V_53 ) {
V_80 =
F_11 ( V_19 -> V_26 , V_27 ) ;
if ( V_80 < 0 )
return - V_25 ;
F_13 ( V_16 -> V_2 ,
L_6 ,
V_46 , V_19 -> V_26 , V_27 ,
V_28 [ V_80 ] . V_50 ) ;
V_19 -> V_68 [ V_46 ] . V_50 &= 0xC0 ;
V_19 -> V_68 [ V_46 ] . V_50 |= V_28 [ V_80 ] . V_50 ;
V_19 -> V_68 [ V_46 ] . V_49 &= 0xFC ;
if ( V_19 -> V_26 >= 6400000 )
V_19 -> V_68 [ V_46 ] . V_49 |= V_81 ;
else
V_19 -> V_68 [ V_46 ] . V_49 |= V_82 ;
} else {
V_19 -> V_68 [ V_46 ] . V_49 &= 0xFC ;
V_19 -> V_68 [ V_46 ] . V_49 |= V_81 ;
}
V_19 -> V_68 [ V_46 ] . V_27 = V_27 ;
F_14 ( V_16 , F_19 ( V_46 ) , V_19 -> V_68 [ V_46 ] . V_49 ) ;
F_14 ( V_16 , F_20 ( V_46 ) , V_19 -> V_68 [ V_46 ] . V_50 ) ;
F_22 ( V_16 , V_46 , V_27 ) ;
return 0 ;
}
static int F_26 ( struct V_15 * V_16 ,
enum V_83 V_84 )
{
struct V_18 * V_85 = F_5 ( V_16 ) ;
switch ( V_84 ) {
case V_86 :
F_23 ( V_16 , V_37 , V_87 , 0 ) ;
F_23 ( V_16 , V_88 , V_89 , 0 ) ;
break;
case V_90 :
break;
case V_91 :
if ( F_27 ( V_16 ) == V_92 ) {
F_28 ( V_85 -> V_93 , false ) ;
F_29 ( V_85 -> V_93 ) ;
}
F_23 ( V_16 , V_88 , V_89 , 1 ) ;
break;
case V_92 :
F_23 ( V_16 , V_88 , V_89 , 1 ) ;
if ( V_85 -> V_21 > 0 ) {
F_30 ( V_85 -> V_21 ) ;
V_85 -> V_21 = 0 ;
} else {
F_30 ( 15 ) ;
}
F_23 ( V_16 , V_37 , V_87 , 1 ) ;
break;
}
return 0 ;
}
static int F_31 ( struct V_29 * V_30 , int V_94 )
{
struct V_15 * V_16 = V_30 -> V_16 ;
int V_46 = V_30 -> V_46 ;
return F_23 ( V_16 , F_19 ( V_46 ) , V_95 ,
V_94 << 7 ) ;
}
static int F_32 ( struct V_76 * V_77 ,
struct V_29 * V_30 )
{
F_33 ( V_77 -> V_96 , 0 ,
V_97 ,
& V_98 ) ;
return 0 ;
}
static int F_34 ( struct V_15 * V_16 )
{
struct V_18 * V_85 = F_5 ( V_16 ) ;
if ( V_85 -> V_99 . V_100 )
F_23 ( V_16 , V_101 ,
V_102 ,
V_85 -> V_99 . V_100 << 4 ) ;
V_85 -> V_35 = V_41 ;
V_85 -> V_26 = 0 ;
return 0 ;
}
static int F_35 ( struct V_103 * V_103 ,
const struct V_104 * V_46 )
{
struct V_18 * V_85 ;
struct V_105 * V_99 = F_36 ( & V_103 -> V_2 ) ;
int V_106 ;
unsigned int V_107 = 0 ;
unsigned int V_3 ;
T_1 V_108 ;
V_85 = F_37 ( & V_103 -> V_2 , sizeof( struct V_18 ) ,
V_109 ) ;
if ( ! V_85 )
return - V_110 ;
V_85 -> V_93 = F_38 ( V_103 , & V_111 ) ;
if ( F_39 ( V_85 -> V_93 ) ) {
V_106 = F_40 ( V_85 -> V_93 ) ;
F_16 ( & V_103 -> V_2 , L_7 , V_106 ) ;
return V_106 ;
}
if ( V_99 ) {
V_85 -> V_99 = * V_99 ;
} else {
V_99 = F_37 ( & V_103 -> V_2 ,
sizeof( struct V_105 ) ,
V_109 ) ;
if ( ! V_99 ) {
F_16 ( & V_103 -> V_2 , L_8 ) ;
return - V_110 ;
}
if ( V_103 -> V_2 . V_112 ) {
if ( F_41 ( V_103 -> V_2 . V_112 ,
L_9 , & V_108 ) >= 0 )
V_99 -> V_100 = V_108 ;
}
V_99 -> V_113 = F_42 ( V_103 -> V_2 . V_112 ,
L_10 , 0 ) ;
V_85 -> V_99 = * V_99 ;
}
F_43 ( V_103 , V_85 ) ;
if ( V_85 -> V_99 . V_113 ) {
V_106 = F_44 ( & V_103 -> V_2 ,
V_85 -> V_99 . V_113 ,
V_114 ,
L_11 ) ;
if ( V_106 < 0 ) {
F_16 ( & V_103 -> V_2 , L_12 ,
V_85 -> V_99 . V_113 , V_106 ) ;
return V_106 ;
}
F_45 ( V_85 -> V_99 . V_113 , 0 ) ;
F_45 ( V_85 -> V_99 . V_113 , 1 ) ;
}
F_46 ( V_85 -> V_93 , true ) ;
V_106 = F_47 ( V_85 -> V_93 , V_6 , & V_3 ) ;
V_107 = ( V_3 & 0xFF ) << 12 ;
V_106 = F_47 ( V_85 -> V_93 , V_115 , & V_3 ) ;
V_107 |= ( V_3 & 0xFF ) << 4 ;
V_106 = F_47 ( V_85 -> V_93 , V_7 , & V_3 ) ;
V_107 |= ( V_3 & 0xF0 ) >> 4 ;
if ( V_107 != V_116 ) {
V_106 = - V_117 ;
F_16 ( & V_103 -> V_2 ,
L_13 ,
V_107 , V_116 ) ;
return V_106 ;
}
V_106 = F_47 ( V_85 -> V_93 , V_8 , & V_3 ) ;
if ( V_106 < 0 ) {
F_16 ( & V_103 -> V_2 , L_14 ) ;
return V_106 ; ;
}
F_48 ( & V_103 -> V_2 ,
L_15 , V_3 & 0xFF ) ;
F_46 ( V_85 -> V_93 , false ) ;
V_106 = F_49 ( & V_103 -> V_2 ,
& V_118 , V_119 ,
F_10 ( V_119 ) ) ;
if ( V_106 < 0 )
return V_106 ;
return 0 ;
}
static int F_50 ( struct V_103 * V_120 )
{
F_51 ( & V_120 -> V_2 ) ;
return 0 ;
}
