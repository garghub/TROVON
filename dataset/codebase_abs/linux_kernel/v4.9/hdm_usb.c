static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
int V_5 ;
T_1 * V_6 = F_2 ( sizeof( T_1 ) , V_7 ) ;
T_2 V_8 = V_9 | V_10 | V_11 ;
if ( ! V_6 )
return - V_12 ;
V_5 = F_3 ( V_2 , F_4 ( V_2 , 0 ) ,
V_13 , V_8 ,
0x0000 ,
V_3 , V_6 , sizeof( T_1 ) , 5 * V_14 ) ;
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
static void F_9 ( struct V_18 * V_19 , unsigned int V_20 ,
enum V_21 V_22 )
{
struct V_23 * V_23 ;
struct V_24 * V_24 ;
while ( ( V_24 = F_10 ( & V_19 -> V_25 [ V_20 ] ) ) ) {
V_23 = V_24 -> V_26 ;
F_11 ( V_24 ) ;
if ( V_23 && V_23 -> V_27 ) {
V_23 -> V_22 = V_22 ;
V_23 -> V_28 = 0 ;
V_23 -> V_27 ( V_23 ) ;
}
F_12 ( V_24 ) ;
}
}
static unsigned int F_13 ( struct V_29 * V_30 )
{
unsigned int V_31 = 0 ;
unsigned int V_32 = V_30 -> V_33 ;
if ( ! V_32 ) {
F_14 ( L_1 ) ;
return V_31 ;
}
switch ( V_30 -> V_34 ) {
case V_35 :
V_31 = V_36 * V_32 ;
break;
case V_37 :
if ( V_30 -> V_38 == 0 ) {
F_14 ( L_2 ) ;
V_31 = 0 ;
} else if ( V_30 -> V_38 == 0xFF ) {
V_31 = ( V_39 / V_32 ) * V_32 ;
} else {
V_31 = V_30 -> V_38 * V_32 ;
}
break;
default:
F_14 ( L_3 ) ;
break;
}
return V_31 ;
}
static int F_15 ( struct V_40 * V_41 , int V_20 )
{
struct V_18 * V_19 = F_16 ( V_41 ) ;
unsigned long V_42 ;
T_3 * V_43 ;
if ( F_17 ( ! V_41 ) ) {
F_18 ( & V_19 -> V_1 -> V_2 , L_4 ) ;
return - V_44 ;
}
if ( F_17 ( V_20 < 0 || V_20 >= V_41 -> V_45 ) ) {
F_18 ( & V_19 -> V_1 -> V_2 , L_5 ) ;
return - V_46 ;
}
V_43 = V_19 -> V_47 + V_20 ;
F_19 ( V_43 , V_42 ) ;
V_19 -> V_48 [ V_20 ] = false ;
F_20 ( V_43 , V_42 ) ;
F_21 ( & V_19 -> V_49 [ V_20 ] . V_50 ) ;
F_22 ( & V_19 -> V_51 ) ;
F_9 ( V_19 , V_20 , V_52 ) ;
if ( V_19 -> V_53 [ V_20 ] )
V_19 -> V_53 [ V_20 ] = false ;
if ( V_19 -> V_54 [ V_20 ] . V_34 == V_55 ) {
F_23 ( & V_19 -> V_56 ) ;
F_21 ( & V_19 -> V_57 ) ;
}
F_24 ( & V_19 -> V_51 ) ;
return 0 ;
}
static int F_25 ( struct V_18 * V_19 , int V_20 , struct V_23 * V_23 )
{
struct V_29 * V_54 = & V_19 -> V_54 [ V_20 ] ;
unsigned int V_31 = F_13 ( V_54 ) ;
unsigned int V_58 , V_59 ;
T_1 V_60 , V_61 ;
if ( ! V_31 )
return - V_44 ;
V_59 = V_23 -> V_62 / V_31 ;
if ( V_59 < 1 ) {
F_26 ( & V_19 -> V_1 -> V_2 ,
L_6 ) ;
return - V_44 ;
}
for ( V_58 = 1 ; V_58 < V_59 ; V_58 ++ ) {
V_61 = ( V_59 - V_58 ) * V_39 ;
V_60 = ( V_59 - V_58 ) * V_31 ;
memmove ( V_23 -> V_63 + V_61 ,
V_23 -> V_63 + V_60 ,
V_31 ) ;
}
V_23 -> V_62 = V_59 * V_39 ;
return 0 ;
}
static int F_27 ( struct V_18 * V_19 , int V_20 ,
struct V_23 * V_23 )
{
struct V_29 * const V_54 = & V_19 -> V_54 [ V_20 ] ;
unsigned int V_31 = F_13 ( V_54 ) ;
unsigned int V_58 , V_59 ;
if ( ! V_31 )
return - V_44 ;
V_59 = V_23 -> V_28 / V_39 ;
for ( V_58 = 1 ; V_58 < V_59 ; V_58 ++ )
memmove ( V_23 -> V_63 + V_31 * V_58 ,
V_23 -> V_63 + V_39 * V_58 ,
V_31 ) ;
V_23 -> V_28 = V_31 * V_59 ;
return 0 ;
}
static void F_28 ( struct V_24 * V_24 )
{
struct V_23 * V_23 = V_24 -> V_26 ;
struct V_18 * V_19 = F_16 ( V_23 -> V_64 ) ;
unsigned int V_20 = V_23 -> V_65 ;
struct V_66 * V_2 = & V_19 -> V_1 -> V_2 ;
T_3 * V_43 = V_19 -> V_47 + V_20 ;
unsigned long V_42 ;
F_19 ( V_43 , V_42 ) ;
if ( V_24 -> V_22 == - V_67 || V_24 -> V_22 == - V_68 ||
! V_19 -> V_48 [ V_20 ] ) {
F_20 ( V_43 , V_42 ) ;
return;
}
if ( F_17 ( V_24 -> V_22 && V_24 -> V_22 != - V_69 ) ) {
V_23 -> V_28 = 0 ;
switch ( V_24 -> V_22 ) {
case - V_70 :
F_18 ( V_2 , L_7 ) ;
V_19 -> V_48 [ V_20 ] = false ;
F_20 ( V_43 , V_42 ) ;
V_19 -> V_49 [ V_20 ] . V_71 = V_24 -> V_71 ;
F_29 ( & V_19 -> V_49 [ V_20 ] . V_50 ) ;
return;
case - V_72 :
case - V_73 :
V_23 -> V_22 = V_52 ;
break;
default:
V_23 -> V_22 = V_74 ;
break;
}
} else {
V_23 -> V_22 = V_75 ;
V_23 -> V_28 = V_24 -> V_76 ;
}
F_20 ( V_43 , V_42 ) ;
if ( F_30 ( V_23 -> V_27 ) )
V_23 -> V_27 ( V_23 ) ;
F_12 ( V_24 ) ;
}
static void F_31 ( struct V_24 * V_24 )
{
struct V_23 * V_23 = V_24 -> V_26 ;
struct V_18 * V_19 = F_16 ( V_23 -> V_64 ) ;
unsigned int V_20 = V_23 -> V_65 ;
struct V_66 * V_2 = & V_19 -> V_1 -> V_2 ;
T_3 * V_43 = V_19 -> V_47 + V_20 ;
unsigned long V_42 ;
F_19 ( V_43 , V_42 ) ;
if ( V_24 -> V_22 == - V_67 || V_24 -> V_22 == - V_68 ||
! V_19 -> V_48 [ V_20 ] ) {
F_20 ( V_43 , V_42 ) ;
return;
}
if ( F_17 ( V_24 -> V_22 && V_24 -> V_22 != - V_69 ) ) {
V_23 -> V_28 = 0 ;
switch ( V_24 -> V_22 ) {
case - V_70 :
F_18 ( V_2 , L_8 ) ;
V_19 -> V_48 [ V_20 ] = false ;
F_20 ( V_43 , V_42 ) ;
V_19 -> V_49 [ V_20 ] . V_71 = V_24 -> V_71 ;
F_29 ( & V_19 -> V_49 [ V_20 ] . V_50 ) ;
return;
case - V_72 :
case - V_73 :
V_23 -> V_22 = V_52 ;
break;
case - V_77 :
F_18 ( V_2 , L_9 ) ;
default:
V_23 -> V_22 = V_74 ;
break;
}
} else {
V_23 -> V_28 = V_24 -> V_76 ;
V_23 -> V_22 = V_75 ;
if ( V_19 -> V_53 [ V_20 ] &&
F_27 ( V_19 , V_20 , V_23 ) ) {
V_23 -> V_28 = 0 ;
V_23 -> V_22 = V_74 ;
}
}
F_20 ( V_43 , V_42 ) ;
if ( F_30 ( V_23 -> V_27 ) )
V_23 -> V_27 ( V_23 ) ;
F_12 ( V_24 ) ;
}
static int F_32 ( struct V_40 * V_41 , int V_20 ,
struct V_23 * V_23 )
{
struct V_18 * V_19 ;
struct V_29 * V_54 ;
struct V_66 * V_2 ;
int V_5 = 0 ;
struct V_24 * V_24 ;
unsigned long V_78 ;
void * V_63 ;
if ( F_17 ( ! V_41 || ! V_23 ) )
return - V_44 ;
if ( F_17 ( V_41 -> V_45 <= V_20 || V_20 < 0 ) )
return - V_46 ;
V_19 = F_16 ( V_41 ) ;
V_54 = & V_19 -> V_54 [ V_20 ] ;
V_2 = & V_19 -> V_1 -> V_2 ;
if ( ! V_19 -> V_1 )
return - V_72 ;
V_24 = F_33 ( V_79 , V_80 ) ;
if ( ! V_24 )
return - V_12 ;
if ( ( V_54 -> V_81 & V_82 ) && V_19 -> V_53 [ V_20 ] &&
F_25 ( V_19 , V_20 , V_23 ) ) {
V_5 = - V_44 ;
goto V_83;
}
V_24 -> V_84 = V_23 -> V_85 ;
V_63 = V_23 -> V_63 ;
V_78 = V_23 -> V_62 ;
if ( V_54 -> V_81 & V_82 ) {
F_34 ( V_24 , V_19 -> V_1 ,
F_35 ( V_19 -> V_1 ,
V_19 -> V_86 [ V_20 ] ) ,
V_63 ,
V_78 ,
F_28 ,
V_23 ) ;
if ( V_54 -> V_34 != V_35 )
V_24 -> V_87 |= V_88 ;
} else {
F_34 ( V_24 , V_19 -> V_1 ,
F_36 ( V_19 -> V_1 ,
V_19 -> V_86 [ V_20 ] ) ,
V_63 ,
V_78 + V_54 -> V_89 ,
F_31 ,
V_23 ) ;
}
V_24 -> V_87 |= V_90 ;
F_37 ( V_24 , & V_19 -> V_25 [ V_20 ] ) ;
V_5 = F_38 ( V_24 , V_7 ) ;
if ( V_5 ) {
F_26 ( V_2 , L_10 , V_5 ) ;
goto V_91;
}
return 0 ;
V_91:
F_39 ( V_24 ) ;
V_83:
F_12 ( V_24 ) ;
return V_5 ;
}
static int F_40 ( struct V_40 * V_41 , int V_20 ,
struct V_29 * V_54 )
{
unsigned int V_59 ;
unsigned int V_31 ;
unsigned int V_92 ;
unsigned int V_93 ;
struct V_18 * V_19 = F_16 ( V_41 ) ;
struct V_66 * V_2 = & V_19 -> V_1 -> V_2 ;
V_19 -> V_48 [ V_20 ] = true ;
V_19 -> V_49 [ V_20 ] . V_20 = V_20 ;
V_19 -> V_49 [ V_20 ] . V_19 = V_19 ;
F_41 ( & V_19 -> V_49 [ V_20 ] . V_50 , V_94 ) ;
if ( F_17 ( ! V_41 || ! V_54 ) ) {
F_26 ( V_2 , L_11 ) ;
return - V_95 ;
}
if ( F_17 ( V_20 < 0 || V_20 >= V_41 -> V_45 ) ) {
F_26 ( V_2 , L_5 ) ;
return - V_95 ;
}
if ( ! V_54 -> V_96 || ! V_54 -> V_97 ) {
F_26 ( V_2 , L_12 ) ;
return - V_95 ;
}
if ( V_54 -> V_34 != V_37 &&
! ( V_54 -> V_34 == V_35 &&
V_54 -> V_38 != 0xFF ) ) {
V_19 -> V_53 [ V_20 ] = false ;
goto exit;
}
V_19 -> V_53 [ V_20 ] = true ;
V_92 = V_54 -> V_97 ;
V_31 = F_13 ( V_54 ) ;
if ( V_31 == 0 || V_31 > V_39 ) {
F_18 ( V_2 , L_13 ) ;
return - V_95 ;
}
if ( V_54 -> V_97 % V_31 ) {
T_1 V_98 ;
V_98 = V_54 -> V_97 / V_31 ;
V_54 -> V_97 = V_98 * V_31 ;
F_42 ( V_2 ,
L_14 ,
V_20 ,
V_54 -> V_97 ,
V_92 ) ;
}
V_59 = V_54 -> V_97 / V_31 ;
V_93 = V_59 * ( V_39 - V_31 ) ;
V_92 += V_93 ;
V_54 -> V_89 = ( F_43 ( V_92 , V_39 ) * V_39 )
- V_54 -> V_97 ;
exit:
V_19 -> V_54 [ V_20 ] = * V_54 ;
return 0 ;
}
static int F_44 ( struct V_18 * V_19 )
{
struct V_1 * V_1 = V_19 -> V_1 ;
struct V_66 * V_2 = & V_1 -> V_2 ;
T_1 V_99 , V_100 , V_101 , V_102 ;
if ( ! F_45 ( V_19 -> V_103 ) ) {
if ( F_1 ( V_1 , V_104 , & V_99 ) < 0 ) {
F_26 ( V_2 , L_15 ) ;
return - V_105 ;
}
if ( F_1 ( V_1 , V_106 , & V_100 ) < 0 ) {
F_26 ( V_2 , L_16 ) ;
return - V_105 ;
}
if ( F_1 ( V_1 , V_107 , & V_101 ) < 0 ) {
F_26 ( V_2 , L_17 ) ;
return - V_105 ;
}
F_22 ( & V_19 -> V_51 ) ;
V_19 -> V_103 [ 0 ] = V_99 >> 8 ;
V_19 -> V_103 [ 1 ] = V_99 ;
V_19 -> V_103 [ 2 ] = V_100 >> 8 ;
V_19 -> V_103 [ 3 ] = V_100 ;
V_19 -> V_103 [ 4 ] = V_101 >> 8 ;
V_19 -> V_103 [ 5 ] = V_101 ;
F_24 ( & V_19 -> V_51 ) ;
}
if ( F_1 ( V_1 , V_108 , & V_102 ) < 0 ) {
F_26 ( V_2 , L_18 ) ;
return - V_105 ;
}
F_22 ( & V_19 -> V_51 ) ;
V_19 -> V_109 = V_102 ;
F_24 ( & V_19 -> V_51 ) ;
return 0 ;
}
static void F_46 ( struct V_40 * V_41 , int V_20 )
{
struct V_18 * V_19 ;
F_47 ( ! V_41 ) ;
V_19 = F_16 ( V_41 ) ;
V_19 -> V_56 . V_110 = V_111 + V_14 ;
F_48 ( & V_19 -> V_56 , V_19 -> V_56 . V_110 ) ;
}
static void F_49 ( unsigned long V_15 )
{
struct V_18 * V_19 = (struct V_18 * ) V_15 ;
F_29 ( & V_19 -> V_57 ) ;
V_19 -> V_56 . V_110 = V_111 + ( 2 * V_14 ) ;
F_50 ( & V_19 -> V_56 ) ;
}
static void F_51 ( struct V_112 * V_113 )
{
struct V_18 * V_19 = F_52 ( V_113 ) ;
int V_114 , V_115 = V_19 -> V_109 ;
T_2 V_116 [ 6 ] ;
for ( V_114 = 0 ; V_114 < 6 ; V_114 ++ )
V_116 [ V_114 ] = V_19 -> V_103 [ V_114 ] ;
if ( F_44 ( V_19 ) < 0 )
return;
if ( V_115 != V_19 -> V_109 ||
V_116 [ 0 ] != V_19 -> V_103 [ 0 ] ||
V_116 [ 1 ] != V_19 -> V_103 [ 1 ] ||
V_116 [ 2 ] != V_19 -> V_103 [ 2 ] ||
V_116 [ 3 ] != V_19 -> V_103 [ 3 ] ||
V_116 [ 4 ] != V_19 -> V_103 [ 4 ] ||
V_116 [ 5 ] != V_19 -> V_103 [ 5 ] )
F_53 ( & V_19 -> V_41 , V_19 -> V_109 ,
& V_19 -> V_103 [ 0 ] ) ;
}
static void V_94 ( struct V_112 * V_113 )
{
struct V_117 * V_49 = F_54 ( V_113 ) ;
struct V_18 * V_19 = V_49 -> V_19 ;
unsigned int V_20 = V_49 -> V_20 ;
int V_71 = V_49 -> V_71 ;
F_22 ( & V_19 -> V_51 ) ;
F_55 ( & V_19 -> V_41 , V_20 ) ;
F_9 ( V_19 , V_20 , V_74 ) ;
if ( F_56 ( V_19 -> V_1 , V_71 ) )
F_18 ( & V_19 -> V_1 -> V_2 , L_19 ) ;
V_19 -> V_48 [ V_20 ] = true ;
F_57 ( & V_19 -> V_41 , V_20 ) ;
F_24 ( & V_19 -> V_51 ) ;
}
static T_4 F_58 ( struct V_118 * V_119 , struct V_120 * V_121 ,
char * V_4 )
{
struct V_122 * V_123 = F_59 ( V_121 ) ;
struct V_124 * V_125 = F_60 ( V_119 ) ;
if ( ! V_123 -> V_126 )
return - V_44 ;
return V_123 -> V_126 ( V_125 , V_123 , V_4 ) ;
}
static T_4 F_61 ( struct V_118 * V_119 ,
struct V_120 * V_121 ,
const char * V_4 ,
T_5 V_127 )
{
struct V_122 * V_123 = F_59 ( V_121 ) ;
struct V_124 * V_125 = F_60 ( V_119 ) ;
if ( ! V_123 -> V_128 )
return - V_44 ;
return V_123 -> V_128 ( V_125 , V_123 , V_4 , V_127 ) ;
}
static void F_62 ( struct V_118 * V_119 )
{
struct V_124 * V_125 = F_60 ( V_119 ) ;
F_6 ( V_125 ) ;
}
static int F_63 ( const struct V_129 * V_129 , int V_130 ,
const char * V_131 , T_1 * V_132 )
{
int V_114 ;
for ( V_114 = 0 ; V_114 < V_130 ; V_114 ++ ) {
if ( ! strcmp ( V_131 , V_129 [ V_114 ] . V_131 ) ) {
* V_132 = V_129 [ V_114 ] . V_3 ;
return 0 ;
}
}
return - V_105 ;
}
static T_4 F_64 ( struct V_124 * V_125 ,
struct V_122 * V_121 , char * V_4 )
{
const char * V_131 = V_121 -> V_121 . V_131 ;
T_1 V_133 ;
T_1 V_132 ;
int V_134 ;
if ( ! strcmp ( V_131 , L_20 ) )
return snprintf ( V_4 , V_135 , L_21 , V_125 -> V_132 ) ;
if ( ! strcmp ( V_131 , L_22 ) )
V_132 = V_125 -> V_132 ;
else if ( F_65 ( V_136 , V_131 , & V_132 ) &&
F_65 ( V_137 , V_131 , & V_132 ) )
return - V_105 ;
V_134 = F_1 ( V_125 -> V_1 , V_132 , & V_133 ) ;
if ( V_134 < 0 )
return V_134 ;
return snprintf ( V_4 , V_135 , L_21 , V_133 ) ;
}
static T_4 F_66 ( struct V_124 * V_125 ,
struct V_122 * V_121 ,
const char * V_4 , T_5 V_138 )
{
T_1 V_133 ;
T_1 V_132 ;
const char * V_131 = V_121 -> V_121 . V_131 ;
int V_134 = F_67 ( V_4 , 16 , & V_133 ) ;
if ( V_134 )
return V_134 ;
if ( ! strcmp ( V_131 , L_20 ) ) {
V_125 -> V_132 = V_133 ;
return V_138 ;
}
if ( ! strcmp ( V_131 , L_22 ) ) {
V_132 = V_125 -> V_132 ;
} else if ( ! strcmp ( V_131 , L_23 ) ) {
T_1 V_139 = V_133 ;
V_132 = V_140 + V_141 + V_139 * 16 ;
V_133 = 1 ;
} else if ( F_65 ( V_136 , V_131 , & V_132 ) ) {
return - V_105 ;
}
V_134 = F_7 ( V_125 -> V_1 , V_132 , V_133 ) ;
if ( V_134 < 0 )
return V_134 ;
return V_138 ;
}
static struct
V_124 * F_68 ( struct V_118 * V_142 )
{
struct V_124 * V_143 = F_2 ( sizeof( * V_143 ) , V_7 ) ;
int V_5 ;
if ( ! V_143 )
return NULL ;
V_5 = F_69 ( & V_143 -> V_119 , & V_144 , V_142 ,
L_24 ) ;
if ( V_5 ) {
F_70 ( & V_143 -> V_119 ) ;
return NULL ;
}
return V_143 ;
}
static void F_71 ( struct V_124 * V_145 )
{
F_70 ( & V_145 -> V_119 ) ;
}
static int
F_72 ( struct V_146 * V_147 , const struct V_148 * V_149 )
{
struct V_150 * V_151 = V_147 -> V_152 ;
struct V_1 * V_153 = F_73 ( V_147 ) ;
struct V_66 * V_2 = & V_153 -> V_2 ;
struct V_18 * V_19 = F_2 ( sizeof( * V_19 ) , V_7 ) ;
unsigned int V_114 ;
unsigned int V_154 ;
struct V_155 * V_156 ;
struct V_157 * V_158 ;
int V_159 = 0 ;
int V_134 ;
if ( ! V_19 )
goto V_160;
F_74 ( V_147 , V_19 ) ;
V_154 = V_151 -> V_161 . V_162 ;
F_75 ( & V_19 -> V_51 ) ;
F_41 ( & V_19 -> V_57 , F_51 ) ;
F_76 ( & V_19 -> V_56 , F_49 ,
( unsigned long ) V_19 ) ;
V_19 -> V_1 = V_153 ;
V_19 -> V_56 . V_110 = V_111 + ( 2 * V_14 ) ;
V_19 -> V_41 . V_163 = V_164 . V_165 ;
V_19 -> V_41 . V_147 = V_166 ;
V_19 -> V_41 . V_167 = F_40 ;
V_19 -> V_41 . V_168 = F_46 ;
V_19 -> V_41 . V_169 = F_32 ;
V_19 -> V_41 . V_170 = F_15 ;
V_19 -> V_41 . V_171 = V_19 -> V_171 ;
V_19 -> V_41 . V_45 = V_154 ;
snprintf ( V_19 -> V_171 , sizeof( V_19 -> V_171 ) ,
L_25 ,
V_153 -> V_172 -> V_173 ,
V_153 -> V_174 ,
V_153 -> V_175 -> V_161 . V_176 ,
V_151 -> V_161 . V_177 ) ;
V_19 -> V_54 = F_77 ( V_154 , sizeof( * V_19 -> V_54 ) , V_7 ) ;
if ( ! V_19 -> V_54 )
goto V_178;
V_19 -> V_179 = F_77 ( V_154 , sizeof( * V_19 -> V_179 ) , V_7 ) ;
if ( ! V_19 -> V_179 )
goto V_180;
V_19 -> V_41 . V_181 = V_19 -> V_179 ;
V_19 -> V_41 . V_182 = NULL ;
V_19 -> V_86 =
F_77 ( V_154 , sizeof( * V_19 -> V_86 ) , V_7 ) ;
if ( ! V_19 -> V_86 )
goto V_183;
V_19 -> V_25 =
F_77 ( V_154 , sizeof( * V_19 -> V_25 ) , V_7 ) ;
if ( ! V_19 -> V_25 )
goto V_184;
V_156 = V_19 -> V_179 ;
for ( V_114 = 0 ; V_114 < V_154 ; V_114 ++ ) {
V_158 = & V_151 -> V_185 [ V_114 ] . V_161 ;
V_19 -> V_86 [ V_114 ] = V_158 -> V_186 ;
V_19 -> V_53 [ V_114 ] = false ;
V_19 -> V_48 [ V_114 ] = true ;
snprintf ( & V_19 -> V_187 [ V_114 ] [ 0 ] , V_188 , L_26 ,
V_19 -> V_86 [ V_114 ] ) ;
V_156 -> V_189 = & V_19 -> V_187 [ V_114 ] [ 0 ] ;
V_156 -> V_190 = V_191 ;
V_156 -> V_192 = V_191 ;
V_156 -> V_193 = V_194 ;
V_156 -> V_195 = V_194 ;
V_156 -> V_34 = V_196 | V_55 |
V_35 | V_37 ;
if ( F_78 ( V_158 ) )
V_156 -> V_81 = V_197 ;
else
V_156 -> V_81 = V_82 ;
V_156 ++ ;
F_79 ( & V_19 -> V_25 [ V_114 ] ) ;
F_80 ( & V_19 -> V_47 [ V_114 ] ) ;
V_134 = F_7 ( V_153 ,
V_140 + V_141 +
V_158 -> V_186 * 16 ,
1 ) ;
if ( V_134 < 0 )
F_18 ( V_2 , L_27 ,
V_158 -> V_186 ) ;
}
F_42 ( V_2 , L_28 ,
F_5 ( V_153 -> V_198 . V_199 ) ,
F_5 ( V_153 -> V_198 . V_200 ) ,
V_153 -> V_172 -> V_173 ,
V_153 -> V_201 ) ;
F_42 ( V_2 , L_29 ,
V_153 -> V_172 -> V_173 ,
V_153 -> V_174 ,
V_153 -> V_175 -> V_161 . V_176 ,
V_151 -> V_161 . V_177 ) ;
V_19 -> V_142 = F_81 ( & V_19 -> V_41 ) ;
if ( F_82 ( V_19 -> V_142 ) ) {
V_159 = F_83 ( V_19 -> V_142 ) ;
goto V_202;
}
F_22 ( & V_19 -> V_51 ) ;
if ( F_5 ( V_153 -> V_198 . V_200 ) == V_203 ||
F_5 ( V_153 -> V_198 . V_200 ) == V_204 ||
F_5 ( V_153 -> V_198 . V_200 ) == V_205 ) {
V_19 -> V_206 = F_68 ( V_19 -> V_142 ) ;
if ( ! V_19 -> V_206 ) {
F_24 ( & V_19 -> V_51 ) ;
F_84 ( & V_19 -> V_41 ) ;
V_159 = - V_12 ;
goto V_202;
}
F_85 ( & V_19 -> V_206 -> V_119 , V_207 ) ;
V_19 -> V_206 -> V_1 = V_19 -> V_1 ;
}
F_24 ( & V_19 -> V_51 ) ;
return 0 ;
V_202:
F_6 ( V_19 -> V_25 ) ;
V_184:
F_6 ( V_19 -> V_86 ) ;
V_183:
F_6 ( V_19 -> V_179 ) ;
V_180:
F_6 ( V_19 -> V_54 ) ;
V_178:
F_6 ( V_19 ) ;
V_160:
if ( V_159 == 0 || V_159 == - V_12 ) {
V_159 = - V_12 ;
F_26 ( V_2 , L_30 ) ;
}
return V_159 ;
}
static void F_86 ( struct V_146 * V_147 )
{
struct V_18 * V_19 = F_87 ( V_147 ) ;
F_22 ( & V_19 -> V_51 ) ;
F_74 ( V_147 , NULL ) ;
V_19 -> V_1 = NULL ;
F_24 ( & V_19 -> V_51 ) ;
F_23 ( & V_19 -> V_56 ) ;
F_21 ( & V_19 -> V_57 ) ;
F_71 ( V_19 -> V_206 ) ;
F_84 ( & V_19 -> V_41 ) ;
F_6 ( V_19 -> V_25 ) ;
F_6 ( V_19 -> V_179 ) ;
F_6 ( V_19 -> V_54 ) ;
F_6 ( V_19 -> V_86 ) ;
F_6 ( V_19 ) ;
}
static int T_6 F_88 ( void )
{
F_89 ( L_31 ) ;
if ( F_90 ( & V_208 ) ) {
F_91 ( L_32 ) ;
return - V_44 ;
}
return 0 ;
}
static void T_7 F_92 ( void )
{
F_89 ( L_33 ) ;
F_93 ( & V_208 ) ;
}
