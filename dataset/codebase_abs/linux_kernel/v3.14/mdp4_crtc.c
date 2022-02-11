static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
return F_2 ( F_3 ( V_5 -> V_8 ) ) ;
}
static void F_4 ( struct V_2 * V_3 , T_1 V_9 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_6 ( V_9 , & V_10 -> V_9 ) ;
F_7 ( & F_1 ( V_3 ) -> V_11 , & V_10 -> V_12 ) ;
}
static void F_8 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_13 , V_14 = 0 ;
for ( V_13 = 0 ; V_13 < F_9 ( V_10 -> V_15 ) ; V_13 ++ ) {
struct V_16 * V_17 = V_10 -> V_15 [ V_13 ] ;
if ( V_17 ) {
enum V_18 V_19 = F_10 ( V_17 ) ;
V_14 |= F_11 ( V_19 ) ;
}
}
V_14 |= F_12 ( V_10 -> V_20 ) ;
F_13 ( L_1 , V_10 -> V_21 , V_14 ) ;
F_14 ( V_1 , V_22 , V_14 ) ;
}
static void F_15 ( struct V_2 * V_3 , struct V_23 * V_24 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_23 * V_25 = V_10 -> V_26 ;
F_16 ( V_24 ) ;
V_10 -> V_11 . V_26 = V_24 ;
V_10 -> V_26 = V_24 ;
if ( V_25 )
F_17 ( & V_10 -> V_27 , V_25 ) ;
}
static void F_18 ( struct V_2 * V_3 , struct V_23 * V_26 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_8 ( V_3 ) ;
if ( V_10 -> V_28 )
F_17 ( & V_10 -> V_27 ,
V_10 -> V_28 ) ;
V_10 -> V_28 = V_26 ;
F_4 ( V_3 , V_29 ) ;
}
static void F_19 ( struct V_2 * V_3 , struct V_30 * V_31 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_32 * V_6 = V_3 -> V_6 ;
struct V_33 * V_34 ;
unsigned long V_35 ;
F_20 ( & V_6 -> V_36 , V_35 ) ;
V_34 = V_10 -> V_34 ;
if ( V_34 ) {
if ( ! V_31 || ( V_34 -> V_11 . V_37 == V_31 ) ) {
V_10 -> V_34 = NULL ;
F_21 ( V_6 , V_10 -> V_38 , V_34 ) ;
}
}
F_22 ( & V_6 -> V_36 , V_35 ) ;
}
static void F_23 ( struct V_39 * V_40 )
{
struct V_10 * V_10 =
F_24 ( V_40 , struct V_10 , F_23 ) ;
struct V_2 * V_3 = & V_10 -> V_11 ;
struct V_23 * V_26 = V_3 -> V_26 ;
if ( ! V_26 )
return;
F_16 ( V_26 ) ;
F_25 ( V_10 -> V_17 , V_26 ) ;
F_18 ( V_3 , V_26 ) ;
}
static void F_26 ( struct V_41 * V_42 , void * V_43 )
{
struct V_10 * V_10 =
F_24 ( V_42 , struct V_10 , V_27 ) ;
struct V_32 * V_6 = V_10 -> V_11 . V_6 ;
F_27 ( & V_6 -> V_44 . V_45 ) ;
F_28 ( V_43 ) ;
F_29 ( & V_6 -> V_44 . V_45 ) ;
}
static void F_30 ( struct V_41 * V_42 , void * V_43 )
{
struct V_10 * V_10 =
F_24 ( V_42 , struct V_10 , V_46 ) ;
struct V_1 * V_1 = F_1 ( & V_10 -> V_11 ) ;
F_31 ( V_43 , V_1 -> V_38 ) ;
F_32 ( V_43 ) ;
}
static void F_33 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
V_10 -> V_17 -> V_47 -> V_48 ( V_10 -> V_17 ) ;
F_34 ( V_3 ) ;
F_35 ( & V_10 -> V_27 ) ;
F_35 ( & V_10 -> V_46 ) ;
F_36 ( V_10 ) ;
}
static void F_37 ( struct V_2 * V_3 , int V_49 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
bool V_50 = ( V_49 == V_51 ) ;
F_13 ( L_2 , V_10 -> V_21 , V_49 ) ;
if ( V_50 != V_10 -> V_50 ) {
if ( V_50 ) {
F_38 ( V_1 ) ;
F_7 ( & V_1 -> V_11 , & V_10 -> V_52 ) ;
} else {
F_39 ( & V_1 -> V_11 , & V_10 -> V_52 ) ;
F_40 ( V_1 ) ;
}
V_10 -> V_50 = V_50 ;
}
}
static bool F_41 ( struct V_2 * V_3 ,
const struct V_53 * V_49 ,
struct V_53 * V_54 )
{
return true ;
}
static void F_42 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_13 , V_20 = V_10 -> V_20 ;
T_1 V_55 = 0 ;
static const enum V_56 V_57 [] = {
V_58 , V_59 , V_60 , V_61 , V_62 ,
} ;
static const int V_63 [] = {
[ V_64 ] = 1 ,
[ V_65 ] = 2 ,
[ V_66 ] = 0 ,
[ V_67 ] = 0 ,
[ V_68 ] = 0 ,
[ V_69 ] = 3 ,
[ V_70 ] = 4 ,
} ;
bool V_71 [ 4 ] = { false , false , false , false } ;
F_14 ( V_1 , F_43 ( V_20 ) , 0 ) ;
F_14 ( V_1 , F_44 ( V_20 ) , 0 ) ;
F_14 ( V_1 , F_45 ( V_20 ) , 0 ) ;
F_14 ( V_1 , F_46 ( V_20 ) , 0 ) ;
for ( V_13 = 0 ; V_13 < F_9 ( V_10 -> V_15 ) ; V_13 ++ ) {
struct V_16 * V_17 = V_10 -> V_15 [ V_13 ] ;
if ( V_17 ) {
enum V_18 V_19 = F_10 ( V_17 ) ;
int V_72 = V_63 [ V_19 ] ;
if ( V_72 > 0 ) {
const struct V_73 * V_74 =
F_47 ( F_48 ( V_17 -> V_26 ) ) ;
V_71 [ V_72 - 1 ] = V_74 -> V_75 ;
}
V_55 |= F_49 ( V_10 -> V_76 , V_19 , V_57 [ V_72 ] ) ;
}
}
F_50 ( ! V_55 ) ;
for ( V_13 = 0 ; V_13 < 4 ; V_13 ++ ) {
T_1 V_77 ;
if ( V_71 [ V_13 ] ) {
V_77 = F_51 ( V_78 ) |
F_52 ( V_78 ) |
V_79 ;
} else {
V_77 = F_51 ( V_80 ) |
F_52 ( V_81 ) ;
}
F_14 ( V_1 , F_53 ( V_20 , V_13 ) , 0xff ) ;
F_14 ( V_1 , F_54 ( V_20 , V_13 ) , 0x00 ) ;
F_14 ( V_1 , F_55 ( V_20 , V_13 ) , V_77 ) ;
F_14 ( V_1 , F_56 ( V_20 , V_13 ) , 1 ) ;
F_14 ( V_1 , F_57 ( V_20 , V_13 ) , 0 ) ;
F_14 ( V_1 , F_58 ( V_20 , V_13 ) , 0 ) ;
F_14 ( V_1 , F_59 ( V_20 , V_13 ) , 0 ) ;
F_14 ( V_1 , F_60 ( V_20 , V_13 ) , 0 ) ;
}
F_14 ( V_1 , V_82 , V_55 ) ;
}
static int F_61 ( struct V_2 * V_3 ,
struct V_53 * V_49 ,
struct V_53 * V_54 ,
int V_83 , int V_84 ,
struct V_23 * V_25 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_85 V_86 = V_10 -> V_86 ;
int V_87 , V_20 = V_10 -> V_20 ;
V_49 = V_54 ;
F_13 ( L_3 ,
V_10 -> V_21 , V_49 -> V_11 . V_38 , V_49 -> V_21 ,
V_49 -> V_88 , V_49 -> clock ,
V_49 -> V_89 , V_49 -> V_90 ,
V_49 -> V_91 , V_49 -> V_92 ,
V_49 -> V_93 , V_49 -> V_94 ,
V_49 -> V_95 , V_49 -> V_96 ,
V_49 -> type , V_49 -> V_35 ) ;
F_16 ( V_3 -> V_26 ) ;
V_87 = F_62 ( V_10 -> V_17 , V_3 , V_3 -> V_26 ,
0 , 0 , V_49 -> V_89 , V_49 -> V_93 ,
V_83 << 16 , V_84 << 16 ,
V_49 -> V_89 << 16 , V_49 -> V_93 << 16 ) ;
if ( V_87 ) {
F_28 ( V_3 -> V_26 ) ;
F_63 ( V_3 -> V_6 -> V_6 , L_4 ,
V_10 -> V_21 , V_87 ) ;
return V_87 ;
}
F_14 ( V_1 , F_64 ( V_86 ) ,
F_65 ( V_49 -> V_89 ) |
F_66 ( V_49 -> V_93 ) ) ;
F_14 ( V_1 , F_67 ( V_86 ) , 0 ) ;
F_14 ( V_1 , F_68 ( V_86 ) ,
V_3 -> V_26 -> V_97 [ 0 ] ) ;
F_14 ( V_1 , F_69 ( V_86 ) ,
F_70 ( 0 ) |
F_71 ( 0 ) ) ;
F_14 ( V_1 , F_72 ( V_20 ) , 0 ) ;
F_14 ( V_1 , F_73 ( V_20 ) ,
F_74 ( V_49 -> V_89 ) |
F_75 ( V_49 -> V_93 ) ) ;
F_14 ( V_1 , F_76 ( V_20 ) ,
V_3 -> V_26 -> V_97 [ 0 ] ) ;
F_14 ( V_1 , F_77 ( V_20 ) , 1 ) ;
if ( V_86 == V_98 ) {
F_14 ( V_1 , F_78 ( 0 ) , 0x00ff0000 ) ;
F_14 ( V_1 , F_78 ( 1 ) , 0x00ff0000 ) ;
F_14 ( V_1 , F_78 ( 2 ) , 0x00ff0000 ) ;
}
F_15 ( V_3 , V_3 -> V_26 ) ;
F_18 ( V_3 , V_3 -> V_26 ) ;
return 0 ;
}
static void F_79 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_13 ( L_5 , V_10 -> V_21 ) ;
F_38 ( F_1 ( V_3 ) ) ;
F_37 ( V_3 , V_99 ) ;
}
static void F_80 ( struct V_2 * V_3 )
{
F_37 ( V_3 , V_51 ) ;
F_8 ( V_3 ) ;
F_40 ( F_1 ( V_3 ) ) ;
}
static int F_81 ( struct V_2 * V_3 , int V_83 , int V_84 ,
struct V_23 * V_25 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_16 * V_17 = V_10 -> V_17 ;
struct V_53 * V_49 = & V_3 -> V_49 ;
int V_87 ;
F_16 ( V_3 -> V_26 ) ;
V_87 = F_62 ( V_17 , V_3 , V_3 -> V_26 ,
0 , 0 , V_49 -> V_89 , V_49 -> V_93 ,
V_83 << 16 , V_84 << 16 ,
V_49 -> V_89 << 16 , V_49 -> V_93 << 16 ) ;
if ( V_87 ) {
F_28 ( V_3 -> V_26 ) ;
return V_87 ;
}
F_15 ( V_3 , V_3 -> V_26 ) ;
F_18 ( V_3 , V_3 -> V_26 ) ;
return 0 ;
}
static void F_82 ( struct V_2 * V_3 )
{
}
static int F_83 ( struct V_2 * V_3 ,
struct V_23 * V_24 ,
struct V_33 * V_34 ,
T_1 V_100 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_32 * V_6 = V_3 -> V_6 ;
struct V_101 * V_102 ;
unsigned long V_35 ;
if ( V_10 -> V_34 ) {
F_63 ( V_6 -> V_6 , L_6 ) ;
return - V_103 ;
}
V_102 = F_84 ( V_24 , 0 ) ;
F_20 ( & V_6 -> V_36 , V_35 ) ;
V_10 -> V_34 = V_34 ;
F_22 ( & V_6 -> V_36 , V_35 ) ;
F_15 ( V_3 , V_24 ) ;
return F_85 ( V_102 , & V_10 -> F_23 ) ;
}
static int F_86 ( struct V_2 * V_3 ,
struct V_104 * V_105 , T_2 V_43 )
{
return - V_106 ;
}
static void F_87 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_85 V_86 = V_10 -> V_86 ;
unsigned long V_35 ;
F_20 ( & V_10 -> V_107 . V_108 , V_35 ) ;
if ( V_10 -> V_107 . V_109 ) {
struct V_101 * V_110 = V_10 -> V_107 . V_110 ;
struct V_101 * V_111 = V_10 -> V_107 . V_112 ;
T_1 V_113 = V_10 -> V_107 . V_114 ;
if ( V_110 ) {
F_88 ( V_110 ) ;
F_89 ( V_110 , V_1 -> V_38 , & V_113 ) ;
F_14 ( V_1 , F_90 ( V_86 ) ,
F_91 ( V_10 -> V_107 . V_115 ) |
F_92 ( V_10 -> V_107 . V_116 ) ) ;
F_14 ( V_1 , F_93 ( V_86 ) , V_113 ) ;
F_14 ( V_1 , F_94 ( V_86 ) ,
F_95 ( V_117 ) |
V_118 ) ;
} else {
F_14 ( V_1 , F_93 ( V_86 ) , 0 ) ;
F_14 ( V_1 , F_94 ( V_86 ) ,
F_95 ( V_117 ) ) ;
}
if ( V_111 )
F_17 ( & V_10 -> V_46 , V_111 ) ;
V_10 -> V_107 . V_112 = V_110 ;
V_10 -> V_107 . V_109 = false ;
}
F_14 ( V_1 , F_96 ( V_86 ) ,
F_97 ( V_10 -> V_107 . V_83 ) |
F_98 ( V_10 -> V_107 . V_84 ) ) ;
F_22 ( & V_10 -> V_107 . V_108 , V_35 ) ;
}
static int F_99 ( struct V_2 * V_3 ,
struct V_30 * V_37 , T_1 V_119 ,
T_1 V_115 , T_1 V_116 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_32 * V_6 = V_3 -> V_6 ;
struct V_101 * V_120 , * V_121 ;
unsigned long V_35 ;
T_1 V_113 ;
int V_87 ;
if ( ( V_115 > V_122 ) || ( V_116 > V_123 ) ) {
F_63 ( V_6 -> V_6 , L_7 , V_115 , V_116 ) ;
return - V_106 ;
}
if ( V_119 ) {
V_120 = F_100 ( V_6 , V_37 , V_119 ) ;
if ( ! V_120 )
return - V_124 ;
} else {
V_120 = NULL ;
}
if ( V_120 ) {
V_87 = F_101 ( V_120 , V_1 -> V_38 , & V_113 ) ;
if ( V_87 )
goto V_125;
} else {
V_113 = 0 ;
}
F_20 ( & V_10 -> V_107 . V_108 , V_35 ) ;
V_121 = V_10 -> V_107 . V_110 ;
V_10 -> V_107 . V_110 = V_120 ;
V_10 -> V_107 . V_114 = V_113 ;
V_10 -> V_107 . V_115 = V_115 ;
V_10 -> V_107 . V_116 = V_116 ;
V_10 -> V_107 . V_109 = true ;
F_22 ( & V_10 -> V_107 . V_108 , V_35 ) ;
if ( V_121 ) {
F_31 ( V_121 , V_1 -> V_38 ) ;
F_32 ( V_121 ) ;
}
F_8 ( V_3 ) ;
F_4 ( V_3 , V_126 ) ;
return 0 ;
V_125:
F_32 ( V_120 ) ;
return V_87 ;
}
static int F_102 ( struct V_2 * V_3 , int V_83 , int V_84 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
unsigned long V_35 ;
F_20 ( & V_10 -> V_107 . V_108 , V_35 ) ;
V_10 -> V_107 . V_83 = V_83 ;
V_10 -> V_107 . V_84 = V_84 ;
F_22 ( & V_10 -> V_107 . V_108 , V_35 ) ;
F_8 ( V_3 ) ;
F_4 ( V_3 , V_126 ) ;
return 0 ;
}
static void F_103 ( struct V_127 * V_128 , T_1 V_129 )
{
struct V_10 * V_10 = F_24 ( V_128 , struct V_10 , V_12 ) ;
struct V_2 * V_3 = & V_10 -> V_11 ;
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
unsigned V_9 ;
F_39 ( & F_1 ( V_3 ) -> V_11 , & V_10 -> V_12 ) ;
V_9 = F_104 ( & V_10 -> V_9 , 0 ) ;
if ( V_9 & V_29 ) {
F_19 ( V_3 , NULL ) ;
F_105 ( & V_10 -> V_27 , V_5 -> V_130 ) ;
}
if ( V_9 & V_126 ) {
F_87 ( V_3 ) ;
F_105 ( & V_10 -> V_46 , V_5 -> V_130 ) ;
}
}
static void F_106 ( struct V_127 * V_128 , T_1 V_129 )
{
struct V_10 * V_10 = F_24 ( V_128 , struct V_10 , V_52 ) ;
struct V_2 * V_3 = & V_10 -> V_11 ;
F_13 ( L_8 , V_10 -> V_21 , V_129 ) ;
F_8 ( V_3 ) ;
}
T_1 F_107 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
return V_10 -> V_12 . V_131 ;
}
void F_108 ( struct V_2 * V_3 , struct V_30 * V_31 )
{
F_13 ( L_9 , V_31 ) ;
F_19 ( V_3 , V_31 ) ;
}
void F_109 ( struct V_2 * V_3 , T_1 V_132 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_14 ( V_1 , F_110 ( V_10 -> V_86 ) , V_132 ) ;
}
void F_111 ( struct V_2 * V_3 , enum V_133 V_134 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_135 ;
V_135 = F_112 ( V_1 , V_136 ) ;
switch ( V_10 -> V_86 ) {
case V_137 :
V_135 &= ~ V_138 ;
V_135 |= F_113 ( V_134 ) ;
break;
case V_139 :
V_135 &= ~ V_140 ;
V_135 |= F_114 ( V_134 ) ;
break;
case V_98 :
V_135 &= ~ V_141 ;
V_135 |= F_115 ( V_134 ) ;
break;
}
if ( V_134 == V_142 ) {
V_135 &= ~ V_143 ;
V_135 |= V_144 ;
V_10 -> V_76 = 0 ;
} else if ( V_134 == V_145 ) {
V_135 &= ~ V_144 ;
V_135 |= V_143 ;
V_10 -> V_76 = 0 ;
} else if ( V_134 == V_146 ) {
V_10 -> V_76 = 1 ;
}
F_42 ( V_3 ) ;
F_13 ( L_10 , V_10 -> V_21 , V_135 ) ;
F_14 ( V_1 , V_136 , V_135 ) ;
}
static void F_116 ( struct V_2 * V_3 , enum V_18 V_19 ,
struct V_16 * V_17 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_117 ( V_19 >= F_9 ( V_10 -> V_15 ) ) ;
if ( V_10 -> V_15 [ V_19 ] == V_17 )
return;
V_10 -> V_15 [ V_19 ] = V_17 ;
F_42 ( V_3 ) ;
if ( V_10 -> V_50 && ( V_17 != V_10 -> V_17 ) )
F_8 ( V_3 ) ;
}
void F_118 ( struct V_2 * V_3 , struct V_16 * V_17 )
{
F_116 ( V_3 , F_10 ( V_17 ) , V_17 ) ;
}
void F_119 ( struct V_2 * V_3 , struct V_16 * V_17 )
{
F_116 ( V_3 , F_10 ( V_17 ) , NULL ) ;
}
struct V_2 * F_120 ( struct V_32 * V_6 ,
struct V_16 * V_17 , int V_38 , int V_147 ,
enum V_85 V_148 )
{
struct V_2 * V_3 = NULL ;
struct V_10 * V_10 ;
int V_87 ;
V_10 = F_121 ( sizeof( * V_10 ) , V_149 ) ;
if ( ! V_10 ) {
V_87 = - V_150 ;
goto V_125;
}
V_3 = & V_10 -> V_11 ;
V_10 -> V_17 = V_17 ;
V_10 -> V_38 = V_38 ;
V_10 -> V_20 = V_147 ;
V_10 -> V_86 = V_148 ;
V_10 -> V_12 . V_131 = F_122 ( V_10 -> V_86 ) ;
V_10 -> V_12 . V_128 = F_103 ;
V_10 -> V_52 . V_131 = F_123 ( V_10 -> V_86 ) ;
V_10 -> V_52 . V_128 = F_106 ;
snprintf ( V_10 -> V_21 , sizeof( V_10 -> V_21 ) , L_11 ,
V_151 [ V_148 ] , V_147 ) ;
F_124 ( & V_10 -> V_107 . V_108 ) ;
V_87 = F_125 ( & V_10 -> V_27 , 16 ,
L_12 , F_26 ) ;
if ( V_87 )
goto V_125;
V_87 = F_125 ( & V_10 -> V_46 , 64 ,
L_13 , F_30 ) ;
F_126 ( & V_10 -> F_23 , F_23 ) ;
F_127 ( V_6 , V_3 , & V_152 ) ;
F_128 ( V_3 , & V_153 ) ;
F_129 ( V_10 -> V_17 , & V_3 -> V_11 ) ;
return V_3 ;
V_125:
if ( V_3 )
F_33 ( V_3 ) ;
return F_130 ( V_87 ) ;
}
