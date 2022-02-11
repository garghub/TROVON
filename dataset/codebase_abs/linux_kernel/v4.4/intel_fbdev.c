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
V_9 = F_22 ( V_12 ) ;
goto V_40;
}
V_9 = F_23 ( NULL , V_12 , NULL , NULL , NULL ) ;
if ( V_9 ) {
F_19 ( L_2 , V_9 ) ;
goto V_41;
}
V_7 -> V_12 = F_24 ( V_12 ) ;
return 0 ;
V_41:
F_25 ( V_12 ) ;
V_40:
F_26 ( & V_13 -> V_42 ) ;
V_39:
return V_9 ;
}
static int F_27 ( struct V_3 * V_8 ,
struct V_18 * V_19 )
{
struct V_6 * V_7 =
F_2 ( V_8 , struct V_6 , V_8 ) ;
struct V_43 * V_44 = V_7 -> V_12 ;
struct V_21 * V_10 = V_8 -> V_10 ;
struct V_22 * V_23 = V_10 -> V_45 ;
struct V_1 * V_2 ;
struct V_20 * V_12 ;
struct V_26 * V_13 ;
int V_27 , V_9 ;
bool V_46 = false ;
F_4 ( & V_10 -> V_11 ) ;
if ( V_44 &&
( V_19 -> V_47 > V_44 -> V_42 . V_29 ||
V_19 -> V_48 > V_44 -> V_42 . V_31 ) ) {
F_28 ( L_3
L_4 ,
V_44 -> V_42 . V_29 , V_44 -> V_42 . V_31 ,
V_19 -> V_47 , V_19 -> V_48 ) ;
F_29 ( & V_44 -> V_42 ) ;
V_44 = V_7 -> V_12 = NULL ;
}
if ( ! V_44 || F_30 ( ! V_44 -> V_13 ) ) {
F_28 ( L_5 ) ;
V_9 = F_11 ( V_8 , V_19 ) ;
if ( V_9 )
goto V_49;
V_44 = V_7 -> V_12 ;
} else {
F_28 ( L_6 ) ;
V_46 = true ;
V_19 -> V_47 = V_44 -> V_42 . V_29 ;
V_19 -> V_48 = V_44 -> V_42 . V_31 ;
}
V_13 = V_44 -> V_13 ;
V_27 = V_13 -> V_42 . V_27 ;
V_2 = F_31 ( V_8 ) ;
if ( F_21 ( V_2 ) ) {
V_9 = F_22 ( V_2 ) ;
goto V_50;
}
V_2 -> V_5 = V_8 ;
V_12 = & V_7 -> V_12 -> V_42 ;
V_7 -> V_8 . V_12 = V_12 ;
strcpy ( V_2 -> V_51 . V_52 , L_7 ) ;
V_2 -> V_53 = V_54 | V_55 ;
V_2 -> V_56 = & V_57 ;
V_2 -> V_58 -> V_59 [ 0 ] . V_42 = V_10 -> V_60 . V_61 ;
V_2 -> V_58 -> V_59 [ 0 ] . V_27 = V_23 -> V_36 . V_62 ;
V_2 -> V_51 . V_63 = V_10 -> V_60 . V_61 + F_32 ( V_13 ) ;
V_2 -> V_51 . V_64 = V_27 ;
V_2 -> V_65 =
F_33 ( V_23 -> V_36 . V_66 + F_32 ( V_13 ) ,
V_27 ) ;
if ( ! V_2 -> V_65 ) {
V_9 = - V_67 ;
goto V_68;
}
V_2 -> V_69 = V_27 ;
V_2 -> V_70 = true ;
F_34 ( V_2 , V_12 -> V_33 [ 0 ] , V_12 -> V_71 ) ;
F_35 ( V_2 , & V_7 -> V_8 , V_19 -> V_47 , V_19 -> V_48 ) ;
if ( V_7 -> V_12 -> V_13 -> V_72 && ! V_46 )
F_36 ( V_2 -> V_65 , 0 , V_2 -> V_69 ) ;
F_28 ( L_8 ,
V_12 -> V_29 , V_12 -> V_31 ,
F_32 ( V_13 ) , V_13 ) ;
F_6 ( & V_10 -> V_11 ) ;
F_37 ( V_10 -> V_73 , V_2 ) ;
return 0 ;
V_68:
F_38 ( V_8 ) ;
V_50:
F_39 ( V_13 ) ;
F_26 ( & V_13 -> V_42 ) ;
V_49:
F_6 ( & V_10 -> V_11 ) ;
return V_9 ;
}
static void F_40 ( struct V_74 * V_75 , T_1 V_76 , T_1 V_77 ,
T_1 V_78 , int V_79 )
{
struct V_80 * V_80 = F_41 ( V_75 ) ;
V_80 -> V_81 [ V_79 ] = V_76 >> 8 ;
V_80 -> V_82 [ V_79 ] = V_77 >> 8 ;
V_80 -> V_83 [ V_79 ] = V_78 >> 8 ;
}
static void F_42 ( struct V_74 * V_75 , T_1 * V_76 , T_1 * V_77 ,
T_1 * V_78 , int V_79 )
{
struct V_80 * V_80 = F_41 ( V_75 ) ;
* V_76 = V_80 -> V_81 [ V_79 ] << 8 ;
* V_77 = V_80 -> V_82 [ V_79 ] << 8 ;
* V_78 = V_80 -> V_83 [ V_79 ] << 8 ;
}
static struct V_84 *
F_43 ( struct V_3 * V_4 , struct V_74 * V_75 )
{
int V_85 ;
for ( V_85 = 0 ; V_85 < V_4 -> V_86 ; V_85 ++ )
if ( V_4 -> V_87 [ V_85 ] . V_88 . V_75 == V_75 )
return & V_4 -> V_87 [ V_85 ] ;
return NULL ;
}
static bool F_44 ( struct V_3 * V_4 ,
struct V_84 * * V_89 ,
struct V_90 * * V_91 ,
struct V_92 * V_93 ,
bool * V_94 , int V_29 , int V_31 )
{
struct V_21 * V_10 = V_4 -> V_10 ;
int V_85 , V_95 ;
bool * V_96 ;
bool V_97 = true ;
int V_98 = 0 ;
int V_99 = 0 ;
T_2 V_100 = 0 , V_101 ;
int V_102 = 0 ;
V_96 = F_45 ( V_10 -> V_60 . V_103 , sizeof( bool ) ,
V_104 ) ;
if ( ! V_96 )
return false ;
memcpy ( V_96 , V_94 , V_10 -> V_60 . V_103 ) ;
V_101 = ( 1 << V_4 -> V_105 ) - 1 ;
V_106:
for ( V_85 = 0 ; V_85 < V_4 -> V_105 ; V_85 ++ ) {
struct V_107 * V_108 ;
struct V_109 * V_110 ;
struct V_111 * V_112 ;
struct V_84 * V_113 ;
V_108 = V_4 -> V_114 [ V_85 ] ;
V_110 = V_108 -> V_110 ;
if ( V_100 & ( 1 << V_85 ) )
continue;
if ( V_102 == 0 && ! V_110 -> V_115 )
continue;
if ( V_110 -> V_116 == V_117 )
V_99 ++ ;
if ( ! V_94 [ V_85 ] ) {
F_28 ( L_9 ,
V_110 -> V_118 ) ;
V_100 |= ( 1 << V_85 ) ;
continue;
}
if ( V_110 -> V_119 == V_120 ) {
F_28 ( L_10 ,
V_110 -> V_118 ) ;
V_94 [ V_85 ] = false ;
continue;
}
V_112 = V_110 -> V_112 ;
if ( ! V_112 || F_30 ( ! V_112 -> V_75 ) ) {
if ( V_110 -> V_119 > V_120 )
goto V_121;
F_28 ( L_11 ,
V_110 -> V_118 ) ;
V_94 [ V_85 ] = false ;
V_100 |= ( 1 << V_85 ) ;
continue;
}
V_98 ++ ;
V_113 = F_43 ( V_4 , V_112 -> V_75 ) ;
for ( V_95 = 0 ; V_95 < V_4 -> V_105 ; V_95 ++ ) {
if ( V_89 [ V_95 ] == V_113 ) {
F_28 ( L_12 ) ;
goto V_121;
}
}
F_28 ( L_13 ,
V_110 -> V_118 ) ;
V_91 [ V_85 ] = F_46 ( V_108 , V_29 , V_31 ) ;
if ( ! V_91 [ V_85 ] ) {
F_28 ( L_14 ,
V_110 -> V_118 , V_110 -> V_115 ) ;
V_91 [ V_85 ] = F_47 ( V_108 , V_29 ,
V_31 ) ;
}
if ( ! V_91 [ V_85 ] && ! F_48 ( & V_110 -> V_91 ) ) {
F_28 ( L_15 ,
V_110 -> V_118 ) ;
V_91 [ V_85 ] = F_49 ( & V_110 -> V_91 ,
struct V_90 ,
V_122 ) ;
}
if ( ! V_91 [ V_85 ] ) {
F_28 ( L_16 ,
V_110 -> V_118 ) ;
V_91 [ V_85 ] = & V_112 -> V_75 -> V_123 ;
}
V_89 [ V_85 ] = V_113 ;
F_28 ( L_17 ,
V_110 -> V_118 ,
F_50 ( F_41 ( V_112 -> V_75 ) -> V_124 ) ,
V_112 -> V_75 -> V_42 . V_52 ,
V_91 [ V_85 ] -> V_125 , V_91 [ V_85 ] -> V_126 ,
V_91 [ V_85 ] -> V_53 & V_127 ? L_18 : L_19 ) ;
V_97 = false ;
V_100 |= ( 1 << V_85 ) ;
}
if ( ( V_100 & V_101 ) != V_101 ) {
V_102 ++ ;
goto V_106;
}
if ( V_98 != V_99 &&
V_98 < F_51 ( V_10 ) -> V_128 ) {
F_28 ( L_20 ) ;
F_28 ( L_21 , V_98 ,
V_99 ) ;
V_97 = true ;
}
if ( V_97 ) {
V_121:
F_28 ( L_22 ) ;
memcpy ( V_94 , V_96 , V_10 -> V_60 . V_103 ) ;
F_52 ( V_96 ) ;
return false ;
}
F_52 ( V_96 ) ;
return true ;
}
static void F_53 ( struct V_21 * V_10 ,
struct V_6 * V_7 )
{
F_54 ( & V_7 -> V_8 ) ;
F_38 ( & V_7 -> V_8 ) ;
F_55 ( & V_7 -> V_8 ) ;
F_56 ( & V_7 -> V_12 -> V_42 ) ;
F_25 ( & V_7 -> V_12 -> V_42 ) ;
}
static bool F_57 ( struct V_21 * V_10 ,
struct V_6 * V_7 )
{
struct V_43 * V_12 = NULL ;
struct V_74 * V_75 ;
struct V_80 * V_80 ;
unsigned int V_129 = 0 ;
F_58 (dev, crtc) {
struct V_26 * V_13 =
F_59 ( V_75 -> V_130 -> V_131 -> V_12 ) ;
V_80 = F_41 ( V_75 ) ;
if ( ! V_75 -> V_131 -> V_132 || ! V_13 ) {
F_28 ( L_23 ,
F_50 ( V_80 -> V_124 ) ) ;
continue;
}
if ( V_13 -> V_42 . V_27 > V_129 ) {
F_28 ( L_24 ,
F_50 ( V_80 -> V_124 ) ) ;
V_12 = F_24 ( V_75 -> V_130 -> V_131 -> V_12 ) ;
V_129 = V_13 -> V_42 . V_27 ;
}
}
if ( ! V_12 ) {
F_28 ( L_25 ) ;
goto V_39;
}
F_58 (dev, crtc) {
unsigned int V_133 ;
V_80 = F_41 ( V_75 ) ;
if ( ! V_75 -> V_131 -> V_132 ) {
F_28 ( L_26 ,
F_50 ( V_80 -> V_124 ) ) ;
continue;
}
F_28 ( L_27 ,
F_50 ( V_80 -> V_124 ) ) ;
V_133 = V_80 -> V_134 -> V_42 . V_135 . V_136 ;
V_133 = V_133 * V_12 -> V_42 . V_137 / 8 ;
if ( V_12 -> V_42 . V_33 [ 0 ] < V_133 ) {
F_28 ( L_28 ,
F_50 ( V_80 -> V_124 ) ,
V_133 , V_12 -> V_42 . V_33 [ 0 ] ) ;
V_12 = NULL ;
break;
}
V_133 = V_80 -> V_134 -> V_42 . V_135 . V_138 ;
V_133 = F_60 ( V_10 , V_133 ,
V_12 -> V_42 . V_34 ,
V_12 -> V_42 . V_139 [ 0 ] ) ;
V_133 *= V_12 -> V_42 . V_33 [ 0 ] ;
F_28 ( L_29 ,
F_50 ( V_80 -> V_124 ) ,
V_80 -> V_134 -> V_42 . V_135 . V_136 ,
V_80 -> V_134 -> V_42 . V_135 . V_138 ,
V_12 -> V_42 . V_137 ,
V_133 ) ;
if ( V_133 > V_129 ) {
F_28 ( L_30 ,
F_50 ( V_80 -> V_124 ) ,
V_133 , V_129 ) ;
V_12 = NULL ;
break;
}
F_28 ( L_31 ,
F_50 ( V_80 -> V_124 ) ,
V_129 , V_133 ) ;
}
if ( ! V_12 ) {
F_28 ( L_32 ) ;
goto V_39;
}
V_7 -> V_140 = V_12 -> V_42 . V_137 ;
V_7 -> V_12 = V_12 ;
F_61 ( & V_7 -> V_12 -> V_42 ) ;
F_58 (dev, crtc) {
V_80 = F_41 ( V_75 ) ;
if ( ! V_75 -> V_131 -> V_132 )
continue;
F_62 ( ! V_75 -> V_130 -> V_12 ,
L_33 ,
V_75 -> V_42 . V_52 ) ;
}
F_28 ( L_34 ) ;
return true ;
V_39:
return false ;
}
static void F_63 ( struct V_141 * V_142 )
{
F_64 ( F_2 ( V_142 ,
struct V_22 ,
V_143 ) -> V_10 ,
V_144 ,
true ) ;
}
int F_65 ( struct V_21 * V_10 )
{
struct V_6 * V_7 ;
struct V_22 * V_23 = V_10 -> V_45 ;
int V_9 ;
if ( F_30 ( F_51 ( V_10 ) -> V_128 == 0 ) )
return - V_145 ;
V_7 = F_66 ( sizeof( struct V_6 ) , V_104 ) ;
if ( V_7 == NULL )
return - V_38 ;
F_67 ( V_10 , & V_7 -> V_8 , & V_146 ) ;
if ( ! F_57 ( V_10 , V_7 ) )
V_7 -> V_140 = 32 ;
V_9 = F_68 ( V_10 , & V_7 -> V_8 ,
F_51 ( V_10 ) -> V_128 , 4 ) ;
if ( V_9 ) {
F_52 ( V_7 ) ;
return V_9 ;
}
V_7 -> V_8 . V_147 = true ;
V_23 -> V_148 = V_7 ;
F_69 ( & V_23 -> V_143 , F_63 ) ;
F_70 ( & V_7 -> V_8 ) ;
return 0 ;
}
void F_71 ( void * V_149 , T_3 V_150 )
{
struct V_22 * V_23 = V_149 ;
struct V_6 * V_7 = V_23 -> V_148 ;
F_72 ( & V_7 -> V_8 , V_7 -> V_140 ) ;
}
void F_73 ( struct V_21 * V_10 )
{
struct V_22 * V_23 = V_10 -> V_45 ;
if ( ! V_23 -> V_148 )
return;
F_74 ( & V_23 -> V_143 ) ;
F_75 () ;
F_53 ( V_10 , V_23 -> V_148 ) ;
F_52 ( V_23 -> V_148 ) ;
V_23 -> V_148 = NULL ;
}
void F_64 ( struct V_21 * V_10 , int V_131 , bool V_151 )
{
struct V_22 * V_23 = V_10 -> V_45 ;
struct V_6 * V_7 = V_23 -> V_148 ;
struct V_1 * V_2 ;
if ( ! V_7 )
return;
V_2 = V_7 -> V_8 . V_148 ;
if ( V_151 ) {
if ( V_131 != V_144 )
F_74 ( & V_23 -> V_143 ) ;
F_76 () ;
} else {
F_30 ( V_131 != V_144 ) ;
if ( ! F_77 () ) {
F_78 ( & V_23 -> V_143 ) ;
return;
}
}
if ( V_131 == V_144 && V_7 -> V_12 -> V_13 -> V_72 )
F_36 ( V_2 -> V_65 , 0 , V_2 -> V_69 ) ;
F_79 ( & V_7 -> V_8 , V_131 ) ;
F_80 () ;
}
void F_81 ( struct V_21 * V_10 )
{
struct V_22 * V_23 = V_10 -> V_45 ;
if ( V_23 -> V_148 )
F_82 ( & V_23 -> V_148 -> V_8 ) ;
}
void F_83 ( struct V_21 * V_10 )
{
int V_9 ;
struct V_22 * V_23 = V_10 -> V_45 ;
struct V_6 * V_7 = V_23 -> V_148 ;
struct V_3 * V_4 ;
if ( ! V_7 )
return;
V_4 = & V_7 -> V_8 ;
V_9 = F_84 ( V_4 ) ;
if ( V_9 ) {
F_85 ( L_35 ) ;
} else {
F_4 ( & V_4 -> V_10 -> V_11 ) ;
F_5 ( V_7 -> V_12 -> V_13 , V_14 ) ;
F_6 ( & V_4 -> V_10 -> V_11 ) ;
}
}
