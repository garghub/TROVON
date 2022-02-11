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
if ( ! V_27 )
return;
V_27 -- ;
F_12 ( V_27 >= V_33 ) ;
if ( V_27 == V_34 ) {
F_13 ( V_32 , V_30 ) ;
} else {
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
( * V_27 ) ++ ;
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
F_11 ( V_24 -> V_50 , V_4 -> V_51 , F_24 ( V_4 ) ) ;
V_49 = V_4 ;
V_49 -= V_24 -> V_52 ;
F_13 ( V_49 , V_24 -> V_53 ) ;
} else {
F_25 ( V_4 ) ;
}
}
void F_26 ( struct V_4 * V_4 )
{
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
F_27 ( & V_4 -> V_54 , 1 ) ;
F_27 ( & V_4 -> V_55 , 1 ) ;
}
void F_28 ( struct V_4 * V_4 )
{
unsigned long V_56 = V_4 -> V_57 & ( ~ 0UL << V_58 ) ;
F_19 ( V_4 ) ;
memset ( V_4 , 0 , V_59 ) ;
V_4 -> V_57 = V_56 ;
F_27 ( & V_4 -> V_54 , 1 ) ;
}
static struct V_4 * F_29 ( struct V_4 * V_4 )
{
struct V_4 * V_60 = V_4 -> V_61 ;
if ( ! V_60 -> V_62 )
V_60 -> V_62 = V_4 -> V_62 ;
F_30 ( V_4 ) ;
return V_60 ;
}
static void F_31 ( struct V_4 * V_4 )
{
F_32 ( F_29 ( V_4 ) ) ;
}
void F_33 ( struct V_4 * V_4 , struct V_4 * V_60 )
{
F_34 ( V_4 -> V_61 || V_4 -> V_63 ) ;
V_4 -> V_61 = V_60 ;
V_4 -> V_63 = F_31 ;
F_35 ( V_60 ) ;
}
static void F_36 ( struct V_64 * V_65 )
{
struct V_23 * V_24 = F_37 ( V_65 , struct V_23 , V_66 ) ;
struct V_4 * V_4 ;
while ( 1 ) {
F_38 ( & V_24 -> V_67 ) ;
V_4 = F_39 ( & V_24 -> V_68 ) ;
F_40 ( & V_24 -> V_67 ) ;
if ( ! V_4 )
break;
F_41 ( V_4 ) ;
}
}
static void F_42 ( struct V_23 * V_24 )
{
struct V_69 V_70 , V_71 ;
struct V_4 * V_4 ;
F_43 ( & V_70 ) ;
F_43 ( & V_71 ) ;
while ( ( V_4 = F_39 ( V_72 -> V_69 ) ) )
F_44 ( V_4 -> V_48 == V_24 ? & V_70 : & V_71 , V_4 ) ;
* V_72 -> V_69 = V_71 ;
F_38 ( & V_24 -> V_67 ) ;
F_45 ( & V_24 -> V_68 , & V_70 ) ;
F_40 ( & V_24 -> V_67 ) ;
F_46 ( V_24 -> V_73 , & V_24 -> V_66 ) ;
}
struct V_4 * F_47 ( T_2 V_37 , int V_74 , struct V_23 * V_24 )
{
T_2 V_75 = V_37 ;
unsigned V_52 ;
unsigned V_76 ;
struct V_31 * V_39 = NULL ;
struct V_4 * V_4 ;
void * V_49 ;
if ( ! V_24 ) {
if ( V_74 > V_77 )
return NULL ;
V_49 = F_48 ( sizeof( struct V_4 ) +
V_74 * sizeof( struct V_31 ) ,
V_37 ) ;
V_52 = 0 ;
V_76 = V_74 ;
} else {
if ( F_49 ( ! V_24 -> V_50 && V_74 > 0 ) )
return NULL ;
if ( V_72 -> V_69 && ! F_50 ( V_72 -> V_69 ) )
V_37 &= ~ V_43 ;
V_49 = F_16 ( V_24 -> V_53 , V_37 ) ;
if ( ! V_49 && V_37 != V_75 ) {
F_42 ( V_24 ) ;
V_37 = V_75 ;
V_49 = F_16 ( V_24 -> V_53 , V_37 ) ;
}
V_52 = V_24 -> V_52 ;
V_76 = V_78 ;
}
if ( F_18 ( ! V_49 ) )
return NULL ;
V_4 = V_49 + V_52 ;
F_26 ( V_4 ) ;
if ( V_74 > V_76 ) {
unsigned long V_27 = 0 ;
V_39 = F_15 ( V_37 , V_74 , & V_27 , V_24 -> V_50 ) ;
if ( ! V_39 && V_37 != V_75 ) {
F_42 ( V_24 ) ;
V_37 = V_75 ;
V_39 = F_15 ( V_37 , V_74 , & V_27 , V_24 -> V_50 ) ;
}
if ( F_18 ( ! V_39 ) )
goto V_79;
V_4 -> V_57 |= V_27 << V_80 ;
} else if ( V_74 ) {
V_39 = V_4 -> V_81 ;
}
V_4 -> V_48 = V_24 ;
V_4 -> V_82 = V_74 ;
V_4 -> V_51 = V_39 ;
return V_4 ;
V_79:
F_13 ( V_49 , V_24 -> V_53 ) ;
return NULL ;
}
void F_51 ( struct V_4 * V_4 )
{
unsigned long V_56 ;
struct V_31 V_32 ;
struct V_83 V_84 ;
F_52 (bv, bio, iter) {
char * V_85 = F_53 ( & V_32 , & V_56 ) ;
memset ( V_85 , 0 , V_32 . V_86 ) ;
F_54 ( V_32 . V_87 ) ;
F_55 ( V_85 , & V_56 ) ;
}
}
void F_30 ( struct V_4 * V_4 )
{
if ( ! F_56 ( V_4 , V_88 ) )
F_23 ( V_4 ) ;
else {
F_12 ( ! F_57 ( & V_4 -> V_55 ) ) ;
if ( F_58 ( & V_4 -> V_55 ) )
F_23 ( V_4 ) ;
}
}
inline int F_59 ( struct V_89 * V_90 , struct V_4 * V_4 )
{
if ( F_18 ( ! F_56 ( V_4 , V_91 ) ) )
F_60 ( V_90 , V_4 ) ;
return V_4 -> V_92 ;
}
void F_61 ( struct V_4 * V_4 , struct V_4 * V_93 )
{
F_34 ( V_4 -> V_48 && F_24 ( V_4 ) ) ;
V_4 -> V_94 = V_93 -> V_94 ;
F_62 ( V_4 , V_95 ) ;
V_4 -> V_96 = V_93 -> V_96 ;
V_4 -> V_97 = V_93 -> V_97 ;
V_4 -> V_51 = V_93 -> V_51 ;
F_63 ( V_4 , V_93 ) ;
}
struct V_4 * F_64 ( struct V_4 * V_4 , T_2 V_37 , struct V_23 * V_24 )
{
struct V_4 * V_98 ;
V_98 = F_47 ( V_37 , 0 , V_24 ) ;
if ( ! V_98 )
return NULL ;
F_61 ( V_98 , V_4 ) ;
if ( F_21 ( V_4 ) ) {
int V_99 ;
V_99 = F_65 ( V_98 , V_4 , V_37 ) ;
if ( V_99 < 0 ) {
F_30 ( V_98 ) ;
return NULL ;
}
}
return V_98 ;
}
struct V_4 * F_66 ( struct V_4 * V_93 , T_2 V_37 ,
struct V_23 * V_24 )
{
struct V_83 V_84 ;
struct V_31 V_32 ;
struct V_4 * V_4 ;
V_4 = F_47 ( V_37 , F_67 ( V_93 ) , V_24 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_94 = V_93 -> V_94 ;
V_4 -> V_96 = V_93 -> V_96 ;
V_4 -> V_97 . V_100 = V_93 -> V_97 . V_100 ;
V_4 -> V_97 . V_101 = V_93 -> V_97 . V_101 ;
switch ( F_68 ( V_4 ) ) {
case V_102 :
case V_103 :
break;
case V_104 :
V_4 -> V_51 [ V_4 -> V_105 ++ ] = V_93 -> V_51 [ 0 ] ;
break;
default:
F_52 (bv, bio_src, iter)
V_4 -> V_51 [ V_4 -> V_105 ++ ] = V_32 ;
break;
}
if ( F_21 ( V_93 ) ) {
int V_99 ;
V_99 = F_65 ( V_4 , V_93 , V_37 ) ;
if ( V_99 < 0 ) {
F_30 ( V_4 ) ;
return NULL ;
}
}
F_63 ( V_4 , V_93 ) ;
return V_4 ;
}
int F_69 ( struct V_89 * V_90 , struct V_4 * V_4 , struct V_106
* V_106 , unsigned int V_107 , unsigned int V_108 )
{
int V_109 = 0 ;
struct V_31 * V_110 ;
if ( F_18 ( F_56 ( V_4 , V_95 ) ) )
return 0 ;
if ( ( ( V_4 -> V_97 . V_101 + V_107 ) >> 9 ) > F_70 ( V_90 ) )
return 0 ;
if ( V_4 -> V_105 > 0 ) {
struct V_31 * V_111 = & V_4 -> V_51 [ V_4 -> V_105 - 1 ] ;
if ( V_106 == V_111 -> V_87 &&
V_108 == V_111 -> V_112 + V_111 -> V_86 ) {
V_111 -> V_86 += V_107 ;
V_4 -> V_97 . V_101 += V_107 ;
goto V_113;
}
if ( F_71 ( V_90 , V_111 , V_108 ) )
return 0 ;
}
if ( V_4 -> V_105 >= V_4 -> V_82 )
return 0 ;
V_110 = & V_4 -> V_51 [ V_4 -> V_105 ] ;
V_110 -> V_87 = V_106 ;
V_110 -> V_86 = V_107 ;
V_110 -> V_112 = V_108 ;
V_4 -> V_105 ++ ;
V_4 -> V_92 ++ ;
V_4 -> V_97 . V_101 += V_107 ;
while ( V_4 -> V_92 > F_72 ( V_90 ) ) {
if ( V_109 )
goto V_114;
V_109 = 1 ;
F_60 ( V_90 , V_4 ) ;
}
if ( V_4 -> V_105 > 1 && ( F_73 ( V_110 - 1 , V_110 ) ) )
F_74 ( V_4 , V_91 ) ;
V_113:
return V_107 ;
V_114:
V_110 -> V_87 = NULL ;
V_110 -> V_86 = 0 ;
V_110 -> V_112 = 0 ;
V_4 -> V_105 -- ;
V_4 -> V_97 . V_101 -= V_107 ;
F_60 ( V_90 , V_4 ) ;
return 0 ;
}
int F_75 ( struct V_4 * V_4 , struct V_106 * V_106 ,
unsigned int V_107 , unsigned int V_108 )
{
struct V_31 * V_32 ;
if ( F_49 ( F_56 ( V_4 , V_95 ) ) )
return 0 ;
if ( V_4 -> V_105 > 0 ) {
V_32 = & V_4 -> V_51 [ V_4 -> V_105 - 1 ] ;
if ( V_106 == V_32 -> V_87 &&
V_108 == V_32 -> V_112 + V_32 -> V_86 ) {
V_32 -> V_86 += V_107 ;
goto V_113;
}
}
if ( V_4 -> V_105 >= V_4 -> V_82 )
return 0 ;
V_32 = & V_4 -> V_51 [ V_4 -> V_105 ] ;
V_32 -> V_87 = V_106 ;
V_32 -> V_86 = V_107 ;
V_32 -> V_112 = V_108 ;
V_4 -> V_105 ++ ;
V_113:
V_4 -> V_97 . V_101 += V_107 ;
return V_107 ;
}
static void F_76 ( struct V_4 * V_4 )
{
struct V_115 * V_99 = V_4 -> V_61 ;
V_99 -> error = V_4 -> V_62 ;
F_77 ( & V_99 -> V_116 ) ;
}
int F_78 ( struct V_4 * V_4 )
{
struct V_115 V_99 ;
F_79 ( & V_99 . V_116 ) ;
V_4 -> V_61 = & V_99 ;
V_4 -> V_63 = F_76 ;
V_4 -> V_96 |= V_117 ;
F_80 ( V_4 ) ;
F_81 ( & V_99 . V_116 ) ;
return V_99 . error ;
}
void F_82 ( struct V_4 * V_4 , unsigned V_118 )
{
if ( F_21 ( V_4 ) )
F_83 ( V_4 , V_118 ) ;
F_84 ( V_4 , & V_4 -> V_97 , V_118 ) ;
}
int F_85 ( struct V_4 * V_4 , T_2 V_37 )
{
int V_10 ;
struct V_31 * V_32 ;
F_86 (bv, bio, i) {
V_32 -> V_87 = F_87 ( V_37 ) ;
if ( ! V_32 -> V_87 ) {
while ( -- V_32 >= V_4 -> V_51 )
F_88 ( V_32 -> V_87 ) ;
return - V_119 ;
}
}
return 0 ;
}
void F_89 ( struct V_4 * V_120 , struct V_4 * V_121 )
{
struct V_83 V_122 , V_123 ;
struct V_31 V_124 , V_125 ;
void * V_126 , * V_127 ;
unsigned V_118 ;
V_122 = V_121 -> V_97 ;
V_123 = V_120 -> V_97 ;
while ( 1 ) {
if ( ! V_122 . V_101 ) {
V_121 = V_121 -> V_128 ;
if ( ! V_121 )
break;
V_122 = V_121 -> V_97 ;
}
if ( ! V_123 . V_101 ) {
V_120 = V_120 -> V_128 ;
if ( ! V_120 )
break;
V_123 = V_120 -> V_97 ;
}
V_124 = F_90 ( V_121 , V_122 ) ;
V_125 = F_90 ( V_120 , V_123 ) ;
V_118 = F_91 ( V_124 . V_86 , V_125 . V_86 ) ;
V_126 = F_92 ( V_124 . V_87 ) ;
V_127 = F_92 ( V_125 . V_87 ) ;
memcpy ( V_127 + V_125 . V_112 ,
V_126 + V_124 . V_112 ,
V_118 ) ;
F_93 ( V_127 ) ;
F_93 ( V_126 ) ;
F_84 ( V_121 , & V_122 , V_118 ) ;
F_84 ( V_120 , & V_123 , V_118 ) ;
}
}
static struct V_129 * F_94 ( unsigned int V_130 ,
T_2 V_37 )
{
if ( V_130 > V_77 )
return NULL ;
return F_48 ( sizeof( struct V_129 ) +
sizeof( struct V_131 ) * V_130 , V_37 ) ;
}
static int F_95 ( struct V_4 * V_4 , struct V_132 V_84 )
{
int V_10 ;
struct V_31 * V_110 ;
F_86 (bvec, bio, i) {
T_3 V_99 ;
V_99 = F_96 ( V_110 -> V_87 ,
V_110 -> V_112 ,
V_110 -> V_86 ,
& V_84 ) ;
if ( ! F_97 ( & V_84 ) )
break;
if ( V_99 < V_110 -> V_86 )
return - V_133 ;
}
return 0 ;
}
static int F_98 ( struct V_4 * V_4 , struct V_132 V_84 )
{
int V_10 ;
struct V_31 * V_110 ;
F_86 (bvec, bio, i) {
T_3 V_99 ;
V_99 = F_99 ( V_110 -> V_87 ,
V_110 -> V_112 ,
V_110 -> V_86 ,
& V_84 ) ;
if ( ! F_97 ( & V_84 ) )
break;
if ( V_99 < V_110 -> V_86 )
return - V_133 ;
}
return 0 ;
}
void F_100 ( struct V_4 * V_4 )
{
struct V_31 * V_110 ;
int V_10 ;
F_86 (bvec, bio, i)
F_88 ( V_110 -> V_87 ) ;
}
int F_101 ( struct V_4 * V_4 )
{
struct V_129 * V_134 = V_4 -> V_61 ;
int V_99 = 0 ;
if ( ! F_56 ( V_4 , V_135 ) ) {
if ( ! V_72 -> V_136 )
V_99 = - V_137 ;
else if ( F_102 ( V_4 ) == V_138 )
V_99 = F_98 ( V_4 , V_134 -> V_84 ) ;
if ( V_134 -> V_139 )
F_100 ( V_4 ) ;
}
F_25 ( V_134 ) ;
F_30 ( V_4 ) ;
return V_99 ;
}
struct V_4 * F_103 ( struct V_89 * V_90 ,
struct V_140 * V_141 ,
const struct V_132 * V_84 ,
T_2 V_37 )
{
struct V_129 * V_134 ;
struct V_106 * V_106 ;
struct V_4 * V_4 ;
int V_10 , V_99 ;
int V_142 = 0 ;
unsigned int V_107 = V_84 -> V_143 ;
unsigned int V_108 = V_141 ? F_104 ( V_141 -> V_108 ) : 0 ;
for ( V_10 = 0 ; V_10 < V_84 -> V_144 ; V_10 ++ ) {
unsigned long V_145 ;
unsigned long V_146 ;
unsigned long V_147 ;
V_145 = ( unsigned long ) V_84 -> V_148 [ V_10 ] . V_149 ;
V_146 = ( V_145 + V_84 -> V_148 [ V_10 ] . V_150 + V_151 - 1 )
>> V_152 ;
V_147 = V_145 >> V_152 ;
if ( V_146 < V_147 )
return F_105 ( - V_153 ) ;
V_142 += V_146 - V_147 ;
}
if ( V_108 )
V_142 ++ ;
V_134 = F_94 ( V_84 -> V_144 , V_37 ) ;
if ( ! V_134 )
return F_105 ( - V_119 ) ;
V_134 -> V_139 = V_141 ? 0 : 1 ;
memcpy ( V_134 -> V_148 , V_84 -> V_148 , sizeof( struct V_131 ) * V_84 -> V_144 ) ;
F_106 ( & V_134 -> V_84 , V_84 -> type , V_134 -> V_148 ,
V_84 -> V_144 , V_84 -> V_143 ) ;
V_99 = - V_119 ;
V_4 = F_107 ( V_37 , V_142 ) ;
if ( ! V_4 )
goto V_154;
if ( V_84 -> type & V_155 )
F_108 ( V_4 , V_156 , 0 ) ;
V_99 = 0 ;
if ( V_141 ) {
V_142 = 1 << V_141 -> V_157 ;
V_10 = V_141 -> V_108 / V_151 ;
}
while ( V_107 ) {
unsigned int V_118 = V_151 ;
V_118 -= V_108 ;
if ( V_118 > V_107 )
V_118 = V_107 ;
if ( V_141 ) {
if ( V_10 == V_141 -> V_158 * V_142 ) {
V_99 = - V_119 ;
break;
}
V_106 = V_141 -> V_159 [ V_10 / V_142 ] ;
V_106 += ( V_10 % V_142 ) ;
V_10 ++ ;
} else {
V_106 = F_87 ( V_90 -> V_160 | V_37 ) ;
if ( ! V_106 ) {
V_99 = - V_119 ;
break;
}
}
if ( F_69 ( V_90 , V_4 , V_106 , V_118 , V_108 ) < V_118 )
break;
V_107 -= V_118 ;
V_108 = 0 ;
}
if ( V_99 )
goto V_161;
if ( ( ( V_84 -> type & V_155 ) && ( ! V_141 || ! V_141 -> V_162 ) ) ||
( V_141 && V_141 -> V_163 ) ) {
V_99 = F_95 ( V_4 , * V_84 ) ;
if ( V_99 )
goto V_161;
}
V_4 -> V_61 = V_134 ;
return V_4 ;
V_161:
if ( ! V_141 )
F_100 ( V_4 ) ;
F_30 ( V_4 ) ;
V_154:
F_25 ( V_134 ) ;
return F_105 ( V_99 ) ;
}
struct V_4 * F_109 ( struct V_89 * V_90 ,
const struct V_132 * V_84 ,
T_2 V_37 )
{
int V_164 ;
int V_142 = 0 ;
struct V_106 * * V_159 ;
struct V_4 * V_4 ;
int V_165 = 0 ;
int V_99 , V_108 ;
struct V_132 V_10 ;
struct V_131 V_148 ;
F_110 (iov, i, *iter) {
unsigned long V_145 = ( unsigned long ) V_148 . V_149 ;
unsigned long V_107 = V_148 . V_150 ;
unsigned long V_146 = ( V_145 + V_107 + V_151 - 1 ) >> V_152 ;
unsigned long V_147 = V_145 >> V_152 ;
if ( V_146 < V_147 )
return F_105 ( - V_153 ) ;
V_142 += V_146 - V_147 ;
if ( V_145 & F_111 ( V_90 ) )
return F_105 ( - V_153 ) ;
}
if ( ! V_142 )
return F_105 ( - V_153 ) ;
V_4 = F_107 ( V_37 , V_142 ) ;
if ( ! V_4 )
return F_105 ( - V_119 ) ;
V_99 = - V_119 ;
V_159 = F_112 ( V_142 , sizeof( struct V_106 * ) , V_37 ) ;
if ( ! V_159 )
goto V_26;
F_110 (iov, i, *iter) {
unsigned long V_145 = ( unsigned long ) V_148 . V_149 ;
unsigned long V_107 = V_148 . V_150 ;
unsigned long V_146 = ( V_145 + V_107 + V_151 - 1 ) >> V_152 ;
unsigned long V_147 = V_145 >> V_152 ;
const int V_166 = V_146 - V_147 ;
const int V_167 = V_165 + V_166 ;
V_99 = F_113 ( V_145 , V_166 ,
( V_84 -> type & V_155 ) != V_155 ,
& V_159 [ V_165 ] ) ;
if ( V_99 < V_166 ) {
V_99 = - V_133 ;
goto V_168;
}
V_108 = F_104 ( V_145 ) ;
for ( V_164 = V_165 ; V_164 < V_167 ; V_164 ++ ) {
unsigned int V_118 = V_151 - V_108 ;
if ( V_107 <= 0 )
break;
if ( V_118 > V_107 )
V_118 = V_107 ;
if ( F_69 ( V_90 , V_4 , V_159 [ V_164 ] , V_118 , V_108 ) <
V_118 )
break;
V_107 -= V_118 ;
V_108 = 0 ;
}
V_165 = V_164 ;
while ( V_164 < V_167 )
F_114 ( V_159 [ V_164 ++ ] ) ;
}
F_25 ( V_159 ) ;
if ( V_84 -> type & V_155 )
F_108 ( V_4 , V_156 , 0 ) ;
F_62 ( V_4 , V_169 ) ;
F_115 ( V_4 ) ;
return V_4 ;
V_168:
for ( V_164 = 0 ; V_164 < V_142 ; V_164 ++ ) {
if ( ! V_159 [ V_164 ] )
break;
F_114 ( V_159 [ V_164 ] ) ;
}
V_26:
F_25 ( V_159 ) ;
F_30 ( V_4 ) ;
return F_105 ( V_99 ) ;
}
static void F_116 ( struct V_4 * V_4 )
{
struct V_31 * V_110 ;
int V_10 ;
F_86 (bvec, bio, i) {
if ( F_102 ( V_4 ) == V_138 )
F_117 ( V_110 -> V_87 ) ;
F_114 ( V_110 -> V_87 ) ;
}
F_30 ( V_4 ) ;
}
void F_118 ( struct V_4 * V_4 )
{
F_116 ( V_4 ) ;
F_30 ( V_4 ) ;
}
static void F_119 ( struct V_4 * V_4 )
{
F_30 ( V_4 ) ;
}
struct V_4 * F_120 ( struct V_89 * V_90 , void * V_85 , unsigned int V_107 ,
T_2 V_37 )
{
unsigned long V_170 = ( unsigned long ) V_85 ;
unsigned long V_146 = ( V_170 + V_107 + V_151 - 1 ) >> V_152 ;
unsigned long V_147 = V_170 >> V_152 ;
const int V_142 = V_146 - V_147 ;
int V_108 , V_10 ;
struct V_4 * V_4 ;
V_4 = F_107 ( V_37 , V_142 ) ;
if ( ! V_4 )
return F_105 ( - V_119 ) ;
V_108 = F_104 ( V_170 ) ;
for ( V_10 = 0 ; V_10 < V_142 ; V_10 ++ ) {
unsigned int V_118 = V_151 - V_108 ;
if ( V_107 <= 0 )
break;
if ( V_118 > V_107 )
V_118 = V_107 ;
if ( F_69 ( V_90 , V_4 , F_121 ( V_85 ) , V_118 ,
V_108 ) < V_118 ) {
F_30 ( V_4 ) ;
return F_105 ( - V_153 ) ;
}
V_85 += V_118 ;
V_107 -= V_118 ;
V_108 = 0 ;
}
V_4 -> V_63 = F_119 ;
return V_4 ;
}
static void F_122 ( struct V_4 * V_4 )
{
F_100 ( V_4 ) ;
F_30 ( V_4 ) ;
}
static void F_123 ( struct V_4 * V_4 )
{
char * V_49 = V_4 -> V_61 ;
struct V_31 * V_110 ;
int V_10 ;
F_86 (bvec, bio, i) {
memcpy ( V_49 , F_124 ( V_110 -> V_87 ) , V_110 -> V_86 ) ;
V_49 += V_110 -> V_86 ;
}
F_122 ( V_4 ) ;
}
struct V_4 * F_125 ( struct V_89 * V_90 , void * V_85 , unsigned int V_107 ,
T_2 V_37 , int V_171 )
{
unsigned long V_170 = ( unsigned long ) V_85 ;
unsigned long V_146 = ( V_170 + V_107 + V_151 - 1 ) >> V_152 ;
unsigned long V_147 = V_170 >> V_152 ;
struct V_4 * V_4 ;
void * V_49 = V_85 ;
int V_142 = 0 ;
if ( V_146 < V_147 )
return F_105 ( - V_153 ) ;
V_142 = V_146 - V_147 ;
V_4 = F_107 ( V_37 , V_142 ) ;
if ( ! V_4 )
return F_105 ( - V_119 ) ;
while ( V_107 ) {
struct V_106 * V_106 ;
unsigned int V_118 = V_151 ;
if ( V_118 > V_107 )
V_118 = V_107 ;
V_106 = F_87 ( V_90 -> V_160 | V_37 ) ;
if ( ! V_106 )
goto V_161;
if ( ! V_171 )
memcpy ( F_124 ( V_106 ) , V_49 , V_118 ) ;
if ( F_69 ( V_90 , V_4 , V_106 , V_118 , 0 ) < V_118 )
break;
V_107 -= V_118 ;
V_49 += V_118 ;
}
if ( V_171 ) {
V_4 -> V_63 = F_123 ;
V_4 -> V_61 = V_85 ;
} else {
V_4 -> V_63 = F_122 ;
F_108 ( V_4 , V_156 , 0 ) ;
}
return V_4 ;
V_161:
F_100 ( V_4 ) ;
F_30 ( V_4 ) ;
return F_105 ( - V_119 ) ;
}
void F_126 ( struct V_4 * V_4 )
{
struct V_31 * V_110 ;
int V_10 ;
F_86 (bvec, bio, i) {
struct V_106 * V_106 = V_110 -> V_87 ;
if ( V_106 && ! F_127 ( V_106 ) )
F_117 ( V_106 ) ;
}
}
static void F_128 ( struct V_4 * V_4 )
{
struct V_31 * V_110 ;
int V_10 ;
F_86 (bvec, bio, i) {
struct V_106 * V_106 = V_110 -> V_87 ;
if ( V_106 )
F_114 ( V_106 ) ;
}
}
static void F_129 ( struct V_64 * V_65 )
{
unsigned long V_56 ;
struct V_4 * V_4 ;
F_130 ( & V_172 , V_56 ) ;
V_4 = V_173 ;
V_173 = NULL ;
F_131 ( & V_172 , V_56 ) ;
while ( V_4 ) {
struct V_4 * V_174 = V_4 -> V_61 ;
F_126 ( V_4 ) ;
F_128 ( V_4 ) ;
F_30 ( V_4 ) ;
V_4 = V_174 ;
}
}
void F_132 ( struct V_4 * V_4 )
{
struct V_31 * V_110 ;
int V_175 = 0 ;
int V_10 ;
F_86 (bvec, bio, i) {
struct V_106 * V_106 = V_110 -> V_87 ;
if ( F_133 ( V_106 ) || F_127 ( V_106 ) ) {
F_114 ( V_106 ) ;
V_110 -> V_87 = NULL ;
} else {
V_175 ++ ;
}
}
if ( V_175 ) {
unsigned long V_56 ;
F_130 ( & V_172 , V_56 ) ;
V_4 -> V_61 = V_173 ;
V_173 = V_4 ;
F_131 ( & V_172 , V_56 ) ;
F_134 ( & V_176 ) ;
} else {
F_30 ( V_4 ) ;
}
}
void F_135 ( int V_177 , unsigned long V_178 ,
struct V_179 * V_180 )
{
int V_181 = F_136 () ;
F_137 ( V_181 , V_180 ) ;
F_138 ( V_181 , V_180 , V_182 [ V_177 ] ) ;
F_139 ( V_181 , V_180 , V_178 [ V_177 ] , V_178 ) ;
F_140 ( V_180 , V_177 ) ;
F_141 () ;
}
void F_142 ( int V_177 , struct V_179 * V_180 ,
unsigned long V_183 )
{
unsigned long V_184 = V_185 - V_183 ;
int V_181 = F_136 () ;
F_139 ( V_181 , V_180 , V_186 [ V_177 ] , V_184 ) ;
F_137 ( V_181 , V_180 ) ;
F_143 ( V_180 , V_177 ) ;
F_141 () ;
}
void F_144 ( struct V_4 * V_187 )
{
struct V_31 V_110 ;
struct V_83 V_84 ;
F_52 (bvec, bi, iter)
F_54 ( V_110 . V_87 ) ;
}
static inline bool F_145 ( struct V_4 * V_4 )
{
if ( ! F_56 ( V_4 , V_188 ) )
return true ;
F_34 ( F_57 ( & V_4 -> V_54 ) <= 0 ) ;
if ( F_58 ( & V_4 -> V_54 ) ) {
F_74 ( V_4 , V_188 ) ;
return true ;
}
return false ;
}
void F_32 ( struct V_4 * V_4 )
{
V_189:
if ( ! F_145 ( V_4 ) )
return;
if ( V_4 -> V_63 == F_31 ) {
V_4 = F_29 ( V_4 ) ;
goto V_189;
}
if ( V_4 -> V_63 )
V_4 -> V_63 ( V_4 ) ;
}
struct V_4 * F_146 ( struct V_4 * V_4 , int V_178 ,
T_2 V_190 , struct V_23 * V_24 )
{
struct V_4 * V_191 = NULL ;
F_34 ( V_178 <= 0 ) ;
F_34 ( V_178 >= F_147 ( V_4 ) ) ;
if ( F_68 ( V_4 ) == V_102 || F_68 ( V_4 ) == V_103 )
V_191 = F_66 ( V_4 , V_190 , V_24 ) ;
else
V_191 = F_64 ( V_4 , V_190 , V_24 ) ;
if ( ! V_191 )
return NULL ;
V_191 -> V_97 . V_101 = V_178 << 9 ;
if ( F_21 ( V_191 ) )
F_148 ( V_191 , 0 , V_178 ) ;
F_82 ( V_4 , V_191 -> V_97 . V_101 ) ;
return V_191 ;
}
void F_149 ( struct V_4 * V_4 , int V_108 , int V_192 )
{
V_192 <<= 9 ;
if ( V_108 == 0 && V_192 == V_4 -> V_97 . V_101 )
return;
F_74 ( V_4 , V_91 ) ;
F_82 ( V_4 , V_108 << 9 ) ;
V_4 -> V_97 . V_101 = V_192 ;
}
T_1 * F_150 ( int V_193 )
{
struct V_35 * V_194 = V_28 + V_34 ;
return F_151 ( V_193 , V_194 -> V_5 ) ;
}
void F_152 ( struct V_23 * V_24 )
{
if ( V_24 -> V_73 )
F_153 ( V_24 -> V_73 ) ;
if ( V_24 -> V_53 )
F_154 ( V_24 -> V_53 ) ;
if ( V_24 -> V_50 )
F_154 ( V_24 -> V_50 ) ;
F_155 ( V_24 ) ;
F_6 ( V_24 ) ;
F_25 ( V_24 ) ;
}
static struct V_23 * F_156 ( unsigned int V_195 ,
unsigned int V_52 ,
bool V_196 )
{
unsigned int V_197 = V_78 * sizeof( struct V_31 ) ;
struct V_23 * V_24 ;
V_24 = F_157 ( sizeof( * V_24 ) , V_19 ) ;
if ( ! V_24 )
return NULL ;
V_24 -> V_52 = V_52 ;
F_158 ( & V_24 -> V_67 ) ;
F_43 ( & V_24 -> V_68 ) ;
F_159 ( & V_24 -> V_66 , F_36 ) ;
V_24 -> V_6 = F_1 ( V_52 + V_197 ) ;
if ( ! V_24 -> V_6 ) {
F_25 ( V_24 ) ;
return NULL ;
}
V_24 -> V_53 = F_151 ( V_195 , V_24 -> V_6 ) ;
if ( ! V_24 -> V_53 )
goto V_198;
if ( V_196 ) {
V_24 -> V_50 = F_150 ( V_195 ) ;
if ( ! V_24 -> V_50 )
goto V_198;
}
V_24 -> V_73 = F_160 ( L_3 , V_199 , 0 ) ;
if ( ! V_24 -> V_73 )
goto V_198;
return V_24 ;
V_198:
F_152 ( V_24 ) ;
return NULL ;
}
struct V_23 * F_161 ( unsigned int V_195 , unsigned int V_52 )
{
return F_156 ( V_195 , V_52 , true ) ;
}
struct V_23 * F_162 ( unsigned int V_195 , unsigned int V_52 )
{
return F_156 ( V_195 , V_52 , false ) ;
}
int F_163 ( struct V_4 * V_4 , struct V_200 * V_201 )
{
if ( F_18 ( V_4 -> V_202 ) )
return - V_203 ;
F_164 ( V_201 ) ;
V_4 -> V_202 = V_201 ;
return 0 ;
}
int F_165 ( struct V_4 * V_4 )
{
struct V_204 * V_205 ;
if ( V_4 -> V_202 )
return - V_203 ;
V_205 = V_72 -> V_204 ;
if ( ! V_205 )
return - V_206 ;
F_166 ( V_205 ) ;
V_4 -> V_207 = V_205 ;
V_4 -> V_202 = F_167 ( V_72 , V_208 ) ;
return 0 ;
}
void F_20 ( struct V_4 * V_4 )
{
if ( V_4 -> V_207 ) {
F_168 ( V_4 -> V_207 ) ;
V_4 -> V_207 = NULL ;
}
if ( V_4 -> V_202 ) {
F_169 ( V_4 -> V_202 ) ;
V_4 -> V_202 = NULL ;
}
}
void F_63 ( struct V_4 * V_120 , struct V_4 * V_121 )
{
if ( V_121 -> V_202 )
F_8 ( F_163 ( V_120 , V_121 -> V_202 ) ) ;
}
static void T_4 F_170 ( void )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_33 ; V_10 ++ ) {
int V_192 ;
struct V_35 * V_36 = V_28 + V_10 ;
if ( V_36 -> V_29 <= V_78 ) {
V_36 -> V_5 = NULL ;
continue;
}
V_192 = V_36 -> V_29 * sizeof( struct V_31 ) ;
V_36 -> V_5 = F_4 ( V_36 -> V_20 , V_192 , 0 ,
V_22 | V_209 , NULL ) ;
}
}
static int T_4 F_171 ( void )
{
V_18 = 2 ;
V_13 = 0 ;
V_14 = F_157 ( V_18 * sizeof( struct V_6 ) , V_19 ) ;
if ( ! V_14 )
F_172 ( L_4 ) ;
F_173 () ;
F_170 () ;
V_210 = F_161 ( V_211 , 0 ) ;
if ( ! V_210 )
F_172 ( L_4 ) ;
if ( F_174 ( V_210 , V_211 ) )
F_172 ( L_5 ) ;
return 0 ;
}
