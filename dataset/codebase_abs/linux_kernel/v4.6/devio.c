static int F_1 ( unsigned V_1 )
{
unsigned V_2 ;
V_2 = F_2 ( V_3 ) ;
if ( V_2 == 0 || V_2 > ( V_4 >> 20 ) )
V_2 = V_4 ;
else
V_2 <<= 20 ;
F_3 ( V_1 , & V_5 ) ;
if ( F_4 ( & V_5 ) <= V_2 )
return 0 ;
F_5 ( V_1 , & V_5 ) ;
return - V_6 ;
}
static void F_6 ( unsigned V_1 )
{
F_5 ( V_1 , & V_5 ) ;
}
static int F_7 ( struct V_7 * V_8 )
{
return ( ! F_8 ( & V_8 -> V_9 ) &&
V_8 -> V_10 -> V_11 != V_12 ) ;
}
static void F_9 ( struct V_13 * V_14 , int * V_15 )
{
struct V_7 * V_8 = V_14 -> V_8 ;
unsigned long V_16 ;
F_10 ( & V_8 -> V_17 , V_16 ) ;
-- * V_15 ;
if ( V_14 -> V_18 == 0 && V_14 -> V_19 == 0 ) {
F_11 ( & V_14 -> V_20 ) ;
F_12 ( & V_8 -> V_17 , V_16 ) ;
F_13 ( V_8 -> V_10 , V_14 -> V_21 , V_14 -> V_22 ,
V_14 -> V_23 ) ;
F_6 (
V_14 -> V_21 + sizeof( struct V_13 ) ) ;
F_14 ( V_14 ) ;
} else {
F_12 ( & V_8 -> V_17 , V_16 ) ;
}
}
static void F_15 ( struct V_24 * V_25 )
{
struct V_13 * V_14 = V_25 -> V_26 ;
unsigned long V_16 ;
F_10 ( & V_14 -> V_8 -> V_17 , V_16 ) ;
++ V_14 -> V_19 ;
F_12 ( & V_14 -> V_8 -> V_17 , V_16 ) ;
}
static void F_16 ( struct V_24 * V_25 )
{
struct V_13 * V_14 = V_25 -> V_26 ;
F_9 ( V_14 , & V_14 -> V_19 ) ;
}
static int F_17 ( struct V_27 * V_27 , struct V_24 * V_25 )
{
struct V_13 * V_14 = NULL ;
struct V_7 * V_8 = V_27 -> V_28 ;
T_1 V_21 = V_25 -> V_29 - V_25 -> V_30 ;
void * V_22 ;
unsigned long V_16 ;
T_2 V_23 ;
int V_31 ;
V_31 = F_1 ( V_21 + sizeof( struct V_13 ) ) ;
if ( V_31 )
goto error;
V_14 = F_18 ( sizeof( struct V_13 ) , V_32 ) ;
if ( ! V_14 ) {
V_31 = - V_6 ;
goto V_33;
}
V_22 = F_19 ( V_8 -> V_10 , V_21 , V_34 , & V_23 ) ;
if ( ! V_22 ) {
V_31 = - V_6 ;
goto V_35;
}
memset ( V_22 , 0 , V_21 ) ;
V_14 -> V_22 = V_22 ;
V_14 -> V_23 = V_23 ;
V_14 -> V_21 = V_21 ;
V_14 -> V_8 = V_8 ;
V_14 -> V_30 = V_25 -> V_30 ;
V_14 -> V_19 = 1 ;
F_20 ( & V_14 -> V_20 ) ;
if ( F_21 ( V_25 , V_25 -> V_30 ,
F_22 ( V_14 -> V_22 ) >> V_36 ,
V_21 , V_25 -> V_37 ) < 0 ) {
F_9 ( V_14 , & V_14 -> V_19 ) ;
return - V_38 ;
}
V_25 -> V_39 |= V_40 ;
V_25 -> V_39 |= ( V_41 | V_42 ) ;
V_25 -> V_43 = & V_44 ;
V_25 -> V_26 = V_14 ;
F_10 ( & V_8 -> V_17 , V_16 ) ;
F_23 ( & V_14 -> V_20 , & V_8 -> V_45 ) ;
F_12 ( & V_8 -> V_17 , V_16 ) ;
return 0 ;
V_35:
F_14 ( V_14 ) ;
V_33:
F_6 ( V_21 + sizeof( struct V_13 ) ) ;
error:
return V_31 ;
}
static T_3 F_24 ( struct V_27 * V_27 , char T_4 * V_46 , T_1 V_47 ,
T_5 * V_48 )
{
struct V_7 * V_8 = V_27 -> V_28 ;
struct V_49 * V_10 = V_8 -> V_10 ;
T_3 V_31 = 0 ;
unsigned V_50 ;
T_5 V_51 ;
int V_52 ;
V_51 = * V_48 ;
F_25 ( V_10 ) ;
if ( ! F_7 ( V_8 ) ) {
V_31 = - V_53 ;
goto V_54;
} else if ( V_51 < 0 ) {
V_31 = - V_55 ;
goto V_54;
}
if ( V_51 < sizeof( struct V_56 ) ) {
struct V_56 V_57 ;
memcpy ( & V_57 , & V_10 -> V_58 , sizeof( V_10 -> V_58 ) ) ;
F_26 ( & V_57 . V_59 ) ;
F_26 ( & V_57 . V_60 ) ;
F_26 ( & V_57 . V_61 ) ;
F_26 ( & V_57 . V_62 ) ;
V_50 = sizeof( struct V_56 ) - V_51 ;
if ( V_50 > V_47 )
V_50 = V_47 ;
if ( F_27 ( V_46 , ( ( char * ) & V_57 ) + V_51 , V_50 ) ) {
V_31 = - V_63 ;
goto V_54;
}
* V_48 += V_50 ;
V_46 += V_50 ;
V_47 -= V_50 ;
V_31 += V_50 ;
}
V_51 = sizeof( struct V_56 ) ;
for ( V_52 = 0 ; V_47 && V_52 < V_10 -> V_58 . V_64 ; V_52 ++ ) {
struct V_65 * V_66 =
(struct V_65 * ) V_10 -> V_67 [ V_52 ] ;
unsigned int V_68 = F_28 ( V_66 -> V_69 ) ;
if ( * V_48 < V_51 + V_68 ) {
unsigned V_70 =
F_28 ( V_10 -> V_66 [ V_52 ] . V_71 . V_69 ) ;
V_50 = V_68 - ( * V_48 - V_51 ) ;
if ( V_50 > V_47 )
V_50 = V_47 ;
if ( V_70 > ( * V_48 - V_51 ) ) {
V_70 -= ( * V_48 - V_51 ) ;
if ( F_27 ( V_46 ,
V_10 -> V_67 [ V_52 ] + ( * V_48 - V_51 ) ,
F_29 ( V_50 , V_70 ) ) ) {
V_31 = - V_63 ;
goto V_54;
}
}
* V_48 += V_50 ;
V_46 += V_50 ;
V_47 -= V_50 ;
V_31 += V_50 ;
}
V_51 += V_68 ;
}
V_54:
F_30 ( V_10 ) ;
return V_31 ;
}
static struct V_72 * F_31 ( unsigned int V_73 )
{
struct V_72 * V_74 ;
V_74 = F_18 ( sizeof( struct V_72 ) , V_32 ) ;
if ( ! V_74 )
return NULL ;
V_74 -> V_75 = F_32 ( V_73 , V_32 ) ;
if ( ! V_74 -> V_75 ) {
F_14 ( V_74 ) ;
return NULL ;
}
return V_74 ;
}
static void F_33 ( struct V_72 * V_74 )
{
int V_52 ;
F_34 ( V_74 -> V_76 ) ;
if ( V_74 -> V_77 )
F_35 ( V_74 -> V_77 ) ;
for ( V_52 = 0 ; V_52 < V_74 -> V_75 -> V_78 ; V_52 ++ ) {
if ( F_36 ( & V_74 -> V_75 -> V_79 [ V_52 ] ) )
F_14 ( F_37 ( & V_74 -> V_75 -> V_79 [ V_52 ] ) ) ;
}
F_14 ( V_74 -> V_75 -> V_79 ) ;
if ( V_74 -> V_14 == NULL )
F_14 ( V_74 -> V_75 -> V_80 ) ;
else
F_9 ( V_74 -> V_14 , & V_74 -> V_14 -> V_18 ) ;
F_14 ( V_74 -> V_75 -> V_81 ) ;
F_38 ( V_74 -> V_75 ) ;
F_6 ( V_74 -> V_82 ) ;
F_14 ( V_74 ) ;
}
static void F_39 ( struct V_72 * V_74 )
{
struct V_7 * V_8 = V_74 -> V_8 ;
unsigned long V_16 ;
F_10 ( & V_8 -> V_17 , V_16 ) ;
F_23 ( & V_74 -> V_83 , & V_8 -> V_84 ) ;
F_12 ( & V_8 -> V_17 , V_16 ) ;
}
static void F_40 ( struct V_72 * V_74 )
{
struct V_7 * V_8 = V_74 -> V_8 ;
unsigned long V_16 ;
F_10 ( & V_8 -> V_17 , V_16 ) ;
F_41 ( & V_74 -> V_83 ) ;
F_12 ( & V_8 -> V_17 , V_16 ) ;
}
static struct V_72 * F_42 ( struct V_7 * V_8 )
{
unsigned long V_16 ;
struct V_72 * V_74 = NULL ;
F_10 ( & V_8 -> V_17 , V_16 ) ;
if ( ! F_8 ( & V_8 -> V_85 ) ) {
V_74 = F_43 ( V_8 -> V_85 . V_86 , struct V_72 ,
V_83 ) ;
F_41 ( & V_74 -> V_83 ) ;
}
F_12 ( & V_8 -> V_17 , V_16 ) ;
return V_74 ;
}
static struct V_72 * F_44 ( struct V_7 * V_8 ,
void T_4 * V_87 )
{
struct V_72 * V_74 ;
F_45 (as, &ps->async_pending, asynclist)
if ( V_74 -> V_87 == V_87 ) {
F_41 ( & V_74 -> V_83 ) ;
return V_74 ;
}
return NULL ;
}
static void F_46 ( struct V_49 * V_88 ,
void T_4 * V_87 , int V_89 , unsigned V_68 ,
int V_90 , enum V_91 V_92 ,
unsigned char * V_93 , unsigned V_94 )
{
static const char * V_95 [] = { L_1 , L_2 , L_3 , L_4 } ;
static const char * V_96 [] = { L_5 , L_6 } ;
int V_97 ;
const char * V_98 , * V_99 ;
if ( ! V_100 )
return;
V_97 = F_47 ( V_89 ) ;
V_98 = V_95 [ F_48 ( V_89 ) ] ;
V_99 = V_96 [ ! ! F_49 ( V_89 ) ] ;
if ( V_87 ) {
if ( V_92 == V_101 )
F_50 ( & V_88 -> V_10 , L_7
L_8 ,
V_87 , V_97 , V_98 , V_99 , V_68 ) ;
else
F_50 ( & V_88 -> V_10 , L_7
L_9 ,
V_87 , V_97 , V_98 , V_99 , V_68 ,
V_90 ) ;
} else {
if ( V_92 == V_101 )
F_50 ( & V_88 -> V_10 , L_10
L_11 ,
V_97 , V_98 , V_99 , V_68 , V_90 ) ;
else
F_50 ( & V_88 -> V_10 , L_12
L_13 ,
V_97 , V_98 , V_99 , V_68 , V_90 ) ;
}
V_94 = F_29 ( V_94 , V_102 ) ;
if ( V_93 && V_94 > 0 ) {
F_51 ( V_103 , L_14 , V_104 , 32 , 1 ,
V_93 , V_94 , 1 ) ;
}
}
static void F_52 ( struct V_75 * V_75 , unsigned V_50 )
{
int V_52 , V_21 ;
V_50 = F_29 ( V_50 , V_102 ) ;
if ( ! V_100 || V_50 == 0 )
return;
if ( V_75 -> V_78 == 0 ) {
F_51 ( V_103 , L_14 , V_104 , 32 , 1 ,
V_75 -> V_80 , V_50 , 1 ) ;
return;
}
for ( V_52 = 0 ; V_52 < V_75 -> V_78 && V_50 ; V_52 ++ ) {
V_21 = ( V_50 > V_105 ) ? V_105 : V_50 ;
F_51 ( V_103 , L_14 , V_104 , 32 , 1 ,
F_37 ( & V_75 -> V_79 [ V_52 ] ) , V_21 , 1 ) ;
V_50 -= V_21 ;
}
}
static int F_53 ( T_6 T_4 * V_106 , struct V_75 * V_75 )
{
unsigned V_52 , V_50 , V_21 ;
if ( V_75 -> V_107 > 0 )
V_50 = V_75 -> V_108 ;
else
V_50 = V_75 -> V_109 ;
if ( V_75 -> V_78 == 0 ) {
if ( F_27 ( V_106 , V_75 -> V_80 , V_50 ) )
return - V_63 ;
return 0 ;
}
for ( V_52 = 0 ; V_52 < V_75 -> V_78 && V_50 ; V_52 ++ ) {
V_21 = ( V_50 > V_105 ) ? V_105 : V_50 ;
if ( F_27 ( V_106 , F_37 ( & V_75 -> V_79 [ V_52 ] ) , V_21 ) )
return - V_63 ;
V_106 += V_21 ;
V_50 -= V_21 ;
}
return 0 ;
}
static void F_54 ( struct V_7 * V_8 , unsigned V_110 )
__releases( V_8 -> V_17 )
__acquires( V_8 -> V_17 )
{
struct V_75 * V_75 ;
struct V_72 * V_74 ;
F_45 (as, &ps->async_pending, asynclist) {
if ( V_74 -> V_110 == V_110 ) {
if ( V_74 -> V_111 != V_112 )
goto V_113;
V_74 -> V_111 = V_114 ;
V_74 -> V_110 = 0 ;
}
}
V_8 -> V_115 |= ( 1 << V_110 ) ;
V_113:
F_45 (as, &ps->async_pending, asynclist) {
if ( V_74 -> V_111 == V_114 ) {
V_74 -> V_111 = 0 ;
V_75 = V_74 -> V_75 ;
F_55 ( V_75 ) ;
F_56 ( & V_8 -> V_17 ) ;
F_57 ( V_75 ) ;
F_58 ( V_75 ) ;
F_59 ( & V_8 -> V_17 ) ;
goto V_113;
}
}
}
static void V_85 ( struct V_75 * V_75 )
{
struct V_72 * V_74 = V_75 -> V_116 ;
struct V_7 * V_8 = V_74 -> V_8 ;
struct V_117 V_118 ;
struct V_76 * V_76 = NULL ;
T_7 V_119 = 0 ;
const struct V_77 * V_77 = NULL ;
int V_120 ;
F_59 ( & V_8 -> V_17 ) ;
F_60 ( & V_74 -> V_83 , & V_8 -> V_85 ) ;
V_74 -> V_121 = V_75 -> V_121 ;
V_120 = V_74 -> V_120 ;
if ( V_120 ) {
memset ( & V_118 , 0 , sizeof( V_118 ) ) ;
V_118 . V_122 = V_74 -> V_120 ;
V_118 . V_123 = V_74 -> V_121 ;
V_118 . V_124 = V_125 ;
V_118 . V_126 = V_74 -> V_87 ;
V_76 = F_61 ( V_74 -> V_76 ) ;
V_77 = F_62 ( V_74 -> V_77 ) ;
V_119 = V_74 -> V_119 ;
}
F_63 ( & V_75 -> V_10 -> V_10 , L_15 ) ;
F_46 ( V_75 -> V_10 , V_74 -> V_87 , V_75 -> V_89 , V_75 -> V_109 ,
V_74 -> V_121 , V_127 , NULL , 0 ) ;
if ( ( V_75 -> V_128 & V_129 ) == V_130 )
F_52 ( V_75 , V_75 -> V_109 ) ;
if ( V_74 -> V_121 < 0 && V_74 -> V_110 && V_74 -> V_121 != - V_131 &&
V_74 -> V_121 != - V_132 )
F_54 ( V_8 , V_74 -> V_110 ) ;
F_56 ( & V_8 -> V_17 ) ;
if ( V_120 ) {
F_64 ( V_118 . V_122 , & V_118 , V_76 , V_77 , V_119 ) ;
F_34 ( V_76 ) ;
F_35 ( V_77 ) ;
}
F_65 ( & V_8 -> V_133 ) ;
}
static void F_66 ( struct V_7 * V_8 , struct V_134 * V_9 )
{
struct V_75 * V_75 ;
struct V_72 * V_74 ;
unsigned long V_16 ;
F_10 ( & V_8 -> V_17 , V_16 ) ;
while ( ! F_8 ( V_9 ) ) {
V_74 = F_43 ( V_9 -> V_86 , struct V_72 , V_83 ) ;
F_41 ( & V_74 -> V_83 ) ;
V_75 = V_74 -> V_75 ;
F_55 ( V_75 ) ;
F_12 ( & V_8 -> V_17 , V_16 ) ;
F_67 ( V_75 ) ;
F_58 ( V_75 ) ;
F_10 ( & V_8 -> V_17 , V_16 ) ;
}
F_12 ( & V_8 -> V_17 , V_16 ) ;
}
static void F_68 ( struct V_7 * V_8 ,
unsigned int V_135 )
{
struct V_134 * V_136 , * V_137 , V_138 ;
unsigned long V_16 ;
F_20 ( & V_138 ) ;
F_10 ( & V_8 -> V_17 , V_16 ) ;
F_69 (p, q, &ps->async_pending)
if ( V_135 == F_43 ( V_136 , struct V_72 , V_83 ) -> V_135 )
F_60 ( V_136 , & V_138 ) ;
F_12 ( & V_8 -> V_17 , V_16 ) ;
F_66 ( V_8 , & V_138 ) ;
}
static void F_70 ( struct V_7 * V_8 )
{
F_66 ( V_8 , & V_8 -> V_84 ) ;
}
static int F_71 ( struct V_139 * V_140 ,
const struct V_141 * V_142 )
{
return - V_53 ;
}
static void F_72 ( struct V_139 * V_140 )
{
struct V_7 * V_8 = F_73 ( V_140 ) ;
unsigned int V_135 = V_140 -> V_143 -> V_71 . V_144 ;
if ( ! V_8 )
return;
if ( F_74 ( V_135 < 8 * sizeof( V_8 -> V_145 ) ) )
F_75 ( V_135 , & V_8 -> V_145 ) ;
else
F_76 ( & V_140 -> V_10 , L_16 ,
V_135 ) ;
F_77 ( V_140 , NULL ) ;
F_68 ( V_8 , V_135 ) ;
}
static int F_78 ( struct V_139 * V_140 , T_8 V_146 )
{
return 0 ;
}
static int F_79 ( struct V_139 * V_140 )
{
return 0 ;
}
static int F_80 ( struct V_7 * V_8 , unsigned int V_135 )
{
struct V_49 * V_10 = V_8 -> V_10 ;
struct V_139 * V_140 ;
int V_54 ;
if ( V_135 >= 8 * sizeof( V_8 -> V_145 ) )
return - V_55 ;
if ( F_81 ( V_135 , & V_8 -> V_145 ) )
return 0 ;
if ( V_8 -> V_147 &&
! F_81 ( V_135 , & V_8 -> V_148 ) )
return - V_149 ;
V_140 = F_82 ( V_10 , V_135 ) ;
if ( ! V_140 )
V_54 = - V_132 ;
else
V_54 = F_83 ( & V_150 , V_140 , V_8 ) ;
if ( V_54 == 0 )
F_84 ( V_135 , & V_8 -> V_145 ) ;
return V_54 ;
}
static int F_85 ( struct V_7 * V_8 , unsigned int V_135 )
{
struct V_49 * V_10 ;
struct V_139 * V_140 ;
int V_54 ;
V_54 = - V_55 ;
if ( V_135 >= 8 * sizeof( V_8 -> V_145 ) )
return V_54 ;
V_10 = V_8 -> V_10 ;
V_140 = F_82 ( V_10 , V_135 ) ;
if ( ! V_140 )
V_54 = - V_132 ;
else if ( F_86 ( V_135 , & V_8 -> V_145 ) ) {
F_87 ( & V_150 , V_140 ) ;
V_54 = 0 ;
}
return V_54 ;
}
static int F_88 ( struct V_7 * V_8 , unsigned int V_135 )
{
if ( V_8 -> V_10 -> V_11 != V_151 )
return - V_152 ;
if ( V_135 >= 8 * sizeof( V_8 -> V_145 ) )
return - V_55 ;
if ( F_81 ( V_135 , & V_8 -> V_145 ) )
return 0 ;
F_76 ( & V_8 -> V_10 -> V_10 , L_17
L_18 , F_89 ( V_153 ) ,
V_153 -> V_154 , V_135 ) ;
return F_80 ( V_8 , V_135 ) ;
}
static int F_90 ( struct V_49 * V_10 , unsigned int V_97 )
{
unsigned int V_52 , V_155 , V_156 ;
struct V_139 * V_140 ;
struct V_157 * V_158 ;
struct V_159 * V_160 ;
if ( V_97 & ~ ( V_161 | 0xf ) )
return - V_55 ;
if ( ! V_10 -> V_162 )
return - V_163 ;
for ( V_52 = 0 ; V_52 < V_10 -> V_162 -> V_71 . V_164 ; V_52 ++ ) {
V_140 = V_10 -> V_162 -> V_165 [ V_52 ] ;
for ( V_155 = 0 ; V_155 < V_140 -> V_166 ; V_155 ++ ) {
V_158 = & V_140 -> V_143 [ V_155 ] ;
for ( V_156 = 0 ; V_156 < V_158 -> V_71 . V_167 ; V_156 ++ ) {
V_160 = & V_158 -> V_168 [ V_156 ] . V_71 ;
if ( V_160 -> V_169 == V_97 )
return V_158 -> V_71 . V_144 ;
}
}
}
return - V_132 ;
}
static int F_91 ( struct V_7 * V_8 , unsigned int V_170 ,
unsigned int V_171 , unsigned int V_172 )
{
int V_31 = 0 ;
struct V_157 * V_173 ;
if ( V_8 -> V_10 -> V_11 != V_174
&& V_8 -> V_10 -> V_11 != V_175
&& V_8 -> V_10 -> V_11 != V_151 )
return - V_152 ;
if ( V_176 == ( V_177 & V_170 ) )
return 0 ;
if ( V_170 == 0xa1 && V_171 == 0 ) {
V_173 = F_92 ( V_8 -> V_10 -> V_162 ,
V_172 >> 8 , V_172 & 0xff ) ;
if ( V_173
&& V_173 -> V_71 . V_178 == V_179 )
return 0 ;
}
V_172 &= 0xff ;
switch ( V_170 & V_180 ) {
case V_181 :
if ( ( V_172 & ~ V_161 ) == 0 )
return 0 ;
V_31 = F_90 ( V_8 -> V_10 , V_172 ) ;
if ( V_31 < 0 ) {
V_31 = F_90 ( V_8 -> V_10 , V_172 ^ 0x80 ) ;
if ( V_31 >= 0 )
F_50 ( & V_8 -> V_10 -> V_10 ,
L_19 ,
V_182 , F_89 ( V_153 ) ,
V_153 -> V_154 , V_172 , V_172 ^ 0x80 ) ;
}
if ( V_31 >= 0 )
V_31 = F_88 ( V_8 , V_31 ) ;
break;
case V_183 :
V_31 = F_88 ( V_8 , V_172 ) ;
break;
}
return V_31 ;
}
static struct V_184 * F_93 ( struct V_49 * V_10 ,
unsigned char V_97 )
{
if ( V_97 & V_185 )
return V_10 -> V_186 [ V_97 & V_187 ] ;
else
return V_10 -> V_188 [ V_97 & V_187 ] ;
}
static int F_94 ( struct V_7 * V_8 ,
struct V_189 T_4 * V_190 ,
unsigned int * V_191 ,
unsigned int * V_192 ,
struct V_184 * * * V_193 ,
struct V_139 * * V_194 )
{
unsigned int V_52 , V_195 , V_196 ;
struct V_184 * * V_197 ;
struct V_139 * V_140 = NULL ;
unsigned char V_97 ;
int V_135 , V_31 ;
if ( F_95 ( V_195 , & V_190 -> V_195 ) ||
F_95 ( V_196 , & V_190 -> V_196 ) )
return - V_63 ;
if ( V_196 < 1 || V_196 > V_198 )
return - V_55 ;
if ( V_191 && ( V_195 < 2 || V_195 > 65536 ) )
return - V_55 ;
V_197 = F_96 ( V_196 * sizeof( * V_197 ) , V_32 ) ;
if ( ! V_197 )
return - V_6 ;
for ( V_52 = 0 ; V_52 < V_196 ; V_52 ++ ) {
if ( F_95 ( V_97 , & V_190 -> V_197 [ V_52 ] ) ) {
V_31 = - V_63 ;
goto error;
}
V_197 [ V_52 ] = F_93 ( V_8 -> V_10 , V_97 ) ;
if ( ! V_197 [ V_52 ] ) {
V_31 = - V_55 ;
goto error;
}
V_135 = F_90 ( V_8 -> V_10 , V_97 ) ;
if ( V_135 < 0 ) {
V_31 = V_135 ;
goto error;
}
if ( V_52 == 0 ) {
V_31 = F_88 ( V_8 , V_135 ) ;
if ( V_31 < 0 )
goto error;
V_140 = F_82 ( V_8 -> V_10 , V_135 ) ;
} else {
if ( V_135 != V_140 -> V_143 -> V_71 . V_144 ) {
V_31 = - V_55 ;
goto error;
}
}
}
if ( V_191 )
* V_191 = V_195 ;
* V_192 = V_196 ;
* V_193 = V_197 ;
* V_194 = V_140 ;
return 0 ;
error:
F_14 ( V_197 ) ;
return V_31 ;
}
static int F_97 ( struct V_199 * V_10 , void * V_93 )
{
return V_10 -> V_200 == ( V_201 ) ( unsigned long ) V_93 ;
}
static struct V_49 * F_98 ( V_201 V_200 )
{
struct V_199 * V_10 ;
V_10 = F_99 ( & V_202 , NULL ,
( void * ) ( unsigned long ) V_200 , F_97 ) ;
if ( ! V_10 )
return NULL ;
return F_100 ( V_10 ) ;
}
static int F_101 ( struct V_203 * V_203 , struct V_27 * V_27 )
{
struct V_49 * V_10 = NULL ;
struct V_7 * V_8 ;
int V_31 ;
V_31 = - V_6 ;
V_8 = F_18 ( sizeof( struct V_7 ) , V_32 ) ;
if ( ! V_8 )
goto V_204;
V_31 = - V_53 ;
F_102 ( & V_205 ) ;
if ( F_103 ( V_203 ) == V_206 )
V_10 = F_98 ( V_203 -> V_207 ) ;
F_104 ( & V_205 ) ;
if ( ! V_10 )
goto V_204;
F_25 ( V_10 ) ;
if ( V_10 -> V_11 == V_12 )
goto V_208;
V_31 = F_105 ( V_10 ) ;
if ( V_31 )
goto V_208;
V_8 -> V_10 = V_10 ;
V_8 -> V_27 = V_27 ;
V_8 -> V_148 = 0xFFFFFFFF ;
F_106 ( & V_8 -> V_17 ) ;
F_20 ( & V_8 -> V_9 ) ;
F_20 ( & V_8 -> V_84 ) ;
F_20 ( & V_8 -> V_85 ) ;
F_20 ( & V_8 -> V_45 ) ;
F_107 ( & V_8 -> V_133 ) ;
V_8 -> V_209 = F_61 ( F_108 ( V_153 ) ) ;
V_8 -> V_77 = F_109 () ;
F_110 ( V_153 , & V_8 -> V_119 ) ;
F_111 () ;
F_23 ( & V_8 -> V_9 , & V_10 -> V_210 ) ;
V_27 -> V_28 = V_8 ;
F_30 ( V_10 ) ;
F_63 ( & V_10 -> V_10 , L_20 , F_89 ( V_153 ) ,
V_153 -> V_154 ) ;
return V_31 ;
V_208:
F_30 ( V_10 ) ;
F_112 ( V_10 ) ;
V_204:
F_14 ( V_8 ) ;
return V_31 ;
}
static int F_113 ( struct V_203 * V_203 , struct V_27 * V_27 )
{
struct V_7 * V_8 = V_27 -> V_28 ;
struct V_49 * V_10 = V_8 -> V_10 ;
unsigned int V_135 ;
struct V_72 * V_74 ;
F_25 ( V_10 ) ;
F_114 ( V_10 , V_8 ) ;
F_41 ( & V_8 -> V_9 ) ;
for ( V_135 = 0 ; V_8 -> V_145 && V_135 < 8 * sizeof( V_8 -> V_145 ) ;
V_135 ++ ) {
if ( F_81 ( V_135 , & V_8 -> V_145 ) )
F_85 ( V_8 , V_135 ) ;
}
F_70 ( V_8 ) ;
F_115 ( V_10 ) ;
F_30 ( V_10 ) ;
F_112 ( V_10 ) ;
F_34 ( V_8 -> V_209 ) ;
F_35 ( V_8 -> V_77 ) ;
V_74 = F_42 ( V_8 ) ;
while ( V_74 ) {
F_33 ( V_74 ) ;
V_74 = F_42 ( V_8 ) ;
}
F_14 ( V_8 ) ;
return 0 ;
}
static int F_116 ( struct V_7 * V_8 , void T_4 * V_211 )
{
struct V_49 * V_10 = V_8 -> V_10 ;
struct V_212 V_213 ;
unsigned int V_214 ;
unsigned char * V_215 ;
unsigned V_216 ;
int V_52 , V_89 , V_31 ;
if ( F_117 ( & V_213 , V_211 , sizeof( V_213 ) ) )
return - V_63 ;
V_31 = F_91 ( V_8 , V_213 . V_217 , V_213 . V_218 ,
V_213 . V_219 ) ;
if ( V_31 )
return V_31 ;
V_216 = V_213 . V_216 ;
if ( V_216 > V_220 )
return - V_55 ;
V_31 = F_1 ( V_220 + sizeof( struct V_75 ) +
sizeof( struct V_221 ) ) ;
if ( V_31 )
return V_31 ;
V_215 = ( unsigned char * ) F_118 ( V_32 ) ;
if ( ! V_215 ) {
V_31 = - V_6 ;
goto V_222;
}
V_214 = V_213 . V_223 ;
F_63 ( & V_10 -> V_10 , L_21
L_22
L_23 ,
V_213 . V_217 , V_213 . V_218 , V_213 . V_224 ,
V_213 . V_219 , V_213 . V_216 ) ;
if ( V_213 . V_217 & 0x80 ) {
if ( V_213 . V_216 && ! F_119 ( V_225 , V_213 . V_93 ,
V_213 . V_216 ) ) {
V_31 = - V_55 ;
goto V_222;
}
V_89 = F_120 ( V_10 , 0 ) ;
F_46 ( V_10 , NULL , V_89 , V_213 . V_216 , V_214 , V_101 , NULL , 0 ) ;
F_30 ( V_10 ) ;
V_52 = F_121 ( V_10 , V_89 , V_213 . V_218 ,
V_213 . V_217 , V_213 . V_224 , V_213 . V_219 ,
V_215 , V_213 . V_216 , V_214 ) ;
F_25 ( V_10 ) ;
F_46 ( V_10 , NULL , V_89 , F_122 ( V_52 , 0 ) , F_29 ( V_52 , 0 ) , V_127 ,
V_215 , F_122 ( V_52 , 0 ) ) ;
if ( ( V_52 > 0 ) && V_213 . V_216 ) {
if ( F_27 ( V_213 . V_93 , V_215 , V_52 ) ) {
V_31 = - V_63 ;
goto V_222;
}
}
} else {
if ( V_213 . V_216 ) {
if ( F_117 ( V_215 , V_213 . V_93 , V_213 . V_216 ) ) {
V_31 = - V_63 ;
goto V_222;
}
}
V_89 = F_123 ( V_10 , 0 ) ;
F_46 ( V_10 , NULL , V_89 , V_213 . V_216 , V_214 , V_101 ,
V_215 , V_213 . V_216 ) ;
F_30 ( V_10 ) ;
V_52 = F_121 ( V_10 , F_123 ( V_10 , 0 ) , V_213 . V_218 ,
V_213 . V_217 , V_213 . V_224 , V_213 . V_219 ,
V_215 , V_213 . V_216 , V_214 ) ;
F_25 ( V_10 ) ;
F_46 ( V_10 , NULL , V_89 , F_122 ( V_52 , 0 ) , F_29 ( V_52 , 0 ) , V_127 , NULL , 0 ) ;
}
if ( V_52 < 0 && V_52 != - V_226 ) {
F_124 ( V_103 , & V_10 -> V_10 , L_24
L_25 ,
V_153 -> V_154 , V_213 . V_217 , V_213 . V_218 ,
V_213 . V_216 , V_52 ) ;
}
V_31 = V_52 ;
V_222:
F_125 ( ( unsigned long ) V_215 ) ;
F_6 ( V_220 + sizeof( struct V_75 ) +
sizeof( struct V_221 ) ) ;
return V_31 ;
}
static int F_126 ( struct V_7 * V_8 , void T_4 * V_211 )
{
struct V_49 * V_10 = V_8 -> V_10 ;
struct V_227 V_228 ;
unsigned int V_214 , V_229 , V_89 ;
int V_230 ;
unsigned char * V_215 ;
int V_52 , V_31 ;
if ( F_117 ( & V_228 , V_211 , sizeof( V_228 ) ) )
return - V_63 ;
V_31 = F_90 ( V_8 -> V_10 , V_228 . V_97 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_88 ( V_8 , V_31 ) ;
if ( V_31 )
return V_31 ;
if ( V_228 . V_97 & V_161 )
V_89 = F_127 ( V_10 , V_228 . V_97 & 0x7f ) ;
else
V_89 = F_128 ( V_10 , V_228 . V_97 & 0x7f ) ;
if ( ! F_129 ( V_10 , V_89 , ! ( V_228 . V_97 & V_161 ) ) )
return - V_55 ;
V_229 = V_228 . V_50 ;
if ( V_229 >= V_4 )
return - V_55 ;
V_31 = F_1 ( V_229 + sizeof( struct V_75 ) ) ;
if ( V_31 )
return V_31 ;
V_215 = F_96 ( V_229 , V_32 ) ;
if ( ! V_215 ) {
V_31 = - V_6 ;
goto V_222;
}
V_214 = V_228 . V_223 ;
if ( V_228 . V_97 & 0x80 ) {
if ( V_229 && ! F_119 ( V_225 , V_228 . V_93 , V_229 ) ) {
V_31 = - V_55 ;
goto V_222;
}
F_46 ( V_10 , NULL , V_89 , V_229 , V_214 , V_101 , NULL , 0 ) ;
F_30 ( V_10 ) ;
V_52 = F_130 ( V_10 , V_89 , V_215 , V_229 , & V_230 , V_214 ) ;
F_25 ( V_10 ) ;
F_46 ( V_10 , NULL , V_89 , V_230 , V_52 , V_127 , V_215 , V_230 ) ;
if ( ! V_52 && V_230 ) {
if ( F_27 ( V_228 . V_93 , V_215 , V_230 ) ) {
V_31 = - V_63 ;
goto V_222;
}
}
} else {
if ( V_229 ) {
if ( F_117 ( V_215 , V_228 . V_93 , V_229 ) ) {
V_31 = - V_63 ;
goto V_222;
}
}
F_46 ( V_10 , NULL , V_89 , V_229 , V_214 , V_101 , V_215 , V_229 ) ;
F_30 ( V_10 ) ;
V_52 = F_130 ( V_10 , V_89 , V_215 , V_229 , & V_230 , V_214 ) ;
F_25 ( V_10 ) ;
F_46 ( V_10 , NULL , V_89 , V_230 , V_52 , V_127 , NULL , 0 ) ;
}
V_31 = ( V_52 < 0 ? V_52 : V_230 ) ;
V_222:
F_14 ( V_215 ) ;
F_6 ( V_229 + sizeof( struct V_75 ) ) ;
return V_31 ;
}
static void F_131 ( struct V_49 * V_88 ,
unsigned int V_231 , char * V_232 )
{
struct V_184 * * V_197 ;
struct V_184 * V_97 ;
V_197 = ( V_231 & V_161 ) ? V_88 -> V_186 : V_88 -> V_188 ;
V_97 = V_197 [ V_231 & 0x0f ] ;
if ( V_97 && ! F_8 ( & V_97 -> V_233 ) )
F_76 ( & V_88 -> V_10 , L_26 ,
F_89 ( V_153 ) , V_153 -> V_154 ,
V_232 , V_231 ) ;
}
static int F_132 ( struct V_7 * V_8 , void T_4 * V_211 )
{
unsigned int V_97 ;
int V_31 ;
if ( F_95 ( V_97 , ( unsigned int T_4 * ) V_211 ) )
return - V_63 ;
V_31 = F_90 ( V_8 -> V_10 , V_97 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_88 ( V_8 , V_31 ) ;
if ( V_31 )
return V_31 ;
F_131 ( V_8 -> V_10 , V_97 , L_27 ) ;
F_133 ( V_8 -> V_10 , V_97 ) ;
return 0 ;
}
static int F_134 ( struct V_7 * V_8 , void T_4 * V_211 )
{
unsigned int V_97 ;
int V_89 ;
int V_31 ;
if ( F_95 ( V_97 , ( unsigned int T_4 * ) V_211 ) )
return - V_63 ;
V_31 = F_90 ( V_8 -> V_10 , V_97 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_88 ( V_8 , V_31 ) ;
if ( V_31 )
return V_31 ;
F_131 ( V_8 -> V_10 , V_97 , L_28 ) ;
if ( V_97 & V_161 )
V_89 = F_127 ( V_8 -> V_10 , V_97 & 0x7f ) ;
else
V_89 = F_128 ( V_8 -> V_10 , V_97 & 0x7f ) ;
return F_135 ( V_8 -> V_10 , V_89 ) ;
}
static int F_136 ( struct V_7 * V_8 , void T_4 * V_211 )
{
struct V_234 V_235 ;
struct V_139 * V_140 ;
int V_31 ;
if ( F_117 ( & V_235 , V_211 , sizeof( V_235 ) ) )
return - V_63 ;
V_140 = F_82 ( V_8 -> V_10 , V_235 . V_165 ) ;
if ( ! V_140 || ! V_140 -> V_10 . V_236 )
V_31 = - V_237 ;
else {
F_137 ( V_235 . V_236 , V_140 -> V_10 . V_236 -> V_238 ,
sizeof( V_235 . V_236 ) ) ;
V_31 = ( F_27 ( V_211 , & V_235 , sizeof( V_235 ) ) ? - V_63 : 0 ) ;
}
return V_31 ;
}
static int F_138 ( struct V_7 * V_8 , void T_4 * V_211 )
{
struct V_239 V_240 = {
. V_241 = V_8 -> V_10 -> V_241 ,
. V_242 = V_8 -> V_10 -> V_243 == V_244
} ;
if ( F_27 ( V_211 , & V_240 , sizeof( V_240 ) ) )
return - V_63 ;
return 0 ;
}
static int F_139 ( struct V_7 * V_8 )
{
struct V_245 * V_162 = V_8 -> V_10 -> V_162 ;
struct V_139 * V_165 ;
int V_52 , V_246 ;
if ( V_8 -> V_147 && V_162 ) {
for ( V_52 = 0 ; V_52 < V_162 -> V_71 . V_164 ; ++ V_52 ) {
V_165 = V_162 -> V_165 [ V_52 ] ;
V_246 = V_165 -> V_247 -> V_71 . V_144 ;
if ( F_140 ( V_165 ) &&
! F_81 ( V_246 , & V_8 -> V_145 ) ) {
F_76 ( & V_8 -> V_10 -> V_10 ,
L_29 ,
V_246 , V_165 -> V_10 . V_236 -> V_238 , V_153 -> V_154 ) ;
return - V_149 ;
}
}
}
return F_141 ( V_8 -> V_10 ) ;
}
static int F_142 ( struct V_7 * V_8 , void T_4 * V_211 )
{
struct V_248 V_249 ;
int V_31 ;
if ( F_117 ( & V_249 , V_211 , sizeof( V_249 ) ) )
return - V_63 ;
V_31 = F_88 ( V_8 , V_249 . V_165 ) ;
if ( V_31 )
return V_31 ;
F_68 ( V_8 , V_249 . V_165 ) ;
return F_143 ( V_8 -> V_10 , V_249 . V_165 ,
V_249 . V_143 ) ;
}
static int F_144 ( struct V_7 * V_8 , void T_4 * V_211 )
{
int V_250 ;
int V_121 = 0 ;
struct V_245 * V_162 ;
if ( F_95 ( V_250 , ( int T_4 * ) V_211 ) )
return - V_63 ;
V_162 = V_8 -> V_10 -> V_162 ;
if ( V_162 ) {
int V_52 ;
for ( V_52 = 0 ; V_52 < V_162 -> V_71 . V_164 ; ++ V_52 ) {
if ( F_140 ( V_162 -> V_165 [ V_52 ] ) ) {
F_76 ( & V_8 -> V_10 -> V_10 ,
L_30
L_31 ,
V_162 -> V_165 [ V_52 ]
-> V_247
-> V_71 . V_144 ,
V_162 -> V_165 [ V_52 ]
-> V_10 . V_236 -> V_238 ,
V_153 -> V_154 , V_250 ) ;
V_121 = - V_251 ;
break;
}
}
}
if ( V_121 == 0 ) {
if ( V_162 && V_162 -> V_71 . V_252 == V_250 )
V_121 = F_145 ( V_8 -> V_10 ) ;
else
V_121 = F_146 ( V_8 -> V_10 , V_250 ) ;
}
return V_121 ;
}
static struct V_13 *
F_147 ( struct V_7 * V_8 , const struct V_253 * V_254 )
{
struct V_13 * V_14 = NULL , * V_255 ;
unsigned long V_16 ;
unsigned long V_256 = ( unsigned long ) V_254 -> V_257 ;
F_10 ( & V_8 -> V_17 , V_16 ) ;
F_45 (iter, &ps->memory_list, memlist) {
if ( V_256 >= V_255 -> V_30 &&
V_256 < V_255 -> V_30 + V_255 -> V_21 ) {
if ( V_254 -> V_258 > V_255 -> V_30 + V_255 -> V_21 -
V_256 ) {
V_14 = F_148 ( - V_55 ) ;
} else {
V_14 = V_255 ;
V_14 -> V_18 ++ ;
}
break;
}
}
F_12 ( & V_8 -> V_17 , V_16 ) ;
return V_14 ;
}
static int F_149 ( struct V_7 * V_8 , struct V_253 * V_254 ,
struct V_259 T_4 * V_260 ,
void T_4 * V_211 )
{
struct V_259 * V_261 = NULL ;
struct V_184 * V_97 ;
struct V_72 * V_74 = NULL ;
struct V_221 * V_262 = NULL ;
unsigned int V_250 , V_263 , V_264 ;
int V_52 , V_31 , V_265 , V_78 = 0 , V_135 = - 1 ;
int V_107 = 0 ;
unsigned int V_266 = 0 ;
void * V_46 ;
if ( V_254 -> V_16 & ~ ( V_267 |
V_268 |
V_269 |
V_270 |
V_271 |
V_272 ) )
return - V_55 ;
if ( V_254 -> V_258 > 0 && ! V_254 -> V_257 )
return - V_55 ;
if ( ! ( V_254 -> type == V_273 &&
( V_254 -> V_168 & ~ V_185 ) == 0 ) ) {
V_135 = F_90 ( V_8 -> V_10 , V_254 -> V_168 ) ;
if ( V_135 < 0 )
return V_135 ;
V_31 = F_88 ( V_8 , V_135 ) ;
if ( V_31 )
return V_31 ;
}
V_97 = F_93 ( V_8 -> V_10 , V_254 -> V_168 ) ;
if ( ! V_97 )
return - V_132 ;
V_265 = ( V_254 -> V_168 & V_185 ) != 0 ;
V_250 = 0 ;
switch ( V_254 -> type ) {
case V_273 :
if ( ! F_150 ( & V_97 -> V_71 ) )
return - V_55 ;
if ( V_254 -> V_258 < 8 )
return - V_55 ;
V_262 = F_96 ( sizeof( struct V_221 ) , V_32 ) ;
if ( ! V_262 )
return - V_6 ;
if ( F_117 ( V_262 , V_254 -> V_257 , 8 ) ) {
V_31 = - V_63 ;
goto error;
}
if ( V_254 -> V_258 < ( F_151 ( & V_262 -> V_216 ) + 8 ) ) {
V_31 = - V_55 ;
goto error;
}
V_31 = F_91 ( V_8 , V_262 -> V_217 , V_262 -> V_218 ,
F_151 ( & V_262 -> V_219 ) ) ;
if ( V_31 )
goto error;
V_254 -> V_258 = F_151 ( & V_262 -> V_216 ) ;
V_254 -> V_257 += 8 ;
if ( ( V_262 -> V_217 & V_161 ) && V_254 -> V_258 ) {
V_265 = 1 ;
V_254 -> V_168 |= V_161 ;
} else {
V_265 = 0 ;
V_254 -> V_168 &= ~ V_161 ;
}
F_63 ( & V_8 -> V_10 -> V_10 , L_21
L_22
L_23 ,
V_262 -> V_217 , V_262 -> V_218 ,
F_152 ( & V_262 -> V_224 ) ,
F_152 ( & V_262 -> V_219 ) ,
F_152 ( & V_262 -> V_216 ) ) ;
V_250 = sizeof( struct V_221 ) ;
break;
case V_274 :
switch ( F_153 ( & V_97 -> V_71 ) ) {
case V_275 :
case V_276 :
return - V_55 ;
case V_277 :
V_254 -> type = V_278 ;
goto V_279;
}
V_78 = F_154 ( V_254 -> V_258 , V_105 ) ;
if ( V_78 == 1 || V_78 > V_8 -> V_10 -> V_280 -> V_281 )
V_78 = 0 ;
if ( V_97 -> V_190 )
V_266 = V_254 -> V_266 ;
break;
case V_278 :
if ( ! F_155 ( & V_97 -> V_71 ) )
return - V_55 ;
V_279:
break;
case V_282 :
if ( V_254 -> V_107 < 1 ||
V_254 -> V_107 > 128 )
return - V_55 ;
if ( ! F_156 ( & V_97 -> V_71 ) )
return - V_55 ;
V_107 = V_254 -> V_107 ;
V_264 = sizeof( struct V_259 ) *
V_107 ;
V_261 = F_157 ( V_260 , V_264 ) ;
if ( F_158 ( V_261 ) ) {
V_31 = F_159 ( V_261 ) ;
V_261 = NULL ;
goto error;
}
for ( V_263 = V_250 = 0 ; V_250 < V_107 ; V_250 ++ ) {
if ( V_261 [ V_250 ] . V_68 > 49152 ) {
V_31 = - V_55 ;
goto error;
}
V_263 += V_261 [ V_250 ] . V_68 ;
}
V_250 *= sizeof( struct V_283 ) ;
V_254 -> V_258 = V_263 ;
break;
default:
return - V_55 ;
}
if ( V_254 -> V_258 >= V_4 ) {
V_31 = - V_55 ;
goto error;
}
if ( V_254 -> V_258 > 0 &&
! F_119 ( V_265 ? V_225 : V_284 ,
V_254 -> V_257 , V_254 -> V_258 ) ) {
V_31 = - V_63 ;
goto error;
}
V_74 = F_31 ( V_107 ) ;
if ( ! V_74 ) {
V_31 = - V_6 ;
goto error;
}
V_74 -> V_14 = F_147 ( V_8 , V_254 ) ;
if ( F_158 ( V_74 -> V_14 ) ) {
V_31 = F_159 ( V_74 -> V_14 ) ;
V_74 -> V_14 = NULL ;
goto error;
}
if ( V_74 -> V_14 )
V_78 = 0 ;
V_250 += sizeof( struct V_72 ) + sizeof( struct V_75 ) + V_254 -> V_258 +
V_78 * sizeof( struct V_285 ) ;
V_31 = F_1 ( V_250 ) ;
if ( V_31 )
goto error;
V_74 -> V_82 = V_250 ;
if ( V_78 ) {
V_74 -> V_75 -> V_79 = F_96 ( V_78 * sizeof( struct V_285 ) ,
V_32 ) ;
if ( ! V_74 -> V_75 -> V_79 ) {
V_31 = - V_6 ;
goto error;
}
V_74 -> V_75 -> V_78 = V_78 ;
F_160 ( V_74 -> V_75 -> V_79 , V_74 -> V_75 -> V_78 ) ;
V_263 = V_254 -> V_258 ;
for ( V_52 = 0 ; V_52 < V_74 -> V_75 -> V_78 ; V_52 ++ ) {
V_250 = ( V_263 > V_105 ) ? V_105 : V_263 ;
V_46 = F_96 ( V_250 , V_32 ) ;
if ( ! V_46 ) {
V_31 = - V_6 ;
goto error;
}
F_161 ( & V_74 -> V_75 -> V_79 [ V_52 ] , V_46 , V_250 ) ;
if ( ! V_265 ) {
if ( F_117 ( V_46 , V_254 -> V_257 , V_250 ) ) {
V_31 = - V_63 ;
goto error;
}
V_254 -> V_257 += V_250 ;
}
V_263 -= V_250 ;
}
} else if ( V_254 -> V_258 > 0 ) {
if ( V_74 -> V_14 ) {
unsigned long V_256 = ( unsigned long ) V_254 -> V_257 ;
V_74 -> V_75 -> V_80 = V_74 -> V_14 -> V_22 +
( V_256 - V_74 -> V_14 -> V_30 ) ;
} else {
V_74 -> V_75 -> V_80 = F_96 ( V_254 -> V_258 ,
V_32 ) ;
if ( ! V_74 -> V_75 -> V_80 ) {
V_31 = - V_6 ;
goto error;
}
if ( ! V_265 ) {
if ( F_117 ( V_74 -> V_75 -> V_80 ,
V_254 -> V_257 ,
V_254 -> V_258 ) ) {
V_31 = - V_63 ;
goto error;
}
} else if ( V_254 -> type == V_282 ) {
memset ( V_74 -> V_75 -> V_80 , 0 ,
V_254 -> V_258 ) ;
}
}
}
V_74 -> V_75 -> V_10 = V_8 -> V_10 ;
V_74 -> V_75 -> V_89 = ( V_254 -> type << 30 ) |
F_162 ( V_8 -> V_10 , V_254 -> V_168 & 0xf ) |
( V_254 -> V_168 & V_161 ) ;
V_250 = ( V_265 ? V_130 : V_286 ) ;
if ( V_254 -> V_16 & V_267 )
V_250 |= V_287 ;
if ( V_254 -> V_16 & V_268 && V_265 )
V_250 |= V_288 ;
if ( V_254 -> V_16 & V_270 )
V_250 |= V_289 ;
if ( V_254 -> V_16 & V_271 )
V_250 |= V_290 ;
if ( V_254 -> V_16 & V_272 )
V_250 |= V_291 ;
V_74 -> V_75 -> V_128 = V_250 ;
V_74 -> V_75 -> V_108 = V_254 -> V_258 ;
V_74 -> V_75 -> V_81 = ( unsigned char * ) V_262 ;
V_262 = NULL ;
V_74 -> V_75 -> V_292 = V_254 -> V_292 ;
V_74 -> V_75 -> V_107 = V_107 ;
V_74 -> V_75 -> V_266 = V_266 ;
if ( V_254 -> type == V_282 ||
V_8 -> V_10 -> V_243 == V_293 )
V_74 -> V_75 -> V_294 = 1 << F_29 ( 15 , V_97 -> V_71 . V_295 - 1 ) ;
else
V_74 -> V_75 -> V_294 = V_97 -> V_71 . V_295 ;
V_74 -> V_75 -> V_116 = V_74 ;
V_74 -> V_75 -> V_296 = V_85 ;
for ( V_263 = V_250 = 0 ; V_250 < V_107 ; V_250 ++ ) {
V_74 -> V_75 -> V_260 [ V_250 ] . V_297 = V_263 ;
V_74 -> V_75 -> V_260 [ V_250 ] . V_68 = V_261 [ V_250 ] . V_68 ;
V_263 += V_261 [ V_250 ] . V_68 ;
}
F_14 ( V_261 ) ;
V_261 = NULL ;
V_74 -> V_8 = V_8 ;
V_74 -> V_87 = V_211 ;
if ( V_74 -> V_14 ) {
unsigned long V_256 = ( unsigned long ) V_254 -> V_257 ;
V_74 -> V_75 -> V_128 |= V_298 ;
V_74 -> V_75 -> V_299 = V_74 -> V_14 -> V_23 +
( V_256 - V_74 -> V_14 -> V_30 ) ;
} else if ( V_265 && V_254 -> V_258 > 0 )
V_74 -> V_106 = V_254 -> V_257 ;
V_74 -> V_120 = V_254 -> V_120 ;
V_74 -> V_135 = V_135 ;
V_74 -> V_76 = F_61 ( F_108 ( V_153 ) ) ;
V_74 -> V_77 = F_109 () ;
F_110 ( V_153 , & V_74 -> V_119 ) ;
F_46 ( V_8 -> V_10 , V_74 -> V_87 , V_74 -> V_75 -> V_89 ,
V_74 -> V_75 -> V_108 , 0 , V_101 ,
NULL , 0 ) ;
if ( ! V_265 )
F_52 ( V_74 -> V_75 , V_74 -> V_75 -> V_108 ) ;
F_39 ( V_74 ) ;
if ( F_163 ( & V_97 -> V_71 ) ) {
F_164 ( & V_8 -> V_17 ) ;
V_74 -> V_110 = F_165 ( & V_97 -> V_71 ) |
( ( V_97 -> V_71 . V_169 & V_185 )
>> 3 ) ;
if ( V_254 -> V_16 & V_269 )
V_74 -> V_111 = V_112 ;
else
V_8 -> V_115 &= ~ ( 1 << V_74 -> V_110 ) ;
if ( V_8 -> V_115 & ( 1 << V_74 -> V_110 ) )
V_31 = - V_300 ;
else
V_31 = F_166 ( V_74 -> V_75 , V_301 ) ;
F_167 ( & V_8 -> V_17 ) ;
} else {
V_31 = F_166 ( V_74 -> V_75 , V_32 ) ;
}
if ( V_31 ) {
F_124 ( V_103 , & V_8 -> V_10 -> V_10 ,
L_32 , V_31 ) ;
F_46 ( V_8 -> V_10 , V_74 -> V_87 , V_74 -> V_75 -> V_89 ,
0 , V_31 , V_127 , NULL , 0 ) ;
F_40 ( V_74 ) ;
goto error;
}
return 0 ;
error:
if ( V_74 && V_74 -> V_14 )
F_9 ( V_74 -> V_14 , & V_74 -> V_14 -> V_18 ) ;
F_14 ( V_261 ) ;
F_14 ( V_262 ) ;
if ( V_74 )
F_33 ( V_74 ) ;
return V_31 ;
}
static int F_168 ( struct V_7 * V_8 , void T_4 * V_211 )
{
struct V_253 V_254 ;
if ( F_117 ( & V_254 , V_211 , sizeof( V_254 ) ) )
return - V_63 ;
return F_149 ( V_8 , & V_254 ,
( ( (struct V_253 T_4 * ) V_211 ) -> V_260 ) ,
V_211 ) ;
}
static int F_169 ( struct V_7 * V_8 , void T_4 * V_211 )
{
struct V_75 * V_75 ;
struct V_72 * V_74 ;
unsigned long V_16 ;
F_10 ( & V_8 -> V_17 , V_16 ) ;
V_74 = F_44 ( V_8 , V_211 ) ;
if ( ! V_74 ) {
F_12 ( & V_8 -> V_17 , V_16 ) ;
return - V_55 ;
}
V_75 = V_74 -> V_75 ;
F_55 ( V_75 ) ;
F_12 ( & V_8 -> V_17 , V_16 ) ;
F_67 ( V_75 ) ;
F_58 ( V_75 ) ;
return 0 ;
}
static int F_170 ( struct V_72 * V_74 , void T_4 * T_4 * V_211 )
{
struct V_75 * V_75 = V_74 -> V_75 ;
struct V_253 T_4 * V_87 = V_74 -> V_87 ;
void T_4 * V_302 = V_74 -> V_87 ;
unsigned int V_52 ;
if ( V_74 -> V_106 && V_75 -> V_109 ) {
if ( F_53 ( V_74 -> V_106 , V_75 ) )
goto V_303;
}
if ( F_171 ( V_74 -> V_121 , & V_87 -> V_121 ) )
goto V_303;
if ( F_171 ( V_75 -> V_109 , & V_87 -> V_109 ) )
goto V_303;
if ( F_171 ( V_75 -> V_304 , & V_87 -> V_304 ) )
goto V_303;
if ( F_156 ( & V_75 -> V_97 -> V_71 ) ) {
for ( V_52 = 0 ; V_52 < V_75 -> V_107 ; V_52 ++ ) {
if ( F_171 ( V_75 -> V_260 [ V_52 ] . V_109 ,
& V_87 -> V_260 [ V_52 ] . V_109 ) )
goto V_303;
if ( F_171 ( V_75 -> V_260 [ V_52 ] . V_121 ,
& V_87 -> V_260 [ V_52 ] . V_121 ) )
goto V_303;
}
}
if ( F_171 ( V_302 , ( void T_4 * T_4 * ) V_211 ) )
return - V_63 ;
return 0 ;
V_303:
return - V_63 ;
}
static struct V_72 * F_172 ( struct V_7 * V_8 )
{
F_173 ( V_133 , V_153 ) ;
struct V_72 * V_74 = NULL ;
struct V_49 * V_10 = V_8 -> V_10 ;
F_174 ( & V_8 -> V_133 , & V_133 ) ;
for (; ; ) {
F_175 ( V_305 ) ;
V_74 = F_42 ( V_8 ) ;
if ( V_74 || ! F_7 ( V_8 ) )
break;
if ( F_176 ( V_153 ) )
break;
F_30 ( V_10 ) ;
F_177 () ;
F_25 ( V_10 ) ;
}
F_178 ( & V_8 -> V_133 , & V_133 ) ;
F_179 ( V_306 ) ;
return V_74 ;
}
static int F_180 ( struct V_7 * V_8 , void T_4 * V_211 )
{
struct V_72 * V_74 = F_172 ( V_8 ) ;
if ( V_74 ) {
int V_307 ;
F_63 ( & V_8 -> V_10 -> V_10 , L_33 , V_74 -> V_87 ) ;
V_307 = F_170 ( V_74 , ( void T_4 * T_4 * ) V_211 ) ;
F_33 ( V_74 ) ;
return V_307 ;
}
if ( F_176 ( V_153 ) )
return - V_308 ;
return - V_53 ;
}
static int F_181 ( struct V_7 * V_8 , void T_4 * V_211 )
{
int V_307 ;
struct V_72 * V_74 ;
V_74 = F_42 ( V_8 ) ;
if ( V_74 ) {
F_63 ( & V_8 -> V_10 -> V_10 , L_33 , V_74 -> V_87 ) ;
V_307 = F_170 ( V_74 , ( void T_4 * T_4 * ) V_211 ) ;
F_33 ( V_74 ) ;
} else {
V_307 = ( F_7 ( V_8 ) ? - V_38 : - V_53 ) ;
}
return V_307 ;
}
static int F_182 ( struct V_7 * V_8 ,
struct V_309 T_4 * V_310 )
{
struct V_212 T_4 * V_136 ;
T_9 V_311 ;
V_136 = F_183 ( sizeof( * V_136 ) ) ;
if ( F_184 ( V_136 , V_310 , ( sizeof( * V_310 ) - sizeof( V_312 ) ) ) ||
F_95 ( V_311 , & V_310 -> V_93 ) ||
F_171 ( F_185 ( V_311 ) , & V_136 -> V_93 ) )
return - V_63 ;
return F_116 ( V_8 , V_136 ) ;
}
static int F_186 ( struct V_7 * V_8 ,
struct V_313 T_4 * V_310 )
{
struct V_227 T_4 * V_136 ;
T_10 V_314 ;
V_312 V_302 ;
V_136 = F_183 ( sizeof( * V_136 ) ) ;
if ( F_95 ( V_314 , & V_310 -> V_97 ) || F_171 ( V_314 , & V_136 -> V_97 ) ||
F_95 ( V_314 , & V_310 -> V_50 ) || F_171 ( V_314 , & V_136 -> V_50 ) ||
F_95 ( V_314 , & V_310 -> V_223 ) || F_171 ( V_314 , & V_136 -> V_223 ) ||
F_95 ( V_302 , & V_310 -> V_93 ) || F_171 ( F_185 ( V_302 ) , & V_136 -> V_93 ) )
return - V_63 ;
return F_126 ( V_8 , V_136 ) ;
}
static int F_187 ( struct V_7 * V_8 , void T_4 * V_211 )
{
struct V_315 V_316 ;
if ( F_117 ( & V_316 , V_211 , sizeof( V_316 ) ) )
return - V_63 ;
V_8 -> V_317 = V_316 . V_120 ;
V_8 -> V_318 = F_185 ( V_316 . V_116 ) ;
return 0 ;
}
static int F_188 ( struct V_253 * V_319 ,
struct V_320 T_4 * V_254 )
{
T_9 V_321 ;
if ( ! F_119 ( V_284 , V_254 , sizeof( * V_254 ) ) ||
F_189 ( V_319 -> type , & V_254 -> type ) ||
F_189 ( V_319 -> V_168 , & V_254 -> V_168 ) ||
F_189 ( V_319 -> V_121 , & V_254 -> V_121 ) ||
F_189 ( V_319 -> V_16 , & V_254 -> V_16 ) ||
F_189 ( V_319 -> V_258 , & V_254 -> V_258 ) ||
F_189 ( V_319 -> V_109 , & V_254 -> V_109 ) ||
F_189 ( V_319 -> V_292 , & V_254 -> V_292 ) ||
F_189 ( V_319 -> V_107 , & V_254 -> V_107 ) ||
F_189 ( V_319 -> V_304 , & V_254 -> V_304 ) ||
F_189 ( V_319 -> V_120 , & V_254 -> V_120 ) )
return - V_63 ;
if ( F_189 ( V_321 , & V_254 -> V_257 ) )
return - V_63 ;
V_319 -> V_257 = F_185 ( V_321 ) ;
if ( F_189 ( V_321 , & V_254 -> V_322 ) )
return - V_63 ;
V_319 -> V_322 = F_185 ( V_321 ) ;
return 0 ;
}
static int F_190 ( struct V_7 * V_8 , void T_4 * V_211 )
{
struct V_253 V_254 ;
if ( F_188 ( & V_254 , (struct V_320 T_4 * ) V_211 ) )
return - V_63 ;
return F_149 ( V_8 , & V_254 ,
( (struct V_320 T_4 * ) V_211 ) -> V_260 ,
V_211 ) ;
}
static int F_191 ( struct V_72 * V_74 , void T_4 * T_4 * V_211 )
{
struct V_75 * V_75 = V_74 -> V_75 ;
struct V_320 T_4 * V_87 = V_74 -> V_87 ;
void T_4 * V_302 = V_74 -> V_87 ;
unsigned int V_52 ;
if ( V_74 -> V_106 && V_75 -> V_109 ) {
if ( F_53 ( V_74 -> V_106 , V_75 ) )
return - V_63 ;
}
if ( F_171 ( V_74 -> V_121 , & V_87 -> V_121 ) )
return - V_63 ;
if ( F_171 ( V_75 -> V_109 , & V_87 -> V_109 ) )
return - V_63 ;
if ( F_171 ( V_75 -> V_304 , & V_87 -> V_304 ) )
return - V_63 ;
if ( F_156 ( & V_75 -> V_97 -> V_71 ) ) {
for ( V_52 = 0 ; V_52 < V_75 -> V_107 ; V_52 ++ ) {
if ( F_171 ( V_75 -> V_260 [ V_52 ] . V_109 ,
& V_87 -> V_260 [ V_52 ] . V_109 ) )
return - V_63 ;
if ( F_171 ( V_75 -> V_260 [ V_52 ] . V_121 ,
& V_87 -> V_260 [ V_52 ] . V_121 ) )
return - V_63 ;
}
}
if ( F_171 ( F_192 ( V_302 ) , ( T_7 T_4 * ) V_211 ) )
return - V_63 ;
return 0 ;
}
static int F_193 ( struct V_7 * V_8 , void T_4 * V_211 )
{
struct V_72 * V_74 = F_172 ( V_8 ) ;
if ( V_74 ) {
int V_307 ;
F_63 ( & V_8 -> V_10 -> V_10 , L_33 , V_74 -> V_87 ) ;
V_307 = F_191 ( V_74 , ( void T_4 * T_4 * ) V_211 ) ;
F_33 ( V_74 ) ;
return V_307 ;
}
if ( F_176 ( V_153 ) )
return - V_308 ;
return - V_53 ;
}
static int F_194 ( struct V_7 * V_8 , void T_4 * V_211 )
{
int V_307 ;
struct V_72 * V_74 ;
V_74 = F_42 ( V_8 ) ;
if ( V_74 ) {
F_63 ( & V_8 -> V_10 -> V_10 , L_33 , V_74 -> V_87 ) ;
V_307 = F_191 ( V_74 , ( void T_4 * T_4 * ) V_211 ) ;
F_33 ( V_74 ) ;
} else {
V_307 = ( F_7 ( V_8 ) ? - V_38 : - V_53 ) ;
}
return V_307 ;
}
static int F_195 ( struct V_7 * V_8 , void T_4 * V_211 )
{
struct V_323 V_316 ;
if ( F_117 ( & V_316 , V_211 , sizeof( V_316 ) ) )
return - V_63 ;
V_8 -> V_317 = V_316 . V_120 ;
V_8 -> V_318 = V_316 . V_116 ;
return 0 ;
}
static int F_196 ( struct V_7 * V_8 , void T_4 * V_211 )
{
unsigned int V_135 ;
if ( F_95 ( V_135 , ( unsigned int T_4 * ) V_211 ) )
return - V_63 ;
return F_80 ( V_8 , V_135 ) ;
}
static int F_197 ( struct V_7 * V_8 , void T_4 * V_211 )
{
unsigned int V_135 ;
int V_31 ;
if ( F_95 ( V_135 , ( unsigned int T_4 * ) V_211 ) )
return - V_63 ;
V_31 = F_85 ( V_8 , V_135 ) ;
if ( V_31 < 0 )
return V_31 ;
F_68 ( V_8 , V_135 ) ;
return 0 ;
}
static int F_198 ( struct V_7 * V_8 , struct V_324 * V_325 )
{
int V_21 ;
void * V_46 = NULL ;
int V_307 = 0 ;
struct V_139 * V_140 = NULL ;
struct V_326 * V_236 = NULL ;
if ( V_8 -> V_147 )
return - V_149 ;
V_21 = F_199 ( V_325 -> V_327 ) ;
if ( V_21 > 0 ) {
V_46 = F_96 ( V_21 , V_32 ) ;
if ( V_46 == NULL )
return - V_6 ;
if ( ( F_200 ( V_325 -> V_327 ) & V_328 ) ) {
if ( F_117 ( V_46 , V_325 -> V_93 , V_21 ) ) {
F_14 ( V_46 ) ;
return - V_63 ;
}
} else {
memset ( V_46 , 0 , V_21 ) ;
}
}
if ( ! F_7 ( V_8 ) ) {
F_14 ( V_46 ) ;
return - V_53 ;
}
if ( V_8 -> V_10 -> V_11 != V_151 )
V_307 = - V_152 ;
else if ( ! ( V_140 = F_82 ( V_8 -> V_10 , V_325 -> V_329 ) ) )
V_307 = - V_55 ;
else switch ( V_325 -> V_327 ) {
case V_330 :
if ( V_140 -> V_10 . V_236 ) {
V_236 = F_201 ( V_140 -> V_10 . V_236 ) ;
F_202 ( & V_140 -> V_10 , L_34 ) ;
F_87 ( V_236 , V_140 ) ;
} else
V_307 = - V_237 ;
break;
case V_331 :
if ( ! V_140 -> V_10 . V_236 )
V_307 = F_203 ( & V_140 -> V_10 ) ;
else
V_307 = - V_251 ;
break;
default:
if ( V_140 -> V_10 . V_236 )
V_236 = F_201 ( V_140 -> V_10 . V_236 ) ;
if ( V_236 == NULL || V_236 -> V_332 == NULL ) {
V_307 = - V_333 ;
} else {
V_307 = V_236 -> V_332 ( V_140 , V_325 -> V_327 , V_46 ) ;
if ( V_307 == - V_334 )
V_307 = - V_333 ;
}
}
if ( V_307 >= 0
&& ( F_200 ( V_325 -> V_327 ) & V_335 ) != 0
&& V_21 > 0
&& F_27 ( V_325 -> V_93 , V_46 , V_21 ) != 0 )
V_307 = - V_63 ;
F_14 ( V_46 ) ;
return V_307 ;
}
static int F_204 ( struct V_7 * V_8 , void T_4 * V_211 )
{
struct V_324 V_213 ;
if ( F_117 ( & V_213 , V_211 , sizeof( V_213 ) ) )
return - V_63 ;
return F_198 ( V_8 , & V_213 ) ;
}
static int F_205 ( struct V_7 * V_8 , T_11 V_211 )
{
struct V_336 T_4 * V_337 ;
struct V_324 V_213 ;
T_7 V_311 ;
V_337 = F_185 ( ( long ) V_211 ) ;
if ( ! F_119 ( V_284 , V_337 , sizeof( * V_337 ) ) ||
F_189 ( V_213 . V_329 , & V_337 -> V_329 ) ||
F_189 ( V_213 . V_327 , & V_337 -> V_327 ) ||
F_189 ( V_311 , & V_337 -> V_93 ) )
return - V_63 ;
V_213 . V_93 = F_185 ( V_311 ) ;
return F_198 ( V_8 , & V_213 ) ;
}
static int F_206 ( struct V_7 * V_8 , void T_4 * V_211 )
{
unsigned V_338 ;
int V_339 ;
if ( F_95 ( V_338 , ( unsigned T_4 * ) V_211 ) )
return - V_63 ;
V_339 = F_207 ( V_8 -> V_10 , V_338 , V_8 ) ;
if ( V_339 == 0 )
F_63 ( & V_8 -> V_10 -> V_10 , L_35 ,
V_338 , F_89 ( V_153 ) , V_153 -> V_154 ) ;
return V_339 ;
}
static int F_208 ( struct V_7 * V_8 , void T_4 * V_211 )
{
unsigned V_338 ;
if ( F_95 ( V_338 , ( unsigned T_4 * ) V_211 ) )
return - V_63 ;
return F_209 ( V_8 -> V_10 , V_338 , V_8 ) ;
}
static int F_210 ( struct V_7 * V_8 , void T_4 * V_211 )
{
T_9 V_340 ;
V_340 = V_341 | V_342 |
V_343 | V_344 |
V_345 ;
if ( ! V_8 -> V_10 -> V_280 -> V_346 )
V_340 |= V_347 ;
if ( V_8 -> V_10 -> V_280 -> V_281 )
V_340 |= V_348 ;
if ( F_171 ( V_340 , ( T_9 T_4 * ) V_211 ) )
return - V_63 ;
return 0 ;
}
static int F_211 ( struct V_7 * V_8 , void T_4 * V_211 )
{
struct V_349 V_350 ;
struct V_139 * V_140 ;
if ( F_117 ( & V_350 , V_211 , sizeof( V_350 ) ) )
return - V_63 ;
V_140 = F_82 ( V_8 -> V_10 , V_350 . V_165 ) ;
if ( ! V_140 )
return - V_55 ;
if ( V_140 -> V_10 . V_236 ) {
struct V_326 * V_236 = F_201 ( V_140 -> V_10 . V_236 ) ;
if ( V_8 -> V_147 )
return - V_149 ;
if ( ( V_350 . V_16 & V_351 ) &&
strncmp ( V_350 . V_236 , V_140 -> V_10 . V_236 -> V_238 ,
sizeof( V_350 . V_236 ) ) != 0 )
return - V_251 ;
if ( ( V_350 . V_16 & V_352 ) &&
strncmp ( V_350 . V_236 , V_140 -> V_10 . V_236 -> V_238 ,
sizeof( V_350 . V_236 ) ) == 0 )
return - V_251 ;
F_202 ( & V_140 -> V_10 , L_34 ) ;
F_87 ( V_236 , V_140 ) ;
}
return F_80 ( V_8 , V_350 . V_165 ) ;
}
static int F_212 ( struct V_7 * V_8 , void T_4 * V_211 )
{
unsigned V_195 , V_196 ;
struct V_184 * * V_197 ;
struct V_139 * V_140 ;
int V_353 ;
V_353 = F_94 ( V_8 , V_211 , & V_195 , & V_196 ,
& V_197 , & V_140 ) ;
if ( V_353 )
return V_353 ;
F_68 ( V_8 ,
V_140 -> V_143 [ 0 ] . V_71 . V_144 ) ;
V_353 = F_213 ( V_140 , V_197 , V_196 , V_195 , V_32 ) ;
F_14 ( V_197 ) ;
return V_353 ;
}
static int F_214 ( struct V_7 * V_8 , void T_4 * V_211 )
{
unsigned V_196 ;
struct V_184 * * V_197 ;
struct V_139 * V_140 ;
int V_353 ;
V_353 = F_94 ( V_8 , V_211 , NULL , & V_196 , & V_197 , & V_140 ) ;
if ( V_353 )
return V_353 ;
F_68 ( V_8 ,
V_140 -> V_143 [ 0 ] . V_71 . V_144 ) ;
V_353 = F_215 ( V_140 , V_197 , V_196 , V_32 ) ;
F_14 ( V_197 ) ;
return V_353 ;
}
static int F_216 ( struct V_7 * V_8 , void T_4 * V_211 )
{
T_7 V_93 ;
if ( F_117 ( & V_93 , V_211 , sizeof( V_93 ) ) )
return - V_63 ;
V_8 -> V_148 &= V_93 ;
V_8 -> V_147 = true ;
return 0 ;
}
static long F_217 ( struct V_27 * V_27 , unsigned int V_354 ,
void T_4 * V_136 )
{
struct V_7 * V_8 = V_27 -> V_28 ;
struct V_203 * V_203 = F_218 ( V_27 ) ;
struct V_49 * V_10 = V_8 -> V_10 ;
int V_31 = - V_333 ;
if ( ! ( V_27 -> V_355 & V_356 ) )
return - V_357 ;
F_25 ( V_10 ) ;
switch ( V_354 ) {
case V_358 :
F_63 ( & V_10 -> V_10 , L_36 , V_182 ) ;
V_31 = F_180 ( V_8 , V_136 ) ;
goto V_222;
case V_359 :
F_63 ( & V_10 -> V_10 , L_37 , V_182 ) ;
V_31 = F_181 ( V_8 , V_136 ) ;
goto V_222;
#ifdef F_219
case V_360 :
F_63 ( & V_10 -> V_10 , L_38 , V_182 ) ;
V_31 = F_193 ( V_8 , V_136 ) ;
goto V_222;
case V_361 :
F_63 ( & V_10 -> V_10 , L_39 , V_182 ) ;
V_31 = F_194 ( V_8 , V_136 ) ;
goto V_222;
#endif
}
if ( ! F_7 ( V_8 ) ) {
F_30 ( V_10 ) ;
return - V_53 ;
}
switch ( V_354 ) {
case V_362 :
F_63 ( & V_10 -> V_10 , L_40 , V_182 ) ;
V_31 = F_116 ( V_8 , V_136 ) ;
if ( V_31 >= 0 )
V_203 -> V_363 = V_364 ;
break;
case V_365 :
F_63 ( & V_10 -> V_10 , L_41 , V_182 ) ;
V_31 = F_126 ( V_8 , V_136 ) ;
if ( V_31 >= 0 )
V_203 -> V_363 = V_364 ;
break;
case V_366 :
F_63 ( & V_10 -> V_10 , L_42 , V_182 ) ;
V_31 = F_132 ( V_8 , V_136 ) ;
if ( V_31 >= 0 )
V_203 -> V_363 = V_364 ;
break;
case V_367 :
F_63 ( & V_10 -> V_10 , L_43 , V_182 ) ;
V_31 = F_139 ( V_8 ) ;
break;
case V_368 :
F_63 ( & V_10 -> V_10 , L_44 , V_182 ) ;
V_31 = F_134 ( V_8 , V_136 ) ;
if ( V_31 >= 0 )
V_203 -> V_363 = V_364 ;
break;
case V_369 :
F_63 ( & V_10 -> V_10 , L_45 , V_182 ) ;
V_31 = F_136 ( V_8 , V_136 ) ;
break;
case V_370 :
F_63 ( & V_10 -> V_10 , L_46 , V_182 ) ;
V_31 = F_138 ( V_8 , V_136 ) ;
break;
case V_371 :
F_63 ( & V_10 -> V_10 , L_47 , V_182 ) ;
V_31 = F_142 ( V_8 , V_136 ) ;
break;
case V_372 :
F_63 ( & V_10 -> V_10 , L_48 , V_182 ) ;
V_31 = F_144 ( V_8 , V_136 ) ;
break;
case V_373 :
F_63 ( & V_10 -> V_10 , L_49 , V_182 ) ;
V_31 = F_168 ( V_8 , V_136 ) ;
if ( V_31 >= 0 )
V_203 -> V_363 = V_364 ;
break;
#ifdef F_219
case V_374 :
F_63 ( & V_10 -> V_10 , L_50 , V_182 ) ;
V_31 = F_182 ( V_8 , V_136 ) ;
if ( V_31 >= 0 )
V_203 -> V_363 = V_364 ;
break;
case V_375 :
F_63 ( & V_10 -> V_10 , L_51 , V_182 ) ;
V_31 = F_186 ( V_8 , V_136 ) ;
if ( V_31 >= 0 )
V_203 -> V_363 = V_364 ;
break;
case V_376 :
F_63 ( & V_10 -> V_10 , L_52 , V_182 ) ;
V_31 = F_187 ( V_8 , V_136 ) ;
break;
case V_377 :
F_63 ( & V_10 -> V_10 , L_53 , V_182 ) ;
V_31 = F_190 ( V_8 , V_136 ) ;
if ( V_31 >= 0 )
V_203 -> V_363 = V_364 ;
break;
case V_378 :
F_63 ( & V_10 -> V_10 , L_54 , V_182 ) ;
V_31 = F_205 ( V_8 , F_192 ( V_136 ) ) ;
break;
#endif
case V_379 :
F_63 ( & V_10 -> V_10 , L_55 , V_182 , V_136 ) ;
V_31 = F_169 ( V_8 , V_136 ) ;
break;
case V_380 :
F_63 ( & V_10 -> V_10 , L_56 , V_182 ) ;
V_31 = F_195 ( V_8 , V_136 ) ;
break;
case V_381 :
F_63 ( & V_10 -> V_10 , L_57 , V_182 ) ;
V_31 = F_196 ( V_8 , V_136 ) ;
break;
case V_382 :
F_63 ( & V_10 -> V_10 , L_58 , V_182 ) ;
V_31 = F_197 ( V_8 , V_136 ) ;
break;
case V_383 :
F_63 ( & V_10 -> V_10 , L_59 , V_182 ) ;
V_31 = F_204 ( V_8 , V_136 ) ;
break;
case V_384 :
F_63 ( & V_10 -> V_10 , L_60 , V_182 ) ;
V_31 = F_206 ( V_8 , V_136 ) ;
break;
case V_385 :
F_63 ( & V_10 -> V_10 , L_61 , V_182 ) ;
V_31 = F_208 ( V_8 , V_136 ) ;
break;
case V_386 :
V_31 = F_210 ( V_8 , V_136 ) ;
break;
case V_387 :
V_31 = F_211 ( V_8 , V_136 ) ;
break;
case V_388 :
V_31 = F_212 ( V_8 , V_136 ) ;
break;
case V_389 :
V_31 = F_214 ( V_8 , V_136 ) ;
break;
case V_390 :
V_31 = F_216 ( V_8 , V_136 ) ;
break;
}
V_222:
F_30 ( V_10 ) ;
if ( V_31 >= 0 )
V_203 -> V_391 = V_364 ;
return V_31 ;
}
static long F_220 ( struct V_27 * V_27 , unsigned int V_354 ,
unsigned long V_211 )
{
int V_31 ;
V_31 = F_217 ( V_27 , V_354 , ( void T_4 * ) V_211 ) ;
return V_31 ;
}
static long F_221 ( struct V_27 * V_27 , unsigned int V_354 ,
unsigned long V_211 )
{
int V_31 ;
V_31 = F_217 ( V_27 , V_354 , F_185 ( V_211 ) ) ;
return V_31 ;
}
static unsigned int F_222 ( struct V_27 * V_27 ,
struct V_392 * V_133 )
{
struct V_7 * V_8 = V_27 -> V_28 ;
unsigned int V_393 = 0 ;
F_223 ( V_27 , & V_8 -> V_133 , V_133 ) ;
if ( V_27 -> V_355 & V_356 && ! F_8 ( & V_8 -> V_85 ) )
V_393 |= V_394 | V_395 ;
if ( ! F_7 ( V_8 ) )
V_393 |= V_396 | V_397 ;
return V_393 ;
}
static void F_224 ( struct V_49 * V_88 )
{
struct V_7 * V_8 ;
struct V_117 V_118 ;
while ( ! F_8 ( & V_88 -> V_210 ) ) {
V_8 = F_43 ( V_88 -> V_210 . V_86 , struct V_7 , V_9 ) ;
F_70 ( V_8 ) ;
F_225 ( & V_8 -> V_133 ) ;
F_41 ( & V_8 -> V_9 ) ;
if ( V_8 -> V_317 ) {
memset ( & V_118 , 0 , sizeof( V_118 ) ) ;
V_118 . V_122 = V_8 -> V_317 ;
V_118 . V_123 = V_226 ;
V_118 . V_124 = V_125 ;
V_118 . V_126 = V_8 -> V_318 ;
F_64 ( V_8 -> V_317 , & V_118 ,
V_8 -> V_209 , V_8 -> V_77 , V_8 -> V_119 ) ;
}
}
}
static int F_226 ( struct V_398 * V_399 ,
unsigned long V_400 , void * V_10 )
{
switch ( V_400 ) {
case V_401 :
break;
case V_402 :
F_224 ( V_10 ) ;
break;
}
return V_403 ;
}
int T_12 F_227 ( void )
{
int V_307 ;
V_307 = F_228 ( V_404 , V_405 ,
L_62 ) ;
if ( V_307 ) {
F_229 ( V_406 L_63 ) ;
goto V_407;
}
F_230 ( & V_408 , & V_409 ) ;
V_307 = F_231 ( & V_408 , V_404 , V_405 ) ;
if ( V_307 ) {
F_229 ( V_406 L_64 ,
V_206 ) ;
goto V_410;
}
F_232 ( & V_411 ) ;
V_407:
return V_307 ;
V_410:
F_233 ( V_404 , V_405 ) ;
goto V_407;
}
void F_234 ( void )
{
F_235 ( & V_411 ) ;
F_236 ( & V_408 ) ;
F_233 ( V_404 , V_405 ) ;
}
