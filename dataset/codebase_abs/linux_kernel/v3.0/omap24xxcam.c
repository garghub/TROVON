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
V_42 = F_36 ( V_62 | V_65 , V_56 ) ;
while ( V_42 == NULL ) {
V_56 -- ;
V_42 = F_36 ( V_62 | V_65 , V_56 ) ;
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
V_40 -> V_66 = V_40 -> V_45 ;
V_40 -> V_67 = V_68 ;
return 0 ;
V_64:
F_22 ( V_38 ) ;
return V_60 ;
}
static int F_40 ( struct V_47 * V_48 ,
unsigned int V_69 )
{
int V_43 , V_60 = 0 ;
struct V_70 * V_71 =
F_41 ( V_48 , struct V_70 , V_48 ) ;
F_31 ( & V_48 -> V_49 ) ;
for ( V_43 = 0 ; V_43 < V_69 ; V_43 ++ ) {
V_60 = F_34 ( V_48 -> V_51 [ V_43 ] ) ;
if ( V_60 )
goto V_64;
F_20 ( V_71 -> V_2 -> V_6 , L_6 ,
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
static void F_42 ( struct V_72 * V_73 ,
T_1 V_74 , void * V_75 )
{
struct V_1 * V_2 =
F_41 ( V_73 , struct V_1 , V_73 ) ;
struct V_70 * V_71 = V_2 -> V_76 -> V_77 ;
struct V_37 * V_38 = (struct V_37 * ) V_75 ;
const T_1 V_78 = V_79
| V_80 | V_81
| V_82 | V_83 ;
unsigned long V_84 ;
F_43 ( & V_2 -> V_85 , V_84 ) ;
if ( -- V_2 -> V_86 == 0 )
F_16 ( V_2 ) ;
F_44 ( & V_2 -> V_85 , V_84 ) ;
F_45 ( & V_38 -> V_87 ) ;
V_38 -> V_88 = F_46 ( 2 , & V_71 -> V_88 ) ;
if ( V_74 & V_78 ) {
V_38 -> V_89 = V_90 ;
if ( ! F_19 ( & V_71 -> V_2 -> V_36 ) ) {
F_20 ( V_2 -> V_6 , L_7 , V_74 ) ;
F_21 ( V_2 ) ;
}
} else
V_38 -> V_89 = V_91 ;
F_47 ( & V_38 -> V_92 ) ;
}
static void F_48 ( struct V_47 * V_48 ,
struct V_37 * V_38 )
{
struct V_39 * V_40 = F_23 ( V_38 ) ;
F_49 ( V_48 , V_38 , 0 , 0 ) ;
if ( V_38 -> V_53 == V_52 ) {
F_50 ( V_48 -> V_6 , V_40 -> V_44 , V_40 -> V_45 ,
V_40 -> V_67 ) ;
V_40 -> V_67 = V_93 ;
} else {
F_51 ( V_48 -> V_6 , F_23 ( V_38 ) ) ;
F_52 ( F_23 ( V_38 ) ) ;
}
V_38 -> V_89 = V_94 ;
}
static int F_53 ( struct V_47 * V_48 , unsigned int * V_95 ,
unsigned int * V_57 )
{
struct V_70 * V_71 = V_48 -> V_96 ;
if ( * V_95 <= 0 )
* V_95 = V_50 ;
if ( * V_95 > V_50 )
* V_95 = V_50 ;
* V_57 = V_71 -> V_97 . V_98 ;
if ( * V_57 * * V_95 > V_71 -> V_2 -> V_99 )
* V_95 = V_71 -> V_2 -> V_99 / * V_57 ;
return 0 ;
}
static int F_54 ( struct V_47 * V_48 ,
struct V_39 * V_40 )
{
int V_60 = 0 ;
V_40 -> V_67 = V_68 ;
if ( ! F_55 ( V_48 -> V_6 , V_40 -> V_44 , V_40 -> V_45 , V_40 -> V_67 ) ) {
F_29 ( V_40 -> V_44 ) ;
V_40 -> V_44 = NULL ;
V_40 -> V_45 = 0 ;
V_60 = - V_100 ;
}
return V_60 ;
}
static int F_56 ( struct V_47 * V_48 ,
struct V_37 * V_38 ,
enum V_101 V_102 )
{
struct V_70 * V_71 = V_48 -> V_96 ;
int V_60 = 0 ;
if ( V_38 -> V_103 ) {
if ( V_71 -> V_97 . V_98 > V_38 -> V_58 ) {
V_60 = - V_104 ;
} else
V_38 -> V_57 = V_71 -> V_97 . V_98 ;
} else {
if ( V_38 -> V_89 != V_94 ) {
if ( V_71 -> V_97 . V_98 > V_38 -> V_57 ) {
F_48 ( V_48 , V_38 ) ;
V_38 -> V_57 = V_71 -> V_97 . V_98 ;
}
} else {
V_38 -> V_57 = V_71 -> V_97 . V_98 ;
}
}
if ( V_60 )
return V_60 ;
V_38 -> V_105 = V_71 -> V_97 . V_105 ;
V_38 -> V_106 = V_71 -> V_97 . V_106 ;
V_38 -> V_102 = V_102 ;
if ( V_38 -> V_89 == V_94 ) {
if ( V_38 -> V_53 == V_52 )
V_60 = F_54 ( V_48 , F_23 ( V_38 ) ) ;
else
V_60 = F_57 ( V_48 , V_38 , NULL ) ;
}
if ( ! V_60 )
V_38 -> V_89 = V_107 ;
else
F_48 ( V_48 , V_38 ) ;
return V_60 ;
}
static void F_58 ( struct V_47 * V_48 ,
struct V_37 * V_38 )
{
struct V_70 * V_71 = V_48 -> V_96 ;
struct V_1 * V_2 = V_71 -> V_2 ;
enum V_108 V_89 = V_38 -> V_89 ;
unsigned long V_84 ;
int V_60 ;
V_38 -> V_89 = V_109 ;
V_60 = F_59 ( & V_71 -> V_2 -> V_73 ,
F_23 ( V_38 ) -> V_44 ,
F_23 ( V_38 ) -> V_45 , V_38 -> V_57 ,
F_42 , V_38 ) ;
if ( ! V_60 ) {
F_43 ( & V_2 -> V_85 , V_84 ) ;
if ( ++ V_2 -> V_86 == 1
&& ! F_19 ( & V_2 -> V_36 ) )
F_15 ( V_2 ) ;
F_44 ( & V_2 -> V_85 , V_84 ) ;
} else {
F_6 ( V_2 -> V_6 , L_8 ) ;
F_6 ( V_2 -> V_6 , L_9 ) ;
V_38 -> V_89 = V_89 ;
}
}
static void F_60 ( struct V_1 * V_2 )
{
int V_110 = V_111 ;
F_13 ( V_2 -> V_10 ,
V_112 ,
V_113 ) ;
while ( ! ( F_18 ( V_2 -> V_10 , V_114 )
& V_115 )
&& -- V_110 ) {
F_61 ( 1 ) ;
}
if ( ! ( F_18 ( V_2 -> V_10 , V_114 )
& V_115 ) )
F_6 ( V_2 -> V_6 , L_10 ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
F_60 ( V_2 ) ;
F_13 ( V_2 -> V_10 , V_112 ,
V_116 ) ;
F_13 ( V_2 -> V_10 ,
V_117 + V_118 ,
V_119 ) ;
F_14 ( V_2 ) ;
F_63 ( & V_2 -> V_73 . V_40 ) ;
}
static void F_64 ( unsigned long V_120 )
{
struct V_1 * V_2 = (struct V_1 * ) V_120 ;
if ( ! F_19 ( & V_2 -> V_36 ) ) {
F_20 ( V_2 -> V_6 , L_11 ) ;
F_21 ( V_2 ) ;
}
}
static void F_65 ( struct V_1 * V_2 )
{
unsigned long V_84 ;
F_43 ( & V_2 -> V_85 , V_84 ) ;
if ( F_66 ( & V_2 -> V_36 ) != 1 ) {
F_44 ( & V_2 -> V_85 , V_84 ) ;
return;
}
F_16 ( V_2 ) ;
F_44 ( & V_2 -> V_85 , V_84 ) ;
F_67 ( & V_2 -> V_73 ) ;
}
static void F_68 ( struct V_1 * V_2 )
{
unsigned long V_84 ;
F_43 ( & V_2 -> V_85 , V_84 ) ;
if ( F_19 ( & V_2 -> V_36 ) != 1 )
goto V_64;
F_62 ( V_2 ) ;
F_69 ( V_2 ) ;
F_70 ( & V_2 -> V_73 ) ;
if ( V_2 -> V_86 )
F_15 ( V_2 ) ;
V_64:
F_71 ( & V_2 -> V_36 ) ;
F_44 ( & V_2 -> V_85 , V_84 ) ;
}
static T_3
F_72 ( struct V_121 * V_6 , struct V_122 * V_123 ,
char * V_124 )
{
struct V_1 * V_2 = F_73 ( V_6 ) ;
return sprintf ( V_124 , L_12 , V_2 -> V_76 ? L_13 : L_14 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_65 ( V_2 ) ;
F_68 ( V_2 ) ;
}
static T_4 F_74 ( int V_125 , void * V_75 )
{
struct V_1 * V_2 = (struct V_1 * ) V_75 ;
T_1 V_126 ;
unsigned int V_127 = 0 ;
V_126 = F_18 ( V_2 -> V_10 , V_128 ) ;
if ( V_126 &
( V_129 | V_130
| V_131 ) ) {
F_75 ( & V_2 -> V_73 . V_40 ) ;
V_127 = 1 ;
}
if ( V_126 & V_132 ) {
F_17 ( V_2 ) ;
V_127 = 1 ;
}
if ( V_126 & V_133 )
F_6 ( V_2 -> V_6 , L_15 ) ;
return F_76 ( V_127 ) ;
}
static int F_69 ( struct V_1 * V_2 )
{
int V_5 ;
struct V_134 V_135 ;
V_5 = F_77 ( V_2 -> V_136 , & V_135 ) ;
if ( V_5 ) {
F_6 ( V_2 -> V_6 , L_16 , V_5 ) ;
return V_5 ;
}
V_2 -> V_137 = V_135 . V_137 ;
V_2 -> V_26 = V_138 ;
switch ( V_135 . V_137 ) {
case V_139 :
if ( V_135 . V_140 . V_141 . V_142 )
V_2 -> V_26 |= V_143 ;
if ( V_135 . V_140 . V_141 . V_144 )
V_2 -> V_26 |= V_145 ;
if ( V_135 . V_140 . V_141 . V_146 )
V_2 -> V_26 |= V_147 ;
if ( V_135 . V_140 . V_141 . V_148 )
V_2 -> V_26 |= V_149 ;
if ( V_135 . V_140 . V_141 . V_150 )
V_2 -> V_26 |= V_151 ;
if ( V_135 . V_140 . V_141 . V_152 )
V_2 -> V_26 |= V_153 ;
switch ( V_135 . V_140 . V_141 . V_154 ) {
case V_155 :
V_2 -> V_26 |= V_156 ;
break;
case V_157 :
V_2 -> V_26 |= V_158 ;
break;
case V_159 :
V_2 -> V_26 |= V_160 ;
break;
case V_161 :
V_2 -> V_26 |= V_162 ;
break;
case V_163 :
V_2 -> V_26 |= V_164 ;
break;
default:
F_6 ( V_2 -> V_6 ,
L_17 ,
V_135 . V_140 . V_141 . V_154 ) ;
return - V_104 ;
}
if ( V_135 . V_140 . V_141 . V_165 != V_2 -> V_166 . V_141 . V_7 ) {
T_1 V_7 = V_135 . V_140 . V_141 . V_165 ;
T_1 V_8 ;
if ( V_7 == 0 )
return - V_104 ;
if ( V_7 > V_9 )
V_7 = V_9 ;
V_8 = V_9 / V_7 ;
if ( V_8 * V_7 < V_9 )
V_8 ++ ;
if ( V_9 / V_8 < V_135 . V_140 . V_141 . V_167
&& V_8 > 1 )
V_8 -- ;
if ( V_8 > 30 )
V_8 = 30 ;
V_7 = V_9 / V_8 ;
if ( V_7 < V_135 . V_140 . V_141 . V_167
|| V_7 > V_135 . V_140 . V_141 . V_168 )
return - V_104 ;
V_2 -> V_166 . V_141 . V_7 = V_7 ;
}
F_12 ( V_2 , V_2 -> V_166 . V_141 . V_7 ) ;
break;
default:
F_6 ( V_2 -> V_6 , L_18 ,
V_135 . V_137 ) ;
return - V_104 ;
}
return 0 ;
}
static void F_78 ( const struct V_1 * V_2 )
{
switch ( V_2 -> V_137 ) {
case V_139 :
F_12 ( V_2 , 0 ) ;
break;
}
}
static int F_79 ( struct V_1 * V_2 )
{
int V_60 = 0 ;
struct V_169 * V_136 = V_2 -> V_136 ;
F_8 ( V_2 ) ;
V_60 = F_69 ( V_2 ) ;
if ( V_60 ) {
F_6 ( V_2 -> V_6 , L_19
L_20 , V_60 ) ;
V_2 -> V_136 = NULL ;
goto V_64;
}
F_80 ( V_136 , 1 ) ;
V_60 = F_81 ( V_136 ) ;
if ( V_60 ) {
F_6 ( V_2 -> V_6 , L_21 , V_60 ) ;
V_2 -> V_136 = NULL ;
goto V_64;
}
F_82 ( V_2 -> V_6 , L_22 , V_136 -> V_170 ) ;
V_64:
F_78 ( V_2 ) ;
F_10 ( V_2 ) ;
F_80 ( V_136 , 0 ) ;
return V_60 ;
}
static void F_83 ( struct V_1 * V_2 )
{
if ( V_2 -> V_136 )
F_84 ( V_2 -> V_136 ) ;
}
static void F_85 ( struct V_1 * V_2 )
{
F_78 ( V_2 ) ;
F_10 ( V_2 ) ;
F_80 ( V_2 -> V_136 , 0 ) ;
}
static int F_86 ( struct V_1 * V_2 )
{
int V_5 ;
F_8 ( V_2 ) ;
F_69 ( V_2 ) ;
V_5 = F_80 ( V_2 -> V_136 , 1 ) ;
if ( V_5 )
goto V_64;
V_5 = F_87 ( V_2 -> V_136 ) ;
if ( V_5 )
goto V_64;
return 0 ;
V_64:
F_85 ( V_2 ) ;
return V_5 ;
}
static void F_88 ( struct V_171 * V_172 )
{
struct V_1 * V_2 =
F_41 ( V_172 , struct V_1 ,
V_173 ) ;
if ( F_19 ( & V_2 -> V_174 ) )
return;
F_65 ( V_2 ) ;
if ( F_89 ( V_2 -> V_136 ) == 0 ) {
F_87 ( V_2 -> V_136 ) ;
} else {
F_85 ( V_2 ) ;
F_86 ( V_2 ) ;
}
F_68 ( V_2 ) ;
}
static int F_90 ( struct V_175 * V_175 , void * V_71 ,
struct V_176 * V_177 )
{
struct V_70 * V_178 = V_71 ;
struct V_1 * V_2 = V_178 -> V_2 ;
F_91 ( V_177 -> V_179 , V_180 , sizeof( V_177 -> V_179 ) ) ;
F_91 ( V_177 -> V_181 , V_2 -> V_182 -> V_170 , sizeof( V_177 -> V_181 ) ) ;
V_177 -> V_183 = V_184 ;
V_177 -> V_185 = V_186 | V_187 ;
return 0 ;
}
static int F_92 ( struct V_175 * V_175 , void * V_71 ,
struct V_188 * V_189 )
{
struct V_70 * V_178 = V_71 ;
struct V_1 * V_2 = V_178 -> V_2 ;
int V_5 ;
V_5 = F_93 ( V_2 -> V_136 , V_189 ) ;
return V_5 ;
}
static int F_94 ( struct V_175 * V_175 , void * V_71 ,
struct V_190 * V_189 )
{
struct V_70 * V_178 = V_71 ;
struct V_1 * V_2 = V_178 -> V_2 ;
int V_5 ;
F_31 ( & V_2 -> V_191 ) ;
V_5 = F_95 ( V_2 -> V_136 , V_189 ) ;
F_32 ( & V_2 -> V_191 ) ;
return V_5 ;
}
static int F_96 ( struct V_175 * V_175 , void * V_71 ,
struct V_190 * V_189 )
{
struct V_70 * V_178 = V_71 ;
struct V_1 * V_2 = V_178 -> V_2 ;
int V_5 ;
F_31 ( & V_2 -> V_191 ) ;
if ( V_2 -> V_76 ) {
V_5 = - V_192 ;
goto V_64;
}
V_5 = F_97 ( V_2 -> V_136 , V_189 ) ;
V_64:
F_32 ( & V_2 -> V_191 ) ;
if ( ! V_5 ) {
F_31 ( & V_178 -> V_48 . V_49 ) ;
V_178 -> V_97 = V_189 -> V_193 . V_97 ;
F_32 ( & V_178 -> V_48 . V_49 ) ;
}
memset ( V_189 , 0 , sizeof( * V_189 ) ) ;
F_94 ( V_175 , V_71 , V_189 ) ;
return V_5 ;
}
static int F_98 ( struct V_175 * V_175 , void * V_71 ,
struct V_190 * V_189 )
{
struct V_70 * V_178 = V_71 ;
struct V_1 * V_2 = V_178 -> V_2 ;
int V_5 ;
F_31 ( & V_2 -> V_191 ) ;
V_5 = F_99 ( V_2 -> V_136 , V_189 ) ;
F_32 ( & V_2 -> V_191 ) ;
return V_5 ;
}
static int F_100 ( struct V_175 * V_175 , void * V_71 ,
struct V_194 * V_195 )
{
struct V_70 * V_178 = V_71 ;
struct V_1 * V_2 = V_178 -> V_2 ;
int V_5 ;
F_31 ( & V_2 -> V_191 ) ;
if ( V_2 -> V_76 ) {
F_32 ( & V_2 -> V_191 ) ;
return - V_192 ;
}
F_30 ( & V_178 -> V_48 ) ;
F_32 ( & V_2 -> V_191 ) ;
V_5 = F_101 ( & V_178 -> V_48 , V_195 ) ;
if ( V_5 < 0 || V_195 -> V_53 != V_52 )
goto V_64;
V_5 = F_40 ( & V_178 -> V_48 , V_5 ) ;
if ( V_5 )
F_30 ( & V_178 -> V_48 ) ;
V_64:
return V_5 ;
}
static int F_102 ( struct V_175 * V_175 , void * V_71 ,
struct V_196 * V_195 )
{
struct V_70 * V_178 = V_71 ;
return F_103 ( & V_178 -> V_48 , V_195 ) ;
}
static int F_104 ( struct V_175 * V_175 , void * V_71 , struct V_196 * V_195 )
{
struct V_70 * V_178 = V_71 ;
return F_105 ( & V_178 -> V_48 , V_195 ) ;
}
static int F_106 ( struct V_175 * V_175 , void * V_71 , struct V_196 * V_195 )
{
struct V_70 * V_178 = V_71 ;
struct V_1 * V_2 = V_178 -> V_2 ;
struct V_37 * V_38 ;
int V_5 ;
V_197:
V_5 = F_107 ( & V_178 -> V_48 , V_195 , V_175 -> V_198 & V_199 ) ;
if ( V_5 )
goto V_64;
V_38 = V_178 -> V_48 . V_51 [ V_195 -> V_200 ] ;
F_31 ( & V_2 -> V_191 ) ;
V_5 = F_108 ( V_2 -> V_136 , ( void * ) V_38 -> V_103 ) ;
F_32 ( & V_2 -> V_191 ) ;
if ( V_5 == - V_100 )
F_109 ( & V_2 -> V_173 ) ;
else
V_5 = 0 ;
V_64:
if ( V_5 == - V_100 ) {
F_105 ( & V_178 -> V_48 , V_195 ) ;
if ( ! ( V_175 -> V_198 & V_199 ) )
goto V_197;
V_5 = - V_201 ;
}
return V_5 ;
}
static int F_110 ( struct V_175 * V_175 , void * V_71 , enum V_202 V_43 )
{
struct V_70 * V_178 = V_71 ;
struct V_1 * V_2 = V_178 -> V_2 ;
int V_5 ;
F_31 ( & V_2 -> V_191 ) ;
if ( V_2 -> V_76 ) {
V_5 = - V_192 ;
goto V_64;
}
V_5 = F_69 ( V_2 ) ;
if ( V_5 ) {
F_20 ( V_2 -> V_6 , L_23 ) ;
goto V_64;
}
V_5 = F_111 ( & V_178 -> V_48 ) ;
if ( ! V_5 ) {
V_2 -> V_76 = V_175 ;
F_112 ( & V_2 -> V_6 -> V_203 , NULL , L_24 ) ;
}
V_64:
F_32 ( & V_2 -> V_191 ) ;
return V_5 ;
}
static int F_113 ( struct V_175 * V_175 , void * V_71 , enum V_202 V_43 )
{
struct V_70 * V_178 = V_71 ;
struct V_1 * V_2 = V_178 -> V_2 ;
struct V_47 * V_204 = & V_178 -> V_48 ;
int V_5 ;
F_114 ( & V_2 -> V_174 ) ;
F_115 ( & V_2 -> V_173 ) ;
V_5 = F_116 ( V_204 ) ;
if ( ! V_5 ) {
F_31 ( & V_2 -> V_191 ) ;
V_2 -> V_76 = NULL ;
F_32 ( & V_2 -> V_191 ) ;
F_112 ( & V_2 -> V_6 -> V_203 , NULL , L_24 ) ;
}
F_71 ( & V_2 -> V_174 ) ;
return V_5 ;
}
static int F_117 ( struct V_175 * V_175 , void * V_71 ,
struct V_205 * V_206 )
{
if ( V_206 -> V_200 > 0 )
return - V_104 ;
F_91 ( V_206 -> V_170 , L_25 , sizeof( V_206 -> V_170 ) ) ;
V_206 -> type = V_207 ;
return 0 ;
}
static int F_118 ( struct V_175 * V_175 , void * V_71 , unsigned int * V_43 )
{
* V_43 = 0 ;
return 0 ;
}
static int F_119 ( struct V_175 * V_175 , void * V_71 , unsigned int V_43 )
{
if ( V_43 > 0 )
return - V_104 ;
return 0 ;
}
static int F_120 ( struct V_175 * V_175 , void * V_71 ,
struct V_208 * V_209 )
{
struct V_70 * V_178 = V_71 ;
struct V_1 * V_2 = V_178 -> V_2 ;
int V_5 ;
V_5 = F_121 ( V_2 -> V_136 , V_209 ) ;
return V_5 ;
}
static int F_122 ( struct V_175 * V_175 , void * V_71 ,
struct V_210 * V_209 )
{
struct V_70 * V_178 = V_71 ;
struct V_1 * V_2 = V_178 -> V_2 ;
int V_5 ;
F_31 ( & V_2 -> V_191 ) ;
V_5 = F_123 ( V_2 -> V_136 , V_209 ) ;
F_32 ( & V_2 -> V_191 ) ;
return V_5 ;
}
static int F_124 ( struct V_175 * V_175 , void * V_71 ,
struct V_210 * V_209 )
{
struct V_70 * V_178 = V_71 ;
struct V_1 * V_2 = V_178 -> V_2 ;
int V_5 ;
F_31 ( & V_2 -> V_191 ) ;
V_5 = F_125 ( V_2 -> V_136 , V_209 ) ;
F_32 ( & V_2 -> V_191 ) ;
return V_5 ;
}
static int F_126 ( struct V_175 * V_175 , void * V_71 ,
struct V_211 * V_209 ) {
struct V_70 * V_178 = V_71 ;
struct V_1 * V_2 = V_178 -> V_2 ;
int V_5 ;
F_31 ( & V_2 -> V_191 ) ;
V_5 = F_127 ( V_2 -> V_136 , V_209 ) ;
F_32 ( & V_2 -> V_191 ) ;
return V_5 ;
}
static int F_128 ( struct V_175 * V_175 , void * V_71 ,
struct V_211 * V_209 )
{
struct V_70 * V_178 = V_71 ;
struct V_1 * V_2 = V_178 -> V_2 ;
struct V_211 V_212 ;
int V_5 ;
F_31 ( & V_2 -> V_191 ) ;
if ( V_2 -> V_76 ) {
V_5 = - V_192 ;
goto V_64;
}
V_212 . type = V_213 ;
V_5 = F_127 ( V_2 -> V_136 , & V_212 ) ;
if ( V_5 )
goto V_64;
V_5 = F_129 ( V_2 -> V_136 , V_209 ) ;
if ( V_5 )
goto V_64;
V_5 = F_69 ( V_2 ) ;
if ( V_5 )
F_129 ( V_2 -> V_136 , & V_212 ) ;
V_64:
F_32 ( & V_2 -> V_191 ) ;
return V_5 ;
}
static unsigned int F_130 ( struct V_175 * V_175 ,
struct V_214 * V_215 )
{
struct V_70 * V_71 = V_175 -> V_77 ;
struct V_1 * V_2 = V_71 -> V_2 ;
struct V_37 * V_38 ;
F_31 ( & V_2 -> V_191 ) ;
if ( V_2 -> V_76 != V_175 ) {
F_32 ( & V_2 -> V_191 ) ;
return V_216 ;
}
F_32 ( & V_2 -> V_191 ) ;
F_31 ( & V_71 -> V_48 . V_49 ) ;
if ( F_131 ( & V_71 -> V_48 . V_217 ) ) {
F_32 ( & V_71 -> V_48 . V_49 ) ;
return V_216 ;
}
V_38 = F_132 ( V_71 -> V_48 . V_217 . V_218 , struct V_37 , V_217 ) ;
F_32 ( & V_71 -> V_48 . V_49 ) ;
F_133 ( V_175 , & V_38 -> V_92 , V_215 ) ;
if ( V_38 -> V_89 == V_91 || V_38 -> V_89 == V_90 )
return V_219 | V_220 ;
return 0 ;
}
static int F_134 ( struct V_175 * V_175 ,
struct V_221 * V_222 )
{
struct V_70 * V_71 = V_175 -> V_77 ;
struct V_1 * V_2 = V_71 -> V_2 ;
struct V_47 * V_48 = & V_71 -> V_48 ;
unsigned int V_223 , V_224 , V_57 , V_43 , V_225 ;
int V_60 = 0 ;
F_31 ( & V_2 -> V_191 ) ;
if ( V_2 -> V_76 ) {
F_32 ( & V_2 -> V_191 ) ;
return - V_192 ;
}
F_32 ( & V_2 -> V_191 ) ;
F_31 ( & V_48 -> V_49 ) ;
for ( V_223 = 0 ; V_223 < V_50 ; V_223 ++ ) {
if ( NULL == V_48 -> V_51 [ V_223 ] )
continue;
if ( V_52 != V_48 -> V_51 [ V_223 ] -> V_53 )
continue;
if ( V_48 -> V_51 [ V_223 ] -> V_226 == ( V_222 -> V_227 << V_61 ) )
break;
}
for ( V_57 = 0 , V_224 = V_223 ; V_224 < V_50 ; V_224 ++ ) {
if ( NULL == V_48 -> V_51 [ V_224 ] )
continue;
if ( V_52 != V_48 -> V_51 [ V_224 ] -> V_53 )
continue;
V_57 += V_48 -> V_51 [ V_224 ] -> V_58 ;
if ( V_57 == ( V_222 -> V_228 - V_222 -> V_229 ) )
break;
}
V_57 = 0 ;
for ( V_43 = V_223 ; V_43 <= V_224 && V_43 < V_50 ; V_43 ++ ) {
struct V_39 * V_40 = F_23 ( V_48 -> V_51 [ V_43 ] ) ;
for ( V_225 = 0 ; V_225 < V_40 -> V_45 ; V_225 ++ ) {
V_60 = F_135 (
V_222 , V_222 -> V_229 + V_57 ,
F_136 ( F_25 ( & V_40 -> V_44 [ V_225 ] ) ) ,
F_24 ( & V_40 -> V_44 [ V_225 ] ) , V_222 -> V_230 ) ;
if ( V_60 )
goto V_64;
V_57 += F_24 ( & V_40 -> V_44 [ V_225 ] ) ;
}
}
V_64:
F_32 ( & V_48 -> V_49 ) ;
return V_60 ;
}
static int F_137 ( struct V_175 * V_175 , struct V_221 * V_222 )
{
struct V_70 * V_71 = V_175 -> V_77 ;
int V_5 ;
V_5 = F_138 ( & V_71 -> V_48 , V_222 ) ;
if ( V_5 )
return V_5 ;
V_222 -> V_230 = F_139 ( V_222 -> V_230 ) ;
V_5 = F_134 ( V_175 , V_222 ) ;
if ( V_5 )
F_29 ( V_222 -> V_231 ) ;
return V_5 ;
}
static int F_140 ( struct V_175 * V_175 )
{
struct V_1 * V_2 = V_232 . V_233 ;
struct V_70 * V_71 ;
struct V_190 V_234 ;
if ( ! V_2 || ! V_2 -> V_182 )
return - V_235 ;
V_71 = F_141 ( sizeof( * V_71 ) , V_62 ) ;
if ( V_71 == NULL )
return - V_63 ;
F_31 ( & V_2 -> V_191 ) ;
if ( V_2 -> V_136 == NULL || ! F_142 ( V_2 -> V_136 -> V_236 ) ) {
F_32 ( & V_2 -> V_191 ) ;
goto V_237;
}
if ( F_66 ( & V_2 -> V_238 ) == 1 ) {
F_62 ( V_2 ) ;
if ( F_86 ( V_2 ) ) {
F_32 ( & V_2 -> V_191 ) ;
goto V_239;
}
}
F_32 ( & V_2 -> V_191 ) ;
V_71 -> V_2 = V_2 ;
F_31 ( & V_2 -> V_191 ) ;
F_95 ( V_2 -> V_136 , & V_234 ) ;
F_32 ( & V_2 -> V_191 ) ;
V_71 -> V_97 = V_234 . V_193 . V_97 ;
V_175 -> V_77 = V_71 ;
F_143 ( & V_71 -> V_240 ) ;
F_144 ( & V_71 -> V_48 , & V_241 , NULL ,
& V_71 -> V_240 , V_213 ,
V_242 ,
sizeof( struct V_37 ) , V_71 , NULL ) ;
return 0 ;
V_239:
F_60 ( V_2 ) ;
F_145 ( V_2 -> V_136 -> V_236 ) ;
V_237:
F_29 ( V_71 ) ;
return - V_235 ;
}
static int F_146 ( struct V_175 * V_175 )
{
struct V_70 * V_71 = V_175 -> V_77 ;
struct V_1 * V_2 = V_71 -> V_2 ;
F_114 ( & V_2 -> V_174 ) ;
F_115 ( & V_2 -> V_173 ) ;
F_116 ( & V_71 -> V_48 ) ;
F_31 ( & V_2 -> V_191 ) ;
if ( V_2 -> V_76 == V_175 ) {
V_2 -> V_76 = NULL ;
F_32 ( & V_2 -> V_191 ) ;
F_112 ( & V_2 -> V_6 -> V_203 , NULL , L_24 ) ;
} else {
F_32 ( & V_2 -> V_191 ) ;
}
F_71 ( & V_2 -> V_174 ) ;
F_30 ( & V_71 -> V_48 ) ;
F_115 ( & V_2 -> V_173 ) ;
F_31 ( & V_2 -> V_191 ) ;
if ( F_147 ( & V_2 -> V_238 ) == 0 ) {
F_85 ( V_2 ) ;
F_60 ( V_2 ) ;
}
F_32 ( & V_2 -> V_191 ) ;
V_175 -> V_77 = NULL ;
F_145 ( V_2 -> V_136 -> V_236 ) ;
F_29 ( V_71 ) ;
return 0 ;
}
static int F_148 ( struct V_243 * V_244 , T_5 V_89 )
{
struct V_1 * V_2 = F_149 ( V_244 ) ;
if ( F_19 ( & V_2 -> V_238 ) == 0 )
return 0 ;
if ( ! F_19 ( & V_2 -> V_174 ) )
F_65 ( V_2 ) ;
F_85 ( V_2 ) ;
F_60 ( V_2 ) ;
return 0 ;
}
static int F_150 ( struct V_243 * V_244 )
{
struct V_1 * V_2 = F_149 ( V_244 ) ;
if ( F_19 ( & V_2 -> V_238 ) == 0 )
return 0 ;
F_62 ( V_2 ) ;
F_86 ( V_2 ) ;
if ( ! F_19 ( & V_2 -> V_174 ) )
F_68 ( V_2 ) ;
return 0 ;
}
static int F_151 ( struct V_169 * V_245 )
{
struct V_1 * V_2 = V_245 -> V_140 . V_246 -> V_247 -> V_233 ;
struct V_248 * V_182 ;
int V_5 ;
if ( V_2 -> V_136 )
return - V_192 ;
V_2 -> V_136 = V_245 ;
if ( F_152 ( V_2 -> V_6 , & V_249 ) != 0 ) {
F_6 ( V_2 -> V_6 , L_26 ) ;
V_5 = - V_192 ;
goto V_60;
}
V_182 = V_2 -> V_182 = F_153 () ;
if ( ! V_182 ) {
F_6 ( V_2 -> V_6 , L_27 ) ;
V_5 = - V_63 ;
goto V_60;
}
V_182 -> V_250 = V_251 ;
V_182 -> V_252 = V_2 -> V_6 ;
F_91 ( V_182 -> V_170 , V_180 , sizeof( V_182 -> V_170 ) ) ;
V_182 -> V_253 = & V_254 ;
V_182 -> V_255 = & V_256 ;
F_62 ( V_2 ) ;
V_5 = F_79 ( V_2 ) ;
if ( V_5 )
goto V_60;
if ( F_154 ( V_182 , V_257 , V_258 ) < 0 ) {
F_6 ( V_2 -> V_6 , L_28 ) ;
V_5 = - V_192 ;
goto V_60;
}
F_60 ( V_2 ) ;
F_82 ( V_2 -> V_6 , L_29 ,
F_155 ( V_182 ) ) ;
return 0 ;
V_60:
F_156 ( V_245 ) ;
return V_5 ;
}
static void F_156 ( struct V_169 * V_245 )
{
struct V_1 * V_2 = V_245 -> V_140 . V_246 -> V_247 -> V_233 ;
F_83 ( V_2 ) ;
if ( V_2 -> V_182 ) {
if ( ! F_157 ( V_2 -> V_182 ) ) {
V_251 ( V_2 -> V_182 ) ;
} else {
F_158 ( V_2 -> V_182 ) ;
}
V_2 -> V_182 = NULL ;
}
F_159 ( V_2 -> V_6 , & V_249 ) ;
V_2 -> V_136 = NULL ;
}
static int T_6 F_160 ( struct V_243 * V_244 )
{
struct V_1 * V_2 ;
struct V_259 * V_260 ;
int V_125 ;
V_2 = F_141 ( sizeof( * V_2 ) , V_62 ) ;
if ( ! V_2 ) {
F_6 ( & V_244 -> V_6 , L_30 ) ;
goto V_60;
}
F_161 ( V_244 , V_2 ) ;
V_2 -> V_6 = & V_244 -> V_6 ;
if ( V_99 < 320 * 240 * 2 * 2 )
V_99 = 320 * 240 * 2 * 2 ;
V_2 -> V_99 = V_99 ;
V_260 = F_162 ( V_244 , V_261 , 0 ) ;
if ( ! V_260 ) {
F_6 ( V_2 -> V_6 , L_31 ) ;
goto V_60;
}
if ( ! F_163 ( V_260 -> V_262 , ( V_260 -> V_263 - V_260 -> V_262 ) + 1 ,
V_244 -> V_170 ) ) {
F_6 ( V_2 -> V_6 ,
L_32 ) ;
goto V_60;
}
V_2 -> V_264 = V_260 -> V_262 ;
V_2 -> V_265 = ( V_260 -> V_263 - V_260 -> V_262 ) + 1 ;
V_2 -> V_10 = ( unsigned long )
F_164 ( V_2 -> V_264 , V_2 -> V_265 ) ;
if ( ! V_2 -> V_10 ) {
F_6 ( V_2 -> V_6 , L_33 ) ;
goto V_60;
}
V_125 = F_165 ( V_244 , 0 ) ;
if ( V_125 <= 0 ) {
F_6 ( V_2 -> V_6 , L_34 ) ;
goto V_60;
}
if ( F_166 ( V_125 , F_74 , 0 , V_180 , V_2 ) ) {
F_6 ( V_2 -> V_6 ,
L_35 ) ;
goto V_60;
}
V_2 -> V_125 = V_125 ;
if ( F_4 ( V_2 ) )
goto V_60;
F_167 ( & V_2 -> V_173 , F_88 ) ;
F_168 ( & V_2 -> V_191 ) ;
F_143 ( & V_2 -> V_85 ) ;
F_169 ( & V_2 -> V_73 ,
V_2 -> V_10 + V_266 ,
F_64 ,
( unsigned long ) V_2 ) ;
V_232 . V_233 = V_2 ;
if ( F_170 ( & V_232 ) )
goto V_60;
return 0 ;
V_60:
F_171 ( V_244 ) ;
return - V_235 ;
}
static int F_171 ( struct V_243 * V_244 )
{
struct V_1 * V_2 = F_149 ( V_244 ) ;
if ( ! V_2 )
return 0 ;
if ( V_232 . V_233 != NULL )
F_172 ( & V_232 ) ;
V_232 . V_233 = NULL ;
F_1 ( V_2 ) ;
if ( V_2 -> V_125 ) {
F_173 ( V_2 -> V_125 , V_2 ) ;
V_2 -> V_125 = 0 ;
}
if ( V_2 -> V_10 ) {
F_174 ( ( void * ) V_2 -> V_10 ) ;
V_2 -> V_10 = 0 ;
}
if ( V_2 -> V_264 ) {
F_175 ( V_2 -> V_264 , V_2 -> V_265 ) ;
V_2 -> V_264 = 0 ;
}
F_29 ( V_2 ) ;
return 0 ;
}
static int T_7 F_176 ( void )
{
return F_177 ( & V_267 ) ;
}
static void T_8 F_178 ( void )
{
F_179 ( & V_267 ) ;
}
