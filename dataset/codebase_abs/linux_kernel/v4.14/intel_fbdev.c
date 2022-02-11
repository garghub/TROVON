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
V_12 -> V_61 = & V_62 ;
V_12 -> V_63 -> V_64 [ 0 ] . V_53 = V_25 -> V_65 . V_66 ;
V_12 -> V_63 -> V_64 [ 0 ] . V_32 = V_29 -> V_67 ;
V_12 -> V_59 . V_68 = V_25 -> V_65 . V_66 + F_31 ( V_7 ) ;
V_12 -> V_59 . V_69 = V_7 -> V_70 . V_32 ;
V_51 = F_32 ( V_7 ) ;
if ( F_18 ( V_51 ) ) {
F_19 ( L_8 ) ;
V_17 = F_20 ( V_51 ) ;
goto V_58;
}
V_12 -> V_71 = V_51 ;
V_12 -> V_72 = V_7 -> V_70 . V_32 ;
V_12 -> V_73 = true ;
F_33 ( V_12 , V_5 -> V_38 [ 0 ] , V_5 -> V_74 -> V_75 ) ;
F_34 ( V_12 , & V_2 -> V_16 , V_22 -> V_52 , V_22 -> V_54 ) ;
if ( V_45 -> V_4 -> V_76 && ! V_50 )
F_35 ( V_12 -> V_71 , 0 , V_12 -> V_72 ) ;
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
static struct V_77 *
F_39 ( struct V_13 * V_14 , struct V_78 * V_79 )
{
int V_80 ;
for ( V_80 = 0 ; V_80 < V_14 -> V_81 ; V_80 ++ )
if ( V_14 -> V_82 [ V_80 ] . V_83 . V_79 == V_79 )
return & V_14 -> V_82 [ V_80 ] ;
return NULL ;
}
static bool F_40 ( struct V_13 * V_14 ,
struct V_77 * * V_84 ,
struct V_85 * * V_86 ,
struct V_87 * V_88 ,
bool * V_89 , int V_34 , int V_36 )
{
struct V_26 * V_27 = F_11 ( V_14 -> V_25 ) ;
unsigned long V_90 , V_91 , V_92 ;
unsigned int V_93 = F_41 ( V_14 -> V_94 , V_95 ) ;
int V_80 , V_96 ;
bool * V_97 ;
bool V_98 = true , V_17 = true ;
int V_99 = 0 ;
int V_100 = 0 ;
struct V_101 V_102 ;
V_97 = F_42 ( V_93 , sizeof( bool ) , V_103 ) ;
if ( ! V_97 )
return false ;
F_43 ( & V_102 , 0 ) ;
while ( F_44 ( V_14 -> V_25 , & V_102 ) != 0 )
F_45 ( & V_102 ) ;
memcpy ( V_97 , V_89 , V_93 ) ;
V_92 = F_46 ( V_93 - 1 , 0 ) ;
V_90 = 0 ;
V_104:
V_91 = V_90 ;
for ( V_80 = 0 ; V_80 < V_93 ; V_80 ++ ) {
struct V_105 * V_106 ;
struct V_107 * V_108 ;
struct V_109 * V_110 ;
struct V_77 * V_111 ;
V_106 = V_14 -> V_112 [ V_80 ] ;
V_108 = V_106 -> V_108 ;
if ( V_90 & F_47 ( V_80 ) )
continue;
if ( V_91 == 0 && ! V_108 -> V_113 )
continue;
if ( V_108 -> V_114 == V_115 )
V_100 ++ ;
if ( ! V_89 [ V_80 ] ) {
F_25 ( L_10 ,
V_108 -> V_116 ) ;
V_90 |= F_47 ( V_80 ) ;
continue;
}
if ( V_108 -> V_117 == V_118 ) {
F_25 ( L_11 ,
V_108 -> V_116 ) ;
V_89 [ V_80 ] = false ;
continue;
}
V_110 = V_108 -> V_119 -> V_120 ;
if ( ! V_110 || F_27 ( ! V_108 -> V_119 -> V_79 ) ) {
if ( V_108 -> V_117 > V_118 )
goto V_121;
F_25 ( L_12 ,
V_108 -> V_116 ) ;
V_89 [ V_80 ] = false ;
V_90 |= F_47 ( V_80 ) ;
continue;
}
V_99 ++ ;
V_111 = F_39 ( V_14 ,
V_108 -> V_119 -> V_79 ) ;
for ( V_96 = 0 ; V_96 < V_93 ; V_96 ++ ) {
if ( V_84 [ V_96 ] == V_111 ) {
F_25 ( L_13 ) ;
goto V_121;
}
}
F_25 ( L_14 ,
V_108 -> V_116 ) ;
V_86 [ V_80 ] = F_48 ( V_106 ) ;
if ( ! V_86 [ V_80 ] ) {
F_25 ( L_15 ,
V_108 -> V_116 , V_108 -> V_113 ) ;
V_86 [ V_80 ] = F_49 ( V_106 , V_34 ,
V_36 ) ;
}
if ( ! V_86 [ V_80 ] && ! F_50 ( & V_108 -> V_86 ) ) {
F_25 ( L_16 ,
V_108 -> V_116 ) ;
V_86 [ V_80 ] = F_51 ( & V_108 -> V_86 ,
struct V_85 ,
V_122 ) ;
}
if ( ! V_86 [ V_80 ] ) {
F_25 ( L_17 ,
V_108 -> V_116 ) ;
V_86 [ V_80 ] = & V_108 -> V_119 -> V_79 -> V_123 ;
}
V_84 [ V_80 ] = V_111 ;
F_25 ( L_18 ,
V_108 -> V_116 ,
V_108 -> V_119 -> V_79 -> V_53 . V_60 ,
V_108 -> V_119 -> V_79 -> V_116 ,
V_86 [ V_80 ] -> V_124 , V_86 [ V_80 ] -> V_125 ,
V_86 [ V_80 ] -> V_126 & V_127 ? L_19 : L_20 ) ;
V_98 = false ;
V_90 |= F_47 ( V_80 ) ;
}
if ( ( V_90 & V_92 ) != V_92 && V_90 != V_91 )
goto V_104;
if ( V_99 != V_100 &&
V_99 < F_52 ( V_27 ) -> V_128 ) {
F_25 ( L_21 ) ;
F_25 ( L_22 , V_99 ,
V_100 ) ;
V_98 = true ;
}
if ( V_98 ) {
V_121:
F_25 ( L_23 ) ;
memcpy ( V_89 , V_97 , V_93 ) ;
V_17 = false ;
}
F_53 ( & V_102 ) ;
F_54 ( & V_102 ) ;
F_55 ( V_97 ) ;
return V_17 ;
}
static void F_56 ( struct V_1 * V_2 )
{
F_57 ( & V_2 -> V_16 ) ;
if ( V_2 -> V_7 ) {
F_28 ( & V_2 -> V_16 . V_25 -> V_55 ) ;
F_38 ( V_2 -> V_7 ) ;
F_36 ( & V_2 -> V_16 . V_25 -> V_55 ) ;
}
if ( V_2 -> V_5 )
F_58 ( & V_2 -> V_5 -> V_53 ) ;
F_55 ( V_2 ) ;
}
static bool F_59 ( struct V_24 * V_25 ,
struct V_1 * V_2 )
{
struct V_44 * V_5 = NULL ;
struct V_78 * V_79 ;
struct V_129 * V_129 ;
unsigned int V_130 = 0 ;
F_60 (dev, crtc) {
struct V_3 * V_4 =
F_61 ( V_79 -> V_131 -> V_119 -> V_5 ) ;
V_129 = F_62 ( V_79 ) ;
if ( ! V_79 -> V_119 -> V_132 || ! V_4 ) {
F_25 ( L_24 ,
F_63 ( V_129 -> V_133 ) ) ;
continue;
}
if ( V_4 -> V_53 . V_32 > V_130 ) {
F_25 ( L_25 ,
F_63 ( V_129 -> V_133 ) ) ;
V_5 = F_22 ( V_79 -> V_131 -> V_119 -> V_5 ) ;
V_130 = V_4 -> V_53 . V_32 ;
}
}
if ( ! V_5 ) {
F_25 ( L_26 ) ;
goto V_134;
}
F_60 (dev, crtc) {
unsigned int V_135 ;
V_129 = F_62 ( V_79 ) ;
if ( ! V_79 -> V_119 -> V_132 ) {
F_25 ( L_27 ,
F_63 ( V_129 -> V_133 ) ) ;
continue;
}
F_25 ( L_28 ,
F_63 ( V_129 -> V_133 ) ) ;
V_135 = V_129 -> V_136 -> V_53 . V_137 . V_138 ;
V_135 = V_135 * V_5 -> V_53 . V_74 -> V_139 [ 0 ] ;
if ( V_5 -> V_53 . V_38 [ 0 ] < V_135 ) {
F_25 ( L_29 ,
F_63 ( V_129 -> V_133 ) ,
V_135 , V_5 -> V_53 . V_38 [ 0 ] ) ;
V_5 = NULL ;
break;
}
V_135 = V_129 -> V_136 -> V_53 . V_137 . V_140 ;
V_135 = F_64 ( & V_5 -> V_53 , 0 , V_135 ) ;
V_135 *= V_5 -> V_53 . V_38 [ 0 ] ;
F_25 ( L_30 ,
F_63 ( V_129 -> V_133 ) ,
V_129 -> V_136 -> V_53 . V_137 . V_138 ,
V_129 -> V_136 -> V_53 . V_137 . V_140 ,
V_5 -> V_53 . V_74 -> V_139 [ 0 ] * 8 ,
V_135 ) ;
if ( V_135 > V_130 ) {
F_25 ( L_31 ,
F_63 ( V_129 -> V_133 ) ,
V_135 , V_130 ) ;
V_5 = NULL ;
break;
}
F_25 ( L_32 ,
F_63 ( V_129 -> V_133 ) ,
V_130 , V_135 ) ;
}
if ( ! V_5 ) {
F_25 ( L_33 ) ;
goto V_134;
}
V_2 -> V_141 = V_5 -> V_53 . V_74 -> V_139 [ 0 ] * 8 ;
V_2 -> V_5 = V_5 ;
F_65 ( & V_2 -> V_5 -> V_53 ) ;
F_60 (dev, crtc) {
V_129 = F_62 ( V_79 ) ;
if ( ! V_79 -> V_119 -> V_132 )
continue;
F_66 ( ! V_79 -> V_131 -> V_5 ,
L_34 ,
V_79 -> V_53 . V_60 ) ;
}
F_25 ( L_35 ) ;
return true ;
V_134:
return false ;
}
static void F_67 ( struct V_142 * V_143 )
{
F_68 ( & F_4 ( V_143 ,
struct V_26 ,
V_144 ) -> V_48 ,
V_145 ,
true ) ;
}
int F_69 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = F_11 ( V_25 ) ;
struct V_1 * V_2 ;
int V_17 ;
if ( F_27 ( F_52 ( V_27 ) -> V_128 == 0 ) )
return - V_146 ;
V_2 = F_70 ( sizeof( struct V_1 ) , V_103 ) ;
if ( V_2 == NULL )
return - V_147 ;
F_71 ( V_25 , & V_2 -> V_16 , & V_148 ) ;
if ( ! F_59 ( V_25 , V_2 ) )
V_2 -> V_141 = 32 ;
V_17 = F_72 ( V_25 , & V_2 -> V_16 , 4 ) ;
if ( V_17 ) {
F_55 ( V_2 ) ;
return V_17 ;
}
V_27 -> V_149 = V_2 ;
F_73 ( & V_27 -> V_144 , F_67 ) ;
F_74 ( & V_2 -> V_16 ) ;
return 0 ;
}
static void F_75 ( void * V_150 , T_2 V_151 )
{
struct V_1 * V_2 = V_150 ;
if ( F_76 ( & V_2 -> V_16 ,
V_2 -> V_141 ) ) {
F_77 ( F_11 ( V_2 -> V_16 . V_25 ) ) ;
F_78 ( F_11 ( V_2 -> V_16 . V_25 ) ) ;
}
}
void F_79 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_11 ( V_25 ) -> V_149 ;
if ( ! V_2 )
return;
V_2 -> V_151 = F_80 ( F_75 , V_2 ) ;
}
static void F_81 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_151 )
return;
F_82 ( V_2 -> V_151 + 1 ) ;
V_2 -> V_151 = 0 ;
}
void F_77 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_149 ;
if ( ! V_2 )
return;
F_83 ( & V_27 -> V_144 ) ;
if ( ! F_84 () )
F_81 ( V_2 ) ;
F_85 ( & V_2 -> V_16 ) ;
}
void F_78 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_86 ( & V_27 -> V_149 ) ;
if ( ! V_2 )
return;
F_56 ( V_2 ) ;
}
void F_68 ( struct V_24 * V_25 , int V_119 , bool V_152 )
{
struct V_26 * V_27 = F_11 ( V_25 ) ;
struct V_1 * V_2 = V_27 -> V_149 ;
struct V_11 * V_12 ;
if ( ! V_2 || ! V_2 -> V_7 )
return;
V_12 = V_2 -> V_16 . V_149 ;
if ( V_152 ) {
if ( V_119 != V_145 )
F_87 ( & V_27 -> V_144 ) ;
F_88 () ;
} else {
F_27 ( V_119 != V_145 ) ;
if ( ! F_89 () ) {
F_90 ( & V_27 -> V_144 ) ;
return;
}
}
if ( V_119 == V_145 && V_2 -> V_5 -> V_4 -> V_76 )
F_35 ( V_12 -> V_71 , 0 , V_12 -> V_72 ) ;
F_91 ( & V_2 -> V_16 , V_119 ) ;
F_92 () ;
}
void F_93 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_11 ( V_25 ) -> V_149 ;
if ( V_2 )
F_94 ( & V_2 -> V_16 ) ;
}
void F_95 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_11 ( V_25 ) -> V_149 ;
if ( ! V_2 )
return;
F_81 ( V_2 ) ;
if ( ! V_2 -> V_7 )
return;
if ( F_96 ( & V_2 -> V_16 ) == 0 )
F_1 ( V_2 ) ;
}
