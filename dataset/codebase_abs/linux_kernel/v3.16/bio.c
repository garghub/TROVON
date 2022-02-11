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
V_5 = F_4 ( V_7 -> V_20 , V_3 , 0 , V_21 , NULL ) ;
if ( ! V_5 )
goto V_17;
V_7 -> V_5 = V_5 ;
V_7 -> V_16 = 1 ;
V_7 -> V_15 = V_3 ;
V_17:
F_5 ( & V_12 ) ;
return V_5 ;
}
static void F_6 ( struct V_22 * V_23 )
{
struct V_6 * V_7 = NULL ;
unsigned int V_10 ;
F_2 ( & V_12 ) ;
for ( V_10 = 0 ; V_10 < V_13 ; V_10 ++ ) {
if ( V_23 -> V_6 == V_14 [ V_10 ] . V_5 ) {
V_7 = & V_14 [ V_10 ] ;
break;
}
}
if ( F_7 ( ! V_7 , V_24 L_2 ) )
goto V_25;
F_8 ( ! V_7 -> V_16 ) ;
if ( -- V_7 -> V_16 )
goto V_25;
F_9 ( V_7 -> V_5 ) ;
V_7 -> V_5 = NULL ;
V_25:
F_5 ( & V_12 ) ;
}
unsigned int F_10 ( unsigned short V_26 )
{
return V_27 [ V_26 ] . V_28 ;
}
void F_11 ( T_1 * V_29 , struct V_30 * V_31 , unsigned int V_26 )
{
F_12 ( V_26 >= V_32 ) ;
if ( V_26 == V_33 )
F_13 ( V_31 , V_29 ) ;
else {
struct V_34 * V_35 = V_27 + V_26 ;
F_14 ( V_35 -> V_5 , V_31 ) ;
}
}
struct V_30 * F_15 ( T_2 V_36 , int V_37 , unsigned long * V_26 ,
T_1 * V_29 )
{
struct V_30 * V_38 ;
switch ( V_37 ) {
case 1 :
* V_26 = 0 ;
break;
case 2 ... 4 :
* V_26 = 1 ;
break;
case 5 ... 16 :
* V_26 = 2 ;
break;
case 17 ... 64 :
* V_26 = 3 ;
break;
case 65 ... 128 :
* V_26 = 4 ;
break;
case 129 ... V_39 :
* V_26 = 5 ;
break;
default:
return NULL ;
}
if ( * V_26 == V_33 ) {
V_40:
V_38 = F_16 ( V_29 , V_36 ) ;
} else {
struct V_34 * V_35 = V_27 + * V_26 ;
T_2 V_41 = V_36 & ~ ( V_42 | V_43 ) ;
V_41 |= V_44 | V_45 | V_46 ;
V_38 = F_17 ( V_35 -> V_5 , V_41 ) ;
if ( F_18 ( ! V_38 && ( V_36 & V_42 ) ) ) {
* V_26 = V_33 ;
goto V_40;
}
}
return V_38 ;
}
static void F_19 ( struct V_4 * V_4 )
{
F_20 ( V_4 ) ;
if ( F_21 ( V_4 ) )
F_22 ( V_4 ) ;
}
static void F_23 ( struct V_4 * V_4 )
{
struct V_22 * V_23 = V_4 -> V_47 ;
void * V_48 ;
F_19 ( V_4 ) ;
if ( V_23 ) {
if ( F_24 ( V_4 , V_49 ) )
F_11 ( V_23 -> V_50 , V_4 -> V_51 , F_25 ( V_4 ) ) ;
V_48 = V_4 ;
V_48 -= V_23 -> V_52 ;
F_13 ( V_48 , V_23 -> V_53 ) ;
} else {
F_26 ( V_4 ) ;
}
}
void F_27 ( struct V_4 * V_4 )
{
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_54 = 1 << V_55 ;
F_28 ( & V_4 -> V_56 , 1 ) ;
F_28 ( & V_4 -> V_57 , 1 ) ;
}
void F_29 ( struct V_4 * V_4 )
{
unsigned long V_58 = V_4 -> V_54 & ( ~ 0UL << V_59 ) ;
F_19 ( V_4 ) ;
memset ( V_4 , 0 , V_60 ) ;
V_4 -> V_54 = V_58 | ( 1 << V_55 ) ;
F_28 ( & V_4 -> V_56 , 1 ) ;
}
static void F_30 ( struct V_4 * V_4 , int error )
{
F_31 ( V_4 -> V_61 , error ) ;
F_32 ( V_4 ) ;
}
void F_33 ( struct V_4 * V_4 , struct V_4 * V_62 )
{
F_34 ( V_4 -> V_61 || V_4 -> V_63 ) ;
V_4 -> V_61 = V_62 ;
V_4 -> V_63 = F_30 ;
F_35 ( & V_62 -> V_56 ) ;
}
static void F_36 ( struct V_64 * V_65 )
{
struct V_22 * V_23 = F_37 ( V_65 , struct V_22 , V_66 ) ;
struct V_4 * V_4 ;
while ( 1 ) {
F_38 ( & V_23 -> V_67 ) ;
V_4 = F_39 ( & V_23 -> V_68 ) ;
F_40 ( & V_23 -> V_67 ) ;
if ( ! V_4 )
break;
F_41 ( V_4 ) ;
}
}
static void F_42 ( struct V_22 * V_23 )
{
struct V_69 V_70 , V_71 ;
struct V_4 * V_4 ;
F_43 ( & V_70 ) ;
F_43 ( & V_71 ) ;
while ( ( V_4 = F_39 ( V_72 -> V_69 ) ) )
F_44 ( V_4 -> V_47 == V_23 ? & V_70 : & V_71 , V_4 ) ;
* V_72 -> V_69 = V_71 ;
F_38 ( & V_23 -> V_67 ) ;
F_45 ( & V_23 -> V_68 , & V_70 ) ;
F_40 ( & V_23 -> V_67 ) ;
F_46 ( V_23 -> V_73 , & V_23 -> V_66 ) ;
}
struct V_4 * F_47 ( T_2 V_36 , int V_74 , struct V_22 * V_23 )
{
T_2 V_75 = V_36 ;
unsigned V_52 ;
unsigned V_76 ;
unsigned long V_26 = V_77 ;
struct V_30 * V_38 = NULL ;
struct V_4 * V_4 ;
void * V_48 ;
if ( ! V_23 ) {
if ( V_74 > V_78 )
return NULL ;
V_48 = F_48 ( sizeof( struct V_4 ) +
V_74 * sizeof( struct V_30 ) ,
V_36 ) ;
V_52 = 0 ;
V_76 = V_74 ;
} else {
if ( V_72 -> V_69 && ! F_49 ( V_72 -> V_69 ) )
V_36 &= ~ V_42 ;
V_48 = F_16 ( V_23 -> V_53 , V_36 ) ;
if ( ! V_48 && V_36 != V_75 ) {
F_42 ( V_23 ) ;
V_36 = V_75 ;
V_48 = F_16 ( V_23 -> V_53 , V_36 ) ;
}
V_52 = V_23 -> V_52 ;
V_76 = V_79 ;
}
if ( F_18 ( ! V_48 ) )
return NULL ;
V_4 = V_48 + V_52 ;
F_27 ( V_4 ) ;
if ( V_74 > V_76 ) {
V_38 = F_15 ( V_36 , V_74 , & V_26 , V_23 -> V_50 ) ;
if ( ! V_38 && V_36 != V_75 ) {
F_42 ( V_23 ) ;
V_36 = V_75 ;
V_38 = F_15 ( V_36 , V_74 , & V_26 , V_23 -> V_50 ) ;
}
if ( F_18 ( ! V_38 ) )
goto V_80;
V_4 -> V_54 |= 1 << V_49 ;
} else if ( V_74 ) {
V_38 = V_4 -> V_81 ;
}
V_4 -> V_47 = V_23 ;
V_4 -> V_54 |= V_26 << V_82 ;
V_4 -> V_83 = V_74 ;
V_4 -> V_51 = V_38 ;
return V_4 ;
V_80:
F_13 ( V_48 , V_23 -> V_53 ) ;
return NULL ;
}
void F_50 ( struct V_4 * V_4 )
{
unsigned long V_58 ;
struct V_30 V_31 ;
struct V_84 V_85 ;
F_51 (bv, bio, iter) {
char * V_86 = F_52 ( & V_31 , & V_58 ) ;
memset ( V_86 , 0 , V_31 . V_87 ) ;
F_53 ( V_31 . V_88 ) ;
F_54 ( V_86 , & V_58 ) ;
}
}
void F_32 ( struct V_4 * V_4 )
{
F_12 ( ! F_55 ( & V_4 -> V_57 ) ) ;
if ( F_56 ( & V_4 -> V_57 ) )
F_23 ( V_4 ) ;
}
inline int F_57 ( struct V_89 * V_90 , struct V_4 * V_4 )
{
if ( F_18 ( ! F_24 ( V_4 , V_91 ) ) )
F_58 ( V_90 , V_4 ) ;
return V_4 -> V_92 ;
}
void F_59 ( struct V_4 * V_4 , struct V_4 * V_93 )
{
F_34 ( V_4 -> V_47 && F_25 ( V_4 ) != V_77 ) ;
V_4 -> V_94 = V_93 -> V_94 ;
V_4 -> V_54 |= 1 << V_95 ;
V_4 -> V_96 = V_93 -> V_96 ;
V_4 -> V_97 = V_93 -> V_97 ;
V_4 -> V_51 = V_93 -> V_51 ;
}
struct V_4 * F_60 ( struct V_4 * V_4 , T_2 V_36 , struct V_22 * V_23 )
{
struct V_4 * V_98 ;
V_98 = F_47 ( V_36 , 0 , V_23 ) ;
if ( ! V_98 )
return NULL ;
F_59 ( V_98 , V_4 ) ;
if ( F_21 ( V_4 ) ) {
int V_99 ;
V_99 = F_61 ( V_98 , V_4 , V_36 ) ;
if ( V_99 < 0 ) {
F_32 ( V_98 ) ;
return NULL ;
}
}
return V_98 ;
}
struct V_4 * F_62 ( struct V_4 * V_93 , T_2 V_36 ,
struct V_22 * V_23 )
{
struct V_84 V_85 ;
struct V_30 V_31 ;
struct V_4 * V_4 ;
V_4 = F_47 ( V_36 , F_63 ( V_93 ) , V_23 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_94 = V_93 -> V_94 ;
V_4 -> V_96 = V_93 -> V_96 ;
V_4 -> V_97 . V_100 = V_93 -> V_97 . V_100 ;
V_4 -> V_97 . V_101 = V_93 -> V_97 . V_101 ;
if ( V_4 -> V_96 & V_102 )
goto V_103;
if ( V_4 -> V_96 & V_104 ) {
V_4 -> V_51 [ V_4 -> V_105 ++ ] = V_93 -> V_51 [ 0 ] ;
goto V_103;
}
F_51 (bv, bio_src, iter)
V_4 -> V_51 [ V_4 -> V_105 ++ ] = V_31 ;
V_103:
if ( F_21 ( V_93 ) ) {
int V_99 ;
V_99 = F_61 ( V_4 , V_93 , V_36 ) ;
if ( V_99 < 0 ) {
F_32 ( V_4 ) ;
return NULL ;
}
}
return V_4 ;
}
int F_64 ( struct V_106 * V_107 )
{
struct V_89 * V_90 = F_65 ( V_107 ) ;
int V_108 ;
V_108 = F_66 ( unsigned ,
F_67 ( V_90 ) ,
F_68 ( V_90 ) / ( V_109 >> 9 ) + 1 ) ;
return F_66 ( unsigned , V_108 , V_39 ) ;
}
static int F_69 ( struct V_89 * V_90 , struct V_4 * V_4 , struct V_110
* V_110 , unsigned int V_111 , unsigned int V_112 ,
unsigned int V_113 )
{
int V_114 = 0 ;
struct V_30 * V_115 ;
if ( F_18 ( F_24 ( V_4 , V_95 ) ) )
return 0 ;
if ( ( ( V_4 -> V_97 . V_101 + V_111 ) >> 9 ) > V_113 )
return 0 ;
if ( V_4 -> V_105 > 0 ) {
struct V_30 * V_116 = & V_4 -> V_51 [ V_4 -> V_105 - 1 ] ;
if ( V_110 == V_116 -> V_88 &&
V_112 == V_116 -> V_117 + V_116 -> V_87 ) {
unsigned int V_118 = V_116 -> V_87 ;
V_116 -> V_87 += V_111 ;
if ( V_90 -> V_119 ) {
struct V_120 V_121 = {
. V_94 = V_4 -> V_94 ,
. V_100 = V_4 -> V_97 . V_100 ,
. V_101 = V_4 -> V_97 . V_101 -
V_118 ,
. V_96 = V_4 -> V_96 ,
} ;
if ( V_90 -> V_119 ( V_90 , & V_121 , V_116 ) < V_116 -> V_87 ) {
V_116 -> V_87 -= V_111 ;
return 0 ;
}
}
goto V_122;
}
if ( V_90 -> V_123 & ( 1 << V_124 ) &&
F_70 ( V_116 , V_112 ) )
return 0 ;
}
if ( V_4 -> V_105 >= V_4 -> V_83 )
return 0 ;
while ( V_4 -> V_92 >= F_67 ( V_90 ) ) {
if ( V_114 )
return 0 ;
V_114 = 1 ;
F_58 ( V_90 , V_4 ) ;
}
V_115 = & V_4 -> V_51 [ V_4 -> V_105 ] ;
V_115 -> V_88 = V_110 ;
V_115 -> V_87 = V_111 ;
V_115 -> V_117 = V_112 ;
if ( V_90 -> V_119 ) {
struct V_120 V_121 = {
. V_94 = V_4 -> V_94 ,
. V_100 = V_4 -> V_97 . V_100 ,
. V_101 = V_4 -> V_97 . V_101 ,
. V_96 = V_4 -> V_96 ,
} ;
if ( V_90 -> V_119 ( V_90 , & V_121 , V_115 ) < V_115 -> V_87 ) {
V_115 -> V_88 = NULL ;
V_115 -> V_87 = 0 ;
V_115 -> V_117 = 0 ;
return 0 ;
}
}
if ( V_4 -> V_105 && ( F_71 ( V_115 - 1 , V_115 ) ) )
V_4 -> V_54 &= ~ ( 1 << V_91 ) ;
V_4 -> V_105 ++ ;
V_4 -> V_92 ++ ;
V_122:
V_4 -> V_97 . V_101 += V_111 ;
return V_111 ;
}
int F_72 ( struct V_89 * V_90 , struct V_4 * V_4 , struct V_110 * V_110 ,
unsigned int V_111 , unsigned int V_112 )
{
return F_69 ( V_90 , V_4 , V_110 , V_111 , V_112 ,
F_73 ( V_90 ) ) ;
}
int F_74 ( struct V_4 * V_4 , struct V_110 * V_110 , unsigned int V_111 ,
unsigned int V_112 )
{
struct V_89 * V_90 = F_65 ( V_4 -> V_94 ) ;
unsigned int V_113 ;
V_113 = F_75 ( V_90 , V_4 -> V_97 . V_100 ) ;
if ( ( V_113 < ( V_111 >> 9 ) ) && ! V_4 -> V_97 . V_101 )
V_113 = V_111 >> 9 ;
return F_69 ( V_90 , V_4 , V_110 , V_111 , V_112 , V_113 ) ;
}
static void F_76 ( struct V_4 * V_4 , int error )
{
struct V_125 * V_99 = V_4 -> V_61 ;
V_99 -> error = error ;
F_77 ( & V_99 -> V_126 ) ;
}
int F_78 ( int V_127 , struct V_4 * V_4 )
{
struct V_125 V_99 ;
V_127 |= V_128 ;
F_79 ( & V_99 . V_126 ) ;
V_4 -> V_61 = & V_99 ;
V_4 -> V_63 = F_76 ;
F_80 ( V_127 , V_4 ) ;
F_81 ( & V_99 . V_126 ) ;
return V_99 . error ;
}
void F_82 ( struct V_4 * V_4 , unsigned V_129 )
{
if ( F_21 ( V_4 ) )
F_83 ( V_4 , V_129 ) ;
F_84 ( V_4 , & V_4 -> V_97 , V_129 ) ;
}
int F_85 ( struct V_4 * V_4 , T_2 V_36 )
{
int V_10 ;
struct V_30 * V_31 ;
F_86 (bv, bio, i) {
V_31 -> V_88 = F_87 ( V_36 ) ;
if ( ! V_31 -> V_88 ) {
while ( -- V_31 >= V_4 -> V_51 )
F_88 ( V_31 -> V_88 ) ;
return - V_130 ;
}
}
return 0 ;
}
void F_89 ( struct V_4 * V_131 , struct V_4 * V_132 )
{
struct V_84 V_133 , V_134 ;
struct V_30 V_135 , V_136 ;
void * V_137 , * V_138 ;
unsigned V_129 ;
V_133 = V_132 -> V_97 ;
V_134 = V_131 -> V_97 ;
while ( 1 ) {
if ( ! V_133 . V_101 ) {
V_132 = V_132 -> V_139 ;
if ( ! V_132 )
break;
V_133 = V_132 -> V_97 ;
}
if ( ! V_134 . V_101 ) {
V_131 = V_131 -> V_139 ;
if ( ! V_131 )
break;
V_134 = V_131 -> V_97 ;
}
V_135 = F_90 ( V_132 , V_133 ) ;
V_136 = F_90 ( V_131 , V_134 ) ;
V_129 = F_91 ( V_135 . V_87 , V_136 . V_87 ) ;
V_137 = F_92 ( V_135 . V_88 ) ;
V_138 = F_92 ( V_136 . V_88 ) ;
memcpy ( V_138 + V_136 . V_117 ,
V_137 + V_135 . V_117 ,
V_129 ) ;
F_93 ( V_138 ) ;
F_93 ( V_137 ) ;
F_84 ( V_132 , & V_133 , V_129 ) ;
F_84 ( V_131 , & V_134 , V_129 ) ;
}
}
static void F_94 ( struct V_140 * V_141 , struct V_4 * V_4 ,
const struct V_142 * V_143 , int V_144 ,
int V_145 )
{
memcpy ( V_141 -> V_146 , V_143 , sizeof( struct V_142 ) * V_144 ) ;
V_141 -> V_147 = V_144 ;
V_141 -> V_145 = V_145 ;
V_4 -> V_61 = V_141 ;
}
static struct V_140 * F_95 ( unsigned int V_144 ,
T_2 V_36 )
{
if ( V_144 > V_78 )
return NULL ;
return F_48 ( sizeof( struct V_140 ) +
sizeof( struct V_142 ) * V_144 , V_36 ) ;
}
static int F_96 ( struct V_4 * V_4 , const struct V_142 * V_143 , int V_144 ,
int V_148 , int V_149 , int V_150 )
{
int V_99 = 0 , V_10 ;
struct V_30 * V_115 ;
int V_151 = 0 ;
unsigned int V_152 = 0 ;
F_86 (bvec, bio, i) {
char * V_153 = F_97 ( V_115 -> V_88 ) ;
unsigned int V_87 = V_115 -> V_87 ;
while ( V_87 && V_151 < V_144 ) {
unsigned int V_129 ;
char T_3 * V_154 ;
V_129 = F_66 (unsigned int,
iov[iov_idx].iov_len - iov_off, bv_len) ;
V_154 = V_143 [ V_151 ] . V_155 + V_152 ;
if ( ! V_99 ) {
if ( V_148 )
V_99 = F_98 ( V_154 , V_153 ,
V_129 ) ;
if ( V_149 )
V_99 = F_99 ( V_153 , V_154 ,
V_129 ) ;
if ( V_99 )
V_99 = - V_156 ;
}
V_87 -= V_129 ;
V_153 += V_129 ;
V_154 += V_129 ;
V_152 += V_129 ;
if ( V_143 [ V_151 ] . V_157 == V_152 ) {
V_151 ++ ;
V_152 = 0 ;
}
}
if ( V_150 )
F_88 ( V_115 -> V_88 ) ;
}
return V_99 ;
}
int F_100 ( struct V_4 * V_4 )
{
struct V_140 * V_141 = V_4 -> V_61 ;
struct V_30 * V_115 ;
int V_99 = 0 , V_10 ;
if ( ! F_24 ( V_4 , V_158 ) ) {
if ( V_72 -> V_159 )
V_99 = F_96 ( V_4 , V_141 -> V_146 , V_141 -> V_147 ,
F_101 ( V_4 ) == V_160 ,
0 , V_141 -> V_145 ) ;
else if ( V_141 -> V_145 )
F_86 (bvec, bio, i)
F_88 ( V_115 -> V_88 ) ;
}
F_26 ( V_141 ) ;
F_32 ( V_4 ) ;
return V_99 ;
}
struct V_4 * F_102 ( struct V_89 * V_90 ,
struct V_161 * V_162 ,
const struct V_142 * V_143 , int V_144 ,
int V_163 , T_2 V_36 )
{
struct V_140 * V_141 ;
struct V_30 * V_115 ;
struct V_110 * V_110 ;
struct V_4 * V_4 ;
int V_10 , V_99 ;
int V_108 = 0 ;
unsigned int V_111 = 0 ;
unsigned int V_112 = V_162 ? V_162 -> V_112 & ~ V_164 : 0 ;
for ( V_10 = 0 ; V_10 < V_144 ; V_10 ++ ) {
unsigned long V_165 ;
unsigned long V_166 ;
unsigned long V_167 ;
V_165 = ( unsigned long ) V_143 [ V_10 ] . V_155 ;
V_166 = ( V_165 + V_143 [ V_10 ] . V_157 + V_109 - 1 ) >> V_168 ;
V_167 = V_165 >> V_168 ;
if ( V_166 < V_167 )
return F_103 ( - V_169 ) ;
V_108 += V_166 - V_167 ;
V_111 += V_143 [ V_10 ] . V_157 ;
}
if ( V_112 )
V_108 ++ ;
V_141 = F_95 ( V_144 , V_36 ) ;
if ( ! V_141 )
return F_103 ( - V_130 ) ;
V_99 = - V_130 ;
V_4 = F_104 ( V_36 , V_108 ) ;
if ( ! V_4 )
goto V_170;
if ( ! V_163 )
V_4 -> V_96 |= V_171 ;
V_99 = 0 ;
if ( V_162 ) {
V_108 = 1 << V_162 -> V_172 ;
V_10 = V_162 -> V_112 / V_109 ;
}
while ( V_111 ) {
unsigned int V_129 = V_109 ;
V_129 -= V_112 ;
if ( V_129 > V_111 )
V_129 = V_111 ;
if ( V_162 ) {
if ( V_10 == V_162 -> V_173 * V_108 ) {
V_99 = - V_130 ;
break;
}
V_110 = V_162 -> V_174 [ V_10 / V_108 ] ;
V_110 += ( V_10 % V_108 ) ;
V_10 ++ ;
} else {
V_110 = F_87 ( V_90 -> V_175 | V_36 ) ;
if ( ! V_110 ) {
V_99 = - V_130 ;
break;
}
}
if ( F_72 ( V_90 , V_4 , V_110 , V_129 , V_112 ) < V_129 )
break;
V_111 -= V_129 ;
V_112 = 0 ;
}
if ( V_99 )
goto V_176;
if ( ( ! V_163 && ( ! V_162 || ! V_162 -> V_177 ) ) ||
( V_162 && V_162 -> V_149 ) ) {
V_99 = F_96 ( V_4 , V_143 , V_144 , 0 , 1 , 0 ) ;
if ( V_99 )
goto V_176;
}
F_94 ( V_141 , V_4 , V_143 , V_144 , V_162 ? 0 : 1 ) ;
return V_4 ;
V_176:
if ( ! V_162 )
F_86 (bvec, bio, i)
F_88 ( V_115 -> V_88 ) ;
F_32 ( V_4 ) ;
V_170:
F_26 ( V_141 ) ;
return F_103 ( V_99 ) ;
}
struct V_4 * F_105 ( struct V_89 * V_90 , struct V_161 * V_162 ,
unsigned long V_165 , unsigned int V_111 ,
int V_163 , T_2 V_36 )
{
struct V_142 V_143 ;
V_143 . V_155 = ( void T_3 * ) V_165 ;
V_143 . V_157 = V_111 ;
return F_102 ( V_90 , V_162 , & V_143 , 1 , V_163 , V_36 ) ;
}
static struct V_4 * F_106 ( struct V_89 * V_90 ,
struct V_106 * V_107 ,
const struct V_142 * V_143 , int V_144 ,
int V_163 , T_2 V_36 )
{
int V_10 , V_178 ;
int V_108 = 0 ;
struct V_110 * * V_174 ;
struct V_4 * V_4 ;
int V_179 = 0 ;
int V_99 , V_112 ;
for ( V_10 = 0 ; V_10 < V_144 ; V_10 ++ ) {
unsigned long V_165 = ( unsigned long ) V_143 [ V_10 ] . V_155 ;
unsigned long V_111 = V_143 [ V_10 ] . V_157 ;
unsigned long V_166 = ( V_165 + V_111 + V_109 - 1 ) >> V_168 ;
unsigned long V_167 = V_165 >> V_168 ;
if ( V_166 < V_167 )
return F_103 ( - V_169 ) ;
V_108 += V_166 - V_167 ;
if ( V_165 & F_107 ( V_90 ) )
return F_103 ( - V_169 ) ;
}
if ( ! V_108 )
return F_103 ( - V_169 ) ;
V_4 = F_104 ( V_36 , V_108 ) ;
if ( ! V_4 )
return F_103 ( - V_130 ) ;
V_99 = - V_130 ;
V_174 = F_108 ( V_108 , sizeof( struct V_110 * ) , V_36 ) ;
if ( ! V_174 )
goto V_25;
for ( V_10 = 0 ; V_10 < V_144 ; V_10 ++ ) {
unsigned long V_165 = ( unsigned long ) V_143 [ V_10 ] . V_155 ;
unsigned long V_111 = V_143 [ V_10 ] . V_157 ;
unsigned long V_166 = ( V_165 + V_111 + V_109 - 1 ) >> V_168 ;
unsigned long V_167 = V_165 >> V_168 ;
const int V_180 = V_166 - V_167 ;
const int V_181 = V_179 + V_180 ;
V_99 = F_109 ( V_165 , V_180 ,
V_163 , & V_174 [ V_179 ] ) ;
if ( V_99 < V_180 ) {
V_99 = - V_156 ;
goto V_182;
}
V_112 = V_165 & ~ V_164 ;
for ( V_178 = V_179 ; V_178 < V_181 ; V_178 ++ ) {
unsigned int V_129 = V_109 - V_112 ;
if ( V_111 <= 0 )
break;
if ( V_129 > V_111 )
V_129 = V_111 ;
if ( F_72 ( V_90 , V_4 , V_174 [ V_178 ] , V_129 , V_112 ) <
V_129 )
break;
V_111 -= V_129 ;
V_112 = 0 ;
}
V_179 = V_178 ;
while ( V_178 < V_181 )
F_110 ( V_174 [ V_178 ++ ] ) ;
}
F_26 ( V_174 ) ;
if ( ! V_163 )
V_4 -> V_96 |= V_171 ;
V_4 -> V_94 = V_107 ;
V_4 -> V_54 |= ( 1 << V_183 ) ;
return V_4 ;
V_182:
for ( V_10 = 0 ; V_10 < V_108 ; V_10 ++ ) {
if( ! V_174 [ V_10 ] )
break;
F_110 ( V_174 [ V_10 ] ) ;
}
V_25:
F_26 ( V_174 ) ;
F_32 ( V_4 ) ;
return F_103 ( V_99 ) ;
}
struct V_4 * F_111 ( struct V_89 * V_90 , struct V_106 * V_107 ,
unsigned long V_165 , unsigned int V_111 , int V_163 ,
T_2 V_36 )
{
struct V_142 V_143 ;
V_143 . V_155 = ( void T_3 * ) V_165 ;
V_143 . V_157 = V_111 ;
return F_112 ( V_90 , V_107 , & V_143 , 1 , V_163 , V_36 ) ;
}
struct V_4 * F_112 ( struct V_89 * V_90 , struct V_106 * V_107 ,
const struct V_142 * V_143 , int V_144 ,
int V_163 , T_2 V_36 )
{
struct V_4 * V_4 ;
V_4 = F_106 ( V_90 , V_107 , V_143 , V_144 , V_163 ,
V_36 ) ;
if ( F_113 ( V_4 ) )
return V_4 ;
F_114 ( V_4 ) ;
return V_4 ;
}
static void F_115 ( struct V_4 * V_4 )
{
struct V_30 * V_115 ;
int V_10 ;
F_86 (bvec, bio, i) {
if ( F_101 ( V_4 ) == V_160 )
F_116 ( V_115 -> V_88 ) ;
F_110 ( V_115 -> V_88 ) ;
}
F_32 ( V_4 ) ;
}
void F_117 ( struct V_4 * V_4 )
{
F_115 ( V_4 ) ;
F_32 ( V_4 ) ;
}
static void F_118 ( struct V_4 * V_4 , int V_184 )
{
F_32 ( V_4 ) ;
}
static struct V_4 * F_119 ( struct V_89 * V_90 , void * V_86 ,
unsigned int V_111 , T_2 V_36 )
{
unsigned long V_185 = ( unsigned long ) V_86 ;
unsigned long V_166 = ( V_185 + V_111 + V_109 - 1 ) >> V_168 ;
unsigned long V_167 = V_185 >> V_168 ;
const int V_108 = V_166 - V_167 ;
int V_112 , V_10 ;
struct V_4 * V_4 ;
V_4 = F_104 ( V_36 , V_108 ) ;
if ( ! V_4 )
return F_103 ( - V_130 ) ;
V_112 = F_120 ( V_185 ) ;
for ( V_10 = 0 ; V_10 < V_108 ; V_10 ++ ) {
unsigned int V_129 = V_109 - V_112 ;
if ( V_111 <= 0 )
break;
if ( V_129 > V_111 )
V_129 = V_111 ;
if ( F_72 ( V_90 , V_4 , F_121 ( V_86 ) , V_129 ,
V_112 ) < V_129 )
break;
V_86 += V_129 ;
V_111 -= V_129 ;
V_112 = 0 ;
}
V_4 -> V_63 = F_118 ;
return V_4 ;
}
struct V_4 * F_122 ( struct V_89 * V_90 , void * V_86 , unsigned int V_111 ,
T_2 V_36 )
{
struct V_4 * V_4 ;
V_4 = F_119 ( V_90 , V_86 , V_111 , V_36 ) ;
if ( F_113 ( V_4 ) )
return V_4 ;
if ( V_4 -> V_97 . V_101 == V_111 )
return V_4 ;
F_32 ( V_4 ) ;
return F_103 ( - V_169 ) ;
}
static void F_123 ( struct V_4 * V_4 , int V_184 )
{
struct V_30 * V_115 ;
const int V_186 = F_101 ( V_4 ) == V_160 ;
struct V_140 * V_141 = V_4 -> V_61 ;
int V_10 ;
char * V_48 = V_141 -> V_146 [ 0 ] . V_155 ;
F_86 (bvec, bio, i) {
char * V_187 = F_97 ( V_115 -> V_88 ) ;
if ( V_186 )
memcpy ( V_48 , V_187 , V_115 -> V_87 ) ;
F_88 ( V_115 -> V_88 ) ;
V_48 += V_115 -> V_87 ;
}
F_26 ( V_141 ) ;
F_32 ( V_4 ) ;
}
struct V_4 * F_124 ( struct V_89 * V_90 , void * V_86 , unsigned int V_111 ,
T_2 V_36 , int V_188 )
{
struct V_4 * V_4 ;
struct V_30 * V_115 ;
int V_10 ;
V_4 = F_105 ( V_90 , NULL , ( unsigned long ) V_86 , V_111 , 1 , V_36 ) ;
if ( F_113 ( V_4 ) )
return V_4 ;
if ( ! V_188 ) {
void * V_48 = V_86 ;
F_86 (bvec, bio, i) {
char * V_187 = F_97 ( V_115 -> V_88 ) ;
memcpy ( V_187 , V_48 , V_115 -> V_87 ) ;
V_48 += V_115 -> V_87 ;
}
}
V_4 -> V_63 = F_123 ;
return V_4 ;
}
void F_125 ( struct V_4 * V_4 )
{
struct V_30 * V_115 ;
int V_10 ;
F_86 (bvec, bio, i) {
struct V_110 * V_110 = V_115 -> V_88 ;
if ( V_110 && ! F_126 ( V_110 ) )
F_116 ( V_110 ) ;
}
}
static void F_127 ( struct V_4 * V_4 )
{
struct V_30 * V_115 ;
int V_10 ;
F_86 (bvec, bio, i) {
struct V_110 * V_110 = V_115 -> V_88 ;
if ( V_110 )
F_128 ( V_110 ) ;
}
}
static void F_129 ( struct V_64 * V_65 )
{
unsigned long V_58 ;
struct V_4 * V_4 ;
F_130 ( & V_189 , V_58 ) ;
V_4 = V_190 ;
V_190 = NULL ;
F_131 ( & V_189 , V_58 ) ;
while ( V_4 ) {
struct V_4 * V_191 = V_4 -> V_61 ;
F_125 ( V_4 ) ;
F_127 ( V_4 ) ;
F_32 ( V_4 ) ;
V_4 = V_191 ;
}
}
void F_132 ( struct V_4 * V_4 )
{
struct V_30 * V_115 ;
int V_192 = 0 ;
int V_10 ;
F_86 (bvec, bio, i) {
struct V_110 * V_110 = V_115 -> V_88 ;
if ( F_133 ( V_110 ) || F_126 ( V_110 ) ) {
F_110 ( V_110 ) ;
V_115 -> V_88 = NULL ;
} else {
V_192 ++ ;
}
}
if ( V_192 ) {
unsigned long V_58 ;
F_130 ( & V_189 , V_58 ) ;
V_4 -> V_61 = V_190 ;
V_190 = V_4 ;
F_131 ( & V_189 , V_58 ) ;
F_134 ( & V_193 ) ;
} else {
F_32 ( V_4 ) ;
}
}
void F_135 ( struct V_4 * V_194 )
{
struct V_30 V_115 ;
struct V_84 V_85 ;
F_51 (bvec, bi, iter)
F_53 ( V_115 . V_88 ) ;
}
void F_31 ( struct V_4 * V_4 , int error )
{
while ( V_4 ) {
F_34 ( F_55 ( & V_4 -> V_56 ) <= 0 ) ;
if ( error )
F_136 ( V_55 , & V_4 -> V_54 ) ;
else if ( ! F_137 ( V_55 , & V_4 -> V_54 ) )
error = - V_195 ;
if ( ! F_56 ( & V_4 -> V_56 ) )
return;
if ( V_4 -> V_63 == F_30 ) {
struct V_4 * V_62 = V_4 -> V_61 ;
F_32 ( V_4 ) ;
V_4 = V_62 ;
} else {
if ( V_4 -> V_63 )
V_4 -> V_63 ( V_4 , error ) ;
V_4 = NULL ;
}
}
}
void F_138 ( struct V_4 * V_4 , int error )
{
F_35 ( & V_4 -> V_56 ) ;
F_31 ( V_4 , error ) ;
}
struct V_4 * F_139 ( struct V_4 * V_4 , int V_196 ,
T_2 V_197 , struct V_22 * V_23 )
{
struct V_4 * V_198 = NULL ;
F_34 ( V_196 <= 0 ) ;
F_34 ( V_196 >= F_140 ( V_4 ) ) ;
V_198 = F_60 ( V_4 , V_197 , V_23 ) ;
if ( ! V_198 )
return NULL ;
V_198 -> V_97 . V_101 = V_196 << 9 ;
if ( F_21 ( V_198 ) )
F_141 ( V_198 , 0 , V_196 ) ;
F_82 ( V_4 , V_198 -> V_97 . V_101 ) ;
return V_198 ;
}
void F_142 ( struct V_4 * V_4 , int V_112 , int V_199 )
{
V_199 <<= 9 ;
if ( V_112 == 0 && V_199 == V_4 -> V_97 . V_101 )
return;
F_136 ( V_91 , & V_4 -> V_54 ) ;
F_82 ( V_4 , V_112 << 9 ) ;
V_4 -> V_97 . V_101 = V_199 ;
}
T_1 * F_143 ( int V_200 )
{
struct V_34 * V_201 = V_27 + V_33 ;
return F_144 ( V_200 , V_201 -> V_5 ) ;
}
void F_145 ( struct V_22 * V_23 )
{
if ( V_23 -> V_73 )
F_146 ( V_23 -> V_73 ) ;
if ( V_23 -> V_53 )
F_147 ( V_23 -> V_53 ) ;
if ( V_23 -> V_50 )
F_147 ( V_23 -> V_50 ) ;
F_148 ( V_23 ) ;
F_6 ( V_23 ) ;
F_26 ( V_23 ) ;
}
struct V_22 * F_149 ( unsigned int V_202 , unsigned int V_52 )
{
unsigned int V_203 = V_79 * sizeof( struct V_30 ) ;
struct V_22 * V_23 ;
V_23 = F_150 ( sizeof( * V_23 ) , V_19 ) ;
if ( ! V_23 )
return NULL ;
V_23 -> V_52 = V_52 ;
F_151 ( & V_23 -> V_67 ) ;
F_43 ( & V_23 -> V_68 ) ;
F_152 ( & V_23 -> V_66 , F_36 ) ;
V_23 -> V_6 = F_1 ( V_52 + V_203 ) ;
if ( ! V_23 -> V_6 ) {
F_26 ( V_23 ) ;
return NULL ;
}
V_23 -> V_53 = F_144 ( V_202 , V_23 -> V_6 ) ;
if ( ! V_23 -> V_53 )
goto V_204;
V_23 -> V_50 = F_143 ( V_202 ) ;
if ( ! V_23 -> V_50 )
goto V_204;
V_23 -> V_73 = F_153 ( L_3 , V_205 , 0 ) ;
if ( ! V_23 -> V_73 )
goto V_204;
return V_23 ;
V_204:
F_145 ( V_23 ) ;
return NULL ;
}
int F_154 ( struct V_4 * V_4 )
{
struct V_206 * V_207 ;
struct V_208 * V_209 ;
if ( V_4 -> V_210 )
return - V_211 ;
V_207 = V_72 -> V_206 ;
if ( ! V_207 )
return - V_212 ;
F_155 ( V_207 ) ;
V_4 -> V_210 = V_207 ;
F_156 () ;
V_209 = F_157 ( V_72 , V_213 ) ;
if ( V_209 && F_158 ( V_209 ) )
V_4 -> V_214 = V_209 ;
F_159 () ;
return 0 ;
}
void F_20 ( struct V_4 * V_4 )
{
if ( V_4 -> V_210 ) {
F_160 ( V_4 -> V_210 ) ;
V_4 -> V_210 = NULL ;
}
if ( V_4 -> V_214 ) {
F_161 ( V_4 -> V_214 ) ;
V_4 -> V_214 = NULL ;
}
}
static void T_4 F_162 ( void )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_32 ; V_10 ++ ) {
int V_199 ;
struct V_34 * V_35 = V_27 + V_10 ;
if ( V_35 -> V_28 <= V_79 ) {
V_35 -> V_5 = NULL ;
continue;
}
V_199 = V_35 -> V_28 * sizeof( struct V_30 ) ;
V_35 -> V_5 = F_4 ( V_35 -> V_20 , V_199 , 0 ,
V_21 | V_215 , NULL ) ;
}
}
static int T_4 F_163 ( void )
{
V_18 = 2 ;
V_13 = 0 ;
V_14 = F_150 ( V_18 * sizeof( struct V_6 ) , V_19 ) ;
if ( ! V_14 )
F_164 ( L_4 ) ;
F_165 () ;
F_162 () ;
V_216 = F_149 ( V_217 , 0 ) ;
if ( ! V_216 )
F_164 ( L_4 ) ;
if ( F_166 ( V_216 , V_217 ) )
F_164 ( L_5 ) ;
return 0 ;
}
