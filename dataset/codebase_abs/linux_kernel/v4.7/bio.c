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
void F_34 ( struct V_4 * V_4 , struct V_4 * V_61 )
{
F_35 ( V_4 -> V_62 || V_4 -> V_64 ) ;
V_4 -> V_62 = V_61 ;
V_4 -> V_64 = F_32 ;
F_36 ( V_61 ) ;
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
if ( F_50 ( ! V_24 -> V_51 && V_75 > 0 ) )
return NULL ;
if ( V_73 -> V_70 && ! F_51 ( V_73 -> V_70 ) )
V_37 &= ~ V_43 ;
V_49 = F_16 ( V_24 -> V_54 , V_37 ) ;
if ( ! V_49 && V_37 != V_76 ) {
F_43 ( V_24 ) ;
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
F_43 ( V_24 ) ;
V_37 = V_76 ;
V_39 = F_15 ( V_37 , V_75 , & V_27 , V_24 -> V_51 ) ;
}
if ( F_18 ( ! V_39 ) )
goto V_81;
F_52 ( V_4 , V_50 ) ;
} else if ( V_75 ) {
V_39 = V_4 -> V_82 ;
}
V_4 -> V_48 = V_24 ;
V_4 -> V_58 |= V_27 << V_83 ;
V_4 -> V_84 = V_75 ;
V_4 -> V_52 = V_39 ;
return V_4 ;
V_81:
F_13 ( V_49 , V_24 -> V_54 ) ;
return NULL ;
}
void F_53 ( struct V_4 * V_4 )
{
unsigned long V_57 ;
struct V_31 V_32 ;
struct V_85 V_86 ;
F_54 (bv, bio, iter) {
char * V_87 = F_55 ( & V_32 , & V_57 ) ;
memset ( V_87 , 0 , V_32 . V_88 ) ;
F_56 ( V_32 . V_89 ) ;
F_57 ( V_87 , & V_57 ) ;
}
}
void F_31 ( struct V_4 * V_4 )
{
if ( ! F_24 ( V_4 , V_90 ) )
F_23 ( V_4 ) ;
else {
F_12 ( ! F_58 ( & V_4 -> V_56 ) ) ;
if ( F_59 ( & V_4 -> V_56 ) )
F_23 ( V_4 ) ;
}
}
inline int F_60 ( struct V_91 * V_92 , struct V_4 * V_4 )
{
if ( F_18 ( ! F_24 ( V_4 , V_93 ) ) )
F_61 ( V_92 , V_4 ) ;
return V_4 -> V_94 ;
}
void F_62 ( struct V_4 * V_4 , struct V_4 * V_95 )
{
F_35 ( V_4 -> V_48 && F_25 ( V_4 ) != V_78 ) ;
V_4 -> V_96 = V_95 -> V_96 ;
F_52 ( V_4 , V_97 ) ;
V_4 -> V_98 = V_95 -> V_98 ;
V_4 -> V_99 = V_95 -> V_99 ;
V_4 -> V_52 = V_95 -> V_52 ;
}
struct V_4 * F_63 ( struct V_4 * V_4 , T_2 V_37 , struct V_23 * V_24 )
{
struct V_4 * V_100 ;
V_100 = F_48 ( V_37 , 0 , V_24 ) ;
if ( ! V_100 )
return NULL ;
F_62 ( V_100 , V_4 ) ;
if ( F_21 ( V_4 ) ) {
int V_101 ;
V_101 = F_64 ( V_100 , V_4 , V_37 ) ;
if ( V_101 < 0 ) {
F_31 ( V_100 ) ;
return NULL ;
}
}
return V_100 ;
}
struct V_4 * F_65 ( struct V_4 * V_95 , T_2 V_37 ,
struct V_23 * V_24 )
{
struct V_85 V_86 ;
struct V_31 V_32 ;
struct V_4 * V_4 ;
V_4 = F_48 ( V_37 , F_66 ( V_95 ) , V_24 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_96 = V_95 -> V_96 ;
V_4 -> V_98 = V_95 -> V_98 ;
V_4 -> V_99 . V_102 = V_95 -> V_99 . V_102 ;
V_4 -> V_99 . V_103 = V_95 -> V_99 . V_103 ;
if ( V_4 -> V_98 & V_104 )
goto V_105;
if ( V_4 -> V_98 & V_106 ) {
V_4 -> V_52 [ V_4 -> V_107 ++ ] = V_95 -> V_52 [ 0 ] ;
goto V_105;
}
F_54 (bv, bio_src, iter)
V_4 -> V_52 [ V_4 -> V_107 ++ ] = V_32 ;
V_105:
if ( F_21 ( V_95 ) ) {
int V_101 ;
V_101 = F_64 ( V_4 , V_95 , V_37 ) ;
if ( V_101 < 0 ) {
F_31 ( V_4 ) ;
return NULL ;
}
}
return V_4 ;
}
int F_67 ( struct V_91 * V_92 , struct V_4 * V_4 , struct V_108
* V_108 , unsigned int V_109 , unsigned int V_110 )
{
int V_111 = 0 ;
struct V_31 * V_112 ;
if ( F_18 ( F_24 ( V_4 , V_97 ) ) )
return 0 ;
if ( ( ( V_4 -> V_99 . V_103 + V_109 ) >> 9 ) > F_68 ( V_92 ) )
return 0 ;
if ( V_4 -> V_107 > 0 ) {
struct V_31 * V_113 = & V_4 -> V_52 [ V_4 -> V_107 - 1 ] ;
if ( V_108 == V_113 -> V_89 &&
V_110 == V_113 -> V_114 + V_113 -> V_88 ) {
V_113 -> V_88 += V_109 ;
V_4 -> V_99 . V_103 += V_109 ;
goto V_115;
}
if ( F_69 ( V_92 , V_113 , V_110 ) )
return 0 ;
}
if ( V_4 -> V_107 >= V_4 -> V_84 )
return 0 ;
V_112 = & V_4 -> V_52 [ V_4 -> V_107 ] ;
V_112 -> V_89 = V_108 ;
V_112 -> V_88 = V_109 ;
V_112 -> V_114 = V_110 ;
V_4 -> V_107 ++ ;
V_4 -> V_94 ++ ;
V_4 -> V_99 . V_103 += V_109 ;
while ( V_4 -> V_94 > F_70 ( V_92 ) ) {
if ( V_111 )
goto V_116;
V_111 = 1 ;
F_61 ( V_92 , V_4 ) ;
}
if ( V_4 -> V_107 > 1 && ( F_71 ( V_112 - 1 , V_112 ) ) )
F_72 ( V_4 , V_93 ) ;
V_115:
return V_109 ;
V_116:
V_112 -> V_89 = NULL ;
V_112 -> V_88 = 0 ;
V_112 -> V_114 = 0 ;
V_4 -> V_107 -- ;
V_4 -> V_99 . V_103 -= V_109 ;
F_61 ( V_92 , V_4 ) ;
return 0 ;
}
int F_73 ( struct V_4 * V_4 , struct V_108 * V_108 ,
unsigned int V_109 , unsigned int V_110 )
{
struct V_31 * V_32 ;
if ( F_50 ( F_24 ( V_4 , V_97 ) ) )
return 0 ;
if ( V_4 -> V_107 > 0 ) {
V_32 = & V_4 -> V_52 [ V_4 -> V_107 - 1 ] ;
if ( V_108 == V_32 -> V_89 &&
V_110 == V_32 -> V_114 + V_32 -> V_88 ) {
V_32 -> V_88 += V_109 ;
goto V_115;
}
}
if ( V_4 -> V_107 >= V_4 -> V_84 )
return 0 ;
V_32 = & V_4 -> V_52 [ V_4 -> V_107 ] ;
V_32 -> V_89 = V_108 ;
V_32 -> V_88 = V_109 ;
V_32 -> V_114 = V_110 ;
V_4 -> V_107 ++ ;
V_115:
V_4 -> V_99 . V_103 += V_109 ;
return V_109 ;
}
static void F_74 ( struct V_4 * V_4 )
{
struct V_117 * V_101 = V_4 -> V_62 ;
V_101 -> error = V_4 -> V_63 ;
F_75 ( & V_101 -> V_118 ) ;
}
int F_76 ( int V_119 , struct V_4 * V_4 )
{
struct V_117 V_101 ;
V_119 |= V_120 ;
F_77 ( & V_101 . V_118 ) ;
V_4 -> V_62 = & V_101 ;
V_4 -> V_64 = F_74 ;
F_78 ( V_119 , V_4 ) ;
F_79 ( & V_101 . V_118 ) ;
return V_101 . error ;
}
void F_80 ( struct V_4 * V_4 , unsigned V_121 )
{
if ( F_21 ( V_4 ) )
F_81 ( V_4 , V_121 ) ;
F_82 ( V_4 , & V_4 -> V_99 , V_121 ) ;
}
int F_83 ( struct V_4 * V_4 , T_2 V_37 )
{
int V_10 ;
struct V_31 * V_32 ;
F_84 (bv, bio, i) {
V_32 -> V_89 = F_85 ( V_37 ) ;
if ( ! V_32 -> V_89 ) {
while ( -- V_32 >= V_4 -> V_52 )
F_86 ( V_32 -> V_89 ) ;
return - V_122 ;
}
}
return 0 ;
}
void F_87 ( struct V_4 * V_123 , struct V_4 * V_124 )
{
struct V_85 V_125 , V_126 ;
struct V_31 V_127 , V_128 ;
void * V_129 , * V_130 ;
unsigned V_121 ;
V_125 = V_124 -> V_99 ;
V_126 = V_123 -> V_99 ;
while ( 1 ) {
if ( ! V_125 . V_103 ) {
V_124 = V_124 -> V_131 ;
if ( ! V_124 )
break;
V_125 = V_124 -> V_99 ;
}
if ( ! V_126 . V_103 ) {
V_123 = V_123 -> V_131 ;
if ( ! V_123 )
break;
V_126 = V_123 -> V_99 ;
}
V_127 = F_88 ( V_124 , V_125 ) ;
V_128 = F_88 ( V_123 , V_126 ) ;
V_121 = F_89 ( V_127 . V_88 , V_128 . V_88 ) ;
V_129 = F_90 ( V_127 . V_89 ) ;
V_130 = F_90 ( V_128 . V_89 ) ;
memcpy ( V_130 + V_128 . V_114 ,
V_129 + V_127 . V_114 ,
V_121 ) ;
F_91 ( V_130 ) ;
F_91 ( V_129 ) ;
F_82 ( V_124 , & V_125 , V_121 ) ;
F_82 ( V_123 , & V_126 , V_121 ) ;
}
}
static struct V_132 * F_92 ( unsigned int V_133 ,
T_2 V_37 )
{
if ( V_133 > V_79 )
return NULL ;
return F_49 ( sizeof( struct V_132 ) +
sizeof( struct V_134 ) * V_133 , V_37 ) ;
}
static int F_93 ( struct V_4 * V_4 , struct V_135 V_86 )
{
int V_10 ;
struct V_31 * V_112 ;
F_84 (bvec, bio, i) {
T_3 V_101 ;
V_101 = F_94 ( V_112 -> V_89 ,
V_112 -> V_114 ,
V_112 -> V_88 ,
& V_86 ) ;
if ( ! F_95 ( & V_86 ) )
break;
if ( V_101 < V_112 -> V_88 )
return - V_136 ;
}
return 0 ;
}
static int F_96 ( struct V_4 * V_4 , struct V_135 V_86 )
{
int V_10 ;
struct V_31 * V_112 ;
F_84 (bvec, bio, i) {
T_3 V_101 ;
V_101 = F_97 ( V_112 -> V_89 ,
V_112 -> V_114 ,
V_112 -> V_88 ,
& V_86 ) ;
if ( ! F_95 ( & V_86 ) )
break;
if ( V_101 < V_112 -> V_88 )
return - V_136 ;
}
return 0 ;
}
static void F_98 ( struct V_4 * V_4 )
{
struct V_31 * V_112 ;
int V_10 ;
F_84 (bvec, bio, i)
F_86 ( V_112 -> V_89 ) ;
}
int F_99 ( struct V_4 * V_4 )
{
struct V_132 * V_137 = V_4 -> V_62 ;
int V_101 = 0 ;
if ( ! F_24 ( V_4 , V_138 ) ) {
if ( ! V_73 -> V_139 )
V_101 = - V_140 ;
else if ( F_100 ( V_4 ) == V_141 )
V_101 = F_96 ( V_4 , V_137 -> V_86 ) ;
if ( V_137 -> V_142 )
F_98 ( V_4 ) ;
}
F_26 ( V_137 ) ;
F_31 ( V_4 ) ;
return V_101 ;
}
struct V_4 * F_101 ( struct V_91 * V_92 ,
struct V_143 * V_144 ,
const struct V_135 * V_86 ,
T_2 V_37 )
{
struct V_132 * V_137 ;
struct V_108 * V_108 ;
struct V_4 * V_4 ;
int V_10 , V_101 ;
int V_145 = 0 ;
unsigned int V_109 = V_86 -> V_146 ;
unsigned int V_110 = V_144 ? F_102 ( V_144 -> V_110 ) : 0 ;
for ( V_10 = 0 ; V_10 < V_86 -> V_147 ; V_10 ++ ) {
unsigned long V_148 ;
unsigned long V_149 ;
unsigned long V_150 ;
V_148 = ( unsigned long ) V_86 -> V_151 [ V_10 ] . V_152 ;
V_149 = ( V_148 + V_86 -> V_151 [ V_10 ] . V_153 + V_154 - 1 )
>> V_155 ;
V_150 = V_148 >> V_155 ;
if ( V_149 < V_150 )
return F_103 ( - V_156 ) ;
V_145 += V_149 - V_150 ;
}
if ( V_110 )
V_145 ++ ;
V_137 = F_92 ( V_86 -> V_147 , V_37 ) ;
if ( ! V_137 )
return F_103 ( - V_122 ) ;
V_137 -> V_142 = V_144 ? 0 : 1 ;
memcpy ( V_137 -> V_151 , V_86 -> V_151 , sizeof( struct V_134 ) * V_86 -> V_147 ) ;
F_104 ( & V_137 -> V_86 , V_86 -> type , V_137 -> V_151 ,
V_86 -> V_147 , V_86 -> V_146 ) ;
V_101 = - V_122 ;
V_4 = F_105 ( V_37 , V_145 ) ;
if ( ! V_4 )
goto V_157;
if ( V_86 -> type & V_158 )
V_4 -> V_98 |= V_159 ;
V_101 = 0 ;
if ( V_144 ) {
V_145 = 1 << V_144 -> V_160 ;
V_10 = V_144 -> V_110 / V_154 ;
}
while ( V_109 ) {
unsigned int V_121 = V_154 ;
V_121 -= V_110 ;
if ( V_121 > V_109 )
V_121 = V_109 ;
if ( V_144 ) {
if ( V_10 == V_144 -> V_161 * V_145 ) {
V_101 = - V_122 ;
break;
}
V_108 = V_144 -> V_162 [ V_10 / V_145 ] ;
V_108 += ( V_10 % V_145 ) ;
V_10 ++ ;
} else {
V_108 = F_85 ( V_92 -> V_163 | V_37 ) ;
if ( ! V_108 ) {
V_101 = - V_122 ;
break;
}
}
if ( F_67 ( V_92 , V_4 , V_108 , V_121 , V_110 ) < V_121 )
break;
V_109 -= V_121 ;
V_110 = 0 ;
}
if ( V_101 )
goto V_164;
if ( ( ( V_86 -> type & V_158 ) && ( ! V_144 || ! V_144 -> V_165 ) ) ||
( V_144 && V_144 -> V_166 ) ) {
V_101 = F_93 ( V_4 , * V_86 ) ;
if ( V_101 )
goto V_164;
}
V_4 -> V_62 = V_137 ;
return V_4 ;
V_164:
if ( ! V_144 )
F_98 ( V_4 ) ;
F_31 ( V_4 ) ;
V_157:
F_26 ( V_137 ) ;
return F_103 ( V_101 ) ;
}
struct V_4 * F_106 ( struct V_91 * V_92 ,
const struct V_135 * V_86 ,
T_2 V_37 )
{
int V_167 ;
int V_145 = 0 ;
struct V_108 * * V_162 ;
struct V_4 * V_4 ;
int V_168 = 0 ;
int V_101 , V_110 ;
struct V_135 V_10 ;
struct V_134 V_151 ;
F_107 (iov, i, *iter) {
unsigned long V_148 = ( unsigned long ) V_151 . V_152 ;
unsigned long V_109 = V_151 . V_153 ;
unsigned long V_149 = ( V_148 + V_109 + V_154 - 1 ) >> V_155 ;
unsigned long V_150 = V_148 >> V_155 ;
if ( V_149 < V_150 )
return F_103 ( - V_156 ) ;
V_145 += V_149 - V_150 ;
if ( V_148 & F_108 ( V_92 ) )
return F_103 ( - V_156 ) ;
}
if ( ! V_145 )
return F_103 ( - V_156 ) ;
V_4 = F_105 ( V_37 , V_145 ) ;
if ( ! V_4 )
return F_103 ( - V_122 ) ;
V_101 = - V_122 ;
V_162 = F_109 ( V_145 , sizeof( struct V_108 * ) , V_37 ) ;
if ( ! V_162 )
goto V_26;
F_107 (iov, i, *iter) {
unsigned long V_148 = ( unsigned long ) V_151 . V_152 ;
unsigned long V_109 = V_151 . V_153 ;
unsigned long V_149 = ( V_148 + V_109 + V_154 - 1 ) >> V_155 ;
unsigned long V_150 = V_148 >> V_155 ;
const int V_169 = V_149 - V_150 ;
const int V_170 = V_168 + V_169 ;
V_101 = F_110 ( V_148 , V_169 ,
( V_86 -> type & V_158 ) != V_158 ,
& V_162 [ V_168 ] ) ;
if ( V_101 < V_169 ) {
V_101 = - V_136 ;
goto V_171;
}
V_110 = F_102 ( V_148 ) ;
for ( V_167 = V_168 ; V_167 < V_170 ; V_167 ++ ) {
unsigned int V_121 = V_154 - V_110 ;
if ( V_109 <= 0 )
break;
if ( V_121 > V_109 )
V_121 = V_109 ;
if ( F_67 ( V_92 , V_4 , V_162 [ V_167 ] , V_121 , V_110 ) <
V_121 )
break;
V_109 -= V_121 ;
V_110 = 0 ;
}
V_168 = V_167 ;
while ( V_167 < V_170 )
F_111 ( V_162 [ V_167 ++ ] ) ;
}
F_26 ( V_162 ) ;
if ( V_86 -> type & V_158 )
V_4 -> V_98 |= V_159 ;
F_52 ( V_4 , V_172 ) ;
F_112 ( V_4 ) ;
return V_4 ;
V_171:
for ( V_167 = 0 ; V_167 < V_145 ; V_167 ++ ) {
if ( ! V_162 [ V_167 ] )
break;
F_111 ( V_162 [ V_167 ] ) ;
}
V_26:
F_26 ( V_162 ) ;
F_31 ( V_4 ) ;
return F_103 ( V_101 ) ;
}
static void F_113 ( struct V_4 * V_4 )
{
struct V_31 * V_112 ;
int V_10 ;
F_84 (bvec, bio, i) {
if ( F_100 ( V_4 ) == V_141 )
F_114 ( V_112 -> V_89 ) ;
F_111 ( V_112 -> V_89 ) ;
}
F_31 ( V_4 ) ;
}
void F_115 ( struct V_4 * V_4 )
{
F_113 ( V_4 ) ;
F_31 ( V_4 ) ;
}
static void F_116 ( struct V_4 * V_4 )
{
F_31 ( V_4 ) ;
}
struct V_4 * F_117 ( struct V_91 * V_92 , void * V_87 , unsigned int V_109 ,
T_2 V_37 )
{
unsigned long V_173 = ( unsigned long ) V_87 ;
unsigned long V_149 = ( V_173 + V_109 + V_154 - 1 ) >> V_155 ;
unsigned long V_150 = V_173 >> V_155 ;
const int V_145 = V_149 - V_150 ;
int V_110 , V_10 ;
struct V_4 * V_4 ;
V_4 = F_105 ( V_37 , V_145 ) ;
if ( ! V_4 )
return F_103 ( - V_122 ) ;
V_110 = F_102 ( V_173 ) ;
for ( V_10 = 0 ; V_10 < V_145 ; V_10 ++ ) {
unsigned int V_121 = V_154 - V_110 ;
if ( V_109 <= 0 )
break;
if ( V_121 > V_109 )
V_121 = V_109 ;
if ( F_67 ( V_92 , V_4 , F_118 ( V_87 ) , V_121 ,
V_110 ) < V_121 ) {
F_31 ( V_4 ) ;
return F_103 ( - V_156 ) ;
}
V_87 += V_121 ;
V_109 -= V_121 ;
V_110 = 0 ;
}
V_4 -> V_64 = F_116 ;
return V_4 ;
}
static void F_119 ( struct V_4 * V_4 )
{
F_98 ( V_4 ) ;
F_31 ( V_4 ) ;
}
static void F_120 ( struct V_4 * V_4 )
{
char * V_49 = V_4 -> V_62 ;
struct V_31 * V_112 ;
int V_10 ;
F_84 (bvec, bio, i) {
memcpy ( V_49 , F_121 ( V_112 -> V_89 ) , V_112 -> V_88 ) ;
V_49 += V_112 -> V_88 ;
}
F_119 ( V_4 ) ;
}
struct V_4 * F_122 ( struct V_91 * V_92 , void * V_87 , unsigned int V_109 ,
T_2 V_37 , int V_174 )
{
unsigned long V_173 = ( unsigned long ) V_87 ;
unsigned long V_149 = ( V_173 + V_109 + V_154 - 1 ) >> V_155 ;
unsigned long V_150 = V_173 >> V_155 ;
struct V_4 * V_4 ;
void * V_49 = V_87 ;
int V_145 = 0 ;
if ( V_149 < V_150 )
return F_103 ( - V_156 ) ;
V_145 = V_149 - V_150 ;
V_4 = F_105 ( V_37 , V_145 ) ;
if ( ! V_4 )
return F_103 ( - V_122 ) ;
while ( V_109 ) {
struct V_108 * V_108 ;
unsigned int V_121 = V_154 ;
if ( V_121 > V_109 )
V_121 = V_109 ;
V_108 = F_85 ( V_92 -> V_163 | V_37 ) ;
if ( ! V_108 )
goto V_164;
if ( ! V_174 )
memcpy ( F_121 ( V_108 ) , V_49 , V_121 ) ;
if ( F_67 ( V_92 , V_4 , V_108 , V_121 , 0 ) < V_121 )
break;
V_109 -= V_121 ;
V_49 += V_121 ;
}
if ( V_174 ) {
V_4 -> V_64 = F_120 ;
V_4 -> V_62 = V_87 ;
} else {
V_4 -> V_64 = F_119 ;
V_4 -> V_98 |= V_159 ;
}
return V_4 ;
V_164:
F_98 ( V_4 ) ;
F_31 ( V_4 ) ;
return F_103 ( - V_122 ) ;
}
void F_123 ( struct V_4 * V_4 )
{
struct V_31 * V_112 ;
int V_10 ;
F_84 (bvec, bio, i) {
struct V_108 * V_108 = V_112 -> V_89 ;
if ( V_108 && ! F_124 ( V_108 ) )
F_114 ( V_108 ) ;
}
}
static void F_125 ( struct V_4 * V_4 )
{
struct V_31 * V_112 ;
int V_10 ;
F_84 (bvec, bio, i) {
struct V_108 * V_108 = V_112 -> V_89 ;
if ( V_108 )
F_111 ( V_108 ) ;
}
}
static void F_126 ( struct V_65 * V_66 )
{
unsigned long V_57 ;
struct V_4 * V_4 ;
F_127 ( & V_175 , V_57 ) ;
V_4 = V_176 ;
V_176 = NULL ;
F_128 ( & V_175 , V_57 ) ;
while ( V_4 ) {
struct V_4 * V_177 = V_4 -> V_62 ;
F_123 ( V_4 ) ;
F_125 ( V_4 ) ;
F_31 ( V_4 ) ;
V_4 = V_177 ;
}
}
void F_129 ( struct V_4 * V_4 )
{
struct V_31 * V_112 ;
int V_178 = 0 ;
int V_10 ;
F_84 (bvec, bio, i) {
struct V_108 * V_108 = V_112 -> V_89 ;
if ( F_130 ( V_108 ) || F_124 ( V_108 ) ) {
F_111 ( V_108 ) ;
V_112 -> V_89 = NULL ;
} else {
V_178 ++ ;
}
}
if ( V_178 ) {
unsigned long V_57 ;
F_127 ( & V_175 , V_57 ) ;
V_4 -> V_62 = V_176 ;
V_176 = V_4 ;
F_128 ( & V_175 , V_57 ) ;
F_131 ( & V_179 ) ;
} else {
F_31 ( V_4 ) ;
}
}
void F_132 ( int V_119 , unsigned long V_180 ,
struct V_181 * V_182 )
{
int V_183 = F_133 () ;
F_134 ( V_183 , V_182 ) ;
F_135 ( V_183 , V_182 , V_184 [ V_119 ] ) ;
F_136 ( V_183 , V_182 , V_180 [ V_119 ] , V_180 ) ;
F_137 ( V_182 , V_119 ) ;
F_138 () ;
}
void F_139 ( int V_119 , struct V_181 * V_182 ,
unsigned long V_185 )
{
unsigned long V_186 = V_187 - V_185 ;
int V_183 = F_133 () ;
F_136 ( V_183 , V_182 , V_188 [ V_119 ] , V_186 ) ;
F_134 ( V_183 , V_182 ) ;
F_140 ( V_182 , V_119 ) ;
F_138 () ;
}
void F_141 ( struct V_4 * V_189 )
{
struct V_31 V_112 ;
struct V_85 V_86 ;
F_54 (bvec, bi, iter)
F_56 ( V_112 . V_89 ) ;
}
static inline bool F_142 ( struct V_4 * V_4 )
{
if ( ! F_24 ( V_4 , V_190 ) )
return true ;
F_35 ( F_58 ( & V_4 -> V_55 ) <= 0 ) ;
if ( F_59 ( & V_4 -> V_55 ) ) {
F_72 ( V_4 , V_190 ) ;
return true ;
}
return false ;
}
void F_33 ( struct V_4 * V_4 )
{
V_191:
if ( ! F_142 ( V_4 ) )
return;
if ( V_4 -> V_64 == F_32 ) {
V_4 = F_30 ( V_4 ) ;
goto V_191;
}
if ( V_4 -> V_64 )
V_4 -> V_64 ( V_4 ) ;
}
struct V_4 * F_143 ( struct V_4 * V_4 , int V_180 ,
T_2 V_192 , struct V_23 * V_24 )
{
struct V_4 * V_193 = NULL ;
F_35 ( V_180 <= 0 ) ;
F_35 ( V_180 >= F_144 ( V_4 ) ) ;
if ( V_4 -> V_98 & V_104 )
V_193 = F_65 ( V_4 , V_192 , V_24 ) ;
else
V_193 = F_63 ( V_4 , V_192 , V_24 ) ;
if ( ! V_193 )
return NULL ;
V_193 -> V_99 . V_103 = V_180 << 9 ;
if ( F_21 ( V_193 ) )
F_145 ( V_193 , 0 , V_180 ) ;
F_80 ( V_4 , V_193 -> V_99 . V_103 ) ;
return V_193 ;
}
void F_146 ( struct V_4 * V_4 , int V_110 , int V_194 )
{
V_194 <<= 9 ;
if ( V_110 == 0 && V_194 == V_4 -> V_99 . V_103 )
return;
F_72 ( V_4 , V_93 ) ;
F_80 ( V_4 , V_110 << 9 ) ;
V_4 -> V_99 . V_103 = V_194 ;
}
T_1 * F_147 ( int V_195 )
{
struct V_35 * V_196 = V_28 + V_34 ;
return F_148 ( V_195 , V_196 -> V_5 ) ;
}
void F_149 ( struct V_23 * V_24 )
{
if ( V_24 -> V_74 )
F_150 ( V_24 -> V_74 ) ;
if ( V_24 -> V_54 )
F_151 ( V_24 -> V_54 ) ;
if ( V_24 -> V_51 )
F_151 ( V_24 -> V_51 ) ;
F_152 ( V_24 ) ;
F_6 ( V_24 ) ;
F_26 ( V_24 ) ;
}
static struct V_23 * F_153 ( unsigned int V_197 ,
unsigned int V_53 ,
bool V_198 )
{
unsigned int V_199 = V_80 * sizeof( struct V_31 ) ;
struct V_23 * V_24 ;
V_24 = F_154 ( sizeof( * V_24 ) , V_19 ) ;
if ( ! V_24 )
return NULL ;
V_24 -> V_53 = V_53 ;
F_155 ( & V_24 -> V_68 ) ;
F_44 ( & V_24 -> V_69 ) ;
F_156 ( & V_24 -> V_67 , F_37 ) ;
V_24 -> V_6 = F_1 ( V_53 + V_199 ) ;
if ( ! V_24 -> V_6 ) {
F_26 ( V_24 ) ;
return NULL ;
}
V_24 -> V_54 = F_148 ( V_197 , V_24 -> V_6 ) ;
if ( ! V_24 -> V_54 )
goto V_200;
if ( V_198 ) {
V_24 -> V_51 = F_147 ( V_197 ) ;
if ( ! V_24 -> V_51 )
goto V_200;
}
V_24 -> V_74 = F_157 ( L_3 , V_201 , 0 ) ;
if ( ! V_24 -> V_74 )
goto V_200;
return V_24 ;
V_200:
F_149 ( V_24 ) ;
return NULL ;
}
struct V_23 * F_158 ( unsigned int V_197 , unsigned int V_53 )
{
return F_153 ( V_197 , V_53 , true ) ;
}
struct V_23 * F_159 ( unsigned int V_197 , unsigned int V_53 )
{
return F_153 ( V_197 , V_53 , false ) ;
}
int F_160 ( struct V_4 * V_4 , struct V_202 * V_203 )
{
if ( F_18 ( V_4 -> V_204 ) )
return - V_205 ;
F_161 ( V_203 ) ;
V_4 -> V_204 = V_203 ;
return 0 ;
}
int F_162 ( struct V_4 * V_4 )
{
struct V_206 * V_207 ;
if ( V_4 -> V_204 )
return - V_205 ;
V_207 = V_73 -> V_206 ;
if ( ! V_207 )
return - V_208 ;
F_163 ( V_207 ) ;
V_4 -> V_209 = V_207 ;
V_4 -> V_204 = F_164 ( V_73 , V_210 ) ;
return 0 ;
}
void F_20 ( struct V_4 * V_4 )
{
if ( V_4 -> V_209 ) {
F_165 ( V_4 -> V_209 ) ;
V_4 -> V_209 = NULL ;
}
if ( V_4 -> V_204 ) {
F_166 ( V_4 -> V_204 ) ;
V_4 -> V_204 = NULL ;
}
}
static void T_4 F_167 ( void )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_33 ; V_10 ++ ) {
int V_194 ;
struct V_35 * V_36 = V_28 + V_10 ;
if ( V_36 -> V_29 <= V_80 ) {
V_36 -> V_5 = NULL ;
continue;
}
V_194 = V_36 -> V_29 * sizeof( struct V_31 ) ;
V_36 -> V_5 = F_4 ( V_36 -> V_20 , V_194 , 0 ,
V_22 | V_211 , NULL ) ;
}
}
static int T_4 F_168 ( void )
{
V_18 = 2 ;
V_13 = 0 ;
V_14 = F_154 ( V_18 * sizeof( struct V_6 ) , V_19 ) ;
if ( ! V_14 )
F_169 ( L_4 ) ;
F_170 () ;
F_167 () ;
V_212 = F_158 ( V_213 , 0 ) ;
if ( ! V_212 )
F_169 ( L_4 ) ;
if ( F_171 ( V_212 , V_213 ) )
F_169 ( L_5 ) ;
return 0 ;
}
