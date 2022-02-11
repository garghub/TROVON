static inline T_1 F_1 ( const struct V_1 * V_2 )
{
return V_2 -> V_3 & ~ ( T_1 ) ( V_4 | V_5 ) ;
}
static inline bool F_2 ( const struct V_1 * V_2 )
{
return ! ( V_2 -> V_3 & V_5 ) ;
}
static inline unsigned int F_3 ( const struct V_6 * V_7 )
{
return V_7 -> V_8 - 1 - V_7 -> V_9 ;
}
static inline unsigned int F_4 ( const struct V_10 * V_11 )
{
return V_11 -> V_8 - 8 ;
}
static inline bool F_5 ( const struct V_10 * V_11 )
{
return V_11 -> V_12 - V_11 -> V_13 <= V_14 ;
}
static int F_6 ( struct V_15 * V_16 , const struct V_17 * V_18 ,
T_1 * V_19 )
{
const T_2 * V_20 , * V_21 ;
const struct V_22 * V_23 ;
* V_19 = F_7 ( V_16 , V_18 -> V_24 , F_8 ( V_18 ) , V_25 ) ;
if ( F_9 ( V_16 , * V_19 ) )
goto V_26;
V_23 = F_10 ( V_18 ) ;
V_21 = & V_23 -> V_27 [ V_23 -> V_28 ] ;
for ( V_20 = V_23 -> V_27 ; V_20 < V_21 ; V_20 ++ ) {
* ++ V_19 = F_11 ( V_16 , V_20 -> V_29 , V_20 -> V_30 , V_20 -> V_8 ,
V_25 ) ;
if ( F_9 ( V_16 , * V_19 ) )
goto V_31;
}
return 0 ;
V_31:
while ( V_20 -- > V_23 -> V_27 )
F_12 ( V_16 , * -- V_19 , V_20 -> V_8 , V_25 ) ;
F_13 ( V_16 , V_19 [ - 1 ] , F_8 ( V_18 ) , V_25 ) ;
V_26:
return - V_32 ;
}
static void F_14 ( struct V_15 * V_16 , const struct V_17 * V_18 ,
const T_1 * V_19 )
{
const T_2 * V_20 , * V_21 ;
const struct V_22 * V_23 ;
F_13 ( V_16 , * V_19 ++ , F_8 ( V_18 ) , V_25 ) ;
V_23 = F_10 ( V_18 ) ;
V_21 = & V_23 -> V_27 [ V_23 -> V_28 ] ;
for ( V_20 = V_23 -> V_27 ; V_20 < V_21 ; V_20 ++ )
F_12 ( V_16 , * V_19 ++ , V_20 -> V_8 , V_25 ) ;
}
static void F_15 ( struct V_17 * V_18 )
{
F_14 ( V_18 -> V_16 -> V_16 . V_33 , V_18 , ( T_1 * ) V_18 -> V_34 ) ;
}
static void F_16 ( struct V_15 * V_16 , const struct V_17 * V_18 ,
const struct V_35 * V_36 , const struct V_6 * V_7 )
{
const struct V_37 * V_38 ;
unsigned int V_39 = F_10 ( V_18 ) -> V_28 ;
if ( F_17 ( F_8 ( V_18 ) ) )
F_13 ( V_16 , F_18 ( V_36 -> V_40 ) , F_19 ( V_36 -> V_41 ) ,
V_25 ) ;
else {
F_12 ( V_16 , F_18 ( V_36 -> V_40 ) , F_19 ( V_36 -> V_41 ) ,
V_25 ) ;
V_39 -- ;
}
for ( V_38 = V_36 -> V_42 ; V_39 >= 2 ; V_39 -= 2 ) {
if ( F_17 ( ( V_43 * ) ( V_38 + 1 ) <= ( V_43 * ) V_7 -> V_44 ) ) {
V_45: F_12 ( V_16 , F_18 ( V_38 -> V_19 [ 0 ] ) ,
F_19 ( V_38 -> V_46 [ 0 ] ) , V_25 ) ;
F_12 ( V_16 , F_18 ( V_38 -> V_19 [ 1 ] ) ,
F_19 ( V_38 -> V_46 [ 1 ] ) , V_25 ) ;
V_38 ++ ;
} else if ( ( V_43 * ) V_38 == ( V_43 * ) V_7 -> V_44 ) {
V_38 = ( const struct V_37 * ) V_7 -> V_47 ;
goto V_45;
} else if ( ( V_43 * ) V_38 + 8 == ( V_43 * ) V_7 -> V_44 ) {
const T_3 * V_19 = ( const T_3 * ) V_7 -> V_47 ;
F_12 ( V_16 , F_18 ( V_19 [ 0 ] ) ,
F_19 ( V_38 -> V_46 [ 0 ] ) , V_25 ) ;
F_12 ( V_16 , F_18 ( V_19 [ 1 ] ) ,
F_19 ( V_38 -> V_46 [ 1 ] ) , V_25 ) ;
V_38 = ( const struct V_37 * ) & V_19 [ 2 ] ;
} else {
const T_3 * V_19 = ( const T_3 * ) V_7 -> V_47 ;
F_12 ( V_16 , F_18 ( V_38 -> V_19 [ 0 ] ) ,
F_19 ( V_38 -> V_46 [ 0 ] ) , V_25 ) ;
F_12 ( V_16 , F_18 ( V_19 [ 0 ] ) ,
F_19 ( V_38 -> V_46 [ 1 ] ) , V_25 ) ;
V_38 = ( const struct V_37 * ) & V_19 [ 1 ] ;
}
}
if ( V_39 ) {
T_3 V_19 ;
if ( ( V_43 * ) V_38 == ( V_43 * ) V_7 -> V_44 )
V_38 = ( const struct V_37 * ) V_7 -> V_47 ;
V_19 = ( V_43 * ) V_38 + 16 <= ( V_43 * ) V_7 -> V_44 ? V_38 -> V_19 [ 0 ] :
* ( const T_3 * ) V_7 -> V_47 ;
F_12 ( V_16 , F_18 ( V_19 ) , F_19 ( V_38 -> V_46 [ 0 ] ) ,
V_25 ) ;
}
}
static void F_20 ( struct V_48 * V_49 , struct V_6 * V_7 ,
unsigned int V_50 , bool V_45 )
{
struct V_51 * V_2 ;
unsigned int V_52 = V_7 -> V_52 ;
struct V_15 * V_16 = V_49 -> V_53 ;
V_2 = & V_7 -> V_54 [ V_52 ] ;
while ( V_50 -- ) {
if ( V_2 -> V_18 ) {
if ( V_45 )
F_16 ( V_16 , V_2 -> V_18 , V_2 -> V_36 , V_7 ) ;
F_21 ( V_2 -> V_18 ) ;
V_2 -> V_18 = NULL ;
}
++ V_2 ;
if ( ++ V_52 == V_7 -> V_8 ) {
V_52 = 0 ;
V_2 = V_7 -> V_54 ;
}
}
V_7 -> V_52 = V_52 ;
}
static inline int F_22 ( const struct V_6 * V_7 )
{
int V_55 = F_23 ( V_7 -> V_44 -> V_52 ) ;
V_55 -= V_7 -> V_52 ;
return V_55 < 0 ? V_55 + V_7 -> V_8 : V_55 ;
}
static inline void F_24 ( struct V_48 * V_49 , struct V_6 * V_7 ,
bool V_45 )
{
int V_12 = F_22 ( V_7 ) ;
if ( V_12 ) {
if ( V_12 > V_56 )
V_12 = V_56 ;
F_20 ( V_49 , V_7 , V_12 , V_45 ) ;
V_7 -> V_9 -= V_12 ;
}
}
static inline int F_25 ( const struct V_1 * V_2 )
{
#if V_57 > 0
return ( V_2 -> V_3 & V_4 ) ? ( V_58 << V_57 ) :
V_58 ;
#else
return V_58 ;
#endif
}
static void F_26 ( struct V_48 * V_49 , struct V_10 * V_7 , int V_50 )
{
while ( V_50 -- ) {
struct V_1 * V_2 = & V_7 -> V_54 [ V_7 -> V_52 ] ;
if ( F_2 ( V_2 ) )
F_12 ( V_49 -> V_53 , F_1 ( V_2 ) ,
F_25 ( V_2 ) , V_59 ) ;
F_27 ( V_2 -> V_29 ) ;
V_2 -> V_29 = NULL ;
if ( ++ V_7 -> V_52 == V_7 -> V_8 )
V_7 -> V_52 = 0 ;
V_7 -> V_12 -- ;
}
}
static void F_28 ( struct V_48 * V_49 , struct V_10 * V_7 )
{
struct V_1 * V_2 = & V_7 -> V_54 [ V_7 -> V_52 ] ;
if ( F_2 ( V_2 ) )
F_12 ( V_49 -> V_53 , F_1 ( V_2 ) ,
F_25 ( V_2 ) , V_59 ) ;
V_2 -> V_29 = NULL ;
if ( ++ V_7 -> V_52 == V_7 -> V_8 )
V_7 -> V_52 = 0 ;
V_7 -> V_12 -- ;
}
static inline void F_29 ( struct V_48 * V_49 , struct V_10 * V_7 )
{
if ( V_7 -> V_13 >= 8 ) {
F_30 () ;
F_31 ( V_49 , F_32 ( V_60 ) , V_61 |
F_33 ( V_7 -> V_62 ) | F_34 ( V_7 -> V_13 / 8 ) ) ;
V_7 -> V_13 &= 7 ;
}
}
static inline void F_35 ( struct V_1 * V_63 , struct V_29 * V_64 ,
T_1 V_65 )
{
V_63 -> V_29 = V_64 ;
V_63 -> V_3 = V_65 ;
}
static unsigned int F_36 ( struct V_48 * V_49 , struct V_10 * V_7 , int V_50 ,
T_4 V_66 )
{
struct V_29 * V_64 ;
T_1 V_65 ;
unsigned int V_67 = V_7 -> V_12 ;
T_3 * V_2 = & V_7 -> V_47 [ V_7 -> V_68 ] ;
struct V_1 * V_63 = & V_7 -> V_54 [ V_7 -> V_68 ] ;
V_66 |= V_69 ;
#if V_57 > 0
while ( V_50 ) {
V_64 = F_37 ( V_66 | V_70 , V_57 ) ;
if ( F_38 ( ! V_64 ) ) {
V_7 -> V_71 ++ ;
break;
}
V_65 = F_11 ( V_49 -> V_53 , V_64 , 0 ,
V_58 << V_57 ,
V_59 ) ;
if ( F_38 ( F_9 ( V_49 -> V_53 , V_65 ) ) ) {
F_39 ( V_64 , V_57 ) ;
goto V_72;
}
V_65 |= V_4 ;
* V_2 ++ = F_40 ( V_65 ) ;
F_35 ( V_63 , V_64 , V_65 ) ;
V_63 ++ ;
V_7 -> V_12 ++ ;
if ( ++ V_7 -> V_68 == V_7 -> V_8 ) {
V_7 -> V_68 = 0 ;
V_63 = V_7 -> V_54 ;
V_2 = V_7 -> V_47 ;
}
V_50 -- ;
}
#endif
while ( V_50 -- ) {
V_64 = F_41 ( V_49 -> V_73 [ 0 ] , V_66 ) ;
if ( F_38 ( ! V_64 ) ) {
V_7 -> V_74 ++ ;
break;
}
V_65 = F_11 ( V_49 -> V_53 , V_64 , 0 , V_58 ,
V_59 ) ;
if ( F_38 ( F_9 ( V_49 -> V_53 , V_65 ) ) ) {
F_42 ( V_49 -> V_73 [ 0 ] , V_64 ) ;
goto V_72;
}
* V_2 ++ = F_40 ( V_65 ) ;
F_35 ( V_63 , V_64 , V_65 ) ;
V_63 ++ ;
V_7 -> V_12 ++ ;
if ( ++ V_7 -> V_68 == V_7 -> V_8 ) {
V_7 -> V_68 = 0 ;
V_63 = V_7 -> V_54 ;
V_2 = V_7 -> V_47 ;
}
}
V_72: V_67 = V_7 -> V_12 - V_67 ;
V_7 -> V_13 += V_67 ;
F_29 ( V_49 , V_7 ) ;
if ( F_38 ( F_5 ( V_7 ) ) ) {
F_43 () ;
F_44 ( V_7 -> V_62 - V_49 -> V_42 . V_75 ,
V_49 -> V_42 . V_76 ) ;
}
return V_67 ;
}
static inline void F_45 ( struct V_48 * V_49 , struct V_10 * V_11 )
{
F_36 ( V_49 , V_11 , F_46 ( V_77 , F_4 ( V_11 ) - V_11 -> V_12 ) ,
V_78 ) ;
}
static void * F_47 ( struct V_15 * V_16 , T_5 V_79 , T_5 V_80 ,
T_5 V_81 , T_1 * V_82 , void * V_83 ,
T_5 V_84 , int V_85 )
{
T_5 V_46 = V_79 * V_80 + V_84 ;
void * V_86 = NULL ;
void * V_38 = F_48 ( V_16 , V_46 , V_82 , V_87 ) ;
if ( ! V_38 )
return NULL ;
if ( V_81 ) {
V_86 = F_49 ( V_79 * V_81 , V_87 , V_85 ) ;
if ( ! V_86 ) {
F_50 ( V_16 , V_46 , V_38 , * V_82 ) ;
return NULL ;
}
}
if ( V_83 )
* ( void * * ) V_83 = V_86 ;
memset ( V_38 , 0 , V_46 ) ;
return V_38 ;
}
static inline unsigned int F_51 ( unsigned int V_50 )
{
V_50 -- ;
return ( 3 * V_50 ) / 2 + ( V_50 & 1 ) + 2 ;
}
static inline unsigned int F_52 ( unsigned int V_50 )
{
F_53 ( V_50 > V_88 / 8 ) ;
return F_54 ( V_50 , 8 ) ;
}
static inline int F_55 ( const struct V_17 * V_18 )
{
return V_18 -> V_46 <= V_89 - sizeof( struct V_90 ) ;
}
static inline unsigned int F_56 ( const struct V_17 * V_18 )
{
unsigned int V_91 ;
if ( F_55 ( V_18 ) )
return F_54 ( V_18 -> V_46 + sizeof( struct V_90 ) , 8 ) ;
V_91 = F_51 ( F_10 ( V_18 ) -> V_28 + 1 ) + 4 ;
if ( F_10 ( V_18 ) -> V_92 )
V_91 += 2 ;
return V_91 ;
}
static inline unsigned int F_57 ( const struct V_17 * V_18 )
{
return F_52 ( F_56 ( V_18 ) ) ;
}
static void F_58 ( const struct V_17 * V_18 , struct V_6 * V_7 ,
struct V_35 * V_36 , T_6 * V_21 , unsigned int V_93 ,
const T_1 * V_19 )
{
unsigned int V_94 , V_46 ;
struct V_37 * V_95 ;
const struct V_22 * V_23 = F_10 ( V_18 ) ;
unsigned int V_39 = V_23 -> V_28 ;
struct V_37 V_96 [ V_97 / 2 + 1 ] ;
V_46 = F_8 ( V_18 ) - V_93 ;
if ( F_17 ( V_46 ) ) {
V_36 -> V_41 = F_59 ( V_46 ) ;
V_36 -> V_40 = F_40 ( V_19 [ 0 ] + V_93 ) ;
V_39 ++ ;
} else {
V_36 -> V_41 = F_59 ( V_23 -> V_27 [ 0 ] . V_8 ) ;
V_36 -> V_40 = F_40 ( V_19 [ 1 ] ) ;
}
V_36 -> V_98 = F_59 ( F_60 ( V_99 ) | F_61 ( V_39 ) ) ;
if ( F_17 ( -- V_39 == 0 ) )
return;
V_95 = ( V_43 * ) V_21 > ( V_43 * ) V_7 -> V_44 ? V_96 : V_36 -> V_42 ;
for ( V_94 = ( V_39 != V_23 -> V_28 ) ; V_39 >= 2 ; V_39 -= 2 , V_95 ++ ) {
V_95 -> V_46 [ 0 ] = F_62 ( V_23 -> V_27 [ V_94 ] . V_8 ) ;
V_95 -> V_46 [ 1 ] = F_62 ( V_23 -> V_27 [ ++ V_94 ] . V_8 ) ;
V_95 -> V_19 [ 0 ] = F_40 ( V_19 [ V_94 ] ) ;
V_95 -> V_19 [ 1 ] = F_40 ( V_19 [ ++ V_94 ] ) ;
}
if ( V_39 ) {
V_95 -> V_46 [ 0 ] = F_62 ( V_23 -> V_27 [ V_94 ] . V_8 ) ;
V_95 -> V_46 [ 1 ] = F_62 ( 0 ) ;
V_95 -> V_19 [ 0 ] = F_40 ( V_19 [ V_94 + 1 ] ) ;
}
if ( F_38 ( ( V_43 * ) V_21 > ( V_43 * ) V_7 -> V_44 ) ) {
unsigned int V_100 = ( V_43 * ) V_7 -> V_44 - ( V_43 * ) V_36 -> V_42 , V_101 ;
if ( F_17 ( V_100 ) )
memcpy ( V_36 -> V_42 , V_96 , V_100 ) ;
V_101 = ( V_43 * ) V_21 - ( V_43 * ) V_7 -> V_44 ;
memcpy ( V_7 -> V_47 , ( V_43 * ) V_96 + V_100 , V_101 ) ;
V_21 = ( void * ) V_7 -> V_47 + V_101 ;
}
if ( ( V_102 ) V_21 & 8 )
* ( T_6 * ) V_21 = 0 ;
}
static inline void F_63 ( struct V_48 * V_49 , struct V_6 * V_7 , int V_50 )
{
F_30 () ;
F_31 ( V_49 , F_32 ( V_60 ) ,
F_33 ( V_7 -> V_62 ) | F_34 ( V_50 ) ) ;
}
static void F_64 ( const struct V_17 * V_18 , const struct V_6 * V_7 ,
void * V_103 )
{
T_6 * V_38 ;
int V_104 = ( void * ) V_7 -> V_44 - V_103 ;
if ( F_17 ( V_18 -> V_46 <= V_104 ) ) {
if ( F_17 ( ! V_18 -> V_105 ) )
F_65 ( V_18 , V_103 , V_18 -> V_46 ) ;
else
F_66 ( V_18 , 0 , V_103 , V_18 -> V_46 ) ;
V_103 += V_18 -> V_46 ;
} else {
F_66 ( V_18 , 0 , V_103 , V_104 ) ;
F_66 ( V_18 , V_104 , V_7 -> V_47 , V_18 -> V_46 - V_104 ) ;
V_103 = ( void * ) V_7 -> V_47 + ( V_18 -> V_46 - V_104 ) ;
}
V_38 = F_67 ( V_103 , 8 ) ;
if ( ( V_102 ) V_38 & 8 )
* V_38 = 0 ;
}
static T_6 F_68 ( const struct V_17 * V_18 )
{
int V_106 ;
const struct V_107 * V_108 = F_69 ( V_18 ) ;
if ( V_108 -> V_109 == 4 ) {
if ( V_108 -> V_110 == V_111 )
V_106 = V_112 ;
else if ( V_108 -> V_110 == V_113 )
V_106 = V_114 ;
else {
V_115:
return V_116 ;
}
} else {
const struct V_117 * V_118 = ( const struct V_117 * ) V_108 ;
if ( V_118 -> V_119 == V_111 )
V_106 = V_120 ;
else if ( V_118 -> V_119 == V_113 )
V_106 = V_121 ;
else
goto V_115;
}
if ( F_17 ( V_106 >= V_112 ) )
return F_70 ( V_106 ) |
F_71 ( F_72 ( V_18 ) ) |
F_73 ( F_74 ( V_18 ) - V_122 ) ;
else {
int V_93 = F_75 ( V_18 ) ;
return F_70 ( V_106 ) | F_76 ( V_93 ) |
F_77 ( V_93 + V_18 -> V_123 ) ;
}
}
static void F_78 ( struct V_124 * V_7 )
{
F_79 ( V_7 -> V_125 ) ;
V_7 -> V_7 . V_126 ++ ;
}
static inline void F_80 ( struct V_6 * V_7 , unsigned int V_50 )
{
V_7 -> V_9 += V_50 ;
V_7 -> V_68 += V_50 ;
if ( V_7 -> V_68 >= V_7 -> V_8 )
V_7 -> V_68 -= V_7 -> V_8 ;
}
T_7 F_81 ( struct V_17 * V_18 , struct V_127 * V_16 )
{
T_8 V_128 ;
T_6 V_129 , * V_21 ;
int V_130 , V_131 ;
unsigned int V_91 , V_132 ;
struct V_48 * V_49 ;
struct V_124 * V_7 ;
const struct V_133 * V_134 ;
struct V_135 * V_136 ;
struct V_137 * V_138 ;
const struct V_22 * V_139 ;
T_1 V_19 [ V_97 + 1 ] ;
if ( F_38 ( V_18 -> V_46 < V_122 ) ) {
V_140: F_82 ( V_18 ) ;
return V_141 ;
}
V_134 = F_83 ( V_16 ) ;
V_49 = V_134 -> V_48 ;
V_130 = F_84 ( V_18 ) ;
V_7 = & V_49 -> V_42 . V_142 [ V_130 + V_134 -> V_143 ] ;
F_24 ( V_49 , & V_7 -> V_7 , true ) ;
V_91 = F_56 ( V_18 ) ;
V_132 = F_52 ( V_91 ) ;
V_131 = F_3 ( & V_7 -> V_7 ) - V_132 ;
if ( F_38 ( V_131 < 0 ) ) {
F_78 ( V_7 ) ;
F_85 ( V_49 -> V_53 ,
L_1 ,
V_16 -> V_144 , V_130 ) ;
return V_145 ;
}
if ( ! F_55 ( V_18 ) &&
F_38 ( F_6 ( V_49 -> V_53 , V_18 , V_19 ) < 0 ) ) {
V_7 -> V_146 ++ ;
goto V_140;
}
V_128 = F_86 ( F_54 ( V_91 , 2 ) ) ;
if ( F_38 ( V_131 < V_147 ) ) {
F_78 ( V_7 ) ;
V_128 |= V_148 | V_149 ;
}
V_136 = ( void * ) & V_7 -> V_7 . V_47 [ V_7 -> V_7 . V_68 ] ;
V_136 -> V_150 = F_59 ( V_128 ) ;
V_136 -> V_151 = F_40 ( 0 ) ;
V_21 = ( T_6 * ) V_136 + V_91 ;
V_139 = F_10 ( V_18 ) ;
if ( V_139 -> V_92 ) {
struct V_152 * V_153 = ( void * ) V_136 ;
bool V_154 = ( V_139 -> V_155 & V_156 ) != 0 ;
int V_157 = F_72 ( V_18 ) ;
int V_158 = F_74 ( V_18 ) - V_122 ;
V_136 -> V_159 = F_59 ( F_87 ( V_160 ) |
F_88 ( sizeof( * V_153 ) ) ) ;
V_153 -> V_161 . V_162 = F_59 ( F_89 ( V_163 ) |
V_164 | V_165 |
F_90 ( V_154 ) |
F_91 ( V_158 / 4 ) |
F_92 ( V_157 / 4 ) |
F_93 ( F_94 ( V_18 ) -> V_166 ) ) ;
V_153 -> V_161 . V_167 = F_95 ( 0 ) ;
V_153 -> V_161 . V_168 = F_95 ( V_139 -> V_92 ) ;
V_153 -> V_161 . V_169 = F_59 ( 0 ) ;
V_153 -> V_161 . V_46 = F_59 ( V_18 -> V_46 ) ;
V_138 = ( void * ) ( V_153 + 1 ) ;
V_129 = F_70 ( V_154 ? V_120 : V_112 ) |
F_71 ( V_157 ) |
F_73 ( V_158 ) ;
V_7 -> V_170 ++ ;
V_7 -> V_171 += V_139 -> V_172 ;
} else {
int V_46 ;
V_46 = F_55 ( V_18 ) ? V_18 -> V_46 + sizeof( * V_138 ) : sizeof( * V_138 ) ;
V_136 -> V_159 = F_59 ( F_87 ( V_160 ) |
F_88 ( V_46 ) ) ;
V_138 = ( void * ) ( V_136 + 1 ) ;
if ( V_18 -> V_173 == V_174 ) {
V_129 = F_68 ( V_18 ) | V_175 ;
V_7 -> V_171 ++ ;
} else
V_129 = V_116 | V_175 ;
}
if ( F_96 ( V_18 ) ) {
V_7 -> V_176 ++ ;
V_129 |= V_177 | F_97 ( F_98 ( V_18 ) ) ;
}
V_138 -> V_178 = F_59 ( F_99 ( V_179 ) |
F_100 ( V_134 -> V_180 ) | F_101 ( V_49 -> V_181 ) ) ;
V_138 -> V_182 = F_95 ( 0 ) ;
V_138 -> V_46 = F_95 ( V_18 -> V_46 ) ;
V_138 -> V_183 = F_40 ( V_129 ) ;
if ( F_55 ( V_18 ) ) {
F_64 ( V_18 , & V_7 -> V_7 , V_138 + 1 ) ;
F_82 ( V_18 ) ;
} else {
int V_184 ;
F_58 ( V_18 , & V_7 -> V_7 , (struct V_35 * ) ( V_138 + 1 ) , V_21 , 0 ,
V_19 ) ;
F_102 ( V_18 ) ;
V_184 = V_7 -> V_7 . V_68 + V_132 - 1 ;
if ( V_184 >= V_7 -> V_7 . V_8 )
V_184 -= V_7 -> V_7 . V_8 ;
V_7 -> V_7 . V_54 [ V_184 ] . V_18 = V_18 ;
V_7 -> V_7 . V_54 [ V_184 ] . V_36 = (struct V_35 * ) ( V_138 + 1 ) ;
}
F_80 ( & V_7 -> V_7 , V_132 ) ;
F_63 ( V_49 , & V_7 -> V_7 , V_132 ) ;
return V_141 ;
}
static inline void F_103 ( struct V_6 * V_7 )
{
int V_55 = F_23 ( V_7 -> V_44 -> V_52 ) ;
int V_185 = V_55 - V_7 -> V_52 ;
if ( V_185 < 0 )
V_185 += V_7 -> V_8 ;
V_7 -> V_9 -= V_185 ;
V_7 -> V_52 = V_55 ;
}
static inline int F_104 ( const struct V_17 * V_18 )
{
return V_18 -> V_46 <= V_186 ;
}
static void F_105 ( struct V_187 * V_7 , struct V_188 * V_136 )
{
F_103 ( & V_7 -> V_7 ) ;
if ( F_38 ( F_3 ( & V_7 -> V_7 ) < V_189 ) ) {
V_136 -> V_190 |= F_59 ( V_148 | V_149 ) ;
V_7 -> V_7 . V_126 ++ ;
V_7 -> V_191 = 1 ;
}
}
static int F_106 ( struct V_187 * V_7 , struct V_17 * V_18 )
{
unsigned int V_132 ;
struct V_188 * V_136 ;
if ( F_38 ( ! F_104 ( V_18 ) ) ) {
F_107 ( 1 ) ;
F_82 ( V_18 ) ;
return V_192 ;
}
V_132 = F_54 ( V_18 -> V_46 , sizeof( struct V_193 ) ) ;
F_108 ( & V_7 -> V_194 . V_195 ) ;
if ( F_38 ( V_7 -> V_191 ) ) {
V_18 -> V_196 = V_132 ;
F_109 ( & V_7 -> V_194 , V_18 ) ;
F_110 ( & V_7 -> V_194 . V_195 ) ;
return V_197 ;
}
V_136 = (struct V_188 * ) & V_7 -> V_7 . V_47 [ V_7 -> V_7 . V_68 ] ;
F_64 ( V_18 , & V_7 -> V_7 , V_136 ) ;
F_80 ( & V_7 -> V_7 , V_132 ) ;
if ( F_38 ( F_3 ( & V_7 -> V_7 ) < V_189 ) )
F_105 ( V_7 , V_136 ) ;
F_63 ( V_7 -> V_49 , & V_7 -> V_7 , V_132 ) ;
F_110 ( & V_7 -> V_194 . V_195 ) ;
F_21 ( V_18 ) ;
return V_198 ;
}
static void F_111 ( unsigned long V_24 )
{
struct V_17 * V_18 ;
unsigned int V_199 = 0 ;
struct V_187 * V_7 = (struct V_187 * ) V_24 ;
F_108 ( & V_7 -> V_194 . V_195 ) ;
F_103 ( & V_7 -> V_7 ) ;
F_53 ( F_3 ( & V_7 -> V_7 ) < V_189 ) ;
while ( ( V_18 = F_112 ( & V_7 -> V_194 ) ) != NULL ) {
struct V_188 * V_136 ;
unsigned int V_132 = V_18 -> V_196 ;
F_110 ( & V_7 -> V_194 . V_195 ) ;
V_136 = (struct V_188 * ) & V_7 -> V_7 . V_47 [ V_7 -> V_7 . V_68 ] ;
F_64 ( V_18 , & V_7 -> V_7 , V_136 ) ;
F_21 ( V_18 ) ;
V_199 += V_132 ;
F_80 ( & V_7 -> V_7 , V_132 ) ;
if ( F_38 ( F_3 ( & V_7 -> V_7 ) < V_189 ) ) {
unsigned long V_200 = V_7 -> V_7 . V_126 ;
F_105 ( V_7 , V_136 ) ;
if ( V_7 -> V_7 . V_126 != V_200 ) {
F_108 ( & V_7 -> V_194 . V_195 ) ;
goto V_201;
}
}
if ( V_199 > 16 ) {
F_63 ( V_7 -> V_49 , & V_7 -> V_7 , V_199 ) ;
V_199 = 0 ;
}
F_108 ( & V_7 -> V_194 . V_195 ) ;
}
V_7 -> V_191 = 0 ;
V_201: if ( V_199 )
F_63 ( V_7 -> V_49 , & V_7 -> V_7 , V_199 ) ;
F_110 ( & V_7 -> V_194 . V_195 ) ;
}
int F_113 ( struct V_48 * V_49 , struct V_17 * V_18 )
{
int V_202 ;
F_114 () ;
V_202 = F_106 ( & V_49 -> V_42 . V_203 [ 0 ] , V_18 ) ;
F_115 () ;
return V_202 ;
}
static inline int F_116 ( const struct V_17 * V_18 )
{
return V_18 -> V_46 <= V_89 ;
}
static inline unsigned int F_117 ( const struct V_17 * V_18 )
{
unsigned int V_91 , V_204 ;
if ( F_116 ( V_18 ) )
return F_54 ( V_18 -> V_46 , 8 ) ;
V_91 = F_75 ( V_18 ) / 8U ;
V_204 = F_10 ( V_18 ) -> V_28 ;
if ( V_18 -> V_205 != V_18 -> V_206 )
V_204 ++ ;
return V_91 + F_51 ( V_204 ) ;
}
static void F_118 ( struct V_207 * V_7 )
{
V_7 -> V_146 ++ ;
V_7 -> V_7 . V_126 ++ ;
F_44 ( V_7 -> V_7 . V_62 - V_7 -> V_49 -> V_42 . V_75 ,
V_7 -> V_49 -> V_42 . V_208 ) ;
}
static void F_119 ( struct V_207 * V_7 , struct V_17 * V_18 )
{
struct V_188 * V_136 = (struct V_188 * ) V_18 -> V_24 ;
V_136 -> V_190 |= F_59 ( V_148 | V_149 ) ;
V_7 -> V_7 . V_126 ++ ;
V_7 -> V_191 = 1 ;
}
static void F_120 ( struct V_207 * V_7 )
{
T_6 * V_103 ;
int V_131 ;
struct V_17 * V_18 ;
unsigned int V_199 = 0 ;
unsigned int V_91 , V_132 ;
while ( ( V_18 = F_121 ( & V_7 -> V_194 ) ) != NULL && ! V_7 -> V_191 ) {
F_110 ( & V_7 -> V_194 . V_195 ) ;
F_24 ( V_7 -> V_49 , & V_7 -> V_7 , false ) ;
V_91 = V_18 -> V_196 ;
V_132 = F_52 ( V_91 ) ;
V_131 = F_3 ( & V_7 -> V_7 ) - V_132 ;
F_53 ( V_131 < 0 ) ;
if ( F_38 ( V_131 < V_189 ) )
F_119 ( V_7 , V_18 ) ;
V_103 = ( T_6 * ) & V_7 -> V_7 . V_47 [ V_7 -> V_7 . V_68 ] ;
if ( F_116 ( V_18 ) )
F_64 ( V_18 , & V_7 -> V_7 , V_103 ) ;
else if ( F_6 ( V_7 -> V_49 -> V_53 , V_18 ,
( T_1 * ) V_18 -> V_34 ) ) {
F_118 ( V_7 ) ;
F_108 ( & V_7 -> V_194 . V_195 ) ;
break;
} else {
int V_184 , V_209 = F_75 ( V_18 ) ;
memcpy ( V_103 , V_18 -> V_24 , V_209 ) ;
F_58 ( V_18 , & V_7 -> V_7 , ( void * ) V_103 + V_209 ,
V_103 + V_91 , V_209 ,
( T_1 * ) V_18 -> V_34 ) ;
#ifdef F_122
V_18 -> V_16 = V_7 -> V_49 -> V_73 [ 0 ] ;
V_18 -> V_210 = F_15 ;
#endif
V_184 = V_7 -> V_7 . V_68 + V_132 - 1 ;
if ( V_184 >= V_7 -> V_7 . V_8 )
V_184 -= V_7 -> V_7 . V_8 ;
V_7 -> V_7 . V_54 [ V_184 ] . V_18 = V_18 ;
}
F_80 ( & V_7 -> V_7 , V_132 ) ;
V_199 += V_132 ;
if ( F_38 ( V_199 > 32 ) ) {
F_63 ( V_7 -> V_49 , & V_7 -> V_7 , V_199 ) ;
V_199 = 0 ;
}
F_108 ( & V_7 -> V_194 . V_195 ) ;
F_123 ( V_18 , & V_7 -> V_194 ) ;
if ( F_116 ( V_18 ) )
F_21 ( V_18 ) ;
}
if ( F_17 ( V_199 ) )
F_63 ( V_7 -> V_49 , & V_7 -> V_7 , V_199 ) ;
}
static int F_124 ( struct V_207 * V_7 , struct V_17 * V_18 )
{
V_18 -> V_196 = F_117 ( V_18 ) ;
F_108 ( & V_7 -> V_194 . V_195 ) ;
F_109 ( & V_7 -> V_194 , V_18 ) ;
if ( V_7 -> V_194 . V_211 == 1 )
F_120 ( V_7 ) ;
F_110 ( & V_7 -> V_194 . V_195 ) ;
return V_198 ;
}
static void F_125 ( unsigned long V_24 )
{
struct V_207 * V_7 = (struct V_207 * ) V_24 ;
F_108 ( & V_7 -> V_194 . V_195 ) ;
V_7 -> V_191 = 0 ;
F_120 ( V_7 ) ;
F_110 ( & V_7 -> V_194 . V_195 ) ;
}
static inline unsigned int F_126 ( const struct V_17 * V_18 )
{
return V_18 -> V_212 >> 1 ;
}
static inline unsigned int F_127 ( const struct V_17 * V_18 )
{
return V_18 -> V_212 & 1 ;
}
static inline int F_128 ( struct V_48 * V_49 , struct V_17 * V_18 )
{
unsigned int V_213 = F_126 ( V_18 ) ;
if ( F_38 ( F_127 ( V_18 ) ) )
return F_106 ( & V_49 -> V_42 . V_203 [ V_213 ] , V_18 ) ;
return F_124 ( & V_49 -> V_42 . V_214 [ V_213 ] , V_18 ) ;
}
int F_129 ( struct V_48 * V_49 , struct V_17 * V_18 )
{
int V_202 ;
F_114 () ;
V_202 = F_128 ( V_49 , V_18 ) ;
F_115 () ;
return V_202 ;
}
int F_130 ( struct V_127 * V_16 , struct V_17 * V_18 )
{
return F_129 ( F_131 ( V_16 ) , V_18 ) ;
}
static inline void F_132 ( struct V_22 * V_139 ,
const struct V_215 * V_216 , unsigned int V_217 )
{
unsigned int V_50 ;
V_139 -> V_27 [ 0 ] . V_29 = V_216 -> V_27 [ 0 ] . V_29 ;
V_139 -> V_27 [ 0 ] . V_30 = V_216 -> V_27 [ 0 ] . V_30 + V_217 ;
V_139 -> V_27 [ 0 ] . V_8 = V_216 -> V_27 [ 0 ] . V_8 - V_217 ;
V_139 -> V_28 = V_216 -> V_39 ;
V_50 = V_216 -> V_39 - 1 ;
if ( V_50 )
memcpy ( & V_139 -> V_27 [ 1 ] , & V_216 -> V_27 [ 1 ] , V_50 * sizeof( T_2 ) ) ;
F_133 ( V_216 -> V_27 [ V_50 ] . V_29 ) ;
}
struct V_17 * F_134 ( const struct V_215 * V_216 ,
unsigned int V_218 , unsigned int V_219 )
{
struct V_17 * V_18 ;
if ( V_216 -> V_220 <= V_221 ) {
V_18 = F_135 ( V_216 -> V_220 ) ;
if ( F_38 ( ! V_18 ) )
goto V_72;
F_136 ( V_18 , V_216 -> V_220 ) ;
F_137 ( V_18 , V_216 -> V_222 , V_216 -> V_220 ) ;
} else {
V_18 = F_135 ( V_218 ) ;
if ( F_38 ( ! V_18 ) )
goto V_72;
F_136 ( V_18 , V_219 ) ;
F_137 ( V_18 , V_216 -> V_222 , V_219 ) ;
F_132 ( F_10 ( V_18 ) , V_216 , V_219 ) ;
V_18 -> V_46 = V_216 -> V_220 ;
V_18 -> V_105 = V_18 -> V_46 - V_219 ;
V_18 -> V_223 += V_18 -> V_105 ;
}
V_72: return V_18 ;
}
static void F_138 ( const struct V_215 * V_216 )
{
int V_50 ;
const T_2 * V_38 ;
for ( V_38 = V_216 -> V_27 , V_50 = V_216 -> V_39 - 1 ; V_50 -- ; V_38 ++ )
F_27 ( V_38 -> V_29 ) ;
}
static T_9 int F_139 ( struct V_48 * V_49 ,
const struct V_215 * V_216 )
{
struct V_17 * V_18 ;
struct V_224 * V_38 ;
V_18 = F_134 ( V_216 , V_225 , V_225 ) ;
if ( F_38 ( ! V_18 ) ) {
F_138 ( V_216 ) ;
return 0 ;
}
V_38 = (struct V_224 * ) V_18 -> V_24 ;
F_140 ( V_18 , sizeof( * V_38 ) ) ;
F_141 ( V_18 ) ;
V_18 -> V_110 = F_95 ( 0xffff ) ;
V_18 -> V_16 = V_49 -> V_73 [ 0 ] ;
F_142 ( V_18 ) ;
return 0 ;
}
static void F_143 ( struct V_226 * V_227 , const struct V_215 * V_216 ,
const struct V_228 * V_229 )
{
int V_202 ;
struct V_17 * V_18 ;
V_18 = F_144 ( & V_227 -> V_230 . V_231 ) ;
if ( F_38 ( ! V_18 ) ) {
F_138 ( V_216 ) ;
V_227 -> V_232 . V_233 ++ ;
return;
}
F_132 ( F_10 ( V_18 ) , V_216 , V_234 ) ;
V_18 -> V_46 = V_216 -> V_220 - V_234 ;
V_18 -> V_105 = V_18 -> V_46 ;
V_18 -> V_223 += V_18 -> V_105 ;
V_18 -> V_173 = V_235 ;
F_145 ( V_18 , V_227 -> V_230 . V_213 ) ;
if ( V_227 -> V_230 . V_236 -> V_237 & V_238 )
V_18 -> V_239 = ( V_240 T_8 ) V_229 -> V_241 . V_242 ;
if ( F_38 ( V_229 -> V_243 ) ) {
F_146 ( V_18 , F_23 ( V_229 -> V_244 ) ) ;
V_227 -> V_232 . V_243 ++ ;
}
V_202 = F_147 ( & V_227 -> V_230 . V_231 ) ;
if ( V_202 == V_245 )
V_227 -> V_232 . V_246 ++ ;
else if ( V_202 == V_247 || V_202 == V_248 )
V_227 -> V_232 . V_249 ++ ;
V_227 -> V_232 . V_250 ++ ;
V_227 -> V_232 . V_251 ++ ;
}
int F_148 ( struct V_252 * V_7 , const T_3 * V_253 ,
const struct V_215 * V_23 )
{
bool V_254 ;
struct V_17 * V_18 ;
const struct V_228 * V_229 ;
struct V_226 * V_227 = F_149 ( V_7 , struct V_226 , V_230 ) ;
if ( F_38 ( * ( V_43 * ) V_253 == V_255 ) )
return F_139 ( V_7 -> V_49 , V_23 ) ;
V_229 = ( const struct V_228 * ) V_253 ;
V_254 = V_229 -> V_256 && ! V_229 -> V_257 ;
if ( ( V_229 -> V_258 & F_59 ( V_259 ) ) &&
( V_7 -> V_236 -> V_237 & V_260 ) && V_254 && ! V_229 -> V_261 ) {
F_143 ( V_227 , V_23 , V_229 ) ;
return 0 ;
}
V_18 = F_134 ( V_23 , V_262 , V_225 ) ;
if ( F_38 ( ! V_18 ) ) {
F_138 ( V_23 ) ;
V_227 -> V_232 . V_233 ++ ;
return 0 ;
}
F_140 ( V_18 , V_234 ) ;
V_18 -> V_110 = F_150 ( V_18 , V_7 -> V_236 ) ;
F_145 ( V_18 , V_7 -> V_213 ) ;
if ( V_18 -> V_16 -> V_237 & V_238 )
V_18 -> V_239 = ( V_240 T_8 ) V_229 -> V_241 . V_242 ;
V_227 -> V_232 . V_250 ++ ;
if ( V_254 && ( V_7 -> V_236 -> V_237 & V_263 ) &&
( V_229 -> V_258 & F_59 ( V_264 | V_259 ) ) ) {
if ( ! V_229 -> V_261 ) {
V_18 -> V_173 = V_235 ;
V_227 -> V_232 . V_251 ++ ;
} else if ( V_229 -> V_258 & F_59 ( V_265 ) ) {
T_10 V_161 = ( V_240 T_10 ) V_229 -> V_266 ;
V_18 -> V_266 = F_151 ( V_161 ) ;
V_18 -> V_173 = V_267 ;
V_227 -> V_232 . V_251 ++ ;
}
} else
F_152 ( V_18 ) ;
if ( F_38 ( V_229 -> V_243 ) ) {
F_146 ( V_18 , F_23 ( V_229 -> V_244 ) ) ;
V_227 -> V_232 . V_243 ++ ;
}
F_142 ( V_18 ) ;
return 0 ;
}
static void F_153 ( const struct V_215 * V_23 , struct V_10 * V_7 ,
int V_27 )
{
struct V_1 * V_2 ;
while ( V_27 -- ) {
if ( V_7 -> V_52 == 0 )
V_7 -> V_52 = V_7 -> V_8 - 1 ;
else
V_7 -> V_52 -- ;
V_2 = & V_7 -> V_54 [ V_7 -> V_52 ] ;
V_2 -> V_29 = V_23 -> V_27 [ V_27 ] . V_29 ;
V_2 -> V_3 |= V_5 ;
V_7 -> V_12 ++ ;
}
}
static inline bool F_154 ( const struct V_268 * V_269 ,
const struct V_252 * V_7 )
{
return F_155 ( V_269 -> V_270 ) == V_7 -> V_271 ;
}
static inline void F_156 ( struct V_252 * V_7 )
{
V_7 -> V_272 = ( void * ) V_7 -> V_272 + V_7 -> V_273 ;
if ( F_38 ( ++ V_7 -> V_52 == V_7 -> V_8 ) ) {
V_7 -> V_52 = 0 ;
V_7 -> V_271 ^= 1 ;
V_7 -> V_272 = V_7 -> V_47 ;
}
}
static int F_157 ( struct V_252 * V_7 , int V_274 )
{
int V_202 , V_275 ;
int V_276 = V_274 ;
const struct V_268 * V_277 ;
struct V_226 * V_227 = F_149 ( V_7 , struct V_226 , V_230 ) ;
while ( F_17 ( V_276 ) ) {
V_277 = ( void * ) V_7 -> V_272 + ( V_7 -> V_273 - sizeof( * V_277 ) ) ;
if ( ! F_154 ( V_277 , V_7 ) )
break;
F_158 () ;
V_275 = F_159 ( V_277 -> V_270 ) ;
if ( F_17 ( V_275 == V_278 ) ) {
T_2 * V_20 ;
struct V_215 V_23 ;
const struct V_1 * V_279 ;
T_8 V_46 = F_19 ( V_277 -> V_280 ) , V_281 , V_27 ;
if ( V_46 & V_282 ) {
if ( F_17 ( V_7 -> V_217 > 0 ) ) {
F_26 ( V_7 -> V_49 , & V_227 -> V_11 , 1 ) ;
V_7 -> V_217 = 0 ;
}
V_46 = F_160 ( V_46 ) ;
}
V_23 . V_220 = V_46 ;
for ( V_27 = 0 , V_20 = V_23 . V_27 ; ; V_27 ++ , V_20 ++ ) {
V_279 = & V_227 -> V_11 . V_54 [ V_227 -> V_11 . V_52 ] ;
V_281 = F_25 ( V_279 ) ;
V_20 -> V_29 = V_279 -> V_29 ;
V_20 -> V_30 = V_7 -> V_217 ;
V_20 -> V_8 = F_46 ( V_281 , V_46 ) ;
V_46 -= V_20 -> V_8 ;
if ( ! V_46 )
break;
F_28 ( V_7 -> V_49 , & V_227 -> V_11 ) ;
}
F_161 ( V_7 -> V_49 -> V_53 ,
F_1 ( V_279 ) ,
V_20 -> V_8 , V_283 ) ;
V_23 . V_222 = F_162 ( V_23 . V_27 [ 0 ] . V_29 ) +
V_23 . V_27 [ 0 ] . V_30 ;
F_163 ( V_23 . V_222 ) ;
V_23 . V_39 = V_27 + 1 ;
V_202 = V_7 -> V_284 ( V_7 , V_7 -> V_272 , & V_23 ) ;
if ( F_17 ( V_202 == 0 ) )
V_7 -> V_217 += F_164 ( V_20 -> V_8 , V_285 ) ;
else
F_153 ( & V_23 , & V_227 -> V_11 , V_27 ) ;
} else if ( F_17 ( V_275 == V_286 ) ) {
V_202 = V_7 -> V_284 ( V_7 , V_7 -> V_272 , NULL ) ;
} else {
V_202 = V_7 -> V_284 ( V_7 , ( const T_3 * ) V_277 , V_287 ) ;
}
if ( F_38 ( V_202 ) ) {
V_7 -> V_288 = F_165 ( V_289 ) ;
break;
}
F_156 ( V_7 ) ;
V_276 -- ;
}
if ( V_7 -> V_217 >= 0 && V_227 -> V_11 . V_8 - V_227 -> V_11 . V_12 >= 16 )
F_45 ( V_7 -> V_49 , & V_227 -> V_11 ) ;
return V_274 - V_276 ;
}
static int F_166 ( struct V_290 * V_231 , int V_274 )
{
unsigned int V_291 ;
struct V_252 * V_7 = F_149 ( V_231 , struct V_252 , V_231 ) ;
int V_292 = F_157 ( V_7 , V_274 ) ;
if ( F_17 ( V_292 < V_274 ) ) {
F_167 ( V_231 ) ;
V_291 = V_7 -> V_288 ;
V_7 -> V_288 = V_7 -> V_293 ;
} else
V_291 = F_165 ( 7 ) ;
F_31 ( V_7 -> V_49 , F_32 ( V_294 ) , F_168 ( V_292 ) |
F_169 ( ( T_8 ) V_7 -> V_62 ) | F_170 ( V_291 ) ) ;
return V_292 ;
}
T_11 F_171 ( int V_295 , void * V_296 )
{
struct V_252 * V_7 = V_296 ;
F_172 ( & V_7 -> V_231 ) ;
return V_297 ;
}
static unsigned int F_173 ( struct V_48 * V_49 )
{
unsigned int V_131 ;
const struct V_268 * V_277 ;
struct V_252 * V_7 = & V_49 -> V_42 . V_298 ;
F_108 ( & V_49 -> V_42 . V_299 ) ;
for ( V_131 = 0 ; ; V_131 ++ ) {
V_277 = ( void * ) V_7 -> V_272 + ( V_7 -> V_273 - sizeof( * V_277 ) ) ;
if ( ! F_154 ( V_277 , V_7 ) )
break;
F_158 () ;
if ( F_159 ( V_277 -> V_270 ) == V_300 ) {
unsigned int V_301 = F_19 ( V_277 -> V_280 ) ;
V_301 -= V_49 -> V_42 . V_302 ;
F_172 ( & V_49 -> V_42 . V_303 [ V_301 ] -> V_231 ) ;
}
F_156 ( V_7 ) ;
}
F_31 ( V_49 , F_32 ( V_294 ) , F_168 ( V_131 ) |
F_169 ( V_7 -> V_62 ) | F_170 ( V_7 -> V_293 ) ) ;
F_110 ( & V_49 -> V_42 . V_299 ) ;
return V_131 ;
}
static T_11 F_174 ( int V_295 , void * V_296 )
{
struct V_48 * V_49 = V_296 ;
F_175 ( V_49 ) ;
F_173 ( V_49 ) ;
return V_297 ;
}
static T_11 F_176 ( int V_295 , void * V_296 )
{
struct V_48 * V_49 = V_296 ;
F_31 ( V_49 , F_32 ( V_304 ) , 0 ) ;
if ( F_175 ( V_49 ) | F_173 ( V_49 ) )
return V_297 ;
return V_305 ;
}
T_12 F_177 ( struct V_48 * V_49 )
{
if ( V_49 -> V_306 & V_307 )
return F_171 ;
if ( V_49 -> V_306 & V_308 )
return F_174 ;
return F_176 ;
}
static void F_178 ( unsigned long V_24 )
{
unsigned long V_309 ;
unsigned int V_94 , V_204 [ 2 ] ;
struct V_48 * V_49 = (struct V_48 * ) V_24 ;
struct V_42 * V_86 = & V_49 -> V_42 ;
for ( V_94 = 0 ; V_94 < F_179 ( V_86 -> V_76 ) ; V_94 ++ )
for ( V_309 = V_86 -> V_76 [ V_94 ] ; V_309 ; V_309 &= V_309 - 1 ) {
struct V_226 * V_227 ;
unsigned int V_310 = F_180 ( V_309 ) + V_94 * V_311 ;
struct V_10 * V_11 = V_86 -> V_312 [ V_310 ] ;
F_181 ( V_310 , V_86 -> V_76 ) ;
F_182 () ;
if ( F_5 ( V_11 ) ) {
V_227 = F_149 ( V_11 , struct V_226 , V_11 ) ;
if ( F_183 ( & V_227 -> V_230 . V_231 ) )
V_11 -> V_313 ++ ;
else
F_44 ( V_310 , V_86 -> V_76 ) ;
}
}
F_31 ( V_49 , V_314 , 13 ) ;
V_204 [ 0 ] = F_184 ( V_49 , V_315 ) ;
V_204 [ 1 ] = F_184 ( V_49 , V_316 ) ;
for ( V_94 = 0 ; V_94 < 2 ; V_94 ++ )
if ( V_204 [ V_94 ] >= V_86 -> V_317 ) {
if ( V_86 -> V_318 [ V_94 ] || V_204 [ V_94 ] == 0xffffffff )
continue;
V_86 -> V_318 [ V_94 ] = 1 ;
F_31 ( V_49 , V_314 , 11 ) ;
V_309 = F_184 ( V_49 , V_316 ) >> ( V_94 * 16 ) ;
F_185 ( V_49 -> V_53 ,
L_2
L_3 , V_94 , V_309 & 0xffff ) ;
} else if ( V_86 -> V_318 [ V_94 ] )
V_86 -> V_318 [ V_94 ] = 0 ;
F_186 ( & V_86 -> V_319 , V_320 + V_321 ) ;
}
static void F_187 ( unsigned long V_24 )
{
unsigned long V_309 ;
unsigned int V_94 , V_274 ;
struct V_48 * V_49 = (struct V_48 * ) V_24 ;
struct V_42 * V_86 = & V_49 -> V_42 ;
for ( V_94 = 0 ; V_94 < F_179 ( V_86 -> V_208 ) ; V_94 ++ )
for ( V_309 = V_86 -> V_208 [ V_94 ] ; V_309 ; V_309 &= V_309 - 1 ) {
unsigned long V_310 = F_180 ( V_309 ) + V_94 * V_311 ;
struct V_207 * V_125 = V_86 -> V_312 [ V_310 ] ;
F_181 ( V_310 , V_86 -> V_208 ) ;
F_188 ( & V_125 -> V_322 ) ;
}
V_274 = V_323 ;
V_94 = V_86 -> V_324 ;
do {
struct V_124 * V_7 = & V_86 -> V_142 [ V_94 ] ;
if ( V_7 -> V_7 . V_9 &&
F_189 ( V_320 , V_7 -> V_125 -> V_325 + V_326 / 100 ) &&
F_190 ( V_7 -> V_125 ) ) {
int V_12 = F_22 ( & V_7 -> V_7 ) ;
if ( V_12 ) {
if ( V_12 > V_274 )
V_12 = V_274 ;
F_20 ( V_49 , & V_7 -> V_7 , V_12 , true ) ;
V_7 -> V_7 . V_9 -= V_12 ;
V_274 -= V_12 ;
}
F_191 ( V_7 -> V_125 ) ;
}
if ( ++ V_94 >= V_86 -> V_327 )
V_94 = 0 ;
} while ( V_274 && V_94 != V_86 -> V_324 );
V_86 -> V_324 = V_94 ;
F_186 ( & V_86 -> V_328 , V_320 + ( V_274 ? V_329 : 2 ) ) ;
}
int F_192 ( struct V_48 * V_49 , struct V_252 * V_330 , bool V_331 ,
struct V_127 * V_16 , int V_332 ,
struct V_10 * V_11 , T_13 V_333 )
{
int V_202 , V_334 = 0 ;
struct V_335 V_161 ;
struct V_133 * V_134 = F_83 ( V_16 ) ;
V_330 -> V_8 = F_193 ( V_330 -> V_8 , 16 ) ;
V_330 -> V_47 = F_47 ( V_49 -> V_53 , V_330 -> V_8 , V_330 -> V_273 , 0 ,
& V_330 -> V_336 , NULL , 0 , V_337 ) ;
if ( ! V_330 -> V_47 )
return - V_32 ;
memset ( & V_161 , 0 , sizeof( V_161 ) ) ;
V_161 . V_338 = F_59 ( F_194 ( V_339 ) | V_340 |
V_341 | V_342 |
F_195 ( V_49 -> V_181 ) | F_196 ( 0 ) ) ;
V_161 . V_343 = F_59 ( V_344 | F_197 ( 1 ) |
F_198 ( V_161 ) ) ;
V_161 . V_345 = F_59 ( F_199 ( V_346 ) |
F_200 ( V_331 ) | F_201 ( V_134 -> V_347 ) |
F_202 ( V_332 < 0 ) | F_203 ( 1 ) |
F_204 ( V_332 >= 0 ? V_332 :
- V_332 - 1 ) ) ;
V_161 . V_348 = F_95 ( F_205 ( V_134 -> V_180 ) |
V_349 |
F_206 ( V_330 -> V_350 ) |
F_207 ( F_208 ( V_330 -> V_273 ) - 4 ) ) ;
V_161 . V_351 = F_95 ( V_330 -> V_8 ) ;
V_161 . V_352 = F_40 ( V_330 -> V_336 ) ;
if ( V_11 ) {
V_11 -> V_8 = F_193 ( V_11 -> V_8 , 8 ) ;
V_11 -> V_47 = F_47 ( V_49 -> V_53 , V_11 -> V_8 , sizeof( T_3 ) ,
sizeof( struct V_1 ) , & V_11 -> V_19 ,
& V_11 -> V_54 , V_353 , V_337 ) ;
if ( ! V_11 -> V_47 )
goto V_354;
V_334 = V_11 -> V_8 / 8 + V_353 / sizeof( struct V_193 ) ;
V_161 . V_355 = F_59 ( V_356 |
F_209 ( 1 ) |
F_210 ( 1 ) |
V_357 ) ;
V_161 . V_358 = F_95 ( F_211 ( 2 ) |
F_212 ( 3 ) ) ;
V_161 . V_359 = F_95 ( V_334 ) ;
V_161 . V_360 = F_40 ( V_11 -> V_19 ) ;
}
V_202 = F_213 ( V_49 , V_49 -> V_181 , & V_161 , sizeof( V_161 ) , & V_161 ) ;
if ( V_202 )
goto V_361;
F_214 ( V_16 , & V_330 -> V_231 , F_166 , 64 ) ;
V_330 -> V_272 = V_330 -> V_47 ;
V_330 -> V_52 = 0 ;
V_330 -> V_271 = 1 ;
V_330 -> V_288 = V_330 -> V_293 ;
V_330 -> V_62 = F_23 ( V_161 . V_362 ) ;
V_330 -> V_363 = F_23 ( V_161 . V_364 ) ;
V_330 -> V_8 -- ;
V_330 -> V_49 = V_49 ;
V_330 -> V_236 = V_16 ;
V_330 -> V_284 = V_333 ;
V_330 -> V_217 = V_11 ? 0 : - 1 ;
V_49 -> V_42 . V_303 [ V_330 -> V_62 - V_49 -> V_42 . V_302 ] = V_330 ;
if ( V_11 ) {
V_11 -> V_62 = F_23 ( V_161 . V_365 ) ;
V_11 -> V_12 = V_11 -> V_13 = 0 ;
V_11 -> V_68 = V_11 -> V_52 = 0 ;
V_11 -> V_74 = V_11 -> V_71 = V_11 -> V_313 = 0 ;
V_49 -> V_42 . V_312 [ V_11 -> V_62 - V_49 -> V_42 . V_75 ] = V_11 ;
F_36 ( V_49 , V_11 , F_4 ( V_11 ) , V_87 ) ;
}
return 0 ;
V_354:
V_202 = - V_32 ;
V_361:
if ( V_330 -> V_47 ) {
F_50 ( V_49 -> V_53 , V_330 -> V_8 * V_330 -> V_273 ,
V_330 -> V_47 , V_330 -> V_336 ) ;
V_330 -> V_47 = NULL ;
}
if ( V_11 && V_11 -> V_47 ) {
F_215 ( V_11 -> V_54 ) ;
V_11 -> V_54 = NULL ;
F_50 ( V_49 -> V_53 , V_334 * sizeof( struct V_193 ) ,
V_11 -> V_47 , V_11 -> V_19 ) ;
V_11 -> V_47 = NULL ;
}
return V_202 ;
}
static void F_216 ( struct V_48 * V_49 , struct V_6 * V_7 , unsigned int V_310 )
{
V_7 -> V_9 = 0 ;
V_7 -> V_52 = V_7 -> V_68 = 0 ;
V_7 -> V_126 = V_7 -> V_366 = 0 ;
V_7 -> V_44 = ( void * ) & V_7 -> V_47 [ V_7 -> V_8 ] ;
V_7 -> V_62 = V_310 ;
V_49 -> V_42 . V_312 [ V_310 - V_49 -> V_42 . V_75 ] = V_7 ;
}
int F_217 ( struct V_48 * V_49 , struct V_124 * V_125 ,
struct V_127 * V_16 , struct V_367 * V_368 ,
unsigned int V_362 )
{
int V_202 , V_369 ;
struct V_370 V_161 ;
struct V_133 * V_134 = F_83 ( V_16 ) ;
V_369 = V_125 -> V_7 . V_8 + V_353 / sizeof( struct V_193 ) ;
V_125 -> V_7 . V_47 = F_47 ( V_49 -> V_53 , V_125 -> V_7 . V_8 ,
sizeof( struct V_193 ) , sizeof( struct V_51 ) ,
& V_125 -> V_7 . V_336 , & V_125 -> V_7 . V_54 , V_353 ,
F_218 ( V_368 ) ) ;
if ( ! V_125 -> V_7 . V_47 )
return - V_32 ;
memset ( & V_161 , 0 , sizeof( V_161 ) ) ;
V_161 . V_338 = F_59 ( F_194 ( V_371 ) | V_340 |
V_341 | V_342 |
F_219 ( V_49 -> V_181 ) | F_220 ( 0 ) ) ;
V_161 . V_343 = F_59 ( V_372 |
V_373 | F_198 ( V_161 ) ) ;
V_161 . V_374 = F_59 ( F_221 ( V_134 -> V_347 ) ) ;
V_161 . V_375 = F_59 ( F_222 ( 2 ) |
F_223 ( V_134 -> V_180 ) |
F_224 ( 1 ) |
F_225 ( V_362 ) ) ;
V_161 . V_376 = F_59 ( F_226 ( 2 ) |
F_227 ( 3 ) |
F_228 ( 5 ) |
F_229 ( V_369 ) ) ;
V_161 . V_377 = F_40 ( V_125 -> V_7 . V_336 ) ;
V_202 = F_213 ( V_49 , V_49 -> V_181 , & V_161 , sizeof( V_161 ) , & V_161 ) ;
if ( V_202 ) {
F_215 ( V_125 -> V_7 . V_54 ) ;
V_125 -> V_7 . V_54 = NULL ;
F_50 ( V_49 -> V_53 ,
V_369 * sizeof( struct V_193 ) ,
V_125 -> V_7 . V_47 , V_125 -> V_7 . V_336 ) ;
V_125 -> V_7 . V_47 = NULL ;
return V_202 ;
}
F_216 ( V_49 , & V_125 -> V_7 , F_230 ( F_19 ( V_161 . V_378 ) ) ) ;
V_125 -> V_125 = V_368 ;
V_125 -> V_170 = V_125 -> V_171 = V_125 -> V_176 = 0 ;
V_125 -> V_146 = 0 ;
return 0 ;
}
int F_231 ( struct V_48 * V_49 , struct V_187 * V_125 ,
struct V_127 * V_16 , unsigned int V_362 ,
unsigned int V_379 )
{
int V_202 , V_369 ;
struct V_380 V_161 ;
struct V_133 * V_134 = F_83 ( V_16 ) ;
V_369 = V_125 -> V_7 . V_8 + V_353 / sizeof( struct V_193 ) ;
V_125 -> V_7 . V_47 = F_47 ( V_49 -> V_53 , V_369 ,
sizeof( struct V_193 ) , 0 , & V_125 -> V_7 . V_336 ,
NULL , 0 , V_337 ) ;
if ( ! V_125 -> V_7 . V_47 )
return - V_32 ;
V_161 . V_338 = F_59 ( F_194 ( V_381 ) | V_340 |
V_341 | V_342 |
F_232 ( V_49 -> V_181 ) |
F_233 ( 0 ) ) ;
V_161 . V_343 = F_59 ( V_382 |
V_383 | F_198 ( V_161 ) ) ;
V_161 . V_384 = F_59 ( F_234 ( V_379 ) ) ;
V_161 . V_385 = F_59 ( 0 ) ;
V_161 . V_375 = F_59 ( F_235 ( 2 ) |
F_236 ( V_134 -> V_180 ) |
V_386 |
F_237 ( V_362 ) ) ;
V_161 . V_376 = F_59 ( F_238 ( 2 ) |
F_239 ( 3 ) |
F_240 ( 5 ) |
F_241 ( V_369 ) ) ;
V_161 . V_377 = F_40 ( V_125 -> V_7 . V_336 ) ;
V_202 = F_213 ( V_49 , V_49 -> V_181 , & V_161 , sizeof( V_161 ) , & V_161 ) ;
if ( V_202 ) {
F_50 ( V_49 -> V_53 ,
V_369 * sizeof( struct V_193 ) ,
V_125 -> V_7 . V_47 , V_125 -> V_7 . V_336 ) ;
V_125 -> V_7 . V_47 = NULL ;
return V_202 ;
}
F_216 ( V_49 , & V_125 -> V_7 , F_242 ( F_19 ( V_161 . V_384 ) ) ) ;
V_125 -> V_49 = V_49 ;
F_243 ( & V_125 -> V_194 ) ;
F_244 ( & V_125 -> V_322 , F_111 , ( unsigned long ) V_125 ) ;
V_125 -> V_191 = 0 ;
return 0 ;
}
int F_245 ( struct V_48 * V_49 , struct V_207 * V_125 ,
struct V_127 * V_16 , unsigned int V_362 )
{
int V_202 , V_369 ;
struct V_387 V_161 ;
struct V_133 * V_134 = F_83 ( V_16 ) ;
V_369 = V_125 -> V_7 . V_8 + V_353 / sizeof( struct V_193 ) ;
V_125 -> V_7 . V_47 = F_47 ( V_49 -> V_53 , V_125 -> V_7 . V_8 ,
sizeof( struct V_193 ) , sizeof( struct V_51 ) ,
& V_125 -> V_7 . V_336 , & V_125 -> V_7 . V_54 , V_353 ,
V_337 ) ;
if ( ! V_125 -> V_7 . V_47 )
return - V_32 ;
memset ( & V_161 , 0 , sizeof( V_161 ) ) ;
V_161 . V_338 = F_59 ( F_194 ( V_388 ) | V_340 |
V_341 | V_342 |
F_246 ( V_49 -> V_181 ) |
F_247 ( 0 ) ) ;
V_161 . V_343 = F_59 ( V_389 |
V_390 | F_198 ( V_161 ) ) ;
V_161 . V_375 = F_59 ( F_248 ( 2 ) |
F_249 ( V_134 -> V_180 ) |
F_250 ( 1 ) |
F_251 ( V_362 ) ) ;
V_161 . V_376 = F_59 ( F_252 ( 2 ) |
F_253 ( 3 ) |
F_254 ( 5 ) |
F_255 ( V_369 ) ) ;
V_161 . V_377 = F_40 ( V_125 -> V_7 . V_336 ) ;
V_202 = F_213 ( V_49 , V_49 -> V_181 , & V_161 , sizeof( V_161 ) , & V_161 ) ;
if ( V_202 ) {
F_215 ( V_125 -> V_7 . V_54 ) ;
V_125 -> V_7 . V_54 = NULL ;
F_50 ( V_49 -> V_53 ,
V_369 * sizeof( struct V_193 ) ,
V_125 -> V_7 . V_47 , V_125 -> V_7 . V_336 ) ;
V_125 -> V_7 . V_47 = NULL ;
return V_202 ;
}
F_216 ( V_49 , & V_125 -> V_7 , F_256 ( F_19 ( V_161 . V_378 ) ) ) ;
V_125 -> V_49 = V_49 ;
F_243 ( & V_125 -> V_194 ) ;
F_244 ( & V_125 -> V_322 , F_125 , ( unsigned long ) V_125 ) ;
V_125 -> V_191 = 0 ;
V_125 -> V_146 = 0 ;
return 0 ;
}
static void F_257 ( struct V_48 * V_49 , struct V_6 * V_7 )
{
F_50 ( V_49 -> V_53 ,
V_7 -> V_8 * sizeof( struct V_193 ) + V_353 ,
V_7 -> V_47 , V_7 -> V_336 ) ;
V_7 -> V_62 = 0 ;
V_7 -> V_54 = NULL ;
V_7 -> V_47 = NULL ;
}
static void F_258 ( struct V_48 * V_49 , struct V_252 * V_391 ,
struct V_10 * V_11 )
{
unsigned int V_392 = V_11 ? V_11 -> V_62 : 0xffff ;
V_49 -> V_42 . V_303 [ V_391 -> V_62 - V_49 -> V_42 . V_302 ] = NULL ;
F_259 ( V_49 , V_49 -> V_181 , V_49 -> V_181 , 0 , V_346 ,
V_391 -> V_62 , V_392 , 0xffff ) ;
F_50 ( V_49 -> V_53 , ( V_391 -> V_8 + 1 ) * V_391 -> V_273 ,
V_391 -> V_47 , V_391 -> V_336 ) ;
F_260 ( & V_391 -> V_231 ) ;
V_391 -> V_236 = NULL ;
V_391 -> V_62 = V_391 -> V_363 = 0 ;
V_391 -> V_47 = NULL ;
if ( V_11 ) {
F_26 ( V_49 , V_11 , V_11 -> V_12 ) ;
F_50 ( V_49 -> V_53 , V_11 -> V_8 * 8 + V_353 ,
V_11 -> V_47 , V_11 -> V_19 ) ;
F_215 ( V_11 -> V_54 ) ;
V_11 -> V_54 = NULL ;
V_11 -> V_62 = 0 ;
V_11 -> V_47 = NULL ;
}
}
void F_261 ( struct V_48 * V_49 )
{
int V_94 ;
struct V_226 * V_393 = V_49 -> V_42 . V_394 ;
struct V_124 * V_395 = V_49 -> V_42 . V_142 ;
struct V_396 * V_397 = V_49 -> V_42 . V_398 ;
for ( V_94 = 0 ; V_94 < V_49 -> V_42 . V_327 ; V_94 ++ , V_393 ++ , V_395 ++ ) {
if ( V_393 -> V_230 . V_47 )
F_258 ( V_49 , & V_393 -> V_230 , & V_393 -> V_11 ) ;
if ( V_395 -> V_7 . V_47 ) {
F_262 ( V_49 , V_49 -> V_181 , V_49 -> V_181 , 0 ,
V_395 -> V_7 . V_62 ) ;
F_20 ( V_49 , & V_395 -> V_7 , V_395 -> V_7 . V_9 , true ) ;
F_215 ( V_395 -> V_7 . V_54 ) ;
F_257 ( V_49 , & V_395 -> V_7 ) ;
}
}
for ( V_94 = 0 ; V_94 < V_49 -> V_42 . V_399 ; V_94 ++ , V_397 ++ ) {
if ( V_397 -> V_230 . V_47 )
F_258 ( V_49 , & V_397 -> V_230 , & V_397 -> V_11 ) ;
}
for ( V_94 = 0 , V_397 = V_49 -> V_42 . V_400 ; V_94 < V_49 -> V_42 . V_401 ; V_94 ++ , V_397 ++ ) {
if ( V_397 -> V_230 . V_47 )
F_258 ( V_49 , & V_397 -> V_230 , & V_397 -> V_11 ) ;
}
for ( V_94 = 0 ; V_94 < F_179 ( V_49 -> V_42 . V_214 ) ; V_94 ++ ) {
struct V_207 * V_7 = & V_49 -> V_42 . V_214 [ V_94 ] ;
if ( V_7 -> V_7 . V_47 ) {
F_263 ( & V_7 -> V_322 ) ;
F_264 ( V_49 , V_49 -> V_181 , V_49 -> V_181 , 0 ,
V_7 -> V_7 . V_62 ) ;
F_20 ( V_49 , & V_7 -> V_7 , V_7 -> V_7 . V_9 , false ) ;
F_215 ( V_7 -> V_7 . V_54 ) ;
F_265 ( & V_7 -> V_194 ) ;
F_257 ( V_49 , & V_7 -> V_7 ) ;
}
}
for ( V_94 = 0 ; V_94 < F_179 ( V_49 -> V_42 . V_203 ) ; V_94 ++ ) {
struct V_187 * V_402 = & V_49 -> V_42 . V_203 [ V_94 ] ;
if ( V_402 -> V_7 . V_47 ) {
F_263 ( & V_402 -> V_322 ) ;
F_266 ( V_49 , V_49 -> V_181 , V_49 -> V_181 , 0 ,
V_402 -> V_7 . V_62 ) ;
F_265 ( & V_402 -> V_194 ) ;
F_257 ( V_49 , & V_402 -> V_7 ) ;
}
}
if ( V_49 -> V_42 . V_403 . V_47 )
F_258 ( V_49 , & V_49 -> V_42 . V_403 , NULL ) ;
if ( V_49 -> V_42 . V_298 . V_47 )
F_258 ( V_49 , & V_49 -> V_42 . V_298 , NULL ) ;
memset ( V_49 -> V_42 . V_312 , 0 , sizeof( V_49 -> V_42 . V_312 ) ) ;
}
void F_267 ( struct V_48 * V_49 )
{
V_49 -> V_42 . V_324 = 0 ;
F_186 ( & V_49 -> V_42 . V_319 , V_320 + V_321 ) ;
F_186 ( & V_49 -> V_42 . V_328 , V_320 + V_329 ) ;
}
void F_268 ( struct V_48 * V_49 )
{
int V_94 ;
struct V_42 * V_86 = & V_49 -> V_42 ;
if ( F_269 () )
return;
if ( V_86 -> V_319 . V_404 )
F_270 ( & V_86 -> V_319 ) ;
if ( V_86 -> V_328 . V_404 )
F_270 ( & V_86 -> V_328 ) ;
for ( V_94 = 0 ; V_94 < F_179 ( V_86 -> V_214 ) ; V_94 ++ ) {
struct V_207 * V_7 = & V_86 -> V_214 [ V_94 ] ;
if ( V_7 -> V_7 . V_47 )
F_263 ( & V_7 -> V_322 ) ;
}
for ( V_94 = 0 ; V_94 < F_179 ( V_86 -> V_203 ) ; V_94 ++ ) {
struct V_187 * V_402 = & V_86 -> V_203 [ V_94 ] ;
if ( V_402 -> V_7 . V_47 )
F_263 ( & V_402 -> V_322 ) ;
}
}
void F_271 ( struct V_48 * V_49 )
{
unsigned int V_94 , V_405 ;
struct V_42 * V_86 = & V_49 -> V_42 ;
unsigned int V_406 = F_208 ( V_285 ) ;
F_272 ( V_49 , V_407 , V_408 |
V_409 | V_410 ,
F_273 ( V_406 - 5 ) | F_274 ( 2 ) |
V_411 |
( V_353 == 128 ? V_410 : 0 ) ) ;
for ( V_94 = V_405 = 0 ; V_94 < 32 ; V_94 += 4 )
V_405 |= ( V_412 - 10 ) << V_94 ;
F_31 ( V_49 , V_413 , V_405 ) ;
F_31 ( V_49 , V_414 , V_58 ) ;
#if V_57 > 0
F_31 ( V_49 , V_415 , V_58 << V_57 ) ;
#endif
F_31 ( V_49 , V_416 ,
F_275 ( V_86 -> V_417 [ 0 ] ) |
F_276 ( V_86 -> V_417 [ 1 ] ) |
F_277 ( V_86 -> V_417 [ 2 ] ) |
F_278 ( V_86 -> V_417 [ 3 ] ) ) ;
F_31 ( V_49 , V_418 ,
F_279 ( F_280 ( V_49 , V_86 -> V_419 [ 0 ] ) ) |
F_281 ( F_280 ( V_49 , V_86 -> V_419 [ 1 ] ) ) ) ;
F_31 ( V_49 , V_420 ,
F_279 ( F_280 ( V_49 , V_86 -> V_419 [ 2 ] ) ) |
F_281 ( F_280 ( V_49 , V_86 -> V_419 [ 3 ] ) ) ) ;
F_31 ( V_49 , V_421 ,
F_279 ( F_280 ( V_49 , V_86 -> V_419 [ 4 ] ) ) |
F_281 ( F_280 ( V_49 , V_86 -> V_419 [ 5 ] ) ) ) ;
F_282 ( & V_86 -> V_319 , F_178 , ( unsigned long ) V_49 ) ;
F_282 ( & V_86 -> V_328 , F_187 , ( unsigned long ) V_49 ) ;
V_86 -> V_317 = F_283 ( V_49 ) * 1000000 ;
V_86 -> V_318 [ 0 ] = V_86 -> V_318 [ 1 ] = 0 ;
F_284 ( & V_86 -> V_299 ) ;
}
