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
static int F_7 ( struct V_3 * V_8 ,
struct V_14 * V_15 )
{
struct V_6 * V_7 =
F_2 ( V_8 , struct V_6 , V_8 ) ;
struct V_16 * V_12 ;
struct V_17 * V_10 = V_8 -> V_10 ;
struct V_18 V_19 = {} ;
struct V_20 * V_13 ;
int V_21 , V_9 ;
if ( V_15 -> V_22 == 24 )
V_15 -> V_22 = 32 ;
V_19 . V_23 = V_15 -> V_24 ;
V_19 . V_25 = V_15 -> V_26 ;
V_19 . V_27 [ 0 ] = F_8 ( V_19 . V_23 *
F_9 ( V_15 -> V_22 , 8 ) , 64 ) ;
V_19 . V_28 = F_10 ( V_15 -> V_22 ,
V_15 -> V_29 ) ;
V_21 = V_19 . V_27 [ 0 ] * V_19 . V_25 ;
V_21 = F_11 ( V_21 ) ;
V_13 = F_12 ( V_10 , V_21 ) ;
if ( V_13 == NULL )
V_13 = F_13 ( V_10 , V_21 ) ;
if ( ! V_13 ) {
F_14 ( L_1 ) ;
V_9 = - V_30 ;
goto V_31;
}
V_12 = F_15 ( V_10 , & V_19 , V_13 ) ;
if ( F_16 ( V_12 ) ) {
V_9 = F_17 ( V_12 ) ;
goto V_32;
}
V_9 = F_18 ( NULL , V_12 , NULL ) ;
if ( V_9 ) {
F_14 ( L_2 , V_9 ) ;
goto V_33;
}
V_7 -> V_12 = F_19 ( V_12 ) ;
return 0 ;
V_33:
F_20 ( V_12 ) ;
V_32:
F_21 ( & V_13 -> V_34 ) ;
V_31:
return V_9 ;
}
static int F_22 ( struct V_3 * V_8 ,
struct V_14 * V_15 )
{
struct V_6 * V_7 =
F_2 ( V_8 , struct V_6 , V_8 ) ;
struct V_35 * V_36 = V_7 -> V_12 ;
struct V_17 * V_10 = V_8 -> V_10 ;
struct V_37 * V_38 = V_10 -> V_39 ;
struct V_1 * V_2 ;
struct V_16 * V_12 ;
struct V_20 * V_13 ;
int V_21 , V_9 ;
bool V_40 = false ;
F_4 ( & V_10 -> V_11 ) ;
if ( V_36 &&
( V_15 -> V_41 > V_36 -> V_34 . V_23 ||
V_15 -> V_42 > V_36 -> V_34 . V_25 ) ) {
F_23 ( L_3
L_4 ,
V_36 -> V_34 . V_23 , V_36 -> V_34 . V_25 ,
V_15 -> V_41 , V_15 -> V_42 ) ;
F_24 ( & V_36 -> V_34 ) ;
V_36 = V_7 -> V_12 = NULL ;
}
if ( ! V_36 || F_25 ( ! V_36 -> V_13 ) ) {
F_23 ( L_5 ) ;
V_9 = F_7 ( V_8 , V_15 ) ;
if ( V_9 )
goto V_43;
V_36 = V_7 -> V_12 ;
} else {
F_23 ( L_6 ) ;
V_40 = true ;
V_15 -> V_41 = V_36 -> V_34 . V_23 ;
V_15 -> V_42 = V_36 -> V_34 . V_25 ;
}
V_13 = V_36 -> V_13 ;
V_21 = V_13 -> V_34 . V_21 ;
V_2 = F_26 ( 0 , & V_10 -> V_44 -> V_10 ) ;
if ( ! V_2 ) {
V_9 = - V_30 ;
goto V_45;
}
V_2 -> V_5 = V_8 ;
V_12 = & V_7 -> V_12 -> V_34 ;
V_7 -> V_8 . V_12 = V_12 ;
V_7 -> V_8 . V_46 = V_2 ;
strcpy ( V_2 -> V_47 . V_48 , L_7 ) ;
V_2 -> V_49 = V_50 | V_51 ;
V_2 -> V_52 = & V_53 ;
V_9 = F_27 ( & V_2 -> V_54 , 256 , 0 ) ;
if ( V_9 ) {
V_9 = - V_30 ;
goto V_45;
}
V_2 -> V_55 = F_28 ( 1 ) ;
if ( ! V_2 -> V_55 ) {
V_9 = - V_30 ;
goto V_45;
}
V_2 -> V_55 -> V_56 [ 0 ] . V_34 = V_10 -> V_57 . V_58 ;
V_2 -> V_55 -> V_56 [ 0 ] . V_21 = V_38 -> V_59 . V_60 ;
V_2 -> V_47 . V_61 = V_10 -> V_57 . V_58 + F_29 ( V_13 ) ;
V_2 -> V_47 . V_62 = V_21 ;
V_2 -> V_63 =
F_30 ( V_38 -> V_59 . V_64 + F_29 ( V_13 ) ,
V_21 ) ;
if ( ! V_2 -> V_63 ) {
V_9 = - V_65 ;
goto V_45;
}
V_2 -> V_66 = V_21 ;
V_2 -> V_67 = true ;
F_31 ( V_2 , V_12 -> V_27 [ 0 ] , V_12 -> V_68 ) ;
F_32 ( V_2 , & V_7 -> V_8 , V_15 -> V_41 , V_15 -> V_42 ) ;
if ( V_7 -> V_12 -> V_13 -> V_69 && ! V_40 )
F_33 ( V_2 -> V_63 , 0 , V_2 -> V_66 ) ;
F_23 ( L_8 ,
V_12 -> V_23 , V_12 -> V_25 ,
F_29 ( V_13 ) , V_13 ) ;
F_6 ( & V_10 -> V_11 ) ;
F_34 ( V_10 -> V_44 , V_2 ) ;
return 0 ;
V_45:
F_35 ( V_13 ) ;
F_21 ( & V_13 -> V_34 ) ;
V_43:
F_6 ( & V_10 -> V_11 ) ;
return V_9 ;
}
static void F_36 ( struct V_70 * V_71 , T_1 V_72 , T_1 V_73 ,
T_1 V_74 , int V_75 )
{
struct V_76 * V_76 = F_37 ( V_71 ) ;
V_76 -> V_77 [ V_75 ] = V_72 >> 8 ;
V_76 -> V_78 [ V_75 ] = V_73 >> 8 ;
V_76 -> V_79 [ V_75 ] = V_74 >> 8 ;
}
static void F_38 ( struct V_70 * V_71 , T_1 * V_72 , T_1 * V_73 ,
T_1 * V_74 , int V_75 )
{
struct V_76 * V_76 = F_37 ( V_71 ) ;
* V_72 = V_76 -> V_77 [ V_75 ] << 8 ;
* V_73 = V_76 -> V_78 [ V_75 ] << 8 ;
* V_74 = V_76 -> V_79 [ V_75 ] << 8 ;
}
static struct V_80 *
F_39 ( struct V_3 * V_4 , struct V_70 * V_71 )
{
int V_81 ;
for ( V_81 = 0 ; V_81 < V_4 -> V_82 ; V_81 ++ )
if ( V_4 -> V_83 [ V_81 ] . V_84 . V_71 == V_71 )
return & V_4 -> V_83 [ V_81 ] ;
return NULL ;
}
static bool F_40 ( struct V_3 * V_4 ,
struct V_80 * * V_85 ,
struct V_86 * * V_87 ,
struct V_88 * V_89 ,
bool * V_90 , int V_23 , int V_25 )
{
struct V_17 * V_10 = V_4 -> V_10 ;
int V_81 , V_91 ;
bool * V_92 ;
bool V_93 = true ;
int V_94 = 0 ;
int V_95 = 0 ;
T_2 V_96 = 0 , V_97 ;
int V_98 = 0 ;
V_92 = F_41 ( V_10 -> V_57 . V_99 , sizeof( bool ) ,
V_100 ) ;
if ( ! V_92 )
return false ;
memcpy ( V_92 , V_90 , V_10 -> V_57 . V_99 ) ;
V_97 = ( 1 << V_4 -> V_101 ) - 1 ;
V_102:
for ( V_81 = 0 ; V_81 < V_4 -> V_101 ; V_81 ++ ) {
struct V_103 * V_104 ;
struct V_105 * V_106 ;
struct V_107 * V_108 ;
struct V_80 * V_109 ;
V_104 = V_4 -> V_110 [ V_81 ] ;
V_106 = V_104 -> V_106 ;
if ( V_96 & ( 1 << V_81 ) )
continue;
if ( V_98 == 0 && ! V_106 -> V_111 )
continue;
if ( V_106 -> V_112 == V_113 )
V_95 ++ ;
if ( ! V_90 [ V_81 ] ) {
F_23 ( L_9 ,
V_106 -> V_114 ) ;
V_96 |= ( 1 << V_81 ) ;
continue;
}
if ( V_106 -> V_115 == V_116 ) {
F_23 ( L_10 ,
V_106 -> V_114 ) ;
V_90 [ V_81 ] = false ;
continue;
}
V_108 = V_106 -> V_108 ;
if ( ! V_108 || F_25 ( ! V_108 -> V_71 ) ) {
if ( V_106 -> V_115 > V_116 )
goto V_117;
F_23 ( L_11 ,
V_106 -> V_114 ) ;
V_90 [ V_81 ] = false ;
V_96 |= ( 1 << V_81 ) ;
continue;
}
V_94 ++ ;
V_109 = F_39 ( V_4 , V_108 -> V_71 ) ;
for ( V_91 = 0 ; V_91 < V_4 -> V_101 ; V_91 ++ ) {
if ( V_85 [ V_91 ] == V_109 ) {
F_23 ( L_12 ) ;
goto V_117;
}
}
F_23 ( L_13 ,
V_106 -> V_114 ) ;
V_87 [ V_81 ] = F_42 ( V_104 , V_23 , V_25 ) ;
if ( ! V_87 [ V_81 ] ) {
F_23 ( L_14 ,
V_106 -> V_114 , V_106 -> V_111 ) ;
V_87 [ V_81 ] = F_43 ( V_104 , V_23 ,
V_25 ) ;
}
if ( ! V_87 [ V_81 ] && ! F_44 ( & V_106 -> V_87 ) ) {
F_23 ( L_15 ,
V_106 -> V_114 ) ;
V_87 [ V_81 ] = F_45 ( & V_106 -> V_87 ,
struct V_86 ,
V_118 ) ;
}
if ( ! V_87 [ V_81 ] ) {
F_23 ( L_16 ,
V_106 -> V_114 ) ;
F_46 ( & V_108 -> V_71 -> V_119 ,
F_37 ( V_108 -> V_71 ) -> V_120 ) ;
V_87 [ V_81 ] = & V_108 -> V_71 -> V_119 ;
}
V_85 [ V_81 ] = V_109 ;
F_23 ( L_17 ,
V_106 -> V_114 ,
F_47 ( F_37 ( V_108 -> V_71 ) -> V_121 ) ,
V_108 -> V_71 -> V_34 . V_48 ,
V_87 [ V_81 ] -> V_122 , V_87 [ V_81 ] -> V_123 ,
V_87 [ V_81 ] -> V_49 & V_124 ? L_18 : L_19 ) ;
V_93 = false ;
V_96 |= ( 1 << V_81 ) ;
}
if ( ( V_96 & V_97 ) != V_97 ) {
V_98 ++ ;
goto V_102;
}
if ( V_94 != V_95 &&
V_94 < F_48 ( V_10 ) -> V_125 ) {
F_23 ( L_20 ) ;
F_23 ( L_21 , V_94 ,
V_95 ) ;
V_93 = true ;
}
if ( V_93 ) {
V_117:
F_23 ( L_22 ) ;
memcpy ( V_90 , V_92 , V_10 -> V_57 . V_99 ) ;
F_49 ( V_92 ) ;
return false ;
}
F_49 ( V_92 ) ;
return true ;
}
static void F_50 ( struct V_17 * V_10 ,
struct V_6 * V_7 )
{
if ( V_7 -> V_8 . V_46 ) {
struct V_1 * V_2 = V_7 -> V_8 . V_46 ;
F_51 ( V_2 ) ;
F_52 ( V_2 -> V_63 ) ;
if ( V_2 -> V_54 . V_126 )
F_53 ( & V_2 -> V_54 ) ;
F_54 ( V_2 ) ;
}
F_55 ( & V_7 -> V_8 ) ;
F_56 ( & V_7 -> V_12 -> V_34 ) ;
F_20 ( & V_7 -> V_12 -> V_34 ) ;
}
static bool F_57 ( struct V_17 * V_10 ,
struct V_6 * V_7 )
{
struct V_35 * V_12 = NULL ;
struct V_70 * V_71 ;
struct V_76 * V_76 ;
struct V_127 * V_128 = NULL ;
unsigned int V_129 = 0 ;
if ( ! V_130 . V_131 )
return false ;
F_58 (dev, crtc) {
V_76 = F_37 ( V_71 ) ;
if ( ! V_76 -> V_132 || ! V_71 -> V_133 -> V_12 ) {
F_23 ( L_23 ,
F_47 ( V_76 -> V_121 ) ) ;
continue;
}
if ( V_76 -> V_128 . V_21 > V_129 ) {
F_23 ( L_24 ,
F_47 ( V_76 -> V_121 ) ) ;
V_128 = & V_76 -> V_128 ;
V_12 = F_19 ( V_71 -> V_133 -> V_12 ) ;
V_129 = V_128 -> V_21 ;
}
}
if ( ! V_12 ) {
F_23 ( L_25 ) ;
goto V_31;
}
F_58 (dev, crtc) {
unsigned int V_134 ;
V_76 = F_37 ( V_71 ) ;
if ( ! V_76 -> V_132 ) {
F_23 ( L_26 ,
F_47 ( V_76 -> V_121 ) ) ;
continue;
}
F_23 ( L_27 ,
F_47 ( V_76 -> V_121 ) ) ;
V_134 = V_76 -> V_120 -> V_34 . V_135 . V_136 ;
V_134 = V_134 * V_12 -> V_34 . V_137 / 8 ;
if ( V_12 -> V_34 . V_27 [ 0 ] < V_134 ) {
F_23 ( L_28 ,
F_47 ( V_76 -> V_121 ) ,
V_134 , V_12 -> V_34 . V_27 [ 0 ] ) ;
V_128 = NULL ;
V_12 = NULL ;
break;
}
V_134 = V_76 -> V_120 -> V_34 . V_135 . V_138 ;
V_134 = F_59 ( V_10 , V_134 ,
V_128 -> V_139 ) ;
V_134 *= V_12 -> V_34 . V_27 [ 0 ] ;
F_23 ( L_29 ,
F_47 ( V_76 -> V_121 ) ,
V_76 -> V_120 -> V_34 . V_135 . V_136 ,
V_76 -> V_120 -> V_34 . V_135 . V_138 ,
V_12 -> V_34 . V_137 ,
V_134 ) ;
if ( V_134 > V_129 ) {
F_23 ( L_30 ,
F_47 ( V_76 -> V_121 ) ,
V_134 , V_129 ) ;
V_128 = NULL ;
V_12 = NULL ;
break;
}
F_23 ( L_31 ,
F_47 ( V_76 -> V_121 ) ,
V_129 , V_134 ) ;
}
if ( ! V_12 ) {
F_23 ( L_32 ) ;
goto V_31;
}
V_7 -> V_140 = V_12 -> V_34 . V_137 ;
V_7 -> V_12 = V_12 ;
F_60 ( & V_7 -> V_12 -> V_34 ) ;
F_58 (dev, crtc) {
V_76 = F_37 ( V_71 ) ;
if ( ! V_76 -> V_132 )
continue;
F_61 ( ! V_71 -> V_133 -> V_12 ,
L_33 ,
V_71 -> V_34 . V_48 ) ;
}
F_23 ( L_34 ) ;
return true ;
V_31:
return false ;
}
static void F_62 ( struct V_141 * V_142 )
{
F_63 ( F_2 ( V_142 ,
struct V_37 ,
V_143 ) -> V_10 ,
V_144 ,
true ) ;
}
int F_64 ( struct V_17 * V_10 )
{
struct V_6 * V_7 ;
struct V_37 * V_38 = V_10 -> V_39 ;
int V_9 ;
if ( F_25 ( F_48 ( V_10 ) -> V_125 == 0 ) )
return - V_145 ;
V_7 = F_65 ( sizeof( struct V_6 ) , V_100 ) ;
if ( V_7 == NULL )
return - V_30 ;
F_66 ( V_10 , & V_7 -> V_8 , & V_146 ) ;
if ( ! F_57 ( V_10 , V_7 ) )
V_7 -> V_140 = 32 ;
V_9 = F_67 ( V_10 , & V_7 -> V_8 ,
F_48 ( V_10 ) -> V_125 , 4 ) ;
if ( V_9 ) {
F_49 ( V_7 ) ;
return V_9 ;
}
V_38 -> V_46 = V_7 ;
F_68 ( & V_38 -> V_143 , F_62 ) ;
F_69 ( & V_7 -> V_8 ) ;
return 0 ;
}
void F_70 ( void * V_147 , T_3 V_148 )
{
struct V_37 * V_38 = V_147 ;
struct V_6 * V_7 = V_38 -> V_46 ;
F_71 ( & V_7 -> V_8 , V_7 -> V_140 ) ;
}
void F_72 ( struct V_17 * V_10 )
{
struct V_37 * V_38 = V_10 -> V_39 ;
if ( ! V_38 -> V_46 )
return;
F_73 ( & V_38 -> V_143 ) ;
F_74 () ;
F_50 ( V_10 , V_38 -> V_46 ) ;
F_49 ( V_38 -> V_46 ) ;
V_38 -> V_46 = NULL ;
}
void F_63 ( struct V_17 * V_10 , int V_149 , bool V_150 )
{
struct V_37 * V_38 = V_10 -> V_39 ;
struct V_6 * V_7 = V_38 -> V_46 ;
struct V_1 * V_2 ;
if ( ! V_7 )
return;
V_2 = V_7 -> V_8 . V_46 ;
if ( V_150 ) {
if ( V_149 != V_144 )
F_73 ( & V_38 -> V_143 ) ;
F_75 () ;
} else {
F_25 ( V_149 != V_144 ) ;
if ( ! F_76 () ) {
F_77 ( & V_38 -> V_143 ) ;
return;
}
}
if ( V_149 == V_144 && V_7 -> V_12 -> V_13 -> V_69 )
F_33 ( V_2 -> V_63 , 0 , V_2 -> V_66 ) ;
F_78 ( V_2 , V_149 ) ;
F_79 () ;
}
void F_80 ( struct V_17 * V_10 )
{
struct V_37 * V_38 = V_10 -> V_39 ;
if ( V_38 -> V_46 )
F_81 ( & V_38 -> V_46 -> V_8 ) ;
}
void F_82 ( struct V_17 * V_10 )
{
int V_9 ;
struct V_37 * V_38 = V_10 -> V_39 ;
if ( ! V_38 -> V_46 )
return;
V_9 = F_83 ( & V_38 -> V_46 -> V_8 ) ;
if ( V_9 )
F_84 ( L_35 ) ;
}
