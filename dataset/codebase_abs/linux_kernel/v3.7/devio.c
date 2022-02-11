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
int V_29 ;
F_24 ( V_50 -> V_53 ) ;
if ( V_50 -> V_54 )
F_25 ( V_50 -> V_54 ) ;
for ( V_29 = 0 ; V_29 < V_50 -> V_52 -> V_55 ; V_29 ++ ) {
if ( F_26 ( & V_50 -> V_52 -> V_56 [ V_29 ] ) )
F_22 ( F_27 ( & V_50 -> V_52 -> V_56 [ V_29 ] ) ) ;
}
F_22 ( V_50 -> V_52 -> V_56 ) ;
F_22 ( V_50 -> V_52 -> V_57 ) ;
F_22 ( V_50 -> V_52 -> V_58 ) ;
F_28 ( V_50 -> V_52 ) ;
F_6 ( V_50 -> V_59 ) ;
F_22 ( V_50 ) ;
}
static void F_29 ( struct V_48 * V_50 )
{
struct V_7 * V_8 = V_50 -> V_8 ;
unsigned long V_60 ;
F_30 ( & V_8 -> V_61 , V_60 ) ;
F_31 ( & V_50 -> V_62 , & V_8 -> V_63 ) ;
F_32 ( & V_8 -> V_61 , V_60 ) ;
}
static void F_33 ( struct V_48 * V_50 )
{
struct V_7 * V_8 = V_50 -> V_8 ;
unsigned long V_60 ;
F_30 ( & V_8 -> V_61 , V_60 ) ;
F_34 ( & V_50 -> V_62 ) ;
F_32 ( & V_8 -> V_61 , V_60 ) ;
}
static struct V_48 * F_35 ( struct V_7 * V_8 )
{
unsigned long V_60 ;
struct V_48 * V_50 = NULL ;
F_30 ( & V_8 -> V_61 , V_60 ) ;
if ( ! F_8 ( & V_8 -> V_64 ) ) {
V_50 = F_36 ( V_8 -> V_64 . V_65 , struct V_48 ,
V_62 ) ;
F_34 ( & V_50 -> V_62 ) ;
}
F_32 ( & V_8 -> V_61 , V_60 ) ;
return V_50 ;
}
static struct V_48 * F_37 ( struct V_7 * V_8 ,
void T_3 * V_66 )
{
struct V_48 * V_50 ;
F_38 (as, &ps->async_pending, asynclist)
if ( V_50 -> V_66 == V_66 ) {
F_34 ( & V_50 -> V_62 ) ;
return V_50 ;
}
return NULL ;
}
static void F_39 ( struct V_26 * V_67 ,
void T_3 * V_66 , int V_68 , unsigned V_44 ,
int V_69 , enum V_70 V_71 ,
unsigned char * V_72 , unsigned V_73 )
{
static const char * V_74 [] = { L_1 , L_2 , L_3 , L_4 } ;
static const char * V_75 [] = { L_5 , L_6 } ;
int V_76 ;
const char * V_77 , * V_78 ;
if ( ! V_79 )
return;
V_76 = F_40 ( V_68 ) ;
V_77 = V_74 [ F_41 ( V_68 ) ] ;
V_78 = V_75 [ ! ! F_42 ( V_68 ) ] ;
if ( V_66 ) {
if ( V_71 == V_80 )
F_43 ( & V_67 -> V_10 , L_7
L_8 ,
V_66 , V_76 , V_77 , V_78 , V_44 ) ;
else
F_43 ( & V_67 -> V_10 , L_7
L_9 ,
V_66 , V_76 , V_77 , V_78 , V_44 ,
V_69 ) ;
} else {
if ( V_71 == V_80 )
F_43 ( & V_67 -> V_10 , L_10
L_11 ,
V_76 , V_77 , V_78 , V_44 , V_69 ) ;
else
F_43 ( & V_67 -> V_10 , L_12
L_13 ,
V_76 , V_77 , V_78 , V_44 , V_69 ) ;
}
if ( V_72 && V_73 > 0 ) {
F_44 ( V_81 , L_14 , V_82 , 32 , 1 ,
V_72 , V_73 , 1 ) ;
}
}
static void F_45 ( struct V_52 * V_52 , unsigned V_27 )
{
int V_29 , V_83 ;
if ( ! V_79 )
return;
if ( V_52 -> V_55 == 0 ) {
F_44 ( V_81 , L_14 , V_82 , 32 , 1 ,
V_52 -> V_57 , V_27 , 1 ) ;
return;
}
for ( V_29 = 0 ; V_29 < V_52 -> V_55 && V_27 ; V_29 ++ ) {
V_83 = ( V_27 > V_84 ) ? V_84 : V_27 ;
F_44 ( V_81 , L_14 , V_82 , 32 , 1 ,
F_27 ( & V_52 -> V_56 [ V_29 ] ) , V_83 , 1 ) ;
V_27 -= V_83 ;
}
}
static int F_46 ( T_5 T_3 * V_85 , struct V_52 * V_52 )
{
unsigned V_29 , V_27 , V_83 ;
if ( V_52 -> V_86 > 0 )
V_27 = V_52 -> V_87 ;
else
V_27 = V_52 -> V_88 ;
if ( V_52 -> V_55 == 0 ) {
if ( F_15 ( V_85 , V_52 -> V_57 , V_27 ) )
return - V_39 ;
return 0 ;
}
for ( V_29 = 0 ; V_29 < V_52 -> V_55 && V_27 ; V_29 ++ ) {
V_83 = ( V_27 > V_84 ) ? V_84 : V_27 ;
if ( F_15 ( V_85 , F_27 ( & V_52 -> V_56 [ V_29 ] ) , V_83 ) )
return - V_39 ;
V_85 += V_83 ;
V_27 -= V_83 ;
}
return 0 ;
}
static void F_47 ( struct V_7 * V_8 , unsigned V_89 )
__releases( V_8 -> V_61 )
__acquires( V_8 -> V_61 )
{
struct V_52 * V_52 ;
struct V_48 * V_50 ;
F_38 (as, &ps->async_pending, asynclist) {
if ( V_50 -> V_89 == V_89 ) {
if ( V_50 -> V_90 != V_91 )
goto V_92;
V_50 -> V_90 = V_93 ;
V_50 -> V_89 = 0 ;
}
}
V_8 -> V_94 |= ( 1 << V_89 ) ;
V_92:
F_38 (as, &ps->async_pending, asynclist) {
if ( V_50 -> V_90 == V_93 ) {
V_50 -> V_90 = 0 ;
V_52 = V_50 -> V_52 ;
F_48 ( V_52 ) ;
F_49 ( & V_8 -> V_61 ) ;
F_50 ( V_52 ) ;
F_51 ( V_52 ) ;
F_52 ( & V_8 -> V_61 ) ;
goto V_92;
}
}
}
static void V_64 ( struct V_52 * V_52 )
{
struct V_48 * V_50 = V_52 -> V_95 ;
struct V_7 * V_8 = V_50 -> V_8 ;
struct V_96 V_97 ;
struct V_53 * V_53 = NULL ;
T_6 V_98 = 0 ;
const struct V_54 * V_54 = NULL ;
int V_99 ;
F_52 ( & V_8 -> V_61 ) ;
F_53 ( & V_50 -> V_62 , & V_8 -> V_64 ) ;
V_50 -> V_100 = V_52 -> V_100 ;
V_99 = V_50 -> V_99 ;
if ( V_99 ) {
V_97 . V_101 = V_50 -> V_99 ;
V_97 . V_102 = V_50 -> V_100 ;
V_97 . V_103 = V_104 ;
V_97 . V_105 = V_50 -> V_66 ;
V_53 = F_54 ( V_50 -> V_53 ) ;
V_54 = F_55 ( V_50 -> V_54 ) ;
V_98 = V_50 -> V_98 ;
}
F_56 ( & V_52 -> V_10 -> V_10 , L_15 ) ;
F_39 ( V_52 -> V_10 , V_50 -> V_66 , V_52 -> V_68 , V_52 -> V_88 ,
V_50 -> V_100 , V_106 , NULL , 0 ) ;
if ( ( V_52 -> V_107 & V_108 ) == V_109 )
F_45 ( V_52 , V_52 -> V_88 ) ;
if ( V_50 -> V_100 < 0 && V_50 -> V_89 && V_50 -> V_100 != - V_110 &&
V_50 -> V_100 != - V_111 )
F_47 ( V_8 , V_50 -> V_89 ) ;
F_49 ( & V_8 -> V_61 ) ;
if ( V_99 ) {
F_57 ( V_97 . V_101 , & V_97 , V_53 , V_54 , V_98 ) ;
F_24 ( V_53 ) ;
F_25 ( V_54 ) ;
}
F_58 ( & V_8 -> V_112 ) ;
}
static void F_59 ( struct V_7 * V_8 , struct V_113 * V_9 )
{
struct V_52 * V_52 ;
struct V_48 * V_50 ;
unsigned long V_60 ;
F_30 ( & V_8 -> V_61 , V_60 ) ;
while ( ! F_8 ( V_9 ) ) {
V_50 = F_36 ( V_9 -> V_65 , struct V_48 , V_62 ) ;
F_34 ( & V_50 -> V_62 ) ;
V_52 = V_50 -> V_52 ;
F_48 ( V_52 ) ;
F_32 ( & V_8 -> V_61 , V_60 ) ;
F_60 ( V_52 ) ;
F_51 ( V_52 ) ;
F_30 ( & V_8 -> V_61 , V_60 ) ;
}
F_32 ( & V_8 -> V_61 , V_60 ) ;
}
static void F_61 ( struct V_7 * V_8 ,
unsigned int V_114 )
{
struct V_113 * V_115 , * V_116 , V_117 ;
unsigned long V_60 ;
F_62 ( & V_117 ) ;
F_30 ( & V_8 -> V_61 , V_60 ) ;
F_63 (p, q, &ps->async_pending)
if ( V_114 == F_36 ( V_115 , struct V_48 , V_62 ) -> V_114 )
F_53 ( V_115 , & V_117 ) ;
F_32 ( & V_8 -> V_61 , V_60 ) ;
F_59 ( V_8 , & V_117 ) ;
}
static void F_64 ( struct V_7 * V_8 )
{
F_59 ( V_8 , & V_8 -> V_63 ) ;
}
static int F_65 ( struct V_118 * V_119 ,
const struct V_120 * V_121 )
{
return - V_30 ;
}
static void F_66 ( struct V_118 * V_119 )
{
struct V_7 * V_8 = F_67 ( V_119 ) ;
unsigned int V_114 = V_119 -> V_122 -> V_47 . V_123 ;
if ( ! V_8 )
return;
if ( F_68 ( V_114 < 8 * sizeof( V_8 -> V_124 ) ) )
F_69 ( V_114 , & V_8 -> V_124 ) ;
else
F_70 ( & V_119 -> V_10 , L_16 ,
V_114 ) ;
F_71 ( V_119 , NULL ) ;
F_61 ( V_8 , V_114 ) ;
}
static int F_72 ( struct V_118 * V_119 , T_7 V_125 )
{
return 0 ;
}
static int F_73 ( struct V_118 * V_119 )
{
return 0 ;
}
static int F_74 ( struct V_7 * V_8 , unsigned int V_114 )
{
struct V_26 * V_10 = V_8 -> V_10 ;
struct V_118 * V_119 ;
int V_31 ;
if ( V_114 >= 8 * sizeof( V_8 -> V_124 ) )
return - V_21 ;
if ( F_75 ( V_114 , & V_8 -> V_124 ) )
return 0 ;
V_119 = F_76 ( V_10 , V_114 ) ;
if ( ! V_119 )
V_31 = - V_111 ;
else
V_31 = F_77 ( & V_126 , V_119 , V_8 ) ;
if ( V_31 == 0 )
F_78 ( V_114 , & V_8 -> V_124 ) ;
return V_31 ;
}
static int F_79 ( struct V_7 * V_8 , unsigned int V_114 )
{
struct V_26 * V_10 ;
struct V_118 * V_119 ;
int V_31 ;
V_31 = - V_21 ;
if ( V_114 >= 8 * sizeof( V_8 -> V_124 ) )
return V_31 ;
V_10 = V_8 -> V_10 ;
V_119 = F_76 ( V_10 , V_114 ) ;
if ( ! V_119 )
V_31 = - V_111 ;
else if ( F_80 ( V_114 , & V_8 -> V_124 ) ) {
F_81 ( & V_126 , V_119 ) ;
V_31 = 0 ;
}
return V_31 ;
}
static int F_82 ( struct V_7 * V_8 , unsigned int V_114 )
{
if ( V_8 -> V_10 -> V_11 != V_127 )
return - V_128 ;
if ( V_114 >= 8 * sizeof( V_8 -> V_124 ) )
return - V_21 ;
if ( F_75 ( V_114 , & V_8 -> V_124 ) )
return 0 ;
F_70 ( & V_8 -> V_10 -> V_10 , L_17
L_18 , F_83 ( V_129 ) ,
V_129 -> V_130 , V_114 ) ;
return F_74 ( V_8 , V_114 ) ;
}
static int F_84 ( struct V_26 * V_10 , unsigned int V_76 )
{
unsigned int V_29 , V_131 , V_132 ;
struct V_118 * V_119 ;
struct V_133 * V_134 ;
struct V_135 * V_136 ;
if ( V_76 & ~ ( V_109 | 0xf ) )
return - V_21 ;
if ( ! V_10 -> V_137 )
return - V_138 ;
for ( V_29 = 0 ; V_29 < V_10 -> V_137 -> V_47 . V_139 ; V_29 ++ ) {
V_119 = V_10 -> V_137 -> V_140 [ V_29 ] ;
for ( V_131 = 0 ; V_131 < V_119 -> V_141 ; V_131 ++ ) {
V_134 = & V_119 -> V_122 [ V_131 ] ;
for ( V_132 = 0 ; V_132 < V_134 -> V_47 . V_142 ; V_132 ++ ) {
V_136 = & V_134 -> V_143 [ V_132 ] . V_47 ;
if ( V_136 -> V_144 == V_76 )
return V_134 -> V_47 . V_123 ;
}
}
}
return - V_111 ;
}
static int F_85 ( struct V_7 * V_8 , unsigned int V_145 ,
unsigned int V_146 , unsigned int V_147 )
{
int V_16 = 0 ;
struct V_133 * V_148 ;
if ( V_8 -> V_10 -> V_11 != V_149
&& V_8 -> V_10 -> V_11 != V_150
&& V_8 -> V_10 -> V_11 != V_127 )
return - V_128 ;
if ( V_151 == ( V_152 & V_145 ) )
return 0 ;
if ( V_145 == 0xa1 && V_146 == 0 ) {
V_148 = F_86 ( V_8 -> V_10 -> V_137 ,
V_147 >> 8 , V_147 & 0xff ) ;
if ( V_148
&& V_148 -> V_47 . V_153 == V_154 )
V_147 >>= 8 ;
}
V_147 &= 0xff ;
switch ( V_145 & V_155 ) {
case V_156 :
V_16 = F_84 ( V_8 -> V_10 , V_147 ) ;
if ( V_16 >= 0 )
V_16 = F_82 ( V_8 , V_16 ) ;
break;
case V_157 :
V_16 = F_82 ( V_8 , V_147 ) ;
break;
}
return V_16 ;
}
static int F_87 ( struct V_158 * V_10 , void * V_72 )
{
return V_10 -> V_159 == ( V_160 ) ( unsigned long ) V_72 ;
}
static struct V_26 * F_88 ( V_160 V_159 )
{
struct V_158 * V_10 ;
V_10 = F_89 ( & V_161 , NULL ,
( void * ) ( unsigned long ) V_159 , F_87 ) ;
if ( ! V_10 )
return NULL ;
return F_90 ( V_10 , struct V_26 , V_10 ) ;
}
static int F_91 ( struct V_162 * V_162 , struct V_13 * V_13 )
{
struct V_26 * V_10 = NULL ;
struct V_7 * V_8 ;
int V_16 ;
V_16 = - V_6 ;
V_8 = F_92 ( sizeof( struct V_7 ) , V_51 ) ;
if ( ! V_8 )
goto V_163;
V_16 = - V_30 ;
F_10 ( & V_164 ) ;
if ( F_93 ( V_162 ) == V_165 )
V_10 = F_88 ( V_162 -> V_166 ) ;
F_11 ( & V_164 ) ;
if ( ! V_10 )
goto V_163;
F_13 ( V_10 ) ;
if ( V_10 -> V_11 == V_12 )
goto V_167;
V_16 = F_94 ( V_10 ) ;
if ( V_16 )
goto V_167;
V_8 -> V_10 = V_10 ;
V_8 -> V_13 = V_13 ;
F_95 ( & V_8 -> V_61 ) ;
F_62 ( & V_8 -> V_9 ) ;
F_62 ( & V_8 -> V_63 ) ;
F_62 ( & V_8 -> V_64 ) ;
F_96 ( & V_8 -> V_112 ) ;
V_8 -> V_168 = 0 ;
V_8 -> V_169 = F_54 ( F_97 ( V_129 ) ) ;
V_8 -> V_54 = F_98 () ;
V_8 -> V_170 = NULL ;
V_8 -> V_124 = 0 ;
F_99 ( V_129 , & V_8 -> V_98 ) ;
F_100 () ;
F_31 ( & V_8 -> V_9 , & V_10 -> V_171 ) ;
V_13 -> V_25 = V_8 ;
F_18 ( V_10 ) ;
F_56 ( & V_10 -> V_10 , L_19 , F_83 ( V_129 ) ,
V_129 -> V_130 ) ;
return V_16 ;
V_167:
F_18 ( V_10 ) ;
F_101 ( V_10 ) ;
V_163:
F_22 ( V_8 ) ;
return V_16 ;
}
static int F_102 ( struct V_162 * V_162 , struct V_13 * V_13 )
{
struct V_7 * V_8 = V_13 -> V_25 ;
struct V_26 * V_10 = V_8 -> V_10 ;
unsigned int V_114 ;
struct V_48 * V_50 ;
F_13 ( V_10 ) ;
F_103 ( V_10 , V_8 ) ;
F_34 ( & V_8 -> V_9 ) ;
for ( V_114 = 0 ; V_8 -> V_124 && V_114 < 8 * sizeof( V_8 -> V_124 ) ;
V_114 ++ ) {
if ( F_75 ( V_114 , & V_8 -> V_124 ) )
F_79 ( V_8 , V_114 ) ;
}
F_64 ( V_8 ) ;
F_104 ( V_10 ) ;
F_18 ( V_10 ) ;
F_101 ( V_10 ) ;
F_24 ( V_8 -> V_169 ) ;
F_25 ( V_8 -> V_54 ) ;
V_50 = F_35 ( V_8 ) ;
while ( V_50 ) {
F_23 ( V_50 ) ;
V_50 = F_35 ( V_8 ) ;
}
F_22 ( V_8 ) ;
return 0 ;
}
static int F_105 ( struct V_7 * V_8 , void T_3 * V_172 )
{
struct V_26 * V_10 = V_8 -> V_10 ;
struct V_173 V_174 ;
unsigned int V_175 ;
unsigned char * V_176 ;
unsigned V_177 ;
int V_29 , V_68 , V_16 ;
if ( F_106 ( & V_174 , V_172 , sizeof( V_174 ) ) )
return - V_39 ;
V_16 = F_85 ( V_8 , V_174 . V_178 , V_174 . V_179 ,
V_174 . V_180 ) ;
if ( V_16 )
return V_16 ;
V_177 = V_174 . V_177 ;
if ( V_177 > V_181 )
return - V_21 ;
V_16 = F_1 ( V_181 + sizeof( struct V_52 ) +
sizeof( struct V_182 ) ) ;
if ( V_16 )
return V_16 ;
V_176 = ( unsigned char * ) F_107 ( V_51 ) ;
if ( ! V_176 ) {
V_16 = - V_6 ;
goto V_183;
}
V_175 = V_174 . V_184 ;
F_56 ( & V_10 -> V_10 , L_20
L_21
L_22 ,
V_174 . V_178 , V_174 . V_179 ,
F_108 ( & V_174 . V_185 ) ,
F_108 ( & V_174 . V_180 ) ,
F_108 ( & V_174 . V_177 ) ) ;
if ( V_174 . V_178 & 0x80 ) {
if ( V_174 . V_177 && ! F_109 ( V_186 , V_174 . V_72 ,
V_174 . V_177 ) ) {
V_16 = - V_21 ;
goto V_183;
}
V_68 = F_110 ( V_10 , 0 ) ;
F_39 ( V_10 , NULL , V_68 , V_174 . V_177 , V_175 , V_80 , NULL , 0 ) ;
F_18 ( V_10 ) ;
V_29 = F_111 ( V_10 , V_68 , V_174 . V_179 ,
V_174 . V_178 , V_174 . V_185 , V_174 . V_180 ,
V_176 , V_174 . V_177 , V_175 ) ;
F_13 ( V_10 ) ;
F_39 ( V_10 , NULL , V_68 , F_112 ( V_29 , 0 ) , F_17 ( V_29 , 0 ) , V_106 ,
V_176 , F_112 ( V_29 , 0 ) ) ;
if ( ( V_29 > 0 ) && V_174 . V_177 ) {
if ( F_15 ( V_174 . V_72 , V_176 , V_29 ) ) {
V_16 = - V_39 ;
goto V_183;
}
}
} else {
if ( V_174 . V_177 ) {
if ( F_106 ( V_176 , V_174 . V_72 , V_174 . V_177 ) ) {
V_16 = - V_39 ;
goto V_183;
}
}
V_68 = F_113 ( V_10 , 0 ) ;
F_39 ( V_10 , NULL , V_68 , V_174 . V_177 , V_175 , V_80 ,
V_176 , V_174 . V_177 ) ;
F_18 ( V_10 ) ;
V_29 = F_111 ( V_10 , F_113 ( V_10 , 0 ) , V_174 . V_179 ,
V_174 . V_178 , V_174 . V_185 , V_174 . V_180 ,
V_176 , V_174 . V_177 , V_175 ) ;
F_13 ( V_10 ) ;
F_39 ( V_10 , NULL , V_68 , F_112 ( V_29 , 0 ) , F_17 ( V_29 , 0 ) , V_106 , NULL , 0 ) ;
}
if ( V_29 < 0 && V_29 != - V_187 ) {
F_114 ( V_81 , & V_10 -> V_10 , L_23
L_24 ,
V_129 -> V_130 , V_174 . V_178 , V_174 . V_179 ,
V_174 . V_177 , V_29 ) ;
}
V_16 = V_29 ;
V_183:
F_115 ( ( unsigned long ) V_176 ) ;
F_6 ( V_181 + sizeof( struct V_52 ) +
sizeof( struct V_182 ) ) ;
return V_16 ;
}
static int F_116 ( struct V_7 * V_8 , void T_3 * V_172 )
{
struct V_26 * V_10 = V_8 -> V_10 ;
struct V_188 V_189 ;
unsigned int V_175 , V_190 , V_68 ;
int V_191 ;
unsigned char * V_176 ;
int V_29 , V_16 ;
if ( F_106 ( & V_189 , V_172 , sizeof( V_189 ) ) )
return - V_39 ;
V_16 = F_84 ( V_8 -> V_10 , V_189 . V_76 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_82 ( V_8 , V_16 ) ;
if ( V_16 )
return V_16 ;
if ( V_189 . V_76 & V_109 )
V_68 = F_117 ( V_10 , V_189 . V_76 & 0x7f ) ;
else
V_68 = F_118 ( V_10 , V_189 . V_76 & 0x7f ) ;
if ( ! F_119 ( V_10 , V_68 , ! ( V_189 . V_76 & V_109 ) ) )
return - V_21 ;
V_190 = V_189 . V_27 ;
if ( V_190 >= V_4 )
return - V_21 ;
V_16 = F_1 ( V_190 + sizeof( struct V_52 ) ) ;
if ( V_16 )
return V_16 ;
if ( ! ( V_176 = F_92 ( V_190 , V_51 ) ) ) {
V_16 = - V_6 ;
goto V_183;
}
V_175 = V_189 . V_184 ;
if ( V_189 . V_76 & 0x80 ) {
if ( V_190 && ! F_109 ( V_186 , V_189 . V_72 , V_190 ) ) {
V_16 = - V_21 ;
goto V_183;
}
F_39 ( V_10 , NULL , V_68 , V_190 , V_175 , V_80 , NULL , 0 ) ;
F_18 ( V_10 ) ;
V_29 = F_120 ( V_10 , V_68 , V_176 , V_190 , & V_191 , V_175 ) ;
F_13 ( V_10 ) ;
F_39 ( V_10 , NULL , V_68 , V_191 , V_29 , V_106 , V_176 , V_191 ) ;
if ( ! V_29 && V_191 ) {
if ( F_15 ( V_189 . V_72 , V_176 , V_191 ) ) {
V_16 = - V_39 ;
goto V_183;
}
}
} else {
if ( V_190 ) {
if ( F_106 ( V_176 , V_189 . V_72 , V_190 ) ) {
V_16 = - V_39 ;
goto V_183;
}
}
F_39 ( V_10 , NULL , V_68 , V_190 , V_175 , V_80 , V_176 , V_190 ) ;
F_18 ( V_10 ) ;
V_29 = F_120 ( V_10 , V_68 , V_176 , V_190 , & V_191 , V_175 ) ;
F_13 ( V_10 ) ;
F_39 ( V_10 , NULL , V_68 , V_191 , V_29 , V_106 , NULL , 0 ) ;
}
V_16 = ( V_29 < 0 ? V_29 : V_191 ) ;
V_183:
F_22 ( V_176 ) ;
F_6 ( V_190 + sizeof( struct V_52 ) ) ;
return V_16 ;
}
static int F_121 ( struct V_7 * V_8 , void T_3 * V_172 )
{
unsigned int V_76 ;
int V_16 ;
if ( F_122 ( V_76 , ( unsigned int T_3 * ) V_172 ) )
return - V_39 ;
V_16 = F_84 ( V_8 -> V_10 , V_76 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_82 ( V_8 , V_16 ) ;
if ( V_16 )
return V_16 ;
F_123 ( V_8 -> V_10 , V_76 ) ;
return 0 ;
}
static int F_124 ( struct V_7 * V_8 , void T_3 * V_172 )
{
unsigned int V_76 ;
int V_68 ;
int V_16 ;
if ( F_122 ( V_76 , ( unsigned int T_3 * ) V_172 ) )
return - V_39 ;
V_16 = F_84 ( V_8 -> V_10 , V_76 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_82 ( V_8 , V_16 ) ;
if ( V_16 )
return V_16 ;
if ( V_76 & V_109 )
V_68 = F_117 ( V_8 -> V_10 , V_76 & 0x7f ) ;
else
V_68 = F_118 ( V_8 -> V_10 , V_76 & 0x7f ) ;
return F_125 ( V_8 -> V_10 , V_68 ) ;
}
static int F_126 ( struct V_7 * V_8 , void T_3 * V_172 )
{
struct V_192 V_193 ;
struct V_118 * V_119 ;
int V_16 ;
if ( F_106 ( & V_193 , V_172 , sizeof( V_193 ) ) )
return - V_39 ;
V_119 = F_76 ( V_8 -> V_10 , V_193 . V_140 ) ;
if ( ! V_119 || ! V_119 -> V_10 . V_194 )
V_16 = - V_195 ;
else {
strncpy ( V_193 . V_194 , V_119 -> V_10 . V_194 -> V_196 ,
sizeof( V_193 . V_194 ) ) ;
V_16 = ( F_15 ( V_172 , & V_193 , sizeof( V_193 ) ) ? - V_39 : 0 ) ;
}
return V_16 ;
}
static int F_127 ( struct V_7 * V_8 , void T_3 * V_172 )
{
struct V_197 V_198 = {
. V_199 = V_8 -> V_10 -> V_199 ,
. V_200 = V_8 -> V_10 -> V_201 == V_202
} ;
if ( F_15 ( V_172 , & V_198 , sizeof( V_198 ) ) )
return - V_39 ;
return 0 ;
}
static int F_128 ( struct V_7 * V_8 )
{
return F_129 ( V_8 -> V_10 ) ;
}
static int F_130 ( struct V_7 * V_8 , void T_3 * V_172 )
{
struct V_203 V_204 ;
int V_16 ;
if ( F_106 ( & V_204 , V_172 , sizeof( V_204 ) ) )
return - V_39 ;
if ( ( V_16 = F_82 ( V_8 , V_204 . V_140 ) ) )
return V_16 ;
return F_131 ( V_8 -> V_10 , V_204 . V_140 ,
V_204 . V_122 ) ;
}
static int F_132 ( struct V_7 * V_8 , void T_3 * V_172 )
{
int V_205 ;
int V_100 = 0 ;
struct V_206 * V_137 ;
if ( F_122 ( V_205 , ( int T_3 * ) V_172 ) )
return - V_39 ;
V_137 = V_8 -> V_10 -> V_137 ;
if ( V_137 ) {
int V_29 ;
for ( V_29 = 0 ; V_29 < V_137 -> V_47 . V_139 ; ++ V_29 ) {
if ( F_133 ( V_137 -> V_140 [ V_29 ] ) ) {
F_70 ( & V_8 -> V_10 -> V_10 ,
L_25
L_26 ,
V_137 -> V_140 [ V_29 ]
-> V_207
-> V_47 . V_123 ,
V_137 -> V_140 [ V_29 ]
-> V_10 . V_194 -> V_196 ,
V_129 -> V_130 , V_205 ) ;
V_100 = - V_208 ;
break;
}
}
}
if ( V_100 == 0 ) {
if ( V_137 && V_137 -> V_47 . V_209 == V_205 )
V_100 = F_134 ( V_8 -> V_10 ) ;
else
V_100 = F_135 ( V_8 -> V_10 , V_205 ) ;
}
return V_100 ;
}
static int F_136 ( struct V_7 * V_8 , struct V_210 * V_211 ,
struct V_212 T_3 * V_213 ,
void T_3 * V_172 )
{
struct V_212 * V_214 = NULL ;
struct V_215 * V_76 ;
struct V_48 * V_50 = NULL ;
struct V_182 * V_216 = NULL ;
unsigned int V_205 , V_217 , V_218 ;
int V_29 , V_16 , V_219 , V_55 = 0 , V_114 = - 1 ;
void * V_22 ;
if ( V_211 -> V_60 & ~ ( V_220 |
V_221 |
V_222 |
V_223 |
V_224 |
V_225 ) )
return - V_21 ;
if ( V_211 -> V_226 > 0 && ! V_211 -> V_227 )
return - V_21 ;
if ( ! ( V_211 -> type == V_228 &&
( V_211 -> V_143 & ~ V_229 ) == 0 ) ) {
V_114 = F_84 ( V_8 -> V_10 , V_211 -> V_143 ) ;
if ( V_114 < 0 )
return V_114 ;
V_16 = F_82 ( V_8 , V_114 ) ;
if ( V_16 )
return V_16 ;
}
if ( ( V_211 -> V_143 & V_229 ) != 0 ) {
V_219 = 1 ;
V_76 = V_8 -> V_10 -> V_230 [ V_211 -> V_143 & V_231 ] ;
} else {
V_219 = 0 ;
V_76 = V_8 -> V_10 -> V_232 [ V_211 -> V_143 & V_231 ] ;
}
if ( ! V_76 )
return - V_111 ;
V_205 = 0 ;
switch( V_211 -> type ) {
case V_228 :
if ( ! F_137 ( & V_76 -> V_47 ) )
return - V_21 ;
if ( V_211 -> V_226 < 8 )
return - V_21 ;
V_216 = F_92 ( sizeof( struct V_182 ) , V_51 ) ;
if ( ! V_216 )
return - V_6 ;
if ( F_106 ( V_216 , V_211 -> V_227 , 8 ) ) {
V_16 = - V_39 ;
goto error;
}
if ( V_211 -> V_226 < ( F_138 ( & V_216 -> V_177 ) + 8 ) ) {
V_16 = - V_21 ;
goto error;
}
V_16 = F_85 ( V_8 , V_216 -> V_178 , V_216 -> V_179 ,
F_138 ( & V_216 -> V_180 ) ) ;
if ( V_16 )
goto error;
V_211 -> V_86 = 0 ;
V_211 -> V_226 = F_138 ( & V_216 -> V_177 ) ;
V_211 -> V_227 += 8 ;
if ( ( V_216 -> V_178 & V_109 ) && V_211 -> V_226 ) {
V_219 = 1 ;
V_211 -> V_143 |= V_109 ;
} else {
V_219 = 0 ;
V_211 -> V_143 &= ~ V_109 ;
}
F_56 ( & V_8 -> V_10 -> V_10 , L_20
L_21
L_22 ,
V_216 -> V_178 , V_216 -> V_179 ,
F_108 ( & V_216 -> V_185 ) ,
F_108 ( & V_216 -> V_180 ) ,
F_108 ( & V_216 -> V_177 ) ) ;
V_205 = sizeof( struct V_182 ) ;
break;
case V_233 :
switch ( F_139 ( & V_76 -> V_47 ) ) {
case V_234 :
case V_235 :
return - V_21 ;
case V_236 :
V_211 -> type = V_237 ;
goto V_238;
}
V_211 -> V_86 = 0 ;
V_55 = F_140 ( V_211 -> V_226 , V_84 ) ;
if ( V_55 == 1 || V_55 > V_8 -> V_10 -> V_239 -> V_240 )
V_55 = 0 ;
break;
case V_237 :
if ( ! F_141 ( & V_76 -> V_47 ) )
return - V_21 ;
V_238:
V_211 -> V_86 = 0 ;
break;
case V_241 :
if ( V_211 -> V_86 < 1 ||
V_211 -> V_86 > 128 )
return - V_21 ;
if ( ! F_142 ( & V_76 -> V_47 ) )
return - V_21 ;
V_218 = sizeof( struct V_212 ) *
V_211 -> V_86 ;
if ( ! ( V_214 = F_92 ( V_218 , V_51 ) ) )
return - V_6 ;
if ( F_106 ( V_214 , V_213 , V_218 ) ) {
V_16 = - V_39 ;
goto error;
}
for ( V_217 = V_205 = 0 ; V_205 < V_211 -> V_86 ; V_205 ++ ) {
if ( V_214 [ V_205 ] . V_44 > 8192 ) {
V_16 = - V_21 ;
goto error;
}
V_217 += V_214 [ V_205 ] . V_44 ;
}
V_205 *= sizeof( struct V_242 ) ;
V_211 -> V_226 = V_217 ;
break;
default:
return - V_21 ;
}
if ( V_211 -> V_226 >= V_4 ) {
V_16 = - V_21 ;
goto error;
}
if ( V_211 -> V_226 > 0 &&
! F_109 ( V_219 ? V_186 : V_243 ,
V_211 -> V_227 , V_211 -> V_226 ) ) {
V_16 = - V_39 ;
goto error;
}
V_50 = F_19 ( V_211 -> V_86 ) ;
if ( ! V_50 ) {
V_16 = - V_6 ;
goto error;
}
V_205 += sizeof( struct V_48 ) + sizeof( struct V_52 ) + V_211 -> V_226 +
V_55 * sizeof( struct V_244 ) ;
V_16 = F_1 ( V_205 ) ;
if ( V_16 )
goto error;
V_50 -> V_59 = V_205 ;
if ( V_55 ) {
V_50 -> V_52 -> V_56 = F_92 ( V_55 * sizeof( struct V_244 ) ,
V_51 ) ;
if ( ! V_50 -> V_52 -> V_56 ) {
V_16 = - V_6 ;
goto error;
}
V_50 -> V_52 -> V_55 = V_55 ;
F_143 ( V_50 -> V_52 -> V_56 , V_50 -> V_52 -> V_55 ) ;
V_217 = V_211 -> V_226 ;
for ( V_29 = 0 ; V_29 < V_50 -> V_52 -> V_55 ; V_29 ++ ) {
V_205 = ( V_217 > V_84 ) ? V_84 : V_217 ;
V_22 = F_92 ( V_205 , V_51 ) ;
if ( ! V_22 ) {
V_16 = - V_6 ;
goto error;
}
F_144 ( & V_50 -> V_52 -> V_56 [ V_29 ] , V_22 , V_205 ) ;
if ( ! V_219 ) {
if ( F_106 ( V_22 , V_211 -> V_227 , V_205 ) ) {
V_16 = - V_39 ;
goto error;
}
V_211 -> V_227 += V_205 ;
}
V_217 -= V_205 ;
}
} else if ( V_211 -> V_226 > 0 ) {
V_50 -> V_52 -> V_57 = F_92 ( V_211 -> V_226 ,
V_51 ) ;
if ( ! V_50 -> V_52 -> V_57 ) {
V_16 = - V_6 ;
goto error;
}
if ( ! V_219 ) {
if ( F_106 ( V_50 -> V_52 -> V_57 ,
V_211 -> V_227 ,
V_211 -> V_226 ) ) {
V_16 = - V_39 ;
goto error;
}
} else if ( V_211 -> type == V_241 ) {
memset ( V_50 -> V_52 -> V_57 , 0 ,
V_211 -> V_226 ) ;
}
}
V_50 -> V_52 -> V_10 = V_8 -> V_10 ;
V_50 -> V_52 -> V_68 = ( V_211 -> type << 30 ) |
F_145 ( V_8 -> V_10 , V_211 -> V_143 & 0xf ) |
( V_211 -> V_143 & V_109 ) ;
V_205 = ( V_219 ? V_245 : V_246 ) ;
if ( V_211 -> V_60 & V_220 )
V_205 |= V_247 ;
if ( V_211 -> V_60 & V_221 )
V_205 |= V_248 ;
if ( V_211 -> V_60 & V_223 )
V_205 |= V_249 ;
if ( V_211 -> V_60 & V_224 )
V_205 |= V_250 ;
if ( V_211 -> V_60 & V_225 )
V_205 |= V_251 ;
V_50 -> V_52 -> V_107 = V_205 ;
V_50 -> V_52 -> V_87 = V_211 -> V_226 ;
V_50 -> V_52 -> V_58 = ( unsigned char * ) V_216 ;
V_216 = NULL ;
V_50 -> V_52 -> V_252 = V_211 -> V_252 ;
V_50 -> V_52 -> V_86 = V_211 -> V_86 ;
if ( V_211 -> type == V_241 ||
V_8 -> V_10 -> V_201 == V_253 )
V_50 -> V_52 -> V_254 = 1 << F_17 ( 15 , V_76 -> V_47 . V_255 - 1 ) ;
else
V_50 -> V_52 -> V_254 = V_76 -> V_47 . V_255 ;
V_50 -> V_52 -> V_95 = V_50 ;
V_50 -> V_52 -> V_256 = V_64 ;
for ( V_217 = V_205 = 0 ; V_205 < V_211 -> V_86 ; V_205 ++ ) {
V_50 -> V_52 -> V_213 [ V_205 ] . V_14 = V_217 ;
V_50 -> V_52 -> V_213 [ V_205 ] . V_44 = V_214 [ V_205 ] . V_44 ;
V_217 += V_214 [ V_205 ] . V_44 ;
}
F_22 ( V_214 ) ;
V_214 = NULL ;
V_50 -> V_8 = V_8 ;
V_50 -> V_66 = V_172 ;
if ( V_219 && V_211 -> V_226 > 0 )
V_50 -> V_85 = V_211 -> V_227 ;
else
V_50 -> V_85 = NULL ;
V_50 -> V_99 = V_211 -> V_99 ;
V_50 -> V_114 = V_114 ;
V_50 -> V_53 = F_54 ( F_97 ( V_129 ) ) ;
V_50 -> V_54 = F_98 () ;
F_99 ( V_129 , & V_50 -> V_98 ) ;
F_39 ( V_8 -> V_10 , V_50 -> V_66 , V_50 -> V_52 -> V_68 ,
V_50 -> V_52 -> V_87 , 0 , V_80 ,
NULL , 0 ) ;
if ( ! V_219 )
F_45 ( V_50 -> V_52 , V_50 -> V_52 -> V_87 ) ;
F_29 ( V_50 ) ;
if ( F_146 ( & V_76 -> V_47 ) ) {
F_147 ( & V_8 -> V_61 ) ;
V_50 -> V_89 = F_148 ( & V_76 -> V_47 ) |
( ( V_76 -> V_47 . V_144 & V_229 )
>> 3 ) ;
if ( V_211 -> V_60 & V_222 )
V_50 -> V_90 = V_91 ;
else
V_8 -> V_94 &= ~ ( 1 << V_50 -> V_89 ) ;
if ( V_8 -> V_94 & ( 1 << V_50 -> V_89 ) )
V_16 = - V_257 ;
else
V_16 = F_149 ( V_50 -> V_52 , V_258 ) ;
F_150 ( & V_8 -> V_61 ) ;
} else {
V_16 = F_149 ( V_50 -> V_52 , V_51 ) ;
}
if ( V_16 ) {
F_114 ( V_81 , & V_8 -> V_10 -> V_10 ,
L_27 , V_16 ) ;
F_39 ( V_8 -> V_10 , V_50 -> V_66 , V_50 -> V_52 -> V_68 ,
0 , V_16 , V_106 , NULL , 0 ) ;
F_33 ( V_50 ) ;
goto error;
}
return 0 ;
error:
F_22 ( V_214 ) ;
F_22 ( V_216 ) ;
if ( V_50 )
F_23 ( V_50 ) ;
return V_16 ;
}
static int F_151 ( struct V_7 * V_8 , void T_3 * V_172 )
{
struct V_210 V_211 ;
if ( F_106 ( & V_211 , V_172 , sizeof( V_211 ) ) )
return - V_39 ;
return F_136 ( V_8 , & V_211 ,
( ( (struct V_210 T_3 * ) V_172 ) -> V_213 ) ,
V_172 ) ;
}
static int F_152 ( struct V_7 * V_8 , void T_3 * V_172 )
{
struct V_52 * V_52 ;
struct V_48 * V_50 ;
unsigned long V_60 ;
F_30 ( & V_8 -> V_61 , V_60 ) ;
V_50 = F_37 ( V_8 , V_172 ) ;
if ( ! V_50 ) {
F_32 ( & V_8 -> V_61 , V_60 ) ;
return - V_21 ;
}
V_52 = V_50 -> V_52 ;
F_48 ( V_52 ) ;
F_32 ( & V_8 -> V_61 , V_60 ) ;
F_60 ( V_52 ) ;
F_51 ( V_52 ) ;
return 0 ;
}
static int F_153 ( struct V_48 * V_50 , void T_3 * T_3 * V_172 )
{
struct V_52 * V_52 = V_50 -> V_52 ;
struct V_210 T_3 * V_66 = V_50 -> V_66 ;
void T_3 * V_259 = V_50 -> V_66 ;
unsigned int V_29 ;
if ( V_50 -> V_85 && V_52 -> V_88 ) {
if ( F_46 ( V_50 -> V_85 , V_52 ) )
goto V_260;
}
if ( F_154 ( V_50 -> V_100 , & V_66 -> V_100 ) )
goto V_260;
if ( F_154 ( V_52 -> V_88 , & V_66 -> V_88 ) )
goto V_260;
if ( F_154 ( V_52 -> V_261 , & V_66 -> V_261 ) )
goto V_260;
if ( F_142 ( & V_52 -> V_76 -> V_47 ) ) {
for ( V_29 = 0 ; V_29 < V_52 -> V_86 ; V_29 ++ ) {
if ( F_154 ( V_52 -> V_213 [ V_29 ] . V_88 ,
& V_66 -> V_213 [ V_29 ] . V_88 ) )
goto V_260;
if ( F_154 ( V_52 -> V_213 [ V_29 ] . V_100 ,
& V_66 -> V_213 [ V_29 ] . V_100 ) )
goto V_260;
}
}
if ( F_154 ( V_259 , ( void T_3 * T_3 * ) V_172 ) )
return - V_39 ;
return 0 ;
V_260:
return - V_39 ;
}
static struct V_48 * F_155 ( struct V_7 * V_8 )
{
F_156 ( V_112 , V_129 ) ;
struct V_48 * V_50 = NULL ;
struct V_26 * V_10 = V_8 -> V_10 ;
F_157 ( & V_8 -> V_112 , & V_112 ) ;
for (; ; ) {
F_158 ( V_262 ) ;
V_50 = F_35 ( V_8 ) ;
if ( V_50 )
break;
if ( F_159 ( V_129 ) )
break;
F_18 ( V_10 ) ;
F_160 () ;
F_13 ( V_10 ) ;
}
F_161 ( & V_8 -> V_112 , & V_112 ) ;
F_162 ( V_263 ) ;
return V_50 ;
}
static int F_163 ( struct V_7 * V_8 , void T_3 * V_172 )
{
struct V_48 * V_50 = F_155 ( V_8 ) ;
if ( V_50 ) {
int V_264 = F_153 ( V_50 , ( void T_3 * T_3 * ) V_172 ) ;
F_23 ( V_50 ) ;
return V_264 ;
}
if ( F_159 ( V_129 ) )
return - V_265 ;
return - V_266 ;
}
static int F_164 ( struct V_7 * V_8 , void T_3 * V_172 )
{
int V_264 ;
struct V_48 * V_50 ;
V_50 = F_35 ( V_8 ) ;
V_264 = - V_267 ;
if ( V_50 ) {
V_264 = F_153 ( V_50 , ( void T_3 * T_3 * ) V_172 ) ;
F_23 ( V_50 ) ;
}
return V_264 ;
}
static int F_165 ( struct V_7 * V_8 ,
struct V_268 T_3 * V_269 )
{
struct V_173 T_3 * V_115 ;
T_8 V_270 ;
V_115 = F_166 ( sizeof( * V_115 ) ) ;
if ( F_167 ( V_115 , V_269 , ( sizeof( * V_269 ) - sizeof( V_271 ) ) ) ||
F_122 ( V_270 , & V_269 -> V_72 ) ||
F_154 ( F_168 ( V_270 ) , & V_115 -> V_72 ) )
return - V_39 ;
return F_105 ( V_8 , V_115 ) ;
}
static int F_169 ( struct V_7 * V_8 ,
struct V_272 T_3 * V_269 )
{
struct V_188 T_3 * V_115 ;
T_9 V_273 ;
V_271 V_259 ;
V_115 = F_166 ( sizeof( * V_115 ) ) ;
if ( F_122 ( V_273 , & V_269 -> V_76 ) || F_154 ( V_273 , & V_115 -> V_76 ) ||
F_122 ( V_273 , & V_269 -> V_27 ) || F_154 ( V_273 , & V_115 -> V_27 ) ||
F_122 ( V_273 , & V_269 -> V_184 ) || F_154 ( V_273 , & V_115 -> V_184 ) ||
F_122 ( V_259 , & V_269 -> V_72 ) || F_154 ( F_168 ( V_259 ) , & V_115 -> V_72 ) )
return - V_39 ;
return F_116 ( V_8 , V_115 ) ;
}
static int F_170 ( struct V_7 * V_8 , void T_3 * V_172 )
{
struct V_274 V_275 ;
if ( F_106 ( & V_275 , V_172 , sizeof( V_275 ) ) )
return - V_39 ;
V_8 -> V_168 = V_275 . V_99 ;
V_8 -> V_170 = F_168 ( V_275 . V_95 ) ;
return 0 ;
}
static int F_171 ( struct V_210 * V_276 ,
struct V_277 T_3 * V_211 )
{
T_8 V_278 ;
if ( ! F_109 ( V_243 , V_211 , sizeof( * V_211 ) ) ||
F_172 ( V_276 -> type , & V_211 -> type ) ||
F_172 ( V_276 -> V_143 , & V_211 -> V_143 ) ||
F_172 ( V_276 -> V_100 , & V_211 -> V_100 ) ||
F_172 ( V_276 -> V_60 , & V_211 -> V_60 ) ||
F_172 ( V_276 -> V_226 , & V_211 -> V_226 ) ||
F_172 ( V_276 -> V_88 , & V_211 -> V_88 ) ||
F_172 ( V_276 -> V_252 , & V_211 -> V_252 ) ||
F_172 ( V_276 -> V_86 , & V_211 -> V_86 ) ||
F_172 ( V_276 -> V_261 , & V_211 -> V_261 ) ||
F_172 ( V_276 -> V_99 , & V_211 -> V_99 ) )
return - V_39 ;
if ( F_172 ( V_278 , & V_211 -> V_227 ) )
return - V_39 ;
V_276 -> V_227 = F_168 ( V_278 ) ;
if ( F_172 ( V_278 , & V_211 -> V_279 ) )
return - V_39 ;
V_276 -> V_279 = F_168 ( V_278 ) ;
return 0 ;
}
static int F_173 ( struct V_7 * V_8 , void T_3 * V_172 )
{
struct V_210 V_211 ;
if ( F_171 ( & V_211 , (struct V_277 T_3 * ) V_172 ) )
return - V_39 ;
return F_136 ( V_8 , & V_211 ,
( (struct V_277 T_3 * ) V_172 ) -> V_213 ,
V_172 ) ;
}
static int F_174 ( struct V_48 * V_50 , void T_3 * T_3 * V_172 )
{
struct V_52 * V_52 = V_50 -> V_52 ;
struct V_277 T_3 * V_66 = V_50 -> V_66 ;
void T_3 * V_259 = V_50 -> V_66 ;
unsigned int V_29 ;
if ( V_50 -> V_85 && V_52 -> V_88 ) {
if ( F_46 ( V_50 -> V_85 , V_52 ) )
return - V_39 ;
}
if ( F_154 ( V_50 -> V_100 , & V_66 -> V_100 ) )
return - V_39 ;
if ( F_154 ( V_52 -> V_88 , & V_66 -> V_88 ) )
return - V_39 ;
if ( F_154 ( V_52 -> V_261 , & V_66 -> V_261 ) )
return - V_39 ;
if ( F_142 ( & V_52 -> V_76 -> V_47 ) ) {
for ( V_29 = 0 ; V_29 < V_52 -> V_86 ; V_29 ++ ) {
if ( F_154 ( V_52 -> V_213 [ V_29 ] . V_88 ,
& V_66 -> V_213 [ V_29 ] . V_88 ) )
return - V_39 ;
if ( F_154 ( V_52 -> V_213 [ V_29 ] . V_100 ,
& V_66 -> V_213 [ V_29 ] . V_100 ) )
return - V_39 ;
}
}
if ( F_154 ( F_175 ( V_259 ) , ( T_6 T_3 * ) V_172 ) )
return - V_39 ;
return 0 ;
}
static int F_176 ( struct V_7 * V_8 , void T_3 * V_172 )
{
struct V_48 * V_50 = F_155 ( V_8 ) ;
if ( V_50 ) {
int V_264 = F_174 ( V_50 , ( void T_3 * T_3 * ) V_172 ) ;
F_23 ( V_50 ) ;
return V_264 ;
}
if ( F_159 ( V_129 ) )
return - V_265 ;
return - V_266 ;
}
static int F_177 ( struct V_7 * V_8 , void T_3 * V_172 )
{
int V_264 ;
struct V_48 * V_50 ;
V_264 = - V_267 ;
V_50 = F_35 ( V_8 ) ;
if ( V_50 ) {
V_264 = F_174 ( V_50 , ( void T_3 * T_3 * ) V_172 ) ;
F_23 ( V_50 ) ;
}
return V_264 ;
}
static int F_178 ( struct V_7 * V_8 , void T_3 * V_172 )
{
struct V_280 V_275 ;
if ( F_106 ( & V_275 , V_172 , sizeof( V_275 ) ) )
return - V_39 ;
V_8 -> V_168 = V_275 . V_99 ;
V_8 -> V_170 = V_275 . V_95 ;
return 0 ;
}
static int F_179 ( struct V_7 * V_8 , void T_3 * V_172 )
{
unsigned int V_114 ;
if ( F_122 ( V_114 , ( unsigned int T_3 * ) V_172 ) )
return - V_39 ;
return F_74 ( V_8 , V_114 ) ;
}
static int F_180 ( struct V_7 * V_8 , void T_3 * V_172 )
{
unsigned int V_114 ;
int V_16 ;
if ( F_122 ( V_114 , ( unsigned int T_3 * ) V_172 ) )
return - V_39 ;
if ( ( V_16 = F_79 ( V_8 , V_114 ) ) < 0 )
return V_16 ;
F_61 ( V_8 , V_114 ) ;
return 0 ;
}
static int F_181 ( struct V_7 * V_8 , struct V_281 * V_282 )
{
int V_83 ;
void * V_22 = NULL ;
int V_264 = 0 ;
struct V_118 * V_119 = NULL ;
struct V_283 * V_194 = NULL ;
if ( ( V_83 = F_182 ( V_282 -> V_284 ) ) > 0 ) {
if ( ( V_22 = F_92 ( V_83 , V_51 ) ) == NULL )
return - V_6 ;
if ( ( F_183 ( V_282 -> V_284 ) & V_285 ) ) {
if ( F_106 ( V_22 , V_282 -> V_72 , V_83 ) ) {
F_22 ( V_22 ) ;
return - V_39 ;
}
} else {
memset ( V_22 , 0 , V_83 ) ;
}
}
if ( ! F_7 ( V_8 ) ) {
F_22 ( V_22 ) ;
return - V_30 ;
}
if ( V_8 -> V_10 -> V_11 != V_127 )
V_264 = - V_128 ;
else if ( ! ( V_119 = F_76 ( V_8 -> V_10 , V_282 -> V_286 ) ) )
V_264 = - V_21 ;
else switch ( V_282 -> V_284 ) {
case V_287 :
if ( V_119 -> V_10 . V_194 ) {
V_194 = F_184 ( V_119 -> V_10 . V_194 ) ;
F_185 ( & V_119 -> V_10 , L_28 ) ;
F_81 ( V_194 , V_119 ) ;
} else
V_264 = - V_195 ;
break;
case V_288 :
if ( ! V_119 -> V_10 . V_194 )
V_264 = F_186 ( & V_119 -> V_10 ) ;
else
V_264 = - V_208 ;
break;
default:
if ( V_119 -> V_10 . V_194 )
V_194 = F_184 ( V_119 -> V_10 . V_194 ) ;
if ( V_194 == NULL || V_194 -> V_289 == NULL ) {
V_264 = - V_290 ;
} else {
V_264 = V_194 -> V_289 ( V_119 , V_282 -> V_284 , V_22 ) ;
if ( V_264 == - V_291 )
V_264 = - V_290 ;
}
}
if ( V_264 >= 0
&& ( F_183 ( V_282 -> V_284 ) & V_292 ) != 0
&& V_83 > 0
&& F_15 ( V_282 -> V_72 , V_22 , V_83 ) != 0 )
V_264 = - V_39 ;
F_22 ( V_22 ) ;
return V_264 ;
}
static int F_187 ( struct V_7 * V_8 , void T_3 * V_172 )
{
struct V_281 V_174 ;
if ( F_106 ( & V_174 , V_172 , sizeof( V_174 ) ) )
return - V_39 ;
return F_181 ( V_8 , & V_174 ) ;
}
static int F_188 ( struct V_7 * V_8 , T_10 V_172 )
{
struct V_293 T_3 * V_294 ;
struct V_281 V_174 ;
T_6 V_270 ;
V_294 = F_168 ( ( long ) V_172 ) ;
if ( ! F_109 ( V_243 , V_294 , sizeof( * V_294 ) ) ||
F_172 ( V_174 . V_286 , & V_294 -> V_286 ) ||
F_172 ( V_174 . V_284 , & V_294 -> V_284 ) ||
F_172 ( V_270 , & V_294 -> V_72 ) )
return - V_39 ;
V_174 . V_72 = F_168 ( V_270 ) ;
return F_181 ( V_8 , & V_174 ) ;
}
static int F_189 ( struct V_7 * V_8 , void T_3 * V_172 )
{
unsigned V_295 ;
int V_296 ;
if ( F_122 ( V_295 , ( unsigned T_3 * ) V_172 ) )
return - V_39 ;
V_296 = F_190 ( V_8 -> V_10 , V_295 , V_8 ) ;
if ( V_296 == 0 )
F_56 ( & V_8 -> V_10 -> V_10 , L_29 ,
V_295 , F_83 ( V_129 ) , V_129 -> V_130 ) ;
return V_296 ;
}
static int F_191 ( struct V_7 * V_8 , void T_3 * V_172 )
{
unsigned V_295 ;
if ( F_122 ( V_295 , ( unsigned T_3 * ) V_172 ) )
return - V_39 ;
return F_192 ( V_8 -> V_10 , V_295 , V_8 ) ;
}
static int F_193 ( struct V_7 * V_8 , void T_3 * V_172 )
{
T_8 V_297 ;
V_297 = V_298 | V_299 ;
if ( ! V_8 -> V_10 -> V_239 -> V_300 )
V_297 |= V_301 ;
if ( V_8 -> V_10 -> V_239 -> V_240 )
V_297 |= V_302 ;
if ( F_154 ( V_297 , ( T_8 T_3 * ) V_172 ) )
return - V_39 ;
return 0 ;
}
static int F_194 ( struct V_7 * V_8 , void T_3 * V_172 )
{
struct V_303 V_304 ;
struct V_118 * V_119 ;
if ( F_106 ( & V_304 , V_172 , sizeof( V_304 ) ) )
return - V_39 ;
V_119 = F_76 ( V_8 -> V_10 , V_304 . V_140 ) ;
if ( ! V_119 )
return - V_21 ;
if ( V_119 -> V_10 . V_194 ) {
struct V_283 * V_194 = F_184 ( V_119 -> V_10 . V_194 ) ;
if ( ( V_304 . V_60 & V_305 ) &&
strncmp ( V_304 . V_194 , V_119 -> V_10 . V_194 -> V_196 ,
sizeof( V_304 . V_194 ) ) != 0 )
return - V_208 ;
if ( ( V_304 . V_60 & V_306 ) &&
strncmp ( V_304 . V_194 , V_119 -> V_10 . V_194 -> V_196 ,
sizeof( V_304 . V_194 ) ) == 0 )
return - V_208 ;
F_185 ( & V_119 -> V_10 , L_28 ) ;
F_81 ( V_194 , V_119 ) ;
}
return F_74 ( V_8 , V_304 . V_140 ) ;
}
static long F_195 ( struct V_13 * V_13 , unsigned int V_307 ,
void T_3 * V_115 )
{
struct V_7 * V_8 = V_13 -> V_25 ;
struct V_162 * V_162 = V_13 -> V_308 . V_309 -> V_18 ;
struct V_26 * V_10 = V_8 -> V_10 ;
int V_16 = - V_290 ;
if ( ! ( V_13 -> V_310 & V_311 ) )
return - V_312 ;
F_13 ( V_10 ) ;
if ( ! F_7 ( V_8 ) ) {
F_18 ( V_10 ) ;
return - V_30 ;
}
switch ( V_307 ) {
case V_313 :
F_56 ( & V_10 -> V_10 , L_30 , V_314 ) ;
V_16 = F_105 ( V_8 , V_115 ) ;
if ( V_16 >= 0 )
V_162 -> V_315 = V_316 ;
break;
case V_317 :
F_56 ( & V_10 -> V_10 , L_31 , V_314 ) ;
V_16 = F_116 ( V_8 , V_115 ) ;
if ( V_16 >= 0 )
V_162 -> V_315 = V_316 ;
break;
case V_318 :
F_56 ( & V_10 -> V_10 , L_32 , V_314 ) ;
V_16 = F_121 ( V_8 , V_115 ) ;
if ( V_16 >= 0 )
V_162 -> V_315 = V_316 ;
break;
case V_319 :
F_56 ( & V_10 -> V_10 , L_33 , V_314 ) ;
V_16 = F_128 ( V_8 ) ;
break;
case V_320 :
F_56 ( & V_10 -> V_10 , L_34 , V_314 ) ;
V_16 = F_124 ( V_8 , V_115 ) ;
if ( V_16 >= 0 )
V_162 -> V_315 = V_316 ;
break;
case V_321 :
F_56 ( & V_10 -> V_10 , L_35 , V_314 ) ;
V_16 = F_126 ( V_8 , V_115 ) ;
break;
case V_322 :
F_56 ( & V_10 -> V_10 , L_36 , V_314 ) ;
V_16 = F_127 ( V_8 , V_115 ) ;
break;
case V_323 :
F_56 ( & V_10 -> V_10 , L_37 , V_314 ) ;
V_16 = F_130 ( V_8 , V_115 ) ;
break;
case V_324 :
F_56 ( & V_10 -> V_10 , L_38 , V_314 ) ;
V_16 = F_132 ( V_8 , V_115 ) ;
break;
case V_325 :
F_56 ( & V_10 -> V_10 , L_39 , V_314 ) ;
V_16 = F_151 ( V_8 , V_115 ) ;
if ( V_16 >= 0 )
V_162 -> V_315 = V_316 ;
break;
#ifdef F_196
case V_326 :
F_56 ( & V_10 -> V_10 , L_40 , V_314 ) ;
V_16 = F_165 ( V_8 , V_115 ) ;
if ( V_16 >= 0 )
V_162 -> V_315 = V_316 ;
break;
case V_327 :
F_56 ( & V_10 -> V_10 , L_41 , V_314 ) ;
V_16 = F_169 ( V_8 , V_115 ) ;
if ( V_16 >= 0 )
V_162 -> V_315 = V_316 ;
break;
case V_328 :
F_56 ( & V_10 -> V_10 , L_42 , V_314 ) ;
V_16 = F_170 ( V_8 , V_115 ) ;
break;
case V_329 :
F_56 ( & V_10 -> V_10 , L_43 , V_314 ) ;
V_16 = F_173 ( V_8 , V_115 ) ;
if ( V_16 >= 0 )
V_162 -> V_315 = V_316 ;
break;
case V_330 :
F_56 ( & V_10 -> V_10 , L_44 , V_314 ) ;
V_16 = F_176 ( V_8 , V_115 ) ;
break;
case V_331 :
F_56 ( & V_10 -> V_10 , L_45 , V_314 ) ;
V_16 = F_177 ( V_8 , V_115 ) ;
break;
case V_332 :
F_56 ( & V_10 -> V_10 , L_46 , V_314 ) ;
V_16 = F_188 ( V_8 , F_175 ( V_115 ) ) ;
break;
#endif
case V_333 :
F_56 ( & V_10 -> V_10 , L_47 , V_314 ) ;
V_16 = F_152 ( V_8 , V_115 ) ;
break;
case V_334 :
F_56 ( & V_10 -> V_10 , L_48 , V_314 ) ;
V_16 = F_163 ( V_8 , V_115 ) ;
break;
case V_335 :
F_56 ( & V_10 -> V_10 , L_49 , V_314 ) ;
V_16 = F_164 ( V_8 , V_115 ) ;
break;
case V_336 :
F_56 ( & V_10 -> V_10 , L_50 , V_314 ) ;
V_16 = F_178 ( V_8 , V_115 ) ;
break;
case V_337 :
F_56 ( & V_10 -> V_10 , L_51 , V_314 ) ;
V_16 = F_179 ( V_8 , V_115 ) ;
break;
case V_338 :
F_56 ( & V_10 -> V_10 , L_52 , V_314 ) ;
V_16 = F_180 ( V_8 , V_115 ) ;
break;
case V_339 :
F_56 ( & V_10 -> V_10 , L_53 , V_314 ) ;
V_16 = F_187 ( V_8 , V_115 ) ;
break;
case V_340 :
F_56 ( & V_10 -> V_10 , L_54 , V_314 ) ;
V_16 = F_189 ( V_8 , V_115 ) ;
break;
case V_341 :
F_56 ( & V_10 -> V_10 , L_55 , V_314 ) ;
V_16 = F_191 ( V_8 , V_115 ) ;
break;
case V_342 :
V_16 = F_193 ( V_8 , V_115 ) ;
break;
case V_343 :
V_16 = F_194 ( V_8 , V_115 ) ;
break;
}
F_18 ( V_10 ) ;
if ( V_16 >= 0 )
V_162 -> V_344 = V_316 ;
return V_16 ;
}
static long F_197 ( struct V_13 * V_13 , unsigned int V_307 ,
unsigned long V_172 )
{
int V_16 ;
V_16 = F_195 ( V_13 , V_307 , ( void T_3 * ) V_172 ) ;
return V_16 ;
}
static long F_198 ( struct V_13 * V_13 , unsigned int V_307 ,
unsigned long V_172 )
{
int V_16 ;
V_16 = F_195 ( V_13 , V_307 , F_168 ( V_172 ) ) ;
return V_16 ;
}
static unsigned int F_199 ( struct V_13 * V_13 ,
struct V_345 * V_112 )
{
struct V_7 * V_8 = V_13 -> V_25 ;
unsigned int V_346 = 0 ;
F_200 ( V_13 , & V_8 -> V_112 , V_112 ) ;
if ( V_13 -> V_310 & V_311 && ! F_8 ( & V_8 -> V_64 ) )
V_346 |= V_347 | V_348 ;
if ( ! F_7 ( V_8 ) )
V_346 |= V_349 | V_350 ;
return V_346 ;
}
static void F_201 ( struct V_26 * V_67 )
{
struct V_7 * V_8 ;
struct V_96 V_97 ;
while ( ! F_8 ( & V_67 -> V_171 ) ) {
V_8 = F_36 ( V_67 -> V_171 . V_65 , struct V_7 , V_9 ) ;
F_64 ( V_8 ) ;
F_202 ( & V_8 -> V_112 ) ;
F_34 ( & V_8 -> V_9 ) ;
if ( V_8 -> V_168 ) {
V_97 . V_101 = V_8 -> V_168 ;
V_97 . V_102 = V_187 ;
V_97 . V_103 = V_104 ;
V_97 . V_105 = V_8 -> V_170 ;
F_57 ( V_8 -> V_168 , & V_97 ,
V_8 -> V_169 , V_8 -> V_54 , V_8 -> V_98 ) ;
}
}
}
static int F_203 ( struct V_351 * V_352 ,
unsigned long V_353 , void * V_10 )
{
switch ( V_353 ) {
case V_354 :
break;
case V_355 :
F_201 ( V_10 ) ;
break;
}
return V_356 ;
}
int T_11 F_204 ( void )
{
int V_264 ;
V_264 = F_205 ( V_357 , V_358 ,
L_56 ) ;
if ( V_264 ) {
F_206 ( V_359 L_57 ) ;
goto V_360;
}
F_207 ( & V_361 , & V_362 ) ;
V_264 = F_208 ( & V_361 , V_357 , V_358 ) ;
if ( V_264 ) {
F_206 ( V_359 L_58 ,
V_165 ) ;
goto V_363;
}
F_209 ( & V_364 ) ;
V_360:
return V_264 ;
V_363:
F_210 ( V_357 , V_358 ) ;
goto V_360;
}
void F_211 ( void )
{
F_212 ( & V_364 ) ;
F_213 ( & V_361 ) ;
F_210 ( V_357 , V_358 ) ;
}
