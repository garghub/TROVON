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
void F_33 ( struct V_4 * V_4 , struct V_4 * V_63 )
{
F_34 ( V_4 -> V_62 || V_4 -> V_64 ) ;
V_4 -> V_62 = V_63 ;
V_4 -> V_64 = F_30 ;
F_35 ( & V_63 -> V_57 ) ;
}
static void F_36 ( struct V_65 * V_66 )
{
struct V_23 * V_24 = F_37 ( V_66 , struct V_23 , V_67 ) ;
struct V_4 * V_4 ;
while ( 1 ) {
F_38 ( & V_24 -> V_68 ) ;
V_4 = F_39 ( & V_24 -> V_69 ) ;
F_40 ( & V_24 -> V_68 ) ;
if ( ! V_4 )
break;
F_41 ( V_4 ) ;
}
}
static void F_42 ( struct V_23 * V_24 )
{
struct V_70 V_71 , V_72 ;
struct V_4 * V_4 ;
F_43 ( & V_71 ) ;
F_43 ( & V_72 ) ;
while ( ( V_4 = F_39 ( V_73 -> V_70 ) ) )
F_44 ( V_4 -> V_48 == V_24 ? & V_71 : & V_72 , V_4 ) ;
* V_73 -> V_70 = V_72 ;
F_38 ( & V_24 -> V_68 ) ;
F_45 ( & V_24 -> V_69 , & V_71 ) ;
F_40 ( & V_24 -> V_68 ) ;
F_46 ( V_24 -> V_74 , & V_24 -> V_67 ) ;
}
struct V_4 * F_47 ( T_2 V_37 , int V_75 , struct V_23 * V_24 )
{
T_2 V_76 = V_37 ;
unsigned V_53 ;
unsigned V_77 ;
unsigned long V_27 = V_78 ;
struct V_31 * V_39 = NULL ;
struct V_4 * V_4 ;
void * V_49 ;
if ( ! V_24 ) {
if ( V_75 > V_79 )
return NULL ;
V_49 = F_48 ( sizeof( struct V_4 ) +
V_75 * sizeof( struct V_31 ) ,
V_37 ) ;
V_53 = 0 ;
V_77 = V_75 ;
} else {
if ( F_49 ( ! V_24 -> V_51 && V_75 > 0 ) )
return NULL ;
if ( V_73 -> V_70 && ! F_50 ( V_73 -> V_70 ) )
V_37 &= ~ V_43 ;
V_49 = F_16 ( V_24 -> V_54 , V_37 ) ;
if ( ! V_49 && V_37 != V_76 ) {
F_42 ( V_24 ) ;
V_37 = V_76 ;
V_49 = F_16 ( V_24 -> V_54 , V_37 ) ;
}
V_53 = V_24 -> V_53 ;
V_77 = V_80 ;
}
if ( F_18 ( ! V_49 ) )
return NULL ;
V_4 = V_49 + V_53 ;
F_27 ( V_4 ) ;
if ( V_75 > V_77 ) {
V_39 = F_15 ( V_37 , V_75 , & V_27 , V_24 -> V_51 ) ;
if ( ! V_39 && V_37 != V_76 ) {
F_42 ( V_24 ) ;
V_37 = V_76 ;
V_39 = F_15 ( V_37 , V_75 , & V_27 , V_24 -> V_51 ) ;
}
if ( F_18 ( ! V_39 ) )
goto V_81;
V_4 -> V_55 |= 1 << V_50 ;
} else if ( V_75 ) {
V_39 = V_4 -> V_82 ;
}
V_4 -> V_48 = V_24 ;
V_4 -> V_55 |= V_27 << V_83 ;
V_4 -> V_84 = V_75 ;
V_4 -> V_52 = V_39 ;
return V_4 ;
V_81:
F_13 ( V_49 , V_24 -> V_54 ) ;
return NULL ;
}
void F_51 ( struct V_4 * V_4 )
{
unsigned long V_59 ;
struct V_31 V_32 ;
struct V_85 V_86 ;
F_52 (bv, bio, iter) {
char * V_87 = F_53 ( & V_32 , & V_59 ) ;
memset ( V_87 , 0 , V_32 . V_88 ) ;
F_54 ( V_32 . V_89 ) ;
F_55 ( V_87 , & V_59 ) ;
}
}
void F_32 ( struct V_4 * V_4 )
{
F_12 ( ! F_56 ( & V_4 -> V_58 ) ) ;
if ( F_57 ( & V_4 -> V_58 ) )
F_23 ( V_4 ) ;
}
inline int F_58 ( struct V_90 * V_91 , struct V_4 * V_4 )
{
if ( F_18 ( ! F_24 ( V_4 , V_92 ) ) )
F_59 ( V_91 , V_4 ) ;
return V_4 -> V_93 ;
}
void F_60 ( struct V_4 * V_4 , struct V_4 * V_94 )
{
F_34 ( V_4 -> V_48 && F_25 ( V_4 ) != V_78 ) ;
V_4 -> V_95 = V_94 -> V_95 ;
V_4 -> V_55 |= 1 << V_96 ;
V_4 -> V_97 = V_94 -> V_97 ;
V_4 -> V_98 = V_94 -> V_98 ;
V_4 -> V_52 = V_94 -> V_52 ;
}
struct V_4 * F_61 ( struct V_4 * V_4 , T_2 V_37 , struct V_23 * V_24 )
{
struct V_4 * V_99 ;
V_99 = F_47 ( V_37 , 0 , V_24 ) ;
if ( ! V_99 )
return NULL ;
F_60 ( V_99 , V_4 ) ;
if ( F_21 ( V_4 ) ) {
int V_100 ;
V_100 = F_62 ( V_99 , V_4 , V_37 ) ;
if ( V_100 < 0 ) {
F_32 ( V_99 ) ;
return NULL ;
}
}
return V_99 ;
}
struct V_4 * F_63 ( struct V_4 * V_94 , T_2 V_37 ,
struct V_23 * V_24 )
{
struct V_85 V_86 ;
struct V_31 V_32 ;
struct V_4 * V_4 ;
V_4 = F_47 ( V_37 , F_64 ( V_94 ) , V_24 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_95 = V_94 -> V_95 ;
V_4 -> V_97 = V_94 -> V_97 ;
V_4 -> V_98 . V_101 = V_94 -> V_98 . V_101 ;
V_4 -> V_98 . V_102 = V_94 -> V_98 . V_102 ;
if ( V_4 -> V_97 & V_103 )
goto V_104;
if ( V_4 -> V_97 & V_105 ) {
V_4 -> V_52 [ V_4 -> V_106 ++ ] = V_94 -> V_52 [ 0 ] ;
goto V_104;
}
F_52 (bv, bio_src, iter)
V_4 -> V_52 [ V_4 -> V_106 ++ ] = V_32 ;
V_104:
if ( F_21 ( V_94 ) ) {
int V_100 ;
V_100 = F_62 ( V_4 , V_94 , V_37 ) ;
if ( V_100 < 0 ) {
F_32 ( V_4 ) ;
return NULL ;
}
}
return V_4 ;
}
int F_65 ( struct V_107 * V_108 )
{
struct V_90 * V_91 = F_66 ( V_108 ) ;
int V_109 ;
V_109 = F_67 ( unsigned ,
F_68 ( V_91 ) ,
F_69 ( V_91 ) / ( V_110 >> 9 ) + 1 ) ;
return F_67 ( unsigned , V_109 , V_40 ) ;
}
static int F_70 ( struct V_90 * V_91 , struct V_4 * V_4 , struct V_111
* V_111 , unsigned int V_112 , unsigned int V_113 ,
unsigned int V_114 )
{
int V_115 = 0 ;
struct V_31 * V_116 ;
if ( F_18 ( F_24 ( V_4 , V_96 ) ) )
return 0 ;
if ( ( ( V_4 -> V_98 . V_102 + V_112 ) >> 9 ) > V_114 )
return 0 ;
if ( V_4 -> V_106 > 0 ) {
struct V_31 * V_117 = & V_4 -> V_52 [ V_4 -> V_106 - 1 ] ;
if ( V_111 == V_117 -> V_89 &&
V_113 == V_117 -> V_118 + V_117 -> V_88 ) {
unsigned int V_119 = V_117 -> V_88 ;
V_117 -> V_88 += V_112 ;
if ( V_91 -> V_120 ) {
struct V_121 V_122 = {
. V_95 = V_4 -> V_95 ,
. V_101 = V_4 -> V_98 . V_101 ,
. V_102 = V_4 -> V_98 . V_102 -
V_119 ,
. V_97 = V_4 -> V_97 ,
} ;
if ( V_91 -> V_120 ( V_91 , & V_122 , V_117 ) < V_117 -> V_88 ) {
V_117 -> V_88 -= V_112 ;
return 0 ;
}
}
goto V_123;
}
if ( V_91 -> V_124 & ( 1 << V_125 ) &&
F_71 ( V_117 , V_113 ) )
return 0 ;
}
if ( V_4 -> V_106 >= V_4 -> V_84 )
return 0 ;
while ( V_4 -> V_93 >= F_68 ( V_91 ) ) {
if ( V_115 )
return 0 ;
V_115 = 1 ;
F_59 ( V_91 , V_4 ) ;
}
V_116 = & V_4 -> V_52 [ V_4 -> V_106 ] ;
V_116 -> V_89 = V_111 ;
V_116 -> V_88 = V_112 ;
V_116 -> V_118 = V_113 ;
if ( V_91 -> V_120 ) {
struct V_121 V_122 = {
. V_95 = V_4 -> V_95 ,
. V_101 = V_4 -> V_98 . V_101 ,
. V_102 = V_4 -> V_98 . V_102 ,
. V_97 = V_4 -> V_97 ,
} ;
if ( V_91 -> V_120 ( V_91 , & V_122 , V_116 ) < V_116 -> V_88 ) {
V_116 -> V_89 = NULL ;
V_116 -> V_88 = 0 ;
V_116 -> V_118 = 0 ;
return 0 ;
}
}
if ( V_4 -> V_106 && ( F_72 ( V_116 - 1 , V_116 ) ) )
V_4 -> V_55 &= ~ ( 1 << V_92 ) ;
V_4 -> V_106 ++ ;
V_4 -> V_93 ++ ;
V_123:
V_4 -> V_98 . V_102 += V_112 ;
return V_112 ;
}
int F_73 ( struct V_90 * V_91 , struct V_4 * V_4 , struct V_111 * V_111 ,
unsigned int V_112 , unsigned int V_113 )
{
return F_70 ( V_91 , V_4 , V_111 , V_112 , V_113 ,
F_74 ( V_91 ) ) ;
}
int F_75 ( struct V_4 * V_4 , struct V_111 * V_111 , unsigned int V_112 ,
unsigned int V_113 )
{
struct V_90 * V_91 = F_66 ( V_4 -> V_95 ) ;
unsigned int V_114 ;
V_114 = F_76 ( V_91 , V_4 -> V_98 . V_101 ) ;
if ( ( V_114 < ( V_112 >> 9 ) ) && ! V_4 -> V_98 . V_102 )
V_114 = V_112 >> 9 ;
return F_70 ( V_91 , V_4 , V_111 , V_112 , V_113 , V_114 ) ;
}
static void F_77 ( struct V_4 * V_4 , int error )
{
struct V_126 * V_100 = V_4 -> V_62 ;
V_100 -> error = error ;
F_78 ( & V_100 -> V_127 ) ;
}
int F_79 ( int V_128 , struct V_4 * V_4 )
{
struct V_126 V_100 ;
V_128 |= V_129 ;
F_80 ( & V_100 . V_127 ) ;
V_4 -> V_62 = & V_100 ;
V_4 -> V_64 = F_77 ;
F_81 ( V_128 , V_4 ) ;
F_82 ( & V_100 . V_127 ) ;
return V_100 . error ;
}
void F_83 ( struct V_4 * V_4 , unsigned V_130 )
{
if ( F_21 ( V_4 ) )
F_84 ( V_4 , V_130 ) ;
F_85 ( V_4 , & V_4 -> V_98 , V_130 ) ;
}
int F_86 ( struct V_4 * V_4 , T_2 V_37 )
{
int V_10 ;
struct V_31 * V_32 ;
F_87 (bv, bio, i) {
V_32 -> V_89 = F_88 ( V_37 ) ;
if ( ! V_32 -> V_89 ) {
while ( -- V_32 >= V_4 -> V_52 )
F_89 ( V_32 -> V_89 ) ;
return - V_131 ;
}
}
return 0 ;
}
void F_90 ( struct V_4 * V_132 , struct V_4 * V_133 )
{
struct V_85 V_134 , V_135 ;
struct V_31 V_136 , V_137 ;
void * V_138 , * V_139 ;
unsigned V_130 ;
V_134 = V_133 -> V_98 ;
V_135 = V_132 -> V_98 ;
while ( 1 ) {
if ( ! V_134 . V_102 ) {
V_133 = V_133 -> V_140 ;
if ( ! V_133 )
break;
V_134 = V_133 -> V_98 ;
}
if ( ! V_135 . V_102 ) {
V_132 = V_132 -> V_140 ;
if ( ! V_132 )
break;
V_135 = V_132 -> V_98 ;
}
V_136 = F_91 ( V_133 , V_134 ) ;
V_137 = F_91 ( V_132 , V_135 ) ;
V_130 = F_92 ( V_136 . V_88 , V_137 . V_88 ) ;
V_138 = F_93 ( V_136 . V_89 ) ;
V_139 = F_93 ( V_137 . V_89 ) ;
memcpy ( V_139 + V_137 . V_118 ,
V_138 + V_136 . V_118 ,
V_130 ) ;
F_94 ( V_139 ) ;
F_94 ( V_138 ) ;
F_85 ( V_133 , & V_134 , V_130 ) ;
F_85 ( V_132 , & V_135 , V_130 ) ;
}
}
static void F_95 ( struct V_141 * V_142 , struct V_4 * V_4 ,
const struct V_143 * V_144 , int V_145 ,
int V_146 )
{
memcpy ( V_142 -> V_147 , V_144 , sizeof( struct V_143 ) * V_145 ) ;
V_142 -> V_148 = V_145 ;
V_142 -> V_146 = V_146 ;
V_4 -> V_62 = V_142 ;
}
static struct V_141 * F_96 ( unsigned int V_145 ,
T_2 V_37 )
{
if ( V_145 > V_79 )
return NULL ;
return F_48 ( sizeof( struct V_141 ) +
sizeof( struct V_143 ) * V_145 , V_37 ) ;
}
static int F_97 ( struct V_4 * V_4 , const struct V_143 * V_144 , int V_145 ,
int V_149 , int V_150 , int V_151 )
{
int V_100 = 0 , V_10 ;
struct V_31 * V_116 ;
int V_152 = 0 ;
unsigned int V_153 = 0 ;
F_87 (bvec, bio, i) {
char * V_154 = F_98 ( V_116 -> V_89 ) ;
unsigned int V_88 = V_116 -> V_88 ;
while ( V_88 && V_152 < V_145 ) {
unsigned int V_130 ;
char T_3 * V_155 ;
V_130 = F_67 (unsigned int,
iov[iov_idx].iov_len - iov_off, bv_len) ;
V_155 = V_144 [ V_152 ] . V_156 + V_153 ;
if ( ! V_100 ) {
if ( V_149 )
V_100 = F_99 ( V_155 , V_154 ,
V_130 ) ;
if ( V_150 )
V_100 = F_100 ( V_154 , V_155 ,
V_130 ) ;
if ( V_100 )
V_100 = - V_157 ;
}
V_88 -= V_130 ;
V_154 += V_130 ;
V_155 += V_130 ;
V_153 += V_130 ;
if ( V_144 [ V_152 ] . V_158 == V_153 ) {
V_152 ++ ;
V_153 = 0 ;
}
}
if ( V_151 )
F_89 ( V_116 -> V_89 ) ;
}
return V_100 ;
}
int F_101 ( struct V_4 * V_4 )
{
struct V_141 * V_142 = V_4 -> V_62 ;
struct V_31 * V_116 ;
int V_100 = 0 , V_10 ;
if ( ! F_24 ( V_4 , V_159 ) ) {
if ( V_73 -> V_160 )
V_100 = F_97 ( V_4 , V_142 -> V_147 , V_142 -> V_148 ,
F_102 ( V_4 ) == V_161 ,
0 , V_142 -> V_146 ) ;
else if ( V_142 -> V_146 )
F_87 (bvec, bio, i)
F_89 ( V_116 -> V_89 ) ;
}
F_26 ( V_142 ) ;
F_32 ( V_4 ) ;
return V_100 ;
}
struct V_4 * F_103 ( struct V_90 * V_91 ,
struct V_162 * V_163 ,
const struct V_143 * V_144 , int V_145 ,
int V_164 , T_2 V_37 )
{
struct V_141 * V_142 ;
struct V_31 * V_116 ;
struct V_111 * V_111 ;
struct V_4 * V_4 ;
int V_10 , V_100 ;
int V_109 = 0 ;
unsigned int V_112 = 0 ;
unsigned int V_113 = V_163 ? V_163 -> V_113 & ~ V_165 : 0 ;
for ( V_10 = 0 ; V_10 < V_145 ; V_10 ++ ) {
unsigned long V_166 ;
unsigned long V_167 ;
unsigned long V_168 ;
V_166 = ( unsigned long ) V_144 [ V_10 ] . V_156 ;
V_167 = ( V_166 + V_144 [ V_10 ] . V_158 + V_110 - 1 ) >> V_169 ;
V_168 = V_166 >> V_169 ;
if ( V_167 < V_168 )
return F_104 ( - V_170 ) ;
V_109 += V_167 - V_168 ;
V_112 += V_144 [ V_10 ] . V_158 ;
}
if ( V_113 )
V_109 ++ ;
V_142 = F_96 ( V_145 , V_37 ) ;
if ( ! V_142 )
return F_104 ( - V_131 ) ;
V_100 = - V_131 ;
V_4 = F_105 ( V_37 , V_109 ) ;
if ( ! V_4 )
goto V_171;
if ( ! V_164 )
V_4 -> V_97 |= V_172 ;
V_100 = 0 ;
if ( V_163 ) {
V_109 = 1 << V_163 -> V_173 ;
V_10 = V_163 -> V_113 / V_110 ;
}
while ( V_112 ) {
unsigned int V_130 = V_110 ;
V_130 -= V_113 ;
if ( V_130 > V_112 )
V_130 = V_112 ;
if ( V_163 ) {
if ( V_10 == V_163 -> V_174 * V_109 ) {
V_100 = - V_131 ;
break;
}
V_111 = V_163 -> V_175 [ V_10 / V_109 ] ;
V_111 += ( V_10 % V_109 ) ;
V_10 ++ ;
} else {
V_111 = F_88 ( V_91 -> V_176 | V_37 ) ;
if ( ! V_111 ) {
V_100 = - V_131 ;
break;
}
}
if ( F_73 ( V_91 , V_4 , V_111 , V_130 , V_113 ) < V_130 )
break;
V_112 -= V_130 ;
V_113 = 0 ;
}
if ( V_100 )
goto V_177;
if ( ( ! V_164 && ( ! V_163 || ! V_163 -> V_178 ) ) ||
( V_163 && V_163 -> V_150 ) ) {
V_100 = F_97 ( V_4 , V_144 , V_145 , 0 , 1 , 0 ) ;
if ( V_100 )
goto V_177;
}
F_95 ( V_142 , V_4 , V_144 , V_145 , V_163 ? 0 : 1 ) ;
return V_4 ;
V_177:
if ( ! V_163 )
F_87 (bvec, bio, i)
F_89 ( V_116 -> V_89 ) ;
F_32 ( V_4 ) ;
V_171:
F_26 ( V_142 ) ;
return F_104 ( V_100 ) ;
}
struct V_4 * F_106 ( struct V_90 * V_91 , struct V_162 * V_163 ,
unsigned long V_166 , unsigned int V_112 ,
int V_164 , T_2 V_37 )
{
struct V_143 V_144 ;
V_144 . V_156 = ( void T_3 * ) V_166 ;
V_144 . V_158 = V_112 ;
return F_103 ( V_91 , V_163 , & V_144 , 1 , V_164 , V_37 ) ;
}
static struct V_4 * F_107 ( struct V_90 * V_91 ,
struct V_107 * V_108 ,
const struct V_143 * V_144 , int V_145 ,
int V_164 , T_2 V_37 )
{
int V_10 , V_179 ;
int V_109 = 0 ;
struct V_111 * * V_175 ;
struct V_4 * V_4 ;
int V_180 = 0 ;
int V_100 , V_113 ;
for ( V_10 = 0 ; V_10 < V_145 ; V_10 ++ ) {
unsigned long V_166 = ( unsigned long ) V_144 [ V_10 ] . V_156 ;
unsigned long V_112 = V_144 [ V_10 ] . V_158 ;
unsigned long V_167 = ( V_166 + V_112 + V_110 - 1 ) >> V_169 ;
unsigned long V_168 = V_166 >> V_169 ;
if ( V_167 < V_168 )
return F_104 ( - V_170 ) ;
V_109 += V_167 - V_168 ;
if ( V_166 & F_108 ( V_91 ) )
return F_104 ( - V_170 ) ;
}
if ( ! V_109 )
return F_104 ( - V_170 ) ;
V_4 = F_105 ( V_37 , V_109 ) ;
if ( ! V_4 )
return F_104 ( - V_131 ) ;
V_100 = - V_131 ;
V_175 = F_109 ( V_109 , sizeof( struct V_111 * ) , V_37 ) ;
if ( ! V_175 )
goto V_26;
for ( V_10 = 0 ; V_10 < V_145 ; V_10 ++ ) {
unsigned long V_166 = ( unsigned long ) V_144 [ V_10 ] . V_156 ;
unsigned long V_112 = V_144 [ V_10 ] . V_158 ;
unsigned long V_167 = ( V_166 + V_112 + V_110 - 1 ) >> V_169 ;
unsigned long V_168 = V_166 >> V_169 ;
const int V_181 = V_167 - V_168 ;
const int V_182 = V_180 + V_181 ;
V_100 = F_110 ( V_166 , V_181 ,
V_164 , & V_175 [ V_180 ] ) ;
if ( V_100 < V_181 ) {
V_100 = - V_157 ;
goto V_183;
}
V_113 = V_166 & ~ V_165 ;
for ( V_179 = V_180 ; V_179 < V_182 ; V_179 ++ ) {
unsigned int V_130 = V_110 - V_113 ;
if ( V_112 <= 0 )
break;
if ( V_130 > V_112 )
V_130 = V_112 ;
if ( F_73 ( V_91 , V_4 , V_175 [ V_179 ] , V_130 , V_113 ) <
V_130 )
break;
V_112 -= V_130 ;
V_113 = 0 ;
}
V_180 = V_179 ;
while ( V_179 < V_182 )
F_111 ( V_175 [ V_179 ++ ] ) ;
}
F_26 ( V_175 ) ;
if ( ! V_164 )
V_4 -> V_97 |= V_172 ;
V_4 -> V_95 = V_108 ;
V_4 -> V_55 |= ( 1 << V_184 ) ;
return V_4 ;
V_183:
for ( V_10 = 0 ; V_10 < V_109 ; V_10 ++ ) {
if( ! V_175 [ V_10 ] )
break;
F_111 ( V_175 [ V_10 ] ) ;
}
V_26:
F_26 ( V_175 ) ;
F_32 ( V_4 ) ;
return F_104 ( V_100 ) ;
}
struct V_4 * F_112 ( struct V_90 * V_91 , struct V_107 * V_108 ,
unsigned long V_166 , unsigned int V_112 , int V_164 ,
T_2 V_37 )
{
struct V_143 V_144 ;
V_144 . V_156 = ( void T_3 * ) V_166 ;
V_144 . V_158 = V_112 ;
return F_113 ( V_91 , V_108 , & V_144 , 1 , V_164 , V_37 ) ;
}
struct V_4 * F_113 ( struct V_90 * V_91 , struct V_107 * V_108 ,
const struct V_143 * V_144 , int V_145 ,
int V_164 , T_2 V_37 )
{
struct V_4 * V_4 ;
V_4 = F_107 ( V_91 , V_108 , V_144 , V_145 , V_164 ,
V_37 ) ;
if ( F_114 ( V_4 ) )
return V_4 ;
F_115 ( V_4 ) ;
return V_4 ;
}
static void F_116 ( struct V_4 * V_4 )
{
struct V_31 * V_116 ;
int V_10 ;
F_87 (bvec, bio, i) {
if ( F_102 ( V_4 ) == V_161 )
F_117 ( V_116 -> V_89 ) ;
F_111 ( V_116 -> V_89 ) ;
}
F_32 ( V_4 ) ;
}
void F_118 ( struct V_4 * V_4 )
{
F_116 ( V_4 ) ;
F_32 ( V_4 ) ;
}
static void F_119 ( struct V_4 * V_4 , int V_185 )
{
F_32 ( V_4 ) ;
}
static struct V_4 * F_120 ( struct V_90 * V_91 , void * V_87 ,
unsigned int V_112 , T_2 V_37 )
{
unsigned long V_186 = ( unsigned long ) V_87 ;
unsigned long V_167 = ( V_186 + V_112 + V_110 - 1 ) >> V_169 ;
unsigned long V_168 = V_186 >> V_169 ;
const int V_109 = V_167 - V_168 ;
int V_113 , V_10 ;
struct V_4 * V_4 ;
V_4 = F_105 ( V_37 , V_109 ) ;
if ( ! V_4 )
return F_104 ( - V_131 ) ;
V_113 = F_121 ( V_186 ) ;
for ( V_10 = 0 ; V_10 < V_109 ; V_10 ++ ) {
unsigned int V_130 = V_110 - V_113 ;
if ( V_112 <= 0 )
break;
if ( V_130 > V_112 )
V_130 = V_112 ;
if ( F_73 ( V_91 , V_4 , F_122 ( V_87 ) , V_130 ,
V_113 ) < V_130 )
break;
V_87 += V_130 ;
V_112 -= V_130 ;
V_113 = 0 ;
}
V_4 -> V_64 = F_119 ;
return V_4 ;
}
struct V_4 * F_123 ( struct V_90 * V_91 , void * V_87 , unsigned int V_112 ,
T_2 V_37 )
{
struct V_4 * V_4 ;
V_4 = F_120 ( V_91 , V_87 , V_112 , V_37 ) ;
if ( F_114 ( V_4 ) )
return V_4 ;
if ( V_4 -> V_98 . V_102 == V_112 )
return V_4 ;
F_32 ( V_4 ) ;
return F_104 ( - V_170 ) ;
}
static void F_124 ( struct V_4 * V_4 , int V_185 )
{
struct V_31 * V_116 ;
const int V_187 = F_102 ( V_4 ) == V_161 ;
struct V_141 * V_142 = V_4 -> V_62 ;
int V_10 ;
char * V_49 = V_142 -> V_147 [ 0 ] . V_156 ;
F_87 (bvec, bio, i) {
char * V_188 = F_98 ( V_116 -> V_89 ) ;
if ( V_187 )
memcpy ( V_49 , V_188 , V_116 -> V_88 ) ;
F_89 ( V_116 -> V_89 ) ;
V_49 += V_116 -> V_88 ;
}
F_26 ( V_142 ) ;
F_32 ( V_4 ) ;
}
struct V_4 * F_125 ( struct V_90 * V_91 , void * V_87 , unsigned int V_112 ,
T_2 V_37 , int V_189 )
{
struct V_4 * V_4 ;
struct V_31 * V_116 ;
int V_10 ;
V_4 = F_106 ( V_91 , NULL , ( unsigned long ) V_87 , V_112 , 1 , V_37 ) ;
if ( F_114 ( V_4 ) )
return V_4 ;
if ( ! V_189 ) {
void * V_49 = V_87 ;
F_87 (bvec, bio, i) {
char * V_188 = F_98 ( V_116 -> V_89 ) ;
memcpy ( V_188 , V_49 , V_116 -> V_88 ) ;
V_49 += V_116 -> V_88 ;
}
}
V_4 -> V_64 = F_124 ;
return V_4 ;
}
void F_126 ( struct V_4 * V_4 )
{
struct V_31 * V_116 ;
int V_10 ;
F_87 (bvec, bio, i) {
struct V_111 * V_111 = V_116 -> V_89 ;
if ( V_111 && ! F_127 ( V_111 ) )
F_117 ( V_111 ) ;
}
}
static void F_128 ( struct V_4 * V_4 )
{
struct V_31 * V_116 ;
int V_10 ;
F_87 (bvec, bio, i) {
struct V_111 * V_111 = V_116 -> V_89 ;
if ( V_111 )
F_129 ( V_111 ) ;
}
}
static void F_130 ( struct V_65 * V_66 )
{
unsigned long V_59 ;
struct V_4 * V_4 ;
F_131 ( & V_190 , V_59 ) ;
V_4 = V_191 ;
V_191 = NULL ;
F_132 ( & V_190 , V_59 ) ;
while ( V_4 ) {
struct V_4 * V_192 = V_4 -> V_62 ;
F_126 ( V_4 ) ;
F_128 ( V_4 ) ;
F_32 ( V_4 ) ;
V_4 = V_192 ;
}
}
void F_133 ( struct V_4 * V_4 )
{
struct V_31 * V_116 ;
int V_193 = 0 ;
int V_10 ;
F_87 (bvec, bio, i) {
struct V_111 * V_111 = V_116 -> V_89 ;
if ( F_134 ( V_111 ) || F_127 ( V_111 ) ) {
F_111 ( V_111 ) ;
V_116 -> V_89 = NULL ;
} else {
V_193 ++ ;
}
}
if ( V_193 ) {
unsigned long V_59 ;
F_131 ( & V_190 , V_59 ) ;
V_4 -> V_62 = V_191 ;
V_191 = V_4 ;
F_132 ( & V_190 , V_59 ) ;
F_135 ( & V_194 ) ;
} else {
F_32 ( V_4 ) ;
}
}
void F_136 ( struct V_4 * V_195 )
{
struct V_31 V_116 ;
struct V_85 V_86 ;
F_52 (bvec, bi, iter)
F_54 ( V_116 . V_89 ) ;
}
void F_31 ( struct V_4 * V_4 , int error )
{
while ( V_4 ) {
F_34 ( F_56 ( & V_4 -> V_57 ) <= 0 ) ;
if ( error )
F_137 ( V_56 , & V_4 -> V_55 ) ;
else if ( ! F_138 ( V_56 , & V_4 -> V_55 ) )
error = - V_196 ;
if ( ! F_57 ( & V_4 -> V_57 ) )
return;
if ( V_4 -> V_64 == F_30 ) {
struct V_4 * V_63 = V_4 -> V_62 ;
F_32 ( V_4 ) ;
V_4 = V_63 ;
} else {
if ( V_4 -> V_64 )
V_4 -> V_64 ( V_4 , error ) ;
V_4 = NULL ;
}
}
}
void F_139 ( struct V_4 * V_4 , int error )
{
F_35 ( & V_4 -> V_57 ) ;
F_31 ( V_4 , error ) ;
}
struct V_4 * F_140 ( struct V_4 * V_4 , int V_197 ,
T_2 V_198 , struct V_23 * V_24 )
{
struct V_4 * V_199 = NULL ;
F_34 ( V_197 <= 0 ) ;
F_34 ( V_197 >= F_141 ( V_4 ) ) ;
V_199 = F_61 ( V_4 , V_198 , V_24 ) ;
if ( ! V_199 )
return NULL ;
V_199 -> V_98 . V_102 = V_197 << 9 ;
if ( F_21 ( V_199 ) )
F_142 ( V_199 , 0 , V_197 ) ;
F_83 ( V_4 , V_199 -> V_98 . V_102 ) ;
return V_199 ;
}
void F_143 ( struct V_4 * V_4 , int V_113 , int V_200 )
{
V_200 <<= 9 ;
if ( V_113 == 0 && V_200 == V_4 -> V_98 . V_102 )
return;
F_137 ( V_92 , & V_4 -> V_55 ) ;
F_83 ( V_4 , V_113 << 9 ) ;
V_4 -> V_98 . V_102 = V_200 ;
}
T_1 * F_144 ( int V_201 )
{
struct V_35 * V_202 = V_28 + V_34 ;
return F_145 ( V_201 , V_202 -> V_5 ) ;
}
void F_146 ( struct V_23 * V_24 )
{
if ( V_24 -> V_74 )
F_147 ( V_24 -> V_74 ) ;
if ( V_24 -> V_54 )
F_148 ( V_24 -> V_54 ) ;
if ( V_24 -> V_51 )
F_148 ( V_24 -> V_51 ) ;
F_149 ( V_24 ) ;
F_6 ( V_24 ) ;
F_26 ( V_24 ) ;
}
static struct V_23 * F_150 ( unsigned int V_203 ,
unsigned int V_53 ,
bool V_204 )
{
unsigned int V_205 = V_80 * sizeof( struct V_31 ) ;
struct V_23 * V_24 ;
V_24 = F_151 ( sizeof( * V_24 ) , V_19 ) ;
if ( ! V_24 )
return NULL ;
V_24 -> V_53 = V_53 ;
F_152 ( & V_24 -> V_68 ) ;
F_43 ( & V_24 -> V_69 ) ;
F_153 ( & V_24 -> V_67 , F_36 ) ;
V_24 -> V_6 = F_1 ( V_53 + V_205 ) ;
if ( ! V_24 -> V_6 ) {
F_26 ( V_24 ) ;
return NULL ;
}
V_24 -> V_54 = F_145 ( V_203 , V_24 -> V_6 ) ;
if ( ! V_24 -> V_54 )
goto V_206;
if ( V_204 ) {
V_24 -> V_51 = F_144 ( V_203 ) ;
if ( ! V_24 -> V_51 )
goto V_206;
}
V_24 -> V_74 = F_154 ( L_3 , V_207 , 0 ) ;
if ( ! V_24 -> V_74 )
goto V_206;
return V_24 ;
V_206:
F_146 ( V_24 ) ;
return NULL ;
}
struct V_23 * F_155 ( unsigned int V_203 , unsigned int V_53 )
{
return F_150 ( V_203 , V_53 , true ) ;
}
struct V_23 * F_156 ( unsigned int V_203 , unsigned int V_53 )
{
return F_150 ( V_203 , V_53 , false ) ;
}
int F_157 ( struct V_4 * V_4 )
{
struct V_208 * V_209 ;
struct V_210 * V_211 ;
if ( V_4 -> V_212 )
return - V_213 ;
V_209 = V_73 -> V_208 ;
if ( ! V_209 )
return - V_214 ;
F_158 ( V_209 ) ;
V_4 -> V_212 = V_209 ;
F_159 () ;
V_211 = F_160 ( V_73 , V_215 ) ;
if ( V_211 && F_161 ( V_211 ) )
V_4 -> V_216 = V_211 ;
F_162 () ;
return 0 ;
}
void F_20 ( struct V_4 * V_4 )
{
if ( V_4 -> V_212 ) {
F_163 ( V_4 -> V_212 ) ;
V_4 -> V_212 = NULL ;
}
if ( V_4 -> V_216 ) {
F_164 ( V_4 -> V_216 ) ;
V_4 -> V_216 = NULL ;
}
}
static void T_4 F_165 ( void )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_33 ; V_10 ++ ) {
int V_200 ;
struct V_35 * V_36 = V_28 + V_10 ;
if ( V_36 -> V_29 <= V_80 ) {
V_36 -> V_5 = NULL ;
continue;
}
V_200 = V_36 -> V_29 * sizeof( struct V_31 ) ;
V_36 -> V_5 = F_4 ( V_36 -> V_20 , V_200 , 0 ,
V_22 | V_217 , NULL ) ;
}
}
static int T_4 F_166 ( void )
{
V_18 = 2 ;
V_13 = 0 ;
V_14 = F_151 ( V_18 * sizeof( struct V_6 ) , V_19 ) ;
if ( ! V_14 )
F_167 ( L_4 ) ;
F_168 () ;
F_165 () ;
V_218 = F_155 ( V_219 , 0 ) ;
if ( ! V_218 )
F_167 ( L_4 ) ;
if ( F_169 ( V_218 , V_219 ) )
F_167 ( L_5 ) ;
return 0 ;
}
