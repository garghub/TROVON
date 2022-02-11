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
struct V_86 * V_86 ;
int V_11 ;
V_6 = F_1 ( V_52 -> V_3 ) ;
V_83 = V_6 -> V_5 . V_68 ;
V_84 = V_78 -> V_87 << V_88 ;
V_85 = V_77 -> V_87 << V_88 ;
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
F_22 ( ( V_89 % V_90 ) != 0 ) ;
V_11 = F_23 ( V_83 , V_84 , V_85 ,
V_77 -> V_91 * V_89 ,
V_52 -> V_92 , & V_86 ) ;
V_11 = F_24 ( V_52 , V_86 ,
V_80 , V_81 , V_77 ) ;
F_25 ( V_86 ) ;
return V_11 ;
}
static int F_26 ( struct V_51 * V_52 ,
bool V_80 , bool V_93 ,
bool V_81 ,
struct V_76 * V_77 )
{
struct V_1 * V_6 ;
struct V_76 * V_78 = & V_52 -> V_66 ;
struct V_76 V_94 ;
struct V_57 V_58 ;
struct V_53 V_54 ;
int V_11 ;
V_6 = F_1 ( V_52 -> V_3 ) ;
V_94 = * V_77 ;
V_94 . V_79 = NULL ;
V_54 . V_63 = 1 ;
V_54 . V_54 = & V_58 ;
V_54 . V_64 = 1 ;
V_54 . V_62 = & V_58 ;
V_58 . V_59 = 0 ;
V_58 . V_60 = 0 ;
V_58 . V_26 = V_32 | V_95 ;
V_11 = F_27 ( V_52 , & V_54 , & V_94 ,
V_93 , V_81 ) ;
if ( F_28 ( V_11 ) ) {
return V_11 ;
}
V_11 = F_29 ( V_52 -> V_96 , V_94 . V_54 ) ;
if ( F_28 ( V_11 ) ) {
goto V_97;
}
V_11 = F_30 ( V_52 -> V_96 , & V_94 ) ;
if ( F_28 ( V_11 ) ) {
goto V_97;
}
V_11 = F_21 ( V_52 , true , V_81 , & V_94 , V_78 ) ;
if ( F_28 ( V_11 ) ) {
goto V_97;
}
V_11 = F_31 ( V_52 , true , V_81 , V_77 ) ;
V_97:
F_32 ( V_52 , & V_94 ) ;
return V_11 ;
}
static int F_33 ( struct V_51 * V_52 ,
bool V_80 , bool V_93 ,
bool V_81 ,
struct V_76 * V_77 )
{
struct V_1 * V_6 ;
struct V_76 * V_78 = & V_52 -> V_66 ;
struct V_76 V_94 ;
struct V_53 V_54 ;
struct V_57 V_58 ;
int V_11 ;
V_6 = F_1 ( V_52 -> V_3 ) ;
V_94 = * V_77 ;
V_94 . V_79 = NULL ;
V_54 . V_63 = 1 ;
V_54 . V_54 = & V_58 ;
V_54 . V_64 = 1 ;
V_54 . V_62 = & V_58 ;
V_58 . V_59 = 0 ;
V_58 . V_60 = 0 ;
V_58 . V_26 = V_32 | V_95 ;
V_11 = F_27 ( V_52 , & V_54 , & V_94 ,
V_93 , V_81 ) ;
if ( F_28 ( V_11 ) ) {
return V_11 ;
}
V_11 = F_31 ( V_52 , true , V_81 , & V_94 ) ;
if ( F_28 ( V_11 ) ) {
goto V_97;
}
V_11 = F_21 ( V_52 , true , V_81 , V_77 , V_78 ) ;
if ( F_28 ( V_11 ) ) {
goto V_97;
}
V_97:
F_32 ( V_52 , & V_94 ) ;
return V_11 ;
}
static int F_34 ( struct V_51 * V_52 ,
bool V_80 , bool V_93 ,
bool V_81 ,
struct V_76 * V_77 )
{
struct V_1 * V_6 ;
struct V_76 * V_78 = & V_52 -> V_66 ;
int V_11 ;
V_6 = F_1 ( V_52 -> V_3 ) ;
if ( V_78 -> V_67 == V_29 && V_52 -> V_96 == NULL ) {
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
if ( V_6 -> V_5 . V_98 == NULL ||
V_6 -> V_5 . V_68 == NULL ||
! V_6 -> V_5 . V_68 -> V_69 ) {
goto memcpy;
}
if ( V_78 -> V_67 == V_42 &&
V_77 -> V_67 == V_29 ) {
V_11 = F_26 ( V_52 , V_80 , V_93 ,
V_81 , V_77 ) ;
} else if ( V_78 -> V_67 == V_29 &&
V_77 -> V_67 == V_42 ) {
V_11 = F_33 ( V_52 , V_80 , V_93 ,
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
F_36 ( ( V_99 ) V_52 -> V_91 << V_88 , & V_6 -> V_100 ) ;
return 0 ;
}
static int F_37 ( struct V_2 * V_3 , struct V_76 * V_66 )
{
struct V_27 * V_28 = & V_3 -> V_28 [ V_66 -> V_67 ] ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
V_66 -> V_101 . V_102 = NULL ;
V_66 -> V_101 . V_103 = 0 ;
V_66 -> V_101 . V_16 = V_66 -> V_91 << V_88 ;
V_66 -> V_101 . V_104 = 0 ;
V_66 -> V_101 . V_105 = false ;
if ( ! ( V_28 -> V_26 & V_30 ) )
return - V_50 ;
switch ( V_66 -> V_67 ) {
case V_29 :
return 0 ;
case V_35 :
break;
case V_42 :
V_66 -> V_101 . V_103 = V_66 -> V_87 << V_88 ;
if ( ( V_66 -> V_101 . V_103 + V_66 -> V_101 . V_16 ) > V_6 -> V_39 . V_106 )
return - V_50 ;
V_66 -> V_101 . V_104 = V_6 -> V_39 . V_107 ;
V_66 -> V_101 . V_105 = true ;
#ifdef F_38
if ( V_66 -> V_54 & V_46 )
V_66 -> V_101 . V_102 =
F_39 ( V_66 -> V_101 . V_104 + V_66 -> V_101 . V_103 ,
V_66 -> V_101 . V_16 ) ;
else
V_66 -> V_101 . V_102 =
F_40 ( V_66 -> V_101 . V_104 + V_66 -> V_101 . V_103 ,
V_66 -> V_101 . V_16 ) ;
V_66 -> V_101 . V_104 = ( V_66 -> V_101 . V_104 & 0x0ffffffffUL ) +
V_6 -> V_108 -> V_109 -> V_110 ;
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
static int F_42 ( struct V_111 * V_96 )
{
struct V_1 * V_6 = F_1 ( V_96 -> V_3 ) ;
struct V_112 * V_113 = ( void * ) V_96 ;
unsigned V_114 = 0 , V_115 ;
int V_11 ;
int V_116 = ! ( V_113 -> V_117 & V_118 ) ;
enum V_119 V_120 = V_116 ?
V_121 : V_122 ;
if ( V_123 -> V_124 != V_113 -> V_125 )
return - V_126 ;
if ( V_113 -> V_117 & V_127 ) {
unsigned long V_128 = V_113 -> V_129 + V_96 -> V_91 * V_89 ;
struct V_130 * V_131 ;
V_131 = F_43 ( V_113 -> V_125 , V_113 -> V_129 ) ;
if ( ! V_131 || V_131 -> V_132 || V_131 -> V_133 < V_128 )
return - V_126 ;
}
do {
unsigned V_91 = V_96 -> V_91 - V_114 ;
T_2 V_129 = V_113 -> V_129 + V_114 * V_89 ;
struct V_134 * * V_135 = V_96 -> V_135 + V_114 ;
V_11 = F_44 ( V_123 , V_123 -> V_124 , V_129 , V_91 ,
V_116 , 0 , V_135 , NULL ) ;
if ( V_11 < 0 )
goto V_136;
V_114 += V_11 ;
} while ( V_114 < V_96 -> V_91 );
V_11 = F_45 ( V_96 -> V_137 , V_96 -> V_135 , V_96 -> V_91 , 0 ,
V_96 -> V_91 << V_88 ,
V_138 ) ;
if ( V_11 )
goto V_139;
V_11 = - V_140 ;
V_115 = F_46 ( V_6 -> V_141 , V_96 -> V_137 -> V_142 , V_96 -> V_137 -> V_115 , V_120 ) ;
if ( V_115 != V_96 -> V_137 -> V_115 )
goto V_139;
F_47 ( V_96 -> V_137 , V_96 -> V_135 ,
V_113 -> V_96 . V_143 , V_96 -> V_91 ) ;
return 0 ;
V_139:
F_48 ( V_96 -> V_137 ) ;
V_136:
V_136 ( V_96 -> V_135 , V_114 , 0 ) ;
return V_11 ;
}
static void F_49 ( struct V_111 * V_96 )
{
struct V_1 * V_6 = F_1 ( V_96 -> V_3 ) ;
struct V_112 * V_113 = ( void * ) V_96 ;
struct V_144 V_145 ;
int V_116 = ! ( V_113 -> V_117 & V_118 ) ;
enum V_119 V_120 = V_116 ?
V_121 : V_122 ;
if ( ! V_96 -> V_137 -> V_142 )
return;
F_50 ( V_6 -> V_141 , V_96 -> V_137 -> V_142 , V_96 -> V_137 -> V_115 , V_120 ) ;
F_51 (ttm->sg->sgl, &sg_iter, ttm->sg->nents, 0 ) {
struct V_134 * V_134 = F_52 ( & V_145 ) ;
if ( ! ( V_113 -> V_117 & V_118 ) )
F_53 ( V_134 ) ;
F_54 ( V_134 ) ;
F_55 ( V_134 ) ;
}
F_56 ( V_96 -> V_137 ) ;
}
static int F_57 ( struct V_111 * V_96 ,
struct V_76 * V_146 )
{
struct V_112 * V_113 = ( void * ) V_96 ;
T_1 V_26 = F_58 ( V_113 -> V_6 , V_96 , V_146 ) ;
int V_11 ;
if ( V_113 -> V_129 ) {
V_11 = F_42 ( V_96 ) ;
if ( V_11 ) {
F_9 ( L_7 ) ;
return V_11 ;
}
}
V_113 -> V_103 = ( unsigned long ) ( V_146 -> V_87 << V_88 ) ;
if ( ! V_96 -> V_91 ) {
F_59 ( 1 , L_8 ,
V_96 -> V_91 , V_146 , V_96 ) ;
}
if ( V_146 -> V_67 == V_47 ||
V_146 -> V_67 == V_48 ||
V_146 -> V_67 == V_49 )
return - V_50 ;
V_11 = F_60 ( V_113 -> V_6 , V_113 -> V_103 , V_96 -> V_91 ,
V_96 -> V_135 , V_113 -> V_96 . V_143 , V_26 ) ;
if ( V_11 ) {
F_9 ( L_9 ,
V_96 -> V_91 , ( unsigned ) V_113 -> V_103 ) ;
return V_11 ;
}
return 0 ;
}
static int F_61 ( struct V_111 * V_96 )
{
struct V_112 * V_113 = ( void * ) V_96 ;
if ( V_113 -> V_6 -> V_147 . V_69 )
F_62 ( V_113 -> V_6 , V_113 -> V_103 , V_96 -> V_91 ) ;
if ( V_113 -> V_129 )
F_49 ( V_96 ) ;
return 0 ;
}
static void F_63 ( struct V_111 * V_96 )
{
struct V_112 * V_113 = ( void * ) V_96 ;
F_64 ( & V_113 -> V_96 ) ;
F_48 ( V_113 ) ;
}
static struct V_111 * F_65 ( struct V_2 * V_3 ,
unsigned long V_16 , T_1 V_148 ,
struct V_134 * V_149 )
{
struct V_1 * V_6 ;
struct V_112 * V_113 ;
V_6 = F_1 ( V_3 ) ;
V_113 = F_66 ( sizeof( struct V_112 ) , V_138 ) ;
if ( V_113 == NULL ) {
return NULL ;
}
V_113 -> V_96 . V_96 . V_36 = & V_150 ;
V_113 -> V_6 = V_6 ;
if ( F_67 ( & V_113 -> V_96 , V_3 , V_16 , V_148 , V_149 ) ) {
F_48 ( V_113 ) ;
return NULL ;
}
return & V_113 -> V_96 . V_96 ;
}
static int F_68 ( struct V_111 * V_96 )
{
struct V_1 * V_6 ;
struct V_112 * V_113 = ( void * ) V_96 ;
unsigned V_151 ;
int V_11 ;
bool V_152 = ! ! ( V_96 -> V_148 & V_153 ) ;
if ( V_96 -> V_154 != V_155 )
return 0 ;
if ( V_113 && V_113 -> V_129 ) {
V_96 -> V_137 = F_66 ( sizeof( struct V_156 ) , V_138 ) ;
if ( ! V_96 -> V_137 )
return - V_140 ;
V_96 -> V_148 |= V_153 ;
V_96 -> V_154 = V_157 ;
return 0 ;
}
if ( V_152 && V_96 -> V_137 ) {
F_47 ( V_96 -> V_137 , V_96 -> V_135 ,
V_113 -> V_96 . V_143 , V_96 -> V_91 ) ;
V_96 -> V_154 = V_157 ;
return 0 ;
}
V_6 = F_1 ( V_96 -> V_3 ) ;
#ifdef F_69
if ( F_70 () ) {
return F_71 ( & V_113 -> V_96 , V_6 -> V_141 ) ;
}
#endif
V_11 = F_72 ( V_96 ) ;
if ( V_11 ) {
return V_11 ;
}
for ( V_151 = 0 ; V_151 < V_96 -> V_91 ; V_151 ++ ) {
V_113 -> V_96 . V_143 [ V_151 ] = F_73 ( V_6 -> V_158 , V_96 -> V_135 [ V_151 ] ,
0 , V_89 ,
V_159 ) ;
if ( F_74 ( V_6 -> V_158 , V_113 -> V_96 . V_143 [ V_151 ] ) ) {
while ( V_151 -- ) {
F_75 ( V_6 -> V_158 , V_113 -> V_96 . V_143 [ V_151 ] ,
V_89 , V_159 ) ;
V_113 -> V_96 . V_143 [ V_151 ] = 0 ;
}
F_76 ( V_96 ) ;
return - V_160 ;
}
}
return 0 ;
}
static void F_77 ( struct V_111 * V_96 )
{
struct V_1 * V_6 ;
struct V_112 * V_113 = ( void * ) V_96 ;
unsigned V_151 ;
bool V_152 = ! ! ( V_96 -> V_148 & V_153 ) ;
if ( V_113 && V_113 -> V_129 ) {
F_48 ( V_96 -> V_137 ) ;
V_96 -> V_148 &= ~ V_153 ;
return;
}
if ( V_152 )
return;
V_6 = F_1 ( V_96 -> V_3 ) ;
#ifdef F_69
if ( F_70 () ) {
F_78 ( & V_113 -> V_96 , V_6 -> V_141 ) ;
return;
}
#endif
for ( V_151 = 0 ; V_151 < V_96 -> V_91 ; V_151 ++ ) {
if ( V_113 -> V_96 . V_143 [ V_151 ] ) {
F_75 ( V_6 -> V_158 , V_113 -> V_96 . V_143 [ V_151 ] ,
V_89 , V_159 ) ;
}
}
F_76 ( V_96 ) ;
}
int F_79 ( struct V_111 * V_96 , T_2 V_102 ,
T_1 V_26 )
{
struct V_112 * V_113 = ( void * ) V_96 ;
if ( V_113 == NULL )
return - V_50 ;
V_113 -> V_129 = V_102 ;
V_113 -> V_125 = V_123 -> V_124 ;
V_113 -> V_117 = V_26 ;
return 0 ;
}
bool F_80 ( struct V_111 * V_96 )
{
struct V_112 * V_113 = ( void * ) V_96 ;
if ( V_113 == NULL )
return false ;
return ! ! V_113 -> V_129 ;
}
bool F_81 ( struct V_111 * V_96 , unsigned long V_87 ,
unsigned long V_128 )
{
struct V_112 * V_113 = ( void * ) V_96 ;
unsigned long V_16 ;
if ( V_113 == NULL )
return false ;
if ( V_113 -> V_96 . V_96 . V_154 != V_161 || ! V_113 -> V_129 )
return false ;
V_16 = ( unsigned long ) V_113 -> V_96 . V_96 . V_91 * V_89 ;
if ( V_113 -> V_129 > V_128 || V_113 -> V_129 + V_16 <= V_87 )
return false ;
return true ;
}
bool F_82 ( struct V_111 * V_96 )
{
struct V_112 * V_113 = ( void * ) V_96 ;
if ( V_113 == NULL )
return false ;
return ! ! ( V_113 -> V_117 & V_118 ) ;
}
T_1 F_58 ( struct V_1 * V_6 , struct V_111 * V_96 ,
struct V_76 * V_66 )
{
T_1 V_26 = 0 ;
if ( V_66 && V_66 -> V_67 != V_29 )
V_26 |= V_162 ;
if ( V_66 && V_66 -> V_67 == V_35 ) {
V_26 |= V_163 ;
if ( V_96 -> V_164 == V_165 )
V_26 |= V_166 ;
}
if ( V_6 -> V_167 >= V_168 )
V_26 |= V_169 ;
V_26 |= V_170 ;
if ( ! F_82 ( V_96 ) )
V_26 |= V_171 ;
return V_26 ;
}
int F_83 ( struct V_1 * V_6 )
{
int V_11 ;
V_11 = F_7 ( V_6 ) ;
if ( V_11 ) {
return V_11 ;
}
V_11 = F_84 ( & V_6 -> V_5 . V_3 ,
V_6 -> V_5 . V_20 . V_8 . V_9 ,
& V_172 ,
V_6 -> V_108 -> V_173 -> V_174 ,
V_175 ,
V_6 -> V_176 ) ;
if ( V_11 ) {
F_9 ( L_10 , V_11 ) ;
return V_11 ;
}
V_6 -> V_5 . V_177 = true ;
V_11 = F_85 ( & V_6 -> V_5 . V_3 , V_42 ,
V_6 -> V_39 . V_178 >> V_88 ) ;
if ( V_11 ) {
F_9 ( L_11 ) ;
return V_11 ;
}
F_86 ( V_6 , V_6 -> V_39 . V_106 ) ;
V_11 = F_87 ( V_6 , 256 * 1024 , V_89 , true ,
V_179 ,
V_180 ,
NULL , NULL , & V_6 -> V_181 ) ;
if ( V_11 ) {
return V_11 ;
}
V_11 = F_88 ( V_6 -> V_181 , false ) ;
if ( V_11 )
return V_11 ;
V_11 = F_89 ( V_6 -> V_181 , V_179 , NULL ) ;
F_90 ( V_6 -> V_181 ) ;
if ( V_11 ) {
F_91 ( & V_6 -> V_181 ) ;
return V_11 ;
}
F_92 ( L_12 ,
( unsigned ) ( V_6 -> V_39 . V_178 / ( 1024 * 1024 ) ) ) ;
V_11 = F_85 ( & V_6 -> V_5 . V_3 , V_35 ,
V_6 -> V_39 . V_182 >> V_88 ) ;
if ( V_11 ) {
F_9 ( L_13 ) ;
return V_11 ;
}
F_92 ( L_14 ,
( unsigned ) ( V_6 -> V_39 . V_182 / ( 1024 * 1024 ) ) ) ;
V_6 -> V_183 . V_66 . V_184 = V_6 -> V_183 . V_66 . V_184 << V_185 ;
V_6 -> V_183 . V_66 . V_186 = V_6 -> V_183 . V_66 . V_186 << V_185 ;
V_6 -> V_183 . V_66 . V_187 = V_6 -> V_183 . V_66 . V_187 << V_185 ;
V_6 -> V_183 . V_188 . V_184 = V_6 -> V_183 . V_188 . V_184 << V_189 ;
V_6 -> V_183 . V_188 . V_186 = V_6 -> V_183 . V_188 . V_186 << V_189 ;
V_6 -> V_183 . V_188 . V_187 = V_6 -> V_183 . V_188 . V_187 << V_189 ;
V_6 -> V_183 . V_190 . V_184 = V_6 -> V_183 . V_190 . V_184 << V_191 ;
V_6 -> V_183 . V_190 . V_186 = V_6 -> V_183 . V_190 . V_186 << V_191 ;
V_6 -> V_183 . V_190 . V_187 = V_6 -> V_183 . V_190 . V_187 << V_191 ;
V_11 = F_85 ( & V_6 -> V_5 . V_3 , V_47 ,
V_6 -> V_183 . V_66 . V_184 >> V_88 ) ;
if ( V_11 ) {
F_9 ( L_15 ) ;
return V_11 ;
}
V_11 = F_85 ( & V_6 -> V_5 . V_3 , V_48 ,
V_6 -> V_183 . V_188 . V_184 >> V_88 ) ;
if ( V_11 ) {
F_9 ( L_16 ) ;
return V_11 ;
}
V_11 = F_85 ( & V_6 -> V_5 . V_3 , V_49 ,
V_6 -> V_183 . V_190 . V_184 >> V_88 ) ;
if ( V_11 ) {
F_9 ( L_17 ) ;
return V_11 ;
}
V_11 = F_93 ( V_6 ) ;
if ( V_11 ) {
F_9 ( L_18 ) ;
return V_11 ;
}
return 0 ;
}
void F_94 ( struct V_1 * V_6 )
{
int V_11 ;
if ( ! V_6 -> V_5 . V_177 )
return;
F_95 ( V_6 ) ;
if ( V_6 -> V_181 ) {
V_11 = F_88 ( V_6 -> V_181 , false ) ;
if ( V_11 == 0 ) {
F_96 ( V_6 -> V_181 ) ;
F_90 ( V_6 -> V_181 ) ;
}
F_91 ( & V_6 -> V_181 ) ;
}
F_97 ( & V_6 -> V_5 . V_3 , V_42 ) ;
F_97 ( & V_6 -> V_5 . V_3 , V_35 ) ;
F_97 ( & V_6 -> V_5 . V_3 , V_47 ) ;
F_97 ( & V_6 -> V_5 . V_3 , V_48 ) ;
F_97 ( & V_6 -> V_5 . V_3 , V_49 ) ;
F_98 ( & V_6 -> V_5 . V_3 ) ;
F_99 ( V_6 ) ;
F_11 ( V_6 ) ;
V_6 -> V_5 . V_177 = false ;
F_92 ( L_19 ) ;
}
void F_86 ( struct V_1 * V_6 , V_99 V_16 )
{
struct V_27 * V_28 ;
if ( ! V_6 -> V_5 . V_177 )
return;
V_28 = & V_6 -> V_5 . V_3 . V_28 [ V_42 ] ;
V_28 -> V_16 = V_16 >> V_88 ;
}
int F_100 ( struct V_72 * V_73 , struct V_130 * V_131 )
{
struct V_192 * V_193 ;
struct V_1 * V_6 ;
if ( F_28 ( V_131 -> V_194 < V_175 ) )
return - V_50 ;
V_193 = V_73 -> V_195 ;
V_6 = V_193 -> V_196 -> V_141 -> V_197 ;
if ( V_6 == NULL )
return - V_50 ;
return F_101 ( V_73 , V_131 , & V_6 -> V_5 . V_3 ) ;
}
int F_23 ( struct V_82 * V_83 ,
T_2 V_198 ,
T_2 V_199 ,
T_1 V_200 ,
struct V_201 * V_92 ,
struct V_86 * * V_86 )
{
struct V_1 * V_6 = V_83 -> V_6 ;
T_1 V_202 ;
unsigned V_203 , V_204 ;
struct V_205 * V_206 ;
unsigned V_151 ;
int V_11 ;
V_202 = V_6 -> V_5 . V_98 -> V_207 ;
V_203 = F_102 ( V_200 , V_202 ) ;
V_204 = V_203 * V_6 -> V_5 . V_98 -> V_208 ;
while ( V_204 & 0x7 )
V_204 ++ ;
V_206 = F_66 ( sizeof( struct V_205 ) , V_138 ) ;
if ( ! V_206 )
return - V_140 ;
V_11 = F_103 ( V_83 , NULL , V_204 * 4 , V_206 ) ;
if ( V_11 ) {
F_48 ( V_206 ) ;
return V_11 ;
}
V_206 -> V_209 = 0 ;
if ( V_92 ) {
V_11 = F_104 ( V_6 , & V_206 -> V_210 , V_92 ,
V_211 ) ;
if ( V_11 ) {
F_9 ( L_20 , V_11 ) ;
goto V_212;
}
}
for ( V_151 = 0 ; V_151 < V_203 ; V_151 ++ ) {
T_1 V_213 = F_105 ( V_200 , V_202 ) ;
F_106 ( V_6 , V_206 , V_198 , V_199 ,
V_213 ) ;
V_198 += V_213 ;
V_199 += V_213 ;
V_200 -= V_213 ;
}
F_107 ( V_6 , V_206 ) ;
F_108 ( V_206 -> V_209 > V_204 ) ;
V_11 = F_109 ( V_6 , V_83 , V_206 , 1 ,
& V_214 ,
V_211 ,
V_86 ) ;
if ( V_11 )
goto V_212;
if ( ! V_215 ) {
F_110 ( V_6 , V_206 ) ;
F_48 ( V_206 ) ;
}
return 0 ;
V_212:
F_110 ( V_6 , V_206 ) ;
F_48 ( V_206 ) ;
return V_11 ;
}
static int F_111 ( struct V_216 * V_217 , void * V_218 )
{
struct V_219 * V_220 = (struct V_219 * ) V_217 -> V_221 ;
unsigned V_222 = * ( int * ) V_220 -> V_223 -> V_218 ;
struct V_224 * V_141 = V_220 -> V_196 -> V_141 ;
struct V_1 * V_6 = V_141 -> V_197 ;
struct V_225 * V_124 = (struct V_225 * ) V_6 -> V_5 . V_3 . V_28 [ V_222 ] . V_226 ;
int V_227 ;
struct V_23 * V_228 = V_6 -> V_5 . V_3 . V_228 ;
F_112 ( & V_228 -> V_229 ) ;
V_227 = F_113 ( V_217 , V_124 ) ;
F_114 ( & V_228 -> V_229 ) ;
if ( V_222 == V_42 )
F_115 ( V_217 , L_21 ,
V_6 -> V_5 . V_3 . V_28 [ V_222 ] . V_16 ,
( V_99 ) F_116 ( & V_6 -> V_230 ) >> 20 ,
( V_99 ) F_116 ( & V_6 -> V_231 ) >> 20 ) ;
return V_227 ;
}
static T_3 F_117 ( struct V_72 * V_232 , char T_4 * V_233 ,
T_5 V_16 , T_6 * V_234 )
{
struct V_1 * V_6 = V_232 -> V_235 -> V_236 ;
T_3 V_237 = 0 ;
int V_11 ;
if ( V_16 & 0x3 || * V_234 & 0x3 )
return - V_50 ;
while ( V_16 ) {
unsigned long V_26 ;
T_1 V_238 ;
if ( * V_234 >= V_6 -> V_39 . V_239 )
return V_237 ;
F_118 ( & V_6 -> V_240 , V_26 ) ;
F_119 ( V_241 , ( ( T_1 ) * V_234 ) | 0x80000000 ) ;
F_119 ( V_242 , * V_234 >> 31 ) ;
V_238 = F_120 ( V_243 ) ;
F_121 ( & V_6 -> V_240 , V_26 ) ;
V_11 = F_122 ( V_238 , ( T_1 * ) V_233 ) ;
if ( V_11 )
return V_11 ;
V_237 += 4 ;
V_233 += 4 ;
* V_234 += 4 ;
V_16 -= 4 ;
}
return V_237 ;
}
static T_3 F_123 ( struct V_72 * V_232 , char T_4 * V_233 ,
T_5 V_16 , T_6 * V_234 )
{
struct V_1 * V_6 = V_232 -> V_235 -> V_236 ;
T_3 V_237 = 0 ;
int V_11 ;
while ( V_16 ) {
T_6 V_244 = * V_234 / V_89 ;
unsigned V_245 = * V_234 & ~ V_246 ;
T_5 V_247 = F_124 ( T_5 , V_16 , V_89 - V_245 ) ;
struct V_134 * V_134 ;
void * V_248 ;
if ( V_244 >= V_6 -> V_147 . V_249 )
return V_237 ;
V_134 = V_6 -> V_147 . V_135 [ V_244 ] ;
if ( V_134 ) {
V_248 = F_125 ( V_134 ) ;
V_248 += V_245 ;
V_11 = F_126 ( V_233 , V_248 , V_247 ) ;
F_127 ( V_6 -> V_147 . V_135 [ V_244 ] ) ;
} else
V_11 = F_128 ( V_233 , V_247 ) ;
if ( V_11 )
return - V_160 ;
V_237 += V_247 ;
V_233 += V_247 ;
* V_234 += V_247 ;
V_16 -= V_247 ;
}
return V_237 ;
}
static int F_93 ( struct V_1 * V_6 )
{
#if F_129 ( V_250 )
unsigned V_251 ;
struct V_252 * V_196 = V_6 -> V_108 -> V_253 ;
struct V_254 * V_255 , * V_256 = V_196 -> V_257 ;
V_255 = F_130 ( L_22 , V_258 | V_259 , V_256 ,
V_6 , & V_260 ) ;
if ( F_131 ( V_255 ) )
return F_132 ( V_255 ) ;
F_133 ( V_255 -> V_261 , V_6 -> V_39 . V_239 ) ;
V_6 -> V_5 . V_262 = V_255 ;
V_255 = F_130 ( L_23 , V_258 | V_259 , V_256 ,
V_6 , & V_263 ) ;
if ( F_131 ( V_255 ) )
return F_132 ( V_255 ) ;
F_133 ( V_255 -> V_261 , V_6 -> V_39 . V_182 ) ;
V_6 -> V_5 . V_113 = V_255 ;
V_251 = F_134 ( V_264 ) ;
#ifdef F_69
if ( ! F_70 () )
-- V_251 ;
#endif
return F_135 ( V_6 , V_264 , V_251 ) ;
#else
return 0 ;
#endif
}
static void F_95 ( struct V_1 * V_6 )
{
#if F_129 ( V_250 )
F_136 ( V_6 -> V_5 . V_262 ) ;
V_6 -> V_5 . V_262 = NULL ;
F_136 ( V_6 -> V_5 . V_113 ) ;
V_6 -> V_5 . V_113 = NULL ;
#endif
}
