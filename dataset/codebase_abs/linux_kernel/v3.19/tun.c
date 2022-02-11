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
F_13 ( V_10 -> V_16 ) ;
F_14 ( & V_10 -> V_17 ) ;
F_15 ( V_10 , V_19 ) ;
-- V_2 -> V_18 ;
}
static void F_16 ( struct V_1 * V_2 )
{
int V_20 ;
F_17 ( & V_2 -> V_21 ) ;
for ( V_20 = 0 ; V_20 < V_22 ; V_20 ++ ) {
struct V_7 * V_10 ;
struct V_23 * V_24 ;
F_18 (e, n, &tun->flows[i], hash_link)
F_12 ( V_2 , V_10 ) ;
}
F_19 ( & V_2 -> V_21 ) ;
}
static void F_20 ( struct V_1 * V_2 , T_1 V_11 )
{
int V_20 ;
F_17 ( & V_2 -> V_21 ) ;
for ( V_20 = 0 ; V_20 < V_22 ; V_20 ++ ) {
struct V_7 * V_10 ;
struct V_23 * V_24 ;
F_18 (e, n, &tun->flows[i], hash_link) {
if ( V_10 -> V_11 == V_11 )
F_12 ( V_2 , V_10 ) ;
}
}
F_19 ( & V_2 -> V_21 ) ;
}
static void F_21 ( unsigned long V_25 )
{
struct V_1 * V_2 = (struct V_1 * ) V_25 ;
unsigned long V_26 = V_2 -> V_27 ;
unsigned long V_28 = V_15 + V_26 ;
unsigned long V_29 = 0 ;
int V_20 ;
F_10 ( V_13 , V_2 , L_3 ) ;
F_17 ( & V_2 -> V_21 ) ;
for ( V_20 = 0 ; V_20 < V_22 ; V_20 ++ ) {
struct V_7 * V_10 ;
struct V_23 * V_24 ;
F_18 (e, n, &tun->flows[i], hash_link) {
unsigned long V_30 ;
V_29 ++ ;
V_30 = V_10 -> V_14 + V_26 ;
if ( F_22 ( V_30 , V_15 ) )
F_12 ( V_2 , V_10 ) ;
else if ( F_23 ( V_30 , V_28 ) )
V_28 = V_30 ;
}
}
if ( V_29 )
F_24 ( & V_2 -> V_31 , F_25 ( V_28 ) ) ;
F_19 ( & V_2 -> V_21 ) ;
}
static void F_26 ( struct V_1 * V_2 , T_3 V_6 ,
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
F_27 () ;
if ( V_2 -> V_35 == 1 || V_33 -> V_36 )
goto V_37;
V_10 = F_6 ( V_9 , V_6 ) ;
if ( F_28 ( V_10 ) ) {
V_10 -> V_11 = V_11 ;
V_10 -> V_14 = V_15 ;
F_29 ( V_10 -> V_16 ) ;
} else {
F_17 ( & V_2 -> V_21 ) ;
if ( ! F_6 ( V_9 , V_6 ) &&
V_2 -> V_18 < V_38 )
F_8 ( V_2 , V_9 , V_6 , V_11 ) ;
if ( ! F_30 ( & V_2 -> V_31 ) )
F_24 ( & V_2 -> V_31 ,
F_25 ( V_15 + V_26 ) ) ;
F_19 ( & V_2 -> V_21 ) ;
}
V_37:
F_31 () ;
}
static inline void F_32 ( struct V_7 * V_10 , T_3 V_39 )
{
if ( F_33 ( V_10 -> V_16 != V_39 ) ) {
F_13 ( V_10 -> V_16 ) ;
V_10 -> V_16 = V_39 ;
}
}
static T_1 F_34 ( struct V_40 * V_41 , struct V_42 * V_43 ,
void * V_44 , T_4 V_45 )
{
struct V_1 * V_2 = F_35 ( V_41 ) ;
struct V_7 * V_10 ;
T_3 V_46 = 0 ;
T_3 V_35 = 0 ;
F_27 () ;
V_35 = F_36 ( V_2 -> V_35 ) ;
V_46 = F_37 ( V_43 ) ;
if ( V_46 ) {
V_10 = F_6 ( & V_2 -> V_34 [ F_5 ( V_46 ) ] , V_46 ) ;
if ( V_10 ) {
F_32 ( V_10 , V_46 ) ;
V_46 = V_10 -> V_11 ;
} else
V_46 = ( ( V_47 ) V_46 * V_35 ) >> 32 ;
} else if ( F_28 ( F_38 ( V_43 ) ) ) {
V_46 = F_39 ( V_43 ) ;
while ( F_33 ( V_46 >= V_35 ) )
V_46 -= V_35 ;
}
F_31 () ;
return V_46 ;
}
static inline bool F_40 ( struct V_1 * V_2 )
{
const struct V_48 * V_48 = F_41 () ;
struct V_49 * V_49 = F_42 ( V_2 -> V_41 ) ;
return ( ( F_43 ( V_2 -> V_50 ) && ! F_44 ( V_48 -> V_51 , V_2 -> V_50 ) ) ||
( F_45 ( V_2 -> V_52 ) && ! F_46 ( V_2 -> V_52 ) ) ) &&
! F_47 ( V_49 -> V_53 , V_54 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
F_49 ( V_2 -> V_41 , V_2 -> V_35 ) ;
F_50 ( V_2 -> V_41 , V_2 -> V_35 ) ;
}
static void F_51 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
V_33 -> V_36 = V_2 ;
F_52 ( & V_33 -> V_55 , & V_2 -> V_56 ) ;
++ V_2 -> V_57 ;
}
static struct V_1 * F_53 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_36 ;
V_33 -> V_36 = NULL ;
F_54 ( & V_33 -> V_55 ) ;
-- V_2 -> V_57 ;
return V_2 ;
}
static void F_55 ( struct V_32 * V_33 )
{
F_56 ( & V_33 -> V_58 . V_59 ) ;
F_56 ( & V_33 -> V_58 . V_60 ) ;
}
static void F_57 ( struct V_32 * V_33 , bool V_61 )
{
struct V_32 * V_62 ;
struct V_1 * V_2 ;
V_2 = F_58 ( V_33 -> V_2 ) ;
if ( V_2 && ! V_33 -> V_36 ) {
T_1 V_63 = V_33 -> V_11 ;
F_59 ( V_63 >= V_2 -> V_35 ) ;
F_60 ( V_2 -> V_64 [ V_63 ] ,
V_2 -> V_64 [ V_2 -> V_35 - 1 ] ) ;
V_62 = F_58 ( V_2 -> V_64 [ V_63 ] ) ;
V_62 -> V_11 = V_63 ;
-- V_2 -> V_35 ;
if ( V_61 ) {
F_61 ( V_33 -> V_2 , NULL ) ;
F_62 ( & V_33 -> V_58 ) ;
} else
F_51 ( V_2 , V_33 ) ;
F_63 () ;
F_20 ( V_2 , V_2 -> V_35 + 1 ) ;
F_55 ( V_33 ) ;
F_48 ( V_2 ) ;
} else if ( V_33 -> V_36 && V_61 ) {
V_2 = F_53 ( V_33 ) ;
F_62 ( & V_33 -> V_58 ) ;
}
if ( V_61 ) {
if ( V_2 && V_2 -> V_35 == 0 && V_2 -> V_57 == 0 ) {
F_64 ( V_2 -> V_41 ) ;
if ( ! ( V_2 -> V_4 & V_65 ) &&
V_2 -> V_41 -> V_66 == V_67 )
F_65 ( V_2 -> V_41 ) ;
}
F_59 ( ! F_66 ( V_68 ,
& V_33 -> V_69 . V_4 ) ) ;
F_67 ( & V_33 -> V_58 ) ;
}
}
static void F_68 ( struct V_32 * V_33 , bool V_61 )
{
F_69 () ;
F_57 ( V_33 , V_61 ) ;
F_70 () ;
}
static void F_71 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = F_35 ( V_41 ) ;
struct V_32 * V_33 , * V_70 ;
int V_20 , V_24 = V_2 -> V_35 ;
for ( V_20 = 0 ; V_20 < V_24 ; V_20 ++ ) {
V_33 = F_58 ( V_2 -> V_64 [ V_20 ] ) ;
F_59 ( ! V_33 ) ;
V_33 -> V_69 . V_58 -> V_71 ( V_33 -> V_69 . V_58 ) ;
F_61 ( V_33 -> V_2 , NULL ) ;
-- V_2 -> V_35 ;
}
F_72 (tfile, &tun->disabled, next) {
V_33 -> V_69 . V_58 -> V_71 ( V_33 -> V_69 . V_58 ) ;
F_61 ( V_33 -> V_2 , NULL ) ;
}
F_59 ( V_2 -> V_35 != 0 ) ;
F_63 () ;
for ( V_20 = 0 ; V_20 < V_24 ; V_20 ++ ) {
V_33 = F_58 ( V_2 -> V_64 [ V_20 ] ) ;
F_55 ( V_33 ) ;
F_62 ( & V_33 -> V_58 ) ;
}
F_73 (tfile, tmp, &tun->disabled, next) {
F_53 ( V_33 ) ;
F_55 ( V_33 ) ;
F_62 ( & V_33 -> V_58 ) ;
}
F_59 ( V_2 -> V_57 != 0 ) ;
if ( V_2 -> V_4 & V_65 )
F_74 ( V_72 ) ;
}
static int F_75 ( struct V_1 * V_2 , struct V_73 * V_73 , bool V_74 )
{
struct V_32 * V_33 = V_73 -> V_75 ;
int V_76 ;
V_76 = F_76 ( V_33 -> V_69 . V_58 , V_2 -> V_77 ) ;
if ( V_76 < 0 )
goto V_78;
V_76 = - V_79 ;
if ( F_58 ( V_33 -> V_2 ) && ! V_33 -> V_36 )
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
V_76 = F_77 ( & V_2 -> V_85 , V_33 -> V_69 . V_58 ) ;
if ( ! V_76 )
goto V_78;
}
V_33 -> V_11 = V_2 -> V_35 ;
F_60 ( V_33 -> V_2 , V_2 ) ;
F_60 ( V_2 -> V_64 [ V_2 -> V_35 ] , V_33 ) ;
V_2 -> V_35 ++ ;
if ( V_33 -> V_36 )
F_53 ( V_33 ) ;
else
F_78 ( & V_33 -> V_58 ) ;
F_48 ( V_2 ) ;
V_78:
return V_76 ;
}
static struct V_1 * F_79 ( struct V_32 * V_33 )
{
struct V_1 * V_2 ;
F_27 () ;
V_2 = F_80 ( V_33 -> V_2 ) ;
if ( V_2 )
F_81 ( V_2 -> V_41 ) ;
F_31 () ;
return V_2 ;
}
static struct V_1 * F_82 ( struct V_73 * V_73 )
{
return F_79 ( V_73 -> V_75 ) ;
}
static void F_83 ( struct V_1 * V_2 )
{
F_84 ( V_2 -> V_41 ) ;
}
static void F_85 ( T_3 * V_86 , const T_5 * V_87 )
{
int V_24 = F_86 ( V_88 , V_87 ) >> 26 ;
V_86 [ V_24 >> 5 ] |= ( 1 << ( V_24 & 31 ) ) ;
}
static unsigned int F_87 ( const T_3 * V_86 , const T_5 * V_87 )
{
int V_24 = F_86 ( V_88 , V_87 ) >> 26 ;
return V_86 [ V_24 >> 5 ] & ( 1 << ( V_24 & 31 ) ) ;
}
static int F_88 ( struct V_89 * V_90 , void T_6 * V_91 )
{
struct { T_5 V_92 [ V_88 ] ; } * V_87 ;
struct V_93 V_94 ;
int V_76 , V_95 , V_24 , V_96 ;
if ( F_89 ( & V_94 , V_91 , sizeof( V_94 ) ) )
return - V_97 ;
if ( ! V_94 . V_29 ) {
V_90 -> V_29 = 0 ;
return 0 ;
}
V_95 = V_88 * V_94 . V_29 ;
V_87 = F_9 ( V_95 , V_98 ) ;
if ( ! V_87 )
return - V_99 ;
if ( F_89 ( V_87 , V_91 + sizeof( V_94 ) , V_95 ) ) {
V_76 = - V_97 ;
goto V_100;
}
V_90 -> V_29 = 0 ;
F_90 () ;
for ( V_24 = 0 ; V_24 < V_94 . V_29 && V_24 < V_101 ; V_24 ++ )
memcpy ( V_90 -> V_87 [ V_24 ] , V_87 [ V_24 ] . V_92 , V_88 ) ;
V_96 = V_24 ;
memset ( V_90 -> V_86 , 0 , sizeof( V_90 -> V_86 ) ) ;
for (; V_24 < V_94 . V_29 ; V_24 ++ ) {
if ( ! F_91 ( V_87 [ V_24 ] . V_92 ) ) {
V_76 = 0 ;
goto V_100;
}
F_85 ( V_90 -> V_86 , V_87 [ V_24 ] . V_92 ) ;
}
if ( ( V_94 . V_4 & V_102 ) )
memset ( V_90 -> V_86 , ~ 0 , sizeof( V_90 -> V_86 ) ) ;
F_90 () ;
V_90 -> V_29 = V_96 ;
V_76 = V_96 ;
V_100:
F_92 ( V_87 ) ;
return V_76 ;
}
static int F_93 ( struct V_89 * V_90 , const struct V_42 * V_43 )
{
struct V_103 * V_104 = (struct V_103 * ) V_43 -> V_25 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_90 -> V_29 ; V_20 ++ )
if ( F_94 ( V_104 -> V_105 , V_90 -> V_87 [ V_20 ] ) )
return 1 ;
if ( F_91 ( V_104 -> V_105 ) )
return F_87 ( V_90 -> V_86 , V_104 -> V_105 ) ;
return 0 ;
}
static int F_95 ( struct V_89 * V_90 , const struct V_42 * V_43 )
{
if ( ! V_90 -> V_29 )
return 1 ;
return F_93 ( V_90 , V_43 ) ;
}
static void F_96 ( struct V_40 * V_41 )
{
F_71 ( V_41 ) ;
}
static int F_97 ( struct V_40 * V_41 )
{
F_98 ( V_41 ) ;
return 0 ;
}
static int F_99 ( struct V_40 * V_41 )
{
F_100 ( V_41 ) ;
return 0 ;
}
static T_7 F_101 ( struct V_42 * V_43 , struct V_40 * V_41 )
{
struct V_1 * V_2 = F_35 ( V_41 ) ;
int V_46 = V_43 -> V_106 ;
struct V_32 * V_33 ;
T_3 V_35 = 0 ;
F_27 () ;
V_33 = F_80 ( V_2 -> V_64 [ V_46 ] ) ;
V_35 = F_36 ( V_2 -> V_35 ) ;
if ( V_46 >= V_35 )
goto V_107;
if ( V_35 == 1 ) {
T_8 V_6 ;
V_6 = F_37 ( V_43 ) ;
if ( V_6 ) {
struct V_7 * V_10 ;
V_10 = F_6 ( & V_2 -> V_34 [ F_5 ( V_6 ) ] ,
V_6 ) ;
if ( V_10 )
F_32 ( V_10 , V_6 ) ;
}
}
F_10 ( V_13 , V_2 , L_4 , V_43 -> V_108 ) ;
F_59 ( ! V_33 ) ;
if ( ! F_95 ( & V_2 -> V_109 , V_43 ) )
goto V_107;
if ( V_33 -> V_69 . V_58 -> V_110 &&
V_110 ( V_33 -> V_69 . V_58 , V_43 ) )
goto V_107;
if ( F_102 ( & V_33 -> V_69 . V_58 -> V_59 ) * V_35
>= V_41 -> V_111 )
goto V_107;
if ( F_33 ( F_103 ( V_43 , V_12 ) ) )
goto V_107;
if ( V_43 -> V_58 ) {
F_104 ( V_43 -> V_58 , & F_105 ( V_43 ) -> V_112 ) ;
F_106 ( V_43 ) ;
}
F_107 ( V_43 ) ;
F_108 ( V_43 ) ;
F_109 ( & V_33 -> V_69 . V_58 -> V_59 , V_43 ) ;
if ( V_33 -> V_4 & V_113 )
F_110 ( & V_33 -> V_114 , V_115 , V_116 ) ;
V_33 -> V_69 . V_58 -> V_71 ( V_33 -> V_69 . V_58 ) ;
F_31 () ;
return V_117 ;
V_107:
V_41 -> V_118 . V_119 ++ ;
F_111 ( V_43 ) ;
F_112 ( V_43 ) ;
F_31 () ;
return V_120 ;
}
static void F_113 ( struct V_40 * V_41 )
{
}
static int
F_114 ( struct V_40 * V_41 , int V_121 )
{
if ( V_121 < V_122 || V_121 + V_41 -> V_123 > V_124 )
return - V_79 ;
V_41 -> V_125 = V_121 ;
return 0 ;
}
static T_9 F_115 ( struct V_40 * V_41 ,
T_9 V_126 )
{
struct V_1 * V_2 = F_35 ( V_41 ) ;
return ( V_126 & V_2 -> V_127 ) | ( V_126 & ~ V_128 ) ;
}
static void F_116 ( struct V_40 * V_41 )
{
return;
}
static void F_117 ( struct V_1 * V_2 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_22 ; V_20 ++ )
F_118 ( & V_2 -> V_34 [ V_20 ] ) ;
V_2 -> V_27 = V_129 ;
F_119 ( & V_2 -> V_31 , F_21 , ( unsigned long ) V_2 ) ;
F_24 ( & V_2 -> V_31 ,
F_25 ( V_15 + V_2 -> V_27 ) ) ;
}
static void F_120 ( struct V_1 * V_2 )
{
F_121 ( & V_2 -> V_31 ) ;
F_16 ( V_2 ) ;
}
static void F_122 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = F_35 ( V_41 ) ;
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
F_123 ( V_41 ) ;
V_41 -> V_142 &= ~ V_143 ;
V_41 -> V_142 |= V_144 ;
F_124 ( V_41 ) ;
V_41 -> V_111 = V_139 ;
break;
}
}
static unsigned int F_125 ( struct V_73 * V_73 , T_10 * V_145 )
{
struct V_32 * V_33 = V_73 -> V_75 ;
struct V_1 * V_2 = F_79 ( V_33 ) ;
struct V_146 * V_58 ;
unsigned int V_86 = 0 ;
if ( ! V_2 )
return V_147 ;
V_58 = V_33 -> V_69 . V_58 ;
F_10 ( V_13 , V_2 , L_5 ) ;
F_126 ( V_73 , F_127 ( V_58 ) , V_145 ) ;
if ( ! F_128 ( & V_58 -> V_59 ) )
V_86 |= V_148 | V_149 ;
if ( F_129 ( V_58 ) ||
( ! F_130 ( V_150 , & V_58 -> V_151 -> V_4 ) &&
F_129 ( V_58 ) ) )
V_86 |= V_152 | V_153 ;
if ( V_2 -> V_41 -> V_66 != V_67 )
V_86 = V_147 ;
F_83 ( V_2 ) ;
return V_86 ;
}
static struct V_42 * F_131 ( struct V_32 * V_33 ,
T_11 V_154 , T_11 V_108 ,
T_11 V_155 , int V_156 )
{
struct V_146 * V_58 = V_33 -> V_69 . V_58 ;
struct V_42 * V_43 ;
int V_76 ;
if ( V_154 + V_108 < V_157 || ! V_155 )
V_155 = V_108 ;
V_43 = F_132 ( V_58 , V_154 + V_155 , V_108 - V_155 , V_156 ,
& V_76 , 0 ) ;
if ( ! V_43 )
return F_133 ( V_76 ) ;
F_134 ( V_43 , V_154 ) ;
F_135 ( V_43 , V_155 ) ;
V_43 -> V_158 = V_108 - V_155 ;
V_43 -> V_108 += V_108 - V_155 ;
return V_43 ;
}
static T_12 F_136 ( struct V_1 * V_2 , struct V_32 * V_33 ,
void * V_159 , struct V_160 * V_161 ,
int V_156 )
{
struct V_162 V_163 = { 0 , F_137 (ETH_P_IP) } ;
struct V_42 * V_43 ;
T_11 V_164 = F_138 ( V_161 ) ;
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
V_24 = F_139 ( & V_163 , sizeof( V_163 ) , V_161 ) ;
if ( V_24 != sizeof( V_163 ) )
return - V_97 ;
}
if ( V_2 -> V_4 & V_173 ) {
if ( V_108 < V_2 -> V_174 )
return - V_79 ;
V_108 -= V_2 -> V_174 ;
V_24 = F_139 ( & V_168 , sizeof( V_168 ) , V_161 ) ;
if ( V_24 != sizeof( V_168 ) )
return - V_97 ;
if ( ( V_168 . V_4 & V_175 ) &&
F_1 ( V_2 , V_168 . V_176 ) + F_1 ( V_2 , V_168 . V_177 ) + 2 > F_1 ( V_2 , V_168 . V_178 ) )
V_168 . V_178 = F_3 ( V_2 , F_1 ( V_2 , V_168 . V_176 ) + F_1 ( V_2 , V_168 . V_177 ) + 2 ) ;
if ( F_1 ( V_2 , V_168 . V_178 ) > V_108 )
return - V_79 ;
F_140 ( V_161 , V_2 -> V_174 - sizeof( V_168 ) ) ;
}
if ( ( V_2 -> V_4 & V_130 ) == V_140 ) {
V_165 += V_179 ;
if ( F_33 ( V_108 < V_180 ||
( V_168 . V_178 && F_1 ( V_2 , V_168 . V_178 ) < V_180 ) ) )
return - V_79 ;
}
V_169 = F_141 ( V_165 ) ;
if ( V_159 ) {
struct V_160 V_20 = * V_161 ;
V_170 = V_168 . V_178 ? F_1 ( V_2 , V_168 . V_178 ) : V_181 ;
if ( V_170 > V_169 )
V_170 = V_169 ;
V_155 = V_170 ;
F_140 ( & V_20 , V_170 ) ;
if ( F_142 ( & V_20 , V_182 ) <= V_183 )
V_171 = true ;
}
if ( ! V_171 ) {
V_170 = V_108 ;
if ( F_1 ( V_2 , V_168 . V_178 ) > V_169 )
V_155 = V_169 ;
else
V_155 = F_1 ( V_2 , V_168 . V_178 ) ;
}
V_43 = F_131 ( V_33 , V_165 , V_170 , V_155 , V_156 ) ;
if ( F_143 ( V_43 ) ) {
if ( F_144 ( V_43 ) != - V_184 )
V_2 -> V_41 -> V_118 . V_185 ++ ;
return F_144 ( V_43 ) ;
}
if ( V_171 )
V_76 = F_145 ( V_43 , V_161 ) ;
else {
V_76 = F_146 ( V_43 , 0 , V_161 , V_108 ) ;
if ( ! V_76 && V_159 ) {
struct V_186 * V_187 = V_159 ;
V_187 -> V_188 ( V_187 , false ) ;
}
}
if ( V_76 ) {
V_2 -> V_41 -> V_118 . V_185 ++ ;
F_112 ( V_43 ) ;
return - V_97 ;
}
if ( V_168 . V_4 & V_175 ) {
if ( ! F_147 ( V_43 , F_1 ( V_2 , V_168 . V_176 ) ,
F_1 ( V_2 , V_168 . V_177 ) ) ) {
V_2 -> V_41 -> V_118 . V_189 ++ ;
F_112 ( V_43 ) ;
return - V_79 ;
}
}
switch ( V_2 -> V_4 & V_130 ) {
case V_131 :
if ( V_2 -> V_4 & V_172 ) {
switch ( V_43 -> V_25 [ 0 ] & 0xf0 ) {
case 0x40 :
V_163 . V_190 = F_148 ( V_191 ) ;
break;
case 0x60 :
V_163 . V_190 = F_148 ( V_192 ) ;
break;
default:
V_2 -> V_41 -> V_118 . V_185 ++ ;
F_112 ( V_43 ) ;
return - V_79 ;
}
}
F_149 ( V_43 ) ;
V_43 -> V_193 = V_163 . V_190 ;
V_43 -> V_41 = V_2 -> V_41 ;
break;
case V_140 :
V_43 -> V_193 = F_150 ( V_43 , V_2 -> V_41 ) ;
break;
}
if ( V_168 . V_194 != V_195 ) {
F_151 ( L_6 ) ;
switch ( V_168 . V_194 & ~ V_196 ) {
case V_197 :
F_105 ( V_43 ) -> V_194 = V_198 ;
break;
case V_199 :
F_105 ( V_43 ) -> V_194 = V_200 ;
break;
case V_201 :
F_105 ( V_43 ) -> V_194 = V_202 ;
break;
default:
V_2 -> V_41 -> V_118 . V_189 ++ ;
F_112 ( V_43 ) ;
return - V_79 ;
}
if ( V_168 . V_194 & V_196 )
F_105 ( V_43 ) -> V_194 |= V_203 ;
F_105 ( V_43 ) -> V_204 = F_1 ( V_2 , V_168 . V_204 ) ;
if ( F_105 ( V_43 ) -> V_204 == 0 ) {
V_2 -> V_41 -> V_118 . V_189 ++ ;
F_112 ( V_43 ) ;
return - V_79 ;
}
F_105 ( V_43 ) -> V_194 |= V_205 ;
F_105 ( V_43 ) -> V_206 = 0 ;
}
if ( V_171 ) {
F_105 ( V_43 ) -> V_207 = V_159 ;
F_105 ( V_43 ) -> V_112 |= V_208 ;
F_105 ( V_43 ) -> V_112 |= V_209 ;
}
F_152 ( V_43 ) ;
F_153 ( V_43 , 0 ) ;
V_6 = F_37 ( V_43 ) ;
F_154 ( V_43 ) ;
V_2 -> V_41 -> V_118 . V_210 ++ ;
V_2 -> V_41 -> V_118 . V_211 += V_108 ;
F_26 ( V_2 , V_6 , V_33 ) ;
return V_164 ;
}
static T_12 F_155 ( struct V_212 * V_213 , struct V_160 * V_161 )
{
struct V_73 * V_73 = V_213 -> V_214 ;
struct V_1 * V_2 = F_82 ( V_73 ) ;
struct V_32 * V_33 = V_73 -> V_75 ;
T_12 V_215 ;
if ( ! V_2 )
return - V_216 ;
V_215 = F_136 ( V_2 , V_33 , NULL , V_161 , V_73 -> V_217 & V_218 ) ;
F_83 ( V_2 ) ;
return V_215 ;
}
static T_12 F_156 ( struct V_1 * V_2 ,
struct V_32 * V_33 ,
struct V_42 * V_43 ,
struct V_160 * V_219 )
{
struct V_162 V_163 = { 0 , V_43 -> V_193 } ;
T_12 V_220 ;
int V_221 = 0 ;
int V_222 = 0 ;
int V_174 = 0 ;
if ( F_157 ( V_43 ) )
V_222 = V_223 ;
if ( V_2 -> V_4 & V_173 )
V_174 = V_2 -> V_174 ;
V_220 = V_43 -> V_108 + V_222 + V_174 ;
if ( ! ( V_2 -> V_4 & V_172 ) ) {
if ( F_138 ( V_219 ) < sizeof( V_163 ) )
return - V_79 ;
V_220 += sizeof( V_163 ) ;
if ( F_138 ( V_219 ) < V_220 ) {
V_163 . V_4 |= V_224 ;
}
if ( F_158 ( & V_163 , sizeof( V_163 ) , V_219 ) != sizeof( V_163 ) )
return - V_97 ;
}
if ( V_174 ) {
struct V_167 V_168 = { 0 } ;
if ( F_138 ( V_219 ) < V_174 )
return - V_79 ;
if ( F_159 ( V_43 ) ) {
struct V_225 * V_226 = F_105 ( V_43 ) ;
V_168 . V_178 = F_3 ( V_2 , F_160 ( V_43 ) ) ;
V_168 . V_204 = F_3 ( V_2 , V_226 -> V_204 ) ;
if ( V_226 -> V_194 & V_198 )
V_168 . V_194 = V_197 ;
else if ( V_226 -> V_194 & V_200 )
V_168 . V_194 = V_199 ;
else if ( V_226 -> V_194 & V_202 )
V_168 . V_194 = V_201 ;
else {
F_161 ( L_7
L_8 ,
V_226 -> V_194 , F_1 ( V_2 , V_168 . V_204 ) ,
F_1 ( V_2 , V_168 . V_178 ) ) ;
F_162 ( V_227 , L_9 ,
V_228 ,
16 , 1 , V_43 -> V_9 ,
F_163 ( ( int ) F_1 ( V_2 , V_168 . V_178 ) , 64 ) , true ) ;
F_164 ( 1 ) ;
return - V_79 ;
}
if ( V_226 -> V_194 & V_203 )
V_168 . V_194 |= V_196 ;
} else
V_168 . V_194 = V_195 ;
if ( V_43 -> V_229 == V_230 ) {
V_168 . V_4 = V_175 ;
V_168 . V_176 = F_3 ( V_2 , F_165 ( V_43 ) +
V_222 ) ;
V_168 . V_177 = F_3 ( V_2 , V_43 -> V_177 ) ;
} else if ( V_43 -> V_229 == V_231 ) {
V_168 . V_4 = V_232 ;
}
if ( F_158 ( & V_168 , sizeof( V_168 ) , V_219 ) != sizeof( V_168 ) )
return - V_97 ;
F_140 ( V_219 , V_174 - sizeof( V_168 ) ) ;
}
if ( V_222 ) {
int V_233 ;
struct {
T_13 V_234 ;
T_13 V_235 ;
} V_236 ;
V_236 . V_234 = V_43 -> V_237 ;
V_236 . V_235 = F_148 ( F_166 ( V_43 ) ) ;
V_221 = F_167 ( struct V_238 , V_234 ) ;
V_233 = F_168 ( V_43 , 0 , V_219 , V_221 ) ;
if ( V_233 || ! F_138 ( V_219 ) )
goto V_100;
V_233 = F_158 ( & V_236 , sizeof( V_236 ) , V_219 ) ;
if ( V_233 != sizeof( V_236 ) || ! F_138 ( V_219 ) )
goto V_100;
}
F_168 ( V_43 , V_221 , V_219 , V_43 -> V_108 - V_221 ) ;
V_100:
V_2 -> V_41 -> V_118 . V_239 ++ ;
V_2 -> V_41 -> V_118 . V_240 += V_43 -> V_108 + V_222 ;
return V_220 ;
}
static T_12 F_169 ( struct V_1 * V_2 , struct V_32 * V_33 ,
struct V_160 * V_241 ,
int V_156 )
{
struct V_42 * V_43 ;
T_12 V_233 ;
int V_242 , V_76 , V_243 = 0 ;
F_10 ( V_13 , V_2 , L_10 ) ;
if ( ! F_138 ( V_241 ) )
return 0 ;
if ( V_2 -> V_41 -> V_66 != V_67 )
return - V_244 ;
V_43 = F_170 ( V_33 -> V_69 . V_58 , V_156 ? V_245 : 0 ,
& V_242 , & V_243 , & V_76 ) ;
if ( ! V_43 )
return 0 ;
V_233 = F_156 ( V_2 , V_33 , V_43 , V_241 ) ;
if ( F_33 ( V_233 < 0 ) )
F_112 ( V_43 ) ;
else
F_171 ( V_43 ) ;
return V_233 ;
}
static T_12 F_172 ( struct V_212 * V_213 , struct V_160 * V_241 )
{
struct V_73 * V_73 = V_213 -> V_214 ;
struct V_32 * V_33 = V_73 -> V_75 ;
struct V_1 * V_2 = F_79 ( V_33 ) ;
T_12 V_108 = F_138 ( V_241 ) , V_233 ;
if ( ! V_2 )
return - V_216 ;
V_233 = F_169 ( V_2 , V_33 , V_241 , V_73 -> V_217 & V_218 ) ;
V_233 = F_173 ( T_12 , V_233 , V_108 ) ;
if ( V_233 > 0 )
V_213 -> V_246 = V_233 ;
F_83 ( V_2 ) ;
return V_233 ;
}
static void F_174 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = F_35 ( V_41 ) ;
F_59 ( ! ( F_175 ( & V_2 -> V_56 ) ) ) ;
F_120 ( V_2 ) ;
F_176 ( V_2 -> V_77 ) ;
F_177 ( V_41 ) ;
}
static void F_178 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = F_35 ( V_41 ) ;
V_2 -> V_50 = V_247 ;
V_2 -> V_52 = V_248 ;
V_41 -> V_249 = & V_250 ;
V_41 -> V_251 = F_174 ;
}
static int F_179 ( struct V_252 * V_253 [] , struct V_252 * V_25 [] )
{
return - V_79 ;
}
static void F_180 ( struct V_146 * V_58 )
{
struct V_32 * V_33 ;
T_14 * V_254 ;
if ( ! F_129 ( V_58 ) )
return;
if ( ! F_181 ( V_150 , & V_58 -> V_151 -> V_4 ) )
return;
V_254 = F_127 ( V_58 ) ;
if ( V_254 && F_182 ( V_254 ) )
F_183 ( V_254 , V_152 |
V_153 | V_255 ) ;
V_33 = F_184 ( V_58 , struct V_32 , V_58 ) ;
F_110 ( & V_33 -> V_114 , V_115 , V_256 ) ;
}
static int F_185 ( struct V_212 * V_213 , struct V_69 * V_146 ,
struct V_257 * V_258 , T_11 V_164 )
{
int V_233 ;
struct V_32 * V_33 = F_184 ( V_146 , struct V_32 , V_69 ) ;
struct V_1 * V_2 = F_79 ( V_33 ) ;
if ( ! V_2 )
return - V_216 ;
V_233 = F_136 ( V_2 , V_33 , V_258 -> V_159 , & V_258 -> V_259 ,
V_258 -> V_260 & V_245 ) ;
F_83 ( V_2 ) ;
return V_233 ;
}
static int F_186 ( struct V_212 * V_213 , struct V_69 * V_146 ,
struct V_257 * V_258 , T_11 V_164 ,
int V_4 )
{
struct V_32 * V_33 = F_184 ( V_146 , struct V_32 , V_69 ) ;
struct V_1 * V_2 = F_79 ( V_33 ) ;
int V_233 ;
if ( ! V_2 )
return - V_216 ;
if ( V_4 & ~ ( V_245 | V_261 | V_262 ) ) {
V_233 = - V_79 ;
goto V_78;
}
if ( V_4 & V_262 ) {
V_233 = F_187 ( V_146 -> V_58 , V_258 , V_164 ,
V_263 , V_264 ) ;
goto V_78;
}
V_233 = F_169 ( V_2 , V_33 , & V_258 -> V_259 , V_4 & V_245 ) ;
if ( V_233 > V_164 ) {
V_258 -> V_260 |= V_261 ;
V_233 = V_4 & V_261 ? V_233 : V_164 ;
}
V_78:
F_83 ( V_2 ) ;
return V_233 ;
}
static int F_188 ( struct V_69 * V_146 )
{
if ( V_146 -> V_58 )
F_62 ( V_146 -> V_58 ) ;
return 0 ;
}
static int F_189 ( struct V_1 * V_2 )
{
return V_2 -> V_4 & ( V_265 | V_65 | V_131 | V_140 ) ;
}
static T_12 F_190 ( struct V_266 * V_41 , struct V_267 * V_268 ,
char * V_269 )
{
struct V_1 * V_2 = F_35 ( F_191 ( V_41 ) ) ;
return sprintf ( V_269 , L_11 , F_189 ( V_2 ) ) ;
}
static T_12 F_192 ( struct V_266 * V_41 , struct V_267 * V_268 ,
char * V_269 )
{
struct V_1 * V_2 = F_35 ( F_191 ( V_41 ) ) ;
return F_43 ( V_2 -> V_50 ) ?
sprintf ( V_269 , L_12 ,
F_193 ( F_194 () , V_2 -> V_50 ) ) :
sprintf ( V_269 , L_13 ) ;
}
static T_12 F_195 ( struct V_266 * V_41 , struct V_267 * V_268 ,
char * V_269 )
{
struct V_1 * V_2 = F_35 ( F_191 ( V_41 ) ) ;
return F_45 ( V_2 -> V_52 ) ?
sprintf ( V_269 , L_12 ,
F_196 ( F_194 () , V_2 -> V_52 ) ) :
sprintf ( V_269 , L_13 ) ;
}
static int F_197 ( struct V_49 * V_49 , struct V_73 * V_73 , struct V_270 * V_271 )
{
struct V_1 * V_2 ;
struct V_32 * V_33 = V_73 -> V_75 ;
struct V_40 * V_41 ;
int V_76 ;
if ( V_33 -> V_36 )
return - V_79 ;
V_41 = F_198 ( V_49 , V_271 -> V_272 ) ;
if ( V_41 ) {
if ( V_271 -> V_273 & V_274 )
return - V_80 ;
if ( ( V_271 -> V_273 & V_131 ) && V_41 -> V_132 == & V_133 )
V_2 = F_35 ( V_41 ) ;
else if ( ( V_271 -> V_273 & V_140 ) && V_41 -> V_132 == & V_141 )
V_2 = F_35 ( V_41 ) ;
else
return - V_79 ;
if ( ! ! ( V_271 -> V_273 & V_81 ) !=
! ! ( V_2 -> V_4 & V_81 ) )
return - V_79 ;
if ( F_40 ( V_2 ) )
return - V_275 ;
V_76 = F_199 ( V_2 -> V_77 ) ;
if ( V_76 < 0 )
return V_76 ;
V_76 = F_75 ( V_2 , V_73 , V_271 -> V_273 & V_276 ) ;
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
if ( ! F_47 ( V_49 -> V_53 , V_54 ) )
return - V_275 ;
V_76 = F_200 () ;
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
V_41 = F_201 ( sizeof( struct V_1 ) , V_277 ,
V_279 , F_178 , V_278 ,
V_278 ) ;
if ( ! V_41 )
return - V_99 ;
F_202 ( V_41 , V_49 ) ;
V_41 -> V_280 = & V_281 ;
V_41 -> V_282 = V_33 -> V_282 ;
V_2 = F_35 ( V_41 ) ;
V_2 -> V_41 = V_41 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_109 . V_29 = 0 ;
V_2 -> V_174 = sizeof( struct V_167 ) ;
V_2 -> V_84 = false ;
V_2 -> V_283 = V_33 -> V_69 . V_58 -> V_284 ;
F_203 ( & V_2 -> V_21 ) ;
V_76 = F_204 ( & V_2 -> V_77 ) ;
if ( V_76 < 0 )
goto V_285;
F_122 ( V_41 ) ;
F_117 ( V_2 ) ;
V_41 -> V_286 = V_287 | V_288 |
V_128 | V_289 |
V_290 ;
V_41 -> V_126 = V_41 -> V_286 ;
V_41 -> V_291 = V_41 -> V_126 &
~ ( V_289 |
V_290 ) ;
F_205 ( & V_2 -> V_56 ) ;
V_76 = F_75 ( V_2 , V_73 , false ) ;
if ( V_76 < 0 )
goto V_292;
V_76 = F_206 ( V_2 -> V_41 ) ;
if ( V_76 < 0 )
goto V_293;
if ( F_207 ( & V_2 -> V_41 -> V_41 , & V_294 ) ||
F_207 ( & V_2 -> V_41 -> V_41 , & V_295 ) ||
F_207 ( & V_2 -> V_41 -> V_41 , & V_296 ) )
F_161 ( L_16 ) ;
}
F_208 ( V_2 -> V_41 ) ;
F_10 ( V_13 , V_2 , L_17 ) ;
V_2 -> V_4 = ( V_2 -> V_4 & ~ V_265 ) |
( V_271 -> V_273 & V_265 ) ;
if ( F_209 ( V_2 -> V_41 ) )
F_210 ( V_2 -> V_41 ) ;
strcpy ( V_271 -> V_272 , V_2 -> V_41 -> V_277 ) ;
return 0 ;
V_293:
F_71 ( V_41 ) ;
V_292:
F_120 ( V_2 ) ;
F_176 ( V_2 -> V_77 ) ;
V_285:
F_177 ( V_41 ) ;
return V_76 ;
}
static void F_211 ( struct V_49 * V_49 , struct V_1 * V_2 ,
struct V_270 * V_271 )
{
F_10 ( V_13 , V_2 , L_18 ) ;
strcpy ( V_271 -> V_272 , V_2 -> V_41 -> V_277 ) ;
V_271 -> V_273 = F_189 ( V_2 ) ;
}
static int F_212 ( struct V_1 * V_2 , unsigned long V_91 )
{
T_9 V_126 = 0 ;
if ( V_91 & V_297 ) {
V_126 |= V_298 ;
V_91 &= ~ V_297 ;
if ( V_91 & ( V_299 | V_300 ) ) {
if ( V_91 & V_301 ) {
V_126 |= V_302 ;
V_91 &= ~ V_301 ;
}
if ( V_91 & V_299 )
V_126 |= V_303 ;
if ( V_91 & V_300 )
V_126 |= V_304 ;
V_91 &= ~ ( V_299 | V_300 ) ;
}
if ( V_91 & V_305 ) {
V_126 |= V_306 ;
V_91 &= ~ V_305 ;
}
}
if ( V_91 )
return - V_79 ;
V_2 -> V_127 = V_126 ;
F_213 ( V_2 -> V_41 ) ;
return 0 ;
}
static void F_214 ( struct V_1 * V_2 , int V_24 )
{
int V_20 ;
struct V_32 * V_33 ;
for ( V_20 = 0 ; V_20 < V_24 ; V_20 ++ ) {
V_33 = F_58 ( V_2 -> V_64 [ V_20 ] ) ;
F_215 ( V_33 -> V_69 . V_58 ) ;
}
V_2 -> V_84 = false ;
}
static int F_216 ( struct V_1 * V_2 )
{
int V_20 , V_233 = 0 ;
struct V_32 * V_33 ;
for ( V_20 = 0 ; V_20 < V_2 -> V_35 ; V_20 ++ ) {
V_33 = F_58 ( V_2 -> V_64 [ V_20 ] ) ;
V_233 = F_77 ( & V_2 -> V_85 , V_33 -> V_69 . V_58 ) ;
if ( V_233 ) {
F_214 ( V_2 , V_20 ) ;
return V_233 ;
}
}
V_2 -> V_84 = true ;
return V_233 ;
}
static void F_217 ( struct V_1 * V_2 )
{
struct V_32 * V_33 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_2 -> V_35 ; V_20 ++ ) {
V_33 = F_58 ( V_2 -> V_64 [ V_20 ] ) ;
V_33 -> V_69 . V_58 -> V_284 = V_2 -> V_283 ;
}
}
static int F_218 ( struct V_73 * V_73 , struct V_270 * V_271 )
{
struct V_32 * V_33 = V_73 -> V_75 ;
struct V_1 * V_2 ;
int V_233 = 0 ;
F_69 () ;
if ( V_271 -> V_273 & V_307 ) {
V_2 = V_33 -> V_36 ;
if ( ! V_2 ) {
V_233 = - V_79 ;
goto V_37;
}
V_233 = F_219 ( V_2 -> V_77 ) ;
if ( V_233 < 0 )
goto V_37;
V_233 = F_75 ( V_2 , V_73 , false ) ;
} else if ( V_271 -> V_273 & V_308 ) {
V_2 = F_58 ( V_33 -> V_2 ) ;
if ( ! V_2 || ! ( V_2 -> V_4 & V_81 ) || V_33 -> V_36 )
V_233 = - V_79 ;
else
F_57 ( V_33 , false ) ;
} else
V_233 = - V_79 ;
V_37:
F_70 () ;
return V_233 ;
}
static long F_220 ( struct V_73 * V_73 , unsigned int V_309 ,
unsigned long V_91 , int V_310 )
{
struct V_32 * V_33 = V_73 -> V_75 ;
struct V_1 * V_2 ;
void T_6 * V_311 = ( void T_6 * ) V_91 ;
struct V_270 V_271 ;
T_15 V_50 ;
T_16 V_52 ;
int V_283 ;
int V_174 ;
unsigned int V_282 ;
int V_312 ;
int V_233 ;
if ( V_309 == V_313 || V_309 == V_314 || F_221 ( V_309 ) == 0x89 ) {
if ( F_89 ( & V_271 , V_311 , V_310 ) )
return - V_97 ;
} else {
memset ( & V_271 , 0 , sizeof( V_271 ) ) ;
}
if ( V_309 == V_315 ) {
return F_222 ( V_131 | V_140 | V_265 ,
( unsigned int T_6 * ) V_311 ) ;
} else if ( V_309 == V_314 )
return F_218 ( V_73 , & V_271 ) ;
V_233 = 0 ;
F_69 () ;
V_2 = F_79 ( V_33 ) ;
if ( V_309 == V_313 && ! V_2 ) {
V_271 . V_272 [ V_316 - 1 ] = '\0' ;
V_233 = F_197 ( V_33 -> V_49 , V_73 , & V_271 ) ;
if ( V_233 )
goto V_37;
if ( F_223 ( V_311 , & V_271 , V_310 ) )
V_233 = - V_97 ;
goto V_37;
}
if ( V_309 == V_317 ) {
V_233 = - V_275 ;
if ( V_2 )
goto V_37;
V_233 = - V_97 ;
if ( F_89 ( & V_282 , V_311 , sizeof( V_282 ) ) )
goto V_37;
V_233 = 0 ;
V_33 -> V_282 = V_282 ;
goto V_37;
}
V_233 = - V_216 ;
if ( ! V_2 )
goto V_37;
F_10 ( V_13 , V_2 , L_19 , V_309 ) ;
V_233 = 0 ;
switch ( V_309 ) {
case V_318 :
F_211 ( V_319 -> V_320 -> V_321 , V_2 , & V_271 ) ;
if ( V_33 -> V_36 )
V_271 . V_273 |= V_308 ;
if ( ! V_33 -> V_69 . V_58 -> V_110 )
V_271 . V_273 |= V_276 ;
if ( F_223 ( V_311 , & V_271 , V_310 ) )
V_233 = - V_97 ;
break;
case V_322 :
F_10 ( V_13 , V_2 , L_20 ,
V_91 ? L_21 : L_22 ) ;
break;
case V_323 :
if ( V_91 && ! ( V_2 -> V_4 & V_65 ) ) {
V_2 -> V_4 |= V_65 ;
F_224 ( V_72 ) ;
}
if ( ! V_91 && ( V_2 -> V_4 & V_65 ) ) {
V_2 -> V_4 &= ~ V_65 ;
F_74 ( V_72 ) ;
}
F_10 ( V_13 , V_2 , L_23 ,
V_91 ? L_22 : L_21 ) ;
break;
case V_324 :
V_50 = F_225 ( F_194 () , V_91 ) ;
if ( ! F_43 ( V_50 ) ) {
V_233 = - V_79 ;
break;
}
V_2 -> V_50 = V_50 ;
F_10 ( V_13 , V_2 , L_24 ,
F_226 ( & V_325 , V_2 -> V_50 ) ) ;
break;
case V_326 :
V_52 = F_227 ( F_194 () , V_91 ) ;
if ( ! F_45 ( V_52 ) ) {
V_233 = - V_79 ;
break;
}
V_2 -> V_52 = V_52 ;
F_10 ( V_13 , V_2 , L_25 ,
F_228 ( & V_325 , V_2 -> V_52 ) ) ;
break;
case V_327 :
if ( V_2 -> V_41 -> V_4 & V_328 ) {
F_10 ( V_13 , V_2 ,
L_26 ) ;
V_233 = - V_80 ;
} else {
V_2 -> V_41 -> type = ( int ) V_91 ;
F_10 ( V_13 , V_2 , L_27 ,
V_2 -> V_41 -> type ) ;
V_233 = 0 ;
}
break;
#ifdef F_229
case V_329 :
V_2 -> V_330 = V_91 ;
break;
#endif
case V_331 :
V_233 = F_212 ( V_2 , V_91 ) ;
break;
case V_332 :
V_233 = - V_79 ;
if ( ( V_2 -> V_4 & V_130 ) != V_140 )
break;
V_233 = F_88 ( & V_2 -> V_109 , ( void T_6 * ) V_91 ) ;
break;
case V_333 :
memcpy ( V_271 . V_334 . V_335 , V_2 -> V_41 -> V_336 , V_88 ) ;
V_271 . V_334 . V_337 = V_2 -> V_41 -> type ;
if ( F_223 ( V_311 , & V_271 , V_310 ) )
V_233 = - V_97 ;
break;
case V_338 :
F_10 ( V_339 , V_2 , L_28 ,
V_271 . V_334 . V_335 ) ;
V_233 = F_230 ( V_2 -> V_41 , & V_271 . V_334 ) ;
break;
case V_340 :
V_283 = V_33 -> V_69 . V_58 -> V_284 ;
if ( F_223 ( V_311 , & V_283 , sizeof( V_283 ) ) )
V_233 = - V_97 ;
break;
case V_341 :
if ( F_89 ( & V_283 , V_311 , sizeof( V_283 ) ) ) {
V_233 = - V_97 ;
break;
}
V_2 -> V_283 = V_283 ;
F_217 ( V_2 ) ;
break;
case V_342 :
V_174 = V_2 -> V_174 ;
if ( F_223 ( V_311 , & V_174 , sizeof( V_174 ) ) )
V_233 = - V_97 ;
break;
case V_343 :
if ( F_89 ( & V_174 , V_311 , sizeof( V_174 ) ) ) {
V_233 = - V_97 ;
break;
}
if ( V_174 < ( int ) sizeof( struct V_167 ) ) {
V_233 = - V_79 ;
break;
}
V_2 -> V_174 = V_174 ;
break;
case V_344 :
V_312 = ! ! ( V_2 -> V_4 & V_5 ) ;
if ( F_222 ( V_312 , ( int T_6 * ) V_311 ) )
V_233 = - V_97 ;
break;
case V_345 :
if ( F_231 ( V_312 , ( int T_6 * ) V_311 ) ) {
V_233 = - V_97 ;
break;
}
if ( V_312 )
V_2 -> V_4 |= V_5 ;
else
V_2 -> V_4 &= ~ V_5 ;
break;
case V_346 :
V_233 = - V_79 ;
if ( ( V_2 -> V_4 & V_130 ) != V_140 )
break;
V_233 = - V_97 ;
if ( F_89 ( & V_2 -> V_85 , V_311 , sizeof( V_2 -> V_85 ) ) )
break;
V_233 = F_216 ( V_2 ) ;
break;
case V_347 :
V_233 = - V_79 ;
if ( ( V_2 -> V_4 & V_130 ) != V_140 )
break;
V_233 = 0 ;
F_214 ( V_2 , V_2 -> V_35 ) ;
break;
case V_348 :
V_233 = - V_79 ;
if ( ( V_2 -> V_4 & V_130 ) != V_140 )
break;
V_233 = - V_97 ;
if ( F_223 ( V_311 , & V_2 -> V_85 , sizeof( V_2 -> V_85 ) ) )
break;
V_233 = 0 ;
break;
default:
V_233 = - V_79 ;
break;
}
V_37:
F_70 () ;
if ( V_2 )
F_83 ( V_2 ) ;
return V_233 ;
}
static long F_232 ( struct V_73 * V_73 ,
unsigned int V_309 , unsigned long V_91 )
{
return F_220 ( V_73 , V_309 , V_91 , sizeof ( struct V_270 ) ) ;
}
static long F_233 ( struct V_73 * V_73 ,
unsigned int V_309 , unsigned long V_91 )
{
switch ( V_309 ) {
case V_313 :
case V_318 :
case V_332 :
case V_340 :
case V_341 :
case V_333 :
case V_338 :
V_91 = ( unsigned long ) F_234 ( V_91 ) ;
break;
default:
V_91 = ( V_349 ) V_91 ;
break;
}
return F_220 ( V_73 , V_309 , V_91 , sizeof( struct V_350 ) ) ;
}
static int F_235 ( int V_351 , struct V_73 * V_73 , int V_352 )
{
struct V_32 * V_33 = V_73 -> V_75 ;
int V_233 ;
if ( ( V_233 = F_236 ( V_351 , V_73 , V_352 , & V_33 -> V_114 ) ) < 0 )
goto V_78;
if ( V_352 ) {
F_237 ( V_73 , F_238 ( V_319 ) , V_353 , 0 ) ;
V_33 -> V_4 |= V_113 ;
} else
V_33 -> V_4 &= ~ V_113 ;
V_233 = 0 ;
V_78:
return V_233 ;
}
static int F_239 ( struct V_354 * V_354 , struct V_73 * V_73 )
{
struct V_32 * V_33 ;
F_240 ( V_13 , L_29 ) ;
V_33 = (struct V_32 * ) F_241 ( & V_355 , V_356 , V_98 ,
& V_357 ) ;
if ( ! V_33 )
return - V_99 ;
F_61 ( V_33 -> V_2 , NULL ) ;
V_33 -> V_49 = F_242 ( V_319 -> V_320 -> V_321 ) ;
V_33 -> V_4 = 0 ;
V_33 -> V_282 = 0 ;
F_243 ( & V_33 -> V_358 . V_145 ) ;
F_61 ( V_33 -> V_69 . V_358 , & V_33 -> V_358 ) ;
V_33 -> V_69 . V_73 = V_73 ;
V_33 -> V_69 . V_359 = & V_360 ;
F_244 ( & V_33 -> V_69 , & V_33 -> V_58 ) ;
F_245 ( & V_33 -> V_58 , V_33 -> V_49 ) ;
V_33 -> V_58 . V_361 = F_180 ;
V_33 -> V_58 . V_284 = V_182 ;
V_73 -> V_75 = V_33 ;
F_246 ( V_68 , & V_33 -> V_69 . V_4 ) ;
F_205 ( & V_33 -> V_55 ) ;
F_247 ( & V_33 -> V_58 , V_362 ) ;
return 0 ;
}
static int F_248 ( struct V_354 * V_354 , struct V_73 * V_73 )
{
struct V_32 * V_33 = V_73 -> V_75 ;
struct V_49 * V_49 = V_33 -> V_49 ;
F_68 ( V_33 , true ) ;
F_249 ( V_49 ) ;
return 0 ;
}
static void F_250 ( struct V_363 * V_258 , struct V_73 * V_364 )
{
struct V_1 * V_2 ;
struct V_270 V_271 ;
memset ( & V_271 , 0 , sizeof( V_271 ) ) ;
F_69 () ;
V_2 = F_82 ( V_364 ) ;
if ( V_2 )
F_211 ( V_319 -> V_320 -> V_321 , V_2 , & V_271 ) ;
F_70 () ;
if ( V_2 )
F_83 ( V_2 ) ;
F_251 ( V_258 , L_30 , V_271 . V_272 ) ;
}
static int F_252 ( struct V_40 * V_41 , struct V_365 * V_309 )
{
V_309 -> V_366 = 0 ;
V_309 -> V_367 = 0 ;
F_253 ( V_309 , V_368 ) ;
V_309 -> V_369 = V_370 ;
V_309 -> V_371 = V_372 ;
V_309 -> V_373 = 0 ;
V_309 -> V_374 = V_375 ;
V_309 -> V_376 = V_377 ;
V_309 -> V_378 = 0 ;
V_309 -> V_379 = 0 ;
return 0 ;
}
static void F_254 ( struct V_40 * V_41 , struct V_380 * V_381 )
{
struct V_1 * V_2 = F_35 ( V_41 ) ;
F_255 ( V_381 -> V_382 , V_383 , sizeof( V_381 -> V_382 ) ) ;
F_255 ( V_381 -> V_384 , V_385 , sizeof( V_381 -> V_384 ) ) ;
switch ( V_2 -> V_4 & V_130 ) {
case V_131 :
F_255 ( V_381 -> V_386 , L_31 , sizeof( V_381 -> V_386 ) ) ;
break;
case V_140 :
F_255 ( V_381 -> V_386 , L_32 , sizeof( V_381 -> V_386 ) ) ;
break;
}
}
static T_3 F_256 ( struct V_40 * V_41 )
{
#ifdef F_229
struct V_1 * V_2 = F_35 ( V_41 ) ;
return V_2 -> V_330 ;
#else
return - V_387 ;
#endif
}
static void F_257 ( struct V_40 * V_41 , T_3 V_388 )
{
#ifdef F_229
struct V_1 * V_2 = F_35 ( V_41 ) ;
V_2 -> V_330 = V_388 ;
#endif
}
static int T_17 F_258 ( void )
{
int V_233 = 0 ;
F_259 ( L_33 , V_389 , V_385 ) ;
F_259 ( L_34 , V_390 ) ;
V_233 = F_260 ( & V_281 ) ;
if ( V_233 ) {
F_161 ( L_35 ) ;
goto V_391;
}
V_233 = F_261 ( & V_392 ) ;
if ( V_233 ) {
F_161 ( L_36 , V_393 ) ;
goto V_394;
}
return 0 ;
V_394:
F_262 ( & V_281 ) ;
V_391:
return V_233 ;
}
static void F_263 ( void )
{
F_264 ( & V_392 ) ;
F_262 ( & V_281 ) ;
}
struct V_69 * F_265 ( struct V_73 * V_73 )
{
struct V_32 * V_33 ;
if ( V_73 -> V_395 != & V_396 )
return F_133 ( - V_79 ) ;
V_33 = V_73 -> V_75 ;
if ( ! V_33 )
return F_133 ( - V_216 ) ;
return & V_33 -> V_69 ;
}
