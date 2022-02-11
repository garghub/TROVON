static int F_1 ( struct V_1 * V_2 )
{
return ( ! F_2 ( & V_2 -> V_3 ) &&
V_2 -> V_4 -> V_5 != V_6 ) ;
}
static T_1 F_3 ( struct V_7 * V_7 , T_1 V_8 , int V_9 )
{
T_1 V_10 ;
F_4 ( & V_7 -> V_11 -> V_12 -> V_13 ) ;
switch ( V_9 ) {
case 0 :
V_7 -> V_14 = V_8 ;
V_10 = V_7 -> V_14 ;
break;
case 1 :
V_7 -> V_14 += V_8 ;
V_10 = V_7 -> V_14 ;
break;
case 2 :
default:
V_10 = - V_15 ;
}
F_5 ( & V_7 -> V_11 -> V_12 -> V_13 ) ;
return V_10 ;
}
static T_2 F_6 ( struct V_7 * V_7 , char T_3 * V_16 , T_4 V_17 ,
T_1 * V_18 )
{
struct V_1 * V_2 = V_7 -> V_19 ;
struct V_20 * V_4 = V_2 -> V_4 ;
T_2 V_10 = 0 ;
unsigned V_21 ;
T_1 V_22 ;
int V_23 ;
V_22 = * V_18 ;
F_7 ( V_4 ) ;
if ( ! F_1 ( V_2 ) ) {
V_10 = - V_24 ;
goto V_25;
} else if ( V_22 < 0 ) {
V_10 = - V_15 ;
goto V_25;
}
if ( V_22 < sizeof( struct V_26 ) ) {
struct V_26 V_27 ;
memcpy ( & V_27 , & V_4 -> V_28 , sizeof( V_4 -> V_28 ) ) ;
F_8 ( & V_27 . V_29 ) ;
F_8 ( & V_27 . V_30 ) ;
F_8 ( & V_27 . V_31 ) ;
F_8 ( & V_27 . V_32 ) ;
V_21 = sizeof( struct V_26 ) - V_22 ;
if ( V_21 > V_17 )
V_21 = V_17 ;
if ( F_9 ( V_16 , ( ( char * ) & V_27 ) + V_22 , V_21 ) ) {
V_10 = - V_33 ;
goto V_25;
}
* V_18 += V_21 ;
V_16 += V_21 ;
V_17 -= V_21 ;
V_10 += V_21 ;
}
V_22 = sizeof( struct V_26 ) ;
for ( V_23 = 0 ; V_17 && V_23 < V_4 -> V_28 . V_34 ; V_23 ++ ) {
struct V_35 * V_36 =
(struct V_35 * ) V_4 -> V_37 [ V_23 ] ;
unsigned int V_38 = F_10 ( V_36 -> V_39 ) ;
if ( * V_18 < V_22 + V_38 ) {
unsigned V_40 =
F_10 ( V_4 -> V_36 [ V_23 ] . V_41 . V_39 ) ;
V_21 = V_38 - ( * V_18 - V_22 ) ;
if ( V_21 > V_17 )
V_21 = V_17 ;
if ( V_40 > ( * V_18 - V_22 ) ) {
V_40 -= ( * V_18 - V_22 ) ;
if ( F_9 ( V_16 ,
V_4 -> V_37 [ V_23 ] + ( * V_18 - V_22 ) ,
F_11 ( V_21 , V_40 ) ) ) {
V_10 = - V_33 ;
goto V_25;
}
}
* V_18 += V_21 ;
V_16 += V_21 ;
V_17 -= V_21 ;
V_10 += V_21 ;
}
V_22 += V_38 ;
}
V_25:
F_12 ( V_4 ) ;
return V_10 ;
}
static struct V_42 * F_13 ( unsigned int V_43 )
{
struct V_42 * V_44 ;
V_44 = F_14 ( sizeof( struct V_42 ) , V_45 ) ;
if ( ! V_44 )
return NULL ;
V_44 -> V_46 = F_15 ( V_43 , V_45 ) ;
if ( ! V_44 -> V_46 ) {
F_16 ( V_44 ) ;
return NULL ;
}
return V_44 ;
}
static void F_17 ( struct V_42 * V_44 )
{
F_18 ( V_44 -> V_47 ) ;
F_16 ( V_44 -> V_46 -> V_48 ) ;
F_16 ( V_44 -> V_46 -> V_49 ) ;
F_19 ( V_44 -> V_46 ) ;
F_16 ( V_44 ) ;
}
static void F_20 ( struct V_42 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_2 ;
unsigned long V_50 ;
F_21 ( & V_2 -> V_51 , V_50 ) ;
F_22 ( & V_44 -> V_52 , & V_2 -> V_53 ) ;
F_23 ( & V_2 -> V_51 , V_50 ) ;
}
static void F_24 ( struct V_42 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_2 ;
unsigned long V_50 ;
F_21 ( & V_2 -> V_51 , V_50 ) ;
F_25 ( & V_44 -> V_52 ) ;
F_23 ( & V_2 -> V_51 , V_50 ) ;
}
static struct V_42 * F_26 ( struct V_1 * V_2 )
{
unsigned long V_50 ;
struct V_42 * V_44 = NULL ;
F_21 ( & V_2 -> V_51 , V_50 ) ;
if ( ! F_2 ( & V_2 -> V_54 ) ) {
V_44 = F_27 ( V_2 -> V_54 . V_55 , struct V_42 ,
V_52 ) ;
F_25 ( & V_44 -> V_52 ) ;
}
F_23 ( & V_2 -> V_51 , V_50 ) ;
return V_44 ;
}
static struct V_42 * F_28 ( struct V_1 * V_2 ,
void T_3 * V_56 )
{
unsigned long V_50 ;
struct V_42 * V_44 ;
F_21 ( & V_2 -> V_51 , V_50 ) ;
F_29 (as, &ps->async_pending, asynclist)
if ( V_44 -> V_56 == V_56 ) {
F_25 ( & V_44 -> V_52 ) ;
F_23 ( & V_2 -> V_51 , V_50 ) ;
return V_44 ;
}
F_23 ( & V_2 -> V_51 , V_50 ) ;
return NULL ;
}
static void F_30 ( struct V_20 * V_57 ,
void T_3 * V_56 , int V_58 , unsigned V_38 ,
int V_59 , enum V_60 V_61 ,
unsigned char * V_62 , unsigned V_63 )
{
static const char * V_64 [] = { L_1 , L_2 , L_3 , L_4 } ;
static const char * V_65 [] = { L_5 , L_6 } ;
int V_66 ;
const char * V_67 , * V_68 ;
if ( ! V_69 )
return;
V_66 = F_31 ( V_58 ) ;
V_67 = V_64 [ F_32 ( V_58 ) ] ;
V_68 = V_65 [ ! ! F_33 ( V_58 ) ] ;
if ( V_56 ) {
if ( V_61 == V_70 )
F_34 ( & V_57 -> V_4 , L_7
L_8 ,
V_56 , V_66 , V_67 , V_68 , V_38 ) ;
else
F_34 ( & V_57 -> V_4 , L_7
L_9 ,
V_56 , V_66 , V_67 , V_68 , V_38 ,
V_59 ) ;
} else {
if ( V_61 == V_70 )
F_34 ( & V_57 -> V_4 , L_10
L_11 ,
V_66 , V_67 , V_68 , V_38 , V_59 ) ;
else
F_34 ( & V_57 -> V_4 , L_12
L_13 ,
V_66 , V_67 , V_68 , V_38 , V_59 ) ;
}
if ( V_62 && V_63 > 0 ) {
F_35 ( V_71 , L_14 , V_72 , 32 , 1 ,
V_62 , V_63 , 1 ) ;
}
}
static void F_36 ( struct V_1 * V_2 , unsigned V_73 )
__releases( V_2 -> V_51 )
__acquires( V_2 -> V_51 )
{
struct V_42 * V_44 ;
F_29 (as, &ps->async_pending, asynclist) {
if ( V_44 -> V_73 == V_73 ) {
if ( V_44 -> V_74 != V_75 )
goto V_76;
V_44 -> V_74 = V_77 ;
V_44 -> V_73 = 0 ;
}
}
V_2 -> V_78 |= ( 1 << V_73 ) ;
V_76:
F_29 (as, &ps->async_pending, asynclist) {
if ( V_44 -> V_74 == V_77 ) {
V_44 -> V_74 = 0 ;
F_37 ( & V_2 -> V_51 ) ;
F_38 ( V_44 -> V_46 ) ;
F_39 ( & V_2 -> V_51 ) ;
goto V_76;
}
}
}
static void V_54 ( struct V_46 * V_46 )
{
struct V_42 * V_44 = V_46 -> V_79 ;
struct V_1 * V_2 = V_44 -> V_2 ;
struct V_80 V_81 ;
struct V_47 * V_47 = NULL ;
T_5 V_82 = 0 ;
T_5 V_83 = 0 ;
T_6 V_84 = 0 ;
int V_85 ;
F_39 ( & V_2 -> V_51 ) ;
F_40 ( & V_44 -> V_52 , & V_2 -> V_54 ) ;
V_44 -> V_86 = V_46 -> V_86 ;
V_85 = V_44 -> V_85 ;
if ( V_85 ) {
V_81 . V_87 = V_44 -> V_85 ;
V_81 . V_88 = V_44 -> V_86 ;
V_81 . V_89 = V_90 ;
V_81 . V_91 = V_44 -> V_56 ;
V_47 = V_44 -> V_47 ;
V_82 = V_44 -> V_82 ;
V_83 = V_44 -> V_83 ;
V_84 = V_44 -> V_84 ;
}
F_41 ( & V_46 -> V_4 -> V_4 , L_15 ) ;
F_30 ( V_46 -> V_4 , V_44 -> V_56 , V_46 -> V_58 , V_46 -> V_92 ,
V_44 -> V_86 , V_93 ,
( ( V_46 -> V_94 & V_95 ) == V_96 ) ?
NULL : V_46 -> V_48 , V_46 -> V_92 ) ;
if ( V_44 -> V_86 < 0 && V_44 -> V_73 && V_44 -> V_86 != - V_97 &&
V_44 -> V_86 != - V_98 )
F_36 ( V_2 , V_44 -> V_73 ) ;
F_37 ( & V_2 -> V_51 ) ;
if ( V_85 )
F_42 ( V_81 . V_87 , & V_81 , V_47 , V_82 ,
V_83 , V_84 ) ;
F_43 ( & V_2 -> V_99 ) ;
}
static void F_44 ( struct V_1 * V_2 , struct V_100 * V_3 )
{
struct V_42 * V_44 ;
unsigned long V_50 ;
F_21 ( & V_2 -> V_51 , V_50 ) ;
while ( ! F_2 ( V_3 ) ) {
V_44 = F_27 ( V_3 -> V_55 , struct V_42 , V_52 ) ;
F_25 ( & V_44 -> V_52 ) ;
F_23 ( & V_2 -> V_51 , V_50 ) ;
F_45 ( V_44 -> V_46 ) ;
F_21 ( & V_2 -> V_51 , V_50 ) ;
}
F_23 ( & V_2 -> V_51 , V_50 ) ;
}
static void F_46 ( struct V_1 * V_2 ,
unsigned int V_101 )
{
struct V_100 * V_102 , * V_103 , V_104 ;
unsigned long V_50 ;
F_47 ( & V_104 ) ;
F_21 ( & V_2 -> V_51 , V_50 ) ;
F_48 (p, q, &ps->async_pending)
if ( V_101 == F_27 ( V_102 , struct V_42 , V_52 ) -> V_101 )
F_40 ( V_102 , & V_104 ) ;
F_23 ( & V_2 -> V_51 , V_50 ) ;
F_44 ( V_2 , & V_104 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_44 ( V_2 , & V_2 -> V_53 ) ;
}
static int F_50 ( struct V_105 * V_106 ,
const struct V_107 * V_108 )
{
return - V_24 ;
}
static void F_51 ( struct V_105 * V_106 )
{
struct V_1 * V_2 = F_52 ( V_106 ) ;
unsigned int V_101 = V_106 -> V_109 -> V_41 . V_110 ;
if ( ! V_2 )
return;
if ( F_53 ( V_101 < 8 * sizeof( V_2 -> V_111 ) ) )
F_54 ( V_101 , & V_2 -> V_111 ) ;
else
F_55 ( & V_106 -> V_4 , L_16 ,
V_101 ) ;
F_56 ( V_106 , NULL ) ;
F_46 ( V_2 , V_101 ) ;
}
static int F_57 ( struct V_105 * V_106 , T_7 V_112 )
{
return 0 ;
}
static int F_58 ( struct V_105 * V_106 )
{
return 0 ;
}
static int F_59 ( struct V_1 * V_2 , unsigned int V_101 )
{
struct V_20 * V_4 = V_2 -> V_4 ;
struct V_105 * V_106 ;
int V_25 ;
if ( V_101 >= 8 * sizeof( V_2 -> V_111 ) )
return - V_15 ;
if ( F_60 ( V_101 , & V_2 -> V_111 ) )
return 0 ;
V_106 = F_61 ( V_4 , V_101 ) ;
if ( ! V_106 )
V_25 = - V_98 ;
else
V_25 = F_62 ( & V_113 , V_106 , V_2 ) ;
if ( V_25 == 0 )
F_63 ( V_101 , & V_2 -> V_111 ) ;
return V_25 ;
}
static int F_64 ( struct V_1 * V_2 , unsigned int V_101 )
{
struct V_20 * V_4 ;
struct V_105 * V_106 ;
int V_25 ;
V_25 = - V_15 ;
if ( V_101 >= 8 * sizeof( V_2 -> V_111 ) )
return V_25 ;
V_4 = V_2 -> V_4 ;
V_106 = F_61 ( V_4 , V_101 ) ;
if ( ! V_106 )
V_25 = - V_98 ;
else if ( F_65 ( V_101 , & V_2 -> V_111 ) ) {
F_66 ( & V_113 , V_106 ) ;
V_25 = 0 ;
}
return V_25 ;
}
static int F_67 ( struct V_1 * V_2 , unsigned int V_101 )
{
if ( V_2 -> V_4 -> V_5 != V_114 )
return - V_115 ;
if ( V_101 >= 8 * sizeof( V_2 -> V_111 ) )
return - V_15 ;
if ( F_60 ( V_101 , & V_2 -> V_111 ) )
return 0 ;
F_55 ( & V_2 -> V_4 -> V_4 , L_17
L_18 , F_68 ( V_116 ) ,
V_116 -> V_117 , V_101 ) ;
return F_59 ( V_2 , V_101 ) ;
}
static int F_69 ( struct V_20 * V_4 , unsigned int V_66 )
{
unsigned int V_23 , V_118 , V_119 ;
struct V_105 * V_106 ;
struct V_120 * V_121 ;
struct V_122 * V_123 ;
if ( V_66 & ~ ( V_124 | 0xf ) )
return - V_15 ;
if ( ! V_4 -> V_125 )
return - V_126 ;
for ( V_23 = 0 ; V_23 < V_4 -> V_125 -> V_41 . V_127 ; V_23 ++ ) {
V_106 = V_4 -> V_125 -> V_128 [ V_23 ] ;
for ( V_118 = 0 ; V_118 < V_106 -> V_129 ; V_118 ++ ) {
V_121 = & V_106 -> V_109 [ V_118 ] ;
for ( V_119 = 0 ; V_119 < V_121 -> V_41 . V_130 ; V_119 ++ ) {
V_123 = & V_121 -> V_131 [ V_119 ] . V_41 ;
if ( V_123 -> V_132 == V_66 )
return V_121 -> V_41 . V_110 ;
}
}
}
return - V_98 ;
}
static int F_70 ( struct V_1 * V_2 , unsigned int V_133 ,
unsigned int V_134 )
{
int V_10 = 0 ;
if ( V_2 -> V_4 -> V_5 != V_135
&& V_2 -> V_4 -> V_5 != V_136
&& V_2 -> V_4 -> V_5 != V_114 )
return - V_115 ;
if ( V_137 == ( V_138 & V_133 ) )
return 0 ;
V_134 &= 0xff ;
switch ( V_133 & V_139 ) {
case V_140 :
V_10 = F_69 ( V_2 -> V_4 , V_134 ) ;
if ( V_10 >= 0 )
V_10 = F_67 ( V_2 , V_10 ) ;
break;
case V_141 :
V_10 = F_67 ( V_2 , V_134 ) ;
break;
}
return V_10 ;
}
static int F_71 ( struct V_142 * V_4 , void * V_62 )
{
return V_4 -> V_143 == ( V_144 ) ( unsigned long ) V_62 ;
}
static struct V_20 * F_72 ( V_144 V_143 )
{
struct V_142 * V_4 ;
V_4 = F_73 ( & V_145 , NULL ,
( void * ) ( unsigned long ) V_143 , F_71 ) ;
if ( ! V_4 )
return NULL ;
return F_74 ( V_4 , struct V_20 , V_4 ) ;
}
static int F_75 ( struct V_146 * V_146 , struct V_7 * V_7 )
{
struct V_20 * V_4 = NULL ;
struct V_1 * V_2 ;
const struct V_147 * V_147 = F_76 () ;
int V_10 ;
V_10 = - V_148 ;
V_2 = F_77 ( sizeof( struct V_1 ) , V_45 ) ;
if ( ! V_2 )
goto V_149;
V_10 = - V_24 ;
F_4 ( & V_150 ) ;
if ( F_78 ( V_146 ) == V_151 )
V_4 = F_72 ( V_146 -> V_152 ) ;
#ifdef F_79
if ( ! V_4 ) {
V_4 = V_146 -> V_153 ;
if ( V_4 && V_4 -> V_154 &&
V_4 -> V_154 -> V_12 == V_146 )
F_80 ( V_4 ) ;
else
V_4 = NULL ;
}
#endif
F_5 ( & V_150 ) ;
if ( ! V_4 )
goto V_149;
F_7 ( V_4 ) ;
if ( V_4 -> V_5 == V_6 )
goto V_155;
V_10 = F_81 ( V_4 ) ;
if ( V_10 )
goto V_155;
V_2 -> V_4 = V_4 ;
V_2 -> V_7 = V_7 ;
F_82 ( & V_2 -> V_51 ) ;
F_47 ( & V_2 -> V_3 ) ;
F_47 ( & V_2 -> V_53 ) ;
F_47 ( & V_2 -> V_54 ) ;
F_83 ( & V_2 -> V_99 ) ;
V_2 -> V_156 = 0 ;
V_2 -> V_157 = F_84 ( F_85 ( V_116 ) ) ;
V_2 -> V_158 = V_147 -> V_82 ;
V_2 -> V_159 = V_147 -> V_83 ;
V_2 -> V_160 = NULL ;
V_2 -> V_111 = 0 ;
F_86 ( V_116 , & V_2 -> V_84 ) ;
F_87 () ;
F_22 ( & V_2 -> V_3 , & V_4 -> V_161 ) ;
V_7 -> V_19 = V_2 ;
F_12 ( V_4 ) ;
F_41 ( & V_4 -> V_4 , L_19 , F_68 ( V_116 ) ,
V_116 -> V_117 ) ;
return V_10 ;
V_155:
F_12 ( V_4 ) ;
F_88 ( V_4 ) ;
V_149:
F_16 ( V_2 ) ;
return V_10 ;
}
static int F_89 ( struct V_146 * V_146 , struct V_7 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_19 ;
struct V_20 * V_4 = V_2 -> V_4 ;
unsigned int V_101 ;
struct V_42 * V_44 ;
F_7 ( V_4 ) ;
F_90 ( V_4 , V_2 ) ;
F_25 ( & V_2 -> V_3 ) ;
for ( V_101 = 0 ; V_2 -> V_111 && V_101 < 8 * sizeof( V_2 -> V_111 ) ;
V_101 ++ ) {
if ( F_60 ( V_101 , & V_2 -> V_111 ) )
F_64 ( V_2 , V_101 ) ;
}
F_49 ( V_2 ) ;
F_91 ( V_4 ) ;
F_12 ( V_4 ) ;
F_88 ( V_4 ) ;
F_18 ( V_2 -> V_157 ) ;
V_44 = F_26 ( V_2 ) ;
while ( V_44 ) {
F_17 ( V_44 ) ;
V_44 = F_26 ( V_2 ) ;
}
F_16 ( V_2 ) ;
return 0 ;
}
static int F_92 ( struct V_1 * V_2 , void T_3 * V_162 )
{
struct V_20 * V_4 = V_2 -> V_4 ;
struct V_163 V_164 ;
unsigned int V_165 ;
unsigned char * V_166 ;
unsigned V_167 ;
int V_23 , V_58 , V_10 ;
if ( F_93 ( & V_164 , V_162 , sizeof( V_164 ) ) )
return - V_33 ;
V_10 = F_70 ( V_2 , V_164 . V_168 , V_164 . V_169 ) ;
if ( V_10 )
return V_10 ;
V_167 = V_164 . V_167 ;
if ( V_167 > V_170 )
return - V_15 ;
V_166 = ( unsigned char * ) F_94 ( V_45 ) ;
if ( ! V_166 )
return - V_148 ;
V_165 = V_164 . V_171 ;
F_41 ( & V_4 -> V_4 , L_20
L_21
L_22 ,
V_164 . V_168 , V_164 . V_172 ,
F_95 ( & V_164 . V_173 ) ,
F_95 ( & V_164 . V_169 ) ,
F_95 ( & V_164 . V_167 ) ) ;
if ( V_164 . V_168 & 0x80 ) {
if ( V_164 . V_167 && ! F_96 ( V_174 , V_164 . V_62 ,
V_164 . V_167 ) ) {
F_97 ( ( unsigned long ) V_166 ) ;
return - V_15 ;
}
V_58 = F_98 ( V_4 , 0 ) ;
F_30 ( V_4 , NULL , V_58 , V_164 . V_167 , V_165 , V_70 , NULL , 0 ) ;
F_12 ( V_4 ) ;
V_23 = F_99 ( V_4 , V_58 , V_164 . V_172 ,
V_164 . V_168 , V_164 . V_173 , V_164 . V_169 ,
V_166 , V_164 . V_167 , V_165 ) ;
F_7 ( V_4 ) ;
F_30 ( V_4 , NULL , V_58 , F_100 ( V_23 , 0 ) , F_11 ( V_23 , 0 ) , V_93 ,
V_166 , F_100 ( V_23 , 0 ) ) ;
if ( ( V_23 > 0 ) && V_164 . V_167 ) {
if ( F_9 ( V_164 . V_62 , V_166 , V_23 ) ) {
F_97 ( ( unsigned long ) V_166 ) ;
return - V_33 ;
}
}
} else {
if ( V_164 . V_167 ) {
if ( F_93 ( V_166 , V_164 . V_62 , V_164 . V_167 ) ) {
F_97 ( ( unsigned long ) V_166 ) ;
return - V_33 ;
}
}
V_58 = F_101 ( V_4 , 0 ) ;
F_30 ( V_4 , NULL , V_58 , V_164 . V_167 , V_165 , V_70 ,
V_166 , V_164 . V_167 ) ;
F_12 ( V_4 ) ;
V_23 = F_99 ( V_4 , F_101 ( V_4 , 0 ) , V_164 . V_172 ,
V_164 . V_168 , V_164 . V_173 , V_164 . V_169 ,
V_166 , V_164 . V_167 , V_165 ) ;
F_7 ( V_4 ) ;
F_30 ( V_4 , NULL , V_58 , F_100 ( V_23 , 0 ) , F_11 ( V_23 , 0 ) , V_93 , NULL , 0 ) ;
}
F_97 ( ( unsigned long ) V_166 ) ;
if ( V_23 < 0 && V_23 != - V_175 ) {
F_102 ( V_71 , & V_4 -> V_4 , L_23
L_24 ,
V_116 -> V_117 , V_164 . V_168 , V_164 . V_172 ,
V_164 . V_167 , V_23 ) ;
}
return V_23 ;
}
static int F_103 ( struct V_1 * V_2 , void T_3 * V_162 )
{
struct V_20 * V_4 = V_2 -> V_4 ;
struct V_176 V_177 ;
unsigned int V_165 , V_178 , V_58 ;
int V_179 ;
unsigned char * V_166 ;
int V_23 , V_10 ;
if ( F_93 ( & V_177 , V_162 , sizeof( V_177 ) ) )
return - V_33 ;
V_10 = F_69 ( V_2 -> V_4 , V_177 . V_66 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_67 ( V_2 , V_10 ) ;
if ( V_10 )
return V_10 ;
if ( V_177 . V_66 & V_124 )
V_58 = F_104 ( V_4 , V_177 . V_66 & 0x7f ) ;
else
V_58 = F_105 ( V_4 , V_177 . V_66 & 0x7f ) ;
if ( ! F_106 ( V_4 , V_58 , ! ( V_177 . V_66 & V_124 ) ) )
return - V_15 ;
V_178 = V_177 . V_21 ;
if ( V_178 > V_180 )
return - V_15 ;
if ( ! ( V_166 = F_77 ( V_178 , V_45 ) ) )
return - V_148 ;
V_165 = V_177 . V_171 ;
if ( V_177 . V_66 & 0x80 ) {
if ( V_178 && ! F_96 ( V_174 , V_177 . V_62 , V_178 ) ) {
F_16 ( V_166 ) ;
return - V_15 ;
}
F_30 ( V_4 , NULL , V_58 , V_178 , V_165 , V_70 , NULL , 0 ) ;
F_12 ( V_4 ) ;
V_23 = F_107 ( V_4 , V_58 , V_166 , V_178 , & V_179 , V_165 ) ;
F_7 ( V_4 ) ;
F_30 ( V_4 , NULL , V_58 , V_179 , V_23 , V_93 , V_166 , V_179 ) ;
if ( ! V_23 && V_179 ) {
if ( F_9 ( V_177 . V_62 , V_166 , V_179 ) ) {
F_16 ( V_166 ) ;
return - V_33 ;
}
}
} else {
if ( V_178 ) {
if ( F_93 ( V_166 , V_177 . V_62 , V_178 ) ) {
F_16 ( V_166 ) ;
return - V_33 ;
}
}
F_30 ( V_4 , NULL , V_58 , V_178 , V_165 , V_70 , V_166 , V_178 ) ;
F_12 ( V_4 ) ;
V_23 = F_107 ( V_4 , V_58 , V_166 , V_178 , & V_179 , V_165 ) ;
F_7 ( V_4 ) ;
F_30 ( V_4 , NULL , V_58 , V_179 , V_23 , V_93 , NULL , 0 ) ;
}
F_16 ( V_166 ) ;
if ( V_23 < 0 )
return V_23 ;
return V_179 ;
}
static int F_108 ( struct V_1 * V_2 , void T_3 * V_162 )
{
unsigned int V_66 ;
int V_10 ;
if ( F_109 ( V_66 , ( unsigned int T_3 * ) V_162 ) )
return - V_33 ;
V_10 = F_69 ( V_2 -> V_4 , V_66 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_67 ( V_2 , V_10 ) ;
if ( V_10 )
return V_10 ;
F_110 ( V_2 -> V_4 , V_66 ) ;
return 0 ;
}
static int F_111 ( struct V_1 * V_2 , void T_3 * V_162 )
{
unsigned int V_66 ;
int V_58 ;
int V_10 ;
if ( F_109 ( V_66 , ( unsigned int T_3 * ) V_162 ) )
return - V_33 ;
V_10 = F_69 ( V_2 -> V_4 , V_66 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_67 ( V_2 , V_10 ) ;
if ( V_10 )
return V_10 ;
if ( V_66 & V_124 )
V_58 = F_104 ( V_2 -> V_4 , V_66 & 0x7f ) ;
else
V_58 = F_105 ( V_2 -> V_4 , V_66 & 0x7f ) ;
return F_112 ( V_2 -> V_4 , V_58 ) ;
}
static int F_113 ( struct V_1 * V_2 , void T_3 * V_162 )
{
struct V_181 V_182 ;
struct V_105 * V_106 ;
int V_10 ;
if ( F_93 ( & V_182 , V_162 , sizeof( V_182 ) ) )
return - V_33 ;
V_106 = F_61 ( V_2 -> V_4 , V_182 . V_128 ) ;
if ( ! V_106 || ! V_106 -> V_4 . V_183 )
V_10 = - V_184 ;
else {
strncpy ( V_182 . V_183 , V_106 -> V_4 . V_183 -> V_185 ,
sizeof( V_182 . V_183 ) ) ;
V_10 = ( F_9 ( V_162 , & V_182 , sizeof( V_182 ) ) ? - V_33 : 0 ) ;
}
return V_10 ;
}
static int F_114 ( struct V_1 * V_2 , void T_3 * V_162 )
{
struct V_186 V_187 = {
. V_188 = V_2 -> V_4 -> V_188 ,
. V_189 = V_2 -> V_4 -> V_190 == V_191
} ;
if ( F_9 ( V_162 , & V_187 , sizeof( V_187 ) ) )
return - V_33 ;
return 0 ;
}
static int F_115 ( struct V_1 * V_2 )
{
return F_116 ( V_2 -> V_4 ) ;
}
static int F_117 ( struct V_1 * V_2 , void T_3 * V_162 )
{
struct V_192 V_193 ;
int V_10 ;
if ( F_93 ( & V_193 , V_162 , sizeof( V_193 ) ) )
return - V_33 ;
if ( ( V_10 = F_67 ( V_2 , V_193 . V_128 ) ) )
return V_10 ;
return F_118 ( V_2 -> V_4 , V_193 . V_128 ,
V_193 . V_109 ) ;
}
static int F_119 ( struct V_1 * V_2 , void T_3 * V_162 )
{
int V_194 ;
int V_86 = 0 ;
struct V_195 * V_125 ;
if ( F_109 ( V_194 , ( int T_3 * ) V_162 ) )
return - V_33 ;
V_125 = V_2 -> V_4 -> V_125 ;
if ( V_125 ) {
int V_23 ;
for ( V_23 = 0 ; V_23 < V_125 -> V_41 . V_127 ; ++ V_23 ) {
if ( F_120 ( V_125 -> V_128 [ V_23 ] ) ) {
F_55 ( & V_2 -> V_4 -> V_4 ,
L_25
L_26 ,
V_125 -> V_128 [ V_23 ]
-> V_196
-> V_41 . V_110 ,
V_125 -> V_128 [ V_23 ]
-> V_4 . V_183 -> V_185 ,
V_116 -> V_117 , V_194 ) ;
V_86 = - V_197 ;
break;
}
}
}
if ( V_86 == 0 ) {
if ( V_125 && V_125 -> V_41 . V_198 == V_194 )
V_86 = F_121 ( V_2 -> V_4 ) ;
else
V_86 = F_122 ( V_2 -> V_4 , V_194 ) ;
}
return V_86 ;
}
static int F_123 ( struct V_1 * V_2 , struct V_199 * V_200 ,
struct V_201 T_3 * V_202 ,
void T_3 * V_162 )
{
struct V_201 * V_203 = NULL ;
struct V_204 * V_66 ;
struct V_42 * V_44 ;
struct V_205 * V_206 = NULL ;
const struct V_147 * V_147 = F_76 () ;
unsigned int V_194 , V_207 , V_208 ;
int V_10 , V_101 = - 1 ;
int V_209 ;
if ( V_200 -> V_50 & ~ ( V_210 |
V_211 |
V_212 |
V_213 |
V_214 |
V_215 ) )
return - V_15 ;
if ( V_200 -> V_216 > 0 && ! V_200 -> V_217 )
return - V_15 ;
if ( ! ( V_200 -> type == V_218 &&
( V_200 -> V_131 & ~ V_219 ) == 0 ) ) {
V_101 = F_69 ( V_2 -> V_4 , V_200 -> V_131 ) ;
if ( V_101 < 0 )
return V_101 ;
V_10 = F_67 ( V_2 , V_101 ) ;
if ( V_10 )
return V_10 ;
}
if ( ( V_200 -> V_131 & V_219 ) != 0 ) {
V_209 = 1 ;
V_66 = V_2 -> V_4 -> V_220 [ V_200 -> V_131 & V_221 ] ;
} else {
V_209 = 0 ;
V_66 = V_2 -> V_4 -> V_222 [ V_200 -> V_131 & V_221 ] ;
}
if ( ! V_66 )
return - V_98 ;
switch( V_200 -> type ) {
case V_218 :
if ( ! F_124 ( & V_66 -> V_41 ) )
return - V_15 ;
if ( V_200 -> V_216 < 8 ||
V_200 -> V_216 > ( 8 + V_180 ) )
return - V_15 ;
V_206 = F_77 ( sizeof( struct V_205 ) , V_45 ) ;
if ( ! V_206 )
return - V_148 ;
if ( F_93 ( V_206 , V_200 -> V_217 , 8 ) ) {
F_16 ( V_206 ) ;
return - V_33 ;
}
if ( V_200 -> V_216 < ( F_125 ( & V_206 -> V_167 ) + 8 ) ) {
F_16 ( V_206 ) ;
return - V_15 ;
}
V_10 = F_70 ( V_2 , V_206 -> V_168 ,
F_125 ( & V_206 -> V_169 ) ) ;
if ( V_10 ) {
F_16 ( V_206 ) ;
return V_10 ;
}
V_200 -> V_223 = 0 ;
V_200 -> V_216 = F_125 ( & V_206 -> V_167 ) ;
V_200 -> V_217 += 8 ;
if ( ( V_206 -> V_168 & V_124 ) && V_200 -> V_216 ) {
V_209 = 1 ;
V_200 -> V_131 |= V_124 ;
} else {
V_209 = 0 ;
V_200 -> V_131 &= ~ V_124 ;
}
F_41 ( & V_2 -> V_4 -> V_4 , L_20
L_21
L_22 ,
V_206 -> V_168 , V_206 -> V_172 ,
F_95 ( & V_206 -> V_173 ) ,
F_95 ( & V_206 -> V_169 ) ,
F_95 ( & V_206 -> V_167 ) ) ;
break;
case V_224 :
switch ( F_126 ( & V_66 -> V_41 ) ) {
case V_225 :
case V_226 :
return - V_15 ;
case V_227 :
V_200 -> type = V_228 ;
goto V_229;
}
V_200 -> V_223 = 0 ;
if ( V_200 -> V_216 > V_180 )
return - V_15 ;
break;
case V_228 :
if ( ! F_127 ( & V_66 -> V_41 ) )
return - V_15 ;
V_229:
V_200 -> V_223 = 0 ;
if ( V_200 -> V_216 > V_180 )
return - V_15 ;
break;
case V_230 :
if ( V_200 -> V_223 < 1 ||
V_200 -> V_223 > 128 )
return - V_15 ;
if ( ! F_128 ( & V_66 -> V_41 ) )
return - V_15 ;
V_208 = sizeof( struct V_201 ) *
V_200 -> V_223 ;
if ( ! ( V_203 = F_77 ( V_208 , V_45 ) ) )
return - V_148 ;
if ( F_93 ( V_203 , V_202 , V_208 ) ) {
F_16 ( V_203 ) ;
return - V_33 ;
}
for ( V_207 = V_194 = 0 ; V_194 < V_200 -> V_223 ; V_194 ++ ) {
if ( V_203 [ V_194 ] . V_38 > 8192 ) {
F_16 ( V_203 ) ;
return - V_15 ;
}
V_207 += V_203 [ V_194 ] . V_38 ;
}
if ( V_207 > 196608 ) {
F_16 ( V_203 ) ;
return - V_15 ;
}
V_200 -> V_216 = V_207 ;
break;
default:
return - V_15 ;
}
if ( V_200 -> V_216 > 0 &&
! F_96 ( V_209 ? V_174 : V_231 ,
V_200 -> V_217 , V_200 -> V_216 ) ) {
F_16 ( V_203 ) ;
F_16 ( V_206 ) ;
return - V_33 ;
}
V_44 = F_13 ( V_200 -> V_223 ) ;
if ( ! V_44 ) {
F_16 ( V_203 ) ;
F_16 ( V_206 ) ;
return - V_148 ;
}
if ( V_200 -> V_216 > 0 ) {
V_44 -> V_46 -> V_48 = F_77 ( V_200 -> V_216 ,
V_45 ) ;
if ( ! V_44 -> V_46 -> V_48 ) {
F_16 ( V_203 ) ;
F_16 ( V_206 ) ;
F_17 ( V_44 ) ;
return - V_148 ;
}
if ( V_209 && V_200 -> type == V_230 )
memset ( V_44 -> V_46 -> V_48 , 0 ,
V_200 -> V_216 ) ;
}
V_44 -> V_46 -> V_4 = V_2 -> V_4 ;
V_44 -> V_46 -> V_58 = ( V_200 -> type << 30 ) |
F_129 ( V_2 -> V_4 , V_200 -> V_131 & 0xf ) |
( V_200 -> V_131 & V_124 ) ;
V_194 = ( V_209 ? V_232 : V_233 ) ;
if ( V_200 -> V_50 & V_210 )
V_194 |= V_234 ;
if ( V_200 -> V_50 & V_211 )
V_194 |= V_235 ;
if ( V_200 -> V_50 & V_213 )
V_194 |= V_236 ;
if ( V_200 -> V_50 & V_214 )
V_194 |= V_237 ;
if ( V_200 -> V_50 & V_215 )
V_194 |= V_238 ;
V_44 -> V_46 -> V_94 = V_194 ;
V_44 -> V_46 -> V_239 = V_200 -> V_216 ;
V_44 -> V_46 -> V_49 = ( unsigned char * ) V_206 ;
V_44 -> V_46 -> V_240 = V_200 -> V_240 ;
V_44 -> V_46 -> V_223 = V_200 -> V_223 ;
if ( V_200 -> type == V_230 ||
V_2 -> V_4 -> V_190 == V_241 )
V_44 -> V_46 -> V_242 = 1 << F_11 ( 15 , V_66 -> V_41 . V_243 - 1 ) ;
else
V_44 -> V_46 -> V_242 = V_66 -> V_41 . V_243 ;
V_44 -> V_46 -> V_79 = V_44 ;
V_44 -> V_46 -> V_244 = V_54 ;
for ( V_207 = V_194 = 0 ; V_194 < V_200 -> V_223 ; V_194 ++ ) {
V_44 -> V_46 -> V_202 [ V_194 ] . V_8 = V_207 ;
V_44 -> V_46 -> V_202 [ V_194 ] . V_38 = V_203 [ V_194 ] . V_38 ;
V_207 += V_203 [ V_194 ] . V_38 ;
}
F_16 ( V_203 ) ;
V_44 -> V_2 = V_2 ;
V_44 -> V_56 = V_162 ;
if ( V_209 && V_200 -> V_216 > 0 )
V_44 -> V_245 = V_200 -> V_217 ;
else
V_44 -> V_245 = NULL ;
V_44 -> V_85 = V_200 -> V_85 ;
V_44 -> V_101 = V_101 ;
V_44 -> V_47 = F_84 ( F_85 ( V_116 ) ) ;
V_44 -> V_82 = V_147 -> V_82 ;
V_44 -> V_83 = V_147 -> V_83 ;
F_86 ( V_116 , & V_44 -> V_84 ) ;
if ( ! V_209 && V_200 -> V_216 > 0 ) {
if ( F_93 ( V_44 -> V_46 -> V_48 , V_200 -> V_217 ,
V_200 -> V_216 ) ) {
F_17 ( V_44 ) ;
return - V_33 ;
}
}
F_30 ( V_2 -> V_4 , V_44 -> V_56 , V_44 -> V_46 -> V_58 ,
V_44 -> V_46 -> V_239 , 0 , V_70 ,
V_209 ? NULL : V_44 -> V_46 -> V_48 ,
V_200 -> V_216 ) ;
F_20 ( V_44 ) ;
if ( F_130 ( & V_66 -> V_41 ) ) {
F_131 ( & V_2 -> V_51 ) ;
V_44 -> V_73 = F_132 ( & V_66 -> V_41 ) |
( ( V_66 -> V_41 . V_132 & V_219 )
>> 3 ) ;
if ( V_200 -> V_50 & V_212 )
V_44 -> V_74 = V_75 ;
else
V_2 -> V_78 &= ~ ( 1 << V_44 -> V_73 ) ;
if ( V_2 -> V_78 & ( 1 << V_44 -> V_73 ) )
V_10 = - V_246 ;
else
V_10 = F_133 ( V_44 -> V_46 , V_247 ) ;
F_134 ( & V_2 -> V_51 ) ;
} else {
V_10 = F_133 ( V_44 -> V_46 , V_45 ) ;
}
if ( V_10 ) {
F_102 ( V_71 , & V_2 -> V_4 -> V_4 ,
L_27 , V_10 ) ;
F_30 ( V_2 -> V_4 , V_44 -> V_56 , V_44 -> V_46 -> V_58 ,
0 , V_10 , V_93 , NULL , 0 ) ;
F_24 ( V_44 ) ;
F_17 ( V_44 ) ;
return V_10 ;
}
return 0 ;
}
static int F_135 ( struct V_1 * V_2 , void T_3 * V_162 )
{
struct V_199 V_200 ;
if ( F_93 ( & V_200 , V_162 , sizeof( V_200 ) ) )
return - V_33 ;
return F_123 ( V_2 , & V_200 ,
( ( (struct V_199 T_3 * ) V_162 ) -> V_202 ) ,
V_162 ) ;
}
static int F_136 ( struct V_1 * V_2 , void T_3 * V_162 )
{
struct V_42 * V_44 ;
V_44 = F_28 ( V_2 , V_162 ) ;
if ( ! V_44 )
return - V_15 ;
F_45 ( V_44 -> V_46 ) ;
return 0 ;
}
static int F_137 ( struct V_42 * V_44 , void T_3 * T_3 * V_162 )
{
struct V_46 * V_46 = V_44 -> V_46 ;
struct V_199 T_3 * V_56 = V_44 -> V_56 ;
void T_3 * V_248 = V_44 -> V_56 ;
unsigned int V_23 ;
if ( V_44 -> V_245 && V_46 -> V_92 ) {
if ( V_46 -> V_223 > 0 )
V_23 = V_46 -> V_239 ;
else
V_23 = V_46 -> V_92 ;
if ( F_9 ( V_44 -> V_245 , V_46 -> V_48 , V_23 ) )
goto V_249;
}
if ( F_138 ( V_44 -> V_86 , & V_56 -> V_86 ) )
goto V_249;
if ( F_138 ( V_46 -> V_92 , & V_56 -> V_92 ) )
goto V_249;
if ( F_138 ( V_46 -> V_250 , & V_56 -> V_250 ) )
goto V_249;
if ( F_128 ( & V_46 -> V_66 -> V_41 ) ) {
for ( V_23 = 0 ; V_23 < V_46 -> V_223 ; V_23 ++ ) {
if ( F_138 ( V_46 -> V_202 [ V_23 ] . V_92 ,
& V_56 -> V_202 [ V_23 ] . V_92 ) )
goto V_249;
if ( F_138 ( V_46 -> V_202 [ V_23 ] . V_86 ,
& V_56 -> V_202 [ V_23 ] . V_86 ) )
goto V_249;
}
}
if ( F_138 ( V_248 , ( void T_3 * T_3 * ) V_162 ) )
return - V_33 ;
return 0 ;
V_249:
return - V_33 ;
}
static struct V_42 * F_139 ( struct V_1 * V_2 )
{
F_140 ( V_99 , V_116 ) ;
struct V_42 * V_44 = NULL ;
struct V_20 * V_4 = V_2 -> V_4 ;
F_141 ( & V_2 -> V_99 , & V_99 ) ;
for (; ; ) {
F_142 ( V_251 ) ;
V_44 = F_26 ( V_2 ) ;
if ( V_44 )
break;
if ( F_143 ( V_116 ) )
break;
F_12 ( V_4 ) ;
F_144 () ;
F_7 ( V_4 ) ;
}
F_145 ( & V_2 -> V_99 , & V_99 ) ;
F_146 ( V_252 ) ;
return V_44 ;
}
static int F_147 ( struct V_1 * V_2 , void T_3 * V_162 )
{
struct V_42 * V_44 = F_139 ( V_2 ) ;
if ( V_44 ) {
int V_253 = F_137 ( V_44 , ( void T_3 * T_3 * ) V_162 ) ;
F_17 ( V_44 ) ;
return V_253 ;
}
if ( F_143 ( V_116 ) )
return - V_254 ;
return - V_255 ;
}
static int F_148 ( struct V_1 * V_2 , void T_3 * V_162 )
{
int V_253 ;
struct V_42 * V_44 ;
V_44 = F_26 ( V_2 ) ;
V_253 = - V_256 ;
if ( V_44 ) {
V_253 = F_137 ( V_44 , ( void T_3 * T_3 * ) V_162 ) ;
F_17 ( V_44 ) ;
}
return V_253 ;
}
static int F_149 ( struct V_1 * V_2 ,
struct V_257 T_3 * V_258 )
{
struct V_163 T_3 * V_102 ;
T_8 V_259 ;
V_102 = F_150 ( sizeof( * V_102 ) ) ;
if ( F_151 ( V_102 , V_258 , ( sizeof( * V_258 ) - sizeof( V_260 ) ) ) ||
F_109 ( V_259 , & V_258 -> V_62 ) ||
F_138 ( F_152 ( V_259 ) , & V_102 -> V_62 ) )
return - V_33 ;
return F_92 ( V_2 , V_102 ) ;
}
static int F_153 ( struct V_1 * V_2 ,
struct V_261 T_3 * V_258 )
{
struct V_176 T_3 * V_102 ;
T_9 V_262 ;
V_260 V_248 ;
V_102 = F_150 ( sizeof( * V_102 ) ) ;
if ( F_109 ( V_262 , & V_258 -> V_66 ) || F_138 ( V_262 , & V_102 -> V_66 ) ||
F_109 ( V_262 , & V_258 -> V_21 ) || F_138 ( V_262 , & V_102 -> V_21 ) ||
F_109 ( V_262 , & V_258 -> V_171 ) || F_138 ( V_262 , & V_102 -> V_171 ) ||
F_109 ( V_248 , & V_258 -> V_62 ) || F_138 ( F_152 ( V_248 ) , & V_102 -> V_62 ) )
return - V_33 ;
return F_103 ( V_2 , V_102 ) ;
}
static int F_154 ( struct V_1 * V_2 , void T_3 * V_162 )
{
struct V_263 V_264 ;
if ( F_93 ( & V_264 , V_162 , sizeof( V_264 ) ) )
return - V_33 ;
V_2 -> V_156 = V_264 . V_85 ;
V_2 -> V_160 = F_152 ( V_264 . V_79 ) ;
return 0 ;
}
static int F_155 ( struct V_199 * V_265 ,
struct V_266 T_3 * V_200 )
{
T_8 V_267 ;
if ( ! F_96 ( V_231 , V_200 , sizeof( * V_200 ) ) ||
F_156 ( V_265 -> type , & V_200 -> type ) ||
F_156 ( V_265 -> V_131 , & V_200 -> V_131 ) ||
F_156 ( V_265 -> V_86 , & V_200 -> V_86 ) ||
F_156 ( V_265 -> V_50 , & V_200 -> V_50 ) ||
F_156 ( V_265 -> V_216 , & V_200 -> V_216 ) ||
F_156 ( V_265 -> V_92 , & V_200 -> V_92 ) ||
F_156 ( V_265 -> V_240 , & V_200 -> V_240 ) ||
F_156 ( V_265 -> V_223 , & V_200 -> V_223 ) ||
F_156 ( V_265 -> V_250 , & V_200 -> V_250 ) ||
F_156 ( V_265 -> V_85 , & V_200 -> V_85 ) )
return - V_33 ;
if ( F_156 ( V_267 , & V_200 -> V_217 ) )
return - V_33 ;
V_265 -> V_217 = F_152 ( V_267 ) ;
if ( F_156 ( V_267 , & V_200 -> V_268 ) )
return - V_33 ;
V_265 -> V_268 = F_152 ( V_267 ) ;
return 0 ;
}
static int F_157 ( struct V_1 * V_2 , void T_3 * V_162 )
{
struct V_199 V_200 ;
if ( F_155 ( & V_200 , (struct V_266 T_3 * ) V_162 ) )
return - V_33 ;
return F_123 ( V_2 , & V_200 ,
( (struct V_266 T_3 * ) V_162 ) -> V_202 ,
V_162 ) ;
}
static int F_158 ( struct V_42 * V_44 , void T_3 * T_3 * V_162 )
{
struct V_46 * V_46 = V_44 -> V_46 ;
struct V_266 T_3 * V_56 = V_44 -> V_56 ;
void T_3 * V_248 = V_44 -> V_56 ;
unsigned int V_23 ;
if ( V_44 -> V_245 && V_46 -> V_92 )
if ( F_9 ( V_44 -> V_245 , V_46 -> V_48 ,
V_46 -> V_92 ) )
return - V_33 ;
if ( F_138 ( V_44 -> V_86 , & V_56 -> V_86 ) )
return - V_33 ;
if ( F_138 ( V_46 -> V_92 , & V_56 -> V_92 ) )
return - V_33 ;
if ( F_138 ( V_46 -> V_250 , & V_56 -> V_250 ) )
return - V_33 ;
if ( F_128 ( & V_46 -> V_66 -> V_41 ) ) {
for ( V_23 = 0 ; V_23 < V_46 -> V_223 ; V_23 ++ ) {
if ( F_138 ( V_46 -> V_202 [ V_23 ] . V_92 ,
& V_56 -> V_202 [ V_23 ] . V_92 ) )
return - V_33 ;
if ( F_138 ( V_46 -> V_202 [ V_23 ] . V_86 ,
& V_56 -> V_202 [ V_23 ] . V_86 ) )
return - V_33 ;
}
}
if ( F_138 ( F_159 ( V_248 ) , ( T_6 T_3 * ) V_162 ) )
return - V_33 ;
return 0 ;
}
static int F_160 ( struct V_1 * V_2 , void T_3 * V_162 )
{
struct V_42 * V_44 = F_139 ( V_2 ) ;
if ( V_44 ) {
int V_253 = F_158 ( V_44 , ( void T_3 * T_3 * ) V_162 ) ;
F_17 ( V_44 ) ;
return V_253 ;
}
if ( F_143 ( V_116 ) )
return - V_254 ;
return - V_255 ;
}
static int F_161 ( struct V_1 * V_2 , void T_3 * V_162 )
{
int V_253 ;
struct V_42 * V_44 ;
V_253 = - V_256 ;
V_44 = F_26 ( V_2 ) ;
if ( V_44 ) {
V_253 = F_158 ( V_44 , ( void T_3 * T_3 * ) V_162 ) ;
F_17 ( V_44 ) ;
}
return V_253 ;
}
static int F_162 ( struct V_1 * V_2 , void T_3 * V_162 )
{
struct V_269 V_264 ;
if ( F_93 ( & V_264 , V_162 , sizeof( V_264 ) ) )
return - V_33 ;
V_2 -> V_156 = V_264 . V_85 ;
V_2 -> V_160 = V_264 . V_79 ;
return 0 ;
}
static int F_163 ( struct V_1 * V_2 , void T_3 * V_162 )
{
unsigned int V_101 ;
if ( F_109 ( V_101 , ( unsigned int T_3 * ) V_162 ) )
return - V_33 ;
return F_59 ( V_2 , V_101 ) ;
}
static int F_164 ( struct V_1 * V_2 , void T_3 * V_162 )
{
unsigned int V_101 ;
int V_10 ;
if ( F_109 ( V_101 , ( unsigned int T_3 * ) V_162 ) )
return - V_33 ;
if ( ( V_10 = F_64 ( V_2 , V_101 ) ) < 0 )
return V_10 ;
F_46 ( V_2 , V_101 ) ;
return 0 ;
}
static int F_165 ( struct V_1 * V_2 , struct V_270 * V_271 )
{
int V_272 ;
void * V_16 = NULL ;
int V_253 = 0 ;
struct V_105 * V_106 = NULL ;
struct V_273 * V_183 = NULL ;
if ( ( V_272 = F_166 ( V_271 -> V_274 ) ) > 0 ) {
if ( ( V_16 = F_77 ( V_272 , V_45 ) ) == NULL )
return - V_148 ;
if ( ( F_167 ( V_271 -> V_274 ) & V_275 ) ) {
if ( F_93 ( V_16 , V_271 -> V_62 , V_272 ) ) {
F_16 ( V_16 ) ;
return - V_33 ;
}
} else {
memset ( V_16 , 0 , V_272 ) ;
}
}
if ( ! F_1 ( V_2 ) ) {
F_16 ( V_16 ) ;
return - V_24 ;
}
if ( V_2 -> V_4 -> V_5 != V_114 )
V_253 = - V_115 ;
else if ( ! ( V_106 = F_61 ( V_2 -> V_4 , V_271 -> V_276 ) ) )
V_253 = - V_15 ;
else switch ( V_271 -> V_274 ) {
case V_277 :
if ( V_106 -> V_4 . V_183 ) {
V_183 = F_168 ( V_106 -> V_4 . V_183 ) ;
F_169 ( & V_106 -> V_4 , L_28 ) ;
F_66 ( V_183 , V_106 ) ;
} else
V_253 = - V_184 ;
break;
case V_278 :
if ( ! V_106 -> V_4 . V_183 )
V_253 = F_170 ( & V_106 -> V_4 ) ;
else
V_253 = - V_197 ;
break;
default:
if ( V_106 -> V_4 . V_183 )
V_183 = F_168 ( V_106 -> V_4 . V_183 ) ;
if ( V_183 == NULL || V_183 -> V_279 == NULL ) {
V_253 = - V_280 ;
} else {
V_253 = V_183 -> V_279 ( V_106 , V_271 -> V_274 , V_16 ) ;
if ( V_253 == - V_281 )
V_253 = - V_280 ;
}
}
if ( V_253 >= 0
&& ( F_167 ( V_271 -> V_274 ) & V_282 ) != 0
&& V_272 > 0
&& F_9 ( V_271 -> V_62 , V_16 , V_272 ) != 0 )
V_253 = - V_33 ;
F_16 ( V_16 ) ;
return V_253 ;
}
static int F_171 ( struct V_1 * V_2 , void T_3 * V_162 )
{
struct V_270 V_164 ;
if ( F_93 ( & V_164 , V_162 , sizeof( V_164 ) ) )
return - V_33 ;
return F_165 ( V_2 , & V_164 ) ;
}
static int F_172 ( struct V_1 * V_2 , T_10 V_162 )
{
struct V_283 T_3 * V_284 ;
struct V_270 V_164 ;
T_6 V_259 ;
V_284 = F_152 ( ( long ) V_162 ) ;
if ( ! F_96 ( V_231 , V_284 , sizeof( * V_284 ) ) ||
F_156 ( V_164 . V_276 , & V_284 -> V_276 ) ||
F_156 ( V_164 . V_274 , & V_284 -> V_274 ) ||
F_156 ( V_259 , & V_284 -> V_62 ) )
return - V_33 ;
V_164 . V_62 = F_152 ( V_259 ) ;
return F_165 ( V_2 , & V_164 ) ;
}
static int F_173 ( struct V_1 * V_2 , void T_3 * V_162 )
{
unsigned V_285 ;
int V_286 ;
if ( F_109 ( V_285 , ( unsigned T_3 * ) V_162 ) )
return - V_33 ;
V_286 = F_174 ( V_2 -> V_4 , V_285 , V_2 ) ;
if ( V_286 == 0 )
F_41 ( & V_2 -> V_4 -> V_4 , L_29 ,
V_285 , F_68 ( V_116 ) , V_116 -> V_117 ) ;
return V_286 ;
}
static int F_175 ( struct V_1 * V_2 , void T_3 * V_162 )
{
unsigned V_285 ;
if ( F_109 ( V_285 , ( unsigned T_3 * ) V_162 ) )
return - V_33 ;
return F_176 ( V_2 -> V_4 , V_285 , V_2 ) ;
}
static long F_177 ( struct V_7 * V_7 , unsigned int V_287 ,
void T_3 * V_102 )
{
struct V_1 * V_2 = V_7 -> V_19 ;
struct V_146 * V_146 = V_7 -> V_288 . V_289 -> V_12 ;
struct V_20 * V_4 = V_2 -> V_4 ;
int V_10 = - V_280 ;
if ( ! ( V_7 -> V_290 & V_291 ) )
return - V_292 ;
F_7 ( V_4 ) ;
if ( ! F_1 ( V_2 ) ) {
F_12 ( V_4 ) ;
return - V_24 ;
}
switch ( V_287 ) {
case V_293 :
F_41 ( & V_4 -> V_4 , L_30 , V_294 ) ;
V_10 = F_92 ( V_2 , V_102 ) ;
if ( V_10 >= 0 )
V_146 -> V_295 = V_296 ;
break;
case V_297 :
F_41 ( & V_4 -> V_4 , L_31 , V_294 ) ;
V_10 = F_103 ( V_2 , V_102 ) ;
if ( V_10 >= 0 )
V_146 -> V_295 = V_296 ;
break;
case V_298 :
F_41 ( & V_4 -> V_4 , L_32 , V_294 ) ;
V_10 = F_108 ( V_2 , V_102 ) ;
if ( V_10 >= 0 )
V_146 -> V_295 = V_296 ;
break;
case V_299 :
F_41 ( & V_4 -> V_4 , L_33 , V_294 ) ;
V_10 = F_115 ( V_2 ) ;
break;
case V_300 :
F_41 ( & V_4 -> V_4 , L_34 , V_294 ) ;
V_10 = F_111 ( V_2 , V_102 ) ;
if ( V_10 >= 0 )
V_146 -> V_295 = V_296 ;
break;
case V_301 :
F_41 ( & V_4 -> V_4 , L_35 , V_294 ) ;
V_10 = F_113 ( V_2 , V_102 ) ;
break;
case V_302 :
F_41 ( & V_4 -> V_4 , L_36 , V_294 ) ;
V_10 = F_114 ( V_2 , V_102 ) ;
break;
case V_303 :
F_41 ( & V_4 -> V_4 , L_37 , V_294 ) ;
V_10 = F_117 ( V_2 , V_102 ) ;
break;
case V_304 :
F_41 ( & V_4 -> V_4 , L_38 , V_294 ) ;
V_10 = F_119 ( V_2 , V_102 ) ;
break;
case V_305 :
F_41 ( & V_4 -> V_4 , L_39 , V_294 ) ;
V_10 = F_135 ( V_2 , V_102 ) ;
if ( V_10 >= 0 )
V_146 -> V_295 = V_296 ;
break;
#ifdef F_178
case V_306 :
F_41 ( & V_4 -> V_4 , L_40 , V_294 ) ;
V_10 = F_149 ( V_2 , V_102 ) ;
if ( V_10 >= 0 )
V_146 -> V_295 = V_296 ;
break;
case V_307 :
F_41 ( & V_4 -> V_4 , L_41 , V_294 ) ;
V_10 = F_153 ( V_2 , V_102 ) ;
if ( V_10 >= 0 )
V_146 -> V_295 = V_296 ;
break;
case V_308 :
F_41 ( & V_4 -> V_4 , L_42 , V_294 ) ;
V_10 = F_154 ( V_2 , V_102 ) ;
break;
case V_309 :
F_41 ( & V_4 -> V_4 , L_43 , V_294 ) ;
V_10 = F_157 ( V_2 , V_102 ) ;
if ( V_10 >= 0 )
V_146 -> V_295 = V_296 ;
break;
case V_310 :
F_41 ( & V_4 -> V_4 , L_44 , V_294 ) ;
V_10 = F_160 ( V_2 , V_102 ) ;
break;
case V_311 :
F_41 ( & V_4 -> V_4 , L_45 , V_294 ) ;
V_10 = F_161 ( V_2 , V_102 ) ;
break;
case V_312 :
F_41 ( & V_4 -> V_4 , L_46 , V_294 ) ;
V_10 = F_172 ( V_2 , F_159 ( V_102 ) ) ;
break;
#endif
case V_313 :
F_41 ( & V_4 -> V_4 , L_47 , V_294 ) ;
V_10 = F_136 ( V_2 , V_102 ) ;
break;
case V_314 :
F_41 ( & V_4 -> V_4 , L_48 , V_294 ) ;
V_10 = F_147 ( V_2 , V_102 ) ;
break;
case V_315 :
F_41 ( & V_4 -> V_4 , L_49 , V_294 ) ;
V_10 = F_148 ( V_2 , V_102 ) ;
break;
case V_316 :
F_41 ( & V_4 -> V_4 , L_50 , V_294 ) ;
V_10 = F_162 ( V_2 , V_102 ) ;
break;
case V_317 :
F_41 ( & V_4 -> V_4 , L_51 , V_294 ) ;
V_10 = F_163 ( V_2 , V_102 ) ;
break;
case V_318 :
F_41 ( & V_4 -> V_4 , L_52 , V_294 ) ;
V_10 = F_164 ( V_2 , V_102 ) ;
break;
case V_319 :
F_41 ( & V_4 -> V_4 , L_53 , V_294 ) ;
V_10 = F_171 ( V_2 , V_102 ) ;
break;
case V_320 :
F_41 ( & V_4 -> V_4 , L_54 , V_294 ) ;
V_10 = F_173 ( V_2 , V_102 ) ;
break;
case V_321 :
F_41 ( & V_4 -> V_4 , L_55 , V_294 ) ;
V_10 = F_175 ( V_2 , V_102 ) ;
break;
}
F_12 ( V_4 ) ;
if ( V_10 >= 0 )
V_146 -> V_322 = V_296 ;
return V_10 ;
}
static long F_179 ( struct V_7 * V_7 , unsigned int V_287 ,
unsigned long V_162 )
{
int V_10 ;
V_10 = F_177 ( V_7 , V_287 , ( void T_3 * ) V_162 ) ;
return V_10 ;
}
static long F_180 ( struct V_7 * V_7 , unsigned int V_287 ,
unsigned long V_162 )
{
int V_10 ;
V_10 = F_177 ( V_7 , V_287 , F_152 ( V_162 ) ) ;
return V_10 ;
}
static unsigned int F_181 ( struct V_7 * V_7 ,
struct V_323 * V_99 )
{
struct V_1 * V_2 = V_7 -> V_19 ;
unsigned int V_324 = 0 ;
F_182 ( V_7 , & V_2 -> V_99 , V_99 ) ;
if ( V_7 -> V_290 & V_291 && ! F_2 ( & V_2 -> V_54 ) )
V_324 |= V_325 | V_326 ;
if ( ! F_1 ( V_2 ) )
V_324 |= V_327 | V_328 ;
return V_324 ;
}
static void F_183 ( struct V_20 * V_57 )
{
struct V_1 * V_2 ;
struct V_80 V_81 ;
while ( ! F_2 ( & V_57 -> V_161 ) ) {
V_2 = F_27 ( V_57 -> V_161 . V_55 , struct V_1 , V_3 ) ;
F_49 ( V_2 ) ;
F_184 ( & V_2 -> V_99 ) ;
F_25 ( & V_2 -> V_3 ) ;
if ( V_2 -> V_156 ) {
V_81 . V_87 = V_2 -> V_156 ;
V_81 . V_88 = V_175 ;
V_81 . V_89 = V_90 ;
V_81 . V_91 = V_2 -> V_160 ;
F_42 ( V_2 -> V_156 , & V_81 ,
V_2 -> V_157 , V_2 -> V_158 ,
V_2 -> V_159 , V_2 -> V_84 ) ;
}
}
}
static int F_185 ( struct V_20 * V_4 )
{
struct V_142 * V_329 ;
V_329 = F_186 ( V_330 , & V_4 -> V_4 , V_4 -> V_4 . V_143 ,
NULL , L_56 , V_4 -> V_331 -> V_332 ,
V_4 -> V_188 ) ;
if ( F_187 ( V_329 ) )
return F_188 ( V_329 ) ;
V_4 -> V_333 = V_329 ;
return 0 ;
}
static void F_189 ( struct V_20 * V_4 )
{
if ( V_4 -> V_333 )
F_190 ( V_4 -> V_333 ) ;
}
static int F_191 ( struct V_334 * V_335 ,
unsigned long V_336 , void * V_4 )
{
switch ( V_336 ) {
case V_337 :
if ( F_185 ( V_4 ) )
return V_338 ;
break;
case V_339 :
F_189 ( V_4 ) ;
F_183 ( V_4 ) ;
break;
}
return V_340 ;
}
int T_11 F_192 ( void )
{
int V_253 ;
V_253 = F_193 ( V_341 , V_342 ,
L_57 ) ;
if ( V_253 ) {
F_194 ( V_343 L_58 ) ;
goto V_344;
}
F_195 ( & V_345 , & V_346 ) ;
V_253 = F_196 ( & V_345 , V_341 , V_342 ) ;
if ( V_253 ) {
F_194 ( V_343 L_59 ,
V_151 ) ;
goto V_347;
}
#ifdef F_197
V_330 = F_198 ( V_348 , L_57 ) ;
if ( F_187 ( V_330 ) ) {
F_194 ( V_343 L_60 ) ;
V_253 = F_188 ( V_330 ) ;
F_199 ( & V_345 ) ;
V_330 = NULL ;
goto V_344;
}
V_330 -> V_349 = NULL ;
#endif
F_200 ( & V_350 ) ;
V_344:
return V_253 ;
V_347:
F_201 ( V_341 , V_342 ) ;
goto V_344;
}
void F_202 ( void )
{
F_203 ( & V_350 ) ;
#ifdef F_197
F_204 ( V_330 ) ;
#endif
F_199 ( & V_345 ) ;
F_201 ( V_341 , V_342 ) ;
}
