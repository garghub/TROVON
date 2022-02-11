static int F_1 ( T_1 V_1 )
{
T_1 V_2 ;
V_2 = F_2 ( V_3 ) ;
V_2 <<= 20 ;
F_3 ( V_1 , & V_4 ) ;
if ( V_2 > 0 && F_4 ( & V_4 ) > V_2 ) {
F_5 ( V_1 , & V_4 ) ;
return - V_5 ;
}
return 0 ;
}
static void F_6 ( T_1 V_1 )
{
F_5 ( V_1 , & V_4 ) ;
}
static int F_7 ( struct V_6 * V_7 )
{
return ( ! F_8 ( & V_7 -> V_8 ) &&
V_7 -> V_9 -> V_10 != V_11 ) ;
}
static void F_9 ( struct V_12 * V_13 , int * V_14 )
{
struct V_6 * V_7 = V_13 -> V_7 ;
unsigned long V_15 ;
F_10 ( & V_7 -> V_16 , V_15 ) ;
-- * V_14 ;
if ( V_13 -> V_17 == 0 && V_13 -> V_18 == 0 ) {
F_11 ( & V_13 -> V_19 ) ;
F_12 ( & V_7 -> V_16 , V_15 ) ;
F_13 ( V_7 -> V_9 , V_13 -> V_20 , V_13 -> V_21 ,
V_13 -> V_22 ) ;
F_6 (
V_13 -> V_20 + sizeof( struct V_12 ) ) ;
F_14 ( V_13 ) ;
} else {
F_12 ( & V_7 -> V_16 , V_15 ) ;
}
}
static void F_15 ( struct V_23 * V_24 )
{
struct V_12 * V_13 = V_24 -> V_25 ;
unsigned long V_15 ;
F_10 ( & V_13 -> V_7 -> V_16 , V_15 ) ;
++ V_13 -> V_18 ;
F_12 ( & V_13 -> V_7 -> V_16 , V_15 ) ;
}
static void F_16 ( struct V_23 * V_24 )
{
struct V_12 * V_13 = V_24 -> V_25 ;
F_9 ( V_13 , & V_13 -> V_18 ) ;
}
static int F_17 ( struct V_26 * V_26 , struct V_23 * V_24 )
{
struct V_12 * V_13 = NULL ;
struct V_6 * V_7 = V_26 -> V_27 ;
T_2 V_20 = V_24 -> V_28 - V_24 -> V_29 ;
void * V_21 ;
unsigned long V_15 ;
T_3 V_22 ;
int V_30 ;
V_30 = F_1 ( V_20 + sizeof( struct V_12 ) ) ;
if ( V_30 )
goto error;
V_13 = F_18 ( sizeof( struct V_12 ) , V_31 ) ;
if ( ! V_13 ) {
V_30 = - V_5 ;
goto V_32;
}
V_21 = F_19 ( V_7 -> V_9 , V_20 , V_33 | V_34 ,
& V_22 ) ;
if ( ! V_21 ) {
V_30 = - V_5 ;
goto V_35;
}
memset ( V_21 , 0 , V_20 ) ;
V_13 -> V_21 = V_21 ;
V_13 -> V_22 = V_22 ;
V_13 -> V_20 = V_20 ;
V_13 -> V_7 = V_7 ;
V_13 -> V_29 = V_24 -> V_29 ;
V_13 -> V_18 = 1 ;
F_20 ( & V_13 -> V_19 ) ;
if ( F_21 ( V_24 , V_24 -> V_29 ,
F_22 ( V_13 -> V_21 ) >> V_36 ,
V_20 , V_24 -> V_37 ) < 0 ) {
F_9 ( V_13 , & V_13 -> V_18 ) ;
return - V_38 ;
}
V_24 -> V_39 |= V_40 ;
V_24 -> V_39 |= ( V_41 | V_42 ) ;
V_24 -> V_43 = & V_44 ;
V_24 -> V_25 = V_13 ;
F_10 ( & V_7 -> V_16 , V_15 ) ;
F_23 ( & V_13 -> V_19 , & V_7 -> V_45 ) ;
F_12 ( & V_7 -> V_16 , V_15 ) ;
return 0 ;
V_35:
F_14 ( V_13 ) ;
V_32:
F_6 ( V_20 + sizeof( struct V_12 ) ) ;
error:
return V_30 ;
}
static T_4 F_24 ( struct V_26 * V_26 , char T_5 * V_46 , T_2 V_47 ,
T_6 * V_48 )
{
struct V_6 * V_7 = V_26 -> V_27 ;
struct V_49 * V_9 = V_7 -> V_9 ;
T_4 V_30 = 0 ;
unsigned V_50 ;
T_6 V_51 ;
int V_52 ;
V_51 = * V_48 ;
F_25 ( V_9 ) ;
if ( ! F_7 ( V_7 ) ) {
V_30 = - V_53 ;
goto V_54;
} else if ( V_51 < 0 ) {
V_30 = - V_55 ;
goto V_54;
}
if ( V_51 < sizeof( struct V_56 ) ) {
struct V_56 V_57 ;
memcpy ( & V_57 , & V_9 -> V_58 , sizeof( V_9 -> V_58 ) ) ;
F_26 ( & V_57 . V_59 ) ;
F_26 ( & V_57 . V_60 ) ;
F_26 ( & V_57 . V_61 ) ;
F_26 ( & V_57 . V_62 ) ;
V_50 = sizeof( struct V_56 ) - V_51 ;
if ( V_50 > V_47 )
V_50 = V_47 ;
if ( F_27 ( V_46 , ( ( char * ) & V_57 ) + V_51 , V_50 ) ) {
V_30 = - V_63 ;
goto V_54;
}
* V_48 += V_50 ;
V_46 += V_50 ;
V_47 -= V_50 ;
V_30 += V_50 ;
}
V_51 = sizeof( struct V_56 ) ;
for ( V_52 = 0 ; V_47 && V_52 < V_9 -> V_58 . V_64 ; V_52 ++ ) {
struct V_65 * V_66 =
(struct V_65 * ) V_9 -> V_67 [ V_52 ] ;
unsigned int V_68 = F_28 ( V_66 -> V_69 ) ;
if ( * V_48 < V_51 + V_68 ) {
unsigned V_70 =
F_28 ( V_9 -> V_66 [ V_52 ] . V_71 . V_69 ) ;
V_50 = V_68 - ( * V_48 - V_51 ) ;
if ( V_50 > V_47 )
V_50 = V_47 ;
if ( V_70 > ( * V_48 - V_51 ) ) {
V_70 -= ( * V_48 - V_51 ) ;
if ( F_27 ( V_46 ,
V_9 -> V_67 [ V_52 ] + ( * V_48 - V_51 ) ,
F_29 ( V_50 , V_70 ) ) ) {
V_30 = - V_63 ;
goto V_54;
}
}
* V_48 += V_50 ;
V_46 += V_50 ;
V_47 -= V_50 ;
V_30 += V_50 ;
}
V_51 += V_68 ;
}
V_54:
F_30 ( V_9 ) ;
return V_30 ;
}
static struct V_72 * F_31 ( unsigned int V_73 )
{
struct V_72 * V_74 ;
V_74 = F_18 ( sizeof( struct V_72 ) , V_31 ) ;
if ( ! V_74 )
return NULL ;
V_74 -> V_75 = F_32 ( V_73 , V_31 ) ;
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
if ( V_74 -> V_13 == NULL )
F_14 ( V_74 -> V_75 -> V_80 ) ;
else
F_9 ( V_74 -> V_13 , & V_74 -> V_13 -> V_17 ) ;
F_14 ( V_74 -> V_75 -> V_81 ) ;
F_38 ( V_74 -> V_75 ) ;
F_6 ( V_74 -> V_82 ) ;
F_14 ( V_74 ) ;
}
static void F_39 ( struct V_72 * V_74 )
{
struct V_6 * V_7 = V_74 -> V_7 ;
unsigned long V_15 ;
F_10 ( & V_7 -> V_16 , V_15 ) ;
F_23 ( & V_74 -> V_83 , & V_7 -> V_84 ) ;
F_12 ( & V_7 -> V_16 , V_15 ) ;
}
static void F_40 ( struct V_72 * V_74 )
{
struct V_6 * V_7 = V_74 -> V_7 ;
unsigned long V_15 ;
F_10 ( & V_7 -> V_16 , V_15 ) ;
F_41 ( & V_74 -> V_83 ) ;
F_12 ( & V_7 -> V_16 , V_15 ) ;
}
static struct V_72 * F_42 ( struct V_6 * V_7 )
{
unsigned long V_15 ;
struct V_72 * V_74 = NULL ;
F_10 ( & V_7 -> V_16 , V_15 ) ;
if ( ! F_8 ( & V_7 -> V_85 ) ) {
V_74 = F_43 ( V_7 -> V_85 . V_86 , struct V_72 ,
V_83 ) ;
F_41 ( & V_74 -> V_83 ) ;
}
F_12 ( & V_7 -> V_16 , V_15 ) ;
return V_74 ;
}
static struct V_72 * F_44 ( struct V_6 * V_7 ,
void T_5 * V_87 )
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
void T_5 * V_87 , int V_89 , unsigned V_68 ,
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
F_50 ( & V_88 -> V_9 , L_7
L_8 ,
V_87 , V_97 , V_98 , V_99 , V_68 ) ;
else
F_50 ( & V_88 -> V_9 , L_7
L_9 ,
V_87 , V_97 , V_98 , V_99 , V_68 ,
V_90 ) ;
} else {
if ( V_92 == V_101 )
F_50 ( & V_88 -> V_9 , L_10
L_11 ,
V_97 , V_98 , V_99 , V_68 , V_90 ) ;
else
F_50 ( & V_88 -> V_9 , L_12
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
int V_52 , V_20 ;
V_50 = F_29 ( V_50 , V_102 ) ;
if ( ! V_100 || V_50 == 0 )
return;
if ( V_75 -> V_78 == 0 ) {
F_51 ( V_103 , L_14 , V_104 , 32 , 1 ,
V_75 -> V_80 , V_50 , 1 ) ;
return;
}
for ( V_52 = 0 ; V_52 < V_75 -> V_78 && V_50 ; V_52 ++ ) {
V_20 = ( V_50 > V_105 ) ? V_105 : V_50 ;
F_51 ( V_103 , L_14 , V_104 , 32 , 1 ,
F_37 ( & V_75 -> V_79 [ V_52 ] ) , V_20 , 1 ) ;
V_50 -= V_20 ;
}
}
static int F_53 ( T_7 T_5 * V_106 , struct V_75 * V_75 )
{
unsigned V_52 , V_50 , V_20 ;
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
V_20 = ( V_50 > V_105 ) ? V_105 : V_50 ;
if ( F_27 ( V_106 , F_37 ( & V_75 -> V_79 [ V_52 ] ) , V_20 ) )
return - V_63 ;
V_106 += V_20 ;
V_50 -= V_20 ;
}
return 0 ;
}
static void F_54 ( struct V_6 * V_7 , unsigned V_110 )
__releases( V_7 -> V_16 )
__acquires( V_7 -> V_16 )
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
V_7 -> V_115 |= ( 1 << V_110 ) ;
V_113:
F_45 (as, &ps->async_pending, asynclist) {
if ( V_74 -> V_111 == V_114 ) {
V_74 -> V_111 = 0 ;
V_75 = V_74 -> V_75 ;
F_55 ( V_75 ) ;
F_56 ( & V_7 -> V_16 ) ;
F_57 ( V_75 ) ;
F_58 ( V_75 ) ;
F_59 ( & V_7 -> V_16 ) ;
goto V_113;
}
}
}
static void V_85 ( struct V_75 * V_75 )
{
struct V_72 * V_74 = V_75 -> V_116 ;
struct V_6 * V_7 = V_74 -> V_7 ;
struct V_117 V_118 ;
struct V_76 * V_76 = NULL ;
T_8 V_119 = 0 ;
const struct V_77 * V_77 = NULL ;
int V_120 ;
F_59 ( & V_7 -> V_16 ) ;
F_60 ( & V_74 -> V_83 , & V_7 -> V_85 ) ;
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
F_63 ( & V_75 -> V_9 -> V_9 , L_15 ) ;
F_46 ( V_75 -> V_9 , V_74 -> V_87 , V_75 -> V_89 , V_75 -> V_109 ,
V_74 -> V_121 , V_127 , NULL , 0 ) ;
if ( ( V_75 -> V_128 & V_129 ) == V_130 )
F_52 ( V_75 , V_75 -> V_109 ) ;
if ( V_74 -> V_121 < 0 && V_74 -> V_110 && V_74 -> V_121 != - V_131 &&
V_74 -> V_121 != - V_132 )
F_54 ( V_7 , V_74 -> V_110 ) ;
F_64 ( & V_7 -> V_133 ) ;
F_56 ( & V_7 -> V_16 ) ;
if ( V_120 ) {
F_65 ( V_118 . V_122 , & V_118 , V_76 , V_77 , V_119 ) ;
F_34 ( V_76 ) ;
F_35 ( V_77 ) ;
}
}
static void F_66 ( struct V_6 * V_7 , struct V_134 * V_8 )
{
struct V_75 * V_75 ;
struct V_72 * V_74 ;
unsigned long V_15 ;
F_10 ( & V_7 -> V_16 , V_15 ) ;
while ( ! F_8 ( V_8 ) ) {
V_74 = F_43 ( V_8 -> V_86 , struct V_72 , V_83 ) ;
F_41 ( & V_74 -> V_83 ) ;
V_75 = V_74 -> V_75 ;
F_55 ( V_75 ) ;
F_12 ( & V_7 -> V_16 , V_15 ) ;
F_67 ( V_75 ) ;
F_58 ( V_75 ) ;
F_10 ( & V_7 -> V_16 , V_15 ) ;
}
F_12 ( & V_7 -> V_16 , V_15 ) ;
}
static void F_68 ( struct V_6 * V_7 ,
unsigned int V_135 )
{
struct V_134 * V_136 , * V_137 , V_138 ;
unsigned long V_15 ;
F_20 ( & V_138 ) ;
F_10 ( & V_7 -> V_16 , V_15 ) ;
F_69 (p, q, &ps->async_pending)
if ( V_135 == F_43 ( V_136 , struct V_72 , V_83 ) -> V_135 )
F_60 ( V_136 , & V_138 ) ;
F_12 ( & V_7 -> V_16 , V_15 ) ;
F_66 ( V_7 , & V_138 ) ;
}
static void F_70 ( struct V_6 * V_7 )
{
F_66 ( V_7 , & V_7 -> V_84 ) ;
}
static int F_71 ( struct V_139 * V_140 ,
const struct V_141 * V_142 )
{
return - V_53 ;
}
static void F_72 ( struct V_139 * V_140 )
{
struct V_6 * V_7 = F_73 ( V_140 ) ;
unsigned int V_135 = V_140 -> V_143 -> V_71 . V_144 ;
if ( ! V_7 )
return;
if ( F_74 ( V_135 < 8 * sizeof( V_7 -> V_145 ) ) )
F_75 ( V_135 , & V_7 -> V_145 ) ;
else
F_76 ( & V_140 -> V_9 , L_16 ,
V_135 ) ;
F_77 ( V_140 , NULL ) ;
F_68 ( V_7 , V_135 ) ;
}
static int F_78 ( struct V_139 * V_140 , T_9 V_146 )
{
return 0 ;
}
static int F_79 ( struct V_139 * V_140 )
{
return 0 ;
}
static int F_80 ( struct V_6 * V_7 , unsigned int V_135 )
{
struct V_49 * V_9 = V_7 -> V_9 ;
struct V_139 * V_140 ;
int V_54 ;
if ( V_135 >= 8 * sizeof( V_7 -> V_145 ) )
return - V_55 ;
if ( F_81 ( V_135 , & V_7 -> V_145 ) )
return 0 ;
if ( V_7 -> V_147 &&
! F_81 ( V_135 , & V_7 -> V_148 ) )
return - V_149 ;
V_140 = F_82 ( V_9 , V_135 ) ;
if ( ! V_140 )
V_54 = - V_132 ;
else
V_54 = F_83 ( & V_150 , V_140 , V_7 ) ;
if ( V_54 == 0 )
F_84 ( V_135 , & V_7 -> V_145 ) ;
return V_54 ;
}
static int F_85 ( struct V_6 * V_7 , unsigned int V_135 )
{
struct V_49 * V_9 ;
struct V_139 * V_140 ;
int V_54 ;
V_54 = - V_55 ;
if ( V_135 >= 8 * sizeof( V_7 -> V_145 ) )
return V_54 ;
V_9 = V_7 -> V_9 ;
V_140 = F_82 ( V_9 , V_135 ) ;
if ( ! V_140 )
V_54 = - V_132 ;
else if ( F_86 ( V_135 , & V_7 -> V_145 ) ) {
F_87 ( & V_150 , V_140 ) ;
V_54 = 0 ;
}
return V_54 ;
}
static int F_88 ( struct V_6 * V_7 , unsigned int V_135 )
{
if ( V_7 -> V_9 -> V_10 != V_151 )
return - V_152 ;
if ( V_135 >= 8 * sizeof( V_7 -> V_145 ) )
return - V_55 ;
if ( F_81 ( V_135 , & V_7 -> V_145 ) )
return 0 ;
F_76 ( & V_7 -> V_9 -> V_9 , L_17
L_18 , F_89 ( V_153 ) ,
V_153 -> V_154 , V_135 ) ;
return F_80 ( V_7 , V_135 ) ;
}
static int F_90 ( struct V_49 * V_9 , unsigned int V_97 )
{
unsigned int V_52 , V_155 , V_156 ;
struct V_139 * V_140 ;
struct V_157 * V_158 ;
struct V_159 * V_160 ;
if ( V_97 & ~ ( V_161 | 0xf ) )
return - V_55 ;
if ( ! V_9 -> V_162 )
return - V_163 ;
for ( V_52 = 0 ; V_52 < V_9 -> V_162 -> V_71 . V_164 ; V_52 ++ ) {
V_140 = V_9 -> V_162 -> V_165 [ V_52 ] ;
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
static int F_91 ( struct V_6 * V_7 , unsigned int V_170 ,
unsigned int V_171 , unsigned int V_172 )
{
int V_30 = 0 ;
struct V_157 * V_173 ;
if ( V_7 -> V_9 -> V_10 != V_174
&& V_7 -> V_9 -> V_10 != V_175
&& V_7 -> V_9 -> V_10 != V_151 )
return - V_152 ;
if ( V_176 == ( V_177 & V_170 ) )
return 0 ;
if ( V_170 == 0xa1 && V_171 == 0 ) {
V_173 = F_92 ( V_7 -> V_9 -> V_162 ,
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
V_30 = F_90 ( V_7 -> V_9 , V_172 ) ;
if ( V_30 < 0 ) {
V_30 = F_90 ( V_7 -> V_9 , V_172 ^ 0x80 ) ;
if ( V_30 >= 0 )
F_50 ( & V_7 -> V_9 -> V_9 ,
L_19 ,
V_182 , F_89 ( V_153 ) ,
V_153 -> V_154 , V_172 , V_172 ^ 0x80 ) ;
}
if ( V_30 >= 0 )
V_30 = F_88 ( V_7 , V_30 ) ;
break;
case V_183 :
V_30 = F_88 ( V_7 , V_172 ) ;
break;
}
return V_30 ;
}
static struct V_184 * F_93 ( struct V_49 * V_9 ,
unsigned char V_97 )
{
if ( V_97 & V_185 )
return V_9 -> V_186 [ V_97 & V_187 ] ;
else
return V_9 -> V_188 [ V_97 & V_187 ] ;
}
static int F_94 ( struct V_6 * V_7 ,
struct V_189 T_5 * V_190 ,
unsigned int * V_191 ,
unsigned int * V_192 ,
struct V_184 * * * V_193 ,
struct V_139 * * V_194 )
{
unsigned int V_52 , V_195 , V_196 ;
struct V_184 * * V_197 ;
struct V_139 * V_140 = NULL ;
unsigned char V_97 ;
int V_135 , V_30 ;
if ( F_95 ( V_195 , & V_190 -> V_195 ) ||
F_95 ( V_196 , & V_190 -> V_196 ) )
return - V_63 ;
if ( V_196 < 1 || V_196 > V_198 )
return - V_55 ;
if ( V_191 && ( V_195 < 2 || V_195 > 65536 ) )
return - V_55 ;
V_197 = F_96 ( V_196 * sizeof( * V_197 ) , V_31 ) ;
if ( ! V_197 )
return - V_5 ;
for ( V_52 = 0 ; V_52 < V_196 ; V_52 ++ ) {
if ( F_95 ( V_97 , & V_190 -> V_197 [ V_52 ] ) ) {
V_30 = - V_63 ;
goto error;
}
V_197 [ V_52 ] = F_93 ( V_7 -> V_9 , V_97 ) ;
if ( ! V_197 [ V_52 ] ) {
V_30 = - V_55 ;
goto error;
}
V_135 = F_90 ( V_7 -> V_9 , V_97 ) ;
if ( V_135 < 0 ) {
V_30 = V_135 ;
goto error;
}
if ( V_52 == 0 ) {
V_30 = F_88 ( V_7 , V_135 ) ;
if ( V_30 < 0 )
goto error;
V_140 = F_82 ( V_7 -> V_9 , V_135 ) ;
} else {
if ( V_135 != V_140 -> V_143 -> V_71 . V_144 ) {
V_30 = - V_55 ;
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
return V_30 ;
}
static int F_97 ( struct V_199 * V_9 , void * V_93 )
{
return V_9 -> V_200 == ( V_201 ) ( unsigned long ) V_93 ;
}
static struct V_49 * F_98 ( V_201 V_200 )
{
struct V_199 * V_9 ;
V_9 = F_99 ( & V_202 , NULL ,
( void * ) ( unsigned long ) V_200 , F_97 ) ;
if ( ! V_9 )
return NULL ;
return F_100 ( V_9 ) ;
}
static int F_101 ( struct V_203 * V_203 , struct V_26 * V_26 )
{
struct V_49 * V_9 = NULL ;
struct V_6 * V_7 ;
int V_30 ;
V_30 = - V_5 ;
V_7 = F_18 ( sizeof( struct V_6 ) , V_31 ) ;
if ( ! V_7 )
goto V_204;
V_30 = - V_53 ;
F_102 ( & V_205 ) ;
if ( F_103 ( V_203 ) == V_206 )
V_9 = F_98 ( V_203 -> V_207 ) ;
F_104 ( & V_205 ) ;
if ( ! V_9 )
goto V_204;
F_25 ( V_9 ) ;
if ( V_9 -> V_10 == V_11 )
goto V_208;
V_30 = F_105 ( V_9 ) ;
if ( V_30 )
goto V_208;
V_7 -> V_9 = V_9 ;
V_7 -> V_26 = V_26 ;
V_7 -> V_148 = 0xFFFFFFFF ;
F_106 ( & V_7 -> V_16 ) ;
F_20 ( & V_7 -> V_8 ) ;
F_20 ( & V_7 -> V_84 ) ;
F_20 ( & V_7 -> V_85 ) ;
F_20 ( & V_7 -> V_45 ) ;
F_107 ( & V_7 -> V_133 ) ;
V_7 -> V_209 = F_61 ( F_108 ( V_153 ) ) ;
V_7 -> V_77 = F_109 () ;
F_110 ( V_153 , & V_7 -> V_119 ) ;
F_111 () ;
F_23 ( & V_7 -> V_8 , & V_9 -> V_210 ) ;
V_26 -> V_27 = V_7 ;
F_30 ( V_9 ) ;
F_63 ( & V_9 -> V_9 , L_20 , F_89 ( V_153 ) ,
V_153 -> V_154 ) ;
return V_30 ;
V_208:
F_30 ( V_9 ) ;
F_112 ( V_9 ) ;
V_204:
F_14 ( V_7 ) ;
return V_30 ;
}
static int F_113 ( struct V_203 * V_203 , struct V_26 * V_26 )
{
struct V_6 * V_7 = V_26 -> V_27 ;
struct V_49 * V_9 = V_7 -> V_9 ;
unsigned int V_135 ;
struct V_72 * V_74 ;
F_25 ( V_9 ) ;
F_114 ( V_9 , V_7 ) ;
F_41 ( & V_7 -> V_8 ) ;
for ( V_135 = 0 ; V_7 -> V_145 && V_135 < 8 * sizeof( V_7 -> V_145 ) ;
V_135 ++ ) {
if ( F_81 ( V_135 , & V_7 -> V_145 ) )
F_85 ( V_7 , V_135 ) ;
}
F_70 ( V_7 ) ;
F_115 ( V_9 ) ;
F_30 ( V_9 ) ;
F_112 ( V_9 ) ;
F_34 ( V_7 -> V_209 ) ;
F_35 ( V_7 -> V_77 ) ;
V_74 = F_42 ( V_7 ) ;
while ( V_74 ) {
F_33 ( V_74 ) ;
V_74 = F_42 ( V_7 ) ;
}
F_14 ( V_7 ) ;
return 0 ;
}
static int F_116 ( struct V_6 * V_7 , void T_5 * V_211 )
{
struct V_49 * V_9 = V_7 -> V_9 ;
struct V_212 V_213 ;
unsigned int V_214 ;
unsigned char * V_215 ;
unsigned V_216 ;
int V_52 , V_89 , V_30 ;
if ( F_117 ( & V_213 , V_211 , sizeof( V_213 ) ) )
return - V_63 ;
V_30 = F_91 ( V_7 , V_213 . V_217 , V_213 . V_218 ,
V_213 . V_219 ) ;
if ( V_30 )
return V_30 ;
V_216 = V_213 . V_216 ;
if ( V_216 > V_220 )
return - V_55 ;
V_30 = F_1 ( V_220 + sizeof( struct V_75 ) +
sizeof( struct V_221 ) ) ;
if ( V_30 )
return V_30 ;
V_215 = ( unsigned char * ) F_118 ( V_31 ) ;
if ( ! V_215 ) {
V_30 = - V_5 ;
goto V_222;
}
V_214 = V_213 . V_223 ;
F_63 ( & V_9 -> V_9 , L_21
L_22
L_23 ,
V_213 . V_217 , V_213 . V_218 , V_213 . V_224 ,
V_213 . V_219 , V_213 . V_216 ) ;
if ( V_213 . V_217 & 0x80 ) {
if ( V_213 . V_216 && ! F_119 ( V_225 , V_213 . V_93 ,
V_213 . V_216 ) ) {
V_30 = - V_55 ;
goto V_222;
}
V_89 = F_120 ( V_9 , 0 ) ;
F_46 ( V_9 , NULL , V_89 , V_213 . V_216 , V_214 , V_101 , NULL , 0 ) ;
F_30 ( V_9 ) ;
V_52 = F_121 ( V_9 , V_89 , V_213 . V_218 ,
V_213 . V_217 , V_213 . V_224 , V_213 . V_219 ,
V_215 , V_213 . V_216 , V_214 ) ;
F_25 ( V_9 ) ;
F_46 ( V_9 , NULL , V_89 , F_122 ( V_52 , 0 ) , F_29 ( V_52 , 0 ) , V_127 ,
V_215 , F_122 ( V_52 , 0 ) ) ;
if ( ( V_52 > 0 ) && V_213 . V_216 ) {
if ( F_27 ( V_213 . V_93 , V_215 , V_52 ) ) {
V_30 = - V_63 ;
goto V_222;
}
}
} else {
if ( V_213 . V_216 ) {
if ( F_117 ( V_215 , V_213 . V_93 , V_213 . V_216 ) ) {
V_30 = - V_63 ;
goto V_222;
}
}
V_89 = F_123 ( V_9 , 0 ) ;
F_46 ( V_9 , NULL , V_89 , V_213 . V_216 , V_214 , V_101 ,
V_215 , V_213 . V_216 ) ;
F_30 ( V_9 ) ;
V_52 = F_121 ( V_9 , F_123 ( V_9 , 0 ) , V_213 . V_218 ,
V_213 . V_217 , V_213 . V_224 , V_213 . V_219 ,
V_215 , V_213 . V_216 , V_214 ) ;
F_25 ( V_9 ) ;
F_46 ( V_9 , NULL , V_89 , F_122 ( V_52 , 0 ) , F_29 ( V_52 , 0 ) , V_127 , NULL , 0 ) ;
}
if ( V_52 < 0 && V_52 != - V_226 ) {
F_124 ( V_103 , & V_9 -> V_9 , L_24
L_25 ,
V_153 -> V_154 , V_213 . V_217 , V_213 . V_218 ,
V_213 . V_216 , V_52 ) ;
}
V_30 = V_52 ;
V_222:
F_125 ( ( unsigned long ) V_215 ) ;
F_6 ( V_220 + sizeof( struct V_75 ) +
sizeof( struct V_221 ) ) ;
return V_30 ;
}
static int F_126 ( struct V_6 * V_7 , void T_5 * V_211 )
{
struct V_49 * V_9 = V_7 -> V_9 ;
struct V_227 V_228 ;
unsigned int V_214 , V_229 , V_89 ;
int V_230 ;
unsigned char * V_215 ;
int V_52 , V_30 ;
if ( F_117 ( & V_228 , V_211 , sizeof( V_228 ) ) )
return - V_63 ;
V_30 = F_90 ( V_7 -> V_9 , V_228 . V_97 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_88 ( V_7 , V_30 ) ;
if ( V_30 )
return V_30 ;
if ( V_228 . V_97 & V_161 )
V_89 = F_127 ( V_9 , V_228 . V_97 & 0x7f ) ;
else
V_89 = F_128 ( V_9 , V_228 . V_97 & 0x7f ) ;
if ( ! F_129 ( V_9 , V_89 , ! ( V_228 . V_97 & V_161 ) ) )
return - V_55 ;
V_229 = V_228 . V_50 ;
if ( V_229 >= ( V_231 - sizeof( struct V_75 ) ) )
return - V_55 ;
V_30 = F_1 ( V_229 + sizeof( struct V_75 ) ) ;
if ( V_30 )
return V_30 ;
V_215 = F_96 ( V_229 , V_31 ) ;
if ( ! V_215 ) {
V_30 = - V_5 ;
goto V_222;
}
V_214 = V_228 . V_223 ;
if ( V_228 . V_97 & 0x80 ) {
if ( V_229 && ! F_119 ( V_225 , V_228 . V_93 , V_229 ) ) {
V_30 = - V_55 ;
goto V_222;
}
F_46 ( V_9 , NULL , V_89 , V_229 , V_214 , V_101 , NULL , 0 ) ;
F_30 ( V_9 ) ;
V_52 = F_130 ( V_9 , V_89 , V_215 , V_229 , & V_230 , V_214 ) ;
F_25 ( V_9 ) ;
F_46 ( V_9 , NULL , V_89 , V_230 , V_52 , V_127 , V_215 , V_230 ) ;
if ( ! V_52 && V_230 ) {
if ( F_27 ( V_228 . V_93 , V_215 , V_230 ) ) {
V_30 = - V_63 ;
goto V_222;
}
}
} else {
if ( V_229 ) {
if ( F_117 ( V_215 , V_228 . V_93 , V_229 ) ) {
V_30 = - V_63 ;
goto V_222;
}
}
F_46 ( V_9 , NULL , V_89 , V_229 , V_214 , V_101 , V_215 , V_229 ) ;
F_30 ( V_9 ) ;
V_52 = F_130 ( V_9 , V_89 , V_215 , V_229 , & V_230 , V_214 ) ;
F_25 ( V_9 ) ;
F_46 ( V_9 , NULL , V_89 , V_230 , V_52 , V_127 , NULL , 0 ) ;
}
V_30 = ( V_52 < 0 ? V_52 : V_230 ) ;
V_222:
F_14 ( V_215 ) ;
F_6 ( V_229 + sizeof( struct V_75 ) ) ;
return V_30 ;
}
static void F_131 ( struct V_49 * V_88 ,
unsigned int V_232 , char * V_233 )
{
struct V_184 * * V_197 ;
struct V_184 * V_97 ;
V_197 = ( V_232 & V_161 ) ? V_88 -> V_186 : V_88 -> V_188 ;
V_97 = V_197 [ V_232 & 0x0f ] ;
if ( V_97 && ! F_8 ( & V_97 -> V_234 ) )
F_76 ( & V_88 -> V_9 , L_26 ,
F_89 ( V_153 ) , V_153 -> V_154 ,
V_233 , V_232 ) ;
}
static int F_132 ( struct V_6 * V_7 , void T_5 * V_211 )
{
unsigned int V_97 ;
int V_30 ;
if ( F_95 ( V_97 , ( unsigned int T_5 * ) V_211 ) )
return - V_63 ;
V_30 = F_90 ( V_7 -> V_9 , V_97 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_88 ( V_7 , V_30 ) ;
if ( V_30 )
return V_30 ;
F_131 ( V_7 -> V_9 , V_97 , L_27 ) ;
F_133 ( V_7 -> V_9 , V_97 ) ;
return 0 ;
}
static int F_134 ( struct V_6 * V_7 , void T_5 * V_211 )
{
unsigned int V_97 ;
int V_89 ;
int V_30 ;
if ( F_95 ( V_97 , ( unsigned int T_5 * ) V_211 ) )
return - V_63 ;
V_30 = F_90 ( V_7 -> V_9 , V_97 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_88 ( V_7 , V_30 ) ;
if ( V_30 )
return V_30 ;
F_131 ( V_7 -> V_9 , V_97 , L_28 ) ;
if ( V_97 & V_161 )
V_89 = F_127 ( V_7 -> V_9 , V_97 & 0x7f ) ;
else
V_89 = F_128 ( V_7 -> V_9 , V_97 & 0x7f ) ;
return F_135 ( V_7 -> V_9 , V_89 ) ;
}
static int F_136 ( struct V_6 * V_7 , void T_5 * V_211 )
{
struct V_235 V_236 ;
struct V_139 * V_140 ;
int V_30 ;
if ( F_117 ( & V_236 , V_211 , sizeof( V_236 ) ) )
return - V_63 ;
V_140 = F_82 ( V_7 -> V_9 , V_236 . V_165 ) ;
if ( ! V_140 || ! V_140 -> V_9 . V_237 )
V_30 = - V_238 ;
else {
F_137 ( V_236 . V_237 , V_140 -> V_9 . V_237 -> V_239 ,
sizeof( V_236 . V_237 ) ) ;
V_30 = ( F_27 ( V_211 , & V_236 , sizeof( V_236 ) ) ? - V_63 : 0 ) ;
}
return V_30 ;
}
static int F_138 ( struct V_6 * V_7 , void T_5 * V_211 )
{
struct V_240 V_241 ;
memset ( & V_241 , 0 , sizeof( V_241 ) ) ;
V_241 . V_242 = V_7 -> V_9 -> V_242 ;
V_241 . V_243 = V_7 -> V_9 -> V_244 == V_245 ;
if ( F_27 ( V_211 , & V_241 , sizeof( V_241 ) ) )
return - V_63 ;
return 0 ;
}
static int F_139 ( struct V_6 * V_7 )
{
struct V_246 * V_162 = V_7 -> V_9 -> V_162 ;
struct V_139 * V_165 ;
int V_52 , V_247 ;
if ( V_7 -> V_147 && V_162 ) {
for ( V_52 = 0 ; V_52 < V_162 -> V_71 . V_164 ; ++ V_52 ) {
V_165 = V_162 -> V_165 [ V_52 ] ;
V_247 = V_165 -> V_248 -> V_71 . V_144 ;
if ( F_140 ( V_165 ) &&
! F_81 ( V_247 , & V_7 -> V_145 ) ) {
F_76 ( & V_7 -> V_9 -> V_9 ,
L_29 ,
V_247 , V_165 -> V_9 . V_237 -> V_239 , V_153 -> V_154 ) ;
return - V_149 ;
}
}
}
return F_141 ( V_7 -> V_9 ) ;
}
static int F_142 ( struct V_6 * V_7 , void T_5 * V_211 )
{
struct V_249 V_250 ;
int V_30 ;
if ( F_117 ( & V_250 , V_211 , sizeof( V_250 ) ) )
return - V_63 ;
V_30 = F_88 ( V_7 , V_250 . V_165 ) ;
if ( V_30 )
return V_30 ;
F_68 ( V_7 , V_250 . V_165 ) ;
return F_143 ( V_7 -> V_9 , V_250 . V_165 ,
V_250 . V_143 ) ;
}
static int F_144 ( struct V_6 * V_7 , void T_5 * V_211 )
{
int V_251 ;
int V_121 = 0 ;
struct V_246 * V_162 ;
if ( F_95 ( V_251 , ( int T_5 * ) V_211 ) )
return - V_63 ;
V_162 = V_7 -> V_9 -> V_162 ;
if ( V_162 ) {
int V_52 ;
for ( V_52 = 0 ; V_52 < V_162 -> V_71 . V_164 ; ++ V_52 ) {
if ( F_140 ( V_162 -> V_165 [ V_52 ] ) ) {
F_76 ( & V_7 -> V_9 -> V_9 ,
L_30
L_31 ,
V_162 -> V_165 [ V_52 ]
-> V_248
-> V_71 . V_144 ,
V_162 -> V_165 [ V_52 ]
-> V_9 . V_237 -> V_239 ,
V_153 -> V_154 , V_251 ) ;
V_121 = - V_252 ;
break;
}
}
}
if ( V_121 == 0 ) {
if ( V_162 && V_162 -> V_71 . V_253 == V_251 )
V_121 = F_145 ( V_7 -> V_9 ) ;
else
V_121 = F_146 ( V_7 -> V_9 , V_251 ) ;
}
return V_121 ;
}
static struct V_12 *
F_147 ( struct V_6 * V_7 , const struct V_254 * V_255 )
{
struct V_12 * V_13 = NULL , * V_256 ;
unsigned long V_15 ;
unsigned long V_257 = ( unsigned long ) V_255 -> V_258 ;
F_10 ( & V_7 -> V_16 , V_15 ) ;
F_45 (iter, &ps->memory_list, memlist) {
if ( V_257 >= V_256 -> V_29 &&
V_257 < V_256 -> V_29 + V_256 -> V_20 ) {
if ( V_255 -> V_259 > V_256 -> V_29 + V_256 -> V_20 -
V_257 ) {
V_13 = F_148 ( - V_55 ) ;
} else {
V_13 = V_256 ;
V_13 -> V_17 ++ ;
}
break;
}
}
F_12 ( & V_7 -> V_16 , V_15 ) ;
return V_13 ;
}
static int F_149 ( struct V_6 * V_7 , struct V_254 * V_255 ,
struct V_260 T_5 * V_261 ,
void T_5 * V_211 )
{
struct V_260 * V_262 = NULL ;
struct V_184 * V_97 ;
struct V_72 * V_74 = NULL ;
struct V_221 * V_263 = NULL ;
unsigned int V_251 , V_264 , V_265 ;
int V_52 , V_30 , V_266 , V_78 = 0 , V_135 = - 1 ;
int V_107 = 0 ;
unsigned int V_267 = 0 ;
void * V_46 ;
if ( V_255 -> V_15 & ~ ( V_268 |
V_269 |
V_270 |
V_271 |
V_272 |
V_273 ) )
return - V_55 ;
if ( ( unsigned int ) V_255 -> V_259 >= V_274 )
return - V_55 ;
if ( V_255 -> V_259 > 0 && ! V_255 -> V_258 )
return - V_55 ;
if ( ! ( V_255 -> type == V_275 &&
( V_255 -> V_168 & ~ V_185 ) == 0 ) ) {
V_135 = F_90 ( V_7 -> V_9 , V_255 -> V_168 ) ;
if ( V_135 < 0 )
return V_135 ;
V_30 = F_88 ( V_7 , V_135 ) ;
if ( V_30 )
return V_30 ;
}
V_97 = F_93 ( V_7 -> V_9 , V_255 -> V_168 ) ;
if ( ! V_97 )
return - V_132 ;
V_266 = ( V_255 -> V_168 & V_185 ) != 0 ;
V_251 = 0 ;
switch ( V_255 -> type ) {
case V_275 :
if ( ! F_150 ( & V_97 -> V_71 ) )
return - V_55 ;
if ( V_255 -> V_259 < 8 )
return - V_55 ;
V_263 = F_96 ( sizeof( struct V_221 ) , V_31 ) ;
if ( ! V_263 )
return - V_5 ;
if ( F_117 ( V_263 , V_255 -> V_258 , 8 ) ) {
V_30 = - V_63 ;
goto error;
}
if ( V_255 -> V_259 < ( F_151 ( & V_263 -> V_216 ) + 8 ) ) {
V_30 = - V_55 ;
goto error;
}
V_30 = F_91 ( V_7 , V_263 -> V_217 , V_263 -> V_218 ,
F_151 ( & V_263 -> V_219 ) ) ;
if ( V_30 )
goto error;
V_255 -> V_259 = F_151 ( & V_263 -> V_216 ) ;
V_255 -> V_258 += 8 ;
if ( ( V_263 -> V_217 & V_161 ) && V_255 -> V_259 ) {
V_266 = 1 ;
V_255 -> V_168 |= V_161 ;
} else {
V_266 = 0 ;
V_255 -> V_168 &= ~ V_161 ;
}
F_63 ( & V_7 -> V_9 -> V_9 , L_21
L_22
L_23 ,
V_263 -> V_217 , V_263 -> V_218 ,
F_152 ( & V_263 -> V_224 ) ,
F_152 ( & V_263 -> V_219 ) ,
F_152 ( & V_263 -> V_216 ) ) ;
V_251 = sizeof( struct V_221 ) ;
break;
case V_276 :
switch ( F_153 ( & V_97 -> V_71 ) ) {
case V_277 :
case V_278 :
return - V_55 ;
case V_279 :
V_255 -> type = V_280 ;
goto V_281;
}
V_78 = F_154 ( V_255 -> V_259 , V_105 ) ;
if ( V_78 == 1 || V_78 > V_7 -> V_9 -> V_282 -> V_283 )
V_78 = 0 ;
if ( V_97 -> V_190 )
V_267 = V_255 -> V_267 ;
break;
case V_280 :
if ( ! F_155 ( & V_97 -> V_71 ) )
return - V_55 ;
V_281:
break;
case V_284 :
if ( V_255 -> V_107 < 1 ||
V_255 -> V_107 > 128 )
return - V_55 ;
if ( ! F_156 ( & V_97 -> V_71 ) )
return - V_55 ;
V_107 = V_255 -> V_107 ;
V_265 = sizeof( struct V_260 ) *
V_107 ;
V_262 = F_157 ( V_261 , V_265 ) ;
if ( F_158 ( V_262 ) ) {
V_30 = F_159 ( V_262 ) ;
V_262 = NULL ;
goto error;
}
for ( V_264 = V_251 = 0 ; V_251 < V_107 ; V_251 ++ ) {
if ( V_262 [ V_251 ] . V_68 > 49152 ) {
V_30 = - V_55 ;
goto error;
}
V_264 += V_262 [ V_251 ] . V_68 ;
}
V_251 *= sizeof( struct V_285 ) ;
V_255 -> V_259 = V_264 ;
break;
default:
return - V_55 ;
}
if ( V_255 -> V_259 > 0 &&
! F_119 ( V_266 ? V_225 : V_286 ,
V_255 -> V_258 , V_255 -> V_259 ) ) {
V_30 = - V_63 ;
goto error;
}
V_74 = F_31 ( V_107 ) ;
if ( ! V_74 ) {
V_30 = - V_5 ;
goto error;
}
V_74 -> V_13 = F_147 ( V_7 , V_255 ) ;
if ( F_158 ( V_74 -> V_13 ) ) {
V_30 = F_159 ( V_74 -> V_13 ) ;
V_74 -> V_13 = NULL ;
goto error;
}
if ( V_74 -> V_13 )
V_78 = 0 ;
V_251 += sizeof( struct V_72 ) + sizeof( struct V_75 ) + V_255 -> V_259 +
V_78 * sizeof( struct V_287 ) ;
V_30 = F_1 ( V_251 ) ;
if ( V_30 )
goto error;
V_74 -> V_82 = V_251 ;
if ( V_78 ) {
V_74 -> V_75 -> V_79 = F_96 ( V_78 * sizeof( struct V_287 ) ,
V_31 ) ;
if ( ! V_74 -> V_75 -> V_79 ) {
V_30 = - V_5 ;
goto error;
}
V_74 -> V_75 -> V_78 = V_78 ;
F_160 ( V_74 -> V_75 -> V_79 , V_74 -> V_75 -> V_78 ) ;
V_264 = V_255 -> V_259 ;
for ( V_52 = 0 ; V_52 < V_74 -> V_75 -> V_78 ; V_52 ++ ) {
V_251 = ( V_264 > V_105 ) ? V_105 : V_264 ;
V_46 = F_96 ( V_251 , V_31 ) ;
if ( ! V_46 ) {
V_30 = - V_5 ;
goto error;
}
F_161 ( & V_74 -> V_75 -> V_79 [ V_52 ] , V_46 , V_251 ) ;
if ( ! V_266 ) {
if ( F_117 ( V_46 , V_255 -> V_258 , V_251 ) ) {
V_30 = - V_63 ;
goto error;
}
V_255 -> V_258 += V_251 ;
}
V_264 -= V_251 ;
}
} else if ( V_255 -> V_259 > 0 ) {
if ( V_74 -> V_13 ) {
unsigned long V_257 = ( unsigned long ) V_255 -> V_258 ;
V_74 -> V_75 -> V_80 = V_74 -> V_13 -> V_21 +
( V_257 - V_74 -> V_13 -> V_29 ) ;
} else {
V_74 -> V_75 -> V_80 = F_96 ( V_255 -> V_259 ,
V_31 ) ;
if ( ! V_74 -> V_75 -> V_80 ) {
V_30 = - V_5 ;
goto error;
}
if ( ! V_266 ) {
if ( F_117 ( V_74 -> V_75 -> V_80 ,
V_255 -> V_258 ,
V_255 -> V_259 ) ) {
V_30 = - V_63 ;
goto error;
}
} else if ( V_255 -> type == V_284 ) {
memset ( V_74 -> V_75 -> V_80 , 0 ,
V_255 -> V_259 ) ;
}
}
}
V_74 -> V_75 -> V_9 = V_7 -> V_9 ;
V_74 -> V_75 -> V_89 = ( V_255 -> type << 30 ) |
F_162 ( V_7 -> V_9 , V_255 -> V_168 & 0xf ) |
( V_255 -> V_168 & V_161 ) ;
V_251 = ( V_266 ? V_130 : V_288 ) ;
if ( V_255 -> V_15 & V_268 )
V_251 |= V_289 ;
if ( V_255 -> V_15 & V_269 && V_266 )
V_251 |= V_290 ;
if ( V_255 -> V_15 & V_271 )
V_251 |= V_291 ;
if ( V_255 -> V_15 & V_272 )
V_251 |= V_292 ;
if ( V_255 -> V_15 & V_273 )
V_251 |= V_293 ;
V_74 -> V_75 -> V_128 = V_251 ;
V_74 -> V_75 -> V_108 = V_255 -> V_259 ;
V_74 -> V_75 -> V_81 = ( unsigned char * ) V_263 ;
V_263 = NULL ;
V_74 -> V_75 -> V_294 = V_255 -> V_294 ;
V_74 -> V_75 -> V_107 = V_107 ;
V_74 -> V_75 -> V_267 = V_267 ;
if ( V_97 -> V_71 . V_295 ) {
if ( V_255 -> type == V_284 ||
V_7 -> V_9 -> V_244 == V_296 ||
V_7 -> V_9 -> V_244 >= V_297 )
V_74 -> V_75 -> V_298 = 1 <<
F_29 ( 15 , V_97 -> V_71 . V_295 - 1 ) ;
else
V_74 -> V_75 -> V_298 = V_97 -> V_71 . V_295 ;
}
V_74 -> V_75 -> V_116 = V_74 ;
V_74 -> V_75 -> V_299 = V_85 ;
for ( V_264 = V_251 = 0 ; V_251 < V_107 ; V_251 ++ ) {
V_74 -> V_75 -> V_261 [ V_251 ] . V_300 = V_264 ;
V_74 -> V_75 -> V_261 [ V_251 ] . V_68 = V_262 [ V_251 ] . V_68 ;
V_264 += V_262 [ V_251 ] . V_68 ;
}
F_14 ( V_262 ) ;
V_262 = NULL ;
V_74 -> V_7 = V_7 ;
V_74 -> V_87 = V_211 ;
if ( V_74 -> V_13 ) {
unsigned long V_257 = ( unsigned long ) V_255 -> V_258 ;
V_74 -> V_75 -> V_128 |= V_301 ;
V_74 -> V_75 -> V_302 = V_74 -> V_13 -> V_22 +
( V_257 - V_74 -> V_13 -> V_29 ) ;
} else if ( V_266 && V_255 -> V_259 > 0 )
V_74 -> V_106 = V_255 -> V_258 ;
V_74 -> V_120 = V_255 -> V_120 ;
V_74 -> V_135 = V_135 ;
V_74 -> V_76 = F_61 ( F_108 ( V_153 ) ) ;
V_74 -> V_77 = F_109 () ;
F_110 ( V_153 , & V_74 -> V_119 ) ;
F_46 ( V_7 -> V_9 , V_74 -> V_87 , V_74 -> V_75 -> V_89 ,
V_74 -> V_75 -> V_108 , 0 , V_101 ,
NULL , 0 ) ;
if ( ! V_266 )
F_52 ( V_74 -> V_75 , V_74 -> V_75 -> V_108 ) ;
F_39 ( V_74 ) ;
if ( F_163 ( & V_97 -> V_71 ) ) {
F_164 ( & V_7 -> V_16 ) ;
V_74 -> V_110 = F_165 ( & V_97 -> V_71 ) |
( ( V_97 -> V_71 . V_169 & V_185 )
>> 3 ) ;
if ( V_255 -> V_15 & V_270 )
V_74 -> V_111 = V_112 ;
else
V_7 -> V_115 &= ~ ( 1 << V_74 -> V_110 ) ;
if ( V_7 -> V_115 & ( 1 << V_74 -> V_110 ) )
V_30 = - V_303 ;
else
V_30 = F_166 ( V_74 -> V_75 , V_304 ) ;
F_167 ( & V_7 -> V_16 ) ;
} else {
V_30 = F_166 ( V_74 -> V_75 , V_31 ) ;
}
if ( V_30 ) {
F_124 ( V_103 , & V_7 -> V_9 -> V_9 ,
L_32 , V_30 ) ;
F_46 ( V_7 -> V_9 , V_74 -> V_87 , V_74 -> V_75 -> V_89 ,
0 , V_30 , V_127 , NULL , 0 ) ;
F_40 ( V_74 ) ;
goto error;
}
return 0 ;
error:
if ( V_74 && V_74 -> V_13 )
F_9 ( V_74 -> V_13 , & V_74 -> V_13 -> V_17 ) ;
F_14 ( V_262 ) ;
F_14 ( V_263 ) ;
if ( V_74 )
F_33 ( V_74 ) ;
return V_30 ;
}
static int F_168 ( struct V_6 * V_7 , void T_5 * V_211 )
{
struct V_254 V_255 ;
if ( F_117 ( & V_255 , V_211 , sizeof( V_255 ) ) )
return - V_63 ;
return F_149 ( V_7 , & V_255 ,
( ( (struct V_254 T_5 * ) V_211 ) -> V_261 ) ,
V_211 ) ;
}
static int F_169 ( struct V_6 * V_7 , void T_5 * V_211 )
{
struct V_75 * V_75 ;
struct V_72 * V_74 ;
unsigned long V_15 ;
F_10 ( & V_7 -> V_16 , V_15 ) ;
V_74 = F_44 ( V_7 , V_211 ) ;
if ( ! V_74 ) {
F_12 ( & V_7 -> V_16 , V_15 ) ;
return - V_55 ;
}
V_75 = V_74 -> V_75 ;
F_55 ( V_75 ) ;
F_12 ( & V_7 -> V_16 , V_15 ) ;
F_67 ( V_75 ) ;
F_58 ( V_75 ) ;
return 0 ;
}
static int F_170 ( struct V_72 * V_74 , void T_5 * T_5 * V_211 )
{
struct V_75 * V_75 = V_74 -> V_75 ;
struct V_254 T_5 * V_87 = V_74 -> V_87 ;
void T_5 * V_305 = V_74 -> V_87 ;
unsigned int V_52 ;
if ( V_74 -> V_106 && V_75 -> V_109 ) {
if ( F_53 ( V_74 -> V_106 , V_75 ) )
goto V_306;
}
if ( F_171 ( V_74 -> V_121 , & V_87 -> V_121 ) )
goto V_306;
if ( F_171 ( V_75 -> V_109 , & V_87 -> V_109 ) )
goto V_306;
if ( F_171 ( V_75 -> V_307 , & V_87 -> V_307 ) )
goto V_306;
if ( F_156 ( & V_75 -> V_97 -> V_71 ) ) {
for ( V_52 = 0 ; V_52 < V_75 -> V_107 ; V_52 ++ ) {
if ( F_171 ( V_75 -> V_261 [ V_52 ] . V_109 ,
& V_87 -> V_261 [ V_52 ] . V_109 ) )
goto V_306;
if ( F_171 ( V_75 -> V_261 [ V_52 ] . V_121 ,
& V_87 -> V_261 [ V_52 ] . V_121 ) )
goto V_306;
}
}
if ( F_171 ( V_305 , ( void T_5 * T_5 * ) V_211 ) )
return - V_63 ;
return 0 ;
V_306:
return - V_63 ;
}
static struct V_72 * F_172 ( struct V_6 * V_7 )
{
F_173 ( V_133 , V_153 ) ;
struct V_72 * V_74 = NULL ;
struct V_49 * V_9 = V_7 -> V_9 ;
F_174 ( & V_7 -> V_133 , & V_133 ) ;
for (; ; ) {
F_175 ( V_308 ) ;
V_74 = F_42 ( V_7 ) ;
if ( V_74 || ! F_7 ( V_7 ) )
break;
if ( F_176 ( V_153 ) )
break;
F_30 ( V_9 ) ;
F_177 () ;
F_25 ( V_9 ) ;
}
F_178 ( & V_7 -> V_133 , & V_133 ) ;
F_179 ( V_309 ) ;
return V_74 ;
}
static int F_180 ( struct V_6 * V_7 , void T_5 * V_211 )
{
struct V_72 * V_74 = F_172 ( V_7 ) ;
if ( V_74 ) {
int V_310 ;
F_63 ( & V_7 -> V_9 -> V_9 , L_33 , V_74 -> V_87 ) ;
V_310 = F_170 ( V_74 , ( void T_5 * T_5 * ) V_211 ) ;
F_33 ( V_74 ) ;
return V_310 ;
}
if ( F_176 ( V_153 ) )
return - V_311 ;
return - V_53 ;
}
static int F_181 ( struct V_6 * V_7 , void T_5 * V_211 )
{
int V_310 ;
struct V_72 * V_74 ;
V_74 = F_42 ( V_7 ) ;
if ( V_74 ) {
F_63 ( & V_7 -> V_9 -> V_9 , L_33 , V_74 -> V_87 ) ;
V_310 = F_170 ( V_74 , ( void T_5 * T_5 * ) V_211 ) ;
F_33 ( V_74 ) ;
} else {
V_310 = ( F_7 ( V_7 ) ? - V_38 : - V_53 ) ;
}
return V_310 ;
}
static int F_182 ( struct V_6 * V_7 ,
struct V_312 T_5 * V_313 )
{
struct V_212 T_5 * V_136 ;
T_10 V_314 ;
V_136 = F_183 ( sizeof( * V_136 ) ) ;
if ( F_184 ( V_136 , V_313 , ( sizeof( * V_313 ) - sizeof( V_315 ) ) ) ||
F_95 ( V_314 , & V_313 -> V_93 ) ||
F_171 ( F_185 ( V_314 ) , & V_136 -> V_93 ) )
return - V_63 ;
return F_116 ( V_7 , V_136 ) ;
}
static int F_186 ( struct V_6 * V_7 ,
struct V_316 T_5 * V_313 )
{
struct V_227 T_5 * V_136 ;
T_11 V_317 ;
V_315 V_305 ;
V_136 = F_183 ( sizeof( * V_136 ) ) ;
if ( F_95 ( V_317 , & V_313 -> V_97 ) || F_171 ( V_317 , & V_136 -> V_97 ) ||
F_95 ( V_317 , & V_313 -> V_50 ) || F_171 ( V_317 , & V_136 -> V_50 ) ||
F_95 ( V_317 , & V_313 -> V_223 ) || F_171 ( V_317 , & V_136 -> V_223 ) ||
F_95 ( V_305 , & V_313 -> V_93 ) || F_171 ( F_185 ( V_305 ) , & V_136 -> V_93 ) )
return - V_63 ;
return F_126 ( V_7 , V_136 ) ;
}
static int F_187 ( struct V_6 * V_7 , void T_5 * V_211 )
{
struct V_318 V_319 ;
if ( F_117 ( & V_319 , V_211 , sizeof( V_319 ) ) )
return - V_63 ;
V_7 -> V_320 = V_319 . V_120 ;
V_7 -> V_321 = F_185 ( V_319 . V_116 ) ;
return 0 ;
}
static int F_188 ( struct V_254 * V_322 ,
struct V_323 T_5 * V_255 )
{
struct V_323 V_324 ;
if ( F_117 ( & V_324 , V_255 , sizeof( * V_255 ) ) )
return - V_63 ;
V_322 -> type = V_324 . type ;
V_322 -> V_168 = V_324 . V_168 ;
V_322 -> V_121 = V_324 . V_121 ;
V_322 -> V_15 = V_324 . V_15 ;
V_322 -> V_258 = F_185 ( V_324 . V_258 ) ;
V_322 -> V_259 = V_324 . V_259 ;
V_322 -> V_109 = V_324 . V_109 ;
V_322 -> V_294 = V_324 . V_294 ;
V_322 -> V_107 = V_324 . V_107 ;
V_322 -> V_307 = V_324 . V_307 ;
V_322 -> V_120 = V_324 . V_120 ;
V_322 -> V_325 = F_185 ( V_324 . V_325 ) ;
return 0 ;
}
static int F_189 ( struct V_6 * V_7 , void T_5 * V_211 )
{
struct V_254 V_255 ;
if ( F_188 ( & V_255 , (struct V_323 T_5 * ) V_211 ) )
return - V_63 ;
return F_149 ( V_7 , & V_255 ,
( (struct V_323 T_5 * ) V_211 ) -> V_261 ,
V_211 ) ;
}
static int F_190 ( struct V_72 * V_74 , void T_5 * T_5 * V_211 )
{
struct V_75 * V_75 = V_74 -> V_75 ;
struct V_323 T_5 * V_87 = V_74 -> V_87 ;
void T_5 * V_305 = V_74 -> V_87 ;
unsigned int V_52 ;
if ( V_74 -> V_106 && V_75 -> V_109 ) {
if ( F_53 ( V_74 -> V_106 , V_75 ) )
return - V_63 ;
}
if ( F_171 ( V_74 -> V_121 , & V_87 -> V_121 ) )
return - V_63 ;
if ( F_171 ( V_75 -> V_109 , & V_87 -> V_109 ) )
return - V_63 ;
if ( F_171 ( V_75 -> V_307 , & V_87 -> V_307 ) )
return - V_63 ;
if ( F_156 ( & V_75 -> V_97 -> V_71 ) ) {
for ( V_52 = 0 ; V_52 < V_75 -> V_107 ; V_52 ++ ) {
if ( F_171 ( V_75 -> V_261 [ V_52 ] . V_109 ,
& V_87 -> V_261 [ V_52 ] . V_109 ) )
return - V_63 ;
if ( F_171 ( V_75 -> V_261 [ V_52 ] . V_121 ,
& V_87 -> V_261 [ V_52 ] . V_121 ) )
return - V_63 ;
}
}
if ( F_171 ( F_191 ( V_305 ) , ( T_8 T_5 * ) V_211 ) )
return - V_63 ;
return 0 ;
}
static int F_192 ( struct V_6 * V_7 , void T_5 * V_211 )
{
struct V_72 * V_74 = F_172 ( V_7 ) ;
if ( V_74 ) {
int V_310 ;
F_63 ( & V_7 -> V_9 -> V_9 , L_33 , V_74 -> V_87 ) ;
V_310 = F_190 ( V_74 , ( void T_5 * T_5 * ) V_211 ) ;
F_33 ( V_74 ) ;
return V_310 ;
}
if ( F_176 ( V_153 ) )
return - V_311 ;
return - V_53 ;
}
static int F_193 ( struct V_6 * V_7 , void T_5 * V_211 )
{
int V_310 ;
struct V_72 * V_74 ;
V_74 = F_42 ( V_7 ) ;
if ( V_74 ) {
F_63 ( & V_7 -> V_9 -> V_9 , L_33 , V_74 -> V_87 ) ;
V_310 = F_190 ( V_74 , ( void T_5 * T_5 * ) V_211 ) ;
F_33 ( V_74 ) ;
} else {
V_310 = ( F_7 ( V_7 ) ? - V_38 : - V_53 ) ;
}
return V_310 ;
}
static int F_194 ( struct V_6 * V_7 , void T_5 * V_211 )
{
struct V_326 V_319 ;
if ( F_117 ( & V_319 , V_211 , sizeof( V_319 ) ) )
return - V_63 ;
V_7 -> V_320 = V_319 . V_120 ;
V_7 -> V_321 = V_319 . V_116 ;
return 0 ;
}
static int F_195 ( struct V_6 * V_7 , void T_5 * V_211 )
{
unsigned int V_135 ;
if ( F_95 ( V_135 , ( unsigned int T_5 * ) V_211 ) )
return - V_63 ;
return F_80 ( V_7 , V_135 ) ;
}
static int F_196 ( struct V_6 * V_7 , void T_5 * V_211 )
{
unsigned int V_135 ;
int V_30 ;
if ( F_95 ( V_135 , ( unsigned int T_5 * ) V_211 ) )
return - V_63 ;
V_30 = F_85 ( V_7 , V_135 ) ;
if ( V_30 < 0 )
return V_30 ;
F_68 ( V_7 , V_135 ) ;
return 0 ;
}
static int F_197 ( struct V_6 * V_7 , struct V_327 * V_328 )
{
int V_20 ;
void * V_46 = NULL ;
int V_310 = 0 ;
struct V_139 * V_140 = NULL ;
struct V_329 * V_237 = NULL ;
if ( V_7 -> V_147 )
return - V_149 ;
V_20 = F_198 ( V_328 -> V_330 ) ;
if ( V_20 > 0 ) {
V_46 = F_96 ( V_20 , V_31 ) ;
if ( V_46 == NULL )
return - V_5 ;
if ( ( F_199 ( V_328 -> V_330 ) & V_331 ) ) {
if ( F_117 ( V_46 , V_328 -> V_93 , V_20 ) ) {
F_14 ( V_46 ) ;
return - V_63 ;
}
} else {
memset ( V_46 , 0 , V_20 ) ;
}
}
if ( ! F_7 ( V_7 ) ) {
F_14 ( V_46 ) ;
return - V_53 ;
}
if ( V_7 -> V_9 -> V_10 != V_151 )
V_310 = - V_152 ;
else if ( ! ( V_140 = F_82 ( V_7 -> V_9 , V_328 -> V_332 ) ) )
V_310 = - V_55 ;
else switch ( V_328 -> V_330 ) {
case V_333 :
if ( V_140 -> V_9 . V_237 ) {
V_237 = F_200 ( V_140 -> V_9 . V_237 ) ;
F_201 ( & V_140 -> V_9 , L_34 ) ;
F_87 ( V_237 , V_140 ) ;
} else
V_310 = - V_238 ;
break;
case V_334 :
if ( ! V_140 -> V_9 . V_237 )
V_310 = F_202 ( & V_140 -> V_9 ) ;
else
V_310 = - V_252 ;
break;
default:
if ( V_140 -> V_9 . V_237 )
V_237 = F_200 ( V_140 -> V_9 . V_237 ) ;
if ( V_237 == NULL || V_237 -> V_335 == NULL ) {
V_310 = - V_336 ;
} else {
V_310 = V_237 -> V_335 ( V_140 , V_328 -> V_330 , V_46 ) ;
if ( V_310 == - V_337 )
V_310 = - V_336 ;
}
}
if ( V_310 >= 0
&& ( F_199 ( V_328 -> V_330 ) & V_338 ) != 0
&& V_20 > 0
&& F_27 ( V_328 -> V_93 , V_46 , V_20 ) != 0 )
V_310 = - V_63 ;
F_14 ( V_46 ) ;
return V_310 ;
}
static int F_203 ( struct V_6 * V_7 , void T_5 * V_211 )
{
struct V_327 V_213 ;
if ( F_117 ( & V_213 , V_211 , sizeof( V_213 ) ) )
return - V_63 ;
return F_197 ( V_7 , & V_213 ) ;
}
static int F_204 ( struct V_6 * V_7 , T_12 V_211 )
{
struct V_339 V_340 ;
struct V_327 V_213 ;
if ( F_117 ( & V_340 , F_185 ( V_211 ) , sizeof( V_340 ) ) )
return - V_63 ;
V_213 . V_332 = V_340 . V_332 ;
V_213 . V_330 = V_340 . V_330 ;
V_213 . V_93 = F_185 ( V_340 . V_93 ) ;
return F_197 ( V_7 , & V_213 ) ;
}
static int F_205 ( struct V_6 * V_7 , void T_5 * V_211 )
{
unsigned V_341 ;
int V_342 ;
if ( F_95 ( V_341 , ( unsigned T_5 * ) V_211 ) )
return - V_63 ;
V_342 = F_206 ( V_7 -> V_9 , V_341 , V_7 ) ;
if ( V_342 == 0 )
F_63 ( & V_7 -> V_9 -> V_9 , L_35 ,
V_341 , F_89 ( V_153 ) , V_153 -> V_154 ) ;
return V_342 ;
}
static int F_207 ( struct V_6 * V_7 , void T_5 * V_211 )
{
unsigned V_341 ;
if ( F_95 ( V_341 , ( unsigned T_5 * ) V_211 ) )
return - V_63 ;
return F_208 ( V_7 -> V_9 , V_341 , V_7 ) ;
}
static int F_209 ( struct V_6 * V_7 , void T_5 * V_211 )
{
T_10 V_343 ;
V_343 = V_344 | V_345 |
V_346 | V_347 |
V_348 ;
if ( ! V_7 -> V_9 -> V_282 -> V_349 )
V_343 |= V_350 ;
if ( V_7 -> V_9 -> V_282 -> V_283 )
V_343 |= V_351 ;
if ( F_171 ( V_343 , ( T_10 T_5 * ) V_211 ) )
return - V_63 ;
return 0 ;
}
static int F_210 ( struct V_6 * V_7 , void T_5 * V_211 )
{
struct V_352 V_353 ;
struct V_139 * V_140 ;
if ( F_117 ( & V_353 , V_211 , sizeof( V_353 ) ) )
return - V_63 ;
V_140 = F_82 ( V_7 -> V_9 , V_353 . V_165 ) ;
if ( ! V_140 )
return - V_55 ;
if ( V_140 -> V_9 . V_237 ) {
struct V_329 * V_237 = F_200 ( V_140 -> V_9 . V_237 ) ;
if ( V_7 -> V_147 )
return - V_149 ;
if ( ( V_353 . V_15 & V_354 ) &&
strncmp ( V_353 . V_237 , V_140 -> V_9 . V_237 -> V_239 ,
sizeof( V_353 . V_237 ) ) != 0 )
return - V_252 ;
if ( ( V_353 . V_15 & V_355 ) &&
strncmp ( V_353 . V_237 , V_140 -> V_9 . V_237 -> V_239 ,
sizeof( V_353 . V_237 ) ) == 0 )
return - V_252 ;
F_201 ( & V_140 -> V_9 , L_34 ) ;
F_87 ( V_237 , V_140 ) ;
}
return F_80 ( V_7 , V_353 . V_165 ) ;
}
static int F_211 ( struct V_6 * V_7 , void T_5 * V_211 )
{
unsigned V_195 , V_196 ;
struct V_184 * * V_197 ;
struct V_139 * V_140 ;
int V_356 ;
V_356 = F_94 ( V_7 , V_211 , & V_195 , & V_196 ,
& V_197 , & V_140 ) ;
if ( V_356 )
return V_356 ;
F_68 ( V_7 ,
V_140 -> V_143 [ 0 ] . V_71 . V_144 ) ;
V_356 = F_212 ( V_140 , V_197 , V_196 , V_195 , V_31 ) ;
F_14 ( V_197 ) ;
return V_356 ;
}
static int F_213 ( struct V_6 * V_7 , void T_5 * V_211 )
{
unsigned V_196 ;
struct V_184 * * V_197 ;
struct V_139 * V_140 ;
int V_356 ;
V_356 = F_94 ( V_7 , V_211 , NULL , & V_196 , & V_197 , & V_140 ) ;
if ( V_356 )
return V_356 ;
F_68 ( V_7 ,
V_140 -> V_143 [ 0 ] . V_71 . V_144 ) ;
V_356 = F_214 ( V_140 , V_197 , V_196 , V_31 ) ;
F_14 ( V_197 ) ;
return V_356 ;
}
static int F_215 ( struct V_6 * V_7 , void T_5 * V_211 )
{
T_8 V_93 ;
if ( F_117 ( & V_93 , V_211 , sizeof( V_93 ) ) )
return - V_63 ;
V_7 -> V_148 &= V_93 ;
V_7 -> V_147 = true ;
return 0 ;
}
static long F_216 ( struct V_26 * V_26 , unsigned int V_357 ,
void T_5 * V_136 )
{
struct V_6 * V_7 = V_26 -> V_27 ;
struct V_203 * V_203 = F_217 ( V_26 ) ;
struct V_49 * V_9 = V_7 -> V_9 ;
int V_30 = - V_336 ;
if ( ! ( V_26 -> V_358 & V_359 ) )
return - V_360 ;
F_25 ( V_9 ) ;
switch ( V_357 ) {
case V_361 :
F_63 ( & V_9 -> V_9 , L_36 , V_182 ) ;
V_30 = F_180 ( V_7 , V_136 ) ;
goto V_222;
case V_362 :
F_63 ( & V_9 -> V_9 , L_37 , V_182 ) ;
V_30 = F_181 ( V_7 , V_136 ) ;
goto V_222;
#ifdef F_218
case V_363 :
F_63 ( & V_9 -> V_9 , L_38 , V_182 ) ;
V_30 = F_192 ( V_7 , V_136 ) ;
goto V_222;
case V_364 :
F_63 ( & V_9 -> V_9 , L_39 , V_182 ) ;
V_30 = F_193 ( V_7 , V_136 ) ;
goto V_222;
#endif
}
if ( ! F_7 ( V_7 ) ) {
F_30 ( V_9 ) ;
return - V_53 ;
}
switch ( V_357 ) {
case V_365 :
F_63 ( & V_9 -> V_9 , L_40 , V_182 ) ;
V_30 = F_116 ( V_7 , V_136 ) ;
if ( V_30 >= 0 )
V_203 -> V_366 = F_219 ( V_203 ) ;
break;
case V_367 :
F_63 ( & V_9 -> V_9 , L_41 , V_182 ) ;
V_30 = F_126 ( V_7 , V_136 ) ;
if ( V_30 >= 0 )
V_203 -> V_366 = F_219 ( V_203 ) ;
break;
case V_368 :
F_63 ( & V_9 -> V_9 , L_42 , V_182 ) ;
V_30 = F_132 ( V_7 , V_136 ) ;
if ( V_30 >= 0 )
V_203 -> V_366 = F_219 ( V_203 ) ;
break;
case V_369 :
F_63 ( & V_9 -> V_9 , L_43 , V_182 ) ;
V_30 = F_139 ( V_7 ) ;
break;
case V_370 :
F_63 ( & V_9 -> V_9 , L_44 , V_182 ) ;
V_30 = F_134 ( V_7 , V_136 ) ;
if ( V_30 >= 0 )
V_203 -> V_366 = F_219 ( V_203 ) ;
break;
case V_371 :
F_63 ( & V_9 -> V_9 , L_45 , V_182 ) ;
V_30 = F_136 ( V_7 , V_136 ) ;
break;
case V_372 :
F_63 ( & V_9 -> V_9 , L_46 , V_182 ) ;
V_30 = F_138 ( V_7 , V_136 ) ;
break;
case V_373 :
F_63 ( & V_9 -> V_9 , L_47 , V_182 ) ;
V_30 = F_142 ( V_7 , V_136 ) ;
break;
case V_374 :
F_63 ( & V_9 -> V_9 , L_48 , V_182 ) ;
V_30 = F_144 ( V_7 , V_136 ) ;
break;
case V_375 :
F_63 ( & V_9 -> V_9 , L_49 , V_182 ) ;
V_30 = F_168 ( V_7 , V_136 ) ;
if ( V_30 >= 0 )
V_203 -> V_366 = F_219 ( V_203 ) ;
break;
#ifdef F_218
case V_376 :
F_63 ( & V_9 -> V_9 , L_50 , V_182 ) ;
V_30 = F_182 ( V_7 , V_136 ) ;
if ( V_30 >= 0 )
V_203 -> V_366 = F_219 ( V_203 ) ;
break;
case V_377 :
F_63 ( & V_9 -> V_9 , L_51 , V_182 ) ;
V_30 = F_186 ( V_7 , V_136 ) ;
if ( V_30 >= 0 )
V_203 -> V_366 = F_219 ( V_203 ) ;
break;
case V_378 :
F_63 ( & V_9 -> V_9 , L_52 , V_182 ) ;
V_30 = F_187 ( V_7 , V_136 ) ;
break;
case V_379 :
F_63 ( & V_9 -> V_9 , L_53 , V_182 ) ;
V_30 = F_189 ( V_7 , V_136 ) ;
if ( V_30 >= 0 )
V_203 -> V_366 = F_219 ( V_203 ) ;
break;
case V_380 :
F_63 ( & V_9 -> V_9 , L_54 , V_182 ) ;
V_30 = F_204 ( V_7 , F_191 ( V_136 ) ) ;
break;
#endif
case V_381 :
F_63 ( & V_9 -> V_9 , L_55 , V_182 , V_136 ) ;
V_30 = F_169 ( V_7 , V_136 ) ;
break;
case V_382 :
F_63 ( & V_9 -> V_9 , L_56 , V_182 ) ;
V_30 = F_194 ( V_7 , V_136 ) ;
break;
case V_383 :
F_63 ( & V_9 -> V_9 , L_57 , V_182 ) ;
V_30 = F_195 ( V_7 , V_136 ) ;
break;
case V_384 :
F_63 ( & V_9 -> V_9 , L_58 , V_182 ) ;
V_30 = F_196 ( V_7 , V_136 ) ;
break;
case V_385 :
F_63 ( & V_9 -> V_9 , L_59 , V_182 ) ;
V_30 = F_203 ( V_7 , V_136 ) ;
break;
case V_386 :
F_63 ( & V_9 -> V_9 , L_60 , V_182 ) ;
V_30 = F_205 ( V_7 , V_136 ) ;
break;
case V_387 :
F_63 ( & V_9 -> V_9 , L_61 , V_182 ) ;
V_30 = F_207 ( V_7 , V_136 ) ;
break;
case V_388 :
V_30 = F_209 ( V_7 , V_136 ) ;
break;
case V_389 :
V_30 = F_210 ( V_7 , V_136 ) ;
break;
case V_390 :
V_30 = F_211 ( V_7 , V_136 ) ;
break;
case V_391 :
V_30 = F_213 ( V_7 , V_136 ) ;
break;
case V_392 :
V_30 = F_215 ( V_7 , V_136 ) ;
break;
case V_393 :
V_30 = V_7 -> V_9 -> V_244 ;
break;
}
V_222:
F_30 ( V_9 ) ;
if ( V_30 >= 0 )
V_203 -> V_394 = F_219 ( V_203 ) ;
return V_30 ;
}
static long F_220 ( struct V_26 * V_26 , unsigned int V_357 ,
unsigned long V_211 )
{
int V_30 ;
V_30 = F_216 ( V_26 , V_357 , ( void T_5 * ) V_211 ) ;
return V_30 ;
}
static long F_221 ( struct V_26 * V_26 , unsigned int V_357 ,
unsigned long V_211 )
{
int V_30 ;
V_30 = F_216 ( V_26 , V_357 , F_185 ( V_211 ) ) ;
return V_30 ;
}
static unsigned int F_222 ( struct V_26 * V_26 ,
struct V_395 * V_133 )
{
struct V_6 * V_7 = V_26 -> V_27 ;
unsigned int V_396 = 0 ;
F_223 ( V_26 , & V_7 -> V_133 , V_133 ) ;
if ( V_26 -> V_358 & V_359 && ! F_8 ( & V_7 -> V_85 ) )
V_396 |= V_397 | V_398 ;
if ( ! F_7 ( V_7 ) )
V_396 |= V_399 ;
if ( F_8 ( & V_7 -> V_8 ) )
V_396 |= V_400 ;
return V_396 ;
}
static void F_224 ( struct V_49 * V_88 )
{
struct V_6 * V_7 ;
struct V_117 V_118 ;
while ( ! F_8 ( & V_88 -> V_210 ) ) {
V_7 = F_43 ( V_88 -> V_210 . V_86 , struct V_6 , V_8 ) ;
F_70 ( V_7 ) ;
F_225 ( & V_7 -> V_133 ) ;
F_41 ( & V_7 -> V_8 ) ;
if ( V_7 -> V_320 ) {
memset ( & V_118 , 0 , sizeof( V_118 ) ) ;
V_118 . V_122 = V_7 -> V_320 ;
V_118 . V_123 = V_226 ;
V_118 . V_124 = V_125 ;
V_118 . V_126 = V_7 -> V_321 ;
F_65 ( V_7 -> V_320 , & V_118 ,
V_7 -> V_209 , V_7 -> V_77 , V_7 -> V_119 ) ;
}
}
}
static int F_226 ( struct V_401 * V_402 ,
unsigned long V_403 , void * V_9 )
{
switch ( V_403 ) {
case V_404 :
break;
case V_405 :
F_224 ( V_9 ) ;
break;
}
return V_406 ;
}
int T_13 F_227 ( void )
{
int V_310 ;
V_310 = F_228 ( V_407 , V_408 ,
L_62 ) ;
if ( V_310 ) {
F_229 ( V_409 L_63 ) ;
goto V_410;
}
F_230 ( & V_411 , & V_412 ) ;
V_310 = F_231 ( & V_411 , V_407 , V_408 ) ;
if ( V_310 ) {
F_229 ( V_409 L_64 ,
V_206 ) ;
goto V_413;
}
F_232 ( & V_414 ) ;
V_410:
return V_310 ;
V_413:
F_233 ( V_407 , V_408 ) ;
goto V_410;
}
void F_234 ( void )
{
F_235 ( & V_414 ) ;
F_236 ( & V_411 ) ;
F_233 ( V_407 , V_408 ) ;
}
