void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
T_1 V_6 ;
F_2 ( & V_2 -> V_7 ) ;
V_6 = F_3 ( & V_2 -> clock , V_3 ) ;
F_4 ( & V_2 -> V_7 ) ;
V_5 -> V_8 = F_5 ( V_6 ) ;
}
static T_1 F_6 ( const struct V_9 * V_10 )
{
struct V_1 * V_2 = F_7 ( V_10 , struct V_1 ,
V_11 ) ;
return F_8 ( V_2 -> V_12 ) & V_10 -> V_13 ;
}
static void F_9 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = F_10 ( V_15 ) ;
struct V_1 * V_2 = F_7 ( V_17 , struct V_1 ,
V_18 ) ;
unsigned long V_19 ;
F_11 ( & V_2 -> V_7 , V_19 ) ;
F_12 ( & V_2 -> clock ) ;
F_13 ( & V_2 -> V_7 , V_19 ) ;
F_14 ( & V_2 -> V_18 , V_2 -> V_20 ) ;
}
int F_15 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
struct V_25 * V_26 = F_16 ( V_22 ) ;
struct V_27 V_28 ;
int V_29 ;
if ( ! F_17 ( V_26 -> V_12 , V_30 ) )
return - V_31 ;
if ( F_18 ( & V_28 , V_24 -> V_32 , sizeof( V_28 ) ) )
return - V_33 ;
switch ( V_28 . V_34 ) {
case V_35 :
case V_36 :
break;
default:
return - V_37 ;
}
F_19 ( & V_26 -> V_38 ) ;
switch ( V_28 . V_39 ) {
case V_40 :
F_20 ( V_26 , V_26 -> V_41 . V_42 . V_43 ) ;
break;
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
F_21 ( V_22 , L_1 ) ;
V_29 = F_20 ( V_26 , false ) ;
if ( V_29 ) {
F_22 ( V_22 , L_2 , V_29 ) ;
F_23 ( & V_26 -> V_38 ) ;
return V_29 ;
}
V_28 . V_39 = V_44 ;
break;
default:
F_23 ( & V_26 -> V_38 ) ;
return - V_37 ;
}
memcpy ( & V_26 -> V_2 . V_27 , & V_28 , sizeof( V_28 ) ) ;
F_23 ( & V_26 -> V_38 ) ;
return F_24 ( V_24 -> V_32 , & V_28 ,
sizeof( V_28 ) ) ? - V_33 : 0 ;
}
int F_25 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
struct V_25 * V_26 = F_16 ( V_22 ) ;
struct V_27 * V_58 = & V_26 -> V_2 . V_27 ;
if ( ! F_17 ( V_26 -> V_12 , V_30 ) )
return - V_31 ;
return F_24 ( V_24 -> V_32 , V_58 , sizeof( * V_58 ) ) ? - V_33 : 0 ;
}
static int F_26 ( struct V_59 * V_60 ,
const struct V_61 * V_62 )
{
struct V_1 * V_2 = F_7 ( V_60 , struct V_1 ,
V_63 ) ;
T_1 V_64 = F_27 ( V_62 ) ;
unsigned long V_19 ;
F_11 ( & V_2 -> V_7 , V_19 ) ;
F_28 ( & V_2 -> clock , & V_2 -> V_11 , V_64 ) ;
F_13 ( & V_2 -> V_7 , V_19 ) ;
return 0 ;
}
static int F_29 ( struct V_59 * V_60 ,
struct V_61 * V_62 )
{
struct V_1 * V_2 = F_7 ( V_60 , struct V_1 ,
V_63 ) ;
T_1 V_64 ;
unsigned long V_19 ;
F_11 ( & V_2 -> V_7 , V_19 ) ;
V_64 = F_12 ( & V_2 -> clock ) ;
F_13 ( & V_2 -> V_7 , V_19 ) ;
* V_62 = F_30 ( V_64 ) ;
return 0 ;
}
static int F_31 ( struct V_59 * V_60 , T_2 V_65 )
{
struct V_1 * V_2 = F_7 ( V_60 , struct V_1 ,
V_63 ) ;
unsigned long V_19 ;
F_11 ( & V_2 -> V_7 , V_19 ) ;
F_32 ( & V_2 -> clock , V_65 ) ;
F_13 ( & V_2 -> V_7 , V_19 ) ;
return 0 ;
}
static int F_33 ( struct V_59 * V_60 , T_3 V_65 )
{
T_1 V_66 ;
T_4 V_67 ;
unsigned long V_19 ;
int V_68 = 0 ;
struct V_1 * V_2 = F_7 ( V_60 , struct V_1 ,
V_63 ) ;
struct V_25 * V_26 =
F_7 ( V_2 , struct V_25 , V_2 ) ;
if ( F_17 ( V_26 -> V_12 , V_69 ) ) {
T_4 V_70 [ F_34 ( V_71 ) ] = { 0 } ;
F_35 ( V_71 , V_70 , V_72 , V_73 ) ;
F_35 ( V_71 , V_70 , V_74 , V_65 & 0xFFFF ) ;
F_36 ( V_26 -> V_12 , V_70 , sizeof( V_70 ) ) ;
}
if ( V_65 < 0 ) {
V_68 = 1 ;
V_65 = - V_65 ;
}
V_66 = V_2 -> V_75 ;
V_66 *= V_65 ;
V_67 = F_37 ( V_66 , 1000000000ULL ) ;
F_11 ( & V_2 -> V_7 , V_19 ) ;
F_12 ( & V_2 -> clock ) ;
V_2 -> V_11 . V_76 = V_68 ? V_2 -> V_75 - V_67 :
V_2 -> V_75 + V_67 ;
F_13 ( & V_2 -> V_7 , V_19 ) ;
return 0 ;
}
static int F_38 ( struct V_59 * V_60 ,
struct V_77 * V_78 ,
int V_79 )
{
struct V_1 * V_2 =
F_7 ( V_60 , struct V_1 , V_63 ) ;
struct V_25 * V_26 =
F_7 ( V_2 , struct V_25 , V_2 ) ;
T_4 V_70 [ F_34 ( V_71 ) ] = { 0 } ;
T_5 V_80 = 0 ;
int V_81 = - 1 ;
int V_29 = 0 ;
if ( ! F_17 ( V_26 -> V_12 , V_82 ) ||
! F_17 ( V_26 -> V_12 , V_69 ) )
return - V_31 ;
if ( V_78 -> V_83 . V_84 >= V_2 -> V_63 . V_85 )
return - V_86 ;
if ( V_79 ) {
V_81 = F_39 ( V_2 -> V_60 , V_87 , V_78 -> V_83 . V_84 ) ;
if ( V_81 < 0 )
return - V_88 ;
}
if ( V_78 -> V_83 . V_19 & V_89 )
V_80 = 1 ;
F_35 ( V_71 , V_70 , V_81 , V_81 ) ;
F_35 ( V_71 , V_70 , V_72 , V_90 ) ;
F_35 ( V_71 , V_70 , V_80 , V_80 ) ;
F_35 ( V_71 , V_70 , V_91 , V_79 ) ;
V_29 = F_36 ( V_26 -> V_12 , V_70 , sizeof( V_70 ) ) ;
if ( V_29 )
return V_29 ;
return F_40 ( V_26 -> V_12 , V_81 , 0 ,
V_92 & V_79 ) ;
}
static int F_41 ( struct V_59 * V_60 ,
struct V_77 * V_78 ,
int V_79 )
{
struct V_1 * V_2 =
F_7 ( V_60 , struct V_1 , V_63 ) ;
struct V_25 * V_26 =
F_7 ( V_2 , struct V_25 , V_2 ) ;
T_4 V_70 [ F_34 ( V_71 ) ] = { 0 } ;
T_1 V_93 , V_94 , V_95 ;
T_1 V_96 , V_97 ;
struct V_61 V_62 ;
unsigned long V_19 ;
int V_81 = - 1 ;
T_2 V_64 ;
if ( ! F_17 ( V_26 -> V_12 , V_69 ) )
return - V_31 ;
if ( V_78 -> V_98 . V_84 >= V_2 -> V_63 . V_85 )
return - V_86 ;
if ( V_79 ) {
V_81 = F_39 ( V_2 -> V_60 , V_99 ,
V_78 -> V_98 . V_84 ) ;
if ( V_81 < 0 )
return - V_88 ;
}
V_62 . V_100 = V_78 -> V_98 . V_101 . V_102 ;
V_62 . V_103 = V_78 -> V_98 . V_101 . V_6 ;
V_64 = F_27 ( & V_62 ) ;
if ( V_79 )
if ( ( V_64 >> 1 ) != 500000000LL )
return - V_86 ;
V_62 . V_100 = V_78 -> V_98 . V_104 . V_102 ;
V_62 . V_103 = V_78 -> V_98 . V_104 . V_6 ;
V_64 = F_27 ( & V_62 ) ;
V_96 = F_8 ( V_2 -> V_12 ) ;
F_11 ( & V_2 -> V_7 , V_19 ) ;
V_93 = F_3 ( & V_2 -> clock , V_96 ) ;
V_94 = V_64 - V_93 ;
V_97 = F_42 ( V_94 << V_2 -> V_11 . V_105 ,
V_2 -> V_11 . V_76 ) ;
F_13 ( & V_2 -> V_7 , V_19 ) ;
V_95 = V_96 + V_97 ;
F_35 ( V_71 , V_70 , V_81 , V_81 ) ;
F_35 ( V_71 , V_70 , V_72 , V_73 ) ;
F_35 ( V_71 , V_70 , V_80 , V_106 ) ;
F_35 ( V_71 , V_70 , V_91 , V_79 ) ;
F_43 ( V_71 , V_70 , V_95 , V_95 ) ;
return F_36 ( V_26 -> V_12 , V_70 , sizeof( V_70 ) ) ;
}
static int F_44 ( struct V_59 * V_60 ,
struct V_77 * V_78 ,
int V_79 )
{
switch ( V_78 -> type ) {
case V_107 :
return F_38 ( V_60 , V_78 , V_79 ) ;
case V_108 :
return F_41 ( V_60 , V_78 , V_79 ) ;
default:
return - V_31 ;
}
return 0 ;
}
static int F_45 ( struct V_59 * V_60 , unsigned int V_81 ,
enum V_109 V_110 , unsigned int V_111 )
{
return ( V_110 == V_112 ) ? - V_31 : 0 ;
}
static void F_46 ( struct V_1 * V_2 )
{
V_2 -> V_27 . V_34 = V_35 ;
V_2 -> V_27 . V_39 = V_40 ;
}
static int F_47 ( struct V_1 * V_2 )
{
int V_113 ;
V_2 -> V_63 . V_114 =
F_48 ( sizeof( * V_2 -> V_63 . V_114 ) *
V_2 -> V_63 . V_85 , V_115 ) ;
if ( ! V_2 -> V_63 . V_114 )
return - V_116 ;
V_2 -> V_63 . V_91 = F_44 ;
V_2 -> V_63 . V_117 = F_45 ;
for ( V_113 = 0 ; V_113 < V_2 -> V_63 . V_85 ; V_113 ++ ) {
snprintf ( V_2 -> V_63 . V_114 [ V_113 ] . V_118 ,
sizeof( V_2 -> V_63 . V_114 [ V_113 ] . V_118 ) ,
L_3 , V_113 ) ;
V_2 -> V_63 . V_114 [ V_113 ] . V_84 = V_113 ;
V_2 -> V_63 . V_114 [ V_113 ] . V_110 = V_119 ;
V_2 -> V_63 . V_114 [ V_113 ] . V_111 = V_113 ;
}
return 0 ;
}
static void F_49 ( struct V_25 * V_26 ,
struct V_1 * V_2 )
{
T_4 V_120 [ F_34 ( V_71 ) ] = { 0 } ;
F_50 ( V_26 -> V_12 , V_120 , sizeof( V_120 ) ) ;
V_2 -> V_63 . V_85 = F_51 ( V_71 , V_120 ,
V_121 ) ;
V_2 -> V_63 . V_122 = F_51 ( V_71 , V_120 ,
V_123 ) ;
V_2 -> V_63 . V_124 = F_51 ( V_71 , V_120 ,
V_125 ) ;
V_2 -> V_126 [ 0 ] = F_51 ( V_71 , V_120 , V_127 ) ;
V_2 -> V_126 [ 1 ] = F_51 ( V_71 , V_120 , V_128 ) ;
V_2 -> V_126 [ 2 ] = F_51 ( V_71 , V_120 , V_129 ) ;
V_2 -> V_126 [ 3 ] = F_51 ( V_71 , V_120 , V_130 ) ;
V_2 -> V_126 [ 4 ] = F_51 ( V_71 , V_120 , V_131 ) ;
V_2 -> V_126 [ 5 ] = F_51 ( V_71 , V_120 , V_132 ) ;
V_2 -> V_126 [ 6 ] = F_51 ( V_71 , V_120 , V_133 ) ;
V_2 -> V_126 [ 7 ] = F_51 ( V_71 , V_120 , V_134 ) ;
}
void F_52 ( struct V_25 * V_26 ,
struct V_135 * V_136 )
{
struct V_1 * V_2 = & V_26 -> V_2 ;
V_135 ( V_2 -> V_60 , V_136 ) ;
}
void F_53 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = & V_26 -> V_2 ;
T_1 V_64 ;
T_1 V_137 = 0 ;
T_4 V_138 ;
F_46 ( V_2 ) ;
V_138 = F_17 ( V_26 -> V_12 , V_30 ) ;
if ( ! V_138 ) {
F_54 ( V_26 -> V_12 , L_4 ) ;
return;
}
F_55 ( & V_2 -> V_7 ) ;
V_2 -> V_11 . V_139 = F_6 ;
V_2 -> V_11 . V_105 = V_140 ;
V_2 -> V_11 . V_76 = F_56 ( V_138 ,
V_2 -> V_11 . V_105 ) ;
V_2 -> V_75 = V_2 -> V_11 . V_76 ;
V_2 -> V_11 . V_13 = F_57 ( 41 ) ;
V_2 -> V_12 = V_26 -> V_12 ;
F_28 ( & V_2 -> clock , & V_2 -> V_11 ,
F_58 ( F_59 () ) ) ;
V_64 = F_60 ( & V_2 -> V_11 , V_2 -> V_11 . V_13 ,
V_137 , & V_137 ) ;
F_61 ( V_64 , V_141 / 2 / V_142 ) ;
V_2 -> V_20 = V_64 ;
F_62 ( & V_2 -> V_18 , F_9 ) ;
if ( V_2 -> V_20 )
F_14 ( & V_2 -> V_18 , 0 ) ;
else
F_54 ( V_26 -> V_12 , L_5 ) ;
V_2 -> V_63 = V_143 ;
snprintf ( V_2 -> V_63 . V_118 , 16 , L_6 ) ;
#define F_63 8
V_2 -> V_126 = F_48 ( sizeof( T_5 ) * F_63 , V_115 ) ;
if ( V_2 -> V_126 ) {
if ( F_17 ( V_26 -> V_12 , V_82 ) )
F_49 ( V_26 , V_2 ) ;
if ( V_2 -> V_63 . V_85 )
F_47 ( V_2 ) ;
} else {
F_54 ( V_26 -> V_12 , L_7 ) ;
}
V_2 -> V_60 = F_64 ( & V_2 -> V_63 ,
& V_26 -> V_12 -> V_144 -> V_22 ) ;
if ( F_65 ( V_2 -> V_60 ) ) {
F_54 ( V_26 -> V_12 , L_8 ,
F_66 ( V_2 -> V_60 ) ) ;
V_2 -> V_60 = NULL ;
}
}
void F_67 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = & V_26 -> V_2 ;
if ( ! F_17 ( V_26 -> V_12 , V_30 ) )
return;
if ( V_26 -> V_2 . V_60 ) {
F_68 ( V_26 -> V_2 . V_60 ) ;
V_26 -> V_2 . V_60 = NULL ;
}
F_69 ( V_2 -> V_126 ) ;
F_69 ( V_2 -> V_63 . V_114 ) ;
F_70 ( & V_2 -> V_18 ) ;
}
