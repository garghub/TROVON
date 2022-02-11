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
void F_26 ( struct V_4 * V_4 , struct V_31 * V_54 ,
unsigned short V_55 )
{
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
F_27 ( & V_4 -> V_56 , 1 ) ;
F_27 ( & V_4 -> V_57 , 1 ) ;
V_4 -> V_51 = V_54 ;
V_4 -> V_58 = V_55 ;
}
void F_28 ( struct V_4 * V_4 )
{
unsigned long V_59 = V_4 -> V_60 & ( ~ 0UL << V_61 ) ;
F_19 ( V_4 ) ;
memset ( V_4 , 0 , V_62 ) ;
V_4 -> V_60 = V_59 ;
F_27 ( & V_4 -> V_56 , 1 ) ;
}
static struct V_4 * F_29 ( struct V_4 * V_4 )
{
struct V_4 * V_63 = V_4 -> V_64 ;
if ( ! V_63 -> V_65 )
V_63 -> V_65 = V_4 -> V_65 ;
F_30 ( V_4 ) ;
return V_63 ;
}
static void F_31 ( struct V_4 * V_4 )
{
F_32 ( F_29 ( V_4 ) ) ;
}
void F_33 ( struct V_4 * V_4 , struct V_4 * V_63 )
{
F_34 ( V_4 -> V_64 || V_4 -> V_66 ) ;
V_4 -> V_64 = V_63 ;
V_4 -> V_66 = F_31 ;
F_35 ( V_63 ) ;
}
static void F_36 ( struct V_67 * V_68 )
{
struct V_23 * V_24 = F_37 ( V_68 , struct V_23 , V_69 ) ;
struct V_4 * V_4 ;
while ( 1 ) {
F_38 ( & V_24 -> V_70 ) ;
V_4 = F_39 ( & V_24 -> V_71 ) ;
F_40 ( & V_24 -> V_70 ) ;
if ( ! V_4 )
break;
F_41 ( V_4 ) ;
}
}
static void F_42 ( struct V_23 * V_24 )
{
struct V_72 V_73 , V_74 ;
struct V_4 * V_4 ;
F_43 ( & V_73 ) ;
F_43 ( & V_74 ) ;
while ( ( V_4 = F_39 ( V_75 -> V_72 ) ) )
F_44 ( V_4 -> V_48 == V_24 ? & V_73 : & V_74 , V_4 ) ;
* V_75 -> V_72 = V_74 ;
F_38 ( & V_24 -> V_70 ) ;
F_45 ( & V_24 -> V_71 , & V_73 ) ;
F_40 ( & V_24 -> V_70 ) ;
F_46 ( V_24 -> V_76 , & V_24 -> V_69 ) ;
}
struct V_4 * F_47 ( T_2 V_37 , int V_77 , struct V_23 * V_24 )
{
T_2 V_78 = V_37 ;
unsigned V_52 ;
unsigned V_79 ;
struct V_31 * V_39 = NULL ;
struct V_4 * V_4 ;
void * V_49 ;
if ( ! V_24 ) {
if ( V_77 > V_80 )
return NULL ;
V_49 = F_48 ( sizeof( struct V_4 ) +
V_77 * sizeof( struct V_31 ) ,
V_37 ) ;
V_52 = 0 ;
V_79 = V_77 ;
} else {
if ( F_49 ( ! V_24 -> V_50 && V_77 > 0 ) )
return NULL ;
if ( V_75 -> V_72 && ! F_50 ( V_75 -> V_72 ) )
V_37 &= ~ V_43 ;
V_49 = F_16 ( V_24 -> V_53 , V_37 ) ;
if ( ! V_49 && V_37 != V_78 ) {
F_42 ( V_24 ) ;
V_37 = V_78 ;
V_49 = F_16 ( V_24 -> V_53 , V_37 ) ;
}
V_52 = V_24 -> V_52 ;
V_79 = V_81 ;
}
if ( F_18 ( ! V_49 ) )
return NULL ;
V_4 = V_49 + V_52 ;
F_26 ( V_4 , NULL , 0 ) ;
if ( V_77 > V_79 ) {
unsigned long V_27 = 0 ;
V_39 = F_15 ( V_37 , V_77 , & V_27 , V_24 -> V_50 ) ;
if ( ! V_39 && V_37 != V_78 ) {
F_42 ( V_24 ) ;
V_37 = V_78 ;
V_39 = F_15 ( V_37 , V_77 , & V_27 , V_24 -> V_50 ) ;
}
if ( F_18 ( ! V_39 ) )
goto V_82;
V_4 -> V_60 |= V_27 << V_83 ;
} else if ( V_77 ) {
V_39 = V_4 -> V_84 ;
}
V_4 -> V_48 = V_24 ;
V_4 -> V_58 = V_77 ;
V_4 -> V_51 = V_39 ;
return V_4 ;
V_82:
F_13 ( V_49 , V_24 -> V_53 ) ;
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
void F_30 ( struct V_4 * V_4 )
{
if ( ! F_56 ( V_4 , V_90 ) )
F_23 ( V_4 ) ;
else {
F_12 ( ! F_57 ( & V_4 -> V_57 ) ) ;
if ( F_58 ( & V_4 -> V_57 ) )
F_23 ( V_4 ) ;
}
}
inline int F_59 ( struct V_91 * V_92 , struct V_4 * V_4 )
{
if ( F_18 ( ! F_56 ( V_4 , V_93 ) ) )
F_60 ( V_92 , V_4 ) ;
return V_4 -> V_94 ;
}
void F_61 ( struct V_4 * V_4 , struct V_4 * V_95 )
{
F_34 ( V_4 -> V_48 && F_24 ( V_4 ) ) ;
V_4 -> V_96 = V_95 -> V_96 ;
F_62 ( V_4 , V_97 ) ;
V_4 -> V_98 = V_95 -> V_98 ;
V_4 -> V_99 = V_95 -> V_99 ;
V_4 -> V_51 = V_95 -> V_51 ;
F_63 ( V_4 , V_95 ) ;
}
struct V_4 * F_64 ( struct V_4 * V_4 , T_2 V_37 , struct V_23 * V_24 )
{
struct V_4 * V_100 ;
V_100 = F_47 ( V_37 , 0 , V_24 ) ;
if ( ! V_100 )
return NULL ;
F_61 ( V_100 , V_4 ) ;
if ( F_21 ( V_4 ) ) {
int V_101 ;
V_101 = F_65 ( V_100 , V_4 , V_37 ) ;
if ( V_101 < 0 ) {
F_30 ( V_100 ) ;
return NULL ;
}
}
return V_100 ;
}
struct V_4 * F_66 ( struct V_4 * V_95 , T_2 V_37 ,
struct V_23 * V_24 )
{
struct V_85 V_86 ;
struct V_31 V_32 ;
struct V_4 * V_4 ;
V_4 = F_47 ( V_37 , F_67 ( V_95 ) , V_24 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_96 = V_95 -> V_96 ;
V_4 -> V_98 = V_95 -> V_98 ;
V_4 -> V_99 . V_102 = V_95 -> V_99 . V_102 ;
V_4 -> V_99 . V_103 = V_95 -> V_99 . V_103 ;
switch ( F_68 ( V_4 ) ) {
case V_104 :
case V_105 :
case V_106 :
break;
case V_107 :
V_4 -> V_51 [ V_4 -> V_108 ++ ] = V_95 -> V_51 [ 0 ] ;
break;
default:
F_52 (bv, bio_src, iter)
V_4 -> V_51 [ V_4 -> V_108 ++ ] = V_32 ;
break;
}
if ( F_21 ( V_95 ) ) {
int V_101 ;
V_101 = F_65 ( V_4 , V_95 , V_37 ) ;
if ( V_101 < 0 ) {
F_30 ( V_4 ) ;
return NULL ;
}
}
F_63 ( V_4 , V_95 ) ;
return V_4 ;
}
int F_69 ( struct V_91 * V_92 , struct V_4 * V_4 , struct V_109
* V_109 , unsigned int V_110 , unsigned int V_111 )
{
int V_112 = 0 ;
struct V_31 * V_113 ;
if ( F_18 ( F_56 ( V_4 , V_97 ) ) )
return 0 ;
if ( ( ( V_4 -> V_99 . V_103 + V_110 ) >> 9 ) > F_70 ( V_92 ) )
return 0 ;
if ( V_4 -> V_108 > 0 ) {
struct V_31 * V_114 = & V_4 -> V_51 [ V_4 -> V_108 - 1 ] ;
if ( V_109 == V_114 -> V_89 &&
V_111 == V_114 -> V_115 + V_114 -> V_88 ) {
V_114 -> V_88 += V_110 ;
V_4 -> V_99 . V_103 += V_110 ;
goto V_116;
}
if ( F_71 ( V_92 , V_114 , V_111 ) )
return 0 ;
}
if ( V_4 -> V_108 >= V_4 -> V_58 )
return 0 ;
V_113 = & V_4 -> V_51 [ V_4 -> V_108 ] ;
V_113 -> V_89 = V_109 ;
V_113 -> V_88 = V_110 ;
V_113 -> V_115 = V_111 ;
V_4 -> V_108 ++ ;
V_4 -> V_94 ++ ;
V_4 -> V_99 . V_103 += V_110 ;
while ( V_4 -> V_94 > F_72 ( V_92 ) ) {
if ( V_112 )
goto V_117;
V_112 = 1 ;
F_60 ( V_92 , V_4 ) ;
}
if ( V_4 -> V_108 > 1 && ( F_73 ( V_113 - 1 , V_113 ) ) )
F_74 ( V_4 , V_93 ) ;
V_116:
return V_110 ;
V_117:
V_113 -> V_89 = NULL ;
V_113 -> V_88 = 0 ;
V_113 -> V_115 = 0 ;
V_4 -> V_108 -- ;
V_4 -> V_99 . V_103 -= V_110 ;
F_60 ( V_92 , V_4 ) ;
return 0 ;
}
int F_75 ( struct V_4 * V_4 , struct V_109 * V_109 ,
unsigned int V_110 , unsigned int V_111 )
{
struct V_31 * V_32 ;
if ( F_49 ( F_56 ( V_4 , V_97 ) ) )
return 0 ;
if ( V_4 -> V_108 > 0 ) {
V_32 = & V_4 -> V_51 [ V_4 -> V_108 - 1 ] ;
if ( V_109 == V_32 -> V_89 &&
V_111 == V_32 -> V_115 + V_32 -> V_88 ) {
V_32 -> V_88 += V_110 ;
goto V_116;
}
}
if ( V_4 -> V_108 >= V_4 -> V_58 )
return 0 ;
V_32 = & V_4 -> V_51 [ V_4 -> V_108 ] ;
V_32 -> V_89 = V_109 ;
V_32 -> V_88 = V_110 ;
V_32 -> V_115 = V_111 ;
V_4 -> V_108 ++ ;
V_116:
V_4 -> V_99 . V_103 += V_110 ;
return V_110 ;
}
int F_76 ( struct V_4 * V_4 , struct V_118 * V_86 )
{
unsigned short V_119 = V_4 -> V_58 - V_4 -> V_108 ;
struct V_31 * V_32 = V_4 -> V_51 + V_4 -> V_108 ;
struct V_109 * * V_120 = (struct V_109 * * ) V_32 ;
T_3 V_111 , V_121 ;
T_4 V_122 ;
V_122 = F_77 ( V_86 , V_120 , V_123 , V_119 , & V_111 ) ;
if ( F_18 ( V_122 <= 0 ) )
return V_122 ? V_122 : - V_124 ;
V_119 = ( V_122 + V_111 + V_125 - 1 ) / V_125 ;
V_4 -> V_99 . V_103 += V_122 ;
V_4 -> V_108 += V_119 ;
V_121 = ( V_119 * V_125 - V_111 ) - V_122 ;
while ( V_119 -- ) {
V_32 [ V_119 ] . V_89 = V_120 [ V_119 ] ;
V_32 [ V_119 ] . V_88 = V_125 ;
V_32 [ V_119 ] . V_115 = 0 ;
}
V_32 [ 0 ] . V_115 += V_111 ;
V_32 [ 0 ] . V_88 -= V_111 ;
if ( V_121 )
V_32 [ V_4 -> V_108 - 1 ] . V_88 -= V_121 ;
F_78 ( V_86 , V_122 ) ;
return 0 ;
}
static void F_79 ( struct V_4 * V_4 )
{
struct V_126 * V_101 = V_4 -> V_64 ;
V_101 -> error = V_4 -> V_65 ;
F_80 ( & V_101 -> V_127 ) ;
}
int F_81 ( struct V_4 * V_4 )
{
struct V_126 V_101 ;
F_82 ( & V_101 . V_127 ) ;
V_4 -> V_64 = & V_101 ;
V_4 -> V_66 = F_79 ;
V_4 -> V_98 |= V_128 ;
F_83 ( V_4 ) ;
F_84 ( & V_101 . V_127 ) ;
return V_101 . error ;
}
void F_85 ( struct V_4 * V_4 , unsigned V_129 )
{
if ( F_21 ( V_4 ) )
F_86 ( V_4 , V_129 ) ;
F_87 ( V_4 , & V_4 -> V_99 , V_129 ) ;
}
int F_88 ( struct V_4 * V_4 , T_2 V_37 )
{
int V_10 ;
struct V_31 * V_32 ;
F_89 (bv, bio, i) {
V_32 -> V_89 = F_90 ( V_37 ) ;
if ( ! V_32 -> V_89 ) {
while ( -- V_32 >= V_4 -> V_51 )
F_91 ( V_32 -> V_89 ) ;
return - V_130 ;
}
}
return 0 ;
}
void F_92 ( struct V_4 * V_131 , struct V_4 * V_132 )
{
struct V_85 V_133 , V_134 ;
struct V_31 V_135 , V_136 ;
void * V_137 , * V_138 ;
unsigned V_129 ;
V_133 = V_132 -> V_99 ;
V_134 = V_131 -> V_99 ;
while ( 1 ) {
if ( ! V_133 . V_103 ) {
V_132 = V_132 -> V_139 ;
if ( ! V_132 )
break;
V_133 = V_132 -> V_99 ;
}
if ( ! V_134 . V_103 ) {
V_131 = V_131 -> V_139 ;
if ( ! V_131 )
break;
V_134 = V_131 -> V_99 ;
}
V_135 = F_93 ( V_132 , V_133 ) ;
V_136 = F_93 ( V_131 , V_134 ) ;
V_129 = F_94 ( V_135 . V_88 , V_136 . V_88 ) ;
V_137 = F_95 ( V_135 . V_89 ) ;
V_138 = F_95 ( V_136 . V_89 ) ;
memcpy ( V_138 + V_136 . V_115 ,
V_137 + V_135 . V_115 ,
V_129 ) ;
F_96 ( V_138 ) ;
F_96 ( V_137 ) ;
F_87 ( V_132 , & V_133 , V_129 ) ;
F_87 ( V_131 , & V_134 , V_129 ) ;
}
}
static struct V_140 * F_97 ( unsigned int V_141 ,
T_2 V_37 )
{
if ( V_141 > V_80 )
return NULL ;
return F_48 ( sizeof( struct V_140 ) +
sizeof( struct V_142 ) * V_141 , V_37 ) ;
}
static int F_98 ( struct V_4 * V_4 , struct V_118 V_86 )
{
int V_10 ;
struct V_31 * V_113 ;
F_89 (bvec, bio, i) {
T_4 V_101 ;
V_101 = F_99 ( V_113 -> V_89 ,
V_113 -> V_115 ,
V_113 -> V_88 ,
& V_86 ) ;
if ( ! F_100 ( & V_86 ) )
break;
if ( V_101 < V_113 -> V_88 )
return - V_124 ;
}
return 0 ;
}
static int F_101 ( struct V_4 * V_4 , struct V_118 V_86 )
{
int V_10 ;
struct V_31 * V_113 ;
F_89 (bvec, bio, i) {
T_4 V_101 ;
V_101 = F_102 ( V_113 -> V_89 ,
V_113 -> V_115 ,
V_113 -> V_88 ,
& V_86 ) ;
if ( ! F_100 ( & V_86 ) )
break;
if ( V_101 < V_113 -> V_88 )
return - V_124 ;
}
return 0 ;
}
void F_103 ( struct V_4 * V_4 )
{
struct V_31 * V_113 ;
int V_10 ;
F_89 (bvec, bio, i)
F_91 ( V_113 -> V_89 ) ;
}
int F_104 ( struct V_4 * V_4 )
{
struct V_140 * V_143 = V_4 -> V_64 ;
int V_101 = 0 ;
if ( ! F_56 ( V_4 , V_144 ) ) {
if ( ! V_75 -> V_145 )
V_101 = - V_146 ;
else if ( F_105 ( V_4 ) == V_147 )
V_101 = F_101 ( V_4 , V_143 -> V_86 ) ;
if ( V_143 -> V_148 )
F_103 ( V_4 ) ;
}
F_25 ( V_143 ) ;
F_30 ( V_4 ) ;
return V_101 ;
}
struct V_4 * F_106 ( struct V_91 * V_92 ,
struct V_149 * V_150 ,
const struct V_118 * V_86 ,
T_2 V_37 )
{
struct V_140 * V_143 ;
struct V_109 * V_109 ;
struct V_4 * V_4 ;
int V_10 , V_101 ;
int V_119 = 0 ;
unsigned int V_110 = V_86 -> V_151 ;
unsigned int V_111 = V_150 ? F_107 ( V_150 -> V_111 ) : 0 ;
for ( V_10 = 0 ; V_10 < V_86 -> V_152 ; V_10 ++ ) {
unsigned long V_153 ;
unsigned long V_154 ;
unsigned long V_155 ;
V_153 = ( unsigned long ) V_86 -> V_156 [ V_10 ] . V_157 ;
V_154 = ( V_153 + V_86 -> V_156 [ V_10 ] . V_158 + V_125 - 1 )
>> V_159 ;
V_155 = V_153 >> V_159 ;
if ( V_154 < V_155 )
return F_108 ( - V_160 ) ;
V_119 += V_154 - V_155 ;
}
if ( V_111 )
V_119 ++ ;
V_143 = F_97 ( V_86 -> V_152 , V_37 ) ;
if ( ! V_143 )
return F_108 ( - V_130 ) ;
V_143 -> V_148 = V_150 ? 0 : 1 ;
memcpy ( V_143 -> V_156 , V_86 -> V_156 , sizeof( struct V_142 ) * V_86 -> V_152 ) ;
F_109 ( & V_143 -> V_86 , V_86 -> type , V_143 -> V_156 ,
V_86 -> V_152 , V_86 -> V_151 ) ;
V_101 = - V_130 ;
V_4 = F_110 ( V_37 , V_119 ) ;
if ( ! V_4 )
goto V_161;
if ( V_86 -> type & V_162 )
F_111 ( V_4 , V_163 , 0 ) ;
V_101 = 0 ;
if ( V_150 ) {
V_119 = 1 << V_150 -> V_164 ;
V_10 = V_150 -> V_111 / V_125 ;
}
while ( V_110 ) {
unsigned int V_129 = V_125 ;
V_129 -= V_111 ;
if ( V_129 > V_110 )
V_129 = V_110 ;
if ( V_150 ) {
if ( V_10 == V_150 -> V_165 * V_119 ) {
V_101 = - V_130 ;
break;
}
V_109 = V_150 -> V_120 [ V_10 / V_119 ] ;
V_109 += ( V_10 % V_119 ) ;
V_10 ++ ;
} else {
V_109 = F_90 ( V_92 -> V_166 | V_37 ) ;
if ( ! V_109 ) {
V_101 = - V_130 ;
break;
}
}
if ( F_69 ( V_92 , V_4 , V_109 , V_129 , V_111 ) < V_129 )
break;
V_110 -= V_129 ;
V_111 = 0 ;
}
if ( V_101 )
goto V_167;
if ( ( ( V_86 -> type & V_162 ) && ( ! V_150 || ! V_150 -> V_168 ) ) ||
( V_150 && V_150 -> V_169 ) ) {
V_101 = F_98 ( V_4 , * V_86 ) ;
if ( V_101 )
goto V_167;
}
V_4 -> V_64 = V_143 ;
return V_4 ;
V_167:
if ( ! V_150 )
F_103 ( V_4 ) ;
F_30 ( V_4 ) ;
V_161:
F_25 ( V_143 ) ;
return F_108 ( V_101 ) ;
}
struct V_4 * F_112 ( struct V_91 * V_92 ,
const struct V_118 * V_86 ,
T_2 V_37 )
{
int V_170 ;
int V_119 = 0 ;
struct V_109 * * V_120 ;
struct V_4 * V_4 ;
int V_171 = 0 ;
int V_101 , V_111 ;
struct V_118 V_10 ;
struct V_142 V_156 ;
F_113 (iov, i, *iter) {
unsigned long V_153 = ( unsigned long ) V_156 . V_157 ;
unsigned long V_110 = V_156 . V_158 ;
unsigned long V_154 = ( V_153 + V_110 + V_125 - 1 ) >> V_159 ;
unsigned long V_155 = V_153 >> V_159 ;
if ( V_154 < V_155 )
return F_108 ( - V_160 ) ;
V_119 += V_154 - V_155 ;
if ( V_153 & F_114 ( V_92 ) )
return F_108 ( - V_160 ) ;
}
if ( ! V_119 )
return F_108 ( - V_160 ) ;
V_4 = F_110 ( V_37 , V_119 ) ;
if ( ! V_4 )
return F_108 ( - V_130 ) ;
V_101 = - V_130 ;
V_120 = F_115 ( V_119 , sizeof( struct V_109 * ) , V_37 ) ;
if ( ! V_120 )
goto V_26;
F_113 (iov, i, *iter) {
unsigned long V_153 = ( unsigned long ) V_156 . V_157 ;
unsigned long V_110 = V_156 . V_158 ;
unsigned long V_154 = ( V_153 + V_110 + V_125 - 1 ) >> V_159 ;
unsigned long V_155 = V_153 >> V_159 ;
const int V_172 = V_154 - V_155 ;
const int V_173 = V_171 + V_172 ;
V_101 = F_116 ( V_153 , V_172 ,
( V_86 -> type & V_162 ) != V_162 ,
& V_120 [ V_171 ] ) ;
if ( V_101 < V_172 ) {
V_101 = - V_124 ;
goto V_174;
}
V_111 = F_107 ( V_153 ) ;
for ( V_170 = V_171 ; V_170 < V_173 ; V_170 ++ ) {
unsigned int V_129 = V_125 - V_111 ;
if ( V_110 <= 0 )
break;
if ( V_129 > V_110 )
V_129 = V_110 ;
if ( F_69 ( V_92 , V_4 , V_120 [ V_170 ] , V_129 , V_111 ) <
V_129 )
break;
V_110 -= V_129 ;
V_111 = 0 ;
}
V_171 = V_170 ;
while ( V_170 < V_173 )
F_117 ( V_120 [ V_170 ++ ] ) ;
}
F_25 ( V_120 ) ;
if ( V_86 -> type & V_162 )
F_111 ( V_4 , V_163 , 0 ) ;
F_62 ( V_4 , V_175 ) ;
F_118 ( V_4 ) ;
return V_4 ;
V_174:
for ( V_170 = 0 ; V_170 < V_119 ; V_170 ++ ) {
if ( ! V_120 [ V_170 ] )
break;
F_117 ( V_120 [ V_170 ] ) ;
}
V_26:
F_25 ( V_120 ) ;
F_30 ( V_4 ) ;
return F_108 ( V_101 ) ;
}
static void F_119 ( struct V_4 * V_4 )
{
struct V_31 * V_113 ;
int V_10 ;
F_89 (bvec, bio, i) {
if ( F_105 ( V_4 ) == V_147 )
F_120 ( V_113 -> V_89 ) ;
F_117 ( V_113 -> V_89 ) ;
}
F_30 ( V_4 ) ;
}
void F_121 ( struct V_4 * V_4 )
{
F_119 ( V_4 ) ;
F_30 ( V_4 ) ;
}
static void F_122 ( struct V_4 * V_4 )
{
F_30 ( V_4 ) ;
}
struct V_4 * F_123 ( struct V_91 * V_92 , void * V_87 , unsigned int V_110 ,
T_2 V_37 )
{
unsigned long V_176 = ( unsigned long ) V_87 ;
unsigned long V_154 = ( V_176 + V_110 + V_125 - 1 ) >> V_159 ;
unsigned long V_155 = V_176 >> V_159 ;
const int V_119 = V_154 - V_155 ;
int V_111 , V_10 ;
struct V_4 * V_4 ;
V_4 = F_110 ( V_37 , V_119 ) ;
if ( ! V_4 )
return F_108 ( - V_130 ) ;
V_111 = F_107 ( V_176 ) ;
for ( V_10 = 0 ; V_10 < V_119 ; V_10 ++ ) {
unsigned int V_129 = V_125 - V_111 ;
if ( V_110 <= 0 )
break;
if ( V_129 > V_110 )
V_129 = V_110 ;
if ( F_69 ( V_92 , V_4 , F_124 ( V_87 ) , V_129 ,
V_111 ) < V_129 ) {
F_30 ( V_4 ) ;
return F_108 ( - V_160 ) ;
}
V_87 += V_129 ;
V_110 -= V_129 ;
V_111 = 0 ;
}
V_4 -> V_66 = F_122 ;
return V_4 ;
}
static void F_125 ( struct V_4 * V_4 )
{
F_103 ( V_4 ) ;
F_30 ( V_4 ) ;
}
static void F_126 ( struct V_4 * V_4 )
{
char * V_49 = V_4 -> V_64 ;
struct V_31 * V_113 ;
int V_10 ;
F_89 (bvec, bio, i) {
memcpy ( V_49 , F_127 ( V_113 -> V_89 ) , V_113 -> V_88 ) ;
V_49 += V_113 -> V_88 ;
}
F_125 ( V_4 ) ;
}
struct V_4 * F_128 ( struct V_91 * V_92 , void * V_87 , unsigned int V_110 ,
T_2 V_37 , int V_177 )
{
unsigned long V_176 = ( unsigned long ) V_87 ;
unsigned long V_154 = ( V_176 + V_110 + V_125 - 1 ) >> V_159 ;
unsigned long V_155 = V_176 >> V_159 ;
struct V_4 * V_4 ;
void * V_49 = V_87 ;
int V_119 = 0 ;
if ( V_154 < V_155 )
return F_108 ( - V_160 ) ;
V_119 = V_154 - V_155 ;
V_4 = F_110 ( V_37 , V_119 ) ;
if ( ! V_4 )
return F_108 ( - V_130 ) ;
while ( V_110 ) {
struct V_109 * V_109 ;
unsigned int V_129 = V_125 ;
if ( V_129 > V_110 )
V_129 = V_110 ;
V_109 = F_90 ( V_92 -> V_166 | V_37 ) ;
if ( ! V_109 )
goto V_167;
if ( ! V_177 )
memcpy ( F_127 ( V_109 ) , V_49 , V_129 ) ;
if ( F_69 ( V_92 , V_4 , V_109 , V_129 , 0 ) < V_129 )
break;
V_110 -= V_129 ;
V_49 += V_129 ;
}
if ( V_177 ) {
V_4 -> V_66 = F_126 ;
V_4 -> V_64 = V_87 ;
} else {
V_4 -> V_66 = F_125 ;
F_111 ( V_4 , V_163 , 0 ) ;
}
return V_4 ;
V_167:
F_103 ( V_4 ) ;
F_30 ( V_4 ) ;
return F_108 ( - V_130 ) ;
}
void F_129 ( struct V_4 * V_4 )
{
struct V_31 * V_113 ;
int V_10 ;
F_89 (bvec, bio, i) {
struct V_109 * V_109 = V_113 -> V_89 ;
if ( V_109 && ! F_130 ( V_109 ) )
F_120 ( V_109 ) ;
}
}
static void F_131 ( struct V_4 * V_4 )
{
struct V_31 * V_113 ;
int V_10 ;
F_89 (bvec, bio, i) {
struct V_109 * V_109 = V_113 -> V_89 ;
if ( V_109 )
F_117 ( V_109 ) ;
}
}
static void F_132 ( struct V_67 * V_68 )
{
unsigned long V_59 ;
struct V_4 * V_4 ;
F_133 ( & V_178 , V_59 ) ;
V_4 = V_179 ;
V_179 = NULL ;
F_134 ( & V_178 , V_59 ) ;
while ( V_4 ) {
struct V_4 * V_180 = V_4 -> V_64 ;
F_129 ( V_4 ) ;
F_131 ( V_4 ) ;
F_30 ( V_4 ) ;
V_4 = V_180 ;
}
}
void F_135 ( struct V_4 * V_4 )
{
struct V_31 * V_113 ;
int V_181 = 0 ;
int V_10 ;
F_89 (bvec, bio, i) {
struct V_109 * V_109 = V_113 -> V_89 ;
if ( F_136 ( V_109 ) || F_130 ( V_109 ) ) {
F_117 ( V_109 ) ;
V_113 -> V_89 = NULL ;
} else {
V_181 ++ ;
}
}
if ( V_181 ) {
unsigned long V_59 ;
F_133 ( & V_178 , V_59 ) ;
V_4 -> V_64 = V_179 ;
V_179 = V_4 ;
F_134 ( & V_178 , V_59 ) ;
F_137 ( & V_182 ) ;
} else {
F_30 ( V_4 ) ;
}
}
void F_138 ( int V_183 , unsigned long V_184 ,
struct V_185 * V_186 )
{
int V_187 = F_139 () ;
F_140 ( V_187 , V_186 ) ;
F_141 ( V_187 , V_186 , V_188 [ V_183 ] ) ;
F_142 ( V_187 , V_186 , V_184 [ V_183 ] , V_184 ) ;
F_143 ( V_186 , V_183 ) ;
F_144 () ;
}
void F_145 ( int V_183 , struct V_185 * V_186 ,
unsigned long V_189 )
{
unsigned long V_190 = V_191 - V_189 ;
int V_187 = F_139 () ;
F_142 ( V_187 , V_186 , V_192 [ V_183 ] , V_190 ) ;
F_140 ( V_187 , V_186 ) ;
F_146 ( V_186 , V_183 ) ;
F_144 () ;
}
void F_147 ( struct V_4 * V_193 )
{
struct V_31 V_113 ;
struct V_85 V_86 ;
F_52 (bvec, bi, iter)
F_54 ( V_113 . V_89 ) ;
}
static inline bool F_148 ( struct V_4 * V_4 )
{
if ( ! F_56 ( V_4 , V_194 ) )
return true ;
F_34 ( F_57 ( & V_4 -> V_56 ) <= 0 ) ;
if ( F_58 ( & V_4 -> V_56 ) ) {
F_74 ( V_4 , V_194 ) ;
return true ;
}
return false ;
}
void F_32 ( struct V_4 * V_4 )
{
V_195:
if ( ! F_148 ( V_4 ) )
return;
if ( V_4 -> V_66 == F_31 ) {
V_4 = F_29 ( V_4 ) ;
goto V_195;
}
if ( V_4 -> V_66 )
V_4 -> V_66 ( V_4 ) ;
}
struct V_4 * F_149 ( struct V_4 * V_4 , int V_184 ,
T_2 V_196 , struct V_23 * V_24 )
{
struct V_4 * V_197 = NULL ;
F_34 ( V_184 <= 0 ) ;
F_34 ( V_184 >= F_150 ( V_4 ) ) ;
V_197 = F_64 ( V_4 , V_196 , V_24 ) ;
if ( ! V_197 )
return NULL ;
V_197 -> V_99 . V_103 = V_184 << 9 ;
if ( F_21 ( V_197 ) )
F_151 ( V_197 , 0 , V_184 ) ;
F_85 ( V_4 , V_197 -> V_99 . V_103 ) ;
return V_197 ;
}
void F_152 ( struct V_4 * V_4 , int V_111 , int V_122 )
{
V_122 <<= 9 ;
if ( V_111 == 0 && V_122 == V_4 -> V_99 . V_103 )
return;
F_74 ( V_4 , V_93 ) ;
F_85 ( V_4 , V_111 << 9 ) ;
V_4 -> V_99 . V_103 = V_122 ;
}
T_1 * F_153 ( int V_198 )
{
struct V_35 * V_199 = V_28 + V_34 ;
return F_154 ( V_198 , V_199 -> V_5 ) ;
}
void F_155 ( struct V_23 * V_24 )
{
if ( V_24 -> V_76 )
F_156 ( V_24 -> V_76 ) ;
if ( V_24 -> V_53 )
F_157 ( V_24 -> V_53 ) ;
if ( V_24 -> V_50 )
F_157 ( V_24 -> V_50 ) ;
F_158 ( V_24 ) ;
F_6 ( V_24 ) ;
F_25 ( V_24 ) ;
}
static struct V_23 * F_159 ( unsigned int V_200 ,
unsigned int V_52 ,
bool V_201 )
{
unsigned int V_202 = V_81 * sizeof( struct V_31 ) ;
struct V_23 * V_24 ;
V_24 = F_160 ( sizeof( * V_24 ) , V_19 ) ;
if ( ! V_24 )
return NULL ;
V_24 -> V_52 = V_52 ;
F_161 ( & V_24 -> V_70 ) ;
F_43 ( & V_24 -> V_71 ) ;
F_162 ( & V_24 -> V_69 , F_36 ) ;
V_24 -> V_6 = F_1 ( V_52 + V_202 ) ;
if ( ! V_24 -> V_6 ) {
F_25 ( V_24 ) ;
return NULL ;
}
V_24 -> V_53 = F_154 ( V_200 , V_24 -> V_6 ) ;
if ( ! V_24 -> V_53 )
goto V_203;
if ( V_201 ) {
V_24 -> V_50 = F_153 ( V_200 ) ;
if ( ! V_24 -> V_50 )
goto V_203;
}
V_24 -> V_76 = F_163 ( L_3 , V_204 , 0 ) ;
if ( ! V_24 -> V_76 )
goto V_203;
return V_24 ;
V_203:
F_155 ( V_24 ) ;
return NULL ;
}
struct V_23 * F_164 ( unsigned int V_200 , unsigned int V_52 )
{
return F_159 ( V_200 , V_52 , true ) ;
}
struct V_23 * F_165 ( unsigned int V_200 , unsigned int V_52 )
{
return F_159 ( V_200 , V_52 , false ) ;
}
int F_166 ( struct V_4 * V_4 , struct V_205 * V_206 )
{
if ( F_18 ( V_4 -> V_207 ) )
return - V_208 ;
F_167 ( V_206 ) ;
V_4 -> V_207 = V_206 ;
return 0 ;
}
int F_168 ( struct V_4 * V_4 )
{
struct V_209 * V_210 ;
if ( V_4 -> V_207 )
return - V_208 ;
V_210 = V_75 -> V_209 ;
if ( ! V_210 )
return - V_211 ;
F_169 ( V_210 ) ;
V_4 -> V_212 = V_210 ;
V_4 -> V_207 = F_170 ( V_75 , V_213 ) ;
return 0 ;
}
void F_20 ( struct V_4 * V_4 )
{
if ( V_4 -> V_212 ) {
F_171 ( V_4 -> V_212 ) ;
V_4 -> V_212 = NULL ;
}
if ( V_4 -> V_207 ) {
F_172 ( V_4 -> V_207 ) ;
V_4 -> V_207 = NULL ;
}
}
void F_63 ( struct V_4 * V_131 , struct V_4 * V_132 )
{
if ( V_132 -> V_207 )
F_8 ( F_166 ( V_131 , V_132 -> V_207 ) ) ;
}
static void T_5 F_173 ( void )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_33 ; V_10 ++ ) {
int V_122 ;
struct V_35 * V_36 = V_28 + V_10 ;
if ( V_36 -> V_29 <= V_81 ) {
V_36 -> V_5 = NULL ;
continue;
}
V_122 = V_36 -> V_29 * sizeof( struct V_31 ) ;
V_36 -> V_5 = F_4 ( V_36 -> V_20 , V_122 , 0 ,
V_22 | V_214 , NULL ) ;
}
}
static int T_5 F_174 ( void )
{
V_18 = 2 ;
V_13 = 0 ;
V_14 = F_160 ( V_18 * sizeof( struct V_6 ) , V_19 ) ;
if ( ! V_14 )
F_175 ( L_4 ) ;
F_176 () ;
F_173 () ;
V_215 = F_164 ( V_216 , 0 ) ;
if ( ! V_215 )
F_175 ( L_4 ) ;
if ( F_177 ( V_215 , V_216 ) )
F_175 ( L_5 ) ;
return 0 ;
}
