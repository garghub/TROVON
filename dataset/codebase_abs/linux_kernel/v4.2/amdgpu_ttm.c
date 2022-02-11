static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_1 * V_6 ;
V_5 = F_2 ( V_3 , struct V_4 , V_3 ) ;
V_6 = F_2 ( V_5 , struct V_1 , V_5 ) ;
return V_6 ;
}
static int F_3 ( struct V_7 * V_8 )
{
return F_4 ( V_8 -> V_9 ) ;
}
static void F_5 ( struct V_7 * V_8 )
{
F_6 ( V_8 -> V_9 ) ;
}
static int F_7 ( struct V_1 * V_6 )
{
struct V_7 * V_10 ;
int V_11 ;
V_6 -> V_5 . V_12 = false ;
V_10 = & V_6 -> V_5 . V_13 ;
V_10 -> V_14 = V_15 ;
V_10 -> V_16 = sizeof( struct V_17 ) ;
V_10 -> V_18 = & F_3 ;
V_10 -> V_19 = & F_5 ;
V_11 = F_8 ( V_10 ) ;
if ( V_11 != 0 ) {
F_9 ( L_1
L_2 ) ;
return V_11 ;
}
V_6 -> V_5 . V_20 . V_21 =
V_6 -> V_5 . V_13 . V_9 ;
V_10 = & V_6 -> V_5 . V_20 . V_8 ;
V_10 -> V_14 = V_22 ;
V_10 -> V_16 = sizeof( struct V_23 ) ;
V_10 -> V_18 = & V_24 ;
V_10 -> V_19 = & V_25 ;
V_11 = F_8 ( V_10 ) ;
if ( V_11 != 0 ) {
F_9 ( L_3 ) ;
F_10 ( & V_6 -> V_5 . V_13 ) ;
return V_11 ;
}
V_6 -> V_5 . V_12 = true ;
return 0 ;
}
static void F_11 ( struct V_1 * V_6 )
{
if ( V_6 -> V_5 . V_12 ) {
F_10 ( & V_6 -> V_5 . V_20 . V_8 ) ;
F_10 ( & V_6 -> V_5 . V_13 ) ;
V_6 -> V_5 . V_12 = false ;
}
}
static int F_12 ( struct V_2 * V_3 , T_1 V_26 )
{
return 0 ;
}
static int F_13 ( struct V_2 * V_3 , T_1 type ,
struct V_27 * V_28 )
{
struct V_1 * V_6 ;
V_6 = F_1 ( V_3 ) ;
switch ( type ) {
case V_29 :
V_28 -> V_26 = V_30 ;
V_28 -> V_31 = V_32 ;
V_28 -> V_33 = V_34 ;
break;
case V_35 :
V_28 -> V_36 = & V_37 ;
V_28 -> V_38 = V_6 -> V_39 . V_40 ;
V_28 -> V_31 = V_32 ;
V_28 -> V_33 = V_34 ;
V_28 -> V_26 = V_30 | V_41 ;
break;
case V_42 :
V_28 -> V_36 = & V_37 ;
V_28 -> V_38 = V_6 -> V_39 . V_43 ;
V_28 -> V_26 = V_44 |
V_30 ;
V_28 -> V_31 = V_45 | V_46 ;
V_28 -> V_33 = V_46 ;
break;
case V_47 :
case V_48 :
case V_49 :
V_28 -> V_36 = & V_37 ;
V_28 -> V_38 = 0 ;
V_28 -> V_26 = V_44 | V_41 ;
V_28 -> V_31 = V_45 ;
V_28 -> V_33 = V_45 ;
break;
default:
F_9 ( L_4 , ( unsigned ) type ) ;
return - V_50 ;
}
return 0 ;
}
static void F_14 ( struct V_51 * V_52 ,
struct V_53 * V_54 )
{
struct V_55 * V_56 ;
static struct V_57 V_58 = {
. V_59 = 0 ,
. V_60 = 0 ,
. V_26 = V_32 | V_61
} ;
if ( ! F_15 ( V_52 ) ) {
V_54 -> V_54 = & V_58 ;
V_54 -> V_62 = & V_58 ;
V_54 -> V_63 = 1 ;
V_54 -> V_64 = 1 ;
return;
}
V_56 = F_2 ( V_52 , struct V_55 , V_65 ) ;
switch ( V_52 -> V_66 . V_67 ) {
case V_42 :
if ( V_56 -> V_6 -> V_5 . V_68 -> V_69 == false )
F_16 ( V_56 , V_70 ) ;
else
F_16 ( V_56 , V_71 ) ;
break;
case V_35 :
default:
F_16 ( V_56 , V_70 ) ;
}
* V_54 = V_56 -> V_54 ;
}
static int F_17 ( struct V_51 * V_52 , struct V_72 * V_73 )
{
struct V_55 * V_56 = F_2 ( V_52 , struct V_55 , V_65 ) ;
return F_18 ( & V_56 -> V_74 . V_75 , V_73 ) ;
}
static void F_19 ( struct V_51 * V_52 ,
struct V_76 * V_77 )
{
struct V_76 * V_78 = & V_52 -> V_66 ;
F_20 ( V_78 -> V_79 != NULL ) ;
* V_78 = * V_77 ;
V_77 -> V_79 = NULL ;
}
static int F_21 ( struct V_51 * V_52 ,
bool V_80 , bool V_81 ,
struct V_76 * V_77 ,
struct V_76 * V_78 )
{
struct V_1 * V_6 ;
struct V_82 * V_83 ;
T_2 V_84 , V_85 ;
struct V_86 * V_87 ;
int V_11 ;
V_6 = F_1 ( V_52 -> V_3 ) ;
V_83 = V_6 -> V_5 . V_68 ;
V_84 = V_78 -> V_88 << V_89 ;
V_85 = V_77 -> V_88 << V_89 ;
switch ( V_78 -> V_67 ) {
case V_42 :
V_84 += V_6 -> V_39 . V_43 ;
break;
case V_35 :
V_84 += V_6 -> V_39 . V_40 ;
break;
default:
F_9 ( L_5 , V_78 -> V_67 ) ;
return - V_50 ;
}
switch ( V_77 -> V_67 ) {
case V_42 :
V_85 += V_6 -> V_39 . V_43 ;
break;
case V_35 :
V_85 += V_6 -> V_39 . V_40 ;
break;
default:
F_9 ( L_5 , V_78 -> V_67 ) ;
return - V_50 ;
}
if ( ! V_83 -> V_69 ) {
F_9 ( L_6 ) ;
return - V_50 ;
}
F_22 ( ( V_90 % V_91 ) != 0 ) ;
V_11 = F_23 ( V_83 , V_84 , V_85 ,
V_77 -> V_92 * V_90 ,
V_52 -> V_93 , & V_87 ) ;
V_11 = F_24 ( V_52 , & V_87 -> V_94 ,
V_80 , V_81 , V_77 ) ;
F_25 ( & V_87 ) ;
return V_11 ;
}
static int F_26 ( struct V_51 * V_52 ,
bool V_80 , bool V_95 ,
bool V_81 ,
struct V_76 * V_77 )
{
struct V_1 * V_6 ;
struct V_76 * V_78 = & V_52 -> V_66 ;
struct V_76 V_96 ;
struct V_57 V_58 ;
struct V_53 V_54 ;
int V_11 ;
V_6 = F_1 ( V_52 -> V_3 ) ;
V_96 = * V_77 ;
V_96 . V_79 = NULL ;
V_54 . V_63 = 1 ;
V_54 . V_54 = & V_58 ;
V_54 . V_64 = 1 ;
V_54 . V_62 = & V_58 ;
V_58 . V_59 = 0 ;
V_58 . V_60 = 0 ;
V_58 . V_26 = V_32 | V_97 ;
V_11 = F_27 ( V_52 , & V_54 , & V_96 ,
V_95 , V_81 ) ;
if ( F_28 ( V_11 ) ) {
return V_11 ;
}
V_11 = F_29 ( V_52 -> V_98 , V_96 . V_54 ) ;
if ( F_28 ( V_11 ) ) {
goto V_99;
}
V_11 = F_30 ( V_52 -> V_98 , & V_96 ) ;
if ( F_28 ( V_11 ) ) {
goto V_99;
}
V_11 = F_21 ( V_52 , true , V_81 , & V_96 , V_78 ) ;
if ( F_28 ( V_11 ) ) {
goto V_99;
}
V_11 = F_31 ( V_52 , true , V_81 , V_77 ) ;
V_99:
F_32 ( V_52 , & V_96 ) ;
return V_11 ;
}
static int F_33 ( struct V_51 * V_52 ,
bool V_80 , bool V_95 ,
bool V_81 ,
struct V_76 * V_77 )
{
struct V_1 * V_6 ;
struct V_76 * V_78 = & V_52 -> V_66 ;
struct V_76 V_96 ;
struct V_53 V_54 ;
struct V_57 V_58 ;
int V_11 ;
V_6 = F_1 ( V_52 -> V_3 ) ;
V_96 = * V_77 ;
V_96 . V_79 = NULL ;
V_54 . V_63 = 1 ;
V_54 . V_54 = & V_58 ;
V_54 . V_64 = 1 ;
V_54 . V_62 = & V_58 ;
V_58 . V_59 = 0 ;
V_58 . V_60 = 0 ;
V_58 . V_26 = V_32 | V_97 ;
V_11 = F_27 ( V_52 , & V_54 , & V_96 ,
V_95 , V_81 ) ;
if ( F_28 ( V_11 ) ) {
return V_11 ;
}
V_11 = F_31 ( V_52 , true , V_81 , & V_96 ) ;
if ( F_28 ( V_11 ) ) {
goto V_99;
}
V_11 = F_21 ( V_52 , true , V_81 , V_77 , V_78 ) ;
if ( F_28 ( V_11 ) ) {
goto V_99;
}
V_99:
F_32 ( V_52 , & V_96 ) ;
return V_11 ;
}
static int F_34 ( struct V_51 * V_52 ,
bool V_80 , bool V_95 ,
bool V_81 ,
struct V_76 * V_77 )
{
struct V_1 * V_6 ;
struct V_76 * V_78 = & V_52 -> V_66 ;
int V_11 ;
V_6 = F_1 ( V_52 -> V_3 ) ;
if ( V_78 -> V_67 == V_29 && V_52 -> V_98 == NULL ) {
F_19 ( V_52 , V_77 ) ;
return 0 ;
}
if ( ( V_78 -> V_67 == V_35 &&
V_77 -> V_67 == V_29 ) ||
( V_78 -> V_67 == V_29 &&
V_77 -> V_67 == V_35 ) ) {
F_19 ( V_52 , V_77 ) ;
return 0 ;
}
if ( V_6 -> V_5 . V_100 == NULL ||
V_6 -> V_5 . V_68 == NULL ||
! V_6 -> V_5 . V_68 -> V_69 ) {
goto memcpy;
}
if ( V_78 -> V_67 == V_42 &&
V_77 -> V_67 == V_29 ) {
V_11 = F_26 ( V_52 , V_80 , V_95 ,
V_81 , V_77 ) ;
} else if ( V_78 -> V_67 == V_29 &&
V_77 -> V_67 == V_42 ) {
V_11 = F_33 ( V_52 , V_80 , V_95 ,
V_81 , V_77 ) ;
} else {
V_11 = F_21 ( V_52 , V_80 , V_81 , V_77 , V_78 ) ;
}
if ( V_11 ) {
memcpy:
V_11 = F_35 ( V_52 , V_80 , V_81 , V_77 ) ;
if ( V_11 ) {
return V_11 ;
}
}
F_36 ( ( V_101 ) V_52 -> V_92 << V_89 , & V_6 -> V_102 ) ;
return 0 ;
}
static int F_37 ( struct V_2 * V_3 , struct V_76 * V_66 )
{
struct V_27 * V_28 = & V_3 -> V_28 [ V_66 -> V_67 ] ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
V_66 -> V_103 . V_104 = NULL ;
V_66 -> V_103 . V_105 = 0 ;
V_66 -> V_103 . V_16 = V_66 -> V_92 << V_89 ;
V_66 -> V_103 . V_94 = 0 ;
V_66 -> V_103 . V_106 = false ;
if ( ! ( V_28 -> V_26 & V_30 ) )
return - V_50 ;
switch ( V_66 -> V_67 ) {
case V_29 :
return 0 ;
case V_35 :
break;
case V_42 :
V_66 -> V_103 . V_105 = V_66 -> V_88 << V_89 ;
if ( ( V_66 -> V_103 . V_105 + V_66 -> V_103 . V_16 ) > V_6 -> V_39 . V_107 )
return - V_50 ;
V_66 -> V_103 . V_94 = V_6 -> V_39 . V_108 ;
V_66 -> V_103 . V_106 = true ;
#ifdef F_38
if ( V_66 -> V_54 & V_46 )
V_66 -> V_103 . V_104 =
F_39 ( V_66 -> V_103 . V_94 + V_66 -> V_103 . V_105 ,
V_66 -> V_103 . V_16 ) ;
else
V_66 -> V_103 . V_104 =
F_40 ( V_66 -> V_103 . V_94 + V_66 -> V_103 . V_105 ,
V_66 -> V_103 . V_16 ) ;
V_66 -> V_103 . V_94 = ( V_66 -> V_103 . V_94 & 0x0ffffffffUL ) +
V_6 -> V_109 -> V_110 -> V_111 ;
#endif
break;
default:
return - V_50 ;
}
return 0 ;
}
static void F_41 ( struct V_2 * V_3 , struct V_76 * V_66 )
{
}
static int F_42 ( struct V_112 * V_98 )
{
struct V_1 * V_6 = F_1 ( V_98 -> V_3 ) ;
struct V_113 * V_114 = ( void * ) V_98 ;
unsigned V_115 = 0 , V_116 ;
int V_11 ;
int V_117 = ! ( V_114 -> V_118 & V_119 ) ;
enum V_120 V_121 = V_117 ?
V_122 : V_123 ;
if ( V_124 -> V_125 != V_114 -> V_126 )
return - V_127 ;
if ( V_114 -> V_118 & V_128 ) {
unsigned long V_129 = V_114 -> V_130 + V_98 -> V_92 * V_90 ;
struct V_131 * V_132 ;
V_132 = F_43 ( V_114 -> V_126 , V_114 -> V_130 ) ;
if ( ! V_132 || V_132 -> V_133 || V_132 -> V_134 < V_129 )
return - V_127 ;
}
do {
unsigned V_92 = V_98 -> V_92 - V_115 ;
T_2 V_130 = V_114 -> V_130 + V_115 * V_90 ;
struct V_135 * * V_136 = V_98 -> V_136 + V_115 ;
V_11 = F_44 ( V_124 , V_124 -> V_125 , V_130 , V_92 ,
V_117 , 0 , V_136 , NULL ) ;
if ( V_11 < 0 )
goto V_137;
V_115 += V_11 ;
} while ( V_115 < V_98 -> V_92 );
V_11 = F_45 ( V_98 -> V_138 , V_98 -> V_136 , V_98 -> V_92 , 0 ,
V_98 -> V_92 << V_89 ,
V_139 ) ;
if ( V_11 )
goto V_140;
V_11 = - V_141 ;
V_116 = F_46 ( V_6 -> V_142 , V_98 -> V_138 -> V_143 , V_98 -> V_138 -> V_116 , V_121 ) ;
if ( V_116 != V_98 -> V_138 -> V_116 )
goto V_140;
F_47 ( V_98 -> V_138 , V_98 -> V_136 ,
V_114 -> V_98 . V_144 , V_98 -> V_92 ) ;
return 0 ;
V_140:
F_48 ( V_98 -> V_138 ) ;
V_137:
V_137 ( V_98 -> V_136 , V_115 , 0 ) ;
return V_11 ;
}
static void F_49 ( struct V_112 * V_98 )
{
struct V_1 * V_6 = F_1 ( V_98 -> V_3 ) ;
struct V_113 * V_114 = ( void * ) V_98 ;
struct V_145 V_146 ;
int V_117 = ! ( V_114 -> V_118 & V_119 ) ;
enum V_120 V_121 = V_117 ?
V_122 : V_123 ;
if ( ! V_98 -> V_138 -> V_143 )
return;
F_50 ( V_6 -> V_142 , V_98 -> V_138 -> V_143 , V_98 -> V_138 -> V_116 , V_121 ) ;
F_51 (ttm->sg->sgl, &sg_iter, ttm->sg->nents, 0 ) {
struct V_135 * V_135 = F_52 ( & V_146 ) ;
if ( ! ( V_114 -> V_118 & V_119 ) )
F_53 ( V_135 ) ;
F_54 ( V_135 ) ;
F_55 ( V_135 ) ;
}
F_56 ( V_98 -> V_138 ) ;
}
static int F_57 ( struct V_112 * V_98 ,
struct V_76 * V_147 )
{
struct V_113 * V_114 = ( void * ) V_98 ;
T_1 V_26 = F_58 ( V_114 -> V_6 , V_98 , V_147 ) ;
int V_11 ;
if ( V_114 -> V_130 )
F_42 ( V_98 ) ;
V_114 -> V_105 = ( unsigned long ) ( V_147 -> V_88 << V_89 ) ;
if ( ! V_98 -> V_92 ) {
F_59 ( 1 , L_7 ,
V_98 -> V_92 , V_147 , V_98 ) ;
}
if ( V_147 -> V_67 == V_47 ||
V_147 -> V_67 == V_48 ||
V_147 -> V_67 == V_49 )
return - V_50 ;
V_11 = F_60 ( V_114 -> V_6 , V_114 -> V_105 , V_98 -> V_92 ,
V_98 -> V_136 , V_114 -> V_98 . V_144 , V_26 ) ;
if ( V_11 ) {
F_9 ( L_8 ,
V_98 -> V_92 , ( unsigned ) V_114 -> V_105 ) ;
return V_11 ;
}
return 0 ;
}
static int F_61 ( struct V_112 * V_98 )
{
struct V_113 * V_114 = ( void * ) V_98 ;
if ( V_114 -> V_6 -> V_148 . V_69 )
F_62 ( V_114 -> V_6 , V_114 -> V_105 , V_98 -> V_92 ) ;
if ( V_114 -> V_130 )
F_49 ( V_98 ) ;
return 0 ;
}
static void F_63 ( struct V_112 * V_98 )
{
struct V_113 * V_114 = ( void * ) V_98 ;
F_64 ( & V_114 -> V_98 ) ;
F_48 ( V_114 ) ;
}
static struct V_112 * F_65 ( struct V_2 * V_3 ,
unsigned long V_16 , T_1 V_149 ,
struct V_135 * V_150 )
{
struct V_1 * V_6 ;
struct V_113 * V_114 ;
V_6 = F_1 ( V_3 ) ;
V_114 = F_66 ( sizeof( struct V_113 ) , V_139 ) ;
if ( V_114 == NULL ) {
return NULL ;
}
V_114 -> V_98 . V_98 . V_36 = & V_151 ;
V_114 -> V_6 = V_6 ;
if ( F_67 ( & V_114 -> V_98 , V_3 , V_16 , V_149 , V_150 ) ) {
F_48 ( V_114 ) ;
return NULL ;
}
return & V_114 -> V_98 . V_98 ;
}
static int F_68 ( struct V_112 * V_98 )
{
struct V_1 * V_6 ;
struct V_113 * V_114 = ( void * ) V_98 ;
unsigned V_152 ;
int V_11 ;
bool V_153 = ! ! ( V_98 -> V_149 & V_154 ) ;
if ( V_98 -> V_155 != V_156 )
return 0 ;
if ( V_114 && V_114 -> V_130 ) {
V_98 -> V_138 = F_66 ( sizeof( struct V_157 ) , V_139 ) ;
if ( ! V_98 -> V_138 )
return - V_141 ;
V_98 -> V_149 |= V_154 ;
V_98 -> V_155 = V_158 ;
return 0 ;
}
if ( V_153 && V_98 -> V_138 ) {
F_47 ( V_98 -> V_138 , V_98 -> V_136 ,
V_114 -> V_98 . V_144 , V_98 -> V_92 ) ;
V_98 -> V_155 = V_158 ;
return 0 ;
}
V_6 = F_1 ( V_98 -> V_3 ) ;
#ifdef F_69
if ( F_70 () ) {
return F_71 ( & V_114 -> V_98 , V_6 -> V_142 ) ;
}
#endif
V_11 = F_72 ( V_98 ) ;
if ( V_11 ) {
return V_11 ;
}
for ( V_152 = 0 ; V_152 < V_98 -> V_92 ; V_152 ++ ) {
V_114 -> V_98 . V_144 [ V_152 ] = F_73 ( V_6 -> V_159 , V_98 -> V_136 [ V_152 ] ,
0 , V_90 ,
V_160 ) ;
if ( F_74 ( V_6 -> V_159 , V_114 -> V_98 . V_144 [ V_152 ] ) ) {
while ( -- V_152 ) {
F_75 ( V_6 -> V_159 , V_114 -> V_98 . V_144 [ V_152 ] ,
V_90 , V_160 ) ;
V_114 -> V_98 . V_144 [ V_152 ] = 0 ;
}
F_76 ( V_98 ) ;
return - V_161 ;
}
}
return 0 ;
}
static void F_77 ( struct V_112 * V_98 )
{
struct V_1 * V_6 ;
struct V_113 * V_114 = ( void * ) V_98 ;
unsigned V_152 ;
bool V_153 = ! ! ( V_98 -> V_149 & V_154 ) ;
if ( V_114 && V_114 -> V_130 ) {
F_48 ( V_98 -> V_138 ) ;
V_98 -> V_149 &= ~ V_154 ;
return;
}
if ( V_153 )
return;
V_6 = F_1 ( V_98 -> V_3 ) ;
#ifdef F_69
if ( F_70 () ) {
F_78 ( & V_114 -> V_98 , V_6 -> V_142 ) ;
return;
}
#endif
for ( V_152 = 0 ; V_152 < V_98 -> V_92 ; V_152 ++ ) {
if ( V_114 -> V_98 . V_144 [ V_152 ] ) {
F_75 ( V_6 -> V_159 , V_114 -> V_98 . V_144 [ V_152 ] ,
V_90 , V_160 ) ;
}
}
F_76 ( V_98 ) ;
}
int F_79 ( struct V_112 * V_98 , T_2 V_104 ,
T_1 V_26 )
{
struct V_113 * V_114 = ( void * ) V_98 ;
if ( V_114 == NULL )
return - V_50 ;
V_114 -> V_130 = V_104 ;
V_114 -> V_126 = V_124 -> V_125 ;
V_114 -> V_118 = V_26 ;
return 0 ;
}
bool F_80 ( struct V_112 * V_98 )
{
struct V_113 * V_114 = ( void * ) V_98 ;
if ( V_114 == NULL )
return false ;
return ! ! V_114 -> V_130 ;
}
bool F_81 ( struct V_112 * V_98 )
{
struct V_113 * V_114 = ( void * ) V_98 ;
if ( V_114 == NULL )
return false ;
return ! ! ( V_114 -> V_118 & V_119 ) ;
}
T_1 F_58 ( struct V_1 * V_6 , struct V_112 * V_98 ,
struct V_76 * V_66 )
{
T_1 V_26 = 0 ;
if ( V_66 && V_66 -> V_67 != V_29 )
V_26 |= V_162 ;
if ( V_66 && V_66 -> V_67 == V_35 )
V_26 |= V_163 ;
if ( ! V_98 || V_98 -> V_164 == V_165 )
V_26 |= V_166 ;
if ( V_6 -> V_167 >= V_168 )
V_26 |= V_169 ;
V_26 |= V_170 ;
if ( ! F_81 ( V_98 ) )
V_26 |= V_171 ;
return V_26 ;
}
int F_82 ( struct V_1 * V_6 )
{
int V_11 ;
V_11 = F_7 ( V_6 ) ;
if ( V_11 ) {
return V_11 ;
}
V_11 = F_83 ( & V_6 -> V_5 . V_3 ,
V_6 -> V_5 . V_20 . V_8 . V_9 ,
& V_172 ,
V_6 -> V_109 -> V_173 -> V_174 ,
V_175 ,
V_6 -> V_176 ) ;
if ( V_11 ) {
F_9 ( L_9 , V_11 ) ;
return V_11 ;
}
V_6 -> V_5 . V_177 = true ;
V_11 = F_84 ( & V_6 -> V_5 . V_3 , V_42 ,
V_6 -> V_39 . V_178 >> V_89 ) ;
if ( V_11 ) {
F_9 ( L_10 ) ;
return V_11 ;
}
F_85 ( V_6 , V_6 -> V_39 . V_107 ) ;
V_11 = F_86 ( V_6 , 256 * 1024 , V_90 , true ,
V_179 , 0 ,
NULL , & V_6 -> V_180 ) ;
if ( V_11 ) {
return V_11 ;
}
V_11 = F_87 ( V_6 -> V_180 , false ) ;
if ( V_11 )
return V_11 ;
V_11 = F_88 ( V_6 -> V_180 , V_179 , NULL ) ;
F_89 ( V_6 -> V_180 ) ;
if ( V_11 ) {
F_90 ( & V_6 -> V_180 ) ;
return V_11 ;
}
F_91 ( L_11 ,
( unsigned ) ( V_6 -> V_39 . V_178 / ( 1024 * 1024 ) ) ) ;
V_11 = F_84 ( & V_6 -> V_5 . V_3 , V_35 ,
V_6 -> V_39 . V_181 >> V_89 ) ;
if ( V_11 ) {
F_9 ( L_12 ) ;
return V_11 ;
}
F_91 ( L_13 ,
( unsigned ) ( V_6 -> V_39 . V_181 / ( 1024 * 1024 ) ) ) ;
V_6 -> V_182 . V_66 . V_183 = V_6 -> V_182 . V_66 . V_183 << V_184 ;
V_6 -> V_182 . V_66 . V_185 = V_6 -> V_182 . V_66 . V_185 << V_184 ;
V_6 -> V_182 . V_66 . V_186 = V_6 -> V_182 . V_66 . V_186 << V_184 ;
V_6 -> V_182 . V_187 . V_183 = V_6 -> V_182 . V_187 . V_183 << V_188 ;
V_6 -> V_182 . V_187 . V_185 = V_6 -> V_182 . V_187 . V_185 << V_188 ;
V_6 -> V_182 . V_187 . V_186 = V_6 -> V_182 . V_187 . V_186 << V_188 ;
V_6 -> V_182 . V_189 . V_183 = V_6 -> V_182 . V_189 . V_183 << V_190 ;
V_6 -> V_182 . V_189 . V_185 = V_6 -> V_182 . V_189 . V_185 << V_190 ;
V_6 -> V_182 . V_189 . V_186 = V_6 -> V_182 . V_189 . V_186 << V_190 ;
V_11 = F_84 ( & V_6 -> V_5 . V_3 , V_47 ,
V_6 -> V_182 . V_66 . V_183 >> V_89 ) ;
if ( V_11 ) {
F_9 ( L_14 ) ;
return V_11 ;
}
V_11 = F_84 ( & V_6 -> V_5 . V_3 , V_48 ,
V_6 -> V_182 . V_187 . V_183 >> V_89 ) ;
if ( V_11 ) {
F_9 ( L_15 ) ;
return V_11 ;
}
V_11 = F_84 ( & V_6 -> V_5 . V_3 , V_49 ,
V_6 -> V_182 . V_189 . V_183 >> V_89 ) ;
if ( V_11 ) {
F_9 ( L_16 ) ;
return V_11 ;
}
V_11 = F_92 ( V_6 ) ;
if ( V_11 ) {
F_9 ( L_17 ) ;
return V_11 ;
}
return 0 ;
}
void F_93 ( struct V_1 * V_6 )
{
int V_11 ;
if ( ! V_6 -> V_5 . V_177 )
return;
F_94 ( V_6 ) ;
if ( V_6 -> V_180 ) {
V_11 = F_87 ( V_6 -> V_180 , false ) ;
if ( V_11 == 0 ) {
F_95 ( V_6 -> V_180 ) ;
F_89 ( V_6 -> V_180 ) ;
}
F_90 ( & V_6 -> V_180 ) ;
}
F_96 ( & V_6 -> V_5 . V_3 , V_42 ) ;
F_96 ( & V_6 -> V_5 . V_3 , V_35 ) ;
F_96 ( & V_6 -> V_5 . V_3 , V_47 ) ;
F_96 ( & V_6 -> V_5 . V_3 , V_48 ) ;
F_96 ( & V_6 -> V_5 . V_3 , V_49 ) ;
F_97 ( & V_6 -> V_5 . V_3 ) ;
F_98 ( V_6 ) ;
F_11 ( V_6 ) ;
V_6 -> V_5 . V_177 = false ;
F_91 ( L_18 ) ;
}
void F_85 ( struct V_1 * V_6 , V_101 V_16 )
{
struct V_27 * V_28 ;
if ( ! V_6 -> V_5 . V_177 )
return;
V_28 = & V_6 -> V_5 . V_3 . V_28 [ V_42 ] ;
V_28 -> V_16 = V_16 >> V_89 ;
}
int F_99 ( struct V_72 * V_73 , struct V_131 * V_132 )
{
struct V_191 * V_192 ;
struct V_1 * V_6 ;
if ( F_28 ( V_132 -> V_193 < V_175 ) )
return - V_50 ;
V_192 = V_73 -> V_194 ;
V_6 = V_192 -> V_195 -> V_142 -> V_196 ;
if ( V_6 == NULL )
return - V_50 ;
return F_100 ( V_73 , V_132 , & V_6 -> V_5 . V_3 ) ;
}
int F_23 ( struct V_82 * V_83 ,
T_2 V_197 ,
T_2 V_198 ,
T_1 V_199 ,
struct V_200 * V_93 ,
struct V_86 * * V_87 )
{
struct V_1 * V_6 = V_83 -> V_6 ;
struct V_201 V_202 ;
T_1 V_203 ;
unsigned V_204 , V_205 ;
unsigned V_152 ;
int V_11 ;
F_101 ( & V_202 ) ;
if ( V_93 ) {
V_11 = F_102 ( V_6 , & V_202 , V_93 , false ) ;
if ( V_11 ) {
F_9 ( L_19 , V_11 ) ;
F_103 ( V_6 , & V_202 , NULL ) ;
return V_11 ;
}
}
V_203 = V_6 -> V_5 . V_100 -> V_206 ;
V_204 = F_104 ( V_199 , V_203 ) ;
V_205 = V_204 * V_6 -> V_5 . V_100 -> V_207 ;
V_205 += 64 + V_208 * 8 ;
V_11 = F_105 ( V_83 , V_205 ) ;
if ( V_11 ) {
F_9 ( L_20 , V_11 ) ;
F_103 ( V_6 , & V_202 , NULL ) ;
return V_11 ;
}
F_106 ( & V_202 , V_83 ) ;
for ( V_152 = 0 ; V_152 < V_204 ; V_152 ++ ) {
T_1 V_209 = F_107 ( V_199 , V_203 ) ;
F_108 ( V_6 , V_83 , V_197 , V_198 ,
V_209 ) ;
V_197 += V_209 ;
V_198 += V_209 ;
V_199 -= V_209 ;
}
V_11 = F_109 ( V_83 , V_210 , V_87 ) ;
if ( V_11 ) {
F_110 ( V_83 ) ;
F_103 ( V_6 , & V_202 , NULL ) ;
return V_11 ;
}
F_111 ( V_83 ) ;
F_103 ( V_6 , & V_202 , * V_87 ) ;
return 0 ;
}
static int F_112 ( struct V_211 * V_212 , void * V_213 )
{
struct V_214 * V_215 = (struct V_214 * ) V_212 -> V_216 ;
unsigned V_217 = * ( int * ) V_215 -> V_218 -> V_213 ;
struct V_219 * V_142 = V_215 -> V_195 -> V_142 ;
struct V_1 * V_6 = V_142 -> V_196 ;
struct V_220 * V_125 = (struct V_220 * ) V_6 -> V_5 . V_3 . V_28 [ V_217 ] . V_221 ;
int V_222 ;
struct V_23 * V_223 = V_6 -> V_5 . V_3 . V_223 ;
F_113 ( & V_223 -> V_224 ) ;
V_222 = F_114 ( V_212 , V_125 ) ;
F_115 ( & V_223 -> V_224 ) ;
return V_222 ;
}
static T_3 F_116 ( struct V_72 * V_225 , char T_4 * V_226 ,
T_5 V_16 , T_6 * V_227 )
{
struct V_1 * V_6 = V_225 -> V_228 -> V_229 ;
T_3 V_230 = 0 ;
int V_11 ;
if ( V_16 & 0x3 || * V_227 & 0x3 )
return - V_50 ;
while ( V_16 ) {
unsigned long V_26 ;
T_1 V_231 ;
if ( * V_227 >= V_6 -> V_39 . V_232 )
return V_230 ;
F_117 ( & V_6 -> V_233 , V_26 ) ;
F_118 ( V_234 , ( ( T_1 ) * V_227 ) | 0x80000000 ) ;
F_118 ( V_235 , * V_227 >> 31 ) ;
V_231 = F_119 ( V_236 ) ;
F_120 ( & V_6 -> V_233 , V_26 ) ;
V_11 = F_121 ( V_231 , ( T_1 * ) V_226 ) ;
if ( V_11 )
return V_11 ;
V_230 += 4 ;
V_226 += 4 ;
* V_227 += 4 ;
V_16 -= 4 ;
}
return V_230 ;
}
static T_3 F_122 ( struct V_72 * V_225 , char T_4 * V_226 ,
T_5 V_16 , T_6 * V_227 )
{
struct V_1 * V_6 = V_225 -> V_228 -> V_229 ;
T_3 V_230 = 0 ;
int V_11 ;
while ( V_16 ) {
T_6 V_237 = * V_227 / V_90 ;
unsigned V_238 = * V_227 & ~ V_239 ;
T_5 V_240 = F_123 ( T_5 , V_16 , V_90 - V_238 ) ;
struct V_135 * V_135 ;
void * V_241 ;
if ( V_237 >= V_6 -> V_148 . V_242 )
return V_230 ;
V_135 = V_6 -> V_148 . V_136 [ V_237 ] ;
if ( V_135 ) {
V_241 = F_124 ( V_135 ) ;
V_241 += V_238 ;
V_11 = F_125 ( V_226 , V_241 , V_240 ) ;
F_126 ( V_6 -> V_148 . V_136 [ V_237 ] ) ;
} else
V_11 = F_127 ( V_226 , V_240 ) ;
if ( V_11 )
return - V_161 ;
V_230 += V_240 ;
V_226 += V_240 ;
* V_227 += V_240 ;
V_16 -= V_240 ;
}
return V_230 ;
}
static int F_92 ( struct V_1 * V_6 )
{
#if F_128 ( V_243 )
unsigned V_244 ;
struct V_245 * V_195 = V_6 -> V_109 -> V_246 ;
struct V_247 * V_248 , * V_249 = V_195 -> V_250 ;
V_248 = F_129 ( L_21 , V_251 | V_252 , V_249 ,
V_6 , & V_253 ) ;
if ( F_130 ( V_248 ) )
return F_131 ( V_248 ) ;
F_132 ( V_248 -> V_254 , V_6 -> V_39 . V_232 ) ;
V_6 -> V_5 . V_255 = V_248 ;
V_248 = F_129 ( L_22 , V_251 | V_252 , V_249 ,
V_6 , & V_256 ) ;
if ( F_130 ( V_248 ) )
return F_131 ( V_248 ) ;
F_132 ( V_248 -> V_254 , V_6 -> V_39 . V_181 ) ;
V_6 -> V_5 . V_114 = V_248 ;
V_244 = F_133 ( V_257 ) ;
#ifdef F_69
if ( ! F_70 () )
-- V_244 ;
#endif
return F_134 ( V_6 , V_257 , V_244 ) ;
#else
return 0 ;
#endif
}
static void F_94 ( struct V_1 * V_6 )
{
#if F_128 ( V_243 )
F_135 ( V_6 -> V_5 . V_255 ) ;
V_6 -> V_5 . V_255 = NULL ;
F_135 ( V_6 -> V_5 . V_114 ) ;
V_6 -> V_5 . V_114 = NULL ;
#endif
}
