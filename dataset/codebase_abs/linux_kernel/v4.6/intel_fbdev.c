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
struct V_24 V_25 = {} ;
struct V_26 * V_13 = NULL ;
int V_27 , V_9 ;
if ( V_19 -> V_28 == 24 )
V_19 -> V_28 = 32 ;
V_25 . V_29 = V_19 -> V_30 ;
V_25 . V_31 = V_19 -> V_32 ;
V_25 . V_33 [ 0 ] = F_13 ( V_25 . V_29 *
F_14 ( V_19 -> V_28 , 8 ) , 64 ) ;
V_25 . V_34 = F_15 ( V_19 -> V_28 ,
V_19 -> V_35 ) ;
F_4 ( & V_10 -> V_11 ) ;
V_27 = V_25 . V_33 [ 0 ] * V_25 . V_31 ;
V_27 = F_16 ( V_27 ) ;
if ( V_27 * 2 < V_23 -> V_36 . V_37 )
V_13 = F_17 ( V_10 , V_27 ) ;
if ( V_13 == NULL )
V_13 = F_18 ( V_10 , V_27 ) ;
if ( ! V_13 ) {
F_19 ( L_1 ) ;
V_9 = - V_38 ;
goto V_39;
}
V_12 = F_20 ( V_10 , & V_25 , V_13 ) ;
if ( F_21 ( V_12 ) ) {
F_22 ( & V_13 -> V_40 ) ;
V_9 = F_23 ( V_12 ) ;
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
struct V_22 * V_23 = V_10 -> V_43 ;
struct V_1 * V_2 ;
struct V_20 * V_12 ;
struct V_26 * V_13 ;
int V_27 , V_9 ;
bool V_44 = false ;
if ( V_42 &&
( V_19 -> V_45 > V_42 -> V_40 . V_29 ||
V_19 -> V_46 > V_42 -> V_40 . V_31 ) ) {
F_26 ( L_2
L_3 ,
V_42 -> V_40 . V_29 , V_42 -> V_40 . V_31 ,
V_19 -> V_45 , V_19 -> V_46 ) ;
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
V_44 = true ;
V_19 -> V_45 = V_42 -> V_40 . V_29 ;
V_19 -> V_46 = V_42 -> V_40 . V_31 ;
}
V_13 = V_42 -> V_13 ;
V_27 = V_13 -> V_40 . V_27 ;
F_4 ( & V_10 -> V_11 ) ;
V_9 = F_29 ( NULL , & V_7 -> V_12 -> V_40 , NULL ) ;
if ( V_9 )
goto V_47;
V_2 = F_30 ( V_8 ) ;
if ( F_21 ( V_2 ) ) {
F_19 ( L_6 ) ;
V_9 = F_23 ( V_2 ) ;
goto V_48;
}
V_2 -> V_5 = V_8 ;
V_12 = & V_7 -> V_12 -> V_40 ;
V_7 -> V_8 . V_12 = V_12 ;
strcpy ( V_2 -> V_49 . V_50 , L_7 ) ;
V_2 -> V_51 = V_52 | V_53 ;
V_2 -> V_54 = & V_55 ;
V_2 -> V_56 -> V_57 [ 0 ] . V_40 = V_10 -> V_58 . V_59 ;
V_2 -> V_56 -> V_57 [ 0 ] . V_27 = V_23 -> V_36 . V_60 ;
V_2 -> V_49 . V_61 = V_10 -> V_58 . V_59 + F_31 ( V_13 ) ;
V_2 -> V_49 . V_62 = V_27 ;
V_2 -> V_63 =
F_32 ( V_23 -> V_36 . V_64 + F_31 ( V_13 ) ,
V_27 ) ;
if ( ! V_2 -> V_63 ) {
F_19 ( L_8 ) ;
V_9 = - V_65 ;
goto V_66;
}
V_2 -> V_67 = V_27 ;
V_2 -> V_68 = true ;
F_33 ( V_2 , V_12 -> V_33 [ 0 ] , V_12 -> V_69 ) ;
F_34 ( V_2 , & V_7 -> V_8 , V_19 -> V_45 , V_19 -> V_46 ) ;
if ( V_7 -> V_12 -> V_13 -> V_70 && ! V_44 )
F_35 ( V_2 -> V_63 , 0 , V_2 -> V_67 ) ;
F_26 ( L_9 ,
V_12 -> V_29 , V_12 -> V_31 ,
F_31 ( V_13 ) , V_13 ) ;
F_6 ( & V_10 -> V_11 ) ;
F_36 ( V_10 -> V_71 , V_2 ) ;
return 0 ;
V_66:
F_37 ( V_8 ) ;
V_48:
F_38 ( V_13 ) ;
V_47:
F_6 ( & V_10 -> V_11 ) ;
return V_9 ;
}
static void F_39 ( struct V_72 * V_73 , T_1 V_74 , T_1 V_75 ,
T_1 V_76 , int V_77 )
{
struct V_78 * V_78 = F_40 ( V_73 ) ;
V_78 -> V_79 [ V_77 ] = V_74 >> 8 ;
V_78 -> V_80 [ V_77 ] = V_75 >> 8 ;
V_78 -> V_81 [ V_77 ] = V_76 >> 8 ;
}
static void F_41 ( struct V_72 * V_73 , T_1 * V_74 , T_1 * V_75 ,
T_1 * V_76 , int V_77 )
{
struct V_78 * V_78 = F_40 ( V_73 ) ;
* V_74 = V_78 -> V_79 [ V_77 ] << 8 ;
* V_75 = V_78 -> V_80 [ V_77 ] << 8 ;
* V_76 = V_78 -> V_81 [ V_77 ] << 8 ;
}
static struct V_82 *
F_42 ( struct V_3 * V_4 , struct V_72 * V_73 )
{
int V_83 ;
for ( V_83 = 0 ; V_83 < V_4 -> V_84 ; V_83 ++ )
if ( V_4 -> V_85 [ V_83 ] . V_86 . V_73 == V_73 )
return & V_4 -> V_85 [ V_83 ] ;
return NULL ;
}
static bool F_43 ( struct V_3 * V_4 ,
struct V_82 * * V_87 ,
struct V_88 * * V_89 ,
struct V_90 * V_91 ,
bool * V_92 , int V_29 , int V_31 )
{
struct V_21 * V_10 = V_4 -> V_10 ;
int V_83 , V_93 ;
bool * V_94 ;
bool V_95 = true ;
int V_96 = 0 ;
int V_97 = 0 ;
T_2 V_98 = 0 , V_99 ;
int V_100 = 0 ;
V_94 = F_44 ( V_10 -> V_58 . V_101 , sizeof( bool ) ,
V_102 ) ;
if ( ! V_94 )
return false ;
memcpy ( V_94 , V_92 , V_10 -> V_58 . V_101 ) ;
V_99 = ( 1 << V_4 -> V_103 ) - 1 ;
V_104:
for ( V_83 = 0 ; V_83 < V_4 -> V_103 ; V_83 ++ ) {
struct V_105 * V_106 ;
struct V_107 * V_108 ;
struct V_109 * V_110 ;
struct V_82 * V_111 ;
V_106 = V_4 -> V_112 [ V_83 ] ;
V_108 = V_106 -> V_108 ;
if ( V_98 & ( 1 << V_83 ) )
continue;
if ( V_100 == 0 && ! V_108 -> V_113 )
continue;
if ( V_108 -> V_114 == V_115 )
V_97 ++ ;
if ( ! V_92 [ V_83 ] ) {
F_26 ( L_10 ,
V_108 -> V_116 ) ;
V_98 |= ( 1 << V_83 ) ;
continue;
}
if ( V_108 -> V_117 == V_118 ) {
F_26 ( L_11 ,
V_108 -> V_116 ) ;
V_92 [ V_83 ] = false ;
continue;
}
V_110 = V_108 -> V_119 -> V_120 ;
if ( ! V_110 || F_28 ( ! V_108 -> V_119 -> V_73 ) ) {
if ( V_108 -> V_117 > V_118 )
goto V_121;
F_26 ( L_12 ,
V_108 -> V_116 ) ;
V_92 [ V_83 ] = false ;
V_98 |= ( 1 << V_83 ) ;
continue;
}
V_96 ++ ;
V_111 = F_42 ( V_4 , V_108 -> V_119 -> V_73 ) ;
for ( V_93 = 0 ; V_93 < V_4 -> V_103 ; V_93 ++ ) {
if ( V_87 [ V_93 ] == V_111 ) {
F_26 ( L_13 ) ;
goto V_121;
}
}
F_26 ( L_14 ,
V_108 -> V_116 ) ;
V_89 [ V_83 ] = F_45 ( V_106 , V_29 , V_31 ) ;
if ( ! V_89 [ V_83 ] ) {
F_26 ( L_15 ,
V_108 -> V_116 , V_108 -> V_113 ) ;
V_89 [ V_83 ] = F_46 ( V_106 , V_29 ,
V_31 ) ;
}
if ( ! V_89 [ V_83 ] && ! F_47 ( & V_108 -> V_89 ) ) {
F_26 ( L_16 ,
V_108 -> V_116 ) ;
V_89 [ V_83 ] = F_48 ( & V_108 -> V_89 ,
struct V_88 ,
V_122 ) ;
}
if ( ! V_89 [ V_83 ] ) {
F_26 ( L_17 ,
V_108 -> V_116 ) ;
V_89 [ V_83 ] = & V_108 -> V_119 -> V_73 -> V_123 ;
}
V_87 [ V_83 ] = V_111 ;
F_26 ( L_18 ,
V_108 -> V_116 ,
F_49 ( F_40 ( V_108 -> V_119 -> V_73 ) -> V_124 ) ,
V_108 -> V_119 -> V_73 -> V_40 . V_50 ,
V_89 [ V_83 ] -> V_125 , V_89 [ V_83 ] -> V_126 ,
V_89 [ V_83 ] -> V_51 & V_127 ? L_19 : L_20 ) ;
V_95 = false ;
V_98 |= ( 1 << V_83 ) ;
}
if ( ( V_98 & V_99 ) != V_99 ) {
V_100 ++ ;
goto V_104;
}
if ( V_96 != V_97 &&
V_96 < F_50 ( V_10 ) -> V_128 ) {
F_26 ( L_21 ) ;
F_26 ( L_22 , V_96 ,
V_97 ) ;
V_95 = true ;
}
if ( V_95 ) {
V_121:
F_26 ( L_23 ) ;
memcpy ( V_92 , V_94 , V_10 -> V_58 . V_101 ) ;
F_51 ( V_94 ) ;
return false ;
}
F_51 ( V_94 ) ;
return true ;
}
static void F_52 ( struct V_21 * V_10 ,
struct V_6 * V_7 )
{
F_53 ( & V_7 -> V_8 ) ;
F_37 ( & V_7 -> V_8 ) ;
F_54 ( & V_7 -> V_8 ) ;
if ( V_7 -> V_12 ) {
F_55 ( & V_7 -> V_12 -> V_40 ) ;
F_56 ( & V_7 -> V_12 -> V_40 ) ;
}
}
static bool F_57 ( struct V_21 * V_10 ,
struct V_6 * V_7 )
{
struct V_41 * V_12 = NULL ;
struct V_72 * V_73 ;
struct V_78 * V_78 ;
unsigned int V_129 = 0 ;
F_58 (dev, crtc) {
struct V_26 * V_13 =
F_59 ( V_73 -> V_130 -> V_119 -> V_12 ) ;
V_78 = F_40 ( V_73 ) ;
if ( ! V_73 -> V_119 -> V_131 || ! V_13 ) {
F_26 ( L_24 ,
F_49 ( V_78 -> V_124 ) ) ;
continue;
}
if ( V_13 -> V_40 . V_27 > V_129 ) {
F_26 ( L_25 ,
F_49 ( V_78 -> V_124 ) ) ;
V_12 = F_24 ( V_73 -> V_130 -> V_119 -> V_12 ) ;
V_129 = V_13 -> V_40 . V_27 ;
}
}
if ( ! V_12 ) {
F_26 ( L_26 ) ;
goto V_39;
}
F_58 (dev, crtc) {
unsigned int V_132 ;
V_78 = F_40 ( V_73 ) ;
if ( ! V_73 -> V_119 -> V_131 ) {
F_26 ( L_27 ,
F_49 ( V_78 -> V_124 ) ) ;
continue;
}
F_26 ( L_28 ,
F_49 ( V_78 -> V_124 ) ) ;
V_132 = V_78 -> V_133 -> V_40 . V_134 . V_135 ;
V_132 = V_132 * V_12 -> V_40 . V_136 / 8 ;
if ( V_12 -> V_40 . V_33 [ 0 ] < V_132 ) {
F_26 ( L_29 ,
F_49 ( V_78 -> V_124 ) ,
V_132 , V_12 -> V_40 . V_33 [ 0 ] ) ;
V_12 = NULL ;
break;
}
V_132 = V_78 -> V_133 -> V_40 . V_134 . V_137 ;
V_132 = F_60 ( V_10 , V_132 ,
V_12 -> V_40 . V_34 ,
V_12 -> V_40 . V_138 [ 0 ] ) ;
V_132 *= V_12 -> V_40 . V_33 [ 0 ] ;
F_26 ( L_30 ,
F_49 ( V_78 -> V_124 ) ,
V_78 -> V_133 -> V_40 . V_134 . V_135 ,
V_78 -> V_133 -> V_40 . V_134 . V_137 ,
V_12 -> V_40 . V_136 ,
V_132 ) ;
if ( V_132 > V_129 ) {
F_26 ( L_31 ,
F_49 ( V_78 -> V_124 ) ,
V_132 , V_129 ) ;
V_12 = NULL ;
break;
}
F_26 ( L_32 ,
F_49 ( V_78 -> V_124 ) ,
V_129 , V_132 ) ;
}
if ( ! V_12 ) {
F_26 ( L_33 ) ;
goto V_39;
}
V_7 -> V_139 = V_12 -> V_40 . V_136 ;
V_7 -> V_12 = V_12 ;
F_61 ( & V_7 -> V_12 -> V_40 ) ;
F_58 (dev, crtc) {
V_78 = F_40 ( V_73 ) ;
if ( ! V_73 -> V_119 -> V_131 )
continue;
F_62 ( ! V_73 -> V_130 -> V_12 ,
L_34 ,
V_73 -> V_40 . V_50 ) ;
}
F_26 ( L_35 ) ;
return true ;
V_39:
return false ;
}
static void F_63 ( struct V_140 * V_141 )
{
F_64 ( F_2 ( V_141 ,
struct V_22 ,
V_142 ) -> V_10 ,
V_143 ,
true ) ;
}
int F_65 ( struct V_21 * V_10 )
{
struct V_6 * V_7 ;
struct V_22 * V_23 = V_10 -> V_43 ;
int V_9 ;
if ( F_28 ( F_50 ( V_10 ) -> V_128 == 0 ) )
return - V_144 ;
V_7 = F_66 ( sizeof( struct V_6 ) , V_102 ) ;
if ( V_7 == NULL )
return - V_38 ;
F_67 ( V_10 , & V_7 -> V_8 , & V_145 ) ;
if ( ! F_57 ( V_10 , V_7 ) )
V_7 -> V_139 = 32 ;
V_9 = F_68 ( V_10 , & V_7 -> V_8 ,
F_50 ( V_10 ) -> V_128 , 4 ) ;
if ( V_9 ) {
F_51 ( V_7 ) ;
return V_9 ;
}
V_7 -> V_8 . V_146 = true ;
V_23 -> V_147 = V_7 ;
F_69 ( & V_23 -> V_142 , F_63 ) ;
F_70 ( & V_7 -> V_8 ) ;
return 0 ;
}
static void F_71 ( void * V_148 , T_3 V_149 )
{
struct V_22 * V_23 = V_148 ;
struct V_6 * V_7 = V_23 -> V_147 ;
if ( F_72 ( & V_7 -> V_8 ,
V_7 -> V_139 ) )
F_73 ( V_23 -> V_10 ) ;
}
void F_74 ( struct V_21 * V_10 )
{
F_75 ( F_71 , F_12 ( V_10 ) ) ;
}
void F_73 ( struct V_21 * V_10 )
{
struct V_22 * V_23 = V_10 -> V_43 ;
if ( ! V_23 -> V_147 )
return;
F_76 ( & V_23 -> V_142 ) ;
if ( ! F_77 () )
F_78 () ;
F_52 ( V_10 , V_23 -> V_147 ) ;
F_51 ( V_23 -> V_147 ) ;
V_23 -> V_147 = NULL ;
}
void F_64 ( struct V_21 * V_10 , int V_119 , bool V_150 )
{
struct V_22 * V_23 = V_10 -> V_43 ;
struct V_6 * V_7 = V_23 -> V_147 ;
struct V_1 * V_2 ;
if ( ! V_7 )
return;
V_2 = V_7 -> V_8 . V_147 ;
if ( V_150 ) {
if ( V_119 != V_143 )
F_76 ( & V_23 -> V_142 ) ;
F_79 () ;
} else {
F_28 ( V_119 != V_143 ) ;
if ( ! F_80 () ) {
F_81 ( & V_23 -> V_142 ) ;
return;
}
}
if ( V_119 == V_143 && V_7 -> V_12 -> V_13 -> V_70 )
F_35 ( V_2 -> V_63 , 0 , V_2 -> V_67 ) ;
F_82 ( & V_7 -> V_8 , V_119 ) ;
F_83 () ;
}
void F_84 ( struct V_21 * V_10 )
{
struct V_22 * V_23 = V_10 -> V_43 ;
if ( V_23 -> V_147 )
F_85 ( & V_23 -> V_147 -> V_8 ) ;
}
void F_86 ( struct V_21 * V_10 )
{
int V_9 ;
struct V_22 * V_23 = V_10 -> V_43 ;
struct V_6 * V_7 = V_23 -> V_147 ;
struct V_3 * V_4 ;
if ( ! V_7 )
return;
V_4 = & V_7 -> V_8 ;
V_9 = F_87 ( V_4 ) ;
if ( V_9 ) {
F_88 ( L_36 ) ;
} else {
F_4 ( & V_4 -> V_10 -> V_11 ) ;
F_5 ( V_7 -> V_12 -> V_13 , V_14 ) ;
F_6 ( & V_4 -> V_10 -> V_11 ) ;
}
}
