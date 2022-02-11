static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_4 ;
unsigned int V_6 = V_2 -> V_7 -> V_8 ? V_9 : V_10 ;
F_2 ( V_4 , V_6 ) ;
}
static int F_3 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_1 * V_2 =
F_4 ( V_14 , struct V_1 , V_16 ) ;
int V_17 ;
V_17 = F_5 ( V_12 ) ;
if ( V_17 == 0 )
F_1 ( V_2 ) ;
return V_17 ;
}
static int F_6 ( int V_18 , struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_1 * V_2 =
F_4 ( V_14 , struct V_1 , V_16 ) ;
int V_17 ;
V_17 = F_7 ( V_18 , V_12 ) ;
if ( V_17 == 0 )
F_1 ( V_2 ) ;
return V_17 ;
}
static int F_8 ( struct V_19 * V_20 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_1 * V_2 =
F_4 ( V_14 , struct V_1 , V_16 ) ;
int V_17 ;
V_17 = F_9 ( V_20 , V_12 ) ;
if ( V_17 == 0 )
F_1 ( V_2 ) ;
return V_17 ;
}
static int F_10 ( struct V_13 * V_16 ,
struct V_21 * V_22 )
{
struct V_1 * V_2 =
F_4 ( V_16 , struct V_1 , V_16 ) ;
struct V_23 * V_5 ;
struct V_24 * V_25 = V_16 -> V_25 ;
struct V_26 * V_27 = F_11 ( V_25 ) ;
struct V_28 * V_29 = & V_27 -> V_29 ;
struct V_30 V_31 = {} ;
struct V_3 * V_4 ;
int V_32 , V_17 ;
if ( V_22 -> V_33 == 24 )
V_22 -> V_33 = 32 ;
V_31 . V_34 = V_22 -> V_35 ;
V_31 . V_36 = V_22 -> V_37 ;
V_31 . V_38 [ 0 ] = F_12 ( V_31 . V_34 *
F_13 ( V_22 -> V_33 , 8 ) , 64 ) ;
V_31 . V_39 = F_14 ( V_22 -> V_33 ,
V_22 -> V_40 ) ;
V_32 = V_31 . V_38 [ 0 ] * V_31 . V_36 ;
V_32 = F_15 ( V_32 ) ;
V_4 = NULL ;
if ( V_32 * 2 < V_29 -> V_41 )
V_4 = F_16 ( V_27 , V_32 ) ;
if ( V_4 == NULL )
V_4 = F_17 ( V_27 , V_32 ) ;
if ( F_18 ( V_4 ) ) {
F_19 ( L_1 ) ;
V_17 = F_20 ( V_4 ) ;
goto V_42;
}
V_5 = F_21 ( V_4 , & V_31 ) ;
if ( F_18 ( V_5 ) ) {
V_17 = F_20 ( V_5 ) ;
goto V_43;
}
V_2 -> V_5 = F_22 ( V_5 ) ;
return 0 ;
V_43:
F_23 ( V_4 ) ;
V_42:
return V_17 ;
}
static int F_24 ( struct V_13 * V_16 ,
struct V_21 * V_22 )
{
struct V_1 * V_2 =
F_4 ( V_16 , struct V_1 , V_16 ) ;
struct V_44 * V_45 = V_2 -> V_5 ;
struct V_24 * V_25 = V_16 -> V_25 ;
struct V_26 * V_27 = F_11 ( V_25 ) ;
struct V_46 * V_47 = V_27 -> V_48 . V_47 ;
struct V_28 * V_29 = & V_27 -> V_29 ;
struct V_11 * V_12 ;
struct V_23 * V_5 ;
struct V_49 * V_7 ;
bool V_50 = false ;
void T_1 * V_51 ;
int V_17 ;
if ( V_45 &&
( V_22 -> V_52 > V_45 -> V_53 . V_34 ||
V_22 -> V_54 > V_45 -> V_53 . V_36 ) ) {
F_25 ( L_2
L_3 ,
V_45 -> V_53 . V_34 , V_45 -> V_53 . V_36 ,
V_22 -> V_52 , V_22 -> V_54 ) ;
F_26 ( & V_45 -> V_53 ) ;
V_45 = V_2 -> V_5 = NULL ;
}
if ( ! V_45 || F_27 ( ! V_45 -> V_4 ) ) {
F_25 ( L_4 ) ;
V_17 = F_10 ( V_16 , V_22 ) ;
if ( V_17 )
return V_17 ;
V_45 = V_2 -> V_5 ;
} else {
F_25 ( L_5 ) ;
V_50 = true ;
V_22 -> V_52 = V_45 -> V_53 . V_34 ;
V_22 -> V_54 = V_45 -> V_53 . V_36 ;
}
F_28 ( & V_25 -> V_55 ) ;
V_7 = F_29 ( & V_2 -> V_5 -> V_53 , V_56 ) ;
if ( F_18 ( V_7 ) ) {
V_17 = F_20 ( V_7 ) ;
goto V_57;
}
V_12 = F_30 ( V_16 ) ;
if ( F_18 ( V_12 ) ) {
F_19 ( L_6 ) ;
V_17 = F_20 ( V_12 ) ;
goto V_58;
}
V_12 -> V_15 = V_16 ;
V_5 = & V_2 -> V_5 -> V_53 ;
V_2 -> V_16 . V_5 = V_5 ;
strcpy ( V_12 -> V_59 . V_60 , L_7 ) ;
V_12 -> V_61 = V_62 | V_63 ;
V_12 -> V_64 = & V_65 ;
V_12 -> V_66 -> V_67 [ 0 ] . V_53 = V_25 -> V_68 . V_69 ;
V_12 -> V_66 -> V_67 [ 0 ] . V_32 = V_29 -> V_70 ;
V_12 -> V_59 . V_71 = V_25 -> V_68 . V_69 + F_31 ( V_7 ) ;
V_12 -> V_59 . V_72 = V_7 -> V_73 . V_32 ;
V_51 = F_32 ( V_7 ) ;
if ( F_18 ( V_51 ) ) {
F_19 ( L_8 ) ;
V_17 = F_20 ( V_51 ) ;
goto V_58;
}
V_12 -> V_74 = V_51 ;
V_12 -> V_75 = V_7 -> V_73 . V_32 ;
V_12 -> V_76 = true ;
F_33 ( V_12 , V_5 -> V_38 [ 0 ] , V_5 -> V_77 -> V_78 ) ;
F_34 ( V_12 , & V_2 -> V_16 , V_22 -> V_52 , V_22 -> V_54 ) ;
if ( V_45 -> V_4 -> V_79 && ! V_50 )
F_35 ( V_12 -> V_74 , 0 , V_12 -> V_75 ) ;
F_25 ( L_9 ,
V_5 -> V_34 , V_5 -> V_36 , F_31 ( V_7 ) ) ;
V_2 -> V_7 = V_7 ;
F_36 ( & V_25 -> V_55 ) ;
F_37 ( V_47 , V_12 ) ;
return 0 ;
V_58:
F_38 ( V_7 ) ;
V_57:
F_36 ( & V_25 -> V_55 ) ;
return V_17 ;
}
static void F_39 ( struct V_80 * V_81 , T_2 V_82 , T_2 V_83 ,
T_2 V_84 , int V_85 )
{
struct V_86 * V_86 = F_40 ( V_81 ) ;
V_86 -> V_87 [ V_85 ] = V_82 >> 8 ;
V_86 -> V_88 [ V_85 ] = V_83 >> 8 ;
V_86 -> V_89 [ V_85 ] = V_84 >> 8 ;
}
static void F_41 ( struct V_80 * V_81 , T_2 * V_82 , T_2 * V_83 ,
T_2 * V_84 , int V_85 )
{
struct V_86 * V_86 = F_40 ( V_81 ) ;
* V_82 = V_86 -> V_87 [ V_85 ] << 8 ;
* V_83 = V_86 -> V_88 [ V_85 ] << 8 ;
* V_84 = V_86 -> V_89 [ V_85 ] << 8 ;
}
static struct V_90 *
F_42 ( struct V_13 * V_14 , struct V_80 * V_81 )
{
int V_91 ;
for ( V_91 = 0 ; V_91 < V_14 -> V_92 ; V_91 ++ )
if ( V_14 -> V_93 [ V_91 ] . V_94 . V_81 == V_81 )
return & V_14 -> V_93 [ V_91 ] ;
return NULL ;
}
static bool F_43 ( struct V_13 * V_14 ,
struct V_90 * * V_95 ,
struct V_96 * * V_97 ,
struct V_98 * V_99 ,
bool * V_100 , int V_34 , int V_36 )
{
struct V_26 * V_27 = F_11 ( V_14 -> V_25 ) ;
unsigned long V_101 , V_102 , V_103 ;
unsigned int V_104 = F_44 ( V_14 -> V_105 , V_106 ) ;
int V_91 , V_107 ;
bool * V_108 ;
bool V_109 = true ;
int V_110 = 0 ;
int V_111 = 0 ;
V_108 = F_45 ( V_104 , sizeof( bool ) , V_112 ) ;
if ( ! V_108 )
return false ;
memcpy ( V_108 , V_100 , V_104 ) ;
V_103 = F_46 ( V_104 - 1 , 0 ) ;
V_101 = 0 ;
V_113:
V_102 = V_101 ;
for ( V_91 = 0 ; V_91 < V_104 ; V_91 ++ ) {
struct V_114 * V_115 ;
struct V_116 * V_117 ;
struct V_118 * V_119 ;
struct V_90 * V_120 ;
struct V_86 * V_86 ;
V_115 = V_14 -> V_121 [ V_91 ] ;
V_117 = V_115 -> V_117 ;
if ( V_101 & F_47 ( V_91 ) )
continue;
if ( V_102 == 0 && ! V_117 -> V_122 )
continue;
if ( V_117 -> V_123 == V_124 )
V_111 ++ ;
if ( ! V_100 [ V_91 ] ) {
F_25 ( L_10 ,
V_117 -> V_125 ) ;
V_101 |= F_47 ( V_91 ) ;
continue;
}
if ( V_117 -> V_126 == V_127 ) {
F_25 ( L_11 ,
V_117 -> V_125 ) ;
V_100 [ V_91 ] = false ;
continue;
}
V_119 = V_117 -> V_128 -> V_129 ;
if ( ! V_119 || F_27 ( ! V_117 -> V_128 -> V_81 ) ) {
if ( V_117 -> V_126 > V_127 )
goto V_130;
F_25 ( L_12 ,
V_117 -> V_125 ) ;
V_100 [ V_91 ] = false ;
V_101 |= F_47 ( V_91 ) ;
continue;
}
V_110 ++ ;
V_86 = F_40 ( V_117 -> V_128 -> V_81 ) ;
for ( V_107 = 0 ; V_107 < 256 ; V_107 ++ ) {
V_86 -> V_87 [ V_107 ] = V_107 ;
V_86 -> V_88 [ V_107 ] = V_107 ;
V_86 -> V_89 [ V_107 ] = V_107 ;
}
V_120 = F_42 ( V_14 ,
V_117 -> V_128 -> V_81 ) ;
for ( V_107 = 0 ; V_107 < V_104 ; V_107 ++ ) {
if ( V_95 [ V_107 ] == V_120 ) {
F_25 ( L_13 ) ;
goto V_130;
}
}
F_25 ( L_14 ,
V_117 -> V_125 ) ;
V_97 [ V_91 ] = F_48 ( V_115 ) ;
if ( ! V_97 [ V_91 ] ) {
F_25 ( L_15 ,
V_117 -> V_125 , V_117 -> V_122 ) ;
V_97 [ V_91 ] = F_49 ( V_115 , V_34 ,
V_36 ) ;
}
if ( ! V_97 [ V_91 ] && ! F_50 ( & V_117 -> V_97 ) ) {
F_25 ( L_16 ,
V_117 -> V_125 ) ;
V_97 [ V_91 ] = F_51 ( & V_117 -> V_97 ,
struct V_96 ,
V_131 ) ;
}
if ( ! V_97 [ V_91 ] ) {
F_25 ( L_17 ,
V_117 -> V_125 ) ;
V_97 [ V_91 ] = & V_117 -> V_128 -> V_81 -> V_132 ;
}
V_95 [ V_91 ] = V_120 ;
F_25 ( L_18 ,
V_117 -> V_125 ,
V_117 -> V_128 -> V_81 -> V_53 . V_60 ,
V_117 -> V_128 -> V_81 -> V_125 ,
V_97 [ V_91 ] -> V_133 , V_97 [ V_91 ] -> V_134 ,
V_97 [ V_91 ] -> V_61 & V_135 ? L_19 : L_20 ) ;
V_109 = false ;
V_101 |= F_47 ( V_91 ) ;
}
if ( ( V_101 & V_103 ) != V_103 && V_101 != V_102 )
goto V_113;
if ( V_110 != V_111 &&
V_110 < F_52 ( V_27 ) -> V_136 ) {
F_25 ( L_21 ) ;
F_25 ( L_22 , V_110 ,
V_111 ) ;
V_109 = true ;
}
if ( V_109 ) {
V_130:
F_25 ( L_23 ) ;
memcpy ( V_100 , V_108 , V_104 ) ;
F_53 ( V_108 ) ;
return false ;
}
F_53 ( V_108 ) ;
return true ;
}
static void F_54 ( struct V_1 * V_2 )
{
F_55 ( & V_2 -> V_16 ) ;
F_56 ( & V_2 -> V_16 ) ;
if ( V_2 -> V_7 ) {
F_28 ( & V_2 -> V_16 . V_25 -> V_55 ) ;
F_38 ( V_2 -> V_7 ) ;
F_36 ( & V_2 -> V_16 . V_25 -> V_55 ) ;
}
if ( V_2 -> V_5 )
F_57 ( & V_2 -> V_5 -> V_53 ) ;
F_53 ( V_2 ) ;
}
static bool F_58 ( struct V_24 * V_25 ,
struct V_1 * V_2 )
{
struct V_44 * V_5 = NULL ;
struct V_80 * V_81 ;
struct V_86 * V_86 ;
unsigned int V_137 = 0 ;
F_59 (dev, crtc) {
struct V_3 * V_4 =
F_60 ( V_81 -> V_138 -> V_128 -> V_5 ) ;
V_86 = F_40 ( V_81 ) ;
if ( ! V_81 -> V_128 -> V_139 || ! V_4 ) {
F_25 ( L_24 ,
F_61 ( V_86 -> V_140 ) ) ;
continue;
}
if ( V_4 -> V_53 . V_32 > V_137 ) {
F_25 ( L_25 ,
F_61 ( V_86 -> V_140 ) ) ;
V_5 = F_22 ( V_81 -> V_138 -> V_128 -> V_5 ) ;
V_137 = V_4 -> V_53 . V_32 ;
}
}
if ( ! V_5 ) {
F_25 ( L_26 ) ;
goto V_141;
}
F_59 (dev, crtc) {
unsigned int V_142 ;
V_86 = F_40 ( V_81 ) ;
if ( ! V_81 -> V_128 -> V_139 ) {
F_25 ( L_27 ,
F_61 ( V_86 -> V_140 ) ) ;
continue;
}
F_25 ( L_28 ,
F_61 ( V_86 -> V_140 ) ) ;
V_142 = V_86 -> V_143 -> V_53 . V_144 . V_145 ;
V_142 = V_142 * V_5 -> V_53 . V_77 -> V_146 [ 0 ] ;
if ( V_5 -> V_53 . V_38 [ 0 ] < V_142 ) {
F_25 ( L_29 ,
F_61 ( V_86 -> V_140 ) ,
V_142 , V_5 -> V_53 . V_38 [ 0 ] ) ;
V_5 = NULL ;
break;
}
V_142 = V_86 -> V_143 -> V_53 . V_144 . V_147 ;
V_142 = F_62 ( & V_5 -> V_53 , 0 , V_142 ) ;
V_142 *= V_5 -> V_53 . V_38 [ 0 ] ;
F_25 ( L_30 ,
F_61 ( V_86 -> V_140 ) ,
V_86 -> V_143 -> V_53 . V_144 . V_145 ,
V_86 -> V_143 -> V_53 . V_144 . V_147 ,
V_5 -> V_53 . V_77 -> V_146 [ 0 ] * 8 ,
V_142 ) ;
if ( V_142 > V_137 ) {
F_25 ( L_31 ,
F_61 ( V_86 -> V_140 ) ,
V_142 , V_137 ) ;
V_5 = NULL ;
break;
}
F_25 ( L_32 ,
F_61 ( V_86 -> V_140 ) ,
V_137 , V_142 ) ;
}
if ( ! V_5 ) {
F_25 ( L_33 ) ;
goto V_141;
}
V_2 -> V_148 = V_5 -> V_53 . V_77 -> V_146 [ 0 ] * 8 ;
V_2 -> V_5 = V_5 ;
F_63 ( & V_2 -> V_5 -> V_53 ) ;
F_59 (dev, crtc) {
V_86 = F_40 ( V_81 ) ;
if ( ! V_81 -> V_128 -> V_139 )
continue;
F_64 ( ! V_81 -> V_138 -> V_5 ,
L_34 ,
V_81 -> V_53 . V_60 ) ;
}
F_25 ( L_35 ) ;
return true ;
V_141:
return false ;
}
static void F_65 ( struct V_149 * V_150 )
{
F_66 ( & F_4 ( V_150 ,
struct V_26 ,
V_151 ) -> V_48 ,
V_152 ,
true ) ;
}
int F_67 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = F_11 ( V_25 ) ;
struct V_1 * V_2 ;
int V_17 ;
if ( F_27 ( F_52 ( V_27 ) -> V_136 == 0 ) )
return - V_153 ;
V_2 = F_68 ( sizeof( struct V_1 ) , V_112 ) ;
if ( V_2 == NULL )
return - V_154 ;
F_69 ( V_25 , & V_2 -> V_16 , & V_155 ) ;
if ( ! F_58 ( V_25 , V_2 ) )
V_2 -> V_148 = 32 ;
V_17 = F_70 ( V_25 , & V_2 -> V_16 , 4 ) ;
if ( V_17 ) {
F_53 ( V_2 ) ;
return V_17 ;
}
V_27 -> V_156 = V_2 ;
F_71 ( & V_27 -> V_151 , F_65 ) ;
F_72 ( & V_2 -> V_16 ) ;
return 0 ;
}
static void F_73 ( void * V_157 , T_3 V_158 )
{
struct V_1 * V_2 = V_157 ;
if ( F_74 ( & V_2 -> V_16 ,
V_2 -> V_148 ) )
F_75 ( V_2 -> V_16 . V_25 ) ;
}
void F_76 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_11 ( V_25 ) -> V_156 ;
if ( ! V_2 )
return;
V_2 -> V_158 = F_77 ( F_73 , V_2 ) ;
}
static void F_78 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_158 )
return;
F_79 ( V_2 -> V_158 + 1 ) ;
V_2 -> V_158 = 0 ;
}
void F_75 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = F_11 ( V_25 ) ;
struct V_1 * V_2 = V_27 -> V_156 ;
if ( ! V_2 )
return;
F_80 ( & V_27 -> V_151 ) ;
if ( ! F_81 () )
F_78 ( V_2 ) ;
F_54 ( V_2 ) ;
V_27 -> V_156 = NULL ;
}
void F_66 ( struct V_24 * V_25 , int V_128 , bool V_159 )
{
struct V_26 * V_27 = F_11 ( V_25 ) ;
struct V_1 * V_2 = V_27 -> V_156 ;
struct V_11 * V_12 ;
if ( ! V_2 || ! V_2 -> V_7 )
return;
V_12 = V_2 -> V_16 . V_156 ;
if ( V_159 ) {
if ( V_128 != V_152 )
F_82 ( & V_27 -> V_151 ) ;
F_83 () ;
} else {
F_27 ( V_128 != V_152 ) ;
if ( ! F_84 () ) {
F_85 ( & V_27 -> V_151 ) ;
return;
}
}
if ( V_128 == V_152 && V_2 -> V_5 -> V_4 -> V_79 )
F_35 ( V_12 -> V_74 , 0 , V_12 -> V_75 ) ;
F_86 ( & V_2 -> V_16 , V_128 ) ;
F_87 () ;
}
void F_88 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_11 ( V_25 ) -> V_156 ;
if ( V_2 && V_2 -> V_7 )
F_89 ( & V_2 -> V_16 ) ;
}
void F_90 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_11 ( V_25 ) -> V_156 ;
if ( ! V_2 )
return;
F_78 ( V_2 ) ;
if ( ! V_2 -> V_7 )
return;
if ( F_91 ( & V_2 -> V_16 ) == 0 )
F_1 ( V_2 ) ;
}
