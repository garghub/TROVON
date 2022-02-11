static struct V_1 * F_1 ( unsigned int V_2 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ )
if ( V_4 [ V_3 ] . V_2 == V_2 )
return V_4 + V_3 ;
F_3 ( V_5 L_1 , V_6 ,
( V_2 & 0xff ) ,
( ( V_2 >> 8 ) & 0xff ) ,
( ( V_2 >> 16 ) & 0xff ) ,
( ( V_2 >> 24 ) & 0xff )
) ;
return NULL ;
}
void F_4 ( struct V_7 * V_8 ,
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
int F_13 ( struct V_7 * V_8 , T_2 V_27 )
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
V_40 [ V_8 -> V_41 ] . V_39 , type ) ;
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
static int F_27 ( struct V_7 * V_8 , T_3 V_58 , T_3 V_59 )
{
T_3 V_13 [] = { V_58 , V_59 } ;
struct V_60 V_61 = { . V_62 = 0x98 >> 1 ,
. V_63 = 0 , . V_13 = V_13 , . V_64 = 2 } ;
return F_28 ( & V_8 -> V_65 [ 2 ] . V_66 , & V_61 , 1 ) ;
}
static T_3 F_29 ( struct V_7 * V_8 , T_3 V_58 )
{
int V_67 ;
T_3 V_68 [] = { V_58 } ;
T_3 V_69 [] = { 0 } ;
struct V_60 V_61 [] = {
{ . V_62 = 0x98 >> 1 , . V_63 = 0 , . V_13 = V_68 , . V_64 = 1 } ,
{ . V_62 = 0x98 >> 1 , . V_63 = V_70 , . V_13 = V_69 , . V_64 = 1 }
} ;
V_67 = F_28 ( & V_8 -> V_65 [ 2 ] . V_66 , & V_61 [ 0 ] , 2 ) ;
if ( V_67 != 2 )
F_3 ( V_5 L_9 , V_6 ) ;
return V_69 [ 0 ] ;
}
static void F_30 ( struct V_7 * V_8 )
{
int V_3 ;
F_8 ( 1 , L_10 ) ;
for ( V_3 = 0 ; V_3 < 0x24 ; V_3 ++ ) {
F_8 ( 1 , L_11 , V_3 ,
F_29 ( V_8 , V_3 ) ) ;
}
}
static int F_31 ( struct V_7 * V_8 , int V_71 )
{
T_3 V_72 ;
F_8 ( 1 , L_12 , V_6 , V_71 ) ;
if ( V_71 == 1 )
V_72 = F_29 ( V_8 , V_73 ) & ~ V_74 ;
else if ( V_71 == 2 )
V_72 = F_29 ( V_8 , V_73 ) | V_74 ;
else
return - V_47 ;
V_72 |= 0x20 ;
F_27 ( V_8 , V_73 , V_72 ) ;
F_27 ( V_8 , V_75 , 0 ) ;
if ( V_76 )
F_30 ( V_8 ) ;
return 0 ;
}
static int F_32 ( struct V_7 * V_8 , unsigned int V_71 )
{
F_8 ( 1 , L_13 ,
V_6 ,
V_71 , F_33 ( V_71 ) -> V_77 ,
F_33 ( V_71 ) -> V_78 , F_33 ( V_71 ) -> V_79 ,
F_33 ( V_71 ) -> V_80 , F_33 ( V_71 ) -> V_81 ) ;
V_8 -> V_71 = V_71 ;
if ( V_8 -> V_41 == V_82 ||
V_8 -> V_41 == V_83 ||
V_8 -> V_41 == V_84 ) {
if ( F_33 ( V_71 ) -> type == V_85 )
F_34 ( V_8 , V_86 ) ;
}
F_35 ( V_8 -> V_87 , V_88 , V_89 ,
F_33 ( V_71 ) -> V_77 , 0 , 0 ) ;
if ( ( V_8 -> V_41 == V_90 ) ||
( V_8 -> V_41 == V_91 ) ||
( V_8 -> V_41 == V_92 ) ||
( V_8 -> V_41 == V_93 ) ||
( V_8 -> V_41 == V_94 ) ||
( V_8 -> V_41 == V_95 ) ||
( V_8 -> V_41 == V_84 ) ) {
F_35 ( V_8 -> V_87 , V_96 , V_89 ,
F_33 ( V_71 ) -> V_97 , 0 , 0 ) ;
if ( F_33 ( V_71 ) -> V_97 == V_98 )
F_31 ( V_8 , 1 ) ;
else if ( F_33 ( V_71 ) -> V_97 == V_99 )
F_31 ( V_8 , 2 ) ;
}
return 0 ;
}
static int F_36 ( struct V_7 * V_8 , unsigned int V_71 )
{
F_8 ( 1 , L_14 , V_6 , V_71 ) ;
if ( F_33 ( V_71 ) -> V_97 == V_98 )
F_31 ( V_8 , 1 ) ;
else if ( F_33 ( V_71 ) -> V_97 == V_99 )
F_31 ( V_8 , 2 ) ;
else {
F_31 ( V_8 , 1 ) ;
}
return 0 ;
}
static int F_37 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
struct V_12 * V_13 )
{
F_8 ( 1 , L_5 , V_6 ) ;
F_38 ( V_100 , 0x11 ) ;
F_39 ( V_8 , & V_8 -> V_101 [ V_102 ] ,
V_13 -> V_103 , V_13 -> V_104 . V_105 ) ;
F_40 ( V_106 , 3 ) ;
V_10 -> V_11 = 1 ;
F_41 ( V_8 , 0x01 ) ;
F_42 ( V_107 , 0x000011 ) ;
F_42 ( V_108 , ( 1 << 5 ) ) ;
F_42 ( V_100 , 0x11 ) ;
return 0 ;
}
static int F_43 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_12 * V_13 , * V_109 ;
struct V_110 * V_111 ;
F_8 ( 1 , L_5 , V_6 ) ;
if ( ! F_5 ( & V_10 -> V_15 ) ) {
V_13 = F_6 ( V_10 -> V_15 . V_16 , struct V_12 ,
V_17 . V_18 ) ;
F_8 ( 2 , L_15 ,
V_13 , V_13 -> V_17 . V_3 ) ;
F_37 ( V_8 , V_10 , V_13 ) ;
F_44 (item, &q->active) {
V_13 = F_6 ( V_111 , struct V_12 ,
V_17 . V_18 ) ;
V_13 -> V_11 = V_10 -> V_11 ++ ;
}
F_12 ( & V_10 -> V_24 , V_25 + V_26 ) ;
return 0 ;
}
V_109 = NULL ;
for (; ; ) {
if ( F_5 ( & V_10 -> V_112 ) )
return 0 ;
V_13 = F_6 ( V_10 -> V_112 . V_16 , struct V_12 ,
V_17 . V_18 ) ;
if ( NULL == V_109 ) {
F_45 ( & V_13 -> V_17 . V_18 , & V_10 -> V_15 ) ;
F_37 ( V_8 , V_10 , V_13 ) ;
V_13 -> V_17 . V_21 = V_113 ;
V_13 -> V_11 = V_10 -> V_11 ++ ;
F_12 ( & V_10 -> V_24 , V_25 + V_26 ) ;
F_8 ( 2 , L_16 ,
V_13 , V_13 -> V_17 . V_3 ) ;
} else if ( V_109 -> V_17 . V_114 == V_13 -> V_17 . V_114 &&
V_109 -> V_17 . V_115 == V_13 -> V_17 . V_115 &&
V_109 -> V_116 == V_13 -> V_116 ) {
F_45 ( & V_13 -> V_17 . V_18 , & V_10 -> V_15 ) ;
V_13 -> V_17 . V_21 = V_113 ;
V_13 -> V_11 = V_10 -> V_11 ++ ;
V_109 -> V_104 . V_117 [ 1 ] = F_46 ( V_13 -> V_104 . V_105 ) ;
V_109 -> V_104 . V_117 [ 2 ] = F_46 ( 0 ) ;
F_8 ( 2 , L_17 ,
V_13 , V_13 -> V_17 . V_3 ) ;
} else {
return 0 ;
}
V_109 = V_13 ;
}
}
static int F_47 ( struct V_118 * V_10 , unsigned int * V_11 ,
unsigned int * V_119 )
{
struct V_52 * V_53 = V_10 -> V_120 ;
* V_119 = V_53 -> V_116 -> V_121 * V_53 -> V_114 * V_53 -> V_115 >> 3 ;
if ( 0 == * V_11 )
* V_11 = 32 ;
if ( * V_119 * * V_11 > V_122 * 1024 * 1024 )
* V_11 = ( V_122 * 1024 * 1024 ) / * V_119 ;
return 0 ;
}
static int F_48 ( struct V_118 * V_10 , struct V_123 * V_17 ,
enum V_124 V_125 )
{
struct V_52 * V_53 = V_10 -> V_120 ;
struct V_7 * V_8 = V_53 -> V_8 ;
struct V_12 * V_13 =
F_49 ( V_17 , struct V_12 , V_17 ) ;
int V_126 , V_127 = 0 ;
T_1 V_128 , V_129 ;
struct V_130 * V_105 = F_50 ( & V_13 -> V_17 ) ;
int V_131 ;
F_26 ( NULL == V_53 -> V_116 ) ;
if ( V_53 -> V_114 < 48 || V_53 -> V_114 > F_51 ( V_8 -> V_28 ) ||
V_53 -> V_115 < 32 || V_53 -> V_115 > F_52 ( V_8 -> V_28 ) )
return - V_47 ;
V_13 -> V_17 . V_119 = ( V_53 -> V_114 * V_53 -> V_115 * V_53 -> V_116 -> V_121 ) >> 3 ;
if ( 0 != V_13 -> V_17 . V_132 && V_13 -> V_17 . V_133 < V_13 -> V_17 . V_119 )
return - V_47 ;
if ( V_13 -> V_116 != V_53 -> V_116 ||
V_13 -> V_17 . V_114 != V_53 -> V_114 ||
V_13 -> V_17 . V_115 != V_53 -> V_115 ||
V_13 -> V_17 . V_125 != V_125 ) {
V_13 -> V_116 = V_53 -> V_116 ;
V_13 -> V_17 . V_114 = V_53 -> V_114 ;
V_13 -> V_17 . V_115 = V_53 -> V_115 ;
V_13 -> V_17 . V_125 = V_125 ;
V_127 = 1 ;
}
if ( V_134 == V_13 -> V_17 . V_21 ) {
V_127 = 1 ;
V_126 = F_53 ( V_10 , & V_13 -> V_17 , NULL ) ;
if ( 0 != V_126 )
goto V_135;
}
if ( V_127 ) {
V_13 -> V_103 = V_13 -> V_17 . V_114 * V_13 -> V_116 -> V_121 >> 3 ;
switch ( V_13 -> V_17 . V_125 ) {
case V_136 :
F_54 ( V_8 -> V_33 , & V_13 -> V_104 ,
V_105 -> V_137 , 0 , V_138 ,
V_13 -> V_103 , 0 , V_13 -> V_17 . V_115 ) ;
break;
case V_139 :
F_54 ( V_8 -> V_33 , & V_13 -> V_104 ,
V_105 -> V_137 , V_138 , 0 ,
V_13 -> V_103 , 0 , V_13 -> V_17 . V_115 ) ;
break;
case V_140 :
if ( V_8 -> V_28 & V_141 )
V_131 = 1 ;
else
V_131 = 0 ;
if ( V_40 [ V_8 -> V_41 ] . V_142 )
V_131 = 0 ;
if ( V_131 ) {
F_8 ( 1 , L_18 ,
V_6 ) ;
V_128 = V_13 -> V_103 ;
V_129 = 0 ;
} else {
F_8 ( 1 , L_19 ,
V_6 ) ;
V_128 = 0 ;
V_129 = V_13 -> V_103 ;
}
F_54 ( V_8 -> V_33 , & V_13 -> V_104 ,
V_105 -> V_137 , V_128 ,
V_129 ,
V_13 -> V_103 , V_13 -> V_103 ,
V_13 -> V_17 . V_115 >> 1 ) ;
break;
case V_143 :
F_54 ( V_8 -> V_33 , & V_13 -> V_104 ,
V_105 -> V_137 ,
0 , V_13 -> V_103 * ( V_13 -> V_17 . V_115 >> 1 ) ,
V_13 -> V_103 , 0 ,
V_13 -> V_17 . V_115 >> 1 ) ;
break;
case V_144 :
F_54 ( V_8 -> V_33 , & V_13 -> V_104 ,
V_105 -> V_137 ,
V_13 -> V_103 * ( V_13 -> V_17 . V_115 >> 1 ) , 0 ,
V_13 -> V_103 , 0 ,
V_13 -> V_17 . V_115 >> 1 ) ;
break;
default:
F_55 () ;
}
}
F_8 ( 2 , L_20 ,
V_13 , V_13 -> V_17 . V_3 ,
V_53 -> V_114 , V_53 -> V_115 , V_53 -> V_116 -> V_121 , V_53 -> V_116 -> V_39 ,
( unsigned long ) V_13 -> V_104 . V_105 ) ;
V_13 -> V_17 . V_21 = V_145 ;
return 0 ;
V_135:
F_56 ( V_10 , V_13 ) ;
return V_126 ;
}
static void F_57 ( struct V_118 * V_146 , struct V_123 * V_17 )
{
struct V_12 * V_13 = F_49 ( V_17 ,
struct V_12 , V_17 ) ;
struct V_12 * V_109 ;
struct V_52 * V_53 = V_146 -> V_120 ;
struct V_7 * V_8 = V_53 -> V_8 ;
struct V_9 * V_10 = & V_8 -> V_147 ;
V_13 -> V_104 . V_117 [ 0 ] = F_46 ( V_148 | V_149 | V_150 ) ;
V_13 -> V_104 . V_117 [ 1 ] = F_46 ( V_10 -> V_151 . V_105 ) ;
V_13 -> V_104 . V_117 [ 2 ] = F_46 ( 0 ) ;
if ( ! F_5 ( & V_10 -> V_112 ) ) {
F_58 ( & V_13 -> V_17 . V_18 , & V_10 -> V_112 ) ;
V_13 -> V_17 . V_21 = V_152 ;
F_8 ( 2 , L_21 ,
V_13 , V_13 -> V_17 . V_3 ) ;
} else if ( F_5 ( & V_10 -> V_15 ) ) {
F_58 ( & V_13 -> V_17 . V_18 , & V_10 -> V_15 ) ;
F_37 ( V_8 , V_10 , V_13 ) ;
V_13 -> V_17 . V_21 = V_113 ;
V_13 -> V_11 = V_10 -> V_11 ++ ;
F_12 ( & V_10 -> V_24 , V_25 + V_26 ) ;
F_8 ( 2 , L_22 ,
V_13 , V_13 -> V_17 . V_3 ) ;
} else {
V_109 = F_6 ( V_10 -> V_15 . V_109 , struct V_12 ,
V_17 . V_18 ) ;
if ( V_109 -> V_17 . V_114 == V_13 -> V_17 . V_114 &&
V_109 -> V_17 . V_115 == V_13 -> V_17 . V_115 &&
V_109 -> V_116 == V_13 -> V_116 ) {
F_58 ( & V_13 -> V_17 . V_18 , & V_10 -> V_15 ) ;
V_13 -> V_17 . V_21 = V_113 ;
V_13 -> V_11 = V_10 -> V_11 ++ ;
V_109 -> V_104 . V_117 [ 1 ] = F_46 ( V_13 -> V_104 . V_105 ) ;
V_109 -> V_104 . V_117 [ 2 ] = F_46 ( 0 ) ;
F_8 ( 2 , L_23 ,
V_13 , V_13 -> V_17 . V_3 ) ;
} else {
F_58 ( & V_13 -> V_17 . V_18 , & V_10 -> V_112 ) ;
V_13 -> V_17 . V_21 = V_152 ;
F_8 ( 2 , L_24 ,
V_13 , V_13 -> V_17 . V_3 ) ;
}
}
}
static void F_59 ( struct V_118 * V_10 ,
struct V_123 * V_17 )
{
struct V_12 * V_13 = F_49 ( V_17 ,
struct V_12 , V_17 ) ;
F_56 ( V_10 , V_13 ) ;
}
static struct V_118 * F_60 ( struct V_52 * V_53 )
{
switch ( V_53 -> type ) {
case V_153 :
return & V_53 -> V_147 ;
case V_154 :
return & V_53 -> V_155 ;
default:
F_55 () ;
return NULL ;
}
}
static int F_61 ( struct V_52 * V_53 )
{
switch ( V_53 -> type ) {
case V_153 :
return V_156 ;
case V_154 :
return V_157 ;
default:
F_55 () ;
return 0 ;
}
}
static int F_62 ( struct V_158 * V_158 )
{
struct V_31 * V_159 = F_63 ( V_158 ) ;
struct V_7 * V_8 = F_64 ( V_158 ) ;
struct V_52 * V_53 ;
enum V_160 type = 0 ;
int V_161 = 0 ;
switch ( V_159 -> V_162 ) {
case V_163 :
type = V_153 ;
break;
case V_164 :
type = V_154 ;
break;
case V_165 :
V_161 = 1 ;
break;
}
F_8 ( 1 , L_25 ,
F_65 ( V_159 ) , V_161 , V_166 [ type ] ) ;
V_53 = F_66 ( sizeof( * V_53 ) , V_167 ) ;
if ( NULL == V_53 )
return - V_168 ;
V_158 -> V_169 = V_53 ;
V_53 -> V_8 = V_8 ;
V_53 -> V_161 = V_161 ;
V_53 -> type = type ;
V_53 -> V_114 = 320 ;
V_53 -> V_115 = 240 ;
V_53 -> V_116 = F_1 ( V_170 ) ;
F_67 ( & V_53 -> V_147 , & V_171 ,
& V_8 -> V_33 -> V_8 , & V_8 -> V_172 ,
V_153 ,
V_140 ,
sizeof( struct V_12 ) ,
V_53 , NULL ) ;
F_67 ( & V_53 -> V_155 , & V_173 ,
& V_8 -> V_33 -> V_8 , & V_8 -> V_172 ,
V_154 ,
V_143 ,
sizeof( struct V_12 ) ,
V_53 , NULL ) ;
F_8 ( 1 , L_26 ) ;
return 0 ;
}
static T_4 F_68 ( struct V_158 * V_158 , char T_5 * V_59 ,
T_6 V_11 , T_7 * V_174 )
{
struct V_52 * V_53 = V_158 -> V_169 ;
switch ( V_53 -> type ) {
case V_153 :
if ( F_24 ( V_53 -> V_8 , V_156 ) )
return - V_175 ;
return F_69 ( & V_53 -> V_147 , V_59 , V_11 , V_174 ,
V_158 -> V_176 & V_177 ) ;
case V_154 :
if ( ! F_20 ( V_53 -> V_8 , V_53 , V_157 ) )
return - V_175 ;
return F_70 ( & V_53 -> V_155 , V_59 , V_11 , V_174 , 1 ,
V_158 -> V_176 & V_177 ) ;
default:
F_55 () ;
return 0 ;
}
}
static unsigned int F_71 ( struct V_158 * V_158 ,
struct V_178 * V_179 )
{
struct V_52 * V_53 = V_158 -> V_169 ;
struct V_12 * V_13 ;
unsigned int V_126 = V_180 ;
if ( V_154 == V_53 -> type ) {
if ( ! F_20 ( V_53 -> V_8 , V_53 , V_157 ) )
return V_180 ;
return F_72 ( V_158 , & V_53 -> V_155 , V_179 ) ;
}
F_21 ( & V_53 -> V_147 . V_181 ) ;
if ( F_23 ( V_53 , V_156 ) ) {
if ( F_5 ( & V_53 -> V_147 . V_182 ) )
goto V_23;
V_13 = F_6 ( V_53 -> V_147 . V_182 . V_16 ,
struct V_12 , V_17 . V_182 ) ;
} else {
V_13 = (struct V_12 * ) V_53 -> V_147 . V_183 ;
if ( NULL == V_13 )
goto V_23;
}
F_73 ( V_158 , & V_13 -> V_17 . V_23 , V_179 ) ;
if ( V_13 -> V_17 . V_21 == V_22 ||
V_13 -> V_17 . V_21 == V_184 )
V_126 = V_185 | V_186 ;
else
V_126 = 0 ;
V_23:
F_22 ( & V_53 -> V_147 . V_181 ) ;
return V_126 ;
}
static int F_74 ( struct V_158 * V_158 )
{
struct V_52 * V_53 = V_158 -> V_169 ;
struct V_7 * V_8 = V_53 -> V_8 ;
if ( F_23 ( V_53 , V_187 ) ) {
F_25 ( V_8 , V_53 , V_187 ) ;
}
if ( F_23 ( V_53 , V_156 ) ) {
F_75 ( & V_53 -> V_147 ) ;
F_25 ( V_8 , V_53 , V_156 ) ;
}
if ( V_53 -> V_147 . V_183 ) {
F_59 ( & V_53 -> V_147 , V_53 -> V_147 . V_183 ) ;
F_76 ( V_53 -> V_147 . V_183 ) ;
}
if ( F_23 ( V_53 , V_157 ) ) {
if ( V_53 -> V_155 . V_188 )
F_77 ( & V_53 -> V_155 ) ;
if ( V_53 -> V_155 . V_189 )
F_78 ( & V_53 -> V_155 ) ;
F_25 ( V_8 , V_53 , V_157 ) ;
}
F_79 ( & V_53 -> V_147 ) ;
F_79 ( & V_53 -> V_155 ) ;
V_158 -> V_169 = NULL ;
F_76 ( V_53 ) ;
return 0 ;
}
static int F_80 ( struct V_158 * V_158 , struct V_190 * V_191 )
{
struct V_52 * V_53 = V_158 -> V_169 ;
return F_81 ( F_60 ( V_53 ) , V_191 ) ;
}
int F_82 ( struct V_7 * V_8 ,
struct V_192 * V_193 )
{
F_8 ( 1 , L_27 , V_6 ) ;
F_15 ( V_8 , V_29 , V_194 , V_193 ) ;
return 0 ;
}
int F_83 ( struct V_7 * V_8 ,
struct V_192 * V_193 )
{
F_8 ( 1 , L_28 , V_6 ) ;
F_15 ( V_8 , V_29 , V_195 , V_193 ) ;
return 0 ;
}
static void F_84 ( struct V_7 * V_8 )
{
struct V_192 V_196 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_48 ; V_3 ++ ) {
V_196 . V_44 = V_49 [ V_3 ] . V_50 . V_44 ;
V_196 . V_197 = V_49 [ V_3 ] . V_50 . V_198 ;
F_83 ( V_8 , & V_196 ) ;
}
}
static int F_85 ( struct V_158 * V_158 , void * V_199 ,
struct V_200 * V_201 )
{
struct V_52 * V_53 = V_199 ;
V_201 -> V_116 . V_202 . V_114 = V_53 -> V_114 ;
V_201 -> V_116 . V_202 . V_115 = V_53 -> V_115 ;
V_201 -> V_116 . V_202 . V_125 = V_53 -> V_147 . V_125 ;
V_201 -> V_116 . V_202 . V_203 = V_53 -> V_116 -> V_2 ;
V_201 -> V_116 . V_202 . V_204 =
( V_201 -> V_116 . V_202 . V_114 * V_53 -> V_116 -> V_121 ) >> 3 ;
V_201 -> V_116 . V_202 . V_205 =
V_201 -> V_116 . V_202 . V_115 * V_201 -> V_116 . V_202 . V_204 ;
return 0 ;
}
static int F_86 ( struct V_158 * V_158 , void * V_199 ,
struct V_200 * V_201 )
{
struct V_7 * V_8 = ( (struct V_52 * ) V_199 ) -> V_8 ;
struct V_1 * V_116 ;
enum V_124 V_125 ;
unsigned int V_206 , V_207 ;
V_116 = F_1 ( V_201 -> V_116 . V_202 . V_203 ) ;
if ( NULL == V_116 )
return - V_47 ;
V_125 = V_201 -> V_116 . V_202 . V_125 ;
V_206 = F_51 ( V_8 -> V_28 ) ;
V_207 = F_52 ( V_8 -> V_28 ) ;
if ( V_208 == V_125 ) {
V_125 = ( V_201 -> V_116 . V_202 . V_115 > V_207 / 2 )
? V_140
: V_139 ;
}
switch ( V_125 ) {
case V_136 :
case V_139 :
V_207 = V_207 / 2 ;
break;
case V_140 :
break;
default:
return - V_47 ;
}
V_201 -> V_116 . V_202 . V_125 = V_125 ;
F_87 ( & V_201 -> V_116 . V_202 . V_114 , 48 , V_206 , 2 ,
& V_201 -> V_116 . V_202 . V_115 , 32 , V_207 , 0 , 0 ) ;
V_201 -> V_116 . V_202 . V_204 =
( V_201 -> V_116 . V_202 . V_114 * V_116 -> V_121 ) >> 3 ;
V_201 -> V_116 . V_202 . V_205 =
V_201 -> V_116 . V_202 . V_115 * V_201 -> V_116 . V_202 . V_204 ;
return 0 ;
}
static int F_88 ( struct V_158 * V_158 , void * V_199 ,
struct V_200 * V_201 )
{
struct V_52 * V_53 = V_199 ;
struct V_7 * V_8 = ( (struct V_52 * ) V_199 ) -> V_8 ;
struct V_209 V_210 ;
int V_211 ;
F_8 ( 2 , L_5 , V_6 ) ;
V_211 = F_86 ( V_158 , V_199 , V_201 ) ;
if ( 0 != V_211 )
return V_211 ;
V_53 -> V_116 = F_1 ( V_201 -> V_116 . V_202 . V_203 ) ;
V_53 -> V_114 = V_201 -> V_116 . V_202 . V_114 ;
V_53 -> V_115 = V_201 -> V_116 . V_202 . V_115 ;
V_53 -> V_147 . V_125 = V_201 -> V_116 . V_202 . V_125 ;
F_8 ( 2 , L_29 , V_6 ,
V_53 -> V_114 , V_53 -> V_115 , V_53 -> V_147 . V_125 ) ;
F_89 ( & V_210 , & V_201 -> V_116 . V_202 , V_212 ) ;
F_15 ( V_8 , V_88 , V_213 , & V_210 ) ;
F_90 ( & V_201 -> V_116 . V_202 , & V_210 ) ;
return 0 ;
}
static int F_91 ( struct V_158 * V_158 , void * V_199 ,
struct V_214 * V_215 )
{
struct V_7 * V_8 = ( (struct V_52 * ) V_199 ) -> V_8 ;
strcpy ( V_215 -> V_216 , L_30 ) ;
F_92 ( V_215 -> V_217 , V_40 [ V_8 -> V_41 ] . V_39 ,
sizeof( V_215 -> V_217 ) ) ;
sprintf ( V_215 -> V_218 , L_31 , F_93 ( V_8 -> V_33 ) ) ;
V_215 -> V_219 =
V_220 |
V_221 |
V_222 |
V_223 ;
if ( V_138 != V_8 -> V_224 )
V_215 -> V_219 |= V_225 ;
return 0 ;
}
static int F_94 ( struct V_158 * V_158 , void * V_199 ,
struct V_226 * V_201 )
{
if ( F_95 ( V_201 -> V_227 >= F_2 ( V_4 ) ) )
return - V_47 ;
F_92 ( V_201 -> V_228 , V_4 [ V_201 -> V_227 ] . V_39 ,
sizeof( V_201 -> V_228 ) ) ;
V_201 -> V_203 = V_4 [ V_201 -> V_227 ] . V_2 ;
return 0 ;
}
static int F_96 ( struct V_158 * V_158 , void * V_199 ,
struct V_229 * V_230 )
{
struct V_52 * V_53 = V_199 ;
return F_97 ( F_60 ( V_53 ) , V_230 ) ;
}
static int F_98 ( struct V_158 * V_158 , void * V_199 ,
struct V_231 * V_230 )
{
struct V_52 * V_53 = V_199 ;
return F_99 ( F_60 ( V_53 ) , V_230 ) ;
}
static int F_100 ( struct V_158 * V_158 , void * V_199 ,
struct V_231 * V_230 )
{
struct V_52 * V_53 = V_199 ;
return F_101 ( F_60 ( V_53 ) , V_230 ) ;
}
static int F_102 ( struct V_158 * V_158 , void * V_199 ,
struct V_231 * V_230 )
{
struct V_52 * V_53 = V_199 ;
return F_103 ( F_60 ( V_53 ) , V_230 ,
V_158 -> V_176 & V_177 ) ;
}
static int F_104 ( struct V_158 * V_158 , void * V_199 ,
enum V_160 V_3 )
{
struct V_52 * V_53 = V_199 ;
struct V_7 * V_8 = V_53 -> V_8 ;
F_8 ( 1 , L_5 , V_6 ) ;
if ( ( V_53 -> type != V_153 ) &&
( V_53 -> type != V_154 ) )
return - V_47 ;
if ( F_95 ( V_3 != V_53 -> type ) )
return - V_47 ;
if ( F_95 ( ! F_20 ( V_8 , V_53 , F_61 ( V_53 ) ) ) )
return - V_175 ;
if ( ( V_53 -> type == V_154 ) &&
( ( F_105 ( V_100 ) & 0x11 ) == 0 ) )
return - V_47 ;
return F_106 ( F_60 ( V_53 ) ) ;
}
static int F_107 ( struct V_158 * V_158 , void * V_199 , enum V_160 V_3 )
{
struct V_52 * V_53 = V_199 ;
struct V_7 * V_8 = V_53 -> V_8 ;
int V_211 , V_232 ;
F_8 ( 1 , L_5 , V_6 ) ;
if ( ( V_53 -> type != V_153 ) &&
( V_53 -> type != V_154 ) )
return - V_47 ;
if ( V_3 != V_53 -> type )
return - V_47 ;
V_232 = F_61 ( V_53 ) ;
V_211 = F_77 ( F_60 ( V_53 ) ) ;
if ( V_211 < 0 )
return V_211 ;
F_25 ( V_8 , V_53 , V_232 ) ;
return 0 ;
}
static int F_108 ( struct V_158 * V_158 , void * V_199 , T_2 * V_44 )
{
struct V_7 * V_8 = ( (struct V_52 * ) V_199 ) -> V_8 ;
F_8 ( 1 , L_5 , V_6 ) ;
F_15 ( V_8 , V_29 , V_233 , V_44 ) ;
return 0 ;
}
static int F_109 ( struct V_158 * V_158 , void * V_199 , T_2 * V_234 )
{
struct V_7 * V_8 = ( (struct V_52 * ) V_199 ) -> V_8 ;
F_8 ( 1 , L_5 , V_6 ) ;
F_21 ( & V_8 -> V_56 ) ;
F_13 ( V_8 , * V_234 ) ;
F_22 ( & V_8 -> V_56 ) ;
return 0 ;
}
int F_110 ( struct V_7 * V_8 , struct V_235 * V_3 )
{
static const char * V_236 [] = {
[ V_237 ] = L_32 ,
[ V_238 ] = L_33 ,
[ V_239 ] = L_34 ,
[ V_240 ] = L_35 ,
[ V_241 ] = L_36 ,
[ V_242 ] = L_37 ,
[ V_85 ] = L_38 ,
[ V_243 ] = L_39 ,
[ V_244 ] = L_40 ,
[ V_245 ] = L_41 ,
} ;
unsigned int V_246 ;
F_8 ( 1 , L_5 , V_6 ) ;
V_246 = V_3 -> V_227 ;
if ( V_246 >= V_247 )
return - V_47 ;
if ( 0 == F_33 ( V_246 ) -> type )
return - V_47 ;
V_3 -> V_227 = V_246 ;
V_3 -> type = V_248 ;
strcpy ( V_3 -> V_39 , V_236 [ F_33 ( V_246 ) -> type ] ) ;
if ( ( V_85 == F_33 ( V_246 ) -> type ) ||
( V_243 == F_33 ( V_246 ) -> type ) ) {
V_3 -> type = V_249 ;
V_3 -> V_250 = V_251 ;
}
if ( F_33 ( V_246 ) -> type != V_85 )
V_3 -> V_252 = 0x3 ;
if ( V_8 -> V_71 == V_246 ) {
F_15 ( V_8 , V_88 , V_253 , & V_3 -> V_254 ) ;
}
return 0 ;
}
static int F_111 ( struct V_158 * V_158 , void * V_199 ,
struct V_235 * V_3 )
{
struct V_7 * V_8 = ( (struct V_52 * ) V_199 ) -> V_8 ;
F_8 ( 1 , L_5 , V_6 ) ;
return F_110 ( V_8 , V_3 ) ;
}
int F_112 ( struct V_158 * V_158 , void * V_199 , unsigned int * V_3 )
{
struct V_7 * V_8 = ( (struct V_52 * ) V_199 ) -> V_8 ;
* V_3 = V_8 -> V_71 ;
F_8 ( 1 , L_42 , V_6 , * V_3 ) ;
return 0 ;
}
static int F_113 ( struct V_158 * V_158 , void * V_199 , unsigned int * V_3 )
{
return F_112 ( V_158 , V_199 , V_3 ) ;
}
int F_114 ( struct V_158 * V_158 , void * V_199 , unsigned int V_3 )
{
struct V_7 * V_8 = ( (struct V_52 * ) V_199 ) -> V_8 ;
F_8 ( 1 , L_43 , V_6 , V_3 ) ;
if ( V_3 >= V_247 ) {
F_8 ( 1 , L_44 , V_6 ) ;
return - V_47 ;
}
if ( F_33 ( V_3 ) -> type == 0 )
return - V_47 ;
F_21 ( & V_8 -> V_56 ) ;
F_32 ( V_8 , V_3 ) ;
F_36 ( V_8 , V_3 ) ;
F_22 ( & V_8 -> V_56 ) ;
return 0 ;
}
static int F_115 ( struct V_158 * V_158 , void * V_199 , unsigned int V_3 )
{
return F_114 ( V_158 , V_199 , V_3 ) ;
}
static int F_116 ( struct V_158 * V_158 , void * V_199 )
{
struct V_52 * V_53 = V_199 ;
struct V_7 * V_8 = V_53 -> V_8 ;
F_3 ( V_255
L_45 ,
V_8 -> V_39 ) ;
F_15 ( V_8 , V_29 , V_256 ) ;
F_3 ( V_255
L_46 ,
V_8 -> V_39 ) ;
return 0 ;
}
static int F_117 ( struct V_158 * V_158 , void * V_199 ,
struct V_257 * V_3 )
{
struct V_7 * V_8 = ( (struct V_52 * ) V_199 ) -> V_8 ;
static const char * V_236 [] = {
[ 0 ] = L_47 ,
[ 1 ] = L_48 ,
} ;
unsigned int V_246 ;
F_8 ( 1 , L_5 , V_6 ) ;
V_246 = V_3 -> V_227 ;
if ( V_246 >= 2 )
return - V_47 ;
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
V_3 -> V_227 = V_246 ;
strcpy ( V_3 -> V_39 , V_236 [ V_246 ] ) ;
V_3 -> V_258 = V_259 ;
V_3 -> V_260 = V_261 ;
return 0 ;
}
static int F_118 ( struct V_158 * V_158 , void * V_199 ,
struct V_257 * V_3 )
{
return F_117 ( V_158 , V_199 , V_3 ) ;
}
static int F_119 ( struct V_158 * V_158 , void * V_199 ,
struct V_257 * V_3 )
{
struct V_7 * V_8 = ( (struct V_52 * ) V_199 ) -> V_8 ;
V_3 -> V_227 = V_8 -> V_262 ;
F_8 ( 1 , L_14 , V_6 , V_3 -> V_227 ) ;
return F_117 ( V_158 , V_199 , V_3 ) ;
}
static int F_120 ( struct V_158 * V_158 , void * V_199 ,
const struct V_257 * V_3 )
{
struct V_7 * V_8 = ( (struct V_52 * ) V_199 ) -> V_8 ;
if ( V_3 -> V_227 >= 2 )
return - V_47 ;
F_8 ( 1 , L_43 , V_6 , V_3 -> V_227 ) ;
V_8 -> V_262 = V_3 -> V_227 ;
F_31 ( V_8 , V_8 -> V_262 + 1 ) ;
return 0 ;
}
static int F_121 ( struct V_158 * V_158 , void * V_199 ,
struct V_42 * V_43 )
{
V_43 -> V_44 = F_122 ( V_263 , V_43 -> V_44 ) ;
if ( F_95 ( V_43 -> V_44 == 0 ) )
return - V_47 ;
return F_19 ( V_43 ) ;
}
static int F_123 ( struct V_158 * V_158 , void * V_199 ,
struct V_192 * V_193 )
{
struct V_7 * V_8 = ( (struct V_52 * ) V_199 ) -> V_8 ;
return F_82 ( V_8 , V_193 ) ;
}
static int F_124 ( struct V_158 * V_158 , void * V_199 ,
struct V_192 * V_193 )
{
struct V_7 * V_8 = ( (struct V_52 * ) V_199 ) -> V_8 ;
return F_83 ( V_8 , V_193 ) ;
}
static int F_125 ( struct V_158 * V_158 , void * V_199 ,
struct V_264 * V_265 )
{
struct V_7 * V_8 = ( (struct V_52 * ) V_199 ) -> V_8 ;
if ( F_95 ( V_138 == V_8 -> V_224 ) )
return - V_47 ;
if ( 0 != V_265 -> V_227 )
return - V_47 ;
strcpy ( V_265 -> V_39 , L_38 ) ;
F_15 ( V_8 , V_266 , V_267 , V_265 ) ;
return 0 ;
}
static int F_126 ( struct V_158 * V_158 , void * V_199 ,
struct V_264 * V_265 )
{
struct V_7 * V_8 = ( (struct V_52 * ) V_199 ) -> V_8 ;
if ( V_138 == V_8 -> V_224 )
return - V_47 ;
if ( 0 != V_265 -> V_227 )
return - V_47 ;
F_15 ( V_8 , V_266 , V_268 , V_265 ) ;
return 0 ;
}
static int F_127 ( struct V_158 * V_158 , void * V_199 ,
struct V_269 * V_201 )
{
struct V_52 * V_53 = V_199 ;
struct V_7 * V_8 = V_53 -> V_8 ;
if ( F_95 ( V_138 == V_8 -> V_224 ) )
return - V_47 ;
V_201 -> type = V_53 -> V_161 ? V_270 : V_271 ;
V_201 -> V_272 = V_8 -> V_273 ;
F_15 ( V_8 , V_266 , V_274 , V_201 ) ;
return 0 ;
}
static int F_128 ( struct V_7 * V_8 , struct V_269 * V_201 )
{
struct V_192 V_196 ;
if ( F_95 ( V_138 == V_8 -> V_224 ) )
return - V_47 ;
if ( F_95 ( V_201 -> V_266 != 0 ) )
return - V_47 ;
F_21 ( & V_8 -> V_56 ) ;
V_8 -> V_273 = V_201 -> V_272 ;
V_196 . V_44 = V_275 ;
V_196 . V_197 = 1 ;
F_83 ( V_8 , & V_196 ) ;
F_15 ( V_8 , V_266 , V_276 , V_201 ) ;
F_129 ( 100 ) ;
V_196 . V_197 = 0 ;
F_83 ( V_8 , & V_196 ) ;
F_22 ( & V_8 -> V_56 ) ;
return 0 ;
}
static int F_130 ( struct V_7 * V_8 ,
struct V_269 * V_201 )
{
struct V_192 V_196 ;
struct V_277 * V_278 ;
struct V_279 * V_280 ;
struct V_281 V_282 = {
. V_260 = V_271 ,
. V_283 = V_284 ,
. V_250 = V_8 -> V_28 ,
. V_272 = V_201 -> V_272
} ;
F_21 ( & V_8 -> V_56 ) ;
V_8 -> V_273 = V_201 -> V_272 ;
V_196 . V_44 = V_275 ;
V_196 . V_197 = 1 ;
F_83 ( V_8 , & V_196 ) ;
F_8 ( 1 , L_49 , V_6 ,
V_282 . V_272 , V_201 -> V_266 , V_282 . V_250 ) ;
V_278 = F_131 ( & V_8 -> V_285 . V_286 , 1 ) ;
if ( ! V_278 ) {
F_22 ( & V_8 -> V_56 ) ;
return - V_47 ;
}
V_280 = V_278 -> V_287 . V_288 ;
if ( ( V_8 -> V_41 == V_95 ) ||
( V_8 -> V_41 == V_93 ) ||
( V_8 -> V_41 == V_94 ) )
V_280 = & V_8 -> V_289 . V_290 ;
if ( V_280 && V_280 -> V_291 . V_292 . V_293 ) {
F_15 ( V_8 , V_29 , V_30 , V_8 -> V_28 ) ;
V_280 -> V_291 . V_292 . V_293 ( V_280 , & V_282 ) ;
}
else
F_3 ( V_5 L_50 , V_6 ) ;
F_129 ( 100 ) ;
V_196 . V_197 = 0 ;
F_83 ( V_8 , & V_196 ) ;
F_22 ( & V_8 -> V_56 ) ;
return 0 ;
}
int F_132 ( struct V_158 * V_158 , void * V_199 ,
struct V_269 * V_201 )
{
struct V_52 * V_53 = V_199 ;
struct V_7 * V_8 = V_53 -> V_8 ;
int V_67 ;
switch ( V_8 -> V_41 ) {
case V_93 :
case V_94 :
case V_95 :
V_67 = F_130 ( V_8 , V_201 ) ;
break;
default:
V_67 = F_128 ( V_8 , V_201 ) ;
}
return V_67 ;
}
static int F_133 ( struct V_158 * V_158 , void * V_199 ,
struct V_269 * V_201 )
{
return F_132 ( V_158 , V_199 , V_201 ) ;
}
static void F_134 ( unsigned long V_59 )
{
struct V_7 * V_8 = (struct V_7 * ) V_59 ;
struct V_9 * V_10 = & V_8 -> V_147 ;
struct V_12 * V_13 ;
unsigned long V_63 ;
F_135 ( & V_8 -> V_172 , V_63 ) ;
while ( ! F_5 ( & V_10 -> V_15 ) ) {
V_13 = F_6 ( V_10 -> V_15 . V_16 ,
struct V_12 , V_17 . V_18 ) ;
F_9 ( & V_13 -> V_17 . V_18 ) ;
V_13 -> V_17 . V_21 = V_184 ;
F_10 ( & V_13 -> V_17 . V_23 ) ;
F_3 ( V_5 L_51 ,
V_8 -> V_39 , V_13 , V_13 -> V_17 . V_3 ,
( unsigned long ) V_13 -> V_104 . V_105 ) ;
}
F_43 ( V_8 , V_10 ) ;
F_136 ( & V_8 -> V_172 , V_63 ) ;
}
int F_137 ( struct V_7 * V_8 , T_1 V_254 )
{
T_1 V_294 , V_11 ;
int V_295 = 0 ;
V_294 = F_105 ( V_107 ) ;
if ( 0 == ( V_254 & V_294 ) )
return V_295 ;
F_40 ( V_296 , V_254 ) ;
if ( ( V_254 & V_297 ) ||
( V_254 & V_298 ) ||
( V_254 & V_299 ) ) {
if ( V_254 & V_297 ) {
F_8 ( 7 , L_52 ,
V_297 ) ;
F_3 ( V_300 L_53 ,
V_8 -> V_39 ) ;
F_138 ( V_8 ,
& V_8 -> V_101 [ V_102 ] ) ;
}
if ( V_254 & V_298 )
F_8 ( 7 , L_54
L_55 ,
V_298 ) ;
if ( V_254 & V_299 )
F_8 ( 7 , L_56 ,
V_299 ) ;
}
if ( V_254 & V_301 ) {
F_139 ( & V_8 -> V_172 ) ;
V_11 = F_105 ( V_302 ) ;
F_4 ( V_8 , & V_8 -> V_147 , V_11 ) ;
F_140 ( & V_8 -> V_172 ) ;
V_295 ++ ;
}
if ( V_254 & V_303 ) {
F_8 ( 2 , L_57 ) ;
F_139 ( & V_8 -> V_172 ) ;
F_43 ( V_8 , & V_8 -> V_147 ) ;
F_140 ( & V_8 -> V_172 ) ;
V_295 ++ ;
}
V_295 += F_141 ( V_8 , V_254 ) ;
return V_295 ;
}
void F_142 ( struct V_7 * V_8 )
{
F_8 ( 1 , L_5 , V_6 ) ;
F_143 ( V_8 , 0x01 ) ;
if ( V_8 -> V_304 ) {
if ( F_144 ( V_8 -> V_304 ) )
F_145 ( V_8 -> V_304 ) ;
else
V_38 ( V_8 -> V_304 ) ;
V_8 -> V_304 = NULL ;
F_146 ( V_8 -> V_33 , & V_8 -> V_155 . V_151 ) ;
}
if ( V_8 -> V_305 ) {
if ( F_144 ( V_8 -> V_305 ) )
F_145 ( V_8 -> V_305 ) ;
else
V_38 ( V_8 -> V_305 ) ;
V_8 -> V_305 = NULL ;
F_146 ( V_8 -> V_33 , & V_8 -> V_147 . V_151 ) ;
}
if ( V_8 -> V_306 )
F_147 ( V_8 ) ;
}
int F_148 ( struct V_7 * V_8 )
{
int V_211 ;
F_8 ( 1 , L_5 , V_6 ) ;
F_149 ( & V_8 -> V_172 ) ;
memcpy ( & V_307 , & V_308 ,
sizeof( V_307 ) ) ;
strcpy ( V_307 . V_39 , L_58 ) ;
V_8 -> V_28 = V_308 . V_309 ;
F_150 ( & V_8 -> V_147 . V_15 ) ;
F_150 ( & V_8 -> V_147 . V_112 ) ;
V_8 -> V_147 . V_24 . V_310 = F_134 ;
V_8 -> V_147 . V_24 . V_59 = ( unsigned long ) V_8 ;
F_151 ( & V_8 -> V_147 . V_24 ) ;
F_152 ( V_8 -> V_33 , & V_8 -> V_147 . V_151 ,
V_100 , 0x11 , 0x00 ) ;
F_150 ( & V_8 -> V_155 . V_15 ) ;
F_150 ( & V_8 -> V_155 . V_112 ) ;
V_8 -> V_155 . V_24 . V_310 = V_311 ;
V_8 -> V_155 . V_24 . V_59 = ( unsigned long ) V_8 ;
F_151 ( & V_8 -> V_155 . V_24 ) ;
F_152 ( V_8 -> V_33 , & V_8 -> V_155 . V_151 ,
V_100 , 0x22 , 0x00 ) ;
F_41 ( V_8 , 0x01 ) ;
if ( ( V_312 != V_8 -> V_224 ) &&
( ( V_8 -> V_313 == 0 ) || ( V_8 -> V_313 == 1 ) ) ) {
struct V_314 * V_315 = NULL ;
if ( V_8 -> V_316 )
V_315 = F_153 ( & V_8 -> V_36 ,
& V_8 -> V_65 [ V_8 -> V_313 ] . V_66 ,
L_59 , V_8 -> V_316 , NULL ) ;
else
V_315 = F_153 ( & V_8 -> V_36 ,
& V_8 -> V_65 [ V_8 -> V_313 ] . V_66 ,
L_59 , 0 , F_154 ( V_317 ) ) ;
if ( V_315 ) {
struct V_318 V_319 ;
memset ( & V_319 , 0 , sizeof( V_319 ) ) ;
V_319 . V_320 = V_321 ;
V_319 . type = V_8 -> V_224 ;
V_319 . V_62 = F_155 ( V_315 ) ;
V_319 . V_322 = V_323 ;
F_35 ( V_315 , V_266 , V_324 , & V_319 ) ;
if ( V_8 -> V_41 == V_325 ) {
struct V_326 V_196 = {
. V_327 = V_328 ,
. V_329 = 64
} ;
struct V_330 V_331 = {
. V_266 = V_8 -> V_224 ,
. V_199 = & V_196
} ;
F_35 ( V_315 , V_266 , V_332 , & V_331 ) ;
}
}
}
V_8 -> V_305 = F_16 ( V_8 , V_8 -> V_33 ,
& V_308 , L_60 ) ;
V_211 = F_156 ( V_8 -> V_305 , V_163 ,
V_333 [ V_8 -> V_334 ] ) ;
if ( V_211 < 0 ) {
F_3 ( V_255 L_61 ,
V_8 -> V_39 ) ;
goto V_335;
}
F_3 ( V_255 L_62 ,
V_8 -> V_39 , F_65 ( V_8 -> V_305 ) ) ;
V_8 -> V_304 = F_16 ( V_8 , V_8 -> V_33 ,
& V_307 , L_63 ) ;
V_211 = F_156 ( V_8 -> V_304 , V_164 ,
V_336 [ V_8 -> V_334 ] ) ;
if ( V_211 < 0 ) {
F_3 ( V_255 L_64 ,
V_8 -> V_39 ) ;
goto V_335;
}
F_3 ( V_255 L_65 ,
V_8 -> V_39 , F_65 ( V_8 -> V_304 ) ) ;
V_8 -> V_306 = F_157 ( V_8 ) ;
F_21 ( & V_8 -> V_56 ) ;
F_13 ( V_8 , V_8 -> V_28 ) ;
F_84 ( V_8 ) ;
F_32 ( V_8 , 0 ) ;
F_36 ( V_8 , 0 ) ;
F_22 ( & V_8 -> V_56 ) ;
return 0 ;
V_335:
F_142 ( V_8 ) ;
return V_211 ;
}
