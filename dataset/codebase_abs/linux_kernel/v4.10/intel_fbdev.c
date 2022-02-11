static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 =
F_2 ( V_4 , struct V_6 , V_8 ) ;
int V_9 ;
V_9 = F_3 ( V_2 ) ;
if ( V_9 == 0 ) {
F_4 ( & V_4 -> V_10 -> V_11 ) ;
F_5 ( V_7 -> V_12 -> V_13 , V_14 ) ;
F_6 ( & V_4 -> V_10 -> V_11 ) ;
}
return V_9 ;
}
static int F_7 ( int V_15 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 =
F_2 ( V_4 , struct V_6 , V_8 ) ;
int V_9 ;
V_9 = F_8 ( V_15 , V_2 ) ;
if ( V_9 == 0 ) {
F_4 ( & V_4 -> V_10 -> V_11 ) ;
F_5 ( V_7 -> V_12 -> V_13 , V_14 ) ;
F_6 ( & V_4 -> V_10 -> V_11 ) ;
}
return V_9 ;
}
static int F_9 ( struct V_16 * V_17 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 =
F_2 ( V_4 , struct V_6 , V_8 ) ;
int V_9 ;
V_9 = F_10 ( V_17 , V_2 ) ;
if ( V_9 == 0 ) {
F_4 ( & V_4 -> V_10 -> V_11 ) ;
F_5 ( V_7 -> V_12 -> V_13 , V_14 ) ;
F_6 ( & V_4 -> V_10 -> V_11 ) ;
}
return V_9 ;
}
static int F_11 ( struct V_3 * V_8 ,
struct V_18 * V_19 )
{
struct V_6 * V_7 =
F_2 ( V_8 , struct V_6 , V_8 ) ;
struct V_20 * V_12 ;
struct V_21 * V_10 = V_8 -> V_10 ;
struct V_22 * V_23 = F_12 ( V_10 ) ;
struct V_24 * V_25 = & V_23 -> V_25 ;
struct V_26 V_27 = {} ;
struct V_28 * V_13 = NULL ;
int V_29 , V_9 ;
if ( V_19 -> V_30 == 24 )
V_19 -> V_30 = 32 ;
V_27 . V_31 = V_19 -> V_32 ;
V_27 . V_33 = V_19 -> V_34 ;
V_27 . V_35 [ 0 ] = F_13 ( V_27 . V_31 *
F_14 ( V_19 -> V_30 , 8 ) , 64 ) ;
V_27 . V_36 = F_15 ( V_19 -> V_30 ,
V_19 -> V_37 ) ;
F_4 ( & V_10 -> V_11 ) ;
V_29 = V_27 . V_35 [ 0 ] * V_27 . V_33 ;
V_29 = F_16 ( V_29 ) ;
if ( V_29 * 2 < V_25 -> V_38 )
V_13 = F_17 ( V_10 , V_29 ) ;
if ( V_13 == NULL )
V_13 = F_18 ( V_10 , V_29 ) ;
if ( F_19 ( V_13 ) ) {
F_20 ( L_1 ) ;
V_9 = F_21 ( V_13 ) ;
goto V_39;
}
V_12 = F_22 ( V_10 , & V_27 , V_13 ) ;
if ( F_19 ( V_12 ) ) {
F_23 ( V_13 ) ;
V_9 = F_21 ( V_12 ) ;
goto V_39;
}
F_6 ( & V_10 -> V_11 ) ;
V_7 -> V_12 = F_24 ( V_12 ) ;
return 0 ;
V_39:
F_6 ( & V_10 -> V_11 ) ;
return V_9 ;
}
static int F_25 ( struct V_3 * V_8 ,
struct V_18 * V_19 )
{
struct V_6 * V_7 =
F_2 ( V_8 , struct V_6 , V_8 ) ;
struct V_40 * V_41 = V_7 -> V_12 ;
struct V_21 * V_10 = V_8 -> V_10 ;
struct V_22 * V_23 = F_12 ( V_10 ) ;
struct V_42 * V_43 = V_23 -> V_44 . V_43 ;
struct V_24 * V_25 = & V_23 -> V_25 ;
struct V_1 * V_2 ;
struct V_20 * V_12 ;
struct V_45 * V_46 ;
bool V_47 = false ;
void T_1 * V_48 ;
int V_9 ;
if ( V_41 &&
( V_19 -> V_49 > V_41 -> V_50 . V_31 ||
V_19 -> V_51 > V_41 -> V_50 . V_33 ) ) {
F_26 ( L_2
L_3 ,
V_41 -> V_50 . V_31 , V_41 -> V_50 . V_33 ,
V_19 -> V_49 , V_19 -> V_51 ) ;
F_27 ( & V_41 -> V_50 ) ;
V_41 = V_7 -> V_12 = NULL ;
}
if ( ! V_41 || F_28 ( ! V_41 -> V_13 ) ) {
F_26 ( L_4 ) ;
V_9 = F_11 ( V_8 , V_19 ) ;
if ( V_9 )
return V_9 ;
V_41 = V_7 -> V_12 ;
} else {
F_26 ( L_5 ) ;
V_47 = true ;
V_19 -> V_49 = V_41 -> V_50 . V_31 ;
V_19 -> V_51 = V_41 -> V_50 . V_33 ;
}
F_4 ( & V_10 -> V_11 ) ;
V_46 = F_29 ( & V_7 -> V_12 -> V_50 , V_52 ) ;
if ( F_19 ( V_46 ) ) {
V_9 = F_21 ( V_46 ) ;
goto V_53;
}
V_2 = F_30 ( V_8 ) ;
if ( F_19 ( V_2 ) ) {
F_20 ( L_6 ) ;
V_9 = F_21 ( V_2 ) ;
goto V_54;
}
V_2 -> V_5 = V_8 ;
V_12 = & V_7 -> V_12 -> V_50 ;
V_7 -> V_8 . V_12 = V_12 ;
strcpy ( V_2 -> V_55 . V_56 , L_7 ) ;
V_2 -> V_57 = V_58 | V_59 ;
V_2 -> V_60 = & V_61 ;
V_2 -> V_62 -> V_63 [ 0 ] . V_50 = V_10 -> V_64 . V_65 ;
V_2 -> V_62 -> V_63 [ 0 ] . V_29 = V_25 -> V_66 ;
V_2 -> V_55 . V_67 = V_10 -> V_64 . V_65 + F_31 ( V_46 ) ;
V_2 -> V_55 . V_68 = V_46 -> V_69 . V_29 ;
V_48 = F_32 ( V_46 ) ;
if ( F_19 ( V_48 ) ) {
F_20 ( L_8 ) ;
V_9 = F_21 ( V_48 ) ;
goto V_70;
}
V_2 -> V_71 = V_48 ;
V_2 -> V_72 = V_46 -> V_69 . V_29 ;
V_2 -> V_73 = true ;
F_33 ( V_2 , V_12 -> V_35 [ 0 ] , V_12 -> V_74 ) ;
F_34 ( V_2 , & V_7 -> V_8 , V_19 -> V_49 , V_19 -> V_51 ) ;
if ( V_41 -> V_13 -> V_75 && ! V_47 )
F_35 ( V_2 -> V_71 , 0 , V_2 -> V_72 ) ;
F_26 ( L_9 ,
V_12 -> V_31 , V_12 -> V_33 , F_31 ( V_46 ) ) ;
V_7 -> V_46 = V_46 ;
F_6 ( & V_10 -> V_11 ) ;
F_36 ( V_43 , V_2 ) ;
return 0 ;
V_70:
F_37 ( V_8 ) ;
V_54:
F_38 ( V_46 ) ;
V_53:
F_6 ( & V_10 -> V_11 ) ;
return V_9 ;
}
static void F_39 ( struct V_76 * V_77 , T_2 V_78 , T_2 V_79 ,
T_2 V_80 , int V_81 )
{
struct V_82 * V_82 = F_40 ( V_77 ) ;
V_82 -> V_83 [ V_81 ] = V_78 >> 8 ;
V_82 -> V_84 [ V_81 ] = V_79 >> 8 ;
V_82 -> V_85 [ V_81 ] = V_80 >> 8 ;
}
static void F_41 ( struct V_76 * V_77 , T_2 * V_78 , T_2 * V_79 ,
T_2 * V_80 , int V_81 )
{
struct V_82 * V_82 = F_40 ( V_77 ) ;
* V_78 = V_82 -> V_83 [ V_81 ] << 8 ;
* V_79 = V_82 -> V_84 [ V_81 ] << 8 ;
* V_80 = V_82 -> V_85 [ V_81 ] << 8 ;
}
static struct V_86 *
F_42 ( struct V_3 * V_4 , struct V_76 * V_77 )
{
int V_87 ;
for ( V_87 = 0 ; V_87 < V_4 -> V_88 ; V_87 ++ )
if ( V_4 -> V_89 [ V_87 ] . V_90 . V_77 == V_77 )
return & V_4 -> V_89 [ V_87 ] ;
return NULL ;
}
static bool F_43 ( struct V_3 * V_4 ,
struct V_86 * * V_91 ,
struct V_92 * * V_93 ,
struct V_94 * V_95 ,
bool * V_96 , int V_31 , int V_33 )
{
struct V_22 * V_23 = F_12 ( V_4 -> V_10 ) ;
unsigned long V_97 , V_98 ;
unsigned int V_99 = F_44 ( V_4 -> V_100 , V_101 ) ;
int V_87 , V_102 ;
bool * V_103 ;
bool V_104 = true ;
int V_105 = 0 ;
int V_106 = 0 ;
int V_107 = 0 ;
V_103 = F_45 ( V_99 , sizeof( bool ) , V_108 ) ;
if ( ! V_103 )
return false ;
memcpy ( V_103 , V_96 , V_99 ) ;
V_98 = F_46 ( V_99 ) - 1 ;
V_97 = 0 ;
V_109:
for ( V_87 = 0 ; V_87 < V_99 ; V_87 ++ ) {
struct V_110 * V_111 ;
struct V_112 * V_113 ;
struct V_114 * V_115 ;
struct V_86 * V_116 ;
struct V_82 * V_82 ;
V_111 = V_4 -> V_117 [ V_87 ] ;
V_113 = V_111 -> V_113 ;
if ( V_97 & F_46 ( V_87 ) )
continue;
if ( V_107 == 0 && ! V_113 -> V_118 )
continue;
if ( V_113 -> V_119 == V_120 )
V_106 ++ ;
if ( ! V_96 [ V_87 ] ) {
F_26 ( L_10 ,
V_113 -> V_121 ) ;
V_97 |= F_46 ( V_87 ) ;
continue;
}
if ( V_113 -> V_122 == V_123 ) {
F_26 ( L_11 ,
V_113 -> V_121 ) ;
V_96 [ V_87 ] = false ;
continue;
}
V_115 = V_113 -> V_124 -> V_125 ;
if ( ! V_115 || F_28 ( ! V_113 -> V_124 -> V_77 ) ) {
if ( V_113 -> V_122 > V_123 )
goto V_126;
F_26 ( L_12 ,
V_113 -> V_121 ) ;
V_96 [ V_87 ] = false ;
V_97 |= F_46 ( V_87 ) ;
continue;
}
V_105 ++ ;
V_82 = F_40 ( V_113 -> V_124 -> V_77 ) ;
for ( V_102 = 0 ; V_102 < 256 ; V_102 ++ ) {
V_82 -> V_83 [ V_102 ] = V_102 ;
V_82 -> V_84 [ V_102 ] = V_102 ;
V_82 -> V_85 [ V_102 ] = V_102 ;
}
V_116 = F_42 ( V_4 ,
V_113 -> V_124 -> V_77 ) ;
for ( V_102 = 0 ; V_102 < V_99 ; V_102 ++ ) {
if ( V_91 [ V_102 ] == V_116 ) {
F_26 ( L_13 ) ;
goto V_126;
}
}
F_26 ( L_14 ,
V_113 -> V_121 ) ;
V_93 [ V_87 ] = F_47 ( V_111 , V_31 , V_33 ) ;
if ( ! V_93 [ V_87 ] ) {
F_26 ( L_15 ,
V_113 -> V_121 , V_113 -> V_118 ) ;
V_93 [ V_87 ] = F_48 ( V_111 , V_31 ,
V_33 ) ;
}
if ( ! V_93 [ V_87 ] && ! F_49 ( & V_113 -> V_93 ) ) {
F_26 ( L_16 ,
V_113 -> V_121 ) ;
V_93 [ V_87 ] = F_50 ( & V_113 -> V_93 ,
struct V_92 ,
V_127 ) ;
}
if ( ! V_93 [ V_87 ] ) {
F_26 ( L_17 ,
V_113 -> V_121 ) ;
V_93 [ V_87 ] = & V_113 -> V_124 -> V_77 -> V_128 ;
}
V_91 [ V_87 ] = V_116 ;
F_26 ( L_18 ,
V_113 -> V_121 ,
V_113 -> V_124 -> V_77 -> V_50 . V_56 ,
V_113 -> V_124 -> V_77 -> V_121 ,
V_93 [ V_87 ] -> V_129 , V_93 [ V_87 ] -> V_130 ,
V_93 [ V_87 ] -> V_57 & V_131 ? L_19 : L_20 ) ;
V_104 = false ;
V_97 |= F_46 ( V_87 ) ;
}
if ( ( V_97 & V_98 ) != V_98 ) {
V_107 ++ ;
goto V_109;
}
if ( V_105 != V_106 &&
V_105 < F_51 ( V_23 ) -> V_132 ) {
F_26 ( L_21 ) ;
F_26 ( L_22 , V_105 ,
V_106 ) ;
V_104 = true ;
}
if ( V_104 ) {
V_126:
F_26 ( L_23 ) ;
memcpy ( V_96 , V_103 , V_99 ) ;
F_52 ( V_103 ) ;
return false ;
}
F_52 ( V_103 ) ;
return true ;
}
static void F_53 ( struct V_6 * V_7 )
{
F_54 ( & V_7 -> V_8 ) ;
F_37 ( & V_7 -> V_8 ) ;
F_55 ( & V_7 -> V_8 ) ;
if ( V_7 -> V_12 ) {
F_4 ( & V_7 -> V_8 . V_10 -> V_11 ) ;
F_38 ( V_7 -> V_46 ) ;
F_6 ( & V_7 -> V_8 . V_10 -> V_11 ) ;
F_56 ( & V_7 -> V_12 -> V_50 ) ;
}
F_52 ( V_7 ) ;
}
static bool F_57 ( struct V_21 * V_10 ,
struct V_6 * V_7 )
{
struct V_40 * V_12 = NULL ;
struct V_76 * V_77 ;
struct V_82 * V_82 ;
unsigned int V_133 = 0 ;
F_58 (dev, crtc) {
struct V_28 * V_13 =
F_59 ( V_77 -> V_134 -> V_124 -> V_12 ) ;
V_82 = F_40 ( V_77 ) ;
if ( ! V_77 -> V_124 -> V_135 || ! V_13 ) {
F_26 ( L_24 ,
F_60 ( V_82 -> V_136 ) ) ;
continue;
}
if ( V_13 -> V_50 . V_29 > V_133 ) {
F_26 ( L_25 ,
F_60 ( V_82 -> V_136 ) ) ;
V_12 = F_24 ( V_77 -> V_134 -> V_124 -> V_12 ) ;
V_133 = V_13 -> V_50 . V_29 ;
}
}
if ( ! V_12 ) {
F_26 ( L_26 ) ;
goto V_39;
}
F_58 (dev, crtc) {
unsigned int V_137 ;
V_82 = F_40 ( V_77 ) ;
if ( ! V_77 -> V_124 -> V_135 ) {
F_26 ( L_27 ,
F_60 ( V_82 -> V_136 ) ) ;
continue;
}
F_26 ( L_28 ,
F_60 ( V_82 -> V_136 ) ) ;
V_137 = V_82 -> V_138 -> V_50 . V_139 . V_140 ;
V_137 = V_137 * V_12 -> V_50 . V_141 / 8 ;
if ( V_12 -> V_50 . V_35 [ 0 ] < V_137 ) {
F_26 ( L_29 ,
F_60 ( V_82 -> V_136 ) ,
V_137 , V_12 -> V_50 . V_35 [ 0 ] ) ;
V_12 = NULL ;
break;
}
V_137 = V_82 -> V_138 -> V_50 . V_139 . V_142 ;
V_137 = F_61 ( V_10 , V_137 ,
V_12 -> V_50 . V_36 ,
V_12 -> V_50 . V_143 ) ;
V_137 *= V_12 -> V_50 . V_35 [ 0 ] ;
F_26 ( L_30 ,
F_60 ( V_82 -> V_136 ) ,
V_82 -> V_138 -> V_50 . V_139 . V_140 ,
V_82 -> V_138 -> V_50 . V_139 . V_142 ,
V_12 -> V_50 . V_141 ,
V_137 ) ;
if ( V_137 > V_133 ) {
F_26 ( L_31 ,
F_60 ( V_82 -> V_136 ) ,
V_137 , V_133 ) ;
V_12 = NULL ;
break;
}
F_26 ( L_32 ,
F_60 ( V_82 -> V_136 ) ,
V_133 , V_137 ) ;
}
if ( ! V_12 ) {
F_26 ( L_33 ) ;
goto V_39;
}
V_7 -> V_144 = V_12 -> V_50 . V_141 ;
V_7 -> V_12 = V_12 ;
F_62 ( & V_7 -> V_12 -> V_50 ) ;
F_58 (dev, crtc) {
V_82 = F_40 ( V_77 ) ;
if ( ! V_77 -> V_124 -> V_135 )
continue;
F_63 ( ! V_77 -> V_134 -> V_12 ,
L_34 ,
V_77 -> V_50 . V_56 ) ;
}
F_26 ( L_35 ) ;
return true ;
V_39:
return false ;
}
static void F_64 ( struct V_145 * V_146 )
{
F_65 ( & F_2 ( V_146 ,
struct V_22 ,
V_147 ) -> V_44 ,
V_148 ,
true ) ;
}
int F_66 ( struct V_21 * V_10 )
{
struct V_22 * V_23 = F_12 ( V_10 ) ;
struct V_6 * V_7 ;
int V_9 ;
if ( F_28 ( F_51 ( V_23 ) -> V_132 == 0 ) )
return - V_149 ;
V_7 = F_67 ( sizeof( struct V_6 ) , V_108 ) ;
if ( V_7 == NULL )
return - V_150 ;
F_68 ( V_10 , & V_7 -> V_8 , & V_151 ) ;
if ( ! F_57 ( V_10 , V_7 ) )
V_7 -> V_144 = 32 ;
V_9 = F_69 ( V_10 , & V_7 -> V_8 ,
F_51 ( V_23 ) -> V_132 , 4 ) ;
if ( V_9 ) {
F_52 ( V_7 ) ;
return V_9 ;
}
V_23 -> V_152 = V_7 ;
F_70 ( & V_23 -> V_147 , F_64 ) ;
F_71 ( & V_7 -> V_8 ) ;
return 0 ;
}
static void F_72 ( void * V_153 , T_3 V_154 )
{
struct V_6 * V_7 = V_153 ;
if ( F_73 ( & V_7 -> V_8 ,
V_7 -> V_144 ) )
F_74 ( V_7 -> V_8 . V_10 ) ;
}
void F_75 ( struct V_21 * V_10 )
{
struct V_6 * V_7 = F_12 ( V_10 ) -> V_152 ;
if ( ! V_7 )
return;
V_7 -> V_154 = F_76 ( F_72 , V_7 ) ;
}
static void F_77 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_154 )
return;
F_78 ( V_7 -> V_154 + 1 ) ;
V_7 -> V_154 = 0 ;
}
void F_74 ( struct V_21 * V_10 )
{
struct V_22 * V_23 = F_12 ( V_10 ) ;
struct V_6 * V_7 = V_23 -> V_152 ;
if ( ! V_7 )
return;
F_79 ( & V_23 -> V_147 ) ;
if ( ! F_80 () )
F_77 ( V_7 ) ;
F_53 ( V_7 ) ;
V_23 -> V_152 = NULL ;
}
void F_65 ( struct V_21 * V_10 , int V_124 , bool V_155 )
{
struct V_22 * V_23 = F_12 ( V_10 ) ;
struct V_6 * V_7 = V_23 -> V_152 ;
struct V_1 * V_2 ;
if ( ! V_7 || ! V_7 -> V_12 )
return;
V_2 = V_7 -> V_8 . V_152 ;
if ( V_155 ) {
if ( V_124 != V_148 )
F_81 ( & V_23 -> V_147 ) ;
F_82 () ;
} else {
F_28 ( V_124 != V_148 ) ;
if ( ! F_83 () ) {
F_84 ( & V_23 -> V_147 ) ;
return;
}
}
if ( V_124 == V_148 && V_7 -> V_12 -> V_13 -> V_75 )
F_35 ( V_2 -> V_71 , 0 , V_2 -> V_72 ) ;
F_85 ( & V_7 -> V_8 , V_124 ) ;
F_86 () ;
}
void F_87 ( struct V_21 * V_10 )
{
struct V_6 * V_7 = F_12 ( V_10 ) -> V_152 ;
if ( V_7 && V_7 -> V_12 )
F_88 ( & V_7 -> V_8 ) ;
}
void F_89 ( struct V_21 * V_10 )
{
struct V_6 * V_7 = F_12 ( V_10 ) -> V_152 ;
if ( ! V_7 )
return;
F_77 ( V_7 ) ;
if ( ! V_7 -> V_12 )
return;
if ( F_90 ( & V_7 -> V_8 ) ) {
F_91 ( L_36 ) ;
} else {
F_4 ( & V_10 -> V_11 ) ;
F_5 ( V_7 -> V_12 -> V_13 , V_14 ) ;
F_6 ( & V_10 -> V_11 ) ;
}
}
