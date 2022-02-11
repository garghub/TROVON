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
static int F_30 ( struct V_8 * V_9 ,
struct V_45 * V_46 , int V_49 )
{
unsigned long V_50 = F_31 ( V_46 -> V_51 ) ;
unsigned long V_52 = V_35 ;
unsigned long V_53 = ( V_52 + V_46 -> V_54 ) & ~ 3UL ;
unsigned int V_55 ;
int V_56 ;
int V_57 ;
if ( F_32 ( V_46 -> V_58 & V_59 ) )
V_57 = 0 ;
else if ( F_33 ( V_46 -> V_60 == V_61 ) ) {
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
} else if ( F_32 ( V_46 -> V_60 == V_70 ) ) {
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
V_55 = F_34 ( V_9 ) ;
if ( V_55 > 0 ) {
long V_75 = V_53 - V_50 ;
long V_76 = F_21 ( V_46 -> V_54 >> 1 , 10UL * V_77 ) ;
if ( abs ( V_75 ) < F_35 ( long , V_55 , V_76 ) ) {
int V_78 = V_50 & 3 ;
if ( V_78 >= F_36 ( V_9 ) )
return 0 ;
if ( F_37 ( V_52 , V_50 - V_46 -> V_54 +
( V_55 >> 3 ) ) )
return 0 ;
V_53 |= V_78 + 1 ;
}
}
V_56 = F_38 ( V_9 ) ;
if ( V_56 > 0 ) {
if ( ! ( V_46 -> V_58 & V_59 ) &&
V_49 % V_56 != F_39 ( V_9 ) )
return 0 ;
} else if ( V_55 <= 0 &&
V_49 != F_39 ( V_9 ) )
return 0 ;
V_69:
V_46 -> V_68 = V_46 -> V_62 ;
V_53 = F_40 ( & V_46 -> V_51 , V_50 , V_53 ) ;
return V_53 == V_50 || V_57 ;
}
static void F_41 ( struct V_79 * V_79 , struct V_45 * V_46 ,
int V_49 )
{
struct V_8 * V_9 = F_42 ( V_79 ) ;
struct V_48 * V_80 ;
struct F_41 * V_81 ;
struct V_7 * V_82 ;
struct V_10 * V_11 ;
int V_83 ;
int V_84 ;
if ( F_32 ( V_46 -> V_85 != V_86 ) )
return;
if ( V_46 -> V_58 & V_87 )
return;
if ( ! F_30 ( V_9 , V_46 , V_49 ) )
return;
F_6 ( & V_9 -> V_43 ) ;
if ( ! ( V_9 -> V_37 & V_38 ) ) {
F_11 ( & V_9 -> V_43 ) ;
return;
}
V_83 = F_27 ( V_9 , V_46 ) ;
V_11 = & V_9 -> V_11 [ V_83 ] ;
V_82 = V_11 -> V_36 ;
if ( V_82 ) {
V_80 = (struct V_48 * ) V_82 -> V_21 ;
if ( ! V_80 -> V_30 ) {
F_17 ( V_9 , V_11 ) ;
V_11 -> V_36 = NULL ;
V_82 = NULL ;
}
}
if ( ! V_82 ) {
V_82 = F_29 ( V_9 ) ;
if ( ! V_82 ) {
F_11 ( & V_9 -> V_43 ) ;
F_43 ( L_1 ) ;
return;
}
V_11 -> V_36 = V_82 ;
}
V_84 = ( V_46 -> V_58 & V_88 ) ? V_89 :
V_90 ;
V_80 = (struct V_48 * ) V_82 -> V_21 ;
V_81 = (struct F_41 * ) V_82 -> V_32 ;
V_81 -> V_23 = 0 ;
V_81 -> V_60 = V_46 -> V_60 ;
V_81 -> V_91 = V_46 -> V_91 ;
V_81 -> V_92 = V_46 -> V_92 ;
V_81 -> V_93 = V_46 -> V_93 ;
V_81 -> V_94 = V_46 -> V_94 . V_95 ;
V_81 -> V_96 = V_46 -> V_96 . V_95 ;
V_81 -> V_97 = V_46 -> V_97 . V_95 ;
V_81 -> V_58 = F_15 ( V_46 -> V_58 & ~ V_98 ) ;
V_81 -> V_62 = F_15 ( V_46 -> V_62 ) ;
if ( V_46 -> V_58 & V_88 ) {
struct V_99 * V_100 =
(struct V_99 * ) & V_81 [ 1 ] ;
memcpy ( V_100 , & V_46 -> V_101 , sizeof( * V_100 ) ) ;
}
V_80 -> V_30 ++ ;
V_80 -> V_28 = F_15 ( F_44 ( V_80 -> V_28 ) + V_84 ) ;
V_82 -> V_32 += V_84 ;
if ( V_82 -> V_32 + V_89 > V_82 -> V_33 ) {
F_17 ( V_9 , V_11 ) ;
V_11 -> V_36 = NULL ;
}
F_11 ( & V_9 -> V_43 ) ;
V_46 = V_46 -> V_102 ;
if ( V_46 ) {
if ( V_46 -> V_58 & V_59 )
V_49 = F_45 ( 1 , & V_46 -> V_103 ) ;
else
V_49 = F_39 ( V_9 ) ;
F_46 ( V_79 , V_46 -> V_102 , V_49 ) ;
}
}
void F_46 ( struct V_79 * V_79 , struct V_45 * V_46 , int V_49 )
{
struct V_8 * V_9 = F_42 ( V_79 ) ;
struct V_29 * V_80 ;
union F_46 * V_81 ;
struct V_7 * V_82 ;
struct V_10 * V_11 ;
int V_83 ;
T_1 * V_104 ;
unsigned int V_84 , V_105 , V_106 ;
if ( F_47 ( V_9 ) == 0 ) {
F_41 ( V_79 , V_46 , V_49 ) ;
return;
}
if ( V_46 -> V_58 & V_87 )
goto V_102;
V_107:
if ( ! F_30 ( V_9 , V_46 , V_49 ) )
goto V_102;
V_105 = 0 ;
if ( V_46 -> V_108 ) {
if ( ! V_46 -> V_109 || ! V_46 -> V_110 ) {
F_48 ( L_2 ) ;
return;
}
V_105 = F_49 ( V_46 -> V_111 -> V_112 , V_113 ) ;
}
F_6 ( & V_9 -> V_43 ) ;
if ( ! ( V_9 -> V_37 & V_38 ) ) {
F_11 ( & V_9 -> V_43 ) ;
return;
}
V_83 = F_27 ( V_9 , V_46 ) ;
V_11 = & V_9 -> V_11 [ V_83 ] ;
#ifdef F_50
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
F_17 ( V_9 , V_11 ) ;
V_11 -> V_36 = NULL ;
V_82 = NULL ;
V_106 = 0 ;
}
}
if ( ! V_82 ) {
V_82 = F_12 ( V_9 ) ;
if ( ! V_82 ) {
F_11 ( & V_9 -> V_43 ) ;
F_43 ( L_1 ) ;
return;
}
V_11 -> V_36 = V_82 ;
V_80 = V_82 -> V_21 ;
}
V_104 = V_82 -> V_32 ;
V_82 -> V_32 += V_106 + V_84 ;
V_80 -> V_28 = F_15 ( F_44 ( V_80 -> V_28 ) + V_106 + V_84 ) ;
while ( V_106 -- )
* ( V_104 ++ ) = 0 ;
V_81 = (union F_46 * ) V_104 ;
V_81 -> V_118 . type = ( V_46 -> V_85 == V_114 ? V_119 : 0 ) ;
V_81 -> V_118 . V_120 = F_15 ( V_84 & V_121 ) ;
V_81 -> V_118 . V_58 = F_51 ( V_46 -> V_58 & ~ V_98 ) ;
V_81 -> V_118 . V_62 = F_15 ( V_46 -> V_62 ) ;
V_81 -> V_118 . V_60 = V_46 -> V_60 ;
V_81 -> V_118 . V_91 = V_46 -> V_91 ;
V_81 -> V_118 . V_92 = V_46 -> V_92 ;
V_81 -> V_118 . V_93 = V_46 -> V_93 ;
V_81 -> V_118 . V_122 = F_51 ( V_46 -> V_122 ) ;
V_81 -> V_118 . V_54 = F_51 ( V_46 -> V_54 / V_77 ) ;
V_80 -> V_30 ++ ;
#ifdef F_50
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
F_11 ( & V_9 -> V_43 ) ;
V_102:
V_46 = V_46 -> V_102 ;
if ( ! V_46 )
return;
if ( V_46 -> V_58 & V_59 )
V_49 = F_45 ( 1 , & V_46 -> V_103 ) ;
else
V_49 = F_39 ( V_9 ) ;
goto V_107;
}
static inline int
F_52 ( struct V_79 * V_79 , int V_85 , union F_46 * V_129 ,
struct V_130 * V_104 ,
T_1 * V_109 , unsigned int V_108 ,
T_1 * V_131 , unsigned int V_105 )
{
#ifdef F_50
if ( V_85 == V_114 )
F_53 ( V_79 , V_85 , V_129 -> V_123 . V_60 ,
( const union V_132 * ) & V_129 -> V_123 . V_94 ,
V_129 -> V_123 . V_91 ,
( const union V_132 * ) & V_129 -> V_123 . V_96 ,
V_129 -> V_123 . V_92 , V_104 ) ;
else
#endif
F_53 ( V_79 , V_85 , V_129 -> V_118 . V_60 ,
( const union V_132 * ) & V_129 -> V_118 . V_94 ,
V_129 -> V_118 . V_91 ,
( const union V_132 * ) & V_129 -> V_118 . V_96 ,
V_129 -> V_118 . V_92 , V_104 ) ;
if ( V_108 ) {
if ( V_105 ) {
char V_82 [ V_113 + 1 ] ;
memcpy ( V_82 , V_131 , V_105 ) ;
V_82 [ V_105 ] = 0 ;
V_104 -> V_111 = F_54 ( V_82 ) ;
if ( ! V_104 -> V_111 ) {
F_55 ( 3 , L_3 ,
V_82 ) ;
return 1 ;
}
} else {
F_48 ( L_4 ) ;
return 1 ;
}
V_104 -> V_109 = F_56 ( V_109 , V_108 , V_20 ) ;
if ( ! V_104 -> V_109 ) {
if ( V_104 -> V_111 -> V_133 )
F_57 ( V_104 -> V_111 -> V_133 ) ;
return - V_134 ;
}
V_104 -> V_108 = V_108 ;
}
return 0 ;
}
static void F_58 ( struct V_79 * V_79 , struct V_130 * V_135 ,
unsigned int V_58 , unsigned int V_62 ,
unsigned int V_60 , unsigned int type ,
const union V_132 * V_97 , T_2 V_93 ,
unsigned long V_54 , T_3 V_122 ,
struct V_99 * V_100 )
{
struct V_136 * V_110 ;
struct V_45 * V_46 ;
struct V_8 * V_9 = F_42 ( V_79 ) ;
if ( ! ( V_58 & V_59 ) )
V_46 = F_59 ( V_135 ) ;
else
V_46 = F_60 ( V_135 ) ;
if ( V_46 ) {
F_14 ( V_135 -> V_109 ) ;
V_110 = V_46 -> V_110 ;
F_6 ( & V_46 -> V_137 ) ;
if ( ( V_46 -> V_58 ^ V_58 ) & V_138 &&
! ( V_58 & V_59 ) && V_110 ) {
if ( V_58 & V_138 ) {
F_61 ( & V_110 -> V_139 ) ;
F_62 ( & V_110 -> V_140 ) ;
} else {
F_62 ( & V_110 -> V_139 ) ;
F_61 ( & V_110 -> V_140 ) ;
}
}
V_58 &= V_141 ;
V_58 |= V_46 -> V_58 & ~ V_141 ;
V_46 -> V_58 = V_58 ;
F_11 ( & V_46 -> V_137 ) ;
if ( ! V_110 )
F_63 ( V_46 ) ;
} else {
F_64 () ;
V_110 = F_65 ( V_79 , type , V_97 , V_93 , V_135 -> V_96 ,
V_135 -> V_92 , V_60 , V_122 , V_58 ) ;
V_46 = F_66 ( V_135 , V_97 , V_93 , V_58 , V_110 , V_122 ) ;
F_67 () ;
if ( ! V_46 ) {
if ( V_135 -> V_109 )
F_14 ( V_135 -> V_109 ) ;
F_55 ( 2 , L_5 ) ;
return;
}
}
if ( V_100 )
memcpy ( & V_46 -> V_101 , V_100 , sizeof( * V_100 ) ) ;
F_68 ( & V_46 -> V_103 , F_39 ( V_9 ) ) ;
V_46 -> V_62 = V_62 ;
V_46 -> V_68 = V_46 -> V_62 ;
if ( V_54 ) {
if ( V_54 > V_142 / V_77 )
V_54 = V_142 / V_77 ;
V_46 -> V_54 = V_54 * V_77 ;
} else {
struct V_143 * V_144 ;
V_144 = F_69 ( V_79 , V_60 ) ;
if ( ! ( V_58 & V_59 ) && V_144 && V_144 -> V_145 )
V_46 -> V_54 = V_144 -> V_145 [ V_62 ] ;
else
V_46 -> V_54 = ( 3 * 60 * V_77 ) ;
}
F_70 ( V_46 ) ;
}
static void F_71 ( struct V_79 * V_79 , const char * V_146 ,
const V_117 V_147 )
{
struct V_48 * V_80 = (struct V_48 * ) V_146 ;
struct F_41 * V_81 ;
struct V_99 * V_100 ;
struct V_148 * V_149 ;
struct V_130 V_135 ;
char * V_104 ;
int V_150 ;
V_104 = ( char * ) V_146 + sizeof( struct V_48 ) ;
for ( V_150 = 0 ; V_150 < V_80 -> V_30 ; V_150 ++ ) {
unsigned int V_58 , V_62 ;
if ( V_104 + V_90 > V_146 + V_147 ) {
F_48 ( L_6 ) ;
return;
}
V_81 = (struct F_41 * ) V_104 ;
V_58 = F_44 ( V_81 -> V_58 ) | V_151 ;
V_58 &= ~ V_98 ;
if ( V_58 & V_88 ) {
V_100 = (struct V_99 * ) & V_81 [ 1 ] ;
V_104 += V_89 ;
if ( V_104 > V_146 + V_147 ) {
F_48 ( L_7 ) ;
return;
}
} else {
V_100 = NULL ;
V_104 += V_90 ;
}
V_62 = F_44 ( V_81 -> V_62 ) ;
if ( ! ( V_58 & V_59 ) ) {
V_149 = F_72 ( V_81 -> V_60 ) ;
if ( ! V_149 ) {
F_55 ( 2 , L_8 ,
V_81 -> V_60 ) ;
continue;
}
if ( V_62 >= V_149 -> V_152 ) {
F_55 ( 2 , L_9 ,
V_149 -> V_112 , V_62 ) ;
continue;
}
} else {
if ( V_62 > 0 ) {
F_55 ( 2 , L_10 ,
V_62 ) ;
V_62 = 0 ;
}
}
F_53 ( V_79 , V_86 , V_81 -> V_60 ,
( const union V_132 * ) & V_81 -> V_94 ,
V_81 -> V_91 ,
( const union V_132 * ) & V_81 -> V_96 ,
V_81 -> V_92 , & V_135 ) ;
F_58 ( V_79 , & V_135 , V_58 , V_62 , V_81 -> V_60 , V_86 ,
(union V_132 * ) & V_81 -> V_97 , V_81 -> V_93 ,
0 , 0 , V_100 ) ;
}
}
static inline int F_73 ( T_1 * V_104 , unsigned int V_153 ,
T_3 * V_154 ,
struct V_99 * V_100 )
{
struct V_99 * V_155 ;
V_155 = (struct V_99 * ) V_104 ;
if ( V_153 != sizeof( struct V_99 ) ) {
F_55 ( 2 , L_11 ) ;
return - V_156 ;
}
if ( * V_154 & V_157 ) {
F_55 ( 2 , L_12 ) ;
return - V_156 ;
}
F_1 ( & V_155 -> V_101 , & V_100 -> V_101 ) ;
F_1 ( & V_155 -> V_126 , & V_100 -> V_126 ) ;
* V_154 |= V_157 ;
return 0 ;
}
static int F_74 ( T_1 * V_104 , unsigned int V_153 , unsigned int * V_158 ,
T_1 * * V_159 , unsigned int V_160 ,
T_3 * V_154 , T_3 V_161 )
{
if ( V_153 > V_160 ) {
F_55 ( 2 , L_13 , V_160 ) ;
return - V_156 ;
}
if ( * V_154 & V_161 ) {
F_55 ( 2 , L_14 , V_161 ) ;
return - V_156 ;
}
* V_158 = V_153 ;
* V_159 = V_104 ;
* V_154 |= V_161 ;
return 0 ;
}
static inline int F_75 ( struct V_79 * V_79 , T_1 * V_104 , T_1 * V_162 )
{
struct V_99 V_100 ;
union F_46 * V_81 ;
struct V_148 * V_149 ;
struct V_130 V_135 ;
T_3 V_58 ;
unsigned int V_85 , V_62 , V_108 = 0 , V_105 = 0 ;
T_1 * V_109 = NULL , * V_131 = NULL ;
T_3 V_154 = 0 ;
int V_163 = 0 ;
V_81 = (union F_46 * ) V_104 ;
if ( V_81 -> V_123 . type & V_119 ) {
#ifdef F_50
V_85 = V_114 ;
V_104 += sizeof( struct V_115 ) ;
#else
F_55 ( 3 , L_15 ) ;
V_163 = 10 ;
goto V_164;
#endif
} else if ( ! V_81 -> V_118 . type ) {
V_85 = V_86 ;
V_104 += sizeof( struct V_116 ) ;
} else {
return - 10 ;
}
if ( V_104 > V_162 )
return - 20 ;
while ( V_104 < V_162 ) {
int V_165 ;
int V_153 ;
if ( V_104 + 2 > V_162 )
return - 30 ;
V_165 = * ( V_104 ++ ) ;
V_153 = * ( V_104 ++ ) ;
if ( ! V_153 || ( ( V_104 + V_153 ) > V_162 ) )
return - 40 ;
switch ( V_165 & ~ V_166 ) {
case V_125 :
if ( F_73 ( V_104 , V_153 , & V_154 , & V_100 ) )
return - 50 ;
break;
case V_127 :
if ( F_74 ( V_104 , V_153 , & V_108 , & V_109 ,
V_167 , & V_154 ,
V_168 ) )
return - 60 ;
break;
case V_128 :
if ( F_74 ( V_104 , V_153 , & V_105 , & V_131 ,
V_113 , & V_154 ,
V_169 ) )
return - 70 ;
break;
default:
if ( ! ( V_165 & V_166 ) ) {
F_55 ( 3 , L_16 ,
V_165 & ~ V_166 ) ;
V_163 = 20 ;
goto V_164;
}
}
V_104 += V_153 ;
}
V_58 = F_76 ( V_81 -> V_118 . V_58 ) & V_170 ;
V_58 |= V_151 ;
V_62 = F_44 ( V_81 -> V_118 . V_62 ) ;
if ( ! ( V_58 & V_59 ) ) {
V_149 = F_72 ( V_81 -> V_118 . V_60 ) ;
if ( ! V_149 ) {
F_55 ( 3 , L_17 ,
V_81 -> V_118 . V_60 ) ;
V_163 = 30 ;
goto V_164;
}
if ( V_62 >= V_149 -> V_152 ) {
F_55 ( 3 , L_18 ,
V_149 -> V_112 , V_62 ) ;
V_163 = 40 ;
goto V_164;
}
} else {
if ( V_62 > 0 ) {
F_55 ( 3 , L_19 ,
V_62 ) ;
V_62 = 0 ;
}
}
if ( F_52 ( V_79 , V_85 , V_81 , & V_135 , V_109 ,
V_108 , V_131 , V_105 ) ) {
V_163 = 50 ;
goto V_164;
}
if ( V_85 == V_86 )
F_58 ( V_79 , & V_135 , V_58 , V_62 , V_81 -> V_118 . V_60 , V_85 ,
(union V_132 * ) & V_81 -> V_118 . V_97 , V_81 -> V_118 . V_93 ,
F_76 ( V_81 -> V_118 . V_54 ) , F_76 ( V_81 -> V_118 . V_122 ) ,
( V_154 & V_157 ? & V_100 : NULL )
) ;
#ifdef F_50
else
F_58 ( V_79 , & V_135 , V_58 , V_62 , V_81 -> V_123 . V_60 , V_85 ,
(union V_132 * ) & V_81 -> V_123 . V_97 , V_81 -> V_123 . V_93 ,
F_76 ( V_81 -> V_123 . V_54 ) , F_76 ( V_81 -> V_123 . V_122 ) ,
( V_154 & V_157 ? & V_100 : NULL )
) ;
#endif
return 0 ;
V_164:
F_55 ( 2 , L_20 , V_163 ) ;
return V_163 ;
}
static void F_77 ( struct V_79 * V_79 , T_1 * V_146 ,
const V_117 V_147 )
{
struct V_8 * V_9 = F_42 ( V_79 ) ;
struct V_29 * V_171 = (struct V_29 * ) V_146 ;
T_1 * V_104 , * V_162 ;
int V_150 , V_30 ;
if ( V_147 < sizeof( struct V_48 ) ) {
F_55 ( 2 , L_21 ) ;
return;
}
if ( V_147 != F_44 ( V_171 -> V_28 ) ) {
F_55 ( 2 , L_22 ) ;
return;
}
if ( V_9 -> V_172 != 0 && V_171 -> V_26 != V_9 -> V_172 ) {
F_55 ( 7 , L_23 , V_171 -> V_26 ) ;
return;
}
if ( ( V_171 -> V_24 == V_25 ) && ( V_171 -> V_23 == 0 )
&& ( V_171 -> V_31 == 0 ) ) {
V_162 = V_146 + sizeof( struct V_29 ) ;
V_30 = V_171 -> V_30 ;
for ( V_150 = 0 ; V_150 < V_30 ; V_150 ++ ) {
union F_46 * V_81 ;
unsigned int V_28 ;
int V_163 ;
V_104 = V_162 ;
if ( V_104 + sizeof( V_81 -> V_118 ) > V_146 + V_147 ) {
F_48 ( L_24 ) ;
return;
}
V_81 = (union F_46 * ) V_104 ;
V_28 = F_44 ( V_81 -> V_118 . V_120 ) & V_121 ;
V_162 = V_104 + V_28 ;
if ( V_162 > V_146 + V_147 ) {
F_48 ( L_25 ) ;
return;
}
if ( F_44 ( V_81 -> V_118 . V_120 ) >> V_173 ) {
F_48 ( L_26 ,
F_44 ( V_81 -> V_118 . V_120 ) >> V_173 ) ;
return;
}
V_163 = F_75 ( V_79 , V_104 , V_162 ) ;
if ( V_163 < 0 ) {
F_48 ( L_27 ,
V_163 ) ;
return;
}
V_162 = V_104 + ( ( V_28 + 3 ) & ~ 3 ) ;
}
} else {
F_71 ( V_79 , V_146 , V_147 ) ;
return;
}
}
static void F_78 ( struct V_174 * V_175 , int V_176 , int V_177 )
{
F_79 ( V_175 ) ;
if ( V_176 ) {
V_177 = F_80 ( int , V_177 , ( V_178 + 1 ) / 2 ,
V_179 ) ;
V_175 -> V_180 = V_177 * 2 ;
V_175 -> V_181 |= V_182 ;
} else {
V_177 = F_80 ( int , V_177 , ( V_183 + 1 ) / 2 ,
V_184 ) ;
V_175 -> V_185 = V_177 * 2 ;
V_175 -> V_181 |= V_186 ;
}
F_81 ( V_175 ) ;
}
static void F_82 ( struct V_174 * V_175 , T_4 V_187 )
{
struct V_188 * V_189 = F_83 ( V_175 ) ;
F_79 ( V_175 ) ;
V_189 -> V_190 = V_187 ? 1 : 0 ;
F_81 ( V_175 ) ;
}
static void F_84 ( struct V_174 * V_175 , T_4 V_191 )
{
struct V_188 * V_189 = F_83 ( V_175 ) ;
F_79 ( V_175 ) ;
V_189 -> V_192 = V_191 ;
F_81 ( V_175 ) ;
}
static int F_85 ( struct V_174 * V_175 , char * V_193 )
{
struct V_194 * V_195 ;
struct V_188 * V_189 = F_83 ( V_175 ) ;
struct V_79 * V_79 = F_86 ( V_175 ) ;
V_195 = F_87 ( V_79 , V_193 ) ;
if ( ! V_195 )
return - V_196 ;
if ( V_175 -> V_197 && V_195 -> V_198 != V_175 -> V_197 )
return - V_156 ;
F_79 ( V_175 ) ;
V_189 -> V_199 = V_195 -> V_198 ;
F_81 ( V_175 ) ;
return 0 ;
}
static int F_88 ( struct V_79 * V_79 , int V_37 )
{
struct V_8 * V_9 = F_42 ( V_79 ) ;
struct V_194 * V_195 ;
int V_200 ;
if ( V_37 == V_38 ) {
V_195 = F_87 ( V_79 , V_9 -> V_201 ) ;
if ( ! V_195 )
return - V_196 ;
V_200 = ( V_195 -> V_202 - sizeof( struct V_203 ) -
sizeof( struct V_204 ) -
V_205 - 20 ) / V_90 ;
V_9 -> V_22 = V_205 +
V_90 * F_89 ( V_200 , V_206 ) ;
F_55 ( 7 , L_28
L_29 , V_9 -> V_22 ) ;
} else if ( V_37 == V_207 ) {
V_195 = F_87 ( V_79 , V_9 -> V_208 ) ;
if ( ! V_195 )
return - V_196 ;
V_9 -> V_209 = V_195 -> V_202 -
sizeof( struct V_203 ) - sizeof( struct V_204 ) ;
F_55 ( 7 , L_30
L_29 , V_9 -> V_209 ) ;
}
return 0 ;
}
static int
F_90 ( struct V_174 * V_175 , struct V_210 * V_211 , char * V_193 )
{
struct V_79 * V_79 = F_86 ( V_175 ) ;
struct V_212 V_213 ;
struct V_194 * V_195 ;
int V_214 ;
memset ( & V_213 , 0 , sizeof( V_213 ) ) ;
memcpy ( & V_213 . V_215 , V_211 , sizeof( struct V_210 ) ) ;
V_195 = F_87 ( V_79 , V_193 ) ;
if ( ! V_195 )
return - V_196 ;
if ( V_175 -> V_197 && V_195 -> V_198 != V_175 -> V_197 )
return - V_156 ;
V_213 . V_216 = V_195 -> V_198 ;
F_79 ( V_175 ) ;
V_214 = F_91 ( V_175 , & V_213 ) ;
F_81 ( V_175 ) ;
return V_214 ;
}
static int F_92 ( struct V_217 * V_174 , char * V_193 )
{
struct V_79 * V_79 = F_86 ( V_174 -> V_175 ) ;
struct V_194 * V_195 ;
T_5 V_211 ;
struct V_218 sin ;
V_195 = F_87 ( V_79 , V_193 ) ;
if ( ! V_195 )
return - V_196 ;
V_211 = F_93 ( V_195 , 0 , V_219 ) ;
if ( ! V_211 )
F_43 ( L_31
L_32 ) ;
F_55 ( 7 , L_33 ,
V_193 , & V_211 ) ;
sin . V_220 = V_86 ;
sin . V_221 . V_222 = V_211 ;
sin . V_223 = 0 ;
return V_174 -> V_224 -> V_225 ( V_174 , (struct V_226 * ) & sin , sizeof( sin ) ) ;
}
static struct V_217 * F_94 ( struct V_79 * V_79 , int V_83 )
{
struct V_8 * V_9 = F_42 ( V_79 ) ;
struct V_218 V_227 = {
. V_220 = V_86 ,
. V_223 = F_95 ( V_228 + V_83 ) ,
. V_221 . V_222 = F_96 ( V_229 ) ,
} ;
struct V_217 * V_174 ;
int V_230 ;
V_230 = F_97 ( V_231 , V_232 , V_233 , & V_174 ) ;
if ( V_230 < 0 ) {
F_43 ( L_34 ) ;
return F_98 ( V_230 ) ;
}
F_99 ( V_174 -> V_175 , V_79 ) ;
V_230 = F_85 ( V_174 -> V_175 , V_9 -> V_201 ) ;
if ( V_230 < 0 ) {
F_43 ( L_35 ) ;
goto error;
}
F_82 ( V_174 -> V_175 , 0 ) ;
F_84 ( V_174 -> V_175 , 1 ) ;
V_230 = F_100 ( V_9 ) ;
if ( V_230 > 0 )
F_78 ( V_174 -> V_175 , 1 , V_230 ) ;
V_230 = F_92 ( V_174 , V_9 -> V_201 ) ;
if ( V_230 < 0 ) {
F_43 ( L_36 ) ;
goto error;
}
V_230 = V_174 -> V_224 -> V_234 ( V_174 , (struct V_226 * ) & V_227 ,
sizeof( struct V_226 ) , 0 ) ;
if ( V_230 < 0 ) {
F_43 ( L_37 ) ;
goto error;
}
return V_174 ;
error:
F_101 ( V_174 -> V_175 ) ;
return F_98 ( V_230 ) ;
}
static struct V_217 * F_102 ( struct V_79 * V_79 , int V_83 )
{
struct V_8 * V_9 = F_42 ( V_79 ) ;
struct V_218 V_227 = {
. V_220 = V_86 ,
. V_223 = F_95 ( V_228 + V_83 ) ,
. V_221 . V_222 = F_96 ( V_229 ) ,
} ;
struct V_217 * V_174 ;
int V_230 ;
V_230 = F_97 ( V_231 , V_232 , V_233 , & V_174 ) ;
if ( V_230 < 0 ) {
F_43 ( L_34 ) ;
return F_98 ( V_230 ) ;
}
F_99 ( V_174 -> V_175 , V_79 ) ;
V_174 -> V_175 -> V_235 = V_236 ;
V_230 = F_100 ( V_9 ) ;
if ( V_230 > 0 )
F_78 ( V_174 -> V_175 , 0 , V_230 ) ;
V_230 = V_174 -> V_224 -> V_225 ( V_174 , (struct V_226 * ) & V_227 ,
sizeof( struct V_226 ) ) ;
if ( V_230 < 0 ) {
F_43 ( L_38 ) ;
goto error;
}
V_230 = F_90 ( V_174 -> V_175 ,
(struct V_210 * ) & V_227 . V_221 ,
V_9 -> V_208 ) ;
if ( V_230 < 0 ) {
F_43 ( L_39 ) ;
goto error;
}
return V_174 ;
error:
F_101 ( V_174 -> V_175 ) ;
return F_98 ( V_230 ) ;
}
static int
F_103 ( struct V_217 * V_174 , const char * V_146 , const V_117 V_237 )
{
struct V_238 V_239 = { . V_240 = V_241 | V_242 } ;
struct V_243 V_244 ;
int V_84 ;
F_104 ( 7 ) ;
V_244 . V_245 = ( void * ) V_146 ;
V_244 . V_246 = V_237 ;
V_84 = F_105 ( V_174 , & V_239 , & V_244 , 1 , ( V_117 ) ( V_237 ) ) ;
F_106 ( 7 ) ;
return V_84 ;
}
static int
F_107 ( struct V_217 * V_174 , struct V_29 * V_239 )
{
int V_247 ;
int V_214 ;
V_247 = F_44 ( V_239 -> V_28 ) ;
V_214 = F_103 ( V_174 , ( char * ) V_239 , V_247 ) ;
if ( V_214 >= 0 || V_214 == - V_248 )
return V_214 ;
F_43 ( L_40 , V_214 ) ;
return 0 ;
}
static int
F_108 ( struct V_217 * V_174 , char * V_146 , const V_117 V_147 )
{
struct V_238 V_239 = { NULL ,} ;
struct V_243 V_244 ;
int V_84 ;
F_104 ( 7 ) ;
V_244 . V_245 = V_146 ;
V_244 . V_246 = ( V_117 ) V_147 ;
V_84 = F_109 ( V_174 , & V_239 , & V_244 , 1 , V_147 , V_241 ) ;
if ( V_84 < 0 )
return V_84 ;
F_106 ( 7 ) ;
return V_84 ;
}
static void F_110 ( struct V_249 * V_250 )
{
struct V_10 * V_11 =
F_111 ( V_250 , struct V_10 ,
V_39 . V_250 ) ;
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
F_112 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
struct V_7 * V_12 ;
V_12 = F_5 ( V_9 , V_11 ) ;
if ( V_12 )
return V_12 ;
return F_25 ( V_9 , V_11 , V_251 ) ;
}
static int F_113 ( void * V_159 )
{
struct V_252 * V_253 = V_159 ;
struct V_8 * V_9 = F_42 ( V_253 -> V_79 ) ;
struct V_10 * V_11 = & V_9 -> V_11 [ V_253 -> V_83 ] ;
struct V_174 * V_175 = V_253 -> V_174 -> V_175 ;
struct V_7 * V_12 ;
F_114 ( L_41
L_42 ,
V_9 -> V_201 , V_9 -> V_27 , V_253 -> V_83 ) ;
for (; ; ) {
V_12 = F_112 ( V_9 , V_11 ) ;
if ( F_32 ( F_115 () ) )
break;
if ( ! V_12 ) {
F_116 ( V_254 ) ;
continue;
}
while ( F_107 ( V_253 -> V_174 , V_12 -> V_21 ) < 0 ) {
int V_214 = 0 ;
F_117 ( * F_118 ( V_175 ) ,
F_119 ( V_175 ) ||
F_115 () ,
V_214 ) ;
if ( F_32 ( F_115 () ) )
goto V_255;
}
F_16 ( V_12 ) ;
}
V_255:
F_8 ( V_44 ) ;
if ( V_12 )
F_16 ( V_12 ) ;
while ( ( V_12 = F_5 ( V_9 , V_11 ) ) )
F_16 ( V_12 ) ;
F_8 ( V_44 ) ;
V_12 = F_25 ( V_9 , V_11 , 0 ) ;
if ( V_12 )
F_16 ( V_12 ) ;
F_101 ( V_253 -> V_174 -> V_175 ) ;
F_14 ( V_253 ) ;
return 0 ;
}
static int F_120 ( void * V_159 )
{
struct V_252 * V_253 = V_159 ;
struct V_8 * V_9 = F_42 ( V_253 -> V_79 ) ;
int V_84 ;
F_114 ( L_43
L_42 ,
V_9 -> V_208 , V_9 -> V_172 , V_253 -> V_83 ) ;
while ( ! F_115 () ) {
F_121 ( * F_118 ( V_253 -> V_174 -> V_175 ) ,
! F_122 ( & V_253 -> V_174 -> V_175 -> V_256 )
|| F_115 () ) ;
while ( ! F_122 ( & ( V_253 -> V_174 -> V_175 -> V_256 ) ) ) {
V_84 = F_108 ( V_253 -> V_174 , V_253 -> V_257 ,
V_9 -> V_209 ) ;
if ( V_84 <= 0 ) {
if ( V_84 != - V_248 )
F_43 ( L_44 ) ;
break;
}
F_77 ( V_253 -> V_79 , V_253 -> V_257 , V_84 ) ;
}
}
F_101 ( V_253 -> V_174 -> V_175 ) ;
F_14 ( V_253 -> V_257 ) ;
F_14 ( V_253 ) ;
return 0 ;
}
int F_123 ( struct V_79 * V_79 , int V_62 , char * V_258 , T_1 V_26 )
{
struct V_252 * V_253 ;
struct V_259 * * V_260 = NULL , * V_261 ;
struct V_217 * V_174 ;
struct V_8 * V_9 = F_42 ( V_79 ) ;
char * V_112 ;
int (* F_124)( void * V_159 );
int V_83 , V_262 ;
int V_230 = - V_134 ;
F_55 ( 7 , L_45 , V_263 , F_125 ( V_264 ) ) ;
F_55 ( 7 , L_46 ,
sizeof( struct F_41 ) ) ;
if ( ! V_9 -> V_37 ) {
V_262 = F_126 ( F_127 ( V_9 ) , 1 , V_265 ) ;
V_9 -> V_47 = V_262 - 1 ;
} else
V_262 = V_9 -> V_47 + 1 ;
if ( V_62 == V_38 ) {
if ( V_9 -> V_11 )
return - V_266 ;
F_128 ( V_9 -> V_201 , V_258 ,
sizeof( V_9 -> V_201 ) ) ;
V_9 -> V_27 = V_26 ;
V_112 = L_47 ;
F_124 = F_113 ;
} else if ( V_62 == V_207 ) {
if ( V_9 -> V_267 )
return - V_266 ;
F_128 ( V_9 -> V_208 , V_258 ,
sizeof( V_9 -> V_208 ) ) ;
V_9 -> V_172 = V_26 ;
V_112 = L_48 ;
F_124 = F_120 ;
} else {
return - V_156 ;
}
if ( V_62 == V_38 ) {
struct V_10 * V_11 ;
V_9 -> V_11 = F_129 ( V_262 * sizeof( V_9 -> V_11 [ 0 ] ) , V_268 ) ;
if ( ! V_9 -> V_11 )
goto V_164;
V_11 = V_9 -> V_11 ;
for ( V_83 = 0 ; V_83 < V_262 ; V_83 ++ , V_11 ++ ) {
F_130 ( & V_11 -> V_14 ) ;
V_11 -> V_18 = 0 ;
V_11 -> V_19 = 0 ;
F_131 ( & V_11 -> V_39 ,
F_110 ) ;
V_11 -> V_9 = V_9 ;
}
} else {
V_260 = F_129 ( V_262 * sizeof( struct V_259 * ) ,
V_268 ) ;
if ( ! V_260 )
goto V_164;
}
F_88 ( V_79 , V_62 ) ;
V_253 = NULL ;
for ( V_83 = 0 ; V_83 < V_262 ; V_83 ++ ) {
if ( V_62 == V_38 )
V_174 = F_94 ( V_79 , V_83 ) ;
else
V_174 = F_102 ( V_79 , V_83 ) ;
if ( F_132 ( V_174 ) ) {
V_230 = F_133 ( V_174 ) ;
goto V_269;
}
V_253 = F_13 ( sizeof( * V_253 ) , V_268 ) ;
if ( ! V_253 )
goto V_270;
V_253 -> V_79 = V_79 ;
V_253 -> V_174 = V_174 ;
if ( V_62 == V_207 ) {
V_253 -> V_257 = F_13 ( V_9 -> V_209 ,
V_268 ) ;
if ( ! V_253 -> V_257 )
goto V_269;
} else {
V_253 -> V_257 = NULL ;
}
V_253 -> V_83 = V_83 ;
V_261 = F_134 ( F_124 , V_253 , V_112 , V_9 -> V_271 , V_83 ) ;
if ( F_132 ( V_261 ) ) {
V_230 = F_133 ( V_261 ) ;
goto V_269;
}
V_253 = NULL ;
if ( V_62 == V_38 )
V_9 -> V_11 [ V_83 ] . V_42 = V_261 ;
else
V_260 [ V_83 ] = V_261 ;
}
if ( V_62 == V_207 )
V_9 -> V_267 = V_260 ;
F_6 ( & V_9 -> V_43 ) ;
V_9 -> V_37 |= V_62 ;
F_11 ( & V_9 -> V_43 ) ;
F_135 () ;
return 0 ;
V_270:
F_101 ( V_174 -> V_175 ) ;
V_269:
if ( V_253 ) {
F_101 ( V_253 -> V_174 -> V_175 ) ;
F_14 ( V_253 -> V_257 ) ;
F_14 ( V_253 ) ;
}
V_262 = V_83 ;
while ( V_262 -- > 0 ) {
if ( V_62 == V_38 )
F_136 ( V_9 -> V_11 [ V_262 ] . V_42 ) ;
else
F_136 ( V_260 [ V_262 ] ) ;
}
F_14 ( V_260 ) ;
V_164:
if ( ! ( V_9 -> V_37 & V_38 ) ) {
F_14 ( V_9 -> V_11 ) ;
V_9 -> V_11 = NULL ;
}
return V_230 ;
}
int F_137 ( struct V_79 * V_79 , int V_62 )
{
struct V_8 * V_9 = F_42 ( V_79 ) ;
struct V_259 * * V_260 ;
int V_83 ;
int V_163 = - V_156 ;
F_55 ( 7 , L_45 , V_263 , F_125 ( V_264 ) ) ;
if ( V_62 == V_38 ) {
if ( ! V_9 -> V_11 )
return - V_272 ;
F_6 ( & V_9 -> V_43 ) ;
F_18 ( & V_9 -> V_13 ) ;
V_9 -> V_37 &= ~ V_38 ;
F_24 ( & V_9 -> V_13 ) ;
F_11 ( & V_9 -> V_43 ) ;
V_163 = 0 ;
for ( V_83 = V_9 -> V_47 ; V_83 >= 0 ; V_83 -- ) {
struct V_10 * V_11 = & V_9 -> V_11 [ V_83 ] ;
int V_214 ;
F_114 ( L_49 ,
F_125 ( V_11 -> V_42 ) ) ;
F_138 ( & V_11 -> V_39 ) ;
V_214 = F_136 ( V_11 -> V_42 ) ;
if ( V_163 >= 0 )
V_163 = V_214 ;
}
F_14 ( V_9 -> V_11 ) ;
V_9 -> V_11 = NULL ;
} else if ( V_62 == V_207 ) {
if ( ! V_9 -> V_267 )
return - V_272 ;
V_9 -> V_37 &= ~ V_207 ;
V_260 = V_9 -> V_267 ;
V_163 = 0 ;
for ( V_83 = V_9 -> V_47 ; V_83 >= 0 ; V_83 -- ) {
int V_214 ;
F_114 ( L_50 ,
F_125 ( V_260 [ V_83 ] ) ) ;
V_214 = F_136 ( V_260 [ V_83 ] ) ;
if ( V_163 >= 0 )
V_163 = V_214 ;
}
F_14 ( V_260 ) ;
V_9 -> V_267 = NULL ;
}
F_139 () ;
return V_163 ;
}
int T_6 F_140 ( struct V_79 * V_79 )
{
struct V_8 * V_9 = F_42 ( V_79 ) ;
F_141 ( & V_9 -> V_273 , L_51 , & V_274 ) ;
F_142 ( & V_9 -> V_13 ) ;
F_142 ( & V_9 -> V_43 ) ;
return 0 ;
}
void F_143 ( struct V_79 * V_79 )
{
int V_163 ;
struct V_8 * V_9 = F_42 ( V_79 ) ;
F_144 ( & V_9 -> V_273 ) ;
V_163 = F_137 ( V_79 , V_38 ) ;
if ( V_163 && V_163 != - V_272 )
F_43 ( L_52 ) ;
V_163 = F_137 ( V_79 , V_207 ) ;
if ( V_163 && V_163 != - V_272 )
F_43 ( L_53 ) ;
F_145 ( & V_9 -> V_273 ) ;
}
