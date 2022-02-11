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
F_10 ( & F_11 ( V_13 ) -> V_17 ) ;
switch ( V_15 ) {
case 0 :
V_13 -> V_18 = V_14 ;
V_16 = V_13 -> V_18 ;
break;
case 1 :
V_13 -> V_18 += V_14 ;
V_16 = V_13 -> V_18 ;
break;
case 2 :
default:
V_16 = - V_19 ;
}
F_12 ( & F_11 ( V_13 ) -> V_17 ) ;
return V_16 ;
}
static T_2 F_13 ( struct V_13 * V_13 , char T_3 * V_20 , T_4 V_21 ,
T_1 * V_22 )
{
struct V_7 * V_8 = V_13 -> V_23 ;
struct V_24 * V_10 = V_8 -> V_10 ;
T_2 V_16 = 0 ;
unsigned V_25 ;
T_1 V_26 ;
int V_27 ;
V_26 = * V_22 ;
F_14 ( V_10 ) ;
if ( ! F_7 ( V_8 ) ) {
V_16 = - V_28 ;
goto V_29;
} else if ( V_26 < 0 ) {
V_16 = - V_19 ;
goto V_29;
}
if ( V_26 < sizeof( struct V_30 ) ) {
struct V_30 V_31 ;
memcpy ( & V_31 , & V_10 -> V_32 , sizeof( V_10 -> V_32 ) ) ;
F_15 ( & V_31 . V_33 ) ;
F_15 ( & V_31 . V_34 ) ;
F_15 ( & V_31 . V_35 ) ;
F_15 ( & V_31 . V_36 ) ;
V_25 = sizeof( struct V_30 ) - V_26 ;
if ( V_25 > V_21 )
V_25 = V_21 ;
if ( F_16 ( V_20 , ( ( char * ) & V_31 ) + V_26 , V_25 ) ) {
V_16 = - V_37 ;
goto V_29;
}
* V_22 += V_25 ;
V_20 += V_25 ;
V_21 -= V_25 ;
V_16 += V_25 ;
}
V_26 = sizeof( struct V_30 ) ;
for ( V_27 = 0 ; V_21 && V_27 < V_10 -> V_32 . V_38 ; V_27 ++ ) {
struct V_39 * V_40 =
(struct V_39 * ) V_10 -> V_41 [ V_27 ] ;
unsigned int V_42 = F_17 ( V_40 -> V_43 ) ;
if ( * V_22 < V_26 + V_42 ) {
unsigned V_44 =
F_17 ( V_10 -> V_40 [ V_27 ] . V_45 . V_43 ) ;
V_25 = V_42 - ( * V_22 - V_26 ) ;
if ( V_25 > V_21 )
V_25 = V_21 ;
if ( V_44 > ( * V_22 - V_26 ) ) {
V_44 -= ( * V_22 - V_26 ) ;
if ( F_16 ( V_20 ,
V_10 -> V_41 [ V_27 ] + ( * V_22 - V_26 ) ,
F_18 ( V_25 , V_44 ) ) ) {
V_16 = - V_37 ;
goto V_29;
}
}
* V_22 += V_25 ;
V_20 += V_25 ;
V_21 -= V_25 ;
V_16 += V_25 ;
}
V_26 += V_42 ;
}
V_29:
F_19 ( V_10 ) ;
return V_16 ;
}
static struct V_46 * F_20 ( unsigned int V_47 )
{
struct V_46 * V_48 ;
V_48 = F_21 ( sizeof( struct V_46 ) , V_49 ) ;
if ( ! V_48 )
return NULL ;
V_48 -> V_50 = F_22 ( V_47 , V_49 ) ;
if ( ! V_48 -> V_50 ) {
F_23 ( V_48 ) ;
return NULL ;
}
return V_48 ;
}
static void F_24 ( struct V_46 * V_48 )
{
int V_27 ;
F_25 ( V_48 -> V_51 ) ;
if ( V_48 -> V_52 )
F_26 ( V_48 -> V_52 ) ;
for ( V_27 = 0 ; V_27 < V_48 -> V_50 -> V_53 ; V_27 ++ ) {
if ( F_27 ( & V_48 -> V_50 -> V_54 [ V_27 ] ) )
F_23 ( F_28 ( & V_48 -> V_50 -> V_54 [ V_27 ] ) ) ;
}
F_23 ( V_48 -> V_50 -> V_54 ) ;
F_23 ( V_48 -> V_50 -> V_55 ) ;
F_23 ( V_48 -> V_50 -> V_56 ) ;
F_29 ( V_48 -> V_50 ) ;
F_6 ( V_48 -> V_57 ) ;
F_23 ( V_48 ) ;
}
static void F_30 ( struct V_46 * V_48 )
{
struct V_7 * V_8 = V_48 -> V_8 ;
unsigned long V_58 ;
F_31 ( & V_8 -> V_59 , V_58 ) ;
F_32 ( & V_48 -> V_60 , & V_8 -> V_61 ) ;
F_33 ( & V_8 -> V_59 , V_58 ) ;
}
static void F_34 ( struct V_46 * V_48 )
{
struct V_7 * V_8 = V_48 -> V_8 ;
unsigned long V_58 ;
F_31 ( & V_8 -> V_59 , V_58 ) ;
F_35 ( & V_48 -> V_60 ) ;
F_33 ( & V_8 -> V_59 , V_58 ) ;
}
static struct V_46 * F_36 ( struct V_7 * V_8 )
{
unsigned long V_58 ;
struct V_46 * V_48 = NULL ;
F_31 ( & V_8 -> V_59 , V_58 ) ;
if ( ! F_8 ( & V_8 -> V_62 ) ) {
V_48 = F_37 ( V_8 -> V_62 . V_63 , struct V_46 ,
V_60 ) ;
F_35 ( & V_48 -> V_60 ) ;
}
F_33 ( & V_8 -> V_59 , V_58 ) ;
return V_48 ;
}
static struct V_46 * F_38 ( struct V_7 * V_8 ,
void T_3 * V_64 )
{
struct V_46 * V_48 ;
F_39 (as, &ps->async_pending, asynclist)
if ( V_48 -> V_64 == V_64 ) {
F_35 ( & V_48 -> V_60 ) ;
return V_48 ;
}
return NULL ;
}
static void F_40 ( struct V_24 * V_65 ,
void T_3 * V_64 , int V_66 , unsigned V_42 ,
int V_67 , enum V_68 V_69 ,
unsigned char * V_70 , unsigned V_71 )
{
static const char * V_72 [] = { L_1 , L_2 , L_3 , L_4 } ;
static const char * V_73 [] = { L_5 , L_6 } ;
int V_74 ;
const char * V_75 , * V_76 ;
if ( ! V_77 )
return;
V_74 = F_41 ( V_66 ) ;
V_75 = V_72 [ F_42 ( V_66 ) ] ;
V_76 = V_73 [ ! ! F_43 ( V_66 ) ] ;
if ( V_64 ) {
if ( V_69 == V_78 )
F_44 ( & V_65 -> V_10 , L_7
L_8 ,
V_64 , V_74 , V_75 , V_76 , V_42 ) ;
else
F_44 ( & V_65 -> V_10 , L_7
L_9 ,
V_64 , V_74 , V_75 , V_76 , V_42 ,
V_67 ) ;
} else {
if ( V_69 == V_78 )
F_44 ( & V_65 -> V_10 , L_10
L_11 ,
V_74 , V_75 , V_76 , V_42 , V_67 ) ;
else
F_44 ( & V_65 -> V_10 , L_12
L_13 ,
V_74 , V_75 , V_76 , V_42 , V_67 ) ;
}
if ( V_70 && V_71 > 0 ) {
F_45 ( V_79 , L_14 , V_80 , 32 , 1 ,
V_70 , V_71 , 1 ) ;
}
}
static void F_46 ( struct V_50 * V_50 , unsigned V_25 )
{
int V_27 , V_81 ;
if ( ! V_77 )
return;
if ( V_50 -> V_53 == 0 ) {
F_45 ( V_79 , L_14 , V_80 , 32 , 1 ,
V_50 -> V_55 , V_25 , 1 ) ;
return;
}
for ( V_27 = 0 ; V_27 < V_50 -> V_53 && V_25 ; V_27 ++ ) {
V_81 = ( V_25 > V_82 ) ? V_82 : V_25 ;
F_45 ( V_79 , L_14 , V_80 , 32 , 1 ,
F_28 ( & V_50 -> V_54 [ V_27 ] ) , V_81 , 1 ) ;
V_25 -= V_81 ;
}
}
static int F_47 ( T_5 T_3 * V_83 , struct V_50 * V_50 )
{
unsigned V_27 , V_25 , V_81 ;
if ( V_50 -> V_84 > 0 )
V_25 = V_50 -> V_85 ;
else
V_25 = V_50 -> V_86 ;
if ( V_50 -> V_53 == 0 ) {
if ( F_16 ( V_83 , V_50 -> V_55 , V_25 ) )
return - V_37 ;
return 0 ;
}
for ( V_27 = 0 ; V_27 < V_50 -> V_53 && V_25 ; V_27 ++ ) {
V_81 = ( V_25 > V_82 ) ? V_82 : V_25 ;
if ( F_16 ( V_83 , F_28 ( & V_50 -> V_54 [ V_27 ] ) , V_81 ) )
return - V_37 ;
V_83 += V_81 ;
V_25 -= V_81 ;
}
return 0 ;
}
static void F_48 ( struct V_7 * V_8 , unsigned V_87 )
__releases( V_8 -> V_59 )
__acquires( V_8 -> V_59 )
{
struct V_50 * V_50 ;
struct V_46 * V_48 ;
F_39 (as, &ps->async_pending, asynclist) {
if ( V_48 -> V_87 == V_87 ) {
if ( V_48 -> V_88 != V_89 )
goto V_90;
V_48 -> V_88 = V_91 ;
V_48 -> V_87 = 0 ;
}
}
V_8 -> V_92 |= ( 1 << V_87 ) ;
V_90:
F_39 (as, &ps->async_pending, asynclist) {
if ( V_48 -> V_88 == V_91 ) {
V_48 -> V_88 = 0 ;
V_50 = V_48 -> V_50 ;
F_49 ( V_50 ) ;
F_50 ( & V_8 -> V_59 ) ;
F_51 ( V_50 ) ;
F_52 ( V_50 ) ;
F_53 ( & V_8 -> V_59 ) ;
goto V_90;
}
}
}
static void V_62 ( struct V_50 * V_50 )
{
struct V_46 * V_48 = V_50 -> V_93 ;
struct V_7 * V_8 = V_48 -> V_8 ;
struct V_94 V_95 ;
struct V_51 * V_51 = NULL ;
T_6 V_96 = 0 ;
const struct V_52 * V_52 = NULL ;
int V_97 ;
F_53 ( & V_8 -> V_59 ) ;
F_54 ( & V_48 -> V_60 , & V_8 -> V_62 ) ;
V_48 -> V_98 = V_50 -> V_98 ;
V_97 = V_48 -> V_97 ;
if ( V_97 ) {
V_95 . V_99 = V_48 -> V_97 ;
V_95 . V_100 = V_48 -> V_98 ;
V_95 . V_101 = V_102 ;
V_95 . V_103 = V_48 -> V_64 ;
V_51 = F_55 ( V_48 -> V_51 ) ;
V_52 = F_56 ( V_48 -> V_52 ) ;
V_96 = V_48 -> V_96 ;
}
F_57 ( & V_50 -> V_10 -> V_10 , L_15 ) ;
F_40 ( V_50 -> V_10 , V_48 -> V_64 , V_50 -> V_66 , V_50 -> V_86 ,
V_48 -> V_98 , V_104 , NULL , 0 ) ;
if ( ( V_50 -> V_105 & V_106 ) == V_107 )
F_46 ( V_50 , V_50 -> V_86 ) ;
if ( V_48 -> V_98 < 0 && V_48 -> V_87 && V_48 -> V_98 != - V_108 &&
V_48 -> V_98 != - V_109 )
F_48 ( V_8 , V_48 -> V_87 ) ;
F_50 ( & V_8 -> V_59 ) ;
if ( V_97 ) {
F_58 ( V_95 . V_99 , & V_95 , V_51 , V_52 , V_96 ) ;
F_25 ( V_51 ) ;
F_26 ( V_52 ) ;
}
F_59 ( & V_8 -> V_110 ) ;
}
static void F_60 ( struct V_7 * V_8 , struct V_111 * V_9 )
{
struct V_50 * V_50 ;
struct V_46 * V_48 ;
unsigned long V_58 ;
F_31 ( & V_8 -> V_59 , V_58 ) ;
while ( ! F_8 ( V_9 ) ) {
V_48 = F_37 ( V_9 -> V_63 , struct V_46 , V_60 ) ;
F_35 ( & V_48 -> V_60 ) ;
V_50 = V_48 -> V_50 ;
F_49 ( V_50 ) ;
F_33 ( & V_8 -> V_59 , V_58 ) ;
F_61 ( V_50 ) ;
F_52 ( V_50 ) ;
F_31 ( & V_8 -> V_59 , V_58 ) ;
}
F_33 ( & V_8 -> V_59 , V_58 ) ;
}
static void F_62 ( struct V_7 * V_8 ,
unsigned int V_112 )
{
struct V_111 * V_113 , * V_114 , V_115 ;
unsigned long V_58 ;
F_63 ( & V_115 ) ;
F_31 ( & V_8 -> V_59 , V_58 ) ;
F_64 (p, q, &ps->async_pending)
if ( V_112 == F_37 ( V_113 , struct V_46 , V_60 ) -> V_112 )
F_54 ( V_113 , & V_115 ) ;
F_33 ( & V_8 -> V_59 , V_58 ) ;
F_60 ( V_8 , & V_115 ) ;
}
static void F_65 ( struct V_7 * V_8 )
{
F_60 ( V_8 , & V_8 -> V_61 ) ;
}
static int F_66 ( struct V_116 * V_117 ,
const struct V_118 * V_119 )
{
return - V_28 ;
}
static void F_67 ( struct V_116 * V_117 )
{
struct V_7 * V_8 = F_68 ( V_117 ) ;
unsigned int V_112 = V_117 -> V_120 -> V_45 . V_121 ;
if ( ! V_8 )
return;
if ( F_69 ( V_112 < 8 * sizeof( V_8 -> V_122 ) ) )
F_70 ( V_112 , & V_8 -> V_122 ) ;
else
F_71 ( & V_117 -> V_10 , L_16 ,
V_112 ) ;
F_72 ( V_117 , NULL ) ;
F_62 ( V_8 , V_112 ) ;
}
static int F_73 ( struct V_116 * V_117 , T_7 V_123 )
{
return 0 ;
}
static int F_74 ( struct V_116 * V_117 )
{
return 0 ;
}
static int F_75 ( struct V_7 * V_8 , unsigned int V_112 )
{
struct V_24 * V_10 = V_8 -> V_10 ;
struct V_116 * V_117 ;
int V_29 ;
if ( V_112 >= 8 * sizeof( V_8 -> V_122 ) )
return - V_19 ;
if ( F_76 ( V_112 , & V_8 -> V_122 ) )
return 0 ;
V_117 = F_77 ( V_10 , V_112 ) ;
if ( ! V_117 )
V_29 = - V_109 ;
else
V_29 = F_78 ( & V_124 , V_117 , V_8 ) ;
if ( V_29 == 0 )
F_79 ( V_112 , & V_8 -> V_122 ) ;
return V_29 ;
}
static int F_80 ( struct V_7 * V_8 , unsigned int V_112 )
{
struct V_24 * V_10 ;
struct V_116 * V_117 ;
int V_29 ;
V_29 = - V_19 ;
if ( V_112 >= 8 * sizeof( V_8 -> V_122 ) )
return V_29 ;
V_10 = V_8 -> V_10 ;
V_117 = F_77 ( V_10 , V_112 ) ;
if ( ! V_117 )
V_29 = - V_109 ;
else if ( F_81 ( V_112 , & V_8 -> V_122 ) ) {
F_82 ( & V_124 , V_117 ) ;
V_29 = 0 ;
}
return V_29 ;
}
static int F_83 ( struct V_7 * V_8 , unsigned int V_112 )
{
if ( V_8 -> V_10 -> V_11 != V_125 )
return - V_126 ;
if ( V_112 >= 8 * sizeof( V_8 -> V_122 ) )
return - V_19 ;
if ( F_76 ( V_112 , & V_8 -> V_122 ) )
return 0 ;
F_71 ( & V_8 -> V_10 -> V_10 , L_17
L_18 , F_84 ( V_127 ) ,
V_127 -> V_128 , V_112 ) ;
return F_75 ( V_8 , V_112 ) ;
}
static int F_85 ( struct V_24 * V_10 , unsigned int V_74 )
{
unsigned int V_27 , V_129 , V_130 ;
struct V_116 * V_117 ;
struct V_131 * V_132 ;
struct V_133 * V_134 ;
if ( V_74 & ~ ( V_107 | 0xf ) )
return - V_19 ;
if ( ! V_10 -> V_135 )
return - V_136 ;
for ( V_27 = 0 ; V_27 < V_10 -> V_135 -> V_45 . V_137 ; V_27 ++ ) {
V_117 = V_10 -> V_135 -> V_138 [ V_27 ] ;
for ( V_129 = 0 ; V_129 < V_117 -> V_139 ; V_129 ++ ) {
V_132 = & V_117 -> V_120 [ V_129 ] ;
for ( V_130 = 0 ; V_130 < V_132 -> V_45 . V_140 ; V_130 ++ ) {
V_134 = & V_132 -> V_141 [ V_130 ] . V_45 ;
if ( V_134 -> V_142 == V_74 )
return V_132 -> V_45 . V_121 ;
}
}
}
return - V_109 ;
}
static int F_86 ( struct V_7 * V_8 , unsigned int V_143 ,
unsigned int V_144 , unsigned int V_145 )
{
int V_16 = 0 ;
struct V_131 * V_146 ;
if ( V_8 -> V_10 -> V_11 != V_147
&& V_8 -> V_10 -> V_11 != V_148
&& V_8 -> V_10 -> V_11 != V_125 )
return - V_126 ;
if ( V_149 == ( V_150 & V_143 ) )
return 0 ;
if ( V_143 == 0xa1 && V_144 == 0 ) {
V_146 = F_87 ( V_8 -> V_10 -> V_135 ,
V_145 >> 8 , V_145 & 0xff ) ;
if ( V_146
&& V_146 -> V_45 . V_151 == V_152 )
return 0 ;
}
V_145 &= 0xff ;
switch ( V_143 & V_153 ) {
case V_154 :
if ( ( V_145 & ~ V_107 ) == 0 )
return 0 ;
V_16 = F_85 ( V_8 -> V_10 , V_145 ) ;
if ( V_16 < 0 ) {
V_16 = F_85 ( V_8 -> V_10 , V_145 ^ 0x80 ) ;
if ( V_16 >= 0 )
F_44 ( & V_8 -> V_10 -> V_10 ,
L_19 ,
V_155 , F_84 ( V_127 ) ,
V_127 -> V_128 , V_145 , V_145 ^ 0x80 ) ;
}
if ( V_16 >= 0 )
V_16 = F_83 ( V_8 , V_16 ) ;
break;
case V_156 :
V_16 = F_83 ( V_8 , V_145 ) ;
break;
}
return V_16 ;
}
static int F_88 ( struct V_157 * V_10 , void * V_70 )
{
return V_10 -> V_158 == ( V_159 ) ( unsigned long ) V_70 ;
}
static struct V_24 * F_89 ( V_159 V_158 )
{
struct V_157 * V_10 ;
V_10 = F_90 ( & V_160 , NULL ,
( void * ) ( unsigned long ) V_158 , F_88 ) ;
if ( ! V_10 )
return NULL ;
return F_91 ( V_10 , struct V_24 , V_10 ) ;
}
static int F_92 ( struct V_161 * V_161 , struct V_13 * V_13 )
{
struct V_24 * V_10 = NULL ;
struct V_7 * V_8 ;
int V_16 ;
V_16 = - V_6 ;
V_8 = F_93 ( sizeof( struct V_7 ) , V_49 ) ;
if ( ! V_8 )
goto V_162;
V_16 = - V_28 ;
F_10 ( & V_163 ) ;
if ( F_94 ( V_161 ) == V_164 )
V_10 = F_89 ( V_161 -> V_165 ) ;
F_12 ( & V_163 ) ;
if ( ! V_10 )
goto V_162;
F_14 ( V_10 ) ;
if ( V_10 -> V_11 == V_12 )
goto V_166;
V_16 = F_95 ( V_10 ) ;
if ( V_16 )
goto V_166;
V_8 -> V_10 = V_10 ;
V_8 -> V_13 = V_13 ;
F_96 ( & V_8 -> V_59 ) ;
F_63 ( & V_8 -> V_9 ) ;
F_63 ( & V_8 -> V_61 ) ;
F_63 ( & V_8 -> V_62 ) ;
F_97 ( & V_8 -> V_110 ) ;
V_8 -> V_167 = 0 ;
V_8 -> V_168 = F_55 ( F_98 ( V_127 ) ) ;
V_8 -> V_52 = F_99 () ;
V_8 -> V_169 = NULL ;
V_8 -> V_122 = 0 ;
F_100 ( V_127 , & V_8 -> V_96 ) ;
F_101 () ;
F_32 ( & V_8 -> V_9 , & V_10 -> V_170 ) ;
V_13 -> V_23 = V_8 ;
F_19 ( V_10 ) ;
F_57 ( & V_10 -> V_10 , L_20 , F_84 ( V_127 ) ,
V_127 -> V_128 ) ;
return V_16 ;
V_166:
F_19 ( V_10 ) ;
F_102 ( V_10 ) ;
V_162:
F_23 ( V_8 ) ;
return V_16 ;
}
static int F_103 ( struct V_161 * V_161 , struct V_13 * V_13 )
{
struct V_7 * V_8 = V_13 -> V_23 ;
struct V_24 * V_10 = V_8 -> V_10 ;
unsigned int V_112 ;
struct V_46 * V_48 ;
F_14 ( V_10 ) ;
F_104 ( V_10 , V_8 ) ;
F_35 ( & V_8 -> V_9 ) ;
for ( V_112 = 0 ; V_8 -> V_122 && V_112 < 8 * sizeof( V_8 -> V_122 ) ;
V_112 ++ ) {
if ( F_76 ( V_112 , & V_8 -> V_122 ) )
F_80 ( V_8 , V_112 ) ;
}
F_65 ( V_8 ) ;
F_105 ( V_10 ) ;
F_19 ( V_10 ) ;
F_102 ( V_10 ) ;
F_25 ( V_8 -> V_168 ) ;
F_26 ( V_8 -> V_52 ) ;
V_48 = F_36 ( V_8 ) ;
while ( V_48 ) {
F_24 ( V_48 ) ;
V_48 = F_36 ( V_8 ) ;
}
F_23 ( V_8 ) ;
return 0 ;
}
static int F_106 ( struct V_7 * V_8 , void T_3 * V_171 )
{
struct V_24 * V_10 = V_8 -> V_10 ;
struct V_172 V_173 ;
unsigned int V_174 ;
unsigned char * V_175 ;
unsigned V_176 ;
int V_27 , V_66 , V_16 ;
if ( F_107 ( & V_173 , V_171 , sizeof( V_173 ) ) )
return - V_37 ;
V_16 = F_86 ( V_8 , V_173 . V_177 , V_173 . V_178 ,
V_173 . V_179 ) ;
if ( V_16 )
return V_16 ;
V_176 = V_173 . V_176 ;
if ( V_176 > V_180 )
return - V_19 ;
V_16 = F_1 ( V_180 + sizeof( struct V_50 ) +
sizeof( struct V_181 ) ) ;
if ( V_16 )
return V_16 ;
V_175 = ( unsigned char * ) F_108 ( V_49 ) ;
if ( ! V_175 ) {
V_16 = - V_6 ;
goto V_182;
}
V_174 = V_173 . V_183 ;
F_57 ( & V_10 -> V_10 , L_21
L_22
L_23 ,
V_173 . V_177 , V_173 . V_178 , V_173 . V_184 ,
V_173 . V_179 , V_173 . V_176 ) ;
if ( V_173 . V_177 & 0x80 ) {
if ( V_173 . V_176 && ! F_109 ( V_185 , V_173 . V_70 ,
V_173 . V_176 ) ) {
V_16 = - V_19 ;
goto V_182;
}
V_66 = F_110 ( V_10 , 0 ) ;
F_40 ( V_10 , NULL , V_66 , V_173 . V_176 , V_174 , V_78 , NULL , 0 ) ;
F_19 ( V_10 ) ;
V_27 = F_111 ( V_10 , V_66 , V_173 . V_178 ,
V_173 . V_177 , V_173 . V_184 , V_173 . V_179 ,
V_175 , V_173 . V_176 , V_174 ) ;
F_14 ( V_10 ) ;
F_40 ( V_10 , NULL , V_66 , F_112 ( V_27 , 0 ) , F_18 ( V_27 , 0 ) , V_104 ,
V_175 , F_112 ( V_27 , 0 ) ) ;
if ( ( V_27 > 0 ) && V_173 . V_176 ) {
if ( F_16 ( V_173 . V_70 , V_175 , V_27 ) ) {
V_16 = - V_37 ;
goto V_182;
}
}
} else {
if ( V_173 . V_176 ) {
if ( F_107 ( V_175 , V_173 . V_70 , V_173 . V_176 ) ) {
V_16 = - V_37 ;
goto V_182;
}
}
V_66 = F_113 ( V_10 , 0 ) ;
F_40 ( V_10 , NULL , V_66 , V_173 . V_176 , V_174 , V_78 ,
V_175 , V_173 . V_176 ) ;
F_19 ( V_10 ) ;
V_27 = F_111 ( V_10 , F_113 ( V_10 , 0 ) , V_173 . V_178 ,
V_173 . V_177 , V_173 . V_184 , V_173 . V_179 ,
V_175 , V_173 . V_176 , V_174 ) ;
F_14 ( V_10 ) ;
F_40 ( V_10 , NULL , V_66 , F_112 ( V_27 , 0 ) , F_18 ( V_27 , 0 ) , V_104 , NULL , 0 ) ;
}
if ( V_27 < 0 && V_27 != - V_186 ) {
F_114 ( V_79 , & V_10 -> V_10 , L_24
L_25 ,
V_127 -> V_128 , V_173 . V_177 , V_173 . V_178 ,
V_173 . V_176 , V_27 ) ;
}
V_16 = V_27 ;
V_182:
F_115 ( ( unsigned long ) V_175 ) ;
F_6 ( V_180 + sizeof( struct V_50 ) +
sizeof( struct V_181 ) ) ;
return V_16 ;
}
static int F_116 ( struct V_7 * V_8 , void T_3 * V_171 )
{
struct V_24 * V_10 = V_8 -> V_10 ;
struct V_187 V_188 ;
unsigned int V_174 , V_189 , V_66 ;
int V_190 ;
unsigned char * V_175 ;
int V_27 , V_16 ;
if ( F_107 ( & V_188 , V_171 , sizeof( V_188 ) ) )
return - V_37 ;
V_16 = F_85 ( V_8 -> V_10 , V_188 . V_74 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_83 ( V_8 , V_16 ) ;
if ( V_16 )
return V_16 ;
if ( V_188 . V_74 & V_107 )
V_66 = F_117 ( V_10 , V_188 . V_74 & 0x7f ) ;
else
V_66 = F_118 ( V_10 , V_188 . V_74 & 0x7f ) ;
if ( ! F_119 ( V_10 , V_66 , ! ( V_188 . V_74 & V_107 ) ) )
return - V_19 ;
V_189 = V_188 . V_25 ;
if ( V_189 >= V_4 )
return - V_19 ;
V_16 = F_1 ( V_189 + sizeof( struct V_50 ) ) ;
if ( V_16 )
return V_16 ;
if ( ! ( V_175 = F_93 ( V_189 , V_49 ) ) ) {
V_16 = - V_6 ;
goto V_182;
}
V_174 = V_188 . V_183 ;
if ( V_188 . V_74 & 0x80 ) {
if ( V_189 && ! F_109 ( V_185 , V_188 . V_70 , V_189 ) ) {
V_16 = - V_19 ;
goto V_182;
}
F_40 ( V_10 , NULL , V_66 , V_189 , V_174 , V_78 , NULL , 0 ) ;
F_19 ( V_10 ) ;
V_27 = F_120 ( V_10 , V_66 , V_175 , V_189 , & V_190 , V_174 ) ;
F_14 ( V_10 ) ;
F_40 ( V_10 , NULL , V_66 , V_190 , V_27 , V_104 , V_175 , V_190 ) ;
if ( ! V_27 && V_190 ) {
if ( F_16 ( V_188 . V_70 , V_175 , V_190 ) ) {
V_16 = - V_37 ;
goto V_182;
}
}
} else {
if ( V_189 ) {
if ( F_107 ( V_175 , V_188 . V_70 , V_189 ) ) {
V_16 = - V_37 ;
goto V_182;
}
}
F_40 ( V_10 , NULL , V_66 , V_189 , V_174 , V_78 , V_175 , V_189 ) ;
F_19 ( V_10 ) ;
V_27 = F_120 ( V_10 , V_66 , V_175 , V_189 , & V_190 , V_174 ) ;
F_14 ( V_10 ) ;
F_40 ( V_10 , NULL , V_66 , V_190 , V_27 , V_104 , NULL , 0 ) ;
}
V_16 = ( V_27 < 0 ? V_27 : V_190 ) ;
V_182:
F_23 ( V_175 ) ;
F_6 ( V_189 + sizeof( struct V_50 ) ) ;
return V_16 ;
}
static int F_121 ( struct V_7 * V_8 , void T_3 * V_171 )
{
unsigned int V_74 ;
int V_16 ;
if ( F_122 ( V_74 , ( unsigned int T_3 * ) V_171 ) )
return - V_37 ;
V_16 = F_85 ( V_8 -> V_10 , V_74 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_83 ( V_8 , V_16 ) ;
if ( V_16 )
return V_16 ;
F_123 ( V_8 -> V_10 , V_74 ) ;
return 0 ;
}
static int F_124 ( struct V_7 * V_8 , void T_3 * V_171 )
{
unsigned int V_74 ;
int V_66 ;
int V_16 ;
if ( F_122 ( V_74 , ( unsigned int T_3 * ) V_171 ) )
return - V_37 ;
V_16 = F_85 ( V_8 -> V_10 , V_74 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_83 ( V_8 , V_16 ) ;
if ( V_16 )
return V_16 ;
if ( V_74 & V_107 )
V_66 = F_117 ( V_8 -> V_10 , V_74 & 0x7f ) ;
else
V_66 = F_118 ( V_8 -> V_10 , V_74 & 0x7f ) ;
return F_125 ( V_8 -> V_10 , V_66 ) ;
}
static int F_126 ( struct V_7 * V_8 , void T_3 * V_171 )
{
struct V_191 V_192 ;
struct V_116 * V_117 ;
int V_16 ;
if ( F_107 ( & V_192 , V_171 , sizeof( V_192 ) ) )
return - V_37 ;
V_117 = F_77 ( V_8 -> V_10 , V_192 . V_138 ) ;
if ( ! V_117 || ! V_117 -> V_10 . V_193 )
V_16 = - V_194 ;
else {
F_127 ( V_192 . V_193 , V_117 -> V_10 . V_193 -> V_195 ,
sizeof( V_192 . V_193 ) ) ;
V_16 = ( F_16 ( V_171 , & V_192 , sizeof( V_192 ) ) ? - V_37 : 0 ) ;
}
return V_16 ;
}
static int F_128 ( struct V_7 * V_8 , void T_3 * V_171 )
{
struct V_196 V_197 = {
. V_198 = V_8 -> V_10 -> V_198 ,
. V_199 = V_8 -> V_10 -> V_200 == V_201
} ;
if ( F_16 ( V_171 , & V_197 , sizeof( V_197 ) ) )
return - V_37 ;
return 0 ;
}
static int F_129 ( struct V_7 * V_8 )
{
return F_130 ( V_8 -> V_10 ) ;
}
static int F_131 ( struct V_7 * V_8 , void T_3 * V_171 )
{
struct V_202 V_203 ;
int V_16 ;
if ( F_107 ( & V_203 , V_171 , sizeof( V_203 ) ) )
return - V_37 ;
if ( ( V_16 = F_83 ( V_8 , V_203 . V_138 ) ) )
return V_16 ;
return F_132 ( V_8 -> V_10 , V_203 . V_138 ,
V_203 . V_120 ) ;
}
static int F_133 ( struct V_7 * V_8 , void T_3 * V_171 )
{
int V_204 ;
int V_98 = 0 ;
struct V_205 * V_135 ;
if ( F_122 ( V_204 , ( int T_3 * ) V_171 ) )
return - V_37 ;
V_135 = V_8 -> V_10 -> V_135 ;
if ( V_135 ) {
int V_27 ;
for ( V_27 = 0 ; V_27 < V_135 -> V_45 . V_137 ; ++ V_27 ) {
if ( F_134 ( V_135 -> V_138 [ V_27 ] ) ) {
F_71 ( & V_8 -> V_10 -> V_10 ,
L_26
L_27 ,
V_135 -> V_138 [ V_27 ]
-> V_206
-> V_45 . V_121 ,
V_135 -> V_138 [ V_27 ]
-> V_10 . V_193 -> V_195 ,
V_127 -> V_128 , V_204 ) ;
V_98 = - V_207 ;
break;
}
}
}
if ( V_98 == 0 ) {
if ( V_135 && V_135 -> V_45 . V_208 == V_204 )
V_98 = F_135 ( V_8 -> V_10 ) ;
else
V_98 = F_136 ( V_8 -> V_10 , V_204 ) ;
}
return V_98 ;
}
static int F_137 ( struct V_7 * V_8 , struct V_209 * V_210 ,
struct V_211 T_3 * V_212 ,
void T_3 * V_171 )
{
struct V_211 * V_213 = NULL ;
struct V_214 * V_74 ;
struct V_46 * V_48 = NULL ;
struct V_181 * V_215 = NULL ;
unsigned int V_204 , V_216 , V_217 ;
int V_27 , V_16 , V_218 , V_53 = 0 , V_112 = - 1 ;
void * V_20 ;
if ( V_210 -> V_58 & ~ ( V_219 |
V_220 |
V_221 |
V_222 |
V_223 |
V_224 ) )
return - V_19 ;
if ( V_210 -> V_225 > 0 && ! V_210 -> V_226 )
return - V_19 ;
if ( ! ( V_210 -> type == V_227 &&
( V_210 -> V_141 & ~ V_228 ) == 0 ) ) {
V_112 = F_85 ( V_8 -> V_10 , V_210 -> V_141 ) ;
if ( V_112 < 0 )
return V_112 ;
V_16 = F_83 ( V_8 , V_112 ) ;
if ( V_16 )
return V_16 ;
}
if ( ( V_210 -> V_141 & V_228 ) != 0 ) {
V_218 = 1 ;
V_74 = V_8 -> V_10 -> V_229 [ V_210 -> V_141 & V_230 ] ;
} else {
V_218 = 0 ;
V_74 = V_8 -> V_10 -> V_231 [ V_210 -> V_141 & V_230 ] ;
}
if ( ! V_74 )
return - V_109 ;
V_204 = 0 ;
switch( V_210 -> type ) {
case V_227 :
if ( ! F_138 ( & V_74 -> V_45 ) )
return - V_19 ;
if ( V_210 -> V_225 < 8 )
return - V_19 ;
V_215 = F_93 ( sizeof( struct V_181 ) , V_49 ) ;
if ( ! V_215 )
return - V_6 ;
if ( F_107 ( V_215 , V_210 -> V_226 , 8 ) ) {
V_16 = - V_37 ;
goto error;
}
if ( V_210 -> V_225 < ( F_139 ( & V_215 -> V_176 ) + 8 ) ) {
V_16 = - V_19 ;
goto error;
}
V_16 = F_86 ( V_8 , V_215 -> V_177 , V_215 -> V_178 ,
F_139 ( & V_215 -> V_179 ) ) ;
if ( V_16 )
goto error;
V_210 -> V_84 = 0 ;
V_210 -> V_225 = F_139 ( & V_215 -> V_176 ) ;
V_210 -> V_226 += 8 ;
if ( ( V_215 -> V_177 & V_107 ) && V_210 -> V_225 ) {
V_218 = 1 ;
V_210 -> V_141 |= V_107 ;
} else {
V_218 = 0 ;
V_210 -> V_141 &= ~ V_107 ;
}
F_57 ( & V_8 -> V_10 -> V_10 , L_21
L_22
L_23 ,
V_215 -> V_177 , V_215 -> V_178 ,
F_140 ( & V_215 -> V_184 ) ,
F_140 ( & V_215 -> V_179 ) ,
F_140 ( & V_215 -> V_176 ) ) ;
V_204 = sizeof( struct V_181 ) ;
break;
case V_232 :
switch ( F_141 ( & V_74 -> V_45 ) ) {
case V_233 :
case V_234 :
return - V_19 ;
case V_235 :
V_210 -> type = V_236 ;
goto V_237;
}
V_210 -> V_84 = 0 ;
V_53 = F_142 ( V_210 -> V_225 , V_82 ) ;
if ( V_53 == 1 || V_53 > V_8 -> V_10 -> V_238 -> V_239 )
V_53 = 0 ;
break;
case V_236 :
if ( ! F_143 ( & V_74 -> V_45 ) )
return - V_19 ;
V_237:
V_210 -> V_84 = 0 ;
break;
case V_240 :
if ( V_210 -> V_84 < 1 ||
V_210 -> V_84 > 128 )
return - V_19 ;
if ( ! F_144 ( & V_74 -> V_45 ) )
return - V_19 ;
V_217 = sizeof( struct V_211 ) *
V_210 -> V_84 ;
if ( ! ( V_213 = F_93 ( V_217 , V_49 ) ) )
return - V_6 ;
if ( F_107 ( V_213 , V_212 , V_217 ) ) {
V_16 = - V_37 ;
goto error;
}
for ( V_216 = V_204 = 0 ; V_204 < V_210 -> V_84 ; V_204 ++ ) {
if ( V_213 [ V_204 ] . V_42 > 49152 ) {
V_16 = - V_19 ;
goto error;
}
V_216 += V_213 [ V_204 ] . V_42 ;
}
V_204 *= sizeof( struct V_241 ) ;
V_210 -> V_225 = V_216 ;
break;
default:
return - V_19 ;
}
if ( V_210 -> V_225 >= V_4 ) {
V_16 = - V_19 ;
goto error;
}
if ( V_210 -> V_225 > 0 &&
! F_109 ( V_218 ? V_185 : V_242 ,
V_210 -> V_226 , V_210 -> V_225 ) ) {
V_16 = - V_37 ;
goto error;
}
V_48 = F_20 ( V_210 -> V_84 ) ;
if ( ! V_48 ) {
V_16 = - V_6 ;
goto error;
}
V_204 += sizeof( struct V_46 ) + sizeof( struct V_50 ) + V_210 -> V_225 +
V_53 * sizeof( struct V_243 ) ;
V_16 = F_1 ( V_204 ) ;
if ( V_16 )
goto error;
V_48 -> V_57 = V_204 ;
if ( V_53 ) {
V_48 -> V_50 -> V_54 = F_93 ( V_53 * sizeof( struct V_243 ) ,
V_49 ) ;
if ( ! V_48 -> V_50 -> V_54 ) {
V_16 = - V_6 ;
goto error;
}
V_48 -> V_50 -> V_53 = V_53 ;
F_145 ( V_48 -> V_50 -> V_54 , V_48 -> V_50 -> V_53 ) ;
V_216 = V_210 -> V_225 ;
for ( V_27 = 0 ; V_27 < V_48 -> V_50 -> V_53 ; V_27 ++ ) {
V_204 = ( V_216 > V_82 ) ? V_82 : V_216 ;
V_20 = F_93 ( V_204 , V_49 ) ;
if ( ! V_20 ) {
V_16 = - V_6 ;
goto error;
}
F_146 ( & V_48 -> V_50 -> V_54 [ V_27 ] , V_20 , V_204 ) ;
if ( ! V_218 ) {
if ( F_107 ( V_20 , V_210 -> V_226 , V_204 ) ) {
V_16 = - V_37 ;
goto error;
}
V_210 -> V_226 += V_204 ;
}
V_216 -= V_204 ;
}
} else if ( V_210 -> V_225 > 0 ) {
V_48 -> V_50 -> V_55 = F_93 ( V_210 -> V_225 ,
V_49 ) ;
if ( ! V_48 -> V_50 -> V_55 ) {
V_16 = - V_6 ;
goto error;
}
if ( ! V_218 ) {
if ( F_107 ( V_48 -> V_50 -> V_55 ,
V_210 -> V_226 ,
V_210 -> V_225 ) ) {
V_16 = - V_37 ;
goto error;
}
} else if ( V_210 -> type == V_240 ) {
memset ( V_48 -> V_50 -> V_55 , 0 ,
V_210 -> V_225 ) ;
}
}
V_48 -> V_50 -> V_10 = V_8 -> V_10 ;
V_48 -> V_50 -> V_66 = ( V_210 -> type << 30 ) |
F_147 ( V_8 -> V_10 , V_210 -> V_141 & 0xf ) |
( V_210 -> V_141 & V_107 ) ;
V_204 = ( V_218 ? V_244 : V_245 ) ;
if ( V_210 -> V_58 & V_219 )
V_204 |= V_246 ;
if ( V_210 -> V_58 & V_220 )
V_204 |= V_247 ;
if ( V_210 -> V_58 & V_222 )
V_204 |= V_248 ;
if ( V_210 -> V_58 & V_223 )
V_204 |= V_249 ;
if ( V_210 -> V_58 & V_224 )
V_204 |= V_250 ;
V_48 -> V_50 -> V_105 = V_204 ;
V_48 -> V_50 -> V_85 = V_210 -> V_225 ;
V_48 -> V_50 -> V_56 = ( unsigned char * ) V_215 ;
V_215 = NULL ;
V_48 -> V_50 -> V_251 = V_210 -> V_251 ;
V_48 -> V_50 -> V_84 = V_210 -> V_84 ;
if ( V_210 -> type == V_240 ||
V_8 -> V_10 -> V_200 == V_252 )
V_48 -> V_50 -> V_253 = 1 << F_18 ( 15 , V_74 -> V_45 . V_254 - 1 ) ;
else
V_48 -> V_50 -> V_253 = V_74 -> V_45 . V_254 ;
V_48 -> V_50 -> V_93 = V_48 ;
V_48 -> V_50 -> V_255 = V_62 ;
for ( V_216 = V_204 = 0 ; V_204 < V_210 -> V_84 ; V_204 ++ ) {
V_48 -> V_50 -> V_212 [ V_204 ] . V_14 = V_216 ;
V_48 -> V_50 -> V_212 [ V_204 ] . V_42 = V_213 [ V_204 ] . V_42 ;
V_216 += V_213 [ V_204 ] . V_42 ;
}
F_23 ( V_213 ) ;
V_213 = NULL ;
V_48 -> V_8 = V_8 ;
V_48 -> V_64 = V_171 ;
if ( V_218 && V_210 -> V_225 > 0 )
V_48 -> V_83 = V_210 -> V_226 ;
else
V_48 -> V_83 = NULL ;
V_48 -> V_97 = V_210 -> V_97 ;
V_48 -> V_112 = V_112 ;
V_48 -> V_51 = F_55 ( F_98 ( V_127 ) ) ;
V_48 -> V_52 = F_99 () ;
F_100 ( V_127 , & V_48 -> V_96 ) ;
F_40 ( V_8 -> V_10 , V_48 -> V_64 , V_48 -> V_50 -> V_66 ,
V_48 -> V_50 -> V_85 , 0 , V_78 ,
NULL , 0 ) ;
if ( ! V_218 )
F_46 ( V_48 -> V_50 , V_48 -> V_50 -> V_85 ) ;
F_30 ( V_48 ) ;
if ( F_148 ( & V_74 -> V_45 ) ) {
F_149 ( & V_8 -> V_59 ) ;
V_48 -> V_87 = F_150 ( & V_74 -> V_45 ) |
( ( V_74 -> V_45 . V_142 & V_228 )
>> 3 ) ;
if ( V_210 -> V_58 & V_221 )
V_48 -> V_88 = V_89 ;
else
V_8 -> V_92 &= ~ ( 1 << V_48 -> V_87 ) ;
if ( V_8 -> V_92 & ( 1 << V_48 -> V_87 ) )
V_16 = - V_256 ;
else
V_16 = F_151 ( V_48 -> V_50 , V_257 ) ;
F_152 ( & V_8 -> V_59 ) ;
} else {
V_16 = F_151 ( V_48 -> V_50 , V_49 ) ;
}
if ( V_16 ) {
F_114 ( V_79 , & V_8 -> V_10 -> V_10 ,
L_28 , V_16 ) ;
F_40 ( V_8 -> V_10 , V_48 -> V_64 , V_48 -> V_50 -> V_66 ,
0 , V_16 , V_104 , NULL , 0 ) ;
F_34 ( V_48 ) ;
goto error;
}
return 0 ;
error:
F_23 ( V_213 ) ;
F_23 ( V_215 ) ;
if ( V_48 )
F_24 ( V_48 ) ;
return V_16 ;
}
static int F_153 ( struct V_7 * V_8 , void T_3 * V_171 )
{
struct V_209 V_210 ;
if ( F_107 ( & V_210 , V_171 , sizeof( V_210 ) ) )
return - V_37 ;
return F_137 ( V_8 , & V_210 ,
( ( (struct V_209 T_3 * ) V_171 ) -> V_212 ) ,
V_171 ) ;
}
static int F_154 ( struct V_7 * V_8 , void T_3 * V_171 )
{
struct V_50 * V_50 ;
struct V_46 * V_48 ;
unsigned long V_58 ;
F_31 ( & V_8 -> V_59 , V_58 ) ;
V_48 = F_38 ( V_8 , V_171 ) ;
if ( ! V_48 ) {
F_33 ( & V_8 -> V_59 , V_58 ) ;
return - V_19 ;
}
V_50 = V_48 -> V_50 ;
F_49 ( V_50 ) ;
F_33 ( & V_8 -> V_59 , V_58 ) ;
F_61 ( V_50 ) ;
F_52 ( V_50 ) ;
return 0 ;
}
static int F_155 ( struct V_46 * V_48 , void T_3 * T_3 * V_171 )
{
struct V_50 * V_50 = V_48 -> V_50 ;
struct V_209 T_3 * V_64 = V_48 -> V_64 ;
void T_3 * V_258 = V_48 -> V_64 ;
unsigned int V_27 ;
if ( V_48 -> V_83 && V_50 -> V_86 ) {
if ( F_47 ( V_48 -> V_83 , V_50 ) )
goto V_259;
}
if ( F_156 ( V_48 -> V_98 , & V_64 -> V_98 ) )
goto V_259;
if ( F_156 ( V_50 -> V_86 , & V_64 -> V_86 ) )
goto V_259;
if ( F_156 ( V_50 -> V_260 , & V_64 -> V_260 ) )
goto V_259;
if ( F_144 ( & V_50 -> V_74 -> V_45 ) ) {
for ( V_27 = 0 ; V_27 < V_50 -> V_84 ; V_27 ++ ) {
if ( F_156 ( V_50 -> V_212 [ V_27 ] . V_86 ,
& V_64 -> V_212 [ V_27 ] . V_86 ) )
goto V_259;
if ( F_156 ( V_50 -> V_212 [ V_27 ] . V_98 ,
& V_64 -> V_212 [ V_27 ] . V_98 ) )
goto V_259;
}
}
if ( F_156 ( V_258 , ( void T_3 * T_3 * ) V_171 ) )
return - V_37 ;
return 0 ;
V_259:
return - V_37 ;
}
static struct V_46 * F_157 ( struct V_7 * V_8 )
{
F_158 ( V_110 , V_127 ) ;
struct V_46 * V_48 = NULL ;
struct V_24 * V_10 = V_8 -> V_10 ;
F_159 ( & V_8 -> V_110 , & V_110 ) ;
for (; ; ) {
F_160 ( V_261 ) ;
V_48 = F_36 ( V_8 ) ;
if ( V_48 )
break;
if ( F_161 ( V_127 ) )
break;
F_19 ( V_10 ) ;
F_162 () ;
F_14 ( V_10 ) ;
}
F_163 ( & V_8 -> V_110 , & V_110 ) ;
F_164 ( V_262 ) ;
return V_48 ;
}
static int F_165 ( struct V_7 * V_8 , void T_3 * V_171 )
{
struct V_46 * V_48 = F_157 ( V_8 ) ;
if ( V_48 ) {
int V_263 = F_155 ( V_48 , ( void T_3 * T_3 * ) V_171 ) ;
F_24 ( V_48 ) ;
return V_263 ;
}
if ( F_161 ( V_127 ) )
return - V_264 ;
return - V_265 ;
}
static int F_166 ( struct V_7 * V_8 , void T_3 * V_171 )
{
int V_263 ;
struct V_46 * V_48 ;
V_48 = F_36 ( V_8 ) ;
V_263 = - V_266 ;
if ( V_48 ) {
V_263 = F_155 ( V_48 , ( void T_3 * T_3 * ) V_171 ) ;
F_24 ( V_48 ) ;
}
return V_263 ;
}
static int F_167 ( struct V_7 * V_8 ,
struct V_267 T_3 * V_268 )
{
struct V_172 T_3 * V_113 ;
T_8 V_269 ;
V_113 = F_168 ( sizeof( * V_113 ) ) ;
if ( F_169 ( V_113 , V_268 , ( sizeof( * V_268 ) - sizeof( V_270 ) ) ) ||
F_122 ( V_269 , & V_268 -> V_70 ) ||
F_156 ( F_170 ( V_269 ) , & V_113 -> V_70 ) )
return - V_37 ;
return F_106 ( V_8 , V_113 ) ;
}
static int F_171 ( struct V_7 * V_8 ,
struct V_271 T_3 * V_268 )
{
struct V_187 T_3 * V_113 ;
T_9 V_272 ;
V_270 V_258 ;
V_113 = F_168 ( sizeof( * V_113 ) ) ;
if ( F_122 ( V_272 , & V_268 -> V_74 ) || F_156 ( V_272 , & V_113 -> V_74 ) ||
F_122 ( V_272 , & V_268 -> V_25 ) || F_156 ( V_272 , & V_113 -> V_25 ) ||
F_122 ( V_272 , & V_268 -> V_183 ) || F_156 ( V_272 , & V_113 -> V_183 ) ||
F_122 ( V_258 , & V_268 -> V_70 ) || F_156 ( F_170 ( V_258 ) , & V_113 -> V_70 ) )
return - V_37 ;
return F_116 ( V_8 , V_113 ) ;
}
static int F_172 ( struct V_7 * V_8 , void T_3 * V_171 )
{
struct V_273 V_274 ;
if ( F_107 ( & V_274 , V_171 , sizeof( V_274 ) ) )
return - V_37 ;
V_8 -> V_167 = V_274 . V_97 ;
V_8 -> V_169 = F_170 ( V_274 . V_93 ) ;
return 0 ;
}
static int F_173 ( struct V_209 * V_275 ,
struct V_276 T_3 * V_210 )
{
T_8 V_277 ;
if ( ! F_109 ( V_242 , V_210 , sizeof( * V_210 ) ) ||
F_174 ( V_275 -> type , & V_210 -> type ) ||
F_174 ( V_275 -> V_141 , & V_210 -> V_141 ) ||
F_174 ( V_275 -> V_98 , & V_210 -> V_98 ) ||
F_174 ( V_275 -> V_58 , & V_210 -> V_58 ) ||
F_174 ( V_275 -> V_225 , & V_210 -> V_225 ) ||
F_174 ( V_275 -> V_86 , & V_210 -> V_86 ) ||
F_174 ( V_275 -> V_251 , & V_210 -> V_251 ) ||
F_174 ( V_275 -> V_84 , & V_210 -> V_84 ) ||
F_174 ( V_275 -> V_260 , & V_210 -> V_260 ) ||
F_174 ( V_275 -> V_97 , & V_210 -> V_97 ) )
return - V_37 ;
if ( F_174 ( V_277 , & V_210 -> V_226 ) )
return - V_37 ;
V_275 -> V_226 = F_170 ( V_277 ) ;
if ( F_174 ( V_277 , & V_210 -> V_278 ) )
return - V_37 ;
V_275 -> V_278 = F_170 ( V_277 ) ;
return 0 ;
}
static int F_175 ( struct V_7 * V_8 , void T_3 * V_171 )
{
struct V_209 V_210 ;
if ( F_173 ( & V_210 , (struct V_276 T_3 * ) V_171 ) )
return - V_37 ;
return F_137 ( V_8 , & V_210 ,
( (struct V_276 T_3 * ) V_171 ) -> V_212 ,
V_171 ) ;
}
static int F_176 ( struct V_46 * V_48 , void T_3 * T_3 * V_171 )
{
struct V_50 * V_50 = V_48 -> V_50 ;
struct V_276 T_3 * V_64 = V_48 -> V_64 ;
void T_3 * V_258 = V_48 -> V_64 ;
unsigned int V_27 ;
if ( V_48 -> V_83 && V_50 -> V_86 ) {
if ( F_47 ( V_48 -> V_83 , V_50 ) )
return - V_37 ;
}
if ( F_156 ( V_48 -> V_98 , & V_64 -> V_98 ) )
return - V_37 ;
if ( F_156 ( V_50 -> V_86 , & V_64 -> V_86 ) )
return - V_37 ;
if ( F_156 ( V_50 -> V_260 , & V_64 -> V_260 ) )
return - V_37 ;
if ( F_144 ( & V_50 -> V_74 -> V_45 ) ) {
for ( V_27 = 0 ; V_27 < V_50 -> V_84 ; V_27 ++ ) {
if ( F_156 ( V_50 -> V_212 [ V_27 ] . V_86 ,
& V_64 -> V_212 [ V_27 ] . V_86 ) )
return - V_37 ;
if ( F_156 ( V_50 -> V_212 [ V_27 ] . V_98 ,
& V_64 -> V_212 [ V_27 ] . V_98 ) )
return - V_37 ;
}
}
if ( F_156 ( F_177 ( V_258 ) , ( T_6 T_3 * ) V_171 ) )
return - V_37 ;
return 0 ;
}
static int F_178 ( struct V_7 * V_8 , void T_3 * V_171 )
{
struct V_46 * V_48 = F_157 ( V_8 ) ;
if ( V_48 ) {
int V_263 = F_176 ( V_48 , ( void T_3 * T_3 * ) V_171 ) ;
F_24 ( V_48 ) ;
return V_263 ;
}
if ( F_161 ( V_127 ) )
return - V_264 ;
return - V_265 ;
}
static int F_179 ( struct V_7 * V_8 , void T_3 * V_171 )
{
int V_263 ;
struct V_46 * V_48 ;
V_263 = - V_266 ;
V_48 = F_36 ( V_8 ) ;
if ( V_48 ) {
V_263 = F_176 ( V_48 , ( void T_3 * T_3 * ) V_171 ) ;
F_24 ( V_48 ) ;
}
return V_263 ;
}
static int F_180 ( struct V_7 * V_8 , void T_3 * V_171 )
{
struct V_279 V_274 ;
if ( F_107 ( & V_274 , V_171 , sizeof( V_274 ) ) )
return - V_37 ;
V_8 -> V_167 = V_274 . V_97 ;
V_8 -> V_169 = V_274 . V_93 ;
return 0 ;
}
static int F_181 ( struct V_7 * V_8 , void T_3 * V_171 )
{
unsigned int V_112 ;
if ( F_122 ( V_112 , ( unsigned int T_3 * ) V_171 ) )
return - V_37 ;
return F_75 ( V_8 , V_112 ) ;
}
static int F_182 ( struct V_7 * V_8 , void T_3 * V_171 )
{
unsigned int V_112 ;
int V_16 ;
if ( F_122 ( V_112 , ( unsigned int T_3 * ) V_171 ) )
return - V_37 ;
if ( ( V_16 = F_80 ( V_8 , V_112 ) ) < 0 )
return V_16 ;
F_62 ( V_8 , V_112 ) ;
return 0 ;
}
static int F_183 ( struct V_7 * V_8 , struct V_280 * V_281 )
{
int V_81 ;
void * V_20 = NULL ;
int V_263 = 0 ;
struct V_116 * V_117 = NULL ;
struct V_282 * V_193 = NULL ;
if ( ( V_81 = F_184 ( V_281 -> V_283 ) ) > 0 ) {
V_20 = F_93 ( V_81 , V_49 ) ;
if ( V_20 == NULL )
return - V_6 ;
if ( ( F_185 ( V_281 -> V_283 ) & V_284 ) ) {
if ( F_107 ( V_20 , V_281 -> V_70 , V_81 ) ) {
F_23 ( V_20 ) ;
return - V_37 ;
}
} else {
memset ( V_20 , 0 , V_81 ) ;
}
}
if ( ! F_7 ( V_8 ) ) {
F_23 ( V_20 ) ;
return - V_28 ;
}
if ( V_8 -> V_10 -> V_11 != V_125 )
V_263 = - V_126 ;
else if ( ! ( V_117 = F_77 ( V_8 -> V_10 , V_281 -> V_285 ) ) )
V_263 = - V_19 ;
else switch ( V_281 -> V_283 ) {
case V_286 :
if ( V_117 -> V_10 . V_193 ) {
V_193 = F_186 ( V_117 -> V_10 . V_193 ) ;
F_187 ( & V_117 -> V_10 , L_29 ) ;
F_82 ( V_193 , V_117 ) ;
} else
V_263 = - V_194 ;
break;
case V_287 :
if ( ! V_117 -> V_10 . V_193 )
V_263 = F_188 ( & V_117 -> V_10 ) ;
else
V_263 = - V_207 ;
break;
default:
if ( V_117 -> V_10 . V_193 )
V_193 = F_186 ( V_117 -> V_10 . V_193 ) ;
if ( V_193 == NULL || V_193 -> V_288 == NULL ) {
V_263 = - V_289 ;
} else {
V_263 = V_193 -> V_288 ( V_117 , V_281 -> V_283 , V_20 ) ;
if ( V_263 == - V_290 )
V_263 = - V_289 ;
}
}
if ( V_263 >= 0
&& ( F_185 ( V_281 -> V_283 ) & V_291 ) != 0
&& V_81 > 0
&& F_16 ( V_281 -> V_70 , V_20 , V_81 ) != 0 )
V_263 = - V_37 ;
F_23 ( V_20 ) ;
return V_263 ;
}
static int F_189 ( struct V_7 * V_8 , void T_3 * V_171 )
{
struct V_280 V_173 ;
if ( F_107 ( & V_173 , V_171 , sizeof( V_173 ) ) )
return - V_37 ;
return F_183 ( V_8 , & V_173 ) ;
}
static int F_190 ( struct V_7 * V_8 , T_10 V_171 )
{
struct V_292 T_3 * V_293 ;
struct V_280 V_173 ;
T_6 V_269 ;
V_293 = F_170 ( ( long ) V_171 ) ;
if ( ! F_109 ( V_242 , V_293 , sizeof( * V_293 ) ) ||
F_174 ( V_173 . V_285 , & V_293 -> V_285 ) ||
F_174 ( V_173 . V_283 , & V_293 -> V_283 ) ||
F_174 ( V_269 , & V_293 -> V_70 ) )
return - V_37 ;
V_173 . V_70 = F_170 ( V_269 ) ;
return F_183 ( V_8 , & V_173 ) ;
}
static int F_191 ( struct V_7 * V_8 , void T_3 * V_171 )
{
unsigned V_294 ;
int V_295 ;
if ( F_122 ( V_294 , ( unsigned T_3 * ) V_171 ) )
return - V_37 ;
V_295 = F_192 ( V_8 -> V_10 , V_294 , V_8 ) ;
if ( V_295 == 0 )
F_57 ( & V_8 -> V_10 -> V_10 , L_30 ,
V_294 , F_84 ( V_127 ) , V_127 -> V_128 ) ;
return V_295 ;
}
static int F_193 ( struct V_7 * V_8 , void T_3 * V_171 )
{
unsigned V_294 ;
if ( F_122 ( V_294 , ( unsigned T_3 * ) V_171 ) )
return - V_37 ;
return F_194 ( V_8 -> V_10 , V_294 , V_8 ) ;
}
static int F_195 ( struct V_7 * V_8 , void T_3 * V_171 )
{
T_8 V_296 ;
V_296 = V_297 | V_298 ;
if ( ! V_8 -> V_10 -> V_238 -> V_299 )
V_296 |= V_300 ;
if ( V_8 -> V_10 -> V_238 -> V_239 )
V_296 |= V_301 ;
if ( F_156 ( V_296 , ( T_8 T_3 * ) V_171 ) )
return - V_37 ;
return 0 ;
}
static int F_196 ( struct V_7 * V_8 , void T_3 * V_171 )
{
struct V_302 V_303 ;
struct V_116 * V_117 ;
if ( F_107 ( & V_303 , V_171 , sizeof( V_303 ) ) )
return - V_37 ;
V_117 = F_77 ( V_8 -> V_10 , V_303 . V_138 ) ;
if ( ! V_117 )
return - V_19 ;
if ( V_117 -> V_10 . V_193 ) {
struct V_282 * V_193 = F_186 ( V_117 -> V_10 . V_193 ) ;
if ( ( V_303 . V_58 & V_304 ) &&
strncmp ( V_303 . V_193 , V_117 -> V_10 . V_193 -> V_195 ,
sizeof( V_303 . V_193 ) ) != 0 )
return - V_207 ;
if ( ( V_303 . V_58 & V_305 ) &&
strncmp ( V_303 . V_193 , V_117 -> V_10 . V_193 -> V_195 ,
sizeof( V_303 . V_193 ) ) == 0 )
return - V_207 ;
F_187 ( & V_117 -> V_10 , L_29 ) ;
F_82 ( V_193 , V_117 ) ;
}
return F_75 ( V_8 , V_303 . V_138 ) ;
}
static long F_197 ( struct V_13 * V_13 , unsigned int V_306 ,
void T_3 * V_113 )
{
struct V_7 * V_8 = V_13 -> V_23 ;
struct V_161 * V_161 = F_11 ( V_13 ) ;
struct V_24 * V_10 = V_8 -> V_10 ;
int V_16 = - V_289 ;
if ( ! ( V_13 -> V_307 & V_308 ) )
return - V_309 ;
F_14 ( V_10 ) ;
if ( ! F_7 ( V_8 ) ) {
F_19 ( V_10 ) ;
return - V_28 ;
}
switch ( V_306 ) {
case V_310 :
F_57 ( & V_10 -> V_10 , L_31 , V_155 ) ;
V_16 = F_106 ( V_8 , V_113 ) ;
if ( V_16 >= 0 )
V_161 -> V_311 = V_312 ;
break;
case V_313 :
F_57 ( & V_10 -> V_10 , L_32 , V_155 ) ;
V_16 = F_116 ( V_8 , V_113 ) ;
if ( V_16 >= 0 )
V_161 -> V_311 = V_312 ;
break;
case V_314 :
F_57 ( & V_10 -> V_10 , L_33 , V_155 ) ;
V_16 = F_121 ( V_8 , V_113 ) ;
if ( V_16 >= 0 )
V_161 -> V_311 = V_312 ;
break;
case V_315 :
F_57 ( & V_10 -> V_10 , L_34 , V_155 ) ;
V_16 = F_129 ( V_8 ) ;
break;
case V_316 :
F_57 ( & V_10 -> V_10 , L_35 , V_155 ) ;
V_16 = F_124 ( V_8 , V_113 ) ;
if ( V_16 >= 0 )
V_161 -> V_311 = V_312 ;
break;
case V_317 :
F_57 ( & V_10 -> V_10 , L_36 , V_155 ) ;
V_16 = F_126 ( V_8 , V_113 ) ;
break;
case V_318 :
F_57 ( & V_10 -> V_10 , L_37 , V_155 ) ;
V_16 = F_128 ( V_8 , V_113 ) ;
break;
case V_319 :
F_57 ( & V_10 -> V_10 , L_38 , V_155 ) ;
V_16 = F_131 ( V_8 , V_113 ) ;
break;
case V_320 :
F_57 ( & V_10 -> V_10 , L_39 , V_155 ) ;
V_16 = F_133 ( V_8 , V_113 ) ;
break;
case V_321 :
F_57 ( & V_10 -> V_10 , L_40 , V_155 ) ;
V_16 = F_153 ( V_8 , V_113 ) ;
if ( V_16 >= 0 )
V_161 -> V_311 = V_312 ;
break;
#ifdef F_198
case V_322 :
F_57 ( & V_10 -> V_10 , L_41 , V_155 ) ;
V_16 = F_167 ( V_8 , V_113 ) ;
if ( V_16 >= 0 )
V_161 -> V_311 = V_312 ;
break;
case V_323 :
F_57 ( & V_10 -> V_10 , L_42 , V_155 ) ;
V_16 = F_171 ( V_8 , V_113 ) ;
if ( V_16 >= 0 )
V_161 -> V_311 = V_312 ;
break;
case V_324 :
F_57 ( & V_10 -> V_10 , L_43 , V_155 ) ;
V_16 = F_172 ( V_8 , V_113 ) ;
break;
case V_325 :
F_57 ( & V_10 -> V_10 , L_44 , V_155 ) ;
V_16 = F_175 ( V_8 , V_113 ) ;
if ( V_16 >= 0 )
V_161 -> V_311 = V_312 ;
break;
case V_326 :
F_57 ( & V_10 -> V_10 , L_45 , V_155 ) ;
V_16 = F_178 ( V_8 , V_113 ) ;
break;
case V_327 :
F_57 ( & V_10 -> V_10 , L_46 , V_155 ) ;
V_16 = F_179 ( V_8 , V_113 ) ;
break;
case V_328 :
F_57 ( & V_10 -> V_10 , L_47 , V_155 ) ;
V_16 = F_190 ( V_8 , F_177 ( V_113 ) ) ;
break;
#endif
case V_329 :
F_57 ( & V_10 -> V_10 , L_48 , V_155 ) ;
V_16 = F_154 ( V_8 , V_113 ) ;
break;
case V_330 :
F_57 ( & V_10 -> V_10 , L_49 , V_155 ) ;
V_16 = F_165 ( V_8 , V_113 ) ;
break;
case V_331 :
F_57 ( & V_10 -> V_10 , L_50 , V_155 ) ;
V_16 = F_166 ( V_8 , V_113 ) ;
break;
case V_332 :
F_57 ( & V_10 -> V_10 , L_51 , V_155 ) ;
V_16 = F_180 ( V_8 , V_113 ) ;
break;
case V_333 :
F_57 ( & V_10 -> V_10 , L_52 , V_155 ) ;
V_16 = F_181 ( V_8 , V_113 ) ;
break;
case V_334 :
F_57 ( & V_10 -> V_10 , L_53 , V_155 ) ;
V_16 = F_182 ( V_8 , V_113 ) ;
break;
case V_335 :
F_57 ( & V_10 -> V_10 , L_54 , V_155 ) ;
V_16 = F_189 ( V_8 , V_113 ) ;
break;
case V_336 :
F_57 ( & V_10 -> V_10 , L_55 , V_155 ) ;
V_16 = F_191 ( V_8 , V_113 ) ;
break;
case V_337 :
F_57 ( & V_10 -> V_10 , L_56 , V_155 ) ;
V_16 = F_193 ( V_8 , V_113 ) ;
break;
case V_338 :
V_16 = F_195 ( V_8 , V_113 ) ;
break;
case V_339 :
V_16 = F_196 ( V_8 , V_113 ) ;
break;
}
F_19 ( V_10 ) ;
if ( V_16 >= 0 )
V_161 -> V_340 = V_312 ;
return V_16 ;
}
static long F_199 ( struct V_13 * V_13 , unsigned int V_306 ,
unsigned long V_171 )
{
int V_16 ;
V_16 = F_197 ( V_13 , V_306 , ( void T_3 * ) V_171 ) ;
return V_16 ;
}
static long F_200 ( struct V_13 * V_13 , unsigned int V_306 ,
unsigned long V_171 )
{
int V_16 ;
V_16 = F_197 ( V_13 , V_306 , F_170 ( V_171 ) ) ;
return V_16 ;
}
static unsigned int F_201 ( struct V_13 * V_13 ,
struct V_341 * V_110 )
{
struct V_7 * V_8 = V_13 -> V_23 ;
unsigned int V_342 = 0 ;
F_202 ( V_13 , & V_8 -> V_110 , V_110 ) ;
if ( V_13 -> V_307 & V_308 && ! F_8 ( & V_8 -> V_62 ) )
V_342 |= V_343 | V_344 ;
if ( ! F_7 ( V_8 ) )
V_342 |= V_345 | V_346 ;
return V_342 ;
}
static void F_203 ( struct V_24 * V_65 )
{
struct V_7 * V_8 ;
struct V_94 V_95 ;
while ( ! F_8 ( & V_65 -> V_170 ) ) {
V_8 = F_37 ( V_65 -> V_170 . V_63 , struct V_7 , V_9 ) ;
F_65 ( V_8 ) ;
F_204 ( & V_8 -> V_110 ) ;
F_35 ( & V_8 -> V_9 ) ;
if ( V_8 -> V_167 ) {
V_95 . V_99 = V_8 -> V_167 ;
V_95 . V_100 = V_186 ;
V_95 . V_101 = V_102 ;
V_95 . V_103 = V_8 -> V_169 ;
F_58 ( V_8 -> V_167 , & V_95 ,
V_8 -> V_168 , V_8 -> V_52 , V_8 -> V_96 ) ;
}
}
}
static int F_205 ( struct V_347 * V_348 ,
unsigned long V_349 , void * V_10 )
{
switch ( V_349 ) {
case V_350 :
break;
case V_351 :
F_203 ( V_10 ) ;
break;
}
return V_352 ;
}
int T_11 F_206 ( void )
{
int V_263 ;
V_263 = F_207 ( V_353 , V_354 ,
L_57 ) ;
if ( V_263 ) {
F_208 ( V_355 L_58 ) ;
goto V_356;
}
F_209 ( & V_357 , & V_358 ) ;
V_263 = F_210 ( & V_357 , V_353 , V_354 ) ;
if ( V_263 ) {
F_208 ( V_355 L_59 ,
V_164 ) ;
goto V_359;
}
F_211 ( & V_360 ) ;
V_356:
return V_263 ;
V_359:
F_212 ( V_353 , V_354 ) ;
goto V_356;
}
void F_213 ( void )
{
F_214 ( & V_360 ) ;
F_215 ( & V_357 ) ;
F_212 ( V_353 , V_354 ) ;
}
