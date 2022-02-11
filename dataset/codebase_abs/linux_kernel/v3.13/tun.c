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
V_5 -> V_8 = V_8 ;
V_5 -> V_7 = V_7 ;
F_7 ( & V_5 -> V_13 , V_4 ) ;
++ V_7 -> V_14 ;
}
return V_5 ;
}
static void F_8 ( struct V_6 * V_7 , struct V_2 * V_5 )
{
F_6 ( V_10 , V_7 , L_2 ,
V_5 -> V_1 , V_5 -> V_8 ) ;
F_9 ( & V_5 -> V_13 ) ;
F_10 ( V_5 , V_15 ) ;
-- V_7 -> V_14 ;
}
static void F_11 ( struct V_6 * V_7 )
{
int V_16 ;
F_12 ( & V_7 -> V_17 ) ;
for ( V_16 = 0 ; V_16 < V_18 ; V_16 ++ ) {
struct V_2 * V_5 ;
struct V_19 * V_20 ;
F_13 (e, n, &tun->flows[i], hash_link)
F_8 ( V_7 , V_5 ) ;
}
F_14 ( & V_7 -> V_17 ) ;
}
static void F_15 ( struct V_6 * V_7 , T_2 V_8 )
{
int V_16 ;
F_12 ( & V_7 -> V_17 ) ;
for ( V_16 = 0 ; V_16 < V_18 ; V_16 ++ ) {
struct V_2 * V_5 ;
struct V_19 * V_20 ;
F_13 (e, n, &tun->flows[i], hash_link) {
if ( V_5 -> V_8 == V_8 )
F_8 ( V_7 , V_5 ) ;
}
}
F_14 ( & V_7 -> V_17 ) ;
}
static void F_16 ( unsigned long V_21 )
{
struct V_6 * V_7 = (struct V_6 * ) V_21 ;
unsigned long V_22 = V_7 -> V_23 ;
unsigned long V_24 = V_12 + V_22 ;
unsigned long V_25 = 0 ;
int V_16 ;
F_6 ( V_10 , V_7 , L_3 ) ;
F_12 ( & V_7 -> V_17 ) ;
for ( V_16 = 0 ; V_16 < V_18 ; V_16 ++ ) {
struct V_2 * V_5 ;
struct V_19 * V_20 ;
F_13 (e, n, &tun->flows[i], hash_link) {
unsigned long V_26 ;
V_25 ++ ;
V_26 = V_5 -> V_11 + V_22 ;
if ( F_17 ( V_26 , V_12 ) )
F_8 ( V_7 , V_5 ) ;
else if ( F_18 ( V_26 , V_24 ) )
V_24 = V_26 ;
}
}
if ( V_25 )
F_19 ( & V_7 -> V_27 , F_20 ( V_24 ) ) ;
F_14 ( & V_7 -> V_17 ) ;
}
static void F_21 ( struct V_6 * V_7 , T_1 V_1 ,
struct V_28 * V_29 )
{
struct V_3 * V_4 ;
struct V_2 * V_5 ;
unsigned long V_22 = V_7 -> V_23 ;
T_2 V_8 = V_29 -> V_8 ;
if ( ! V_1 )
return;
else
V_4 = & V_7 -> V_30 [ F_1 ( V_1 ) ] ;
F_22 () ;
if ( V_7 -> V_31 == 1 || V_29 -> V_32 )
goto V_33;
V_5 = F_2 ( V_4 , V_1 ) ;
if ( F_23 ( V_5 ) ) {
V_5 -> V_8 = V_8 ;
V_5 -> V_11 = V_12 ;
} else {
F_12 ( & V_7 -> V_17 ) ;
if ( ! F_2 ( V_4 , V_1 ) &&
V_7 -> V_14 < V_34 )
F_4 ( V_7 , V_4 , V_1 , V_8 ) ;
if ( ! F_24 ( & V_7 -> V_27 ) )
F_19 ( & V_7 -> V_27 ,
F_20 ( V_12 + V_22 ) ) ;
F_14 ( & V_7 -> V_17 ) ;
}
V_33:
F_25 () ;
}
static T_2 F_26 ( struct V_35 * V_36 , struct V_37 * V_38 ,
void * V_39 )
{
struct V_6 * V_7 = F_27 ( V_36 ) ;
struct V_2 * V_5 ;
T_1 V_40 = 0 ;
T_1 V_31 = 0 ;
F_22 () ;
V_31 = F_28 ( V_7 -> V_31 ) ;
V_40 = F_29 ( V_38 ) ;
if ( V_40 ) {
V_5 = F_2 ( & V_7 -> V_30 [ F_1 ( V_40 ) ] , V_40 ) ;
if ( V_5 )
V_40 = V_5 -> V_8 ;
else
V_40 = ( ( V_41 ) V_40 * V_31 ) >> 32 ;
} else if ( F_23 ( F_30 ( V_38 ) ) ) {
V_40 = F_31 ( V_38 ) ;
while ( F_32 ( V_40 >= V_31 ) )
V_40 -= V_31 ;
}
F_25 () ;
return V_40 ;
}
static inline bool F_33 ( struct V_6 * V_7 )
{
const struct V_42 * V_42 = F_34 () ;
struct V_43 * V_43 = F_35 ( V_7 -> V_36 ) ;
return ( ( F_36 ( V_7 -> V_44 ) && ! F_37 ( V_42 -> V_45 , V_7 -> V_44 ) ) ||
( F_38 ( V_7 -> V_46 ) && ! F_39 ( V_7 -> V_46 ) ) ) &&
! F_40 ( V_43 -> V_47 , V_48 ) ;
}
static void F_41 ( struct V_6 * V_7 )
{
F_42 ( V_7 -> V_36 , V_7 -> V_31 ) ;
F_43 ( V_7 -> V_36 , V_7 -> V_31 ) ;
}
static void F_44 ( struct V_6 * V_7 , struct V_28 * V_29 )
{
V_29 -> V_32 = V_7 ;
F_45 ( & V_29 -> V_49 , & V_7 -> V_50 ) ;
++ V_7 -> V_51 ;
}
static struct V_6 * F_46 ( struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_32 ;
V_29 -> V_32 = NULL ;
F_47 ( & V_29 -> V_49 ) ;
-- V_7 -> V_51 ;
return V_7 ;
}
static void F_48 ( struct V_28 * V_29 )
{
F_49 ( & V_29 -> V_52 . V_53 ) ;
F_49 ( & V_29 -> V_52 . V_54 ) ;
}
static void F_50 ( struct V_28 * V_29 , bool V_55 )
{
struct V_28 * V_56 ;
struct V_6 * V_7 ;
V_7 = F_51 ( V_29 -> V_7 ) ;
if ( V_7 && ! V_29 -> V_32 ) {
T_2 V_57 = V_29 -> V_8 ;
F_52 ( V_57 >= V_7 -> V_31 ) ;
F_53 ( V_7 -> V_58 [ V_57 ] ,
V_7 -> V_58 [ V_7 -> V_31 - 1 ] ) ;
V_56 = F_51 ( V_7 -> V_58 [ V_57 ] ) ;
V_56 -> V_8 = V_57 ;
-- V_7 -> V_31 ;
if ( V_55 ) {
F_53 ( V_29 -> V_7 , NULL ) ;
F_54 ( & V_29 -> V_52 ) ;
} else
F_44 ( V_7 , V_29 ) ;
F_55 () ;
F_15 ( V_7 , V_7 -> V_31 + 1 ) ;
F_48 ( V_29 ) ;
F_41 ( V_7 ) ;
} else if ( V_29 -> V_32 && V_55 ) {
V_7 = F_46 ( V_29 ) ;
F_54 ( & V_29 -> V_52 ) ;
}
if ( V_55 ) {
if ( V_7 && V_7 -> V_31 == 0 && V_7 -> V_51 == 0 ) {
F_56 ( V_7 -> V_36 ) ;
if ( ! ( V_7 -> V_59 & V_60 ) &&
V_7 -> V_36 -> V_61 == V_62 )
F_57 ( V_7 -> V_36 ) ;
}
F_52 ( ! F_58 ( V_63 ,
& V_29 -> V_64 . V_59 ) ) ;
F_59 ( & V_29 -> V_52 ) ;
}
}
static void F_60 ( struct V_28 * V_29 , bool V_55 )
{
F_61 () ;
F_50 ( V_29 , V_55 ) ;
F_62 () ;
}
static void F_63 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_27 ( V_36 ) ;
struct V_28 * V_29 , * V_65 ;
int V_16 , V_20 = V_7 -> V_31 ;
for ( V_16 = 0 ; V_16 < V_20 ; V_16 ++ ) {
V_29 = F_51 ( V_7 -> V_58 [ V_16 ] ) ;
F_52 ( ! V_29 ) ;
F_64 ( & V_29 -> V_66 . V_67 ) ;
F_53 ( V_29 -> V_7 , NULL ) ;
-- V_7 -> V_31 ;
}
F_65 (tfile, &tun->disabled, next) {
F_64 ( & V_29 -> V_66 . V_67 ) ;
F_53 ( V_29 -> V_7 , NULL ) ;
}
F_52 ( V_7 -> V_31 != 0 ) ;
F_55 () ;
for ( V_16 = 0 ; V_16 < V_20 ; V_16 ++ ) {
V_29 = F_51 ( V_7 -> V_58 [ V_16 ] ) ;
F_48 ( V_29 ) ;
F_54 ( & V_29 -> V_52 ) ;
}
F_66 (tfile, tmp, &tun->disabled, next) {
F_46 ( V_29 ) ;
F_48 ( V_29 ) ;
F_54 ( & V_29 -> V_52 ) ;
}
F_52 ( V_7 -> V_51 != 0 ) ;
if ( V_7 -> V_59 & V_60 )
F_67 ( V_68 ) ;
}
static int F_68 ( struct V_6 * V_7 , struct V_69 * V_69 , bool V_70 )
{
struct V_28 * V_29 = V_69 -> V_71 ;
int V_72 ;
V_72 = F_69 ( V_29 -> V_64 . V_52 , V_7 -> V_73 ) ;
if ( V_72 < 0 )
goto V_74;
V_72 = - V_75 ;
if ( F_51 ( V_29 -> V_7 ) && ! V_29 -> V_32 )
goto V_74;
V_72 = - V_76 ;
if ( ! ( V_7 -> V_59 & V_77 ) && V_7 -> V_31 == 1 )
goto V_74;
V_72 = - V_78 ;
if ( ! V_29 -> V_32 &&
V_7 -> V_31 + V_7 -> V_51 == V_79 )
goto V_74;
V_72 = 0 ;
if ( ! V_70 && ( V_7 -> V_80 == true ) ) {
V_72 = F_70 ( & V_7 -> V_81 , V_29 -> V_64 . V_52 ) ;
if ( ! V_72 )
goto V_74;
}
V_29 -> V_8 = V_7 -> V_31 ;
F_53 ( V_29 -> V_7 , V_7 ) ;
F_53 ( V_7 -> V_58 [ V_7 -> V_31 ] , V_29 ) ;
V_7 -> V_31 ++ ;
if ( V_29 -> V_32 )
F_46 ( V_29 ) ;
else
F_71 ( & V_29 -> V_52 ) ;
F_41 ( V_7 ) ;
V_74:
return V_72 ;
}
static struct V_6 * F_72 ( struct V_28 * V_29 )
{
struct V_6 * V_7 ;
F_22 () ;
V_7 = F_73 ( V_29 -> V_7 ) ;
if ( V_7 )
F_74 ( V_7 -> V_36 ) ;
F_25 () ;
return V_7 ;
}
static struct V_6 * F_75 ( struct V_69 * V_69 )
{
return F_72 ( V_69 -> V_71 ) ;
}
static void F_76 ( struct V_6 * V_7 )
{
F_77 ( V_7 -> V_36 ) ;
}
static void F_78 ( T_1 * V_82 , const T_3 * V_83 )
{
int V_20 = F_79 ( V_84 , V_83 ) >> 26 ;
V_82 [ V_20 >> 5 ] |= ( 1 << ( V_20 & 31 ) ) ;
}
static unsigned int F_80 ( const T_1 * V_82 , const T_3 * V_83 )
{
int V_20 = F_79 ( V_84 , V_83 ) >> 26 ;
return V_82 [ V_20 >> 5 ] & ( 1 << ( V_20 & 31 ) ) ;
}
static int F_81 ( struct V_85 * V_86 , void T_4 * V_87 )
{
struct { T_3 V_88 [ V_84 ] ; } * V_83 ;
struct V_89 V_90 ;
int V_72 , V_91 , V_20 , V_92 ;
if ( F_82 ( & V_90 , V_87 , sizeof( V_90 ) ) )
return - V_93 ;
if ( ! V_90 . V_25 ) {
V_86 -> V_25 = 0 ;
return 0 ;
}
V_91 = V_84 * V_90 . V_25 ;
V_83 = F_5 ( V_91 , V_94 ) ;
if ( ! V_83 )
return - V_95 ;
if ( F_82 ( V_83 , V_87 + sizeof( V_90 ) , V_91 ) ) {
V_72 = - V_93 ;
goto V_96;
}
V_86 -> V_25 = 0 ;
F_83 () ;
for ( V_20 = 0 ; V_20 < V_90 . V_25 && V_20 < V_97 ; V_20 ++ )
memcpy ( V_86 -> V_83 [ V_20 ] , V_83 [ V_20 ] . V_88 , V_84 ) ;
V_92 = V_20 ;
memset ( V_86 -> V_82 , 0 , sizeof( V_86 -> V_82 ) ) ;
for (; V_20 < V_90 . V_25 ; V_20 ++ ) {
if ( ! F_84 ( V_83 [ V_20 ] . V_88 ) ) {
V_72 = 0 ;
goto V_96;
}
F_78 ( V_86 -> V_82 , V_83 [ V_20 ] . V_88 ) ;
}
if ( ( V_90 . V_59 & V_98 ) )
memset ( V_86 -> V_82 , ~ 0 , sizeof( V_86 -> V_82 ) ) ;
F_83 () ;
V_86 -> V_25 = V_92 ;
V_72 = V_92 ;
V_96:
F_85 ( V_83 ) ;
return V_72 ;
}
static int F_86 ( struct V_85 * V_86 , const struct V_37 * V_38 )
{
struct V_99 * V_100 = (struct V_99 * ) V_38 -> V_21 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_86 -> V_25 ; V_16 ++ )
if ( F_87 ( V_100 -> V_101 , V_86 -> V_83 [ V_16 ] ) )
return 1 ;
if ( F_84 ( V_100 -> V_101 ) )
return F_80 ( V_86 -> V_82 , V_100 -> V_101 ) ;
return 0 ;
}
static int F_88 ( struct V_85 * V_86 , const struct V_37 * V_38 )
{
if ( ! V_86 -> V_25 )
return 1 ;
return F_86 ( V_86 , V_38 ) ;
}
static void F_89 ( struct V_35 * V_36 )
{
F_63 ( V_36 ) ;
}
static int F_90 ( struct V_35 * V_36 )
{
F_91 ( V_36 ) ;
return 0 ;
}
static int F_92 ( struct V_35 * V_36 )
{
F_93 ( V_36 ) ;
return 0 ;
}
static T_5 F_94 ( struct V_37 * V_38 , struct V_35 * V_36 )
{
struct V_6 * V_7 = F_27 ( V_36 ) ;
int V_40 = V_38 -> V_102 ;
struct V_28 * V_29 ;
F_22 () ;
V_29 = F_73 ( V_7 -> V_58 [ V_40 ] ) ;
if ( V_40 >= V_7 -> V_31 )
goto V_103;
F_6 ( V_10 , V_7 , L_4 , V_38 -> V_104 ) ;
F_52 ( ! V_29 ) ;
if ( ! F_88 ( & V_7 -> V_105 , V_38 ) )
goto V_103;
if ( V_29 -> V_64 . V_52 -> V_106 &&
V_106 ( V_29 -> V_64 . V_52 , V_38 ) )
goto V_103;
if ( F_95 ( & V_29 -> V_64 . V_52 -> V_53 )
>= V_36 -> V_107 / V_7 -> V_31 )
goto V_103;
if ( F_32 ( F_96 ( V_38 , V_9 ) ) )
goto V_103;
if ( V_38 -> V_52 ) {
F_97 ( V_38 -> V_52 , & F_98 ( V_38 ) -> V_108 ) ;
F_99 ( V_38 ) ;
}
F_100 ( V_38 ) ;
F_101 ( V_38 ) ;
F_102 ( & V_29 -> V_64 . V_52 -> V_53 , V_38 ) ;
if ( V_29 -> V_59 & V_109 )
F_103 ( & V_29 -> V_110 , V_111 , V_112 ) ;
F_104 ( & V_29 -> V_66 . V_67 , V_113 |
V_114 | V_115 ) ;
F_25 () ;
return V_116 ;
V_103:
V_36 -> V_117 . V_118 ++ ;
F_105 ( V_38 ) ;
F_106 ( V_38 ) ;
F_25 () ;
return V_116 ;
}
static void F_107 ( struct V_35 * V_36 )
{
}
static int
F_108 ( struct V_35 * V_36 , int V_119 )
{
if ( V_119 < V_120 || V_119 + V_36 -> V_121 > V_122 )
return - V_75 ;
V_36 -> V_123 = V_119 ;
return 0 ;
}
static T_6 F_109 ( struct V_35 * V_36 ,
T_6 V_124 )
{
struct V_6 * V_7 = F_27 ( V_36 ) ;
return ( V_124 & V_7 -> V_125 ) | ( V_124 & ~ V_126 ) ;
}
static void F_110 ( struct V_35 * V_36 )
{
return;
}
static void F_111 ( struct V_6 * V_7 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_18 ; V_16 ++ )
F_112 ( & V_7 -> V_30 [ V_16 ] ) ;
V_7 -> V_23 = V_127 ;
F_113 ( & V_7 -> V_27 , F_16 , ( unsigned long ) V_7 ) ;
F_19 ( & V_7 -> V_27 ,
F_20 ( V_12 + V_7 -> V_23 ) ) ;
}
static void F_114 ( struct V_6 * V_7 )
{
F_115 ( & V_7 -> V_27 ) ;
F_11 ( V_7 ) ;
}
static void F_116 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_27 ( V_36 ) ;
switch ( V_7 -> V_59 & V_128 ) {
case V_129 :
V_36 -> V_130 = & V_131 ;
V_36 -> V_121 = 0 ;
V_36 -> V_132 = 0 ;
V_36 -> V_123 = 1500 ;
V_36 -> type = V_133 ;
V_36 -> V_59 = V_134 | V_135 | V_136 ;
V_36 -> V_107 = V_137 ;
break;
case V_138 :
V_36 -> V_130 = & V_139 ;
F_117 ( V_36 ) ;
V_36 -> V_140 &= ~ V_141 ;
V_36 -> V_140 |= V_142 ;
F_118 ( V_36 ) ;
V_36 -> V_107 = V_137 ;
break;
}
}
static unsigned int F_119 ( struct V_69 * V_69 , T_7 * V_67 )
{
struct V_28 * V_29 = V_69 -> V_71 ;
struct V_6 * V_7 = F_72 ( V_29 ) ;
struct V_143 * V_52 ;
unsigned int V_82 = 0 ;
if ( ! V_7 )
return V_144 ;
V_52 = V_29 -> V_64 . V_52 ;
F_6 ( V_10 , V_7 , L_5 ) ;
F_120 ( V_69 , & V_29 -> V_66 . V_67 , V_67 ) ;
if ( ! F_121 ( & V_52 -> V_53 ) )
V_82 |= V_113 | V_114 ;
if ( F_122 ( V_52 ) ||
( ! F_123 ( V_145 , & V_52 -> V_146 -> V_59 ) &&
F_122 ( V_52 ) ) )
V_82 |= V_147 | V_148 ;
if ( V_7 -> V_36 -> V_61 != V_62 )
V_82 = V_144 ;
F_76 ( V_7 ) ;
return V_82 ;
}
static struct V_37 * F_124 ( struct V_28 * V_29 ,
T_8 V_149 , T_8 V_104 ,
T_8 V_150 , int V_151 )
{
struct V_143 * V_52 = V_29 -> V_64 . V_52 ;
struct V_37 * V_38 ;
int V_72 ;
if ( V_149 + V_104 < V_152 || ! V_150 )
V_150 = V_104 ;
V_38 = F_125 ( V_52 , V_149 + V_150 , V_104 - V_150 , V_151 ,
& V_72 , 0 ) ;
if ( ! V_38 )
return F_126 ( V_72 ) ;
F_127 ( V_38 , V_149 ) ;
F_128 ( V_38 , V_150 ) ;
V_38 -> V_153 = V_104 - V_150 ;
V_38 -> V_104 += V_104 - V_150 ;
return V_38 ;
}
static T_9 F_129 ( struct V_6 * V_7 , struct V_28 * V_29 ,
void * V_154 , const struct V_155 * V_156 ,
T_8 V_157 , T_8 V_25 , int V_151 )
{
struct V_158 V_159 = { 0 , F_130 (ETH_P_IP) } ;
struct V_37 * V_38 ;
T_8 V_104 = V_157 , V_160 = V_161 , V_150 ;
struct V_162 V_163 = { 0 } ;
int V_164 ;
int V_165 = 0 ;
int V_166 ;
bool V_167 = false ;
int V_72 ;
T_1 V_1 ;
if ( ! ( V_7 -> V_59 & V_168 ) ) {
if ( V_104 < sizeof( V_159 ) )
return - V_75 ;
V_104 -= sizeof( V_159 ) ;
if ( F_131 ( ( void * ) & V_159 , V_156 , 0 , sizeof( V_159 ) ) )
return - V_93 ;
V_165 += sizeof( V_159 ) ;
}
if ( V_7 -> V_59 & V_169 ) {
if ( V_104 < V_7 -> V_170 )
return - V_75 ;
V_104 -= V_7 -> V_170 ;
if ( F_131 ( ( void * ) & V_163 , V_156 , V_165 , sizeof( V_163 ) ) )
return - V_93 ;
if ( ( V_163 . V_59 & V_171 ) &&
V_163 . V_172 + V_163 . V_173 + 2 > V_163 . V_174 )
V_163 . V_174 = V_163 . V_172 + V_163 . V_173 + 2 ;
if ( V_163 . V_174 > V_104 )
return - V_75 ;
V_165 += V_7 -> V_170 ;
}
if ( ( V_7 -> V_59 & V_128 ) == V_138 ) {
V_160 += V_175 ;
if ( F_32 ( V_104 < V_176 ||
( V_163 . V_174 && V_163 . V_174 < V_176 ) ) )
return - V_75 ;
}
V_164 = F_132 ( V_160 ) ;
if ( V_154 ) {
V_166 = V_163 . V_174 ? V_163 . V_174 : V_177 ;
if ( V_166 > V_164 )
V_166 = V_164 ;
V_150 = V_166 ;
if ( F_133 ( V_156 , V_165 + V_166 , V_25 ) <= V_178 )
V_167 = true ;
}
if ( ! V_167 ) {
V_166 = V_104 ;
if ( V_163 . V_174 > V_164 )
V_150 = V_164 ;
else
V_150 = V_163 . V_174 ;
}
V_38 = F_124 ( V_29 , V_160 , V_166 , V_150 , V_151 ) ;
if ( F_134 ( V_38 ) ) {
if ( F_135 ( V_38 ) != - V_179 )
V_7 -> V_36 -> V_117 . V_180 ++ ;
return F_135 ( V_38 ) ;
}
if ( V_167 )
V_72 = F_136 ( V_38 , V_156 , V_165 , V_25 ) ;
else {
V_72 = F_137 ( V_38 , 0 , V_156 , V_165 , V_104 ) ;
if ( ! V_72 && V_154 ) {
struct V_181 * V_182 = V_154 ;
V_182 -> V_183 ( V_182 , false ) ;
}
}
if ( V_72 ) {
V_7 -> V_36 -> V_117 . V_180 ++ ;
F_106 ( V_38 ) ;
return - V_93 ;
}
if ( V_163 . V_59 & V_171 ) {
if ( ! F_138 ( V_38 , V_163 . V_172 ,
V_163 . V_173 ) ) {
V_7 -> V_36 -> V_117 . V_184 ++ ;
F_106 ( V_38 ) ;
return - V_75 ;
}
}
switch ( V_7 -> V_59 & V_128 ) {
case V_129 :
if ( V_7 -> V_59 & V_168 ) {
switch ( V_38 -> V_21 [ 0 ] & 0xf0 ) {
case 0x40 :
V_159 . V_185 = F_139 ( V_186 ) ;
break;
case 0x60 :
V_159 . V_185 = F_139 ( V_187 ) ;
break;
default:
V_7 -> V_36 -> V_117 . V_180 ++ ;
F_106 ( V_38 ) ;
return - V_75 ;
}
}
F_140 ( V_38 ) ;
V_38 -> V_188 = V_159 . V_185 ;
V_38 -> V_36 = V_7 -> V_36 ;
break;
case V_138 :
V_38 -> V_188 = F_141 ( V_38 , V_7 -> V_36 ) ;
break;
}
if ( V_163 . V_189 != V_190 ) {
F_142 ( L_6 ) ;
switch ( V_163 . V_189 & ~ V_191 ) {
case V_192 :
F_98 ( V_38 ) -> V_189 = V_193 ;
break;
case V_194 :
F_98 ( V_38 ) -> V_189 = V_195 ;
break;
case V_196 :
F_98 ( V_38 ) -> V_189 = V_197 ;
break;
default:
V_7 -> V_36 -> V_117 . V_184 ++ ;
F_106 ( V_38 ) ;
return - V_75 ;
}
if ( V_163 . V_189 & V_191 )
F_98 ( V_38 ) -> V_189 |= V_198 ;
F_98 ( V_38 ) -> V_199 = V_163 . V_199 ;
if ( F_98 ( V_38 ) -> V_199 == 0 ) {
V_7 -> V_36 -> V_117 . V_184 ++ ;
F_106 ( V_38 ) ;
return - V_75 ;
}
F_98 ( V_38 ) -> V_189 |= V_200 ;
F_98 ( V_38 ) -> V_201 = 0 ;
}
if ( V_167 ) {
F_98 ( V_38 ) -> V_202 = V_154 ;
F_98 ( V_38 ) -> V_108 |= V_203 ;
F_98 ( V_38 ) -> V_108 |= V_204 ;
}
F_143 ( V_38 ) ;
F_144 ( V_38 , 0 ) ;
V_1 = F_29 ( V_38 ) ;
F_145 ( V_38 ) ;
V_7 -> V_36 -> V_117 . V_205 ++ ;
V_7 -> V_36 -> V_117 . V_206 += V_104 ;
F_21 ( V_7 , V_1 , V_29 ) ;
return V_157 ;
}
static T_9 F_146 ( struct V_207 * V_208 , const struct V_155 * V_156 ,
unsigned long V_25 , T_10 V_209 )
{
struct V_69 * V_69 = V_208 -> V_210 ;
struct V_6 * V_7 = F_75 ( V_69 ) ;
struct V_28 * V_29 = V_69 -> V_71 ;
T_9 V_211 ;
if ( ! V_7 )
return - V_212 ;
F_6 ( V_10 , V_7 , L_7 , V_25 ) ;
V_211 = F_129 ( V_7 , V_29 , NULL , V_156 , F_147 ( V_156 , V_25 ) ,
V_25 , V_69 -> V_213 & V_214 ) ;
F_76 ( V_7 ) ;
return V_211 ;
}
static T_9 F_148 ( struct V_6 * V_7 ,
struct V_28 * V_29 ,
struct V_37 * V_38 ,
const struct V_155 * V_156 , int V_104 )
{
struct V_158 V_159 = { 0 , V_38 -> V_188 } ;
T_9 V_215 = 0 ;
int V_216 = 0 , V_217 ;
if ( ! ( V_7 -> V_59 & V_168 ) ) {
if ( ( V_104 -= sizeof( V_159 ) ) < 0 )
return - V_75 ;
if ( V_104 < V_38 -> V_104 ) {
V_159 . V_59 |= V_218 ;
}
if ( F_149 ( V_156 , ( void * ) & V_159 , 0 , sizeof( V_159 ) ) )
return - V_93 ;
V_215 += sizeof( V_159 ) ;
}
if ( V_7 -> V_59 & V_169 ) {
struct V_162 V_163 = { 0 } ;
if ( ( V_104 -= V_7 -> V_170 ) < 0 )
return - V_75 ;
if ( F_150 ( V_38 ) ) {
struct V_219 * V_220 = F_98 ( V_38 ) ;
V_163 . V_174 = F_151 ( V_38 ) ;
V_163 . V_199 = V_220 -> V_199 ;
if ( V_220 -> V_189 & V_193 )
V_163 . V_189 = V_192 ;
else if ( V_220 -> V_189 & V_195 )
V_163 . V_189 = V_194 ;
else if ( V_220 -> V_189 & V_197 )
V_163 . V_189 = V_196 ;
else {
F_152 ( L_8
L_9 ,
V_220 -> V_189 , V_163 . V_199 ,
V_163 . V_174 ) ;
F_153 ( V_221 , L_10 ,
V_222 ,
16 , 1 , V_38 -> V_4 ,
F_154 ( ( int ) V_163 . V_174 , 64 ) , true ) ;
F_155 ( 1 ) ;
return - V_75 ;
}
if ( V_220 -> V_189 & V_198 )
V_163 . V_189 |= V_191 ;
} else
V_163 . V_189 = V_190 ;
if ( V_38 -> V_223 == V_224 ) {
V_163 . V_59 = V_171 ;
V_163 . V_172 = F_156 ( V_38 ) ;
V_163 . V_173 = V_38 -> V_173 ;
} else if ( V_38 -> V_223 == V_225 ) {
V_163 . V_59 = V_226 ;
}
if ( F_32 ( F_149 ( V_156 , ( void * ) & V_163 , V_215 ,
sizeof( V_163 ) ) ) )
return - V_93 ;
V_215 += V_7 -> V_170 ;
}
V_217 = V_215 ;
V_215 += V_38 -> V_104 ;
if ( ! F_157 ( V_38 ) ) {
V_104 = F_158 ( int , V_38 -> V_104 , V_104 ) ;
} else {
int V_227 , V_228 ;
struct {
T_11 V_229 ;
T_11 V_230 ;
} V_231 ;
V_231 . V_229 = V_38 -> V_232 ;
V_231 . V_230 = F_139 ( F_159 ( V_38 ) ) ;
V_216 = F_160 ( struct V_233 , V_229 ) ;
V_104 = F_158 ( int , V_38 -> V_104 + V_234 , V_104 ) ;
V_215 += V_234 ;
V_227 = F_158 ( int , V_216 , V_104 ) ;
V_228 = F_161 ( V_38 , 0 , V_156 , V_217 , V_227 ) ;
V_104 -= V_227 ;
V_217 += V_227 ;
if ( V_228 || ! V_104 )
goto V_96;
V_227 = F_158 ( int , sizeof( V_231 ) , V_104 ) ;
V_228 = F_149 ( V_156 , ( void * ) & V_231 , V_217 , V_227 ) ;
V_104 -= V_227 ;
V_217 += V_227 ;
if ( V_228 || ! V_104 )
goto V_96;
}
F_161 ( V_38 , V_216 , V_156 , V_217 , V_104 ) ;
V_96:
V_7 -> V_36 -> V_117 . V_235 ++ ;
V_7 -> V_36 -> V_117 . V_236 += V_104 ;
return V_215 ;
}
static T_9 F_162 ( struct V_6 * V_7 , struct V_28 * V_29 ,
struct V_207 * V_208 , const struct V_155 * V_156 ,
T_9 V_104 , int V_151 )
{
F_163 ( V_67 , V_237 ) ;
struct V_37 * V_38 ;
T_9 V_228 = 0 ;
F_6 ( V_10 , V_7 , L_11 ) ;
if ( F_32 ( ! V_151 ) )
F_164 ( & V_29 -> V_66 . V_67 , & V_67 ) ;
while ( V_104 ) {
if ( F_32 ( ! V_151 ) )
V_237 -> V_238 = V_239 ;
if ( ! ( V_38 = F_165 ( & V_29 -> V_64 . V_52 -> V_53 ) ) ) {
if ( V_151 ) {
V_228 = - V_179 ;
break;
}
if ( F_166 ( V_237 ) ) {
V_228 = - V_240 ;
break;
}
if ( V_7 -> V_36 -> V_61 != V_62 ) {
V_228 = - V_241 ;
break;
}
F_167 () ;
continue;
}
V_228 = F_148 ( V_7 , V_29 , V_38 , V_156 , V_104 ) ;
F_106 ( V_38 ) ;
break;
}
if ( F_32 ( ! V_151 ) ) {
V_237 -> V_238 = V_242 ;
F_168 ( & V_29 -> V_66 . V_67 , & V_67 ) ;
}
return V_228 ;
}
static T_9 F_169 ( struct V_207 * V_208 , const struct V_155 * V_156 ,
unsigned long V_25 , T_10 V_209 )
{
struct V_69 * V_69 = V_208 -> V_210 ;
struct V_28 * V_29 = V_69 -> V_71 ;
struct V_6 * V_7 = F_72 ( V_29 ) ;
T_9 V_104 , V_228 ;
if ( ! V_7 )
return - V_212 ;
V_104 = F_147 ( V_156 , V_25 ) ;
if ( V_104 < 0 ) {
V_228 = - V_75 ;
goto V_74;
}
V_228 = F_162 ( V_7 , V_29 , V_208 , V_156 , V_104 ,
V_69 -> V_213 & V_214 ) ;
V_228 = F_158 ( T_9 , V_228 , V_104 ) ;
if ( V_228 > 0 )
V_208 -> V_243 = V_228 ;
V_74:
F_76 ( V_7 ) ;
return V_228 ;
}
static void F_170 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_27 ( V_36 ) ;
F_52 ( ! ( F_171 ( & V_7 -> V_50 ) ) ) ;
F_114 ( V_7 ) ;
F_172 ( V_7 -> V_73 ) ;
F_173 ( V_36 ) ;
}
static void F_174 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_27 ( V_36 ) ;
V_7 -> V_44 = V_244 ;
V_7 -> V_46 = V_245 ;
V_36 -> V_246 = & V_247 ;
V_36 -> V_248 = F_170 ;
}
static int F_175 ( struct V_249 * V_250 [] , struct V_249 * V_21 [] )
{
return - V_75 ;
}
static void F_176 ( struct V_143 * V_52 )
{
struct V_28 * V_29 ;
T_12 * V_251 ;
if ( ! F_122 ( V_52 ) )
return;
if ( ! F_177 ( V_145 , & V_52 -> V_146 -> V_59 ) )
return;
V_251 = F_178 ( V_52 ) ;
if ( V_251 && F_179 ( V_251 ) )
F_180 ( V_251 , V_147 |
V_148 | V_252 ) ;
V_29 = F_181 ( V_52 , struct V_28 , V_52 ) ;
F_103 ( & V_29 -> V_110 , V_111 , V_253 ) ;
}
static int F_182 ( struct V_207 * V_208 , struct V_64 * V_143 ,
struct V_254 * V_255 , T_8 V_157 )
{
int V_228 ;
struct V_28 * V_29 = F_181 ( V_143 , struct V_28 , V_64 ) ;
struct V_6 * V_7 = F_72 ( V_29 ) ;
if ( ! V_7 )
return - V_212 ;
V_228 = F_129 ( V_7 , V_29 , V_255 -> V_154 , V_255 -> V_256 , V_157 ,
V_255 -> V_257 , V_255 -> V_258 & V_259 ) ;
F_76 ( V_7 ) ;
return V_228 ;
}
static int F_183 ( struct V_207 * V_208 , struct V_64 * V_143 ,
struct V_254 * V_255 , T_8 V_157 ,
int V_59 )
{
struct V_28 * V_29 = F_181 ( V_143 , struct V_28 , V_64 ) ;
struct V_6 * V_7 = F_72 ( V_29 ) ;
int V_228 ;
if ( ! V_7 )
return - V_212 ;
if ( V_59 & ~ ( V_259 | V_260 | V_261 ) ) {
V_228 = - V_75 ;
goto V_74;
}
if ( V_59 & V_261 ) {
V_228 = F_184 ( V_143 -> V_52 , V_255 , V_157 ,
V_262 , V_263 ) ;
goto V_74;
}
V_228 = F_162 ( V_7 , V_29 , V_208 , V_255 -> V_256 , V_157 ,
V_59 & V_259 ) ;
if ( V_228 > V_157 ) {
V_255 -> V_258 |= V_260 ;
V_228 = V_59 & V_260 ? V_228 : V_157 ;
}
V_74:
F_76 ( V_7 ) ;
return V_228 ;
}
static int F_185 ( struct V_64 * V_143 )
{
if ( V_143 -> V_52 )
F_54 ( V_143 -> V_52 ) ;
return 0 ;
}
static int F_186 ( struct V_6 * V_7 )
{
int V_59 = 0 ;
if ( V_7 -> V_59 & V_129 )
V_59 |= V_264 ;
else
V_59 |= V_265 ;
if ( V_7 -> V_59 & V_168 )
V_59 |= V_266 ;
if ( V_7 -> V_59 & V_267 )
V_59 |= V_268 ;
if ( V_7 -> V_59 & V_169 )
V_59 |= V_269 ;
if ( V_7 -> V_59 & V_77 )
V_59 |= V_270 ;
if ( V_7 -> V_59 & V_60 )
V_59 |= V_271 ;
return V_59 ;
}
static T_9 F_187 ( struct V_272 * V_36 , struct V_273 * V_274 ,
char * V_275 )
{
struct V_6 * V_7 = F_27 ( F_188 ( V_36 ) ) ;
return sprintf ( V_275 , L_12 , F_186 ( V_7 ) ) ;
}
static T_9 F_189 ( struct V_272 * V_36 , struct V_273 * V_274 ,
char * V_275 )
{
struct V_6 * V_7 = F_27 ( F_188 ( V_36 ) ) ;
return F_36 ( V_7 -> V_44 ) ?
sprintf ( V_275 , L_13 ,
F_190 ( F_191 () , V_7 -> V_44 ) ) :
sprintf ( V_275 , L_14 ) ;
}
static T_9 F_192 ( struct V_272 * V_36 , struct V_273 * V_274 ,
char * V_275 )
{
struct V_6 * V_7 = F_27 ( F_188 ( V_36 ) ) ;
return F_38 ( V_7 -> V_46 ) ?
sprintf ( V_275 , L_13 ,
F_193 ( F_191 () , V_7 -> V_46 ) ) :
sprintf ( V_275 , L_14 ) ;
}
static int F_194 ( struct V_43 * V_43 , struct V_69 * V_69 , struct V_276 * V_277 )
{
struct V_6 * V_7 ;
struct V_28 * V_29 = V_69 -> V_71 ;
struct V_35 * V_36 ;
int V_72 ;
if ( V_29 -> V_32 )
return - V_75 ;
V_36 = F_195 ( V_43 , V_277 -> V_278 ) ;
if ( V_36 ) {
if ( V_277 -> V_279 & V_280 )
return - V_76 ;
if ( ( V_277 -> V_279 & V_264 ) && V_36 -> V_130 == & V_131 )
V_7 = F_27 ( V_36 ) ;
else if ( ( V_277 -> V_279 & V_265 ) && V_36 -> V_130 == & V_139 )
V_7 = F_27 ( V_36 ) ;
else
return - V_75 ;
if ( ! ! ( V_277 -> V_279 & V_270 ) !=
! ! ( V_7 -> V_59 & V_77 ) )
return - V_75 ;
if ( F_33 ( V_7 ) )
return - V_281 ;
V_72 = F_196 ( V_7 -> V_73 ) ;
if ( V_72 < 0 )
return V_72 ;
V_72 = F_68 ( V_7 , V_69 , V_277 -> V_279 & V_282 ) ;
if ( V_72 < 0 )
return V_72 ;
if ( V_7 -> V_59 & V_77 &&
( V_7 -> V_31 + V_7 -> V_51 > 1 ) ) {
return 0 ;
}
}
else {
char * V_283 ;
unsigned long V_59 = 0 ;
int V_284 = V_277 -> V_279 & V_270 ?
V_79 : 1 ;
if ( ! F_40 ( V_43 -> V_47 , V_48 ) )
return - V_281 ;
V_72 = F_197 () ;
if ( V_72 < 0 )
return V_72 ;
if ( V_277 -> V_279 & V_264 ) {
V_59 |= V_129 ;
V_283 = L_15 ;
} else if ( V_277 -> V_279 & V_265 ) {
V_59 |= V_138 ;
V_283 = L_16 ;
} else
return - V_75 ;
if ( * V_277 -> V_278 )
V_283 = V_277 -> V_278 ;
V_36 = F_198 ( sizeof( struct V_6 ) , V_283 ,
F_174 , V_284 , V_284 ) ;
if ( ! V_36 )
return - V_95 ;
F_199 ( V_36 , V_43 ) ;
V_36 -> V_285 = & V_286 ;
V_36 -> V_287 = V_29 -> V_287 ;
V_7 = F_27 ( V_36 ) ;
V_7 -> V_36 = V_36 ;
V_7 -> V_59 = V_59 ;
V_7 -> V_105 . V_25 = 0 ;
V_7 -> V_170 = sizeof( struct V_162 ) ;
V_7 -> V_80 = false ;
V_7 -> V_288 = V_29 -> V_64 . V_52 -> V_289 ;
F_200 ( & V_7 -> V_17 ) ;
V_72 = F_201 ( & V_7 -> V_73 ) ;
if ( V_72 < 0 )
goto V_290;
F_116 ( V_36 ) ;
F_111 ( V_7 ) ;
V_36 -> V_291 = V_292 | V_293 |
V_126 | V_294 |
V_295 ;
V_36 -> V_124 = V_36 -> V_291 ;
V_36 -> V_296 = V_36 -> V_124 ;
F_202 ( & V_7 -> V_50 ) ;
V_72 = F_68 ( V_7 , V_69 , false ) ;
if ( V_72 < 0 )
goto V_297;
V_72 = F_203 ( V_7 -> V_36 ) ;
if ( V_72 < 0 )
goto V_298;
if ( F_204 ( & V_7 -> V_36 -> V_36 , & V_299 ) ||
F_204 ( & V_7 -> V_36 -> V_36 , & V_300 ) ||
F_204 ( & V_7 -> V_36 -> V_36 , & V_301 ) )
F_152 ( L_17 ) ;
}
F_205 ( V_7 -> V_36 ) ;
F_6 ( V_10 , V_7 , L_18 ) ;
if ( V_277 -> V_279 & V_266 )
V_7 -> V_59 |= V_168 ;
else
V_7 -> V_59 &= ~ V_168 ;
if ( V_277 -> V_279 & V_268 )
V_7 -> V_59 |= V_267 ;
else
V_7 -> V_59 &= ~ V_267 ;
if ( V_277 -> V_279 & V_269 )
V_7 -> V_59 |= V_169 ;
else
V_7 -> V_59 &= ~ V_169 ;
if ( V_277 -> V_279 & V_270 )
V_7 -> V_59 |= V_77 ;
else
V_7 -> V_59 &= ~ V_77 ;
if ( F_206 ( V_7 -> V_36 ) )
F_207 ( V_7 -> V_36 ) ;
strcpy ( V_277 -> V_278 , V_7 -> V_36 -> V_283 ) ;
return 0 ;
V_298:
F_63 ( V_36 ) ;
V_297:
F_114 ( V_7 ) ;
F_172 ( V_7 -> V_73 ) ;
V_290:
F_173 ( V_36 ) ;
return V_72 ;
}
static void F_208 ( struct V_43 * V_43 , struct V_6 * V_7 ,
struct V_276 * V_277 )
{
F_6 ( V_10 , V_7 , L_19 ) ;
strcpy ( V_277 -> V_278 , V_7 -> V_36 -> V_283 ) ;
V_277 -> V_279 = F_186 ( V_7 ) ;
}
static int F_209 ( struct V_6 * V_7 , unsigned long V_87 )
{
T_6 V_124 = 0 ;
if ( V_87 & V_302 ) {
V_124 |= V_303 ;
V_87 &= ~ V_302 ;
if ( V_87 & ( V_304 | V_305 ) ) {
if ( V_87 & V_306 ) {
V_124 |= V_307 ;
V_87 &= ~ V_306 ;
}
if ( V_87 & V_304 )
V_124 |= V_308 ;
if ( V_87 & V_305 )
V_124 |= V_309 ;
V_87 &= ~ ( V_304 | V_305 ) ;
}
if ( V_87 & V_310 ) {
V_124 |= V_311 ;
V_87 &= ~ V_310 ;
}
}
if ( V_87 )
return - V_75 ;
V_7 -> V_125 = V_124 ;
F_210 ( V_7 -> V_36 ) ;
return 0 ;
}
static void F_211 ( struct V_6 * V_7 , int V_20 )
{
int V_16 ;
struct V_28 * V_29 ;
for ( V_16 = 0 ; V_16 < V_20 ; V_16 ++ ) {
V_29 = F_51 ( V_7 -> V_58 [ V_16 ] ) ;
F_212 ( V_29 -> V_64 . V_52 ) ;
}
V_7 -> V_80 = false ;
}
static int F_213 ( struct V_6 * V_7 )
{
int V_16 , V_228 = 0 ;
struct V_28 * V_29 ;
for ( V_16 = 0 ; V_16 < V_7 -> V_31 ; V_16 ++ ) {
V_29 = F_51 ( V_7 -> V_58 [ V_16 ] ) ;
V_228 = F_70 ( & V_7 -> V_81 , V_29 -> V_64 . V_52 ) ;
if ( V_228 ) {
F_211 ( V_7 , V_16 ) ;
return V_228 ;
}
}
V_7 -> V_80 = true ;
return V_228 ;
}
static void F_214 ( struct V_6 * V_7 )
{
struct V_28 * V_29 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_7 -> V_31 ; V_16 ++ ) {
V_29 = F_51 ( V_7 -> V_58 [ V_16 ] ) ;
V_29 -> V_64 . V_52 -> V_289 = V_7 -> V_288 ;
}
}
static int F_215 ( struct V_69 * V_69 , struct V_276 * V_277 )
{
struct V_28 * V_29 = V_69 -> V_71 ;
struct V_6 * V_7 ;
int V_228 = 0 ;
F_61 () ;
if ( V_277 -> V_279 & V_312 ) {
V_7 = V_29 -> V_32 ;
if ( ! V_7 ) {
V_228 = - V_75 ;
goto V_33;
}
V_228 = F_216 ( V_7 -> V_73 ) ;
if ( V_228 < 0 )
goto V_33;
V_228 = F_68 ( V_7 , V_69 , false ) ;
} else if ( V_277 -> V_279 & V_313 ) {
V_7 = F_51 ( V_29 -> V_7 ) ;
if ( ! V_7 || ! ( V_7 -> V_59 & V_77 ) || V_29 -> V_32 )
V_228 = - V_75 ;
else
F_50 ( V_29 , false ) ;
} else
V_228 = - V_75 ;
V_33:
F_62 () ;
return V_228 ;
}
static long F_217 ( struct V_69 * V_69 , unsigned int V_314 ,
unsigned long V_87 , int V_315 )
{
struct V_28 * V_29 = V_69 -> V_71 ;
struct V_6 * V_7 ;
void T_4 * V_316 = ( void T_4 * ) V_87 ;
struct V_276 V_277 ;
T_13 V_44 ;
T_14 V_46 ;
int V_288 ;
int V_170 ;
unsigned int V_287 ;
int V_228 ;
if ( V_314 == V_317 || V_314 == V_318 || F_218 ( V_314 ) == 0x89 ) {
if ( F_82 ( & V_277 , V_316 , V_315 ) )
return - V_93 ;
} else {
memset ( & V_277 , 0 , sizeof( V_277 ) ) ;
}
if ( V_314 == V_319 ) {
return F_219 ( V_264 | V_265 | V_266 | V_268 |
V_269 | V_270 ,
( unsigned int T_4 * ) V_316 ) ;
} else if ( V_314 == V_318 )
return F_215 ( V_69 , & V_277 ) ;
V_228 = 0 ;
F_61 () ;
V_7 = F_72 ( V_29 ) ;
if ( V_314 == V_317 && ! V_7 ) {
V_277 . V_278 [ V_320 - 1 ] = '\0' ;
V_228 = F_194 ( V_29 -> V_43 , V_69 , & V_277 ) ;
if ( V_228 )
goto V_33;
if ( F_220 ( V_316 , & V_277 , V_315 ) )
V_228 = - V_93 ;
goto V_33;
}
if ( V_314 == V_321 ) {
V_228 = - V_281 ;
if ( V_7 )
goto V_33;
V_228 = - V_93 ;
if ( F_82 ( & V_287 , V_316 , sizeof( V_287 ) ) )
goto V_33;
V_228 = 0 ;
V_29 -> V_287 = V_287 ;
goto V_33;
}
V_228 = - V_212 ;
if ( ! V_7 )
goto V_33;
F_6 ( V_10 , V_7 , L_20 , V_314 ) ;
V_228 = 0 ;
switch ( V_314 ) {
case V_322 :
F_208 ( V_237 -> V_323 -> V_324 , V_7 , & V_277 ) ;
if ( V_29 -> V_32 )
V_277 . V_279 |= V_313 ;
if ( ! V_29 -> V_64 . V_52 -> V_106 )
V_277 . V_279 |= V_282 ;
if ( F_220 ( V_316 , & V_277 , V_315 ) )
V_228 = - V_93 ;
break;
case V_325 :
F_6 ( V_10 , V_7 , L_21 ,
V_87 ? L_22 : L_23 ) ;
break;
case V_326 :
if ( V_87 && ! ( V_7 -> V_59 & V_60 ) ) {
V_7 -> V_59 |= V_60 ;
F_221 ( V_68 ) ;
}
if ( ! V_87 && ( V_7 -> V_59 & V_60 ) ) {
V_7 -> V_59 &= ~ V_60 ;
F_67 ( V_68 ) ;
}
F_6 ( V_10 , V_7 , L_24 ,
V_87 ? L_23 : L_22 ) ;
break;
case V_327 :
V_44 = F_222 ( F_191 () , V_87 ) ;
if ( ! F_36 ( V_44 ) ) {
V_228 = - V_75 ;
break;
}
V_7 -> V_44 = V_44 ;
F_6 ( V_10 , V_7 , L_25 ,
F_223 ( & V_328 , V_7 -> V_44 ) ) ;
break;
case V_329 :
V_46 = F_224 ( F_191 () , V_87 ) ;
if ( ! F_38 ( V_46 ) ) {
V_228 = - V_75 ;
break;
}
V_7 -> V_46 = V_46 ;
F_6 ( V_10 , V_7 , L_26 ,
F_225 ( & V_328 , V_7 -> V_46 ) ) ;
break;
case V_330 :
if ( V_7 -> V_36 -> V_59 & V_331 ) {
F_6 ( V_10 , V_7 ,
L_27 ) ;
V_228 = - V_76 ;
} else {
V_7 -> V_36 -> type = ( int ) V_87 ;
F_6 ( V_10 , V_7 , L_28 ,
V_7 -> V_36 -> type ) ;
V_228 = 0 ;
}
break;
#ifdef F_226
case V_332 :
V_7 -> V_333 = V_87 ;
break;
#endif
case V_334 :
V_228 = F_209 ( V_7 , V_87 ) ;
break;
case V_335 :
V_228 = - V_75 ;
if ( ( V_7 -> V_59 & V_128 ) != V_138 )
break;
V_228 = F_81 ( & V_7 -> V_105 , ( void T_4 * ) V_87 ) ;
break;
case V_336 :
memcpy ( V_277 . V_337 . V_338 , V_7 -> V_36 -> V_339 , V_84 ) ;
V_277 . V_337 . V_340 = V_7 -> V_36 -> type ;
if ( F_220 ( V_316 , & V_277 , V_315 ) )
V_228 = - V_93 ;
break;
case V_341 :
F_6 ( V_342 , V_7 , L_29 ,
V_277 . V_337 . V_338 ) ;
V_228 = F_227 ( V_7 -> V_36 , & V_277 . V_337 ) ;
break;
case V_343 :
V_288 = V_29 -> V_64 . V_52 -> V_289 ;
if ( F_220 ( V_316 , & V_288 , sizeof( V_288 ) ) )
V_228 = - V_93 ;
break;
case V_344 :
if ( F_82 ( & V_288 , V_316 , sizeof( V_288 ) ) ) {
V_228 = - V_93 ;
break;
}
V_7 -> V_288 = V_288 ;
F_214 ( V_7 ) ;
break;
case V_345 :
V_170 = V_7 -> V_170 ;
if ( F_220 ( V_316 , & V_170 , sizeof( V_170 ) ) )
V_228 = - V_93 ;
break;
case V_346 :
if ( F_82 ( & V_170 , V_316 , sizeof( V_170 ) ) ) {
V_228 = - V_93 ;
break;
}
if ( V_170 < ( int ) sizeof( struct V_162 ) ) {
V_228 = - V_75 ;
break;
}
V_7 -> V_170 = V_170 ;
break;
case V_347 :
V_228 = - V_75 ;
if ( ( V_7 -> V_59 & V_128 ) != V_138 )
break;
V_228 = - V_93 ;
if ( F_82 ( & V_7 -> V_81 , V_316 , sizeof( V_7 -> V_81 ) ) )
break;
V_228 = F_213 ( V_7 ) ;
break;
case V_348 :
V_228 = - V_75 ;
if ( ( V_7 -> V_59 & V_128 ) != V_138 )
break;
V_228 = 0 ;
F_211 ( V_7 , V_7 -> V_31 ) ;
break;
case V_349 :
V_228 = - V_75 ;
if ( ( V_7 -> V_59 & V_128 ) != V_138 )
break;
V_228 = - V_93 ;
if ( F_220 ( V_316 , & V_7 -> V_81 , sizeof( V_7 -> V_81 ) ) )
break;
V_228 = 0 ;
break;
default:
V_228 = - V_75 ;
break;
}
V_33:
F_62 () ;
if ( V_7 )
F_76 ( V_7 ) ;
return V_228 ;
}
static long F_228 ( struct V_69 * V_69 ,
unsigned int V_314 , unsigned long V_87 )
{
return F_217 ( V_69 , V_314 , V_87 , sizeof ( struct V_276 ) ) ;
}
static long F_229 ( struct V_69 * V_69 ,
unsigned int V_314 , unsigned long V_87 )
{
switch ( V_314 ) {
case V_317 :
case V_322 :
case V_335 :
case V_343 :
case V_344 :
case V_336 :
case V_341 :
V_87 = ( unsigned long ) F_230 ( V_87 ) ;
break;
default:
V_87 = ( V_350 ) V_87 ;
break;
}
return F_217 ( V_69 , V_314 , V_87 , sizeof( struct V_351 ) ) ;
}
static int F_231 ( int V_352 , struct V_69 * V_69 , int V_353 )
{
struct V_28 * V_29 = V_69 -> V_71 ;
int V_228 ;
if ( ( V_228 = F_232 ( V_352 , V_69 , V_353 , & V_29 -> V_110 ) ) < 0 )
goto V_74;
if ( V_353 ) {
V_228 = F_233 ( V_69 , F_234 ( V_237 ) , V_354 , 0 ) ;
if ( V_228 )
goto V_74;
V_29 -> V_59 |= V_109 ;
} else
V_29 -> V_59 &= ~ V_109 ;
V_228 = 0 ;
V_74:
return V_228 ;
}
static int F_235 ( struct V_355 * V_355 , struct V_69 * V_69 )
{
struct V_28 * V_29 ;
F_236 ( V_10 , L_30 ) ;
V_29 = (struct V_28 * ) F_237 ( & V_356 , V_357 , V_94 ,
& V_358 ) ;
if ( ! V_29 )
return - V_95 ;
F_53 ( V_29 -> V_7 , NULL ) ;
V_29 -> V_43 = F_238 ( V_237 -> V_323 -> V_324 ) ;
V_29 -> V_59 = 0 ;
V_29 -> V_287 = 0 ;
F_53 ( V_29 -> V_64 . V_66 , & V_29 -> V_66 ) ;
F_239 ( & V_29 -> V_66 . V_67 ) ;
V_29 -> V_64 . V_69 = V_69 ;
V_29 -> V_64 . V_359 = & V_360 ;
F_240 ( & V_29 -> V_64 , & V_29 -> V_52 ) ;
F_241 ( & V_29 -> V_52 , V_29 -> V_43 ) ;
V_29 -> V_52 . V_361 = F_176 ;
V_29 -> V_52 . V_289 = V_362 ;
V_69 -> V_71 = V_29 ;
F_242 ( V_63 , & V_29 -> V_64 . V_59 ) ;
F_202 ( & V_29 -> V_49 ) ;
F_243 ( & V_29 -> V_52 , V_363 ) ;
return 0 ;
}
static int F_244 ( struct V_355 * V_355 , struct V_69 * V_69 )
{
struct V_28 * V_29 = V_69 -> V_71 ;
struct V_43 * V_43 = V_29 -> V_43 ;
F_60 ( V_29 , true ) ;
F_245 ( V_43 ) ;
return 0 ;
}
static int F_246 ( struct V_35 * V_36 , struct V_364 * V_314 )
{
V_314 -> V_365 = 0 ;
V_314 -> V_366 = 0 ;
F_247 ( V_314 , V_367 ) ;
V_314 -> V_368 = V_369 ;
V_314 -> V_370 = V_371 ;
V_314 -> V_372 = 0 ;
V_314 -> V_373 = V_374 ;
V_314 -> V_375 = V_376 ;
V_314 -> V_377 = 0 ;
V_314 -> V_378 = 0 ;
return 0 ;
}
static void F_248 ( struct V_35 * V_36 , struct V_379 * V_380 )
{
struct V_6 * V_7 = F_27 ( V_36 ) ;
F_249 ( V_380 -> V_381 , V_382 , sizeof( V_380 -> V_381 ) ) ;
F_249 ( V_380 -> V_383 , V_384 , sizeof( V_380 -> V_383 ) ) ;
switch ( V_7 -> V_59 & V_128 ) {
case V_129 :
F_249 ( V_380 -> V_385 , L_31 , sizeof( V_380 -> V_385 ) ) ;
break;
case V_138 :
F_249 ( V_380 -> V_385 , L_32 , sizeof( V_380 -> V_385 ) ) ;
break;
}
}
static T_1 F_250 ( struct V_35 * V_36 )
{
#ifdef F_226
struct V_6 * V_7 = F_27 ( V_36 ) ;
return V_7 -> V_333 ;
#else
return - V_386 ;
#endif
}
static void F_251 ( struct V_35 * V_36 , T_1 V_387 )
{
#ifdef F_226
struct V_6 * V_7 = F_27 ( V_36 ) ;
V_7 -> V_333 = V_387 ;
#endif
}
static int T_15 F_252 ( void )
{
int V_228 = 0 ;
F_253 ( L_33 , V_388 , V_384 ) ;
F_253 ( L_34 , V_389 ) ;
V_228 = F_254 ( & V_286 ) ;
if ( V_228 ) {
F_152 ( L_35 ) ;
goto V_390;
}
V_228 = F_255 ( & V_391 ) ;
if ( V_228 ) {
F_152 ( L_36 , V_392 ) ;
goto V_393;
}
return 0 ;
V_393:
F_256 ( & V_286 ) ;
V_390:
return V_228 ;
}
static void F_257 ( void )
{
F_258 ( & V_391 ) ;
F_256 ( & V_286 ) ;
}
struct V_64 * F_259 ( struct V_69 * V_69 )
{
struct V_28 * V_29 ;
if ( V_69 -> V_394 != & V_395 )
return F_126 ( - V_75 ) ;
V_29 = V_69 -> V_71 ;
if ( ! V_29 )
return F_126 ( - V_212 ) ;
return & V_29 -> V_64 ;
}
