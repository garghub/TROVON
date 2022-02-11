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
V_38 -> V_74 . V_63 -> V_75 ( V_38 -> V_74 . V_63 ) ;
F_67 ( V_38 -> V_2 , NULL ) ;
-- V_2 -> V_40 ;
}
F_76 (tfile, &tun->disabled, next) {
V_38 -> V_74 . V_63 -> V_75 ( V_38 -> V_74 . V_63 ) ;
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
F_78 ( V_76 ) ;
}
static int F_79 ( struct V_1 * V_2 , struct V_77 * V_77 , bool V_78 )
{
struct V_37 * V_38 = V_77 -> V_79 ;
int V_80 ;
V_80 = F_80 ( V_38 -> V_74 . V_63 , V_2 -> V_81 ) ;
if ( V_80 < 0 )
goto V_82;
V_80 = - V_8 ;
if ( F_64 ( V_38 -> V_2 ) && ! V_38 -> V_41 )
goto V_82;
V_80 = - V_83 ;
if ( ! ( V_2 -> V_3 & V_84 ) && V_2 -> V_40 == 1 )
goto V_82;
V_80 = - V_85 ;
if ( ! V_38 -> V_41 &&
V_2 -> V_40 + V_2 -> V_62 == V_86 )
goto V_82;
V_80 = 0 ;
if ( ! V_78 && ( V_2 -> V_87 == true ) ) {
V_80 = F_81 ( & V_2 -> V_88 , V_38 -> V_74 . V_63 ) ;
if ( ! V_80 )
goto V_82;
}
V_38 -> V_16 = V_2 -> V_40 ;
F_66 ( V_38 -> V_2 , V_2 ) ;
F_66 ( V_2 -> V_69 [ V_2 -> V_40 ] , V_38 ) ;
V_2 -> V_40 ++ ;
if ( V_38 -> V_41 )
F_59 ( V_38 ) ;
else
F_82 ( & V_38 -> V_63 ) ;
F_54 ( V_2 ) ;
V_82:
return V_80 ;
}
static struct V_1 * F_83 ( struct V_37 * V_38 )
{
struct V_1 * V_2 ;
F_33 () ;
V_2 = F_84 ( V_38 -> V_2 ) ;
if ( V_2 )
F_85 ( V_2 -> V_46 ) ;
F_37 () ;
return V_2 ;
}
static struct V_1 * F_86 ( struct V_77 * V_77 )
{
return F_83 ( V_77 -> V_79 ) ;
}
static void F_87 ( struct V_1 * V_2 )
{
F_88 ( V_2 -> V_46 ) ;
}
static void F_89 ( T_4 * V_89 , const T_6 * V_90 )
{
int V_29 = F_90 ( V_91 , V_90 ) >> 26 ;
V_89 [ V_29 >> 5 ] |= ( 1 << ( V_29 & 31 ) ) ;
}
static unsigned int F_91 ( const T_4 * V_89 , const T_6 * V_90 )
{
int V_29 = F_90 ( V_91 , V_90 ) >> 26 ;
return V_89 [ V_29 >> 5 ] & ( 1 << ( V_29 & 31 ) ) ;
}
static int F_92 ( struct V_92 * V_93 , void T_1 * V_94 )
{
struct { T_6 V_95 [ V_91 ] ; } * V_90 ;
struct V_96 V_97 ;
int V_80 , V_98 , V_29 , V_99 ;
if ( F_93 ( & V_97 , V_94 , sizeof( V_97 ) ) )
return - V_7 ;
if ( ! V_97 . V_34 ) {
V_93 -> V_34 = 0 ;
return 0 ;
}
V_98 = V_91 * V_97 . V_34 ;
V_90 = F_16 ( V_98 , V_100 ) ;
if ( ! V_90 )
return - V_101 ;
if ( F_93 ( V_90 , V_94 + sizeof( V_97 ) , V_98 ) ) {
V_80 = - V_7 ;
goto V_102;
}
V_93 -> V_34 = 0 ;
F_94 () ;
for ( V_29 = 0 ; V_29 < V_97 . V_34 && V_29 < V_103 ; V_29 ++ )
memcpy ( V_93 -> V_90 [ V_29 ] , V_90 [ V_29 ] . V_95 , V_91 ) ;
V_99 = V_29 ;
memset ( V_93 -> V_89 , 0 , sizeof( V_93 -> V_89 ) ) ;
for (; V_29 < V_97 . V_34 ; V_29 ++ ) {
if ( ! F_95 ( V_90 [ V_29 ] . V_95 ) ) {
V_80 = 0 ;
goto V_102;
}
F_89 ( V_93 -> V_89 , V_90 [ V_29 ] . V_95 ) ;
}
if ( ( V_97 . V_3 & V_104 ) )
memset ( V_93 -> V_89 , ~ 0 , sizeof( V_93 -> V_89 ) ) ;
F_94 () ;
V_93 -> V_34 = V_99 ;
V_80 = V_99 ;
V_102:
F_96 ( V_90 ) ;
return V_80 ;
}
static int F_97 ( struct V_92 * V_93 , const struct V_47 * V_48 )
{
struct V_105 * V_106 = (struct V_105 * ) V_48 -> V_30 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_93 -> V_34 ; V_25 ++ )
if ( F_98 ( V_106 -> V_107 , V_93 -> V_90 [ V_25 ] ) )
return 1 ;
if ( F_95 ( V_106 -> V_107 ) )
return F_91 ( V_93 -> V_89 , V_106 -> V_107 ) ;
return 0 ;
}
static int F_99 ( struct V_92 * V_93 , const struct V_47 * V_48 )
{
if ( ! V_93 -> V_34 )
return 1 ;
return F_97 ( V_93 , V_48 ) ;
}
static void F_100 ( struct V_45 * V_46 )
{
F_75 ( V_46 ) ;
}
static int F_101 ( struct V_45 * V_46 )
{
F_102 ( V_46 ) ;
return 0 ;
}
static int F_103 ( struct V_45 * V_46 )
{
F_104 ( V_46 ) ;
return 0 ;
}
static T_7 F_105 ( struct V_47 * V_48 , struct V_45 * V_46 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
int V_51 = V_48 -> V_108 ;
struct V_37 * V_38 ;
T_4 V_40 = 0 ;
F_33 () ;
V_38 = F_84 ( V_2 -> V_69 [ V_51 ] ) ;
V_40 = F_42 ( V_2 -> V_40 ) ;
if ( V_51 >= V_40 )
goto V_109;
if ( V_40 == 1 ) {
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
F_17 ( V_18 , V_2 , L_4 , V_48 -> V_110 ) ;
F_65 ( ! V_38 ) ;
if ( ! F_99 ( & V_2 -> V_111 , V_48 ) )
goto V_109;
if ( V_38 -> V_74 . V_63 -> V_112 &&
V_112 ( V_38 -> V_74 . V_63 , V_48 ) )
goto V_109;
if ( F_106 ( & V_38 -> V_74 . V_63 -> V_64 ) * V_40
>= V_46 -> V_113 )
goto V_109;
if ( F_39 ( F_107 ( V_48 , V_17 ) ) )
goto V_109;
if ( V_48 -> V_63 && F_108 ( V_48 -> V_63 ) ) {
F_109 ( V_48 -> V_63 , & F_110 ( V_48 ) -> V_114 ) ;
F_111 ( V_48 ) ;
}
F_112 ( V_48 ) ;
F_113 ( V_48 ) ;
F_114 ( & V_38 -> V_74 . V_63 -> V_64 , V_48 ) ;
if ( V_38 -> V_3 & V_115 )
F_115 ( & V_38 -> V_116 , V_117 , V_118 ) ;
V_38 -> V_74 . V_63 -> V_75 ( V_38 -> V_74 . V_63 ) ;
F_37 () ;
return V_119 ;
V_109:
V_46 -> V_120 . V_121 ++ ;
F_116 ( V_48 ) ;
F_117 ( V_48 ) ;
F_37 () ;
return V_122 ;
}
static void F_118 ( struct V_45 * V_46 )
{
}
static int
F_119 ( struct V_45 * V_46 , int V_123 )
{
if ( V_123 < V_124 || V_123 + V_46 -> V_125 > V_126 )
return - V_8 ;
V_46 -> V_127 = V_123 ;
return 0 ;
}
static T_9 F_120 ( struct V_45 * V_46 ,
T_9 V_128 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
return ( V_128 & V_2 -> V_129 ) | ( V_128 & ~ V_130 ) ;
}
static void F_121 ( struct V_45 * V_46 )
{
return;
}
static void F_122 ( struct V_1 * V_2 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_27 ; V_25 ++ )
F_123 ( & V_2 -> V_39 [ V_25 ] ) ;
V_2 -> V_32 = V_131 ;
F_124 ( & V_2 -> V_36 , F_27 , ( unsigned long ) V_2 ) ;
F_30 ( & V_2 -> V_36 ,
F_31 ( V_20 + V_2 -> V_32 ) ) ;
}
static void F_125 ( struct V_1 * V_2 )
{
F_126 ( & V_2 -> V_36 ) ;
F_22 ( V_2 ) ;
}
static void F_127 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
switch ( V_2 -> V_3 & V_132 ) {
case V_133 :
V_46 -> V_134 = & V_135 ;
V_46 -> V_125 = 0 ;
V_46 -> V_136 = 0 ;
V_46 -> V_127 = 1500 ;
V_46 -> type = V_137 ;
V_46 -> V_3 = V_138 | V_139 | V_140 ;
V_46 -> V_113 = V_141 ;
break;
case V_142 :
V_46 -> V_134 = & V_143 ;
F_128 ( V_46 ) ;
V_46 -> V_144 &= ~ V_145 ;
V_46 -> V_144 |= V_146 ;
F_129 ( V_46 ) ;
V_46 -> V_113 = V_141 ;
break;
}
}
static unsigned int F_130 ( struct V_77 * V_77 , T_10 * V_147 )
{
struct V_37 * V_38 = V_77 -> V_79 ;
struct V_1 * V_2 = F_83 ( V_38 ) ;
struct V_148 * V_63 ;
unsigned int V_89 = 0 ;
if ( ! V_2 )
return V_149 ;
V_63 = V_38 -> V_74 . V_63 ;
F_17 ( V_18 , V_2 , L_5 ) ;
F_131 ( V_77 , F_132 ( V_63 ) , V_147 ) ;
if ( ! F_133 ( & V_63 -> V_64 ) )
V_89 |= V_150 | V_151 ;
if ( F_134 ( V_63 ) ||
( ! F_135 ( V_152 , & V_63 -> V_153 -> V_3 ) &&
F_134 ( V_63 ) ) )
V_89 |= V_154 | V_155 ;
if ( V_2 -> V_46 -> V_71 != V_72 )
V_89 = V_149 ;
F_87 ( V_2 ) ;
return V_89 ;
}
static struct V_47 * F_136 ( struct V_37 * V_38 ,
T_11 V_156 , T_11 V_110 ,
T_11 V_157 , int V_158 )
{
struct V_148 * V_63 = V_38 -> V_74 . V_63 ;
struct V_47 * V_48 ;
int V_80 ;
if ( V_156 + V_110 < V_159 || ! V_157 )
V_157 = V_110 ;
V_48 = F_137 ( V_63 , V_156 + V_157 , V_110 - V_157 , V_158 ,
& V_80 , 0 ) ;
if ( ! V_48 )
return F_138 ( V_80 ) ;
F_139 ( V_48 , V_156 ) ;
F_140 ( V_48 , V_157 ) ;
V_48 -> V_160 = V_110 - V_157 ;
V_48 -> V_110 += V_110 - V_157 ;
return V_48 ;
}
static T_12 F_141 ( struct V_1 * V_2 , struct V_37 * V_38 ,
void * V_161 , struct V_162 * V_163 ,
int V_158 )
{
struct V_164 V_165 = { 0 , F_142 (ETH_P_IP) } ;
struct V_47 * V_48 ;
T_11 V_166 = F_143 ( V_163 ) ;
T_11 V_110 = V_166 , V_167 = V_168 , V_157 ;
struct V_169 V_170 = { 0 } ;
int V_171 ;
int V_172 ;
bool V_173 = false ;
int V_80 ;
T_4 V_11 ;
T_12 V_29 ;
if ( ! ( V_2 -> V_46 -> V_3 & V_174 ) )
return - V_175 ;
if ( ! ( V_2 -> V_3 & V_176 ) ) {
if ( V_110 < sizeof( V_165 ) )
return - V_8 ;
V_110 -= sizeof( V_165 ) ;
V_29 = F_144 ( & V_165 , sizeof( V_165 ) , V_163 ) ;
if ( V_29 != sizeof( V_165 ) )
return - V_7 ;
}
if ( V_2 -> V_3 & V_177 ) {
if ( V_110 < V_2 -> V_178 )
return - V_8 ;
V_110 -= V_2 -> V_178 ;
V_29 = F_144 ( & V_170 , sizeof( V_170 ) , V_163 ) ;
if ( V_29 != sizeof( V_170 ) )
return - V_7 ;
if ( ( V_170 . V_3 & V_179 ) &&
F_8 ( V_2 , V_170 . V_180 ) + F_8 ( V_2 , V_170 . V_181 ) + 2 > F_8 ( V_2 , V_170 . V_182 ) )
V_170 . V_182 = F_10 ( V_2 , F_8 ( V_2 , V_170 . V_180 ) + F_8 ( V_2 , V_170 . V_181 ) + 2 ) ;
if ( F_8 ( V_2 , V_170 . V_182 ) > V_110 )
return - V_8 ;
F_145 ( V_163 , V_2 -> V_178 - sizeof( V_170 ) ) ;
}
if ( ( V_2 -> V_3 & V_132 ) == V_142 ) {
V_167 += V_183 ;
if ( F_39 ( V_110 < V_184 ||
( V_170 . V_182 && F_8 ( V_2 , V_170 . V_182 ) < V_184 ) ) )
return - V_8 ;
}
V_171 = F_146 ( V_167 ) ;
if ( V_161 ) {
struct V_162 V_25 = * V_163 ;
V_172 = V_170 . V_182 ? F_8 ( V_2 , V_170 . V_182 ) : V_185 ;
if ( V_172 > V_171 )
V_172 = V_171 ;
V_157 = V_172 ;
F_145 ( & V_25 , V_172 ) ;
if ( F_147 ( & V_25 , V_186 ) <= V_187 )
V_173 = true ;
}
if ( ! V_173 ) {
V_172 = V_110 ;
if ( F_8 ( V_2 , V_170 . V_182 ) > V_171 )
V_157 = V_171 ;
else
V_157 = F_8 ( V_2 , V_170 . V_182 ) ;
}
V_48 = F_136 ( V_38 , V_167 , V_172 , V_157 , V_158 ) ;
if ( F_148 ( V_48 ) ) {
if ( F_149 ( V_48 ) != - V_188 )
V_2 -> V_46 -> V_120 . V_189 ++ ;
return F_149 ( V_48 ) ;
}
if ( V_173 )
V_80 = F_150 ( V_48 , V_163 ) ;
else {
V_80 = F_151 ( V_48 , 0 , V_163 , V_110 ) ;
if ( ! V_80 && V_161 ) {
struct V_190 * V_191 = V_161 ;
V_191 -> V_192 ( V_191 , false ) ;
}
}
if ( V_80 ) {
V_2 -> V_46 -> V_120 . V_189 ++ ;
F_117 ( V_48 ) ;
return - V_7 ;
}
if ( V_170 . V_3 & V_179 ) {
if ( ! F_152 ( V_48 , F_8 ( V_2 , V_170 . V_180 ) ,
F_8 ( V_2 , V_170 . V_181 ) ) ) {
V_2 -> V_46 -> V_120 . V_193 ++ ;
F_117 ( V_48 ) ;
return - V_8 ;
}
}
switch ( V_2 -> V_3 & V_132 ) {
case V_133 :
if ( V_2 -> V_3 & V_176 ) {
switch ( V_48 -> V_30 [ 0 ] & 0xf0 ) {
case 0x40 :
V_165 . V_194 = F_153 ( V_195 ) ;
break;
case 0x60 :
V_165 . V_194 = F_153 ( V_196 ) ;
break;
default:
V_2 -> V_46 -> V_120 . V_189 ++ ;
F_117 ( V_48 ) ;
return - V_8 ;
}
}
F_154 ( V_48 ) ;
V_48 -> V_197 = V_165 . V_194 ;
V_48 -> V_46 = V_2 -> V_46 ;
break;
case V_142 :
V_48 -> V_197 = F_155 ( V_48 , V_2 -> V_46 ) ;
break;
}
if ( V_170 . V_198 != V_199 ) {
F_156 ( L_6 ) ;
switch ( V_170 . V_198 & ~ V_200 ) {
case V_201 :
F_110 ( V_48 ) -> V_198 = V_202 ;
break;
case V_203 :
F_110 ( V_48 ) -> V_198 = V_204 ;
break;
case V_205 :
F_110 ( V_48 ) -> V_198 = V_206 ;
break;
default:
V_2 -> V_46 -> V_120 . V_193 ++ ;
F_117 ( V_48 ) ;
return - V_8 ;
}
if ( V_170 . V_198 & V_200 )
F_110 ( V_48 ) -> V_198 |= V_207 ;
F_110 ( V_48 ) -> V_208 = F_8 ( V_2 , V_170 . V_208 ) ;
if ( F_110 ( V_48 ) -> V_208 == 0 ) {
V_2 -> V_46 -> V_120 . V_193 ++ ;
F_117 ( V_48 ) ;
return - V_8 ;
}
F_110 ( V_48 ) -> V_198 |= V_209 ;
F_110 ( V_48 ) -> V_210 = 0 ;
}
if ( V_173 ) {
F_110 ( V_48 ) -> V_211 = V_161 ;
F_110 ( V_48 ) -> V_114 |= V_212 ;
F_110 ( V_48 ) -> V_114 |= V_213 ;
}
F_157 ( V_48 ) ;
F_158 ( V_48 , 0 ) ;
V_11 = F_43 ( V_48 ) ;
F_159 ( V_48 ) ;
V_2 -> V_46 -> V_120 . V_214 ++ ;
V_2 -> V_46 -> V_120 . V_215 += V_110 ;
F_32 ( V_2 , V_11 , V_38 ) ;
return V_166 ;
}
static T_12 F_160 ( struct V_216 * V_217 , struct V_162 * V_163 )
{
struct V_77 * V_77 = V_217 -> V_218 ;
struct V_1 * V_2 = F_86 ( V_77 ) ;
struct V_37 * V_38 = V_77 -> V_79 ;
T_12 V_219 ;
if ( ! V_2 )
return - V_220 ;
V_219 = F_141 ( V_2 , V_38 , NULL , V_163 , V_77 -> V_221 & V_222 ) ;
F_87 ( V_2 ) ;
return V_219 ;
}
static T_12 F_161 ( struct V_1 * V_2 ,
struct V_37 * V_38 ,
struct V_47 * V_48 ,
struct V_162 * V_223 )
{
struct V_164 V_165 = { 0 , V_48 -> V_197 } ;
T_12 V_224 ;
int V_225 = 0 ;
int V_226 = 0 ;
int V_178 = 0 ;
if ( F_162 ( V_48 ) )
V_226 = V_227 ;
if ( V_2 -> V_3 & V_177 )
V_178 = V_2 -> V_178 ;
V_224 = V_48 -> V_110 + V_226 + V_178 ;
if ( ! ( V_2 -> V_3 & V_176 ) ) {
if ( F_143 ( V_223 ) < sizeof( V_165 ) )
return - V_8 ;
V_224 += sizeof( V_165 ) ;
if ( F_143 ( V_223 ) < V_224 ) {
V_165 . V_3 |= V_228 ;
}
if ( F_163 ( & V_165 , sizeof( V_165 ) , V_223 ) != sizeof( V_165 ) )
return - V_7 ;
}
if ( V_178 ) {
struct V_169 V_170 = { 0 } ;
if ( F_143 ( V_223 ) < V_178 )
return - V_8 ;
if ( F_164 ( V_48 ) ) {
struct V_229 * V_230 = F_110 ( V_48 ) ;
V_170 . V_182 = F_10 ( V_2 , F_165 ( V_48 ) ) ;
V_170 . V_208 = F_10 ( V_2 , V_230 -> V_208 ) ;
if ( V_230 -> V_198 & V_202 )
V_170 . V_198 = V_201 ;
else if ( V_230 -> V_198 & V_204 )
V_170 . V_198 = V_203 ;
else if ( V_230 -> V_198 & V_206 )
V_170 . V_198 = V_205 ;
else {
F_166 ( L_7
L_8 ,
V_230 -> V_198 , F_8 ( V_2 , V_170 . V_208 ) ,
F_8 ( V_2 , V_170 . V_182 ) ) ;
F_167 ( V_231 , L_9 ,
V_232 ,
16 , 1 , V_48 -> V_14 ,
F_168 ( ( int ) F_8 ( V_2 , V_170 . V_182 ) , 64 ) , true ) ;
F_169 ( 1 ) ;
return - V_8 ;
}
if ( V_230 -> V_198 & V_207 )
V_170 . V_198 |= V_200 ;
} else
V_170 . V_198 = V_199 ;
if ( V_48 -> V_233 == V_234 ) {
V_170 . V_3 = V_179 ;
V_170 . V_180 = F_10 ( V_2 , F_170 ( V_48 ) +
V_226 ) ;
V_170 . V_181 = F_10 ( V_2 , V_48 -> V_181 ) ;
} else if ( V_48 -> V_233 == V_235 ) {
V_170 . V_3 = V_236 ;
}
if ( F_163 ( & V_170 , sizeof( V_170 ) , V_223 ) != sizeof( V_170 ) )
return - V_7 ;
F_145 ( V_223 , V_178 - sizeof( V_170 ) ) ;
}
if ( V_226 ) {
int V_237 ;
struct {
T_13 V_238 ;
T_13 V_239 ;
} V_240 ;
V_240 . V_238 = V_48 -> V_241 ;
V_240 . V_239 = F_153 ( F_171 ( V_48 ) ) ;
V_225 = F_172 ( struct V_242 , V_238 ) ;
V_237 = F_173 ( V_48 , 0 , V_223 , V_225 ) ;
if ( V_237 || ! F_143 ( V_223 ) )
goto V_102;
V_237 = F_163 ( & V_240 , sizeof( V_240 ) , V_223 ) ;
if ( V_237 != sizeof( V_240 ) || ! F_143 ( V_223 ) )
goto V_102;
}
F_173 ( V_48 , V_225 , V_223 , V_48 -> V_110 - V_225 ) ;
V_102:
V_2 -> V_46 -> V_120 . V_243 ++ ;
V_2 -> V_46 -> V_120 . V_244 += V_48 -> V_110 + V_226 ;
return V_224 ;
}
static T_12 F_174 ( struct V_1 * V_2 , struct V_37 * V_38 ,
struct V_162 * V_245 ,
int V_158 )
{
struct V_47 * V_48 ;
T_12 V_237 ;
int V_246 , V_80 , V_247 = 0 ;
F_17 ( V_18 , V_2 , L_10 ) ;
if ( ! F_143 ( V_245 ) )
return 0 ;
if ( V_2 -> V_46 -> V_71 != V_72 )
return - V_175 ;
V_48 = F_175 ( V_38 -> V_74 . V_63 , V_158 ? V_248 : 0 ,
& V_246 , & V_247 , & V_80 ) ;
if ( ! V_48 )
return V_80 ;
V_237 = F_161 ( V_2 , V_38 , V_48 , V_245 ) ;
if ( F_39 ( V_237 < 0 ) )
F_117 ( V_48 ) ;
else
F_176 ( V_48 ) ;
return V_237 ;
}
static T_12 F_177 ( struct V_216 * V_217 , struct V_162 * V_245 )
{
struct V_77 * V_77 = V_217 -> V_218 ;
struct V_37 * V_38 = V_77 -> V_79 ;
struct V_1 * V_2 = F_83 ( V_38 ) ;
T_12 V_110 = F_143 ( V_245 ) , V_237 ;
if ( ! V_2 )
return - V_220 ;
V_237 = F_174 ( V_2 , V_38 , V_245 , V_77 -> V_221 & V_222 ) ;
V_237 = F_178 ( T_12 , V_237 , V_110 ) ;
if ( V_237 > 0 )
V_217 -> V_249 = V_237 ;
F_87 ( V_2 ) ;
return V_237 ;
}
static void F_179 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
F_65 ( ! ( F_180 ( & V_2 -> V_61 ) ) ) ;
F_125 ( V_2 ) ;
F_181 ( V_2 -> V_81 ) ;
F_182 ( V_46 ) ;
}
static void F_183 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
V_2 -> V_55 = V_250 ;
V_2 -> V_57 = V_251 ;
V_46 -> V_252 = & V_253 ;
V_46 -> V_254 = F_179 ;
}
static int F_184 ( struct V_255 * V_256 [] , struct V_255 * V_30 [] )
{
return - V_8 ;
}
static void F_185 ( struct V_148 * V_63 )
{
struct V_37 * V_38 ;
T_14 * V_257 ;
if ( ! F_134 ( V_63 ) )
return;
if ( ! F_186 ( V_152 , & V_63 -> V_153 -> V_3 ) )
return;
V_257 = F_132 ( V_63 ) ;
if ( V_257 && F_187 ( V_257 ) )
F_188 ( V_257 , V_154 |
V_155 | V_258 ) ;
V_38 = F_189 ( V_63 , struct V_37 , V_63 ) ;
F_115 ( & V_38 -> V_116 , V_117 , V_259 ) ;
}
static int F_190 ( struct V_74 * V_148 , struct V_260 * V_261 , T_11 V_166 )
{
int V_237 ;
struct V_37 * V_38 = F_189 ( V_148 , struct V_37 , V_74 ) ;
struct V_1 * V_2 = F_83 ( V_38 ) ;
if ( ! V_2 )
return - V_220 ;
V_237 = F_141 ( V_2 , V_38 , V_261 -> V_161 , & V_261 -> V_262 ,
V_261 -> V_263 & V_248 ) ;
F_87 ( V_2 ) ;
return V_237 ;
}
static int F_191 ( struct V_74 * V_148 , struct V_260 * V_261 , T_11 V_166 ,
int V_3 )
{
struct V_37 * V_38 = F_189 ( V_148 , struct V_37 , V_74 ) ;
struct V_1 * V_2 = F_83 ( V_38 ) ;
int V_237 ;
if ( ! V_2 )
return - V_220 ;
if ( V_3 & ~ ( V_248 | V_264 | V_265 ) ) {
V_237 = - V_8 ;
goto V_82;
}
if ( V_3 & V_265 ) {
V_237 = F_192 ( V_148 -> V_63 , V_261 , V_166 ,
V_266 , V_267 ) ;
goto V_82;
}
V_237 = F_174 ( V_2 , V_38 , & V_261 -> V_262 , V_3 & V_248 ) ;
if ( V_237 > ( T_12 ) V_166 ) {
V_261 -> V_263 |= V_264 ;
V_237 = V_3 & V_264 ? V_237 : V_166 ;
}
V_82:
F_87 ( V_2 ) ;
return V_237 ;
}
static int F_193 ( struct V_1 * V_2 )
{
return V_2 -> V_3 & ( V_268 | V_70 | V_133 | V_142 ) ;
}
static T_12 F_194 ( struct V_269 * V_46 , struct V_270 * V_271 ,
char * V_272 )
{
struct V_1 * V_2 = F_41 ( F_195 ( V_46 ) ) ;
return sprintf ( V_272 , L_11 , F_193 ( V_2 ) ) ;
}
static T_12 F_196 ( struct V_269 * V_46 , struct V_270 * V_271 ,
char * V_272 )
{
struct V_1 * V_2 = F_41 ( F_195 ( V_46 ) ) ;
return F_49 ( V_2 -> V_55 ) ?
sprintf ( V_272 , L_12 ,
F_197 ( F_198 () , V_2 -> V_55 ) ) :
sprintf ( V_272 , L_13 ) ;
}
static T_12 F_199 ( struct V_269 * V_46 , struct V_270 * V_271 ,
char * V_272 )
{
struct V_1 * V_2 = F_41 ( F_195 ( V_46 ) ) ;
return F_51 ( V_2 -> V_57 ) ?
sprintf ( V_272 , L_12 ,
F_200 ( F_198 () , V_2 -> V_57 ) ) :
sprintf ( V_272 , L_13 ) ;
}
static int F_201 ( struct V_54 * V_54 , struct V_77 * V_77 , struct V_273 * V_274 )
{
struct V_1 * V_2 ;
struct V_37 * V_38 = V_77 -> V_79 ;
struct V_45 * V_46 ;
int V_80 ;
if ( V_38 -> V_41 )
return - V_8 ;
V_46 = F_202 ( V_54 , V_274 -> V_275 ) ;
if ( V_46 ) {
if ( V_274 -> V_276 & V_277 )
return - V_83 ;
if ( ( V_274 -> V_276 & V_133 ) && V_46 -> V_134 == & V_135 )
V_2 = F_41 ( V_46 ) ;
else if ( ( V_274 -> V_276 & V_142 ) && V_46 -> V_134 == & V_143 )
V_2 = F_41 ( V_46 ) ;
else
return - V_8 ;
if ( ! ! ( V_274 -> V_276 & V_84 ) !=
! ! ( V_2 -> V_3 & V_84 ) )
return - V_8 ;
if ( F_46 ( V_2 ) )
return - V_278 ;
V_80 = F_203 ( V_2 -> V_81 ) ;
if ( V_80 < 0 )
return V_80 ;
V_80 = F_79 ( V_2 , V_77 , V_274 -> V_276 & V_279 ) ;
if ( V_80 < 0 )
return V_80 ;
if ( V_2 -> V_3 & V_84 &&
( V_2 -> V_40 + V_2 -> V_62 > 1 ) ) {
return 0 ;
}
}
else {
char * V_280 ;
unsigned long V_3 = 0 ;
int V_281 = V_274 -> V_276 & V_84 ?
V_86 : 1 ;
if ( ! F_53 ( V_54 -> V_58 , V_59 ) )
return - V_278 ;
V_80 = F_204 () ;
if ( V_80 < 0 )
return V_80 ;
if ( V_274 -> V_276 & V_133 ) {
V_3 |= V_133 ;
V_280 = L_14 ;
} else if ( V_274 -> V_276 & V_142 ) {
V_3 |= V_142 ;
V_280 = L_15 ;
} else
return - V_8 ;
if ( * V_274 -> V_275 )
V_280 = V_274 -> V_275 ;
V_46 = F_205 ( sizeof( struct V_1 ) , V_280 ,
V_282 , F_183 , V_281 ,
V_281 ) ;
if ( ! V_46 )
return - V_101 ;
F_206 ( V_46 , V_54 ) ;
V_46 -> V_283 = & V_284 ;
V_46 -> V_285 = V_38 -> V_285 ;
V_46 -> V_286 [ 0 ] = & V_287 ;
V_2 = F_41 ( V_46 ) ;
V_2 -> V_46 = V_46 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_111 . V_34 = 0 ;
V_2 -> V_178 = sizeof( struct V_169 ) ;
V_2 -> V_87 = false ;
V_2 -> V_288 = V_38 -> V_74 . V_63 -> V_289 ;
F_207 ( & V_2 -> V_26 ) ;
V_80 = F_208 ( & V_2 -> V_81 ) ;
if ( V_80 < 0 )
goto V_290;
F_127 ( V_46 ) ;
F_122 ( V_2 ) ;
V_46 -> V_291 = V_292 | V_293 |
V_130 | V_294 |
V_295 ;
V_46 -> V_128 = V_46 -> V_291 ;
V_46 -> V_296 = V_46 -> V_128 &
~ ( V_294 |
V_295 ) ;
F_209 ( & V_2 -> V_61 ) ;
V_80 = F_79 ( V_2 , V_77 , false ) ;
if ( V_80 < 0 )
goto V_297;
V_80 = F_210 ( V_2 -> V_46 ) ;
if ( V_80 < 0 )
goto V_298;
}
F_211 ( V_2 -> V_46 ) ;
F_17 ( V_18 , V_2 , L_16 ) ;
V_2 -> V_3 = ( V_2 -> V_3 & ~ V_268 ) |
( V_274 -> V_276 & V_268 ) ;
if ( F_212 ( V_2 -> V_46 ) )
F_213 ( V_2 -> V_46 ) ;
strcpy ( V_274 -> V_275 , V_2 -> V_46 -> V_280 ) ;
return 0 ;
V_298:
F_75 ( V_46 ) ;
V_297:
F_125 ( V_2 ) ;
F_181 ( V_2 -> V_81 ) ;
V_290:
F_182 ( V_46 ) ;
return V_80 ;
}
static void F_214 ( struct V_54 * V_54 , struct V_1 * V_2 ,
struct V_273 * V_274 )
{
F_17 ( V_18 , V_2 , L_17 ) ;
strcpy ( V_274 -> V_275 , V_2 -> V_46 -> V_280 ) ;
V_274 -> V_276 = F_193 ( V_2 ) ;
}
static int F_215 ( struct V_1 * V_2 , unsigned long V_94 )
{
T_9 V_128 = 0 ;
if ( V_94 & V_299 ) {
V_128 |= V_300 ;
V_94 &= ~ V_299 ;
if ( V_94 & ( V_301 | V_302 ) ) {
if ( V_94 & V_303 ) {
V_128 |= V_304 ;
V_94 &= ~ V_303 ;
}
if ( V_94 & V_301 )
V_128 |= V_305 ;
if ( V_94 & V_302 )
V_128 |= V_306 ;
V_94 &= ~ ( V_301 | V_302 ) ;
}
if ( V_94 & V_307 ) {
V_128 |= V_308 ;
V_94 &= ~ V_307 ;
}
}
if ( V_94 )
return - V_8 ;
V_2 -> V_129 = V_128 ;
F_216 ( V_2 -> V_46 ) ;
return 0 ;
}
static void F_217 ( struct V_1 * V_2 , int V_29 )
{
int V_25 ;
struct V_37 * V_38 ;
for ( V_25 = 0 ; V_25 < V_29 ; V_25 ++ ) {
V_38 = F_64 ( V_2 -> V_69 [ V_25 ] ) ;
F_218 ( V_38 -> V_74 . V_63 ) ;
}
V_2 -> V_87 = false ;
}
static int F_219 ( struct V_1 * V_2 )
{
int V_25 , V_237 = 0 ;
struct V_37 * V_38 ;
for ( V_25 = 0 ; V_25 < V_2 -> V_40 ; V_25 ++ ) {
V_38 = F_64 ( V_2 -> V_69 [ V_25 ] ) ;
V_237 = F_81 ( & V_2 -> V_88 , V_38 -> V_74 . V_63 ) ;
if ( V_237 ) {
F_217 ( V_2 , V_25 ) ;
return V_237 ;
}
}
V_2 -> V_87 = true ;
return V_237 ;
}
static void F_220 ( struct V_1 * V_2 )
{
struct V_37 * V_38 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_2 -> V_40 ; V_25 ++ ) {
V_38 = F_64 ( V_2 -> V_69 [ V_25 ] ) ;
V_38 -> V_74 . V_63 -> V_289 = V_2 -> V_288 ;
}
}
static int F_221 ( struct V_77 * V_77 , struct V_273 * V_274 )
{
struct V_37 * V_38 = V_77 -> V_79 ;
struct V_1 * V_2 ;
int V_237 = 0 ;
F_73 () ;
if ( V_274 -> V_276 & V_309 ) {
V_2 = V_38 -> V_41 ;
if ( ! V_2 ) {
V_237 = - V_8 ;
goto V_42;
}
V_237 = F_222 ( V_2 -> V_81 ) ;
if ( V_237 < 0 )
goto V_42;
V_237 = F_79 ( V_2 , V_77 , false ) ;
} else if ( V_274 -> V_276 & V_310 ) {
V_2 = F_64 ( V_38 -> V_2 ) ;
if ( ! V_2 || ! ( V_2 -> V_3 & V_84 ) || V_38 -> V_41 )
V_237 = - V_8 ;
else
F_63 ( V_38 , false ) ;
} else
V_237 = - V_8 ;
V_42:
F_74 () ;
return V_237 ;
}
static long F_223 ( struct V_77 * V_77 , unsigned int V_311 ,
unsigned long V_94 , int V_312 )
{
struct V_37 * V_38 = V_77 -> V_79 ;
struct V_1 * V_2 ;
void T_1 * V_5 = ( void T_1 * ) V_94 ;
struct V_273 V_274 ;
T_15 V_55 ;
T_16 V_57 ;
int V_288 ;
int V_178 ;
unsigned int V_285 ;
int V_313 ;
int V_237 ;
if ( V_311 == V_314 || V_311 == V_315 || F_224 ( V_311 ) == 0x89 ) {
if ( F_93 ( & V_274 , V_5 , V_312 ) )
return - V_7 ;
} else {
memset ( & V_274 , 0 , sizeof( V_274 ) ) ;
}
if ( V_311 == V_316 ) {
return F_4 ( V_133 | V_142 | V_268 ,
( unsigned int T_1 * ) V_5 ) ;
} else if ( V_311 == V_315 )
return F_221 ( V_77 , & V_274 ) ;
V_237 = 0 ;
F_73 () ;
V_2 = F_83 ( V_38 ) ;
if ( V_311 == V_314 && ! V_2 ) {
V_274 . V_275 [ V_317 - 1 ] = '\0' ;
V_237 = F_201 ( F_225 ( & V_38 -> V_63 ) , V_77 , & V_274 ) ;
if ( V_237 )
goto V_42;
if ( F_226 ( V_5 , & V_274 , V_312 ) )
V_237 = - V_7 ;
goto V_42;
}
if ( V_311 == V_318 ) {
V_237 = - V_278 ;
if ( V_2 )
goto V_42;
V_237 = - V_7 ;
if ( F_93 ( & V_285 , V_5 , sizeof( V_285 ) ) )
goto V_42;
V_237 = 0 ;
V_38 -> V_285 = V_285 ;
goto V_42;
}
V_237 = - V_220 ;
if ( ! V_2 )
goto V_42;
F_17 ( V_18 , V_2 , L_18 , V_311 ) ;
V_237 = 0 ;
switch ( V_311 ) {
case V_319 :
F_214 ( V_320 -> V_321 -> V_322 , V_2 , & V_274 ) ;
if ( V_38 -> V_41 )
V_274 . V_276 |= V_310 ;
if ( ! V_38 -> V_74 . V_63 -> V_112 )
V_274 . V_276 |= V_279 ;
if ( F_226 ( V_5 , & V_274 , V_312 ) )
V_237 = - V_7 ;
break;
case V_323 :
F_17 ( V_18 , V_2 , L_19 ,
V_94 ? L_20 : L_21 ) ;
break;
case V_324 :
if ( V_94 && ! ( V_2 -> V_3 & V_70 ) ) {
V_2 -> V_3 |= V_70 ;
F_227 ( V_76 ) ;
}
if ( ! V_94 && ( V_2 -> V_3 & V_70 ) ) {
V_2 -> V_3 &= ~ V_70 ;
F_78 ( V_76 ) ;
}
F_17 ( V_18 , V_2 , L_22 ,
V_94 ? L_21 : L_20 ) ;
break;
case V_325 :
V_55 = F_228 ( F_198 () , V_94 ) ;
if ( ! F_49 ( V_55 ) ) {
V_237 = - V_8 ;
break;
}
V_2 -> V_55 = V_55 ;
F_17 ( V_18 , V_2 , L_23 ,
F_229 ( & V_326 , V_2 -> V_55 ) ) ;
break;
case V_327 :
V_57 = F_230 ( F_198 () , V_94 ) ;
if ( ! F_51 ( V_57 ) ) {
V_237 = - V_8 ;
break;
}
V_2 -> V_57 = V_57 ;
F_17 ( V_18 , V_2 , L_24 ,
F_231 ( & V_326 , V_2 -> V_57 ) ) ;
break;
case V_328 :
if ( V_2 -> V_46 -> V_3 & V_174 ) {
F_17 ( V_18 , V_2 ,
L_25 ) ;
V_237 = - V_83 ;
} else {
V_2 -> V_46 -> type = ( int ) V_94 ;
F_17 ( V_18 , V_2 , L_26 ,
V_2 -> V_46 -> type ) ;
V_237 = 0 ;
}
break;
#ifdef F_232
case V_329 :
V_2 -> V_330 = V_94 ;
break;
#endif
case V_331 :
V_237 = F_215 ( V_2 , V_94 ) ;
break;
case V_332 :
V_237 = - V_8 ;
if ( ( V_2 -> V_3 & V_132 ) != V_142 )
break;
V_237 = F_92 ( & V_2 -> V_111 , ( void T_1 * ) V_94 ) ;
break;
case V_333 :
memcpy ( V_274 . V_334 . V_335 , V_2 -> V_46 -> V_336 , V_91 ) ;
V_274 . V_334 . V_337 = V_2 -> V_46 -> type ;
if ( F_226 ( V_5 , & V_274 , V_312 ) )
V_237 = - V_7 ;
break;
case V_338 :
F_17 ( V_339 , V_2 , L_27 ,
V_274 . V_334 . V_335 ) ;
V_237 = F_233 ( V_2 -> V_46 , & V_274 . V_334 ) ;
break;
case V_340 :
V_288 = V_38 -> V_74 . V_63 -> V_289 ;
if ( F_226 ( V_5 , & V_288 , sizeof( V_288 ) ) )
V_237 = - V_7 ;
break;
case V_341 :
if ( F_93 ( & V_288 , V_5 , sizeof( V_288 ) ) ) {
V_237 = - V_7 ;
break;
}
V_2 -> V_288 = V_288 ;
F_220 ( V_2 ) ;
break;
case V_342 :
V_178 = V_2 -> V_178 ;
if ( F_226 ( V_5 , & V_178 , sizeof( V_178 ) ) )
V_237 = - V_7 ;
break;
case V_343 :
if ( F_93 ( & V_178 , V_5 , sizeof( V_178 ) ) ) {
V_237 = - V_7 ;
break;
}
if ( V_178 < ( int ) sizeof( struct V_169 ) ) {
V_237 = - V_8 ;
break;
}
V_2 -> V_178 = V_178 ;
break;
case V_344 :
V_313 = ! ! ( V_2 -> V_3 & V_9 ) ;
if ( F_4 ( V_313 , ( int T_1 * ) V_5 ) )
V_237 = - V_7 ;
break;
case V_345 :
if ( F_6 ( V_313 , ( int T_1 * ) V_5 ) ) {
V_237 = - V_7 ;
break;
}
if ( V_313 )
V_2 -> V_3 |= V_9 ;
else
V_2 -> V_3 &= ~ V_9 ;
break;
case V_346 :
V_237 = F_3 ( V_2 , V_5 ) ;
break;
case V_347 :
V_237 = F_5 ( V_2 , V_5 ) ;
break;
case V_348 :
V_237 = - V_8 ;
if ( ( V_2 -> V_3 & V_132 ) != V_142 )
break;
V_237 = - V_7 ;
if ( F_93 ( & V_2 -> V_88 , V_5 , sizeof( V_2 -> V_88 ) ) )
break;
V_237 = F_219 ( V_2 ) ;
break;
case V_349 :
V_237 = - V_8 ;
if ( ( V_2 -> V_3 & V_132 ) != V_142 )
break;
V_237 = 0 ;
F_217 ( V_2 , V_2 -> V_40 ) ;
break;
case V_350 :
V_237 = - V_8 ;
if ( ( V_2 -> V_3 & V_132 ) != V_142 )
break;
V_237 = - V_7 ;
if ( F_226 ( V_5 , & V_2 -> V_88 , sizeof( V_2 -> V_88 ) ) )
break;
V_237 = 0 ;
break;
default:
V_237 = - V_8 ;
break;
}
V_42:
F_74 () ;
if ( V_2 )
F_87 ( V_2 ) ;
return V_237 ;
}
static long F_234 ( struct V_77 * V_77 ,
unsigned int V_311 , unsigned long V_94 )
{
return F_223 ( V_77 , V_311 , V_94 , sizeof ( struct V_273 ) ) ;
}
static long F_235 ( struct V_77 * V_77 ,
unsigned int V_311 , unsigned long V_94 )
{
switch ( V_311 ) {
case V_314 :
case V_319 :
case V_332 :
case V_340 :
case V_341 :
case V_333 :
case V_338 :
V_94 = ( unsigned long ) F_236 ( V_94 ) ;
break;
default:
V_94 = ( V_351 ) V_94 ;
break;
}
return F_223 ( V_77 , V_311 , V_94 , sizeof( struct V_352 ) ) ;
}
static int F_237 ( int V_353 , struct V_77 * V_77 , int V_354 )
{
struct V_37 * V_38 = V_77 -> V_79 ;
int V_237 ;
if ( ( V_237 = F_238 ( V_353 , V_77 , V_354 , & V_38 -> V_116 ) ) < 0 )
goto V_82;
if ( V_354 ) {
F_239 ( V_77 , F_240 ( V_320 ) , V_355 , 0 ) ;
V_38 -> V_3 |= V_115 ;
} else
V_38 -> V_3 &= ~ V_115 ;
V_237 = 0 ;
V_82:
return V_237 ;
}
static int F_241 ( struct V_356 * V_356 , struct V_77 * V_77 )
{
struct V_54 * V_54 = V_320 -> V_321 -> V_322 ;
struct V_37 * V_38 ;
F_242 ( V_18 , L_28 ) ;
V_38 = (struct V_37 * ) F_243 ( V_54 , V_357 , V_100 ,
& V_358 , 0 ) ;
if ( ! V_38 )
return - V_101 ;
F_67 ( V_38 -> V_2 , NULL ) ;
V_38 -> V_3 = 0 ;
V_38 -> V_285 = 0 ;
F_244 ( & V_38 -> V_359 . V_147 ) ;
F_67 ( V_38 -> V_74 . V_359 , & V_38 -> V_359 ) ;
V_38 -> V_74 . V_77 = V_77 ;
V_38 -> V_74 . V_360 = & V_361 ;
F_245 ( & V_38 -> V_74 , & V_38 -> V_63 ) ;
V_38 -> V_63 . V_362 = F_185 ;
V_38 -> V_63 . V_289 = V_186 ;
V_77 -> V_79 = V_38 ;
F_209 ( & V_38 -> V_60 ) ;
F_246 ( & V_38 -> V_63 , V_363 ) ;
return 0 ;
}
static int F_247 ( struct V_356 * V_356 , struct V_77 * V_77 )
{
struct V_37 * V_38 = V_77 -> V_79 ;
F_72 ( V_38 , true ) ;
return 0 ;
}
static void F_248 ( struct V_364 * V_261 , struct V_77 * V_365 )
{
struct V_1 * V_2 ;
struct V_273 V_274 ;
memset ( & V_274 , 0 , sizeof( V_274 ) ) ;
F_73 () ;
V_2 = F_86 ( V_365 ) ;
if ( V_2 )
F_214 ( V_320 -> V_321 -> V_322 , V_2 , & V_274 ) ;
F_74 () ;
if ( V_2 )
F_87 ( V_2 ) ;
F_249 ( V_261 , L_29 , V_274 . V_275 ) ;
}
static int F_250 ( struct V_45 * V_46 , struct V_366 * V_311 )
{
V_311 -> V_367 = 0 ;
V_311 -> V_368 = 0 ;
F_251 ( V_311 , V_369 ) ;
V_311 -> V_370 = V_371 ;
V_311 -> V_372 = V_373 ;
V_311 -> V_374 = 0 ;
V_311 -> V_375 = V_376 ;
V_311 -> V_377 = V_378 ;
V_311 -> V_379 = 0 ;
V_311 -> V_380 = 0 ;
return 0 ;
}
static void F_252 ( struct V_45 * V_46 , struct V_381 * V_382 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
F_253 ( V_382 -> V_383 , V_384 , sizeof( V_382 -> V_383 ) ) ;
F_253 ( V_382 -> V_385 , V_386 , sizeof( V_382 -> V_385 ) ) ;
switch ( V_2 -> V_3 & V_132 ) {
case V_133 :
F_253 ( V_382 -> V_387 , L_30 , sizeof( V_382 -> V_387 ) ) ;
break;
case V_142 :
F_253 ( V_382 -> V_387 , L_31 , sizeof( V_382 -> V_387 ) ) ;
break;
}
}
static T_4 F_254 ( struct V_45 * V_46 )
{
#ifdef F_232
struct V_1 * V_2 = F_41 ( V_46 ) ;
return V_2 -> V_330 ;
#else
return - V_388 ;
#endif
}
static void F_255 ( struct V_45 * V_46 , T_4 V_389 )
{
#ifdef F_232
struct V_1 * V_2 = F_41 ( V_46 ) ;
V_2 -> V_330 = V_389 ;
#endif
}
static int T_17 F_256 ( void )
{
int V_237 = 0 ;
F_257 ( L_32 , V_390 , V_386 ) ;
F_257 ( L_33 , V_391 ) ;
V_237 = F_258 ( & V_284 ) ;
if ( V_237 ) {
F_166 ( L_34 ) ;
goto V_392;
}
V_237 = F_259 ( & V_393 ) ;
if ( V_237 ) {
F_166 ( L_35 , V_394 ) ;
goto V_395;
}
return 0 ;
V_395:
F_260 ( & V_284 ) ;
V_392:
return V_237 ;
}
static void F_261 ( void )
{
F_262 ( & V_393 ) ;
F_260 ( & V_284 ) ;
}
struct V_74 * F_263 ( struct V_77 * V_77 )
{
struct V_37 * V_38 ;
if ( V_77 -> V_396 != & V_397 )
return F_138 ( - V_8 ) ;
V_38 = V_77 -> V_79 ;
if ( ! V_38 )
return F_138 ( - V_220 ) ;
return & V_38 -> V_74 ;
}
