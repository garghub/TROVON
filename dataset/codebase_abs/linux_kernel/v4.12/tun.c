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
F_64 ( & V_38 -> V_64 . V_66 ) ;
}
static void F_65 ( struct V_37 * V_38 , bool V_67 )
{
struct V_37 * V_68 ;
struct V_1 * V_2 ;
V_2 = F_66 ( V_38 -> V_2 ) ;
if ( V_2 && ! V_38 -> V_41 ) {
T_2 V_69 = V_38 -> V_16 ;
F_67 ( V_69 >= V_2 -> V_40 ) ;
F_68 ( V_2 -> V_70 [ V_69 ] ,
V_2 -> V_70 [ V_2 -> V_40 - 1 ] ) ;
V_68 = F_66 ( V_2 -> V_70 [ V_69 ] ) ;
V_68 -> V_16 = V_69 ;
-- V_2 -> V_40 ;
if ( V_67 ) {
F_69 ( V_38 -> V_2 , NULL ) ;
F_70 ( & V_38 -> V_64 ) ;
} else
F_57 ( V_2 , V_38 ) ;
F_71 () ;
F_26 ( V_2 , V_2 -> V_40 + 1 ) ;
F_61 ( V_38 ) ;
F_54 ( V_2 ) ;
} else if ( V_38 -> V_41 && V_67 ) {
V_2 = F_59 ( V_38 ) ;
F_70 ( & V_38 -> V_64 ) ;
}
if ( V_67 ) {
if ( V_2 && V_2 -> V_40 == 0 && V_2 -> V_62 == 0 ) {
F_72 ( V_2 -> V_46 ) ;
if ( ! ( V_2 -> V_3 & V_71 ) &&
V_2 -> V_46 -> V_72 == V_73 )
F_73 ( V_2 -> V_46 ) ;
}
if ( V_2 )
F_74 ( & V_38 -> V_63 ) ;
F_70 ( & V_38 -> V_64 ) ;
}
}
static void F_75 ( struct V_37 * V_38 , bool V_67 )
{
F_76 () ;
F_65 ( V_38 , V_67 ) ;
F_77 () ;
}
static void F_78 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
struct V_37 * V_38 , * V_74 ;
int V_25 , V_29 = V_2 -> V_40 ;
for ( V_25 = 0 ; V_25 < V_29 ; V_25 ++ ) {
V_38 = F_66 ( V_2 -> V_70 [ V_25 ] ) ;
F_67 ( ! V_38 ) ;
V_38 -> V_75 . V_64 -> V_76 = V_77 ;
V_38 -> V_75 . V_64 -> V_78 ( V_38 -> V_75 . V_64 ) ;
F_69 ( V_38 -> V_2 , NULL ) ;
-- V_2 -> V_40 ;
}
F_79 (tfile, &tun->disabled, next) {
V_38 -> V_75 . V_64 -> V_76 = V_77 ;
V_38 -> V_75 . V_64 -> V_78 ( V_38 -> V_75 . V_64 ) ;
F_69 ( V_38 -> V_2 , NULL ) ;
}
F_67 ( V_2 -> V_40 != 0 ) ;
F_71 () ;
for ( V_25 = 0 ; V_25 < V_29 ; V_25 ++ ) {
V_38 = F_66 ( V_2 -> V_70 [ V_25 ] ) ;
F_61 ( V_38 ) ;
F_70 ( & V_38 -> V_64 ) ;
}
F_80 (tfile, tmp, &tun->disabled, next) {
F_59 ( V_38 ) ;
F_61 ( V_38 ) ;
F_70 ( & V_38 -> V_64 ) ;
}
F_67 ( V_2 -> V_62 != 0 ) ;
if ( V_2 -> V_3 & V_71 )
F_81 ( V_79 ) ;
}
static int F_82 ( struct V_1 * V_2 , struct V_80 * V_80 , bool V_81 )
{
struct V_37 * V_38 = V_80 -> V_82 ;
struct V_45 * V_46 = V_2 -> V_46 ;
int V_83 ;
V_83 = F_83 ( V_38 -> V_75 . V_64 , V_2 -> V_84 ) ;
if ( V_83 < 0 )
goto V_85;
V_83 = - V_8 ;
if ( F_66 ( V_38 -> V_2 ) && ! V_38 -> V_41 )
goto V_85;
V_83 = - V_86 ;
if ( ! ( V_2 -> V_3 & V_87 ) && V_2 -> V_40 == 1 )
goto V_85;
V_83 = - V_88 ;
if ( ! V_38 -> V_41 &&
V_2 -> V_40 + V_2 -> V_62 == V_89 )
goto V_85;
V_83 = 0 ;
if ( ! V_81 && ( V_2 -> V_90 == true ) ) {
F_84 ( V_38 -> V_75 . V_64 ) ;
V_83 = F_85 ( & V_2 -> V_91 , V_38 -> V_75 . V_64 ) ;
F_86 ( V_38 -> V_75 . V_64 ) ;
if ( ! V_83 )
goto V_85;
}
if ( ! V_38 -> V_41 &&
F_87 ( & V_38 -> V_63 , V_46 -> V_92 , V_93 ) ) {
V_83 = - V_94 ;
goto V_85;
}
V_38 -> V_16 = V_2 -> V_40 ;
V_38 -> V_75 . V_64 -> V_76 &= ~ V_77 ;
F_68 ( V_38 -> V_2 , V_2 ) ;
F_68 ( V_2 -> V_70 [ V_2 -> V_40 ] , V_38 ) ;
V_2 -> V_40 ++ ;
if ( V_38 -> V_41 )
F_59 ( V_38 ) ;
else
F_88 ( & V_38 -> V_64 ) ;
F_54 ( V_2 ) ;
V_85:
return V_83 ;
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
static struct V_1 * F_92 ( struct V_80 * V_80 )
{
return F_89 ( V_80 -> V_82 ) ;
}
static void F_93 ( struct V_1 * V_2 )
{
F_94 ( V_2 -> V_46 ) ;
}
static void F_95 ( T_4 * V_95 , const T_6 * V_96 )
{
int V_29 = F_96 ( V_97 , V_96 ) >> 26 ;
V_95 [ V_29 >> 5 ] |= ( 1 << ( V_29 & 31 ) ) ;
}
static unsigned int F_97 ( const T_4 * V_95 , const T_6 * V_96 )
{
int V_29 = F_96 ( V_97 , V_96 ) >> 26 ;
return V_95 [ V_29 >> 5 ] & ( 1 << ( V_29 & 31 ) ) ;
}
static int F_98 ( struct V_98 * V_99 , void T_1 * V_100 )
{
struct { T_6 V_101 [ V_97 ] ; } * V_96 ;
struct V_102 V_103 ;
int V_83 , V_104 , V_29 , V_105 ;
if ( F_99 ( & V_103 , V_100 , sizeof( V_103 ) ) )
return - V_7 ;
if ( ! V_103 . V_34 ) {
V_99 -> V_34 = 0 ;
return 0 ;
}
V_104 = V_97 * V_103 . V_34 ;
V_96 = F_100 ( V_100 + sizeof( V_103 ) , V_104 ) ;
if ( F_101 ( V_96 ) )
return F_102 ( V_96 ) ;
V_99 -> V_34 = 0 ;
F_103 () ;
for ( V_29 = 0 ; V_29 < V_103 . V_34 && V_29 < V_106 ; V_29 ++ )
memcpy ( V_99 -> V_96 [ V_29 ] , V_96 [ V_29 ] . V_101 , V_97 ) ;
V_105 = V_29 ;
memset ( V_99 -> V_95 , 0 , sizeof( V_99 -> V_95 ) ) ;
for (; V_29 < V_103 . V_34 ; V_29 ++ ) {
if ( ! F_104 ( V_96 [ V_29 ] . V_101 ) ) {
V_83 = 0 ;
goto V_107;
}
F_95 ( V_99 -> V_95 , V_96 [ V_29 ] . V_101 ) ;
}
if ( ( V_103 . V_3 & V_108 ) )
memset ( V_99 -> V_95 , ~ 0 , sizeof( V_99 -> V_95 ) ) ;
F_103 () ;
V_99 -> V_34 = V_105 ;
V_83 = V_105 ;
V_107:
F_105 ( V_96 ) ;
return V_83 ;
}
static int F_106 ( struct V_98 * V_99 , const struct V_47 * V_48 )
{
struct V_109 * V_110 = (struct V_109 * ) V_48 -> V_30 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_99 -> V_34 ; V_25 ++ )
if ( F_107 ( V_110 -> V_111 , V_99 -> V_96 [ V_25 ] ) )
return 1 ;
if ( F_104 ( V_110 -> V_111 ) )
return F_97 ( V_99 -> V_95 , V_110 -> V_111 ) ;
return 0 ;
}
static int F_108 ( struct V_98 * V_99 , const struct V_47 * V_48 )
{
if ( ! V_99 -> V_34 )
return 1 ;
return F_106 ( V_99 , V_48 ) ;
}
static void F_109 ( struct V_45 * V_46 )
{
F_78 ( V_46 ) ;
}
static int F_110 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
int V_25 ;
F_111 ( V_46 ) ;
for ( V_25 = 0 ; V_25 < V_2 -> V_40 ; V_25 ++ ) {
struct V_37 * V_38 ;
V_38 = F_66 ( V_2 -> V_70 [ V_25 ] ) ;
V_38 -> V_75 . V_64 -> V_112 ( V_38 -> V_75 . V_64 ) ;
}
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
int V_51 = V_48 -> V_113 ;
struct V_37 * V_38 ;
T_4 V_40 = 0 ;
F_33 () ;
V_38 = F_90 ( V_2 -> V_70 [ V_51 ] ) ;
V_40 = F_42 ( V_2 -> V_40 ) ;
if ( V_51 >= V_40 )
goto V_114;
#ifdef F_115
if ( V_40 == 1 && F_116 ( & V_115 ) ) {
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
F_17 ( V_18 , V_2 , L_4 , V_48 -> V_116 ) ;
F_67 ( ! V_38 ) ;
if ( ! F_108 ( & V_2 -> V_117 , V_48 ) )
goto V_114;
if ( V_38 -> V_75 . V_64 -> V_118 &&
V_118 ( V_38 -> V_75 . V_64 , V_48 ) )
goto V_114;
if ( F_39 ( F_117 ( V_48 , V_17 ) ) )
goto V_114;
F_118 ( V_48 ) ;
F_119 ( V_48 ) ;
F_120 ( V_48 ) ;
if ( F_121 ( & V_38 -> V_63 , V_48 ) )
goto V_114;
if ( V_38 -> V_3 & V_119 )
F_122 ( & V_38 -> V_120 , V_121 , V_122 ) ;
V_38 -> V_75 . V_64 -> V_78 ( V_38 -> V_75 . V_64 ) ;
F_37 () ;
return V_123 ;
V_114:
F_123 ( V_2 -> V_124 -> V_125 ) ;
F_124 ( V_48 ) ;
F_63 ( V_48 ) ;
F_37 () ;
return V_126 ;
}
static void F_125 ( struct V_45 * V_46 )
{
}
static T_9 F_126 ( struct V_45 * V_46 ,
T_9 V_127 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
return ( V_127 & V_2 -> V_128 ) | ( V_127 & ~ V_129 ) ;
}
static void F_127 ( struct V_45 * V_46 )
{
return;
}
static void F_128 ( struct V_45 * V_46 , int V_130 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
if ( V_130 < V_131 )
V_130 = V_131 ;
V_2 -> V_132 = V_130 ;
}
static void
F_129 ( struct V_45 * V_46 , struct V_133 * V_134 )
{
T_4 V_135 = 0 , V_125 = 0 , V_136 = 0 ;
struct V_1 * V_2 = F_41 ( V_46 ) ;
struct V_137 * V_138 ;
int V_25 ;
F_130 (i) {
V_52 V_139 , V_140 , V_141 , V_142 ;
unsigned int V_143 ;
V_138 = F_131 ( V_2 -> V_124 , V_25 ) ;
do {
V_143 = F_132 ( & V_138 -> V_144 ) ;
V_139 = V_138 -> V_145 ;
V_140 = V_138 -> V_146 ;
V_141 = V_138 -> V_147 ;
V_142 = V_138 -> V_148 ;
} while ( F_133 ( & V_138 -> V_144 , V_143 ) );
V_134 -> V_145 += V_139 ;
V_134 -> V_146 += V_140 ;
V_134 -> V_147 += V_141 ;
V_134 -> V_148 += V_142 ;
V_135 += V_138 -> V_135 ;
V_136 += V_138 -> V_136 ;
V_125 += V_138 -> V_125 ;
}
V_134 -> V_135 = V_135 ;
V_134 -> V_136 = V_136 ;
V_134 -> V_125 = V_125 ;
}
static void F_134 ( struct V_1 * V_2 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_27 ; V_25 ++ )
F_135 ( & V_2 -> V_39 [ V_25 ] ) ;
V_2 -> V_32 = V_149 ;
F_136 ( & V_2 -> V_36 , F_27 , ( unsigned long ) V_2 ) ;
F_30 ( & V_2 -> V_36 ,
F_31 ( V_20 + V_2 -> V_32 ) ) ;
}
static void F_137 ( struct V_1 * V_2 )
{
F_138 ( & V_2 -> V_36 ) ;
F_22 ( V_2 ) ;
}
static void F_139 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
switch ( V_2 -> V_3 & V_150 ) {
case V_151 :
V_46 -> V_152 = & V_153 ;
V_46 -> V_154 = 0 ;
V_46 -> V_155 = 0 ;
V_46 -> V_156 = 1500 ;
V_46 -> type = V_157 ;
V_46 -> V_3 = V_158 | V_159 | V_160 ;
break;
case V_161 :
V_46 -> V_152 = & V_162 ;
F_140 ( V_46 ) ;
V_46 -> V_163 &= ~ V_164 ;
V_46 -> V_163 |= V_165 ;
F_141 ( V_46 ) ;
break;
}
V_46 -> V_166 = V_167 ;
V_46 -> V_168 = V_169 - V_46 -> V_154 ;
}
static unsigned int F_142 ( struct V_80 * V_80 , T_10 * V_170 )
{
struct V_37 * V_38 = V_80 -> V_82 ;
struct V_1 * V_2 = F_89 ( V_38 ) ;
struct V_171 * V_64 ;
unsigned int V_95 = 0 ;
if ( ! V_2 )
return V_172 ;
V_64 = V_38 -> V_75 . V_64 ;
F_17 ( V_18 , V_2 , L_5 ) ;
F_143 ( V_80 , F_144 ( V_64 ) , V_170 ) ;
if ( ! F_145 ( & V_38 -> V_63 ) )
V_95 |= V_173 | V_174 ;
if ( V_2 -> V_46 -> V_3 & V_175 &&
( F_146 ( V_64 ) ||
( ! F_147 ( V_176 , & V_64 -> V_177 -> V_3 ) &&
F_146 ( V_64 ) ) ) )
V_95 |= V_178 | V_179 ;
if ( V_2 -> V_46 -> V_72 != V_73 )
V_95 = V_172 ;
F_93 ( V_2 ) ;
return V_95 ;
}
static struct V_47 * F_148 ( struct V_37 * V_38 ,
T_11 V_180 , T_11 V_116 ,
T_11 V_181 , int V_182 )
{
struct V_171 * V_64 = V_38 -> V_75 . V_64 ;
struct V_47 * V_48 ;
int V_83 ;
if ( V_180 + V_116 < V_183 || ! V_181 )
V_181 = V_116 ;
V_48 = F_149 ( V_64 , V_180 + V_181 , V_116 - V_181 , V_182 ,
& V_83 , 0 ) ;
if ( ! V_48 )
return F_150 ( V_83 ) ;
F_151 ( V_48 , V_180 ) ;
F_152 ( V_48 , V_181 ) ;
V_48 -> V_184 = V_116 - V_181 ;
V_48 -> V_116 += V_116 - V_181 ;
return V_48 ;
}
static void F_153 ( struct V_1 * V_2 , struct V_37 * V_38 ,
struct V_47 * V_48 , int V_185 )
{
struct V_186 * V_187 = & V_38 -> V_64 . V_65 ;
struct V_186 V_188 ;
T_4 V_189 = V_2 -> V_189 ;
bool V_190 = false ;
if ( ! V_189 || ( ! V_185 && F_154 ( V_187 ) ) ) {
F_155 () ;
F_156 ( V_48 ) ;
F_157 () ;
return;
}
F_158 ( & V_187 -> V_26 ) ;
if ( ! V_185 || F_159 ( V_187 ) == V_189 ) {
F_160 ( & V_188 ) ;
F_161 ( V_187 , & V_188 ) ;
V_190 = true ;
} else {
F_162 ( V_187 , V_48 ) ;
}
F_163 ( & V_187 -> V_26 ) ;
if ( V_190 ) {
struct V_47 * V_191 ;
F_155 () ;
while ( ( V_191 = F_164 ( & V_188 ) ) )
F_156 ( V_191 ) ;
F_156 ( V_48 ) ;
F_157 () ;
}
}
static T_12 F_165 ( struct V_1 * V_2 , struct V_37 * V_38 ,
void * V_192 , struct V_193 * V_194 ,
int V_182 , bool V_185 )
{
struct V_195 V_196 = { 0 , F_166 (ETH_P_IP) } ;
struct V_47 * V_48 ;
T_11 V_197 = F_167 ( V_194 ) ;
T_11 V_116 = V_197 , V_132 = V_2 -> V_132 , V_181 ;
struct V_198 V_199 = { 0 } ;
struct V_137 * V_134 ;
int V_200 ;
int V_201 ;
bool V_202 = false ;
int V_83 ;
T_4 V_11 ;
if ( ! ( V_2 -> V_46 -> V_3 & V_175 ) )
return - V_203 ;
if ( ! ( V_2 -> V_3 & V_204 ) ) {
if ( V_116 < sizeof( V_196 ) )
return - V_8 ;
V_116 -= sizeof( V_196 ) ;
if ( ! F_168 ( & V_196 , sizeof( V_196 ) , V_194 ) )
return - V_7 ;
}
if ( V_2 -> V_3 & V_205 ) {
int V_206 = F_169 ( V_2 -> V_206 ) ;
if ( V_116 < V_206 )
return - V_8 ;
V_116 -= V_206 ;
if ( ! F_168 ( & V_199 , sizeof( V_199 ) , V_194 ) )
return - V_7 ;
if ( ( V_199 . V_3 & V_207 ) &&
F_8 ( V_2 , V_199 . V_208 ) + F_8 ( V_2 , V_199 . V_209 ) + 2 > F_8 ( V_2 , V_199 . V_210 ) )
V_199 . V_210 = F_10 ( V_2 , F_8 ( V_2 , V_199 . V_208 ) + F_8 ( V_2 , V_199 . V_209 ) + 2 ) ;
if ( F_8 ( V_2 , V_199 . V_210 ) > V_116 )
return - V_8 ;
F_170 ( V_194 , V_206 - sizeof( V_199 ) ) ;
}
if ( ( V_2 -> V_3 & V_150 ) == V_161 ) {
V_132 += V_211 ;
if ( F_39 ( V_116 < V_212 ||
( V_199 . V_210 && F_8 ( V_2 , V_199 . V_210 ) < V_212 ) ) )
return - V_8 ;
}
V_200 = F_171 ( V_132 ) ;
if ( V_192 ) {
struct V_193 V_25 = * V_194 ;
V_201 = V_199 . V_210 ? F_8 ( V_2 , V_199 . V_210 ) : V_213 ;
if ( V_201 > V_200 )
V_201 = V_200 ;
V_181 = V_201 ;
F_170 ( & V_25 , V_201 ) ;
if ( F_172 ( & V_25 , V_214 ) <= V_215 )
V_202 = true ;
}
if ( ! V_202 ) {
V_201 = V_116 ;
if ( F_8 ( V_2 , V_199 . V_210 ) > V_200 )
V_181 = V_200 ;
else
V_181 = F_8 ( V_2 , V_199 . V_210 ) ;
}
V_48 = F_148 ( V_38 , V_132 , V_201 , V_181 , V_182 ) ;
if ( F_101 ( V_48 ) ) {
if ( F_102 ( V_48 ) != - V_216 )
F_123 ( V_2 -> V_124 -> V_135 ) ;
return F_102 ( V_48 ) ;
}
if ( V_202 )
V_83 = F_173 ( V_48 , V_194 ) ;
else
V_83 = F_174 ( V_48 , 0 , V_194 , V_116 ) ;
if ( V_83 ) {
F_123 ( V_2 -> V_124 -> V_135 ) ;
F_63 ( V_48 ) ;
return - V_7 ;
}
if ( F_175 ( V_48 , & V_199 , F_7 ( V_2 ) ) ) {
F_123 ( V_2 -> V_124 -> V_136 ) ;
F_63 ( V_48 ) ;
return - V_8 ;
}
switch ( V_2 -> V_3 & V_150 ) {
case V_151 :
if ( V_2 -> V_3 & V_204 ) {
switch ( V_48 -> V_30 [ 0 ] & 0xf0 ) {
case 0x40 :
V_196 . V_217 = F_176 ( V_218 ) ;
break;
case 0x60 :
V_196 . V_217 = F_176 ( V_219 ) ;
break;
default:
F_123 ( V_2 -> V_124 -> V_135 ) ;
F_63 ( V_48 ) ;
return - V_8 ;
}
}
F_177 ( V_48 ) ;
V_48 -> V_220 = V_196 . V_217 ;
V_48 -> V_46 = V_2 -> V_46 ;
break;
case V_161 :
V_48 -> V_220 = F_178 ( V_48 , V_2 -> V_46 ) ;
break;
}
if ( V_202 ) {
F_179 ( V_48 ) -> V_221 = V_192 ;
F_179 ( V_48 ) -> V_222 |= V_223 ;
F_179 ( V_48 ) -> V_222 |= V_224 ;
} else if ( V_192 ) {
struct V_225 * V_226 = V_192 ;
V_226 -> V_227 ( V_226 , false ) ;
}
F_180 ( V_48 ) ;
F_181 ( V_48 , 0 ) ;
V_11 = F_43 ( V_48 ) ;
#ifndef F_182
F_153 ( V_2 , V_38 , V_48 , V_185 ) ;
#else
F_183 ( V_48 ) ;
#endif
V_134 = F_184 ( V_2 -> V_124 ) ;
F_185 ( & V_134 -> V_144 ) ;
V_134 -> V_145 ++ ;
V_134 -> V_146 += V_116 ;
F_186 ( & V_134 -> V_144 ) ;
F_187 ( V_134 ) ;
F_32 ( V_2 , V_11 , V_38 ) ;
return V_197 ;
}
static T_12 F_188 ( struct V_228 * V_229 , struct V_193 * V_194 )
{
struct V_80 * V_80 = V_229 -> V_230 ;
struct V_1 * V_2 = F_92 ( V_80 ) ;
struct V_37 * V_38 = V_80 -> V_82 ;
T_12 V_231 ;
if ( ! V_2 )
return - V_232 ;
V_231 = F_165 ( V_2 , V_38 , NULL , V_194 ,
V_80 -> V_233 & V_234 , false ) ;
F_93 ( V_2 ) ;
return V_231 ;
}
static T_12 F_189 ( struct V_1 * V_2 ,
struct V_37 * V_38 ,
struct V_47 * V_48 ,
struct V_193 * V_235 )
{
struct V_195 V_196 = { 0 , V_48 -> V_220 } ;
struct V_137 * V_134 ;
T_12 V_236 ;
int V_237 = 0 ;
int V_238 = 0 ;
int V_206 = 0 ;
if ( F_190 ( V_48 ) )
V_238 = V_239 ;
if ( V_2 -> V_3 & V_205 )
V_206 = F_169 ( V_2 -> V_206 ) ;
V_236 = V_48 -> V_116 + V_238 + V_206 ;
if ( ! ( V_2 -> V_3 & V_204 ) ) {
if ( F_167 ( V_235 ) < sizeof( V_196 ) )
return - V_8 ;
V_236 += sizeof( V_196 ) ;
if ( F_167 ( V_235 ) < V_236 ) {
V_196 . V_3 |= V_240 ;
}
if ( F_191 ( & V_196 , sizeof( V_196 ) , V_235 ) != sizeof( V_196 ) )
return - V_7 ;
}
if ( V_206 ) {
struct V_198 V_199 ;
if ( F_167 ( V_235 ) < V_206 )
return - V_8 ;
if ( F_192 ( V_48 , & V_199 ,
F_7 ( V_2 ) , true ) ) {
struct V_241 * V_242 = F_179 ( V_48 ) ;
F_193 ( L_6
L_7 ,
V_242 -> V_243 , F_8 ( V_2 , V_199 . V_244 ) ,
F_8 ( V_2 , V_199 . V_210 ) ) ;
F_194 ( V_245 , L_8 ,
V_246 ,
16 , 1 , V_48 -> V_14 ,
F_195 ( ( int ) F_8 ( V_2 , V_199 . V_210 ) , 64 ) , true ) ;
F_196 ( 1 ) ;
return - V_8 ;
}
if ( F_191 ( & V_199 , sizeof( V_199 ) , V_235 ) != sizeof( V_199 ) )
return - V_7 ;
F_170 ( V_235 , V_206 - sizeof( V_199 ) ) ;
}
if ( V_238 ) {
int V_247 ;
struct {
T_13 V_248 ;
T_13 V_249 ;
} V_250 ;
V_250 . V_248 = V_48 -> V_251 ;
V_250 . V_249 = F_176 ( F_197 ( V_48 ) ) ;
V_237 = F_198 ( struct V_252 , V_248 ) ;
V_247 = F_199 ( V_48 , 0 , V_235 , V_237 ) ;
if ( V_247 || ! F_167 ( V_235 ) )
goto V_253;
V_247 = F_191 ( & V_250 , sizeof( V_250 ) , V_235 ) ;
if ( V_247 != sizeof( V_250 ) || ! F_167 ( V_235 ) )
goto V_253;
}
F_199 ( V_48 , V_237 , V_235 , V_48 -> V_116 - V_237 ) ;
V_253:
V_134 = F_184 ( V_2 -> V_124 ) ;
F_185 ( & V_134 -> V_144 ) ;
V_134 -> V_147 ++ ;
V_134 -> V_148 += V_48 -> V_116 + V_238 ;
F_186 ( & V_134 -> V_144 ) ;
F_187 ( V_2 -> V_124 ) ;
return V_236 ;
}
static struct V_47 * F_200 ( struct V_37 * V_38 , int V_182 ,
int * V_83 )
{
F_201 ( V_170 , V_254 ) ;
struct V_47 * V_48 = NULL ;
int error = 0 ;
V_48 = F_62 ( & V_38 -> V_63 ) ;
if ( V_48 )
goto V_85;
if ( V_182 ) {
error = - V_216 ;
goto V_85;
}
F_202 ( & V_38 -> V_255 . V_170 , & V_170 ) ;
V_254 -> V_256 = V_257 ;
while ( 1 ) {
V_48 = F_62 ( & V_38 -> V_63 ) ;
if ( V_48 )
break;
if ( F_203 ( V_254 ) ) {
error = - V_258 ;
break;
}
if ( V_38 -> V_75 . V_64 -> V_76 & V_77 ) {
error = - V_7 ;
break;
}
F_204 () ;
}
V_254 -> V_256 = V_259 ;
F_205 ( & V_38 -> V_255 . V_170 , & V_170 ) ;
V_85:
* V_83 = error ;
return V_48 ;
}
static T_12 F_206 ( struct V_1 * V_2 , struct V_37 * V_38 ,
struct V_193 * V_260 ,
int V_182 )
{
struct V_47 * V_48 ;
T_12 V_247 ;
int V_83 ;
F_17 ( V_18 , V_2 , L_9 ) ;
if ( ! F_167 ( V_260 ) )
return 0 ;
V_48 = F_200 ( V_38 , V_182 , & V_83 ) ;
if ( ! V_48 )
return V_83 ;
V_247 = F_189 ( V_2 , V_38 , V_48 , V_260 ) ;
if ( F_39 ( V_247 < 0 ) )
F_63 ( V_48 ) ;
else
F_207 ( V_48 ) ;
return V_247 ;
}
static T_12 F_208 ( struct V_228 * V_229 , struct V_193 * V_260 )
{
struct V_80 * V_80 = V_229 -> V_230 ;
struct V_37 * V_38 = V_80 -> V_82 ;
struct V_1 * V_2 = F_89 ( V_38 ) ;
T_12 V_116 = F_167 ( V_260 ) , V_247 ;
if ( ! V_2 )
return - V_232 ;
V_247 = F_206 ( V_2 , V_38 , V_260 , V_80 -> V_233 & V_234 ) ;
V_247 = F_209 ( T_12 , V_247 , V_116 ) ;
if ( V_247 > 0 )
V_229 -> V_261 = V_247 ;
F_93 ( V_2 ) ;
return V_247 ;
}
static void F_210 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
F_67 ( ! ( F_211 ( & V_2 -> V_61 ) ) ) ;
F_212 ( V_2 -> V_124 ) ;
F_137 ( V_2 ) ;
F_213 ( V_2 -> V_84 ) ;
}
static void F_214 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
V_2 -> V_55 = V_262 ;
V_2 -> V_57 = V_263 ;
V_46 -> V_264 = & V_265 ;
V_46 -> V_266 = true ;
V_46 -> V_267 = F_210 ;
V_46 -> V_92 = V_268 ;
}
static int F_215 ( struct V_269 * V_270 [] , struct V_269 * V_30 [] )
{
return - V_8 ;
}
static void F_216 ( struct V_171 * V_64 )
{
struct V_37 * V_38 ;
T_14 * V_271 ;
if ( ! F_146 ( V_64 ) )
return;
if ( ! F_217 ( V_176 , & V_64 -> V_177 -> V_3 ) )
return;
V_271 = F_144 ( V_64 ) ;
if ( V_271 && F_218 ( V_271 ) )
F_219 ( V_271 , V_178 |
V_179 | V_272 ) ;
V_38 = F_220 ( V_64 , struct V_37 , V_64 ) ;
F_122 ( & V_38 -> V_120 , V_121 , V_273 ) ;
}
static int F_221 ( struct V_75 * V_171 , struct V_274 * V_275 , T_11 V_197 )
{
int V_247 ;
struct V_37 * V_38 = F_220 ( V_171 , struct V_37 , V_75 ) ;
struct V_1 * V_2 = F_89 ( V_38 ) ;
if ( ! V_2 )
return - V_232 ;
V_247 = F_165 ( V_2 , V_38 , V_275 -> V_192 , & V_275 -> V_276 ,
V_275 -> V_277 & V_278 ,
V_275 -> V_277 & V_279 ) ;
F_93 ( V_2 ) ;
return V_247 ;
}
static int F_222 ( struct V_75 * V_171 , struct V_274 * V_275 , T_11 V_197 ,
int V_3 )
{
struct V_37 * V_38 = F_220 ( V_171 , struct V_37 , V_75 ) ;
struct V_1 * V_2 = F_89 ( V_38 ) ;
int V_247 ;
if ( ! V_2 )
return - V_232 ;
if ( V_3 & ~ ( V_278 | V_280 | V_281 ) ) {
V_247 = - V_8 ;
goto V_85;
}
if ( V_3 & V_281 ) {
V_247 = F_223 ( V_171 -> V_64 , V_275 , V_197 ,
V_282 , V_283 ) ;
goto V_85;
}
V_247 = F_206 ( V_2 , V_38 , & V_275 -> V_276 , V_3 & V_278 ) ;
if ( V_247 > ( T_12 ) V_197 ) {
V_275 -> V_277 |= V_280 ;
V_247 = V_3 & V_280 ? V_247 : V_197 ;
}
V_85:
F_93 ( V_2 ) ;
return V_247 ;
}
static int F_224 ( struct V_75 * V_171 )
{
struct V_37 * V_38 = F_220 ( V_171 , struct V_37 , V_75 ) ;
struct V_1 * V_2 ;
int V_247 = 0 ;
V_2 = F_89 ( V_38 ) ;
if ( ! V_2 )
return 0 ;
V_247 = F_225 ( & V_38 -> V_63 ) ;
F_93 ( V_2 ) ;
return V_247 ;
}
static int F_226 ( struct V_1 * V_2 )
{
return V_2 -> V_3 & ( V_284 | V_71 | V_151 | V_161 ) ;
}
static T_12 F_227 ( struct V_285 * V_46 , struct V_286 * V_287 ,
char * V_288 )
{
struct V_1 * V_2 = F_41 ( F_228 ( V_46 ) ) ;
return sprintf ( V_288 , L_10 , F_226 ( V_2 ) ) ;
}
static T_12 F_229 ( struct V_285 * V_46 , struct V_286 * V_287 ,
char * V_288 )
{
struct V_1 * V_2 = F_41 ( F_228 ( V_46 ) ) ;
return F_49 ( V_2 -> V_55 ) ?
sprintf ( V_288 , L_11 ,
F_230 ( F_231 () , V_2 -> V_55 ) ) :
sprintf ( V_288 , L_12 ) ;
}
static T_12 F_232 ( struct V_285 * V_46 , struct V_286 * V_287 ,
char * V_288 )
{
struct V_1 * V_2 = F_41 ( F_228 ( V_46 ) ) ;
return F_51 ( V_2 -> V_57 ) ?
sprintf ( V_288 , L_11 ,
F_233 ( F_231 () , V_2 -> V_57 ) ) :
sprintf ( V_288 , L_12 ) ;
}
static int F_234 ( struct V_54 * V_54 , struct V_80 * V_80 , struct V_289 * V_290 )
{
struct V_1 * V_2 ;
struct V_37 * V_38 = V_80 -> V_82 ;
struct V_45 * V_46 ;
int V_83 ;
if ( V_38 -> V_41 )
return - V_8 ;
V_46 = F_235 ( V_54 , V_290 -> V_291 ) ;
if ( V_46 ) {
if ( V_290 -> V_292 & V_293 )
return - V_86 ;
if ( ( V_290 -> V_292 & V_151 ) && V_46 -> V_152 == & V_153 )
V_2 = F_41 ( V_46 ) ;
else if ( ( V_290 -> V_292 & V_161 ) && V_46 -> V_152 == & V_162 )
V_2 = F_41 ( V_46 ) ;
else
return - V_8 ;
if ( ! ! ( V_290 -> V_292 & V_87 ) !=
! ! ( V_2 -> V_3 & V_87 ) )
return - V_8 ;
if ( F_46 ( V_2 ) )
return - V_294 ;
V_83 = F_236 ( V_2 -> V_84 ) ;
if ( V_83 < 0 )
return V_83 ;
V_83 = F_82 ( V_2 , V_80 , V_290 -> V_292 & V_295 ) ;
if ( V_83 < 0 )
return V_83 ;
if ( V_2 -> V_3 & V_87 &&
( V_2 -> V_40 + V_2 -> V_62 > 1 ) ) {
return 0 ;
}
}
else {
char * V_296 ;
unsigned long V_3 = 0 ;
int V_297 = V_290 -> V_292 & V_87 ?
V_89 : 1 ;
if ( ! F_53 ( V_54 -> V_58 , V_59 ) )
return - V_294 ;
V_83 = F_237 () ;
if ( V_83 < 0 )
return V_83 ;
if ( V_290 -> V_292 & V_151 ) {
V_3 |= V_151 ;
V_296 = L_13 ;
} else if ( V_290 -> V_292 & V_161 ) {
V_3 |= V_161 ;
V_296 = L_14 ;
} else
return - V_8 ;
if ( * V_290 -> V_291 )
V_296 = V_290 -> V_291 ;
V_46 = F_238 ( sizeof( struct V_1 ) , V_296 ,
V_298 , F_214 , V_297 ,
V_297 ) ;
if ( ! V_46 )
return - V_94 ;
F_239 ( V_46 , V_54 ) ;
V_46 -> V_299 = & V_300 ;
V_46 -> V_301 = V_38 -> V_301 ;
V_46 -> V_302 [ 0 ] = & V_303 ;
V_2 = F_41 ( V_46 ) ;
V_2 -> V_46 = V_46 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_117 . V_34 = 0 ;
V_2 -> V_206 = sizeof( struct V_198 ) ;
V_2 -> V_132 = V_131 ;
V_2 -> V_90 = false ;
V_2 -> V_304 = V_38 -> V_75 . V_64 -> V_305 ;
V_2 -> V_189 = 0 ;
V_2 -> V_124 = F_240 ( struct V_137 ) ;
if ( ! V_2 -> V_124 ) {
V_83 = - V_94 ;
goto V_306;
}
F_241 ( & V_2 -> V_26 ) ;
V_83 = F_242 ( & V_2 -> V_84 ) ;
if ( V_83 < 0 )
goto V_307;
F_139 ( V_46 ) ;
F_134 ( V_2 ) ;
V_46 -> V_308 = V_309 | V_310 |
V_129 | V_311 |
V_312 ;
V_46 -> V_127 = V_46 -> V_308 | V_313 ;
V_46 -> V_314 = V_46 -> V_127 &
~ ( V_311 |
V_312 ) ;
F_243 ( & V_2 -> V_61 ) ;
V_83 = F_82 ( V_2 , V_80 , false ) ;
if ( V_83 < 0 )
goto V_315;
V_83 = F_244 ( V_2 -> V_46 ) ;
if ( V_83 < 0 )
goto V_316;
}
F_245 ( V_2 -> V_46 ) ;
F_17 ( V_18 , V_2 , L_15 ) ;
V_2 -> V_3 = ( V_2 -> V_3 & ~ V_284 ) |
( V_290 -> V_292 & V_284 ) ;
if ( F_246 ( V_2 -> V_46 ) )
F_247 ( V_2 -> V_46 ) ;
strcpy ( V_290 -> V_291 , V_2 -> V_46 -> V_296 ) ;
return 0 ;
V_316:
F_78 ( V_46 ) ;
V_315:
F_137 ( V_2 ) ;
F_213 ( V_2 -> V_84 ) ;
V_307:
F_212 ( V_2 -> V_124 ) ;
V_306:
F_248 ( V_46 ) ;
return V_83 ;
}
static void F_249 ( struct V_54 * V_54 , struct V_1 * V_2 ,
struct V_289 * V_290 )
{
F_17 ( V_18 , V_2 , L_16 ) ;
strcpy ( V_290 -> V_291 , V_2 -> V_46 -> V_296 ) ;
V_290 -> V_292 = F_226 ( V_2 ) ;
}
static int F_250 ( struct V_1 * V_2 , unsigned long V_100 )
{
T_9 V_127 = 0 ;
if ( V_100 & V_317 ) {
V_127 |= V_318 ;
V_100 &= ~ V_317 ;
if ( V_100 & ( V_319 | V_320 ) ) {
if ( V_100 & V_321 ) {
V_127 |= V_322 ;
V_100 &= ~ V_321 ;
}
if ( V_100 & V_319 )
V_127 |= V_323 ;
if ( V_100 & V_320 )
V_127 |= V_324 ;
V_100 &= ~ ( V_319 | V_320 ) ;
}
if ( V_100 & V_325 ) {
V_127 |= V_326 ;
V_100 &= ~ V_325 ;
}
}
if ( V_100 )
return - V_8 ;
V_2 -> V_128 = V_127 ;
V_2 -> V_46 -> V_327 &= ~ V_129 ;
V_2 -> V_46 -> V_327 |= V_127 ;
F_251 ( V_2 -> V_46 ) ;
return 0 ;
}
static void F_252 ( struct V_1 * V_2 , int V_29 )
{
int V_25 ;
struct V_37 * V_38 ;
for ( V_25 = 0 ; V_25 < V_29 ; V_25 ++ ) {
V_38 = F_66 ( V_2 -> V_70 [ V_25 ] ) ;
F_84 ( V_38 -> V_75 . V_64 ) ;
F_253 ( V_38 -> V_75 . V_64 ) ;
F_86 ( V_38 -> V_75 . V_64 ) ;
}
V_2 -> V_90 = false ;
}
static int F_254 ( struct V_1 * V_2 )
{
int V_25 , V_247 = 0 ;
struct V_37 * V_38 ;
for ( V_25 = 0 ; V_25 < V_2 -> V_40 ; V_25 ++ ) {
V_38 = F_66 ( V_2 -> V_70 [ V_25 ] ) ;
F_84 ( V_38 -> V_75 . V_64 ) ;
V_247 = F_85 ( & V_2 -> V_91 , V_38 -> V_75 . V_64 ) ;
F_86 ( V_38 -> V_75 . V_64 ) ;
if ( V_247 ) {
F_252 ( V_2 , V_25 ) ;
return V_247 ;
}
}
V_2 -> V_90 = true ;
return V_247 ;
}
static void F_255 ( struct V_1 * V_2 )
{
struct V_37 * V_38 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_2 -> V_40 ; V_25 ++ ) {
V_38 = F_66 ( V_2 -> V_70 [ V_25 ] ) ;
V_38 -> V_75 . V_64 -> V_305 = V_2 -> V_304 ;
}
}
static int F_256 ( struct V_80 * V_80 , struct V_289 * V_290 )
{
struct V_37 * V_38 = V_80 -> V_82 ;
struct V_1 * V_2 ;
int V_247 = 0 ;
F_76 () ;
if ( V_290 -> V_292 & V_328 ) {
V_2 = V_38 -> V_41 ;
if ( ! V_2 ) {
V_247 = - V_8 ;
goto V_42;
}
V_247 = F_257 ( V_2 -> V_84 ) ;
if ( V_247 < 0 )
goto V_42;
V_247 = F_82 ( V_2 , V_80 , false ) ;
} else if ( V_290 -> V_292 & V_329 ) {
V_2 = F_66 ( V_38 -> V_2 ) ;
if ( ! V_2 || ! ( V_2 -> V_3 & V_87 ) || V_38 -> V_41 )
V_247 = - V_8 ;
else
F_65 ( V_38 , false ) ;
} else
V_247 = - V_8 ;
V_42:
F_77 () ;
return V_247 ;
}
static long F_258 ( struct V_80 * V_80 , unsigned int V_330 ,
unsigned long V_100 , int V_331 )
{
struct V_37 * V_38 = V_80 -> V_82 ;
struct V_1 * V_2 ;
void T_1 * V_5 = ( void T_1 * ) V_100 ;
struct V_289 V_290 ;
T_15 V_55 ;
T_16 V_57 ;
int V_304 ;
int V_206 ;
unsigned int V_301 ;
int V_332 ;
int V_247 ;
if ( V_330 == V_333 || V_330 == V_334 || F_259 ( V_330 ) == V_335 ) {
if ( F_99 ( & V_290 , V_5 , V_331 ) )
return - V_7 ;
} else {
memset ( & V_290 , 0 , sizeof( V_290 ) ) ;
}
if ( V_330 == V_336 ) {
return F_4 ( V_151 | V_161 | V_284 ,
( unsigned int T_1 * ) V_5 ) ;
} else if ( V_330 == V_334 )
return F_256 ( V_80 , & V_290 ) ;
V_247 = 0 ;
F_76 () ;
V_2 = F_89 ( V_38 ) ;
if ( V_330 == V_333 ) {
V_247 = - V_337 ;
if ( V_2 )
goto V_42;
V_290 . V_291 [ V_338 - 1 ] = '\0' ;
V_247 = F_234 ( F_260 ( & V_38 -> V_64 ) , V_80 , & V_290 ) ;
if ( V_247 )
goto V_42;
if ( F_261 ( V_5 , & V_290 , V_331 ) )
V_247 = - V_7 ;
goto V_42;
}
if ( V_330 == V_339 ) {
V_247 = - V_294 ;
if ( V_2 )
goto V_42;
V_247 = - V_7 ;
if ( F_99 ( & V_301 , V_5 , sizeof( V_301 ) ) )
goto V_42;
V_247 = 0 ;
V_38 -> V_301 = V_301 ;
goto V_42;
}
V_247 = - V_232 ;
if ( ! V_2 )
goto V_42;
F_17 ( V_18 , V_2 , L_17 , V_330 ) ;
V_247 = 0 ;
switch ( V_330 ) {
case V_340 :
F_249 ( V_254 -> V_341 -> V_342 , V_2 , & V_290 ) ;
if ( V_38 -> V_41 )
V_290 . V_292 |= V_329 ;
if ( ! V_38 -> V_75 . V_64 -> V_118 )
V_290 . V_292 |= V_295 ;
if ( F_261 ( V_5 , & V_290 , V_331 ) )
V_247 = - V_7 ;
break;
case V_343 :
F_17 ( V_18 , V_2 , L_18 ,
V_100 ? L_19 : L_20 ) ;
break;
case V_344 :
if ( V_100 && ! ( V_2 -> V_3 & V_71 ) ) {
V_2 -> V_3 |= V_71 ;
F_262 ( V_79 ) ;
}
if ( ! V_100 && ( V_2 -> V_3 & V_71 ) ) {
V_2 -> V_3 &= ~ V_71 ;
F_81 ( V_79 ) ;
}
F_17 ( V_18 , V_2 , L_21 ,
V_100 ? L_20 : L_19 ) ;
break;
case V_345 :
V_55 = F_263 ( F_231 () , V_100 ) ;
if ( ! F_49 ( V_55 ) ) {
V_247 = - V_8 ;
break;
}
V_2 -> V_55 = V_55 ;
F_17 ( V_18 , V_2 , L_22 ,
F_264 ( & V_346 , V_2 -> V_55 ) ) ;
break;
case V_347 :
V_57 = F_265 ( F_231 () , V_100 ) ;
if ( ! F_51 ( V_57 ) ) {
V_247 = - V_8 ;
break;
}
V_2 -> V_57 = V_57 ;
F_17 ( V_18 , V_2 , L_23 ,
F_266 ( & V_346 , V_2 -> V_57 ) ) ;
break;
case V_348 :
if ( V_2 -> V_46 -> V_3 & V_175 ) {
F_17 ( V_18 , V_2 ,
L_24 ) ;
V_247 = - V_86 ;
} else {
V_2 -> V_46 -> type = ( int ) V_100 ;
F_17 ( V_18 , V_2 , L_25 ,
V_2 -> V_46 -> type ) ;
V_247 = 0 ;
}
break;
#ifdef F_267
case V_349 :
V_2 -> V_350 = V_100 ;
break;
#endif
case V_351 :
V_247 = F_250 ( V_2 , V_100 ) ;
break;
case V_352 :
V_247 = - V_8 ;
if ( ( V_2 -> V_3 & V_150 ) != V_161 )
break;
V_247 = F_98 ( & V_2 -> V_117 , ( void T_1 * ) V_100 ) ;
break;
case V_353 :
memcpy ( V_290 . V_354 . V_355 , V_2 -> V_46 -> V_356 , V_97 ) ;
V_290 . V_354 . V_357 = V_2 -> V_46 -> type ;
if ( F_261 ( V_5 , & V_290 , V_331 ) )
V_247 = - V_7 ;
break;
case V_358 :
F_17 ( V_359 , V_2 , L_26 ,
V_290 . V_354 . V_355 ) ;
V_247 = F_268 ( V_2 -> V_46 , & V_290 . V_354 ) ;
break;
case V_360 :
V_304 = V_38 -> V_75 . V_64 -> V_305 ;
if ( F_261 ( V_5 , & V_304 , sizeof( V_304 ) ) )
V_247 = - V_7 ;
break;
case V_361 :
if ( F_99 ( & V_304 , V_5 , sizeof( V_304 ) ) ) {
V_247 = - V_7 ;
break;
}
V_2 -> V_304 = V_304 ;
F_255 ( V_2 ) ;
break;
case V_362 :
V_206 = V_2 -> V_206 ;
if ( F_261 ( V_5 , & V_206 , sizeof( V_206 ) ) )
V_247 = - V_7 ;
break;
case V_363 :
if ( F_99 ( & V_206 , V_5 , sizeof( V_206 ) ) ) {
V_247 = - V_7 ;
break;
}
if ( V_206 < ( int ) sizeof( struct V_198 ) ) {
V_247 = - V_8 ;
break;
}
V_2 -> V_206 = V_206 ;
break;
case V_364 :
V_332 = ! ! ( V_2 -> V_3 & V_9 ) ;
if ( F_4 ( V_332 , ( int T_1 * ) V_5 ) )
V_247 = - V_7 ;
break;
case V_365 :
if ( F_6 ( V_332 , ( int T_1 * ) V_5 ) ) {
V_247 = - V_7 ;
break;
}
if ( V_332 )
V_2 -> V_3 |= V_9 ;
else
V_2 -> V_3 &= ~ V_9 ;
break;
case V_366 :
V_247 = F_3 ( V_2 , V_5 ) ;
break;
case V_367 :
V_247 = F_5 ( V_2 , V_5 ) ;
break;
case V_368 :
V_247 = - V_8 ;
if ( ( V_2 -> V_3 & V_150 ) != V_161 )
break;
V_247 = - V_7 ;
if ( F_99 ( & V_2 -> V_91 , V_5 , sizeof( V_2 -> V_91 ) ) )
break;
V_247 = F_254 ( V_2 ) ;
break;
case V_369 :
V_247 = - V_8 ;
if ( ( V_2 -> V_3 & V_150 ) != V_161 )
break;
V_247 = 0 ;
F_252 ( V_2 , V_2 -> V_40 ) ;
break;
case V_370 :
V_247 = - V_8 ;
if ( ( V_2 -> V_3 & V_150 ) != V_161 )
break;
V_247 = - V_7 ;
if ( F_261 ( V_5 , & V_2 -> V_91 , sizeof( V_2 -> V_91 ) ) )
break;
V_247 = 0 ;
break;
default:
V_247 = - V_8 ;
break;
}
V_42:
F_77 () ;
if ( V_2 )
F_93 ( V_2 ) ;
return V_247 ;
}
static long F_269 ( struct V_80 * V_80 ,
unsigned int V_330 , unsigned long V_100 )
{
return F_258 ( V_80 , V_330 , V_100 , sizeof ( struct V_289 ) ) ;
}
static long F_270 ( struct V_80 * V_80 ,
unsigned int V_330 , unsigned long V_100 )
{
switch ( V_330 ) {
case V_333 :
case V_340 :
case V_352 :
case V_360 :
case V_361 :
case V_353 :
case V_358 :
V_100 = ( unsigned long ) F_271 ( V_100 ) ;
break;
default:
V_100 = ( V_371 ) V_100 ;
break;
}
return F_258 ( V_80 , V_330 , V_100 , sizeof( struct V_372 ) ) ;
}
static int F_272 ( int V_373 , struct V_80 * V_80 , int V_374 )
{
struct V_37 * V_38 = V_80 -> V_82 ;
int V_247 ;
if ( ( V_247 = F_273 ( V_373 , V_80 , V_374 , & V_38 -> V_120 ) ) < 0 )
goto V_85;
if ( V_374 ) {
F_274 ( V_80 , F_275 ( V_254 ) , V_375 , 0 ) ;
V_38 -> V_3 |= V_119 ;
} else
V_38 -> V_3 &= ~ V_119 ;
V_247 = 0 ;
V_85:
return V_247 ;
}
static int F_276 ( struct V_376 * V_376 , struct V_80 * V_80 )
{
struct V_54 * V_54 = V_254 -> V_341 -> V_342 ;
struct V_37 * V_38 ;
F_277 ( V_18 , L_27 ) ;
V_38 = (struct V_37 * ) F_278 ( V_54 , V_377 , V_93 ,
& V_378 , 0 ) ;
if ( ! V_38 )
return - V_94 ;
F_69 ( V_38 -> V_2 , NULL ) ;
V_38 -> V_3 = 0 ;
V_38 -> V_301 = 0 ;
F_279 ( & V_38 -> V_255 . V_170 ) ;
F_69 ( V_38 -> V_75 . V_255 , & V_38 -> V_255 ) ;
V_38 -> V_75 . V_80 = V_80 ;
V_38 -> V_75 . V_379 = & V_380 ;
F_280 ( & V_38 -> V_75 , & V_38 -> V_64 ) ;
V_38 -> V_64 . V_112 = F_216 ;
V_38 -> V_64 . V_305 = V_214 ;
V_80 -> V_82 = V_38 ;
F_243 ( & V_38 -> V_60 ) ;
F_281 ( & V_38 -> V_64 , V_381 ) ;
return 0 ;
}
static int F_282 ( struct V_376 * V_376 , struct V_80 * V_80 )
{
struct V_37 * V_38 = V_80 -> V_82 ;
F_75 ( V_38 , true ) ;
return 0 ;
}
static void F_283 ( struct V_382 * V_275 , struct V_80 * V_383 )
{
struct V_1 * V_2 ;
struct V_289 V_290 ;
memset ( & V_290 , 0 , sizeof( V_290 ) ) ;
F_76 () ;
V_2 = F_92 ( V_383 ) ;
if ( V_2 )
F_249 ( V_254 -> V_341 -> V_342 , V_2 , & V_290 ) ;
F_77 () ;
if ( V_2 )
F_93 ( V_2 ) ;
F_284 ( V_275 , L_28 , V_290 . V_291 ) ;
}
static int F_285 ( struct V_45 * V_46 ,
struct V_384 * V_330 )
{
F_286 ( V_330 , V_385 ) ;
F_286 ( V_330 , V_386 ) ;
V_330 -> V_387 . V_388 = V_389 ;
V_330 -> V_387 . V_390 = V_391 ;
V_330 -> V_387 . V_392 = V_393 ;
V_330 -> V_387 . V_394 = 0 ;
V_330 -> V_387 . V_395 = V_396 ;
return 0 ;
}
static void F_287 ( struct V_45 * V_46 , struct V_397 * V_398 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
F_288 ( V_398 -> V_399 , V_400 , sizeof( V_398 -> V_399 ) ) ;
F_288 ( V_398 -> V_401 , V_402 , sizeof( V_398 -> V_401 ) ) ;
switch ( V_2 -> V_3 & V_150 ) {
case V_151 :
F_288 ( V_398 -> V_403 , L_29 , sizeof( V_398 -> V_403 ) ) ;
break;
case V_161 :
F_288 ( V_398 -> V_403 , L_30 , sizeof( V_398 -> V_403 ) ) ;
break;
}
}
static T_4 F_289 ( struct V_45 * V_46 )
{
#ifdef F_267
struct V_1 * V_2 = F_41 ( V_46 ) ;
return V_2 -> V_350 ;
#else
return - V_404 ;
#endif
}
static void F_290 ( struct V_45 * V_46 , T_4 V_405 )
{
#ifdef F_267
struct V_1 * V_2 = F_41 ( V_46 ) ;
V_2 -> V_350 = V_405 ;
#endif
}
static int F_291 ( struct V_45 * V_46 ,
struct V_406 * V_407 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
V_407 -> V_408 = V_2 -> V_189 ;
return 0 ;
}
static int F_292 ( struct V_45 * V_46 ,
struct V_406 * V_407 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
if ( V_407 -> V_408 > V_409 )
V_2 -> V_189 = V_409 ;
else
V_2 -> V_189 = V_407 -> V_408 ;
return 0 ;
}
static int F_293 ( struct V_1 * V_2 )
{
struct V_45 * V_46 = V_2 -> V_46 ;
struct V_37 * V_38 ;
struct V_410 * * V_411 ;
int V_29 = V_2 -> V_40 + V_2 -> V_62 ;
int V_247 , V_25 ;
V_411 = F_16 ( sizeof *V_411 * V_29 , V_93 ) ;
if ( ! V_411 )
return - V_94 ;
for ( V_25 = 0 ; V_25 < V_2 -> V_40 ; V_25 ++ ) {
V_38 = F_66 ( V_2 -> V_70 [ V_25 ] ) ;
V_411 [ V_25 ] = & V_38 -> V_63 ;
}
F_79 (tfile, &tun->disabled, next)
V_411 [ V_25 ++ ] = & V_38 -> V_63 ;
V_247 = F_294 ( V_411 , V_29 ,
V_46 -> V_92 , V_93 ) ;
F_105 ( V_411 ) ;
return V_247 ;
}
static int F_295 ( struct V_412 * V_413 ,
unsigned long V_414 , void * V_415 )
{
struct V_45 * V_46 = F_296 ( V_415 ) ;
struct V_1 * V_2 = F_41 ( V_46 ) ;
if ( V_46 -> V_299 != & V_300 )
return V_416 ;
switch ( V_414 ) {
case V_417 :
if ( F_293 ( V_2 ) )
return V_418 ;
break;
default:
break;
}
return V_416 ;
}
static int T_17 F_297 ( void )
{
int V_247 = 0 ;
F_298 ( L_31 , V_419 , V_402 ) ;
V_247 = F_299 ( & V_300 ) ;
if ( V_247 ) {
F_193 ( L_32 ) ;
goto V_420;
}
V_247 = F_300 ( & V_421 ) ;
if ( V_247 ) {
F_193 ( L_33 , V_422 ) ;
goto V_423;
}
F_301 ( & V_424 ) ;
return 0 ;
V_423:
F_302 ( & V_300 ) ;
V_420:
return V_247 ;
}
static void F_303 ( void )
{
F_304 ( & V_421 ) ;
F_302 ( & V_300 ) ;
F_305 ( & V_424 ) ;
}
struct V_75 * F_306 ( struct V_80 * V_80 )
{
struct V_37 * V_38 ;
if ( V_80 -> V_425 != & V_426 )
return F_150 ( - V_8 ) ;
V_38 = V_80 -> V_82 ;
if ( ! V_38 )
return F_150 ( - V_232 ) ;
return & V_38 -> V_75 ;
}
