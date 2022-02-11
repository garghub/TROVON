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
}
void F_30 ( struct V_4 * V_4 )
{
unsigned long V_58 = V_4 -> V_55 & ( ~ 0UL << V_59 ) ;
F_20 ( V_4 ) ;
memset ( V_4 , 0 , V_60 ) ;
V_4 -> V_55 = V_58 | ( 1 << V_56 ) ;
}
static void F_31 ( struct V_61 * V_62 )
{
struct V_23 * V_24 = F_32 ( V_62 , struct V_23 , V_63 ) ;
struct V_4 * V_4 ;
while ( 1 ) {
F_33 ( & V_24 -> V_64 ) ;
V_4 = F_34 ( & V_24 -> V_65 ) ;
F_35 ( & V_24 -> V_64 ) ;
if ( ! V_4 )
break;
F_36 ( V_4 ) ;
}
}
static void F_37 ( struct V_23 * V_24 )
{
struct V_66 V_67 , V_68 ;
struct V_4 * V_4 ;
F_38 ( & V_67 ) ;
F_38 ( & V_68 ) ;
while ( ( V_4 = F_34 ( V_69 -> V_66 ) ) )
F_39 ( V_4 -> V_48 == V_24 ? & V_67 : & V_68 , V_4 ) ;
* V_69 -> V_66 = V_68 ;
F_33 ( & V_24 -> V_64 ) ;
F_40 ( & V_24 -> V_65 , & V_67 ) ;
F_35 ( & V_24 -> V_64 ) ;
F_41 ( V_24 -> V_70 , & V_24 -> V_63 ) ;
}
struct V_4 * F_42 ( T_2 V_37 , int V_71 , struct V_23 * V_24 )
{
T_2 V_72 = V_37 ;
unsigned V_53 ;
unsigned V_73 ;
unsigned long V_27 = V_74 ;
struct V_31 * V_39 = NULL ;
struct V_4 * V_4 ;
void * V_49 ;
if ( ! V_24 ) {
if ( V_71 > V_75 )
return NULL ;
V_49 = F_43 ( sizeof( struct V_4 ) +
V_71 * sizeof( struct V_31 ) ,
V_37 ) ;
V_53 = 0 ;
V_73 = V_71 ;
} else {
if ( V_69 -> V_66 && ! F_44 ( V_69 -> V_66 ) )
V_37 &= ~ V_43 ;
V_49 = F_17 ( V_24 -> V_54 , V_37 ) ;
if ( ! V_49 && V_37 != V_72 ) {
F_37 ( V_24 ) ;
V_37 = V_72 ;
V_49 = F_17 ( V_24 -> V_54 , V_37 ) ;
}
V_53 = V_24 -> V_53 ;
V_73 = V_76 ;
}
if ( F_19 ( ! V_49 ) )
return NULL ;
V_4 = V_49 + V_53 ;
F_28 ( V_4 ) ;
if ( V_71 > V_73 ) {
V_39 = F_16 ( V_37 , V_71 , & V_27 , V_24 -> V_51 ) ;
if ( ! V_39 && V_37 != V_72 ) {
F_37 ( V_24 ) ;
V_37 = V_72 ;
V_39 = F_16 ( V_37 , V_71 , & V_27 , V_24 -> V_51 ) ;
}
if ( F_19 ( ! V_39 ) )
goto V_77;
V_4 -> V_55 |= 1 << V_50 ;
} else if ( V_71 ) {
V_39 = V_4 -> V_78 ;
}
V_4 -> V_48 = V_24 ;
V_4 -> V_55 |= V_27 << V_79 ;
V_4 -> V_80 = V_71 ;
V_4 -> V_52 = V_39 ;
return V_4 ;
V_77:
F_14 ( V_49 , V_24 -> V_54 ) ;
return NULL ;
}
void F_45 ( struct V_4 * V_4 )
{
unsigned long V_58 ;
struct V_31 * V_32 ;
int V_10 ;
F_46 (bv, bio, i) {
char * V_81 = F_47 ( V_32 , & V_58 ) ;
memset ( V_81 , 0 , V_32 -> V_82 ) ;
F_48 ( V_32 -> V_83 ) ;
F_49 ( V_81 , & V_58 ) ;
}
}
void F_50 ( struct V_4 * V_4 )
{
F_13 ( ! F_51 ( & V_4 -> V_57 ) ) ;
if ( F_52 ( & V_4 -> V_57 ) )
F_24 ( V_4 ) ;
}
inline int F_53 ( struct V_84 * V_85 , struct V_4 * V_4 )
{
if ( F_19 ( ! F_25 ( V_4 , V_86 ) ) )
F_54 ( V_85 , V_4 ) ;
return V_4 -> V_87 ;
}
void F_55 ( struct V_4 * V_4 , struct V_4 * V_88 )
{
memcpy ( V_4 -> V_52 , V_88 -> V_52 ,
V_88 -> V_80 * sizeof( struct V_31 ) ) ;
V_4 -> V_89 = V_88 -> V_89 ;
V_4 -> V_90 = V_88 -> V_90 ;
V_4 -> V_55 |= 1 << V_91 ;
V_4 -> V_92 = V_88 -> V_92 ;
V_4 -> V_93 = V_88 -> V_93 ;
V_4 -> V_94 = V_88 -> V_94 ;
V_4 -> V_95 = V_88 -> V_95 ;
}
struct V_4 * F_56 ( struct V_4 * V_4 , T_2 V_37 ,
struct V_23 * V_24 )
{
struct V_4 * V_96 ;
V_96 = F_42 ( V_37 , V_4 -> V_80 , V_24 ) ;
if ( ! V_96 )
return NULL ;
F_55 ( V_96 , V_4 ) ;
if ( F_22 ( V_4 ) ) {
int V_97 ;
V_97 = F_57 ( V_96 , V_4 , V_37 ) ;
if ( V_97 < 0 ) {
F_50 ( V_96 ) ;
return NULL ;
}
}
return V_96 ;
}
int F_58 ( struct V_98 * V_99 )
{
struct V_84 * V_85 = F_59 ( V_99 ) ;
int V_100 ;
V_100 = F_60 ( unsigned ,
F_61 ( V_85 ) ,
F_62 ( V_85 ) / ( V_101 >> 9 ) + 1 ) ;
return F_60 ( unsigned , V_100 , V_40 ) ;
}
static int F_63 ( struct V_84 * V_85 , struct V_4 * V_4 , struct V_102
* V_102 , unsigned int V_103 , unsigned int V_104 ,
unsigned short V_105 )
{
int V_106 = 0 ;
struct V_31 * V_107 ;
if ( F_19 ( F_25 ( V_4 , V_91 ) ) )
return 0 ;
if ( ( ( V_4 -> V_94 + V_103 ) >> 9 ) > V_105 )
return 0 ;
if ( V_4 -> V_93 > 0 ) {
struct V_31 * V_108 = & V_4 -> V_52 [ V_4 -> V_93 - 1 ] ;
if ( V_102 == V_108 -> V_83 &&
V_104 == V_108 -> V_109 + V_108 -> V_82 ) {
unsigned int V_110 = V_108 -> V_82 ;
V_108 -> V_82 += V_103 ;
if ( V_85 -> V_111 ) {
struct V_112 V_113 = {
. V_90 = V_4 -> V_90 ,
. V_89 = V_4 -> V_89 ,
. V_94 = V_4 -> V_94 - V_110 ,
. V_92 = V_4 -> V_92 ,
} ;
if ( V_85 -> V_111 ( V_85 , & V_113 , V_108 ) < V_108 -> V_82 ) {
V_108 -> V_82 -= V_103 ;
return 0 ;
}
}
goto V_114;
}
}
if ( V_4 -> V_93 >= V_4 -> V_80 )
return 0 ;
while ( V_4 -> V_87 >= F_61 ( V_85 ) ) {
if ( V_106 )
return 0 ;
V_106 = 1 ;
F_54 ( V_85 , V_4 ) ;
}
V_107 = & V_4 -> V_52 [ V_4 -> V_93 ] ;
V_107 -> V_83 = V_102 ;
V_107 -> V_82 = V_103 ;
V_107 -> V_109 = V_104 ;
if ( V_85 -> V_111 ) {
struct V_112 V_113 = {
. V_90 = V_4 -> V_90 ,
. V_89 = V_4 -> V_89 ,
. V_94 = V_4 -> V_94 ,
. V_92 = V_4 -> V_92 ,
} ;
if ( V_85 -> V_111 ( V_85 , & V_113 , V_107 ) < V_107 -> V_82 ) {
V_107 -> V_83 = NULL ;
V_107 -> V_82 = 0 ;
V_107 -> V_109 = 0 ;
return 0 ;
}
}
if ( V_4 -> V_93 && ( F_64 ( V_107 - 1 , V_107 ) ) )
V_4 -> V_55 &= ~ ( 1 << V_86 ) ;
V_4 -> V_93 ++ ;
V_4 -> V_87 ++ ;
V_114:
V_4 -> V_94 += V_103 ;
return V_103 ;
}
int F_65 ( struct V_84 * V_85 , struct V_4 * V_4 , struct V_102 * V_102 ,
unsigned int V_103 , unsigned int V_104 )
{
return F_63 ( V_85 , V_4 , V_102 , V_103 , V_104 ,
F_66 ( V_85 ) ) ;
}
int F_67 ( struct V_4 * V_4 , struct V_102 * V_102 , unsigned int V_103 ,
unsigned int V_104 )
{
struct V_84 * V_85 = F_59 ( V_4 -> V_90 ) ;
return F_63 ( V_85 , V_4 , V_102 , V_103 , V_104 , F_62 ( V_85 ) ) ;
}
static void F_68 ( struct V_4 * V_4 , int error )
{
struct V_115 * V_97 = V_4 -> V_116 ;
V_97 -> error = error ;
F_69 ( & V_97 -> V_117 ) ;
}
int F_70 ( int V_118 , struct V_4 * V_4 )
{
struct V_115 V_97 ;
V_118 |= V_119 ;
F_71 ( & V_97 . V_117 ) ;
V_4 -> V_116 = & V_97 ;
V_4 -> V_120 = F_68 ;
F_72 ( V_118 , V_4 ) ;
F_73 ( & V_97 . V_117 ) ;
return V_97 . error ;
}
void F_74 ( struct V_4 * V_4 , unsigned V_121 )
{
if ( F_22 ( V_4 ) )
F_75 ( V_4 , V_121 ) ;
V_4 -> V_89 += V_121 >> 9 ;
V_4 -> V_94 -= V_121 ;
if ( V_4 -> V_92 & V_122 )
return;
while ( V_121 ) {
if ( F_19 ( V_4 -> V_95 >= V_4 -> V_93 ) ) {
F_76 ( 1 , L_4 ,
V_4 -> V_95 , V_4 -> V_93 ) ;
break;
}
if ( V_121 >= F_77 ( V_4 ) -> V_82 ) {
V_121 -= F_77 ( V_4 ) -> V_82 ;
V_4 -> V_95 ++ ;
} else {
F_77 ( V_4 ) -> V_82 -= V_121 ;
F_77 ( V_4 ) -> V_109 += V_121 ;
V_121 = 0 ;
}
}
}
int F_78 ( struct V_4 * V_4 , T_2 V_37 )
{
int V_10 ;
struct V_31 * V_32 ;
F_79 (bv, bio, i) {
V_32 -> V_83 = F_80 ( V_37 ) ;
if ( ! V_32 -> V_83 ) {
while ( -- V_32 >= V_4 -> V_52 )
F_81 ( V_32 -> V_83 ) ;
return - V_123 ;
}
}
return 0 ;
}
void F_82 ( struct V_4 * V_124 , struct V_4 * V_125 )
{
struct V_31 * V_126 , * V_127 ;
unsigned V_128 , V_129 , V_121 ;
void * V_130 , * V_131 ;
V_126 = F_77 ( V_125 ) ;
V_127 = F_77 ( V_124 ) ;
V_128 = V_126 -> V_109 ;
V_129 = V_127 -> V_109 ;
while ( 1 ) {
if ( V_128 == V_126 -> V_109 + V_126 -> V_82 ) {
V_126 ++ ;
if ( V_126 == F_83 ( V_125 , V_125 -> V_93 ) ) {
V_125 = V_125 -> V_132 ;
if ( ! V_125 )
break;
V_126 = F_77 ( V_125 ) ;
}
V_128 = V_126 -> V_109 ;
}
if ( V_129 == V_127 -> V_109 + V_127 -> V_82 ) {
V_127 ++ ;
if ( V_127 == F_83 ( V_124 , V_124 -> V_93 ) ) {
V_124 = V_124 -> V_132 ;
if ( ! V_124 )
break;
V_127 = F_77 ( V_124 ) ;
}
V_129 = V_127 -> V_109 ;
}
V_121 = F_84 ( V_127 -> V_109 + V_127 -> V_82 - V_129 ,
V_126 -> V_109 + V_126 -> V_82 - V_128 ) ;
V_130 = F_85 ( V_126 -> V_83 ) ;
V_131 = F_85 ( V_127 -> V_83 ) ;
memcpy ( V_131 + V_127 -> V_109 ,
V_130 + V_126 -> V_109 ,
V_121 ) ;
F_86 ( V_131 ) ;
F_86 ( V_130 ) ;
V_128 += V_121 ;
V_129 += V_121 ;
}
}
static void F_87 ( struct V_133 * V_134 , struct V_4 * V_4 ,
struct V_135 * V_136 , int V_137 ,
int V_138 )
{
memcpy ( V_134 -> V_139 , V_4 -> V_52 , sizeof( struct V_31 ) * V_4 -> V_93 ) ;
memcpy ( V_134 -> V_140 , V_136 , sizeof( struct V_135 ) * V_137 ) ;
V_134 -> V_141 = V_137 ;
V_134 -> V_138 = V_138 ;
V_4 -> V_116 = V_134 ;
}
static void F_88 ( struct V_133 * V_134 )
{
F_27 ( V_134 -> V_139 ) ;
F_27 ( V_134 -> V_140 ) ;
F_27 ( V_134 ) ;
}
static struct V_133 * F_89 ( int V_142 ,
unsigned int V_137 ,
T_2 V_37 )
{
struct V_133 * V_134 ;
if ( V_137 > V_75 )
return NULL ;
V_134 = F_43 ( sizeof( * V_134 ) , V_37 ) ;
if ( ! V_134 )
return NULL ;
V_134 -> V_139 = F_43 ( sizeof( struct V_31 ) * V_142 , V_37 ) ;
if ( ! V_134 -> V_139 ) {
F_27 ( V_134 ) ;
return NULL ;
}
V_134 -> V_140 = F_43 ( sizeof( struct V_135 ) * V_137 , V_37 ) ;
if ( V_134 -> V_140 )
return V_134 ;
F_27 ( V_134 -> V_139 ) ;
F_27 ( V_134 ) ;
return NULL ;
}
static int F_90 ( struct V_4 * V_4 , struct V_31 * V_139 ,
struct V_135 * V_136 , int V_137 ,
int V_143 , int V_144 , int V_145 )
{
int V_97 = 0 , V_10 ;
struct V_31 * V_107 ;
int V_146 = 0 ;
unsigned int V_147 = 0 ;
F_79 (bvec, bio, i) {
char * V_148 = F_91 ( V_107 -> V_83 ) ;
unsigned int V_82 = V_139 [ V_10 ] . V_82 ;
while ( V_82 && V_146 < V_137 ) {
unsigned int V_121 ;
char T_3 * V_149 ;
V_121 = F_60 (unsigned int,
iov[iov_idx].iov_len - iov_off, bv_len) ;
V_149 = V_136 [ V_146 ] . V_150 + V_147 ;
if ( ! V_97 ) {
if ( V_143 )
V_97 = F_92 ( V_149 , V_148 ,
V_121 ) ;
if ( V_144 )
V_97 = F_93 ( V_148 , V_149 ,
V_121 ) ;
if ( V_97 )
V_97 = - V_151 ;
}
V_82 -= V_121 ;
V_148 += V_121 ;
V_149 += V_121 ;
V_147 += V_121 ;
if ( V_136 [ V_146 ] . V_152 == V_147 ) {
V_146 ++ ;
V_147 = 0 ;
}
}
if ( V_145 )
F_81 ( V_107 -> V_83 ) ;
}
return V_97 ;
}
int F_94 ( struct V_4 * V_4 )
{
struct V_133 * V_134 = V_4 -> V_116 ;
struct V_31 * V_107 ;
int V_97 = 0 , V_10 ;
if ( ! F_25 ( V_4 , V_153 ) ) {
if ( V_69 -> V_154 )
V_97 = F_90 ( V_4 , V_134 -> V_139 , V_134 -> V_140 ,
V_134 -> V_141 , F_95 ( V_4 ) == V_155 ,
0 , V_134 -> V_138 ) ;
else if ( V_134 -> V_138 )
F_79 (bvec, bio, i)
F_81 ( V_107 -> V_83 ) ;
}
F_88 ( V_134 ) ;
F_50 ( V_4 ) ;
return V_97 ;
}
struct V_4 * F_96 ( struct V_84 * V_85 ,
struct V_156 * V_157 ,
struct V_135 * V_136 , int V_137 ,
int V_158 , T_2 V_37 )
{
struct V_133 * V_134 ;
struct V_31 * V_107 ;
struct V_102 * V_102 ;
struct V_4 * V_4 ;
int V_10 , V_97 ;
int V_100 = 0 ;
unsigned int V_103 = 0 ;
unsigned int V_104 = V_157 ? V_157 -> V_104 & ~ V_159 : 0 ;
for ( V_10 = 0 ; V_10 < V_137 ; V_10 ++ ) {
unsigned long V_160 ;
unsigned long V_161 ;
unsigned long V_162 ;
V_160 = ( unsigned long ) V_136 [ V_10 ] . V_150 ;
V_161 = ( V_160 + V_136 [ V_10 ] . V_152 + V_101 - 1 ) >> V_163 ;
V_162 = V_160 >> V_163 ;
if ( V_161 < V_162 )
return F_97 ( - V_164 ) ;
V_100 += V_161 - V_162 ;
V_103 += V_136 [ V_10 ] . V_152 ;
}
if ( V_104 )
V_100 ++ ;
V_134 = F_89 ( V_100 , V_137 , V_37 ) ;
if ( ! V_134 )
return F_97 ( - V_123 ) ;
V_97 = - V_123 ;
V_4 = F_98 ( V_37 , V_100 ) ;
if ( ! V_4 )
goto V_165;
if ( ! V_158 )
V_4 -> V_92 |= V_166 ;
V_97 = 0 ;
if ( V_157 ) {
V_100 = 1 << V_157 -> V_167 ;
V_10 = V_157 -> V_104 / V_101 ;
}
while ( V_103 ) {
unsigned int V_121 = V_101 ;
V_121 -= V_104 ;
if ( V_121 > V_103 )
V_121 = V_103 ;
if ( V_157 ) {
if ( V_10 == V_157 -> V_168 * V_100 ) {
V_97 = - V_123 ;
break;
}
V_102 = V_157 -> V_169 [ V_10 / V_100 ] ;
V_102 += ( V_10 % V_100 ) ;
V_10 ++ ;
} else {
V_102 = F_80 ( V_85 -> V_170 | V_37 ) ;
if ( ! V_102 ) {
V_97 = - V_123 ;
break;
}
}
if ( F_65 ( V_85 , V_4 , V_102 , V_121 , V_104 ) < V_121 )
break;
V_103 -= V_121 ;
V_104 = 0 ;
}
if ( V_97 )
goto V_171;
if ( ( ! V_158 && ( ! V_157 || ! V_157 -> V_172 ) ) ||
( V_157 && V_157 -> V_144 ) ) {
V_97 = F_90 ( V_4 , V_4 -> V_52 , V_136 , V_137 , 0 , 1 , 0 ) ;
if ( V_97 )
goto V_171;
}
F_87 ( V_134 , V_4 , V_136 , V_137 , V_157 ? 0 : 1 ) ;
return V_4 ;
V_171:
if ( ! V_157 )
F_79 (bvec, bio, i)
F_81 ( V_107 -> V_83 ) ;
F_50 ( V_4 ) ;
V_165:
F_88 ( V_134 ) ;
return F_97 ( V_97 ) ;
}
struct V_4 * F_99 ( struct V_84 * V_85 , struct V_156 * V_157 ,
unsigned long V_160 , unsigned int V_103 ,
int V_158 , T_2 V_37 )
{
struct V_135 V_136 ;
V_136 . V_150 = ( void T_3 * ) V_160 ;
V_136 . V_152 = V_103 ;
return F_96 ( V_85 , V_157 , & V_136 , 1 , V_158 , V_37 ) ;
}
static struct V_4 * F_100 ( struct V_84 * V_85 ,
struct V_98 * V_99 ,
struct V_135 * V_136 , int V_137 ,
int V_158 , T_2 V_37 )
{
int V_10 , V_173 ;
int V_100 = 0 ;
struct V_102 * * V_169 ;
struct V_4 * V_4 ;
int V_174 = 0 ;
int V_97 , V_104 ;
for ( V_10 = 0 ; V_10 < V_137 ; V_10 ++ ) {
unsigned long V_160 = ( unsigned long ) V_136 [ V_10 ] . V_150 ;
unsigned long V_103 = V_136 [ V_10 ] . V_152 ;
unsigned long V_161 = ( V_160 + V_103 + V_101 - 1 ) >> V_163 ;
unsigned long V_162 = V_160 >> V_163 ;
if ( V_161 < V_162 )
return F_97 ( - V_164 ) ;
V_100 += V_161 - V_162 ;
if ( V_160 & F_101 ( V_85 ) )
return F_97 ( - V_164 ) ;
}
if ( ! V_100 )
return F_97 ( - V_164 ) ;
V_4 = F_98 ( V_37 , V_100 ) ;
if ( ! V_4 )
return F_97 ( - V_123 ) ;
V_97 = - V_123 ;
V_169 = F_102 ( V_100 , sizeof( struct V_102 * ) , V_37 ) ;
if ( ! V_169 )
goto V_26;
for ( V_10 = 0 ; V_10 < V_137 ; V_10 ++ ) {
unsigned long V_160 = ( unsigned long ) V_136 [ V_10 ] . V_150 ;
unsigned long V_103 = V_136 [ V_10 ] . V_152 ;
unsigned long V_161 = ( V_160 + V_103 + V_101 - 1 ) >> V_163 ;
unsigned long V_162 = V_160 >> V_163 ;
const int V_175 = V_161 - V_162 ;
const int V_176 = V_174 + V_175 ;
V_97 = F_103 ( V_160 , V_175 ,
V_158 , & V_169 [ V_174 ] ) ;
if ( V_97 < V_175 ) {
V_97 = - V_151 ;
goto V_177;
}
V_104 = V_160 & ~ V_159 ;
for ( V_173 = V_174 ; V_173 < V_176 ; V_173 ++ ) {
unsigned int V_121 = V_101 - V_104 ;
if ( V_103 <= 0 )
break;
if ( V_121 > V_103 )
V_121 = V_103 ;
if ( F_65 ( V_85 , V_4 , V_169 [ V_173 ] , V_121 , V_104 ) <
V_121 )
break;
V_103 -= V_121 ;
V_104 = 0 ;
}
V_174 = V_173 ;
while ( V_173 < V_176 )
F_104 ( V_169 [ V_173 ++ ] ) ;
}
F_27 ( V_169 ) ;
if ( ! V_158 )
V_4 -> V_92 |= V_166 ;
V_4 -> V_90 = V_99 ;
V_4 -> V_55 |= ( 1 << V_178 ) ;
return V_4 ;
V_177:
for ( V_10 = 0 ; V_10 < V_100 ; V_10 ++ ) {
if( ! V_169 [ V_10 ] )
break;
F_104 ( V_169 [ V_10 ] ) ;
}
V_26:
F_27 ( V_169 ) ;
F_50 ( V_4 ) ;
return F_97 ( V_97 ) ;
}
struct V_4 * F_105 ( struct V_84 * V_85 , struct V_98 * V_99 ,
unsigned long V_160 , unsigned int V_103 , int V_158 ,
T_2 V_37 )
{
struct V_135 V_136 ;
V_136 . V_150 = ( void T_3 * ) V_160 ;
V_136 . V_152 = V_103 ;
return F_106 ( V_85 , V_99 , & V_136 , 1 , V_158 , V_37 ) ;
}
struct V_4 * F_106 ( struct V_84 * V_85 , struct V_98 * V_99 ,
struct V_135 * V_136 , int V_137 ,
int V_158 , T_2 V_37 )
{
struct V_4 * V_4 ;
V_4 = F_100 ( V_85 , V_99 , V_136 , V_137 , V_158 ,
V_37 ) ;
if ( F_107 ( V_4 ) )
return V_4 ;
F_108 ( V_4 ) ;
return V_4 ;
}
static void F_109 ( struct V_4 * V_4 )
{
struct V_31 * V_107 ;
int V_10 ;
F_79 (bvec, bio, i) {
if ( F_95 ( V_4 ) == V_155 )
F_110 ( V_107 -> V_83 ) ;
F_104 ( V_107 -> V_83 ) ;
}
F_50 ( V_4 ) ;
}
void F_111 ( struct V_4 * V_4 )
{
F_109 ( V_4 ) ;
F_50 ( V_4 ) ;
}
static void F_112 ( struct V_4 * V_4 , int V_179 )
{
F_50 ( V_4 ) ;
}
static struct V_4 * F_113 ( struct V_84 * V_85 , void * V_81 ,
unsigned int V_103 , T_2 V_37 )
{
unsigned long V_180 = ( unsigned long ) V_81 ;
unsigned long V_161 = ( V_180 + V_103 + V_101 - 1 ) >> V_163 ;
unsigned long V_162 = V_180 >> V_163 ;
const int V_100 = V_161 - V_162 ;
int V_104 , V_10 ;
struct V_4 * V_4 ;
V_4 = F_98 ( V_37 , V_100 ) ;
if ( ! V_4 )
return F_97 ( - V_123 ) ;
V_104 = F_114 ( V_180 ) ;
for ( V_10 = 0 ; V_10 < V_100 ; V_10 ++ ) {
unsigned int V_121 = V_101 - V_104 ;
if ( V_103 <= 0 )
break;
if ( V_121 > V_103 )
V_121 = V_103 ;
if ( F_65 ( V_85 , V_4 , F_115 ( V_81 ) , V_121 ,
V_104 ) < V_121 )
break;
V_81 += V_121 ;
V_103 -= V_121 ;
V_104 = 0 ;
}
V_4 -> V_120 = F_112 ;
return V_4 ;
}
struct V_4 * F_116 ( struct V_84 * V_85 , void * V_81 , unsigned int V_103 ,
T_2 V_37 )
{
struct V_4 * V_4 ;
V_4 = F_113 ( V_85 , V_81 , V_103 , V_37 ) ;
if ( F_107 ( V_4 ) )
return V_4 ;
if ( V_4 -> V_94 == V_103 )
return V_4 ;
F_50 ( V_4 ) ;
return F_97 ( - V_164 ) ;
}
static void F_117 ( struct V_4 * V_4 , int V_179 )
{
struct V_31 * V_107 ;
const int V_181 = F_95 ( V_4 ) == V_155 ;
struct V_133 * V_134 = V_4 -> V_116 ;
int V_10 ;
char * V_49 = V_134 -> V_140 [ 0 ] . V_150 ;
F_79 (bvec, bio, i) {
char * V_182 = F_91 ( V_107 -> V_83 ) ;
int V_103 = V_134 -> V_139 [ V_10 ] . V_82 ;
if ( V_181 )
memcpy ( V_49 , V_182 , V_103 ) ;
F_81 ( V_107 -> V_83 ) ;
V_49 += V_103 ;
}
F_88 ( V_134 ) ;
F_50 ( V_4 ) ;
}
struct V_4 * F_118 ( struct V_84 * V_85 , void * V_81 , unsigned int V_103 ,
T_2 V_37 , int V_183 )
{
struct V_4 * V_4 ;
struct V_31 * V_107 ;
int V_10 ;
V_4 = F_99 ( V_85 , NULL , ( unsigned long ) V_81 , V_103 , 1 , V_37 ) ;
if ( F_107 ( V_4 ) )
return V_4 ;
if ( ! V_183 ) {
void * V_49 = V_81 ;
F_79 (bvec, bio, i) {
char * V_182 = F_91 ( V_107 -> V_83 ) ;
memcpy ( V_182 , V_49 , V_107 -> V_82 ) ;
V_49 += V_107 -> V_82 ;
}
}
V_4 -> V_120 = F_117 ;
return V_4 ;
}
void F_119 ( struct V_4 * V_4 )
{
struct V_31 * V_107 ;
int V_10 ;
F_79 (bvec, bio, i) {
struct V_102 * V_102 = V_107 -> V_83 ;
if ( V_102 && ! F_120 ( V_102 ) )
F_110 ( V_102 ) ;
}
}
static void F_121 ( struct V_4 * V_4 )
{
struct V_31 * V_107 ;
int V_10 ;
F_79 (bvec, bio, i) {
struct V_102 * V_102 = V_107 -> V_83 ;
if ( V_102 )
F_122 ( V_102 ) ;
}
}
static void F_123 ( struct V_61 * V_62 )
{
unsigned long V_58 ;
struct V_4 * V_4 ;
F_124 ( & V_184 , V_58 ) ;
V_4 = V_185 ;
V_185 = NULL ;
F_125 ( & V_184 , V_58 ) ;
while ( V_4 ) {
struct V_4 * V_186 = V_4 -> V_116 ;
F_119 ( V_4 ) ;
F_121 ( V_4 ) ;
F_50 ( V_4 ) ;
V_4 = V_186 ;
}
}
void F_126 ( struct V_4 * V_4 )
{
struct V_31 * V_107 ;
int V_187 = 0 ;
int V_10 ;
F_79 (bvec, bio, i) {
struct V_102 * V_102 = V_107 -> V_83 ;
if ( F_127 ( V_102 ) || F_120 ( V_102 ) ) {
F_104 ( V_102 ) ;
V_107 -> V_83 = NULL ;
} else {
V_187 ++ ;
}
}
if ( V_187 ) {
unsigned long V_58 ;
F_124 ( & V_184 , V_58 ) ;
V_4 -> V_116 = V_185 ;
V_185 = V_4 ;
F_125 ( & V_184 , V_58 ) ;
F_128 ( & V_188 ) ;
} else {
F_50 ( V_4 ) ;
}
}
void F_129 ( struct V_4 * V_189 )
{
int V_10 ;
struct V_31 * V_107 ;
F_46 (bvec, bi, i)
F_48 ( V_107 -> V_83 ) ;
}
void F_130 ( struct V_4 * V_4 , int error )
{
if ( error )
F_131 ( V_56 , & V_4 -> V_55 ) ;
else if ( ! F_132 ( V_56 , & V_4 -> V_55 ) )
error = - V_190 ;
if ( V_4 -> V_120 )
V_4 -> V_120 ( V_4 , error ) ;
}
void F_133 ( struct V_191 * V_192 )
{
if ( F_52 ( & V_192 -> V_193 ) ) {
struct V_4 * V_194 = V_192 -> V_195 . V_116 ;
F_130 ( V_194 , V_192 -> error ) ;
F_14 ( V_192 , V_192 -> V_196 . V_116 ) ;
}
}
static void F_134 ( struct V_4 * V_189 , int V_179 )
{
struct V_191 * V_192 = F_32 ( V_189 , struct V_191 , V_195 ) ;
if ( V_179 )
V_192 -> error = V_179 ;
F_133 ( V_192 ) ;
}
static void F_135 ( struct V_4 * V_189 , int V_179 )
{
struct V_191 * V_192 = F_32 ( V_189 , struct V_191 , V_196 ) ;
if ( V_179 )
V_192 -> error = V_179 ;
F_133 ( V_192 ) ;
}
struct V_191 * F_136 ( struct V_4 * V_189 , int V_197 )
{
struct V_191 * V_192 = F_17 ( V_198 , V_199 ) ;
if ( ! V_192 )
return V_192 ;
F_137 ( F_59 ( V_189 -> V_90 ) , V_189 ,
V_189 -> V_89 + V_197 ) ;
F_138 ( F_139 ( V_189 ) > 1 ) ;
F_29 ( & V_192 -> V_193 , 3 ) ;
V_192 -> error = 0 ;
V_192 -> V_195 = * V_189 ;
V_192 -> V_196 = * V_189 ;
V_192 -> V_196 . V_89 += V_197 ;
V_192 -> V_196 . V_94 -= V_197 << 9 ;
V_192 -> V_195 . V_94 = V_197 << 9 ;
if ( V_189 -> V_93 != 0 ) {
V_192 -> V_200 = * F_77 ( V_189 ) ;
V_192 -> V_201 = * F_77 ( V_189 ) ;
if ( F_140 ( V_189 ) ) {
V_192 -> V_201 . V_109 += V_197 << 9 ;
V_192 -> V_201 . V_82 -= V_197 << 9 ;
V_192 -> V_200 . V_82 = V_197 << 9 ;
}
V_192 -> V_195 . V_52 = & V_192 -> V_200 ;
V_192 -> V_196 . V_52 = & V_192 -> V_201 ;
V_192 -> V_195 . V_80 = 1 ;
V_192 -> V_196 . V_80 = 1 ;
}
V_192 -> V_195 . V_120 = F_134 ;
V_192 -> V_196 . V_120 = F_135 ;
V_192 -> V_195 . V_116 = V_189 ;
V_192 -> V_196 . V_116 = V_198 ;
if ( F_22 ( V_189 ) )
F_141 ( V_189 , V_192 , V_197 ) ;
return V_192 ;
}
T_4 F_142 ( struct V_4 * V_4 , unsigned short V_202 ,
unsigned int V_104 )
{
unsigned int V_203 ;
struct V_31 * V_32 ;
T_4 V_204 ;
int V_10 ;
V_203 = F_143 ( V_4 -> V_90 -> V_205 -> V_206 ) ;
V_204 = 0 ;
if ( V_202 >= V_4 -> V_95 )
V_202 = V_4 -> V_93 - 1 ;
F_79 (bv, bio, i) {
if ( V_10 == V_202 ) {
if ( V_104 > V_32 -> V_109 )
V_204 += ( V_104 - V_32 -> V_109 ) / V_203 ;
break;
}
V_204 += V_32 -> V_82 / V_203 ;
}
return V_204 ;
}
T_1 * F_144 ( struct V_23 * V_24 , int V_207 )
{
struct V_35 * V_192 = V_28 + V_34 ;
return F_145 ( V_207 , V_192 -> V_5 ) ;
}
void F_146 ( struct V_23 * V_24 )
{
if ( V_24 -> V_70 )
F_147 ( V_24 -> V_70 ) ;
if ( V_24 -> V_54 )
F_148 ( V_24 -> V_54 ) ;
if ( V_24 -> V_51 )
F_148 ( V_24 -> V_51 ) ;
F_149 ( V_24 ) ;
F_7 ( V_24 ) ;
F_27 ( V_24 ) ;
}
struct V_23 * F_150 ( unsigned int V_208 , unsigned int V_53 )
{
unsigned int V_209 = V_76 * sizeof( struct V_31 ) ;
struct V_23 * V_24 ;
V_24 = F_151 ( sizeof( * V_24 ) , V_19 ) ;
if ( ! V_24 )
return NULL ;
V_24 -> V_53 = V_53 ;
F_152 ( & V_24 -> V_64 ) ;
F_38 ( & V_24 -> V_65 ) ;
F_153 ( & V_24 -> V_63 , F_31 ) ;
V_24 -> V_6 = F_1 ( V_53 + V_209 ) ;
if ( ! V_24 -> V_6 ) {
F_27 ( V_24 ) ;
return NULL ;
}
V_24 -> V_54 = F_145 ( V_208 , V_24 -> V_6 ) ;
if ( ! V_24 -> V_54 )
goto V_210;
V_24 -> V_51 = F_144 ( V_24 , V_208 ) ;
if ( ! V_24 -> V_51 )
goto V_210;
V_24 -> V_70 = F_154 ( L_5 , V_211 , 0 ) ;
if ( ! V_24 -> V_70 )
goto V_210;
return V_24 ;
V_210:
F_146 ( V_24 ) ;
return NULL ;
}
int F_155 ( struct V_4 * V_4 )
{
struct V_212 * V_213 ;
struct V_214 * V_215 ;
if ( V_4 -> V_216 )
return - V_217 ;
V_213 = V_69 -> V_212 ;
if ( ! V_213 )
return - V_218 ;
F_156 ( V_213 ) ;
V_4 -> V_216 = V_213 ;
F_157 () ;
V_215 = F_158 ( V_69 , V_219 ) ;
if ( V_215 && F_159 ( V_215 ) )
V_4 -> V_220 = V_215 ;
F_160 () ;
return 0 ;
}
void F_21 ( struct V_4 * V_4 )
{
if ( V_4 -> V_216 ) {
F_161 ( V_4 -> V_216 ) ;
V_4 -> V_216 = NULL ;
}
if ( V_4 -> V_220 ) {
F_162 ( V_4 -> V_220 ) ;
V_4 -> V_220 = NULL ;
}
}
static void T_5 F_163 ( void )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_33 ; V_10 ++ ) {
int V_221 ;
struct V_35 * V_36 = V_28 + V_10 ;
if ( V_36 -> V_29 <= V_76 ) {
V_36 -> V_5 = NULL ;
continue;
}
V_221 = V_36 -> V_29 * sizeof( struct V_31 ) ;
V_36 -> V_5 = F_4 ( V_36 -> V_20 , V_221 , 0 ,
V_21 | V_222 , NULL ) ;
}
}
static int T_5 F_164 ( void )
{
V_18 = 2 ;
V_13 = 0 ;
V_14 = F_151 ( V_18 * sizeof( struct V_6 ) , V_19 ) ;
if ( ! V_14 )
F_165 ( L_6 ) ;
F_166 () ;
F_163 () ;
V_223 = F_150 ( V_224 , 0 ) ;
if ( ! V_223 )
F_165 ( L_6 ) ;
if ( F_167 ( V_223 , V_224 ) )
F_165 ( L_7 ) ;
V_198 = F_168 ( V_225 ,
sizeof( struct V_191 ) ) ;
if ( ! V_198 )
F_165 ( L_8 ) ;
return 0 ;
}
