static struct V_1 * F_1 ( unsigned int V_2 )
{
unsigned int V_3 = sizeof( struct V_4 ) + V_2 ;
struct V_1 * V_5 = NULL ;
struct V_6 * V_7 ;
unsigned int V_8 , V_9 = - 1 ;
F_2 ( & V_10 ) ;
V_8 = 0 ;
while ( V_8 < V_11 ) {
V_7 = & V_12 [ V_8 ] ;
if ( ! V_7 -> V_5 && V_9 == - 1 )
V_9 = V_8 ;
else if ( V_7 -> V_13 == V_3 ) {
V_5 = V_7 -> V_5 ;
V_7 -> V_14 ++ ;
break;
}
V_8 ++ ;
}
if ( V_5 )
goto V_15;
if ( V_11 == V_16 && V_9 == - 1 ) {
V_16 <<= 1 ;
V_12 = F_3 ( V_12 ,
V_16 * sizeof( struct V_6 ) ,
V_17 ) ;
if ( ! V_12 )
goto V_15;
}
if ( V_9 == - 1 )
V_9 = V_11 ++ ;
V_7 = & V_12 [ V_9 ] ;
snprintf ( V_7 -> V_18 , sizeof( V_7 -> V_18 ) , L_1 , V_9 ) ;
V_5 = F_4 ( V_7 -> V_18 , V_3 , 0 , V_19 , NULL ) ;
if ( ! V_5 )
goto V_15;
F_5 ( V_20 L_2 , V_7 -> V_18 , V_9 ) ;
V_7 -> V_5 = V_5 ;
V_7 -> V_14 = 1 ;
V_7 -> V_13 = V_3 ;
V_15:
F_6 ( & V_10 ) ;
return V_5 ;
}
static void F_7 ( struct V_21 * V_22 )
{
struct V_6 * V_7 = NULL ;
unsigned int V_8 ;
F_2 ( & V_10 ) ;
for ( V_8 = 0 ; V_8 < V_11 ; V_8 ++ ) {
if ( V_22 -> V_6 == V_12 [ V_8 ] . V_5 ) {
V_7 = & V_12 [ V_8 ] ;
break;
}
}
if ( F_8 ( ! V_7 , V_23 L_3 ) )
goto V_24;
F_9 ( ! V_7 -> V_14 ) ;
if ( -- V_7 -> V_14 )
goto V_24;
F_10 ( V_7 -> V_5 ) ;
V_7 -> V_5 = NULL ;
V_24:
F_6 ( & V_10 ) ;
}
unsigned int F_11 ( unsigned short V_25 )
{
return V_26 [ V_25 ] . V_27 ;
}
void F_12 ( struct V_21 * V_22 , struct V_28 * V_29 , unsigned int V_25 )
{
F_13 ( V_25 >= V_30 ) ;
if ( V_25 == V_31 )
F_14 ( V_29 , V_22 -> V_32 ) ;
else {
struct V_33 * V_34 = V_26 + V_25 ;
F_15 ( V_34 -> V_5 , V_29 ) ;
}
}
struct V_28 * F_16 ( T_1 V_35 , int V_36 , unsigned long * V_25 ,
struct V_21 * V_22 )
{
struct V_28 * V_37 ;
switch ( V_36 ) {
case 1 :
* V_25 = 0 ;
break;
case 2 ... 4 :
* V_25 = 1 ;
break;
case 5 ... 16 :
* V_25 = 2 ;
break;
case 17 ... 64 :
* V_25 = 3 ;
break;
case 65 ... 128 :
* V_25 = 4 ;
break;
case 129 ... V_38 :
* V_25 = 5 ;
break;
default:
return NULL ;
}
if ( * V_25 == V_31 ) {
V_39:
V_37 = F_17 ( V_22 -> V_32 , V_35 ) ;
} else {
struct V_33 * V_34 = V_26 + * V_25 ;
T_1 V_40 = V_35 & ~ ( V_41 | V_42 ) ;
V_40 |= V_43 | V_44 | V_45 ;
V_37 = F_18 ( V_34 -> V_5 , V_40 ) ;
if ( F_19 ( ! V_37 && ( V_35 & V_41 ) ) ) {
* V_25 = V_31 ;
goto V_39;
}
}
return V_37 ;
}
void F_20 ( struct V_4 * V_4 , struct V_21 * V_22 )
{
void * V_46 ;
if ( F_21 ( V_4 ) )
F_12 ( V_22 , V_4 -> V_47 , F_22 ( V_4 ) ) ;
if ( F_23 ( V_4 ) )
F_24 ( V_4 , V_22 ) ;
V_46 = V_4 ;
if ( V_22 -> V_48 )
V_46 -= V_22 -> V_48 ;
F_14 ( V_46 , V_22 -> V_49 ) ;
}
void F_25 ( struct V_4 * V_4 )
{
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_50 = 1 << V_51 ;
V_4 -> V_52 = - 1 ;
F_26 ( & V_4 -> V_53 , 1 ) ;
}
struct V_4 * F_27 ( T_1 V_35 , int V_54 , struct V_21 * V_22 )
{
unsigned long V_25 = V_55 ;
struct V_28 * V_37 = NULL ;
struct V_4 * V_4 ;
void * V_46 ;
V_46 = F_17 ( V_22 -> V_49 , V_35 ) ;
if ( F_19 ( ! V_46 ) )
return NULL ;
V_4 = V_46 + V_22 -> V_48 ;
F_25 ( V_4 ) ;
if ( F_19 ( ! V_54 ) )
goto V_56;
if ( V_54 <= V_57 ) {
V_37 = V_4 -> V_58 ;
V_54 = V_57 ;
} else {
V_37 = F_16 ( V_35 , V_54 , & V_25 , V_22 ) ;
if ( F_19 ( ! V_37 ) )
goto V_59;
V_54 = F_11 ( V_25 ) ;
}
V_56:
V_4 -> V_50 |= V_25 << V_60 ;
V_4 -> V_61 = V_54 ;
V_4 -> V_47 = V_37 ;
return V_4 ;
V_59:
F_14 ( V_46 , V_22 -> V_49 ) ;
return NULL ;
}
static void F_28 ( struct V_4 * V_4 )
{
F_20 ( V_4 , V_62 ) ;
}
struct V_4 * F_29 ( T_1 V_35 , int V_54 )
{
struct V_4 * V_4 = F_27 ( V_35 , V_54 , V_62 ) ;
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
struct V_4 * F_32 ( T_1 V_35 , int V_54 )
{
struct V_4 * V_4 ;
if ( V_54 > V_64 )
return NULL ;
V_4 = F_33 ( sizeof( struct V_4 ) + V_54 * sizeof( struct V_28 ) ,
V_35 ) ;
if ( F_19 ( ! V_4 ) )
return NULL ;
F_25 ( V_4 ) ;
V_4 -> V_50 |= V_55 << V_60 ;
V_4 -> V_61 = V_54 ;
V_4 -> V_47 = V_4 -> V_58 ;
V_4 -> V_63 = F_30 ;
return V_4 ;
}
void F_34 ( struct V_4 * V_4 )
{
unsigned long V_65 ;
struct V_28 * V_29 ;
int V_8 ;
F_35 (bv, bio, i) {
char * V_66 = F_36 ( V_29 , & V_65 ) ;
memset ( V_66 , 0 , V_29 -> V_67 ) ;
F_37 ( V_29 -> V_68 ) ;
F_38 ( V_66 , & V_65 ) ;
}
}
void F_39 ( struct V_4 * V_4 )
{
F_13 ( ! F_40 ( & V_4 -> V_53 ) ) ;
if ( F_41 ( & V_4 -> V_53 ) ) {
V_4 -> V_69 = NULL ;
V_4 -> V_63 ( V_4 ) ;
}
}
inline int F_42 ( struct V_70 * V_71 , struct V_4 * V_4 )
{
if ( F_19 ( ! F_43 ( V_4 , V_72 ) ) )
F_44 ( V_71 , V_4 ) ;
return V_4 -> V_73 ;
}
void F_45 ( struct V_4 * V_4 , struct V_4 * V_74 )
{
memcpy ( V_4 -> V_47 , V_74 -> V_47 ,
V_74 -> V_61 * sizeof( struct V_28 ) ) ;
V_4 -> V_75 = V_74 -> V_75 ;
V_4 -> V_76 = V_74 -> V_76 ;
V_4 -> V_50 |= 1 << V_77 ;
V_4 -> V_78 = V_74 -> V_78 ;
V_4 -> V_79 = V_74 -> V_79 ;
V_4 -> V_80 = V_74 -> V_80 ;
V_4 -> V_81 = V_74 -> V_81 ;
}
struct V_4 * F_46 ( struct V_4 * V_4 , T_1 V_35 )
{
struct V_4 * V_82 = F_27 ( V_35 , V_4 -> V_61 , V_62 ) ;
if ( ! V_82 )
return NULL ;
V_82 -> V_63 = F_28 ;
F_45 ( V_82 , V_4 ) ;
if ( F_23 ( V_4 ) ) {
int V_83 ;
V_83 = F_47 ( V_82 , V_4 , V_35 , V_62 ) ;
if ( V_83 < 0 ) {
F_39 ( V_82 ) ;
return NULL ;
}
}
return V_82 ;
}
int F_48 ( struct V_84 * V_85 )
{
struct V_70 * V_71 = F_49 ( V_85 ) ;
int V_86 ;
V_86 = ( ( F_50 ( V_71 ) << 9 ) + V_87 - 1 ) >> V_88 ;
if ( V_86 > F_51 ( V_71 ) )
V_86 = F_51 ( V_71 ) ;
return V_86 ;
}
static int F_52 ( struct V_70 * V_71 , struct V_4 * V_4 , struct V_89
* V_89 , unsigned int V_90 , unsigned int V_91 ,
unsigned short V_92 )
{
int V_93 = 0 ;
struct V_28 * V_94 ;
if ( F_19 ( F_43 ( V_4 , V_77 ) ) )
return 0 ;
if ( ( ( V_4 -> V_80 + V_90 ) >> 9 ) > V_92 )
return 0 ;
if ( V_4 -> V_79 > 0 ) {
struct V_28 * V_95 = & V_4 -> V_47 [ V_4 -> V_79 - 1 ] ;
if ( V_89 == V_95 -> V_68 &&
V_91 == V_95 -> V_96 + V_95 -> V_67 ) {
unsigned int V_97 = V_95 -> V_67 ;
V_95 -> V_67 += V_90 ;
if ( V_71 -> V_98 ) {
struct V_99 V_100 = {
. V_76 = V_4 -> V_76 ,
. V_75 = V_4 -> V_75 ,
. V_80 = V_4 -> V_80 - V_97 ,
. V_78 = V_4 -> V_78 ,
} ;
if ( V_71 -> V_98 ( V_71 , & V_100 , V_95 ) < V_95 -> V_67 ) {
V_95 -> V_67 -= V_90 ;
return 0 ;
}
}
goto V_101;
}
}
if ( V_4 -> V_79 >= V_4 -> V_61 )
return 0 ;
while ( V_4 -> V_73 >= F_51 ( V_71 ) ) {
if ( V_93 )
return 0 ;
V_93 = 1 ;
F_44 ( V_71 , V_4 ) ;
}
V_94 = & V_4 -> V_47 [ V_4 -> V_79 ] ;
V_94 -> V_68 = V_89 ;
V_94 -> V_67 = V_90 ;
V_94 -> V_96 = V_91 ;
if ( V_71 -> V_98 ) {
struct V_99 V_100 = {
. V_76 = V_4 -> V_76 ,
. V_75 = V_4 -> V_75 ,
. V_80 = V_4 -> V_80 ,
. V_78 = V_4 -> V_78 ,
} ;
if ( V_71 -> V_98 ( V_71 , & V_100 , V_94 ) < V_94 -> V_67 ) {
V_94 -> V_68 = NULL ;
V_94 -> V_67 = 0 ;
V_94 -> V_96 = 0 ;
return 0 ;
}
}
if ( V_4 -> V_79 && ( F_53 ( V_94 - 1 , V_94 ) ) )
V_4 -> V_50 &= ~ ( 1 << V_72 ) ;
V_4 -> V_79 ++ ;
V_4 -> V_73 ++ ;
V_101:
V_4 -> V_80 += V_90 ;
return V_90 ;
}
int F_54 ( struct V_70 * V_71 , struct V_4 * V_4 , struct V_89 * V_89 ,
unsigned int V_90 , unsigned int V_91 )
{
return F_52 ( V_71 , V_4 , V_89 , V_90 , V_91 ,
F_55 ( V_71 ) ) ;
}
int F_56 ( struct V_4 * V_4 , struct V_89 * V_89 , unsigned int V_90 ,
unsigned int V_91 )
{
struct V_70 * V_71 = F_49 ( V_4 -> V_76 ) ;
return F_52 ( V_71 , V_4 , V_89 , V_90 , V_91 , F_50 ( V_71 ) ) ;
}
static void F_57 ( struct V_102 * V_103 , struct V_4 * V_4 ,
struct V_104 * V_105 , int V_106 ,
int V_107 )
{
memcpy ( V_103 -> V_108 , V_4 -> V_47 , sizeof( struct V_28 ) * V_4 -> V_79 ) ;
memcpy ( V_103 -> V_109 , V_105 , sizeof( struct V_104 ) * V_106 ) ;
V_103 -> V_110 = V_106 ;
V_103 -> V_107 = V_107 ;
V_4 -> V_111 = V_103 ;
}
static void F_58 ( struct V_102 * V_103 )
{
F_31 ( V_103 -> V_108 ) ;
F_31 ( V_103 -> V_109 ) ;
F_31 ( V_103 ) ;
}
static struct V_102 * F_59 ( int V_112 , int V_106 ,
T_1 V_35 )
{
struct V_102 * V_103 ;
if ( V_106 > V_64 )
return NULL ;
V_103 = F_33 ( sizeof( * V_103 ) , V_35 ) ;
if ( ! V_103 )
return NULL ;
V_103 -> V_108 = F_33 ( sizeof( struct V_28 ) * V_112 , V_35 ) ;
if ( ! V_103 -> V_108 ) {
F_31 ( V_103 ) ;
return NULL ;
}
V_103 -> V_109 = F_33 ( sizeof( struct V_104 ) * V_106 , V_35 ) ;
if ( V_103 -> V_109 )
return V_103 ;
F_31 ( V_103 -> V_108 ) ;
F_31 ( V_103 ) ;
return NULL ;
}
static int F_60 ( struct V_4 * V_4 , struct V_28 * V_108 ,
struct V_104 * V_105 , int V_106 ,
int V_113 , int V_114 , int V_115 )
{
int V_83 = 0 , V_8 ;
struct V_28 * V_94 ;
int V_116 = 0 ;
unsigned int V_117 = 0 ;
F_61 (bvec, bio, i, 0 ) {
char * V_118 = F_62 ( V_94 -> V_68 ) ;
unsigned int V_67 = V_108 [ V_8 ] . V_67 ;
while ( V_67 && V_116 < V_106 ) {
unsigned int V_119 ;
char T_2 * V_120 ;
V_119 = F_63 (unsigned int,
iov[iov_idx].iov_len - iov_off, bv_len) ;
V_120 = V_105 [ V_116 ] . V_121 + V_117 ;
if ( ! V_83 ) {
if ( V_113 )
V_83 = F_64 ( V_120 , V_118 ,
V_119 ) ;
if ( V_114 )
V_83 = F_65 ( V_118 , V_120 ,
V_119 ) ;
if ( V_83 )
V_83 = - V_122 ;
}
V_67 -= V_119 ;
V_118 += V_119 ;
V_120 += V_119 ;
V_117 += V_119 ;
if ( V_105 [ V_116 ] . V_123 == V_117 ) {
V_116 ++ ;
V_117 = 0 ;
}
}
if ( V_115 )
F_66 ( V_94 -> V_68 ) ;
}
return V_83 ;
}
int F_67 ( struct V_4 * V_4 )
{
struct V_102 * V_103 = V_4 -> V_111 ;
int V_83 = 0 ;
if ( ! F_43 ( V_4 , V_124 ) )
V_83 = F_60 ( V_4 , V_103 -> V_108 , V_103 -> V_109 ,
V_103 -> V_110 , F_68 ( V_4 ) == V_125 ,
0 , V_103 -> V_107 ) ;
F_58 ( V_103 ) ;
F_39 ( V_4 ) ;
return V_83 ;
}
struct V_4 * F_69 ( struct V_70 * V_71 ,
struct V_126 * V_127 ,
struct V_104 * V_105 , int V_106 ,
int V_128 , T_1 V_35 )
{
struct V_102 * V_103 ;
struct V_28 * V_94 ;
struct V_89 * V_89 ;
struct V_4 * V_4 ;
int V_8 , V_83 ;
int V_86 = 0 ;
unsigned int V_90 = 0 ;
unsigned int V_91 = V_127 ? V_127 -> V_91 & ~ V_129 : 0 ;
for ( V_8 = 0 ; V_8 < V_106 ; V_8 ++ ) {
unsigned long V_130 ;
unsigned long V_131 ;
unsigned long V_132 ;
V_130 = ( unsigned long ) V_105 [ V_8 ] . V_121 ;
V_131 = ( V_130 + V_105 [ V_8 ] . V_123 + V_87 - 1 ) >> V_88 ;
V_132 = V_130 >> V_88 ;
if ( V_131 < V_132 )
return F_70 ( - V_133 ) ;
V_86 += V_131 - V_132 ;
V_90 += V_105 [ V_8 ] . V_123 ;
}
if ( V_91 )
V_86 ++ ;
V_103 = F_59 ( V_86 , V_106 , V_35 ) ;
if ( ! V_103 )
return F_70 ( - V_134 ) ;
V_83 = - V_134 ;
V_4 = F_32 ( V_35 , V_86 ) ;
if ( ! V_4 )
goto V_135;
if ( ! V_128 )
V_4 -> V_78 |= V_136 ;
V_83 = 0 ;
if ( V_127 ) {
V_86 = 1 << V_127 -> V_137 ;
V_8 = V_127 -> V_91 / V_87 ;
}
while ( V_90 ) {
unsigned int V_119 = V_87 ;
V_119 -= V_91 ;
if ( V_119 > V_90 )
V_119 = V_90 ;
if ( V_127 ) {
if ( V_8 == V_127 -> V_138 * V_86 ) {
V_83 = - V_134 ;
break;
}
V_89 = V_127 -> V_139 [ V_8 / V_86 ] ;
V_89 += ( V_8 % V_86 ) ;
V_8 ++ ;
} else {
V_89 = F_71 ( V_71 -> V_140 | V_35 ) ;
if ( ! V_89 ) {
V_83 = - V_134 ;
break;
}
}
if ( F_54 ( V_71 , V_4 , V_89 , V_119 , V_91 ) < V_119 )
break;
V_90 -= V_119 ;
V_91 = 0 ;
}
if ( V_83 )
goto V_141;
if ( ( ! V_128 && ( ! V_127 || ! V_127 -> V_142 ) ) ||
( V_127 && V_127 -> V_114 ) ) {
V_83 = F_60 ( V_4 , V_4 -> V_47 , V_105 , V_106 , 0 , 1 , 0 ) ;
if ( V_83 )
goto V_141;
}
F_57 ( V_103 , V_4 , V_105 , V_106 , V_127 ? 0 : 1 ) ;
return V_4 ;
V_141:
if ( ! V_127 )
F_35 (bvec, bio, i)
F_66 ( V_94 -> V_68 ) ;
F_39 ( V_4 ) ;
V_135:
F_58 ( V_103 ) ;
return F_70 ( V_83 ) ;
}
struct V_4 * F_72 ( struct V_70 * V_71 , struct V_126 * V_127 ,
unsigned long V_130 , unsigned int V_90 ,
int V_128 , T_1 V_35 )
{
struct V_104 V_105 ;
V_105 . V_121 = ( void T_2 * ) V_130 ;
V_105 . V_123 = V_90 ;
return F_69 ( V_71 , V_127 , & V_105 , 1 , V_128 , V_35 ) ;
}
static struct V_4 * F_73 ( struct V_70 * V_71 ,
struct V_84 * V_85 ,
struct V_104 * V_105 , int V_106 ,
int V_128 , T_1 V_35 )
{
int V_8 , V_143 ;
int V_86 = 0 ;
struct V_89 * * V_139 ;
struct V_4 * V_4 ;
int V_144 = 0 ;
int V_83 , V_91 ;
for ( V_8 = 0 ; V_8 < V_106 ; V_8 ++ ) {
unsigned long V_130 = ( unsigned long ) V_105 [ V_8 ] . V_121 ;
unsigned long V_90 = V_105 [ V_8 ] . V_123 ;
unsigned long V_131 = ( V_130 + V_90 + V_87 - 1 ) >> V_88 ;
unsigned long V_132 = V_130 >> V_88 ;
if ( V_131 < V_132 )
return F_70 ( - V_133 ) ;
V_86 += V_131 - V_132 ;
if ( V_130 & F_74 ( V_71 ) )
return F_70 ( - V_133 ) ;
}
if ( ! V_86 )
return F_70 ( - V_133 ) ;
V_4 = F_32 ( V_35 , V_86 ) ;
if ( ! V_4 )
return F_70 ( - V_134 ) ;
V_83 = - V_134 ;
V_139 = F_75 ( V_86 , sizeof( struct V_89 * ) , V_35 ) ;
if ( ! V_139 )
goto V_24;
for ( V_8 = 0 ; V_8 < V_106 ; V_8 ++ ) {
unsigned long V_130 = ( unsigned long ) V_105 [ V_8 ] . V_121 ;
unsigned long V_90 = V_105 [ V_8 ] . V_123 ;
unsigned long V_131 = ( V_130 + V_90 + V_87 - 1 ) >> V_88 ;
unsigned long V_132 = V_130 >> V_88 ;
const int V_145 = V_131 - V_132 ;
const int V_146 = V_144 + V_145 ;
V_83 = F_76 ( V_130 , V_145 ,
V_128 , & V_139 [ V_144 ] ) ;
if ( V_83 < V_145 ) {
V_83 = - V_122 ;
goto V_147;
}
V_91 = V_130 & ~ V_129 ;
for ( V_143 = V_144 ; V_143 < V_146 ; V_143 ++ ) {
unsigned int V_119 = V_87 - V_91 ;
if ( V_90 <= 0 )
break;
if ( V_119 > V_90 )
V_119 = V_90 ;
if ( F_54 ( V_71 , V_4 , V_139 [ V_143 ] , V_119 , V_91 ) <
V_119 )
break;
V_90 -= V_119 ;
V_91 = 0 ;
}
V_144 = V_143 ;
while ( V_143 < V_146 )
F_77 ( V_139 [ V_143 ++ ] ) ;
}
F_31 ( V_139 ) ;
if ( ! V_128 )
V_4 -> V_78 |= V_136 ;
V_4 -> V_76 = V_85 ;
V_4 -> V_50 |= ( 1 << V_148 ) ;
return V_4 ;
V_147:
for ( V_8 = 0 ; V_8 < V_86 ; V_8 ++ ) {
if( ! V_139 [ V_8 ] )
break;
F_77 ( V_139 [ V_8 ] ) ;
}
V_24:
F_31 ( V_139 ) ;
F_39 ( V_4 ) ;
return F_70 ( V_83 ) ;
}
struct V_4 * F_78 ( struct V_70 * V_71 , struct V_84 * V_85 ,
unsigned long V_130 , unsigned int V_90 , int V_128 ,
T_1 V_35 )
{
struct V_104 V_105 ;
V_105 . V_121 = ( void T_2 * ) V_130 ;
V_105 . V_123 = V_90 ;
return F_79 ( V_71 , V_85 , & V_105 , 1 , V_128 , V_35 ) ;
}
struct V_4 * F_79 ( struct V_70 * V_71 , struct V_84 * V_85 ,
struct V_104 * V_105 , int V_106 ,
int V_128 , T_1 V_35 )
{
struct V_4 * V_4 ;
V_4 = F_73 ( V_71 , V_85 , V_105 , V_106 , V_128 ,
V_35 ) ;
if ( F_80 ( V_4 ) )
return V_4 ;
F_81 ( V_4 ) ;
return V_4 ;
}
static void F_82 ( struct V_4 * V_4 )
{
struct V_28 * V_94 ;
int V_8 ;
F_61 (bvec, bio, i, 0 ) {
if ( F_68 ( V_4 ) == V_125 )
F_83 ( V_94 -> V_68 ) ;
F_77 ( V_94 -> V_68 ) ;
}
F_39 ( V_4 ) ;
}
void F_84 ( struct V_4 * V_4 )
{
F_82 ( V_4 ) ;
F_39 ( V_4 ) ;
}
static void F_85 ( struct V_4 * V_4 , int V_149 )
{
F_39 ( V_4 ) ;
}
static struct V_4 * F_86 ( struct V_70 * V_71 , void * V_66 ,
unsigned int V_90 , T_1 V_35 )
{
unsigned long V_150 = ( unsigned long ) V_66 ;
unsigned long V_131 = ( V_150 + V_90 + V_87 - 1 ) >> V_88 ;
unsigned long V_132 = V_150 >> V_88 ;
const int V_86 = V_131 - V_132 ;
int V_91 , V_8 ;
struct V_4 * V_4 ;
V_4 = F_32 ( V_35 , V_86 ) ;
if ( ! V_4 )
return F_70 ( - V_134 ) ;
V_91 = F_87 ( V_150 ) ;
for ( V_8 = 0 ; V_8 < V_86 ; V_8 ++ ) {
unsigned int V_119 = V_87 - V_91 ;
if ( V_90 <= 0 )
break;
if ( V_119 > V_90 )
V_119 = V_90 ;
if ( F_54 ( V_71 , V_4 , F_88 ( V_66 ) , V_119 ,
V_91 ) < V_119 )
break;
V_66 += V_119 ;
V_90 -= V_119 ;
V_91 = 0 ;
}
V_4 -> V_151 = F_85 ;
return V_4 ;
}
struct V_4 * F_89 ( struct V_70 * V_71 , void * V_66 , unsigned int V_90 ,
T_1 V_35 )
{
struct V_4 * V_4 ;
V_4 = F_86 ( V_71 , V_66 , V_90 , V_35 ) ;
if ( F_80 ( V_4 ) )
return V_4 ;
if ( V_4 -> V_80 == V_90 )
return V_4 ;
F_39 ( V_4 ) ;
return F_70 ( - V_133 ) ;
}
static void F_90 ( struct V_4 * V_4 , int V_149 )
{
struct V_28 * V_94 ;
const int V_152 = F_68 ( V_4 ) == V_125 ;
struct V_102 * V_103 = V_4 -> V_111 ;
int V_8 ;
char * V_46 = V_103 -> V_109 [ 0 ] . V_121 ;
F_61 (bvec, bio, i, 0 ) {
char * V_153 = F_62 ( V_94 -> V_68 ) ;
int V_90 = V_103 -> V_108 [ V_8 ] . V_67 ;
if ( V_152 )
memcpy ( V_46 , V_153 , V_90 ) ;
F_66 ( V_94 -> V_68 ) ;
V_46 += V_90 ;
}
F_58 ( V_103 ) ;
F_39 ( V_4 ) ;
}
struct V_4 * F_91 ( struct V_70 * V_71 , void * V_66 , unsigned int V_90 ,
T_1 V_35 , int V_154 )
{
struct V_4 * V_4 ;
struct V_28 * V_94 ;
int V_8 ;
V_4 = F_72 ( V_71 , NULL , ( unsigned long ) V_66 , V_90 , 1 , V_35 ) ;
if ( F_80 ( V_4 ) )
return V_4 ;
if ( ! V_154 ) {
void * V_46 = V_66 ;
F_35 (bvec, bio, i) {
char * V_153 = F_62 ( V_94 -> V_68 ) ;
memcpy ( V_153 , V_46 , V_94 -> V_67 ) ;
V_46 += V_94 -> V_67 ;
}
}
V_4 -> V_151 = F_90 ;
return V_4 ;
}
void F_92 ( struct V_4 * V_4 )
{
struct V_28 * V_94 = V_4 -> V_47 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_4 -> V_79 ; V_8 ++ ) {
struct V_89 * V_89 = V_94 [ V_8 ] . V_68 ;
if ( V_89 && ! F_93 ( V_89 ) )
F_83 ( V_89 ) ;
}
}
static void F_94 ( struct V_4 * V_4 )
{
struct V_28 * V_94 = V_4 -> V_47 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_4 -> V_79 ; V_8 ++ ) {
struct V_89 * V_89 = V_94 [ V_8 ] . V_68 ;
if ( V_89 )
F_95 ( V_89 ) ;
}
}
static void F_96 ( struct V_155 * V_156 )
{
unsigned long V_65 ;
struct V_4 * V_4 ;
F_97 ( & V_157 , V_65 ) ;
V_4 = V_158 ;
V_158 = NULL ;
F_98 ( & V_157 , V_65 ) ;
while ( V_4 ) {
struct V_4 * V_159 = V_4 -> V_111 ;
F_92 ( V_4 ) ;
F_94 ( V_4 ) ;
F_39 ( V_4 ) ;
V_4 = V_159 ;
}
}
void F_99 ( struct V_4 * V_4 )
{
struct V_28 * V_94 = V_4 -> V_47 ;
int V_160 = 0 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_4 -> V_79 ; V_8 ++ ) {
struct V_89 * V_89 = V_94 [ V_8 ] . V_68 ;
if ( F_100 ( V_89 ) || F_93 ( V_89 ) ) {
F_77 ( V_89 ) ;
V_94 [ V_8 ] . V_68 = NULL ;
} else {
V_160 ++ ;
}
}
if ( V_160 ) {
unsigned long V_65 ;
F_97 ( & V_157 , V_65 ) ;
V_4 -> V_111 = V_158 ;
V_158 = V_4 ;
F_98 ( & V_157 , V_65 ) ;
F_101 ( & V_161 ) ;
} else {
F_39 ( V_4 ) ;
}
}
void F_102 ( struct V_4 * V_162 )
{
int V_8 ;
struct V_28 * V_94 ;
F_35 (bvec, bi, i)
F_37 ( V_94 -> V_68 ) ;
}
void F_103 ( struct V_4 * V_4 , int error )
{
if ( error )
F_104 ( V_51 , & V_4 -> V_50 ) ;
else if ( ! F_105 ( V_51 , & V_4 -> V_50 ) )
error = - V_163 ;
if ( V_4 -> V_151 )
V_4 -> V_151 ( V_4 , error ) ;
}
void F_106 ( struct V_164 * V_165 )
{
if ( F_41 ( & V_165 -> V_166 ) ) {
struct V_4 * V_167 = V_165 -> V_168 . V_111 ;
F_103 ( V_167 , V_165 -> error ) ;
F_14 ( V_165 , V_165 -> V_169 . V_111 ) ;
}
}
static void F_107 ( struct V_4 * V_162 , int V_149 )
{
struct V_164 * V_165 = F_108 ( V_162 , struct V_164 , V_168 ) ;
if ( V_149 )
V_165 -> error = V_149 ;
F_106 ( V_165 ) ;
}
static void F_109 ( struct V_4 * V_162 , int V_149 )
{
struct V_164 * V_165 = F_108 ( V_162 , struct V_164 , V_169 ) ;
if ( V_149 )
V_165 -> error = V_149 ;
F_106 ( V_165 ) ;
}
struct V_164 * F_110 ( struct V_4 * V_162 , int V_170 )
{
struct V_164 * V_165 = F_17 ( V_171 , V_172 ) ;
if ( ! V_165 )
return V_165 ;
F_111 ( F_49 ( V_162 -> V_76 ) , V_162 ,
V_162 -> V_75 + V_170 ) ;
F_112 ( V_162 -> V_79 != 1 ) ;
F_112 ( V_162 -> V_81 != 0 ) ;
F_26 ( & V_165 -> V_166 , 3 ) ;
V_165 -> error = 0 ;
V_165 -> V_168 = * V_162 ;
V_165 -> V_169 = * V_162 ;
V_165 -> V_169 . V_75 += V_170 ;
V_165 -> V_169 . V_80 -= V_170 << 9 ;
V_165 -> V_168 . V_80 = V_170 << 9 ;
V_165 -> V_173 = V_162 -> V_47 [ 0 ] ;
V_165 -> V_174 = V_162 -> V_47 [ 0 ] ;
V_165 -> V_174 . V_96 += V_170 << 9 ;
V_165 -> V_174 . V_67 -= V_170 << 9 ;
V_165 -> V_173 . V_67 = V_170 << 9 ;
V_165 -> V_168 . V_47 = & V_165 -> V_173 ;
V_165 -> V_169 . V_47 = & V_165 -> V_174 ;
V_165 -> V_168 . V_61 = 1 ;
V_165 -> V_169 . V_61 = 1 ;
V_165 -> V_168 . V_151 = F_107 ;
V_165 -> V_169 . V_151 = F_109 ;
V_165 -> V_168 . V_111 = V_162 ;
V_165 -> V_169 . V_111 = V_171 ;
if ( F_23 ( V_162 ) )
F_113 ( V_162 , V_165 , V_170 ) ;
return V_165 ;
}
T_3 F_114 ( struct V_4 * V_4 , unsigned short V_175 ,
unsigned int V_91 )
{
unsigned int V_176 ;
struct V_28 * V_29 ;
T_3 V_177 ;
int V_8 ;
V_176 = F_115 ( V_4 -> V_76 -> V_178 -> V_179 ) ;
V_177 = 0 ;
if ( V_175 >= V_4 -> V_81 )
V_175 = V_4 -> V_79 - 1 ;
F_61 (bv, bio, i, 0 ) {
if ( V_8 == V_175 ) {
if ( V_91 > V_29 -> V_96 )
V_177 += ( V_91 - V_29 -> V_96 ) / V_176 ;
break;
}
V_177 += V_29 -> V_67 / V_176 ;
}
return V_177 ;
}
static int F_116 ( struct V_21 * V_22 , int V_180 )
{
struct V_33 * V_165 = V_26 + V_31 ;
V_22 -> V_32 = F_117 ( V_180 , V_165 -> V_5 ) ;
if ( ! V_22 -> V_32 )
return - V_134 ;
return 0 ;
}
static void F_118 ( struct V_21 * V_22 )
{
F_119 ( V_22 -> V_32 ) ;
}
void F_120 ( struct V_21 * V_22 )
{
if ( V_22 -> V_49 )
F_119 ( V_22 -> V_49 ) ;
F_121 ( V_22 ) ;
F_118 ( V_22 ) ;
F_7 ( V_22 ) ;
F_31 ( V_22 ) ;
}
struct V_21 * F_122 ( unsigned int V_181 , unsigned int V_48 )
{
unsigned int V_182 = V_57 * sizeof( struct V_28 ) ;
struct V_21 * V_22 ;
V_22 = F_123 ( sizeof( * V_22 ) , V_17 ) ;
if ( ! V_22 )
return NULL ;
V_22 -> V_48 = V_48 ;
V_22 -> V_6 = F_1 ( V_48 + V_182 ) ;
if ( ! V_22 -> V_6 ) {
F_31 ( V_22 ) ;
return NULL ;
}
V_22 -> V_49 = F_117 ( V_181 , V_22 -> V_6 ) ;
if ( ! V_22 -> V_49 )
goto V_183;
if ( ! F_116 ( V_22 , V_181 ) )
return V_22 ;
V_183:
F_120 ( V_22 ) ;
return NULL ;
}
static void T_4 F_124 ( void )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_30 ; V_8 ++ ) {
int V_184 ;
struct V_33 * V_34 = V_26 + V_8 ;
if ( V_34 -> V_27 <= V_57 ) {
V_34 -> V_5 = NULL ;
continue;
}
V_184 = V_34 -> V_27 * sizeof( struct V_28 ) ;
V_34 -> V_5 = F_4 ( V_34 -> V_18 , V_184 , 0 ,
V_19 | V_185 , NULL ) ;
}
}
static int T_4 F_125 ( void )
{
V_16 = 2 ;
V_11 = 0 ;
V_12 = F_123 ( V_16 * sizeof( struct V_6 ) , V_17 ) ;
if ( ! V_12 )
F_126 ( L_4 ) ;
F_127 () ;
F_124 () ;
V_62 = F_122 ( V_186 , 0 ) ;
if ( ! V_62 )
F_126 ( L_4 ) ;
if ( F_128 ( V_62 , V_186 ) )
F_126 ( L_5 ) ;
V_171 = F_129 ( V_187 ,
sizeof( struct V_164 ) ) ;
if ( ! V_171 )
F_126 ( L_6 ) ;
return 0 ;
}
