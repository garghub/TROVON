static void F_1 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
V_3 -> V_4 = F_2 ( & V_2 -> V_4 ) ;
V_3 -> V_5 = F_2 ( & V_2 -> V_5 ) ;
V_3 -> V_6 = F_2 ( & V_2 -> V_6 ) ;
}
static void F_3 ( struct V_1 * V_3 , struct V_1 * V_2 )
{
F_4 ( V_3 -> V_4 , & V_2 -> V_4 ) ;
F_4 ( V_3 -> V_5 , & V_2 -> V_5 ) ;
F_4 ( V_3 -> V_6 , & V_2 -> V_6 ) ;
}
static inline struct V_7 *
F_5 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
struct V_7 * V_12 ;
F_6 ( & V_9 -> V_13 ) ;
if ( F_7 ( & V_11 -> V_14 ) ) {
V_12 = NULL ;
F_8 ( V_15 ) ;
} else {
V_12 = F_9 ( V_11 -> V_14 . V_16 , struct V_7 ,
V_17 ) ;
F_10 ( & V_12 -> V_17 ) ;
V_11 -> V_18 -- ;
if ( ! V_11 -> V_18 )
V_11 -> V_19 = 0 ;
}
F_11 ( & V_9 -> V_13 ) ;
return V_12 ;
}
static inline struct V_7 *
F_12 ( struct V_8 * V_9 )
{
struct V_7 * V_12 ;
if ( ! ( V_12 = F_13 ( sizeof( struct V_7 ) , V_20 ) ) )
return NULL ;
V_12 -> V_21 = F_13 ( V_9 -> V_22 , V_20 ) ;
if ( ! V_12 -> V_21 ) {
F_14 ( V_12 ) ;
return NULL ;
}
V_12 -> V_21 -> V_23 = 0 ;
V_12 -> V_21 -> V_24 = V_25 ;
V_12 -> V_21 -> V_26 = V_9 -> V_27 ;
V_12 -> V_21 -> V_28 = sizeof( struct V_29 ) ;
V_12 -> V_21 -> V_30 = 0 ;
V_12 -> V_21 -> V_31 = 0 ;
V_12 -> V_32 = ( unsigned char * ) V_12 -> V_21 + sizeof( struct V_29 ) ;
V_12 -> V_33 = ( unsigned char * ) V_12 -> V_21 + V_9 -> V_22 ;
V_12 -> V_34 = V_35 ;
return V_12 ;
}
static inline void F_15 ( struct V_7 * V_12 )
{
F_14 ( V_12 -> V_21 ) ;
F_14 ( V_12 ) ;
}
static inline void F_16 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
struct V_7 * V_12 = V_11 -> V_36 ;
F_17 ( & V_9 -> V_13 ) ;
if ( V_9 -> V_37 & V_38 &&
V_11 -> V_18 < F_18 ( V_9 ) ) {
if ( ! V_11 -> V_18 )
F_19 ( & V_11 -> V_39 ,
F_20 ( V_40 , 1 ) ) ;
V_11 -> V_18 ++ ;
F_21 ( & V_12 -> V_17 , & V_11 -> V_14 ) ;
if ( ( ++ V_11 -> V_19 ) == V_41 )
F_22 ( V_11 -> V_42 ) ;
} else
F_15 ( V_12 ) ;
F_23 ( & V_9 -> V_13 ) ;
}
static inline struct V_7 *
F_24 ( struct V_8 * V_9 , struct V_10 * V_11 ,
unsigned long time )
{
struct V_7 * V_12 ;
F_6 ( & V_9 -> V_43 ) ;
V_12 = V_11 -> V_36 ;
if ( V_12 && F_25 ( V_35 - V_12 -> V_34 , time ) ) {
V_11 -> V_36 = NULL ;
F_8 ( V_44 ) ;
} else
V_12 = NULL ;
F_11 ( & V_9 -> V_43 ) ;
return V_12 ;
}
static inline int
F_26 ( struct V_8 * V_9 , struct V_45 * V_46 )
{
return ( ( long ) V_46 >> ( 1 + F_27 ( sizeof( * V_46 ) ) ) ) & V_9 -> V_47 ;
}
static inline struct V_7 *
F_28 ( struct V_8 * V_9 )
{
struct V_7 * V_12 ;
struct V_48 * V_21 ;
if ( ! ( V_12 = F_13 ( sizeof( struct V_7 ) , V_20 ) ) )
return NULL ;
V_12 -> V_21 = F_13 ( V_9 -> V_22 , V_20 ) ;
if ( ! V_12 -> V_21 ) {
F_14 ( V_12 ) ;
return NULL ;
}
V_21 = (struct V_48 * ) V_12 -> V_21 ;
V_21 -> V_30 = 0 ;
V_21 -> V_26 = V_9 -> V_27 ;
V_21 -> V_28 = sizeof( struct V_48 ) ;
V_12 -> V_32 = ( unsigned char * ) V_21 + sizeof( struct V_48 ) ;
V_12 -> V_33 = ( unsigned char * ) V_21 + V_9 -> V_22 ;
V_12 -> V_34 = V_35 ;
return V_12 ;
}
static int F_29 ( struct V_8 * V_9 ,
struct V_45 * V_46 , int V_49 )
{
unsigned long V_50 = F_30 ( V_46 -> V_51 ) ;
unsigned long V_52 = V_35 ;
unsigned long V_53 = ( V_52 + V_46 -> V_54 ) & ~ 3UL ;
unsigned int V_55 ;
int V_56 ;
int V_57 ;
if ( F_31 ( V_46 -> V_58 & V_59 ) )
V_57 = 0 ;
else if ( F_32 ( V_46 -> V_60 == V_61 ) ) {
if ( ! ( ( 1 << V_46 -> V_62 ) &
( ( 1 << V_63 ) |
( 1 << V_64 ) |
( 1 << V_65 ) |
( 1 << V_66 ) |
( 1 << V_67 ) ) ) )
return 0 ;
V_57 = V_46 -> V_62 != V_46 -> V_68 ;
if ( V_57 && V_46 -> V_62 != V_63 )
goto V_69;
} else if ( F_31 ( V_46 -> V_60 == V_70 ) ) {
if ( ! ( ( 1 << V_46 -> V_62 ) &
( ( 1 << V_71 ) |
( 1 << V_72 ) |
( 1 << V_73 ) |
( 1 << V_74 ) ) ) )
return 0 ;
V_57 = V_46 -> V_62 != V_46 -> V_68 ;
if ( V_57 && V_46 -> V_62 != V_71 )
goto V_69;
} else {
V_57 = 0 ;
}
V_55 = F_33 ( V_9 ) ;
if ( V_55 > 0 ) {
long V_75 = V_53 - V_50 ;
long V_76 = F_20 ( V_46 -> V_54 >> 1 , 10UL * V_77 ) ;
if ( abs ( V_75 ) < F_34 ( long , V_55 , V_76 ) ) {
int V_78 = V_50 & 3 ;
if ( V_78 >= F_35 ( V_9 ) )
return 0 ;
if ( F_36 ( V_52 , V_50 - V_46 -> V_54 +
( V_55 >> 3 ) ) )
return 0 ;
V_53 |= V_78 + 1 ;
}
}
V_56 = F_37 ( V_9 ) ;
if ( V_56 > 0 ) {
if ( ! ( V_46 -> V_58 & V_59 ) &&
V_49 % V_56 != F_38 ( V_9 ) )
return 0 ;
} else if ( V_55 <= 0 &&
V_49 != F_38 ( V_9 ) )
return 0 ;
V_69:
V_46 -> V_68 = V_46 -> V_62 ;
V_53 = F_39 ( & V_46 -> V_51 , V_50 , V_53 ) ;
return V_53 == V_50 || V_57 ;
}
static void F_40 ( struct V_79 * V_79 , struct V_45 * V_46 ,
int V_49 )
{
struct V_8 * V_9 = F_41 ( V_79 ) ;
struct V_48 * V_80 ;
struct F_40 * V_81 ;
struct V_7 * V_82 ;
struct V_10 * V_11 ;
int V_83 ;
int V_84 ;
if ( F_31 ( V_46 -> V_85 != V_86 ) )
return;
if ( V_46 -> V_58 & V_87 )
return;
if ( ! F_29 ( V_9 , V_46 , V_49 ) )
return;
F_17 ( & V_9 -> V_43 ) ;
if ( ! ( V_9 -> V_37 & V_38 ) ) {
F_23 ( & V_9 -> V_43 ) ;
return;
}
V_83 = F_26 ( V_9 , V_46 ) ;
V_11 = & V_9 -> V_11 [ V_83 ] ;
V_82 = V_11 -> V_36 ;
if ( V_82 ) {
V_80 = (struct V_48 * ) V_82 -> V_21 ;
if ( ! V_80 -> V_30 ) {
F_16 ( V_9 , V_11 ) ;
V_11 -> V_36 = NULL ;
V_82 = NULL ;
}
}
if ( ! V_82 ) {
V_82 = F_28 ( V_9 ) ;
if ( ! V_82 ) {
F_23 ( & V_9 -> V_43 ) ;
F_42 ( L_1 ) ;
return;
}
V_11 -> V_36 = V_82 ;
}
V_84 = ( V_46 -> V_58 & V_88 ) ? V_89 :
V_90 ;
V_80 = (struct V_48 * ) V_82 -> V_21 ;
V_81 = (struct F_40 * ) V_82 -> V_32 ;
V_81 -> V_23 = 0 ;
V_81 -> V_60 = V_46 -> V_60 ;
V_81 -> V_91 = V_46 -> V_91 ;
V_81 -> V_92 = V_46 -> V_92 ;
V_81 -> V_93 = V_46 -> V_93 ;
V_81 -> V_94 = V_46 -> V_94 . V_95 ;
V_81 -> V_96 = V_46 -> V_96 . V_95 ;
V_81 -> V_97 = V_46 -> V_97 . V_95 ;
V_81 -> V_58 = F_43 ( V_46 -> V_58 & ~ V_98 ) ;
V_81 -> V_62 = F_43 ( V_46 -> V_62 ) ;
if ( V_46 -> V_58 & V_88 ) {
struct V_99 * V_100 =
(struct V_99 * ) & V_81 [ 1 ] ;
memcpy ( V_100 , & V_46 -> V_101 , sizeof( * V_100 ) ) ;
}
V_80 -> V_30 ++ ;
V_80 -> V_28 += V_84 ;
V_82 -> V_32 += V_84 ;
if ( V_82 -> V_32 + V_89 > V_82 -> V_33 ) {
F_16 ( V_9 , V_11 ) ;
V_11 -> V_36 = NULL ;
}
F_23 ( & V_9 -> V_43 ) ;
V_46 = V_46 -> V_102 ;
if ( V_46 ) {
if ( V_46 -> V_58 & V_59 )
V_49 = F_44 ( 1 , & V_46 -> V_103 ) ;
else
V_49 = F_38 ( V_9 ) ;
F_45 ( V_79 , V_46 -> V_102 , V_49 ) ;
}
}
void F_45 ( struct V_79 * V_79 , struct V_45 * V_46 , int V_49 )
{
struct V_8 * V_9 = F_41 ( V_79 ) ;
struct V_29 * V_80 ;
union F_45 * V_81 ;
struct V_7 * V_82 ;
struct V_10 * V_11 ;
int V_83 ;
T_1 * V_104 ;
unsigned int V_84 , V_105 , V_106 ;
if ( F_46 ( V_9 ) == 0 ) {
F_40 ( V_79 , V_46 , V_49 ) ;
return;
}
if ( V_46 -> V_58 & V_87 )
goto V_102;
V_107:
if ( ! F_29 ( V_9 , V_46 , V_49 ) )
goto V_102;
V_105 = 0 ;
if ( V_46 -> V_108 ) {
if ( ! V_46 -> V_109 || ! V_46 -> V_110 ) {
F_47 ( L_2 ) ;
return;
}
V_105 = F_48 ( V_46 -> V_111 -> V_112 , V_113 ) ;
}
F_17 ( & V_9 -> V_43 ) ;
if ( ! ( V_9 -> V_37 & V_38 ) ) {
F_23 ( & V_9 -> V_43 ) ;
return;
}
V_83 = F_26 ( V_9 , V_46 ) ;
V_11 = & V_9 -> V_11 [ V_83 ] ;
#ifdef F_49
if ( V_46 -> V_85 == V_114 )
V_84 = sizeof( struct V_115 ) ;
else
#endif
V_84 = sizeof( struct V_116 ) ;
if ( V_46 -> V_58 & V_88 )
V_84 += sizeof( struct V_99 ) + 2 ;
if ( V_46 -> V_108 )
V_84 += V_46 -> V_108 + 2 ;
if ( V_105 )
V_84 += V_105 + 2 ;
V_106 = 0 ;
V_82 = V_11 -> V_36 ;
if ( V_82 ) {
V_80 = V_82 -> V_21 ;
V_106 = ( 4 - ( V_117 ) V_82 -> V_32 ) & 3 ;
if ( V_82 -> V_32 + V_84 + V_106 > V_82 -> V_33 || V_80 -> V_23 ) {
F_16 ( V_9 , V_11 ) ;
V_11 -> V_36 = NULL ;
V_82 = NULL ;
V_106 = 0 ;
}
}
if ( ! V_82 ) {
V_82 = F_12 ( V_9 ) ;
if ( ! V_82 ) {
F_23 ( & V_9 -> V_43 ) ;
F_42 ( L_1 ) ;
return;
}
V_11 -> V_36 = V_82 ;
V_80 = V_82 -> V_21 ;
}
V_104 = V_82 -> V_32 ;
V_82 -> V_32 += V_106 + V_84 ;
V_80 -> V_28 += V_106 + V_84 ;
while ( V_106 -- )
* ( V_104 ++ ) = 0 ;
V_81 = (union F_45 * ) V_104 ;
V_81 -> V_118 . type = ( V_46 -> V_85 == V_114 ? V_119 : 0 ) ;
V_81 -> V_118 . V_120 = F_43 ( V_84 & V_121 ) ;
V_81 -> V_118 . V_58 = F_50 ( V_46 -> V_58 & ~ V_98 ) ;
V_81 -> V_118 . V_62 = F_43 ( V_46 -> V_62 ) ;
V_81 -> V_118 . V_60 = V_46 -> V_60 ;
V_81 -> V_118 . V_91 = V_46 -> V_91 ;
V_81 -> V_118 . V_92 = V_46 -> V_92 ;
V_81 -> V_118 . V_93 = V_46 -> V_93 ;
V_81 -> V_118 . V_122 = F_50 ( V_46 -> V_122 ) ;
V_81 -> V_118 . V_54 = F_50 ( V_46 -> V_54 / V_77 ) ;
V_80 -> V_30 ++ ;
#ifdef F_49
if ( V_46 -> V_85 == V_114 ) {
V_104 += sizeof( struct V_115 ) ;
V_81 -> V_123 . V_94 = V_46 -> V_94 . V_124 ;
V_81 -> V_123 . V_96 = V_46 -> V_96 . V_124 ;
V_81 -> V_123 . V_97 = V_46 -> V_97 . V_124 ;
} else
#endif
{
V_104 += sizeof( struct V_116 ) ;
V_81 -> V_118 . V_94 = V_46 -> V_94 . V_95 ;
V_81 -> V_118 . V_96 = V_46 -> V_96 . V_95 ;
V_81 -> V_118 . V_97 = V_46 -> V_97 . V_95 ;
}
if ( V_46 -> V_58 & V_88 ) {
* ( V_104 ++ ) = V_125 ;
* ( V_104 ++ ) = sizeof( struct V_99 ) ;
F_3 ( (struct V_1 * ) V_104 , & V_46 -> V_101 ) ;
V_104 += sizeof( struct V_1 ) ;
F_3 ( (struct V_1 * ) V_104 , & V_46 -> V_126 ) ;
V_104 += sizeof( struct V_1 ) ;
}
if ( V_46 -> V_108 && V_46 -> V_109 ) {
* ( V_104 ++ ) = V_127 ;
* ( V_104 ++ ) = V_46 -> V_108 ;
memcpy ( V_104 , V_46 -> V_109 , V_46 -> V_108 ) ;
V_104 += V_46 -> V_108 ;
if ( V_105 ) {
* ( V_104 ++ ) = V_128 ;
* ( V_104 ++ ) = V_105 ;
memcpy ( V_104 , V_46 -> V_111 -> V_112 , V_105 ) ;
V_104 += V_105 ;
}
}
F_23 ( & V_9 -> V_43 ) ;
V_102:
V_46 = V_46 -> V_102 ;
if ( ! V_46 )
return;
if ( V_46 -> V_58 & V_59 )
V_49 = F_44 ( 1 , & V_46 -> V_103 ) ;
else
V_49 = F_38 ( V_9 ) ;
goto V_107;
}
static inline int
F_51 ( struct V_79 * V_79 , int V_85 , union F_45 * V_129 ,
struct V_130 * V_104 ,
T_1 * V_109 , unsigned int V_108 ,
T_1 * V_131 , unsigned int V_105 )
{
#ifdef F_49
if ( V_85 == V_114 )
F_52 ( V_79 , V_85 , V_129 -> V_123 . V_60 ,
( const union V_132 * ) & V_129 -> V_123 . V_94 ,
V_129 -> V_123 . V_91 ,
( const union V_132 * ) & V_129 -> V_123 . V_96 ,
V_129 -> V_123 . V_92 , V_104 ) ;
else
#endif
F_52 ( V_79 , V_85 , V_129 -> V_118 . V_60 ,
( const union V_132 * ) & V_129 -> V_118 . V_94 ,
V_129 -> V_118 . V_91 ,
( const union V_132 * ) & V_129 -> V_118 . V_96 ,
V_129 -> V_118 . V_92 , V_104 ) ;
if ( V_108 ) {
if ( V_105 ) {
char V_82 [ V_113 + 1 ] ;
memcpy ( V_82 , V_131 , V_105 ) ;
V_82 [ V_105 ] = 0 ;
V_104 -> V_111 = F_53 ( V_82 ) ;
if ( ! V_104 -> V_111 ) {
F_54 ( 3 , L_3 ,
V_82 ) ;
return 1 ;
}
} else {
F_47 ( L_4 ) ;
return 1 ;
}
V_104 -> V_109 = F_55 ( V_109 , V_108 , V_20 ) ;
if ( ! V_104 -> V_109 ) {
if ( V_104 -> V_111 -> V_133 )
F_56 ( V_104 -> V_111 -> V_133 ) ;
return - V_134 ;
}
V_104 -> V_108 = V_108 ;
}
return 0 ;
}
static void F_57 ( struct V_79 * V_79 , struct V_130 * V_135 ,
unsigned int V_58 , unsigned int V_62 ,
unsigned int V_60 , unsigned int type ,
const union V_132 * V_97 , T_2 V_93 ,
unsigned long V_54 , T_3 V_122 ,
struct V_99 * V_100 )
{
struct V_136 * V_110 ;
struct V_45 * V_46 ;
struct V_8 * V_9 = F_41 ( V_79 ) ;
if ( ! ( V_58 & V_59 ) )
V_46 = F_58 ( V_135 ) ;
else
V_46 = F_59 ( V_135 ) ;
if ( V_46 ) {
F_14 ( V_135 -> V_109 ) ;
V_110 = V_46 -> V_110 ;
F_17 ( & V_46 -> V_137 ) ;
if ( ( V_46 -> V_58 ^ V_58 ) & V_138 &&
! ( V_58 & V_59 ) && V_110 ) {
if ( V_58 & V_138 ) {
F_60 ( & V_110 -> V_139 ) ;
F_61 ( & V_110 -> V_140 ) ;
} else {
F_61 ( & V_110 -> V_139 ) ;
F_60 ( & V_110 -> V_140 ) ;
}
}
V_58 &= V_141 ;
V_58 |= V_46 -> V_58 & ~ V_141 ;
V_46 -> V_58 = V_58 ;
F_23 ( & V_46 -> V_137 ) ;
if ( ! V_110 ) {
V_110 = F_62 ( V_46 ) ;
if ( V_110 )
F_60 ( & V_110 -> V_142 ) ;
}
} else {
V_110 = F_63 ( V_79 , type , V_97 , V_93 , V_135 -> V_96 ,
V_135 -> V_92 , V_60 , V_122 , V_58 ) ;
V_46 = F_64 ( V_135 , V_97 , V_93 , V_58 , V_110 , V_122 ) ;
if ( V_110 )
F_60 ( & V_110 -> V_142 ) ;
if ( ! V_46 ) {
if ( V_135 -> V_109 )
F_14 ( V_135 -> V_109 ) ;
F_54 ( 2 , L_5 ) ;
return;
}
}
if ( V_100 )
memcpy ( & V_46 -> V_101 , V_100 , sizeof( * V_100 ) ) ;
F_65 ( & V_46 -> V_103 , F_38 ( V_9 ) ) ;
V_46 -> V_62 = V_62 ;
V_46 -> V_68 = V_46 -> V_62 ;
if ( V_54 ) {
if ( V_54 > V_143 / V_77 )
V_54 = V_143 / V_77 ;
V_46 -> V_54 = V_54 * V_77 ;
} else {
struct V_144 * V_145 ;
V_145 = F_66 ( V_79 , V_60 ) ;
if ( ! ( V_58 & V_59 ) && V_145 && V_145 -> V_146 )
V_46 -> V_54 = V_145 -> V_146 [ V_62 ] ;
else
V_46 -> V_54 = ( 3 * 60 * V_77 ) ;
}
F_67 ( V_46 ) ;
}
static void F_68 ( struct V_79 * V_79 , const char * V_147 ,
const V_117 V_148 )
{
struct V_48 * V_80 = (struct V_48 * ) V_147 ;
struct F_40 * V_81 ;
struct V_99 * V_100 ;
struct V_149 * V_150 ;
struct V_130 V_135 ;
char * V_104 ;
int V_151 ;
V_104 = ( char * ) V_147 + sizeof( struct V_48 ) ;
for ( V_151 = 0 ; V_151 < V_80 -> V_30 ; V_151 ++ ) {
unsigned int V_58 , V_62 ;
if ( V_104 + V_90 > V_147 + V_148 ) {
F_47 ( L_6 ) ;
return;
}
V_81 = (struct F_40 * ) V_104 ;
V_58 = F_69 ( V_81 -> V_58 ) | V_152 ;
V_58 &= ~ V_98 ;
if ( V_58 & V_88 ) {
V_100 = (struct V_99 * ) & V_81 [ 1 ] ;
V_104 += V_89 ;
if ( V_104 > V_147 + V_148 ) {
F_47 ( L_7 ) ;
return;
}
} else {
V_100 = NULL ;
V_104 += V_90 ;
}
V_62 = F_69 ( V_81 -> V_62 ) ;
if ( ! ( V_58 & V_59 ) ) {
V_150 = F_70 ( V_81 -> V_60 ) ;
if ( ! V_150 ) {
F_54 ( 2 , L_8 ,
V_81 -> V_60 ) ;
continue;
}
if ( V_62 >= V_150 -> V_153 ) {
F_54 ( 2 , L_9 ,
V_150 -> V_112 , V_62 ) ;
continue;
}
} else {
if ( V_62 > 0 ) {
F_54 ( 2 , L_10 ,
V_62 ) ;
V_62 = 0 ;
}
}
F_52 ( V_79 , V_86 , V_81 -> V_60 ,
( const union V_132 * ) & V_81 -> V_94 ,
V_81 -> V_91 ,
( const union V_132 * ) & V_81 -> V_96 ,
V_81 -> V_92 , & V_135 ) ;
F_57 ( V_79 , & V_135 , V_58 , V_62 , V_81 -> V_60 , V_86 ,
(union V_132 * ) & V_81 -> V_97 , V_81 -> V_93 ,
0 , 0 , V_100 ) ;
}
}
static inline int F_71 ( T_1 * V_104 , unsigned int V_154 ,
T_3 * V_155 ,
struct V_99 * V_100 )
{
struct V_99 * V_156 ;
V_156 = (struct V_99 * ) V_104 ;
if ( V_154 != sizeof( struct V_99 ) ) {
F_54 ( 2 , L_11 ) ;
return - V_157 ;
}
if ( * V_155 & V_158 ) {
F_54 ( 2 , L_12 ) ;
return - V_157 ;
}
F_1 ( & V_156 -> V_101 , & V_100 -> V_101 ) ;
F_1 ( & V_156 -> V_126 , & V_100 -> V_126 ) ;
* V_155 |= V_158 ;
return 0 ;
}
static int F_72 ( T_1 * V_104 , unsigned int V_154 , unsigned int * V_159 ,
T_1 * * V_160 , unsigned int V_161 ,
T_3 * V_155 , T_3 V_162 )
{
if ( V_154 > V_161 ) {
F_54 ( 2 , L_13 , V_161 ) ;
return - V_157 ;
}
if ( * V_155 & V_162 ) {
F_54 ( 2 , L_14 , V_162 ) ;
return - V_157 ;
}
* V_159 = V_154 ;
* V_160 = V_104 ;
* V_155 |= V_162 ;
return 0 ;
}
static inline int F_73 ( struct V_79 * V_79 , T_1 * V_104 , T_1 * V_163 )
{
struct V_99 V_100 ;
union F_45 * V_81 ;
struct V_149 * V_150 ;
struct V_130 V_135 ;
T_3 V_58 ;
unsigned int V_85 , V_62 , V_108 = 0 , V_105 = 0 ;
T_1 * V_109 = NULL , * V_131 = NULL ;
T_3 V_155 = 0 ;
int V_164 = 0 ;
V_81 = (union F_45 * ) V_104 ;
if ( V_81 -> V_123 . type & V_119 ) {
#ifdef F_49
V_85 = V_114 ;
V_104 += sizeof( struct V_115 ) ;
#else
F_54 ( 3 , L_15 ) ;
V_164 = 10 ;
goto V_165;
#endif
} else if ( ! V_81 -> V_118 . type ) {
V_85 = V_86 ;
V_104 += sizeof( struct V_116 ) ;
} else {
return - 10 ;
}
if ( V_104 > V_163 )
return - 20 ;
while ( V_104 < V_163 ) {
int V_166 ;
int V_154 ;
if ( V_104 + 2 > V_163 )
return - 30 ;
V_166 = * ( V_104 ++ ) ;
V_154 = * ( V_104 ++ ) ;
if ( ! V_154 || ( ( V_104 + V_154 ) > V_163 ) )
return - 40 ;
switch ( V_166 & ~ V_167 ) {
case V_125 :
if ( F_71 ( V_104 , V_154 , & V_155 , & V_100 ) )
return - 50 ;
break;
case V_127 :
if ( F_72 ( V_104 , V_154 , & V_108 , & V_109 ,
V_168 , & V_155 ,
V_169 ) )
return - 60 ;
break;
case V_128 :
if ( F_72 ( V_104 , V_154 , & V_105 , & V_131 ,
V_113 , & V_155 ,
V_170 ) )
return - 70 ;
break;
default:
if ( ! ( V_166 & V_167 ) ) {
F_54 ( 3 , L_16 ,
V_166 & ~ V_167 ) ;
V_164 = 20 ;
goto V_165;
}
}
V_104 += V_154 ;
}
V_58 = F_74 ( V_81 -> V_118 . V_58 ) & V_171 ;
V_58 |= V_152 ;
V_62 = F_69 ( V_81 -> V_118 . V_62 ) ;
if ( ! ( V_58 & V_59 ) ) {
V_150 = F_70 ( V_81 -> V_118 . V_60 ) ;
if ( ! V_150 ) {
F_54 ( 3 , L_17 ,
V_81 -> V_118 . V_60 ) ;
V_164 = 30 ;
goto V_165;
}
if ( V_62 >= V_150 -> V_153 ) {
F_54 ( 3 , L_18 ,
V_150 -> V_112 , V_62 ) ;
V_164 = 40 ;
goto V_165;
}
} else {
if ( V_62 > 0 ) {
F_54 ( 3 , L_19 ,
V_62 ) ;
V_62 = 0 ;
}
}
if ( F_51 ( V_79 , V_85 , V_81 , & V_135 , V_109 ,
V_108 , V_131 , V_105 ) ) {
V_164 = 50 ;
goto V_165;
}
if ( V_85 == V_86 )
F_57 ( V_79 , & V_135 , V_58 , V_62 , V_81 -> V_118 . V_60 , V_85 ,
(union V_132 * ) & V_81 -> V_118 . V_97 , V_81 -> V_118 . V_93 ,
F_74 ( V_81 -> V_118 . V_54 ) , F_74 ( V_81 -> V_118 . V_122 ) ,
( V_155 & V_158 ? & V_100 : NULL )
) ;
#ifdef F_49
else
F_57 ( V_79 , & V_135 , V_58 , V_62 , V_81 -> V_123 . V_60 , V_85 ,
(union V_132 * ) & V_81 -> V_123 . V_97 , V_81 -> V_123 . V_93 ,
F_74 ( V_81 -> V_123 . V_54 ) , F_74 ( V_81 -> V_123 . V_122 ) ,
( V_155 & V_158 ? & V_100 : NULL )
) ;
#endif
return 0 ;
V_165:
F_54 ( 2 , L_20 , V_164 ) ;
return V_164 ;
}
static void F_75 ( struct V_79 * V_79 , T_1 * V_147 ,
const V_117 V_148 )
{
struct V_8 * V_9 = F_41 ( V_79 ) ;
struct V_29 * V_172 = (struct V_29 * ) V_147 ;
T_1 * V_104 , * V_163 ;
int V_151 , V_30 ;
if ( V_148 < sizeof( struct V_48 ) ) {
F_54 ( 2 , L_21 ) ;
return;
}
V_172 -> V_28 = F_69 ( V_172 -> V_28 ) ;
if ( V_148 != V_172 -> V_28 ) {
F_54 ( 2 , L_22 ) ;
return;
}
if ( V_9 -> V_173 != 0 && V_172 -> V_26 != V_9 -> V_173 ) {
F_54 ( 7 , L_23 , V_172 -> V_26 ) ;
return;
}
if ( ( V_172 -> V_24 == V_25 ) && ( V_172 -> V_23 == 0 )
&& ( V_172 -> V_31 == 0 ) ) {
V_163 = V_147 + sizeof( struct V_29 ) ;
V_30 = V_172 -> V_30 ;
for ( V_151 = 0 ; V_151 < V_30 ; V_151 ++ ) {
union F_45 * V_81 ;
unsigned int V_28 ;
int V_164 ;
V_104 = V_163 ;
if ( V_104 + sizeof( V_81 -> V_118 ) > V_147 + V_148 ) {
F_47 ( L_24 ) ;
return;
}
V_81 = (union F_45 * ) V_104 ;
V_28 = F_69 ( V_81 -> V_118 . V_120 ) & V_121 ;
V_163 = V_104 + V_28 ;
if ( V_163 > V_147 + V_148 ) {
F_47 ( L_25 ) ;
return;
}
if ( F_69 ( V_81 -> V_118 . V_120 ) >> V_174 ) {
F_47 ( L_26 ,
F_69 ( V_81 -> V_118 . V_120 ) >> V_174 ) ;
return;
}
V_164 = F_73 ( V_79 , V_104 , V_163 ) ;
if ( V_164 < 0 ) {
F_47 ( L_27 ,
V_164 ) ;
return;
}
V_163 = V_104 + ( ( V_28 + 3 ) & ~ 3 ) ;
}
} else {
F_68 ( V_79 , V_147 , V_148 ) ;
return;
}
}
static void F_76 ( struct V_175 * V_176 , int V_177 , int V_178 )
{
F_77 ( V_176 ) ;
if ( V_177 ) {
V_178 = F_78 ( int , V_178 , ( V_179 + 1 ) / 2 ,
V_180 ) ;
V_176 -> V_181 = V_178 * 2 ;
V_176 -> V_182 |= V_183 ;
} else {
V_178 = F_78 ( int , V_178 , ( V_184 + 1 ) / 2 ,
V_185 ) ;
V_176 -> V_186 = V_178 * 2 ;
V_176 -> V_182 |= V_187 ;
}
F_79 ( V_176 ) ;
}
static void F_80 ( struct V_175 * V_176 , T_4 V_188 )
{
struct V_189 * V_190 = F_81 ( V_176 ) ;
F_77 ( V_176 ) ;
V_190 -> V_191 = V_188 ? 1 : 0 ;
F_79 ( V_176 ) ;
}
static void F_82 ( struct V_175 * V_176 , T_4 V_192 )
{
struct V_189 * V_190 = F_81 ( V_176 ) ;
F_77 ( V_176 ) ;
V_190 -> V_193 = V_192 ;
F_79 ( V_176 ) ;
}
static int F_83 ( struct V_175 * V_176 , char * V_194 )
{
struct V_195 * V_196 ;
struct V_189 * V_190 = F_81 ( V_176 ) ;
struct V_79 * V_79 = F_84 ( V_176 ) ;
V_196 = F_85 ( V_79 , V_194 ) ;
if ( ! V_196 )
return - V_197 ;
if ( V_176 -> V_198 && V_196 -> V_199 != V_176 -> V_198 )
return - V_157 ;
F_77 ( V_176 ) ;
V_190 -> V_200 = V_196 -> V_199 ;
F_79 ( V_176 ) ;
return 0 ;
}
static int F_86 ( struct V_79 * V_79 , int V_37 )
{
struct V_8 * V_9 = F_41 ( V_79 ) ;
struct V_195 * V_196 ;
int V_201 ;
if ( V_37 == V_38 ) {
V_196 = F_85 ( V_79 , V_9 -> V_202 ) ;
if ( ! V_196 )
return - V_197 ;
V_201 = ( V_196 -> V_203 - sizeof( struct V_204 ) -
sizeof( struct V_205 ) -
V_206 - 20 ) / V_90 ;
V_9 -> V_22 = V_206 +
V_90 * F_87 ( V_201 , V_207 ) ;
F_54 ( 7 , L_28
L_29 , V_9 -> V_22 ) ;
} else if ( V_37 == V_208 ) {
V_196 = F_85 ( V_79 , V_9 -> V_209 ) ;
if ( ! V_196 )
return - V_197 ;
V_9 -> V_210 = V_196 -> V_203 -
sizeof( struct V_204 ) - sizeof( struct V_205 ) ;
F_54 ( 7 , L_30
L_29 , V_9 -> V_210 ) ;
}
return 0 ;
}
static int
F_88 ( struct V_175 * V_176 , struct V_211 * V_212 , char * V_194 )
{
struct V_79 * V_79 = F_84 ( V_176 ) ;
struct V_213 V_214 ;
struct V_195 * V_196 ;
int V_215 ;
memset ( & V_214 , 0 , sizeof( V_214 ) ) ;
memcpy ( & V_214 . V_216 , V_212 , sizeof( struct V_211 ) ) ;
V_196 = F_85 ( V_79 , V_194 ) ;
if ( ! V_196 )
return - V_197 ;
if ( V_176 -> V_198 && V_196 -> V_199 != V_176 -> V_198 )
return - V_157 ;
V_214 . V_217 = V_196 -> V_199 ;
F_77 ( V_176 ) ;
V_215 = F_89 ( V_176 , & V_214 ) ;
F_79 ( V_176 ) ;
return V_215 ;
}
static int F_90 ( struct V_218 * V_175 , char * V_194 )
{
struct V_79 * V_79 = F_84 ( V_175 -> V_176 ) ;
struct V_195 * V_196 ;
T_5 V_212 ;
struct V_219 sin ;
V_196 = F_85 ( V_79 , V_194 ) ;
if ( ! V_196 )
return - V_197 ;
V_212 = F_91 ( V_196 , 0 , V_220 ) ;
if ( ! V_212 )
F_42 ( L_31
L_32 ) ;
F_54 ( 7 , L_33 ,
V_194 , & V_212 ) ;
sin . V_221 = V_86 ;
sin . V_222 . V_223 = V_212 ;
sin . V_224 = 0 ;
return V_175 -> V_225 -> V_226 ( V_175 , (struct V_227 * ) & sin , sizeof( sin ) ) ;
}
static struct V_218 * F_92 ( struct V_79 * V_79 , int V_83 )
{
struct V_8 * V_9 = F_41 ( V_79 ) ;
struct V_219 V_228 = {
. V_221 = V_86 ,
. V_224 = F_93 ( V_229 + V_83 ) ,
. V_222 . V_223 = F_94 ( V_230 ) ,
} ;
struct V_218 * V_175 ;
int V_231 ;
V_231 = F_95 ( V_232 , V_233 , V_234 , & V_175 ) ;
if ( V_231 < 0 ) {
F_42 ( L_34 ) ;
return F_96 ( V_231 ) ;
}
F_97 ( V_175 -> V_176 , V_79 ) ;
V_231 = F_83 ( V_175 -> V_176 , V_9 -> V_202 ) ;
if ( V_231 < 0 ) {
F_42 ( L_35 ) ;
goto error;
}
F_80 ( V_175 -> V_176 , 0 ) ;
F_82 ( V_175 -> V_176 , 1 ) ;
V_231 = F_98 ( V_9 ) ;
if ( V_231 > 0 )
F_76 ( V_175 -> V_176 , 1 , V_231 ) ;
V_231 = F_90 ( V_175 , V_9 -> V_202 ) ;
if ( V_231 < 0 ) {
F_42 ( L_36 ) ;
goto error;
}
V_231 = V_175 -> V_225 -> V_235 ( V_175 , (struct V_227 * ) & V_228 ,
sizeof( struct V_227 ) , 0 ) ;
if ( V_231 < 0 ) {
F_42 ( L_37 ) ;
goto error;
}
return V_175 ;
error:
F_99 ( V_175 -> V_176 ) ;
return F_96 ( V_231 ) ;
}
static struct V_218 * F_100 ( struct V_79 * V_79 , int V_83 )
{
struct V_8 * V_9 = F_41 ( V_79 ) ;
struct V_219 V_228 = {
. V_221 = V_86 ,
. V_224 = F_93 ( V_229 + V_83 ) ,
. V_222 . V_223 = F_94 ( V_230 ) ,
} ;
struct V_218 * V_175 ;
int V_231 ;
V_231 = F_95 ( V_232 , V_233 , V_234 , & V_175 ) ;
if ( V_231 < 0 ) {
F_42 ( L_34 ) ;
return F_96 ( V_231 ) ;
}
F_97 ( V_175 -> V_176 , V_79 ) ;
V_175 -> V_176 -> V_236 = V_237 ;
V_231 = F_98 ( V_9 ) ;
if ( V_231 > 0 )
F_76 ( V_175 -> V_176 , 0 , V_231 ) ;
V_231 = V_175 -> V_225 -> V_226 ( V_175 , (struct V_227 * ) & V_228 ,
sizeof( struct V_227 ) ) ;
if ( V_231 < 0 ) {
F_42 ( L_38 ) ;
goto error;
}
V_231 = F_88 ( V_175 -> V_176 ,
(struct V_211 * ) & V_228 . V_222 ,
V_9 -> V_209 ) ;
if ( V_231 < 0 ) {
F_42 ( L_39 ) ;
goto error;
}
return V_175 ;
error:
F_99 ( V_175 -> V_176 ) ;
return F_96 ( V_231 ) ;
}
static int
F_101 ( struct V_218 * V_175 , const char * V_147 , const V_117 V_238 )
{
struct V_239 V_240 = { . V_241 = V_242 | V_243 } ;
struct V_244 V_245 ;
int V_84 ;
F_102 ( 7 ) ;
V_245 . V_246 = ( void * ) V_147 ;
V_245 . V_247 = V_238 ;
V_84 = F_103 ( V_175 , & V_240 , & V_245 , 1 , ( V_117 ) ( V_238 ) ) ;
F_104 ( 7 ) ;
return V_84 ;
}
static int
F_105 ( struct V_218 * V_175 , struct V_29 * V_240 )
{
int V_248 ;
int V_215 ;
V_248 = V_240 -> V_28 ;
V_240 -> V_28 = F_43 ( V_240 -> V_28 ) ;
V_215 = F_101 ( V_175 , ( char * ) V_240 , V_248 ) ;
if ( V_215 >= 0 || V_215 == - V_249 )
return V_215 ;
F_42 ( L_40 , V_215 ) ;
return 0 ;
}
static int
F_106 ( struct V_218 * V_175 , char * V_147 , const V_117 V_148 )
{
struct V_239 V_240 = { NULL ,} ;
struct V_244 V_245 ;
int V_84 ;
F_102 ( 7 ) ;
V_245 . V_246 = V_147 ;
V_245 . V_247 = ( V_117 ) V_148 ;
V_84 = F_107 ( V_175 , & V_240 , & V_245 , 1 , V_148 , V_242 ) ;
if ( V_84 < 0 )
return V_84 ;
F_104 ( 7 ) ;
return V_84 ;
}
static void F_108 ( struct V_250 * V_251 )
{
struct V_10 * V_11 =
F_109 ( V_251 , struct V_10 ,
V_39 . V_251 ) ;
struct V_8 * V_9 = V_11 -> V_9 ;
F_6 ( & V_9 -> V_13 ) ;
if ( V_11 -> V_18 &&
V_11 -> V_19 < V_41 ) {
V_11 -> V_19 = V_41 ;
F_22 ( V_11 -> V_42 ) ;
}
F_11 ( & V_9 -> V_13 ) ;
}
static inline struct V_7 *
F_110 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
struct V_7 * V_12 ;
V_12 = F_5 ( V_9 , V_11 ) ;
if ( V_12 )
return V_12 ;
return F_24 ( V_9 , V_11 , V_252 ) ;
}
static int F_111 ( void * V_160 )
{
struct V_253 * V_254 = V_160 ;
struct V_8 * V_9 = F_41 ( V_254 -> V_79 ) ;
struct V_10 * V_11 = & V_9 -> V_11 [ V_254 -> V_83 ] ;
struct V_175 * V_176 = V_254 -> V_175 -> V_176 ;
struct V_7 * V_12 ;
F_112 ( L_41
L_42 ,
V_9 -> V_202 , V_9 -> V_27 , V_254 -> V_83 ) ;
for (; ; ) {
V_12 = F_110 ( V_9 , V_11 ) ;
if ( F_31 ( F_113 () ) )
break;
if ( ! V_12 ) {
F_114 ( V_255 ) ;
continue;
}
while ( F_105 ( V_254 -> V_175 , V_12 -> V_21 ) < 0 ) {
int V_215 = 0 ;
F_115 ( * F_116 ( V_176 ) ,
F_117 ( V_176 ) ||
F_113 () ,
V_215 ) ;
if ( F_31 ( F_113 () ) )
goto V_256;
}
F_15 ( V_12 ) ;
}
V_256:
F_8 ( V_44 ) ;
if ( V_12 )
F_15 ( V_12 ) ;
while ( ( V_12 = F_5 ( V_9 , V_11 ) ) )
F_15 ( V_12 ) ;
F_8 ( V_44 ) ;
V_12 = F_24 ( V_9 , V_11 , 0 ) ;
if ( V_12 )
F_15 ( V_12 ) ;
F_99 ( V_254 -> V_175 -> V_176 ) ;
F_14 ( V_254 ) ;
return 0 ;
}
static int F_118 ( void * V_160 )
{
struct V_253 * V_254 = V_160 ;
struct V_8 * V_9 = F_41 ( V_254 -> V_79 ) ;
int V_84 ;
F_112 ( L_43
L_42 ,
V_9 -> V_209 , V_9 -> V_173 , V_254 -> V_83 ) ;
while ( ! F_113 () ) {
F_119 ( * F_116 ( V_254 -> V_175 -> V_176 ) ,
! F_120 ( & V_254 -> V_175 -> V_176 -> V_257 )
|| F_113 () ) ;
while ( ! F_120 ( & ( V_254 -> V_175 -> V_176 -> V_257 ) ) ) {
V_84 = F_106 ( V_254 -> V_175 , V_254 -> V_258 ,
V_9 -> V_210 ) ;
if ( V_84 <= 0 ) {
if ( V_84 != - V_249 )
F_42 ( L_44 ) ;
break;
}
F_121 () ;
F_75 ( V_254 -> V_79 , V_254 -> V_258 , V_84 ) ;
F_122 () ;
}
}
F_99 ( V_254 -> V_175 -> V_176 ) ;
F_14 ( V_254 -> V_258 ) ;
F_14 ( V_254 ) ;
return 0 ;
}
int F_123 ( struct V_79 * V_79 , int V_62 , char * V_259 , T_1 V_26 )
{
struct V_253 * V_254 ;
struct V_260 * * V_261 = NULL , * V_262 ;
struct V_218 * V_175 ;
struct V_8 * V_9 = F_41 ( V_79 ) ;
char * V_112 ;
int (* F_124)( void * V_160 );
int V_83 , V_263 ;
int V_231 = - V_134 ;
F_54 ( 7 , L_45 , V_264 , F_125 ( V_265 ) ) ;
F_54 ( 7 , L_46 ,
sizeof( struct F_40 ) ) ;
if ( ! V_9 -> V_37 ) {
V_263 = F_126 ( F_127 ( V_9 ) , 1 , V_266 ) ;
V_9 -> V_47 = V_263 - 1 ;
} else
V_263 = V_9 -> V_47 + 1 ;
if ( V_62 == V_38 ) {
if ( V_9 -> V_11 )
return - V_267 ;
F_128 ( V_9 -> V_202 , V_259 ,
sizeof( V_9 -> V_202 ) ) ;
V_9 -> V_27 = V_26 ;
V_112 = L_47 ;
F_124 = F_111 ;
} else if ( V_62 == V_208 ) {
if ( V_9 -> V_268 )
return - V_267 ;
F_128 ( V_9 -> V_209 , V_259 ,
sizeof( V_9 -> V_209 ) ) ;
V_9 -> V_173 = V_26 ;
V_112 = L_48 ;
F_124 = F_118 ;
} else {
return - V_157 ;
}
if ( V_62 == V_38 ) {
struct V_10 * V_11 ;
V_9 -> V_11 = F_129 ( V_263 * sizeof( V_9 -> V_11 [ 0 ] ) , V_269 ) ;
if ( ! V_9 -> V_11 )
goto V_165;
V_11 = V_9 -> V_11 ;
for ( V_83 = 0 ; V_83 < V_263 ; V_83 ++ , V_11 ++ ) {
F_130 ( & V_11 -> V_14 ) ;
V_11 -> V_18 = 0 ;
V_11 -> V_19 = 0 ;
F_131 ( & V_11 -> V_39 ,
F_108 ) ;
V_11 -> V_9 = V_9 ;
}
} else {
V_261 = F_129 ( V_263 * sizeof( struct V_260 * ) ,
V_269 ) ;
if ( ! V_261 )
goto V_165;
}
F_86 ( V_79 , V_62 ) ;
V_254 = NULL ;
for ( V_83 = 0 ; V_83 < V_263 ; V_83 ++ ) {
if ( V_62 == V_38 )
V_175 = F_92 ( V_79 , V_83 ) ;
else
V_175 = F_100 ( V_79 , V_83 ) ;
if ( F_132 ( V_175 ) ) {
V_231 = F_133 ( V_175 ) ;
goto V_270;
}
V_254 = F_13 ( sizeof( * V_254 ) , V_269 ) ;
if ( ! V_254 )
goto V_271;
V_254 -> V_79 = V_79 ;
V_254 -> V_175 = V_175 ;
if ( V_62 == V_208 ) {
V_254 -> V_258 = F_13 ( V_9 -> V_210 ,
V_269 ) ;
if ( ! V_254 -> V_258 )
goto V_270;
}
V_254 -> V_83 = V_83 ;
V_262 = F_134 ( F_124 , V_254 , V_112 , V_9 -> V_272 , V_83 ) ;
if ( F_132 ( V_262 ) ) {
V_231 = F_133 ( V_262 ) ;
goto V_270;
}
V_254 = NULL ;
if ( V_62 == V_38 )
V_9 -> V_11 [ V_83 ] . V_42 = V_262 ;
else
V_261 [ V_83 ] = V_262 ;
}
if ( V_62 == V_208 )
V_9 -> V_268 = V_261 ;
F_6 ( & V_9 -> V_43 ) ;
V_9 -> V_37 |= V_62 ;
F_11 ( & V_9 -> V_43 ) ;
F_135 () ;
return 0 ;
V_271:
F_99 ( V_175 -> V_176 ) ;
V_270:
if ( V_254 ) {
F_99 ( V_254 -> V_175 -> V_176 ) ;
F_14 ( V_254 -> V_258 ) ;
F_14 ( V_254 ) ;
}
V_263 = V_83 ;
while ( V_263 -- > 0 ) {
if ( V_62 == V_38 )
F_136 ( V_9 -> V_11 [ V_263 ] . V_42 ) ;
else
F_136 ( V_261 [ V_263 ] ) ;
}
F_14 ( V_261 ) ;
V_165:
if ( ! ( V_9 -> V_37 & V_38 ) ) {
F_14 ( V_9 -> V_11 ) ;
V_9 -> V_11 = NULL ;
}
return V_231 ;
}
int F_137 ( struct V_79 * V_79 , int V_62 )
{
struct V_8 * V_9 = F_41 ( V_79 ) ;
struct V_260 * * V_261 ;
int V_83 ;
int V_164 = - V_157 ;
F_54 ( 7 , L_45 , V_264 , F_125 ( V_265 ) ) ;
if ( V_62 == V_38 ) {
if ( ! V_9 -> V_11 )
return - V_273 ;
F_6 ( & V_9 -> V_43 ) ;
F_17 ( & V_9 -> V_13 ) ;
V_9 -> V_37 &= ~ V_38 ;
F_23 ( & V_9 -> V_13 ) ;
F_11 ( & V_9 -> V_43 ) ;
V_164 = 0 ;
for ( V_83 = V_9 -> V_47 ; V_83 >= 0 ; V_83 -- ) {
struct V_10 * V_11 = & V_9 -> V_11 [ V_83 ] ;
int V_215 ;
F_112 ( L_49 ,
F_125 ( V_11 -> V_42 ) ) ;
F_138 ( & V_11 -> V_39 ) ;
V_215 = F_136 ( V_11 -> V_42 ) ;
if ( V_164 >= 0 )
V_164 = V_215 ;
}
F_14 ( V_9 -> V_11 ) ;
V_9 -> V_11 = NULL ;
} else if ( V_62 == V_208 ) {
if ( ! V_9 -> V_268 )
return - V_273 ;
V_9 -> V_37 &= ~ V_208 ;
V_261 = V_9 -> V_268 ;
V_164 = 0 ;
for ( V_83 = V_9 -> V_47 ; V_83 >= 0 ; V_83 -- ) {
int V_215 ;
F_112 ( L_50 ,
F_125 ( V_261 [ V_83 ] ) ) ;
V_215 = F_136 ( V_261 [ V_83 ] ) ;
if ( V_164 >= 0 )
V_164 = V_215 ;
}
F_14 ( V_261 ) ;
V_9 -> V_268 = NULL ;
}
F_139 () ;
return V_164 ;
}
int T_6 F_140 ( struct V_79 * V_79 )
{
struct V_8 * V_9 = F_41 ( V_79 ) ;
F_141 ( & V_9 -> V_274 , L_51 , & V_275 ) ;
F_142 ( & V_9 -> V_13 ) ;
F_142 ( & V_9 -> V_43 ) ;
return 0 ;
}
void F_143 ( struct V_79 * V_79 )
{
int V_164 ;
struct V_8 * V_9 = F_41 ( V_79 ) ;
F_144 ( & V_9 -> V_274 ) ;
V_164 = F_137 ( V_79 , V_38 ) ;
if ( V_164 && V_164 != - V_273 )
F_42 ( L_52 ) ;
V_164 = F_137 ( V_79 , V_208 ) ;
if ( V_164 && V_164 != - V_273 )
F_42 ( L_53 ) ;
F_145 ( & V_9 -> V_274 ) ;
}
