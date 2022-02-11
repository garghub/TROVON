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
switch ( V_9 -> V_12 -> V_13 -> V_14 ) {
case 24 :
case 32 :
V_10 [ V_1 ] = ( ( V_2 & 0xff00 ) << 8 ) |
( V_3 & 0xff00 ) |
( ( V_4 & 0xff00 ) >> 8 ) ;
break;
default:
F_2 ( L_2 ,
V_9 -> V_12 -> V_13 -> V_14 ,
V_9 -> V_12 -> V_13 -> V_15 [ 0 ] * 8 ) ;
return 1 ;
}
return 0 ;
}
static int F_3 ( struct V_16 * V_17 ,
struct V_6 * V_7 )
{
int V_14 = V_17 -> V_18 ;
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_19 * V_20 = V_9 -> V_20 ;
switch ( V_17 -> V_18 ) {
case 32 :
V_14 = ( V_17 -> V_5 . V_21 > 0 ) ? 32 : 24 ;
break;
default:
F_2 ( L_3 , V_17 -> V_18 ) ;
return - V_22 ;
}
switch ( V_14 ) {
case 24 :
V_17 -> V_2 . V_23 = 16 ;
V_17 -> V_3 . V_23 = 8 ;
V_17 -> V_4 . V_23 = 0 ;
V_17 -> V_2 . V_21 = 8 ;
V_17 -> V_3 . V_21 = 8 ;
V_17 -> V_4 . V_21 = 8 ;
V_17 -> V_5 . V_21 = 0 ;
V_17 -> V_5 . V_23 = 0 ;
break;
case 32 :
V_17 -> V_2 . V_23 = 16 ;
V_17 -> V_3 . V_23 = 8 ;
V_17 -> V_4 . V_23 = 0 ;
V_17 -> V_2 . V_21 = 8 ;
V_17 -> V_3 . V_21 = 8 ;
V_17 -> V_4 . V_21 = 8 ;
V_17 -> V_5 . V_21 = 8 ;
V_17 -> V_5 . V_23 = 24 ;
break;
default:
F_2 ( L_4 , V_14 ) ;
return - V_22 ;
}
if ( ( V_17 -> V_24 + V_17 -> V_25 ) > V_9 -> V_26 ||
( V_17 -> V_27 + V_17 -> V_28 ) > V_9 -> V_29 ) {
F_2 ( L_5 ) ;
return - V_22 ;
}
if ( ! F_4 ( V_20 ,
V_17 -> V_25 * V_17 -> V_18 / 8 ,
V_17 -> V_27 + V_17 -> V_28 ) ) {
F_2 ( L_5 ) ;
return - V_22 ;
}
return 0 ;
}
static int F_5 ( int V_30 , struct V_6 * V_7 )
{
return 0 ;
}
static void F_6 ( struct V_31 * V_32 )
{
struct V_8 * V_9 = F_7 ( V_32 , struct V_8 ,
V_33 . V_32 ) ;
struct V_19 * V_20 = V_9 -> V_20 ;
struct V_6 * V_7 = V_20 -> V_6 ;
unsigned long V_34 ;
T_2 V_35 , V_36 , V_37 , V_38 , V_39 , V_40 ;
T_1 V_15 , V_41 , V_42 ;
struct V_43 V_44 ;
struct V_45 * V_46 ;
T_3 * V_47 , * V_48 ;
if ( V_20 -> V_49 )
return;
F_8 ( & V_9 -> V_50 ) ;
V_46 = V_9 -> V_12 ;
if ( ! V_46 )
goto V_51;
F_9 ( & V_9 -> V_52 . V_53 , V_34 ) ;
if ( ! V_9 -> V_52 . V_54 ) {
F_10 ( & V_9 -> V_52 . V_53 , V_34 ) ;
goto V_51;
}
V_15 = V_46 -> V_13 -> V_15 [ 0 ] ;
V_41 = V_9 -> V_55 + V_46 -> V_56 ;
V_42 = V_9 -> V_57 + V_46 -> V_58 ;
V_35 = V_9 -> V_52 . V_59 - V_9 -> V_55 ;
V_37 = V_9 -> V_52 . y1 - V_9 -> V_57 ;
V_35 = F_11 ( T_2 , V_35 , 0 ) ;
V_37 = F_11 ( T_2 , V_37 , 0 ) ;
V_36 = V_9 -> V_52 . V_60 - V_9 -> V_55 ;
V_38 = V_9 -> V_52 . V_61 - V_9 -> V_57 ;
V_36 = F_12 ( T_2 , V_36 , V_41 ) ;
V_38 = F_12 ( T_2 , V_38 , V_42 ) ;
V_39 = V_36 - V_35 ;
V_40 = V_38 - V_37 ;
V_39 = F_11 ( T_2 , 0 , V_39 ) ;
V_40 = F_11 ( T_2 , 0 , V_40 ) ;
V_9 -> V_52 . V_59 = V_9 -> V_52 . V_60 = 0 ;
V_9 -> V_52 . y1 = V_9 -> V_52 . V_61 = 0 ;
F_10 ( & V_9 -> V_52 . V_53 , V_34 ) ;
if ( V_39 && V_40 ) {
V_48 = ( T_3 * ) V_9 -> V_62 +
( V_37 * V_9 -> V_12 -> V_63 [ 0 ] + V_35 * V_15 ) ;
V_47 = ( T_3 * ) V_9 -> V_64 +
( ( V_37 + V_9 -> V_57 ) * V_7 -> V_65 . V_66 +
( V_35 + V_9 -> V_55 ) * V_15 ) ;
while ( V_40 -- > 0 ) {
memcpy ( V_48 , V_47 , V_39 * V_15 ) ;
V_48 += V_9 -> V_12 -> V_63 [ 0 ] ;
V_47 += V_7 -> V_65 . V_66 ;
}
V_44 . V_59 = V_35 ;
V_44 . V_60 = V_36 ;
V_44 . y1 = V_37 ;
V_44 . V_61 = V_38 ;
F_13 ( V_9 -> V_12 -> V_67 -> V_52 ( V_46 , NULL , 0 , 0 ,
& V_44 , 1 ) ) ;
F_14 ( V_20 , false ) ;
}
V_51:
F_15 ( & V_9 -> V_50 ) ;
}
static void F_16 ( struct V_8 * V_9 ,
unsigned V_59 , unsigned y1 ,
unsigned V_56 , unsigned V_58 )
{
unsigned long V_68 ;
unsigned V_60 = V_59 + V_56 ;
unsigned V_61 = y1 + V_58 ;
F_9 ( & V_9 -> V_52 . V_53 , V_68 ) ;
if ( V_9 -> V_52 . V_59 == V_9 -> V_52 . V_60 ) {
V_9 -> V_52 . V_59 = V_59 ;
V_9 -> V_52 . y1 = y1 ;
V_9 -> V_52 . V_60 = V_60 ;
V_9 -> V_52 . V_61 = V_61 ;
if ( V_9 -> V_52 . V_54 )
F_17 ( & V_9 -> V_33 ,
V_69 ) ;
} else {
if ( V_59 < V_9 -> V_52 . V_59 )
V_9 -> V_52 . V_59 = V_59 ;
if ( y1 < V_9 -> V_52 . y1 )
V_9 -> V_52 . y1 = y1 ;
if ( V_60 > V_9 -> V_52 . V_60 )
V_9 -> V_52 . V_60 = V_60 ;
if ( V_61 > V_9 -> V_52 . V_61 )
V_9 -> V_52 . V_61 = V_61 ;
}
F_10 ( & V_9 -> V_52 . V_53 , V_68 ) ;
}
static int F_18 ( struct V_16 * V_17 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
if ( ( V_17 -> V_24 + V_17 -> V_25 ) > V_17 -> V_70 ||
( V_17 -> V_27 + V_17 -> V_28 ) > V_17 -> V_71 ) {
F_2 ( L_6 ) ;
return - V_22 ;
}
F_8 ( & V_9 -> V_50 ) ;
V_9 -> V_55 = V_17 -> V_24 ;
V_9 -> V_57 = V_17 -> V_27 ;
if ( V_9 -> V_12 )
F_16 ( V_9 , V_9 -> V_55 , V_9 -> V_57 , V_9 -> V_12 -> V_56 ,
V_9 -> V_12 -> V_58 ) ;
F_15 ( & V_9 -> V_50 ) ;
return 0 ;
}
static void F_19 ( struct V_6 * V_7 ,
struct V_72 * V_73 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
unsigned long V_74 , V_75 , V_76 , V_77 ;
unsigned long V_68 ;
struct V_78 * V_78 ;
int y1 , V_61 ;
V_76 = V_79 ;
V_77 = 0 ;
F_20 (page, pagelist, lru) {
V_74 = V_78 -> V_80 << V_81 ;
V_75 = V_74 + V_82 - 1 ;
V_76 = V_76 ( V_76 , V_74 ) ;
V_77 = V_77 ( V_77 , V_75 ) ;
}
if ( V_76 < V_77 ) {
y1 = V_76 / V_7 -> V_65 . V_66 ;
V_61 = ( V_77 / V_7 -> V_65 . V_66 ) + 1 ;
F_9 ( & V_9 -> V_52 . V_53 , V_68 ) ;
V_9 -> V_52 . V_59 = 0 ;
V_9 -> V_52 . y1 = y1 ;
V_9 -> V_52 . V_60 = V_7 -> V_17 . V_25 ;
V_9 -> V_52 . V_61 = V_61 ;
F_10 ( & V_9 -> V_52 . V_53 , V_68 ) ;
F_21 ( & V_9 -> V_33 ) ;
F_17 ( & V_9 -> V_33 , 0 ) ;
}
}
static void F_22 ( struct V_6 * V_7 , const struct V_83 * V_84 )
{
F_23 ( V_7 , V_84 ) ;
F_16 ( V_7 -> V_9 , V_84 -> V_85 , V_84 -> V_86 ,
V_84 -> V_56 , V_84 -> V_58 ) ;
}
static void F_24 ( struct V_6 * V_7 , const struct V_87 * V_88 )
{
F_25 ( V_7 , V_88 ) ;
F_16 ( V_7 -> V_9 , V_88 -> V_85 , V_88 -> V_86 ,
V_88 -> V_56 , V_88 -> V_58 ) ;
}
static void F_26 ( struct V_6 * V_7 , const struct V_89 * V_90 )
{
F_27 ( V_7 , V_90 ) ;
F_16 ( V_7 -> V_9 , V_90 -> V_85 , V_90 -> V_86 ,
V_90 -> V_56 , V_90 -> V_58 ) ;
}
static int F_28 ( struct V_19 * V_20 ,
T_4 V_91 , struct V_92 * * V_93 )
{
struct V_92 * V_94 ;
int V_95 ;
( void ) F_29 ( & V_20 -> V_96 , false ) ;
V_94 = F_30 ( sizeof( * V_94 ) , V_97 ) ;
if ( ! V_94 ) {
V_95 = - V_98 ;
goto V_99;
}
V_95 = F_31 ( V_20 , V_94 , V_91 ,
& V_100 ,
false ,
& V_101 ) ;
if ( F_32 ( V_95 != 0 ) )
goto V_99;
* V_93 = V_94 ;
F_33 ( & V_20 -> V_96 ) ;
return 0 ;
V_99:
F_33 ( & V_20 -> V_96 ) ;
return V_95 ;
}
static int F_34 ( struct V_16 * V_17 ,
int * V_14 )
{
switch ( V_17 -> V_18 ) {
case 32 :
* V_14 = ( V_17 -> V_5 . V_21 > 0 ) ? 32 : 24 ;
break;
default:
F_2 ( L_3 , V_17 -> V_18 ) ;
return - V_22 ;
}
return 0 ;
}
static int F_35 ( struct V_8 * V_9 ,
bool V_102 ,
bool V_103 )
{
struct V_45 * V_46 = V_9 -> V_12 ;
int V_95 ;
if ( V_9 -> V_104 ) {
struct V_105 V_106 ;
V_106 . V_107 = V_9 -> V_107 ;
V_106 . V_108 = 0 ;
V_106 . V_109 = 0 ;
V_106 . V_110 = NULL ;
V_106 . V_111 = NULL ;
V_106 . V_112 = 1 ;
V_106 . V_113 = & V_9 -> V_114 ;
V_95 = F_36 ( & V_106 ) ;
if ( V_95 ) {
F_2 ( L_7 ) ;
return V_95 ;
}
F_37 ( V_9 -> V_20 -> V_115 , V_9 -> V_104 ) ;
V_9 -> V_104 = NULL ;
}
if ( V_46 ) {
F_38 ( V_46 ) ;
V_9 -> V_12 = NULL ;
}
if ( V_9 -> V_94 && V_102 ) {
if ( V_9 -> V_62 ) {
F_39 ( & V_9 -> V_116 ) ;
V_9 -> V_62 = NULL ;
}
if ( V_103 )
F_40 ( & V_9 -> V_94 ) ;
else
F_41 ( V_9 -> V_20 , V_9 -> V_94 , false ) ;
}
return 0 ;
}
static int F_42 ( struct V_6 * V_7 )
{
struct V_117 V_118 ;
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_16 * V_17 = & V_7 -> V_17 ;
struct V_45 * V_46 ;
struct V_119 * V_120 ;
int V_95 = 0 , V_14 ;
T_4 V_121 ;
V_95 = F_34 ( V_17 , & V_14 ) ;
if ( V_95 )
return V_95 ;
V_118 . V_56 = V_17 -> V_25 ;
V_118 . V_58 = V_17 -> V_28 ;
V_118 . V_63 [ 0 ] = ( ( V_17 -> V_18 + 7 ) / 8 ) * V_118 . V_56 ;
V_118 . V_122 =
F_43 ( V_17 -> V_18 , V_14 ) ;
V_46 = V_9 -> V_12 ;
if ( V_46 && V_46 -> V_56 == V_118 . V_56 &&
V_46 -> V_58 == V_118 . V_58 &&
V_46 -> V_13 -> V_13 == V_118 . V_122 &&
V_46 -> V_63 [ 0 ] == V_118 . V_63 [ 0 ] )
return 0 ;
V_121 = ( T_4 ) V_118 . V_63 [ 0 ] * ( T_4 ) V_118 . V_58 ;
V_95 = F_35 ( V_9 ,
V_9 -> V_123 < V_121 ||
V_9 -> V_123 > 2 * V_121 ,
true ) ;
if ( V_95 )
return V_95 ;
if ( ! V_9 -> V_94 ) {
V_95 = F_28 ( V_9 -> V_20 , V_121 ,
& V_9 -> V_94 ) ;
if ( V_95 ) {
F_2 ( L_8
L_9 ) ;
return V_95 ;
}
V_9 -> V_123 = V_121 ;
}
V_120 = F_44 ( V_9 -> V_20 , V_9 -> V_94 , NULL ,
true , & V_118 ) ;
if ( F_45 ( V_120 ) )
return F_46 ( V_120 ) ;
V_9 -> V_12 = & V_120 -> V_124 ;
return 0 ;
}
static int F_47 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_19 * V_20 = V_9 -> V_20 ;
struct V_105 V_106 ;
struct V_16 * V_17 = & V_7 -> V_17 ;
struct V_125 V_126 = { F_48 ( L_10 ,
DRM_MODE_TYPE_DRIVER,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_PVSYNC)
} ;
struct V_125 * V_127 ;
struct V_125 * V_110 ;
int V_95 ;
V_127 = V_9 -> V_104 ;
V_110 = F_49 ( V_20 -> V_115 , & V_126 ) ;
if ( ! V_110 ) {
F_2 ( L_11 ) ;
return - V_98 ;
}
V_110 -> V_128 = V_17 -> V_25 ;
V_110 -> V_129 = V_17 -> V_28 ;
F_50 ( V_110 ) ;
if ( V_127 && F_51 ( V_127 , V_110 ) ) {
F_37 ( V_20 -> V_115 , V_110 ) ;
V_110 = V_127 ;
V_127 = NULL ;
} else if ( ! F_4 ( V_20 ,
V_110 -> V_128 *
F_52 ( V_17 -> V_18 , 8 ) ,
V_110 -> V_129 ) ) {
F_37 ( V_20 -> V_115 , V_110 ) ;
return - V_22 ;
}
F_8 ( & V_9 -> V_50 ) ;
F_53 ( V_20 -> V_115 ) ;
V_95 = F_42 ( V_7 ) ;
if ( V_95 )
goto V_51;
V_9 -> V_55 = V_17 -> V_24 ;
V_9 -> V_57 = V_17 -> V_27 ;
V_106 . V_107 = V_9 -> V_107 ;
V_106 . V_108 = 0 ;
V_106 . V_109 = 0 ;
V_106 . V_110 = V_110 ;
V_106 . V_111 = V_9 -> V_12 ;
V_106 . V_112 = 1 ;
V_106 . V_113 = & V_9 -> V_114 ;
V_95 = F_36 ( & V_106 ) ;
if ( V_95 )
goto V_51;
if ( ! V_9 -> V_62 ) {
struct V_119 * V_120 = F_54 ( V_106 . V_111 ) ;
V_95 = V_120 -> V_130 ( V_120 ) ;
if ( V_95 ) {
F_2 ( L_12 ) ;
goto V_51;
}
V_95 = F_55 ( & V_9 -> V_94 -> V_124 , 0 ,
V_9 -> V_94 -> V_124 . V_131 , & V_9 -> V_116 ) ;
if ( V_95 ) {
V_120 -> V_132 ( V_120 ) ;
F_2 ( L_13 ) ;
goto V_51;
}
V_9 -> V_62 = F_56 ( & V_9 -> V_116 , & V_9 -> V_133 ) ;
}
F_16 ( V_9 , V_9 -> V_55 , V_9 -> V_57 ,
V_9 -> V_12 -> V_56 , V_9 -> V_12 -> V_58 ) ;
F_17 ( & V_9 -> V_33 , 0 ) ;
V_51:
if ( V_127 )
F_37 ( V_20 -> V_115 , V_127 ) ;
V_9 -> V_104 = V_110 ;
F_57 ( V_20 -> V_115 ) ;
F_15 ( & V_9 -> V_50 ) ;
return V_95 ;
}
int F_58 ( struct V_19 * V_20 )
{
struct V_134 * V_134 = & V_20 -> V_115 -> V_135 -> V_115 ;
struct V_8 * V_9 ;
struct V_6 * V_7 ;
unsigned V_136 , V_137 ;
unsigned V_138 , V_139 , V_140 , V_141 , V_142 ;
struct V_125 * V_143 ;
int V_95 ;
V_138 = 32 ;
V_139 = 24 ;
V_136 = V_76 ( V_20 -> V_144 , ( unsigned ) 2048 ) ;
V_137 = V_76 ( V_20 -> V_145 , ( unsigned ) 2048 ) ;
V_141 = V_136 * V_138 / 8 ;
V_142 = V_141 * V_137 ;
V_140 = F_59 ( V_20 , V_146 ) ;
V_7 = F_60 ( sizeof( * V_9 ) , V_134 ) ;
if ( ! V_7 )
return - V_98 ;
V_20 -> V_6 = V_7 ;
V_9 = V_7 -> V_9 ;
memset ( V_9 , 0 , sizeof( * V_9 ) ) ;
F_61 ( & V_9 -> V_33 , & F_6 ) ;
V_9 -> V_20 = V_20 ;
V_9 -> V_64 = NULL ;
V_9 -> V_26 = V_136 ;
V_9 -> V_29 = V_137 ;
F_53 ( V_20 -> V_115 ) ;
V_95 = F_62 ( V_20 , 0 , V_9 -> V_26 ,
V_9 -> V_29 , & V_9 -> V_114 ,
& V_9 -> V_107 , & V_143 ) ;
if ( V_95 ) {
F_57 ( V_20 -> V_115 ) ;
goto V_147;
}
V_7 -> V_17 . V_25 = V_143 -> V_128 ;
V_7 -> V_17 . V_28 = V_143 -> V_129 ;
F_57 ( V_20 -> V_115 ) ;
V_9 -> V_64 = F_63 ( V_142 ) ;
if ( F_32 ( V_9 -> V_64 == NULL ) ) {
V_95 = - V_98 ;
goto V_148;
}
strcpy ( V_7 -> V_65 . V_149 , L_14 ) ;
V_7 -> V_65 . type = V_150 ;
V_7 -> V_65 . V_151 = V_152 ;
V_7 -> V_65 . V_153 = 0 ;
V_7 -> V_65 . V_154 = 1 ;
V_7 -> V_65 . V_155 = 1 ;
V_7 -> V_65 . V_156 = 0 ;
V_7 -> V_65 . V_157 = V_158 ;
V_7 -> V_65 . V_66 = V_141 ;
V_7 -> V_65 . V_159 = 0 ;
V_7 -> V_65 . V_160 = V_142 ;
V_7 -> V_11 = V_9 -> V_11 ;
V_7 -> V_161 = ( char V_162 * ) V_9 -> V_64 ;
V_7 -> V_163 = V_142 ;
V_7 -> V_68 = V_164 ;
V_7 -> V_165 = & V_166 ;
V_7 -> V_17 . V_2 . V_23 = 16 ;
V_7 -> V_17 . V_3 . V_23 = 8 ;
V_7 -> V_17 . V_4 . V_23 = 0 ;
V_7 -> V_17 . V_2 . V_21 = 8 ;
V_7 -> V_17 . V_3 . V_21 = 8 ;
V_7 -> V_17 . V_4 . V_21 = 8 ;
V_7 -> V_17 . V_5 . V_23 = 0 ;
V_7 -> V_17 . V_5 . V_21 = 0 ;
V_7 -> V_17 . V_70 = V_136 ;
V_7 -> V_17 . V_71 = V_137 ;
V_7 -> V_17 . V_18 = V_138 ;
V_7 -> V_17 . V_24 = 0 ;
V_7 -> V_17 . V_27 = 0 ;
V_7 -> V_17 . V_167 = V_168 ;
V_7 -> V_17 . V_58 = - 1 ;
V_7 -> V_17 . V_56 = - 1 ;
V_7 -> V_169 = F_64 ( 1 ) ;
if ( ! V_7 -> V_169 ) {
V_95 = - V_98 ;
goto V_170;
}
V_7 -> V_169 -> V_171 [ 0 ] . V_124 = V_20 -> V_172 ;
V_7 -> V_169 -> V_171 [ 0 ] . V_91 = V_20 -> V_173 ;
V_9 -> V_52 . V_59 = V_9 -> V_52 . V_60 = 0 ;
V_9 -> V_52 . y1 = V_9 -> V_52 . V_61 = 0 ;
V_9 -> V_52 . V_54 = true ;
F_65 ( & V_9 -> V_52 . V_53 ) ;
F_66 ( & V_9 -> V_50 ) ;
V_7 -> V_174 = & V_175 ;
F_67 ( V_7 ) ;
V_95 = F_68 ( V_7 ) ;
if ( F_32 ( V_95 != 0 ) )
goto V_176;
F_47 ( V_7 ) ;
return 0 ;
V_176:
F_69 ( V_7 ) ;
V_170:
V_148:
F_70 ( V_9 -> V_64 ) ;
V_147:
F_71 ( V_7 ) ;
V_20 -> V_6 = NULL ;
return V_95 ;
}
int F_72 ( struct V_19 * V_20 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
if ( ! V_20 -> V_6 )
return 0 ;
V_7 = V_20 -> V_6 ;
V_9 = V_7 -> V_9 ;
F_69 ( V_7 ) ;
F_73 ( & V_9 -> V_33 ) ;
F_74 ( V_7 ) ;
( void ) F_35 ( V_9 , true , true ) ;
F_70 ( V_9 -> V_64 ) ;
F_71 ( V_7 ) ;
return 0 ;
}
int F_75 ( struct V_19 * V_20 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
unsigned long V_68 ;
if ( ! V_20 -> V_6 )
return - V_22 ;
V_7 = V_20 -> V_6 ;
V_9 = V_7 -> V_9 ;
F_9 ( & V_9 -> V_52 . V_53 , V_68 ) ;
V_9 -> V_52 . V_54 = false ;
F_10 ( & V_9 -> V_52 . V_53 , V_68 ) ;
F_76 ( & V_7 -> V_177 ) ;
F_76 ( & V_9 -> V_33 ) ;
F_8 ( & V_9 -> V_50 ) ;
( void ) F_35 ( V_9 , true , false ) ;
F_15 ( & V_9 -> V_50 ) ;
return 0 ;
}
int F_77 ( struct V_19 * V_20 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
unsigned long V_68 ;
if ( ! V_20 -> V_6 )
return - V_22 ;
V_7 = V_20 -> V_6 ;
V_9 = V_7 -> V_9 ;
F_47 ( V_7 ) ;
F_9 ( & V_9 -> V_52 . V_53 , V_68 ) ;
V_9 -> V_52 . V_54 = true ;
F_10 ( & V_9 -> V_52 . V_53 , V_68 ) ;
return 0 ;
}
