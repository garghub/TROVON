static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , T_1 V_6 ,
T_1 V_5 , T_1 V_7 )
{
T_1 V_8 ;
V_8 = F_1 ( V_2 , V_6 ) ;
V_8 &= ~ V_7 ;
V_8 |= V_5 ;
F_3 ( V_2 , V_6 , V_8 ) ;
}
static inline int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_9 )
{
unsigned long V_10 = V_11 + V_12 ;
while ( ! ( F_1 ( V_2 , V_3 ) & V_9 ) ) {
if ( F_7 ( V_10 ) )
return - V_13 ;
}
return 0 ;
}
static void F_8 ( struct V_14 * V_15 , int V_16 )
{
struct V_17 * V_18 = F_9 ( V_15 ) ;
struct V_1 * V_2 = V_18 -> V_2 ;
T_1 * V_19 = ( T_1 * ) V_18 -> V_20 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_22 -> V_23 / sizeof( T_1 ) ; V_21 ++ ) {
if ( V_16 )
V_19 [ V_21 ] = F_1 ( V_2 , F_10 ( V_2 , V_21 ) ) ;
else
F_3 ( V_2 , F_10 ( V_2 , V_21 ) , V_19 [ V_21 ] ) ;
}
}
static void F_11 ( struct V_14 * V_15 , int V_16 )
{
struct V_17 * V_18 = F_9 ( V_15 ) ;
struct V_1 * V_2 = V_18 -> V_2 ;
int V_21 ;
if ( V_18 -> V_24 & F_12 ( V_25 ) ) {
struct V_26 * V_27 = F_13 ( V_2 -> V_15 ) ;
struct V_28 * V_29 = F_14 ( V_27 ) ;
struct V_30 * V_31 = V_29 -> V_32 ;
T_1 * V_33 = ( T_1 * ) V_31 -> V_33 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_22 -> V_23 / sizeof( T_1 ) ; V_21 ++ ) {
if ( V_16 )
V_33 [ V_21 ] = F_1 ( V_2 ,
F_15 ( V_2 , V_21 ) ) ;
else
F_3 ( V_2 , F_15 ( V_2 , V_21 ) ,
V_33 [ V_21 ] ) ;
}
}
F_8 ( V_15 , V_16 ) ;
}
static void F_16 ( struct V_14 * V_15 )
{
struct V_17 * V_18 = F_9 ( V_15 ) ;
T_1 * V_34 = ( T_1 * ) V_18 -> V_20 ;
T_1 * V_19 = ( T_1 * ) V_15 -> V_35 ;
int V_21 , V_36 , V_37 = 0 ;
if ( ! V_19 )
return;
switch ( V_18 -> V_24 & V_38 ) {
case V_39 :
V_36 = V_40 / sizeof( T_1 ) ;
break;
case V_41 :
if ( F_17 ( V_42 , & V_18 -> V_2 -> V_24 ) )
V_37 = 1 ;
V_36 = V_43 / sizeof( T_1 ) ;
break;
case V_44 :
V_36 = V_45 / sizeof( T_1 ) ;
break;
case V_46 :
V_36 = V_47 / sizeof( T_1 ) ;
break;
case V_48 :
V_36 = V_49 / sizeof( T_1 ) ;
break;
case V_50 :
V_36 = V_51 / sizeof( T_1 ) ;
break;
default:
V_36 = 0 ;
}
if ( V_37 )
for ( V_21 = 0 ; V_21 < V_36 ; V_21 ++ )
V_19 [ V_21 ] = F_18 ( V_34 [ V_21 ] ) ;
else
for ( V_21 = 0 ; V_21 < V_36 ; V_21 ++ )
V_19 [ V_21 ] = F_19 ( V_34 [ V_21 ] ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_52 ;
V_52 = F_21 ( V_2 -> V_53 ) ;
if ( V_52 < 0 ) {
F_22 ( V_2 -> V_53 , L_1 , V_52 ) ;
return V_52 ;
}
if ( ! F_17 ( V_54 , & V_2 -> V_24 ) ) {
F_23 ( V_54 , & V_2 -> V_24 ) ;
V_2 -> V_52 = 0 ;
}
return 0 ;
}
static void F_24 ( struct V_1 * V_2 , T_2 V_55 ,
int V_56 , int V_57 )
{
struct V_17 * V_18 = F_9 ( V_2 -> V_15 ) ;
T_1 V_8 = V_55 << 5 , V_7 ;
if ( F_25 ( V_18 -> V_58 ) )
F_3 ( V_2 , F_26 ( V_2 ) , V_18 -> V_58 ) ;
F_5 ( V_2 , F_27 ( V_2 ) ,
V_59 | ( V_57 ? V_60 : 0 ) ,
V_59 | V_60 ) ;
if ( ( V_18 -> V_24 & V_38 ) == V_41 )
V_8 |= V_61 ;
if ( ! V_18 -> V_58 )
V_8 |= V_62 ;
if ( V_56 )
V_8 |= V_63 ;
V_7 = V_62 | V_63 |
V_61 | V_64 ;
F_5 ( V_2 , V_65 , V_8 , V_7 ) ;
}
static void F_28 ( struct V_1 * V_2 , T_2 V_55 )
{
}
static int F_29 ( struct V_1 * V_2 )
{
return F_6 ( V_2 , V_65 , V_66 ) ;
}
static int F_30 ( struct V_17 * V_18 )
{
int V_36 ;
switch ( V_18 -> V_24 & V_38 ) {
case V_39 :
case V_41 :
V_36 = V_67 ;
break;
case V_44 :
case V_46 :
V_36 = V_68 ;
break;
case V_48 :
case V_50 :
V_36 = V_69 ;
break;
default:
V_36 = 0 ;
}
return V_36 ;
}
static void F_31 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 * V_5 , int V_70 )
{
for (; V_70 -- ; V_5 ++ , V_3 += 4 )
F_3 ( V_2 , V_3 , * V_5 ) ;
}
static void F_32 ( struct V_1 * V_2 , T_2 V_55 ,
int V_56 , int V_57 )
{
struct V_17 * V_18 = F_9 ( V_2 -> V_15 ) ;
T_1 V_8 , V_7 ;
V_8 = ( V_18 -> V_24 & V_38 ) >> ( V_71 ) ;
if ( ! V_18 -> V_58 ) {
struct V_26 * V_27 = F_13 ( V_2 -> V_15 ) ;
struct V_28 * V_29 = F_14 ( V_27 ) ;
struct V_30 * V_31 = V_29 -> V_32 ;
int V_72 , V_73 ;
V_8 |= V_74 ;
if ( V_18 -> V_24 & F_12 ( V_25 ) ) {
V_72 = F_30 ( V_18 ) ;
V_73 = V_72 / ( 2 * sizeof( T_1 ) ) ;
V_8 |= V_75 ;
F_31 ( V_2 , F_15 ( V_2 , 0 ) ,
( T_1 * ) V_31 -> V_76 , V_73 ) ;
F_31 ( V_2 , F_10 ( V_2 , 0 ) ,
( T_1 * ) V_31 -> V_76 + V_73 , V_73 ) ;
V_18 -> V_58 += V_72 ;
}
}
if ( V_56 ) {
V_8 |= V_77 ;
if ( V_18 -> V_24 & F_12 ( V_25 ) )
V_8 |= V_78 ;
}
V_7 = V_74 | V_77 |
V_79 | V_78 |
V_75 ;
F_33 ( V_2 -> V_53 , L_2 , V_8 , V_18 -> V_24 ) ;
F_5 ( V_2 , F_34 ( V_2 ) , V_8 , V_7 ) ;
F_3 ( V_2 , V_80 , V_81 ) ;
F_5 ( V_2 , F_27 ( V_2 ) ,
V_59 |
( V_57 ? V_60 : 0 ) ,
V_59 | V_60 ) ;
}
static void F_35 ( struct V_1 * V_2 , T_2 V_55 )
{
F_3 ( V_2 , F_36 ( V_2 ) , V_55 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
return F_6 ( V_2 , V_82 ,
V_83 ) ;
}
static int F_38 ( struct V_1 * V_2 , T_2 V_55 ,
int V_56 )
{
struct V_17 * V_18 = F_9 ( V_2 -> V_15 ) ;
int V_70 , V_84 , V_85 , V_3 = 0 ;
const T_1 * V_86 ;
int V_87 ;
struct V_88 V_89 ;
F_33 ( V_2 -> V_53 , L_3 ,
V_18 -> V_58 , V_55 , V_56 ) ;
V_2 -> V_22 -> V_90 ( V_2 , V_55 , V_56 , 0 ) ;
V_2 -> V_22 -> V_91 ( V_2 , V_55 ) ;
V_18 -> V_58 += V_55 ;
V_18 -> V_92 -= V_55 ;
if ( V_56 )
F_23 ( V_93 , & V_2 -> V_24 ) ;
F_23 ( V_94 , & V_2 -> V_24 ) ;
V_84 = F_39 ( V_55 , sizeof( T_1 ) ) ;
V_85 = F_30 ( V_18 ) / sizeof( T_1 ) ;
F_40 ( & V_89 , V_18 -> V_95 , V_18 -> V_96 ,
V_97 | V_98 ) ;
V_87 = 0 ;
while ( V_84 ) {
if ( V_2 -> V_22 -> V_99 ( V_2 ) )
return - V_13 ;
for ( V_70 = 0 ; V_70 < F_41 ( V_84 , V_85 ) ; V_70 ++ , V_3 ++ ) {
if ( ! V_87 ) {
F_42 ( & V_89 ) ;
V_87 = V_89 . V_55 ;
if ( ! V_87 ) {
F_43 ( L_4 ) ;
return - V_100 ;
}
V_3 = 0 ;
V_86 = V_89 . V_101 ;
}
F_3 ( V_2 , F_44 ( V_2 , V_70 ) ,
V_86 [ V_3 ] ) ;
V_87 -= 4 ;
}
V_84 -= F_41 ( V_84 , V_85 ) ;
}
F_45 ( & V_89 ) ;
return - V_102 ;
}
static void F_46 ( void * V_103 )
{
struct V_1 * V_2 = V_103 ;
F_23 ( V_104 , & V_2 -> V_24 ) ;
F_47 ( & V_2 -> V_105 ) ;
}
static int F_48 ( struct V_1 * V_2 , T_2 V_55 ,
int V_56 )
{
struct V_17 * V_18 = F_9 ( V_2 -> V_15 ) ;
struct V_106 * V_107 ;
struct V_108 V_109 ;
int V_110 ;
F_33 ( V_2 -> V_53 , L_5 ,
V_18 -> V_58 , V_55 , V_56 ) ;
if ( ! F_49 ( V_2 -> V_53 , V_18 -> V_95 , V_18 -> V_96 , V_111 ) ) {
F_22 ( V_2 -> V_53 , L_6 ) ;
return - V_100 ;
}
memset ( & V_109 , 0 , sizeof( V_109 ) ) ;
V_109 . V_112 = V_2 -> V_113 + F_44 ( V_2 , 0 ) ;
V_109 . V_114 = V_115 ;
V_109 . V_116 = F_30 ( V_18 ) / V_115 ;
V_110 = F_50 ( V_2 -> V_117 , & V_109 ) ;
if ( V_110 ) {
F_43 ( L_7 , V_110 ) ;
return V_110 ;
}
V_107 = F_51 ( V_2 -> V_117 , V_18 -> V_95 , V_18 -> V_96 ,
V_118 ,
V_119 | V_120 ) ;
if ( ! V_107 ) {
F_22 ( V_2 -> V_53 , L_8 ) ;
return - V_100 ;
}
V_107 -> V_121 = F_46 ;
V_107 -> V_122 = V_2 ;
V_2 -> V_22 -> V_90 ( V_2 , V_55 , V_56 , 1 ) ;
V_18 -> V_58 += V_55 ;
V_18 -> V_92 -= V_55 ;
if ( V_56 )
F_23 ( V_93 , & V_2 -> V_24 ) ;
F_23 ( V_123 , & V_2 -> V_24 ) ;
F_52 ( V_107 ) ;
F_53 ( V_2 -> V_117 ) ;
V_2 -> V_22 -> V_91 ( V_2 , V_55 ) ;
return - V_102 ;
}
static int F_54 ( struct V_17 * V_18 ,
struct V_124 * V_95 , int V_72 , int V_125 )
{
int V_126 = F_55 ( V_95 ) ;
struct V_124 * V_127 ;
int V_3 = V_18 -> V_3 ;
if ( V_18 -> V_128 )
V_126 ++ ;
V_18 -> V_95 = F_56 ( V_126 , sizeof( * V_95 ) , V_129 ) ;
if ( ! V_18 -> V_95 )
return - V_130 ;
F_57 ( V_18 -> V_95 , V_126 ) ;
V_127 = V_18 -> V_95 ;
V_18 -> V_96 = 0 ;
if ( V_18 -> V_128 ) {
F_58 ( V_127 , V_18 -> V_2 -> V_131 , V_18 -> V_128 ) ;
V_127 = F_59 ( V_127 ) ;
V_18 -> V_96 ++ ;
}
while ( V_95 && V_125 ) {
int V_132 = V_95 -> V_55 - V_3 ;
if ( V_3 ) {
V_3 -= V_95 -> V_55 ;
if ( V_3 < 0 )
V_3 = 0 ;
}
if ( V_125 < V_132 )
V_132 = V_125 ;
if ( V_132 > 0 ) {
V_125 -= V_132 ;
F_60 ( V_127 , F_61 ( V_95 ) , V_132 , V_95 -> V_3 ) ;
if ( V_125 <= 0 )
F_62 ( V_127 ) ;
V_127 = F_59 ( V_127 ) ;
V_18 -> V_96 ++ ;
}
V_95 = F_59 ( V_95 ) ;
}
F_23 ( V_133 , & V_18 -> V_2 -> V_24 ) ;
V_18 -> V_128 = 0 ;
return 0 ;
}
static int F_63 ( struct V_17 * V_18 ,
struct V_124 * V_95 , int V_72 , int V_125 )
{
int V_134 ;
void * V_135 ;
int V_132 ;
V_132 = V_125 + V_18 -> V_128 ;
V_134 = F_64 ( V_18 -> V_92 ) ;
V_135 = ( void * ) F_65 ( V_136 , V_134 ) ;
if ( ! V_135 ) {
F_43 ( L_9 ) ;
return - V_130 ;
}
if ( V_18 -> V_128 )
memcpy ( V_135 , V_18 -> V_2 -> V_131 , V_18 -> V_128 ) ;
F_66 ( V_135 + V_18 -> V_128 , V_95 , V_18 -> V_3 ,
V_18 -> V_92 - V_18 -> V_128 , 0 ) ;
F_57 ( V_18 -> V_137 , 1 ) ;
F_58 ( V_18 -> V_137 , V_135 , V_132 ) ;
V_18 -> V_95 = V_18 -> V_137 ;
F_23 ( V_138 , & V_18 -> V_2 -> V_24 ) ;
V_18 -> V_96 = 1 ;
V_18 -> V_128 = 0 ;
V_18 -> V_3 = 0 ;
return 0 ;
}
static int F_67 ( struct V_124 * V_95 ,
int V_139 , int V_72 , bool V_56 ,
struct V_17 * V_140 )
{
int V_126 = 0 ;
bool V_141 = true ;
bool V_142 = true ;
struct V_124 * V_143 = V_95 ;
int V_125 ;
int V_3 = V_140 -> V_3 ;
if ( ! V_95 || ! V_95 -> V_55 || ! V_139 )
return 0 ;
V_125 = V_139 ;
if ( V_3 )
V_142 = false ;
if ( V_56 )
V_125 = F_39 ( V_125 , V_72 ) * V_72 ;
else
V_125 = V_125 / V_72 * V_72 ;
while ( V_139 > 0 && V_143 ) {
V_126 ++ ;
if ( V_3 < V_143 -> V_55 ) {
if ( ! F_68 ( V_3 + V_143 -> V_3 , 4 ) ) {
V_141 = false ;
break;
}
if ( ! F_68 ( V_143 -> V_55 - V_3 , V_72 ) ) {
V_141 = false ;
break;
}
}
if ( V_3 ) {
V_3 -= V_143 -> V_55 ;
if ( V_3 < 0 ) {
V_139 += V_3 ;
V_3 = 0 ;
}
} else {
V_139 -= V_143 -> V_55 ;
}
V_143 = F_59 ( V_143 ) ;
if ( V_139 < 0 ) {
V_142 = false ;
break;
}
}
if ( ! V_141 )
return F_63 ( V_140 , V_95 , V_72 , V_125 ) ;
else if ( ! V_142 )
return F_54 ( V_140 , V_95 , V_72 , V_125 ) ;
V_140 -> V_96 = V_126 ;
V_140 -> V_95 = V_95 ;
return 0 ;
}
static int F_69 ( struct V_14 * V_15 , bool V_144 )
{
struct V_17 * V_140 = F_9 ( V_15 ) ;
int V_72 ;
int V_110 ;
int V_139 ;
bool V_56 = V_140 -> V_24 & F_12 ( V_145 ) ;
int V_146 , V_147 ;
if ( ! V_15 )
return 0 ;
V_72 = F_30 ( V_140 ) ;
if ( V_144 )
V_139 = V_15 -> V_139 ;
else
V_139 = 0 ;
V_140 -> V_92 = V_139 + V_140 -> V_128 ;
if ( ! V_140 -> V_92 )
return 0 ;
if ( V_139 && ( ! F_68 ( V_140 -> V_128 , V_72 ) ) ) {
int V_132 = V_72 - V_140 -> V_128 % V_72 ;
if ( V_132 > V_139 )
V_132 = V_139 ;
F_66 ( V_140 -> V_86 + V_140 -> V_128 , V_15 -> V_148 ,
0 , V_132 , 0 ) ;
V_140 -> V_128 += V_132 ;
V_139 -= V_132 ;
V_140 -> V_3 = V_132 ;
}
if ( V_140 -> V_128 )
memcpy ( V_140 -> V_2 -> V_131 , V_140 -> V_86 , V_140 -> V_128 ) ;
V_110 = F_67 ( V_15 -> V_148 , V_139 , V_72 , V_56 , V_140 ) ;
if ( V_110 )
return V_110 ;
V_146 = V_140 -> V_92 ;
if ( ! F_68 ( V_146 , V_72 ) ) {
if ( V_56 )
V_146 = F_39 ( V_146 , V_72 ) * V_72 ;
else
V_146 = V_146 / V_72 * V_72 ;
}
V_147 = V_140 -> V_92 - V_146 ;
if ( V_147 < 0 )
V_147 = 0 ;
if ( V_140 -> V_128 && V_139 ) {
F_57 ( V_140 -> V_137 , 2 ) ;
F_58 ( V_140 -> V_137 , V_140 -> V_2 -> V_131 , V_140 -> V_128 ) ;
F_70 ( V_140 -> V_137 , 2 , V_15 -> V_148 ) ;
V_140 -> V_95 = V_140 -> V_137 ;
V_140 -> V_96 ++ ;
} else if ( V_140 -> V_128 ) {
F_57 ( V_140 -> V_137 , 1 ) ;
F_58 ( V_140 -> V_137 , V_140 -> V_2 -> V_131 , V_146 ) ;
V_140 -> V_95 = V_140 -> V_137 ;
V_140 -> V_96 = 1 ;
}
if ( V_147 ) {
if ( V_15 -> V_139 ) {
F_66 ( V_140 -> V_86 , V_15 -> V_148 ,
V_15 -> V_139 - V_147 ,
V_147 , 0 ) ;
} else {
memcpy ( V_140 -> V_86 , V_140 -> V_86 + V_146 ,
V_147 ) ;
}
V_140 -> V_128 = V_147 ;
} else {
V_140 -> V_128 = 0 ;
}
if ( ! V_56 )
V_140 -> V_92 = V_146 ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_9 ( V_2 -> V_15 ) ;
F_72 ( V_2 -> V_53 , V_18 -> V_95 , V_18 -> V_96 , V_111 ) ;
F_73 ( V_123 , & V_2 -> V_24 ) ;
return 0 ;
}
static int F_74 ( struct V_14 * V_15 )
{
struct V_26 * V_27 = F_13 ( V_15 ) ;
struct V_28 * V_29 = F_14 ( V_27 ) ;
struct V_17 * V_18 = F_9 ( V_15 ) ;
struct V_1 * V_2 = NULL , * V_127 ;
int V_72 = 0 ;
F_75 ( & V_149 . V_150 ) ;
if ( ! V_29 -> V_2 ) {
F_76 (tmp, &sham.dev_list, list) {
V_2 = V_127 ;
break;
}
V_29 -> V_2 = V_2 ;
} else {
V_2 = V_29 -> V_2 ;
}
F_77 ( & V_149 . V_150 ) ;
V_18 -> V_2 = V_2 ;
V_18 -> V_24 = 0 ;
F_33 ( V_2 -> V_53 , L_10 ,
F_78 ( V_27 ) ) ;
switch ( F_78 ( V_27 ) ) {
case V_40 :
V_18 -> V_24 |= V_39 ;
V_72 = V_67 ;
break;
case V_43 :
V_18 -> V_24 |= V_41 ;
V_72 = V_67 ;
break;
case V_45 :
V_18 -> V_24 |= V_44 ;
V_72 = V_151 ;
break;
case V_47 :
V_18 -> V_24 |= V_46 ;
V_72 = V_68 ;
break;
case V_49 :
V_18 -> V_24 |= V_48 ;
V_72 = V_152 ;
break;
case V_51 :
V_18 -> V_24 |= V_50 ;
V_72 = V_69 ;
break;
}
V_18 -> V_128 = 0 ;
V_18 -> V_58 = 0 ;
V_18 -> V_92 = 0 ;
V_18 -> V_3 = 0 ;
V_18 -> V_153 = V_154 ;
if ( V_29 -> V_24 & F_12 ( V_25 ) ) {
if ( ! F_17 ( V_155 , & V_2 -> V_24 ) ) {
struct V_30 * V_31 = V_29 -> V_32 ;
memcpy ( V_18 -> V_86 , V_31 -> V_76 , V_72 ) ;
V_18 -> V_128 = V_72 ;
}
V_18 -> V_24 |= F_12 ( V_25 ) ;
}
return 0 ;
}
static int F_79 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_17 * V_18 = F_9 ( V_15 ) ;
int V_52 ;
bool V_56 = V_18 -> V_24 & F_12 ( V_145 ) ;
F_33 ( V_2 -> V_53 , L_11 ,
V_18 -> V_92 , V_18 -> V_58 , ( V_18 -> V_24 & F_12 ( V_145 ) ) != 0 ) ;
if ( V_18 -> V_92 < F_30 ( V_18 ) ||
V_18 -> V_92 < V_156 )
V_18 -> V_24 |= F_12 ( V_94 ) ;
if ( V_18 -> V_24 & F_12 ( V_94 ) )
V_52 = F_38 ( V_2 , V_18 -> V_92 , V_56 ) ;
else
V_52 = F_48 ( V_2 , V_18 -> V_92 , V_56 ) ;
F_33 ( V_2 -> V_53 , L_12 , V_52 , V_18 -> V_58 ) ;
return V_52 ;
}
static int F_80 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_17 * V_18 = F_9 ( V_15 ) ;
int V_52 = 0 , V_157 = 1 ;
if ( ( V_18 -> V_92 <= F_30 ( V_18 ) ) || V_2 -> V_158 )
V_157 = 0 ;
if ( V_157 )
V_52 = F_48 ( V_2 , V_18 -> V_92 , 1 ) ;
else
V_52 = F_38 ( V_2 , V_18 -> V_92 , 1 ) ;
V_18 -> V_128 = 0 ;
F_33 ( V_2 -> V_53 , L_13 , V_52 ) ;
return V_52 ;
}
static int F_81 ( struct V_14 * V_15 )
{
struct V_28 * V_29 = F_82 ( V_15 -> V_32 . V_27 ) ;
struct V_30 * V_31 = V_29 -> V_32 ;
int V_72 = F_83 ( V_31 -> V_159 ) ;
int V_160 = F_84 ( V_31 -> V_159 ) ;
F_85 ( V_159 , V_31 -> V_159 ) ;
V_159 -> V_27 = V_31 -> V_159 ;
V_159 -> V_24 = 0 ;
return F_86 ( V_159 ) ? :
F_87 ( V_159 , V_31 -> V_33 , V_72 ) ? :
F_88 ( V_159 , V_15 -> V_35 , V_160 , V_15 -> V_35 ) ;
}
static int F_89 ( struct V_14 * V_15 )
{
struct V_17 * V_18 = F_9 ( V_15 ) ;
struct V_1 * V_2 = V_18 -> V_2 ;
int V_52 = 0 ;
if ( V_18 -> V_58 ) {
F_16 ( V_15 ) ;
if ( ( V_18 -> V_24 & F_12 ( V_25 ) ) &&
! F_17 ( V_155 , & V_2 -> V_24 ) )
V_52 = F_81 ( V_15 ) ;
}
F_33 ( V_2 -> V_53 , L_14 , V_18 -> V_58 , V_18 -> V_128 ) ;
return V_52 ;
}
static void F_90 ( struct V_14 * V_15 , int V_52 )
{
struct V_17 * V_18 = F_9 ( V_15 ) ;
struct V_1 * V_2 = V_18 -> V_2 ;
if ( F_17 ( V_138 , & V_2 -> V_24 ) )
F_91 ( ( unsigned long ) F_92 ( V_18 -> V_95 ) ,
F_64 ( V_18 -> V_95 -> V_55 ) ) ;
if ( F_17 ( V_133 , & V_2 -> V_24 ) )
F_93 ( V_18 -> V_95 ) ;
V_18 -> V_95 = NULL ;
V_2 -> V_24 &= ~ ( F_12 ( V_133 ) | F_12 ( V_138 ) ) ;
if ( ! V_52 ) {
V_2 -> V_22 -> V_161 ( V_15 , 1 ) ;
if ( F_17 ( V_93 , & V_2 -> V_24 ) )
V_52 = F_89 ( V_15 ) ;
} else {
V_18 -> V_24 |= F_12 ( V_162 ) ;
}
V_2 -> V_24 &= ~ ( F_12 ( V_163 ) | F_12 ( V_93 ) | F_12 ( V_94 ) |
F_12 ( V_104 ) | F_12 ( V_164 ) ) ;
F_94 ( V_2 -> V_53 ) ;
F_95 ( V_2 -> V_53 ) ;
if ( V_15 -> V_32 . V_165 )
V_15 -> V_32 . V_165 ( & V_15 -> V_32 , V_52 ) ;
}
static int F_96 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_166 * V_167 , * V_168 ;
struct V_17 * V_18 ;
unsigned long V_24 ;
int V_52 = 0 , V_110 = 0 ;
V_169:
F_97 ( & V_2 -> V_150 , V_24 ) ;
if ( V_15 )
V_110 = F_98 ( & V_2 -> V_170 , V_15 ) ;
if ( F_17 ( V_163 , & V_2 -> V_24 ) ) {
F_99 ( & V_2 -> V_150 , V_24 ) ;
return V_110 ;
}
V_168 = F_100 ( & V_2 -> V_170 ) ;
V_167 = F_101 ( & V_2 -> V_170 ) ;
if ( V_167 )
F_23 ( V_163 , & V_2 -> V_24 ) ;
F_99 ( & V_2 -> V_150 , V_24 ) ;
if ( ! V_167 )
return V_110 ;
if ( V_168 )
V_168 -> V_165 ( V_168 , - V_102 ) ;
V_15 = F_102 ( V_167 ) ;
V_2 -> V_15 = V_15 ;
V_18 = F_9 ( V_15 ) ;
V_52 = F_69 ( V_15 , V_18 -> V_171 == V_172 ) ;
if ( V_52 )
goto V_173;
F_33 ( V_2 -> V_53 , L_15 ,
V_18 -> V_171 , V_15 -> V_139 ) ;
V_52 = F_20 ( V_2 ) ;
if ( V_52 )
goto V_173;
if ( V_18 -> V_58 )
V_2 -> V_22 -> V_161 ( V_15 , 0 ) ;
if ( V_18 -> V_171 == V_172 ) {
V_52 = F_79 ( V_2 ) ;
if ( V_52 != - V_102 && ( V_18 -> V_24 & F_12 ( V_145 ) ) )
V_52 = F_80 ( V_2 ) ;
} else if ( V_18 -> V_171 == V_174 ) {
V_52 = F_80 ( V_2 ) ;
}
V_173:
F_33 ( V_2 -> V_53 , L_16 , V_52 ) ;
if ( V_52 != - V_102 ) {
F_90 ( V_15 , V_52 ) ;
V_15 = NULL ;
goto V_169;
}
return V_110 ;
}
static int F_103 ( struct V_14 * V_15 , unsigned int V_171 )
{
struct V_17 * V_18 = F_9 ( V_15 ) ;
struct V_28 * V_29 = F_82 ( V_15 -> V_32 . V_27 ) ;
struct V_1 * V_2 = V_29 -> V_2 ;
V_18 -> V_171 = V_171 ;
return F_96 ( V_2 , V_15 ) ;
}
static int F_104 ( struct V_14 * V_15 )
{
struct V_17 * V_18 = F_9 ( V_15 ) ;
struct V_1 * V_2 = V_18 -> V_2 ;
if ( ! V_15 -> V_139 )
return 0 ;
if ( V_18 -> V_92 + V_15 -> V_139 < V_18 -> V_153 ) {
F_66 ( V_18 -> V_86 + V_18 -> V_128 , V_15 -> V_148 ,
0 , V_15 -> V_139 , 0 ) ;
V_18 -> V_128 += V_15 -> V_139 ;
V_18 -> V_92 += V_15 -> V_139 ;
return 0 ;
}
if ( V_2 -> V_158 )
V_18 -> V_24 |= F_12 ( V_94 ) ;
return F_103 ( V_15 , V_172 ) ;
}
static int F_105 ( struct V_175 * V_27 , T_1 V_24 ,
const T_3 * V_176 , unsigned int V_132 , T_3 * V_16 )
{
F_85 ( V_159 , V_27 ) ;
V_159 -> V_27 = V_27 ;
V_159 -> V_24 = V_24 & V_177 ;
return F_106 ( V_159 , V_176 , V_132 , V_16 ) ;
}
static int F_107 ( struct V_14 * V_15 )
{
struct V_28 * V_29 = F_82 ( V_15 -> V_32 . V_27 ) ;
struct V_17 * V_18 = F_9 ( V_15 ) ;
int V_3 = 0 ;
if ( F_17 ( V_25 , & V_18 -> V_24 ) &&
! F_17 ( V_155 , & V_18 -> V_2 -> V_24 ) )
V_3 = F_30 ( V_18 ) ;
return F_105 ( V_29 -> V_178 , V_15 -> V_32 . V_24 ,
V_18 -> V_86 + V_3 ,
V_18 -> V_128 - V_3 , V_15 -> V_35 ) ;
}
static int F_108 ( struct V_14 * V_15 )
{
struct V_17 * V_18 = F_9 ( V_15 ) ;
V_18 -> V_24 |= F_12 ( V_145 ) ;
if ( V_18 -> V_24 & F_12 ( V_162 ) )
return 0 ;
if ( ! V_18 -> V_58 && V_18 -> V_128 < V_156 )
return F_107 ( V_15 ) ;
else if ( V_18 -> V_128 )
return F_103 ( V_15 , V_174 ) ;
return F_89 ( V_15 ) ;
}
static int F_109 ( struct V_14 * V_15 )
{
struct V_17 * V_18 = F_9 ( V_15 ) ;
int V_173 , V_179 ;
V_18 -> V_24 |= F_12 ( V_145 ) ;
V_173 = F_104 ( V_15 ) ;
if ( V_173 == - V_102 || V_173 == - V_180 )
return V_173 ;
V_179 = F_108 ( V_15 ) ;
return V_173 ? : V_179 ;
}
static int F_110 ( struct V_14 * V_15 )
{
return F_74 ( V_15 ) ? : F_109 ( V_15 ) ;
}
static int F_111 ( struct V_26 * V_27 , const T_3 * V_181 ,
unsigned int V_182 )
{
struct V_28 * V_29 = F_14 ( V_27 ) ;
struct V_30 * V_31 = V_29 -> V_32 ;
int V_72 = F_83 ( V_31 -> V_159 ) ;
int V_160 = F_84 ( V_31 -> V_159 ) ;
struct V_1 * V_2 = NULL , * V_127 ;
int V_52 , V_21 ;
F_75 ( & V_149 . V_150 ) ;
if ( ! V_29 -> V_2 ) {
F_76 (tmp, &sham.dev_list, list) {
V_2 = V_127 ;
break;
}
V_29 -> V_2 = V_2 ;
} else {
V_2 = V_29 -> V_2 ;
}
F_77 ( & V_149 . V_150 ) ;
V_52 = F_112 ( V_29 -> V_178 , V_181 , V_182 ) ;
if ( V_52 )
return V_52 ;
if ( V_182 > V_72 ) {
V_52 = F_105 ( V_31 -> V_159 ,
F_113 ( V_31 -> V_159 ) ,
V_181 , V_182 , V_31 -> V_76 ) ;
if ( V_52 )
return V_52 ;
V_182 = V_160 ;
} else {
memcpy ( V_31 -> V_76 , V_181 , V_182 ) ;
}
memset ( V_31 -> V_76 + V_182 , 0 , V_72 - V_182 ) ;
if ( ! F_17 ( V_155 , & V_2 -> V_24 ) ) {
memcpy ( V_31 -> V_33 , V_31 -> V_76 , V_72 ) ;
for ( V_21 = 0 ; V_21 < V_72 ; V_21 ++ ) {
V_31 -> V_76 [ V_21 ] ^= 0x36 ;
V_31 -> V_33 [ V_21 ] ^= 0x5c ;
}
}
return V_52 ;
}
static int F_114 ( struct V_183 * V_27 , const char * V_184 )
{
struct V_28 * V_29 = F_82 ( V_27 ) ;
const char * V_185 = F_115 ( V_27 ) ;
V_29 -> V_178 = F_116 ( V_185 , 0 ,
V_186 ) ;
if ( F_117 ( V_29 -> V_178 ) ) {
F_43 ( L_17
L_18 , V_185 ) ;
return F_118 ( V_29 -> V_178 ) ;
}
F_119 ( F_120 ( V_27 ) ,
sizeof( struct V_17 ) + V_154 ) ;
if ( V_184 ) {
struct V_30 * V_31 = V_29 -> V_32 ;
V_29 -> V_24 |= F_12 ( V_25 ) ;
V_31 -> V_159 = F_116 ( V_184 , 0 ,
V_186 ) ;
if ( F_117 ( V_31 -> V_159 ) ) {
F_43 ( L_19
L_18 , V_184 ) ;
F_121 ( V_29 -> V_178 ) ;
return F_118 ( V_31 -> V_159 ) ;
}
}
return 0 ;
}
static int F_122 ( struct V_183 * V_27 )
{
return F_114 ( V_27 , NULL ) ;
}
static int F_123 ( struct V_183 * V_27 )
{
return F_114 ( V_27 , L_20 ) ;
}
static int F_124 ( struct V_183 * V_27 )
{
return F_114 ( V_27 , L_21 ) ;
}
static int F_125 ( struct V_183 * V_27 )
{
return F_114 ( V_27 , L_22 ) ;
}
static int F_126 ( struct V_183 * V_27 )
{
return F_114 ( V_27 , L_23 ) ;
}
static int F_127 ( struct V_183 * V_27 )
{
return F_114 ( V_27 , L_24 ) ;
}
static int F_128 ( struct V_183 * V_27 )
{
return F_114 ( V_27 , L_25 ) ;
}
static void F_129 ( struct V_183 * V_27 )
{
struct V_28 * V_29 = F_82 ( V_27 ) ;
F_121 ( V_29 -> V_178 ) ;
V_29 -> V_178 = NULL ;
if ( V_29 -> V_24 & F_12 ( V_25 ) ) {
struct V_30 * V_31 = V_29 -> V_32 ;
F_121 ( V_31 -> V_159 ) ;
}
}
static int F_130 ( struct V_14 * V_15 , void * V_16 )
{
struct V_17 * V_140 = F_9 ( V_15 ) ;
memcpy ( V_16 , V_140 , sizeof( * V_140 ) + V_140 -> V_128 ) ;
return 0 ;
}
static int F_131 ( struct V_14 * V_15 , const void * V_34 )
{
struct V_17 * V_140 = F_9 ( V_15 ) ;
const struct V_17 * V_187 = V_34 ;
memcpy ( V_140 , V_34 , sizeof( * V_140 ) + V_187 -> V_128 ) ;
return 0 ;
}
static void F_132 ( unsigned long V_176 )
{
struct V_1 * V_2 = (struct V_1 * ) V_176 ;
int V_52 = 0 ;
if ( ! F_17 ( V_163 , & V_2 -> V_24 ) ) {
F_96 ( V_2 , NULL ) ;
return;
}
if ( F_17 ( V_94 , & V_2 -> V_24 ) ) {
if ( F_133 ( V_164 , & V_2 -> V_24 ) )
goto V_188;
} else if ( F_17 ( V_104 , & V_2 -> V_24 ) ) {
if ( F_133 ( V_123 , & V_2 -> V_24 ) ) {
F_71 ( V_2 ) ;
if ( V_2 -> V_52 ) {
V_52 = V_2 -> V_52 ;
goto V_188;
}
}
if ( F_133 ( V_164 , & V_2 -> V_24 ) ) {
F_73 ( V_104 , & V_2 -> V_24 ) ;
goto V_188;
}
}
return;
V_188:
F_33 ( V_2 -> V_53 , L_26 , V_52 ) ;
F_90 ( V_2 -> V_15 , V_52 ) ;
if ( ! F_17 ( V_163 , & V_2 -> V_24 ) )
F_96 ( V_2 , NULL ) ;
}
static T_4 F_134 ( struct V_1 * V_2 )
{
if ( ! F_17 ( V_163 , & V_2 -> V_24 ) ) {
F_135 ( V_2 -> V_53 , L_27 ) ;
} else {
F_23 ( V_164 , & V_2 -> V_24 ) ;
F_47 ( & V_2 -> V_105 ) ;
}
return V_189 ;
}
static T_4 F_136 ( int V_190 , void * V_191 )
{
struct V_1 * V_2 = V_191 ;
if ( F_137 ( F_17 ( V_93 , & V_2 -> V_24 ) ) )
F_5 ( V_2 , V_65 , 0 , V_64 ) ;
F_5 ( V_2 , V_65 , V_192 ,
V_192 ) ;
F_1 ( V_2 , V_65 ) ;
return F_134 ( V_2 ) ;
}
static T_4 F_138 ( int V_190 , void * V_191 )
{
struct V_1 * V_2 = V_191 ;
F_5 ( V_2 , F_27 ( V_2 ) , 0 , V_59 ) ;
return F_134 ( V_2 ) ;
}
static int F_139 ( struct V_1 * V_2 ,
struct V_193 * V_53 , struct V_194 * V_195 )
{
struct V_196 * V_197 = V_53 -> V_198 ;
const struct V_199 * V_200 ;
int V_52 = 0 ;
V_200 = F_140 ( F_141 ( V_201 ) , V_53 ) ;
if ( ! V_200 ) {
F_22 ( V_53 , L_28 ) ;
V_52 = - V_100 ;
goto V_52;
}
V_52 = F_142 ( V_197 , 0 , V_195 ) ;
if ( V_52 < 0 ) {
F_22 ( V_53 , L_29 ) ;
V_52 = - V_100 ;
goto V_52;
}
V_2 -> V_190 = F_143 ( V_197 , 0 ) ;
if ( ! V_2 -> V_190 ) {
F_22 ( V_53 , L_30 ) ;
V_52 = - V_100 ;
goto V_52;
}
V_2 -> V_22 = V_200 -> V_176 ;
V_52:
return V_52 ;
}
static int F_139 ( struct V_1 * V_2 ,
struct V_193 * V_53 , struct V_194 * V_195 )
{
return - V_100 ;
}
static int F_144 ( struct V_1 * V_2 ,
struct V_202 * V_203 , struct V_194 * V_195 )
{
struct V_193 * V_53 = & V_203 -> V_53 ;
struct V_194 * V_204 ;
int V_52 = 0 ;
V_204 = F_145 ( V_203 , V_205 , 0 ) ;
if ( ! V_204 ) {
F_22 ( V_53 , L_31 ) ;
V_52 = - V_206 ;
goto V_52;
}
memcpy ( V_195 , V_204 , sizeof( * V_195 ) ) ;
V_2 -> V_190 = F_146 ( V_203 , 0 ) ;
if ( V_2 -> V_190 < 0 ) {
F_22 ( V_53 , L_32 ) ;
V_52 = V_2 -> V_190 ;
goto V_52;
}
V_2 -> V_22 = & V_207 ;
V_52:
return V_52 ;
}
static int F_147 ( struct V_202 * V_203 )
{
struct V_1 * V_2 ;
struct V_193 * V_53 = & V_203 -> V_53 ;
struct V_194 V_195 ;
T_5 V_7 ;
int V_52 , V_21 , V_208 ;
T_1 V_209 ;
V_2 = F_148 ( V_53 , sizeof( struct V_1 ) , V_129 ) ;
if ( V_2 == NULL ) {
F_22 ( V_53 , L_33 ) ;
V_52 = - V_130 ;
goto V_210;
}
V_2 -> V_53 = V_53 ;
F_149 ( V_203 , V_2 ) ;
F_150 ( & V_2 -> V_211 ) ;
F_151 ( & V_2 -> V_150 ) ;
F_152 ( & V_2 -> V_105 , F_132 , ( unsigned long ) V_2 ) ;
F_153 ( & V_2 -> V_170 , V_212 ) ;
V_52 = ( V_53 -> V_198 ) ? F_139 ( V_2 , V_53 , & V_195 ) :
F_144 ( V_2 , V_203 , & V_195 ) ;
if ( V_52 )
goto V_210;
V_2 -> V_4 = F_154 ( V_53 , & V_195 ) ;
if ( F_117 ( V_2 -> V_4 ) ) {
V_52 = F_118 ( V_2 -> V_4 ) ;
goto V_210;
}
V_2 -> V_113 = V_195 . V_213 ;
V_52 = F_155 ( V_53 , V_2 -> V_190 , V_2 -> V_22 -> V_214 ,
V_215 , F_156 ( V_53 ) , V_2 ) ;
if ( V_52 ) {
F_22 ( V_53 , L_34 ,
V_2 -> V_190 , V_52 ) ;
goto V_210;
}
F_157 ( V_7 ) ;
F_158 ( V_216 , V_7 ) ;
V_2 -> V_117 = F_159 ( V_53 , L_35 ) ;
if ( F_117 ( V_2 -> V_117 ) ) {
V_52 = F_118 ( V_2 -> V_117 ) ;
if ( V_52 == - V_217 )
goto V_210;
V_2 -> V_158 = 1 ;
F_33 ( V_53 , L_36 ) ;
}
V_2 -> V_24 |= V_2 -> V_22 -> V_24 ;
F_160 ( V_53 ) ;
F_161 ( V_53 , V_218 ) ;
F_162 ( V_53 ) ;
F_163 ( V_53 ) ;
V_52 = F_21 ( V_53 ) ;
if ( V_52 < 0 ) {
F_22 ( V_53 , L_1 , V_52 ) ;
goto V_219;
}
V_209 = F_1 ( V_2 , F_164 ( V_2 ) ) ;
F_165 ( & V_203 -> V_53 ) ;
F_166 ( V_53 , L_37 ,
( V_209 & V_2 -> V_22 -> V_220 ) >> V_2 -> V_22 -> V_221 ,
( V_209 & V_2 -> V_22 -> V_222 ) >> V_2 -> V_22 -> V_223 ) ;
F_167 ( & V_149 . V_150 ) ;
F_168 ( & V_2 -> V_211 , & V_149 . V_224 ) ;
F_169 ( & V_149 . V_150 ) ;
for ( V_21 = 0 ; V_21 < V_2 -> V_22 -> V_225 ; V_21 ++ ) {
for ( V_208 = 0 ; V_208 < V_2 -> V_22 -> V_226 [ V_21 ] . V_227 ; V_208 ++ ) {
struct V_228 * V_229 ;
V_229 = & V_2 -> V_22 -> V_226 [ V_21 ] . V_230 [ V_208 ] ;
V_229 -> V_231 = F_130 ;
V_229 -> V_232 = F_131 ;
V_229 -> V_233 . V_234 = sizeof( struct V_17 ) +
V_154 ;
V_52 = F_170 ( V_229 ) ;
if ( V_52 )
goto V_235;
V_2 -> V_22 -> V_226 [ V_21 ] . V_236 ++ ;
}
}
return 0 ;
V_235:
for ( V_21 = V_2 -> V_22 -> V_225 - 1 ; V_21 >= 0 ; V_21 -- )
for ( V_208 = V_2 -> V_22 -> V_226 [ V_21 ] . V_236 - 1 ; V_208 >= 0 ; V_208 -- )
F_171 (
& V_2 -> V_22 -> V_226 [ V_21 ] . V_230 [ V_208 ] ) ;
V_219:
F_172 ( V_53 ) ;
if ( ! V_2 -> V_158 )
F_173 ( V_2 -> V_117 ) ;
V_210:
F_22 ( V_53 , L_38 ) ;
return V_52 ;
}
static int F_174 ( struct V_202 * V_203 )
{
static struct V_1 * V_2 ;
int V_21 , V_208 ;
V_2 = F_175 ( V_203 ) ;
if ( ! V_2 )
return - V_206 ;
F_167 ( & V_149 . V_150 ) ;
F_176 ( & V_2 -> V_211 ) ;
F_169 ( & V_149 . V_150 ) ;
for ( V_21 = V_2 -> V_22 -> V_225 - 1 ; V_21 >= 0 ; V_21 -- )
for ( V_208 = V_2 -> V_22 -> V_226 [ V_21 ] . V_236 - 1 ; V_208 >= 0 ; V_208 -- )
F_171 (
& V_2 -> V_22 -> V_226 [ V_21 ] . V_230 [ V_208 ] ) ;
F_177 ( & V_2 -> V_105 ) ;
F_172 ( & V_203 -> V_53 ) ;
if ( ! V_2 -> V_158 )
F_173 ( V_2 -> V_117 ) ;
return 0 ;
}
static int F_178 ( struct V_193 * V_53 )
{
F_165 ( V_53 ) ;
return 0 ;
}
static int F_179 ( struct V_193 * V_53 )
{
int V_52 = F_21 ( V_53 ) ;
if ( V_52 < 0 ) {
F_22 ( V_53 , L_1 , V_52 ) ;
return V_52 ;
}
return 0 ;
}
