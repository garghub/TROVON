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
if ( ! V_13 ) {
F_19 ( L_1 ) ;
V_9 = - V_39 ;
goto V_40;
}
V_12 = F_20 ( V_10 , & V_27 , V_13 ) ;
if ( F_21 ( V_12 ) ) {
F_22 ( & V_13 -> V_41 ) ;
V_9 = F_23 ( V_12 ) ;
goto V_40;
}
F_6 ( & V_10 -> V_11 ) ;
V_7 -> V_12 = F_24 ( V_12 ) ;
return 0 ;
V_40:
F_6 ( & V_10 -> V_11 ) ;
return V_9 ;
}
static int F_25 ( struct V_3 * V_8 ,
struct V_18 * V_19 )
{
struct V_6 * V_7 =
F_2 ( V_8 , struct V_6 , V_8 ) ;
struct V_42 * V_43 = V_7 -> V_12 ;
struct V_21 * V_10 = V_8 -> V_10 ;
struct V_22 * V_23 = F_12 ( V_10 ) ;
struct V_24 * V_25 = & V_23 -> V_25 ;
struct V_1 * V_2 ;
struct V_20 * V_12 ;
struct V_28 * V_13 ;
int V_29 , V_9 ;
bool V_44 = false ;
if ( V_43 &&
( V_19 -> V_45 > V_43 -> V_41 . V_31 ||
V_19 -> V_46 > V_43 -> V_41 . V_33 ) ) {
F_26 ( L_2
L_3 ,
V_43 -> V_41 . V_31 , V_43 -> V_41 . V_33 ,
V_19 -> V_45 , V_19 -> V_46 ) ;
F_27 ( & V_43 -> V_41 ) ;
V_43 = V_7 -> V_12 = NULL ;
}
if ( ! V_43 || F_28 ( ! V_43 -> V_13 ) ) {
F_26 ( L_4 ) ;
V_9 = F_11 ( V_8 , V_19 ) ;
if ( V_9 )
return V_9 ;
V_43 = V_7 -> V_12 ;
} else {
F_26 ( L_5 ) ;
V_44 = true ;
V_19 -> V_45 = V_43 -> V_41 . V_31 ;
V_19 -> V_46 = V_43 -> V_41 . V_33 ;
}
V_13 = V_43 -> V_13 ;
V_29 = V_13 -> V_41 . V_29 ;
F_4 ( & V_10 -> V_11 ) ;
V_9 = F_29 ( & V_7 -> V_12 -> V_41 , F_30 ( V_47 ) ) ;
if ( V_9 )
goto V_48;
V_2 = F_31 ( V_8 ) ;
if ( F_21 ( V_2 ) ) {
F_19 ( L_6 ) ;
V_9 = F_23 ( V_2 ) ;
goto V_49;
}
V_2 -> V_5 = V_8 ;
V_12 = & V_7 -> V_12 -> V_41 ;
V_7 -> V_8 . V_12 = V_12 ;
strcpy ( V_2 -> V_50 . V_51 , L_7 ) ;
V_2 -> V_52 = V_53 | V_54 ;
V_2 -> V_55 = & V_56 ;
V_2 -> V_57 -> V_58 [ 0 ] . V_41 = V_10 -> V_59 . V_60 ;
V_2 -> V_57 -> V_58 [ 0 ] . V_29 = V_25 -> V_61 ;
V_2 -> V_50 . V_62 = V_10 -> V_59 . V_60 + F_32 ( V_13 ) ;
V_2 -> V_50 . V_63 = V_29 ;
V_2 -> V_64 =
F_33 ( V_25 -> V_65 + F_32 ( V_13 ) ,
V_29 ) ;
if ( ! V_2 -> V_64 ) {
F_19 ( L_8 ) ;
V_9 = - V_66 ;
goto V_67;
}
V_2 -> V_68 = V_29 ;
V_2 -> V_69 = true ;
F_34 ( V_2 , V_12 -> V_35 [ 0 ] , V_12 -> V_70 ) ;
F_35 ( V_2 , & V_7 -> V_8 , V_19 -> V_45 , V_19 -> V_46 ) ;
if ( V_7 -> V_12 -> V_13 -> V_71 && ! V_44 )
F_36 ( V_2 -> V_64 , 0 , V_2 -> V_68 ) ;
F_26 ( L_9 ,
V_12 -> V_31 , V_12 -> V_33 ,
F_32 ( V_13 ) , V_13 ) ;
F_6 ( & V_10 -> V_11 ) ;
F_37 ( V_10 -> V_72 , V_2 ) ;
return 0 ;
V_67:
F_38 ( V_8 ) ;
V_49:
F_39 ( V_13 ) ;
V_48:
F_6 ( & V_10 -> V_11 ) ;
return V_9 ;
}
static void F_40 ( struct V_73 * V_74 , T_1 V_75 , T_1 V_76 ,
T_1 V_77 , int V_78 )
{
struct V_79 * V_79 = F_41 ( V_74 ) ;
V_79 -> V_80 [ V_78 ] = V_75 >> 8 ;
V_79 -> V_81 [ V_78 ] = V_76 >> 8 ;
V_79 -> V_82 [ V_78 ] = V_77 >> 8 ;
}
static void F_42 ( struct V_73 * V_74 , T_1 * V_75 , T_1 * V_76 ,
T_1 * V_77 , int V_78 )
{
struct V_79 * V_79 = F_41 ( V_74 ) ;
* V_75 = V_79 -> V_80 [ V_78 ] << 8 ;
* V_76 = V_79 -> V_81 [ V_78 ] << 8 ;
* V_77 = V_79 -> V_82 [ V_78 ] << 8 ;
}
static struct V_83 *
F_43 ( struct V_3 * V_4 , struct V_73 * V_74 )
{
int V_84 ;
for ( V_84 = 0 ; V_84 < V_4 -> V_85 ; V_84 ++ )
if ( V_4 -> V_86 [ V_84 ] . V_87 . V_74 == V_74 )
return & V_4 -> V_86 [ V_84 ] ;
return NULL ;
}
static bool F_44 ( struct V_3 * V_4 ,
struct V_83 * * V_88 ,
struct V_89 * * V_90 ,
struct V_91 * V_92 ,
bool * V_93 , int V_31 , int V_33 )
{
struct V_21 * V_10 = V_4 -> V_10 ;
int V_84 , V_94 ;
bool * V_95 ;
bool V_96 = true ;
int V_97 = 0 ;
int V_98 = 0 ;
T_2 V_99 = 0 , V_100 ;
int V_101 = 0 ;
V_95 = F_45 ( V_4 -> V_102 , sizeof( bool ) ,
V_103 ) ;
if ( ! V_95 )
return false ;
memcpy ( V_95 , V_93 , V_4 -> V_102 ) ;
V_100 = ( 1 << V_4 -> V_102 ) - 1 ;
V_104:
for ( V_84 = 0 ; V_84 < V_4 -> V_102 ; V_84 ++ ) {
struct V_105 * V_106 ;
struct V_107 * V_108 ;
struct V_109 * V_110 ;
struct V_83 * V_111 ;
struct V_79 * V_79 ;
V_106 = V_4 -> V_112 [ V_84 ] ;
V_108 = V_106 -> V_108 ;
if ( V_99 & ( 1 << V_84 ) )
continue;
if ( V_101 == 0 && ! V_108 -> V_113 )
continue;
if ( V_108 -> V_114 == V_115 )
V_98 ++ ;
if ( ! V_93 [ V_84 ] ) {
F_26 ( L_10 ,
V_108 -> V_116 ) ;
V_99 |= ( 1 << V_84 ) ;
continue;
}
if ( V_108 -> V_117 == V_118 ) {
F_26 ( L_11 ,
V_108 -> V_116 ) ;
V_93 [ V_84 ] = false ;
continue;
}
V_110 = V_108 -> V_119 -> V_120 ;
if ( ! V_110 || F_28 ( ! V_108 -> V_119 -> V_74 ) ) {
if ( V_108 -> V_117 > V_118 )
goto V_121;
F_26 ( L_12 ,
V_108 -> V_116 ) ;
V_93 [ V_84 ] = false ;
V_99 |= ( 1 << V_84 ) ;
continue;
}
V_97 ++ ;
V_79 = F_41 ( V_108 -> V_119 -> V_74 ) ;
for ( V_94 = 0 ; V_94 < 256 ; V_94 ++ ) {
V_79 -> V_80 [ V_94 ] = V_94 ;
V_79 -> V_81 [ V_94 ] = V_94 ;
V_79 -> V_82 [ V_94 ] = V_94 ;
}
V_111 = F_43 ( V_4 , V_108 -> V_119 -> V_74 ) ;
for ( V_94 = 0 ; V_94 < V_4 -> V_102 ; V_94 ++ ) {
if ( V_88 [ V_94 ] == V_111 ) {
F_26 ( L_13 ) ;
goto V_121;
}
}
F_26 ( L_14 ,
V_108 -> V_116 ) ;
V_90 [ V_84 ] = F_46 ( V_106 , V_31 , V_33 ) ;
if ( ! V_90 [ V_84 ] ) {
F_26 ( L_15 ,
V_108 -> V_116 , V_108 -> V_113 ) ;
V_90 [ V_84 ] = F_47 ( V_106 , V_31 ,
V_33 ) ;
}
if ( ! V_90 [ V_84 ] && ! F_48 ( & V_108 -> V_90 ) ) {
F_26 ( L_16 ,
V_108 -> V_116 ) ;
V_90 [ V_84 ] = F_49 ( & V_108 -> V_90 ,
struct V_89 ,
V_122 ) ;
}
if ( ! V_90 [ V_84 ] ) {
F_26 ( L_17 ,
V_108 -> V_116 ) ;
V_90 [ V_84 ] = & V_108 -> V_119 -> V_74 -> V_123 ;
}
V_88 [ V_84 ] = V_111 ;
F_26 ( L_18 ,
V_108 -> V_116 ,
F_50 ( F_41 ( V_108 -> V_119 -> V_74 ) -> V_124 ) ,
V_108 -> V_119 -> V_74 -> V_41 . V_51 ,
V_90 [ V_84 ] -> V_125 , V_90 [ V_84 ] -> V_126 ,
V_90 [ V_84 ] -> V_52 & V_127 ? L_19 : L_20 ) ;
V_96 = false ;
V_99 |= ( 1 << V_84 ) ;
}
if ( ( V_99 & V_100 ) != V_100 ) {
V_101 ++ ;
goto V_104;
}
if ( V_97 != V_98 &&
V_97 < F_51 ( V_10 ) -> V_128 ) {
F_26 ( L_21 ) ;
F_26 ( L_22 , V_97 ,
V_98 ) ;
V_96 = true ;
}
if ( V_96 ) {
V_121:
F_26 ( L_23 ) ;
memcpy ( V_93 , V_95 , V_4 -> V_102 ) ;
F_52 ( V_95 ) ;
return false ;
}
F_52 ( V_95 ) ;
return true ;
}
static void F_53 ( struct V_21 * V_10 ,
struct V_6 * V_7 )
{
F_54 ( & V_7 -> V_8 ) ;
F_38 ( & V_7 -> V_8 ) ;
F_55 ( & V_7 -> V_8 ) ;
if ( V_7 -> V_12 ) {
F_56 ( & V_7 -> V_12 -> V_41 ) ;
F_57 ( & V_7 -> V_12 -> V_41 ) ;
}
}
static bool F_58 ( struct V_21 * V_10 ,
struct V_6 * V_7 )
{
struct V_42 * V_12 = NULL ;
struct V_73 * V_74 ;
struct V_79 * V_79 ;
unsigned int V_129 = 0 ;
F_59 (dev, crtc) {
struct V_28 * V_13 =
F_60 ( V_74 -> V_130 -> V_119 -> V_12 ) ;
V_79 = F_41 ( V_74 ) ;
if ( ! V_74 -> V_119 -> V_131 || ! V_13 ) {
F_26 ( L_24 ,
F_50 ( V_79 -> V_124 ) ) ;
continue;
}
if ( V_13 -> V_41 . V_29 > V_129 ) {
F_26 ( L_25 ,
F_50 ( V_79 -> V_124 ) ) ;
V_12 = F_24 ( V_74 -> V_130 -> V_119 -> V_12 ) ;
V_129 = V_13 -> V_41 . V_29 ;
}
}
if ( ! V_12 ) {
F_26 ( L_26 ) ;
goto V_40;
}
F_59 (dev, crtc) {
unsigned int V_132 ;
V_79 = F_41 ( V_74 ) ;
if ( ! V_74 -> V_119 -> V_131 ) {
F_26 ( L_27 ,
F_50 ( V_79 -> V_124 ) ) ;
continue;
}
F_26 ( L_28 ,
F_50 ( V_79 -> V_124 ) ) ;
V_132 = V_79 -> V_133 -> V_41 . V_134 . V_135 ;
V_132 = V_132 * V_12 -> V_41 . V_136 / 8 ;
if ( V_12 -> V_41 . V_35 [ 0 ] < V_132 ) {
F_26 ( L_29 ,
F_50 ( V_79 -> V_124 ) ,
V_132 , V_12 -> V_41 . V_35 [ 0 ] ) ;
V_12 = NULL ;
break;
}
V_132 = V_79 -> V_133 -> V_41 . V_134 . V_137 ;
V_132 = F_61 ( V_10 , V_132 ,
V_12 -> V_41 . V_36 ,
V_12 -> V_41 . V_138 [ 0 ] ) ;
V_132 *= V_12 -> V_41 . V_35 [ 0 ] ;
F_26 ( L_30 ,
F_50 ( V_79 -> V_124 ) ,
V_79 -> V_133 -> V_41 . V_134 . V_135 ,
V_79 -> V_133 -> V_41 . V_134 . V_137 ,
V_12 -> V_41 . V_136 ,
V_132 ) ;
if ( V_132 > V_129 ) {
F_26 ( L_31 ,
F_50 ( V_79 -> V_124 ) ,
V_132 , V_129 ) ;
V_12 = NULL ;
break;
}
F_26 ( L_32 ,
F_50 ( V_79 -> V_124 ) ,
V_129 , V_132 ) ;
}
if ( ! V_12 ) {
F_26 ( L_33 ) ;
goto V_40;
}
V_7 -> V_139 = V_12 -> V_41 . V_136 ;
V_7 -> V_12 = V_12 ;
F_62 ( & V_7 -> V_12 -> V_41 ) ;
F_59 (dev, crtc) {
V_79 = F_41 ( V_74 ) ;
if ( ! V_74 -> V_119 -> V_131 )
continue;
F_63 ( ! V_74 -> V_130 -> V_12 ,
L_34 ,
V_74 -> V_41 . V_51 ) ;
}
F_26 ( L_35 ) ;
return true ;
V_40:
return false ;
}
static void F_64 ( struct V_140 * V_141 )
{
F_65 ( F_2 ( V_141 ,
struct V_22 ,
V_142 ) -> V_10 ,
V_143 ,
true ) ;
}
int F_66 ( struct V_21 * V_10 )
{
struct V_6 * V_7 ;
struct V_22 * V_23 = V_10 -> V_144 ;
int V_9 ;
if ( F_28 ( F_51 ( V_10 ) -> V_128 == 0 ) )
return - V_145 ;
V_7 = F_67 ( sizeof( struct V_6 ) , V_103 ) ;
if ( V_7 == NULL )
return - V_39 ;
F_68 ( V_10 , & V_7 -> V_8 , & V_146 ) ;
if ( ! F_58 ( V_10 , V_7 ) )
V_7 -> V_139 = 32 ;
V_9 = F_69 ( V_10 , & V_7 -> V_8 ,
F_51 ( V_10 ) -> V_128 , 4 ) ;
if ( V_9 ) {
F_52 ( V_7 ) ;
return V_9 ;
}
V_7 -> V_8 . V_147 = true ;
V_23 -> V_148 = V_7 ;
F_70 ( & V_23 -> V_142 , F_64 ) ;
F_71 ( & V_7 -> V_8 ) ;
return 0 ;
}
static void F_72 ( void * V_149 , T_3 V_150 )
{
struct V_22 * V_23 = V_149 ;
struct V_6 * V_7 = V_23 -> V_148 ;
if ( F_73 ( & V_7 -> V_8 ,
V_7 -> V_139 ) )
F_74 ( V_23 -> V_10 ) ;
}
void F_75 ( struct V_21 * V_10 )
{
F_76 ( F_72 , F_12 ( V_10 ) ) ;
}
void F_74 ( struct V_21 * V_10 )
{
struct V_22 * V_23 = V_10 -> V_144 ;
if ( ! V_23 -> V_148 )
return;
F_77 ( & V_23 -> V_142 ) ;
if ( ! F_78 () )
F_79 () ;
F_53 ( V_10 , V_23 -> V_148 ) ;
F_52 ( V_23 -> V_148 ) ;
V_23 -> V_148 = NULL ;
}
void F_65 ( struct V_21 * V_10 , int V_119 , bool V_151 )
{
struct V_22 * V_23 = V_10 -> V_144 ;
struct V_6 * V_7 = V_23 -> V_148 ;
struct V_1 * V_2 ;
if ( ! V_7 )
return;
V_2 = V_7 -> V_8 . V_148 ;
if ( V_151 ) {
if ( V_119 != V_143 )
F_77 ( & V_23 -> V_142 ) ;
F_80 () ;
} else {
F_28 ( V_119 != V_143 ) ;
if ( ! F_81 () ) {
F_82 ( & V_23 -> V_142 ) ;
return;
}
}
if ( V_119 == V_143 && V_7 -> V_12 -> V_13 -> V_71 )
F_36 ( V_2 -> V_64 , 0 , V_2 -> V_68 ) ;
F_83 ( & V_7 -> V_8 , V_119 ) ;
F_84 () ;
}
void F_85 ( struct V_21 * V_10 )
{
struct V_22 * V_23 = V_10 -> V_144 ;
if ( V_23 -> V_148 )
F_86 ( & V_23 -> V_148 -> V_8 ) ;
}
void F_87 ( struct V_21 * V_10 )
{
int V_9 ;
struct V_22 * V_23 = V_10 -> V_144 ;
struct V_6 * V_7 = V_23 -> V_148 ;
struct V_3 * V_4 ;
if ( ! V_7 )
return;
V_4 = & V_7 -> V_8 ;
V_9 = F_88 ( V_4 ) ;
if ( V_9 ) {
F_89 ( L_36 ) ;
} else {
F_4 ( & V_4 -> V_10 -> V_11 ) ;
F_5 ( V_7 -> V_12 -> V_13 , V_14 ) ;
F_6 ( & V_4 -> V_10 -> V_11 ) ;
}
}
