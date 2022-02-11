static struct V_1 * F_1 ( unsigned int V_2 )
{
unsigned int V_3 = sizeof( struct V_4 ) + V_2 ;
struct V_1 * V_5 = NULL ;
struct V_6 * V_7 , * V_8 ;
unsigned int V_9 ;
unsigned int V_10 , V_11 = - 1 ;
F_2 ( & V_12 ) ;
V_10 = 0 ;
while ( V_10 < V_13 ) {
V_7 = & V_14 [ V_10 ] ;
if ( ! V_7 -> V_5 && V_11 == - 1 )
V_11 = V_10 ;
else if ( V_7 -> V_15 == V_3 ) {
V_5 = V_7 -> V_5 ;
V_7 -> V_16 ++ ;
break;
}
V_10 ++ ;
}
if ( V_5 )
goto V_17;
if ( V_13 == V_18 && V_11 == - 1 ) {
V_9 = V_18 << 1 ;
V_8 = F_3 ( V_14 ,
V_9 * sizeof( struct V_6 ) ,
V_19 ) ;
if ( ! V_8 )
goto V_17;
V_18 = V_9 ;
V_14 = V_8 ;
}
if ( V_11 == - 1 )
V_11 = V_13 ++ ;
V_7 = & V_14 [ V_11 ] ;
snprintf ( V_7 -> V_20 , sizeof( V_7 -> V_20 ) , L_1 , V_11 ) ;
V_5 = F_4 ( V_7 -> V_20 , V_3 , V_21 ,
V_22 , NULL ) ;
if ( ! V_5 )
goto V_17;
V_7 -> V_5 = V_5 ;
V_7 -> V_16 = 1 ;
V_7 -> V_15 = V_3 ;
V_17:
F_5 ( & V_12 ) ;
return V_5 ;
}
static void F_6 ( struct V_23 * V_24 )
{
struct V_6 * V_7 = NULL ;
unsigned int V_10 ;
F_2 ( & V_12 ) ;
for ( V_10 = 0 ; V_10 < V_13 ; V_10 ++ ) {
if ( V_24 -> V_6 == V_14 [ V_10 ] . V_5 ) {
V_7 = & V_14 [ V_10 ] ;
break;
}
}
if ( F_7 ( ! V_7 , V_25 L_2 ) )
goto V_26;
F_8 ( ! V_7 -> V_16 ) ;
if ( -- V_7 -> V_16 )
goto V_26;
F_9 ( V_7 -> V_5 ) ;
V_7 -> V_5 = NULL ;
V_26:
F_5 ( & V_12 ) ;
}
unsigned int F_10 ( unsigned short V_27 )
{
return V_28 [ V_27 ] . V_29 ;
}
void F_11 ( T_1 * V_30 , struct V_31 * V_32 , unsigned int V_27 )
{
F_12 ( V_27 >= V_33 ) ;
if ( V_27 == V_34 )
F_13 ( V_32 , V_30 ) ;
else {
struct V_35 * V_36 = V_28 + V_27 ;
F_14 ( V_36 -> V_5 , V_32 ) ;
}
}
struct V_31 * F_15 ( T_2 V_37 , int V_38 , unsigned long * V_27 ,
T_1 * V_30 )
{
struct V_31 * V_39 ;
switch ( V_38 ) {
case 1 :
* V_27 = 0 ;
break;
case 2 ... 4 :
* V_27 = 1 ;
break;
case 5 ... 16 :
* V_27 = 2 ;
break;
case 17 ... 64 :
* V_27 = 3 ;
break;
case 65 ... 128 :
* V_27 = 4 ;
break;
case 129 ... V_40 :
* V_27 = 5 ;
break;
default:
return NULL ;
}
if ( * V_27 == V_34 ) {
V_41:
V_39 = F_16 ( V_30 , V_37 ) ;
} else {
struct V_35 * V_36 = V_28 + * V_27 ;
T_2 V_42 = V_37 & ~ ( V_43 | V_44 ) ;
V_42 |= V_45 | V_46 | V_47 ;
V_39 = F_17 ( V_36 -> V_5 , V_42 ) ;
if ( F_18 ( ! V_39 && ( V_37 & V_43 ) ) ) {
* V_27 = V_34 ;
goto V_41;
}
}
return V_39 ;
}
static void F_19 ( struct V_4 * V_4 )
{
F_20 ( V_4 ) ;
if ( F_21 ( V_4 ) )
F_22 ( V_4 ) ;
}
static void F_23 ( struct V_4 * V_4 )
{
struct V_23 * V_24 = V_4 -> V_48 ;
void * V_49 ;
F_19 ( V_4 ) ;
if ( V_24 ) {
if ( F_24 ( V_4 , V_50 ) )
F_11 ( V_24 -> V_51 , V_4 -> V_52 , F_25 ( V_4 ) ) ;
V_49 = V_4 ;
V_49 -= V_24 -> V_53 ;
F_13 ( V_49 , V_24 -> V_54 ) ;
} else {
F_26 ( V_4 ) ;
}
}
void F_27 ( struct V_4 * V_4 )
{
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_55 = 1 << V_56 ;
F_28 ( & V_4 -> V_57 , 1 ) ;
F_28 ( & V_4 -> V_58 , 1 ) ;
}
void F_29 ( struct V_4 * V_4 )
{
unsigned long V_59 = V_4 -> V_55 & ( ~ 0UL << V_60 ) ;
F_19 ( V_4 ) ;
memset ( V_4 , 0 , V_61 ) ;
V_4 -> V_55 = V_59 | ( 1 << V_56 ) ;
F_28 ( & V_4 -> V_57 , 1 ) ;
}
static void F_30 ( struct V_4 * V_4 , int error )
{
F_31 ( V_4 -> V_62 , error ) ;
F_32 ( V_4 ) ;
}
static inline void F_33 ( struct V_4 * V_4 )
{
V_4 -> V_55 |= ( 1 << V_63 ) ;
F_34 () ;
F_35 ( & V_4 -> V_57 ) ;
}
void F_36 ( struct V_4 * V_4 , struct V_4 * V_64 )
{
F_37 ( V_4 -> V_62 || V_4 -> V_65 ) ;
V_4 -> V_62 = V_64 ;
V_4 -> V_65 = F_30 ;
F_33 ( V_64 ) ;
}
static void F_38 ( struct V_66 * V_67 )
{
struct V_23 * V_24 = F_39 ( V_67 , struct V_23 , V_68 ) ;
struct V_4 * V_4 ;
while ( 1 ) {
F_40 ( & V_24 -> V_69 ) ;
V_4 = F_41 ( & V_24 -> V_70 ) ;
F_42 ( & V_24 -> V_69 ) ;
if ( ! V_4 )
break;
F_43 ( V_4 ) ;
}
}
static void F_44 ( struct V_23 * V_24 )
{
struct V_71 V_72 , V_73 ;
struct V_4 * V_4 ;
F_45 ( & V_72 ) ;
F_45 ( & V_73 ) ;
while ( ( V_4 = F_41 ( V_74 -> V_71 ) ) )
F_46 ( V_4 -> V_48 == V_24 ? & V_72 : & V_73 , V_4 ) ;
* V_74 -> V_71 = V_73 ;
F_40 ( & V_24 -> V_69 ) ;
F_47 ( & V_24 -> V_70 , & V_72 ) ;
F_42 ( & V_24 -> V_69 ) ;
F_48 ( V_24 -> V_75 , & V_24 -> V_68 ) ;
}
struct V_4 * F_49 ( T_2 V_37 , int V_76 , struct V_23 * V_24 )
{
T_2 V_77 = V_37 ;
unsigned V_53 ;
unsigned V_78 ;
unsigned long V_27 = V_79 ;
struct V_31 * V_39 = NULL ;
struct V_4 * V_4 ;
void * V_49 ;
if ( ! V_24 ) {
if ( V_76 > V_80 )
return NULL ;
V_49 = F_50 ( sizeof( struct V_4 ) +
V_76 * sizeof( struct V_31 ) ,
V_37 ) ;
V_53 = 0 ;
V_78 = V_76 ;
} else {
if ( F_51 ( ! V_24 -> V_51 && V_76 > 0 ) )
return NULL ;
if ( V_74 -> V_71 && ! F_52 ( V_74 -> V_71 ) )
V_37 &= ~ V_43 ;
V_49 = F_16 ( V_24 -> V_54 , V_37 ) ;
if ( ! V_49 && V_37 != V_77 ) {
F_44 ( V_24 ) ;
V_37 = V_77 ;
V_49 = F_16 ( V_24 -> V_54 , V_37 ) ;
}
V_53 = V_24 -> V_53 ;
V_78 = V_81 ;
}
if ( F_18 ( ! V_49 ) )
return NULL ;
V_4 = V_49 + V_53 ;
F_27 ( V_4 ) ;
if ( V_76 > V_78 ) {
V_39 = F_15 ( V_37 , V_76 , & V_27 , V_24 -> V_51 ) ;
if ( ! V_39 && V_37 != V_77 ) {
F_44 ( V_24 ) ;
V_37 = V_77 ;
V_39 = F_15 ( V_37 , V_76 , & V_27 , V_24 -> V_51 ) ;
}
if ( F_18 ( ! V_39 ) )
goto V_82;
V_4 -> V_55 |= 1 << V_50 ;
} else if ( V_76 ) {
V_39 = V_4 -> V_83 ;
}
V_4 -> V_48 = V_24 ;
V_4 -> V_55 |= V_27 << V_84 ;
V_4 -> V_85 = V_76 ;
V_4 -> V_52 = V_39 ;
return V_4 ;
V_82:
F_13 ( V_49 , V_24 -> V_54 ) ;
return NULL ;
}
void F_53 ( struct V_4 * V_4 )
{
unsigned long V_59 ;
struct V_31 V_32 ;
struct V_86 V_87 ;
F_54 (bv, bio, iter) {
char * V_88 = F_55 ( & V_32 , & V_59 ) ;
memset ( V_88 , 0 , V_32 . V_89 ) ;
F_56 ( V_32 . V_90 ) ;
F_57 ( V_88 , & V_59 ) ;
}
}
void F_32 ( struct V_4 * V_4 )
{
if ( ! F_24 ( V_4 , V_91 ) )
F_23 ( V_4 ) ;
else {
F_12 ( ! F_58 ( & V_4 -> V_58 ) ) ;
if ( F_59 ( & V_4 -> V_58 ) )
F_23 ( V_4 ) ;
}
}
inline int F_60 ( struct V_92 * V_93 , struct V_4 * V_4 )
{
if ( F_18 ( ! F_24 ( V_4 , V_94 ) ) )
F_61 ( V_93 , V_4 ) ;
return V_4 -> V_95 ;
}
void F_62 ( struct V_4 * V_4 , struct V_4 * V_96 )
{
F_37 ( V_4 -> V_48 && F_25 ( V_4 ) != V_79 ) ;
V_4 -> V_97 = V_96 -> V_97 ;
V_4 -> V_55 |= 1 << V_98 ;
V_4 -> V_99 = V_96 -> V_99 ;
V_4 -> V_100 = V_96 -> V_100 ;
V_4 -> V_52 = V_96 -> V_52 ;
}
struct V_4 * F_63 ( struct V_4 * V_4 , T_2 V_37 , struct V_23 * V_24 )
{
struct V_4 * V_101 ;
V_101 = F_49 ( V_37 , 0 , V_24 ) ;
if ( ! V_101 )
return NULL ;
F_62 ( V_101 , V_4 ) ;
if ( F_21 ( V_4 ) ) {
int V_102 ;
V_102 = F_64 ( V_101 , V_4 , V_37 ) ;
if ( V_102 < 0 ) {
F_32 ( V_101 ) ;
return NULL ;
}
}
return V_101 ;
}
struct V_4 * F_65 ( struct V_4 * V_96 , T_2 V_37 ,
struct V_23 * V_24 )
{
struct V_86 V_87 ;
struct V_31 V_32 ;
struct V_4 * V_4 ;
V_4 = F_49 ( V_37 , F_66 ( V_96 ) , V_24 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_97 = V_96 -> V_97 ;
V_4 -> V_99 = V_96 -> V_99 ;
V_4 -> V_100 . V_103 = V_96 -> V_100 . V_103 ;
V_4 -> V_100 . V_104 = V_96 -> V_100 . V_104 ;
if ( V_4 -> V_99 & V_105 )
goto V_106;
if ( V_4 -> V_99 & V_107 ) {
V_4 -> V_52 [ V_4 -> V_108 ++ ] = V_96 -> V_52 [ 0 ] ;
goto V_106;
}
F_54 (bv, bio_src, iter)
V_4 -> V_52 [ V_4 -> V_108 ++ ] = V_32 ;
V_106:
if ( F_21 ( V_96 ) ) {
int V_102 ;
V_102 = F_64 ( V_4 , V_96 , V_37 ) ;
if ( V_102 < 0 ) {
F_32 ( V_4 ) ;
return NULL ;
}
}
return V_4 ;
}
int F_67 ( struct V_109 * V_110 )
{
struct V_92 * V_93 = F_68 ( V_110 ) ;
int V_111 ;
V_111 = F_69 ( unsigned ,
F_70 ( V_93 ) ,
F_71 ( V_93 ) / ( V_112 >> 9 ) + 1 ) ;
return F_69 ( unsigned , V_111 , V_40 ) ;
}
static int F_72 ( struct V_92 * V_93 , struct V_4 * V_4 , struct V_113
* V_113 , unsigned int V_114 , unsigned int V_115 ,
unsigned int V_116 )
{
int V_117 = 0 ;
struct V_31 * V_118 ;
if ( F_18 ( F_24 ( V_4 , V_98 ) ) )
return 0 ;
if ( ( ( V_4 -> V_100 . V_104 + V_114 ) >> 9 ) > V_116 )
return 0 ;
if ( V_4 -> V_108 > 0 ) {
struct V_31 * V_119 = & V_4 -> V_52 [ V_4 -> V_108 - 1 ] ;
if ( V_113 == V_119 -> V_90 &&
V_115 == V_119 -> V_120 + V_119 -> V_89 ) {
unsigned int V_121 = V_119 -> V_89 ;
V_119 -> V_89 += V_114 ;
if ( V_93 -> V_122 ) {
struct V_123 V_124 = {
. V_97 = V_4 -> V_97 ,
. V_103 = V_4 -> V_100 . V_103 ,
. V_104 = V_4 -> V_100 . V_104 -
V_121 ,
. V_99 = V_4 -> V_99 ,
} ;
if ( V_93 -> V_122 ( V_93 , & V_124 , V_119 ) < V_119 -> V_89 ) {
V_119 -> V_89 -= V_114 ;
return 0 ;
}
}
V_4 -> V_100 . V_104 += V_114 ;
goto V_125;
}
if ( V_93 -> V_126 & ( 1 << V_127 ) &&
F_73 ( V_119 , V_115 ) )
return 0 ;
}
if ( V_4 -> V_108 >= V_4 -> V_85 )
return 0 ;
V_118 = & V_4 -> V_52 [ V_4 -> V_108 ] ;
V_118 -> V_90 = V_113 ;
V_118 -> V_89 = V_114 ;
V_118 -> V_120 = V_115 ;
V_4 -> V_108 ++ ;
V_4 -> V_95 ++ ;
V_4 -> V_100 . V_104 += V_114 ;
while ( V_4 -> V_95 > F_70 ( V_93 ) ) {
if ( V_117 )
goto V_128;
V_117 = 1 ;
F_61 ( V_93 , V_4 ) ;
}
if ( V_93 -> V_122 ) {
struct V_123 V_124 = {
. V_97 = V_4 -> V_97 ,
. V_103 = V_4 -> V_100 . V_103 ,
. V_104 = V_4 -> V_100 . V_104 - V_114 ,
. V_99 = V_4 -> V_99 ,
} ;
if ( V_93 -> V_122 ( V_93 , & V_124 , V_118 ) < V_118 -> V_89 )
goto V_128;
}
if ( V_4 -> V_108 > 1 && ( F_74 ( V_118 - 1 , V_118 ) ) )
V_4 -> V_55 &= ~ ( 1 << V_94 ) ;
V_125:
return V_114 ;
V_128:
V_118 -> V_90 = NULL ;
V_118 -> V_89 = 0 ;
V_118 -> V_120 = 0 ;
V_4 -> V_108 -- ;
V_4 -> V_100 . V_104 -= V_114 ;
F_61 ( V_93 , V_4 ) ;
return 0 ;
}
int F_75 ( struct V_92 * V_93 , struct V_4 * V_4 , struct V_113 * V_113 ,
unsigned int V_114 , unsigned int V_115 )
{
return F_72 ( V_93 , V_4 , V_113 , V_114 , V_115 ,
F_76 ( V_93 ) ) ;
}
int F_77 ( struct V_4 * V_4 , struct V_113 * V_113 , unsigned int V_114 ,
unsigned int V_115 )
{
struct V_92 * V_93 = F_68 ( V_4 -> V_97 ) ;
unsigned int V_116 ;
V_116 = F_78 ( V_93 , V_4 -> V_100 . V_103 ) ;
if ( ( V_116 < ( V_114 >> 9 ) ) && ! V_4 -> V_100 . V_104 )
V_116 = V_114 >> 9 ;
return F_72 ( V_93 , V_4 , V_113 , V_114 , V_115 , V_116 ) ;
}
static void F_79 ( struct V_4 * V_4 , int error )
{
struct V_129 * V_102 = V_4 -> V_62 ;
V_102 -> error = error ;
F_80 ( & V_102 -> V_130 ) ;
}
int F_81 ( int V_131 , struct V_4 * V_4 )
{
struct V_129 V_102 ;
V_131 |= V_132 ;
F_82 ( & V_102 . V_130 ) ;
V_4 -> V_62 = & V_102 ;
V_4 -> V_65 = F_79 ;
F_83 ( V_131 , V_4 ) ;
F_84 ( & V_102 . V_130 ) ;
return V_102 . error ;
}
void F_85 ( struct V_4 * V_4 , unsigned V_133 )
{
if ( F_21 ( V_4 ) )
F_86 ( V_4 , V_133 ) ;
F_87 ( V_4 , & V_4 -> V_100 , V_133 ) ;
}
int F_88 ( struct V_4 * V_4 , T_2 V_37 )
{
int V_10 ;
struct V_31 * V_32 ;
F_89 (bv, bio, i) {
V_32 -> V_90 = F_90 ( V_37 ) ;
if ( ! V_32 -> V_90 ) {
while ( -- V_32 >= V_4 -> V_52 )
F_91 ( V_32 -> V_90 ) ;
return - V_134 ;
}
}
return 0 ;
}
void F_92 ( struct V_4 * V_135 , struct V_4 * V_136 )
{
struct V_86 V_137 , V_138 ;
struct V_31 V_139 , V_140 ;
void * V_141 , * V_142 ;
unsigned V_133 ;
V_137 = V_136 -> V_100 ;
V_138 = V_135 -> V_100 ;
while ( 1 ) {
if ( ! V_137 . V_104 ) {
V_136 = V_136 -> V_143 ;
if ( ! V_136 )
break;
V_137 = V_136 -> V_100 ;
}
if ( ! V_138 . V_104 ) {
V_135 = V_135 -> V_143 ;
if ( ! V_135 )
break;
V_138 = V_135 -> V_100 ;
}
V_139 = F_93 ( V_136 , V_137 ) ;
V_140 = F_93 ( V_135 , V_138 ) ;
V_133 = F_94 ( V_139 . V_89 , V_140 . V_89 ) ;
V_141 = F_95 ( V_139 . V_90 ) ;
V_142 = F_95 ( V_140 . V_90 ) ;
memcpy ( V_142 + V_140 . V_120 ,
V_141 + V_139 . V_120 ,
V_133 ) ;
F_96 ( V_142 ) ;
F_96 ( V_141 ) ;
F_87 ( V_136 , & V_137 , V_133 ) ;
F_87 ( V_135 , & V_138 , V_133 ) ;
}
}
static struct V_144 * F_97 ( unsigned int V_145 ,
T_2 V_37 )
{
if ( V_145 > V_80 )
return NULL ;
return F_50 ( sizeof( struct V_144 ) +
sizeof( struct V_146 ) * V_145 , V_37 ) ;
}
static int F_98 ( struct V_4 * V_4 , struct V_147 V_87 )
{
int V_10 ;
struct V_31 * V_118 ;
F_89 (bvec, bio, i) {
T_3 V_102 ;
V_102 = F_99 ( V_118 -> V_90 ,
V_118 -> V_120 ,
V_118 -> V_89 ,
& V_87 ) ;
if ( ! F_100 ( & V_87 ) )
break;
if ( V_102 < V_118 -> V_89 )
return - V_148 ;
}
return 0 ;
}
static int F_101 ( struct V_4 * V_4 , struct V_147 V_87 )
{
int V_10 ;
struct V_31 * V_118 ;
F_89 (bvec, bio, i) {
T_3 V_102 ;
V_102 = F_102 ( V_118 -> V_90 ,
V_118 -> V_120 ,
V_118 -> V_89 ,
& V_87 ) ;
if ( ! F_100 ( & V_87 ) )
break;
if ( V_102 < V_118 -> V_89 )
return - V_148 ;
}
return 0 ;
}
static void F_103 ( struct V_4 * V_4 )
{
struct V_31 * V_118 ;
int V_10 ;
F_89 (bvec, bio, i)
F_91 ( V_118 -> V_90 ) ;
}
int F_104 ( struct V_4 * V_4 )
{
struct V_144 * V_149 = V_4 -> V_62 ;
int V_102 = 0 ;
if ( ! F_24 ( V_4 , V_150 ) ) {
if ( V_74 -> V_151 && F_105 ( V_4 ) == V_152 )
V_102 = F_101 ( V_4 , V_149 -> V_87 ) ;
if ( V_149 -> V_153 )
F_103 ( V_4 ) ;
}
F_26 ( V_149 ) ;
F_32 ( V_4 ) ;
return V_102 ;
}
struct V_4 * F_106 ( struct V_92 * V_93 ,
struct V_154 * V_155 ,
const struct V_147 * V_87 ,
T_2 V_37 )
{
struct V_144 * V_149 ;
struct V_113 * V_113 ;
struct V_4 * V_4 ;
int V_10 , V_102 ;
int V_111 = 0 ;
unsigned int V_114 = V_87 -> V_156 ;
unsigned int V_115 = V_155 ? V_155 -> V_115 & ~ V_157 : 0 ;
for ( V_10 = 0 ; V_10 < V_87 -> V_158 ; V_10 ++ ) {
unsigned long V_159 ;
unsigned long V_160 ;
unsigned long V_161 ;
V_159 = ( unsigned long ) V_87 -> V_162 [ V_10 ] . V_163 ;
V_160 = ( V_159 + V_87 -> V_162 [ V_10 ] . V_164 + V_112 - 1 )
>> V_165 ;
V_161 = V_159 >> V_165 ;
if ( V_160 < V_161 )
return F_107 ( - V_166 ) ;
V_111 += V_160 - V_161 ;
}
if ( V_115 )
V_111 ++ ;
V_149 = F_97 ( V_87 -> V_158 , V_37 ) ;
if ( ! V_149 )
return F_107 ( - V_134 ) ;
V_149 -> V_153 = V_155 ? 0 : 1 ;
memcpy ( V_149 -> V_162 , V_87 -> V_162 , sizeof( struct V_146 ) * V_87 -> V_158 ) ;
F_108 ( & V_149 -> V_87 , V_87 -> type , V_149 -> V_162 ,
V_87 -> V_158 , V_87 -> V_156 ) ;
V_102 = - V_134 ;
V_4 = F_109 ( V_37 , V_111 ) ;
if ( ! V_4 )
goto V_167;
if ( V_87 -> type & V_168 )
V_4 -> V_99 |= V_169 ;
V_102 = 0 ;
if ( V_155 ) {
V_111 = 1 << V_155 -> V_170 ;
V_10 = V_155 -> V_115 / V_112 ;
}
while ( V_114 ) {
unsigned int V_133 = V_112 ;
V_133 -= V_115 ;
if ( V_133 > V_114 )
V_133 = V_114 ;
if ( V_155 ) {
if ( V_10 == V_155 -> V_171 * V_111 ) {
V_102 = - V_134 ;
break;
}
V_113 = V_155 -> V_172 [ V_10 / V_111 ] ;
V_113 += ( V_10 % V_111 ) ;
V_10 ++ ;
} else {
V_113 = F_90 ( V_93 -> V_173 | V_37 ) ;
if ( ! V_113 ) {
V_102 = - V_134 ;
break;
}
}
if ( F_75 ( V_93 , V_4 , V_113 , V_133 , V_115 ) < V_133 )
break;
V_114 -= V_133 ;
V_115 = 0 ;
}
if ( V_102 )
goto V_174;
if ( ( ( V_87 -> type & V_168 ) && ( ! V_155 || ! V_155 -> V_175 ) ) ||
( V_155 && V_155 -> V_176 ) ) {
V_102 = F_98 ( V_4 , * V_87 ) ;
if ( V_102 )
goto V_174;
}
V_4 -> V_62 = V_149 ;
return V_4 ;
V_174:
if ( ! V_155 )
F_103 ( V_4 ) ;
F_32 ( V_4 ) ;
V_167:
F_26 ( V_149 ) ;
return F_107 ( V_102 ) ;
}
struct V_4 * F_110 ( struct V_92 * V_93 ,
const struct V_147 * V_87 ,
T_2 V_37 )
{
int V_177 ;
int V_111 = 0 ;
struct V_113 * * V_172 ;
struct V_4 * V_4 ;
int V_178 = 0 ;
int V_102 , V_115 ;
struct V_147 V_10 ;
struct V_146 V_162 ;
F_111 (iov, i, *iter) {
unsigned long V_159 = ( unsigned long ) V_162 . V_163 ;
unsigned long V_114 = V_162 . V_164 ;
unsigned long V_160 = ( V_159 + V_114 + V_112 - 1 ) >> V_165 ;
unsigned long V_161 = V_159 >> V_165 ;
if ( V_160 < V_161 )
return F_107 ( - V_166 ) ;
V_111 += V_160 - V_161 ;
if ( V_159 & F_112 ( V_93 ) )
return F_107 ( - V_166 ) ;
}
if ( ! V_111 )
return F_107 ( - V_166 ) ;
V_4 = F_109 ( V_37 , V_111 ) ;
if ( ! V_4 )
return F_107 ( - V_134 ) ;
V_102 = - V_134 ;
V_172 = F_113 ( V_111 , sizeof( struct V_113 * ) , V_37 ) ;
if ( ! V_172 )
goto V_26;
F_111 (iov, i, *iter) {
unsigned long V_159 = ( unsigned long ) V_162 . V_163 ;
unsigned long V_114 = V_162 . V_164 ;
unsigned long V_160 = ( V_159 + V_114 + V_112 - 1 ) >> V_165 ;
unsigned long V_161 = V_159 >> V_165 ;
const int V_179 = V_160 - V_161 ;
const int V_180 = V_178 + V_179 ;
V_102 = F_114 ( V_159 , V_179 ,
( V_87 -> type & V_168 ) != V_168 ,
& V_172 [ V_178 ] ) ;
if ( V_102 < V_179 ) {
V_102 = - V_148 ;
goto V_181;
}
V_115 = V_159 & ~ V_157 ;
for ( V_177 = V_178 ; V_177 < V_180 ; V_177 ++ ) {
unsigned int V_133 = V_112 - V_115 ;
if ( V_114 <= 0 )
break;
if ( V_133 > V_114 )
V_133 = V_114 ;
if ( F_75 ( V_93 , V_4 , V_172 [ V_177 ] , V_133 , V_115 ) <
V_133 )
break;
V_114 -= V_133 ;
V_115 = 0 ;
}
V_178 = V_177 ;
while ( V_177 < V_180 )
F_115 ( V_172 [ V_177 ++ ] ) ;
}
F_26 ( V_172 ) ;
if ( V_87 -> type & V_168 )
V_4 -> V_99 |= V_169 ;
V_4 -> V_55 |= ( 1 << V_182 ) ;
F_116 ( V_4 ) ;
return V_4 ;
V_181:
for ( V_177 = 0 ; V_177 < V_111 ; V_177 ++ ) {
if ( ! V_172 [ V_177 ] )
break;
F_115 ( V_172 [ V_177 ] ) ;
}
V_26:
F_26 ( V_172 ) ;
F_32 ( V_4 ) ;
return F_107 ( V_102 ) ;
}
static void F_117 ( struct V_4 * V_4 )
{
struct V_31 * V_118 ;
int V_10 ;
F_89 (bvec, bio, i) {
if ( F_105 ( V_4 ) == V_152 )
F_118 ( V_118 -> V_90 ) ;
F_115 ( V_118 -> V_90 ) ;
}
F_32 ( V_4 ) ;
}
void F_119 ( struct V_4 * V_4 )
{
F_117 ( V_4 ) ;
F_32 ( V_4 ) ;
}
static void F_120 ( struct V_4 * V_4 , int V_183 )
{
F_32 ( V_4 ) ;
}
struct V_4 * F_121 ( struct V_92 * V_93 , void * V_88 , unsigned int V_114 ,
T_2 V_37 )
{
unsigned long V_184 = ( unsigned long ) V_88 ;
unsigned long V_160 = ( V_184 + V_114 + V_112 - 1 ) >> V_165 ;
unsigned long V_161 = V_184 >> V_165 ;
const int V_111 = V_160 - V_161 ;
int V_115 , V_10 ;
struct V_4 * V_4 ;
V_4 = F_109 ( V_37 , V_111 ) ;
if ( ! V_4 )
return F_107 ( - V_134 ) ;
V_115 = F_122 ( V_184 ) ;
for ( V_10 = 0 ; V_10 < V_111 ; V_10 ++ ) {
unsigned int V_133 = V_112 - V_115 ;
if ( V_114 <= 0 )
break;
if ( V_133 > V_114 )
V_133 = V_114 ;
if ( F_75 ( V_93 , V_4 , F_123 ( V_88 ) , V_133 ,
V_115 ) < V_133 ) {
F_32 ( V_4 ) ;
return F_107 ( - V_166 ) ;
}
V_88 += V_133 ;
V_114 -= V_133 ;
V_115 = 0 ;
}
V_4 -> V_65 = F_120 ;
return V_4 ;
}
static void F_124 ( struct V_4 * V_4 , int V_183 )
{
F_103 ( V_4 ) ;
F_32 ( V_4 ) ;
}
static void F_125 ( struct V_4 * V_4 , int V_183 )
{
char * V_49 = V_4 -> V_62 ;
struct V_31 * V_118 ;
int V_10 ;
F_89 (bvec, bio, i) {
memcpy ( V_49 , F_126 ( V_118 -> V_90 ) , V_118 -> V_89 ) ;
V_49 += V_118 -> V_89 ;
}
F_124 ( V_4 , V_183 ) ;
}
struct V_4 * F_127 ( struct V_92 * V_93 , void * V_88 , unsigned int V_114 ,
T_2 V_37 , int V_185 )
{
unsigned long V_184 = ( unsigned long ) V_88 ;
unsigned long V_160 = ( V_184 + V_114 + V_112 - 1 ) >> V_165 ;
unsigned long V_161 = V_184 >> V_165 ;
struct V_4 * V_4 ;
void * V_49 = V_88 ;
int V_111 = 0 ;
if ( V_160 < V_161 )
return F_107 ( - V_166 ) ;
V_111 = V_160 - V_161 ;
V_4 = F_109 ( V_37 , V_111 ) ;
if ( ! V_4 )
return F_107 ( - V_134 ) ;
while ( V_114 ) {
struct V_113 * V_113 ;
unsigned int V_133 = V_112 ;
if ( V_133 > V_114 )
V_133 = V_114 ;
V_113 = F_90 ( V_93 -> V_173 | V_37 ) ;
if ( ! V_113 )
goto V_174;
if ( ! V_185 )
memcpy ( F_126 ( V_113 ) , V_49 , V_133 ) ;
if ( F_75 ( V_93 , V_4 , V_113 , V_133 , 0 ) < V_133 )
break;
V_114 -= V_133 ;
V_49 += V_133 ;
}
if ( V_185 ) {
V_4 -> V_65 = F_125 ;
V_4 -> V_62 = V_88 ;
} else {
V_4 -> V_65 = F_124 ;
V_4 -> V_99 |= V_169 ;
}
return V_4 ;
V_174:
F_103 ( V_4 ) ;
F_32 ( V_4 ) ;
return F_107 ( - V_134 ) ;
}
void F_128 ( struct V_4 * V_4 )
{
struct V_31 * V_118 ;
int V_10 ;
F_89 (bvec, bio, i) {
struct V_113 * V_113 = V_118 -> V_90 ;
if ( V_113 && ! F_129 ( V_113 ) )
F_118 ( V_113 ) ;
}
}
static void F_130 ( struct V_4 * V_4 )
{
struct V_31 * V_118 ;
int V_10 ;
F_89 (bvec, bio, i) {
struct V_113 * V_113 = V_118 -> V_90 ;
if ( V_113 )
F_131 ( V_113 ) ;
}
}
static void F_132 ( struct V_66 * V_67 )
{
unsigned long V_59 ;
struct V_4 * V_4 ;
F_133 ( & V_186 , V_59 ) ;
V_4 = V_187 ;
V_187 = NULL ;
F_134 ( & V_186 , V_59 ) ;
while ( V_4 ) {
struct V_4 * V_188 = V_4 -> V_62 ;
F_128 ( V_4 ) ;
F_130 ( V_4 ) ;
F_32 ( V_4 ) ;
V_4 = V_188 ;
}
}
void F_135 ( struct V_4 * V_4 )
{
struct V_31 * V_118 ;
int V_189 = 0 ;
int V_10 ;
F_89 (bvec, bio, i) {
struct V_113 * V_113 = V_118 -> V_90 ;
if ( F_136 ( V_113 ) || F_129 ( V_113 ) ) {
F_115 ( V_113 ) ;
V_118 -> V_90 = NULL ;
} else {
V_189 ++ ;
}
}
if ( V_189 ) {
unsigned long V_59 ;
F_133 ( & V_186 , V_59 ) ;
V_4 -> V_62 = V_187 ;
V_187 = V_4 ;
F_134 ( & V_186 , V_59 ) ;
F_137 ( & V_190 ) ;
} else {
F_32 ( V_4 ) ;
}
}
void F_138 ( int V_131 , unsigned long V_191 ,
struct V_192 * V_193 )
{
int V_194 = F_139 () ;
F_140 ( V_194 , V_193 ) ;
F_141 ( V_194 , V_193 , V_195 [ V_131 ] ) ;
F_142 ( V_194 , V_193 , V_191 [ V_131 ] , V_191 ) ;
F_143 ( V_193 , V_131 ) ;
F_144 () ;
}
void F_145 ( int V_131 , struct V_192 * V_193 ,
unsigned long V_196 )
{
unsigned long V_197 = V_198 - V_196 ;
int V_194 = F_139 () ;
F_142 ( V_194 , V_193 , V_199 [ V_131 ] , V_197 ) ;
F_140 ( V_194 , V_193 ) ;
F_146 ( V_193 , V_131 ) ;
F_144 () ;
}
void F_147 ( struct V_4 * V_200 )
{
struct V_31 V_118 ;
struct V_86 V_87 ;
F_54 (bvec, bi, iter)
F_56 ( V_118 . V_90 ) ;
}
static inline bool F_148 ( struct V_4 * V_4 )
{
if ( ! F_24 ( V_4 , V_63 ) )
return true ;
F_37 ( F_58 ( & V_4 -> V_57 ) <= 0 ) ;
if ( F_59 ( & V_4 -> V_57 ) ) {
F_149 ( V_63 , & V_4 -> V_55 ) ;
return true ;
}
return false ;
}
void F_31 ( struct V_4 * V_4 , int error )
{
while ( V_4 ) {
if ( error )
F_149 ( V_56 , & V_4 -> V_55 ) ;
else if ( ! F_150 ( V_56 , & V_4 -> V_55 ) )
error = - V_201 ;
if ( F_18 ( ! F_148 ( V_4 ) ) )
break;
if ( V_4 -> V_65 == F_30 ) {
struct V_4 * V_64 = V_4 -> V_62 ;
F_32 ( V_4 ) ;
V_4 = V_64 ;
} else {
if ( V_4 -> V_65 )
V_4 -> V_65 ( V_4 , error ) ;
V_4 = NULL ;
}
}
}
struct V_4 * F_151 ( struct V_4 * V_4 , int V_191 ,
T_2 V_202 , struct V_23 * V_24 )
{
struct V_4 * V_203 = NULL ;
F_37 ( V_191 <= 0 ) ;
F_37 ( V_191 >= F_152 ( V_4 ) ) ;
if ( V_4 -> V_99 & V_105 )
V_203 = F_65 ( V_4 , V_202 , V_24 ) ;
else
V_203 = F_63 ( V_4 , V_202 , V_24 ) ;
if ( ! V_203 )
return NULL ;
V_203 -> V_100 . V_104 = V_191 << 9 ;
if ( F_21 ( V_203 ) )
F_153 ( V_203 , 0 , V_191 ) ;
F_85 ( V_4 , V_203 -> V_100 . V_104 ) ;
return V_203 ;
}
void F_154 ( struct V_4 * V_4 , int V_115 , int V_204 )
{
V_204 <<= 9 ;
if ( V_115 == 0 && V_204 == V_4 -> V_100 . V_104 )
return;
F_149 ( V_94 , & V_4 -> V_55 ) ;
F_85 ( V_4 , V_115 << 9 ) ;
V_4 -> V_100 . V_104 = V_204 ;
}
T_1 * F_155 ( int V_205 )
{
struct V_35 * V_206 = V_28 + V_34 ;
return F_156 ( V_205 , V_206 -> V_5 ) ;
}
void F_157 ( struct V_23 * V_24 )
{
if ( V_24 -> V_75 )
F_158 ( V_24 -> V_75 ) ;
if ( V_24 -> V_54 )
F_159 ( V_24 -> V_54 ) ;
if ( V_24 -> V_51 )
F_159 ( V_24 -> V_51 ) ;
F_160 ( V_24 ) ;
F_6 ( V_24 ) ;
F_26 ( V_24 ) ;
}
static struct V_23 * F_161 ( unsigned int V_207 ,
unsigned int V_53 ,
bool V_208 )
{
unsigned int V_209 = V_81 * sizeof( struct V_31 ) ;
struct V_23 * V_24 ;
V_24 = F_162 ( sizeof( * V_24 ) , V_19 ) ;
if ( ! V_24 )
return NULL ;
V_24 -> V_53 = V_53 ;
F_163 ( & V_24 -> V_69 ) ;
F_45 ( & V_24 -> V_70 ) ;
F_164 ( & V_24 -> V_68 , F_38 ) ;
V_24 -> V_6 = F_1 ( V_53 + V_209 ) ;
if ( ! V_24 -> V_6 ) {
F_26 ( V_24 ) ;
return NULL ;
}
V_24 -> V_54 = F_156 ( V_207 , V_24 -> V_6 ) ;
if ( ! V_24 -> V_54 )
goto V_210;
if ( V_208 ) {
V_24 -> V_51 = F_155 ( V_207 ) ;
if ( ! V_24 -> V_51 )
goto V_210;
}
V_24 -> V_75 = F_165 ( L_3 , V_211 , 0 ) ;
if ( ! V_24 -> V_75 )
goto V_210;
return V_24 ;
V_210:
F_157 ( V_24 ) ;
return NULL ;
}
struct V_23 * F_166 ( unsigned int V_207 , unsigned int V_53 )
{
return F_161 ( V_207 , V_53 , true ) ;
}
struct V_23 * F_167 ( unsigned int V_207 , unsigned int V_53 )
{
return F_161 ( V_207 , V_53 , false ) ;
}
int F_168 ( struct V_4 * V_4 , struct V_212 * V_213 )
{
if ( F_18 ( V_4 -> V_214 ) )
return - V_215 ;
F_169 ( V_213 ) ;
V_4 -> V_214 = V_213 ;
return 0 ;
}
int F_170 ( struct V_4 * V_4 )
{
struct V_216 * V_217 ;
if ( V_4 -> V_214 )
return - V_215 ;
V_217 = V_74 -> V_216 ;
if ( ! V_217 )
return - V_218 ;
F_171 ( V_217 ) ;
V_4 -> V_219 = V_217 ;
V_4 -> V_214 = F_172 ( V_74 , V_220 ) ;
return 0 ;
}
void F_20 ( struct V_4 * V_4 )
{
if ( V_4 -> V_219 ) {
F_173 ( V_4 -> V_219 ) ;
V_4 -> V_219 = NULL ;
}
if ( V_4 -> V_214 ) {
F_174 ( V_4 -> V_214 ) ;
V_4 -> V_214 = NULL ;
}
}
static void T_4 F_175 ( void )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_33 ; V_10 ++ ) {
int V_204 ;
struct V_35 * V_36 = V_28 + V_10 ;
if ( V_36 -> V_29 <= V_81 ) {
V_36 -> V_5 = NULL ;
continue;
}
V_204 = V_36 -> V_29 * sizeof( struct V_31 ) ;
V_36 -> V_5 = F_4 ( V_36 -> V_20 , V_204 , 0 ,
V_22 | V_221 , NULL ) ;
}
}
static int T_4 F_176 ( void )
{
V_18 = 2 ;
V_13 = 0 ;
V_14 = F_162 ( V_18 * sizeof( struct V_6 ) , V_19 ) ;
if ( ! V_14 )
F_177 ( L_4 ) ;
F_178 () ;
F_175 () ;
V_222 = F_166 ( V_223 , 0 ) ;
if ( ! V_222 )
F_177 ( L_4 ) ;
if ( F_179 ( V_222 , V_223 ) )
F_177 ( L_5 ) ;
return 0 ;
}
