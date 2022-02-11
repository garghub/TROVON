static inline bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 & V_4 ? false :
F_2 () ;
}
static long F_3 ( struct V_1 * V_2 , int T_1 * V_5 )
{
int V_6 = ! ! ( V_2 -> V_3 & V_4 ) ;
if ( F_4 ( V_6 , V_5 ) )
return - V_7 ;
return 0 ;
}
static long F_5 ( struct V_1 * V_2 , int T_1 * V_5 )
{
int V_6 ;
if ( F_6 ( V_6 , V_5 ) )
return - V_7 ;
if ( V_6 )
V_2 -> V_3 |= V_4 ;
else
V_2 -> V_3 &= ~ V_4 ;
return 0 ;
}
static inline bool F_1 ( struct V_1 * V_2 )
{
return F_2 () ;
}
static long F_3 ( struct V_1 * V_2 , int T_1 * V_5 )
{
return - V_8 ;
}
static long F_5 ( struct V_1 * V_2 , int T_1 * V_5 )
{
return - V_8 ;
}
static inline bool F_7 ( struct V_1 * V_2 )
{
return V_2 -> V_3 & V_9 ||
F_1 ( V_2 ) ;
}
static inline T_2 F_8 ( struct V_1 * V_2 , T_3 V_10 )
{
return F_9 ( F_7 ( V_2 ) , V_10 ) ;
}
static inline T_3 F_10 ( struct V_1 * V_2 , T_2 V_10 )
{
return F_11 ( F_7 ( V_2 ) , V_10 ) ;
}
static inline T_4 F_12 ( T_4 V_11 )
{
return V_11 & 0x3ff ;
}
static struct V_12 * F_13 ( struct V_13 * V_14 , T_4 V_11 )
{
struct V_12 * V_15 ;
F_14 (e, head, hash_link) {
if ( V_15 -> V_11 == V_11 )
return V_15 ;
}
return NULL ;
}
static struct V_12 * F_15 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
T_4 V_11 , T_2 V_16 )
{
struct V_12 * V_15 = F_16 ( sizeof( * V_15 ) , V_17 ) ;
if ( V_15 ) {
F_17 ( V_18 , V_2 , L_1 ,
V_11 , V_16 ) ;
V_15 -> V_19 = V_20 ;
V_15 -> V_11 = V_11 ;
V_15 -> V_21 = 0 ;
V_15 -> V_16 = V_16 ;
V_15 -> V_2 = V_2 ;
F_18 ( & V_15 -> V_22 , V_14 ) ;
++ V_2 -> V_23 ;
}
return V_15 ;
}
static void F_19 ( struct V_1 * V_2 , struct V_12 * V_15 )
{
F_17 ( V_18 , V_2 , L_2 ,
V_15 -> V_11 , V_15 -> V_16 ) ;
F_20 ( & V_15 -> V_22 ) ;
F_21 ( V_15 , V_24 ) ;
-- V_2 -> V_23 ;
}
static void F_22 ( struct V_1 * V_2 )
{
int V_25 ;
F_23 ( & V_2 -> V_26 ) ;
for ( V_25 = 0 ; V_25 < V_27 ; V_25 ++ ) {
struct V_12 * V_15 ;
struct V_28 * V_29 ;
F_24 (e, n, &tun->flows[i], hash_link)
F_19 ( V_2 , V_15 ) ;
}
F_25 ( & V_2 -> V_26 ) ;
}
static void F_26 ( struct V_1 * V_2 , T_2 V_16 )
{
int V_25 ;
F_23 ( & V_2 -> V_26 ) ;
for ( V_25 = 0 ; V_25 < V_27 ; V_25 ++ ) {
struct V_12 * V_15 ;
struct V_28 * V_29 ;
F_24 (e, n, &tun->flows[i], hash_link) {
if ( V_15 -> V_16 == V_16 )
F_19 ( V_2 , V_15 ) ;
}
}
F_25 ( & V_2 -> V_26 ) ;
}
static void F_27 ( unsigned long V_30 )
{
struct V_1 * V_2 = (struct V_1 * ) V_30 ;
unsigned long V_31 = V_2 -> V_32 ;
unsigned long V_33 = V_20 + V_31 ;
unsigned long V_34 = 0 ;
int V_25 ;
F_17 ( V_18 , V_2 , L_3 ) ;
F_23 ( & V_2 -> V_26 ) ;
for ( V_25 = 0 ; V_25 < V_27 ; V_25 ++ ) {
struct V_12 * V_15 ;
struct V_28 * V_29 ;
F_24 (e, n, &tun->flows[i], hash_link) {
unsigned long V_35 ;
V_34 ++ ;
V_35 = V_15 -> V_19 + V_31 ;
if ( F_28 ( V_35 , V_20 ) )
F_19 ( V_2 , V_15 ) ;
else if ( F_29 ( V_35 , V_33 ) )
V_33 = V_35 ;
}
}
if ( V_34 )
F_30 ( & V_2 -> V_36 , F_31 ( V_33 ) ) ;
F_25 ( & V_2 -> V_26 ) ;
}
static void F_32 ( struct V_1 * V_2 , T_4 V_11 ,
struct V_37 * V_38 )
{
struct V_13 * V_14 ;
struct V_12 * V_15 ;
unsigned long V_31 = V_2 -> V_32 ;
T_2 V_16 = V_38 -> V_16 ;
if ( ! V_11 )
return;
else
V_14 = & V_2 -> V_39 [ F_12 ( V_11 ) ] ;
F_33 () ;
if ( V_2 -> V_40 == 1 || V_38 -> V_41 )
goto V_42;
V_15 = F_13 ( V_14 , V_11 ) ;
if ( F_34 ( V_15 ) ) {
V_15 -> V_16 = V_16 ;
V_15 -> V_19 = V_20 ;
F_35 ( V_15 -> V_21 ) ;
} else {
F_23 ( & V_2 -> V_26 ) ;
if ( ! F_13 ( V_14 , V_11 ) &&
V_2 -> V_23 < V_43 )
F_15 ( V_2 , V_14 , V_11 , V_16 ) ;
if ( ! F_36 ( & V_2 -> V_36 ) )
F_30 ( & V_2 -> V_36 ,
F_31 ( V_20 + V_31 ) ) ;
F_25 ( & V_2 -> V_26 ) ;
}
V_42:
F_37 () ;
}
static inline void F_38 ( struct V_12 * V_15 , T_4 V_44 )
{
if ( F_39 ( V_15 -> V_21 != V_44 ) )
V_15 -> V_21 = V_44 ;
}
static T_2 F_40 ( struct V_45 * V_46 , struct V_47 * V_48 ,
void * V_49 , T_5 V_50 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
struct V_12 * V_15 ;
T_4 V_51 = 0 ;
T_4 V_40 = 0 ;
F_33 () ;
V_40 = F_42 ( V_2 -> V_40 ) ;
V_51 = F_43 ( V_48 ) ;
if ( V_51 ) {
V_15 = F_13 ( & V_2 -> V_39 [ F_12 ( V_51 ) ] , V_51 ) ;
if ( V_15 ) {
F_38 ( V_15 , V_51 ) ;
V_51 = V_15 -> V_16 ;
} else
V_51 = ( ( V_52 ) V_51 * V_40 ) >> 32 ;
} else if ( F_34 ( F_44 ( V_48 ) ) ) {
V_51 = F_45 ( V_48 ) ;
while ( F_39 ( V_51 >= V_40 ) )
V_51 -= V_40 ;
}
F_37 () ;
return V_51 ;
}
static inline bool F_46 ( struct V_1 * V_2 )
{
const struct V_53 * V_53 = F_47 () ;
struct V_54 * V_54 = F_48 ( V_2 -> V_46 ) ;
return ( ( F_49 ( V_2 -> V_55 ) && ! F_50 ( V_53 -> V_56 , V_2 -> V_55 ) ) ||
( F_51 ( V_2 -> V_57 ) && ! F_52 ( V_2 -> V_57 ) ) ) &&
! F_53 ( V_54 -> V_58 , V_59 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
F_55 ( V_2 -> V_46 , V_2 -> V_40 ) ;
F_56 ( V_2 -> V_46 , V_2 -> V_40 ) ;
}
static void F_57 ( struct V_1 * V_2 , struct V_37 * V_38 )
{
V_38 -> V_41 = V_2 ;
F_58 ( & V_38 -> V_60 , & V_2 -> V_61 ) ;
++ V_2 -> V_62 ;
}
static struct V_1 * F_59 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = V_38 -> V_41 ;
V_38 -> V_41 = NULL ;
F_60 ( & V_38 -> V_60 ) ;
-- V_2 -> V_62 ;
return V_2 ;
}
static void F_61 ( struct V_37 * V_38 )
{
struct V_47 * V_48 ;
while ( ( V_48 = F_62 ( & V_38 -> V_63 ) ) != NULL )
F_63 ( V_48 ) ;
F_64 ( & V_38 -> V_64 . V_65 ) ;
}
static void F_65 ( struct V_37 * V_38 , bool V_66 )
{
struct V_37 * V_67 ;
struct V_1 * V_2 ;
V_2 = F_66 ( V_38 -> V_2 ) ;
if ( V_2 && ! V_38 -> V_41 ) {
T_2 V_68 = V_38 -> V_16 ;
F_67 ( V_68 >= V_2 -> V_40 ) ;
F_68 ( V_2 -> V_69 [ V_68 ] ,
V_2 -> V_69 [ V_2 -> V_40 - 1 ] ) ;
V_67 = F_66 ( V_2 -> V_69 [ V_68 ] ) ;
V_67 -> V_16 = V_68 ;
-- V_2 -> V_40 ;
if ( V_66 ) {
F_69 ( V_38 -> V_2 , NULL ) ;
F_70 ( & V_38 -> V_64 ) ;
} else
F_57 ( V_2 , V_38 ) ;
F_71 () ;
F_26 ( V_2 , V_2 -> V_40 + 1 ) ;
F_61 ( V_38 ) ;
F_54 ( V_2 ) ;
} else if ( V_38 -> V_41 && V_66 ) {
V_2 = F_59 ( V_38 ) ;
F_70 ( & V_38 -> V_64 ) ;
}
if ( V_66 ) {
if ( V_2 && V_2 -> V_40 == 0 && V_2 -> V_62 == 0 ) {
F_72 ( V_2 -> V_46 ) ;
if ( ! ( V_2 -> V_3 & V_70 ) &&
V_2 -> V_46 -> V_71 == V_72 )
F_73 ( V_2 -> V_46 ) ;
}
if ( V_2 )
F_74 ( & V_38 -> V_63 ) ;
F_70 ( & V_38 -> V_64 ) ;
}
}
static void F_75 ( struct V_37 * V_38 , bool V_66 )
{
F_76 () ;
F_65 ( V_38 , V_66 ) ;
F_77 () ;
}
static void F_78 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
struct V_37 * V_38 , * V_73 ;
int V_25 , V_29 = V_2 -> V_40 ;
for ( V_25 = 0 ; V_25 < V_29 ; V_25 ++ ) {
V_38 = F_66 ( V_2 -> V_69 [ V_25 ] ) ;
F_67 ( ! V_38 ) ;
V_38 -> V_74 . V_64 -> V_75 = V_76 ;
V_38 -> V_74 . V_64 -> V_77 ( V_38 -> V_74 . V_64 ) ;
F_69 ( V_38 -> V_2 , NULL ) ;
-- V_2 -> V_40 ;
}
F_79 (tfile, &tun->disabled, next) {
V_38 -> V_74 . V_64 -> V_75 = V_76 ;
V_38 -> V_74 . V_64 -> V_77 ( V_38 -> V_74 . V_64 ) ;
F_69 ( V_38 -> V_2 , NULL ) ;
}
F_67 ( V_2 -> V_40 != 0 ) ;
F_71 () ;
for ( V_25 = 0 ; V_25 < V_29 ; V_25 ++ ) {
V_38 = F_66 ( V_2 -> V_69 [ V_25 ] ) ;
F_61 ( V_38 ) ;
F_70 ( & V_38 -> V_64 ) ;
}
F_80 (tfile, tmp, &tun->disabled, next) {
F_59 ( V_38 ) ;
F_61 ( V_38 ) ;
F_70 ( & V_38 -> V_64 ) ;
}
F_67 ( V_2 -> V_62 != 0 ) ;
if ( V_2 -> V_3 & V_70 )
F_81 ( V_78 ) ;
}
static int F_82 ( struct V_1 * V_2 , struct V_79 * V_79 , bool V_80 )
{
struct V_37 * V_38 = V_79 -> V_81 ;
struct V_45 * V_46 = V_2 -> V_46 ;
int V_82 ;
V_82 = F_83 ( V_38 -> V_74 . V_64 , V_2 -> V_83 ) ;
if ( V_82 < 0 )
goto V_84;
V_82 = - V_8 ;
if ( F_66 ( V_38 -> V_2 ) && ! V_38 -> V_41 )
goto V_84;
V_82 = - V_85 ;
if ( ! ( V_2 -> V_3 & V_86 ) && V_2 -> V_40 == 1 )
goto V_84;
V_82 = - V_87 ;
if ( ! V_38 -> V_41 &&
V_2 -> V_40 + V_2 -> V_62 == V_88 )
goto V_84;
V_82 = 0 ;
if ( ! V_80 && ( V_2 -> V_89 == true ) ) {
F_84 ( V_38 -> V_74 . V_64 ) ;
V_82 = F_85 ( & V_2 -> V_90 , V_38 -> V_74 . V_64 ) ;
F_86 ( V_38 -> V_74 . V_64 ) ;
if ( ! V_82 )
goto V_84;
}
if ( ! V_38 -> V_41 &&
F_87 ( & V_38 -> V_63 , V_46 -> V_91 , V_92 ) ) {
V_82 = - V_93 ;
goto V_84;
}
V_38 -> V_16 = V_2 -> V_40 ;
V_38 -> V_74 . V_64 -> V_75 &= ~ V_76 ;
F_68 ( V_38 -> V_2 , V_2 ) ;
F_68 ( V_2 -> V_69 [ V_2 -> V_40 ] , V_38 ) ;
V_2 -> V_40 ++ ;
if ( V_38 -> V_41 )
F_59 ( V_38 ) ;
else
F_88 ( & V_38 -> V_64 ) ;
F_54 ( V_2 ) ;
V_84:
return V_82 ;
}
static struct V_1 * F_89 ( struct V_37 * V_38 )
{
struct V_1 * V_2 ;
F_33 () ;
V_2 = F_90 ( V_38 -> V_2 ) ;
if ( V_2 )
F_91 ( V_2 -> V_46 ) ;
F_37 () ;
return V_2 ;
}
static struct V_1 * F_92 ( struct V_79 * V_79 )
{
return F_89 ( V_79 -> V_81 ) ;
}
static void F_93 ( struct V_1 * V_2 )
{
F_94 ( V_2 -> V_46 ) ;
}
static void F_95 ( T_4 * V_94 , const T_6 * V_95 )
{
int V_29 = F_96 ( V_96 , V_95 ) >> 26 ;
V_94 [ V_29 >> 5 ] |= ( 1 << ( V_29 & 31 ) ) ;
}
static unsigned int F_97 ( const T_4 * V_94 , const T_6 * V_95 )
{
int V_29 = F_96 ( V_96 , V_95 ) >> 26 ;
return V_94 [ V_29 >> 5 ] & ( 1 << ( V_29 & 31 ) ) ;
}
static int F_98 ( struct V_97 * V_98 , void T_1 * V_99 )
{
struct { T_6 V_100 [ V_96 ] ; } * V_95 ;
struct V_101 V_102 ;
int V_82 , V_103 , V_29 , V_104 ;
if ( F_99 ( & V_102 , V_99 , sizeof( V_102 ) ) )
return - V_7 ;
if ( ! V_102 . V_34 ) {
V_98 -> V_34 = 0 ;
return 0 ;
}
V_103 = V_96 * V_102 . V_34 ;
V_95 = F_100 ( V_99 + sizeof( V_102 ) , V_103 ) ;
if ( F_101 ( V_95 ) )
return F_102 ( V_95 ) ;
V_98 -> V_34 = 0 ;
F_103 () ;
for ( V_29 = 0 ; V_29 < V_102 . V_34 && V_29 < V_105 ; V_29 ++ )
memcpy ( V_98 -> V_95 [ V_29 ] , V_95 [ V_29 ] . V_100 , V_96 ) ;
V_104 = V_29 ;
memset ( V_98 -> V_94 , 0 , sizeof( V_98 -> V_94 ) ) ;
for (; V_29 < V_102 . V_34 ; V_29 ++ ) {
if ( ! F_104 ( V_95 [ V_29 ] . V_100 ) ) {
V_82 = 0 ;
goto V_106;
}
F_95 ( V_98 -> V_94 , V_95 [ V_29 ] . V_100 ) ;
}
if ( ( V_102 . V_3 & V_107 ) )
memset ( V_98 -> V_94 , ~ 0 , sizeof( V_98 -> V_94 ) ) ;
F_103 () ;
V_98 -> V_34 = V_104 ;
V_82 = V_104 ;
V_106:
F_105 ( V_95 ) ;
return V_82 ;
}
static int F_106 ( struct V_97 * V_98 , const struct V_47 * V_48 )
{
struct V_108 * V_109 = (struct V_108 * ) V_48 -> V_30 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_98 -> V_34 ; V_25 ++ )
if ( F_107 ( V_109 -> V_110 , V_98 -> V_95 [ V_25 ] ) )
return 1 ;
if ( F_104 ( V_109 -> V_110 ) )
return F_97 ( V_98 -> V_94 , V_109 -> V_110 ) ;
return 0 ;
}
static int F_108 ( struct V_97 * V_98 , const struct V_47 * V_48 )
{
if ( ! V_98 -> V_34 )
return 1 ;
return F_106 ( V_98 , V_48 ) ;
}
static void F_109 ( struct V_45 * V_46 )
{
F_78 ( V_46 ) ;
}
static int F_110 ( struct V_45 * V_46 )
{
F_111 ( V_46 ) ;
return 0 ;
}
static int F_112 ( struct V_45 * V_46 )
{
F_113 ( V_46 ) ;
return 0 ;
}
static T_7 F_114 ( struct V_47 * V_48 , struct V_45 * V_46 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
int V_51 = V_48 -> V_111 ;
struct V_37 * V_38 ;
T_4 V_40 = 0 ;
F_33 () ;
V_38 = F_90 ( V_2 -> V_69 [ V_51 ] ) ;
V_40 = F_42 ( V_2 -> V_40 ) ;
if ( V_51 >= V_40 )
goto V_112;
#ifdef F_115
if ( V_40 == 1 && F_116 ( & V_113 ) ) {
T_8 V_11 ;
V_11 = F_43 ( V_48 ) ;
if ( V_11 ) {
struct V_12 * V_15 ;
V_15 = F_13 ( & V_2 -> V_39 [ F_12 ( V_11 ) ] ,
V_11 ) ;
if ( V_15 )
F_38 ( V_15 , V_11 ) ;
}
}
#endif
F_17 ( V_18 , V_2 , L_4 , V_48 -> V_114 ) ;
F_67 ( ! V_38 ) ;
if ( ! F_108 ( & V_2 -> V_115 , V_48 ) )
goto V_112;
if ( V_38 -> V_74 . V_64 -> V_116 &&
V_116 ( V_38 -> V_74 . V_64 , V_48 ) )
goto V_112;
if ( F_117 ( & V_38 -> V_74 . V_64 -> V_117 ) * V_40
>= V_46 -> V_91 )
goto V_112;
if ( F_39 ( F_118 ( V_48 , V_17 ) ) )
goto V_112;
F_119 ( V_48 ) ;
F_120 ( V_48 ) ;
F_121 ( V_48 ) ;
if ( F_122 ( & V_38 -> V_63 , V_48 ) )
goto V_112;
if ( V_38 -> V_3 & V_118 )
F_123 ( & V_38 -> V_119 , V_120 , V_121 ) ;
V_38 -> V_74 . V_64 -> V_77 ( V_38 -> V_74 . V_64 ) ;
F_37 () ;
return V_122 ;
V_112:
F_124 ( V_2 -> V_123 -> V_124 ) ;
F_125 ( V_48 ) ;
F_63 ( V_48 ) ;
F_37 () ;
return V_125 ;
}
static void F_126 ( struct V_45 * V_46 )
{
}
static int
F_127 ( struct V_45 * V_46 , int V_126 )
{
if ( V_126 < V_127 || V_126 + V_46 -> V_128 > V_129 )
return - V_8 ;
V_46 -> V_130 = V_126 ;
return 0 ;
}
static T_9 F_128 ( struct V_45 * V_46 ,
T_9 V_131 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
return ( V_131 & V_2 -> V_132 ) | ( V_131 & ~ V_133 ) ;
}
static void F_129 ( struct V_45 * V_46 )
{
return;
}
static void F_130 ( struct V_45 * V_46 , int V_134 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
if ( V_134 < V_135 )
V_134 = V_135 ;
V_2 -> V_136 = V_134 ;
}
static struct V_137 *
F_131 ( struct V_45 * V_46 , struct V_137 * V_138 )
{
T_4 V_139 = 0 , V_124 = 0 , V_140 = 0 ;
struct V_1 * V_2 = F_41 ( V_46 ) ;
struct V_141 * V_142 ;
int V_25 ;
F_132 (i) {
V_52 V_143 , V_144 , V_145 , V_146 ;
unsigned int V_147 ;
V_142 = F_133 ( V_2 -> V_123 , V_25 ) ;
do {
V_147 = F_134 ( & V_142 -> V_148 ) ;
V_143 = V_142 -> V_149 ;
V_144 = V_142 -> V_150 ;
V_145 = V_142 -> V_151 ;
V_146 = V_142 -> V_152 ;
} while ( F_135 ( & V_142 -> V_148 , V_147 ) );
V_138 -> V_149 += V_143 ;
V_138 -> V_150 += V_144 ;
V_138 -> V_151 += V_145 ;
V_138 -> V_152 += V_146 ;
V_139 += V_142 -> V_139 ;
V_140 += V_142 -> V_140 ;
V_124 += V_142 -> V_124 ;
}
V_138 -> V_139 = V_139 ;
V_138 -> V_140 = V_140 ;
V_138 -> V_124 = V_124 ;
return V_138 ;
}
static void F_136 ( struct V_1 * V_2 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_27 ; V_25 ++ )
F_137 ( & V_2 -> V_39 [ V_25 ] ) ;
V_2 -> V_32 = V_153 ;
F_138 ( & V_2 -> V_36 , F_27 , ( unsigned long ) V_2 ) ;
F_30 ( & V_2 -> V_36 ,
F_31 ( V_20 + V_2 -> V_32 ) ) ;
}
static void F_139 ( struct V_1 * V_2 )
{
F_140 ( & V_2 -> V_36 ) ;
F_22 ( V_2 ) ;
}
static void F_141 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
switch ( V_2 -> V_3 & V_154 ) {
case V_155 :
V_46 -> V_156 = & V_157 ;
V_46 -> V_128 = 0 ;
V_46 -> V_158 = 0 ;
V_46 -> V_130 = 1500 ;
V_46 -> type = V_159 ;
V_46 -> V_3 = V_160 | V_161 | V_162 ;
break;
case V_163 :
V_46 -> V_156 = & V_164 ;
F_142 ( V_46 ) ;
V_46 -> V_165 &= ~ V_166 ;
V_46 -> V_165 |= V_167 ;
F_143 ( V_46 ) ;
break;
}
}
static unsigned int F_144 ( struct V_79 * V_79 , T_10 * V_168 )
{
struct V_37 * V_38 = V_79 -> V_81 ;
struct V_1 * V_2 = F_89 ( V_38 ) ;
struct V_169 * V_64 ;
unsigned int V_94 = 0 ;
if ( ! V_2 )
return V_170 ;
V_64 = V_38 -> V_74 . V_64 ;
F_17 ( V_18 , V_2 , L_5 ) ;
F_145 ( V_79 , F_146 ( V_64 ) , V_168 ) ;
if ( ! F_147 ( & V_38 -> V_63 ) )
V_94 |= V_171 | V_172 ;
if ( F_148 ( V_64 ) ||
( ! F_149 ( V_173 , & V_64 -> V_174 -> V_3 ) &&
F_148 ( V_64 ) ) )
V_94 |= V_175 | V_176 ;
if ( V_2 -> V_46 -> V_71 != V_72 )
V_94 = V_170 ;
F_93 ( V_2 ) ;
return V_94 ;
}
static struct V_47 * F_150 ( struct V_37 * V_38 ,
T_11 V_177 , T_11 V_114 ,
T_11 V_178 , int V_179 )
{
struct V_169 * V_64 = V_38 -> V_74 . V_64 ;
struct V_47 * V_48 ;
int V_82 ;
if ( V_177 + V_114 < V_180 || ! V_178 )
V_178 = V_114 ;
V_48 = F_151 ( V_64 , V_177 + V_178 , V_114 - V_178 , V_179 ,
& V_82 , 0 ) ;
if ( ! V_48 )
return F_152 ( V_82 ) ;
F_153 ( V_48 , V_177 ) ;
F_154 ( V_48 , V_178 ) ;
V_48 -> V_181 = V_114 - V_178 ;
V_48 -> V_114 += V_114 - V_178 ;
return V_48 ;
}
static T_12 F_155 ( struct V_1 * V_2 , struct V_37 * V_38 ,
void * V_182 , struct V_183 * V_184 ,
int V_179 )
{
struct V_185 V_186 = { 0 , F_156 (ETH_P_IP) } ;
struct V_47 * V_48 ;
T_11 V_187 = F_157 ( V_184 ) ;
T_11 V_114 = V_187 , V_136 = V_2 -> V_136 , V_178 ;
struct V_188 V_189 = { 0 } ;
struct V_141 * V_138 ;
int V_190 ;
int V_191 ;
bool V_192 = false ;
int V_82 ;
T_4 V_11 ;
T_12 V_29 ;
if ( ! ( V_2 -> V_46 -> V_3 & V_193 ) )
return - V_194 ;
if ( ! ( V_2 -> V_3 & V_195 ) ) {
if ( V_114 < sizeof( V_186 ) )
return - V_8 ;
V_114 -= sizeof( V_186 ) ;
V_29 = F_158 ( & V_186 , sizeof( V_186 ) , V_184 ) ;
if ( V_29 != sizeof( V_186 ) )
return - V_7 ;
}
if ( V_2 -> V_3 & V_196 ) {
if ( V_114 < V_2 -> V_197 )
return - V_8 ;
V_114 -= V_2 -> V_197 ;
V_29 = F_158 ( & V_189 , sizeof( V_189 ) , V_184 ) ;
if ( V_29 != sizeof( V_189 ) )
return - V_7 ;
if ( ( V_189 . V_3 & V_198 ) &&
F_8 ( V_2 , V_189 . V_199 ) + F_8 ( V_2 , V_189 . V_200 ) + 2 > F_8 ( V_2 , V_189 . V_201 ) )
V_189 . V_201 = F_10 ( V_2 , F_8 ( V_2 , V_189 . V_199 ) + F_8 ( V_2 , V_189 . V_200 ) + 2 ) ;
if ( F_8 ( V_2 , V_189 . V_201 ) > V_114 )
return - V_8 ;
F_159 ( V_184 , V_2 -> V_197 - sizeof( V_189 ) ) ;
}
if ( ( V_2 -> V_3 & V_154 ) == V_163 ) {
V_136 += V_202 ;
if ( F_39 ( V_114 < V_203 ||
( V_189 . V_201 && F_8 ( V_2 , V_189 . V_201 ) < V_203 ) ) )
return - V_8 ;
}
V_190 = F_160 ( V_136 ) ;
if ( V_182 ) {
struct V_183 V_25 = * V_184 ;
V_191 = V_189 . V_201 ? F_8 ( V_2 , V_189 . V_201 ) : V_204 ;
if ( V_191 > V_190 )
V_191 = V_190 ;
V_178 = V_191 ;
F_159 ( & V_25 , V_191 ) ;
if ( F_161 ( & V_25 , V_205 ) <= V_206 )
V_192 = true ;
}
if ( ! V_192 ) {
V_191 = V_114 ;
if ( F_8 ( V_2 , V_189 . V_201 ) > V_190 )
V_178 = V_190 ;
else
V_178 = F_8 ( V_2 , V_189 . V_201 ) ;
}
V_48 = F_150 ( V_38 , V_136 , V_191 , V_178 , V_179 ) ;
if ( F_101 ( V_48 ) ) {
if ( F_102 ( V_48 ) != - V_207 )
F_124 ( V_2 -> V_123 -> V_139 ) ;
return F_102 ( V_48 ) ;
}
if ( V_192 )
V_82 = F_162 ( V_48 , V_184 ) ;
else
V_82 = F_163 ( V_48 , 0 , V_184 , V_114 ) ;
if ( V_82 ) {
F_124 ( V_2 -> V_123 -> V_139 ) ;
F_63 ( V_48 ) ;
return - V_7 ;
}
V_82 = F_164 ( V_48 , & V_189 , F_7 ( V_2 ) ) ;
if ( V_82 ) {
F_124 ( V_2 -> V_123 -> V_140 ) ;
F_63 ( V_48 ) ;
return - V_8 ;
}
switch ( V_2 -> V_3 & V_154 ) {
case V_155 :
if ( V_2 -> V_3 & V_195 ) {
switch ( V_48 -> V_30 [ 0 ] & 0xf0 ) {
case 0x40 :
V_186 . V_208 = F_165 ( V_209 ) ;
break;
case 0x60 :
V_186 . V_208 = F_165 ( V_210 ) ;
break;
default:
F_124 ( V_2 -> V_123 -> V_139 ) ;
F_63 ( V_48 ) ;
return - V_8 ;
}
}
F_166 ( V_48 ) ;
V_48 -> V_211 = V_186 . V_208 ;
V_48 -> V_46 = V_2 -> V_46 ;
break;
case V_163 :
V_48 -> V_211 = F_167 ( V_48 , V_2 -> V_46 ) ;
break;
}
if ( V_192 ) {
F_168 ( V_48 ) -> V_212 = V_182 ;
F_168 ( V_48 ) -> V_213 |= V_214 ;
F_168 ( V_48 ) -> V_213 |= V_215 ;
} else if ( V_182 ) {
struct V_216 * V_217 = V_182 ;
V_217 -> V_218 ( V_217 , false ) ;
}
F_169 ( V_48 ) ;
F_170 ( V_48 , 0 ) ;
V_11 = F_43 ( V_48 ) ;
F_171 ( V_48 ) ;
V_138 = F_172 ( V_2 -> V_123 ) ;
F_173 ( & V_138 -> V_148 ) ;
V_138 -> V_149 ++ ;
V_138 -> V_150 += V_114 ;
F_174 ( & V_138 -> V_148 ) ;
F_175 ( V_138 ) ;
F_32 ( V_2 , V_11 , V_38 ) ;
return V_187 ;
}
static T_12 F_176 ( struct V_219 * V_220 , struct V_183 * V_184 )
{
struct V_79 * V_79 = V_220 -> V_221 ;
struct V_1 * V_2 = F_92 ( V_79 ) ;
struct V_37 * V_38 = V_79 -> V_81 ;
T_12 V_222 ;
if ( ! V_2 )
return - V_223 ;
V_222 = F_155 ( V_2 , V_38 , NULL , V_184 , V_79 -> V_224 & V_225 ) ;
F_93 ( V_2 ) ;
return V_222 ;
}
static T_12 F_177 ( struct V_1 * V_2 ,
struct V_37 * V_38 ,
struct V_47 * V_48 ,
struct V_183 * V_226 )
{
struct V_185 V_186 = { 0 , V_48 -> V_211 } ;
struct V_141 * V_138 ;
T_12 V_227 ;
int V_228 = 0 ;
int V_229 = 0 ;
int V_197 = 0 ;
if ( F_178 ( V_48 ) )
V_229 = V_230 ;
if ( V_2 -> V_3 & V_196 )
V_197 = V_2 -> V_197 ;
V_227 = V_48 -> V_114 + V_229 + V_197 ;
if ( ! ( V_2 -> V_3 & V_195 ) ) {
if ( F_157 ( V_226 ) < sizeof( V_186 ) )
return - V_8 ;
V_227 += sizeof( V_186 ) ;
if ( F_157 ( V_226 ) < V_227 ) {
V_186 . V_3 |= V_231 ;
}
if ( F_179 ( & V_186 , sizeof( V_186 ) , V_226 ) != sizeof( V_186 ) )
return - V_7 ;
}
if ( V_197 ) {
struct V_188 V_189 = { 0 } ;
int V_232 ;
if ( F_157 ( V_226 ) < V_197 )
return - V_8 ;
V_232 = F_180 ( V_48 , & V_189 ,
F_7 ( V_2 ) ) ;
if ( V_232 ) {
struct V_233 * V_234 = F_168 ( V_48 ) ;
F_181 ( L_6
L_7 ,
V_234 -> V_235 , F_8 ( V_2 , V_189 . V_236 ) ,
F_8 ( V_2 , V_189 . V_201 ) ) ;
F_182 ( V_237 , L_8 ,
V_238 ,
16 , 1 , V_48 -> V_14 ,
F_183 ( ( int ) F_8 ( V_2 , V_189 . V_201 ) , 64 ) , true ) ;
F_184 ( 1 ) ;
return - V_8 ;
}
if ( F_179 ( & V_189 , sizeof( V_189 ) , V_226 ) != sizeof( V_189 ) )
return - V_7 ;
F_159 ( V_226 , V_197 - sizeof( V_189 ) ) ;
}
if ( V_229 ) {
int V_232 ;
struct {
T_13 V_239 ;
T_13 V_240 ;
} V_241 ;
V_241 . V_239 = V_48 -> V_242 ;
V_241 . V_240 = F_165 ( F_185 ( V_48 ) ) ;
V_228 = F_186 ( struct V_243 , V_239 ) ;
V_232 = F_187 ( V_48 , 0 , V_226 , V_228 ) ;
if ( V_232 || ! F_157 ( V_226 ) )
goto V_244;
V_232 = F_179 ( & V_241 , sizeof( V_241 ) , V_226 ) ;
if ( V_232 != sizeof( V_241 ) || ! F_157 ( V_226 ) )
goto V_244;
}
F_187 ( V_48 , V_228 , V_226 , V_48 -> V_114 - V_228 ) ;
V_244:
V_138 = F_172 ( V_2 -> V_123 ) ;
F_173 ( & V_138 -> V_148 ) ;
V_138 -> V_151 ++ ;
V_138 -> V_152 += V_48 -> V_114 + V_229 ;
F_174 ( & V_138 -> V_148 ) ;
F_175 ( V_2 -> V_123 ) ;
return V_227 ;
}
static struct V_47 * F_188 ( struct V_37 * V_38 , int V_179 ,
int * V_82 )
{
F_189 ( V_168 , V_245 ) ;
struct V_47 * V_48 = NULL ;
int error = 0 ;
V_48 = F_62 ( & V_38 -> V_63 ) ;
if ( V_48 )
goto V_84;
if ( V_179 ) {
error = - V_207 ;
goto V_84;
}
F_190 ( & V_38 -> V_246 . V_168 , & V_168 ) ;
V_245 -> V_247 = V_248 ;
while ( 1 ) {
V_48 = F_62 ( & V_38 -> V_63 ) ;
if ( V_48 )
break;
if ( F_191 ( V_245 ) ) {
error = - V_249 ;
break;
}
if ( V_38 -> V_74 . V_64 -> V_75 & V_76 ) {
error = - V_7 ;
break;
}
F_192 () ;
}
V_245 -> V_247 = V_250 ;
F_193 ( & V_38 -> V_246 . V_168 , & V_168 ) ;
V_84:
* V_82 = error ;
return V_48 ;
}
static T_12 F_194 ( struct V_1 * V_2 , struct V_37 * V_38 ,
struct V_183 * V_251 ,
int V_179 )
{
struct V_47 * V_48 ;
T_12 V_232 ;
int V_82 ;
F_17 ( V_18 , V_2 , L_9 ) ;
if ( ! F_157 ( V_251 ) )
return 0 ;
V_48 = F_188 ( V_38 , V_179 , & V_82 ) ;
if ( ! V_48 )
return V_82 ;
V_232 = F_177 ( V_2 , V_38 , V_48 , V_251 ) ;
if ( F_39 ( V_232 < 0 ) )
F_63 ( V_48 ) ;
else
F_195 ( V_48 ) ;
return V_232 ;
}
static T_12 F_196 ( struct V_219 * V_220 , struct V_183 * V_251 )
{
struct V_79 * V_79 = V_220 -> V_221 ;
struct V_37 * V_38 = V_79 -> V_81 ;
struct V_1 * V_2 = F_89 ( V_38 ) ;
T_12 V_114 = F_157 ( V_251 ) , V_232 ;
if ( ! V_2 )
return - V_223 ;
V_232 = F_194 ( V_2 , V_38 , V_251 , V_79 -> V_224 & V_225 ) ;
V_232 = F_197 ( T_12 , V_232 , V_114 ) ;
if ( V_232 > 0 )
V_220 -> V_252 = V_232 ;
F_93 ( V_2 ) ;
return V_232 ;
}
static void F_198 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
F_67 ( ! ( F_199 ( & V_2 -> V_61 ) ) ) ;
F_200 ( V_2 -> V_123 ) ;
F_139 ( V_2 ) ;
F_201 ( V_2 -> V_83 ) ;
F_202 ( V_46 ) ;
}
static void F_203 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
V_2 -> V_55 = V_253 ;
V_2 -> V_57 = V_254 ;
V_46 -> V_255 = & V_256 ;
V_46 -> V_257 = F_198 ;
V_46 -> V_91 = V_258 ;
}
static int F_204 ( struct V_259 * V_260 [] , struct V_259 * V_30 [] )
{
return - V_8 ;
}
static void F_205 ( struct V_169 * V_64 )
{
struct V_37 * V_38 ;
T_14 * V_261 ;
if ( ! F_148 ( V_64 ) )
return;
if ( ! F_206 ( V_173 , & V_64 -> V_174 -> V_3 ) )
return;
V_261 = F_146 ( V_64 ) ;
if ( V_261 && F_207 ( V_261 ) )
F_208 ( V_261 , V_175 |
V_176 | V_262 ) ;
V_38 = F_209 ( V_64 , struct V_37 , V_64 ) ;
F_123 ( & V_38 -> V_119 , V_120 , V_263 ) ;
}
static int F_210 ( struct V_74 * V_169 , struct V_264 * V_265 , T_11 V_187 )
{
int V_232 ;
struct V_37 * V_38 = F_209 ( V_169 , struct V_37 , V_74 ) ;
struct V_1 * V_2 = F_89 ( V_38 ) ;
if ( ! V_2 )
return - V_223 ;
V_232 = F_155 ( V_2 , V_38 , V_265 -> V_182 , & V_265 -> V_266 ,
V_265 -> V_267 & V_268 ) ;
F_93 ( V_2 ) ;
return V_232 ;
}
static int F_211 ( struct V_74 * V_169 , struct V_264 * V_265 , T_11 V_187 ,
int V_3 )
{
struct V_37 * V_38 = F_209 ( V_169 , struct V_37 , V_74 ) ;
struct V_1 * V_2 = F_89 ( V_38 ) ;
int V_232 ;
if ( ! V_2 )
return - V_223 ;
if ( V_3 & ~ ( V_268 | V_269 | V_270 ) ) {
V_232 = - V_8 ;
goto V_84;
}
if ( V_3 & V_270 ) {
V_232 = F_212 ( V_169 -> V_64 , V_265 , V_187 ,
V_271 , V_272 ) ;
goto V_84;
}
V_232 = F_194 ( V_2 , V_38 , & V_265 -> V_266 , V_3 & V_268 ) ;
if ( V_232 > ( T_12 ) V_187 ) {
V_265 -> V_267 |= V_269 ;
V_232 = V_3 & V_269 ? V_232 : V_187 ;
}
V_84:
F_93 ( V_2 ) ;
return V_232 ;
}
static int F_213 ( struct V_74 * V_169 )
{
struct V_37 * V_38 = F_209 ( V_169 , struct V_37 , V_74 ) ;
struct V_1 * V_2 ;
int V_232 = 0 ;
V_2 = F_89 ( V_38 ) ;
if ( ! V_2 )
return 0 ;
V_232 = F_214 ( & V_38 -> V_63 ) ;
F_93 ( V_2 ) ;
return V_232 ;
}
static int F_215 ( struct V_1 * V_2 )
{
return V_2 -> V_3 & ( V_273 | V_70 | V_155 | V_163 ) ;
}
static T_12 F_216 ( struct V_274 * V_46 , struct V_275 * V_276 ,
char * V_277 )
{
struct V_1 * V_2 = F_41 ( F_217 ( V_46 ) ) ;
return sprintf ( V_277 , L_10 , F_215 ( V_2 ) ) ;
}
static T_12 F_218 ( struct V_274 * V_46 , struct V_275 * V_276 ,
char * V_277 )
{
struct V_1 * V_2 = F_41 ( F_217 ( V_46 ) ) ;
return F_49 ( V_2 -> V_55 ) ?
sprintf ( V_277 , L_11 ,
F_219 ( F_220 () , V_2 -> V_55 ) ) :
sprintf ( V_277 , L_12 ) ;
}
static T_12 F_221 ( struct V_274 * V_46 , struct V_275 * V_276 ,
char * V_277 )
{
struct V_1 * V_2 = F_41 ( F_217 ( V_46 ) ) ;
return F_51 ( V_2 -> V_57 ) ?
sprintf ( V_277 , L_11 ,
F_222 ( F_220 () , V_2 -> V_57 ) ) :
sprintf ( V_277 , L_12 ) ;
}
static int F_223 ( struct V_54 * V_54 , struct V_79 * V_79 , struct V_278 * V_279 )
{
struct V_1 * V_2 ;
struct V_37 * V_38 = V_79 -> V_81 ;
struct V_45 * V_46 ;
int V_82 ;
if ( V_38 -> V_41 )
return - V_8 ;
V_46 = F_224 ( V_54 , V_279 -> V_280 ) ;
if ( V_46 ) {
if ( V_279 -> V_281 & V_282 )
return - V_85 ;
if ( ( V_279 -> V_281 & V_155 ) && V_46 -> V_156 == & V_157 )
V_2 = F_41 ( V_46 ) ;
else if ( ( V_279 -> V_281 & V_163 ) && V_46 -> V_156 == & V_164 )
V_2 = F_41 ( V_46 ) ;
else
return - V_8 ;
if ( ! ! ( V_279 -> V_281 & V_86 ) !=
! ! ( V_2 -> V_3 & V_86 ) )
return - V_8 ;
if ( F_46 ( V_2 ) )
return - V_283 ;
V_82 = F_225 ( V_2 -> V_83 ) ;
if ( V_82 < 0 )
return V_82 ;
V_82 = F_82 ( V_2 , V_79 , V_279 -> V_281 & V_284 ) ;
if ( V_82 < 0 )
return V_82 ;
if ( V_2 -> V_3 & V_86 &&
( V_2 -> V_40 + V_2 -> V_62 > 1 ) ) {
return 0 ;
}
}
else {
char * V_285 ;
unsigned long V_3 = 0 ;
int V_286 = V_279 -> V_281 & V_86 ?
V_88 : 1 ;
if ( ! F_53 ( V_54 -> V_58 , V_59 ) )
return - V_283 ;
V_82 = F_226 () ;
if ( V_82 < 0 )
return V_82 ;
if ( V_279 -> V_281 & V_155 ) {
V_3 |= V_155 ;
V_285 = L_13 ;
} else if ( V_279 -> V_281 & V_163 ) {
V_3 |= V_163 ;
V_285 = L_14 ;
} else
return - V_8 ;
if ( * V_279 -> V_280 )
V_285 = V_279 -> V_280 ;
V_46 = F_227 ( sizeof( struct V_1 ) , V_285 ,
V_287 , F_203 , V_286 ,
V_286 ) ;
if ( ! V_46 )
return - V_93 ;
F_228 ( V_46 , V_54 ) ;
V_46 -> V_288 = & V_289 ;
V_46 -> V_290 = V_38 -> V_290 ;
V_46 -> V_291 [ 0 ] = & V_292 ;
V_2 = F_41 ( V_46 ) ;
V_2 -> V_46 = V_46 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_115 . V_34 = 0 ;
V_2 -> V_197 = sizeof( struct V_188 ) ;
V_2 -> V_136 = V_135 ;
V_2 -> V_89 = false ;
V_2 -> V_293 = V_38 -> V_74 . V_64 -> V_294 ;
V_2 -> V_123 = F_229 ( struct V_141 ) ;
if ( ! V_2 -> V_123 ) {
V_82 = - V_93 ;
goto V_295;
}
F_230 ( & V_2 -> V_26 ) ;
V_82 = F_231 ( & V_2 -> V_83 ) ;
if ( V_82 < 0 )
goto V_296;
F_141 ( V_46 ) ;
F_136 ( V_2 ) ;
V_46 -> V_297 = V_298 | V_299 |
V_133 | V_300 |
V_301 ;
V_46 -> V_131 = V_46 -> V_297 | V_302 ;
V_46 -> V_303 = V_46 -> V_131 &
~ ( V_300 |
V_301 ) ;
F_232 ( & V_2 -> V_61 ) ;
V_82 = F_82 ( V_2 , V_79 , false ) ;
if ( V_82 < 0 )
goto V_304;
V_82 = F_233 ( V_2 -> V_46 ) ;
if ( V_82 < 0 )
goto V_305;
}
F_234 ( V_2 -> V_46 ) ;
F_17 ( V_18 , V_2 , L_15 ) ;
V_2 -> V_3 = ( V_2 -> V_3 & ~ V_273 ) |
( V_279 -> V_281 & V_273 ) ;
if ( F_235 ( V_2 -> V_46 ) )
F_236 ( V_2 -> V_46 ) ;
strcpy ( V_279 -> V_280 , V_2 -> V_46 -> V_285 ) ;
return 0 ;
V_305:
F_78 ( V_46 ) ;
V_304:
F_139 ( V_2 ) ;
F_201 ( V_2 -> V_83 ) ;
V_296:
F_200 ( V_2 -> V_123 ) ;
V_295:
F_202 ( V_46 ) ;
return V_82 ;
}
static void F_237 ( struct V_54 * V_54 , struct V_1 * V_2 ,
struct V_278 * V_279 )
{
F_17 ( V_18 , V_2 , L_16 ) ;
strcpy ( V_279 -> V_280 , V_2 -> V_46 -> V_285 ) ;
V_279 -> V_281 = F_215 ( V_2 ) ;
}
static int F_238 ( struct V_1 * V_2 , unsigned long V_99 )
{
T_9 V_131 = 0 ;
if ( V_99 & V_306 ) {
V_131 |= V_307 ;
V_99 &= ~ V_306 ;
if ( V_99 & ( V_308 | V_309 ) ) {
if ( V_99 & V_310 ) {
V_131 |= V_311 ;
V_99 &= ~ V_310 ;
}
if ( V_99 & V_308 )
V_131 |= V_312 ;
if ( V_99 & V_309 )
V_131 |= V_313 ;
V_99 &= ~ ( V_308 | V_309 ) ;
}
if ( V_99 & V_314 ) {
V_131 |= V_315 ;
V_99 &= ~ V_314 ;
}
}
if ( V_99 )
return - V_8 ;
V_2 -> V_132 = V_131 ;
F_239 ( V_2 -> V_46 ) ;
return 0 ;
}
static void F_240 ( struct V_1 * V_2 , int V_29 )
{
int V_25 ;
struct V_37 * V_38 ;
for ( V_25 = 0 ; V_25 < V_29 ; V_25 ++ ) {
V_38 = F_66 ( V_2 -> V_69 [ V_25 ] ) ;
F_84 ( V_38 -> V_74 . V_64 ) ;
F_241 ( V_38 -> V_74 . V_64 ) ;
F_86 ( V_38 -> V_74 . V_64 ) ;
}
V_2 -> V_89 = false ;
}
static int F_242 ( struct V_1 * V_2 )
{
int V_25 , V_232 = 0 ;
struct V_37 * V_38 ;
for ( V_25 = 0 ; V_25 < V_2 -> V_40 ; V_25 ++ ) {
V_38 = F_66 ( V_2 -> V_69 [ V_25 ] ) ;
F_84 ( V_38 -> V_74 . V_64 ) ;
V_232 = F_85 ( & V_2 -> V_90 , V_38 -> V_74 . V_64 ) ;
F_86 ( V_38 -> V_74 . V_64 ) ;
if ( V_232 ) {
F_240 ( V_2 , V_25 ) ;
return V_232 ;
}
}
V_2 -> V_89 = true ;
return V_232 ;
}
static void F_243 ( struct V_1 * V_2 )
{
struct V_37 * V_38 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_2 -> V_40 ; V_25 ++ ) {
V_38 = F_66 ( V_2 -> V_69 [ V_25 ] ) ;
V_38 -> V_74 . V_64 -> V_294 = V_2 -> V_293 ;
}
}
static int F_244 ( struct V_79 * V_79 , struct V_278 * V_279 )
{
struct V_37 * V_38 = V_79 -> V_81 ;
struct V_1 * V_2 ;
int V_232 = 0 ;
F_76 () ;
if ( V_279 -> V_281 & V_316 ) {
V_2 = V_38 -> V_41 ;
if ( ! V_2 ) {
V_232 = - V_8 ;
goto V_42;
}
V_232 = F_245 ( V_2 -> V_83 ) ;
if ( V_232 < 0 )
goto V_42;
V_232 = F_82 ( V_2 , V_79 , false ) ;
} else if ( V_279 -> V_281 & V_317 ) {
V_2 = F_66 ( V_38 -> V_2 ) ;
if ( ! V_2 || ! ( V_2 -> V_3 & V_86 ) || V_38 -> V_41 )
V_232 = - V_8 ;
else
F_65 ( V_38 , false ) ;
} else
V_232 = - V_8 ;
V_42:
F_77 () ;
return V_232 ;
}
static long F_246 ( struct V_79 * V_79 , unsigned int V_318 ,
unsigned long V_99 , int V_319 )
{
struct V_37 * V_38 = V_79 -> V_81 ;
struct V_1 * V_2 ;
void T_1 * V_5 = ( void T_1 * ) V_99 ;
struct V_278 V_279 ;
T_15 V_55 ;
T_16 V_57 ;
int V_293 ;
int V_197 ;
unsigned int V_290 ;
int V_320 ;
int V_232 ;
if ( V_318 == V_321 || V_318 == V_322 || F_247 ( V_318 ) == 0x89 ) {
if ( F_99 ( & V_279 , V_5 , V_319 ) )
return - V_7 ;
} else {
memset ( & V_279 , 0 , sizeof( V_279 ) ) ;
}
if ( V_318 == V_323 ) {
return F_4 ( V_155 | V_163 | V_273 ,
( unsigned int T_1 * ) V_5 ) ;
} else if ( V_318 == V_322 )
return F_244 ( V_79 , & V_279 ) ;
V_232 = 0 ;
F_76 () ;
V_2 = F_89 ( V_38 ) ;
if ( V_318 == V_321 && ! V_2 ) {
V_279 . V_280 [ V_324 - 1 ] = '\0' ;
V_232 = F_223 ( F_248 ( & V_38 -> V_64 ) , V_79 , & V_279 ) ;
if ( V_232 )
goto V_42;
if ( F_249 ( V_5 , & V_279 , V_319 ) )
V_232 = - V_7 ;
goto V_42;
}
if ( V_318 == V_325 ) {
V_232 = - V_283 ;
if ( V_2 )
goto V_42;
V_232 = - V_7 ;
if ( F_99 ( & V_290 , V_5 , sizeof( V_290 ) ) )
goto V_42;
V_232 = 0 ;
V_38 -> V_290 = V_290 ;
goto V_42;
}
V_232 = - V_223 ;
if ( ! V_2 )
goto V_42;
F_17 ( V_18 , V_2 , L_17 , V_318 ) ;
V_232 = 0 ;
switch ( V_318 ) {
case V_326 :
F_237 ( V_245 -> V_327 -> V_328 , V_2 , & V_279 ) ;
if ( V_38 -> V_41 )
V_279 . V_281 |= V_317 ;
if ( ! V_38 -> V_74 . V_64 -> V_116 )
V_279 . V_281 |= V_284 ;
if ( F_249 ( V_5 , & V_279 , V_319 ) )
V_232 = - V_7 ;
break;
case V_329 :
F_17 ( V_18 , V_2 , L_18 ,
V_99 ? L_19 : L_20 ) ;
break;
case V_330 :
if ( V_99 && ! ( V_2 -> V_3 & V_70 ) ) {
V_2 -> V_3 |= V_70 ;
F_250 ( V_78 ) ;
}
if ( ! V_99 && ( V_2 -> V_3 & V_70 ) ) {
V_2 -> V_3 &= ~ V_70 ;
F_81 ( V_78 ) ;
}
F_17 ( V_18 , V_2 , L_21 ,
V_99 ? L_20 : L_19 ) ;
break;
case V_331 :
V_55 = F_251 ( F_220 () , V_99 ) ;
if ( ! F_49 ( V_55 ) ) {
V_232 = - V_8 ;
break;
}
V_2 -> V_55 = V_55 ;
F_17 ( V_18 , V_2 , L_22 ,
F_252 ( & V_332 , V_2 -> V_55 ) ) ;
break;
case V_333 :
V_57 = F_253 ( F_220 () , V_99 ) ;
if ( ! F_51 ( V_57 ) ) {
V_232 = - V_8 ;
break;
}
V_2 -> V_57 = V_57 ;
F_17 ( V_18 , V_2 , L_23 ,
F_254 ( & V_332 , V_2 -> V_57 ) ) ;
break;
case V_334 :
if ( V_2 -> V_46 -> V_3 & V_193 ) {
F_17 ( V_18 , V_2 ,
L_24 ) ;
V_232 = - V_85 ;
} else {
V_2 -> V_46 -> type = ( int ) V_99 ;
F_17 ( V_18 , V_2 , L_25 ,
V_2 -> V_46 -> type ) ;
V_232 = 0 ;
}
break;
#ifdef F_255
case V_335 :
V_2 -> V_336 = V_99 ;
break;
#endif
case V_337 :
V_232 = F_238 ( V_2 , V_99 ) ;
break;
case V_338 :
V_232 = - V_8 ;
if ( ( V_2 -> V_3 & V_154 ) != V_163 )
break;
V_232 = F_98 ( & V_2 -> V_115 , ( void T_1 * ) V_99 ) ;
break;
case V_339 :
memcpy ( V_279 . V_340 . V_341 , V_2 -> V_46 -> V_342 , V_96 ) ;
V_279 . V_340 . V_343 = V_2 -> V_46 -> type ;
if ( F_249 ( V_5 , & V_279 , V_319 ) )
V_232 = - V_7 ;
break;
case V_344 :
F_17 ( V_345 , V_2 , L_26 ,
V_279 . V_340 . V_341 ) ;
V_232 = F_256 ( V_2 -> V_46 , & V_279 . V_340 ) ;
break;
case V_346 :
V_293 = V_38 -> V_74 . V_64 -> V_294 ;
if ( F_249 ( V_5 , & V_293 , sizeof( V_293 ) ) )
V_232 = - V_7 ;
break;
case V_347 :
if ( F_99 ( & V_293 , V_5 , sizeof( V_293 ) ) ) {
V_232 = - V_7 ;
break;
}
V_2 -> V_293 = V_293 ;
F_243 ( V_2 ) ;
break;
case V_348 :
V_197 = V_2 -> V_197 ;
if ( F_249 ( V_5 , & V_197 , sizeof( V_197 ) ) )
V_232 = - V_7 ;
break;
case V_349 :
if ( F_99 ( & V_197 , V_5 , sizeof( V_197 ) ) ) {
V_232 = - V_7 ;
break;
}
if ( V_197 < ( int ) sizeof( struct V_188 ) ) {
V_232 = - V_8 ;
break;
}
V_2 -> V_197 = V_197 ;
break;
case V_350 :
V_320 = ! ! ( V_2 -> V_3 & V_9 ) ;
if ( F_4 ( V_320 , ( int T_1 * ) V_5 ) )
V_232 = - V_7 ;
break;
case V_351 :
if ( F_6 ( V_320 , ( int T_1 * ) V_5 ) ) {
V_232 = - V_7 ;
break;
}
if ( V_320 )
V_2 -> V_3 |= V_9 ;
else
V_2 -> V_3 &= ~ V_9 ;
break;
case V_352 :
V_232 = F_3 ( V_2 , V_5 ) ;
break;
case V_353 :
V_232 = F_5 ( V_2 , V_5 ) ;
break;
case V_354 :
V_232 = - V_8 ;
if ( ( V_2 -> V_3 & V_154 ) != V_163 )
break;
V_232 = - V_7 ;
if ( F_99 ( & V_2 -> V_90 , V_5 , sizeof( V_2 -> V_90 ) ) )
break;
V_232 = F_242 ( V_2 ) ;
break;
case V_355 :
V_232 = - V_8 ;
if ( ( V_2 -> V_3 & V_154 ) != V_163 )
break;
V_232 = 0 ;
F_240 ( V_2 , V_2 -> V_40 ) ;
break;
case V_356 :
V_232 = - V_8 ;
if ( ( V_2 -> V_3 & V_154 ) != V_163 )
break;
V_232 = - V_7 ;
if ( F_249 ( V_5 , & V_2 -> V_90 , sizeof( V_2 -> V_90 ) ) )
break;
V_232 = 0 ;
break;
default:
V_232 = - V_8 ;
break;
}
V_42:
F_77 () ;
if ( V_2 )
F_93 ( V_2 ) ;
return V_232 ;
}
static long F_257 ( struct V_79 * V_79 ,
unsigned int V_318 , unsigned long V_99 )
{
return F_246 ( V_79 , V_318 , V_99 , sizeof ( struct V_278 ) ) ;
}
static long F_258 ( struct V_79 * V_79 ,
unsigned int V_318 , unsigned long V_99 )
{
switch ( V_318 ) {
case V_321 :
case V_326 :
case V_338 :
case V_346 :
case V_347 :
case V_339 :
case V_344 :
V_99 = ( unsigned long ) F_259 ( V_99 ) ;
break;
default:
V_99 = ( V_357 ) V_99 ;
break;
}
return F_246 ( V_79 , V_318 , V_99 , sizeof( struct V_358 ) ) ;
}
static int F_260 ( int V_359 , struct V_79 * V_79 , int V_360 )
{
struct V_37 * V_38 = V_79 -> V_81 ;
int V_232 ;
if ( ( V_232 = F_261 ( V_359 , V_79 , V_360 , & V_38 -> V_119 ) ) < 0 )
goto V_84;
if ( V_360 ) {
F_262 ( V_79 , F_263 ( V_245 ) , V_361 , 0 ) ;
V_38 -> V_3 |= V_118 ;
} else
V_38 -> V_3 &= ~ V_118 ;
V_232 = 0 ;
V_84:
return V_232 ;
}
static int F_264 ( struct V_362 * V_362 , struct V_79 * V_79 )
{
struct V_54 * V_54 = V_245 -> V_327 -> V_328 ;
struct V_37 * V_38 ;
F_265 ( V_18 , L_27 ) ;
V_38 = (struct V_37 * ) F_266 ( V_54 , V_363 , V_92 ,
& V_364 , 0 ) ;
if ( ! V_38 )
return - V_93 ;
F_69 ( V_38 -> V_2 , NULL ) ;
V_38 -> V_3 = 0 ;
V_38 -> V_290 = 0 ;
F_267 ( & V_38 -> V_246 . V_168 ) ;
F_69 ( V_38 -> V_74 . V_246 , & V_38 -> V_246 ) ;
V_38 -> V_74 . V_79 = V_79 ;
V_38 -> V_74 . V_365 = & V_366 ;
F_268 ( & V_38 -> V_74 , & V_38 -> V_64 ) ;
V_38 -> V_64 . V_367 = F_205 ;
V_38 -> V_64 . V_294 = V_205 ;
V_79 -> V_81 = V_38 ;
F_232 ( & V_38 -> V_60 ) ;
F_269 ( & V_38 -> V_64 , V_368 ) ;
return 0 ;
}
static int F_270 ( struct V_362 * V_362 , struct V_79 * V_79 )
{
struct V_37 * V_38 = V_79 -> V_81 ;
F_75 ( V_38 , true ) ;
return 0 ;
}
static void F_271 ( struct V_369 * V_265 , struct V_79 * V_370 )
{
struct V_1 * V_2 ;
struct V_278 V_279 ;
memset ( & V_279 , 0 , sizeof( V_279 ) ) ;
F_76 () ;
V_2 = F_92 ( V_370 ) ;
if ( V_2 )
F_237 ( V_245 -> V_327 -> V_328 , V_2 , & V_279 ) ;
F_77 () ;
if ( V_2 )
F_93 ( V_2 ) ;
F_272 ( V_265 , L_28 , V_279 . V_280 ) ;
}
static int F_273 ( struct V_45 * V_46 , struct V_371 * V_318 )
{
V_318 -> V_372 = 0 ;
V_318 -> V_373 = 0 ;
F_274 ( V_318 , V_374 ) ;
V_318 -> V_375 = V_376 ;
V_318 -> V_377 = V_378 ;
V_318 -> V_379 = 0 ;
V_318 -> V_380 = V_381 ;
V_318 -> V_382 = V_383 ;
V_318 -> V_384 = 0 ;
V_318 -> V_385 = 0 ;
return 0 ;
}
static void F_275 ( struct V_45 * V_46 , struct V_386 * V_387 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
F_276 ( V_387 -> V_388 , V_389 , sizeof( V_387 -> V_388 ) ) ;
F_276 ( V_387 -> V_390 , V_391 , sizeof( V_387 -> V_390 ) ) ;
switch ( V_2 -> V_3 & V_154 ) {
case V_155 :
F_276 ( V_387 -> V_392 , L_29 , sizeof( V_387 -> V_392 ) ) ;
break;
case V_163 :
F_276 ( V_387 -> V_392 , L_30 , sizeof( V_387 -> V_392 ) ) ;
break;
}
}
static T_4 F_277 ( struct V_45 * V_46 )
{
#ifdef F_255
struct V_1 * V_2 = F_41 ( V_46 ) ;
return V_2 -> V_336 ;
#else
return - V_393 ;
#endif
}
static void F_278 ( struct V_45 * V_46 , T_4 V_394 )
{
#ifdef F_255
struct V_1 * V_2 = F_41 ( V_46 ) ;
V_2 -> V_336 = V_394 ;
#endif
}
static int F_279 ( struct V_1 * V_2 )
{
struct V_45 * V_46 = V_2 -> V_46 ;
struct V_37 * V_38 ;
struct V_395 * * V_396 ;
int V_29 = V_2 -> V_40 + V_2 -> V_62 ;
int V_232 , V_25 ;
V_396 = F_16 ( sizeof *V_396 * V_29 , V_92 ) ;
if ( ! V_396 )
return - V_93 ;
for ( V_25 = 0 ; V_25 < V_2 -> V_40 ; V_25 ++ ) {
V_38 = F_66 ( V_2 -> V_69 [ V_25 ] ) ;
V_396 [ V_25 ] = & V_38 -> V_63 ;
}
F_79 (tfile, &tun->disabled, next)
V_396 [ V_25 ++ ] = & V_38 -> V_63 ;
V_232 = F_280 ( V_396 , V_29 ,
V_46 -> V_91 , V_92 ) ;
F_105 ( V_396 ) ;
return V_232 ;
}
static int F_281 ( struct V_397 * V_398 ,
unsigned long V_399 , void * V_400 )
{
struct V_45 * V_46 = F_282 ( V_400 ) ;
struct V_1 * V_2 = F_41 ( V_46 ) ;
if ( V_46 -> V_288 != & V_289 )
return V_401 ;
switch ( V_399 ) {
case V_402 :
if ( F_279 ( V_2 ) )
return V_403 ;
break;
default:
break;
}
return V_401 ;
}
static int T_17 F_283 ( void )
{
int V_232 = 0 ;
F_284 ( L_31 , V_404 , V_391 ) ;
F_284 ( L_32 , V_405 ) ;
V_232 = F_285 ( & V_289 ) ;
if ( V_232 ) {
F_181 ( L_33 ) ;
goto V_406;
}
V_232 = F_286 ( & V_407 ) ;
if ( V_232 ) {
F_181 ( L_34 , V_408 ) ;
goto V_409;
}
F_287 ( & V_410 ) ;
return 0 ;
V_409:
F_288 ( & V_289 ) ;
V_406:
return V_232 ;
}
static void F_289 ( void )
{
F_290 ( & V_407 ) ;
F_288 ( & V_289 ) ;
F_291 ( & V_410 ) ;
}
struct V_74 * F_292 ( struct V_79 * V_79 )
{
struct V_37 * V_38 ;
if ( V_79 -> V_411 != & V_412 )
return F_152 ( - V_8 ) ;
V_38 = V_79 -> V_81 ;
if ( ! V_38 )
return F_152 ( - V_223 ) ;
return & V_38 -> V_74 ;
}
