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
V_10 -> V_11 . V_27 -> V_26 = V_24 ;
V_10 -> V_26 = V_24 ;
if ( V_25 )
F_17 ( & V_10 -> V_28 , V_25 ) ;
}
static void F_18 ( struct V_2 * V_3 , struct V_23 * V_26 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_8 ( V_3 ) ;
if ( V_10 -> V_29 )
F_17 ( & V_10 -> V_28 ,
V_10 -> V_29 ) ;
V_10 -> V_29 = V_26 ;
F_4 ( V_3 , V_30 ) ;
}
static void F_19 ( struct V_2 * V_3 , struct V_31 * V_32 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_33 * V_6 = V_3 -> V_6 ;
struct V_34 * V_35 ;
unsigned long V_36 ;
F_20 ( & V_6 -> V_37 , V_36 ) ;
V_35 = V_10 -> V_35 ;
if ( V_35 ) {
if ( ! V_32 || ( V_35 -> V_11 . V_38 == V_32 ) ) {
V_10 -> V_35 = NULL ;
F_21 ( V_6 , V_10 -> V_39 , V_35 ) ;
}
}
F_22 ( & V_6 -> V_37 , V_36 ) ;
}
static void F_23 ( struct V_40 * V_41 )
{
struct V_10 * V_10 =
F_24 ( V_41 , struct V_10 , F_23 ) ;
struct V_2 * V_3 = & V_10 -> V_11 ;
struct V_23 * V_26 = V_3 -> V_27 -> V_26 ;
if ( ! V_26 )
return;
F_16 ( V_26 ) ;
F_25 ( V_10 -> V_17 , V_26 ) ;
F_18 ( V_3 , V_26 ) ;
}
static void F_26 ( struct V_42 * V_43 , void * V_44 )
{
struct V_10 * V_10 =
F_24 ( V_43 , struct V_10 , V_28 ) ;
struct V_33 * V_6 = V_10 -> V_11 . V_6 ;
F_27 ( & V_6 -> V_45 . V_46 ) ;
F_28 ( V_44 ) ;
F_29 ( & V_6 -> V_45 . V_46 ) ;
}
static void F_30 ( struct V_42 * V_43 , void * V_44 )
{
struct V_10 * V_10 =
F_24 ( V_43 , struct V_10 , V_47 ) ;
struct V_1 * V_1 = F_1 ( & V_10 -> V_11 ) ;
F_31 ( V_44 , V_1 -> V_39 ) ;
F_32 ( V_44 ) ;
}
static void F_33 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_34 ( V_3 ) ;
F_35 ( & V_10 -> V_28 ) ;
F_35 ( & V_10 -> V_47 ) ;
F_36 ( V_10 ) ;
}
static void F_37 ( struct V_2 * V_3 , int V_48 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
bool V_49 = ( V_48 == V_50 ) ;
F_13 ( L_2 , V_10 -> V_21 , V_48 ) ;
if ( V_49 != V_10 -> V_49 ) {
if ( V_49 ) {
F_38 ( V_1 ) ;
F_7 ( & V_1 -> V_11 , & V_10 -> V_51 ) ;
} else {
F_39 ( & V_1 -> V_11 , & V_10 -> V_51 ) ;
F_40 ( V_1 ) ;
}
V_10 -> V_49 = V_49 ;
}
}
static bool F_41 ( struct V_2 * V_3 ,
const struct V_52 * V_48 ,
struct V_52 * V_53 )
{
return true ;
}
static void F_42 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_13 , V_20 = V_10 -> V_20 ;
T_1 V_54 = 0 ;
static const enum V_55 V_56 [] = {
V_57 , V_58 , V_59 , V_60 , V_61 ,
} ;
static const int V_62 [] = {
[ V_63 ] = 1 ,
[ V_64 ] = 2 ,
[ V_65 ] = 0 ,
[ V_66 ] = 0 ,
[ V_67 ] = 0 ,
[ V_68 ] = 3 ,
[ V_69 ] = 4 ,
} ;
bool V_70 [ 4 ] = { false , false , false , false } ;
F_14 ( V_1 , F_43 ( V_20 ) , 0 ) ;
F_14 ( V_1 , F_44 ( V_20 ) , 0 ) ;
F_14 ( V_1 , F_45 ( V_20 ) , 0 ) ;
F_14 ( V_1 , F_46 ( V_20 ) , 0 ) ;
for ( V_13 = 0 ; V_13 < F_9 ( V_10 -> V_15 ) ; V_13 ++ ) {
struct V_16 * V_17 = V_10 -> V_15 [ V_13 ] ;
if ( V_17 ) {
enum V_18 V_19 = F_10 ( V_17 ) ;
int V_71 = V_62 [ V_19 ] ;
if ( V_71 > 0 ) {
const struct V_72 * V_73 =
F_47 ( F_48 ( V_17 -> V_26 ) ) ;
V_70 [ V_71 - 1 ] = V_73 -> V_74 ;
}
V_54 |= F_49 ( V_10 -> V_75 , V_19 , V_56 [ V_71 ] ) ;
}
}
F_50 ( ! V_54 ) ;
for ( V_13 = 0 ; V_13 < 4 ; V_13 ++ ) {
T_1 V_76 ;
if ( V_70 [ V_13 ] ) {
V_76 = F_51 ( V_77 ) |
F_52 ( V_77 ) |
V_78 ;
} else {
V_76 = F_51 ( V_79 ) |
F_52 ( V_80 ) ;
}
F_14 ( V_1 , F_53 ( V_20 , V_13 ) , 0xff ) ;
F_14 ( V_1 , F_54 ( V_20 , V_13 ) , 0x00 ) ;
F_14 ( V_1 , F_55 ( V_20 , V_13 ) , V_76 ) ;
F_14 ( V_1 , F_56 ( V_20 , V_13 ) , 1 ) ;
F_14 ( V_1 , F_57 ( V_20 , V_13 ) , 0 ) ;
F_14 ( V_1 , F_58 ( V_20 , V_13 ) , 0 ) ;
F_14 ( V_1 , F_59 ( V_20 , V_13 ) , 0 ) ;
F_14 ( V_1 , F_60 ( V_20 , V_13 ) , 0 ) ;
}
F_14 ( V_1 , V_81 , V_54 ) ;
}
static int F_61 ( struct V_2 * V_3 ,
struct V_52 * V_48 ,
struct V_52 * V_53 ,
int V_82 , int V_83 ,
struct V_23 * V_25 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_84 V_85 = V_10 -> V_85 ;
int V_86 , V_20 = V_10 -> V_20 ;
V_48 = V_53 ;
F_13 ( L_3 ,
V_10 -> V_21 , V_48 -> V_11 . V_39 , V_48 -> V_21 ,
V_48 -> V_87 , V_48 -> clock ,
V_48 -> V_88 , V_48 -> V_89 ,
V_48 -> V_90 , V_48 -> V_91 ,
V_48 -> V_92 , V_48 -> V_93 ,
V_48 -> V_94 , V_48 -> V_95 ,
V_48 -> type , V_48 -> V_36 ) ;
F_16 ( V_3 -> V_27 -> V_26 ) ;
V_86 = F_62 ( V_10 -> V_17 , V_3 , V_3 -> V_27 -> V_26 ,
0 , 0 , V_48 -> V_88 , V_48 -> V_92 ,
V_82 << 16 , V_83 << 16 ,
V_48 -> V_88 << 16 , V_48 -> V_92 << 16 ) ;
if ( V_86 ) {
F_28 ( V_3 -> V_27 -> V_26 ) ;
F_63 ( V_3 -> V_6 -> V_6 , L_4 ,
V_10 -> V_21 , V_86 ) ;
return V_86 ;
}
F_14 ( V_1 , F_64 ( V_85 ) ,
F_65 ( V_48 -> V_88 ) |
F_66 ( V_48 -> V_92 ) ) ;
F_14 ( V_1 , F_67 ( V_85 ) , 0 ) ;
F_14 ( V_1 , F_68 ( V_85 ) ,
V_3 -> V_27 -> V_26 -> V_96 [ 0 ] ) ;
F_14 ( V_1 , F_69 ( V_85 ) ,
F_70 ( 0 ) |
F_71 ( 0 ) ) ;
F_14 ( V_1 , F_72 ( V_20 ) , 0 ) ;
F_14 ( V_1 , F_73 ( V_20 ) ,
F_74 ( V_48 -> V_88 ) |
F_75 ( V_48 -> V_92 ) ) ;
F_14 ( V_1 , F_76 ( V_20 ) ,
V_3 -> V_27 -> V_26 -> V_96 [ 0 ] ) ;
F_14 ( V_1 , F_77 ( V_20 ) , 1 ) ;
if ( V_85 == V_97 ) {
F_14 ( V_1 , F_78 ( 0 ) , 0x00ff0000 ) ;
F_14 ( V_1 , F_78 ( 1 ) , 0x00ff0000 ) ;
F_14 ( V_1 , F_78 ( 2 ) , 0x00ff0000 ) ;
}
F_15 ( V_3 , V_3 -> V_27 -> V_26 ) ;
F_18 ( V_3 , V_3 -> V_27 -> V_26 ) ;
return 0 ;
}
static void F_79 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_13 ( L_5 , V_10 -> V_21 ) ;
F_38 ( F_1 ( V_3 ) ) ;
F_37 ( V_3 , V_98 ) ;
}
static void F_80 ( struct V_2 * V_3 )
{
F_37 ( V_3 , V_50 ) ;
F_8 ( V_3 ) ;
F_40 ( F_1 ( V_3 ) ) ;
}
static int F_81 ( struct V_2 * V_3 , int V_82 , int V_83 ,
struct V_23 * V_25 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_16 * V_17 = V_10 -> V_17 ;
struct V_52 * V_48 = & V_3 -> V_48 ;
int V_86 ;
F_16 ( V_3 -> V_27 -> V_26 ) ;
V_86 = F_62 ( V_17 , V_3 , V_3 -> V_27 -> V_26 ,
0 , 0 , V_48 -> V_88 , V_48 -> V_92 ,
V_82 << 16 , V_83 << 16 ,
V_48 -> V_88 << 16 , V_48 -> V_92 << 16 ) ;
if ( V_86 ) {
F_28 ( V_3 -> V_27 -> V_26 ) ;
return V_86 ;
}
F_15 ( V_3 , V_3 -> V_27 -> V_26 ) ;
F_18 ( V_3 , V_3 -> V_27 -> V_26 ) ;
return 0 ;
}
static void F_82 ( struct V_2 * V_3 )
{
}
static int F_83 ( struct V_2 * V_3 ,
struct V_23 * V_24 ,
struct V_34 * V_35 ,
T_1 V_99 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_33 * V_6 = V_3 -> V_6 ;
struct V_100 * V_101 ;
unsigned long V_36 ;
if ( V_10 -> V_35 ) {
F_63 ( V_6 -> V_6 , L_6 ) ;
return - V_102 ;
}
V_101 = F_84 ( V_24 , 0 ) ;
F_20 ( & V_6 -> V_37 , V_36 ) ;
V_10 -> V_35 = V_35 ;
F_22 ( & V_6 -> V_37 , V_36 ) ;
F_15 ( V_3 , V_24 ) ;
return F_85 ( V_101 , & V_10 -> F_23 ) ;
}
static int F_86 ( struct V_2 * V_3 ,
struct V_103 * V_104 , T_2 V_44 )
{
return - V_105 ;
}
static void F_87 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_84 V_85 = V_10 -> V_85 ;
unsigned long V_36 ;
F_20 ( & V_10 -> V_106 . V_107 , V_36 ) ;
if ( V_10 -> V_106 . V_108 ) {
struct V_100 * V_109 = V_10 -> V_106 . V_109 ;
struct V_100 * V_110 = V_10 -> V_106 . V_111 ;
T_1 V_112 = V_10 -> V_106 . V_113 ;
if ( V_109 ) {
F_88 ( V_109 ) ;
F_89 ( V_109 , V_1 -> V_39 , & V_112 ) ;
F_14 ( V_1 , F_90 ( V_85 ) ,
F_91 ( V_10 -> V_106 . V_114 ) |
F_92 ( V_10 -> V_106 . V_115 ) ) ;
F_14 ( V_1 , F_93 ( V_85 ) , V_112 ) ;
F_14 ( V_1 , F_94 ( V_85 ) ,
F_95 ( V_116 ) |
V_117 ) ;
} else {
F_14 ( V_1 , F_93 ( V_85 ) ,
V_1 -> V_118 ) ;
}
if ( V_110 )
F_17 ( & V_10 -> V_47 , V_110 ) ;
V_10 -> V_106 . V_111 = V_109 ;
V_10 -> V_106 . V_108 = false ;
}
F_14 ( V_1 , F_96 ( V_85 ) ,
F_97 ( V_10 -> V_106 . V_82 ) |
F_98 ( V_10 -> V_106 . V_83 ) ) ;
F_22 ( & V_10 -> V_106 . V_107 , V_36 ) ;
}
static int F_99 ( struct V_2 * V_3 ,
struct V_31 * V_38 , T_1 V_119 ,
T_1 V_114 , T_1 V_115 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_33 * V_6 = V_3 -> V_6 ;
struct V_100 * V_120 , * V_121 ;
unsigned long V_36 ;
T_1 V_112 ;
int V_86 ;
if ( ( V_114 > V_122 ) || ( V_115 > V_123 ) ) {
F_63 ( V_6 -> V_6 , L_7 , V_114 , V_115 ) ;
return - V_105 ;
}
if ( V_119 ) {
V_120 = F_100 ( V_6 , V_38 , V_119 ) ;
if ( ! V_120 )
return - V_124 ;
} else {
V_120 = NULL ;
}
if ( V_120 ) {
V_86 = F_101 ( V_120 , V_1 -> V_39 , & V_112 ) ;
if ( V_86 )
goto V_125;
} else {
V_112 = 0 ;
}
F_20 ( & V_10 -> V_106 . V_107 , V_36 ) ;
V_121 = V_10 -> V_106 . V_109 ;
V_10 -> V_106 . V_109 = V_120 ;
V_10 -> V_106 . V_113 = V_112 ;
V_10 -> V_106 . V_114 = V_114 ;
V_10 -> V_106 . V_115 = V_115 ;
V_10 -> V_106 . V_108 = true ;
F_22 ( & V_10 -> V_106 . V_107 , V_36 ) ;
if ( V_121 ) {
F_17 ( & V_10 -> V_47 , V_121 ) ;
}
F_4 ( V_3 , V_126 ) ;
return 0 ;
V_125:
F_32 ( V_120 ) ;
return V_86 ;
}
static int F_102 ( struct V_2 * V_3 , int V_82 , int V_83 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
unsigned long V_36 ;
F_20 ( & V_10 -> V_106 . V_107 , V_36 ) ;
V_10 -> V_106 . V_82 = V_82 ;
V_10 -> V_106 . V_83 = V_83 ;
F_22 ( & V_10 -> V_106 . V_107 , V_36 ) ;
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
if ( V_9 & V_30 ) {
F_19 ( V_3 , NULL ) ;
F_105 ( & V_10 -> V_28 , V_5 -> V_130 ) ;
}
if ( V_9 & V_126 ) {
F_87 ( V_3 ) ;
F_105 ( & V_10 -> V_47 , V_5 -> V_130 ) ;
}
}
static void F_106 ( struct V_127 * V_128 , T_1 V_129 )
{
struct V_10 * V_10 = F_24 ( V_128 , struct V_10 , V_51 ) ;
struct V_2 * V_3 = & V_10 -> V_11 ;
F_13 ( L_8 , V_10 -> V_21 , V_129 ) ;
F_8 ( V_3 ) ;
}
T_1 F_107 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
return V_10 -> V_12 . V_131 ;
}
void F_108 ( struct V_2 * V_3 , struct V_31 * V_32 )
{
F_13 ( L_9 , V_32 ) ;
F_19 ( V_3 , V_32 ) ;
}
void F_109 ( struct V_2 * V_3 , T_1 V_132 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_14 ( V_1 , F_110 ( V_10 -> V_85 ) , V_132 ) ;
}
void F_111 ( struct V_2 * V_3 , enum V_133 V_134 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_135 ;
V_135 = F_112 ( V_1 , V_136 ) ;
switch ( V_10 -> V_85 ) {
case V_137 :
V_135 &= ~ V_138 ;
V_135 |= F_113 ( V_134 ) ;
break;
case V_139 :
V_135 &= ~ V_140 ;
V_135 |= F_114 ( V_134 ) ;
break;
case V_97 :
V_135 &= ~ V_141 ;
V_135 |= F_115 ( V_134 ) ;
break;
}
if ( V_134 == V_142 ) {
V_135 &= ~ V_143 ;
V_135 |= V_144 ;
V_10 -> V_75 = 0 ;
} else if ( V_134 == V_145 ) {
V_135 &= ~ V_144 ;
V_135 |= V_143 ;
V_10 -> V_75 = 0 ;
} else if ( V_134 == V_146 ) {
V_10 -> V_75 = 1 ;
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
if ( V_10 -> V_49 && ( V_17 != V_10 -> V_17 ) )
F_8 ( V_3 ) ;
}
void F_118 ( struct V_2 * V_3 , struct V_16 * V_17 )
{
F_116 ( V_3 , F_10 ( V_17 ) , V_17 ) ;
}
void F_119 ( struct V_2 * V_3 , struct V_16 * V_17 )
{
if ( F_5 ( V_3 ) -> V_17 == V_17 )
return;
F_116 ( V_3 , F_10 ( V_17 ) , NULL ) ;
}
struct V_2 * F_120 ( struct V_33 * V_6 ,
struct V_16 * V_17 , int V_39 , int V_147 ,
enum V_84 V_148 )
{
struct V_2 * V_3 = NULL ;
struct V_10 * V_10 ;
int V_86 ;
V_10 = F_121 ( sizeof( * V_10 ) , V_149 ) ;
if ( ! V_10 ) {
V_86 = - V_150 ;
goto V_125;
}
V_3 = & V_10 -> V_11 ;
V_10 -> V_17 = V_17 ;
V_10 -> V_39 = V_39 ;
V_10 -> V_20 = V_147 ;
V_10 -> V_85 = V_148 ;
V_10 -> V_12 . V_131 = F_122 ( V_10 -> V_85 ) ;
V_10 -> V_12 . V_128 = F_103 ;
V_10 -> V_51 . V_131 = F_123 ( V_10 -> V_85 ) ;
V_10 -> V_51 . V_128 = F_106 ;
snprintf ( V_10 -> V_21 , sizeof( V_10 -> V_21 ) , L_11 ,
V_151 [ V_148 ] , V_147 ) ;
F_124 ( & V_10 -> V_106 . V_107 ) ;
V_86 = F_125 ( & V_10 -> V_28 , 16 ,
L_12 , F_26 ) ;
if ( V_86 )
goto V_125;
V_86 = F_125 ( & V_10 -> V_47 , 64 ,
L_13 , F_30 ) ;
F_126 ( & V_10 -> F_23 , F_23 ) ;
F_127 ( V_6 , V_3 , V_17 , NULL , & V_152 ) ;
F_128 ( V_3 , & V_153 ) ;
F_129 ( V_10 -> V_17 , & V_3 -> V_11 ) ;
return V_3 ;
V_125:
if ( V_3 )
F_33 ( V_3 ) ;
return F_130 ( V_86 ) ;
}
