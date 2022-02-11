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
F_23 ( & V_13 -> V_40 ) ;
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
struct V_41 * V_42 = V_7 -> V_12 ;
struct V_21 * V_10 = V_8 -> V_10 ;
struct V_22 * V_23 = F_12 ( V_10 ) ;
struct V_24 * V_25 = & V_23 -> V_25 ;
struct V_1 * V_2 ;
struct V_20 * V_12 ;
struct V_43 * V_44 ;
struct V_28 * V_13 ;
bool V_45 = false ;
void * V_46 ;
int V_9 ;
if ( V_42 &&
( V_19 -> V_47 > V_42 -> V_40 . V_31 ||
V_19 -> V_48 > V_42 -> V_40 . V_33 ) ) {
F_26 ( L_2
L_3 ,
V_42 -> V_40 . V_31 , V_42 -> V_40 . V_33 ,
V_19 -> V_47 , V_19 -> V_48 ) ;
F_27 ( & V_42 -> V_40 ) ;
V_42 = V_7 -> V_12 = NULL ;
}
if ( ! V_42 || F_28 ( ! V_42 -> V_13 ) ) {
F_26 ( L_4 ) ;
V_9 = F_11 ( V_8 , V_19 ) ;
if ( V_9 )
return V_9 ;
V_42 = V_7 -> V_12 ;
} else {
F_26 ( L_5 ) ;
V_45 = true ;
V_19 -> V_47 = V_42 -> V_40 . V_31 ;
V_19 -> V_48 = V_42 -> V_40 . V_33 ;
}
V_13 = V_42 -> V_13 ;
F_4 ( & V_10 -> V_11 ) ;
V_9 = F_29 ( & V_7 -> V_12 -> V_40 , F_30 ( V_49 ) ) ;
if ( V_9 )
goto V_50;
V_2 = F_31 ( V_8 ) ;
if ( F_19 ( V_2 ) ) {
F_20 ( L_6 ) ;
V_9 = F_21 ( V_2 ) ;
goto V_51;
}
V_2 -> V_5 = V_8 ;
V_12 = & V_7 -> V_12 -> V_40 ;
V_7 -> V_8 . V_12 = V_12 ;
strcpy ( V_2 -> V_52 . V_53 , L_7 ) ;
V_2 -> V_54 = V_55 | V_56 ;
V_2 -> V_57 = & V_58 ;
V_44 = F_32 ( V_13 ) ;
V_2 -> V_59 -> V_60 [ 0 ] . V_40 = V_10 -> V_61 . V_62 ;
V_2 -> V_59 -> V_60 [ 0 ] . V_29 = V_25 -> V_63 ;
V_2 -> V_52 . V_64 = V_10 -> V_61 . V_62 + V_44 -> V_65 . V_66 ;
V_2 -> V_52 . V_67 = V_44 -> V_65 . V_29 ;
V_46 = F_33 ( V_44 ) ;
if ( F_19 ( V_46 ) ) {
F_20 ( L_8 ) ;
V_9 = F_21 ( V_46 ) ;
goto V_68;
}
V_2 -> V_69 = V_46 ;
V_2 -> V_70 = V_44 -> V_65 . V_29 ;
V_2 -> V_71 = true ;
F_34 ( V_2 , V_12 -> V_35 [ 0 ] , V_12 -> V_72 ) ;
F_35 ( V_2 , & V_7 -> V_8 , V_19 -> V_47 , V_19 -> V_48 ) ;
if ( V_7 -> V_12 -> V_13 -> V_73 && ! V_45 )
F_36 ( V_2 -> V_69 , 0 , V_2 -> V_70 ) ;
F_26 ( L_9 ,
V_12 -> V_31 , V_12 -> V_33 ,
F_37 ( V_13 ) , V_13 ) ;
F_6 ( & V_10 -> V_11 ) ;
F_38 ( V_10 -> V_74 , V_2 ) ;
return 0 ;
V_68:
F_39 ( V_8 ) ;
V_51:
F_40 ( & V_7 -> V_12 -> V_40 , F_30 ( V_49 ) ) ;
V_50:
F_6 ( & V_10 -> V_11 ) ;
return V_9 ;
}
static void F_41 ( struct V_75 * V_76 , T_1 V_77 , T_1 V_78 ,
T_1 V_79 , int V_80 )
{
struct V_81 * V_81 = F_42 ( V_76 ) ;
V_81 -> V_82 [ V_80 ] = V_77 >> 8 ;
V_81 -> V_83 [ V_80 ] = V_78 >> 8 ;
V_81 -> V_84 [ V_80 ] = V_79 >> 8 ;
}
static void F_43 ( struct V_75 * V_76 , T_1 * V_77 , T_1 * V_78 ,
T_1 * V_79 , int V_80 )
{
struct V_81 * V_81 = F_42 ( V_76 ) ;
* V_77 = V_81 -> V_82 [ V_80 ] << 8 ;
* V_78 = V_81 -> V_83 [ V_80 ] << 8 ;
* V_79 = V_81 -> V_84 [ V_80 ] << 8 ;
}
static struct V_85 *
F_44 ( struct V_3 * V_4 , struct V_75 * V_76 )
{
int V_86 ;
for ( V_86 = 0 ; V_86 < V_4 -> V_87 ; V_86 ++ )
if ( V_4 -> V_88 [ V_86 ] . V_89 . V_76 == V_76 )
return & V_4 -> V_88 [ V_86 ] ;
return NULL ;
}
static bool F_45 ( struct V_3 * V_4 ,
struct V_85 * * V_90 ,
struct V_91 * * V_92 ,
struct V_93 * V_94 ,
bool * V_95 , int V_31 , int V_33 )
{
struct V_21 * V_10 = V_4 -> V_10 ;
unsigned long V_96 , V_97 ;
unsigned int V_98 = F_46 ( V_4 -> V_99 , V_100 ) ;
int V_86 , V_101 ;
bool * V_102 ;
bool V_103 = true ;
int V_104 = 0 ;
int V_105 = 0 ;
int V_106 = 0 ;
V_102 = F_47 ( V_98 , sizeof( bool ) , V_107 ) ;
if ( ! V_102 )
return false ;
memcpy ( V_102 , V_95 , V_98 ) ;
V_97 = F_30 ( V_98 ) - 1 ;
V_96 = 0 ;
V_108:
for ( V_86 = 0 ; V_86 < V_98 ; V_86 ++ ) {
struct V_109 * V_110 ;
struct V_111 * V_112 ;
struct V_113 * V_114 ;
struct V_85 * V_115 ;
struct V_81 * V_81 ;
V_110 = V_4 -> V_116 [ V_86 ] ;
V_112 = V_110 -> V_112 ;
if ( V_96 & F_30 ( V_86 ) )
continue;
if ( V_106 == 0 && ! V_112 -> V_117 )
continue;
if ( V_112 -> V_118 == V_119 )
V_105 ++ ;
if ( ! V_95 [ V_86 ] ) {
F_26 ( L_10 ,
V_112 -> V_120 ) ;
V_96 |= F_30 ( V_86 ) ;
continue;
}
if ( V_112 -> V_121 == V_122 ) {
F_26 ( L_11 ,
V_112 -> V_120 ) ;
V_95 [ V_86 ] = false ;
continue;
}
V_114 = V_112 -> V_123 -> V_124 ;
if ( ! V_114 || F_28 ( ! V_112 -> V_123 -> V_76 ) ) {
if ( V_112 -> V_121 > V_122 )
goto V_125;
F_26 ( L_12 ,
V_112 -> V_120 ) ;
V_95 [ V_86 ] = false ;
V_96 |= F_30 ( V_86 ) ;
continue;
}
V_104 ++ ;
V_81 = F_42 ( V_112 -> V_123 -> V_76 ) ;
for ( V_101 = 0 ; V_101 < 256 ; V_101 ++ ) {
V_81 -> V_82 [ V_101 ] = V_101 ;
V_81 -> V_83 [ V_101 ] = V_101 ;
V_81 -> V_84 [ V_101 ] = V_101 ;
}
V_115 = F_44 ( V_4 ,
V_112 -> V_123 -> V_76 ) ;
for ( V_101 = 0 ; V_101 < V_98 ; V_101 ++ ) {
if ( V_90 [ V_101 ] == V_115 ) {
F_26 ( L_13 ) ;
goto V_125;
}
}
F_26 ( L_14 ,
V_112 -> V_120 ) ;
V_92 [ V_86 ] = F_48 ( V_110 , V_31 , V_33 ) ;
if ( ! V_92 [ V_86 ] ) {
F_26 ( L_15 ,
V_112 -> V_120 , V_112 -> V_117 ) ;
V_92 [ V_86 ] = F_49 ( V_110 , V_31 ,
V_33 ) ;
}
if ( ! V_92 [ V_86 ] && ! F_50 ( & V_112 -> V_92 ) ) {
F_26 ( L_16 ,
V_112 -> V_120 ) ;
V_92 [ V_86 ] = F_51 ( & V_112 -> V_92 ,
struct V_91 ,
V_126 ) ;
}
if ( ! V_92 [ V_86 ] ) {
F_26 ( L_17 ,
V_112 -> V_120 ) ;
V_92 [ V_86 ] = & V_112 -> V_123 -> V_76 -> V_127 ;
}
V_90 [ V_86 ] = V_115 ;
F_26 ( L_18 ,
V_112 -> V_120 ,
V_112 -> V_123 -> V_76 -> V_40 . V_53 ,
V_112 -> V_123 -> V_76 -> V_120 ,
V_92 [ V_86 ] -> V_128 , V_92 [ V_86 ] -> V_129 ,
V_92 [ V_86 ] -> V_54 & V_130 ? L_19 : L_20 ) ;
V_103 = false ;
V_96 |= F_30 ( V_86 ) ;
}
if ( ( V_96 & V_97 ) != V_97 ) {
V_106 ++ ;
goto V_108;
}
if ( V_104 != V_105 &&
V_104 < F_52 ( V_10 ) -> V_131 ) {
F_26 ( L_21 ) ;
F_26 ( L_22 , V_104 ,
V_105 ) ;
V_103 = true ;
}
if ( V_103 ) {
V_125:
F_26 ( L_23 ) ;
memcpy ( V_95 , V_102 , V_98 ) ;
F_53 ( V_102 ) ;
return false ;
}
F_53 ( V_102 ) ;
return true ;
}
static void F_54 ( struct V_6 * V_7 )
{
F_55 ( & V_7 -> V_8 ) ;
F_39 ( & V_7 -> V_8 ) ;
F_56 ( & V_7 -> V_8 ) ;
if ( V_7 -> V_12 ) {
F_4 ( & V_7 -> V_8 . V_10 -> V_11 ) ;
F_40 ( & V_7 -> V_12 -> V_40 , F_30 ( V_49 ) ) ;
F_6 ( & V_7 -> V_8 . V_10 -> V_11 ) ;
F_57 ( & V_7 -> V_12 -> V_40 ) ;
}
F_53 ( V_7 ) ;
}
static bool F_58 ( struct V_21 * V_10 ,
struct V_6 * V_7 )
{
struct V_41 * V_12 = NULL ;
struct V_75 * V_76 ;
struct V_81 * V_81 ;
unsigned int V_132 = 0 ;
F_59 (dev, crtc) {
struct V_28 * V_13 =
F_60 ( V_76 -> V_133 -> V_123 -> V_12 ) ;
V_81 = F_42 ( V_76 ) ;
if ( ! V_76 -> V_123 -> V_134 || ! V_13 ) {
F_26 ( L_24 ,
F_61 ( V_81 -> V_135 ) ) ;
continue;
}
if ( V_13 -> V_40 . V_29 > V_132 ) {
F_26 ( L_25 ,
F_61 ( V_81 -> V_135 ) ) ;
V_12 = F_24 ( V_76 -> V_133 -> V_123 -> V_12 ) ;
V_132 = V_13 -> V_40 . V_29 ;
}
}
if ( ! V_12 ) {
F_26 ( L_26 ) ;
goto V_39;
}
F_59 (dev, crtc) {
unsigned int V_136 ;
V_81 = F_42 ( V_76 ) ;
if ( ! V_76 -> V_123 -> V_134 ) {
F_26 ( L_27 ,
F_61 ( V_81 -> V_135 ) ) ;
continue;
}
F_26 ( L_28 ,
F_61 ( V_81 -> V_135 ) ) ;
V_136 = V_81 -> V_137 -> V_40 . V_138 . V_139 ;
V_136 = V_136 * V_12 -> V_40 . V_140 / 8 ;
if ( V_12 -> V_40 . V_35 [ 0 ] < V_136 ) {
F_26 ( L_29 ,
F_61 ( V_81 -> V_135 ) ,
V_136 , V_12 -> V_40 . V_35 [ 0 ] ) ;
V_12 = NULL ;
break;
}
V_136 = V_81 -> V_137 -> V_40 . V_138 . V_141 ;
V_136 = F_62 ( V_10 , V_136 ,
V_12 -> V_40 . V_36 ,
V_12 -> V_40 . V_142 [ 0 ] ) ;
V_136 *= V_12 -> V_40 . V_35 [ 0 ] ;
F_26 ( L_30 ,
F_61 ( V_81 -> V_135 ) ,
V_81 -> V_137 -> V_40 . V_138 . V_139 ,
V_81 -> V_137 -> V_40 . V_138 . V_141 ,
V_12 -> V_40 . V_140 ,
V_136 ) ;
if ( V_136 > V_132 ) {
F_26 ( L_31 ,
F_61 ( V_81 -> V_135 ) ,
V_136 , V_132 ) ;
V_12 = NULL ;
break;
}
F_26 ( L_32 ,
F_61 ( V_81 -> V_135 ) ,
V_132 , V_136 ) ;
}
if ( ! V_12 ) {
F_26 ( L_33 ) ;
goto V_39;
}
V_7 -> V_143 = V_12 -> V_40 . V_140 ;
V_7 -> V_12 = V_12 ;
F_63 ( & V_7 -> V_12 -> V_40 ) ;
F_59 (dev, crtc) {
V_81 = F_42 ( V_76 ) ;
if ( ! V_76 -> V_123 -> V_134 )
continue;
F_64 ( ! V_76 -> V_133 -> V_12 ,
L_34 ,
V_76 -> V_40 . V_53 ) ;
}
F_26 ( L_35 ) ;
return true ;
V_39:
return false ;
}
static void F_65 ( struct V_144 * V_145 )
{
F_66 ( & F_2 ( V_145 ,
struct V_22 ,
V_146 ) -> V_147 ,
V_148 ,
true ) ;
}
int F_67 ( struct V_21 * V_10 )
{
struct V_6 * V_7 ;
struct V_22 * V_23 = F_12 ( V_10 ) ;
int V_9 ;
if ( F_28 ( F_52 ( V_10 ) -> V_131 == 0 ) )
return - V_149 ;
V_7 = F_68 ( sizeof( struct V_6 ) , V_107 ) ;
if ( V_7 == NULL )
return - V_150 ;
F_69 ( V_10 , & V_7 -> V_8 , & V_151 ) ;
if ( ! F_58 ( V_10 , V_7 ) )
V_7 -> V_143 = 32 ;
V_9 = F_70 ( V_10 , & V_7 -> V_8 ,
F_52 ( V_10 ) -> V_131 , 4 ) ;
if ( V_9 ) {
F_53 ( V_7 ) ;
return V_9 ;
}
V_23 -> V_152 = V_7 ;
F_71 ( & V_23 -> V_146 , F_65 ) ;
F_72 ( & V_7 -> V_8 ) ;
return 0 ;
}
static void F_73 ( void * V_153 , T_2 V_154 )
{
struct V_6 * V_7 = V_153 ;
if ( F_74 ( & V_7 -> V_8 ,
V_7 -> V_143 ) )
F_75 ( V_7 -> V_8 . V_10 ) ;
}
void F_76 ( struct V_21 * V_10 )
{
struct V_6 * V_7 = F_12 ( V_10 ) -> V_152 ;
V_7 -> V_154 = F_77 ( F_73 , V_7 ) ;
}
static void F_78 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_154 )
return;
F_79 ( V_7 -> V_154 + 1 ) ;
V_7 -> V_154 = 0 ;
}
void F_75 ( struct V_21 * V_10 )
{
struct V_22 * V_23 = F_12 ( V_10 ) ;
struct V_6 * V_7 = V_23 -> V_152 ;
if ( ! V_7 )
return;
F_80 ( & V_23 -> V_146 ) ;
if ( ! F_81 () )
F_78 ( V_7 ) ;
F_54 ( V_7 ) ;
V_23 -> V_152 = NULL ;
}
void F_66 ( struct V_21 * V_10 , int V_123 , bool V_155 )
{
struct V_22 * V_23 = F_12 ( V_10 ) ;
struct V_6 * V_7 = V_23 -> V_152 ;
struct V_1 * V_2 ;
if ( ! V_7 || ! V_7 -> V_12 )
return;
V_2 = V_7 -> V_8 . V_152 ;
if ( V_155 ) {
if ( V_123 != V_148 )
F_80 ( & V_23 -> V_146 ) ;
F_82 () ;
} else {
F_28 ( V_123 != V_148 ) ;
if ( ! F_83 () ) {
F_84 ( & V_23 -> V_146 ) ;
return;
}
}
if ( V_123 == V_148 && V_7 -> V_12 -> V_13 -> V_73 )
F_36 ( V_2 -> V_69 , 0 , V_2 -> V_70 ) ;
F_85 ( & V_7 -> V_8 , V_123 ) ;
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
F_78 ( V_7 ) ;
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
