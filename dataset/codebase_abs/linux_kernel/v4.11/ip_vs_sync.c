static void F_1 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
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
static void F_44 ( struct V_8 * V_9 , struct V_45 * V_46 ,
int V_52 )
{
struct V_48 * V_81 ;
struct F_44 * V_82 ;
struct V_7 * V_83 ;
struct V_10 * V_11 ;
int V_84 ;
unsigned int V_20 ;
if ( F_34 ( V_46 -> V_85 != V_86 ) )
return;
if ( V_46 -> V_50 & V_87 )
return;
if ( ! F_32 ( V_9 , V_46 , V_52 ) )
return;
F_6 ( & V_9 -> V_43 ) ;
if ( ! ( V_9 -> V_37 & V_38 ) ) {
F_11 ( & V_9 -> V_43 ) ;
return;
}
V_84 = F_28 ( V_9 , V_46 ) ;
V_11 = & V_9 -> V_11 [ V_84 ] ;
V_83 = V_11 -> V_36 ;
V_20 = ( V_46 -> V_50 & V_88 ) ? V_89 :
V_90 ;
if ( V_83 ) {
V_81 = (struct V_48 * ) V_83 -> V_22 ;
if ( V_83 -> V_32 + V_20 > V_83 -> V_33 || ! V_81 -> V_30 ) {
F_18 ( V_9 , V_11 ) ;
V_11 -> V_36 = NULL ;
V_83 = NULL ;
}
}
if ( ! V_83 ) {
V_83 = F_30 ( V_9 , V_20 ) ;
if ( ! V_83 ) {
F_11 ( & V_9 -> V_43 ) ;
F_45 ( L_1 ) ;
return;
}
V_11 -> V_36 = V_83 ;
}
V_81 = (struct V_48 * ) V_83 -> V_22 ;
V_82 = (struct F_44 * ) V_83 -> V_32 ;
V_82 -> V_23 = 0 ;
V_82 -> V_61 = V_46 -> V_61 ;
V_82 -> V_91 = V_46 -> V_91 ;
V_82 -> V_92 = V_46 -> V_92 ;
V_82 -> V_93 = V_46 -> V_93 ;
V_82 -> V_94 = V_46 -> V_94 . V_95 ;
V_82 -> V_96 = V_46 -> V_96 . V_95 ;
V_82 -> V_97 = V_46 -> V_97 . V_95 ;
V_82 -> V_50 = F_16 ( V_46 -> V_50 & ~ V_98 ) ;
V_82 -> V_63 = F_16 ( V_46 -> V_63 ) ;
if ( V_46 -> V_50 & V_88 ) {
struct V_99 * V_100 =
(struct V_99 * ) & V_82 [ 1 ] ;
memcpy ( V_100 , & V_46 -> V_101 , sizeof( * V_100 ) ) ;
}
V_81 -> V_30 ++ ;
V_81 -> V_28 = F_16 ( F_46 ( V_81 -> V_28 ) + V_20 ) ;
V_83 -> V_32 += V_20 ;
F_11 ( & V_9 -> V_43 ) ;
V_46 = V_46 -> V_49 ;
if ( V_46 ) {
if ( V_46 -> V_50 & V_51 )
V_52 = F_47 ( 1 , & V_46 -> V_102 ) ;
else
V_52 = F_42 ( V_9 ) ;
F_48 ( V_9 , V_46 , V_52 ) ;
}
}
void F_48 ( struct V_8 * V_9 , struct V_45 * V_46 , int V_52 )
{
struct V_29 * V_81 ;
union F_48 * V_82 ;
struct V_7 * V_83 ;
struct V_10 * V_11 ;
int V_84 ;
T_1 * V_103 ;
unsigned int V_20 , V_104 , V_105 ;
if ( F_49 ( V_9 ) == 0 ) {
F_44 ( V_9 , V_46 , V_52 ) ;
return;
}
if ( V_46 -> V_50 & V_87 )
goto V_49;
V_106:
if ( ! F_32 ( V_9 , V_46 , V_52 ) )
goto V_49;
V_104 = 0 ;
if ( V_46 -> V_107 ) {
if ( ! V_46 -> V_108 || ! V_46 -> V_109 ) {
F_50 ( L_2 ) ;
return;
}
V_104 = F_51 ( V_46 -> V_110 -> V_111 , V_112 ) ;
}
F_6 ( & V_9 -> V_43 ) ;
if ( ! ( V_9 -> V_37 & V_38 ) ) {
F_11 ( & V_9 -> V_43 ) ;
return;
}
V_84 = F_28 ( V_9 , V_46 ) ;
V_11 = & V_9 -> V_11 [ V_84 ] ;
#ifdef F_52
if ( V_46 -> V_85 == V_113 )
V_20 = sizeof( struct V_114 ) ;
else
#endif
V_20 = sizeof( struct V_115 ) ;
if ( V_46 -> V_50 & V_88 )
V_20 += sizeof( struct V_99 ) + 2 ;
if ( V_46 -> V_107 )
V_20 += V_46 -> V_107 + 2 ;
if ( V_104 )
V_20 += V_104 + 2 ;
V_105 = 0 ;
V_83 = V_11 -> V_36 ;
if ( V_83 ) {
V_81 = V_83 -> V_22 ;
V_105 = ( 4 - ( V_116 ) V_83 -> V_32 ) & 3 ;
if ( V_83 -> V_32 + V_20 + V_105 > V_83 -> V_33 || V_81 -> V_23 ) {
F_18 ( V_9 , V_11 ) ;
V_11 -> V_36 = NULL ;
V_83 = NULL ;
V_105 = 0 ;
}
}
if ( ! V_83 ) {
V_83 = F_12 ( V_9 , V_20 ) ;
if ( ! V_83 ) {
F_11 ( & V_9 -> V_43 ) ;
F_45 ( L_1 ) ;
return;
}
V_11 -> V_36 = V_83 ;
V_81 = V_83 -> V_22 ;
}
V_103 = V_83 -> V_32 ;
V_83 -> V_32 += V_105 + V_20 ;
V_81 -> V_28 = F_16 ( F_46 ( V_81 -> V_28 ) + V_105 + V_20 ) ;
while ( V_105 -- )
* ( V_103 ++ ) = 0 ;
V_82 = (union F_48 * ) V_103 ;
V_82 -> V_117 . type = ( V_46 -> V_85 == V_113 ? V_118 : 0 ) ;
V_82 -> V_117 . V_119 = F_16 ( V_20 & V_120 ) ;
V_82 -> V_117 . V_50 = F_53 ( V_46 -> V_50 & ~ V_98 ) ;
V_82 -> V_117 . V_63 = F_16 ( V_46 -> V_63 ) ;
V_82 -> V_117 . V_61 = V_46 -> V_61 ;
V_82 -> V_117 . V_91 = V_46 -> V_91 ;
V_82 -> V_117 . V_92 = V_46 -> V_92 ;
V_82 -> V_117 . V_93 = V_46 -> V_93 ;
V_82 -> V_117 . V_121 = F_53 ( V_46 -> V_121 ) ;
V_82 -> V_117 . V_57 = F_53 ( V_46 -> V_57 / V_79 ) ;
V_81 -> V_30 ++ ;
#ifdef F_52
if ( V_46 -> V_85 == V_113 ) {
V_103 += sizeof( struct V_114 ) ;
V_82 -> V_122 . V_94 = V_46 -> V_94 . V_123 ;
V_82 -> V_122 . V_96 = V_46 -> V_96 . V_123 ;
V_82 -> V_122 . V_97 = V_46 -> V_97 . V_123 ;
} else
#endif
{
V_103 += sizeof( struct V_115 ) ;
V_82 -> V_117 . V_94 = V_46 -> V_94 . V_95 ;
V_82 -> V_117 . V_96 = V_46 -> V_96 . V_95 ;
V_82 -> V_117 . V_97 = V_46 -> V_97 . V_95 ;
}
if ( V_46 -> V_50 & V_88 ) {
* ( V_103 ++ ) = V_124 ;
* ( V_103 ++ ) = sizeof( struct V_99 ) ;
F_3 ( (struct V_1 * ) V_103 , & V_46 -> V_101 ) ;
V_103 += sizeof( struct V_1 ) ;
F_3 ( (struct V_1 * ) V_103 , & V_46 -> V_125 ) ;
V_103 += sizeof( struct V_1 ) ;
}
if ( V_46 -> V_107 && V_46 -> V_108 ) {
* ( V_103 ++ ) = V_126 ;
* ( V_103 ++ ) = V_46 -> V_107 ;
memcpy ( V_103 , V_46 -> V_108 , V_46 -> V_107 ) ;
V_103 += V_46 -> V_107 ;
if ( V_104 ) {
* ( V_103 ++ ) = V_127 ;
* ( V_103 ++ ) = V_104 ;
memcpy ( V_103 , V_46 -> V_110 -> V_111 , V_104 ) ;
V_103 += V_104 ;
}
}
F_11 ( & V_9 -> V_43 ) ;
V_49:
V_46 = V_46 -> V_49 ;
if ( ! V_46 )
return;
if ( V_46 -> V_50 & V_51 )
V_52 = F_47 ( 1 , & V_46 -> V_102 ) ;
else
V_52 = F_42 ( V_9 ) ;
goto V_106;
}
static inline int
F_54 ( struct V_8 * V_9 , int V_85 , union F_48 * V_128 ,
struct V_129 * V_103 ,
T_1 * V_108 , unsigned int V_107 ,
T_1 * V_130 , unsigned int V_104 )
{
#ifdef F_52
if ( V_85 == V_113 )
F_55 ( V_9 , V_85 , V_128 -> V_122 . V_61 ,
( const union V_131 * ) & V_128 -> V_122 . V_94 ,
V_128 -> V_122 . V_91 ,
( const union V_131 * ) & V_128 -> V_122 . V_96 ,
V_128 -> V_122 . V_92 , V_103 ) ;
else
#endif
F_55 ( V_9 , V_85 , V_128 -> V_117 . V_61 ,
( const union V_131 * ) & V_128 -> V_117 . V_94 ,
V_128 -> V_117 . V_91 ,
( const union V_131 * ) & V_128 -> V_117 . V_96 ,
V_128 -> V_117 . V_92 , V_103 ) ;
if ( V_107 ) {
if ( V_104 ) {
char V_83 [ V_112 + 1 ] ;
memcpy ( V_83 , V_130 , V_104 ) ;
V_83 [ V_104 ] = 0 ;
V_103 -> V_110 = F_56 ( V_83 ) ;
if ( ! V_103 -> V_110 ) {
F_57 ( 3 , L_3 ,
V_83 ) ;
return 1 ;
}
} else {
F_50 ( L_4 ) ;
return 1 ;
}
V_103 -> V_108 = F_58 ( V_108 , V_107 , V_21 ) ;
if ( ! V_103 -> V_108 ) {
F_59 ( V_103 -> V_110 -> V_132 ) ;
return - V_133 ;
}
V_103 -> V_107 = V_107 ;
}
return 0 ;
}
static void F_60 ( struct V_8 * V_9 , struct V_129 * V_134 ,
unsigned int V_50 , unsigned int V_63 ,
unsigned int V_61 , unsigned int type ,
const union V_131 * V_97 , T_2 V_93 ,
unsigned long V_57 , T_3 V_121 ,
struct V_99 * V_100 )
{
struct V_135 * V_109 ;
struct V_45 * V_46 ;
if ( ! ( V_50 & V_51 ) ) {
V_46 = F_61 ( V_134 ) ;
if ( V_46 && ( ( V_46 -> V_93 != V_93 ) ||
! F_62 ( V_46 -> V_136 , & V_46 -> V_97 , V_97 ) ) ) {
if ( ! ( V_50 & V_137 ) ) {
F_63 ( V_46 ) ;
F_64 ( V_46 ) ;
V_46 = NULL ;
} else {
F_64 ( V_46 ) ;
F_15 ( V_134 -> V_108 ) ;
return;
}
}
} else {
V_46 = F_65 ( V_134 ) ;
}
if ( V_46 ) {
F_15 ( V_134 -> V_108 ) ;
V_109 = V_46 -> V_109 ;
F_6 ( & V_46 -> V_138 ) ;
if ( ( V_46 -> V_50 ^ V_50 ) & V_137 &&
! ( V_50 & V_51 ) && V_109 ) {
if ( V_50 & V_137 ) {
F_66 ( & V_109 -> V_139 ) ;
F_67 ( & V_109 -> V_140 ) ;
} else {
F_67 ( & V_109 -> V_139 ) ;
F_66 ( & V_109 -> V_140 ) ;
}
}
V_50 &= V_141 ;
V_50 |= V_46 -> V_50 & ~ V_141 ;
V_46 -> V_50 = V_50 ;
F_11 ( & V_46 -> V_138 ) ;
if ( ! V_109 )
F_68 ( V_46 ) ;
} else {
F_69 () ;
V_109 = F_70 ( V_9 , type , type , V_97 , V_93 ,
V_134 -> V_96 , V_134 -> V_92 , V_61 ,
V_121 , V_50 ) ;
V_46 = F_71 ( V_134 , type , V_97 , V_93 , V_50 , V_109 ,
V_121 ) ;
F_72 () ;
if ( ! V_46 ) {
F_15 ( V_134 -> V_108 ) ;
F_57 ( 2 , L_5 ) ;
return;
}
if ( ! ( V_50 & V_51 ) )
F_15 ( V_134 -> V_108 ) ;
}
if ( V_100 ) {
V_46 -> V_101 = V_100 -> V_101 ;
V_46 -> V_125 = V_100 -> V_125 ;
}
F_73 ( & V_46 -> V_102 , F_42 ( V_9 ) ) ;
V_46 -> V_63 = V_63 ;
V_46 -> V_69 = V_46 -> V_63 ;
if ( V_57 ) {
if ( V_57 > V_142 / V_79 )
V_57 = V_142 / V_79 ;
V_46 -> V_57 = V_57 * V_79 ;
} else {
struct V_143 * V_144 ;
V_144 = F_74 ( V_9 , V_61 ) ;
if ( ! ( V_50 & V_51 ) && V_144 && V_144 -> V_145 )
V_46 -> V_57 = V_144 -> V_145 [ V_63 ] ;
else
V_46 -> V_57 = ( 3 * 60 * V_79 ) ;
}
F_75 ( V_46 ) ;
}
static void F_76 ( struct V_8 * V_9 , const char * V_146 ,
const V_116 V_147 )
{
struct V_48 * V_81 = (struct V_48 * ) V_146 ;
struct F_44 * V_82 ;
struct V_99 * V_100 ;
struct V_148 * V_149 ;
struct V_129 V_134 ;
char * V_103 ;
int V_150 ;
V_103 = ( char * ) V_146 + sizeof( struct V_48 ) ;
for ( V_150 = 0 ; V_150 < V_81 -> V_30 ; V_150 ++ ) {
unsigned int V_50 , V_63 ;
if ( V_103 + V_90 > V_146 + V_147 ) {
F_50 ( L_6 ) ;
return;
}
V_82 = (struct F_44 * ) V_103 ;
V_50 = F_46 ( V_82 -> V_50 ) | V_151 ;
V_50 &= ~ V_98 ;
if ( V_50 & V_88 ) {
V_100 = (struct V_99 * ) & V_82 [ 1 ] ;
V_103 += V_89 ;
if ( V_103 > V_146 + V_147 ) {
F_50 ( L_7 ) ;
return;
}
} else {
V_100 = NULL ;
V_103 += V_90 ;
}
V_63 = F_46 ( V_82 -> V_63 ) ;
if ( ! ( V_50 & V_51 ) ) {
V_149 = F_77 ( V_82 -> V_61 ) ;
if ( ! V_149 ) {
F_57 ( 2 , L_8 ,
V_82 -> V_61 ) ;
continue;
}
if ( V_63 >= V_149 -> V_152 ) {
F_57 ( 2 , L_9 ,
V_149 -> V_111 , V_63 ) ;
continue;
}
} else {
if ( V_63 > 0 ) {
F_57 ( 2 , L_10 ,
V_63 ) ;
V_63 = 0 ;
}
}
F_55 ( V_9 , V_86 , V_82 -> V_61 ,
( const union V_131 * ) & V_82 -> V_94 ,
V_82 -> V_91 ,
( const union V_131 * ) & V_82 -> V_96 ,
V_82 -> V_92 , & V_134 ) ;
F_60 ( V_9 , & V_134 , V_50 , V_63 , V_82 -> V_61 , V_86 ,
(union V_131 * ) & V_82 -> V_97 , V_82 -> V_93 ,
0 , 0 , V_100 ) ;
}
}
static inline int F_78 ( T_1 * V_103 , unsigned int V_153 ,
T_3 * V_154 ,
struct V_99 * V_100 )
{
struct V_99 * V_155 ;
V_155 = (struct V_99 * ) V_103 ;
if ( V_153 != sizeof( struct V_99 ) ) {
F_57 ( 2 , L_11 ) ;
return - V_156 ;
}
if ( * V_154 & V_157 ) {
F_57 ( 2 , L_12 ) ;
return - V_156 ;
}
F_1 ( & V_155 -> V_101 , & V_100 -> V_101 ) ;
F_1 ( & V_155 -> V_125 , & V_100 -> V_125 ) ;
* V_154 |= V_157 ;
return 0 ;
}
static int F_79 ( T_1 * V_103 , unsigned int V_153 , unsigned int * V_158 ,
T_1 * * V_159 , unsigned int V_160 ,
T_3 * V_154 , T_3 V_161 )
{
if ( V_153 > V_160 ) {
F_57 ( 2 , L_13 , V_160 ) ;
return - V_156 ;
}
if ( * V_154 & V_161 ) {
F_57 ( 2 , L_14 , V_161 ) ;
return - V_156 ;
}
* V_158 = V_153 ;
* V_159 = V_103 ;
* V_154 |= V_161 ;
return 0 ;
}
static inline int F_80 ( struct V_8 * V_9 , T_1 * V_103 , T_1 * V_162 )
{
struct V_99 V_100 ;
union F_48 * V_82 ;
struct V_148 * V_149 ;
struct V_129 V_134 ;
T_3 V_50 ;
unsigned int V_85 , V_63 , V_107 = 0 , V_104 = 0 ;
T_1 * V_108 = NULL , * V_130 = NULL ;
T_3 V_154 = 0 ;
int V_163 = 0 ;
V_82 = (union F_48 * ) V_103 ;
if ( V_82 -> V_122 . type & V_118 ) {
#ifdef F_52
V_85 = V_113 ;
V_103 += sizeof( struct V_114 ) ;
#else
F_57 ( 3 , L_15 ) ;
V_163 = 10 ;
goto V_164;
#endif
} else if ( ! V_82 -> V_117 . type ) {
V_85 = V_86 ;
V_103 += sizeof( struct V_115 ) ;
} else {
return - 10 ;
}
if ( V_103 > V_162 )
return - 20 ;
while ( V_103 < V_162 ) {
int V_165 ;
int V_153 ;
if ( V_103 + 2 > V_162 )
return - 30 ;
V_165 = * ( V_103 ++ ) ;
V_153 = * ( V_103 ++ ) ;
if ( ! V_153 || ( ( V_103 + V_153 ) > V_162 ) )
return - 40 ;
switch ( V_165 & ~ V_166 ) {
case V_124 :
if ( F_78 ( V_103 , V_153 , & V_154 , & V_100 ) )
return - 50 ;
break;
case V_126 :
if ( F_79 ( V_103 , V_153 , & V_107 , & V_108 ,
V_167 , & V_154 ,
V_168 ) )
return - 60 ;
break;
case V_127 :
if ( F_79 ( V_103 , V_153 , & V_104 , & V_130 ,
V_112 , & V_154 ,
V_169 ) )
return - 70 ;
break;
default:
if ( ! ( V_165 & V_166 ) ) {
F_57 ( 3 , L_16 ,
V_165 & ~ V_166 ) ;
V_163 = 20 ;
goto V_164;
}
}
V_103 += V_153 ;
}
V_50 = F_81 ( V_82 -> V_117 . V_50 ) & V_170 ;
V_50 |= V_151 ;
V_63 = F_46 ( V_82 -> V_117 . V_63 ) ;
if ( ! ( V_50 & V_51 ) ) {
V_149 = F_77 ( V_82 -> V_117 . V_61 ) ;
if ( ! V_149 ) {
F_57 ( 3 , L_17 ,
V_82 -> V_117 . V_61 ) ;
V_163 = 30 ;
goto V_164;
}
if ( V_63 >= V_149 -> V_152 ) {
F_57 ( 3 , L_18 ,
V_149 -> V_111 , V_63 ) ;
V_163 = 40 ;
goto V_164;
}
} else {
if ( V_63 > 0 ) {
F_57 ( 3 , L_19 ,
V_63 ) ;
V_63 = 0 ;
}
}
if ( F_54 ( V_9 , V_85 , V_82 , & V_134 , V_108 ,
V_107 , V_130 , V_104 ) ) {
V_163 = 50 ;
goto V_164;
}
if ( V_85 == V_86 )
F_60 ( V_9 , & V_134 , V_50 , V_63 , V_82 -> V_117 . V_61 , V_85 ,
(union V_131 * ) & V_82 -> V_117 . V_97 , V_82 -> V_117 . V_93 ,
F_81 ( V_82 -> V_117 . V_57 ) , F_81 ( V_82 -> V_117 . V_121 ) ,
( V_154 & V_157 ? & V_100 : NULL )
) ;
#ifdef F_52
else
F_60 ( V_9 , & V_134 , V_50 , V_63 , V_82 -> V_122 . V_61 , V_85 ,
(union V_131 * ) & V_82 -> V_122 . V_97 , V_82 -> V_122 . V_93 ,
F_81 ( V_82 -> V_122 . V_57 ) , F_81 ( V_82 -> V_122 . V_121 ) ,
( V_154 & V_157 ? & V_100 : NULL )
) ;
#endif
F_82 ( V_134 . V_110 ) ;
return 0 ;
V_164:
F_57 ( 2 , L_20 , V_163 ) ;
return V_163 ;
}
static void F_83 ( struct V_8 * V_9 , T_1 * V_146 ,
const V_116 V_147 )
{
struct V_29 * V_171 = (struct V_29 * ) V_146 ;
T_1 * V_103 , * V_162 ;
int V_150 , V_30 ;
if ( V_147 < sizeof( struct V_48 ) ) {
F_57 ( 2 , L_21 ) ;
return;
}
if ( V_147 != F_46 ( V_171 -> V_28 ) ) {
F_57 ( 2 , L_22 ) ;
return;
}
if ( V_9 -> V_172 . V_26 != 0 && V_171 -> V_26 != V_9 -> V_172 . V_26 ) {
F_57 ( 7 , L_23 , V_171 -> V_26 ) ;
return;
}
if ( ( V_171 -> V_24 == V_25 ) && ( V_171 -> V_23 == 0 )
&& ( V_171 -> V_31 == 0 ) ) {
V_162 = V_146 + sizeof( struct V_29 ) ;
V_30 = V_171 -> V_30 ;
for ( V_150 = 0 ; V_150 < V_30 ; V_150 ++ ) {
union F_48 * V_82 ;
unsigned int V_28 ;
int V_163 ;
V_103 = V_162 ;
if ( V_103 + sizeof( V_82 -> V_117 ) > V_146 + V_147 ) {
F_50 ( L_24 ) ;
return;
}
V_82 = (union F_48 * ) V_103 ;
V_28 = F_46 ( V_82 -> V_117 . V_119 ) & V_120 ;
V_162 = V_103 + V_28 ;
if ( V_162 > V_146 + V_147 ) {
F_50 ( L_25 ) ;
return;
}
if ( F_46 ( V_82 -> V_117 . V_119 ) >> V_173 ) {
F_50 ( L_26 ,
F_46 ( V_82 -> V_117 . V_119 ) >> V_173 ) ;
return;
}
V_163 = F_80 ( V_9 , V_103 , V_162 ) ;
if ( V_163 < 0 ) {
F_50 ( L_27 ,
V_163 ) ;
return;
}
V_162 = V_103 + ( ( V_28 + 3 ) & ~ 3 ) ;
}
} else {
F_76 ( V_9 , V_146 , V_147 ) ;
return;
}
}
static void F_84 ( struct V_174 * V_175 , int V_176 , int V_177 )
{
F_85 ( V_175 ) ;
if ( V_176 ) {
V_177 = F_86 ( int , V_177 , ( V_178 + 1 ) / 2 ,
V_179 ) ;
V_175 -> V_180 = V_177 * 2 ;
V_175 -> V_181 |= V_182 ;
} else {
V_177 = F_86 ( int , V_177 , ( V_183 + 1 ) / 2 ,
V_184 ) ;
V_175 -> V_185 = V_177 * 2 ;
V_175 -> V_181 |= V_186 ;
}
F_87 ( V_175 ) ;
}
static void F_88 ( struct V_174 * V_175 , T_4 V_187 )
{
struct V_188 * V_189 = F_89 ( V_175 ) ;
F_85 ( V_175 ) ;
V_189 -> V_190 = V_187 ? 1 : 0 ;
#ifdef F_52
if ( V_175 -> V_191 == V_113 ) {
struct V_192 * V_193 = F_90 ( V_175 ) ;
V_193 -> V_190 = V_187 ? 1 : 0 ;
}
#endif
F_87 ( V_175 ) ;
}
static void F_91 ( struct V_174 * V_175 , T_4 V_194 )
{
struct V_188 * V_189 = F_89 ( V_175 ) ;
F_85 ( V_175 ) ;
V_189 -> V_195 = V_194 ;
#ifdef F_52
if ( V_175 -> V_191 == V_113 ) {
struct V_192 * V_193 = F_90 ( V_175 ) ;
V_193 -> V_196 = V_194 ;
}
#endif
F_87 ( V_175 ) ;
}
static void F_92 ( struct V_174 * V_175 , int V_177 )
{
struct V_188 * V_189 = F_89 ( V_175 ) ;
F_85 ( V_175 ) ;
V_189 -> V_197 = V_177 ;
#ifdef F_52
if ( V_175 -> V_191 == V_113 ) {
struct V_192 * V_193 = F_90 ( V_175 ) ;
V_193 -> V_197 = V_177 ;
}
#endif
F_87 ( V_175 ) ;
}
static int F_93 ( struct V_174 * V_175 , char * V_198 )
{
struct V_199 * V_200 ;
struct V_188 * V_189 = F_89 ( V_175 ) ;
struct V_201 * V_201 = F_94 ( V_175 ) ;
V_200 = F_95 ( V_201 , V_198 ) ;
if ( ! V_200 )
return - V_202 ;
if ( V_175 -> V_203 && V_200 -> V_204 != V_175 -> V_203 )
return - V_156 ;
F_85 ( V_175 ) ;
V_189 -> V_205 = V_200 -> V_204 ;
#ifdef F_52
if ( V_175 -> V_191 == V_113 ) {
struct V_192 * V_193 = F_90 ( V_175 ) ;
V_193 -> V_206 = V_200 -> V_204 ;
}
#endif
F_87 ( V_175 ) ;
return 0 ;
}
static int
F_96 ( struct V_174 * V_175 , struct V_207 * V_208 , char * V_198 )
{
struct V_201 * V_201 = F_94 ( V_175 ) ;
struct V_209 V_210 ;
struct V_199 * V_200 ;
int V_211 ;
memset ( & V_210 , 0 , sizeof( V_210 ) ) ;
memcpy ( & V_210 . V_212 , V_208 , sizeof( struct V_207 ) ) ;
V_200 = F_95 ( V_201 , V_198 ) ;
if ( ! V_200 )
return - V_202 ;
if ( V_175 -> V_203 && V_200 -> V_204 != V_175 -> V_203 )
return - V_156 ;
V_210 . V_213 = V_200 -> V_204 ;
F_85 ( V_175 ) ;
V_211 = F_97 ( V_175 , & V_210 ) ;
F_87 ( V_175 ) ;
return V_211 ;
}
static int F_98 ( struct V_174 * V_175 , struct V_214 * V_208 ,
char * V_198 )
{
struct V_201 * V_201 = F_94 ( V_175 ) ;
struct V_199 * V_200 ;
int V_211 ;
V_200 = F_95 ( V_201 , V_198 ) ;
if ( ! V_200 )
return - V_202 ;
if ( V_175 -> V_203 && V_200 -> V_204 != V_175 -> V_203 )
return - V_156 ;
F_85 ( V_175 ) ;
V_211 = F_99 ( V_175 , V_200 -> V_204 , V_208 ) ;
F_87 ( V_175 ) ;
return V_211 ;
}
static int F_100 ( struct V_215 * V_174 , char * V_198 )
{
struct V_201 * V_201 = F_94 ( V_174 -> V_175 ) ;
struct V_199 * V_200 ;
T_5 V_208 ;
struct V_216 sin ;
V_200 = F_95 ( V_201 , V_198 ) ;
if ( ! V_200 )
return - V_202 ;
V_208 = F_101 ( V_200 , 0 , V_217 ) ;
if ( ! V_208 )
F_45 ( L_28
L_29 ) ;
F_57 ( 7 , L_30 ,
V_198 , & V_208 ) ;
sin . V_218 = V_86 ;
sin . V_219 . V_220 = V_208 ;
sin . V_221 = 0 ;
return V_174 -> V_222 -> V_223 ( V_174 , (struct V_224 * ) & sin , sizeof( sin ) ) ;
}
static void F_102 ( union V_225 * V_226 , int * V_227 ,
struct V_228 * V_229 , int V_84 )
{
if ( V_113 == V_229 -> V_230 ) {
V_226 -> V_123 = (struct V_231 ) {
. V_232 = V_113 ,
. V_233 = F_16 ( V_229 -> V_234 + V_84 ) ,
} ;
V_226 -> V_123 . V_235 = V_229 -> V_236 . V_123 ;
* V_227 = sizeof( V_226 -> V_123 ) ;
} else {
V_226 -> V_237 = (struct V_216 ) {
. V_218 = V_86 ,
. V_221 = F_16 ( V_229 -> V_234 + V_84 ) ,
} ;
V_226 -> V_237 . V_219 = V_229 -> V_236 . V_237 ;
* V_227 = sizeof( V_226 -> V_237 ) ;
}
}
static struct V_215 * F_103 ( struct V_8 * V_9 , int V_84 )
{
union V_225 V_238 ;
struct V_215 * V_174 ;
int V_239 , V_227 ;
V_239 = F_104 ( V_9 -> V_201 , V_9 -> V_27 . V_230 , V_240 ,
V_241 , & V_174 ) ;
if ( V_239 < 0 ) {
F_45 ( L_31 ) ;
return F_105 ( V_239 ) ;
}
V_239 = F_93 ( V_174 -> V_175 , V_9 -> V_27 . V_242 ) ;
if ( V_239 < 0 ) {
F_45 ( L_32 ) ;
goto error;
}
F_88 ( V_174 -> V_175 , 0 ) ;
F_91 ( V_174 -> V_175 , V_9 -> V_27 . V_243 ) ;
F_92 ( V_174 -> V_175 , V_244 ) ;
V_239 = F_106 ( V_9 ) ;
if ( V_239 > 0 )
F_84 ( V_174 -> V_175 , 1 , V_239 ) ;
if ( V_86 == V_9 -> V_27 . V_230 )
V_239 = F_100 ( V_174 , V_9 -> V_27 . V_242 ) ;
else
V_239 = 0 ;
if ( V_239 < 0 ) {
F_45 ( L_33 ) ;
goto error;
}
F_102 ( & V_238 , & V_227 , & V_9 -> V_27 , V_84 ) ;
V_239 = V_174 -> V_222 -> V_245 ( V_174 , (struct V_224 * ) & V_238 ,
V_227 , 0 ) ;
if ( V_239 < 0 ) {
F_45 ( L_34 ) ;
goto error;
}
return V_174 ;
error:
F_107 ( V_174 ) ;
return F_105 ( V_239 ) ;
}
static struct V_215 * F_108 ( struct V_8 * V_9 , int V_84 ,
int V_204 )
{
union V_225 V_238 ;
struct V_215 * V_174 ;
int V_239 , V_227 ;
V_239 = F_104 ( V_9 -> V_201 , V_9 -> V_172 . V_230 , V_240 ,
V_241 , & V_174 ) ;
if ( V_239 < 0 ) {
F_45 ( L_31 ) ;
return F_105 ( V_239 ) ;
}
V_174 -> V_175 -> V_246 = V_247 ;
V_239 = F_106 ( V_9 ) ;
if ( V_239 > 0 )
F_84 ( V_174 -> V_175 , 0 , V_239 ) ;
F_102 ( & V_238 , & V_227 , & V_9 -> V_172 , V_84 ) ;
V_174 -> V_175 -> V_203 = V_204 ;
V_239 = V_174 -> V_222 -> V_223 ( V_174 , (struct V_224 * ) & V_238 , V_227 ) ;
if ( V_239 < 0 ) {
F_45 ( L_35 ) ;
goto error;
}
#ifdef F_52
if ( V_9 -> V_172 . V_230 == V_113 )
V_239 = F_98 ( V_174 -> V_175 , & V_238 . V_123 . V_235 ,
V_9 -> V_172 . V_242 ) ;
else
#endif
V_239 = F_96 ( V_174 -> V_175 , & V_238 . V_237 . V_219 ,
V_9 -> V_172 . V_242 ) ;
if ( V_239 < 0 ) {
F_45 ( L_36 ) ;
goto error;
}
return V_174 ;
error:
F_107 ( V_174 ) ;
return F_105 ( V_239 ) ;
}
static int
F_109 ( struct V_215 * V_174 , const char * V_146 , const V_116 V_248 )
{
struct V_249 V_250 = { . V_251 = V_252 | V_253 } ;
struct V_254 V_255 ;
int V_20 ;
F_110 ( 7 ) ;
V_255 . V_256 = ( void * ) V_146 ;
V_255 . V_257 = V_248 ;
V_20 = F_111 ( V_174 , & V_250 , & V_255 , 1 , ( V_116 ) ( V_248 ) ) ;
F_112 ( 7 ) ;
return V_20 ;
}
static int
F_113 ( struct V_215 * V_174 , struct V_29 * V_250 )
{
int V_258 ;
int V_211 ;
V_258 = F_46 ( V_250 -> V_28 ) ;
V_211 = F_109 ( V_174 , ( char * ) V_250 , V_258 ) ;
if ( V_211 >= 0 || V_211 == - V_259 )
return V_211 ;
F_45 ( L_37 , V_211 ) ;
return 0 ;
}
static int
F_114 ( struct V_215 * V_174 , char * V_146 , const V_116 V_147 )
{
struct V_249 V_250 = { NULL ,} ;
struct V_254 V_255 ;
int V_20 ;
F_110 ( 7 ) ;
V_255 . V_256 = V_146 ;
V_255 . V_257 = ( V_116 ) V_147 ;
V_20 = F_115 ( V_174 , & V_250 , & V_255 , 1 , V_147 , V_252 ) ;
if ( V_20 < 0 )
return V_20 ;
F_112 ( 7 ) ;
return V_20 ;
}
static void F_116 ( struct V_260 * V_261 )
{
struct V_10 * V_11 =
F_117 ( V_261 , struct V_10 ,
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
F_118 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
struct V_7 * V_12 ;
V_12 = F_5 ( V_9 , V_11 ) ;
if ( V_12 )
return V_12 ;
return F_26 ( V_9 , V_11 , V_262 ) ;
}
static int F_119 ( void * V_159 )
{
struct V_263 * V_264 = V_159 ;
struct V_8 * V_9 = V_264 -> V_9 ;
struct V_10 * V_11 = & V_9 -> V_11 [ V_264 -> V_84 ] ;
struct V_174 * V_175 = V_264 -> V_174 -> V_175 ;
struct V_7 * V_12 ;
F_120 ( L_38
L_39 ,
V_9 -> V_27 . V_242 , V_9 -> V_27 . V_26 , V_264 -> V_84 ) ;
for (; ; ) {
V_12 = F_118 ( V_9 , V_11 ) ;
if ( F_34 ( F_121 () ) )
break;
if ( ! V_12 ) {
F_122 ( V_265 ) ;
continue;
}
while ( F_113 ( V_264 -> V_174 , V_12 -> V_22 ) < 0 ) {
F_123 ( * F_124 ( V_175 ) ,
F_125 ( V_175 ) ||
F_121 () ) ;
if ( F_34 ( F_121 () ) )
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
F_107 ( V_264 -> V_174 ) ;
F_15 ( V_264 ) ;
return 0 ;
}
static int F_126 ( void * V_159 )
{
struct V_263 * V_264 = V_159 ;
struct V_8 * V_9 = V_264 -> V_9 ;
int V_20 ;
F_120 ( L_40
L_39 ,
V_9 -> V_172 . V_242 , V_9 -> V_172 . V_26 , V_264 -> V_84 ) ;
while ( ! F_121 () ) {
F_127 ( * F_124 ( V_264 -> V_174 -> V_175 ) ,
! F_128 ( & V_264 -> V_174 -> V_175 -> V_267 )
|| F_121 () ) ;
while ( ! F_128 ( & ( V_264 -> V_174 -> V_175 -> V_267 ) ) ) {
V_20 = F_114 ( V_264 -> V_174 , V_264 -> V_268 ,
V_9 -> V_172 . V_269 ) ;
if ( V_20 <= 0 ) {
if ( V_20 != - V_259 )
F_45 ( L_41 ) ;
break;
}
F_83 ( V_9 , V_264 -> V_268 , V_20 ) ;
}
}
F_107 ( V_264 -> V_174 ) ;
F_15 ( V_264 -> V_268 ) ;
F_15 ( V_264 ) ;
return 0 ;
}
int F_129 ( struct V_8 * V_9 , struct V_228 * V_229 ,
int V_63 )
{
struct V_263 * V_264 ;
struct V_270 * * V_271 = NULL , * V_272 ;
struct V_215 * V_174 ;
struct V_199 * V_200 ;
char * V_111 ;
int (* F_130)( void * V_159 );
int V_84 , V_273 , V_274 ;
int V_239 = - V_133 ;
T_6 V_275 , V_276 ;
F_57 ( 7 , L_42 , V_277 , F_131 ( V_278 ) ) ;
F_57 ( 7 , L_43 ,
sizeof( struct F_44 ) ) ;
if ( ! V_9 -> V_37 ) {
V_273 = F_132 ( F_133 ( V_9 ) , 1 , V_279 ) ;
V_9 -> V_47 = V_273 - 1 ;
} else
V_273 = V_9 -> V_47 + 1 ;
if ( V_229 -> V_230 == V_280 ) {
V_229 -> V_230 = V_86 ;
V_229 -> V_236 . V_95 = F_134 ( V_281 ) ;
}
if ( ! V_229 -> V_234 )
V_229 -> V_234 = V_282 ;
if ( ! V_229 -> V_243 )
V_229 -> V_243 = 1 ;
V_200 = F_95 ( V_9 -> V_201 , V_229 -> V_242 ) ;
if ( ! V_200 ) {
F_45 ( L_44 , V_229 -> V_242 ) ;
return - V_202 ;
}
V_274 = ( V_113 == V_229 -> V_230 ) ?
sizeof( struct V_283 ) + sizeof( struct V_284 ) :
sizeof( struct V_285 ) + sizeof( struct V_284 ) ;
V_275 = ( V_63 == V_286 ) ?
F_132 ( V_200 -> V_275 , 1500U , 65535U ) : 1500U ;
V_276 = ( V_63 == V_286 ) ? 1024 : 1 ;
if ( V_229 -> V_269 )
V_229 -> V_269 = F_86 (unsigned int,
c->sync_maxlen, min_mtu,
65535 - hlen) ;
else
V_229 -> V_269 = V_275 - V_274 ;
if ( V_63 == V_38 ) {
if ( V_9 -> V_11 )
return - V_287 ;
V_9 -> V_27 = * V_229 ;
V_111 = L_45 ;
F_130 = F_119 ;
} else if ( V_63 == V_286 ) {
if ( V_9 -> V_288 )
return - V_287 ;
V_9 -> V_172 = * V_229 ;
V_111 = L_46 ;
F_130 = F_126 ;
} else {
return - V_156 ;
}
if ( V_63 == V_38 ) {
struct V_10 * V_11 ;
V_9 -> V_11 = F_135 ( V_273 * sizeof( V_9 -> V_11 [ 0 ] ) , V_289 ) ;
if ( ! V_9 -> V_11 )
goto V_164;
V_11 = V_9 -> V_11 ;
for ( V_84 = 0 ; V_84 < V_273 ; V_84 ++ , V_11 ++ ) {
F_136 ( & V_11 -> V_14 ) ;
V_11 -> V_18 = 0 ;
V_11 -> V_19 = 0 ;
F_137 ( & V_11 -> V_39 ,
F_116 ) ;
V_11 -> V_9 = V_9 ;
}
} else {
V_271 = F_135 ( V_273 * sizeof( struct V_270 * ) ,
V_289 ) ;
if ( ! V_271 )
goto V_164;
}
V_264 = NULL ;
for ( V_84 = 0 ; V_84 < V_273 ; V_84 ++ ) {
if ( V_63 == V_38 )
V_174 = F_103 ( V_9 , V_84 ) ;
else
V_174 = F_108 ( V_9 , V_84 , V_200 -> V_204 ) ;
if ( F_138 ( V_174 ) ) {
V_239 = F_139 ( V_174 ) ;
goto V_290;
}
V_264 = F_13 ( sizeof( * V_264 ) , V_289 ) ;
if ( ! V_264 )
goto V_291;
V_264 -> V_9 = V_9 ;
V_264 -> V_174 = V_174 ;
if ( V_63 == V_286 ) {
V_264 -> V_268 = F_13 ( V_9 -> V_172 . V_269 ,
V_289 ) ;
if ( ! V_264 -> V_268 )
goto V_290;
} else {
V_264 -> V_268 = NULL ;
}
V_264 -> V_84 = V_84 ;
V_272 = F_140 ( F_130 , V_264 , V_111 , V_9 -> V_292 , V_84 ) ;
if ( F_138 ( V_272 ) ) {
V_239 = F_139 ( V_272 ) ;
goto V_290;
}
V_264 = NULL ;
if ( V_63 == V_38 )
V_9 -> V_11 [ V_84 ] . V_42 = V_272 ;
else
V_271 [ V_84 ] = V_272 ;
}
if ( V_63 == V_286 )
V_9 -> V_288 = V_271 ;
F_6 ( & V_9 -> V_43 ) ;
V_9 -> V_37 |= V_63 ;
F_11 ( & V_9 -> V_43 ) ;
F_141 () ;
return 0 ;
V_291:
F_107 ( V_174 ) ;
V_290:
if ( V_264 ) {
F_107 ( V_264 -> V_174 ) ;
F_15 ( V_264 -> V_268 ) ;
F_15 ( V_264 ) ;
}
V_273 = V_84 ;
while ( V_273 -- > 0 ) {
if ( V_63 == V_38 )
F_142 ( V_9 -> V_11 [ V_273 ] . V_42 ) ;
else
F_142 ( V_271 [ V_273 ] ) ;
}
F_15 ( V_271 ) ;
V_164:
if ( ! ( V_9 -> V_37 & V_38 ) ) {
F_15 ( V_9 -> V_11 ) ;
V_9 -> V_11 = NULL ;
}
return V_239 ;
}
int F_143 ( struct V_8 * V_9 , int V_63 )
{
struct V_270 * * V_271 ;
int V_84 ;
int V_163 = - V_156 ;
F_57 ( 7 , L_42 , V_277 , F_131 ( V_278 ) ) ;
if ( V_63 == V_38 ) {
if ( ! V_9 -> V_11 )
return - V_293 ;
F_6 ( & V_9 -> V_43 ) ;
F_19 ( & V_9 -> V_13 ) ;
V_9 -> V_37 &= ~ V_38 ;
F_25 ( & V_9 -> V_13 ) ;
F_11 ( & V_9 -> V_43 ) ;
V_163 = 0 ;
for ( V_84 = V_9 -> V_47 ; V_84 >= 0 ; V_84 -- ) {
struct V_10 * V_11 = & V_9 -> V_11 [ V_84 ] ;
int V_211 ;
F_120 ( L_47 ,
F_131 ( V_11 -> V_42 ) ) ;
F_144 ( & V_11 -> V_39 ) ;
V_211 = F_142 ( V_11 -> V_42 ) ;
if ( V_163 >= 0 )
V_163 = V_211 ;
}
F_15 ( V_9 -> V_11 ) ;
V_9 -> V_11 = NULL ;
} else if ( V_63 == V_286 ) {
if ( ! V_9 -> V_288 )
return - V_293 ;
V_9 -> V_37 &= ~ V_286 ;
V_271 = V_9 -> V_288 ;
V_163 = 0 ;
for ( V_84 = V_9 -> V_47 ; V_84 >= 0 ; V_84 -- ) {
int V_211 ;
F_120 ( L_48 ,
F_131 ( V_271 [ V_84 ] ) ) ;
V_211 = F_142 ( V_271 [ V_84 ] ) ;
if ( V_163 >= 0 )
V_163 = V_211 ;
}
F_15 ( V_271 ) ;
V_9 -> V_288 = NULL ;
}
F_145 () ;
return V_163 ;
}
int T_7 F_146 ( struct V_8 * V_9 )
{
F_147 ( & V_9 -> V_294 , L_49 , & V_295 ) ;
F_148 ( & V_9 -> V_13 ) ;
F_148 ( & V_9 -> V_43 ) ;
return 0 ;
}
void F_149 ( struct V_8 * V_9 )
{
int V_163 ;
F_150 ( & V_9 -> V_294 ) ;
V_163 = F_143 ( V_9 , V_38 ) ;
if ( V_163 && V_163 != - V_293 )
F_45 ( L_50 ) ;
V_163 = F_143 ( V_9 , V_286 ) ;
if ( V_163 && V_163 != - V_293 )
F_45 ( L_51 ) ;
F_151 ( & V_9 -> V_294 ) ;
}
