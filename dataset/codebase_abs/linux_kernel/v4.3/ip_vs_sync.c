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
F_12 ( struct V_8 * V_9 , unsigned int V_20 )
{
struct V_7 * V_12 ;
if ( ! ( V_12 = F_13 ( sizeof( struct V_7 ) , V_21 ) ) )
return NULL ;
V_20 = F_14 (unsigned int, len + sizeof(struct ip_vs_sync_mesg),
ipvs->mcfg.sync_maxlen) ;
V_12 -> V_22 = F_13 ( V_20 , V_21 ) ;
if ( ! V_12 -> V_22 ) {
F_15 ( V_12 ) ;
return NULL ;
}
V_12 -> V_22 -> V_23 = 0 ;
V_12 -> V_22 -> V_24 = V_25 ;
V_12 -> V_22 -> V_26 = V_9 -> V_27 . V_26 ;
V_12 -> V_22 -> V_28 = F_16 ( sizeof( struct V_29 ) ) ;
V_12 -> V_22 -> V_30 = 0 ;
V_12 -> V_22 -> V_31 = 0 ;
V_12 -> V_32 = ( unsigned char * ) V_12 -> V_22 + sizeof( struct V_29 ) ;
V_12 -> V_33 = ( unsigned char * ) V_12 -> V_22 + V_20 ;
V_12 -> V_34 = V_35 ;
return V_12 ;
}
static inline void F_17 ( struct V_7 * V_12 )
{
F_15 ( V_12 -> V_22 ) ;
F_15 ( V_12 ) ;
}
static inline void F_18 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
struct V_7 * V_12 = V_11 -> V_36 ;
F_19 ( & V_9 -> V_13 ) ;
if ( V_9 -> V_37 & V_38 &&
V_11 -> V_18 < F_20 ( V_9 ) ) {
if ( ! V_11 -> V_18 )
F_21 ( & V_11 -> V_39 ,
F_22 ( V_40 , 1 ) ) ;
V_11 -> V_18 ++ ;
F_23 ( & V_12 -> V_17 , & V_11 -> V_14 ) ;
if ( ( ++ V_11 -> V_19 ) == V_41 )
F_24 ( V_11 -> V_42 ) ;
} else
F_17 ( V_12 ) ;
F_25 ( & V_9 -> V_13 ) ;
}
static inline struct V_7 *
F_26 ( struct V_8 * V_9 , struct V_10 * V_11 ,
unsigned long time )
{
struct V_7 * V_12 ;
F_6 ( & V_9 -> V_43 ) ;
V_12 = V_11 -> V_36 ;
if ( V_12 && F_27 ( V_35 - V_12 -> V_34 , time ) ) {
V_11 -> V_36 = NULL ;
F_8 ( V_44 ) ;
} else
V_12 = NULL ;
F_11 ( & V_9 -> V_43 ) ;
return V_12 ;
}
static inline int
F_28 ( struct V_8 * V_9 , struct V_45 * V_46 )
{
return ( ( long ) V_46 >> ( 1 + F_29 ( sizeof( * V_46 ) ) ) ) & V_9 -> V_47 ;
}
static inline struct V_7 *
F_30 ( struct V_8 * V_9 , unsigned int V_20 )
{
struct V_7 * V_12 ;
struct V_48 * V_22 ;
if ( ! ( V_12 = F_13 ( sizeof( struct V_7 ) , V_21 ) ) )
return NULL ;
V_20 = F_14 (unsigned int, len + sizeof(struct ip_vs_sync_mesg_v0),
ipvs->mcfg.sync_maxlen) ;
V_12 -> V_22 = F_13 ( V_20 , V_21 ) ;
if ( ! V_12 -> V_22 ) {
F_15 ( V_12 ) ;
return NULL ;
}
V_22 = (struct V_48 * ) V_12 -> V_22 ;
V_22 -> V_30 = 0 ;
V_22 -> V_26 = V_9 -> V_27 . V_26 ;
V_22 -> V_28 = F_16 ( sizeof( struct V_48 ) ) ;
V_12 -> V_32 = ( unsigned char * ) V_22 + sizeof( struct V_48 ) ;
V_12 -> V_33 = ( unsigned char * ) V_22 + V_20 ;
V_12 -> V_34 = V_35 ;
return V_12 ;
}
static inline bool F_31 ( struct V_45 * V_46 )
{
for ( V_46 = V_46 -> V_49 ; V_46 ; V_46 = V_46 -> V_49 ) {
if ( V_46 -> V_50 & V_51 )
return true ;
}
return false ;
}
static int F_32 ( struct V_8 * V_9 ,
struct V_45 * V_46 , int V_52 )
{
unsigned long V_53 = F_33 ( V_46 -> V_54 ) ;
unsigned long V_55 = V_35 ;
unsigned long V_56 = ( V_55 + V_46 -> V_57 ) & ~ 3UL ;
unsigned int V_58 ;
int V_59 ;
int V_60 ;
if ( F_34 ( V_46 -> V_50 & V_51 ) )
V_60 = 0 ;
else if ( F_34 ( F_35 ( V_9 ) && F_31 ( V_46 ) ) )
return 0 ;
else if ( F_36 ( V_46 -> V_61 == V_62 ) ) {
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
} else if ( F_34 ( V_46 -> V_61 == V_71 ) ) {
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
V_58 = F_37 ( V_9 ) ;
if ( V_58 > 0 ) {
long V_77 = V_56 - V_53 ;
long V_78 = F_22 ( V_46 -> V_57 >> 1 , 10UL * V_79 ) ;
if ( abs ( V_77 ) < F_38 ( long , V_58 , V_78 ) ) {
int V_80 = V_53 & 3 ;
if ( V_80 >= F_39 ( V_9 ) )
return 0 ;
if ( F_40 ( V_55 , V_53 - V_46 -> V_57 +
( V_58 >> 3 ) ) )
return 0 ;
V_56 |= V_80 + 1 ;
}
}
V_59 = F_41 ( V_9 ) ;
if ( V_59 > 0 ) {
if ( ! ( V_46 -> V_50 & V_51 ) &&
V_52 % V_59 != F_42 ( V_9 ) )
return 0 ;
} else if ( V_58 <= 0 &&
V_52 != F_42 ( V_9 ) )
return 0 ;
V_70:
V_46 -> V_69 = V_46 -> V_63 ;
V_56 = F_43 ( & V_46 -> V_54 , V_53 , V_56 ) ;
return V_56 == V_53 || V_60 ;
}
static void F_44 ( struct V_81 * V_81 , struct V_45 * V_46 ,
int V_52 )
{
struct V_8 * V_9 = F_45 ( V_81 ) ;
struct V_48 * V_82 ;
struct F_44 * V_83 ;
struct V_7 * V_84 ;
struct V_10 * V_11 ;
int V_85 ;
unsigned int V_20 ;
if ( F_34 ( V_46 -> V_86 != V_87 ) )
return;
if ( V_46 -> V_50 & V_88 )
return;
if ( ! F_32 ( V_9 , V_46 , V_52 ) )
return;
F_6 ( & V_9 -> V_43 ) ;
if ( ! ( V_9 -> V_37 & V_38 ) ) {
F_11 ( & V_9 -> V_43 ) ;
return;
}
V_85 = F_28 ( V_9 , V_46 ) ;
V_11 = & V_9 -> V_11 [ V_85 ] ;
V_84 = V_11 -> V_36 ;
V_20 = ( V_46 -> V_50 & V_89 ) ? V_90 :
V_91 ;
if ( V_84 ) {
V_82 = (struct V_48 * ) V_84 -> V_22 ;
if ( V_84 -> V_32 + V_20 > V_84 -> V_33 || ! V_82 -> V_30 ) {
F_18 ( V_9 , V_11 ) ;
V_11 -> V_36 = NULL ;
V_84 = NULL ;
}
}
if ( ! V_84 ) {
V_84 = F_30 ( V_9 , V_20 ) ;
if ( ! V_84 ) {
F_11 ( & V_9 -> V_43 ) ;
F_46 ( L_1 ) ;
return;
}
V_11 -> V_36 = V_84 ;
}
V_82 = (struct V_48 * ) V_84 -> V_22 ;
V_83 = (struct F_44 * ) V_84 -> V_32 ;
V_83 -> V_23 = 0 ;
V_83 -> V_61 = V_46 -> V_61 ;
V_83 -> V_92 = V_46 -> V_92 ;
V_83 -> V_93 = V_46 -> V_93 ;
V_83 -> V_94 = V_46 -> V_94 ;
V_83 -> V_95 = V_46 -> V_95 . V_96 ;
V_83 -> V_97 = V_46 -> V_97 . V_96 ;
V_83 -> V_98 = V_46 -> V_98 . V_96 ;
V_83 -> V_50 = F_16 ( V_46 -> V_50 & ~ V_99 ) ;
V_83 -> V_63 = F_16 ( V_46 -> V_63 ) ;
if ( V_46 -> V_50 & V_89 ) {
struct V_100 * V_101 =
(struct V_100 * ) & V_83 [ 1 ] ;
memcpy ( V_101 , & V_46 -> V_102 , sizeof( * V_101 ) ) ;
}
V_82 -> V_30 ++ ;
V_82 -> V_28 = F_16 ( F_47 ( V_82 -> V_28 ) + V_20 ) ;
V_84 -> V_32 += V_20 ;
F_11 ( & V_9 -> V_43 ) ;
V_46 = V_46 -> V_49 ;
if ( V_46 ) {
if ( V_46 -> V_50 & V_51 )
V_52 = F_48 ( 1 , & V_46 -> V_103 ) ;
else
V_52 = F_42 ( V_9 ) ;
F_49 ( V_81 , V_46 , V_52 ) ;
}
}
void F_49 ( struct V_81 * V_81 , struct V_45 * V_46 , int V_52 )
{
struct V_8 * V_9 = F_45 ( V_81 ) ;
struct V_29 * V_82 ;
union F_49 * V_83 ;
struct V_7 * V_84 ;
struct V_10 * V_11 ;
int V_85 ;
T_1 * V_104 ;
unsigned int V_20 , V_105 , V_106 ;
if ( F_50 ( V_9 ) == 0 ) {
F_44 ( V_81 , V_46 , V_52 ) ;
return;
}
if ( V_46 -> V_50 & V_88 )
goto V_49;
V_107:
if ( ! F_32 ( V_9 , V_46 , V_52 ) )
goto V_49;
V_105 = 0 ;
if ( V_46 -> V_108 ) {
if ( ! V_46 -> V_109 || ! V_46 -> V_110 ) {
F_51 ( L_2 ) ;
return;
}
V_105 = F_52 ( V_46 -> V_111 -> V_112 , V_113 ) ;
}
F_6 ( & V_9 -> V_43 ) ;
if ( ! ( V_9 -> V_37 & V_38 ) ) {
F_11 ( & V_9 -> V_43 ) ;
return;
}
V_85 = F_28 ( V_9 , V_46 ) ;
V_11 = & V_9 -> V_11 [ V_85 ] ;
#ifdef F_53
if ( V_46 -> V_86 == V_114 )
V_20 = sizeof( struct V_115 ) ;
else
#endif
V_20 = sizeof( struct V_116 ) ;
if ( V_46 -> V_50 & V_89 )
V_20 += sizeof( struct V_100 ) + 2 ;
if ( V_46 -> V_108 )
V_20 += V_46 -> V_108 + 2 ;
if ( V_105 )
V_20 += V_105 + 2 ;
V_106 = 0 ;
V_84 = V_11 -> V_36 ;
if ( V_84 ) {
V_82 = V_84 -> V_22 ;
V_106 = ( 4 - ( V_117 ) V_84 -> V_32 ) & 3 ;
if ( V_84 -> V_32 + V_20 + V_106 > V_84 -> V_33 || V_82 -> V_23 ) {
F_18 ( V_9 , V_11 ) ;
V_11 -> V_36 = NULL ;
V_84 = NULL ;
V_106 = 0 ;
}
}
if ( ! V_84 ) {
V_84 = F_12 ( V_9 , V_20 ) ;
if ( ! V_84 ) {
F_11 ( & V_9 -> V_43 ) ;
F_46 ( L_1 ) ;
return;
}
V_11 -> V_36 = V_84 ;
V_82 = V_84 -> V_22 ;
}
V_104 = V_84 -> V_32 ;
V_84 -> V_32 += V_106 + V_20 ;
V_82 -> V_28 = F_16 ( F_47 ( V_82 -> V_28 ) + V_106 + V_20 ) ;
while ( V_106 -- )
* ( V_104 ++ ) = 0 ;
V_83 = (union F_49 * ) V_104 ;
V_83 -> V_118 . type = ( V_46 -> V_86 == V_114 ? V_119 : 0 ) ;
V_83 -> V_118 . V_120 = F_16 ( V_20 & V_121 ) ;
V_83 -> V_118 . V_50 = F_54 ( V_46 -> V_50 & ~ V_99 ) ;
V_83 -> V_118 . V_63 = F_16 ( V_46 -> V_63 ) ;
V_83 -> V_118 . V_61 = V_46 -> V_61 ;
V_83 -> V_118 . V_92 = V_46 -> V_92 ;
V_83 -> V_118 . V_93 = V_46 -> V_93 ;
V_83 -> V_118 . V_94 = V_46 -> V_94 ;
V_83 -> V_118 . V_122 = F_54 ( V_46 -> V_122 ) ;
V_83 -> V_118 . V_57 = F_54 ( V_46 -> V_57 / V_79 ) ;
V_82 -> V_30 ++ ;
#ifdef F_53
if ( V_46 -> V_86 == V_114 ) {
V_104 += sizeof( struct V_115 ) ;
V_83 -> V_123 . V_95 = V_46 -> V_95 . V_124 ;
V_83 -> V_123 . V_97 = V_46 -> V_97 . V_124 ;
V_83 -> V_123 . V_98 = V_46 -> V_98 . V_124 ;
} else
#endif
{
V_104 += sizeof( struct V_116 ) ;
V_83 -> V_118 . V_95 = V_46 -> V_95 . V_96 ;
V_83 -> V_118 . V_97 = V_46 -> V_97 . V_96 ;
V_83 -> V_118 . V_98 = V_46 -> V_98 . V_96 ;
}
if ( V_46 -> V_50 & V_89 ) {
* ( V_104 ++ ) = V_125 ;
* ( V_104 ++ ) = sizeof( struct V_100 ) ;
F_3 ( (struct V_1 * ) V_104 , & V_46 -> V_102 ) ;
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
V_49:
V_46 = V_46 -> V_49 ;
if ( ! V_46 )
return;
if ( V_46 -> V_50 & V_51 )
V_52 = F_48 ( 1 , & V_46 -> V_103 ) ;
else
V_52 = F_42 ( V_9 ) ;
goto V_107;
}
static inline int
F_55 ( struct V_81 * V_81 , int V_86 , union F_49 * V_129 ,
struct V_130 * V_104 ,
T_1 * V_109 , unsigned int V_108 ,
T_1 * V_131 , unsigned int V_105 )
{
#ifdef F_53
if ( V_86 == V_114 )
F_56 ( V_81 , V_86 , V_129 -> V_123 . V_61 ,
( const union V_132 * ) & V_129 -> V_123 . V_95 ,
V_129 -> V_123 . V_92 ,
( const union V_132 * ) & V_129 -> V_123 . V_97 ,
V_129 -> V_123 . V_93 , V_104 ) ;
else
#endif
F_56 ( V_81 , V_86 , V_129 -> V_118 . V_61 ,
( const union V_132 * ) & V_129 -> V_118 . V_95 ,
V_129 -> V_118 . V_92 ,
( const union V_132 * ) & V_129 -> V_118 . V_97 ,
V_129 -> V_118 . V_93 , V_104 ) ;
if ( V_108 ) {
if ( V_105 ) {
char V_84 [ V_113 + 1 ] ;
memcpy ( V_84 , V_131 , V_105 ) ;
V_84 [ V_105 ] = 0 ;
V_104 -> V_111 = F_57 ( V_84 ) ;
if ( ! V_104 -> V_111 ) {
F_58 ( 3 , L_3 ,
V_84 ) ;
return 1 ;
}
} else {
F_51 ( L_4 ) ;
return 1 ;
}
V_104 -> V_109 = F_59 ( V_109 , V_108 , V_21 ) ;
if ( ! V_104 -> V_109 ) {
F_60 ( V_104 -> V_111 -> V_133 ) ;
return - V_134 ;
}
V_104 -> V_108 = V_108 ;
}
return 0 ;
}
static void F_61 ( struct V_81 * V_81 , struct V_130 * V_135 ,
unsigned int V_50 , unsigned int V_63 ,
unsigned int V_61 , unsigned int type ,
const union V_132 * V_98 , T_2 V_94 ,
unsigned long V_57 , T_3 V_122 ,
struct V_100 * V_101 )
{
struct V_136 * V_110 ;
struct V_45 * V_46 ;
struct V_8 * V_9 = F_45 ( V_81 ) ;
if ( ! ( V_50 & V_51 ) ) {
V_46 = F_62 ( V_135 ) ;
if ( V_46 && ( ( V_46 -> V_94 != V_94 ) ||
! F_63 ( V_46 -> V_137 , & V_46 -> V_98 , V_98 ) ) ) {
if ( ! ( V_50 & V_138 ) ) {
F_64 ( V_46 ) ;
F_65 ( V_46 ) ;
V_46 = NULL ;
} else {
F_65 ( V_46 ) ;
F_15 ( V_135 -> V_109 ) ;
return;
}
}
} else {
V_46 = F_66 ( V_135 ) ;
}
if ( V_46 ) {
F_15 ( V_135 -> V_109 ) ;
V_110 = V_46 -> V_110 ;
F_6 ( & V_46 -> V_139 ) ;
if ( ( V_46 -> V_50 ^ V_50 ) & V_138 &&
! ( V_50 & V_51 ) && V_110 ) {
if ( V_50 & V_138 ) {
F_67 ( & V_110 -> V_140 ) ;
F_68 ( & V_110 -> V_141 ) ;
} else {
F_68 ( & V_110 -> V_140 ) ;
F_67 ( & V_110 -> V_141 ) ;
}
}
V_50 &= V_142 ;
V_50 |= V_46 -> V_50 & ~ V_142 ;
V_46 -> V_50 = V_50 ;
F_11 ( & V_46 -> V_139 ) ;
if ( ! V_110 )
F_69 ( V_46 ) ;
} else {
F_70 () ;
V_110 = F_71 ( V_81 , type , type , V_98 , V_94 ,
V_135 -> V_97 , V_135 -> V_93 , V_61 ,
V_122 , V_50 ) ;
V_46 = F_72 ( V_135 , type , V_98 , V_94 , V_50 , V_110 ,
V_122 ) ;
F_73 () ;
if ( ! V_46 ) {
F_15 ( V_135 -> V_109 ) ;
F_58 ( 2 , L_5 ) ;
return;
}
if ( ! ( V_50 & V_51 ) )
F_15 ( V_135 -> V_109 ) ;
}
if ( V_101 )
memcpy ( & V_46 -> V_102 , V_101 , sizeof( * V_101 ) ) ;
F_74 ( & V_46 -> V_103 , F_42 ( V_9 ) ) ;
V_46 -> V_63 = V_63 ;
V_46 -> V_69 = V_46 -> V_63 ;
if ( V_57 ) {
if ( V_57 > V_143 / V_79 )
V_57 = V_143 / V_79 ;
V_46 -> V_57 = V_57 * V_79 ;
} else {
struct V_144 * V_145 ;
V_145 = F_75 ( V_81 , V_61 ) ;
if ( ! ( V_50 & V_51 ) && V_145 && V_145 -> V_146 )
V_46 -> V_57 = V_145 -> V_146 [ V_63 ] ;
else
V_46 -> V_57 = ( 3 * 60 * V_79 ) ;
}
F_76 ( V_46 ) ;
}
static void F_77 ( struct V_81 * V_81 , const char * V_147 ,
const V_117 V_148 )
{
struct V_48 * V_82 = (struct V_48 * ) V_147 ;
struct F_44 * V_83 ;
struct V_100 * V_101 ;
struct V_149 * V_150 ;
struct V_130 V_135 ;
char * V_104 ;
int V_151 ;
V_104 = ( char * ) V_147 + sizeof( struct V_48 ) ;
for ( V_151 = 0 ; V_151 < V_82 -> V_30 ; V_151 ++ ) {
unsigned int V_50 , V_63 ;
if ( V_104 + V_91 > V_147 + V_148 ) {
F_51 ( L_6 ) ;
return;
}
V_83 = (struct F_44 * ) V_104 ;
V_50 = F_47 ( V_83 -> V_50 ) | V_152 ;
V_50 &= ~ V_99 ;
if ( V_50 & V_89 ) {
V_101 = (struct V_100 * ) & V_83 [ 1 ] ;
V_104 += V_90 ;
if ( V_104 > V_147 + V_148 ) {
F_51 ( L_7 ) ;
return;
}
} else {
V_101 = NULL ;
V_104 += V_91 ;
}
V_63 = F_47 ( V_83 -> V_63 ) ;
if ( ! ( V_50 & V_51 ) ) {
V_150 = F_78 ( V_83 -> V_61 ) ;
if ( ! V_150 ) {
F_58 ( 2 , L_8 ,
V_83 -> V_61 ) ;
continue;
}
if ( V_63 >= V_150 -> V_153 ) {
F_58 ( 2 , L_9 ,
V_150 -> V_112 , V_63 ) ;
continue;
}
} else {
if ( V_63 > 0 ) {
F_58 ( 2 , L_10 ,
V_63 ) ;
V_63 = 0 ;
}
}
F_56 ( V_81 , V_87 , V_83 -> V_61 ,
( const union V_132 * ) & V_83 -> V_95 ,
V_83 -> V_92 ,
( const union V_132 * ) & V_83 -> V_97 ,
V_83 -> V_93 , & V_135 ) ;
F_61 ( V_81 , & V_135 , V_50 , V_63 , V_83 -> V_61 , V_87 ,
(union V_132 * ) & V_83 -> V_98 , V_83 -> V_94 ,
0 , 0 , V_101 ) ;
}
}
static inline int F_79 ( T_1 * V_104 , unsigned int V_154 ,
T_3 * V_155 ,
struct V_100 * V_101 )
{
struct V_100 * V_156 ;
V_156 = (struct V_100 * ) V_104 ;
if ( V_154 != sizeof( struct V_100 ) ) {
F_58 ( 2 , L_11 ) ;
return - V_157 ;
}
if ( * V_155 & V_158 ) {
F_58 ( 2 , L_12 ) ;
return - V_157 ;
}
F_1 ( & V_156 -> V_102 , & V_101 -> V_102 ) ;
F_1 ( & V_156 -> V_126 , & V_101 -> V_126 ) ;
* V_155 |= V_158 ;
return 0 ;
}
static int F_80 ( T_1 * V_104 , unsigned int V_154 , unsigned int * V_159 ,
T_1 * * V_160 , unsigned int V_161 ,
T_3 * V_155 , T_3 V_162 )
{
if ( V_154 > V_161 ) {
F_58 ( 2 , L_13 , V_161 ) ;
return - V_157 ;
}
if ( * V_155 & V_162 ) {
F_58 ( 2 , L_14 , V_162 ) ;
return - V_157 ;
}
* V_159 = V_154 ;
* V_160 = V_104 ;
* V_155 |= V_162 ;
return 0 ;
}
static inline int F_81 ( struct V_81 * V_81 , T_1 * V_104 , T_1 * V_163 )
{
struct V_100 V_101 ;
union F_49 * V_83 ;
struct V_149 * V_150 ;
struct V_130 V_135 ;
T_3 V_50 ;
unsigned int V_86 , V_63 , V_108 = 0 , V_105 = 0 ;
T_1 * V_109 = NULL , * V_131 = NULL ;
T_3 V_155 = 0 ;
int V_164 = 0 ;
V_83 = (union F_49 * ) V_104 ;
if ( V_83 -> V_123 . type & V_119 ) {
#ifdef F_53
V_86 = V_114 ;
V_104 += sizeof( struct V_115 ) ;
#else
F_58 ( 3 , L_15 ) ;
V_164 = 10 ;
goto V_165;
#endif
} else if ( ! V_83 -> V_118 . type ) {
V_86 = V_87 ;
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
if ( F_79 ( V_104 , V_154 , & V_155 , & V_101 ) )
return - 50 ;
break;
case V_127 :
if ( F_80 ( V_104 , V_154 , & V_108 , & V_109 ,
V_168 , & V_155 ,
V_169 ) )
return - 60 ;
break;
case V_128 :
if ( F_80 ( V_104 , V_154 , & V_105 , & V_131 ,
V_113 , & V_155 ,
V_170 ) )
return - 70 ;
break;
default:
if ( ! ( V_166 & V_167 ) ) {
F_58 ( 3 , L_16 ,
V_166 & ~ V_167 ) ;
V_164 = 20 ;
goto V_165;
}
}
V_104 += V_154 ;
}
V_50 = F_82 ( V_83 -> V_118 . V_50 ) & V_171 ;
V_50 |= V_152 ;
V_63 = F_47 ( V_83 -> V_118 . V_63 ) ;
if ( ! ( V_50 & V_51 ) ) {
V_150 = F_78 ( V_83 -> V_118 . V_61 ) ;
if ( ! V_150 ) {
F_58 ( 3 , L_17 ,
V_83 -> V_118 . V_61 ) ;
V_164 = 30 ;
goto V_165;
}
if ( V_63 >= V_150 -> V_153 ) {
F_58 ( 3 , L_18 ,
V_150 -> V_112 , V_63 ) ;
V_164 = 40 ;
goto V_165;
}
} else {
if ( V_63 > 0 ) {
F_58 ( 3 , L_19 ,
V_63 ) ;
V_63 = 0 ;
}
}
if ( F_55 ( V_81 , V_86 , V_83 , & V_135 , V_109 ,
V_108 , V_131 , V_105 ) ) {
V_164 = 50 ;
goto V_165;
}
if ( V_86 == V_87 )
F_61 ( V_81 , & V_135 , V_50 , V_63 , V_83 -> V_118 . V_61 , V_86 ,
(union V_132 * ) & V_83 -> V_118 . V_98 , V_83 -> V_118 . V_94 ,
F_82 ( V_83 -> V_118 . V_57 ) , F_82 ( V_83 -> V_118 . V_122 ) ,
( V_155 & V_158 ? & V_101 : NULL )
) ;
#ifdef F_53
else
F_61 ( V_81 , & V_135 , V_50 , V_63 , V_83 -> V_123 . V_61 , V_86 ,
(union V_132 * ) & V_83 -> V_123 . V_98 , V_83 -> V_123 . V_94 ,
F_82 ( V_83 -> V_123 . V_57 ) , F_82 ( V_83 -> V_123 . V_122 ) ,
( V_155 & V_158 ? & V_101 : NULL )
) ;
#endif
F_83 ( V_135 . V_111 ) ;
return 0 ;
V_165:
F_58 ( 2 , L_20 , V_164 ) ;
return V_164 ;
}
static void F_84 ( struct V_81 * V_81 , T_1 * V_147 ,
const V_117 V_148 )
{
struct V_8 * V_9 = F_45 ( V_81 ) ;
struct V_29 * V_172 = (struct V_29 * ) V_147 ;
T_1 * V_104 , * V_163 ;
int V_151 , V_30 ;
if ( V_148 < sizeof( struct V_48 ) ) {
F_58 ( 2 , L_21 ) ;
return;
}
if ( V_148 != F_47 ( V_172 -> V_28 ) ) {
F_58 ( 2 , L_22 ) ;
return;
}
if ( V_9 -> V_173 . V_26 != 0 && V_172 -> V_26 != V_9 -> V_173 . V_26 ) {
F_58 ( 7 , L_23 , V_172 -> V_26 ) ;
return;
}
if ( ( V_172 -> V_24 == V_25 ) && ( V_172 -> V_23 == 0 )
&& ( V_172 -> V_31 == 0 ) ) {
V_163 = V_147 + sizeof( struct V_29 ) ;
V_30 = V_172 -> V_30 ;
for ( V_151 = 0 ; V_151 < V_30 ; V_151 ++ ) {
union F_49 * V_83 ;
unsigned int V_28 ;
int V_164 ;
V_104 = V_163 ;
if ( V_104 + sizeof( V_83 -> V_118 ) > V_147 + V_148 ) {
F_51 ( L_24 ) ;
return;
}
V_83 = (union F_49 * ) V_104 ;
V_28 = F_47 ( V_83 -> V_118 . V_120 ) & V_121 ;
V_163 = V_104 + V_28 ;
if ( V_163 > V_147 + V_148 ) {
F_51 ( L_25 ) ;
return;
}
if ( F_47 ( V_83 -> V_118 . V_120 ) >> V_174 ) {
F_51 ( L_26 ,
F_47 ( V_83 -> V_118 . V_120 ) >> V_174 ) ;
return;
}
V_164 = F_81 ( V_81 , V_104 , V_163 ) ;
if ( V_164 < 0 ) {
F_51 ( L_27 ,
V_164 ) ;
return;
}
V_163 = V_104 + ( ( V_28 + 3 ) & ~ 3 ) ;
}
} else {
F_77 ( V_81 , V_147 , V_148 ) ;
return;
}
}
static void F_85 ( struct V_175 * V_176 , int V_177 , int V_178 )
{
F_86 ( V_176 ) ;
if ( V_177 ) {
V_178 = F_87 ( int , V_178 , ( V_179 + 1 ) / 2 ,
V_180 ) ;
V_176 -> V_181 = V_178 * 2 ;
V_176 -> V_182 |= V_183 ;
} else {
V_178 = F_87 ( int , V_178 , ( V_184 + 1 ) / 2 ,
V_185 ) ;
V_176 -> V_186 = V_178 * 2 ;
V_176 -> V_182 |= V_187 ;
}
F_88 ( V_176 ) ;
}
static void F_89 ( struct V_175 * V_176 , T_4 V_188 )
{
struct V_189 * V_190 = F_90 ( V_176 ) ;
F_86 ( V_176 ) ;
V_190 -> V_191 = V_188 ? 1 : 0 ;
#ifdef F_53
if ( V_176 -> V_192 == V_114 ) {
struct V_193 * V_194 = F_91 ( V_176 ) ;
V_194 -> V_191 = V_188 ? 1 : 0 ;
}
#endif
F_88 ( V_176 ) ;
}
static void F_92 ( struct V_175 * V_176 , T_4 V_195 )
{
struct V_189 * V_190 = F_90 ( V_176 ) ;
F_86 ( V_176 ) ;
V_190 -> V_196 = V_195 ;
#ifdef F_53
if ( V_176 -> V_192 == V_114 ) {
struct V_193 * V_194 = F_91 ( V_176 ) ;
V_194 -> V_197 = V_195 ;
}
#endif
F_88 ( V_176 ) ;
}
static void F_93 ( struct V_175 * V_176 , int V_178 )
{
struct V_189 * V_190 = F_90 ( V_176 ) ;
F_86 ( V_176 ) ;
V_190 -> V_198 = V_178 ;
#ifdef F_53
if ( V_176 -> V_192 == V_114 ) {
struct V_193 * V_194 = F_91 ( V_176 ) ;
V_194 -> V_198 = V_178 ;
}
#endif
F_88 ( V_176 ) ;
}
static int F_94 ( struct V_175 * V_176 , char * V_199 )
{
struct V_200 * V_201 ;
struct V_189 * V_190 = F_90 ( V_176 ) ;
struct V_81 * V_81 = F_95 ( V_176 ) ;
V_201 = F_96 ( V_81 , V_199 ) ;
if ( ! V_201 )
return - V_202 ;
if ( V_176 -> V_203 && V_201 -> V_204 != V_176 -> V_203 )
return - V_157 ;
F_86 ( V_176 ) ;
V_190 -> V_205 = V_201 -> V_204 ;
#ifdef F_53
if ( V_176 -> V_192 == V_114 ) {
struct V_193 * V_194 = F_91 ( V_176 ) ;
V_194 -> V_206 = V_201 -> V_204 ;
}
#endif
F_88 ( V_176 ) ;
return 0 ;
}
static int
F_97 ( struct V_175 * V_176 , struct V_207 * V_208 , char * V_199 )
{
struct V_81 * V_81 = F_95 ( V_176 ) ;
struct V_209 V_210 ;
struct V_200 * V_201 ;
int V_211 ;
memset ( & V_210 , 0 , sizeof( V_210 ) ) ;
memcpy ( & V_210 . V_212 , V_208 , sizeof( struct V_207 ) ) ;
V_201 = F_96 ( V_81 , V_199 ) ;
if ( ! V_201 )
return - V_202 ;
if ( V_176 -> V_203 && V_201 -> V_204 != V_176 -> V_203 )
return - V_157 ;
V_210 . V_213 = V_201 -> V_204 ;
F_86 ( V_176 ) ;
V_211 = F_98 ( V_176 , & V_210 ) ;
F_88 ( V_176 ) ;
return V_211 ;
}
static int F_99 ( struct V_175 * V_176 , struct V_214 * V_208 ,
char * V_199 )
{
struct V_81 * V_81 = F_95 ( V_176 ) ;
struct V_200 * V_201 ;
int V_211 ;
V_201 = F_96 ( V_81 , V_199 ) ;
if ( ! V_201 )
return - V_202 ;
if ( V_176 -> V_203 && V_201 -> V_204 != V_176 -> V_203 )
return - V_157 ;
F_86 ( V_176 ) ;
V_211 = F_100 ( V_176 , V_201 -> V_204 , V_208 ) ;
F_88 ( V_176 ) ;
return V_211 ;
}
static int F_101 ( struct V_215 * V_175 , char * V_199 )
{
struct V_81 * V_81 = F_95 ( V_175 -> V_176 ) ;
struct V_200 * V_201 ;
T_5 V_208 ;
struct V_216 sin ;
V_201 = F_96 ( V_81 , V_199 ) ;
if ( ! V_201 )
return - V_202 ;
V_208 = F_102 ( V_201 , 0 , V_217 ) ;
if ( ! V_208 )
F_46 ( L_28
L_29 ) ;
F_58 ( 7 , L_30 ,
V_199 , & V_208 ) ;
sin . V_218 = V_87 ;
sin . V_219 . V_220 = V_208 ;
sin . V_221 = 0 ;
return V_175 -> V_222 -> V_223 ( V_175 , (struct V_224 * ) & sin , sizeof( sin ) ) ;
}
static void F_103 ( union V_225 * V_226 , int * V_227 ,
struct V_228 * V_229 , int V_85 )
{
if ( V_114 == V_229 -> V_230 ) {
V_226 -> V_124 = (struct V_231 ) {
. V_232 = V_114 ,
. V_233 = F_16 ( V_229 -> V_234 + V_85 ) ,
} ;
V_226 -> V_124 . V_235 = V_229 -> V_236 . V_124 ;
* V_227 = sizeof( V_226 -> V_124 ) ;
} else {
V_226 -> V_237 = (struct V_216 ) {
. V_218 = V_87 ,
. V_221 = F_16 ( V_229 -> V_234 + V_85 ) ,
} ;
V_226 -> V_237 . V_219 = V_229 -> V_236 . V_237 ;
* V_227 = sizeof( V_226 -> V_237 ) ;
}
}
static struct V_215 * F_104 ( struct V_81 * V_81 , int V_85 )
{
struct V_8 * V_9 = F_45 ( V_81 ) ;
union V_225 V_238 ;
struct V_215 * V_175 ;
int V_239 , V_227 ;
V_239 = F_105 ( V_81 , V_9 -> V_27 . V_230 , V_240 ,
V_241 , & V_175 ) ;
if ( V_239 < 0 ) {
F_46 ( L_31 ) ;
return F_106 ( V_239 ) ;
}
V_239 = F_94 ( V_175 -> V_176 , V_9 -> V_27 . V_242 ) ;
if ( V_239 < 0 ) {
F_46 ( L_32 ) ;
goto error;
}
F_89 ( V_175 -> V_176 , 0 ) ;
F_92 ( V_175 -> V_176 , V_9 -> V_27 . V_243 ) ;
F_93 ( V_175 -> V_176 , V_244 ) ;
V_239 = F_107 ( V_9 ) ;
if ( V_239 > 0 )
F_85 ( V_175 -> V_176 , 1 , V_239 ) ;
if ( V_87 == V_9 -> V_27 . V_230 )
V_239 = F_101 ( V_175 , V_9 -> V_27 . V_242 ) ;
else
V_239 = 0 ;
if ( V_239 < 0 ) {
F_46 ( L_33 ) ;
goto error;
}
F_103 ( & V_238 , & V_227 , & V_9 -> V_27 , V_85 ) ;
V_239 = V_175 -> V_222 -> V_245 ( V_175 , (struct V_224 * ) & V_238 ,
V_227 , 0 ) ;
if ( V_239 < 0 ) {
F_46 ( L_34 ) ;
goto error;
}
return V_175 ;
error:
F_108 ( V_175 ) ;
return F_106 ( V_239 ) ;
}
static struct V_215 * F_109 ( struct V_81 * V_81 , int V_85 )
{
struct V_8 * V_9 = F_45 ( V_81 ) ;
union V_225 V_238 ;
struct V_215 * V_175 ;
int V_239 , V_227 ;
V_239 = F_105 ( V_81 , V_9 -> V_173 . V_230 , V_240 ,
V_241 , & V_175 ) ;
if ( V_239 < 0 ) {
F_46 ( L_31 ) ;
return F_106 ( V_239 ) ;
}
V_175 -> V_176 -> V_246 = V_247 ;
V_239 = F_107 ( V_9 ) ;
if ( V_239 > 0 )
F_85 ( V_175 -> V_176 , 0 , V_239 ) ;
F_103 ( & V_238 , & V_227 , & V_9 -> V_173 , V_85 ) ;
V_239 = V_175 -> V_222 -> V_223 ( V_175 , (struct V_224 * ) & V_238 , V_227 ) ;
if ( V_239 < 0 ) {
F_46 ( L_35 ) ;
goto error;
}
#ifdef F_53
if ( V_9 -> V_173 . V_230 == V_114 )
V_239 = F_99 ( V_175 -> V_176 , & V_238 . V_124 . V_235 ,
V_9 -> V_173 . V_242 ) ;
else
#endif
V_239 = F_97 ( V_175 -> V_176 , & V_238 . V_237 . V_219 ,
V_9 -> V_173 . V_242 ) ;
if ( V_239 < 0 ) {
F_46 ( L_36 ) ;
goto error;
}
return V_175 ;
error:
F_108 ( V_175 ) ;
return F_106 ( V_239 ) ;
}
static int
F_110 ( struct V_215 * V_175 , const char * V_147 , const V_117 V_248 )
{
struct V_249 V_250 = { . V_251 = V_252 | V_253 } ;
struct V_254 V_255 ;
int V_20 ;
F_111 ( 7 ) ;
V_255 . V_256 = ( void * ) V_147 ;
V_255 . V_257 = V_248 ;
V_20 = F_112 ( V_175 , & V_250 , & V_255 , 1 , ( V_117 ) ( V_248 ) ) ;
F_113 ( 7 ) ;
return V_20 ;
}
static int
F_114 ( struct V_215 * V_175 , struct V_29 * V_250 )
{
int V_258 ;
int V_211 ;
V_258 = F_47 ( V_250 -> V_28 ) ;
V_211 = F_110 ( V_175 , ( char * ) V_250 , V_258 ) ;
if ( V_211 >= 0 || V_211 == - V_259 )
return V_211 ;
F_46 ( L_37 , V_211 ) ;
return 0 ;
}
static int
F_115 ( struct V_215 * V_175 , char * V_147 , const V_117 V_148 )
{
struct V_249 V_250 = { NULL ,} ;
struct V_254 V_255 ;
int V_20 ;
F_111 ( 7 ) ;
V_255 . V_256 = V_147 ;
V_255 . V_257 = ( V_117 ) V_148 ;
V_20 = F_116 ( V_175 , & V_250 , & V_255 , 1 , V_148 , V_252 ) ;
if ( V_20 < 0 )
return V_20 ;
F_113 ( 7 ) ;
return V_20 ;
}
static void F_117 ( struct V_260 * V_261 )
{
struct V_10 * V_11 =
F_118 ( V_261 , struct V_10 ,
V_39 . V_261 ) ;
struct V_8 * V_9 = V_11 -> V_9 ;
F_6 ( & V_9 -> V_13 ) ;
if ( V_11 -> V_18 &&
V_11 -> V_19 < V_41 ) {
V_11 -> V_19 = V_41 ;
F_24 ( V_11 -> V_42 ) ;
}
F_11 ( & V_9 -> V_13 ) ;
}
static inline struct V_7 *
F_119 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
struct V_7 * V_12 ;
V_12 = F_5 ( V_9 , V_11 ) ;
if ( V_12 )
return V_12 ;
return F_26 ( V_9 , V_11 , V_262 ) ;
}
static int F_120 ( void * V_160 )
{
struct V_263 * V_264 = V_160 ;
struct V_8 * V_9 = F_45 ( V_264 -> V_81 ) ;
struct V_10 * V_11 = & V_9 -> V_11 [ V_264 -> V_85 ] ;
struct V_175 * V_176 = V_264 -> V_175 -> V_176 ;
struct V_7 * V_12 ;
F_121 ( L_38
L_39 ,
V_9 -> V_27 . V_242 , V_9 -> V_27 . V_26 , V_264 -> V_85 ) ;
for (; ; ) {
V_12 = F_119 ( V_9 , V_11 ) ;
if ( F_34 ( F_122 () ) )
break;
if ( ! V_12 ) {
F_123 ( V_265 ) ;
continue;
}
while ( F_114 ( V_264 -> V_175 , V_12 -> V_22 ) < 0 ) {
F_124 ( * F_125 ( V_176 ) ,
F_126 ( V_176 ) ||
F_122 () ) ;
if ( F_34 ( F_122 () ) )
goto V_266;
}
F_17 ( V_12 ) ;
}
V_266:
F_8 ( V_44 ) ;
if ( V_12 )
F_17 ( V_12 ) ;
while ( ( V_12 = F_5 ( V_9 , V_11 ) ) )
F_17 ( V_12 ) ;
F_8 ( V_44 ) ;
V_12 = F_26 ( V_9 , V_11 , 0 ) ;
if ( V_12 )
F_17 ( V_12 ) ;
F_108 ( V_264 -> V_175 ) ;
F_15 ( V_264 ) ;
return 0 ;
}
static int F_127 ( void * V_160 )
{
struct V_263 * V_264 = V_160 ;
struct V_8 * V_9 = F_45 ( V_264 -> V_81 ) ;
int V_20 ;
F_121 ( L_40
L_39 ,
V_9 -> V_173 . V_242 , V_9 -> V_173 . V_26 , V_264 -> V_85 ) ;
while ( ! F_122 () ) {
F_128 ( * F_125 ( V_264 -> V_175 -> V_176 ) ,
! F_129 ( & V_264 -> V_175 -> V_176 -> V_267 )
|| F_122 () ) ;
while ( ! F_129 ( & ( V_264 -> V_175 -> V_176 -> V_267 ) ) ) {
V_20 = F_115 ( V_264 -> V_175 , V_264 -> V_268 ,
V_9 -> V_173 . V_269 ) ;
if ( V_20 <= 0 ) {
if ( V_20 != - V_259 )
F_46 ( L_41 ) ;
break;
}
F_84 ( V_264 -> V_81 , V_264 -> V_268 , V_20 ) ;
}
}
F_108 ( V_264 -> V_175 ) ;
F_15 ( V_264 -> V_268 ) ;
F_15 ( V_264 ) ;
return 0 ;
}
int F_130 ( struct V_81 * V_81 , struct V_228 * V_229 ,
int V_63 )
{
struct V_263 * V_264 ;
struct V_270 * * V_271 = NULL , * V_272 ;
struct V_215 * V_175 ;
struct V_8 * V_9 = F_45 ( V_81 ) ;
struct V_200 * V_201 ;
char * V_112 ;
int (* F_131)( void * V_160 );
int V_85 , V_273 , V_274 ;
int V_239 = - V_134 ;
T_6 V_275 , V_276 ;
F_58 ( 7 , L_42 , V_277 , F_132 ( V_278 ) ) ;
F_58 ( 7 , L_43 ,
sizeof( struct F_44 ) ) ;
if ( ! V_9 -> V_37 ) {
V_273 = F_133 ( F_134 ( V_9 ) , 1 , V_279 ) ;
V_9 -> V_47 = V_273 - 1 ;
} else
V_273 = V_9 -> V_47 + 1 ;
if ( V_229 -> V_230 == V_280 ) {
V_229 -> V_230 = V_87 ;
V_229 -> V_236 . V_96 = F_135 ( V_281 ) ;
}
if ( ! V_229 -> V_234 )
V_229 -> V_234 = V_282 ;
if ( ! V_229 -> V_243 )
V_229 -> V_243 = 1 ;
V_201 = F_96 ( V_81 , V_229 -> V_242 ) ;
if ( ! V_201 ) {
F_46 ( L_44 , V_229 -> V_242 ) ;
return - V_202 ;
}
V_274 = ( V_114 == V_229 -> V_230 ) ?
sizeof( struct V_283 ) + sizeof( struct V_284 ) :
sizeof( struct V_285 ) + sizeof( struct V_284 ) ;
V_275 = ( V_63 == V_286 ) ?
F_133 ( V_201 -> V_275 , 1500U , 65535U ) : 1500U ;
V_276 = ( V_63 == V_286 ) ? 1024 : 1 ;
if ( V_229 -> V_269 )
V_229 -> V_269 = F_87 (unsigned int,
c->sync_maxlen, min_mtu,
65535 - hlen) ;
else
V_229 -> V_269 = V_275 - V_274 ;
if ( V_63 == V_38 ) {
if ( V_9 -> V_11 )
return - V_287 ;
V_9 -> V_27 = * V_229 ;
V_112 = L_45 ;
F_131 = F_120 ;
} else if ( V_63 == V_286 ) {
if ( V_9 -> V_288 )
return - V_287 ;
V_9 -> V_173 = * V_229 ;
V_112 = L_46 ;
F_131 = F_127 ;
} else {
return - V_157 ;
}
if ( V_63 == V_38 ) {
struct V_10 * V_11 ;
V_9 -> V_11 = F_136 ( V_273 * sizeof( V_9 -> V_11 [ 0 ] ) , V_289 ) ;
if ( ! V_9 -> V_11 )
goto V_165;
V_11 = V_9 -> V_11 ;
for ( V_85 = 0 ; V_85 < V_273 ; V_85 ++ , V_11 ++ ) {
F_137 ( & V_11 -> V_14 ) ;
V_11 -> V_18 = 0 ;
V_11 -> V_19 = 0 ;
F_138 ( & V_11 -> V_39 ,
F_117 ) ;
V_11 -> V_9 = V_9 ;
}
} else {
V_271 = F_136 ( V_273 * sizeof( struct V_270 * ) ,
V_289 ) ;
if ( ! V_271 )
goto V_165;
}
V_264 = NULL ;
for ( V_85 = 0 ; V_85 < V_273 ; V_85 ++ ) {
if ( V_63 == V_38 )
V_175 = F_104 ( V_81 , V_85 ) ;
else
V_175 = F_109 ( V_81 , V_85 ) ;
if ( F_139 ( V_175 ) ) {
V_239 = F_140 ( V_175 ) ;
goto V_290;
}
V_264 = F_13 ( sizeof( * V_264 ) , V_289 ) ;
if ( ! V_264 )
goto V_291;
V_264 -> V_81 = V_81 ;
V_264 -> V_175 = V_175 ;
if ( V_63 == V_286 ) {
V_264 -> V_268 = F_13 ( V_9 -> V_173 . V_269 ,
V_289 ) ;
if ( ! V_264 -> V_268 )
goto V_290;
} else {
V_264 -> V_268 = NULL ;
}
V_264 -> V_85 = V_85 ;
V_272 = F_141 ( F_131 , V_264 , V_112 , V_9 -> V_292 , V_85 ) ;
if ( F_139 ( V_272 ) ) {
V_239 = F_140 ( V_272 ) ;
goto V_290;
}
V_264 = NULL ;
if ( V_63 == V_38 )
V_9 -> V_11 [ V_85 ] . V_42 = V_272 ;
else
V_271 [ V_85 ] = V_272 ;
}
if ( V_63 == V_286 )
V_9 -> V_288 = V_271 ;
F_6 ( & V_9 -> V_43 ) ;
V_9 -> V_37 |= V_63 ;
F_11 ( & V_9 -> V_43 ) ;
F_142 () ;
return 0 ;
V_291:
F_108 ( V_175 ) ;
V_290:
if ( V_264 ) {
F_108 ( V_264 -> V_175 ) ;
F_15 ( V_264 -> V_268 ) ;
F_15 ( V_264 ) ;
}
V_273 = V_85 ;
while ( V_273 -- > 0 ) {
if ( V_63 == V_38 )
F_143 ( V_9 -> V_11 [ V_273 ] . V_42 ) ;
else
F_143 ( V_271 [ V_273 ] ) ;
}
F_15 ( V_271 ) ;
V_165:
if ( ! ( V_9 -> V_37 & V_38 ) ) {
F_15 ( V_9 -> V_11 ) ;
V_9 -> V_11 = NULL ;
}
return V_239 ;
}
int F_144 ( struct V_81 * V_81 , int V_63 )
{
struct V_8 * V_9 = F_45 ( V_81 ) ;
struct V_270 * * V_271 ;
int V_85 ;
int V_164 = - V_157 ;
F_58 ( 7 , L_42 , V_277 , F_132 ( V_278 ) ) ;
if ( V_63 == V_38 ) {
if ( ! V_9 -> V_11 )
return - V_293 ;
F_6 ( & V_9 -> V_43 ) ;
F_19 ( & V_9 -> V_13 ) ;
V_9 -> V_37 &= ~ V_38 ;
F_25 ( & V_9 -> V_13 ) ;
F_11 ( & V_9 -> V_43 ) ;
V_164 = 0 ;
for ( V_85 = V_9 -> V_47 ; V_85 >= 0 ; V_85 -- ) {
struct V_10 * V_11 = & V_9 -> V_11 [ V_85 ] ;
int V_211 ;
F_121 ( L_47 ,
F_132 ( V_11 -> V_42 ) ) ;
F_145 ( & V_11 -> V_39 ) ;
V_211 = F_143 ( V_11 -> V_42 ) ;
if ( V_164 >= 0 )
V_164 = V_211 ;
}
F_15 ( V_9 -> V_11 ) ;
V_9 -> V_11 = NULL ;
} else if ( V_63 == V_286 ) {
if ( ! V_9 -> V_288 )
return - V_293 ;
V_9 -> V_37 &= ~ V_286 ;
V_271 = V_9 -> V_288 ;
V_164 = 0 ;
for ( V_85 = V_9 -> V_47 ; V_85 >= 0 ; V_85 -- ) {
int V_211 ;
F_121 ( L_48 ,
F_132 ( V_271 [ V_85 ] ) ) ;
V_211 = F_143 ( V_271 [ V_85 ] ) ;
if ( V_164 >= 0 )
V_164 = V_211 ;
}
F_15 ( V_271 ) ;
V_9 -> V_288 = NULL ;
}
F_146 () ;
return V_164 ;
}
int T_7 F_147 ( struct V_81 * V_81 )
{
struct V_8 * V_9 = F_45 ( V_81 ) ;
F_148 ( & V_9 -> V_294 , L_49 , & V_295 ) ;
F_149 ( & V_9 -> V_13 ) ;
F_149 ( & V_9 -> V_43 ) ;
return 0 ;
}
void F_150 ( struct V_81 * V_81 )
{
int V_164 ;
struct V_8 * V_9 = F_45 ( V_81 ) ;
F_151 ( & V_9 -> V_294 ) ;
V_164 = F_144 ( V_81 , V_38 ) ;
if ( V_164 && V_164 != - V_293 )
F_46 ( L_50 ) ;
V_164 = F_144 ( V_81 , V_286 ) ;
if ( V_164 && V_164 != - V_293 )
F_46 ( L_51 ) ;
F_152 ( & V_9 -> V_294 ) ;
}
