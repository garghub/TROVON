static struct V_1 * F_1 ( unsigned int V_2 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ )
if ( V_4 [ V_3 ] . V_2 == V_2 )
return V_4 + V_3 ;
F_3 ( V_5 L_1 , V_6 , V_2 ) ;
return NULL ;
}
static void F_4 ( struct V_7 * V_8 ,
struct V_9 * V_10 , T_1 V_11 )
{
struct V_12 * V_13 ;
int V_14 ;
for ( V_14 = 0 ; ; V_14 ++ ) {
if ( F_5 ( & V_10 -> V_15 ) )
break;
V_13 = F_6 ( V_10 -> V_15 . V_16 ,
struct V_12 , V_17 . V_18 ) ;
if ( ( V_19 ) ( V_11 - V_13 -> V_11 ) < 0 )
break;
F_7 ( & V_13 -> V_17 . V_20 ) ;
F_8 ( 2 , L_2 , V_13 , V_13 -> V_17 . V_3 ,
V_11 , V_13 -> V_11 ) ;
V_13 -> V_17 . V_21 = V_22 ;
F_9 ( & V_13 -> V_17 . V_18 ) ;
F_10 ( & V_13 -> V_17 . V_23 ) ;
}
if ( F_5 ( & V_10 -> V_15 ) )
F_11 ( & V_10 -> V_24 ) ;
else
F_12 ( & V_10 -> V_24 , V_25 + V_26 ) ;
if ( V_14 != 1 )
F_3 ( V_5 L_3 ,
V_6 , V_14 ) ;
}
static int F_13 ( struct V_7 * V_8 , T_2 V_27 )
{
F_8 ( 1 , L_4 ,
V_6 ,
( unsigned int ) V_27 ,
F_14 ( V_27 ) ) ;
V_8 -> V_28 = V_27 ;
F_15 ( V_8 , V_29 , V_30 , V_27 ) ;
return 0 ;
}
static struct V_31 * F_16 ( struct V_7 * V_8 ,
struct V_32 * V_33 ,
struct V_31 * V_34 ,
char * type )
{
struct V_31 * V_35 ;
F_8 ( 1 , L_5 , V_6 ) ;
V_35 = F_17 () ;
if ( NULL == V_35 )
return NULL ;
* V_35 = * V_34 ;
V_35 -> V_36 = & V_8 -> V_36 ;
V_35 -> V_37 = V_38 ;
snprintf ( V_35 -> V_39 , sizeof( V_35 -> V_39 ) , L_6 ,
V_8 -> V_39 , type , V_40 [ V_8 -> V_41 ] . V_39 ) ;
F_18 ( V_35 , V_8 ) ;
return V_35 ;
}
static int F_19 ( struct V_42 * V_43 )
{
int V_3 ;
if ( V_43 -> V_44 < V_45 ||
V_43 -> V_44 >= V_46 )
return - V_47 ;
for ( V_3 = 0 ; V_3 < V_48 ; V_3 ++ )
if ( V_49 [ V_3 ] . V_50 . V_44 == V_43 -> V_44 )
break;
if ( V_3 == V_48 ) {
* V_43 = V_51 ;
return 0 ;
}
* V_43 = V_49 [ V_3 ] . V_50 ;
return 0 ;
}
static int F_20 ( struct V_7 * V_8 , struct V_52 * V_53 ,
unsigned int V_54 )
{
F_8 ( 1 , L_5 , V_6 ) ;
if ( V_53 -> V_55 & V_54 )
return 1 ;
F_21 ( & V_8 -> V_56 ) ;
if ( V_8 -> V_55 & V_54 ) {
F_22 ( & V_8 -> V_56 ) ;
return 0 ;
}
V_53 -> V_55 |= V_54 ;
V_8 -> V_55 |= V_54 ;
F_8 ( 1 , L_7 , V_54 ) ;
F_22 ( & V_8 -> V_56 ) ;
return 1 ;
}
static int F_23 ( struct V_52 * V_53 , unsigned int V_54 )
{
return V_53 -> V_55 & V_54 ;
}
static int F_24 ( struct V_7 * V_8 , unsigned int V_54 )
{
return V_8 -> V_55 & V_54 ;
}
static void F_25 ( struct V_7 * V_8 , struct V_52 * V_53 ,
unsigned int V_57 )
{
F_26 ( ( V_53 -> V_55 & V_57 ) != V_57 ) ;
F_8 ( 1 , L_5 , V_6 ) ;
F_21 ( & V_8 -> V_56 ) ;
V_53 -> V_55 &= ~ V_57 ;
V_8 -> V_55 &= ~ V_57 ;
F_8 ( 1 , L_8 , V_57 ) ;
F_22 ( & V_8 -> V_56 ) ;
}
static int F_27 ( struct V_7 * V_8 , unsigned int V_58 )
{
F_8 ( 1 , L_9 ,
V_6 ,
V_58 , F_28 ( V_58 ) -> V_59 ,
F_28 ( V_58 ) -> V_60 , F_28 ( V_58 ) -> V_61 ,
F_28 ( V_58 ) -> V_62 , F_28 ( V_58 ) -> V_63 ) ;
V_8 -> V_58 = V_58 ;
if ( V_8 -> V_41 == V_64 ||
V_8 -> V_41 == V_65 ) {
if ( F_28 ( V_58 ) -> type == V_66 )
F_29 ( V_8 , V_67 ) ;
}
F_30 ( V_8 -> V_68 , V_69 , V_70 ,
F_28 ( V_58 ) -> V_59 , 0 , 0 ) ;
return 0 ;
}
static int F_31 ( struct V_7 * V_8 , unsigned int V_71 ,
unsigned int V_72 , enum V_73 V_74 )
{
F_8 ( 1 , L_5 , V_6 ) ;
return 0 ;
}
static int F_32 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
struct V_12 * V_13 )
{
F_8 ( 1 , L_5 , V_6 ) ;
F_33 ( V_8 , & V_8 -> V_75 [ V_76 ] ,
V_13 -> V_77 , V_13 -> V_78 . V_79 ) ;
F_31 ( V_8 , V_13 -> V_17 . V_71 , V_13 -> V_17 . V_72 , V_13 -> V_17 . V_74 ) ;
F_34 ( V_80 , 3 ) ;
V_10 -> V_11 = 1 ;
F_35 ( V_8 , 0x01 ) ;
F_36 ( V_81 , 0x000011 ) ;
F_36 ( V_82 , ( 1 << 5 ) ) ;
F_36 ( V_83 , 0x11 ) ;
return 0 ;
}
static int F_37 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_12 * V_13 , * V_84 ;
struct V_85 * V_86 ;
F_8 ( 1 , L_5 , V_6 ) ;
if ( ! F_5 ( & V_10 -> V_15 ) ) {
V_13 = F_6 ( V_10 -> V_15 . V_16 , struct V_12 ,
V_17 . V_18 ) ;
F_8 ( 2 , L_10 ,
V_13 , V_13 -> V_17 . V_3 ) ;
F_32 ( V_8 , V_10 , V_13 ) ;
F_38 (item, &q->active) {
V_13 = F_6 ( V_86 , struct V_12 ,
V_17 . V_18 ) ;
V_13 -> V_11 = V_10 -> V_11 ++ ;
}
F_12 ( & V_10 -> V_24 , V_25 + V_26 ) ;
return 0 ;
}
V_84 = NULL ;
for (; ; ) {
if ( F_5 ( & V_10 -> V_87 ) )
return 0 ;
V_13 = F_6 ( V_10 -> V_87 . V_16 , struct V_12 ,
V_17 . V_18 ) ;
if ( NULL == V_84 ) {
F_39 ( & V_13 -> V_17 . V_18 , & V_10 -> V_15 ) ;
F_32 ( V_8 , V_10 , V_13 ) ;
V_13 -> V_17 . V_21 = V_88 ;
V_13 -> V_11 = V_10 -> V_11 ++ ;
F_12 ( & V_10 -> V_24 , V_25 + V_26 ) ;
F_8 ( 2 , L_11 ,
V_13 , V_13 -> V_17 . V_3 ) ;
} else if ( V_84 -> V_17 . V_71 == V_13 -> V_17 . V_71 &&
V_84 -> V_17 . V_72 == V_13 -> V_17 . V_72 &&
V_84 -> V_89 == V_13 -> V_89 ) {
F_39 ( & V_13 -> V_17 . V_18 , & V_10 -> V_15 ) ;
V_13 -> V_17 . V_21 = V_88 ;
V_13 -> V_11 = V_10 -> V_11 ++ ;
V_84 -> V_78 . V_90 [ 1 ] = F_40 ( V_13 -> V_78 . V_79 ) ;
V_84 -> V_78 . V_90 [ 2 ] = F_40 ( 0 ) ;
F_8 ( 2 , L_12 ,
V_13 , V_13 -> V_17 . V_3 ) ;
} else {
return 0 ;
}
V_84 = V_13 ;
}
}
static int F_41 ( struct V_91 * V_10 , unsigned int * V_11 ,
unsigned int * V_92 )
{
struct V_52 * V_53 = V_10 -> V_93 ;
* V_92 = V_53 -> V_89 -> V_94 * V_53 -> V_71 * V_53 -> V_72 >> 3 ;
if ( 0 == * V_11 )
* V_11 = 32 ;
if ( * V_92 * * V_11 > V_95 * 1024 * 1024 )
* V_11 = ( V_95 * 1024 * 1024 ) / * V_92 ;
return 0 ;
}
static int F_42 ( struct V_91 * V_10 , struct V_96 * V_17 ,
enum V_73 V_74 )
{
struct V_52 * V_53 = V_10 -> V_93 ;
struct V_7 * V_8 = V_53 -> V_8 ;
struct V_12 * V_13 =
F_43 ( V_17 , struct V_12 , V_17 ) ;
int V_97 , V_98 = 0 ;
T_1 V_99 , V_100 ;
struct V_101 * V_79 = F_44 ( & V_13 -> V_17 ) ;
F_26 ( NULL == V_53 -> V_89 ) ;
if ( V_53 -> V_71 < 48 || V_53 -> V_71 > F_45 ( V_8 -> V_28 ) ||
V_53 -> V_72 < 32 || V_53 -> V_72 > F_46 ( V_8 -> V_28 ) )
return - V_47 ;
V_13 -> V_17 . V_92 = ( V_53 -> V_71 * V_53 -> V_72 * V_53 -> V_89 -> V_94 ) >> 3 ;
if ( 0 != V_13 -> V_17 . V_102 && V_13 -> V_17 . V_103 < V_13 -> V_17 . V_92 )
return - V_47 ;
if ( V_13 -> V_89 != V_53 -> V_89 ||
V_13 -> V_17 . V_71 != V_53 -> V_71 ||
V_13 -> V_17 . V_72 != V_53 -> V_72 ||
V_13 -> V_17 . V_74 != V_74 ) {
V_13 -> V_89 = V_53 -> V_89 ;
V_13 -> V_17 . V_71 = V_53 -> V_71 ;
V_13 -> V_17 . V_72 = V_53 -> V_72 ;
V_13 -> V_17 . V_74 = V_74 ;
V_98 = 1 ;
}
if ( V_104 == V_13 -> V_17 . V_21 ) {
V_98 = 1 ;
V_97 = F_47 ( V_10 , & V_13 -> V_17 , NULL ) ;
if ( 0 != V_97 )
goto V_105;
}
if ( V_98 ) {
V_13 -> V_77 = V_13 -> V_17 . V_71 * V_13 -> V_89 -> V_94 >> 3 ;
switch ( V_13 -> V_17 . V_74 ) {
case V_106 :
F_48 ( V_8 -> V_33 , & V_13 -> V_78 ,
V_79 -> V_107 , 0 , V_108 ,
V_13 -> V_77 , 0 , V_13 -> V_17 . V_72 ) ;
break;
case V_109 :
F_48 ( V_8 -> V_33 , & V_13 -> V_78 ,
V_79 -> V_107 , V_108 , 0 ,
V_13 -> V_77 , 0 , V_13 -> V_17 . V_72 ) ;
break;
case V_110 :
if ( V_8 -> V_28 & V_111 ) {
F_8 ( 1 , L_13 ,
V_6 ) ;
V_99 = V_13 -> V_77 ;
V_100 = 0 ;
} else {
F_8 ( 1 , L_14 ,
V_6 ) ;
V_99 = 0 ;
V_100 = V_13 -> V_77 ;
}
F_48 ( V_8 -> V_33 , & V_13 -> V_78 ,
V_79 -> V_107 , V_99 ,
V_100 ,
V_13 -> V_77 , V_13 -> V_77 ,
V_13 -> V_17 . V_72 >> 1 ) ;
break;
case V_112 :
F_48 ( V_8 -> V_33 , & V_13 -> V_78 ,
V_79 -> V_107 ,
0 , V_13 -> V_77 * ( V_13 -> V_17 . V_72 >> 1 ) ,
V_13 -> V_77 , 0 ,
V_13 -> V_17 . V_72 >> 1 ) ;
break;
case V_113 :
F_48 ( V_8 -> V_33 , & V_13 -> V_78 ,
V_79 -> V_107 ,
V_13 -> V_77 * ( V_13 -> V_17 . V_72 >> 1 ) , 0 ,
V_13 -> V_77 , 0 ,
V_13 -> V_17 . V_72 >> 1 ) ;
break;
default:
F_49 () ;
}
}
F_8 ( 2 , L_15 ,
V_13 , V_13 -> V_17 . V_3 ,
V_53 -> V_71 , V_53 -> V_72 , V_53 -> V_89 -> V_94 , V_53 -> V_89 -> V_39 ,
( unsigned long ) V_13 -> V_78 . V_79 ) ;
V_13 -> V_17 . V_21 = V_114 ;
return 0 ;
V_105:
F_50 ( V_10 , V_13 ) ;
return V_97 ;
}
static void F_51 ( struct V_91 * V_115 , struct V_96 * V_17 )
{
struct V_12 * V_13 = F_43 ( V_17 ,
struct V_12 , V_17 ) ;
struct V_12 * V_84 ;
struct V_52 * V_53 = V_115 -> V_93 ;
struct V_7 * V_8 = V_53 -> V_8 ;
struct V_9 * V_10 = & V_8 -> V_116 ;
V_13 -> V_78 . V_90 [ 0 ] = F_40 ( V_117 | V_118 | V_119 ) ;
V_13 -> V_78 . V_90 [ 1 ] = F_40 ( V_10 -> V_120 . V_79 ) ;
V_13 -> V_78 . V_90 [ 2 ] = F_40 ( 0 ) ;
if ( ! F_5 ( & V_10 -> V_87 ) ) {
F_52 ( & V_13 -> V_17 . V_18 , & V_10 -> V_87 ) ;
V_13 -> V_17 . V_21 = V_121 ;
F_8 ( 2 , L_16 ,
V_13 , V_13 -> V_17 . V_3 ) ;
} else if ( F_5 ( & V_10 -> V_15 ) ) {
F_52 ( & V_13 -> V_17 . V_18 , & V_10 -> V_15 ) ;
F_32 ( V_8 , V_10 , V_13 ) ;
V_13 -> V_17 . V_21 = V_88 ;
V_13 -> V_11 = V_10 -> V_11 ++ ;
F_12 ( & V_10 -> V_24 , V_25 + V_26 ) ;
F_8 ( 2 , L_17 ,
V_13 , V_13 -> V_17 . V_3 ) ;
} else {
V_84 = F_6 ( V_10 -> V_15 . V_84 , struct V_12 ,
V_17 . V_18 ) ;
if ( V_84 -> V_17 . V_71 == V_13 -> V_17 . V_71 &&
V_84 -> V_17 . V_72 == V_13 -> V_17 . V_72 &&
V_84 -> V_89 == V_13 -> V_89 ) {
F_52 ( & V_13 -> V_17 . V_18 , & V_10 -> V_15 ) ;
V_13 -> V_17 . V_21 = V_88 ;
V_13 -> V_11 = V_10 -> V_11 ++ ;
V_84 -> V_78 . V_90 [ 1 ] = F_40 ( V_13 -> V_78 . V_79 ) ;
V_84 -> V_78 . V_90 [ 2 ] = F_40 ( 0 ) ;
F_8 ( 2 , L_18 ,
V_13 , V_13 -> V_17 . V_3 ) ;
} else {
F_52 ( & V_13 -> V_17 . V_18 , & V_10 -> V_87 ) ;
V_13 -> V_17 . V_21 = V_121 ;
F_8 ( 2 , L_19 ,
V_13 , V_13 -> V_17 . V_3 ) ;
}
}
}
static void F_53 ( struct V_91 * V_10 ,
struct V_96 * V_17 )
{
struct V_12 * V_13 = F_43 ( V_17 ,
struct V_12 , V_17 ) ;
F_50 ( V_10 , V_13 ) ;
}
static struct V_91 * F_54 ( struct V_52 * V_53 )
{
switch ( V_53 -> type ) {
case V_122 :
return & V_53 -> V_116 ;
case V_123 :
return & V_53 -> V_124 ;
default:
F_49 () ;
return NULL ;
}
}
static int F_55 ( struct V_52 * V_53 )
{
switch ( V_53 -> type ) {
case V_122 :
return V_125 ;
case V_123 :
return V_126 ;
default:
F_49 () ;
return 0 ;
}
}
static int F_56 ( struct V_127 * V_127 )
{
struct V_31 * V_128 = F_57 ( V_127 ) ;
struct V_7 * V_8 = F_58 ( V_127 ) ;
struct V_52 * V_53 ;
enum V_129 type = 0 ;
int V_130 = 0 ;
switch ( V_128 -> V_131 ) {
case V_132 :
type = V_122 ;
break;
case V_133 :
type = V_123 ;
break;
case V_134 :
V_130 = 1 ;
break;
}
F_8 ( 1 , L_20 ,
F_59 ( V_128 ) , V_130 , V_135 [ type ] ) ;
V_53 = F_60 ( sizeof( * V_53 ) , V_136 ) ;
if ( NULL == V_53 )
return - V_137 ;
V_127 -> V_138 = V_53 ;
V_53 -> V_8 = V_8 ;
V_53 -> V_130 = V_130 ;
V_53 -> type = type ;
V_53 -> V_71 = 320 ;
V_53 -> V_72 = 240 ;
V_53 -> V_89 = F_1 ( V_139 ) ;
F_61 ( & V_53 -> V_116 , & V_140 ,
& V_8 -> V_33 -> V_8 , & V_8 -> V_141 ,
V_122 ,
V_110 ,
sizeof( struct V_12 ) ,
V_53 , NULL ) ;
F_8 ( 1 , L_21 ) ;
return 0 ;
}
static T_3 F_62 ( struct V_127 * V_127 , char T_4 * V_142 ,
T_5 V_11 , T_6 * V_143 )
{
struct V_52 * V_53 = V_127 -> V_138 ;
switch ( V_53 -> type ) {
case V_122 :
if ( F_24 ( V_53 -> V_8 , V_125 ) )
return - V_144 ;
return F_63 ( & V_53 -> V_116 , V_142 , V_11 , V_143 ,
V_127 -> V_145 & V_146 ) ;
case V_123 :
if ( ! F_20 ( V_53 -> V_8 , V_53 , V_126 ) )
return - V_144 ;
return F_64 ( & V_53 -> V_124 , V_142 , V_11 , V_143 , 1 ,
V_127 -> V_145 & V_146 ) ;
default:
F_49 () ;
return 0 ;
}
}
static unsigned int F_65 ( struct V_127 * V_127 ,
struct V_147 * V_148 )
{
struct V_52 * V_53 = V_127 -> V_138 ;
struct V_12 * V_13 ;
unsigned int V_97 = V_149 ;
if ( V_123 == V_53 -> type ) {
if ( ! F_20 ( V_53 -> V_8 , V_53 , V_126 ) )
return V_149 ;
return F_66 ( V_127 , & V_53 -> V_124 , V_148 ) ;
}
F_21 ( & V_53 -> V_116 . V_150 ) ;
if ( F_23 ( V_53 , V_125 ) ) {
if ( F_5 ( & V_53 -> V_116 . V_151 ) )
goto V_23;
V_13 = F_6 ( V_53 -> V_116 . V_151 . V_16 ,
struct V_12 , V_17 . V_151 ) ;
} else {
V_13 = (struct V_12 * ) V_53 -> V_116 . V_152 ;
if ( NULL == V_13 )
goto V_23;
}
F_67 ( V_127 , & V_13 -> V_17 . V_23 , V_148 ) ;
if ( V_13 -> V_17 . V_21 == V_22 ||
V_13 -> V_17 . V_21 == V_153 )
V_97 = V_154 | V_155 ;
else
V_97 = 0 ;
V_23:
F_22 ( & V_53 -> V_116 . V_150 ) ;
return V_97 ;
}
static int F_68 ( struct V_127 * V_127 )
{
struct V_52 * V_53 = V_127 -> V_138 ;
struct V_7 * V_8 = V_53 -> V_8 ;
if ( F_23 ( V_53 , V_156 ) ) {
F_25 ( V_8 , V_53 , V_156 ) ;
}
if ( F_23 ( V_53 , V_125 ) ) {
F_69 ( & V_53 -> V_116 ) ;
F_25 ( V_8 , V_53 , V_125 ) ;
}
if ( V_53 -> V_116 . V_152 ) {
F_53 ( & V_53 -> V_116 , V_53 -> V_116 . V_152 ) ;
F_70 ( V_53 -> V_116 . V_152 ) ;
}
if ( F_23 ( V_53 , V_126 ) ) {
if ( V_53 -> V_124 . V_157 )
F_71 ( & V_53 -> V_124 ) ;
if ( V_53 -> V_124 . V_158 )
F_72 ( & V_53 -> V_124 ) ;
F_25 ( V_8 , V_53 , V_126 ) ;
}
F_73 ( & V_53 -> V_116 ) ;
V_127 -> V_138 = NULL ;
F_70 ( V_53 ) ;
return 0 ;
}
static int F_74 ( struct V_127 * V_127 , struct V_159 * V_160 )
{
struct V_52 * V_53 = V_127 -> V_138 ;
return F_75 ( F_54 ( V_53 ) , V_160 ) ;
}
static int F_76 ( struct V_7 * V_8 ,
struct V_161 * V_162 )
{
F_8 ( 1 , L_22 , V_6 ) ;
F_15 ( V_8 , V_29 , V_163 , V_162 ) ;
return 0 ;
}
static int F_77 ( struct V_7 * V_8 ,
struct V_161 * V_162 )
{
F_8 ( 1 , L_23
L_24 , V_6 ) ;
return 0 ;
}
static void F_78 ( struct V_7 * V_8 )
{
struct V_161 V_164 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_48 ; V_3 ++ ) {
V_164 . V_44 = V_49 [ V_3 ] . V_50 . V_44 ;
V_164 . V_165 = V_49 [ V_3 ] . V_50 . V_166 ;
F_77 ( V_8 , & V_164 ) ;
}
}
static int F_79 ( struct V_127 * V_127 , void * V_167 ,
struct V_168 * V_169 )
{
struct V_52 * V_53 = V_167 ;
V_169 -> V_89 . V_170 . V_71 = V_53 -> V_71 ;
V_169 -> V_89 . V_170 . V_72 = V_53 -> V_72 ;
V_169 -> V_89 . V_170 . V_74 = V_53 -> V_116 . V_74 ;
V_169 -> V_89 . V_170 . V_171 = V_53 -> V_89 -> V_2 ;
V_169 -> V_89 . V_170 . V_172 =
( V_169 -> V_89 . V_170 . V_71 * V_53 -> V_89 -> V_94 ) >> 3 ;
V_169 -> V_89 . V_170 . V_173 =
V_169 -> V_89 . V_170 . V_72 * V_169 -> V_89 . V_170 . V_172 ;
return 0 ;
}
static int F_80 ( struct V_127 * V_127 , void * V_167 ,
struct V_168 * V_169 )
{
struct V_7 * V_8 = ( (struct V_52 * ) V_167 ) -> V_8 ;
struct V_1 * V_89 ;
enum V_73 V_74 ;
unsigned int V_174 , V_175 ;
V_89 = F_1 ( V_169 -> V_89 . V_170 . V_171 ) ;
if ( NULL == V_89 )
return - V_47 ;
V_74 = V_169 -> V_89 . V_170 . V_74 ;
V_174 = F_45 ( V_8 -> V_28 ) ;
V_175 = F_46 ( V_8 -> V_28 ) ;
if ( V_176 == V_74 ) {
V_74 = ( V_169 -> V_89 . V_170 . V_72 > V_175 / 2 )
? V_110
: V_109 ;
}
switch ( V_74 ) {
case V_106 :
case V_109 :
V_175 = V_175 / 2 ;
break;
case V_110 :
break;
default:
return - V_47 ;
}
V_169 -> V_89 . V_170 . V_74 = V_74 ;
F_81 ( & V_169 -> V_89 . V_170 . V_71 , 48 , V_174 , 2 ,
& V_169 -> V_89 . V_170 . V_72 , 32 , V_175 , 0 , 0 ) ;
V_169 -> V_89 . V_170 . V_172 =
( V_169 -> V_89 . V_170 . V_71 * V_89 -> V_94 ) >> 3 ;
V_169 -> V_89 . V_170 . V_173 =
V_169 -> V_89 . V_170 . V_72 * V_169 -> V_89 . V_170 . V_172 ;
return 0 ;
}
static int F_82 ( struct V_127 * V_127 , void * V_167 ,
struct V_168 * V_169 )
{
struct V_52 * V_53 = V_167 ;
struct V_7 * V_8 = ( (struct V_52 * ) V_167 ) -> V_8 ;
struct V_177 V_178 ;
int V_179 ;
F_8 ( 2 , L_5 , V_6 ) ;
V_179 = F_80 ( V_127 , V_167 , V_169 ) ;
if ( 0 != V_179 )
return V_179 ;
V_53 -> V_89 = F_1 ( V_169 -> V_89 . V_170 . V_171 ) ;
V_53 -> V_71 = V_169 -> V_89 . V_170 . V_71 ;
V_53 -> V_72 = V_169 -> V_89 . V_170 . V_72 ;
V_53 -> V_116 . V_74 = V_169 -> V_89 . V_170 . V_74 ;
F_8 ( 2 , L_25 , V_6 ,
V_53 -> V_71 , V_53 -> V_72 , V_53 -> V_116 . V_74 ) ;
F_83 ( & V_178 , & V_169 -> V_89 . V_170 , V_180 ) ;
F_15 ( V_8 , V_69 , V_181 , & V_178 ) ;
F_84 ( & V_169 -> V_89 . V_170 , & V_178 ) ;
return 0 ;
}
static int F_85 ( struct V_127 * V_127 , void * V_167 ,
struct V_182 * V_183 )
{
struct V_7 * V_8 = ( (struct V_52 * ) V_167 ) -> V_8 ;
strcpy ( V_183 -> V_184 , L_26 ) ;
F_86 ( V_183 -> V_185 , V_40 [ V_8 -> V_41 ] . V_39 ,
sizeof( V_183 -> V_185 ) ) ;
sprintf ( V_183 -> V_186 , L_27 , F_87 ( V_8 -> V_33 ) ) ;
V_183 -> V_187 =
V_188 |
V_189 |
V_190 |
V_191 ;
if ( V_108 != V_8 -> V_192 )
V_183 -> V_187 |= V_193 ;
return 0 ;
}
static int F_88 ( struct V_127 * V_127 , void * V_167 ,
struct V_194 * V_169 )
{
if ( F_89 ( V_169 -> V_195 >= F_2 ( V_4 ) ) )
return - V_47 ;
F_86 ( V_169 -> V_196 , V_4 [ V_169 -> V_195 ] . V_39 ,
sizeof( V_169 -> V_196 ) ) ;
V_169 -> V_171 = V_4 [ V_169 -> V_195 ] . V_2 ;
return 0 ;
}
static int F_90 ( struct V_127 * V_127 , void * V_167 ,
struct V_197 * V_198 )
{
struct V_52 * V_53 = V_167 ;
return F_91 ( F_54 ( V_53 ) , V_198 ) ;
}
static int F_92 ( struct V_127 * V_127 , void * V_167 ,
struct V_199 * V_198 )
{
struct V_52 * V_53 = V_167 ;
return F_93 ( F_54 ( V_53 ) , V_198 ) ;
}
static int F_94 ( struct V_127 * V_127 , void * V_167 ,
struct V_199 * V_198 )
{
struct V_52 * V_53 = V_167 ;
return F_95 ( F_54 ( V_53 ) , V_198 ) ;
}
static int F_96 ( struct V_127 * V_127 , void * V_167 ,
struct V_199 * V_198 )
{
struct V_52 * V_53 = V_167 ;
return F_97 ( F_54 ( V_53 ) , V_198 ,
V_127 -> V_145 & V_146 ) ;
}
static int F_98 ( struct V_127 * V_127 , void * V_167 ,
enum V_129 V_3 )
{
struct V_52 * V_53 = V_167 ;
struct V_7 * V_8 = V_53 -> V_8 ;
F_8 ( 1 , L_5 , V_6 ) ;
if ( F_89 ( V_53 -> type != V_122 ) )
return - V_47 ;
if ( F_89 ( V_3 != V_53 -> type ) )
return - V_47 ;
if ( F_89 ( ! F_20 ( V_8 , V_53 , F_55 ( V_53 ) ) ) )
return - V_144 ;
return F_99 ( F_54 ( V_53 ) ) ;
}
static int F_100 ( struct V_127 * V_127 , void * V_167 , enum V_129 V_3 )
{
struct V_52 * V_53 = V_167 ;
struct V_7 * V_8 = V_53 -> V_8 ;
int V_179 , V_200 ;
F_8 ( 1 , L_5 , V_6 ) ;
if ( V_53 -> type != V_122 )
return - V_47 ;
if ( V_3 != V_53 -> type )
return - V_47 ;
V_200 = F_55 ( V_53 ) ;
V_179 = F_71 ( F_54 ( V_53 ) ) ;
if ( V_179 < 0 )
return V_179 ;
F_25 ( V_8 , V_53 , V_200 ) ;
return 0 ;
}
static int F_101 ( struct V_127 * V_127 , void * V_167 , T_2 * V_201 )
{
struct V_7 * V_8 = ( (struct V_52 * ) V_167 ) -> V_8 ;
F_8 ( 1 , L_5 , V_6 ) ;
F_21 ( & V_8 -> V_56 ) ;
F_13 ( V_8 , * V_201 ) ;
F_22 ( & V_8 -> V_56 ) ;
return 0 ;
}
static int F_102 ( struct V_7 * V_8 , struct V_202 * V_3 )
{
static const char * V_203 [] = {
[ V_204 ] = L_28 ,
[ V_205 ] = L_29 ,
[ V_206 ] = L_30 ,
[ V_207 ] = L_31 ,
[ V_208 ] = L_32 ,
[ V_209 ] = L_33 ,
[ V_66 ] = L_34 ,
[ V_210 ] = L_35 ,
[ V_211 ] = L_36 ,
[ V_212 ] = L_37 ,
} ;
unsigned int V_213 ;
F_8 ( 1 , L_5 , V_6 ) ;
V_213 = V_3 -> V_195 ;
if ( V_213 >= 4 )
return - V_47 ;
if ( 0 == F_28 ( V_213 ) -> type )
return - V_47 ;
V_3 -> V_195 = V_213 ;
V_3 -> type = V_214 ;
strcpy ( V_3 -> V_39 , V_203 [ F_28 ( V_213 ) -> type ] ) ;
if ( ( V_66 == F_28 ( V_213 ) -> type ) ||
( V_210 == F_28 ( V_213 ) -> type ) ) {
V_3 -> type = V_215 ;
V_3 -> V_216 = V_217 ;
}
return 0 ;
}
static int F_103 ( struct V_127 * V_127 , void * V_167 ,
struct V_202 * V_3 )
{
struct V_7 * V_8 = ( (struct V_52 * ) V_167 ) -> V_8 ;
F_8 ( 1 , L_5 , V_6 ) ;
return F_102 ( V_8 , V_3 ) ;
}
static int F_104 ( struct V_127 * V_127 , void * V_167 , unsigned int * V_3 )
{
struct V_7 * V_8 = ( (struct V_52 * ) V_167 ) -> V_8 ;
* V_3 = V_8 -> V_58 ;
F_8 ( 1 , L_38 , V_6 , * V_3 ) ;
return 0 ;
}
static int F_105 ( struct V_127 * V_127 , void * V_167 , unsigned int V_3 )
{
struct V_7 * V_8 = ( (struct V_52 * ) V_167 ) -> V_8 ;
F_8 ( 1 , L_39 , V_6 , V_3 ) ;
if ( V_3 >= 4 ) {
F_8 ( 1 , L_40 , V_6 ) ;
return - V_47 ;
}
F_21 ( & V_8 -> V_56 ) ;
F_27 ( V_8 , V_3 ) ;
F_22 ( & V_8 -> V_56 ) ;
return 0 ;
}
static int F_106 ( struct V_127 * V_127 , void * V_167 )
{
struct V_52 * V_53 = V_167 ;
struct V_7 * V_8 = V_53 -> V_8 ;
F_3 ( V_218
L_41 ,
V_8 -> V_39 ) ;
F_15 ( V_8 , V_29 , V_219 ) ;
F_3 ( V_218
L_42 ,
V_8 -> V_39 ) ;
return 0 ;
}
static int F_107 ( struct V_127 * V_127 , void * V_167 ,
struct V_42 * V_43 )
{
V_43 -> V_44 = F_108 ( V_220 , V_43 -> V_44 ) ;
if ( F_89 ( V_43 -> V_44 == 0 ) )
return - V_47 ;
return F_19 ( V_43 ) ;
}
static int F_109 ( struct V_127 * V_127 , void * V_167 ,
struct V_161 * V_162 )
{
struct V_7 * V_8 = ( (struct V_52 * ) V_167 ) -> V_8 ;
return F_76 ( V_8 , V_162 ) ;
}
static int F_110 ( struct V_127 * V_127 , void * V_167 ,
struct V_161 * V_162 )
{
struct V_7 * V_8 = ( (struct V_52 * ) V_167 ) -> V_8 ;
return F_77 ( V_8 , V_162 ) ;
}
static int F_111 ( struct V_127 * V_127 , void * V_167 ,
struct V_221 * V_222 )
{
struct V_7 * V_8 = ( (struct V_52 * ) V_167 ) -> V_8 ;
if ( F_89 ( V_108 == V_8 -> V_192 ) )
return - V_47 ;
if ( 0 != V_222 -> V_195 )
return - V_47 ;
strcpy ( V_222 -> V_39 , L_34 ) ;
V_222 -> type = V_223 ;
V_222 -> V_224 = V_225 ;
V_222 -> V_226 = 0xffffffffUL ;
V_222 -> signal = 0xffff ;
return 0 ;
}
static int F_112 ( struct V_127 * V_127 , void * V_167 ,
struct V_221 * V_222 )
{
struct V_7 * V_8 = ( (struct V_52 * ) V_167 ) -> V_8 ;
if ( V_108 == V_8 -> V_192 )
return - V_47 ;
if ( 0 != V_222 -> V_195 )
return - V_47 ;
return 0 ;
}
static int F_113 ( struct V_127 * V_127 , void * V_167 ,
struct V_227 * V_169 )
{
struct V_52 * V_53 = V_167 ;
struct V_7 * V_8 = V_53 -> V_8 ;
if ( F_89 ( V_108 == V_8 -> V_192 ) )
return - V_47 ;
V_169 -> type = V_53 -> V_130 ? V_228 : V_223 ;
V_169 -> V_229 = V_8 -> V_230 ;
F_15 ( V_8 , V_231 , V_232 , V_169 ) ;
return 0 ;
}
static int F_114 ( struct V_7 * V_8 , struct V_227 * V_169 )
{
if ( F_89 ( V_108 == V_8 -> V_192 ) )
return - V_47 ;
if ( F_89 ( V_169 -> V_231 != 0 ) )
return - V_47 ;
F_21 ( & V_8 -> V_56 ) ;
V_8 -> V_230 = V_169 -> V_229 ;
F_15 ( V_8 , V_231 , V_233 , V_169 ) ;
F_115 ( 10 ) ;
F_22 ( & V_8 -> V_56 ) ;
return 0 ;
}
static int F_116 ( struct V_127 * V_127 , void * V_167 ,
struct V_227 * V_169 )
{
struct V_52 * V_53 = V_167 ;
struct V_7 * V_8 = V_53 -> V_8 ;
if ( F_89 ( 0 == V_53 -> V_130 && V_169 -> type != V_223 ) )
return - V_47 ;
if ( F_89 ( 1 == V_53 -> V_130 && V_169 -> type != V_228 ) )
return - V_47 ;
return
F_114 ( V_8 , V_169 ) ;
}
static void F_117 ( unsigned long V_142 )
{
struct V_7 * V_8 = (struct V_7 * ) V_142 ;
struct V_9 * V_10 = & V_8 -> V_116 ;
struct V_12 * V_13 ;
unsigned long V_234 ;
F_118 ( V_8 , & V_8 -> V_75 [ V_76 ] ) ;
F_119 ( V_83 , 0x11 ) ;
F_120 ( & V_8 -> V_141 , V_234 ) ;
while ( ! F_5 ( & V_10 -> V_15 ) ) {
V_13 = F_6 ( V_10 -> V_15 . V_16 ,
struct V_12 , V_17 . V_18 ) ;
F_9 ( & V_13 -> V_17 . V_18 ) ;
V_13 -> V_17 . V_21 = V_153 ;
F_10 ( & V_13 -> V_17 . V_23 ) ;
F_3 ( V_5 L_43 ,
V_8 -> V_39 , V_13 , V_13 -> V_17 . V_3 ,
( unsigned long ) V_13 -> V_78 . V_79 ) ;
}
F_37 ( V_8 , V_10 ) ;
F_121 ( & V_8 -> V_141 , V_234 ) ;
}
int F_122 ( struct V_7 * V_8 , T_1 V_235 )
{
T_1 V_236 , V_11 ;
int V_237 = 0 ;
V_236 = F_123 ( V_81 ) ;
if ( 0 == ( V_235 & V_236 ) )
return V_237 ;
F_34 ( V_238 , V_235 ) ;
F_8 ( 2 , L_44 , V_6 , V_235 ) ;
if ( V_235 & ( 1 << 16 ) ) {
F_3 ( V_239 L_45 ,
V_8 -> V_39 ) ;
F_119 ( V_83 , 0x11 ) ;
F_118 ( V_8 , & V_8 -> V_75 [ V_76 ] ) ;
}
if ( V_235 & 0x01 ) {
F_124 ( & V_8 -> V_141 ) ;
V_11 = F_123 ( V_240 ) ;
F_4 ( V_8 , & V_8 -> V_116 , V_11 ) ;
F_125 ( & V_8 -> V_141 ) ;
V_237 ++ ;
}
if ( V_235 & 0x10 ) {
F_8 ( 2 , L_46 ) ;
F_124 ( & V_8 -> V_141 ) ;
F_37 ( V_8 , & V_8 -> V_116 ) ;
F_125 ( & V_8 -> V_141 ) ;
V_237 ++ ;
}
return V_237 ;
}
void F_126 ( struct V_7 * V_8 )
{
F_8 ( 1 , L_5 , V_6 ) ;
F_127 ( V_8 , 0x01 ) ;
if ( V_8 -> V_241 ) {
if ( F_128 ( V_8 -> V_241 ) )
F_129 ( V_8 -> V_241 ) ;
else
V_38 ( V_8 -> V_241 ) ;
V_8 -> V_241 = NULL ;
F_130 ( V_8 -> V_33 , & V_8 -> V_116 . V_120 ) ;
}
}
int F_131 ( struct V_7 * V_8 )
{
int V_179 ;
F_8 ( 1 , L_5 , V_6 ) ;
F_132 ( & V_8 -> V_141 ) ;
memcpy ( & V_242 , & V_243 ,
sizeof( V_242 ) ) ;
strcpy ( V_242 . V_39 , L_47 ) ;
V_8 -> V_28 = V_243 . V_244 ;
F_133 ( & V_8 -> V_116 . V_15 ) ;
F_133 ( & V_8 -> V_116 . V_87 ) ;
V_8 -> V_116 . V_24 . V_245 = F_117 ;
V_8 -> V_116 . V_24 . V_142 = ( unsigned long ) V_8 ;
F_134 ( & V_8 -> V_116 . V_24 ) ;
F_135 ( V_8 -> V_33 , & V_8 -> V_116 . V_120 ,
V_83 , 0x11 , 0x00 ) ;
F_35 ( V_8 , 0x01 ) ;
if ( ( V_246 != V_8 -> V_192 ) &&
( ( V_8 -> V_247 == 0 ) || ( V_8 -> V_247 == 1 ) ) ) {
struct V_248 * V_249 = NULL ;
if ( V_8 -> V_250 )
V_249 = F_136 ( & V_8 -> V_36 ,
& V_8 -> V_251 [ V_8 -> V_247 ] . V_252 ,
L_48 , V_8 -> V_250 , NULL ) ;
else
V_249 = F_136 ( & V_8 -> V_36 ,
& V_8 -> V_251 [ V_8 -> V_247 ] . V_252 ,
L_48 , 0 , F_137 ( V_253 ) ) ;
if ( V_249 ) {
struct V_254 V_255 ;
memset ( & V_255 , 0 , sizeof( V_255 ) ) ;
V_255 . V_256 = V_257 ;
V_255 . type = V_8 -> V_192 ;
V_255 . V_258 = F_138 ( V_249 ) ;
V_255 . V_259 = V_260 ;
F_30 ( V_249 , V_231 , V_261 , & V_255 ) ;
if ( V_8 -> V_41 == V_262 ) {
struct V_263 V_164 = {
. V_264 = V_265 ,
. V_266 = 64
} ;
struct V_267 V_268 = {
. V_231 = V_8 -> V_192 ,
. V_167 = & V_164
} ;
F_30 ( V_249 , V_231 , V_269 , & V_268 ) ;
}
}
}
V_8 -> V_241 = F_16 ( V_8 , V_8 -> V_33 ,
& V_243 , L_49 ) ;
V_179 = F_139 ( V_8 -> V_241 , V_132 ,
V_270 [ V_8 -> V_271 ] ) ;
if ( V_179 < 0 ) {
F_3 ( V_218 L_50 ,
V_8 -> V_39 ) ;
goto V_272;
}
F_3 ( V_218 L_51 ,
V_8 -> V_39 , F_59 ( V_8 -> V_241 ) ) ;
F_21 ( & V_8 -> V_56 ) ;
F_13 ( V_8 , V_8 -> V_28 ) ;
F_78 ( V_8 ) ;
F_27 ( V_8 , 0 ) ;
F_22 ( & V_8 -> V_56 ) ;
return 0 ;
V_272:
F_126 ( V_8 ) ;
return V_179 ;
}
