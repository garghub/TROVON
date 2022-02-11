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
F_28 ( & V_4 -> V_55 , 1 ) ;
F_28 ( & V_4 -> V_56 , 1 ) ;
}
void F_29 ( struct V_4 * V_4 )
{
unsigned long V_57 = V_4 -> V_58 & ( ~ 0UL << V_59 ) ;
F_19 ( V_4 ) ;
memset ( V_4 , 0 , V_60 ) ;
V_4 -> V_58 = V_57 ;
F_28 ( & V_4 -> V_55 , 1 ) ;
}
static struct V_4 * F_30 ( struct V_4 * V_4 )
{
struct V_4 * V_61 = V_4 -> V_62 ;
if ( ! V_61 -> V_63 )
V_61 -> V_63 = V_4 -> V_63 ;
F_31 ( V_4 ) ;
return V_61 ;
}
static void F_32 ( struct V_4 * V_4 )
{
F_33 ( F_30 ( V_4 ) ) ;
}
static inline void F_34 ( struct V_4 * V_4 )
{
F_35 ( V_4 , V_64 ) ;
F_36 () ;
F_37 ( & V_4 -> V_55 ) ;
}
void F_38 ( struct V_4 * V_4 , struct V_4 * V_61 )
{
F_39 ( V_4 -> V_62 || V_4 -> V_65 ) ;
V_4 -> V_62 = V_61 ;
V_4 -> V_65 = F_32 ;
F_34 ( V_61 ) ;
}
static void F_40 ( struct V_66 * V_67 )
{
struct V_23 * V_24 = F_41 ( V_67 , struct V_23 , V_68 ) ;
struct V_4 * V_4 ;
while ( 1 ) {
F_42 ( & V_24 -> V_69 ) ;
V_4 = F_43 ( & V_24 -> V_70 ) ;
F_44 ( & V_24 -> V_69 ) ;
if ( ! V_4 )
break;
F_45 ( V_4 ) ;
}
}
static void F_46 ( struct V_23 * V_24 )
{
struct V_71 V_72 , V_73 ;
struct V_4 * V_4 ;
F_47 ( & V_72 ) ;
F_47 ( & V_73 ) ;
while ( ( V_4 = F_43 ( V_74 -> V_71 ) ) )
F_48 ( V_4 -> V_48 == V_24 ? & V_72 : & V_73 , V_4 ) ;
* V_74 -> V_71 = V_73 ;
F_42 ( & V_24 -> V_69 ) ;
F_49 ( & V_24 -> V_70 , & V_72 ) ;
F_44 ( & V_24 -> V_69 ) ;
F_50 ( V_24 -> V_75 , & V_24 -> V_68 ) ;
}
struct V_4 * F_51 ( T_2 V_37 , int V_76 , struct V_23 * V_24 )
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
V_49 = F_52 ( sizeof( struct V_4 ) +
V_76 * sizeof( struct V_31 ) ,
V_37 ) ;
V_53 = 0 ;
V_78 = V_76 ;
} else {
if ( F_53 ( ! V_24 -> V_51 && V_76 > 0 ) )
return NULL ;
if ( V_74 -> V_71 && ! F_54 ( V_74 -> V_71 ) )
V_37 &= ~ V_43 ;
V_49 = F_16 ( V_24 -> V_54 , V_37 ) ;
if ( ! V_49 && V_37 != V_77 ) {
F_46 ( V_24 ) ;
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
F_46 ( V_24 ) ;
V_37 = V_77 ;
V_39 = F_15 ( V_37 , V_76 , & V_27 , V_24 -> V_51 ) ;
}
if ( F_18 ( ! V_39 ) )
goto V_82;
F_35 ( V_4 , V_50 ) ;
} else if ( V_76 ) {
V_39 = V_4 -> V_83 ;
}
V_4 -> V_48 = V_24 ;
V_4 -> V_58 |= V_27 << V_84 ;
V_4 -> V_85 = V_76 ;
V_4 -> V_52 = V_39 ;
return V_4 ;
V_82:
F_13 ( V_49 , V_24 -> V_54 ) ;
return NULL ;
}
void F_55 ( struct V_4 * V_4 )
{
unsigned long V_57 ;
struct V_31 V_32 ;
struct V_86 V_87 ;
F_56 (bv, bio, iter) {
char * V_88 = F_57 ( & V_32 , & V_57 ) ;
memset ( V_88 , 0 , V_32 . V_89 ) ;
F_58 ( V_32 . V_90 ) ;
F_59 ( V_88 , & V_57 ) ;
}
}
void F_31 ( struct V_4 * V_4 )
{
if ( ! F_24 ( V_4 , V_91 ) )
F_23 ( V_4 ) ;
else {
F_12 ( ! F_60 ( & V_4 -> V_56 ) ) ;
if ( F_61 ( & V_4 -> V_56 ) )
F_23 ( V_4 ) ;
}
}
inline int F_62 ( struct V_92 * V_93 , struct V_4 * V_4 )
{
if ( F_18 ( ! F_24 ( V_4 , V_94 ) ) )
F_63 ( V_93 , V_4 ) ;
return V_4 -> V_95 ;
}
void F_64 ( struct V_4 * V_4 , struct V_4 * V_96 )
{
F_39 ( V_4 -> V_48 && F_25 ( V_4 ) != V_79 ) ;
V_4 -> V_97 = V_96 -> V_97 ;
F_35 ( V_4 , V_98 ) ;
V_4 -> V_99 = V_96 -> V_99 ;
V_4 -> V_100 = V_96 -> V_100 ;
V_4 -> V_52 = V_96 -> V_52 ;
}
struct V_4 * F_65 ( struct V_4 * V_4 , T_2 V_37 , struct V_23 * V_24 )
{
struct V_4 * V_101 ;
V_101 = F_51 ( V_37 , 0 , V_24 ) ;
if ( ! V_101 )
return NULL ;
F_64 ( V_101 , V_4 ) ;
if ( F_21 ( V_4 ) ) {
int V_102 ;
V_102 = F_66 ( V_101 , V_4 , V_37 ) ;
if ( V_102 < 0 ) {
F_31 ( V_101 ) ;
return NULL ;
}
}
return V_101 ;
}
struct V_4 * F_67 ( struct V_4 * V_96 , T_2 V_37 ,
struct V_23 * V_24 )
{
struct V_86 V_87 ;
struct V_31 V_32 ;
struct V_4 * V_4 ;
V_4 = F_51 ( V_37 , F_68 ( V_96 ) , V_24 ) ;
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
F_56 (bv, bio_src, iter)
V_4 -> V_52 [ V_4 -> V_108 ++ ] = V_32 ;
V_106:
if ( F_21 ( V_96 ) ) {
int V_102 ;
V_102 = F_66 ( V_4 , V_96 , V_37 ) ;
if ( V_102 < 0 ) {
F_31 ( V_4 ) ;
return NULL ;
}
}
return V_4 ;
}
int F_69 ( struct V_92 * V_93 , struct V_4 * V_4 , struct V_109
* V_109 , unsigned int V_110 , unsigned int V_111 )
{
int V_112 = 0 ;
struct V_31 * V_113 ;
if ( F_18 ( F_24 ( V_4 , V_98 ) ) )
return 0 ;
if ( ( ( V_4 -> V_100 . V_104 + V_110 ) >> 9 ) > F_70 ( V_93 ) )
return 0 ;
if ( V_4 -> V_108 > 0 ) {
struct V_31 * V_114 = & V_4 -> V_52 [ V_4 -> V_108 - 1 ] ;
if ( V_109 == V_114 -> V_90 &&
V_111 == V_114 -> V_115 + V_114 -> V_89 ) {
V_114 -> V_89 += V_110 ;
V_4 -> V_100 . V_104 += V_110 ;
goto V_116;
}
if ( F_71 ( V_93 , V_114 , V_111 ) )
return 0 ;
}
if ( V_4 -> V_108 >= V_4 -> V_85 )
return 0 ;
V_113 = & V_4 -> V_52 [ V_4 -> V_108 ] ;
V_113 -> V_90 = V_109 ;
V_113 -> V_89 = V_110 ;
V_113 -> V_115 = V_111 ;
V_4 -> V_108 ++ ;
V_4 -> V_95 ++ ;
V_4 -> V_100 . V_104 += V_110 ;
while ( V_4 -> V_95 > F_72 ( V_93 ) ) {
if ( V_112 )
goto V_117;
V_112 = 1 ;
F_63 ( V_93 , V_4 ) ;
}
if ( V_4 -> V_108 > 1 && ( F_73 ( V_113 - 1 , V_113 ) ) )
F_74 ( V_4 , V_94 ) ;
V_116:
return V_110 ;
V_117:
V_113 -> V_90 = NULL ;
V_113 -> V_89 = 0 ;
V_113 -> V_115 = 0 ;
V_4 -> V_108 -- ;
V_4 -> V_100 . V_104 -= V_110 ;
F_63 ( V_93 , V_4 ) ;
return 0 ;
}
int F_75 ( struct V_4 * V_4 , struct V_109 * V_109 ,
unsigned int V_110 , unsigned int V_111 )
{
struct V_31 * V_32 ;
if ( F_53 ( F_24 ( V_4 , V_98 ) ) )
return 0 ;
if ( V_4 -> V_108 > 0 ) {
V_32 = & V_4 -> V_52 [ V_4 -> V_108 - 1 ] ;
if ( V_109 == V_32 -> V_90 &&
V_111 == V_32 -> V_115 + V_32 -> V_89 ) {
V_32 -> V_89 += V_110 ;
goto V_116;
}
}
if ( V_4 -> V_108 >= V_4 -> V_85 )
return 0 ;
V_32 = & V_4 -> V_52 [ V_4 -> V_108 ] ;
V_32 -> V_90 = V_109 ;
V_32 -> V_89 = V_110 ;
V_32 -> V_115 = V_111 ;
V_4 -> V_108 ++ ;
V_116:
V_4 -> V_100 . V_104 += V_110 ;
return V_110 ;
}
static void F_76 ( struct V_4 * V_4 )
{
struct V_118 * V_102 = V_4 -> V_62 ;
V_102 -> error = V_4 -> V_63 ;
F_77 ( & V_102 -> V_119 ) ;
}
int F_78 ( int V_120 , struct V_4 * V_4 )
{
struct V_118 V_102 ;
V_120 |= V_121 ;
F_79 ( & V_102 . V_119 ) ;
V_4 -> V_62 = & V_102 ;
V_4 -> V_65 = F_76 ;
F_80 ( V_120 , V_4 ) ;
F_81 ( & V_102 . V_119 ) ;
return V_102 . error ;
}
void F_82 ( struct V_4 * V_4 , unsigned V_122 )
{
if ( F_21 ( V_4 ) )
F_83 ( V_4 , V_122 ) ;
F_84 ( V_4 , & V_4 -> V_100 , V_122 ) ;
}
int F_85 ( struct V_4 * V_4 , T_2 V_37 )
{
int V_10 ;
struct V_31 * V_32 ;
F_86 (bv, bio, i) {
V_32 -> V_90 = F_87 ( V_37 ) ;
if ( ! V_32 -> V_90 ) {
while ( -- V_32 >= V_4 -> V_52 )
F_88 ( V_32 -> V_90 ) ;
return - V_123 ;
}
}
return 0 ;
}
void F_89 ( struct V_4 * V_124 , struct V_4 * V_125 )
{
struct V_86 V_126 , V_127 ;
struct V_31 V_128 , V_129 ;
void * V_130 , * V_131 ;
unsigned V_122 ;
V_126 = V_125 -> V_100 ;
V_127 = V_124 -> V_100 ;
while ( 1 ) {
if ( ! V_126 . V_104 ) {
V_125 = V_125 -> V_132 ;
if ( ! V_125 )
break;
V_126 = V_125 -> V_100 ;
}
if ( ! V_127 . V_104 ) {
V_124 = V_124 -> V_132 ;
if ( ! V_124 )
break;
V_127 = V_124 -> V_100 ;
}
V_128 = F_90 ( V_125 , V_126 ) ;
V_129 = F_90 ( V_124 , V_127 ) ;
V_122 = F_91 ( V_128 . V_89 , V_129 . V_89 ) ;
V_130 = F_92 ( V_128 . V_90 ) ;
V_131 = F_92 ( V_129 . V_90 ) ;
memcpy ( V_131 + V_129 . V_115 ,
V_130 + V_128 . V_115 ,
V_122 ) ;
F_93 ( V_131 ) ;
F_93 ( V_130 ) ;
F_84 ( V_125 , & V_126 , V_122 ) ;
F_84 ( V_124 , & V_127 , V_122 ) ;
}
}
static struct V_133 * F_94 ( unsigned int V_134 ,
T_2 V_37 )
{
if ( V_134 > V_80 )
return NULL ;
return F_52 ( sizeof( struct V_133 ) +
sizeof( struct V_135 ) * V_134 , V_37 ) ;
}
static int F_95 ( struct V_4 * V_4 , struct V_136 V_87 )
{
int V_10 ;
struct V_31 * V_113 ;
F_86 (bvec, bio, i) {
T_3 V_102 ;
V_102 = F_96 ( V_113 -> V_90 ,
V_113 -> V_115 ,
V_113 -> V_89 ,
& V_87 ) ;
if ( ! F_97 ( & V_87 ) )
break;
if ( V_102 < V_113 -> V_89 )
return - V_137 ;
}
return 0 ;
}
static int F_98 ( struct V_4 * V_4 , struct V_136 V_87 )
{
int V_10 ;
struct V_31 * V_113 ;
F_86 (bvec, bio, i) {
T_3 V_102 ;
V_102 = F_99 ( V_113 -> V_90 ,
V_113 -> V_115 ,
V_113 -> V_89 ,
& V_87 ) ;
if ( ! F_97 ( & V_87 ) )
break;
if ( V_102 < V_113 -> V_89 )
return - V_137 ;
}
return 0 ;
}
static void F_100 ( struct V_4 * V_4 )
{
struct V_31 * V_113 ;
int V_10 ;
F_86 (bvec, bio, i)
F_88 ( V_113 -> V_90 ) ;
}
int F_101 ( struct V_4 * V_4 )
{
struct V_133 * V_138 = V_4 -> V_62 ;
int V_102 = 0 ;
if ( ! F_24 ( V_4 , V_139 ) ) {
if ( ! V_74 -> V_140 )
V_102 = - V_141 ;
else if ( F_102 ( V_4 ) == V_142 )
V_102 = F_98 ( V_4 , V_138 -> V_87 ) ;
if ( V_138 -> V_143 )
F_100 ( V_4 ) ;
}
F_26 ( V_138 ) ;
F_31 ( V_4 ) ;
return V_102 ;
}
struct V_4 * F_103 ( struct V_92 * V_93 ,
struct V_144 * V_145 ,
const struct V_136 * V_87 ,
T_2 V_37 )
{
struct V_133 * V_138 ;
struct V_109 * V_109 ;
struct V_4 * V_4 ;
int V_10 , V_102 ;
int V_146 = 0 ;
unsigned int V_110 = V_87 -> V_147 ;
unsigned int V_111 = V_145 ? F_104 ( V_145 -> V_111 ) : 0 ;
for ( V_10 = 0 ; V_10 < V_87 -> V_148 ; V_10 ++ ) {
unsigned long V_149 ;
unsigned long V_150 ;
unsigned long V_151 ;
V_149 = ( unsigned long ) V_87 -> V_152 [ V_10 ] . V_153 ;
V_150 = ( V_149 + V_87 -> V_152 [ V_10 ] . V_154 + V_155 - 1 )
>> V_156 ;
V_151 = V_149 >> V_156 ;
if ( V_150 < V_151 )
return F_105 ( - V_157 ) ;
V_146 += V_150 - V_151 ;
}
if ( V_111 )
V_146 ++ ;
V_138 = F_94 ( V_87 -> V_148 , V_37 ) ;
if ( ! V_138 )
return F_105 ( - V_123 ) ;
V_138 -> V_143 = V_145 ? 0 : 1 ;
memcpy ( V_138 -> V_152 , V_87 -> V_152 , sizeof( struct V_135 ) * V_87 -> V_148 ) ;
F_106 ( & V_138 -> V_87 , V_87 -> type , V_138 -> V_152 ,
V_87 -> V_148 , V_87 -> V_147 ) ;
V_102 = - V_123 ;
V_4 = F_107 ( V_37 , V_146 ) ;
if ( ! V_4 )
goto V_158;
if ( V_87 -> type & V_159 )
V_4 -> V_99 |= V_160 ;
V_102 = 0 ;
if ( V_145 ) {
V_146 = 1 << V_145 -> V_161 ;
V_10 = V_145 -> V_111 / V_155 ;
}
while ( V_110 ) {
unsigned int V_122 = V_155 ;
V_122 -= V_111 ;
if ( V_122 > V_110 )
V_122 = V_110 ;
if ( V_145 ) {
if ( V_10 == V_145 -> V_162 * V_146 ) {
V_102 = - V_123 ;
break;
}
V_109 = V_145 -> V_163 [ V_10 / V_146 ] ;
V_109 += ( V_10 % V_146 ) ;
V_10 ++ ;
} else {
V_109 = F_87 ( V_93 -> V_164 | V_37 ) ;
if ( ! V_109 ) {
V_102 = - V_123 ;
break;
}
}
if ( F_69 ( V_93 , V_4 , V_109 , V_122 , V_111 ) < V_122 )
break;
V_110 -= V_122 ;
V_111 = 0 ;
}
if ( V_102 )
goto V_165;
if ( ( ( V_87 -> type & V_159 ) && ( ! V_145 || ! V_145 -> V_166 ) ) ||
( V_145 && V_145 -> V_167 ) ) {
V_102 = F_95 ( V_4 , * V_87 ) ;
if ( V_102 )
goto V_165;
}
V_4 -> V_62 = V_138 ;
return V_4 ;
V_165:
if ( ! V_145 )
F_100 ( V_4 ) ;
F_31 ( V_4 ) ;
V_158:
F_26 ( V_138 ) ;
return F_105 ( V_102 ) ;
}
struct V_4 * F_108 ( struct V_92 * V_93 ,
const struct V_136 * V_87 ,
T_2 V_37 )
{
int V_168 ;
int V_146 = 0 ;
struct V_109 * * V_163 ;
struct V_4 * V_4 ;
int V_169 = 0 ;
int V_102 , V_111 ;
struct V_136 V_10 ;
struct V_135 V_152 ;
F_109 (iov, i, *iter) {
unsigned long V_149 = ( unsigned long ) V_152 . V_153 ;
unsigned long V_110 = V_152 . V_154 ;
unsigned long V_150 = ( V_149 + V_110 + V_155 - 1 ) >> V_156 ;
unsigned long V_151 = V_149 >> V_156 ;
if ( V_150 < V_151 )
return F_105 ( - V_157 ) ;
V_146 += V_150 - V_151 ;
if ( V_149 & F_110 ( V_93 ) )
return F_105 ( - V_157 ) ;
}
if ( ! V_146 )
return F_105 ( - V_157 ) ;
V_4 = F_107 ( V_37 , V_146 ) ;
if ( ! V_4 )
return F_105 ( - V_123 ) ;
V_102 = - V_123 ;
V_163 = F_111 ( V_146 , sizeof( struct V_109 * ) , V_37 ) ;
if ( ! V_163 )
goto V_26;
F_109 (iov, i, *iter) {
unsigned long V_149 = ( unsigned long ) V_152 . V_153 ;
unsigned long V_110 = V_152 . V_154 ;
unsigned long V_150 = ( V_149 + V_110 + V_155 - 1 ) >> V_156 ;
unsigned long V_151 = V_149 >> V_156 ;
const int V_170 = V_150 - V_151 ;
const int V_171 = V_169 + V_170 ;
V_102 = F_112 ( V_149 , V_170 ,
( V_87 -> type & V_159 ) != V_159 ,
& V_163 [ V_169 ] ) ;
if ( V_102 < V_170 ) {
V_102 = - V_137 ;
goto V_172;
}
V_111 = F_104 ( V_149 ) ;
for ( V_168 = V_169 ; V_168 < V_171 ; V_168 ++ ) {
unsigned int V_122 = V_155 - V_111 ;
if ( V_110 <= 0 )
break;
if ( V_122 > V_110 )
V_122 = V_110 ;
if ( F_69 ( V_93 , V_4 , V_163 [ V_168 ] , V_122 , V_111 ) <
V_122 )
break;
V_110 -= V_122 ;
V_111 = 0 ;
}
V_169 = V_168 ;
while ( V_168 < V_171 )
F_113 ( V_163 [ V_168 ++ ] ) ;
}
F_26 ( V_163 ) ;
if ( V_87 -> type & V_159 )
V_4 -> V_99 |= V_160 ;
F_35 ( V_4 , V_173 ) ;
F_114 ( V_4 ) ;
return V_4 ;
V_172:
for ( V_168 = 0 ; V_168 < V_146 ; V_168 ++ ) {
if ( ! V_163 [ V_168 ] )
break;
F_113 ( V_163 [ V_168 ] ) ;
}
V_26:
F_26 ( V_163 ) ;
F_31 ( V_4 ) ;
return F_105 ( V_102 ) ;
}
static void F_115 ( struct V_4 * V_4 )
{
struct V_31 * V_113 ;
int V_10 ;
F_86 (bvec, bio, i) {
if ( F_102 ( V_4 ) == V_142 )
F_116 ( V_113 -> V_90 ) ;
F_113 ( V_113 -> V_90 ) ;
}
F_31 ( V_4 ) ;
}
void F_117 ( struct V_4 * V_4 )
{
F_115 ( V_4 ) ;
F_31 ( V_4 ) ;
}
static void F_118 ( struct V_4 * V_4 )
{
F_31 ( V_4 ) ;
}
struct V_4 * F_119 ( struct V_92 * V_93 , void * V_88 , unsigned int V_110 ,
T_2 V_37 )
{
unsigned long V_174 = ( unsigned long ) V_88 ;
unsigned long V_150 = ( V_174 + V_110 + V_155 - 1 ) >> V_156 ;
unsigned long V_151 = V_174 >> V_156 ;
const int V_146 = V_150 - V_151 ;
int V_111 , V_10 ;
struct V_4 * V_4 ;
V_4 = F_107 ( V_37 , V_146 ) ;
if ( ! V_4 )
return F_105 ( - V_123 ) ;
V_111 = F_104 ( V_174 ) ;
for ( V_10 = 0 ; V_10 < V_146 ; V_10 ++ ) {
unsigned int V_122 = V_155 - V_111 ;
if ( V_110 <= 0 )
break;
if ( V_122 > V_110 )
V_122 = V_110 ;
if ( F_69 ( V_93 , V_4 , F_120 ( V_88 ) , V_122 ,
V_111 ) < V_122 ) {
F_31 ( V_4 ) ;
return F_105 ( - V_157 ) ;
}
V_88 += V_122 ;
V_110 -= V_122 ;
V_111 = 0 ;
}
V_4 -> V_65 = F_118 ;
return V_4 ;
}
static void F_121 ( struct V_4 * V_4 )
{
F_100 ( V_4 ) ;
F_31 ( V_4 ) ;
}
static void F_122 ( struct V_4 * V_4 )
{
char * V_49 = V_4 -> V_62 ;
struct V_31 * V_113 ;
int V_10 ;
F_86 (bvec, bio, i) {
memcpy ( V_49 , F_123 ( V_113 -> V_90 ) , V_113 -> V_89 ) ;
V_49 += V_113 -> V_89 ;
}
F_121 ( V_4 ) ;
}
struct V_4 * F_124 ( struct V_92 * V_93 , void * V_88 , unsigned int V_110 ,
T_2 V_37 , int V_175 )
{
unsigned long V_174 = ( unsigned long ) V_88 ;
unsigned long V_150 = ( V_174 + V_110 + V_155 - 1 ) >> V_156 ;
unsigned long V_151 = V_174 >> V_156 ;
struct V_4 * V_4 ;
void * V_49 = V_88 ;
int V_146 = 0 ;
if ( V_150 < V_151 )
return F_105 ( - V_157 ) ;
V_146 = V_150 - V_151 ;
V_4 = F_107 ( V_37 , V_146 ) ;
if ( ! V_4 )
return F_105 ( - V_123 ) ;
while ( V_110 ) {
struct V_109 * V_109 ;
unsigned int V_122 = V_155 ;
if ( V_122 > V_110 )
V_122 = V_110 ;
V_109 = F_87 ( V_93 -> V_164 | V_37 ) ;
if ( ! V_109 )
goto V_165;
if ( ! V_175 )
memcpy ( F_123 ( V_109 ) , V_49 , V_122 ) ;
if ( F_69 ( V_93 , V_4 , V_109 , V_122 , 0 ) < V_122 )
break;
V_110 -= V_122 ;
V_49 += V_122 ;
}
if ( V_175 ) {
V_4 -> V_65 = F_122 ;
V_4 -> V_62 = V_88 ;
} else {
V_4 -> V_65 = F_121 ;
V_4 -> V_99 |= V_160 ;
}
return V_4 ;
V_165:
F_100 ( V_4 ) ;
F_31 ( V_4 ) ;
return F_105 ( - V_123 ) ;
}
void F_125 ( struct V_4 * V_4 )
{
struct V_31 * V_113 ;
int V_10 ;
F_86 (bvec, bio, i) {
struct V_109 * V_109 = V_113 -> V_90 ;
if ( V_109 && ! F_126 ( V_109 ) )
F_116 ( V_109 ) ;
}
}
static void F_127 ( struct V_4 * V_4 )
{
struct V_31 * V_113 ;
int V_10 ;
F_86 (bvec, bio, i) {
struct V_109 * V_109 = V_113 -> V_90 ;
if ( V_109 )
F_113 ( V_109 ) ;
}
}
static void F_128 ( struct V_66 * V_67 )
{
unsigned long V_57 ;
struct V_4 * V_4 ;
F_129 ( & V_176 , V_57 ) ;
V_4 = V_177 ;
V_177 = NULL ;
F_130 ( & V_176 , V_57 ) ;
while ( V_4 ) {
struct V_4 * V_178 = V_4 -> V_62 ;
F_125 ( V_4 ) ;
F_127 ( V_4 ) ;
F_31 ( V_4 ) ;
V_4 = V_178 ;
}
}
void F_131 ( struct V_4 * V_4 )
{
struct V_31 * V_113 ;
int V_179 = 0 ;
int V_10 ;
F_86 (bvec, bio, i) {
struct V_109 * V_109 = V_113 -> V_90 ;
if ( F_132 ( V_109 ) || F_126 ( V_109 ) ) {
F_113 ( V_109 ) ;
V_113 -> V_90 = NULL ;
} else {
V_179 ++ ;
}
}
if ( V_179 ) {
unsigned long V_57 ;
F_129 ( & V_176 , V_57 ) ;
V_4 -> V_62 = V_177 ;
V_177 = V_4 ;
F_130 ( & V_176 , V_57 ) ;
F_133 ( & V_180 ) ;
} else {
F_31 ( V_4 ) ;
}
}
void F_134 ( int V_120 , unsigned long V_181 ,
struct V_182 * V_183 )
{
int V_184 = F_135 () ;
F_136 ( V_184 , V_183 ) ;
F_137 ( V_184 , V_183 , V_185 [ V_120 ] ) ;
F_138 ( V_184 , V_183 , V_181 [ V_120 ] , V_181 ) ;
F_139 ( V_183 , V_120 ) ;
F_140 () ;
}
void F_141 ( int V_120 , struct V_182 * V_183 ,
unsigned long V_186 )
{
unsigned long V_187 = V_188 - V_186 ;
int V_184 = F_135 () ;
F_138 ( V_184 , V_183 , V_189 [ V_120 ] , V_187 ) ;
F_136 ( V_184 , V_183 ) ;
F_142 ( V_183 , V_120 ) ;
F_140 () ;
}
void F_143 ( struct V_4 * V_190 )
{
struct V_31 V_113 ;
struct V_86 V_87 ;
F_56 (bvec, bi, iter)
F_58 ( V_113 . V_90 ) ;
}
static inline bool F_144 ( struct V_4 * V_4 )
{
if ( ! F_24 ( V_4 , V_64 ) )
return true ;
F_39 ( F_60 ( & V_4 -> V_55 ) <= 0 ) ;
if ( F_61 ( & V_4 -> V_55 ) ) {
F_74 ( V_4 , V_64 ) ;
return true ;
}
return false ;
}
void F_33 ( struct V_4 * V_4 )
{
V_191:
if ( ! F_144 ( V_4 ) )
return;
if ( V_4 -> V_65 == F_32 ) {
V_4 = F_30 ( V_4 ) ;
goto V_191;
}
if ( V_4 -> V_65 )
V_4 -> V_65 ( V_4 ) ;
}
struct V_4 * F_145 ( struct V_4 * V_4 , int V_181 ,
T_2 V_192 , struct V_23 * V_24 )
{
struct V_4 * V_193 = NULL ;
F_39 ( V_181 <= 0 ) ;
F_39 ( V_181 >= F_146 ( V_4 ) ) ;
if ( V_4 -> V_99 & V_105 )
V_193 = F_67 ( V_4 , V_192 , V_24 ) ;
else
V_193 = F_65 ( V_4 , V_192 , V_24 ) ;
if ( ! V_193 )
return NULL ;
V_193 -> V_100 . V_104 = V_181 << 9 ;
if ( F_21 ( V_193 ) )
F_147 ( V_193 , 0 , V_181 ) ;
F_82 ( V_4 , V_193 -> V_100 . V_104 ) ;
return V_193 ;
}
void F_148 ( struct V_4 * V_4 , int V_111 , int V_194 )
{
V_194 <<= 9 ;
if ( V_111 == 0 && V_194 == V_4 -> V_100 . V_104 )
return;
F_74 ( V_4 , V_94 ) ;
F_82 ( V_4 , V_111 << 9 ) ;
V_4 -> V_100 . V_104 = V_194 ;
}
T_1 * F_149 ( int V_195 )
{
struct V_35 * V_196 = V_28 + V_34 ;
return F_150 ( V_195 , V_196 -> V_5 ) ;
}
void F_151 ( struct V_23 * V_24 )
{
if ( V_24 -> V_75 )
F_152 ( V_24 -> V_75 ) ;
if ( V_24 -> V_54 )
F_153 ( V_24 -> V_54 ) ;
if ( V_24 -> V_51 )
F_153 ( V_24 -> V_51 ) ;
F_154 ( V_24 ) ;
F_6 ( V_24 ) ;
F_26 ( V_24 ) ;
}
static struct V_23 * F_155 ( unsigned int V_197 ,
unsigned int V_53 ,
bool V_198 )
{
unsigned int V_199 = V_81 * sizeof( struct V_31 ) ;
struct V_23 * V_24 ;
V_24 = F_156 ( sizeof( * V_24 ) , V_19 ) ;
if ( ! V_24 )
return NULL ;
V_24 -> V_53 = V_53 ;
F_157 ( & V_24 -> V_69 ) ;
F_47 ( & V_24 -> V_70 ) ;
F_158 ( & V_24 -> V_68 , F_40 ) ;
V_24 -> V_6 = F_1 ( V_53 + V_199 ) ;
if ( ! V_24 -> V_6 ) {
F_26 ( V_24 ) ;
return NULL ;
}
V_24 -> V_54 = F_150 ( V_197 , V_24 -> V_6 ) ;
if ( ! V_24 -> V_54 )
goto V_200;
if ( V_198 ) {
V_24 -> V_51 = F_149 ( V_197 ) ;
if ( ! V_24 -> V_51 )
goto V_200;
}
V_24 -> V_75 = F_159 ( L_3 , V_201 , 0 ) ;
if ( ! V_24 -> V_75 )
goto V_200;
return V_24 ;
V_200:
F_151 ( V_24 ) ;
return NULL ;
}
struct V_23 * F_160 ( unsigned int V_197 , unsigned int V_53 )
{
return F_155 ( V_197 , V_53 , true ) ;
}
struct V_23 * F_161 ( unsigned int V_197 , unsigned int V_53 )
{
return F_155 ( V_197 , V_53 , false ) ;
}
int F_162 ( struct V_4 * V_4 , struct V_202 * V_203 )
{
if ( F_18 ( V_4 -> V_204 ) )
return - V_205 ;
F_163 ( V_203 ) ;
V_4 -> V_204 = V_203 ;
return 0 ;
}
int F_164 ( struct V_4 * V_4 )
{
struct V_206 * V_207 ;
if ( V_4 -> V_204 )
return - V_205 ;
V_207 = V_74 -> V_206 ;
if ( ! V_207 )
return - V_208 ;
F_165 ( V_207 ) ;
V_4 -> V_209 = V_207 ;
V_4 -> V_204 = F_166 ( V_74 , V_210 ) ;
return 0 ;
}
void F_20 ( struct V_4 * V_4 )
{
if ( V_4 -> V_209 ) {
F_167 ( V_4 -> V_209 ) ;
V_4 -> V_209 = NULL ;
}
if ( V_4 -> V_204 ) {
F_168 ( V_4 -> V_204 ) ;
V_4 -> V_204 = NULL ;
}
}
static void T_4 F_169 ( void )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_33 ; V_10 ++ ) {
int V_194 ;
struct V_35 * V_36 = V_28 + V_10 ;
if ( V_36 -> V_29 <= V_81 ) {
V_36 -> V_5 = NULL ;
continue;
}
V_194 = V_36 -> V_29 * sizeof( struct V_31 ) ;
V_36 -> V_5 = F_4 ( V_36 -> V_20 , V_194 , 0 ,
V_22 | V_211 , NULL ) ;
}
}
static int T_4 F_170 ( void )
{
V_18 = 2 ;
V_13 = 0 ;
V_14 = F_156 ( V_18 * sizeof( struct V_6 ) , V_19 ) ;
if ( ! V_14 )
F_171 ( L_4 ) ;
F_172 () ;
F_169 () ;
V_212 = F_160 ( V_213 , 0 ) ;
if ( ! V_212 )
F_171 ( L_4 ) ;
if ( F_173 ( V_212 , V_213 ) )
F_171 ( L_5 ) ;
return 0 ;
}
