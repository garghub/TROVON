static const struct V_1 * F_1 ( unsigned int V_2 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ )
if ( V_4 [ V_3 ] . V_2 == V_2 )
return V_4 + V_3 ;
return NULL ;
}
int F_3 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_9 * V_10 ,
const struct V_11 * V_12 )
{
int V_13 = 0 ;
F_4 ( V_6 , V_12 , V_10 -> V_14 , V_10 -> V_15 . V_16 ) ;
F_5 ( V_12 -> V_17 , 3 ) ;
F_6 ( V_18 , F_7 ( V_18 ) | ( 1 << V_12 -> V_3 ) ) ;
F_6 ( V_12 -> V_19 , 0x11 ) ;
F_5 ( V_12 -> V_20 , 0x11 ) ;
V_13 = F_7 ( V_21 ) ;
F_5 ( V_21 , V_13 & 0xFFFFFE00 ) ;
return 0 ;
}
int F_8 ( struct V_5 * V_6 , int V_22 , T_1 V_23 )
{
int V_24 = 0 ;
T_1 V_25 ;
const struct V_11 * V_12 = V_6 -> V_26 [ V_22 ] . V_27 ;
V_25 = F_7 ( V_12 -> V_19 ) ;
if ( 0 == ( V_23 & V_25 ) )
return V_24 ;
F_5 ( V_12 -> V_28 , V_23 ) ;
if ( V_23 & ( 1 << 16 ) ) {
F_9 ( L_1 ,
V_6 -> V_29 , V_12 -> V_29 ) ;
F_10 ( V_12 -> V_20 , 0x11 ) ;
F_11 ( V_6 , V_12 ) ;
}
if ( V_23 & V_30 ) {
struct V_7 * V_31 =
& V_6 -> V_26 [ V_12 -> V_3 ] . V_32 ;
struct V_9 * V_10 ;
F_12 ( & V_6 -> V_33 ) ;
if ( ! F_13 ( & V_31 -> V_34 ) ) {
V_10 = F_14 ( V_31 -> V_34 . V_35 ,
struct V_9 , V_36 ) ;
V_10 -> V_37 . V_38 . V_39 = F_15 () ;
V_10 -> V_37 . V_40 = V_31 -> V_41 ++ ;
F_16 ( & V_10 -> V_36 ) ;
F_17 ( & V_10 -> V_37 . V_38 , V_42 ) ;
}
F_18 ( & V_6 -> V_33 ) ;
V_24 ++ ;
}
return V_24 ;
}
static int F_19 ( struct V_43 * V_8 ,
unsigned int * V_44 , unsigned int * V_45 ,
unsigned int V_46 [] , void * V_47 [] )
{
struct V_48 * V_49 = V_8 -> V_50 ;
unsigned V_51 = ( V_49 -> V_52 -> V_53 * V_49 -> V_54 * V_49 -> V_55 ) >> 3 ;
V_47 [ 0 ] = V_49 -> V_6 -> V_56 ;
if ( * V_45 )
return V_46 [ 0 ] < V_51 ? - V_57 : 0 ;
* V_45 = 1 ;
V_46 [ 0 ] = V_51 ;
return 0 ;
}
static int F_20 ( struct V_58 * V_37 )
{
struct V_59 * V_60 = F_21 ( V_37 ) ;
struct V_48 * V_49 = V_37 -> V_43 -> V_50 ;
struct V_5 * V_6 = V_49 -> V_6 ;
struct V_9 * V_10 =
F_22 ( V_60 , struct V_9 , V_37 ) ;
struct V_61 * V_62 = F_23 ( V_37 , 0 ) ;
T_1 V_63 ;
int V_64 = V_65 ;
int V_66 ;
if ( V_49 -> V_67 == V_68 )
V_10 -> V_14 = ( V_49 -> V_52 -> V_53 * V_49 -> V_54 ) >> 3 ;
else
V_10 -> V_14 = ( V_49 -> V_52 -> V_53 >> 3 ) * V_49 -> V_54 ;
if ( F_24 ( V_37 , 0 ) < V_49 -> V_55 * V_10 -> V_14 )
return - V_57 ;
F_25 ( V_37 , 0 , V_49 -> V_55 * V_10 -> V_14 ) ;
V_10 -> V_37 . V_69 = V_49 -> V_69 ;
if ( V_49 -> V_67 == V_68 ) {
V_64 = V_10 -> V_14 ;
} else {
V_64 = V_10 -> V_14 ;
if ( V_49 -> V_70 ) {
if ( V_6 -> V_71 & V_72 )
V_64 = 352 << 1 ;
else
V_64 = V_49 -> V_73 << 1 ;
}
}
switch ( V_49 -> V_69 ) {
case V_74 :
V_66 = F_26 ( V_6 -> V_75 , & V_10 -> V_15 ,
V_62 -> V_76 , 0 , V_77 ,
V_10 -> V_14 , 0 , V_49 -> V_55 ) ;
break;
case V_78 :
V_66 = F_26 ( V_6 -> V_75 , & V_10 -> V_15 ,
V_62 -> V_76 , V_77 , 0 ,
V_10 -> V_14 , 0 , V_49 -> V_55 ) ;
break;
case V_79 :
V_63 = 0 ;
F_27 ( 1 , L_2 ) ;
V_66 = F_26 ( V_6 -> V_75 , & V_10 -> V_15 ,
V_62 -> V_76 , V_63 ,
V_64 , V_64 , V_64 ,
V_49 -> V_55 >> 1 ) ;
break;
case V_80 :
V_66 = F_26 ( V_6 -> V_75 , & V_10 -> V_15 ,
V_62 -> V_76 ,
0 , V_10 -> V_14 * ( V_49 -> V_55 >> 1 ) ,
V_10 -> V_14 , 0 , V_49 -> V_55 >> 1 ) ;
break;
case V_81 :
V_66 = F_26 ( V_6 -> V_75 , & V_10 -> V_15 ,
V_62 -> V_76 ,
V_10 -> V_14 * ( V_49 -> V_55 >> 1 ) , 0 ,
V_10 -> V_14 , 0 , V_49 -> V_55 >> 1 ) ;
break;
default:
F_28 ( 1 ) ;
V_66 = - V_57 ;
break;
}
F_27 ( 2 , L_3 ,
V_10 , V_10 -> V_37 . V_38 . V_82 , V_49 -> V_54 , V_49 -> V_55 ,
V_49 -> V_52 -> V_53 , V_49 -> V_52 -> V_29 ,
( unsigned long ) V_10 -> V_15 . V_16 ) ;
return V_66 ;
}
static void F_29 ( struct V_58 * V_37 )
{
struct V_59 * V_60 = F_21 ( V_37 ) ;
struct V_9 * V_10 =
F_22 ( V_60 , struct V_9 , V_37 ) ;
struct V_48 * V_49 = V_37 -> V_43 -> V_50 ;
struct V_5 * V_6 = V_49 -> V_6 ;
F_30 ( V_6 , V_10 ) ;
}
static void F_31 ( struct V_58 * V_37 )
{
struct V_59 * V_60 = F_21 ( V_37 ) ;
struct V_9 * V_10 =
F_22 ( V_60 , struct V_9 , V_37 ) ;
struct V_48 * V_49 = V_37 -> V_43 -> V_50 ;
struct V_5 * V_6 = V_49 -> V_6 ;
struct V_9 * V_83 ;
struct V_7 * V_8 = & V_6 -> V_26 [ V_49 -> V_84 ] . V_32 ;
V_10 -> V_15 . V_85 [ 1 ] = F_32 ( V_10 -> V_15 . V_16 + 12 ) ;
V_10 -> V_15 . V_86 [ 0 ] = F_32 ( V_87 | V_88 ) ;
V_10 -> V_15 . V_86 [ 1 ] = F_32 ( V_10 -> V_15 . V_16 + 12 ) ;
V_10 -> V_15 . V_86 [ 2 ] = F_32 ( 0 ) ;
if ( F_13 ( & V_8 -> V_34 ) ) {
F_33 ( & V_10 -> V_36 , & V_8 -> V_34 ) ;
} else {
V_10 -> V_15 . V_85 [ 0 ] |= F_32 ( V_89 ) ;
V_83 = F_14 ( V_8 -> V_34 . V_83 , struct V_9 ,
V_36 ) ;
F_33 ( & V_10 -> V_36 , & V_8 -> V_34 ) ;
V_83 -> V_15 . V_86 [ 1 ] = F_32 ( V_10 -> V_15 . V_16 ) ;
}
}
static int F_34 ( struct V_43 * V_8 , unsigned int V_41 )
{
struct V_48 * V_49 = V_8 -> V_50 ;
struct V_5 * V_6 = V_49 -> V_6 ;
struct V_7 * V_31 = & V_6 -> V_26 [ V_49 -> V_84 ] . V_32 ;
struct V_9 * V_10 = F_14 ( V_31 -> V_34 . V_35 ,
struct V_9 , V_36 ) ;
V_31 -> V_41 = 0 ;
F_3 ( V_6 , V_31 , V_10 , V_49 -> V_27 ) ;
return 0 ;
}
static void F_35 ( struct V_43 * V_8 )
{
struct V_48 * V_49 = V_8 -> V_50 ;
struct V_5 * V_6 = V_49 -> V_6 ;
struct V_7 * V_31 = & V_6 -> V_26 [ V_49 -> V_84 ] . V_32 ;
unsigned long V_90 ;
F_5 ( V_49 -> V_27 -> V_20 , 0 ) ;
F_36 ( & V_6 -> V_33 , V_90 ) ;
while ( ! F_13 ( & V_31 -> V_34 ) ) {
struct V_9 * V_10 = F_14 ( V_31 -> V_34 . V_35 ,
struct V_9 , V_36 ) ;
F_16 ( & V_10 -> V_36 ) ;
F_17 ( & V_10 -> V_37 . V_38 , V_91 ) ;
}
F_37 ( & V_6 -> V_33 , V_90 ) ;
}
static int F_38 ( struct V_92 * V_92 , void * V_93 ,
struct V_94 * V_95 )
{
if ( F_39 ( V_95 -> V_82 >= F_2 ( V_4 ) ) )
return - V_57 ;
F_40 ( V_95 -> V_96 , V_4 [ V_95 -> V_82 ] . V_29 , sizeof( V_95 -> V_96 ) ) ;
V_95 -> V_97 = V_4 [ V_95 -> V_82 ] . V_2 ;
return 0 ;
}
static int F_41 ( struct V_92 * V_92 , void * V_93 ,
struct V_98 * V_95 )
{
struct V_48 * V_49 = F_42 ( V_92 ) ;
V_95 -> V_52 . V_99 . V_54 = V_49 -> V_54 ;
V_95 -> V_52 . V_99 . V_55 = V_49 -> V_55 ;
V_95 -> V_52 . V_99 . V_69 = V_49 -> V_69 ;
V_95 -> V_52 . V_99 . V_97 = V_49 -> V_52 -> V_2 ;
V_95 -> V_52 . V_99 . V_100 = ( V_49 -> V_54 * V_49 -> V_52 -> V_53 ) >> 3 ;
V_95 -> V_52 . V_99 . V_101 = V_49 -> V_55 * V_95 -> V_52 . V_99 . V_100 ;
V_95 -> V_52 . V_99 . V_102 = V_103 ;
return 0 ;
}
static int F_43 ( struct V_92 * V_92 , void * V_93 ,
struct V_98 * V_95 )
{
struct V_48 * V_49 = F_42 ( V_92 ) ;
struct V_5 * V_6 = V_49 -> V_6 ;
const struct V_1 * V_52 ;
enum V_104 V_69 = V_95 -> V_52 . V_99 . V_69 ;
unsigned int V_105 ;
unsigned V_106 ;
V_52 = F_1 ( V_95 -> V_52 . V_99 . V_97 ) ;
if ( NULL == V_52 )
return - V_57 ;
V_105 = ( V_6 -> V_71 & V_72 ) ? 576 : 480 ;
V_106 = V_95 -> V_52 . V_99 . V_54 ;
if ( V_69 != V_78 )
V_69 = V_74 ;
if ( V_106 < 352 ) {
V_106 = 176 ;
V_95 -> V_52 . V_99 . V_55 = V_105 / 4 ;
} else if ( V_106 < 720 ) {
V_106 = 352 ;
V_95 -> V_52 . V_99 . V_55 = V_105 / 2 ;
} else {
V_106 = 720 ;
V_95 -> V_52 . V_99 . V_55 = V_105 ;
V_69 = V_79 ;
}
V_95 -> V_52 . V_99 . V_69 = V_69 ;
V_95 -> V_52 . V_99 . V_54 = V_106 ;
V_95 -> V_52 . V_99 . V_100 = ( V_95 -> V_52 . V_99 . V_54 * V_52 -> V_53 ) >> 3 ;
V_95 -> V_52 . V_99 . V_101 = V_95 -> V_52 . V_99 . V_55 * V_95 -> V_52 . V_99 . V_100 ;
V_95 -> V_52 . V_99 . V_102 = V_103 ;
return 0 ;
}
static int F_44 ( struct V_92 * V_92 , void * V_93 ,
struct V_98 * V_95 )
{
struct V_48 * V_49 = F_42 ( V_92 ) ;
struct V_5 * V_6 = V_49 -> V_6 ;
int V_107 = V_108 ;
int V_109 ;
V_109 = F_43 ( V_92 , V_93 , V_95 ) ;
if ( 0 != V_109 )
return V_109 ;
V_49 -> V_52 = F_1 ( V_95 -> V_52 . V_99 . V_97 ) ;
V_49 -> V_69 = V_95 -> V_52 . V_99 . V_69 ;
V_49 -> V_54 = V_95 -> V_52 . V_99 . V_54 ;
V_49 -> V_55 = V_95 -> V_52 . V_99 . V_55 ;
if ( V_95 -> V_52 . V_99 . V_97 == V_110 )
V_107 = V_68 ;
else
V_107 = V_108 ;
F_45 ( V_6 , V_111 , V_107 ) ;
if ( V_49 -> V_54 == 320 || V_49 -> V_54 == 352 )
V_49 -> V_70 = 1 ;
else
V_49 -> V_70 = 0 ;
V_49 -> V_73 = V_49 -> V_54 ;
F_46 ( V_6 , V_49 -> V_54 , V_111 ) ;
return 0 ;
}
static int F_47 ( struct V_92 * V_92 , void * V_93 )
{
struct V_48 * V_49 = F_42 ( V_92 ) ;
struct V_5 * V_6 = V_49 -> V_6 ;
const struct V_11 * V_112 = V_49 -> V_27 ;
T_1 V_13 = 0 ;
V_13 = F_7 ( V_112 -> V_20 ) ;
F_48 ( L_4 ,
( V_13 & 0x11 ) ? L_5 : L_6 ) ;
return 0 ;
}
static int F_49 ( struct V_92 * V_92 , void * V_93 ,
struct V_113 * V_114 )
{
struct V_48 * V_49 = F_42 ( V_92 ) ;
struct V_5 * V_6 = V_49 -> V_6 ;
const T_1 V_115 = V_116 |
V_117 | V_118 ;
const T_1 V_119 = V_120 | V_117 ;
strcpy ( V_114 -> V_121 , L_7 ) ;
F_40 ( V_114 -> V_122 , V_123 [ V_6 -> V_124 ] . V_29 , sizeof( V_114 -> V_122 ) ) ;
sprintf ( V_114 -> V_125 , L_8 , F_50 ( V_6 -> V_75 ) ) ;
if ( V_49 -> V_84 >= V_126 )
V_114 -> V_127 = V_119 ;
else
V_114 -> V_127 = V_115 ;
V_114 -> V_128 = V_115 | V_119 | V_129 ;
return 0 ;
}
static int F_51 ( struct V_92 * V_92 , void * V_93 , T_2 * V_130 )
{
struct V_48 * V_49 = F_42 ( V_92 ) ;
* V_130 = V_49 -> V_6 -> V_71 ;
return 0 ;
}
static int F_52 ( struct V_92 * V_92 , void * V_93 ,
T_2 V_130 )
{
struct V_48 * V_49 = F_42 ( V_92 ) ;
struct V_5 * V_6 = V_49 -> V_6 ;
if ( V_6 -> V_71 == V_130 )
return 0 ;
V_6 -> V_71 = V_130 ;
V_49 -> V_54 = 720 ;
V_49 -> V_55 = ( V_6 -> V_71 & V_72 ) ? 576 : 480 ;
F_53 ( V_6 ) ;
return 0 ;
}
static int F_54 ( struct V_92 * V_92 , void * V_93 ,
struct V_131 * V_3 )
{
if ( V_3 -> V_82 )
return - V_57 ;
V_3 -> type = V_132 ;
V_3 -> V_133 = V_134 ;
strcpy ( V_3 -> V_29 , L_9 ) ;
return 0 ;
}
static int F_55 ( struct V_92 * V_92 , void * V_93 , unsigned int * V_3 )
{
* V_3 = 0 ;
return 0 ;
}
static int F_56 ( struct V_92 * V_92 , void * V_93 , unsigned int V_3 )
{
return V_3 ? - V_57 : 0 ;
}
static int F_57 ( struct V_135 * V_136 )
{
struct V_48 * V_49 =
F_22 ( V_136 -> V_137 , struct V_48 , V_138 ) ;
struct V_5 * V_6 = V_49 -> V_6 ;
switch ( V_136 -> V_84 ) {
case V_139 :
F_58 ( V_6 , V_136 -> V_140 , V_49 -> V_84 ) ;
break;
case V_141 :
F_59 ( V_6 , V_136 -> V_140 , V_49 -> V_84 ) ;
break;
case V_142 :
F_60 ( V_6 , V_136 -> V_140 , V_49 -> V_84 ) ;
break;
case V_143 :
F_61 ( V_6 , V_136 -> V_140 , V_49 -> V_84 ) ;
break;
default:
return - V_57 ;
}
return 0 ;
}
static int F_62 ( struct V_92 * V_92 , void * V_93 ,
struct V_144 * V_145 )
{
if ( V_145 -> V_82 )
return - V_57 ;
V_145 -> type = V_132 ;
V_145 -> V_133 = V_134 ;
strcpy ( V_145 -> V_29 , L_9 ) ;
return 0 ;
}
static int F_63 ( struct V_92 * V_92 , void * V_93 , unsigned int * V_145 )
{
* V_145 = 0 ;
return 0 ;
}
static int F_64 ( struct V_92 * V_92 , void * V_93 , unsigned int V_145 )
{
return V_145 ? - V_57 : 0 ;
}
static int F_65 ( struct V_92 * V_92 , void * V_93 ,
struct V_98 * V_95 )
{
struct V_48 * V_49 = F_42 ( V_92 ) ;
struct V_5 * V_6 = V_49 -> V_6 ;
const struct V_1 * V_52 ;
V_52 = F_1 ( V_95 -> V_52 . V_99 . V_97 ) ;
if ( NULL == V_52 )
return - V_57 ;
V_95 -> V_52 . V_99 . V_54 = 720 ;
V_95 -> V_52 . V_99 . V_55 = ( V_6 -> V_71 & V_72 ) ? 576 : 480 ;
V_95 -> V_52 . V_99 . V_69 = V_79 ;
V_95 -> V_52 . V_99 . V_100 = ( V_95 -> V_52 . V_99 . V_54 * V_52 -> V_53 ) >> 3 ;
V_95 -> V_52 . V_99 . V_101 = V_95 -> V_52 . V_99 . V_55 * V_95 -> V_52 . V_99 . V_100 ;
V_95 -> V_52 . V_99 . V_102 = V_103 ;
return 0 ;
}
static int F_66 ( struct V_92 * V_92 , void * V_93 ,
struct V_98 * V_95 )
{
struct V_48 * V_49 = F_42 ( V_92 ) ;
int V_109 ;
V_109 = F_65 ( V_92 , V_93 , V_95 ) ;
if ( 0 != V_109 )
return V_109 ;
V_49 -> V_52 = F_1 ( V_95 -> V_52 . V_99 . V_97 ) ;
V_49 -> V_69 = V_95 -> V_52 . V_99 . V_69 ;
V_49 -> V_54 = V_95 -> V_52 . V_99 . V_54 ;
V_49 -> V_55 = V_95 -> V_52 . V_99 . V_55 ;
if ( V_95 -> V_52 . V_99 . V_97 == V_110 )
V_49 -> V_67 = V_68 ;
else
V_49 -> V_67 = V_108 ;
return 0 ;
}
void F_67 ( struct V_5 * V_6 , int V_22 )
{
F_10 ( V_18 , 1 ) ;
if ( F_68 ( & V_6 -> V_26 [ V_22 ] . V_146 ) ) {
F_69 ( & V_6 -> V_26 [ V_22 ] . V_146 ) ;
F_70 ( & V_6 -> V_26 [ V_22 ] . V_138 ) ;
}
}
int F_71 ( struct V_5 * V_6 )
{
int V_109 ;
int V_3 ;
V_6 -> V_71 = V_147 ;
F_72 ( & V_6 -> V_33 ) ;
for ( V_3 = 0 ; V_3 < V_148 - 1 ; ++ V_3 ) {
struct V_48 * V_49 = & V_6 -> V_26 [ V_3 ] ;
struct V_149 * V_146 = & V_49 -> V_146 ;
struct V_150 * V_138 = & V_49 -> V_138 ;
struct V_43 * V_8 ;
bool V_151 = V_3 > V_152 ;
if ( V_3 == V_152 )
continue;
if ( ! V_151 ) {
F_73 ( V_138 , 4 ) ;
F_74 ( V_138 , & V_153 ,
V_139 , 0 , 10000 , 1 , 6200 ) ;
F_74 ( V_138 , & V_153 ,
V_142 , 0 , 10000 , 1 , 5000 ) ;
F_74 ( V_138 , & V_153 ,
V_143 , 0 , 10000 , 1 , 5000 ) ;
F_74 ( V_138 , & V_153 ,
V_141 , 0 , 10000 , 1 , 5000 ) ;
if ( V_138 -> error ) {
V_109 = V_138 -> error ;
goto V_154;
}
V_109 = F_75 ( V_138 ) ;
if ( V_109 )
goto V_154;
} else {
V_49 -> V_155 = & V_6 -> V_156 [ V_3 - V_157 ] ;
V_49 -> V_155 -> V_49 = V_49 ;
}
V_49 -> V_27 = & V_158 [ V_3 ] ;
V_49 -> V_54 = 720 ;
V_49 -> V_69 = V_79 ;
if ( V_6 -> V_71 & V_72 )
V_49 -> V_55 = 576 ;
else
V_49 -> V_55 = 480 ;
if ( V_49 -> V_67 == V_68 )
V_49 -> V_52 = F_1 ( V_110 ) ;
else
V_49 -> V_52 = F_1 ( V_159 ) ;
F_5 ( V_49 -> V_27 -> V_28 , 0xffffffff ) ;
F_76 ( & V_49 -> V_32 . V_34 ) ;
V_8 = & V_49 -> V_160 ;
V_8 -> type = V_151 ? V_161 :
V_162 ;
V_8 -> V_163 = V_164 | V_165 | V_166 ;
V_8 -> V_163 |= V_151 ? V_167 : V_168 ;
V_8 -> V_169 = V_170 ;
V_8 -> V_171 = 2 ;
V_8 -> V_50 = V_49 ;
V_8 -> V_172 = sizeof( struct V_9 ) ;
V_8 -> V_173 = & V_174 ;
V_8 -> V_175 = & V_176 ;
V_8 -> V_177 = V_178 ;
V_8 -> V_179 = & V_6 -> V_179 ;
if ( ! V_151 ) {
V_109 = F_77 ( V_8 ) ;
if ( V_109 < 0 )
goto V_154;
}
* V_146 = V_151 ? V_180 : V_181 ;
V_146 -> V_182 = & V_6 -> V_182 ;
if ( ! V_151 )
V_146 -> V_183 = V_138 ;
else
V_146 -> V_184 = V_185 ;
V_146 -> V_179 = & V_6 -> V_179 ;
V_146 -> V_36 = V_8 ;
snprintf ( V_146 -> V_29 , sizeof( V_146 -> V_29 ) , L_10 , V_6 -> V_29 , V_3 ) ;
F_78 ( V_146 , V_49 ) ;
V_109 = F_79 ( V_146 , V_186 ,
V_187 [ V_6 -> V_188 ] ) ;
if ( V_109 < 0 )
goto V_154;
}
F_6 ( V_18 , 0xff ) ;
return 0 ;
V_154:
while ( V_3 >= 0 )
F_67 ( V_6 , V_3 -- ) ;
return V_109 ;
}
