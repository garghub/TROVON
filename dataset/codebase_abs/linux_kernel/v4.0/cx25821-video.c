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
F_15 ( & V_10 -> V_37 . V_38 . V_39 ) ;
V_10 -> V_37 . V_38 . V_40 = V_31 -> V_41 ++ ;
F_16 ( & V_10 -> V_36 ) ;
F_17 ( & V_10 -> V_37 , V_42 ) ;
}
F_18 ( & V_6 -> V_33 ) ;
V_24 ++ ;
}
return V_24 ;
}
static int F_19 ( struct V_43 * V_8 , const struct V_44 * V_45 ,
unsigned int * V_46 , unsigned int * V_47 ,
unsigned int V_48 [] , void * V_49 [] )
{
struct V_50 * V_51 = V_8 -> V_52 ;
unsigned V_53 = ( V_51 -> V_45 -> V_54 * V_51 -> V_55 * V_51 -> V_56 ) >> 3 ;
if ( V_45 && V_45 -> V_45 . V_57 . V_58 < V_53 )
return - V_59 ;
* V_47 = 1 ;
V_48 [ 0 ] = V_45 ? V_45 -> V_45 . V_57 . V_58 : V_53 ;
V_49 [ 0 ] = V_51 -> V_6 -> V_60 ;
return 0 ;
}
static int F_20 ( struct V_61 * V_37 )
{
struct V_50 * V_51 = V_37 -> V_43 -> V_52 ;
struct V_5 * V_6 = V_51 -> V_6 ;
struct V_9 * V_10 =
F_21 ( V_37 , struct V_9 , V_37 ) ;
struct V_62 * V_63 = F_22 ( V_37 , 0 ) ;
T_1 V_64 ;
int V_65 = V_66 ;
int V_67 ;
if ( V_51 -> V_68 == V_69 )
V_10 -> V_14 = ( V_51 -> V_45 -> V_54 * V_51 -> V_55 ) >> 3 ;
else
V_10 -> V_14 = ( V_51 -> V_45 -> V_54 >> 3 ) * V_51 -> V_55 ;
if ( F_23 ( V_37 , 0 ) < V_51 -> V_56 * V_10 -> V_14 )
return - V_59 ;
F_24 ( V_37 , 0 , V_51 -> V_56 * V_10 -> V_14 ) ;
V_10 -> V_37 . V_38 . V_70 = V_51 -> V_70 ;
if ( V_51 -> V_68 == V_69 ) {
V_65 = V_10 -> V_14 ;
} else {
V_65 = V_10 -> V_14 ;
if ( V_51 -> V_71 ) {
if ( V_6 -> V_72 & V_73 )
V_65 = 352 << 1 ;
else
V_65 = V_51 -> V_74 << 1 ;
}
}
switch ( V_51 -> V_70 ) {
case V_75 :
V_67 = F_25 ( V_6 -> V_76 , & V_10 -> V_15 ,
V_63 -> V_77 , 0 , V_78 ,
V_10 -> V_14 , 0 , V_51 -> V_56 ) ;
break;
case V_79 :
V_67 = F_25 ( V_6 -> V_76 , & V_10 -> V_15 ,
V_63 -> V_77 , V_78 , 0 ,
V_10 -> V_14 , 0 , V_51 -> V_56 ) ;
break;
case V_80 :
V_64 = 0 ;
F_26 ( 1 , L_2 ) ;
V_67 = F_25 ( V_6 -> V_76 , & V_10 -> V_15 ,
V_63 -> V_77 , V_64 ,
V_65 , V_65 , V_65 ,
V_51 -> V_56 >> 1 ) ;
break;
case V_81 :
V_67 = F_25 ( V_6 -> V_76 , & V_10 -> V_15 ,
V_63 -> V_77 ,
0 , V_10 -> V_14 * ( V_51 -> V_56 >> 1 ) ,
V_10 -> V_14 , 0 , V_51 -> V_56 >> 1 ) ;
break;
case V_82 :
V_67 = F_25 ( V_6 -> V_76 , & V_10 -> V_15 ,
V_63 -> V_77 ,
V_10 -> V_14 * ( V_51 -> V_56 >> 1 ) , 0 ,
V_10 -> V_14 , 0 , V_51 -> V_56 >> 1 ) ;
break;
default:
F_27 ( 1 ) ;
V_67 = - V_59 ;
break;
}
F_26 ( 2 , L_3 ,
V_10 , V_10 -> V_37 . V_38 . V_83 , V_51 -> V_55 , V_51 -> V_56 ,
V_51 -> V_45 -> V_54 , V_51 -> V_45 -> V_29 ,
( unsigned long ) V_10 -> V_15 . V_16 ) ;
return V_67 ;
}
static void F_28 ( struct V_61 * V_37 )
{
struct V_9 * V_10 =
F_21 ( V_37 , struct V_9 , V_37 ) ;
struct V_50 * V_51 = V_37 -> V_43 -> V_52 ;
struct V_5 * V_6 = V_51 -> V_6 ;
F_29 ( V_6 , V_10 ) ;
}
static void F_30 ( struct V_61 * V_37 )
{
struct V_9 * V_10 =
F_21 ( V_37 , struct V_9 , V_37 ) ;
struct V_50 * V_51 = V_37 -> V_43 -> V_52 ;
struct V_5 * V_6 = V_51 -> V_6 ;
struct V_9 * V_84 ;
struct V_7 * V_8 = & V_6 -> V_26 [ V_51 -> V_85 ] . V_32 ;
V_10 -> V_15 . V_86 [ 1 ] = F_31 ( V_10 -> V_15 . V_16 + 12 ) ;
V_10 -> V_15 . V_87 [ 0 ] = F_31 ( V_88 | V_89 ) ;
V_10 -> V_15 . V_87 [ 1 ] = F_31 ( V_10 -> V_15 . V_16 + 12 ) ;
V_10 -> V_15 . V_87 [ 2 ] = F_31 ( 0 ) ;
if ( F_13 ( & V_8 -> V_34 ) ) {
F_32 ( & V_10 -> V_36 , & V_8 -> V_34 ) ;
} else {
V_10 -> V_15 . V_86 [ 0 ] |= F_31 ( V_90 ) ;
V_84 = F_14 ( V_8 -> V_34 . V_84 , struct V_9 ,
V_36 ) ;
F_32 ( & V_10 -> V_36 , & V_8 -> V_34 ) ;
V_84 -> V_15 . V_87 [ 1 ] = F_31 ( V_10 -> V_15 . V_16 ) ;
}
}
static int F_33 ( struct V_43 * V_8 , unsigned int V_41 )
{
struct V_50 * V_51 = V_8 -> V_52 ;
struct V_5 * V_6 = V_51 -> V_6 ;
struct V_7 * V_31 = & V_6 -> V_26 [ V_51 -> V_85 ] . V_32 ;
struct V_9 * V_10 = F_14 ( V_31 -> V_34 . V_35 ,
struct V_9 , V_36 ) ;
V_31 -> V_41 = 0 ;
F_3 ( V_6 , V_31 , V_10 , V_51 -> V_27 ) ;
return 0 ;
}
static void F_34 ( struct V_43 * V_8 )
{
struct V_50 * V_51 = V_8 -> V_52 ;
struct V_5 * V_6 = V_51 -> V_6 ;
struct V_7 * V_31 = & V_6 -> V_26 [ V_51 -> V_85 ] . V_32 ;
unsigned long V_91 ;
F_5 ( V_51 -> V_27 -> V_20 , 0 ) ;
F_35 ( & V_6 -> V_33 , V_91 ) ;
while ( ! F_13 ( & V_31 -> V_34 ) ) {
struct V_9 * V_10 = F_14 ( V_31 -> V_34 . V_35 ,
struct V_9 , V_36 ) ;
F_16 ( & V_10 -> V_36 ) ;
F_17 ( & V_10 -> V_37 , V_92 ) ;
}
F_36 ( & V_6 -> V_33 , V_91 ) ;
}
static int F_37 ( struct V_93 * V_93 , void * V_94 ,
struct V_95 * V_96 )
{
if ( F_38 ( V_96 -> V_83 >= F_2 ( V_4 ) ) )
return - V_59 ;
F_39 ( V_96 -> V_97 , V_4 [ V_96 -> V_83 ] . V_29 , sizeof( V_96 -> V_97 ) ) ;
V_96 -> V_98 = V_4 [ V_96 -> V_83 ] . V_2 ;
return 0 ;
}
static int F_40 ( struct V_93 * V_93 , void * V_94 ,
struct V_44 * V_96 )
{
struct V_50 * V_51 = F_41 ( V_93 ) ;
V_96 -> V_45 . V_57 . V_55 = V_51 -> V_55 ;
V_96 -> V_45 . V_57 . V_56 = V_51 -> V_56 ;
V_96 -> V_45 . V_57 . V_70 = V_51 -> V_70 ;
V_96 -> V_45 . V_57 . V_98 = V_51 -> V_45 -> V_2 ;
V_96 -> V_45 . V_57 . V_99 = ( V_51 -> V_55 * V_51 -> V_45 -> V_54 ) >> 3 ;
V_96 -> V_45 . V_57 . V_58 = V_51 -> V_56 * V_96 -> V_45 . V_57 . V_99 ;
V_96 -> V_45 . V_57 . V_100 = V_101 ;
return 0 ;
}
static int F_42 ( struct V_93 * V_93 , void * V_94 ,
struct V_44 * V_96 )
{
struct V_50 * V_51 = F_41 ( V_93 ) ;
struct V_5 * V_6 = V_51 -> V_6 ;
const struct V_1 * V_45 ;
enum V_102 V_70 = V_96 -> V_45 . V_57 . V_70 ;
unsigned int V_103 ;
unsigned V_104 ;
V_45 = F_1 ( V_96 -> V_45 . V_57 . V_98 ) ;
if ( NULL == V_45 )
return - V_59 ;
V_103 = ( V_6 -> V_72 & V_73 ) ? 576 : 480 ;
V_104 = V_96 -> V_45 . V_57 . V_55 ;
if ( V_70 != V_79 )
V_70 = V_75 ;
if ( V_104 < 352 ) {
V_104 = 176 ;
V_96 -> V_45 . V_57 . V_56 = V_103 / 4 ;
} else if ( V_104 < 720 ) {
V_104 = 352 ;
V_96 -> V_45 . V_57 . V_56 = V_103 / 2 ;
} else {
V_104 = 720 ;
V_96 -> V_45 . V_57 . V_56 = V_103 ;
V_70 = V_80 ;
}
V_96 -> V_45 . V_57 . V_70 = V_70 ;
V_96 -> V_45 . V_57 . V_55 = V_104 ;
V_96 -> V_45 . V_57 . V_99 = ( V_96 -> V_45 . V_57 . V_55 * V_45 -> V_54 ) >> 3 ;
V_96 -> V_45 . V_57 . V_58 = V_96 -> V_45 . V_57 . V_56 * V_96 -> V_45 . V_57 . V_99 ;
V_96 -> V_45 . V_57 . V_100 = V_101 ;
return 0 ;
}
static int F_43 ( struct V_93 * V_93 , void * V_94 ,
struct V_44 * V_96 )
{
struct V_50 * V_51 = F_41 ( V_93 ) ;
struct V_5 * V_6 = V_51 -> V_6 ;
int V_105 = V_106 ;
int V_107 ;
V_107 = F_42 ( V_93 , V_94 , V_96 ) ;
if ( 0 != V_107 )
return V_107 ;
V_51 -> V_45 = F_1 ( V_96 -> V_45 . V_57 . V_98 ) ;
V_51 -> V_70 = V_96 -> V_45 . V_57 . V_70 ;
V_51 -> V_55 = V_96 -> V_45 . V_57 . V_55 ;
V_51 -> V_56 = V_96 -> V_45 . V_57 . V_56 ;
if ( V_96 -> V_45 . V_57 . V_98 == V_108 )
V_105 = V_69 ;
else
V_105 = V_106 ;
F_44 ( V_6 , V_109 , V_105 ) ;
if ( V_51 -> V_55 == 320 || V_51 -> V_55 == 352 )
V_51 -> V_71 = 1 ;
else
V_51 -> V_71 = 0 ;
V_51 -> V_74 = V_51 -> V_55 ;
F_45 ( V_6 , V_51 -> V_55 , V_109 ) ;
return 0 ;
}
static int F_46 ( struct V_93 * V_93 , void * V_94 )
{
struct V_50 * V_51 = F_41 ( V_93 ) ;
struct V_5 * V_6 = V_51 -> V_6 ;
const struct V_11 * V_110 = V_51 -> V_27 ;
T_1 V_13 = 0 ;
V_13 = F_7 ( V_110 -> V_20 ) ;
F_47 ( L_4 ,
( V_13 & 0x11 ) ? L_5 : L_6 ) ;
return 0 ;
}
static int F_48 ( struct V_93 * V_93 , void * V_94 ,
struct V_111 * V_112 )
{
struct V_50 * V_51 = F_41 ( V_93 ) ;
struct V_5 * V_6 = V_51 -> V_6 ;
const T_1 V_113 = V_114 |
V_115 | V_116 ;
const T_1 V_117 = V_118 | V_115 ;
strcpy ( V_112 -> V_119 , L_7 ) ;
F_39 ( V_112 -> V_120 , V_121 [ V_6 -> V_122 ] . V_29 , sizeof( V_112 -> V_120 ) ) ;
sprintf ( V_112 -> V_123 , L_8 , F_49 ( V_6 -> V_76 ) ) ;
if ( V_51 -> V_85 >= V_124 )
V_112 -> V_125 = V_117 ;
else
V_112 -> V_125 = V_113 ;
V_112 -> V_126 = V_113 | V_117 | V_127 ;
return 0 ;
}
static int F_50 ( struct V_93 * V_93 , void * V_94 , T_2 * V_128 )
{
struct V_50 * V_51 = F_41 ( V_93 ) ;
* V_128 = V_51 -> V_6 -> V_72 ;
return 0 ;
}
static int F_51 ( struct V_93 * V_93 , void * V_94 ,
T_2 V_128 )
{
struct V_50 * V_51 = F_41 ( V_93 ) ;
struct V_5 * V_6 = V_51 -> V_6 ;
if ( V_6 -> V_72 == V_128 )
return 0 ;
V_6 -> V_72 = V_128 ;
V_51 -> V_55 = 720 ;
V_51 -> V_56 = ( V_6 -> V_72 & V_73 ) ? 576 : 480 ;
F_52 ( V_6 ) ;
return 0 ;
}
static int F_53 ( struct V_93 * V_93 , void * V_94 ,
struct V_129 * V_3 )
{
if ( V_3 -> V_83 )
return - V_59 ;
V_3 -> type = V_130 ;
V_3 -> V_131 = V_132 ;
strcpy ( V_3 -> V_29 , L_9 ) ;
return 0 ;
}
static int F_54 ( struct V_93 * V_93 , void * V_94 , unsigned int * V_3 )
{
* V_3 = 0 ;
return 0 ;
}
static int F_55 ( struct V_93 * V_93 , void * V_94 , unsigned int V_3 )
{
return V_3 ? - V_59 : 0 ;
}
static int F_56 ( struct V_133 * V_134 )
{
struct V_50 * V_51 =
F_21 ( V_134 -> V_135 , struct V_50 , V_136 ) ;
struct V_5 * V_6 = V_51 -> V_6 ;
switch ( V_134 -> V_85 ) {
case V_137 :
F_57 ( V_6 , V_134 -> V_138 , V_51 -> V_85 ) ;
break;
case V_139 :
F_58 ( V_6 , V_134 -> V_138 , V_51 -> V_85 ) ;
break;
case V_140 :
F_59 ( V_6 , V_134 -> V_138 , V_51 -> V_85 ) ;
break;
case V_141 :
F_60 ( V_6 , V_134 -> V_138 , V_51 -> V_85 ) ;
break;
default:
return - V_59 ;
}
return 0 ;
}
static int F_61 ( struct V_93 * V_93 , void * V_94 ,
struct V_142 * V_143 )
{
if ( V_143 -> V_83 )
return - V_59 ;
V_143 -> type = V_130 ;
V_143 -> V_131 = V_132 ;
strcpy ( V_143 -> V_29 , L_9 ) ;
return 0 ;
}
static int F_62 ( struct V_93 * V_93 , void * V_94 , unsigned int * V_143 )
{
* V_143 = 0 ;
return 0 ;
}
static int F_63 ( struct V_93 * V_93 , void * V_94 , unsigned int V_143 )
{
return V_143 ? - V_59 : 0 ;
}
static int F_64 ( struct V_93 * V_93 , void * V_94 ,
struct V_44 * V_96 )
{
struct V_50 * V_51 = F_41 ( V_93 ) ;
struct V_5 * V_6 = V_51 -> V_6 ;
const struct V_1 * V_45 ;
V_45 = F_1 ( V_96 -> V_45 . V_57 . V_98 ) ;
if ( NULL == V_45 )
return - V_59 ;
V_96 -> V_45 . V_57 . V_55 = 720 ;
V_96 -> V_45 . V_57 . V_56 = ( V_6 -> V_72 & V_73 ) ? 576 : 480 ;
V_96 -> V_45 . V_57 . V_70 = V_80 ;
V_96 -> V_45 . V_57 . V_99 = ( V_96 -> V_45 . V_57 . V_55 * V_45 -> V_54 ) >> 3 ;
V_96 -> V_45 . V_57 . V_58 = V_96 -> V_45 . V_57 . V_56 * V_96 -> V_45 . V_57 . V_99 ;
V_96 -> V_45 . V_57 . V_100 = V_101 ;
return 0 ;
}
static int F_65 ( struct V_93 * V_93 , void * V_94 ,
struct V_44 * V_96 )
{
struct V_50 * V_51 = F_41 ( V_93 ) ;
int V_107 ;
V_107 = F_64 ( V_93 , V_94 , V_96 ) ;
if ( 0 != V_107 )
return V_107 ;
V_51 -> V_45 = F_1 ( V_96 -> V_45 . V_57 . V_98 ) ;
V_51 -> V_70 = V_96 -> V_45 . V_57 . V_70 ;
V_51 -> V_55 = V_96 -> V_45 . V_57 . V_55 ;
V_51 -> V_56 = V_96 -> V_45 . V_57 . V_56 ;
if ( V_96 -> V_45 . V_57 . V_98 == V_108 )
V_51 -> V_68 = V_69 ;
else
V_51 -> V_68 = V_106 ;
return 0 ;
}
void F_66 ( struct V_5 * V_6 , int V_22 )
{
F_10 ( V_18 , 1 ) ;
if ( F_67 ( & V_6 -> V_26 [ V_22 ] . V_144 ) ) {
F_68 ( & V_6 -> V_26 [ V_22 ] . V_144 ) ;
F_69 ( & V_6 -> V_26 [ V_22 ] . V_136 ) ;
}
}
int F_70 ( struct V_5 * V_6 )
{
int V_107 ;
int V_3 ;
V_6 -> V_72 = V_145 ;
F_71 ( & V_6 -> V_33 ) ;
for ( V_3 = 0 ; V_3 < V_146 - 1 ; ++ V_3 ) {
struct V_50 * V_51 = & V_6 -> V_26 [ V_3 ] ;
struct V_147 * V_144 = & V_51 -> V_144 ;
struct V_148 * V_136 = & V_51 -> V_136 ;
struct V_43 * V_8 ;
bool V_149 = V_3 > V_150 ;
if ( V_3 == V_150 )
continue;
if ( ! V_149 ) {
F_72 ( V_136 , 4 ) ;
F_73 ( V_136 , & V_151 ,
V_137 , 0 , 10000 , 1 , 6200 ) ;
F_73 ( V_136 , & V_151 ,
V_140 , 0 , 10000 , 1 , 5000 ) ;
F_73 ( V_136 , & V_151 ,
V_141 , 0 , 10000 , 1 , 5000 ) ;
F_73 ( V_136 , & V_151 ,
V_139 , 0 , 10000 , 1 , 5000 ) ;
if ( V_136 -> error ) {
V_107 = V_136 -> error ;
goto V_152;
}
V_107 = F_74 ( V_136 ) ;
if ( V_107 )
goto V_152;
} else {
V_51 -> V_153 = & V_6 -> V_154 [ V_3 - V_155 ] ;
V_51 -> V_153 -> V_51 = V_51 ;
}
V_51 -> V_27 = & V_156 [ V_3 ] ;
V_51 -> V_55 = 720 ;
V_51 -> V_70 = V_80 ;
if ( V_6 -> V_72 & V_73 )
V_51 -> V_56 = 576 ;
else
V_51 -> V_56 = 480 ;
if ( V_51 -> V_68 == V_69 )
V_51 -> V_45 = F_1 ( V_108 ) ;
else
V_51 -> V_45 = F_1 ( V_157 ) ;
F_5 ( V_51 -> V_27 -> V_28 , 0xffffffff ) ;
F_75 ( & V_51 -> V_32 . V_34 ) ;
V_8 = & V_51 -> V_158 ;
V_8 -> type = V_149 ? V_159 :
V_160 ;
V_8 -> V_161 = V_162 | V_163 | V_164 ;
V_8 -> V_161 |= V_149 ? V_165 : V_166 ;
V_8 -> V_167 = V_168 ;
V_8 -> V_169 = 2 ;
V_8 -> V_52 = V_51 ;
V_8 -> V_170 = sizeof( struct V_9 ) ;
V_8 -> V_171 = & V_172 ;
V_8 -> V_173 = & V_174 ;
V_8 -> V_175 = V_176 ;
V_8 -> V_177 = & V_6 -> V_177 ;
if ( ! V_149 ) {
V_107 = F_76 ( V_8 ) ;
if ( V_107 < 0 )
goto V_152;
}
* V_144 = V_149 ? V_178 : V_179 ;
V_144 -> V_180 = & V_6 -> V_180 ;
if ( ! V_149 )
V_144 -> V_181 = V_136 ;
else
V_144 -> V_182 = V_183 ;
V_144 -> V_177 = & V_6 -> V_177 ;
V_144 -> V_36 = V_8 ;
snprintf ( V_144 -> V_29 , sizeof( V_144 -> V_29 ) , L_10 , V_6 -> V_29 , V_3 ) ;
F_77 ( V_144 , V_51 ) ;
V_107 = F_78 ( V_144 , V_184 ,
V_185 [ V_6 -> V_186 ] ) ;
if ( V_107 < 0 )
goto V_152;
}
F_6 ( V_18 , 0xff ) ;
return 0 ;
V_152:
while ( V_3 >= 0 )
F_66 ( V_6 , V_3 -- ) ;
return V_107 ;
}
