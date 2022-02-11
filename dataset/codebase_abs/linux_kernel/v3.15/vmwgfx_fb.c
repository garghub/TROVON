static int F_1 ( unsigned V_1 , unsigned V_2 , unsigned V_3 ,
unsigned V_4 , unsigned V_5 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
T_1 * V_10 = V_9 -> V_11 ;
if ( V_1 > 15 ) {
F_2 ( L_1 , V_1 ) ;
return 1 ;
}
switch ( V_9 -> V_12 ) {
case 24 :
case 32 :
V_10 [ V_1 ] = ( ( V_2 & 0xff00 ) << 8 ) |
( V_3 & 0xff00 ) |
( ( V_4 & 0xff00 ) >> 8 ) ;
break;
default:
F_2 ( L_2 , V_9 -> V_12 , V_9 -> V_13 ) ;
return 1 ;
}
return 0 ;
}
static int F_3 ( struct V_14 * V_15 ,
struct V_6 * V_7 )
{
int V_12 = V_15 -> V_16 ;
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_17 * V_18 = V_9 -> V_18 ;
switch ( V_15 -> V_16 ) {
case 32 :
V_12 = ( V_15 -> V_5 . V_19 > 0 ) ? 32 : 24 ;
break;
default:
F_2 ( L_3 , V_15 -> V_16 ) ;
return - V_20 ;
}
switch ( V_12 ) {
case 24 :
V_15 -> V_2 . V_21 = 16 ;
V_15 -> V_3 . V_21 = 8 ;
V_15 -> V_4 . V_21 = 0 ;
V_15 -> V_2 . V_19 = 8 ;
V_15 -> V_3 . V_19 = 8 ;
V_15 -> V_4 . V_19 = 8 ;
V_15 -> V_5 . V_19 = 0 ;
V_15 -> V_5 . V_21 = 0 ;
break;
case 32 :
V_15 -> V_2 . V_21 = 16 ;
V_15 -> V_3 . V_21 = 8 ;
V_15 -> V_4 . V_21 = 0 ;
V_15 -> V_2 . V_19 = 8 ;
V_15 -> V_3 . V_19 = 8 ;
V_15 -> V_4 . V_19 = 8 ;
V_15 -> V_5 . V_19 = 8 ;
V_15 -> V_5 . V_21 = 24 ;
break;
default:
F_2 ( L_4 , V_12 ) ;
return - V_20 ;
}
if ( ! ( V_18 -> V_22 & V_23 ) &&
( V_15 -> V_24 != 0 || V_15 -> V_25 != 0 ) ) {
F_2 ( L_5 ) ;
return - V_20 ;
}
if ( ( V_15 -> V_24 + V_15 -> V_26 ) > V_9 -> V_27 ||
( V_15 -> V_25 + V_15 -> V_28 ) > V_9 -> V_29 ) {
F_2 ( L_6 ) ;
return - V_20 ;
}
if ( ! F_4 ( V_18 ,
V_15 -> V_26 * V_15 -> V_16 / 8 ,
V_15 -> V_25 + V_15 -> V_28 ) ) {
F_2 ( L_6 ) ;
return - V_20 ;
}
return 0 ;
}
static int F_5 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_17 * V_18 = V_9 -> V_18 ;
int V_30 ;
V_7 -> V_31 . V_32 = V_7 -> V_15 . V_26 * V_7 -> V_15 . V_16 / 8 ;
V_30 = F_6 ( V_18 , V_7 -> V_15 . V_26 , V_7 -> V_15 . V_28 ,
V_7 -> V_31 . V_32 ,
V_9 -> V_13 , V_9 -> V_12 ) ;
if ( V_30 )
return V_30 ;
if ( V_18 -> V_22 & V_23 ) {
F_7 ( V_18 , V_33 , 1 ) ;
F_7 ( V_18 , V_34 , 0 ) ;
F_7 ( V_18 , V_35 , true ) ;
F_7 ( V_18 , V_36 , V_7 -> V_15 . V_24 ) ;
F_7 ( V_18 , V_37 , V_7 -> V_15 . V_25 ) ;
F_7 ( V_18 , V_38 , V_7 -> V_15 . V_26 ) ;
F_7 ( V_18 , V_39 , V_7 -> V_15 . V_28 ) ;
F_7 ( V_18 , V_40 , V_7 -> V_31 . V_32 ) ;
F_7 ( V_18 , V_34 , V_41 ) ;
}
F_8 ( F_9 ( V_18 , V_42 ) != 0 ) ;
return 0 ;
}
static int F_10 ( struct V_14 * V_15 ,
struct V_6 * V_7 )
{
return 0 ;
}
static int F_11 ( int V_43 , struct V_6 * V_7 )
{
return 0 ;
}
static void F_12 ( struct V_8 * V_9 )
{
struct V_17 * V_18 = V_9 -> V_18 ;
struct V_6 * V_7 = V_18 -> V_6 ;
int V_44 = ( V_7 -> V_31 . V_32 / 4 ) ;
int * V_45 = ( int * ) V_7 -> V_46 ;
T_2 T_3 * V_47 = V_9 -> V_48 ;
unsigned long V_49 ;
unsigned V_50 , V_51 , V_52 , V_53 ;
int V_54 , V_55 ;
struct {
T_4 V_56 ;
T_5 V_57 ;
} * V_58 ;
if ( V_18 -> V_59 )
return;
F_13 ( & V_9 -> V_60 . V_61 , V_49 ) ;
if ( ! V_9 -> V_60 . V_62 ) {
F_14 ( & V_9 -> V_60 . V_61 , V_49 ) ;
return;
}
V_50 = V_9 -> V_60 . V_63 ;
V_51 = V_9 -> V_60 . y1 ;
V_52 = F_15 ( V_9 -> V_60 . V_64 , V_7 -> V_15 . V_26 ) - V_50 ;
V_53 = F_15 ( V_9 -> V_60 . V_65 , V_7 -> V_15 . V_28 ) - V_51 ;
V_9 -> V_60 . V_63 = V_9 -> V_60 . V_64 = 0 ;
V_9 -> V_60 . y1 = V_9 -> V_60 . V_65 = 0 ;
F_14 ( & V_9 -> V_60 . V_61 , V_49 ) ;
for ( V_54 = V_51 * V_44 ; V_54 < V_7 -> V_31 . V_66 / 4 ; V_54 += V_44 ) {
for ( V_55 = V_54 + V_50 ; V_55 < V_54 + V_50 + V_52 && V_55 < V_7 -> V_31 . V_66 / 4 ; V_55 ++ )
F_16 ( V_45 [ V_55 ] , V_47 + V_55 ) ;
}
#if 0
DRM_INFO("%s, (%u, %u) (%ux%u)\n", __func__, x, y, w, h);
#endif
V_58 = F_17 ( V_18 , sizeof( * V_58 ) ) ;
if ( F_18 ( V_58 == NULL ) ) {
F_2 ( L_7 ) ;
return;
}
V_58 -> V_56 = F_19 ( V_67 ) ;
V_58 -> V_57 . V_50 = F_19 ( V_50 ) ;
V_58 -> V_57 . V_51 = F_19 ( V_51 ) ;
V_58 -> V_57 . V_68 = F_19 ( V_52 ) ;
V_58 -> V_57 . V_69 = F_19 ( V_53 ) ;
F_20 ( V_18 , sizeof( * V_58 ) ) ;
}
static void F_21 ( struct V_8 * V_9 ,
unsigned V_63 , unsigned y1 ,
unsigned V_68 , unsigned V_69 )
{
struct V_6 * V_7 = V_9 -> V_18 -> V_6 ;
unsigned long V_49 ;
unsigned V_64 = V_63 + V_68 ;
unsigned V_65 = y1 + V_69 ;
F_13 ( & V_9 -> V_60 . V_61 , V_49 ) ;
if ( V_9 -> V_60 . V_63 == V_9 -> V_60 . V_64 ) {
V_9 -> V_60 . V_63 = V_63 ;
V_9 -> V_60 . y1 = y1 ;
V_9 -> V_60 . V_64 = V_64 ;
V_9 -> V_60 . V_65 = V_65 ;
if ( V_9 -> V_60 . V_62 )
F_22 ( & V_7 -> V_70 , V_71 ) ;
} else {
if ( V_63 < V_9 -> V_60 . V_63 )
V_9 -> V_60 . V_63 = V_63 ;
if ( y1 < V_9 -> V_60 . y1 )
V_9 -> V_60 . y1 = y1 ;
if ( V_64 > V_9 -> V_60 . V_64 )
V_9 -> V_60 . V_64 = V_64 ;
if ( V_65 > V_9 -> V_60 . V_65 )
V_9 -> V_60 . V_65 = V_65 ;
}
F_14 ( & V_9 -> V_60 . V_61 , V_49 ) ;
}
static void F_23 ( struct V_6 * V_7 ,
struct V_72 * V_73 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
unsigned long V_74 , V_75 , F_15 , V_76 ;
unsigned long V_49 ;
struct V_77 * V_77 ;
int y1 , V_65 ;
F_15 = V_78 ;
V_76 = 0 ;
F_24 (page, pagelist, lru) {
V_74 = V_77 -> V_79 << V_80 ;
V_75 = V_74 + V_81 - 1 ;
F_15 = F_15 ( F_15 , V_74 ) ;
V_76 = V_76 ( V_76 , V_75 ) ;
}
if ( F_15 < V_76 ) {
y1 = F_15 / V_7 -> V_31 . V_32 ;
V_65 = ( V_76 / V_7 -> V_31 . V_32 ) + 1 ;
F_13 ( & V_9 -> V_60 . V_61 , V_49 ) ;
V_9 -> V_60 . V_63 = 0 ;
V_9 -> V_60 . y1 = y1 ;
V_9 -> V_60 . V_64 = V_7 -> V_15 . V_26 ;
V_9 -> V_60 . V_65 = V_65 ;
F_14 ( & V_9 -> V_60 . V_61 , V_49 ) ;
}
F_12 ( V_9 ) ;
}
static void F_25 ( struct V_6 * V_7 , const struct V_82 * V_83 )
{
F_26 ( V_7 , V_83 ) ;
F_21 ( V_7 -> V_9 , V_83 -> V_84 , V_83 -> V_85 ,
V_83 -> V_68 , V_83 -> V_69 ) ;
}
static void F_27 ( struct V_6 * V_7 , const struct V_86 * V_87 )
{
F_28 ( V_7 , V_87 ) ;
F_21 ( V_7 -> V_9 , V_87 -> V_84 , V_87 -> V_85 ,
V_87 -> V_68 , V_87 -> V_69 ) ;
}
static void F_29 ( struct V_6 * V_7 , const struct V_88 * V_89 )
{
F_30 ( V_7 , V_89 ) ;
F_21 ( V_7 -> V_9 , V_89 -> V_84 , V_89 -> V_85 ,
V_89 -> V_68 , V_89 -> V_69 ) ;
}
static int F_31 ( struct V_17 * V_18 ,
T_6 V_90 , struct V_91 * * V_92 )
{
struct V_91 * V_93 ;
struct V_94 V_95 = V_96 ;
int V_30 ;
V_95 . V_97 = ( V_90 + V_81 - 1 ) >> V_80 ;
( void ) F_32 ( & V_18 -> V_98 , false ) ;
V_93 = F_33 ( sizeof( * V_93 ) , V_99 ) ;
if ( ! V_93 ) {
V_30 = - V_100 ;
goto V_101;
}
V_30 = F_34 ( V_18 , V_93 , V_90 ,
& V_95 ,
false ,
& V_102 ) ;
if ( F_18 ( V_30 != 0 ) )
goto V_101;
* V_92 = V_93 ;
F_35 ( & V_18 -> V_103 . V_61 ) ;
return 0 ;
V_101:
F_35 ( & V_18 -> V_103 . V_61 ) ;
return V_30 ;
}
int F_36 ( struct V_17 * V_18 )
{
struct V_104 * V_104 = & V_18 -> V_105 -> V_106 -> V_105 ;
struct V_8 * V_9 ;
struct V_6 * V_7 ;
unsigned V_107 , V_108 ;
unsigned V_109 , V_110 ;
unsigned V_111 , V_112 , V_113 , V_114 , V_115 ;
int V_30 ;
V_111 = 32 ;
V_112 = 24 ;
V_109 = F_15 ( V_18 -> V_116 , ( unsigned ) 2048 ) ;
V_110 = F_15 ( V_18 -> V_117 , ( unsigned ) 2048 ) ;
V_107 = F_15 ( V_18 -> V_107 , V_109 ) ;
V_108 = F_15 ( V_18 -> V_108 , V_110 ) ;
V_114 = V_109 * V_111 / 8 ;
V_115 = V_114 * V_110 ;
V_113 = F_9 ( V_18 , V_42 ) ;
V_7 = F_37 ( sizeof( * V_9 ) , V_104 ) ;
if ( ! V_7 )
return - V_100 ;
V_18 -> V_6 = V_7 ;
V_9 = V_7 -> V_9 ;
V_9 -> V_18 = V_18 ;
V_9 -> V_12 = V_112 ;
V_9 -> V_13 = V_111 ;
V_9 -> V_118 = NULL ;
V_9 -> V_27 = V_109 ;
V_9 -> V_29 = V_110 ;
V_9 -> V_118 = V_118 ( V_115 ) ;
if ( F_18 ( V_9 -> V_118 == NULL ) ) {
V_30 = - V_100 ;
goto V_119;
}
V_30 = F_31 ( V_18 , V_115 , & V_9 -> V_93 ) ;
if ( F_18 ( V_30 != 0 ) )
goto V_119;
V_30 = F_38 ( & V_9 -> V_93 -> V_120 ,
0 ,
V_9 -> V_93 -> V_120 . V_121 ,
& V_9 -> V_122 ) ;
if ( F_18 ( V_30 != 0 ) )
goto V_123;
V_9 -> V_48 = F_39 ( & V_9 -> V_122 , & V_9 -> V_124 ) ;
V_9 -> V_125 = V_115 ;
strcpy ( V_7 -> V_31 . V_126 , L_8 ) ;
V_7 -> V_31 . type = V_127 ;
V_7 -> V_31 . V_128 = V_129 ;
V_7 -> V_31 . V_130 = 0 ;
V_7 -> V_31 . V_131 = 1 ;
V_7 -> V_31 . V_132 = 1 ;
V_7 -> V_31 . V_133 = 0 ;
V_7 -> V_31 . V_134 = V_135 ;
V_7 -> V_31 . V_32 = V_114 ;
V_7 -> V_31 . V_136 = 0 ;
V_7 -> V_31 . V_66 = V_115 ;
V_7 -> V_11 = V_9 -> V_11 ;
V_7 -> V_46 = V_9 -> V_118 ;
V_7 -> V_137 = V_115 ;
V_7 -> V_49 = V_138 ;
V_7 -> V_139 = & V_140 ;
V_7 -> V_15 . V_2 . V_21 = 16 ;
V_7 -> V_15 . V_3 . V_21 = 8 ;
V_7 -> V_15 . V_4 . V_21 = 0 ;
V_7 -> V_15 . V_2 . V_19 = 8 ;
V_7 -> V_15 . V_3 . V_19 = 8 ;
V_7 -> V_15 . V_4 . V_19 = 8 ;
V_7 -> V_15 . V_5 . V_21 = 0 ;
V_7 -> V_15 . V_5 . V_19 = 0 ;
V_7 -> V_15 . V_141 = V_109 ;
V_7 -> V_15 . V_142 = V_110 ;
V_7 -> V_15 . V_16 = V_9 -> V_13 ;
V_7 -> V_15 . V_24 = 0 ;
V_7 -> V_15 . V_25 = 0 ;
V_7 -> V_15 . V_143 = V_144 ;
V_7 -> V_15 . V_69 = - 1 ;
V_7 -> V_15 . V_68 = - 1 ;
V_7 -> V_15 . V_26 = V_107 ;
V_7 -> V_15 . V_28 = V_108 ;
V_7 -> V_145 = F_40 ( 1 ) ;
if ( ! V_7 -> V_145 ) {
V_30 = - V_100 ;
goto V_146;
}
V_7 -> V_145 -> V_147 [ 0 ] . V_120 = V_18 -> V_148 ;
V_7 -> V_145 -> V_147 [ 0 ] . V_90 = V_18 -> V_149 ;
V_9 -> V_60 . V_63 = V_9 -> V_60 . V_64 = 0 ;
V_9 -> V_60 . y1 = V_9 -> V_60 . V_65 = 0 ;
V_9 -> V_60 . V_62 = true ;
F_41 ( & V_9 -> V_60 . V_61 ) ;
V_7 -> V_150 = & V_151 ;
F_42 ( V_7 ) ;
V_30 = F_43 ( V_7 ) ;
if ( F_18 ( V_30 != 0 ) )
goto V_152;
return 0 ;
V_152:
F_44 ( V_7 ) ;
V_146:
F_45 ( & V_9 -> V_122 ) ;
V_123:
F_46 ( (struct V_153 * * ) & V_9 -> V_93 ) ;
V_119:
F_47 ( V_9 -> V_118 ) ;
F_48 ( V_7 ) ;
V_18 -> V_6 = NULL ;
return V_30 ;
}
int F_49 ( struct V_17 * V_18 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_153 * V_154 ;
if ( ! V_18 -> V_6 )
return 0 ;
V_7 = V_18 -> V_6 ;
V_9 = V_7 -> V_9 ;
V_154 = & V_9 -> V_93 -> V_120 ;
V_9 -> V_93 = NULL ;
F_44 ( V_7 ) ;
F_50 ( V_7 ) ;
F_45 ( & V_9 -> V_122 ) ;
F_46 ( & V_154 ) ;
F_47 ( V_9 -> V_118 ) ;
F_48 ( V_7 ) ;
return 0 ;
}
int F_51 ( struct V_17 * V_18 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
unsigned long V_49 ;
if ( ! V_18 -> V_6 )
return - V_20 ;
V_7 = V_18 -> V_6 ;
V_9 = V_7 -> V_9 ;
F_13 ( & V_9 -> V_60 . V_61 , V_49 ) ;
V_9 -> V_60 . V_62 = false ;
F_14 ( & V_9 -> V_60 . V_61 , V_49 ) ;
F_52 ( & V_7 -> V_70 ) ;
V_9 -> V_48 = NULL ;
F_45 ( & V_9 -> V_122 ) ;
F_53 ( V_18 , V_9 -> V_93 , false ) ;
return 0 ;
}
int F_54 ( struct V_17 * V_18 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
unsigned long V_49 ;
bool V_155 ;
int V_30 ;
if ( ! V_18 -> V_6 )
return - V_20 ;
V_7 = V_18 -> V_6 ;
V_9 = V_7 -> V_9 ;
if ( V_9 -> V_48 != NULL )
return 0 ;
F_55 ( V_18 ) ;
V_30 = F_56 ( V_18 , V_9 -> V_93 , true , false ) ;
if ( F_18 ( V_30 != 0 ) ) {
F_2 ( L_9 ) ;
goto V_156;
}
V_30 = F_38 ( & V_9 -> V_93 -> V_120 ,
0 ,
V_9 -> V_93 -> V_120 . V_121 ,
& V_9 -> V_122 ) ;
F_57 ( V_30 != 0 ) ;
V_9 -> V_48 = F_39 ( & V_9 -> V_122 , & V_155 ) ;
F_13 ( & V_9 -> V_60 . V_61 , V_49 ) ;
V_9 -> V_60 . V_62 = true ;
F_14 ( & V_9 -> V_60 . V_61 , V_49 ) ;
V_156:
F_5 ( V_7 ) ;
F_21 ( V_9 , 0 , 0 , V_7 -> V_15 . V_26 , V_7 -> V_15 . V_28 ) ;
F_22 ( & V_7 -> V_70 , 0 ) ;
return 0 ;
}
