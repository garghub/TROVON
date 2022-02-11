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
V_12 -> V_21 -> V_28 = F_15 ( sizeof( struct V_29 ) ) ;
V_12 -> V_21 -> V_30 = 0 ;
V_12 -> V_21 -> V_31 = 0 ;
V_12 -> V_32 = ( unsigned char * ) V_12 -> V_21 + sizeof( struct V_29 ) ;
V_12 -> V_33 = ( unsigned char * ) V_12 -> V_21 + V_9 -> V_22 ;
V_12 -> V_34 = V_35 ;
return V_12 ;
}
static inline void F_16 ( struct V_7 * V_12 )
{
F_14 ( V_12 -> V_21 ) ;
F_14 ( V_12 ) ;
}
static inline void F_17 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
struct V_7 * V_12 = V_11 -> V_36 ;
F_18 ( & V_9 -> V_13 ) ;
if ( V_9 -> V_37 & V_38 &&
V_11 -> V_18 < F_19 ( V_9 ) ) {
if ( ! V_11 -> V_18 )
F_20 ( & V_11 -> V_39 ,
F_21 ( V_40 , 1 ) ) ;
V_11 -> V_18 ++ ;
F_22 ( & V_12 -> V_17 , & V_11 -> V_14 ) ;
if ( ( ++ V_11 -> V_19 ) == V_41 )
F_23 ( V_11 -> V_42 ) ;
} else
F_16 ( V_12 ) ;
F_24 ( & V_9 -> V_13 ) ;
}
static inline struct V_7 *
F_25 ( struct V_8 * V_9 , struct V_10 * V_11 ,
unsigned long time )
{
struct V_7 * V_12 ;
F_6 ( & V_9 -> V_43 ) ;
V_12 = V_11 -> V_36 ;
if ( V_12 && F_26 ( V_35 - V_12 -> V_34 , time ) ) {
V_11 -> V_36 = NULL ;
F_8 ( V_44 ) ;
} else
V_12 = NULL ;
F_11 ( & V_9 -> V_43 ) ;
return V_12 ;
}
static inline int
F_27 ( struct V_8 * V_9 , struct V_45 * V_46 )
{
return ( ( long ) V_46 >> ( 1 + F_28 ( sizeof( * V_46 ) ) ) ) & V_9 -> V_47 ;
}
static inline struct V_7 *
F_29 ( struct V_8 * V_9 )
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
V_21 -> V_28 = F_15 ( sizeof( struct V_48 ) ) ;
V_12 -> V_32 = ( unsigned char * ) V_21 + sizeof( struct V_48 ) ;
V_12 -> V_33 = ( unsigned char * ) V_21 + V_9 -> V_22 ;
V_12 -> V_34 = V_35 ;
return V_12 ;
}
static inline bool F_30 ( struct V_45 * V_46 )
{
for ( V_46 = V_46 -> V_49 ; V_46 ; V_46 = V_46 -> V_49 ) {
if ( V_46 -> V_50 & V_51 )
return true ;
}
return false ;
}
static int F_31 ( struct V_8 * V_9 ,
struct V_45 * V_46 , int V_52 )
{
unsigned long V_53 = F_32 ( V_46 -> V_54 ) ;
unsigned long V_55 = V_35 ;
unsigned long V_56 = ( V_55 + V_46 -> V_57 ) & ~ 3UL ;
unsigned int V_58 ;
int V_59 ;
int V_60 ;
if ( F_33 ( V_46 -> V_50 & V_51 ) )
V_60 = 0 ;
else if ( F_33 ( F_34 ( V_9 ) && F_30 ( V_46 ) ) )
return 0 ;
else if ( F_35 ( V_46 -> V_61 == V_62 ) ) {
if ( ! ( ( 1 << V_46 -> V_63 ) &
( ( 1 << V_64 ) |
( 1 << V_65 ) |
( 1 << V_66 ) |
( 1 << V_67 ) |
( 1 << V_68 ) ) ) )
return 0 ;
V_60 = V_46 -> V_63 != V_46 -> V_69 ;
if ( V_60 && V_46 -> V_63 != V_64 )
goto V_70;
} else if ( F_33 ( V_46 -> V_61 == V_71 ) ) {
if ( ! ( ( 1 << V_46 -> V_63 ) &
( ( 1 << V_72 ) |
( 1 << V_73 ) |
( 1 << V_74 ) |
( 1 << V_75 ) |
( 1 << V_76 ) ) ) )
return 0 ;
V_60 = V_46 -> V_63 != V_46 -> V_69 ;
if ( V_60 && V_46 -> V_63 != V_72 )
goto V_70;
} else {
V_60 = 0 ;
}
V_58 = F_36 ( V_9 ) ;
if ( V_58 > 0 ) {
long V_77 = V_56 - V_53 ;
long V_78 = F_21 ( V_46 -> V_57 >> 1 , 10UL * V_79 ) ;
if ( abs ( V_77 ) < F_37 ( long , V_58 , V_78 ) ) {
int V_80 = V_53 & 3 ;
if ( V_80 >= F_38 ( V_9 ) )
return 0 ;
if ( F_39 ( V_55 , V_53 - V_46 -> V_57 +
( V_58 >> 3 ) ) )
return 0 ;
V_56 |= V_80 + 1 ;
}
}
V_59 = F_40 ( V_9 ) ;
if ( V_59 > 0 ) {
if ( ! ( V_46 -> V_50 & V_51 ) &&
V_52 % V_59 != F_41 ( V_9 ) )
return 0 ;
} else if ( V_58 <= 0 &&
V_52 != F_41 ( V_9 ) )
return 0 ;
V_70:
V_46 -> V_69 = V_46 -> V_63 ;
V_56 = F_42 ( & V_46 -> V_54 , V_53 , V_56 ) ;
return V_56 == V_53 || V_60 ;
}
static void F_43 ( struct V_81 * V_81 , struct V_45 * V_46 ,
int V_52 )
{
struct V_8 * V_9 = F_44 ( V_81 ) ;
struct V_48 * V_82 ;
struct F_43 * V_83 ;
struct V_7 * V_84 ;
struct V_10 * V_11 ;
int V_85 ;
int V_86 ;
if ( F_33 ( V_46 -> V_87 != V_88 ) )
return;
if ( V_46 -> V_50 & V_89 )
return;
if ( ! F_31 ( V_9 , V_46 , V_52 ) )
return;
F_6 ( & V_9 -> V_43 ) ;
if ( ! ( V_9 -> V_37 & V_38 ) ) {
F_11 ( & V_9 -> V_43 ) ;
return;
}
V_85 = F_27 ( V_9 , V_46 ) ;
V_11 = & V_9 -> V_11 [ V_85 ] ;
V_84 = V_11 -> V_36 ;
if ( V_84 ) {
V_82 = (struct V_48 * ) V_84 -> V_21 ;
if ( ! V_82 -> V_30 ) {
F_17 ( V_9 , V_11 ) ;
V_11 -> V_36 = NULL ;
V_84 = NULL ;
}
}
if ( ! V_84 ) {
V_84 = F_29 ( V_9 ) ;
if ( ! V_84 ) {
F_11 ( & V_9 -> V_43 ) ;
F_45 ( L_1 ) ;
return;
}
V_11 -> V_36 = V_84 ;
}
V_86 = ( V_46 -> V_50 & V_90 ) ? V_91 :
V_92 ;
V_82 = (struct V_48 * ) V_84 -> V_21 ;
V_83 = (struct F_43 * ) V_84 -> V_32 ;
V_83 -> V_23 = 0 ;
V_83 -> V_61 = V_46 -> V_61 ;
V_83 -> V_93 = V_46 -> V_93 ;
V_83 -> V_94 = V_46 -> V_94 ;
V_83 -> V_95 = V_46 -> V_95 ;
V_83 -> V_96 = V_46 -> V_96 . V_97 ;
V_83 -> V_98 = V_46 -> V_98 . V_97 ;
V_83 -> V_99 = V_46 -> V_99 . V_97 ;
V_83 -> V_50 = F_15 ( V_46 -> V_50 & ~ V_100 ) ;
V_83 -> V_63 = F_15 ( V_46 -> V_63 ) ;
if ( V_46 -> V_50 & V_90 ) {
struct V_101 * V_102 =
(struct V_101 * ) & V_83 [ 1 ] ;
memcpy ( V_102 , & V_46 -> V_103 , sizeof( * V_102 ) ) ;
}
V_82 -> V_30 ++ ;
V_82 -> V_28 = F_15 ( F_46 ( V_82 -> V_28 ) + V_86 ) ;
V_84 -> V_32 += V_86 ;
if ( V_84 -> V_32 + V_91 > V_84 -> V_33 ) {
F_17 ( V_9 , V_11 ) ;
V_11 -> V_36 = NULL ;
}
F_11 ( & V_9 -> V_43 ) ;
V_46 = V_46 -> V_49 ;
if ( V_46 ) {
if ( V_46 -> V_50 & V_51 )
V_52 = F_47 ( 1 , & V_46 -> V_104 ) ;
else
V_52 = F_41 ( V_9 ) ;
F_48 ( V_81 , V_46 -> V_49 , V_52 ) ;
}
}
void F_48 ( struct V_81 * V_81 , struct V_45 * V_46 , int V_52 )
{
struct V_8 * V_9 = F_44 ( V_81 ) ;
struct V_29 * V_82 ;
union F_48 * V_83 ;
struct V_7 * V_84 ;
struct V_10 * V_11 ;
int V_85 ;
T_1 * V_105 ;
unsigned int V_86 , V_106 , V_107 ;
if ( F_49 ( V_9 ) == 0 ) {
F_43 ( V_81 , V_46 , V_52 ) ;
return;
}
if ( V_46 -> V_50 & V_89 )
goto V_49;
V_108:
if ( ! F_31 ( V_9 , V_46 , V_52 ) )
goto V_49;
V_106 = 0 ;
if ( V_46 -> V_109 ) {
if ( ! V_46 -> V_110 || ! V_46 -> V_111 ) {
F_50 ( L_2 ) ;
return;
}
V_106 = F_51 ( V_46 -> V_112 -> V_113 , V_114 ) ;
}
F_6 ( & V_9 -> V_43 ) ;
if ( ! ( V_9 -> V_37 & V_38 ) ) {
F_11 ( & V_9 -> V_43 ) ;
return;
}
V_85 = F_27 ( V_9 , V_46 ) ;
V_11 = & V_9 -> V_11 [ V_85 ] ;
#ifdef F_52
if ( V_46 -> V_87 == V_115 )
V_86 = sizeof( struct V_116 ) ;
else
#endif
V_86 = sizeof( struct V_117 ) ;
if ( V_46 -> V_50 & V_90 )
V_86 += sizeof( struct V_101 ) + 2 ;
if ( V_46 -> V_109 )
V_86 += V_46 -> V_109 + 2 ;
if ( V_106 )
V_86 += V_106 + 2 ;
V_107 = 0 ;
V_84 = V_11 -> V_36 ;
if ( V_84 ) {
V_82 = V_84 -> V_21 ;
V_107 = ( 4 - ( V_118 ) V_84 -> V_32 ) & 3 ;
if ( V_84 -> V_32 + V_86 + V_107 > V_84 -> V_33 || V_82 -> V_23 ) {
F_17 ( V_9 , V_11 ) ;
V_11 -> V_36 = NULL ;
V_84 = NULL ;
V_107 = 0 ;
}
}
if ( ! V_84 ) {
V_84 = F_12 ( V_9 ) ;
if ( ! V_84 ) {
F_11 ( & V_9 -> V_43 ) ;
F_45 ( L_1 ) ;
return;
}
V_11 -> V_36 = V_84 ;
V_82 = V_84 -> V_21 ;
}
V_105 = V_84 -> V_32 ;
V_84 -> V_32 += V_107 + V_86 ;
V_82 -> V_28 = F_15 ( F_46 ( V_82 -> V_28 ) + V_107 + V_86 ) ;
while ( V_107 -- )
* ( V_105 ++ ) = 0 ;
V_83 = (union F_48 * ) V_105 ;
V_83 -> V_119 . type = ( V_46 -> V_87 == V_115 ? V_120 : 0 ) ;
V_83 -> V_119 . V_121 = F_15 ( V_86 & V_122 ) ;
V_83 -> V_119 . V_50 = F_53 ( V_46 -> V_50 & ~ V_100 ) ;
V_83 -> V_119 . V_63 = F_15 ( V_46 -> V_63 ) ;
V_83 -> V_119 . V_61 = V_46 -> V_61 ;
V_83 -> V_119 . V_93 = V_46 -> V_93 ;
V_83 -> V_119 . V_94 = V_46 -> V_94 ;
V_83 -> V_119 . V_95 = V_46 -> V_95 ;
V_83 -> V_119 . V_123 = F_53 ( V_46 -> V_123 ) ;
V_83 -> V_119 . V_57 = F_53 ( V_46 -> V_57 / V_79 ) ;
V_82 -> V_30 ++ ;
#ifdef F_52
if ( V_46 -> V_87 == V_115 ) {
V_105 += sizeof( struct V_116 ) ;
V_83 -> V_124 . V_96 = V_46 -> V_96 . V_125 ;
V_83 -> V_124 . V_98 = V_46 -> V_98 . V_125 ;
V_83 -> V_124 . V_99 = V_46 -> V_99 . V_125 ;
} else
#endif
{
V_105 += sizeof( struct V_117 ) ;
V_83 -> V_119 . V_96 = V_46 -> V_96 . V_97 ;
V_83 -> V_119 . V_98 = V_46 -> V_98 . V_97 ;
V_83 -> V_119 . V_99 = V_46 -> V_99 . V_97 ;
}
if ( V_46 -> V_50 & V_90 ) {
* ( V_105 ++ ) = V_126 ;
* ( V_105 ++ ) = sizeof( struct V_101 ) ;
F_3 ( (struct V_1 * ) V_105 , & V_46 -> V_103 ) ;
V_105 += sizeof( struct V_1 ) ;
F_3 ( (struct V_1 * ) V_105 , & V_46 -> V_127 ) ;
V_105 += sizeof( struct V_1 ) ;
}
if ( V_46 -> V_109 && V_46 -> V_110 ) {
* ( V_105 ++ ) = V_128 ;
* ( V_105 ++ ) = V_46 -> V_109 ;
memcpy ( V_105 , V_46 -> V_110 , V_46 -> V_109 ) ;
V_105 += V_46 -> V_109 ;
if ( V_106 ) {
* ( V_105 ++ ) = V_129 ;
* ( V_105 ++ ) = V_106 ;
memcpy ( V_105 , V_46 -> V_112 -> V_113 , V_106 ) ;
V_105 += V_106 ;
}
}
F_11 ( & V_9 -> V_43 ) ;
V_49:
V_46 = V_46 -> V_49 ;
if ( ! V_46 )
return;
if ( V_46 -> V_50 & V_51 )
V_52 = F_47 ( 1 , & V_46 -> V_104 ) ;
else
V_52 = F_41 ( V_9 ) ;
goto V_108;
}
static inline int
F_54 ( struct V_81 * V_81 , int V_87 , union F_48 * V_130 ,
struct V_131 * V_105 ,
T_1 * V_110 , unsigned int V_109 ,
T_1 * V_132 , unsigned int V_106 )
{
#ifdef F_52
if ( V_87 == V_115 )
F_55 ( V_81 , V_87 , V_130 -> V_124 . V_61 ,
( const union V_133 * ) & V_130 -> V_124 . V_96 ,
V_130 -> V_124 . V_93 ,
( const union V_133 * ) & V_130 -> V_124 . V_98 ,
V_130 -> V_124 . V_94 , V_105 ) ;
else
#endif
F_55 ( V_81 , V_87 , V_130 -> V_119 . V_61 ,
( const union V_133 * ) & V_130 -> V_119 . V_96 ,
V_130 -> V_119 . V_93 ,
( const union V_133 * ) & V_130 -> V_119 . V_98 ,
V_130 -> V_119 . V_94 , V_105 ) ;
if ( V_109 ) {
if ( V_106 ) {
char V_84 [ V_114 + 1 ] ;
memcpy ( V_84 , V_132 , V_106 ) ;
V_84 [ V_106 ] = 0 ;
V_105 -> V_112 = F_56 ( V_84 ) ;
if ( ! V_105 -> V_112 ) {
F_57 ( 3 , L_3 ,
V_84 ) ;
return 1 ;
}
} else {
F_50 ( L_4 ) ;
return 1 ;
}
V_105 -> V_110 = F_58 ( V_110 , V_109 , V_20 ) ;
if ( ! V_105 -> V_110 ) {
F_59 ( V_105 -> V_112 -> V_134 ) ;
return - V_135 ;
}
V_105 -> V_109 = V_109 ;
}
return 0 ;
}
static void F_60 ( struct V_81 * V_81 , struct V_131 * V_136 ,
unsigned int V_50 , unsigned int V_63 ,
unsigned int V_61 , unsigned int type ,
const union V_133 * V_99 , T_2 V_95 ,
unsigned long V_57 , T_3 V_123 ,
struct V_101 * V_102 )
{
struct V_137 * V_111 ;
struct V_45 * V_46 ;
struct V_8 * V_9 = F_44 ( V_81 ) ;
if ( ! ( V_50 & V_51 ) ) {
V_46 = F_61 ( V_136 ) ;
if ( V_46 && ( ( V_46 -> V_95 != V_95 ) ||
! F_62 ( V_46 -> V_138 , & V_46 -> V_99 , V_99 ) ) ) {
if ( ! ( V_50 & V_139 ) ) {
F_63 ( V_46 ) ;
F_64 ( V_46 ) ;
V_46 = NULL ;
} else {
F_64 ( V_46 ) ;
F_14 ( V_136 -> V_110 ) ;
return;
}
}
} else {
V_46 = F_65 ( V_136 ) ;
}
if ( V_46 ) {
F_14 ( V_136 -> V_110 ) ;
V_111 = V_46 -> V_111 ;
F_6 ( & V_46 -> V_140 ) ;
if ( ( V_46 -> V_50 ^ V_50 ) & V_139 &&
! ( V_50 & V_51 ) && V_111 ) {
if ( V_50 & V_139 ) {
F_66 ( & V_111 -> V_141 ) ;
F_67 ( & V_111 -> V_142 ) ;
} else {
F_67 ( & V_111 -> V_141 ) ;
F_66 ( & V_111 -> V_142 ) ;
}
}
V_50 &= V_143 ;
V_50 |= V_46 -> V_50 & ~ V_143 ;
V_46 -> V_50 = V_50 ;
F_11 ( & V_46 -> V_140 ) ;
if ( ! V_111 )
F_68 ( V_46 ) ;
} else {
F_69 () ;
V_111 = F_70 ( V_81 , type , type , V_99 , V_95 ,
V_136 -> V_98 , V_136 -> V_94 , V_61 ,
V_123 , V_50 ) ;
V_46 = F_71 ( V_136 , type , V_99 , V_95 , V_50 , V_111 ,
V_123 ) ;
F_72 () ;
if ( ! V_46 ) {
F_14 ( V_136 -> V_110 ) ;
F_57 ( 2 , L_5 ) ;
return;
}
if ( ! ( V_50 & V_51 ) )
F_14 ( V_136 -> V_110 ) ;
}
if ( V_102 )
memcpy ( & V_46 -> V_103 , V_102 , sizeof( * V_102 ) ) ;
F_73 ( & V_46 -> V_104 , F_41 ( V_9 ) ) ;
V_46 -> V_63 = V_63 ;
V_46 -> V_69 = V_46 -> V_63 ;
if ( V_57 ) {
if ( V_57 > V_144 / V_79 )
V_57 = V_144 / V_79 ;
V_46 -> V_57 = V_57 * V_79 ;
} else {
struct V_145 * V_146 ;
V_146 = F_74 ( V_81 , V_61 ) ;
if ( ! ( V_50 & V_51 ) && V_146 && V_146 -> V_147 )
V_46 -> V_57 = V_146 -> V_147 [ V_63 ] ;
else
V_46 -> V_57 = ( 3 * 60 * V_79 ) ;
}
F_75 ( V_46 ) ;
}
static void F_76 ( struct V_81 * V_81 , const char * V_148 ,
const V_118 V_149 )
{
struct V_48 * V_82 = (struct V_48 * ) V_148 ;
struct F_43 * V_83 ;
struct V_101 * V_102 ;
struct V_150 * V_151 ;
struct V_131 V_136 ;
char * V_105 ;
int V_152 ;
V_105 = ( char * ) V_148 + sizeof( struct V_48 ) ;
for ( V_152 = 0 ; V_152 < V_82 -> V_30 ; V_152 ++ ) {
unsigned int V_50 , V_63 ;
if ( V_105 + V_92 > V_148 + V_149 ) {
F_50 ( L_6 ) ;
return;
}
V_83 = (struct F_43 * ) V_105 ;
V_50 = F_46 ( V_83 -> V_50 ) | V_153 ;
V_50 &= ~ V_100 ;
if ( V_50 & V_90 ) {
V_102 = (struct V_101 * ) & V_83 [ 1 ] ;
V_105 += V_91 ;
if ( V_105 > V_148 + V_149 ) {
F_50 ( L_7 ) ;
return;
}
} else {
V_102 = NULL ;
V_105 += V_92 ;
}
V_63 = F_46 ( V_83 -> V_63 ) ;
if ( ! ( V_50 & V_51 ) ) {
V_151 = F_77 ( V_83 -> V_61 ) ;
if ( ! V_151 ) {
F_57 ( 2 , L_8 ,
V_83 -> V_61 ) ;
continue;
}
if ( V_63 >= V_151 -> V_154 ) {
F_57 ( 2 , L_9 ,
V_151 -> V_113 , V_63 ) ;
continue;
}
} else {
if ( V_63 > 0 ) {
F_57 ( 2 , L_10 ,
V_63 ) ;
V_63 = 0 ;
}
}
F_55 ( V_81 , V_88 , V_83 -> V_61 ,
( const union V_133 * ) & V_83 -> V_96 ,
V_83 -> V_93 ,
( const union V_133 * ) & V_83 -> V_98 ,
V_83 -> V_94 , & V_136 ) ;
F_60 ( V_81 , & V_136 , V_50 , V_63 , V_83 -> V_61 , V_88 ,
(union V_133 * ) & V_83 -> V_99 , V_83 -> V_95 ,
0 , 0 , V_102 ) ;
}
}
static inline int F_78 ( T_1 * V_105 , unsigned int V_155 ,
T_3 * V_156 ,
struct V_101 * V_102 )
{
struct V_101 * V_157 ;
V_157 = (struct V_101 * ) V_105 ;
if ( V_155 != sizeof( struct V_101 ) ) {
F_57 ( 2 , L_11 ) ;
return - V_158 ;
}
if ( * V_156 & V_159 ) {
F_57 ( 2 , L_12 ) ;
return - V_158 ;
}
F_1 ( & V_157 -> V_103 , & V_102 -> V_103 ) ;
F_1 ( & V_157 -> V_127 , & V_102 -> V_127 ) ;
* V_156 |= V_159 ;
return 0 ;
}
static int F_79 ( T_1 * V_105 , unsigned int V_155 , unsigned int * V_160 ,
T_1 * * V_161 , unsigned int V_162 ,
T_3 * V_156 , T_3 V_163 )
{
if ( V_155 > V_162 ) {
F_57 ( 2 , L_13 , V_162 ) ;
return - V_158 ;
}
if ( * V_156 & V_163 ) {
F_57 ( 2 , L_14 , V_163 ) ;
return - V_158 ;
}
* V_160 = V_155 ;
* V_161 = V_105 ;
* V_156 |= V_163 ;
return 0 ;
}
static inline int F_80 ( struct V_81 * V_81 , T_1 * V_105 , T_1 * V_164 )
{
struct V_101 V_102 ;
union F_48 * V_83 ;
struct V_150 * V_151 ;
struct V_131 V_136 ;
T_3 V_50 ;
unsigned int V_87 , V_63 , V_109 = 0 , V_106 = 0 ;
T_1 * V_110 = NULL , * V_132 = NULL ;
T_3 V_156 = 0 ;
int V_165 = 0 ;
V_83 = (union F_48 * ) V_105 ;
if ( V_83 -> V_124 . type & V_120 ) {
#ifdef F_52
V_87 = V_115 ;
V_105 += sizeof( struct V_116 ) ;
#else
F_57 ( 3 , L_15 ) ;
V_165 = 10 ;
goto V_166;
#endif
} else if ( ! V_83 -> V_119 . type ) {
V_87 = V_88 ;
V_105 += sizeof( struct V_117 ) ;
} else {
return - 10 ;
}
if ( V_105 > V_164 )
return - 20 ;
while ( V_105 < V_164 ) {
int V_167 ;
int V_155 ;
if ( V_105 + 2 > V_164 )
return - 30 ;
V_167 = * ( V_105 ++ ) ;
V_155 = * ( V_105 ++ ) ;
if ( ! V_155 || ( ( V_105 + V_155 ) > V_164 ) )
return - 40 ;
switch ( V_167 & ~ V_168 ) {
case V_126 :
if ( F_78 ( V_105 , V_155 , & V_156 , & V_102 ) )
return - 50 ;
break;
case V_128 :
if ( F_79 ( V_105 , V_155 , & V_109 , & V_110 ,
V_169 , & V_156 ,
V_170 ) )
return - 60 ;
break;
case V_129 :
if ( F_79 ( V_105 , V_155 , & V_106 , & V_132 ,
V_114 , & V_156 ,
V_171 ) )
return - 70 ;
break;
default:
if ( ! ( V_167 & V_168 ) ) {
F_57 ( 3 , L_16 ,
V_167 & ~ V_168 ) ;
V_165 = 20 ;
goto V_166;
}
}
V_105 += V_155 ;
}
V_50 = F_81 ( V_83 -> V_119 . V_50 ) & V_172 ;
V_50 |= V_153 ;
V_63 = F_46 ( V_83 -> V_119 . V_63 ) ;
if ( ! ( V_50 & V_51 ) ) {
V_151 = F_77 ( V_83 -> V_119 . V_61 ) ;
if ( ! V_151 ) {
F_57 ( 3 , L_17 ,
V_83 -> V_119 . V_61 ) ;
V_165 = 30 ;
goto V_166;
}
if ( V_63 >= V_151 -> V_154 ) {
F_57 ( 3 , L_18 ,
V_151 -> V_113 , V_63 ) ;
V_165 = 40 ;
goto V_166;
}
} else {
if ( V_63 > 0 ) {
F_57 ( 3 , L_19 ,
V_63 ) ;
V_63 = 0 ;
}
}
if ( F_54 ( V_81 , V_87 , V_83 , & V_136 , V_110 ,
V_109 , V_132 , V_106 ) ) {
V_165 = 50 ;
goto V_166;
}
if ( V_87 == V_88 )
F_60 ( V_81 , & V_136 , V_50 , V_63 , V_83 -> V_119 . V_61 , V_87 ,
(union V_133 * ) & V_83 -> V_119 . V_99 , V_83 -> V_119 . V_95 ,
F_81 ( V_83 -> V_119 . V_57 ) , F_81 ( V_83 -> V_119 . V_123 ) ,
( V_156 & V_159 ? & V_102 : NULL )
) ;
#ifdef F_52
else
F_60 ( V_81 , & V_136 , V_50 , V_63 , V_83 -> V_124 . V_61 , V_87 ,
(union V_133 * ) & V_83 -> V_124 . V_99 , V_83 -> V_124 . V_95 ,
F_81 ( V_83 -> V_124 . V_57 ) , F_81 ( V_83 -> V_124 . V_123 ) ,
( V_156 & V_159 ? & V_102 : NULL )
) ;
#endif
F_82 ( V_136 . V_112 ) ;
return 0 ;
V_166:
F_57 ( 2 , L_20 , V_165 ) ;
return V_165 ;
}
static void F_83 ( struct V_81 * V_81 , T_1 * V_148 ,
const V_118 V_149 )
{
struct V_8 * V_9 = F_44 ( V_81 ) ;
struct V_29 * V_173 = (struct V_29 * ) V_148 ;
T_1 * V_105 , * V_164 ;
int V_152 , V_30 ;
if ( V_149 < sizeof( struct V_48 ) ) {
F_57 ( 2 , L_21 ) ;
return;
}
if ( V_149 != F_46 ( V_173 -> V_28 ) ) {
F_57 ( 2 , L_22 ) ;
return;
}
if ( V_9 -> V_174 != 0 && V_173 -> V_26 != V_9 -> V_174 ) {
F_57 ( 7 , L_23 , V_173 -> V_26 ) ;
return;
}
if ( ( V_173 -> V_24 == V_25 ) && ( V_173 -> V_23 == 0 )
&& ( V_173 -> V_31 == 0 ) ) {
V_164 = V_148 + sizeof( struct V_29 ) ;
V_30 = V_173 -> V_30 ;
for ( V_152 = 0 ; V_152 < V_30 ; V_152 ++ ) {
union F_48 * V_83 ;
unsigned int V_28 ;
int V_165 ;
V_105 = V_164 ;
if ( V_105 + sizeof( V_83 -> V_119 ) > V_148 + V_149 ) {
F_50 ( L_24 ) ;
return;
}
V_83 = (union F_48 * ) V_105 ;
V_28 = F_46 ( V_83 -> V_119 . V_121 ) & V_122 ;
V_164 = V_105 + V_28 ;
if ( V_164 > V_148 + V_149 ) {
F_50 ( L_25 ) ;
return;
}
if ( F_46 ( V_83 -> V_119 . V_121 ) >> V_175 ) {
F_50 ( L_26 ,
F_46 ( V_83 -> V_119 . V_121 ) >> V_175 ) ;
return;
}
V_165 = F_80 ( V_81 , V_105 , V_164 ) ;
if ( V_165 < 0 ) {
F_50 ( L_27 ,
V_165 ) ;
return;
}
V_164 = V_105 + ( ( V_28 + 3 ) & ~ 3 ) ;
}
} else {
F_76 ( V_81 , V_148 , V_149 ) ;
return;
}
}
static void F_84 ( struct V_176 * V_177 , int V_178 , int V_179 )
{
F_85 ( V_177 ) ;
if ( V_178 ) {
V_179 = F_86 ( int , V_179 , ( V_180 + 1 ) / 2 ,
V_181 ) ;
V_177 -> V_182 = V_179 * 2 ;
V_177 -> V_183 |= V_184 ;
} else {
V_179 = F_86 ( int , V_179 , ( V_185 + 1 ) / 2 ,
V_186 ) ;
V_177 -> V_187 = V_179 * 2 ;
V_177 -> V_183 |= V_188 ;
}
F_87 ( V_177 ) ;
}
static void F_88 ( struct V_176 * V_177 , T_4 V_189 )
{
struct V_190 * V_191 = F_89 ( V_177 ) ;
F_85 ( V_177 ) ;
V_191 -> V_192 = V_189 ? 1 : 0 ;
F_87 ( V_177 ) ;
}
static void F_90 ( struct V_176 * V_177 , T_4 V_193 )
{
struct V_190 * V_191 = F_89 ( V_177 ) ;
F_85 ( V_177 ) ;
V_191 -> V_194 = V_193 ;
F_87 ( V_177 ) ;
}
static int F_91 ( struct V_176 * V_177 , char * V_195 )
{
struct V_196 * V_197 ;
struct V_190 * V_191 = F_89 ( V_177 ) ;
struct V_81 * V_81 = F_92 ( V_177 ) ;
V_197 = F_93 ( V_81 , V_195 ) ;
if ( ! V_197 )
return - V_198 ;
if ( V_177 -> V_199 && V_197 -> V_200 != V_177 -> V_199 )
return - V_158 ;
F_85 ( V_177 ) ;
V_191 -> V_201 = V_197 -> V_200 ;
F_87 ( V_177 ) ;
return 0 ;
}
static int F_94 ( struct V_81 * V_81 , int V_37 )
{
struct V_8 * V_9 = F_44 ( V_81 ) ;
struct V_196 * V_197 ;
int V_202 ;
if ( V_37 == V_38 ) {
V_197 = F_93 ( V_81 , V_9 -> V_203 ) ;
if ( ! V_197 )
return - V_198 ;
V_202 = ( V_197 -> V_204 - sizeof( struct V_205 ) -
sizeof( struct V_206 ) -
V_207 - 20 ) / V_92 ;
V_9 -> V_22 = V_207 +
V_92 * F_95 ( V_202 , V_208 ) ;
F_57 ( 7 , L_28
L_29 , V_9 -> V_22 ) ;
} else if ( V_37 == V_209 ) {
V_197 = F_93 ( V_81 , V_9 -> V_210 ) ;
if ( ! V_197 )
return - V_198 ;
V_9 -> V_211 = V_197 -> V_204 -
sizeof( struct V_205 ) - sizeof( struct V_206 ) ;
F_57 ( 7 , L_30
L_29 , V_9 -> V_211 ) ;
}
return 0 ;
}
static int
F_96 ( struct V_176 * V_177 , struct V_212 * V_213 , char * V_195 )
{
struct V_81 * V_81 = F_92 ( V_177 ) ;
struct V_214 V_215 ;
struct V_196 * V_197 ;
int V_216 ;
memset ( & V_215 , 0 , sizeof( V_215 ) ) ;
memcpy ( & V_215 . V_217 , V_213 , sizeof( struct V_212 ) ) ;
V_197 = F_93 ( V_81 , V_195 ) ;
if ( ! V_197 )
return - V_198 ;
if ( V_177 -> V_199 && V_197 -> V_200 != V_177 -> V_199 )
return - V_158 ;
V_215 . V_218 = V_197 -> V_200 ;
F_97 () ;
F_85 ( V_177 ) ;
V_216 = F_98 ( V_177 , & V_215 ) ;
F_87 ( V_177 ) ;
F_99 () ;
return V_216 ;
}
static int F_100 ( struct V_219 * V_176 , char * V_195 )
{
struct V_81 * V_81 = F_92 ( V_176 -> V_177 ) ;
struct V_196 * V_197 ;
T_5 V_213 ;
struct V_220 sin ;
V_197 = F_93 ( V_81 , V_195 ) ;
if ( ! V_197 )
return - V_198 ;
V_213 = F_101 ( V_197 , 0 , V_221 ) ;
if ( ! V_213 )
F_45 ( L_31
L_32 ) ;
F_57 ( 7 , L_33 ,
V_195 , & V_213 ) ;
sin . V_222 = V_88 ;
sin . V_223 . V_224 = V_213 ;
sin . V_225 = 0 ;
return V_176 -> V_226 -> V_227 ( V_176 , (struct V_228 * ) & sin , sizeof( sin ) ) ;
}
static struct V_219 * F_102 ( struct V_81 * V_81 , int V_85 )
{
struct V_8 * V_9 = F_44 ( V_81 ) ;
struct V_220 V_229 = {
. V_222 = V_88 ,
. V_225 = F_103 ( V_230 + V_85 ) ,
. V_223 . V_224 = F_104 ( V_231 ) ,
} ;
struct V_219 * V_176 ;
int V_232 ;
V_232 = F_105 ( V_233 , V_234 , V_235 , & V_176 ) ;
if ( V_232 < 0 ) {
F_45 ( L_34 ) ;
return F_106 ( V_232 ) ;
}
F_107 ( V_176 -> V_177 , V_81 ) ;
V_232 = F_91 ( V_176 -> V_177 , V_9 -> V_203 ) ;
if ( V_232 < 0 ) {
F_45 ( L_35 ) ;
goto error;
}
F_88 ( V_176 -> V_177 , 0 ) ;
F_90 ( V_176 -> V_177 , 1 ) ;
V_232 = F_108 ( V_9 ) ;
if ( V_232 > 0 )
F_84 ( V_176 -> V_177 , 1 , V_232 ) ;
V_232 = F_100 ( V_176 , V_9 -> V_203 ) ;
if ( V_232 < 0 ) {
F_45 ( L_36 ) ;
goto error;
}
V_232 = V_176 -> V_226 -> V_236 ( V_176 , (struct V_228 * ) & V_229 ,
sizeof( struct V_228 ) , 0 ) ;
if ( V_232 < 0 ) {
F_45 ( L_37 ) ;
goto error;
}
return V_176 ;
error:
F_109 ( V_176 -> V_177 ) ;
return F_106 ( V_232 ) ;
}
static struct V_219 * F_110 ( struct V_81 * V_81 , int V_85 )
{
struct V_8 * V_9 = F_44 ( V_81 ) ;
struct V_220 V_229 = {
. V_222 = V_88 ,
. V_225 = F_103 ( V_230 + V_85 ) ,
. V_223 . V_224 = F_104 ( V_231 ) ,
} ;
struct V_219 * V_176 ;
int V_232 ;
V_232 = F_105 ( V_233 , V_234 , V_235 , & V_176 ) ;
if ( V_232 < 0 ) {
F_45 ( L_34 ) ;
return F_106 ( V_232 ) ;
}
F_107 ( V_176 -> V_177 , V_81 ) ;
V_176 -> V_177 -> V_237 = V_238 ;
V_232 = F_108 ( V_9 ) ;
if ( V_232 > 0 )
F_84 ( V_176 -> V_177 , 0 , V_232 ) ;
V_232 = V_176 -> V_226 -> V_227 ( V_176 , (struct V_228 * ) & V_229 ,
sizeof( struct V_228 ) ) ;
if ( V_232 < 0 ) {
F_45 ( L_38 ) ;
goto error;
}
V_232 = F_96 ( V_176 -> V_177 ,
(struct V_212 * ) & V_229 . V_223 ,
V_9 -> V_210 ) ;
if ( V_232 < 0 ) {
F_45 ( L_39 ) ;
goto error;
}
return V_176 ;
error:
F_109 ( V_176 -> V_177 ) ;
return F_106 ( V_232 ) ;
}
static int
F_111 ( struct V_219 * V_176 , const char * V_148 , const V_118 V_239 )
{
struct V_240 V_241 = { . V_242 = V_243 | V_244 } ;
struct V_245 V_246 ;
int V_86 ;
F_112 ( 7 ) ;
V_246 . V_247 = ( void * ) V_148 ;
V_246 . V_248 = V_239 ;
V_86 = F_113 ( V_176 , & V_241 , & V_246 , 1 , ( V_118 ) ( V_239 ) ) ;
F_114 ( 7 ) ;
return V_86 ;
}
static int
F_115 ( struct V_219 * V_176 , struct V_29 * V_241 )
{
int V_249 ;
int V_216 ;
V_249 = F_46 ( V_241 -> V_28 ) ;
V_216 = F_111 ( V_176 , ( char * ) V_241 , V_249 ) ;
if ( V_216 >= 0 || V_216 == - V_250 )
return V_216 ;
F_45 ( L_40 , V_216 ) ;
return 0 ;
}
static int
F_116 ( struct V_219 * V_176 , char * V_148 , const V_118 V_149 )
{
struct V_240 V_241 = { NULL ,} ;
struct V_245 V_246 ;
int V_86 ;
F_112 ( 7 ) ;
V_246 . V_247 = V_148 ;
V_246 . V_248 = ( V_118 ) V_149 ;
V_86 = F_117 ( V_176 , & V_241 , & V_246 , 1 , V_149 , V_243 ) ;
if ( V_86 < 0 )
return V_86 ;
F_114 ( 7 ) ;
return V_86 ;
}
static void F_118 ( struct V_251 * V_252 )
{
struct V_10 * V_11 =
F_119 ( V_252 , struct V_10 ,
V_39 . V_252 ) ;
struct V_8 * V_9 = V_11 -> V_9 ;
F_6 ( & V_9 -> V_13 ) ;
if ( V_11 -> V_18 &&
V_11 -> V_19 < V_41 ) {
V_11 -> V_19 = V_41 ;
F_23 ( V_11 -> V_42 ) ;
}
F_11 ( & V_9 -> V_13 ) ;
}
static inline struct V_7 *
F_120 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
struct V_7 * V_12 ;
V_12 = F_5 ( V_9 , V_11 ) ;
if ( V_12 )
return V_12 ;
return F_25 ( V_9 , V_11 , V_253 ) ;
}
static int F_121 ( void * V_161 )
{
struct V_254 * V_255 = V_161 ;
struct V_8 * V_9 = F_44 ( V_255 -> V_81 ) ;
struct V_10 * V_11 = & V_9 -> V_11 [ V_255 -> V_85 ] ;
struct V_176 * V_177 = V_255 -> V_176 -> V_177 ;
struct V_7 * V_12 ;
F_122 ( L_41
L_42 ,
V_9 -> V_203 , V_9 -> V_27 , V_255 -> V_85 ) ;
for (; ; ) {
V_12 = F_120 ( V_9 , V_11 ) ;
if ( F_33 ( F_123 () ) )
break;
if ( ! V_12 ) {
F_124 ( V_256 ) ;
continue;
}
while ( F_115 ( V_255 -> V_176 , V_12 -> V_21 ) < 0 ) {
F_125 ( * F_126 ( V_177 ) ,
F_127 ( V_177 ) ||
F_123 () ) ;
if ( F_33 ( F_123 () ) )
goto V_257;
}
F_16 ( V_12 ) ;
}
V_257:
F_8 ( V_44 ) ;
if ( V_12 )
F_16 ( V_12 ) ;
while ( ( V_12 = F_5 ( V_9 , V_11 ) ) )
F_16 ( V_12 ) ;
F_8 ( V_44 ) ;
V_12 = F_25 ( V_9 , V_11 , 0 ) ;
if ( V_12 )
F_16 ( V_12 ) ;
F_109 ( V_255 -> V_176 -> V_177 ) ;
F_14 ( V_255 ) ;
return 0 ;
}
static int F_128 ( void * V_161 )
{
struct V_254 * V_255 = V_161 ;
struct V_8 * V_9 = F_44 ( V_255 -> V_81 ) ;
int V_86 ;
F_122 ( L_43
L_42 ,
V_9 -> V_210 , V_9 -> V_174 , V_255 -> V_85 ) ;
while ( ! F_123 () ) {
F_129 ( * F_126 ( V_255 -> V_176 -> V_177 ) ,
! F_130 ( & V_255 -> V_176 -> V_177 -> V_258 )
|| F_123 () ) ;
while ( ! F_130 ( & ( V_255 -> V_176 -> V_177 -> V_258 ) ) ) {
V_86 = F_116 ( V_255 -> V_176 , V_255 -> V_259 ,
V_9 -> V_211 ) ;
if ( V_86 <= 0 ) {
if ( V_86 != - V_250 )
F_45 ( L_44 ) ;
break;
}
F_83 ( V_255 -> V_81 , V_255 -> V_259 , V_86 ) ;
}
}
F_109 ( V_255 -> V_176 -> V_177 ) ;
F_14 ( V_255 -> V_259 ) ;
F_14 ( V_255 ) ;
return 0 ;
}
int F_131 ( struct V_81 * V_81 , int V_63 , char * V_260 , T_1 V_26 )
{
struct V_254 * V_255 ;
struct V_261 * * V_262 = NULL , * V_263 ;
struct V_219 * V_176 ;
struct V_8 * V_9 = F_44 ( V_81 ) ;
char * V_113 ;
int (* F_132)( void * V_161 );
int V_85 , V_264 ;
int V_232 = - V_135 ;
F_57 ( 7 , L_45 , V_265 , F_133 ( V_266 ) ) ;
F_57 ( 7 , L_46 ,
sizeof( struct F_43 ) ) ;
if ( ! V_9 -> V_37 ) {
V_264 = F_134 ( F_135 ( V_9 ) , 1 , V_267 ) ;
V_9 -> V_47 = V_264 - 1 ;
} else
V_264 = V_9 -> V_47 + 1 ;
if ( V_63 == V_38 ) {
if ( V_9 -> V_11 )
return - V_268 ;
F_136 ( V_9 -> V_203 , V_260 ,
sizeof( V_9 -> V_203 ) ) ;
V_9 -> V_27 = V_26 ;
V_113 = L_47 ;
F_132 = F_121 ;
} else if ( V_63 == V_209 ) {
if ( V_9 -> V_269 )
return - V_268 ;
F_136 ( V_9 -> V_210 , V_260 ,
sizeof( V_9 -> V_210 ) ) ;
V_9 -> V_174 = V_26 ;
V_113 = L_48 ;
F_132 = F_128 ;
} else {
return - V_158 ;
}
if ( V_63 == V_38 ) {
struct V_10 * V_11 ;
V_9 -> V_11 = F_137 ( V_264 * sizeof( V_9 -> V_11 [ 0 ] ) , V_270 ) ;
if ( ! V_9 -> V_11 )
goto V_166;
V_11 = V_9 -> V_11 ;
for ( V_85 = 0 ; V_85 < V_264 ; V_85 ++ , V_11 ++ ) {
F_138 ( & V_11 -> V_14 ) ;
V_11 -> V_18 = 0 ;
V_11 -> V_19 = 0 ;
F_139 ( & V_11 -> V_39 ,
F_118 ) ;
V_11 -> V_9 = V_9 ;
}
} else {
V_262 = F_137 ( V_264 * sizeof( struct V_261 * ) ,
V_270 ) ;
if ( ! V_262 )
goto V_166;
}
F_94 ( V_81 , V_63 ) ;
V_255 = NULL ;
for ( V_85 = 0 ; V_85 < V_264 ; V_85 ++ ) {
if ( V_63 == V_38 )
V_176 = F_102 ( V_81 , V_85 ) ;
else
V_176 = F_110 ( V_81 , V_85 ) ;
if ( F_140 ( V_176 ) ) {
V_232 = F_141 ( V_176 ) ;
goto V_271;
}
V_255 = F_13 ( sizeof( * V_255 ) , V_270 ) ;
if ( ! V_255 )
goto V_272;
V_255 -> V_81 = V_81 ;
V_255 -> V_176 = V_176 ;
if ( V_63 == V_209 ) {
V_255 -> V_259 = F_13 ( V_9 -> V_211 ,
V_270 ) ;
if ( ! V_255 -> V_259 )
goto V_271;
} else {
V_255 -> V_259 = NULL ;
}
V_255 -> V_85 = V_85 ;
V_263 = F_142 ( F_132 , V_255 , V_113 , V_9 -> V_273 , V_85 ) ;
if ( F_140 ( V_263 ) ) {
V_232 = F_141 ( V_263 ) ;
goto V_271;
}
V_255 = NULL ;
if ( V_63 == V_38 )
V_9 -> V_11 [ V_85 ] . V_42 = V_263 ;
else
V_262 [ V_85 ] = V_263 ;
}
if ( V_63 == V_209 )
V_9 -> V_269 = V_262 ;
F_6 ( & V_9 -> V_43 ) ;
V_9 -> V_37 |= V_63 ;
F_11 ( & V_9 -> V_43 ) ;
F_143 () ;
return 0 ;
V_272:
F_109 ( V_176 -> V_177 ) ;
V_271:
if ( V_255 ) {
F_109 ( V_255 -> V_176 -> V_177 ) ;
F_14 ( V_255 -> V_259 ) ;
F_14 ( V_255 ) ;
}
V_264 = V_85 ;
while ( V_264 -- > 0 ) {
if ( V_63 == V_38 )
F_144 ( V_9 -> V_11 [ V_264 ] . V_42 ) ;
else
F_144 ( V_262 [ V_264 ] ) ;
}
F_14 ( V_262 ) ;
V_166:
if ( ! ( V_9 -> V_37 & V_38 ) ) {
F_14 ( V_9 -> V_11 ) ;
V_9 -> V_11 = NULL ;
}
return V_232 ;
}
int F_145 ( struct V_81 * V_81 , int V_63 )
{
struct V_8 * V_9 = F_44 ( V_81 ) ;
struct V_261 * * V_262 ;
int V_85 ;
int V_165 = - V_158 ;
F_57 ( 7 , L_45 , V_265 , F_133 ( V_266 ) ) ;
if ( V_63 == V_38 ) {
if ( ! V_9 -> V_11 )
return - V_274 ;
F_6 ( & V_9 -> V_43 ) ;
F_18 ( & V_9 -> V_13 ) ;
V_9 -> V_37 &= ~ V_38 ;
F_24 ( & V_9 -> V_13 ) ;
F_11 ( & V_9 -> V_43 ) ;
V_165 = 0 ;
for ( V_85 = V_9 -> V_47 ; V_85 >= 0 ; V_85 -- ) {
struct V_10 * V_11 = & V_9 -> V_11 [ V_85 ] ;
int V_216 ;
F_122 ( L_49 ,
F_133 ( V_11 -> V_42 ) ) ;
F_146 ( & V_11 -> V_39 ) ;
V_216 = F_144 ( V_11 -> V_42 ) ;
if ( V_165 >= 0 )
V_165 = V_216 ;
}
F_14 ( V_9 -> V_11 ) ;
V_9 -> V_11 = NULL ;
} else if ( V_63 == V_209 ) {
if ( ! V_9 -> V_269 )
return - V_274 ;
V_9 -> V_37 &= ~ V_209 ;
V_262 = V_9 -> V_269 ;
V_165 = 0 ;
for ( V_85 = V_9 -> V_47 ; V_85 >= 0 ; V_85 -- ) {
int V_216 ;
F_122 ( L_50 ,
F_133 ( V_262 [ V_85 ] ) ) ;
V_216 = F_144 ( V_262 [ V_85 ] ) ;
if ( V_165 >= 0 )
V_165 = V_216 ;
}
F_14 ( V_262 ) ;
V_9 -> V_269 = NULL ;
}
F_147 () ;
return V_165 ;
}
int T_6 F_148 ( struct V_81 * V_81 )
{
struct V_8 * V_9 = F_44 ( V_81 ) ;
F_149 ( & V_9 -> V_275 , L_51 , & V_276 ) ;
F_150 ( & V_9 -> V_13 ) ;
F_150 ( & V_9 -> V_43 ) ;
return 0 ;
}
void F_151 ( struct V_81 * V_81 )
{
int V_165 ;
struct V_8 * V_9 = F_44 ( V_81 ) ;
F_152 ( & V_9 -> V_275 ) ;
V_165 = F_145 ( V_81 , V_38 ) ;
if ( V_165 && V_165 != - V_274 )
F_45 ( L_52 ) ;
V_165 = F_145 ( V_81 , V_209 ) ;
if ( V_165 && V_165 != - V_274 )
F_45 ( L_53 ) ;
F_153 ( & V_9 -> V_275 ) ;
}
