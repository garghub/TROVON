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
V_80 = F_81 ( & V_2 -> V_88 , V_38 -> V_74 . V_63 ,
F_82 () ) ;
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
F_83 ( & V_38 -> V_63 ) ;
F_54 ( V_2 ) ;
V_82:
return V_80 ;
}
static struct V_1 * F_84 ( struct V_37 * V_38 )
{
struct V_1 * V_2 ;
F_33 () ;
V_2 = F_85 ( V_38 -> V_2 ) ;
if ( V_2 )
F_86 ( V_2 -> V_46 ) ;
F_37 () ;
return V_2 ;
}
static struct V_1 * F_87 ( struct V_77 * V_77 )
{
return F_84 ( V_77 -> V_79 ) ;
}
static void F_88 ( struct V_1 * V_2 )
{
F_89 ( V_2 -> V_46 ) ;
}
static void F_90 ( T_4 * V_89 , const T_6 * V_90 )
{
int V_29 = F_91 ( V_91 , V_90 ) >> 26 ;
V_89 [ V_29 >> 5 ] |= ( 1 << ( V_29 & 31 ) ) ;
}
static unsigned int F_92 ( const T_4 * V_89 , const T_6 * V_90 )
{
int V_29 = F_91 ( V_91 , V_90 ) >> 26 ;
return V_89 [ V_29 >> 5 ] & ( 1 << ( V_29 & 31 ) ) ;
}
static int F_93 ( struct V_92 * V_93 , void T_1 * V_94 )
{
struct { T_6 V_95 [ V_91 ] ; } * V_90 ;
struct V_96 V_97 ;
int V_80 , V_98 , V_29 , V_99 ;
if ( F_94 ( & V_97 , V_94 , sizeof( V_97 ) ) )
return - V_7 ;
if ( ! V_97 . V_34 ) {
V_93 -> V_34 = 0 ;
return 0 ;
}
V_98 = V_91 * V_97 . V_34 ;
V_90 = F_16 ( V_98 , V_100 ) ;
if ( ! V_90 )
return - V_101 ;
if ( F_94 ( V_90 , V_94 + sizeof( V_97 ) , V_98 ) ) {
V_80 = - V_7 ;
goto V_102;
}
V_93 -> V_34 = 0 ;
F_95 () ;
for ( V_29 = 0 ; V_29 < V_97 . V_34 && V_29 < V_103 ; V_29 ++ )
memcpy ( V_93 -> V_90 [ V_29 ] , V_90 [ V_29 ] . V_95 , V_91 ) ;
V_99 = V_29 ;
memset ( V_93 -> V_89 , 0 , sizeof( V_93 -> V_89 ) ) ;
for (; V_29 < V_97 . V_34 ; V_29 ++ ) {
if ( ! F_96 ( V_90 [ V_29 ] . V_95 ) ) {
V_80 = 0 ;
goto V_102;
}
F_90 ( V_93 -> V_89 , V_90 [ V_29 ] . V_95 ) ;
}
if ( ( V_97 . V_3 & V_104 ) )
memset ( V_93 -> V_89 , ~ 0 , sizeof( V_93 -> V_89 ) ) ;
F_95 () ;
V_93 -> V_34 = V_99 ;
V_80 = V_99 ;
V_102:
F_97 ( V_90 ) ;
return V_80 ;
}
static int F_98 ( struct V_92 * V_93 , const struct V_47 * V_48 )
{
struct V_105 * V_106 = (struct V_105 * ) V_48 -> V_30 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_93 -> V_34 ; V_25 ++ )
if ( F_99 ( V_106 -> V_107 , V_93 -> V_90 [ V_25 ] ) )
return 1 ;
if ( F_96 ( V_106 -> V_107 ) )
return F_92 ( V_93 -> V_89 , V_106 -> V_107 ) ;
return 0 ;
}
static int F_100 ( struct V_92 * V_93 , const struct V_47 * V_48 )
{
if ( ! V_93 -> V_34 )
return 1 ;
return F_98 ( V_93 , V_48 ) ;
}
static void F_101 ( struct V_45 * V_46 )
{
F_75 ( V_46 ) ;
}
static int F_102 ( struct V_45 * V_46 )
{
F_103 ( V_46 ) ;
return 0 ;
}
static int F_104 ( struct V_45 * V_46 )
{
F_105 ( V_46 ) ;
return 0 ;
}
static T_7 F_106 ( struct V_47 * V_48 , struct V_45 * V_46 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
int V_51 = V_48 -> V_108 ;
struct V_37 * V_38 ;
T_4 V_40 = 0 ;
F_33 () ;
V_38 = F_85 ( V_2 -> V_69 [ V_51 ] ) ;
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
if ( ! F_100 ( & V_2 -> V_111 , V_48 ) )
goto V_109;
if ( V_38 -> V_74 . V_63 -> V_112 &&
V_112 ( V_38 -> V_74 . V_63 , V_48 ) )
goto V_109;
if ( F_107 ( & V_38 -> V_74 . V_63 -> V_64 ) * V_40
>= V_46 -> V_113 )
goto V_109;
if ( F_39 ( F_108 ( V_48 , V_17 ) ) )
goto V_109;
if ( V_48 -> V_63 && F_109 ( V_48 -> V_63 ) ) {
F_110 ( V_48 -> V_63 , & F_111 ( V_48 ) -> V_114 ) ;
F_112 ( V_48 ) ;
}
F_113 ( V_48 ) ;
F_114 ( V_48 ) ;
F_115 ( & V_38 -> V_74 . V_63 -> V_64 , V_48 ) ;
if ( V_38 -> V_3 & V_115 )
F_116 ( & V_38 -> V_116 , V_117 , V_118 ) ;
V_38 -> V_74 . V_63 -> V_75 ( V_38 -> V_74 . V_63 ) ;
F_37 () ;
return V_119 ;
V_109:
V_46 -> V_120 . V_121 ++ ;
F_117 ( V_48 ) ;
F_118 ( V_48 ) ;
F_37 () ;
return V_122 ;
}
static void F_119 ( struct V_45 * V_46 )
{
}
static int
F_120 ( struct V_45 * V_46 , int V_123 )
{
if ( V_123 < V_124 || V_123 + V_46 -> V_125 > V_126 )
return - V_8 ;
V_46 -> V_127 = V_123 ;
return 0 ;
}
static T_9 F_121 ( struct V_45 * V_46 ,
T_9 V_128 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
return ( V_128 & V_2 -> V_129 ) | ( V_128 & ~ V_130 ) ;
}
static void F_122 ( struct V_45 * V_46 )
{
return;
}
static void F_123 ( struct V_45 * V_46 , int V_131 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
if ( V_131 < V_132 )
V_131 = V_132 ;
V_2 -> V_133 = V_131 ;
}
static void F_124 ( struct V_1 * V_2 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_27 ; V_25 ++ )
F_125 ( & V_2 -> V_39 [ V_25 ] ) ;
V_2 -> V_32 = V_134 ;
F_126 ( & V_2 -> V_36 , F_27 , ( unsigned long ) V_2 ) ;
F_30 ( & V_2 -> V_36 ,
F_31 ( V_20 + V_2 -> V_32 ) ) ;
}
static void F_127 ( struct V_1 * V_2 )
{
F_128 ( & V_2 -> V_36 ) ;
F_22 ( V_2 ) ;
}
static void F_129 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
switch ( V_2 -> V_3 & V_135 ) {
case V_136 :
V_46 -> V_137 = & V_138 ;
V_46 -> V_125 = 0 ;
V_46 -> V_139 = 0 ;
V_46 -> V_127 = 1500 ;
V_46 -> type = V_140 ;
V_46 -> V_3 = V_141 | V_142 | V_143 ;
break;
case V_144 :
V_46 -> V_137 = & V_145 ;
F_130 ( V_46 ) ;
V_46 -> V_146 &= ~ V_147 ;
V_46 -> V_146 |= V_148 ;
F_131 ( V_46 ) ;
break;
}
}
static unsigned int F_132 ( struct V_77 * V_77 , T_10 * V_149 )
{
struct V_37 * V_38 = V_77 -> V_79 ;
struct V_1 * V_2 = F_84 ( V_38 ) ;
struct V_150 * V_63 ;
unsigned int V_89 = 0 ;
if ( ! V_2 )
return V_151 ;
V_63 = V_38 -> V_74 . V_63 ;
F_17 ( V_18 , V_2 , L_5 ) ;
F_133 ( V_77 , F_134 ( V_63 ) , V_149 ) ;
if ( ! F_135 ( & V_63 -> V_64 ) )
V_89 |= V_152 | V_153 ;
if ( F_136 ( V_63 ) ||
( ! F_137 ( V_154 , & V_63 -> V_155 -> V_3 ) &&
F_136 ( V_63 ) ) )
V_89 |= V_156 | V_157 ;
if ( V_2 -> V_46 -> V_71 != V_72 )
V_89 = V_151 ;
F_88 ( V_2 ) ;
return V_89 ;
}
static struct V_47 * F_138 ( struct V_37 * V_38 ,
T_11 V_158 , T_11 V_110 ,
T_11 V_159 , int V_160 )
{
struct V_150 * V_63 = V_38 -> V_74 . V_63 ;
struct V_47 * V_48 ;
int V_80 ;
if ( V_158 + V_110 < V_161 || ! V_159 )
V_159 = V_110 ;
V_48 = F_139 ( V_63 , V_158 + V_159 , V_110 - V_159 , V_160 ,
& V_80 , 0 ) ;
if ( ! V_48 )
return F_140 ( V_80 ) ;
F_141 ( V_48 , V_158 ) ;
F_142 ( V_48 , V_159 ) ;
V_48 -> V_162 = V_110 - V_159 ;
V_48 -> V_110 += V_110 - V_159 ;
return V_48 ;
}
static T_12 F_143 ( struct V_1 * V_2 , struct V_37 * V_38 ,
void * V_163 , struct V_164 * V_165 ,
int V_160 )
{
struct V_166 V_167 = { 0 , F_144 (ETH_P_IP) } ;
struct V_47 * V_48 ;
T_11 V_168 = F_145 ( V_165 ) ;
T_11 V_110 = V_168 , V_133 = V_2 -> V_133 , V_159 ;
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
if ( V_110 < sizeof( V_167 ) )
return - V_8 ;
V_110 -= sizeof( V_167 ) ;
V_29 = F_146 ( & V_167 , sizeof( V_167 ) , V_165 ) ;
if ( V_29 != sizeof( V_167 ) )
return - V_7 ;
}
if ( V_2 -> V_3 & V_177 ) {
if ( V_110 < V_2 -> V_178 )
return - V_8 ;
V_110 -= V_2 -> V_178 ;
V_29 = F_146 ( & V_170 , sizeof( V_170 ) , V_165 ) ;
if ( V_29 != sizeof( V_170 ) )
return - V_7 ;
if ( ( V_170 . V_3 & V_179 ) &&
F_8 ( V_2 , V_170 . V_180 ) + F_8 ( V_2 , V_170 . V_181 ) + 2 > F_8 ( V_2 , V_170 . V_182 ) )
V_170 . V_182 = F_10 ( V_2 , F_8 ( V_2 , V_170 . V_180 ) + F_8 ( V_2 , V_170 . V_181 ) + 2 ) ;
if ( F_8 ( V_2 , V_170 . V_182 ) > V_110 )
return - V_8 ;
F_147 ( V_165 , V_2 -> V_178 - sizeof( V_170 ) ) ;
}
if ( ( V_2 -> V_3 & V_135 ) == V_144 ) {
V_133 += V_183 ;
if ( F_39 ( V_110 < V_184 ||
( V_170 . V_182 && F_8 ( V_2 , V_170 . V_182 ) < V_184 ) ) )
return - V_8 ;
}
V_171 = F_148 ( V_133 ) ;
if ( V_163 ) {
struct V_164 V_25 = * V_165 ;
V_172 = V_170 . V_182 ? F_8 ( V_2 , V_170 . V_182 ) : V_185 ;
if ( V_172 > V_171 )
V_172 = V_171 ;
V_159 = V_172 ;
F_147 ( & V_25 , V_172 ) ;
if ( F_149 ( & V_25 , V_186 ) <= V_187 )
V_173 = true ;
}
if ( ! V_173 ) {
V_172 = V_110 ;
if ( F_8 ( V_2 , V_170 . V_182 ) > V_171 )
V_159 = V_171 ;
else
V_159 = F_8 ( V_2 , V_170 . V_182 ) ;
}
V_48 = F_138 ( V_38 , V_133 , V_172 , V_159 , V_160 ) ;
if ( F_150 ( V_48 ) ) {
if ( F_151 ( V_48 ) != - V_188 )
V_2 -> V_46 -> V_120 . V_189 ++ ;
return F_151 ( V_48 ) ;
}
if ( V_173 )
V_80 = F_152 ( V_48 , V_165 ) ;
else {
V_80 = F_153 ( V_48 , 0 , V_165 , V_110 ) ;
if ( ! V_80 && V_163 ) {
struct V_190 * V_191 = V_163 ;
V_191 -> V_192 ( V_191 , false ) ;
}
}
if ( V_80 ) {
V_2 -> V_46 -> V_120 . V_189 ++ ;
F_118 ( V_48 ) ;
return - V_7 ;
}
if ( V_170 . V_3 & V_179 ) {
if ( ! F_154 ( V_48 , F_8 ( V_2 , V_170 . V_180 ) ,
F_8 ( V_2 , V_170 . V_181 ) ) ) {
V_2 -> V_46 -> V_120 . V_193 ++ ;
F_118 ( V_48 ) ;
return - V_8 ;
}
}
switch ( V_2 -> V_3 & V_135 ) {
case V_136 :
if ( V_2 -> V_3 & V_176 ) {
switch ( V_48 -> V_30 [ 0 ] & 0xf0 ) {
case 0x40 :
V_167 . V_194 = F_155 ( V_195 ) ;
break;
case 0x60 :
V_167 . V_194 = F_155 ( V_196 ) ;
break;
default:
V_2 -> V_46 -> V_120 . V_189 ++ ;
F_118 ( V_48 ) ;
return - V_8 ;
}
}
F_156 ( V_48 ) ;
V_48 -> V_197 = V_167 . V_194 ;
V_48 -> V_46 = V_2 -> V_46 ;
break;
case V_144 :
V_48 -> V_197 = F_157 ( V_48 , V_2 -> V_46 ) ;
break;
}
if ( V_170 . V_198 != V_199 ) {
F_158 ( L_6 ) ;
switch ( V_170 . V_198 & ~ V_200 ) {
case V_201 :
F_111 ( V_48 ) -> V_198 = V_202 ;
break;
case V_203 :
F_111 ( V_48 ) -> V_198 = V_204 ;
break;
case V_205 :
F_111 ( V_48 ) -> V_198 = V_206 ;
break;
default:
V_2 -> V_46 -> V_120 . V_193 ++ ;
F_118 ( V_48 ) ;
return - V_8 ;
}
if ( V_170 . V_198 & V_200 )
F_111 ( V_48 ) -> V_198 |= V_207 ;
F_111 ( V_48 ) -> V_208 = F_8 ( V_2 , V_170 . V_208 ) ;
if ( F_111 ( V_48 ) -> V_208 == 0 ) {
V_2 -> V_46 -> V_120 . V_193 ++ ;
F_118 ( V_48 ) ;
return - V_8 ;
}
F_111 ( V_48 ) -> V_198 |= V_209 ;
F_111 ( V_48 ) -> V_210 = 0 ;
}
if ( V_173 ) {
F_111 ( V_48 ) -> V_211 = V_163 ;
F_111 ( V_48 ) -> V_114 |= V_212 ;
F_111 ( V_48 ) -> V_114 |= V_213 ;
}
F_159 ( V_48 ) ;
F_160 ( V_48 , 0 ) ;
V_11 = F_43 ( V_48 ) ;
F_161 ( V_48 ) ;
V_2 -> V_46 -> V_120 . V_214 ++ ;
V_2 -> V_46 -> V_120 . V_215 += V_110 ;
F_32 ( V_2 , V_11 , V_38 ) ;
return V_168 ;
}
static T_12 F_162 ( struct V_216 * V_217 , struct V_164 * V_165 )
{
struct V_77 * V_77 = V_217 -> V_218 ;
struct V_1 * V_2 = F_87 ( V_77 ) ;
struct V_37 * V_38 = V_77 -> V_79 ;
T_12 V_219 ;
if ( ! V_2 )
return - V_220 ;
V_219 = F_143 ( V_2 , V_38 , NULL , V_165 , V_77 -> V_221 & V_222 ) ;
F_88 ( V_2 ) ;
return V_219 ;
}
static T_12 F_163 ( struct V_1 * V_2 ,
struct V_37 * V_38 ,
struct V_47 * V_48 ,
struct V_164 * V_223 )
{
struct V_166 V_167 = { 0 , V_48 -> V_197 } ;
T_12 V_224 ;
int V_225 = 0 ;
int V_226 = 0 ;
int V_178 = 0 ;
if ( F_164 ( V_48 ) )
V_226 = V_227 ;
if ( V_2 -> V_3 & V_177 )
V_178 = V_2 -> V_178 ;
V_224 = V_48 -> V_110 + V_226 + V_178 ;
if ( ! ( V_2 -> V_3 & V_176 ) ) {
if ( F_145 ( V_223 ) < sizeof( V_167 ) )
return - V_8 ;
V_224 += sizeof( V_167 ) ;
if ( F_145 ( V_223 ) < V_224 ) {
V_167 . V_3 |= V_228 ;
}
if ( F_165 ( & V_167 , sizeof( V_167 ) , V_223 ) != sizeof( V_167 ) )
return - V_7 ;
}
if ( V_178 ) {
struct V_169 V_170 = { 0 } ;
if ( F_145 ( V_223 ) < V_178 )
return - V_8 ;
if ( F_166 ( V_48 ) ) {
struct V_229 * V_230 = F_111 ( V_48 ) ;
V_170 . V_182 = F_10 ( V_2 , F_167 ( V_48 ) ) ;
V_170 . V_208 = F_10 ( V_2 , V_230 -> V_208 ) ;
if ( V_230 -> V_198 & V_202 )
V_170 . V_198 = V_201 ;
else if ( V_230 -> V_198 & V_204 )
V_170 . V_198 = V_203 ;
else if ( V_230 -> V_198 & V_206 )
V_170 . V_198 = V_205 ;
else {
F_168 ( L_7
L_8 ,
V_230 -> V_198 , F_8 ( V_2 , V_170 . V_208 ) ,
F_8 ( V_2 , V_170 . V_182 ) ) ;
F_169 ( V_231 , L_9 ,
V_232 ,
16 , 1 , V_48 -> V_14 ,
F_170 ( ( int ) F_8 ( V_2 , V_170 . V_182 ) , 64 ) , true ) ;
F_171 ( 1 ) ;
return - V_8 ;
}
if ( V_230 -> V_198 & V_207 )
V_170 . V_198 |= V_200 ;
} else
V_170 . V_198 = V_199 ;
if ( V_48 -> V_233 == V_234 ) {
V_170 . V_3 = V_179 ;
V_170 . V_180 = F_10 ( V_2 , F_172 ( V_48 ) +
V_226 ) ;
V_170 . V_181 = F_10 ( V_2 , V_48 -> V_181 ) ;
} else if ( V_48 -> V_233 == V_235 ) {
V_170 . V_3 = V_236 ;
}
if ( F_165 ( & V_170 , sizeof( V_170 ) , V_223 ) != sizeof( V_170 ) )
return - V_7 ;
F_147 ( V_223 , V_178 - sizeof( V_170 ) ) ;
}
if ( V_226 ) {
int V_237 ;
struct {
T_13 V_238 ;
T_13 V_239 ;
} V_240 ;
V_240 . V_238 = V_48 -> V_241 ;
V_240 . V_239 = F_155 ( F_173 ( V_48 ) ) ;
V_225 = F_174 ( struct V_242 , V_238 ) ;
V_237 = F_175 ( V_48 , 0 , V_223 , V_225 ) ;
if ( V_237 || ! F_145 ( V_223 ) )
goto V_102;
V_237 = F_165 ( & V_240 , sizeof( V_240 ) , V_223 ) ;
if ( V_237 != sizeof( V_240 ) || ! F_145 ( V_223 ) )
goto V_102;
}
F_175 ( V_48 , V_225 , V_223 , V_48 -> V_110 - V_225 ) ;
V_102:
V_2 -> V_46 -> V_120 . V_243 ++ ;
V_2 -> V_46 -> V_120 . V_244 += V_48 -> V_110 + V_226 ;
return V_224 ;
}
static T_12 F_176 ( struct V_1 * V_2 , struct V_37 * V_38 ,
struct V_164 * V_245 ,
int V_160 )
{
struct V_47 * V_48 ;
T_12 V_237 ;
int V_246 , V_80 , V_247 = 0 ;
F_17 ( V_18 , V_2 , L_10 ) ;
if ( ! F_145 ( V_245 ) )
return 0 ;
if ( V_2 -> V_46 -> V_71 != V_72 )
return - V_175 ;
V_48 = F_177 ( V_38 -> V_74 . V_63 , V_160 ? V_248 : 0 ,
& V_246 , & V_247 , & V_80 ) ;
if ( ! V_48 )
return V_80 ;
V_237 = F_163 ( V_2 , V_38 , V_48 , V_245 ) ;
if ( F_39 ( V_237 < 0 ) )
F_118 ( V_48 ) ;
else
F_178 ( V_48 ) ;
return V_237 ;
}
static T_12 F_179 ( struct V_216 * V_217 , struct V_164 * V_245 )
{
struct V_77 * V_77 = V_217 -> V_218 ;
struct V_37 * V_38 = V_77 -> V_79 ;
struct V_1 * V_2 = F_84 ( V_38 ) ;
T_12 V_110 = F_145 ( V_245 ) , V_237 ;
if ( ! V_2 )
return - V_220 ;
V_237 = F_176 ( V_2 , V_38 , V_245 , V_77 -> V_221 & V_222 ) ;
V_237 = F_180 ( T_12 , V_237 , V_110 ) ;
if ( V_237 > 0 )
V_217 -> V_249 = V_237 ;
F_88 ( V_2 ) ;
return V_237 ;
}
static void F_181 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
F_65 ( ! ( F_182 ( & V_2 -> V_61 ) ) ) ;
F_127 ( V_2 ) ;
F_183 ( V_2 -> V_81 ) ;
F_184 ( V_46 ) ;
}
static void F_185 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
V_2 -> V_55 = V_250 ;
V_2 -> V_57 = V_251 ;
V_46 -> V_252 = & V_253 ;
V_46 -> V_254 = F_181 ;
V_46 -> V_113 = V_255 ;
}
static int F_186 ( struct V_256 * V_257 [] , struct V_256 * V_30 [] )
{
return - V_8 ;
}
static void F_187 ( struct V_150 * V_63 )
{
struct V_37 * V_38 ;
T_14 * V_258 ;
if ( ! F_136 ( V_63 ) )
return;
if ( ! F_188 ( V_154 , & V_63 -> V_155 -> V_3 ) )
return;
V_258 = F_134 ( V_63 ) ;
if ( V_258 && F_189 ( V_258 ) )
F_190 ( V_258 , V_156 |
V_157 | V_259 ) ;
V_38 = F_191 ( V_63 , struct V_37 , V_63 ) ;
F_116 ( & V_38 -> V_116 , V_117 , V_260 ) ;
}
static int F_192 ( struct V_74 * V_150 , struct V_261 * V_262 , T_11 V_168 )
{
int V_237 ;
struct V_37 * V_38 = F_191 ( V_150 , struct V_37 , V_74 ) ;
struct V_1 * V_2 = F_84 ( V_38 ) ;
if ( ! V_2 )
return - V_220 ;
V_237 = F_143 ( V_2 , V_38 , V_262 -> V_163 , & V_262 -> V_263 ,
V_262 -> V_264 & V_248 ) ;
F_88 ( V_2 ) ;
return V_237 ;
}
static int F_193 ( struct V_74 * V_150 , struct V_261 * V_262 , T_11 V_168 ,
int V_3 )
{
struct V_37 * V_38 = F_191 ( V_150 , struct V_37 , V_74 ) ;
struct V_1 * V_2 = F_84 ( V_38 ) ;
int V_237 ;
if ( ! V_2 )
return - V_220 ;
if ( V_3 & ~ ( V_248 | V_265 | V_266 ) ) {
V_237 = - V_8 ;
goto V_82;
}
if ( V_3 & V_266 ) {
V_237 = F_194 ( V_150 -> V_63 , V_262 , V_168 ,
V_267 , V_268 ) ;
goto V_82;
}
V_237 = F_176 ( V_2 , V_38 , & V_262 -> V_263 , V_3 & V_248 ) ;
if ( V_237 > ( T_12 ) V_168 ) {
V_262 -> V_264 |= V_265 ;
V_237 = V_3 & V_265 ? V_237 : V_168 ;
}
V_82:
F_88 ( V_2 ) ;
return V_237 ;
}
static int F_195 ( struct V_1 * V_2 )
{
return V_2 -> V_3 & ( V_269 | V_70 | V_136 | V_144 ) ;
}
static T_12 F_196 ( struct V_270 * V_46 , struct V_271 * V_272 ,
char * V_273 )
{
struct V_1 * V_2 = F_41 ( F_197 ( V_46 ) ) ;
return sprintf ( V_273 , L_11 , F_195 ( V_2 ) ) ;
}
static T_12 F_198 ( struct V_270 * V_46 , struct V_271 * V_272 ,
char * V_273 )
{
struct V_1 * V_2 = F_41 ( F_197 ( V_46 ) ) ;
return F_49 ( V_2 -> V_55 ) ?
sprintf ( V_273 , L_12 ,
F_199 ( F_200 () , V_2 -> V_55 ) ) :
sprintf ( V_273 , L_13 ) ;
}
static T_12 F_201 ( struct V_270 * V_46 , struct V_271 * V_272 ,
char * V_273 )
{
struct V_1 * V_2 = F_41 ( F_197 ( V_46 ) ) ;
return F_51 ( V_2 -> V_57 ) ?
sprintf ( V_273 , L_12 ,
F_202 ( F_200 () , V_2 -> V_57 ) ) :
sprintf ( V_273 , L_13 ) ;
}
static int F_203 ( struct V_54 * V_54 , struct V_77 * V_77 , struct V_274 * V_275 )
{
struct V_1 * V_2 ;
struct V_37 * V_38 = V_77 -> V_79 ;
struct V_45 * V_46 ;
int V_80 ;
if ( V_38 -> V_41 )
return - V_8 ;
V_46 = F_204 ( V_54 , V_275 -> V_276 ) ;
if ( V_46 ) {
if ( V_275 -> V_277 & V_278 )
return - V_83 ;
if ( ( V_275 -> V_277 & V_136 ) && V_46 -> V_137 == & V_138 )
V_2 = F_41 ( V_46 ) ;
else if ( ( V_275 -> V_277 & V_144 ) && V_46 -> V_137 == & V_145 )
V_2 = F_41 ( V_46 ) ;
else
return - V_8 ;
if ( ! ! ( V_275 -> V_277 & V_84 ) !=
! ! ( V_2 -> V_3 & V_84 ) )
return - V_8 ;
if ( F_46 ( V_2 ) )
return - V_279 ;
V_80 = F_205 ( V_2 -> V_81 ) ;
if ( V_80 < 0 )
return V_80 ;
V_80 = F_79 ( V_2 , V_77 , V_275 -> V_277 & V_280 ) ;
if ( V_80 < 0 )
return V_80 ;
if ( V_2 -> V_3 & V_84 &&
( V_2 -> V_40 + V_2 -> V_62 > 1 ) ) {
return 0 ;
}
}
else {
char * V_281 ;
unsigned long V_3 = 0 ;
int V_282 = V_275 -> V_277 & V_84 ?
V_86 : 1 ;
if ( ! F_53 ( V_54 -> V_58 , V_59 ) )
return - V_279 ;
V_80 = F_206 () ;
if ( V_80 < 0 )
return V_80 ;
if ( V_275 -> V_277 & V_136 ) {
V_3 |= V_136 ;
V_281 = L_14 ;
} else if ( V_275 -> V_277 & V_144 ) {
V_3 |= V_144 ;
V_281 = L_15 ;
} else
return - V_8 ;
if ( * V_275 -> V_276 )
V_281 = V_275 -> V_276 ;
V_46 = F_207 ( sizeof( struct V_1 ) , V_281 ,
V_283 , F_185 , V_282 ,
V_282 ) ;
if ( ! V_46 )
return - V_101 ;
F_208 ( V_46 , V_54 ) ;
V_46 -> V_284 = & V_285 ;
V_46 -> V_286 = V_38 -> V_286 ;
V_46 -> V_287 [ 0 ] = & V_288 ;
V_2 = F_41 ( V_46 ) ;
V_2 -> V_46 = V_46 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_111 . V_34 = 0 ;
V_2 -> V_178 = sizeof( struct V_169 ) ;
V_2 -> V_133 = V_132 ;
V_2 -> V_87 = false ;
V_2 -> V_289 = V_38 -> V_74 . V_63 -> V_290 ;
F_209 ( & V_2 -> V_26 ) ;
V_80 = F_210 ( & V_2 -> V_81 ) ;
if ( V_80 < 0 )
goto V_291;
F_129 ( V_46 ) ;
F_124 ( V_2 ) ;
V_46 -> V_292 = V_293 | V_294 |
V_130 | V_295 |
V_296 ;
V_46 -> V_128 = V_46 -> V_292 ;
V_46 -> V_297 = V_46 -> V_128 &
~ ( V_295 |
V_296 ) ;
F_211 ( & V_2 -> V_61 ) ;
V_80 = F_79 ( V_2 , V_77 , false ) ;
if ( V_80 < 0 )
goto V_298;
V_80 = F_212 ( V_2 -> V_46 ) ;
if ( V_80 < 0 )
goto V_299;
}
F_213 ( V_2 -> V_46 ) ;
F_17 ( V_18 , V_2 , L_16 ) ;
V_2 -> V_3 = ( V_2 -> V_3 & ~ V_269 ) |
( V_275 -> V_277 & V_269 ) ;
if ( F_214 ( V_2 -> V_46 ) )
F_215 ( V_2 -> V_46 ) ;
strcpy ( V_275 -> V_276 , V_2 -> V_46 -> V_281 ) ;
return 0 ;
V_299:
F_75 ( V_46 ) ;
V_298:
F_127 ( V_2 ) ;
F_183 ( V_2 -> V_81 ) ;
V_291:
F_184 ( V_46 ) ;
return V_80 ;
}
static void F_216 ( struct V_54 * V_54 , struct V_1 * V_2 ,
struct V_274 * V_275 )
{
F_17 ( V_18 , V_2 , L_17 ) ;
strcpy ( V_275 -> V_276 , V_2 -> V_46 -> V_281 ) ;
V_275 -> V_277 = F_195 ( V_2 ) ;
}
static int F_217 ( struct V_1 * V_2 , unsigned long V_94 )
{
T_9 V_128 = 0 ;
if ( V_94 & V_300 ) {
V_128 |= V_301 ;
V_94 &= ~ V_300 ;
if ( V_94 & ( V_302 | V_303 ) ) {
if ( V_94 & V_304 ) {
V_128 |= V_305 ;
V_94 &= ~ V_304 ;
}
if ( V_94 & V_302 )
V_128 |= V_306 ;
if ( V_94 & V_303 )
V_128 |= V_307 ;
V_94 &= ~ ( V_302 | V_303 ) ;
}
if ( V_94 & V_308 ) {
V_128 |= V_309 ;
V_94 &= ~ V_308 ;
}
}
if ( V_94 )
return - V_8 ;
V_2 -> V_129 = V_128 ;
F_218 ( V_2 -> V_46 ) ;
return 0 ;
}
static void F_219 ( struct V_1 * V_2 , int V_29 )
{
int V_25 ;
struct V_37 * V_38 ;
for ( V_25 = 0 ; V_25 < V_29 ; V_25 ++ ) {
V_38 = F_64 ( V_2 -> V_69 [ V_25 ] ) ;
F_220 ( V_38 -> V_74 . V_63 , F_82 () ) ;
}
V_2 -> V_87 = false ;
}
static int F_221 ( struct V_1 * V_2 )
{
int V_25 , V_237 = 0 ;
struct V_37 * V_38 ;
for ( V_25 = 0 ; V_25 < V_2 -> V_40 ; V_25 ++ ) {
V_38 = F_64 ( V_2 -> V_69 [ V_25 ] ) ;
V_237 = F_81 ( & V_2 -> V_88 , V_38 -> V_74 . V_63 ,
F_82 () ) ;
if ( V_237 ) {
F_219 ( V_2 , V_25 ) ;
return V_237 ;
}
}
V_2 -> V_87 = true ;
return V_237 ;
}
static void F_222 ( struct V_1 * V_2 )
{
struct V_37 * V_38 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_2 -> V_40 ; V_25 ++ ) {
V_38 = F_64 ( V_2 -> V_69 [ V_25 ] ) ;
V_38 -> V_74 . V_63 -> V_290 = V_2 -> V_289 ;
}
}
static int F_223 ( struct V_77 * V_77 , struct V_274 * V_275 )
{
struct V_37 * V_38 = V_77 -> V_79 ;
struct V_1 * V_2 ;
int V_237 = 0 ;
F_73 () ;
if ( V_275 -> V_277 & V_310 ) {
V_2 = V_38 -> V_41 ;
if ( ! V_2 ) {
V_237 = - V_8 ;
goto V_42;
}
V_237 = F_224 ( V_2 -> V_81 ) ;
if ( V_237 < 0 )
goto V_42;
V_237 = F_79 ( V_2 , V_77 , false ) ;
} else if ( V_275 -> V_277 & V_311 ) {
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
static long F_225 ( struct V_77 * V_77 , unsigned int V_312 ,
unsigned long V_94 , int V_313 )
{
struct V_37 * V_38 = V_77 -> V_79 ;
struct V_1 * V_2 ;
void T_1 * V_5 = ( void T_1 * ) V_94 ;
struct V_274 V_275 ;
T_15 V_55 ;
T_16 V_57 ;
int V_289 ;
int V_178 ;
unsigned int V_286 ;
int V_314 ;
int V_237 ;
if ( V_312 == V_315 || V_312 == V_316 || F_226 ( V_312 ) == 0x89 ) {
if ( F_94 ( & V_275 , V_5 , V_313 ) )
return - V_7 ;
} else {
memset ( & V_275 , 0 , sizeof( V_275 ) ) ;
}
if ( V_312 == V_317 ) {
return F_4 ( V_136 | V_144 | V_269 ,
( unsigned int T_1 * ) V_5 ) ;
} else if ( V_312 == V_316 )
return F_223 ( V_77 , & V_275 ) ;
V_237 = 0 ;
F_73 () ;
V_2 = F_84 ( V_38 ) ;
if ( V_312 == V_315 && ! V_2 ) {
V_275 . V_276 [ V_318 - 1 ] = '\0' ;
V_237 = F_203 ( F_227 ( & V_38 -> V_63 ) , V_77 , & V_275 ) ;
if ( V_237 )
goto V_42;
if ( F_228 ( V_5 , & V_275 , V_313 ) )
V_237 = - V_7 ;
goto V_42;
}
if ( V_312 == V_319 ) {
V_237 = - V_279 ;
if ( V_2 )
goto V_42;
V_237 = - V_7 ;
if ( F_94 ( & V_286 , V_5 , sizeof( V_286 ) ) )
goto V_42;
V_237 = 0 ;
V_38 -> V_286 = V_286 ;
goto V_42;
}
V_237 = - V_220 ;
if ( ! V_2 )
goto V_42;
F_17 ( V_18 , V_2 , L_18 , V_312 ) ;
V_237 = 0 ;
switch ( V_312 ) {
case V_320 :
F_216 ( V_321 -> V_322 -> V_323 , V_2 , & V_275 ) ;
if ( V_38 -> V_41 )
V_275 . V_277 |= V_311 ;
if ( ! V_38 -> V_74 . V_63 -> V_112 )
V_275 . V_277 |= V_280 ;
if ( F_228 ( V_5 , & V_275 , V_313 ) )
V_237 = - V_7 ;
break;
case V_324 :
F_17 ( V_18 , V_2 , L_19 ,
V_94 ? L_20 : L_21 ) ;
break;
case V_325 :
if ( V_94 && ! ( V_2 -> V_3 & V_70 ) ) {
V_2 -> V_3 |= V_70 ;
F_229 ( V_76 ) ;
}
if ( ! V_94 && ( V_2 -> V_3 & V_70 ) ) {
V_2 -> V_3 &= ~ V_70 ;
F_78 ( V_76 ) ;
}
F_17 ( V_18 , V_2 , L_22 ,
V_94 ? L_21 : L_20 ) ;
break;
case V_326 :
V_55 = F_230 ( F_200 () , V_94 ) ;
if ( ! F_49 ( V_55 ) ) {
V_237 = - V_8 ;
break;
}
V_2 -> V_55 = V_55 ;
F_17 ( V_18 , V_2 , L_23 ,
F_231 ( & V_327 , V_2 -> V_55 ) ) ;
break;
case V_328 :
V_57 = F_232 ( F_200 () , V_94 ) ;
if ( ! F_51 ( V_57 ) ) {
V_237 = - V_8 ;
break;
}
V_2 -> V_57 = V_57 ;
F_17 ( V_18 , V_2 , L_24 ,
F_233 ( & V_327 , V_2 -> V_57 ) ) ;
break;
case V_329 :
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
#ifdef F_234
case V_330 :
V_2 -> V_331 = V_94 ;
break;
#endif
case V_332 :
V_237 = F_217 ( V_2 , V_94 ) ;
break;
case V_333 :
V_237 = - V_8 ;
if ( ( V_2 -> V_3 & V_135 ) != V_144 )
break;
V_237 = F_93 ( & V_2 -> V_111 , ( void T_1 * ) V_94 ) ;
break;
case V_334 :
memcpy ( V_275 . V_335 . V_336 , V_2 -> V_46 -> V_337 , V_91 ) ;
V_275 . V_335 . V_338 = V_2 -> V_46 -> type ;
if ( F_228 ( V_5 , & V_275 , V_313 ) )
V_237 = - V_7 ;
break;
case V_339 :
F_17 ( V_340 , V_2 , L_27 ,
V_275 . V_335 . V_336 ) ;
V_237 = F_235 ( V_2 -> V_46 , & V_275 . V_335 ) ;
break;
case V_341 :
V_289 = V_38 -> V_74 . V_63 -> V_290 ;
if ( F_228 ( V_5 , & V_289 , sizeof( V_289 ) ) )
V_237 = - V_7 ;
break;
case V_342 :
if ( F_94 ( & V_289 , V_5 , sizeof( V_289 ) ) ) {
V_237 = - V_7 ;
break;
}
V_2 -> V_289 = V_289 ;
F_222 ( V_2 ) ;
break;
case V_343 :
V_178 = V_2 -> V_178 ;
if ( F_228 ( V_5 , & V_178 , sizeof( V_178 ) ) )
V_237 = - V_7 ;
break;
case V_344 :
if ( F_94 ( & V_178 , V_5 , sizeof( V_178 ) ) ) {
V_237 = - V_7 ;
break;
}
if ( V_178 < ( int ) sizeof( struct V_169 ) ) {
V_237 = - V_8 ;
break;
}
V_2 -> V_178 = V_178 ;
break;
case V_345 :
V_314 = ! ! ( V_2 -> V_3 & V_9 ) ;
if ( F_4 ( V_314 , ( int T_1 * ) V_5 ) )
V_237 = - V_7 ;
break;
case V_346 :
if ( F_6 ( V_314 , ( int T_1 * ) V_5 ) ) {
V_237 = - V_7 ;
break;
}
if ( V_314 )
V_2 -> V_3 |= V_9 ;
else
V_2 -> V_3 &= ~ V_9 ;
break;
case V_347 :
V_237 = F_3 ( V_2 , V_5 ) ;
break;
case V_348 :
V_237 = F_5 ( V_2 , V_5 ) ;
break;
case V_349 :
V_237 = - V_8 ;
if ( ( V_2 -> V_3 & V_135 ) != V_144 )
break;
V_237 = - V_7 ;
if ( F_94 ( & V_2 -> V_88 , V_5 , sizeof( V_2 -> V_88 ) ) )
break;
V_237 = F_221 ( V_2 ) ;
break;
case V_350 :
V_237 = - V_8 ;
if ( ( V_2 -> V_3 & V_135 ) != V_144 )
break;
V_237 = 0 ;
F_219 ( V_2 , V_2 -> V_40 ) ;
break;
case V_351 :
V_237 = - V_8 ;
if ( ( V_2 -> V_3 & V_135 ) != V_144 )
break;
V_237 = - V_7 ;
if ( F_228 ( V_5 , & V_2 -> V_88 , sizeof( V_2 -> V_88 ) ) )
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
F_88 ( V_2 ) ;
return V_237 ;
}
static long F_236 ( struct V_77 * V_77 ,
unsigned int V_312 , unsigned long V_94 )
{
return F_225 ( V_77 , V_312 , V_94 , sizeof ( struct V_274 ) ) ;
}
static long F_237 ( struct V_77 * V_77 ,
unsigned int V_312 , unsigned long V_94 )
{
switch ( V_312 ) {
case V_315 :
case V_320 :
case V_333 :
case V_341 :
case V_342 :
case V_334 :
case V_339 :
V_94 = ( unsigned long ) F_238 ( V_94 ) ;
break;
default:
V_94 = ( V_352 ) V_94 ;
break;
}
return F_225 ( V_77 , V_312 , V_94 , sizeof( struct V_353 ) ) ;
}
static int F_239 ( int V_354 , struct V_77 * V_77 , int V_355 )
{
struct V_37 * V_38 = V_77 -> V_79 ;
int V_237 ;
if ( ( V_237 = F_240 ( V_354 , V_77 , V_355 , & V_38 -> V_116 ) ) < 0 )
goto V_82;
if ( V_355 ) {
F_241 ( V_77 , F_242 ( V_321 ) , V_356 , 0 ) ;
V_38 -> V_3 |= V_115 ;
} else
V_38 -> V_3 &= ~ V_115 ;
V_237 = 0 ;
V_82:
return V_237 ;
}
static int F_243 ( struct V_357 * V_357 , struct V_77 * V_77 )
{
struct V_54 * V_54 = V_321 -> V_322 -> V_323 ;
struct V_37 * V_38 ;
F_244 ( V_18 , L_28 ) ;
V_38 = (struct V_37 * ) F_245 ( V_54 , V_358 , V_100 ,
& V_359 , 0 ) ;
if ( ! V_38 )
return - V_101 ;
F_67 ( V_38 -> V_2 , NULL ) ;
V_38 -> V_3 = 0 ;
V_38 -> V_286 = 0 ;
F_246 ( & V_38 -> V_360 . V_149 ) ;
F_67 ( V_38 -> V_74 . V_360 , & V_38 -> V_360 ) ;
V_38 -> V_74 . V_77 = V_77 ;
V_38 -> V_74 . V_361 = & V_362 ;
F_247 ( & V_38 -> V_74 , & V_38 -> V_63 ) ;
V_38 -> V_63 . V_363 = F_187 ;
V_38 -> V_63 . V_290 = V_186 ;
V_77 -> V_79 = V_38 ;
F_211 ( & V_38 -> V_60 ) ;
F_248 ( & V_38 -> V_63 , V_364 ) ;
return 0 ;
}
static int F_249 ( struct V_357 * V_357 , struct V_77 * V_77 )
{
struct V_37 * V_38 = V_77 -> V_79 ;
F_72 ( V_38 , true ) ;
return 0 ;
}
static void F_250 ( struct V_365 * V_262 , struct V_77 * V_366 )
{
struct V_1 * V_2 ;
struct V_274 V_275 ;
memset ( & V_275 , 0 , sizeof( V_275 ) ) ;
F_73 () ;
V_2 = F_87 ( V_366 ) ;
if ( V_2 )
F_216 ( V_321 -> V_322 -> V_323 , V_2 , & V_275 ) ;
F_74 () ;
if ( V_2 )
F_88 ( V_2 ) ;
F_251 ( V_262 , L_29 , V_275 . V_276 ) ;
}
static int F_252 ( struct V_45 * V_46 , struct V_367 * V_312 )
{
V_312 -> V_368 = 0 ;
V_312 -> V_369 = 0 ;
F_253 ( V_312 , V_370 ) ;
V_312 -> V_371 = V_372 ;
V_312 -> V_373 = V_374 ;
V_312 -> V_375 = 0 ;
V_312 -> V_376 = V_377 ;
V_312 -> V_378 = V_379 ;
V_312 -> V_380 = 0 ;
V_312 -> V_381 = 0 ;
return 0 ;
}
static void F_254 ( struct V_45 * V_46 , struct V_382 * V_383 )
{
struct V_1 * V_2 = F_41 ( V_46 ) ;
F_255 ( V_383 -> V_384 , V_385 , sizeof( V_383 -> V_384 ) ) ;
F_255 ( V_383 -> V_386 , V_387 , sizeof( V_383 -> V_386 ) ) ;
switch ( V_2 -> V_3 & V_135 ) {
case V_136 :
F_255 ( V_383 -> V_388 , L_30 , sizeof( V_383 -> V_388 ) ) ;
break;
case V_144 :
F_255 ( V_383 -> V_388 , L_31 , sizeof( V_383 -> V_388 ) ) ;
break;
}
}
static T_4 F_256 ( struct V_45 * V_46 )
{
#ifdef F_234
struct V_1 * V_2 = F_41 ( V_46 ) ;
return V_2 -> V_331 ;
#else
return - V_389 ;
#endif
}
static void F_257 ( struct V_45 * V_46 , T_4 V_390 )
{
#ifdef F_234
struct V_1 * V_2 = F_41 ( V_46 ) ;
V_2 -> V_331 = V_390 ;
#endif
}
static int T_17 F_258 ( void )
{
int V_237 = 0 ;
F_259 ( L_32 , V_391 , V_387 ) ;
F_259 ( L_33 , V_392 ) ;
V_237 = F_260 ( & V_285 ) ;
if ( V_237 ) {
F_168 ( L_34 ) ;
goto V_393;
}
V_237 = F_261 ( & V_394 ) ;
if ( V_237 ) {
F_168 ( L_35 , V_395 ) ;
goto V_396;
}
return 0 ;
V_396:
F_262 ( & V_285 ) ;
V_393:
return V_237 ;
}
static void F_263 ( void )
{
F_264 ( & V_394 ) ;
F_262 ( & V_285 ) ;
}
struct V_74 * F_265 ( struct V_77 * V_77 )
{
struct V_37 * V_38 ;
if ( V_77 -> V_397 != & V_398 )
return F_140 ( - V_8 ) ;
V_38 = V_77 -> V_79 ;
if ( ! V_38 )
return F_140 ( - V_220 ) ;
return & V_38 -> V_74 ;
}
