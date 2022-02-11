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
static T_1 F_9 ( struct V_13 * V_13 , T_1 V_14 , int V_15 )
{
T_1 V_16 ;
F_10 ( & V_13 -> V_17 -> V_18 -> V_19 ) ;
switch ( V_15 ) {
case 0 :
V_13 -> V_20 = V_14 ;
V_16 = V_13 -> V_20 ;
break;
case 1 :
V_13 -> V_20 += V_14 ;
V_16 = V_13 -> V_20 ;
break;
case 2 :
default:
V_16 = - V_21 ;
}
F_11 ( & V_13 -> V_17 -> V_18 -> V_19 ) ;
return V_16 ;
}
static T_2 F_12 ( struct V_13 * V_13 , char T_3 * V_22 , T_4 V_23 ,
T_1 * V_24 )
{
struct V_7 * V_8 = V_13 -> V_25 ;
struct V_26 * V_10 = V_8 -> V_10 ;
T_2 V_16 = 0 ;
unsigned V_27 ;
T_1 V_28 ;
int V_29 ;
V_28 = * V_24 ;
F_13 ( V_10 ) ;
if ( ! F_7 ( V_8 ) ) {
V_16 = - V_30 ;
goto V_31;
} else if ( V_28 < 0 ) {
V_16 = - V_21 ;
goto V_31;
}
if ( V_28 < sizeof( struct V_32 ) ) {
struct V_32 V_33 ;
memcpy ( & V_33 , & V_10 -> V_34 , sizeof( V_10 -> V_34 ) ) ;
F_14 ( & V_33 . V_35 ) ;
F_14 ( & V_33 . V_36 ) ;
F_14 ( & V_33 . V_37 ) ;
F_14 ( & V_33 . V_38 ) ;
V_27 = sizeof( struct V_32 ) - V_28 ;
if ( V_27 > V_23 )
V_27 = V_23 ;
if ( F_15 ( V_22 , ( ( char * ) & V_33 ) + V_28 , V_27 ) ) {
V_16 = - V_39 ;
goto V_31;
}
* V_24 += V_27 ;
V_22 += V_27 ;
V_23 -= V_27 ;
V_16 += V_27 ;
}
V_28 = sizeof( struct V_32 ) ;
for ( V_29 = 0 ; V_23 && V_29 < V_10 -> V_34 . V_40 ; V_29 ++ ) {
struct V_41 * V_42 =
(struct V_41 * ) V_10 -> V_43 [ V_29 ] ;
unsigned int V_44 = F_16 ( V_42 -> V_45 ) ;
if ( * V_24 < V_28 + V_44 ) {
unsigned V_46 =
F_16 ( V_10 -> V_42 [ V_29 ] . V_47 . V_45 ) ;
V_27 = V_44 - ( * V_24 - V_28 ) ;
if ( V_27 > V_23 )
V_27 = V_23 ;
if ( V_46 > ( * V_24 - V_28 ) ) {
V_46 -= ( * V_24 - V_28 ) ;
if ( F_15 ( V_22 ,
V_10 -> V_43 [ V_29 ] + ( * V_24 - V_28 ) ,
F_17 ( V_27 , V_46 ) ) ) {
V_16 = - V_39 ;
goto V_31;
}
}
* V_24 += V_27 ;
V_22 += V_27 ;
V_23 -= V_27 ;
V_16 += V_27 ;
}
V_28 += V_44 ;
}
V_31:
F_18 ( V_10 ) ;
return V_16 ;
}
static struct V_48 * F_19 ( unsigned int V_49 )
{
struct V_48 * V_50 ;
V_50 = F_20 ( sizeof( struct V_48 ) , V_51 ) ;
if ( ! V_50 )
return NULL ;
V_50 -> V_52 = F_21 ( V_49 , V_51 ) ;
if ( ! V_50 -> V_52 ) {
F_22 ( V_50 ) ;
return NULL ;
}
return V_50 ;
}
static void F_23 ( struct V_48 * V_50 )
{
F_24 ( V_50 -> V_53 ) ;
if ( V_50 -> V_54 )
F_25 ( V_50 -> V_54 ) ;
F_22 ( V_50 -> V_52 -> V_55 ) ;
F_22 ( V_50 -> V_52 -> V_56 ) ;
F_26 ( V_50 -> V_52 ) ;
F_6 ( V_50 -> V_57 ) ;
F_22 ( V_50 ) ;
}
static void F_27 ( struct V_48 * V_50 )
{
struct V_7 * V_8 = V_50 -> V_8 ;
unsigned long V_58 ;
F_28 ( & V_8 -> V_59 , V_58 ) ;
F_29 ( & V_50 -> V_60 , & V_8 -> V_61 ) ;
F_30 ( & V_8 -> V_59 , V_58 ) ;
}
static void F_31 ( struct V_48 * V_50 )
{
struct V_7 * V_8 = V_50 -> V_8 ;
unsigned long V_58 ;
F_28 ( & V_8 -> V_59 , V_58 ) ;
F_32 ( & V_50 -> V_60 ) ;
F_30 ( & V_8 -> V_59 , V_58 ) ;
}
static struct V_48 * F_33 ( struct V_7 * V_8 )
{
unsigned long V_58 ;
struct V_48 * V_50 = NULL ;
F_28 ( & V_8 -> V_59 , V_58 ) ;
if ( ! F_8 ( & V_8 -> V_62 ) ) {
V_50 = F_34 ( V_8 -> V_62 . V_63 , struct V_48 ,
V_60 ) ;
F_32 ( & V_50 -> V_60 ) ;
}
F_30 ( & V_8 -> V_59 , V_58 ) ;
return V_50 ;
}
static struct V_48 * F_35 ( struct V_7 * V_8 ,
void T_3 * V_64 )
{
struct V_48 * V_50 ;
F_36 (as, &ps->async_pending, asynclist)
if ( V_50 -> V_64 == V_64 ) {
F_32 ( & V_50 -> V_60 ) ;
return V_50 ;
}
return NULL ;
}
static void F_37 ( struct V_26 * V_65 ,
void T_3 * V_64 , int V_66 , unsigned V_44 ,
int V_67 , enum V_68 V_69 ,
unsigned char * V_70 , unsigned V_71 )
{
static const char * V_72 [] = { L_1 , L_2 , L_3 , L_4 } ;
static const char * V_73 [] = { L_5 , L_6 } ;
int V_74 ;
const char * V_75 , * V_76 ;
if ( ! V_77 )
return;
V_74 = F_38 ( V_66 ) ;
V_75 = V_72 [ F_39 ( V_66 ) ] ;
V_76 = V_73 [ ! ! F_40 ( V_66 ) ] ;
if ( V_64 ) {
if ( V_69 == V_78 )
F_41 ( & V_65 -> V_10 , L_7
L_8 ,
V_64 , V_74 , V_75 , V_76 , V_44 ) ;
else
F_41 ( & V_65 -> V_10 , L_7
L_9 ,
V_64 , V_74 , V_75 , V_76 , V_44 ,
V_67 ) ;
} else {
if ( V_69 == V_78 )
F_41 ( & V_65 -> V_10 , L_10
L_11 ,
V_74 , V_75 , V_76 , V_44 , V_67 ) ;
else
F_41 ( & V_65 -> V_10 , L_12
L_13 ,
V_74 , V_75 , V_76 , V_44 , V_67 ) ;
}
if ( V_70 && V_71 > 0 ) {
F_42 ( V_79 , L_14 , V_80 , 32 , 1 ,
V_70 , V_71 , 1 ) ;
}
}
static void F_43 ( struct V_7 * V_8 , unsigned V_81 )
__releases( V_8 -> V_59 )
__acquires( V_8 -> V_59 )
{
struct V_52 * V_52 ;
struct V_48 * V_50 ;
F_36 (as, &ps->async_pending, asynclist) {
if ( V_50 -> V_81 == V_81 ) {
if ( V_50 -> V_82 != V_83 )
goto V_84;
V_50 -> V_82 = V_85 ;
V_50 -> V_81 = 0 ;
}
}
V_8 -> V_86 |= ( 1 << V_81 ) ;
V_84:
F_36 (as, &ps->async_pending, asynclist) {
if ( V_50 -> V_82 == V_85 ) {
V_50 -> V_82 = 0 ;
V_52 = V_50 -> V_52 ;
F_44 ( V_52 ) ;
F_45 ( & V_8 -> V_59 ) ;
F_46 ( V_52 ) ;
F_47 ( V_52 ) ;
F_48 ( & V_8 -> V_59 ) ;
goto V_84;
}
}
}
static void V_62 ( struct V_52 * V_52 )
{
struct V_48 * V_50 = V_52 -> V_87 ;
struct V_7 * V_8 = V_50 -> V_8 ;
struct V_88 V_89 ;
struct V_53 * V_53 = NULL ;
T_5 V_90 = 0 ;
const struct V_54 * V_54 = NULL ;
int V_91 ;
F_48 ( & V_8 -> V_59 ) ;
F_49 ( & V_50 -> V_60 , & V_8 -> V_62 ) ;
V_50 -> V_92 = V_52 -> V_92 ;
V_91 = V_50 -> V_91 ;
if ( V_91 ) {
V_89 . V_93 = V_50 -> V_91 ;
V_89 . V_94 = V_50 -> V_92 ;
V_89 . V_95 = V_96 ;
V_89 . V_97 = V_50 -> V_64 ;
V_53 = F_50 ( V_50 -> V_53 ) ;
V_54 = F_51 ( V_50 -> V_54 ) ;
V_90 = V_50 -> V_90 ;
}
F_52 ( & V_52 -> V_10 -> V_10 , L_15 ) ;
F_37 ( V_52 -> V_10 , V_50 -> V_64 , V_52 -> V_66 , V_52 -> V_98 ,
V_50 -> V_92 , V_99 ,
( ( V_52 -> V_100 & V_101 ) == V_102 ) ?
NULL : V_52 -> V_55 , V_52 -> V_98 ) ;
if ( V_50 -> V_92 < 0 && V_50 -> V_81 && V_50 -> V_92 != - V_103 &&
V_50 -> V_92 != - V_104 )
F_43 ( V_8 , V_50 -> V_81 ) ;
F_45 ( & V_8 -> V_59 ) ;
if ( V_91 ) {
F_53 ( V_89 . V_93 , & V_89 , V_53 , V_54 , V_90 ) ;
F_24 ( V_53 ) ;
F_25 ( V_54 ) ;
}
F_54 ( & V_8 -> V_105 ) ;
}
static void F_55 ( struct V_7 * V_8 , struct V_106 * V_9 )
{
struct V_52 * V_52 ;
struct V_48 * V_50 ;
unsigned long V_58 ;
F_28 ( & V_8 -> V_59 , V_58 ) ;
while ( ! F_8 ( V_9 ) ) {
V_50 = F_34 ( V_9 -> V_63 , struct V_48 , V_60 ) ;
F_32 ( & V_50 -> V_60 ) ;
V_52 = V_50 -> V_52 ;
F_44 ( V_52 ) ;
F_30 ( & V_8 -> V_59 , V_58 ) ;
F_56 ( V_52 ) ;
F_47 ( V_52 ) ;
F_28 ( & V_8 -> V_59 , V_58 ) ;
}
F_30 ( & V_8 -> V_59 , V_58 ) ;
}
static void F_57 ( struct V_7 * V_8 ,
unsigned int V_107 )
{
struct V_106 * V_108 , * V_109 , V_110 ;
unsigned long V_58 ;
F_58 ( & V_110 ) ;
F_28 ( & V_8 -> V_59 , V_58 ) ;
F_59 (p, q, &ps->async_pending)
if ( V_107 == F_34 ( V_108 , struct V_48 , V_60 ) -> V_107 )
F_49 ( V_108 , & V_110 ) ;
F_30 ( & V_8 -> V_59 , V_58 ) ;
F_55 ( V_8 , & V_110 ) ;
}
static void F_60 ( struct V_7 * V_8 )
{
F_55 ( V_8 , & V_8 -> V_61 ) ;
}
static int F_61 ( struct V_111 * V_112 ,
const struct V_113 * V_114 )
{
return - V_30 ;
}
static void F_62 ( struct V_111 * V_112 )
{
struct V_7 * V_8 = F_63 ( V_112 ) ;
unsigned int V_107 = V_112 -> V_115 -> V_47 . V_116 ;
if ( ! V_8 )
return;
if ( F_64 ( V_107 < 8 * sizeof( V_8 -> V_117 ) ) )
F_65 ( V_107 , & V_8 -> V_117 ) ;
else
F_66 ( & V_112 -> V_10 , L_16 ,
V_107 ) ;
F_67 ( V_112 , NULL ) ;
F_57 ( V_8 , V_107 ) ;
}
static int F_68 ( struct V_111 * V_112 , T_6 V_118 )
{
return 0 ;
}
static int F_69 ( struct V_111 * V_112 )
{
return 0 ;
}
static int F_70 ( struct V_7 * V_8 , unsigned int V_107 )
{
struct V_26 * V_10 = V_8 -> V_10 ;
struct V_111 * V_112 ;
int V_31 ;
if ( V_107 >= 8 * sizeof( V_8 -> V_117 ) )
return - V_21 ;
if ( F_71 ( V_107 , & V_8 -> V_117 ) )
return 0 ;
V_112 = F_72 ( V_10 , V_107 ) ;
if ( ! V_112 )
V_31 = - V_104 ;
else
V_31 = F_73 ( & V_119 , V_112 , V_8 ) ;
if ( V_31 == 0 )
F_74 ( V_107 , & V_8 -> V_117 ) ;
return V_31 ;
}
static int F_75 ( struct V_7 * V_8 , unsigned int V_107 )
{
struct V_26 * V_10 ;
struct V_111 * V_112 ;
int V_31 ;
V_31 = - V_21 ;
if ( V_107 >= 8 * sizeof( V_8 -> V_117 ) )
return V_31 ;
V_10 = V_8 -> V_10 ;
V_112 = F_72 ( V_10 , V_107 ) ;
if ( ! V_112 )
V_31 = - V_104 ;
else if ( F_76 ( V_107 , & V_8 -> V_117 ) ) {
F_77 ( & V_119 , V_112 ) ;
V_31 = 0 ;
}
return V_31 ;
}
static int F_78 ( struct V_7 * V_8 , unsigned int V_107 )
{
if ( V_8 -> V_10 -> V_11 != V_120 )
return - V_121 ;
if ( V_107 >= 8 * sizeof( V_8 -> V_117 ) )
return - V_21 ;
if ( F_71 ( V_107 , & V_8 -> V_117 ) )
return 0 ;
F_66 ( & V_8 -> V_10 -> V_10 , L_17
L_18 , F_79 ( V_122 ) ,
V_122 -> V_123 , V_107 ) ;
return F_70 ( V_8 , V_107 ) ;
}
static int F_80 ( struct V_26 * V_10 , unsigned int V_74 )
{
unsigned int V_29 , V_124 , V_125 ;
struct V_111 * V_112 ;
struct V_126 * V_127 ;
struct V_128 * V_129 ;
if ( V_74 & ~ ( V_130 | 0xf ) )
return - V_21 ;
if ( ! V_10 -> V_131 )
return - V_132 ;
for ( V_29 = 0 ; V_29 < V_10 -> V_131 -> V_47 . V_133 ; V_29 ++ ) {
V_112 = V_10 -> V_131 -> V_134 [ V_29 ] ;
for ( V_124 = 0 ; V_124 < V_112 -> V_135 ; V_124 ++ ) {
V_127 = & V_112 -> V_115 [ V_124 ] ;
for ( V_125 = 0 ; V_125 < V_127 -> V_47 . V_136 ; V_125 ++ ) {
V_129 = & V_127 -> V_137 [ V_125 ] . V_47 ;
if ( V_129 -> V_138 == V_74 )
return V_127 -> V_47 . V_116 ;
}
}
}
return - V_104 ;
}
static int F_81 ( struct V_7 * V_8 , unsigned int V_139 ,
unsigned int V_140 , unsigned int V_141 )
{
int V_16 = 0 ;
struct V_126 * V_142 ;
if ( V_8 -> V_10 -> V_11 != V_143
&& V_8 -> V_10 -> V_11 != V_144
&& V_8 -> V_10 -> V_11 != V_120 )
return - V_121 ;
if ( V_145 == ( V_146 & V_139 ) )
return 0 ;
if ( V_139 == 0xa1 && V_140 == 0 ) {
V_142 = F_82 ( V_8 -> V_10 -> V_131 ,
V_141 >> 8 , V_141 & 0xff ) ;
if ( V_142
&& V_142 -> V_47 . V_147 == V_148 )
V_141 >>= 8 ;
}
V_141 &= 0xff ;
switch ( V_139 & V_149 ) {
case V_150 :
V_16 = F_80 ( V_8 -> V_10 , V_141 ) ;
if ( V_16 >= 0 )
V_16 = F_78 ( V_8 , V_16 ) ;
break;
case V_151 :
V_16 = F_78 ( V_8 , V_141 ) ;
break;
}
return V_16 ;
}
static int F_83 ( struct V_152 * V_10 , void * V_70 )
{
return V_10 -> V_153 == ( V_154 ) ( unsigned long ) V_70 ;
}
static struct V_26 * F_84 ( V_154 V_153 )
{
struct V_152 * V_10 ;
V_10 = F_85 ( & V_155 , NULL ,
( void * ) ( unsigned long ) V_153 , F_83 ) ;
if ( ! V_10 )
return NULL ;
return F_86 ( V_10 , struct V_26 , V_10 ) ;
}
static int F_87 ( struct V_156 * V_156 , struct V_13 * V_13 )
{
struct V_26 * V_10 = NULL ;
struct V_7 * V_8 ;
int V_16 ;
V_16 = - V_6 ;
V_8 = F_88 ( sizeof( struct V_7 ) , V_51 ) ;
if ( ! V_8 )
goto V_157;
V_16 = - V_30 ;
F_10 ( & V_158 ) ;
if ( F_89 ( V_156 ) == V_159 )
V_10 = F_84 ( V_156 -> V_160 ) ;
F_11 ( & V_158 ) ;
if ( ! V_10 )
goto V_157;
F_13 ( V_10 ) ;
if ( V_10 -> V_11 == V_12 )
goto V_161;
V_16 = F_90 ( V_10 ) ;
if ( V_16 )
goto V_161;
V_8 -> V_10 = V_10 ;
V_8 -> V_13 = V_13 ;
F_91 ( & V_8 -> V_59 ) ;
F_58 ( & V_8 -> V_9 ) ;
F_58 ( & V_8 -> V_61 ) ;
F_58 ( & V_8 -> V_62 ) ;
F_92 ( & V_8 -> V_105 ) ;
V_8 -> V_162 = 0 ;
V_8 -> V_163 = F_50 ( F_93 ( V_122 ) ) ;
V_8 -> V_54 = F_94 () ;
V_8 -> V_164 = NULL ;
V_8 -> V_117 = 0 ;
F_95 ( V_122 , & V_8 -> V_90 ) ;
F_96 () ;
F_29 ( & V_8 -> V_9 , & V_10 -> V_165 ) ;
V_13 -> V_25 = V_8 ;
F_18 ( V_10 ) ;
F_52 ( & V_10 -> V_10 , L_19 , F_79 ( V_122 ) ,
V_122 -> V_123 ) ;
return V_16 ;
V_161:
F_18 ( V_10 ) ;
F_97 ( V_10 ) ;
V_157:
F_22 ( V_8 ) ;
return V_16 ;
}
static int F_98 ( struct V_156 * V_156 , struct V_13 * V_13 )
{
struct V_7 * V_8 = V_13 -> V_25 ;
struct V_26 * V_10 = V_8 -> V_10 ;
unsigned int V_107 ;
struct V_48 * V_50 ;
F_13 ( V_10 ) ;
F_99 ( V_10 , V_8 ) ;
F_32 ( & V_8 -> V_9 ) ;
for ( V_107 = 0 ; V_8 -> V_117 && V_107 < 8 * sizeof( V_8 -> V_117 ) ;
V_107 ++ ) {
if ( F_71 ( V_107 , & V_8 -> V_117 ) )
F_75 ( V_8 , V_107 ) ;
}
F_60 ( V_8 ) ;
F_100 ( V_10 ) ;
F_18 ( V_10 ) ;
F_97 ( V_10 ) ;
F_24 ( V_8 -> V_163 ) ;
F_25 ( V_8 -> V_54 ) ;
V_50 = F_33 ( V_8 ) ;
while ( V_50 ) {
F_23 ( V_50 ) ;
V_50 = F_33 ( V_8 ) ;
}
F_22 ( V_8 ) ;
return 0 ;
}
static int F_101 ( struct V_7 * V_8 , void T_3 * V_166 )
{
struct V_26 * V_10 = V_8 -> V_10 ;
struct V_167 V_168 ;
unsigned int V_169 ;
unsigned char * V_170 ;
unsigned V_171 ;
int V_29 , V_66 , V_16 ;
if ( F_102 ( & V_168 , V_166 , sizeof( V_168 ) ) )
return - V_39 ;
V_16 = F_81 ( V_8 , V_168 . V_172 , V_168 . V_173 ,
V_168 . V_174 ) ;
if ( V_16 )
return V_16 ;
V_171 = V_168 . V_171 ;
if ( V_171 > V_175 )
return - V_21 ;
V_16 = F_1 ( V_175 + sizeof( struct V_52 ) +
sizeof( struct V_176 ) ) ;
if ( V_16 )
return V_16 ;
V_170 = ( unsigned char * ) F_103 ( V_51 ) ;
if ( ! V_170 ) {
V_16 = - V_6 ;
goto V_177;
}
V_169 = V_168 . V_178 ;
F_52 ( & V_10 -> V_10 , L_20
L_21
L_22 ,
V_168 . V_172 , V_168 . V_173 ,
F_104 ( & V_168 . V_179 ) ,
F_104 ( & V_168 . V_174 ) ,
F_104 ( & V_168 . V_171 ) ) ;
if ( V_168 . V_172 & 0x80 ) {
if ( V_168 . V_171 && ! F_105 ( V_180 , V_168 . V_70 ,
V_168 . V_171 ) ) {
V_16 = - V_21 ;
goto V_177;
}
V_66 = F_106 ( V_10 , 0 ) ;
F_37 ( V_10 , NULL , V_66 , V_168 . V_171 , V_169 , V_78 , NULL , 0 ) ;
F_18 ( V_10 ) ;
V_29 = F_107 ( V_10 , V_66 , V_168 . V_173 ,
V_168 . V_172 , V_168 . V_179 , V_168 . V_174 ,
V_170 , V_168 . V_171 , V_169 ) ;
F_13 ( V_10 ) ;
F_37 ( V_10 , NULL , V_66 , F_108 ( V_29 , 0 ) , F_17 ( V_29 , 0 ) , V_99 ,
V_170 , F_108 ( V_29 , 0 ) ) ;
if ( ( V_29 > 0 ) && V_168 . V_171 ) {
if ( F_15 ( V_168 . V_70 , V_170 , V_29 ) ) {
V_16 = - V_39 ;
goto V_177;
}
}
} else {
if ( V_168 . V_171 ) {
if ( F_102 ( V_170 , V_168 . V_70 , V_168 . V_171 ) ) {
V_16 = - V_39 ;
goto V_177;
}
}
V_66 = F_109 ( V_10 , 0 ) ;
F_37 ( V_10 , NULL , V_66 , V_168 . V_171 , V_169 , V_78 ,
V_170 , V_168 . V_171 ) ;
F_18 ( V_10 ) ;
V_29 = F_107 ( V_10 , F_109 ( V_10 , 0 ) , V_168 . V_173 ,
V_168 . V_172 , V_168 . V_179 , V_168 . V_174 ,
V_170 , V_168 . V_171 , V_169 ) ;
F_13 ( V_10 ) ;
F_37 ( V_10 , NULL , V_66 , F_108 ( V_29 , 0 ) , F_17 ( V_29 , 0 ) , V_99 , NULL , 0 ) ;
}
if ( V_29 < 0 && V_29 != - V_181 ) {
F_110 ( V_79 , & V_10 -> V_10 , L_23
L_24 ,
V_122 -> V_123 , V_168 . V_172 , V_168 . V_173 ,
V_168 . V_171 , V_29 ) ;
}
V_16 = V_29 ;
V_177:
F_111 ( ( unsigned long ) V_170 ) ;
F_6 ( V_175 + sizeof( struct V_52 ) +
sizeof( struct V_176 ) ) ;
return V_16 ;
}
static int F_112 ( struct V_7 * V_8 , void T_3 * V_166 )
{
struct V_26 * V_10 = V_8 -> V_10 ;
struct V_182 V_183 ;
unsigned int V_169 , V_184 , V_66 ;
int V_185 ;
unsigned char * V_170 ;
int V_29 , V_16 ;
if ( F_102 ( & V_183 , V_166 , sizeof( V_183 ) ) )
return - V_39 ;
V_16 = F_80 ( V_8 -> V_10 , V_183 . V_74 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_78 ( V_8 , V_16 ) ;
if ( V_16 )
return V_16 ;
if ( V_183 . V_74 & V_130 )
V_66 = F_113 ( V_10 , V_183 . V_74 & 0x7f ) ;
else
V_66 = F_114 ( V_10 , V_183 . V_74 & 0x7f ) ;
if ( ! F_115 ( V_10 , V_66 , ! ( V_183 . V_74 & V_130 ) ) )
return - V_21 ;
V_184 = V_183 . V_27 ;
if ( V_184 >= V_4 )
return - V_21 ;
V_16 = F_1 ( V_184 + sizeof( struct V_52 ) ) ;
if ( V_16 )
return V_16 ;
if ( ! ( V_170 = F_88 ( V_184 , V_51 ) ) ) {
V_16 = - V_6 ;
goto V_177;
}
V_169 = V_183 . V_178 ;
if ( V_183 . V_74 & 0x80 ) {
if ( V_184 && ! F_105 ( V_180 , V_183 . V_70 , V_184 ) ) {
V_16 = - V_21 ;
goto V_177;
}
F_37 ( V_10 , NULL , V_66 , V_184 , V_169 , V_78 , NULL , 0 ) ;
F_18 ( V_10 ) ;
V_29 = F_116 ( V_10 , V_66 , V_170 , V_184 , & V_185 , V_169 ) ;
F_13 ( V_10 ) ;
F_37 ( V_10 , NULL , V_66 , V_185 , V_29 , V_99 , V_170 , V_185 ) ;
if ( ! V_29 && V_185 ) {
if ( F_15 ( V_183 . V_70 , V_170 , V_185 ) ) {
V_16 = - V_39 ;
goto V_177;
}
}
} else {
if ( V_184 ) {
if ( F_102 ( V_170 , V_183 . V_70 , V_184 ) ) {
V_16 = - V_39 ;
goto V_177;
}
}
F_37 ( V_10 , NULL , V_66 , V_184 , V_169 , V_78 , V_170 , V_184 ) ;
F_18 ( V_10 ) ;
V_29 = F_116 ( V_10 , V_66 , V_170 , V_184 , & V_185 , V_169 ) ;
F_13 ( V_10 ) ;
F_37 ( V_10 , NULL , V_66 , V_185 , V_29 , V_99 , NULL , 0 ) ;
}
V_16 = ( V_29 < 0 ? V_29 : V_185 ) ;
V_177:
F_22 ( V_170 ) ;
F_6 ( V_184 + sizeof( struct V_52 ) ) ;
return V_16 ;
}
static int F_117 ( struct V_7 * V_8 , void T_3 * V_166 )
{
unsigned int V_74 ;
int V_16 ;
if ( F_118 ( V_74 , ( unsigned int T_3 * ) V_166 ) )
return - V_39 ;
V_16 = F_80 ( V_8 -> V_10 , V_74 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_78 ( V_8 , V_16 ) ;
if ( V_16 )
return V_16 ;
F_119 ( V_8 -> V_10 , V_74 ) ;
return 0 ;
}
static int F_120 ( struct V_7 * V_8 , void T_3 * V_166 )
{
unsigned int V_74 ;
int V_66 ;
int V_16 ;
if ( F_118 ( V_74 , ( unsigned int T_3 * ) V_166 ) )
return - V_39 ;
V_16 = F_80 ( V_8 -> V_10 , V_74 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_78 ( V_8 , V_16 ) ;
if ( V_16 )
return V_16 ;
if ( V_74 & V_130 )
V_66 = F_113 ( V_8 -> V_10 , V_74 & 0x7f ) ;
else
V_66 = F_114 ( V_8 -> V_10 , V_74 & 0x7f ) ;
return F_121 ( V_8 -> V_10 , V_66 ) ;
}
static int F_122 ( struct V_7 * V_8 , void T_3 * V_166 )
{
struct V_186 V_187 ;
struct V_111 * V_112 ;
int V_16 ;
if ( F_102 ( & V_187 , V_166 , sizeof( V_187 ) ) )
return - V_39 ;
V_112 = F_72 ( V_8 -> V_10 , V_187 . V_134 ) ;
if ( ! V_112 || ! V_112 -> V_10 . V_188 )
V_16 = - V_189 ;
else {
strncpy ( V_187 . V_188 , V_112 -> V_10 . V_188 -> V_190 ,
sizeof( V_187 . V_188 ) ) ;
V_16 = ( F_15 ( V_166 , & V_187 , sizeof( V_187 ) ) ? - V_39 : 0 ) ;
}
return V_16 ;
}
static int F_123 ( struct V_7 * V_8 , void T_3 * V_166 )
{
struct V_191 V_192 = {
. V_193 = V_8 -> V_10 -> V_193 ,
. V_194 = V_8 -> V_10 -> V_195 == V_196
} ;
if ( F_15 ( V_166 , & V_192 , sizeof( V_192 ) ) )
return - V_39 ;
return 0 ;
}
static int F_124 ( struct V_7 * V_8 )
{
return F_125 ( V_8 -> V_10 ) ;
}
static int F_126 ( struct V_7 * V_8 , void T_3 * V_166 )
{
struct V_197 V_198 ;
int V_16 ;
if ( F_102 ( & V_198 , V_166 , sizeof( V_198 ) ) )
return - V_39 ;
if ( ( V_16 = F_78 ( V_8 , V_198 . V_134 ) ) )
return V_16 ;
return F_127 ( V_8 -> V_10 , V_198 . V_134 ,
V_198 . V_115 ) ;
}
static int F_128 ( struct V_7 * V_8 , void T_3 * V_166 )
{
int V_199 ;
int V_92 = 0 ;
struct V_200 * V_131 ;
if ( F_118 ( V_199 , ( int T_3 * ) V_166 ) )
return - V_39 ;
V_131 = V_8 -> V_10 -> V_131 ;
if ( V_131 ) {
int V_29 ;
for ( V_29 = 0 ; V_29 < V_131 -> V_47 . V_133 ; ++ V_29 ) {
if ( F_129 ( V_131 -> V_134 [ V_29 ] ) ) {
F_66 ( & V_8 -> V_10 -> V_10 ,
L_25
L_26 ,
V_131 -> V_134 [ V_29 ]
-> V_201
-> V_47 . V_116 ,
V_131 -> V_134 [ V_29 ]
-> V_10 . V_188 -> V_190 ,
V_122 -> V_123 , V_199 ) ;
V_92 = - V_202 ;
break;
}
}
}
if ( V_92 == 0 ) {
if ( V_131 && V_131 -> V_47 . V_203 == V_199 )
V_92 = F_130 ( V_8 -> V_10 ) ;
else
V_92 = F_131 ( V_8 -> V_10 , V_199 ) ;
}
return V_92 ;
}
static int F_132 ( struct V_7 * V_8 , struct V_204 * V_205 ,
struct V_206 T_3 * V_207 ,
void T_3 * V_166 )
{
struct V_206 * V_208 = NULL ;
struct V_209 * V_74 ;
struct V_48 * V_50 = NULL ;
struct V_176 * V_210 = NULL ;
unsigned int V_199 , V_211 , V_212 ;
int V_16 , V_107 = - 1 ;
int V_213 ;
if ( V_205 -> V_58 & ~ ( V_214 |
V_215 |
V_216 |
V_217 |
V_218 |
V_219 ) )
return - V_21 ;
if ( V_205 -> V_220 > 0 && ! V_205 -> V_221 )
return - V_21 ;
if ( ! ( V_205 -> type == V_222 &&
( V_205 -> V_137 & ~ V_223 ) == 0 ) ) {
V_107 = F_80 ( V_8 -> V_10 , V_205 -> V_137 ) ;
if ( V_107 < 0 )
return V_107 ;
V_16 = F_78 ( V_8 , V_107 ) ;
if ( V_16 )
return V_16 ;
}
if ( ( V_205 -> V_137 & V_223 ) != 0 ) {
V_213 = 1 ;
V_74 = V_8 -> V_10 -> V_224 [ V_205 -> V_137 & V_225 ] ;
} else {
V_213 = 0 ;
V_74 = V_8 -> V_10 -> V_226 [ V_205 -> V_137 & V_225 ] ;
}
if ( ! V_74 )
return - V_104 ;
V_199 = 0 ;
switch( V_205 -> type ) {
case V_222 :
if ( ! F_133 ( & V_74 -> V_47 ) )
return - V_21 ;
if ( V_205 -> V_220 < 8 )
return - V_21 ;
V_210 = F_88 ( sizeof( struct V_176 ) , V_51 ) ;
if ( ! V_210 )
return - V_6 ;
if ( F_102 ( V_210 , V_205 -> V_221 , 8 ) ) {
V_16 = - V_39 ;
goto error;
}
if ( V_205 -> V_220 < ( F_134 ( & V_210 -> V_171 ) + 8 ) ) {
V_16 = - V_21 ;
goto error;
}
V_16 = F_81 ( V_8 , V_210 -> V_172 , V_210 -> V_173 ,
F_134 ( & V_210 -> V_174 ) ) ;
if ( V_16 )
goto error;
V_205 -> V_227 = 0 ;
V_205 -> V_220 = F_134 ( & V_210 -> V_171 ) ;
V_205 -> V_221 += 8 ;
if ( ( V_210 -> V_172 & V_130 ) && V_205 -> V_220 ) {
V_213 = 1 ;
V_205 -> V_137 |= V_130 ;
} else {
V_213 = 0 ;
V_205 -> V_137 &= ~ V_130 ;
}
F_52 ( & V_8 -> V_10 -> V_10 , L_20
L_21
L_22 ,
V_210 -> V_172 , V_210 -> V_173 ,
F_104 ( & V_210 -> V_179 ) ,
F_104 ( & V_210 -> V_174 ) ,
F_104 ( & V_210 -> V_171 ) ) ;
V_199 = sizeof( struct V_176 ) ;
break;
case V_228 :
switch ( F_135 ( & V_74 -> V_47 ) ) {
case V_229 :
case V_230 :
return - V_21 ;
case V_231 :
V_205 -> type = V_232 ;
goto V_233;
}
V_205 -> V_227 = 0 ;
break;
case V_232 :
if ( ! F_136 ( & V_74 -> V_47 ) )
return - V_21 ;
V_233:
V_205 -> V_227 = 0 ;
break;
case V_234 :
if ( V_205 -> V_227 < 1 ||
V_205 -> V_227 > 128 )
return - V_21 ;
if ( ! F_137 ( & V_74 -> V_47 ) )
return - V_21 ;
V_212 = sizeof( struct V_206 ) *
V_205 -> V_227 ;
if ( ! ( V_208 = F_88 ( V_212 , V_51 ) ) )
return - V_6 ;
if ( F_102 ( V_208 , V_207 , V_212 ) ) {
V_16 = - V_39 ;
goto error;
}
for ( V_211 = V_199 = 0 ; V_199 < V_205 -> V_227 ; V_199 ++ ) {
if ( V_208 [ V_199 ] . V_44 > 8192 ) {
V_16 = - V_21 ;
goto error;
}
V_211 += V_208 [ V_199 ] . V_44 ;
}
V_199 *= sizeof( struct V_235 ) ;
V_205 -> V_220 = V_211 ;
break;
default:
return - V_21 ;
}
if ( V_205 -> V_220 >= V_4 ) {
V_16 = - V_21 ;
goto error;
}
if ( V_205 -> V_220 > 0 &&
! F_105 ( V_213 ? V_180 : V_236 ,
V_205 -> V_221 , V_205 -> V_220 ) ) {
V_16 = - V_39 ;
goto error;
}
V_50 = F_19 ( V_205 -> V_227 ) ;
if ( ! V_50 ) {
V_16 = - V_6 ;
goto error;
}
V_199 += sizeof( struct V_48 ) + sizeof( struct V_52 ) + V_205 -> V_220 ;
V_16 = F_1 ( V_199 ) ;
if ( V_16 )
goto error;
V_50 -> V_57 = V_199 ;
if ( V_205 -> V_220 > 0 ) {
V_50 -> V_52 -> V_55 = F_88 ( V_205 -> V_220 ,
V_51 ) ;
if ( ! V_50 -> V_52 -> V_55 ) {
V_16 = - V_6 ;
goto error;
}
if ( V_213 && V_205 -> type == V_234 )
memset ( V_50 -> V_52 -> V_55 , 0 ,
V_205 -> V_220 ) ;
}
V_50 -> V_52 -> V_10 = V_8 -> V_10 ;
V_50 -> V_52 -> V_66 = ( V_205 -> type << 30 ) |
F_138 ( V_8 -> V_10 , V_205 -> V_137 & 0xf ) |
( V_205 -> V_137 & V_130 ) ;
V_199 = ( V_213 ? V_237 : V_238 ) ;
if ( V_205 -> V_58 & V_214 )
V_199 |= V_239 ;
if ( V_205 -> V_58 & V_215 )
V_199 |= V_240 ;
if ( V_205 -> V_58 & V_217 )
V_199 |= V_241 ;
if ( V_205 -> V_58 & V_218 )
V_199 |= V_242 ;
if ( V_205 -> V_58 & V_219 )
V_199 |= V_243 ;
V_50 -> V_52 -> V_100 = V_199 ;
V_50 -> V_52 -> V_244 = V_205 -> V_220 ;
V_50 -> V_52 -> V_56 = ( unsigned char * ) V_210 ;
V_210 = NULL ;
V_50 -> V_52 -> V_245 = V_205 -> V_245 ;
V_50 -> V_52 -> V_227 = V_205 -> V_227 ;
if ( V_205 -> type == V_234 ||
V_8 -> V_10 -> V_195 == V_246 )
V_50 -> V_52 -> V_247 = 1 << F_17 ( 15 , V_74 -> V_47 . V_248 - 1 ) ;
else
V_50 -> V_52 -> V_247 = V_74 -> V_47 . V_248 ;
V_50 -> V_52 -> V_87 = V_50 ;
V_50 -> V_52 -> V_249 = V_62 ;
for ( V_211 = V_199 = 0 ; V_199 < V_205 -> V_227 ; V_199 ++ ) {
V_50 -> V_52 -> V_207 [ V_199 ] . V_14 = V_211 ;
V_50 -> V_52 -> V_207 [ V_199 ] . V_44 = V_208 [ V_199 ] . V_44 ;
V_211 += V_208 [ V_199 ] . V_44 ;
}
F_22 ( V_208 ) ;
V_208 = NULL ;
V_50 -> V_8 = V_8 ;
V_50 -> V_64 = V_166 ;
if ( V_213 && V_205 -> V_220 > 0 )
V_50 -> V_250 = V_205 -> V_221 ;
else
V_50 -> V_250 = NULL ;
V_50 -> V_91 = V_205 -> V_91 ;
V_50 -> V_107 = V_107 ;
V_50 -> V_53 = F_50 ( F_93 ( V_122 ) ) ;
V_50 -> V_54 = F_94 () ;
F_95 ( V_122 , & V_50 -> V_90 ) ;
if ( ! V_213 && V_205 -> V_220 > 0 ) {
if ( F_102 ( V_50 -> V_52 -> V_55 , V_205 -> V_221 ,
V_205 -> V_220 ) ) {
V_16 = - V_39 ;
goto error;
}
}
F_37 ( V_8 -> V_10 , V_50 -> V_64 , V_50 -> V_52 -> V_66 ,
V_50 -> V_52 -> V_244 , 0 , V_78 ,
V_213 ? NULL : V_50 -> V_52 -> V_55 ,
V_205 -> V_220 ) ;
F_27 ( V_50 ) ;
if ( F_139 ( & V_74 -> V_47 ) ) {
F_140 ( & V_8 -> V_59 ) ;
V_50 -> V_81 = F_141 ( & V_74 -> V_47 ) |
( ( V_74 -> V_47 . V_138 & V_223 )
>> 3 ) ;
if ( V_205 -> V_58 & V_216 )
V_50 -> V_82 = V_83 ;
else
V_8 -> V_86 &= ~ ( 1 << V_50 -> V_81 ) ;
if ( V_8 -> V_86 & ( 1 << V_50 -> V_81 ) )
V_16 = - V_251 ;
else
V_16 = F_142 ( V_50 -> V_52 , V_252 ) ;
F_143 ( & V_8 -> V_59 ) ;
} else {
V_16 = F_142 ( V_50 -> V_52 , V_51 ) ;
}
if ( V_16 ) {
F_110 ( V_79 , & V_8 -> V_10 -> V_10 ,
L_27 , V_16 ) ;
F_37 ( V_8 -> V_10 , V_50 -> V_64 , V_50 -> V_52 -> V_66 ,
0 , V_16 , V_99 , NULL , 0 ) ;
F_31 ( V_50 ) ;
goto error;
}
return 0 ;
error:
F_22 ( V_208 ) ;
F_22 ( V_210 ) ;
if ( V_50 )
F_23 ( V_50 ) ;
return V_16 ;
}
static int F_144 ( struct V_7 * V_8 , void T_3 * V_166 )
{
struct V_204 V_205 ;
if ( F_102 ( & V_205 , V_166 , sizeof( V_205 ) ) )
return - V_39 ;
return F_132 ( V_8 , & V_205 ,
( ( (struct V_204 T_3 * ) V_166 ) -> V_207 ) ,
V_166 ) ;
}
static int F_145 ( struct V_7 * V_8 , void T_3 * V_166 )
{
struct V_52 * V_52 ;
struct V_48 * V_50 ;
unsigned long V_58 ;
F_28 ( & V_8 -> V_59 , V_58 ) ;
V_50 = F_35 ( V_8 , V_166 ) ;
if ( ! V_50 ) {
F_30 ( & V_8 -> V_59 , V_58 ) ;
return - V_21 ;
}
V_52 = V_50 -> V_52 ;
F_44 ( V_52 ) ;
F_30 ( & V_8 -> V_59 , V_58 ) ;
F_56 ( V_52 ) ;
F_47 ( V_52 ) ;
return 0 ;
}
static int F_146 ( struct V_48 * V_50 , void T_3 * T_3 * V_166 )
{
struct V_52 * V_52 = V_50 -> V_52 ;
struct V_204 T_3 * V_64 = V_50 -> V_64 ;
void T_3 * V_253 = V_50 -> V_64 ;
unsigned int V_29 ;
if ( V_50 -> V_250 && V_52 -> V_98 ) {
if ( V_52 -> V_227 > 0 )
V_29 = V_52 -> V_244 ;
else
V_29 = V_52 -> V_98 ;
if ( F_15 ( V_50 -> V_250 , V_52 -> V_55 , V_29 ) )
goto V_254;
}
if ( F_147 ( V_50 -> V_92 , & V_64 -> V_92 ) )
goto V_254;
if ( F_147 ( V_52 -> V_98 , & V_64 -> V_98 ) )
goto V_254;
if ( F_147 ( V_52 -> V_255 , & V_64 -> V_255 ) )
goto V_254;
if ( F_137 ( & V_52 -> V_74 -> V_47 ) ) {
for ( V_29 = 0 ; V_29 < V_52 -> V_227 ; V_29 ++ ) {
if ( F_147 ( V_52 -> V_207 [ V_29 ] . V_98 ,
& V_64 -> V_207 [ V_29 ] . V_98 ) )
goto V_254;
if ( F_147 ( V_52 -> V_207 [ V_29 ] . V_92 ,
& V_64 -> V_207 [ V_29 ] . V_92 ) )
goto V_254;
}
}
if ( F_147 ( V_253 , ( void T_3 * T_3 * ) V_166 ) )
return - V_39 ;
return 0 ;
V_254:
return - V_39 ;
}
static struct V_48 * F_148 ( struct V_7 * V_8 )
{
F_149 ( V_105 , V_122 ) ;
struct V_48 * V_50 = NULL ;
struct V_26 * V_10 = V_8 -> V_10 ;
F_150 ( & V_8 -> V_105 , & V_105 ) ;
for (; ; ) {
F_151 ( V_256 ) ;
V_50 = F_33 ( V_8 ) ;
if ( V_50 )
break;
if ( F_152 ( V_122 ) )
break;
F_18 ( V_10 ) ;
F_153 () ;
F_13 ( V_10 ) ;
}
F_154 ( & V_8 -> V_105 , & V_105 ) ;
F_155 ( V_257 ) ;
return V_50 ;
}
static int F_156 ( struct V_7 * V_8 , void T_3 * V_166 )
{
struct V_48 * V_50 = F_148 ( V_8 ) ;
if ( V_50 ) {
int V_258 = F_146 ( V_50 , ( void T_3 * T_3 * ) V_166 ) ;
F_23 ( V_50 ) ;
return V_258 ;
}
if ( F_152 ( V_122 ) )
return - V_259 ;
return - V_260 ;
}
static int F_157 ( struct V_7 * V_8 , void T_3 * V_166 )
{
int V_258 ;
struct V_48 * V_50 ;
V_50 = F_33 ( V_8 ) ;
V_258 = - V_261 ;
if ( V_50 ) {
V_258 = F_146 ( V_50 , ( void T_3 * T_3 * ) V_166 ) ;
F_23 ( V_50 ) ;
}
return V_258 ;
}
static int F_158 ( struct V_7 * V_8 ,
struct V_262 T_3 * V_263 )
{
struct V_167 T_3 * V_108 ;
T_7 V_264 ;
V_108 = F_159 ( sizeof( * V_108 ) ) ;
if ( F_160 ( V_108 , V_263 , ( sizeof( * V_263 ) - sizeof( V_265 ) ) ) ||
F_118 ( V_264 , & V_263 -> V_70 ) ||
F_147 ( F_161 ( V_264 ) , & V_108 -> V_70 ) )
return - V_39 ;
return F_101 ( V_8 , V_108 ) ;
}
static int F_162 ( struct V_7 * V_8 ,
struct V_266 T_3 * V_263 )
{
struct V_182 T_3 * V_108 ;
T_8 V_267 ;
V_265 V_253 ;
V_108 = F_159 ( sizeof( * V_108 ) ) ;
if ( F_118 ( V_267 , & V_263 -> V_74 ) || F_147 ( V_267 , & V_108 -> V_74 ) ||
F_118 ( V_267 , & V_263 -> V_27 ) || F_147 ( V_267 , & V_108 -> V_27 ) ||
F_118 ( V_267 , & V_263 -> V_178 ) || F_147 ( V_267 , & V_108 -> V_178 ) ||
F_118 ( V_253 , & V_263 -> V_70 ) || F_147 ( F_161 ( V_253 ) , & V_108 -> V_70 ) )
return - V_39 ;
return F_112 ( V_8 , V_108 ) ;
}
static int F_163 ( struct V_7 * V_8 , void T_3 * V_166 )
{
struct V_268 V_269 ;
if ( F_102 ( & V_269 , V_166 , sizeof( V_269 ) ) )
return - V_39 ;
V_8 -> V_162 = V_269 . V_91 ;
V_8 -> V_164 = F_161 ( V_269 . V_87 ) ;
return 0 ;
}
static int F_164 ( struct V_204 * V_270 ,
struct V_271 T_3 * V_205 )
{
T_7 V_272 ;
if ( ! F_105 ( V_236 , V_205 , sizeof( * V_205 ) ) ||
F_165 ( V_270 -> type , & V_205 -> type ) ||
F_165 ( V_270 -> V_137 , & V_205 -> V_137 ) ||
F_165 ( V_270 -> V_92 , & V_205 -> V_92 ) ||
F_165 ( V_270 -> V_58 , & V_205 -> V_58 ) ||
F_165 ( V_270 -> V_220 , & V_205 -> V_220 ) ||
F_165 ( V_270 -> V_98 , & V_205 -> V_98 ) ||
F_165 ( V_270 -> V_245 , & V_205 -> V_245 ) ||
F_165 ( V_270 -> V_227 , & V_205 -> V_227 ) ||
F_165 ( V_270 -> V_255 , & V_205 -> V_255 ) ||
F_165 ( V_270 -> V_91 , & V_205 -> V_91 ) )
return - V_39 ;
if ( F_165 ( V_272 , & V_205 -> V_221 ) )
return - V_39 ;
V_270 -> V_221 = F_161 ( V_272 ) ;
if ( F_165 ( V_272 , & V_205 -> V_273 ) )
return - V_39 ;
V_270 -> V_273 = F_161 ( V_272 ) ;
return 0 ;
}
static int F_166 ( struct V_7 * V_8 , void T_3 * V_166 )
{
struct V_204 V_205 ;
if ( F_164 ( & V_205 , (struct V_271 T_3 * ) V_166 ) )
return - V_39 ;
return F_132 ( V_8 , & V_205 ,
( (struct V_271 T_3 * ) V_166 ) -> V_207 ,
V_166 ) ;
}
static int F_167 ( struct V_48 * V_50 , void T_3 * T_3 * V_166 )
{
struct V_52 * V_52 = V_50 -> V_52 ;
struct V_271 T_3 * V_64 = V_50 -> V_64 ;
void T_3 * V_253 = V_50 -> V_64 ;
unsigned int V_29 ;
if ( V_50 -> V_250 && V_52 -> V_98 )
if ( F_15 ( V_50 -> V_250 , V_52 -> V_55 ,
V_52 -> V_98 ) )
return - V_39 ;
if ( F_147 ( V_50 -> V_92 , & V_64 -> V_92 ) )
return - V_39 ;
if ( F_147 ( V_52 -> V_98 , & V_64 -> V_98 ) )
return - V_39 ;
if ( F_147 ( V_52 -> V_255 , & V_64 -> V_255 ) )
return - V_39 ;
if ( F_137 ( & V_52 -> V_74 -> V_47 ) ) {
for ( V_29 = 0 ; V_29 < V_52 -> V_227 ; V_29 ++ ) {
if ( F_147 ( V_52 -> V_207 [ V_29 ] . V_98 ,
& V_64 -> V_207 [ V_29 ] . V_98 ) )
return - V_39 ;
if ( F_147 ( V_52 -> V_207 [ V_29 ] . V_92 ,
& V_64 -> V_207 [ V_29 ] . V_92 ) )
return - V_39 ;
}
}
if ( F_147 ( F_168 ( V_253 ) , ( T_5 T_3 * ) V_166 ) )
return - V_39 ;
return 0 ;
}
static int F_169 ( struct V_7 * V_8 , void T_3 * V_166 )
{
struct V_48 * V_50 = F_148 ( V_8 ) ;
if ( V_50 ) {
int V_258 = F_167 ( V_50 , ( void T_3 * T_3 * ) V_166 ) ;
F_23 ( V_50 ) ;
return V_258 ;
}
if ( F_152 ( V_122 ) )
return - V_259 ;
return - V_260 ;
}
static int F_170 ( struct V_7 * V_8 , void T_3 * V_166 )
{
int V_258 ;
struct V_48 * V_50 ;
V_258 = - V_261 ;
V_50 = F_33 ( V_8 ) ;
if ( V_50 ) {
V_258 = F_167 ( V_50 , ( void T_3 * T_3 * ) V_166 ) ;
F_23 ( V_50 ) ;
}
return V_258 ;
}
static int F_171 ( struct V_7 * V_8 , void T_3 * V_166 )
{
struct V_274 V_269 ;
if ( F_102 ( & V_269 , V_166 , sizeof( V_269 ) ) )
return - V_39 ;
V_8 -> V_162 = V_269 . V_91 ;
V_8 -> V_164 = V_269 . V_87 ;
return 0 ;
}
static int F_172 ( struct V_7 * V_8 , void T_3 * V_166 )
{
unsigned int V_107 ;
if ( F_118 ( V_107 , ( unsigned int T_3 * ) V_166 ) )
return - V_39 ;
return F_70 ( V_8 , V_107 ) ;
}
static int F_173 ( struct V_7 * V_8 , void T_3 * V_166 )
{
unsigned int V_107 ;
int V_16 ;
if ( F_118 ( V_107 , ( unsigned int T_3 * ) V_166 ) )
return - V_39 ;
if ( ( V_16 = F_75 ( V_8 , V_107 ) ) < 0 )
return V_16 ;
F_57 ( V_8 , V_107 ) ;
return 0 ;
}
static int F_174 ( struct V_7 * V_8 , struct V_275 * V_276 )
{
int V_277 ;
void * V_22 = NULL ;
int V_258 = 0 ;
struct V_111 * V_112 = NULL ;
struct V_278 * V_188 = NULL ;
if ( ( V_277 = F_175 ( V_276 -> V_279 ) ) > 0 ) {
if ( ( V_22 = F_88 ( V_277 , V_51 ) ) == NULL )
return - V_6 ;
if ( ( F_176 ( V_276 -> V_279 ) & V_280 ) ) {
if ( F_102 ( V_22 , V_276 -> V_70 , V_277 ) ) {
F_22 ( V_22 ) ;
return - V_39 ;
}
} else {
memset ( V_22 , 0 , V_277 ) ;
}
}
if ( ! F_7 ( V_8 ) ) {
F_22 ( V_22 ) ;
return - V_30 ;
}
if ( V_8 -> V_10 -> V_11 != V_120 )
V_258 = - V_121 ;
else if ( ! ( V_112 = F_72 ( V_8 -> V_10 , V_276 -> V_281 ) ) )
V_258 = - V_21 ;
else switch ( V_276 -> V_279 ) {
case V_282 :
if ( V_112 -> V_10 . V_188 ) {
V_188 = F_177 ( V_112 -> V_10 . V_188 ) ;
F_178 ( & V_112 -> V_10 , L_28 ) ;
F_77 ( V_188 , V_112 ) ;
} else
V_258 = - V_189 ;
break;
case V_283 :
if ( ! V_112 -> V_10 . V_188 )
V_258 = F_179 ( & V_112 -> V_10 ) ;
else
V_258 = - V_202 ;
break;
default:
if ( V_112 -> V_10 . V_188 )
V_188 = F_177 ( V_112 -> V_10 . V_188 ) ;
if ( V_188 == NULL || V_188 -> V_284 == NULL ) {
V_258 = - V_285 ;
} else {
V_258 = V_188 -> V_284 ( V_112 , V_276 -> V_279 , V_22 ) ;
if ( V_258 == - V_286 )
V_258 = - V_285 ;
}
}
if ( V_258 >= 0
&& ( F_176 ( V_276 -> V_279 ) & V_287 ) != 0
&& V_277 > 0
&& F_15 ( V_276 -> V_70 , V_22 , V_277 ) != 0 )
V_258 = - V_39 ;
F_22 ( V_22 ) ;
return V_258 ;
}
static int F_180 ( struct V_7 * V_8 , void T_3 * V_166 )
{
struct V_275 V_168 ;
if ( F_102 ( & V_168 , V_166 , sizeof( V_168 ) ) )
return - V_39 ;
return F_174 ( V_8 , & V_168 ) ;
}
static int F_181 ( struct V_7 * V_8 , T_9 V_166 )
{
struct V_288 T_3 * V_289 ;
struct V_275 V_168 ;
T_5 V_264 ;
V_289 = F_161 ( ( long ) V_166 ) ;
if ( ! F_105 ( V_236 , V_289 , sizeof( * V_289 ) ) ||
F_165 ( V_168 . V_281 , & V_289 -> V_281 ) ||
F_165 ( V_168 . V_279 , & V_289 -> V_279 ) ||
F_165 ( V_264 , & V_289 -> V_70 ) )
return - V_39 ;
V_168 . V_70 = F_161 ( V_264 ) ;
return F_174 ( V_8 , & V_168 ) ;
}
static int F_182 ( struct V_7 * V_8 , void T_3 * V_166 )
{
unsigned V_290 ;
int V_291 ;
if ( F_118 ( V_290 , ( unsigned T_3 * ) V_166 ) )
return - V_39 ;
V_291 = F_183 ( V_8 -> V_10 , V_290 , V_8 ) ;
if ( V_291 == 0 )
F_52 ( & V_8 -> V_10 -> V_10 , L_29 ,
V_290 , F_79 ( V_122 ) , V_122 -> V_123 ) ;
return V_291 ;
}
static int F_184 ( struct V_7 * V_8 , void T_3 * V_166 )
{
unsigned V_290 ;
if ( F_118 ( V_290 , ( unsigned T_3 * ) V_166 ) )
return - V_39 ;
return F_185 ( V_8 -> V_10 , V_290 , V_8 ) ;
}
static long F_186 ( struct V_13 * V_13 , unsigned int V_292 ,
void T_3 * V_108 )
{
struct V_7 * V_8 = V_13 -> V_25 ;
struct V_156 * V_156 = V_13 -> V_293 . V_294 -> V_18 ;
struct V_26 * V_10 = V_8 -> V_10 ;
int V_16 = - V_285 ;
if ( ! ( V_13 -> V_295 & V_296 ) )
return - V_297 ;
F_13 ( V_10 ) ;
if ( ! F_7 ( V_8 ) ) {
F_18 ( V_10 ) ;
return - V_30 ;
}
switch ( V_292 ) {
case V_298 :
F_52 ( & V_10 -> V_10 , L_30 , V_299 ) ;
V_16 = F_101 ( V_8 , V_108 ) ;
if ( V_16 >= 0 )
V_156 -> V_300 = V_301 ;
break;
case V_302 :
F_52 ( & V_10 -> V_10 , L_31 , V_299 ) ;
V_16 = F_112 ( V_8 , V_108 ) ;
if ( V_16 >= 0 )
V_156 -> V_300 = V_301 ;
break;
case V_303 :
F_52 ( & V_10 -> V_10 , L_32 , V_299 ) ;
V_16 = F_117 ( V_8 , V_108 ) ;
if ( V_16 >= 0 )
V_156 -> V_300 = V_301 ;
break;
case V_304 :
F_52 ( & V_10 -> V_10 , L_33 , V_299 ) ;
V_16 = F_124 ( V_8 ) ;
break;
case V_305 :
F_52 ( & V_10 -> V_10 , L_34 , V_299 ) ;
V_16 = F_120 ( V_8 , V_108 ) ;
if ( V_16 >= 0 )
V_156 -> V_300 = V_301 ;
break;
case V_306 :
F_52 ( & V_10 -> V_10 , L_35 , V_299 ) ;
V_16 = F_122 ( V_8 , V_108 ) ;
break;
case V_307 :
F_52 ( & V_10 -> V_10 , L_36 , V_299 ) ;
V_16 = F_123 ( V_8 , V_108 ) ;
break;
case V_308 :
F_52 ( & V_10 -> V_10 , L_37 , V_299 ) ;
V_16 = F_126 ( V_8 , V_108 ) ;
break;
case V_309 :
F_52 ( & V_10 -> V_10 , L_38 , V_299 ) ;
V_16 = F_128 ( V_8 , V_108 ) ;
break;
case V_310 :
F_52 ( & V_10 -> V_10 , L_39 , V_299 ) ;
V_16 = F_144 ( V_8 , V_108 ) ;
if ( V_16 >= 0 )
V_156 -> V_300 = V_301 ;
break;
#ifdef F_187
case V_311 :
F_52 ( & V_10 -> V_10 , L_40 , V_299 ) ;
V_16 = F_158 ( V_8 , V_108 ) ;
if ( V_16 >= 0 )
V_156 -> V_300 = V_301 ;
break;
case V_312 :
F_52 ( & V_10 -> V_10 , L_41 , V_299 ) ;
V_16 = F_162 ( V_8 , V_108 ) ;
if ( V_16 >= 0 )
V_156 -> V_300 = V_301 ;
break;
case V_313 :
F_52 ( & V_10 -> V_10 , L_42 , V_299 ) ;
V_16 = F_163 ( V_8 , V_108 ) ;
break;
case V_314 :
F_52 ( & V_10 -> V_10 , L_43 , V_299 ) ;
V_16 = F_166 ( V_8 , V_108 ) ;
if ( V_16 >= 0 )
V_156 -> V_300 = V_301 ;
break;
case V_315 :
F_52 ( & V_10 -> V_10 , L_44 , V_299 ) ;
V_16 = F_169 ( V_8 , V_108 ) ;
break;
case V_316 :
F_52 ( & V_10 -> V_10 , L_45 , V_299 ) ;
V_16 = F_170 ( V_8 , V_108 ) ;
break;
case V_317 :
F_52 ( & V_10 -> V_10 , L_46 , V_299 ) ;
V_16 = F_181 ( V_8 , F_168 ( V_108 ) ) ;
break;
#endif
case V_318 :
F_52 ( & V_10 -> V_10 , L_47 , V_299 ) ;
V_16 = F_145 ( V_8 , V_108 ) ;
break;
case V_319 :
F_52 ( & V_10 -> V_10 , L_48 , V_299 ) ;
V_16 = F_156 ( V_8 , V_108 ) ;
break;
case V_320 :
F_52 ( & V_10 -> V_10 , L_49 , V_299 ) ;
V_16 = F_157 ( V_8 , V_108 ) ;
break;
case V_321 :
F_52 ( & V_10 -> V_10 , L_50 , V_299 ) ;
V_16 = F_171 ( V_8 , V_108 ) ;
break;
case V_322 :
F_52 ( & V_10 -> V_10 , L_51 , V_299 ) ;
V_16 = F_172 ( V_8 , V_108 ) ;
break;
case V_323 :
F_52 ( & V_10 -> V_10 , L_52 , V_299 ) ;
V_16 = F_173 ( V_8 , V_108 ) ;
break;
case V_324 :
F_52 ( & V_10 -> V_10 , L_53 , V_299 ) ;
V_16 = F_180 ( V_8 , V_108 ) ;
break;
case V_325 :
F_52 ( & V_10 -> V_10 , L_54 , V_299 ) ;
V_16 = F_182 ( V_8 , V_108 ) ;
break;
case V_326 :
F_52 ( & V_10 -> V_10 , L_55 , V_299 ) ;
V_16 = F_184 ( V_8 , V_108 ) ;
break;
}
F_18 ( V_10 ) ;
if ( V_16 >= 0 )
V_156 -> V_327 = V_301 ;
return V_16 ;
}
static long F_188 ( struct V_13 * V_13 , unsigned int V_292 ,
unsigned long V_166 )
{
int V_16 ;
V_16 = F_186 ( V_13 , V_292 , ( void T_3 * ) V_166 ) ;
return V_16 ;
}
static long F_189 ( struct V_13 * V_13 , unsigned int V_292 ,
unsigned long V_166 )
{
int V_16 ;
V_16 = F_186 ( V_13 , V_292 , F_161 ( V_166 ) ) ;
return V_16 ;
}
static unsigned int F_190 ( struct V_13 * V_13 ,
struct V_328 * V_105 )
{
struct V_7 * V_8 = V_13 -> V_25 ;
unsigned int V_329 = 0 ;
F_191 ( V_13 , & V_8 -> V_105 , V_105 ) ;
if ( V_13 -> V_295 & V_296 && ! F_8 ( & V_8 -> V_62 ) )
V_329 |= V_330 | V_331 ;
if ( ! F_7 ( V_8 ) )
V_329 |= V_332 | V_333 ;
return V_329 ;
}
static void F_192 ( struct V_26 * V_65 )
{
struct V_7 * V_8 ;
struct V_88 V_89 ;
while ( ! F_8 ( & V_65 -> V_165 ) ) {
V_8 = F_34 ( V_65 -> V_165 . V_63 , struct V_7 , V_9 ) ;
F_60 ( V_8 ) ;
F_193 ( & V_8 -> V_105 ) ;
F_32 ( & V_8 -> V_9 ) ;
if ( V_8 -> V_162 ) {
V_89 . V_93 = V_8 -> V_162 ;
V_89 . V_94 = V_181 ;
V_89 . V_95 = V_96 ;
V_89 . V_97 = V_8 -> V_164 ;
F_53 ( V_8 -> V_162 , & V_89 ,
V_8 -> V_163 , V_8 -> V_54 , V_8 -> V_90 ) ;
}
}
}
static int F_194 ( struct V_334 * V_335 ,
unsigned long V_336 , void * V_10 )
{
switch ( V_336 ) {
case V_337 :
break;
case V_338 :
F_192 ( V_10 ) ;
break;
}
return V_339 ;
}
int T_10 F_195 ( void )
{
int V_258 ;
V_258 = F_196 ( V_340 , V_341 ,
L_56 ) ;
if ( V_258 ) {
F_197 ( V_342 L_57 ) ;
goto V_343;
}
F_198 ( & V_344 , & V_345 ) ;
V_258 = F_199 ( & V_344 , V_340 , V_341 ) ;
if ( V_258 ) {
F_197 ( V_342 L_58 ,
V_159 ) ;
goto V_346;
}
F_200 ( & V_347 ) ;
V_343:
return V_258 ;
V_346:
F_201 ( V_340 , V_341 ) ;
goto V_343;
}
void F_202 ( void )
{
F_203 ( & V_347 ) ;
F_204 ( & V_344 ) ;
F_201 ( V_340 , V_341 ) ;
}
