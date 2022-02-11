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
V_9 = F_15 ( V_10 , V_13 , NULL ) ;
if ( V_9 ) {
F_14 ( L_2 , V_9 ) ;
goto V_32;
}
V_12 = F_16 ( V_10 , & V_19 , V_13 ) ;
if ( F_17 ( V_12 ) ) {
V_9 = F_18 ( V_12 ) ;
goto V_33;
}
V_7 -> V_12 = F_19 ( V_12 ) ;
return 0 ;
V_33:
F_20 ( V_13 ) ;
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
goto V_33;
}
V_2 -> V_5 = V_8 ;
V_12 = & V_7 -> V_12 -> V_34 ;
V_7 -> V_8 . V_12 = V_12 ;
V_7 -> V_8 . V_45 = V_2 ;
strcpy ( V_2 -> V_46 . V_47 , L_7 ) ;
V_2 -> V_48 = V_49 | V_50 ;
V_2 -> V_51 = & V_52 ;
V_9 = F_27 ( & V_2 -> V_53 , 256 , 0 ) ;
if ( V_9 ) {
V_9 = - V_30 ;
goto V_33;
}
V_2 -> V_54 = F_28 ( 1 ) ;
if ( ! V_2 -> V_54 ) {
V_9 = - V_30 ;
goto V_33;
}
V_2 -> V_54 -> V_55 [ 0 ] . V_34 = V_10 -> V_56 . V_57 ;
V_2 -> V_54 -> V_55 [ 0 ] . V_21 = V_38 -> V_58 . V_59 ;
V_2 -> V_46 . V_60 = V_10 -> V_56 . V_57 + F_29 ( V_13 ) ;
V_2 -> V_46 . V_61 = V_21 ;
V_2 -> V_62 =
F_30 ( V_38 -> V_58 . V_63 + F_29 ( V_13 ) ,
V_21 ) ;
if ( ! V_2 -> V_62 ) {
V_9 = - V_64 ;
goto V_33;
}
V_2 -> V_65 = V_21 ;
V_2 -> V_66 = true ;
F_31 ( V_2 , V_12 -> V_27 [ 0 ] , V_12 -> V_67 ) ;
F_32 ( V_2 , & V_7 -> V_8 , V_15 -> V_41 , V_15 -> V_42 ) ;
if ( V_7 -> V_12 -> V_13 -> V_68 && ! V_40 )
F_33 ( V_2 -> V_62 , 0 , V_2 -> V_65 ) ;
F_23 ( L_8 ,
V_12 -> V_23 , V_12 -> V_25 ,
F_29 ( V_13 ) , V_13 ) ;
F_6 ( & V_10 -> V_11 ) ;
F_34 ( V_10 -> V_44 , V_2 ) ;
return 0 ;
V_33:
F_20 ( V_13 ) ;
F_21 ( & V_13 -> V_34 ) ;
V_43:
F_6 ( & V_10 -> V_11 ) ;
return V_9 ;
}
static void F_35 ( struct V_69 * V_70 , T_1 V_71 , T_1 V_72 ,
T_1 V_73 , int V_74 )
{
struct V_75 * V_75 = F_36 ( V_70 ) ;
V_75 -> V_76 [ V_74 ] = V_71 >> 8 ;
V_75 -> V_77 [ V_74 ] = V_72 >> 8 ;
V_75 -> V_78 [ V_74 ] = V_73 >> 8 ;
}
static void F_37 ( struct V_69 * V_70 , T_1 * V_71 , T_1 * V_72 ,
T_1 * V_73 , int V_74 )
{
struct V_75 * V_75 = F_36 ( V_70 ) ;
* V_71 = V_75 -> V_76 [ V_74 ] << 8 ;
* V_72 = V_75 -> V_77 [ V_74 ] << 8 ;
* V_73 = V_75 -> V_78 [ V_74 ] << 8 ;
}
static struct V_79 *
F_38 ( struct V_3 * V_4 , struct V_69 * V_70 )
{
int V_80 ;
for ( V_80 = 0 ; V_80 < V_4 -> V_81 ; V_80 ++ )
if ( V_4 -> V_82 [ V_80 ] . V_83 . V_70 == V_70 )
return & V_4 -> V_82 [ V_80 ] ;
return NULL ;
}
static bool F_39 ( struct V_3 * V_4 ,
struct V_79 * * V_84 ,
struct V_85 * * V_86 ,
bool * V_87 , int V_23 , int V_25 )
{
struct V_17 * V_10 = V_4 -> V_10 ;
int V_80 , V_88 ;
bool * V_89 ;
bool V_90 = true ;
int V_91 = 0 ;
int V_92 = 0 ;
V_89 = F_40 ( V_10 -> V_56 . V_93 , sizeof( bool ) ,
V_94 ) ;
if ( ! V_89 )
return false ;
memcpy ( V_89 , V_87 , V_10 -> V_56 . V_93 ) ;
for ( V_80 = 0 ; V_80 < V_4 -> V_95 ; V_80 ++ ) {
struct V_96 * V_97 ;
struct V_98 * V_99 ;
struct V_100 * V_101 ;
struct V_79 * V_102 ;
V_97 = V_4 -> V_103 [ V_80 ] ;
V_99 = V_97 -> V_99 ;
if ( V_99 -> V_104 == V_105 )
V_92 ++ ;
if ( ! V_87 [ V_80 ] ) {
F_23 ( L_9 ,
V_99 -> V_106 ) ;
continue;
}
if ( V_99 -> V_107 == V_108 ) {
F_23 ( L_10 ,
V_99 -> V_106 ) ;
V_87 [ V_80 ] = false ;
continue;
}
V_101 = V_99 -> V_101 ;
if ( ! V_101 || F_25 ( ! V_101 -> V_70 ) ) {
if ( V_99 -> V_107 > V_108 )
goto V_109;
F_23 ( L_11 ,
V_99 -> V_106 ) ;
V_87 [ V_80 ] = false ;
continue;
}
V_91 ++ ;
V_102 = F_38 ( V_4 , V_101 -> V_70 ) ;
for ( V_88 = 0 ; V_88 < V_4 -> V_95 ; V_88 ++ ) {
if ( V_84 [ V_88 ] == V_102 ) {
F_23 ( L_12 ) ;
goto V_109;
}
}
F_23 ( L_13 ,
V_99 -> V_106 ) ;
V_86 [ V_80 ] = F_41 ( V_97 , V_23 , V_25 ) ;
if ( ! V_86 [ V_80 ] ) {
F_23 ( L_14 ,
V_99 -> V_106 ) ;
V_86 [ V_80 ] = F_42 ( V_97 , V_23 ,
V_25 ) ;
}
if ( ! V_86 [ V_80 ] && ! F_43 ( & V_99 -> V_86 ) ) {
F_23 ( L_15 ,
V_99 -> V_106 ) ;
V_86 [ V_80 ] = F_44 ( & V_99 -> V_86 ,
struct V_85 ,
V_110 ) ;
}
if ( ! V_86 [ V_80 ] ) {
F_23 ( L_16 ,
V_99 -> V_106 ) ;
F_45 ( & V_101 -> V_70 -> V_111 ,
& F_36 ( V_101 -> V_70 ) -> V_112 ) ;
V_86 [ V_80 ] = & V_101 -> V_70 -> V_111 ;
}
V_84 [ V_80 ] = V_102 ;
F_23 ( L_17 ,
V_99 -> V_106 ,
F_46 ( F_36 ( V_101 -> V_70 ) -> V_113 ) ,
V_101 -> V_70 -> V_34 . V_47 ,
V_86 [ V_80 ] -> V_114 , V_86 [ V_80 ] -> V_115 ,
V_86 [ V_80 ] -> V_48 & V_116 ? L_18 : L_19 ) ;
V_90 = false ;
}
if ( V_91 != V_92 &&
V_91 < F_47 ( V_10 ) -> V_117 ) {
F_23 ( L_20 ) ;
F_23 ( L_21 , V_91 ,
V_92 ) ;
V_90 = true ;
}
if ( V_90 ) {
V_109:
F_23 ( L_22 ) ;
memcpy ( V_87 , V_89 , V_10 -> V_56 . V_93 ) ;
F_48 ( V_89 ) ;
return false ;
}
F_48 ( V_89 ) ;
return true ;
}
static void F_49 ( struct V_17 * V_10 ,
struct V_6 * V_7 )
{
if ( V_7 -> V_8 . V_45 ) {
struct V_1 * V_2 = V_7 -> V_8 . V_45 ;
F_50 ( V_2 ) ;
F_51 ( V_2 -> V_62 ) ;
if ( V_2 -> V_53 . V_118 )
F_52 ( & V_2 -> V_53 ) ;
F_53 ( V_2 ) ;
}
F_54 ( & V_7 -> V_8 ) ;
F_55 ( & V_7 -> V_12 -> V_34 ) ;
F_56 ( & V_7 -> V_12 -> V_34 ) ;
}
static bool F_57 ( struct V_17 * V_10 ,
struct V_6 * V_7 )
{
struct V_35 * V_12 = NULL ;
struct V_69 * V_70 ;
struct V_75 * V_75 ;
struct V_119 * V_120 = NULL ;
unsigned int V_121 = 0 ;
if ( ! V_122 . V_123 )
return false ;
F_58 (dev, crtc) {
V_75 = F_36 ( V_70 ) ;
if ( ! V_75 -> V_124 || ! V_70 -> V_125 -> V_12 ) {
F_23 ( L_23 ,
F_46 ( V_75 -> V_113 ) ) ;
continue;
}
if ( V_75 -> V_120 . V_21 > V_121 ) {
F_23 ( L_24 ,
F_46 ( V_75 -> V_113 ) ) ;
V_120 = & V_75 -> V_120 ;
V_12 = F_19 ( V_70 -> V_125 -> V_12 ) ;
V_121 = V_120 -> V_21 ;
}
}
if ( ! V_12 ) {
F_23 ( L_25 ) ;
goto V_31;
}
F_58 (dev, crtc) {
unsigned int V_126 ;
V_75 = F_36 ( V_70 ) ;
if ( ! V_75 -> V_124 ) {
F_23 ( L_26 ,
F_46 ( V_75 -> V_113 ) ) ;
continue;
}
F_23 ( L_27 ,
F_46 ( V_75 -> V_113 ) ) ;
V_126 = V_75 -> V_112 . V_127 . V_128 ;
V_126 = V_126 * V_12 -> V_34 . V_129 / 8 ;
if ( V_12 -> V_34 . V_27 [ 0 ] < V_126 ) {
F_23 ( L_28 ,
F_46 ( V_75 -> V_113 ) ,
V_126 , V_12 -> V_34 . V_27 [ 0 ] ) ;
V_120 = NULL ;
V_12 = NULL ;
break;
}
V_126 = V_75 -> V_112 . V_127 . V_130 ;
V_126 = F_8 ( V_126 , V_120 -> V_131 ? ( F_59 ( V_10 ) ? 16 : 8 ) : 1 ) ;
V_126 *= V_12 -> V_34 . V_27 [ 0 ] ;
F_23 ( L_29 ,
F_46 ( V_75 -> V_113 ) ,
V_75 -> V_112 . V_127 . V_128 ,
V_75 -> V_112 . V_127 . V_130 ,
V_12 -> V_34 . V_129 ,
V_126 ) ;
if ( V_126 > V_121 ) {
F_23 ( L_30 ,
F_46 ( V_75 -> V_113 ) ,
V_126 , V_121 ) ;
V_120 = NULL ;
V_12 = NULL ;
break;
}
F_23 ( L_31 ,
F_46 ( V_75 -> V_113 ) ,
V_121 , V_126 ) ;
}
if ( ! V_12 ) {
F_23 ( L_32 ) ;
goto V_31;
}
V_7 -> V_132 = V_12 -> V_34 . V_129 ;
V_7 -> V_12 = V_12 ;
F_60 ( & V_7 -> V_12 -> V_34 ) ;
F_58 (dev, crtc) {
V_75 = F_36 ( V_70 ) ;
if ( ! V_75 -> V_124 )
continue;
F_61 ( ! V_70 -> V_125 -> V_12 ,
L_33 ,
V_70 -> V_34 . V_47 ) ;
}
F_23 ( L_34 ) ;
return true ;
V_31:
return false ;
}
static void F_62 ( struct V_133 * V_134 )
{
F_63 ( F_2 ( V_134 ,
struct V_37 ,
V_135 ) -> V_10 ,
V_136 ,
true ) ;
}
int F_64 ( struct V_17 * V_10 )
{
struct V_6 * V_7 ;
struct V_37 * V_38 = V_10 -> V_39 ;
int V_9 ;
if ( F_25 ( F_47 ( V_10 ) -> V_117 == 0 ) )
return - V_137 ;
V_7 = F_65 ( sizeof( struct V_6 ) , V_94 ) ;
if ( V_7 == NULL )
return - V_30 ;
F_66 ( V_10 , & V_7 -> V_8 , & V_138 ) ;
if ( ! F_57 ( V_10 , V_7 ) )
V_7 -> V_132 = 32 ;
V_9 = F_67 ( V_10 , & V_7 -> V_8 ,
F_47 ( V_10 ) -> V_117 , 4 ) ;
if ( V_9 ) {
F_48 ( V_7 ) ;
return V_9 ;
}
V_38 -> V_45 = V_7 ;
F_68 ( & V_38 -> V_135 , F_62 ) ;
F_69 ( & V_7 -> V_8 ) ;
return 0 ;
}
void F_70 ( void * V_139 , T_2 V_140 )
{
struct V_37 * V_38 = V_139 ;
struct V_6 * V_7 = V_38 -> V_45 ;
F_71 ( & V_7 -> V_8 , V_7 -> V_132 ) ;
}
void F_72 ( struct V_17 * V_10 )
{
struct V_37 * V_38 = V_10 -> V_39 ;
if ( ! V_38 -> V_45 )
return;
F_73 ( & V_38 -> V_135 ) ;
F_74 () ;
F_49 ( V_10 , V_38 -> V_45 ) ;
F_48 ( V_38 -> V_45 ) ;
V_38 -> V_45 = NULL ;
}
void F_63 ( struct V_17 * V_10 , int V_141 , bool V_142 )
{
struct V_37 * V_38 = V_10 -> V_39 ;
struct V_6 * V_7 = V_38 -> V_45 ;
struct V_1 * V_2 ;
if ( ! V_7 )
return;
V_2 = V_7 -> V_8 . V_45 ;
if ( V_142 ) {
if ( V_141 != V_136 )
F_73 ( & V_38 -> V_135 ) ;
F_75 () ;
} else {
F_25 ( V_141 != V_136 ) ;
if ( ! F_76 () ) {
F_77 ( & V_38 -> V_135 ) ;
return;
}
}
if ( V_141 == V_136 && V_7 -> V_12 -> V_13 -> V_68 )
F_33 ( V_2 -> V_62 , 0 , V_2 -> V_65 ) ;
F_78 ( V_2 , V_141 ) ;
F_79 () ;
}
void F_80 ( struct V_17 * V_10 )
{
struct V_37 * V_38 = V_10 -> V_39 ;
if ( V_38 -> V_45 )
F_81 ( & V_38 -> V_45 -> V_8 ) ;
}
void F_82 ( struct V_17 * V_10 )
{
int V_9 ;
struct V_37 * V_38 = V_10 -> V_39 ;
if ( ! V_38 -> V_45 )
return;
V_9 = F_83 ( & V_38 -> V_45 -> V_8 ) ;
if ( V_9 )
F_84 ( L_35 ) ;
}
