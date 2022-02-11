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
F_62 ( & V_38 -> V_63 . V_64 ) ;
F_62 ( & V_38 -> V_63 . V_65 ) ;
}
static void F_63 ( struct V_37 * V_38 , bool V_66 )
{
struct V_37 * V_67 ;
struct V_1 * V_2 ;
V_2 = F_64 ( V_38 -> V_2 ) ;
if ( V_2 && ! V_38 -> V_41 ) {
T_2 V_68 = V_38 -> V_16 ;
F_65 ( V_68 >= V_2 -> V_40 ) ;
F_66 ( V_2 -> V_69 [ V_68 ] ,
V_2 -> V_69 [ V_2 -> V_40 - 1 ] ) ;
V_67 = F_64 ( V_2 -> V_69 [ V_68 ] ) ;
V_67 -> V_16 = V_68 ;
-- V_2 -> V_40 ;
if ( V_66 ) {
F_67 ( V_38 -> V_2 , NULL ) ;
F_68 ( & V_38 -> V_63 ) ;
} else
F_57 ( V_2 , V_38 ) ;
F_69 () ;
F_26 ( V_2 , V_2 -> V_40 + 1 ) ;
F_61 ( V_38 ) ;
F_54 ( V_2 ) ;
} else if ( V_38 -> V_41 && V_66 ) {
V_2 = F_59 ( V_38 ) ;
F_68 ( & V_38 -> V_63 ) ;
}
if ( V_66 ) {
if ( V_2 && V_2 -> V_40 == 0 && V_2 -> V_62 == 0 ) {
F_70 ( V_2 -> V_46 ) ;
if ( ! ( V_2 -> V_3 & V_70 ) &&
V_2 -> V_46 -> V_71 == V_72 )
F_71 ( V_2 -> V_46 ) ;
}
F_68 ( & V_38 -> V_63 ) ;
}
}
static void F_72 ( struct V_37 * V_38 , bool V_66 )
{
F_73 () ;
F_63 ( V_38 , V_66 ) ;
F_74 () ;
}
static void F_75 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
struct V_37 * V_38 , * V_73 ;
int V_25 , V_29 = V_2 -> V_40 ;
for ( V_25 = 0 ; V_25 < V_29 ; V_25 ++ ) {
V_38 = F_64 ( V_2 -> V_69 [ V_25 ] ) ;
F_65 ( ! V_38 ) ;
V_38 -> V_74 . V_63 -> V_75 = V_76 ;
V_38 -> V_74 . V_63 -> V_77 ( V_38 -> V_74 . V_63 ) ;
F_67 ( V_38 -> V_2 , NULL ) ;
-- V_2 -> V_40 ;
}
F_76 (tfile, &tun->disabled, next) {
V_38 -> V_74 . V_63 -> V_75 = V_76 ;
V_38 -> V_74 . V_63 -> V_77 ( V_38 -> V_74 . V_63 ) ;
F_67 ( V_38 -> V_2 , NULL ) ;
}
F_65 ( V_2 -> V_40 != 0 ) ;
F_69 () ;
for ( V_25 = 0 ; V_25 < V_29 ; V_25 ++ ) {
V_38 = F_64 ( V_2 -> V_69 [ V_25 ] ) ;
F_61 ( V_38 ) ;
F_68 ( & V_38 -> V_63 ) ;
}
F_77 (tfile, tmp, &tun->disabled, next) {
F_59 ( V_38 ) ;
F_61 ( V_38 ) ;
F_68 ( & V_38 -> V_63 ) ;
}
F_65 ( V_2 -> V_62 != 0 ) ;
if ( V_2 -> V_3 & V_70 )
F_78 ( V_78 ) ;
}
static int F_79 ( struct V_1 * V_2 , struct V_79 * V_79 , bool V_80 )
{
struct V_37 * V_38 = V_79 -> V_81 ;
int V_82 ;
V_82 = F_80 ( V_38 -> V_74 . V_63 , V_2 -> V_83 ) ;
if ( V_82 < 0 )
goto V_84;
V_82 = - V_8 ;
if ( F_64 ( V_38 -> V_2 ) && ! V_38 -> V_41 )
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
F_81 ( V_38 -> V_74 . V_63 ) ;
V_82 = F_82 ( & V_2 -> V_90 , V_38 -> V_74 . V_63 ) ;
F_83 ( V_38 -> V_74 . V_63 ) ;
if ( ! V_82 )
goto V_84;
}
V_38 -> V_16 = V_2 -> V_40 ;
V_38 -> V_74 . V_63 -> V_75 &= ~ V_76 ;
F_66 ( V_38 -> V_2 , V_2 ) ;
F_66 ( V_2 -> V_69 [ V_2 -> V_40 ] , V_38 ) ;
V_2 -> V_40 ++ ;
if ( V_38 -> V_41 )
F_59 ( V_38 ) ;
else
F_84 ( & V_38 -> V_63 ) ;
F_54 ( V_2 ) ;
V_84:
return V_82 ;
}
static struct V_1 * F_85 ( struct V_37 * V_38 )
{
struct V_1 * V_2 ;
F_33 () ;
V_2 = F_86 ( V_38 -> V_2 ) ;
if ( V_2 )
F_87 ( V_2 -> V_46 ) ;
F_37 () ;
return V_2 ;
}
static struct V_1 * F_88 ( struct V_79 * V_79 )
{
return F_85 ( V_79 -> V_81 ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
F_90 ( V_2 -> V_46 ) ;
}
static void F_91 ( T_4 * V_91 , const T_6 * V_92 )
{
int V_29 = F_92 ( V_93 , V_92 ) >> 26 ;
V_91 [ V_29 >> 5 ] |= ( 1 << ( V_29 & 31 ) ) ;
}
static unsigned int F_93 ( const T_4 * V_91 , const T_6 * V_92 )
{
int V_29 = F_92 ( V_93 , V_92 ) >> 26 ;
return V_91 [ V_29 >> 5 ] & ( 1 << ( V_29 & 31 ) ) ;
}
static int F_94 ( struct V_94 * V_95 , void T_1 * V_96 )
{
struct { T_6 V_97 [ V_93 ] ; } * V_92 ;
struct V_98 V_99 ;
int V_82 , V_100 , V_29 , V_101 ;
if ( F_95 ( & V_99 , V_96 , sizeof( V_99 ) ) )
return - V_7 ;
if ( ! V_99 . V_34 ) {
V_95 -> V_34 = 0 ;
return 0 ;
}
V_100 = V_93 * V_99 . V_34 ;
V_92 = F_16 ( V_100 , V_102 ) ;
if ( ! V_92 )
return - V_103 ;
if ( F_95 ( V_92 , V_96 + sizeof( V_99 ) , V_100 ) ) {
V_82 = - V_7 ;
goto V_104;
}
V_95 -> V_34 = 0 ;
F_96 () ;
for ( V_29 = 0 ; V_29 < V_99 . V_34 && V_29 < V_105 ; V_29 ++ )
memcpy ( V_95 -> V_92 [ V_29 ] , V_92 [ V_29 ] . V_97 , V_93 ) ;
V_101 = V_29 ;
memset ( V_95 -> V_91 , 0 , sizeof( V_95 -> V_91 ) ) ;
for (; V_29 < V_99 . V_34 ; V_29 ++ ) {
if ( ! F_97 ( V_92 [ V_29 ] . V_97 ) ) {
V_82 = 0 ;
goto V_104;
}
F_91 ( V_95 -> V_91 , V_92 [ V_29 ] . V_97 ) ;
}
if ( ( V_99 . V_3 & V_106 ) )
memset ( V_95 -> V_91 , ~ 0 , sizeof( V_95 -> V_91 ) ) ;
F_96 () ;
V_95 -> V_34 = V_101 ;
V_82 = V_101 ;
V_104:
F_98 ( V_92 ) ;
return V_82 ;
}
static int F_99 ( struct V_94 * V_95 , const struct V_47 * V_48 )
{
struct V_107 * V_108 = (struct V_107 * ) V_48 -> V_30 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_95 -> V_34 ; V_25 ++ )
if ( F_100 ( V_108 -> V_109 , V_95 -> V_92 [ V_25 ] ) )
return 1 ;
if ( F_97 ( V_108 -> V_109 ) )
return F_93 ( V_95 -> V_91 , V_108 -> V_109 ) ;
return 0 ;
}
static int F_101 ( struct V_94 * V_95 , const struct V_47 * V_48 )
{
if ( ! V_95 -> V_34 )
return 1 ;
return F_99 ( V_95 , V_48 ) ;
}
static void F_102 ( struct V_45 * V_46 )
{
F_75 ( V_46 ) ;
}
static int F_103 ( struct V_45 * V_46 )
{
F_104 ( V_46 ) ;
return 0 ;
}
static int F_105 ( struct V_45 * V_46 )
{
F_106 ( V_46 ) ;
return 0 ;
}
static T_7 F_107 ( struct V_47 * V_48 , struct V_45 * V_46 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
int V_51 = V_48 -> V_110 ;
struct V_37 * V_38 ;
T_4 V_40 = 0 ;
F_33 () ;
V_38 = F_86 ( V_2 -> V_69 [ V_51 ] ) ;
V_40 = F_42 ( V_2 -> V_40 ) ;
if ( V_51 >= V_40 )
goto V_111;
#ifdef F_108
if ( V_40 == 1 && F_109 ( & V_112 ) ) {
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
F_17 ( V_18 , V_2 , L_4 , V_48 -> V_113 ) ;
F_65 ( ! V_38 ) ;
if ( ! F_101 ( & V_2 -> V_114 , V_48 ) )
goto V_111;
if ( V_38 -> V_74 . V_63 -> V_115 &&
V_115 ( V_38 -> V_74 . V_63 , V_48 ) )
goto V_111;
if ( F_110 ( & V_38 -> V_74 . V_63 -> V_64 ) * V_40
>= V_46 -> V_116 )
goto V_111;
if ( F_39 ( F_111 ( V_48 , V_17 ) ) )
goto V_111;
if ( V_48 -> V_63 && F_112 ( V_48 -> V_63 ) ) {
F_113 ( V_48 -> V_63 , V_48 -> V_63 -> V_117 ,
& F_114 ( V_48 ) -> V_118 ) ;
F_115 ( V_48 ) ;
}
F_116 ( V_48 ) ;
F_117 ( V_48 ) ;
F_118 ( & V_38 -> V_74 . V_63 -> V_64 , V_48 ) ;
if ( V_38 -> V_3 & V_119 )
F_119 ( & V_38 -> V_120 , V_121 , V_122 ) ;
V_38 -> V_74 . V_63 -> V_77 ( V_38 -> V_74 . V_63 ) ;
F_37 () ;
return V_123 ;
V_111:
F_120 ( V_2 -> V_124 -> V_125 ) ;
F_121 ( V_48 ) ;
F_122 ( V_48 ) ;
F_37 () ;
return V_126 ;
}
static void F_123 ( struct V_45 * V_46 )
{
}
static int
F_124 ( struct V_45 * V_46 , int V_127 )
{
if ( V_127 < V_128 || V_127 + V_46 -> V_129 > V_130 )
return - V_8 ;
V_46 -> V_131 = V_127 ;
return 0 ;
}
static T_9 F_125 ( struct V_45 * V_46 ,
T_9 V_132 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
return ( V_132 & V_2 -> V_133 ) | ( V_132 & ~ V_134 ) ;
}
static void F_126 ( struct V_45 * V_46 )
{
return;
}
static void F_127 ( struct V_45 * V_46 , int V_135 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
if ( V_135 < V_136 )
V_135 = V_136 ;
V_2 -> V_137 = V_135 ;
}
static struct V_138 *
F_128 ( struct V_45 * V_46 , struct V_138 * V_139 )
{
T_4 V_140 = 0 , V_125 = 0 , V_141 = 0 ;
struct V_1 * V_2 = F_41 ( V_46 ) ;
struct V_142 * V_143 ;
int V_25 ;
F_129 (i) {
V_52 V_144 , V_145 , V_146 , V_147 ;
unsigned int V_148 ;
V_143 = F_130 ( V_2 -> V_124 , V_25 ) ;
do {
V_148 = F_131 ( & V_143 -> V_149 ) ;
V_144 = V_143 -> V_150 ;
V_145 = V_143 -> V_151 ;
V_146 = V_143 -> V_152 ;
V_147 = V_143 -> V_153 ;
} while ( F_132 ( & V_143 -> V_149 , V_148 ) );
V_139 -> V_150 += V_144 ;
V_139 -> V_151 += V_145 ;
V_139 -> V_152 += V_146 ;
V_139 -> V_153 += V_147 ;
V_140 += V_143 -> V_140 ;
V_141 += V_143 -> V_141 ;
V_125 += V_143 -> V_125 ;
}
V_139 -> V_140 = V_140 ;
V_139 -> V_141 = V_141 ;
V_139 -> V_125 = V_125 ;
return V_139 ;
}
static void F_133 ( struct V_1 * V_2 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_27 ; V_25 ++ )
F_134 ( & V_2 -> V_39 [ V_25 ] ) ;
V_2 -> V_32 = V_154 ;
F_135 ( & V_2 -> V_36 , F_27 , ( unsigned long ) V_2 ) ;
F_30 ( & V_2 -> V_36 ,
F_31 ( V_20 + V_2 -> V_32 ) ) ;
}
static void F_136 ( struct V_1 * V_2 )
{
F_137 ( & V_2 -> V_36 ) ;
F_22 ( V_2 ) ;
}
static void F_138 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
switch ( V_2 -> V_3 & V_155 ) {
case V_156 :
V_46 -> V_157 = & V_158 ;
V_46 -> V_129 = 0 ;
V_46 -> V_159 = 0 ;
V_46 -> V_131 = 1500 ;
V_46 -> type = V_160 ;
V_46 -> V_3 = V_161 | V_162 | V_163 ;
break;
case V_164 :
V_46 -> V_157 = & V_165 ;
F_139 ( V_46 ) ;
V_46 -> V_166 &= ~ V_167 ;
V_46 -> V_166 |= V_168 ;
F_140 ( V_46 ) ;
break;
}
}
static unsigned int F_141 ( struct V_79 * V_79 , T_10 * V_169 )
{
struct V_37 * V_38 = V_79 -> V_81 ;
struct V_1 * V_2 = F_85 ( V_38 ) ;
struct V_170 * V_63 ;
unsigned int V_91 = 0 ;
if ( ! V_2 )
return V_171 ;
V_63 = V_38 -> V_74 . V_63 ;
F_17 ( V_18 , V_2 , L_5 ) ;
F_142 ( V_79 , F_143 ( V_63 ) , V_169 ) ;
if ( ! F_144 ( & V_63 -> V_64 ) )
V_91 |= V_172 | V_173 ;
if ( F_145 ( V_63 ) ||
( ! F_146 ( V_174 , & V_63 -> V_175 -> V_3 ) &&
F_145 ( V_63 ) ) )
V_91 |= V_176 | V_177 ;
if ( V_2 -> V_46 -> V_71 != V_72 )
V_91 = V_171 ;
F_89 ( V_2 ) ;
return V_91 ;
}
static struct V_47 * F_147 ( struct V_37 * V_38 ,
T_11 V_178 , T_11 V_113 ,
T_11 V_179 , int V_180 )
{
struct V_170 * V_63 = V_38 -> V_74 . V_63 ;
struct V_47 * V_48 ;
int V_82 ;
if ( V_178 + V_113 < V_181 || ! V_179 )
V_179 = V_113 ;
V_48 = F_148 ( V_63 , V_178 + V_179 , V_113 - V_179 , V_180 ,
& V_82 , 0 ) ;
if ( ! V_48 )
return F_149 ( V_82 ) ;
F_150 ( V_48 , V_178 ) ;
F_151 ( V_48 , V_179 ) ;
V_48 -> V_182 = V_113 - V_179 ;
V_48 -> V_113 += V_113 - V_179 ;
return V_48 ;
}
static T_12 F_152 ( struct V_1 * V_2 , struct V_37 * V_38 ,
void * V_183 , struct V_184 * V_185 ,
int V_180 )
{
struct V_186 V_187 = { 0 , F_153 (ETH_P_IP) } ;
struct V_47 * V_48 ;
T_11 V_188 = F_154 ( V_185 ) ;
T_11 V_113 = V_188 , V_137 = V_2 -> V_137 , V_179 ;
struct V_189 V_190 = { 0 } ;
struct V_142 * V_139 ;
int V_191 ;
int V_192 ;
bool V_193 = false ;
int V_82 ;
T_4 V_11 ;
T_12 V_29 ;
if ( ! ( V_2 -> V_46 -> V_3 & V_194 ) )
return - V_195 ;
if ( ! ( V_2 -> V_3 & V_196 ) ) {
if ( V_113 < sizeof( V_187 ) )
return - V_8 ;
V_113 -= sizeof( V_187 ) ;
V_29 = F_155 ( & V_187 , sizeof( V_187 ) , V_185 ) ;
if ( V_29 != sizeof( V_187 ) )
return - V_7 ;
}
if ( V_2 -> V_3 & V_197 ) {
if ( V_113 < V_2 -> V_198 )
return - V_8 ;
V_113 -= V_2 -> V_198 ;
V_29 = F_155 ( & V_190 , sizeof( V_190 ) , V_185 ) ;
if ( V_29 != sizeof( V_190 ) )
return - V_7 ;
if ( ( V_190 . V_3 & V_199 ) &&
F_8 ( V_2 , V_190 . V_200 ) + F_8 ( V_2 , V_190 . V_201 ) + 2 > F_8 ( V_2 , V_190 . V_202 ) )
V_190 . V_202 = F_10 ( V_2 , F_8 ( V_2 , V_190 . V_200 ) + F_8 ( V_2 , V_190 . V_201 ) + 2 ) ;
if ( F_8 ( V_2 , V_190 . V_202 ) > V_113 )
return - V_8 ;
F_156 ( V_185 , V_2 -> V_198 - sizeof( V_190 ) ) ;
}
if ( ( V_2 -> V_3 & V_155 ) == V_164 ) {
V_137 += V_203 ;
if ( F_39 ( V_113 < V_204 ||
( V_190 . V_202 && F_8 ( V_2 , V_190 . V_202 ) < V_204 ) ) )
return - V_8 ;
}
V_191 = F_157 ( V_137 ) ;
if ( V_183 ) {
struct V_184 V_25 = * V_185 ;
V_192 = V_190 . V_202 ? F_8 ( V_2 , V_190 . V_202 ) : V_205 ;
if ( V_192 > V_191 )
V_192 = V_191 ;
V_179 = V_192 ;
F_156 ( & V_25 , V_192 ) ;
if ( F_158 ( & V_25 , V_206 ) <= V_207 )
V_193 = true ;
}
if ( ! V_193 ) {
V_192 = V_113 ;
if ( F_8 ( V_2 , V_190 . V_202 ) > V_191 )
V_179 = V_191 ;
else
V_179 = F_8 ( V_2 , V_190 . V_202 ) ;
}
V_48 = F_147 ( V_38 , V_137 , V_192 , V_179 , V_180 ) ;
if ( F_159 ( V_48 ) ) {
if ( F_160 ( V_48 ) != - V_208 )
F_120 ( V_2 -> V_124 -> V_140 ) ;
return F_160 ( V_48 ) ;
}
if ( V_193 )
V_82 = F_161 ( V_48 , V_185 ) ;
else {
V_82 = F_162 ( V_48 , 0 , V_185 , V_113 ) ;
if ( ! V_82 && V_183 ) {
struct V_209 * V_210 = V_183 ;
V_210 -> V_211 ( V_210 , false ) ;
}
}
if ( V_82 ) {
F_120 ( V_2 -> V_124 -> V_140 ) ;
F_122 ( V_48 ) ;
return - V_7 ;
}
if ( V_190 . V_3 & V_199 ) {
if ( ! F_163 ( V_48 , F_8 ( V_2 , V_190 . V_200 ) ,
F_8 ( V_2 , V_190 . V_201 ) ) ) {
F_120 ( V_2 -> V_124 -> V_141 ) ;
F_122 ( V_48 ) ;
return - V_8 ;
}
}
switch ( V_2 -> V_3 & V_155 ) {
case V_156 :
if ( V_2 -> V_3 & V_196 ) {
switch ( V_48 -> V_30 [ 0 ] & 0xf0 ) {
case 0x40 :
V_187 . V_212 = F_164 ( V_213 ) ;
break;
case 0x60 :
V_187 . V_212 = F_164 ( V_214 ) ;
break;
default:
F_120 ( V_2 -> V_124 -> V_140 ) ;
F_122 ( V_48 ) ;
return - V_8 ;
}
}
F_165 ( V_48 ) ;
V_48 -> V_215 = V_187 . V_212 ;
V_48 -> V_46 = V_2 -> V_46 ;
break;
case V_164 :
V_48 -> V_215 = F_166 ( V_48 , V_2 -> V_46 ) ;
break;
}
if ( V_190 . V_216 != V_217 ) {
F_167 ( L_6 ) ;
switch ( V_190 . V_216 & ~ V_218 ) {
case V_219 :
F_114 ( V_48 ) -> V_216 = V_220 ;
break;
case V_221 :
F_114 ( V_48 ) -> V_216 = V_222 ;
break;
case V_223 :
F_114 ( V_48 ) -> V_216 = V_224 ;
break;
default:
F_120 ( V_2 -> V_124 -> V_141 ) ;
F_122 ( V_48 ) ;
return - V_8 ;
}
if ( V_190 . V_216 & V_218 )
F_114 ( V_48 ) -> V_216 |= V_225 ;
F_114 ( V_48 ) -> V_226 = F_8 ( V_2 , V_190 . V_226 ) ;
if ( F_114 ( V_48 ) -> V_226 == 0 ) {
F_120 ( V_2 -> V_124 -> V_141 ) ;
F_122 ( V_48 ) ;
return - V_8 ;
}
F_114 ( V_48 ) -> V_216 |= V_227 ;
F_114 ( V_48 ) -> V_228 = 0 ;
}
if ( V_193 ) {
F_114 ( V_48 ) -> V_229 = V_183 ;
F_114 ( V_48 ) -> V_118 |= V_230 ;
F_114 ( V_48 ) -> V_118 |= V_231 ;
}
F_168 ( V_48 ) ;
F_169 ( V_48 , 0 ) ;
V_11 = F_43 ( V_48 ) ;
F_170 ( V_48 ) ;
V_139 = F_171 ( V_2 -> V_124 ) ;
F_172 ( & V_139 -> V_149 ) ;
V_139 -> V_150 ++ ;
V_139 -> V_151 += V_113 ;
F_173 ( & V_139 -> V_149 ) ;
F_174 ( V_139 ) ;
F_32 ( V_2 , V_11 , V_38 ) ;
return V_188 ;
}
static T_12 F_175 ( struct V_232 * V_233 , struct V_184 * V_185 )
{
struct V_79 * V_79 = V_233 -> V_234 ;
struct V_1 * V_2 = F_88 ( V_79 ) ;
struct V_37 * V_38 = V_79 -> V_81 ;
T_12 V_235 ;
if ( ! V_2 )
return - V_236 ;
V_235 = F_152 ( V_2 , V_38 , NULL , V_185 , V_79 -> V_237 & V_238 ) ;
F_89 ( V_2 ) ;
return V_235 ;
}
static T_12 F_176 ( struct V_1 * V_2 ,
struct V_37 * V_38 ,
struct V_47 * V_48 ,
struct V_184 * V_239 )
{
struct V_186 V_187 = { 0 , V_48 -> V_215 } ;
struct V_142 * V_139 ;
T_12 V_240 ;
int V_241 = 0 ;
int V_242 = 0 ;
int V_198 = 0 ;
if ( F_177 ( V_48 ) )
V_242 = V_243 ;
if ( V_2 -> V_3 & V_197 )
V_198 = V_2 -> V_198 ;
V_240 = V_48 -> V_113 + V_242 + V_198 ;
if ( ! ( V_2 -> V_3 & V_196 ) ) {
if ( F_154 ( V_239 ) < sizeof( V_187 ) )
return - V_8 ;
V_240 += sizeof( V_187 ) ;
if ( F_154 ( V_239 ) < V_240 ) {
V_187 . V_3 |= V_244 ;
}
if ( F_178 ( & V_187 , sizeof( V_187 ) , V_239 ) != sizeof( V_187 ) )
return - V_7 ;
}
if ( V_198 ) {
struct V_189 V_190 = { 0 } ;
if ( F_154 ( V_239 ) < V_198 )
return - V_8 ;
if ( F_179 ( V_48 ) ) {
struct V_245 * V_246 = F_114 ( V_48 ) ;
V_190 . V_202 = F_10 ( V_2 , F_180 ( V_48 ) ) ;
V_190 . V_226 = F_10 ( V_2 , V_246 -> V_226 ) ;
if ( V_246 -> V_216 & V_220 )
V_190 . V_216 = V_219 ;
else if ( V_246 -> V_216 & V_222 )
V_190 . V_216 = V_221 ;
else if ( V_246 -> V_216 & V_224 )
V_190 . V_216 = V_223 ;
else {
F_181 ( L_7
L_8 ,
V_246 -> V_216 , F_8 ( V_2 , V_190 . V_226 ) ,
F_8 ( V_2 , V_190 . V_202 ) ) ;
F_182 ( V_247 , L_9 ,
V_248 ,
16 , 1 , V_48 -> V_14 ,
F_183 ( ( int ) F_8 ( V_2 , V_190 . V_202 ) , 64 ) , true ) ;
F_184 ( 1 ) ;
return - V_8 ;
}
if ( V_246 -> V_216 & V_225 )
V_190 . V_216 |= V_218 ;
} else
V_190 . V_216 = V_217 ;
if ( V_48 -> V_249 == V_250 ) {
V_190 . V_3 = V_199 ;
V_190 . V_200 = F_10 ( V_2 , F_185 ( V_48 ) +
V_242 ) ;
V_190 . V_201 = F_10 ( V_2 , V_48 -> V_201 ) ;
} else if ( V_48 -> V_249 == V_251 ) {
V_190 . V_3 = V_252 ;
}
if ( F_178 ( & V_190 , sizeof( V_190 ) , V_239 ) != sizeof( V_190 ) )
return - V_7 ;
F_156 ( V_239 , V_198 - sizeof( V_190 ) ) ;
}
if ( V_242 ) {
int V_253 ;
struct {
T_13 V_254 ;
T_13 V_255 ;
} V_256 ;
V_256 . V_254 = V_48 -> V_257 ;
V_256 . V_255 = F_164 ( F_186 ( V_48 ) ) ;
V_241 = F_187 ( struct V_258 , V_254 ) ;
V_253 = F_188 ( V_48 , 0 , V_239 , V_241 ) ;
if ( V_253 || ! F_154 ( V_239 ) )
goto V_104;
V_253 = F_178 ( & V_256 , sizeof( V_256 ) , V_239 ) ;
if ( V_253 != sizeof( V_256 ) || ! F_154 ( V_239 ) )
goto V_104;
}
F_188 ( V_48 , V_241 , V_239 , V_48 -> V_113 - V_241 ) ;
V_104:
V_139 = F_171 ( V_2 -> V_124 ) ;
F_172 ( & V_139 -> V_149 ) ;
V_139 -> V_152 ++ ;
V_139 -> V_153 += V_48 -> V_113 + V_242 ;
F_173 ( & V_139 -> V_149 ) ;
F_174 ( V_2 -> V_124 ) ;
return V_240 ;
}
static T_12 F_189 ( struct V_1 * V_2 , struct V_37 * V_38 ,
struct V_184 * V_259 ,
int V_180 )
{
struct V_47 * V_48 ;
T_12 V_253 ;
int V_260 , V_82 , V_261 = 0 ;
F_17 ( V_18 , V_2 , L_10 ) ;
if ( ! F_154 ( V_259 ) )
return 0 ;
V_48 = F_190 ( V_38 -> V_74 . V_63 , V_180 ? V_262 : 0 ,
& V_260 , & V_261 , & V_82 ) ;
if ( ! V_48 )
return V_82 ;
V_253 = F_176 ( V_2 , V_38 , V_48 , V_259 ) ;
if ( F_39 ( V_253 < 0 ) )
F_122 ( V_48 ) ;
else
F_191 ( V_48 ) ;
return V_253 ;
}
static T_12 F_192 ( struct V_232 * V_233 , struct V_184 * V_259 )
{
struct V_79 * V_79 = V_233 -> V_234 ;
struct V_37 * V_38 = V_79 -> V_81 ;
struct V_1 * V_2 = F_85 ( V_38 ) ;
T_12 V_113 = F_154 ( V_259 ) , V_253 ;
if ( ! V_2 )
return - V_236 ;
V_253 = F_189 ( V_2 , V_38 , V_259 , V_79 -> V_237 & V_238 ) ;
V_253 = F_193 ( T_12 , V_253 , V_113 ) ;
if ( V_253 > 0 )
V_233 -> V_263 = V_253 ;
F_89 ( V_2 ) ;
return V_253 ;
}
static void F_194 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
F_65 ( ! ( F_195 ( & V_2 -> V_61 ) ) ) ;
F_196 ( V_2 -> V_124 ) ;
F_136 ( V_2 ) ;
F_197 ( V_2 -> V_83 ) ;
F_198 ( V_46 ) ;
}
static void F_199 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
V_2 -> V_55 = V_264 ;
V_2 -> V_57 = V_265 ;
V_46 -> V_266 = & V_267 ;
V_46 -> V_268 = F_194 ;
V_46 -> V_116 = V_269 ;
}
static int F_200 ( struct V_270 * V_271 [] , struct V_270 * V_30 [] )
{
return - V_8 ;
}
static void F_201 ( struct V_170 * V_63 )
{
struct V_37 * V_38 ;
T_14 * V_272 ;
if ( ! F_145 ( V_63 ) )
return;
if ( ! F_202 ( V_174 , & V_63 -> V_175 -> V_3 ) )
return;
V_272 = F_143 ( V_63 ) ;
if ( V_272 && F_203 ( V_272 ) )
F_204 ( V_272 , V_176 |
V_177 | V_273 ) ;
V_38 = F_205 ( V_63 , struct V_37 , V_63 ) ;
F_119 ( & V_38 -> V_120 , V_121 , V_274 ) ;
}
static int F_206 ( struct V_74 * V_170 , struct V_275 * V_276 , T_11 V_188 )
{
int V_253 ;
struct V_37 * V_38 = F_205 ( V_170 , struct V_37 , V_74 ) ;
struct V_1 * V_2 = F_85 ( V_38 ) ;
if ( ! V_2 )
return - V_236 ;
V_253 = F_152 ( V_2 , V_38 , V_276 -> V_183 , & V_276 -> V_277 ,
V_276 -> V_278 & V_262 ) ;
F_89 ( V_2 ) ;
return V_253 ;
}
static int F_207 ( struct V_74 * V_170 , struct V_275 * V_276 , T_11 V_188 ,
int V_3 )
{
struct V_37 * V_38 = F_205 ( V_170 , struct V_37 , V_74 ) ;
struct V_1 * V_2 = F_85 ( V_38 ) ;
int V_253 ;
if ( ! V_2 )
return - V_236 ;
if ( V_3 & ~ ( V_262 | V_279 | V_280 ) ) {
V_253 = - V_8 ;
goto V_84;
}
if ( V_3 & V_280 ) {
V_253 = F_208 ( V_170 -> V_63 , V_276 , V_188 ,
V_281 , V_282 ) ;
goto V_84;
}
V_253 = F_189 ( V_2 , V_38 , & V_276 -> V_277 , V_3 & V_262 ) ;
if ( V_253 > ( T_12 ) V_188 ) {
V_276 -> V_278 |= V_279 ;
V_253 = V_3 & V_279 ? V_253 : V_188 ;
}
V_84:
F_89 ( V_2 ) ;
return V_253 ;
}
static int F_209 ( struct V_1 * V_2 )
{
return V_2 -> V_3 & ( V_283 | V_70 | V_156 | V_164 ) ;
}
static T_12 F_210 ( struct V_284 * V_46 , struct V_285 * V_286 ,
char * V_287 )
{
struct V_1 * V_2 = F_41 ( F_211 ( V_46 ) ) ;
return sprintf ( V_287 , L_11 , F_209 ( V_2 ) ) ;
}
static T_12 F_212 ( struct V_284 * V_46 , struct V_285 * V_286 ,
char * V_287 )
{
struct V_1 * V_2 = F_41 ( F_211 ( V_46 ) ) ;
return F_49 ( V_2 -> V_55 ) ?
sprintf ( V_287 , L_12 ,
F_213 ( F_214 () , V_2 -> V_55 ) ) :
sprintf ( V_287 , L_13 ) ;
}
static T_12 F_215 ( struct V_284 * V_46 , struct V_285 * V_286 ,
char * V_287 )
{
struct V_1 * V_2 = F_41 ( F_211 ( V_46 ) ) ;
return F_51 ( V_2 -> V_57 ) ?
sprintf ( V_287 , L_12 ,
F_216 ( F_214 () , V_2 -> V_57 ) ) :
sprintf ( V_287 , L_13 ) ;
}
static int F_217 ( struct V_54 * V_54 , struct V_79 * V_79 , struct V_288 * V_289 )
{
struct V_1 * V_2 ;
struct V_37 * V_38 = V_79 -> V_81 ;
struct V_45 * V_46 ;
int V_82 ;
if ( V_38 -> V_41 )
return - V_8 ;
V_46 = F_218 ( V_54 , V_289 -> V_290 ) ;
if ( V_46 ) {
if ( V_289 -> V_291 & V_292 )
return - V_85 ;
if ( ( V_289 -> V_291 & V_156 ) && V_46 -> V_157 == & V_158 )
V_2 = F_41 ( V_46 ) ;
else if ( ( V_289 -> V_291 & V_164 ) && V_46 -> V_157 == & V_165 )
V_2 = F_41 ( V_46 ) ;
else
return - V_8 ;
if ( ! ! ( V_289 -> V_291 & V_86 ) !=
! ! ( V_2 -> V_3 & V_86 ) )
return - V_8 ;
if ( F_46 ( V_2 ) )
return - V_293 ;
V_82 = F_219 ( V_2 -> V_83 ) ;
if ( V_82 < 0 )
return V_82 ;
V_82 = F_79 ( V_2 , V_79 , V_289 -> V_291 & V_294 ) ;
if ( V_82 < 0 )
return V_82 ;
if ( V_2 -> V_3 & V_86 &&
( V_2 -> V_40 + V_2 -> V_62 > 1 ) ) {
return 0 ;
}
}
else {
char * V_295 ;
unsigned long V_3 = 0 ;
int V_296 = V_289 -> V_291 & V_86 ?
V_88 : 1 ;
if ( ! F_53 ( V_54 -> V_58 , V_59 ) )
return - V_293 ;
V_82 = F_220 () ;
if ( V_82 < 0 )
return V_82 ;
if ( V_289 -> V_291 & V_156 ) {
V_3 |= V_156 ;
V_295 = L_14 ;
} else if ( V_289 -> V_291 & V_164 ) {
V_3 |= V_164 ;
V_295 = L_15 ;
} else
return - V_8 ;
if ( * V_289 -> V_290 )
V_295 = V_289 -> V_290 ;
V_46 = F_221 ( sizeof( struct V_1 ) , V_295 ,
V_297 , F_199 , V_296 ,
V_296 ) ;
if ( ! V_46 )
return - V_103 ;
F_222 ( V_46 , V_54 ) ;
V_46 -> V_298 = & V_299 ;
V_46 -> V_300 = V_38 -> V_300 ;
V_46 -> V_301 [ 0 ] = & V_302 ;
V_2 = F_41 ( V_46 ) ;
V_2 -> V_46 = V_46 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_114 . V_34 = 0 ;
V_2 -> V_198 = sizeof( struct V_189 ) ;
V_2 -> V_137 = V_136 ;
V_2 -> V_89 = false ;
V_2 -> V_303 = V_38 -> V_74 . V_63 -> V_304 ;
V_2 -> V_124 = F_223 ( struct V_142 ) ;
if ( ! V_2 -> V_124 ) {
V_82 = - V_103 ;
goto V_305;
}
F_224 ( & V_2 -> V_26 ) ;
V_82 = F_225 ( & V_2 -> V_83 ) ;
if ( V_82 < 0 )
goto V_306;
F_138 ( V_46 ) ;
F_133 ( V_2 ) ;
V_46 -> V_307 = V_308 | V_309 |
V_134 | V_310 |
V_311 ;
V_46 -> V_132 = V_46 -> V_307 | V_312 ;
V_46 -> V_313 = V_46 -> V_132 &
~ ( V_310 |
V_311 ) ;
F_226 ( & V_2 -> V_61 ) ;
V_82 = F_79 ( V_2 , V_79 , false ) ;
if ( V_82 < 0 )
goto V_314;
V_82 = F_227 ( V_2 -> V_46 ) ;
if ( V_82 < 0 )
goto V_315;
}
F_228 ( V_2 -> V_46 ) ;
F_17 ( V_18 , V_2 , L_16 ) ;
V_2 -> V_3 = ( V_2 -> V_3 & ~ V_283 ) |
( V_289 -> V_291 & V_283 ) ;
if ( F_229 ( V_2 -> V_46 ) )
F_230 ( V_2 -> V_46 ) ;
strcpy ( V_289 -> V_290 , V_2 -> V_46 -> V_295 ) ;
return 0 ;
V_315:
F_75 ( V_46 ) ;
V_314:
F_136 ( V_2 ) ;
F_197 ( V_2 -> V_83 ) ;
V_306:
F_196 ( V_2 -> V_124 ) ;
V_305:
F_198 ( V_46 ) ;
return V_82 ;
}
static void F_231 ( struct V_54 * V_54 , struct V_1 * V_2 ,
struct V_288 * V_289 )
{
F_17 ( V_18 , V_2 , L_17 ) ;
strcpy ( V_289 -> V_290 , V_2 -> V_46 -> V_295 ) ;
V_289 -> V_291 = F_209 ( V_2 ) ;
}
static int F_232 ( struct V_1 * V_2 , unsigned long V_96 )
{
T_9 V_132 = 0 ;
if ( V_96 & V_316 ) {
V_132 |= V_317 ;
V_96 &= ~ V_316 ;
if ( V_96 & ( V_318 | V_319 ) ) {
if ( V_96 & V_320 ) {
V_132 |= V_321 ;
V_96 &= ~ V_320 ;
}
if ( V_96 & V_318 )
V_132 |= V_322 ;
if ( V_96 & V_319 )
V_132 |= V_323 ;
V_96 &= ~ ( V_318 | V_319 ) ;
}
if ( V_96 & V_324 ) {
V_132 |= V_325 ;
V_96 &= ~ V_324 ;
}
}
if ( V_96 )
return - V_8 ;
V_2 -> V_133 = V_132 ;
F_233 ( V_2 -> V_46 ) ;
return 0 ;
}
static void F_234 ( struct V_1 * V_2 , int V_29 )
{
int V_25 ;
struct V_37 * V_38 ;
for ( V_25 = 0 ; V_25 < V_29 ; V_25 ++ ) {
V_38 = F_64 ( V_2 -> V_69 [ V_25 ] ) ;
F_81 ( V_38 -> V_74 . V_63 ) ;
F_235 ( V_38 -> V_74 . V_63 ) ;
F_83 ( V_38 -> V_74 . V_63 ) ;
}
V_2 -> V_89 = false ;
}
static int F_236 ( struct V_1 * V_2 )
{
int V_25 , V_253 = 0 ;
struct V_37 * V_38 ;
for ( V_25 = 0 ; V_25 < V_2 -> V_40 ; V_25 ++ ) {
V_38 = F_64 ( V_2 -> V_69 [ V_25 ] ) ;
F_81 ( V_38 -> V_74 . V_63 ) ;
V_253 = F_82 ( & V_2 -> V_90 , V_38 -> V_74 . V_63 ) ;
F_83 ( V_38 -> V_74 . V_63 ) ;
if ( V_253 ) {
F_234 ( V_2 , V_25 ) ;
return V_253 ;
}
}
V_2 -> V_89 = true ;
return V_253 ;
}
static void F_237 ( struct V_1 * V_2 )
{
struct V_37 * V_38 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_2 -> V_40 ; V_25 ++ ) {
V_38 = F_64 ( V_2 -> V_69 [ V_25 ] ) ;
V_38 -> V_74 . V_63 -> V_304 = V_2 -> V_303 ;
}
}
static int F_238 ( struct V_79 * V_79 , struct V_288 * V_289 )
{
struct V_37 * V_38 = V_79 -> V_81 ;
struct V_1 * V_2 ;
int V_253 = 0 ;
F_73 () ;
if ( V_289 -> V_291 & V_326 ) {
V_2 = V_38 -> V_41 ;
if ( ! V_2 ) {
V_253 = - V_8 ;
goto V_42;
}
V_253 = F_239 ( V_2 -> V_83 ) ;
if ( V_253 < 0 )
goto V_42;
V_253 = F_79 ( V_2 , V_79 , false ) ;
} else if ( V_289 -> V_291 & V_327 ) {
V_2 = F_64 ( V_38 -> V_2 ) ;
if ( ! V_2 || ! ( V_2 -> V_3 & V_86 ) || V_38 -> V_41 )
V_253 = - V_8 ;
else
F_63 ( V_38 , false ) ;
} else
V_253 = - V_8 ;
V_42:
F_74 () ;
return V_253 ;
}
static long F_240 ( struct V_79 * V_79 , unsigned int V_328 ,
unsigned long V_96 , int V_329 )
{
struct V_37 * V_38 = V_79 -> V_81 ;
struct V_1 * V_2 ;
void T_1 * V_5 = ( void T_1 * ) V_96 ;
struct V_288 V_289 ;
T_15 V_55 ;
T_16 V_57 ;
int V_303 ;
int V_198 ;
unsigned int V_300 ;
int V_330 ;
int V_253 ;
if ( V_328 == V_331 || V_328 == V_332 || F_241 ( V_328 ) == 0x89 ) {
if ( F_95 ( & V_289 , V_5 , V_329 ) )
return - V_7 ;
} else {
memset ( & V_289 , 0 , sizeof( V_289 ) ) ;
}
if ( V_328 == V_333 ) {
return F_4 ( V_156 | V_164 | V_283 ,
( unsigned int T_1 * ) V_5 ) ;
} else if ( V_328 == V_332 )
return F_238 ( V_79 , & V_289 ) ;
V_253 = 0 ;
F_73 () ;
V_2 = F_85 ( V_38 ) ;
if ( V_328 == V_331 && ! V_2 ) {
V_289 . V_290 [ V_334 - 1 ] = '\0' ;
V_253 = F_217 ( F_242 ( & V_38 -> V_63 ) , V_79 , & V_289 ) ;
if ( V_253 )
goto V_42;
if ( F_243 ( V_5 , & V_289 , V_329 ) )
V_253 = - V_7 ;
goto V_42;
}
if ( V_328 == V_335 ) {
V_253 = - V_293 ;
if ( V_2 )
goto V_42;
V_253 = - V_7 ;
if ( F_95 ( & V_300 , V_5 , sizeof( V_300 ) ) )
goto V_42;
V_253 = 0 ;
V_38 -> V_300 = V_300 ;
goto V_42;
}
V_253 = - V_236 ;
if ( ! V_2 )
goto V_42;
F_17 ( V_18 , V_2 , L_18 , V_328 ) ;
V_253 = 0 ;
switch ( V_328 ) {
case V_336 :
F_231 ( V_337 -> V_338 -> V_339 , V_2 , & V_289 ) ;
if ( V_38 -> V_41 )
V_289 . V_291 |= V_327 ;
if ( ! V_38 -> V_74 . V_63 -> V_115 )
V_289 . V_291 |= V_294 ;
if ( F_243 ( V_5 , & V_289 , V_329 ) )
V_253 = - V_7 ;
break;
case V_340 :
F_17 ( V_18 , V_2 , L_19 ,
V_96 ? L_20 : L_21 ) ;
break;
case V_341 :
if ( V_96 && ! ( V_2 -> V_3 & V_70 ) ) {
V_2 -> V_3 |= V_70 ;
F_244 ( V_78 ) ;
}
if ( ! V_96 && ( V_2 -> V_3 & V_70 ) ) {
V_2 -> V_3 &= ~ V_70 ;
F_78 ( V_78 ) ;
}
F_17 ( V_18 , V_2 , L_22 ,
V_96 ? L_21 : L_20 ) ;
break;
case V_342 :
V_55 = F_245 ( F_214 () , V_96 ) ;
if ( ! F_49 ( V_55 ) ) {
V_253 = - V_8 ;
break;
}
V_2 -> V_55 = V_55 ;
F_17 ( V_18 , V_2 , L_23 ,
F_246 ( & V_343 , V_2 -> V_55 ) ) ;
break;
case V_344 :
V_57 = F_247 ( F_214 () , V_96 ) ;
if ( ! F_51 ( V_57 ) ) {
V_253 = - V_8 ;
break;
}
V_2 -> V_57 = V_57 ;
F_17 ( V_18 , V_2 , L_24 ,
F_248 ( & V_343 , V_2 -> V_57 ) ) ;
break;
case V_345 :
if ( V_2 -> V_46 -> V_3 & V_194 ) {
F_17 ( V_18 , V_2 ,
L_25 ) ;
V_253 = - V_85 ;
} else {
V_2 -> V_46 -> type = ( int ) V_96 ;
F_17 ( V_18 , V_2 , L_26 ,
V_2 -> V_46 -> type ) ;
V_253 = 0 ;
}
break;
#ifdef F_249
case V_346 :
V_2 -> V_347 = V_96 ;
break;
#endif
case V_348 :
V_253 = F_232 ( V_2 , V_96 ) ;
break;
case V_349 :
V_253 = - V_8 ;
if ( ( V_2 -> V_3 & V_155 ) != V_164 )
break;
V_253 = F_94 ( & V_2 -> V_114 , ( void T_1 * ) V_96 ) ;
break;
case V_350 :
memcpy ( V_289 . V_351 . V_352 , V_2 -> V_46 -> V_353 , V_93 ) ;
V_289 . V_351 . V_354 = V_2 -> V_46 -> type ;
if ( F_243 ( V_5 , & V_289 , V_329 ) )
V_253 = - V_7 ;
break;
case V_355 :
F_17 ( V_356 , V_2 , L_27 ,
V_289 . V_351 . V_352 ) ;
V_253 = F_250 ( V_2 -> V_46 , & V_289 . V_351 ) ;
break;
case V_357 :
V_303 = V_38 -> V_74 . V_63 -> V_304 ;
if ( F_243 ( V_5 , & V_303 , sizeof( V_303 ) ) )
V_253 = - V_7 ;
break;
case V_358 :
if ( F_95 ( & V_303 , V_5 , sizeof( V_303 ) ) ) {
V_253 = - V_7 ;
break;
}
V_2 -> V_303 = V_303 ;
F_237 ( V_2 ) ;
break;
case V_359 :
V_198 = V_2 -> V_198 ;
if ( F_243 ( V_5 , & V_198 , sizeof( V_198 ) ) )
V_253 = - V_7 ;
break;
case V_360 :
if ( F_95 ( & V_198 , V_5 , sizeof( V_198 ) ) ) {
V_253 = - V_7 ;
break;
}
if ( V_198 < ( int ) sizeof( struct V_189 ) ) {
V_253 = - V_8 ;
break;
}
V_2 -> V_198 = V_198 ;
break;
case V_361 :
V_330 = ! ! ( V_2 -> V_3 & V_9 ) ;
if ( F_4 ( V_330 , ( int T_1 * ) V_5 ) )
V_253 = - V_7 ;
break;
case V_362 :
if ( F_6 ( V_330 , ( int T_1 * ) V_5 ) ) {
V_253 = - V_7 ;
break;
}
if ( V_330 )
V_2 -> V_3 |= V_9 ;
else
V_2 -> V_3 &= ~ V_9 ;
break;
case V_363 :
V_253 = F_3 ( V_2 , V_5 ) ;
break;
case V_364 :
V_253 = F_5 ( V_2 , V_5 ) ;
break;
case V_365 :
V_253 = - V_8 ;
if ( ( V_2 -> V_3 & V_155 ) != V_164 )
break;
V_253 = - V_7 ;
if ( F_95 ( & V_2 -> V_90 , V_5 , sizeof( V_2 -> V_90 ) ) )
break;
V_253 = F_236 ( V_2 ) ;
break;
case V_366 :
V_253 = - V_8 ;
if ( ( V_2 -> V_3 & V_155 ) != V_164 )
break;
V_253 = 0 ;
F_234 ( V_2 , V_2 -> V_40 ) ;
break;
case V_367 :
V_253 = - V_8 ;
if ( ( V_2 -> V_3 & V_155 ) != V_164 )
break;
V_253 = - V_7 ;
if ( F_243 ( V_5 , & V_2 -> V_90 , sizeof( V_2 -> V_90 ) ) )
break;
V_253 = 0 ;
break;
default:
V_253 = - V_8 ;
break;
}
V_42:
F_74 () ;
if ( V_2 )
F_89 ( V_2 ) ;
return V_253 ;
}
static long F_251 ( struct V_79 * V_79 ,
unsigned int V_328 , unsigned long V_96 )
{
return F_240 ( V_79 , V_328 , V_96 , sizeof ( struct V_288 ) ) ;
}
static long F_252 ( struct V_79 * V_79 ,
unsigned int V_328 , unsigned long V_96 )
{
switch ( V_328 ) {
case V_331 :
case V_336 :
case V_349 :
case V_357 :
case V_358 :
case V_350 :
case V_355 :
V_96 = ( unsigned long ) F_253 ( V_96 ) ;
break;
default:
V_96 = ( V_368 ) V_96 ;
break;
}
return F_240 ( V_79 , V_328 , V_96 , sizeof( struct V_369 ) ) ;
}
static int F_254 ( int V_370 , struct V_79 * V_79 , int V_371 )
{
struct V_37 * V_38 = V_79 -> V_81 ;
int V_253 ;
if ( ( V_253 = F_255 ( V_370 , V_79 , V_371 , & V_38 -> V_120 ) ) < 0 )
goto V_84;
if ( V_371 ) {
F_256 ( V_79 , F_257 ( V_337 ) , V_372 , 0 ) ;
V_38 -> V_3 |= V_119 ;
} else
V_38 -> V_3 &= ~ V_119 ;
V_253 = 0 ;
V_84:
return V_253 ;
}
static int F_258 ( struct V_373 * V_373 , struct V_79 * V_79 )
{
struct V_54 * V_54 = V_337 -> V_338 -> V_339 ;
struct V_37 * V_38 ;
F_259 ( V_18 , L_28 ) ;
V_38 = (struct V_37 * ) F_260 ( V_54 , V_374 , V_102 ,
& V_375 , 0 ) ;
if ( ! V_38 )
return - V_103 ;
F_67 ( V_38 -> V_2 , NULL ) ;
V_38 -> V_3 = 0 ;
V_38 -> V_300 = 0 ;
F_261 ( & V_38 -> V_376 . V_169 ) ;
F_67 ( V_38 -> V_74 . V_376 , & V_38 -> V_376 ) ;
V_38 -> V_74 . V_79 = V_79 ;
V_38 -> V_74 . V_377 = & V_378 ;
F_262 ( & V_38 -> V_74 , & V_38 -> V_63 ) ;
V_38 -> V_63 . V_379 = F_201 ;
V_38 -> V_63 . V_304 = V_206 ;
V_79 -> V_81 = V_38 ;
F_226 ( & V_38 -> V_60 ) ;
F_263 ( & V_38 -> V_63 , V_380 ) ;
return 0 ;
}
static int F_264 ( struct V_373 * V_373 , struct V_79 * V_79 )
{
struct V_37 * V_38 = V_79 -> V_81 ;
F_72 ( V_38 , true ) ;
return 0 ;
}
static void F_265 ( struct V_381 * V_276 , struct V_79 * V_382 )
{
struct V_1 * V_2 ;
struct V_288 V_289 ;
memset ( & V_289 , 0 , sizeof( V_289 ) ) ;
F_73 () ;
V_2 = F_88 ( V_382 ) ;
if ( V_2 )
F_231 ( V_337 -> V_338 -> V_339 , V_2 , & V_289 ) ;
F_74 () ;
if ( V_2 )
F_89 ( V_2 ) ;
F_266 ( V_276 , L_29 , V_289 . V_290 ) ;
}
static int F_267 ( struct V_45 * V_46 , struct V_383 * V_328 )
{
V_328 -> V_384 = 0 ;
V_328 -> V_385 = 0 ;
F_268 ( V_328 , V_386 ) ;
V_328 -> V_387 = V_388 ;
V_328 -> V_389 = V_390 ;
V_328 -> V_391 = 0 ;
V_328 -> V_392 = V_393 ;
V_328 -> V_394 = V_395 ;
V_328 -> V_396 = 0 ;
V_328 -> V_397 = 0 ;
return 0 ;
}
static void F_269 ( struct V_45 * V_46 , struct V_398 * V_399 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
F_270 ( V_399 -> V_400 , V_401 , sizeof( V_399 -> V_400 ) ) ;
F_270 ( V_399 -> V_402 , V_403 , sizeof( V_399 -> V_402 ) ) ;
switch ( V_2 -> V_3 & V_155 ) {
case V_156 :
F_270 ( V_399 -> V_404 , L_30 , sizeof( V_399 -> V_404 ) ) ;
break;
case V_164 :
F_270 ( V_399 -> V_404 , L_31 , sizeof( V_399 -> V_404 ) ) ;
break;
}
}
static T_4 F_271 ( struct V_45 * V_46 )
{
#ifdef F_249
struct V_1 * V_2 = F_41 ( V_46 ) ;
return V_2 -> V_347 ;
#else
return - V_405 ;
#endif
}
static void F_272 ( struct V_45 * V_46 , T_4 V_406 )
{
#ifdef F_249
struct V_1 * V_2 = F_41 ( V_46 ) ;
V_2 -> V_347 = V_406 ;
#endif
}
static int T_17 F_273 ( void )
{
int V_253 = 0 ;
F_274 ( L_32 , V_407 , V_403 ) ;
F_274 ( L_33 , V_408 ) ;
V_253 = F_275 ( & V_299 ) ;
if ( V_253 ) {
F_181 ( L_34 ) ;
goto V_409;
}
V_253 = F_276 ( & V_410 ) ;
if ( V_253 ) {
F_181 ( L_35 , V_411 ) ;
goto V_412;
}
return 0 ;
V_412:
F_277 ( & V_299 ) ;
V_409:
return V_253 ;
}
static void F_278 ( void )
{
F_279 ( & V_410 ) ;
F_277 ( & V_299 ) ;
}
struct V_74 * F_280 ( struct V_79 * V_79 )
{
struct V_37 * V_38 ;
if ( V_79 -> V_413 != & V_414 )
return F_149 ( - V_8 ) ;
V_38 = V_79 -> V_81 ;
if ( ! V_38 )
return F_149 ( - V_236 ) ;
return & V_38 -> V_74 ;
}
