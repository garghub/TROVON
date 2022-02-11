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
V_22 = F_19 ( V_8 -> V_10 , V_21 , V_34 | V_35 ,
& V_23 ) ;
if ( ! V_22 ) {
V_31 = - V_6 ;
goto V_36;
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
F_22 ( V_14 -> V_22 ) >> V_37 ,
V_21 , V_25 -> V_38 ) < 0 ) {
F_9 ( V_14 , & V_14 -> V_19 ) ;
return - V_39 ;
}
V_25 -> V_40 |= V_41 ;
V_25 -> V_40 |= ( V_42 | V_43 ) ;
V_25 -> V_44 = & V_45 ;
V_25 -> V_26 = V_14 ;
F_10 ( & V_8 -> V_17 , V_16 ) ;
F_23 ( & V_14 -> V_20 , & V_8 -> V_46 ) ;
F_12 ( & V_8 -> V_17 , V_16 ) ;
return 0 ;
V_36:
F_14 ( V_14 ) ;
V_33:
F_6 ( V_21 + sizeof( struct V_13 ) ) ;
error:
return V_31 ;
}
static T_3 F_24 ( struct V_27 * V_27 , char T_4 * V_47 , T_1 V_48 ,
T_5 * V_49 )
{
struct V_7 * V_8 = V_27 -> V_28 ;
struct V_50 * V_10 = V_8 -> V_10 ;
T_3 V_31 = 0 ;
unsigned V_51 ;
T_5 V_52 ;
int V_53 ;
V_52 = * V_49 ;
F_25 ( V_10 ) ;
if ( ! F_7 ( V_8 ) ) {
V_31 = - V_54 ;
goto V_55;
} else if ( V_52 < 0 ) {
V_31 = - V_56 ;
goto V_55;
}
if ( V_52 < sizeof( struct V_57 ) ) {
struct V_57 V_58 ;
memcpy ( & V_58 , & V_10 -> V_59 , sizeof( V_10 -> V_59 ) ) ;
F_26 ( & V_58 . V_60 ) ;
F_26 ( & V_58 . V_61 ) ;
F_26 ( & V_58 . V_62 ) ;
F_26 ( & V_58 . V_63 ) ;
V_51 = sizeof( struct V_57 ) - V_52 ;
if ( V_51 > V_48 )
V_51 = V_48 ;
if ( F_27 ( V_47 , ( ( char * ) & V_58 ) + V_52 , V_51 ) ) {
V_31 = - V_64 ;
goto V_55;
}
* V_49 += V_51 ;
V_47 += V_51 ;
V_48 -= V_51 ;
V_31 += V_51 ;
}
V_52 = sizeof( struct V_57 ) ;
for ( V_53 = 0 ; V_48 && V_53 < V_10 -> V_59 . V_65 ; V_53 ++ ) {
struct V_66 * V_67 =
(struct V_66 * ) V_10 -> V_68 [ V_53 ] ;
unsigned int V_69 = F_28 ( V_67 -> V_70 ) ;
if ( * V_49 < V_52 + V_69 ) {
unsigned V_71 =
F_28 ( V_10 -> V_67 [ V_53 ] . V_72 . V_70 ) ;
V_51 = V_69 - ( * V_49 - V_52 ) ;
if ( V_51 > V_48 )
V_51 = V_48 ;
if ( V_71 > ( * V_49 - V_52 ) ) {
V_71 -= ( * V_49 - V_52 ) ;
if ( F_27 ( V_47 ,
V_10 -> V_68 [ V_53 ] + ( * V_49 - V_52 ) ,
F_29 ( V_51 , V_71 ) ) ) {
V_31 = - V_64 ;
goto V_55;
}
}
* V_49 += V_51 ;
V_47 += V_51 ;
V_48 -= V_51 ;
V_31 += V_51 ;
}
V_52 += V_69 ;
}
V_55:
F_30 ( V_10 ) ;
return V_31 ;
}
static struct V_73 * F_31 ( unsigned int V_74 )
{
struct V_73 * V_75 ;
V_75 = F_18 ( sizeof( struct V_73 ) , V_32 ) ;
if ( ! V_75 )
return NULL ;
V_75 -> V_76 = F_32 ( V_74 , V_32 ) ;
if ( ! V_75 -> V_76 ) {
F_14 ( V_75 ) ;
return NULL ;
}
return V_75 ;
}
static void F_33 ( struct V_73 * V_75 )
{
int V_53 ;
F_34 ( V_75 -> V_77 ) ;
if ( V_75 -> V_78 )
F_35 ( V_75 -> V_78 ) ;
for ( V_53 = 0 ; V_53 < V_75 -> V_76 -> V_79 ; V_53 ++ ) {
if ( F_36 ( & V_75 -> V_76 -> V_80 [ V_53 ] ) )
F_14 ( F_37 ( & V_75 -> V_76 -> V_80 [ V_53 ] ) ) ;
}
F_14 ( V_75 -> V_76 -> V_80 ) ;
if ( V_75 -> V_14 == NULL )
F_14 ( V_75 -> V_76 -> V_81 ) ;
else
F_9 ( V_75 -> V_14 , & V_75 -> V_14 -> V_18 ) ;
F_14 ( V_75 -> V_76 -> V_82 ) ;
F_38 ( V_75 -> V_76 ) ;
F_6 ( V_75 -> V_83 ) ;
F_14 ( V_75 ) ;
}
static void F_39 ( struct V_73 * V_75 )
{
struct V_7 * V_8 = V_75 -> V_8 ;
unsigned long V_16 ;
F_10 ( & V_8 -> V_17 , V_16 ) ;
F_23 ( & V_75 -> V_84 , & V_8 -> V_85 ) ;
F_12 ( & V_8 -> V_17 , V_16 ) ;
}
static void F_40 ( struct V_73 * V_75 )
{
struct V_7 * V_8 = V_75 -> V_8 ;
unsigned long V_16 ;
F_10 ( & V_8 -> V_17 , V_16 ) ;
F_41 ( & V_75 -> V_84 ) ;
F_12 ( & V_8 -> V_17 , V_16 ) ;
}
static struct V_73 * F_42 ( struct V_7 * V_8 )
{
unsigned long V_16 ;
struct V_73 * V_75 = NULL ;
F_10 ( & V_8 -> V_17 , V_16 ) ;
if ( ! F_8 ( & V_8 -> V_86 ) ) {
V_75 = F_43 ( V_8 -> V_86 . V_87 , struct V_73 ,
V_84 ) ;
F_41 ( & V_75 -> V_84 ) ;
}
F_12 ( & V_8 -> V_17 , V_16 ) ;
return V_75 ;
}
static struct V_73 * F_44 ( struct V_7 * V_8 ,
void T_4 * V_88 )
{
struct V_73 * V_75 ;
F_45 (as, &ps->async_pending, asynclist)
if ( V_75 -> V_88 == V_88 ) {
F_41 ( & V_75 -> V_84 ) ;
return V_75 ;
}
return NULL ;
}
static void F_46 ( struct V_50 * V_89 ,
void T_4 * V_88 , int V_90 , unsigned V_69 ,
int V_91 , enum V_92 V_93 ,
unsigned char * V_94 , unsigned V_95 )
{
static const char * V_96 [] = { L_1 , L_2 , L_3 , L_4 } ;
static const char * V_97 [] = { L_5 , L_6 } ;
int V_98 ;
const char * V_99 , * V_100 ;
if ( ! V_101 )
return;
V_98 = F_47 ( V_90 ) ;
V_99 = V_96 [ F_48 ( V_90 ) ] ;
V_100 = V_97 [ ! ! F_49 ( V_90 ) ] ;
if ( V_88 ) {
if ( V_93 == V_102 )
F_50 ( & V_89 -> V_10 , L_7
L_8 ,
V_88 , V_98 , V_99 , V_100 , V_69 ) ;
else
F_50 ( & V_89 -> V_10 , L_7
L_9 ,
V_88 , V_98 , V_99 , V_100 , V_69 ,
V_91 ) ;
} else {
if ( V_93 == V_102 )
F_50 ( & V_89 -> V_10 , L_10
L_11 ,
V_98 , V_99 , V_100 , V_69 , V_91 ) ;
else
F_50 ( & V_89 -> V_10 , L_12
L_13 ,
V_98 , V_99 , V_100 , V_69 , V_91 ) ;
}
V_95 = F_29 ( V_95 , V_103 ) ;
if ( V_94 && V_95 > 0 ) {
F_51 ( V_104 , L_14 , V_105 , 32 , 1 ,
V_94 , V_95 , 1 ) ;
}
}
static void F_52 ( struct V_76 * V_76 , unsigned V_51 )
{
int V_53 , V_21 ;
V_51 = F_29 ( V_51 , V_103 ) ;
if ( ! V_101 || V_51 == 0 )
return;
if ( V_76 -> V_79 == 0 ) {
F_51 ( V_104 , L_14 , V_105 , 32 , 1 ,
V_76 -> V_81 , V_51 , 1 ) ;
return;
}
for ( V_53 = 0 ; V_53 < V_76 -> V_79 && V_51 ; V_53 ++ ) {
V_21 = ( V_51 > V_106 ) ? V_106 : V_51 ;
F_51 ( V_104 , L_14 , V_105 , 32 , 1 ,
F_37 ( & V_76 -> V_80 [ V_53 ] ) , V_21 , 1 ) ;
V_51 -= V_21 ;
}
}
static int F_53 ( T_6 T_4 * V_107 , struct V_76 * V_76 )
{
unsigned V_53 , V_51 , V_21 ;
if ( V_76 -> V_108 > 0 )
V_51 = V_76 -> V_109 ;
else
V_51 = V_76 -> V_110 ;
if ( V_76 -> V_79 == 0 ) {
if ( F_27 ( V_107 , V_76 -> V_81 , V_51 ) )
return - V_64 ;
return 0 ;
}
for ( V_53 = 0 ; V_53 < V_76 -> V_79 && V_51 ; V_53 ++ ) {
V_21 = ( V_51 > V_106 ) ? V_106 : V_51 ;
if ( F_27 ( V_107 , F_37 ( & V_76 -> V_80 [ V_53 ] ) , V_21 ) )
return - V_64 ;
V_107 += V_21 ;
V_51 -= V_21 ;
}
return 0 ;
}
static void F_54 ( struct V_7 * V_8 , unsigned V_111 )
__releases( V_8 -> V_17 )
__acquires( V_8 -> V_17 )
{
struct V_76 * V_76 ;
struct V_73 * V_75 ;
F_45 (as, &ps->async_pending, asynclist) {
if ( V_75 -> V_111 == V_111 ) {
if ( V_75 -> V_112 != V_113 )
goto V_114;
V_75 -> V_112 = V_115 ;
V_75 -> V_111 = 0 ;
}
}
V_8 -> V_116 |= ( 1 << V_111 ) ;
V_114:
F_45 (as, &ps->async_pending, asynclist) {
if ( V_75 -> V_112 == V_115 ) {
V_75 -> V_112 = 0 ;
V_76 = V_75 -> V_76 ;
F_55 ( V_76 ) ;
F_56 ( & V_8 -> V_17 ) ;
F_57 ( V_76 ) ;
F_58 ( V_76 ) ;
F_59 ( & V_8 -> V_17 ) ;
goto V_114;
}
}
}
static void V_86 ( struct V_76 * V_76 )
{
struct V_73 * V_75 = V_76 -> V_117 ;
struct V_7 * V_8 = V_75 -> V_8 ;
struct V_118 V_119 ;
struct V_77 * V_77 = NULL ;
T_7 V_120 = 0 ;
const struct V_78 * V_78 = NULL ;
int V_121 ;
F_59 ( & V_8 -> V_17 ) ;
F_60 ( & V_75 -> V_84 , & V_8 -> V_86 ) ;
V_75 -> V_122 = V_76 -> V_122 ;
V_121 = V_75 -> V_121 ;
if ( V_121 ) {
memset ( & V_119 , 0 , sizeof( V_119 ) ) ;
V_119 . V_123 = V_75 -> V_121 ;
V_119 . V_124 = V_75 -> V_122 ;
V_119 . V_125 = V_126 ;
V_119 . V_127 = V_75 -> V_88 ;
V_77 = F_61 ( V_75 -> V_77 ) ;
V_78 = F_62 ( V_75 -> V_78 ) ;
V_120 = V_75 -> V_120 ;
}
F_63 ( & V_76 -> V_10 -> V_10 , L_15 ) ;
F_46 ( V_76 -> V_10 , V_75 -> V_88 , V_76 -> V_90 , V_76 -> V_110 ,
V_75 -> V_122 , V_128 , NULL , 0 ) ;
if ( ( V_76 -> V_129 & V_130 ) == V_131 )
F_52 ( V_76 , V_76 -> V_110 ) ;
if ( V_75 -> V_122 < 0 && V_75 -> V_111 && V_75 -> V_122 != - V_132 &&
V_75 -> V_122 != - V_133 )
F_54 ( V_8 , V_75 -> V_111 ) ;
F_56 ( & V_8 -> V_17 ) ;
if ( V_121 ) {
F_64 ( V_119 . V_123 , & V_119 , V_77 , V_78 , V_120 ) ;
F_34 ( V_77 ) ;
F_35 ( V_78 ) ;
}
F_65 ( & V_8 -> V_134 ) ;
}
static void F_66 ( struct V_7 * V_8 , struct V_135 * V_9 )
{
struct V_76 * V_76 ;
struct V_73 * V_75 ;
unsigned long V_16 ;
F_10 ( & V_8 -> V_17 , V_16 ) ;
while ( ! F_8 ( V_9 ) ) {
V_75 = F_43 ( V_9 -> V_87 , struct V_73 , V_84 ) ;
F_41 ( & V_75 -> V_84 ) ;
V_76 = V_75 -> V_76 ;
F_55 ( V_76 ) ;
F_12 ( & V_8 -> V_17 , V_16 ) ;
F_67 ( V_76 ) ;
F_58 ( V_76 ) ;
F_10 ( & V_8 -> V_17 , V_16 ) ;
}
F_12 ( & V_8 -> V_17 , V_16 ) ;
}
static void F_68 ( struct V_7 * V_8 ,
unsigned int V_136 )
{
struct V_135 * V_137 , * V_138 , V_139 ;
unsigned long V_16 ;
F_20 ( & V_139 ) ;
F_10 ( & V_8 -> V_17 , V_16 ) ;
F_69 (p, q, &ps->async_pending)
if ( V_136 == F_43 ( V_137 , struct V_73 , V_84 ) -> V_136 )
F_60 ( V_137 , & V_139 ) ;
F_12 ( & V_8 -> V_17 , V_16 ) ;
F_66 ( V_8 , & V_139 ) ;
}
static void F_70 ( struct V_7 * V_8 )
{
F_66 ( V_8 , & V_8 -> V_85 ) ;
}
static int F_71 ( struct V_140 * V_141 ,
const struct V_142 * V_143 )
{
return - V_54 ;
}
static void F_72 ( struct V_140 * V_141 )
{
struct V_7 * V_8 = F_73 ( V_141 ) ;
unsigned int V_136 = V_141 -> V_144 -> V_72 . V_145 ;
if ( ! V_8 )
return;
if ( F_74 ( V_136 < 8 * sizeof( V_8 -> V_146 ) ) )
F_75 ( V_136 , & V_8 -> V_146 ) ;
else
F_76 ( & V_141 -> V_10 , L_16 ,
V_136 ) ;
F_77 ( V_141 , NULL ) ;
F_68 ( V_8 , V_136 ) ;
}
static int F_78 ( struct V_140 * V_141 , T_8 V_147 )
{
return 0 ;
}
static int F_79 ( struct V_140 * V_141 )
{
return 0 ;
}
static int F_80 ( struct V_7 * V_8 , unsigned int V_136 )
{
struct V_50 * V_10 = V_8 -> V_10 ;
struct V_140 * V_141 ;
int V_55 ;
if ( V_136 >= 8 * sizeof( V_8 -> V_146 ) )
return - V_56 ;
if ( F_81 ( V_136 , & V_8 -> V_146 ) )
return 0 ;
if ( V_8 -> V_148 &&
! F_81 ( V_136 , & V_8 -> V_149 ) )
return - V_150 ;
V_141 = F_82 ( V_10 , V_136 ) ;
if ( ! V_141 )
V_55 = - V_133 ;
else
V_55 = F_83 ( & V_151 , V_141 , V_8 ) ;
if ( V_55 == 0 )
F_84 ( V_136 , & V_8 -> V_146 ) ;
return V_55 ;
}
static int F_85 ( struct V_7 * V_8 , unsigned int V_136 )
{
struct V_50 * V_10 ;
struct V_140 * V_141 ;
int V_55 ;
V_55 = - V_56 ;
if ( V_136 >= 8 * sizeof( V_8 -> V_146 ) )
return V_55 ;
V_10 = V_8 -> V_10 ;
V_141 = F_82 ( V_10 , V_136 ) ;
if ( ! V_141 )
V_55 = - V_133 ;
else if ( F_86 ( V_136 , & V_8 -> V_146 ) ) {
F_87 ( & V_151 , V_141 ) ;
V_55 = 0 ;
}
return V_55 ;
}
static int F_88 ( struct V_7 * V_8 , unsigned int V_136 )
{
if ( V_8 -> V_10 -> V_11 != V_152 )
return - V_153 ;
if ( V_136 >= 8 * sizeof( V_8 -> V_146 ) )
return - V_56 ;
if ( F_81 ( V_136 , & V_8 -> V_146 ) )
return 0 ;
F_76 ( & V_8 -> V_10 -> V_10 , L_17
L_18 , F_89 ( V_154 ) ,
V_154 -> V_155 , V_136 ) ;
return F_80 ( V_8 , V_136 ) ;
}
static int F_90 ( struct V_50 * V_10 , unsigned int V_98 )
{
unsigned int V_53 , V_156 , V_157 ;
struct V_140 * V_141 ;
struct V_158 * V_159 ;
struct V_160 * V_161 ;
if ( V_98 & ~ ( V_162 | 0xf ) )
return - V_56 ;
if ( ! V_10 -> V_163 )
return - V_164 ;
for ( V_53 = 0 ; V_53 < V_10 -> V_163 -> V_72 . V_165 ; V_53 ++ ) {
V_141 = V_10 -> V_163 -> V_166 [ V_53 ] ;
for ( V_156 = 0 ; V_156 < V_141 -> V_167 ; V_156 ++ ) {
V_159 = & V_141 -> V_144 [ V_156 ] ;
for ( V_157 = 0 ; V_157 < V_159 -> V_72 . V_168 ; V_157 ++ ) {
V_161 = & V_159 -> V_169 [ V_157 ] . V_72 ;
if ( V_161 -> V_170 == V_98 )
return V_159 -> V_72 . V_145 ;
}
}
}
return - V_133 ;
}
static int F_91 ( struct V_7 * V_8 , unsigned int V_171 ,
unsigned int V_172 , unsigned int V_173 )
{
int V_31 = 0 ;
struct V_158 * V_174 ;
if ( V_8 -> V_10 -> V_11 != V_175
&& V_8 -> V_10 -> V_11 != V_176
&& V_8 -> V_10 -> V_11 != V_152 )
return - V_153 ;
if ( V_177 == ( V_178 & V_171 ) )
return 0 ;
if ( V_171 == 0xa1 && V_172 == 0 ) {
V_174 = F_92 ( V_8 -> V_10 -> V_163 ,
V_173 >> 8 , V_173 & 0xff ) ;
if ( V_174
&& V_174 -> V_72 . V_179 == V_180 )
return 0 ;
}
V_173 &= 0xff ;
switch ( V_171 & V_181 ) {
case V_182 :
if ( ( V_173 & ~ V_162 ) == 0 )
return 0 ;
V_31 = F_90 ( V_8 -> V_10 , V_173 ) ;
if ( V_31 < 0 ) {
V_31 = F_90 ( V_8 -> V_10 , V_173 ^ 0x80 ) ;
if ( V_31 >= 0 )
F_50 ( & V_8 -> V_10 -> V_10 ,
L_19 ,
V_183 , F_89 ( V_154 ) ,
V_154 -> V_155 , V_173 , V_173 ^ 0x80 ) ;
}
if ( V_31 >= 0 )
V_31 = F_88 ( V_8 , V_31 ) ;
break;
case V_184 :
V_31 = F_88 ( V_8 , V_173 ) ;
break;
}
return V_31 ;
}
static struct V_185 * F_93 ( struct V_50 * V_10 ,
unsigned char V_98 )
{
if ( V_98 & V_186 )
return V_10 -> V_187 [ V_98 & V_188 ] ;
else
return V_10 -> V_189 [ V_98 & V_188 ] ;
}
static int F_94 ( struct V_7 * V_8 ,
struct V_190 T_4 * V_191 ,
unsigned int * V_192 ,
unsigned int * V_193 ,
struct V_185 * * * V_194 ,
struct V_140 * * V_195 )
{
unsigned int V_53 , V_196 , V_197 ;
struct V_185 * * V_198 ;
struct V_140 * V_141 = NULL ;
unsigned char V_98 ;
int V_136 , V_31 ;
if ( F_95 ( V_196 , & V_191 -> V_196 ) ||
F_95 ( V_197 , & V_191 -> V_197 ) )
return - V_64 ;
if ( V_197 < 1 || V_197 > V_199 )
return - V_56 ;
if ( V_192 && ( V_196 < 2 || V_196 > 65536 ) )
return - V_56 ;
V_198 = F_96 ( V_197 * sizeof( * V_198 ) , V_32 ) ;
if ( ! V_198 )
return - V_6 ;
for ( V_53 = 0 ; V_53 < V_197 ; V_53 ++ ) {
if ( F_95 ( V_98 , & V_191 -> V_198 [ V_53 ] ) ) {
V_31 = - V_64 ;
goto error;
}
V_198 [ V_53 ] = F_93 ( V_8 -> V_10 , V_98 ) ;
if ( ! V_198 [ V_53 ] ) {
V_31 = - V_56 ;
goto error;
}
V_136 = F_90 ( V_8 -> V_10 , V_98 ) ;
if ( V_136 < 0 ) {
V_31 = V_136 ;
goto error;
}
if ( V_53 == 0 ) {
V_31 = F_88 ( V_8 , V_136 ) ;
if ( V_31 < 0 )
goto error;
V_141 = F_82 ( V_8 -> V_10 , V_136 ) ;
} else {
if ( V_136 != V_141 -> V_144 -> V_72 . V_145 ) {
V_31 = - V_56 ;
goto error;
}
}
}
if ( V_192 )
* V_192 = V_196 ;
* V_193 = V_197 ;
* V_194 = V_198 ;
* V_195 = V_141 ;
return 0 ;
error:
F_14 ( V_198 ) ;
return V_31 ;
}
static int F_97 ( struct V_200 * V_10 , void * V_94 )
{
return V_10 -> V_201 == ( V_202 ) ( unsigned long ) V_94 ;
}
static struct V_50 * F_98 ( V_202 V_201 )
{
struct V_200 * V_10 ;
V_10 = F_99 ( & V_203 , NULL ,
( void * ) ( unsigned long ) V_201 , F_97 ) ;
if ( ! V_10 )
return NULL ;
return F_100 ( V_10 ) ;
}
static int F_101 ( struct V_204 * V_204 , struct V_27 * V_27 )
{
struct V_50 * V_10 = NULL ;
struct V_7 * V_8 ;
int V_31 ;
V_31 = - V_6 ;
V_8 = F_18 ( sizeof( struct V_7 ) , V_32 ) ;
if ( ! V_8 )
goto V_205;
V_31 = - V_54 ;
F_102 ( & V_206 ) ;
if ( F_103 ( V_204 ) == V_207 )
V_10 = F_98 ( V_204 -> V_208 ) ;
F_104 ( & V_206 ) ;
if ( ! V_10 )
goto V_205;
F_25 ( V_10 ) ;
if ( V_10 -> V_11 == V_12 )
goto V_209;
V_31 = F_105 ( V_10 ) ;
if ( V_31 )
goto V_209;
V_8 -> V_10 = V_10 ;
V_8 -> V_27 = V_27 ;
V_8 -> V_149 = 0xFFFFFFFF ;
F_106 ( & V_8 -> V_17 ) ;
F_20 ( & V_8 -> V_9 ) ;
F_20 ( & V_8 -> V_85 ) ;
F_20 ( & V_8 -> V_86 ) ;
F_20 ( & V_8 -> V_46 ) ;
F_107 ( & V_8 -> V_134 ) ;
V_8 -> V_210 = F_61 ( F_108 ( V_154 ) ) ;
V_8 -> V_78 = F_109 () ;
F_110 ( V_154 , & V_8 -> V_120 ) ;
F_111 () ;
F_23 ( & V_8 -> V_9 , & V_10 -> V_211 ) ;
V_27 -> V_28 = V_8 ;
F_30 ( V_10 ) ;
F_63 ( & V_10 -> V_10 , L_20 , F_89 ( V_154 ) ,
V_154 -> V_155 ) ;
return V_31 ;
V_209:
F_30 ( V_10 ) ;
F_112 ( V_10 ) ;
V_205:
F_14 ( V_8 ) ;
return V_31 ;
}
static int F_113 ( struct V_204 * V_204 , struct V_27 * V_27 )
{
struct V_7 * V_8 = V_27 -> V_28 ;
struct V_50 * V_10 = V_8 -> V_10 ;
unsigned int V_136 ;
struct V_73 * V_75 ;
F_25 ( V_10 ) ;
F_114 ( V_10 , V_8 ) ;
F_41 ( & V_8 -> V_9 ) ;
for ( V_136 = 0 ; V_8 -> V_146 && V_136 < 8 * sizeof( V_8 -> V_146 ) ;
V_136 ++ ) {
if ( F_81 ( V_136 , & V_8 -> V_146 ) )
F_85 ( V_8 , V_136 ) ;
}
F_70 ( V_8 ) ;
F_115 ( V_10 ) ;
F_30 ( V_10 ) ;
F_112 ( V_10 ) ;
F_34 ( V_8 -> V_210 ) ;
F_35 ( V_8 -> V_78 ) ;
V_75 = F_42 ( V_8 ) ;
while ( V_75 ) {
F_33 ( V_75 ) ;
V_75 = F_42 ( V_8 ) ;
}
F_14 ( V_8 ) ;
return 0 ;
}
static int F_116 ( struct V_7 * V_8 , void T_4 * V_212 )
{
struct V_50 * V_10 = V_8 -> V_10 ;
struct V_213 V_214 ;
unsigned int V_215 ;
unsigned char * V_216 ;
unsigned V_217 ;
int V_53 , V_90 , V_31 ;
if ( F_117 ( & V_214 , V_212 , sizeof( V_214 ) ) )
return - V_64 ;
V_31 = F_91 ( V_8 , V_214 . V_218 , V_214 . V_219 ,
V_214 . V_220 ) ;
if ( V_31 )
return V_31 ;
V_217 = V_214 . V_217 ;
if ( V_217 > V_221 )
return - V_56 ;
V_31 = F_1 ( V_221 + sizeof( struct V_76 ) +
sizeof( struct V_222 ) ) ;
if ( V_31 )
return V_31 ;
V_216 = ( unsigned char * ) F_118 ( V_32 ) ;
if ( ! V_216 ) {
V_31 = - V_6 ;
goto V_223;
}
V_215 = V_214 . V_224 ;
F_63 ( & V_10 -> V_10 , L_21
L_22
L_23 ,
V_214 . V_218 , V_214 . V_219 , V_214 . V_225 ,
V_214 . V_220 , V_214 . V_217 ) ;
if ( V_214 . V_218 & 0x80 ) {
if ( V_214 . V_217 && ! F_119 ( V_226 , V_214 . V_94 ,
V_214 . V_217 ) ) {
V_31 = - V_56 ;
goto V_223;
}
V_90 = F_120 ( V_10 , 0 ) ;
F_46 ( V_10 , NULL , V_90 , V_214 . V_217 , V_215 , V_102 , NULL , 0 ) ;
F_30 ( V_10 ) ;
V_53 = F_121 ( V_10 , V_90 , V_214 . V_219 ,
V_214 . V_218 , V_214 . V_225 , V_214 . V_220 ,
V_216 , V_214 . V_217 , V_215 ) ;
F_25 ( V_10 ) ;
F_46 ( V_10 , NULL , V_90 , F_122 ( V_53 , 0 ) , F_29 ( V_53 , 0 ) , V_128 ,
V_216 , F_122 ( V_53 , 0 ) ) ;
if ( ( V_53 > 0 ) && V_214 . V_217 ) {
if ( F_27 ( V_214 . V_94 , V_216 , V_53 ) ) {
V_31 = - V_64 ;
goto V_223;
}
}
} else {
if ( V_214 . V_217 ) {
if ( F_117 ( V_216 , V_214 . V_94 , V_214 . V_217 ) ) {
V_31 = - V_64 ;
goto V_223;
}
}
V_90 = F_123 ( V_10 , 0 ) ;
F_46 ( V_10 , NULL , V_90 , V_214 . V_217 , V_215 , V_102 ,
V_216 , V_214 . V_217 ) ;
F_30 ( V_10 ) ;
V_53 = F_121 ( V_10 , F_123 ( V_10 , 0 ) , V_214 . V_219 ,
V_214 . V_218 , V_214 . V_225 , V_214 . V_220 ,
V_216 , V_214 . V_217 , V_215 ) ;
F_25 ( V_10 ) ;
F_46 ( V_10 , NULL , V_90 , F_122 ( V_53 , 0 ) , F_29 ( V_53 , 0 ) , V_128 , NULL , 0 ) ;
}
if ( V_53 < 0 && V_53 != - V_227 ) {
F_124 ( V_104 , & V_10 -> V_10 , L_24
L_25 ,
V_154 -> V_155 , V_214 . V_218 , V_214 . V_219 ,
V_214 . V_217 , V_53 ) ;
}
V_31 = V_53 ;
V_223:
F_125 ( ( unsigned long ) V_216 ) ;
F_6 ( V_221 + sizeof( struct V_76 ) +
sizeof( struct V_222 ) ) ;
return V_31 ;
}
static int F_126 ( struct V_7 * V_8 , void T_4 * V_212 )
{
struct V_50 * V_10 = V_8 -> V_10 ;
struct V_228 V_229 ;
unsigned int V_215 , V_230 , V_90 ;
int V_231 ;
unsigned char * V_216 ;
int V_53 , V_31 ;
if ( F_117 ( & V_229 , V_212 , sizeof( V_229 ) ) )
return - V_64 ;
V_31 = F_90 ( V_8 -> V_10 , V_229 . V_98 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_88 ( V_8 , V_31 ) ;
if ( V_31 )
return V_31 ;
if ( V_229 . V_98 & V_162 )
V_90 = F_127 ( V_10 , V_229 . V_98 & 0x7f ) ;
else
V_90 = F_128 ( V_10 , V_229 . V_98 & 0x7f ) ;
if ( ! F_129 ( V_10 , V_90 , ! ( V_229 . V_98 & V_162 ) ) )
return - V_56 ;
V_230 = V_229 . V_51 ;
if ( V_230 >= V_4 )
return - V_56 ;
V_31 = F_1 ( V_230 + sizeof( struct V_76 ) ) ;
if ( V_31 )
return V_31 ;
V_216 = F_96 ( V_230 , V_32 ) ;
if ( ! V_216 ) {
V_31 = - V_6 ;
goto V_223;
}
V_215 = V_229 . V_224 ;
if ( V_229 . V_98 & 0x80 ) {
if ( V_230 && ! F_119 ( V_226 , V_229 . V_94 , V_230 ) ) {
V_31 = - V_56 ;
goto V_223;
}
F_46 ( V_10 , NULL , V_90 , V_230 , V_215 , V_102 , NULL , 0 ) ;
F_30 ( V_10 ) ;
V_53 = F_130 ( V_10 , V_90 , V_216 , V_230 , & V_231 , V_215 ) ;
F_25 ( V_10 ) ;
F_46 ( V_10 , NULL , V_90 , V_231 , V_53 , V_128 , V_216 , V_231 ) ;
if ( ! V_53 && V_231 ) {
if ( F_27 ( V_229 . V_94 , V_216 , V_231 ) ) {
V_31 = - V_64 ;
goto V_223;
}
}
} else {
if ( V_230 ) {
if ( F_117 ( V_216 , V_229 . V_94 , V_230 ) ) {
V_31 = - V_64 ;
goto V_223;
}
}
F_46 ( V_10 , NULL , V_90 , V_230 , V_215 , V_102 , V_216 , V_230 ) ;
F_30 ( V_10 ) ;
V_53 = F_130 ( V_10 , V_90 , V_216 , V_230 , & V_231 , V_215 ) ;
F_25 ( V_10 ) ;
F_46 ( V_10 , NULL , V_90 , V_231 , V_53 , V_128 , NULL , 0 ) ;
}
V_31 = ( V_53 < 0 ? V_53 : V_231 ) ;
V_223:
F_14 ( V_216 ) ;
F_6 ( V_230 + sizeof( struct V_76 ) ) ;
return V_31 ;
}
static void F_131 ( struct V_50 * V_89 ,
unsigned int V_232 , char * V_233 )
{
struct V_185 * * V_198 ;
struct V_185 * V_98 ;
V_198 = ( V_232 & V_162 ) ? V_89 -> V_187 : V_89 -> V_189 ;
V_98 = V_198 [ V_232 & 0x0f ] ;
if ( V_98 && ! F_8 ( & V_98 -> V_234 ) )
F_76 ( & V_89 -> V_10 , L_26 ,
F_89 ( V_154 ) , V_154 -> V_155 ,
V_233 , V_232 ) ;
}
static int F_132 ( struct V_7 * V_8 , void T_4 * V_212 )
{
unsigned int V_98 ;
int V_31 ;
if ( F_95 ( V_98 , ( unsigned int T_4 * ) V_212 ) )
return - V_64 ;
V_31 = F_90 ( V_8 -> V_10 , V_98 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_88 ( V_8 , V_31 ) ;
if ( V_31 )
return V_31 ;
F_131 ( V_8 -> V_10 , V_98 , L_27 ) ;
F_133 ( V_8 -> V_10 , V_98 ) ;
return 0 ;
}
static int F_134 ( struct V_7 * V_8 , void T_4 * V_212 )
{
unsigned int V_98 ;
int V_90 ;
int V_31 ;
if ( F_95 ( V_98 , ( unsigned int T_4 * ) V_212 ) )
return - V_64 ;
V_31 = F_90 ( V_8 -> V_10 , V_98 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_88 ( V_8 , V_31 ) ;
if ( V_31 )
return V_31 ;
F_131 ( V_8 -> V_10 , V_98 , L_28 ) ;
if ( V_98 & V_162 )
V_90 = F_127 ( V_8 -> V_10 , V_98 & 0x7f ) ;
else
V_90 = F_128 ( V_8 -> V_10 , V_98 & 0x7f ) ;
return F_135 ( V_8 -> V_10 , V_90 ) ;
}
static int F_136 ( struct V_7 * V_8 , void T_4 * V_212 )
{
struct V_235 V_236 ;
struct V_140 * V_141 ;
int V_31 ;
if ( F_117 ( & V_236 , V_212 , sizeof( V_236 ) ) )
return - V_64 ;
V_141 = F_82 ( V_8 -> V_10 , V_236 . V_166 ) ;
if ( ! V_141 || ! V_141 -> V_10 . V_237 )
V_31 = - V_238 ;
else {
F_137 ( V_236 . V_237 , V_141 -> V_10 . V_237 -> V_239 ,
sizeof( V_236 . V_237 ) ) ;
V_31 = ( F_27 ( V_212 , & V_236 , sizeof( V_236 ) ) ? - V_64 : 0 ) ;
}
return V_31 ;
}
static int F_138 ( struct V_7 * V_8 , void T_4 * V_212 )
{
struct V_240 V_241 ;
memset ( & V_241 , 0 , sizeof( V_241 ) ) ;
V_241 . V_242 = V_8 -> V_10 -> V_242 ;
V_241 . V_243 = V_8 -> V_10 -> V_244 == V_245 ;
if ( F_27 ( V_212 , & V_241 , sizeof( V_241 ) ) )
return - V_64 ;
return 0 ;
}
static int F_139 ( struct V_7 * V_8 )
{
struct V_246 * V_163 = V_8 -> V_10 -> V_163 ;
struct V_140 * V_166 ;
int V_53 , V_247 ;
if ( V_8 -> V_148 && V_163 ) {
for ( V_53 = 0 ; V_53 < V_163 -> V_72 . V_165 ; ++ V_53 ) {
V_166 = V_163 -> V_166 [ V_53 ] ;
V_247 = V_166 -> V_248 -> V_72 . V_145 ;
if ( F_140 ( V_166 ) &&
! F_81 ( V_247 , & V_8 -> V_146 ) ) {
F_76 ( & V_8 -> V_10 -> V_10 ,
L_29 ,
V_247 , V_166 -> V_10 . V_237 -> V_239 , V_154 -> V_155 ) ;
return - V_150 ;
}
}
}
return F_141 ( V_8 -> V_10 ) ;
}
static int F_142 ( struct V_7 * V_8 , void T_4 * V_212 )
{
struct V_249 V_250 ;
int V_31 ;
if ( F_117 ( & V_250 , V_212 , sizeof( V_250 ) ) )
return - V_64 ;
V_31 = F_88 ( V_8 , V_250 . V_166 ) ;
if ( V_31 )
return V_31 ;
F_68 ( V_8 , V_250 . V_166 ) ;
return F_143 ( V_8 -> V_10 , V_250 . V_166 ,
V_250 . V_144 ) ;
}
static int F_144 ( struct V_7 * V_8 , void T_4 * V_212 )
{
int V_251 ;
int V_122 = 0 ;
struct V_246 * V_163 ;
if ( F_95 ( V_251 , ( int T_4 * ) V_212 ) )
return - V_64 ;
V_163 = V_8 -> V_10 -> V_163 ;
if ( V_163 ) {
int V_53 ;
for ( V_53 = 0 ; V_53 < V_163 -> V_72 . V_165 ; ++ V_53 ) {
if ( F_140 ( V_163 -> V_166 [ V_53 ] ) ) {
F_76 ( & V_8 -> V_10 -> V_10 ,
L_30
L_31 ,
V_163 -> V_166 [ V_53 ]
-> V_248
-> V_72 . V_145 ,
V_163 -> V_166 [ V_53 ]
-> V_10 . V_237 -> V_239 ,
V_154 -> V_155 , V_251 ) ;
V_122 = - V_252 ;
break;
}
}
}
if ( V_122 == 0 ) {
if ( V_163 && V_163 -> V_72 . V_253 == V_251 )
V_122 = F_145 ( V_8 -> V_10 ) ;
else
V_122 = F_146 ( V_8 -> V_10 , V_251 ) ;
}
return V_122 ;
}
static struct V_13 *
F_147 ( struct V_7 * V_8 , const struct V_254 * V_255 )
{
struct V_13 * V_14 = NULL , * V_256 ;
unsigned long V_16 ;
unsigned long V_257 = ( unsigned long ) V_255 -> V_258 ;
F_10 ( & V_8 -> V_17 , V_16 ) ;
F_45 (iter, &ps->memory_list, memlist) {
if ( V_257 >= V_256 -> V_30 &&
V_257 < V_256 -> V_30 + V_256 -> V_21 ) {
if ( V_255 -> V_259 > V_256 -> V_30 + V_256 -> V_21 -
V_257 ) {
V_14 = F_148 ( - V_56 ) ;
} else {
V_14 = V_256 ;
V_14 -> V_18 ++ ;
}
break;
}
}
F_12 ( & V_8 -> V_17 , V_16 ) ;
return V_14 ;
}
static int F_149 ( struct V_7 * V_8 , struct V_254 * V_255 ,
struct V_260 T_4 * V_261 ,
void T_4 * V_212 )
{
struct V_260 * V_262 = NULL ;
struct V_185 * V_98 ;
struct V_73 * V_75 = NULL ;
struct V_222 * V_263 = NULL ;
unsigned int V_251 , V_264 , V_265 ;
int V_53 , V_31 , V_266 , V_79 = 0 , V_136 = - 1 ;
int V_108 = 0 ;
unsigned int V_267 = 0 ;
void * V_47 ;
if ( V_255 -> V_16 & ~ ( V_268 |
V_269 |
V_270 |
V_271 |
V_272 |
V_273 ) )
return - V_56 ;
if ( V_255 -> V_259 > 0 && ! V_255 -> V_258 )
return - V_56 ;
if ( ! ( V_255 -> type == V_274 &&
( V_255 -> V_169 & ~ V_186 ) == 0 ) ) {
V_136 = F_90 ( V_8 -> V_10 , V_255 -> V_169 ) ;
if ( V_136 < 0 )
return V_136 ;
V_31 = F_88 ( V_8 , V_136 ) ;
if ( V_31 )
return V_31 ;
}
V_98 = F_93 ( V_8 -> V_10 , V_255 -> V_169 ) ;
if ( ! V_98 )
return - V_133 ;
V_266 = ( V_255 -> V_169 & V_186 ) != 0 ;
V_251 = 0 ;
switch ( V_255 -> type ) {
case V_274 :
if ( ! F_150 ( & V_98 -> V_72 ) )
return - V_56 ;
if ( V_255 -> V_259 < 8 )
return - V_56 ;
V_263 = F_96 ( sizeof( struct V_222 ) , V_32 ) ;
if ( ! V_263 )
return - V_6 ;
if ( F_117 ( V_263 , V_255 -> V_258 , 8 ) ) {
V_31 = - V_64 ;
goto error;
}
if ( V_255 -> V_259 < ( F_151 ( & V_263 -> V_217 ) + 8 ) ) {
V_31 = - V_56 ;
goto error;
}
V_31 = F_91 ( V_8 , V_263 -> V_218 , V_263 -> V_219 ,
F_151 ( & V_263 -> V_220 ) ) ;
if ( V_31 )
goto error;
V_255 -> V_259 = F_151 ( & V_263 -> V_217 ) ;
V_255 -> V_258 += 8 ;
if ( ( V_263 -> V_218 & V_162 ) && V_255 -> V_259 ) {
V_266 = 1 ;
V_255 -> V_169 |= V_162 ;
} else {
V_266 = 0 ;
V_255 -> V_169 &= ~ V_162 ;
}
F_63 ( & V_8 -> V_10 -> V_10 , L_21
L_22
L_23 ,
V_263 -> V_218 , V_263 -> V_219 ,
F_152 ( & V_263 -> V_225 ) ,
F_152 ( & V_263 -> V_220 ) ,
F_152 ( & V_263 -> V_217 ) ) ;
V_251 = sizeof( struct V_222 ) ;
break;
case V_275 :
switch ( F_153 ( & V_98 -> V_72 ) ) {
case V_276 :
case V_277 :
return - V_56 ;
case V_278 :
V_255 -> type = V_279 ;
goto V_280;
}
V_79 = F_154 ( V_255 -> V_259 , V_106 ) ;
if ( V_79 == 1 || V_79 > V_8 -> V_10 -> V_281 -> V_282 )
V_79 = 0 ;
if ( V_98 -> V_191 )
V_267 = V_255 -> V_267 ;
break;
case V_279 :
if ( ! F_155 ( & V_98 -> V_72 ) )
return - V_56 ;
V_280:
break;
case V_283 :
if ( V_255 -> V_108 < 1 ||
V_255 -> V_108 > 128 )
return - V_56 ;
if ( ! F_156 ( & V_98 -> V_72 ) )
return - V_56 ;
V_108 = V_255 -> V_108 ;
V_265 = sizeof( struct V_260 ) *
V_108 ;
V_262 = F_157 ( V_261 , V_265 ) ;
if ( F_158 ( V_262 ) ) {
V_31 = F_159 ( V_262 ) ;
V_262 = NULL ;
goto error;
}
for ( V_264 = V_251 = 0 ; V_251 < V_108 ; V_251 ++ ) {
if ( V_262 [ V_251 ] . V_69 > 49152 ) {
V_31 = - V_56 ;
goto error;
}
V_264 += V_262 [ V_251 ] . V_69 ;
}
V_251 *= sizeof( struct V_284 ) ;
V_255 -> V_259 = V_264 ;
break;
default:
return - V_56 ;
}
if ( V_255 -> V_259 >= V_4 ) {
V_31 = - V_56 ;
goto error;
}
if ( V_255 -> V_259 > 0 &&
! F_119 ( V_266 ? V_226 : V_285 ,
V_255 -> V_258 , V_255 -> V_259 ) ) {
V_31 = - V_64 ;
goto error;
}
V_75 = F_31 ( V_108 ) ;
if ( ! V_75 ) {
V_31 = - V_6 ;
goto error;
}
V_75 -> V_14 = F_147 ( V_8 , V_255 ) ;
if ( F_158 ( V_75 -> V_14 ) ) {
V_31 = F_159 ( V_75 -> V_14 ) ;
V_75 -> V_14 = NULL ;
goto error;
}
if ( V_75 -> V_14 )
V_79 = 0 ;
V_251 += sizeof( struct V_73 ) + sizeof( struct V_76 ) + V_255 -> V_259 +
V_79 * sizeof( struct V_286 ) ;
V_31 = F_1 ( V_251 ) ;
if ( V_31 )
goto error;
V_75 -> V_83 = V_251 ;
if ( V_79 ) {
V_75 -> V_76 -> V_80 = F_96 ( V_79 * sizeof( struct V_286 ) ,
V_32 ) ;
if ( ! V_75 -> V_76 -> V_80 ) {
V_31 = - V_6 ;
goto error;
}
V_75 -> V_76 -> V_79 = V_79 ;
F_160 ( V_75 -> V_76 -> V_80 , V_75 -> V_76 -> V_79 ) ;
V_264 = V_255 -> V_259 ;
for ( V_53 = 0 ; V_53 < V_75 -> V_76 -> V_79 ; V_53 ++ ) {
V_251 = ( V_264 > V_106 ) ? V_106 : V_264 ;
V_47 = F_96 ( V_251 , V_32 ) ;
if ( ! V_47 ) {
V_31 = - V_6 ;
goto error;
}
F_161 ( & V_75 -> V_76 -> V_80 [ V_53 ] , V_47 , V_251 ) ;
if ( ! V_266 ) {
if ( F_117 ( V_47 , V_255 -> V_258 , V_251 ) ) {
V_31 = - V_64 ;
goto error;
}
V_255 -> V_258 += V_251 ;
}
V_264 -= V_251 ;
}
} else if ( V_255 -> V_259 > 0 ) {
if ( V_75 -> V_14 ) {
unsigned long V_257 = ( unsigned long ) V_255 -> V_258 ;
V_75 -> V_76 -> V_81 = V_75 -> V_14 -> V_22 +
( V_257 - V_75 -> V_14 -> V_30 ) ;
} else {
V_75 -> V_76 -> V_81 = F_96 ( V_255 -> V_259 ,
V_32 ) ;
if ( ! V_75 -> V_76 -> V_81 ) {
V_31 = - V_6 ;
goto error;
}
if ( ! V_266 ) {
if ( F_117 ( V_75 -> V_76 -> V_81 ,
V_255 -> V_258 ,
V_255 -> V_259 ) ) {
V_31 = - V_64 ;
goto error;
}
} else if ( V_255 -> type == V_283 ) {
memset ( V_75 -> V_76 -> V_81 , 0 ,
V_255 -> V_259 ) ;
}
}
}
V_75 -> V_76 -> V_10 = V_8 -> V_10 ;
V_75 -> V_76 -> V_90 = ( V_255 -> type << 30 ) |
F_162 ( V_8 -> V_10 , V_255 -> V_169 & 0xf ) |
( V_255 -> V_169 & V_162 ) ;
V_251 = ( V_266 ? V_131 : V_287 ) ;
if ( V_255 -> V_16 & V_268 )
V_251 |= V_288 ;
if ( V_255 -> V_16 & V_269 && V_266 )
V_251 |= V_289 ;
if ( V_255 -> V_16 & V_271 )
V_251 |= V_290 ;
if ( V_255 -> V_16 & V_272 )
V_251 |= V_291 ;
if ( V_255 -> V_16 & V_273 )
V_251 |= V_292 ;
V_75 -> V_76 -> V_129 = V_251 ;
V_75 -> V_76 -> V_109 = V_255 -> V_259 ;
V_75 -> V_76 -> V_82 = ( unsigned char * ) V_263 ;
V_263 = NULL ;
V_75 -> V_76 -> V_293 = V_255 -> V_293 ;
V_75 -> V_76 -> V_108 = V_108 ;
V_75 -> V_76 -> V_267 = V_267 ;
if ( V_98 -> V_72 . V_294 ) {
if ( V_255 -> type == V_283 ||
V_8 -> V_10 -> V_244 == V_295 ||
V_8 -> V_10 -> V_244 >= V_296 )
V_75 -> V_76 -> V_297 = 1 <<
F_29 ( 15 , V_98 -> V_72 . V_294 - 1 ) ;
else
V_75 -> V_76 -> V_297 = V_98 -> V_72 . V_294 ;
}
V_75 -> V_76 -> V_117 = V_75 ;
V_75 -> V_76 -> V_298 = V_86 ;
for ( V_264 = V_251 = 0 ; V_251 < V_108 ; V_251 ++ ) {
V_75 -> V_76 -> V_261 [ V_251 ] . V_299 = V_264 ;
V_75 -> V_76 -> V_261 [ V_251 ] . V_69 = V_262 [ V_251 ] . V_69 ;
V_264 += V_262 [ V_251 ] . V_69 ;
}
F_14 ( V_262 ) ;
V_262 = NULL ;
V_75 -> V_8 = V_8 ;
V_75 -> V_88 = V_212 ;
if ( V_75 -> V_14 ) {
unsigned long V_257 = ( unsigned long ) V_255 -> V_258 ;
V_75 -> V_76 -> V_129 |= V_300 ;
V_75 -> V_76 -> V_301 = V_75 -> V_14 -> V_23 +
( V_257 - V_75 -> V_14 -> V_30 ) ;
} else if ( V_266 && V_255 -> V_259 > 0 )
V_75 -> V_107 = V_255 -> V_258 ;
V_75 -> V_121 = V_255 -> V_121 ;
V_75 -> V_136 = V_136 ;
V_75 -> V_77 = F_61 ( F_108 ( V_154 ) ) ;
V_75 -> V_78 = F_109 () ;
F_110 ( V_154 , & V_75 -> V_120 ) ;
F_46 ( V_8 -> V_10 , V_75 -> V_88 , V_75 -> V_76 -> V_90 ,
V_75 -> V_76 -> V_109 , 0 , V_102 ,
NULL , 0 ) ;
if ( ! V_266 )
F_52 ( V_75 -> V_76 , V_75 -> V_76 -> V_109 ) ;
F_39 ( V_75 ) ;
if ( F_163 ( & V_98 -> V_72 ) ) {
F_164 ( & V_8 -> V_17 ) ;
V_75 -> V_111 = F_165 ( & V_98 -> V_72 ) |
( ( V_98 -> V_72 . V_170 & V_186 )
>> 3 ) ;
if ( V_255 -> V_16 & V_270 )
V_75 -> V_112 = V_113 ;
else
V_8 -> V_116 &= ~ ( 1 << V_75 -> V_111 ) ;
if ( V_8 -> V_116 & ( 1 << V_75 -> V_111 ) )
V_31 = - V_302 ;
else
V_31 = F_166 ( V_75 -> V_76 , V_303 ) ;
F_167 ( & V_8 -> V_17 ) ;
} else {
V_31 = F_166 ( V_75 -> V_76 , V_32 ) ;
}
if ( V_31 ) {
F_124 ( V_104 , & V_8 -> V_10 -> V_10 ,
L_32 , V_31 ) ;
F_46 ( V_8 -> V_10 , V_75 -> V_88 , V_75 -> V_76 -> V_90 ,
0 , V_31 , V_128 , NULL , 0 ) ;
F_40 ( V_75 ) ;
goto error;
}
return 0 ;
error:
if ( V_75 && V_75 -> V_14 )
F_9 ( V_75 -> V_14 , & V_75 -> V_14 -> V_18 ) ;
F_14 ( V_262 ) ;
F_14 ( V_263 ) ;
if ( V_75 )
F_33 ( V_75 ) ;
return V_31 ;
}
static int F_168 ( struct V_7 * V_8 , void T_4 * V_212 )
{
struct V_254 V_255 ;
if ( F_117 ( & V_255 , V_212 , sizeof( V_255 ) ) )
return - V_64 ;
return F_149 ( V_8 , & V_255 ,
( ( (struct V_254 T_4 * ) V_212 ) -> V_261 ) ,
V_212 ) ;
}
static int F_169 ( struct V_7 * V_8 , void T_4 * V_212 )
{
struct V_76 * V_76 ;
struct V_73 * V_75 ;
unsigned long V_16 ;
F_10 ( & V_8 -> V_17 , V_16 ) ;
V_75 = F_44 ( V_8 , V_212 ) ;
if ( ! V_75 ) {
F_12 ( & V_8 -> V_17 , V_16 ) ;
return - V_56 ;
}
V_76 = V_75 -> V_76 ;
F_55 ( V_76 ) ;
F_12 ( & V_8 -> V_17 , V_16 ) ;
F_67 ( V_76 ) ;
F_58 ( V_76 ) ;
return 0 ;
}
static int F_170 ( struct V_73 * V_75 , void T_4 * T_4 * V_212 )
{
struct V_76 * V_76 = V_75 -> V_76 ;
struct V_254 T_4 * V_88 = V_75 -> V_88 ;
void T_4 * V_304 = V_75 -> V_88 ;
unsigned int V_53 ;
if ( V_75 -> V_107 && V_76 -> V_110 ) {
if ( F_53 ( V_75 -> V_107 , V_76 ) )
goto V_305;
}
if ( F_171 ( V_75 -> V_122 , & V_88 -> V_122 ) )
goto V_305;
if ( F_171 ( V_76 -> V_110 , & V_88 -> V_110 ) )
goto V_305;
if ( F_171 ( V_76 -> V_306 , & V_88 -> V_306 ) )
goto V_305;
if ( F_156 ( & V_76 -> V_98 -> V_72 ) ) {
for ( V_53 = 0 ; V_53 < V_76 -> V_108 ; V_53 ++ ) {
if ( F_171 ( V_76 -> V_261 [ V_53 ] . V_110 ,
& V_88 -> V_261 [ V_53 ] . V_110 ) )
goto V_305;
if ( F_171 ( V_76 -> V_261 [ V_53 ] . V_122 ,
& V_88 -> V_261 [ V_53 ] . V_122 ) )
goto V_305;
}
}
if ( F_171 ( V_304 , ( void T_4 * T_4 * ) V_212 ) )
return - V_64 ;
return 0 ;
V_305:
return - V_64 ;
}
static struct V_73 * F_172 ( struct V_7 * V_8 )
{
F_173 ( V_134 , V_154 ) ;
struct V_73 * V_75 = NULL ;
struct V_50 * V_10 = V_8 -> V_10 ;
F_174 ( & V_8 -> V_134 , & V_134 ) ;
for (; ; ) {
F_175 ( V_307 ) ;
V_75 = F_42 ( V_8 ) ;
if ( V_75 || ! F_7 ( V_8 ) )
break;
if ( F_176 ( V_154 ) )
break;
F_30 ( V_10 ) ;
F_177 () ;
F_25 ( V_10 ) ;
}
F_178 ( & V_8 -> V_134 , & V_134 ) ;
F_179 ( V_308 ) ;
return V_75 ;
}
static int F_180 ( struct V_7 * V_8 , void T_4 * V_212 )
{
struct V_73 * V_75 = F_172 ( V_8 ) ;
if ( V_75 ) {
int V_309 ;
F_63 ( & V_8 -> V_10 -> V_10 , L_33 , V_75 -> V_88 ) ;
V_309 = F_170 ( V_75 , ( void T_4 * T_4 * ) V_212 ) ;
F_33 ( V_75 ) ;
return V_309 ;
}
if ( F_176 ( V_154 ) )
return - V_310 ;
return - V_54 ;
}
static int F_181 ( struct V_7 * V_8 , void T_4 * V_212 )
{
int V_309 ;
struct V_73 * V_75 ;
V_75 = F_42 ( V_8 ) ;
if ( V_75 ) {
F_63 ( & V_8 -> V_10 -> V_10 , L_33 , V_75 -> V_88 ) ;
V_309 = F_170 ( V_75 , ( void T_4 * T_4 * ) V_212 ) ;
F_33 ( V_75 ) ;
} else {
V_309 = ( F_7 ( V_8 ) ? - V_39 : - V_54 ) ;
}
return V_309 ;
}
static int F_182 ( struct V_7 * V_8 ,
struct V_311 T_4 * V_312 )
{
struct V_213 T_4 * V_137 ;
T_9 V_313 ;
V_137 = F_183 ( sizeof( * V_137 ) ) ;
if ( F_184 ( V_137 , V_312 , ( sizeof( * V_312 ) - sizeof( V_314 ) ) ) ||
F_95 ( V_313 , & V_312 -> V_94 ) ||
F_171 ( F_185 ( V_313 ) , & V_137 -> V_94 ) )
return - V_64 ;
return F_116 ( V_8 , V_137 ) ;
}
static int F_186 ( struct V_7 * V_8 ,
struct V_315 T_4 * V_312 )
{
struct V_228 T_4 * V_137 ;
T_10 V_316 ;
V_314 V_304 ;
V_137 = F_183 ( sizeof( * V_137 ) ) ;
if ( F_95 ( V_316 , & V_312 -> V_98 ) || F_171 ( V_316 , & V_137 -> V_98 ) ||
F_95 ( V_316 , & V_312 -> V_51 ) || F_171 ( V_316 , & V_137 -> V_51 ) ||
F_95 ( V_316 , & V_312 -> V_224 ) || F_171 ( V_316 , & V_137 -> V_224 ) ||
F_95 ( V_304 , & V_312 -> V_94 ) || F_171 ( F_185 ( V_304 ) , & V_137 -> V_94 ) )
return - V_64 ;
return F_126 ( V_8 , V_137 ) ;
}
static int F_187 ( struct V_7 * V_8 , void T_4 * V_212 )
{
struct V_317 V_318 ;
if ( F_117 ( & V_318 , V_212 , sizeof( V_318 ) ) )
return - V_64 ;
V_8 -> V_319 = V_318 . V_121 ;
V_8 -> V_320 = F_185 ( V_318 . V_117 ) ;
return 0 ;
}
static int F_188 ( struct V_254 * V_321 ,
struct V_322 T_4 * V_255 )
{
T_9 V_323 ;
if ( ! F_119 ( V_285 , V_255 , sizeof( * V_255 ) ) ||
F_189 ( V_321 -> type , & V_255 -> type ) ||
F_189 ( V_321 -> V_169 , & V_255 -> V_169 ) ||
F_189 ( V_321 -> V_122 , & V_255 -> V_122 ) ||
F_189 ( V_321 -> V_16 , & V_255 -> V_16 ) ||
F_189 ( V_321 -> V_259 , & V_255 -> V_259 ) ||
F_189 ( V_321 -> V_110 , & V_255 -> V_110 ) ||
F_189 ( V_321 -> V_293 , & V_255 -> V_293 ) ||
F_189 ( V_321 -> V_108 , & V_255 -> V_108 ) ||
F_189 ( V_321 -> V_306 , & V_255 -> V_306 ) ||
F_189 ( V_321 -> V_121 , & V_255 -> V_121 ) )
return - V_64 ;
if ( F_189 ( V_323 , & V_255 -> V_258 ) )
return - V_64 ;
V_321 -> V_258 = F_185 ( V_323 ) ;
if ( F_189 ( V_323 , & V_255 -> V_324 ) )
return - V_64 ;
V_321 -> V_324 = F_185 ( V_323 ) ;
return 0 ;
}
static int F_190 ( struct V_7 * V_8 , void T_4 * V_212 )
{
struct V_254 V_255 ;
if ( F_188 ( & V_255 , (struct V_322 T_4 * ) V_212 ) )
return - V_64 ;
return F_149 ( V_8 , & V_255 ,
( (struct V_322 T_4 * ) V_212 ) -> V_261 ,
V_212 ) ;
}
static int F_191 ( struct V_73 * V_75 , void T_4 * T_4 * V_212 )
{
struct V_76 * V_76 = V_75 -> V_76 ;
struct V_322 T_4 * V_88 = V_75 -> V_88 ;
void T_4 * V_304 = V_75 -> V_88 ;
unsigned int V_53 ;
if ( V_75 -> V_107 && V_76 -> V_110 ) {
if ( F_53 ( V_75 -> V_107 , V_76 ) )
return - V_64 ;
}
if ( F_171 ( V_75 -> V_122 , & V_88 -> V_122 ) )
return - V_64 ;
if ( F_171 ( V_76 -> V_110 , & V_88 -> V_110 ) )
return - V_64 ;
if ( F_171 ( V_76 -> V_306 , & V_88 -> V_306 ) )
return - V_64 ;
if ( F_156 ( & V_76 -> V_98 -> V_72 ) ) {
for ( V_53 = 0 ; V_53 < V_76 -> V_108 ; V_53 ++ ) {
if ( F_171 ( V_76 -> V_261 [ V_53 ] . V_110 ,
& V_88 -> V_261 [ V_53 ] . V_110 ) )
return - V_64 ;
if ( F_171 ( V_76 -> V_261 [ V_53 ] . V_122 ,
& V_88 -> V_261 [ V_53 ] . V_122 ) )
return - V_64 ;
}
}
if ( F_171 ( F_192 ( V_304 ) , ( T_7 T_4 * ) V_212 ) )
return - V_64 ;
return 0 ;
}
static int F_193 ( struct V_7 * V_8 , void T_4 * V_212 )
{
struct V_73 * V_75 = F_172 ( V_8 ) ;
if ( V_75 ) {
int V_309 ;
F_63 ( & V_8 -> V_10 -> V_10 , L_33 , V_75 -> V_88 ) ;
V_309 = F_191 ( V_75 , ( void T_4 * T_4 * ) V_212 ) ;
F_33 ( V_75 ) ;
return V_309 ;
}
if ( F_176 ( V_154 ) )
return - V_310 ;
return - V_54 ;
}
static int F_194 ( struct V_7 * V_8 , void T_4 * V_212 )
{
int V_309 ;
struct V_73 * V_75 ;
V_75 = F_42 ( V_8 ) ;
if ( V_75 ) {
F_63 ( & V_8 -> V_10 -> V_10 , L_33 , V_75 -> V_88 ) ;
V_309 = F_191 ( V_75 , ( void T_4 * T_4 * ) V_212 ) ;
F_33 ( V_75 ) ;
} else {
V_309 = ( F_7 ( V_8 ) ? - V_39 : - V_54 ) ;
}
return V_309 ;
}
static int F_195 ( struct V_7 * V_8 , void T_4 * V_212 )
{
struct V_325 V_318 ;
if ( F_117 ( & V_318 , V_212 , sizeof( V_318 ) ) )
return - V_64 ;
V_8 -> V_319 = V_318 . V_121 ;
V_8 -> V_320 = V_318 . V_117 ;
return 0 ;
}
static int F_196 ( struct V_7 * V_8 , void T_4 * V_212 )
{
unsigned int V_136 ;
if ( F_95 ( V_136 , ( unsigned int T_4 * ) V_212 ) )
return - V_64 ;
return F_80 ( V_8 , V_136 ) ;
}
static int F_197 ( struct V_7 * V_8 , void T_4 * V_212 )
{
unsigned int V_136 ;
int V_31 ;
if ( F_95 ( V_136 , ( unsigned int T_4 * ) V_212 ) )
return - V_64 ;
V_31 = F_85 ( V_8 , V_136 ) ;
if ( V_31 < 0 )
return V_31 ;
F_68 ( V_8 , V_136 ) ;
return 0 ;
}
static int F_198 ( struct V_7 * V_8 , struct V_326 * V_327 )
{
int V_21 ;
void * V_47 = NULL ;
int V_309 = 0 ;
struct V_140 * V_141 = NULL ;
struct V_328 * V_237 = NULL ;
if ( V_8 -> V_148 )
return - V_150 ;
V_21 = F_199 ( V_327 -> V_329 ) ;
if ( V_21 > 0 ) {
V_47 = F_96 ( V_21 , V_32 ) ;
if ( V_47 == NULL )
return - V_6 ;
if ( ( F_200 ( V_327 -> V_329 ) & V_330 ) ) {
if ( F_117 ( V_47 , V_327 -> V_94 , V_21 ) ) {
F_14 ( V_47 ) ;
return - V_64 ;
}
} else {
memset ( V_47 , 0 , V_21 ) ;
}
}
if ( ! F_7 ( V_8 ) ) {
F_14 ( V_47 ) ;
return - V_54 ;
}
if ( V_8 -> V_10 -> V_11 != V_152 )
V_309 = - V_153 ;
else if ( ! ( V_141 = F_82 ( V_8 -> V_10 , V_327 -> V_331 ) ) )
V_309 = - V_56 ;
else switch ( V_327 -> V_329 ) {
case V_332 :
if ( V_141 -> V_10 . V_237 ) {
V_237 = F_201 ( V_141 -> V_10 . V_237 ) ;
F_202 ( & V_141 -> V_10 , L_34 ) ;
F_87 ( V_237 , V_141 ) ;
} else
V_309 = - V_238 ;
break;
case V_333 :
if ( ! V_141 -> V_10 . V_237 )
V_309 = F_203 ( & V_141 -> V_10 ) ;
else
V_309 = - V_252 ;
break;
default:
if ( V_141 -> V_10 . V_237 )
V_237 = F_201 ( V_141 -> V_10 . V_237 ) ;
if ( V_237 == NULL || V_237 -> V_334 == NULL ) {
V_309 = - V_335 ;
} else {
V_309 = V_237 -> V_334 ( V_141 , V_327 -> V_329 , V_47 ) ;
if ( V_309 == - V_336 )
V_309 = - V_335 ;
}
}
if ( V_309 >= 0
&& ( F_200 ( V_327 -> V_329 ) & V_337 ) != 0
&& V_21 > 0
&& F_27 ( V_327 -> V_94 , V_47 , V_21 ) != 0 )
V_309 = - V_64 ;
F_14 ( V_47 ) ;
return V_309 ;
}
static int F_204 ( struct V_7 * V_8 , void T_4 * V_212 )
{
struct V_326 V_214 ;
if ( F_117 ( & V_214 , V_212 , sizeof( V_214 ) ) )
return - V_64 ;
return F_198 ( V_8 , & V_214 ) ;
}
static int F_205 ( struct V_7 * V_8 , T_11 V_212 )
{
struct V_338 T_4 * V_339 ;
struct V_326 V_214 ;
T_7 V_313 ;
V_339 = F_185 ( ( long ) V_212 ) ;
if ( ! F_119 ( V_285 , V_339 , sizeof( * V_339 ) ) ||
F_189 ( V_214 . V_331 , & V_339 -> V_331 ) ||
F_189 ( V_214 . V_329 , & V_339 -> V_329 ) ||
F_189 ( V_313 , & V_339 -> V_94 ) )
return - V_64 ;
V_214 . V_94 = F_185 ( V_313 ) ;
return F_198 ( V_8 , & V_214 ) ;
}
static int F_206 ( struct V_7 * V_8 , void T_4 * V_212 )
{
unsigned V_340 ;
int V_341 ;
if ( F_95 ( V_340 , ( unsigned T_4 * ) V_212 ) )
return - V_64 ;
V_341 = F_207 ( V_8 -> V_10 , V_340 , V_8 ) ;
if ( V_341 == 0 )
F_63 ( & V_8 -> V_10 -> V_10 , L_35 ,
V_340 , F_89 ( V_154 ) , V_154 -> V_155 ) ;
return V_341 ;
}
static int F_208 ( struct V_7 * V_8 , void T_4 * V_212 )
{
unsigned V_340 ;
if ( F_95 ( V_340 , ( unsigned T_4 * ) V_212 ) )
return - V_64 ;
return F_209 ( V_8 -> V_10 , V_340 , V_8 ) ;
}
static int F_210 ( struct V_7 * V_8 , void T_4 * V_212 )
{
T_9 V_342 ;
V_342 = V_343 | V_344 |
V_345 | V_346 |
V_347 ;
if ( ! V_8 -> V_10 -> V_281 -> V_348 )
V_342 |= V_349 ;
if ( V_8 -> V_10 -> V_281 -> V_282 )
V_342 |= V_350 ;
if ( F_171 ( V_342 , ( T_9 T_4 * ) V_212 ) )
return - V_64 ;
return 0 ;
}
static int F_211 ( struct V_7 * V_8 , void T_4 * V_212 )
{
struct V_351 V_352 ;
struct V_140 * V_141 ;
if ( F_117 ( & V_352 , V_212 , sizeof( V_352 ) ) )
return - V_64 ;
V_141 = F_82 ( V_8 -> V_10 , V_352 . V_166 ) ;
if ( ! V_141 )
return - V_56 ;
if ( V_141 -> V_10 . V_237 ) {
struct V_328 * V_237 = F_201 ( V_141 -> V_10 . V_237 ) ;
if ( V_8 -> V_148 )
return - V_150 ;
if ( ( V_352 . V_16 & V_353 ) &&
strncmp ( V_352 . V_237 , V_141 -> V_10 . V_237 -> V_239 ,
sizeof( V_352 . V_237 ) ) != 0 )
return - V_252 ;
if ( ( V_352 . V_16 & V_354 ) &&
strncmp ( V_352 . V_237 , V_141 -> V_10 . V_237 -> V_239 ,
sizeof( V_352 . V_237 ) ) == 0 )
return - V_252 ;
F_202 ( & V_141 -> V_10 , L_34 ) ;
F_87 ( V_237 , V_141 ) ;
}
return F_80 ( V_8 , V_352 . V_166 ) ;
}
static int F_212 ( struct V_7 * V_8 , void T_4 * V_212 )
{
unsigned V_196 , V_197 ;
struct V_185 * * V_198 ;
struct V_140 * V_141 ;
int V_355 ;
V_355 = F_94 ( V_8 , V_212 , & V_196 , & V_197 ,
& V_198 , & V_141 ) ;
if ( V_355 )
return V_355 ;
F_68 ( V_8 ,
V_141 -> V_144 [ 0 ] . V_72 . V_145 ) ;
V_355 = F_213 ( V_141 , V_198 , V_197 , V_196 , V_32 ) ;
F_14 ( V_198 ) ;
return V_355 ;
}
static int F_214 ( struct V_7 * V_8 , void T_4 * V_212 )
{
unsigned V_197 ;
struct V_185 * * V_198 ;
struct V_140 * V_141 ;
int V_355 ;
V_355 = F_94 ( V_8 , V_212 , NULL , & V_197 , & V_198 , & V_141 ) ;
if ( V_355 )
return V_355 ;
F_68 ( V_8 ,
V_141 -> V_144 [ 0 ] . V_72 . V_145 ) ;
V_355 = F_215 ( V_141 , V_198 , V_197 , V_32 ) ;
F_14 ( V_198 ) ;
return V_355 ;
}
static int F_216 ( struct V_7 * V_8 , void T_4 * V_212 )
{
T_7 V_94 ;
if ( F_117 ( & V_94 , V_212 , sizeof( V_94 ) ) )
return - V_64 ;
V_8 -> V_149 &= V_94 ;
V_8 -> V_148 = true ;
return 0 ;
}
static long F_217 ( struct V_27 * V_27 , unsigned int V_356 ,
void T_4 * V_137 )
{
struct V_7 * V_8 = V_27 -> V_28 ;
struct V_204 * V_204 = F_218 ( V_27 ) ;
struct V_50 * V_10 = V_8 -> V_10 ;
int V_31 = - V_335 ;
if ( ! ( V_27 -> V_357 & V_358 ) )
return - V_359 ;
F_25 ( V_10 ) ;
switch ( V_356 ) {
case V_360 :
F_63 ( & V_10 -> V_10 , L_36 , V_183 ) ;
V_31 = F_180 ( V_8 , V_137 ) ;
goto V_223;
case V_361 :
F_63 ( & V_10 -> V_10 , L_37 , V_183 ) ;
V_31 = F_181 ( V_8 , V_137 ) ;
goto V_223;
#ifdef F_219
case V_362 :
F_63 ( & V_10 -> V_10 , L_38 , V_183 ) ;
V_31 = F_193 ( V_8 , V_137 ) ;
goto V_223;
case V_363 :
F_63 ( & V_10 -> V_10 , L_39 , V_183 ) ;
V_31 = F_194 ( V_8 , V_137 ) ;
goto V_223;
#endif
}
if ( ! F_7 ( V_8 ) ) {
F_30 ( V_10 ) ;
return - V_54 ;
}
switch ( V_356 ) {
case V_364 :
F_63 ( & V_10 -> V_10 , L_40 , V_183 ) ;
V_31 = F_116 ( V_8 , V_137 ) ;
if ( V_31 >= 0 )
V_204 -> V_365 = V_366 ;
break;
case V_367 :
F_63 ( & V_10 -> V_10 , L_41 , V_183 ) ;
V_31 = F_126 ( V_8 , V_137 ) ;
if ( V_31 >= 0 )
V_204 -> V_365 = V_366 ;
break;
case V_368 :
F_63 ( & V_10 -> V_10 , L_42 , V_183 ) ;
V_31 = F_132 ( V_8 , V_137 ) ;
if ( V_31 >= 0 )
V_204 -> V_365 = V_366 ;
break;
case V_369 :
F_63 ( & V_10 -> V_10 , L_43 , V_183 ) ;
V_31 = F_139 ( V_8 ) ;
break;
case V_370 :
F_63 ( & V_10 -> V_10 , L_44 , V_183 ) ;
V_31 = F_134 ( V_8 , V_137 ) ;
if ( V_31 >= 0 )
V_204 -> V_365 = V_366 ;
break;
case V_371 :
F_63 ( & V_10 -> V_10 , L_45 , V_183 ) ;
V_31 = F_136 ( V_8 , V_137 ) ;
break;
case V_372 :
F_63 ( & V_10 -> V_10 , L_46 , V_183 ) ;
V_31 = F_138 ( V_8 , V_137 ) ;
break;
case V_373 :
F_63 ( & V_10 -> V_10 , L_47 , V_183 ) ;
V_31 = F_142 ( V_8 , V_137 ) ;
break;
case V_374 :
F_63 ( & V_10 -> V_10 , L_48 , V_183 ) ;
V_31 = F_144 ( V_8 , V_137 ) ;
break;
case V_375 :
F_63 ( & V_10 -> V_10 , L_49 , V_183 ) ;
V_31 = F_168 ( V_8 , V_137 ) ;
if ( V_31 >= 0 )
V_204 -> V_365 = V_366 ;
break;
#ifdef F_219
case V_376 :
F_63 ( & V_10 -> V_10 , L_50 , V_183 ) ;
V_31 = F_182 ( V_8 , V_137 ) ;
if ( V_31 >= 0 )
V_204 -> V_365 = V_366 ;
break;
case V_377 :
F_63 ( & V_10 -> V_10 , L_51 , V_183 ) ;
V_31 = F_186 ( V_8 , V_137 ) ;
if ( V_31 >= 0 )
V_204 -> V_365 = V_366 ;
break;
case V_378 :
F_63 ( & V_10 -> V_10 , L_52 , V_183 ) ;
V_31 = F_187 ( V_8 , V_137 ) ;
break;
case V_379 :
F_63 ( & V_10 -> V_10 , L_53 , V_183 ) ;
V_31 = F_190 ( V_8 , V_137 ) ;
if ( V_31 >= 0 )
V_204 -> V_365 = V_366 ;
break;
case V_380 :
F_63 ( & V_10 -> V_10 , L_54 , V_183 ) ;
V_31 = F_205 ( V_8 , F_192 ( V_137 ) ) ;
break;
#endif
case V_381 :
F_63 ( & V_10 -> V_10 , L_55 , V_183 , V_137 ) ;
V_31 = F_169 ( V_8 , V_137 ) ;
break;
case V_382 :
F_63 ( & V_10 -> V_10 , L_56 , V_183 ) ;
V_31 = F_195 ( V_8 , V_137 ) ;
break;
case V_383 :
F_63 ( & V_10 -> V_10 , L_57 , V_183 ) ;
V_31 = F_196 ( V_8 , V_137 ) ;
break;
case V_384 :
F_63 ( & V_10 -> V_10 , L_58 , V_183 ) ;
V_31 = F_197 ( V_8 , V_137 ) ;
break;
case V_385 :
F_63 ( & V_10 -> V_10 , L_59 , V_183 ) ;
V_31 = F_204 ( V_8 , V_137 ) ;
break;
case V_386 :
F_63 ( & V_10 -> V_10 , L_60 , V_183 ) ;
V_31 = F_206 ( V_8 , V_137 ) ;
break;
case V_387 :
F_63 ( & V_10 -> V_10 , L_61 , V_183 ) ;
V_31 = F_208 ( V_8 , V_137 ) ;
break;
case V_388 :
V_31 = F_210 ( V_8 , V_137 ) ;
break;
case V_389 :
V_31 = F_211 ( V_8 , V_137 ) ;
break;
case V_390 :
V_31 = F_212 ( V_8 , V_137 ) ;
break;
case V_391 :
V_31 = F_214 ( V_8 , V_137 ) ;
break;
case V_392 :
V_31 = F_216 ( V_8 , V_137 ) ;
break;
}
V_223:
F_30 ( V_10 ) ;
if ( V_31 >= 0 )
V_204 -> V_393 = V_366 ;
return V_31 ;
}
static long F_220 ( struct V_27 * V_27 , unsigned int V_356 ,
unsigned long V_212 )
{
int V_31 ;
V_31 = F_217 ( V_27 , V_356 , ( void T_4 * ) V_212 ) ;
return V_31 ;
}
static long F_221 ( struct V_27 * V_27 , unsigned int V_356 ,
unsigned long V_212 )
{
int V_31 ;
V_31 = F_217 ( V_27 , V_356 , F_185 ( V_212 ) ) ;
return V_31 ;
}
static unsigned int F_222 ( struct V_27 * V_27 ,
struct V_394 * V_134 )
{
struct V_7 * V_8 = V_27 -> V_28 ;
unsigned int V_395 = 0 ;
F_223 ( V_27 , & V_8 -> V_134 , V_134 ) ;
if ( V_27 -> V_357 & V_358 && ! F_8 ( & V_8 -> V_86 ) )
V_395 |= V_396 | V_397 ;
if ( ! F_7 ( V_8 ) )
V_395 |= V_398 ;
if ( F_8 ( & V_8 -> V_9 ) )
V_395 |= V_399 ;
return V_395 ;
}
static void F_224 ( struct V_50 * V_89 )
{
struct V_7 * V_8 ;
struct V_118 V_119 ;
while ( ! F_8 ( & V_89 -> V_211 ) ) {
V_8 = F_43 ( V_89 -> V_211 . V_87 , struct V_7 , V_9 ) ;
F_70 ( V_8 ) ;
F_225 ( & V_8 -> V_134 ) ;
F_41 ( & V_8 -> V_9 ) ;
if ( V_8 -> V_319 ) {
memset ( & V_119 , 0 , sizeof( V_119 ) ) ;
V_119 . V_123 = V_8 -> V_319 ;
V_119 . V_124 = V_227 ;
V_119 . V_125 = V_126 ;
V_119 . V_127 = V_8 -> V_320 ;
F_64 ( V_8 -> V_319 , & V_119 ,
V_8 -> V_210 , V_8 -> V_78 , V_8 -> V_120 ) ;
}
}
}
static int F_226 ( struct V_400 * V_401 ,
unsigned long V_402 , void * V_10 )
{
switch ( V_402 ) {
case V_403 :
break;
case V_404 :
F_224 ( V_10 ) ;
break;
}
return V_405 ;
}
int T_12 F_227 ( void )
{
int V_309 ;
V_309 = F_228 ( V_406 , V_407 ,
L_62 ) ;
if ( V_309 ) {
F_229 ( V_408 L_63 ) ;
goto V_409;
}
F_230 ( & V_410 , & V_411 ) ;
V_309 = F_231 ( & V_410 , V_406 , V_407 ) ;
if ( V_309 ) {
F_229 ( V_408 L_64 ,
V_207 ) ;
goto V_412;
}
F_232 ( & V_413 ) ;
V_409:
return V_309 ;
V_412:
F_233 ( V_406 , V_407 ) ;
goto V_409;
}
void F_234 ( void )
{
F_235 ( & V_413 ) ;
F_236 ( & V_410 ) ;
F_233 ( V_406 , V_407 ) ;
}
