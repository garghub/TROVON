static inline T_1 F_1 ( T_1 V_1 )
{
return V_1 & 0x3ff ;
}
static struct V_2 * F_2 ( struct V_3 * V_4 , T_1 V_1 )
{
struct V_2 * V_5 ;
F_3 (e, head, hash_link) {
if ( V_5 -> V_1 == V_1 )
return V_5 ;
}
return NULL ;
}
static struct V_2 * F_4 ( struct V_6 * V_7 ,
struct V_3 * V_4 ,
T_1 V_1 , T_2 V_8 )
{
struct V_2 * V_5 = F_5 ( sizeof( * V_5 ) , V_9 ) ;
if ( V_5 ) {
F_6 ( V_10 , V_7 , L_1 ,
V_1 , V_8 ) ;
V_5 -> V_11 = V_12 ;
V_5 -> V_1 = V_1 ;
V_5 -> V_13 = 0 ;
V_5 -> V_8 = V_8 ;
V_5 -> V_7 = V_7 ;
F_7 ( & V_5 -> V_14 , V_4 ) ;
++ V_7 -> V_15 ;
}
return V_5 ;
}
static void F_8 ( struct V_6 * V_7 , struct V_2 * V_5 )
{
F_6 ( V_10 , V_7 , L_2 ,
V_5 -> V_1 , V_5 -> V_8 ) ;
F_9 ( V_5 -> V_13 ) ;
F_10 ( & V_5 -> V_14 ) ;
F_11 ( V_5 , V_16 ) ;
-- V_7 -> V_15 ;
}
static void F_12 ( struct V_6 * V_7 )
{
int V_17 ;
F_13 ( & V_7 -> V_18 ) ;
for ( V_17 = 0 ; V_17 < V_19 ; V_17 ++ ) {
struct V_2 * V_5 ;
struct V_20 * V_21 ;
F_14 (e, n, &tun->flows[i], hash_link)
F_8 ( V_7 , V_5 ) ;
}
F_15 ( & V_7 -> V_18 ) ;
}
static void F_16 ( struct V_6 * V_7 , T_2 V_8 )
{
int V_17 ;
F_13 ( & V_7 -> V_18 ) ;
for ( V_17 = 0 ; V_17 < V_19 ; V_17 ++ ) {
struct V_2 * V_5 ;
struct V_20 * V_21 ;
F_14 (e, n, &tun->flows[i], hash_link) {
if ( V_5 -> V_8 == V_8 )
F_8 ( V_7 , V_5 ) ;
}
}
F_15 ( & V_7 -> V_18 ) ;
}
static void F_17 ( unsigned long V_22 )
{
struct V_6 * V_7 = (struct V_6 * ) V_22 ;
unsigned long V_23 = V_7 -> V_24 ;
unsigned long V_25 = V_12 + V_23 ;
unsigned long V_26 = 0 ;
int V_17 ;
F_6 ( V_10 , V_7 , L_3 ) ;
F_13 ( & V_7 -> V_18 ) ;
for ( V_17 = 0 ; V_17 < V_19 ; V_17 ++ ) {
struct V_2 * V_5 ;
struct V_20 * V_21 ;
F_14 (e, n, &tun->flows[i], hash_link) {
unsigned long V_27 ;
V_26 ++ ;
V_27 = V_5 -> V_11 + V_23 ;
if ( F_18 ( V_27 , V_12 ) )
F_8 ( V_7 , V_5 ) ;
else if ( F_19 ( V_27 , V_25 ) )
V_25 = V_27 ;
}
}
if ( V_26 )
F_20 ( & V_7 -> V_28 , F_21 ( V_25 ) ) ;
F_15 ( & V_7 -> V_18 ) ;
}
static void F_22 ( struct V_6 * V_7 , T_1 V_1 ,
struct V_29 * V_30 )
{
struct V_3 * V_4 ;
struct V_2 * V_5 ;
unsigned long V_23 = V_7 -> V_24 ;
T_2 V_8 = V_30 -> V_8 ;
if ( ! V_1 )
return;
else
V_4 = & V_7 -> V_31 [ F_1 ( V_1 ) ] ;
F_23 () ;
if ( V_7 -> V_32 == 1 || V_30 -> V_33 )
goto V_34;
V_5 = F_2 ( V_4 , V_1 ) ;
if ( F_24 ( V_5 ) ) {
V_5 -> V_8 = V_8 ;
V_5 -> V_11 = V_12 ;
F_25 ( V_5 -> V_13 ) ;
} else {
F_13 ( & V_7 -> V_18 ) ;
if ( ! F_2 ( V_4 , V_1 ) &&
V_7 -> V_15 < V_35 )
F_4 ( V_7 , V_4 , V_1 , V_8 ) ;
if ( ! F_26 ( & V_7 -> V_28 ) )
F_20 ( & V_7 -> V_28 ,
F_21 ( V_12 + V_23 ) ) ;
F_15 ( & V_7 -> V_18 ) ;
}
V_34:
F_27 () ;
}
static inline void F_28 ( struct V_2 * V_5 , T_1 V_36 )
{
if ( F_29 ( V_5 -> V_13 != V_36 ) ) {
F_9 ( V_5 -> V_13 ) ;
V_5 -> V_13 = V_36 ;
}
}
static T_2 F_30 ( struct V_37 * V_38 , struct V_39 * V_40 ,
void * V_41 , T_3 V_42 )
{
struct V_6 * V_7 = F_31 ( V_38 ) ;
struct V_2 * V_5 ;
T_1 V_43 = 0 ;
T_1 V_32 = 0 ;
F_23 () ;
V_32 = F_32 ( V_7 -> V_32 ) ;
V_43 = F_33 ( V_40 ) ;
if ( V_43 ) {
V_5 = F_2 ( & V_7 -> V_31 [ F_1 ( V_43 ) ] , V_43 ) ;
if ( V_5 ) {
F_28 ( V_5 , V_43 ) ;
V_43 = V_5 -> V_8 ;
} else
V_43 = ( ( V_44 ) V_43 * V_32 ) >> 32 ;
} else if ( F_24 ( F_34 ( V_40 ) ) ) {
V_43 = F_35 ( V_40 ) ;
while ( F_29 ( V_43 >= V_32 ) )
V_43 -= V_32 ;
}
F_27 () ;
return V_43 ;
}
static inline bool F_36 ( struct V_6 * V_7 )
{
const struct V_45 * V_45 = F_37 () ;
struct V_46 * V_46 = F_38 ( V_7 -> V_38 ) ;
return ( ( F_39 ( V_7 -> V_47 ) && ! F_40 ( V_45 -> V_48 , V_7 -> V_47 ) ) ||
( F_41 ( V_7 -> V_49 ) && ! F_42 ( V_7 -> V_49 ) ) ) &&
! F_43 ( V_46 -> V_50 , V_51 ) ;
}
static void F_44 ( struct V_6 * V_7 )
{
F_45 ( V_7 -> V_38 , V_7 -> V_32 ) ;
F_46 ( V_7 -> V_38 , V_7 -> V_32 ) ;
}
static void F_47 ( struct V_6 * V_7 , struct V_29 * V_30 )
{
V_30 -> V_33 = V_7 ;
F_48 ( & V_30 -> V_52 , & V_7 -> V_53 ) ;
++ V_7 -> V_54 ;
}
static struct V_6 * F_49 ( struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_33 ;
V_30 -> V_33 = NULL ;
F_50 ( & V_30 -> V_52 ) ;
-- V_7 -> V_54 ;
return V_7 ;
}
static void F_51 ( struct V_29 * V_30 )
{
F_52 ( & V_30 -> V_55 . V_56 ) ;
F_52 ( & V_30 -> V_55 . V_57 ) ;
}
static void F_53 ( struct V_29 * V_30 , bool V_58 )
{
struct V_29 * V_59 ;
struct V_6 * V_7 ;
V_7 = F_54 ( V_30 -> V_7 ) ;
if ( V_7 && ! V_30 -> V_33 ) {
T_2 V_60 = V_30 -> V_8 ;
F_55 ( V_60 >= V_7 -> V_32 ) ;
F_56 ( V_7 -> V_61 [ V_60 ] ,
V_7 -> V_61 [ V_7 -> V_32 - 1 ] ) ;
V_59 = F_54 ( V_7 -> V_61 [ V_60 ] ) ;
V_59 -> V_8 = V_60 ;
-- V_7 -> V_32 ;
if ( V_58 ) {
F_57 ( V_30 -> V_7 , NULL ) ;
F_58 ( & V_30 -> V_55 ) ;
} else
F_47 ( V_7 , V_30 ) ;
F_59 () ;
F_16 ( V_7 , V_7 -> V_32 + 1 ) ;
F_51 ( V_30 ) ;
F_44 ( V_7 ) ;
} else if ( V_30 -> V_33 && V_58 ) {
V_7 = F_49 ( V_30 ) ;
F_58 ( & V_30 -> V_55 ) ;
}
if ( V_58 ) {
if ( V_7 && V_7 -> V_32 == 0 && V_7 -> V_54 == 0 ) {
F_60 ( V_7 -> V_38 ) ;
if ( ! ( V_7 -> V_62 & V_63 ) &&
V_7 -> V_38 -> V_64 == V_65 )
F_61 ( V_7 -> V_38 ) ;
}
F_55 ( ! F_62 ( V_66 ,
& V_30 -> V_67 . V_62 ) ) ;
F_63 ( & V_30 -> V_55 ) ;
}
}
static void F_64 ( struct V_29 * V_30 , bool V_58 )
{
F_65 () ;
F_53 ( V_30 , V_58 ) ;
F_66 () ;
}
static void F_67 ( struct V_37 * V_38 )
{
struct V_6 * V_7 = F_31 ( V_38 ) ;
struct V_29 * V_30 , * V_68 ;
int V_17 , V_21 = V_7 -> V_32 ;
for ( V_17 = 0 ; V_17 < V_21 ; V_17 ++ ) {
V_30 = F_54 ( V_7 -> V_61 [ V_17 ] ) ;
F_55 ( ! V_30 ) ;
V_30 -> V_67 . V_55 -> V_69 ( V_30 -> V_67 . V_55 ) ;
F_57 ( V_30 -> V_7 , NULL ) ;
-- V_7 -> V_32 ;
}
F_68 (tfile, &tun->disabled, next) {
V_30 -> V_67 . V_55 -> V_69 ( V_30 -> V_67 . V_55 ) ;
F_57 ( V_30 -> V_7 , NULL ) ;
}
F_55 ( V_7 -> V_32 != 0 ) ;
F_59 () ;
for ( V_17 = 0 ; V_17 < V_21 ; V_17 ++ ) {
V_30 = F_54 ( V_7 -> V_61 [ V_17 ] ) ;
F_51 ( V_30 ) ;
F_58 ( & V_30 -> V_55 ) ;
}
F_69 (tfile, tmp, &tun->disabled, next) {
F_49 ( V_30 ) ;
F_51 ( V_30 ) ;
F_58 ( & V_30 -> V_55 ) ;
}
F_55 ( V_7 -> V_54 != 0 ) ;
if ( V_7 -> V_62 & V_63 )
F_70 ( V_70 ) ;
}
static int F_71 ( struct V_6 * V_7 , struct V_71 * V_71 , bool V_72 )
{
struct V_29 * V_30 = V_71 -> V_73 ;
int V_74 ;
V_74 = F_72 ( V_30 -> V_67 . V_55 , V_7 -> V_75 ) ;
if ( V_74 < 0 )
goto V_76;
V_74 = - V_77 ;
if ( F_54 ( V_30 -> V_7 ) && ! V_30 -> V_33 )
goto V_76;
V_74 = - V_78 ;
if ( ! ( V_7 -> V_62 & V_79 ) && V_7 -> V_32 == 1 )
goto V_76;
V_74 = - V_80 ;
if ( ! V_30 -> V_33 &&
V_7 -> V_32 + V_7 -> V_54 == V_81 )
goto V_76;
V_74 = 0 ;
if ( ! V_72 && ( V_7 -> V_82 == true ) ) {
V_74 = F_73 ( & V_7 -> V_83 , V_30 -> V_67 . V_55 ) ;
if ( ! V_74 )
goto V_76;
}
V_30 -> V_8 = V_7 -> V_32 ;
F_56 ( V_30 -> V_7 , V_7 ) ;
F_56 ( V_7 -> V_61 [ V_7 -> V_32 ] , V_30 ) ;
V_7 -> V_32 ++ ;
if ( V_30 -> V_33 )
F_49 ( V_30 ) ;
else
F_74 ( & V_30 -> V_55 ) ;
F_44 ( V_7 ) ;
V_76:
return V_74 ;
}
static struct V_6 * F_75 ( struct V_29 * V_30 )
{
struct V_6 * V_7 ;
F_23 () ;
V_7 = F_76 ( V_30 -> V_7 ) ;
if ( V_7 )
F_77 ( V_7 -> V_38 ) ;
F_27 () ;
return V_7 ;
}
static struct V_6 * F_78 ( struct V_71 * V_71 )
{
return F_75 ( V_71 -> V_73 ) ;
}
static void F_79 ( struct V_6 * V_7 )
{
F_80 ( V_7 -> V_38 ) ;
}
static void F_81 ( T_1 * V_84 , const T_4 * V_85 )
{
int V_21 = F_82 ( V_86 , V_85 ) >> 26 ;
V_84 [ V_21 >> 5 ] |= ( 1 << ( V_21 & 31 ) ) ;
}
static unsigned int F_83 ( const T_1 * V_84 , const T_4 * V_85 )
{
int V_21 = F_82 ( V_86 , V_85 ) >> 26 ;
return V_84 [ V_21 >> 5 ] & ( 1 << ( V_21 & 31 ) ) ;
}
static int F_84 ( struct V_87 * V_88 , void T_5 * V_89 )
{
struct { T_4 V_90 [ V_86 ] ; } * V_85 ;
struct V_91 V_92 ;
int V_74 , V_93 , V_21 , V_94 ;
if ( F_85 ( & V_92 , V_89 , sizeof( V_92 ) ) )
return - V_95 ;
if ( ! V_92 . V_26 ) {
V_88 -> V_26 = 0 ;
return 0 ;
}
V_93 = V_86 * V_92 . V_26 ;
V_85 = F_5 ( V_93 , V_96 ) ;
if ( ! V_85 )
return - V_97 ;
if ( F_85 ( V_85 , V_89 + sizeof( V_92 ) , V_93 ) ) {
V_74 = - V_95 ;
goto V_98;
}
V_88 -> V_26 = 0 ;
F_86 () ;
for ( V_21 = 0 ; V_21 < V_92 . V_26 && V_21 < V_99 ; V_21 ++ )
memcpy ( V_88 -> V_85 [ V_21 ] , V_85 [ V_21 ] . V_90 , V_86 ) ;
V_94 = V_21 ;
memset ( V_88 -> V_84 , 0 , sizeof( V_88 -> V_84 ) ) ;
for (; V_21 < V_92 . V_26 ; V_21 ++ ) {
if ( ! F_87 ( V_85 [ V_21 ] . V_90 ) ) {
V_74 = 0 ;
goto V_98;
}
F_81 ( V_88 -> V_84 , V_85 [ V_21 ] . V_90 ) ;
}
if ( ( V_92 . V_62 & V_100 ) )
memset ( V_88 -> V_84 , ~ 0 , sizeof( V_88 -> V_84 ) ) ;
F_86 () ;
V_88 -> V_26 = V_94 ;
V_74 = V_94 ;
V_98:
F_88 ( V_85 ) ;
return V_74 ;
}
static int F_89 ( struct V_87 * V_88 , const struct V_39 * V_40 )
{
struct V_101 * V_102 = (struct V_101 * ) V_40 -> V_22 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_88 -> V_26 ; V_17 ++ )
if ( F_90 ( V_102 -> V_103 , V_88 -> V_85 [ V_17 ] ) )
return 1 ;
if ( F_87 ( V_102 -> V_103 ) )
return F_83 ( V_88 -> V_84 , V_102 -> V_103 ) ;
return 0 ;
}
static int F_91 ( struct V_87 * V_88 , const struct V_39 * V_40 )
{
if ( ! V_88 -> V_26 )
return 1 ;
return F_89 ( V_88 , V_40 ) ;
}
static void F_92 ( struct V_37 * V_38 )
{
F_67 ( V_38 ) ;
}
static int F_93 ( struct V_37 * V_38 )
{
F_94 ( V_38 ) ;
return 0 ;
}
static int F_95 ( struct V_37 * V_38 )
{
F_96 ( V_38 ) ;
return 0 ;
}
static T_6 F_97 ( struct V_39 * V_40 , struct V_37 * V_38 )
{
struct V_6 * V_7 = F_31 ( V_38 ) ;
int V_43 = V_40 -> V_104 ;
struct V_29 * V_30 ;
T_1 V_32 = 0 ;
F_23 () ;
V_30 = F_76 ( V_7 -> V_61 [ V_43 ] ) ;
V_32 = F_32 ( V_7 -> V_32 ) ;
if ( V_43 >= V_32 )
goto V_105;
if ( V_32 == 1 ) {
T_7 V_1 ;
V_1 = F_33 ( V_40 ) ;
if ( V_1 ) {
struct V_2 * V_5 ;
V_5 = F_2 ( & V_7 -> V_31 [ F_1 ( V_1 ) ] ,
V_1 ) ;
if ( V_5 )
F_28 ( V_5 , V_1 ) ;
}
}
F_6 ( V_10 , V_7 , L_4 , V_40 -> V_106 ) ;
F_55 ( ! V_30 ) ;
if ( ! F_91 ( & V_7 -> V_107 , V_40 ) )
goto V_105;
if ( V_30 -> V_67 . V_55 -> V_108 &&
V_108 ( V_30 -> V_67 . V_55 , V_40 ) )
goto V_105;
if ( F_98 ( & V_30 -> V_67 . V_55 -> V_56 ) * V_32
>= V_38 -> V_109 )
goto V_105;
if ( F_29 ( F_99 ( V_40 , V_9 ) ) )
goto V_105;
if ( V_40 -> V_55 ) {
F_100 ( V_40 -> V_55 , & F_101 ( V_40 ) -> V_110 ) ;
F_102 ( V_40 ) ;
}
F_103 ( V_40 ) ;
F_104 ( V_40 ) ;
F_105 ( & V_30 -> V_67 . V_55 -> V_56 , V_40 ) ;
if ( V_30 -> V_62 & V_111 )
F_106 ( & V_30 -> V_112 , V_113 , V_114 ) ;
V_30 -> V_67 . V_55 -> V_69 ( V_30 -> V_67 . V_55 ) ;
F_27 () ;
return V_115 ;
V_105:
V_38 -> V_116 . V_117 ++ ;
F_107 ( V_40 ) ;
F_108 ( V_40 ) ;
F_27 () ;
return V_115 ;
}
static void F_109 ( struct V_37 * V_38 )
{
}
static int
F_110 ( struct V_37 * V_38 , int V_118 )
{
if ( V_118 < V_119 || V_118 + V_38 -> V_120 > V_121 )
return - V_77 ;
V_38 -> V_122 = V_118 ;
return 0 ;
}
static T_8 F_111 ( struct V_37 * V_38 ,
T_8 V_123 )
{
struct V_6 * V_7 = F_31 ( V_38 ) ;
return ( V_123 & V_7 -> V_124 ) | ( V_123 & ~ V_125 ) ;
}
static void F_112 ( struct V_37 * V_38 )
{
return;
}
static void F_113 ( struct V_6 * V_7 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_19 ; V_17 ++ )
F_114 ( & V_7 -> V_31 [ V_17 ] ) ;
V_7 -> V_24 = V_126 ;
F_115 ( & V_7 -> V_28 , F_17 , ( unsigned long ) V_7 ) ;
F_20 ( & V_7 -> V_28 ,
F_21 ( V_12 + V_7 -> V_24 ) ) ;
}
static void F_116 ( struct V_6 * V_7 )
{
F_117 ( & V_7 -> V_28 ) ;
F_12 ( V_7 ) ;
}
static void F_118 ( struct V_37 * V_38 )
{
struct V_6 * V_7 = F_31 ( V_38 ) ;
switch ( V_7 -> V_62 & V_127 ) {
case V_128 :
V_38 -> V_129 = & V_130 ;
V_38 -> V_120 = 0 ;
V_38 -> V_131 = 0 ;
V_38 -> V_122 = 1500 ;
V_38 -> type = V_132 ;
V_38 -> V_62 = V_133 | V_134 | V_135 ;
V_38 -> V_109 = V_136 ;
break;
case V_137 :
V_38 -> V_129 = & V_138 ;
F_119 ( V_38 ) ;
V_38 -> V_139 &= ~ V_140 ;
V_38 -> V_139 |= V_141 ;
F_120 ( V_38 ) ;
V_38 -> V_109 = V_136 ;
break;
}
}
static unsigned int F_121 ( struct V_71 * V_71 , T_9 * V_142 )
{
struct V_29 * V_30 = V_71 -> V_73 ;
struct V_6 * V_7 = F_75 ( V_30 ) ;
struct V_143 * V_55 ;
unsigned int V_84 = 0 ;
if ( ! V_7 )
return V_144 ;
V_55 = V_30 -> V_67 . V_55 ;
F_6 ( V_10 , V_7 , L_5 ) ;
F_122 ( V_71 , F_123 ( V_55 ) , V_142 ) ;
if ( ! F_124 ( & V_55 -> V_56 ) )
V_84 |= V_145 | V_146 ;
if ( F_125 ( V_55 ) ||
( ! F_126 ( V_147 , & V_55 -> V_148 -> V_62 ) &&
F_125 ( V_55 ) ) )
V_84 |= V_149 | V_150 ;
if ( V_7 -> V_38 -> V_64 != V_65 )
V_84 = V_144 ;
F_79 ( V_7 ) ;
return V_84 ;
}
static struct V_39 * F_127 ( struct V_29 * V_30 ,
T_10 V_151 , T_10 V_106 ,
T_10 V_152 , int V_153 )
{
struct V_143 * V_55 = V_30 -> V_67 . V_55 ;
struct V_39 * V_40 ;
int V_74 ;
if ( V_151 + V_106 < V_154 || ! V_152 )
V_152 = V_106 ;
V_40 = F_128 ( V_55 , V_151 + V_152 , V_106 - V_152 , V_153 ,
& V_74 , 0 ) ;
if ( ! V_40 )
return F_129 ( V_74 ) ;
F_130 ( V_40 , V_151 ) ;
F_131 ( V_40 , V_152 ) ;
V_40 -> V_155 = V_106 - V_152 ;
V_40 -> V_106 += V_106 - V_152 ;
return V_40 ;
}
static T_11 F_132 ( struct V_6 * V_7 , struct V_29 * V_30 ,
void * V_156 , const struct V_157 * V_158 ,
T_10 V_159 , T_10 V_26 , int V_153 )
{
struct V_160 V_161 = { 0 , F_133 (ETH_P_IP) } ;
struct V_39 * V_40 ;
T_10 V_106 = V_159 , V_162 = V_163 , V_152 ;
struct V_164 V_165 = { 0 } ;
int V_166 ;
int V_167 = 0 ;
int V_168 ;
bool V_169 = false ;
int V_74 ;
T_1 V_1 ;
if ( ! ( V_7 -> V_62 & V_170 ) ) {
if ( V_106 < sizeof( V_161 ) )
return - V_77 ;
V_106 -= sizeof( V_161 ) ;
if ( F_134 ( ( void * ) & V_161 , V_158 , 0 , sizeof( V_161 ) ) )
return - V_95 ;
V_167 += sizeof( V_161 ) ;
}
if ( V_7 -> V_62 & V_171 ) {
if ( V_106 < V_7 -> V_172 )
return - V_77 ;
V_106 -= V_7 -> V_172 ;
if ( F_134 ( ( void * ) & V_165 , V_158 , V_167 , sizeof( V_165 ) ) )
return - V_95 ;
if ( ( V_165 . V_62 & V_173 ) &&
V_165 . V_174 + V_165 . V_175 + 2 > V_165 . V_176 )
V_165 . V_176 = V_165 . V_174 + V_165 . V_175 + 2 ;
if ( V_165 . V_176 > V_106 )
return - V_77 ;
V_167 += V_7 -> V_172 ;
}
if ( ( V_7 -> V_62 & V_127 ) == V_137 ) {
V_162 += V_177 ;
if ( F_29 ( V_106 < V_178 ||
( V_165 . V_176 && V_165 . V_176 < V_178 ) ) )
return - V_77 ;
}
V_166 = F_135 ( V_162 ) ;
if ( V_156 ) {
V_168 = V_165 . V_176 ? V_165 . V_176 : V_179 ;
if ( V_168 > V_166 )
V_168 = V_166 ;
V_152 = V_168 ;
if ( F_136 ( V_158 , V_167 + V_168 , V_26 ) <= V_180 )
V_169 = true ;
}
if ( ! V_169 ) {
V_168 = V_106 ;
if ( V_165 . V_176 > V_166 )
V_152 = V_166 ;
else
V_152 = V_165 . V_176 ;
}
V_40 = F_127 ( V_30 , V_162 , V_168 , V_152 , V_153 ) ;
if ( F_137 ( V_40 ) ) {
if ( F_138 ( V_40 ) != - V_181 )
V_7 -> V_38 -> V_116 . V_182 ++ ;
return F_138 ( V_40 ) ;
}
if ( V_169 )
V_74 = F_139 ( V_40 , V_158 , V_167 , V_26 ) ;
else {
V_74 = F_140 ( V_40 , 0 , V_158 , V_167 , V_106 ) ;
if ( ! V_74 && V_156 ) {
struct V_183 * V_184 = V_156 ;
V_184 -> V_185 ( V_184 , false ) ;
}
}
if ( V_74 ) {
V_7 -> V_38 -> V_116 . V_182 ++ ;
F_108 ( V_40 ) ;
return - V_95 ;
}
if ( V_165 . V_62 & V_173 ) {
if ( ! F_141 ( V_40 , V_165 . V_174 ,
V_165 . V_175 ) ) {
V_7 -> V_38 -> V_116 . V_186 ++ ;
F_108 ( V_40 ) ;
return - V_77 ;
}
}
switch ( V_7 -> V_62 & V_127 ) {
case V_128 :
if ( V_7 -> V_62 & V_170 ) {
switch ( V_40 -> V_22 [ 0 ] & 0xf0 ) {
case 0x40 :
V_161 . V_187 = F_142 ( V_188 ) ;
break;
case 0x60 :
V_161 . V_187 = F_142 ( V_189 ) ;
break;
default:
V_7 -> V_38 -> V_116 . V_182 ++ ;
F_108 ( V_40 ) ;
return - V_77 ;
}
}
F_143 ( V_40 ) ;
V_40 -> V_190 = V_161 . V_187 ;
V_40 -> V_38 = V_7 -> V_38 ;
break;
case V_137 :
V_40 -> V_190 = F_144 ( V_40 , V_7 -> V_38 ) ;
break;
}
F_145 ( V_40 ) ;
if ( V_165 . V_191 != V_192 ) {
F_146 ( L_6 ) ;
switch ( V_165 . V_191 & ~ V_193 ) {
case V_194 :
F_101 ( V_40 ) -> V_191 = V_195 ;
break;
case V_196 :
F_101 ( V_40 ) -> V_191 = V_197 ;
break;
case V_198 :
{
static bool V_199 ;
if ( ! V_199 ) {
V_199 = true ;
F_147 ( V_7 -> V_38 ,
L_7 ,
V_200 -> V_201 ) ;
}
F_101 ( V_40 ) -> V_191 = V_202 ;
if ( V_40 -> V_190 == F_142 ( V_189 ) )
F_148 ( V_40 ) ;
break;
}
default:
V_7 -> V_38 -> V_116 . V_186 ++ ;
F_108 ( V_40 ) ;
return - V_77 ;
}
if ( V_165 . V_191 & V_193 )
F_101 ( V_40 ) -> V_191 |= V_203 ;
F_101 ( V_40 ) -> V_204 = V_165 . V_204 ;
if ( F_101 ( V_40 ) -> V_204 == 0 ) {
V_7 -> V_38 -> V_116 . V_186 ++ ;
F_108 ( V_40 ) ;
return - V_77 ;
}
F_101 ( V_40 ) -> V_191 |= V_205 ;
F_101 ( V_40 ) -> V_206 = 0 ;
}
if ( V_169 ) {
F_101 ( V_40 ) -> V_207 = V_156 ;
F_101 ( V_40 ) -> V_110 |= V_208 ;
F_101 ( V_40 ) -> V_110 |= V_209 ;
}
F_149 ( V_40 , 0 ) ;
V_1 = F_33 ( V_40 ) ;
F_150 ( V_40 ) ;
V_7 -> V_38 -> V_116 . V_210 ++ ;
V_7 -> V_38 -> V_116 . V_211 += V_106 ;
F_22 ( V_7 , V_1 , V_30 ) ;
return V_159 ;
}
static T_11 F_151 ( struct V_212 * V_213 , const struct V_157 * V_158 ,
unsigned long V_26 , T_12 V_214 )
{
struct V_71 * V_71 = V_213 -> V_215 ;
struct V_6 * V_7 = F_78 ( V_71 ) ;
struct V_29 * V_30 = V_71 -> V_73 ;
T_11 V_216 ;
if ( ! V_7 )
return - V_217 ;
F_6 ( V_10 , V_7 , L_8 , V_26 ) ;
V_216 = F_132 ( V_7 , V_30 , NULL , V_158 , F_152 ( V_158 , V_26 ) ,
V_26 , V_71 -> V_218 & V_219 ) ;
F_79 ( V_7 ) ;
return V_216 ;
}
static T_11 F_153 ( struct V_6 * V_7 ,
struct V_29 * V_30 ,
struct V_39 * V_40 ,
const struct V_157 * V_158 , int V_106 )
{
struct V_160 V_161 = { 0 , V_40 -> V_190 } ;
T_11 V_220 = 0 ;
int V_221 = 0 , V_222 ;
int V_223 = 0 ;
int V_172 = 0 ;
if ( F_154 ( V_40 ) )
V_223 = V_224 ;
if ( V_7 -> V_62 & V_171 )
V_172 = V_7 -> V_172 ;
if ( ! ( V_7 -> V_62 & V_170 ) ) {
if ( ( V_106 -= sizeof( V_161 ) ) < 0 )
return - V_77 ;
if ( V_106 < V_40 -> V_106 + V_223 + V_172 ) {
V_161 . V_62 |= V_225 ;
}
if ( F_155 ( V_158 , ( void * ) & V_161 , 0 , sizeof( V_161 ) ) )
return - V_95 ;
V_220 += sizeof( V_161 ) ;
}
if ( V_172 ) {
struct V_164 V_165 = { 0 } ;
if ( ( V_106 -= V_172 ) < 0 )
return - V_77 ;
if ( F_156 ( V_40 ) ) {
struct V_226 * V_227 = F_101 ( V_40 ) ;
V_165 . V_176 = F_157 ( V_40 ) ;
V_165 . V_204 = V_227 -> V_204 ;
if ( V_227 -> V_191 & V_195 )
V_165 . V_191 = V_194 ;
else if ( V_227 -> V_191 & V_197 )
V_165 . V_191 = V_196 ;
else {
F_158 ( L_9
L_10 ,
V_227 -> V_191 , V_165 . V_204 ,
V_165 . V_176 ) ;
F_159 ( V_228 , L_11 ,
V_229 ,
16 , 1 , V_40 -> V_4 ,
F_160 ( ( int ) V_165 . V_176 , 64 ) , true ) ;
F_161 ( 1 ) ;
return - V_77 ;
}
if ( V_227 -> V_191 & V_203 )
V_165 . V_191 |= V_193 ;
} else
V_165 . V_191 = V_192 ;
if ( V_40 -> V_230 == V_231 ) {
V_165 . V_62 = V_173 ;
V_165 . V_174 = F_162 ( V_40 ) +
V_223 ;
V_165 . V_175 = V_40 -> V_175 ;
} else if ( V_40 -> V_230 == V_232 ) {
V_165 . V_62 = V_233 ;
}
if ( F_29 ( F_155 ( V_158 , ( void * ) & V_165 , V_220 ,
sizeof( V_165 ) ) ) )
return - V_95 ;
V_220 += V_172 ;
}
V_222 = V_220 ;
V_106 = F_163 ( int , V_40 -> V_106 + V_223 , V_106 ) ;
V_220 += V_40 -> V_106 + V_223 ;
if ( V_223 ) {
int V_234 , V_235 ;
struct {
T_13 V_236 ;
T_13 V_237 ;
} V_238 ;
V_238 . V_236 = V_40 -> V_239 ;
V_238 . V_237 = F_142 ( F_164 ( V_40 ) ) ;
V_221 = F_165 ( struct V_240 , V_236 ) ;
V_234 = F_163 ( int , V_221 , V_106 ) ;
V_235 = F_166 ( V_40 , 0 , V_158 , V_222 , V_234 ) ;
V_106 -= V_234 ;
V_222 += V_234 ;
if ( V_235 || ! V_106 )
goto V_98;
V_234 = F_163 ( int , sizeof( V_238 ) , V_106 ) ;
V_235 = F_155 ( V_158 , ( void * ) & V_238 , V_222 , V_234 ) ;
V_106 -= V_234 ;
V_222 += V_234 ;
if ( V_235 || ! V_106 )
goto V_98;
}
F_166 ( V_40 , V_221 , V_158 , V_222 , V_106 ) ;
V_98:
V_7 -> V_38 -> V_116 . V_241 ++ ;
V_7 -> V_38 -> V_116 . V_242 += V_106 ;
return V_220 ;
}
static T_11 F_167 ( struct V_6 * V_7 , struct V_29 * V_30 ,
const struct V_157 * V_158 , T_11 V_106 , int V_153 )
{
struct V_39 * V_40 ;
T_11 V_235 = 0 ;
int V_243 , V_74 , V_244 = 0 ;
F_6 ( V_10 , V_7 , L_12 ) ;
if ( ! V_106 )
return V_235 ;
if ( V_7 -> V_38 -> V_64 != V_65 )
return - V_245 ;
V_40 = F_168 ( V_30 -> V_67 . V_55 , V_153 ? V_246 : 0 ,
& V_243 , & V_244 , & V_74 ) ;
if ( V_40 ) {
V_235 = F_153 ( V_7 , V_30 , V_40 , V_158 , V_106 ) ;
F_108 ( V_40 ) ;
} else
V_235 = V_74 ;
return V_235 ;
}
static T_11 F_169 ( struct V_212 * V_213 , const struct V_157 * V_158 ,
unsigned long V_26 , T_12 V_214 )
{
struct V_71 * V_71 = V_213 -> V_215 ;
struct V_29 * V_30 = V_71 -> V_73 ;
struct V_6 * V_7 = F_75 ( V_30 ) ;
T_11 V_106 , V_235 ;
if ( ! V_7 )
return - V_217 ;
V_106 = F_152 ( V_158 , V_26 ) ;
if ( V_106 < 0 ) {
V_235 = - V_77 ;
goto V_76;
}
V_235 = F_167 ( V_7 , V_30 , V_158 , V_106 ,
V_71 -> V_218 & V_219 ) ;
V_235 = F_163 ( T_11 , V_235 , V_106 ) ;
if ( V_235 > 0 )
V_213 -> V_247 = V_235 ;
V_76:
F_79 ( V_7 ) ;
return V_235 ;
}
static void F_170 ( struct V_37 * V_38 )
{
struct V_6 * V_7 = F_31 ( V_38 ) ;
F_55 ( ! ( F_171 ( & V_7 -> V_53 ) ) ) ;
F_116 ( V_7 ) ;
F_172 ( V_7 -> V_75 ) ;
F_173 ( V_38 ) ;
}
static void F_174 ( struct V_37 * V_38 )
{
struct V_6 * V_7 = F_31 ( V_38 ) ;
V_7 -> V_47 = V_248 ;
V_7 -> V_49 = V_249 ;
V_38 -> V_250 = & V_251 ;
V_38 -> V_252 = F_170 ;
}
static int F_175 ( struct V_253 * V_254 [] , struct V_253 * V_22 [] )
{
return - V_77 ;
}
static void F_176 ( struct V_143 * V_55 )
{
struct V_29 * V_30 ;
T_14 * V_255 ;
if ( ! F_125 ( V_55 ) )
return;
if ( ! F_177 ( V_147 , & V_55 -> V_148 -> V_62 ) )
return;
V_255 = F_123 ( V_55 ) ;
if ( V_255 && F_178 ( V_255 ) )
F_179 ( V_255 , V_149 |
V_150 | V_256 ) ;
V_30 = F_180 ( V_55 , struct V_29 , V_55 ) ;
F_106 ( & V_30 -> V_112 , V_113 , V_257 ) ;
}
static int F_181 ( struct V_212 * V_213 , struct V_67 * V_143 ,
struct V_258 * V_259 , T_10 V_159 )
{
int V_235 ;
struct V_29 * V_30 = F_180 ( V_143 , struct V_29 , V_67 ) ;
struct V_6 * V_7 = F_75 ( V_30 ) ;
if ( ! V_7 )
return - V_217 ;
V_235 = F_132 ( V_7 , V_30 , V_259 -> V_156 , V_259 -> V_260 , V_159 ,
V_259 -> V_261 , V_259 -> V_262 & V_246 ) ;
F_79 ( V_7 ) ;
return V_235 ;
}
static int F_182 ( struct V_212 * V_213 , struct V_67 * V_143 ,
struct V_258 * V_259 , T_10 V_159 ,
int V_62 )
{
struct V_29 * V_30 = F_180 ( V_143 , struct V_29 , V_67 ) ;
struct V_6 * V_7 = F_75 ( V_30 ) ;
int V_235 ;
if ( ! V_7 )
return - V_217 ;
if ( V_62 & ~ ( V_246 | V_263 | V_264 ) ) {
V_235 = - V_77 ;
goto V_76;
}
if ( V_62 & V_264 ) {
V_235 = F_183 ( V_143 -> V_55 , V_259 , V_159 ,
V_265 , V_266 ) ;
goto V_76;
}
V_235 = F_167 ( V_7 , V_30 , V_259 -> V_260 , V_159 ,
V_62 & V_246 ) ;
if ( V_235 > V_159 ) {
V_259 -> V_262 |= V_263 ;
V_235 = V_62 & V_263 ? V_235 : V_159 ;
}
V_76:
F_79 ( V_7 ) ;
return V_235 ;
}
static int F_184 ( struct V_67 * V_143 )
{
if ( V_143 -> V_55 )
F_58 ( V_143 -> V_55 ) ;
return 0 ;
}
static int F_185 ( struct V_6 * V_7 )
{
int V_62 = 0 ;
if ( V_7 -> V_62 & V_128 )
V_62 |= V_267 ;
else
V_62 |= V_268 ;
if ( V_7 -> V_62 & V_170 )
V_62 |= V_269 ;
if ( V_7 -> V_62 & V_270 )
V_62 |= V_271 ;
if ( V_7 -> V_62 & V_171 )
V_62 |= V_272 ;
if ( V_7 -> V_62 & V_79 )
V_62 |= V_273 ;
if ( V_7 -> V_62 & V_63 )
V_62 |= V_274 ;
return V_62 ;
}
static T_11 F_186 ( struct V_275 * V_38 , struct V_276 * V_277 ,
char * V_278 )
{
struct V_6 * V_7 = F_31 ( F_187 ( V_38 ) ) ;
return sprintf ( V_278 , L_13 , F_185 ( V_7 ) ) ;
}
static T_11 F_188 ( struct V_275 * V_38 , struct V_276 * V_277 ,
char * V_278 )
{
struct V_6 * V_7 = F_31 ( F_187 ( V_38 ) ) ;
return F_39 ( V_7 -> V_47 ) ?
sprintf ( V_278 , L_14 ,
F_189 ( F_190 () , V_7 -> V_47 ) ) :
sprintf ( V_278 , L_15 ) ;
}
static T_11 F_191 ( struct V_275 * V_38 , struct V_276 * V_277 ,
char * V_278 )
{
struct V_6 * V_7 = F_31 ( F_187 ( V_38 ) ) ;
return F_41 ( V_7 -> V_49 ) ?
sprintf ( V_278 , L_14 ,
F_192 ( F_190 () , V_7 -> V_49 ) ) :
sprintf ( V_278 , L_15 ) ;
}
static int F_193 ( struct V_46 * V_46 , struct V_71 * V_71 , struct V_279 * V_280 )
{
struct V_6 * V_7 ;
struct V_29 * V_30 = V_71 -> V_73 ;
struct V_37 * V_38 ;
int V_74 ;
if ( V_30 -> V_33 )
return - V_77 ;
V_38 = F_194 ( V_46 , V_280 -> V_281 ) ;
if ( V_38 ) {
if ( V_280 -> V_282 & V_283 )
return - V_78 ;
if ( ( V_280 -> V_282 & V_267 ) && V_38 -> V_129 == & V_130 )
V_7 = F_31 ( V_38 ) ;
else if ( ( V_280 -> V_282 & V_268 ) && V_38 -> V_129 == & V_138 )
V_7 = F_31 ( V_38 ) ;
else
return - V_77 ;
if ( ! ! ( V_280 -> V_282 & V_273 ) !=
! ! ( V_7 -> V_62 & V_79 ) )
return - V_77 ;
if ( F_36 ( V_7 ) )
return - V_284 ;
V_74 = F_195 ( V_7 -> V_75 ) ;
if ( V_74 < 0 )
return V_74 ;
V_74 = F_71 ( V_7 , V_71 , V_280 -> V_282 & V_285 ) ;
if ( V_74 < 0 )
return V_74 ;
if ( V_7 -> V_62 & V_79 &&
( V_7 -> V_32 + V_7 -> V_54 > 1 ) ) {
return 0 ;
}
}
else {
char * V_286 ;
unsigned long V_62 = 0 ;
int V_287 = V_280 -> V_282 & V_273 ?
V_81 : 1 ;
if ( ! F_43 ( V_46 -> V_50 , V_51 ) )
return - V_284 ;
V_74 = F_196 () ;
if ( V_74 < 0 )
return V_74 ;
if ( V_280 -> V_282 & V_267 ) {
V_62 |= V_128 ;
V_286 = L_16 ;
} else if ( V_280 -> V_282 & V_268 ) {
V_62 |= V_137 ;
V_286 = L_17 ;
} else
return - V_77 ;
if ( * V_280 -> V_281 )
V_286 = V_280 -> V_281 ;
V_38 = F_197 ( sizeof( struct V_6 ) , V_286 ,
V_288 , F_174 , V_287 ,
V_287 ) ;
if ( ! V_38 )
return - V_97 ;
F_198 ( V_38 , V_46 ) ;
V_38 -> V_289 = & V_290 ;
V_38 -> V_291 = V_30 -> V_291 ;
V_7 = F_31 ( V_38 ) ;
V_7 -> V_38 = V_38 ;
V_7 -> V_62 = V_62 ;
V_7 -> V_107 . V_26 = 0 ;
V_7 -> V_172 = sizeof( struct V_164 ) ;
V_7 -> V_82 = false ;
V_7 -> V_292 = V_30 -> V_67 . V_55 -> V_293 ;
F_199 ( & V_7 -> V_18 ) ;
V_74 = F_200 ( & V_7 -> V_75 ) ;
if ( V_74 < 0 )
goto V_294;
F_118 ( V_38 ) ;
F_113 ( V_7 ) ;
V_38 -> V_295 = V_296 | V_297 |
V_125 | V_298 |
V_299 ;
V_38 -> V_123 = V_38 -> V_295 ;
V_38 -> V_300 = V_38 -> V_123 &
~ ( V_298 |
V_299 ) ;
F_201 ( & V_7 -> V_53 ) ;
V_74 = F_71 ( V_7 , V_71 , false ) ;
if ( V_74 < 0 )
goto V_301;
V_74 = F_202 ( V_7 -> V_38 ) ;
if ( V_74 < 0 )
goto V_302;
if ( F_203 ( & V_7 -> V_38 -> V_38 , & V_303 ) ||
F_203 ( & V_7 -> V_38 -> V_38 , & V_304 ) ||
F_203 ( & V_7 -> V_38 -> V_38 , & V_305 ) )
F_158 ( L_18 ) ;
}
F_204 ( V_7 -> V_38 ) ;
F_6 ( V_10 , V_7 , L_19 ) ;
if ( V_280 -> V_282 & V_269 )
V_7 -> V_62 |= V_170 ;
else
V_7 -> V_62 &= ~ V_170 ;
if ( V_280 -> V_282 & V_271 )
V_7 -> V_62 |= V_270 ;
else
V_7 -> V_62 &= ~ V_270 ;
if ( V_280 -> V_282 & V_272 )
V_7 -> V_62 |= V_171 ;
else
V_7 -> V_62 &= ~ V_171 ;
if ( V_280 -> V_282 & V_273 )
V_7 -> V_62 |= V_79 ;
else
V_7 -> V_62 &= ~ V_79 ;
if ( F_205 ( V_7 -> V_38 ) )
F_206 ( V_7 -> V_38 ) ;
strcpy ( V_280 -> V_281 , V_7 -> V_38 -> V_286 ) ;
return 0 ;
V_302:
F_67 ( V_38 ) ;
V_301:
F_116 ( V_7 ) ;
F_172 ( V_7 -> V_75 ) ;
V_294:
F_173 ( V_38 ) ;
return V_74 ;
}
static void F_207 ( struct V_46 * V_46 , struct V_6 * V_7 ,
struct V_279 * V_280 )
{
F_6 ( V_10 , V_7 , L_20 ) ;
strcpy ( V_280 -> V_281 , V_7 -> V_38 -> V_286 ) ;
V_280 -> V_282 = F_185 ( V_7 ) ;
}
static int F_208 ( struct V_6 * V_7 , unsigned long V_89 )
{
T_8 V_123 = 0 ;
if ( V_89 & V_306 ) {
V_123 |= V_307 ;
V_89 &= ~ V_306 ;
if ( V_89 & ( V_308 | V_309 ) ) {
if ( V_89 & V_310 ) {
V_123 |= V_311 ;
V_89 &= ~ V_310 ;
}
if ( V_89 & V_308 )
V_123 |= V_312 ;
if ( V_89 & V_309 )
V_123 |= V_313 ;
V_89 &= ~ ( V_308 | V_309 ) ;
}
}
if ( V_89 )
return - V_77 ;
V_7 -> V_124 = V_123 ;
F_209 ( V_7 -> V_38 ) ;
return 0 ;
}
static void F_210 ( struct V_6 * V_7 , int V_21 )
{
int V_17 ;
struct V_29 * V_30 ;
for ( V_17 = 0 ; V_17 < V_21 ; V_17 ++ ) {
V_30 = F_54 ( V_7 -> V_61 [ V_17 ] ) ;
F_211 ( V_30 -> V_67 . V_55 ) ;
}
V_7 -> V_82 = false ;
}
static int F_212 ( struct V_6 * V_7 )
{
int V_17 , V_235 = 0 ;
struct V_29 * V_30 ;
for ( V_17 = 0 ; V_17 < V_7 -> V_32 ; V_17 ++ ) {
V_30 = F_54 ( V_7 -> V_61 [ V_17 ] ) ;
V_235 = F_73 ( & V_7 -> V_83 , V_30 -> V_67 . V_55 ) ;
if ( V_235 ) {
F_210 ( V_7 , V_17 ) ;
return V_235 ;
}
}
V_7 -> V_82 = true ;
return V_235 ;
}
static void F_213 ( struct V_6 * V_7 )
{
struct V_29 * V_30 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_7 -> V_32 ; V_17 ++ ) {
V_30 = F_54 ( V_7 -> V_61 [ V_17 ] ) ;
V_30 -> V_67 . V_55 -> V_293 = V_7 -> V_292 ;
}
}
static int F_214 ( struct V_71 * V_71 , struct V_279 * V_280 )
{
struct V_29 * V_30 = V_71 -> V_73 ;
struct V_6 * V_7 ;
int V_235 = 0 ;
F_65 () ;
if ( V_280 -> V_282 & V_314 ) {
V_7 = V_30 -> V_33 ;
if ( ! V_7 ) {
V_235 = - V_77 ;
goto V_34;
}
V_235 = F_215 ( V_7 -> V_75 ) ;
if ( V_235 < 0 )
goto V_34;
V_235 = F_71 ( V_7 , V_71 , false ) ;
} else if ( V_280 -> V_282 & V_315 ) {
V_7 = F_54 ( V_30 -> V_7 ) ;
if ( ! V_7 || ! ( V_7 -> V_62 & V_79 ) || V_30 -> V_33 )
V_235 = - V_77 ;
else
F_53 ( V_30 , false ) ;
} else
V_235 = - V_77 ;
V_34:
F_66 () ;
return V_235 ;
}
static long F_216 ( struct V_71 * V_71 , unsigned int V_316 ,
unsigned long V_89 , int V_317 )
{
struct V_29 * V_30 = V_71 -> V_73 ;
struct V_6 * V_7 ;
void T_5 * V_318 = ( void T_5 * ) V_89 ;
struct V_279 V_280 ;
T_15 V_47 ;
T_16 V_49 ;
int V_292 ;
int V_172 ;
unsigned int V_291 ;
int V_235 ;
if ( V_316 == V_319 || V_316 == V_320 || F_217 ( V_316 ) == 0x89 ) {
if ( F_85 ( & V_280 , V_318 , V_317 ) )
return - V_95 ;
} else {
memset ( & V_280 , 0 , sizeof( V_280 ) ) ;
}
if ( V_316 == V_321 ) {
return F_218 ( V_267 | V_268 | V_269 | V_271 |
V_272 | V_273 ,
( unsigned int T_5 * ) V_318 ) ;
} else if ( V_316 == V_320 )
return F_214 ( V_71 , & V_280 ) ;
V_235 = 0 ;
F_65 () ;
V_7 = F_75 ( V_30 ) ;
if ( V_316 == V_319 && ! V_7 ) {
V_280 . V_281 [ V_322 - 1 ] = '\0' ;
V_235 = F_193 ( V_30 -> V_46 , V_71 , & V_280 ) ;
if ( V_235 )
goto V_34;
if ( F_219 ( V_318 , & V_280 , V_317 ) )
V_235 = - V_95 ;
goto V_34;
}
if ( V_316 == V_323 ) {
V_235 = - V_284 ;
if ( V_7 )
goto V_34;
V_235 = - V_95 ;
if ( F_85 ( & V_291 , V_318 , sizeof( V_291 ) ) )
goto V_34;
V_235 = 0 ;
V_30 -> V_291 = V_291 ;
goto V_34;
}
V_235 = - V_217 ;
if ( ! V_7 )
goto V_34;
F_6 ( V_10 , V_7 , L_21 , V_316 ) ;
V_235 = 0 ;
switch ( V_316 ) {
case V_324 :
F_207 ( V_200 -> V_325 -> V_326 , V_7 , & V_280 ) ;
if ( V_30 -> V_33 )
V_280 . V_282 |= V_315 ;
if ( ! V_30 -> V_67 . V_55 -> V_108 )
V_280 . V_282 |= V_285 ;
if ( F_219 ( V_318 , & V_280 , V_317 ) )
V_235 = - V_95 ;
break;
case V_327 :
F_6 ( V_10 , V_7 , L_22 ,
V_89 ? L_23 : L_24 ) ;
break;
case V_328 :
if ( V_89 && ! ( V_7 -> V_62 & V_63 ) ) {
V_7 -> V_62 |= V_63 ;
F_220 ( V_70 ) ;
}
if ( ! V_89 && ( V_7 -> V_62 & V_63 ) ) {
V_7 -> V_62 &= ~ V_63 ;
F_70 ( V_70 ) ;
}
F_6 ( V_10 , V_7 , L_25 ,
V_89 ? L_24 : L_23 ) ;
break;
case V_329 :
V_47 = F_221 ( F_190 () , V_89 ) ;
if ( ! F_39 ( V_47 ) ) {
V_235 = - V_77 ;
break;
}
V_7 -> V_47 = V_47 ;
F_6 ( V_10 , V_7 , L_26 ,
F_222 ( & V_330 , V_7 -> V_47 ) ) ;
break;
case V_331 :
V_49 = F_223 ( F_190 () , V_89 ) ;
if ( ! F_41 ( V_49 ) ) {
V_235 = - V_77 ;
break;
}
V_7 -> V_49 = V_49 ;
F_6 ( V_10 , V_7 , L_27 ,
F_224 ( & V_330 , V_7 -> V_49 ) ) ;
break;
case V_332 :
if ( V_7 -> V_38 -> V_62 & V_333 ) {
F_6 ( V_10 , V_7 ,
L_28 ) ;
V_235 = - V_78 ;
} else {
V_7 -> V_38 -> type = ( int ) V_89 ;
F_6 ( V_10 , V_7 , L_29 ,
V_7 -> V_38 -> type ) ;
V_235 = 0 ;
}
break;
#ifdef F_225
case V_334 :
V_7 -> V_335 = V_89 ;
break;
#endif
case V_336 :
V_235 = F_208 ( V_7 , V_89 ) ;
break;
case V_337 :
V_235 = - V_77 ;
if ( ( V_7 -> V_62 & V_127 ) != V_137 )
break;
V_235 = F_84 ( & V_7 -> V_107 , ( void T_5 * ) V_89 ) ;
break;
case V_338 :
memcpy ( V_280 . V_339 . V_340 , V_7 -> V_38 -> V_341 , V_86 ) ;
V_280 . V_339 . V_342 = V_7 -> V_38 -> type ;
if ( F_219 ( V_318 , & V_280 , V_317 ) )
V_235 = - V_95 ;
break;
case V_343 :
F_6 ( V_344 , V_7 , L_30 ,
V_280 . V_339 . V_340 ) ;
V_235 = F_226 ( V_7 -> V_38 , & V_280 . V_339 ) ;
break;
case V_345 :
V_292 = V_30 -> V_67 . V_55 -> V_293 ;
if ( F_219 ( V_318 , & V_292 , sizeof( V_292 ) ) )
V_235 = - V_95 ;
break;
case V_346 :
if ( F_85 ( & V_292 , V_318 , sizeof( V_292 ) ) ) {
V_235 = - V_95 ;
break;
}
V_7 -> V_292 = V_292 ;
F_213 ( V_7 ) ;
break;
case V_347 :
V_172 = V_7 -> V_172 ;
if ( F_219 ( V_318 , & V_172 , sizeof( V_172 ) ) )
V_235 = - V_95 ;
break;
case V_348 :
if ( F_85 ( & V_172 , V_318 , sizeof( V_172 ) ) ) {
V_235 = - V_95 ;
break;
}
if ( V_172 < ( int ) sizeof( struct V_164 ) ) {
V_235 = - V_77 ;
break;
}
V_7 -> V_172 = V_172 ;
break;
case V_349 :
V_235 = - V_77 ;
if ( ( V_7 -> V_62 & V_127 ) != V_137 )
break;
V_235 = - V_95 ;
if ( F_85 ( & V_7 -> V_83 , V_318 , sizeof( V_7 -> V_83 ) ) )
break;
V_235 = F_212 ( V_7 ) ;
break;
case V_350 :
V_235 = - V_77 ;
if ( ( V_7 -> V_62 & V_127 ) != V_137 )
break;
V_235 = 0 ;
F_210 ( V_7 , V_7 -> V_32 ) ;
break;
case V_351 :
V_235 = - V_77 ;
if ( ( V_7 -> V_62 & V_127 ) != V_137 )
break;
V_235 = - V_95 ;
if ( F_219 ( V_318 , & V_7 -> V_83 , sizeof( V_7 -> V_83 ) ) )
break;
V_235 = 0 ;
break;
default:
V_235 = - V_77 ;
break;
}
V_34:
F_66 () ;
if ( V_7 )
F_79 ( V_7 ) ;
return V_235 ;
}
static long F_227 ( struct V_71 * V_71 ,
unsigned int V_316 , unsigned long V_89 )
{
return F_216 ( V_71 , V_316 , V_89 , sizeof ( struct V_279 ) ) ;
}
static long F_228 ( struct V_71 * V_71 ,
unsigned int V_316 , unsigned long V_89 )
{
switch ( V_316 ) {
case V_319 :
case V_324 :
case V_337 :
case V_345 :
case V_346 :
case V_338 :
case V_343 :
V_89 = ( unsigned long ) F_229 ( V_89 ) ;
break;
default:
V_89 = ( V_352 ) V_89 ;
break;
}
return F_216 ( V_71 , V_316 , V_89 , sizeof( struct V_353 ) ) ;
}
static int F_230 ( int V_354 , struct V_71 * V_71 , int V_355 )
{
struct V_29 * V_30 = V_71 -> V_73 ;
int V_235 ;
if ( ( V_235 = F_231 ( V_354 , V_71 , V_355 , & V_30 -> V_112 ) ) < 0 )
goto V_76;
if ( V_355 ) {
F_232 ( V_71 , F_233 ( V_200 ) , V_356 , 0 ) ;
V_30 -> V_62 |= V_111 ;
} else
V_30 -> V_62 &= ~ V_111 ;
V_235 = 0 ;
V_76:
return V_235 ;
}
static int F_234 ( struct V_357 * V_357 , struct V_71 * V_71 )
{
struct V_29 * V_30 ;
F_235 ( V_10 , L_31 ) ;
V_30 = (struct V_29 * ) F_236 ( & V_358 , V_359 , V_96 ,
& V_360 ) ;
if ( ! V_30 )
return - V_97 ;
F_57 ( V_30 -> V_7 , NULL ) ;
V_30 -> V_46 = F_237 ( V_200 -> V_325 -> V_326 ) ;
V_30 -> V_62 = 0 ;
V_30 -> V_291 = 0 ;
F_238 ( & V_30 -> V_361 . V_142 ) ;
F_57 ( V_30 -> V_67 . V_361 , & V_30 -> V_361 ) ;
V_30 -> V_67 . V_71 = V_71 ;
V_30 -> V_67 . V_362 = & V_363 ;
F_239 ( & V_30 -> V_67 , & V_30 -> V_55 ) ;
F_240 ( & V_30 -> V_55 , V_30 -> V_46 ) ;
V_30 -> V_55 . V_364 = F_176 ;
V_30 -> V_55 . V_293 = V_365 ;
V_71 -> V_73 = V_30 ;
F_241 ( V_66 , & V_30 -> V_67 . V_62 ) ;
F_201 ( & V_30 -> V_52 ) ;
F_242 ( & V_30 -> V_55 , V_366 ) ;
return 0 ;
}
static int F_243 ( struct V_357 * V_357 , struct V_71 * V_71 )
{
struct V_29 * V_30 = V_71 -> V_73 ;
struct V_46 * V_46 = V_30 -> V_46 ;
F_64 ( V_30 , true ) ;
F_244 ( V_46 ) ;
return 0 ;
}
static int F_245 ( struct V_367 * V_259 , struct V_71 * V_368 )
{
struct V_6 * V_7 ;
struct V_279 V_280 ;
memset ( & V_280 , 0 , sizeof( V_280 ) ) ;
F_65 () ;
V_7 = F_78 ( V_368 ) ;
if ( V_7 )
F_207 ( V_200 -> V_325 -> V_326 , V_7 , & V_280 ) ;
F_66 () ;
if ( V_7 )
F_79 ( V_7 ) ;
return F_246 ( V_259 , L_32 , V_280 . V_281 ) ;
}
static int F_247 ( struct V_37 * V_38 , struct V_369 * V_316 )
{
V_316 -> V_370 = 0 ;
V_316 -> V_371 = 0 ;
F_248 ( V_316 , V_372 ) ;
V_316 -> V_373 = V_374 ;
V_316 -> V_375 = V_376 ;
V_316 -> V_377 = 0 ;
V_316 -> V_378 = V_379 ;
V_316 -> V_380 = V_381 ;
V_316 -> V_382 = 0 ;
V_316 -> V_383 = 0 ;
return 0 ;
}
static void F_249 ( struct V_37 * V_38 , struct V_384 * V_385 )
{
struct V_6 * V_7 = F_31 ( V_38 ) ;
F_250 ( V_385 -> V_386 , V_387 , sizeof( V_385 -> V_386 ) ) ;
F_250 ( V_385 -> V_388 , V_389 , sizeof( V_385 -> V_388 ) ) ;
switch ( V_7 -> V_62 & V_127 ) {
case V_128 :
F_250 ( V_385 -> V_390 , L_33 , sizeof( V_385 -> V_390 ) ) ;
break;
case V_137 :
F_250 ( V_385 -> V_390 , L_34 , sizeof( V_385 -> V_390 ) ) ;
break;
}
}
static T_1 F_251 ( struct V_37 * V_38 )
{
#ifdef F_225
struct V_6 * V_7 = F_31 ( V_38 ) ;
return V_7 -> V_335 ;
#else
return - V_391 ;
#endif
}
static void F_252 ( struct V_37 * V_38 , T_1 V_392 )
{
#ifdef F_225
struct V_6 * V_7 = F_31 ( V_38 ) ;
V_7 -> V_335 = V_392 ;
#endif
}
static int T_17 F_253 ( void )
{
int V_235 = 0 ;
F_254 ( L_35 , V_393 , V_389 ) ;
F_254 ( L_36 , V_394 ) ;
V_235 = F_255 ( & V_290 ) ;
if ( V_235 ) {
F_158 ( L_37 ) ;
goto V_395;
}
V_235 = F_256 ( & V_396 ) ;
if ( V_235 ) {
F_158 ( L_38 , V_397 ) ;
goto V_398;
}
return 0 ;
V_398:
F_257 ( & V_290 ) ;
V_395:
return V_235 ;
}
static void F_258 ( void )
{
F_259 ( & V_396 ) ;
F_257 ( & V_290 ) ;
}
struct V_67 * F_260 ( struct V_71 * V_71 )
{
struct V_29 * V_30 ;
if ( V_71 -> V_399 != & V_400 )
return F_129 ( - V_77 ) ;
V_30 = V_71 -> V_73 ;
if ( ! V_30 )
return F_129 ( - V_217 ) ;
return & V_30 -> V_67 ;
}
