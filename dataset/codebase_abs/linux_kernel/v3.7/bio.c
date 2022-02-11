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
void F_12 ( struct V_23 * V_24 , struct V_30 * V_31 , unsigned int V_27 )
{
F_13 ( V_27 >= V_32 ) ;
if ( V_27 == V_33 )
F_14 ( V_31 , V_24 -> V_34 ) ;
else {
struct V_35 * V_36 = V_28 + V_27 ;
F_15 ( V_36 -> V_5 , V_31 ) ;
}
}
struct V_30 * F_16 ( T_1 V_37 , int V_38 , unsigned long * V_27 ,
struct V_23 * V_24 )
{
struct V_30 * V_39 ;
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
if ( * V_27 == V_33 ) {
V_41:
V_39 = F_17 ( V_24 -> V_34 , V_37 ) ;
} else {
struct V_35 * V_36 = V_28 + * V_27 ;
T_1 V_42 = V_37 & ~ ( V_43 | V_44 ) ;
V_42 |= V_45 | V_46 | V_47 ;
V_39 = F_18 ( V_36 -> V_5 , V_42 ) ;
if ( F_19 ( ! V_39 && ( V_37 & V_43 ) ) ) {
* V_27 = V_33 ;
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
if ( F_25 ( V_4 ) )
F_12 ( V_24 , V_4 -> V_50 , F_26 ( V_4 ) ) ;
V_49 = V_4 ;
V_49 -= V_24 -> V_51 ;
F_14 ( V_49 , V_24 -> V_52 ) ;
} else {
F_27 ( V_4 ) ;
}
}
void F_28 ( struct V_4 * V_4 )
{
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_53 = 1 << V_54 ;
F_29 ( & V_4 -> V_55 , 1 ) ;
}
void F_30 ( struct V_4 * V_4 )
{
unsigned long V_56 = V_4 -> V_53 & ( ~ 0UL << V_57 ) ;
F_20 ( V_4 ) ;
memset ( V_4 , 0 , V_58 ) ;
V_4 -> V_53 = V_56 | ( 1 << V_54 ) ;
}
struct V_4 * F_31 ( T_1 V_37 , int V_59 , struct V_23 * V_24 )
{
unsigned V_51 ;
unsigned V_60 ;
unsigned long V_27 = V_61 ;
struct V_30 * V_39 = NULL ;
struct V_4 * V_4 ;
void * V_49 ;
if ( ! V_24 ) {
if ( V_59 > V_62 )
return NULL ;
V_49 = F_32 ( sizeof( struct V_4 ) +
V_59 * sizeof( struct V_30 ) ,
V_37 ) ;
V_51 = 0 ;
V_60 = V_59 ;
} else {
V_49 = F_17 ( V_24 -> V_52 , V_37 ) ;
V_51 = V_24 -> V_51 ;
V_60 = V_63 ;
}
if ( F_19 ( ! V_49 ) )
return NULL ;
V_4 = V_49 + V_51 ;
F_28 ( V_4 ) ;
if ( V_59 > V_60 ) {
V_39 = F_16 ( V_37 , V_59 , & V_27 , V_24 ) ;
if ( F_19 ( ! V_39 ) )
goto V_64;
} else if ( V_59 ) {
V_39 = V_4 -> V_65 ;
}
V_4 -> V_48 = V_24 ;
V_4 -> V_53 |= V_27 << V_66 ;
V_4 -> V_67 = V_59 ;
V_4 -> V_50 = V_39 ;
return V_4 ;
V_64:
F_14 ( V_49 , V_24 -> V_52 ) ;
return NULL ;
}
void F_33 ( struct V_4 * V_4 )
{
unsigned long V_56 ;
struct V_30 * V_31 ;
int V_10 ;
F_34 (bv, bio, i) {
char * V_68 = F_35 ( V_31 , & V_56 ) ;
memset ( V_68 , 0 , V_31 -> V_69 ) ;
F_36 ( V_31 -> V_70 ) ;
F_37 ( V_68 , & V_56 ) ;
}
}
void F_38 ( struct V_4 * V_4 )
{
F_13 ( ! F_39 ( & V_4 -> V_55 ) ) ;
if ( F_40 ( & V_4 -> V_55 ) )
F_24 ( V_4 ) ;
}
inline int F_41 ( struct V_71 * V_72 , struct V_4 * V_4 )
{
if ( F_19 ( ! F_42 ( V_4 , V_73 ) ) )
F_43 ( V_72 , V_4 ) ;
return V_4 -> V_74 ;
}
void F_44 ( struct V_4 * V_4 , struct V_4 * V_75 )
{
memcpy ( V_4 -> V_50 , V_75 -> V_50 ,
V_75 -> V_67 * sizeof( struct V_30 ) ) ;
V_4 -> V_76 = V_75 -> V_76 ;
V_4 -> V_77 = V_75 -> V_77 ;
V_4 -> V_53 |= 1 << V_78 ;
V_4 -> V_79 = V_75 -> V_79 ;
V_4 -> V_80 = V_75 -> V_80 ;
V_4 -> V_81 = V_75 -> V_81 ;
V_4 -> V_82 = V_75 -> V_82 ;
}
struct V_4 * F_45 ( struct V_4 * V_4 , T_1 V_37 ,
struct V_23 * V_24 )
{
struct V_4 * V_83 ;
V_83 = F_31 ( V_37 , V_4 -> V_67 , V_24 ) ;
if ( ! V_83 )
return NULL ;
F_44 ( V_83 , V_4 ) ;
if ( F_22 ( V_4 ) ) {
int V_84 ;
V_84 = F_46 ( V_83 , V_4 , V_37 ) ;
if ( V_84 < 0 ) {
F_38 ( V_83 ) ;
return NULL ;
}
}
return V_83 ;
}
int F_47 ( struct V_85 * V_86 )
{
struct V_71 * V_72 = F_48 ( V_86 ) ;
int V_87 ;
V_87 = F_49 ( unsigned ,
F_50 ( V_72 ) ,
F_51 ( V_72 ) / ( V_88 >> 9 ) + 1 ) ;
return F_49 ( unsigned , V_87 , V_40 ) ;
}
static int F_52 ( struct V_71 * V_72 , struct V_4 * V_4 , struct V_89
* V_89 , unsigned int V_90 , unsigned int V_91 ,
unsigned short V_92 )
{
int V_93 = 0 ;
struct V_30 * V_94 ;
if ( F_19 ( F_42 ( V_4 , V_78 ) ) )
return 0 ;
if ( ( ( V_4 -> V_81 + V_90 ) >> 9 ) > V_92 )
return 0 ;
if ( V_4 -> V_80 > 0 ) {
struct V_30 * V_95 = & V_4 -> V_50 [ V_4 -> V_80 - 1 ] ;
if ( V_89 == V_95 -> V_70 &&
V_91 == V_95 -> V_96 + V_95 -> V_69 ) {
unsigned int V_97 = V_95 -> V_69 ;
V_95 -> V_69 += V_90 ;
if ( V_72 -> V_98 ) {
struct V_99 V_100 = {
. V_77 = V_4 -> V_77 ,
. V_76 = V_4 -> V_76 ,
. V_81 = V_4 -> V_81 - V_97 ,
. V_79 = V_4 -> V_79 ,
} ;
if ( V_72 -> V_98 ( V_72 , & V_100 , V_95 ) < V_95 -> V_69 ) {
V_95 -> V_69 -= V_90 ;
return 0 ;
}
}
goto V_101;
}
}
if ( V_4 -> V_80 >= V_4 -> V_67 )
return 0 ;
while ( V_4 -> V_74 >= F_50 ( V_72 ) ) {
if ( V_93 )
return 0 ;
V_93 = 1 ;
F_43 ( V_72 , V_4 ) ;
}
V_94 = & V_4 -> V_50 [ V_4 -> V_80 ] ;
V_94 -> V_70 = V_89 ;
V_94 -> V_69 = V_90 ;
V_94 -> V_96 = V_91 ;
if ( V_72 -> V_98 ) {
struct V_99 V_100 = {
. V_77 = V_4 -> V_77 ,
. V_76 = V_4 -> V_76 ,
. V_81 = V_4 -> V_81 ,
. V_79 = V_4 -> V_79 ,
} ;
if ( V_72 -> V_98 ( V_72 , & V_100 , V_94 ) < V_94 -> V_69 ) {
V_94 -> V_70 = NULL ;
V_94 -> V_69 = 0 ;
V_94 -> V_96 = 0 ;
return 0 ;
}
}
if ( V_4 -> V_80 && ( F_53 ( V_94 - 1 , V_94 ) ) )
V_4 -> V_53 &= ~ ( 1 << V_73 ) ;
V_4 -> V_80 ++ ;
V_4 -> V_74 ++ ;
V_101:
V_4 -> V_81 += V_90 ;
return V_90 ;
}
int F_54 ( struct V_71 * V_72 , struct V_4 * V_4 , struct V_89 * V_89 ,
unsigned int V_90 , unsigned int V_91 )
{
return F_52 ( V_72 , V_4 , V_89 , V_90 , V_91 ,
F_55 ( V_72 ) ) ;
}
int F_56 ( struct V_4 * V_4 , struct V_89 * V_89 , unsigned int V_90 ,
unsigned int V_91 )
{
struct V_71 * V_72 = F_48 ( V_4 -> V_77 ) ;
return F_52 ( V_72 , V_4 , V_89 , V_90 , V_91 , F_51 ( V_72 ) ) ;
}
static void F_57 ( struct V_102 * V_103 , struct V_4 * V_4 ,
struct V_104 * V_105 , int V_106 ,
int V_107 )
{
memcpy ( V_103 -> V_108 , V_4 -> V_50 , sizeof( struct V_30 ) * V_4 -> V_80 ) ;
memcpy ( V_103 -> V_109 , V_105 , sizeof( struct V_104 ) * V_106 ) ;
V_103 -> V_110 = V_106 ;
V_103 -> V_107 = V_107 ;
V_4 -> V_111 = V_103 ;
}
static void F_58 ( struct V_102 * V_103 )
{
F_27 ( V_103 -> V_108 ) ;
F_27 ( V_103 -> V_109 ) ;
F_27 ( V_103 ) ;
}
static struct V_102 * F_59 ( int V_112 ,
unsigned int V_106 ,
T_1 V_37 )
{
struct V_102 * V_103 ;
if ( V_106 > V_62 )
return NULL ;
V_103 = F_32 ( sizeof( * V_103 ) , V_37 ) ;
if ( ! V_103 )
return NULL ;
V_103 -> V_108 = F_32 ( sizeof( struct V_30 ) * V_112 , V_37 ) ;
if ( ! V_103 -> V_108 ) {
F_27 ( V_103 ) ;
return NULL ;
}
V_103 -> V_109 = F_32 ( sizeof( struct V_104 ) * V_106 , V_37 ) ;
if ( V_103 -> V_109 )
return V_103 ;
F_27 ( V_103 -> V_108 ) ;
F_27 ( V_103 ) ;
return NULL ;
}
static int F_60 ( struct V_4 * V_4 , struct V_30 * V_108 ,
struct V_104 * V_105 , int V_106 ,
int V_113 , int V_114 , int V_115 )
{
int V_84 = 0 , V_10 ;
struct V_30 * V_94 ;
int V_116 = 0 ;
unsigned int V_117 = 0 ;
F_61 (bvec, bio, i, 0 ) {
char * V_118 = F_62 ( V_94 -> V_70 ) ;
unsigned int V_69 = V_108 [ V_10 ] . V_69 ;
while ( V_69 && V_116 < V_106 ) {
unsigned int V_119 ;
char T_2 * V_120 ;
V_119 = F_49 (unsigned int,
iov[iov_idx].iov_len - iov_off, bv_len) ;
V_120 = V_105 [ V_116 ] . V_121 + V_117 ;
if ( ! V_84 ) {
if ( V_113 )
V_84 = F_63 ( V_120 , V_118 ,
V_119 ) ;
if ( V_114 )
V_84 = F_64 ( V_118 , V_120 ,
V_119 ) ;
if ( V_84 )
V_84 = - V_122 ;
}
V_69 -= V_119 ;
V_118 += V_119 ;
V_120 += V_119 ;
V_117 += V_119 ;
if ( V_105 [ V_116 ] . V_123 == V_117 ) {
V_116 ++ ;
V_117 = 0 ;
}
}
if ( V_115 )
F_65 ( V_94 -> V_70 ) ;
}
return V_84 ;
}
int F_66 ( struct V_4 * V_4 )
{
struct V_102 * V_103 = V_4 -> V_111 ;
int V_84 = 0 ;
if ( ! F_42 ( V_4 , V_124 ) )
V_84 = F_60 ( V_4 , V_103 -> V_108 , V_103 -> V_109 ,
V_103 -> V_110 , F_67 ( V_4 ) == V_125 ,
0 , V_103 -> V_107 ) ;
F_58 ( V_103 ) ;
F_38 ( V_4 ) ;
return V_84 ;
}
struct V_4 * F_68 ( struct V_71 * V_72 ,
struct V_126 * V_127 ,
struct V_104 * V_105 , int V_106 ,
int V_128 , T_1 V_37 )
{
struct V_102 * V_103 ;
struct V_30 * V_94 ;
struct V_89 * V_89 ;
struct V_4 * V_4 ;
int V_10 , V_84 ;
int V_87 = 0 ;
unsigned int V_90 = 0 ;
unsigned int V_91 = V_127 ? V_127 -> V_91 & ~ V_129 : 0 ;
for ( V_10 = 0 ; V_10 < V_106 ; V_10 ++ ) {
unsigned long V_130 ;
unsigned long V_131 ;
unsigned long V_132 ;
V_130 = ( unsigned long ) V_105 [ V_10 ] . V_121 ;
V_131 = ( V_130 + V_105 [ V_10 ] . V_123 + V_88 - 1 ) >> V_133 ;
V_132 = V_130 >> V_133 ;
if ( V_131 < V_132 )
return F_69 ( - V_134 ) ;
V_87 += V_131 - V_132 ;
V_90 += V_105 [ V_10 ] . V_123 ;
}
if ( V_91 )
V_87 ++ ;
V_103 = F_59 ( V_87 , V_106 , V_37 ) ;
if ( ! V_103 )
return F_69 ( - V_135 ) ;
V_84 = - V_135 ;
V_4 = F_70 ( V_37 , V_87 ) ;
if ( ! V_4 )
goto V_136;
if ( ! V_128 )
V_4 -> V_79 |= V_137 ;
V_84 = 0 ;
if ( V_127 ) {
V_87 = 1 << V_127 -> V_138 ;
V_10 = V_127 -> V_91 / V_88 ;
}
while ( V_90 ) {
unsigned int V_119 = V_88 ;
V_119 -= V_91 ;
if ( V_119 > V_90 )
V_119 = V_90 ;
if ( V_127 ) {
if ( V_10 == V_127 -> V_139 * V_87 ) {
V_84 = - V_135 ;
break;
}
V_89 = V_127 -> V_140 [ V_10 / V_87 ] ;
V_89 += ( V_10 % V_87 ) ;
V_10 ++ ;
} else {
V_89 = F_71 ( V_72 -> V_141 | V_37 ) ;
if ( ! V_89 ) {
V_84 = - V_135 ;
break;
}
}
if ( F_54 ( V_72 , V_4 , V_89 , V_119 , V_91 ) < V_119 )
break;
V_90 -= V_119 ;
V_91 = 0 ;
}
if ( V_84 )
goto V_142;
if ( ( ! V_128 && ( ! V_127 || ! V_127 -> V_143 ) ) ||
( V_127 && V_127 -> V_114 ) ) {
V_84 = F_60 ( V_4 , V_4 -> V_50 , V_105 , V_106 , 0 , 1 , 0 ) ;
if ( V_84 )
goto V_142;
}
F_57 ( V_103 , V_4 , V_105 , V_106 , V_127 ? 0 : 1 ) ;
return V_4 ;
V_142:
if ( ! V_127 )
F_34 (bvec, bio, i)
F_65 ( V_94 -> V_70 ) ;
F_38 ( V_4 ) ;
V_136:
F_58 ( V_103 ) ;
return F_69 ( V_84 ) ;
}
struct V_4 * F_72 ( struct V_71 * V_72 , struct V_126 * V_127 ,
unsigned long V_130 , unsigned int V_90 ,
int V_128 , T_1 V_37 )
{
struct V_104 V_105 ;
V_105 . V_121 = ( void T_2 * ) V_130 ;
V_105 . V_123 = V_90 ;
return F_68 ( V_72 , V_127 , & V_105 , 1 , V_128 , V_37 ) ;
}
static struct V_4 * F_73 ( struct V_71 * V_72 ,
struct V_85 * V_86 ,
struct V_104 * V_105 , int V_106 ,
int V_128 , T_1 V_37 )
{
int V_10 , V_144 ;
int V_87 = 0 ;
struct V_89 * * V_140 ;
struct V_4 * V_4 ;
int V_145 = 0 ;
int V_84 , V_91 ;
for ( V_10 = 0 ; V_10 < V_106 ; V_10 ++ ) {
unsigned long V_130 = ( unsigned long ) V_105 [ V_10 ] . V_121 ;
unsigned long V_90 = V_105 [ V_10 ] . V_123 ;
unsigned long V_131 = ( V_130 + V_90 + V_88 - 1 ) >> V_133 ;
unsigned long V_132 = V_130 >> V_133 ;
if ( V_131 < V_132 )
return F_69 ( - V_134 ) ;
V_87 += V_131 - V_132 ;
if ( V_130 & F_74 ( V_72 ) )
return F_69 ( - V_134 ) ;
}
if ( ! V_87 )
return F_69 ( - V_134 ) ;
V_4 = F_70 ( V_37 , V_87 ) ;
if ( ! V_4 )
return F_69 ( - V_135 ) ;
V_84 = - V_135 ;
V_140 = F_75 ( V_87 , sizeof( struct V_89 * ) , V_37 ) ;
if ( ! V_140 )
goto V_26;
for ( V_10 = 0 ; V_10 < V_106 ; V_10 ++ ) {
unsigned long V_130 = ( unsigned long ) V_105 [ V_10 ] . V_121 ;
unsigned long V_90 = V_105 [ V_10 ] . V_123 ;
unsigned long V_131 = ( V_130 + V_90 + V_88 - 1 ) >> V_133 ;
unsigned long V_132 = V_130 >> V_133 ;
const int V_146 = V_131 - V_132 ;
const int V_147 = V_145 + V_146 ;
V_84 = F_76 ( V_130 , V_146 ,
V_128 , & V_140 [ V_145 ] ) ;
if ( V_84 < V_146 ) {
V_84 = - V_122 ;
goto V_148;
}
V_91 = V_130 & ~ V_129 ;
for ( V_144 = V_145 ; V_144 < V_147 ; V_144 ++ ) {
unsigned int V_119 = V_88 - V_91 ;
if ( V_90 <= 0 )
break;
if ( V_119 > V_90 )
V_119 = V_90 ;
if ( F_54 ( V_72 , V_4 , V_140 [ V_144 ] , V_119 , V_91 ) <
V_119 )
break;
V_90 -= V_119 ;
V_91 = 0 ;
}
V_145 = V_144 ;
while ( V_144 < V_147 )
F_77 ( V_140 [ V_144 ++ ] ) ;
}
F_27 ( V_140 ) ;
if ( ! V_128 )
V_4 -> V_79 |= V_137 ;
V_4 -> V_77 = V_86 ;
V_4 -> V_53 |= ( 1 << V_149 ) ;
return V_4 ;
V_148:
for ( V_10 = 0 ; V_10 < V_87 ; V_10 ++ ) {
if( ! V_140 [ V_10 ] )
break;
F_77 ( V_140 [ V_10 ] ) ;
}
V_26:
F_27 ( V_140 ) ;
F_38 ( V_4 ) ;
return F_69 ( V_84 ) ;
}
struct V_4 * F_78 ( struct V_71 * V_72 , struct V_85 * V_86 ,
unsigned long V_130 , unsigned int V_90 , int V_128 ,
T_1 V_37 )
{
struct V_104 V_105 ;
V_105 . V_121 = ( void T_2 * ) V_130 ;
V_105 . V_123 = V_90 ;
return F_79 ( V_72 , V_86 , & V_105 , 1 , V_128 , V_37 ) ;
}
struct V_4 * F_79 ( struct V_71 * V_72 , struct V_85 * V_86 ,
struct V_104 * V_105 , int V_106 ,
int V_128 , T_1 V_37 )
{
struct V_4 * V_4 ;
V_4 = F_73 ( V_72 , V_86 , V_105 , V_106 , V_128 ,
V_37 ) ;
if ( F_80 ( V_4 ) )
return V_4 ;
F_81 ( V_4 ) ;
return V_4 ;
}
static void F_82 ( struct V_4 * V_4 )
{
struct V_30 * V_94 ;
int V_10 ;
F_61 (bvec, bio, i, 0 ) {
if ( F_67 ( V_4 ) == V_125 )
F_83 ( V_94 -> V_70 ) ;
F_77 ( V_94 -> V_70 ) ;
}
F_38 ( V_4 ) ;
}
void F_84 ( struct V_4 * V_4 )
{
F_82 ( V_4 ) ;
F_38 ( V_4 ) ;
}
static void F_85 ( struct V_4 * V_4 , int V_150 )
{
F_38 ( V_4 ) ;
}
static struct V_4 * F_86 ( struct V_71 * V_72 , void * V_68 ,
unsigned int V_90 , T_1 V_37 )
{
unsigned long V_151 = ( unsigned long ) V_68 ;
unsigned long V_131 = ( V_151 + V_90 + V_88 - 1 ) >> V_133 ;
unsigned long V_132 = V_151 >> V_133 ;
const int V_87 = V_131 - V_132 ;
int V_91 , V_10 ;
struct V_4 * V_4 ;
V_4 = F_70 ( V_37 , V_87 ) ;
if ( ! V_4 )
return F_69 ( - V_135 ) ;
V_91 = F_87 ( V_151 ) ;
for ( V_10 = 0 ; V_10 < V_87 ; V_10 ++ ) {
unsigned int V_119 = V_88 - V_91 ;
if ( V_90 <= 0 )
break;
if ( V_119 > V_90 )
V_119 = V_90 ;
if ( F_54 ( V_72 , V_4 , F_88 ( V_68 ) , V_119 ,
V_91 ) < V_119 )
break;
V_68 += V_119 ;
V_90 -= V_119 ;
V_91 = 0 ;
}
V_4 -> V_152 = F_85 ;
return V_4 ;
}
struct V_4 * F_89 ( struct V_71 * V_72 , void * V_68 , unsigned int V_90 ,
T_1 V_37 )
{
struct V_4 * V_4 ;
V_4 = F_86 ( V_72 , V_68 , V_90 , V_37 ) ;
if ( F_80 ( V_4 ) )
return V_4 ;
if ( V_4 -> V_81 == V_90 )
return V_4 ;
F_38 ( V_4 ) ;
return F_69 ( - V_134 ) ;
}
static void F_90 ( struct V_4 * V_4 , int V_150 )
{
struct V_30 * V_94 ;
const int V_153 = F_67 ( V_4 ) == V_125 ;
struct V_102 * V_103 = V_4 -> V_111 ;
int V_10 ;
char * V_49 = V_103 -> V_109 [ 0 ] . V_121 ;
F_61 (bvec, bio, i, 0 ) {
char * V_154 = F_62 ( V_94 -> V_70 ) ;
int V_90 = V_103 -> V_108 [ V_10 ] . V_69 ;
if ( V_153 )
memcpy ( V_49 , V_154 , V_90 ) ;
F_65 ( V_94 -> V_70 ) ;
V_49 += V_90 ;
}
F_58 ( V_103 ) ;
F_38 ( V_4 ) ;
}
struct V_4 * F_91 ( struct V_71 * V_72 , void * V_68 , unsigned int V_90 ,
T_1 V_37 , int V_155 )
{
struct V_4 * V_4 ;
struct V_30 * V_94 ;
int V_10 ;
V_4 = F_72 ( V_72 , NULL , ( unsigned long ) V_68 , V_90 , 1 , V_37 ) ;
if ( F_80 ( V_4 ) )
return V_4 ;
if ( ! V_155 ) {
void * V_49 = V_68 ;
F_34 (bvec, bio, i) {
char * V_154 = F_62 ( V_94 -> V_70 ) ;
memcpy ( V_154 , V_49 , V_94 -> V_69 ) ;
V_49 += V_94 -> V_69 ;
}
}
V_4 -> V_152 = F_90 ;
return V_4 ;
}
void F_92 ( struct V_4 * V_4 )
{
struct V_30 * V_94 = V_4 -> V_50 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_4 -> V_80 ; V_10 ++ ) {
struct V_89 * V_89 = V_94 [ V_10 ] . V_70 ;
if ( V_89 && ! F_93 ( V_89 ) )
F_83 ( V_89 ) ;
}
}
static void F_94 ( struct V_4 * V_4 )
{
struct V_30 * V_94 = V_4 -> V_50 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_4 -> V_80 ; V_10 ++ ) {
struct V_89 * V_89 = V_94 [ V_10 ] . V_70 ;
if ( V_89 )
F_95 ( V_89 ) ;
}
}
static void F_96 ( struct V_156 * V_157 )
{
unsigned long V_56 ;
struct V_4 * V_4 ;
F_97 ( & V_158 , V_56 ) ;
V_4 = V_159 ;
V_159 = NULL ;
F_98 ( & V_158 , V_56 ) ;
while ( V_4 ) {
struct V_4 * V_160 = V_4 -> V_111 ;
F_92 ( V_4 ) ;
F_94 ( V_4 ) ;
F_38 ( V_4 ) ;
V_4 = V_160 ;
}
}
void F_99 ( struct V_4 * V_4 )
{
struct V_30 * V_94 = V_4 -> V_50 ;
int V_161 = 0 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_4 -> V_80 ; V_10 ++ ) {
struct V_89 * V_89 = V_94 [ V_10 ] . V_70 ;
if ( F_100 ( V_89 ) || F_93 ( V_89 ) ) {
F_77 ( V_89 ) ;
V_94 [ V_10 ] . V_70 = NULL ;
} else {
V_161 ++ ;
}
}
if ( V_161 ) {
unsigned long V_56 ;
F_97 ( & V_158 , V_56 ) ;
V_4 -> V_111 = V_159 ;
V_159 = V_4 ;
F_98 ( & V_158 , V_56 ) ;
F_101 ( & V_162 ) ;
} else {
F_38 ( V_4 ) ;
}
}
void F_102 ( struct V_4 * V_163 )
{
int V_10 ;
struct V_30 * V_94 ;
F_34 (bvec, bi, i)
F_36 ( V_94 -> V_70 ) ;
}
void F_103 ( struct V_4 * V_4 , int error )
{
if ( error )
F_104 ( V_54 , & V_4 -> V_53 ) ;
else if ( ! F_105 ( V_54 , & V_4 -> V_53 ) )
error = - V_164 ;
if ( V_4 -> V_152 )
V_4 -> V_152 ( V_4 , error ) ;
}
void F_106 ( struct V_165 * V_166 )
{
if ( F_40 ( & V_166 -> V_167 ) ) {
struct V_4 * V_168 = V_166 -> V_169 . V_111 ;
F_103 ( V_168 , V_166 -> error ) ;
F_14 ( V_166 , V_166 -> V_170 . V_111 ) ;
}
}
static void F_107 ( struct V_4 * V_163 , int V_150 )
{
struct V_165 * V_166 = F_108 ( V_163 , struct V_165 , V_169 ) ;
if ( V_150 )
V_166 -> error = V_150 ;
F_106 ( V_166 ) ;
}
static void F_109 ( struct V_4 * V_163 , int V_150 )
{
struct V_165 * V_166 = F_108 ( V_163 , struct V_165 , V_170 ) ;
if ( V_150 )
V_166 -> error = V_150 ;
F_106 ( V_166 ) ;
}
struct V_165 * F_110 ( struct V_4 * V_163 , int V_171 )
{
struct V_165 * V_166 = F_17 ( V_172 , V_173 ) ;
if ( ! V_166 )
return V_166 ;
F_111 ( F_48 ( V_163 -> V_77 ) , V_163 ,
V_163 -> V_76 + V_171 ) ;
F_112 ( V_163 -> V_80 != 1 && V_163 -> V_80 != 0 ) ;
F_112 ( V_163 -> V_82 != 0 ) ;
F_29 ( & V_166 -> V_167 , 3 ) ;
V_166 -> error = 0 ;
V_166 -> V_169 = * V_163 ;
V_166 -> V_170 = * V_163 ;
V_166 -> V_170 . V_76 += V_171 ;
V_166 -> V_170 . V_81 -= V_171 << 9 ;
V_166 -> V_169 . V_81 = V_171 << 9 ;
if ( V_163 -> V_80 != 0 ) {
V_166 -> V_174 = V_163 -> V_50 [ 0 ] ;
V_166 -> V_175 = V_163 -> V_50 [ 0 ] ;
if ( F_113 ( V_163 ) ) {
V_166 -> V_175 . V_96 += V_171 << 9 ;
V_166 -> V_175 . V_69 -= V_171 << 9 ;
V_166 -> V_174 . V_69 = V_171 << 9 ;
}
V_166 -> V_169 . V_50 = & V_166 -> V_174 ;
V_166 -> V_170 . V_50 = & V_166 -> V_175 ;
V_166 -> V_169 . V_67 = 1 ;
V_166 -> V_170 . V_67 = 1 ;
}
V_166 -> V_169 . V_152 = F_107 ;
V_166 -> V_170 . V_152 = F_109 ;
V_166 -> V_169 . V_111 = V_163 ;
V_166 -> V_170 . V_111 = V_172 ;
if ( F_22 ( V_163 ) )
F_114 ( V_163 , V_166 , V_171 ) ;
return V_166 ;
}
T_3 F_115 ( struct V_4 * V_4 , unsigned short V_176 ,
unsigned int V_91 )
{
unsigned int V_177 ;
struct V_30 * V_31 ;
T_3 V_178 ;
int V_10 ;
V_177 = F_116 ( V_4 -> V_77 -> V_179 -> V_180 ) ;
V_178 = 0 ;
if ( V_176 >= V_4 -> V_82 )
V_176 = V_4 -> V_80 - 1 ;
F_61 (bv, bio, i, 0 ) {
if ( V_10 == V_176 ) {
if ( V_91 > V_31 -> V_96 )
V_178 += ( V_91 - V_31 -> V_96 ) / V_177 ;
break;
}
V_178 += V_31 -> V_69 / V_177 ;
}
return V_178 ;
}
static int F_117 ( struct V_23 * V_24 , int V_181 )
{
struct V_35 * V_166 = V_28 + V_33 ;
V_24 -> V_34 = F_118 ( V_181 , V_166 -> V_5 ) ;
if ( ! V_24 -> V_34 )
return - V_135 ;
return 0 ;
}
static void F_119 ( struct V_23 * V_24 )
{
F_120 ( V_24 -> V_34 ) ;
}
void F_121 ( struct V_23 * V_24 )
{
if ( V_24 -> V_52 )
F_120 ( V_24 -> V_52 ) ;
F_122 ( V_24 ) ;
F_119 ( V_24 ) ;
F_7 ( V_24 ) ;
F_27 ( V_24 ) ;
}
struct V_23 * F_123 ( unsigned int V_182 , unsigned int V_51 )
{
unsigned int V_183 = V_63 * sizeof( struct V_30 ) ;
struct V_23 * V_24 ;
V_24 = F_124 ( sizeof( * V_24 ) , V_19 ) ;
if ( ! V_24 )
return NULL ;
V_24 -> V_51 = V_51 ;
V_24 -> V_6 = F_1 ( V_51 + V_183 ) ;
if ( ! V_24 -> V_6 ) {
F_27 ( V_24 ) ;
return NULL ;
}
V_24 -> V_52 = F_118 ( V_182 , V_24 -> V_6 ) ;
if ( ! V_24 -> V_52 )
goto V_184;
if ( ! F_117 ( V_24 , V_182 ) )
return V_24 ;
V_184:
F_121 ( V_24 ) ;
return NULL ;
}
int F_125 ( struct V_4 * V_4 )
{
struct V_185 * V_186 ;
struct V_187 * V_188 ;
if ( V_4 -> V_189 )
return - V_190 ;
V_186 = V_191 -> V_185 ;
if ( ! V_186 )
return - V_192 ;
F_126 ( V_186 ) ;
V_4 -> V_189 = V_186 ;
F_127 () ;
V_188 = F_128 ( V_191 , V_193 ) ;
if ( V_188 && F_129 ( V_188 ) )
V_4 -> V_194 = V_188 ;
F_130 () ;
return 0 ;
}
void F_21 ( struct V_4 * V_4 )
{
if ( V_4 -> V_189 ) {
F_131 ( V_4 -> V_189 ) ;
V_4 -> V_189 = NULL ;
}
if ( V_4 -> V_194 ) {
F_132 ( V_4 -> V_194 ) ;
V_4 -> V_194 = NULL ;
}
}
static void T_4 F_133 ( void )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_32 ; V_10 ++ ) {
int V_195 ;
struct V_35 * V_36 = V_28 + V_10 ;
if ( V_36 -> V_29 <= V_63 ) {
V_36 -> V_5 = NULL ;
continue;
}
V_195 = V_36 -> V_29 * sizeof( struct V_30 ) ;
V_36 -> V_5 = F_4 ( V_36 -> V_20 , V_195 , 0 ,
V_21 | V_196 , NULL ) ;
}
}
static int T_4 F_134 ( void )
{
V_18 = 2 ;
V_13 = 0 ;
V_14 = F_124 ( V_18 * sizeof( struct V_6 ) , V_19 ) ;
if ( ! V_14 )
F_135 ( L_4 ) ;
F_136 () ;
F_133 () ;
V_197 = F_123 ( V_198 , 0 ) ;
if ( ! V_197 )
F_135 ( L_4 ) ;
if ( F_137 ( V_197 , V_198 ) )
F_135 ( L_5 ) ;
V_172 = F_138 ( V_199 ,
sizeof( struct V_165 ) ) ;
if ( ! V_172 )
F_135 ( L_6 ) ;
return 0 ;
}
