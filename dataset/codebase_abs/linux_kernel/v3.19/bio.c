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
V_4 -> V_98 . V_102 += V_112 ;
goto V_123;
}
if ( V_91 -> V_124 & ( 1 << V_125 ) &&
F_71 ( V_117 , V_113 ) )
return 0 ;
}
if ( V_4 -> V_106 >= V_4 -> V_84 )
return 0 ;
V_116 = & V_4 -> V_52 [ V_4 -> V_106 ] ;
V_116 -> V_89 = V_111 ;
V_116 -> V_88 = V_112 ;
V_116 -> V_118 = V_113 ;
V_4 -> V_106 ++ ;
V_4 -> V_93 ++ ;
V_4 -> V_98 . V_102 += V_112 ;
while ( V_4 -> V_93 > F_68 ( V_91 ) ) {
if ( V_115 )
goto V_126;
V_115 = 1 ;
F_59 ( V_91 , V_4 ) ;
}
if ( V_91 -> V_120 ) {
struct V_121 V_122 = {
. V_95 = V_4 -> V_95 ,
. V_101 = V_4 -> V_98 . V_101 ,
. V_102 = V_4 -> V_98 . V_102 - V_112 ,
. V_97 = V_4 -> V_97 ,
} ;
if ( V_91 -> V_120 ( V_91 , & V_122 , V_116 ) < V_116 -> V_88 )
goto V_126;
}
if ( V_4 -> V_106 > 1 && ( F_72 ( V_116 - 1 , V_116 ) ) )
V_4 -> V_55 &= ~ ( 1 << V_92 ) ;
V_123:
return V_112 ;
V_126:
V_116 -> V_89 = NULL ;
V_116 -> V_88 = 0 ;
V_116 -> V_118 = 0 ;
V_4 -> V_106 -- ;
V_4 -> V_98 . V_102 -= V_112 ;
F_59 ( V_91 , V_4 ) ;
return 0 ;
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
struct V_127 * V_100 = V_4 -> V_62 ;
V_100 -> error = error ;
F_78 ( & V_100 -> V_128 ) ;
}
int F_79 ( int V_129 , struct V_4 * V_4 )
{
struct V_127 V_100 ;
V_129 |= V_130 ;
F_80 ( & V_100 . V_128 ) ;
V_4 -> V_62 = & V_100 ;
V_4 -> V_64 = F_77 ;
F_81 ( V_129 , V_4 ) ;
F_82 ( & V_100 . V_128 ) ;
return V_100 . error ;
}
void F_83 ( struct V_4 * V_4 , unsigned V_131 )
{
if ( F_21 ( V_4 ) )
F_84 ( V_4 , V_131 ) ;
F_85 ( V_4 , & V_4 -> V_98 , V_131 ) ;
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
return - V_132 ;
}
}
return 0 ;
}
void F_90 ( struct V_4 * V_133 , struct V_4 * V_134 )
{
struct V_85 V_135 , V_136 ;
struct V_31 V_137 , V_138 ;
void * V_139 , * V_140 ;
unsigned V_131 ;
V_135 = V_134 -> V_98 ;
V_136 = V_133 -> V_98 ;
while ( 1 ) {
if ( ! V_135 . V_102 ) {
V_134 = V_134 -> V_141 ;
if ( ! V_134 )
break;
V_135 = V_134 -> V_98 ;
}
if ( ! V_136 . V_102 ) {
V_133 = V_133 -> V_141 ;
if ( ! V_133 )
break;
V_136 = V_133 -> V_98 ;
}
V_137 = F_91 ( V_134 , V_135 ) ;
V_138 = F_91 ( V_133 , V_136 ) ;
V_131 = F_92 ( V_137 . V_88 , V_138 . V_88 ) ;
V_139 = F_93 ( V_137 . V_89 ) ;
V_140 = F_93 ( V_138 . V_89 ) ;
memcpy ( V_140 + V_138 . V_118 ,
V_139 + V_137 . V_118 ,
V_131 ) ;
F_94 ( V_140 ) ;
F_94 ( V_139 ) ;
F_85 ( V_134 , & V_135 , V_131 ) ;
F_85 ( V_133 , & V_136 , V_131 ) ;
}
}
static void F_95 ( struct V_142 * V_143 , struct V_4 * V_4 ,
const struct V_144 * V_145 , int V_146 ,
int V_147 )
{
memcpy ( V_143 -> V_148 , V_145 , sizeof( struct V_144 ) * V_146 ) ;
V_143 -> V_149 = V_146 ;
V_143 -> V_147 = V_147 ;
V_4 -> V_62 = V_143 ;
}
static struct V_142 * F_96 ( unsigned int V_146 ,
T_2 V_37 )
{
if ( V_146 > V_79 )
return NULL ;
return F_48 ( sizeof( struct V_142 ) +
sizeof( struct V_144 ) * V_146 , V_37 ) ;
}
static int F_97 ( struct V_4 * V_4 , const struct V_144 * V_145 , int V_146 ,
int V_150 , int V_151 , int V_152 )
{
int V_100 = 0 , V_10 ;
struct V_31 * V_116 ;
int V_153 = 0 ;
unsigned int V_154 = 0 ;
F_87 (bvec, bio, i) {
char * V_155 = F_98 ( V_116 -> V_89 ) ;
unsigned int V_88 = V_116 -> V_88 ;
while ( V_88 && V_153 < V_146 ) {
unsigned int V_131 ;
char T_3 * V_156 ;
V_131 = F_67 (unsigned int,
iov[iov_idx].iov_len - iov_off, bv_len) ;
V_156 = V_145 [ V_153 ] . V_157 + V_154 ;
if ( ! V_100 ) {
if ( V_150 )
V_100 = F_99 ( V_156 , V_155 ,
V_131 ) ;
if ( V_151 )
V_100 = F_100 ( V_155 , V_156 ,
V_131 ) ;
if ( V_100 )
V_100 = - V_158 ;
}
V_88 -= V_131 ;
V_155 += V_131 ;
V_156 += V_131 ;
V_154 += V_131 ;
if ( V_145 [ V_153 ] . V_159 == V_154 ) {
V_153 ++ ;
V_154 = 0 ;
}
}
if ( V_152 )
F_89 ( V_116 -> V_89 ) ;
}
return V_100 ;
}
int F_101 ( struct V_4 * V_4 )
{
struct V_142 * V_143 = V_4 -> V_62 ;
struct V_31 * V_116 ;
int V_100 = 0 , V_10 ;
if ( ! F_24 ( V_4 , V_160 ) ) {
if ( V_73 -> V_161 )
V_100 = F_97 ( V_4 , V_143 -> V_148 , V_143 -> V_149 ,
F_102 ( V_4 ) == V_162 ,
0 , V_143 -> V_147 ) ;
else if ( V_143 -> V_147 )
F_87 (bvec, bio, i)
F_89 ( V_116 -> V_89 ) ;
}
F_26 ( V_143 ) ;
F_32 ( V_4 ) ;
return V_100 ;
}
struct V_4 * F_103 ( struct V_90 * V_91 ,
struct V_163 * V_164 ,
const struct V_144 * V_145 , int V_146 ,
int V_165 , T_2 V_37 )
{
struct V_142 * V_143 ;
struct V_31 * V_116 ;
struct V_111 * V_111 ;
struct V_4 * V_4 ;
int V_10 , V_100 ;
int V_109 = 0 ;
unsigned int V_112 = 0 ;
unsigned int V_113 = V_164 ? V_164 -> V_113 & ~ V_166 : 0 ;
for ( V_10 = 0 ; V_10 < V_146 ; V_10 ++ ) {
unsigned long V_167 ;
unsigned long V_168 ;
unsigned long V_169 ;
V_167 = ( unsigned long ) V_145 [ V_10 ] . V_157 ;
V_168 = ( V_167 + V_145 [ V_10 ] . V_159 + V_110 - 1 ) >> V_170 ;
V_169 = V_167 >> V_170 ;
if ( V_168 < V_169 )
return F_104 ( - V_171 ) ;
V_109 += V_168 - V_169 ;
V_112 += V_145 [ V_10 ] . V_159 ;
}
if ( V_113 )
V_109 ++ ;
V_143 = F_96 ( V_146 , V_37 ) ;
if ( ! V_143 )
return F_104 ( - V_132 ) ;
V_100 = - V_132 ;
V_4 = F_105 ( V_37 , V_109 ) ;
if ( ! V_4 )
goto V_172;
if ( ! V_165 )
V_4 -> V_97 |= V_173 ;
V_100 = 0 ;
if ( V_164 ) {
V_109 = 1 << V_164 -> V_174 ;
V_10 = V_164 -> V_113 / V_110 ;
}
while ( V_112 ) {
unsigned int V_131 = V_110 ;
V_131 -= V_113 ;
if ( V_131 > V_112 )
V_131 = V_112 ;
if ( V_164 ) {
if ( V_10 == V_164 -> V_175 * V_109 ) {
V_100 = - V_132 ;
break;
}
V_111 = V_164 -> V_176 [ V_10 / V_109 ] ;
V_111 += ( V_10 % V_109 ) ;
V_10 ++ ;
} else {
V_111 = F_88 ( V_91 -> V_177 | V_37 ) ;
if ( ! V_111 ) {
V_100 = - V_132 ;
break;
}
}
if ( F_73 ( V_91 , V_4 , V_111 , V_131 , V_113 ) < V_131 )
break;
V_112 -= V_131 ;
V_113 = 0 ;
}
if ( V_100 )
goto V_178;
if ( ( ! V_165 && ( ! V_164 || ! V_164 -> V_179 ) ) ||
( V_164 && V_164 -> V_151 ) ) {
V_100 = F_97 ( V_4 , V_145 , V_146 , 0 , 1 , 0 ) ;
if ( V_100 )
goto V_178;
}
F_95 ( V_143 , V_4 , V_145 , V_146 , V_164 ? 0 : 1 ) ;
return V_4 ;
V_178:
if ( ! V_164 )
F_87 (bvec, bio, i)
F_89 ( V_116 -> V_89 ) ;
F_32 ( V_4 ) ;
V_172:
F_26 ( V_143 ) ;
return F_104 ( V_100 ) ;
}
struct V_4 * F_106 ( struct V_90 * V_91 , struct V_163 * V_164 ,
unsigned long V_167 , unsigned int V_112 ,
int V_165 , T_2 V_37 )
{
struct V_144 V_145 ;
V_145 . V_157 = ( void T_3 * ) V_167 ;
V_145 . V_159 = V_112 ;
return F_103 ( V_91 , V_164 , & V_145 , 1 , V_165 , V_37 ) ;
}
static struct V_4 * F_107 ( struct V_90 * V_91 ,
struct V_107 * V_108 ,
const struct V_144 * V_145 , int V_146 ,
int V_165 , T_2 V_37 )
{
int V_10 , V_180 ;
int V_109 = 0 ;
struct V_111 * * V_176 ;
struct V_4 * V_4 ;
int V_181 = 0 ;
int V_100 , V_113 ;
for ( V_10 = 0 ; V_10 < V_146 ; V_10 ++ ) {
unsigned long V_167 = ( unsigned long ) V_145 [ V_10 ] . V_157 ;
unsigned long V_112 = V_145 [ V_10 ] . V_159 ;
unsigned long V_168 = ( V_167 + V_112 + V_110 - 1 ) >> V_170 ;
unsigned long V_169 = V_167 >> V_170 ;
if ( V_168 < V_169 )
return F_104 ( - V_171 ) ;
V_109 += V_168 - V_169 ;
if ( V_167 & F_108 ( V_91 ) )
return F_104 ( - V_171 ) ;
}
if ( ! V_109 )
return F_104 ( - V_171 ) ;
V_4 = F_105 ( V_37 , V_109 ) ;
if ( ! V_4 )
return F_104 ( - V_132 ) ;
V_100 = - V_132 ;
V_176 = F_109 ( V_109 , sizeof( struct V_111 * ) , V_37 ) ;
if ( ! V_176 )
goto V_26;
for ( V_10 = 0 ; V_10 < V_146 ; V_10 ++ ) {
unsigned long V_167 = ( unsigned long ) V_145 [ V_10 ] . V_157 ;
unsigned long V_112 = V_145 [ V_10 ] . V_159 ;
unsigned long V_168 = ( V_167 + V_112 + V_110 - 1 ) >> V_170 ;
unsigned long V_169 = V_167 >> V_170 ;
const int V_182 = V_168 - V_169 ;
const int V_183 = V_181 + V_182 ;
V_100 = F_110 ( V_167 , V_182 ,
V_165 , & V_176 [ V_181 ] ) ;
if ( V_100 < V_182 ) {
V_100 = - V_158 ;
goto V_184;
}
V_113 = V_167 & ~ V_166 ;
for ( V_180 = V_181 ; V_180 < V_183 ; V_180 ++ ) {
unsigned int V_131 = V_110 - V_113 ;
if ( V_112 <= 0 )
break;
if ( V_131 > V_112 )
V_131 = V_112 ;
if ( F_73 ( V_91 , V_4 , V_176 [ V_180 ] , V_131 , V_113 ) <
V_131 )
break;
V_112 -= V_131 ;
V_113 = 0 ;
}
V_181 = V_180 ;
while ( V_180 < V_183 )
F_111 ( V_176 [ V_180 ++ ] ) ;
}
F_26 ( V_176 ) ;
if ( ! V_165 )
V_4 -> V_97 |= V_173 ;
V_4 -> V_95 = V_108 ;
V_4 -> V_55 |= ( 1 << V_185 ) ;
return V_4 ;
V_184:
for ( V_10 = 0 ; V_10 < V_109 ; V_10 ++ ) {
if( ! V_176 [ V_10 ] )
break;
F_111 ( V_176 [ V_10 ] ) ;
}
V_26:
F_26 ( V_176 ) ;
F_32 ( V_4 ) ;
return F_104 ( V_100 ) ;
}
struct V_4 * F_112 ( struct V_90 * V_91 , struct V_107 * V_108 ,
unsigned long V_167 , unsigned int V_112 , int V_165 ,
T_2 V_37 )
{
struct V_144 V_145 ;
V_145 . V_157 = ( void T_3 * ) V_167 ;
V_145 . V_159 = V_112 ;
return F_113 ( V_91 , V_108 , & V_145 , 1 , V_165 , V_37 ) ;
}
struct V_4 * F_113 ( struct V_90 * V_91 , struct V_107 * V_108 ,
const struct V_144 * V_145 , int V_146 ,
int V_165 , T_2 V_37 )
{
struct V_4 * V_4 ;
V_4 = F_107 ( V_91 , V_108 , V_145 , V_146 , V_165 ,
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
if ( F_102 ( V_4 ) == V_162 )
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
static void F_119 ( struct V_4 * V_4 , int V_186 )
{
F_32 ( V_4 ) ;
}
static struct V_4 * F_120 ( struct V_90 * V_91 , void * V_87 ,
unsigned int V_112 , T_2 V_37 )
{
unsigned long V_187 = ( unsigned long ) V_87 ;
unsigned long V_168 = ( V_187 + V_112 + V_110 - 1 ) >> V_170 ;
unsigned long V_169 = V_187 >> V_170 ;
const int V_109 = V_168 - V_169 ;
int V_113 , V_10 ;
struct V_4 * V_4 ;
V_4 = F_105 ( V_37 , V_109 ) ;
if ( ! V_4 )
return F_104 ( - V_132 ) ;
V_113 = F_121 ( V_187 ) ;
for ( V_10 = 0 ; V_10 < V_109 ; V_10 ++ ) {
unsigned int V_131 = V_110 - V_113 ;
if ( V_112 <= 0 )
break;
if ( V_131 > V_112 )
V_131 = V_112 ;
if ( F_73 ( V_91 , V_4 , F_122 ( V_87 ) , V_131 ,
V_113 ) < V_131 )
break;
V_87 += V_131 ;
V_112 -= V_131 ;
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
return F_104 ( - V_171 ) ;
}
static void F_124 ( struct V_4 * V_4 , int V_186 )
{
struct V_31 * V_116 ;
const int V_188 = F_102 ( V_4 ) == V_162 ;
struct V_142 * V_143 = V_4 -> V_62 ;
int V_10 ;
char * V_49 = V_143 -> V_148 [ 0 ] . V_157 ;
F_87 (bvec, bio, i) {
char * V_189 = F_98 ( V_116 -> V_89 ) ;
if ( V_188 )
memcpy ( V_49 , V_189 , V_116 -> V_88 ) ;
F_89 ( V_116 -> V_89 ) ;
V_49 += V_116 -> V_88 ;
}
F_26 ( V_143 ) ;
F_32 ( V_4 ) ;
}
struct V_4 * F_125 ( struct V_90 * V_91 , void * V_87 , unsigned int V_112 ,
T_2 V_37 , int V_190 )
{
struct V_4 * V_4 ;
struct V_31 * V_116 ;
int V_10 ;
V_4 = F_106 ( V_91 , NULL , ( unsigned long ) V_87 , V_112 , 1 , V_37 ) ;
if ( F_114 ( V_4 ) )
return V_4 ;
if ( ! V_190 ) {
void * V_49 = V_87 ;
F_87 (bvec, bio, i) {
char * V_189 = F_98 ( V_116 -> V_89 ) ;
memcpy ( V_189 , V_49 , V_116 -> V_88 ) ;
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
F_131 ( & V_191 , V_59 ) ;
V_4 = V_192 ;
V_192 = NULL ;
F_132 ( & V_191 , V_59 ) ;
while ( V_4 ) {
struct V_4 * V_193 = V_4 -> V_62 ;
F_126 ( V_4 ) ;
F_128 ( V_4 ) ;
F_32 ( V_4 ) ;
V_4 = V_193 ;
}
}
void F_133 ( struct V_4 * V_4 )
{
struct V_31 * V_116 ;
int V_194 = 0 ;
int V_10 ;
F_87 (bvec, bio, i) {
struct V_111 * V_111 = V_116 -> V_89 ;
if ( F_134 ( V_111 ) || F_127 ( V_111 ) ) {
F_111 ( V_111 ) ;
V_116 -> V_89 = NULL ;
} else {
V_194 ++ ;
}
}
if ( V_194 ) {
unsigned long V_59 ;
F_131 ( & V_191 , V_59 ) ;
V_4 -> V_62 = V_192 ;
V_192 = V_4 ;
F_132 ( & V_191 , V_59 ) ;
F_135 ( & V_195 ) ;
} else {
F_32 ( V_4 ) ;
}
}
void F_136 ( int V_129 , unsigned long V_196 ,
struct V_197 * V_198 )
{
int V_199 = F_137 () ;
F_138 ( V_199 , V_198 ) ;
F_139 ( V_199 , V_198 , V_200 [ V_129 ] ) ;
F_140 ( V_199 , V_198 , V_196 [ V_129 ] , V_196 ) ;
F_141 ( V_198 , V_129 ) ;
F_142 () ;
}
void F_143 ( int V_129 , struct V_197 * V_198 ,
unsigned long V_201 )
{
unsigned long V_202 = V_203 - V_201 ;
int V_199 = F_137 () ;
F_140 ( V_199 , V_198 , V_204 [ V_129 ] , V_202 ) ;
F_138 ( V_199 , V_198 ) ;
F_144 ( V_198 , V_129 ) ;
F_142 () ;
}
void F_145 ( struct V_4 * V_205 )
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
F_146 ( V_56 , & V_4 -> V_55 ) ;
else if ( ! F_147 ( V_56 , & V_4 -> V_55 ) )
error = - V_206 ;
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
void F_148 ( struct V_4 * V_4 , int error )
{
F_35 ( & V_4 -> V_57 ) ;
F_31 ( V_4 , error ) ;
}
struct V_4 * F_149 ( struct V_4 * V_4 , int V_196 ,
T_2 V_207 , struct V_23 * V_24 )
{
struct V_4 * V_208 = NULL ;
F_34 ( V_196 <= 0 ) ;
F_34 ( V_196 >= F_150 ( V_4 ) ) ;
V_208 = F_61 ( V_4 , V_207 , V_24 ) ;
if ( ! V_208 )
return NULL ;
V_208 -> V_98 . V_102 = V_196 << 9 ;
if ( F_21 ( V_208 ) )
F_151 ( V_208 , 0 , V_196 ) ;
F_83 ( V_4 , V_208 -> V_98 . V_102 ) ;
return V_208 ;
}
void F_152 ( struct V_4 * V_4 , int V_113 , int V_209 )
{
V_209 <<= 9 ;
if ( V_113 == 0 && V_209 == V_4 -> V_98 . V_102 )
return;
F_146 ( V_92 , & V_4 -> V_55 ) ;
F_83 ( V_4 , V_113 << 9 ) ;
V_4 -> V_98 . V_102 = V_209 ;
}
T_1 * F_153 ( int V_210 )
{
struct V_35 * V_211 = V_28 + V_34 ;
return F_154 ( V_210 , V_211 -> V_5 ) ;
}
void F_155 ( struct V_23 * V_24 )
{
if ( V_24 -> V_74 )
F_156 ( V_24 -> V_74 ) ;
if ( V_24 -> V_54 )
F_157 ( V_24 -> V_54 ) ;
if ( V_24 -> V_51 )
F_157 ( V_24 -> V_51 ) ;
F_158 ( V_24 ) ;
F_6 ( V_24 ) ;
F_26 ( V_24 ) ;
}
static struct V_23 * F_159 ( unsigned int V_212 ,
unsigned int V_53 ,
bool V_213 )
{
unsigned int V_214 = V_80 * sizeof( struct V_31 ) ;
struct V_23 * V_24 ;
V_24 = F_160 ( sizeof( * V_24 ) , V_19 ) ;
if ( ! V_24 )
return NULL ;
V_24 -> V_53 = V_53 ;
F_161 ( & V_24 -> V_68 ) ;
F_43 ( & V_24 -> V_69 ) ;
F_162 ( & V_24 -> V_67 , F_36 ) ;
V_24 -> V_6 = F_1 ( V_53 + V_214 ) ;
if ( ! V_24 -> V_6 ) {
F_26 ( V_24 ) ;
return NULL ;
}
V_24 -> V_54 = F_154 ( V_212 , V_24 -> V_6 ) ;
if ( ! V_24 -> V_54 )
goto V_215;
if ( V_213 ) {
V_24 -> V_51 = F_153 ( V_212 ) ;
if ( ! V_24 -> V_51 )
goto V_215;
}
V_24 -> V_74 = F_163 ( L_3 , V_216 , 0 ) ;
if ( ! V_24 -> V_74 )
goto V_215;
return V_24 ;
V_215:
F_155 ( V_24 ) ;
return NULL ;
}
struct V_23 * F_164 ( unsigned int V_212 , unsigned int V_53 )
{
return F_159 ( V_212 , V_53 , true ) ;
}
struct V_23 * F_165 ( unsigned int V_212 , unsigned int V_53 )
{
return F_159 ( V_212 , V_53 , false ) ;
}
int F_166 ( struct V_4 * V_4 )
{
struct V_217 * V_218 ;
struct V_219 * V_220 ;
if ( V_4 -> V_221 )
return - V_222 ;
V_218 = V_73 -> V_217 ;
if ( ! V_218 )
return - V_223 ;
F_167 ( V_218 ) ;
V_4 -> V_221 = V_218 ;
F_168 () ;
V_220 = F_169 ( V_73 , V_224 ) ;
if ( V_220 && F_170 ( V_220 ) )
V_4 -> V_225 = V_220 ;
F_171 () ;
return 0 ;
}
void F_20 ( struct V_4 * V_4 )
{
if ( V_4 -> V_221 ) {
F_172 ( V_4 -> V_221 ) ;
V_4 -> V_221 = NULL ;
}
if ( V_4 -> V_225 ) {
F_173 ( V_4 -> V_225 ) ;
V_4 -> V_225 = NULL ;
}
}
static void T_4 F_174 ( void )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_33 ; V_10 ++ ) {
int V_209 ;
struct V_35 * V_36 = V_28 + V_10 ;
if ( V_36 -> V_29 <= V_80 ) {
V_36 -> V_5 = NULL ;
continue;
}
V_209 = V_36 -> V_29 * sizeof( struct V_31 ) ;
V_36 -> V_5 = F_4 ( V_36 -> V_20 , V_209 , 0 ,
V_22 | V_226 , NULL ) ;
}
}
static int T_4 F_175 ( void )
{
V_18 = 2 ;
V_13 = 0 ;
V_14 = F_160 ( V_18 * sizeof( struct V_6 ) , V_19 ) ;
if ( ! V_14 )
F_176 ( L_4 ) ;
F_177 () ;
F_174 () ;
V_227 = F_164 ( V_228 , 0 ) ;
if ( ! V_227 )
F_176 ( L_4 ) ;
if ( F_178 ( V_227 , V_228 ) )
F_176 ( L_5 ) ;
return 0 ;
}
