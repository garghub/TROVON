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
void F_19 ( struct V_4 * V_4 )
{
F_20 ( V_4 ) ;
}
static void F_21 ( struct V_4 * V_4 )
{
struct V_23 * V_24 = V_4 -> V_48 ;
void * V_49 ;
F_19 ( V_4 ) ;
if ( V_24 ) {
F_11 ( V_24 -> V_50 , V_4 -> V_51 , F_22 ( V_4 ) ) ;
V_49 = V_4 ;
V_49 -= V_24 -> V_52 ;
F_13 ( V_49 , V_24 -> V_53 ) ;
} else {
F_23 ( V_4 ) ;
}
}
void F_24 ( struct V_4 * V_4 , struct V_31 * V_54 ,
unsigned short V_55 )
{
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
F_25 ( & V_4 -> V_56 , 1 ) ;
F_25 ( & V_4 -> V_57 , 1 ) ;
V_4 -> V_51 = V_54 ;
V_4 -> V_58 = V_55 ;
}
void F_26 ( struct V_4 * V_4 )
{
unsigned long V_59 = V_4 -> V_60 & ( ~ 0UL << V_61 ) ;
F_19 ( V_4 ) ;
memset ( V_4 , 0 , V_62 ) ;
V_4 -> V_60 = V_59 ;
F_25 ( & V_4 -> V_56 , 1 ) ;
}
static struct V_4 * F_27 ( struct V_4 * V_4 )
{
struct V_4 * V_63 = V_4 -> V_64 ;
if ( ! V_63 -> V_65 )
V_63 -> V_65 = V_4 -> V_65 ;
F_28 ( V_4 ) ;
return V_63 ;
}
static void F_29 ( struct V_4 * V_4 )
{
F_30 ( F_27 ( V_4 ) ) ;
}
void F_31 ( struct V_4 * V_4 , struct V_4 * V_63 )
{
F_32 ( V_4 -> V_64 || V_4 -> V_66 ) ;
V_4 -> V_64 = V_63 ;
V_4 -> V_66 = F_29 ;
F_33 ( V_63 ) ;
}
static void F_34 ( struct V_67 * V_68 )
{
struct V_23 * V_24 = F_35 ( V_68 , struct V_23 , V_69 ) ;
struct V_4 * V_4 ;
while ( 1 ) {
F_36 ( & V_24 -> V_70 ) ;
V_4 = F_37 ( & V_24 -> V_71 ) ;
F_38 ( & V_24 -> V_70 ) ;
if ( ! V_4 )
break;
F_39 ( V_4 ) ;
}
}
static void F_40 ( struct V_23 * V_24 )
{
struct V_72 V_73 , V_74 ;
struct V_4 * V_4 ;
if ( F_41 ( ! V_24 -> V_75 ) )
return;
F_42 ( & V_73 ) ;
F_42 ( & V_74 ) ;
while ( ( V_4 = F_37 ( & V_76 -> V_72 [ 0 ] ) ) )
F_43 ( V_4 -> V_48 == V_24 ? & V_73 : & V_74 , V_4 ) ;
V_76 -> V_72 [ 0 ] = V_74 ;
F_42 ( & V_74 ) ;
while ( ( V_4 = F_37 ( & V_76 -> V_72 [ 1 ] ) ) )
F_43 ( V_4 -> V_48 == V_24 ? & V_73 : & V_74 , V_4 ) ;
V_76 -> V_72 [ 1 ] = V_74 ;
F_36 ( & V_24 -> V_70 ) ;
F_44 ( & V_24 -> V_71 , & V_73 ) ;
F_38 ( & V_24 -> V_70 ) ;
F_45 ( V_24 -> V_75 , & V_24 -> V_69 ) ;
}
struct V_4 * F_46 ( T_2 V_37 , unsigned int V_77 ,
struct V_23 * V_24 )
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
V_49 = F_47 ( sizeof( struct V_4 ) +
V_77 * sizeof( struct V_31 ) ,
V_37 ) ;
V_52 = 0 ;
V_79 = V_77 ;
} else {
if ( F_41 ( ! V_24 -> V_50 && V_77 > 0 ) )
return NULL ;
if ( V_76 -> V_72 &&
( ! F_48 ( & V_76 -> V_72 [ 0 ] ) ||
! F_48 ( & V_76 -> V_72 [ 1 ] ) ) &&
V_24 -> V_75 )
V_37 &= ~ V_43 ;
V_49 = F_16 ( V_24 -> V_53 , V_37 ) ;
if ( ! V_49 && V_37 != V_78 ) {
F_40 ( V_24 ) ;
V_37 = V_78 ;
V_49 = F_16 ( V_24 -> V_53 , V_37 ) ;
}
V_52 = V_24 -> V_52 ;
V_79 = V_81 ;
}
if ( F_18 ( ! V_49 ) )
return NULL ;
V_4 = V_49 + V_52 ;
F_24 ( V_4 , NULL , 0 ) ;
if ( V_77 > V_79 ) {
unsigned long V_27 = 0 ;
V_39 = F_15 ( V_37 , V_77 , & V_27 , V_24 -> V_50 ) ;
if ( ! V_39 && V_37 != V_78 ) {
F_40 ( V_24 ) ;
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
void F_49 ( struct V_4 * V_4 )
{
unsigned long V_59 ;
struct V_31 V_32 ;
struct V_85 V_86 ;
F_50 (bv, bio, iter) {
char * V_87 = F_51 ( & V_32 , & V_59 ) ;
memset ( V_87 , 0 , V_32 . V_88 ) ;
F_52 ( V_32 . V_89 ) ;
F_53 ( V_87 , & V_59 ) ;
}
}
void F_28 ( struct V_4 * V_4 )
{
if ( ! F_54 ( V_4 , V_90 ) )
F_21 ( V_4 ) ;
else {
F_12 ( ! F_55 ( & V_4 -> V_57 ) ) ;
if ( F_56 ( & V_4 -> V_57 ) )
F_21 ( V_4 ) ;
}
}
inline int F_57 ( struct V_91 * V_92 , struct V_4 * V_4 )
{
if ( F_18 ( ! F_54 ( V_4 , V_93 ) ) )
F_58 ( V_92 , V_4 ) ;
return V_4 -> V_94 ;
}
void F_59 ( struct V_4 * V_4 , struct V_4 * V_95 )
{
F_32 ( V_4 -> V_48 && F_22 ( V_4 ) ) ;
V_4 -> V_96 = V_95 -> V_96 ;
F_60 ( V_4 , V_97 ) ;
V_4 -> V_98 = V_95 -> V_98 ;
V_4 -> V_99 = V_95 -> V_99 ;
V_4 -> V_100 = V_95 -> V_100 ;
V_4 -> V_51 = V_95 -> V_51 ;
F_61 ( V_4 , V_95 ) ;
}
struct V_4 * F_62 ( struct V_4 * V_4 , T_2 V_37 , struct V_23 * V_24 )
{
struct V_4 * V_101 ;
V_101 = F_46 ( V_37 , 0 , V_24 ) ;
if ( ! V_101 )
return NULL ;
F_59 ( V_101 , V_4 ) ;
if ( F_63 ( V_4 ) ) {
int V_102 ;
V_102 = F_64 ( V_101 , V_4 , V_37 ) ;
if ( V_102 < 0 ) {
F_28 ( V_101 ) ;
return NULL ;
}
}
return V_101 ;
}
struct V_4 * F_65 ( struct V_4 * V_95 , T_2 V_37 ,
struct V_23 * V_24 )
{
struct V_85 V_86 ;
struct V_31 V_32 ;
struct V_4 * V_4 ;
V_4 = F_46 ( V_37 , F_66 ( V_95 ) , V_24 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_96 = V_95 -> V_96 ;
V_4 -> V_98 = V_95 -> V_98 ;
V_4 -> V_99 = V_95 -> V_99 ;
V_4 -> V_100 . V_103 = V_95 -> V_100 . V_103 ;
V_4 -> V_100 . V_104 = V_95 -> V_100 . V_104 ;
switch ( F_67 ( V_4 ) ) {
case V_105 :
case V_106 :
case V_107 :
break;
case V_108 :
V_4 -> V_51 [ V_4 -> V_109 ++ ] = V_95 -> V_51 [ 0 ] ;
break;
default:
F_50 (bv, bio_src, iter)
V_4 -> V_51 [ V_4 -> V_109 ++ ] = V_32 ;
break;
}
if ( F_63 ( V_95 ) ) {
int V_102 ;
V_102 = F_64 ( V_4 , V_95 , V_37 ) ;
if ( V_102 < 0 ) {
F_28 ( V_4 ) ;
return NULL ;
}
}
F_61 ( V_4 , V_95 ) ;
return V_4 ;
}
int F_68 ( struct V_91 * V_92 , struct V_4 * V_4 , struct V_110
* V_110 , unsigned int V_111 , unsigned int V_112 )
{
int V_113 = 0 ;
struct V_31 * V_114 ;
if ( F_18 ( F_54 ( V_4 , V_97 ) ) )
return 0 ;
if ( ( ( V_4 -> V_100 . V_104 + V_111 ) >> 9 ) > F_69 ( V_92 ) )
return 0 ;
if ( V_4 -> V_109 > 0 ) {
struct V_31 * V_115 = & V_4 -> V_51 [ V_4 -> V_109 - 1 ] ;
if ( V_110 == V_115 -> V_89 &&
V_112 == V_115 -> V_116 + V_115 -> V_88 ) {
V_115 -> V_88 += V_111 ;
V_4 -> V_100 . V_104 += V_111 ;
goto V_117;
}
if ( F_70 ( V_92 , V_115 , V_112 ) )
return 0 ;
}
if ( V_4 -> V_109 >= V_4 -> V_58 )
return 0 ;
V_114 = & V_4 -> V_51 [ V_4 -> V_109 ] ;
V_114 -> V_89 = V_110 ;
V_114 -> V_88 = V_111 ;
V_114 -> V_116 = V_112 ;
V_4 -> V_109 ++ ;
V_4 -> V_94 ++ ;
V_4 -> V_100 . V_104 += V_111 ;
while ( V_4 -> V_94 > F_71 ( V_92 ) ) {
if ( V_113 )
goto V_118;
V_113 = 1 ;
F_58 ( V_92 , V_4 ) ;
}
if ( V_4 -> V_109 > 1 && ( F_72 ( V_114 - 1 , V_114 ) ) )
F_73 ( V_4 , V_93 ) ;
V_117:
return V_111 ;
V_118:
V_114 -> V_89 = NULL ;
V_114 -> V_88 = 0 ;
V_114 -> V_116 = 0 ;
V_4 -> V_109 -- ;
V_4 -> V_100 . V_104 -= V_111 ;
F_58 ( V_92 , V_4 ) ;
return 0 ;
}
int F_74 ( struct V_4 * V_4 , struct V_110 * V_110 ,
unsigned int V_111 , unsigned int V_112 )
{
struct V_31 * V_32 ;
if ( F_41 ( F_54 ( V_4 , V_97 ) ) )
return 0 ;
if ( V_4 -> V_109 > 0 ) {
V_32 = & V_4 -> V_51 [ V_4 -> V_109 - 1 ] ;
if ( V_110 == V_32 -> V_89 &&
V_112 == V_32 -> V_116 + V_32 -> V_88 ) {
V_32 -> V_88 += V_111 ;
goto V_117;
}
}
if ( V_4 -> V_109 >= V_4 -> V_58 )
return 0 ;
V_32 = & V_4 -> V_51 [ V_4 -> V_109 ] ;
V_32 -> V_89 = V_110 ;
V_32 -> V_88 = V_111 ;
V_32 -> V_116 = V_112 ;
V_4 -> V_109 ++ ;
V_117:
V_4 -> V_100 . V_104 += V_111 ;
return V_111 ;
}
int F_75 ( struct V_4 * V_4 , struct V_119 * V_86 )
{
unsigned short V_120 = V_4 -> V_58 - V_4 -> V_109 ;
struct V_31 * V_32 = V_4 -> V_51 + V_4 -> V_109 ;
struct V_110 * * V_121 = (struct V_110 * * ) V_32 ;
T_3 V_112 , V_122 ;
T_4 V_123 ;
V_123 = F_76 ( V_86 , V_121 , V_124 , V_120 , & V_112 ) ;
if ( F_18 ( V_123 <= 0 ) )
return V_123 ? V_123 : - V_125 ;
V_120 = ( V_123 + V_112 + V_126 - 1 ) / V_126 ;
V_4 -> V_100 . V_104 += V_123 ;
V_4 -> V_109 += V_120 ;
V_122 = ( V_120 * V_126 - V_112 ) - V_123 ;
while ( V_120 -- ) {
V_32 [ V_120 ] . V_89 = V_121 [ V_120 ] ;
V_32 [ V_120 ] . V_88 = V_126 ;
V_32 [ V_120 ] . V_116 = 0 ;
}
V_32 [ 0 ] . V_116 += V_112 ;
V_32 [ 0 ] . V_88 -= V_112 ;
if ( V_122 )
V_32 [ V_4 -> V_109 - 1 ] . V_88 -= V_122 ;
F_77 ( V_86 , V_123 ) ;
return 0 ;
}
static void F_78 ( struct V_4 * V_4 )
{
struct V_127 * V_102 = V_4 -> V_64 ;
V_102 -> error = F_79 ( V_4 -> V_65 ) ;
F_80 ( & V_102 -> V_128 ) ;
}
int F_81 ( struct V_4 * V_4 )
{
struct V_127 V_102 ;
F_82 ( & V_102 . V_128 ) ;
V_4 -> V_64 = & V_102 ;
V_4 -> V_66 = F_78 ;
V_4 -> V_98 |= V_129 ;
F_83 ( V_4 ) ;
F_84 ( & V_102 . V_128 ) ;
return V_102 . error ;
}
void F_85 ( struct V_4 * V_4 , unsigned V_130 )
{
if ( F_63 ( V_4 ) )
F_86 ( V_4 , V_130 ) ;
F_87 ( V_4 , & V_4 -> V_100 , V_130 ) ;
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
return - V_131 ;
}
}
return 0 ;
}
void F_92 ( struct V_4 * V_132 , struct V_4 * V_133 )
{
struct V_85 V_134 , V_135 ;
struct V_31 V_136 , V_137 ;
void * V_138 , * V_139 ;
unsigned V_130 ;
V_134 = V_133 -> V_100 ;
V_135 = V_132 -> V_100 ;
while ( 1 ) {
if ( ! V_134 . V_104 ) {
V_133 = V_133 -> V_140 ;
if ( ! V_133 )
break;
V_134 = V_133 -> V_100 ;
}
if ( ! V_135 . V_104 ) {
V_132 = V_132 -> V_140 ;
if ( ! V_132 )
break;
V_135 = V_132 -> V_100 ;
}
V_136 = F_93 ( V_133 , V_134 ) ;
V_137 = F_93 ( V_132 , V_135 ) ;
V_130 = F_94 ( V_136 . V_88 , V_137 . V_88 ) ;
V_138 = F_95 ( V_136 . V_89 ) ;
V_139 = F_95 ( V_137 . V_89 ) ;
memcpy ( V_139 + V_137 . V_116 ,
V_138 + V_136 . V_116 ,
V_130 ) ;
F_96 ( V_139 ) ;
F_96 ( V_138 ) ;
F_87 ( V_133 , & V_134 , V_130 ) ;
F_87 ( V_132 , & V_135 , V_130 ) ;
}
}
static struct V_141 * F_97 ( unsigned int V_142 ,
T_2 V_37 )
{
if ( V_142 > V_80 )
return NULL ;
return F_47 ( sizeof( struct V_141 ) +
sizeof( struct V_143 ) * V_142 , V_37 ) ;
}
static int F_98 ( struct V_4 * V_4 , struct V_119 V_86 )
{
int V_10 ;
struct V_31 * V_114 ;
F_89 (bvec, bio, i) {
T_4 V_102 ;
V_102 = F_99 ( V_114 -> V_89 ,
V_114 -> V_116 ,
V_114 -> V_88 ,
& V_86 ) ;
if ( ! F_100 ( & V_86 ) )
break;
if ( V_102 < V_114 -> V_88 )
return - V_125 ;
}
return 0 ;
}
static int F_101 ( struct V_4 * V_4 , struct V_119 V_86 )
{
int V_10 ;
struct V_31 * V_114 ;
F_89 (bvec, bio, i) {
T_4 V_102 ;
V_102 = F_102 ( V_114 -> V_89 ,
V_114 -> V_116 ,
V_114 -> V_88 ,
& V_86 ) ;
if ( ! F_100 ( & V_86 ) )
break;
if ( V_102 < V_114 -> V_88 )
return - V_125 ;
}
return 0 ;
}
void F_103 ( struct V_4 * V_4 )
{
struct V_31 * V_114 ;
int V_10 ;
F_89 (bvec, bio, i)
F_91 ( V_114 -> V_89 ) ;
}
int F_104 ( struct V_4 * V_4 )
{
struct V_141 * V_144 = V_4 -> V_64 ;
int V_102 = 0 ;
if ( ! F_54 ( V_4 , V_145 ) ) {
if ( ! V_76 -> V_146 )
V_102 = - V_147 ;
else if ( F_105 ( V_4 ) == V_148 )
V_102 = F_101 ( V_4 , V_144 -> V_86 ) ;
if ( V_144 -> V_149 )
F_103 ( V_4 ) ;
}
F_23 ( V_144 ) ;
F_28 ( V_4 ) ;
return V_102 ;
}
struct V_4 * F_106 ( struct V_91 * V_92 ,
struct V_150 * V_151 ,
const struct V_119 * V_86 ,
T_2 V_37 )
{
struct V_141 * V_144 ;
struct V_110 * V_110 ;
struct V_4 * V_4 ;
int V_10 , V_102 ;
int V_120 = 0 ;
unsigned int V_111 = V_86 -> V_152 ;
unsigned int V_112 = V_151 ? F_107 ( V_151 -> V_112 ) : 0 ;
for ( V_10 = 0 ; V_10 < V_86 -> V_153 ; V_10 ++ ) {
unsigned long V_154 ;
unsigned long V_155 ;
unsigned long V_156 ;
V_154 = ( unsigned long ) V_86 -> V_157 [ V_10 ] . V_158 ;
V_155 = ( V_154 + V_86 -> V_157 [ V_10 ] . V_159 + V_126 - 1 )
>> V_160 ;
V_156 = V_154 >> V_160 ;
if ( V_155 < V_156 )
return F_108 ( - V_161 ) ;
V_120 += V_155 - V_156 ;
}
if ( V_112 )
V_120 ++ ;
V_144 = F_97 ( V_86 -> V_153 , V_37 ) ;
if ( ! V_144 )
return F_108 ( - V_131 ) ;
V_144 -> V_149 = V_151 ? 0 : 1 ;
memcpy ( V_144 -> V_157 , V_86 -> V_157 , sizeof( struct V_143 ) * V_86 -> V_153 ) ;
F_109 ( & V_144 -> V_86 , V_86 -> type , V_144 -> V_157 ,
V_86 -> V_153 , V_86 -> V_152 ) ;
V_102 = - V_131 ;
V_4 = F_110 ( V_37 , V_120 ) ;
if ( ! V_4 )
goto V_162;
V_102 = 0 ;
if ( V_151 ) {
V_120 = 1 << V_151 -> V_163 ;
V_10 = V_151 -> V_112 / V_126 ;
}
while ( V_111 ) {
unsigned int V_130 = V_126 ;
V_130 -= V_112 ;
if ( V_130 > V_111 )
V_130 = V_111 ;
if ( V_151 ) {
if ( V_10 == V_151 -> V_164 * V_120 ) {
V_102 = - V_131 ;
break;
}
V_110 = V_151 -> V_121 [ V_10 / V_120 ] ;
V_110 += ( V_10 % V_120 ) ;
V_10 ++ ;
} else {
V_110 = F_90 ( V_92 -> V_165 | V_37 ) ;
if ( ! V_110 ) {
V_102 = - V_131 ;
break;
}
}
if ( F_68 ( V_92 , V_4 , V_110 , V_130 , V_112 ) < V_130 )
break;
V_111 -= V_130 ;
V_112 = 0 ;
}
if ( V_102 )
goto V_166;
if ( ( ( V_86 -> type & V_167 ) && ( ! V_151 || ! V_151 -> V_168 ) ) ||
( V_151 && V_151 -> V_169 ) ) {
V_102 = F_98 ( V_4 , * V_86 ) ;
if ( V_102 )
goto V_166;
}
V_4 -> V_64 = V_144 ;
return V_4 ;
V_166:
if ( ! V_151 )
F_103 ( V_4 ) ;
F_28 ( V_4 ) ;
V_162:
F_23 ( V_144 ) ;
return F_108 ( V_102 ) ;
}
struct V_4 * F_111 ( struct V_91 * V_92 ,
const struct V_119 * V_86 ,
T_2 V_37 )
{
int V_170 ;
int V_120 = 0 ;
struct V_110 * * V_121 ;
struct V_4 * V_4 ;
int V_171 = 0 ;
int V_102 , V_112 ;
struct V_119 V_10 ;
struct V_143 V_157 ;
F_112 (iov, i, *iter) {
unsigned long V_154 = ( unsigned long ) V_157 . V_158 ;
unsigned long V_111 = V_157 . V_159 ;
unsigned long V_155 = ( V_154 + V_111 + V_126 - 1 ) >> V_160 ;
unsigned long V_156 = V_154 >> V_160 ;
if ( V_155 < V_156 )
return F_108 ( - V_161 ) ;
V_120 += V_155 - V_156 ;
if ( V_154 & F_113 ( V_92 ) )
return F_108 ( - V_161 ) ;
}
if ( ! V_120 )
return F_108 ( - V_161 ) ;
V_4 = F_110 ( V_37 , V_120 ) ;
if ( ! V_4 )
return F_108 ( - V_131 ) ;
V_102 = - V_131 ;
V_121 = F_114 ( V_120 , sizeof( struct V_110 * ) , V_37 ) ;
if ( ! V_121 )
goto V_26;
F_112 (iov, i, *iter) {
unsigned long V_154 = ( unsigned long ) V_157 . V_158 ;
unsigned long V_111 = V_157 . V_159 ;
unsigned long V_155 = ( V_154 + V_111 + V_126 - 1 ) >> V_160 ;
unsigned long V_156 = V_154 >> V_160 ;
const int V_172 = V_155 - V_156 ;
const int V_173 = V_171 + V_172 ;
V_102 = F_115 ( V_154 , V_172 ,
( V_86 -> type & V_167 ) != V_167 ,
& V_121 [ V_171 ] ) ;
if ( V_102 < V_172 ) {
V_102 = - V_125 ;
goto V_174;
}
V_112 = F_107 ( V_154 ) ;
for ( V_170 = V_171 ; V_170 < V_173 ; V_170 ++ ) {
unsigned int V_130 = V_126 - V_112 ;
if ( V_111 <= 0 )
break;
if ( V_130 > V_111 )
V_130 = V_111 ;
if ( F_68 ( V_92 , V_4 , V_121 [ V_170 ] , V_130 , V_112 ) <
V_130 )
break;
V_111 -= V_130 ;
V_112 = 0 ;
}
V_171 = V_170 ;
while ( V_170 < V_173 )
F_116 ( V_121 [ V_170 ++ ] ) ;
}
F_23 ( V_121 ) ;
F_60 ( V_4 , V_175 ) ;
F_117 ( V_4 ) ;
return V_4 ;
V_174:
for ( V_170 = 0 ; V_170 < V_120 ; V_170 ++ ) {
if ( ! V_121 [ V_170 ] )
break;
F_116 ( V_121 [ V_170 ] ) ;
}
V_26:
F_23 ( V_121 ) ;
F_28 ( V_4 ) ;
return F_108 ( V_102 ) ;
}
static void F_118 ( struct V_4 * V_4 )
{
struct V_31 * V_114 ;
int V_10 ;
F_89 (bvec, bio, i) {
if ( F_105 ( V_4 ) == V_148 )
F_119 ( V_114 -> V_89 ) ;
F_116 ( V_114 -> V_89 ) ;
}
F_28 ( V_4 ) ;
}
void F_120 ( struct V_4 * V_4 )
{
F_118 ( V_4 ) ;
F_28 ( V_4 ) ;
}
static void F_121 ( struct V_4 * V_4 )
{
F_28 ( V_4 ) ;
}
struct V_4 * F_122 ( struct V_91 * V_92 , void * V_87 , unsigned int V_111 ,
T_2 V_37 )
{
unsigned long V_176 = ( unsigned long ) V_87 ;
unsigned long V_155 = ( V_176 + V_111 + V_126 - 1 ) >> V_160 ;
unsigned long V_156 = V_176 >> V_160 ;
const int V_120 = V_155 - V_156 ;
int V_112 , V_10 ;
struct V_4 * V_4 ;
V_4 = F_110 ( V_37 , V_120 ) ;
if ( ! V_4 )
return F_108 ( - V_131 ) ;
V_112 = F_107 ( V_176 ) ;
for ( V_10 = 0 ; V_10 < V_120 ; V_10 ++ ) {
unsigned int V_130 = V_126 - V_112 ;
if ( V_111 <= 0 )
break;
if ( V_130 > V_111 )
V_130 = V_111 ;
if ( F_68 ( V_92 , V_4 , F_123 ( V_87 ) , V_130 ,
V_112 ) < V_130 ) {
F_28 ( V_4 ) ;
return F_108 ( - V_161 ) ;
}
V_87 += V_130 ;
V_111 -= V_130 ;
V_112 = 0 ;
}
V_4 -> V_66 = F_121 ;
return V_4 ;
}
static void F_124 ( struct V_4 * V_4 )
{
F_103 ( V_4 ) ;
F_28 ( V_4 ) ;
}
static void F_125 ( struct V_4 * V_4 )
{
char * V_49 = V_4 -> V_64 ;
struct V_31 * V_114 ;
int V_10 ;
F_89 (bvec, bio, i) {
memcpy ( V_49 , F_126 ( V_114 -> V_89 ) , V_114 -> V_88 ) ;
V_49 += V_114 -> V_88 ;
}
F_124 ( V_4 ) ;
}
struct V_4 * F_127 ( struct V_91 * V_92 , void * V_87 , unsigned int V_111 ,
T_2 V_37 , int V_177 )
{
unsigned long V_176 = ( unsigned long ) V_87 ;
unsigned long V_155 = ( V_176 + V_111 + V_126 - 1 ) >> V_160 ;
unsigned long V_156 = V_176 >> V_160 ;
struct V_4 * V_4 ;
void * V_49 = V_87 ;
int V_120 = 0 ;
if ( V_155 < V_156 )
return F_108 ( - V_161 ) ;
V_120 = V_155 - V_156 ;
V_4 = F_110 ( V_37 , V_120 ) ;
if ( ! V_4 )
return F_108 ( - V_131 ) ;
while ( V_111 ) {
struct V_110 * V_110 ;
unsigned int V_130 = V_126 ;
if ( V_130 > V_111 )
V_130 = V_111 ;
V_110 = F_90 ( V_92 -> V_165 | V_37 ) ;
if ( ! V_110 )
goto V_166;
if ( ! V_177 )
memcpy ( F_126 ( V_110 ) , V_49 , V_130 ) ;
if ( F_68 ( V_92 , V_4 , V_110 , V_130 , 0 ) < V_130 )
break;
V_111 -= V_130 ;
V_49 += V_130 ;
}
if ( V_177 ) {
V_4 -> V_66 = F_125 ;
V_4 -> V_64 = V_87 ;
} else {
V_4 -> V_66 = F_124 ;
}
return V_4 ;
V_166:
F_103 ( V_4 ) ;
F_28 ( V_4 ) ;
return F_108 ( - V_131 ) ;
}
void F_128 ( struct V_4 * V_4 )
{
struct V_31 * V_114 ;
int V_10 ;
F_89 (bvec, bio, i) {
struct V_110 * V_110 = V_114 -> V_89 ;
if ( V_110 && ! F_129 ( V_110 ) )
F_119 ( V_110 ) ;
}
}
static void F_130 ( struct V_4 * V_4 )
{
struct V_31 * V_114 ;
int V_10 ;
F_89 (bvec, bio, i) {
struct V_110 * V_110 = V_114 -> V_89 ;
if ( V_110 )
F_116 ( V_110 ) ;
}
}
static void F_131 ( struct V_67 * V_68 )
{
unsigned long V_59 ;
struct V_4 * V_4 ;
F_132 ( & V_178 , V_59 ) ;
V_4 = V_179 ;
V_179 = NULL ;
F_133 ( & V_178 , V_59 ) ;
while ( V_4 ) {
struct V_4 * V_180 = V_4 -> V_64 ;
F_128 ( V_4 ) ;
F_130 ( V_4 ) ;
F_28 ( V_4 ) ;
V_4 = V_180 ;
}
}
void F_134 ( struct V_4 * V_4 )
{
struct V_31 * V_114 ;
int V_181 = 0 ;
int V_10 ;
F_89 (bvec, bio, i) {
struct V_110 * V_110 = V_114 -> V_89 ;
if ( F_135 ( V_110 ) || F_129 ( V_110 ) ) {
F_116 ( V_110 ) ;
V_114 -> V_89 = NULL ;
} else {
V_181 ++ ;
}
}
if ( V_181 ) {
unsigned long V_59 ;
F_132 ( & V_178 , V_59 ) ;
V_4 -> V_64 = V_179 ;
V_179 = V_4 ;
F_133 ( & V_178 , V_59 ) ;
F_136 ( & V_182 ) ;
} else {
F_28 ( V_4 ) ;
}
}
void F_137 ( int V_183 , unsigned long V_184 ,
struct V_185 * V_186 )
{
int V_187 = F_138 () ;
F_139 ( V_187 , V_186 ) ;
F_140 ( V_187 , V_186 , V_188 [ V_183 ] ) ;
F_141 ( V_187 , V_186 , V_184 [ V_183 ] , V_184 ) ;
F_142 ( V_186 , V_183 ) ;
F_143 () ;
}
void F_144 ( int V_183 , struct V_185 * V_186 ,
unsigned long V_189 )
{
unsigned long V_190 = V_191 - V_189 ;
int V_187 = F_138 () ;
F_141 ( V_187 , V_186 , V_192 [ V_183 ] , V_190 ) ;
F_139 ( V_187 , V_186 ) ;
F_145 ( V_186 , V_183 ) ;
F_143 () ;
}
void F_146 ( struct V_4 * V_193 )
{
struct V_31 V_114 ;
struct V_85 V_86 ;
F_50 (bvec, bi, iter)
F_52 ( V_114 . V_89 ) ;
}
static inline bool F_147 ( struct V_4 * V_4 )
{
if ( ! F_54 ( V_4 , V_194 ) )
return true ;
F_32 ( F_55 ( & V_4 -> V_56 ) <= 0 ) ;
if ( F_56 ( & V_4 -> V_56 ) ) {
F_73 ( V_4 , V_194 ) ;
return true ;
}
return false ;
}
void F_30 ( struct V_4 * V_4 )
{
V_195:
if ( ! F_147 ( V_4 ) )
return;
if ( ! F_148 ( V_4 ) )
return;
if ( V_4 -> V_66 == F_29 ) {
V_4 = F_27 ( V_4 ) ;
goto V_195;
}
if ( V_4 -> V_96 && F_54 ( V_4 , V_196 ) ) {
F_149 ( F_150 ( V_4 -> V_96 ) , V_4 ,
F_79 ( V_4 -> V_65 ) ) ;
F_73 ( V_4 , V_196 ) ;
}
F_151 ( V_4 ) ;
F_19 ( V_4 ) ;
if ( V_4 -> V_66 )
V_4 -> V_66 ( V_4 ) ;
}
struct V_4 * F_152 ( struct V_4 * V_4 , int V_184 ,
T_2 V_197 , struct V_23 * V_24 )
{
struct V_4 * V_198 = NULL ;
F_32 ( V_184 <= 0 ) ;
F_32 ( V_184 >= F_153 ( V_4 ) ) ;
V_198 = F_62 ( V_4 , V_197 , V_24 ) ;
if ( ! V_198 )
return NULL ;
V_198 -> V_100 . V_104 = V_184 << 9 ;
if ( F_63 ( V_198 ) )
F_154 ( V_198 ) ;
F_85 ( V_4 , V_198 -> V_100 . V_104 ) ;
if ( F_54 ( V_4 , V_196 ) )
F_60 ( V_4 , V_196 ) ;
return V_198 ;
}
void F_155 ( struct V_4 * V_4 , int V_112 , int V_123 )
{
V_123 <<= 9 ;
if ( V_112 == 0 && V_123 == V_4 -> V_100 . V_104 )
return;
F_73 ( V_4 , V_93 ) ;
F_85 ( V_4 , V_112 << 9 ) ;
V_4 -> V_100 . V_104 = V_123 ;
if ( F_63 ( V_4 ) )
F_154 ( V_4 ) ;
}
T_1 * F_156 ( int V_199 )
{
struct V_35 * V_200 = V_28 + V_34 ;
return F_157 ( V_199 , V_200 -> V_5 ) ;
}
void F_158 ( struct V_23 * V_24 )
{
if ( V_24 -> V_75 )
F_159 ( V_24 -> V_75 ) ;
if ( V_24 -> V_53 )
F_160 ( V_24 -> V_53 ) ;
if ( V_24 -> V_50 )
F_160 ( V_24 -> V_50 ) ;
F_161 ( V_24 ) ;
F_6 ( V_24 ) ;
F_23 ( V_24 ) ;
}
struct V_23 * F_162 ( unsigned int V_201 ,
unsigned int V_52 ,
int V_59 )
{
unsigned int V_202 = V_81 * sizeof( struct V_31 ) ;
struct V_23 * V_24 ;
V_24 = F_163 ( sizeof( * V_24 ) , V_19 ) ;
if ( ! V_24 )
return NULL ;
V_24 -> V_52 = V_52 ;
F_164 ( & V_24 -> V_70 ) ;
F_42 ( & V_24 -> V_71 ) ;
F_165 ( & V_24 -> V_69 , F_34 ) ;
V_24 -> V_6 = F_1 ( V_52 + V_202 ) ;
if ( ! V_24 -> V_6 ) {
F_23 ( V_24 ) ;
return NULL ;
}
V_24 -> V_53 = F_157 ( V_201 , V_24 -> V_6 ) ;
if ( ! V_24 -> V_53 )
goto V_203;
if ( V_59 & V_204 ) {
V_24 -> V_50 = F_156 ( V_201 ) ;
if ( ! V_24 -> V_50 )
goto V_203;
}
if ( ! ( V_59 & V_205 ) )
return V_24 ;
V_24 -> V_75 = F_166 ( L_3 , V_206 , 0 ) ;
if ( ! V_24 -> V_75 )
goto V_203;
return V_24 ;
V_203:
F_158 ( V_24 ) ;
return NULL ;
}
int F_167 ( struct V_4 * V_4 , struct V_207 * V_208 )
{
if ( F_18 ( V_4 -> V_209 ) )
return - V_210 ;
F_168 ( V_208 ) ;
V_4 -> V_209 = V_208 ;
return 0 ;
}
int F_169 ( struct V_4 * V_4 )
{
struct V_211 * V_212 ;
if ( V_4 -> V_209 )
return - V_210 ;
V_212 = V_76 -> V_211 ;
if ( ! V_212 )
return - V_213 ;
F_170 ( V_212 ) ;
V_4 -> V_214 = V_212 ;
V_4 -> V_209 = F_171 ( V_76 , V_215 ) ;
return 0 ;
}
void F_20 ( struct V_4 * V_4 )
{
if ( V_4 -> V_214 ) {
F_172 ( V_4 -> V_214 ) ;
V_4 -> V_214 = NULL ;
}
if ( V_4 -> V_209 ) {
F_173 ( V_4 -> V_209 ) ;
V_4 -> V_209 = NULL ;
}
}
void F_61 ( struct V_4 * V_132 , struct V_4 * V_133 )
{
if ( V_133 -> V_209 )
F_8 ( F_167 ( V_132 , V_133 -> V_209 ) ) ;
}
static void T_5 F_174 ( void )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_33 ; V_10 ++ ) {
int V_123 ;
struct V_35 * V_36 = V_28 + V_10 ;
if ( V_36 -> V_29 <= V_81 ) {
V_36 -> V_5 = NULL ;
continue;
}
V_123 = V_36 -> V_29 * sizeof( struct V_31 ) ;
V_36 -> V_5 = F_4 ( V_36 -> V_20 , V_123 , 0 ,
V_22 | V_216 , NULL ) ;
}
}
static int T_5 F_175 ( void )
{
V_18 = 2 ;
V_13 = 0 ;
V_14 = F_163 ( V_18 * sizeof( struct V_6 ) , V_19 ) ;
if ( ! V_14 )
F_176 ( L_4 ) ;
F_177 () ;
F_174 () ;
V_217 = F_162 ( V_218 , 0 , V_204 ) ;
if ( ! V_217 )
F_176 ( L_4 ) ;
if ( F_178 ( V_217 , V_218 ) )
F_176 ( L_5 ) ;
return 0 ;
}
