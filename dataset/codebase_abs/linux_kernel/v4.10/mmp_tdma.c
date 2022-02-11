static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_3 , V_2 -> V_4 + V_5 ) ;
F_2 ( F_3 ( V_2 -> V_4 + V_6 ) | V_7 ,
V_2 -> V_4 + V_6 ) ;
}
static void F_4 ( struct V_1 * V_2 , bool V_8 )
{
if ( V_8 )
F_2 ( V_9 , V_2 -> V_4 + V_10 ) ;
else
F_2 ( 0 , V_2 -> V_4 + V_10 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_2 ( F_3 ( V_2 -> V_4 + V_6 ) | V_11 ,
V_2 -> V_4 + V_6 ) ;
V_2 -> V_12 = V_13 ;
}
static int F_6 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_7 ( V_15 ) ;
T_2 V_16 ;
V_16 = F_3 ( V_2 -> V_4 + V_6 ) ;
V_16 |= V_17 ;
V_16 &= ~ V_11 ;
F_2 ( V_16 , V_2 -> V_4 + V_6 ) ;
V_2 -> V_12 = V_18 ;
return 0 ;
}
static int F_8 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_7 ( V_15 ) ;
F_2 ( F_3 ( V_2 -> V_4 + V_6 ) | V_11 ,
V_2 -> V_4 + V_6 ) ;
V_2 -> V_12 = V_13 ;
return 0 ;
}
static int F_9 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_7 ( V_15 ) ;
F_2 ( F_3 ( V_2 -> V_4 + V_6 ) & ~ V_11 ,
V_2 -> V_4 + V_6 ) ;
V_2 -> V_12 = V_19 ;
return 0 ;
}
static int F_10 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_7 ( V_15 ) ;
unsigned int V_16 = 0 ;
F_6 ( V_15 ) ;
if ( V_2 -> V_20 == V_21 )
V_16 = V_22 | V_23 ;
else if ( V_2 -> V_20 == V_24 )
V_16 = V_25 | V_26 ;
if ( V_2 -> type == V_27 ) {
V_16 |= V_28 ;
switch ( V_2 -> V_29 ) {
case 4 :
V_16 |= V_30 ;
break;
case 8 :
V_16 |= V_31 ;
break;
case 16 :
V_16 |= V_32 ;
break;
case 32 :
V_16 |= V_33 ;
break;
case 64 :
V_16 |= V_34 ;
break;
case 128 :
V_16 |= V_35 ;
break;
default:
F_11 ( V_2 -> V_36 , L_1 ) ;
return - V_37 ;
}
switch ( V_2 -> V_38 ) {
case V_39 :
V_16 |= V_40 ;
break;
case V_41 :
V_16 |= V_42 ;
break;
case V_43 :
V_16 |= V_44 ;
break;
default:
F_11 ( V_2 -> V_36 , L_2 ) ;
return - V_37 ;
}
} else if ( V_2 -> type == V_45 ) {
V_16 |= V_46 ;
switch ( V_2 -> V_29 ) {
case 1 :
V_16 |= V_47 ;
break;
case 2 :
V_16 |= V_48 ;
break;
case 4 :
V_16 |= V_49 ;
break;
case 8 :
V_16 |= V_50 ;
break;
case 16 :
V_16 |= V_51 ;
break;
case 32 :
V_16 |= V_52 ;
break;
default:
F_11 ( V_2 -> V_36 , L_1 ) ;
return - V_37 ;
}
}
F_2 ( V_16 , V_2 -> V_4 + V_6 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
T_2 V_53 = F_3 ( V_2 -> V_4 + V_54 ) ;
if ( V_53 & V_55 ) {
V_53 &= ~ V_55 ;
F_2 ( V_53 , V_2 -> V_4 + V_54 ) ;
return 0 ;
}
return - V_56 ;
}
static T_3 F_13 ( struct V_1 * V_2 )
{
T_3 V_53 ;
if ( V_2 -> V_57 == 0 ) {
V_53 = F_14 ( V_2 -> V_4 + V_58 ) ;
V_53 -= V_2 -> V_59 [ 0 ] . V_60 ;
} else if ( V_2 -> V_57 == 1 ) {
V_53 = F_14 ( V_2 -> V_4 + V_61 ) ;
V_53 -= V_2 -> V_59 [ 0 ] . V_62 ;
} else
return - V_37 ;
return V_53 ;
}
static T_4 F_15 ( int V_63 , void * V_64 )
{
struct V_1 * V_2 = V_64 ;
if ( F_12 ( V_2 ) == 0 ) {
F_16 ( & V_2 -> V_65 ) ;
return V_66 ;
} else
return V_67 ;
}
static T_4 F_17 ( int V_63 , void * V_64 )
{
struct V_68 * V_69 = V_64 ;
int V_70 , V_71 ;
int V_72 = 0 ;
for ( V_70 = 0 ; V_70 < V_73 ; V_70 ++ ) {
struct V_1 * V_2 = V_69 -> V_2 [ V_70 ] ;
V_71 = F_15 ( V_63 , V_2 ) ;
if ( V_71 == V_66 )
V_72 ++ ;
}
if ( V_72 )
return V_66 ;
else
return V_67 ;
}
static void F_18 ( unsigned long V_74 )
{
struct V_1 * V_2 = (struct V_1 * ) V_74 ;
F_19 ( & V_2 -> V_75 , NULL ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_76 * V_77 ;
int V_78 = V_2 -> V_79 * sizeof( struct V_80 ) ;
V_77 = V_2 -> V_81 ;
if ( V_77 && V_2 -> V_59 )
F_21 ( V_77 , ( unsigned long ) V_2 -> V_59 ,
V_78 ) ;
V_2 -> V_59 = NULL ;
return;
}
static T_5 F_22 ( struct V_82 * V_83 )
{
struct V_1 * V_2 = F_7 ( V_83 -> V_15 ) ;
F_1 ( V_2 , V_2 -> V_84 ) ;
return 0 ;
}
static int F_23 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_7 ( V_15 ) ;
int V_71 ;
F_24 ( & V_2 -> V_75 , V_15 ) ;
V_2 -> V_75 . V_85 = F_22 ;
if ( V_2 -> V_63 ) {
V_71 = F_25 ( V_2 -> V_36 , V_2 -> V_63 ,
F_15 , 0 , L_3 , V_2 ) ;
if ( V_71 )
return V_71 ;
}
return 1 ;
}
static void F_26 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_7 ( V_15 ) ;
if ( V_2 -> V_63 )
F_27 ( V_2 -> V_36 , V_2 -> V_63 , V_2 ) ;
F_20 ( V_2 ) ;
return;
}
static struct V_80 * F_28 ( struct V_1 * V_2 )
{
struct V_76 * V_77 ;
int V_78 = V_2 -> V_79 * sizeof( struct V_80 ) ;
V_77 = V_2 -> V_81 ;
if ( ! V_77 )
return NULL ;
V_2 -> V_59 = F_29 ( V_77 , V_78 , & V_2 -> V_84 ) ;
return V_2 -> V_59 ;
}
static struct V_82 * F_30 (
struct V_14 * V_15 , T_1 V_86 , T_3 V_87 ,
T_3 V_88 , enum V_89 V_90 ,
unsigned long V_91 )
{
struct V_1 * V_2 = F_7 ( V_15 ) ;
struct V_80 * V_75 ;
int V_92 = V_87 / V_88 ;
int V_70 = 0 , V_93 = 0 ;
if ( V_2 -> V_12 != V_18 )
return NULL ;
if ( V_88 > V_94 ) {
F_11 ( V_2 -> V_36 ,
L_4 ,
V_88 , V_94 ) ;
goto V_95;
}
V_2 -> V_12 = V_13 ;
V_2 -> V_79 = V_92 ;
V_75 = F_28 ( V_2 ) ;
if ( ! V_75 )
goto V_95;
while ( V_93 < V_87 ) {
V_75 = & V_2 -> V_59 [ V_70 ] ;
if ( V_70 + 1 == V_92 )
V_75 -> V_96 = V_2 -> V_84 ;
else
V_75 -> V_96 = V_2 -> V_84 +
sizeof( * V_75 ) * ( V_70 + 1 ) ;
if ( V_90 == V_21 ) {
V_75 -> V_60 = V_86 ;
V_75 -> V_62 = V_2 -> V_97 ;
} else {
V_75 -> V_60 = V_2 -> V_97 ;
V_75 -> V_62 = V_86 ;
}
V_75 -> V_98 = V_88 ;
V_86 += V_88 ;
V_93 += V_88 ;
V_70 ++ ;
}
if ( V_91 & V_99 )
F_4 ( V_2 , true ) ;
V_2 -> V_87 = V_87 ;
V_2 -> V_88 = V_88 ;
V_2 -> V_100 = 0 ;
return & V_2 -> V_75 ;
V_95:
V_2 -> V_12 = V_101 ;
return NULL ;
}
static int F_31 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_7 ( V_15 ) ;
F_6 ( V_15 ) ;
F_4 ( V_2 , false ) ;
return 0 ;
}
static int F_32 ( struct V_14 * V_15 ,
struct V_102 * V_103 )
{
struct V_1 * V_2 = F_7 ( V_15 ) ;
if ( V_103 -> V_90 == V_24 ) {
V_2 -> V_97 = V_103 -> V_60 ;
V_2 -> V_29 = V_103 -> V_104 ;
V_2 -> V_38 = V_103 -> V_105 ;
} else {
V_2 -> V_97 = V_103 -> V_62 ;
V_2 -> V_29 = V_103 -> V_106 ;
V_2 -> V_38 = V_103 -> V_107 ;
}
V_2 -> V_20 = V_103 -> V_90 ;
return F_10 ( V_15 ) ;
}
static enum V_108 F_33 ( struct V_14 * V_15 ,
T_5 V_109 , struct V_110 * V_111 )
{
struct V_1 * V_2 = F_7 ( V_15 ) ;
V_2 -> V_100 = F_13 ( V_2 ) ;
F_34 ( V_111 , V_15 -> V_112 , V_15 -> V_109 ,
V_2 -> V_87 - V_2 -> V_100 ) ;
return V_2 -> V_12 ;
}
static void F_35 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_7 ( V_15 ) ;
F_5 ( V_2 ) ;
}
static int F_36 ( struct V_113 * V_114 )
{
struct V_68 * V_69 = F_37 ( V_114 ) ;
F_38 ( & V_69 -> V_115 ) ;
return 0 ;
}
static int F_39 ( struct V_68 * V_69 ,
int V_57 , int V_63 ,
int type , struct V_76 * V_81 )
{
struct V_1 * V_2 ;
if ( V_57 >= V_73 ) {
F_11 ( V_69 -> V_36 , L_5 ) ;
return - V_37 ;
}
V_2 = F_40 ( V_69 -> V_36 , sizeof( * V_2 ) , V_116 ) ;
if ( ! V_2 )
return - V_117 ;
if ( V_63 )
V_2 -> V_63 = V_63 ;
V_2 -> V_36 = V_69 -> V_36 ;
V_2 -> V_15 . V_115 = & V_69 -> V_115 ;
V_2 -> V_57 = V_57 ;
V_2 -> type = type ;
V_2 -> V_4 = V_69 -> V_118 + V_57 * 4 ;
V_2 -> V_81 = V_81 ;
V_2 -> V_12 = V_18 ;
V_69 -> V_2 [ V_2 -> V_57 ] = V_2 ;
F_41 ( & V_2 -> V_65 , F_18 , ( unsigned long ) V_2 ) ;
F_42 ( & V_2 -> V_15 . V_119 ,
& V_69 -> V_115 . V_120 ) ;
return 0 ;
}
static bool F_43 ( struct V_14 * V_15 , void * V_121 )
{
struct V_122 * V_123 = V_121 ;
struct V_1 * V_2 = F_7 ( V_15 ) ;
struct V_124 * V_125 = V_2 -> V_15 . V_115 ;
if ( V_125 -> V_36 -> V_126 != V_123 -> V_126 )
return false ;
if ( V_15 -> V_127 != V_123 -> V_127 )
return false ;
return true ;
}
static struct V_14 * F_44 ( struct V_128 * V_129 ,
struct V_130 * V_131 )
{
struct V_68 * V_69 = V_131 -> V_132 ;
T_6 V_133 = V_69 -> V_115 . V_134 ;
struct V_122 V_123 ;
if ( V_129 -> V_135 != 1 )
return NULL ;
V_123 . V_126 = V_131 -> V_126 ;
V_123 . V_127 = V_129 -> args [ 0 ] ;
if ( V_123 . V_127 >= V_73 )
return NULL ;
return F_45 ( V_133 , F_43 , & V_123 ) ;
}
static int F_46 ( struct V_113 * V_114 )
{
enum V_136 type ;
const struct V_137 * V_138 ;
struct V_68 * V_69 ;
struct V_139 * V_140 ;
int V_70 , V_71 ;
int V_63 = 0 , V_72 = 0 ;
int V_141 = V_73 ;
struct V_76 * V_81 = NULL ;
V_138 = F_47 ( V_142 , & V_114 -> V_36 ) ;
if ( V_138 )
type = (enum V_136 ) V_138 -> V_74 ;
else
type = F_48 ( V_114 ) -> V_143 ;
V_69 = F_40 ( & V_114 -> V_36 , sizeof( * V_69 ) , V_116 ) ;
if ( ! V_69 )
return - V_117 ;
V_69 -> V_36 = & V_114 -> V_36 ;
for ( V_70 = 0 ; V_70 < V_141 ; V_70 ++ ) {
if ( F_49 ( V_114 , V_70 ) > 0 )
V_72 ++ ;
}
V_140 = F_50 ( V_114 , V_144 , 0 ) ;
V_69 -> V_118 = F_51 ( & V_114 -> V_36 , V_140 ) ;
if ( F_52 ( V_69 -> V_118 ) )
return F_53 ( V_69 -> V_118 ) ;
F_54 ( & V_69 -> V_115 . V_120 ) ;
if ( V_114 -> V_36 . V_126 )
V_81 = F_55 ( V_114 -> V_36 . V_126 , L_6 , 0 ) ;
else
V_81 = F_56 ( L_6 ) ;
if ( ! V_81 ) {
F_11 ( & V_114 -> V_36 , L_7 ) ;
return - V_117 ;
}
if ( V_72 != V_141 ) {
V_63 = F_49 ( V_114 , 0 ) ;
V_71 = F_25 ( & V_114 -> V_36 , V_63 ,
F_17 , 0 , L_3 , V_69 ) ;
if ( V_71 )
return V_71 ;
}
for ( V_70 = 0 ; V_70 < V_141 ; V_70 ++ ) {
V_63 = ( V_72 != V_141 ) ? 0 : F_49 ( V_114 , V_70 ) ;
V_71 = F_39 ( V_69 , V_70 , V_63 , type , V_81 ) ;
if ( V_71 )
return V_71 ;
}
F_57 ( V_145 , V_69 -> V_115 . V_134 ) ;
F_57 ( V_146 , V_69 -> V_115 . V_134 ) ;
V_69 -> V_115 . V_36 = & V_114 -> V_36 ;
V_69 -> V_115 . V_147 =
F_23 ;
V_69 -> V_115 . V_148 =
F_26 ;
V_69 -> V_115 . V_149 = F_30 ;
V_69 -> V_115 . V_150 = F_33 ;
V_69 -> V_115 . V_151 = F_35 ;
V_69 -> V_115 . V_152 = F_32 ;
V_69 -> V_115 . V_153 = F_9 ;
V_69 -> V_115 . V_154 = F_8 ;
V_69 -> V_115 . V_155 = F_31 ;
V_69 -> V_115 . V_156 = V_157 ;
F_58 ( & V_114 -> V_36 , F_59 ( 64 ) ) ;
F_60 ( V_114 , V_69 ) ;
V_71 = F_61 ( & V_69 -> V_115 ) ;
if ( V_71 ) {
F_11 ( V_69 -> V_115 . V_36 , L_8 ) ;
return V_71 ;
}
if ( V_114 -> V_36 . V_126 ) {
V_71 = F_62 ( V_114 -> V_36 . V_126 ,
F_44 , V_69 ) ;
if ( V_71 ) {
F_11 ( V_69 -> V_115 . V_36 ,
L_9 ) ;
F_38 ( & V_69 -> V_115 ) ;
}
}
F_63 ( V_69 -> V_115 . V_36 , L_10 ) ;
return 0 ;
}
