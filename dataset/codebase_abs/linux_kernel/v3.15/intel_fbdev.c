static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 =
F_2 ( V_2 , struct V_5 , V_2 ) ;
struct V_7 * V_8 ;
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_11 V_12 = {} ;
struct V_13 * V_14 ;
int V_15 , V_16 ;
if ( V_4 -> V_17 == 24 )
V_4 -> V_17 = 32 ;
V_12 . V_18 = V_4 -> V_19 ;
V_12 . V_20 = V_4 -> V_21 ;
V_12 . V_22 [ 0 ] = F_3 ( V_12 . V_18 *
F_4 ( V_4 -> V_17 , 8 ) , 64 ) ;
V_12 . V_23 = F_5 ( V_4 -> V_17 ,
V_4 -> V_24 ) ;
V_15 = V_12 . V_22 [ 0 ] * V_12 . V_20 ;
V_15 = F_3 ( V_15 , V_25 ) ;
V_14 = F_6 ( V_10 , V_15 ) ;
if ( V_14 == NULL )
V_14 = F_7 ( V_10 , V_15 ) ;
if ( ! V_14 ) {
F_8 ( L_1 ) ;
V_16 = - V_26 ;
goto V_27;
}
V_16 = F_9 ( V_10 , V_14 , NULL ) ;
if ( V_16 ) {
F_8 ( L_2 , V_16 ) ;
goto V_28;
}
V_8 = F_10 ( V_10 , & V_12 , V_14 ) ;
if ( F_11 ( V_8 ) ) {
V_16 = F_12 ( V_8 ) ;
goto V_29;
}
V_6 -> V_8 = F_13 ( V_8 ) ;
return 0 ;
V_29:
F_14 ( V_14 ) ;
V_28:
F_15 ( & V_14 -> V_30 ) ;
V_27:
return V_16 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 =
F_2 ( V_2 , struct V_5 , V_2 ) ;
struct V_31 * V_32 = V_6 -> V_8 ;
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_33 * V_34 = V_10 -> V_35 ;
struct V_36 * V_37 ;
struct V_7 * V_8 ;
struct V_13 * V_14 ;
int V_15 , V_16 ;
bool V_38 = false ;
F_17 ( & V_10 -> V_39 ) ;
if ( V_32 &&
( V_4 -> V_40 > V_32 -> V_30 . V_18 ||
V_4 -> V_41 > V_32 -> V_30 . V_20 ) ) {
F_18 ( L_3
L_4 ,
V_32 -> V_30 . V_18 , V_32 -> V_30 . V_20 ,
V_4 -> V_40 , V_4 -> V_41 ) ;
F_19 ( & V_32 -> V_30 ) ;
V_32 = V_6 -> V_8 = NULL ;
}
if ( ! V_32 || F_20 ( ! V_32 -> V_14 ) ) {
F_18 ( L_5 ) ;
V_16 = F_1 ( V_2 , V_4 ) ;
if ( V_16 )
goto V_42;
V_32 = V_6 -> V_8 ;
} else {
F_18 ( L_6 ) ;
V_38 = true ;
V_4 -> V_40 = V_32 -> V_30 . V_18 ;
V_4 -> V_41 = V_32 -> V_30 . V_20 ;
}
V_14 = V_32 -> V_14 ;
V_15 = V_14 -> V_30 . V_15 ;
V_37 = F_21 ( 0 , & V_10 -> V_43 -> V_10 ) ;
if ( ! V_37 ) {
V_16 = - V_26 ;
goto V_29;
}
V_37 -> V_44 = V_2 ;
V_8 = & V_6 -> V_8 -> V_30 ;
V_6 -> V_2 . V_8 = V_8 ;
V_6 -> V_2 . V_45 = V_37 ;
strcpy ( V_37 -> V_46 . V_47 , L_7 ) ;
V_37 -> V_48 = V_49 | V_50 ;
V_37 -> V_51 = & V_52 ;
V_16 = F_22 ( & V_37 -> V_53 , 256 , 0 ) ;
if ( V_16 ) {
V_16 = - V_26 ;
goto V_29;
}
V_37 -> V_54 = F_23 ( 1 ) ;
if ( ! V_37 -> V_54 ) {
V_16 = - V_26 ;
goto V_29;
}
V_37 -> V_54 -> V_55 [ 0 ] . V_30 = V_10 -> V_56 . V_57 ;
V_37 -> V_54 -> V_55 [ 0 ] . V_15 = V_34 -> V_58 . V_59 ;
V_37 -> V_46 . V_60 = V_10 -> V_56 . V_57 + F_24 ( V_14 ) ;
V_37 -> V_46 . V_61 = V_15 ;
V_37 -> V_62 =
F_25 ( V_34 -> V_58 . V_63 + F_24 ( V_14 ) ,
V_15 ) ;
if ( ! V_37 -> V_62 ) {
V_16 = - V_64 ;
goto V_29;
}
V_37 -> V_65 = V_15 ;
V_37 -> V_66 = true ;
F_26 ( V_37 , V_8 -> V_22 [ 0 ] , V_8 -> V_67 ) ;
F_27 ( V_37 , & V_6 -> V_2 , V_4 -> V_40 , V_4 -> V_41 ) ;
if ( V_6 -> V_8 -> V_14 -> V_68 && ! V_38 )
F_28 ( V_37 -> V_62 , 0 , V_37 -> V_65 ) ;
F_18 ( L_8 ,
V_8 -> V_18 , V_8 -> V_20 ,
F_24 ( V_14 ) , V_14 ) ;
F_29 ( & V_10 -> V_39 ) ;
F_30 ( V_10 -> V_43 , V_37 ) ;
return 0 ;
V_29:
F_14 ( V_14 ) ;
F_15 ( & V_14 -> V_30 ) ;
V_42:
F_29 ( & V_10 -> V_39 ) ;
return V_16 ;
}
static void F_31 ( struct V_69 * V_70 , T_1 V_71 , T_1 V_72 ,
T_1 V_73 , int V_74 )
{
struct V_75 * V_75 = F_32 ( V_70 ) ;
V_75 -> V_76 [ V_74 ] = V_71 >> 8 ;
V_75 -> V_77 [ V_74 ] = V_72 >> 8 ;
V_75 -> V_78 [ V_74 ] = V_73 >> 8 ;
}
static void F_33 ( struct V_69 * V_70 , T_1 * V_71 , T_1 * V_72 ,
T_1 * V_73 , int V_74 )
{
struct V_75 * V_75 = F_32 ( V_70 ) ;
* V_71 = V_75 -> V_76 [ V_74 ] << 8 ;
* V_72 = V_75 -> V_77 [ V_74 ] << 8 ;
* V_73 = V_75 -> V_78 [ V_74 ] << 8 ;
}
static struct V_79 *
F_34 ( struct V_1 * V_80 , struct V_69 * V_70 )
{
int V_81 ;
for ( V_81 = 0 ; V_81 < V_80 -> V_82 ; V_81 ++ )
if ( V_80 -> V_83 [ V_81 ] . V_84 . V_70 == V_70 )
return & V_80 -> V_83 [ V_81 ] ;
return NULL ;
}
static bool F_35 ( struct V_1 * V_80 ,
struct V_79 * * V_85 ,
struct V_86 * * V_87 ,
bool * V_88 , int V_18 , int V_20 )
{
struct V_9 * V_10 = V_80 -> V_10 ;
int V_81 , V_89 ;
bool * V_90 ;
bool V_91 = true ;
int V_92 = 0 ;
int V_93 = 0 ;
for ( V_81 = 0 ; V_81 < V_80 -> V_94 ; V_81 ++ ) {
struct V_95 * V_96 ;
struct V_97 * V_98 ;
V_96 = V_80 -> V_99 [ V_81 ] ;
V_98 = V_96 -> V_98 ;
if ( ! V_88 [ V_81 ] )
continue;
if ( V_98 -> V_100 != V_101 )
return false ;
}
V_90 = F_36 ( V_10 -> V_56 . V_102 , sizeof( bool ) ,
V_103 ) ;
if ( ! V_90 )
return false ;
memcpy ( V_90 , V_88 , V_10 -> V_56 . V_102 ) ;
for ( V_81 = 0 ; V_81 < V_80 -> V_94 ; V_81 ++ ) {
struct V_95 * V_96 ;
struct V_97 * V_98 ;
struct V_104 * V_105 ;
struct V_79 * V_106 ;
V_96 = V_80 -> V_99 [ V_81 ] ;
V_98 = V_96 -> V_98 ;
if ( V_98 -> V_107 == V_108 )
V_93 ++ ;
if ( ! V_88 [ V_81 ] ) {
F_18 ( L_9 ,
V_98 -> V_30 . V_47 ) ;
continue;
}
V_105 = V_98 -> V_105 ;
if ( ! V_105 || F_20 ( ! V_105 -> V_70 ) ) {
F_18 ( L_10 ,
V_98 -> V_30 . V_47 ) ;
V_88 [ V_81 ] = false ;
continue;
}
V_92 ++ ;
V_106 = F_34 ( V_80 , V_105 -> V_70 ) ;
for ( V_89 = 0 ; V_89 < V_80 -> V_94 ; V_89 ++ ) {
if ( V_85 [ V_89 ] == V_106 ) {
F_18 ( L_11 ) ;
V_91 = true ;
goto V_27;
}
}
F_18 ( L_12 ,
V_96 -> V_98 -> V_30 . V_47 ) ;
V_87 [ V_81 ] = F_37 ( V_96 , V_18 , V_20 ) ;
if ( ! V_87 [ V_81 ] ) {
F_18 ( L_13 ,
V_96 -> V_98 -> V_30 . V_47 ) ;
V_87 [ V_81 ] = F_38 ( V_96 , V_18 ,
V_20 ) ;
}
if ( ! V_87 [ V_81 ] && ! F_39 ( & V_98 -> V_87 ) ) {
F_18 ( L_14 ,
F_40 ( V_98 ) ) ;
V_87 [ V_81 ] = F_41 ( & V_98 -> V_87 ,
struct V_86 ,
V_109 ) ;
}
if ( ! V_87 [ V_81 ] ) {
F_42 ( & V_105 -> V_70 -> V_110 ,
& F_32 ( V_105 -> V_70 ) -> V_111 ) ;
V_87 [ V_81 ] = & V_105 -> V_70 -> V_110 ;
}
V_85 [ V_81 ] = V_106 ;
F_18 ( L_15 ,
F_40 ( V_98 ) ,
V_105 -> V_70 -> V_30 . V_47 ,
V_87 [ V_81 ] -> V_112 ) ;
V_91 = false ;
}
if ( V_92 != V_93 &&
V_92 < F_43 ( V_10 ) -> V_113 ) {
F_18 ( L_16 ) ;
F_18 ( L_17 , V_92 ,
V_93 ) ;
V_91 = true ;
}
V_27:
if ( V_91 ) {
F_18 ( L_18 ) ;
memcpy ( V_88 , V_90 , V_10 -> V_56 . V_102 ) ;
F_44 ( V_90 ) ;
return false ;
}
F_44 ( V_90 ) ;
return true ;
}
static void F_45 ( struct V_9 * V_10 ,
struct V_5 * V_6 )
{
if ( V_6 -> V_2 . V_45 ) {
struct V_36 * V_37 = V_6 -> V_2 . V_45 ;
F_46 ( V_37 ) ;
F_47 ( V_37 -> V_62 ) ;
if ( V_37 -> V_53 . V_114 )
F_48 ( & V_37 -> V_53 ) ;
F_49 ( V_37 ) ;
}
F_50 ( & V_6 -> V_2 ) ;
F_51 ( & V_6 -> V_8 -> V_30 ) ;
F_52 ( & V_6 -> V_8 -> V_30 ) ;
}
static bool F_53 ( struct V_9 * V_10 ,
struct V_5 * V_6 )
{
struct V_31 * V_8 = NULL ;
struct V_69 * V_70 ;
struct V_75 * V_75 ;
struct V_115 * V_116 = NULL ;
unsigned int V_117 = 0 ;
if ( ! V_118 . V_119 )
return false ;
F_54 (crtc, &dev->mode_config.crtc_list, head) {
V_75 = F_32 ( V_70 ) ;
if ( ! V_75 -> V_120 || ! V_70 -> V_121 -> V_8 ) {
F_18 ( L_19 ,
F_55 ( V_75 -> V_122 ) ) ;
continue;
}
if ( V_75 -> V_116 . V_15 > V_117 ) {
F_18 ( L_20 ,
F_55 ( V_75 -> V_122 ) ) ;
V_116 = & V_75 -> V_116 ;
V_8 = F_13 ( V_70 -> V_121 -> V_8 ) ;
V_117 = V_116 -> V_15 ;
}
}
if ( ! V_8 ) {
F_18 ( L_21 ) ;
goto V_27;
}
F_54 (crtc, &dev->mode_config.crtc_list, head) {
unsigned int V_123 ;
V_75 = F_32 ( V_70 ) ;
if ( ! V_75 -> V_120 ) {
F_18 ( L_22 ,
F_55 ( V_75 -> V_122 ) ) ;
continue;
}
F_18 ( L_23 ,
F_55 ( V_75 -> V_122 ) ) ;
V_123 = V_75 -> V_111 . V_124 . V_125 ;
V_123 = V_123 * V_8 -> V_30 . V_126 / 8 ;
if ( V_8 -> V_30 . V_22 [ 0 ] < V_123 ) {
F_18 ( L_24 ,
F_55 ( V_75 -> V_122 ) ,
V_123 , V_8 -> V_30 . V_22 [ 0 ] ) ;
V_116 = NULL ;
V_8 = NULL ;
break;
}
V_123 = V_75 -> V_111 . V_124 . V_127 ;
V_123 = F_3 ( V_123 , V_116 -> V_128 ? ( F_56 ( V_10 ) ? 16 : 8 ) : 1 ) ;
V_123 *= V_8 -> V_30 . V_22 [ 0 ] ;
F_18 ( L_25 ,
F_55 ( V_75 -> V_122 ) ,
V_75 -> V_111 . V_124 . V_125 ,
V_75 -> V_111 . V_124 . V_127 ,
V_8 -> V_30 . V_126 ,
V_123 ) ;
if ( V_123 > V_117 ) {
F_18 ( L_26 ,
F_55 ( V_75 -> V_122 ) ,
V_123 , V_117 ) ;
V_116 = NULL ;
V_8 = NULL ;
break;
}
F_18 ( L_27 ,
F_55 ( V_75 -> V_122 ) ,
V_117 , V_123 ) ;
}
if ( ! V_8 ) {
F_18 ( L_28 ) ;
goto V_27;
}
V_6 -> V_129 = V_8 -> V_30 . V_126 ;
V_6 -> V_8 = V_8 ;
F_57 ( & V_6 -> V_8 -> V_30 ) ;
F_54 (crtc, &dev->mode_config.crtc_list, head) {
V_75 = F_32 ( V_70 ) ;
if ( ! V_75 -> V_120 )
continue;
F_58 ( ! V_70 -> V_121 -> V_8 ,
L_29 ,
V_70 -> V_30 . V_47 ) ;
}
F_18 ( L_30 ) ;
return true ;
V_27:
return false ;
}
int F_59 ( struct V_9 * V_10 )
{
struct V_5 * V_6 ;
struct V_33 * V_34 = V_10 -> V_35 ;
int V_16 ;
if ( F_20 ( F_43 ( V_10 ) -> V_113 == 0 ) )
return - V_130 ;
V_6 = F_60 ( sizeof( struct V_5 ) , V_103 ) ;
if ( V_6 == NULL )
return - V_26 ;
V_6 -> V_2 . V_131 = & V_132 ;
if ( ! F_53 ( V_10 , V_6 ) )
V_6 -> V_129 = 32 ;
V_16 = F_61 ( V_10 , & V_6 -> V_2 ,
F_43 ( V_10 ) -> V_113 , 4 ) ;
if ( V_16 ) {
F_44 ( V_6 ) ;
return V_16 ;
}
V_34 -> V_45 = V_6 ;
F_62 ( & V_6 -> V_2 ) ;
return 0 ;
}
void F_63 ( struct V_9 * V_10 )
{
struct V_33 * V_34 = V_10 -> V_35 ;
struct V_5 * V_6 = V_34 -> V_45 ;
F_64 ( & V_6 -> V_2 , V_6 -> V_129 ) ;
}
void F_65 ( struct V_9 * V_10 )
{
struct V_33 * V_34 = V_10 -> V_35 ;
if ( ! V_34 -> V_45 )
return;
F_45 ( V_10 , V_34 -> V_45 ) ;
F_44 ( V_34 -> V_45 ) ;
V_34 -> V_45 = NULL ;
}
void F_66 ( struct V_9 * V_10 , int V_133 )
{
struct V_33 * V_34 = V_10 -> V_35 ;
struct V_5 * V_6 = V_34 -> V_45 ;
struct V_36 * V_37 ;
if ( ! V_6 )
return;
V_37 = V_6 -> V_2 . V_45 ;
if ( V_133 == V_134 && V_6 -> V_8 -> V_14 -> V_68 )
F_28 ( V_37 -> V_62 , 0 , V_37 -> V_65 ) ;
F_67 ( V_37 , V_133 ) ;
}
void F_68 ( struct V_9 * V_10 )
{
struct V_33 * V_34 = V_10 -> V_35 ;
if ( V_34 -> V_45 )
F_69 ( & V_34 -> V_45 -> V_2 ) ;
}
void F_70 ( struct V_9 * V_10 )
{
int V_16 ;
struct V_33 * V_34 = V_10 -> V_35 ;
if ( ! V_34 -> V_45 )
return;
F_71 ( V_10 ) ;
V_16 = F_72 ( & V_34 -> V_45 -> V_2 ) ;
if ( V_16 )
F_73 ( L_31 ) ;
F_74 ( V_10 ) ;
}
