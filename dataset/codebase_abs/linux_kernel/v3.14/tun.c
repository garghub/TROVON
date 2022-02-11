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
F_56 ( V_30 -> V_7 , NULL ) ;
F_57 ( & V_30 -> V_55 ) ;
} else
F_47 ( V_7 , V_30 ) ;
F_58 () ;
F_16 ( V_7 , V_7 -> V_32 + 1 ) ;
F_51 ( V_30 ) ;
F_44 ( V_7 ) ;
} else if ( V_30 -> V_33 && V_58 ) {
V_7 = F_49 ( V_30 ) ;
F_57 ( & V_30 -> V_55 ) ;
}
if ( V_58 ) {
if ( V_7 && V_7 -> V_32 == 0 && V_7 -> V_54 == 0 ) {
F_59 ( V_7 -> V_38 ) ;
if ( ! ( V_7 -> V_62 & V_63 ) &&
V_7 -> V_38 -> V_64 == V_65 )
F_60 ( V_7 -> V_38 ) ;
}
F_55 ( ! F_61 ( V_66 ,
& V_30 -> V_67 . V_62 ) ) ;
F_62 ( & V_30 -> V_55 ) ;
}
}
static void F_63 ( struct V_29 * V_30 , bool V_58 )
{
F_64 () ;
F_53 ( V_30 , V_58 ) ;
F_65 () ;
}
static void F_66 ( struct V_37 * V_38 )
{
struct V_6 * V_7 = F_31 ( V_38 ) ;
struct V_29 * V_30 , * V_68 ;
int V_17 , V_21 = V_7 -> V_32 ;
for ( V_17 = 0 ; V_17 < V_21 ; V_17 ++ ) {
V_30 = F_54 ( V_7 -> V_61 [ V_17 ] ) ;
F_55 ( ! V_30 ) ;
F_67 ( & V_30 -> V_69 . V_70 ) ;
F_56 ( V_30 -> V_7 , NULL ) ;
-- V_7 -> V_32 ;
}
F_68 (tfile, &tun->disabled, next) {
F_67 ( & V_30 -> V_69 . V_70 ) ;
F_56 ( V_30 -> V_7 , NULL ) ;
}
F_55 ( V_7 -> V_32 != 0 ) ;
F_58 () ;
for ( V_17 = 0 ; V_17 < V_21 ; V_17 ++ ) {
V_30 = F_54 ( V_7 -> V_61 [ V_17 ] ) ;
F_51 ( V_30 ) ;
F_57 ( & V_30 -> V_55 ) ;
}
F_69 (tfile, tmp, &tun->disabled, next) {
F_49 ( V_30 ) ;
F_51 ( V_30 ) ;
F_57 ( & V_30 -> V_55 ) ;
}
F_55 ( V_7 -> V_54 != 0 ) ;
if ( V_7 -> V_62 & V_63 )
F_70 ( V_71 ) ;
}
static int F_71 ( struct V_6 * V_7 , struct V_72 * V_72 , bool V_73 )
{
struct V_29 * V_30 = V_72 -> V_74 ;
int V_75 ;
V_75 = F_72 ( V_30 -> V_67 . V_55 , V_7 -> V_76 ) ;
if ( V_75 < 0 )
goto V_77;
V_75 = - V_78 ;
if ( F_54 ( V_30 -> V_7 ) && ! V_30 -> V_33 )
goto V_77;
V_75 = - V_79 ;
if ( ! ( V_7 -> V_62 & V_80 ) && V_7 -> V_32 == 1 )
goto V_77;
V_75 = - V_81 ;
if ( ! V_30 -> V_33 &&
V_7 -> V_32 + V_7 -> V_54 == V_82 )
goto V_77;
V_75 = 0 ;
if ( ! V_73 && ( V_7 -> V_83 == true ) ) {
V_75 = F_73 ( & V_7 -> V_84 , V_30 -> V_67 . V_55 ) ;
if ( ! V_75 )
goto V_77;
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
V_77:
return V_75 ;
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
static struct V_6 * F_78 ( struct V_72 * V_72 )
{
return F_75 ( V_72 -> V_74 ) ;
}
static void F_79 ( struct V_6 * V_7 )
{
F_80 ( V_7 -> V_38 ) ;
}
static void F_81 ( T_1 * V_85 , const T_4 * V_86 )
{
int V_21 = F_82 ( V_87 , V_86 ) >> 26 ;
V_85 [ V_21 >> 5 ] |= ( 1 << ( V_21 & 31 ) ) ;
}
static unsigned int F_83 ( const T_1 * V_85 , const T_4 * V_86 )
{
int V_21 = F_82 ( V_87 , V_86 ) >> 26 ;
return V_85 [ V_21 >> 5 ] & ( 1 << ( V_21 & 31 ) ) ;
}
static int F_84 ( struct V_88 * V_89 , void T_5 * V_90 )
{
struct { T_4 V_91 [ V_87 ] ; } * V_86 ;
struct V_92 V_93 ;
int V_75 , V_94 , V_21 , V_95 ;
if ( F_85 ( & V_93 , V_90 , sizeof( V_93 ) ) )
return - V_96 ;
if ( ! V_93 . V_26 ) {
V_89 -> V_26 = 0 ;
return 0 ;
}
V_94 = V_87 * V_93 . V_26 ;
V_86 = F_5 ( V_94 , V_97 ) ;
if ( ! V_86 )
return - V_98 ;
if ( F_85 ( V_86 , V_90 + sizeof( V_93 ) , V_94 ) ) {
V_75 = - V_96 ;
goto V_99;
}
V_89 -> V_26 = 0 ;
F_86 () ;
for ( V_21 = 0 ; V_21 < V_93 . V_26 && V_21 < V_100 ; V_21 ++ )
memcpy ( V_89 -> V_86 [ V_21 ] , V_86 [ V_21 ] . V_91 , V_87 ) ;
V_95 = V_21 ;
memset ( V_89 -> V_85 , 0 , sizeof( V_89 -> V_85 ) ) ;
for (; V_21 < V_93 . V_26 ; V_21 ++ ) {
if ( ! F_87 ( V_86 [ V_21 ] . V_91 ) ) {
V_75 = 0 ;
goto V_99;
}
F_81 ( V_89 -> V_85 , V_86 [ V_21 ] . V_91 ) ;
}
if ( ( V_93 . V_62 & V_101 ) )
memset ( V_89 -> V_85 , ~ 0 , sizeof( V_89 -> V_85 ) ) ;
F_86 () ;
V_89 -> V_26 = V_95 ;
V_75 = V_95 ;
V_99:
F_88 ( V_86 ) ;
return V_75 ;
}
static int F_89 ( struct V_88 * V_89 , const struct V_39 * V_40 )
{
struct V_102 * V_103 = (struct V_102 * ) V_40 -> V_22 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_89 -> V_26 ; V_17 ++ )
if ( F_90 ( V_103 -> V_104 , V_89 -> V_86 [ V_17 ] ) )
return 1 ;
if ( F_87 ( V_103 -> V_104 ) )
return F_83 ( V_89 -> V_85 , V_103 -> V_104 ) ;
return 0 ;
}
static int F_91 ( struct V_88 * V_89 , const struct V_39 * V_40 )
{
if ( ! V_89 -> V_26 )
return 1 ;
return F_89 ( V_89 , V_40 ) ;
}
static void F_92 ( struct V_37 * V_38 )
{
F_66 ( V_38 ) ;
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
int V_43 = V_40 -> V_105 ;
struct V_29 * V_30 ;
T_1 V_32 = 0 ;
F_23 () ;
V_30 = F_76 ( V_7 -> V_61 [ V_43 ] ) ;
V_32 = F_32 ( V_7 -> V_32 ) ;
if ( V_43 >= V_32 )
goto V_106;
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
F_6 ( V_10 , V_7 , L_4 , V_40 -> V_107 ) ;
F_55 ( ! V_30 ) ;
if ( ! F_91 ( & V_7 -> V_108 , V_40 ) )
goto V_106;
if ( V_30 -> V_67 . V_55 -> V_109 &&
V_109 ( V_30 -> V_67 . V_55 , V_40 ) )
goto V_106;
if ( F_98 ( & V_30 -> V_67 . V_55 -> V_56 ) * V_32
>= V_38 -> V_110 )
goto V_106;
if ( F_29 ( F_99 ( V_40 , V_9 ) ) )
goto V_106;
if ( V_40 -> V_55 ) {
F_100 ( V_40 -> V_55 , & F_101 ( V_40 ) -> V_111 ) ;
F_102 ( V_40 ) ;
}
F_103 ( V_40 ) ;
F_104 ( V_40 ) ;
F_105 ( & V_30 -> V_67 . V_55 -> V_56 , V_40 ) ;
if ( V_30 -> V_62 & V_112 )
F_106 ( & V_30 -> V_113 , V_114 , V_115 ) ;
F_107 ( & V_30 -> V_69 . V_70 , V_116 |
V_117 | V_118 ) ;
F_27 () ;
return V_119 ;
V_106:
V_38 -> V_120 . V_121 ++ ;
F_108 ( V_40 ) ;
F_109 ( V_40 ) ;
F_27 () ;
return V_119 ;
}
static void F_110 ( struct V_37 * V_38 )
{
}
static int
F_111 ( struct V_37 * V_38 , int V_122 )
{
if ( V_122 < V_123 || V_122 + V_38 -> V_124 > V_125 )
return - V_78 ;
V_38 -> V_126 = V_122 ;
return 0 ;
}
static T_8 F_112 ( struct V_37 * V_38 ,
T_8 V_127 )
{
struct V_6 * V_7 = F_31 ( V_38 ) ;
return ( V_127 & V_7 -> V_128 ) | ( V_127 & ~ V_129 ) ;
}
static void F_113 ( struct V_37 * V_38 )
{
return;
}
static void F_114 ( struct V_6 * V_7 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_19 ; V_17 ++ )
F_115 ( & V_7 -> V_31 [ V_17 ] ) ;
V_7 -> V_24 = V_130 ;
F_116 ( & V_7 -> V_28 , F_17 , ( unsigned long ) V_7 ) ;
F_20 ( & V_7 -> V_28 ,
F_21 ( V_12 + V_7 -> V_24 ) ) ;
}
static void F_117 ( struct V_6 * V_7 )
{
F_118 ( & V_7 -> V_28 ) ;
F_12 ( V_7 ) ;
}
static void F_119 ( struct V_37 * V_38 )
{
struct V_6 * V_7 = F_31 ( V_38 ) ;
switch ( V_7 -> V_62 & V_131 ) {
case V_132 :
V_38 -> V_133 = & V_134 ;
V_38 -> V_124 = 0 ;
V_38 -> V_135 = 0 ;
V_38 -> V_126 = 1500 ;
V_38 -> type = V_136 ;
V_38 -> V_62 = V_137 | V_138 | V_139 ;
V_38 -> V_110 = V_140 ;
break;
case V_141 :
V_38 -> V_133 = & V_142 ;
F_120 ( V_38 ) ;
V_38 -> V_143 &= ~ V_144 ;
V_38 -> V_143 |= V_145 ;
F_121 ( V_38 ) ;
V_38 -> V_110 = V_140 ;
break;
}
}
static unsigned int F_122 ( struct V_72 * V_72 , T_9 * V_70 )
{
struct V_29 * V_30 = V_72 -> V_74 ;
struct V_6 * V_7 = F_75 ( V_30 ) ;
struct V_146 * V_55 ;
unsigned int V_85 = 0 ;
if ( ! V_7 )
return V_147 ;
V_55 = V_30 -> V_67 . V_55 ;
F_6 ( V_10 , V_7 , L_5 ) ;
F_123 ( V_72 , & V_30 -> V_69 . V_70 , V_70 ) ;
if ( ! F_124 ( & V_55 -> V_56 ) )
V_85 |= V_116 | V_117 ;
if ( F_125 ( V_55 ) ||
( ! F_126 ( V_148 , & V_55 -> V_149 -> V_62 ) &&
F_125 ( V_55 ) ) )
V_85 |= V_150 | V_151 ;
if ( V_7 -> V_38 -> V_64 != V_65 )
V_85 = V_147 ;
F_79 ( V_7 ) ;
return V_85 ;
}
static struct V_39 * F_127 ( struct V_29 * V_30 ,
T_10 V_152 , T_10 V_107 ,
T_10 V_153 , int V_154 )
{
struct V_146 * V_55 = V_30 -> V_67 . V_55 ;
struct V_39 * V_40 ;
int V_75 ;
if ( V_152 + V_107 < V_155 || ! V_153 )
V_153 = V_107 ;
V_40 = F_128 ( V_55 , V_152 + V_153 , V_107 - V_153 , V_154 ,
& V_75 , 0 ) ;
if ( ! V_40 )
return F_129 ( V_75 ) ;
F_130 ( V_40 , V_152 ) ;
F_131 ( V_40 , V_153 ) ;
V_40 -> V_156 = V_107 - V_153 ;
V_40 -> V_107 += V_107 - V_153 ;
return V_40 ;
}
static T_11 F_132 ( struct V_6 * V_7 , struct V_29 * V_30 ,
void * V_157 , const struct V_158 * V_159 ,
T_10 V_160 , T_10 V_26 , int V_154 )
{
struct V_161 V_162 = { 0 , F_133 (ETH_P_IP) } ;
struct V_39 * V_40 ;
T_10 V_107 = V_160 , V_163 = V_164 , V_153 ;
struct V_165 V_166 = { 0 } ;
int V_167 ;
int V_168 = 0 ;
int V_169 ;
bool V_170 = false ;
int V_75 ;
T_1 V_1 ;
if ( ! ( V_7 -> V_62 & V_171 ) ) {
if ( V_107 < sizeof( V_162 ) )
return - V_78 ;
V_107 -= sizeof( V_162 ) ;
if ( F_134 ( ( void * ) & V_162 , V_159 , 0 , sizeof( V_162 ) ) )
return - V_96 ;
V_168 += sizeof( V_162 ) ;
}
if ( V_7 -> V_62 & V_172 ) {
if ( V_107 < V_7 -> V_173 )
return - V_78 ;
V_107 -= V_7 -> V_173 ;
if ( F_134 ( ( void * ) & V_166 , V_159 , V_168 , sizeof( V_166 ) ) )
return - V_96 ;
if ( ( V_166 . V_62 & V_174 ) &&
V_166 . V_175 + V_166 . V_176 + 2 > V_166 . V_177 )
V_166 . V_177 = V_166 . V_175 + V_166 . V_176 + 2 ;
if ( V_166 . V_177 > V_107 )
return - V_78 ;
V_168 += V_7 -> V_173 ;
}
if ( ( V_7 -> V_62 & V_131 ) == V_141 ) {
V_163 += V_178 ;
if ( F_29 ( V_107 < V_179 ||
( V_166 . V_177 && V_166 . V_177 < V_179 ) ) )
return - V_78 ;
}
V_167 = F_135 ( V_163 ) ;
if ( V_157 ) {
V_169 = V_166 . V_177 ? V_166 . V_177 : V_180 ;
if ( V_169 > V_167 )
V_169 = V_167 ;
V_153 = V_169 ;
if ( F_136 ( V_159 , V_168 + V_169 , V_26 ) <= V_181 )
V_170 = true ;
}
if ( ! V_170 ) {
V_169 = V_107 ;
if ( V_166 . V_177 > V_167 )
V_153 = V_167 ;
else
V_153 = V_166 . V_177 ;
}
V_40 = F_127 ( V_30 , V_163 , V_169 , V_153 , V_154 ) ;
if ( F_137 ( V_40 ) ) {
if ( F_138 ( V_40 ) != - V_182 )
V_7 -> V_38 -> V_120 . V_183 ++ ;
return F_138 ( V_40 ) ;
}
if ( V_170 )
V_75 = F_139 ( V_40 , V_159 , V_168 , V_26 ) ;
else {
V_75 = F_140 ( V_40 , 0 , V_159 , V_168 , V_107 ) ;
if ( ! V_75 && V_157 ) {
struct V_184 * V_185 = V_157 ;
V_185 -> V_186 ( V_185 , false ) ;
}
}
if ( V_75 ) {
V_7 -> V_38 -> V_120 . V_183 ++ ;
F_109 ( V_40 ) ;
return - V_96 ;
}
if ( V_166 . V_62 & V_174 ) {
if ( ! F_141 ( V_40 , V_166 . V_175 ,
V_166 . V_176 ) ) {
V_7 -> V_38 -> V_120 . V_187 ++ ;
F_109 ( V_40 ) ;
return - V_78 ;
}
}
switch ( V_7 -> V_62 & V_131 ) {
case V_132 :
if ( V_7 -> V_62 & V_171 ) {
switch ( V_40 -> V_22 [ 0 ] & 0xf0 ) {
case 0x40 :
V_162 . V_188 = F_142 ( V_189 ) ;
break;
case 0x60 :
V_162 . V_188 = F_142 ( V_190 ) ;
break;
default:
V_7 -> V_38 -> V_120 . V_183 ++ ;
F_109 ( V_40 ) ;
return - V_78 ;
}
}
F_143 ( V_40 ) ;
V_40 -> V_191 = V_162 . V_188 ;
V_40 -> V_38 = V_7 -> V_38 ;
break;
case V_141 :
V_40 -> V_191 = F_144 ( V_40 , V_7 -> V_38 ) ;
break;
}
if ( V_166 . V_192 != V_193 ) {
F_145 ( L_6 ) ;
switch ( V_166 . V_192 & ~ V_194 ) {
case V_195 :
F_101 ( V_40 ) -> V_192 = V_196 ;
break;
case V_197 :
F_101 ( V_40 ) -> V_192 = V_198 ;
break;
case V_199 :
F_101 ( V_40 ) -> V_192 = V_200 ;
break;
default:
V_7 -> V_38 -> V_120 . V_187 ++ ;
F_109 ( V_40 ) ;
return - V_78 ;
}
if ( V_166 . V_192 & V_194 )
F_101 ( V_40 ) -> V_192 |= V_201 ;
F_101 ( V_40 ) -> V_202 = V_166 . V_202 ;
if ( F_101 ( V_40 ) -> V_202 == 0 ) {
V_7 -> V_38 -> V_120 . V_187 ++ ;
F_109 ( V_40 ) ;
return - V_78 ;
}
F_101 ( V_40 ) -> V_192 |= V_203 ;
F_101 ( V_40 ) -> V_204 = 0 ;
}
if ( V_170 ) {
F_101 ( V_40 ) -> V_205 = V_157 ;
F_101 ( V_40 ) -> V_111 |= V_206 ;
F_101 ( V_40 ) -> V_111 |= V_207 ;
}
F_146 ( V_40 ) ;
F_147 ( V_40 , 0 ) ;
V_1 = F_33 ( V_40 ) ;
F_148 ( V_40 ) ;
V_7 -> V_38 -> V_120 . V_208 ++ ;
V_7 -> V_38 -> V_120 . V_209 += V_107 ;
F_22 ( V_7 , V_1 , V_30 ) ;
return V_160 ;
}
static T_11 F_149 ( struct V_210 * V_211 , const struct V_158 * V_159 ,
unsigned long V_26 , T_12 V_212 )
{
struct V_72 * V_72 = V_211 -> V_213 ;
struct V_6 * V_7 = F_78 ( V_72 ) ;
struct V_29 * V_30 = V_72 -> V_74 ;
T_11 V_214 ;
if ( ! V_7 )
return - V_215 ;
F_6 ( V_10 , V_7 , L_7 , V_26 ) ;
V_214 = F_132 ( V_7 , V_30 , NULL , V_159 , F_150 ( V_159 , V_26 ) ,
V_26 , V_72 -> V_216 & V_217 ) ;
F_79 ( V_7 ) ;
return V_214 ;
}
static T_11 F_151 ( struct V_6 * V_7 ,
struct V_29 * V_30 ,
struct V_39 * V_40 ,
const struct V_158 * V_159 , int V_107 )
{
struct V_161 V_162 = { 0 , V_40 -> V_191 } ;
T_11 V_218 = 0 ;
int V_219 = 0 , V_220 ;
if ( ! ( V_7 -> V_62 & V_171 ) ) {
if ( ( V_107 -= sizeof( V_162 ) ) < 0 )
return - V_78 ;
if ( V_107 < V_40 -> V_107 ) {
V_162 . V_62 |= V_221 ;
}
if ( F_152 ( V_159 , ( void * ) & V_162 , 0 , sizeof( V_162 ) ) )
return - V_96 ;
V_218 += sizeof( V_162 ) ;
}
if ( V_7 -> V_62 & V_172 ) {
struct V_165 V_166 = { 0 } ;
if ( ( V_107 -= V_7 -> V_173 ) < 0 )
return - V_78 ;
if ( F_153 ( V_40 ) ) {
struct V_222 * V_223 = F_101 ( V_40 ) ;
V_166 . V_177 = F_154 ( V_40 ) ;
V_166 . V_202 = V_223 -> V_202 ;
if ( V_223 -> V_192 & V_196 )
V_166 . V_192 = V_195 ;
else if ( V_223 -> V_192 & V_198 )
V_166 . V_192 = V_197 ;
else if ( V_223 -> V_192 & V_200 )
V_166 . V_192 = V_199 ;
else {
F_155 ( L_8
L_9 ,
V_223 -> V_192 , V_166 . V_202 ,
V_166 . V_177 ) ;
F_156 ( V_224 , L_10 ,
V_225 ,
16 , 1 , V_40 -> V_4 ,
F_157 ( ( int ) V_166 . V_177 , 64 ) , true ) ;
F_158 ( 1 ) ;
return - V_78 ;
}
if ( V_223 -> V_192 & V_201 )
V_166 . V_192 |= V_194 ;
} else
V_166 . V_192 = V_193 ;
if ( V_40 -> V_226 == V_227 ) {
V_166 . V_62 = V_174 ;
V_166 . V_175 = F_159 ( V_40 ) ;
V_166 . V_176 = V_40 -> V_176 ;
} else if ( V_40 -> V_226 == V_228 ) {
V_166 . V_62 = V_229 ;
}
if ( F_29 ( F_152 ( V_159 , ( void * ) & V_166 , V_218 ,
sizeof( V_166 ) ) ) )
return - V_96 ;
V_218 += V_7 -> V_173 ;
}
V_220 = V_218 ;
V_218 += V_40 -> V_107 ;
if ( ! F_160 ( V_40 ) ) {
V_107 = F_161 ( int , V_40 -> V_107 , V_107 ) ;
} else {
int V_230 , V_231 ;
struct {
T_13 V_232 ;
T_13 V_233 ;
} V_234 ;
V_234 . V_232 = V_40 -> V_235 ;
V_234 . V_233 = F_142 ( F_162 ( V_40 ) ) ;
V_219 = F_163 ( struct V_236 , V_232 ) ;
V_107 = F_161 ( int , V_40 -> V_107 + V_237 , V_107 ) ;
V_218 += V_237 ;
V_230 = F_161 ( int , V_219 , V_107 ) ;
V_231 = F_164 ( V_40 , 0 , V_159 , V_220 , V_230 ) ;
V_107 -= V_230 ;
V_220 += V_230 ;
if ( V_231 || ! V_107 )
goto V_99;
V_230 = F_161 ( int , sizeof( V_234 ) , V_107 ) ;
V_231 = F_152 ( V_159 , ( void * ) & V_234 , V_220 , V_230 ) ;
V_107 -= V_230 ;
V_220 += V_230 ;
if ( V_231 || ! V_107 )
goto V_99;
}
F_164 ( V_40 , V_219 , V_159 , V_220 , V_107 ) ;
V_99:
V_7 -> V_38 -> V_120 . V_238 ++ ;
V_7 -> V_38 -> V_120 . V_239 += V_107 ;
return V_218 ;
}
static T_11 F_165 ( struct V_6 * V_7 , struct V_29 * V_30 ,
const struct V_158 * V_159 , T_11 V_107 , int V_154 )
{
F_166 ( V_70 , V_240 ) ;
struct V_39 * V_40 ;
T_11 V_231 = 0 ;
F_6 ( V_10 , V_7 , L_11 ) ;
if ( F_29 ( ! V_154 ) )
F_167 ( & V_30 -> V_69 . V_70 , & V_70 ) ;
while ( V_107 ) {
if ( F_29 ( ! V_154 ) )
V_240 -> V_241 = V_242 ;
if ( ! ( V_40 = F_168 ( & V_30 -> V_67 . V_55 -> V_56 ) ) ) {
if ( V_154 ) {
V_231 = - V_182 ;
break;
}
if ( F_169 ( V_240 ) ) {
V_231 = - V_243 ;
break;
}
if ( V_7 -> V_38 -> V_64 != V_65 ) {
V_231 = - V_244 ;
break;
}
F_170 () ;
continue;
}
V_231 = F_151 ( V_7 , V_30 , V_40 , V_159 , V_107 ) ;
F_109 ( V_40 ) ;
break;
}
if ( F_29 ( ! V_154 ) ) {
V_240 -> V_241 = V_245 ;
F_171 ( & V_30 -> V_69 . V_70 , & V_70 ) ;
}
return V_231 ;
}
static T_11 F_172 ( struct V_210 * V_211 , const struct V_158 * V_159 ,
unsigned long V_26 , T_12 V_212 )
{
struct V_72 * V_72 = V_211 -> V_213 ;
struct V_29 * V_30 = V_72 -> V_74 ;
struct V_6 * V_7 = F_75 ( V_30 ) ;
T_11 V_107 , V_231 ;
if ( ! V_7 )
return - V_215 ;
V_107 = F_150 ( V_159 , V_26 ) ;
if ( V_107 < 0 ) {
V_231 = - V_78 ;
goto V_77;
}
V_231 = F_165 ( V_7 , V_30 , V_159 , V_107 ,
V_72 -> V_216 & V_217 ) ;
V_231 = F_161 ( T_11 , V_231 , V_107 ) ;
if ( V_231 > 0 )
V_211 -> V_246 = V_231 ;
V_77:
F_79 ( V_7 ) ;
return V_231 ;
}
static void F_173 ( struct V_37 * V_38 )
{
struct V_6 * V_7 = F_31 ( V_38 ) ;
F_55 ( ! ( F_174 ( & V_7 -> V_53 ) ) ) ;
F_117 ( V_7 ) ;
F_175 ( V_7 -> V_76 ) ;
F_176 ( V_38 ) ;
}
static void F_177 ( struct V_37 * V_38 )
{
struct V_6 * V_7 = F_31 ( V_38 ) ;
V_7 -> V_47 = V_247 ;
V_7 -> V_49 = V_248 ;
V_38 -> V_249 = & V_250 ;
V_38 -> V_251 = F_173 ;
}
static int F_178 ( struct V_252 * V_253 [] , struct V_252 * V_22 [] )
{
return - V_78 ;
}
static void F_179 ( struct V_146 * V_55 )
{
struct V_29 * V_30 ;
T_14 * V_254 ;
if ( ! F_125 ( V_55 ) )
return;
if ( ! F_180 ( V_148 , & V_55 -> V_149 -> V_62 ) )
return;
V_254 = F_181 ( V_55 ) ;
if ( V_254 && F_182 ( V_254 ) )
F_183 ( V_254 , V_150 |
V_151 | V_255 ) ;
V_30 = F_184 ( V_55 , struct V_29 , V_55 ) ;
F_106 ( & V_30 -> V_113 , V_114 , V_256 ) ;
}
static int F_185 ( struct V_210 * V_211 , struct V_67 * V_146 ,
struct V_257 * V_258 , T_10 V_160 )
{
int V_231 ;
struct V_29 * V_30 = F_184 ( V_146 , struct V_29 , V_67 ) ;
struct V_6 * V_7 = F_75 ( V_30 ) ;
if ( ! V_7 )
return - V_215 ;
V_231 = F_132 ( V_7 , V_30 , V_258 -> V_157 , V_258 -> V_259 , V_160 ,
V_258 -> V_260 , V_258 -> V_261 & V_262 ) ;
F_79 ( V_7 ) ;
return V_231 ;
}
static int F_186 ( struct V_210 * V_211 , struct V_67 * V_146 ,
struct V_257 * V_258 , T_10 V_160 ,
int V_62 )
{
struct V_29 * V_30 = F_184 ( V_146 , struct V_29 , V_67 ) ;
struct V_6 * V_7 = F_75 ( V_30 ) ;
int V_231 ;
if ( ! V_7 )
return - V_215 ;
if ( V_62 & ~ ( V_262 | V_263 | V_264 ) ) {
V_231 = - V_78 ;
goto V_77;
}
if ( V_62 & V_264 ) {
V_231 = F_187 ( V_146 -> V_55 , V_258 , V_160 ,
V_265 , V_266 ) ;
goto V_77;
}
V_231 = F_165 ( V_7 , V_30 , V_258 -> V_259 , V_160 ,
V_62 & V_262 ) ;
if ( V_231 > V_160 ) {
V_258 -> V_261 |= V_263 ;
V_231 = V_62 & V_263 ? V_231 : V_160 ;
}
V_77:
F_79 ( V_7 ) ;
return V_231 ;
}
static int F_188 ( struct V_67 * V_146 )
{
if ( V_146 -> V_55 )
F_57 ( V_146 -> V_55 ) ;
return 0 ;
}
static int F_189 ( struct V_6 * V_7 )
{
int V_62 = 0 ;
if ( V_7 -> V_62 & V_132 )
V_62 |= V_267 ;
else
V_62 |= V_268 ;
if ( V_7 -> V_62 & V_171 )
V_62 |= V_269 ;
if ( V_7 -> V_62 & V_270 )
V_62 |= V_271 ;
if ( V_7 -> V_62 & V_172 )
V_62 |= V_272 ;
if ( V_7 -> V_62 & V_80 )
V_62 |= V_273 ;
if ( V_7 -> V_62 & V_63 )
V_62 |= V_274 ;
return V_62 ;
}
static T_11 F_190 ( struct V_275 * V_38 , struct V_276 * V_277 ,
char * V_278 )
{
struct V_6 * V_7 = F_31 ( F_191 ( V_38 ) ) ;
return sprintf ( V_278 , L_12 , F_189 ( V_7 ) ) ;
}
static T_11 F_192 ( struct V_275 * V_38 , struct V_276 * V_277 ,
char * V_278 )
{
struct V_6 * V_7 = F_31 ( F_191 ( V_38 ) ) ;
return F_39 ( V_7 -> V_47 ) ?
sprintf ( V_278 , L_13 ,
F_193 ( F_194 () , V_7 -> V_47 ) ) :
sprintf ( V_278 , L_14 ) ;
}
static T_11 F_195 ( struct V_275 * V_38 , struct V_276 * V_277 ,
char * V_278 )
{
struct V_6 * V_7 = F_31 ( F_191 ( V_38 ) ) ;
return F_41 ( V_7 -> V_49 ) ?
sprintf ( V_278 , L_13 ,
F_196 ( F_194 () , V_7 -> V_49 ) ) :
sprintf ( V_278 , L_14 ) ;
}
static int F_197 ( struct V_46 * V_46 , struct V_72 * V_72 , struct V_279 * V_280 )
{
struct V_6 * V_7 ;
struct V_29 * V_30 = V_72 -> V_74 ;
struct V_37 * V_38 ;
int V_75 ;
if ( V_30 -> V_33 )
return - V_78 ;
V_38 = F_198 ( V_46 , V_280 -> V_281 ) ;
if ( V_38 ) {
if ( V_280 -> V_282 & V_283 )
return - V_79 ;
if ( ( V_280 -> V_282 & V_267 ) && V_38 -> V_133 == & V_134 )
V_7 = F_31 ( V_38 ) ;
else if ( ( V_280 -> V_282 & V_268 ) && V_38 -> V_133 == & V_142 )
V_7 = F_31 ( V_38 ) ;
else
return - V_78 ;
if ( ! ! ( V_280 -> V_282 & V_273 ) !=
! ! ( V_7 -> V_62 & V_80 ) )
return - V_78 ;
if ( F_36 ( V_7 ) )
return - V_284 ;
V_75 = F_199 ( V_7 -> V_76 ) ;
if ( V_75 < 0 )
return V_75 ;
V_75 = F_71 ( V_7 , V_72 , V_280 -> V_282 & V_285 ) ;
if ( V_75 < 0 )
return V_75 ;
if ( V_7 -> V_62 & V_80 &&
( V_7 -> V_32 + V_7 -> V_54 > 1 ) ) {
return 0 ;
}
}
else {
char * V_286 ;
unsigned long V_62 = 0 ;
int V_287 = V_280 -> V_282 & V_273 ?
V_82 : 1 ;
if ( ! F_43 ( V_46 -> V_50 , V_51 ) )
return - V_284 ;
V_75 = F_200 () ;
if ( V_75 < 0 )
return V_75 ;
if ( V_280 -> V_282 & V_267 ) {
V_62 |= V_132 ;
V_286 = L_15 ;
} else if ( V_280 -> V_282 & V_268 ) {
V_62 |= V_141 ;
V_286 = L_16 ;
} else
return - V_78 ;
if ( * V_280 -> V_281 )
V_286 = V_280 -> V_281 ;
V_38 = F_201 ( sizeof( struct V_6 ) , V_286 ,
F_177 , V_287 , V_287 ) ;
if ( ! V_38 )
return - V_98 ;
F_202 ( V_38 , V_46 ) ;
V_38 -> V_288 = & V_289 ;
V_38 -> V_290 = V_30 -> V_290 ;
V_7 = F_31 ( V_38 ) ;
V_7 -> V_38 = V_38 ;
V_7 -> V_62 = V_62 ;
V_7 -> V_108 . V_26 = 0 ;
V_7 -> V_173 = sizeof( struct V_165 ) ;
V_7 -> V_83 = false ;
V_7 -> V_291 = V_30 -> V_67 . V_55 -> V_292 ;
F_203 ( & V_7 -> V_18 ) ;
V_75 = F_204 ( & V_7 -> V_76 ) ;
if ( V_75 < 0 )
goto V_293;
F_119 ( V_38 ) ;
F_114 ( V_7 ) ;
V_38 -> V_294 = V_295 | V_296 |
V_129 | V_297 |
V_298 ;
V_38 -> V_127 = V_38 -> V_294 ;
V_38 -> V_299 = V_38 -> V_127 &
~ ( V_297 |
V_298 ) ;
F_205 ( & V_7 -> V_53 ) ;
V_75 = F_71 ( V_7 , V_72 , false ) ;
if ( V_75 < 0 )
goto V_300;
V_75 = F_206 ( V_7 -> V_38 ) ;
if ( V_75 < 0 )
goto V_301;
if ( F_207 ( & V_7 -> V_38 -> V_38 , & V_302 ) ||
F_207 ( & V_7 -> V_38 -> V_38 , & V_303 ) ||
F_207 ( & V_7 -> V_38 -> V_38 , & V_304 ) )
F_155 ( L_17 ) ;
}
F_208 ( V_7 -> V_38 ) ;
F_6 ( V_10 , V_7 , L_18 ) ;
if ( V_280 -> V_282 & V_269 )
V_7 -> V_62 |= V_171 ;
else
V_7 -> V_62 &= ~ V_171 ;
if ( V_280 -> V_282 & V_271 )
V_7 -> V_62 |= V_270 ;
else
V_7 -> V_62 &= ~ V_270 ;
if ( V_280 -> V_282 & V_272 )
V_7 -> V_62 |= V_172 ;
else
V_7 -> V_62 &= ~ V_172 ;
if ( V_280 -> V_282 & V_273 )
V_7 -> V_62 |= V_80 ;
else
V_7 -> V_62 &= ~ V_80 ;
if ( F_209 ( V_7 -> V_38 ) )
F_210 ( V_7 -> V_38 ) ;
strcpy ( V_280 -> V_281 , V_7 -> V_38 -> V_286 ) ;
return 0 ;
V_301:
F_66 ( V_38 ) ;
V_300:
F_117 ( V_7 ) ;
F_175 ( V_7 -> V_76 ) ;
V_293:
F_176 ( V_38 ) ;
return V_75 ;
}
static void F_211 ( struct V_46 * V_46 , struct V_6 * V_7 ,
struct V_279 * V_280 )
{
F_6 ( V_10 , V_7 , L_19 ) ;
strcpy ( V_280 -> V_281 , V_7 -> V_38 -> V_286 ) ;
V_280 -> V_282 = F_189 ( V_7 ) ;
}
static int F_212 ( struct V_6 * V_7 , unsigned long V_90 )
{
T_8 V_127 = 0 ;
if ( V_90 & V_305 ) {
V_127 |= V_306 ;
V_90 &= ~ V_305 ;
if ( V_90 & ( V_307 | V_308 ) ) {
if ( V_90 & V_309 ) {
V_127 |= V_310 ;
V_90 &= ~ V_309 ;
}
if ( V_90 & V_307 )
V_127 |= V_311 ;
if ( V_90 & V_308 )
V_127 |= V_312 ;
V_90 &= ~ ( V_307 | V_308 ) ;
}
if ( V_90 & V_313 ) {
V_127 |= V_314 ;
V_90 &= ~ V_313 ;
}
}
if ( V_90 )
return - V_78 ;
V_7 -> V_128 = V_127 ;
F_213 ( V_7 -> V_38 ) ;
return 0 ;
}
static void F_214 ( struct V_6 * V_7 , int V_21 )
{
int V_17 ;
struct V_29 * V_30 ;
for ( V_17 = 0 ; V_17 < V_21 ; V_17 ++ ) {
V_30 = F_54 ( V_7 -> V_61 [ V_17 ] ) ;
F_215 ( V_30 -> V_67 . V_55 ) ;
}
V_7 -> V_83 = false ;
}
static int F_216 ( struct V_6 * V_7 )
{
int V_17 , V_231 = 0 ;
struct V_29 * V_30 ;
for ( V_17 = 0 ; V_17 < V_7 -> V_32 ; V_17 ++ ) {
V_30 = F_54 ( V_7 -> V_61 [ V_17 ] ) ;
V_231 = F_73 ( & V_7 -> V_84 , V_30 -> V_67 . V_55 ) ;
if ( V_231 ) {
F_214 ( V_7 , V_17 ) ;
return V_231 ;
}
}
V_7 -> V_83 = true ;
return V_231 ;
}
static void F_217 ( struct V_6 * V_7 )
{
struct V_29 * V_30 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_7 -> V_32 ; V_17 ++ ) {
V_30 = F_54 ( V_7 -> V_61 [ V_17 ] ) ;
V_30 -> V_67 . V_55 -> V_292 = V_7 -> V_291 ;
}
}
static int F_218 ( struct V_72 * V_72 , struct V_279 * V_280 )
{
struct V_29 * V_30 = V_72 -> V_74 ;
struct V_6 * V_7 ;
int V_231 = 0 ;
F_64 () ;
if ( V_280 -> V_282 & V_315 ) {
V_7 = V_30 -> V_33 ;
if ( ! V_7 ) {
V_231 = - V_78 ;
goto V_34;
}
V_231 = F_219 ( V_7 -> V_76 ) ;
if ( V_231 < 0 )
goto V_34;
V_231 = F_71 ( V_7 , V_72 , false ) ;
} else if ( V_280 -> V_282 & V_316 ) {
V_7 = F_54 ( V_30 -> V_7 ) ;
if ( ! V_7 || ! ( V_7 -> V_62 & V_80 ) || V_30 -> V_33 )
V_231 = - V_78 ;
else
F_53 ( V_30 , false ) ;
} else
V_231 = - V_78 ;
V_34:
F_65 () ;
return V_231 ;
}
static long F_220 ( struct V_72 * V_72 , unsigned int V_317 ,
unsigned long V_90 , int V_318 )
{
struct V_29 * V_30 = V_72 -> V_74 ;
struct V_6 * V_7 ;
void T_5 * V_319 = ( void T_5 * ) V_90 ;
struct V_279 V_280 ;
T_15 V_47 ;
T_16 V_49 ;
int V_291 ;
int V_173 ;
unsigned int V_290 ;
int V_231 ;
if ( V_317 == V_320 || V_317 == V_321 || F_221 ( V_317 ) == 0x89 ) {
if ( F_85 ( & V_280 , V_319 , V_318 ) )
return - V_96 ;
} else {
memset ( & V_280 , 0 , sizeof( V_280 ) ) ;
}
if ( V_317 == V_322 ) {
return F_222 ( V_267 | V_268 | V_269 | V_271 |
V_272 | V_273 ,
( unsigned int T_5 * ) V_319 ) ;
} else if ( V_317 == V_321 )
return F_218 ( V_72 , & V_280 ) ;
V_231 = 0 ;
F_64 () ;
V_7 = F_75 ( V_30 ) ;
if ( V_317 == V_320 && ! V_7 ) {
V_280 . V_281 [ V_323 - 1 ] = '\0' ;
V_231 = F_197 ( V_30 -> V_46 , V_72 , & V_280 ) ;
if ( V_231 )
goto V_34;
if ( F_223 ( V_319 , & V_280 , V_318 ) )
V_231 = - V_96 ;
goto V_34;
}
if ( V_317 == V_324 ) {
V_231 = - V_284 ;
if ( V_7 )
goto V_34;
V_231 = - V_96 ;
if ( F_85 ( & V_290 , V_319 , sizeof( V_290 ) ) )
goto V_34;
V_231 = 0 ;
V_30 -> V_290 = V_290 ;
goto V_34;
}
V_231 = - V_215 ;
if ( ! V_7 )
goto V_34;
F_6 ( V_10 , V_7 , L_20 , V_317 ) ;
V_231 = 0 ;
switch ( V_317 ) {
case V_325 :
F_211 ( V_240 -> V_326 -> V_327 , V_7 , & V_280 ) ;
if ( V_30 -> V_33 )
V_280 . V_282 |= V_316 ;
if ( ! V_30 -> V_67 . V_55 -> V_109 )
V_280 . V_282 |= V_285 ;
if ( F_223 ( V_319 , & V_280 , V_318 ) )
V_231 = - V_96 ;
break;
case V_328 :
F_6 ( V_10 , V_7 , L_21 ,
V_90 ? L_22 : L_23 ) ;
break;
case V_329 :
if ( V_90 && ! ( V_7 -> V_62 & V_63 ) ) {
V_7 -> V_62 |= V_63 ;
F_224 ( V_71 ) ;
}
if ( ! V_90 && ( V_7 -> V_62 & V_63 ) ) {
V_7 -> V_62 &= ~ V_63 ;
F_70 ( V_71 ) ;
}
F_6 ( V_10 , V_7 , L_24 ,
V_90 ? L_23 : L_22 ) ;
break;
case V_330 :
V_47 = F_225 ( F_194 () , V_90 ) ;
if ( ! F_39 ( V_47 ) ) {
V_231 = - V_78 ;
break;
}
V_7 -> V_47 = V_47 ;
F_6 ( V_10 , V_7 , L_25 ,
F_226 ( & V_331 , V_7 -> V_47 ) ) ;
break;
case V_332 :
V_49 = F_227 ( F_194 () , V_90 ) ;
if ( ! F_41 ( V_49 ) ) {
V_231 = - V_78 ;
break;
}
V_7 -> V_49 = V_49 ;
F_6 ( V_10 , V_7 , L_26 ,
F_228 ( & V_331 , V_7 -> V_49 ) ) ;
break;
case V_333 :
if ( V_7 -> V_38 -> V_62 & V_334 ) {
F_6 ( V_10 , V_7 ,
L_27 ) ;
V_231 = - V_79 ;
} else {
V_7 -> V_38 -> type = ( int ) V_90 ;
F_6 ( V_10 , V_7 , L_28 ,
V_7 -> V_38 -> type ) ;
V_231 = 0 ;
}
break;
#ifdef F_229
case V_335 :
V_7 -> V_336 = V_90 ;
break;
#endif
case V_337 :
V_231 = F_212 ( V_7 , V_90 ) ;
break;
case V_338 :
V_231 = - V_78 ;
if ( ( V_7 -> V_62 & V_131 ) != V_141 )
break;
V_231 = F_84 ( & V_7 -> V_108 , ( void T_5 * ) V_90 ) ;
break;
case V_339 :
memcpy ( V_280 . V_340 . V_341 , V_7 -> V_38 -> V_342 , V_87 ) ;
V_280 . V_340 . V_343 = V_7 -> V_38 -> type ;
if ( F_223 ( V_319 , & V_280 , V_318 ) )
V_231 = - V_96 ;
break;
case V_344 :
F_6 ( V_345 , V_7 , L_29 ,
V_280 . V_340 . V_341 ) ;
V_231 = F_230 ( V_7 -> V_38 , & V_280 . V_340 ) ;
break;
case V_346 :
V_291 = V_30 -> V_67 . V_55 -> V_292 ;
if ( F_223 ( V_319 , & V_291 , sizeof( V_291 ) ) )
V_231 = - V_96 ;
break;
case V_347 :
if ( F_85 ( & V_291 , V_319 , sizeof( V_291 ) ) ) {
V_231 = - V_96 ;
break;
}
V_7 -> V_291 = V_291 ;
F_217 ( V_7 ) ;
break;
case V_348 :
V_173 = V_7 -> V_173 ;
if ( F_223 ( V_319 , & V_173 , sizeof( V_173 ) ) )
V_231 = - V_96 ;
break;
case V_349 :
if ( F_85 ( & V_173 , V_319 , sizeof( V_173 ) ) ) {
V_231 = - V_96 ;
break;
}
if ( V_173 < ( int ) sizeof( struct V_165 ) ) {
V_231 = - V_78 ;
break;
}
V_7 -> V_173 = V_173 ;
break;
case V_350 :
V_231 = - V_78 ;
if ( ( V_7 -> V_62 & V_131 ) != V_141 )
break;
V_231 = - V_96 ;
if ( F_85 ( & V_7 -> V_84 , V_319 , sizeof( V_7 -> V_84 ) ) )
break;
V_231 = F_216 ( V_7 ) ;
break;
case V_351 :
V_231 = - V_78 ;
if ( ( V_7 -> V_62 & V_131 ) != V_141 )
break;
V_231 = 0 ;
F_214 ( V_7 , V_7 -> V_32 ) ;
break;
case V_352 :
V_231 = - V_78 ;
if ( ( V_7 -> V_62 & V_131 ) != V_141 )
break;
V_231 = - V_96 ;
if ( F_223 ( V_319 , & V_7 -> V_84 , sizeof( V_7 -> V_84 ) ) )
break;
V_231 = 0 ;
break;
default:
V_231 = - V_78 ;
break;
}
V_34:
F_65 () ;
if ( V_7 )
F_79 ( V_7 ) ;
return V_231 ;
}
static long F_231 ( struct V_72 * V_72 ,
unsigned int V_317 , unsigned long V_90 )
{
return F_220 ( V_72 , V_317 , V_90 , sizeof ( struct V_279 ) ) ;
}
static long F_232 ( struct V_72 * V_72 ,
unsigned int V_317 , unsigned long V_90 )
{
switch ( V_317 ) {
case V_320 :
case V_325 :
case V_338 :
case V_346 :
case V_347 :
case V_339 :
case V_344 :
V_90 = ( unsigned long ) F_233 ( V_90 ) ;
break;
default:
V_90 = ( V_353 ) V_90 ;
break;
}
return F_220 ( V_72 , V_317 , V_90 , sizeof( struct V_354 ) ) ;
}
static int F_234 ( int V_355 , struct V_72 * V_72 , int V_356 )
{
struct V_29 * V_30 = V_72 -> V_74 ;
int V_231 ;
if ( ( V_231 = F_235 ( V_355 , V_72 , V_356 , & V_30 -> V_113 ) ) < 0 )
goto V_77;
if ( V_356 ) {
V_231 = F_236 ( V_72 , F_237 ( V_240 ) , V_357 , 0 ) ;
if ( V_231 )
goto V_77;
V_30 -> V_62 |= V_112 ;
} else
V_30 -> V_62 &= ~ V_112 ;
V_231 = 0 ;
V_77:
return V_231 ;
}
static int F_238 ( struct V_358 * V_358 , struct V_72 * V_72 )
{
struct V_29 * V_30 ;
F_239 ( V_10 , L_30 ) ;
V_30 = (struct V_29 * ) F_240 ( & V_359 , V_360 , V_97 ,
& V_361 ) ;
if ( ! V_30 )
return - V_98 ;
F_56 ( V_30 -> V_7 , NULL ) ;
V_30 -> V_46 = F_241 ( V_240 -> V_326 -> V_327 ) ;
V_30 -> V_62 = 0 ;
V_30 -> V_290 = 0 ;
F_56 ( V_30 -> V_67 . V_69 , & V_30 -> V_69 ) ;
F_242 ( & V_30 -> V_69 . V_70 ) ;
V_30 -> V_67 . V_72 = V_72 ;
V_30 -> V_67 . V_362 = & V_363 ;
F_243 ( & V_30 -> V_67 , & V_30 -> V_55 ) ;
F_244 ( & V_30 -> V_55 , V_30 -> V_46 ) ;
V_30 -> V_55 . V_364 = F_179 ;
V_30 -> V_55 . V_292 = V_365 ;
V_72 -> V_74 = V_30 ;
F_245 ( V_66 , & V_30 -> V_67 . V_62 ) ;
F_205 ( & V_30 -> V_52 ) ;
F_246 ( & V_30 -> V_55 , V_366 ) ;
return 0 ;
}
static int F_247 ( struct V_358 * V_358 , struct V_72 * V_72 )
{
struct V_29 * V_30 = V_72 -> V_74 ;
struct V_46 * V_46 = V_30 -> V_46 ;
F_63 ( V_30 , true ) ;
F_248 ( V_46 ) ;
return 0 ;
}
static int F_249 ( struct V_367 * V_258 , struct V_72 * V_368 )
{
struct V_6 * V_7 ;
struct V_279 V_280 ;
memset ( & V_280 , 0 , sizeof( V_280 ) ) ;
F_64 () ;
V_7 = F_78 ( V_368 ) ;
if ( V_7 )
F_211 ( V_240 -> V_326 -> V_327 , V_7 , & V_280 ) ;
F_65 () ;
if ( V_7 )
F_79 ( V_7 ) ;
return F_250 ( V_258 , L_31 , V_280 . V_281 ) ;
}
static int F_251 ( struct V_37 * V_38 , struct V_369 * V_317 )
{
V_317 -> V_370 = 0 ;
V_317 -> V_371 = 0 ;
F_252 ( V_317 , V_372 ) ;
V_317 -> V_373 = V_374 ;
V_317 -> V_375 = V_376 ;
V_317 -> V_377 = 0 ;
V_317 -> V_378 = V_379 ;
V_317 -> V_380 = V_381 ;
V_317 -> V_382 = 0 ;
V_317 -> V_383 = 0 ;
return 0 ;
}
static void F_253 ( struct V_37 * V_38 , struct V_384 * V_385 )
{
struct V_6 * V_7 = F_31 ( V_38 ) ;
F_254 ( V_385 -> V_386 , V_387 , sizeof( V_385 -> V_386 ) ) ;
F_254 ( V_385 -> V_388 , V_389 , sizeof( V_385 -> V_388 ) ) ;
switch ( V_7 -> V_62 & V_131 ) {
case V_132 :
F_254 ( V_385 -> V_390 , L_32 , sizeof( V_385 -> V_390 ) ) ;
break;
case V_141 :
F_254 ( V_385 -> V_390 , L_33 , sizeof( V_385 -> V_390 ) ) ;
break;
}
}
static T_1 F_255 ( struct V_37 * V_38 )
{
#ifdef F_229
struct V_6 * V_7 = F_31 ( V_38 ) ;
return V_7 -> V_336 ;
#else
return - V_391 ;
#endif
}
static void F_256 ( struct V_37 * V_38 , T_1 V_392 )
{
#ifdef F_229
struct V_6 * V_7 = F_31 ( V_38 ) ;
V_7 -> V_336 = V_392 ;
#endif
}
static int T_17 F_257 ( void )
{
int V_231 = 0 ;
F_258 ( L_34 , V_393 , V_389 ) ;
F_258 ( L_35 , V_394 ) ;
V_231 = F_259 ( & V_289 ) ;
if ( V_231 ) {
F_155 ( L_36 ) ;
goto V_395;
}
V_231 = F_260 ( & V_396 ) ;
if ( V_231 ) {
F_155 ( L_37 , V_397 ) ;
goto V_398;
}
return 0 ;
V_398:
F_261 ( & V_289 ) ;
V_395:
return V_231 ;
}
static void F_262 ( void )
{
F_263 ( & V_396 ) ;
F_261 ( & V_289 ) ;
}
struct V_67 * F_264 ( struct V_72 * V_72 )
{
struct V_29 * V_30 ;
if ( V_72 -> V_399 != & V_400 )
return F_129 ( - V_78 ) ;
V_30 = V_72 -> V_74 ;
if ( ! V_30 )
return F_129 ( - V_215 ) ;
return & V_30 -> V_67 ;
}
