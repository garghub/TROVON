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
if ( ! F_17 ( V_26 -> V_12 , V_29 ) )
return - V_30 ;
if ( F_18 ( & V_28 , V_24 -> V_31 , sizeof( V_28 ) ) )
return - V_32 ;
switch ( V_28 . V_33 ) {
case V_34 :
case V_35 :
break;
default:
return - V_36 ;
}
F_19 ( & V_26 -> V_37 ) ;
switch ( V_28 . V_38 ) {
case V_39 :
F_20 ( V_26 , V_26 -> V_40 . V_41 ) ;
break;
case V_42 :
case V_43 :
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
F_21 ( V_22 , L_1 ) ;
F_20 ( V_26 , false ) ;
V_28 . V_38 = V_42 ;
break;
default:
F_22 ( & V_26 -> V_37 ) ;
return - V_36 ;
}
memcpy ( & V_26 -> V_2 . V_27 , & V_28 , sizeof( V_28 ) ) ;
F_22 ( & V_26 -> V_37 ) ;
return F_23 ( V_24 -> V_31 , & V_28 ,
sizeof( V_28 ) ) ? - V_32 : 0 ;
}
int F_24 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
struct V_25 * V_26 = F_16 ( V_22 ) ;
struct V_27 * V_56 = & V_26 -> V_2 . V_27 ;
if ( ! F_17 ( V_26 -> V_12 , V_29 ) )
return - V_30 ;
return F_23 ( V_24 -> V_31 , V_56 , sizeof( * V_56 ) ) ? - V_32 : 0 ;
}
static int F_25 ( struct V_57 * V_58 ,
const struct V_59 * V_60 )
{
struct V_1 * V_2 = F_7 ( V_58 , struct V_1 ,
V_61 ) ;
T_1 V_62 = F_26 ( V_60 ) ;
unsigned long V_19 ;
F_11 ( & V_2 -> V_7 , V_19 ) ;
F_27 ( & V_2 -> clock , & V_2 -> V_11 , V_62 ) ;
F_13 ( & V_2 -> V_7 , V_19 ) ;
return 0 ;
}
static int F_28 ( struct V_57 * V_58 ,
struct V_59 * V_60 )
{
struct V_1 * V_2 = F_7 ( V_58 , struct V_1 ,
V_61 ) ;
T_1 V_62 ;
unsigned long V_19 ;
F_11 ( & V_2 -> V_7 , V_19 ) ;
V_62 = F_12 ( & V_2 -> clock ) ;
F_13 ( & V_2 -> V_7 , V_19 ) ;
* V_60 = F_29 ( V_62 ) ;
return 0 ;
}
static int F_30 ( struct V_57 * V_58 , T_2 V_63 )
{
struct V_1 * V_2 = F_7 ( V_58 , struct V_1 ,
V_61 ) ;
unsigned long V_19 ;
F_11 ( & V_2 -> V_7 , V_19 ) ;
F_31 ( & V_2 -> clock , V_63 ) ;
F_13 ( & V_2 -> V_7 , V_19 ) ;
return 0 ;
}
static int F_32 ( struct V_57 * V_58 , T_3 V_63 )
{
T_1 V_64 ;
T_4 V_65 ;
unsigned long V_19 ;
int V_66 = 0 ;
struct V_1 * V_2 = F_7 ( V_58 , struct V_1 ,
V_61 ) ;
struct V_25 * V_26 =
F_7 ( V_2 , struct V_25 , V_2 ) ;
if ( F_17 ( V_26 -> V_12 , V_67 ) ) {
T_4 V_68 [ F_33 ( V_69 ) ] = { 0 } ;
F_34 ( V_69 , V_68 , V_70 , V_71 ) ;
F_34 ( V_69 , V_68 , V_72 , V_63 & 0xFFFF ) ;
F_35 ( V_26 -> V_12 , V_68 , sizeof( V_68 ) ) ;
}
if ( V_63 < 0 ) {
V_66 = 1 ;
V_63 = - V_63 ;
}
V_64 = V_2 -> V_73 ;
V_64 *= V_63 ;
V_65 = F_36 ( V_64 , 1000000000ULL ) ;
F_11 ( & V_2 -> V_7 , V_19 ) ;
F_12 ( & V_2 -> clock ) ;
V_2 -> V_11 . V_74 = V_66 ? V_2 -> V_73 - V_65 :
V_2 -> V_73 + V_65 ;
F_13 ( & V_2 -> V_7 , V_19 ) ;
return 0 ;
}
static int F_37 ( struct V_57 * V_58 ,
struct V_75 * V_76 ,
int V_77 )
{
struct V_1 * V_2 =
F_7 ( V_58 , struct V_1 , V_61 ) ;
struct V_25 * V_26 =
F_7 ( V_2 , struct V_25 , V_2 ) ;
T_4 V_68 [ F_33 ( V_69 ) ] = { 0 } ;
T_5 V_78 = 0 ;
int V_79 = - 1 ;
int V_80 = 0 ;
if ( ! F_17 ( V_26 -> V_12 , V_81 ) ||
! F_17 ( V_26 -> V_12 , V_67 ) )
return - V_30 ;
if ( V_76 -> V_82 . V_83 >= V_2 -> V_61 . V_84 )
return - V_85 ;
if ( V_77 ) {
V_79 = F_38 ( V_2 -> V_58 , V_86 , V_76 -> V_82 . V_83 ) ;
if ( V_79 < 0 )
return - V_87 ;
}
if ( V_76 -> V_82 . V_19 & V_88 )
V_78 = 1 ;
F_34 ( V_69 , V_68 , V_79 , V_79 ) ;
F_34 ( V_69 , V_68 , V_70 , V_89 ) ;
F_34 ( V_69 , V_68 , V_78 , V_78 ) ;
F_34 ( V_69 , V_68 , V_90 , V_77 ) ;
V_80 = F_35 ( V_26 -> V_12 , V_68 , sizeof( V_68 ) ) ;
if ( V_80 )
return V_80 ;
return F_39 ( V_26 -> V_12 , V_79 , 0 ,
V_91 & V_77 ) ;
}
static int F_40 ( struct V_57 * V_58 ,
struct V_75 * V_76 ,
int V_77 )
{
struct V_1 * V_2 =
F_7 ( V_58 , struct V_1 , V_61 ) ;
struct V_25 * V_26 =
F_7 ( V_2 , struct V_25 , V_2 ) ;
T_4 V_68 [ F_33 ( V_69 ) ] = { 0 } ;
T_1 V_92 , V_93 , V_94 ;
T_1 V_95 , V_96 ;
struct V_59 V_60 ;
unsigned long V_19 ;
int V_79 = - 1 ;
T_2 V_62 ;
if ( ! F_17 ( V_26 -> V_12 , V_67 ) )
return - V_30 ;
if ( V_76 -> V_97 . V_83 >= V_2 -> V_61 . V_84 )
return - V_85 ;
if ( V_77 ) {
V_79 = F_38 ( V_2 -> V_58 , V_98 ,
V_76 -> V_97 . V_83 ) ;
if ( V_79 < 0 )
return - V_87 ;
}
V_60 . V_99 = V_76 -> V_97 . V_100 . V_101 ;
V_60 . V_102 = V_76 -> V_97 . V_100 . V_6 ;
V_62 = F_26 ( & V_60 ) ;
if ( V_77 )
if ( ( V_62 >> 1 ) != 500000000LL )
return - V_85 ;
V_60 . V_99 = V_76 -> V_97 . V_103 . V_101 ;
V_60 . V_102 = V_76 -> V_97 . V_103 . V_6 ;
V_62 = F_26 ( & V_60 ) ;
V_95 = F_8 ( V_2 -> V_12 ) ;
F_11 ( & V_2 -> V_7 , V_19 ) ;
V_92 = F_3 ( & V_2 -> clock , V_95 ) ;
V_93 = V_62 - V_92 ;
V_96 = F_41 ( V_93 << V_2 -> V_11 . V_104 ,
V_2 -> V_11 . V_74 ) ;
F_13 ( & V_2 -> V_7 , V_19 ) ;
V_94 = V_95 + V_96 ;
F_34 ( V_69 , V_68 , V_79 , V_79 ) ;
F_34 ( V_69 , V_68 , V_70 , V_71 ) ;
F_34 ( V_69 , V_68 , V_78 , V_105 ) ;
F_34 ( V_69 , V_68 , V_90 , V_77 ) ;
F_42 ( V_69 , V_68 , V_94 , V_94 ) ;
return F_35 ( V_26 -> V_12 , V_68 , sizeof( V_68 ) ) ;
}
static int F_43 ( struct V_57 * V_58 ,
struct V_75 * V_76 ,
int V_77 )
{
switch ( V_76 -> type ) {
case V_106 :
return F_37 ( V_58 , V_76 , V_77 ) ;
case V_107 :
return F_40 ( V_58 , V_76 , V_77 ) ;
default:
return - V_30 ;
}
return 0 ;
}
static int F_44 ( struct V_57 * V_58 , unsigned int V_79 ,
enum V_108 V_109 , unsigned int V_110 )
{
return ( V_109 == V_111 ) ? - V_30 : 0 ;
}
static void F_45 ( struct V_1 * V_2 )
{
V_2 -> V_27 . V_33 = V_34 ;
V_2 -> V_27 . V_38 = V_39 ;
}
static int F_46 ( struct V_1 * V_2 )
{
int V_112 ;
V_2 -> V_61 . V_113 =
F_47 ( sizeof( * V_2 -> V_61 . V_113 ) *
V_2 -> V_61 . V_84 , V_114 ) ;
if ( ! V_2 -> V_61 . V_113 )
return - V_115 ;
V_2 -> V_61 . V_90 = F_43 ;
V_2 -> V_61 . V_116 = F_44 ;
for ( V_112 = 0 ; V_112 < V_2 -> V_61 . V_84 ; V_112 ++ ) {
snprintf ( V_2 -> V_61 . V_113 [ V_112 ] . V_117 ,
sizeof( V_2 -> V_61 . V_113 [ V_112 ] . V_117 ) ,
L_2 , V_112 ) ;
V_2 -> V_61 . V_113 [ V_112 ] . V_83 = V_112 ;
V_2 -> V_61 . V_113 [ V_112 ] . V_109 = V_118 ;
V_2 -> V_61 . V_113 [ V_112 ] . V_110 = V_112 ;
}
return 0 ;
}
static void F_48 ( struct V_25 * V_26 ,
struct V_1 * V_2 )
{
T_4 V_119 [ F_33 ( V_69 ) ] = { 0 } ;
F_49 ( V_26 -> V_12 , V_119 , sizeof( V_119 ) ) ;
V_2 -> V_61 . V_84 = F_50 ( V_69 , V_119 ,
V_120 ) ;
V_2 -> V_61 . V_121 = F_50 ( V_69 , V_119 ,
V_122 ) ;
V_2 -> V_61 . V_123 = F_50 ( V_69 , V_119 ,
V_124 ) ;
V_2 -> V_125 [ 0 ] = F_50 ( V_69 , V_119 , V_126 ) ;
V_2 -> V_125 [ 1 ] = F_50 ( V_69 , V_119 , V_127 ) ;
V_2 -> V_125 [ 2 ] = F_50 ( V_69 , V_119 , V_128 ) ;
V_2 -> V_125 [ 3 ] = F_50 ( V_69 , V_119 , V_129 ) ;
V_2 -> V_125 [ 4 ] = F_50 ( V_69 , V_119 , V_130 ) ;
V_2 -> V_125 [ 5 ] = F_50 ( V_69 , V_119 , V_131 ) ;
V_2 -> V_125 [ 6 ] = F_50 ( V_69 , V_119 , V_132 ) ;
V_2 -> V_125 [ 7 ] = F_50 ( V_69 , V_119 , V_133 ) ;
}
void F_51 ( struct V_25 * V_26 ,
struct V_134 * V_135 )
{
struct V_1 * V_2 = & V_26 -> V_2 ;
V_134 ( V_2 -> V_58 , V_135 ) ;
}
void F_52 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = & V_26 -> V_2 ;
T_1 V_62 ;
T_1 V_136 = 0 ;
T_4 V_137 ;
F_45 ( V_2 ) ;
V_137 = F_17 ( V_26 -> V_12 , V_29 ) ;
if ( ! V_137 ) {
F_53 ( V_26 -> V_12 , L_3 ) ;
return;
}
F_54 ( & V_2 -> V_7 ) ;
V_2 -> V_11 . V_138 = F_6 ;
V_2 -> V_11 . V_104 = V_139 ;
V_2 -> V_11 . V_74 = F_55 ( V_137 ,
V_2 -> V_11 . V_104 ) ;
V_2 -> V_73 = V_2 -> V_11 . V_74 ;
V_2 -> V_11 . V_13 = F_56 ( 41 ) ;
V_2 -> V_12 = V_26 -> V_12 ;
F_27 ( & V_2 -> clock , & V_2 -> V_11 ,
F_57 ( F_58 () ) ) ;
V_62 = F_59 ( & V_2 -> V_11 , V_2 -> V_11 . V_13 ,
V_136 , & V_136 ) ;
F_60 ( V_62 , V_140 / 2 / V_141 ) ;
V_2 -> V_20 = V_62 ;
F_61 ( & V_2 -> V_18 , F_9 ) ;
if ( V_2 -> V_20 )
F_14 ( & V_2 -> V_18 , 0 ) ;
else
F_53 ( V_26 -> V_12 , L_4 ) ;
V_2 -> V_61 = V_142 ;
snprintf ( V_2 -> V_61 . V_117 , 16 , L_5 ) ;
#define F_62 8
V_2 -> V_125 = F_47 ( sizeof( T_5 ) * F_62 , V_114 ) ;
if ( V_2 -> V_125 ) {
if ( F_17 ( V_26 -> V_12 , V_81 ) )
F_48 ( V_26 , V_2 ) ;
if ( V_2 -> V_61 . V_84 )
F_46 ( V_2 ) ;
} else {
F_53 ( V_26 -> V_12 , L_6 ) ;
}
V_2 -> V_58 = F_63 ( & V_2 -> V_61 ,
& V_26 -> V_12 -> V_143 -> V_22 ) ;
if ( F_64 ( V_2 -> V_58 ) ) {
F_53 ( V_26 -> V_12 , L_7 ,
F_65 ( V_2 -> V_58 ) ) ;
V_2 -> V_58 = NULL ;
}
}
void F_66 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = & V_26 -> V_2 ;
if ( ! F_17 ( V_26 -> V_12 , V_29 ) )
return;
if ( V_26 -> V_2 . V_58 ) {
F_67 ( V_26 -> V_2 . V_58 ) ;
V_26 -> V_2 . V_58 = NULL ;
}
F_68 ( V_2 -> V_125 ) ;
F_68 ( V_2 -> V_61 . V_113 ) ;
F_69 ( & V_2 -> V_18 ) ;
}
