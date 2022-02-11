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
struct V_74 * V_75 = F_66 ( V_2 -> V_75 ) ;
struct V_37 * V_38 , * V_76 ;
int V_25 , V_29 = V_2 -> V_40 ;
for ( V_25 = 0 ; V_25 < V_29 ; V_25 ++ ) {
V_38 = F_66 ( V_2 -> V_70 [ V_25 ] ) ;
F_67 ( ! V_38 ) ;
V_38 -> V_77 . V_64 -> V_78 = V_79 ;
V_38 -> V_77 . V_64 -> V_80 ( V_38 -> V_77 . V_64 ) ;
F_69 ( V_38 -> V_2 , NULL ) ;
-- V_2 -> V_40 ;
}
F_79 (tfile, &tun->disabled, next) {
V_38 -> V_77 . V_64 -> V_78 = V_79 ;
V_38 -> V_77 . V_64 -> V_80 ( V_38 -> V_77 . V_64 ) ;
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
if ( V_75 )
F_81 ( V_75 ) ;
if ( V_2 -> V_3 & V_71 )
F_82 ( V_81 ) ;
}
static int F_83 ( struct V_1 * V_2 , struct V_82 * V_82 , bool V_83 )
{
struct V_37 * V_38 = V_82 -> V_84 ;
struct V_45 * V_46 = V_2 -> V_46 ;
int V_85 ;
V_85 = F_84 ( V_38 -> V_77 . V_64 , V_2 -> V_86 ) ;
if ( V_85 < 0 )
goto V_87;
V_85 = - V_8 ;
if ( F_66 ( V_38 -> V_2 ) && ! V_38 -> V_41 )
goto V_87;
V_85 = - V_88 ;
if ( ! ( V_2 -> V_3 & V_89 ) && V_2 -> V_40 == 1 )
goto V_87;
V_85 = - V_90 ;
if ( ! V_38 -> V_41 &&
V_2 -> V_40 + V_2 -> V_62 == V_91 )
goto V_87;
V_85 = 0 ;
if ( ! V_83 && ( V_2 -> V_92 == true ) ) {
F_85 ( V_38 -> V_77 . V_64 ) ;
V_85 = F_86 ( & V_2 -> V_93 , V_38 -> V_77 . V_64 ) ;
F_87 ( V_38 -> V_77 . V_64 ) ;
if ( ! V_85 )
goto V_87;
}
if ( ! V_38 -> V_41 &&
F_88 ( & V_38 -> V_63 , V_46 -> V_94 , V_95 ) ) {
V_85 = - V_96 ;
goto V_87;
}
V_38 -> V_16 = V_2 -> V_40 ;
V_38 -> V_77 . V_64 -> V_78 &= ~ V_79 ;
F_68 ( V_38 -> V_2 , V_2 ) ;
F_68 ( V_2 -> V_70 [ V_2 -> V_40 ] , V_38 ) ;
V_2 -> V_40 ++ ;
if ( V_38 -> V_41 )
F_59 ( V_38 ) ;
else
F_89 ( & V_38 -> V_64 ) ;
F_54 ( V_2 ) ;
V_87:
return V_85 ;
}
static struct V_1 * F_90 ( struct V_37 * V_38 )
{
struct V_1 * V_2 ;
F_33 () ;
V_2 = F_91 ( V_38 -> V_2 ) ;
if ( V_2 )
F_92 ( V_2 -> V_46 ) ;
F_37 () ;
return V_2 ;
}
static struct V_1 * F_93 ( struct V_82 * V_82 )
{
return F_90 ( V_82 -> V_84 ) ;
}
static void F_94 ( struct V_1 * V_2 )
{
F_95 ( V_2 -> V_46 ) ;
}
static void F_96 ( T_4 * V_97 , const T_6 * V_98 )
{
int V_29 = F_97 ( V_99 , V_98 ) >> 26 ;
V_97 [ V_29 >> 5 ] |= ( 1 << ( V_29 & 31 ) ) ;
}
static unsigned int F_98 ( const T_4 * V_97 , const T_6 * V_98 )
{
int V_29 = F_97 ( V_99 , V_98 ) >> 26 ;
return V_97 [ V_29 >> 5 ] & ( 1 << ( V_29 & 31 ) ) ;
}
static int F_99 ( struct V_100 * V_101 , void T_1 * V_102 )
{
struct { T_6 V_103 [ V_99 ] ; } * V_98 ;
struct V_104 V_105 ;
int V_85 , V_106 , V_29 , V_107 ;
if ( F_100 ( & V_105 , V_102 , sizeof( V_105 ) ) )
return - V_7 ;
if ( ! V_105 . V_34 ) {
V_101 -> V_34 = 0 ;
return 0 ;
}
V_106 = V_99 * V_105 . V_34 ;
V_98 = F_101 ( V_102 + sizeof( V_105 ) , V_106 ) ;
if ( F_102 ( V_98 ) )
return F_103 ( V_98 ) ;
V_101 -> V_34 = 0 ;
F_104 () ;
for ( V_29 = 0 ; V_29 < V_105 . V_34 && V_29 < V_108 ; V_29 ++ )
memcpy ( V_101 -> V_98 [ V_29 ] , V_98 [ V_29 ] . V_103 , V_99 ) ;
V_107 = V_29 ;
memset ( V_101 -> V_97 , 0 , sizeof( V_101 -> V_97 ) ) ;
for (; V_29 < V_105 . V_34 ; V_29 ++ ) {
if ( ! F_105 ( V_98 [ V_29 ] . V_103 ) ) {
V_85 = 0 ;
goto V_109;
}
F_96 ( V_101 -> V_97 , V_98 [ V_29 ] . V_103 ) ;
}
if ( ( V_105 . V_3 & V_110 ) )
memset ( V_101 -> V_97 , ~ 0 , sizeof( V_101 -> V_97 ) ) ;
F_104 () ;
V_101 -> V_34 = V_107 ;
V_85 = V_107 ;
V_109:
F_106 ( V_98 ) ;
return V_85 ;
}
static int F_107 ( struct V_100 * V_101 , const struct V_47 * V_48 )
{
struct V_111 * V_112 = (struct V_111 * ) V_48 -> V_30 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_101 -> V_34 ; V_25 ++ )
if ( F_108 ( V_112 -> V_113 , V_101 -> V_98 [ V_25 ] ) )
return 1 ;
if ( F_105 ( V_112 -> V_113 ) )
return F_98 ( V_101 -> V_97 , V_112 -> V_113 ) ;
return 0 ;
}
static int F_109 ( struct V_100 * V_101 , const struct V_47 * V_48 )
{
if ( ! V_101 -> V_34 )
return 1 ;
return F_107 ( V_101 , V_48 ) ;
}
static void F_110 ( struct V_45 * V_46 )
{
F_78 ( V_46 ) ;
}
static int F_111 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
int V_25 ;
F_112 ( V_46 ) ;
for ( V_25 = 0 ; V_25 < V_2 -> V_40 ; V_25 ++ ) {
struct V_37 * V_38 ;
V_38 = F_66 ( V_2 -> V_70 [ V_25 ] ) ;
V_38 -> V_77 . V_64 -> V_114 ( V_38 -> V_77 . V_64 ) ;
}
return 0 ;
}
static int F_113 ( struct V_45 * V_46 )
{
F_114 ( V_46 ) ;
return 0 ;
}
static T_7 F_115 ( struct V_47 * V_48 , struct V_45 * V_46 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
int V_51 = V_48 -> V_115 ;
struct V_37 * V_38 ;
T_4 V_40 = 0 ;
F_33 () ;
V_38 = F_91 ( V_2 -> V_70 [ V_51 ] ) ;
V_40 = F_42 ( V_2 -> V_40 ) ;
if ( V_51 >= V_40 )
goto V_116;
#ifdef F_116
if ( V_40 == 1 && F_117 ( & V_117 ) ) {
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
F_17 ( V_18 , V_2 , L_4 , V_48 -> V_118 ) ;
F_67 ( ! V_38 ) ;
if ( ! F_109 ( & V_2 -> V_119 , V_48 ) )
goto V_116;
if ( V_38 -> V_77 . V_64 -> V_120 &&
V_120 ( V_38 -> V_77 . V_64 , V_48 ) )
goto V_116;
if ( F_39 ( F_118 ( V_48 , V_17 ) ) )
goto V_116;
F_119 ( V_48 ) ;
F_120 ( V_48 ) ;
F_121 ( V_48 ) ;
if ( F_122 ( & V_38 -> V_63 , V_48 ) )
goto V_116;
if ( V_38 -> V_3 & V_121 )
F_123 ( & V_38 -> V_122 , V_123 , V_124 ) ;
V_38 -> V_77 . V_64 -> V_80 ( V_38 -> V_77 . V_64 ) ;
F_37 () ;
return V_125 ;
V_116:
F_124 ( V_2 -> V_126 -> V_127 ) ;
F_125 ( V_48 ) ;
F_63 ( V_48 ) ;
F_37 () ;
return V_128 ;
}
static void F_126 ( struct V_45 * V_46 )
{
}
static T_9 F_127 ( struct V_45 * V_46 ,
T_9 V_129 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
return ( V_129 & V_2 -> V_130 ) | ( V_129 & ~ V_131 ) ;
}
static void F_128 ( struct V_45 * V_46 )
{
return;
}
static void F_129 ( struct V_45 * V_46 , int V_132 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
if ( V_132 < V_133 )
V_132 = V_133 ;
V_2 -> V_134 = V_132 ;
}
static void
F_130 ( struct V_45 * V_46 , struct V_135 * V_136 )
{
T_4 V_137 = 0 , V_127 = 0 , V_138 = 0 ;
struct V_1 * V_2 = F_41 ( V_46 ) ;
struct V_139 * V_140 ;
int V_25 ;
F_131 (i) {
V_52 V_141 , V_142 , V_143 , V_144 ;
unsigned int V_145 ;
V_140 = F_132 ( V_2 -> V_126 , V_25 ) ;
do {
V_145 = F_133 ( & V_140 -> V_146 ) ;
V_141 = V_140 -> V_147 ;
V_142 = V_140 -> V_148 ;
V_143 = V_140 -> V_149 ;
V_144 = V_140 -> V_150 ;
} while ( F_134 ( & V_140 -> V_146 , V_145 ) );
V_136 -> V_147 += V_141 ;
V_136 -> V_148 += V_142 ;
V_136 -> V_149 += V_143 ;
V_136 -> V_150 += V_144 ;
V_137 += V_140 -> V_137 ;
V_138 += V_140 -> V_138 ;
V_127 += V_140 -> V_127 ;
}
V_136 -> V_137 = V_137 ;
V_136 -> V_138 = V_138 ;
V_136 -> V_127 = V_127 ;
}
static int F_135 ( struct V_45 * V_46 , struct V_74 * V_151 ,
struct V_152 * V_153 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
struct V_74 * V_154 ;
V_154 = F_66 ( V_2 -> V_75 ) ;
F_68 ( V_2 -> V_75 , V_151 ) ;
if ( V_154 )
F_81 ( V_154 ) ;
return 0 ;
}
static T_4 F_136 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
const struct V_74 * V_75 ;
V_75 = F_66 ( V_2 -> V_75 ) ;
if ( V_75 )
return V_75 -> V_155 -> V_156 ;
return 0 ;
}
static int F_137 ( struct V_45 * V_46 , struct V_157 * V_158 )
{
switch ( V_158 -> V_159 ) {
case V_160 :
return F_135 ( V_46 , V_158 -> V_151 , V_158 -> V_153 ) ;
case V_161 :
V_158 -> V_162 = F_136 ( V_46 ) ;
V_158 -> V_163 = ! ! V_158 -> V_162 ;
return 0 ;
default:
return - V_8 ;
}
}
static void F_138 ( struct V_1 * V_2 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_27 ; V_25 ++ )
F_139 ( & V_2 -> V_39 [ V_25 ] ) ;
V_2 -> V_32 = V_164 ;
F_140 ( & V_2 -> V_36 , F_27 , ( unsigned long ) V_2 ) ;
F_30 ( & V_2 -> V_36 ,
F_31 ( V_20 + V_2 -> V_32 ) ) ;
}
static void F_141 ( struct V_1 * V_2 )
{
F_142 ( & V_2 -> V_36 ) ;
F_22 ( V_2 ) ;
}
static void F_143 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
switch ( V_2 -> V_3 & V_165 ) {
case V_166 :
V_46 -> V_167 = & V_168 ;
V_46 -> V_169 = 0 ;
V_46 -> V_170 = 0 ;
V_46 -> V_171 = 1500 ;
V_46 -> type = V_172 ;
V_46 -> V_3 = V_173 | V_174 | V_175 ;
break;
case V_176 :
V_46 -> V_167 = & V_177 ;
F_144 ( V_46 ) ;
V_46 -> V_178 &= ~ V_179 ;
V_46 -> V_178 |= V_180 ;
F_145 ( V_46 ) ;
break;
}
V_46 -> V_181 = V_182 ;
V_46 -> V_183 = V_184 - V_46 -> V_169 ;
}
static unsigned int F_146 ( struct V_82 * V_82 , T_10 * V_185 )
{
struct V_37 * V_38 = V_82 -> V_84 ;
struct V_1 * V_2 = F_90 ( V_38 ) ;
struct V_186 * V_64 ;
unsigned int V_97 = 0 ;
if ( ! V_2 )
return V_187 ;
V_64 = V_38 -> V_77 . V_64 ;
F_17 ( V_18 , V_2 , L_5 ) ;
F_147 ( V_82 , F_148 ( V_64 ) , V_185 ) ;
if ( ! F_149 ( & V_38 -> V_63 ) )
V_97 |= V_188 | V_189 ;
if ( V_2 -> V_46 -> V_3 & V_190 &&
( F_150 ( V_64 ) ||
( ! F_151 ( V_191 , & V_64 -> V_192 -> V_3 ) &&
F_150 ( V_64 ) ) ) )
V_97 |= V_193 | V_194 ;
if ( V_2 -> V_46 -> V_72 != V_73 )
V_97 = V_187 ;
F_94 ( V_2 ) ;
return V_97 ;
}
static struct V_47 * F_152 ( struct V_37 * V_38 ,
T_11 V_195 , T_11 V_118 ,
T_11 V_196 , int V_197 )
{
struct V_186 * V_64 = V_38 -> V_77 . V_64 ;
struct V_47 * V_48 ;
int V_85 ;
if ( V_195 + V_118 < V_198 || ! V_196 )
V_196 = V_118 ;
V_48 = F_153 ( V_64 , V_195 + V_196 , V_118 - V_196 , V_197 ,
& V_85 , 0 ) ;
if ( ! V_48 )
return F_154 ( V_85 ) ;
F_155 ( V_48 , V_195 ) ;
F_156 ( V_48 , V_196 ) ;
V_48 -> V_199 = V_118 - V_196 ;
V_48 -> V_118 += V_118 - V_196 ;
return V_48 ;
}
static void F_157 ( struct V_1 * V_2 , struct V_37 * V_38 ,
struct V_47 * V_48 , int V_200 )
{
struct V_201 * V_202 = & V_38 -> V_64 . V_65 ;
struct V_201 V_203 ;
T_4 V_204 = V_2 -> V_204 ;
bool V_205 = false ;
if ( ! V_204 || ( ! V_200 && F_158 ( V_202 ) ) ) {
F_159 () ;
F_160 ( V_48 ) ;
F_161 () ;
return;
}
F_162 ( & V_202 -> V_26 ) ;
if ( ! V_200 || F_163 ( V_202 ) == V_204 ) {
F_164 ( & V_203 ) ;
F_165 ( V_202 , & V_203 ) ;
V_205 = true ;
} else {
F_166 ( V_202 , V_48 ) ;
}
F_167 ( & V_202 -> V_26 ) ;
if ( V_205 ) {
struct V_47 * V_206 ;
F_159 () ;
while ( ( V_206 = F_168 ( & V_203 ) ) )
F_160 ( V_206 ) ;
F_160 ( V_48 ) ;
F_161 () ;
}
}
static bool F_169 ( struct V_1 * V_2 , struct V_37 * V_38 ,
int V_118 , int V_197 , bool V_207 )
{
if ( ( V_2 -> V_3 & V_165 ) != V_176 )
return false ;
if ( V_38 -> V_77 . V_64 -> V_208 != V_209 )
return false ;
if ( ! V_197 )
return false ;
if ( V_207 )
return false ;
if ( F_170 ( V_118 + V_210 ) +
F_170 ( sizeof( struct V_211 ) ) > V_198 )
return false ;
return true ;
}
static struct V_47 * F_171 ( struct V_1 * V_2 ,
struct V_37 * V_38 ,
struct V_212 * V_213 ,
struct V_214 * V_215 ,
int V_118 , int * V_216 )
{
struct V_217 * V_218 = & V_219 -> V_220 ;
struct V_47 * V_48 ;
struct V_74 * V_75 ;
int V_221 = F_170 ( sizeof( struct V_211 ) ) ;
unsigned int V_222 = 0 ;
char * V_223 ;
T_11 V_224 ;
bool V_225 = false ;
int V_85 , V_226 = V_210 ;
F_33 () ;
V_75 = F_91 ( V_2 -> V_75 ) ;
if ( V_75 )
V_226 += V_227 ;
V_221 += F_170 ( V_118 + V_226 ) ;
F_37 () ;
V_218 -> V_228 = F_172 ( ( V_52 ) V_218 -> V_228 , V_229 ) ;
if ( F_39 ( ! F_173 ( V_221 , V_218 , V_95 ) ) )
return F_154 ( - V_96 ) ;
V_223 = ( char * ) F_174 ( V_218 -> V_230 ) + V_218 -> V_228 ;
V_224 = F_175 ( V_218 -> V_230 ,
V_218 -> V_228 + V_226 ,
V_118 , V_213 ) ;
if ( V_224 != V_118 )
return F_154 ( - V_7 ) ;
if ( V_215 -> V_231 || ! V_75 )
* V_216 = 1 ;
else
* V_216 = 0 ;
F_33 () ;
V_75 = F_91 ( V_2 -> V_75 ) ;
if ( V_75 && ! * V_216 ) {
struct V_232 V_158 ;
void * V_233 ;
T_4 V_234 ;
V_158 . V_235 = V_223 ;
V_158 . V_30 = V_223 + V_226 ;
V_158 . V_236 = V_158 . V_30 + V_118 ;
V_233 = V_158 . V_30 ;
V_234 = F_176 ( V_75 , & V_158 ) ;
switch ( V_234 ) {
case V_237 :
F_177 ( V_218 -> V_230 ) ;
V_218 -> V_228 += V_221 ;
V_85 = F_178 ( V_2 -> V_46 , & V_158 , V_75 ) ;
if ( V_85 )
goto V_238;
return NULL ;
case V_239 :
V_225 = true ;
case V_240 :
V_222 = V_233 - V_158 . V_30 ;
break;
default:
F_179 ( V_234 ) ;
case V_241 :
F_180 ( V_2 -> V_46 , V_75 , V_234 ) ;
case V_242 :
goto V_243;
}
}
V_48 = F_181 ( V_223 , V_221 ) ;
if ( ! V_48 ) {
F_37 () ;
return F_154 ( - V_96 ) ;
}
F_155 ( V_48 , V_226 - V_222 ) ;
F_156 ( V_48 , V_118 + V_222 ) ;
F_177 ( V_218 -> V_230 ) ;
V_218 -> V_228 += V_221 ;
if ( V_225 ) {
V_48 -> V_46 = V_2 -> V_46 ;
F_182 ( V_48 , V_75 ) ;
F_33 () ;
return NULL ;
}
F_37 () ;
return V_48 ;
V_238:
F_183 ( V_218 -> V_230 ) ;
V_243:
F_37 () ;
F_124 ( V_2 -> V_126 -> V_137 ) ;
return NULL ;
}
static T_12 F_184 ( struct V_1 * V_2 , struct V_37 * V_38 ,
void * V_244 , struct V_212 * V_213 ,
int V_197 , bool V_200 )
{
struct V_245 V_246 = { 0 , F_185 (ETH_P_IP) } ;
struct V_47 * V_48 ;
T_11 V_247 = F_186 ( V_213 ) ;
T_11 V_118 = V_247 , V_134 = V_2 -> V_134 , V_196 ;
struct V_214 V_248 = { 0 } ;
struct V_139 * V_136 ;
int V_249 ;
int V_250 ;
bool V_207 = false ;
int V_85 ;
T_4 V_11 ;
int V_216 = 1 ;
if ( ! ( V_2 -> V_46 -> V_3 & V_190 ) )
return - V_251 ;
if ( ! ( V_2 -> V_3 & V_252 ) ) {
if ( V_118 < sizeof( V_246 ) )
return - V_8 ;
V_118 -= sizeof( V_246 ) ;
if ( ! F_187 ( & V_246 , sizeof( V_246 ) , V_213 ) )
return - V_7 ;
}
if ( V_2 -> V_3 & V_253 ) {
int V_254 = F_188 ( V_2 -> V_254 ) ;
if ( V_118 < V_254 )
return - V_8 ;
V_118 -= V_254 ;
if ( ! F_187 ( & V_248 , sizeof( V_248 ) , V_213 ) )
return - V_7 ;
if ( ( V_248 . V_3 & V_255 ) &&
F_8 ( V_2 , V_248 . V_256 ) + F_8 ( V_2 , V_248 . V_257 ) + 2 > F_8 ( V_2 , V_248 . V_258 ) )
V_248 . V_258 = F_10 ( V_2 , F_8 ( V_2 , V_248 . V_256 ) + F_8 ( V_2 , V_248 . V_257 ) + 2 ) ;
if ( F_8 ( V_2 , V_248 . V_258 ) > V_118 )
return - V_8 ;
F_189 ( V_213 , V_254 - sizeof( V_248 ) ) ;
}
if ( ( V_2 -> V_3 & V_165 ) == V_176 ) {
V_134 += V_259 ;
if ( F_39 ( V_118 < V_260 ||
( V_248 . V_258 && F_8 ( V_2 , V_248 . V_258 ) < V_260 ) ) )
return - V_8 ;
}
V_249 = F_190 ( V_134 ) ;
if ( V_244 ) {
struct V_212 V_25 = * V_213 ;
V_250 = V_248 . V_258 ? F_8 ( V_2 , V_248 . V_258 ) : V_261 ;
if ( V_250 > V_249 )
V_250 = V_249 ;
V_196 = V_250 ;
F_189 ( & V_25 , V_250 ) ;
if ( F_191 ( & V_25 , V_209 ) <= V_262 )
V_207 = true ;
}
if ( F_169 ( V_2 , V_38 , V_118 , V_197 , V_207 ) ) {
V_48 = F_171 ( V_2 , V_38 , V_213 , & V_248 , V_118 , & V_216 ) ;
if ( F_102 ( V_48 ) ) {
F_124 ( V_2 -> V_126 -> V_137 ) ;
return F_103 ( V_48 ) ;
}
if ( ! V_48 )
return V_247 ;
} else {
if ( ! V_207 ) {
V_250 = V_118 ;
if ( F_8 ( V_2 , V_248 . V_258 ) > V_249 )
V_196 = V_249 ;
else
V_196 = F_8 ( V_2 , V_248 . V_258 ) ;
}
V_48 = F_152 ( V_38 , V_134 , V_250 , V_196 , V_197 ) ;
if ( F_102 ( V_48 ) ) {
if ( F_103 ( V_48 ) != - V_263 )
F_124 ( V_2 -> V_126 -> V_137 ) ;
return F_103 ( V_48 ) ;
}
if ( V_207 )
V_85 = F_192 ( V_48 , V_213 ) ;
else
V_85 = F_193 ( V_48 , 0 , V_213 , V_118 ) ;
if ( V_85 ) {
F_124 ( V_2 -> V_126 -> V_137 ) ;
F_63 ( V_48 ) ;
return - V_7 ;
}
}
if ( F_194 ( V_48 , & V_248 , F_7 ( V_2 ) ) ) {
F_124 ( V_2 -> V_126 -> V_138 ) ;
F_63 ( V_48 ) ;
return - V_8 ;
}
switch ( V_2 -> V_3 & V_165 ) {
case V_166 :
if ( V_2 -> V_3 & V_252 ) {
T_6 V_264 = V_48 -> V_118 ? ( V_48 -> V_30 [ 0 ] >> 4 ) : 0 ;
switch ( V_264 ) {
case 4 :
V_246 . V_265 = F_195 ( V_266 ) ;
break;
case 6 :
V_246 . V_265 = F_195 ( V_267 ) ;
break;
default:
F_124 ( V_2 -> V_126 -> V_137 ) ;
F_63 ( V_48 ) ;
return - V_8 ;
}
}
F_196 ( V_48 ) ;
V_48 -> V_268 = V_246 . V_265 ;
V_48 -> V_46 = V_2 -> V_46 ;
break;
case V_176 :
V_48 -> V_268 = F_197 ( V_48 , V_2 -> V_46 ) ;
break;
}
if ( V_207 ) {
F_198 ( V_48 ) -> V_269 = V_244 ;
F_198 ( V_48 ) -> V_270 |= V_271 ;
F_198 ( V_48 ) -> V_270 |= V_272 ;
} else if ( V_244 ) {
struct V_273 * V_274 = V_244 ;
V_274 -> V_275 ( V_274 , false ) ;
}
F_199 ( V_48 ) ;
F_200 ( V_48 , 0 ) ;
if ( V_216 ) {
struct V_74 * V_75 ;
int V_276 ;
F_33 () ;
V_75 = F_91 ( V_2 -> V_75 ) ;
if ( V_75 ) {
V_276 = F_201 ( V_75 , V_48 ) ;
if ( V_276 != V_240 ) {
F_37 () ;
return V_247 ;
}
}
F_37 () ;
}
V_11 = F_43 ( V_48 ) ;
#ifndef F_202
F_157 ( V_2 , V_38 , V_48 , V_200 ) ;
#else
F_203 ( V_48 ) ;
#endif
V_136 = F_204 ( V_2 -> V_126 ) ;
F_205 ( & V_136 -> V_146 ) ;
V_136 -> V_147 ++ ;
V_136 -> V_148 += V_118 ;
F_206 ( & V_136 -> V_146 ) ;
F_207 ( V_136 ) ;
F_32 ( V_2 , V_11 , V_38 ) ;
return V_247 ;
}
static T_12 F_208 ( struct V_277 * V_278 , struct V_212 * V_213 )
{
struct V_82 * V_82 = V_278 -> V_279 ;
struct V_1 * V_2 = F_93 ( V_82 ) ;
struct V_37 * V_38 = V_82 -> V_84 ;
T_12 V_280 ;
if ( ! V_2 )
return - V_281 ;
V_280 = F_184 ( V_2 , V_38 , NULL , V_213 ,
V_82 -> V_282 & V_283 , false ) ;
F_94 ( V_2 ) ;
return V_280 ;
}
static T_12 F_209 ( struct V_1 * V_2 ,
struct V_37 * V_38 ,
struct V_47 * V_48 ,
struct V_212 * V_284 )
{
struct V_245 V_246 = { 0 , V_48 -> V_268 } ;
struct V_139 * V_136 ;
T_12 V_285 ;
int V_286 = 0 ;
int V_287 = 0 ;
int V_254 = 0 ;
if ( F_210 ( V_48 ) )
V_287 = V_288 ;
if ( V_2 -> V_3 & V_253 )
V_254 = F_188 ( V_2 -> V_254 ) ;
V_285 = V_48 -> V_118 + V_287 + V_254 ;
if ( ! ( V_2 -> V_3 & V_252 ) ) {
if ( F_186 ( V_284 ) < sizeof( V_246 ) )
return - V_8 ;
V_285 += sizeof( V_246 ) ;
if ( F_186 ( V_284 ) < V_285 ) {
V_246 . V_3 |= V_289 ;
}
if ( F_211 ( & V_246 , sizeof( V_246 ) , V_284 ) != sizeof( V_246 ) )
return - V_7 ;
}
if ( V_254 ) {
struct V_214 V_248 ;
if ( F_186 ( V_284 ) < V_254 )
return - V_8 ;
if ( F_212 ( V_48 , & V_248 ,
F_7 ( V_2 ) , true ) ) {
struct V_211 * V_290 = F_198 ( V_48 ) ;
F_213 ( L_6
L_7 ,
V_290 -> V_231 , F_8 ( V_2 , V_248 . V_291 ) ,
F_8 ( V_2 , V_248 . V_258 ) ) ;
F_214 ( V_292 , L_8 ,
V_293 ,
16 , 1 , V_48 -> V_14 ,
F_215 ( ( int ) F_8 ( V_2 , V_248 . V_258 ) , 64 ) , true ) ;
F_216 ( 1 ) ;
return - V_8 ;
}
if ( F_211 ( & V_248 , sizeof( V_248 ) , V_284 ) != sizeof( V_248 ) )
return - V_7 ;
F_189 ( V_284 , V_254 - sizeof( V_248 ) ) ;
}
if ( V_287 ) {
int V_276 ;
struct {
T_13 V_294 ;
T_13 V_295 ;
} V_296 ;
V_296 . V_294 = V_48 -> V_297 ;
V_296 . V_295 = F_195 ( F_217 ( V_48 ) ) ;
V_286 = F_218 ( struct V_298 , V_294 ) ;
V_276 = F_219 ( V_48 , 0 , V_284 , V_286 ) ;
if ( V_276 || ! F_186 ( V_284 ) )
goto V_299;
V_276 = F_211 ( & V_296 , sizeof( V_296 ) , V_284 ) ;
if ( V_276 != sizeof( V_296 ) || ! F_186 ( V_284 ) )
goto V_299;
}
F_219 ( V_48 , V_286 , V_284 , V_48 -> V_118 - V_286 ) ;
V_299:
V_136 = F_204 ( V_2 -> V_126 ) ;
F_205 ( & V_136 -> V_146 ) ;
V_136 -> V_149 ++ ;
V_136 -> V_150 += V_48 -> V_118 + V_287 ;
F_206 ( & V_136 -> V_146 ) ;
F_207 ( V_2 -> V_126 ) ;
return V_285 ;
}
static struct V_47 * F_220 ( struct V_37 * V_38 , int V_197 ,
int * V_85 )
{
F_221 ( V_185 , V_219 ) ;
struct V_47 * V_48 = NULL ;
int error = 0 ;
V_48 = F_62 ( & V_38 -> V_63 ) ;
if ( V_48 )
goto V_87;
if ( V_197 ) {
error = - V_263 ;
goto V_87;
}
F_222 ( & V_38 -> V_300 . V_185 , & V_185 ) ;
V_219 -> V_301 = V_302 ;
while ( 1 ) {
V_48 = F_62 ( & V_38 -> V_63 ) ;
if ( V_48 )
break;
if ( F_223 ( V_219 ) ) {
error = - V_303 ;
break;
}
if ( V_38 -> V_77 . V_64 -> V_78 & V_79 ) {
error = - V_7 ;
break;
}
F_224 () ;
}
V_219 -> V_301 = V_304 ;
F_225 ( & V_38 -> V_300 . V_185 , & V_185 ) ;
V_87:
* V_85 = error ;
return V_48 ;
}
static T_12 F_226 ( struct V_1 * V_2 , struct V_37 * V_38 ,
struct V_212 * V_305 ,
int V_197 , struct V_47 * V_48 )
{
T_12 V_276 ;
int V_85 ;
F_17 ( V_18 , V_2 , L_9 ) ;
if ( ! F_186 ( V_305 ) )
return 0 ;
if ( ! V_48 ) {
V_48 = F_220 ( V_38 , V_197 , & V_85 ) ;
if ( ! V_48 )
return V_85 ;
}
V_276 = F_209 ( V_2 , V_38 , V_48 , V_305 ) ;
if ( F_39 ( V_276 < 0 ) )
F_63 ( V_48 ) ;
else
F_227 ( V_48 ) ;
return V_276 ;
}
static T_12 F_228 ( struct V_277 * V_278 , struct V_212 * V_305 )
{
struct V_82 * V_82 = V_278 -> V_279 ;
struct V_37 * V_38 = V_82 -> V_84 ;
struct V_1 * V_2 = F_90 ( V_38 ) ;
T_12 V_118 = F_186 ( V_305 ) , V_276 ;
if ( ! V_2 )
return - V_281 ;
V_276 = F_226 ( V_2 , V_38 , V_305 , V_82 -> V_282 & V_283 , NULL ) ;
V_276 = F_229 ( T_12 , V_276 , V_118 ) ;
if ( V_276 > 0 )
V_278 -> V_306 = V_276 ;
F_94 ( V_2 ) ;
return V_276 ;
}
static void F_230 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
F_67 ( ! ( F_231 ( & V_2 -> V_61 ) ) ) ;
F_232 ( V_2 -> V_126 ) ;
F_141 ( V_2 ) ;
F_233 ( V_2 -> V_86 ) ;
}
static void F_234 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
V_2 -> V_55 = V_307 ;
V_2 -> V_57 = V_308 ;
V_46 -> V_309 = & V_310 ;
V_46 -> V_311 = true ;
V_46 -> V_312 = F_230 ;
V_46 -> V_94 = V_313 ;
}
static int F_235 ( struct V_314 * V_315 [] , struct V_314 * V_30 [] ,
struct V_152 * V_153 )
{
return - V_8 ;
}
static void F_236 ( struct V_186 * V_64 )
{
struct V_37 * V_38 ;
T_14 * V_316 ;
if ( ! F_150 ( V_64 ) )
return;
if ( ! F_237 ( V_191 , & V_64 -> V_192 -> V_3 ) )
return;
V_316 = F_148 ( V_64 ) ;
if ( V_316 && F_238 ( V_316 ) )
F_239 ( V_316 , V_193 |
V_194 | V_317 ) ;
V_38 = F_240 ( V_64 , struct V_37 , V_64 ) ;
F_123 ( & V_38 -> V_122 , V_123 , V_318 ) ;
}
static int F_241 ( struct V_77 * V_186 , struct V_319 * V_320 , T_11 V_247 )
{
int V_276 ;
struct V_37 * V_38 = F_240 ( V_186 , struct V_37 , V_77 ) ;
struct V_1 * V_2 = F_90 ( V_38 ) ;
if ( ! V_2 )
return - V_281 ;
V_276 = F_184 ( V_2 , V_38 , V_320 -> V_244 , & V_320 -> V_321 ,
V_320 -> V_322 & V_323 ,
V_320 -> V_322 & V_324 ) ;
F_94 ( V_2 ) ;
return V_276 ;
}
static int F_242 ( struct V_77 * V_186 , struct V_319 * V_320 , T_11 V_247 ,
int V_3 )
{
struct V_37 * V_38 = F_240 ( V_186 , struct V_37 , V_77 ) ;
struct V_1 * V_2 = F_90 ( V_38 ) ;
int V_276 ;
if ( ! V_2 )
return - V_281 ;
if ( V_3 & ~ ( V_323 | V_325 | V_326 ) ) {
V_276 = - V_8 ;
goto V_87;
}
if ( V_3 & V_326 ) {
V_276 = F_243 ( V_186 -> V_64 , V_320 , V_247 ,
V_327 , V_328 ) ;
goto V_87;
}
V_276 = F_226 ( V_2 , V_38 , & V_320 -> V_321 , V_3 & V_323 ,
V_320 -> V_244 ) ;
if ( V_276 > ( T_12 ) V_247 ) {
V_320 -> V_322 |= V_325 ;
V_276 = V_3 & V_325 ? V_276 : V_247 ;
}
V_87:
F_94 ( V_2 ) ;
return V_276 ;
}
static int F_244 ( struct V_77 * V_186 )
{
struct V_37 * V_38 = F_240 ( V_186 , struct V_37 , V_77 ) ;
struct V_1 * V_2 ;
int V_276 = 0 ;
V_2 = F_90 ( V_38 ) ;
if ( ! V_2 )
return 0 ;
V_276 = F_245 ( & V_38 -> V_63 ) ;
F_94 ( V_2 ) ;
return V_276 ;
}
static int F_246 ( struct V_1 * V_2 )
{
return V_2 -> V_3 & ( V_329 | V_71 | V_166 | V_176 ) ;
}
static T_12 F_247 ( struct V_330 * V_46 , struct V_331 * V_332 ,
char * V_223 )
{
struct V_1 * V_2 = F_41 ( F_248 ( V_46 ) ) ;
return sprintf ( V_223 , L_10 , F_246 ( V_2 ) ) ;
}
static T_12 F_249 ( struct V_330 * V_46 , struct V_331 * V_332 ,
char * V_223 )
{
struct V_1 * V_2 = F_41 ( F_248 ( V_46 ) ) ;
return F_49 ( V_2 -> V_55 ) ?
sprintf ( V_223 , L_11 ,
F_250 ( F_251 () , V_2 -> V_55 ) ) :
sprintf ( V_223 , L_12 ) ;
}
static T_12 F_252 ( struct V_330 * V_46 , struct V_331 * V_332 ,
char * V_223 )
{
struct V_1 * V_2 = F_41 ( F_248 ( V_46 ) ) ;
return F_51 ( V_2 -> V_57 ) ?
sprintf ( V_223 , L_11 ,
F_253 ( F_251 () , V_2 -> V_57 ) ) :
sprintf ( V_223 , L_12 ) ;
}
static int F_254 ( struct V_54 * V_54 , struct V_82 * V_82 , struct V_333 * V_334 )
{
struct V_1 * V_2 ;
struct V_37 * V_38 = V_82 -> V_84 ;
struct V_45 * V_46 ;
int V_85 ;
if ( V_38 -> V_41 )
return - V_8 ;
V_46 = F_255 ( V_54 , V_334 -> V_335 ) ;
if ( V_46 ) {
if ( V_334 -> V_336 & V_337 )
return - V_88 ;
if ( ( V_334 -> V_336 & V_166 ) && V_46 -> V_167 == & V_168 )
V_2 = F_41 ( V_46 ) ;
else if ( ( V_334 -> V_336 & V_176 ) && V_46 -> V_167 == & V_177 )
V_2 = F_41 ( V_46 ) ;
else
return - V_8 ;
if ( ! ! ( V_334 -> V_336 & V_89 ) !=
! ! ( V_2 -> V_3 & V_89 ) )
return - V_8 ;
if ( F_46 ( V_2 ) )
return - V_338 ;
V_85 = F_256 ( V_2 -> V_86 ) ;
if ( V_85 < 0 )
return V_85 ;
V_85 = F_83 ( V_2 , V_82 , V_334 -> V_336 & V_339 ) ;
if ( V_85 < 0 )
return V_85 ;
if ( V_2 -> V_3 & V_89 &&
( V_2 -> V_40 + V_2 -> V_62 > 1 ) ) {
return 0 ;
}
}
else {
char * V_340 ;
unsigned long V_3 = 0 ;
int V_341 = V_334 -> V_336 & V_89 ?
V_91 : 1 ;
if ( ! F_53 ( V_54 -> V_58 , V_59 ) )
return - V_338 ;
V_85 = F_257 () ;
if ( V_85 < 0 )
return V_85 ;
if ( V_334 -> V_336 & V_166 ) {
V_3 |= V_166 ;
V_340 = L_13 ;
} else if ( V_334 -> V_336 & V_176 ) {
V_3 |= V_176 ;
V_340 = L_14 ;
} else
return - V_8 ;
if ( * V_334 -> V_335 )
V_340 = V_334 -> V_335 ;
V_46 = F_258 ( sizeof( struct V_1 ) , V_340 ,
V_342 , F_234 , V_341 ,
V_341 ) ;
if ( ! V_46 )
return - V_96 ;
V_85 = F_259 ( V_54 , V_46 , V_340 ) ;
if ( V_85 < 0 )
goto V_343;
F_260 ( V_46 , V_54 ) ;
V_46 -> V_344 = & V_345 ;
V_46 -> V_346 = V_38 -> V_346 ;
V_46 -> V_347 [ 0 ] = & V_348 ;
V_2 = F_41 ( V_46 ) ;
V_2 -> V_46 = V_46 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_119 . V_34 = 0 ;
V_2 -> V_254 = sizeof( struct V_214 ) ;
V_2 -> V_134 = V_133 ;
V_2 -> V_92 = false ;
V_2 -> V_349 = V_38 -> V_77 . V_64 -> V_208 ;
V_2 -> V_204 = 0 ;
V_2 -> V_126 = F_261 ( struct V_139 ) ;
if ( ! V_2 -> V_126 ) {
V_85 = - V_96 ;
goto V_343;
}
F_262 ( & V_2 -> V_26 ) ;
V_85 = F_263 ( & V_2 -> V_86 ) ;
if ( V_85 < 0 )
goto V_350;
F_143 ( V_46 ) ;
F_138 ( V_2 ) ;
V_46 -> V_351 = V_352 | V_353 |
V_131 | V_354 |
V_355 ;
V_46 -> V_129 = V_46 -> V_351 | V_356 ;
V_46 -> V_357 = V_46 -> V_129 &
~ ( V_354 |
V_355 ) ;
F_264 ( & V_2 -> V_61 ) ;
V_85 = F_83 ( V_2 , V_82 , false ) ;
if ( V_85 < 0 )
goto V_358;
V_85 = F_265 ( V_2 -> V_46 ) ;
if ( V_85 < 0 )
goto V_359;
}
F_266 ( V_2 -> V_46 ) ;
F_17 ( V_18 , V_2 , L_15 ) ;
V_2 -> V_3 = ( V_2 -> V_3 & ~ V_329 ) |
( V_334 -> V_336 & V_329 ) ;
if ( F_267 ( V_2 -> V_46 ) )
F_268 ( V_2 -> V_46 ) ;
strcpy ( V_334 -> V_335 , V_2 -> V_46 -> V_340 ) ;
return 0 ;
V_359:
F_78 ( V_46 ) ;
goto V_343;
V_358:
F_141 ( V_2 ) ;
F_233 ( V_2 -> V_86 ) ;
V_350:
F_232 ( V_2 -> V_126 ) ;
V_343:
F_269 ( V_46 ) ;
return V_85 ;
}
static void F_270 ( struct V_54 * V_54 , struct V_1 * V_2 ,
struct V_333 * V_334 )
{
F_17 ( V_18 , V_2 , L_16 ) ;
strcpy ( V_334 -> V_335 , V_2 -> V_46 -> V_340 ) ;
V_334 -> V_336 = F_246 ( V_2 ) ;
}
static int F_271 ( struct V_1 * V_2 , unsigned long V_102 )
{
T_9 V_129 = 0 ;
if ( V_102 & V_360 ) {
V_129 |= V_361 ;
V_102 &= ~ V_360 ;
if ( V_102 & ( V_362 | V_363 ) ) {
if ( V_102 & V_364 ) {
V_129 |= V_365 ;
V_102 &= ~ V_364 ;
}
if ( V_102 & V_362 )
V_129 |= V_366 ;
if ( V_102 & V_363 )
V_129 |= V_367 ;
V_102 &= ~ ( V_362 | V_363 ) ;
}
}
if ( V_102 )
return - V_8 ;
V_2 -> V_130 = V_129 ;
V_2 -> V_46 -> V_368 &= ~ V_131 ;
V_2 -> V_46 -> V_368 |= V_129 ;
F_272 ( V_2 -> V_46 ) ;
return 0 ;
}
static void F_273 ( struct V_1 * V_2 , int V_29 )
{
int V_25 ;
struct V_37 * V_38 ;
for ( V_25 = 0 ; V_25 < V_29 ; V_25 ++ ) {
V_38 = F_66 ( V_2 -> V_70 [ V_25 ] ) ;
F_85 ( V_38 -> V_77 . V_64 ) ;
F_274 ( V_38 -> V_77 . V_64 ) ;
F_87 ( V_38 -> V_77 . V_64 ) ;
}
V_2 -> V_92 = false ;
}
static int F_275 ( struct V_1 * V_2 )
{
int V_25 , V_276 = 0 ;
struct V_37 * V_38 ;
for ( V_25 = 0 ; V_25 < V_2 -> V_40 ; V_25 ++ ) {
V_38 = F_66 ( V_2 -> V_70 [ V_25 ] ) ;
F_85 ( V_38 -> V_77 . V_64 ) ;
V_276 = F_86 ( & V_2 -> V_93 , V_38 -> V_77 . V_64 ) ;
F_87 ( V_38 -> V_77 . V_64 ) ;
if ( V_276 ) {
F_273 ( V_2 , V_25 ) ;
return V_276 ;
}
}
V_2 -> V_92 = true ;
return V_276 ;
}
static void F_276 ( struct V_1 * V_2 )
{
struct V_37 * V_38 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_2 -> V_40 ; V_25 ++ ) {
V_38 = F_66 ( V_2 -> V_70 [ V_25 ] ) ;
V_38 -> V_77 . V_64 -> V_208 = V_2 -> V_349 ;
}
}
static int F_277 ( struct V_82 * V_82 , struct V_333 * V_334 )
{
struct V_37 * V_38 = V_82 -> V_84 ;
struct V_1 * V_2 ;
int V_276 = 0 ;
F_76 () ;
if ( V_334 -> V_336 & V_369 ) {
V_2 = V_38 -> V_41 ;
if ( ! V_2 ) {
V_276 = - V_8 ;
goto V_42;
}
V_276 = F_278 ( V_2 -> V_86 ) ;
if ( V_276 < 0 )
goto V_42;
V_276 = F_83 ( V_2 , V_82 , false ) ;
} else if ( V_334 -> V_336 & V_370 ) {
V_2 = F_66 ( V_38 -> V_2 ) ;
if ( ! V_2 || ! ( V_2 -> V_3 & V_89 ) || V_38 -> V_41 )
V_276 = - V_8 ;
else
F_65 ( V_38 , false ) ;
} else
V_276 = - V_8 ;
V_42:
F_77 () ;
return V_276 ;
}
static long F_279 ( struct V_82 * V_82 , unsigned int V_371 ,
unsigned long V_102 , int V_372 )
{
struct V_37 * V_38 = V_82 -> V_84 ;
struct V_1 * V_2 ;
void T_1 * V_5 = ( void T_1 * ) V_102 ;
struct V_333 V_334 ;
T_15 V_55 ;
T_16 V_57 ;
int V_349 ;
int V_254 ;
unsigned int V_346 ;
int V_373 ;
int V_276 ;
if ( V_371 == V_374 || V_371 == V_375 || F_280 ( V_371 ) == V_376 ) {
if ( F_100 ( & V_334 , V_5 , V_372 ) )
return - V_7 ;
} else {
memset ( & V_334 , 0 , sizeof( V_334 ) ) ;
}
if ( V_371 == V_377 ) {
return F_4 ( V_166 | V_176 | V_329 ,
( unsigned int T_1 * ) V_5 ) ;
} else if ( V_371 == V_375 )
return F_277 ( V_82 , & V_334 ) ;
V_276 = 0 ;
F_76 () ;
V_2 = F_90 ( V_38 ) ;
if ( V_371 == V_374 ) {
V_276 = - V_378 ;
if ( V_2 )
goto V_42;
V_334 . V_335 [ V_379 - 1 ] = '\0' ;
V_276 = F_254 ( F_281 ( & V_38 -> V_64 ) , V_82 , & V_334 ) ;
if ( V_276 )
goto V_42;
if ( F_282 ( V_5 , & V_334 , V_372 ) )
V_276 = - V_7 ;
goto V_42;
}
if ( V_371 == V_380 ) {
V_276 = - V_338 ;
if ( V_2 )
goto V_42;
V_276 = - V_7 ;
if ( F_100 ( & V_346 , V_5 , sizeof( V_346 ) ) )
goto V_42;
V_276 = 0 ;
V_38 -> V_346 = V_346 ;
goto V_42;
}
V_276 = - V_281 ;
if ( ! V_2 )
goto V_42;
F_17 ( V_18 , V_2 , L_17 , V_371 ) ;
V_276 = 0 ;
switch ( V_371 ) {
case V_381 :
F_270 ( V_219 -> V_382 -> V_383 , V_2 , & V_334 ) ;
if ( V_38 -> V_41 )
V_334 . V_336 |= V_370 ;
if ( ! V_38 -> V_77 . V_64 -> V_120 )
V_334 . V_336 |= V_339 ;
if ( F_282 ( V_5 , & V_334 , V_372 ) )
V_276 = - V_7 ;
break;
case V_384 :
F_17 ( V_18 , V_2 , L_18 ,
V_102 ? L_19 : L_20 ) ;
break;
case V_385 :
if ( V_102 && ! ( V_2 -> V_3 & V_71 ) ) {
V_2 -> V_3 |= V_71 ;
F_283 ( V_81 ) ;
}
if ( ! V_102 && ( V_2 -> V_3 & V_71 ) ) {
V_2 -> V_3 &= ~ V_71 ;
F_82 ( V_81 ) ;
}
F_17 ( V_18 , V_2 , L_21 ,
V_102 ? L_20 : L_19 ) ;
break;
case V_386 :
V_55 = F_284 ( F_251 () , V_102 ) ;
if ( ! F_49 ( V_55 ) ) {
V_276 = - V_8 ;
break;
}
V_2 -> V_55 = V_55 ;
F_17 ( V_18 , V_2 , L_22 ,
F_285 ( & V_387 , V_2 -> V_55 ) ) ;
break;
case V_388 :
V_57 = F_286 ( F_251 () , V_102 ) ;
if ( ! F_51 ( V_57 ) ) {
V_276 = - V_8 ;
break;
}
V_2 -> V_57 = V_57 ;
F_17 ( V_18 , V_2 , L_23 ,
F_287 ( & V_387 , V_2 -> V_57 ) ) ;
break;
case V_389 :
if ( V_2 -> V_46 -> V_3 & V_190 ) {
F_17 ( V_18 , V_2 ,
L_24 ) ;
V_276 = - V_88 ;
} else {
V_2 -> V_46 -> type = ( int ) V_102 ;
F_17 ( V_18 , V_2 , L_25 ,
V_2 -> V_46 -> type ) ;
V_276 = 0 ;
}
break;
#ifdef F_288
case V_390 :
V_2 -> V_391 = V_102 ;
break;
#endif
case V_392 :
V_276 = F_271 ( V_2 , V_102 ) ;
break;
case V_393 :
V_276 = - V_8 ;
if ( ( V_2 -> V_3 & V_165 ) != V_176 )
break;
V_276 = F_99 ( & V_2 -> V_119 , ( void T_1 * ) V_102 ) ;
break;
case V_394 :
memcpy ( V_334 . V_395 . V_396 , V_2 -> V_46 -> V_397 , V_99 ) ;
V_334 . V_395 . V_398 = V_2 -> V_46 -> type ;
if ( F_282 ( V_5 , & V_334 , V_372 ) )
V_276 = - V_7 ;
break;
case V_399 :
F_17 ( V_400 , V_2 , L_26 ,
V_334 . V_395 . V_396 ) ;
V_276 = F_289 ( V_2 -> V_46 , & V_334 . V_395 ) ;
break;
case V_401 :
V_349 = V_38 -> V_77 . V_64 -> V_208 ;
if ( F_282 ( V_5 , & V_349 , sizeof( V_349 ) ) )
V_276 = - V_7 ;
break;
case V_402 :
if ( F_100 ( & V_349 , V_5 , sizeof( V_349 ) ) ) {
V_276 = - V_7 ;
break;
}
if ( V_349 <= 0 ) {
V_276 = - V_8 ;
break;
}
V_2 -> V_349 = V_349 ;
F_276 ( V_2 ) ;
break;
case V_403 :
V_254 = V_2 -> V_254 ;
if ( F_282 ( V_5 , & V_254 , sizeof( V_254 ) ) )
V_276 = - V_7 ;
break;
case V_404 :
if ( F_100 ( & V_254 , V_5 , sizeof( V_254 ) ) ) {
V_276 = - V_7 ;
break;
}
if ( V_254 < ( int ) sizeof( struct V_214 ) ) {
V_276 = - V_8 ;
break;
}
V_2 -> V_254 = V_254 ;
break;
case V_405 :
V_373 = ! ! ( V_2 -> V_3 & V_9 ) ;
if ( F_4 ( V_373 , ( int T_1 * ) V_5 ) )
V_276 = - V_7 ;
break;
case V_406 :
if ( F_6 ( V_373 , ( int T_1 * ) V_5 ) ) {
V_276 = - V_7 ;
break;
}
if ( V_373 )
V_2 -> V_3 |= V_9 ;
else
V_2 -> V_3 &= ~ V_9 ;
break;
case V_407 :
V_276 = F_3 ( V_2 , V_5 ) ;
break;
case V_408 :
V_276 = F_5 ( V_2 , V_5 ) ;
break;
case V_409 :
V_276 = - V_8 ;
if ( ( V_2 -> V_3 & V_165 ) != V_176 )
break;
V_276 = - V_7 ;
if ( F_100 ( & V_2 -> V_93 , V_5 , sizeof( V_2 -> V_93 ) ) )
break;
V_276 = F_275 ( V_2 ) ;
break;
case V_410 :
V_276 = - V_8 ;
if ( ( V_2 -> V_3 & V_165 ) != V_176 )
break;
V_276 = 0 ;
F_273 ( V_2 , V_2 -> V_40 ) ;
break;
case V_411 :
V_276 = - V_8 ;
if ( ( V_2 -> V_3 & V_165 ) != V_176 )
break;
V_276 = - V_7 ;
if ( F_282 ( V_5 , & V_2 -> V_93 , sizeof( V_2 -> V_93 ) ) )
break;
V_276 = 0 ;
break;
default:
V_276 = - V_8 ;
break;
}
V_42:
F_77 () ;
if ( V_2 )
F_94 ( V_2 ) ;
return V_276 ;
}
static long F_290 ( struct V_82 * V_82 ,
unsigned int V_371 , unsigned long V_102 )
{
return F_279 ( V_82 , V_371 , V_102 , sizeof ( struct V_333 ) ) ;
}
static long F_291 ( struct V_82 * V_82 ,
unsigned int V_371 , unsigned long V_102 )
{
switch ( V_371 ) {
case V_374 :
case V_381 :
case V_393 :
case V_401 :
case V_402 :
case V_394 :
case V_399 :
V_102 = ( unsigned long ) F_292 ( V_102 ) ;
break;
default:
V_102 = ( V_412 ) V_102 ;
break;
}
return F_279 ( V_82 , V_371 , V_102 , sizeof( struct V_413 ) ) ;
}
static int F_293 ( int V_414 , struct V_82 * V_82 , int V_415 )
{
struct V_37 * V_38 = V_82 -> V_84 ;
int V_276 ;
if ( ( V_276 = F_294 ( V_414 , V_82 , V_415 , & V_38 -> V_122 ) ) < 0 )
goto V_87;
if ( V_415 ) {
F_295 ( V_82 , F_296 ( V_219 ) , V_416 , 0 ) ;
V_38 -> V_3 |= V_121 ;
} else
V_38 -> V_3 &= ~ V_121 ;
V_276 = 0 ;
V_87:
return V_276 ;
}
static int F_297 ( struct V_417 * V_417 , struct V_82 * V_82 )
{
struct V_54 * V_54 = V_219 -> V_382 -> V_383 ;
struct V_37 * V_38 ;
F_298 ( V_18 , L_27 ) ;
V_38 = (struct V_37 * ) F_299 ( V_54 , V_418 , V_95 ,
& V_419 , 0 ) ;
if ( ! V_38 )
return - V_96 ;
F_69 ( V_38 -> V_2 , NULL ) ;
V_38 -> V_3 = 0 ;
V_38 -> V_346 = 0 ;
F_300 ( & V_38 -> V_300 . V_185 ) ;
F_69 ( V_38 -> V_77 . V_300 , & V_38 -> V_300 ) ;
V_38 -> V_77 . V_82 = V_82 ;
V_38 -> V_77 . V_420 = & V_421 ;
F_301 ( & V_38 -> V_77 , & V_38 -> V_64 ) ;
V_38 -> V_64 . V_114 = F_236 ;
V_38 -> V_64 . V_208 = V_209 ;
V_82 -> V_84 = V_38 ;
F_264 ( & V_38 -> V_60 ) ;
F_302 ( & V_38 -> V_64 , V_422 ) ;
return 0 ;
}
static int F_303 ( struct V_417 * V_417 , struct V_82 * V_82 )
{
struct V_37 * V_38 = V_82 -> V_84 ;
F_75 ( V_38 , true ) ;
return 0 ;
}
static void F_304 ( struct V_423 * V_320 , struct V_82 * V_424 )
{
struct V_1 * V_2 ;
struct V_333 V_334 ;
memset ( & V_334 , 0 , sizeof( V_334 ) ) ;
F_76 () ;
V_2 = F_93 ( V_424 ) ;
if ( V_2 )
F_270 ( V_219 -> V_382 -> V_383 , V_2 , & V_334 ) ;
F_77 () ;
if ( V_2 )
F_94 ( V_2 ) ;
F_305 ( V_320 , L_28 , V_334 . V_335 ) ;
}
static int F_306 ( struct V_45 * V_46 ,
struct V_425 * V_371 )
{
F_307 ( V_371 , V_426 ) ;
F_307 ( V_371 , V_427 ) ;
V_371 -> V_428 . V_429 = V_430 ;
V_371 -> V_428 . V_431 = V_432 ;
V_371 -> V_428 . V_433 = V_434 ;
V_371 -> V_428 . V_435 = 0 ;
V_371 -> V_428 . V_436 = V_437 ;
return 0 ;
}
static void F_308 ( struct V_45 * V_46 , struct V_438 * V_439 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
F_309 ( V_439 -> V_440 , V_441 , sizeof( V_439 -> V_440 ) ) ;
F_309 ( V_439 -> V_442 , V_443 , sizeof( V_439 -> V_442 ) ) ;
switch ( V_2 -> V_3 & V_165 ) {
case V_166 :
F_309 ( V_439 -> V_444 , L_29 , sizeof( V_439 -> V_444 ) ) ;
break;
case V_176 :
F_309 ( V_439 -> V_444 , L_30 , sizeof( V_439 -> V_444 ) ) ;
break;
}
}
static T_4 F_310 ( struct V_45 * V_46 )
{
#ifdef F_288
struct V_1 * V_2 = F_41 ( V_46 ) ;
return V_2 -> V_391 ;
#else
return - V_445 ;
#endif
}
static void F_311 ( struct V_45 * V_46 , T_4 V_446 )
{
#ifdef F_288
struct V_1 * V_2 = F_41 ( V_46 ) ;
V_2 -> V_391 = V_446 ;
#endif
}
static int F_312 ( struct V_45 * V_46 ,
struct V_447 * V_448 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
V_448 -> V_449 = V_2 -> V_204 ;
return 0 ;
}
static int F_313 ( struct V_45 * V_46 ,
struct V_447 * V_448 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
if ( V_448 -> V_449 > V_450 )
V_2 -> V_204 = V_450 ;
else
V_2 -> V_204 = V_448 -> V_449 ;
return 0 ;
}
static int F_314 ( struct V_1 * V_2 )
{
struct V_45 * V_46 = V_2 -> V_46 ;
struct V_37 * V_38 ;
struct V_451 * * V_452 ;
int V_29 = V_2 -> V_40 + V_2 -> V_62 ;
int V_276 , V_25 ;
V_452 = F_315 ( V_29 , sizeof( * V_452 ) , V_95 ) ;
if ( ! V_452 )
return - V_96 ;
for ( V_25 = 0 ; V_25 < V_2 -> V_40 ; V_25 ++ ) {
V_38 = F_66 ( V_2 -> V_70 [ V_25 ] ) ;
V_452 [ V_25 ] = & V_38 -> V_63 ;
}
F_79 (tfile, &tun->disabled, next)
V_452 [ V_25 ++ ] = & V_38 -> V_63 ;
V_276 = F_316 ( V_452 , V_29 ,
V_46 -> V_94 , V_95 ) ;
F_106 ( V_452 ) ;
return V_276 ;
}
static int F_317 ( struct V_453 * V_454 ,
unsigned long V_455 , void * V_456 )
{
struct V_45 * V_46 = F_318 ( V_456 ) ;
struct V_1 * V_2 = F_41 ( V_46 ) ;
if ( V_46 -> V_344 != & V_345 )
return V_457 ;
switch ( V_455 ) {
case V_458 :
if ( F_314 ( V_2 ) )
return V_459 ;
break;
default:
break;
}
return V_457 ;
}
static int T_17 F_319 ( void )
{
int V_276 = 0 ;
F_320 ( L_31 , V_460 , V_443 ) ;
V_276 = F_321 ( & V_345 ) ;
if ( V_276 ) {
F_213 ( L_32 ) ;
goto V_461;
}
V_276 = F_322 ( & V_462 ) ;
if ( V_276 ) {
F_213 ( L_33 , V_463 ) ;
goto V_464;
}
V_276 = F_323 ( & V_465 ) ;
if ( V_276 ) {
F_213 ( L_34 ) ;
goto V_466;
}
return 0 ;
V_466:
F_324 ( & V_462 ) ;
V_464:
F_325 ( & V_345 ) ;
V_461:
return V_276 ;
}
static void F_326 ( void )
{
F_324 ( & V_462 ) ;
F_325 ( & V_345 ) ;
F_327 ( & V_465 ) ;
}
struct V_77 * F_328 ( struct V_82 * V_82 )
{
struct V_37 * V_38 ;
if ( V_82 -> V_467 != & V_468 )
return F_154 ( - V_8 ) ;
V_38 = V_82 -> V_84 ;
if ( ! V_38 )
return F_154 ( - V_281 ) ;
return & V_38 -> V_77 ;
}
struct V_451 * F_329 ( struct V_82 * V_82 )
{
struct V_37 * V_38 ;
if ( V_82 -> V_467 != & V_468 )
return F_154 ( - V_8 ) ;
V_38 = V_82 -> V_84 ;
if ( ! V_38 )
return F_154 ( - V_281 ) ;
return & V_38 -> V_63 ;
}
