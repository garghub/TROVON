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
F_26 ( & V_4 -> V_52 , 1 ) ;
}
struct V_4 * F_27 ( T_1 V_35 , int V_53 , struct V_21 * V_22 )
{
unsigned long V_25 = V_54 ;
struct V_28 * V_37 = NULL ;
struct V_4 * V_4 ;
void * V_46 ;
V_46 = F_17 ( V_22 -> V_49 , V_35 ) ;
if ( F_19 ( ! V_46 ) )
return NULL ;
V_4 = V_46 + V_22 -> V_48 ;
F_25 ( V_4 ) ;
if ( F_19 ( ! V_53 ) )
goto V_55;
if ( V_53 <= V_56 ) {
V_37 = V_4 -> V_57 ;
V_53 = V_56 ;
} else {
V_37 = F_16 ( V_35 , V_53 , & V_25 , V_22 ) ;
if ( F_19 ( ! V_37 ) )
goto V_58;
V_53 = F_11 ( V_25 ) ;
}
V_55:
V_4 -> V_50 |= V_25 << V_59 ;
V_4 -> V_60 = V_53 ;
V_4 -> V_47 = V_37 ;
return V_4 ;
V_58:
F_14 ( V_46 , V_22 -> V_49 ) ;
return NULL ;
}
static void F_28 ( struct V_4 * V_4 )
{
F_20 ( V_4 , V_61 ) ;
}
struct V_4 * F_29 ( T_1 V_35 , unsigned int V_53 )
{
struct V_4 * V_4 = F_27 ( V_35 , V_53 , V_61 ) ;
if ( V_4 )
V_4 -> V_62 = F_28 ;
return V_4 ;
}
static void F_30 ( struct V_4 * V_4 )
{
if ( F_23 ( V_4 ) )
F_24 ( V_4 , V_61 ) ;
F_31 ( V_4 ) ;
}
struct V_4 * F_32 ( T_1 V_35 , unsigned int V_53 )
{
struct V_4 * V_4 ;
if ( V_53 > V_63 )
return NULL ;
V_4 = F_33 ( sizeof( struct V_4 ) + V_53 * sizeof( struct V_28 ) ,
V_35 ) ;
if ( F_19 ( ! V_4 ) )
return NULL ;
F_25 ( V_4 ) ;
V_4 -> V_50 |= V_54 << V_59 ;
V_4 -> V_60 = V_53 ;
V_4 -> V_47 = V_4 -> V_57 ;
V_4 -> V_62 = F_30 ;
return V_4 ;
}
void F_34 ( struct V_4 * V_4 )
{
unsigned long V_64 ;
struct V_28 * V_29 ;
int V_8 ;
F_35 (bv, bio, i) {
char * V_65 = F_36 ( V_29 , & V_64 ) ;
memset ( V_65 , 0 , V_29 -> V_66 ) ;
F_37 ( V_29 -> V_67 ) ;
F_38 ( V_65 , & V_64 ) ;
}
}
void F_39 ( struct V_4 * V_4 )
{
F_13 ( ! F_40 ( & V_4 -> V_52 ) ) ;
if ( F_41 ( & V_4 -> V_52 ) ) {
V_4 -> V_68 = NULL ;
V_4 -> V_62 ( V_4 ) ;
}
}
inline int F_42 ( struct V_69 * V_70 , struct V_4 * V_4 )
{
if ( F_19 ( ! F_43 ( V_4 , V_71 ) ) )
F_44 ( V_70 , V_4 ) ;
return V_4 -> V_72 ;
}
void F_45 ( struct V_4 * V_4 , struct V_4 * V_73 )
{
memcpy ( V_4 -> V_47 , V_73 -> V_47 ,
V_73 -> V_60 * sizeof( struct V_28 ) ) ;
V_4 -> V_74 = V_73 -> V_74 ;
V_4 -> V_75 = V_73 -> V_75 ;
V_4 -> V_50 |= 1 << V_76 ;
V_4 -> V_77 = V_73 -> V_77 ;
V_4 -> V_78 = V_73 -> V_78 ;
V_4 -> V_79 = V_73 -> V_79 ;
V_4 -> V_80 = V_73 -> V_80 ;
}
struct V_4 * F_46 ( struct V_4 * V_4 , T_1 V_35 )
{
struct V_4 * V_81 = F_27 ( V_35 , V_4 -> V_60 , V_61 ) ;
if ( ! V_81 )
return NULL ;
V_81 -> V_62 = F_28 ;
F_45 ( V_81 , V_4 ) ;
if ( F_23 ( V_4 ) ) {
int V_82 ;
V_82 = F_47 ( V_81 , V_4 , V_35 , V_61 ) ;
if ( V_82 < 0 ) {
F_39 ( V_81 ) ;
return NULL ;
}
}
return V_81 ;
}
int F_48 ( struct V_83 * V_84 )
{
struct V_69 * V_70 = F_49 ( V_84 ) ;
int V_85 ;
V_85 = ( ( F_50 ( V_70 ) << 9 ) + V_86 - 1 ) >> V_87 ;
if ( V_85 > F_51 ( V_70 ) )
V_85 = F_51 ( V_70 ) ;
return V_85 ;
}
static int F_52 ( struct V_69 * V_70 , struct V_4 * V_4 , struct V_88
* V_88 , unsigned int V_89 , unsigned int V_90 ,
unsigned short V_91 )
{
int V_92 = 0 ;
struct V_28 * V_93 ;
if ( F_19 ( F_43 ( V_4 , V_76 ) ) )
return 0 ;
if ( ( ( V_4 -> V_79 + V_89 ) >> 9 ) > V_91 )
return 0 ;
if ( V_4 -> V_78 > 0 ) {
struct V_28 * V_94 = & V_4 -> V_47 [ V_4 -> V_78 - 1 ] ;
if ( V_88 == V_94 -> V_67 &&
V_90 == V_94 -> V_95 + V_94 -> V_66 ) {
unsigned int V_96 = V_94 -> V_66 ;
V_94 -> V_66 += V_89 ;
if ( V_70 -> V_97 ) {
struct V_98 V_99 = {
. V_75 = V_4 -> V_75 ,
. V_74 = V_4 -> V_74 ,
. V_79 = V_4 -> V_79 - V_96 ,
. V_77 = V_4 -> V_77 ,
} ;
if ( V_70 -> V_97 ( V_70 , & V_99 , V_94 ) < V_94 -> V_66 ) {
V_94 -> V_66 -= V_89 ;
return 0 ;
}
}
goto V_100;
}
}
if ( V_4 -> V_78 >= V_4 -> V_60 )
return 0 ;
while ( V_4 -> V_72 >= F_51 ( V_70 ) ) {
if ( V_92 )
return 0 ;
V_92 = 1 ;
F_44 ( V_70 , V_4 ) ;
}
V_93 = & V_4 -> V_47 [ V_4 -> V_78 ] ;
V_93 -> V_67 = V_88 ;
V_93 -> V_66 = V_89 ;
V_93 -> V_95 = V_90 ;
if ( V_70 -> V_97 ) {
struct V_98 V_99 = {
. V_75 = V_4 -> V_75 ,
. V_74 = V_4 -> V_74 ,
. V_79 = V_4 -> V_79 ,
. V_77 = V_4 -> V_77 ,
} ;
if ( V_70 -> V_97 ( V_70 , & V_99 , V_93 ) < V_93 -> V_66 ) {
V_93 -> V_67 = NULL ;
V_93 -> V_66 = 0 ;
V_93 -> V_95 = 0 ;
return 0 ;
}
}
if ( V_4 -> V_78 && ( F_53 ( V_93 - 1 , V_93 ) ) )
V_4 -> V_50 &= ~ ( 1 << V_71 ) ;
V_4 -> V_78 ++ ;
V_4 -> V_72 ++ ;
V_100:
V_4 -> V_79 += V_89 ;
return V_89 ;
}
int F_54 ( struct V_69 * V_70 , struct V_4 * V_4 , struct V_88 * V_88 ,
unsigned int V_89 , unsigned int V_90 )
{
return F_52 ( V_70 , V_4 , V_88 , V_89 , V_90 ,
F_55 ( V_70 ) ) ;
}
int F_56 ( struct V_4 * V_4 , struct V_88 * V_88 , unsigned int V_89 ,
unsigned int V_90 )
{
struct V_69 * V_70 = F_49 ( V_4 -> V_75 ) ;
return F_52 ( V_70 , V_4 , V_88 , V_89 , V_90 , F_50 ( V_70 ) ) ;
}
static void F_57 ( struct V_101 * V_102 , struct V_4 * V_4 ,
struct V_103 * V_104 , int V_105 ,
int V_106 )
{
memcpy ( V_102 -> V_107 , V_4 -> V_47 , sizeof( struct V_28 ) * V_4 -> V_78 ) ;
memcpy ( V_102 -> V_108 , V_104 , sizeof( struct V_103 ) * V_105 ) ;
V_102 -> V_109 = V_105 ;
V_102 -> V_106 = V_106 ;
V_4 -> V_110 = V_102 ;
}
static void F_58 ( struct V_101 * V_102 )
{
F_31 ( V_102 -> V_107 ) ;
F_31 ( V_102 -> V_108 ) ;
F_31 ( V_102 ) ;
}
static struct V_101 * F_59 ( int V_111 ,
unsigned int V_105 ,
T_1 V_35 )
{
struct V_101 * V_102 ;
if ( V_105 > V_63 )
return NULL ;
V_102 = F_33 ( sizeof( * V_102 ) , V_35 ) ;
if ( ! V_102 )
return NULL ;
V_102 -> V_107 = F_33 ( sizeof( struct V_28 ) * V_111 , V_35 ) ;
if ( ! V_102 -> V_107 ) {
F_31 ( V_102 ) ;
return NULL ;
}
V_102 -> V_108 = F_33 ( sizeof( struct V_103 ) * V_105 , V_35 ) ;
if ( V_102 -> V_108 )
return V_102 ;
F_31 ( V_102 -> V_107 ) ;
F_31 ( V_102 ) ;
return NULL ;
}
static int F_60 ( struct V_4 * V_4 , struct V_28 * V_107 ,
struct V_103 * V_104 , int V_105 ,
int V_112 , int V_113 , int V_114 )
{
int V_82 = 0 , V_8 ;
struct V_28 * V_93 ;
int V_115 = 0 ;
unsigned int V_116 = 0 ;
F_61 (bvec, bio, i, 0 ) {
char * V_117 = F_62 ( V_93 -> V_67 ) ;
unsigned int V_66 = V_107 [ V_8 ] . V_66 ;
while ( V_66 && V_115 < V_105 ) {
unsigned int V_118 ;
char T_2 * V_119 ;
V_118 = F_63 (unsigned int,
iov[iov_idx].iov_len - iov_off, bv_len) ;
V_119 = V_104 [ V_115 ] . V_120 + V_116 ;
if ( ! V_82 ) {
if ( V_112 )
V_82 = F_64 ( V_119 , V_117 ,
V_118 ) ;
if ( V_113 )
V_82 = F_65 ( V_117 , V_119 ,
V_118 ) ;
if ( V_82 )
V_82 = - V_121 ;
}
V_66 -= V_118 ;
V_117 += V_118 ;
V_119 += V_118 ;
V_116 += V_118 ;
if ( V_104 [ V_115 ] . V_122 == V_116 ) {
V_115 ++ ;
V_116 = 0 ;
}
}
if ( V_114 )
F_66 ( V_93 -> V_67 ) ;
}
return V_82 ;
}
int F_67 ( struct V_4 * V_4 )
{
struct V_101 * V_102 = V_4 -> V_110 ;
int V_82 = 0 ;
if ( ! F_43 ( V_4 , V_123 ) )
V_82 = F_60 ( V_4 , V_102 -> V_107 , V_102 -> V_108 ,
V_102 -> V_109 , F_68 ( V_4 ) == V_124 ,
0 , V_102 -> V_106 ) ;
F_58 ( V_102 ) ;
F_39 ( V_4 ) ;
return V_82 ;
}
struct V_4 * F_69 ( struct V_69 * V_70 ,
struct V_125 * V_126 ,
struct V_103 * V_104 , int V_105 ,
int V_127 , T_1 V_35 )
{
struct V_101 * V_102 ;
struct V_28 * V_93 ;
struct V_88 * V_88 ;
struct V_4 * V_4 ;
int V_8 , V_82 ;
int V_85 = 0 ;
unsigned int V_89 = 0 ;
unsigned int V_90 = V_126 ? V_126 -> V_90 & ~ V_128 : 0 ;
for ( V_8 = 0 ; V_8 < V_105 ; V_8 ++ ) {
unsigned long V_129 ;
unsigned long V_130 ;
unsigned long V_131 ;
V_129 = ( unsigned long ) V_104 [ V_8 ] . V_120 ;
V_130 = ( V_129 + V_104 [ V_8 ] . V_122 + V_86 - 1 ) >> V_87 ;
V_131 = V_129 >> V_87 ;
if ( V_130 < V_131 )
return F_70 ( - V_132 ) ;
V_85 += V_130 - V_131 ;
V_89 += V_104 [ V_8 ] . V_122 ;
}
if ( V_90 )
V_85 ++ ;
V_102 = F_59 ( V_85 , V_105 , V_35 ) ;
if ( ! V_102 )
return F_70 ( - V_133 ) ;
V_82 = - V_133 ;
V_4 = F_32 ( V_35 , V_85 ) ;
if ( ! V_4 )
goto V_134;
if ( ! V_127 )
V_4 -> V_77 |= V_135 ;
V_82 = 0 ;
if ( V_126 ) {
V_85 = 1 << V_126 -> V_136 ;
V_8 = V_126 -> V_90 / V_86 ;
}
while ( V_89 ) {
unsigned int V_118 = V_86 ;
V_118 -= V_90 ;
if ( V_118 > V_89 )
V_118 = V_89 ;
if ( V_126 ) {
if ( V_8 == V_126 -> V_137 * V_85 ) {
V_82 = - V_133 ;
break;
}
V_88 = V_126 -> V_138 [ V_8 / V_85 ] ;
V_88 += ( V_8 % V_85 ) ;
V_8 ++ ;
} else {
V_88 = F_71 ( V_70 -> V_139 | V_35 ) ;
if ( ! V_88 ) {
V_82 = - V_133 ;
break;
}
}
if ( F_54 ( V_70 , V_4 , V_88 , V_118 , V_90 ) < V_118 )
break;
V_89 -= V_118 ;
V_90 = 0 ;
}
if ( V_82 )
goto V_140;
if ( ( ! V_127 && ( ! V_126 || ! V_126 -> V_141 ) ) ||
( V_126 && V_126 -> V_113 ) ) {
V_82 = F_60 ( V_4 , V_4 -> V_47 , V_104 , V_105 , 0 , 1 , 0 ) ;
if ( V_82 )
goto V_140;
}
F_57 ( V_102 , V_4 , V_104 , V_105 , V_126 ? 0 : 1 ) ;
return V_4 ;
V_140:
if ( ! V_126 )
F_35 (bvec, bio, i)
F_66 ( V_93 -> V_67 ) ;
F_39 ( V_4 ) ;
V_134:
F_58 ( V_102 ) ;
return F_70 ( V_82 ) ;
}
struct V_4 * F_72 ( struct V_69 * V_70 , struct V_125 * V_126 ,
unsigned long V_129 , unsigned int V_89 ,
int V_127 , T_1 V_35 )
{
struct V_103 V_104 ;
V_104 . V_120 = ( void T_2 * ) V_129 ;
V_104 . V_122 = V_89 ;
return F_69 ( V_70 , V_126 , & V_104 , 1 , V_127 , V_35 ) ;
}
static struct V_4 * F_73 ( struct V_69 * V_70 ,
struct V_83 * V_84 ,
struct V_103 * V_104 , int V_105 ,
int V_127 , T_1 V_35 )
{
int V_8 , V_142 ;
int V_85 = 0 ;
struct V_88 * * V_138 ;
struct V_4 * V_4 ;
int V_143 = 0 ;
int V_82 , V_90 ;
for ( V_8 = 0 ; V_8 < V_105 ; V_8 ++ ) {
unsigned long V_129 = ( unsigned long ) V_104 [ V_8 ] . V_120 ;
unsigned long V_89 = V_104 [ V_8 ] . V_122 ;
unsigned long V_130 = ( V_129 + V_89 + V_86 - 1 ) >> V_87 ;
unsigned long V_131 = V_129 >> V_87 ;
if ( V_130 < V_131 )
return F_70 ( - V_132 ) ;
V_85 += V_130 - V_131 ;
if ( V_129 & F_74 ( V_70 ) )
return F_70 ( - V_132 ) ;
}
if ( ! V_85 )
return F_70 ( - V_132 ) ;
V_4 = F_32 ( V_35 , V_85 ) ;
if ( ! V_4 )
return F_70 ( - V_133 ) ;
V_82 = - V_133 ;
V_138 = F_75 ( V_85 , sizeof( struct V_88 * ) , V_35 ) ;
if ( ! V_138 )
goto V_24;
for ( V_8 = 0 ; V_8 < V_105 ; V_8 ++ ) {
unsigned long V_129 = ( unsigned long ) V_104 [ V_8 ] . V_120 ;
unsigned long V_89 = V_104 [ V_8 ] . V_122 ;
unsigned long V_130 = ( V_129 + V_89 + V_86 - 1 ) >> V_87 ;
unsigned long V_131 = V_129 >> V_87 ;
const int V_144 = V_130 - V_131 ;
const int V_145 = V_143 + V_144 ;
V_82 = F_76 ( V_129 , V_144 ,
V_127 , & V_138 [ V_143 ] ) ;
if ( V_82 < V_144 ) {
V_82 = - V_121 ;
goto V_146;
}
V_90 = V_129 & ~ V_128 ;
for ( V_142 = V_143 ; V_142 < V_145 ; V_142 ++ ) {
unsigned int V_118 = V_86 - V_90 ;
if ( V_89 <= 0 )
break;
if ( V_118 > V_89 )
V_118 = V_89 ;
if ( F_54 ( V_70 , V_4 , V_138 [ V_142 ] , V_118 , V_90 ) <
V_118 )
break;
V_89 -= V_118 ;
V_90 = 0 ;
}
V_143 = V_142 ;
while ( V_142 < V_145 )
F_77 ( V_138 [ V_142 ++ ] ) ;
}
F_31 ( V_138 ) ;
if ( ! V_127 )
V_4 -> V_77 |= V_135 ;
V_4 -> V_75 = V_84 ;
V_4 -> V_50 |= ( 1 << V_147 ) ;
return V_4 ;
V_146:
for ( V_8 = 0 ; V_8 < V_85 ; V_8 ++ ) {
if( ! V_138 [ V_8 ] )
break;
F_77 ( V_138 [ V_8 ] ) ;
}
V_24:
F_31 ( V_138 ) ;
F_39 ( V_4 ) ;
return F_70 ( V_82 ) ;
}
struct V_4 * F_78 ( struct V_69 * V_70 , struct V_83 * V_84 ,
unsigned long V_129 , unsigned int V_89 , int V_127 ,
T_1 V_35 )
{
struct V_103 V_104 ;
V_104 . V_120 = ( void T_2 * ) V_129 ;
V_104 . V_122 = V_89 ;
return F_79 ( V_70 , V_84 , & V_104 , 1 , V_127 , V_35 ) ;
}
struct V_4 * F_79 ( struct V_69 * V_70 , struct V_83 * V_84 ,
struct V_103 * V_104 , int V_105 ,
int V_127 , T_1 V_35 )
{
struct V_4 * V_4 ;
V_4 = F_73 ( V_70 , V_84 , V_104 , V_105 , V_127 ,
V_35 ) ;
if ( F_80 ( V_4 ) )
return V_4 ;
F_81 ( V_4 ) ;
return V_4 ;
}
static void F_82 ( struct V_4 * V_4 )
{
struct V_28 * V_93 ;
int V_8 ;
F_61 (bvec, bio, i, 0 ) {
if ( F_68 ( V_4 ) == V_124 )
F_83 ( V_93 -> V_67 ) ;
F_77 ( V_93 -> V_67 ) ;
}
F_39 ( V_4 ) ;
}
void F_84 ( struct V_4 * V_4 )
{
F_82 ( V_4 ) ;
F_39 ( V_4 ) ;
}
static void F_85 ( struct V_4 * V_4 , int V_148 )
{
F_39 ( V_4 ) ;
}
static struct V_4 * F_86 ( struct V_69 * V_70 , void * V_65 ,
unsigned int V_89 , T_1 V_35 )
{
unsigned long V_149 = ( unsigned long ) V_65 ;
unsigned long V_130 = ( V_149 + V_89 + V_86 - 1 ) >> V_87 ;
unsigned long V_131 = V_149 >> V_87 ;
const int V_85 = V_130 - V_131 ;
int V_90 , V_8 ;
struct V_4 * V_4 ;
V_4 = F_32 ( V_35 , V_85 ) ;
if ( ! V_4 )
return F_70 ( - V_133 ) ;
V_90 = F_87 ( V_149 ) ;
for ( V_8 = 0 ; V_8 < V_85 ; V_8 ++ ) {
unsigned int V_118 = V_86 - V_90 ;
if ( V_89 <= 0 )
break;
if ( V_118 > V_89 )
V_118 = V_89 ;
if ( F_54 ( V_70 , V_4 , F_88 ( V_65 ) , V_118 ,
V_90 ) < V_118 )
break;
V_65 += V_118 ;
V_89 -= V_118 ;
V_90 = 0 ;
}
V_4 -> V_150 = F_85 ;
return V_4 ;
}
struct V_4 * F_89 ( struct V_69 * V_70 , void * V_65 , unsigned int V_89 ,
T_1 V_35 )
{
struct V_4 * V_4 ;
V_4 = F_86 ( V_70 , V_65 , V_89 , V_35 ) ;
if ( F_80 ( V_4 ) )
return V_4 ;
if ( V_4 -> V_79 == V_89 )
return V_4 ;
F_39 ( V_4 ) ;
return F_70 ( - V_132 ) ;
}
static void F_90 ( struct V_4 * V_4 , int V_148 )
{
struct V_28 * V_93 ;
const int V_151 = F_68 ( V_4 ) == V_124 ;
struct V_101 * V_102 = V_4 -> V_110 ;
int V_8 ;
char * V_46 = V_102 -> V_108 [ 0 ] . V_120 ;
F_61 (bvec, bio, i, 0 ) {
char * V_152 = F_62 ( V_93 -> V_67 ) ;
int V_89 = V_102 -> V_107 [ V_8 ] . V_66 ;
if ( V_151 )
memcpy ( V_46 , V_152 , V_89 ) ;
F_66 ( V_93 -> V_67 ) ;
V_46 += V_89 ;
}
F_58 ( V_102 ) ;
F_39 ( V_4 ) ;
}
struct V_4 * F_91 ( struct V_69 * V_70 , void * V_65 , unsigned int V_89 ,
T_1 V_35 , int V_153 )
{
struct V_4 * V_4 ;
struct V_28 * V_93 ;
int V_8 ;
V_4 = F_72 ( V_70 , NULL , ( unsigned long ) V_65 , V_89 , 1 , V_35 ) ;
if ( F_80 ( V_4 ) )
return V_4 ;
if ( ! V_153 ) {
void * V_46 = V_65 ;
F_35 (bvec, bio, i) {
char * V_152 = F_62 ( V_93 -> V_67 ) ;
memcpy ( V_152 , V_46 , V_93 -> V_66 ) ;
V_46 += V_93 -> V_66 ;
}
}
V_4 -> V_150 = F_90 ;
return V_4 ;
}
void F_92 ( struct V_4 * V_4 )
{
struct V_28 * V_93 = V_4 -> V_47 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_4 -> V_78 ; V_8 ++ ) {
struct V_88 * V_88 = V_93 [ V_8 ] . V_67 ;
if ( V_88 && ! F_93 ( V_88 ) )
F_83 ( V_88 ) ;
}
}
static void F_94 ( struct V_4 * V_4 )
{
struct V_28 * V_93 = V_4 -> V_47 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_4 -> V_78 ; V_8 ++ ) {
struct V_88 * V_88 = V_93 [ V_8 ] . V_67 ;
if ( V_88 )
F_95 ( V_88 ) ;
}
}
static void F_96 ( struct V_154 * V_155 )
{
unsigned long V_64 ;
struct V_4 * V_4 ;
F_97 ( & V_156 , V_64 ) ;
V_4 = V_157 ;
V_157 = NULL ;
F_98 ( & V_156 , V_64 ) ;
while ( V_4 ) {
struct V_4 * V_158 = V_4 -> V_110 ;
F_92 ( V_4 ) ;
F_94 ( V_4 ) ;
F_39 ( V_4 ) ;
V_4 = V_158 ;
}
}
void F_99 ( struct V_4 * V_4 )
{
struct V_28 * V_93 = V_4 -> V_47 ;
int V_159 = 0 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_4 -> V_78 ; V_8 ++ ) {
struct V_88 * V_88 = V_93 [ V_8 ] . V_67 ;
if ( F_100 ( V_88 ) || F_93 ( V_88 ) ) {
F_77 ( V_88 ) ;
V_93 [ V_8 ] . V_67 = NULL ;
} else {
V_159 ++ ;
}
}
if ( V_159 ) {
unsigned long V_64 ;
F_97 ( & V_156 , V_64 ) ;
V_4 -> V_110 = V_157 ;
V_157 = V_4 ;
F_98 ( & V_156 , V_64 ) ;
F_101 ( & V_160 ) ;
} else {
F_39 ( V_4 ) ;
}
}
void F_102 ( struct V_4 * V_161 )
{
int V_8 ;
struct V_28 * V_93 ;
F_35 (bvec, bi, i)
F_37 ( V_93 -> V_67 ) ;
}
void F_103 ( struct V_4 * V_4 , int error )
{
if ( error )
F_104 ( V_51 , & V_4 -> V_50 ) ;
else if ( ! F_105 ( V_51 , & V_4 -> V_50 ) )
error = - V_162 ;
if ( V_4 -> V_150 )
V_4 -> V_150 ( V_4 , error ) ;
}
void F_106 ( struct V_163 * V_164 )
{
if ( F_41 ( & V_164 -> V_165 ) ) {
struct V_4 * V_166 = V_164 -> V_167 . V_110 ;
F_103 ( V_166 , V_164 -> error ) ;
F_14 ( V_164 , V_164 -> V_168 . V_110 ) ;
}
}
static void F_107 ( struct V_4 * V_161 , int V_148 )
{
struct V_163 * V_164 = F_108 ( V_161 , struct V_163 , V_167 ) ;
if ( V_148 )
V_164 -> error = V_148 ;
F_106 ( V_164 ) ;
}
static void F_109 ( struct V_4 * V_161 , int V_148 )
{
struct V_163 * V_164 = F_108 ( V_161 , struct V_163 , V_168 ) ;
if ( V_148 )
V_164 -> error = V_148 ;
F_106 ( V_164 ) ;
}
struct V_163 * F_110 ( struct V_4 * V_161 , int V_169 )
{
struct V_163 * V_164 = F_17 ( V_170 , V_171 ) ;
if ( ! V_164 )
return V_164 ;
F_111 ( F_49 ( V_161 -> V_75 ) , V_161 ,
V_161 -> V_74 + V_169 ) ;
F_112 ( V_161 -> V_78 != 1 ) ;
F_112 ( V_161 -> V_80 != 0 ) ;
F_26 ( & V_164 -> V_165 , 3 ) ;
V_164 -> error = 0 ;
V_164 -> V_167 = * V_161 ;
V_164 -> V_168 = * V_161 ;
V_164 -> V_168 . V_74 += V_169 ;
V_164 -> V_168 . V_79 -= V_169 << 9 ;
V_164 -> V_167 . V_79 = V_169 << 9 ;
V_164 -> V_172 = V_161 -> V_47 [ 0 ] ;
V_164 -> V_173 = V_161 -> V_47 [ 0 ] ;
V_164 -> V_173 . V_95 += V_169 << 9 ;
V_164 -> V_173 . V_66 -= V_169 << 9 ;
V_164 -> V_172 . V_66 = V_169 << 9 ;
V_164 -> V_167 . V_47 = & V_164 -> V_172 ;
V_164 -> V_168 . V_47 = & V_164 -> V_173 ;
V_164 -> V_167 . V_60 = 1 ;
V_164 -> V_168 . V_60 = 1 ;
V_164 -> V_167 . V_150 = F_107 ;
V_164 -> V_168 . V_150 = F_109 ;
V_164 -> V_167 . V_110 = V_161 ;
V_164 -> V_168 . V_110 = V_170 ;
if ( F_23 ( V_161 ) )
F_113 ( V_161 , V_164 , V_169 ) ;
return V_164 ;
}
T_3 F_114 ( struct V_4 * V_4 , unsigned short V_174 ,
unsigned int V_90 )
{
unsigned int V_175 ;
struct V_28 * V_29 ;
T_3 V_176 ;
int V_8 ;
V_175 = F_115 ( V_4 -> V_75 -> V_177 -> V_178 ) ;
V_176 = 0 ;
if ( V_174 >= V_4 -> V_80 )
V_174 = V_4 -> V_78 - 1 ;
F_61 (bv, bio, i, 0 ) {
if ( V_8 == V_174 ) {
if ( V_90 > V_29 -> V_95 )
V_176 += ( V_90 - V_29 -> V_95 ) / V_175 ;
break;
}
V_176 += V_29 -> V_66 / V_175 ;
}
return V_176 ;
}
static int F_116 ( struct V_21 * V_22 , int V_179 )
{
struct V_33 * V_164 = V_26 + V_31 ;
V_22 -> V_32 = F_117 ( V_179 , V_164 -> V_5 ) ;
if ( ! V_22 -> V_32 )
return - V_133 ;
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
struct V_21 * F_122 ( unsigned int V_180 , unsigned int V_48 )
{
unsigned int V_181 = V_56 * sizeof( struct V_28 ) ;
struct V_21 * V_22 ;
V_22 = F_123 ( sizeof( * V_22 ) , V_17 ) ;
if ( ! V_22 )
return NULL ;
V_22 -> V_48 = V_48 ;
V_22 -> V_6 = F_1 ( V_48 + V_181 ) ;
if ( ! V_22 -> V_6 ) {
F_31 ( V_22 ) ;
return NULL ;
}
V_22 -> V_49 = F_117 ( V_180 , V_22 -> V_6 ) ;
if ( ! V_22 -> V_49 )
goto V_182;
if ( ! F_116 ( V_22 , V_180 ) )
return V_22 ;
V_182:
F_120 ( V_22 ) ;
return NULL ;
}
static void T_4 F_124 ( void )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_30 ; V_8 ++ ) {
int V_183 ;
struct V_33 * V_34 = V_26 + V_8 ;
if ( V_34 -> V_27 <= V_56 ) {
V_34 -> V_5 = NULL ;
continue;
}
V_183 = V_34 -> V_27 * sizeof( struct V_28 ) ;
V_34 -> V_5 = F_4 ( V_34 -> V_18 , V_183 , 0 ,
V_19 | V_184 , NULL ) ;
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
V_61 = F_122 ( V_185 , 0 ) ;
if ( ! V_61 )
F_126 ( L_4 ) ;
if ( F_128 ( V_61 , V_185 ) )
F_126 ( L_5 ) ;
V_170 = F_129 ( V_186 ,
sizeof( struct V_163 ) ) ;
if ( ! V_170 )
F_126 ( L_6 ) ;
return 0 ;
}
