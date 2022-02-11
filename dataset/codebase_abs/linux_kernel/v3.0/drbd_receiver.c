static struct V_1 * F_1 ( struct V_1 * * V_2 , int V_3 )
{
struct V_1 * V_1 ;
struct V_1 * V_4 ;
F_2 ( ! V_3 ) ;
F_2 ( ! V_2 ) ;
V_1 = * V_2 ;
if ( ! V_1 )
return NULL ;
while ( V_1 ) {
V_4 = F_3 ( V_1 ) ;
if ( -- V_3 == 0 )
break;
if ( V_4 == NULL )
return NULL ;
V_1 = V_4 ;
}
F_4 ( V_1 , 0 ) ;
V_1 = * V_2 ;
* V_2 = V_4 ;
return V_1 ;
}
static struct V_1 * F_5 ( struct V_1 * V_1 , int * V_5 )
{
struct V_1 * V_4 ;
int V_6 = 1 ;
while ( ( V_4 = F_3 ( V_1 ) ) )
++ V_6 , V_1 = V_4 ;
if ( V_5 )
* V_5 = V_6 ;
return V_1 ;
}
static int F_6 ( struct V_1 * V_1 )
{
struct V_1 * V_4 ;
int V_6 = 0 ;
F_7 (page, tmp) {
F_8 ( V_1 ) ;
++ V_6 ;
}
return V_6 ;
}
static void F_9 ( struct V_1 * * V_2 ,
struct V_1 * V_7 , struct V_1 * V_8 )
{
#if 1
struct V_1 * V_4 ;
V_4 = F_5 ( V_7 , NULL ) ;
F_2 ( V_4 != V_8 ) ;
#endif
F_4 ( V_8 , ( unsigned long ) * V_2 ) ;
* V_2 = V_7 ;
}
static struct V_1 * F_10 ( struct V_9 * V_10 , int V_11 )
{
struct V_1 * V_1 = NULL ;
struct V_1 * V_4 = NULL ;
int V_6 = 0 ;
if ( V_12 >= V_11 ) {
F_11 ( & V_13 ) ;
V_1 = F_1 ( & V_14 , V_11 ) ;
if ( V_1 )
V_12 -= V_11 ;
F_12 ( & V_13 ) ;
if ( V_1 )
return V_1 ;
}
for ( V_6 = 0 ; V_6 < V_11 ; V_6 ++ ) {
V_4 = F_13 ( V_15 ) ;
if ( ! V_4 )
break;
F_4 ( V_4 , ( unsigned long ) V_1 ) ;
V_1 = V_4 ;
}
if ( V_6 == V_11 )
return V_1 ;
if ( V_1 ) {
V_4 = F_5 ( V_1 , NULL ) ;
F_11 ( & V_13 ) ;
F_9 ( & V_14 , V_1 , V_4 ) ;
V_12 += V_6 ;
F_12 ( & V_13 ) ;
}
return NULL ;
}
static void F_14 ( struct V_9 * V_10 , struct V_16 * V_17 )
{
struct V_18 * V_19 ;
struct V_16 * V_20 , * V_21 ;
F_15 (le, tle, &mdev->net_ee) {
V_19 = F_16 ( V_20 , struct V_18 , V_22 . V_23 ) ;
if ( F_17 ( V_19 ) )
break;
F_18 ( V_20 , V_17 ) ;
}
}
static void F_19 ( struct V_9 * V_10 )
{
F_20 ( V_24 ) ;
struct V_18 * V_19 , * V_25 ;
F_21 ( & V_10 -> V_26 ) ;
F_14 ( V_10 , & V_24 ) ;
F_22 ( & V_10 -> V_26 ) ;
F_23 (e, t, &reclaimed, w.list)
F_24 ( V_10 , V_19 ) ;
}
static struct V_1 * F_25 ( struct V_9 * V_10 , unsigned V_11 , bool V_27 )
{
struct V_1 * V_1 = NULL ;
F_26 ( V_28 ) ;
if ( F_27 ( & V_10 -> V_29 ) < V_10 -> V_30 -> V_31 )
V_1 = F_10 ( V_10 , V_11 ) ;
while ( V_1 == NULL ) {
F_28 ( & V_32 , & V_28 , V_33 ) ;
F_19 ( V_10 ) ;
if ( F_27 ( & V_10 -> V_29 ) < V_10 -> V_30 -> V_31 ) {
V_1 = F_10 ( V_10 , V_11 ) ;
if ( V_1 )
break;
}
if ( ! V_27 )
break;
if ( F_29 ( V_34 ) ) {
F_30 ( V_35 , L_1 ) ;
break;
}
F_31 () ;
}
F_32 ( & V_32 , & V_28 ) ;
if ( V_1 )
F_33 ( V_11 , & V_10 -> V_29 ) ;
return V_1 ;
}
static void F_34 ( struct V_9 * V_10 , struct V_1 * V_1 , int V_36 )
{
T_1 * V_37 = V_36 ? & V_10 -> V_38 : & V_10 -> V_29 ;
int V_6 ;
if ( V_12 > ( V_39 / V_40 ) * V_41 )
V_6 = F_6 ( V_1 ) ;
else {
struct V_1 * V_4 ;
V_4 = F_5 ( V_1 , & V_6 ) ;
F_11 ( & V_13 ) ;
F_9 ( & V_14 , V_1 , V_4 ) ;
V_12 += V_6 ;
F_12 ( & V_13 ) ;
}
V_6 = F_35 ( V_6 , V_37 ) ;
if ( V_6 < 0 )
F_30 ( V_35 , L_2 ,
V_36 ? L_3 : L_4 , V_6 ) ;
F_36 ( & V_32 ) ;
}
struct V_18 * F_37 ( struct V_9 * V_10 ,
T_2 V_42 ,
T_3 V_43 ,
unsigned int V_44 ,
T_4 V_45 ) __must_hold( T_5 )
{
struct V_18 * V_19 ;
struct V_1 * V_1 ;
unsigned V_46 = ( V_44 + V_40 - 1 ) >> V_47 ;
if ( F_38 ( V_10 , V_48 ) )
return NULL ;
V_19 = F_39 ( V_49 , V_45 & ~ V_50 ) ;
if ( ! V_19 ) {
if ( ! ( V_45 & V_51 ) )
F_40 ( V_35 , L_5 ) ;
return NULL ;
}
V_1 = F_25 ( V_10 , V_46 , ( V_45 & V_52 ) ) ;
if ( ! V_1 )
goto V_53;
F_41 ( & V_19 -> V_54 ) ;
V_19 -> V_55 = NULL ;
V_19 -> V_10 = V_10 ;
V_19 -> V_56 = V_1 ;
F_42 ( & V_19 -> V_57 , 0 ) ;
V_19 -> V_58 = V_44 ;
V_19 -> V_59 = 0 ;
V_19 -> V_43 = V_43 ;
V_19 -> V_60 = V_42 ;
return V_19 ;
V_53:
F_43 ( V_19 , V_49 ) ;
return NULL ;
}
void F_44 ( struct V_9 * V_10 , struct V_18 * V_19 , int V_36 )
{
if ( V_19 -> V_59 & V_61 )
F_45 ( V_19 -> V_62 ) ;
F_34 ( V_10 , V_19 -> V_56 , V_36 ) ;
F_46 ( F_27 ( & V_19 -> V_57 ) == 0 ) ;
F_46 ( F_47 ( & V_19 -> V_54 ) ) ;
F_43 ( V_19 , V_49 ) ;
}
int F_48 ( struct V_9 * V_10 , struct V_16 * V_23 )
{
F_20 ( V_63 ) ;
struct V_18 * V_19 , * V_25 ;
int V_64 = 0 ;
int V_36 = V_23 == & V_10 -> V_65 ;
F_21 ( & V_10 -> V_26 ) ;
F_49 ( V_23 , & V_63 ) ;
F_22 ( & V_10 -> V_26 ) ;
F_23 (e, t, &work_list, w.list) {
F_44 ( V_10 , V_19 , V_36 ) ;
V_64 ++ ;
}
return V_64 ;
}
static int F_50 ( struct V_9 * V_10 )
{
F_20 ( V_63 ) ;
F_20 ( V_24 ) ;
struct V_18 * V_19 , * V_25 ;
int V_66 = ( V_10 -> V_67 . V_68 >= V_69 ) ;
F_21 ( & V_10 -> V_26 ) ;
F_14 ( V_10 , & V_24 ) ;
F_49 ( & V_10 -> V_70 , & V_63 ) ;
F_22 ( & V_10 -> V_26 ) ;
F_23 (e, t, &reclaimed, w.list)
F_24 ( V_10 , V_19 ) ;
F_23 (e, t, &work_list, w.list) {
V_66 = V_19 -> V_22 . V_71 ( V_10 , & V_19 -> V_22 , ! V_66 ) && V_66 ;
F_51 ( V_10 , V_19 ) ;
}
F_36 ( & V_10 -> V_72 ) ;
return V_66 ;
}
void F_52 ( struct V_9 * V_10 , struct V_16 * V_2 )
{
F_26 ( V_28 ) ;
while ( ! F_53 ( V_2 ) ) {
F_28 ( & V_10 -> V_72 , & V_28 , V_73 ) ;
F_22 ( & V_10 -> V_26 ) ;
F_54 () ;
F_32 ( & V_10 -> V_72 , & V_28 ) ;
F_21 ( & V_10 -> V_26 ) ;
}
}
void F_55 ( struct V_9 * V_10 , struct V_16 * V_2 )
{
F_21 ( & V_10 -> V_26 ) ;
F_52 ( V_10 , V_2 ) ;
F_22 ( & V_10 -> V_26 ) ;
}
static int F_56 ( struct V_9 * V_10 , const char * * V_74 ,
struct V_75 * V_76 , struct V_75 * * V_77 )
{
struct V_76 * V_78 = V_76 -> V_78 ;
int V_79 = 0 ;
* V_74 = L_6 ;
V_79 = V_76 -> V_80 -> V_81 ( V_76 , 5 ) ;
if ( V_79 < 0 )
goto V_82;
* V_74 = L_7 ;
V_79 = F_57 ( V_78 -> V_83 , V_78 -> V_84 , V_78 -> V_85 ,
V_77 ) ;
if ( V_79 < 0 )
goto V_82;
* V_74 = L_8 ;
V_79 = V_76 -> V_80 -> V_86 ( V_76 , * V_77 , 0 ) ;
if ( V_79 < 0 ) {
F_58 ( * V_77 ) ;
* V_77 = NULL ;
goto V_82;
}
( * V_77 ) -> V_80 = V_76 -> V_80 ;
V_82:
return V_79 ;
}
static int F_59 ( struct V_9 * V_10 , struct V_75 * V_76 ,
void * V_87 , T_6 V_58 , int V_59 )
{
T_7 V_88 ;
struct V_89 V_90 = {
. V_91 = V_87 ,
. V_92 = V_58 ,
} ;
struct V_93 V_94 = {
. V_95 = 1 ,
. V_96 = (struct V_97 * ) & V_90 ,
. V_98 = ( V_59 ? V_59 : V_99 | V_100 )
} ;
int V_101 ;
V_88 = F_60 () ;
F_61 ( V_102 ) ;
V_101 = F_62 ( V_76 , & V_94 , V_58 , V_94 . V_98 ) ;
F_61 ( V_88 ) ;
return V_101 ;
}
static int F_63 ( struct V_9 * V_10 , void * V_87 , T_6 V_58 )
{
T_7 V_88 ;
struct V_89 V_90 = {
. V_91 = V_87 ,
. V_92 = V_58 ,
} ;
struct V_93 V_94 = {
. V_95 = 1 ,
. V_96 = (struct V_97 * ) & V_90 ,
. V_98 = V_99 | V_100
} ;
int V_101 ;
V_88 = F_60 () ;
F_61 ( V_102 ) ;
for (; ; ) {
V_101 = F_62 ( V_10 -> V_103 . V_75 , & V_94 , V_58 , V_94 . V_98 ) ;
if ( V_101 == V_58 )
break;
if ( V_101 < 0 ) {
if ( V_101 == - V_104 )
F_64 ( V_35 , L_9 ) ;
else if ( V_101 != - V_105 )
F_40 ( V_35 , L_10 , V_101 ) ;
break;
} else if ( V_101 == 0 ) {
F_64 ( V_35 , L_11 ) ;
break;
} else {
break;
}
} ;
F_61 ( V_88 ) ;
if ( V_101 != V_58 )
F_65 ( V_10 , F_66 ( V_68 , V_106 ) ) ;
return V_101 ;
}
static void F_67 ( struct V_75 * V_76 , unsigned int V_107 ,
unsigned int V_108 )
{
if ( V_107 ) {
V_76 -> V_78 -> V_109 = V_107 ;
V_76 -> V_78 -> V_110 |= V_111 ;
}
if ( V_108 ) {
V_76 -> V_78 -> V_112 = V_108 ;
V_76 -> V_78 -> V_110 |= V_113 ;
}
}
static struct V_75 * F_68 ( struct V_9 * V_10 )
{
const char * V_74 ;
struct V_75 * V_76 ;
struct V_114 V_115 ;
int V_79 ;
int V_116 = 1 ;
if ( ! F_69 ( V_10 ) )
return NULL ;
V_74 = L_12 ;
V_79 = F_70 ( ( (struct V_117 * ) V_10 -> V_30 -> V_118 ) -> V_119 ,
V_120 , V_121 , & V_76 ) ;
if ( V_79 < 0 ) {
V_76 = NULL ;
goto V_82;
}
V_76 -> V_78 -> V_122 =
V_76 -> V_78 -> V_123 = V_10 -> V_30 -> V_124 * V_125 ;
F_67 ( V_76 , V_10 -> V_30 -> V_126 ,
V_10 -> V_30 -> V_127 ) ;
memcpy ( & V_115 , V_10 -> V_30 -> V_118 ,
F_71 ( int , V_10 -> V_30 -> V_128 , sizeof( V_115 ) ) ) ;
if ( ( (struct V_117 * ) V_10 -> V_30 -> V_118 ) -> V_119 == V_129 )
V_115 . V_130 = 0 ;
else
( (struct V_131 * ) & V_115 ) -> V_132 = 0 ;
V_74 = L_13 ;
V_79 = V_76 -> V_80 -> V_133 ( V_76 ,
(struct V_117 * ) & V_115 ,
V_10 -> V_30 -> V_128 ) ;
if ( V_79 < 0 )
goto V_82;
V_116 = 0 ;
V_74 = L_14 ;
V_79 = V_76 -> V_80 -> V_134 ( V_76 ,
(struct V_117 * ) V_10 -> V_30 -> V_135 ,
V_10 -> V_30 -> V_136 , 0 ) ;
V_82:
if ( V_79 < 0 ) {
if ( V_76 ) {
F_58 ( V_76 ) ;
V_76 = NULL ;
}
switch ( - V_79 ) {
case V_137 : case V_138 : case V_139 :
case V_140 : case V_105 :
case V_141 : case V_142 :
case V_143 : case V_144 :
V_116 = 0 ;
break;
default:
F_40 ( V_35 , L_15 , V_74 , V_79 ) ;
}
if ( V_116 )
F_65 ( V_10 , F_66 ( V_68 , V_145 ) ) ;
}
F_72 ( V_10 ) ;
return V_76 ;
}
static struct V_75 * F_73 ( struct V_9 * V_10 )
{
int V_146 , V_79 ;
struct V_75 * V_147 = NULL , * V_148 ;
const char * V_74 ;
if ( ! F_69 ( V_10 ) )
return NULL ;
V_74 = L_12 ;
V_79 = F_70 ( ( (struct V_117 * ) V_10 -> V_30 -> V_118 ) -> V_119 ,
V_120 , V_121 , & V_148 ) ;
if ( V_79 ) {
V_148 = NULL ;
goto V_82;
}
V_146 = V_10 -> V_30 -> V_124 * V_125 ;
V_146 += ( F_74 () & 1 ) ? V_146 / 7 : - V_146 / 7 ;
V_148 -> V_78 -> V_149 = 1 ;
V_148 -> V_78 -> V_122 = V_146 ;
V_148 -> V_78 -> V_123 = V_146 ;
F_67 ( V_148 , V_10 -> V_30 -> V_126 ,
V_10 -> V_30 -> V_127 ) ;
V_74 = L_16 ;
V_79 = V_148 -> V_80 -> V_133 ( V_148 ,
(struct V_117 * ) V_10 -> V_30 -> V_118 ,
V_10 -> V_30 -> V_128 ) ;
if ( V_79 < 0 )
goto V_82;
V_79 = F_56 ( V_10 , & V_74 , V_148 , & V_147 ) ;
V_82:
if ( V_148 )
F_58 ( V_148 ) ;
if ( V_79 < 0 ) {
if ( V_79 != - V_138 && V_79 != - V_140 && V_79 != - V_105 ) {
F_40 ( V_35 , L_15 , V_74 , V_79 ) ;
F_65 ( V_10 , F_66 ( V_68 , V_145 ) ) ;
}
}
F_72 ( V_10 ) ;
return V_147 ;
}
static int F_75 ( struct V_9 * V_10 ,
struct V_75 * V_76 , enum V_150 V_151 )
{
struct V_152 * V_153 = & V_10 -> V_103 . V_154 . V_155 . V_156 ;
return F_76 ( V_10 , V_76 , V_151 , V_153 , sizeof( * V_153 ) , 0 ) ;
}
static enum V_150 F_77 ( struct V_9 * V_10 , struct V_75 * V_76 )
{
struct V_152 * V_153 = & V_10 -> V_103 . V_157 . V_155 . V_156 ;
int V_158 ;
V_158 = F_59 ( V_10 , V_76 , V_153 , sizeof( * V_153 ) , 0 ) ;
if ( V_158 == sizeof( * V_153 ) && V_153 -> V_159 == V_160 )
return F_78 ( V_153 -> V_161 ) ;
return 0xffff ;
}
static int F_79 ( struct V_9 * V_10 , struct V_75 * * V_76 )
{
int V_158 ;
char V_162 [ 4 ] ;
if ( ! * V_76 )
return false ;
V_158 = F_59 ( V_10 , * V_76 , V_162 , 4 , V_163 | V_164 ) ;
if ( V_158 > 0 || V_158 == - V_138 ) {
return true ;
} else {
F_58 ( * V_76 ) ;
* V_76 = NULL ;
return false ;
}
}
static int F_80 ( struct V_9 * V_10 )
{
struct V_75 * V_165 , * V_76 , * V_166 ;
int V_167 , V_153 , V_66 ;
F_46 ( ! V_10 -> V_103 . V_75 ) ;
if ( F_81 ( V_10 , F_66 ( V_68 , V_168 ) ) < V_169 )
return - 2 ;
F_82 ( V_170 , & V_10 -> V_59 ) ;
V_76 = NULL ;
V_166 = NULL ;
do {
for ( V_167 = 0 ; ; ) {
V_165 = F_68 ( V_10 ) ;
if ( V_165 || ++ V_167 >= 3 )
break;
F_83 ( V_125 / 10 ) ;
}
if ( V_165 ) {
if ( ! V_76 ) {
F_75 ( V_10 , V_165 , V_171 ) ;
V_76 = V_165 ;
V_165 = NULL ;
} else if ( ! V_166 ) {
F_75 ( V_10 , V_165 , V_172 ) ;
V_166 = V_165 ;
V_165 = NULL ;
} else {
F_40 ( V_35 , L_17 ) ;
goto V_173;
}
}
if ( V_76 && V_166 ) {
F_83 ( V_10 -> V_30 -> V_174 * V_125 / 10 ) ;
V_66 = F_79 ( V_10 , & V_76 ) ;
V_66 = F_79 ( V_10 , & V_166 ) && V_66 ;
if ( V_66 )
break;
}
V_27:
V_165 = F_73 ( V_10 ) ;
if ( V_165 ) {
V_167 = F_77 ( V_10 , V_165 ) ;
F_79 ( V_10 , & V_76 ) ;
F_79 ( V_10 , & V_166 ) ;
switch ( V_167 ) {
case V_171 :
if ( V_76 ) {
F_30 ( V_35 , L_18 ) ;
F_58 ( V_76 ) ;
}
V_76 = V_165 ;
break;
case V_172 :
if ( V_166 ) {
F_30 ( V_35 , L_19 ) ;
F_58 ( V_166 ) ;
}
V_166 = V_165 ;
F_84 ( V_170 , & V_10 -> V_59 ) ;
break;
default:
F_30 ( V_35 , L_20 ) ;
F_58 ( V_165 ) ;
if ( F_74 () & 1 )
goto V_27;
}
}
if ( V_10 -> V_67 . V_68 <= V_145 )
goto V_173;
if ( F_29 ( V_34 ) ) {
F_85 ( V_34 ) ;
F_86 () ;
if ( F_87 ( & V_10 -> V_175 ) == V_176 )
goto V_173;
}
if ( V_76 && V_166 ) {
V_66 = F_79 ( V_10 , & V_76 ) ;
V_66 = F_79 ( V_10 , & V_166 ) && V_66 ;
if ( V_66 )
break;
}
} while ( 1 );
V_166 -> V_78 -> V_149 = 1 ;
V_76 -> V_78 -> V_149 = 1 ;
V_76 -> V_78 -> V_177 = V_178 ;
V_166 -> V_78 -> V_177 = V_178 ;
V_76 -> V_78 -> V_179 = V_180 ;
V_166 -> V_78 -> V_179 = V_181 ;
V_76 -> V_78 -> V_123 =
V_76 -> V_78 -> V_122 = V_10 -> V_30 -> V_174 * 4 * V_125 / 10 ;
V_166 -> V_78 -> V_123 = V_10 -> V_30 -> V_182 * V_125 / 10 ;
V_166 -> V_78 -> V_122 = V_10 -> V_30 -> V_183 * V_125 ;
F_88 ( V_76 ) ;
F_88 ( V_166 ) ;
V_10 -> V_103 . V_75 = V_76 ;
V_10 -> V_184 . V_75 = V_166 ;
V_10 -> V_185 = V_186 ;
F_46 ( V_10 -> V_187 . V_188 == NULL ) ;
V_153 = F_89 ( V_10 ) ;
if ( V_153 <= 0 )
return V_153 ;
if ( V_10 -> V_189 ) {
switch ( F_90 ( V_10 ) ) {
case - 1 :
F_40 ( V_35 , L_21 ) ;
return - 1 ;
case 0 :
F_40 ( V_35 , L_22 ) ;
return 0 ;
}
}
if ( F_81 ( V_10 , F_66 ( V_68 , V_69 ) ) < V_169 )
return 0 ;
V_76 -> V_78 -> V_123 = V_10 -> V_30 -> V_182 * V_125 / 10 ;
V_76 -> V_78 -> V_122 = V_190 ;
F_42 ( & V_10 -> V_191 , 0 ) ;
V_10 -> V_192 = 0 ;
F_91 ( & V_10 -> V_187 ) ;
if ( F_92 ( V_10 ) == - 1 )
return - 1 ;
F_93 ( V_10 , & V_10 -> V_193 ) ;
F_94 ( V_10 , 0 , 0 ) ;
F_95 ( V_10 ) ;
F_96 ( V_10 ) ;
F_82 ( V_194 , & V_10 -> V_59 ) ;
F_82 ( V_195 , & V_10 -> V_59 ) ;
F_97 ( & V_10 -> V_196 , V_186 + V_125 ) ;
return 1 ;
V_173:
if ( V_76 )
F_58 ( V_76 ) ;
if ( V_166 )
F_58 ( V_166 ) ;
return - 1 ;
}
static int F_98 ( struct V_9 * V_10 , enum V_150 * V_151 , unsigned int * V_197 )
{
union V_198 * V_153 = & V_10 -> V_103 . V_157 . V_155 ;
int V_199 ;
V_199 = F_63 ( V_10 , V_153 , sizeof( * V_153 ) ) ;
if ( F_99 ( V_199 != sizeof( * V_153 ) ) ) {
if ( ! F_29 ( V_34 ) )
F_30 ( V_35 , L_23 , V_199 ) ;
return false ;
}
if ( F_100 ( V_153 -> V_156 . V_159 == V_160 ) ) {
* V_151 = F_78 ( V_153 -> V_156 . V_161 ) ;
* V_197 = F_78 ( V_153 -> V_156 . V_200 ) ;
} else if ( V_153 -> V_201 . V_159 == V_202 ) {
* V_151 = F_78 ( V_153 -> V_201 . V_161 ) ;
* V_197 = F_101 ( V_153 -> V_201 . V_200 ) ;
} else {
F_40 ( V_35 , L_24 ,
F_101 ( V_153 -> V_156 . V_159 ) ,
F_78 ( V_153 -> V_156 . V_161 ) ,
F_78 ( V_153 -> V_156 . V_200 ) ) ;
return false ;
}
V_10 -> V_185 = V_186 ;
return true ;
}
static void F_102 ( struct V_9 * V_10 )
{
int V_101 ;
if ( V_10 -> V_203 >= V_204 && F_103 ( V_10 ) ) {
V_101 = F_104 ( V_10 -> V_205 -> V_206 , V_207 ,
NULL ) ;
if ( V_101 ) {
F_40 ( V_35 , L_25 , V_101 ) ;
F_105 ( V_10 , V_208 ) ;
}
F_106 ( V_10 ) ;
}
}
static enum V_209 F_107 ( struct V_9 * V_10 ,
struct V_210 * V_55 ,
enum V_211 V_212 )
{
int V_213 ;
struct V_210 * V_214 ;
enum V_209 V_101 = V_215 ;
F_11 ( & V_10 -> V_216 ) ;
do {
V_214 = NULL ;
V_213 = F_27 ( & V_55 -> V_213 ) ;
switch ( V_212 & ~ V_217 ) {
case V_218 :
F_108 ( & V_55 -> V_219 ) ;
break;
case V_220 :
F_84 ( V_221 , & V_55 -> V_59 ) ;
break;
case V_222 :
break;
}
if ( V_213 != 0 &&
F_27 ( & V_55 -> V_219 ) == 0 &&
F_109 ( V_221 , & V_55 -> V_59 ) ) {
if ( ! ( V_212 & V_217 ) ) {
F_12 ( & V_10 -> V_216 ) ;
F_110 ( V_10 , V_55 -> V_223 , V_213 ) ;
F_11 ( & V_10 -> V_216 ) ;
}
F_111 ( V_10 ) ;
if ( V_10 -> V_224 != V_55 ) {
V_214 = F_16 ( V_55 -> V_23 . V_225 , struct V_210 , V_23 ) ;
F_112 ( & V_55 -> V_23 ) ;
V_212 = V_222 | ( V_212 & V_217 ) ;
V_10 -> V_226 -- ;
F_45 ( V_55 ) ;
if ( V_101 == V_215 )
V_101 = V_227 ;
} else {
V_55 -> V_59 = 0 ;
F_42 ( & V_55 -> V_213 , 0 ) ;
if ( V_101 == V_215 )
V_101 = V_228 ;
F_36 ( & V_10 -> V_72 ) ;
}
}
if ( ! V_214 )
break;
V_55 = V_214 ;
} while ( 1 );
F_12 ( & V_10 -> V_216 ) ;
return V_101 ;
}
void F_105 ( struct V_9 * V_10 , enum V_229 V_230 ) __must_hold( T_5 )
{
enum V_229 V_231 ;
static char * V_232 [] = {
[ V_233 ] = L_26 ,
[ V_208 ] = L_27 ,
[ V_204 ] = L_28 ,
} ;
V_231 = V_10 -> V_203 ;
V_230 = F_113 ( V_231 , V_230 ) ;
if ( V_230 == V_204 && V_10 -> V_205 -> V_234 . V_235 )
V_230 = V_208 ;
if ( V_230 == V_208 && V_10 -> V_205 -> V_234 . V_236 )
V_230 = V_233 ;
V_10 -> V_203 = V_230 ;
if ( V_231 != V_10 -> V_203 || V_230 == V_204 )
F_64 ( V_35 , L_29 , V_232 [ V_10 -> V_203 ] ) ;
}
int F_114 ( struct V_9 * V_10 , struct V_18 * V_19 ,
const unsigned V_237 , const int V_238 )
{
struct V_239 * V_240 = NULL ;
struct V_239 * V_239 ;
struct V_1 * V_1 = V_19 -> V_56 ;
T_3 V_43 = V_19 -> V_43 ;
unsigned V_241 = V_19 -> V_58 ;
unsigned V_242 = 0 ;
unsigned V_46 = ( V_241 + V_40 - 1 ) >> V_47 ;
int V_79 = - V_243 ;
V_244:
V_239 = F_115 ( V_178 , V_46 ) ;
if ( ! V_239 ) {
F_40 ( V_35 , L_30 ) ;
goto V_53;
}
V_239 -> V_245 = V_43 ;
V_239 -> V_246 = V_10 -> V_205 -> V_206 ;
V_239 -> V_247 = V_237 ;
V_239 -> V_248 = V_19 ;
V_239 -> V_249 = V_250 ;
V_239 -> V_251 = V_240 ;
V_240 = V_239 ;
++ V_242 ;
F_116 (page) {
unsigned V_5 = F_71 ( unsigned , V_241 , V_40 ) ;
if ( ! F_117 ( V_239 , V_1 , V_5 , 0 ) ) {
if ( V_239 -> V_252 == 0 ) {
F_40 ( V_35 ,
L_31
L_32 ,
V_5 , ( unsigned long long ) V_239 -> V_245 ) ;
V_79 = - V_253 ;
goto V_53;
}
goto V_244;
}
V_241 -= V_5 ;
V_43 += V_5 >> 9 ;
-- V_46 ;
}
F_46 ( V_1 == NULL ) ;
F_46 ( V_241 == 0 ) ;
F_42 ( & V_19 -> V_57 , V_242 ) ;
do {
V_239 = V_240 ;
V_240 = V_240 -> V_251 ;
V_239 -> V_251 = NULL ;
F_118 ( V_10 , V_238 , V_239 ) ;
} while ( V_240 );
return 0 ;
V_53:
while ( V_240 ) {
V_239 = V_240 ;
V_240 = V_240 -> V_251 ;
F_119 ( V_239 ) ;
}
return V_79 ;
}
static int F_120 ( struct V_9 * V_10 , enum V_150 V_151 , unsigned int V_44 )
{
int V_101 ;
struct V_254 * V_255 = & V_10 -> V_103 . V_157 . V_256 ;
struct V_210 * V_55 ;
F_121 ( V_10 ) ;
V_10 -> V_224 -> V_223 = V_255 -> V_256 ;
V_101 = F_107 ( V_10 , V_10 -> V_224 , V_220 ) ;
switch ( V_10 -> V_203 ) {
case V_233 :
if ( V_101 == V_228 )
return true ;
V_55 = F_122 ( sizeof( struct V_210 ) , V_178 ) ;
if ( V_55 )
break;
else
F_30 ( V_35 , L_33 ) ;
case V_204 :
case V_208 :
F_55 ( V_10 , & V_10 -> V_257 ) ;
F_102 ( V_10 ) ;
if ( F_27 ( & V_10 -> V_224 -> V_213 ) ) {
V_55 = F_122 ( sizeof( struct V_210 ) , V_178 ) ;
if ( V_55 )
break;
}
V_55 = V_10 -> V_224 ;
F_123 ( V_10 -> V_72 , F_27 ( & V_55 -> V_213 ) == 0 ) ;
F_46 ( F_27 ( & V_55 -> V_219 ) == 0 ) ;
F_46 ( V_55 -> V_59 == 0 ) ;
return true ;
default:
F_40 ( V_35 , L_34 , V_10 -> V_203 ) ;
return false ;
}
V_55 -> V_59 = 0 ;
F_42 ( & V_55 -> V_213 , 0 ) ;
F_42 ( & V_55 -> V_219 , 0 ) ;
F_11 ( & V_10 -> V_216 ) ;
if ( F_27 ( & V_10 -> V_224 -> V_213 ) ) {
F_124 ( & V_55 -> V_23 , & V_10 -> V_224 -> V_23 ) ;
V_10 -> V_224 = V_55 ;
V_10 -> V_226 ++ ;
} else {
F_45 ( V_55 ) ;
}
F_12 ( & V_10 -> V_216 ) ;
return true ;
}
static struct V_18 *
F_125 ( struct V_9 * V_10 , T_2 V_42 , T_3 V_43 , int V_44 ) __must_hold( T_5 )
{
const T_3 V_258 = F_126 ( V_10 -> V_259 ) ;
struct V_18 * V_19 ;
struct V_1 * V_1 ;
int V_260 , V_241 , V_158 ;
void * V_261 = V_10 -> V_262 ;
void * V_263 = V_10 -> V_264 ;
unsigned long * V_103 ;
V_260 = ( V_10 -> V_265 >= 87 && V_10 -> V_266 ) ?
F_127 ( V_10 -> V_266 ) : 0 ;
if ( V_260 ) {
V_158 = F_63 ( V_10 , V_261 , V_260 ) ;
if ( V_158 != V_260 ) {
if ( ! F_29 ( V_34 ) )
F_30 ( V_35 ,
L_35 ,
V_158 , V_260 ) ;
return NULL ;
}
}
V_44 -= V_260 ;
F_128 (data_size == 0 ) return NULL ;
F_128 (data_size & 0x1ff ) return NULL ;
F_128 (data_size > DRBD_MAX_BIO_SIZE) return NULL ;
if ( V_43 + ( V_44 >> 9 ) > V_258 ) {
F_40 ( V_35 , L_36
L_37 ,
( unsigned long long ) V_258 ,
( unsigned long long ) V_43 , V_44 ) ;
return NULL ;
}
V_19 = F_37 ( V_10 , V_42 , V_43 , V_44 , V_178 ) ;
if ( ! V_19 )
return NULL ;
V_241 = V_44 ;
V_1 = V_19 -> V_56 ;
F_116 (page) {
unsigned V_5 = F_71 ( int , V_241 , V_40 ) ;
V_103 = F_129 ( V_1 ) ;
V_158 = F_63 ( V_10 , V_103 , V_5 ) ;
if ( F_38 ( V_10 , V_267 ) ) {
F_40 ( V_35 , L_38 ) ;
V_103 [ 0 ] = V_103 [ 0 ] ^ ( unsigned long ) - 1 ;
}
F_130 ( V_1 ) ;
if ( V_158 != V_5 ) {
F_51 ( V_10 , V_19 ) ;
if ( ! F_29 ( V_34 ) )
F_30 ( V_35 , L_39 ,
V_158 , V_5 ) ;
return NULL ;
}
V_241 -= V_158 ;
}
if ( V_260 ) {
F_131 ( V_10 , V_10 -> V_266 , V_19 , V_263 ) ;
if ( memcmp ( V_261 , V_263 , V_260 ) ) {
F_40 ( V_35 , L_40 ,
( unsigned long long ) V_43 , V_44 ) ;
F_132 ( V_10 , L_41 ,
V_260 , V_261 , V_263 , V_19 ) ;
F_51 ( V_10 , V_19 ) ;
return NULL ;
}
}
V_10 -> V_268 += V_44 >> 9 ;
return V_19 ;
}
static int F_133 ( struct V_9 * V_10 , int V_44 )
{
struct V_1 * V_1 ;
int V_158 , V_101 = 1 ;
void * V_103 ;
if ( ! V_44 )
return true ;
V_1 = F_25 ( V_10 , 1 , 1 ) ;
V_103 = F_129 ( V_1 ) ;
while ( V_44 ) {
V_158 = F_63 ( V_10 , V_103 , F_71 ( int , V_44 , V_40 ) ) ;
if ( V_158 != F_71 ( int , V_44 , V_40 ) ) {
V_101 = 0 ;
if ( ! F_29 ( V_34 ) )
F_30 ( V_35 ,
L_39 ,
V_158 , F_71 ( int , V_44 , V_40 ) ) ;
break;
}
V_44 -= V_158 ;
}
F_130 ( V_1 ) ;
F_34 ( V_10 , V_1 , 0 ) ;
return V_101 ;
}
static int F_134 ( struct V_9 * V_10 , struct V_269 * V_270 ,
T_3 V_43 , int V_44 )
{
struct V_271 * V_272 ;
struct V_239 * V_239 ;
int V_260 , V_158 , V_6 , V_273 ;
void * V_261 = V_10 -> V_262 ;
void * V_263 = V_10 -> V_264 ;
V_260 = ( V_10 -> V_265 >= 87 && V_10 -> V_266 ) ?
F_127 ( V_10 -> V_266 ) : 0 ;
if ( V_260 ) {
V_158 = F_63 ( V_10 , V_261 , V_260 ) ;
if ( V_158 != V_260 ) {
if ( ! F_29 ( V_34 ) )
F_30 ( V_35 ,
L_42 ,
V_158 , V_260 ) ;
return 0 ;
}
}
V_44 -= V_260 ;
V_10 -> V_268 += V_44 >> 9 ;
V_239 = V_270 -> V_274 ;
F_46 ( V_43 == V_239 -> V_245 ) ;
F_135 (bvec, bio, i) {
V_273 = F_71 ( int , V_44 , V_272 -> V_275 ) ;
V_158 = F_63 ( V_10 ,
F_129 ( V_272 -> V_276 ) + V_272 -> V_277 ,
V_273 ) ;
F_130 ( V_272 -> V_276 ) ;
if ( V_158 != V_273 ) {
if ( ! F_29 ( V_34 ) )
F_30 ( V_35 , L_43
L_44 ,
V_158 , V_273 ) ;
return 0 ;
}
V_44 -= V_158 ;
}
if ( V_260 ) {
F_136 ( V_10 , V_10 -> V_266 , V_239 , V_263 ) ;
if ( memcmp ( V_261 , V_263 , V_260 ) ) {
F_40 ( V_35 , L_45 ) ;
return 0 ;
}
}
F_46 ( V_44 == 0 ) ;
return 1 ;
}
static int F_137 ( struct V_9 * V_10 , struct V_278 * V_22 , int V_279 )
{
struct V_18 * V_19 = (struct V_18 * ) V_22 ;
T_3 V_43 = V_19 -> V_43 ;
int V_66 ;
F_46 ( F_47 ( & V_19 -> V_54 ) ) ;
if ( F_100 ( ( V_19 -> V_59 & V_280 ) == 0 ) ) {
F_138 ( V_10 , V_43 , V_19 -> V_58 ) ;
V_66 = F_139 ( V_10 , V_281 , V_19 ) ;
} else {
F_140 ( V_10 , V_43 , V_19 -> V_58 ) ;
V_66 = F_139 ( V_10 , V_282 , V_19 ) ;
}
F_111 ( V_10 ) ;
return V_66 ;
}
static int F_141 ( struct V_9 * V_10 , T_3 V_43 , int V_44 ) __releases( T_5 )
{
struct V_18 * V_19 ;
V_19 = F_125 ( V_10 , V_283 , V_43 , V_44 ) ;
if ( ! V_19 )
goto V_53;
F_142 ( V_10 ) ;
F_121 ( V_10 ) ;
V_19 -> V_22 . V_71 = F_137 ;
F_21 ( & V_10 -> V_26 ) ;
F_124 ( & V_19 -> V_22 . V_23 , & V_10 -> V_284 ) ;
F_22 ( & V_10 -> V_26 ) ;
F_33 ( V_44 >> 9 , & V_10 -> V_285 ) ;
if ( F_114 ( V_10 , V_19 , V_286 , V_287 ) == 0 )
return true ;
F_40 ( V_35 , L_46 ) ;
F_21 ( & V_10 -> V_26 ) ;
F_112 ( & V_19 -> V_22 . V_23 ) ;
F_22 ( & V_10 -> V_26 ) ;
F_51 ( V_10 , V_19 ) ;
V_53:
F_106 ( V_10 ) ;
return false ;
}
static int F_143 ( struct V_9 * V_10 , enum V_150 V_151 , unsigned int V_44 )
{
struct V_269 * V_270 ;
T_3 V_43 ;
int V_66 ;
struct V_288 * V_255 = & V_10 -> V_103 . V_157 . V_103 ;
V_43 = F_144 ( V_255 -> V_43 ) ;
F_21 ( & V_10 -> V_26 ) ;
V_270 = F_145 ( V_10 , V_255 -> V_60 , V_43 ) ;
F_22 ( & V_10 -> V_26 ) ;
if ( F_99 ( ! V_270 ) ) {
F_40 ( V_35 , L_47 ) ;
return false ;
}
V_66 = F_134 ( V_10 , V_270 , V_43 , V_44 ) ;
if ( V_66 )
F_146 ( V_270 , V_289 ) ;
return V_66 ;
}
static int F_147 ( struct V_9 * V_10 , enum V_150 V_151 , unsigned int V_44 )
{
T_3 V_43 ;
int V_66 ;
struct V_288 * V_255 = & V_10 -> V_103 . V_157 . V_103 ;
V_43 = F_144 ( V_255 -> V_43 ) ;
F_46 ( V_255 -> V_60 == V_283 ) ;
if ( F_103 ( V_10 ) ) {
V_66 = F_141 ( V_10 , V_43 , V_44 ) ;
} else {
if ( F_148 ( & V_290 ) )
F_40 ( V_35 , L_48 ) ;
V_66 = F_133 ( V_10 , V_44 ) ;
F_149 ( V_10 , V_282 , V_255 , V_44 ) ;
}
F_33 ( V_44 >> 9 , & V_10 -> V_291 ) ;
return V_66 ;
}
static int F_150 ( struct V_9 * V_10 , struct V_278 * V_22 , int V_292 )
{
struct V_18 * V_19 = (struct V_18 * ) V_22 ;
T_3 V_43 = V_19 -> V_43 ;
int V_66 = 1 , V_293 ;
if ( V_10 -> V_30 -> V_294 == V_295 ) {
if ( F_100 ( ( V_19 -> V_59 & V_280 ) == 0 ) ) {
V_293 = ( V_10 -> V_67 . V_68 >= V_296 &&
V_10 -> V_67 . V_68 <= V_297 &&
V_19 -> V_59 & V_298 ) ?
V_281 : V_299 ;
V_66 &= F_139 ( V_10 , V_293 , V_19 ) ;
if ( V_293 == V_281 )
F_138 ( V_10 , V_43 , V_19 -> V_58 ) ;
} else {
V_66 = F_139 ( V_10 , V_282 , V_19 ) ;
}
F_111 ( V_10 ) ;
}
if ( V_10 -> V_30 -> V_300 ) {
F_21 ( & V_10 -> V_26 ) ;
F_46 ( ! F_47 ( & V_19 -> V_54 ) ) ;
F_151 ( & V_19 -> V_54 ) ;
F_22 ( & V_10 -> V_26 ) ;
} else {
F_46 ( F_47 ( & V_19 -> V_54 ) ) ;
}
F_107 ( V_10 , V_19 -> V_55 , V_218 + ( V_292 ? V_217 : 0 ) ) ;
return V_66 ;
}
static int F_152 ( struct V_9 * V_10 , struct V_278 * V_22 , int V_279 )
{
struct V_18 * V_19 = (struct V_18 * ) V_22 ;
int V_66 = 1 ;
F_46 ( V_10 -> V_30 -> V_294 == V_295 ) ;
V_66 = F_139 ( V_10 , V_301 , V_19 ) ;
F_21 ( & V_10 -> V_26 ) ;
F_46 ( ! F_47 ( & V_19 -> V_54 ) ) ;
F_151 ( & V_19 -> V_54 ) ;
F_22 ( & V_10 -> V_26 ) ;
F_111 ( V_10 ) ;
return V_66 ;
}
static int F_153 ( struct V_9 * V_10 , const T_8 V_191 )
{
F_26 ( V_28 ) ;
unsigned int V_302 ;
long V_182 ;
int V_303 = 0 ;
F_11 ( & V_10 -> V_304 ) ;
for (; ; ) {
F_28 ( & V_10 -> V_305 , & V_28 , V_33 ) ;
if ( F_154 ( V_191 , V_10 -> V_192 + 1 ) )
break;
if ( F_29 ( V_34 ) ) {
V_303 = - V_105 ;
break;
}
V_302 = V_10 -> V_192 ;
F_12 ( & V_10 -> V_304 ) ;
V_182 = F_155 ( 30 * V_125 ) ;
F_11 ( & V_10 -> V_304 ) ;
if ( V_182 == 0 && V_302 == V_10 -> V_192 ) {
V_303 = - V_137 ;
F_40 ( V_35 , L_49 ) ;
break;
}
}
F_32 ( & V_10 -> V_305 , & V_28 ) ;
if ( V_10 -> V_192 + 1 == V_191 )
V_10 -> V_192 ++ ;
F_12 ( & V_10 -> V_304 ) ;
return V_303 ;
}
static unsigned long F_156 ( struct V_9 * V_10 , T_8 V_306 )
{
return ( V_306 & V_307 ? V_308 : 0 ) |
( V_306 & V_309 ? V_310 : 0 ) |
( V_306 & V_311 ? V_312 : 0 ) |
( V_306 & V_313 ? V_314 : 0 ) ;
}
static int F_157 ( struct V_9 * V_10 , enum V_150 V_151 , unsigned int V_44 )
{
T_3 V_43 ;
struct V_18 * V_19 ;
struct V_288 * V_255 = & V_10 -> V_103 . V_157 . V_103 ;
int V_237 = V_286 ;
T_8 V_315 ;
if ( ! F_103 ( V_10 ) ) {
F_11 ( & V_10 -> V_304 ) ;
if ( V_10 -> V_192 + 1 == F_101 ( V_255 -> V_316 ) )
V_10 -> V_192 ++ ;
F_12 ( & V_10 -> V_304 ) ;
F_149 ( V_10 , V_282 , V_255 , V_44 ) ;
F_158 ( & V_10 -> V_224 -> V_213 ) ;
return F_133 ( V_10 , V_44 ) ;
}
V_43 = F_144 ( V_255 -> V_43 ) ;
V_19 = F_125 ( V_10 , V_255 -> V_60 , V_43 , V_44 ) ;
if ( ! V_19 ) {
F_106 ( V_10 ) ;
return false ;
}
V_19 -> V_22 . V_71 = F_150 ;
V_315 = F_101 ( V_255 -> V_315 ) ;
V_237 |= F_156 ( V_10 , V_315 ) ;
if ( V_315 & V_317 )
V_19 -> V_59 |= V_298 ;
F_11 ( & V_10 -> V_216 ) ;
V_19 -> V_55 = V_10 -> V_224 ;
F_158 ( & V_19 -> V_55 -> V_213 ) ;
F_158 ( & V_19 -> V_55 -> V_219 ) ;
F_12 ( & V_10 -> V_216 ) ;
if ( ! V_10 -> V_30 -> V_300 ) {
F_21 ( & V_10 -> V_26 ) ;
} else {
const int V_58 = V_19 -> V_58 ;
const int V_318 = F_109 ( V_170 , & V_10 -> V_59 ) ;
F_26 ( V_28 ) ;
struct V_269 * V_6 ;
struct V_319 * V_3 ;
struct V_320 * V_321 ;
int V_322 ;
F_46 ( V_10 -> V_30 -> V_294 == V_295 ) ;
F_2 ( V_10 -> V_323 == NULL ) ;
F_2 ( V_10 -> V_324 == NULL ) ;
if ( F_153 ( V_10 , F_101 ( V_255 -> V_316 ) ) )
goto V_325;
F_21 ( & V_10 -> V_26 ) ;
F_159 ( & V_19 -> V_54 , F_160 ( V_10 , V_43 ) ) ;
#define F_161 overlaps(i->sector, i->size, sector, size)
V_321 = F_162 ( V_10 , V_43 ) ;
V_322 = 1 ;
for (; ; ) {
int V_326 = 0 ;
int V_327 = 0 ;
F_28 ( & V_10 -> V_328 , & V_28 ,
V_33 ) ;
F_163 (i, n, slot, collision) {
if ( F_161 ) {
if ( V_322 )
F_164 ( V_35 , L_50
L_51 ,
V_34 -> V_329 , V_34 -> V_330 ,
( unsigned long long ) V_43 , V_58 ,
( unsigned long long ) V_6 -> V_43 , V_6 -> V_58 ) ;
if ( V_6 -> V_331 & V_332 )
++ V_326 ;
++ V_327 ;
}
}
#undef F_161
if ( ! V_327 )
break;
if ( V_322 && V_318 && V_326 ) {
F_164 ( V_35 , L_52 ,
( unsigned long long ) V_43 ) ;
F_121 ( V_10 ) ;
V_19 -> V_22 . V_71 = F_152 ;
F_165 ( & V_19 -> V_22 . V_23 , & V_10 -> V_70 ) ;
F_22 ( & V_10 -> V_26 ) ;
F_106 ( V_10 ) ;
F_166 ( V_10 ) ;
F_32 ( & V_10 -> V_328 , & V_28 ) ;
return true ;
}
if ( F_29 ( V_34 ) ) {
F_151 ( & V_19 -> V_54 ) ;
F_22 ( & V_10 -> V_26 ) ;
F_32 ( & V_10 -> V_328 , & V_28 ) ;
goto V_325;
}
F_22 ( & V_10 -> V_26 ) ;
if ( V_322 ) {
V_322 = 0 ;
F_164 ( V_35 , L_53
L_54 , ( unsigned long long ) V_43 ) ;
} else if ( V_318 ) {
F_46 ( V_326 == 0 ) ;
}
F_31 () ;
F_21 ( & V_10 -> V_26 ) ;
}
F_32 ( & V_10 -> V_328 , & V_28 ) ;
}
F_124 ( & V_19 -> V_22 . V_23 , & V_10 -> V_257 ) ;
F_22 ( & V_10 -> V_26 ) ;
switch ( V_10 -> V_30 -> V_294 ) {
case V_295 :
F_121 ( V_10 ) ;
break;
case V_333 :
F_139 ( V_10 , V_334 , V_19 ) ;
break;
case V_335 :
break;
}
if ( V_10 -> V_67 . V_336 < V_337 ) {
F_167 ( V_10 , V_19 -> V_43 , V_19 -> V_58 ) ;
V_19 -> V_59 |= V_338 ;
V_19 -> V_59 &= ~ V_298 ;
F_168 ( V_10 , V_19 -> V_43 ) ;
}
if ( F_114 ( V_10 , V_19 , V_237 , V_339 ) == 0 )
return true ;
F_40 ( V_35 , L_46 ) ;
F_21 ( & V_10 -> V_26 ) ;
F_112 ( & V_19 -> V_22 . V_23 ) ;
F_151 ( & V_19 -> V_54 ) ;
F_22 ( & V_10 -> V_26 ) ;
if ( V_19 -> V_59 & V_338 )
F_169 ( V_10 , V_19 -> V_43 ) ;
V_325:
F_107 ( V_10 , V_19 -> V_55 , V_218 + V_217 ) ;
F_106 ( V_10 ) ;
F_51 ( V_10 , V_19 ) ;
return false ;
}
int F_170 ( struct V_9 * V_10 , T_3 V_43 )
{
struct V_340 * V_341 = V_10 -> V_205 -> V_206 -> V_342 -> V_343 ;
unsigned long V_344 , V_345 , V_346 ;
struct V_347 * V_4 ;
int V_348 ;
int V_349 = 0 ;
if ( V_10 -> V_193 . V_350 == 0 )
return 0 ;
F_21 ( & V_10 -> V_351 ) ;
V_4 = F_171 ( V_10 -> V_352 , F_172 ( V_43 ) ) ;
if ( V_4 ) {
struct V_353 * V_354 = F_173 ( V_4 , struct V_353 , V_355 ) ;
if ( F_109 ( V_356 , & V_354 -> V_59 ) ) {
F_22 ( & V_10 -> V_351 ) ;
return 0 ;
}
}
F_22 ( & V_10 -> V_351 ) ;
V_348 = ( int ) F_174 ( & V_341 -> V_357 , V_358 [ 0 ] ) +
( int ) F_174 ( & V_341 -> V_357 , V_358 [ 1 ] ) -
F_27 ( & V_10 -> V_285 ) ;
if ( ! V_10 -> V_359 || V_348 - V_10 -> V_359 > 64 ) {
unsigned long V_360 ;
int V_6 ;
V_10 -> V_359 = V_348 ;
V_6 = ( V_10 -> V_361 + V_362 - 1 ) % V_362 ;
if ( V_10 -> V_67 . V_68 == V_363 || V_10 -> V_67 . V_68 == V_364 )
V_360 = V_10 -> V_365 ;
else
V_360 = F_175 ( V_10 ) - V_10 -> V_366 ;
V_345 = ( ( long ) V_186 - ( long ) V_10 -> V_367 [ V_6 ] ) / V_125 ;
if ( ! V_345 )
V_345 ++ ;
V_344 = V_10 -> V_368 [ V_6 ] - V_360 ;
V_346 = F_176 ( V_344 / V_345 ) ;
if ( V_346 > V_10 -> V_193 . V_350 )
V_349 = 1 ;
}
return V_349 ;
}
static int F_177 ( struct V_9 * V_10 , enum V_150 V_151 , unsigned int V_369 )
{
T_3 V_43 ;
const T_3 V_258 = F_126 ( V_10 -> V_259 ) ;
struct V_18 * V_19 ;
struct V_370 * V_371 = NULL ;
int V_58 , V_372 ;
unsigned int V_238 ;
struct V_373 * V_255 = & V_10 -> V_103 . V_157 . V_374 ;
V_43 = F_144 ( V_255 -> V_43 ) ;
V_58 = F_101 ( V_255 -> V_375 ) ;
if ( V_58 <= 0 || ( V_58 & 0x1ff ) != 0 || V_58 > V_39 ) {
F_40 ( V_35 , L_55 , __FILE__ , __LINE__ ,
( unsigned long long ) V_43 , V_58 ) ;
return false ;
}
if ( V_43 + ( V_58 >> 9 ) > V_258 ) {
F_40 ( V_35 , L_55 , __FILE__ , __LINE__ ,
( unsigned long long ) V_43 , V_58 ) ;
return false ;
}
if ( ! F_178 ( V_10 , V_376 ) ) {
V_372 = 1 ;
switch ( V_151 ) {
case V_377 :
F_179 ( V_10 , V_378 , V_255 ) ;
break;
case V_379 :
case V_380 :
case V_381 :
F_179 ( V_10 , V_382 , V_255 ) ;
break;
case V_383 :
V_372 = 0 ;
F_142 ( V_10 ) ;
F_180 ( V_10 , V_384 , V_43 , V_58 , V_385 ) ;
break;
default:
F_40 ( V_35 , L_56 ,
F_181 ( V_151 ) ) ;
}
if ( V_372 && F_148 ( & V_290 ) )
F_40 ( V_35 , L_57
L_58 ) ;
return F_133 ( V_10 , V_369 ) ;
}
V_19 = F_37 ( V_10 , V_255 -> V_60 , V_43 , V_58 , V_178 ) ;
if ( ! V_19 ) {
F_106 ( V_10 ) ;
return false ;
}
switch ( V_151 ) {
case V_377 :
V_19 -> V_22 . V_71 = V_386 ;
V_238 = V_387 ;
goto V_388;
case V_379 :
V_19 -> V_22 . V_71 = V_389 ;
V_238 = V_390 ;
V_10 -> V_391 = F_182 ( V_43 ) ;
break;
case V_383 :
case V_380 :
V_238 = V_390 ;
V_371 = F_122 ( sizeof( * V_371 ) + V_369 , V_178 ) ;
if ( ! V_371 )
goto V_392;
V_371 -> V_369 = V_369 ;
V_371 -> V_62 = ( ( ( char * ) V_371 ) + sizeof( struct V_370 ) ) ;
V_19 -> V_62 = V_371 ;
V_19 -> V_59 |= V_61 ;
if ( F_63 ( V_10 , V_371 -> V_62 , V_369 ) != V_369 )
goto V_392;
if ( V_151 == V_380 ) {
F_46 ( V_10 -> V_265 >= 89 ) ;
V_19 -> V_22 . V_71 = V_393 ;
V_10 -> V_391 = F_182 ( V_43 ) ;
} else if ( V_151 == V_383 ) {
F_33 ( V_58 >> 9 , & V_10 -> V_291 ) ;
V_19 -> V_22 . V_71 = V_394 ;
F_142 ( V_10 ) ;
goto V_395;
}
break;
case V_381 :
if ( V_10 -> V_396 == ~ ( T_3 ) 0 &&
V_10 -> V_265 >= 90 ) {
unsigned long V_397 = V_186 ;
int V_6 ;
V_10 -> V_396 = V_43 ;
V_10 -> V_398 = V_43 ;
V_10 -> V_365 = F_183 ( V_10 ) - F_182 ( V_43 ) ;
V_10 -> V_399 = V_10 -> V_365 ;
for ( V_6 = 0 ; V_6 < V_362 ; V_6 ++ ) {
V_10 -> V_368 [ V_6 ] = V_10 -> V_365 ;
V_10 -> V_367 [ V_6 ] = V_397 ;
}
F_64 ( V_35 , L_59 ,
( unsigned long long ) V_43 ) ;
}
V_19 -> V_22 . V_71 = V_400 ;
V_238 = V_390 ;
break;
default:
F_40 ( V_35 , L_56 ,
F_181 ( V_151 ) ) ;
V_238 = V_401 ;
goto V_392;
}
if ( V_10 -> V_67 . V_402 != V_403 && F_170 ( V_10 , V_43 ) )
F_184 ( V_125 / 10 ) ;
if ( F_185 ( V_10 , V_43 ) )
goto V_392;
V_395:
F_33 ( V_58 >> 9 , & V_10 -> V_285 ) ;
V_388:
F_121 ( V_10 ) ;
F_21 ( & V_10 -> V_26 ) ;
F_165 ( & V_19 -> V_22 . V_23 , & V_10 -> V_404 ) ;
F_22 ( & V_10 -> V_26 ) ;
if ( F_114 ( V_10 , V_19 , V_405 , V_238 ) == 0 )
return true ;
F_40 ( V_35 , L_46 ) ;
F_21 ( & V_10 -> V_26 ) ;
F_112 ( & V_19 -> V_22 . V_23 ) ;
F_22 ( & V_10 -> V_26 ) ;
V_392:
F_106 ( V_10 ) ;
F_51 ( V_10 , V_19 ) ;
return false ;
}
static int F_186 ( struct V_9 * V_10 ) __must_hold( T_5 )
{
int V_406 , V_402 , V_101 = - 100 ;
unsigned long V_407 , V_408 ;
V_406 = V_10 -> V_205 -> V_409 . V_410 [ V_411 ] & 1 ;
V_402 = V_10 -> V_412 [ V_411 ] & 1 ;
V_408 = V_10 -> V_412 [ V_413 ] ;
V_407 = V_10 -> V_414 ;
switch ( V_10 -> V_30 -> V_415 ) {
case V_416 :
case V_417 :
case V_418 :
F_40 ( V_35 , L_60 ) ;
break;
case V_419 :
break;
case V_420 :
if ( V_406 == 0 && V_402 == 1 ) {
V_101 = - 1 ;
break;
}
if ( V_406 == 1 && V_402 == 0 ) {
V_101 = 1 ;
break;
}
case V_421 :
if ( V_406 == 0 && V_402 == 1 ) {
V_101 = 1 ;
break;
}
if ( V_406 == 1 && V_402 == 0 ) {
V_101 = - 1 ;
break;
}
F_30 ( V_35 , L_61
L_62 ) ;
case V_422 :
if ( V_408 == 0 && V_407 == 0 ) {
V_101 = F_109 ( V_170 , & V_10 -> V_59 )
? - 1 : 1 ;
break;
} else {
if ( V_408 == 0 ) { V_101 = 1 ; break; }
if ( V_407 == 0 ) { V_101 = - 1 ; break; }
}
if ( V_10 -> V_30 -> V_415 == V_422 )
break;
case V_423 :
if ( V_407 < V_408 )
V_101 = - 1 ;
else if ( V_407 > V_408 )
V_101 = 1 ;
else
V_101 = F_109 ( V_170 , & V_10 -> V_59 )
? - 1 : 1 ;
break;
case V_424 :
V_101 = - 1 ;
break;
case V_425 :
V_101 = 1 ;
}
return V_101 ;
}
static int F_187 ( struct V_9 * V_10 ) __must_hold( T_5 )
{
int V_426 , V_101 = - 100 ;
switch ( V_10 -> V_30 -> V_427 ) {
case V_420 :
case V_421 :
case V_423 :
case V_424 :
case V_425 :
F_40 ( V_35 , L_60 ) ;
break;
case V_419 :
break;
case V_416 :
V_426 = F_186 ( V_10 ) ;
if ( V_426 == - 1 && V_10 -> V_67 . V_428 == V_429 )
V_101 = V_426 ;
if ( V_426 == 1 && V_10 -> V_67 . V_428 == V_403 )
V_101 = V_426 ;
break;
case V_430 :
V_101 = F_186 ( V_10 ) ;
break;
case V_417 :
return V_10 -> V_67 . V_428 == V_403 ? 1 : - 1 ;
case V_418 :
V_426 = F_186 ( V_10 ) ;
if ( V_426 == - 1 && V_10 -> V_67 . V_428 == V_403 ) {
enum V_431 V_432 ;
F_188 ( V_10 , V_429 , 0 ) ;
V_432 = F_189 ( V_10 , V_433 , F_66 ( V_428 , V_429 ) ) ;
if ( V_432 != V_169 ) {
F_190 ( V_10 , L_63 ) ;
} else {
F_30 ( V_35 , L_64 ) ;
V_101 = V_426 ;
}
} else
V_101 = V_426 ;
}
return V_101 ;
}
static int F_191 ( struct V_9 * V_10 ) __must_hold( T_5 )
{
int V_426 , V_101 = - 100 ;
switch ( V_10 -> V_30 -> V_434 ) {
case V_420 :
case V_421 :
case V_423 :
case V_424 :
case V_425 :
case V_416 :
case V_417 :
F_40 ( V_35 , L_60 ) ;
break;
case V_430 :
V_101 = F_186 ( V_10 ) ;
break;
case V_419 :
break;
case V_418 :
V_426 = F_186 ( V_10 ) ;
if ( V_426 == - 1 ) {
enum V_431 V_432 ;
V_432 = F_189 ( V_10 , V_433 , F_66 ( V_428 , V_429 ) ) ;
if ( V_432 != V_169 ) {
F_190 ( V_10 , L_63 ) ;
} else {
F_30 ( V_35 , L_64 ) ;
V_101 = V_426 ;
}
} else
V_101 = V_426 ;
}
return V_101 ;
}
static void F_192 ( struct V_9 * V_10 , char * V_435 , T_2 * V_410 ,
T_2 V_436 , T_2 V_59 )
{
if ( ! V_410 ) {
F_64 ( V_35 , L_65 , V_435 ) ;
return;
}
F_64 ( V_35 , L_66 ,
V_435 ,
( unsigned long long ) V_410 [ V_437 ] ,
( unsigned long long ) V_410 [ V_411 ] ,
( unsigned long long ) V_410 [ V_438 ] ,
( unsigned long long ) V_410 [ V_439 ] ,
( unsigned long long ) V_436 ,
( unsigned long long ) V_59 ) ;
}
static int F_193 ( struct V_9 * V_10 , int * V_440 ) __must_hold( T_5 )
{
T_2 V_406 , V_402 ;
int V_6 , V_441 ;
V_406 = V_10 -> V_205 -> V_409 . V_410 [ V_437 ] & ~ ( ( T_2 ) 1 ) ;
V_402 = V_10 -> V_412 [ V_437 ] & ~ ( ( T_2 ) 1 ) ;
* V_440 = 10 ;
if ( V_406 == V_442 && V_402 == V_442 )
return 0 ;
* V_440 = 20 ;
if ( ( V_406 == V_442 || V_406 == ( T_2 ) 0 ) &&
V_402 != V_442 )
return - 2 ;
* V_440 = 30 ;
if ( V_406 != V_442 &&
( V_402 == V_442 || V_402 == ( T_2 ) 0 ) )
return 2 ;
if ( V_406 == V_402 ) {
int V_443 , V_234 ;
if ( V_10 -> V_412 [ V_411 ] == ( T_2 ) 0 && V_10 -> V_205 -> V_409 . V_410 [ V_411 ] != ( T_2 ) 0 ) {
if ( V_10 -> V_265 < 91 )
return - 1091 ;
if ( ( V_10 -> V_205 -> V_409 . V_410 [ V_411 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_412 [ V_438 ] & ~ ( ( T_2 ) 1 ) ) &&
( V_10 -> V_205 -> V_409 . V_410 [ V_438 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_412 [ V_438 + 1 ] & ~ ( ( T_2 ) 1 ) ) ) {
F_64 ( V_35 , L_67 ) ;
F_194 ( V_10 , 0UL ) ;
F_192 ( V_10 , L_68 , V_10 -> V_205 -> V_409 . V_410 ,
V_10 -> V_67 . V_341 >= V_444 ? F_175 ( V_10 ) : 0 , 0 ) ;
* V_440 = 34 ;
} else {
F_64 ( V_35 , L_69 ) ;
* V_440 = 36 ;
}
return 1 ;
}
if ( V_10 -> V_205 -> V_409 . V_410 [ V_411 ] == ( T_2 ) 0 && V_10 -> V_412 [ V_411 ] != ( T_2 ) 0 ) {
if ( V_10 -> V_265 < 91 )
return - 1091 ;
if ( ( V_10 -> V_205 -> V_409 . V_410 [ V_438 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_412 [ V_411 ] & ~ ( ( T_2 ) 1 ) ) &&
( V_10 -> V_205 -> V_409 . V_410 [ V_438 + 1 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_412 [ V_438 ] & ~ ( ( T_2 ) 1 ) ) ) {
F_64 ( V_35 , L_70 ) ;
V_10 -> V_412 [ V_438 + 1 ] = V_10 -> V_412 [ V_438 ] ;
V_10 -> V_412 [ V_438 ] = V_10 -> V_412 [ V_411 ] ;
V_10 -> V_412 [ V_411 ] = 0UL ;
F_192 ( V_10 , L_71 , V_10 -> V_412 , V_10 -> V_412 [ V_413 ] , V_10 -> V_412 [ V_445 ] ) ;
* V_440 = 35 ;
} else {
F_64 ( V_35 , L_72 ) ;
* V_440 = 37 ;
}
return - 1 ;
}
V_443 = ( F_109 ( V_446 , & V_10 -> V_59 ) ? 1 : 0 ) +
( V_10 -> V_412 [ V_445 ] & 2 ) ;
* V_440 = 40 ;
switch ( V_443 ) {
case 0 : return 0 ;
case 1 : return 1 ;
case 2 : return - 1 ;
case 3 :
V_234 = F_109 ( V_170 , & V_10 -> V_59 ) ;
return V_234 ? - 1 : 1 ;
}
}
* V_440 = 50 ;
V_402 = V_10 -> V_412 [ V_411 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_406 == V_402 )
return - 1 ;
* V_440 = 51 ;
V_402 = V_10 -> V_412 [ V_438 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_406 == V_402 ) {
if ( V_10 -> V_265 < 96 ?
( V_10 -> V_205 -> V_409 . V_410 [ V_438 ] & ~ ( ( T_2 ) 1 ) ) ==
( V_10 -> V_412 [ V_438 + 1 ] & ~ ( ( T_2 ) 1 ) ) :
V_402 + V_447 == ( V_10 -> V_412 [ V_411 ] & ~ ( ( T_2 ) 1 ) ) ) {
if ( V_10 -> V_265 < 91 )
return - 1091 ;
V_10 -> V_412 [ V_411 ] = V_10 -> V_412 [ V_438 ] ;
V_10 -> V_412 [ V_438 ] = V_10 -> V_412 [ V_438 + 1 ] ;
F_64 ( V_35 , L_73 ) ;
F_192 ( V_10 , L_71 , V_10 -> V_412 , V_10 -> V_412 [ V_413 ] , V_10 -> V_412 [ V_445 ] ) ;
return - 1 ;
}
}
* V_440 = 60 ;
V_406 = V_10 -> V_205 -> V_409 . V_410 [ V_437 ] & ~ ( ( T_2 ) 1 ) ;
for ( V_6 = V_438 ; V_6 <= V_439 ; V_6 ++ ) {
V_402 = V_10 -> V_412 [ V_6 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_406 == V_402 )
return - 2 ;
}
* V_440 = 70 ;
V_406 = V_10 -> V_205 -> V_409 . V_410 [ V_411 ] & ~ ( ( T_2 ) 1 ) ;
V_402 = V_10 -> V_412 [ V_437 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_406 == V_402 )
return 1 ;
* V_440 = 71 ;
V_406 = V_10 -> V_205 -> V_409 . V_410 [ V_438 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_406 == V_402 ) {
if ( V_10 -> V_265 < 96 ?
( V_10 -> V_205 -> V_409 . V_410 [ V_438 + 1 ] & ~ ( ( T_2 ) 1 ) ) ==
( V_10 -> V_412 [ V_438 ] & ~ ( ( T_2 ) 1 ) ) :
V_406 + V_447 == ( V_10 -> V_205 -> V_409 . V_410 [ V_411 ] & ~ ( ( T_2 ) 1 ) ) ) {
if ( V_10 -> V_265 < 91 )
return - 1091 ;
F_195 ( V_10 , V_411 , V_10 -> V_205 -> V_409 . V_410 [ V_438 ] ) ;
F_195 ( V_10 , V_438 , V_10 -> V_205 -> V_409 . V_410 [ V_438 + 1 ] ) ;
F_64 ( V_35 , L_74 ) ;
F_192 ( V_10 , L_68 , V_10 -> V_205 -> V_409 . V_410 ,
V_10 -> V_67 . V_341 >= V_444 ? F_175 ( V_10 ) : 0 , 0 ) ;
return 1 ;
}
}
* V_440 = 80 ;
V_402 = V_10 -> V_412 [ V_437 ] & ~ ( ( T_2 ) 1 ) ;
for ( V_6 = V_438 ; V_6 <= V_439 ; V_6 ++ ) {
V_406 = V_10 -> V_205 -> V_409 . V_410 [ V_6 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_406 == V_402 )
return 2 ;
}
* V_440 = 90 ;
V_406 = V_10 -> V_205 -> V_409 . V_410 [ V_411 ] & ~ ( ( T_2 ) 1 ) ;
V_402 = V_10 -> V_412 [ V_411 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_406 == V_402 && V_406 != ( ( T_2 ) 0 ) )
return 100 ;
* V_440 = 100 ;
for ( V_6 = V_438 ; V_6 <= V_439 ; V_6 ++ ) {
V_406 = V_10 -> V_205 -> V_409 . V_410 [ V_6 ] & ~ ( ( T_2 ) 1 ) ;
for ( V_441 = V_438 ; V_441 <= V_439 ; V_441 ++ ) {
V_402 = V_10 -> V_412 [ V_441 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_406 == V_402 )
return - 100 ;
}
}
return - 1000 ;
}
static enum V_448 F_196 ( struct V_9 * V_10 , enum V_449 V_450 ,
enum V_451 V_452 ) __must_hold( T_5 )
{
int V_426 , V_440 ;
enum V_448 V_101 = V_453 ;
enum V_451 V_454 ;
V_454 = V_10 -> V_67 . V_341 ;
if ( V_454 == V_444 )
V_454 = V_10 -> V_455 . V_341 ;
F_64 ( V_35 , L_75 ) ;
F_192 ( V_10 , L_68 , V_10 -> V_205 -> V_409 . V_410 , V_10 -> V_414 , 0 ) ;
F_192 ( V_10 , L_71 , V_10 -> V_412 ,
V_10 -> V_412 [ V_413 ] , V_10 -> V_412 [ V_445 ] ) ;
V_426 = F_193 ( V_10 , & V_440 ) ;
F_64 ( V_35 , L_76 , V_426 , V_440 ) ;
if ( V_426 == - 1000 ) {
F_164 ( V_35 , L_77 ) ;
return V_453 ;
}
if ( V_426 < - 1000 ) {
F_164 ( V_35 , L_78 , - V_426 - 1000 ) ;
return V_453 ;
}
if ( ( V_454 == V_337 && V_452 > V_337 ) ||
( V_452 == V_337 && V_454 > V_337 ) ) {
int V_456 = ( V_426 == - 100 ) || abs ( V_426 ) == 2 ;
V_426 = V_454 > V_337 ? 1 : - 1 ;
if ( V_456 )
V_426 = V_426 * 2 ;
F_64 ( V_35 , L_79 ,
V_426 > 0 ? L_80 : L_81 ) ;
}
if ( abs ( V_426 ) == 100 )
F_190 ( V_10 , L_82 ) ;
if ( V_426 == 100 || ( V_426 == - 100 && V_10 -> V_30 -> V_457 ) ) {
int V_458 = ( V_10 -> V_67 . V_428 == V_403 )
+ ( V_450 == V_403 ) ;
int V_459 = ( V_426 == - 100 ) ;
switch ( V_458 ) {
case 0 :
V_426 = F_186 ( V_10 ) ;
break;
case 1 :
V_426 = F_187 ( V_10 ) ;
break;
case 2 :
V_426 = F_191 ( V_10 ) ;
break;
}
if ( abs ( V_426 ) < 100 ) {
F_30 ( V_35 , L_83
L_84 ,
V_458 , ( V_426 < 0 ) ? L_71 : L_85 ) ;
if ( V_459 ) {
F_30 ( V_35 , L_86
L_87 ) ;
V_426 = V_426 * 2 ;
}
}
}
if ( V_426 == - 100 ) {
if ( V_10 -> V_30 -> V_460 && ! ( V_10 -> V_412 [ V_445 ] & 1 ) )
V_426 = - 1 ;
if ( ! V_10 -> V_30 -> V_460 && ( V_10 -> V_412 [ V_445 ] & 1 ) )
V_426 = 1 ;
if ( abs ( V_426 ) < 100 )
F_30 ( V_35 , L_88
L_89 ,
( V_426 < 0 ) ? L_71 : L_85 ) ;
}
if ( V_426 == - 100 ) {
F_164 ( V_35 , L_90 ) ;
F_190 ( V_10 , L_91 ) ;
return V_453 ;
}
if ( V_426 > 0 && V_454 <= V_337 ) {
F_40 ( V_35 , L_92 ) ;
return V_453 ;
}
if ( V_426 < 0 &&
V_10 -> V_67 . V_428 == V_403 && V_10 -> V_67 . V_341 >= V_461 ) {
switch ( V_10 -> V_30 -> V_462 ) {
case V_418 :
F_190 ( V_10 , L_93 ) ;
case V_419 :
F_40 ( V_35 , L_94 ) ;
return V_453 ;
case V_430 :
F_30 ( V_35 , L_95
L_96 ) ;
}
}
if ( V_10 -> V_30 -> V_463 || F_109 ( V_464 , & V_10 -> V_59 ) ) {
if ( V_426 == 0 )
F_64 ( V_35 , L_97 ) ;
else
F_64 ( V_35 , L_98 ,
F_197 ( V_426 > 0 ? V_296 : V_465 ) ,
abs ( V_426 ) >= 2 ? L_99 : L_100 ) ;
return V_453 ;
}
if ( abs ( V_426 ) >= 2 ) {
F_64 ( V_35 , L_101 ) ;
if ( F_198 ( V_10 , & V_466 , L_102 ,
V_467 ) )
return V_453 ;
}
if ( V_426 > 0 ) {
V_101 = V_468 ;
} else if ( V_426 < 0 ) {
V_101 = V_469 ;
} else {
V_101 = V_470 ;
if ( F_175 ( V_10 ) ) {
F_64 ( V_35 , L_103 ,
F_175 ( V_10 ) ) ;
}
}
return V_101 ;
}
static int F_199 ( enum V_471 V_402 , enum V_471 V_406 )
{
if ( ( V_402 == V_425 && V_406 == V_424 ) ||
( V_406 == V_425 && V_402 == V_424 ) )
return 0 ;
if ( V_402 == V_425 || V_402 == V_424 ||
V_406 == V_425 || V_406 == V_424 )
return 1 ;
if ( V_402 == V_406 )
return 0 ;
return 1 ;
}
static int F_200 ( struct V_9 * V_10 , enum V_150 V_151 , unsigned int V_44 )
{
struct V_472 * V_255 = & V_10 -> V_103 . V_157 . V_473 ;
int V_474 , V_475 , V_476 , V_477 ;
int V_478 , V_479 , V_480 ;
char V_481 [ V_482 ] = L_104 ;
V_474 = F_101 ( V_255 -> V_473 ) ;
V_475 = F_101 ( V_255 -> V_415 ) ;
V_476 = F_101 ( V_255 -> V_427 ) ;
V_477 = F_101 ( V_255 -> V_434 ) ;
V_479 = F_101 ( V_255 -> V_300 ) ;
V_480 = F_101 ( V_255 -> V_483 ) ;
V_478 = V_480 & V_484 ;
F_82 ( V_464 , & V_10 -> V_59 ) ;
if ( V_480 & V_485 )
F_84 ( V_464 , & V_10 -> V_59 ) ;
if ( V_474 != V_10 -> V_30 -> V_294 ) {
F_40 ( V_35 , L_105 ) ;
goto V_486;
}
if ( F_199 ( V_475 , V_10 -> V_30 -> V_415 ) ) {
F_40 ( V_35 , L_106 ) ;
goto V_486;
}
if ( F_199 ( V_476 , V_10 -> V_30 -> V_427 ) ) {
F_40 ( V_35 , L_107 ) ;
goto V_486;
}
if ( F_199 ( V_477 , V_10 -> V_30 -> V_434 ) ) {
F_40 ( V_35 , L_108 ) ;
goto V_486;
}
if ( V_478 && V_10 -> V_30 -> V_460 ) {
F_40 ( V_35 , L_109 ) ;
goto V_486;
}
if ( V_479 != V_10 -> V_30 -> V_300 ) {
F_40 ( V_35 , L_110 ) ;
goto V_486;
}
if ( V_10 -> V_265 >= 87 ) {
unsigned char * V_487 = V_10 -> V_30 -> V_488 ;
if ( F_63 ( V_10 , V_481 , V_44 ) != V_44 )
return false ;
V_481 [ V_482 - 1 ] = 0 ;
if ( strcmp ( V_481 , V_487 ) ) {
F_40 ( V_35 , L_111 ) ;
goto V_486;
}
F_64 ( V_35 , L_112 ,
V_487 [ 0 ] ? V_487 : ( unsigned char * ) L_113 ) ;
}
return true ;
V_486:
F_65 ( V_10 , F_66 ( V_68 , V_145 ) ) ;
return false ;
}
struct V_489 * F_201 ( const struct V_9 * V_10 ,
const char * V_490 , const char * V_491 )
{
struct V_489 * V_492 ;
if ( ! V_490 [ 0 ] )
return NULL ;
V_492 = F_202 ( V_490 , 0 , V_493 ) ;
if ( F_203 ( V_492 ) ) {
F_40 ( V_35 , L_114 ,
V_490 , V_491 , F_204 ( V_492 ) ) ;
return V_492 ;
}
if ( ! F_205 ( F_206 ( V_492 ) ) ) {
F_207 ( V_492 ) ;
F_40 ( V_35 , L_115 , V_490 , V_491 ) ;
return F_208 ( - V_494 ) ;
}
return V_492 ;
}
static int F_209 ( struct V_9 * V_10 , enum V_150 V_151 , unsigned int V_197 )
{
int V_66 = true ;
struct V_495 * V_255 = & V_10 -> V_103 . V_157 . V_496 ;
unsigned int V_497 , V_44 , V_498 ;
struct V_489 * V_499 = NULL ;
struct V_489 * V_500 = NULL ;
const int V_501 = V_10 -> V_265 ;
int * V_502 = NULL ;
int V_503 = 0 ;
V_498 = V_501 <= 87 ? sizeof( struct V_504 )
: V_501 == 88 ? sizeof( struct V_504 )
+ V_482
: V_501 <= 94 ? sizeof( struct V_505 )
: sizeof( struct V_495 ) ;
if ( V_197 > V_498 ) {
F_40 ( V_35 , L_116 ,
V_197 , V_498 ) ;
return false ;
}
if ( V_501 <= 88 ) {
V_497 = sizeof( struct V_504 ) - sizeof( struct V_152 ) ;
V_44 = V_197 - V_497 ;
} else if ( V_501 <= 94 ) {
V_497 = sizeof( struct V_505 ) - sizeof( struct V_152 ) ;
V_44 = V_197 - V_497 ;
F_46 ( V_44 == 0 ) ;
} else {
V_497 = sizeof( struct V_495 ) - sizeof( struct V_152 ) ;
V_44 = V_197 - V_497 ;
F_46 ( V_44 == 0 ) ;
}
memset ( V_255 -> V_506 , 0 , 2 * V_482 ) ;
if ( F_63 ( V_10 , & V_255 -> V_2 . V_507 , V_497 ) != V_497 )
return false ;
V_10 -> V_193 . V_508 = F_101 ( V_255 -> V_508 ) ;
if ( V_501 >= 88 ) {
if ( V_501 == 88 ) {
if ( V_44 > V_482 ) {
F_40 ( V_35 , L_117
L_118 ,
V_44 , V_482 ) ;
return false ;
}
if ( F_63 ( V_10 , V_255 -> V_506 , V_44 ) != V_44 )
return false ;
F_46 ( V_255 -> V_506 [ V_44 - 1 ] == 0 ) ;
V_255 -> V_506 [ V_44 - 1 ] = 0 ;
} else {
F_46 ( V_255 -> V_506 [ V_482 - 1 ] == 0 ) ;
F_46 ( V_255 -> V_509 [ V_482 - 1 ] == 0 ) ;
V_255 -> V_506 [ V_482 - 1 ] = 0 ;
V_255 -> V_509 [ V_482 - 1 ] = 0 ;
}
if ( strcmp ( V_10 -> V_193 . V_506 , V_255 -> V_506 ) ) {
if ( V_10 -> V_67 . V_68 == V_69 ) {
F_40 ( V_35 , L_119 ,
V_10 -> V_193 . V_506 , V_255 -> V_506 ) ;
goto V_486;
}
V_499 = F_201 ( V_10 ,
V_255 -> V_506 , L_120 ) ;
if ( F_203 ( V_499 ) ) {
V_499 = NULL ;
goto V_486;
}
}
if ( V_501 >= 89 && strcmp ( V_10 -> V_193 . V_509 , V_255 -> V_509 ) ) {
if ( V_10 -> V_67 . V_68 == V_69 ) {
F_40 ( V_35 , L_121 ,
V_10 -> V_193 . V_509 , V_255 -> V_509 ) ;
goto V_486;
}
V_500 = F_201 ( V_10 ,
V_255 -> V_509 , L_122 ) ;
if ( F_203 ( V_500 ) ) {
V_500 = NULL ;
goto V_486;
}
}
if ( V_501 > 94 ) {
V_10 -> V_193 . V_508 = F_101 ( V_255 -> V_508 ) ;
V_10 -> V_193 . V_510 = F_101 ( V_255 -> V_510 ) ;
V_10 -> V_193 . V_511 = F_101 ( V_255 -> V_511 ) ;
V_10 -> V_193 . V_512 = F_101 ( V_255 -> V_512 ) ;
V_10 -> V_193 . V_513 = F_101 ( V_255 -> V_513 ) ;
V_503 = ( V_10 -> V_193 . V_510 * 10 * V_514 ) / V_125 ;
if ( V_503 != V_10 -> V_502 . V_58 && V_503 > 0 ) {
V_502 = F_210 ( sizeof( int ) * V_503 , V_207 ) ;
if ( ! V_502 ) {
F_40 ( V_35 , L_123 ) ;
goto V_486;
}
}
}
F_11 ( & V_10 -> V_304 ) ;
if ( V_499 ) {
strcpy ( V_10 -> V_193 . V_506 , V_255 -> V_506 ) ;
V_10 -> V_193 . V_515 = strlen ( V_255 -> V_506 ) + 1 ;
F_207 ( V_10 -> V_499 ) ;
V_10 -> V_499 = V_499 ;
F_64 ( V_35 , L_124 , V_255 -> V_506 ) ;
}
if ( V_500 ) {
strcpy ( V_10 -> V_193 . V_509 , V_255 -> V_509 ) ;
V_10 -> V_193 . V_516 = strlen ( V_255 -> V_509 ) + 1 ;
F_207 ( V_10 -> V_500 ) ;
V_10 -> V_500 = V_500 ;
F_64 ( V_35 , L_125 , V_255 -> V_509 ) ;
}
if ( V_503 != V_10 -> V_502 . V_58 ) {
F_45 ( V_10 -> V_502 . V_517 ) ;
V_10 -> V_502 . V_517 = V_502 ;
V_10 -> V_502 . V_58 = V_503 ;
V_10 -> V_518 = 0 ;
}
F_12 ( & V_10 -> V_304 ) ;
}
return V_66 ;
V_486:
F_207 ( V_500 ) ;
F_207 ( V_499 ) ;
F_65 ( V_10 , F_66 ( V_68 , V_145 ) ) ;
return false ;
}
static void F_211 ( struct V_9 * V_10 ,
const char * V_165 , T_3 V_37 , T_3 V_519 )
{
T_3 V_520 ;
if ( V_37 == 0 || V_519 == 0 )
return;
V_520 = ( V_37 > V_519 ) ? ( V_37 - V_519 ) : ( V_519 - V_37 ) ;
if ( V_520 > ( V_37 >> 3 ) || V_520 > ( V_519 >> 3 ) )
F_30 ( V_35 , L_126 , V_165 ,
( unsigned long long ) V_37 , ( unsigned long long ) V_519 ) ;
}
static int F_212 ( struct V_9 * V_10 , enum V_150 V_151 , unsigned int V_44 )
{
struct V_521 * V_255 = & V_10 -> V_103 . V_157 . V_522 ;
enum V_523 V_524 = V_525 ;
T_3 V_526 , V_527 , V_528 ;
int V_529 = 0 ;
enum V_530 V_531 ;
V_526 = F_144 ( V_255 -> V_532 ) ;
V_527 = F_144 ( V_255 -> V_533 ) ;
if ( V_526 == 0 && V_10 -> V_67 . V_341 == V_534 ) {
F_40 ( V_35 , L_127 ) ;
F_65 ( V_10 , F_66 ( V_68 , V_145 ) ) ;
return false ;
}
V_10 -> V_526 = V_526 ;
if ( F_103 ( V_10 ) ) {
F_211 ( V_10 , L_128 ,
V_526 , F_213 ( V_10 -> V_205 ) ) ;
F_211 ( V_10 , L_129 ,
V_527 , V_10 -> V_205 -> V_234 . V_535 ) ;
if ( V_10 -> V_67 . V_68 == V_69 )
V_527 = F_214 ( ( T_3 ) V_10 -> V_205 -> V_234 . V_535 ,
V_527 ) ;
V_528 = V_10 -> V_205 -> V_234 . V_535 ;
if ( V_10 -> V_205 -> V_234 . V_535 != V_527 ) {
V_10 -> V_205 -> V_234 . V_535 = V_527 ;
F_64 ( V_35 , L_130 ,
( unsigned long ) V_10 -> V_205 -> V_234 . V_535 ) ;
}
if ( F_215 ( V_10 , V_10 -> V_205 , 0 ) <
F_126 ( V_10 -> V_259 ) &&
V_10 -> V_67 . V_341 >= V_536 &&
V_10 -> V_67 . V_68 < V_470 ) {
F_40 ( V_35 , L_131 ) ;
F_65 ( V_10 , F_66 ( V_68 , V_145 ) ) ;
V_10 -> V_205 -> V_234 . V_535 = V_528 ;
F_106 ( V_10 ) ;
return false ;
}
F_106 ( V_10 ) ;
}
V_531 = F_78 ( V_255 -> V_530 ) ;
if ( F_103 ( V_10 ) ) {
V_524 = F_216 ( V_10 , V_531 ) ;
F_106 ( V_10 ) ;
if ( V_524 == V_537 )
return false ;
F_217 ( V_10 ) ;
} else {
F_218 ( V_10 , V_526 ) ;
}
V_10 -> V_538 = F_101 ( V_255 -> V_539 ) ;
F_219 ( V_10 ) ;
if ( F_103 ( V_10 ) ) {
if ( V_10 -> V_205 -> V_540 != F_126 ( V_10 -> V_205 -> V_206 ) ) {
V_10 -> V_205 -> V_540 = F_126 ( V_10 -> V_205 -> V_206 ) ;
V_529 = 1 ;
}
F_106 ( V_10 ) ;
}
if ( V_10 -> V_67 . V_68 > V_69 ) {
if ( F_144 ( V_255 -> V_541 ) !=
F_126 ( V_10 -> V_259 ) || V_529 ) {
F_94 ( V_10 , 0 , V_531 ) ;
}
if ( F_220 ( V_195 , & V_10 -> V_59 ) ||
( V_524 == V_542 && V_10 -> V_67 . V_68 == V_470 ) ) {
if ( V_10 -> V_67 . V_336 >= V_337 &&
V_10 -> V_67 . V_341 >= V_337 ) {
if ( V_531 & V_543 )
F_64 ( V_35 , L_132 ) ;
else
F_221 ( V_10 ) ;
} else
F_84 ( V_544 , & V_10 -> V_59 ) ;
}
}
return true ;
}
static int F_222 ( struct V_9 * V_10 , enum V_150 V_151 , unsigned int V_44 )
{
struct V_545 * V_255 = & V_10 -> V_103 . V_157 . V_546 ;
T_2 * V_412 ;
int V_6 , V_547 = 0 ;
V_412 = F_122 ( sizeof( T_2 ) * V_548 , V_178 ) ;
for ( V_6 = V_437 ; V_6 < V_548 ; V_6 ++ )
V_412 [ V_6 ] = F_144 ( V_255 -> V_410 [ V_6 ] ) ;
F_45 ( V_10 -> V_412 ) ;
V_10 -> V_412 = V_412 ;
if ( V_10 -> V_67 . V_68 < V_470 &&
V_10 -> V_67 . V_341 < V_337 &&
V_10 -> V_67 . V_428 == V_403 &&
( V_10 -> V_549 & ~ ( ( T_2 ) 1 ) ) != ( V_412 [ V_437 ] & ~ ( ( T_2 ) 1 ) ) ) {
F_40 ( V_35 , L_133 ,
( unsigned long long ) V_10 -> V_549 ) ;
F_65 ( V_10 , F_66 ( V_68 , V_145 ) ) ;
return false ;
}
if ( F_103 ( V_10 ) ) {
int V_550 =
V_10 -> V_67 . V_68 == V_470 &&
V_10 -> V_265 >= 90 &&
V_10 -> V_205 -> V_409 . V_410 [ V_437 ] == V_442 &&
( V_412 [ V_445 ] & 8 ) ;
if ( V_550 ) {
F_64 ( V_35 , L_134 ) ;
F_198 ( V_10 , & V_551 ,
L_135 ,
V_552 ) ;
F_195 ( V_10 , V_437 , V_412 [ V_437 ] ) ;
F_195 ( V_10 , V_411 , 0 ) ;
F_223 ( F_224 ( V_10 , V_341 , V_376 , V_336 , V_376 ) ,
V_433 , NULL ) ;
F_217 ( V_10 ) ;
V_547 = 1 ;
}
F_106 ( V_10 ) ;
} else if ( V_10 -> V_67 . V_341 < V_337 &&
V_10 -> V_67 . V_428 == V_403 ) {
V_547 = F_225 ( V_10 , V_412 [ V_437 ] ) ;
}
F_123 ( V_10 -> V_328 , ! F_109 ( V_553 , & V_10 -> V_59 ) ) ;
if ( V_10 -> V_67 . V_68 >= V_470 && V_10 -> V_67 . V_341 < V_337 )
V_547 |= F_225 ( V_10 , V_412 [ V_437 ] ) ;
if ( V_547 )
F_226 ( V_10 , L_136 ) ;
return true ;
}
static union V_554 F_227 ( union V_554 V_555 )
{
union V_554 V_556 ;
static enum V_448 V_557 [] = {
[ V_470 ] = V_470 ,
[ V_558 ] = V_559 ,
[ V_559 ] = V_558 ,
[ V_145 ] = V_560 ,
[ V_363 ] = V_364 ,
[ V_453 ] = V_453 ,
} ;
V_556 . V_6 = V_555 . V_6 ;
V_556 . V_68 = V_557 [ V_555 . V_68 ] ;
V_556 . V_402 = V_555 . V_428 ;
V_556 . V_428 = V_555 . V_402 ;
V_556 . V_336 = V_555 . V_341 ;
V_556 . V_341 = V_555 . V_336 ;
V_556 . V_561 = ( V_555 . V_562 | V_555 . V_563 ) ;
return V_556 ;
}
static int F_228 ( struct V_9 * V_10 , enum V_150 V_151 , unsigned int V_44 )
{
struct V_564 * V_255 = & V_10 -> V_103 . V_157 . V_565 ;
union V_554 V_566 , V_567 ;
enum V_431 V_101 ;
V_566 . V_6 = F_101 ( V_255 -> V_566 ) ;
V_567 . V_6 = F_101 ( V_255 -> V_567 ) ;
if ( F_109 ( V_170 , & V_10 -> V_59 ) &&
F_109 ( V_553 , & V_10 -> V_59 ) ) {
F_229 ( V_10 , V_568 ) ;
return true ;
}
V_566 = F_227 ( V_566 ) ;
V_567 = F_227 ( V_567 ) ;
V_101 = F_189 ( V_10 , V_433 , V_566 , V_567 ) ;
F_229 ( V_10 , V_101 ) ;
F_217 ( V_10 ) ;
return true ;
}
static int F_230 ( struct V_9 * V_10 , enum V_150 V_151 , unsigned int V_44 )
{
struct V_569 * V_255 = & V_10 -> V_103 . V_157 . V_67 ;
union V_554 V_570 , V_571 , V_572 ;
enum V_451 V_573 ;
enum V_574 V_575 ;
int V_101 ;
V_572 . V_6 = F_101 ( V_255 -> V_67 ) ;
V_573 = V_572 . V_341 ;
if ( V_572 . V_341 == V_444 ) {
V_573 = V_10 -> V_412 [ V_445 ] & 4 ? V_337 : V_461 ;
F_64 ( V_35 , L_137 , F_231 ( V_573 ) ) ;
}
F_21 ( & V_10 -> V_26 ) ;
V_27:
V_570 = V_571 = V_10 -> V_67 ;
F_22 ( & V_10 -> V_26 ) ;
if ( V_570 . V_336 == V_337 && V_573 == V_376 &&
V_570 . V_68 > V_470 && V_570 . V_341 == V_376 ) {
if ( V_572 . V_68 > V_470 &&
V_572 . V_68 < V_296 )
V_573 = V_337 ;
else if ( V_570 . V_68 >= V_296 &&
V_572 . V_68 == V_470 ) {
if ( F_175 ( V_10 ) <= V_10 -> V_366 )
F_232 ( V_10 ) ;
return true ;
}
}
if ( V_570 . V_336 == V_376 && V_573 == V_337 &&
V_570 . V_68 == V_470 && V_572 . V_68 > V_296 )
V_573 = V_376 ;
if ( V_571 . V_68 == V_69 )
V_571 . V_68 = V_470 ;
if ( V_572 . V_68 == V_576 )
V_571 . V_68 = V_577 ;
if ( V_10 -> V_412 && V_572 . V_341 >= V_444 &&
F_178 ( V_10 , V_444 ) ) {
int V_578 ;
V_578 = ( V_570 . V_68 < V_470 ) ;
V_578 |= ( V_570 . V_68 == V_470 &&
( V_572 . V_341 == V_444 ||
V_570 . V_341 == V_444 ) ) ;
V_578 |= F_109 ( V_579 , & V_10 -> V_59 ) ;
V_578 |= ( V_570 . V_68 == V_470 &&
( V_572 . V_68 >= V_558 &&
V_572 . V_68 <= V_469 ) ) ;
if ( V_578 )
V_571 . V_68 = F_196 ( V_10 , V_572 . V_428 , V_573 ) ;
F_106 ( V_10 ) ;
if ( V_571 . V_68 == V_453 ) {
V_571 . V_68 = V_470 ;
if ( V_10 -> V_67 . V_341 == V_444 ) {
F_65 ( V_10 , F_66 ( V_341 , V_580 ) ) ;
} else if ( V_572 . V_341 == V_444 ) {
F_40 ( V_35 , L_138 ) ;
V_572 . V_341 = V_534 ;
V_573 = V_534 ;
} else {
if ( F_220 ( V_464 , & V_10 -> V_59 ) )
return false ;
F_46 ( V_570 . V_68 == V_69 ) ;
F_65 ( V_10 , F_66 ( V_68 , V_145 ) ) ;
return false ;
}
}
}
F_21 ( & V_10 -> V_26 ) ;
if ( V_10 -> V_67 . V_6 != V_570 . V_6 )
goto V_27;
F_82 ( V_579 , & V_10 -> V_59 ) ;
V_571 . V_402 = V_572 . V_428 ;
V_571 . V_336 = V_573 ;
V_571 . V_561 = ( V_572 . V_562 | V_572 . V_563 ) ;
if ( ( V_571 . V_68 == V_470 || V_571 . V_68 == V_468 ) && V_571 . V_341 == V_444 )
V_571 . V_341 = V_10 -> V_455 . V_341 ;
V_575 = V_433 + ( V_570 . V_68 < V_470 && V_571 . V_68 >= V_470 ? 0 : V_581 ) ;
if ( V_571 . V_336 == V_461 && F_233 ( V_571 ) && V_571 . V_68 == V_470 && V_570 . V_68 < V_470 &&
F_109 ( V_582 , & V_10 -> V_59 ) ) {
F_22 ( & V_10 -> V_26 ) ;
F_40 ( V_35 , L_139 ) ;
F_234 ( V_10 ) ;
F_235 ( V_10 ) ;
F_82 ( V_582 , & V_10 -> V_59 ) ;
F_65 ( V_10 , F_236 ( V_68 , V_583 , V_584 , 0 ) ) ;
return false ;
}
V_101 = F_223 ( V_10 , V_571 , V_575 , NULL ) ;
V_571 = V_10 -> V_67 ;
F_22 ( & V_10 -> V_26 ) ;
if ( V_101 < V_169 ) {
F_65 ( V_10 , F_66 ( V_68 , V_145 ) ) ;
return false ;
}
if ( V_570 . V_68 > V_69 ) {
if ( V_571 . V_68 > V_470 && V_572 . V_68 <= V_470 &&
V_572 . V_341 != V_444 ) {
F_95 ( V_10 ) ;
F_96 ( V_10 ) ;
}
}
V_10 -> V_30 -> V_460 = 0 ;
F_217 ( V_10 ) ;
return true ;
}
static int F_237 ( struct V_9 * V_10 , enum V_150 V_151 , unsigned int V_44 )
{
struct V_585 * V_255 = & V_10 -> V_103 . V_157 . V_586 ;
F_123 ( V_10 -> V_328 ,
V_10 -> V_67 . V_68 == V_587 ||
V_10 -> V_67 . V_68 == V_577 ||
V_10 -> V_67 . V_68 < V_470 ||
V_10 -> V_67 . V_341 < V_444 ) ;
if ( F_178 ( V_10 , V_444 ) ) {
F_195 ( V_10 , V_437 , F_144 ( V_255 -> V_410 ) ) ;
F_195 ( V_10 , V_411 , 0UL ) ;
F_226 ( V_10 , L_140 ) ;
F_238 ( V_10 , V_465 ) ;
F_106 ( V_10 ) ;
} else
F_40 ( V_35 , L_141 ) ;
return true ;
}
static int
F_239 ( struct V_9 * V_10 , unsigned int V_44 ,
unsigned long * V_588 , struct V_589 * V_590 )
{
unsigned V_591 = F_71 ( T_6 , V_592 , V_590 -> V_593 - V_590 -> V_594 ) ;
unsigned V_595 = V_591 * sizeof( long ) ;
int V_79 ;
if ( V_595 != V_44 ) {
F_40 ( V_35 , L_142 , V_596 , V_595 , V_44 ) ;
return - V_597 ;
}
if ( V_595 == 0 )
return 0 ;
V_79 = F_63 ( V_10 , V_588 , V_595 ) ;
if ( V_79 != V_595 ) {
if ( V_79 >= 0 )
V_79 = - V_597 ;
return V_79 ;
}
F_240 ( V_10 , V_590 -> V_594 , V_591 , V_588 ) ;
V_590 -> V_594 += V_591 ;
V_590 -> V_598 = V_590 -> V_594 * V_599 ;
if ( V_590 -> V_598 > V_590 -> V_600 )
V_590 -> V_598 = V_590 -> V_600 ;
return 1 ;
}
static int
F_241 ( struct V_9 * V_10 ,
struct V_601 * V_255 ,
struct V_589 * V_590 )
{
struct V_602 V_603 ;
T_2 V_604 ;
T_2 V_605 ;
T_2 V_4 ;
unsigned long V_165 = V_590 -> V_598 ;
unsigned long V_19 ;
int V_5 = F_78 ( V_255 -> V_2 . V_200 ) - ( sizeof( * V_255 ) - sizeof( V_255 -> V_2 ) ) ;
int V_606 = F_242 ( V_255 ) ;
int V_607 ;
int V_436 ;
F_243 ( & V_603 , V_255 -> V_608 , V_5 , F_244 ( V_255 ) ) ;
V_436 = F_245 ( & V_603 , & V_604 , 64 ) ;
if ( V_436 < 0 )
return - V_597 ;
for ( V_607 = V_436 ; V_607 > 0 ; V_165 += V_605 , V_606 = ! V_606 ) {
V_436 = F_246 ( & V_605 , V_604 ) ;
if ( V_436 <= 0 )
return - V_597 ;
if ( V_606 ) {
V_19 = V_165 + V_605 - 1 ;
if ( V_19 >= V_590 -> V_600 ) {
F_40 ( V_35 , L_143 , V_19 ) ;
return - V_597 ;
}
F_247 ( V_10 , V_165 , V_19 ) ;
}
if ( V_607 < V_436 ) {
F_40 ( V_35 , L_144 ,
V_607 , V_436 , V_604 ,
( unsigned int ) ( V_603 . V_609 . V_519 - V_255 -> V_608 ) ,
( unsigned int ) V_603 . V_610 ) ;
return - V_597 ;
}
V_604 >>= V_436 ;
V_607 -= V_436 ;
V_436 = F_245 ( & V_603 , & V_4 , 64 - V_607 ) ;
if ( V_436 < 0 )
return - V_597 ;
V_604 |= V_4 << V_607 ;
V_607 += V_436 ;
}
V_590 -> V_598 = V_165 ;
F_248 ( V_590 ) ;
return ( V_165 != V_590 -> V_600 ) ;
}
static int
F_249 ( struct V_9 * V_10 ,
struct V_601 * V_255 ,
struct V_589 * V_590 )
{
if ( F_250 ( V_255 ) == V_611 )
return F_241 ( V_10 , V_255 , V_590 ) ;
F_40 ( V_35 , L_145 , V_255 -> V_612 ) ;
F_65 ( V_10 , F_66 ( V_68 , V_583 ) ) ;
return - V_597 ;
}
void F_251 ( struct V_9 * V_10 ,
const char * V_613 , struct V_589 * V_590 )
{
unsigned V_614 = sizeof( struct V_152 ) *
( ( V_590 -> V_593 + V_592 - 1 ) / V_592 + 1 )
+ V_590 -> V_593 * sizeof( long ) ;
unsigned V_615 = V_590 -> V_616 [ 0 ] + V_590 -> V_616 [ 1 ] ;
unsigned V_199 ;
if ( V_615 == 0 )
return;
if ( V_615 >= V_614 )
return;
V_199 = ( V_615 > V_617 / 1000 ) ? ( V_615 / ( V_614 / 1000 ) )
: ( 1000 * V_615 / V_614 ) ;
if ( V_199 > 1000 )
V_199 = 1000 ;
V_199 = 1000 - V_199 ;
F_64 ( V_35 , L_146
L_147 ,
V_613 ,
V_590 -> V_616 [ 1 ] , V_590 -> V_618 [ 1 ] ,
V_590 -> V_616 [ 0 ] , V_590 -> V_618 [ 0 ] ,
V_615 , V_199 / 10 , V_199 % 10 ) ;
}
static int F_252 ( struct V_9 * V_10 , enum V_150 V_151 , unsigned int V_44 )
{
struct V_589 V_590 ;
void * V_588 ;
int V_79 ;
int V_66 = false ;
struct V_152 * V_153 = & V_10 -> V_103 . V_157 . V_155 . V_156 ;
F_253 ( V_10 , L_148 , V_467 ) ;
V_588 = ( unsigned long * ) F_254 ( V_178 ) ;
if ( ! V_588 ) {
F_40 ( V_35 , L_149 , V_596 ) ;
goto V_82;
}
V_590 = (struct V_589 ) {
. V_600 = F_183 ( V_10 ) ,
. V_593 = F_255 ( V_10 ) ,
} ;
for(; ; ) {
if ( V_151 == V_619 ) {
V_79 = F_239 ( V_10 , V_44 , V_588 , & V_590 ) ;
} else if ( V_151 == V_620 ) {
struct V_601 * V_255 ;
if ( V_44 > V_621 ) {
F_40 ( V_35 , L_150 ) ;
goto V_82;
}
V_255 = V_588 ;
memcpy ( V_255 , V_153 , sizeof( * V_153 ) ) ;
if ( F_63 ( V_10 , V_255 -> V_2 . V_507 , V_44 ) != V_44 )
goto V_82;
if ( V_44 <= ( sizeof( * V_255 ) - sizeof( V_255 -> V_2 ) ) ) {
F_40 ( V_35 , L_151 , V_44 ) ;
goto V_82;
}
V_79 = F_249 ( V_10 , V_255 , & V_590 ) ;
} else {
F_30 ( V_35 , L_152 , V_151 ) ;
goto V_82;
}
V_590 . V_618 [ V_151 == V_619 ] ++ ;
V_590 . V_616 [ V_151 == V_619 ] += sizeof( struct V_152 ) + V_44 ;
if ( V_79 <= 0 ) {
if ( V_79 < 0 )
goto V_82;
break;
}
if ( ! F_98 ( V_10 , & V_151 , & V_44 ) )
goto V_82;
}
F_251 ( V_10 , L_153 , & V_590 ) ;
if ( V_10 -> V_67 . V_68 == V_469 ) {
enum V_431 V_101 ;
V_66 = ! F_256 ( V_10 ) ;
if ( ! V_66 )
goto V_82;
V_101 = F_257 ( V_10 , F_66 ( V_68 , V_587 ) , V_433 ) ;
F_46 ( V_101 == V_169 ) ;
} else if ( V_10 -> V_67 . V_68 != V_468 ) {
F_64 ( V_35 , L_154 ,
F_197 ( V_10 -> V_67 . V_68 ) ) ;
}
V_66 = true ;
V_82:
F_258 ( V_10 ) ;
if ( V_66 && V_10 -> V_67 . V_68 == V_468 )
F_238 ( V_10 , V_296 ) ;
F_259 ( ( unsigned long ) V_588 ) ;
return V_66 ;
}
static int F_260 ( struct V_9 * V_10 , enum V_150 V_151 , unsigned int V_44 )
{
static char V_622 [ 128 ] ;
int V_58 , V_595 , V_199 ;
F_30 ( V_35 , L_155 ,
V_151 , V_44 ) ;
V_58 = V_44 ;
while ( V_58 > 0 ) {
V_595 = F_71 ( int , V_58 , sizeof( V_622 ) ) ;
V_199 = F_63 ( V_10 , V_622 , V_595 ) ;
F_128 (r <= 0 ) break;
V_58 -= V_199 ;
}
return V_58 == 0 ;
}
static int F_261 ( struct V_9 * V_10 , enum V_150 V_151 , unsigned int V_44 )
{
F_262 ( V_10 -> V_103 . V_75 ) ;
return true ;
}
static int F_263 ( struct V_9 * V_10 , enum V_150 V_151 , unsigned int V_44 )
{
struct V_623 * V_255 = & V_10 -> V_103 . V_157 . V_624 ;
switch ( V_10 -> V_67 . V_68 ) {
case V_587 :
case V_469 :
case V_577 :
break;
default:
F_40 ( V_35 , L_156 ,
F_197 ( V_10 -> V_67 . V_68 ) ) ;
}
F_167 ( V_10 , F_144 ( V_255 -> V_43 ) , F_101 ( V_255 -> V_375 ) ) ;
return true ;
}
static void F_264 ( struct V_9 * V_10 )
{
union V_198 * V_155 = & V_10 -> V_103 . V_157 . V_155 ;
unsigned int V_197 ;
enum V_150 V_151 ;
T_6 V_625 ;
int V_101 ;
while ( F_87 ( & V_10 -> V_175 ) == V_626 ) {
F_265 ( V_10 ) ;
if ( ! F_98 ( V_10 , & V_151 , & V_197 ) )
goto V_627;
if ( F_99 ( V_151 >= V_628 || ! V_629 [ V_151 ] . V_630 ) ) {
F_40 ( V_35 , L_157 , V_151 , V_197 ) ;
goto V_627;
}
V_625 = V_629 [ V_151 ] . V_631 - sizeof( union V_198 ) ;
if ( V_197 - V_625 > 0 && ! V_629 [ V_151 ] . V_632 ) {
F_40 ( V_35 , L_158 , F_181 ( V_151 ) , V_197 ) ;
goto V_627;
}
if ( V_625 ) {
V_101 = F_63 ( V_10 , & V_155 -> V_156 . V_507 , V_625 ) ;
if ( F_99 ( V_101 != V_625 ) ) {
if ( ! F_29 ( V_34 ) )
F_30 ( V_35 , L_159 , V_101 ) ;
goto V_627;
}
}
V_101 = V_629 [ V_151 ] . V_630 ( V_10 , V_151 , V_197 - V_625 ) ;
if ( F_99 ( ! V_101 ) ) {
F_40 ( V_35 , L_160 ,
F_181 ( V_151 ) , V_197 ) ;
goto V_627;
}
}
if ( 0 ) {
V_627:
F_65 ( V_10 , F_66 ( V_68 , V_583 ) ) ;
}
F_217 ( V_10 ) ;
}
void F_266 ( struct V_9 * V_10 )
{
struct V_633 V_634 ;
V_634 . V_22 . V_71 = V_635 ;
F_267 ( & V_634 . V_636 ) ;
F_268 ( & V_10 -> V_103 . V_637 , & V_634 . V_22 ) ;
F_269 ( & V_634 . V_636 ) ;
}
void F_270 ( struct V_9 * V_10 )
{
struct V_320 * V_153 ;
F_21 ( & V_10 -> V_26 ) ;
if ( ! V_10 -> V_324 || V_10 -> V_67 . V_68 != V_638 ) {
F_22 ( & V_10 -> V_26 ) ;
return;
}
for ( V_153 = V_10 -> V_323 ; V_153 < V_10 -> V_323 + V_10 -> V_639 ; V_153 ++ )
if ( V_153 -> V_322 )
F_40 ( V_35 , L_161 ,
( int ) ( V_153 - V_10 -> V_323 ) , V_153 -> V_322 ) ;
F_45 ( V_10 -> V_323 ) ;
V_10 -> V_323 = NULL ;
V_10 -> V_639 = 0 ;
for ( V_153 = V_10 -> V_324 ; V_153 < V_10 -> V_324 + V_10 -> V_640 ; V_153 ++ )
if ( V_153 -> V_322 )
F_40 ( V_35 , L_162 ,
( int ) ( V_153 - V_10 -> V_324 ) , V_153 -> V_322 ) ;
F_45 ( V_10 -> V_324 ) ;
V_10 -> V_324 = NULL ;
V_10 -> V_640 = 0 ;
F_22 ( & V_10 -> V_26 ) ;
}
static void F_271 ( struct V_9 * V_10 )
{
enum V_641 V_642 ;
union V_554 V_570 , V_571 ;
int V_101 = V_643 ;
unsigned int V_6 ;
if ( V_10 -> V_67 . V_68 == V_638 )
return;
F_272 ( & V_10 -> V_187 ) ;
F_273 ( V_10 ) ;
F_21 ( & V_10 -> V_26 ) ;
F_52 ( V_10 , & V_10 -> V_257 ) ;
F_52 ( V_10 , & V_10 -> V_284 ) ;
F_52 ( V_10 , & V_10 -> V_404 ) ;
F_22 ( & V_10 -> V_26 ) ;
F_274 ( V_10 ) ;
V_10 -> V_399 = 0 ;
V_10 -> V_366 = 0 ;
F_42 ( & V_10 -> V_644 , 0 ) ;
F_36 ( & V_10 -> V_328 ) ;
F_275 ( & V_10 -> V_196 ) ;
F_276 ( & V_10 -> V_645 ) ;
F_277 ( ( unsigned long ) V_10 ) ;
F_266 ( V_10 ) ;
F_50 ( V_10 ) ;
F_45 ( V_10 -> V_412 ) ;
V_10 -> V_412 = NULL ;
if ( ! F_233 ( V_10 -> V_67 ) )
F_234 ( V_10 ) ;
F_64 ( V_35 , L_163 ) ;
F_217 ( V_10 ) ;
V_642 = V_646 ;
if ( F_103 ( V_10 ) ) {
V_642 = V_10 -> V_205 -> V_234 . V_647 ;
F_106 ( V_10 ) ;
}
if ( V_10 -> V_67 . V_428 == V_403 && V_642 >= V_648 && V_10 -> V_67 . V_336 >= V_649 )
F_278 ( V_10 ) ;
F_21 ( & V_10 -> V_26 ) ;
V_570 = V_10 -> V_67 ;
if ( V_570 . V_68 >= V_650 ) {
V_571 = V_570 ;
V_571 . V_68 = V_650 ;
V_101 = F_223 ( V_10 , V_571 , V_433 , NULL ) ;
}
F_22 ( & V_10 -> V_26 ) ;
if ( V_570 . V_68 == V_145 ) {
F_123 ( V_10 -> V_651 , F_27 ( & V_10 -> V_652 ) == 0 ) ;
F_207 ( V_10 -> V_189 ) ;
V_10 -> V_189 = NULL ;
F_45 ( V_10 -> V_30 ) ;
V_10 -> V_30 = NULL ;
F_81 ( V_10 , F_66 ( V_68 , V_638 ) ) ;
}
F_123 ( V_10 -> V_328 , ! F_109 ( V_653 , & V_10 -> V_59 ) ) ;
V_6 = F_48 ( V_10 , & V_10 -> V_65 ) ;
if ( V_6 )
F_64 ( V_35 , L_164 , V_6 ) ;
V_6 = F_27 ( & V_10 -> V_38 ) ;
if ( V_6 )
F_64 ( V_35 , L_165 , V_6 ) ;
V_6 = F_27 ( & V_10 -> V_29 ) ;
if ( V_6 )
F_64 ( V_35 , L_166 , V_6 ) ;
F_46 ( F_53 ( & V_10 -> V_404 ) ) ;
F_46 ( F_53 ( & V_10 -> V_257 ) ) ;
F_46 ( F_53 ( & V_10 -> V_284 ) ) ;
F_46 ( F_53 ( & V_10 -> V_70 ) ) ;
F_42 ( & V_10 -> V_224 -> V_213 , 0 ) ;
F_46 ( F_53 ( & V_10 -> V_224 -> V_23 ) ) ;
}
static int F_279 ( struct V_9 * V_10 )
{
struct V_654 * V_255 = & V_10 -> V_103 . V_154 . V_655 ;
int V_66 ;
if ( F_280 ( & V_10 -> V_103 . V_656 ) ) {
F_40 ( V_35 , L_167 ) ;
return 0 ;
}
if ( V_10 -> V_103 . V_75 == NULL ) {
F_281 ( & V_10 -> V_103 . V_656 ) ;
return 0 ;
}
memset ( V_255 , 0 , sizeof( * V_255 ) ) ;
V_255 -> V_657 = F_282 ( V_658 ) ;
V_255 -> V_659 = F_282 ( V_660 ) ;
V_66 = F_76 ( V_10 , V_10 -> V_103 . V_75 , V_661 ,
(struct V_152 * ) V_255 , sizeof( * V_255 ) , 0 ) ;
F_281 ( & V_10 -> V_103 . V_656 ) ;
return V_66 ;
}
static int F_89 ( struct V_9 * V_10 )
{
struct V_654 * V_255 = & V_10 -> V_103 . V_157 . V_655 ;
const int V_273 = sizeof( struct V_654 ) - sizeof( struct V_152 ) ;
unsigned int V_200 ;
enum V_150 V_151 ;
int V_101 ;
V_101 = F_279 ( V_10 ) ;
if ( ! V_101 )
return 0 ;
V_101 = F_98 ( V_10 , & V_151 , & V_200 ) ;
if ( ! V_101 )
return 0 ;
if ( V_151 != V_661 ) {
F_40 ( V_35 , L_168 ,
F_181 ( V_151 ) , V_151 ) ;
return - 1 ;
}
if ( V_200 != V_273 ) {
F_40 ( V_35 , L_169 ,
V_273 , V_200 ) ;
return - 1 ;
}
V_101 = F_63 ( V_10 , & V_255 -> V_2 . V_507 , V_273 ) ;
if ( V_101 != V_273 ) {
if ( ! F_29 ( V_34 ) )
F_30 ( V_35 , L_170 , V_101 ) ;
return 0 ;
}
V_255 -> V_657 = F_101 ( V_255 -> V_657 ) ;
V_255 -> V_659 = F_101 ( V_255 -> V_659 ) ;
if ( V_255 -> V_659 == 0 )
V_255 -> V_659 = V_255 -> V_657 ;
if ( V_660 < V_255 -> V_657 ||
V_658 > V_255 -> V_659 )
goto V_662;
V_10 -> V_265 = F_71 ( int , V_660 , V_255 -> V_659 ) ;
F_64 ( V_35 , L_171
L_172 , V_10 -> V_265 ) ;
return 1 ;
V_662:
F_40 ( V_35 , L_173
L_174 ,
V_658 , V_660 ,
V_255 -> V_657 , V_255 -> V_659 ) ;
return - 1 ;
}
static int F_90 ( struct V_9 * V_10 )
{
F_40 ( V_35 , L_175 ) ;
F_40 ( V_35 , L_176 ) ;
return - 1 ;
}
static int F_90 ( struct V_9 * V_10 )
{
char V_663 [ V_664 ] ;
struct V_665 V_666 ;
char * V_667 = NULL ;
char * V_668 = NULL ;
char * V_669 = NULL ;
unsigned int V_670 = strlen ( V_10 -> V_30 -> V_671 ) ;
unsigned int V_672 ;
struct V_673 V_674 ;
enum V_150 V_151 ;
unsigned int V_200 ;
int V_101 ;
V_674 . V_492 = V_10 -> V_189 ;
V_674 . V_59 = 0 ;
V_101 = F_283 ( V_10 -> V_189 ,
( V_675 * ) V_10 -> V_30 -> V_671 , V_670 ) ;
if ( V_101 ) {
F_40 ( V_35 , L_177 , V_101 ) ;
V_101 = - 1 ;
goto V_53;
}
F_284 ( V_663 , V_664 ) ;
V_101 = F_285 ( V_10 , V_676 , V_663 , V_664 ) ;
if ( ! V_101 )
goto V_53;
V_101 = F_98 ( V_10 , & V_151 , & V_200 ) ;
if ( ! V_101 )
goto V_53;
if ( V_151 != V_676 ) {
F_40 ( V_35 , L_178 ,
F_181 ( V_151 ) , V_151 ) ;
V_101 = 0 ;
goto V_53;
}
if ( V_200 > V_664 * 2 ) {
F_40 ( V_35 , L_179 ) ;
V_101 = - 1 ;
goto V_53;
}
V_669 = F_122 ( V_200 , V_178 ) ;
if ( V_669 == NULL ) {
F_40 ( V_35 , L_180 ) ;
V_101 = - 1 ;
goto V_53;
}
V_101 = F_63 ( V_10 , V_669 , V_200 ) ;
if ( V_101 != V_200 ) {
if ( ! F_29 ( V_34 ) )
F_30 ( V_35 , L_181 , V_101 ) ;
V_101 = 0 ;
goto V_53;
}
V_672 = F_127 ( V_10 -> V_189 ) ;
V_667 = F_122 ( V_672 , V_178 ) ;
if ( V_667 == NULL ) {
F_40 ( V_35 , L_182 ) ;
V_101 = - 1 ;
goto V_53;
}
F_286 ( & V_666 , 1 ) ;
F_287 ( & V_666 , V_669 , V_200 ) ;
V_101 = F_288 ( & V_674 , & V_666 , V_666 . V_200 , V_667 ) ;
if ( V_101 ) {
F_40 ( V_35 , L_183 , V_101 ) ;
V_101 = - 1 ;
goto V_53;
}
V_101 = F_285 ( V_10 , V_677 , V_667 , V_672 ) ;
if ( ! V_101 )
goto V_53;
V_101 = F_98 ( V_10 , & V_151 , & V_200 ) ;
if ( ! V_101 )
goto V_53;
if ( V_151 != V_677 ) {
F_40 ( V_35 , L_184 ,
F_181 ( V_151 ) , V_151 ) ;
V_101 = 0 ;
goto V_53;
}
if ( V_200 != V_672 ) {
F_40 ( V_35 , L_185 ) ;
V_101 = 0 ;
goto V_53;
}
V_101 = F_63 ( V_10 , V_667 , V_672 ) ;
if ( V_101 != V_672 ) {
if ( ! F_29 ( V_34 ) )
F_30 ( V_35 , L_186 , V_101 ) ;
V_101 = 0 ;
goto V_53;
}
V_668 = F_122 ( V_672 , V_178 ) ;
if ( V_668 == NULL ) {
F_40 ( V_35 , L_187 ) ;
V_101 = - 1 ;
goto V_53;
}
F_287 ( & V_666 , V_663 , V_664 ) ;
V_101 = F_288 ( & V_674 , & V_666 , V_666 . V_200 , V_668 ) ;
if ( V_101 ) {
F_40 ( V_35 , L_183 , V_101 ) ;
V_101 = - 1 ;
goto V_53;
}
V_101 = ! memcmp ( V_667 , V_668 , V_672 ) ;
if ( V_101 )
F_64 ( V_35 , L_188 ,
V_672 , V_10 -> V_30 -> V_678 ) ;
else
V_101 = - 1 ;
V_53:
F_45 ( V_669 ) ;
F_45 ( V_667 ) ;
F_45 ( V_668 ) ;
return V_101 ;
}
int F_289 ( struct V_679 * V_680 )
{
struct V_9 * V_10 = V_680 -> V_10 ;
unsigned int V_681 = F_290 ( V_10 ) ;
int V_153 ;
sprintf ( V_34 -> V_329 , L_189 , V_681 ) ;
F_64 ( V_35 , L_190 ) ;
do {
V_153 = F_80 ( V_10 ) ;
if ( V_153 == 0 ) {
F_271 ( V_10 ) ;
F_83 ( V_125 ) ;
}
if ( V_153 == - 1 ) {
F_30 ( V_35 , L_191 ) ;
F_65 ( V_10 , F_66 ( V_68 , V_145 ) ) ;
}
} while ( V_153 == 0 );
if ( V_153 > 0 ) {
if ( F_69 ( V_10 ) ) {
F_264 ( V_10 ) ;
F_72 ( V_10 ) ;
}
}
F_271 ( V_10 ) ;
F_64 ( V_35 , L_192 ) ;
return 0 ;
}
static int F_291 ( struct V_9 * V_10 , struct V_152 * V_153 )
{
struct V_682 * V_255 = (struct V_682 * ) V_153 ;
int V_683 = F_101 ( V_255 -> V_683 ) ;
if ( V_683 >= V_169 ) {
F_84 ( V_684 , & V_10 -> V_59 ) ;
} else {
F_84 ( V_685 , & V_10 -> V_59 ) ;
F_40 ( V_35 , L_193 ,
F_292 ( V_683 ) , V_683 ) ;
}
F_36 ( & V_10 -> V_686 ) ;
return true ;
}
static int F_293 ( struct V_9 * V_10 , struct V_152 * V_153 )
{
return F_294 ( V_10 ) ;
}
static int F_295 ( struct V_9 * V_10 , struct V_152 * V_153 )
{
V_10 -> V_184 . V_75 -> V_78 -> V_122 = V_10 -> V_30 -> V_183 * V_125 ;
if ( ! F_296 ( V_687 , & V_10 -> V_59 ) )
F_36 ( & V_10 -> V_328 ) ;
return true ;
}
static int F_297 ( struct V_9 * V_10 , struct V_152 * V_153 )
{
struct V_688 * V_255 = (struct V_688 * ) V_153 ;
T_3 V_43 = F_144 ( V_255 -> V_43 ) ;
int V_375 = F_101 ( V_255 -> V_375 ) ;
F_46 ( V_10 -> V_265 >= 89 ) ;
F_298 ( V_10 , F_101 ( V_255 -> V_316 ) ) ;
if ( F_103 ( V_10 ) ) {
F_299 ( V_10 , V_43 ) ;
F_138 ( V_10 , V_43 , V_375 ) ;
V_10 -> V_689 += ( V_375 >> V_690 ) ;
F_106 ( V_10 ) ;
}
F_142 ( V_10 ) ;
F_33 ( V_375 >> 9 , & V_10 -> V_291 ) ;
return true ;
}
static struct V_269 * F_300 ( struct V_9 * V_10 ,
T_2 V_42 , T_3 V_43 )
{
struct V_320 * V_321 = F_162 ( V_10 , V_43 ) ;
struct V_319 * V_3 ;
struct V_269 * V_270 ;
F_163 (req, n, slot, collision) {
if ( ( unsigned long ) V_270 == ( unsigned long ) V_42 ) {
if ( V_270 -> V_43 != V_43 ) {
F_40 ( V_35 , L_194
L_195 , V_270 ,
( unsigned long long ) V_270 -> V_43 ,
( unsigned long long ) V_43 ) ;
break;
}
return V_270 ;
}
}
return NULL ;
}
static int F_301 ( struct V_9 * V_10 ,
T_2 V_42 , T_3 V_43 , T_9 V_691 ,
const char * V_692 , enum V_693 V_74 )
{
struct V_269 * V_270 ;
struct V_694 V_695 ;
F_21 ( & V_10 -> V_26 ) ;
V_270 = V_691 ( V_10 , V_42 , V_43 ) ;
if ( F_99 ( ! V_270 ) ) {
F_22 ( & V_10 -> V_26 ) ;
F_40 ( V_35 , L_196 , V_692 ,
( void * ) ( unsigned long ) V_42 , ( unsigned long long ) V_43 ) ;
return false ;
}
F_302 ( V_270 , V_74 , & V_695 ) ;
F_22 ( & V_10 -> V_26 ) ;
if ( V_695 . V_239 )
F_303 ( V_10 , & V_695 ) ;
return true ;
}
static int F_304 ( struct V_9 * V_10 , struct V_152 * V_153 )
{
struct V_688 * V_255 = (struct V_688 * ) V_153 ;
T_3 V_43 = F_144 ( V_255 -> V_43 ) ;
int V_375 = F_101 ( V_255 -> V_375 ) ;
enum V_693 V_74 ;
F_298 ( V_10 , F_101 ( V_255 -> V_316 ) ) ;
if ( F_305 ( V_255 -> V_60 ) ) {
F_138 ( V_10 , V_43 , V_375 ) ;
F_142 ( V_10 ) ;
return true ;
}
switch ( F_78 ( V_153 -> V_161 ) ) {
case V_281 :
F_46 ( V_10 -> V_30 -> V_294 == V_295 ) ;
V_74 = V_696 ;
break;
case V_299 :
F_46 ( V_10 -> V_30 -> V_294 == V_295 ) ;
V_74 = V_697 ;
break;
case V_334 :
F_46 ( V_10 -> V_30 -> V_294 == V_333 ) ;
V_74 = V_698 ;
break;
case V_301 :
F_46 ( V_10 -> V_30 -> V_294 == V_295 ) ;
V_74 = V_699 ;
break;
default:
F_46 ( 0 ) ;
return false ;
}
return F_301 ( V_10 , V_255 -> V_60 , V_43 ,
F_300 , V_596 , V_74 ) ;
}
static int F_306 ( struct V_9 * V_10 , struct V_152 * V_153 )
{
struct V_688 * V_255 = (struct V_688 * ) V_153 ;
T_3 V_43 = F_144 ( V_255 -> V_43 ) ;
int V_58 = F_101 ( V_255 -> V_375 ) ;
struct V_269 * V_270 ;
struct V_694 V_695 ;
F_298 ( V_10 , F_101 ( V_255 -> V_316 ) ) ;
if ( F_305 ( V_255 -> V_60 ) ) {
F_142 ( V_10 ) ;
F_140 ( V_10 , V_43 , V_58 ) ;
return true ;
}
F_21 ( & V_10 -> V_26 ) ;
V_270 = F_300 ( V_10 , V_255 -> V_60 , V_43 ) ;
if ( ! V_270 ) {
F_22 ( & V_10 -> V_26 ) ;
if ( V_10 -> V_30 -> V_294 == V_335 ||
V_10 -> V_30 -> V_294 == V_333 ) {
F_167 ( V_10 , V_43 , V_58 ) ;
return true ;
} else {
F_40 ( V_35 , L_196 , V_596 ,
( void * ) ( unsigned long ) V_255 -> V_60 , ( unsigned long long ) V_43 ) ;
return false ;
}
}
F_302 ( V_270 , V_700 , & V_695 ) ;
F_22 ( & V_10 -> V_26 ) ;
if ( V_695 . V_239 )
F_303 ( V_10 , & V_695 ) ;
return true ;
}
static int F_307 ( struct V_9 * V_10 , struct V_152 * V_153 )
{
struct V_688 * V_255 = (struct V_688 * ) V_153 ;
T_3 V_43 = F_144 ( V_255 -> V_43 ) ;
F_298 ( V_10 , F_101 ( V_255 -> V_316 ) ) ;
F_40 ( V_35 , L_197 ,
( unsigned long long ) V_43 , F_101 ( V_255 -> V_375 ) ) ;
return F_301 ( V_10 , V_255 -> V_60 , V_43 ,
F_145 , V_596 , V_700 ) ;
}
static int F_308 ( struct V_9 * V_10 , struct V_152 * V_153 )
{
T_3 V_43 ;
int V_58 ;
struct V_688 * V_255 = (struct V_688 * ) V_153 ;
V_43 = F_144 ( V_255 -> V_43 ) ;
V_58 = F_101 ( V_255 -> V_375 ) ;
F_298 ( V_10 , F_101 ( V_255 -> V_316 ) ) ;
F_142 ( V_10 ) ;
if ( F_178 ( V_10 , V_580 ) ) {
F_299 ( V_10 , V_43 ) ;
switch ( F_78 ( V_153 -> V_161 ) ) {
case V_382 :
F_140 ( V_10 , V_43 , V_58 ) ;
case V_701 :
break;
default:
F_46 ( 0 ) ;
F_106 ( V_10 ) ;
return false ;
}
F_106 ( V_10 ) ;
}
return true ;
}
static int F_309 ( struct V_9 * V_10 , struct V_152 * V_153 )
{
struct V_702 * V_255 = (struct V_702 * ) V_153 ;
F_310 ( V_10 , V_255 -> V_256 , F_101 ( V_255 -> V_703 ) ) ;
if ( V_10 -> V_67 . V_68 == V_576 &&
F_27 ( & V_10 -> V_704 ) == 0 &&
! F_296 ( V_705 , & V_10 -> V_224 -> V_59 ) ) {
V_10 -> V_706 . V_707 = V_186 + V_125 ;
F_311 ( & V_10 -> V_706 ) ;
}
return true ;
}
static int F_312 ( struct V_9 * V_10 , struct V_152 * V_153 )
{
struct V_688 * V_255 = (struct V_688 * ) V_153 ;
struct V_278 * V_22 ;
T_3 V_43 ;
int V_58 ;
V_43 = F_144 ( V_255 -> V_43 ) ;
V_58 = F_101 ( V_255 -> V_375 ) ;
F_298 ( V_10 , F_101 ( V_255 -> V_316 ) ) ;
if ( F_144 ( V_255 -> V_60 ) == V_708 )
F_313 ( V_10 , V_43 , V_58 ) ;
else
F_314 ( V_10 ) ;
if ( ! F_103 ( V_10 ) )
return true ;
F_299 ( V_10 , V_43 ) ;
F_142 ( V_10 ) ;
-- V_10 -> V_365 ;
if ( ( V_10 -> V_365 & 0x200 ) == 0x200 )
F_315 ( V_10 , V_10 -> V_365 ) ;
if ( V_10 -> V_365 == 0 ) {
V_22 = F_122 ( sizeof( * V_22 ) , V_178 ) ;
if ( V_22 ) {
V_22 -> V_71 = V_709 ;
F_316 ( & V_10 -> V_103 . V_637 , V_22 ) ;
} else {
F_40 ( V_35 , L_198 ) ;
F_314 ( V_10 ) ;
F_232 ( V_10 ) ;
}
}
F_106 ( V_10 ) ;
return true ;
}
static int F_317 ( struct V_9 * V_10 , struct V_152 * V_153 )
{
return true ;
}
static struct V_710 * F_318 ( int V_151 )
{
static struct V_710 V_711 [] = {
[ V_712 ] = { sizeof( struct V_152 ) , F_293 } ,
[ V_713 ] = { sizeof( struct V_152 ) , F_295 } ,
[ V_334 ] = { sizeof( struct V_688 ) , F_304 } ,
[ V_299 ] = { sizeof( struct V_688 ) , F_304 } ,
[ V_281 ] = { sizeof( struct V_688 ) , F_304 } ,
[ V_301 ] = { sizeof( struct V_688 ) , F_304 } ,
[ V_282 ] = { sizeof( struct V_688 ) , F_306 } ,
[ V_378 ] = { sizeof( struct V_688 ) , F_307 } ,
[ V_382 ] = { sizeof( struct V_688 ) , F_308 } ,
[ V_384 ] = { sizeof( struct V_688 ) , F_312 } ,
[ V_714 ] = { sizeof( struct V_702 ) , F_309 } ,
[ V_715 ] = { sizeof( struct V_682 ) , F_291 } ,
[ V_716 ] = { sizeof( struct V_688 ) , F_297 } ,
[ V_717 ] = { sizeof( struct V_718 ) , F_317 } ,
[ V_701 ] = { sizeof( struct V_688 ) , F_308 } ,
[ V_628 ] = { 0 , NULL } ,
} ;
if ( V_151 > V_628 || V_711 [ V_151 ] . V_719 == NULL )
return NULL ;
return & V_711 [ V_151 ] ;
}
int F_319 ( struct V_679 * V_680 )
{
struct V_9 * V_10 = V_680 -> V_10 ;
struct V_152 * V_153 = & V_10 -> V_184 . V_157 . V_155 . V_156 ;
struct V_710 * V_151 = NULL ;
int V_101 , V_5 ;
void * V_87 = V_153 ;
int V_720 = 0 ;
int V_273 = sizeof( struct V_152 ) ;
int V_721 ;
int V_722 = 0 ;
sprintf ( V_34 -> V_329 , L_199 , F_290 ( V_10 ) ) ;
V_34 -> V_723 = V_724 ;
V_34 -> V_725 = 2 ;
while ( F_87 ( V_680 ) == V_626 ) {
F_265 ( V_10 ) ;
if ( F_220 ( V_726 , & V_10 -> V_59 ) ) {
F_128 (!drbd_send_ping(mdev)) goto V_727;
V_10 -> V_184 . V_75 -> V_78 -> V_122 =
V_10 -> V_30 -> V_174 * V_125 / 10 ;
V_722 = 1 ;
}
if ( ! V_10 -> V_30 -> V_728 &&
3 < F_27 ( & V_10 -> V_729 ) )
F_320 ( V_10 -> V_184 . V_75 ) ;
while ( 1 ) {
F_82 ( V_730 , & V_10 -> V_59 ) ;
F_85 ( V_34 ) ;
if ( ! F_50 ( V_10 ) )
goto V_727;
F_84 ( V_730 , & V_10 -> V_59 ) ;
F_21 ( & V_10 -> V_26 ) ;
V_721 = F_53 ( & V_10 -> V_70 ) ;
F_22 ( & V_10 -> V_26 ) ;
if ( V_721 )
break;
}
if ( ! V_10 -> V_30 -> V_728 )
F_321 ( V_10 -> V_184 . V_75 ) ;
if ( F_29 ( V_34 ) )
continue;
V_101 = F_59 ( V_10 , V_10 -> V_184 . V_75 ,
V_87 , V_273 - V_720 , 0 ) ;
F_82 ( V_730 , & V_10 -> V_59 ) ;
F_85 ( V_34 ) ;
if ( F_100 ( V_101 > 0 ) ) {
V_720 += V_101 ;
V_87 += V_101 ;
} else if ( V_101 == 0 ) {
F_40 ( V_35 , L_200 ) ;
goto V_727;
} else if ( V_101 == - V_138 ) {
if ( F_322 ( V_10 -> V_185 ,
V_186 - V_10 -> V_184 . V_75 -> V_78 -> V_122 ) )
continue;
if ( V_722 ) {
F_40 ( V_35 , L_201 ) ;
goto V_727;
}
F_84 ( V_726 , & V_10 -> V_59 ) ;
continue;
} else if ( V_101 == - V_140 ) {
continue;
} else {
F_40 ( V_35 , L_10 , V_101 ) ;
goto V_727;
}
if ( V_720 == V_273 && V_151 == NULL ) {
if ( F_99 ( V_153 -> V_159 != V_160 ) ) {
F_40 ( V_35 , L_202 ,
F_101 ( V_153 -> V_159 ) ,
F_78 ( V_153 -> V_161 ) ,
F_78 ( V_153 -> V_200 ) ) ;
goto V_727;
}
V_151 = F_318 ( F_78 ( V_153 -> V_161 ) ) ;
V_5 = F_78 ( V_153 -> V_200 ) ;
if ( F_99 ( V_151 == NULL ) ) {
F_40 ( V_35 , L_203 ,
F_101 ( V_153 -> V_159 ) ,
F_78 ( V_153 -> V_161 ) ,
F_78 ( V_153 -> V_200 ) ) ;
goto V_486;
}
V_273 = V_151 -> V_631 ;
F_128 (len != expect-sizeof(struct p_header80))
goto V_727;
}
if ( V_720 == V_273 ) {
V_10 -> V_185 = V_186 ;
F_46 ( V_151 != NULL ) ;
if ( ! V_151 -> V_719 ( V_10 , V_153 ) )
goto V_727;
if ( V_151 == F_318 ( V_713 ) )
V_722 = 0 ;
V_87 = V_153 ;
V_720 = 0 ;
V_273 = sizeof( struct V_152 ) ;
V_151 = NULL ;
}
}
if ( 0 ) {
V_727:
F_65 ( V_10 , F_66 ( V_68 , V_731 ) ) ;
F_217 ( V_10 ) ;
}
if ( 0 ) {
V_486:
F_65 ( V_10 , F_66 ( V_68 , V_145 ) ) ;
F_217 ( V_10 ) ;
}
F_82 ( V_730 , & V_10 -> V_59 ) ;
F_46 ( V_10 -> V_67 . V_68 < V_470 ) ;
F_64 ( V_35 , L_204 ) ;
return 0 ;
}
