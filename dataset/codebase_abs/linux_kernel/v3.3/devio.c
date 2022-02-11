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
unsigned long V_58 ;
struct V_48 * V_50 ;
F_28 ( & V_8 -> V_59 , V_58 ) ;
F_36 (as, &ps->async_pending, asynclist)
if ( V_50 -> V_64 == V_64 ) {
F_32 ( & V_50 -> V_60 ) ;
F_30 ( & V_8 -> V_59 , V_58 ) ;
return V_50 ;
}
F_30 ( & V_8 -> V_59 , V_58 ) ;
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
F_44 ( & V_8 -> V_59 ) ;
F_45 ( V_50 -> V_52 ) ;
F_46 ( & V_8 -> V_59 ) ;
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
F_46 ( & V_8 -> V_59 ) ;
F_47 ( & V_50 -> V_60 , & V_8 -> V_62 ) ;
V_50 -> V_92 = V_52 -> V_92 ;
V_91 = V_50 -> V_91 ;
if ( V_91 ) {
V_89 . V_93 = V_50 -> V_91 ;
V_89 . V_94 = V_50 -> V_92 ;
V_89 . V_95 = V_96 ;
V_89 . V_97 = V_50 -> V_64 ;
V_53 = F_48 ( V_50 -> V_53 ) ;
V_54 = F_49 ( V_50 -> V_54 ) ;
V_90 = V_50 -> V_90 ;
}
F_50 ( & V_52 -> V_10 -> V_10 , L_15 ) ;
F_37 ( V_52 -> V_10 , V_50 -> V_64 , V_52 -> V_66 , V_52 -> V_98 ,
V_50 -> V_92 , V_99 ,
( ( V_52 -> V_100 & V_101 ) == V_102 ) ?
NULL : V_52 -> V_55 , V_52 -> V_98 ) ;
if ( V_50 -> V_92 < 0 && V_50 -> V_81 && V_50 -> V_92 != - V_103 &&
V_50 -> V_92 != - V_104 )
F_43 ( V_8 , V_50 -> V_81 ) ;
F_44 ( & V_8 -> V_59 ) ;
if ( V_91 ) {
F_51 ( V_89 . V_93 , & V_89 , V_53 , V_54 , V_90 ) ;
F_24 ( V_53 ) ;
F_25 ( V_54 ) ;
}
F_52 ( & V_8 -> V_105 ) ;
}
static void F_53 ( struct V_7 * V_8 , struct V_106 * V_9 )
{
struct V_48 * V_50 ;
unsigned long V_58 ;
F_28 ( & V_8 -> V_59 , V_58 ) ;
while ( ! F_8 ( V_9 ) ) {
V_50 = F_34 ( V_9 -> V_63 , struct V_48 , V_60 ) ;
F_32 ( & V_50 -> V_60 ) ;
F_30 ( & V_8 -> V_59 , V_58 ) ;
F_54 ( V_50 -> V_52 ) ;
F_28 ( & V_8 -> V_59 , V_58 ) ;
}
F_30 ( & V_8 -> V_59 , V_58 ) ;
}
static void F_55 ( struct V_7 * V_8 ,
unsigned int V_107 )
{
struct V_106 * V_108 , * V_109 , V_110 ;
unsigned long V_58 ;
F_56 ( & V_110 ) ;
F_28 ( & V_8 -> V_59 , V_58 ) ;
F_57 (p, q, &ps->async_pending)
if ( V_107 == F_34 ( V_108 , struct V_48 , V_60 ) -> V_107 )
F_47 ( V_108 , & V_110 ) ;
F_30 ( & V_8 -> V_59 , V_58 ) ;
F_53 ( V_8 , & V_110 ) ;
}
static void F_58 ( struct V_7 * V_8 )
{
F_53 ( V_8 , & V_8 -> V_61 ) ;
}
static int F_59 ( struct V_111 * V_112 ,
const struct V_113 * V_114 )
{
return - V_30 ;
}
static void F_60 ( struct V_111 * V_112 )
{
struct V_7 * V_8 = F_61 ( V_112 ) ;
unsigned int V_107 = V_112 -> V_115 -> V_47 . V_116 ;
if ( ! V_8 )
return;
if ( F_62 ( V_107 < 8 * sizeof( V_8 -> V_117 ) ) )
F_63 ( V_107 , & V_8 -> V_117 ) ;
else
F_64 ( & V_112 -> V_10 , L_16 ,
V_107 ) ;
F_65 ( V_112 , NULL ) ;
F_55 ( V_8 , V_107 ) ;
}
static int F_66 ( struct V_111 * V_112 , T_6 V_118 )
{
return 0 ;
}
static int F_67 ( struct V_111 * V_112 )
{
return 0 ;
}
static int F_68 ( struct V_7 * V_8 , unsigned int V_107 )
{
struct V_26 * V_10 = V_8 -> V_10 ;
struct V_111 * V_112 ;
int V_31 ;
if ( V_107 >= 8 * sizeof( V_8 -> V_117 ) )
return - V_21 ;
if ( F_69 ( V_107 , & V_8 -> V_117 ) )
return 0 ;
V_112 = F_70 ( V_10 , V_107 ) ;
if ( ! V_112 )
V_31 = - V_104 ;
else
V_31 = F_71 ( & V_119 , V_112 , V_8 ) ;
if ( V_31 == 0 )
F_72 ( V_107 , & V_8 -> V_117 ) ;
return V_31 ;
}
static int F_73 ( struct V_7 * V_8 , unsigned int V_107 )
{
struct V_26 * V_10 ;
struct V_111 * V_112 ;
int V_31 ;
V_31 = - V_21 ;
if ( V_107 >= 8 * sizeof( V_8 -> V_117 ) )
return V_31 ;
V_10 = V_8 -> V_10 ;
V_112 = F_70 ( V_10 , V_107 ) ;
if ( ! V_112 )
V_31 = - V_104 ;
else if ( F_74 ( V_107 , & V_8 -> V_117 ) ) {
F_75 ( & V_119 , V_112 ) ;
V_31 = 0 ;
}
return V_31 ;
}
static int F_76 ( struct V_7 * V_8 , unsigned int V_107 )
{
if ( V_8 -> V_10 -> V_11 != V_120 )
return - V_121 ;
if ( V_107 >= 8 * sizeof( V_8 -> V_117 ) )
return - V_21 ;
if ( F_69 ( V_107 , & V_8 -> V_117 ) )
return 0 ;
F_64 ( & V_8 -> V_10 -> V_10 , L_17
L_18 , F_77 ( V_122 ) ,
V_122 -> V_123 , V_107 ) ;
return F_68 ( V_8 , V_107 ) ;
}
static int F_78 ( struct V_26 * V_10 , unsigned int V_74 )
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
static int F_79 ( struct V_7 * V_8 , unsigned int V_139 ,
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
V_142 = F_80 ( V_8 -> V_10 -> V_131 ,
V_141 >> 8 , V_141 & 0xff ) ;
if ( V_142
&& V_142 -> V_47 . V_147 == V_148 )
V_141 >>= 8 ;
}
V_141 &= 0xff ;
switch ( V_139 & V_149 ) {
case V_150 :
V_16 = F_78 ( V_8 -> V_10 , V_141 ) ;
if ( V_16 >= 0 )
V_16 = F_76 ( V_8 , V_16 ) ;
break;
case V_151 :
V_16 = F_76 ( V_8 , V_141 ) ;
break;
}
return V_16 ;
}
static int F_81 ( struct V_152 * V_10 , void * V_70 )
{
return V_10 -> V_153 == ( V_154 ) ( unsigned long ) V_70 ;
}
static struct V_26 * F_82 ( V_154 V_153 )
{
struct V_152 * V_10 ;
V_10 = F_83 ( & V_155 , NULL ,
( void * ) ( unsigned long ) V_153 , F_81 ) ;
if ( ! V_10 )
return NULL ;
return F_84 ( V_10 , struct V_26 , V_10 ) ;
}
static int F_85 ( struct V_156 * V_156 , struct V_13 * V_13 )
{
struct V_26 * V_10 = NULL ;
struct V_7 * V_8 ;
int V_16 ;
V_16 = - V_6 ;
V_8 = F_86 ( sizeof( struct V_7 ) , V_51 ) ;
if ( ! V_8 )
goto V_157;
V_16 = - V_30 ;
F_10 ( & V_158 ) ;
if ( F_87 ( V_156 ) == V_159 )
V_10 = F_82 ( V_156 -> V_160 ) ;
#ifdef F_88
if ( ! V_10 ) {
V_10 = V_156 -> V_161 ;
if ( V_10 && V_10 -> V_162 &&
V_10 -> V_162 -> V_18 == V_156 )
F_89 ( V_10 ) ;
else
V_10 = NULL ;
}
#endif
F_11 ( & V_158 ) ;
if ( ! V_10 )
goto V_157;
F_13 ( V_10 ) ;
if ( V_10 -> V_11 == V_12 )
goto V_163;
V_16 = F_90 ( V_10 ) ;
if ( V_16 )
goto V_163;
V_8 -> V_10 = V_10 ;
V_8 -> V_13 = V_13 ;
F_91 ( & V_8 -> V_59 ) ;
F_56 ( & V_8 -> V_9 ) ;
F_56 ( & V_8 -> V_61 ) ;
F_56 ( & V_8 -> V_62 ) ;
F_92 ( & V_8 -> V_105 ) ;
V_8 -> V_164 = 0 ;
V_8 -> V_165 = F_48 ( F_93 ( V_122 ) ) ;
V_8 -> V_54 = F_94 () ;
V_8 -> V_166 = NULL ;
V_8 -> V_117 = 0 ;
F_95 ( V_122 , & V_8 -> V_90 ) ;
F_96 () ;
F_29 ( & V_8 -> V_9 , & V_10 -> V_167 ) ;
V_13 -> V_25 = V_8 ;
F_18 ( V_10 ) ;
F_50 ( & V_10 -> V_10 , L_19 , F_77 ( V_122 ) ,
V_122 -> V_123 ) ;
return V_16 ;
V_163:
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
if ( F_69 ( V_107 , & V_8 -> V_117 ) )
F_73 ( V_8 , V_107 ) ;
}
F_58 ( V_8 ) ;
F_100 ( V_10 ) ;
F_18 ( V_10 ) ;
F_97 ( V_10 ) ;
F_24 ( V_8 -> V_165 ) ;
F_25 ( V_8 -> V_54 ) ;
V_50 = F_33 ( V_8 ) ;
while ( V_50 ) {
F_23 ( V_50 ) ;
V_50 = F_33 ( V_8 ) ;
}
F_22 ( V_8 ) ;
return 0 ;
}
static int F_101 ( struct V_7 * V_8 , void T_3 * V_168 )
{
struct V_26 * V_10 = V_8 -> V_10 ;
struct V_169 V_170 ;
unsigned int V_171 ;
unsigned char * V_172 ;
unsigned V_173 ;
int V_29 , V_66 , V_16 ;
if ( F_102 ( & V_170 , V_168 , sizeof( V_170 ) ) )
return - V_39 ;
V_16 = F_79 ( V_8 , V_170 . V_174 , V_170 . V_175 ,
V_170 . V_176 ) ;
if ( V_16 )
return V_16 ;
V_173 = V_170 . V_173 ;
if ( V_173 > V_177 )
return - V_21 ;
V_16 = F_1 ( V_177 + sizeof( struct V_52 ) +
sizeof( struct V_178 ) ) ;
if ( V_16 )
return V_16 ;
V_172 = ( unsigned char * ) F_103 ( V_51 ) ;
if ( ! V_172 ) {
V_16 = - V_6 ;
goto V_179;
}
V_171 = V_170 . V_180 ;
F_50 ( & V_10 -> V_10 , L_20
L_21
L_22 ,
V_170 . V_174 , V_170 . V_175 ,
F_104 ( & V_170 . V_181 ) ,
F_104 ( & V_170 . V_176 ) ,
F_104 ( & V_170 . V_173 ) ) ;
if ( V_170 . V_174 & 0x80 ) {
if ( V_170 . V_173 && ! F_105 ( V_182 , V_170 . V_70 ,
V_170 . V_173 ) ) {
V_16 = - V_21 ;
goto V_179;
}
V_66 = F_106 ( V_10 , 0 ) ;
F_37 ( V_10 , NULL , V_66 , V_170 . V_173 , V_171 , V_78 , NULL , 0 ) ;
F_18 ( V_10 ) ;
V_29 = F_107 ( V_10 , V_66 , V_170 . V_175 ,
V_170 . V_174 , V_170 . V_181 , V_170 . V_176 ,
V_172 , V_170 . V_173 , V_171 ) ;
F_13 ( V_10 ) ;
F_37 ( V_10 , NULL , V_66 , F_108 ( V_29 , 0 ) , F_17 ( V_29 , 0 ) , V_99 ,
V_172 , F_108 ( V_29 , 0 ) ) ;
if ( ( V_29 > 0 ) && V_170 . V_173 ) {
if ( F_15 ( V_170 . V_70 , V_172 , V_29 ) ) {
V_16 = - V_39 ;
goto V_179;
}
}
} else {
if ( V_170 . V_173 ) {
if ( F_102 ( V_172 , V_170 . V_70 , V_170 . V_173 ) ) {
V_16 = - V_39 ;
goto V_179;
}
}
V_66 = F_109 ( V_10 , 0 ) ;
F_37 ( V_10 , NULL , V_66 , V_170 . V_173 , V_171 , V_78 ,
V_172 , V_170 . V_173 ) ;
F_18 ( V_10 ) ;
V_29 = F_107 ( V_10 , F_109 ( V_10 , 0 ) , V_170 . V_175 ,
V_170 . V_174 , V_170 . V_181 , V_170 . V_176 ,
V_172 , V_170 . V_173 , V_171 ) ;
F_13 ( V_10 ) ;
F_37 ( V_10 , NULL , V_66 , F_108 ( V_29 , 0 ) , F_17 ( V_29 , 0 ) , V_99 , NULL , 0 ) ;
}
if ( V_29 < 0 && V_29 != - V_183 ) {
F_110 ( V_79 , & V_10 -> V_10 , L_23
L_24 ,
V_122 -> V_123 , V_170 . V_174 , V_170 . V_175 ,
V_170 . V_173 , V_29 ) ;
}
V_16 = V_29 ;
V_179:
F_111 ( ( unsigned long ) V_172 ) ;
F_6 ( V_177 + sizeof( struct V_52 ) +
sizeof( struct V_178 ) ) ;
return V_16 ;
}
static int F_112 ( struct V_7 * V_8 , void T_3 * V_168 )
{
struct V_26 * V_10 = V_8 -> V_10 ;
struct V_184 V_185 ;
unsigned int V_171 , V_186 , V_66 ;
int V_187 ;
unsigned char * V_172 ;
int V_29 , V_16 ;
if ( F_102 ( & V_185 , V_168 , sizeof( V_185 ) ) )
return - V_39 ;
V_16 = F_78 ( V_8 -> V_10 , V_185 . V_74 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_76 ( V_8 , V_16 ) ;
if ( V_16 )
return V_16 ;
if ( V_185 . V_74 & V_130 )
V_66 = F_113 ( V_10 , V_185 . V_74 & 0x7f ) ;
else
V_66 = F_114 ( V_10 , V_185 . V_74 & 0x7f ) ;
if ( ! F_115 ( V_10 , V_66 , ! ( V_185 . V_74 & V_130 ) ) )
return - V_21 ;
V_186 = V_185 . V_27 ;
if ( V_186 >= V_4 )
return - V_21 ;
V_16 = F_1 ( V_186 + sizeof( struct V_52 ) ) ;
if ( V_16 )
return V_16 ;
if ( ! ( V_172 = F_86 ( V_186 , V_51 ) ) ) {
V_16 = - V_6 ;
goto V_179;
}
V_171 = V_185 . V_180 ;
if ( V_185 . V_74 & 0x80 ) {
if ( V_186 && ! F_105 ( V_182 , V_185 . V_70 , V_186 ) ) {
V_16 = - V_21 ;
goto V_179;
}
F_37 ( V_10 , NULL , V_66 , V_186 , V_171 , V_78 , NULL , 0 ) ;
F_18 ( V_10 ) ;
V_29 = F_116 ( V_10 , V_66 , V_172 , V_186 , & V_187 , V_171 ) ;
F_13 ( V_10 ) ;
F_37 ( V_10 , NULL , V_66 , V_187 , V_29 , V_99 , V_172 , V_187 ) ;
if ( ! V_29 && V_187 ) {
if ( F_15 ( V_185 . V_70 , V_172 , V_187 ) ) {
V_16 = - V_39 ;
goto V_179;
}
}
} else {
if ( V_186 ) {
if ( F_102 ( V_172 , V_185 . V_70 , V_186 ) ) {
V_16 = - V_39 ;
goto V_179;
}
}
F_37 ( V_10 , NULL , V_66 , V_186 , V_171 , V_78 , V_172 , V_186 ) ;
F_18 ( V_10 ) ;
V_29 = F_116 ( V_10 , V_66 , V_172 , V_186 , & V_187 , V_171 ) ;
F_13 ( V_10 ) ;
F_37 ( V_10 , NULL , V_66 , V_187 , V_29 , V_99 , NULL , 0 ) ;
}
V_16 = ( V_29 < 0 ? V_29 : V_187 ) ;
V_179:
F_22 ( V_172 ) ;
F_6 ( V_186 + sizeof( struct V_52 ) ) ;
return V_16 ;
}
static int F_117 ( struct V_7 * V_8 , void T_3 * V_168 )
{
unsigned int V_74 ;
int V_16 ;
if ( F_118 ( V_74 , ( unsigned int T_3 * ) V_168 ) )
return - V_39 ;
V_16 = F_78 ( V_8 -> V_10 , V_74 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_76 ( V_8 , V_16 ) ;
if ( V_16 )
return V_16 ;
F_119 ( V_8 -> V_10 , V_74 ) ;
return 0 ;
}
static int F_120 ( struct V_7 * V_8 , void T_3 * V_168 )
{
unsigned int V_74 ;
int V_66 ;
int V_16 ;
if ( F_118 ( V_74 , ( unsigned int T_3 * ) V_168 ) )
return - V_39 ;
V_16 = F_78 ( V_8 -> V_10 , V_74 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_76 ( V_8 , V_16 ) ;
if ( V_16 )
return V_16 ;
if ( V_74 & V_130 )
V_66 = F_113 ( V_8 -> V_10 , V_74 & 0x7f ) ;
else
V_66 = F_114 ( V_8 -> V_10 , V_74 & 0x7f ) ;
return F_121 ( V_8 -> V_10 , V_66 ) ;
}
static int F_122 ( struct V_7 * V_8 , void T_3 * V_168 )
{
struct V_188 V_189 ;
struct V_111 * V_112 ;
int V_16 ;
if ( F_102 ( & V_189 , V_168 , sizeof( V_189 ) ) )
return - V_39 ;
V_112 = F_70 ( V_8 -> V_10 , V_189 . V_134 ) ;
if ( ! V_112 || ! V_112 -> V_10 . V_190 )
V_16 = - V_191 ;
else {
strncpy ( V_189 . V_190 , V_112 -> V_10 . V_190 -> V_192 ,
sizeof( V_189 . V_190 ) ) ;
V_16 = ( F_15 ( V_168 , & V_189 , sizeof( V_189 ) ) ? - V_39 : 0 ) ;
}
return V_16 ;
}
static int F_123 ( struct V_7 * V_8 , void T_3 * V_168 )
{
struct V_193 V_194 = {
. V_195 = V_8 -> V_10 -> V_195 ,
. V_196 = V_8 -> V_10 -> V_197 == V_198
} ;
if ( F_15 ( V_168 , & V_194 , sizeof( V_194 ) ) )
return - V_39 ;
return 0 ;
}
static int F_124 ( struct V_7 * V_8 )
{
return F_125 ( V_8 -> V_10 ) ;
}
static int F_126 ( struct V_7 * V_8 , void T_3 * V_168 )
{
struct V_199 V_200 ;
int V_16 ;
if ( F_102 ( & V_200 , V_168 , sizeof( V_200 ) ) )
return - V_39 ;
if ( ( V_16 = F_76 ( V_8 , V_200 . V_134 ) ) )
return V_16 ;
return F_127 ( V_8 -> V_10 , V_200 . V_134 ,
V_200 . V_115 ) ;
}
static int F_128 ( struct V_7 * V_8 , void T_3 * V_168 )
{
int V_201 ;
int V_92 = 0 ;
struct V_202 * V_131 ;
if ( F_118 ( V_201 , ( int T_3 * ) V_168 ) )
return - V_39 ;
V_131 = V_8 -> V_10 -> V_131 ;
if ( V_131 ) {
int V_29 ;
for ( V_29 = 0 ; V_29 < V_131 -> V_47 . V_133 ; ++ V_29 ) {
if ( F_129 ( V_131 -> V_134 [ V_29 ] ) ) {
F_64 ( & V_8 -> V_10 -> V_10 ,
L_25
L_26 ,
V_131 -> V_134 [ V_29 ]
-> V_203
-> V_47 . V_116 ,
V_131 -> V_134 [ V_29 ]
-> V_10 . V_190 -> V_192 ,
V_122 -> V_123 , V_201 ) ;
V_92 = - V_204 ;
break;
}
}
}
if ( V_92 == 0 ) {
if ( V_131 && V_131 -> V_47 . V_205 == V_201 )
V_92 = F_130 ( V_8 -> V_10 ) ;
else
V_92 = F_131 ( V_8 -> V_10 , V_201 ) ;
}
return V_92 ;
}
static int F_132 ( struct V_7 * V_8 , struct V_206 * V_207 ,
struct V_208 T_3 * V_209 ,
void T_3 * V_168 )
{
struct V_208 * V_210 = NULL ;
struct V_211 * V_74 ;
struct V_48 * V_50 = NULL ;
struct V_178 * V_212 = NULL ;
unsigned int V_201 , V_213 , V_214 ;
int V_16 , V_107 = - 1 ;
int V_215 ;
if ( V_207 -> V_58 & ~ ( V_216 |
V_217 |
V_218 |
V_219 |
V_220 |
V_221 ) )
return - V_21 ;
if ( V_207 -> V_222 > 0 && ! V_207 -> V_223 )
return - V_21 ;
if ( ! ( V_207 -> type == V_224 &&
( V_207 -> V_137 & ~ V_225 ) == 0 ) ) {
V_107 = F_78 ( V_8 -> V_10 , V_207 -> V_137 ) ;
if ( V_107 < 0 )
return V_107 ;
V_16 = F_76 ( V_8 , V_107 ) ;
if ( V_16 )
return V_16 ;
}
if ( ( V_207 -> V_137 & V_225 ) != 0 ) {
V_215 = 1 ;
V_74 = V_8 -> V_10 -> V_226 [ V_207 -> V_137 & V_227 ] ;
} else {
V_215 = 0 ;
V_74 = V_8 -> V_10 -> V_228 [ V_207 -> V_137 & V_227 ] ;
}
if ( ! V_74 )
return - V_104 ;
V_201 = 0 ;
switch( V_207 -> type ) {
case V_224 :
if ( ! F_133 ( & V_74 -> V_47 ) )
return - V_21 ;
if ( V_207 -> V_222 < 8 )
return - V_21 ;
V_212 = F_86 ( sizeof( struct V_178 ) , V_51 ) ;
if ( ! V_212 )
return - V_6 ;
if ( F_102 ( V_212 , V_207 -> V_223 , 8 ) ) {
V_16 = - V_39 ;
goto error;
}
if ( V_207 -> V_222 < ( F_134 ( & V_212 -> V_173 ) + 8 ) ) {
V_16 = - V_21 ;
goto error;
}
V_16 = F_79 ( V_8 , V_212 -> V_174 , V_212 -> V_175 ,
F_134 ( & V_212 -> V_176 ) ) ;
if ( V_16 )
goto error;
V_207 -> V_229 = 0 ;
V_207 -> V_222 = F_134 ( & V_212 -> V_173 ) ;
V_207 -> V_223 += 8 ;
if ( ( V_212 -> V_174 & V_130 ) && V_207 -> V_222 ) {
V_215 = 1 ;
V_207 -> V_137 |= V_130 ;
} else {
V_215 = 0 ;
V_207 -> V_137 &= ~ V_130 ;
}
F_50 ( & V_8 -> V_10 -> V_10 , L_20
L_21
L_22 ,
V_212 -> V_174 , V_212 -> V_175 ,
F_104 ( & V_212 -> V_181 ) ,
F_104 ( & V_212 -> V_176 ) ,
F_104 ( & V_212 -> V_173 ) ) ;
V_201 = sizeof( struct V_178 ) ;
break;
case V_230 :
switch ( F_135 ( & V_74 -> V_47 ) ) {
case V_231 :
case V_232 :
return - V_21 ;
case V_233 :
V_207 -> type = V_234 ;
goto V_235;
}
V_207 -> V_229 = 0 ;
break;
case V_234 :
if ( ! F_136 ( & V_74 -> V_47 ) )
return - V_21 ;
V_235:
V_207 -> V_229 = 0 ;
break;
case V_236 :
if ( V_207 -> V_229 < 1 ||
V_207 -> V_229 > 128 )
return - V_21 ;
if ( ! F_137 ( & V_74 -> V_47 ) )
return - V_21 ;
V_214 = sizeof( struct V_208 ) *
V_207 -> V_229 ;
if ( ! ( V_210 = F_86 ( V_214 , V_51 ) ) )
return - V_6 ;
if ( F_102 ( V_210 , V_209 , V_214 ) ) {
V_16 = - V_39 ;
goto error;
}
for ( V_213 = V_201 = 0 ; V_201 < V_207 -> V_229 ; V_201 ++ ) {
if ( V_210 [ V_201 ] . V_44 > 8192 ) {
V_16 = - V_21 ;
goto error;
}
V_213 += V_210 [ V_201 ] . V_44 ;
}
V_201 *= sizeof( struct V_237 ) ;
V_207 -> V_222 = V_213 ;
break;
default:
return - V_21 ;
}
if ( V_207 -> V_222 >= V_4 ) {
V_16 = - V_21 ;
goto error;
}
if ( V_207 -> V_222 > 0 &&
! F_105 ( V_215 ? V_182 : V_238 ,
V_207 -> V_223 , V_207 -> V_222 ) ) {
V_16 = - V_39 ;
goto error;
}
V_50 = F_19 ( V_207 -> V_229 ) ;
if ( ! V_50 ) {
V_16 = - V_6 ;
goto error;
}
V_201 += sizeof( struct V_48 ) + sizeof( struct V_52 ) + V_207 -> V_222 ;
V_16 = F_1 ( V_201 ) ;
if ( V_16 )
goto error;
V_50 -> V_57 = V_201 ;
if ( V_207 -> V_222 > 0 ) {
V_50 -> V_52 -> V_55 = F_86 ( V_207 -> V_222 ,
V_51 ) ;
if ( ! V_50 -> V_52 -> V_55 ) {
V_16 = - V_6 ;
goto error;
}
if ( V_215 && V_207 -> type == V_236 )
memset ( V_50 -> V_52 -> V_55 , 0 ,
V_207 -> V_222 ) ;
}
V_50 -> V_52 -> V_10 = V_8 -> V_10 ;
V_50 -> V_52 -> V_66 = ( V_207 -> type << 30 ) |
F_138 ( V_8 -> V_10 , V_207 -> V_137 & 0xf ) |
( V_207 -> V_137 & V_130 ) ;
V_201 = ( V_215 ? V_239 : V_240 ) ;
if ( V_207 -> V_58 & V_216 )
V_201 |= V_241 ;
if ( V_207 -> V_58 & V_217 )
V_201 |= V_242 ;
if ( V_207 -> V_58 & V_219 )
V_201 |= V_243 ;
if ( V_207 -> V_58 & V_220 )
V_201 |= V_244 ;
if ( V_207 -> V_58 & V_221 )
V_201 |= V_245 ;
V_50 -> V_52 -> V_100 = V_201 ;
V_50 -> V_52 -> V_246 = V_207 -> V_222 ;
V_50 -> V_52 -> V_56 = ( unsigned char * ) V_212 ;
V_212 = NULL ;
V_50 -> V_52 -> V_247 = V_207 -> V_247 ;
V_50 -> V_52 -> V_229 = V_207 -> V_229 ;
if ( V_207 -> type == V_236 ||
V_8 -> V_10 -> V_197 == V_248 )
V_50 -> V_52 -> V_249 = 1 << F_17 ( 15 , V_74 -> V_47 . V_250 - 1 ) ;
else
V_50 -> V_52 -> V_249 = V_74 -> V_47 . V_250 ;
V_50 -> V_52 -> V_87 = V_50 ;
V_50 -> V_52 -> V_251 = V_62 ;
for ( V_213 = V_201 = 0 ; V_201 < V_207 -> V_229 ; V_201 ++ ) {
V_50 -> V_52 -> V_209 [ V_201 ] . V_14 = V_213 ;
V_50 -> V_52 -> V_209 [ V_201 ] . V_44 = V_210 [ V_201 ] . V_44 ;
V_213 += V_210 [ V_201 ] . V_44 ;
}
F_22 ( V_210 ) ;
V_210 = NULL ;
V_50 -> V_8 = V_8 ;
V_50 -> V_64 = V_168 ;
if ( V_215 && V_207 -> V_222 > 0 )
V_50 -> V_252 = V_207 -> V_223 ;
else
V_50 -> V_252 = NULL ;
V_50 -> V_91 = V_207 -> V_91 ;
V_50 -> V_107 = V_107 ;
V_50 -> V_53 = F_48 ( F_93 ( V_122 ) ) ;
V_50 -> V_54 = F_94 () ;
F_95 ( V_122 , & V_50 -> V_90 ) ;
if ( ! V_215 && V_207 -> V_222 > 0 ) {
if ( F_102 ( V_50 -> V_52 -> V_55 , V_207 -> V_223 ,
V_207 -> V_222 ) ) {
V_16 = - V_39 ;
goto error;
}
}
F_37 ( V_8 -> V_10 , V_50 -> V_64 , V_50 -> V_52 -> V_66 ,
V_50 -> V_52 -> V_246 , 0 , V_78 ,
V_215 ? NULL : V_50 -> V_52 -> V_55 ,
V_207 -> V_222 ) ;
F_27 ( V_50 ) ;
if ( F_139 ( & V_74 -> V_47 ) ) {
F_140 ( & V_8 -> V_59 ) ;
V_50 -> V_81 = F_141 ( & V_74 -> V_47 ) |
( ( V_74 -> V_47 . V_138 & V_225 )
>> 3 ) ;
if ( V_207 -> V_58 & V_218 )
V_50 -> V_82 = V_83 ;
else
V_8 -> V_86 &= ~ ( 1 << V_50 -> V_81 ) ;
if ( V_8 -> V_86 & ( 1 << V_50 -> V_81 ) )
V_16 = - V_253 ;
else
V_16 = F_142 ( V_50 -> V_52 , V_254 ) ;
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
F_22 ( V_210 ) ;
F_22 ( V_212 ) ;
if ( V_50 )
F_23 ( V_50 ) ;
return V_16 ;
}
static int F_144 ( struct V_7 * V_8 , void T_3 * V_168 )
{
struct V_206 V_207 ;
if ( F_102 ( & V_207 , V_168 , sizeof( V_207 ) ) )
return - V_39 ;
return F_132 ( V_8 , & V_207 ,
( ( (struct V_206 T_3 * ) V_168 ) -> V_209 ) ,
V_168 ) ;
}
static int F_145 ( struct V_7 * V_8 , void T_3 * V_168 )
{
struct V_48 * V_50 ;
V_50 = F_35 ( V_8 , V_168 ) ;
if ( ! V_50 )
return - V_21 ;
F_54 ( V_50 -> V_52 ) ;
return 0 ;
}
static int F_146 ( struct V_48 * V_50 , void T_3 * T_3 * V_168 )
{
struct V_52 * V_52 = V_50 -> V_52 ;
struct V_206 T_3 * V_64 = V_50 -> V_64 ;
void T_3 * V_255 = V_50 -> V_64 ;
unsigned int V_29 ;
if ( V_50 -> V_252 && V_52 -> V_98 ) {
if ( V_52 -> V_229 > 0 )
V_29 = V_52 -> V_246 ;
else
V_29 = V_52 -> V_98 ;
if ( F_15 ( V_50 -> V_252 , V_52 -> V_55 , V_29 ) )
goto V_256;
}
if ( F_147 ( V_50 -> V_92 , & V_64 -> V_92 ) )
goto V_256;
if ( F_147 ( V_52 -> V_98 , & V_64 -> V_98 ) )
goto V_256;
if ( F_147 ( V_52 -> V_257 , & V_64 -> V_257 ) )
goto V_256;
if ( F_137 ( & V_52 -> V_74 -> V_47 ) ) {
for ( V_29 = 0 ; V_29 < V_52 -> V_229 ; V_29 ++ ) {
if ( F_147 ( V_52 -> V_209 [ V_29 ] . V_98 ,
& V_64 -> V_209 [ V_29 ] . V_98 ) )
goto V_256;
if ( F_147 ( V_52 -> V_209 [ V_29 ] . V_92 ,
& V_64 -> V_209 [ V_29 ] . V_92 ) )
goto V_256;
}
}
if ( F_147 ( V_255 , ( void T_3 * T_3 * ) V_168 ) )
return - V_39 ;
return 0 ;
V_256:
return - V_39 ;
}
static struct V_48 * F_148 ( struct V_7 * V_8 )
{
F_149 ( V_105 , V_122 ) ;
struct V_48 * V_50 = NULL ;
struct V_26 * V_10 = V_8 -> V_10 ;
F_150 ( & V_8 -> V_105 , & V_105 ) ;
for (; ; ) {
F_151 ( V_258 ) ;
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
F_155 ( V_259 ) ;
return V_50 ;
}
static int F_156 ( struct V_7 * V_8 , void T_3 * V_168 )
{
struct V_48 * V_50 = F_148 ( V_8 ) ;
if ( V_50 ) {
int V_260 = F_146 ( V_50 , ( void T_3 * T_3 * ) V_168 ) ;
F_23 ( V_50 ) ;
return V_260 ;
}
if ( F_152 ( V_122 ) )
return - V_261 ;
return - V_262 ;
}
static int F_157 ( struct V_7 * V_8 , void T_3 * V_168 )
{
int V_260 ;
struct V_48 * V_50 ;
V_50 = F_33 ( V_8 ) ;
V_260 = - V_263 ;
if ( V_50 ) {
V_260 = F_146 ( V_50 , ( void T_3 * T_3 * ) V_168 ) ;
F_23 ( V_50 ) ;
}
return V_260 ;
}
static int F_158 ( struct V_7 * V_8 ,
struct V_264 T_3 * V_265 )
{
struct V_169 T_3 * V_108 ;
T_7 V_266 ;
V_108 = F_159 ( sizeof( * V_108 ) ) ;
if ( F_160 ( V_108 , V_265 , ( sizeof( * V_265 ) - sizeof( V_267 ) ) ) ||
F_118 ( V_266 , & V_265 -> V_70 ) ||
F_147 ( F_161 ( V_266 ) , & V_108 -> V_70 ) )
return - V_39 ;
return F_101 ( V_8 , V_108 ) ;
}
static int F_162 ( struct V_7 * V_8 ,
struct V_268 T_3 * V_265 )
{
struct V_184 T_3 * V_108 ;
T_8 V_269 ;
V_267 V_255 ;
V_108 = F_159 ( sizeof( * V_108 ) ) ;
if ( F_118 ( V_269 , & V_265 -> V_74 ) || F_147 ( V_269 , & V_108 -> V_74 ) ||
F_118 ( V_269 , & V_265 -> V_27 ) || F_147 ( V_269 , & V_108 -> V_27 ) ||
F_118 ( V_269 , & V_265 -> V_180 ) || F_147 ( V_269 , & V_108 -> V_180 ) ||
F_118 ( V_255 , & V_265 -> V_70 ) || F_147 ( F_161 ( V_255 ) , & V_108 -> V_70 ) )
return - V_39 ;
return F_112 ( V_8 , V_108 ) ;
}
static int F_163 ( struct V_7 * V_8 , void T_3 * V_168 )
{
struct V_270 V_271 ;
if ( F_102 ( & V_271 , V_168 , sizeof( V_271 ) ) )
return - V_39 ;
V_8 -> V_164 = V_271 . V_91 ;
V_8 -> V_166 = F_161 ( V_271 . V_87 ) ;
return 0 ;
}
static int F_164 ( struct V_206 * V_272 ,
struct V_273 T_3 * V_207 )
{
T_7 V_274 ;
if ( ! F_105 ( V_238 , V_207 , sizeof( * V_207 ) ) ||
F_165 ( V_272 -> type , & V_207 -> type ) ||
F_165 ( V_272 -> V_137 , & V_207 -> V_137 ) ||
F_165 ( V_272 -> V_92 , & V_207 -> V_92 ) ||
F_165 ( V_272 -> V_58 , & V_207 -> V_58 ) ||
F_165 ( V_272 -> V_222 , & V_207 -> V_222 ) ||
F_165 ( V_272 -> V_98 , & V_207 -> V_98 ) ||
F_165 ( V_272 -> V_247 , & V_207 -> V_247 ) ||
F_165 ( V_272 -> V_229 , & V_207 -> V_229 ) ||
F_165 ( V_272 -> V_257 , & V_207 -> V_257 ) ||
F_165 ( V_272 -> V_91 , & V_207 -> V_91 ) )
return - V_39 ;
if ( F_165 ( V_274 , & V_207 -> V_223 ) )
return - V_39 ;
V_272 -> V_223 = F_161 ( V_274 ) ;
if ( F_165 ( V_274 , & V_207 -> V_275 ) )
return - V_39 ;
V_272 -> V_275 = F_161 ( V_274 ) ;
return 0 ;
}
static int F_166 ( struct V_7 * V_8 , void T_3 * V_168 )
{
struct V_206 V_207 ;
if ( F_164 ( & V_207 , (struct V_273 T_3 * ) V_168 ) )
return - V_39 ;
return F_132 ( V_8 , & V_207 ,
( (struct V_273 T_3 * ) V_168 ) -> V_209 ,
V_168 ) ;
}
static int F_167 ( struct V_48 * V_50 , void T_3 * T_3 * V_168 )
{
struct V_52 * V_52 = V_50 -> V_52 ;
struct V_273 T_3 * V_64 = V_50 -> V_64 ;
void T_3 * V_255 = V_50 -> V_64 ;
unsigned int V_29 ;
if ( V_50 -> V_252 && V_52 -> V_98 )
if ( F_15 ( V_50 -> V_252 , V_52 -> V_55 ,
V_52 -> V_98 ) )
return - V_39 ;
if ( F_147 ( V_50 -> V_92 , & V_64 -> V_92 ) )
return - V_39 ;
if ( F_147 ( V_52 -> V_98 , & V_64 -> V_98 ) )
return - V_39 ;
if ( F_147 ( V_52 -> V_257 , & V_64 -> V_257 ) )
return - V_39 ;
if ( F_137 ( & V_52 -> V_74 -> V_47 ) ) {
for ( V_29 = 0 ; V_29 < V_52 -> V_229 ; V_29 ++ ) {
if ( F_147 ( V_52 -> V_209 [ V_29 ] . V_98 ,
& V_64 -> V_209 [ V_29 ] . V_98 ) )
return - V_39 ;
if ( F_147 ( V_52 -> V_209 [ V_29 ] . V_92 ,
& V_64 -> V_209 [ V_29 ] . V_92 ) )
return - V_39 ;
}
}
if ( F_147 ( F_168 ( V_255 ) , ( T_5 T_3 * ) V_168 ) )
return - V_39 ;
return 0 ;
}
static int F_169 ( struct V_7 * V_8 , void T_3 * V_168 )
{
struct V_48 * V_50 = F_148 ( V_8 ) ;
if ( V_50 ) {
int V_260 = F_167 ( V_50 , ( void T_3 * T_3 * ) V_168 ) ;
F_23 ( V_50 ) ;
return V_260 ;
}
if ( F_152 ( V_122 ) )
return - V_261 ;
return - V_262 ;
}
static int F_170 ( struct V_7 * V_8 , void T_3 * V_168 )
{
int V_260 ;
struct V_48 * V_50 ;
V_260 = - V_263 ;
V_50 = F_33 ( V_8 ) ;
if ( V_50 ) {
V_260 = F_167 ( V_50 , ( void T_3 * T_3 * ) V_168 ) ;
F_23 ( V_50 ) ;
}
return V_260 ;
}
static int F_171 ( struct V_7 * V_8 , void T_3 * V_168 )
{
struct V_276 V_271 ;
if ( F_102 ( & V_271 , V_168 , sizeof( V_271 ) ) )
return - V_39 ;
V_8 -> V_164 = V_271 . V_91 ;
V_8 -> V_166 = V_271 . V_87 ;
return 0 ;
}
static int F_172 ( struct V_7 * V_8 , void T_3 * V_168 )
{
unsigned int V_107 ;
if ( F_118 ( V_107 , ( unsigned int T_3 * ) V_168 ) )
return - V_39 ;
return F_68 ( V_8 , V_107 ) ;
}
static int F_173 ( struct V_7 * V_8 , void T_3 * V_168 )
{
unsigned int V_107 ;
int V_16 ;
if ( F_118 ( V_107 , ( unsigned int T_3 * ) V_168 ) )
return - V_39 ;
if ( ( V_16 = F_73 ( V_8 , V_107 ) ) < 0 )
return V_16 ;
F_55 ( V_8 , V_107 ) ;
return 0 ;
}
static int F_174 ( struct V_7 * V_8 , struct V_277 * V_278 )
{
int V_279 ;
void * V_22 = NULL ;
int V_260 = 0 ;
struct V_111 * V_112 = NULL ;
struct V_280 * V_190 = NULL ;
if ( ( V_279 = F_175 ( V_278 -> V_281 ) ) > 0 ) {
if ( ( V_22 = F_86 ( V_279 , V_51 ) ) == NULL )
return - V_6 ;
if ( ( F_176 ( V_278 -> V_281 ) & V_282 ) ) {
if ( F_102 ( V_22 , V_278 -> V_70 , V_279 ) ) {
F_22 ( V_22 ) ;
return - V_39 ;
}
} else {
memset ( V_22 , 0 , V_279 ) ;
}
}
if ( ! F_7 ( V_8 ) ) {
F_22 ( V_22 ) ;
return - V_30 ;
}
if ( V_8 -> V_10 -> V_11 != V_120 )
V_260 = - V_121 ;
else if ( ! ( V_112 = F_70 ( V_8 -> V_10 , V_278 -> V_283 ) ) )
V_260 = - V_21 ;
else switch ( V_278 -> V_281 ) {
case V_284 :
if ( V_112 -> V_10 . V_190 ) {
V_190 = F_177 ( V_112 -> V_10 . V_190 ) ;
F_178 ( & V_112 -> V_10 , L_28 ) ;
F_75 ( V_190 , V_112 ) ;
} else
V_260 = - V_191 ;
break;
case V_285 :
if ( ! V_112 -> V_10 . V_190 )
V_260 = F_179 ( & V_112 -> V_10 ) ;
else
V_260 = - V_204 ;
break;
default:
if ( V_112 -> V_10 . V_190 )
V_190 = F_177 ( V_112 -> V_10 . V_190 ) ;
if ( V_190 == NULL || V_190 -> V_286 == NULL ) {
V_260 = - V_287 ;
} else {
V_260 = V_190 -> V_286 ( V_112 , V_278 -> V_281 , V_22 ) ;
if ( V_260 == - V_288 )
V_260 = - V_287 ;
}
}
if ( V_260 >= 0
&& ( F_176 ( V_278 -> V_281 ) & V_289 ) != 0
&& V_279 > 0
&& F_15 ( V_278 -> V_70 , V_22 , V_279 ) != 0 )
V_260 = - V_39 ;
F_22 ( V_22 ) ;
return V_260 ;
}
static int F_180 ( struct V_7 * V_8 , void T_3 * V_168 )
{
struct V_277 V_170 ;
if ( F_102 ( & V_170 , V_168 , sizeof( V_170 ) ) )
return - V_39 ;
return F_174 ( V_8 , & V_170 ) ;
}
static int F_181 ( struct V_7 * V_8 , T_9 V_168 )
{
struct V_290 T_3 * V_291 ;
struct V_277 V_170 ;
T_5 V_266 ;
V_291 = F_161 ( ( long ) V_168 ) ;
if ( ! F_105 ( V_238 , V_291 , sizeof( * V_291 ) ) ||
F_165 ( V_170 . V_283 , & V_291 -> V_283 ) ||
F_165 ( V_170 . V_281 , & V_291 -> V_281 ) ||
F_165 ( V_266 , & V_291 -> V_70 ) )
return - V_39 ;
V_170 . V_70 = F_161 ( V_266 ) ;
return F_174 ( V_8 , & V_170 ) ;
}
static int F_182 ( struct V_7 * V_8 , void T_3 * V_168 )
{
unsigned V_292 ;
int V_293 ;
if ( F_118 ( V_292 , ( unsigned T_3 * ) V_168 ) )
return - V_39 ;
V_293 = F_183 ( V_8 -> V_10 , V_292 , V_8 ) ;
if ( V_293 == 0 )
F_50 ( & V_8 -> V_10 -> V_10 , L_29 ,
V_292 , F_77 ( V_122 ) , V_122 -> V_123 ) ;
return V_293 ;
}
static int F_184 ( struct V_7 * V_8 , void T_3 * V_168 )
{
unsigned V_292 ;
if ( F_118 ( V_292 , ( unsigned T_3 * ) V_168 ) )
return - V_39 ;
return F_185 ( V_8 -> V_10 , V_292 , V_8 ) ;
}
static long F_186 ( struct V_13 * V_13 , unsigned int V_294 ,
void T_3 * V_108 )
{
struct V_7 * V_8 = V_13 -> V_25 ;
struct V_156 * V_156 = V_13 -> V_295 . V_296 -> V_18 ;
struct V_26 * V_10 = V_8 -> V_10 ;
int V_16 = - V_287 ;
if ( ! ( V_13 -> V_297 & V_298 ) )
return - V_299 ;
F_13 ( V_10 ) ;
if ( ! F_7 ( V_8 ) ) {
F_18 ( V_10 ) ;
return - V_30 ;
}
switch ( V_294 ) {
case V_300 :
F_50 ( & V_10 -> V_10 , L_30 , V_301 ) ;
V_16 = F_101 ( V_8 , V_108 ) ;
if ( V_16 >= 0 )
V_156 -> V_302 = V_303 ;
break;
case V_304 :
F_50 ( & V_10 -> V_10 , L_31 , V_301 ) ;
V_16 = F_112 ( V_8 , V_108 ) ;
if ( V_16 >= 0 )
V_156 -> V_302 = V_303 ;
break;
case V_305 :
F_50 ( & V_10 -> V_10 , L_32 , V_301 ) ;
V_16 = F_117 ( V_8 , V_108 ) ;
if ( V_16 >= 0 )
V_156 -> V_302 = V_303 ;
break;
case V_306 :
F_50 ( & V_10 -> V_10 , L_33 , V_301 ) ;
V_16 = F_124 ( V_8 ) ;
break;
case V_307 :
F_50 ( & V_10 -> V_10 , L_34 , V_301 ) ;
V_16 = F_120 ( V_8 , V_108 ) ;
if ( V_16 >= 0 )
V_156 -> V_302 = V_303 ;
break;
case V_308 :
F_50 ( & V_10 -> V_10 , L_35 , V_301 ) ;
V_16 = F_122 ( V_8 , V_108 ) ;
break;
case V_309 :
F_50 ( & V_10 -> V_10 , L_36 , V_301 ) ;
V_16 = F_123 ( V_8 , V_108 ) ;
break;
case V_310 :
F_50 ( & V_10 -> V_10 , L_37 , V_301 ) ;
V_16 = F_126 ( V_8 , V_108 ) ;
break;
case V_311 :
F_50 ( & V_10 -> V_10 , L_38 , V_301 ) ;
V_16 = F_128 ( V_8 , V_108 ) ;
break;
case V_312 :
F_50 ( & V_10 -> V_10 , L_39 , V_301 ) ;
V_16 = F_144 ( V_8 , V_108 ) ;
if ( V_16 >= 0 )
V_156 -> V_302 = V_303 ;
break;
#ifdef F_187
case V_313 :
F_50 ( & V_10 -> V_10 , L_40 , V_301 ) ;
V_16 = F_158 ( V_8 , V_108 ) ;
if ( V_16 >= 0 )
V_156 -> V_302 = V_303 ;
break;
case V_314 :
F_50 ( & V_10 -> V_10 , L_41 , V_301 ) ;
V_16 = F_162 ( V_8 , V_108 ) ;
if ( V_16 >= 0 )
V_156 -> V_302 = V_303 ;
break;
case V_315 :
F_50 ( & V_10 -> V_10 , L_42 , V_301 ) ;
V_16 = F_163 ( V_8 , V_108 ) ;
break;
case V_316 :
F_50 ( & V_10 -> V_10 , L_43 , V_301 ) ;
V_16 = F_166 ( V_8 , V_108 ) ;
if ( V_16 >= 0 )
V_156 -> V_302 = V_303 ;
break;
case V_317 :
F_50 ( & V_10 -> V_10 , L_44 , V_301 ) ;
V_16 = F_169 ( V_8 , V_108 ) ;
break;
case V_318 :
F_50 ( & V_10 -> V_10 , L_45 , V_301 ) ;
V_16 = F_170 ( V_8 , V_108 ) ;
break;
case V_319 :
F_50 ( & V_10 -> V_10 , L_46 , V_301 ) ;
V_16 = F_181 ( V_8 , F_168 ( V_108 ) ) ;
break;
#endif
case V_320 :
F_50 ( & V_10 -> V_10 , L_47 , V_301 ) ;
V_16 = F_145 ( V_8 , V_108 ) ;
break;
case V_321 :
F_50 ( & V_10 -> V_10 , L_48 , V_301 ) ;
V_16 = F_156 ( V_8 , V_108 ) ;
break;
case V_322 :
F_50 ( & V_10 -> V_10 , L_49 , V_301 ) ;
V_16 = F_157 ( V_8 , V_108 ) ;
break;
case V_323 :
F_50 ( & V_10 -> V_10 , L_50 , V_301 ) ;
V_16 = F_171 ( V_8 , V_108 ) ;
break;
case V_324 :
F_50 ( & V_10 -> V_10 , L_51 , V_301 ) ;
V_16 = F_172 ( V_8 , V_108 ) ;
break;
case V_325 :
F_50 ( & V_10 -> V_10 , L_52 , V_301 ) ;
V_16 = F_173 ( V_8 , V_108 ) ;
break;
case V_326 :
F_50 ( & V_10 -> V_10 , L_53 , V_301 ) ;
V_16 = F_180 ( V_8 , V_108 ) ;
break;
case V_327 :
F_50 ( & V_10 -> V_10 , L_54 , V_301 ) ;
V_16 = F_182 ( V_8 , V_108 ) ;
break;
case V_328 :
F_50 ( & V_10 -> V_10 , L_55 , V_301 ) ;
V_16 = F_184 ( V_8 , V_108 ) ;
break;
}
F_18 ( V_10 ) ;
if ( V_16 >= 0 )
V_156 -> V_329 = V_303 ;
return V_16 ;
}
static long F_188 ( struct V_13 * V_13 , unsigned int V_294 ,
unsigned long V_168 )
{
int V_16 ;
V_16 = F_186 ( V_13 , V_294 , ( void T_3 * ) V_168 ) ;
return V_16 ;
}
static long F_189 ( struct V_13 * V_13 , unsigned int V_294 ,
unsigned long V_168 )
{
int V_16 ;
V_16 = F_186 ( V_13 , V_294 , F_161 ( V_168 ) ) ;
return V_16 ;
}
static unsigned int F_190 ( struct V_13 * V_13 ,
struct V_330 * V_105 )
{
struct V_7 * V_8 = V_13 -> V_25 ;
unsigned int V_331 = 0 ;
F_191 ( V_13 , & V_8 -> V_105 , V_105 ) ;
if ( V_13 -> V_297 & V_298 && ! F_8 ( & V_8 -> V_62 ) )
V_331 |= V_332 | V_333 ;
if ( ! F_7 ( V_8 ) )
V_331 |= V_334 | V_335 ;
return V_331 ;
}
static void F_192 ( struct V_26 * V_65 )
{
struct V_7 * V_8 ;
struct V_88 V_89 ;
while ( ! F_8 ( & V_65 -> V_167 ) ) {
V_8 = F_34 ( V_65 -> V_167 . V_63 , struct V_7 , V_9 ) ;
F_58 ( V_8 ) ;
F_193 ( & V_8 -> V_105 ) ;
F_32 ( & V_8 -> V_9 ) ;
if ( V_8 -> V_164 ) {
V_89 . V_93 = V_8 -> V_164 ;
V_89 . V_94 = V_183 ;
V_89 . V_95 = V_96 ;
V_89 . V_97 = V_8 -> V_166 ;
F_51 ( V_8 -> V_164 , & V_89 ,
V_8 -> V_165 , V_8 -> V_54 , V_8 -> V_90 ) ;
}
}
}
static int F_194 ( struct V_26 * V_10 )
{
struct V_152 * V_336 ;
V_336 = F_195 ( V_337 , & V_10 -> V_10 , V_10 -> V_10 . V_153 ,
NULL , L_56 , V_10 -> V_338 -> V_339 ,
V_10 -> V_195 ) ;
if ( F_196 ( V_336 ) )
return F_197 ( V_336 ) ;
V_10 -> V_340 = V_336 ;
return 0 ;
}
static void F_198 ( struct V_26 * V_10 )
{
if ( V_10 -> V_340 )
F_199 ( V_10 -> V_340 ) ;
}
static int F_200 ( struct V_341 * V_342 ,
unsigned long V_343 , void * V_10 )
{
switch ( V_343 ) {
case V_344 :
if ( F_194 ( V_10 ) )
return V_345 ;
break;
case V_346 :
F_198 ( V_10 ) ;
F_192 ( V_10 ) ;
break;
}
return V_347 ;
}
int T_10 F_201 ( void )
{
int V_260 ;
V_260 = F_202 ( V_348 , V_349 ,
L_57 ) ;
if ( V_260 ) {
F_203 ( V_350 L_58 ) ;
goto V_351;
}
F_204 ( & V_352 , & V_353 ) ;
V_260 = F_205 ( & V_352 , V_348 , V_349 ) ;
if ( V_260 ) {
F_203 ( V_350 L_59 ,
V_159 ) ;
goto V_354;
}
#ifdef F_206
V_337 = F_207 ( V_355 , L_57 ) ;
if ( F_196 ( V_337 ) ) {
F_203 ( V_350 L_60 ) ;
V_260 = F_197 ( V_337 ) ;
F_208 ( & V_352 ) ;
V_337 = NULL ;
goto V_351;
}
V_337 -> V_356 = NULL ;
#endif
F_209 ( & V_357 ) ;
V_351:
return V_260 ;
V_354:
F_210 ( V_348 , V_349 ) ;
goto V_351;
}
void F_211 ( void )
{
F_212 ( & V_357 ) ;
#ifdef F_206
F_213 ( V_337 ) ;
#endif
F_208 ( & V_352 ) ;
F_210 ( V_348 , V_349 ) ;
}
