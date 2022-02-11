static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
int V_5 ;
T_2 * V_6 = F_2 ( sizeof( * V_6 ) , V_7 ) ;
T_3 V_8 = V_9 | V_10 | V_11 ;
if ( ! V_6 )
return - V_12 ;
V_5 = F_3 ( V_2 , F_4 ( V_2 , 0 ) ,
V_13 , V_8 ,
0x0000 ,
V_3 , V_6 , sizeof( * V_6 ) , 5 * V_14 ) ;
* V_4 = F_5 ( * V_6 ) ;
F_6 ( V_6 ) ;
return V_5 ;
}
static inline int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_15 )
{
return F_3 ( V_2 ,
F_8 ( V_2 , 0 ) ,
V_16 ,
V_17 | V_10 | V_11 ,
V_15 ,
V_3 ,
NULL ,
0 ,
5 * V_14 ) ;
}
static inline int F_9 ( struct V_1 * V_18 , T_1 V_19 )
{
return F_7 ( V_18 , V_20 + V_21 + V_19 * 16 , 1 ) ;
}
static unsigned int F_10 ( struct V_22 * V_23 )
{
unsigned int V_24 = 0 ;
unsigned int V_25 = V_23 -> V_26 ;
if ( ! V_25 ) {
F_11 ( L_1 ) ;
return V_24 ;
}
switch ( V_23 -> V_27 ) {
case V_28 :
V_24 = V_29 * V_25 ;
break;
case V_30 :
if ( V_23 -> V_31 == 0 ) {
F_11 ( L_2 ) ;
V_24 = 0 ;
} else if ( V_23 -> V_31 == 0xFF ) {
V_24 = ( V_32 / V_25 ) * V_25 ;
} else {
V_24 = V_23 -> V_31 * V_25 ;
}
break;
default:
F_11 ( L_3 ) ;
break;
}
return V_24 ;
}
static int F_12 ( struct V_33 * V_34 , int V_35 )
{
struct V_36 * V_37 = F_13 ( V_34 ) ;
unsigned long V_38 ;
T_4 * V_39 ;
if ( F_14 ( ! V_34 ) ) {
F_15 ( & V_37 -> V_1 -> V_2 , L_4 ) ;
return - V_40 ;
}
if ( F_14 ( V_35 < 0 || V_35 >= V_34 -> V_41 ) ) {
F_15 ( & V_37 -> V_1 -> V_2 , L_5 ) ;
return - V_42 ;
}
V_39 = V_37 -> V_43 + V_35 ;
F_16 ( V_39 , V_38 ) ;
V_37 -> V_44 [ V_35 ] = false ;
F_17 ( V_39 , V_38 ) ;
F_18 ( & V_37 -> V_45 [ V_35 ] . V_46 ) ;
F_19 ( & V_37 -> V_47 ) ;
F_20 ( & V_37 -> V_48 [ V_35 ] ) ;
if ( V_37 -> V_49 [ V_35 ] )
V_37 -> V_49 [ V_35 ] = false ;
if ( V_37 -> V_50 [ V_35 ] . V_27 == V_51 ) {
F_21 ( & V_37 -> V_52 ) ;
F_18 ( & V_37 -> V_53 ) ;
}
F_22 ( & V_37 -> V_47 ) ;
return 0 ;
}
static int F_23 ( struct V_36 * V_37 , int V_35 , struct V_54 * V_54 )
{
struct V_22 * V_50 = & V_37 -> V_50 [ V_35 ] ;
unsigned int V_24 = F_10 ( V_50 ) ;
unsigned int V_55 , V_56 ;
T_1 V_57 , V_58 ;
if ( ! V_24 )
return - V_40 ;
V_56 = V_54 -> V_59 / V_24 ;
if ( V_56 < 1 ) {
F_24 ( & V_37 -> V_1 -> V_2 ,
L_6 ) ;
return - V_40 ;
}
for ( V_55 = 1 ; V_55 < V_56 ; V_55 ++ ) {
V_58 = ( V_56 - V_55 ) * V_32 ;
V_57 = ( V_56 - V_55 ) * V_24 ;
memmove ( V_54 -> V_60 + V_58 ,
V_54 -> V_60 + V_57 ,
V_24 ) ;
}
V_54 -> V_59 = V_56 * V_32 ;
return 0 ;
}
static int F_25 ( struct V_36 * V_37 , int V_35 ,
struct V_54 * V_54 )
{
struct V_22 * const V_50 = & V_37 -> V_50 [ V_35 ] ;
unsigned int V_24 = F_10 ( V_50 ) ;
unsigned int V_55 , V_56 ;
if ( ! V_24 )
return - V_40 ;
V_56 = V_54 -> V_61 / V_32 ;
for ( V_55 = 1 ; V_55 < V_56 ; V_55 ++ )
memmove ( V_54 -> V_60 + V_24 * V_55 ,
V_54 -> V_60 + V_32 * V_55 ,
V_24 ) ;
V_54 -> V_61 = V_24 * V_56 ;
return 0 ;
}
static void F_26 ( struct V_62 * V_62 )
{
struct V_54 * V_54 = V_62 -> V_63 ;
struct V_36 * V_37 = F_13 ( V_54 -> V_64 ) ;
unsigned int V_35 = V_54 -> V_65 ;
struct V_66 * V_2 = & V_37 -> V_1 -> V_2 ;
T_4 * V_39 = V_37 -> V_43 + V_35 ;
unsigned long V_38 ;
F_16 ( V_39 , V_38 ) ;
V_54 -> V_61 = 0 ;
V_54 -> V_67 = V_68 ;
if ( F_27 ( V_37 -> V_44 [ V_35 ] ) ) {
switch ( V_62 -> V_67 ) {
case 0 :
case - V_69 :
V_54 -> V_61 = V_62 -> V_70 ;
V_54 -> V_67 = V_71 ;
break;
case - V_72 :
F_15 ( V_2 , L_7 ) ;
V_37 -> V_44 [ V_35 ] = false ;
V_37 -> V_45 [ V_35 ] . V_73 = V_62 -> V_73 ;
F_28 ( & V_37 -> V_45 [ V_35 ] . V_46 ) ;
break;
case - V_74 :
case - V_75 :
V_54 -> V_67 = V_76 ;
break;
}
}
F_17 ( V_39 , V_38 ) ;
if ( F_27 ( V_54 -> V_77 ) )
V_54 -> V_77 ( V_54 ) ;
F_29 ( V_62 ) ;
}
static void F_30 ( struct V_62 * V_62 )
{
struct V_54 * V_54 = V_62 -> V_63 ;
struct V_36 * V_37 = F_13 ( V_54 -> V_64 ) ;
unsigned int V_35 = V_54 -> V_65 ;
struct V_66 * V_2 = & V_37 -> V_1 -> V_2 ;
T_4 * V_39 = V_37 -> V_43 + V_35 ;
unsigned long V_38 ;
F_16 ( V_39 , V_38 ) ;
V_54 -> V_61 = 0 ;
V_54 -> V_67 = V_68 ;
if ( F_27 ( V_37 -> V_44 [ V_35 ] ) ) {
switch ( V_62 -> V_67 ) {
case 0 :
case - V_69 :
V_54 -> V_61 = V_62 -> V_70 ;
V_54 -> V_67 = V_71 ;
if ( V_37 -> V_49 [ V_35 ] &&
F_25 ( V_37 , V_35 , V_54 ) ) {
V_54 -> V_61 = 0 ;
V_54 -> V_67 = V_68 ;
}
break;
case - V_72 :
F_15 ( V_2 , L_8 ) ;
V_37 -> V_44 [ V_35 ] = false ;
V_37 -> V_45 [ V_35 ] . V_73 = V_62 -> V_73 ;
F_28 ( & V_37 -> V_45 [ V_35 ] . V_46 ) ;
break;
case - V_74 :
case - V_75 :
V_54 -> V_67 = V_76 ;
break;
case - V_78 :
F_15 ( V_2 , L_9 ) ;
break;
}
}
F_17 ( V_39 , V_38 ) ;
if ( F_27 ( V_54 -> V_77 ) )
V_54 -> V_77 ( V_54 ) ;
F_29 ( V_62 ) ;
}
static int F_31 ( struct V_33 * V_34 , int V_35 ,
struct V_54 * V_54 )
{
struct V_36 * V_37 ;
struct V_22 * V_50 ;
struct V_66 * V_2 ;
int V_5 = 0 ;
struct V_62 * V_62 ;
unsigned long V_79 ;
void * V_60 ;
if ( F_14 ( ! V_34 || ! V_54 ) )
return - V_40 ;
if ( F_14 ( V_34 -> V_41 <= V_35 || V_35 < 0 ) )
return - V_42 ;
V_37 = F_13 ( V_34 ) ;
V_50 = & V_37 -> V_50 [ V_35 ] ;
V_2 = & V_37 -> V_1 -> V_2 ;
if ( ! V_37 -> V_1 )
return - V_74 ;
V_62 = F_32 ( V_80 , V_81 ) ;
if ( ! V_62 )
return - V_12 ;
if ( ( V_50 -> V_82 & V_83 ) && V_37 -> V_49 [ V_35 ] &&
F_23 ( V_37 , V_35 , V_54 ) ) {
V_5 = - V_40 ;
goto V_84;
}
V_62 -> V_85 = V_54 -> V_86 ;
V_60 = V_54 -> V_60 ;
V_79 = V_54 -> V_59 ;
if ( V_50 -> V_82 & V_83 ) {
F_33 ( V_62 , V_37 -> V_1 ,
F_34 ( V_37 -> V_1 ,
V_37 -> V_87 [ V_35 ] ) ,
V_60 ,
V_79 ,
F_26 ,
V_54 ) ;
if ( V_50 -> V_27 != V_28 )
V_62 -> V_88 |= V_89 ;
} else {
F_33 ( V_62 , V_37 -> V_1 ,
F_35 ( V_37 -> V_1 ,
V_37 -> V_87 [ V_35 ] ) ,
V_60 ,
V_79 + V_50 -> V_90 ,
F_30 ,
V_54 ) ;
}
V_62 -> V_88 |= V_91 ;
F_36 ( V_62 , & V_37 -> V_48 [ V_35 ] ) ;
V_5 = F_37 ( V_62 , V_7 ) ;
if ( V_5 ) {
F_24 ( V_2 , L_10 , V_5 ) ;
goto V_92;
}
return 0 ;
V_92:
F_38 ( V_62 ) ;
V_84:
F_29 ( V_62 ) ;
return V_5 ;
}
static int F_39 ( struct V_33 * V_34 , int V_35 ,
struct V_22 * V_50 )
{
unsigned int V_56 ;
unsigned int V_24 ;
unsigned int V_93 ;
unsigned int V_94 ;
struct V_36 * V_37 = F_13 ( V_34 ) ;
struct V_66 * V_2 = & V_37 -> V_1 -> V_2 ;
V_37 -> V_44 [ V_35 ] = true ;
V_37 -> V_45 [ V_35 ] . V_35 = V_35 ;
V_37 -> V_45 [ V_35 ] . V_37 = V_37 ;
F_40 ( & V_37 -> V_45 [ V_35 ] . V_46 , V_95 ) ;
if ( F_14 ( ! V_34 || ! V_50 ) ) {
F_24 ( V_2 , L_11 ) ;
return - V_96 ;
}
if ( F_14 ( V_35 < 0 || V_35 >= V_34 -> V_41 ) ) {
F_24 ( V_2 , L_5 ) ;
return - V_96 ;
}
if ( ! V_50 -> V_97 || ! V_50 -> V_98 ) {
F_24 ( V_2 , L_12 ) ;
return - V_96 ;
}
if ( V_50 -> V_27 != V_30 &&
! ( V_50 -> V_27 == V_28 &&
V_50 -> V_31 != 0xFF ) ) {
V_37 -> V_49 [ V_35 ] = false ;
goto exit;
}
V_37 -> V_49 [ V_35 ] = true ;
V_93 = V_50 -> V_98 ;
V_24 = F_10 ( V_50 ) ;
if ( V_24 == 0 || V_24 > V_32 ) {
F_15 ( V_2 , L_13 ) ;
return - V_96 ;
}
if ( V_50 -> V_98 % V_24 ) {
T_1 V_99 ;
V_99 = V_50 -> V_98 / V_24 ;
V_50 -> V_98 = V_99 * V_24 ;
F_41 ( V_2 ,
L_14 ,
V_35 ,
V_50 -> V_98 ,
V_93 ) ;
}
V_56 = V_50 -> V_98 / V_24 ;
V_94 = V_56 * ( V_32 - V_24 ) ;
V_93 += V_94 ;
V_50 -> V_90 = ( F_42 ( V_93 , V_32 ) * V_32 )
- V_50 -> V_98 ;
exit:
V_37 -> V_50 [ V_35 ] = * V_50 ;
if ( V_50 -> V_27 == V_51 ) {
T_1 V_19 = V_37 -> V_87 [ V_35 ] ;
if ( F_9 ( V_37 -> V_1 , V_19 ) < 0 )
F_15 ( V_2 , L_15 , V_19 ) ;
}
return 0 ;
}
static void F_43 ( struct V_33 * V_34 , int V_35 )
{
struct V_36 * V_37 ;
F_44 ( ! V_34 ) ;
V_37 = F_13 ( V_34 ) ;
V_37 -> V_52 . V_100 = V_101 + V_14 ;
F_45 ( & V_37 -> V_52 , V_37 -> V_52 . V_100 ) ;
}
static void F_46 ( unsigned long V_15 )
{
struct V_36 * V_37 = (struct V_36 * ) V_15 ;
F_28 ( & V_37 -> V_53 ) ;
V_37 -> V_52 . V_100 = V_101 + ( 2 * V_14 ) ;
F_47 ( & V_37 -> V_52 ) ;
}
static void F_48 ( struct V_102 * V_103 )
{
struct V_36 * V_37 = F_49 ( V_103 ) ;
struct V_1 * V_1 = V_37 -> V_1 ;
struct V_66 * V_2 = & V_1 -> V_2 ;
T_1 V_104 , V_105 , V_106 , V_107 ;
T_3 V_108 [ 6 ] ;
if ( F_1 ( V_1 , V_109 , & V_104 ) < 0 ) {
F_24 ( V_2 , L_16 ) ;
return;
}
if ( F_1 ( V_1 , V_110 , & V_105 ) < 0 ) {
F_24 ( V_2 , L_17 ) ;
return;
}
if ( F_1 ( V_1 , V_111 , & V_106 ) < 0 ) {
F_24 ( V_2 , L_18 ) ;
return;
}
if ( F_1 ( V_1 , V_112 , & V_107 ) < 0 ) {
F_24 ( V_2 , L_19 ) ;
return;
}
V_108 [ 0 ] = V_104 >> 8 ;
V_108 [ 1 ] = V_104 ;
V_108 [ 2 ] = V_105 >> 8 ;
V_108 [ 3 ] = V_105 ;
V_108 [ 4 ] = V_106 >> 8 ;
V_108 [ 5 ] = V_106 ;
F_50 ( & V_37 -> V_34 , V_107 , V_108 ) ;
}
static void V_95 ( struct V_102 * V_103 )
{
struct V_113 * V_45 = F_51 ( V_103 ) ;
struct V_36 * V_37 = V_45 -> V_37 ;
unsigned int V_35 = V_45 -> V_35 ;
int V_73 = V_45 -> V_73 ;
F_19 ( & V_37 -> V_47 ) ;
F_52 ( & V_37 -> V_34 , V_35 ) ;
F_20 ( & V_37 -> V_48 [ V_35 ] ) ;
if ( F_53 ( V_37 -> V_1 , V_73 ) )
F_15 ( & V_37 -> V_1 -> V_2 , L_20 ) ;
V_37 -> V_44 [ V_35 ] = true ;
F_54 ( & V_37 -> V_34 , V_35 ) ;
F_22 ( & V_37 -> V_47 ) ;
}
static T_5 F_55 ( struct V_114 * V_115 , struct V_116 * V_117 ,
char * V_4 )
{
struct V_118 * V_119 = F_56 ( V_117 ) ;
struct V_120 * V_121 = F_57 ( V_115 ) ;
if ( ! V_119 -> V_122 )
return - V_40 ;
return V_119 -> V_122 ( V_121 , V_119 , V_4 ) ;
}
static T_5 F_58 ( struct V_114 * V_115 ,
struct V_116 * V_117 ,
const char * V_4 ,
T_6 V_123 )
{
struct V_118 * V_119 = F_56 ( V_117 ) ;
struct V_120 * V_121 = F_57 ( V_115 ) ;
if ( ! V_119 -> V_124 )
return - V_40 ;
return V_119 -> V_124 ( V_121 , V_119 , V_4 , V_123 ) ;
}
static void F_59 ( struct V_114 * V_115 )
{
struct V_120 * V_121 = F_57 ( V_115 ) ;
F_6 ( V_121 ) ;
}
static int F_60 ( const struct V_125 * V_125 , int V_126 ,
const char * V_127 , T_1 * V_128 )
{
int V_129 ;
for ( V_129 = 0 ; V_129 < V_126 ; V_129 ++ ) {
if ( ! strcmp ( V_127 , V_125 [ V_129 ] . V_127 ) ) {
* V_128 = V_125 [ V_129 ] . V_3 ;
return 0 ;
}
}
return - V_130 ;
}
static T_5 F_61 ( struct V_120 * V_121 ,
struct V_118 * V_117 , char * V_4 )
{
const char * V_127 = V_117 -> V_117 . V_127 ;
T_1 V_131 ;
T_1 V_128 ;
int V_132 ;
if ( ! strcmp ( V_127 , L_21 ) )
return snprintf ( V_4 , V_133 , L_22 , V_121 -> V_128 ) ;
if ( ! strcmp ( V_127 , L_23 ) )
V_128 = V_121 -> V_128 ;
else if ( F_62 ( V_134 , V_127 , & V_128 ) &&
F_62 ( V_135 , V_127 , & V_128 ) )
return - V_130 ;
V_132 = F_1 ( V_121 -> V_1 , V_128 , & V_131 ) ;
if ( V_132 < 0 )
return V_132 ;
return snprintf ( V_4 , V_133 , L_22 , V_131 ) ;
}
static T_5 F_63 ( struct V_120 * V_121 ,
struct V_118 * V_117 ,
const char * V_4 , T_6 V_136 )
{
T_1 V_131 ;
T_1 V_128 ;
const char * V_127 = V_117 -> V_117 . V_127 ;
struct V_1 * V_18 = V_121 -> V_1 ;
int V_132 = F_64 ( V_4 , 16 , & V_131 ) ;
if ( V_132 )
return V_132 ;
if ( ! strcmp ( V_127 , L_21 ) ) {
V_121 -> V_128 = V_131 ;
return V_136 ;
}
if ( ! strcmp ( V_127 , L_23 ) )
V_132 = F_7 ( V_18 , V_121 -> V_128 , V_131 ) ;
else if ( ! strcmp ( V_127 , L_24 ) )
V_132 = F_9 ( V_18 , V_131 ) ;
else if ( ! F_62 ( V_134 , V_127 , & V_128 ) )
V_132 = F_7 ( V_18 , V_128 , V_131 ) ;
else
return - V_130 ;
if ( V_132 < 0 )
return V_132 ;
return V_136 ;
}
static struct
V_120 * F_65 ( struct V_114 * V_137 )
{
struct V_120 * V_138 = F_2 ( sizeof( * V_138 ) , V_7 ) ;
int V_5 ;
if ( ! V_138 )
return NULL ;
V_5 = F_66 ( & V_138 -> V_115 , & V_139 , V_137 ,
L_25 ) ;
if ( V_5 ) {
F_67 ( & V_138 -> V_115 ) ;
return NULL ;
}
return V_138 ;
}
static void F_68 ( struct V_120 * V_140 )
{
F_67 ( & V_140 -> V_115 ) ;
}
static int
F_69 ( struct V_141 * V_142 , const struct V_143 * V_144 )
{
struct V_145 * V_146 = V_142 -> V_147 ;
struct V_1 * V_18 = F_70 ( V_142 ) ;
struct V_66 * V_2 = & V_18 -> V_2 ;
struct V_36 * V_37 = F_2 ( sizeof( * V_37 ) , V_7 ) ;
unsigned int V_129 ;
unsigned int V_148 ;
struct V_149 * V_150 ;
struct V_151 * V_152 ;
int V_153 = 0 ;
if ( ! V_37 )
goto V_154;
F_71 ( V_142 , V_37 ) ;
V_148 = V_146 -> V_155 . V_156 ;
F_72 ( & V_37 -> V_47 ) ;
F_40 ( & V_37 -> V_53 , F_48 ) ;
F_73 ( & V_37 -> V_52 , F_46 ,
( unsigned long ) V_37 ) ;
V_37 -> V_1 = V_18 ;
V_37 -> V_52 . V_100 = V_101 + ( 2 * V_14 ) ;
V_37 -> V_34 . V_157 = V_158 . V_159 ;
V_37 -> V_34 . V_142 = V_160 ;
V_37 -> V_34 . V_161 = F_39 ;
V_37 -> V_34 . V_162 = F_43 ;
V_37 -> V_34 . V_163 = F_31 ;
V_37 -> V_34 . V_164 = F_12 ;
V_37 -> V_34 . V_165 = V_37 -> V_165 ;
V_37 -> V_34 . V_41 = V_148 ;
snprintf ( V_37 -> V_165 , sizeof( V_37 -> V_165 ) ,
L_26 ,
V_18 -> V_166 -> V_167 ,
V_18 -> V_168 ,
V_18 -> V_169 -> V_155 . V_170 ,
V_146 -> V_155 . V_171 ) ;
V_37 -> V_50 = F_74 ( V_148 , sizeof( * V_37 -> V_50 ) , V_7 ) ;
if ( ! V_37 -> V_50 )
goto V_172;
V_37 -> V_173 = F_74 ( V_148 , sizeof( * V_37 -> V_173 ) , V_7 ) ;
if ( ! V_37 -> V_173 )
goto V_174;
V_37 -> V_34 . V_175 = V_37 -> V_173 ;
V_37 -> V_34 . V_176 = NULL ;
V_37 -> V_87 =
F_74 ( V_148 , sizeof( * V_37 -> V_87 ) , V_7 ) ;
if ( ! V_37 -> V_87 )
goto V_177;
V_37 -> V_48 =
F_74 ( V_148 , sizeof( * V_37 -> V_48 ) , V_7 ) ;
if ( ! V_37 -> V_48 )
goto V_178;
V_150 = V_37 -> V_173 ;
for ( V_129 = 0 ; V_129 < V_148 ; V_129 ++ ) {
V_152 = & V_146 -> V_179 [ V_129 ] . V_155 ;
V_37 -> V_87 [ V_129 ] = V_152 -> V_180 ;
V_37 -> V_49 [ V_129 ] = false ;
V_37 -> V_44 [ V_129 ] = true ;
snprintf ( & V_37 -> V_181 [ V_129 ] [ 0 ] , V_182 , L_27 ,
V_37 -> V_87 [ V_129 ] ) ;
V_150 -> V_183 = & V_37 -> V_181 [ V_129 ] [ 0 ] ;
V_150 -> V_184 = V_185 ;
V_150 -> V_186 = V_185 ;
V_150 -> V_187 = V_188 ;
V_150 -> V_189 = V_188 ;
V_150 -> V_27 = V_190 | V_51 |
V_28 | V_30 ;
if ( F_75 ( V_152 ) )
V_150 -> V_82 = V_191 ;
else
V_150 -> V_82 = V_83 ;
V_150 ++ ;
F_76 ( & V_37 -> V_48 [ V_129 ] ) ;
F_77 ( & V_37 -> V_43 [ V_129 ] ) ;
}
F_41 ( V_2 , L_28 ,
F_5 ( V_18 -> V_192 . V_193 ) ,
F_5 ( V_18 -> V_192 . V_194 ) ,
V_18 -> V_166 -> V_167 ,
V_18 -> V_195 ) ;
F_41 ( V_2 , L_29 ,
V_18 -> V_166 -> V_167 ,
V_18 -> V_168 ,
V_18 -> V_169 -> V_155 . V_170 ,
V_146 -> V_155 . V_171 ) ;
V_37 -> V_137 = F_78 ( & V_37 -> V_34 ) ;
if ( F_79 ( V_37 -> V_137 ) ) {
V_153 = F_80 ( V_37 -> V_137 ) ;
goto V_196;
}
F_19 ( & V_37 -> V_47 ) ;
if ( F_5 ( V_18 -> V_192 . V_194 ) == V_197 ||
F_5 ( V_18 -> V_192 . V_194 ) == V_198 ||
F_5 ( V_18 -> V_192 . V_194 ) == V_199 ) {
V_37 -> V_200 = F_65 ( V_37 -> V_137 ) ;
if ( ! V_37 -> V_200 ) {
F_22 ( & V_37 -> V_47 ) ;
F_81 ( & V_37 -> V_34 ) ;
V_153 = - V_12 ;
goto V_196;
}
F_82 ( & V_37 -> V_200 -> V_115 , V_201 ) ;
V_37 -> V_200 -> V_1 = V_37 -> V_1 ;
}
F_22 ( & V_37 -> V_47 ) ;
return 0 ;
V_196:
F_6 ( V_37 -> V_48 ) ;
V_178:
F_6 ( V_37 -> V_87 ) ;
V_177:
F_6 ( V_37 -> V_173 ) ;
V_174:
F_6 ( V_37 -> V_50 ) ;
V_172:
F_6 ( V_37 ) ;
V_154:
if ( V_153 == 0 || V_153 == - V_12 ) {
V_153 = - V_12 ;
F_24 ( V_2 , L_30 ) ;
}
return V_153 ;
}
static void F_83 ( struct V_141 * V_142 )
{
struct V_36 * V_37 = F_84 ( V_142 ) ;
F_19 ( & V_37 -> V_47 ) ;
F_71 ( V_142 , NULL ) ;
V_37 -> V_1 = NULL ;
F_22 ( & V_37 -> V_47 ) ;
F_21 ( & V_37 -> V_52 ) ;
F_18 ( & V_37 -> V_53 ) ;
F_68 ( V_37 -> V_200 ) ;
F_81 ( & V_37 -> V_34 ) ;
F_6 ( V_37 -> V_48 ) ;
F_6 ( V_37 -> V_173 ) ;
F_6 ( V_37 -> V_50 ) ;
F_6 ( V_37 -> V_87 ) ;
F_6 ( V_37 ) ;
}
static int T_7 F_85 ( void )
{
F_86 ( L_31 ) ;
if ( F_87 ( & V_202 ) ) {
F_88 ( L_32 ) ;
return - V_40 ;
}
return 0 ;
}
static void T_8 F_89 ( void )
{
F_86 ( L_33 ) ;
F_90 ( & V_202 ) ;
}
