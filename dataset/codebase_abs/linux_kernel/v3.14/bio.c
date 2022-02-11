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
F_5 ( V_22 L_2 , V_7 -> V_20 , V_11 ) ;
V_7 -> V_5 = V_5 ;
V_7 -> V_16 = 1 ;
V_7 -> V_15 = V_3 ;
V_17:
F_6 ( & V_12 ) ;
return V_5 ;
}
static void F_7 ( struct V_23 * V_24 )
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
if ( F_8 ( ! V_7 , V_25 L_3 ) )
goto V_26;
F_9 ( ! V_7 -> V_16 ) ;
if ( -- V_7 -> V_16 )
goto V_26;
F_10 ( V_7 -> V_5 ) ;
V_7 -> V_5 = NULL ;
V_26:
F_6 ( & V_12 ) ;
}
unsigned int F_11 ( unsigned short V_27 )
{
return V_28 [ V_27 ] . V_29 ;
}
void F_12 ( T_1 * V_30 , struct V_31 * V_32 , unsigned int V_27 )
{
F_13 ( V_27 >= V_33 ) ;
if ( V_27 == V_34 )
F_14 ( V_32 , V_30 ) ;
else {
struct V_35 * V_36 = V_28 + V_27 ;
F_15 ( V_36 -> V_5 , V_32 ) ;
}
}
struct V_31 * F_16 ( T_2 V_37 , int V_38 , unsigned long * V_27 ,
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
V_39 = F_17 ( V_30 , V_37 ) ;
} else {
struct V_35 * V_36 = V_28 + * V_27 ;
T_2 V_42 = V_37 & ~ ( V_43 | V_44 ) ;
V_42 |= V_45 | V_46 | V_47 ;
V_39 = F_18 ( V_36 -> V_5 , V_42 ) ;
if ( F_19 ( ! V_39 && ( V_37 & V_43 ) ) ) {
* V_27 = V_34 ;
goto V_41;
}
}
return V_39 ;
}
static void F_20 ( struct V_4 * V_4 )
{
F_21 ( V_4 ) ;
if ( F_22 ( V_4 ) )
F_23 ( V_4 ) ;
}
static void F_24 ( struct V_4 * V_4 )
{
struct V_23 * V_24 = V_4 -> V_48 ;
void * V_49 ;
F_20 ( V_4 ) ;
if ( V_24 ) {
if ( F_25 ( V_4 , V_50 ) )
F_12 ( V_24 -> V_51 , V_4 -> V_52 , F_26 ( V_4 ) ) ;
V_49 = V_4 ;
V_49 -= V_24 -> V_53 ;
F_14 ( V_49 , V_24 -> V_54 ) ;
} else {
F_27 ( V_4 ) ;
}
}
void F_28 ( struct V_4 * V_4 )
{
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_55 = 1 << V_56 ;
F_29 ( & V_4 -> V_57 , 1 ) ;
F_29 ( & V_4 -> V_58 , 1 ) ;
}
void F_30 ( struct V_4 * V_4 )
{
unsigned long V_59 = V_4 -> V_55 & ( ~ 0UL << V_60 ) ;
F_20 ( V_4 ) ;
memset ( V_4 , 0 , V_61 ) ;
V_4 -> V_55 = V_59 | ( 1 << V_56 ) ;
F_29 ( & V_4 -> V_57 , 1 ) ;
}
static void F_31 ( struct V_4 * V_4 , int error )
{
F_32 ( V_4 -> V_62 , error ) ;
F_33 ( V_4 ) ;
}
void F_34 ( struct V_4 * V_4 , struct V_4 * V_63 )
{
F_35 ( V_4 -> V_62 || V_4 -> V_64 ) ;
V_4 -> V_62 = V_63 ;
V_4 -> V_64 = F_31 ;
F_36 ( & V_63 -> V_57 ) ;
}
static void F_37 ( struct V_65 * V_66 )
{
struct V_23 * V_24 = F_38 ( V_66 , struct V_23 , V_67 ) ;
struct V_4 * V_4 ;
while ( 1 ) {
F_39 ( & V_24 -> V_68 ) ;
V_4 = F_40 ( & V_24 -> V_69 ) ;
F_41 ( & V_24 -> V_68 ) ;
if ( ! V_4 )
break;
F_42 ( V_4 ) ;
}
}
static void F_43 ( struct V_23 * V_24 )
{
struct V_70 V_71 , V_72 ;
struct V_4 * V_4 ;
F_44 ( & V_71 ) ;
F_44 ( & V_72 ) ;
while ( ( V_4 = F_40 ( V_73 -> V_70 ) ) )
F_45 ( V_4 -> V_48 == V_24 ? & V_71 : & V_72 , V_4 ) ;
* V_73 -> V_70 = V_72 ;
F_39 ( & V_24 -> V_68 ) ;
F_46 ( & V_24 -> V_69 , & V_71 ) ;
F_41 ( & V_24 -> V_68 ) ;
F_47 ( V_24 -> V_74 , & V_24 -> V_67 ) ;
}
struct V_4 * F_48 ( T_2 V_37 , int V_75 , struct V_23 * V_24 )
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
V_49 = F_49 ( sizeof( struct V_4 ) +
V_75 * sizeof( struct V_31 ) ,
V_37 ) ;
V_53 = 0 ;
V_77 = V_75 ;
} else {
if ( V_73 -> V_70 && ! F_50 ( V_73 -> V_70 ) )
V_37 &= ~ V_43 ;
V_49 = F_17 ( V_24 -> V_54 , V_37 ) ;
if ( ! V_49 && V_37 != V_76 ) {
F_43 ( V_24 ) ;
V_37 = V_76 ;
V_49 = F_17 ( V_24 -> V_54 , V_37 ) ;
}
V_53 = V_24 -> V_53 ;
V_77 = V_80 ;
}
if ( F_19 ( ! V_49 ) )
return NULL ;
V_4 = V_49 + V_53 ;
F_28 ( V_4 ) ;
if ( V_75 > V_77 ) {
V_39 = F_16 ( V_37 , V_75 , & V_27 , V_24 -> V_51 ) ;
if ( ! V_39 && V_37 != V_76 ) {
F_43 ( V_24 ) ;
V_37 = V_76 ;
V_39 = F_16 ( V_37 , V_75 , & V_27 , V_24 -> V_51 ) ;
}
if ( F_19 ( ! V_39 ) )
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
F_14 ( V_49 , V_24 -> V_54 ) ;
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
void F_33 ( struct V_4 * V_4 )
{
F_13 ( ! F_56 ( & V_4 -> V_58 ) ) ;
if ( F_57 ( & V_4 -> V_58 ) )
F_24 ( V_4 ) ;
}
inline int F_58 ( struct V_90 * V_91 , struct V_4 * V_4 )
{
if ( F_19 ( ! F_25 ( V_4 , V_92 ) ) )
F_59 ( V_91 , V_4 ) ;
return V_4 -> V_93 ;
}
void F_60 ( struct V_4 * V_4 , struct V_4 * V_94 )
{
F_35 ( V_4 -> V_48 && F_26 ( V_4 ) != V_78 ) ;
V_4 -> V_95 = V_94 -> V_95 ;
V_4 -> V_55 |= 1 << V_96 ;
V_4 -> V_97 = V_94 -> V_97 ;
V_4 -> V_98 = V_94 -> V_98 ;
V_4 -> V_52 = V_94 -> V_52 ;
}
struct V_4 * F_61 ( struct V_4 * V_4 , T_2 V_37 , struct V_23 * V_24 )
{
struct V_4 * V_99 ;
V_99 = F_48 ( V_37 , 0 , V_24 ) ;
if ( ! V_99 )
return NULL ;
F_60 ( V_99 , V_4 ) ;
if ( F_22 ( V_4 ) ) {
int V_100 ;
V_100 = F_62 ( V_99 , V_4 , V_37 ) ;
if ( V_100 < 0 ) {
F_33 ( V_99 ) ;
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
V_4 = F_48 ( V_37 , F_64 ( V_94 ) , V_24 ) ;
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
if ( F_22 ( V_94 ) ) {
int V_100 ;
V_100 = F_62 ( V_4 , V_94 , V_37 ) ;
if ( V_100 < 0 ) {
F_33 ( V_4 ) ;
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
if ( F_19 ( F_25 ( V_4 , V_96 ) ) )
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
if ( V_4 -> V_106 && ( F_71 ( V_116 - 1 , V_116 ) ) )
V_4 -> V_55 &= ~ ( 1 << V_92 ) ;
V_4 -> V_106 ++ ;
V_4 -> V_93 ++ ;
V_123:
V_4 -> V_98 . V_102 += V_112 ;
return V_112 ;
}
int F_72 ( struct V_90 * V_91 , struct V_4 * V_4 , struct V_111 * V_111 ,
unsigned int V_112 , unsigned int V_113 )
{
return F_70 ( V_91 , V_4 , V_111 , V_112 , V_113 ,
F_73 ( V_91 ) ) ;
}
int F_74 ( struct V_4 * V_4 , struct V_111 * V_111 , unsigned int V_112 ,
unsigned int V_113 )
{
struct V_90 * V_91 = F_66 ( V_4 -> V_95 ) ;
return F_70 ( V_91 , V_4 , V_111 , V_112 , V_113 , F_69 ( V_91 ) ) ;
}
static void F_75 ( struct V_4 * V_4 , int error )
{
struct V_124 * V_100 = V_4 -> V_62 ;
V_100 -> error = error ;
F_76 ( & V_100 -> V_125 ) ;
}
int F_77 ( int V_126 , struct V_4 * V_4 )
{
struct V_124 V_100 ;
V_126 |= V_127 ;
F_78 ( & V_100 . V_125 ) ;
V_4 -> V_62 = & V_100 ;
V_4 -> V_64 = F_75 ;
F_79 ( V_126 , V_4 ) ;
F_80 ( & V_100 . V_125 ) ;
return V_100 . error ;
}
void F_81 ( struct V_4 * V_4 , unsigned V_128 )
{
if ( F_22 ( V_4 ) )
F_82 ( V_4 , V_128 ) ;
F_83 ( V_4 , & V_4 -> V_98 , V_128 ) ;
}
int F_84 ( struct V_4 * V_4 , T_2 V_37 )
{
int V_10 ;
struct V_31 * V_32 ;
F_85 (bv, bio, i) {
V_32 -> V_89 = F_86 ( V_37 ) ;
if ( ! V_32 -> V_89 ) {
while ( -- V_32 >= V_4 -> V_52 )
F_87 ( V_32 -> V_89 ) ;
return - V_129 ;
}
}
return 0 ;
}
void F_88 ( struct V_4 * V_130 , struct V_4 * V_131 )
{
struct V_85 V_132 , V_133 ;
struct V_31 V_134 , V_135 ;
void * V_136 , * V_137 ;
unsigned V_128 ;
V_132 = V_131 -> V_98 ;
V_133 = V_130 -> V_98 ;
while ( 1 ) {
if ( ! V_132 . V_102 ) {
V_131 = V_131 -> V_138 ;
if ( ! V_131 )
break;
V_132 = V_131 -> V_98 ;
}
if ( ! V_133 . V_102 ) {
V_130 = V_130 -> V_138 ;
if ( ! V_130 )
break;
V_133 = V_130 -> V_98 ;
}
V_134 = F_89 ( V_131 , V_132 ) ;
V_135 = F_89 ( V_130 , V_133 ) ;
V_128 = F_90 ( V_134 . V_88 , V_135 . V_88 ) ;
V_136 = F_91 ( V_134 . V_89 ) ;
V_137 = F_91 ( V_135 . V_89 ) ;
memcpy ( V_137 + V_135 . V_118 ,
V_136 + V_134 . V_118 ,
V_128 ) ;
F_92 ( V_137 ) ;
F_92 ( V_136 ) ;
F_83 ( V_131 , & V_132 , V_128 ) ;
F_83 ( V_130 , & V_133 , V_128 ) ;
}
}
static void F_93 ( struct V_139 * V_140 , struct V_4 * V_4 ,
struct V_141 * V_142 , int V_143 ,
int V_144 )
{
memcpy ( V_140 -> V_145 , V_142 , sizeof( struct V_141 ) * V_143 ) ;
V_140 -> V_146 = V_143 ;
V_140 -> V_144 = V_144 ;
V_4 -> V_62 = V_140 ;
}
static struct V_139 * F_94 ( int V_147 ,
unsigned int V_143 ,
T_2 V_37 )
{
if ( V_143 > V_79 )
return NULL ;
return F_49 ( sizeof( struct V_139 ) +
sizeof( struct V_141 ) * V_143 , V_37 ) ;
}
static int F_95 ( struct V_4 * V_4 , struct V_141 * V_142 , int V_143 ,
int V_148 , int V_149 , int V_150 )
{
int V_100 = 0 , V_10 ;
struct V_31 * V_116 ;
int V_151 = 0 ;
unsigned int V_152 = 0 ;
F_85 (bvec, bio, i) {
char * V_153 = F_96 ( V_116 -> V_89 ) ;
unsigned int V_88 = V_116 -> V_88 ;
while ( V_88 && V_151 < V_143 ) {
unsigned int V_128 ;
char T_3 * V_154 ;
V_128 = F_67 (unsigned int,
iov[iov_idx].iov_len - iov_off, bv_len) ;
V_154 = V_142 [ V_151 ] . V_155 + V_152 ;
if ( ! V_100 ) {
if ( V_148 )
V_100 = F_97 ( V_154 , V_153 ,
V_128 ) ;
if ( V_149 )
V_100 = F_98 ( V_153 , V_154 ,
V_128 ) ;
if ( V_100 )
V_100 = - V_156 ;
}
V_88 -= V_128 ;
V_153 += V_128 ;
V_154 += V_128 ;
V_152 += V_128 ;
if ( V_142 [ V_151 ] . V_157 == V_152 ) {
V_151 ++ ;
V_152 = 0 ;
}
}
if ( V_150 )
F_87 ( V_116 -> V_89 ) ;
}
return V_100 ;
}
int F_99 ( struct V_4 * V_4 )
{
struct V_139 * V_140 = V_4 -> V_62 ;
struct V_31 * V_116 ;
int V_100 = 0 , V_10 ;
if ( ! F_25 ( V_4 , V_158 ) ) {
if ( V_73 -> V_159 )
V_100 = F_95 ( V_4 , V_140 -> V_145 , V_140 -> V_146 ,
F_100 ( V_4 ) == V_160 ,
0 , V_140 -> V_144 ) ;
else if ( V_140 -> V_144 )
F_85 (bvec, bio, i)
F_87 ( V_116 -> V_89 ) ;
}
F_27 ( V_140 ) ;
F_33 ( V_4 ) ;
return V_100 ;
}
struct V_4 * F_101 ( struct V_90 * V_91 ,
struct V_161 * V_162 ,
struct V_141 * V_142 , int V_143 ,
int V_163 , T_2 V_37 )
{
struct V_139 * V_140 ;
struct V_31 * V_116 ;
struct V_111 * V_111 ;
struct V_4 * V_4 ;
int V_10 , V_100 ;
int V_109 = 0 ;
unsigned int V_112 = 0 ;
unsigned int V_113 = V_162 ? V_162 -> V_113 & ~ V_164 : 0 ;
for ( V_10 = 0 ; V_10 < V_143 ; V_10 ++ ) {
unsigned long V_165 ;
unsigned long V_166 ;
unsigned long V_167 ;
V_165 = ( unsigned long ) V_142 [ V_10 ] . V_155 ;
V_166 = ( V_165 + V_142 [ V_10 ] . V_157 + V_110 - 1 ) >> V_168 ;
V_167 = V_165 >> V_168 ;
if ( V_166 < V_167 )
return F_102 ( - V_169 ) ;
V_109 += V_166 - V_167 ;
V_112 += V_142 [ V_10 ] . V_157 ;
}
if ( V_113 )
V_109 ++ ;
V_140 = F_94 ( V_109 , V_143 , V_37 ) ;
if ( ! V_140 )
return F_102 ( - V_129 ) ;
V_100 = - V_129 ;
V_4 = F_103 ( V_37 , V_109 ) ;
if ( ! V_4 )
goto V_170;
if ( ! V_163 )
V_4 -> V_97 |= V_171 ;
V_100 = 0 ;
if ( V_162 ) {
V_109 = 1 << V_162 -> V_172 ;
V_10 = V_162 -> V_113 / V_110 ;
}
while ( V_112 ) {
unsigned int V_128 = V_110 ;
V_128 -= V_113 ;
if ( V_128 > V_112 )
V_128 = V_112 ;
if ( V_162 ) {
if ( V_10 == V_162 -> V_173 * V_109 ) {
V_100 = - V_129 ;
break;
}
V_111 = V_162 -> V_174 [ V_10 / V_109 ] ;
V_111 += ( V_10 % V_109 ) ;
V_10 ++ ;
} else {
V_111 = F_86 ( V_91 -> V_175 | V_37 ) ;
if ( ! V_111 ) {
V_100 = - V_129 ;
break;
}
}
if ( F_72 ( V_91 , V_4 , V_111 , V_128 , V_113 ) < V_128 )
break;
V_112 -= V_128 ;
V_113 = 0 ;
}
if ( V_100 )
goto V_176;
if ( ( ! V_163 && ( ! V_162 || ! V_162 -> V_177 ) ) ||
( V_162 && V_162 -> V_149 ) ) {
V_100 = F_95 ( V_4 , V_142 , V_143 , 0 , 1 , 0 ) ;
if ( V_100 )
goto V_176;
}
F_93 ( V_140 , V_4 , V_142 , V_143 , V_162 ? 0 : 1 ) ;
return V_4 ;
V_176:
if ( ! V_162 )
F_85 (bvec, bio, i)
F_87 ( V_116 -> V_89 ) ;
F_33 ( V_4 ) ;
V_170:
F_27 ( V_140 ) ;
return F_102 ( V_100 ) ;
}
struct V_4 * F_104 ( struct V_90 * V_91 , struct V_161 * V_162 ,
unsigned long V_165 , unsigned int V_112 ,
int V_163 , T_2 V_37 )
{
struct V_141 V_142 ;
V_142 . V_155 = ( void T_3 * ) V_165 ;
V_142 . V_157 = V_112 ;
return F_101 ( V_91 , V_162 , & V_142 , 1 , V_163 , V_37 ) ;
}
static struct V_4 * F_105 ( struct V_90 * V_91 ,
struct V_107 * V_108 ,
struct V_141 * V_142 , int V_143 ,
int V_163 , T_2 V_37 )
{
int V_10 , V_178 ;
int V_109 = 0 ;
struct V_111 * * V_174 ;
struct V_4 * V_4 ;
int V_179 = 0 ;
int V_100 , V_113 ;
for ( V_10 = 0 ; V_10 < V_143 ; V_10 ++ ) {
unsigned long V_165 = ( unsigned long ) V_142 [ V_10 ] . V_155 ;
unsigned long V_112 = V_142 [ V_10 ] . V_157 ;
unsigned long V_166 = ( V_165 + V_112 + V_110 - 1 ) >> V_168 ;
unsigned long V_167 = V_165 >> V_168 ;
if ( V_166 < V_167 )
return F_102 ( - V_169 ) ;
V_109 += V_166 - V_167 ;
if ( V_165 & F_106 ( V_91 ) )
return F_102 ( - V_169 ) ;
}
if ( ! V_109 )
return F_102 ( - V_169 ) ;
V_4 = F_103 ( V_37 , V_109 ) ;
if ( ! V_4 )
return F_102 ( - V_129 ) ;
V_100 = - V_129 ;
V_174 = F_107 ( V_109 , sizeof( struct V_111 * ) , V_37 ) ;
if ( ! V_174 )
goto V_26;
for ( V_10 = 0 ; V_10 < V_143 ; V_10 ++ ) {
unsigned long V_165 = ( unsigned long ) V_142 [ V_10 ] . V_155 ;
unsigned long V_112 = V_142 [ V_10 ] . V_157 ;
unsigned long V_166 = ( V_165 + V_112 + V_110 - 1 ) >> V_168 ;
unsigned long V_167 = V_165 >> V_168 ;
const int V_180 = V_166 - V_167 ;
const int V_181 = V_179 + V_180 ;
V_100 = F_108 ( V_165 , V_180 ,
V_163 , & V_174 [ V_179 ] ) ;
if ( V_100 < V_180 ) {
V_100 = - V_156 ;
goto V_182;
}
V_113 = V_165 & ~ V_164 ;
for ( V_178 = V_179 ; V_178 < V_181 ; V_178 ++ ) {
unsigned int V_128 = V_110 - V_113 ;
if ( V_112 <= 0 )
break;
if ( V_128 > V_112 )
V_128 = V_112 ;
if ( F_72 ( V_91 , V_4 , V_174 [ V_178 ] , V_128 , V_113 ) <
V_128 )
break;
V_112 -= V_128 ;
V_113 = 0 ;
}
V_179 = V_178 ;
while ( V_178 < V_181 )
F_109 ( V_174 [ V_178 ++ ] ) ;
}
F_27 ( V_174 ) ;
if ( ! V_163 )
V_4 -> V_97 |= V_171 ;
V_4 -> V_95 = V_108 ;
V_4 -> V_55 |= ( 1 << V_183 ) ;
return V_4 ;
V_182:
for ( V_10 = 0 ; V_10 < V_109 ; V_10 ++ ) {
if( ! V_174 [ V_10 ] )
break;
F_109 ( V_174 [ V_10 ] ) ;
}
V_26:
F_27 ( V_174 ) ;
F_33 ( V_4 ) ;
return F_102 ( V_100 ) ;
}
struct V_4 * F_110 ( struct V_90 * V_91 , struct V_107 * V_108 ,
unsigned long V_165 , unsigned int V_112 , int V_163 ,
T_2 V_37 )
{
struct V_141 V_142 ;
V_142 . V_155 = ( void T_3 * ) V_165 ;
V_142 . V_157 = V_112 ;
return F_111 ( V_91 , V_108 , & V_142 , 1 , V_163 , V_37 ) ;
}
struct V_4 * F_111 ( struct V_90 * V_91 , struct V_107 * V_108 ,
struct V_141 * V_142 , int V_143 ,
int V_163 , T_2 V_37 )
{
struct V_4 * V_4 ;
V_4 = F_105 ( V_91 , V_108 , V_142 , V_143 , V_163 ,
V_37 ) ;
if ( F_112 ( V_4 ) )
return V_4 ;
F_113 ( V_4 ) ;
return V_4 ;
}
static void F_114 ( struct V_4 * V_4 )
{
struct V_31 * V_116 ;
int V_10 ;
F_85 (bvec, bio, i) {
if ( F_100 ( V_4 ) == V_160 )
F_115 ( V_116 -> V_89 ) ;
F_109 ( V_116 -> V_89 ) ;
}
F_33 ( V_4 ) ;
}
void F_116 ( struct V_4 * V_4 )
{
F_114 ( V_4 ) ;
F_33 ( V_4 ) ;
}
static void F_117 ( struct V_4 * V_4 , int V_184 )
{
F_33 ( V_4 ) ;
}
static struct V_4 * F_118 ( struct V_90 * V_91 , void * V_87 ,
unsigned int V_112 , T_2 V_37 )
{
unsigned long V_185 = ( unsigned long ) V_87 ;
unsigned long V_166 = ( V_185 + V_112 + V_110 - 1 ) >> V_168 ;
unsigned long V_167 = V_185 >> V_168 ;
const int V_109 = V_166 - V_167 ;
int V_113 , V_10 ;
struct V_4 * V_4 ;
V_4 = F_103 ( V_37 , V_109 ) ;
if ( ! V_4 )
return F_102 ( - V_129 ) ;
V_113 = F_119 ( V_185 ) ;
for ( V_10 = 0 ; V_10 < V_109 ; V_10 ++ ) {
unsigned int V_128 = V_110 - V_113 ;
if ( V_112 <= 0 )
break;
if ( V_128 > V_112 )
V_128 = V_112 ;
if ( F_72 ( V_91 , V_4 , F_120 ( V_87 ) , V_128 ,
V_113 ) < V_128 )
break;
V_87 += V_128 ;
V_112 -= V_128 ;
V_113 = 0 ;
}
V_4 -> V_64 = F_117 ;
return V_4 ;
}
struct V_4 * F_121 ( struct V_90 * V_91 , void * V_87 , unsigned int V_112 ,
T_2 V_37 )
{
struct V_4 * V_4 ;
V_4 = F_118 ( V_91 , V_87 , V_112 , V_37 ) ;
if ( F_112 ( V_4 ) )
return V_4 ;
if ( V_4 -> V_98 . V_102 == V_112 )
return V_4 ;
F_33 ( V_4 ) ;
return F_102 ( - V_169 ) ;
}
static void F_122 ( struct V_4 * V_4 , int V_184 )
{
struct V_31 * V_116 ;
const int V_186 = F_100 ( V_4 ) == V_160 ;
struct V_139 * V_140 = V_4 -> V_62 ;
int V_10 ;
char * V_49 = V_140 -> V_145 [ 0 ] . V_155 ;
F_85 (bvec, bio, i) {
char * V_187 = F_96 ( V_116 -> V_89 ) ;
if ( V_186 )
memcpy ( V_49 , V_187 , V_116 -> V_88 ) ;
F_87 ( V_116 -> V_89 ) ;
V_49 += V_116 -> V_88 ;
}
F_27 ( V_140 ) ;
F_33 ( V_4 ) ;
}
struct V_4 * F_123 ( struct V_90 * V_91 , void * V_87 , unsigned int V_112 ,
T_2 V_37 , int V_188 )
{
struct V_4 * V_4 ;
struct V_31 * V_116 ;
int V_10 ;
V_4 = F_104 ( V_91 , NULL , ( unsigned long ) V_87 , V_112 , 1 , V_37 ) ;
if ( F_112 ( V_4 ) )
return V_4 ;
if ( ! V_188 ) {
void * V_49 = V_87 ;
F_85 (bvec, bio, i) {
char * V_187 = F_96 ( V_116 -> V_89 ) ;
memcpy ( V_187 , V_49 , V_116 -> V_88 ) ;
V_49 += V_116 -> V_88 ;
}
}
V_4 -> V_64 = F_122 ;
return V_4 ;
}
void F_124 ( struct V_4 * V_4 )
{
struct V_31 * V_116 ;
int V_10 ;
F_85 (bvec, bio, i) {
struct V_111 * V_111 = V_116 -> V_89 ;
if ( V_111 && ! F_125 ( V_111 ) )
F_115 ( V_111 ) ;
}
}
static void F_126 ( struct V_4 * V_4 )
{
struct V_31 * V_116 ;
int V_10 ;
F_85 (bvec, bio, i) {
struct V_111 * V_111 = V_116 -> V_89 ;
if ( V_111 )
F_127 ( V_111 ) ;
}
}
static void F_128 ( struct V_65 * V_66 )
{
unsigned long V_59 ;
struct V_4 * V_4 ;
F_129 ( & V_189 , V_59 ) ;
V_4 = V_190 ;
V_190 = NULL ;
F_130 ( & V_189 , V_59 ) ;
while ( V_4 ) {
struct V_4 * V_191 = V_4 -> V_62 ;
F_124 ( V_4 ) ;
F_126 ( V_4 ) ;
F_33 ( V_4 ) ;
V_4 = V_191 ;
}
}
void F_131 ( struct V_4 * V_4 )
{
struct V_31 * V_116 ;
int V_192 = 0 ;
int V_10 ;
F_85 (bvec, bio, i) {
struct V_111 * V_111 = V_116 -> V_89 ;
if ( F_132 ( V_111 ) || F_125 ( V_111 ) ) {
F_109 ( V_111 ) ;
V_116 -> V_89 = NULL ;
} else {
V_192 ++ ;
}
}
if ( V_192 ) {
unsigned long V_59 ;
F_129 ( & V_189 , V_59 ) ;
V_4 -> V_62 = V_190 ;
V_190 = V_4 ;
F_130 ( & V_189 , V_59 ) ;
F_133 ( & V_193 ) ;
} else {
F_33 ( V_4 ) ;
}
}
void F_134 ( struct V_4 * V_194 )
{
struct V_31 V_116 ;
struct V_85 V_86 ;
F_52 (bvec, bi, iter)
F_54 ( V_116 . V_89 ) ;
}
void F_32 ( struct V_4 * V_4 , int error )
{
while ( V_4 ) {
F_35 ( F_56 ( & V_4 -> V_57 ) <= 0 ) ;
if ( error )
F_135 ( V_56 , & V_4 -> V_55 ) ;
else if ( ! F_136 ( V_56 , & V_4 -> V_55 ) )
error = - V_195 ;
if ( ! F_57 ( & V_4 -> V_57 ) )
return;
if ( V_4 -> V_64 == F_31 ) {
struct V_4 * V_63 = V_4 -> V_62 ;
F_33 ( V_4 ) ;
V_4 = V_63 ;
} else {
if ( V_4 -> V_64 )
V_4 -> V_64 ( V_4 , error ) ;
V_4 = NULL ;
}
}
}
void F_137 ( struct V_4 * V_4 , int error )
{
F_36 ( & V_4 -> V_57 ) ;
F_32 ( V_4 , error ) ;
}
struct V_4 * F_138 ( struct V_4 * V_4 , int V_196 ,
T_2 V_197 , struct V_23 * V_24 )
{
struct V_4 * V_198 = NULL ;
F_35 ( V_196 <= 0 ) ;
F_35 ( V_196 >= F_139 ( V_4 ) ) ;
V_198 = F_61 ( V_4 , V_197 , V_24 ) ;
if ( ! V_198 )
return NULL ;
V_198 -> V_98 . V_102 = V_196 << 9 ;
if ( F_22 ( V_198 ) )
F_140 ( V_198 , 0 , V_196 ) ;
F_81 ( V_4 , V_198 -> V_98 . V_102 ) ;
return V_198 ;
}
void F_141 ( struct V_4 * V_4 , int V_113 , int V_199 )
{
V_199 <<= 9 ;
if ( V_113 == 0 && V_199 == V_4 -> V_98 . V_102 )
return;
F_135 ( V_92 , & V_4 -> V_55 ) ;
F_81 ( V_4 , V_113 << 9 ) ;
V_4 -> V_98 . V_102 = V_199 ;
}
T_1 * F_142 ( struct V_23 * V_24 , int V_200 )
{
struct V_35 * V_201 = V_28 + V_34 ;
return F_143 ( V_200 , V_201 -> V_5 ) ;
}
void F_144 ( struct V_23 * V_24 )
{
if ( V_24 -> V_74 )
F_145 ( V_24 -> V_74 ) ;
if ( V_24 -> V_54 )
F_146 ( V_24 -> V_54 ) ;
if ( V_24 -> V_51 )
F_146 ( V_24 -> V_51 ) ;
F_147 ( V_24 ) ;
F_7 ( V_24 ) ;
F_27 ( V_24 ) ;
}
struct V_23 * F_148 ( unsigned int V_202 , unsigned int V_53 )
{
unsigned int V_203 = V_80 * sizeof( struct V_31 ) ;
struct V_23 * V_24 ;
V_24 = F_149 ( sizeof( * V_24 ) , V_19 ) ;
if ( ! V_24 )
return NULL ;
V_24 -> V_53 = V_53 ;
F_150 ( & V_24 -> V_68 ) ;
F_44 ( & V_24 -> V_69 ) ;
F_151 ( & V_24 -> V_67 , F_37 ) ;
V_24 -> V_6 = F_1 ( V_53 + V_203 ) ;
if ( ! V_24 -> V_6 ) {
F_27 ( V_24 ) ;
return NULL ;
}
V_24 -> V_54 = F_143 ( V_202 , V_24 -> V_6 ) ;
if ( ! V_24 -> V_54 )
goto V_204;
V_24 -> V_51 = F_142 ( V_24 , V_202 ) ;
if ( ! V_24 -> V_51 )
goto V_204;
V_24 -> V_74 = F_152 ( L_4 , V_205 , 0 ) ;
if ( ! V_24 -> V_74 )
goto V_204;
return V_24 ;
V_204:
F_144 ( V_24 ) ;
return NULL ;
}
int F_153 ( struct V_4 * V_4 )
{
struct V_206 * V_207 ;
struct V_208 * V_209 ;
if ( V_4 -> V_210 )
return - V_211 ;
V_207 = V_73 -> V_206 ;
if ( ! V_207 )
return - V_212 ;
F_154 ( V_207 ) ;
V_4 -> V_210 = V_207 ;
F_155 () ;
V_209 = F_156 ( V_73 , V_213 ) ;
if ( V_209 && F_157 ( V_209 ) )
V_4 -> V_214 = V_209 ;
F_158 () ;
return 0 ;
}
void F_21 ( struct V_4 * V_4 )
{
if ( V_4 -> V_210 ) {
F_159 ( V_4 -> V_210 ) ;
V_4 -> V_210 = NULL ;
}
if ( V_4 -> V_214 ) {
F_160 ( V_4 -> V_214 ) ;
V_4 -> V_214 = NULL ;
}
}
static void T_4 F_161 ( void )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_33 ; V_10 ++ ) {
int V_199 ;
struct V_35 * V_36 = V_28 + V_10 ;
if ( V_36 -> V_29 <= V_80 ) {
V_36 -> V_5 = NULL ;
continue;
}
V_199 = V_36 -> V_29 * sizeof( struct V_31 ) ;
V_36 -> V_5 = F_4 ( V_36 -> V_20 , V_199 , 0 ,
V_21 | V_215 , NULL ) ;
}
}
static int T_4 F_162 ( void )
{
V_18 = 2 ;
V_13 = 0 ;
V_14 = F_149 ( V_18 * sizeof( struct V_6 ) , V_19 ) ;
if ( ! V_14 )
F_163 ( L_5 ) ;
F_164 () ;
F_161 () ;
V_216 = F_148 ( V_217 , 0 ) ;
if ( ! V_216 )
F_163 ( L_5 ) ;
if ( F_165 ( V_216 , V_217 ) )
F_163 ( L_6 ) ;
return 0 ;
}
