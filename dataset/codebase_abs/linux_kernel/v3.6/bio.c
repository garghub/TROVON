static struct V_1 * F_1 ( unsigned int V_2 )
{
unsigned int V_3 = sizeof( struct V_4 ) + V_2 ;
struct V_1 * V_5 = NULL ;
struct V_6 * V_7 , * V_8 ;
unsigned int V_9 , V_10 = - 1 ;
F_2 ( & V_11 ) ;
V_9 = 0 ;
while ( V_9 < V_12 ) {
V_7 = & V_13 [ V_9 ] ;
if ( ! V_7 -> V_5 && V_10 == - 1 )
V_10 = V_9 ;
else if ( V_7 -> V_14 == V_3 ) {
V_5 = V_7 -> V_5 ;
V_7 -> V_15 ++ ;
break;
}
V_9 ++ ;
}
if ( V_5 )
goto V_16;
if ( V_12 == V_17 && V_10 == - 1 ) {
V_17 <<= 1 ;
V_8 = F_3 ( V_13 ,
V_17 * sizeof( struct V_6 ) ,
V_18 ) ;
if ( ! V_8 )
goto V_16;
V_13 = V_8 ;
}
if ( V_10 == - 1 )
V_10 = V_12 ++ ;
V_7 = & V_13 [ V_10 ] ;
snprintf ( V_7 -> V_19 , sizeof( V_7 -> V_19 ) , L_1 , V_10 ) ;
V_5 = F_4 ( V_7 -> V_19 , V_3 , 0 , V_20 , NULL ) ;
if ( ! V_5 )
goto V_16;
F_5 ( V_21 L_2 , V_7 -> V_19 , V_10 ) ;
V_7 -> V_5 = V_5 ;
V_7 -> V_15 = 1 ;
V_7 -> V_14 = V_3 ;
V_16:
F_6 ( & V_11 ) ;
return V_5 ;
}
static void F_7 ( struct V_22 * V_23 )
{
struct V_6 * V_7 = NULL ;
unsigned int V_9 ;
F_2 ( & V_11 ) ;
for ( V_9 = 0 ; V_9 < V_12 ; V_9 ++ ) {
if ( V_23 -> V_6 == V_13 [ V_9 ] . V_5 ) {
V_7 = & V_13 [ V_9 ] ;
break;
}
}
if ( F_8 ( ! V_7 , V_24 L_3 ) )
goto V_25;
F_9 ( ! V_7 -> V_15 ) ;
if ( -- V_7 -> V_15 )
goto V_25;
F_10 ( V_7 -> V_5 ) ;
V_7 -> V_5 = NULL ;
V_25:
F_6 ( & V_11 ) ;
}
unsigned int F_11 ( unsigned short V_26 )
{
return V_27 [ V_26 ] . V_28 ;
}
void F_12 ( struct V_22 * V_23 , struct V_29 * V_30 , unsigned int V_26 )
{
F_13 ( V_26 >= V_31 ) ;
if ( V_26 == V_32 )
F_14 ( V_30 , V_23 -> V_33 ) ;
else {
struct V_34 * V_35 = V_27 + V_26 ;
F_15 ( V_35 -> V_5 , V_30 ) ;
}
}
struct V_29 * F_16 ( T_1 V_36 , int V_37 , unsigned long * V_26 ,
struct V_22 * V_23 )
{
struct V_29 * V_38 ;
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
if ( * V_26 == V_32 ) {
V_40:
V_38 = F_17 ( V_23 -> V_33 , V_36 ) ;
} else {
struct V_34 * V_35 = V_27 + * V_26 ;
T_1 V_41 = V_36 & ~ ( V_42 | V_43 ) ;
V_41 |= V_44 | V_45 | V_46 ;
V_38 = F_18 ( V_35 -> V_5 , V_41 ) ;
if ( F_19 ( ! V_38 && ( V_36 & V_42 ) ) ) {
* V_26 = V_32 ;
goto V_40;
}
}
return V_38 ;
}
void F_20 ( struct V_4 * V_4 , struct V_22 * V_23 )
{
void * V_47 ;
if ( F_21 ( V_4 ) )
F_12 ( V_23 , V_4 -> V_48 , F_22 ( V_4 ) ) ;
if ( F_23 ( V_4 ) )
F_24 ( V_4 , V_23 ) ;
V_47 = V_4 ;
if ( V_23 -> V_49 )
V_47 -= V_23 -> V_49 ;
F_14 ( V_47 , V_23 -> V_50 ) ;
}
void F_25 ( struct V_4 * V_4 )
{
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_51 = 1 << V_52 ;
F_26 ( & V_4 -> V_53 , 1 ) ;
}
struct V_4 * F_27 ( T_1 V_36 , int V_54 , struct V_22 * V_23 )
{
unsigned long V_26 = V_55 ;
struct V_29 * V_38 = NULL ;
struct V_4 * V_4 ;
void * V_47 ;
V_47 = F_17 ( V_23 -> V_50 , V_36 ) ;
if ( F_19 ( ! V_47 ) )
return NULL ;
V_4 = V_47 + V_23 -> V_49 ;
F_25 ( V_4 ) ;
if ( F_19 ( ! V_54 ) )
goto V_56;
if ( V_54 <= V_57 ) {
V_38 = V_4 -> V_58 ;
V_54 = V_57 ;
} else {
V_38 = F_16 ( V_36 , V_54 , & V_26 , V_23 ) ;
if ( F_19 ( ! V_38 ) )
goto V_59;
V_54 = F_11 ( V_26 ) ;
}
V_56:
V_4 -> V_51 |= V_26 << V_60 ;
V_4 -> V_61 = V_54 ;
V_4 -> V_48 = V_38 ;
return V_4 ;
V_59:
F_14 ( V_47 , V_23 -> V_50 ) ;
return NULL ;
}
static void F_28 ( struct V_4 * V_4 )
{
F_20 ( V_4 , V_62 ) ;
}
struct V_4 * F_29 ( T_1 V_36 , unsigned int V_54 )
{
struct V_4 * V_4 = F_27 ( V_36 , V_54 , V_62 ) ;
if ( V_4 )
V_4 -> V_63 = F_28 ;
return V_4 ;
}
static void F_30 ( struct V_4 * V_4 )
{
if ( F_23 ( V_4 ) )
F_24 ( V_4 , V_62 ) ;
F_31 ( V_4 ) ;
}
struct V_4 * F_32 ( T_1 V_36 , unsigned int V_54 )
{
struct V_4 * V_4 ;
if ( V_54 > V_64 )
return NULL ;
V_4 = F_33 ( sizeof( struct V_4 ) + V_54 * sizeof( struct V_29 ) ,
V_36 ) ;
if ( F_19 ( ! V_4 ) )
return NULL ;
F_25 ( V_4 ) ;
V_4 -> V_51 |= V_55 << V_60 ;
V_4 -> V_61 = V_54 ;
V_4 -> V_48 = V_4 -> V_58 ;
V_4 -> V_63 = F_30 ;
return V_4 ;
}
void F_34 ( struct V_4 * V_4 )
{
unsigned long V_65 ;
struct V_29 * V_30 ;
int V_9 ;
F_35 (bv, bio, i) {
char * V_66 = F_36 ( V_30 , & V_65 ) ;
memset ( V_66 , 0 , V_30 -> V_67 ) ;
F_37 ( V_30 -> V_68 ) ;
F_38 ( V_66 , & V_65 ) ;
}
}
void F_39 ( struct V_4 * V_4 )
{
F_13 ( ! F_40 ( & V_4 -> V_53 ) ) ;
if ( F_41 ( & V_4 -> V_53 ) ) {
F_42 ( V_4 ) ;
V_4 -> V_69 = NULL ;
V_4 -> V_63 ( V_4 ) ;
}
}
inline int F_43 ( struct V_70 * V_71 , struct V_4 * V_4 )
{
if ( F_19 ( ! F_44 ( V_4 , V_72 ) ) )
F_45 ( V_71 , V_4 ) ;
return V_4 -> V_73 ;
}
void F_46 ( struct V_4 * V_4 , struct V_4 * V_74 )
{
memcpy ( V_4 -> V_48 , V_74 -> V_48 ,
V_74 -> V_61 * sizeof( struct V_29 ) ) ;
V_4 -> V_75 = V_74 -> V_75 ;
V_4 -> V_76 = V_74 -> V_76 ;
V_4 -> V_51 |= 1 << V_77 ;
V_4 -> V_78 = V_74 -> V_78 ;
V_4 -> V_79 = V_74 -> V_79 ;
V_4 -> V_80 = V_74 -> V_80 ;
V_4 -> V_81 = V_74 -> V_81 ;
}
struct V_4 * F_47 ( struct V_4 * V_4 , T_1 V_36 )
{
struct V_4 * V_82 = F_27 ( V_36 , V_4 -> V_61 , V_62 ) ;
if ( ! V_82 )
return NULL ;
V_82 -> V_63 = F_28 ;
F_46 ( V_82 , V_4 ) ;
if ( F_23 ( V_4 ) ) {
int V_83 ;
V_83 = F_48 ( V_82 , V_4 , V_36 , V_62 ) ;
if ( V_83 < 0 ) {
F_39 ( V_82 ) ;
return NULL ;
}
}
return V_82 ;
}
int F_49 ( struct V_84 * V_85 )
{
struct V_70 * V_71 = F_50 ( V_85 ) ;
int V_86 ;
V_86 = F_51 ( unsigned ,
F_52 ( V_71 ) ,
F_53 ( V_71 ) / ( V_87 >> 9 ) + 1 ) ;
return F_51 ( unsigned , V_86 , V_39 ) ;
}
static int F_54 ( struct V_70 * V_71 , struct V_4 * V_4 , struct V_88
* V_88 , unsigned int V_89 , unsigned int V_90 ,
unsigned short V_91 )
{
int V_92 = 0 ;
struct V_29 * V_93 ;
if ( F_19 ( F_44 ( V_4 , V_77 ) ) )
return 0 ;
if ( ( ( V_4 -> V_80 + V_89 ) >> 9 ) > V_91 )
return 0 ;
if ( V_4 -> V_79 > 0 ) {
struct V_29 * V_94 = & V_4 -> V_48 [ V_4 -> V_79 - 1 ] ;
if ( V_88 == V_94 -> V_68 &&
V_90 == V_94 -> V_95 + V_94 -> V_67 ) {
unsigned int V_96 = V_94 -> V_67 ;
V_94 -> V_67 += V_89 ;
if ( V_71 -> V_97 ) {
struct V_98 V_99 = {
. V_76 = V_4 -> V_76 ,
. V_75 = V_4 -> V_75 ,
. V_80 = V_4 -> V_80 - V_96 ,
. V_78 = V_4 -> V_78 ,
} ;
if ( V_71 -> V_97 ( V_71 , & V_99 , V_94 ) < V_94 -> V_67 ) {
V_94 -> V_67 -= V_89 ;
return 0 ;
}
}
goto V_100;
}
}
if ( V_4 -> V_79 >= V_4 -> V_61 )
return 0 ;
while ( V_4 -> V_73 >= F_52 ( V_71 ) ) {
if ( V_92 )
return 0 ;
V_92 = 1 ;
F_45 ( V_71 , V_4 ) ;
}
V_93 = & V_4 -> V_48 [ V_4 -> V_79 ] ;
V_93 -> V_68 = V_88 ;
V_93 -> V_67 = V_89 ;
V_93 -> V_95 = V_90 ;
if ( V_71 -> V_97 ) {
struct V_98 V_99 = {
. V_76 = V_4 -> V_76 ,
. V_75 = V_4 -> V_75 ,
. V_80 = V_4 -> V_80 ,
. V_78 = V_4 -> V_78 ,
} ;
if ( V_71 -> V_97 ( V_71 , & V_99 , V_93 ) < V_93 -> V_67 ) {
V_93 -> V_68 = NULL ;
V_93 -> V_67 = 0 ;
V_93 -> V_95 = 0 ;
return 0 ;
}
}
if ( V_4 -> V_79 && ( F_55 ( V_93 - 1 , V_93 ) ) )
V_4 -> V_51 &= ~ ( 1 << V_72 ) ;
V_4 -> V_79 ++ ;
V_4 -> V_73 ++ ;
V_100:
V_4 -> V_80 += V_89 ;
return V_89 ;
}
int F_56 ( struct V_70 * V_71 , struct V_4 * V_4 , struct V_88 * V_88 ,
unsigned int V_89 , unsigned int V_90 )
{
return F_54 ( V_71 , V_4 , V_88 , V_89 , V_90 ,
F_57 ( V_71 ) ) ;
}
int F_58 ( struct V_4 * V_4 , struct V_88 * V_88 , unsigned int V_89 ,
unsigned int V_90 )
{
struct V_70 * V_71 = F_50 ( V_4 -> V_76 ) ;
return F_54 ( V_71 , V_4 , V_88 , V_89 , V_90 , F_53 ( V_71 ) ) ;
}
static void F_59 ( struct V_101 * V_102 , struct V_4 * V_4 ,
struct V_103 * V_104 , int V_105 ,
int V_106 )
{
memcpy ( V_102 -> V_107 , V_4 -> V_48 , sizeof( struct V_29 ) * V_4 -> V_79 ) ;
memcpy ( V_102 -> V_108 , V_104 , sizeof( struct V_103 ) * V_105 ) ;
V_102 -> V_109 = V_105 ;
V_102 -> V_106 = V_106 ;
V_4 -> V_110 = V_102 ;
}
static void F_60 ( struct V_101 * V_102 )
{
F_31 ( V_102 -> V_107 ) ;
F_31 ( V_102 -> V_108 ) ;
F_31 ( V_102 ) ;
}
static struct V_101 * F_61 ( int V_111 ,
unsigned int V_105 ,
T_1 V_36 )
{
struct V_101 * V_102 ;
if ( V_105 > V_64 )
return NULL ;
V_102 = F_33 ( sizeof( * V_102 ) , V_36 ) ;
if ( ! V_102 )
return NULL ;
V_102 -> V_107 = F_33 ( sizeof( struct V_29 ) * V_111 , V_36 ) ;
if ( ! V_102 -> V_107 ) {
F_31 ( V_102 ) ;
return NULL ;
}
V_102 -> V_108 = F_33 ( sizeof( struct V_103 ) * V_105 , V_36 ) ;
if ( V_102 -> V_108 )
return V_102 ;
F_31 ( V_102 -> V_107 ) ;
F_31 ( V_102 ) ;
return NULL ;
}
static int F_62 ( struct V_4 * V_4 , struct V_29 * V_107 ,
struct V_103 * V_104 , int V_105 ,
int V_112 , int V_113 , int V_114 )
{
int V_83 = 0 , V_9 ;
struct V_29 * V_93 ;
int V_115 = 0 ;
unsigned int V_116 = 0 ;
F_63 (bvec, bio, i, 0 ) {
char * V_117 = F_64 ( V_93 -> V_68 ) ;
unsigned int V_67 = V_107 [ V_9 ] . V_67 ;
while ( V_67 && V_115 < V_105 ) {
unsigned int V_118 ;
char T_2 * V_119 ;
V_118 = F_51 (unsigned int,
iov[iov_idx].iov_len - iov_off, bv_len) ;
V_119 = V_104 [ V_115 ] . V_120 + V_116 ;
if ( ! V_83 ) {
if ( V_112 )
V_83 = F_65 ( V_119 , V_117 ,
V_118 ) ;
if ( V_113 )
V_83 = F_66 ( V_117 , V_119 ,
V_118 ) ;
if ( V_83 )
V_83 = - V_121 ;
}
V_67 -= V_118 ;
V_117 += V_118 ;
V_119 += V_118 ;
V_116 += V_118 ;
if ( V_104 [ V_115 ] . V_122 == V_116 ) {
V_115 ++ ;
V_116 = 0 ;
}
}
if ( V_114 )
F_67 ( V_93 -> V_68 ) ;
}
return V_83 ;
}
int F_68 ( struct V_4 * V_4 )
{
struct V_101 * V_102 = V_4 -> V_110 ;
int V_83 = 0 ;
if ( ! F_44 ( V_4 , V_123 ) )
V_83 = F_62 ( V_4 , V_102 -> V_107 , V_102 -> V_108 ,
V_102 -> V_109 , F_69 ( V_4 ) == V_124 ,
0 , V_102 -> V_106 ) ;
F_60 ( V_102 ) ;
F_39 ( V_4 ) ;
return V_83 ;
}
struct V_4 * F_70 ( struct V_70 * V_71 ,
struct V_125 * V_126 ,
struct V_103 * V_104 , int V_105 ,
int V_127 , T_1 V_36 )
{
struct V_101 * V_102 ;
struct V_29 * V_93 ;
struct V_88 * V_88 ;
struct V_4 * V_4 ;
int V_9 , V_83 ;
int V_86 = 0 ;
unsigned int V_89 = 0 ;
unsigned int V_90 = V_126 ? V_126 -> V_90 & ~ V_128 : 0 ;
for ( V_9 = 0 ; V_9 < V_105 ; V_9 ++ ) {
unsigned long V_129 ;
unsigned long V_130 ;
unsigned long V_131 ;
V_129 = ( unsigned long ) V_104 [ V_9 ] . V_120 ;
V_130 = ( V_129 + V_104 [ V_9 ] . V_122 + V_87 - 1 ) >> V_132 ;
V_131 = V_129 >> V_132 ;
if ( V_130 < V_131 )
return F_71 ( - V_133 ) ;
V_86 += V_130 - V_131 ;
V_89 += V_104 [ V_9 ] . V_122 ;
}
if ( V_90 )
V_86 ++ ;
V_102 = F_61 ( V_86 , V_105 , V_36 ) ;
if ( ! V_102 )
return F_71 ( - V_134 ) ;
V_83 = - V_134 ;
V_4 = F_32 ( V_36 , V_86 ) ;
if ( ! V_4 )
goto V_135;
if ( ! V_127 )
V_4 -> V_78 |= V_136 ;
V_83 = 0 ;
if ( V_126 ) {
V_86 = 1 << V_126 -> V_137 ;
V_9 = V_126 -> V_90 / V_87 ;
}
while ( V_89 ) {
unsigned int V_118 = V_87 ;
V_118 -= V_90 ;
if ( V_118 > V_89 )
V_118 = V_89 ;
if ( V_126 ) {
if ( V_9 == V_126 -> V_138 * V_86 ) {
V_83 = - V_134 ;
break;
}
V_88 = V_126 -> V_139 [ V_9 / V_86 ] ;
V_88 += ( V_9 % V_86 ) ;
V_9 ++ ;
} else {
V_88 = F_72 ( V_71 -> V_140 | V_36 ) ;
if ( ! V_88 ) {
V_83 = - V_134 ;
break;
}
}
if ( F_56 ( V_71 , V_4 , V_88 , V_118 , V_90 ) < V_118 )
break;
V_89 -= V_118 ;
V_90 = 0 ;
}
if ( V_83 )
goto V_141;
if ( ( ! V_127 && ( ! V_126 || ! V_126 -> V_142 ) ) ||
( V_126 && V_126 -> V_113 ) ) {
V_83 = F_62 ( V_4 , V_4 -> V_48 , V_104 , V_105 , 0 , 1 , 0 ) ;
if ( V_83 )
goto V_141;
}
F_59 ( V_102 , V_4 , V_104 , V_105 , V_126 ? 0 : 1 ) ;
return V_4 ;
V_141:
if ( ! V_126 )
F_35 (bvec, bio, i)
F_67 ( V_93 -> V_68 ) ;
F_39 ( V_4 ) ;
V_135:
F_60 ( V_102 ) ;
return F_71 ( V_83 ) ;
}
struct V_4 * F_73 ( struct V_70 * V_71 , struct V_125 * V_126 ,
unsigned long V_129 , unsigned int V_89 ,
int V_127 , T_1 V_36 )
{
struct V_103 V_104 ;
V_104 . V_120 = ( void T_2 * ) V_129 ;
V_104 . V_122 = V_89 ;
return F_70 ( V_71 , V_126 , & V_104 , 1 , V_127 , V_36 ) ;
}
static struct V_4 * F_74 ( struct V_70 * V_71 ,
struct V_84 * V_85 ,
struct V_103 * V_104 , int V_105 ,
int V_127 , T_1 V_36 )
{
int V_9 , V_143 ;
int V_86 = 0 ;
struct V_88 * * V_139 ;
struct V_4 * V_4 ;
int V_144 = 0 ;
int V_83 , V_90 ;
for ( V_9 = 0 ; V_9 < V_105 ; V_9 ++ ) {
unsigned long V_129 = ( unsigned long ) V_104 [ V_9 ] . V_120 ;
unsigned long V_89 = V_104 [ V_9 ] . V_122 ;
unsigned long V_130 = ( V_129 + V_89 + V_87 - 1 ) >> V_132 ;
unsigned long V_131 = V_129 >> V_132 ;
if ( V_130 < V_131 )
return F_71 ( - V_133 ) ;
V_86 += V_130 - V_131 ;
if ( V_129 & F_75 ( V_71 ) )
return F_71 ( - V_133 ) ;
}
if ( ! V_86 )
return F_71 ( - V_133 ) ;
V_4 = F_32 ( V_36 , V_86 ) ;
if ( ! V_4 )
return F_71 ( - V_134 ) ;
V_83 = - V_134 ;
V_139 = F_76 ( V_86 , sizeof( struct V_88 * ) , V_36 ) ;
if ( ! V_139 )
goto V_25;
for ( V_9 = 0 ; V_9 < V_105 ; V_9 ++ ) {
unsigned long V_129 = ( unsigned long ) V_104 [ V_9 ] . V_120 ;
unsigned long V_89 = V_104 [ V_9 ] . V_122 ;
unsigned long V_130 = ( V_129 + V_89 + V_87 - 1 ) >> V_132 ;
unsigned long V_131 = V_129 >> V_132 ;
const int V_145 = V_130 - V_131 ;
const int V_146 = V_144 + V_145 ;
V_83 = F_77 ( V_129 , V_145 ,
V_127 , & V_139 [ V_144 ] ) ;
if ( V_83 < V_145 ) {
V_83 = - V_121 ;
goto V_147;
}
V_90 = V_129 & ~ V_128 ;
for ( V_143 = V_144 ; V_143 < V_146 ; V_143 ++ ) {
unsigned int V_118 = V_87 - V_90 ;
if ( V_89 <= 0 )
break;
if ( V_118 > V_89 )
V_118 = V_89 ;
if ( F_56 ( V_71 , V_4 , V_139 [ V_143 ] , V_118 , V_90 ) <
V_118 )
break;
V_89 -= V_118 ;
V_90 = 0 ;
}
V_144 = V_143 ;
while ( V_143 < V_146 )
F_78 ( V_139 [ V_143 ++ ] ) ;
}
F_31 ( V_139 ) ;
if ( ! V_127 )
V_4 -> V_78 |= V_136 ;
V_4 -> V_76 = V_85 ;
V_4 -> V_51 |= ( 1 << V_148 ) ;
return V_4 ;
V_147:
for ( V_9 = 0 ; V_9 < V_86 ; V_9 ++ ) {
if( ! V_139 [ V_9 ] )
break;
F_78 ( V_139 [ V_9 ] ) ;
}
V_25:
F_31 ( V_139 ) ;
F_39 ( V_4 ) ;
return F_71 ( V_83 ) ;
}
struct V_4 * F_79 ( struct V_70 * V_71 , struct V_84 * V_85 ,
unsigned long V_129 , unsigned int V_89 , int V_127 ,
T_1 V_36 )
{
struct V_103 V_104 ;
V_104 . V_120 = ( void T_2 * ) V_129 ;
V_104 . V_122 = V_89 ;
return F_80 ( V_71 , V_85 , & V_104 , 1 , V_127 , V_36 ) ;
}
struct V_4 * F_80 ( struct V_70 * V_71 , struct V_84 * V_85 ,
struct V_103 * V_104 , int V_105 ,
int V_127 , T_1 V_36 )
{
struct V_4 * V_4 ;
V_4 = F_74 ( V_71 , V_85 , V_104 , V_105 , V_127 ,
V_36 ) ;
if ( F_81 ( V_4 ) )
return V_4 ;
F_82 ( V_4 ) ;
return V_4 ;
}
static void F_83 ( struct V_4 * V_4 )
{
struct V_29 * V_93 ;
int V_9 ;
F_63 (bvec, bio, i, 0 ) {
if ( F_69 ( V_4 ) == V_124 )
F_84 ( V_93 -> V_68 ) ;
F_78 ( V_93 -> V_68 ) ;
}
F_39 ( V_4 ) ;
}
void F_85 ( struct V_4 * V_4 )
{
F_83 ( V_4 ) ;
F_39 ( V_4 ) ;
}
static void F_86 ( struct V_4 * V_4 , int V_149 )
{
F_39 ( V_4 ) ;
}
static struct V_4 * F_87 ( struct V_70 * V_71 , void * V_66 ,
unsigned int V_89 , T_1 V_36 )
{
unsigned long V_150 = ( unsigned long ) V_66 ;
unsigned long V_130 = ( V_150 + V_89 + V_87 - 1 ) >> V_132 ;
unsigned long V_131 = V_150 >> V_132 ;
const int V_86 = V_130 - V_131 ;
int V_90 , V_9 ;
struct V_4 * V_4 ;
V_4 = F_32 ( V_36 , V_86 ) ;
if ( ! V_4 )
return F_71 ( - V_134 ) ;
V_90 = F_88 ( V_150 ) ;
for ( V_9 = 0 ; V_9 < V_86 ; V_9 ++ ) {
unsigned int V_118 = V_87 - V_90 ;
if ( V_89 <= 0 )
break;
if ( V_118 > V_89 )
V_118 = V_89 ;
if ( F_56 ( V_71 , V_4 , F_89 ( V_66 ) , V_118 ,
V_90 ) < V_118 )
break;
V_66 += V_118 ;
V_89 -= V_118 ;
V_90 = 0 ;
}
V_4 -> V_151 = F_86 ;
return V_4 ;
}
struct V_4 * F_90 ( struct V_70 * V_71 , void * V_66 , unsigned int V_89 ,
T_1 V_36 )
{
struct V_4 * V_4 ;
V_4 = F_87 ( V_71 , V_66 , V_89 , V_36 ) ;
if ( F_81 ( V_4 ) )
return V_4 ;
if ( V_4 -> V_80 == V_89 )
return V_4 ;
F_39 ( V_4 ) ;
return F_71 ( - V_133 ) ;
}
static void F_91 ( struct V_4 * V_4 , int V_149 )
{
struct V_29 * V_93 ;
const int V_152 = F_69 ( V_4 ) == V_124 ;
struct V_101 * V_102 = V_4 -> V_110 ;
int V_9 ;
char * V_47 = V_102 -> V_108 [ 0 ] . V_120 ;
F_63 (bvec, bio, i, 0 ) {
char * V_153 = F_64 ( V_93 -> V_68 ) ;
int V_89 = V_102 -> V_107 [ V_9 ] . V_67 ;
if ( V_152 )
memcpy ( V_47 , V_153 , V_89 ) ;
F_67 ( V_93 -> V_68 ) ;
V_47 += V_89 ;
}
F_60 ( V_102 ) ;
F_39 ( V_4 ) ;
}
struct V_4 * F_92 ( struct V_70 * V_71 , void * V_66 , unsigned int V_89 ,
T_1 V_36 , int V_154 )
{
struct V_4 * V_4 ;
struct V_29 * V_93 ;
int V_9 ;
V_4 = F_73 ( V_71 , NULL , ( unsigned long ) V_66 , V_89 , 1 , V_36 ) ;
if ( F_81 ( V_4 ) )
return V_4 ;
if ( ! V_154 ) {
void * V_47 = V_66 ;
F_35 (bvec, bio, i) {
char * V_153 = F_64 ( V_93 -> V_68 ) ;
memcpy ( V_153 , V_47 , V_93 -> V_67 ) ;
V_47 += V_93 -> V_67 ;
}
}
V_4 -> V_151 = F_91 ;
return V_4 ;
}
void F_93 ( struct V_4 * V_4 )
{
struct V_29 * V_93 = V_4 -> V_48 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_4 -> V_79 ; V_9 ++ ) {
struct V_88 * V_88 = V_93 [ V_9 ] . V_68 ;
if ( V_88 && ! F_94 ( V_88 ) )
F_84 ( V_88 ) ;
}
}
static void F_95 ( struct V_4 * V_4 )
{
struct V_29 * V_93 = V_4 -> V_48 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_4 -> V_79 ; V_9 ++ ) {
struct V_88 * V_88 = V_93 [ V_9 ] . V_68 ;
if ( V_88 )
F_96 ( V_88 ) ;
}
}
static void F_97 ( struct V_155 * V_156 )
{
unsigned long V_65 ;
struct V_4 * V_4 ;
F_98 ( & V_157 , V_65 ) ;
V_4 = V_158 ;
V_158 = NULL ;
F_99 ( & V_157 , V_65 ) ;
while ( V_4 ) {
struct V_4 * V_159 = V_4 -> V_110 ;
F_93 ( V_4 ) ;
F_95 ( V_4 ) ;
F_39 ( V_4 ) ;
V_4 = V_159 ;
}
}
void F_100 ( struct V_4 * V_4 )
{
struct V_29 * V_93 = V_4 -> V_48 ;
int V_160 = 0 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_4 -> V_79 ; V_9 ++ ) {
struct V_88 * V_88 = V_93 [ V_9 ] . V_68 ;
if ( F_101 ( V_88 ) || F_94 ( V_88 ) ) {
F_78 ( V_88 ) ;
V_93 [ V_9 ] . V_68 = NULL ;
} else {
V_160 ++ ;
}
}
if ( V_160 ) {
unsigned long V_65 ;
F_98 ( & V_157 , V_65 ) ;
V_4 -> V_110 = V_158 ;
V_158 = V_4 ;
F_99 ( & V_157 , V_65 ) ;
F_102 ( & V_161 ) ;
} else {
F_39 ( V_4 ) ;
}
}
void F_103 ( struct V_4 * V_162 )
{
int V_9 ;
struct V_29 * V_93 ;
F_35 (bvec, bi, i)
F_37 ( V_93 -> V_68 ) ;
}
void F_104 ( struct V_4 * V_4 , int error )
{
if ( error )
F_105 ( V_52 , & V_4 -> V_51 ) ;
else if ( ! F_106 ( V_52 , & V_4 -> V_51 ) )
error = - V_163 ;
if ( V_4 -> V_151 )
V_4 -> V_151 ( V_4 , error ) ;
}
void F_107 ( struct V_164 * V_165 )
{
if ( F_41 ( & V_165 -> V_166 ) ) {
struct V_4 * V_167 = V_165 -> V_168 . V_110 ;
F_104 ( V_167 , V_165 -> error ) ;
F_14 ( V_165 , V_165 -> V_169 . V_110 ) ;
}
}
static void F_108 ( struct V_4 * V_162 , int V_149 )
{
struct V_164 * V_165 = F_109 ( V_162 , struct V_164 , V_168 ) ;
if ( V_149 )
V_165 -> error = V_149 ;
F_107 ( V_165 ) ;
}
static void F_110 ( struct V_4 * V_162 , int V_149 )
{
struct V_164 * V_165 = F_109 ( V_162 , struct V_164 , V_169 ) ;
if ( V_149 )
V_165 -> error = V_149 ;
F_107 ( V_165 ) ;
}
struct V_164 * F_111 ( struct V_4 * V_162 , int V_170 )
{
struct V_164 * V_165 = F_17 ( V_171 , V_172 ) ;
if ( ! V_165 )
return V_165 ;
F_112 ( F_50 ( V_162 -> V_76 ) , V_162 ,
V_162 -> V_75 + V_170 ) ;
F_113 ( V_162 -> V_79 != 1 ) ;
F_113 ( V_162 -> V_81 != 0 ) ;
F_26 ( & V_165 -> V_166 , 3 ) ;
V_165 -> error = 0 ;
V_165 -> V_168 = * V_162 ;
V_165 -> V_169 = * V_162 ;
V_165 -> V_169 . V_75 += V_170 ;
V_165 -> V_169 . V_80 -= V_170 << 9 ;
V_165 -> V_168 . V_80 = V_170 << 9 ;
V_165 -> V_173 = V_162 -> V_48 [ 0 ] ;
V_165 -> V_174 = V_162 -> V_48 [ 0 ] ;
V_165 -> V_174 . V_95 += V_170 << 9 ;
V_165 -> V_174 . V_67 -= V_170 << 9 ;
V_165 -> V_173 . V_67 = V_170 << 9 ;
V_165 -> V_168 . V_48 = & V_165 -> V_173 ;
V_165 -> V_169 . V_48 = & V_165 -> V_174 ;
V_165 -> V_168 . V_61 = 1 ;
V_165 -> V_169 . V_61 = 1 ;
V_165 -> V_168 . V_151 = F_108 ;
V_165 -> V_169 . V_151 = F_110 ;
V_165 -> V_168 . V_110 = V_162 ;
V_165 -> V_169 . V_110 = V_171 ;
if ( F_23 ( V_162 ) )
F_114 ( V_162 , V_165 , V_170 ) ;
return V_165 ;
}
T_3 F_115 ( struct V_4 * V_4 , unsigned short V_175 ,
unsigned int V_90 )
{
unsigned int V_176 ;
struct V_29 * V_30 ;
T_3 V_177 ;
int V_9 ;
V_176 = F_116 ( V_4 -> V_76 -> V_178 -> V_179 ) ;
V_177 = 0 ;
if ( V_175 >= V_4 -> V_81 )
V_175 = V_4 -> V_79 - 1 ;
F_63 (bv, bio, i, 0 ) {
if ( V_9 == V_175 ) {
if ( V_90 > V_30 -> V_95 )
V_177 += ( V_90 - V_30 -> V_95 ) / V_176 ;
break;
}
V_177 += V_30 -> V_67 / V_176 ;
}
return V_177 ;
}
static int F_117 ( struct V_22 * V_23 , int V_180 )
{
struct V_34 * V_165 = V_27 + V_32 ;
V_23 -> V_33 = F_118 ( V_180 , V_165 -> V_5 ) ;
if ( ! V_23 -> V_33 )
return - V_134 ;
return 0 ;
}
static void F_119 ( struct V_22 * V_23 )
{
F_120 ( V_23 -> V_33 ) ;
}
void F_121 ( struct V_22 * V_23 )
{
if ( V_23 -> V_50 )
F_120 ( V_23 -> V_50 ) ;
F_122 ( V_23 ) ;
F_119 ( V_23 ) ;
F_7 ( V_23 ) ;
F_31 ( V_23 ) ;
}
struct V_22 * F_123 ( unsigned int V_181 , unsigned int V_49 )
{
unsigned int V_182 = V_57 * sizeof( struct V_29 ) ;
struct V_22 * V_23 ;
V_23 = F_124 ( sizeof( * V_23 ) , V_18 ) ;
if ( ! V_23 )
return NULL ;
V_23 -> V_49 = V_49 ;
V_23 -> V_6 = F_1 ( V_49 + V_182 ) ;
if ( ! V_23 -> V_6 ) {
F_31 ( V_23 ) ;
return NULL ;
}
V_23 -> V_50 = F_118 ( V_181 , V_23 -> V_6 ) ;
if ( ! V_23 -> V_50 )
goto V_183;
if ( ! F_117 ( V_23 , V_181 ) )
return V_23 ;
V_183:
F_121 ( V_23 ) ;
return NULL ;
}
int F_125 ( struct V_4 * V_4 )
{
struct V_184 * V_185 ;
struct V_186 * V_187 ;
if ( V_4 -> V_188 )
return - V_189 ;
V_185 = V_190 -> V_184 ;
if ( ! V_185 )
return - V_191 ;
F_126 ( V_185 ) ;
V_4 -> V_188 = V_185 ;
F_127 () ;
V_187 = F_128 ( V_190 , V_192 ) ;
if ( V_187 && F_129 ( V_187 ) )
V_4 -> V_193 = V_187 ;
F_130 () ;
return 0 ;
}
void F_42 ( struct V_4 * V_4 )
{
if ( V_4 -> V_188 ) {
F_131 ( V_4 -> V_188 ) ;
V_4 -> V_188 = NULL ;
}
if ( V_4 -> V_193 ) {
F_132 ( V_4 -> V_193 ) ;
V_4 -> V_193 = NULL ;
}
}
static void T_4 F_133 ( void )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_31 ; V_9 ++ ) {
int V_194 ;
struct V_34 * V_35 = V_27 + V_9 ;
if ( V_35 -> V_28 <= V_57 ) {
V_35 -> V_5 = NULL ;
continue;
}
V_194 = V_35 -> V_28 * sizeof( struct V_29 ) ;
V_35 -> V_5 = F_4 ( V_35 -> V_19 , V_194 , 0 ,
V_20 | V_195 , NULL ) ;
}
}
static int T_4 F_134 ( void )
{
V_17 = 2 ;
V_12 = 0 ;
V_13 = F_124 ( V_17 * sizeof( struct V_6 ) , V_18 ) ;
if ( ! V_13 )
F_135 ( L_4 ) ;
F_136 () ;
F_133 () ;
V_62 = F_123 ( V_196 , 0 ) ;
if ( ! V_62 )
F_135 ( L_4 ) ;
if ( F_137 ( V_62 , V_196 ) )
F_135 ( L_5 ) ;
V_171 = F_138 ( V_197 ,
sizeof( struct V_164 ) ) ;
if ( ! V_171 )
F_135 ( L_6 ) ;
return 0 ;
}
