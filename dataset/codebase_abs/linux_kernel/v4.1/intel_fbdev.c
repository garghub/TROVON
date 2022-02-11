static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 =
F_2 ( V_4 , struct V_6 , V_8 ) ;
int V_9 ;
V_9 = F_3 ( V_2 ) ;
if ( V_9 == 0 ) {
F_4 ( & V_4 -> V_10 -> V_11 ) ;
V_9 = F_5 ( V_7 -> V_12 -> V_13 ,
true ) ;
F_6 ( & V_4 -> V_10 -> V_11 ) ;
}
return V_9 ;
}
static int F_7 ( int V_14 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 =
F_2 ( V_4 , struct V_6 , V_8 ) ;
int V_9 ;
V_9 = F_8 ( V_14 , V_2 ) ;
if ( V_9 == 0 ) {
F_4 ( & V_4 -> V_10 -> V_11 ) ;
F_9 ( V_7 -> V_12 -> V_13 , NULL , V_15 ) ;
F_6 ( & V_4 -> V_10 -> V_11 ) ;
}
return V_9 ;
}
static int F_10 ( struct V_3 * V_8 ,
struct V_16 * V_17 )
{
struct V_6 * V_7 =
F_2 ( V_8 , struct V_6 , V_8 ) ;
struct V_18 * V_12 ;
struct V_19 * V_10 = V_8 -> V_10 ;
struct V_20 V_21 = {} ;
struct V_22 * V_13 ;
int V_23 , V_9 ;
if ( V_17 -> V_24 == 24 )
V_17 -> V_24 = 32 ;
V_21 . V_25 = V_17 -> V_26 ;
V_21 . V_27 = V_17 -> V_28 ;
V_21 . V_29 [ 0 ] = F_11 ( V_21 . V_25 *
F_12 ( V_17 -> V_24 , 8 ) , 64 ) ;
V_21 . V_30 = F_13 ( V_17 -> V_24 ,
V_17 -> V_31 ) ;
V_23 = V_21 . V_29 [ 0 ] * V_21 . V_27 ;
V_23 = F_14 ( V_23 ) ;
V_13 = F_15 ( V_10 , V_23 ) ;
if ( V_13 == NULL )
V_13 = F_16 ( V_10 , V_23 ) ;
if ( ! V_13 ) {
F_17 ( L_1 ) ;
V_9 = - V_32 ;
goto V_33;
}
V_12 = F_18 ( V_10 , & V_21 , V_13 ) ;
if ( F_19 ( V_12 ) ) {
V_9 = F_20 ( V_12 ) ;
goto V_34;
}
V_9 = F_21 ( NULL , V_12 , NULL , NULL ) ;
if ( V_9 ) {
F_17 ( L_2 , V_9 ) ;
goto V_35;
}
V_7 -> V_12 = F_22 ( V_12 ) ;
return 0 ;
V_35:
F_23 ( V_12 ) ;
V_34:
F_24 ( & V_13 -> V_36 ) ;
V_33:
return V_9 ;
}
static int F_25 ( struct V_3 * V_8 ,
struct V_16 * V_17 )
{
struct V_6 * V_7 =
F_2 ( V_8 , struct V_6 , V_8 ) ;
struct V_37 * V_38 = V_7 -> V_12 ;
struct V_19 * V_10 = V_8 -> V_10 ;
struct V_39 * V_40 = V_10 -> V_41 ;
struct V_1 * V_2 ;
struct V_18 * V_12 ;
struct V_22 * V_13 ;
int V_23 , V_9 ;
bool V_42 = false ;
F_4 ( & V_10 -> V_11 ) ;
if ( V_38 &&
( V_17 -> V_43 > V_38 -> V_36 . V_25 ||
V_17 -> V_44 > V_38 -> V_36 . V_27 ) ) {
F_26 ( L_3
L_4 ,
V_38 -> V_36 . V_25 , V_38 -> V_36 . V_27 ,
V_17 -> V_43 , V_17 -> V_44 ) ;
F_27 ( & V_38 -> V_36 ) ;
V_38 = V_7 -> V_12 = NULL ;
}
if ( ! V_38 || F_28 ( ! V_38 -> V_13 ) ) {
F_26 ( L_5 ) ;
V_9 = F_10 ( V_8 , V_17 ) ;
if ( V_9 )
goto V_45;
V_38 = V_7 -> V_12 ;
} else {
F_26 ( L_6 ) ;
V_42 = true ;
V_17 -> V_43 = V_38 -> V_36 . V_25 ;
V_17 -> V_44 = V_38 -> V_36 . V_27 ;
}
V_13 = V_38 -> V_13 ;
V_23 = V_13 -> V_36 . V_23 ;
V_2 = F_29 ( 0 , & V_10 -> V_46 -> V_10 ) ;
if ( ! V_2 ) {
V_9 = - V_32 ;
goto V_47;
}
V_2 -> V_5 = V_8 ;
V_12 = & V_7 -> V_12 -> V_36 ;
V_7 -> V_8 . V_12 = V_12 ;
V_7 -> V_8 . V_48 = V_2 ;
strcpy ( V_2 -> V_49 . V_50 , L_7 ) ;
V_2 -> V_51 = V_52 | V_53 ;
V_2 -> V_54 = & V_55 ;
V_9 = F_30 ( & V_2 -> V_56 , 256 , 0 ) ;
if ( V_9 ) {
V_9 = - V_32 ;
goto V_47;
}
V_2 -> V_57 = F_31 ( 1 ) ;
if ( ! V_2 -> V_57 ) {
V_9 = - V_32 ;
goto V_47;
}
V_2 -> V_57 -> V_58 [ 0 ] . V_36 = V_10 -> V_59 . V_60 ;
V_2 -> V_57 -> V_58 [ 0 ] . V_23 = V_40 -> V_61 . V_62 ;
V_2 -> V_49 . V_63 = V_10 -> V_59 . V_60 + F_32 ( V_13 ) ;
V_2 -> V_49 . V_64 = V_23 ;
V_2 -> V_65 =
F_33 ( V_40 -> V_61 . V_66 + F_32 ( V_13 ) ,
V_23 ) ;
if ( ! V_2 -> V_65 ) {
V_9 = - V_67 ;
goto V_47;
}
V_2 -> V_68 = V_23 ;
V_2 -> V_69 = true ;
F_34 ( V_2 , V_12 -> V_29 [ 0 ] , V_12 -> V_70 ) ;
F_35 ( V_2 , & V_7 -> V_8 , V_17 -> V_43 , V_17 -> V_44 ) ;
if ( V_7 -> V_12 -> V_13 -> V_71 && ! V_42 )
F_36 ( V_2 -> V_65 , 0 , V_2 -> V_68 ) ;
F_26 ( L_8 ,
V_12 -> V_25 , V_12 -> V_27 ,
F_32 ( V_13 ) , V_13 ) ;
F_6 ( & V_10 -> V_11 ) ;
F_37 ( V_10 -> V_46 , V_2 ) ;
return 0 ;
V_47:
F_38 ( V_13 ) ;
F_24 ( & V_13 -> V_36 ) ;
V_45:
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
bool * V_92 , int V_25 , int V_27 )
{
struct V_19 * V_10 = V_4 -> V_10 ;
int V_83 , V_93 ;
bool * V_94 ;
bool V_95 = true ;
int V_96 = 0 ;
int V_97 = 0 ;
T_2 V_98 = 0 , V_99 ;
int V_100 = 0 ;
V_94 = F_44 ( V_10 -> V_59 . V_101 , sizeof( bool ) ,
V_102 ) ;
if ( ! V_94 )
return false ;
memcpy ( V_94 , V_92 , V_10 -> V_59 . V_101 ) ;
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
F_26 ( L_9 ,
V_108 -> V_116 ) ;
V_98 |= ( 1 << V_83 ) ;
continue;
}
if ( V_108 -> V_117 == V_118 ) {
F_26 ( L_10 ,
V_108 -> V_116 ) ;
V_92 [ V_83 ] = false ;
continue;
}
V_110 = V_108 -> V_110 ;
if ( ! V_110 || F_28 ( ! V_110 -> V_73 ) ) {
if ( V_108 -> V_117 > V_118 )
goto V_119;
F_26 ( L_11 ,
V_108 -> V_116 ) ;
V_92 [ V_83 ] = false ;
V_98 |= ( 1 << V_83 ) ;
continue;
}
V_96 ++ ;
V_111 = F_42 ( V_4 , V_110 -> V_73 ) ;
for ( V_93 = 0 ; V_93 < V_4 -> V_103 ; V_93 ++ ) {
if ( V_87 [ V_93 ] == V_111 ) {
F_26 ( L_12 ) ;
goto V_119;
}
}
F_26 ( L_13 ,
V_108 -> V_116 ) ;
V_89 [ V_83 ] = F_45 ( V_106 , V_25 , V_27 ) ;
if ( ! V_89 [ V_83 ] ) {
F_26 ( L_14 ,
V_108 -> V_116 , V_108 -> V_113 ) ;
V_89 [ V_83 ] = F_46 ( V_106 , V_25 ,
V_27 ) ;
}
if ( ! V_89 [ V_83 ] && ! F_47 ( & V_108 -> V_89 ) ) {
F_26 ( L_15 ,
V_108 -> V_116 ) ;
V_89 [ V_83 ] = F_48 ( & V_108 -> V_89 ,
struct V_88 ,
V_120 ) ;
}
if ( ! V_89 [ V_83 ] ) {
F_26 ( L_16 ,
V_108 -> V_116 ) ;
F_49 ( & V_110 -> V_73 -> V_121 ,
F_40 ( V_110 -> V_73 ) -> V_122 ) ;
V_89 [ V_83 ] = & V_110 -> V_73 -> V_121 ;
}
V_87 [ V_83 ] = V_111 ;
F_26 ( L_17 ,
V_108 -> V_116 ,
F_50 ( F_40 ( V_110 -> V_73 ) -> V_123 ) ,
V_110 -> V_73 -> V_36 . V_50 ,
V_89 [ V_83 ] -> V_124 , V_89 [ V_83 ] -> V_125 ,
V_89 [ V_83 ] -> V_51 & V_126 ? L_18 : L_19 ) ;
V_95 = false ;
V_98 |= ( 1 << V_83 ) ;
}
if ( ( V_98 & V_99 ) != V_99 ) {
V_100 ++ ;
goto V_104;
}
if ( V_96 != V_97 &&
V_96 < F_51 ( V_10 ) -> V_127 ) {
F_26 ( L_20 ) ;
F_26 ( L_21 , V_96 ,
V_97 ) ;
V_95 = true ;
}
if ( V_95 ) {
V_119:
F_26 ( L_22 ) ;
memcpy ( V_92 , V_94 , V_10 -> V_59 . V_101 ) ;
F_52 ( V_94 ) ;
return false ;
}
F_52 ( V_94 ) ;
return true ;
}
static void F_53 ( struct V_19 * V_10 ,
struct V_6 * V_7 )
{
if ( V_7 -> V_8 . V_48 ) {
struct V_1 * V_2 = V_7 -> V_8 . V_48 ;
F_54 ( V_2 ) ;
F_55 ( V_2 -> V_65 ) ;
if ( V_2 -> V_56 . V_128 )
F_56 ( & V_2 -> V_56 ) ;
F_57 ( V_2 ) ;
}
F_58 ( & V_7 -> V_8 ) ;
F_59 ( & V_7 -> V_12 -> V_36 ) ;
F_23 ( & V_7 -> V_12 -> V_36 ) ;
}
static bool F_60 ( struct V_19 * V_10 ,
struct V_6 * V_7 )
{
struct V_37 * V_12 = NULL ;
struct V_72 * V_73 ;
struct V_78 * V_78 ;
struct V_129 * V_130 = NULL ;
unsigned int V_131 = 0 ;
if ( ! V_132 . V_133 )
return false ;
F_61 (dev, crtc) {
V_78 = F_40 ( V_73 ) ;
if ( ! V_78 -> V_134 || ! V_73 -> V_135 -> V_12 ) {
F_26 ( L_23 ,
F_50 ( V_78 -> V_123 ) ) ;
continue;
}
if ( V_78 -> V_130 . V_23 > V_131 ) {
F_26 ( L_24 ,
F_50 ( V_78 -> V_123 ) ) ;
V_130 = & V_78 -> V_130 ;
V_12 = F_22 ( V_73 -> V_135 -> V_12 ) ;
V_131 = V_130 -> V_23 ;
}
}
if ( ! V_12 ) {
F_26 ( L_25 ) ;
goto V_33;
}
F_61 (dev, crtc) {
unsigned int V_136 ;
V_78 = F_40 ( V_73 ) ;
if ( ! V_78 -> V_134 ) {
F_26 ( L_26 ,
F_50 ( V_78 -> V_123 ) ) ;
continue;
}
F_26 ( L_27 ,
F_50 ( V_78 -> V_123 ) ) ;
V_136 = V_78 -> V_122 -> V_36 . V_137 . V_138 ;
V_136 = V_136 * V_12 -> V_36 . V_139 / 8 ;
if ( V_12 -> V_36 . V_29 [ 0 ] < V_136 ) {
F_26 ( L_28 ,
F_50 ( V_78 -> V_123 ) ,
V_136 , V_12 -> V_36 . V_29 [ 0 ] ) ;
V_130 = NULL ;
V_12 = NULL ;
break;
}
V_136 = V_78 -> V_122 -> V_36 . V_137 . V_140 ;
V_136 = F_62 ( V_10 , V_136 ,
V_12 -> V_36 . V_30 ,
V_12 -> V_36 . V_141 [ 0 ] ) ;
V_136 *= V_12 -> V_36 . V_29 [ 0 ] ;
F_26 ( L_29 ,
F_50 ( V_78 -> V_123 ) ,
V_78 -> V_122 -> V_36 . V_137 . V_138 ,
V_78 -> V_122 -> V_36 . V_137 . V_140 ,
V_12 -> V_36 . V_139 ,
V_136 ) ;
if ( V_136 > V_131 ) {
F_26 ( L_30 ,
F_50 ( V_78 -> V_123 ) ,
V_136 , V_131 ) ;
V_130 = NULL ;
V_12 = NULL ;
break;
}
F_26 ( L_31 ,
F_50 ( V_78 -> V_123 ) ,
V_131 , V_136 ) ;
}
if ( ! V_12 ) {
F_26 ( L_32 ) ;
goto V_33;
}
V_7 -> V_142 = V_12 -> V_36 . V_139 ;
V_7 -> V_12 = V_12 ;
F_63 ( & V_7 -> V_12 -> V_36 ) ;
F_61 (dev, crtc) {
V_78 = F_40 ( V_73 ) ;
if ( ! V_78 -> V_134 )
continue;
F_64 ( ! V_73 -> V_135 -> V_12 ,
L_33 ,
V_73 -> V_36 . V_50 ) ;
}
F_26 ( L_34 ) ;
return true ;
V_33:
return false ;
}
static void F_65 ( struct V_143 * V_144 )
{
F_66 ( F_2 ( V_144 ,
struct V_39 ,
V_145 ) -> V_10 ,
V_146 ,
true ) ;
}
int F_67 ( struct V_19 * V_10 )
{
struct V_6 * V_7 ;
struct V_39 * V_40 = V_10 -> V_41 ;
int V_9 ;
if ( F_28 ( F_51 ( V_10 ) -> V_127 == 0 ) )
return - V_147 ;
V_7 = F_68 ( sizeof( struct V_6 ) , V_102 ) ;
if ( V_7 == NULL )
return - V_32 ;
F_69 ( V_10 , & V_7 -> V_8 , & V_148 ) ;
if ( ! F_60 ( V_10 , V_7 ) )
V_7 -> V_142 = 32 ;
V_9 = F_70 ( V_10 , & V_7 -> V_8 ,
F_51 ( V_10 ) -> V_127 , 4 ) ;
if ( V_9 ) {
F_52 ( V_7 ) ;
return V_9 ;
}
V_40 -> V_48 = V_7 ;
F_71 ( & V_40 -> V_145 , F_65 ) ;
F_72 ( & V_7 -> V_8 ) ;
return 0 ;
}
void F_73 ( void * V_149 , T_3 V_150 )
{
struct V_39 * V_40 = V_149 ;
struct V_6 * V_7 = V_40 -> V_48 ;
F_74 ( & V_7 -> V_8 , V_7 -> V_142 ) ;
}
void F_75 ( struct V_19 * V_10 )
{
struct V_39 * V_40 = V_10 -> V_41 ;
if ( ! V_40 -> V_48 )
return;
F_76 ( & V_40 -> V_145 ) ;
F_77 () ;
F_53 ( V_10 , V_40 -> V_48 ) ;
F_52 ( V_40 -> V_48 ) ;
V_40 -> V_48 = NULL ;
}
void F_66 ( struct V_19 * V_10 , int V_151 , bool V_152 )
{
struct V_39 * V_40 = V_10 -> V_41 ;
struct V_6 * V_7 = V_40 -> V_48 ;
struct V_1 * V_2 ;
if ( ! V_7 )
return;
V_2 = V_7 -> V_8 . V_48 ;
if ( V_152 ) {
if ( V_151 != V_146 )
F_76 ( & V_40 -> V_145 ) ;
F_78 () ;
} else {
F_28 ( V_151 != V_146 ) ;
if ( ! F_79 () ) {
F_80 ( & V_40 -> V_145 ) ;
return;
}
}
if ( V_151 == V_146 && V_7 -> V_12 -> V_13 -> V_71 )
F_36 ( V_2 -> V_65 , 0 , V_2 -> V_68 ) ;
F_81 ( V_2 , V_151 ) ;
F_82 () ;
}
void F_83 ( struct V_19 * V_10 )
{
struct V_39 * V_40 = V_10 -> V_41 ;
if ( V_40 -> V_48 )
F_84 ( & V_40 -> V_48 -> V_8 ) ;
}
void F_85 ( struct V_19 * V_10 )
{
int V_9 ;
struct V_39 * V_40 = V_10 -> V_41 ;
if ( ! V_40 -> V_48 )
return;
V_9 = F_86 ( & V_40 -> V_48 -> V_8 ) ;
if ( V_9 )
F_87 ( L_35 ) ;
}
