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
struct V_22 V_23 = {} ;
struct V_24 * V_13 ;
int V_25 , V_9 ;
if ( V_19 -> V_26 == 24 )
V_19 -> V_26 = 32 ;
V_23 . V_27 = V_19 -> V_28 ;
V_23 . V_29 = V_19 -> V_30 ;
V_23 . V_31 [ 0 ] = F_12 ( V_23 . V_27 *
F_13 ( V_19 -> V_26 , 8 ) , 64 ) ;
V_23 . V_32 = F_14 ( V_19 -> V_26 ,
V_19 -> V_33 ) ;
V_25 = V_23 . V_31 [ 0 ] * V_23 . V_29 ;
V_25 = F_15 ( V_25 ) ;
V_13 = F_16 ( V_10 , V_25 ) ;
if ( V_13 == NULL )
V_13 = F_17 ( V_10 , V_25 ) ;
if ( ! V_13 ) {
F_18 ( L_1 ) ;
V_9 = - V_34 ;
goto V_35;
}
V_12 = F_19 ( V_10 , & V_23 , V_13 ) ;
if ( F_20 ( V_12 ) ) {
V_9 = F_21 ( V_12 ) ;
goto V_36;
}
V_9 = F_22 ( NULL , V_12 , NULL , NULL , NULL ) ;
if ( V_9 ) {
F_18 ( L_2 , V_9 ) ;
goto V_37;
}
V_7 -> V_12 = F_23 ( V_12 ) ;
return 0 ;
V_37:
F_24 ( V_12 ) ;
V_36:
F_25 ( & V_13 -> V_38 ) ;
V_35:
return V_9 ;
}
static int F_26 ( struct V_3 * V_8 ,
struct V_18 * V_19 )
{
struct V_6 * V_7 =
F_2 ( V_8 , struct V_6 , V_8 ) ;
struct V_39 * V_40 = V_7 -> V_12 ;
struct V_21 * V_10 = V_8 -> V_10 ;
struct V_41 * V_42 = V_10 -> V_43 ;
struct V_1 * V_2 ;
struct V_20 * V_12 ;
struct V_24 * V_13 ;
int V_25 , V_9 ;
bool V_44 = false ;
F_4 ( & V_10 -> V_11 ) ;
if ( V_40 &&
( V_19 -> V_45 > V_40 -> V_38 . V_27 ||
V_19 -> V_46 > V_40 -> V_38 . V_29 ) ) {
F_27 ( L_3
L_4 ,
V_40 -> V_38 . V_27 , V_40 -> V_38 . V_29 ,
V_19 -> V_45 , V_19 -> V_46 ) ;
F_28 ( & V_40 -> V_38 ) ;
V_40 = V_7 -> V_12 = NULL ;
}
if ( ! V_40 || F_29 ( ! V_40 -> V_13 ) ) {
F_27 ( L_5 ) ;
V_9 = F_11 ( V_8 , V_19 ) ;
if ( V_9 )
goto V_47;
V_40 = V_7 -> V_12 ;
} else {
F_27 ( L_6 ) ;
V_44 = true ;
V_19 -> V_45 = V_40 -> V_38 . V_27 ;
V_19 -> V_46 = V_40 -> V_38 . V_29 ;
}
V_13 = V_40 -> V_13 ;
V_25 = V_13 -> V_38 . V_25 ;
V_2 = F_30 ( V_8 ) ;
if ( F_20 ( V_2 ) ) {
V_9 = F_21 ( V_2 ) ;
goto V_48;
}
V_2 -> V_5 = V_8 ;
V_12 = & V_7 -> V_12 -> V_38 ;
V_7 -> V_8 . V_12 = V_12 ;
strcpy ( V_2 -> V_49 . V_50 , L_7 ) ;
V_2 -> V_51 = V_52 | V_53 ;
V_2 -> V_54 = & V_55 ;
V_2 -> V_56 -> V_57 [ 0 ] . V_38 = V_10 -> V_58 . V_59 ;
V_2 -> V_56 -> V_57 [ 0 ] . V_25 = V_42 -> V_60 . V_61 ;
V_2 -> V_49 . V_62 = V_10 -> V_58 . V_59 + F_31 ( V_13 ) ;
V_2 -> V_49 . V_63 = V_25 ;
V_2 -> V_64 =
F_32 ( V_42 -> V_60 . V_65 + F_31 ( V_13 ) ,
V_25 ) ;
if ( ! V_2 -> V_64 ) {
V_9 = - V_66 ;
goto V_67;
}
V_2 -> V_68 = V_25 ;
V_2 -> V_69 = true ;
F_33 ( V_2 , V_12 -> V_31 [ 0 ] , V_12 -> V_70 ) ;
F_34 ( V_2 , & V_7 -> V_8 , V_19 -> V_45 , V_19 -> V_46 ) ;
if ( V_7 -> V_12 -> V_13 -> V_71 && ! V_44 )
F_35 ( V_2 -> V_64 , 0 , V_2 -> V_68 ) ;
F_27 ( L_8 ,
V_12 -> V_27 , V_12 -> V_29 ,
F_31 ( V_13 ) , V_13 ) ;
F_6 ( & V_10 -> V_11 ) ;
F_36 ( V_10 -> V_72 , V_2 ) ;
return 0 ;
V_67:
F_37 ( V_8 ) ;
V_48:
F_38 ( V_13 ) ;
F_25 ( & V_13 -> V_38 ) ;
V_47:
F_6 ( & V_10 -> V_11 ) ;
return V_9 ;
}
static void F_39 ( struct V_73 * V_74 , T_1 V_75 , T_1 V_76 ,
T_1 V_77 , int V_78 )
{
struct V_79 * V_79 = F_40 ( V_74 ) ;
V_79 -> V_80 [ V_78 ] = V_75 >> 8 ;
V_79 -> V_81 [ V_78 ] = V_76 >> 8 ;
V_79 -> V_82 [ V_78 ] = V_77 >> 8 ;
}
static void F_41 ( struct V_73 * V_74 , T_1 * V_75 , T_1 * V_76 ,
T_1 * V_77 , int V_78 )
{
struct V_79 * V_79 = F_40 ( V_74 ) ;
* V_75 = V_79 -> V_80 [ V_78 ] << 8 ;
* V_76 = V_79 -> V_81 [ V_78 ] << 8 ;
* V_77 = V_79 -> V_82 [ V_78 ] << 8 ;
}
static struct V_83 *
F_42 ( struct V_3 * V_4 , struct V_73 * V_74 )
{
int V_84 ;
for ( V_84 = 0 ; V_84 < V_4 -> V_85 ; V_84 ++ )
if ( V_4 -> V_86 [ V_84 ] . V_87 . V_74 == V_74 )
return & V_4 -> V_86 [ V_84 ] ;
return NULL ;
}
static bool F_43 ( struct V_3 * V_4 ,
struct V_83 * * V_88 ,
struct V_89 * * V_90 ,
struct V_91 * V_92 ,
bool * V_93 , int V_27 , int V_29 )
{
struct V_21 * V_10 = V_4 -> V_10 ;
int V_84 , V_94 ;
bool * V_95 ;
bool V_96 = true ;
int V_97 = 0 ;
int V_98 = 0 ;
T_2 V_99 = 0 , V_100 ;
int V_101 = 0 ;
V_95 = F_44 ( V_10 -> V_58 . V_102 , sizeof( bool ) ,
V_103 ) ;
if ( ! V_95 )
return false ;
memcpy ( V_95 , V_93 , V_10 -> V_58 . V_102 ) ;
V_100 = ( 1 << V_4 -> V_104 ) - 1 ;
V_105:
for ( V_84 = 0 ; V_84 < V_4 -> V_104 ; V_84 ++ ) {
struct V_106 * V_107 ;
struct V_108 * V_109 ;
struct V_110 * V_111 ;
struct V_83 * V_112 ;
V_107 = V_4 -> V_113 [ V_84 ] ;
V_109 = V_107 -> V_109 ;
if ( V_99 & ( 1 << V_84 ) )
continue;
if ( V_101 == 0 && ! V_109 -> V_114 )
continue;
if ( V_109 -> V_115 == V_116 )
V_98 ++ ;
if ( ! V_93 [ V_84 ] ) {
F_27 ( L_9 ,
V_109 -> V_117 ) ;
V_99 |= ( 1 << V_84 ) ;
continue;
}
if ( V_109 -> V_118 == V_119 ) {
F_27 ( L_10 ,
V_109 -> V_117 ) ;
V_93 [ V_84 ] = false ;
continue;
}
V_111 = V_109 -> V_111 ;
if ( ! V_111 || F_29 ( ! V_111 -> V_74 ) ) {
if ( V_109 -> V_118 > V_119 )
goto V_120;
F_27 ( L_11 ,
V_109 -> V_117 ) ;
V_93 [ V_84 ] = false ;
V_99 |= ( 1 << V_84 ) ;
continue;
}
V_97 ++ ;
V_112 = F_42 ( V_4 , V_111 -> V_74 ) ;
for ( V_94 = 0 ; V_94 < V_4 -> V_104 ; V_94 ++ ) {
if ( V_88 [ V_94 ] == V_112 ) {
F_27 ( L_12 ) ;
goto V_120;
}
}
F_27 ( L_13 ,
V_109 -> V_117 ) ;
V_90 [ V_84 ] = F_45 ( V_107 , V_27 , V_29 ) ;
if ( ! V_90 [ V_84 ] ) {
F_27 ( L_14 ,
V_109 -> V_117 , V_109 -> V_114 ) ;
V_90 [ V_84 ] = F_46 ( V_107 , V_27 ,
V_29 ) ;
}
if ( ! V_90 [ V_84 ] && ! F_47 ( & V_109 -> V_90 ) ) {
F_27 ( L_15 ,
V_109 -> V_117 ) ;
V_90 [ V_84 ] = F_48 ( & V_109 -> V_90 ,
struct V_89 ,
V_121 ) ;
}
if ( ! V_90 [ V_84 ] ) {
F_27 ( L_16 ,
V_109 -> V_117 ) ;
V_90 [ V_84 ] = & V_111 -> V_74 -> V_122 ;
}
V_88 [ V_84 ] = V_112 ;
F_27 ( L_17 ,
V_109 -> V_117 ,
F_49 ( F_40 ( V_111 -> V_74 ) -> V_123 ) ,
V_111 -> V_74 -> V_38 . V_50 ,
V_90 [ V_84 ] -> V_124 , V_90 [ V_84 ] -> V_125 ,
V_90 [ V_84 ] -> V_51 & V_126 ? L_18 : L_19 ) ;
V_96 = false ;
V_99 |= ( 1 << V_84 ) ;
}
if ( ( V_99 & V_100 ) != V_100 ) {
V_101 ++ ;
goto V_105;
}
if ( V_97 != V_98 &&
V_97 < F_50 ( V_10 ) -> V_127 ) {
F_27 ( L_20 ) ;
F_27 ( L_21 , V_97 ,
V_98 ) ;
V_96 = true ;
}
if ( V_96 ) {
V_120:
F_27 ( L_22 ) ;
memcpy ( V_93 , V_95 , V_10 -> V_58 . V_102 ) ;
F_51 ( V_95 ) ;
return false ;
}
F_51 ( V_95 ) ;
return true ;
}
static void F_52 ( struct V_21 * V_10 ,
struct V_6 * V_7 )
{
F_53 ( & V_7 -> V_8 ) ;
F_37 ( & V_7 -> V_8 ) ;
F_54 ( & V_7 -> V_8 ) ;
F_55 ( & V_7 -> V_12 -> V_38 ) ;
F_24 ( & V_7 -> V_12 -> V_38 ) ;
}
static bool F_56 ( struct V_21 * V_10 ,
struct V_6 * V_7 )
{
struct V_39 * V_12 = NULL ;
struct V_73 * V_74 ;
struct V_79 * V_79 ;
unsigned int V_128 = 0 ;
if ( ! V_129 . V_130 )
return false ;
F_57 (dev, crtc) {
struct V_24 * V_13 =
F_58 ( V_74 -> V_131 -> V_132 -> V_12 ) ;
V_79 = F_40 ( V_74 ) ;
if ( ! V_79 -> V_133 || ! V_13 ) {
F_27 ( L_23 ,
F_49 ( V_79 -> V_123 ) ) ;
continue;
}
if ( V_13 -> V_38 . V_25 > V_128 ) {
F_27 ( L_24 ,
F_49 ( V_79 -> V_123 ) ) ;
V_12 = F_23 ( V_74 -> V_131 -> V_132 -> V_12 ) ;
V_128 = V_13 -> V_38 . V_25 ;
}
}
if ( ! V_12 ) {
F_27 ( L_25 ) ;
goto V_35;
}
F_57 (dev, crtc) {
unsigned int V_134 ;
V_79 = F_40 ( V_74 ) ;
if ( ! V_79 -> V_133 ) {
F_27 ( L_26 ,
F_49 ( V_79 -> V_123 ) ) ;
continue;
}
F_27 ( L_27 ,
F_49 ( V_79 -> V_123 ) ) ;
V_134 = V_79 -> V_135 -> V_38 . V_136 . V_137 ;
V_134 = V_134 * V_12 -> V_38 . V_138 / 8 ;
if ( V_12 -> V_38 . V_31 [ 0 ] < V_134 ) {
F_27 ( L_28 ,
F_49 ( V_79 -> V_123 ) ,
V_134 , V_12 -> V_38 . V_31 [ 0 ] ) ;
V_12 = NULL ;
break;
}
V_134 = V_79 -> V_135 -> V_38 . V_136 . V_139 ;
V_134 = F_59 ( V_10 , V_134 ,
V_12 -> V_38 . V_32 ,
V_12 -> V_38 . V_140 [ 0 ] ) ;
V_134 *= V_12 -> V_38 . V_31 [ 0 ] ;
F_27 ( L_29 ,
F_49 ( V_79 -> V_123 ) ,
V_79 -> V_135 -> V_38 . V_136 . V_137 ,
V_79 -> V_135 -> V_38 . V_136 . V_139 ,
V_12 -> V_38 . V_138 ,
V_134 ) ;
if ( V_134 > V_128 ) {
F_27 ( L_30 ,
F_49 ( V_79 -> V_123 ) ,
V_134 , V_128 ) ;
V_12 = NULL ;
break;
}
F_27 ( L_31 ,
F_49 ( V_79 -> V_123 ) ,
V_128 , V_134 ) ;
}
if ( ! V_12 ) {
F_27 ( L_32 ) ;
goto V_35;
}
V_7 -> V_141 = V_12 -> V_38 . V_138 ;
V_7 -> V_12 = V_12 ;
F_60 ( & V_7 -> V_12 -> V_38 ) ;
F_57 (dev, crtc) {
V_79 = F_40 ( V_74 ) ;
if ( ! V_79 -> V_133 )
continue;
F_61 ( ! V_74 -> V_131 -> V_12 ,
L_33 ,
V_74 -> V_38 . V_50 ) ;
}
F_27 ( L_34 ) ;
return true ;
V_35:
return false ;
}
static void F_62 ( struct V_142 * V_143 )
{
F_63 ( F_2 ( V_143 ,
struct V_41 ,
V_144 ) -> V_10 ,
V_145 ,
true ) ;
}
int F_64 ( struct V_21 * V_10 )
{
struct V_6 * V_7 ;
struct V_41 * V_42 = V_10 -> V_43 ;
int V_9 ;
if ( F_29 ( F_50 ( V_10 ) -> V_127 == 0 ) )
return - V_146 ;
V_7 = F_65 ( sizeof( struct V_6 ) , V_103 ) ;
if ( V_7 == NULL )
return - V_34 ;
F_66 ( V_10 , & V_7 -> V_8 , & V_147 ) ;
if ( ! F_56 ( V_10 , V_7 ) )
V_7 -> V_141 = 32 ;
V_9 = F_67 ( V_10 , & V_7 -> V_8 ,
F_50 ( V_10 ) -> V_127 , 4 ) ;
if ( V_9 ) {
F_51 ( V_7 ) ;
return V_9 ;
}
V_42 -> V_148 = V_7 ;
F_68 ( & V_42 -> V_144 , F_62 ) ;
F_69 ( & V_7 -> V_8 ) ;
return 0 ;
}
void F_70 ( void * V_149 , T_3 V_150 )
{
struct V_41 * V_42 = V_149 ;
struct V_6 * V_7 = V_42 -> V_148 ;
F_71 ( & V_7 -> V_8 , V_7 -> V_141 ) ;
}
void F_72 ( struct V_21 * V_10 )
{
struct V_41 * V_42 = V_10 -> V_43 ;
if ( ! V_42 -> V_148 )
return;
F_73 ( & V_42 -> V_144 ) ;
F_74 () ;
F_52 ( V_10 , V_42 -> V_148 ) ;
F_51 ( V_42 -> V_148 ) ;
V_42 -> V_148 = NULL ;
}
void F_63 ( struct V_21 * V_10 , int V_132 , bool V_151 )
{
struct V_41 * V_42 = V_10 -> V_43 ;
struct V_6 * V_7 = V_42 -> V_148 ;
struct V_1 * V_2 ;
if ( ! V_7 )
return;
V_2 = V_7 -> V_8 . V_148 ;
if ( V_151 ) {
if ( V_132 != V_145 )
F_73 ( & V_42 -> V_144 ) ;
F_75 () ;
} else {
F_29 ( V_132 != V_145 ) ;
if ( ! F_76 () ) {
F_77 ( & V_42 -> V_144 ) ;
return;
}
}
if ( V_132 == V_145 && V_7 -> V_12 -> V_13 -> V_71 )
F_35 ( V_2 -> V_64 , 0 , V_2 -> V_68 ) ;
F_78 ( & V_7 -> V_8 , V_132 ) ;
F_79 () ;
}
void F_80 ( struct V_21 * V_10 )
{
struct V_41 * V_42 = V_10 -> V_43 ;
if ( V_42 -> V_148 )
F_81 ( & V_42 -> V_148 -> V_8 ) ;
}
void F_82 ( struct V_21 * V_10 )
{
int V_9 ;
struct V_41 * V_42 = V_10 -> V_43 ;
struct V_6 * V_7 = V_42 -> V_148 ;
struct V_3 * V_4 ;
if ( ! V_7 )
return;
V_4 = & V_7 -> V_8 ;
V_9 = F_83 ( V_4 ) ;
if ( V_9 ) {
F_84 ( L_35 ) ;
} else {
F_4 ( & V_4 -> V_10 -> V_11 ) ;
F_5 ( V_7 -> V_12 -> V_13 , V_14 ) ;
F_6 ( & V_4 -> V_10 -> V_11 ) ;
}
}
