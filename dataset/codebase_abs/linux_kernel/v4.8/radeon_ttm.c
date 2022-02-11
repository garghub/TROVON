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
return F_21 ( & V_63 -> V_85 . V_86 , V_82 ) ;
}
static void F_22 ( struct V_53 * V_54 ,
struct V_87 * V_88 )
{
struct V_87 * V_89 = & V_54 -> V_68 ;
F_23 ( V_89 -> V_90 != NULL ) ;
* V_89 = * V_88 ;
V_88 -> V_90 = NULL ;
}
static int F_24 ( struct V_53 * V_54 ,
bool V_91 , bool V_92 ,
struct V_87 * V_88 ,
struct V_87 * V_89 )
{
struct V_1 * V_6 ;
T_2 V_93 , V_94 ;
struct V_95 * V_96 ;
unsigned V_97 ;
int V_11 , V_98 ;
V_6 = F_1 ( V_54 -> V_3 ) ;
V_98 = F_17 ( V_6 ) ;
V_93 = ( V_99 ) V_89 -> V_75 << V_76 ;
V_94 = ( V_99 ) V_88 -> V_75 << V_76 ;
switch ( V_89 -> V_69 ) {
case V_50 :
V_93 += V_6 -> V_39 . V_51 ;
break;
case V_35 :
V_93 += V_6 -> V_39 . V_40 ;
break;
default:
F_9 ( L_6 , V_89 -> V_69 ) ;
return - V_46 ;
}
switch ( V_88 -> V_69 ) {
case V_50 :
V_94 += V_6 -> V_39 . V_51 ;
break;
case V_35 :
V_94 += V_6 -> V_39 . V_40 ;
break;
default:
F_9 ( L_6 , V_89 -> V_69 ) ;
return - V_46 ;
}
if ( ! V_6 -> V_70 [ V_98 ] . V_71 ) {
F_9 ( L_7 ) ;
return - V_46 ;
}
F_25 ( ( V_100 % V_101 ) != 0 ) ;
V_97 = V_88 -> V_97 * ( V_100 / V_101 ) ;
V_96 = F_26 ( V_6 , V_93 , V_94 , V_97 , V_54 -> V_102 ) ;
if ( F_27 ( V_96 ) )
return F_28 ( V_96 ) ;
V_11 = F_29 ( V_54 , & V_96 -> V_103 , V_91 , V_88 ) ;
F_30 ( & V_96 ) ;
return V_11 ;
}
static int F_31 ( struct V_53 * V_54 ,
bool V_91 , bool V_104 ,
bool V_92 ,
struct V_87 * V_88 )
{
struct V_1 * V_6 ;
struct V_87 * V_89 = & V_54 -> V_68 ;
struct V_87 V_105 ;
struct V_57 V_58 ;
struct V_55 V_56 ;
int V_11 ;
V_6 = F_1 ( V_54 -> V_3 ) ;
V_105 = * V_88 ;
V_105 . V_90 = NULL ;
V_56 . V_65 = 1 ;
V_56 . V_56 = & V_58 ;
V_56 . V_66 = 1 ;
V_56 . V_64 = & V_58 ;
V_58 . V_59 = 0 ;
V_58 . V_60 = 0 ;
V_58 . V_26 = V_32 | V_106 ;
V_11 = F_32 ( V_54 , & V_56 , & V_105 ,
V_104 , V_92 ) ;
if ( F_33 ( V_11 ) ) {
return V_11 ;
}
V_11 = F_34 ( V_54 -> V_83 , V_105 . V_56 ) ;
if ( F_33 ( V_11 ) ) {
goto V_107;
}
V_11 = F_35 ( V_54 -> V_83 , & V_105 ) ;
if ( F_33 ( V_11 ) ) {
goto V_107;
}
V_11 = F_24 ( V_54 , true , V_92 , & V_105 , V_89 ) ;
if ( F_33 ( V_11 ) ) {
goto V_107;
}
V_11 = F_36 ( V_54 , true , V_104 , V_92 , V_88 ) ;
V_107:
F_37 ( V_54 , & V_105 ) ;
return V_11 ;
}
static int F_38 ( struct V_53 * V_54 ,
bool V_91 , bool V_104 ,
bool V_92 ,
struct V_87 * V_88 )
{
struct V_1 * V_6 ;
struct V_87 * V_89 = & V_54 -> V_68 ;
struct V_87 V_105 ;
struct V_55 V_56 ;
struct V_57 V_58 ;
int V_11 ;
V_6 = F_1 ( V_54 -> V_3 ) ;
V_105 = * V_88 ;
V_105 . V_90 = NULL ;
V_56 . V_65 = 1 ;
V_56 . V_56 = & V_58 ;
V_56 . V_66 = 1 ;
V_56 . V_64 = & V_58 ;
V_58 . V_59 = 0 ;
V_58 . V_60 = 0 ;
V_58 . V_26 = V_32 | V_106 ;
V_11 = F_32 ( V_54 , & V_56 , & V_105 ,
V_104 , V_92 ) ;
if ( F_33 ( V_11 ) ) {
return V_11 ;
}
V_11 = F_36 ( V_54 , true , V_104 , V_92 , & V_105 ) ;
if ( F_33 ( V_11 ) ) {
goto V_107;
}
V_11 = F_24 ( V_54 , true , V_92 , V_88 , V_89 ) ;
if ( F_33 ( V_11 ) ) {
goto V_107;
}
V_107:
F_37 ( V_54 , & V_105 ) ;
return V_11 ;
}
static int F_39 ( struct V_53 * V_54 ,
bool V_91 , bool V_104 ,
bool V_92 ,
struct V_87 * V_88 )
{
struct V_1 * V_6 ;
struct V_62 * V_63 ;
struct V_87 * V_89 = & V_54 -> V_68 ;
int V_11 ;
V_11 = F_40 ( V_54 , V_104 , V_92 ) ;
if ( V_11 )
return V_11 ;
V_63 = F_2 ( V_54 , struct V_62 , V_67 ) ;
if ( F_41 ( V_63 -> V_108 > 0 ) )
return - V_46 ;
V_6 = F_1 ( V_54 -> V_3 ) ;
if ( V_89 -> V_69 == V_29 && V_54 -> V_83 == NULL ) {
F_22 ( V_54 , V_88 ) ;
return 0 ;
}
if ( ( V_89 -> V_69 == V_35 &&
V_88 -> V_69 == V_29 ) ||
( V_89 -> V_69 == V_29 &&
V_88 -> V_69 == V_35 ) ) {
F_22 ( V_54 , V_88 ) ;
return 0 ;
}
if ( ! V_6 -> V_70 [ F_17 ( V_6 ) ] . V_71 ||
V_6 -> V_109 -> V_110 . V_110 == NULL ) {
goto memcpy;
}
if ( V_89 -> V_69 == V_50 &&
V_88 -> V_69 == V_29 ) {
V_11 = F_31 ( V_54 , V_91 , V_104 ,
V_92 , V_88 ) ;
} else if ( V_89 -> V_69 == V_29 &&
V_88 -> V_69 == V_50 ) {
V_11 = F_38 ( V_54 , V_91 , V_104 ,
V_92 , V_88 ) ;
} else {
V_11 = F_24 ( V_54 , V_91 , V_92 , V_88 , V_89 ) ;
}
if ( V_11 ) {
memcpy:
V_11 = F_42 ( V_54 , V_91 , V_104 ,
V_92 , V_88 ) ;
if ( V_11 ) {
return V_11 ;
}
}
F_43 ( ( V_99 ) V_54 -> V_97 << V_76 , & V_6 -> V_111 ) ;
return 0 ;
}
static int F_44 ( struct V_2 * V_3 , struct V_87 * V_68 )
{
struct V_27 * V_28 = & V_3 -> V_28 [ V_68 -> V_69 ] ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
V_68 -> V_112 . V_113 = NULL ;
V_68 -> V_112 . V_114 = 0 ;
V_68 -> V_112 . V_16 = V_68 -> V_97 << V_76 ;
V_68 -> V_112 . V_103 = 0 ;
V_68 -> V_112 . V_115 = false ;
if ( ! ( V_28 -> V_26 & V_30 ) )
return - V_46 ;
switch ( V_68 -> V_69 ) {
case V_29 :
return 0 ;
case V_35 :
#if F_14 ( V_42 )
if ( V_6 -> V_26 & V_43 ) {
V_68 -> V_112 . V_114 = V_68 -> V_75 << V_76 ;
V_68 -> V_112 . V_103 = V_6 -> V_39 . V_116 ;
V_68 -> V_112 . V_115 = ! V_6 -> V_44 -> V_45 -> V_47 ;
}
#endif
break;
case V_50 :
V_68 -> V_112 . V_114 = V_68 -> V_75 << V_76 ;
if ( ( V_68 -> V_112 . V_114 + V_68 -> V_112 . V_16 ) > V_6 -> V_39 . V_73 )
return - V_46 ;
V_68 -> V_112 . V_103 = V_6 -> V_39 . V_117 ;
V_68 -> V_112 . V_115 = true ;
#ifdef F_45
if ( V_68 -> V_56 & V_49 )
V_68 -> V_112 . V_113 =
F_46 ( V_68 -> V_112 . V_103 + V_68 -> V_112 . V_114 ,
V_68 -> V_112 . V_16 ) ;
else
V_68 -> V_112 . V_113 =
F_47 ( V_68 -> V_112 . V_103 + V_68 -> V_112 . V_114 ,
V_68 -> V_112 . V_16 ) ;
V_68 -> V_112 . V_103 = ( V_68 -> V_112 . V_103 & 0x0ffffffffUL ) +
V_6 -> V_44 -> V_118 -> V_119 ;
#endif
break;
default:
return - V_46 ;
}
return 0 ;
}
static void F_48 ( struct V_2 * V_3 , struct V_87 * V_68 )
{
}
static int F_49 ( struct V_120 * V_83 )
{
struct V_1 * V_6 = F_1 ( V_83 -> V_3 ) ;
struct V_121 * V_122 = ( void * ) V_83 ;
unsigned V_123 = 0 , V_124 ;
int V_11 ;
int V_125 = ! ( V_122 -> V_126 & V_127 ) ;
enum V_128 V_129 = V_125 ?
V_130 : V_131 ;
if ( V_132 -> V_133 != V_122 -> V_134 )
return - V_84 ;
if ( V_122 -> V_126 & V_135 ) {
unsigned long V_136 = V_122 -> V_137 + V_83 -> V_97 * V_100 ;
struct V_138 * V_139 ;
V_139 = F_50 ( V_122 -> V_134 , V_122 -> V_137 ) ;
if ( ! V_139 || V_139 -> V_140 || V_139 -> V_141 < V_136 )
return - V_84 ;
}
do {
unsigned V_97 = V_83 -> V_97 - V_123 ;
T_2 V_137 = V_122 -> V_137 + V_123 * V_100 ;
struct V_142 * * V_143 = V_83 -> V_143 + V_123 ;
V_11 = F_51 ( V_137 , V_97 , V_125 , 0 , V_143 , NULL ) ;
if ( V_11 < 0 )
goto V_144;
V_123 += V_11 ;
} while ( V_123 < V_83 -> V_97 );
V_11 = F_52 ( V_83 -> V_145 , V_83 -> V_143 , V_83 -> V_97 , 0 ,
V_83 -> V_97 << V_76 ,
V_146 ) ;
if ( V_11 )
goto V_147;
V_11 = - V_148 ;
V_124 = F_53 ( V_6 -> V_149 , V_83 -> V_145 -> V_150 , V_83 -> V_145 -> V_124 , V_129 ) ;
if ( V_124 != V_83 -> V_145 -> V_124 )
goto V_147;
F_54 ( V_83 -> V_145 , V_83 -> V_143 ,
V_122 -> V_83 . V_151 , V_83 -> V_97 ) ;
return 0 ;
V_147:
F_55 ( V_83 -> V_145 ) ;
V_144:
V_144 ( V_83 -> V_143 , V_123 , 0 ) ;
return V_11 ;
}
static void F_56 ( struct V_120 * V_83 )
{
struct V_1 * V_6 = F_1 ( V_83 -> V_3 ) ;
struct V_121 * V_122 = ( void * ) V_83 ;
struct V_152 V_153 ;
int V_125 = ! ( V_122 -> V_126 & V_127 ) ;
enum V_128 V_129 = V_125 ?
V_130 : V_131 ;
if ( ! V_83 -> V_145 -> V_150 )
return;
F_57 ( V_6 -> V_149 , V_83 -> V_145 -> V_150 , V_83 -> V_145 -> V_124 , V_129 ) ;
F_58 (ttm->sg->sgl, &sg_iter, ttm->sg->nents, 0 ) {
struct V_142 * V_142 = F_59 ( & V_153 ) ;
if ( ! ( V_122 -> V_126 & V_127 ) )
F_60 ( V_142 ) ;
F_61 ( V_142 ) ;
F_62 ( V_142 ) ;
}
F_63 ( V_83 -> V_145 ) ;
}
static int F_64 ( struct V_120 * V_83 ,
struct V_87 * V_154 )
{
struct V_121 * V_122 = ( void * ) V_83 ;
T_1 V_26 = V_155 | V_156 |
V_157 ;
int V_11 ;
if ( V_122 -> V_137 ) {
F_49 ( V_83 ) ;
V_26 &= ~ V_157 ;
}
V_122 -> V_114 = ( unsigned long ) ( V_154 -> V_75 << V_76 ) ;
if ( ! V_83 -> V_97 ) {
F_65 ( 1 , L_8 ,
V_83 -> V_97 , V_154 , V_83 ) ;
}
if ( V_83 -> V_158 == V_159 )
V_26 |= V_160 ;
V_11 = F_66 ( V_122 -> V_6 , V_122 -> V_114 , V_83 -> V_97 ,
V_83 -> V_143 , V_122 -> V_83 . V_151 , V_26 ) ;
if ( V_11 ) {
F_9 ( L_9 ,
V_83 -> V_97 , ( unsigned ) V_122 -> V_114 ) ;
return V_11 ;
}
return 0 ;
}
static int F_67 ( struct V_120 * V_83 )
{
struct V_121 * V_122 = ( void * ) V_83 ;
F_68 ( V_122 -> V_6 , V_122 -> V_114 , V_83 -> V_97 ) ;
if ( V_122 -> V_137 )
F_56 ( V_83 ) ;
return 0 ;
}
static void F_69 ( struct V_120 * V_83 )
{
struct V_121 * V_122 = ( void * ) V_83 ;
F_70 ( & V_122 -> V_83 ) ;
F_55 ( V_122 ) ;
}
static struct V_120 * F_71 ( struct V_2 * V_3 ,
unsigned long V_16 , T_1 V_161 ,
struct V_142 * V_162 )
{
struct V_1 * V_6 ;
struct V_121 * V_122 ;
V_6 = F_1 ( V_3 ) ;
#if F_14 ( V_42 )
if ( V_6 -> V_26 & V_43 ) {
return F_72 ( V_3 , V_6 -> V_44 -> V_45 -> V_163 ,
V_16 , V_161 , V_162 ) ;
}
#endif
V_122 = F_73 ( sizeof( struct V_121 ) , V_146 ) ;
if ( V_122 == NULL ) {
return NULL ;
}
V_122 -> V_83 . V_83 . V_36 = & V_164 ;
V_122 -> V_6 = V_6 ;
if ( F_74 ( & V_122 -> V_83 , V_3 , V_16 , V_161 , V_162 ) ) {
F_55 ( V_122 ) ;
return NULL ;
}
return & V_122 -> V_83 . V_83 ;
}
static struct V_121 * F_75 ( struct V_120 * V_83 )
{
if ( ! V_83 || V_83 -> V_36 != & V_164 )
return NULL ;
return (struct V_121 * ) V_83 ;
}
static int F_76 ( struct V_120 * V_83 )
{
struct V_121 * V_122 = F_75 ( V_83 ) ;
struct V_1 * V_6 ;
unsigned V_77 ;
int V_11 ;
bool V_165 = ! ! ( V_83 -> V_161 & V_166 ) ;
if ( V_83 -> V_167 != V_168 )
return 0 ;
if ( V_122 && V_122 -> V_137 ) {
V_83 -> V_145 = F_73 ( sizeof( struct V_169 ) , V_146 ) ;
if ( ! V_83 -> V_145 )
return - V_148 ;
V_83 -> V_161 |= V_166 ;
V_83 -> V_167 = V_170 ;
return 0 ;
}
if ( V_165 && V_83 -> V_145 ) {
F_54 ( V_83 -> V_145 , V_83 -> V_143 ,
V_122 -> V_83 . V_151 , V_83 -> V_97 ) ;
V_83 -> V_167 = V_170 ;
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
return F_80 ( & V_122 -> V_83 , V_6 -> V_149 ) ;
}
#endif
V_11 = F_81 ( V_83 ) ;
if ( V_11 ) {
return V_11 ;
}
for ( V_77 = 0 ; V_77 < V_83 -> V_97 ; V_77 ++ ) {
V_122 -> V_83 . V_151 [ V_77 ] = F_82 ( V_6 -> V_171 , V_83 -> V_143 [ V_77 ] ,
0 , V_100 ,
V_172 ) ;
if ( F_83 ( V_6 -> V_171 , V_122 -> V_83 . V_151 [ V_77 ] ) ) {
while ( V_77 -- ) {
F_84 ( V_6 -> V_171 , V_122 -> V_83 . V_151 [ V_77 ] ,
V_100 , V_172 ) ;
V_122 -> V_83 . V_151 [ V_77 ] = 0 ;
}
F_85 ( V_83 ) ;
return - V_173 ;
}
}
return 0 ;
}
static void F_86 ( struct V_120 * V_83 )
{
struct V_1 * V_6 ;
struct V_121 * V_122 = F_75 ( V_83 ) ;
unsigned V_77 ;
bool V_165 = ! ! ( V_83 -> V_161 & V_166 ) ;
if ( V_122 && V_122 -> V_137 ) {
F_55 ( V_83 -> V_145 ) ;
V_83 -> V_161 &= ~ V_166 ;
return;
}
if ( V_165 )
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
F_88 ( & V_122 -> V_83 , V_6 -> V_149 ) ;
return;
}
#endif
for ( V_77 = 0 ; V_77 < V_83 -> V_97 ; V_77 ++ ) {
if ( V_122 -> V_83 . V_151 [ V_77 ] ) {
F_84 ( V_6 -> V_171 , V_122 -> V_83 . V_151 [ V_77 ] ,
V_100 , V_172 ) ;
}
}
F_85 ( V_83 ) ;
}
int F_89 ( struct V_120 * V_83 , T_2 V_113 ,
T_1 V_26 )
{
struct V_121 * V_122 = F_75 ( V_83 ) ;
if ( V_122 == NULL )
return - V_46 ;
V_122 -> V_137 = V_113 ;
V_122 -> V_134 = V_132 -> V_133 ;
V_122 -> V_126 = V_26 ;
return 0 ;
}
bool F_20 ( struct V_120 * V_83 )
{
struct V_121 * V_122 = F_75 ( V_83 ) ;
if ( V_122 == NULL )
return false ;
return ! ! V_122 -> V_137 ;
}
bool F_90 ( struct V_120 * V_83 )
{
struct V_121 * V_122 = F_75 ( V_83 ) ;
if ( V_122 == NULL )
return false ;
return ! ! ( V_122 -> V_126 & V_127 ) ;
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
& V_174 ,
V_6 -> V_44 -> V_175 -> V_176 ,
V_177 ,
V_6 -> V_178 ) ;
if ( V_11 ) {
F_9 ( L_10 , V_11 ) ;
return V_11 ;
}
V_6 -> V_5 . V_179 = true ;
V_11 = F_93 ( & V_6 -> V_5 . V_3 , V_50 ,
V_6 -> V_39 . V_74 >> V_76 ) ;
if ( V_11 ) {
F_9 ( L_11 ) ;
return V_11 ;
}
F_94 ( V_6 , V_6 -> V_39 . V_73 ) ;
V_11 = F_95 ( V_6 , 256 * 1024 , V_100 , true ,
V_78 , 0 , NULL ,
NULL , & V_6 -> V_180 ) ;
if ( V_11 ) {
return V_11 ;
}
V_11 = F_96 ( V_6 -> V_180 , false ) ;
if ( V_11 )
return V_11 ;
V_11 = F_97 ( V_6 -> V_180 , V_78 , NULL ) ;
F_98 ( V_6 -> V_180 ) ;
if ( V_11 ) {
F_99 ( & V_6 -> V_180 ) ;
return V_11 ;
}
F_100 ( L_12 ,
( unsigned ) ( V_6 -> V_39 . V_74 / ( 1024 * 1024 ) ) ) ;
V_11 = F_93 ( & V_6 -> V_5 . V_3 , V_35 ,
V_6 -> V_39 . V_181 >> V_76 ) ;
if ( V_11 ) {
F_9 ( L_13 ) ;
return V_11 ;
}
F_100 ( L_14 ,
( unsigned ) ( V_6 -> V_39 . V_181 / ( 1024 * 1024 ) ) ) ;
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
if ( ! V_6 -> V_5 . V_179 )
return;
F_103 ( V_6 ) ;
if ( V_6 -> V_180 ) {
V_11 = F_96 ( V_6 -> V_180 , false ) ;
if ( V_11 == 0 ) {
F_104 ( V_6 -> V_180 ) ;
F_98 ( V_6 -> V_180 ) ;
}
F_99 ( & V_6 -> V_180 ) ;
}
F_105 ( & V_6 -> V_5 . V_3 , V_50 ) ;
F_105 ( & V_6 -> V_5 . V_3 , V_35 ) ;
F_106 ( & V_6 -> V_5 . V_3 ) ;
F_107 ( V_6 ) ;
F_11 ( V_6 ) ;
V_6 -> V_5 . V_179 = false ;
F_100 ( L_16 ) ;
}
void F_94 ( struct V_1 * V_6 , V_99 V_16 )
{
struct V_27 * V_28 ;
if ( ! V_6 -> V_5 . V_179 )
return;
V_28 = & V_6 -> V_5 . V_3 . V_28 [ V_50 ] ;
V_28 -> V_16 = V_16 >> V_76 ;
}
static int F_108 ( struct V_138 * V_139 , struct V_182 * V_183 )
{
struct V_53 * V_54 ;
struct V_1 * V_6 ;
int V_11 ;
V_54 = (struct V_53 * ) V_139 -> V_184 ;
if ( V_54 == NULL ) {
return V_185 ;
}
V_6 = F_1 ( V_54 -> V_3 ) ;
F_109 ( & V_6 -> V_186 . V_187 ) ;
V_11 = V_188 -> V_189 ( V_139 , V_183 ) ;
F_110 ( & V_6 -> V_186 . V_187 ) ;
return V_11 ;
}
int F_111 ( struct V_81 * V_82 , struct V_138 * V_139 )
{
struct V_190 * V_191 ;
struct V_1 * V_6 ;
int V_11 ;
if ( F_33 ( V_139 -> V_192 < V_177 ) ) {
return - V_46 ;
}
V_191 = V_82 -> V_193 ;
V_6 = V_191 -> V_194 -> V_149 -> V_195 ;
if ( V_6 == NULL ) {
return - V_46 ;
}
V_11 = F_112 ( V_82 , V_139 , & V_6 -> V_5 . V_3 ) ;
if ( F_33 ( V_11 != 0 ) ) {
return V_11 ;
}
if ( F_33 ( V_188 == NULL ) ) {
V_188 = V_139 -> V_196 ;
V_197 = * V_188 ;
V_197 . V_189 = & F_108 ;
}
V_139 -> V_196 = & V_197 ;
return 0 ;
}
static int F_113 ( struct V_198 * V_199 , void * V_200 )
{
struct V_201 * V_202 = (struct V_201 * ) V_199 -> V_203 ;
unsigned V_204 = * ( int * ) V_202 -> V_205 -> V_200 ;
struct V_206 * V_149 = V_202 -> V_194 -> V_149 ;
struct V_1 * V_6 = V_149 -> V_195 ;
struct V_207 * V_133 = (struct V_207 * ) V_6 -> V_5 . V_3 . V_28 [ V_204 ] . V_208 ;
int V_209 ;
struct V_23 * V_210 = V_6 -> V_5 . V_3 . V_210 ;
F_114 ( & V_210 -> V_211 ) ;
V_209 = F_115 ( V_199 , V_133 ) ;
F_116 ( & V_210 -> V_211 ) ;
return V_209 ;
}
static int F_117 ( struct V_212 * V_212 , struct V_81 * V_213 )
{
struct V_1 * V_6 = V_212 -> V_214 ;
F_118 ( V_212 , V_6 -> V_39 . V_215 ) ;
V_213 -> V_193 = V_212 -> V_214 ;
return 0 ;
}
static T_3 F_119 ( struct V_81 * V_216 , char T_4 * V_217 ,
T_5 V_16 , T_6 * V_218 )
{
struct V_1 * V_6 = V_216 -> V_193 ;
T_3 V_219 = 0 ;
int V_11 ;
if ( V_16 & 0x3 || * V_218 & 0x3 )
return - V_46 ;
while ( V_16 ) {
unsigned long V_26 ;
T_1 V_220 ;
if ( * V_218 >= V_6 -> V_39 . V_215 )
return V_219 ;
F_120 ( & V_6 -> V_221 , V_26 ) ;
F_121 ( V_222 , ( ( T_1 ) * V_218 ) | 0x80000000 ) ;
if ( V_6 -> V_223 >= V_224 )
F_121 ( V_225 , * V_218 >> 31 ) ;
V_220 = F_122 ( V_226 ) ;
F_123 ( & V_6 -> V_221 , V_26 ) ;
V_11 = F_124 ( V_220 , ( T_1 * ) V_217 ) ;
if ( V_11 )
return V_11 ;
V_219 += 4 ;
V_217 += 4 ;
* V_218 += 4 ;
V_16 -= 4 ;
}
return V_219 ;
}
static int F_125 ( struct V_212 * V_212 , struct V_81 * V_213 )
{
struct V_1 * V_6 = V_212 -> V_214 ;
F_118 ( V_212 , V_6 -> V_39 . V_181 ) ;
V_213 -> V_193 = V_212 -> V_214 ;
return 0 ;
}
static T_3 F_126 ( struct V_81 * V_216 , char T_4 * V_217 ,
T_5 V_16 , T_6 * V_218 )
{
struct V_1 * V_6 = V_216 -> V_193 ;
T_3 V_219 = 0 ;
int V_11 ;
while ( V_16 ) {
T_6 V_227 = * V_218 / V_100 ;
unsigned V_228 = * V_218 & ~ V_229 ;
T_5 V_230 = F_127 ( T_5 , V_16 , V_100 - V_228 ) ;
struct V_142 * V_142 ;
void * V_231 ;
if ( V_227 >= V_6 -> V_232 . V_233 )
return V_219 ;
V_142 = V_6 -> V_232 . V_143 [ V_227 ] ;
if ( V_142 ) {
V_231 = F_128 ( V_142 ) ;
V_231 += V_228 ;
V_11 = F_129 ( V_217 , V_231 , V_230 ) ;
F_130 ( V_6 -> V_232 . V_143 [ V_227 ] ) ;
} else
V_11 = F_131 ( V_217 , V_230 ) ;
if ( V_11 )
return - V_173 ;
V_219 += V_230 ;
V_217 += V_230 ;
* V_218 += V_230 ;
V_16 -= V_230 ;
}
return V_219 ;
}
static int F_101 ( struct V_1 * V_6 )
{
#if F_132 ( V_234 )
unsigned V_235 ;
struct V_236 * V_194 = V_6 -> V_44 -> V_237 ;
struct V_238 * V_239 , * V_240 = V_194 -> V_241 ;
V_239 = F_133 ( L_17 , V_242 | V_243 , V_240 ,
V_6 , & V_244 ) ;
if ( F_27 ( V_239 ) )
return F_28 ( V_239 ) ;
V_6 -> V_5 . V_245 = V_239 ;
V_239 = F_133 ( L_18 , V_242 | V_243 , V_240 ,
V_6 , & V_246 ) ;
if ( F_27 ( V_239 ) )
return F_28 ( V_239 ) ;
V_6 -> V_5 . V_122 = V_239 ;
V_235 = F_134 ( V_247 ) ;
#ifdef F_78
if ( ! F_79 () )
-- V_235 ;
#endif
return F_135 ( V_6 , V_247 , V_235 ) ;
#else
return 0 ;
#endif
}
static void F_103 ( struct V_1 * V_6 )
{
#if F_132 ( V_234 )
F_136 ( V_6 -> V_5 . V_245 ) ;
V_6 -> V_5 . V_245 = NULL ;
F_136 ( V_6 -> V_5 . V_122 ) ;
V_6 -> V_5 . V_122 = NULL ;
#endif
}
