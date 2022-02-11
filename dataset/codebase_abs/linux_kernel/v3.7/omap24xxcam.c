static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 != NULL && ! F_2 ( V_2 -> V_3 ) )
F_3 ( V_2 -> V_3 ) ;
if ( V_2 -> V_4 != NULL && ! F_2 ( V_2 -> V_4 ) )
F_3 ( V_2 -> V_4 ) ;
V_2 -> V_3 = V_2 -> V_4 = NULL ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_5 = 0 ;
V_2 -> V_4 = F_5 ( V_2 -> V_6 , L_1 ) ;
if ( F_2 ( V_2 -> V_4 ) ) {
F_6 ( V_2 -> V_6 , L_2 ) ;
V_5 = F_7 ( V_2 -> V_4 ) ;
F_1 ( V_2 ) ;
return V_5 ;
}
V_2 -> V_3 = F_5 ( V_2 -> V_6 , L_3 ) ;
if ( F_2 ( V_2 -> V_3 ) ) {
F_6 ( V_2 -> V_6 , L_4 ) ;
V_5 = F_7 ( V_2 -> V_3 ) ;
F_1 ( V_2 ) ;
}
return V_5 ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_9 ( V_2 -> V_4 ) ;
F_9 ( V_2 -> V_3 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_11 ( V_2 -> V_4 ) ;
F_11 ( V_2 -> V_3 ) ;
}
static void F_12 ( const struct V_1 * V_2 ,
T_1 V_7 )
{
if ( V_7 ) {
T_1 V_8 = V_9 / V_7 ;
if ( V_8 == 1 )
F_13 ( V_2 -> V_10 + V_11 ,
V_12 ,
V_13 ) ;
else
F_13 ( V_2 -> V_10 + V_11 ,
V_12 , V_8 ) ;
} else
F_13 ( V_2 -> V_10 + V_11 ,
V_12 , V_14 ) ;
}
static void F_14 ( const struct V_1 * V_2 )
{
F_13 ( V_2 -> V_10 + V_11 , V_15 ,
V_16 ) ;
F_13 ( V_2 -> V_10 + V_11 , V_17 ,
V_18 | ( V_19 / 4 - 1 ) ) ;
F_13 ( V_2 -> V_10 + V_11 , V_20 ,
V_21
| V_22
| V_23
| V_24 ) ;
}
static void F_15 ( const struct V_1 * V_2 )
{
F_13 ( V_2 -> V_10 + V_11 , V_25 ,
V_2 -> V_26 ) ;
}
static void F_16 ( const struct V_1 * V_2 )
{
F_13 ( V_2 -> V_10 + V_11 , V_25 ,
V_27 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
T_1 V_28 ;
const T_1 V_29 =
V_30
| V_31
| V_32
| V_33
| V_34 ;
V_28 = F_18 ( V_2 -> V_10 + V_11 ,
V_35 ) ;
F_13 ( V_2 -> V_10 + V_11 , V_35 ,
V_28 ) ;
if ( V_28 & V_29
&& ! F_19 ( & V_2 -> V_36 ) ) {
F_20 ( V_2 -> V_6 , L_5 ,
V_28 ) ;
F_21 ( V_2 ) ;
}
}
static void F_22 ( struct V_37 * V_38 )
{
struct V_39 * V_40 = F_23 ( V_38 ) ;
T_2 V_41 ;
struct V_42 * V_42 ;
int V_43 ;
if ( V_40 -> V_44 == NULL )
return;
V_43 = V_40 -> V_45 ;
while ( V_43 ) {
V_43 -- ;
V_41 = F_24 ( & V_40 -> V_44 [ V_43 ] ) ;
V_42 = F_25 ( & V_40 -> V_44 [ V_43 ] ) ;
do {
F_26 ( V_42 ++ ) ;
} while ( V_41 -= V_46 );
F_27 ( F_25 ( & V_40 -> V_44 [ V_43 ] ) ,
F_28 ( F_24 ( & V_40 -> V_44 [ V_43 ] ) ) ) ;
}
F_29 ( V_40 -> V_44 ) ;
V_40 -> V_44 = NULL ;
}
static void F_30 ( struct V_47 * V_48 )
{
int V_43 ;
F_31 ( & V_48 -> V_49 ) ;
for ( V_43 = 0 ; V_43 < V_50 ; V_43 ++ ) {
if ( NULL == V_48 -> V_51 [ V_43 ] )
continue;
if ( V_52 != V_48 -> V_51 [ V_43 ] -> V_53 )
continue;
V_48 -> V_54 -> V_55 ( V_48 , V_48 -> V_51 [ V_43 ] ) ;
F_22 ( V_48 -> V_51 [ V_43 ] ) ;
F_29 ( V_48 -> V_51 [ V_43 ] ) ;
V_48 -> V_51 [ V_43 ] = NULL ;
}
F_32 ( & V_48 -> V_49 ) ;
F_33 ( V_48 ) ;
}
static int F_34 ( struct V_37 * V_38 )
{
unsigned int V_56 ;
T_2 V_41 , V_57 = V_38 -> V_58 ;
struct V_42 * V_42 ;
int V_59 , V_60 = 0 , V_43 = 0 ;
struct V_39 * V_40 = F_23 ( V_38 ) ;
V_59 = V_38 -> V_58 >> V_61 ;
V_40 -> V_44 = F_35 ( V_59 , sizeof( * V_40 -> V_44 ) , V_62 ) ;
if ( V_40 -> V_44 == NULL ) {
V_60 = - V_63 ;
goto V_64;
}
while ( V_57 ) {
V_56 = F_28 ( V_57 ) ;
if ( ( V_46 << V_56 ) > V_57 )
V_56 -- ;
V_42 = F_36 ( V_62 , V_56 ) ;
while ( V_42 == NULL ) {
V_56 -- ;
V_42 = F_36 ( V_62 , V_56 ) ;
if ( V_42 == NULL && ! V_56 ) {
V_60 = - V_63 ;
goto V_64;
}
}
V_57 -= ( V_46 << V_56 ) ;
F_37 ( & V_40 -> V_44 [ V_43 ] , V_42 , V_46 << V_56 , 0 ) ;
V_40 -> V_45 ++ ;
V_43 ++ ;
V_41 = ( V_46 << V_56 ) ;
memset ( F_38 ( V_42 ) , 0 , V_41 ) ;
do {
F_39 ( V_42 ++ ) ;
} while ( V_41 -= V_46 );
}
V_40 -> V_65 = V_40 -> V_45 ;
V_40 -> V_66 = V_67 ;
return 0 ;
V_64:
F_22 ( V_38 ) ;
return V_60 ;
}
static int F_40 ( struct V_47 * V_48 ,
unsigned int V_68 )
{
int V_43 , V_60 = 0 ;
struct V_69 * V_70 =
F_41 ( V_48 , struct V_69 , V_48 ) ;
F_31 ( & V_48 -> V_49 ) ;
for ( V_43 = 0 ; V_43 < V_68 ; V_43 ++ ) {
V_60 = F_34 ( V_48 -> V_51 [ V_43 ] ) ;
if ( V_60 )
goto V_64;
F_20 ( V_70 -> V_2 -> V_6 , L_6 ,
F_23 ( V_48 -> V_51 [ V_43 ] ) -> V_45 , V_43 ) ;
}
F_32 ( & V_48 -> V_49 ) ;
return 0 ;
V_64:
while ( V_43 ) {
V_43 -- ;
F_22 ( V_48 -> V_51 [ V_43 ] ) ;
}
F_32 ( & V_48 -> V_49 ) ;
return V_60 ;
}
static void F_42 ( struct V_71 * V_72 ,
T_1 V_73 , void * V_74 )
{
struct V_1 * V_2 =
F_41 ( V_72 , struct V_1 , V_72 ) ;
struct V_69 * V_70 = V_2 -> V_75 -> V_76 ;
struct V_37 * V_38 = (struct V_37 * ) V_74 ;
const T_1 V_77 = V_78
| V_79 | V_80
| V_81 | V_82 ;
unsigned long V_83 ;
F_43 ( & V_2 -> V_84 , V_83 ) ;
if ( -- V_2 -> V_85 == 0 )
F_16 ( V_2 ) ;
F_44 ( & V_2 -> V_84 , V_83 ) ;
F_45 ( & V_38 -> V_86 ) ;
V_38 -> V_87 = F_46 ( 2 , & V_70 -> V_87 ) ;
if ( V_73 & V_77 ) {
V_38 -> V_88 = V_89 ;
if ( ! F_19 ( & V_70 -> V_2 -> V_36 ) ) {
F_20 ( V_2 -> V_6 , L_7 , V_73 ) ;
F_21 ( V_2 ) ;
}
} else
V_38 -> V_88 = V_90 ;
F_47 ( & V_38 -> V_91 ) ;
}
static void F_48 ( struct V_47 * V_48 ,
struct V_37 * V_38 )
{
struct V_39 * V_40 = F_23 ( V_38 ) ;
F_49 ( V_48 , V_38 , 0 , 0 ) ;
if ( V_38 -> V_53 == V_52 ) {
F_50 ( V_48 -> V_6 , V_40 -> V_44 , V_40 -> V_45 ,
V_40 -> V_66 ) ;
V_40 -> V_66 = V_92 ;
} else {
F_51 ( V_48 -> V_6 , F_23 ( V_38 ) ) ;
F_52 ( F_23 ( V_38 ) ) ;
}
V_38 -> V_88 = V_93 ;
}
static int F_53 ( struct V_47 * V_48 , unsigned int * V_94 ,
unsigned int * V_57 )
{
struct V_69 * V_70 = V_48 -> V_95 ;
if ( * V_94 <= 0 )
* V_94 = V_50 ;
if ( * V_94 > V_50 )
* V_94 = V_50 ;
* V_57 = V_70 -> V_96 . V_97 ;
if ( * V_57 * * V_94 > V_70 -> V_2 -> V_98 )
* V_94 = V_70 -> V_2 -> V_98 / * V_57 ;
return 0 ;
}
static int F_54 ( struct V_47 * V_48 ,
struct V_39 * V_40 )
{
int V_60 = 0 ;
V_40 -> V_66 = V_67 ;
if ( ! F_55 ( V_48 -> V_6 , V_40 -> V_44 , V_40 -> V_45 , V_40 -> V_66 ) ) {
F_29 ( V_40 -> V_44 ) ;
V_40 -> V_44 = NULL ;
V_40 -> V_45 = 0 ;
V_60 = - V_99 ;
}
return V_60 ;
}
static int F_56 ( struct V_47 * V_48 ,
struct V_37 * V_38 ,
enum V_100 V_101 )
{
struct V_69 * V_70 = V_48 -> V_95 ;
int V_60 = 0 ;
if ( V_38 -> V_102 ) {
if ( V_70 -> V_96 . V_97 > V_38 -> V_58 ) {
V_60 = - V_103 ;
} else
V_38 -> V_57 = V_70 -> V_96 . V_97 ;
} else {
if ( V_38 -> V_88 != V_93 ) {
if ( V_70 -> V_96 . V_97 > V_38 -> V_57 ) {
F_48 ( V_48 , V_38 ) ;
V_38 -> V_57 = V_70 -> V_96 . V_97 ;
}
} else {
V_38 -> V_57 = V_70 -> V_96 . V_97 ;
}
}
if ( V_60 )
return V_60 ;
V_38 -> V_104 = V_70 -> V_96 . V_104 ;
V_38 -> V_105 = V_70 -> V_96 . V_105 ;
V_38 -> V_101 = V_101 ;
if ( V_38 -> V_88 == V_93 ) {
if ( V_38 -> V_53 == V_52 )
V_60 = F_54 ( V_48 , F_23 ( V_38 ) ) ;
else
V_60 = F_57 ( V_48 , V_38 , NULL ) ;
}
if ( ! V_60 )
V_38 -> V_88 = V_106 ;
else
F_48 ( V_48 , V_38 ) ;
return V_60 ;
}
static void F_58 ( struct V_47 * V_48 ,
struct V_37 * V_38 )
{
struct V_69 * V_70 = V_48 -> V_95 ;
struct V_1 * V_2 = V_70 -> V_2 ;
enum V_107 V_88 = V_38 -> V_88 ;
unsigned long V_83 ;
int V_60 ;
V_38 -> V_88 = V_108 ;
V_60 = F_59 ( & V_70 -> V_2 -> V_72 ,
F_23 ( V_38 ) -> V_44 ,
F_23 ( V_38 ) -> V_45 , V_38 -> V_57 ,
F_42 , V_38 ) ;
if ( ! V_60 ) {
F_43 ( & V_2 -> V_84 , V_83 ) ;
if ( ++ V_2 -> V_85 == 1
&& ! F_19 ( & V_2 -> V_36 ) )
F_15 ( V_2 ) ;
F_44 ( & V_2 -> V_84 , V_83 ) ;
} else {
F_6 ( V_2 -> V_6 , L_8 ) ;
F_6 ( V_2 -> V_6 , L_9 ) ;
V_38 -> V_88 = V_88 ;
}
}
static void F_60 ( struct V_1 * V_2 )
{
int V_109 = V_110 ;
F_13 ( V_2 -> V_10 ,
V_111 ,
V_112 ) ;
while ( ! ( F_18 ( V_2 -> V_10 , V_113 )
& V_114 )
&& -- V_109 ) {
F_61 ( 1 ) ;
}
if ( ! ( F_18 ( V_2 -> V_10 , V_113 )
& V_114 ) )
F_6 ( V_2 -> V_6 , L_10 ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
F_60 ( V_2 ) ;
F_13 ( V_2 -> V_10 , V_111 ,
V_115 ) ;
F_13 ( V_2 -> V_10 ,
V_116 + V_117 ,
V_118 ) ;
F_14 ( V_2 ) ;
F_63 ( & V_2 -> V_72 . V_40 ) ;
}
static void F_64 ( unsigned long V_119 )
{
struct V_1 * V_2 = (struct V_1 * ) V_119 ;
if ( ! F_19 ( & V_2 -> V_36 ) ) {
F_20 ( V_2 -> V_6 , L_11 ) ;
F_21 ( V_2 ) ;
}
}
static void F_65 ( struct V_1 * V_2 )
{
unsigned long V_83 ;
F_43 ( & V_2 -> V_84 , V_83 ) ;
if ( F_66 ( & V_2 -> V_36 ) != 1 ) {
F_44 ( & V_2 -> V_84 , V_83 ) ;
return;
}
F_16 ( V_2 ) ;
F_44 ( & V_2 -> V_84 , V_83 ) ;
F_67 ( & V_2 -> V_72 ) ;
}
static void F_68 ( struct V_1 * V_2 )
{
unsigned long V_83 ;
F_43 ( & V_2 -> V_84 , V_83 ) ;
if ( F_19 ( & V_2 -> V_36 ) != 1 )
goto V_64;
F_62 ( V_2 ) ;
F_69 ( V_2 ) ;
F_70 ( & V_2 -> V_72 ) ;
if ( V_2 -> V_85 )
F_15 ( V_2 ) ;
V_64:
F_71 ( & V_2 -> V_36 ) ;
F_44 ( & V_2 -> V_84 , V_83 ) ;
}
static T_3
F_72 ( struct V_120 * V_6 , struct V_121 * V_122 ,
char * V_123 )
{
struct V_1 * V_2 = F_73 ( V_6 ) ;
return sprintf ( V_123 , L_12 , V_2 -> V_75 ? L_13 : L_14 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_65 ( V_2 ) ;
F_68 ( V_2 ) ;
}
static T_4 F_74 ( int V_124 , void * V_74 )
{
struct V_1 * V_2 = (struct V_1 * ) V_74 ;
T_1 V_125 ;
unsigned int V_126 = 0 ;
V_125 = F_18 ( V_2 -> V_10 , V_127 ) ;
if ( V_125 &
( V_128 | V_129
| V_130 ) ) {
F_75 ( & V_2 -> V_72 . V_40 ) ;
V_126 = 1 ;
}
if ( V_125 & V_131 ) {
F_17 ( V_2 ) ;
V_126 = 1 ;
}
if ( V_125 & V_132 )
F_6 ( V_2 -> V_6 , L_15 ) ;
return F_76 ( V_126 ) ;
}
static int F_69 ( struct V_1 * V_2 )
{
int V_5 ;
struct V_133 V_134 ;
V_5 = F_77 ( V_2 -> V_135 , & V_134 ) ;
if ( V_5 ) {
F_6 ( V_2 -> V_6 , L_16 , V_5 ) ;
return V_5 ;
}
V_2 -> V_136 = V_134 . V_136 ;
V_2 -> V_26 = V_137 ;
switch ( V_134 . V_136 ) {
case V_138 :
if ( V_134 . V_139 . V_140 . V_141 )
V_2 -> V_26 |= V_142 ;
if ( V_134 . V_139 . V_140 . V_143 )
V_2 -> V_26 |= V_144 ;
if ( V_134 . V_139 . V_140 . V_145 )
V_2 -> V_26 |= V_146 ;
if ( V_134 . V_139 . V_140 . V_147 )
V_2 -> V_26 |= V_148 ;
if ( V_134 . V_139 . V_140 . V_149 )
V_2 -> V_26 |= V_150 ;
if ( V_134 . V_139 . V_140 . V_151 )
V_2 -> V_26 |= V_152 ;
switch ( V_134 . V_139 . V_140 . V_153 ) {
case V_154 :
V_2 -> V_26 |= V_155 ;
break;
case V_156 :
V_2 -> V_26 |= V_157 ;
break;
case V_158 :
V_2 -> V_26 |= V_159 ;
break;
case V_160 :
V_2 -> V_26 |= V_161 ;
break;
case V_162 :
V_2 -> V_26 |= V_163 ;
break;
default:
F_6 ( V_2 -> V_6 ,
L_17 ,
V_134 . V_139 . V_140 . V_153 ) ;
return - V_103 ;
}
if ( V_134 . V_139 . V_140 . V_164 != V_2 -> V_165 . V_140 . V_7 ) {
T_1 V_7 = V_134 . V_139 . V_140 . V_164 ;
T_1 V_8 ;
if ( V_7 == 0 )
return - V_103 ;
if ( V_7 > V_9 )
V_7 = V_9 ;
V_8 = V_9 / V_7 ;
if ( V_8 * V_7 < V_9 )
V_8 ++ ;
if ( V_9 / V_8 < V_134 . V_139 . V_140 . V_166
&& V_8 > 1 )
V_8 -- ;
if ( V_8 > 30 )
V_8 = 30 ;
V_7 = V_9 / V_8 ;
if ( V_7 < V_134 . V_139 . V_140 . V_166
|| V_7 > V_134 . V_139 . V_140 . V_167 )
return - V_103 ;
V_2 -> V_165 . V_140 . V_7 = V_7 ;
}
F_12 ( V_2 , V_2 -> V_165 . V_140 . V_7 ) ;
break;
default:
F_6 ( V_2 -> V_6 , L_18 ,
V_134 . V_136 ) ;
return - V_103 ;
}
return 0 ;
}
static void F_78 ( const struct V_1 * V_2 )
{
switch ( V_2 -> V_136 ) {
case V_138 :
F_12 ( V_2 , 0 ) ;
break;
}
}
static int F_79 ( struct V_1 * V_2 )
{
int V_60 = 0 ;
struct V_168 * V_135 = V_2 -> V_135 ;
F_8 ( V_2 ) ;
V_60 = F_69 ( V_2 ) ;
if ( V_60 ) {
F_6 ( V_2 -> V_6 , L_19
L_20 , V_60 ) ;
V_2 -> V_135 = NULL ;
goto V_64;
}
F_80 ( V_135 , 1 ) ;
V_60 = F_81 ( V_135 ) ;
if ( V_60 ) {
F_6 ( V_2 -> V_6 , L_21 , V_60 ) ;
V_2 -> V_135 = NULL ;
goto V_64;
}
F_82 ( V_2 -> V_6 , L_22 , V_135 -> V_169 ) ;
V_64:
F_78 ( V_2 ) ;
F_10 ( V_2 ) ;
F_80 ( V_135 , 0 ) ;
return V_60 ;
}
static void F_83 ( struct V_1 * V_2 )
{
if ( V_2 -> V_135 )
F_84 ( V_2 -> V_135 ) ;
}
static void F_85 ( struct V_1 * V_2 )
{
F_78 ( V_2 ) ;
F_10 ( V_2 ) ;
F_80 ( V_2 -> V_135 , 0 ) ;
}
static int F_86 ( struct V_1 * V_2 )
{
int V_5 ;
F_8 ( V_2 ) ;
F_69 ( V_2 ) ;
V_5 = F_80 ( V_2 -> V_135 , 1 ) ;
if ( V_5 )
goto V_64;
V_5 = F_87 ( V_2 -> V_135 ) ;
if ( V_5 )
goto V_64;
return 0 ;
V_64:
F_85 ( V_2 ) ;
return V_5 ;
}
static void F_88 ( struct V_170 * V_171 )
{
struct V_1 * V_2 =
F_41 ( V_171 , struct V_1 ,
V_172 ) ;
if ( F_19 ( & V_2 -> V_173 ) )
return;
F_65 ( V_2 ) ;
if ( F_89 ( V_2 -> V_135 ) == 0 ) {
F_87 ( V_2 -> V_135 ) ;
} else {
F_85 ( V_2 ) ;
F_86 ( V_2 ) ;
}
F_68 ( V_2 ) ;
}
static int F_90 ( struct V_174 * V_174 , void * V_70 ,
struct V_175 * V_176 )
{
struct V_69 * V_177 = V_70 ;
struct V_1 * V_2 = V_177 -> V_2 ;
F_91 ( V_176 -> V_178 , V_179 , sizeof( V_176 -> V_178 ) ) ;
F_91 ( V_176 -> V_180 , V_2 -> V_181 -> V_169 , sizeof( V_176 -> V_180 ) ) ;
V_176 -> V_182 = V_183 | V_184 ;
return 0 ;
}
static int F_92 ( struct V_174 * V_174 , void * V_70 ,
struct V_185 * V_186 )
{
struct V_69 * V_177 = V_70 ;
struct V_1 * V_2 = V_177 -> V_2 ;
int V_5 ;
V_5 = F_93 ( V_2 -> V_135 , V_186 ) ;
return V_5 ;
}
static int F_94 ( struct V_174 * V_174 , void * V_70 ,
struct V_187 * V_186 )
{
struct V_69 * V_177 = V_70 ;
struct V_1 * V_2 = V_177 -> V_2 ;
int V_5 ;
F_31 ( & V_2 -> V_188 ) ;
V_5 = F_95 ( V_2 -> V_135 , V_186 ) ;
F_32 ( & V_2 -> V_188 ) ;
return V_5 ;
}
static int F_96 ( struct V_174 * V_174 , void * V_70 ,
struct V_187 * V_186 )
{
struct V_69 * V_177 = V_70 ;
struct V_1 * V_2 = V_177 -> V_2 ;
int V_5 ;
F_31 ( & V_2 -> V_188 ) ;
if ( V_2 -> V_75 ) {
V_5 = - V_189 ;
goto V_64;
}
V_5 = F_97 ( V_2 -> V_135 , V_186 ) ;
V_64:
F_32 ( & V_2 -> V_188 ) ;
if ( ! V_5 ) {
F_31 ( & V_177 -> V_48 . V_49 ) ;
V_177 -> V_96 = V_186 -> V_190 . V_96 ;
F_32 ( & V_177 -> V_48 . V_49 ) ;
}
memset ( V_186 , 0 , sizeof( * V_186 ) ) ;
F_94 ( V_174 , V_70 , V_186 ) ;
return V_5 ;
}
static int F_98 ( struct V_174 * V_174 , void * V_70 ,
struct V_187 * V_186 )
{
struct V_69 * V_177 = V_70 ;
struct V_1 * V_2 = V_177 -> V_2 ;
int V_5 ;
F_31 ( & V_2 -> V_188 ) ;
V_5 = F_99 ( V_2 -> V_135 , V_186 ) ;
F_32 ( & V_2 -> V_188 ) ;
return V_5 ;
}
static int F_100 ( struct V_174 * V_174 , void * V_70 ,
struct V_191 * V_192 )
{
struct V_69 * V_177 = V_70 ;
struct V_1 * V_2 = V_177 -> V_2 ;
int V_5 ;
F_31 ( & V_2 -> V_188 ) ;
if ( V_2 -> V_75 ) {
F_32 ( & V_2 -> V_188 ) ;
return - V_189 ;
}
F_30 ( & V_177 -> V_48 ) ;
F_32 ( & V_2 -> V_188 ) ;
V_5 = F_101 ( & V_177 -> V_48 , V_192 ) ;
if ( V_5 < 0 || V_192 -> V_53 != V_52 )
goto V_64;
V_5 = F_40 ( & V_177 -> V_48 , V_5 ) ;
if ( V_5 )
F_30 ( & V_177 -> V_48 ) ;
V_64:
return V_5 ;
}
static int F_102 ( struct V_174 * V_174 , void * V_70 ,
struct V_193 * V_192 )
{
struct V_69 * V_177 = V_70 ;
return F_103 ( & V_177 -> V_48 , V_192 ) ;
}
static int F_104 ( struct V_174 * V_174 , void * V_70 , struct V_193 * V_192 )
{
struct V_69 * V_177 = V_70 ;
return F_105 ( & V_177 -> V_48 , V_192 ) ;
}
static int F_106 ( struct V_174 * V_174 , void * V_70 , struct V_193 * V_192 )
{
struct V_69 * V_177 = V_70 ;
struct V_1 * V_2 = V_177 -> V_2 ;
struct V_37 * V_38 ;
int V_5 ;
V_194:
V_5 = F_107 ( & V_177 -> V_48 , V_192 , V_174 -> V_195 & V_196 ) ;
if ( V_5 )
goto V_64;
V_38 = V_177 -> V_48 . V_51 [ V_192 -> V_197 ] ;
F_31 ( & V_2 -> V_188 ) ;
V_5 = F_108 ( V_2 -> V_135 , ( void * ) V_38 -> V_102 ) ;
F_32 ( & V_2 -> V_188 ) ;
if ( V_5 == - V_99 )
F_109 ( & V_2 -> V_172 ) ;
else
V_5 = 0 ;
V_64:
if ( V_5 == - V_99 ) {
F_105 ( & V_177 -> V_48 , V_192 ) ;
if ( ! ( V_174 -> V_195 & V_196 ) )
goto V_194;
V_5 = - V_198 ;
}
return V_5 ;
}
static int F_110 ( struct V_174 * V_174 , void * V_70 , enum V_199 V_43 )
{
struct V_69 * V_177 = V_70 ;
struct V_1 * V_2 = V_177 -> V_2 ;
int V_5 ;
F_31 ( & V_2 -> V_188 ) ;
if ( V_2 -> V_75 ) {
V_5 = - V_189 ;
goto V_64;
}
V_5 = F_69 ( V_2 ) ;
if ( V_5 ) {
F_20 ( V_2 -> V_6 , L_23 ) ;
goto V_64;
}
V_5 = F_111 ( & V_177 -> V_48 ) ;
if ( ! V_5 ) {
V_2 -> V_75 = V_174 ;
F_112 ( & V_2 -> V_6 -> V_200 , NULL , L_24 ) ;
}
V_64:
F_32 ( & V_2 -> V_188 ) ;
return V_5 ;
}
static int F_113 ( struct V_174 * V_174 , void * V_70 , enum V_199 V_43 )
{
struct V_69 * V_177 = V_70 ;
struct V_1 * V_2 = V_177 -> V_2 ;
struct V_47 * V_201 = & V_177 -> V_48 ;
int V_5 ;
F_114 ( & V_2 -> V_173 ) ;
F_115 ( & V_2 -> V_172 ) ;
V_5 = F_116 ( V_201 ) ;
if ( ! V_5 ) {
F_31 ( & V_2 -> V_188 ) ;
V_2 -> V_75 = NULL ;
F_32 ( & V_2 -> V_188 ) ;
F_112 ( & V_2 -> V_6 -> V_200 , NULL , L_24 ) ;
}
F_71 ( & V_2 -> V_173 ) ;
return V_5 ;
}
static int F_117 ( struct V_174 * V_174 , void * V_70 ,
struct V_202 * V_203 )
{
if ( V_203 -> V_197 > 0 )
return - V_103 ;
F_91 ( V_203 -> V_169 , L_25 , sizeof( V_203 -> V_169 ) ) ;
V_203 -> type = V_204 ;
return 0 ;
}
static int F_118 ( struct V_174 * V_174 , void * V_70 , unsigned int * V_43 )
{
* V_43 = 0 ;
return 0 ;
}
static int F_119 ( struct V_174 * V_174 , void * V_70 , unsigned int V_43 )
{
if ( V_43 > 0 )
return - V_103 ;
return 0 ;
}
static int F_120 ( struct V_174 * V_174 , void * V_70 ,
struct V_205 * V_206 )
{
struct V_69 * V_177 = V_70 ;
struct V_1 * V_2 = V_177 -> V_2 ;
int V_5 ;
V_5 = F_121 ( V_2 -> V_135 , V_206 ) ;
return V_5 ;
}
static int F_122 ( struct V_174 * V_174 , void * V_70 ,
struct V_207 * V_206 )
{
struct V_69 * V_177 = V_70 ;
struct V_1 * V_2 = V_177 -> V_2 ;
int V_5 ;
F_31 ( & V_2 -> V_188 ) ;
V_5 = F_123 ( V_2 -> V_135 , V_206 ) ;
F_32 ( & V_2 -> V_188 ) ;
return V_5 ;
}
static int F_124 ( struct V_174 * V_174 , void * V_70 ,
struct V_207 * V_206 )
{
struct V_69 * V_177 = V_70 ;
struct V_1 * V_2 = V_177 -> V_2 ;
int V_5 ;
F_31 ( & V_2 -> V_188 ) ;
V_5 = F_125 ( V_2 -> V_135 , V_206 ) ;
F_32 ( & V_2 -> V_188 ) ;
return V_5 ;
}
static int F_126 ( struct V_174 * V_174 , void * V_70 ,
struct V_208 * V_206 ) {
struct V_69 * V_177 = V_70 ;
struct V_1 * V_2 = V_177 -> V_2 ;
int V_5 ;
F_31 ( & V_2 -> V_188 ) ;
V_5 = F_127 ( V_2 -> V_135 , V_206 ) ;
F_32 ( & V_2 -> V_188 ) ;
return V_5 ;
}
static int F_128 ( struct V_174 * V_174 , void * V_70 ,
struct V_208 * V_206 )
{
struct V_69 * V_177 = V_70 ;
struct V_1 * V_2 = V_177 -> V_2 ;
struct V_208 V_209 ;
int V_5 ;
F_31 ( & V_2 -> V_188 ) ;
if ( V_2 -> V_75 ) {
V_5 = - V_189 ;
goto V_64;
}
V_209 . type = V_210 ;
V_5 = F_127 ( V_2 -> V_135 , & V_209 ) ;
if ( V_5 )
goto V_64;
V_5 = F_129 ( V_2 -> V_135 , V_206 ) ;
if ( V_5 )
goto V_64;
V_5 = F_69 ( V_2 ) ;
if ( V_5 )
F_129 ( V_2 -> V_135 , & V_209 ) ;
V_64:
F_32 ( & V_2 -> V_188 ) ;
return V_5 ;
}
static unsigned int F_130 ( struct V_174 * V_174 ,
struct V_211 * V_212 )
{
struct V_69 * V_70 = V_174 -> V_76 ;
struct V_1 * V_2 = V_70 -> V_2 ;
struct V_37 * V_38 ;
F_31 ( & V_2 -> V_188 ) ;
if ( V_2 -> V_75 != V_174 ) {
F_32 ( & V_2 -> V_188 ) ;
return V_213 ;
}
F_32 ( & V_2 -> V_188 ) ;
F_31 ( & V_70 -> V_48 . V_49 ) ;
if ( F_131 ( & V_70 -> V_48 . V_214 ) ) {
F_32 ( & V_70 -> V_48 . V_49 ) ;
return V_213 ;
}
V_38 = F_132 ( V_70 -> V_48 . V_214 . V_215 , struct V_37 , V_214 ) ;
F_32 ( & V_70 -> V_48 . V_49 ) ;
F_133 ( V_174 , & V_38 -> V_91 , V_212 ) ;
if ( V_38 -> V_88 == V_90 || V_38 -> V_88 == V_89 )
return V_216 | V_217 ;
return 0 ;
}
static int F_134 ( struct V_174 * V_174 ,
struct V_218 * V_219 )
{
struct V_69 * V_70 = V_174 -> V_76 ;
struct V_1 * V_2 = V_70 -> V_2 ;
struct V_47 * V_48 = & V_70 -> V_48 ;
unsigned int V_220 , V_221 , V_57 , V_43 , V_222 ;
int V_60 = 0 ;
F_31 ( & V_2 -> V_188 ) ;
if ( V_2 -> V_75 ) {
F_32 ( & V_2 -> V_188 ) ;
return - V_189 ;
}
F_32 ( & V_2 -> V_188 ) ;
F_31 ( & V_48 -> V_49 ) ;
for ( V_220 = 0 ; V_220 < V_50 ; V_220 ++ ) {
if ( NULL == V_48 -> V_51 [ V_220 ] )
continue;
if ( V_52 != V_48 -> V_51 [ V_220 ] -> V_53 )
continue;
if ( V_48 -> V_51 [ V_220 ] -> V_223 == ( V_219 -> V_224 << V_61 ) )
break;
}
for ( V_57 = 0 , V_221 = V_220 ; V_221 < V_50 ; V_221 ++ ) {
if ( NULL == V_48 -> V_51 [ V_221 ] )
continue;
if ( V_52 != V_48 -> V_51 [ V_221 ] -> V_53 )
continue;
V_57 += V_48 -> V_51 [ V_221 ] -> V_58 ;
if ( V_57 == ( V_219 -> V_225 - V_219 -> V_226 ) )
break;
}
V_57 = 0 ;
for ( V_43 = V_220 ; V_43 <= V_221 && V_43 < V_50 ; V_43 ++ ) {
struct V_39 * V_40 = F_23 ( V_48 -> V_51 [ V_43 ] ) ;
for ( V_222 = 0 ; V_222 < V_40 -> V_45 ; V_222 ++ ) {
V_60 = F_135 (
V_219 , V_219 -> V_226 + V_57 ,
F_136 ( F_25 ( & V_40 -> V_44 [ V_222 ] ) ) ,
F_24 ( & V_40 -> V_44 [ V_222 ] ) , V_219 -> V_227 ) ;
if ( V_60 )
goto V_64;
V_57 += F_24 ( & V_40 -> V_44 [ V_222 ] ) ;
}
}
V_64:
F_32 ( & V_48 -> V_49 ) ;
return V_60 ;
}
static int F_137 ( struct V_174 * V_174 , struct V_218 * V_219 )
{
struct V_69 * V_70 = V_174 -> V_76 ;
int V_5 ;
V_5 = F_138 ( & V_70 -> V_48 , V_219 ) ;
if ( V_5 )
return V_5 ;
V_219 -> V_227 = F_139 ( V_219 -> V_227 ) ;
V_5 = F_134 ( V_174 , V_219 ) ;
if ( V_5 )
F_29 ( V_219 -> V_228 ) ;
return V_5 ;
}
static int F_140 ( struct V_174 * V_174 )
{
struct V_1 * V_2 = V_229 . V_230 ;
struct V_69 * V_70 ;
struct V_187 V_231 ;
if ( ! V_2 || ! V_2 -> V_181 )
return - V_232 ;
V_70 = F_141 ( sizeof( * V_70 ) , V_62 ) ;
if ( V_70 == NULL )
return - V_63 ;
F_31 ( & V_2 -> V_188 ) ;
if ( V_2 -> V_135 == NULL || ! F_142 ( V_2 -> V_135 -> V_233 ) ) {
F_32 ( & V_2 -> V_188 ) ;
goto V_234;
}
if ( F_66 ( & V_2 -> V_235 ) == 1 ) {
F_62 ( V_2 ) ;
if ( F_86 ( V_2 ) ) {
F_32 ( & V_2 -> V_188 ) ;
goto V_236;
}
}
F_32 ( & V_2 -> V_188 ) ;
V_70 -> V_2 = V_2 ;
F_31 ( & V_2 -> V_188 ) ;
F_95 ( V_2 -> V_135 , & V_231 ) ;
F_32 ( & V_2 -> V_188 ) ;
V_70 -> V_96 = V_231 . V_190 . V_96 ;
V_174 -> V_76 = V_70 ;
F_143 ( & V_70 -> V_237 ) ;
F_144 ( & V_70 -> V_48 , & V_238 , NULL ,
& V_70 -> V_237 , V_210 ,
V_239 ,
sizeof( struct V_37 ) , V_70 , NULL ) ;
return 0 ;
V_236:
F_60 ( V_2 ) ;
F_145 ( V_2 -> V_135 -> V_233 ) ;
V_234:
F_29 ( V_70 ) ;
return - V_232 ;
}
static int F_146 ( struct V_174 * V_174 )
{
struct V_69 * V_70 = V_174 -> V_76 ;
struct V_1 * V_2 = V_70 -> V_2 ;
F_114 ( & V_2 -> V_173 ) ;
F_115 ( & V_2 -> V_172 ) ;
F_116 ( & V_70 -> V_48 ) ;
F_31 ( & V_2 -> V_188 ) ;
if ( V_2 -> V_75 == V_174 ) {
V_2 -> V_75 = NULL ;
F_32 ( & V_2 -> V_188 ) ;
F_112 ( & V_2 -> V_6 -> V_200 , NULL , L_24 ) ;
} else {
F_32 ( & V_2 -> V_188 ) ;
}
F_71 ( & V_2 -> V_173 ) ;
F_30 ( & V_70 -> V_48 ) ;
F_115 ( & V_2 -> V_172 ) ;
F_31 ( & V_2 -> V_188 ) ;
if ( F_147 ( & V_2 -> V_235 ) == 0 ) {
F_85 ( V_2 ) ;
F_60 ( V_2 ) ;
}
F_32 ( & V_2 -> V_188 ) ;
V_174 -> V_76 = NULL ;
F_145 ( V_2 -> V_135 -> V_233 ) ;
F_29 ( V_70 ) ;
return 0 ;
}
static int F_148 ( struct V_240 * V_241 , T_5 V_88 )
{
struct V_1 * V_2 = F_149 ( V_241 ) ;
if ( F_19 ( & V_2 -> V_235 ) == 0 )
return 0 ;
if ( ! F_19 ( & V_2 -> V_173 ) )
F_65 ( V_2 ) ;
F_85 ( V_2 ) ;
F_60 ( V_2 ) ;
return 0 ;
}
static int F_150 ( struct V_240 * V_241 )
{
struct V_1 * V_2 = F_149 ( V_241 ) ;
if ( F_19 ( & V_2 -> V_235 ) == 0 )
return 0 ;
F_62 ( V_2 ) ;
F_86 ( V_2 ) ;
if ( ! F_19 ( & V_2 -> V_173 ) )
F_68 ( V_2 ) ;
return 0 ;
}
static int F_151 ( struct V_168 * V_242 )
{
struct V_1 * V_2 = V_242 -> V_139 . V_243 -> V_244 -> V_230 ;
struct V_245 * V_181 ;
int V_5 ;
if ( V_2 -> V_135 )
return - V_189 ;
V_2 -> V_135 = V_242 ;
if ( F_152 ( V_2 -> V_6 , & V_246 ) != 0 ) {
F_6 ( V_2 -> V_6 , L_26 ) ;
V_5 = - V_189 ;
goto V_60;
}
V_181 = V_2 -> V_181 = F_153 () ;
if ( ! V_181 ) {
F_6 ( V_2 -> V_6 , L_27 ) ;
V_5 = - V_63 ;
goto V_60;
}
V_181 -> V_247 = V_248 ;
V_181 -> V_249 = V_2 -> V_6 ;
F_91 ( V_181 -> V_169 , V_179 , sizeof( V_181 -> V_169 ) ) ;
V_181 -> V_250 = & V_251 ;
V_181 -> V_252 = & V_253 ;
F_62 ( V_2 ) ;
V_5 = F_79 ( V_2 ) ;
if ( V_5 )
goto V_60;
if ( F_154 ( V_181 , V_254 , V_255 ) < 0 ) {
F_6 ( V_2 -> V_6 , L_28 ) ;
V_5 = - V_189 ;
goto V_60;
}
F_60 ( V_2 ) ;
F_82 ( V_2 -> V_6 , L_29 ,
F_155 ( V_181 ) ) ;
return 0 ;
V_60:
F_156 ( V_242 ) ;
return V_5 ;
}
static void F_156 ( struct V_168 * V_242 )
{
struct V_1 * V_2 = V_242 -> V_139 . V_243 -> V_244 -> V_230 ;
F_83 ( V_2 ) ;
if ( V_2 -> V_181 ) {
if ( ! F_157 ( V_2 -> V_181 ) ) {
V_248 ( V_2 -> V_181 ) ;
} else {
F_158 ( V_2 -> V_181 ) ;
}
V_2 -> V_181 = NULL ;
}
F_159 ( V_2 -> V_6 , & V_246 ) ;
V_2 -> V_135 = NULL ;
}
static int T_6 F_160 ( struct V_240 * V_241 )
{
struct V_1 * V_2 ;
struct V_256 * V_257 ;
int V_124 ;
V_2 = F_141 ( sizeof( * V_2 ) , V_62 ) ;
if ( ! V_2 ) {
F_6 ( & V_241 -> V_6 , L_30 ) ;
goto V_60;
}
F_161 ( V_241 , V_2 ) ;
V_2 -> V_6 = & V_241 -> V_6 ;
if ( V_98 < 320 * 240 * 2 * 2 )
V_98 = 320 * 240 * 2 * 2 ;
V_2 -> V_98 = V_98 ;
V_257 = F_162 ( V_241 , V_258 , 0 ) ;
if ( ! V_257 ) {
F_6 ( V_2 -> V_6 , L_31 ) ;
goto V_60;
}
if ( ! F_163 ( V_257 -> V_259 , F_164 ( V_257 ) , V_241 -> V_169 ) ) {
F_6 ( V_2 -> V_6 ,
L_32 ) ;
goto V_60;
}
V_2 -> V_260 = V_257 -> V_259 ;
V_2 -> V_261 = F_164 ( V_257 ) ;
V_2 -> V_10 = F_165 ( V_2 -> V_260 , V_2 -> V_261 ) ;
if ( ! V_2 -> V_10 ) {
F_6 ( V_2 -> V_6 , L_33 ) ;
goto V_60;
}
V_124 = F_166 ( V_241 , 0 ) ;
if ( V_124 <= 0 ) {
F_6 ( V_2 -> V_6 , L_34 ) ;
goto V_60;
}
if ( F_167 ( V_124 , F_74 , 0 , V_179 , V_2 ) ) {
F_6 ( V_2 -> V_6 ,
L_35 ) ;
goto V_60;
}
V_2 -> V_124 = V_124 ;
if ( F_4 ( V_2 ) )
goto V_60;
F_168 ( & V_2 -> V_172 , F_88 ) ;
F_169 ( & V_2 -> V_188 ) ;
F_143 ( & V_2 -> V_84 ) ;
F_170 ( & V_2 -> V_72 ,
V_2 -> V_10 + V_262 ,
F_64 ,
( unsigned long ) V_2 ) ;
V_229 . V_230 = V_2 ;
if ( F_171 ( & V_229 ) )
goto V_60;
return 0 ;
V_60:
F_172 ( V_241 ) ;
return - V_232 ;
}
static int F_172 ( struct V_240 * V_241 )
{
struct V_1 * V_2 = F_149 ( V_241 ) ;
if ( ! V_2 )
return 0 ;
if ( V_229 . V_230 != NULL )
F_173 ( & V_229 ) ;
V_229 . V_230 = NULL ;
F_1 ( V_2 ) ;
if ( V_2 -> V_124 ) {
F_174 ( V_2 -> V_124 , V_2 ) ;
V_2 -> V_124 = 0 ;
}
if ( V_2 -> V_10 ) {
F_175 ( ( void * ) V_2 -> V_10 ) ;
V_2 -> V_10 = 0 ;
}
if ( V_2 -> V_260 ) {
F_176 ( V_2 -> V_260 , V_2 -> V_261 ) ;
V_2 -> V_260 = 0 ;
}
F_29 ( V_2 ) ;
return 0 ;
}
