static inline T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
return F_2 ( V_2 -> V_4 & V_5 , V_3 ) ;
}
static inline T_2 F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_4 ( V_2 -> V_4 & V_5 , V_3 ) ;
}
static inline T_3 F_5 ( T_3 V_6 )
{
return V_6 & 0x3ff ;
}
static struct V_7 * F_6 ( struct V_8 * V_9 , T_3 V_6 )
{
struct V_7 * V_10 ;
F_7 (e, head, hash_link) {
if ( V_10 -> V_6 == V_6 )
return V_10 ;
}
return NULL ;
}
static struct V_7 * F_8 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
T_3 V_6 , T_1 V_11 )
{
struct V_7 * V_10 = F_9 ( sizeof( * V_10 ) , V_12 ) ;
if ( V_10 ) {
F_10 ( V_13 , V_2 , L_1 ,
V_6 , V_11 ) ;
V_10 -> V_14 = V_15 ;
V_10 -> V_6 = V_6 ;
V_10 -> V_16 = 0 ;
V_10 -> V_11 = V_11 ;
V_10 -> V_2 = V_2 ;
F_11 ( & V_10 -> V_17 , V_9 ) ;
++ V_2 -> V_18 ;
}
return V_10 ;
}
static void F_12 ( struct V_1 * V_2 , struct V_7 * V_10 )
{
F_10 ( V_13 , V_2 , L_2 ,
V_10 -> V_6 , V_10 -> V_11 ) ;
F_13 ( & V_10 -> V_17 ) ;
F_14 ( V_10 , V_19 ) ;
-- V_2 -> V_18 ;
}
static void F_15 ( struct V_1 * V_2 )
{
int V_20 ;
F_16 ( & V_2 -> V_21 ) ;
for ( V_20 = 0 ; V_20 < V_22 ; V_20 ++ ) {
struct V_7 * V_10 ;
struct V_23 * V_24 ;
F_17 (e, n, &tun->flows[i], hash_link)
F_12 ( V_2 , V_10 ) ;
}
F_18 ( & V_2 -> V_21 ) ;
}
static void F_19 ( struct V_1 * V_2 , T_1 V_11 )
{
int V_20 ;
F_16 ( & V_2 -> V_21 ) ;
for ( V_20 = 0 ; V_20 < V_22 ; V_20 ++ ) {
struct V_7 * V_10 ;
struct V_23 * V_24 ;
F_17 (e, n, &tun->flows[i], hash_link) {
if ( V_10 -> V_11 == V_11 )
F_12 ( V_2 , V_10 ) ;
}
}
F_18 ( & V_2 -> V_21 ) ;
}
static void F_20 ( unsigned long V_25 )
{
struct V_1 * V_2 = (struct V_1 * ) V_25 ;
unsigned long V_26 = V_2 -> V_27 ;
unsigned long V_28 = V_15 + V_26 ;
unsigned long V_29 = 0 ;
int V_20 ;
F_10 ( V_13 , V_2 , L_3 ) ;
F_16 ( & V_2 -> V_21 ) ;
for ( V_20 = 0 ; V_20 < V_22 ; V_20 ++ ) {
struct V_7 * V_10 ;
struct V_23 * V_24 ;
F_17 (e, n, &tun->flows[i], hash_link) {
unsigned long V_30 ;
V_29 ++ ;
V_30 = V_10 -> V_14 + V_26 ;
if ( F_21 ( V_30 , V_15 ) )
F_12 ( V_2 , V_10 ) ;
else if ( F_22 ( V_30 , V_28 ) )
V_28 = V_30 ;
}
}
if ( V_29 )
F_23 ( & V_2 -> V_31 , F_24 ( V_28 ) ) ;
F_18 ( & V_2 -> V_21 ) ;
}
static void F_25 ( struct V_1 * V_2 , T_3 V_6 ,
struct V_32 * V_33 )
{
struct V_8 * V_9 ;
struct V_7 * V_10 ;
unsigned long V_26 = V_2 -> V_27 ;
T_1 V_11 = V_33 -> V_11 ;
if ( ! V_6 )
return;
else
V_9 = & V_2 -> V_34 [ F_5 ( V_6 ) ] ;
F_26 () ;
if ( V_2 -> V_35 == 1 || V_33 -> V_36 )
goto V_37;
V_10 = F_6 ( V_9 , V_6 ) ;
if ( F_27 ( V_10 ) ) {
V_10 -> V_11 = V_11 ;
V_10 -> V_14 = V_15 ;
F_28 ( V_10 -> V_16 ) ;
} else {
F_16 ( & V_2 -> V_21 ) ;
if ( ! F_6 ( V_9 , V_6 ) &&
V_2 -> V_18 < V_38 )
F_8 ( V_2 , V_9 , V_6 , V_11 ) ;
if ( ! F_29 ( & V_2 -> V_31 ) )
F_23 ( & V_2 -> V_31 ,
F_24 ( V_15 + V_26 ) ) ;
F_18 ( & V_2 -> V_21 ) ;
}
V_37:
F_30 () ;
}
static inline void F_31 ( struct V_7 * V_10 , T_3 V_39 )
{
if ( F_32 ( V_10 -> V_16 != V_39 ) )
V_10 -> V_16 = V_39 ;
}
static T_1 F_33 ( struct V_40 * V_41 , struct V_42 * V_43 ,
void * V_44 , T_4 V_45 )
{
struct V_1 * V_2 = F_34 ( V_41 ) ;
struct V_7 * V_10 ;
T_3 V_46 = 0 ;
T_3 V_35 = 0 ;
F_26 () ;
V_35 = F_35 ( V_2 -> V_35 ) ;
V_46 = F_36 ( V_43 ) ;
if ( V_46 ) {
V_10 = F_6 ( & V_2 -> V_34 [ F_5 ( V_46 ) ] , V_46 ) ;
if ( V_10 ) {
F_31 ( V_10 , V_46 ) ;
V_46 = V_10 -> V_11 ;
} else
V_46 = ( ( V_47 ) V_46 * V_35 ) >> 32 ;
} else if ( F_27 ( F_37 ( V_43 ) ) ) {
V_46 = F_38 ( V_43 ) ;
while ( F_32 ( V_46 >= V_35 ) )
V_46 -= V_35 ;
}
F_30 () ;
return V_46 ;
}
static inline bool F_39 ( struct V_1 * V_2 )
{
const struct V_48 * V_48 = F_40 () ;
struct V_49 * V_49 = F_41 ( V_2 -> V_41 ) ;
return ( ( F_42 ( V_2 -> V_50 ) && ! F_43 ( V_48 -> V_51 , V_2 -> V_50 ) ) ||
( F_44 ( V_2 -> V_52 ) && ! F_45 ( V_2 -> V_52 ) ) ) &&
! F_46 ( V_49 -> V_53 , V_54 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
F_48 ( V_2 -> V_41 , V_2 -> V_35 ) ;
F_49 ( V_2 -> V_41 , V_2 -> V_35 ) ;
}
static void F_50 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
V_33 -> V_36 = V_2 ;
F_51 ( & V_33 -> V_55 , & V_2 -> V_56 ) ;
++ V_2 -> V_57 ;
}
static struct V_1 * F_52 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_36 ;
V_33 -> V_36 = NULL ;
F_53 ( & V_33 -> V_55 ) ;
-- V_2 -> V_57 ;
return V_2 ;
}
static void F_54 ( struct V_32 * V_33 )
{
F_55 ( & V_33 -> V_58 . V_59 ) ;
F_55 ( & V_33 -> V_58 . V_60 ) ;
}
static void F_56 ( struct V_32 * V_33 , bool V_61 )
{
struct V_32 * V_62 ;
struct V_1 * V_2 ;
V_2 = F_57 ( V_33 -> V_2 ) ;
if ( V_2 && ! V_33 -> V_36 ) {
T_1 V_63 = V_33 -> V_11 ;
F_58 ( V_63 >= V_2 -> V_35 ) ;
F_59 ( V_2 -> V_64 [ V_63 ] ,
V_2 -> V_64 [ V_2 -> V_35 - 1 ] ) ;
V_62 = F_57 ( V_2 -> V_64 [ V_63 ] ) ;
V_62 -> V_11 = V_63 ;
-- V_2 -> V_35 ;
if ( V_61 ) {
F_60 ( V_33 -> V_2 , NULL ) ;
F_61 ( & V_33 -> V_58 ) ;
} else
F_50 ( V_2 , V_33 ) ;
F_62 () ;
F_19 ( V_2 , V_2 -> V_35 + 1 ) ;
F_54 ( V_33 ) ;
F_47 ( V_2 ) ;
} else if ( V_33 -> V_36 && V_61 ) {
V_2 = F_52 ( V_33 ) ;
F_61 ( & V_33 -> V_58 ) ;
}
if ( V_61 ) {
if ( V_2 && V_2 -> V_35 == 0 && V_2 -> V_57 == 0 ) {
F_63 ( V_2 -> V_41 ) ;
if ( ! ( V_2 -> V_4 & V_65 ) &&
V_2 -> V_41 -> V_66 == V_67 )
F_64 ( V_2 -> V_41 ) ;
}
F_58 ( ! F_65 ( V_68 ,
& V_33 -> V_69 . V_4 ) ) ;
F_66 ( & V_33 -> V_58 ) ;
}
}
static void F_67 ( struct V_32 * V_33 , bool V_61 )
{
F_68 () ;
F_56 ( V_33 , V_61 ) ;
F_69 () ;
}
static void F_70 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = F_34 ( V_41 ) ;
struct V_32 * V_33 , * V_70 ;
int V_20 , V_24 = V_2 -> V_35 ;
for ( V_20 = 0 ; V_20 < V_24 ; V_20 ++ ) {
V_33 = F_57 ( V_2 -> V_64 [ V_20 ] ) ;
F_58 ( ! V_33 ) ;
V_33 -> V_69 . V_58 -> V_71 ( V_33 -> V_69 . V_58 ) ;
F_60 ( V_33 -> V_2 , NULL ) ;
-- V_2 -> V_35 ;
}
F_71 (tfile, &tun->disabled, next) {
V_33 -> V_69 . V_58 -> V_71 ( V_33 -> V_69 . V_58 ) ;
F_60 ( V_33 -> V_2 , NULL ) ;
}
F_58 ( V_2 -> V_35 != 0 ) ;
F_62 () ;
for ( V_20 = 0 ; V_20 < V_24 ; V_20 ++ ) {
V_33 = F_57 ( V_2 -> V_64 [ V_20 ] ) ;
F_54 ( V_33 ) ;
F_61 ( & V_33 -> V_58 ) ;
}
F_72 (tfile, tmp, &tun->disabled, next) {
F_52 ( V_33 ) ;
F_54 ( V_33 ) ;
F_61 ( & V_33 -> V_58 ) ;
}
F_58 ( V_2 -> V_57 != 0 ) ;
if ( V_2 -> V_4 & V_65 )
F_73 ( V_72 ) ;
}
static int F_74 ( struct V_1 * V_2 , struct V_73 * V_73 , bool V_74 )
{
struct V_32 * V_33 = V_73 -> V_75 ;
int V_76 ;
V_76 = F_75 ( V_33 -> V_69 . V_58 , V_2 -> V_77 ) ;
if ( V_76 < 0 )
goto V_78;
V_76 = - V_79 ;
if ( F_57 ( V_33 -> V_2 ) && ! V_33 -> V_36 )
goto V_78;
V_76 = - V_80 ;
if ( ! ( V_2 -> V_4 & V_81 ) && V_2 -> V_35 == 1 )
goto V_78;
V_76 = - V_82 ;
if ( ! V_33 -> V_36 &&
V_2 -> V_35 + V_2 -> V_57 == V_83 )
goto V_78;
V_76 = 0 ;
if ( ! V_74 && ( V_2 -> V_84 == true ) ) {
V_76 = F_76 ( & V_2 -> V_85 , V_33 -> V_69 . V_58 ) ;
if ( ! V_76 )
goto V_78;
}
V_33 -> V_11 = V_2 -> V_35 ;
F_59 ( V_33 -> V_2 , V_2 ) ;
F_59 ( V_2 -> V_64 [ V_2 -> V_35 ] , V_33 ) ;
V_2 -> V_35 ++ ;
if ( V_33 -> V_36 )
F_52 ( V_33 ) ;
else
F_77 ( & V_33 -> V_58 ) ;
F_47 ( V_2 ) ;
V_78:
return V_76 ;
}
static struct V_1 * F_78 ( struct V_32 * V_33 )
{
struct V_1 * V_2 ;
F_26 () ;
V_2 = F_79 ( V_33 -> V_2 ) ;
if ( V_2 )
F_80 ( V_2 -> V_41 ) ;
F_30 () ;
return V_2 ;
}
static struct V_1 * F_81 ( struct V_73 * V_73 )
{
return F_78 ( V_73 -> V_75 ) ;
}
static void F_82 ( struct V_1 * V_2 )
{
F_83 ( V_2 -> V_41 ) ;
}
static void F_84 ( T_3 * V_86 , const T_5 * V_87 )
{
int V_24 = F_85 ( V_88 , V_87 ) >> 26 ;
V_86 [ V_24 >> 5 ] |= ( 1 << ( V_24 & 31 ) ) ;
}
static unsigned int F_86 ( const T_3 * V_86 , const T_5 * V_87 )
{
int V_24 = F_85 ( V_88 , V_87 ) >> 26 ;
return V_86 [ V_24 >> 5 ] & ( 1 << ( V_24 & 31 ) ) ;
}
static int F_87 ( struct V_89 * V_90 , void T_6 * V_91 )
{
struct { T_5 V_92 [ V_88 ] ; } * V_87 ;
struct V_93 V_94 ;
int V_76 , V_95 , V_24 , V_96 ;
if ( F_88 ( & V_94 , V_91 , sizeof( V_94 ) ) )
return - V_97 ;
if ( ! V_94 . V_29 ) {
V_90 -> V_29 = 0 ;
return 0 ;
}
V_95 = V_88 * V_94 . V_29 ;
V_87 = F_9 ( V_95 , V_98 ) ;
if ( ! V_87 )
return - V_99 ;
if ( F_88 ( V_87 , V_91 + sizeof( V_94 ) , V_95 ) ) {
V_76 = - V_97 ;
goto V_100;
}
V_90 -> V_29 = 0 ;
F_89 () ;
for ( V_24 = 0 ; V_24 < V_94 . V_29 && V_24 < V_101 ; V_24 ++ )
memcpy ( V_90 -> V_87 [ V_24 ] , V_87 [ V_24 ] . V_92 , V_88 ) ;
V_96 = V_24 ;
memset ( V_90 -> V_86 , 0 , sizeof( V_90 -> V_86 ) ) ;
for (; V_24 < V_94 . V_29 ; V_24 ++ ) {
if ( ! F_90 ( V_87 [ V_24 ] . V_92 ) ) {
V_76 = 0 ;
goto V_100;
}
F_84 ( V_90 -> V_86 , V_87 [ V_24 ] . V_92 ) ;
}
if ( ( V_94 . V_4 & V_102 ) )
memset ( V_90 -> V_86 , ~ 0 , sizeof( V_90 -> V_86 ) ) ;
F_89 () ;
V_90 -> V_29 = V_96 ;
V_76 = V_96 ;
V_100:
F_91 ( V_87 ) ;
return V_76 ;
}
static int F_92 ( struct V_89 * V_90 , const struct V_42 * V_43 )
{
struct V_103 * V_104 = (struct V_103 * ) V_43 -> V_25 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_90 -> V_29 ; V_20 ++ )
if ( F_93 ( V_104 -> V_105 , V_90 -> V_87 [ V_20 ] ) )
return 1 ;
if ( F_90 ( V_104 -> V_105 ) )
return F_86 ( V_90 -> V_86 , V_104 -> V_105 ) ;
return 0 ;
}
static int F_94 ( struct V_89 * V_90 , const struct V_42 * V_43 )
{
if ( ! V_90 -> V_29 )
return 1 ;
return F_92 ( V_90 , V_43 ) ;
}
static void F_95 ( struct V_40 * V_41 )
{
F_70 ( V_41 ) ;
}
static int F_96 ( struct V_40 * V_41 )
{
F_97 ( V_41 ) ;
return 0 ;
}
static int F_98 ( struct V_40 * V_41 )
{
F_99 ( V_41 ) ;
return 0 ;
}
static T_7 F_100 ( struct V_42 * V_43 , struct V_40 * V_41 )
{
struct V_1 * V_2 = F_34 ( V_41 ) ;
int V_46 = V_43 -> V_106 ;
struct V_32 * V_33 ;
T_3 V_35 = 0 ;
F_26 () ;
V_33 = F_79 ( V_2 -> V_64 [ V_46 ] ) ;
V_35 = F_35 ( V_2 -> V_35 ) ;
if ( V_46 >= V_35 )
goto V_107;
if ( V_35 == 1 ) {
T_8 V_6 ;
V_6 = F_36 ( V_43 ) ;
if ( V_6 ) {
struct V_7 * V_10 ;
V_10 = F_6 ( & V_2 -> V_34 [ F_5 ( V_6 ) ] ,
V_6 ) ;
if ( V_10 )
F_31 ( V_10 , V_6 ) ;
}
}
F_10 ( V_13 , V_2 , L_4 , V_43 -> V_108 ) ;
F_58 ( ! V_33 ) ;
if ( ! F_94 ( & V_2 -> V_109 , V_43 ) )
goto V_107;
if ( V_33 -> V_69 . V_58 -> V_110 &&
V_110 ( V_33 -> V_69 . V_58 , V_43 ) )
goto V_107;
if ( F_101 ( & V_33 -> V_69 . V_58 -> V_59 ) * V_35
>= V_41 -> V_111 )
goto V_107;
if ( F_32 ( F_102 ( V_43 , V_12 ) ) )
goto V_107;
if ( V_43 -> V_58 ) {
F_103 ( V_43 -> V_58 , & F_104 ( V_43 ) -> V_112 ) ;
F_105 ( V_43 ) ;
}
F_106 ( V_43 ) ;
F_107 ( V_43 ) ;
F_108 ( & V_33 -> V_69 . V_58 -> V_59 , V_43 ) ;
if ( V_33 -> V_4 & V_113 )
F_109 ( & V_33 -> V_114 , V_115 , V_116 ) ;
V_33 -> V_69 . V_58 -> V_71 ( V_33 -> V_69 . V_58 ) ;
F_30 () ;
return V_117 ;
V_107:
V_41 -> V_118 . V_119 ++ ;
F_110 ( V_43 ) ;
F_111 ( V_43 ) ;
F_30 () ;
return V_120 ;
}
static void F_112 ( struct V_40 * V_41 )
{
}
static int
F_113 ( struct V_40 * V_41 , int V_121 )
{
if ( V_121 < V_122 || V_121 + V_41 -> V_123 > V_124 )
return - V_79 ;
V_41 -> V_125 = V_121 ;
return 0 ;
}
static T_9 F_114 ( struct V_40 * V_41 ,
T_9 V_126 )
{
struct V_1 * V_2 = F_34 ( V_41 ) ;
return ( V_126 & V_2 -> V_127 ) | ( V_126 & ~ V_128 ) ;
}
static void F_115 ( struct V_40 * V_41 )
{
return;
}
static void F_116 ( struct V_1 * V_2 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_22 ; V_20 ++ )
F_117 ( & V_2 -> V_34 [ V_20 ] ) ;
V_2 -> V_27 = V_129 ;
F_118 ( & V_2 -> V_31 , F_20 , ( unsigned long ) V_2 ) ;
F_23 ( & V_2 -> V_31 ,
F_24 ( V_15 + V_2 -> V_27 ) ) ;
}
static void F_119 ( struct V_1 * V_2 )
{
F_120 ( & V_2 -> V_31 ) ;
F_15 ( V_2 ) ;
}
static void F_121 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = F_34 ( V_41 ) ;
switch ( V_2 -> V_4 & V_130 ) {
case V_131 :
V_41 -> V_132 = & V_133 ;
V_41 -> V_123 = 0 ;
V_41 -> V_134 = 0 ;
V_41 -> V_125 = 1500 ;
V_41 -> type = V_135 ;
V_41 -> V_4 = V_136 | V_137 | V_138 ;
V_41 -> V_111 = V_139 ;
break;
case V_140 :
V_41 -> V_132 = & V_141 ;
F_122 ( V_41 ) ;
V_41 -> V_142 &= ~ V_143 ;
V_41 -> V_142 |= V_144 ;
F_123 ( V_41 ) ;
V_41 -> V_111 = V_139 ;
break;
}
}
static unsigned int F_124 ( struct V_73 * V_73 , T_10 * V_145 )
{
struct V_32 * V_33 = V_73 -> V_75 ;
struct V_1 * V_2 = F_78 ( V_33 ) ;
struct V_146 * V_58 ;
unsigned int V_86 = 0 ;
if ( ! V_2 )
return V_147 ;
V_58 = V_33 -> V_69 . V_58 ;
F_10 ( V_13 , V_2 , L_5 ) ;
F_125 ( V_73 , F_126 ( V_58 ) , V_145 ) ;
if ( ! F_127 ( & V_58 -> V_59 ) )
V_86 |= V_148 | V_149 ;
if ( F_128 ( V_58 ) ||
( ! F_129 ( V_150 , & V_58 -> V_151 -> V_4 ) &&
F_128 ( V_58 ) ) )
V_86 |= V_152 | V_153 ;
if ( V_2 -> V_41 -> V_66 != V_67 )
V_86 = V_147 ;
F_82 ( V_2 ) ;
return V_86 ;
}
static struct V_42 * F_130 ( struct V_32 * V_33 ,
T_11 V_154 , T_11 V_108 ,
T_11 V_155 , int V_156 )
{
struct V_146 * V_58 = V_33 -> V_69 . V_58 ;
struct V_42 * V_43 ;
int V_76 ;
if ( V_154 + V_108 < V_157 || ! V_155 )
V_155 = V_108 ;
V_43 = F_131 ( V_58 , V_154 + V_155 , V_108 - V_155 , V_156 ,
& V_76 , 0 ) ;
if ( ! V_43 )
return F_132 ( V_76 ) ;
F_133 ( V_43 , V_154 ) ;
F_134 ( V_43 , V_155 ) ;
V_43 -> V_158 = V_108 - V_155 ;
V_43 -> V_108 += V_108 - V_155 ;
return V_43 ;
}
static T_12 F_135 ( struct V_1 * V_2 , struct V_32 * V_33 ,
void * V_159 , struct V_160 * V_161 ,
int V_156 )
{
struct V_162 V_163 = { 0 , F_136 (ETH_P_IP) } ;
struct V_42 * V_43 ;
T_11 V_164 = F_137 ( V_161 ) ;
T_11 V_108 = V_164 , V_165 = V_166 , V_155 ;
struct V_167 V_168 = { 0 } ;
int V_169 ;
int V_170 ;
bool V_171 = false ;
int V_76 ;
T_3 V_6 ;
T_12 V_24 ;
if ( ! ( V_2 -> V_4 & V_172 ) ) {
if ( V_108 < sizeof( V_163 ) )
return - V_79 ;
V_108 -= sizeof( V_163 ) ;
V_24 = F_138 ( & V_163 , sizeof( V_163 ) , V_161 ) ;
if ( V_24 != sizeof( V_163 ) )
return - V_97 ;
}
if ( V_2 -> V_4 & V_173 ) {
if ( V_108 < V_2 -> V_174 )
return - V_79 ;
V_108 -= V_2 -> V_174 ;
V_24 = F_138 ( & V_168 , sizeof( V_168 ) , V_161 ) ;
if ( V_24 != sizeof( V_168 ) )
return - V_97 ;
if ( ( V_168 . V_4 & V_175 ) &&
F_1 ( V_2 , V_168 . V_176 ) + F_1 ( V_2 , V_168 . V_177 ) + 2 > F_1 ( V_2 , V_168 . V_178 ) )
V_168 . V_178 = F_3 ( V_2 , F_1 ( V_2 , V_168 . V_176 ) + F_1 ( V_2 , V_168 . V_177 ) + 2 ) ;
if ( F_1 ( V_2 , V_168 . V_178 ) > V_108 )
return - V_79 ;
F_139 ( V_161 , V_2 -> V_174 - sizeof( V_168 ) ) ;
}
if ( ( V_2 -> V_4 & V_130 ) == V_140 ) {
V_165 += V_179 ;
if ( F_32 ( V_108 < V_180 ||
( V_168 . V_178 && F_1 ( V_2 , V_168 . V_178 ) < V_180 ) ) )
return - V_79 ;
}
V_169 = F_140 ( V_165 ) ;
if ( V_159 ) {
struct V_160 V_20 = * V_161 ;
V_170 = V_168 . V_178 ? F_1 ( V_2 , V_168 . V_178 ) : V_181 ;
if ( V_170 > V_169 )
V_170 = V_169 ;
V_155 = V_170 ;
F_139 ( & V_20 , V_170 ) ;
if ( F_141 ( & V_20 , V_182 ) <= V_183 )
V_171 = true ;
}
if ( ! V_171 ) {
V_170 = V_108 ;
if ( F_1 ( V_2 , V_168 . V_178 ) > V_169 )
V_155 = V_169 ;
else
V_155 = F_1 ( V_2 , V_168 . V_178 ) ;
}
V_43 = F_130 ( V_33 , V_165 , V_170 , V_155 , V_156 ) ;
if ( F_142 ( V_43 ) ) {
if ( F_143 ( V_43 ) != - V_184 )
V_2 -> V_41 -> V_118 . V_185 ++ ;
return F_143 ( V_43 ) ;
}
if ( V_171 )
V_76 = F_144 ( V_43 , V_161 ) ;
else {
V_76 = F_145 ( V_43 , 0 , V_161 , V_108 ) ;
if ( ! V_76 && V_159 ) {
struct V_186 * V_187 = V_159 ;
V_187 -> V_188 ( V_187 , false ) ;
}
}
if ( V_76 ) {
V_2 -> V_41 -> V_118 . V_185 ++ ;
F_111 ( V_43 ) ;
return - V_97 ;
}
if ( V_168 . V_4 & V_175 ) {
if ( ! F_146 ( V_43 , F_1 ( V_2 , V_168 . V_176 ) ,
F_1 ( V_2 , V_168 . V_177 ) ) ) {
V_2 -> V_41 -> V_118 . V_189 ++ ;
F_111 ( V_43 ) ;
return - V_79 ;
}
}
switch ( V_2 -> V_4 & V_130 ) {
case V_131 :
if ( V_2 -> V_4 & V_172 ) {
switch ( V_43 -> V_25 [ 0 ] & 0xf0 ) {
case 0x40 :
V_163 . V_190 = F_147 ( V_191 ) ;
break;
case 0x60 :
V_163 . V_190 = F_147 ( V_192 ) ;
break;
default:
V_2 -> V_41 -> V_118 . V_185 ++ ;
F_111 ( V_43 ) ;
return - V_79 ;
}
}
F_148 ( V_43 ) ;
V_43 -> V_193 = V_163 . V_190 ;
V_43 -> V_41 = V_2 -> V_41 ;
break;
case V_140 :
V_43 -> V_193 = F_149 ( V_43 , V_2 -> V_41 ) ;
break;
}
if ( V_168 . V_194 != V_195 ) {
F_150 ( L_6 ) ;
switch ( V_168 . V_194 & ~ V_196 ) {
case V_197 :
F_104 ( V_43 ) -> V_194 = V_198 ;
break;
case V_199 :
F_104 ( V_43 ) -> V_194 = V_200 ;
break;
case V_201 :
F_104 ( V_43 ) -> V_194 = V_202 ;
break;
default:
V_2 -> V_41 -> V_118 . V_189 ++ ;
F_111 ( V_43 ) ;
return - V_79 ;
}
if ( V_168 . V_194 & V_196 )
F_104 ( V_43 ) -> V_194 |= V_203 ;
F_104 ( V_43 ) -> V_204 = F_1 ( V_2 , V_168 . V_204 ) ;
if ( F_104 ( V_43 ) -> V_204 == 0 ) {
V_2 -> V_41 -> V_118 . V_189 ++ ;
F_111 ( V_43 ) ;
return - V_79 ;
}
F_104 ( V_43 ) -> V_194 |= V_205 ;
F_104 ( V_43 ) -> V_206 = 0 ;
}
if ( V_171 ) {
F_104 ( V_43 ) -> V_207 = V_159 ;
F_104 ( V_43 ) -> V_112 |= V_208 ;
F_104 ( V_43 ) -> V_112 |= V_209 ;
}
F_151 ( V_43 ) ;
F_152 ( V_43 , 0 ) ;
V_6 = F_36 ( V_43 ) ;
F_153 ( V_43 ) ;
V_2 -> V_41 -> V_118 . V_210 ++ ;
V_2 -> V_41 -> V_118 . V_211 += V_108 ;
F_25 ( V_2 , V_6 , V_33 ) ;
return V_164 ;
}
static T_12 F_154 ( struct V_212 * V_213 , struct V_160 * V_161 )
{
struct V_73 * V_73 = V_213 -> V_214 ;
struct V_1 * V_2 = F_81 ( V_73 ) ;
struct V_32 * V_33 = V_73 -> V_75 ;
T_12 V_215 ;
if ( ! V_2 )
return - V_216 ;
V_215 = F_135 ( V_2 , V_33 , NULL , V_161 , V_73 -> V_217 & V_218 ) ;
F_82 ( V_2 ) ;
return V_215 ;
}
static T_12 F_155 ( struct V_1 * V_2 ,
struct V_32 * V_33 ,
struct V_42 * V_43 ,
struct V_160 * V_219 )
{
struct V_162 V_163 = { 0 , V_43 -> V_193 } ;
T_12 V_220 ;
int V_221 = 0 ;
int V_222 = 0 ;
int V_174 = 0 ;
if ( F_156 ( V_43 ) )
V_222 = V_223 ;
if ( V_2 -> V_4 & V_173 )
V_174 = V_2 -> V_174 ;
V_220 = V_43 -> V_108 + V_222 + V_174 ;
if ( ! ( V_2 -> V_4 & V_172 ) ) {
if ( F_137 ( V_219 ) < sizeof( V_163 ) )
return - V_79 ;
V_220 += sizeof( V_163 ) ;
if ( F_137 ( V_219 ) < V_220 ) {
V_163 . V_4 |= V_224 ;
}
if ( F_157 ( & V_163 , sizeof( V_163 ) , V_219 ) != sizeof( V_163 ) )
return - V_97 ;
}
if ( V_174 ) {
struct V_167 V_168 = { 0 } ;
if ( F_137 ( V_219 ) < V_174 )
return - V_79 ;
if ( F_158 ( V_43 ) ) {
struct V_225 * V_226 = F_104 ( V_43 ) ;
V_168 . V_178 = F_3 ( V_2 , F_159 ( V_43 ) ) ;
V_168 . V_204 = F_3 ( V_2 , V_226 -> V_204 ) ;
if ( V_226 -> V_194 & V_198 )
V_168 . V_194 = V_197 ;
else if ( V_226 -> V_194 & V_200 )
V_168 . V_194 = V_199 ;
else if ( V_226 -> V_194 & V_202 )
V_168 . V_194 = V_201 ;
else {
F_160 ( L_7
L_8 ,
V_226 -> V_194 , F_1 ( V_2 , V_168 . V_204 ) ,
F_1 ( V_2 , V_168 . V_178 ) ) ;
F_161 ( V_227 , L_9 ,
V_228 ,
16 , 1 , V_43 -> V_9 ,
F_162 ( ( int ) F_1 ( V_2 , V_168 . V_178 ) , 64 ) , true ) ;
F_163 ( 1 ) ;
return - V_79 ;
}
if ( V_226 -> V_194 & V_203 )
V_168 . V_194 |= V_196 ;
} else
V_168 . V_194 = V_195 ;
if ( V_43 -> V_229 == V_230 ) {
V_168 . V_4 = V_175 ;
V_168 . V_176 = F_3 ( V_2 , F_164 ( V_43 ) +
V_222 ) ;
V_168 . V_177 = F_3 ( V_2 , V_43 -> V_177 ) ;
} else if ( V_43 -> V_229 == V_231 ) {
V_168 . V_4 = V_232 ;
}
if ( F_157 ( & V_168 , sizeof( V_168 ) , V_219 ) != sizeof( V_168 ) )
return - V_97 ;
F_139 ( V_219 , V_174 - sizeof( V_168 ) ) ;
}
if ( V_222 ) {
int V_233 ;
struct {
T_13 V_234 ;
T_13 V_235 ;
} V_236 ;
V_236 . V_234 = V_43 -> V_237 ;
V_236 . V_235 = F_147 ( F_165 ( V_43 ) ) ;
V_221 = F_166 ( struct V_238 , V_234 ) ;
V_233 = F_167 ( V_43 , 0 , V_219 , V_221 ) ;
if ( V_233 || ! F_137 ( V_219 ) )
goto V_100;
V_233 = F_157 ( & V_236 , sizeof( V_236 ) , V_219 ) ;
if ( V_233 != sizeof( V_236 ) || ! F_137 ( V_219 ) )
goto V_100;
}
F_167 ( V_43 , V_221 , V_219 , V_43 -> V_108 - V_221 ) ;
V_100:
V_2 -> V_41 -> V_118 . V_239 ++ ;
V_2 -> V_41 -> V_118 . V_240 += V_43 -> V_108 + V_222 ;
return V_220 ;
}
static T_12 F_168 ( struct V_1 * V_2 , struct V_32 * V_33 ,
struct V_160 * V_241 ,
int V_156 )
{
struct V_42 * V_43 ;
T_12 V_233 ;
int V_242 , V_76 , V_243 = 0 ;
F_10 ( V_13 , V_2 , L_10 ) ;
if ( ! F_137 ( V_241 ) )
return 0 ;
if ( V_2 -> V_41 -> V_66 != V_67 )
return - V_244 ;
V_43 = F_169 ( V_33 -> V_69 . V_58 , V_156 ? V_245 : 0 ,
& V_242 , & V_243 , & V_76 ) ;
if ( ! V_43 )
return V_76 ;
V_233 = F_155 ( V_2 , V_33 , V_43 , V_241 ) ;
if ( F_32 ( V_233 < 0 ) )
F_111 ( V_43 ) ;
else
F_170 ( V_43 ) ;
return V_233 ;
}
static T_12 F_171 ( struct V_212 * V_213 , struct V_160 * V_241 )
{
struct V_73 * V_73 = V_213 -> V_214 ;
struct V_32 * V_33 = V_73 -> V_75 ;
struct V_1 * V_2 = F_78 ( V_33 ) ;
T_12 V_108 = F_137 ( V_241 ) , V_233 ;
if ( ! V_2 )
return - V_216 ;
V_233 = F_168 ( V_2 , V_33 , V_241 , V_73 -> V_217 & V_218 ) ;
V_233 = F_172 ( T_12 , V_233 , V_108 ) ;
if ( V_233 > 0 )
V_213 -> V_246 = V_233 ;
F_82 ( V_2 ) ;
return V_233 ;
}
static void F_173 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = F_34 ( V_41 ) ;
F_58 ( ! ( F_174 ( & V_2 -> V_56 ) ) ) ;
F_119 ( V_2 ) ;
F_175 ( V_2 -> V_77 ) ;
F_176 ( V_41 ) ;
}
static void F_177 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = F_34 ( V_41 ) ;
V_2 -> V_50 = V_247 ;
V_2 -> V_52 = V_248 ;
V_41 -> V_249 = & V_250 ;
V_41 -> V_251 = F_173 ;
}
static int F_178 ( struct V_252 * V_253 [] , struct V_252 * V_25 [] )
{
return - V_79 ;
}
static void F_179 ( struct V_146 * V_58 )
{
struct V_32 * V_33 ;
T_14 * V_254 ;
if ( ! F_128 ( V_58 ) )
return;
if ( ! F_180 ( V_150 , & V_58 -> V_151 -> V_4 ) )
return;
V_254 = F_126 ( V_58 ) ;
if ( V_254 && F_181 ( V_254 ) )
F_182 ( V_254 , V_152 |
V_153 | V_255 ) ;
V_33 = F_183 ( V_58 , struct V_32 , V_58 ) ;
F_109 ( & V_33 -> V_114 , V_115 , V_256 ) ;
}
static int F_184 ( struct V_69 * V_146 , struct V_257 * V_258 , T_11 V_164 )
{
int V_233 ;
struct V_32 * V_33 = F_183 ( V_146 , struct V_32 , V_69 ) ;
struct V_1 * V_2 = F_78 ( V_33 ) ;
if ( ! V_2 )
return - V_216 ;
V_233 = F_135 ( V_2 , V_33 , V_258 -> V_159 , & V_258 -> V_259 ,
V_258 -> V_260 & V_245 ) ;
F_82 ( V_2 ) ;
return V_233 ;
}
static int F_185 ( struct V_69 * V_146 , struct V_257 * V_258 , T_11 V_164 ,
int V_4 )
{
struct V_32 * V_33 = F_183 ( V_146 , struct V_32 , V_69 ) ;
struct V_1 * V_2 = F_78 ( V_33 ) ;
int V_233 ;
if ( ! V_2 )
return - V_216 ;
if ( V_4 & ~ ( V_245 | V_261 | V_262 ) ) {
V_233 = - V_79 ;
goto V_78;
}
if ( V_4 & V_262 ) {
V_233 = F_186 ( V_146 -> V_58 , V_258 , V_164 ,
V_263 , V_264 ) ;
goto V_78;
}
V_233 = F_168 ( V_2 , V_33 , & V_258 -> V_259 , V_4 & V_245 ) ;
if ( V_233 > ( T_12 ) V_164 ) {
V_258 -> V_260 |= V_261 ;
V_233 = V_4 & V_261 ? V_233 : V_164 ;
}
V_78:
F_82 ( V_2 ) ;
return V_233 ;
}
static int F_187 ( struct V_69 * V_146 )
{
if ( V_146 -> V_58 )
F_61 ( V_146 -> V_58 ) ;
return 0 ;
}
static int F_188 ( struct V_1 * V_2 )
{
return V_2 -> V_4 & ( V_265 | V_65 | V_131 | V_140 ) ;
}
static T_12 F_189 ( struct V_266 * V_41 , struct V_267 * V_268 ,
char * V_269 )
{
struct V_1 * V_2 = F_34 ( F_190 ( V_41 ) ) ;
return sprintf ( V_269 , L_11 , F_188 ( V_2 ) ) ;
}
static T_12 F_191 ( struct V_266 * V_41 , struct V_267 * V_268 ,
char * V_269 )
{
struct V_1 * V_2 = F_34 ( F_190 ( V_41 ) ) ;
return F_42 ( V_2 -> V_50 ) ?
sprintf ( V_269 , L_12 ,
F_192 ( F_193 () , V_2 -> V_50 ) ) :
sprintf ( V_269 , L_13 ) ;
}
static T_12 F_194 ( struct V_266 * V_41 , struct V_267 * V_268 ,
char * V_269 )
{
struct V_1 * V_2 = F_34 ( F_190 ( V_41 ) ) ;
return F_44 ( V_2 -> V_52 ) ?
sprintf ( V_269 , L_12 ,
F_195 ( F_193 () , V_2 -> V_52 ) ) :
sprintf ( V_269 , L_13 ) ;
}
static int F_196 ( struct V_49 * V_49 , struct V_73 * V_73 , struct V_270 * V_271 )
{
struct V_1 * V_2 ;
struct V_32 * V_33 = V_73 -> V_75 ;
struct V_40 * V_41 ;
int V_76 ;
if ( V_33 -> V_36 )
return - V_79 ;
V_41 = F_197 ( V_49 , V_271 -> V_272 ) ;
if ( V_41 ) {
if ( V_271 -> V_273 & V_274 )
return - V_80 ;
if ( ( V_271 -> V_273 & V_131 ) && V_41 -> V_132 == & V_133 )
V_2 = F_34 ( V_41 ) ;
else if ( ( V_271 -> V_273 & V_140 ) && V_41 -> V_132 == & V_141 )
V_2 = F_34 ( V_41 ) ;
else
return - V_79 ;
if ( ! ! ( V_271 -> V_273 & V_81 ) !=
! ! ( V_2 -> V_4 & V_81 ) )
return - V_79 ;
if ( F_39 ( V_2 ) )
return - V_275 ;
V_76 = F_198 ( V_2 -> V_77 ) ;
if ( V_76 < 0 )
return V_76 ;
V_76 = F_74 ( V_2 , V_73 , V_271 -> V_273 & V_276 ) ;
if ( V_76 < 0 )
return V_76 ;
if ( V_2 -> V_4 & V_81 &&
( V_2 -> V_35 + V_2 -> V_57 > 1 ) ) {
return 0 ;
}
}
else {
char * V_277 ;
unsigned long V_4 = 0 ;
int V_278 = V_271 -> V_273 & V_81 ?
V_83 : 1 ;
if ( ! F_46 ( V_49 -> V_53 , V_54 ) )
return - V_275 ;
V_76 = F_199 () ;
if ( V_76 < 0 )
return V_76 ;
if ( V_271 -> V_273 & V_131 ) {
V_4 |= V_131 ;
V_277 = L_14 ;
} else if ( V_271 -> V_273 & V_140 ) {
V_4 |= V_140 ;
V_277 = L_15 ;
} else
return - V_79 ;
if ( * V_271 -> V_272 )
V_277 = V_271 -> V_272 ;
V_41 = F_200 ( sizeof( struct V_1 ) , V_277 ,
V_279 , F_177 , V_278 ,
V_278 ) ;
if ( ! V_41 )
return - V_99 ;
F_201 ( V_41 , V_49 ) ;
V_41 -> V_280 = & V_281 ;
V_41 -> V_282 = V_33 -> V_282 ;
V_41 -> V_283 [ 0 ] = & V_284 ;
V_2 = F_34 ( V_41 ) ;
V_2 -> V_41 = V_41 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_109 . V_29 = 0 ;
V_2 -> V_174 = sizeof( struct V_167 ) ;
V_2 -> V_84 = false ;
V_2 -> V_285 = V_33 -> V_69 . V_58 -> V_286 ;
F_202 ( & V_2 -> V_21 ) ;
V_76 = F_203 ( & V_2 -> V_77 ) ;
if ( V_76 < 0 )
goto V_287;
F_121 ( V_41 ) ;
F_116 ( V_2 ) ;
V_41 -> V_288 = V_289 | V_290 |
V_128 | V_291 |
V_292 ;
V_41 -> V_126 = V_41 -> V_288 ;
V_41 -> V_293 = V_41 -> V_126 &
~ ( V_291 |
V_292 ) ;
F_204 ( & V_2 -> V_56 ) ;
V_76 = F_74 ( V_2 , V_73 , false ) ;
if ( V_76 < 0 )
goto V_294;
V_76 = F_205 ( V_2 -> V_41 ) ;
if ( V_76 < 0 )
goto V_295;
}
F_206 ( V_2 -> V_41 ) ;
F_10 ( V_13 , V_2 , L_16 ) ;
V_2 -> V_4 = ( V_2 -> V_4 & ~ V_265 ) |
( V_271 -> V_273 & V_265 ) ;
if ( F_207 ( V_2 -> V_41 ) )
F_208 ( V_2 -> V_41 ) ;
strcpy ( V_271 -> V_272 , V_2 -> V_41 -> V_277 ) ;
return 0 ;
V_295:
F_70 ( V_41 ) ;
V_294:
F_119 ( V_2 ) ;
F_175 ( V_2 -> V_77 ) ;
V_287:
F_176 ( V_41 ) ;
return V_76 ;
}
static void F_209 ( struct V_49 * V_49 , struct V_1 * V_2 ,
struct V_270 * V_271 )
{
F_10 ( V_13 , V_2 , L_17 ) ;
strcpy ( V_271 -> V_272 , V_2 -> V_41 -> V_277 ) ;
V_271 -> V_273 = F_188 ( V_2 ) ;
}
static int F_210 ( struct V_1 * V_2 , unsigned long V_91 )
{
T_9 V_126 = 0 ;
if ( V_91 & V_296 ) {
V_126 |= V_297 ;
V_91 &= ~ V_296 ;
if ( V_91 & ( V_298 | V_299 ) ) {
if ( V_91 & V_300 ) {
V_126 |= V_301 ;
V_91 &= ~ V_300 ;
}
if ( V_91 & V_298 )
V_126 |= V_302 ;
if ( V_91 & V_299 )
V_126 |= V_303 ;
V_91 &= ~ ( V_298 | V_299 ) ;
}
if ( V_91 & V_304 ) {
V_126 |= V_305 ;
V_91 &= ~ V_304 ;
}
}
if ( V_91 )
return - V_79 ;
V_2 -> V_127 = V_126 ;
F_211 ( V_2 -> V_41 ) ;
return 0 ;
}
static void F_212 ( struct V_1 * V_2 , int V_24 )
{
int V_20 ;
struct V_32 * V_33 ;
for ( V_20 = 0 ; V_20 < V_24 ; V_20 ++ ) {
V_33 = F_57 ( V_2 -> V_64 [ V_20 ] ) ;
F_213 ( V_33 -> V_69 . V_58 ) ;
}
V_2 -> V_84 = false ;
}
static int F_214 ( struct V_1 * V_2 )
{
int V_20 , V_233 = 0 ;
struct V_32 * V_33 ;
for ( V_20 = 0 ; V_20 < V_2 -> V_35 ; V_20 ++ ) {
V_33 = F_57 ( V_2 -> V_64 [ V_20 ] ) ;
V_233 = F_76 ( & V_2 -> V_85 , V_33 -> V_69 . V_58 ) ;
if ( V_233 ) {
F_212 ( V_2 , V_20 ) ;
return V_233 ;
}
}
V_2 -> V_84 = true ;
return V_233 ;
}
static void F_215 ( struct V_1 * V_2 )
{
struct V_32 * V_33 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_2 -> V_35 ; V_20 ++ ) {
V_33 = F_57 ( V_2 -> V_64 [ V_20 ] ) ;
V_33 -> V_69 . V_58 -> V_286 = V_2 -> V_285 ;
}
}
static int F_216 ( struct V_73 * V_73 , struct V_270 * V_271 )
{
struct V_32 * V_33 = V_73 -> V_75 ;
struct V_1 * V_2 ;
int V_233 = 0 ;
F_68 () ;
if ( V_271 -> V_273 & V_306 ) {
V_2 = V_33 -> V_36 ;
if ( ! V_2 ) {
V_233 = - V_79 ;
goto V_37;
}
V_233 = F_217 ( V_2 -> V_77 ) ;
if ( V_233 < 0 )
goto V_37;
V_233 = F_74 ( V_2 , V_73 , false ) ;
} else if ( V_271 -> V_273 & V_307 ) {
V_2 = F_57 ( V_33 -> V_2 ) ;
if ( ! V_2 || ! ( V_2 -> V_4 & V_81 ) || V_33 -> V_36 )
V_233 = - V_79 ;
else
F_56 ( V_33 , false ) ;
} else
V_233 = - V_79 ;
V_37:
F_69 () ;
return V_233 ;
}
static long F_218 ( struct V_73 * V_73 , unsigned int V_308 ,
unsigned long V_91 , int V_309 )
{
struct V_32 * V_33 = V_73 -> V_75 ;
struct V_1 * V_2 ;
void T_6 * V_310 = ( void T_6 * ) V_91 ;
struct V_270 V_271 ;
T_15 V_50 ;
T_16 V_52 ;
int V_285 ;
int V_174 ;
unsigned int V_282 ;
int V_311 ;
int V_233 ;
if ( V_308 == V_312 || V_308 == V_313 || F_219 ( V_308 ) == 0x89 ) {
if ( F_88 ( & V_271 , V_310 , V_309 ) )
return - V_97 ;
} else {
memset ( & V_271 , 0 , sizeof( V_271 ) ) ;
}
if ( V_308 == V_314 ) {
return F_220 ( V_131 | V_140 | V_265 ,
( unsigned int T_6 * ) V_310 ) ;
} else if ( V_308 == V_313 )
return F_216 ( V_73 , & V_271 ) ;
V_233 = 0 ;
F_68 () ;
V_2 = F_78 ( V_33 ) ;
if ( V_308 == V_312 && ! V_2 ) {
V_271 . V_272 [ V_315 - 1 ] = '\0' ;
V_233 = F_196 ( V_33 -> V_49 , V_73 , & V_271 ) ;
if ( V_233 )
goto V_37;
if ( F_221 ( V_310 , & V_271 , V_309 ) )
V_233 = - V_97 ;
goto V_37;
}
if ( V_308 == V_316 ) {
V_233 = - V_275 ;
if ( V_2 )
goto V_37;
V_233 = - V_97 ;
if ( F_88 ( & V_282 , V_310 , sizeof( V_282 ) ) )
goto V_37;
V_233 = 0 ;
V_33 -> V_282 = V_282 ;
goto V_37;
}
V_233 = - V_216 ;
if ( ! V_2 )
goto V_37;
F_10 ( V_13 , V_2 , L_18 , V_308 ) ;
V_233 = 0 ;
switch ( V_308 ) {
case V_317 :
F_209 ( V_318 -> V_319 -> V_320 , V_2 , & V_271 ) ;
if ( V_33 -> V_36 )
V_271 . V_273 |= V_307 ;
if ( ! V_33 -> V_69 . V_58 -> V_110 )
V_271 . V_273 |= V_276 ;
if ( F_221 ( V_310 , & V_271 , V_309 ) )
V_233 = - V_97 ;
break;
case V_321 :
F_10 ( V_13 , V_2 , L_19 ,
V_91 ? L_20 : L_21 ) ;
break;
case V_322 :
if ( V_91 && ! ( V_2 -> V_4 & V_65 ) ) {
V_2 -> V_4 |= V_65 ;
F_222 ( V_72 ) ;
}
if ( ! V_91 && ( V_2 -> V_4 & V_65 ) ) {
V_2 -> V_4 &= ~ V_65 ;
F_73 ( V_72 ) ;
}
F_10 ( V_13 , V_2 , L_22 ,
V_91 ? L_21 : L_20 ) ;
break;
case V_323 :
V_50 = F_223 ( F_193 () , V_91 ) ;
if ( ! F_42 ( V_50 ) ) {
V_233 = - V_79 ;
break;
}
V_2 -> V_50 = V_50 ;
F_10 ( V_13 , V_2 , L_23 ,
F_224 ( & V_324 , V_2 -> V_50 ) ) ;
break;
case V_325 :
V_52 = F_225 ( F_193 () , V_91 ) ;
if ( ! F_44 ( V_52 ) ) {
V_233 = - V_79 ;
break;
}
V_2 -> V_52 = V_52 ;
F_10 ( V_13 , V_2 , L_24 ,
F_226 ( & V_324 , V_2 -> V_52 ) ) ;
break;
case V_326 :
if ( V_2 -> V_41 -> V_4 & V_327 ) {
F_10 ( V_13 , V_2 ,
L_25 ) ;
V_233 = - V_80 ;
} else {
V_2 -> V_41 -> type = ( int ) V_91 ;
F_10 ( V_13 , V_2 , L_26 ,
V_2 -> V_41 -> type ) ;
V_233 = 0 ;
}
break;
#ifdef F_227
case V_328 :
V_2 -> V_329 = V_91 ;
break;
#endif
case V_330 :
V_233 = F_210 ( V_2 , V_91 ) ;
break;
case V_331 :
V_233 = - V_79 ;
if ( ( V_2 -> V_4 & V_130 ) != V_140 )
break;
V_233 = F_87 ( & V_2 -> V_109 , ( void T_6 * ) V_91 ) ;
break;
case V_332 :
memcpy ( V_271 . V_333 . V_334 , V_2 -> V_41 -> V_335 , V_88 ) ;
V_271 . V_333 . V_336 = V_2 -> V_41 -> type ;
if ( F_221 ( V_310 , & V_271 , V_309 ) )
V_233 = - V_97 ;
break;
case V_337 :
F_10 ( V_338 , V_2 , L_27 ,
V_271 . V_333 . V_334 ) ;
V_233 = F_228 ( V_2 -> V_41 , & V_271 . V_333 ) ;
break;
case V_339 :
V_285 = V_33 -> V_69 . V_58 -> V_286 ;
if ( F_221 ( V_310 , & V_285 , sizeof( V_285 ) ) )
V_233 = - V_97 ;
break;
case V_340 :
if ( F_88 ( & V_285 , V_310 , sizeof( V_285 ) ) ) {
V_233 = - V_97 ;
break;
}
V_2 -> V_285 = V_285 ;
F_215 ( V_2 ) ;
break;
case V_341 :
V_174 = V_2 -> V_174 ;
if ( F_221 ( V_310 , & V_174 , sizeof( V_174 ) ) )
V_233 = - V_97 ;
break;
case V_342 :
if ( F_88 ( & V_174 , V_310 , sizeof( V_174 ) ) ) {
V_233 = - V_97 ;
break;
}
if ( V_174 < ( int ) sizeof( struct V_167 ) ) {
V_233 = - V_79 ;
break;
}
V_2 -> V_174 = V_174 ;
break;
case V_343 :
V_311 = ! ! ( V_2 -> V_4 & V_5 ) ;
if ( F_220 ( V_311 , ( int T_6 * ) V_310 ) )
V_233 = - V_97 ;
break;
case V_344 :
if ( F_229 ( V_311 , ( int T_6 * ) V_310 ) ) {
V_233 = - V_97 ;
break;
}
if ( V_311 )
V_2 -> V_4 |= V_5 ;
else
V_2 -> V_4 &= ~ V_5 ;
break;
case V_345 :
V_233 = - V_79 ;
if ( ( V_2 -> V_4 & V_130 ) != V_140 )
break;
V_233 = - V_97 ;
if ( F_88 ( & V_2 -> V_85 , V_310 , sizeof( V_2 -> V_85 ) ) )
break;
V_233 = F_214 ( V_2 ) ;
break;
case V_346 :
V_233 = - V_79 ;
if ( ( V_2 -> V_4 & V_130 ) != V_140 )
break;
V_233 = 0 ;
F_212 ( V_2 , V_2 -> V_35 ) ;
break;
case V_347 :
V_233 = - V_79 ;
if ( ( V_2 -> V_4 & V_130 ) != V_140 )
break;
V_233 = - V_97 ;
if ( F_221 ( V_310 , & V_2 -> V_85 , sizeof( V_2 -> V_85 ) ) )
break;
V_233 = 0 ;
break;
default:
V_233 = - V_79 ;
break;
}
V_37:
F_69 () ;
if ( V_2 )
F_82 ( V_2 ) ;
return V_233 ;
}
static long F_230 ( struct V_73 * V_73 ,
unsigned int V_308 , unsigned long V_91 )
{
return F_218 ( V_73 , V_308 , V_91 , sizeof ( struct V_270 ) ) ;
}
static long F_231 ( struct V_73 * V_73 ,
unsigned int V_308 , unsigned long V_91 )
{
switch ( V_308 ) {
case V_312 :
case V_317 :
case V_331 :
case V_339 :
case V_340 :
case V_332 :
case V_337 :
V_91 = ( unsigned long ) F_232 ( V_91 ) ;
break;
default:
V_91 = ( V_348 ) V_91 ;
break;
}
return F_218 ( V_73 , V_308 , V_91 , sizeof( struct V_349 ) ) ;
}
static int F_233 ( int V_350 , struct V_73 * V_73 , int V_351 )
{
struct V_32 * V_33 = V_73 -> V_75 ;
int V_233 ;
if ( ( V_233 = F_234 ( V_350 , V_73 , V_351 , & V_33 -> V_114 ) ) < 0 )
goto V_78;
if ( V_351 ) {
F_235 ( V_73 , F_236 ( V_318 ) , V_352 , 0 ) ;
V_33 -> V_4 |= V_113 ;
} else
V_33 -> V_4 &= ~ V_113 ;
V_233 = 0 ;
V_78:
return V_233 ;
}
static int F_237 ( struct V_353 * V_353 , struct V_73 * V_73 )
{
struct V_32 * V_33 ;
F_238 ( V_13 , L_28 ) ;
V_33 = (struct V_32 * ) F_239 ( & V_354 , V_355 , V_98 ,
& V_356 ) ;
if ( ! V_33 )
return - V_99 ;
F_60 ( V_33 -> V_2 , NULL ) ;
V_33 -> V_49 = F_240 ( V_318 -> V_319 -> V_320 ) ;
V_33 -> V_4 = 0 ;
V_33 -> V_282 = 0 ;
F_241 ( & V_33 -> V_357 . V_145 ) ;
F_60 ( V_33 -> V_69 . V_357 , & V_33 -> V_357 ) ;
V_33 -> V_69 . V_73 = V_73 ;
V_33 -> V_69 . V_358 = & V_359 ;
F_242 ( & V_33 -> V_69 , & V_33 -> V_58 ) ;
F_243 ( & V_33 -> V_58 , V_33 -> V_49 ) ;
V_33 -> V_58 . V_360 = F_179 ;
V_33 -> V_58 . V_286 = V_182 ;
V_73 -> V_75 = V_33 ;
F_244 ( V_68 , & V_33 -> V_69 . V_4 ) ;
F_204 ( & V_33 -> V_55 ) ;
F_245 ( & V_33 -> V_58 , V_361 ) ;
return 0 ;
}
static int F_246 ( struct V_353 * V_353 , struct V_73 * V_73 )
{
struct V_32 * V_33 = V_73 -> V_75 ;
struct V_49 * V_49 = V_33 -> V_49 ;
F_67 ( V_33 , true ) ;
F_247 ( V_49 ) ;
return 0 ;
}
static void F_248 ( struct V_362 * V_258 , struct V_73 * V_363 )
{
struct V_1 * V_2 ;
struct V_270 V_271 ;
memset ( & V_271 , 0 , sizeof( V_271 ) ) ;
F_68 () ;
V_2 = F_81 ( V_363 ) ;
if ( V_2 )
F_209 ( V_318 -> V_319 -> V_320 , V_2 , & V_271 ) ;
F_69 () ;
if ( V_2 )
F_82 ( V_2 ) ;
F_249 ( V_258 , L_29 , V_271 . V_272 ) ;
}
static int F_250 ( struct V_40 * V_41 , struct V_364 * V_308 )
{
V_308 -> V_365 = 0 ;
V_308 -> V_366 = 0 ;
F_251 ( V_308 , V_367 ) ;
V_308 -> V_368 = V_369 ;
V_308 -> V_370 = V_371 ;
V_308 -> V_372 = 0 ;
V_308 -> V_373 = V_374 ;
V_308 -> V_375 = V_376 ;
V_308 -> V_377 = 0 ;
V_308 -> V_378 = 0 ;
return 0 ;
}
static void F_252 ( struct V_40 * V_41 , struct V_379 * V_380 )
{
struct V_1 * V_2 = F_34 ( V_41 ) ;
F_253 ( V_380 -> V_381 , V_382 , sizeof( V_380 -> V_381 ) ) ;
F_253 ( V_380 -> V_383 , V_384 , sizeof( V_380 -> V_383 ) ) ;
switch ( V_2 -> V_4 & V_130 ) {
case V_131 :
F_253 ( V_380 -> V_385 , L_30 , sizeof( V_380 -> V_385 ) ) ;
break;
case V_140 :
F_253 ( V_380 -> V_385 , L_31 , sizeof( V_380 -> V_385 ) ) ;
break;
}
}
static T_3 F_254 ( struct V_40 * V_41 )
{
#ifdef F_227
struct V_1 * V_2 = F_34 ( V_41 ) ;
return V_2 -> V_329 ;
#else
return - V_386 ;
#endif
}
static void F_255 ( struct V_40 * V_41 , T_3 V_387 )
{
#ifdef F_227
struct V_1 * V_2 = F_34 ( V_41 ) ;
V_2 -> V_329 = V_387 ;
#endif
}
static int T_17 F_256 ( void )
{
int V_233 = 0 ;
F_257 ( L_32 , V_388 , V_384 ) ;
F_257 ( L_33 , V_389 ) ;
V_233 = F_258 ( & V_281 ) ;
if ( V_233 ) {
F_160 ( L_34 ) ;
goto V_390;
}
V_233 = F_259 ( & V_391 ) ;
if ( V_233 ) {
F_160 ( L_35 , V_392 ) ;
goto V_393;
}
return 0 ;
V_393:
F_260 ( & V_281 ) ;
V_390:
return V_233 ;
}
static void F_261 ( void )
{
F_262 ( & V_391 ) ;
F_260 ( & V_281 ) ;
}
struct V_69 * F_263 ( struct V_73 * V_73 )
{
struct V_32 * V_33 ;
if ( V_73 -> V_394 != & V_395 )
return F_132 ( - V_79 ) ;
V_33 = V_73 -> V_75 ;
if ( ! V_33 )
return F_132 ( - V_216 ) ;
return & V_33 -> V_69 ;
}
