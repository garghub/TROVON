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
F_15 ( & V_10 -> V_37 . V_38 ) ;
V_10 -> V_37 . V_39 = V_31 -> V_40 ++ ;
F_16 ( & V_10 -> V_36 ) ;
F_17 ( & V_10 -> V_37 . V_41 , V_42 ) ;
}
F_18 ( & V_6 -> V_33 ) ;
V_24 ++ ;
}
return V_24 ;
}
static int F_19 ( struct V_43 * V_8 , const void * V_44 ,
unsigned int * V_45 , unsigned int * V_46 ,
unsigned int V_47 [] , void * V_48 [] )
{
const struct V_49 * V_50 = V_44 ;
struct V_51 * V_52 = V_8 -> V_53 ;
unsigned V_54 = ( V_52 -> V_50 -> V_55 * V_52 -> V_56 * V_52 -> V_57 ) >> 3 ;
if ( V_50 && V_50 -> V_50 . V_58 . V_59 < V_54 )
return - V_60 ;
* V_46 = 1 ;
V_47 [ 0 ] = V_50 ? V_50 -> V_50 . V_58 . V_59 : V_54 ;
V_48 [ 0 ] = V_52 -> V_6 -> V_61 ;
return 0 ;
}
static int F_20 ( struct V_62 * V_37 )
{
struct V_63 * V_64 = F_21 ( V_37 ) ;
struct V_51 * V_52 = V_37 -> V_43 -> V_53 ;
struct V_5 * V_6 = V_52 -> V_6 ;
struct V_9 * V_10 =
F_22 ( V_64 , struct V_9 , V_37 ) ;
struct V_65 * V_66 = F_23 ( V_37 , 0 ) ;
T_1 V_67 ;
int V_68 = V_69 ;
int V_70 ;
if ( V_52 -> V_71 == V_72 )
V_10 -> V_14 = ( V_52 -> V_50 -> V_55 * V_52 -> V_56 ) >> 3 ;
else
V_10 -> V_14 = ( V_52 -> V_50 -> V_55 >> 3 ) * V_52 -> V_56 ;
if ( F_24 ( V_37 , 0 ) < V_52 -> V_57 * V_10 -> V_14 )
return - V_60 ;
F_25 ( V_37 , 0 , V_52 -> V_57 * V_10 -> V_14 ) ;
V_10 -> V_37 . V_73 = V_52 -> V_73 ;
if ( V_52 -> V_71 == V_72 ) {
V_68 = V_10 -> V_14 ;
} else {
V_68 = V_10 -> V_14 ;
if ( V_52 -> V_74 ) {
if ( V_6 -> V_75 & V_76 )
V_68 = 352 << 1 ;
else
V_68 = V_52 -> V_77 << 1 ;
}
}
switch ( V_52 -> V_73 ) {
case V_78 :
V_70 = F_26 ( V_6 -> V_79 , & V_10 -> V_15 ,
V_66 -> V_80 , 0 , V_81 ,
V_10 -> V_14 , 0 , V_52 -> V_57 ) ;
break;
case V_82 :
V_70 = F_26 ( V_6 -> V_79 , & V_10 -> V_15 ,
V_66 -> V_80 , V_81 , 0 ,
V_10 -> V_14 , 0 , V_52 -> V_57 ) ;
break;
case V_83 :
V_67 = 0 ;
F_27 ( 1 , L_2 ) ;
V_70 = F_26 ( V_6 -> V_79 , & V_10 -> V_15 ,
V_66 -> V_80 , V_67 ,
V_68 , V_68 , V_68 ,
V_52 -> V_57 >> 1 ) ;
break;
case V_84 :
V_70 = F_26 ( V_6 -> V_79 , & V_10 -> V_15 ,
V_66 -> V_80 ,
0 , V_10 -> V_14 * ( V_52 -> V_57 >> 1 ) ,
V_10 -> V_14 , 0 , V_52 -> V_57 >> 1 ) ;
break;
case V_85 :
V_70 = F_26 ( V_6 -> V_79 , & V_10 -> V_15 ,
V_66 -> V_80 ,
V_10 -> V_14 * ( V_52 -> V_57 >> 1 ) , 0 ,
V_10 -> V_14 , 0 , V_52 -> V_57 >> 1 ) ;
break;
default:
F_28 ( 1 ) ;
V_70 = - V_60 ;
break;
}
F_27 ( 2 , L_3 ,
V_10 , V_10 -> V_37 . V_41 . V_86 , V_52 -> V_56 , V_52 -> V_57 ,
V_52 -> V_50 -> V_55 , V_52 -> V_50 -> V_29 ,
( unsigned long ) V_10 -> V_15 . V_16 ) ;
return V_70 ;
}
static void F_29 ( struct V_62 * V_37 )
{
struct V_63 * V_64 = F_21 ( V_37 ) ;
struct V_9 * V_10 =
F_22 ( V_64 , struct V_9 , V_37 ) ;
struct V_51 * V_52 = V_37 -> V_43 -> V_53 ;
struct V_5 * V_6 = V_52 -> V_6 ;
F_30 ( V_6 , V_10 ) ;
}
static void F_31 ( struct V_62 * V_37 )
{
struct V_63 * V_64 = F_21 ( V_37 ) ;
struct V_9 * V_10 =
F_22 ( V_64 , struct V_9 , V_37 ) ;
struct V_51 * V_52 = V_37 -> V_43 -> V_53 ;
struct V_5 * V_6 = V_52 -> V_6 ;
struct V_9 * V_87 ;
struct V_7 * V_8 = & V_6 -> V_26 [ V_52 -> V_88 ] . V_32 ;
V_10 -> V_15 . V_89 [ 1 ] = F_32 ( V_10 -> V_15 . V_16 + 12 ) ;
V_10 -> V_15 . V_90 [ 0 ] = F_32 ( V_91 | V_92 ) ;
V_10 -> V_15 . V_90 [ 1 ] = F_32 ( V_10 -> V_15 . V_16 + 12 ) ;
V_10 -> V_15 . V_90 [ 2 ] = F_32 ( 0 ) ;
if ( F_13 ( & V_8 -> V_34 ) ) {
F_33 ( & V_10 -> V_36 , & V_8 -> V_34 ) ;
} else {
V_10 -> V_15 . V_89 [ 0 ] |= F_32 ( V_93 ) ;
V_87 = F_14 ( V_8 -> V_34 . V_87 , struct V_9 ,
V_36 ) ;
F_33 ( & V_10 -> V_36 , & V_8 -> V_34 ) ;
V_87 -> V_15 . V_90 [ 1 ] = F_32 ( V_10 -> V_15 . V_16 ) ;
}
}
static int F_34 ( struct V_43 * V_8 , unsigned int V_40 )
{
struct V_51 * V_52 = V_8 -> V_53 ;
struct V_5 * V_6 = V_52 -> V_6 ;
struct V_7 * V_31 = & V_6 -> V_26 [ V_52 -> V_88 ] . V_32 ;
struct V_9 * V_10 = F_14 ( V_31 -> V_34 . V_35 ,
struct V_9 , V_36 ) ;
V_31 -> V_40 = 0 ;
F_3 ( V_6 , V_31 , V_10 , V_52 -> V_27 ) ;
return 0 ;
}
static void F_35 ( struct V_43 * V_8 )
{
struct V_51 * V_52 = V_8 -> V_53 ;
struct V_5 * V_6 = V_52 -> V_6 ;
struct V_7 * V_31 = & V_6 -> V_26 [ V_52 -> V_88 ] . V_32 ;
unsigned long V_94 ;
F_5 ( V_52 -> V_27 -> V_20 , 0 ) ;
F_36 ( & V_6 -> V_33 , V_94 ) ;
while ( ! F_13 ( & V_31 -> V_34 ) ) {
struct V_9 * V_10 = F_14 ( V_31 -> V_34 . V_35 ,
struct V_9 , V_36 ) ;
F_16 ( & V_10 -> V_36 ) ;
F_17 ( & V_10 -> V_37 . V_41 , V_95 ) ;
}
F_37 ( & V_6 -> V_33 , V_94 ) ;
}
static int F_38 ( struct V_96 * V_96 , void * V_97 ,
struct V_98 * V_99 )
{
if ( F_39 ( V_99 -> V_86 >= F_2 ( V_4 ) ) )
return - V_60 ;
F_40 ( V_99 -> V_100 , V_4 [ V_99 -> V_86 ] . V_29 , sizeof( V_99 -> V_100 ) ) ;
V_99 -> V_101 = V_4 [ V_99 -> V_86 ] . V_2 ;
return 0 ;
}
static int F_41 ( struct V_96 * V_96 , void * V_97 ,
struct V_49 * V_99 )
{
struct V_51 * V_52 = F_42 ( V_96 ) ;
V_99 -> V_50 . V_58 . V_56 = V_52 -> V_56 ;
V_99 -> V_50 . V_58 . V_57 = V_52 -> V_57 ;
V_99 -> V_50 . V_58 . V_73 = V_52 -> V_73 ;
V_99 -> V_50 . V_58 . V_101 = V_52 -> V_50 -> V_2 ;
V_99 -> V_50 . V_58 . V_102 = ( V_52 -> V_56 * V_52 -> V_50 -> V_55 ) >> 3 ;
V_99 -> V_50 . V_58 . V_59 = V_52 -> V_57 * V_99 -> V_50 . V_58 . V_102 ;
V_99 -> V_50 . V_58 . V_103 = V_104 ;
return 0 ;
}
static int F_43 ( struct V_96 * V_96 , void * V_97 ,
struct V_49 * V_99 )
{
struct V_51 * V_52 = F_42 ( V_96 ) ;
struct V_5 * V_6 = V_52 -> V_6 ;
const struct V_1 * V_50 ;
enum V_105 V_73 = V_99 -> V_50 . V_58 . V_73 ;
unsigned int V_106 ;
unsigned V_107 ;
V_50 = F_1 ( V_99 -> V_50 . V_58 . V_101 ) ;
if ( NULL == V_50 )
return - V_60 ;
V_106 = ( V_6 -> V_75 & V_76 ) ? 576 : 480 ;
V_107 = V_99 -> V_50 . V_58 . V_56 ;
if ( V_73 != V_82 )
V_73 = V_78 ;
if ( V_107 < 352 ) {
V_107 = 176 ;
V_99 -> V_50 . V_58 . V_57 = V_106 / 4 ;
} else if ( V_107 < 720 ) {
V_107 = 352 ;
V_99 -> V_50 . V_58 . V_57 = V_106 / 2 ;
} else {
V_107 = 720 ;
V_99 -> V_50 . V_58 . V_57 = V_106 ;
V_73 = V_83 ;
}
V_99 -> V_50 . V_58 . V_73 = V_73 ;
V_99 -> V_50 . V_58 . V_56 = V_107 ;
V_99 -> V_50 . V_58 . V_102 = ( V_99 -> V_50 . V_58 . V_56 * V_50 -> V_55 ) >> 3 ;
V_99 -> V_50 . V_58 . V_59 = V_99 -> V_50 . V_58 . V_57 * V_99 -> V_50 . V_58 . V_102 ;
V_99 -> V_50 . V_58 . V_103 = V_104 ;
return 0 ;
}
static int F_44 ( struct V_96 * V_96 , void * V_97 ,
struct V_49 * V_99 )
{
struct V_51 * V_52 = F_42 ( V_96 ) ;
struct V_5 * V_6 = V_52 -> V_6 ;
int V_108 = V_109 ;
int V_110 ;
V_110 = F_43 ( V_96 , V_97 , V_99 ) ;
if ( 0 != V_110 )
return V_110 ;
V_52 -> V_50 = F_1 ( V_99 -> V_50 . V_58 . V_101 ) ;
V_52 -> V_73 = V_99 -> V_50 . V_58 . V_73 ;
V_52 -> V_56 = V_99 -> V_50 . V_58 . V_56 ;
V_52 -> V_57 = V_99 -> V_50 . V_58 . V_57 ;
if ( V_99 -> V_50 . V_58 . V_101 == V_111 )
V_108 = V_72 ;
else
V_108 = V_109 ;
F_45 ( V_6 , V_112 , V_108 ) ;
if ( V_52 -> V_56 == 320 || V_52 -> V_56 == 352 )
V_52 -> V_74 = 1 ;
else
V_52 -> V_74 = 0 ;
V_52 -> V_77 = V_52 -> V_56 ;
F_46 ( V_6 , V_52 -> V_56 , V_112 ) ;
return 0 ;
}
static int F_47 ( struct V_96 * V_96 , void * V_97 )
{
struct V_51 * V_52 = F_42 ( V_96 ) ;
struct V_5 * V_6 = V_52 -> V_6 ;
const struct V_11 * V_113 = V_52 -> V_27 ;
T_1 V_13 = 0 ;
V_13 = F_7 ( V_113 -> V_20 ) ;
F_48 ( L_4 ,
( V_13 & 0x11 ) ? L_5 : L_6 ) ;
return 0 ;
}
static int F_49 ( struct V_96 * V_96 , void * V_97 ,
struct V_114 * V_115 )
{
struct V_51 * V_52 = F_42 ( V_96 ) ;
struct V_5 * V_6 = V_52 -> V_6 ;
const T_1 V_116 = V_117 |
V_118 | V_119 ;
const T_1 V_120 = V_121 | V_118 ;
strcpy ( V_115 -> V_122 , L_7 ) ;
F_40 ( V_115 -> V_123 , V_124 [ V_6 -> V_125 ] . V_29 , sizeof( V_115 -> V_123 ) ) ;
sprintf ( V_115 -> V_126 , L_8 , F_50 ( V_6 -> V_79 ) ) ;
if ( V_52 -> V_88 >= V_127 )
V_115 -> V_128 = V_120 ;
else
V_115 -> V_128 = V_116 ;
V_115 -> V_129 = V_116 | V_120 | V_130 ;
return 0 ;
}
static int F_51 ( struct V_96 * V_96 , void * V_97 , T_2 * V_131 )
{
struct V_51 * V_52 = F_42 ( V_96 ) ;
* V_131 = V_52 -> V_6 -> V_75 ;
return 0 ;
}
static int F_52 ( struct V_96 * V_96 , void * V_97 ,
T_2 V_131 )
{
struct V_51 * V_52 = F_42 ( V_96 ) ;
struct V_5 * V_6 = V_52 -> V_6 ;
if ( V_6 -> V_75 == V_131 )
return 0 ;
V_6 -> V_75 = V_131 ;
V_52 -> V_56 = 720 ;
V_52 -> V_57 = ( V_6 -> V_75 & V_76 ) ? 576 : 480 ;
F_53 ( V_6 ) ;
return 0 ;
}
static int F_54 ( struct V_96 * V_96 , void * V_97 ,
struct V_132 * V_3 )
{
if ( V_3 -> V_86 )
return - V_60 ;
V_3 -> type = V_133 ;
V_3 -> V_134 = V_135 ;
strcpy ( V_3 -> V_29 , L_9 ) ;
return 0 ;
}
static int F_55 ( struct V_96 * V_96 , void * V_97 , unsigned int * V_3 )
{
* V_3 = 0 ;
return 0 ;
}
static int F_56 ( struct V_96 * V_96 , void * V_97 , unsigned int V_3 )
{
return V_3 ? - V_60 : 0 ;
}
static int F_57 ( struct V_136 * V_137 )
{
struct V_51 * V_52 =
F_22 ( V_137 -> V_138 , struct V_51 , V_139 ) ;
struct V_5 * V_6 = V_52 -> V_6 ;
switch ( V_137 -> V_88 ) {
case V_140 :
F_58 ( V_6 , V_137 -> V_141 , V_52 -> V_88 ) ;
break;
case V_142 :
F_59 ( V_6 , V_137 -> V_141 , V_52 -> V_88 ) ;
break;
case V_143 :
F_60 ( V_6 , V_137 -> V_141 , V_52 -> V_88 ) ;
break;
case V_144 :
F_61 ( V_6 , V_137 -> V_141 , V_52 -> V_88 ) ;
break;
default:
return - V_60 ;
}
return 0 ;
}
static int F_62 ( struct V_96 * V_96 , void * V_97 ,
struct V_145 * V_146 )
{
if ( V_146 -> V_86 )
return - V_60 ;
V_146 -> type = V_133 ;
V_146 -> V_134 = V_135 ;
strcpy ( V_146 -> V_29 , L_9 ) ;
return 0 ;
}
static int F_63 ( struct V_96 * V_96 , void * V_97 , unsigned int * V_146 )
{
* V_146 = 0 ;
return 0 ;
}
static int F_64 ( struct V_96 * V_96 , void * V_97 , unsigned int V_146 )
{
return V_146 ? - V_60 : 0 ;
}
static int F_65 ( struct V_96 * V_96 , void * V_97 ,
struct V_49 * V_99 )
{
struct V_51 * V_52 = F_42 ( V_96 ) ;
struct V_5 * V_6 = V_52 -> V_6 ;
const struct V_1 * V_50 ;
V_50 = F_1 ( V_99 -> V_50 . V_58 . V_101 ) ;
if ( NULL == V_50 )
return - V_60 ;
V_99 -> V_50 . V_58 . V_56 = 720 ;
V_99 -> V_50 . V_58 . V_57 = ( V_6 -> V_75 & V_76 ) ? 576 : 480 ;
V_99 -> V_50 . V_58 . V_73 = V_83 ;
V_99 -> V_50 . V_58 . V_102 = ( V_99 -> V_50 . V_58 . V_56 * V_50 -> V_55 ) >> 3 ;
V_99 -> V_50 . V_58 . V_59 = V_99 -> V_50 . V_58 . V_57 * V_99 -> V_50 . V_58 . V_102 ;
V_99 -> V_50 . V_58 . V_103 = V_104 ;
return 0 ;
}
static int F_66 ( struct V_96 * V_96 , void * V_97 ,
struct V_49 * V_99 )
{
struct V_51 * V_52 = F_42 ( V_96 ) ;
int V_110 ;
V_110 = F_65 ( V_96 , V_97 , V_99 ) ;
if ( 0 != V_110 )
return V_110 ;
V_52 -> V_50 = F_1 ( V_99 -> V_50 . V_58 . V_101 ) ;
V_52 -> V_73 = V_99 -> V_50 . V_58 . V_73 ;
V_52 -> V_56 = V_99 -> V_50 . V_58 . V_56 ;
V_52 -> V_57 = V_99 -> V_50 . V_58 . V_57 ;
if ( V_99 -> V_50 . V_58 . V_101 == V_111 )
V_52 -> V_71 = V_72 ;
else
V_52 -> V_71 = V_109 ;
return 0 ;
}
void F_67 ( struct V_5 * V_6 , int V_22 )
{
F_10 ( V_18 , 1 ) ;
if ( F_68 ( & V_6 -> V_26 [ V_22 ] . V_147 ) ) {
F_69 ( & V_6 -> V_26 [ V_22 ] . V_147 ) ;
F_70 ( & V_6 -> V_26 [ V_22 ] . V_139 ) ;
}
}
int F_71 ( struct V_5 * V_6 )
{
int V_110 ;
int V_3 ;
V_6 -> V_75 = V_148 ;
F_72 ( & V_6 -> V_33 ) ;
for ( V_3 = 0 ; V_3 < V_149 - 1 ; ++ V_3 ) {
struct V_51 * V_52 = & V_6 -> V_26 [ V_3 ] ;
struct V_150 * V_147 = & V_52 -> V_147 ;
struct V_151 * V_139 = & V_52 -> V_139 ;
struct V_43 * V_8 ;
bool V_152 = V_3 > V_153 ;
if ( V_3 == V_153 )
continue;
if ( ! V_152 ) {
F_73 ( V_139 , 4 ) ;
F_74 ( V_139 , & V_154 ,
V_140 , 0 , 10000 , 1 , 6200 ) ;
F_74 ( V_139 , & V_154 ,
V_143 , 0 , 10000 , 1 , 5000 ) ;
F_74 ( V_139 , & V_154 ,
V_144 , 0 , 10000 , 1 , 5000 ) ;
F_74 ( V_139 , & V_154 ,
V_142 , 0 , 10000 , 1 , 5000 ) ;
if ( V_139 -> error ) {
V_110 = V_139 -> error ;
goto V_155;
}
V_110 = F_75 ( V_139 ) ;
if ( V_110 )
goto V_155;
} else {
V_52 -> V_156 = & V_6 -> V_157 [ V_3 - V_158 ] ;
V_52 -> V_156 -> V_52 = V_52 ;
}
V_52 -> V_27 = & V_159 [ V_3 ] ;
V_52 -> V_56 = 720 ;
V_52 -> V_73 = V_83 ;
if ( V_6 -> V_75 & V_76 )
V_52 -> V_57 = 576 ;
else
V_52 -> V_57 = 480 ;
if ( V_52 -> V_71 == V_72 )
V_52 -> V_50 = F_1 ( V_111 ) ;
else
V_52 -> V_50 = F_1 ( V_160 ) ;
F_5 ( V_52 -> V_27 -> V_28 , 0xffffffff ) ;
F_76 ( & V_52 -> V_32 . V_34 ) ;
V_8 = & V_52 -> V_161 ;
V_8 -> type = V_152 ? V_162 :
V_163 ;
V_8 -> V_164 = V_165 | V_166 | V_167 ;
V_8 -> V_164 |= V_152 ? V_168 : V_169 ;
V_8 -> V_170 = V_171 ;
V_8 -> V_172 = 2 ;
V_8 -> V_53 = V_52 ;
V_8 -> V_173 = sizeof( struct V_9 ) ;
V_8 -> V_174 = & V_175 ;
V_8 -> V_176 = & V_177 ;
V_8 -> V_178 = V_179 ;
V_8 -> V_180 = & V_6 -> V_180 ;
if ( ! V_152 ) {
V_110 = F_77 ( V_8 ) ;
if ( V_110 < 0 )
goto V_155;
}
* V_147 = V_152 ? V_181 : V_182 ;
V_147 -> V_183 = & V_6 -> V_183 ;
if ( ! V_152 )
V_147 -> V_184 = V_139 ;
else
V_147 -> V_185 = V_186 ;
V_147 -> V_180 = & V_6 -> V_180 ;
V_147 -> V_36 = V_8 ;
snprintf ( V_147 -> V_29 , sizeof( V_147 -> V_29 ) , L_10 , V_6 -> V_29 , V_3 ) ;
F_78 ( V_147 , V_52 ) ;
V_110 = F_79 ( V_147 , V_187 ,
V_188 [ V_6 -> V_189 ] ) ;
if ( V_110 < 0 )
goto V_155;
}
F_6 ( V_18 , 0xff ) ;
return 0 ;
V_155:
while ( V_3 >= 0 )
F_67 ( V_6 , V_3 -- ) ;
return V_110 ;
}
