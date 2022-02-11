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
F_19 ( V_44 -> V_48 ) ;
F_16 ( V_44 -> V_46 -> V_49 ) ;
F_16 ( V_44 -> V_46 -> V_50 ) ;
F_20 ( V_44 -> V_46 ) ;
F_16 ( V_44 ) ;
}
static void F_21 ( struct V_42 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_2 ;
unsigned long V_51 ;
F_22 ( & V_2 -> V_52 , V_51 ) ;
F_23 ( & V_44 -> V_53 , & V_2 -> V_54 ) ;
F_24 ( & V_2 -> V_52 , V_51 ) ;
}
static void F_25 ( struct V_42 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_2 ;
unsigned long V_51 ;
F_22 ( & V_2 -> V_52 , V_51 ) ;
F_26 ( & V_44 -> V_53 ) ;
F_24 ( & V_2 -> V_52 , V_51 ) ;
}
static struct V_42 * F_27 ( struct V_1 * V_2 )
{
unsigned long V_51 ;
struct V_42 * V_44 = NULL ;
F_22 ( & V_2 -> V_52 , V_51 ) ;
if ( ! F_2 ( & V_2 -> V_55 ) ) {
V_44 = F_28 ( V_2 -> V_55 . V_56 , struct V_42 ,
V_53 ) ;
F_26 ( & V_44 -> V_53 ) ;
}
F_24 ( & V_2 -> V_52 , V_51 ) ;
return V_44 ;
}
static struct V_42 * F_29 ( struct V_1 * V_2 ,
void T_3 * V_57 )
{
unsigned long V_51 ;
struct V_42 * V_44 ;
F_22 ( & V_2 -> V_52 , V_51 ) ;
F_30 (as, &ps->async_pending, asynclist)
if ( V_44 -> V_57 == V_57 ) {
F_26 ( & V_44 -> V_53 ) ;
F_24 ( & V_2 -> V_52 , V_51 ) ;
return V_44 ;
}
F_24 ( & V_2 -> V_52 , V_51 ) ;
return NULL ;
}
static void F_31 ( struct V_20 * V_58 ,
void T_3 * V_57 , int V_59 , unsigned V_38 ,
int V_60 , enum V_61 V_62 ,
unsigned char * V_63 , unsigned V_64 )
{
static const char * V_65 [] = { L_1 , L_2 , L_3 , L_4 } ;
static const char * V_66 [] = { L_5 , L_6 } ;
int V_67 ;
const char * V_68 , * V_69 ;
if ( ! V_70 )
return;
V_67 = F_32 ( V_59 ) ;
V_68 = V_65 [ F_33 ( V_59 ) ] ;
V_69 = V_66 [ ! ! F_34 ( V_59 ) ] ;
if ( V_57 ) {
if ( V_62 == V_71 )
F_35 ( & V_58 -> V_4 , L_7
L_8 ,
V_57 , V_67 , V_68 , V_69 , V_38 ) ;
else
F_35 ( & V_58 -> V_4 , L_7
L_9 ,
V_57 , V_67 , V_68 , V_69 , V_38 ,
V_60 ) ;
} else {
if ( V_62 == V_71 )
F_35 ( & V_58 -> V_4 , L_10
L_11 ,
V_67 , V_68 , V_69 , V_38 , V_60 ) ;
else
F_35 ( & V_58 -> V_4 , L_12
L_13 ,
V_67 , V_68 , V_69 , V_38 , V_60 ) ;
}
if ( V_63 && V_64 > 0 ) {
F_36 ( V_72 , L_14 , V_73 , 32 , 1 ,
V_63 , V_64 , 1 ) ;
}
}
static void F_37 ( struct V_1 * V_2 , unsigned V_74 )
__releases( V_2 -> V_52 )
__acquires( V_2 -> V_52 )
{
struct V_42 * V_44 ;
F_30 (as, &ps->async_pending, asynclist) {
if ( V_44 -> V_74 == V_74 ) {
if ( V_44 -> V_75 != V_76 )
goto V_77;
V_44 -> V_75 = V_78 ;
V_44 -> V_74 = 0 ;
}
}
V_2 -> V_79 |= ( 1 << V_74 ) ;
V_77:
F_30 (as, &ps->async_pending, asynclist) {
if ( V_44 -> V_75 == V_78 ) {
V_44 -> V_75 = 0 ;
F_38 ( & V_2 -> V_52 ) ;
F_39 ( V_44 -> V_46 ) ;
F_40 ( & V_2 -> V_52 ) ;
goto V_77;
}
}
}
static void V_55 ( struct V_46 * V_46 )
{
struct V_42 * V_44 = V_46 -> V_80 ;
struct V_1 * V_2 = V_44 -> V_2 ;
struct V_81 V_82 ;
struct V_47 * V_47 = NULL ;
T_5 V_83 = 0 ;
const struct V_48 * V_48 = NULL ;
int V_84 ;
F_40 ( & V_2 -> V_52 ) ;
F_41 ( & V_44 -> V_53 , & V_2 -> V_55 ) ;
V_44 -> V_85 = V_46 -> V_85 ;
V_84 = V_44 -> V_84 ;
if ( V_84 ) {
V_82 . V_86 = V_44 -> V_84 ;
V_82 . V_87 = V_44 -> V_85 ;
V_82 . V_88 = V_89 ;
V_82 . V_90 = V_44 -> V_57 ;
V_47 = F_42 ( V_44 -> V_47 ) ;
V_48 = F_43 ( V_44 -> V_48 ) ;
V_83 = V_44 -> V_83 ;
}
F_44 ( & V_46 -> V_4 -> V_4 , L_15 ) ;
F_31 ( V_46 -> V_4 , V_44 -> V_57 , V_46 -> V_59 , V_46 -> V_91 ,
V_44 -> V_85 , V_92 ,
( ( V_46 -> V_93 & V_94 ) == V_95 ) ?
NULL : V_46 -> V_49 , V_46 -> V_91 ) ;
if ( V_44 -> V_85 < 0 && V_44 -> V_74 && V_44 -> V_85 != - V_96 &&
V_44 -> V_85 != - V_97 )
F_37 ( V_2 , V_44 -> V_74 ) ;
F_38 ( & V_2 -> V_52 ) ;
if ( V_84 ) {
F_45 ( V_82 . V_86 , & V_82 , V_47 , V_48 , V_83 ) ;
F_18 ( V_47 ) ;
F_19 ( V_48 ) ;
}
F_46 ( & V_2 -> V_98 ) ;
}
static void F_47 ( struct V_1 * V_2 , struct V_99 * V_3 )
{
struct V_42 * V_44 ;
unsigned long V_51 ;
F_22 ( & V_2 -> V_52 , V_51 ) ;
while ( ! F_2 ( V_3 ) ) {
V_44 = F_28 ( V_3 -> V_56 , struct V_42 , V_53 ) ;
F_26 ( & V_44 -> V_53 ) ;
F_24 ( & V_2 -> V_52 , V_51 ) ;
F_48 ( V_44 -> V_46 ) ;
F_22 ( & V_2 -> V_52 , V_51 ) ;
}
F_24 ( & V_2 -> V_52 , V_51 ) ;
}
static void F_49 ( struct V_1 * V_2 ,
unsigned int V_100 )
{
struct V_99 * V_101 , * V_102 , V_103 ;
unsigned long V_51 ;
F_50 ( & V_103 ) ;
F_22 ( & V_2 -> V_52 , V_51 ) ;
F_51 (p, q, &ps->async_pending)
if ( V_100 == F_28 ( V_101 , struct V_42 , V_53 ) -> V_100 )
F_41 ( V_101 , & V_103 ) ;
F_24 ( & V_2 -> V_52 , V_51 ) ;
F_47 ( V_2 , & V_103 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
F_47 ( V_2 , & V_2 -> V_54 ) ;
}
static int F_53 ( struct V_104 * V_105 ,
const struct V_106 * V_107 )
{
return - V_24 ;
}
static void F_54 ( struct V_104 * V_105 )
{
struct V_1 * V_2 = F_55 ( V_105 ) ;
unsigned int V_100 = V_105 -> V_108 -> V_41 . V_109 ;
if ( ! V_2 )
return;
if ( F_56 ( V_100 < 8 * sizeof( V_2 -> V_110 ) ) )
F_57 ( V_100 , & V_2 -> V_110 ) ;
else
F_58 ( & V_105 -> V_4 , L_16 ,
V_100 ) ;
F_59 ( V_105 , NULL ) ;
F_49 ( V_2 , V_100 ) ;
}
static int F_60 ( struct V_104 * V_105 , T_6 V_111 )
{
return 0 ;
}
static int F_61 ( struct V_104 * V_105 )
{
return 0 ;
}
static int F_62 ( struct V_1 * V_2 , unsigned int V_100 )
{
struct V_20 * V_4 = V_2 -> V_4 ;
struct V_104 * V_105 ;
int V_25 ;
if ( V_100 >= 8 * sizeof( V_2 -> V_110 ) )
return - V_15 ;
if ( F_63 ( V_100 , & V_2 -> V_110 ) )
return 0 ;
V_105 = F_64 ( V_4 , V_100 ) ;
if ( ! V_105 )
V_25 = - V_97 ;
else
V_25 = F_65 ( & V_112 , V_105 , V_2 ) ;
if ( V_25 == 0 )
F_66 ( V_100 , & V_2 -> V_110 ) ;
return V_25 ;
}
static int F_67 ( struct V_1 * V_2 , unsigned int V_100 )
{
struct V_20 * V_4 ;
struct V_104 * V_105 ;
int V_25 ;
V_25 = - V_15 ;
if ( V_100 >= 8 * sizeof( V_2 -> V_110 ) )
return V_25 ;
V_4 = V_2 -> V_4 ;
V_105 = F_64 ( V_4 , V_100 ) ;
if ( ! V_105 )
V_25 = - V_97 ;
else if ( F_68 ( V_100 , & V_2 -> V_110 ) ) {
F_69 ( & V_112 , V_105 ) ;
V_25 = 0 ;
}
return V_25 ;
}
static int F_70 ( struct V_1 * V_2 , unsigned int V_100 )
{
if ( V_2 -> V_4 -> V_5 != V_113 )
return - V_114 ;
if ( V_100 >= 8 * sizeof( V_2 -> V_110 ) )
return - V_15 ;
if ( F_63 ( V_100 , & V_2 -> V_110 ) )
return 0 ;
F_58 ( & V_2 -> V_4 -> V_4 , L_17
L_18 , F_71 ( V_115 ) ,
V_115 -> V_116 , V_100 ) ;
return F_62 ( V_2 , V_100 ) ;
}
static int F_72 ( struct V_20 * V_4 , unsigned int V_67 )
{
unsigned int V_23 , V_117 , V_118 ;
struct V_104 * V_105 ;
struct V_119 * V_120 ;
struct V_121 * V_122 ;
if ( V_67 & ~ ( V_123 | 0xf ) )
return - V_15 ;
if ( ! V_4 -> V_124 )
return - V_125 ;
for ( V_23 = 0 ; V_23 < V_4 -> V_124 -> V_41 . V_126 ; V_23 ++ ) {
V_105 = V_4 -> V_124 -> V_127 [ V_23 ] ;
for ( V_117 = 0 ; V_117 < V_105 -> V_128 ; V_117 ++ ) {
V_120 = & V_105 -> V_108 [ V_117 ] ;
for ( V_118 = 0 ; V_118 < V_120 -> V_41 . V_129 ; V_118 ++ ) {
V_122 = & V_120 -> V_130 [ V_118 ] . V_41 ;
if ( V_122 -> V_131 == V_67 )
return V_120 -> V_41 . V_109 ;
}
}
}
return - V_97 ;
}
static int F_73 ( struct V_1 * V_2 , unsigned int V_132 ,
unsigned int V_133 , unsigned int V_134 )
{
int V_10 = 0 ;
struct V_119 * V_135 ;
if ( V_2 -> V_4 -> V_5 != V_136
&& V_2 -> V_4 -> V_5 != V_137
&& V_2 -> V_4 -> V_5 != V_113 )
return - V_114 ;
if ( V_138 == ( V_139 & V_132 ) )
return 0 ;
if ( V_132 == 0xa1 && V_133 == 0 ) {
V_135 = F_74 ( V_2 -> V_4 -> V_124 ,
V_134 >> 8 , V_134 & 0xff ) ;
if ( V_135
&& V_135 -> V_41 . V_140 == V_141 )
V_134 >>= 8 ;
}
V_134 &= 0xff ;
switch ( V_132 & V_142 ) {
case V_143 :
V_10 = F_72 ( V_2 -> V_4 , V_134 ) ;
if ( V_10 >= 0 )
V_10 = F_70 ( V_2 , V_10 ) ;
break;
case V_144 :
V_10 = F_70 ( V_2 , V_134 ) ;
break;
}
return V_10 ;
}
static int F_75 ( struct V_145 * V_4 , void * V_63 )
{
return V_4 -> V_146 == ( V_147 ) ( unsigned long ) V_63 ;
}
static struct V_20 * F_76 ( V_147 V_146 )
{
struct V_145 * V_4 ;
V_4 = F_77 ( & V_148 , NULL ,
( void * ) ( unsigned long ) V_146 , F_75 ) ;
if ( ! V_4 )
return NULL ;
return F_78 ( V_4 , struct V_20 , V_4 ) ;
}
static int F_79 ( struct V_149 * V_149 , struct V_7 * V_7 )
{
struct V_20 * V_4 = NULL ;
struct V_1 * V_2 ;
int V_10 ;
V_10 = - V_150 ;
V_2 = F_80 ( sizeof( struct V_1 ) , V_45 ) ;
if ( ! V_2 )
goto V_151;
V_10 = - V_24 ;
F_4 ( & V_152 ) ;
if ( F_81 ( V_149 ) == V_153 )
V_4 = F_76 ( V_149 -> V_154 ) ;
#ifdef F_82
if ( ! V_4 ) {
V_4 = V_149 -> V_155 ;
if ( V_4 && V_4 -> V_156 &&
V_4 -> V_156 -> V_12 == V_149 )
F_83 ( V_4 ) ;
else
V_4 = NULL ;
}
#endif
F_5 ( & V_152 ) ;
if ( ! V_4 )
goto V_151;
F_7 ( V_4 ) ;
if ( V_4 -> V_5 == V_6 )
goto V_157;
V_10 = F_84 ( V_4 ) ;
if ( V_10 )
goto V_157;
V_2 -> V_4 = V_4 ;
V_2 -> V_7 = V_7 ;
F_85 ( & V_2 -> V_52 ) ;
F_50 ( & V_2 -> V_3 ) ;
F_50 ( & V_2 -> V_54 ) ;
F_50 ( & V_2 -> V_55 ) ;
F_86 ( & V_2 -> V_98 ) ;
V_2 -> V_158 = 0 ;
V_2 -> V_159 = F_42 ( F_87 ( V_115 ) ) ;
V_2 -> V_48 = F_88 () ;
V_2 -> V_160 = NULL ;
V_2 -> V_110 = 0 ;
F_89 ( V_115 , & V_2 -> V_83 ) ;
F_90 () ;
F_23 ( & V_2 -> V_3 , & V_4 -> V_161 ) ;
V_7 -> V_19 = V_2 ;
F_12 ( V_4 ) ;
F_44 ( & V_4 -> V_4 , L_19 , F_71 ( V_115 ) ,
V_115 -> V_116 ) ;
return V_10 ;
V_157:
F_12 ( V_4 ) ;
F_91 ( V_4 ) ;
V_151:
F_16 ( V_2 ) ;
return V_10 ;
}
static int F_92 ( struct V_149 * V_149 , struct V_7 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_19 ;
struct V_20 * V_4 = V_2 -> V_4 ;
unsigned int V_100 ;
struct V_42 * V_44 ;
F_7 ( V_4 ) ;
F_93 ( V_4 , V_2 ) ;
F_26 ( & V_2 -> V_3 ) ;
for ( V_100 = 0 ; V_2 -> V_110 && V_100 < 8 * sizeof( V_2 -> V_110 ) ;
V_100 ++ ) {
if ( F_63 ( V_100 , & V_2 -> V_110 ) )
F_67 ( V_2 , V_100 ) ;
}
F_52 ( V_2 ) ;
F_94 ( V_4 ) ;
F_12 ( V_4 ) ;
F_91 ( V_4 ) ;
F_18 ( V_2 -> V_159 ) ;
F_19 ( V_2 -> V_48 ) ;
V_44 = F_27 ( V_2 ) ;
while ( V_44 ) {
F_17 ( V_44 ) ;
V_44 = F_27 ( V_2 ) ;
}
F_16 ( V_2 ) ;
return 0 ;
}
static int F_95 ( struct V_1 * V_2 , void T_3 * V_162 )
{
struct V_20 * V_4 = V_2 -> V_4 ;
struct V_163 V_164 ;
unsigned int V_165 ;
unsigned char * V_166 ;
unsigned V_167 ;
int V_23 , V_59 , V_10 ;
if ( F_96 ( & V_164 , V_162 , sizeof( V_164 ) ) )
return - V_33 ;
V_10 = F_73 ( V_2 , V_164 . V_168 , V_164 . V_169 ,
V_164 . V_170 ) ;
if ( V_10 )
return V_10 ;
V_167 = V_164 . V_167 ;
if ( V_167 > V_171 )
return - V_15 ;
V_166 = ( unsigned char * ) F_97 ( V_45 ) ;
if ( ! V_166 )
return - V_150 ;
V_165 = V_164 . V_172 ;
F_44 ( & V_4 -> V_4 , L_20
L_21
L_22 ,
V_164 . V_168 , V_164 . V_169 ,
F_98 ( & V_164 . V_173 ) ,
F_98 ( & V_164 . V_170 ) ,
F_98 ( & V_164 . V_167 ) ) ;
if ( V_164 . V_168 & 0x80 ) {
if ( V_164 . V_167 && ! F_99 ( V_174 , V_164 . V_63 ,
V_164 . V_167 ) ) {
F_100 ( ( unsigned long ) V_166 ) ;
return - V_15 ;
}
V_59 = F_101 ( V_4 , 0 ) ;
F_31 ( V_4 , NULL , V_59 , V_164 . V_167 , V_165 , V_71 , NULL , 0 ) ;
F_12 ( V_4 ) ;
V_23 = F_102 ( V_4 , V_59 , V_164 . V_169 ,
V_164 . V_168 , V_164 . V_173 , V_164 . V_170 ,
V_166 , V_164 . V_167 , V_165 ) ;
F_7 ( V_4 ) ;
F_31 ( V_4 , NULL , V_59 , F_103 ( V_23 , 0 ) , F_11 ( V_23 , 0 ) , V_92 ,
V_166 , F_103 ( V_23 , 0 ) ) ;
if ( ( V_23 > 0 ) && V_164 . V_167 ) {
if ( F_9 ( V_164 . V_63 , V_166 , V_23 ) ) {
F_100 ( ( unsigned long ) V_166 ) ;
return - V_33 ;
}
}
} else {
if ( V_164 . V_167 ) {
if ( F_96 ( V_166 , V_164 . V_63 , V_164 . V_167 ) ) {
F_100 ( ( unsigned long ) V_166 ) ;
return - V_33 ;
}
}
V_59 = F_104 ( V_4 , 0 ) ;
F_31 ( V_4 , NULL , V_59 , V_164 . V_167 , V_165 , V_71 ,
V_166 , V_164 . V_167 ) ;
F_12 ( V_4 ) ;
V_23 = F_102 ( V_4 , F_104 ( V_4 , 0 ) , V_164 . V_169 ,
V_164 . V_168 , V_164 . V_173 , V_164 . V_170 ,
V_166 , V_164 . V_167 , V_165 ) ;
F_7 ( V_4 ) ;
F_31 ( V_4 , NULL , V_59 , F_103 ( V_23 , 0 ) , F_11 ( V_23 , 0 ) , V_92 , NULL , 0 ) ;
}
F_100 ( ( unsigned long ) V_166 ) ;
if ( V_23 < 0 && V_23 != - V_175 ) {
F_105 ( V_72 , & V_4 -> V_4 , L_23
L_24 ,
V_115 -> V_116 , V_164 . V_168 , V_164 . V_169 ,
V_164 . V_167 , V_23 ) ;
}
return V_23 ;
}
static int F_106 ( struct V_1 * V_2 , void T_3 * V_162 )
{
struct V_20 * V_4 = V_2 -> V_4 ;
struct V_176 V_177 ;
unsigned int V_165 , V_178 , V_59 ;
int V_179 ;
unsigned char * V_166 ;
int V_23 , V_10 ;
if ( F_96 ( & V_177 , V_162 , sizeof( V_177 ) ) )
return - V_33 ;
V_10 = F_72 ( V_2 -> V_4 , V_177 . V_67 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_70 ( V_2 , V_10 ) ;
if ( V_10 )
return V_10 ;
if ( V_177 . V_67 & V_123 )
V_59 = F_107 ( V_4 , V_177 . V_67 & 0x7f ) ;
else
V_59 = F_108 ( V_4 , V_177 . V_67 & 0x7f ) ;
if ( ! F_109 ( V_4 , V_59 , ! ( V_177 . V_67 & V_123 ) ) )
return - V_15 ;
V_178 = V_177 . V_21 ;
if ( V_178 > V_180 )
return - V_15 ;
if ( ! ( V_166 = F_80 ( V_178 , V_45 ) ) )
return - V_150 ;
V_165 = V_177 . V_172 ;
if ( V_177 . V_67 & 0x80 ) {
if ( V_178 && ! F_99 ( V_174 , V_177 . V_63 , V_178 ) ) {
F_16 ( V_166 ) ;
return - V_15 ;
}
F_31 ( V_4 , NULL , V_59 , V_178 , V_165 , V_71 , NULL , 0 ) ;
F_12 ( V_4 ) ;
V_23 = F_110 ( V_4 , V_59 , V_166 , V_178 , & V_179 , V_165 ) ;
F_7 ( V_4 ) ;
F_31 ( V_4 , NULL , V_59 , V_179 , V_23 , V_92 , V_166 , V_179 ) ;
if ( ! V_23 && V_179 ) {
if ( F_9 ( V_177 . V_63 , V_166 , V_179 ) ) {
F_16 ( V_166 ) ;
return - V_33 ;
}
}
} else {
if ( V_178 ) {
if ( F_96 ( V_166 , V_177 . V_63 , V_178 ) ) {
F_16 ( V_166 ) ;
return - V_33 ;
}
}
F_31 ( V_4 , NULL , V_59 , V_178 , V_165 , V_71 , V_166 , V_178 ) ;
F_12 ( V_4 ) ;
V_23 = F_110 ( V_4 , V_59 , V_166 , V_178 , & V_179 , V_165 ) ;
F_7 ( V_4 ) ;
F_31 ( V_4 , NULL , V_59 , V_179 , V_23 , V_92 , NULL , 0 ) ;
}
F_16 ( V_166 ) ;
if ( V_23 < 0 )
return V_23 ;
return V_179 ;
}
static int F_111 ( struct V_1 * V_2 , void T_3 * V_162 )
{
unsigned int V_67 ;
int V_10 ;
if ( F_112 ( V_67 , ( unsigned int T_3 * ) V_162 ) )
return - V_33 ;
V_10 = F_72 ( V_2 -> V_4 , V_67 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_70 ( V_2 , V_10 ) ;
if ( V_10 )
return V_10 ;
F_113 ( V_2 -> V_4 , V_67 ) ;
return 0 ;
}
static int F_114 ( struct V_1 * V_2 , void T_3 * V_162 )
{
unsigned int V_67 ;
int V_59 ;
int V_10 ;
if ( F_112 ( V_67 , ( unsigned int T_3 * ) V_162 ) )
return - V_33 ;
V_10 = F_72 ( V_2 -> V_4 , V_67 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_70 ( V_2 , V_10 ) ;
if ( V_10 )
return V_10 ;
if ( V_67 & V_123 )
V_59 = F_107 ( V_2 -> V_4 , V_67 & 0x7f ) ;
else
V_59 = F_108 ( V_2 -> V_4 , V_67 & 0x7f ) ;
return F_115 ( V_2 -> V_4 , V_59 ) ;
}
static int F_116 ( struct V_1 * V_2 , void T_3 * V_162 )
{
struct V_181 V_182 ;
struct V_104 * V_105 ;
int V_10 ;
if ( F_96 ( & V_182 , V_162 , sizeof( V_182 ) ) )
return - V_33 ;
V_105 = F_64 ( V_2 -> V_4 , V_182 . V_127 ) ;
if ( ! V_105 || ! V_105 -> V_4 . V_183 )
V_10 = - V_184 ;
else {
strncpy ( V_182 . V_183 , V_105 -> V_4 . V_183 -> V_185 ,
sizeof( V_182 . V_183 ) ) ;
V_10 = ( F_9 ( V_162 , & V_182 , sizeof( V_182 ) ) ? - V_33 : 0 ) ;
}
return V_10 ;
}
static int F_117 ( struct V_1 * V_2 , void T_3 * V_162 )
{
struct V_186 V_187 = {
. V_188 = V_2 -> V_4 -> V_188 ,
. V_189 = V_2 -> V_4 -> V_190 == V_191
} ;
if ( F_9 ( V_162 , & V_187 , sizeof( V_187 ) ) )
return - V_33 ;
return 0 ;
}
static int F_118 ( struct V_1 * V_2 )
{
return F_119 ( V_2 -> V_4 ) ;
}
static int F_120 ( struct V_1 * V_2 , void T_3 * V_162 )
{
struct V_192 V_193 ;
int V_10 ;
if ( F_96 ( & V_193 , V_162 , sizeof( V_193 ) ) )
return - V_33 ;
if ( ( V_10 = F_70 ( V_2 , V_193 . V_127 ) ) )
return V_10 ;
return F_121 ( V_2 -> V_4 , V_193 . V_127 ,
V_193 . V_108 ) ;
}
static int F_122 ( struct V_1 * V_2 , void T_3 * V_162 )
{
int V_194 ;
int V_85 = 0 ;
struct V_195 * V_124 ;
if ( F_112 ( V_194 , ( int T_3 * ) V_162 ) )
return - V_33 ;
V_124 = V_2 -> V_4 -> V_124 ;
if ( V_124 ) {
int V_23 ;
for ( V_23 = 0 ; V_23 < V_124 -> V_41 . V_126 ; ++ V_23 ) {
if ( F_123 ( V_124 -> V_127 [ V_23 ] ) ) {
F_58 ( & V_2 -> V_4 -> V_4 ,
L_25
L_26 ,
V_124 -> V_127 [ V_23 ]
-> V_196
-> V_41 . V_109 ,
V_124 -> V_127 [ V_23 ]
-> V_4 . V_183 -> V_185 ,
V_115 -> V_116 , V_194 ) ;
V_85 = - V_197 ;
break;
}
}
}
if ( V_85 == 0 ) {
if ( V_124 && V_124 -> V_41 . V_198 == V_194 )
V_85 = F_124 ( V_2 -> V_4 ) ;
else
V_85 = F_125 ( V_2 -> V_4 , V_194 ) ;
}
return V_85 ;
}
static int F_126 ( struct V_1 * V_2 , struct V_199 * V_200 ,
struct V_201 T_3 * V_202 ,
void T_3 * V_162 )
{
struct V_201 * V_203 = NULL ;
struct V_204 * V_67 ;
struct V_42 * V_44 ;
struct V_205 * V_206 = NULL ;
unsigned int V_194 , V_207 , V_208 ;
int V_10 , V_100 = - 1 ;
int V_209 ;
if ( V_200 -> V_51 & ~ ( V_210 |
V_211 |
V_212 |
V_213 |
V_214 |
V_215 ) )
return - V_15 ;
if ( V_200 -> V_216 > 0 && ! V_200 -> V_217 )
return - V_15 ;
if ( ! ( V_200 -> type == V_218 &&
( V_200 -> V_130 & ~ V_219 ) == 0 ) ) {
V_100 = F_72 ( V_2 -> V_4 , V_200 -> V_130 ) ;
if ( V_100 < 0 )
return V_100 ;
V_10 = F_70 ( V_2 , V_100 ) ;
if ( V_10 )
return V_10 ;
}
if ( ( V_200 -> V_130 & V_219 ) != 0 ) {
V_209 = 1 ;
V_67 = V_2 -> V_4 -> V_220 [ V_200 -> V_130 & V_221 ] ;
} else {
V_209 = 0 ;
V_67 = V_2 -> V_4 -> V_222 [ V_200 -> V_130 & V_221 ] ;
}
if ( ! V_67 )
return - V_97 ;
switch( V_200 -> type ) {
case V_218 :
if ( ! F_127 ( & V_67 -> V_41 ) )
return - V_15 ;
if ( V_200 -> V_216 < 8 ||
V_200 -> V_216 > ( 8 + V_180 ) )
return - V_15 ;
V_206 = F_80 ( sizeof( struct V_205 ) , V_45 ) ;
if ( ! V_206 )
return - V_150 ;
if ( F_96 ( V_206 , V_200 -> V_217 , 8 ) ) {
F_16 ( V_206 ) ;
return - V_33 ;
}
if ( V_200 -> V_216 < ( F_128 ( & V_206 -> V_167 ) + 8 ) ) {
F_16 ( V_206 ) ;
return - V_15 ;
}
V_10 = F_73 ( V_2 , V_206 -> V_168 , V_206 -> V_169 ,
F_128 ( & V_206 -> V_170 ) ) ;
if ( V_10 ) {
F_16 ( V_206 ) ;
return V_10 ;
}
V_200 -> V_223 = 0 ;
V_200 -> V_216 = F_128 ( & V_206 -> V_167 ) ;
V_200 -> V_217 += 8 ;
if ( ( V_206 -> V_168 & V_123 ) && V_200 -> V_216 ) {
V_209 = 1 ;
V_200 -> V_130 |= V_123 ;
} else {
V_209 = 0 ;
V_200 -> V_130 &= ~ V_123 ;
}
F_44 ( & V_2 -> V_4 -> V_4 , L_20
L_21
L_22 ,
V_206 -> V_168 , V_206 -> V_169 ,
F_98 ( & V_206 -> V_173 ) ,
F_98 ( & V_206 -> V_170 ) ,
F_98 ( & V_206 -> V_167 ) ) ;
break;
case V_224 :
switch ( F_129 ( & V_67 -> V_41 ) ) {
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
if ( ! F_130 ( & V_67 -> V_41 ) )
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
if ( ! F_131 ( & V_67 -> V_41 ) )
return - V_15 ;
V_208 = sizeof( struct V_201 ) *
V_200 -> V_223 ;
if ( ! ( V_203 = F_80 ( V_208 , V_45 ) ) )
return - V_150 ;
if ( F_96 ( V_203 , V_202 , V_208 ) ) {
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
! F_99 ( V_209 ? V_174 : V_231 ,
V_200 -> V_217 , V_200 -> V_216 ) ) {
F_16 ( V_203 ) ;
F_16 ( V_206 ) ;
return - V_33 ;
}
V_44 = F_13 ( V_200 -> V_223 ) ;
if ( ! V_44 ) {
F_16 ( V_203 ) ;
F_16 ( V_206 ) ;
return - V_150 ;
}
if ( V_200 -> V_216 > 0 ) {
V_44 -> V_46 -> V_49 = F_80 ( V_200 -> V_216 ,
V_45 ) ;
if ( ! V_44 -> V_46 -> V_49 ) {
F_16 ( V_203 ) ;
F_16 ( V_206 ) ;
F_17 ( V_44 ) ;
return - V_150 ;
}
if ( V_209 && V_200 -> type == V_230 )
memset ( V_44 -> V_46 -> V_49 , 0 ,
V_200 -> V_216 ) ;
}
V_44 -> V_46 -> V_4 = V_2 -> V_4 ;
V_44 -> V_46 -> V_59 = ( V_200 -> type << 30 ) |
F_132 ( V_2 -> V_4 , V_200 -> V_130 & 0xf ) |
( V_200 -> V_130 & V_123 ) ;
V_194 = ( V_209 ? V_232 : V_233 ) ;
if ( V_200 -> V_51 & V_210 )
V_194 |= V_234 ;
if ( V_200 -> V_51 & V_211 )
V_194 |= V_235 ;
if ( V_200 -> V_51 & V_213 )
V_194 |= V_236 ;
if ( V_200 -> V_51 & V_214 )
V_194 |= V_237 ;
if ( V_200 -> V_51 & V_215 )
V_194 |= V_238 ;
V_44 -> V_46 -> V_93 = V_194 ;
V_44 -> V_46 -> V_239 = V_200 -> V_216 ;
V_44 -> V_46 -> V_50 = ( unsigned char * ) V_206 ;
V_44 -> V_46 -> V_240 = V_200 -> V_240 ;
V_44 -> V_46 -> V_223 = V_200 -> V_223 ;
if ( V_200 -> type == V_230 ||
V_2 -> V_4 -> V_190 == V_241 )
V_44 -> V_46 -> V_242 = 1 << F_11 ( 15 , V_67 -> V_41 . V_243 - 1 ) ;
else
V_44 -> V_46 -> V_242 = V_67 -> V_41 . V_243 ;
V_44 -> V_46 -> V_80 = V_44 ;
V_44 -> V_46 -> V_244 = V_55 ;
for ( V_207 = V_194 = 0 ; V_194 < V_200 -> V_223 ; V_194 ++ ) {
V_44 -> V_46 -> V_202 [ V_194 ] . V_8 = V_207 ;
V_44 -> V_46 -> V_202 [ V_194 ] . V_38 = V_203 [ V_194 ] . V_38 ;
V_207 += V_203 [ V_194 ] . V_38 ;
}
F_16 ( V_203 ) ;
V_44 -> V_2 = V_2 ;
V_44 -> V_57 = V_162 ;
if ( V_209 && V_200 -> V_216 > 0 )
V_44 -> V_245 = V_200 -> V_217 ;
else
V_44 -> V_245 = NULL ;
V_44 -> V_84 = V_200 -> V_84 ;
V_44 -> V_100 = V_100 ;
V_44 -> V_47 = F_42 ( F_87 ( V_115 ) ) ;
V_44 -> V_48 = F_88 () ;
F_89 ( V_115 , & V_44 -> V_83 ) ;
if ( ! V_209 && V_200 -> V_216 > 0 ) {
if ( F_96 ( V_44 -> V_46 -> V_49 , V_200 -> V_217 ,
V_200 -> V_216 ) ) {
F_17 ( V_44 ) ;
return - V_33 ;
}
}
F_31 ( V_2 -> V_4 , V_44 -> V_57 , V_44 -> V_46 -> V_59 ,
V_44 -> V_46 -> V_239 , 0 , V_71 ,
V_209 ? NULL : V_44 -> V_46 -> V_49 ,
V_200 -> V_216 ) ;
F_21 ( V_44 ) ;
if ( F_133 ( & V_67 -> V_41 ) ) {
F_134 ( & V_2 -> V_52 ) ;
V_44 -> V_74 = F_135 ( & V_67 -> V_41 ) |
( ( V_67 -> V_41 . V_131 & V_219 )
>> 3 ) ;
if ( V_200 -> V_51 & V_212 )
V_44 -> V_75 = V_76 ;
else
V_2 -> V_79 &= ~ ( 1 << V_44 -> V_74 ) ;
if ( V_2 -> V_79 & ( 1 << V_44 -> V_74 ) )
V_10 = - V_246 ;
else
V_10 = F_136 ( V_44 -> V_46 , V_247 ) ;
F_137 ( & V_2 -> V_52 ) ;
} else {
V_10 = F_136 ( V_44 -> V_46 , V_45 ) ;
}
if ( V_10 ) {
F_105 ( V_72 , & V_2 -> V_4 -> V_4 ,
L_27 , V_10 ) ;
F_31 ( V_2 -> V_4 , V_44 -> V_57 , V_44 -> V_46 -> V_59 ,
0 , V_10 , V_92 , NULL , 0 ) ;
F_25 ( V_44 ) ;
F_17 ( V_44 ) ;
return V_10 ;
}
return 0 ;
}
static int F_138 ( struct V_1 * V_2 , void T_3 * V_162 )
{
struct V_199 V_200 ;
if ( F_96 ( & V_200 , V_162 , sizeof( V_200 ) ) )
return - V_33 ;
return F_126 ( V_2 , & V_200 ,
( ( (struct V_199 T_3 * ) V_162 ) -> V_202 ) ,
V_162 ) ;
}
static int F_139 ( struct V_1 * V_2 , void T_3 * V_162 )
{
struct V_42 * V_44 ;
V_44 = F_29 ( V_2 , V_162 ) ;
if ( ! V_44 )
return - V_15 ;
F_48 ( V_44 -> V_46 ) ;
return 0 ;
}
static int F_140 ( struct V_42 * V_44 , void T_3 * T_3 * V_162 )
{
struct V_46 * V_46 = V_44 -> V_46 ;
struct V_199 T_3 * V_57 = V_44 -> V_57 ;
void T_3 * V_248 = V_44 -> V_57 ;
unsigned int V_23 ;
if ( V_44 -> V_245 && V_46 -> V_91 ) {
if ( V_46 -> V_223 > 0 )
V_23 = V_46 -> V_239 ;
else
V_23 = V_46 -> V_91 ;
if ( F_9 ( V_44 -> V_245 , V_46 -> V_49 , V_23 ) )
goto V_249;
}
if ( F_141 ( V_44 -> V_85 , & V_57 -> V_85 ) )
goto V_249;
if ( F_141 ( V_46 -> V_91 , & V_57 -> V_91 ) )
goto V_249;
if ( F_141 ( V_46 -> V_250 , & V_57 -> V_250 ) )
goto V_249;
if ( F_131 ( & V_46 -> V_67 -> V_41 ) ) {
for ( V_23 = 0 ; V_23 < V_46 -> V_223 ; V_23 ++ ) {
if ( F_141 ( V_46 -> V_202 [ V_23 ] . V_91 ,
& V_57 -> V_202 [ V_23 ] . V_91 ) )
goto V_249;
if ( F_141 ( V_46 -> V_202 [ V_23 ] . V_85 ,
& V_57 -> V_202 [ V_23 ] . V_85 ) )
goto V_249;
}
}
if ( F_141 ( V_248 , ( void T_3 * T_3 * ) V_162 ) )
return - V_33 ;
return 0 ;
V_249:
return - V_33 ;
}
static struct V_42 * F_142 ( struct V_1 * V_2 )
{
F_143 ( V_98 , V_115 ) ;
struct V_42 * V_44 = NULL ;
struct V_20 * V_4 = V_2 -> V_4 ;
F_144 ( & V_2 -> V_98 , & V_98 ) ;
for (; ; ) {
F_145 ( V_251 ) ;
V_44 = F_27 ( V_2 ) ;
if ( V_44 )
break;
if ( F_146 ( V_115 ) )
break;
F_12 ( V_4 ) ;
F_147 () ;
F_7 ( V_4 ) ;
}
F_148 ( & V_2 -> V_98 , & V_98 ) ;
F_149 ( V_252 ) ;
return V_44 ;
}
static int F_150 ( struct V_1 * V_2 , void T_3 * V_162 )
{
struct V_42 * V_44 = F_142 ( V_2 ) ;
if ( V_44 ) {
int V_253 = F_140 ( V_44 , ( void T_3 * T_3 * ) V_162 ) ;
F_17 ( V_44 ) ;
return V_253 ;
}
if ( F_146 ( V_115 ) )
return - V_254 ;
return - V_255 ;
}
static int F_151 ( struct V_1 * V_2 , void T_3 * V_162 )
{
int V_253 ;
struct V_42 * V_44 ;
V_44 = F_27 ( V_2 ) ;
V_253 = - V_256 ;
if ( V_44 ) {
V_253 = F_140 ( V_44 , ( void T_3 * T_3 * ) V_162 ) ;
F_17 ( V_44 ) ;
}
return V_253 ;
}
static int F_152 ( struct V_1 * V_2 ,
struct V_257 T_3 * V_258 )
{
struct V_163 T_3 * V_101 ;
T_7 V_259 ;
V_101 = F_153 ( sizeof( * V_101 ) ) ;
if ( F_154 ( V_101 , V_258 , ( sizeof( * V_258 ) - sizeof( V_260 ) ) ) ||
F_112 ( V_259 , & V_258 -> V_63 ) ||
F_141 ( F_155 ( V_259 ) , & V_101 -> V_63 ) )
return - V_33 ;
return F_95 ( V_2 , V_101 ) ;
}
static int F_156 ( struct V_1 * V_2 ,
struct V_261 T_3 * V_258 )
{
struct V_176 T_3 * V_101 ;
T_8 V_262 ;
V_260 V_248 ;
V_101 = F_153 ( sizeof( * V_101 ) ) ;
if ( F_112 ( V_262 , & V_258 -> V_67 ) || F_141 ( V_262 , & V_101 -> V_67 ) ||
F_112 ( V_262 , & V_258 -> V_21 ) || F_141 ( V_262 , & V_101 -> V_21 ) ||
F_112 ( V_262 , & V_258 -> V_172 ) || F_141 ( V_262 , & V_101 -> V_172 ) ||
F_112 ( V_248 , & V_258 -> V_63 ) || F_141 ( F_155 ( V_248 ) , & V_101 -> V_63 ) )
return - V_33 ;
return F_106 ( V_2 , V_101 ) ;
}
static int F_157 ( struct V_1 * V_2 , void T_3 * V_162 )
{
struct V_263 V_264 ;
if ( F_96 ( & V_264 , V_162 , sizeof( V_264 ) ) )
return - V_33 ;
V_2 -> V_158 = V_264 . V_84 ;
V_2 -> V_160 = F_155 ( V_264 . V_80 ) ;
return 0 ;
}
static int F_158 ( struct V_199 * V_265 ,
struct V_266 T_3 * V_200 )
{
T_7 V_267 ;
if ( ! F_99 ( V_231 , V_200 , sizeof( * V_200 ) ) ||
F_159 ( V_265 -> type , & V_200 -> type ) ||
F_159 ( V_265 -> V_130 , & V_200 -> V_130 ) ||
F_159 ( V_265 -> V_85 , & V_200 -> V_85 ) ||
F_159 ( V_265 -> V_51 , & V_200 -> V_51 ) ||
F_159 ( V_265 -> V_216 , & V_200 -> V_216 ) ||
F_159 ( V_265 -> V_91 , & V_200 -> V_91 ) ||
F_159 ( V_265 -> V_240 , & V_200 -> V_240 ) ||
F_159 ( V_265 -> V_223 , & V_200 -> V_223 ) ||
F_159 ( V_265 -> V_250 , & V_200 -> V_250 ) ||
F_159 ( V_265 -> V_84 , & V_200 -> V_84 ) )
return - V_33 ;
if ( F_159 ( V_267 , & V_200 -> V_217 ) )
return - V_33 ;
V_265 -> V_217 = F_155 ( V_267 ) ;
if ( F_159 ( V_267 , & V_200 -> V_268 ) )
return - V_33 ;
V_265 -> V_268 = F_155 ( V_267 ) ;
return 0 ;
}
static int F_160 ( struct V_1 * V_2 , void T_3 * V_162 )
{
struct V_199 V_200 ;
if ( F_158 ( & V_200 , (struct V_266 T_3 * ) V_162 ) )
return - V_33 ;
return F_126 ( V_2 , & V_200 ,
( (struct V_266 T_3 * ) V_162 ) -> V_202 ,
V_162 ) ;
}
static int F_161 ( struct V_42 * V_44 , void T_3 * T_3 * V_162 )
{
struct V_46 * V_46 = V_44 -> V_46 ;
struct V_266 T_3 * V_57 = V_44 -> V_57 ;
void T_3 * V_248 = V_44 -> V_57 ;
unsigned int V_23 ;
if ( V_44 -> V_245 && V_46 -> V_91 )
if ( F_9 ( V_44 -> V_245 , V_46 -> V_49 ,
V_46 -> V_91 ) )
return - V_33 ;
if ( F_141 ( V_44 -> V_85 , & V_57 -> V_85 ) )
return - V_33 ;
if ( F_141 ( V_46 -> V_91 , & V_57 -> V_91 ) )
return - V_33 ;
if ( F_141 ( V_46 -> V_250 , & V_57 -> V_250 ) )
return - V_33 ;
if ( F_131 ( & V_46 -> V_67 -> V_41 ) ) {
for ( V_23 = 0 ; V_23 < V_46 -> V_223 ; V_23 ++ ) {
if ( F_141 ( V_46 -> V_202 [ V_23 ] . V_91 ,
& V_57 -> V_202 [ V_23 ] . V_91 ) )
return - V_33 ;
if ( F_141 ( V_46 -> V_202 [ V_23 ] . V_85 ,
& V_57 -> V_202 [ V_23 ] . V_85 ) )
return - V_33 ;
}
}
if ( F_141 ( F_162 ( V_248 ) , ( T_5 T_3 * ) V_162 ) )
return - V_33 ;
return 0 ;
}
static int F_163 ( struct V_1 * V_2 , void T_3 * V_162 )
{
struct V_42 * V_44 = F_142 ( V_2 ) ;
if ( V_44 ) {
int V_253 = F_161 ( V_44 , ( void T_3 * T_3 * ) V_162 ) ;
F_17 ( V_44 ) ;
return V_253 ;
}
if ( F_146 ( V_115 ) )
return - V_254 ;
return - V_255 ;
}
static int F_164 ( struct V_1 * V_2 , void T_3 * V_162 )
{
int V_253 ;
struct V_42 * V_44 ;
V_253 = - V_256 ;
V_44 = F_27 ( V_2 ) ;
if ( V_44 ) {
V_253 = F_161 ( V_44 , ( void T_3 * T_3 * ) V_162 ) ;
F_17 ( V_44 ) ;
}
return V_253 ;
}
static int F_165 ( struct V_1 * V_2 , void T_3 * V_162 )
{
struct V_269 V_264 ;
if ( F_96 ( & V_264 , V_162 , sizeof( V_264 ) ) )
return - V_33 ;
V_2 -> V_158 = V_264 . V_84 ;
V_2 -> V_160 = V_264 . V_80 ;
return 0 ;
}
static int F_166 ( struct V_1 * V_2 , void T_3 * V_162 )
{
unsigned int V_100 ;
if ( F_112 ( V_100 , ( unsigned int T_3 * ) V_162 ) )
return - V_33 ;
return F_62 ( V_2 , V_100 ) ;
}
static int F_167 ( struct V_1 * V_2 , void T_3 * V_162 )
{
unsigned int V_100 ;
int V_10 ;
if ( F_112 ( V_100 , ( unsigned int T_3 * ) V_162 ) )
return - V_33 ;
if ( ( V_10 = F_67 ( V_2 , V_100 ) ) < 0 )
return V_10 ;
F_49 ( V_2 , V_100 ) ;
return 0 ;
}
static int F_168 ( struct V_1 * V_2 , struct V_270 * V_271 )
{
int V_272 ;
void * V_16 = NULL ;
int V_253 = 0 ;
struct V_104 * V_105 = NULL ;
struct V_273 * V_183 = NULL ;
if ( ( V_272 = F_169 ( V_271 -> V_274 ) ) > 0 ) {
if ( ( V_16 = F_80 ( V_272 , V_45 ) ) == NULL )
return - V_150 ;
if ( ( F_170 ( V_271 -> V_274 ) & V_275 ) ) {
if ( F_96 ( V_16 , V_271 -> V_63 , V_272 ) ) {
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
if ( V_2 -> V_4 -> V_5 != V_113 )
V_253 = - V_114 ;
else if ( ! ( V_105 = F_64 ( V_2 -> V_4 , V_271 -> V_276 ) ) )
V_253 = - V_15 ;
else switch ( V_271 -> V_274 ) {
case V_277 :
if ( V_105 -> V_4 . V_183 ) {
V_183 = F_171 ( V_105 -> V_4 . V_183 ) ;
F_172 ( & V_105 -> V_4 , L_28 ) ;
F_69 ( V_183 , V_105 ) ;
} else
V_253 = - V_184 ;
break;
case V_278 :
if ( ! V_105 -> V_4 . V_183 )
V_253 = F_173 ( & V_105 -> V_4 ) ;
else
V_253 = - V_197 ;
break;
default:
if ( V_105 -> V_4 . V_183 )
V_183 = F_171 ( V_105 -> V_4 . V_183 ) ;
if ( V_183 == NULL || V_183 -> V_279 == NULL ) {
V_253 = - V_280 ;
} else {
V_253 = V_183 -> V_279 ( V_105 , V_271 -> V_274 , V_16 ) ;
if ( V_253 == - V_281 )
V_253 = - V_280 ;
}
}
if ( V_253 >= 0
&& ( F_170 ( V_271 -> V_274 ) & V_282 ) != 0
&& V_272 > 0
&& F_9 ( V_271 -> V_63 , V_16 , V_272 ) != 0 )
V_253 = - V_33 ;
F_16 ( V_16 ) ;
return V_253 ;
}
static int F_174 ( struct V_1 * V_2 , void T_3 * V_162 )
{
struct V_270 V_164 ;
if ( F_96 ( & V_164 , V_162 , sizeof( V_164 ) ) )
return - V_33 ;
return F_168 ( V_2 , & V_164 ) ;
}
static int F_175 ( struct V_1 * V_2 , T_9 V_162 )
{
struct V_283 T_3 * V_284 ;
struct V_270 V_164 ;
T_5 V_259 ;
V_284 = F_155 ( ( long ) V_162 ) ;
if ( ! F_99 ( V_231 , V_284 , sizeof( * V_284 ) ) ||
F_159 ( V_164 . V_276 , & V_284 -> V_276 ) ||
F_159 ( V_164 . V_274 , & V_284 -> V_274 ) ||
F_159 ( V_259 , & V_284 -> V_63 ) )
return - V_33 ;
V_164 . V_63 = F_155 ( V_259 ) ;
return F_168 ( V_2 , & V_164 ) ;
}
static int F_176 ( struct V_1 * V_2 , void T_3 * V_162 )
{
unsigned V_285 ;
int V_286 ;
if ( F_112 ( V_285 , ( unsigned T_3 * ) V_162 ) )
return - V_33 ;
V_286 = F_177 ( V_2 -> V_4 , V_285 , V_2 ) ;
if ( V_286 == 0 )
F_44 ( & V_2 -> V_4 -> V_4 , L_29 ,
V_285 , F_71 ( V_115 ) , V_115 -> V_116 ) ;
return V_286 ;
}
static int F_178 ( struct V_1 * V_2 , void T_3 * V_162 )
{
unsigned V_285 ;
if ( F_112 ( V_285 , ( unsigned T_3 * ) V_162 ) )
return - V_33 ;
return F_179 ( V_2 -> V_4 , V_285 , V_2 ) ;
}
static long F_180 ( struct V_7 * V_7 , unsigned int V_287 ,
void T_3 * V_101 )
{
struct V_1 * V_2 = V_7 -> V_19 ;
struct V_149 * V_149 = V_7 -> V_288 . V_289 -> V_12 ;
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
F_44 ( & V_4 -> V_4 , L_30 , V_294 ) ;
V_10 = F_95 ( V_2 , V_101 ) ;
if ( V_10 >= 0 )
V_149 -> V_295 = V_296 ;
break;
case V_297 :
F_44 ( & V_4 -> V_4 , L_31 , V_294 ) ;
V_10 = F_106 ( V_2 , V_101 ) ;
if ( V_10 >= 0 )
V_149 -> V_295 = V_296 ;
break;
case V_298 :
F_44 ( & V_4 -> V_4 , L_32 , V_294 ) ;
V_10 = F_111 ( V_2 , V_101 ) ;
if ( V_10 >= 0 )
V_149 -> V_295 = V_296 ;
break;
case V_299 :
F_44 ( & V_4 -> V_4 , L_33 , V_294 ) ;
V_10 = F_118 ( V_2 ) ;
break;
case V_300 :
F_44 ( & V_4 -> V_4 , L_34 , V_294 ) ;
V_10 = F_114 ( V_2 , V_101 ) ;
if ( V_10 >= 0 )
V_149 -> V_295 = V_296 ;
break;
case V_301 :
F_44 ( & V_4 -> V_4 , L_35 , V_294 ) ;
V_10 = F_116 ( V_2 , V_101 ) ;
break;
case V_302 :
F_44 ( & V_4 -> V_4 , L_36 , V_294 ) ;
V_10 = F_117 ( V_2 , V_101 ) ;
break;
case V_303 :
F_44 ( & V_4 -> V_4 , L_37 , V_294 ) ;
V_10 = F_120 ( V_2 , V_101 ) ;
break;
case V_304 :
F_44 ( & V_4 -> V_4 , L_38 , V_294 ) ;
V_10 = F_122 ( V_2 , V_101 ) ;
break;
case V_305 :
F_44 ( & V_4 -> V_4 , L_39 , V_294 ) ;
V_10 = F_138 ( V_2 , V_101 ) ;
if ( V_10 >= 0 )
V_149 -> V_295 = V_296 ;
break;
#ifdef F_181
case V_306 :
F_44 ( & V_4 -> V_4 , L_40 , V_294 ) ;
V_10 = F_152 ( V_2 , V_101 ) ;
if ( V_10 >= 0 )
V_149 -> V_295 = V_296 ;
break;
case V_307 :
F_44 ( & V_4 -> V_4 , L_41 , V_294 ) ;
V_10 = F_156 ( V_2 , V_101 ) ;
if ( V_10 >= 0 )
V_149 -> V_295 = V_296 ;
break;
case V_308 :
F_44 ( & V_4 -> V_4 , L_42 , V_294 ) ;
V_10 = F_157 ( V_2 , V_101 ) ;
break;
case V_309 :
F_44 ( & V_4 -> V_4 , L_43 , V_294 ) ;
V_10 = F_160 ( V_2 , V_101 ) ;
if ( V_10 >= 0 )
V_149 -> V_295 = V_296 ;
break;
case V_310 :
F_44 ( & V_4 -> V_4 , L_44 , V_294 ) ;
V_10 = F_163 ( V_2 , V_101 ) ;
break;
case V_311 :
F_44 ( & V_4 -> V_4 , L_45 , V_294 ) ;
V_10 = F_164 ( V_2 , V_101 ) ;
break;
case V_312 :
F_44 ( & V_4 -> V_4 , L_46 , V_294 ) ;
V_10 = F_175 ( V_2 , F_162 ( V_101 ) ) ;
break;
#endif
case V_313 :
F_44 ( & V_4 -> V_4 , L_47 , V_294 ) ;
V_10 = F_139 ( V_2 , V_101 ) ;
break;
case V_314 :
F_44 ( & V_4 -> V_4 , L_48 , V_294 ) ;
V_10 = F_150 ( V_2 , V_101 ) ;
break;
case V_315 :
F_44 ( & V_4 -> V_4 , L_49 , V_294 ) ;
V_10 = F_151 ( V_2 , V_101 ) ;
break;
case V_316 :
F_44 ( & V_4 -> V_4 , L_50 , V_294 ) ;
V_10 = F_165 ( V_2 , V_101 ) ;
break;
case V_317 :
F_44 ( & V_4 -> V_4 , L_51 , V_294 ) ;
V_10 = F_166 ( V_2 , V_101 ) ;
break;
case V_318 :
F_44 ( & V_4 -> V_4 , L_52 , V_294 ) ;
V_10 = F_167 ( V_2 , V_101 ) ;
break;
case V_319 :
F_44 ( & V_4 -> V_4 , L_53 , V_294 ) ;
V_10 = F_174 ( V_2 , V_101 ) ;
break;
case V_320 :
F_44 ( & V_4 -> V_4 , L_54 , V_294 ) ;
V_10 = F_176 ( V_2 , V_101 ) ;
break;
case V_321 :
F_44 ( & V_4 -> V_4 , L_55 , V_294 ) ;
V_10 = F_178 ( V_2 , V_101 ) ;
break;
}
F_12 ( V_4 ) ;
if ( V_10 >= 0 )
V_149 -> V_322 = V_296 ;
return V_10 ;
}
static long F_182 ( struct V_7 * V_7 , unsigned int V_287 ,
unsigned long V_162 )
{
int V_10 ;
V_10 = F_180 ( V_7 , V_287 , ( void T_3 * ) V_162 ) ;
return V_10 ;
}
static long F_183 ( struct V_7 * V_7 , unsigned int V_287 ,
unsigned long V_162 )
{
int V_10 ;
V_10 = F_180 ( V_7 , V_287 , F_155 ( V_162 ) ) ;
return V_10 ;
}
static unsigned int F_184 ( struct V_7 * V_7 ,
struct V_323 * V_98 )
{
struct V_1 * V_2 = V_7 -> V_19 ;
unsigned int V_324 = 0 ;
F_185 ( V_7 , & V_2 -> V_98 , V_98 ) ;
if ( V_7 -> V_290 & V_291 && ! F_2 ( & V_2 -> V_55 ) )
V_324 |= V_325 | V_326 ;
if ( ! F_1 ( V_2 ) )
V_324 |= V_327 | V_328 ;
return V_324 ;
}
static void F_186 ( struct V_20 * V_58 )
{
struct V_1 * V_2 ;
struct V_81 V_82 ;
while ( ! F_2 ( & V_58 -> V_161 ) ) {
V_2 = F_28 ( V_58 -> V_161 . V_56 , struct V_1 , V_3 ) ;
F_52 ( V_2 ) ;
F_187 ( & V_2 -> V_98 ) ;
F_26 ( & V_2 -> V_3 ) ;
if ( V_2 -> V_158 ) {
V_82 . V_86 = V_2 -> V_158 ;
V_82 . V_87 = V_175 ;
V_82 . V_88 = V_89 ;
V_82 . V_90 = V_2 -> V_160 ;
F_45 ( V_2 -> V_158 , & V_82 ,
V_2 -> V_159 , V_2 -> V_48 , V_2 -> V_83 ) ;
}
}
}
static int F_188 ( struct V_20 * V_4 )
{
struct V_145 * V_329 ;
V_329 = F_189 ( V_330 , & V_4 -> V_4 , V_4 -> V_4 . V_146 ,
NULL , L_56 , V_4 -> V_331 -> V_332 ,
V_4 -> V_188 ) ;
if ( F_190 ( V_329 ) )
return F_191 ( V_329 ) ;
V_4 -> V_333 = V_329 ;
return 0 ;
}
static void F_192 ( struct V_20 * V_4 )
{
if ( V_4 -> V_333 )
F_193 ( V_4 -> V_333 ) ;
}
static int F_194 ( struct V_334 * V_335 ,
unsigned long V_336 , void * V_4 )
{
switch ( V_336 ) {
case V_337 :
if ( F_188 ( V_4 ) )
return V_338 ;
break;
case V_339 :
F_192 ( V_4 ) ;
F_186 ( V_4 ) ;
break;
}
return V_340 ;
}
int T_10 F_195 ( void )
{
int V_253 ;
V_253 = F_196 ( V_341 , V_342 ,
L_57 ) ;
if ( V_253 ) {
F_197 ( V_343 L_58 ) ;
goto V_344;
}
F_198 ( & V_345 , & V_346 ) ;
V_253 = F_199 ( & V_345 , V_341 , V_342 ) ;
if ( V_253 ) {
F_197 ( V_343 L_59 ,
V_153 ) ;
goto V_347;
}
#ifdef F_200
V_330 = F_201 ( V_348 , L_57 ) ;
if ( F_190 ( V_330 ) ) {
F_197 ( V_343 L_60 ) ;
V_253 = F_191 ( V_330 ) ;
F_202 ( & V_345 ) ;
V_330 = NULL ;
goto V_344;
}
V_330 -> V_349 = NULL ;
#endif
F_203 ( & V_350 ) ;
V_344:
return V_253 ;
V_347:
F_204 ( V_341 , V_342 ) ;
goto V_344;
}
void F_205 ( void )
{
F_206 ( & V_350 ) ;
#ifdef F_200
F_207 ( V_330 ) ;
#endif
F_202 ( & V_345 ) ;
F_204 ( V_341 , V_342 ) ;
}
