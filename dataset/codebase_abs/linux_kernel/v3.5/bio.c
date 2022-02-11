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
F_42 ( V_4 ) ;
V_4 -> V_68 = NULL ;
V_4 -> V_62 ( V_4 ) ;
}
}
inline int F_43 ( struct V_69 * V_70 , struct V_4 * V_4 )
{
if ( F_19 ( ! F_44 ( V_4 , V_71 ) ) )
F_45 ( V_70 , V_4 ) ;
return V_4 -> V_72 ;
}
void F_46 ( struct V_4 * V_4 , struct V_4 * V_73 )
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
struct V_4 * F_47 ( struct V_4 * V_4 , T_1 V_35 )
{
struct V_4 * V_81 = F_27 ( V_35 , V_4 -> V_60 , V_61 ) ;
if ( ! V_81 )
return NULL ;
V_81 -> V_62 = F_28 ;
F_46 ( V_81 , V_4 ) ;
if ( F_23 ( V_4 ) ) {
int V_82 ;
V_82 = F_48 ( V_81 , V_4 , V_35 , V_61 ) ;
if ( V_82 < 0 ) {
F_39 ( V_81 ) ;
return NULL ;
}
}
return V_81 ;
}
int F_49 ( struct V_83 * V_84 )
{
struct V_69 * V_70 = F_50 ( V_84 ) ;
int V_85 ;
V_85 = F_51 ( unsigned ,
F_52 ( V_70 ) ,
F_53 ( V_70 ) / ( V_86 >> 9 ) + 1 ) ;
return F_51 ( unsigned , V_85 , V_38 ) ;
}
static int F_54 ( struct V_69 * V_70 , struct V_4 * V_4 , struct V_87
* V_87 , unsigned int V_88 , unsigned int V_89 ,
unsigned short V_90 )
{
int V_91 = 0 ;
struct V_28 * V_92 ;
if ( F_19 ( F_44 ( V_4 , V_76 ) ) )
return 0 ;
if ( ( ( V_4 -> V_79 + V_88 ) >> 9 ) > V_90 )
return 0 ;
if ( V_4 -> V_78 > 0 ) {
struct V_28 * V_93 = & V_4 -> V_47 [ V_4 -> V_78 - 1 ] ;
if ( V_87 == V_93 -> V_67 &&
V_89 == V_93 -> V_94 + V_93 -> V_66 ) {
unsigned int V_95 = V_93 -> V_66 ;
V_93 -> V_66 += V_88 ;
if ( V_70 -> V_96 ) {
struct V_97 V_98 = {
. V_75 = V_4 -> V_75 ,
. V_74 = V_4 -> V_74 ,
. V_79 = V_4 -> V_79 - V_95 ,
. V_77 = V_4 -> V_77 ,
} ;
if ( V_70 -> V_96 ( V_70 , & V_98 , V_93 ) < V_93 -> V_66 ) {
V_93 -> V_66 -= V_88 ;
return 0 ;
}
}
goto V_99;
}
}
if ( V_4 -> V_78 >= V_4 -> V_60 )
return 0 ;
while ( V_4 -> V_72 >= F_52 ( V_70 ) ) {
if ( V_91 )
return 0 ;
V_91 = 1 ;
F_45 ( V_70 , V_4 ) ;
}
V_92 = & V_4 -> V_47 [ V_4 -> V_78 ] ;
V_92 -> V_67 = V_87 ;
V_92 -> V_66 = V_88 ;
V_92 -> V_94 = V_89 ;
if ( V_70 -> V_96 ) {
struct V_97 V_98 = {
. V_75 = V_4 -> V_75 ,
. V_74 = V_4 -> V_74 ,
. V_79 = V_4 -> V_79 ,
. V_77 = V_4 -> V_77 ,
} ;
if ( V_70 -> V_96 ( V_70 , & V_98 , V_92 ) < V_92 -> V_66 ) {
V_92 -> V_67 = NULL ;
V_92 -> V_66 = 0 ;
V_92 -> V_94 = 0 ;
return 0 ;
}
}
if ( V_4 -> V_78 && ( F_55 ( V_92 - 1 , V_92 ) ) )
V_4 -> V_50 &= ~ ( 1 << V_71 ) ;
V_4 -> V_78 ++ ;
V_4 -> V_72 ++ ;
V_99:
V_4 -> V_79 += V_88 ;
return V_88 ;
}
int F_56 ( struct V_69 * V_70 , struct V_4 * V_4 , struct V_87 * V_87 ,
unsigned int V_88 , unsigned int V_89 )
{
return F_54 ( V_70 , V_4 , V_87 , V_88 , V_89 ,
F_57 ( V_70 ) ) ;
}
int F_58 ( struct V_4 * V_4 , struct V_87 * V_87 , unsigned int V_88 ,
unsigned int V_89 )
{
struct V_69 * V_70 = F_50 ( V_4 -> V_75 ) ;
return F_54 ( V_70 , V_4 , V_87 , V_88 , V_89 , F_53 ( V_70 ) ) ;
}
static void F_59 ( struct V_100 * V_101 , struct V_4 * V_4 ,
struct V_102 * V_103 , int V_104 ,
int V_105 )
{
memcpy ( V_101 -> V_106 , V_4 -> V_47 , sizeof( struct V_28 ) * V_4 -> V_78 ) ;
memcpy ( V_101 -> V_107 , V_103 , sizeof( struct V_102 ) * V_104 ) ;
V_101 -> V_108 = V_104 ;
V_101 -> V_105 = V_105 ;
V_4 -> V_109 = V_101 ;
}
static void F_60 ( struct V_100 * V_101 )
{
F_31 ( V_101 -> V_106 ) ;
F_31 ( V_101 -> V_107 ) ;
F_31 ( V_101 ) ;
}
static struct V_100 * F_61 ( int V_110 ,
unsigned int V_104 ,
T_1 V_35 )
{
struct V_100 * V_101 ;
if ( V_104 > V_63 )
return NULL ;
V_101 = F_33 ( sizeof( * V_101 ) , V_35 ) ;
if ( ! V_101 )
return NULL ;
V_101 -> V_106 = F_33 ( sizeof( struct V_28 ) * V_110 , V_35 ) ;
if ( ! V_101 -> V_106 ) {
F_31 ( V_101 ) ;
return NULL ;
}
V_101 -> V_107 = F_33 ( sizeof( struct V_102 ) * V_104 , V_35 ) ;
if ( V_101 -> V_107 )
return V_101 ;
F_31 ( V_101 -> V_106 ) ;
F_31 ( V_101 ) ;
return NULL ;
}
static int F_62 ( struct V_4 * V_4 , struct V_28 * V_106 ,
struct V_102 * V_103 , int V_104 ,
int V_111 , int V_112 , int V_113 )
{
int V_82 = 0 , V_8 ;
struct V_28 * V_92 ;
int V_114 = 0 ;
unsigned int V_115 = 0 ;
F_63 (bvec, bio, i, 0 ) {
char * V_116 = F_64 ( V_92 -> V_67 ) ;
unsigned int V_66 = V_106 [ V_8 ] . V_66 ;
while ( V_66 && V_114 < V_104 ) {
unsigned int V_117 ;
char T_2 * V_118 ;
V_117 = F_51 (unsigned int,
iov[iov_idx].iov_len - iov_off, bv_len) ;
V_118 = V_103 [ V_114 ] . V_119 + V_115 ;
if ( ! V_82 ) {
if ( V_111 )
V_82 = F_65 ( V_118 , V_116 ,
V_117 ) ;
if ( V_112 )
V_82 = F_66 ( V_116 , V_118 ,
V_117 ) ;
if ( V_82 )
V_82 = - V_120 ;
}
V_66 -= V_117 ;
V_116 += V_117 ;
V_118 += V_117 ;
V_115 += V_117 ;
if ( V_103 [ V_114 ] . V_121 == V_115 ) {
V_114 ++ ;
V_115 = 0 ;
}
}
if ( V_113 )
F_67 ( V_92 -> V_67 ) ;
}
return V_82 ;
}
int F_68 ( struct V_4 * V_4 )
{
struct V_100 * V_101 = V_4 -> V_109 ;
int V_82 = 0 ;
if ( ! F_44 ( V_4 , V_122 ) )
V_82 = F_62 ( V_4 , V_101 -> V_106 , V_101 -> V_107 ,
V_101 -> V_108 , F_69 ( V_4 ) == V_123 ,
0 , V_101 -> V_105 ) ;
F_60 ( V_101 ) ;
F_39 ( V_4 ) ;
return V_82 ;
}
struct V_4 * F_70 ( struct V_69 * V_70 ,
struct V_124 * V_125 ,
struct V_102 * V_103 , int V_104 ,
int V_126 , T_1 V_35 )
{
struct V_100 * V_101 ;
struct V_28 * V_92 ;
struct V_87 * V_87 ;
struct V_4 * V_4 ;
int V_8 , V_82 ;
int V_85 = 0 ;
unsigned int V_88 = 0 ;
unsigned int V_89 = V_125 ? V_125 -> V_89 & ~ V_127 : 0 ;
for ( V_8 = 0 ; V_8 < V_104 ; V_8 ++ ) {
unsigned long V_128 ;
unsigned long V_129 ;
unsigned long V_130 ;
V_128 = ( unsigned long ) V_103 [ V_8 ] . V_119 ;
V_129 = ( V_128 + V_103 [ V_8 ] . V_121 + V_86 - 1 ) >> V_131 ;
V_130 = V_128 >> V_131 ;
if ( V_129 < V_130 )
return F_71 ( - V_132 ) ;
V_85 += V_129 - V_130 ;
V_88 += V_103 [ V_8 ] . V_121 ;
}
if ( V_89 )
V_85 ++ ;
V_101 = F_61 ( V_85 , V_104 , V_35 ) ;
if ( ! V_101 )
return F_71 ( - V_133 ) ;
V_82 = - V_133 ;
V_4 = F_32 ( V_35 , V_85 ) ;
if ( ! V_4 )
goto V_134;
if ( ! V_126 )
V_4 -> V_77 |= V_135 ;
V_82 = 0 ;
if ( V_125 ) {
V_85 = 1 << V_125 -> V_136 ;
V_8 = V_125 -> V_89 / V_86 ;
}
while ( V_88 ) {
unsigned int V_117 = V_86 ;
V_117 -= V_89 ;
if ( V_117 > V_88 )
V_117 = V_88 ;
if ( V_125 ) {
if ( V_8 == V_125 -> V_137 * V_85 ) {
V_82 = - V_133 ;
break;
}
V_87 = V_125 -> V_138 [ V_8 / V_85 ] ;
V_87 += ( V_8 % V_85 ) ;
V_8 ++ ;
} else {
V_87 = F_72 ( V_70 -> V_139 | V_35 ) ;
if ( ! V_87 ) {
V_82 = - V_133 ;
break;
}
}
if ( F_56 ( V_70 , V_4 , V_87 , V_117 , V_89 ) < V_117 )
break;
V_88 -= V_117 ;
V_89 = 0 ;
}
if ( V_82 )
goto V_140;
if ( ( ! V_126 && ( ! V_125 || ! V_125 -> V_141 ) ) ||
( V_125 && V_125 -> V_112 ) ) {
V_82 = F_62 ( V_4 , V_4 -> V_47 , V_103 , V_104 , 0 , 1 , 0 ) ;
if ( V_82 )
goto V_140;
}
F_59 ( V_101 , V_4 , V_103 , V_104 , V_125 ? 0 : 1 ) ;
return V_4 ;
V_140:
if ( ! V_125 )
F_35 (bvec, bio, i)
F_67 ( V_92 -> V_67 ) ;
F_39 ( V_4 ) ;
V_134:
F_60 ( V_101 ) ;
return F_71 ( V_82 ) ;
}
struct V_4 * F_73 ( struct V_69 * V_70 , struct V_124 * V_125 ,
unsigned long V_128 , unsigned int V_88 ,
int V_126 , T_1 V_35 )
{
struct V_102 V_103 ;
V_103 . V_119 = ( void T_2 * ) V_128 ;
V_103 . V_121 = V_88 ;
return F_70 ( V_70 , V_125 , & V_103 , 1 , V_126 , V_35 ) ;
}
static struct V_4 * F_74 ( struct V_69 * V_70 ,
struct V_83 * V_84 ,
struct V_102 * V_103 , int V_104 ,
int V_126 , T_1 V_35 )
{
int V_8 , V_142 ;
int V_85 = 0 ;
struct V_87 * * V_138 ;
struct V_4 * V_4 ;
int V_143 = 0 ;
int V_82 , V_89 ;
for ( V_8 = 0 ; V_8 < V_104 ; V_8 ++ ) {
unsigned long V_128 = ( unsigned long ) V_103 [ V_8 ] . V_119 ;
unsigned long V_88 = V_103 [ V_8 ] . V_121 ;
unsigned long V_129 = ( V_128 + V_88 + V_86 - 1 ) >> V_131 ;
unsigned long V_130 = V_128 >> V_131 ;
if ( V_129 < V_130 )
return F_71 ( - V_132 ) ;
V_85 += V_129 - V_130 ;
if ( V_128 & F_75 ( V_70 ) )
return F_71 ( - V_132 ) ;
}
if ( ! V_85 )
return F_71 ( - V_132 ) ;
V_4 = F_32 ( V_35 , V_85 ) ;
if ( ! V_4 )
return F_71 ( - V_133 ) ;
V_82 = - V_133 ;
V_138 = F_76 ( V_85 , sizeof( struct V_87 * ) , V_35 ) ;
if ( ! V_138 )
goto V_24;
for ( V_8 = 0 ; V_8 < V_104 ; V_8 ++ ) {
unsigned long V_128 = ( unsigned long ) V_103 [ V_8 ] . V_119 ;
unsigned long V_88 = V_103 [ V_8 ] . V_121 ;
unsigned long V_129 = ( V_128 + V_88 + V_86 - 1 ) >> V_131 ;
unsigned long V_130 = V_128 >> V_131 ;
const int V_144 = V_129 - V_130 ;
const int V_145 = V_143 + V_144 ;
V_82 = F_77 ( V_128 , V_144 ,
V_126 , & V_138 [ V_143 ] ) ;
if ( V_82 < V_144 ) {
V_82 = - V_120 ;
goto V_146;
}
V_89 = V_128 & ~ V_127 ;
for ( V_142 = V_143 ; V_142 < V_145 ; V_142 ++ ) {
unsigned int V_117 = V_86 - V_89 ;
if ( V_88 <= 0 )
break;
if ( V_117 > V_88 )
V_117 = V_88 ;
if ( F_56 ( V_70 , V_4 , V_138 [ V_142 ] , V_117 , V_89 ) <
V_117 )
break;
V_88 -= V_117 ;
V_89 = 0 ;
}
V_143 = V_142 ;
while ( V_142 < V_145 )
F_78 ( V_138 [ V_142 ++ ] ) ;
}
F_31 ( V_138 ) ;
if ( ! V_126 )
V_4 -> V_77 |= V_135 ;
V_4 -> V_75 = V_84 ;
V_4 -> V_50 |= ( 1 << V_147 ) ;
return V_4 ;
V_146:
for ( V_8 = 0 ; V_8 < V_85 ; V_8 ++ ) {
if( ! V_138 [ V_8 ] )
break;
F_78 ( V_138 [ V_8 ] ) ;
}
V_24:
F_31 ( V_138 ) ;
F_39 ( V_4 ) ;
return F_71 ( V_82 ) ;
}
struct V_4 * F_79 ( struct V_69 * V_70 , struct V_83 * V_84 ,
unsigned long V_128 , unsigned int V_88 , int V_126 ,
T_1 V_35 )
{
struct V_102 V_103 ;
V_103 . V_119 = ( void T_2 * ) V_128 ;
V_103 . V_121 = V_88 ;
return F_80 ( V_70 , V_84 , & V_103 , 1 , V_126 , V_35 ) ;
}
struct V_4 * F_80 ( struct V_69 * V_70 , struct V_83 * V_84 ,
struct V_102 * V_103 , int V_104 ,
int V_126 , T_1 V_35 )
{
struct V_4 * V_4 ;
V_4 = F_74 ( V_70 , V_84 , V_103 , V_104 , V_126 ,
V_35 ) ;
if ( F_81 ( V_4 ) )
return V_4 ;
F_82 ( V_4 ) ;
return V_4 ;
}
static void F_83 ( struct V_4 * V_4 )
{
struct V_28 * V_92 ;
int V_8 ;
F_63 (bvec, bio, i, 0 ) {
if ( F_69 ( V_4 ) == V_123 )
F_84 ( V_92 -> V_67 ) ;
F_78 ( V_92 -> V_67 ) ;
}
F_39 ( V_4 ) ;
}
void F_85 ( struct V_4 * V_4 )
{
F_83 ( V_4 ) ;
F_39 ( V_4 ) ;
}
static void F_86 ( struct V_4 * V_4 , int V_148 )
{
F_39 ( V_4 ) ;
}
static struct V_4 * F_87 ( struct V_69 * V_70 , void * V_65 ,
unsigned int V_88 , T_1 V_35 )
{
unsigned long V_149 = ( unsigned long ) V_65 ;
unsigned long V_129 = ( V_149 + V_88 + V_86 - 1 ) >> V_131 ;
unsigned long V_130 = V_149 >> V_131 ;
const int V_85 = V_129 - V_130 ;
int V_89 , V_8 ;
struct V_4 * V_4 ;
V_4 = F_32 ( V_35 , V_85 ) ;
if ( ! V_4 )
return F_71 ( - V_133 ) ;
V_89 = F_88 ( V_149 ) ;
for ( V_8 = 0 ; V_8 < V_85 ; V_8 ++ ) {
unsigned int V_117 = V_86 - V_89 ;
if ( V_88 <= 0 )
break;
if ( V_117 > V_88 )
V_117 = V_88 ;
if ( F_56 ( V_70 , V_4 , F_89 ( V_65 ) , V_117 ,
V_89 ) < V_117 )
break;
V_65 += V_117 ;
V_88 -= V_117 ;
V_89 = 0 ;
}
V_4 -> V_150 = F_86 ;
return V_4 ;
}
struct V_4 * F_90 ( struct V_69 * V_70 , void * V_65 , unsigned int V_88 ,
T_1 V_35 )
{
struct V_4 * V_4 ;
V_4 = F_87 ( V_70 , V_65 , V_88 , V_35 ) ;
if ( F_81 ( V_4 ) )
return V_4 ;
if ( V_4 -> V_79 == V_88 )
return V_4 ;
F_39 ( V_4 ) ;
return F_71 ( - V_132 ) ;
}
static void F_91 ( struct V_4 * V_4 , int V_148 )
{
struct V_28 * V_92 ;
const int V_151 = F_69 ( V_4 ) == V_123 ;
struct V_100 * V_101 = V_4 -> V_109 ;
int V_8 ;
char * V_46 = V_101 -> V_107 [ 0 ] . V_119 ;
F_63 (bvec, bio, i, 0 ) {
char * V_152 = F_64 ( V_92 -> V_67 ) ;
int V_88 = V_101 -> V_106 [ V_8 ] . V_66 ;
if ( V_151 )
memcpy ( V_46 , V_152 , V_88 ) ;
F_67 ( V_92 -> V_67 ) ;
V_46 += V_88 ;
}
F_60 ( V_101 ) ;
F_39 ( V_4 ) ;
}
struct V_4 * F_92 ( struct V_69 * V_70 , void * V_65 , unsigned int V_88 ,
T_1 V_35 , int V_153 )
{
struct V_4 * V_4 ;
struct V_28 * V_92 ;
int V_8 ;
V_4 = F_73 ( V_70 , NULL , ( unsigned long ) V_65 , V_88 , 1 , V_35 ) ;
if ( F_81 ( V_4 ) )
return V_4 ;
if ( ! V_153 ) {
void * V_46 = V_65 ;
F_35 (bvec, bio, i) {
char * V_152 = F_64 ( V_92 -> V_67 ) ;
memcpy ( V_152 , V_46 , V_92 -> V_66 ) ;
V_46 += V_92 -> V_66 ;
}
}
V_4 -> V_150 = F_91 ;
return V_4 ;
}
void F_93 ( struct V_4 * V_4 )
{
struct V_28 * V_92 = V_4 -> V_47 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_4 -> V_78 ; V_8 ++ ) {
struct V_87 * V_87 = V_92 [ V_8 ] . V_67 ;
if ( V_87 && ! F_94 ( V_87 ) )
F_84 ( V_87 ) ;
}
}
static void F_95 ( struct V_4 * V_4 )
{
struct V_28 * V_92 = V_4 -> V_47 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_4 -> V_78 ; V_8 ++ ) {
struct V_87 * V_87 = V_92 [ V_8 ] . V_67 ;
if ( V_87 )
F_96 ( V_87 ) ;
}
}
static void F_97 ( struct V_154 * V_155 )
{
unsigned long V_64 ;
struct V_4 * V_4 ;
F_98 ( & V_156 , V_64 ) ;
V_4 = V_157 ;
V_157 = NULL ;
F_99 ( & V_156 , V_64 ) ;
while ( V_4 ) {
struct V_4 * V_158 = V_4 -> V_109 ;
F_93 ( V_4 ) ;
F_95 ( V_4 ) ;
F_39 ( V_4 ) ;
V_4 = V_158 ;
}
}
void F_100 ( struct V_4 * V_4 )
{
struct V_28 * V_92 = V_4 -> V_47 ;
int V_159 = 0 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_4 -> V_78 ; V_8 ++ ) {
struct V_87 * V_87 = V_92 [ V_8 ] . V_67 ;
if ( F_101 ( V_87 ) || F_94 ( V_87 ) ) {
F_78 ( V_87 ) ;
V_92 [ V_8 ] . V_67 = NULL ;
} else {
V_159 ++ ;
}
}
if ( V_159 ) {
unsigned long V_64 ;
F_98 ( & V_156 , V_64 ) ;
V_4 -> V_109 = V_157 ;
V_157 = V_4 ;
F_99 ( & V_156 , V_64 ) ;
F_102 ( & V_160 ) ;
} else {
F_39 ( V_4 ) ;
}
}
void F_103 ( struct V_4 * V_161 )
{
int V_8 ;
struct V_28 * V_92 ;
F_35 (bvec, bi, i)
F_37 ( V_92 -> V_67 ) ;
}
void F_104 ( struct V_4 * V_4 , int error )
{
if ( error )
F_105 ( V_51 , & V_4 -> V_50 ) ;
else if ( ! F_106 ( V_51 , & V_4 -> V_50 ) )
error = - V_162 ;
if ( V_4 -> V_150 )
V_4 -> V_150 ( V_4 , error ) ;
}
void F_107 ( struct V_163 * V_164 )
{
if ( F_41 ( & V_164 -> V_165 ) ) {
struct V_4 * V_166 = V_164 -> V_167 . V_109 ;
F_104 ( V_166 , V_164 -> error ) ;
F_14 ( V_164 , V_164 -> V_168 . V_109 ) ;
}
}
static void F_108 ( struct V_4 * V_161 , int V_148 )
{
struct V_163 * V_164 = F_109 ( V_161 , struct V_163 , V_167 ) ;
if ( V_148 )
V_164 -> error = V_148 ;
F_107 ( V_164 ) ;
}
static void F_110 ( struct V_4 * V_161 , int V_148 )
{
struct V_163 * V_164 = F_109 ( V_161 , struct V_163 , V_168 ) ;
if ( V_148 )
V_164 -> error = V_148 ;
F_107 ( V_164 ) ;
}
struct V_163 * F_111 ( struct V_4 * V_161 , int V_169 )
{
struct V_163 * V_164 = F_17 ( V_170 , V_171 ) ;
if ( ! V_164 )
return V_164 ;
F_112 ( F_50 ( V_161 -> V_75 ) , V_161 ,
V_161 -> V_74 + V_169 ) ;
F_113 ( V_161 -> V_78 != 1 ) ;
F_113 ( V_161 -> V_80 != 0 ) ;
F_26 ( & V_164 -> V_165 , 3 ) ;
V_164 -> error = 0 ;
V_164 -> V_167 = * V_161 ;
V_164 -> V_168 = * V_161 ;
V_164 -> V_168 . V_74 += V_169 ;
V_164 -> V_168 . V_79 -= V_169 << 9 ;
V_164 -> V_167 . V_79 = V_169 << 9 ;
V_164 -> V_172 = V_161 -> V_47 [ 0 ] ;
V_164 -> V_173 = V_161 -> V_47 [ 0 ] ;
V_164 -> V_173 . V_94 += V_169 << 9 ;
V_164 -> V_173 . V_66 -= V_169 << 9 ;
V_164 -> V_172 . V_66 = V_169 << 9 ;
V_164 -> V_167 . V_47 = & V_164 -> V_172 ;
V_164 -> V_168 . V_47 = & V_164 -> V_173 ;
V_164 -> V_167 . V_60 = 1 ;
V_164 -> V_168 . V_60 = 1 ;
V_164 -> V_167 . V_150 = F_108 ;
V_164 -> V_168 . V_150 = F_110 ;
V_164 -> V_167 . V_109 = V_161 ;
V_164 -> V_168 . V_109 = V_170 ;
if ( F_23 ( V_161 ) )
F_114 ( V_161 , V_164 , V_169 ) ;
return V_164 ;
}
T_3 F_115 ( struct V_4 * V_4 , unsigned short V_174 ,
unsigned int V_89 )
{
unsigned int V_175 ;
struct V_28 * V_29 ;
T_3 V_176 ;
int V_8 ;
V_175 = F_116 ( V_4 -> V_75 -> V_177 -> V_178 ) ;
V_176 = 0 ;
if ( V_174 >= V_4 -> V_80 )
V_174 = V_4 -> V_78 - 1 ;
F_63 (bv, bio, i, 0 ) {
if ( V_8 == V_174 ) {
if ( V_89 > V_29 -> V_94 )
V_176 += ( V_89 - V_29 -> V_94 ) / V_175 ;
break;
}
V_176 += V_29 -> V_66 / V_175 ;
}
return V_176 ;
}
static int F_117 ( struct V_21 * V_22 , int V_179 )
{
struct V_33 * V_164 = V_26 + V_31 ;
V_22 -> V_32 = F_118 ( V_179 , V_164 -> V_5 ) ;
if ( ! V_22 -> V_32 )
return - V_133 ;
return 0 ;
}
static void F_119 ( struct V_21 * V_22 )
{
F_120 ( V_22 -> V_32 ) ;
}
void F_121 ( struct V_21 * V_22 )
{
if ( V_22 -> V_49 )
F_120 ( V_22 -> V_49 ) ;
F_122 ( V_22 ) ;
F_119 ( V_22 ) ;
F_7 ( V_22 ) ;
F_31 ( V_22 ) ;
}
struct V_21 * F_123 ( unsigned int V_180 , unsigned int V_48 )
{
unsigned int V_181 = V_56 * sizeof( struct V_28 ) ;
struct V_21 * V_22 ;
V_22 = F_124 ( sizeof( * V_22 ) , V_17 ) ;
if ( ! V_22 )
return NULL ;
V_22 -> V_48 = V_48 ;
V_22 -> V_6 = F_1 ( V_48 + V_181 ) ;
if ( ! V_22 -> V_6 ) {
F_31 ( V_22 ) ;
return NULL ;
}
V_22 -> V_49 = F_118 ( V_180 , V_22 -> V_6 ) ;
if ( ! V_22 -> V_49 )
goto V_182;
if ( ! F_117 ( V_22 , V_180 ) )
return V_22 ;
V_182:
F_121 ( V_22 ) ;
return NULL ;
}
int F_125 ( struct V_4 * V_4 )
{
struct V_183 * V_184 ;
struct V_185 * V_186 ;
if ( V_4 -> V_187 )
return - V_188 ;
V_184 = V_189 -> V_183 ;
if ( ! V_184 )
return - V_190 ;
F_126 ( V_184 ) ;
V_4 -> V_187 = V_184 ;
F_127 () ;
V_186 = F_128 ( V_189 , V_191 ) ;
if ( V_186 && F_129 ( V_186 ) )
V_4 -> V_192 = V_186 ;
F_130 () ;
return 0 ;
}
void F_42 ( struct V_4 * V_4 )
{
if ( V_4 -> V_187 ) {
F_131 ( V_4 -> V_187 ) ;
V_4 -> V_187 = NULL ;
}
if ( V_4 -> V_192 ) {
F_132 ( V_4 -> V_192 ) ;
V_4 -> V_192 = NULL ;
}
}
static void T_4 F_133 ( void )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_30 ; V_8 ++ ) {
int V_193 ;
struct V_33 * V_34 = V_26 + V_8 ;
if ( V_34 -> V_27 <= V_56 ) {
V_34 -> V_5 = NULL ;
continue;
}
V_193 = V_34 -> V_27 * sizeof( struct V_28 ) ;
V_34 -> V_5 = F_4 ( V_34 -> V_18 , V_193 , 0 ,
V_19 | V_194 , NULL ) ;
}
}
static int T_4 F_134 ( void )
{
V_16 = 2 ;
V_11 = 0 ;
V_12 = F_124 ( V_16 * sizeof( struct V_6 ) , V_17 ) ;
if ( ! V_12 )
F_135 ( L_4 ) ;
F_136 () ;
F_133 () ;
V_61 = F_123 ( V_195 , 0 ) ;
if ( ! V_61 )
F_135 ( L_4 ) ;
if ( F_137 ( V_61 , V_195 ) )
F_135 ( L_5 ) ;
V_170 = F_138 ( V_196 ,
sizeof( struct V_163 ) ) ;
if ( ! V_170 )
F_135 ( L_6 ) ;
return 0 ;
}
