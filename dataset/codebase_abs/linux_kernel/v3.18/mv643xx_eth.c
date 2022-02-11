static inline T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 -> V_5 + V_3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_5 + V_3 ) ;
}
static inline void F_4 ( struct V_1 * V_2 , int V_3 , T_1 V_6 )
{
F_5 ( V_6 , V_2 -> V_4 -> V_5 + V_3 ) ;
}
static inline void F_6 ( struct V_1 * V_2 , int V_3 , T_1 V_6 )
{
F_5 ( V_6 , V_2 -> V_5 + V_3 ) ;
}
static struct V_1 * F_7 ( struct V_7 * V_8 )
{
return F_8 ( V_8 , struct V_1 , V_8 [ V_8 -> V_9 ] ) ;
}
static struct V_1 * F_9 ( struct V_10 * V_11 )
{
return F_8 ( V_11 , struct V_1 , V_11 [ V_11 -> V_9 ] ) ;
}
static void F_10 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_7 ( V_8 ) ;
F_6 ( V_2 , V_12 , 1 << V_8 -> V_9 ) ;
}
static void F_11 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_7 ( V_8 ) ;
T_2 V_13 = 1 << V_8 -> V_9 ;
F_6 ( V_2 , V_12 , V_13 << 8 ) ;
while ( F_3 ( V_2 , V_12 ) & V_13 )
F_12 ( 10 ) ;
}
static void F_13 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_9 ( V_11 ) ;
T_1 V_14 ;
V_14 = ( T_1 ) V_11 -> V_15 ;
V_14 += V_11 -> V_16 * sizeof( struct V_17 ) ;
F_6 ( V_2 , F_14 ( V_11 -> V_9 ) , V_14 ) ;
}
static void F_15 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_9 ( V_11 ) ;
F_6 ( V_2 , V_18 , 1 << V_11 -> V_9 ) ;
}
static void F_16 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_9 ( V_11 ) ;
T_2 V_13 = 1 << V_11 -> V_9 ;
F_6 ( V_2 , V_18 , V_13 << 8 ) ;
while ( F_3 ( V_2 , V_18 ) & V_13 )
F_12 ( 10 ) ;
}
static void F_17 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_9 ( V_11 ) ;
struct V_19 * V_20 = F_18 ( V_2 -> V_21 , V_11 -> V_9 ) ;
if ( F_19 ( V_20 ) ) {
F_20 ( V_20 , F_21 () ) ;
if ( V_11 -> V_22 <= V_11 -> V_23 )
F_22 ( V_20 ) ;
F_23 ( V_20 ) ;
}
}
static int F_24 ( struct V_7 * V_8 , int V_24 )
{
struct V_1 * V_2 = F_7 ( V_8 ) ;
struct V_25 * V_26 = & V_2 -> V_21 -> V_26 ;
int V_27 ;
V_27 = 0 ;
while ( V_27 < V_24 && V_8 -> V_28 ) {
struct V_29 * V_29 ;
unsigned int V_30 ;
struct V_31 * V_32 ;
T_3 V_33 ;
V_29 = & V_8 -> V_34 [ V_8 -> V_35 ] ;
V_30 = V_29 -> V_30 ;
if ( V_30 & V_36 )
break;
F_25 () ;
V_32 = V_8 -> V_37 [ V_8 -> V_35 ] ;
V_8 -> V_37 [ V_8 -> V_35 ] = NULL ;
V_8 -> V_35 ++ ;
if ( V_8 -> V_35 == V_8 -> V_38 )
V_8 -> V_35 = 0 ;
F_26 ( V_2 -> V_21 -> V_21 . V_39 , V_29 -> V_40 ,
V_29 -> V_41 , V_42 ) ;
V_8 -> V_28 -- ;
V_27 ++ ;
V_2 -> V_43 |= 1 << V_8 -> V_9 ;
V_33 = V_29 -> V_33 ;
V_26 -> V_44 ++ ;
V_26 -> V_45 += V_33 - 2 ;
if ( ( V_30 & ( V_46 | V_47 | V_48 ) )
!= ( V_46 | V_47 ) )
goto V_49;
F_27 ( V_32 , V_33 - 2 - 4 ) ;
if ( V_30 & V_50 )
V_32 -> V_51 = V_52 ;
V_32 -> V_53 = F_28 ( V_32 , V_2 -> V_21 ) ;
F_29 ( & V_2 -> V_54 , V_32 ) ;
continue;
V_49:
V_26 -> V_55 ++ ;
if ( ( V_30 & ( V_46 | V_47 ) ) !=
( V_46 | V_47 ) ) {
if ( F_30 () )
F_31 ( V_2 -> V_21 ,
L_1 ) ;
}
if ( V_30 & V_48 )
V_26 -> V_56 ++ ;
F_32 ( V_32 ) ;
}
if ( V_27 < V_24 )
V_2 -> V_57 &= ~ ( 1 << V_8 -> V_9 ) ;
return V_27 ;
}
static int F_33 ( struct V_7 * V_8 , int V_24 )
{
struct V_1 * V_2 = F_7 ( V_8 ) ;
int V_58 ;
V_58 = 0 ;
while ( V_58 < V_24 && V_8 -> V_28 < V_8 -> V_38 ) {
struct V_31 * V_32 ;
int V_27 ;
struct V_29 * V_29 ;
int V_59 ;
V_32 = F_34 ( V_2 -> V_21 , V_2 -> V_60 ) ;
if ( V_32 == NULL ) {
V_2 -> V_61 = 1 ;
goto V_61;
}
if ( V_62 )
F_35 ( V_32 , V_62 ) ;
V_58 ++ ;
V_8 -> V_28 ++ ;
V_27 = V_8 -> V_63 ++ ;
if ( V_8 -> V_63 == V_8 -> V_38 )
V_8 -> V_63 = 0 ;
V_29 = V_8 -> V_34 + V_27 ;
V_59 = F_36 ( V_32 ) - V_32 -> V_6 ;
V_29 -> V_40 = F_37 ( V_2 -> V_21 -> V_21 . V_39 ,
V_32 -> V_6 , V_59 ,
V_42 ) ;
V_29 -> V_41 = V_59 ;
V_8 -> V_37 [ V_27 ] = V_32 ;
F_38 () ;
V_29 -> V_30 = V_36 | V_64 ;
F_38 () ;
F_35 ( V_32 , 2 ) ;
}
if ( V_58 < V_24 )
V_2 -> V_43 &= ~ ( 1 << V_8 -> V_9 ) ;
V_61:
return V_58 ;
}
static inline unsigned int F_39 ( struct V_31 * V_32 )
{
int V_65 ;
for ( V_65 = 0 ; V_65 < F_40 ( V_32 ) -> V_66 ; V_65 ++ ) {
const T_4 * V_67 = & F_40 ( V_32 ) -> V_68 [ V_65 ] ;
if ( F_41 ( V_67 ) <= 8 && V_67 -> V_69 & 7 )
return 1 ;
}
return 0 ;
}
static inline T_5 F_42 ( T_6 V_70 )
{
return ( V_71 T_5 ) V_70 ;
}
static int F_43 ( struct V_1 * V_2 , struct V_31 * V_32 ,
T_3 * V_72 , T_1 * V_73 , int V_74 )
{
int V_75 ;
T_1 V_76 = 0 ;
if ( V_32 -> V_51 == V_77 ) {
int V_78 ;
int V_79 ;
F_44 ( V_32 -> V_53 != F_45 ( V_80 ) &&
V_32 -> V_53 != F_45 ( V_81 ) ) ;
V_78 = ( void * ) F_46 ( V_32 ) - ( void * ) V_32 -> V_6 ;
V_79 = V_78 - V_82 ;
if ( V_74 - V_78 > V_2 -> V_4 -> V_83 ||
F_47 ( V_79 & ~ 12 ) ) {
V_75 = F_48 ( V_32 ) ;
if ( ! V_75 )
goto V_84;
return V_75 ;
}
if ( V_79 & 4 )
V_76 |= V_85 ;
if ( V_79 & 8 )
V_76 |= V_86 ;
V_76 |= V_87 | V_88 |
V_89 |
F_46 ( V_32 ) -> V_90 << V_91 ;
switch ( F_46 ( V_32 ) -> V_53 ) {
case V_92 :
V_76 |= V_93 ;
* V_72 = 0 ;
break;
case V_94 :
* V_72 = 0 ;
break;
default:
F_49 ( 1 , L_2 ) ;
}
} else {
V_84:
V_76 |= 5 << V_91 ;
}
* V_73 = V_76 ;
return 0 ;
}
static inline int
F_50 ( struct V_95 * V_21 , struct V_10 * V_11 ,
struct V_31 * V_32 , char * V_6 , int V_74 ,
bool V_96 , bool V_97 )
{
int V_98 ;
T_1 V_30 ;
struct V_17 * V_99 ;
V_98 = V_11 -> V_16 ++ ;
if ( V_11 -> V_16 == V_11 -> V_100 )
V_11 -> V_16 = 0 ;
V_99 = & V_11 -> V_101 [ V_98 ] ;
V_99 -> V_72 = 0 ;
V_99 -> V_33 = V_74 ;
V_99 -> V_40 = F_37 ( V_21 -> V_21 . V_39 , V_6 ,
V_74 , V_102 ) ;
if ( F_47 ( F_51 ( V_21 -> V_21 . V_39 , V_99 -> V_40 ) ) ) {
F_49 ( 1 , L_3 ) ;
return - V_103 ;
}
V_30 = V_36 ;
if ( V_96 ) {
V_30 |= V_104 | V_105 ;
if ( V_97 )
V_30 |= V_106 ;
}
V_99 -> V_30 = V_30 ;
return 0 ;
}
static inline void
F_52 ( struct V_31 * V_32 , struct V_10 * V_11 , int V_74 )
{
struct V_1 * V_2 = F_9 ( V_11 ) ;
int V_78 = F_53 ( V_32 ) + F_54 ( V_32 ) ;
int V_98 ;
struct V_17 * V_99 ;
int V_75 ;
T_1 V_107 = 0 ;
T_3 V_72 = 0 ;
V_98 = V_11 -> V_16 ;
V_99 = & V_11 -> V_101 [ V_98 ] ;
V_75 = F_43 ( V_2 , V_32 , & V_72 , & V_107 , V_74 ) ;
if ( V_75 )
F_49 ( 1 , L_4 ) ;
V_99 -> V_72 = 0 ;
V_99 -> V_33 = V_78 ;
V_99 -> V_40 = V_11 -> V_108 +
V_11 -> V_16 * V_109 ;
V_99 -> V_30 = V_107 | V_36 | V_110 |
V_111 ;
V_11 -> V_16 ++ ;
if ( V_11 -> V_16 == V_11 -> V_100 )
V_11 -> V_16 = 0 ;
}
static int F_55 ( struct V_10 * V_11 , struct V_31 * V_32 ,
struct V_95 * V_21 )
{
struct V_1 * V_2 = F_9 ( V_11 ) ;
int V_112 , V_113 , V_75 ;
int V_114 = 0 ;
struct V_115 V_116 ;
int V_78 = F_53 ( V_32 ) + F_54 ( V_32 ) ;
if ( ( V_11 -> V_22 + F_56 ( V_32 ) ) >= V_11 -> V_100 ) {
F_57 ( V_21 , L_5 ) ;
return - V_117 ;
}
F_58 ( V_32 , & V_116 ) ;
V_112 = V_32 -> V_118 - V_78 ;
while ( V_112 > 0 ) {
char * V_119 ;
V_113 = F_59 ( int , F_40 ( V_32 ) -> V_120 , V_112 ) ;
V_112 -= V_113 ;
V_114 ++ ;
V_119 = V_11 -> V_121 + V_11 -> V_16 * V_109 ;
F_60 ( V_32 , V_119 , & V_116 , V_113 , V_112 == 0 ) ;
F_52 ( V_32 , V_11 , V_113 ) ;
while ( V_113 > 0 ) {
int V_59 ;
V_114 ++ ;
V_59 = F_59 ( int , V_116 . V_59 , V_113 ) ;
V_75 = F_50 ( V_21 , V_11 , V_32 , V_116 . V_6 , V_59 ,
V_59 == V_113 ,
V_112 == 0 ) ;
if ( V_75 )
goto V_122;
V_113 -= V_59 ;
F_61 ( V_32 , & V_116 , V_59 ) ;
}
}
F_62 ( & V_11 -> V_123 , V_32 ) ;
F_63 ( V_32 ) ;
V_2 -> V_124 &= ~ ( 1 << V_11 -> V_9 ) ;
F_38 () ;
F_15 ( V_11 ) ;
V_11 -> V_22 += V_114 ;
return 0 ;
V_122:
return V_75 ;
}
static void F_64 ( struct V_10 * V_11 , struct V_31 * V_32 )
{
struct V_1 * V_2 = F_9 ( V_11 ) ;
int V_66 = F_40 ( V_32 ) -> V_66 ;
int V_65 ;
for ( V_65 = 0 ; V_65 < V_66 ; V_65 ++ ) {
T_4 * V_125 ;
int V_98 ;
struct V_17 * V_99 ;
void * V_14 ;
V_125 = & F_40 ( V_32 ) -> V_68 [ V_65 ] ;
V_14 = F_65 ( V_125 -> V_126 . V_127 ) + V_125 -> V_69 ;
V_98 = V_11 -> V_16 ++ ;
if ( V_11 -> V_16 == V_11 -> V_100 )
V_11 -> V_16 = 0 ;
V_99 = & V_11 -> V_101 [ V_98 ] ;
if ( V_65 == V_66 - 1 ) {
V_99 -> V_30 = V_36 |
V_104 | V_105 |
V_106 ;
} else {
V_99 -> V_30 = V_36 ;
}
V_99 -> V_72 = 0 ;
V_99 -> V_33 = F_41 ( V_125 ) ;
V_99 -> V_40 = F_37 ( V_2 -> V_21 -> V_21 . V_39 , V_14 ,
V_99 -> V_33 , V_102 ) ;
}
}
static int F_66 ( struct V_10 * V_11 , struct V_31 * V_32 ,
struct V_95 * V_21 )
{
struct V_1 * V_2 = F_9 ( V_11 ) ;
int V_66 = F_40 ( V_32 ) -> V_66 ;
int V_98 ;
struct V_17 * V_99 ;
T_1 V_30 ;
T_3 V_72 ;
int V_74 , V_75 ;
V_30 = 0 ;
V_72 = 0 ;
if ( V_11 -> V_100 - V_11 -> V_22 < V_128 + 1 ) {
if ( F_30 () )
F_31 ( V_21 , L_6 ) ;
return - V_117 ;
}
V_75 = F_43 ( V_2 , V_32 , & V_72 , & V_30 , V_32 -> V_118 ) ;
if ( V_75 )
return V_75 ;
V_30 |= V_110 | V_111 | V_36 ;
V_98 = V_11 -> V_16 ++ ;
if ( V_11 -> V_16 == V_11 -> V_100 )
V_11 -> V_16 = 0 ;
V_99 = & V_11 -> V_101 [ V_98 ] ;
if ( V_66 ) {
F_64 ( V_11 , V_32 ) ;
V_74 = F_67 ( V_32 ) ;
} else {
V_30 |= V_104 | V_105 | V_106 ;
V_74 = V_32 -> V_118 ;
}
V_99 -> V_72 = V_72 ;
V_99 -> V_33 = V_74 ;
V_99 -> V_40 = F_37 ( V_2 -> V_21 -> V_21 . V_39 , V_32 -> V_6 ,
V_74 , V_102 ) ;
F_62 ( & V_11 -> V_123 , V_32 ) ;
F_63 ( V_32 ) ;
F_38 () ;
V_99 -> V_30 = V_30 ;
V_2 -> V_124 &= ~ ( 1 << V_11 -> V_9 ) ;
F_38 () ;
F_15 ( V_11 ) ;
V_11 -> V_22 += V_66 + 1 ;
return 0 ;
}
static T_7 F_68 ( struct V_31 * V_32 , struct V_95 * V_21 )
{
struct V_1 * V_2 = F_69 ( V_21 ) ;
int V_74 , V_129 , V_75 ;
struct V_10 * V_11 ;
struct V_19 * V_20 ;
V_129 = F_70 ( V_32 ) ;
V_11 = V_2 -> V_11 + V_129 ;
V_20 = F_18 ( V_21 , V_129 ) ;
if ( F_39 ( V_32 ) && F_71 ( V_32 ) ) {
F_72 ( V_130 , V_21 ,
L_7 ) ;
return V_131 ;
}
V_74 = V_32 -> V_118 ;
if ( F_73 ( V_32 ) )
V_75 = F_55 ( V_11 , V_32 , V_21 ) ;
else
V_75 = F_66 ( V_11 , V_32 , V_21 ) ;
if ( ! V_75 ) {
V_11 -> V_132 += V_74 ;
V_11 -> V_133 ++ ;
if ( V_11 -> V_22 >= V_11 -> V_134 )
F_74 ( V_20 ) ;
} else {
V_11 -> V_135 ++ ;
F_75 ( V_32 ) ;
}
return V_136 ;
}
static void F_76 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_9 ( V_11 ) ;
struct V_19 * V_20 = F_18 ( V_2 -> V_21 , V_11 -> V_9 ) ;
T_1 V_137 ;
T_1 V_138 ;
F_20 ( V_20 , F_21 () ) ;
if ( F_3 ( V_2 , V_18 ) & ( 1 << V_11 -> V_9 ) )
goto V_139;
V_137 = F_3 ( V_2 , F_14 ( V_11 -> V_9 ) ) ;
V_138 = ( T_1 ) V_11 -> V_15 +
V_11 -> V_16 * sizeof( struct V_17 ) ;
if ( V_137 != V_138 )
F_15 ( V_11 ) ;
V_139:
F_23 ( V_20 ) ;
V_2 -> V_124 &= ~ ( 1 << V_11 -> V_9 ) ;
}
static int F_77 ( struct V_10 * V_11 , int V_24 , int V_140 )
{
struct V_1 * V_2 = F_9 ( V_11 ) ;
struct V_19 * V_20 = F_18 ( V_2 -> V_21 , V_11 -> V_9 ) ;
int V_141 ;
F_78 ( V_20 ) ;
V_141 = 0 ;
while ( V_141 < V_24 && V_11 -> V_22 > 0 ) {
int V_98 ;
struct V_17 * V_99 ;
T_1 V_30 ;
V_98 = V_11 -> V_142 ;
V_99 = & V_11 -> V_101 [ V_98 ] ;
V_30 = V_99 -> V_30 ;
if ( V_30 & V_36 ) {
if ( ! V_140 )
break;
V_99 -> V_30 = V_30 & ~ V_36 ;
}
V_11 -> V_142 = V_98 + 1 ;
if ( V_11 -> V_142 == V_11 -> V_100 )
V_11 -> V_142 = 0 ;
V_141 ++ ;
V_11 -> V_22 -- ;
if ( ! F_79 ( V_11 , V_99 -> V_40 ) )
F_26 ( V_2 -> V_21 -> V_21 . V_39 , V_99 -> V_40 ,
V_99 -> V_33 , V_102 ) ;
if ( V_30 & V_106 ) {
struct V_31 * V_32 = F_80 ( & V_11 -> V_123 ) ;
if ( ! F_81 ( ! V_32 ) )
F_32 ( V_32 ) ;
}
if ( V_30 & V_48 ) {
F_82 ( V_2 -> V_21 , L_8 ) ;
V_2 -> V_21 -> V_26 . V_143 ++ ;
}
}
F_83 ( V_20 ) ;
if ( V_141 < V_24 )
V_2 -> V_144 &= ~ ( 1 << V_11 -> V_9 ) ;
return V_141 ;
}
static void F_84 ( struct V_1 * V_2 , int V_145 , int V_146 )
{
int V_147 ;
int V_148 ;
int V_149 ;
V_147 = ( ( V_145 / 1000 ) * 64 ) / ( V_2 -> V_150 / 1000 ) ;
if ( V_147 > 1023 )
V_147 = 1023 ;
V_148 = ( V_2 -> V_21 -> V_148 + 255 ) >> 8 ;
if ( V_148 > 63 )
V_148 = 63 ;
V_149 = ( V_146 + 255 ) >> 8 ;
if ( V_149 > 65535 )
V_149 = 65535 ;
switch ( V_2 -> V_4 -> V_151 ) {
case V_152 :
F_6 ( V_2 , V_153 , V_147 ) ;
F_6 ( V_2 , V_154 , V_148 ) ;
F_6 ( V_2 , V_155 , V_149 ) ;
break;
case V_156 :
F_6 ( V_2 , V_157 , V_147 ) ;
F_6 ( V_2 , V_158 , V_148 ) ;
F_6 ( V_2 , V_159 , V_149 ) ;
break;
}
}
static void F_85 ( struct V_10 * V_11 , int V_145 , int V_146 )
{
struct V_1 * V_2 = F_9 ( V_11 ) ;
int V_147 ;
int V_149 ;
V_147 = ( ( V_145 / 1000 ) * 64 ) / ( V_2 -> V_150 / 1000 ) ;
if ( V_147 > 1023 )
V_147 = 1023 ;
V_149 = ( V_146 + 255 ) >> 8 ;
if ( V_149 > 65535 )
V_149 = 65535 ;
F_6 ( V_2 , F_86 ( V_11 -> V_9 ) , V_147 << 14 ) ;
F_6 ( V_2 , F_87 ( V_11 -> V_9 ) , ( V_149 << 10 ) | V_147 ) ;
}
static void F_88 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_9 ( V_11 ) ;
int V_160 ;
T_1 V_161 ;
V_160 = 0 ;
switch ( V_2 -> V_4 -> V_151 ) {
case V_152 :
V_160 = V_162 ;
break;
case V_156 :
V_160 = V_163 ;
break;
}
if ( V_160 ) {
V_161 = F_3 ( V_2 , V_160 ) ;
V_161 |= 1 << V_11 -> V_9 ;
F_6 ( V_2 , V_160 , V_161 ) ;
}
}
static void F_89 ( struct V_95 * V_21 )
{
struct V_1 * V_2 = F_69 ( V_21 ) ;
T_1 V_164 = F_3 ( V_2 , V_165 ) ;
T_1 V_166 = V_167 |
V_168 |
V_169 |
V_170 ;
if ( V_2 -> V_171 -> V_172 == V_173 ) {
V_164 &= ~ V_166 ;
goto V_174;
}
V_164 |= V_166 ;
if ( V_2 -> V_171 -> V_175 == V_176 ) {
V_164 |= V_177 ;
V_164 |= V_178 ;
goto V_174;
}
V_164 &= ~ V_177 ;
if ( V_2 -> V_171 -> V_175 == V_179 )
V_164 |= V_180 ;
else
V_164 &= ~ V_180 ;
if ( V_2 -> V_171 -> V_181 == V_182 )
V_164 |= V_178 ;
else
V_164 &= ~ V_178 ;
V_174:
F_6 ( V_2 , V_165 , V_164 ) ;
}
static struct V_25 * F_90 ( struct V_95 * V_21 )
{
struct V_1 * V_2 = F_69 ( V_21 ) ;
struct V_25 * V_26 = & V_21 -> V_26 ;
unsigned long V_133 = 0 ;
unsigned long V_132 = 0 ;
unsigned long V_135 = 0 ;
int V_183 ;
for ( V_183 = 0 ; V_183 < V_2 -> V_184 ; V_183 ++ ) {
struct V_10 * V_11 = V_2 -> V_11 + V_183 ;
V_133 += V_11 -> V_133 ;
V_132 += V_11 -> V_132 ;
V_135 += V_11 -> V_135 ;
}
V_26 -> V_133 = V_133 ;
V_26 -> V_132 = V_132 ;
V_26 -> V_135 = V_135 ;
return V_26 ;
}
static inline T_1 F_91 ( struct V_1 * V_2 , int V_3 )
{
return F_1 ( V_2 , F_92 ( V_2 -> V_185 ) + V_3 ) ;
}
static void F_93 ( struct V_1 * V_2 )
{
int V_183 ;
for ( V_183 = 0 ; V_183 < 0x80 ; V_183 += 4 )
F_91 ( V_2 , V_183 ) ;
F_3 ( V_2 , V_186 ) ;
F_3 ( V_2 , V_187 ) ;
}
static void F_94 ( struct V_1 * V_2 )
{
struct V_188 * V_127 = & V_2 -> V_188 ;
F_95 ( & V_2 -> V_189 ) ;
V_127 -> V_190 += F_91 ( V_2 , 0x00 ) ;
V_127 -> V_191 += F_91 ( V_2 , 0x08 ) ;
V_127 -> V_192 += F_91 ( V_2 , 0x0c ) ;
V_127 -> V_193 += F_91 ( V_2 , 0x10 ) ;
V_127 -> V_194 += F_91 ( V_2 , 0x14 ) ;
V_127 -> V_195 += F_91 ( V_2 , 0x18 ) ;
V_127 -> V_196 += F_91 ( V_2 , 0x1c ) ;
V_127 -> V_197 += F_91 ( V_2 , 0x20 ) ;
V_127 -> V_198 += F_91 ( V_2 , 0x24 ) ;
V_127 -> V_199 += F_91 ( V_2 , 0x28 ) ;
V_127 -> V_200 += F_91 ( V_2 , 0x2c ) ;
V_127 -> V_201 += F_91 ( V_2 , 0x30 ) ;
V_127 -> V_202 += F_91 ( V_2 , 0x34 ) ;
V_127 -> V_203 += F_91 ( V_2 , 0x38 ) ;
V_127 -> V_204 += F_91 ( V_2 , 0x40 ) ;
V_127 -> V_205 += F_91 ( V_2 , 0x44 ) ;
V_127 -> V_206 += F_91 ( V_2 , 0x48 ) ;
V_127 -> V_207 += F_91 ( V_2 , 0x4c ) ;
V_127 -> V_208 += F_91 ( V_2 , 0x50 ) ;
V_127 -> V_209 += F_91 ( V_2 , 0x54 ) ;
V_127 -> V_210 += F_91 ( V_2 , 0x58 ) ;
V_127 -> V_211 += F_91 ( V_2 , 0x5c ) ;
V_127 -> V_212 += F_91 ( V_2 , 0x60 ) ;
V_127 -> V_213 += F_91 ( V_2 , 0x64 ) ;
V_127 -> V_214 += F_91 ( V_2 , 0x68 ) ;
V_127 -> V_215 += F_91 ( V_2 , 0x6c ) ;
V_127 -> V_216 += F_91 ( V_2 , 0x70 ) ;
V_127 -> V_217 += F_91 ( V_2 , 0x74 ) ;
V_127 -> V_218 += F_91 ( V_2 , 0x78 ) ;
V_127 -> V_219 += F_91 ( V_2 , 0x7c ) ;
V_127 -> V_220 += F_3 ( V_2 , V_186 ) ;
V_127 -> V_221 += F_3 ( V_2 , V_187 ) ;
F_96 ( & V_2 -> V_189 ) ;
}
static void F_97 ( unsigned long V_222 )
{
struct V_1 * V_2 = ( void * ) V_222 ;
F_94 ( V_2 ) ;
F_98 ( & V_2 -> V_223 , V_224 + 30 * V_225 ) ;
}
static unsigned int F_99 ( struct V_1 * V_2 )
{
T_1 V_161 = F_3 ( V_2 , V_226 ) ;
T_8 V_227 ;
if ( V_2 -> V_4 -> V_228 )
V_227 = ( ( V_161 & 0x02000000 ) >> 10 ) | ( ( V_161 & 0x003fff80 ) >> 7 ) ;
else
V_227 = ( V_161 & 0x003fff00 ) >> 8 ;
V_227 *= 64000000 ;
F_100 ( V_227 , V_2 -> V_150 ) ;
return ( unsigned int ) V_227 ;
}
static void F_101 ( struct V_1 * V_2 , unsigned int V_229 )
{
T_8 V_227 ;
T_1 V_161 ;
V_227 = ( T_8 ) V_229 * V_2 -> V_150 ;
V_227 += 31999999 ;
F_100 ( V_227 , 64000000 ) ;
V_161 = F_3 ( V_2 , V_226 ) ;
if ( V_2 -> V_4 -> V_228 ) {
if ( V_227 > 0xffff )
V_227 = 0xffff ;
V_161 &= ~ 0x023fff80 ;
V_161 |= ( V_227 & 0x8000 ) << 10 ;
V_161 |= ( V_227 & 0x7fff ) << 7 ;
} else {
if ( V_227 > 0x3fff )
V_227 = 0x3fff ;
V_161 &= ~ 0x003fff00 ;
V_161 |= ( V_227 & 0x3fff ) << 8 ;
}
F_6 ( V_2 , V_226 , V_161 ) ;
}
static unsigned int F_102 ( struct V_1 * V_2 )
{
T_8 V_227 ;
V_227 = ( F_3 ( V_2 , V_230 ) & 0x3fff0 ) >> 4 ;
V_227 *= 64000000 ;
F_100 ( V_227 , V_2 -> V_150 ) ;
return ( unsigned int ) V_227 ;
}
static void F_103 ( struct V_1 * V_2 , unsigned int V_229 )
{
T_8 V_227 ;
V_227 = ( T_8 ) V_229 * V_2 -> V_150 ;
V_227 += 31999999 ;
F_100 ( V_227 , 64000000 ) ;
if ( V_227 > 0x3fff )
V_227 = 0x3fff ;
F_6 ( V_2 , V_230 , V_227 << 4 ) ;
}
static int
F_104 ( struct V_1 * V_2 ,
struct V_231 * V_76 )
{
int V_49 ;
V_49 = F_105 ( V_2 -> V_171 ) ;
if ( V_49 == 0 )
V_49 = F_106 ( V_2 -> V_171 , V_76 ) ;
V_76 -> V_232 &= ~ V_233 ;
V_76 -> V_234 &= ~ V_235 ;
return V_49 ;
}
static int
F_107 ( struct V_1 * V_2 ,
struct V_231 * V_76 )
{
T_1 V_236 ;
V_236 = F_3 ( V_2 , V_237 ) ;
V_76 -> V_232 = V_238 ;
V_76 -> V_234 = V_239 ;
switch ( V_236 & V_240 ) {
case V_241 :
F_108 ( V_76 , V_242 ) ;
break;
case V_243 :
F_108 ( V_76 , V_179 ) ;
break;
case V_244 :
F_108 ( V_76 , V_176 ) ;
break;
default:
V_76 -> V_175 = - 1 ;
break;
}
V_76 -> V_181 = ( V_236 & V_245 ) ? V_182 : V_246 ;
V_76 -> V_247 = V_248 ;
V_76 -> V_249 = 0 ;
V_76 -> V_250 = V_251 ;
V_76 -> V_172 = V_252 ;
V_76 -> V_253 = 1 ;
V_76 -> V_254 = 1 ;
return 0 ;
}
static void
F_109 ( struct V_95 * V_21 , struct V_255 * V_256 )
{
struct V_1 * V_2 = F_69 ( V_21 ) ;
V_256 -> V_232 = 0 ;
V_256 -> V_257 = 0 ;
if ( V_2 -> V_171 )
F_110 ( V_2 -> V_171 , V_256 ) ;
}
static int
F_111 ( struct V_95 * V_21 , struct V_255 * V_256 )
{
struct V_1 * V_2 = F_69 ( V_21 ) ;
int V_49 ;
if ( V_2 -> V_171 == NULL )
return - V_258 ;
V_49 = F_112 ( V_2 -> V_171 , V_256 ) ;
if ( V_49 == - V_258 )
F_82 ( V_21 , L_9 ) ;
return V_49 ;
}
static int
F_113 ( struct V_95 * V_21 , struct V_231 * V_76 )
{
struct V_1 * V_2 = F_69 ( V_21 ) ;
if ( V_2 -> V_171 != NULL )
return F_104 ( V_2 , V_76 ) ;
else
return F_107 ( V_2 , V_76 ) ;
}
static int
F_114 ( struct V_95 * V_21 , struct V_231 * V_76 )
{
struct V_1 * V_2 = F_69 ( V_21 ) ;
int V_75 ;
if ( V_2 -> V_171 == NULL )
return - V_259 ;
V_76 -> V_234 &= ~ V_235 ;
V_75 = F_115 ( V_2 -> V_171 , V_76 ) ;
if ( ! V_75 )
F_89 ( V_21 ) ;
return V_75 ;
}
static void F_116 ( struct V_95 * V_21 ,
struct V_260 * V_261 )
{
F_117 ( V_261 -> V_262 , V_263 ,
sizeof( V_261 -> V_262 ) ) ;
F_117 ( V_261 -> V_264 , V_265 ,
sizeof( V_261 -> V_264 ) ) ;
F_117 ( V_261 -> V_266 , L_10 , sizeof( V_261 -> V_266 ) ) ;
F_117 ( V_261 -> V_267 , L_11 , sizeof( V_261 -> V_267 ) ) ;
V_261 -> V_268 = F_118 ( V_269 ) ;
}
static int F_119 ( struct V_95 * V_21 )
{
struct V_1 * V_2 = F_69 ( V_21 ) ;
if ( V_2 -> V_171 == NULL )
return - V_259 ;
return F_120 ( V_2 -> V_171 ) ;
}
static int
F_121 ( struct V_95 * V_21 , struct V_270 * V_271 )
{
struct V_1 * V_2 = F_69 ( V_21 ) ;
V_271 -> V_272 = F_99 ( V_2 ) ;
V_271 -> V_273 = F_102 ( V_2 ) ;
return 0 ;
}
static int
F_122 ( struct V_95 * V_21 , struct V_270 * V_271 )
{
struct V_1 * V_2 = F_69 ( V_21 ) ;
F_101 ( V_2 , V_271 -> V_272 ) ;
F_103 ( V_2 , V_271 -> V_273 ) ;
return 0 ;
}
static void
F_123 ( struct V_95 * V_21 , struct V_274 * V_275 )
{
struct V_1 * V_2 = F_69 ( V_21 ) ;
V_275 -> V_276 = 4096 ;
V_275 -> V_277 = 4096 ;
V_275 -> V_278 = V_2 -> V_38 ;
V_275 -> V_279 = V_2 -> V_100 ;
}
static int
F_124 ( struct V_95 * V_21 , struct V_274 * V_275 )
{
struct V_1 * V_2 = F_69 ( V_21 ) ;
if ( V_275 -> V_280 || V_275 -> V_281 )
return - V_259 ;
V_2 -> V_38 = V_275 -> V_278 < 4096 ? V_275 -> V_278 : 4096 ;
V_2 -> V_100 = F_125 (unsigned int, er->tx_pending,
MV643XX_MAX_SKB_DESCS * 2 , 4096 ) ;
if ( V_2 -> V_100 != V_275 -> V_279 )
F_126 ( V_21 , L_12 ,
V_2 -> V_100 , V_275 -> V_279 ) ;
if ( F_127 ( V_21 ) ) {
F_128 ( V_21 ) ;
if ( F_129 ( V_21 ) ) {
F_31 ( V_21 ,
L_13 ) ;
return - V_103 ;
}
}
return 0 ;
}
static int
F_130 ( struct V_95 * V_21 , T_9 V_282 )
{
struct V_1 * V_2 = F_69 ( V_21 ) ;
bool V_283 = V_282 & V_284 ;
F_6 ( V_2 , V_285 , V_283 ? 0x02000000 : 0x00000000 ) ;
return 0 ;
}
static void F_131 ( struct V_95 * V_21 ,
T_10 V_286 , T_11 * V_6 )
{
int V_183 ;
if ( V_286 == V_287 ) {
for ( V_183 = 0 ; V_183 < F_118 ( V_269 ) ; V_183 ++ ) {
memcpy ( V_6 + V_183 * V_288 ,
V_269 [ V_183 ] . V_289 ,
V_288 ) ;
}
}
}
static void F_132 ( struct V_95 * V_21 ,
struct V_290 * V_26 ,
T_12 * V_6 )
{
struct V_1 * V_2 = F_69 ( V_21 ) ;
int V_183 ;
F_90 ( V_21 ) ;
F_94 ( V_2 ) ;
for ( V_183 = 0 ; V_183 < F_118 ( V_269 ) ; V_183 ++ ) {
const struct V_269 * V_291 ;
void * V_127 ;
V_291 = V_269 + V_183 ;
if ( V_291 -> V_292 >= 0 )
V_127 = ( ( void * ) V_2 -> V_21 ) + V_291 -> V_292 ;
else
V_127 = ( ( void * ) V_2 ) + V_291 -> V_293 ;
V_6 [ V_183 ] = ( V_291 -> V_294 == 8 ) ?
* ( T_12 * ) V_127 : * ( T_10 * ) V_127 ;
}
}
static int F_133 ( struct V_95 * V_21 , int V_295 )
{
if ( V_295 == V_287 )
return F_118 ( V_269 ) ;
return - V_258 ;
}
static void F_134 ( struct V_1 * V_2 , unsigned char * V_14 )
{
unsigned int V_296 = F_3 ( V_2 , V_297 ) ;
unsigned int V_298 = F_3 ( V_2 , V_299 ) ;
V_14 [ 0 ] = ( V_296 >> 24 ) & 0xff ;
V_14 [ 1 ] = ( V_296 >> 16 ) & 0xff ;
V_14 [ 2 ] = ( V_296 >> 8 ) & 0xff ;
V_14 [ 3 ] = V_296 & 0xff ;
V_14 [ 4 ] = ( V_298 >> 8 ) & 0xff ;
V_14 [ 5 ] = V_298 & 0xff ;
}
static void F_135 ( struct V_1 * V_2 , unsigned char * V_14 )
{
F_6 ( V_2 , V_297 ,
( V_14 [ 0 ] << 24 ) | ( V_14 [ 1 ] << 16 ) | ( V_14 [ 2 ] << 8 ) | V_14 [ 3 ] ) ;
F_6 ( V_2 , V_299 , ( V_14 [ 4 ] << 8 ) | V_14 [ 5 ] ) ;
}
static T_1 F_136 ( struct V_95 * V_21 )
{
struct V_300 * V_301 ;
T_1 V_302 ;
if ( V_21 -> V_303 & V_304 )
return 0 ;
V_302 = 1 << ( V_21 -> V_305 [ 5 ] & 0x0f ) ;
F_137 (ha, dev) {
if ( memcmp ( V_21 -> V_305 , V_301 -> V_14 , 5 ) )
return 0 ;
if ( ( V_21 -> V_305 [ 5 ] ^ V_301 -> V_14 [ 5 ] ) & 0xf0 )
return 0 ;
V_302 |= 1 << ( V_301 -> V_14 [ 5 ] & 0x0f ) ;
}
return V_302 ;
}
static void F_138 ( struct V_95 * V_21 )
{
struct V_1 * V_2 = F_69 ( V_21 ) ;
T_1 V_306 ;
T_1 V_302 ;
int V_183 ;
F_135 ( V_2 , V_21 -> V_305 ) ;
V_306 = F_3 ( V_2 , V_285 ) & ~ V_307 ;
V_302 = F_136 ( V_21 ) ;
if ( ! V_302 ) {
V_306 |= V_307 ;
V_302 = 0xffff ;
}
for ( V_183 = 0 ; V_183 < 16 ; V_183 += 4 ) {
int V_160 = F_139 ( V_2 -> V_185 ) + V_183 ;
T_1 V_308 ;
V_308 = 0 ;
if ( V_302 & 1 )
V_308 |= 0x00000001 ;
if ( V_302 & 2 )
V_308 |= 0x00000100 ;
if ( V_302 & 4 )
V_308 |= 0x00010000 ;
if ( V_302 & 8 )
V_308 |= 0x01000000 ;
V_302 >>= 4 ;
F_4 ( V_2 , V_160 , V_308 ) ;
}
F_6 ( V_2 , V_285 , V_306 ) ;
}
static int F_140 ( unsigned char * V_14 )
{
int V_309 = 0 ;
int V_183 ;
for ( V_183 = 0 ; V_183 < 6 ; V_183 ++ ) {
int V_310 ;
V_309 = ( V_309 ^ V_14 [ V_183 ] ) << 8 ;
for ( V_310 = 7 ; V_310 >= 0 ; V_310 -- ) {
if ( V_309 & ( 0x100 << V_310 ) )
V_309 ^= 0x107 << V_310 ;
}
}
return V_309 ;
}
static void F_141 ( struct V_95 * V_21 )
{
struct V_1 * V_2 = F_69 ( V_21 ) ;
T_1 * V_311 ;
T_1 * V_312 ;
struct V_300 * V_301 ;
int V_183 ;
if ( V_21 -> V_303 & ( V_304 | V_313 ) ) {
int V_185 ;
T_1 V_314 ;
V_61:
V_185 = V_2 -> V_185 ;
V_314 = 0x01010101 ;
for ( V_183 = 0 ; V_183 < 0x100 ; V_183 += 4 ) {
F_4 ( V_2 , F_142 ( V_185 ) + V_183 , V_314 ) ;
F_4 ( V_2 , F_143 ( V_185 ) + V_183 , V_314 ) ;
}
return;
}
V_311 = F_144 ( 0x200 , V_315 ) ;
if ( V_311 == NULL )
goto V_61;
V_312 = V_311 + ( 0x100 >> 2 ) ;
memset ( V_311 , 0 , 0x100 ) ;
memset ( V_312 , 0 , 0x100 ) ;
F_145 (ha, dev) {
T_2 * V_316 = V_301 -> V_14 ;
T_1 * V_317 ;
int V_318 ;
if ( memcmp ( V_316 , L_14 , 5 ) == 0 ) {
V_317 = V_311 ;
V_318 = V_316 [ 5 ] ;
} else {
V_317 = V_312 ;
V_318 = F_140 ( V_316 ) ;
}
V_317 [ V_318 >> 2 ] |= 1 << ( 8 * ( V_318 & 3 ) ) ;
}
for ( V_183 = 0 ; V_183 < 0x100 ; V_183 += 4 ) {
F_4 ( V_2 , F_142 ( V_2 -> V_185 ) + V_183 , V_311 [ V_183 >> 2 ] ) ;
F_4 ( V_2 , F_143 ( V_2 -> V_185 ) + V_183 , V_312 [ V_183 >> 2 ] ) ;
}
F_146 ( V_311 ) ;
}
static void F_147 ( struct V_95 * V_21 )
{
F_138 ( V_21 ) ;
F_141 ( V_21 ) ;
}
static int F_148 ( struct V_95 * V_21 , void * V_14 )
{
struct V_319 * V_320 = V_14 ;
if ( ! F_149 ( V_320 -> V_321 ) )
return - V_322 ;
memcpy ( V_21 -> V_305 , V_320 -> V_321 , V_323 ) ;
F_150 ( V_21 ) ;
F_138 ( V_21 ) ;
F_151 ( V_21 ) ;
return 0 ;
}
static int F_152 ( struct V_1 * V_2 , int V_9 )
{
struct V_7 * V_8 = V_2 -> V_8 + V_9 ;
struct V_29 * V_29 ;
int V_59 ;
int V_183 ;
V_8 -> V_9 = V_9 ;
V_8 -> V_38 = V_2 -> V_38 ;
V_8 -> V_28 = 0 ;
V_8 -> V_35 = 0 ;
V_8 -> V_63 = 0 ;
V_59 = V_8 -> V_38 * sizeof( struct V_29 ) ;
if ( V_9 == 0 && V_59 <= V_2 -> V_324 ) {
V_8 -> V_34 = F_153 ( V_2 -> V_325 ,
V_2 -> V_324 ) ;
V_8 -> V_326 = V_2 -> V_325 ;
} else {
V_8 -> V_34 = F_154 ( V_2 -> V_21 -> V_21 . V_39 ,
V_59 , & V_8 -> V_326 ,
V_327 ) ;
}
if ( V_8 -> V_34 == NULL ) {
F_31 ( V_2 -> V_21 ,
L_15 , V_59 ) ;
goto V_139;
}
memset ( V_8 -> V_34 , 0 , V_59 ) ;
V_8 -> V_328 = V_59 ;
V_8 -> V_37 = F_155 ( V_8 -> V_38 , sizeof( * V_8 -> V_37 ) ,
V_327 ) ;
if ( V_8 -> V_37 == NULL )
goto V_329;
V_29 = V_8 -> V_34 ;
for ( V_183 = 0 ; V_183 < V_8 -> V_38 ; V_183 ++ ) {
int V_330 ;
V_330 = V_183 + 1 ;
if ( V_330 == V_8 -> V_38 )
V_330 = 0 ;
V_29 [ V_183 ] . V_331 = V_8 -> V_326 +
V_330 * sizeof( struct V_29 ) ;
}
return 0 ;
V_329:
if ( V_9 == 0 && V_59 <= V_2 -> V_324 )
F_156 ( V_8 -> V_34 ) ;
else
F_157 ( V_2 -> V_21 -> V_21 . V_39 , V_59 ,
V_8 -> V_34 ,
V_8 -> V_326 ) ;
V_139:
return - V_103 ;
}
static void F_158 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_7 ( V_8 ) ;
int V_183 ;
F_11 ( V_8 ) ;
for ( V_183 = 0 ; V_183 < V_8 -> V_38 ; V_183 ++ ) {
if ( V_8 -> V_37 [ V_183 ] ) {
F_32 ( V_8 -> V_37 [ V_183 ] ) ;
V_8 -> V_28 -- ;
}
}
if ( V_8 -> V_28 ) {
F_31 ( V_2 -> V_21 , L_16 ,
V_8 -> V_28 ) ;
}
if ( V_8 -> V_9 == 0 &&
V_8 -> V_328 <= V_2 -> V_324 )
F_156 ( V_8 -> V_34 ) ;
else
F_157 ( V_2 -> V_21 -> V_21 . V_39 , V_8 -> V_328 ,
V_8 -> V_34 , V_8 -> V_326 ) ;
F_146 ( V_8 -> V_37 ) ;
}
static int F_159 ( struct V_1 * V_2 , int V_9 )
{
struct V_10 * V_11 = V_2 -> V_11 + V_9 ;
struct V_17 * V_17 ;
int V_59 ;
int V_183 ;
V_11 -> V_9 = V_9 ;
V_11 -> V_100 = V_2 -> V_100 ;
V_11 -> V_134 = V_11 -> V_100 - V_332 ;
V_11 -> V_23 = V_11 -> V_134 / 2 ;
V_11 -> V_22 = 0 ;
V_11 -> V_16 = 0 ;
V_11 -> V_142 = 0 ;
V_59 = V_11 -> V_100 * sizeof( struct V_17 ) ;
if ( V_9 == 0 && V_59 <= V_2 -> V_333 ) {
V_11 -> V_101 = F_153 ( V_2 -> V_334 ,
V_2 -> V_333 ) ;
V_11 -> V_15 = V_2 -> V_334 ;
} else {
V_11 -> V_101 = F_154 ( V_2 -> V_21 -> V_21 . V_39 ,
V_59 , & V_11 -> V_15 ,
V_327 ) ;
}
if ( V_11 -> V_101 == NULL ) {
F_31 ( V_2 -> V_21 ,
L_17 , V_59 ) ;
return - V_103 ;
}
memset ( V_11 -> V_101 , 0 , V_59 ) ;
V_11 -> V_335 = V_59 ;
V_17 = V_11 -> V_101 ;
for ( V_183 = 0 ; V_183 < V_11 -> V_100 ; V_183 ++ ) {
struct V_17 * V_336 = V_17 + V_183 ;
int V_330 ;
V_330 = V_183 + 1 ;
if ( V_330 == V_11 -> V_100 )
V_330 = 0 ;
V_336 -> V_30 = 0 ;
V_336 -> V_331 = V_11 -> V_15 +
V_330 * sizeof( struct V_17 ) ;
}
V_11 -> V_121 = F_154 ( V_2 -> V_21 -> V_21 . V_39 ,
V_11 -> V_100 * V_109 ,
& V_11 -> V_108 , V_327 ) ;
if ( V_11 -> V_121 == NULL ) {
F_157 ( V_2 -> V_21 -> V_21 . V_39 , V_11 -> V_335 ,
V_11 -> V_101 , V_11 -> V_15 ) ;
return - V_103 ;
}
F_160 ( & V_11 -> V_123 ) ;
return 0 ;
}
static void F_161 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_9 ( V_11 ) ;
F_16 ( V_11 ) ;
F_77 ( V_11 , V_11 -> V_100 , 1 ) ;
F_44 ( V_11 -> V_142 != V_11 -> V_16 ) ;
if ( V_11 -> V_9 == 0 &&
V_11 -> V_335 <= V_2 -> V_333 )
F_156 ( V_11 -> V_101 ) ;
else
F_157 ( V_2 -> V_21 -> V_21 . V_39 , V_11 -> V_335 ,
V_11 -> V_101 , V_11 -> V_15 ) ;
if ( V_11 -> V_121 )
F_157 ( V_2 -> V_21 -> V_21 . V_39 ,
V_11 -> V_100 * V_109 ,
V_11 -> V_121 , V_11 -> V_108 ) ;
}
static int F_162 ( struct V_1 * V_2 )
{
T_1 V_337 ;
T_1 V_338 ;
V_337 = F_3 ( V_2 , V_339 ) & V_2 -> V_340 ;
if ( V_337 == 0 )
return 0 ;
V_338 = 0 ;
if ( V_337 & V_341 ) {
V_337 &= ~ V_341 ;
V_338 = F_3 ( V_2 , V_342 ) ;
}
if ( V_337 ) {
F_6 ( V_2 , V_339 , ~ V_337 ) ;
V_2 -> V_124 |= ( ( V_337 & V_343 ) >> 19 ) &
~ ( F_3 ( V_2 , V_18 ) & 0xff ) ;
V_2 -> V_57 |= ( V_337 & V_344 ) >> 2 ;
}
V_338 &= V_345 | V_346 ;
if ( V_338 ) {
F_6 ( V_2 , V_342 , ~ V_338 ) ;
if ( V_338 & V_345 )
V_2 -> V_347 = 1 ;
V_2 -> V_144 |= V_338 & V_346 ;
}
return 1 ;
}
static T_13 F_163 ( int V_348 , void * V_349 )
{
struct V_95 * V_21 = (struct V_95 * ) V_349 ;
struct V_1 * V_2 = F_69 ( V_21 ) ;
if ( F_47 ( ! F_162 ( V_2 ) ) )
return V_350 ;
F_6 ( V_2 , V_351 , 0 ) ;
F_164 ( & V_2 -> V_54 ) ;
return V_352 ;
}
static void F_165 ( struct V_1 * V_2 )
{
struct V_95 * V_21 = V_2 -> V_21 ;
T_1 V_236 ;
int V_175 ;
int V_181 ;
int V_353 ;
V_236 = F_3 ( V_2 , V_237 ) ;
if ( ! ( V_236 & V_354 ) ) {
if ( F_166 ( V_21 ) ) {
int V_183 ;
F_82 ( V_21 , L_18 ) ;
F_167 ( V_21 ) ;
for ( V_183 = 0 ; V_183 < V_2 -> V_184 ; V_183 ++ ) {
struct V_10 * V_11 = V_2 -> V_11 + V_183 ;
F_77 ( V_11 , V_11 -> V_100 , 1 ) ;
F_13 ( V_11 ) ;
}
}
return;
}
switch ( V_236 & V_240 ) {
case V_241 :
V_175 = 10 ;
break;
case V_243 :
V_175 = 100 ;
break;
case V_244 :
V_175 = 1000 ;
break;
default:
V_175 = - 1 ;
break;
}
V_181 = ( V_236 & V_245 ) ? 1 : 0 ;
V_353 = ( V_236 & V_355 ) ? 1 : 0 ;
F_82 ( V_21 , L_19 ,
V_175 , V_181 ? L_20 : L_21 , V_353 ? L_22 : L_23 ) ;
if ( ! F_166 ( V_21 ) )
F_168 ( V_21 ) ;
}
static int F_169 ( struct V_356 * V_54 , int V_24 )
{
struct V_1 * V_2 ;
int V_357 ;
V_2 = F_8 ( V_54 , struct V_1 , V_54 ) ;
if ( F_47 ( V_2 -> V_61 ) ) {
V_2 -> V_61 = 0 ;
F_170 ( & V_2 -> V_358 ) ;
}
V_357 = 0 ;
while ( V_357 < V_24 ) {
T_2 V_359 ;
int V_129 ;
int V_360 ;
if ( V_2 -> V_347 ) {
V_2 -> V_347 = 0 ;
F_165 ( V_2 ) ;
V_357 ++ ;
continue;
}
V_359 = V_2 -> V_144 | V_2 -> V_124 | V_2 -> V_57 ;
if ( F_171 ( ! V_2 -> V_61 ) )
V_359 |= V_2 -> V_43 ;
if ( ! V_359 ) {
if ( F_162 ( V_2 ) )
continue;
break;
}
V_129 = F_172 ( V_359 ) - 1 ;
V_359 = 1 << V_129 ;
V_360 = V_24 - V_357 ;
if ( V_360 > 16 )
V_360 = 16 ;
if ( V_2 -> V_124 & V_359 ) {
F_76 ( V_2 -> V_11 + V_129 ) ;
} else if ( V_2 -> V_144 & V_359 ) {
V_357 += F_77 ( V_2 -> V_11 + V_129 , V_360 , 0 ) ;
F_17 ( V_2 -> V_11 + V_129 ) ;
} else if ( V_2 -> V_57 & V_359 ) {
V_357 += F_24 ( V_2 -> V_8 + V_129 , V_360 ) ;
} else if ( ! V_2 -> V_61 && ( V_2 -> V_43 & V_359 ) ) {
V_357 += F_33 ( V_2 -> V_8 + V_129 , V_360 ) ;
} else {
F_173 () ;
}
}
if ( V_357 < V_24 ) {
if ( V_2 -> V_61 )
F_98 ( & V_2 -> V_358 , V_224 + ( V_225 / 10 ) ) ;
F_174 ( V_54 ) ;
F_6 ( V_2 , V_351 , V_2 -> V_340 ) ;
}
return V_357 ;
}
static inline void F_175 ( unsigned long V_6 )
{
struct V_1 * V_2 = ( void * ) V_6 ;
F_164 ( & V_2 -> V_54 ) ;
}
static void F_176 ( struct V_1 * V_2 )
{
T_1 V_164 ;
int V_183 ;
if ( V_2 -> V_171 != NULL ) {
struct V_231 V_76 ;
F_113 ( V_2 -> V_21 , & V_76 ) ;
F_177 ( V_2 -> V_171 ) ;
F_114 ( V_2 -> V_21 , & V_76 ) ;
F_178 ( V_2 -> V_171 ) ;
}
V_164 = F_3 ( V_2 , V_165 ) ;
V_164 |= V_361 ;
F_6 ( V_2 , V_165 , V_164 ) ;
V_164 |= V_362 ;
if ( V_2 -> V_171 == NULL )
V_164 |= V_167 ;
F_6 ( V_2 , V_165 , V_164 ) ;
F_84 ( V_2 , 1000000000 , 16777216 ) ;
for ( V_183 = 0 ; V_183 < V_2 -> V_184 ; V_183 ++ ) {
struct V_10 * V_11 = V_2 -> V_11 + V_183 ;
F_13 ( V_11 ) ;
F_85 ( V_11 , 1000000000 , 16777216 ) ;
F_88 ( V_11 ) ;
}
F_130 ( V_2 -> V_21 , V_2 -> V_21 -> V_282 ) ;
F_6 ( V_2 , V_363 , 0x00000000 ) ;
F_138 ( V_2 -> V_21 ) ;
for ( V_183 = 0 ; V_183 < V_2 -> V_364 ; V_183 ++ ) {
struct V_7 * V_8 = V_2 -> V_8 + V_183 ;
T_1 V_14 ;
V_14 = ( T_1 ) V_8 -> V_326 ;
V_14 += V_8 -> V_35 * sizeof( struct V_29 ) ;
F_6 ( V_2 , F_179 ( V_183 ) , V_14 ) ;
F_10 ( V_8 ) ;
}
}
static void F_180 ( struct V_1 * V_2 )
{
int V_60 ;
V_60 = V_2 -> V_21 -> V_148 + 36 ;
V_2 -> V_60 = ( V_60 + 7 ) & ~ 7 ;
V_2 -> V_60 += V_62 ;
}
static int F_129 ( struct V_95 * V_21 )
{
struct V_1 * V_2 = F_69 ( V_21 ) ;
int V_49 ;
int V_183 ;
F_6 ( V_2 , V_339 , 0 ) ;
F_6 ( V_2 , V_342 , 0 ) ;
F_3 ( V_2 , V_342 ) ;
V_49 = F_181 ( V_21 -> V_348 , F_163 ,
V_365 , V_21 -> V_366 , V_21 ) ;
if ( V_49 ) {
F_31 ( V_21 , L_24 ) ;
return - V_367 ;
}
F_180 ( V_2 ) ;
F_182 ( & V_2 -> V_54 ) ;
V_2 -> V_340 = V_341 ;
for ( V_183 = 0 ; V_183 < V_2 -> V_364 ; V_183 ++ ) {
V_49 = F_152 ( V_2 , V_183 ) ;
if ( V_49 ) {
while ( -- V_183 >= 0 )
F_158 ( V_2 -> V_8 + V_183 ) ;
goto V_139;
}
F_33 ( V_2 -> V_8 + V_183 , V_368 ) ;
V_2 -> V_340 |= V_369 << V_183 ;
}
if ( V_2 -> V_61 ) {
V_2 -> V_358 . V_370 = V_224 + ( V_225 / 10 ) ;
F_183 ( & V_2 -> V_358 ) ;
}
for ( V_183 = 0 ; V_183 < V_2 -> V_184 ; V_183 ++ ) {
V_49 = F_159 ( V_2 , V_183 ) ;
if ( V_49 ) {
while ( -- V_183 >= 0 )
F_161 ( V_2 -> V_11 + V_183 ) ;
goto V_329;
}
V_2 -> V_340 |= V_371 << V_183 ;
}
F_183 ( & V_2 -> V_223 ) ;
F_176 ( V_2 ) ;
F_6 ( V_2 , V_372 , V_345 | V_346 ) ;
F_6 ( V_2 , V_351 , V_2 -> V_340 ) ;
return 0 ;
V_329:
for ( V_183 = 0 ; V_183 < V_2 -> V_364 ; V_183 ++ )
F_158 ( V_2 -> V_8 + V_183 ) ;
V_139:
F_184 ( V_21 -> V_348 , V_21 ) ;
return V_49 ;
}
static void F_185 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
int V_183 ;
for ( V_183 = 0 ; V_183 < V_2 -> V_364 ; V_183 ++ )
F_11 ( V_2 -> V_8 + V_183 ) ;
for ( V_183 = 0 ; V_183 < V_2 -> V_184 ; V_183 ++ )
F_16 ( V_2 -> V_11 + V_183 ) ;
while ( 1 ) {
T_1 V_373 = F_3 ( V_2 , V_237 ) ;
if ( ( V_373 & ( V_374 | V_375 ) ) == V_375 )
break;
F_12 ( 10 ) ;
}
V_6 = F_3 ( V_2 , V_165 ) ;
V_6 &= ~ ( V_361 |
V_362 |
V_167 ) ;
F_6 ( V_2 , V_165 , V_6 ) ;
}
static int F_128 ( struct V_95 * V_21 )
{
struct V_1 * V_2 = F_69 ( V_21 ) ;
int V_183 ;
F_6 ( V_2 , V_372 , 0x00000000 ) ;
F_6 ( V_2 , V_351 , 0x00000000 ) ;
F_3 ( V_2 , V_351 ) ;
F_186 ( & V_2 -> V_54 ) ;
F_187 ( & V_2 -> V_358 ) ;
F_167 ( V_21 ) ;
if ( V_2 -> V_171 )
F_188 ( V_2 -> V_171 ) ;
F_184 ( V_21 -> V_348 , V_21 ) ;
F_185 ( V_2 ) ;
F_90 ( V_21 ) ;
F_94 ( V_2 ) ;
F_187 ( & V_2 -> V_223 ) ;
for ( V_183 = 0 ; V_183 < V_2 -> V_364 ; V_183 ++ )
F_158 ( V_2 -> V_8 + V_183 ) ;
for ( V_183 = 0 ; V_183 < V_2 -> V_184 ; V_183 ++ )
F_161 ( V_2 -> V_11 + V_183 ) ;
return 0 ;
}
static int F_189 ( struct V_95 * V_21 , struct V_376 * V_377 , int V_76 )
{
struct V_1 * V_2 = F_69 ( V_21 ) ;
int V_75 ;
if ( V_2 -> V_171 == NULL )
return - V_378 ;
V_75 = F_190 ( V_2 -> V_171 , V_377 , V_76 ) ;
if ( ! V_75 )
F_89 ( V_21 ) ;
return V_75 ;
}
static int F_191 ( struct V_95 * V_21 , int V_379 )
{
struct V_1 * V_2 = F_69 ( V_21 ) ;
if ( V_379 < 64 || V_379 > 9500 )
return - V_259 ;
V_21 -> V_148 = V_379 ;
F_180 ( V_2 ) ;
F_84 ( V_2 , 1000000000 , 16777216 ) ;
if ( ! F_127 ( V_21 ) )
return 0 ;
F_128 ( V_21 ) ;
if ( F_129 ( V_21 ) ) {
F_31 ( V_21 ,
L_25 ) ;
}
return 0 ;
}
static void F_192 ( struct V_380 * V_381 )
{
struct V_1 * V_2 ;
V_2 = F_8 ( V_381 , struct V_1 , F_192 ) ;
if ( F_127 ( V_2 -> V_21 ) ) {
F_193 ( V_2 -> V_21 ) ;
F_185 ( V_2 ) ;
F_176 ( V_2 ) ;
F_194 ( V_2 -> V_21 ) ;
}
}
static void F_195 ( struct V_95 * V_21 )
{
struct V_1 * V_2 = F_69 ( V_21 ) ;
F_82 ( V_21 , L_26 ) ;
F_196 ( & V_2 -> F_192 ) ;
}
static void F_197 ( struct V_95 * V_21 )
{
struct V_1 * V_2 = F_69 ( V_21 ) ;
F_6 ( V_2 , V_351 , 0x00000000 ) ;
F_3 ( V_2 , V_351 ) ;
F_163 ( V_21 -> V_348 , V_21 ) ;
F_6 ( V_2 , V_351 , V_2 -> V_340 ) ;
}
static void
F_198 ( struct V_382 * V_383 ,
const struct V_384 * V_385 )
{
void T_14 * V_5 = V_383 -> V_5 ;
T_1 V_386 ;
T_1 V_387 ;
int V_183 ;
for ( V_183 = 0 ; V_183 < 6 ; V_183 ++ ) {
F_5 ( 0 , V_5 + F_199 ( V_183 ) ) ;
F_5 ( 0 , V_5 + F_200 ( V_183 ) ) ;
if ( V_183 < 4 )
F_5 ( 0 , V_5 + F_201 ( V_183 ) ) ;
}
V_386 = 0x3f ;
V_387 = 0 ;
for ( V_183 = 0 ; V_183 < V_385 -> V_388 ; V_183 ++ ) {
const struct V_389 * V_390 = V_385 -> V_390 + V_183 ;
F_5 ( ( V_390 -> V_5 & 0xffff0000 ) |
( V_390 -> V_391 << 8 ) |
V_385 -> V_392 , V_5 + F_199 ( V_183 ) ) ;
F_5 ( ( V_390 -> V_59 - 1 ) & 0xffff0000 , V_5 + F_200 ( V_183 ) ) ;
V_386 &= ~ ( 1 << V_183 ) ;
V_387 |= 3 << ( 2 * V_183 ) ;
}
F_5 ( V_386 , V_5 + V_393 ) ;
V_383 -> V_387 = V_387 ;
}
static void F_202 ( struct V_382 * V_383 )
{
F_5 ( 0x02000000 , V_383 -> V_5 + 0x0400 + V_226 ) ;
if ( F_2 ( V_383 -> V_5 + 0x0400 + V_226 ) & 0x02000000 )
V_383 -> V_228 = 1 ;
else
V_383 -> V_228 = 0 ;
F_5 ( 1 , V_383 -> V_5 + 0x0400 + V_158 ) ;
if ( F_2 ( V_383 -> V_5 + 0x0400 + V_158 ) & 1 ) {
V_383 -> V_151 = V_156 ;
} else {
F_5 ( 7 , V_383 -> V_5 + 0x0400 + V_153 ) ;
if ( F_2 ( V_383 -> V_5 + 0x0400 + V_153 ) & 7 )
V_383 -> V_151 = V_152 ;
else
V_383 -> V_151 = V_394 ;
}
}
static int F_203 ( struct V_395 * V_396 ,
struct V_397 * V_398 )
{
struct V_395 * V_399 ;
struct V_400 V_401 ;
struct V_402 V_403 ;
const char * V_404 ;
int V_75 ;
int V_405 = 0 ;
memset ( & V_401 , 0 , sizeof( V_401 ) ) ;
V_401 . V_4 = V_396 ;
memset ( & V_403 , 0 , sizeof( V_403 ) ) ;
if ( ! F_204 ( V_398 , 0 , & V_403 ) ) {
F_205 ( & V_396 -> V_21 , L_27 , V_398 -> V_366 ) ;
return - V_259 ;
}
if ( F_206 ( V_398 , L_28 , & V_401 . V_406 ) ) {
F_205 ( & V_396 -> V_21 , L_29 , V_398 -> V_366 ) ;
return - V_259 ;
}
if ( V_401 . V_406 >= 3 ) {
F_205 ( & V_396 -> V_21 , L_30 , V_398 -> V_366 ) ;
return - V_259 ;
}
while ( V_405 < 3 && V_407 [ V_405 ] )
V_405 ++ ;
if ( V_405 == 3 ) {
F_205 ( & V_396 -> V_21 , L_31 ) ;
return - V_259 ;
}
V_404 = F_207 ( V_398 ) ;
if ( V_404 )
memcpy ( V_401 . V_404 , V_404 , V_323 ) ;
F_208 ( V_398 , L_32 , V_401 . V_408 ) ;
F_208 ( V_398 , L_33 , V_401 . V_409 ) ;
F_208 ( V_398 , L_34 , V_401 . V_410 ) ;
F_208 ( V_398 , L_35 , V_401 . V_411 ) ;
F_208 ( V_398 , L_36 , V_401 . V_412 ) ;
F_208 ( V_398 , L_37 , V_401 . V_413 ) ;
V_401 . V_414 = F_209 ( V_398 , L_38 , 0 ) ;
if ( ! V_401 . V_414 ) {
V_401 . V_415 = V_416 ;
F_206 ( V_398 , L_39 , & V_401 . V_175 ) ;
F_206 ( V_398 , L_40 , & V_401 . V_181 ) ;
}
V_399 = F_210 ( V_417 , V_405 ) ;
if ( ! V_399 )
return - V_103 ;
V_399 -> V_21 . V_418 = F_211 ( 32 ) ;
V_399 -> V_21 . V_419 = V_398 ;
V_75 = F_212 ( V_399 , & V_403 , 1 ) ;
if ( V_75 )
goto V_420;
V_75 = F_213 ( V_399 , & V_401 , sizeof( V_401 ) ) ;
if ( V_75 )
goto V_420;
V_75 = F_214 ( V_399 ) ;
if ( V_75 )
goto V_420;
V_407 [ V_405 ] = V_399 ;
return 0 ;
V_420:
F_215 ( V_399 ) ;
return V_75 ;
}
static int F_216 ( struct V_395 * V_396 )
{
struct V_421 * V_422 ;
struct V_397 * V_398 , * V_423 = V_396 -> V_21 . V_419 ;
int V_75 ;
if ( ! V_423 )
return 0 ;
V_422 = F_217 ( & V_396 -> V_21 , sizeof( * V_422 ) , V_327 ) ;
if ( ! V_422 )
return - V_103 ;
V_396 -> V_21 . V_424 = V_422 ;
F_208 ( V_423 , L_41 , V_422 -> V_83 ) ;
F_218 (np, pnp) {
V_75 = F_203 ( V_396 , V_398 ) ;
if ( V_75 )
return V_75 ;
}
return 0 ;
}
static void F_219 ( void )
{
int V_425 ;
for ( V_425 = 0 ; V_425 < 3 ; V_425 ++ ) {
F_220 ( V_407 [ V_425 ] ) ;
V_407 [ V_425 ] = NULL ;
}
}
static inline int F_216 ( struct V_395 * V_396 )
{
return 0 ;
}
static inline void F_219 ( void )
{
}
static int F_221 ( struct V_395 * V_396 )
{
static int V_426 ;
struct V_421 * V_422 ;
struct V_382 * V_383 ;
const struct V_384 * V_385 ;
struct V_402 * V_403 ;
int V_75 ;
if ( ! V_426 ++ )
F_222 ( L_42 ,
V_265 ) ;
V_403 = F_223 ( V_396 , V_427 , 0 ) ;
if ( V_403 == NULL )
return - V_259 ;
V_383 = F_217 ( & V_396 -> V_21 , sizeof( * V_383 ) , V_327 ) ;
if ( V_383 == NULL )
return - V_103 ;
F_224 ( V_396 , V_383 ) ;
V_383 -> V_5 = F_225 ( & V_396 -> V_21 , V_403 -> V_428 , F_226 ( V_403 ) ) ;
if ( V_383 -> V_5 == NULL )
return - V_103 ;
V_383 -> V_429 = F_227 ( & V_396 -> V_21 , NULL ) ;
if ( ! F_228 ( V_383 -> V_429 ) )
F_229 ( V_383 -> V_429 ) ;
V_385 = F_230 () ;
if ( V_385 )
F_198 ( V_383 , V_385 ) ;
V_75 = F_216 ( V_396 ) ;
if ( V_75 )
return V_75 ;
V_422 = F_231 ( & V_396 -> V_21 ) ;
V_383 -> V_83 = ( V_422 != NULL && V_422 -> V_83 ) ?
V_422 -> V_83 : 9 * 1024 ;
F_202 ( V_383 ) ;
return 0 ;
}
static int F_232 ( struct V_395 * V_396 )
{
struct V_382 * V_383 = F_233 ( V_396 ) ;
F_219 () ;
if ( ! F_228 ( V_383 -> V_429 ) )
F_234 ( V_383 -> V_429 ) ;
return 0 ;
}
static void F_235 ( struct V_1 * V_2 , int V_415 )
{
int V_430 = 5 * V_2 -> V_185 ;
T_1 V_6 ;
V_6 = F_1 ( V_2 , V_431 ) ;
V_6 &= ~ ( 0x1f << V_430 ) ;
V_6 |= ( V_415 & 0x1f ) << V_430 ;
F_4 ( V_2 , V_431 , V_6 ) ;
}
static int F_236 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
V_6 = F_1 ( V_2 , V_431 ) ;
return ( V_6 >> ( 5 * V_2 -> V_185 ) ) & 0x1f ;
}
static void F_237 ( struct V_1 * V_2 ,
struct V_400 * V_422 )
{
struct V_95 * V_21 = V_2 -> V_21 ;
unsigned int V_100 ;
if ( F_149 ( V_422 -> V_404 ) )
memcpy ( V_21 -> V_305 , V_422 -> V_404 , V_323 ) ;
else
F_134 ( V_2 , V_21 -> V_305 ) ;
V_2 -> V_38 = V_432 ;
if ( V_422 -> V_411 )
V_2 -> V_38 = V_422 -> V_411 ;
V_2 -> V_325 = V_422 -> V_412 ;
V_2 -> V_324 = V_422 -> V_413 ;
V_2 -> V_364 = V_422 -> V_433 ? : 1 ;
V_100 = V_434 ;
if ( V_422 -> V_408 )
V_100 = V_422 -> V_408 ;
V_2 -> V_100 = F_125 (unsigned int, tx_ring_size,
MV643XX_MAX_SKB_DESCS * 2 , 4096 ) ;
if ( V_2 -> V_100 != V_100 )
F_126 ( V_21 , L_12 ,
V_2 -> V_100 , V_100 ) ;
V_2 -> V_334 = V_422 -> V_409 ;
V_2 -> V_333 = V_422 -> V_410 ;
V_2 -> V_184 = V_422 -> V_435 ? : 1 ;
}
static struct V_436 * F_238 ( struct V_1 * V_2 ,
int V_415 )
{
struct V_436 * V_437 ;
int V_428 ;
int V_438 ;
int V_183 ;
char V_439 [ V_440 + 3 ] ;
if ( V_415 == V_441 ) {
V_428 = F_236 ( V_2 ) & 0x1f ;
V_438 = 32 ;
} else {
V_428 = V_415 & 0x1f ;
V_438 = 1 ;
}
V_437 = F_239 ( - V_442 ) ;
for ( V_183 = 0 ; V_183 < V_438 ; V_183 ++ ) {
int V_14 = ( V_428 + V_183 ) & 0x1f ;
snprintf ( V_439 , sizeof( V_439 ) , V_443 ,
L_43 , V_14 ) ;
V_437 = F_240 ( V_2 -> V_21 , V_439 , F_89 ,
V_444 ) ;
if ( ! F_228 ( V_437 ) ) {
F_235 ( V_2 , V_14 ) ;
break;
}
}
return V_437 ;
}
static void F_241 ( struct V_1 * V_2 , int V_175 , int V_181 )
{
struct V_436 * V_171 = V_2 -> V_171 ;
if ( V_175 == 0 ) {
V_171 -> V_172 = V_173 ;
V_171 -> V_175 = 0 ;
V_171 -> V_181 = 0 ;
V_171 -> V_234 = V_171 -> V_232 | V_445 ;
} else {
V_171 -> V_172 = V_252 ;
V_171 -> V_234 = 0 ;
V_171 -> V_175 = V_175 ;
V_171 -> V_181 = V_181 ;
}
F_242 ( V_171 ) ;
}
static void F_243 ( struct V_1 * V_2 , int V_175 , int V_181 )
{
T_1 V_164 ;
V_164 = F_3 ( V_2 , V_165 ) ;
if ( V_164 & V_361 ) {
V_164 &= ~ V_361 ;
F_6 ( V_2 , V_165 , V_164 ) ;
}
V_164 = V_446 | V_447 ;
if ( V_2 -> V_171 == NULL ) {
V_164 |= V_168 ;
if ( V_175 == V_176 )
V_164 |= V_177 ;
else if ( V_175 == V_179 )
V_164 |= V_180 ;
V_164 |= V_169 ;
V_164 |= V_170 ;
if ( V_181 == V_182 )
V_164 |= V_178 ;
}
F_6 ( V_2 , V_165 , V_164 ) ;
}
static int F_244 ( struct V_395 * V_396 )
{
struct V_400 * V_422 ;
struct V_1 * V_2 ;
struct V_95 * V_21 ;
struct V_402 * V_403 ;
int V_49 ;
V_422 = F_231 ( & V_396 -> V_21 ) ;
if ( V_422 == NULL ) {
F_205 ( & V_396 -> V_21 , L_44 ) ;
return - V_442 ;
}
if ( V_422 -> V_4 == NULL ) {
F_205 ( & V_396 -> V_21 , L_45 ) ;
return - V_442 ;
}
V_21 = F_245 ( sizeof( struct V_1 ) , 8 ) ;
if ( ! V_21 )
return - V_103 ;
V_2 = F_69 ( V_21 ) ;
F_224 ( V_396 , V_2 ) ;
V_2 -> V_4 = F_233 ( V_422 -> V_4 ) ;
V_2 -> V_5 = V_2 -> V_4 -> V_5 + 0x0400 + ( V_422 -> V_406 << 10 ) ;
V_2 -> V_185 = V_422 -> V_406 ;
V_2 -> V_21 = V_21 ;
if ( F_246 ( V_396 -> V_21 . V_419 ,
L_46 ) )
F_6 ( V_2 , V_448 ,
F_3 ( V_2 , V_448 ) & ~ V_449 ) ;
V_2 -> V_150 = 133000000 ;
V_2 -> V_429 = F_227 ( & V_396 -> V_21 , NULL ) ;
if ( ! F_228 ( V_2 -> V_429 ) ) {
F_229 ( V_2 -> V_429 ) ;
V_2 -> V_150 = F_247 ( V_2 -> V_429 ) ;
} else if ( ! F_228 ( V_2 -> V_4 -> V_429 ) ) {
V_2 -> V_150 = F_247 ( V_2 -> V_4 -> V_429 ) ;
}
F_237 ( V_2 , V_422 ) ;
F_248 ( V_21 , V_2 -> V_184 ) ;
F_249 ( V_21 , V_2 -> V_364 ) ;
V_49 = 0 ;
if ( V_422 -> V_414 ) {
V_2 -> V_171 = F_250 ( V_2 -> V_21 , V_422 -> V_414 ,
F_89 , 0 ,
V_444 ) ;
if ( ! V_2 -> V_171 )
V_49 = - V_442 ;
else
F_235 ( V_2 , V_2 -> V_171 -> V_14 ) ;
} else if ( V_422 -> V_415 != V_416 ) {
V_2 -> V_171 = F_238 ( V_2 , V_422 -> V_415 ) ;
if ( F_228 ( V_2 -> V_171 ) )
V_49 = F_251 ( V_2 -> V_171 ) ;
else
F_241 ( V_2 , V_422 -> V_175 , V_422 -> V_181 ) ;
}
if ( V_49 == - V_442 ) {
V_49 = - V_450 ;
goto V_139;
}
if ( V_49 )
goto V_139;
V_21 -> V_451 = & V_452 ;
F_243 ( V_2 , V_422 -> V_175 , V_422 -> V_181 ) ;
F_93 ( V_2 ) ;
F_252 ( & V_2 -> V_223 ) ;
V_2 -> V_223 . V_6 = ( unsigned long ) V_2 ;
V_2 -> V_223 . V_453 = F_97 ;
V_2 -> V_223 . V_370 = V_224 + 30 * V_225 ;
F_253 ( & V_2 -> V_189 ) ;
F_254 ( & V_2 -> F_192 , F_192 ) ;
F_255 ( V_21 , & V_2 -> V_54 , F_169 , V_454 ) ;
F_252 ( & V_2 -> V_358 ) ;
V_2 -> V_358 . V_6 = ( unsigned long ) V_2 ;
V_2 -> V_358 . V_453 = F_175 ;
V_403 = F_223 ( V_396 , V_455 , 0 ) ;
F_44 ( ! V_403 ) ;
V_21 -> V_348 = V_403 -> V_428 ;
V_21 -> V_456 = & V_457 ;
V_21 -> V_458 = 2 * V_225 ;
V_21 -> V_459 = 0 ;
V_21 -> V_282 = V_460 | V_461 | V_462 ;
V_21 -> V_463 = V_21 -> V_282 ;
V_21 -> V_282 |= V_284 ;
V_21 -> V_464 = V_21 -> V_282 ;
V_21 -> V_465 |= V_466 ;
V_21 -> V_467 = V_468 ;
F_256 ( V_21 , & V_396 -> V_21 ) ;
if ( V_2 -> V_4 -> V_387 )
F_4 ( V_2 , F_257 ( V_2 -> V_185 ) , V_2 -> V_4 -> V_387 ) ;
F_167 ( V_21 ) ;
F_6 ( V_2 , V_226 , V_469 ) ;
F_101 ( V_2 , 250 ) ;
F_103 ( V_2 , 0 ) ;
V_49 = F_258 ( V_21 ) ;
if ( V_49 )
goto V_139;
F_259 ( V_21 , L_47 ,
V_2 -> V_185 , V_21 -> V_305 ) ;
if ( V_2 -> V_333 > 0 )
F_259 ( V_21 , L_48 ) ;
return 0 ;
V_139:
if ( ! F_228 ( V_2 -> V_429 ) )
F_234 ( V_2 -> V_429 ) ;
F_260 ( V_21 ) ;
return V_49 ;
}
static int F_261 ( struct V_395 * V_396 )
{
struct V_1 * V_2 = F_233 ( V_396 ) ;
F_262 ( V_2 -> V_21 ) ;
if ( V_2 -> V_171 != NULL )
F_263 ( V_2 -> V_171 ) ;
F_264 ( & V_2 -> F_192 ) ;
if ( ! F_228 ( V_2 -> V_429 ) )
F_234 ( V_2 -> V_429 ) ;
F_260 ( V_2 -> V_21 ) ;
return 0 ;
}
static void F_265 ( struct V_395 * V_396 )
{
struct V_1 * V_2 = F_233 ( V_396 ) ;
F_6 ( V_2 , V_351 , 0 ) ;
F_3 ( V_2 , V_351 ) ;
if ( F_127 ( V_2 -> V_21 ) )
F_185 ( V_2 ) ;
}
static int T_15 F_266 ( void )
{
int V_470 ;
V_470 = F_267 ( & V_471 ) ;
if ( ! V_470 ) {
V_470 = F_267 ( & V_472 ) ;
if ( V_470 )
F_268 ( & V_471 ) ;
}
return V_470 ;
}
static void T_16 F_269 ( void )
{
F_268 ( & V_472 ) ;
F_268 ( & V_471 ) ;
}
