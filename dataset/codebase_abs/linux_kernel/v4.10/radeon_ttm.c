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
#if F_14 ( V_42 )
if ( V_6 -> V_26 & V_43 ) {
if ( ! V_6 -> V_44 -> V_45 ) {
F_9 ( L_4 ,
( unsigned ) type ) ;
return - V_46 ;
}
if ( ! V_6 -> V_44 -> V_45 -> V_47 )
V_28 -> V_26 = V_30 ;
V_28 -> V_31 = V_48 |
V_49 ;
V_28 -> V_33 = V_49 ;
}
#endif
break;
case V_50 :
V_28 -> V_36 = & V_37 ;
V_28 -> V_38 = V_6 -> V_39 . V_51 ;
V_28 -> V_26 = V_52 |
V_30 ;
V_28 -> V_31 = V_48 | V_49 ;
V_28 -> V_33 = V_49 ;
break;
default:
F_9 ( L_5 , ( unsigned ) type ) ;
return - V_46 ;
}
return 0 ;
}
static void F_15 ( struct V_53 * V_54 ,
struct V_55 * V_56 )
{
static struct V_57 V_58 = {
. V_59 = 0 ,
. V_60 = 0 ,
. V_26 = V_32 | V_61
} ;
struct V_62 * V_63 ;
if ( ! F_16 ( V_54 ) ) {
V_56 -> V_56 = & V_58 ;
V_56 -> V_64 = & V_58 ;
V_56 -> V_65 = 1 ;
V_56 -> V_66 = 1 ;
return;
}
V_63 = F_2 ( V_54 , struct V_62 , V_67 ) ;
switch ( V_54 -> V_68 . V_69 ) {
case V_50 :
if ( V_63 -> V_6 -> V_70 [ F_17 ( V_63 -> V_6 ) ] . V_71 == false )
F_18 ( V_63 , V_72 ) ;
else if ( V_63 -> V_6 -> V_39 . V_73 < V_63 -> V_6 -> V_39 . V_74 &&
V_54 -> V_68 . V_75 < ( V_63 -> V_6 -> V_39 . V_73 >> V_76 ) ) {
unsigned V_59 = V_63 -> V_6 -> V_39 . V_73 >> V_76 ;
int V_77 ;
F_18 ( V_63 , V_78 |
V_79 ) ;
V_63 -> V_56 . V_66 = 0 ;
for ( V_77 = 0 ; V_77 < V_63 -> V_56 . V_65 ; V_77 ++ ) {
if ( V_63 -> V_58 [ V_77 ] . V_26 & V_80 ) {
if ( V_63 -> V_58 [ 0 ] . V_59 < V_59 )
V_63 -> V_58 [ 0 ] . V_59 = V_59 ;
} else {
V_63 -> V_56 . V_64 =
& V_63 -> V_58 [ V_77 ] ;
V_63 -> V_56 . V_66 = 1 ;
}
}
} else
F_18 ( V_63 , V_79 ) ;
break;
case V_35 :
default:
F_18 ( V_63 , V_72 ) ;
}
* V_56 = V_63 -> V_56 ;
}
static int F_19 ( struct V_53 * V_54 , struct V_81 * V_82 )
{
struct V_62 * V_63 = F_2 ( V_54 , struct V_62 , V_67 ) ;
if ( F_20 ( V_54 -> V_83 ) )
return - V_84 ;
return F_21 ( & V_63 -> V_85 . V_86 ,
V_82 -> V_87 ) ;
}
static void F_22 ( struct V_53 * V_54 ,
struct V_88 * V_89 )
{
struct V_88 * V_90 = & V_54 -> V_68 ;
F_23 ( V_90 -> V_91 != NULL ) ;
* V_90 = * V_89 ;
V_89 -> V_91 = NULL ;
}
static int F_24 ( struct V_53 * V_54 ,
bool V_92 , bool V_93 ,
struct V_88 * V_89 ,
struct V_88 * V_90 )
{
struct V_1 * V_6 ;
T_2 V_94 , V_95 ;
struct V_96 * V_97 ;
unsigned V_98 ;
int V_11 , V_99 ;
V_6 = F_1 ( V_54 -> V_3 ) ;
V_99 = F_17 ( V_6 ) ;
V_94 = ( V_100 ) V_90 -> V_75 << V_76 ;
V_95 = ( V_100 ) V_89 -> V_75 << V_76 ;
switch ( V_90 -> V_69 ) {
case V_50 :
V_94 += V_6 -> V_39 . V_51 ;
break;
case V_35 :
V_94 += V_6 -> V_39 . V_40 ;
break;
default:
F_9 ( L_6 , V_90 -> V_69 ) ;
return - V_46 ;
}
switch ( V_89 -> V_69 ) {
case V_50 :
V_95 += V_6 -> V_39 . V_51 ;
break;
case V_35 :
V_95 += V_6 -> V_39 . V_40 ;
break;
default:
F_9 ( L_6 , V_90 -> V_69 ) ;
return - V_46 ;
}
if ( ! V_6 -> V_70 [ V_99 ] . V_71 ) {
F_9 ( L_7 ) ;
return - V_46 ;
}
F_25 ( ( V_101 % V_102 ) != 0 ) ;
V_98 = V_89 -> V_98 * ( V_101 / V_102 ) ;
V_97 = F_26 ( V_6 , V_94 , V_95 , V_98 , V_54 -> V_103 ) ;
if ( F_27 ( V_97 ) )
return F_28 ( V_97 ) ;
V_11 = F_29 ( V_54 , & V_97 -> V_104 , V_92 , V_89 ) ;
F_30 ( & V_97 ) ;
return V_11 ;
}
static int F_31 ( struct V_53 * V_54 ,
bool V_92 , bool V_105 ,
bool V_93 ,
struct V_88 * V_89 )
{
struct V_1 * V_6 ;
struct V_88 * V_90 = & V_54 -> V_68 ;
struct V_88 V_106 ;
struct V_57 V_58 ;
struct V_55 V_56 ;
int V_11 ;
V_6 = F_1 ( V_54 -> V_3 ) ;
V_106 = * V_89 ;
V_106 . V_91 = NULL ;
V_56 . V_65 = 1 ;
V_56 . V_56 = & V_58 ;
V_56 . V_66 = 1 ;
V_56 . V_64 = & V_58 ;
V_58 . V_59 = 0 ;
V_58 . V_60 = 0 ;
V_58 . V_26 = V_32 | V_107 ;
V_11 = F_32 ( V_54 , & V_56 , & V_106 ,
V_105 , V_93 ) ;
if ( F_33 ( V_11 ) ) {
return V_11 ;
}
V_11 = F_34 ( V_54 -> V_83 , V_106 . V_56 ) ;
if ( F_33 ( V_11 ) ) {
goto V_108;
}
V_11 = F_35 ( V_54 -> V_83 , & V_106 ) ;
if ( F_33 ( V_11 ) ) {
goto V_108;
}
V_11 = F_24 ( V_54 , true , V_93 , & V_106 , V_90 ) ;
if ( F_33 ( V_11 ) ) {
goto V_108;
}
V_11 = F_36 ( V_54 , V_105 , V_93 , V_89 ) ;
V_108:
F_37 ( V_54 , & V_106 ) ;
return V_11 ;
}
static int F_38 ( struct V_53 * V_54 ,
bool V_92 , bool V_105 ,
bool V_93 ,
struct V_88 * V_89 )
{
struct V_1 * V_6 ;
struct V_88 * V_90 = & V_54 -> V_68 ;
struct V_88 V_106 ;
struct V_55 V_56 ;
struct V_57 V_58 ;
int V_11 ;
V_6 = F_1 ( V_54 -> V_3 ) ;
V_106 = * V_89 ;
V_106 . V_91 = NULL ;
V_56 . V_65 = 1 ;
V_56 . V_56 = & V_58 ;
V_56 . V_66 = 1 ;
V_56 . V_64 = & V_58 ;
V_58 . V_59 = 0 ;
V_58 . V_60 = 0 ;
V_58 . V_26 = V_32 | V_107 ;
V_11 = F_32 ( V_54 , & V_56 , & V_106 ,
V_105 , V_93 ) ;
if ( F_33 ( V_11 ) ) {
return V_11 ;
}
V_11 = F_36 ( V_54 , V_105 , V_93 , & V_106 ) ;
if ( F_33 ( V_11 ) ) {
goto V_108;
}
V_11 = F_24 ( V_54 , true , V_93 , V_89 , V_90 ) ;
if ( F_33 ( V_11 ) ) {
goto V_108;
}
V_108:
F_37 ( V_54 , & V_106 ) ;
return V_11 ;
}
static int F_39 ( struct V_53 * V_54 ,
bool V_92 , bool V_105 ,
bool V_93 ,
struct V_88 * V_89 )
{
struct V_1 * V_6 ;
struct V_62 * V_63 ;
struct V_88 * V_90 = & V_54 -> V_68 ;
int V_11 ;
V_11 = F_40 ( V_54 , V_105 , V_93 ) ;
if ( V_11 )
return V_11 ;
V_63 = F_2 ( V_54 , struct V_62 , V_67 ) ;
if ( F_41 ( V_63 -> V_109 > 0 ) )
return - V_46 ;
V_6 = F_1 ( V_54 -> V_3 ) ;
if ( V_90 -> V_69 == V_29 && V_54 -> V_83 == NULL ) {
F_22 ( V_54 , V_89 ) ;
return 0 ;
}
if ( ( V_90 -> V_69 == V_35 &&
V_89 -> V_69 == V_29 ) ||
( V_90 -> V_69 == V_29 &&
V_89 -> V_69 == V_35 ) ) {
F_22 ( V_54 , V_89 ) ;
return 0 ;
}
if ( ! V_6 -> V_70 [ F_17 ( V_6 ) ] . V_71 ||
V_6 -> V_110 -> V_111 . V_111 == NULL ) {
goto memcpy;
}
if ( V_90 -> V_69 == V_50 &&
V_89 -> V_69 == V_29 ) {
V_11 = F_31 ( V_54 , V_92 , V_105 ,
V_93 , V_89 ) ;
} else if ( V_90 -> V_69 == V_29 &&
V_89 -> V_69 == V_50 ) {
V_11 = F_38 ( V_54 , V_92 , V_105 ,
V_93 , V_89 ) ;
} else {
V_11 = F_24 ( V_54 , V_92 , V_93 , V_89 , V_90 ) ;
}
if ( V_11 ) {
memcpy:
V_11 = F_42 ( V_54 , V_105 , V_93 , V_89 ) ;
if ( V_11 ) {
return V_11 ;
}
}
F_43 ( ( V_100 ) V_54 -> V_98 << V_76 , & V_6 -> V_112 ) ;
return 0 ;
}
static int F_44 ( struct V_2 * V_3 , struct V_88 * V_68 )
{
struct V_27 * V_28 = & V_3 -> V_28 [ V_68 -> V_69 ] ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
V_68 -> V_113 . V_114 = NULL ;
V_68 -> V_113 . V_115 = 0 ;
V_68 -> V_113 . V_16 = V_68 -> V_98 << V_76 ;
V_68 -> V_113 . V_104 = 0 ;
V_68 -> V_113 . V_116 = false ;
if ( ! ( V_28 -> V_26 & V_30 ) )
return - V_46 ;
switch ( V_68 -> V_69 ) {
case V_29 :
return 0 ;
case V_35 :
#if F_14 ( V_42 )
if ( V_6 -> V_26 & V_43 ) {
V_68 -> V_113 . V_115 = V_68 -> V_75 << V_76 ;
V_68 -> V_113 . V_104 = V_6 -> V_39 . V_117 ;
V_68 -> V_113 . V_116 = ! V_6 -> V_44 -> V_45 -> V_47 ;
}
#endif
break;
case V_50 :
V_68 -> V_113 . V_115 = V_68 -> V_75 << V_76 ;
if ( ( V_68 -> V_113 . V_115 + V_68 -> V_113 . V_16 ) > V_6 -> V_39 . V_73 )
return - V_46 ;
V_68 -> V_113 . V_104 = V_6 -> V_39 . V_118 ;
V_68 -> V_113 . V_116 = true ;
#ifdef F_45
if ( V_68 -> V_56 & V_49 )
V_68 -> V_113 . V_114 =
F_46 ( V_68 -> V_113 . V_104 + V_68 -> V_113 . V_115 ,
V_68 -> V_113 . V_16 ) ;
else
V_68 -> V_113 . V_114 =
F_47 ( V_68 -> V_113 . V_104 + V_68 -> V_113 . V_115 ,
V_68 -> V_113 . V_16 ) ;
V_68 -> V_113 . V_104 = ( V_68 -> V_113 . V_104 & 0x0ffffffffUL ) +
V_6 -> V_44 -> V_119 -> V_120 ;
#endif
break;
default:
return - V_46 ;
}
return 0 ;
}
static void F_48 ( struct V_2 * V_3 , struct V_88 * V_68 )
{
}
static int F_49 ( struct V_121 * V_83 )
{
struct V_1 * V_6 = F_1 ( V_83 -> V_3 ) ;
struct V_122 * V_123 = ( void * ) V_83 ;
unsigned V_124 = 0 , V_125 ;
int V_11 ;
int V_126 = ! ( V_123 -> V_127 & V_128 ) ;
enum V_129 V_130 = V_126 ?
V_131 : V_132 ;
if ( V_133 -> V_134 != V_123 -> V_135 )
return - V_84 ;
if ( V_123 -> V_127 & V_136 ) {
unsigned long V_137 = V_123 -> V_138 + V_83 -> V_98 * V_101 ;
struct V_139 * V_140 ;
V_140 = F_50 ( V_123 -> V_135 , V_123 -> V_138 ) ;
if ( ! V_140 || V_140 -> V_141 || V_140 -> V_142 < V_137 )
return - V_84 ;
}
do {
unsigned V_98 = V_83 -> V_98 - V_124 ;
T_2 V_138 = V_123 -> V_138 + V_124 * V_101 ;
struct V_143 * * V_144 = V_83 -> V_144 + V_124 ;
V_11 = F_51 ( V_138 , V_98 , V_126 ? V_145 : 0 ,
V_144 , NULL ) ;
if ( V_11 < 0 )
goto V_146;
V_124 += V_11 ;
} while ( V_124 < V_83 -> V_98 );
V_11 = F_52 ( V_83 -> V_147 , V_83 -> V_144 , V_83 -> V_98 , 0 ,
V_83 -> V_98 << V_76 ,
V_148 ) ;
if ( V_11 )
goto V_149;
V_11 = - V_150 ;
V_125 = F_53 ( V_6 -> V_151 , V_83 -> V_147 -> V_152 , V_83 -> V_147 -> V_125 , V_130 ) ;
if ( V_125 != V_83 -> V_147 -> V_125 )
goto V_149;
F_54 ( V_83 -> V_147 , V_83 -> V_144 ,
V_123 -> V_83 . V_153 , V_83 -> V_98 ) ;
return 0 ;
V_149:
F_55 ( V_83 -> V_147 ) ;
V_146:
V_146 ( V_83 -> V_144 , V_124 , 0 ) ;
return V_11 ;
}
static void F_56 ( struct V_121 * V_83 )
{
struct V_1 * V_6 = F_1 ( V_83 -> V_3 ) ;
struct V_122 * V_123 = ( void * ) V_83 ;
struct V_154 V_155 ;
int V_126 = ! ( V_123 -> V_127 & V_128 ) ;
enum V_129 V_130 = V_126 ?
V_131 : V_132 ;
if ( ! V_83 -> V_147 -> V_152 )
return;
F_57 ( V_6 -> V_151 , V_83 -> V_147 -> V_152 , V_83 -> V_147 -> V_125 , V_130 ) ;
F_58 (ttm->sg->sgl, &sg_iter, ttm->sg->nents, 0 ) {
struct V_143 * V_143 = F_59 ( & V_155 ) ;
if ( ! ( V_123 -> V_127 & V_128 ) )
F_60 ( V_143 ) ;
F_61 ( V_143 ) ;
F_62 ( V_143 ) ;
}
F_63 ( V_83 -> V_147 ) ;
}
static int F_64 ( struct V_121 * V_83 ,
struct V_88 * V_156 )
{
struct V_122 * V_123 = ( void * ) V_83 ;
T_1 V_26 = V_157 | V_158 |
V_159 ;
int V_11 ;
if ( V_123 -> V_138 ) {
F_49 ( V_83 ) ;
V_26 &= ~ V_159 ;
}
V_123 -> V_115 = ( unsigned long ) ( V_156 -> V_75 << V_76 ) ;
if ( ! V_83 -> V_98 ) {
F_65 ( 1 , L_8 ,
V_83 -> V_98 , V_156 , V_83 ) ;
}
if ( V_83 -> V_160 == V_161 )
V_26 |= V_162 ;
V_11 = F_66 ( V_123 -> V_6 , V_123 -> V_115 , V_83 -> V_98 ,
V_83 -> V_144 , V_123 -> V_83 . V_153 , V_26 ) ;
if ( V_11 ) {
F_9 ( L_9 ,
V_83 -> V_98 , ( unsigned ) V_123 -> V_115 ) ;
return V_11 ;
}
return 0 ;
}
static int F_67 ( struct V_121 * V_83 )
{
struct V_122 * V_123 = ( void * ) V_83 ;
F_68 ( V_123 -> V_6 , V_123 -> V_115 , V_83 -> V_98 ) ;
if ( V_123 -> V_138 )
F_56 ( V_83 ) ;
return 0 ;
}
static void F_69 ( struct V_121 * V_83 )
{
struct V_122 * V_123 = ( void * ) V_83 ;
F_70 ( & V_123 -> V_83 ) ;
F_55 ( V_123 ) ;
}
static struct V_121 * F_71 ( struct V_2 * V_3 ,
unsigned long V_16 , T_1 V_163 ,
struct V_143 * V_164 )
{
struct V_1 * V_6 ;
struct V_122 * V_123 ;
V_6 = F_1 ( V_3 ) ;
#if F_14 ( V_42 )
if ( V_6 -> V_26 & V_43 ) {
return F_72 ( V_3 , V_6 -> V_44 -> V_45 -> V_165 ,
V_16 , V_163 , V_164 ) ;
}
#endif
V_123 = F_73 ( sizeof( struct V_122 ) , V_148 ) ;
if ( V_123 == NULL ) {
return NULL ;
}
V_123 -> V_83 . V_83 . V_36 = & V_166 ;
V_123 -> V_6 = V_6 ;
if ( F_74 ( & V_123 -> V_83 , V_3 , V_16 , V_163 , V_164 ) ) {
F_55 ( V_123 ) ;
return NULL ;
}
return & V_123 -> V_83 . V_83 ;
}
static struct V_122 * F_75 ( struct V_121 * V_83 )
{
if ( ! V_83 || V_83 -> V_36 != & V_166 )
return NULL ;
return (struct V_122 * ) V_83 ;
}
static int F_76 ( struct V_121 * V_83 )
{
struct V_122 * V_123 = F_75 ( V_83 ) ;
struct V_1 * V_6 ;
unsigned V_77 ;
int V_11 ;
bool V_167 = ! ! ( V_83 -> V_163 & V_168 ) ;
if ( V_83 -> V_169 != V_170 )
return 0 ;
if ( V_123 && V_123 -> V_138 ) {
V_83 -> V_147 = F_73 ( sizeof( struct V_171 ) , V_148 ) ;
if ( ! V_83 -> V_147 )
return - V_150 ;
V_83 -> V_163 |= V_168 ;
V_83 -> V_169 = V_172 ;
return 0 ;
}
if ( V_167 && V_83 -> V_147 ) {
F_54 ( V_83 -> V_147 , V_83 -> V_144 ,
V_123 -> V_83 . V_153 , V_83 -> V_98 ) ;
V_83 -> V_169 = V_172 ;
return 0 ;
}
V_6 = F_1 ( V_83 -> V_3 ) ;
#if F_14 ( V_42 )
if ( V_6 -> V_26 & V_43 ) {
return F_77 ( V_83 ) ;
}
#endif
#ifdef F_78
if ( F_79 () ) {
return F_80 ( & V_123 -> V_83 , V_6 -> V_151 ) ;
}
#endif
V_11 = F_81 ( V_83 ) ;
if ( V_11 ) {
return V_11 ;
}
for ( V_77 = 0 ; V_77 < V_83 -> V_98 ; V_77 ++ ) {
V_123 -> V_83 . V_153 [ V_77 ] = F_82 ( V_6 -> V_173 , V_83 -> V_144 [ V_77 ] ,
0 , V_101 ,
V_174 ) ;
if ( F_83 ( V_6 -> V_173 , V_123 -> V_83 . V_153 [ V_77 ] ) ) {
while ( V_77 -- ) {
F_84 ( V_6 -> V_173 , V_123 -> V_83 . V_153 [ V_77 ] ,
V_101 , V_174 ) ;
V_123 -> V_83 . V_153 [ V_77 ] = 0 ;
}
F_85 ( V_83 ) ;
return - V_175 ;
}
}
return 0 ;
}
static void F_86 ( struct V_121 * V_83 )
{
struct V_1 * V_6 ;
struct V_122 * V_123 = F_75 ( V_83 ) ;
unsigned V_77 ;
bool V_167 = ! ! ( V_83 -> V_163 & V_168 ) ;
if ( V_123 && V_123 -> V_138 ) {
F_55 ( V_83 -> V_147 ) ;
V_83 -> V_163 &= ~ V_168 ;
return;
}
if ( V_167 )
return;
V_6 = F_1 ( V_83 -> V_3 ) ;
#if F_14 ( V_42 )
if ( V_6 -> V_26 & V_43 ) {
F_87 ( V_83 ) ;
return;
}
#endif
#ifdef F_78
if ( F_79 () ) {
F_88 ( & V_123 -> V_83 , V_6 -> V_151 ) ;
return;
}
#endif
for ( V_77 = 0 ; V_77 < V_83 -> V_98 ; V_77 ++ ) {
if ( V_123 -> V_83 . V_153 [ V_77 ] ) {
F_84 ( V_6 -> V_173 , V_123 -> V_83 . V_153 [ V_77 ] ,
V_101 , V_174 ) ;
}
}
F_85 ( V_83 ) ;
}
int F_89 ( struct V_121 * V_83 , T_2 V_114 ,
T_1 V_26 )
{
struct V_122 * V_123 = F_75 ( V_83 ) ;
if ( V_123 == NULL )
return - V_46 ;
V_123 -> V_138 = V_114 ;
V_123 -> V_135 = V_133 -> V_134 ;
V_123 -> V_127 = V_26 ;
return 0 ;
}
bool F_20 ( struct V_121 * V_83 )
{
struct V_122 * V_123 = F_75 ( V_83 ) ;
if ( V_123 == NULL )
return false ;
return ! ! V_123 -> V_138 ;
}
bool F_90 ( struct V_121 * V_83 )
{
struct V_122 * V_123 = F_75 ( V_83 ) ;
if ( V_123 == NULL )
return false ;
return ! ! ( V_123 -> V_127 & V_128 ) ;
}
int F_91 ( struct V_1 * V_6 )
{
int V_11 ;
V_11 = F_7 ( V_6 ) ;
if ( V_11 ) {
return V_11 ;
}
V_11 = F_92 ( & V_6 -> V_5 . V_3 ,
V_6 -> V_5 . V_20 . V_8 . V_9 ,
& V_176 ,
V_6 -> V_44 -> V_177 -> V_178 ,
V_179 ,
V_6 -> V_180 ) ;
if ( V_11 ) {
F_9 ( L_10 , V_11 ) ;
return V_11 ;
}
V_6 -> V_5 . V_181 = true ;
V_11 = F_93 ( & V_6 -> V_5 . V_3 , V_50 ,
V_6 -> V_39 . V_74 >> V_76 ) ;
if ( V_11 ) {
F_9 ( L_11 ) ;
return V_11 ;
}
F_94 ( V_6 , V_6 -> V_39 . V_73 ) ;
V_11 = F_95 ( V_6 , 256 * 1024 , V_101 , true ,
V_78 , 0 , NULL ,
NULL , & V_6 -> V_182 ) ;
if ( V_11 ) {
return V_11 ;
}
V_11 = F_96 ( V_6 -> V_182 , false ) ;
if ( V_11 )
return V_11 ;
V_11 = F_97 ( V_6 -> V_182 , V_78 , NULL ) ;
F_98 ( V_6 -> V_182 ) ;
if ( V_11 ) {
F_99 ( & V_6 -> V_182 ) ;
return V_11 ;
}
F_100 ( L_12 ,
( unsigned ) ( V_6 -> V_39 . V_74 / ( 1024 * 1024 ) ) ) ;
V_11 = F_93 ( & V_6 -> V_5 . V_3 , V_35 ,
V_6 -> V_39 . V_183 >> V_76 ) ;
if ( V_11 ) {
F_9 ( L_13 ) ;
return V_11 ;
}
F_100 ( L_14 ,
( unsigned ) ( V_6 -> V_39 . V_183 / ( 1024 * 1024 ) ) ) ;
V_11 = F_101 ( V_6 ) ;
if ( V_11 ) {
F_9 ( L_15 ) ;
return V_11 ;
}
return 0 ;
}
void F_102 ( struct V_1 * V_6 )
{
int V_11 ;
if ( ! V_6 -> V_5 . V_181 )
return;
F_103 ( V_6 ) ;
if ( V_6 -> V_182 ) {
V_11 = F_96 ( V_6 -> V_182 , false ) ;
if ( V_11 == 0 ) {
F_104 ( V_6 -> V_182 ) ;
F_98 ( V_6 -> V_182 ) ;
}
F_99 ( & V_6 -> V_182 ) ;
}
F_105 ( & V_6 -> V_5 . V_3 , V_50 ) ;
F_105 ( & V_6 -> V_5 . V_3 , V_35 ) ;
F_106 ( & V_6 -> V_5 . V_3 ) ;
F_107 ( V_6 ) ;
F_11 ( V_6 ) ;
V_6 -> V_5 . V_181 = false ;
F_100 ( L_16 ) ;
}
void F_94 ( struct V_1 * V_6 , V_100 V_16 )
{
struct V_27 * V_28 ;
if ( ! V_6 -> V_5 . V_181 )
return;
V_28 = & V_6 -> V_5 . V_3 . V_28 [ V_50 ] ;
V_28 -> V_16 = V_16 >> V_76 ;
}
static int F_108 ( struct V_139 * V_140 , struct V_184 * V_185 )
{
struct V_53 * V_54 ;
struct V_1 * V_6 ;
int V_11 ;
V_54 = (struct V_53 * ) V_140 -> V_186 ;
if ( V_54 == NULL ) {
return V_187 ;
}
V_6 = F_1 ( V_54 -> V_3 ) ;
F_109 ( & V_6 -> V_188 . V_189 ) ;
V_11 = V_190 -> V_191 ( V_140 , V_185 ) ;
F_110 ( & V_6 -> V_188 . V_189 ) ;
return V_11 ;
}
int F_111 ( struct V_81 * V_82 , struct V_139 * V_140 )
{
struct V_192 * V_193 ;
struct V_1 * V_6 ;
int V_11 ;
if ( F_33 ( V_140 -> V_194 < V_179 ) ) {
return - V_46 ;
}
V_193 = V_82 -> V_87 ;
V_6 = V_193 -> V_195 -> V_151 -> V_196 ;
if ( V_6 == NULL ) {
return - V_46 ;
}
V_11 = F_112 ( V_82 , V_140 , & V_6 -> V_5 . V_3 ) ;
if ( F_33 ( V_11 != 0 ) ) {
return V_11 ;
}
if ( F_33 ( V_190 == NULL ) ) {
V_190 = V_140 -> V_197 ;
V_198 = * V_190 ;
V_198 . V_191 = & F_108 ;
}
V_140 -> V_197 = & V_198 ;
return 0 ;
}
static int F_113 ( struct V_199 * V_200 , void * V_201 )
{
struct V_202 * V_203 = (struct V_202 * ) V_200 -> V_204 ;
unsigned V_205 = * ( int * ) V_203 -> V_206 -> V_201 ;
struct V_207 * V_151 = V_203 -> V_195 -> V_151 ;
struct V_1 * V_6 = V_151 -> V_196 ;
struct V_208 * V_134 = (struct V_208 * ) V_6 -> V_5 . V_3 . V_28 [ V_205 ] . V_209 ;
int V_210 ;
struct V_23 * V_211 = V_6 -> V_5 . V_3 . V_211 ;
F_114 ( & V_211 -> V_212 ) ;
V_210 = F_115 ( V_200 , V_134 ) ;
F_116 ( & V_211 -> V_212 ) ;
return V_210 ;
}
static int F_117 ( struct V_213 * V_213 , struct V_81 * V_214 )
{
struct V_1 * V_6 = V_213 -> V_215 ;
F_118 ( V_213 , V_6 -> V_39 . V_216 ) ;
V_214 -> V_87 = V_213 -> V_215 ;
return 0 ;
}
static T_3 F_119 ( struct V_81 * V_217 , char T_4 * V_218 ,
T_5 V_16 , T_6 * V_219 )
{
struct V_1 * V_6 = V_217 -> V_87 ;
T_3 V_220 = 0 ;
int V_11 ;
if ( V_16 & 0x3 || * V_219 & 0x3 )
return - V_46 ;
while ( V_16 ) {
unsigned long V_26 ;
T_1 V_221 ;
if ( * V_219 >= V_6 -> V_39 . V_216 )
return V_220 ;
F_120 ( & V_6 -> V_222 , V_26 ) ;
F_121 ( V_223 , ( ( T_1 ) * V_219 ) | 0x80000000 ) ;
if ( V_6 -> V_224 >= V_225 )
F_121 ( V_226 , * V_219 >> 31 ) ;
V_221 = F_122 ( V_227 ) ;
F_123 ( & V_6 -> V_222 , V_26 ) ;
V_11 = F_124 ( V_221 , ( T_1 * ) V_218 ) ;
if ( V_11 )
return V_11 ;
V_220 += 4 ;
V_218 += 4 ;
* V_219 += 4 ;
V_16 -= 4 ;
}
return V_220 ;
}
static int F_125 ( struct V_213 * V_213 , struct V_81 * V_214 )
{
struct V_1 * V_6 = V_213 -> V_215 ;
F_118 ( V_213 , V_6 -> V_39 . V_183 ) ;
V_214 -> V_87 = V_213 -> V_215 ;
return 0 ;
}
static T_3 F_126 ( struct V_81 * V_217 , char T_4 * V_218 ,
T_5 V_16 , T_6 * V_219 )
{
struct V_1 * V_6 = V_217 -> V_87 ;
T_3 V_220 = 0 ;
int V_11 ;
while ( V_16 ) {
T_6 V_228 = * V_219 / V_101 ;
unsigned V_229 = * V_219 & ~ V_230 ;
T_5 V_231 = F_127 ( T_5 , V_16 , V_101 - V_229 ) ;
struct V_143 * V_143 ;
void * V_232 ;
if ( V_228 >= V_6 -> V_233 . V_234 )
return V_220 ;
V_143 = V_6 -> V_233 . V_144 [ V_228 ] ;
if ( V_143 ) {
V_232 = F_128 ( V_143 ) ;
V_232 += V_229 ;
V_11 = F_129 ( V_218 , V_232 , V_231 ) ;
F_130 ( V_6 -> V_233 . V_144 [ V_228 ] ) ;
} else
V_11 = F_131 ( V_218 , V_231 ) ;
if ( V_11 )
return - V_175 ;
V_220 += V_231 ;
V_218 += V_231 ;
* V_219 += V_231 ;
V_16 -= V_231 ;
}
return V_220 ;
}
static int F_101 ( struct V_1 * V_6 )
{
#if F_132 ( V_235 )
unsigned V_236 ;
struct V_237 * V_195 = V_6 -> V_44 -> V_238 ;
struct V_239 * V_240 , * V_241 = V_195 -> V_242 ;
V_240 = F_133 ( L_17 , V_243 | V_244 , V_241 ,
V_6 , & V_245 ) ;
if ( F_27 ( V_240 ) )
return F_28 ( V_240 ) ;
V_6 -> V_5 . V_246 = V_240 ;
V_240 = F_133 ( L_18 , V_243 | V_244 , V_241 ,
V_6 , & V_247 ) ;
if ( F_27 ( V_240 ) )
return F_28 ( V_240 ) ;
V_6 -> V_5 . V_123 = V_240 ;
V_236 = F_134 ( V_248 ) ;
#ifdef F_78
if ( ! F_79 () )
-- V_236 ;
#endif
return F_135 ( V_6 , V_248 , V_236 ) ;
#else
return 0 ;
#endif
}
static void F_103 ( struct V_1 * V_6 )
{
#if F_132 ( V_235 )
F_136 ( V_6 -> V_5 . V_246 ) ;
V_6 -> V_5 . V_246 = NULL ;
F_136 ( V_6 -> V_5 . V_123 ) ;
V_6 -> V_5 . V_123 = NULL ;
#endif
}
