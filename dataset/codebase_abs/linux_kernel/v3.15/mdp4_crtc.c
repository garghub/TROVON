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
V_10 -> V_17 -> V_48 -> V_49 ( V_10 -> V_17 ) ;
F_34 ( V_3 ) ;
F_35 ( & V_10 -> V_28 ) ;
F_35 ( & V_10 -> V_47 ) ;
F_36 ( V_10 ) ;
}
static void F_37 ( struct V_2 * V_3 , int V_50 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
bool V_51 = ( V_50 == V_52 ) ;
F_13 ( L_2 , V_10 -> V_21 , V_50 ) ;
if ( V_51 != V_10 -> V_51 ) {
if ( V_51 ) {
F_38 ( V_1 ) ;
F_7 ( & V_1 -> V_11 , & V_10 -> V_53 ) ;
} else {
F_39 ( & V_1 -> V_11 , & V_10 -> V_53 ) ;
F_40 ( V_1 ) ;
}
V_10 -> V_51 = V_51 ;
}
}
static bool F_41 ( struct V_2 * V_3 ,
const struct V_54 * V_50 ,
struct V_54 * V_55 )
{
return true ;
}
static void F_42 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_13 , V_20 = V_10 -> V_20 ;
T_1 V_56 = 0 ;
static const enum V_57 V_58 [] = {
V_59 , V_60 , V_61 , V_62 , V_63 ,
} ;
static const int V_64 [] = {
[ V_65 ] = 1 ,
[ V_66 ] = 2 ,
[ V_67 ] = 0 ,
[ V_68 ] = 0 ,
[ V_69 ] = 0 ,
[ V_70 ] = 3 ,
[ V_71 ] = 4 ,
} ;
bool V_72 [ 4 ] = { false , false , false , false } ;
F_14 ( V_1 , F_43 ( V_20 ) , 0 ) ;
F_14 ( V_1 , F_44 ( V_20 ) , 0 ) ;
F_14 ( V_1 , F_45 ( V_20 ) , 0 ) ;
F_14 ( V_1 , F_46 ( V_20 ) , 0 ) ;
for ( V_13 = 0 ; V_13 < F_9 ( V_10 -> V_15 ) ; V_13 ++ ) {
struct V_16 * V_17 = V_10 -> V_15 [ V_13 ] ;
if ( V_17 ) {
enum V_18 V_19 = F_10 ( V_17 ) ;
int V_73 = V_64 [ V_19 ] ;
if ( V_73 > 0 ) {
const struct V_74 * V_75 =
F_47 ( F_48 ( V_17 -> V_26 ) ) ;
V_72 [ V_73 - 1 ] = V_75 -> V_76 ;
}
V_56 |= F_49 ( V_10 -> V_77 , V_19 , V_58 [ V_73 ] ) ;
}
}
F_50 ( ! V_56 ) ;
for ( V_13 = 0 ; V_13 < 4 ; V_13 ++ ) {
T_1 V_78 ;
if ( V_72 [ V_13 ] ) {
V_78 = F_51 ( V_79 ) |
F_52 ( V_79 ) |
V_80 ;
} else {
V_78 = F_51 ( V_81 ) |
F_52 ( V_82 ) ;
}
F_14 ( V_1 , F_53 ( V_20 , V_13 ) , 0xff ) ;
F_14 ( V_1 , F_54 ( V_20 , V_13 ) , 0x00 ) ;
F_14 ( V_1 , F_55 ( V_20 , V_13 ) , V_78 ) ;
F_14 ( V_1 , F_56 ( V_20 , V_13 ) , 1 ) ;
F_14 ( V_1 , F_57 ( V_20 , V_13 ) , 0 ) ;
F_14 ( V_1 , F_58 ( V_20 , V_13 ) , 0 ) ;
F_14 ( V_1 , F_59 ( V_20 , V_13 ) , 0 ) ;
F_14 ( V_1 , F_60 ( V_20 , V_13 ) , 0 ) ;
}
F_14 ( V_1 , V_83 , V_56 ) ;
}
static int F_61 ( struct V_2 * V_3 ,
struct V_54 * V_50 ,
struct V_54 * V_55 ,
int V_84 , int V_85 ,
struct V_23 * V_25 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_86 V_87 = V_10 -> V_87 ;
int V_88 , V_20 = V_10 -> V_20 ;
V_50 = V_55 ;
F_13 ( L_3 ,
V_10 -> V_21 , V_50 -> V_11 . V_39 , V_50 -> V_21 ,
V_50 -> V_89 , V_50 -> clock ,
V_50 -> V_90 , V_50 -> V_91 ,
V_50 -> V_92 , V_50 -> V_93 ,
V_50 -> V_94 , V_50 -> V_95 ,
V_50 -> V_96 , V_50 -> V_97 ,
V_50 -> type , V_50 -> V_36 ) ;
F_16 ( V_3 -> V_27 -> V_26 ) ;
V_88 = F_62 ( V_10 -> V_17 , V_3 , V_3 -> V_27 -> V_26 ,
0 , 0 , V_50 -> V_90 , V_50 -> V_94 ,
V_84 << 16 , V_85 << 16 ,
V_50 -> V_90 << 16 , V_50 -> V_94 << 16 ) ;
if ( V_88 ) {
F_28 ( V_3 -> V_27 -> V_26 ) ;
F_63 ( V_3 -> V_6 -> V_6 , L_4 ,
V_10 -> V_21 , V_88 ) ;
return V_88 ;
}
F_14 ( V_1 , F_64 ( V_87 ) ,
F_65 ( V_50 -> V_90 ) |
F_66 ( V_50 -> V_94 ) ) ;
F_14 ( V_1 , F_67 ( V_87 ) , 0 ) ;
F_14 ( V_1 , F_68 ( V_87 ) ,
V_3 -> V_27 -> V_26 -> V_98 [ 0 ] ) ;
F_14 ( V_1 , F_69 ( V_87 ) ,
F_70 ( 0 ) |
F_71 ( 0 ) ) ;
F_14 ( V_1 , F_72 ( V_20 ) , 0 ) ;
F_14 ( V_1 , F_73 ( V_20 ) ,
F_74 ( V_50 -> V_90 ) |
F_75 ( V_50 -> V_94 ) ) ;
F_14 ( V_1 , F_76 ( V_20 ) ,
V_3 -> V_27 -> V_26 -> V_98 [ 0 ] ) ;
F_14 ( V_1 , F_77 ( V_20 ) , 1 ) ;
if ( V_87 == V_99 ) {
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
F_37 ( V_3 , V_100 ) ;
}
static void F_80 ( struct V_2 * V_3 )
{
F_37 ( V_3 , V_52 ) ;
F_8 ( V_3 ) ;
F_40 ( F_1 ( V_3 ) ) ;
}
static int F_81 ( struct V_2 * V_3 , int V_84 , int V_85 ,
struct V_23 * V_25 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_16 * V_17 = V_10 -> V_17 ;
struct V_54 * V_50 = & V_3 -> V_50 ;
int V_88 ;
F_16 ( V_3 -> V_27 -> V_26 ) ;
V_88 = F_62 ( V_17 , V_3 , V_3 -> V_27 -> V_26 ,
0 , 0 , V_50 -> V_90 , V_50 -> V_94 ,
V_84 << 16 , V_85 << 16 ,
V_50 -> V_90 << 16 , V_50 -> V_94 << 16 ) ;
if ( V_88 ) {
F_28 ( V_3 -> V_27 -> V_26 ) ;
return V_88 ;
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
T_1 V_101 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_33 * V_6 = V_3 -> V_6 ;
struct V_102 * V_103 ;
unsigned long V_36 ;
if ( V_10 -> V_35 ) {
F_63 ( V_6 -> V_6 , L_6 ) ;
return - V_104 ;
}
V_103 = F_84 ( V_24 , 0 ) ;
F_20 ( & V_6 -> V_37 , V_36 ) ;
V_10 -> V_35 = V_35 ;
F_22 ( & V_6 -> V_37 , V_36 ) ;
F_15 ( V_3 , V_24 ) ;
return F_85 ( V_103 , & V_10 -> F_23 ) ;
}
static int F_86 ( struct V_2 * V_3 ,
struct V_105 * V_106 , T_2 V_44 )
{
return - V_107 ;
}
static void F_87 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_86 V_87 = V_10 -> V_87 ;
unsigned long V_36 ;
F_20 ( & V_10 -> V_108 . V_109 , V_36 ) ;
if ( V_10 -> V_108 . V_110 ) {
struct V_102 * V_111 = V_10 -> V_108 . V_111 ;
struct V_102 * V_112 = V_10 -> V_108 . V_113 ;
T_1 V_114 = V_10 -> V_108 . V_115 ;
if ( V_111 ) {
F_88 ( V_111 ) ;
F_89 ( V_111 , V_1 -> V_39 , & V_114 ) ;
F_14 ( V_1 , F_90 ( V_87 ) ,
F_91 ( V_10 -> V_108 . V_116 ) |
F_92 ( V_10 -> V_108 . V_117 ) ) ;
F_14 ( V_1 , F_93 ( V_87 ) , V_114 ) ;
F_14 ( V_1 , F_94 ( V_87 ) ,
F_95 ( V_118 ) |
V_119 ) ;
} else {
F_14 ( V_1 , F_93 ( V_87 ) ,
V_1 -> V_120 ) ;
}
if ( V_112 )
F_17 ( & V_10 -> V_47 , V_112 ) ;
V_10 -> V_108 . V_113 = V_111 ;
V_10 -> V_108 . V_110 = false ;
}
F_14 ( V_1 , F_96 ( V_87 ) ,
F_97 ( V_10 -> V_108 . V_84 ) |
F_98 ( V_10 -> V_108 . V_85 ) ) ;
F_22 ( & V_10 -> V_108 . V_109 , V_36 ) ;
}
static int F_99 ( struct V_2 * V_3 ,
struct V_31 * V_38 , T_1 V_121 ,
T_1 V_116 , T_1 V_117 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_33 * V_6 = V_3 -> V_6 ;
struct V_102 * V_122 , * V_123 ;
unsigned long V_36 ;
T_1 V_114 ;
int V_88 ;
if ( ( V_116 > V_124 ) || ( V_117 > V_125 ) ) {
F_63 ( V_6 -> V_6 , L_7 , V_116 , V_117 ) ;
return - V_107 ;
}
if ( V_121 ) {
V_122 = F_100 ( V_6 , V_38 , V_121 ) ;
if ( ! V_122 )
return - V_126 ;
} else {
V_122 = NULL ;
}
if ( V_122 ) {
V_88 = F_101 ( V_122 , V_1 -> V_39 , & V_114 ) ;
if ( V_88 )
goto V_127;
} else {
V_114 = 0 ;
}
F_20 ( & V_10 -> V_108 . V_109 , V_36 ) ;
V_123 = V_10 -> V_108 . V_111 ;
V_10 -> V_108 . V_111 = V_122 ;
V_10 -> V_108 . V_115 = V_114 ;
V_10 -> V_108 . V_116 = V_116 ;
V_10 -> V_108 . V_117 = V_117 ;
V_10 -> V_108 . V_110 = true ;
F_22 ( & V_10 -> V_108 . V_109 , V_36 ) ;
if ( V_123 ) {
F_17 ( & V_10 -> V_47 , V_123 ) ;
}
F_4 ( V_3 , V_128 ) ;
return 0 ;
V_127:
F_32 ( V_122 ) ;
return V_88 ;
}
static int F_102 ( struct V_2 * V_3 , int V_84 , int V_85 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
unsigned long V_36 ;
F_20 ( & V_10 -> V_108 . V_109 , V_36 ) ;
V_10 -> V_108 . V_84 = V_84 ;
V_10 -> V_108 . V_85 = V_85 ;
F_22 ( & V_10 -> V_108 . V_109 , V_36 ) ;
F_8 ( V_3 ) ;
F_4 ( V_3 , V_128 ) ;
return 0 ;
}
static void F_103 ( struct V_129 * V_130 , T_1 V_131 )
{
struct V_10 * V_10 = F_24 ( V_130 , struct V_10 , V_12 ) ;
struct V_2 * V_3 = & V_10 -> V_11 ;
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
unsigned V_9 ;
F_39 ( & F_1 ( V_3 ) -> V_11 , & V_10 -> V_12 ) ;
V_9 = F_104 ( & V_10 -> V_9 , 0 ) ;
if ( V_9 & V_30 ) {
F_19 ( V_3 , NULL ) ;
F_105 ( & V_10 -> V_28 , V_5 -> V_132 ) ;
}
if ( V_9 & V_128 ) {
F_87 ( V_3 ) ;
F_105 ( & V_10 -> V_47 , V_5 -> V_132 ) ;
}
}
static void F_106 ( struct V_129 * V_130 , T_1 V_131 )
{
struct V_10 * V_10 = F_24 ( V_130 , struct V_10 , V_53 ) ;
struct V_2 * V_3 = & V_10 -> V_11 ;
F_13 ( L_8 , V_10 -> V_21 , V_131 ) ;
F_8 ( V_3 ) ;
}
T_1 F_107 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
return V_10 -> V_12 . V_133 ;
}
void F_108 ( struct V_2 * V_3 , struct V_31 * V_32 )
{
F_13 ( L_9 , V_32 ) ;
F_19 ( V_3 , V_32 ) ;
}
void F_109 ( struct V_2 * V_3 , T_1 V_134 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_14 ( V_1 , F_110 ( V_10 -> V_87 ) , V_134 ) ;
}
void F_111 ( struct V_2 * V_3 , enum V_135 V_136 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_137 ;
V_137 = F_112 ( V_1 , V_138 ) ;
switch ( V_10 -> V_87 ) {
case V_139 :
V_137 &= ~ V_140 ;
V_137 |= F_113 ( V_136 ) ;
break;
case V_141 :
V_137 &= ~ V_142 ;
V_137 |= F_114 ( V_136 ) ;
break;
case V_99 :
V_137 &= ~ V_143 ;
V_137 |= F_115 ( V_136 ) ;
break;
}
if ( V_136 == V_144 ) {
V_137 &= ~ V_145 ;
V_137 |= V_146 ;
V_10 -> V_77 = 0 ;
} else if ( V_136 == V_147 ) {
V_137 &= ~ V_146 ;
V_137 |= V_145 ;
V_10 -> V_77 = 0 ;
} else if ( V_136 == V_148 ) {
V_10 -> V_77 = 1 ;
}
F_42 ( V_3 ) ;
F_13 ( L_10 , V_10 -> V_21 , V_137 ) ;
F_14 ( V_1 , V_138 , V_137 ) ;
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
if ( V_10 -> V_51 && ( V_17 != V_10 -> V_17 ) )
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
struct V_16 * V_17 , int V_39 , int V_149 ,
enum V_86 V_150 )
{
struct V_2 * V_3 = NULL ;
struct V_10 * V_10 ;
int V_88 ;
V_10 = F_121 ( sizeof( * V_10 ) , V_151 ) ;
if ( ! V_10 ) {
V_88 = - V_152 ;
goto V_127;
}
V_3 = & V_10 -> V_11 ;
V_10 -> V_17 = V_17 ;
V_10 -> V_39 = V_39 ;
V_10 -> V_20 = V_149 ;
V_10 -> V_87 = V_150 ;
V_10 -> V_12 . V_133 = F_122 ( V_10 -> V_87 ) ;
V_10 -> V_12 . V_130 = F_103 ;
V_10 -> V_53 . V_133 = F_123 ( V_10 -> V_87 ) ;
V_10 -> V_53 . V_130 = F_106 ;
snprintf ( V_10 -> V_21 , sizeof( V_10 -> V_21 ) , L_11 ,
V_153 [ V_150 ] , V_149 ) ;
F_124 ( & V_10 -> V_108 . V_109 ) ;
V_88 = F_125 ( & V_10 -> V_28 , 16 ,
L_12 , F_26 ) ;
if ( V_88 )
goto V_127;
V_88 = F_125 ( & V_10 -> V_47 , 64 ,
L_13 , F_30 ) ;
F_126 ( & V_10 -> F_23 , F_23 ) ;
F_127 ( V_6 , V_3 , V_17 , NULL , & V_154 ) ;
F_128 ( V_3 , & V_155 ) ;
F_129 ( V_10 -> V_17 , & V_3 -> V_11 ) ;
return V_3 ;
V_127:
if ( V_3 )
F_33 ( V_3 ) ;
return F_130 ( V_88 ) ;
}
