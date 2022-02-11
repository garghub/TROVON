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
V_145 >>= 8 ;
}
V_145 &= 0xff ;
switch ( V_143 & V_153 ) {
case V_154 :
V_16 = F_85 ( V_8 -> V_10 , V_145 ) ;
if ( V_16 >= 0 )
V_16 = F_83 ( V_8 , V_16 ) ;
break;
case V_155 :
V_16 = F_83 ( V_8 , V_145 ) ;
break;
}
return V_16 ;
}
static int F_88 ( struct V_156 * V_10 , void * V_70 )
{
return V_10 -> V_157 == ( V_158 ) ( unsigned long ) V_70 ;
}
static struct V_24 * F_89 ( V_158 V_157 )
{
struct V_156 * V_10 ;
V_10 = F_90 ( & V_159 , NULL ,
( void * ) ( unsigned long ) V_157 , F_88 ) ;
if ( ! V_10 )
return NULL ;
return F_91 ( V_10 , struct V_24 , V_10 ) ;
}
static int F_92 ( struct V_160 * V_160 , struct V_13 * V_13 )
{
struct V_24 * V_10 = NULL ;
struct V_7 * V_8 ;
int V_16 ;
V_16 = - V_6 ;
V_8 = F_93 ( sizeof( struct V_7 ) , V_49 ) ;
if ( ! V_8 )
goto V_161;
V_16 = - V_28 ;
F_10 ( & V_162 ) ;
if ( F_94 ( V_160 ) == V_163 )
V_10 = F_89 ( V_160 -> V_164 ) ;
F_12 ( & V_162 ) ;
if ( ! V_10 )
goto V_161;
F_14 ( V_10 ) ;
if ( V_10 -> V_11 == V_12 )
goto V_165;
V_16 = F_95 ( V_10 ) ;
if ( V_16 )
goto V_165;
V_8 -> V_10 = V_10 ;
V_8 -> V_13 = V_13 ;
F_96 ( & V_8 -> V_59 ) ;
F_63 ( & V_8 -> V_9 ) ;
F_63 ( & V_8 -> V_61 ) ;
F_63 ( & V_8 -> V_62 ) ;
F_97 ( & V_8 -> V_110 ) ;
V_8 -> V_166 = 0 ;
V_8 -> V_167 = F_55 ( F_98 ( V_127 ) ) ;
V_8 -> V_52 = F_99 () ;
V_8 -> V_168 = NULL ;
V_8 -> V_122 = 0 ;
F_100 ( V_127 , & V_8 -> V_96 ) ;
F_101 () ;
F_32 ( & V_8 -> V_9 , & V_10 -> V_169 ) ;
V_13 -> V_23 = V_8 ;
F_19 ( V_10 ) ;
F_57 ( & V_10 -> V_10 , L_19 , F_84 ( V_127 ) ,
V_127 -> V_128 ) ;
return V_16 ;
V_165:
F_19 ( V_10 ) ;
F_102 ( V_10 ) ;
V_161:
F_23 ( V_8 ) ;
return V_16 ;
}
static int F_103 ( struct V_160 * V_160 , struct V_13 * V_13 )
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
F_25 ( V_8 -> V_167 ) ;
F_26 ( V_8 -> V_52 ) ;
V_48 = F_36 ( V_8 ) ;
while ( V_48 ) {
F_24 ( V_48 ) ;
V_48 = F_36 ( V_8 ) ;
}
F_23 ( V_8 ) ;
return 0 ;
}
static int F_106 ( struct V_7 * V_8 , void T_3 * V_170 )
{
struct V_24 * V_10 = V_8 -> V_10 ;
struct V_171 V_172 ;
unsigned int V_173 ;
unsigned char * V_174 ;
unsigned V_175 ;
int V_27 , V_66 , V_16 ;
if ( F_107 ( & V_172 , V_170 , sizeof( V_172 ) ) )
return - V_37 ;
V_16 = F_86 ( V_8 , V_172 . V_176 , V_172 . V_177 ,
V_172 . V_178 ) ;
if ( V_16 )
return V_16 ;
V_175 = V_172 . V_175 ;
if ( V_175 > V_179 )
return - V_19 ;
V_16 = F_1 ( V_179 + sizeof( struct V_50 ) +
sizeof( struct V_180 ) ) ;
if ( V_16 )
return V_16 ;
V_174 = ( unsigned char * ) F_108 ( V_49 ) ;
if ( ! V_174 ) {
V_16 = - V_6 ;
goto V_181;
}
V_173 = V_172 . V_182 ;
F_57 ( & V_10 -> V_10 , L_20
L_21
L_22 ,
V_172 . V_176 , V_172 . V_177 ,
F_109 ( & V_172 . V_183 ) ,
F_109 ( & V_172 . V_178 ) ,
F_109 ( & V_172 . V_175 ) ) ;
if ( V_172 . V_176 & 0x80 ) {
if ( V_172 . V_175 && ! F_110 ( V_184 , V_172 . V_70 ,
V_172 . V_175 ) ) {
V_16 = - V_19 ;
goto V_181;
}
V_66 = F_111 ( V_10 , 0 ) ;
F_40 ( V_10 , NULL , V_66 , V_172 . V_175 , V_173 , V_78 , NULL , 0 ) ;
F_19 ( V_10 ) ;
V_27 = F_112 ( V_10 , V_66 , V_172 . V_177 ,
V_172 . V_176 , V_172 . V_183 , V_172 . V_178 ,
V_174 , V_172 . V_175 , V_173 ) ;
F_14 ( V_10 ) ;
F_40 ( V_10 , NULL , V_66 , F_113 ( V_27 , 0 ) , F_18 ( V_27 , 0 ) , V_104 ,
V_174 , F_113 ( V_27 , 0 ) ) ;
if ( ( V_27 > 0 ) && V_172 . V_175 ) {
if ( F_16 ( V_172 . V_70 , V_174 , V_27 ) ) {
V_16 = - V_37 ;
goto V_181;
}
}
} else {
if ( V_172 . V_175 ) {
if ( F_107 ( V_174 , V_172 . V_70 , V_172 . V_175 ) ) {
V_16 = - V_37 ;
goto V_181;
}
}
V_66 = F_114 ( V_10 , 0 ) ;
F_40 ( V_10 , NULL , V_66 , V_172 . V_175 , V_173 , V_78 ,
V_174 , V_172 . V_175 ) ;
F_19 ( V_10 ) ;
V_27 = F_112 ( V_10 , F_114 ( V_10 , 0 ) , V_172 . V_177 ,
V_172 . V_176 , V_172 . V_183 , V_172 . V_178 ,
V_174 , V_172 . V_175 , V_173 ) ;
F_14 ( V_10 ) ;
F_40 ( V_10 , NULL , V_66 , F_113 ( V_27 , 0 ) , F_18 ( V_27 , 0 ) , V_104 , NULL , 0 ) ;
}
if ( V_27 < 0 && V_27 != - V_185 ) {
F_115 ( V_79 , & V_10 -> V_10 , L_23
L_24 ,
V_127 -> V_128 , V_172 . V_176 , V_172 . V_177 ,
V_172 . V_175 , V_27 ) ;
}
V_16 = V_27 ;
V_181:
F_116 ( ( unsigned long ) V_174 ) ;
F_6 ( V_179 + sizeof( struct V_50 ) +
sizeof( struct V_180 ) ) ;
return V_16 ;
}
static int F_117 ( struct V_7 * V_8 , void T_3 * V_170 )
{
struct V_24 * V_10 = V_8 -> V_10 ;
struct V_186 V_187 ;
unsigned int V_173 , V_188 , V_66 ;
int V_189 ;
unsigned char * V_174 ;
int V_27 , V_16 ;
if ( F_107 ( & V_187 , V_170 , sizeof( V_187 ) ) )
return - V_37 ;
V_16 = F_85 ( V_8 -> V_10 , V_187 . V_74 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_83 ( V_8 , V_16 ) ;
if ( V_16 )
return V_16 ;
if ( V_187 . V_74 & V_107 )
V_66 = F_118 ( V_10 , V_187 . V_74 & 0x7f ) ;
else
V_66 = F_119 ( V_10 , V_187 . V_74 & 0x7f ) ;
if ( ! F_120 ( V_10 , V_66 , ! ( V_187 . V_74 & V_107 ) ) )
return - V_19 ;
V_188 = V_187 . V_25 ;
if ( V_188 >= V_4 )
return - V_19 ;
V_16 = F_1 ( V_188 + sizeof( struct V_50 ) ) ;
if ( V_16 )
return V_16 ;
if ( ! ( V_174 = F_93 ( V_188 , V_49 ) ) ) {
V_16 = - V_6 ;
goto V_181;
}
V_173 = V_187 . V_182 ;
if ( V_187 . V_74 & 0x80 ) {
if ( V_188 && ! F_110 ( V_184 , V_187 . V_70 , V_188 ) ) {
V_16 = - V_19 ;
goto V_181;
}
F_40 ( V_10 , NULL , V_66 , V_188 , V_173 , V_78 , NULL , 0 ) ;
F_19 ( V_10 ) ;
V_27 = F_121 ( V_10 , V_66 , V_174 , V_188 , & V_189 , V_173 ) ;
F_14 ( V_10 ) ;
F_40 ( V_10 , NULL , V_66 , V_189 , V_27 , V_104 , V_174 , V_189 ) ;
if ( ! V_27 && V_189 ) {
if ( F_16 ( V_187 . V_70 , V_174 , V_189 ) ) {
V_16 = - V_37 ;
goto V_181;
}
}
} else {
if ( V_188 ) {
if ( F_107 ( V_174 , V_187 . V_70 , V_188 ) ) {
V_16 = - V_37 ;
goto V_181;
}
}
F_40 ( V_10 , NULL , V_66 , V_188 , V_173 , V_78 , V_174 , V_188 ) ;
F_19 ( V_10 ) ;
V_27 = F_121 ( V_10 , V_66 , V_174 , V_188 , & V_189 , V_173 ) ;
F_14 ( V_10 ) ;
F_40 ( V_10 , NULL , V_66 , V_189 , V_27 , V_104 , NULL , 0 ) ;
}
V_16 = ( V_27 < 0 ? V_27 : V_189 ) ;
V_181:
F_23 ( V_174 ) ;
F_6 ( V_188 + sizeof( struct V_50 ) ) ;
return V_16 ;
}
static int F_122 ( struct V_7 * V_8 , void T_3 * V_170 )
{
unsigned int V_74 ;
int V_16 ;
if ( F_123 ( V_74 , ( unsigned int T_3 * ) V_170 ) )
return - V_37 ;
V_16 = F_85 ( V_8 -> V_10 , V_74 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_83 ( V_8 , V_16 ) ;
if ( V_16 )
return V_16 ;
F_124 ( V_8 -> V_10 , V_74 ) ;
return 0 ;
}
static int F_125 ( struct V_7 * V_8 , void T_3 * V_170 )
{
unsigned int V_74 ;
int V_66 ;
int V_16 ;
if ( F_123 ( V_74 , ( unsigned int T_3 * ) V_170 ) )
return - V_37 ;
V_16 = F_85 ( V_8 -> V_10 , V_74 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_83 ( V_8 , V_16 ) ;
if ( V_16 )
return V_16 ;
if ( V_74 & V_107 )
V_66 = F_118 ( V_8 -> V_10 , V_74 & 0x7f ) ;
else
V_66 = F_119 ( V_8 -> V_10 , V_74 & 0x7f ) ;
return F_126 ( V_8 -> V_10 , V_66 ) ;
}
static int F_127 ( struct V_7 * V_8 , void T_3 * V_170 )
{
struct V_190 V_191 ;
struct V_116 * V_117 ;
int V_16 ;
if ( F_107 ( & V_191 , V_170 , sizeof( V_191 ) ) )
return - V_37 ;
V_117 = F_77 ( V_8 -> V_10 , V_191 . V_138 ) ;
if ( ! V_117 || ! V_117 -> V_10 . V_192 )
V_16 = - V_193 ;
else {
F_128 ( V_191 . V_192 , V_117 -> V_10 . V_192 -> V_194 ,
sizeof( V_191 . V_192 ) ) ;
V_16 = ( F_16 ( V_170 , & V_191 , sizeof( V_191 ) ) ? - V_37 : 0 ) ;
}
return V_16 ;
}
static int F_129 ( struct V_7 * V_8 , void T_3 * V_170 )
{
struct V_195 V_196 = {
. V_197 = V_8 -> V_10 -> V_197 ,
. V_198 = V_8 -> V_10 -> V_199 == V_200
} ;
if ( F_16 ( V_170 , & V_196 , sizeof( V_196 ) ) )
return - V_37 ;
return 0 ;
}
static int F_130 ( struct V_7 * V_8 )
{
return F_131 ( V_8 -> V_10 ) ;
}
static int F_132 ( struct V_7 * V_8 , void T_3 * V_170 )
{
struct V_201 V_202 ;
int V_16 ;
if ( F_107 ( & V_202 , V_170 , sizeof( V_202 ) ) )
return - V_37 ;
if ( ( V_16 = F_83 ( V_8 , V_202 . V_138 ) ) )
return V_16 ;
return F_133 ( V_8 -> V_10 , V_202 . V_138 ,
V_202 . V_120 ) ;
}
static int F_134 ( struct V_7 * V_8 , void T_3 * V_170 )
{
int V_203 ;
int V_98 = 0 ;
struct V_204 * V_135 ;
if ( F_123 ( V_203 , ( int T_3 * ) V_170 ) )
return - V_37 ;
V_135 = V_8 -> V_10 -> V_135 ;
if ( V_135 ) {
int V_27 ;
for ( V_27 = 0 ; V_27 < V_135 -> V_45 . V_137 ; ++ V_27 ) {
if ( F_135 ( V_135 -> V_138 [ V_27 ] ) ) {
F_71 ( & V_8 -> V_10 -> V_10 ,
L_25
L_26 ,
V_135 -> V_138 [ V_27 ]
-> V_205
-> V_45 . V_121 ,
V_135 -> V_138 [ V_27 ]
-> V_10 . V_192 -> V_194 ,
V_127 -> V_128 , V_203 ) ;
V_98 = - V_206 ;
break;
}
}
}
if ( V_98 == 0 ) {
if ( V_135 && V_135 -> V_45 . V_207 == V_203 )
V_98 = F_136 ( V_8 -> V_10 ) ;
else
V_98 = F_137 ( V_8 -> V_10 , V_203 ) ;
}
return V_98 ;
}
static int F_138 ( struct V_7 * V_8 , struct V_208 * V_209 ,
struct V_210 T_3 * V_211 ,
void T_3 * V_170 )
{
struct V_210 * V_212 = NULL ;
struct V_213 * V_74 ;
struct V_46 * V_48 = NULL ;
struct V_180 * V_214 = NULL ;
unsigned int V_203 , V_215 , V_216 ;
int V_27 , V_16 , V_217 , V_53 = 0 , V_112 = - 1 ;
void * V_20 ;
if ( V_209 -> V_58 & ~ ( V_218 |
V_219 |
V_220 |
V_221 |
V_222 |
V_223 ) )
return - V_19 ;
if ( V_209 -> V_224 > 0 && ! V_209 -> V_225 )
return - V_19 ;
if ( ! ( V_209 -> type == V_226 &&
( V_209 -> V_141 & ~ V_227 ) == 0 ) ) {
V_112 = F_85 ( V_8 -> V_10 , V_209 -> V_141 ) ;
if ( V_112 < 0 )
return V_112 ;
V_16 = F_83 ( V_8 , V_112 ) ;
if ( V_16 )
return V_16 ;
}
if ( ( V_209 -> V_141 & V_227 ) != 0 ) {
V_217 = 1 ;
V_74 = V_8 -> V_10 -> V_228 [ V_209 -> V_141 & V_229 ] ;
} else {
V_217 = 0 ;
V_74 = V_8 -> V_10 -> V_230 [ V_209 -> V_141 & V_229 ] ;
}
if ( ! V_74 )
return - V_109 ;
V_203 = 0 ;
switch( V_209 -> type ) {
case V_226 :
if ( ! F_139 ( & V_74 -> V_45 ) )
return - V_19 ;
if ( V_209 -> V_224 < 8 )
return - V_19 ;
V_214 = F_93 ( sizeof( struct V_180 ) , V_49 ) ;
if ( ! V_214 )
return - V_6 ;
if ( F_107 ( V_214 , V_209 -> V_225 , 8 ) ) {
V_16 = - V_37 ;
goto error;
}
if ( V_209 -> V_224 < ( F_140 ( & V_214 -> V_175 ) + 8 ) ) {
V_16 = - V_19 ;
goto error;
}
V_16 = F_86 ( V_8 , V_214 -> V_176 , V_214 -> V_177 ,
F_140 ( & V_214 -> V_178 ) ) ;
if ( V_16 )
goto error;
V_209 -> V_84 = 0 ;
V_209 -> V_224 = F_140 ( & V_214 -> V_175 ) ;
V_209 -> V_225 += 8 ;
if ( ( V_214 -> V_176 & V_107 ) && V_209 -> V_224 ) {
V_217 = 1 ;
V_209 -> V_141 |= V_107 ;
} else {
V_217 = 0 ;
V_209 -> V_141 &= ~ V_107 ;
}
F_57 ( & V_8 -> V_10 -> V_10 , L_20
L_21
L_22 ,
V_214 -> V_176 , V_214 -> V_177 ,
F_109 ( & V_214 -> V_183 ) ,
F_109 ( & V_214 -> V_178 ) ,
F_109 ( & V_214 -> V_175 ) ) ;
V_203 = sizeof( struct V_180 ) ;
break;
case V_231 :
switch ( F_141 ( & V_74 -> V_45 ) ) {
case V_232 :
case V_233 :
return - V_19 ;
case V_234 :
V_209 -> type = V_235 ;
goto V_236;
}
V_209 -> V_84 = 0 ;
V_53 = F_142 ( V_209 -> V_224 , V_82 ) ;
if ( V_53 == 1 || V_53 > V_8 -> V_10 -> V_237 -> V_238 )
V_53 = 0 ;
break;
case V_235 :
if ( ! F_143 ( & V_74 -> V_45 ) )
return - V_19 ;
V_236:
V_209 -> V_84 = 0 ;
break;
case V_239 :
if ( V_209 -> V_84 < 1 ||
V_209 -> V_84 > 128 )
return - V_19 ;
if ( ! F_144 ( & V_74 -> V_45 ) )
return - V_19 ;
V_216 = sizeof( struct V_210 ) *
V_209 -> V_84 ;
if ( ! ( V_212 = F_93 ( V_216 , V_49 ) ) )
return - V_6 ;
if ( F_107 ( V_212 , V_211 , V_216 ) ) {
V_16 = - V_37 ;
goto error;
}
for ( V_215 = V_203 = 0 ; V_203 < V_209 -> V_84 ; V_203 ++ ) {
if ( V_212 [ V_203 ] . V_42 > 8192 ) {
V_16 = - V_19 ;
goto error;
}
V_215 += V_212 [ V_203 ] . V_42 ;
}
V_203 *= sizeof( struct V_240 ) ;
V_209 -> V_224 = V_215 ;
break;
default:
return - V_19 ;
}
if ( V_209 -> V_224 >= V_4 ) {
V_16 = - V_19 ;
goto error;
}
if ( V_209 -> V_224 > 0 &&
! F_110 ( V_217 ? V_184 : V_241 ,
V_209 -> V_225 , V_209 -> V_224 ) ) {
V_16 = - V_37 ;
goto error;
}
V_48 = F_20 ( V_209 -> V_84 ) ;
if ( ! V_48 ) {
V_16 = - V_6 ;
goto error;
}
V_203 += sizeof( struct V_46 ) + sizeof( struct V_50 ) + V_209 -> V_224 +
V_53 * sizeof( struct V_242 ) ;
V_16 = F_1 ( V_203 ) ;
if ( V_16 )
goto error;
V_48 -> V_57 = V_203 ;
if ( V_53 ) {
V_48 -> V_50 -> V_54 = F_93 ( V_53 * sizeof( struct V_242 ) ,
V_49 ) ;
if ( ! V_48 -> V_50 -> V_54 ) {
V_16 = - V_6 ;
goto error;
}
V_48 -> V_50 -> V_53 = V_53 ;
F_145 ( V_48 -> V_50 -> V_54 , V_48 -> V_50 -> V_53 ) ;
V_215 = V_209 -> V_224 ;
for ( V_27 = 0 ; V_27 < V_48 -> V_50 -> V_53 ; V_27 ++ ) {
V_203 = ( V_215 > V_82 ) ? V_82 : V_215 ;
V_20 = F_93 ( V_203 , V_49 ) ;
if ( ! V_20 ) {
V_16 = - V_6 ;
goto error;
}
F_146 ( & V_48 -> V_50 -> V_54 [ V_27 ] , V_20 , V_203 ) ;
if ( ! V_217 ) {
if ( F_107 ( V_20 , V_209 -> V_225 , V_203 ) ) {
V_16 = - V_37 ;
goto error;
}
V_209 -> V_225 += V_203 ;
}
V_215 -= V_203 ;
}
} else if ( V_209 -> V_224 > 0 ) {
V_48 -> V_50 -> V_55 = F_93 ( V_209 -> V_224 ,
V_49 ) ;
if ( ! V_48 -> V_50 -> V_55 ) {
V_16 = - V_6 ;
goto error;
}
if ( ! V_217 ) {
if ( F_107 ( V_48 -> V_50 -> V_55 ,
V_209 -> V_225 ,
V_209 -> V_224 ) ) {
V_16 = - V_37 ;
goto error;
}
} else if ( V_209 -> type == V_239 ) {
memset ( V_48 -> V_50 -> V_55 , 0 ,
V_209 -> V_224 ) ;
}
}
V_48 -> V_50 -> V_10 = V_8 -> V_10 ;
V_48 -> V_50 -> V_66 = ( V_209 -> type << 30 ) |
F_147 ( V_8 -> V_10 , V_209 -> V_141 & 0xf ) |
( V_209 -> V_141 & V_107 ) ;
V_203 = ( V_217 ? V_243 : V_244 ) ;
if ( V_209 -> V_58 & V_218 )
V_203 |= V_245 ;
if ( V_209 -> V_58 & V_219 )
V_203 |= V_246 ;
if ( V_209 -> V_58 & V_221 )
V_203 |= V_247 ;
if ( V_209 -> V_58 & V_222 )
V_203 |= V_248 ;
if ( V_209 -> V_58 & V_223 )
V_203 |= V_249 ;
V_48 -> V_50 -> V_105 = V_203 ;
V_48 -> V_50 -> V_85 = V_209 -> V_224 ;
V_48 -> V_50 -> V_56 = ( unsigned char * ) V_214 ;
V_214 = NULL ;
V_48 -> V_50 -> V_250 = V_209 -> V_250 ;
V_48 -> V_50 -> V_84 = V_209 -> V_84 ;
if ( V_209 -> type == V_239 ||
V_8 -> V_10 -> V_199 == V_251 )
V_48 -> V_50 -> V_252 = 1 << F_18 ( 15 , V_74 -> V_45 . V_253 - 1 ) ;
else
V_48 -> V_50 -> V_252 = V_74 -> V_45 . V_253 ;
V_48 -> V_50 -> V_93 = V_48 ;
V_48 -> V_50 -> V_254 = V_62 ;
for ( V_215 = V_203 = 0 ; V_203 < V_209 -> V_84 ; V_203 ++ ) {
V_48 -> V_50 -> V_211 [ V_203 ] . V_14 = V_215 ;
V_48 -> V_50 -> V_211 [ V_203 ] . V_42 = V_212 [ V_203 ] . V_42 ;
V_215 += V_212 [ V_203 ] . V_42 ;
}
F_23 ( V_212 ) ;
V_212 = NULL ;
V_48 -> V_8 = V_8 ;
V_48 -> V_64 = V_170 ;
if ( V_217 && V_209 -> V_224 > 0 )
V_48 -> V_83 = V_209 -> V_225 ;
else
V_48 -> V_83 = NULL ;
V_48 -> V_97 = V_209 -> V_97 ;
V_48 -> V_112 = V_112 ;
V_48 -> V_51 = F_55 ( F_98 ( V_127 ) ) ;
V_48 -> V_52 = F_99 () ;
F_100 ( V_127 , & V_48 -> V_96 ) ;
F_40 ( V_8 -> V_10 , V_48 -> V_64 , V_48 -> V_50 -> V_66 ,
V_48 -> V_50 -> V_85 , 0 , V_78 ,
NULL , 0 ) ;
if ( ! V_217 )
F_46 ( V_48 -> V_50 , V_48 -> V_50 -> V_85 ) ;
F_30 ( V_48 ) ;
if ( F_148 ( & V_74 -> V_45 ) ) {
F_149 ( & V_8 -> V_59 ) ;
V_48 -> V_87 = F_150 ( & V_74 -> V_45 ) |
( ( V_74 -> V_45 . V_142 & V_227 )
>> 3 ) ;
if ( V_209 -> V_58 & V_220 )
V_48 -> V_88 = V_89 ;
else
V_8 -> V_92 &= ~ ( 1 << V_48 -> V_87 ) ;
if ( V_8 -> V_92 & ( 1 << V_48 -> V_87 ) )
V_16 = - V_255 ;
else
V_16 = F_151 ( V_48 -> V_50 , V_256 ) ;
F_152 ( & V_8 -> V_59 ) ;
} else {
V_16 = F_151 ( V_48 -> V_50 , V_49 ) ;
}
if ( V_16 ) {
F_115 ( V_79 , & V_8 -> V_10 -> V_10 ,
L_27 , V_16 ) ;
F_40 ( V_8 -> V_10 , V_48 -> V_64 , V_48 -> V_50 -> V_66 ,
0 , V_16 , V_104 , NULL , 0 ) ;
F_34 ( V_48 ) ;
goto error;
}
return 0 ;
error:
F_23 ( V_212 ) ;
F_23 ( V_214 ) ;
if ( V_48 )
F_24 ( V_48 ) ;
return V_16 ;
}
static int F_153 ( struct V_7 * V_8 , void T_3 * V_170 )
{
struct V_208 V_209 ;
if ( F_107 ( & V_209 , V_170 , sizeof( V_209 ) ) )
return - V_37 ;
return F_138 ( V_8 , & V_209 ,
( ( (struct V_208 T_3 * ) V_170 ) -> V_211 ) ,
V_170 ) ;
}
static int F_154 ( struct V_7 * V_8 , void T_3 * V_170 )
{
struct V_50 * V_50 ;
struct V_46 * V_48 ;
unsigned long V_58 ;
F_31 ( & V_8 -> V_59 , V_58 ) ;
V_48 = F_38 ( V_8 , V_170 ) ;
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
static int F_155 ( struct V_46 * V_48 , void T_3 * T_3 * V_170 )
{
struct V_50 * V_50 = V_48 -> V_50 ;
struct V_208 T_3 * V_64 = V_48 -> V_64 ;
void T_3 * V_257 = V_48 -> V_64 ;
unsigned int V_27 ;
if ( V_48 -> V_83 && V_50 -> V_86 ) {
if ( F_47 ( V_48 -> V_83 , V_50 ) )
goto V_258;
}
if ( F_156 ( V_48 -> V_98 , & V_64 -> V_98 ) )
goto V_258;
if ( F_156 ( V_50 -> V_86 , & V_64 -> V_86 ) )
goto V_258;
if ( F_156 ( V_50 -> V_259 , & V_64 -> V_259 ) )
goto V_258;
if ( F_144 ( & V_50 -> V_74 -> V_45 ) ) {
for ( V_27 = 0 ; V_27 < V_50 -> V_84 ; V_27 ++ ) {
if ( F_156 ( V_50 -> V_211 [ V_27 ] . V_86 ,
& V_64 -> V_211 [ V_27 ] . V_86 ) )
goto V_258;
if ( F_156 ( V_50 -> V_211 [ V_27 ] . V_98 ,
& V_64 -> V_211 [ V_27 ] . V_98 ) )
goto V_258;
}
}
if ( F_156 ( V_257 , ( void T_3 * T_3 * ) V_170 ) )
return - V_37 ;
return 0 ;
V_258:
return - V_37 ;
}
static struct V_46 * F_157 ( struct V_7 * V_8 )
{
F_158 ( V_110 , V_127 ) ;
struct V_46 * V_48 = NULL ;
struct V_24 * V_10 = V_8 -> V_10 ;
F_159 ( & V_8 -> V_110 , & V_110 ) ;
for (; ; ) {
F_160 ( V_260 ) ;
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
F_164 ( V_261 ) ;
return V_48 ;
}
static int F_165 ( struct V_7 * V_8 , void T_3 * V_170 )
{
struct V_46 * V_48 = F_157 ( V_8 ) ;
if ( V_48 ) {
int V_262 = F_155 ( V_48 , ( void T_3 * T_3 * ) V_170 ) ;
F_24 ( V_48 ) ;
return V_262 ;
}
if ( F_161 ( V_127 ) )
return - V_263 ;
return - V_264 ;
}
static int F_166 ( struct V_7 * V_8 , void T_3 * V_170 )
{
int V_262 ;
struct V_46 * V_48 ;
V_48 = F_36 ( V_8 ) ;
V_262 = - V_265 ;
if ( V_48 ) {
V_262 = F_155 ( V_48 , ( void T_3 * T_3 * ) V_170 ) ;
F_24 ( V_48 ) ;
}
return V_262 ;
}
static int F_167 ( struct V_7 * V_8 ,
struct V_266 T_3 * V_267 )
{
struct V_171 T_3 * V_113 ;
T_8 V_268 ;
V_113 = F_168 ( sizeof( * V_113 ) ) ;
if ( F_169 ( V_113 , V_267 , ( sizeof( * V_267 ) - sizeof( V_269 ) ) ) ||
F_123 ( V_268 , & V_267 -> V_70 ) ||
F_156 ( F_170 ( V_268 ) , & V_113 -> V_70 ) )
return - V_37 ;
return F_106 ( V_8 , V_113 ) ;
}
static int F_171 ( struct V_7 * V_8 ,
struct V_270 T_3 * V_267 )
{
struct V_186 T_3 * V_113 ;
T_9 V_271 ;
V_269 V_257 ;
V_113 = F_168 ( sizeof( * V_113 ) ) ;
if ( F_123 ( V_271 , & V_267 -> V_74 ) || F_156 ( V_271 , & V_113 -> V_74 ) ||
F_123 ( V_271 , & V_267 -> V_25 ) || F_156 ( V_271 , & V_113 -> V_25 ) ||
F_123 ( V_271 , & V_267 -> V_182 ) || F_156 ( V_271 , & V_113 -> V_182 ) ||
F_123 ( V_257 , & V_267 -> V_70 ) || F_156 ( F_170 ( V_257 ) , & V_113 -> V_70 ) )
return - V_37 ;
return F_117 ( V_8 , V_113 ) ;
}
static int F_172 ( struct V_7 * V_8 , void T_3 * V_170 )
{
struct V_272 V_273 ;
if ( F_107 ( & V_273 , V_170 , sizeof( V_273 ) ) )
return - V_37 ;
V_8 -> V_166 = V_273 . V_97 ;
V_8 -> V_168 = F_170 ( V_273 . V_93 ) ;
return 0 ;
}
static int F_173 ( struct V_208 * V_274 ,
struct V_275 T_3 * V_209 )
{
T_8 V_276 ;
if ( ! F_110 ( V_241 , V_209 , sizeof( * V_209 ) ) ||
F_174 ( V_274 -> type , & V_209 -> type ) ||
F_174 ( V_274 -> V_141 , & V_209 -> V_141 ) ||
F_174 ( V_274 -> V_98 , & V_209 -> V_98 ) ||
F_174 ( V_274 -> V_58 , & V_209 -> V_58 ) ||
F_174 ( V_274 -> V_224 , & V_209 -> V_224 ) ||
F_174 ( V_274 -> V_86 , & V_209 -> V_86 ) ||
F_174 ( V_274 -> V_250 , & V_209 -> V_250 ) ||
F_174 ( V_274 -> V_84 , & V_209 -> V_84 ) ||
F_174 ( V_274 -> V_259 , & V_209 -> V_259 ) ||
F_174 ( V_274 -> V_97 , & V_209 -> V_97 ) )
return - V_37 ;
if ( F_174 ( V_276 , & V_209 -> V_225 ) )
return - V_37 ;
V_274 -> V_225 = F_170 ( V_276 ) ;
if ( F_174 ( V_276 , & V_209 -> V_277 ) )
return - V_37 ;
V_274 -> V_277 = F_170 ( V_276 ) ;
return 0 ;
}
static int F_175 ( struct V_7 * V_8 , void T_3 * V_170 )
{
struct V_208 V_209 ;
if ( F_173 ( & V_209 , (struct V_275 T_3 * ) V_170 ) )
return - V_37 ;
return F_138 ( V_8 , & V_209 ,
( (struct V_275 T_3 * ) V_170 ) -> V_211 ,
V_170 ) ;
}
static int F_176 ( struct V_46 * V_48 , void T_3 * T_3 * V_170 )
{
struct V_50 * V_50 = V_48 -> V_50 ;
struct V_275 T_3 * V_64 = V_48 -> V_64 ;
void T_3 * V_257 = V_48 -> V_64 ;
unsigned int V_27 ;
if ( V_48 -> V_83 && V_50 -> V_86 ) {
if ( F_47 ( V_48 -> V_83 , V_50 ) )
return - V_37 ;
}
if ( F_156 ( V_48 -> V_98 , & V_64 -> V_98 ) )
return - V_37 ;
if ( F_156 ( V_50 -> V_86 , & V_64 -> V_86 ) )
return - V_37 ;
if ( F_156 ( V_50 -> V_259 , & V_64 -> V_259 ) )
return - V_37 ;
if ( F_144 ( & V_50 -> V_74 -> V_45 ) ) {
for ( V_27 = 0 ; V_27 < V_50 -> V_84 ; V_27 ++ ) {
if ( F_156 ( V_50 -> V_211 [ V_27 ] . V_86 ,
& V_64 -> V_211 [ V_27 ] . V_86 ) )
return - V_37 ;
if ( F_156 ( V_50 -> V_211 [ V_27 ] . V_98 ,
& V_64 -> V_211 [ V_27 ] . V_98 ) )
return - V_37 ;
}
}
if ( F_156 ( F_177 ( V_257 ) , ( T_6 T_3 * ) V_170 ) )
return - V_37 ;
return 0 ;
}
static int F_178 ( struct V_7 * V_8 , void T_3 * V_170 )
{
struct V_46 * V_48 = F_157 ( V_8 ) ;
if ( V_48 ) {
int V_262 = F_176 ( V_48 , ( void T_3 * T_3 * ) V_170 ) ;
F_24 ( V_48 ) ;
return V_262 ;
}
if ( F_161 ( V_127 ) )
return - V_263 ;
return - V_264 ;
}
static int F_179 ( struct V_7 * V_8 , void T_3 * V_170 )
{
int V_262 ;
struct V_46 * V_48 ;
V_262 = - V_265 ;
V_48 = F_36 ( V_8 ) ;
if ( V_48 ) {
V_262 = F_176 ( V_48 , ( void T_3 * T_3 * ) V_170 ) ;
F_24 ( V_48 ) ;
}
return V_262 ;
}
static int F_180 ( struct V_7 * V_8 , void T_3 * V_170 )
{
struct V_278 V_273 ;
if ( F_107 ( & V_273 , V_170 , sizeof( V_273 ) ) )
return - V_37 ;
V_8 -> V_166 = V_273 . V_97 ;
V_8 -> V_168 = V_273 . V_93 ;
return 0 ;
}
static int F_181 ( struct V_7 * V_8 , void T_3 * V_170 )
{
unsigned int V_112 ;
if ( F_123 ( V_112 , ( unsigned int T_3 * ) V_170 ) )
return - V_37 ;
return F_75 ( V_8 , V_112 ) ;
}
static int F_182 ( struct V_7 * V_8 , void T_3 * V_170 )
{
unsigned int V_112 ;
int V_16 ;
if ( F_123 ( V_112 , ( unsigned int T_3 * ) V_170 ) )
return - V_37 ;
if ( ( V_16 = F_80 ( V_8 , V_112 ) ) < 0 )
return V_16 ;
F_62 ( V_8 , V_112 ) ;
return 0 ;
}
static int F_183 ( struct V_7 * V_8 , struct V_279 * V_280 )
{
int V_81 ;
void * V_20 = NULL ;
int V_262 = 0 ;
struct V_116 * V_117 = NULL ;
struct V_281 * V_192 = NULL ;
if ( ( V_81 = F_184 ( V_280 -> V_282 ) ) > 0 ) {
if ( ( V_20 = F_93 ( V_81 , V_49 ) ) == NULL )
return - V_6 ;
if ( ( F_185 ( V_280 -> V_282 ) & V_283 ) ) {
if ( F_107 ( V_20 , V_280 -> V_70 , V_81 ) ) {
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
V_262 = - V_126 ;
else if ( ! ( V_117 = F_77 ( V_8 -> V_10 , V_280 -> V_284 ) ) )
V_262 = - V_19 ;
else switch ( V_280 -> V_282 ) {
case V_285 :
if ( V_117 -> V_10 . V_192 ) {
V_192 = F_186 ( V_117 -> V_10 . V_192 ) ;
F_187 ( & V_117 -> V_10 , L_28 ) ;
F_82 ( V_192 , V_117 ) ;
} else
V_262 = - V_193 ;
break;
case V_286 :
if ( ! V_117 -> V_10 . V_192 )
V_262 = F_188 ( & V_117 -> V_10 ) ;
else
V_262 = - V_206 ;
break;
default:
if ( V_117 -> V_10 . V_192 )
V_192 = F_186 ( V_117 -> V_10 . V_192 ) ;
if ( V_192 == NULL || V_192 -> V_287 == NULL ) {
V_262 = - V_288 ;
} else {
V_262 = V_192 -> V_287 ( V_117 , V_280 -> V_282 , V_20 ) ;
if ( V_262 == - V_289 )
V_262 = - V_288 ;
}
}
if ( V_262 >= 0
&& ( F_185 ( V_280 -> V_282 ) & V_290 ) != 0
&& V_81 > 0
&& F_16 ( V_280 -> V_70 , V_20 , V_81 ) != 0 )
V_262 = - V_37 ;
F_23 ( V_20 ) ;
return V_262 ;
}
static int F_189 ( struct V_7 * V_8 , void T_3 * V_170 )
{
struct V_279 V_172 ;
if ( F_107 ( & V_172 , V_170 , sizeof( V_172 ) ) )
return - V_37 ;
return F_183 ( V_8 , & V_172 ) ;
}
static int F_190 ( struct V_7 * V_8 , T_10 V_170 )
{
struct V_291 T_3 * V_292 ;
struct V_279 V_172 ;
T_6 V_268 ;
V_292 = F_170 ( ( long ) V_170 ) ;
if ( ! F_110 ( V_241 , V_292 , sizeof( * V_292 ) ) ||
F_174 ( V_172 . V_284 , & V_292 -> V_284 ) ||
F_174 ( V_172 . V_282 , & V_292 -> V_282 ) ||
F_174 ( V_268 , & V_292 -> V_70 ) )
return - V_37 ;
V_172 . V_70 = F_170 ( V_268 ) ;
return F_183 ( V_8 , & V_172 ) ;
}
static int F_191 ( struct V_7 * V_8 , void T_3 * V_170 )
{
unsigned V_293 ;
int V_294 ;
if ( F_123 ( V_293 , ( unsigned T_3 * ) V_170 ) )
return - V_37 ;
V_294 = F_192 ( V_8 -> V_10 , V_293 , V_8 ) ;
if ( V_294 == 0 )
F_57 ( & V_8 -> V_10 -> V_10 , L_29 ,
V_293 , F_84 ( V_127 ) , V_127 -> V_128 ) ;
return V_294 ;
}
static int F_193 ( struct V_7 * V_8 , void T_3 * V_170 )
{
unsigned V_293 ;
if ( F_123 ( V_293 , ( unsigned T_3 * ) V_170 ) )
return - V_37 ;
return F_194 ( V_8 -> V_10 , V_293 , V_8 ) ;
}
static int F_195 ( struct V_7 * V_8 , void T_3 * V_170 )
{
T_8 V_295 ;
V_295 = V_296 | V_297 ;
if ( ! V_8 -> V_10 -> V_237 -> V_298 )
V_295 |= V_299 ;
if ( V_8 -> V_10 -> V_237 -> V_238 )
V_295 |= V_300 ;
if ( F_156 ( V_295 , ( T_8 T_3 * ) V_170 ) )
return - V_37 ;
return 0 ;
}
static int F_196 ( struct V_7 * V_8 , void T_3 * V_170 )
{
struct V_301 V_302 ;
struct V_116 * V_117 ;
if ( F_107 ( & V_302 , V_170 , sizeof( V_302 ) ) )
return - V_37 ;
V_117 = F_77 ( V_8 -> V_10 , V_302 . V_138 ) ;
if ( ! V_117 )
return - V_19 ;
if ( V_117 -> V_10 . V_192 ) {
struct V_281 * V_192 = F_186 ( V_117 -> V_10 . V_192 ) ;
if ( ( V_302 . V_58 & V_303 ) &&
strncmp ( V_302 . V_192 , V_117 -> V_10 . V_192 -> V_194 ,
sizeof( V_302 . V_192 ) ) != 0 )
return - V_206 ;
if ( ( V_302 . V_58 & V_304 ) &&
strncmp ( V_302 . V_192 , V_117 -> V_10 . V_192 -> V_194 ,
sizeof( V_302 . V_192 ) ) == 0 )
return - V_206 ;
F_187 ( & V_117 -> V_10 , L_28 ) ;
F_82 ( V_192 , V_117 ) ;
}
return F_75 ( V_8 , V_302 . V_138 ) ;
}
static long F_197 ( struct V_13 * V_13 , unsigned int V_305 ,
void T_3 * V_113 )
{
struct V_7 * V_8 = V_13 -> V_23 ;
struct V_160 * V_160 = F_11 ( V_13 ) ;
struct V_24 * V_10 = V_8 -> V_10 ;
int V_16 = - V_288 ;
if ( ! ( V_13 -> V_306 & V_307 ) )
return - V_308 ;
F_14 ( V_10 ) ;
if ( ! F_7 ( V_8 ) ) {
F_19 ( V_10 ) ;
return - V_28 ;
}
switch ( V_305 ) {
case V_309 :
F_57 ( & V_10 -> V_10 , L_30 , V_310 ) ;
V_16 = F_106 ( V_8 , V_113 ) ;
if ( V_16 >= 0 )
V_160 -> V_311 = V_312 ;
break;
case V_313 :
F_57 ( & V_10 -> V_10 , L_31 , V_310 ) ;
V_16 = F_117 ( V_8 , V_113 ) ;
if ( V_16 >= 0 )
V_160 -> V_311 = V_312 ;
break;
case V_314 :
F_57 ( & V_10 -> V_10 , L_32 , V_310 ) ;
V_16 = F_122 ( V_8 , V_113 ) ;
if ( V_16 >= 0 )
V_160 -> V_311 = V_312 ;
break;
case V_315 :
F_57 ( & V_10 -> V_10 , L_33 , V_310 ) ;
V_16 = F_130 ( V_8 ) ;
break;
case V_316 :
F_57 ( & V_10 -> V_10 , L_34 , V_310 ) ;
V_16 = F_125 ( V_8 , V_113 ) ;
if ( V_16 >= 0 )
V_160 -> V_311 = V_312 ;
break;
case V_317 :
F_57 ( & V_10 -> V_10 , L_35 , V_310 ) ;
V_16 = F_127 ( V_8 , V_113 ) ;
break;
case V_318 :
F_57 ( & V_10 -> V_10 , L_36 , V_310 ) ;
V_16 = F_129 ( V_8 , V_113 ) ;
break;
case V_319 :
F_57 ( & V_10 -> V_10 , L_37 , V_310 ) ;
V_16 = F_132 ( V_8 , V_113 ) ;
break;
case V_320 :
F_57 ( & V_10 -> V_10 , L_38 , V_310 ) ;
V_16 = F_134 ( V_8 , V_113 ) ;
break;
case V_321 :
F_57 ( & V_10 -> V_10 , L_39 , V_310 ) ;
V_16 = F_153 ( V_8 , V_113 ) ;
if ( V_16 >= 0 )
V_160 -> V_311 = V_312 ;
break;
#ifdef F_198
case V_322 :
F_57 ( & V_10 -> V_10 , L_40 , V_310 ) ;
V_16 = F_167 ( V_8 , V_113 ) ;
if ( V_16 >= 0 )
V_160 -> V_311 = V_312 ;
break;
case V_323 :
F_57 ( & V_10 -> V_10 , L_41 , V_310 ) ;
V_16 = F_171 ( V_8 , V_113 ) ;
if ( V_16 >= 0 )
V_160 -> V_311 = V_312 ;
break;
case V_324 :
F_57 ( & V_10 -> V_10 , L_42 , V_310 ) ;
V_16 = F_172 ( V_8 , V_113 ) ;
break;
case V_325 :
F_57 ( & V_10 -> V_10 , L_43 , V_310 ) ;
V_16 = F_175 ( V_8 , V_113 ) ;
if ( V_16 >= 0 )
V_160 -> V_311 = V_312 ;
break;
case V_326 :
F_57 ( & V_10 -> V_10 , L_44 , V_310 ) ;
V_16 = F_178 ( V_8 , V_113 ) ;
break;
case V_327 :
F_57 ( & V_10 -> V_10 , L_45 , V_310 ) ;
V_16 = F_179 ( V_8 , V_113 ) ;
break;
case V_328 :
F_57 ( & V_10 -> V_10 , L_46 , V_310 ) ;
V_16 = F_190 ( V_8 , F_177 ( V_113 ) ) ;
break;
#endif
case V_329 :
F_57 ( & V_10 -> V_10 , L_47 , V_310 ) ;
V_16 = F_154 ( V_8 , V_113 ) ;
break;
case V_330 :
F_57 ( & V_10 -> V_10 , L_48 , V_310 ) ;
V_16 = F_165 ( V_8 , V_113 ) ;
break;
case V_331 :
F_57 ( & V_10 -> V_10 , L_49 , V_310 ) ;
V_16 = F_166 ( V_8 , V_113 ) ;
break;
case V_332 :
F_57 ( & V_10 -> V_10 , L_50 , V_310 ) ;
V_16 = F_180 ( V_8 , V_113 ) ;
break;
case V_333 :
F_57 ( & V_10 -> V_10 , L_51 , V_310 ) ;
V_16 = F_181 ( V_8 , V_113 ) ;
break;
case V_334 :
F_57 ( & V_10 -> V_10 , L_52 , V_310 ) ;
V_16 = F_182 ( V_8 , V_113 ) ;
break;
case V_335 :
F_57 ( & V_10 -> V_10 , L_53 , V_310 ) ;
V_16 = F_189 ( V_8 , V_113 ) ;
break;
case V_336 :
F_57 ( & V_10 -> V_10 , L_54 , V_310 ) ;
V_16 = F_191 ( V_8 , V_113 ) ;
break;
case V_337 :
F_57 ( & V_10 -> V_10 , L_55 , V_310 ) ;
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
V_160 -> V_340 = V_312 ;
return V_16 ;
}
static long F_199 ( struct V_13 * V_13 , unsigned int V_305 ,
unsigned long V_170 )
{
int V_16 ;
V_16 = F_197 ( V_13 , V_305 , ( void T_3 * ) V_170 ) ;
return V_16 ;
}
static long F_200 ( struct V_13 * V_13 , unsigned int V_305 ,
unsigned long V_170 )
{
int V_16 ;
V_16 = F_197 ( V_13 , V_305 , F_170 ( V_170 ) ) ;
return V_16 ;
}
static unsigned int F_201 ( struct V_13 * V_13 ,
struct V_341 * V_110 )
{
struct V_7 * V_8 = V_13 -> V_23 ;
unsigned int V_342 = 0 ;
F_202 ( V_13 , & V_8 -> V_110 , V_110 ) ;
if ( V_13 -> V_306 & V_307 && ! F_8 ( & V_8 -> V_62 ) )
V_342 |= V_343 | V_344 ;
if ( ! F_7 ( V_8 ) )
V_342 |= V_345 | V_346 ;
return V_342 ;
}
static void F_203 ( struct V_24 * V_65 )
{
struct V_7 * V_8 ;
struct V_94 V_95 ;
while ( ! F_8 ( & V_65 -> V_169 ) ) {
V_8 = F_37 ( V_65 -> V_169 . V_63 , struct V_7 , V_9 ) ;
F_65 ( V_8 ) ;
F_204 ( & V_8 -> V_110 ) ;
F_35 ( & V_8 -> V_9 ) ;
if ( V_8 -> V_166 ) {
V_95 . V_99 = V_8 -> V_166 ;
V_95 . V_100 = V_185 ;
V_95 . V_101 = V_102 ;
V_95 . V_103 = V_8 -> V_168 ;
F_58 ( V_8 -> V_166 , & V_95 ,
V_8 -> V_167 , V_8 -> V_52 , V_8 -> V_96 ) ;
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
int V_262 ;
V_262 = F_207 ( V_353 , V_354 ,
L_56 ) ;
if ( V_262 ) {
F_208 ( V_355 L_57 ) ;
goto V_356;
}
F_209 ( & V_357 , & V_358 ) ;
V_262 = F_210 ( & V_357 , V_353 , V_354 ) ;
if ( V_262 ) {
F_208 ( V_355 L_58 ,
V_163 ) ;
goto V_359;
}
F_211 ( & V_360 ) ;
V_356:
return V_262 ;
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
