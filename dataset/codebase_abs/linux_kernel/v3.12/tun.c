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
static T_2 F_26 ( struct V_35 * V_36 , struct V_37 * V_38 )
{
struct V_6 * V_7 = F_27 ( V_36 ) ;
struct V_2 * V_5 ;
T_1 V_39 = 0 ;
T_1 V_31 = 0 ;
F_22 () ;
V_31 = F_28 ( V_7 -> V_31 ) ;
V_39 = F_29 ( V_38 ) ;
if ( V_39 ) {
V_5 = F_2 ( & V_7 -> V_30 [ F_1 ( V_39 ) ] , V_39 ) ;
if ( V_5 )
V_39 = V_5 -> V_8 ;
else
V_39 = ( ( V_40 ) V_39 * V_31 ) >> 32 ;
} else if ( F_23 ( F_30 ( V_38 ) ) ) {
V_39 = F_31 ( V_38 ) ;
while ( F_32 ( V_39 >= V_31 ) )
V_39 -= V_31 ;
}
F_25 () ;
return V_39 ;
}
static inline bool F_33 ( struct V_6 * V_7 )
{
const struct V_41 * V_41 = F_34 () ;
struct V_42 * V_42 = F_35 ( V_7 -> V_36 ) ;
return ( ( F_36 ( V_7 -> V_43 ) && ! F_37 ( V_41 -> V_44 , V_7 -> V_43 ) ) ||
( F_38 ( V_7 -> V_45 ) && ! F_39 ( V_7 -> V_45 ) ) ) &&
! F_40 ( V_42 -> V_46 , V_47 ) ;
}
static void F_41 ( struct V_6 * V_7 )
{
F_42 ( V_7 -> V_36 , V_7 -> V_31 ) ;
F_43 ( V_7 -> V_36 , V_7 -> V_31 ) ;
}
static void F_44 ( struct V_6 * V_7 , struct V_28 * V_29 )
{
V_29 -> V_32 = V_7 ;
F_45 ( & V_29 -> V_48 , & V_7 -> V_49 ) ;
++ V_7 -> V_50 ;
}
static struct V_6 * F_46 ( struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_32 ;
V_29 -> V_32 = NULL ;
F_47 ( & V_29 -> V_48 ) ;
-- V_7 -> V_50 ;
return V_7 ;
}
static void F_48 ( struct V_28 * V_29 )
{
F_49 ( & V_29 -> V_51 . V_52 ) ;
F_49 ( & V_29 -> V_51 . V_53 ) ;
}
static void F_50 ( struct V_28 * V_29 , bool V_54 )
{
struct V_28 * V_55 ;
struct V_6 * V_7 ;
V_7 = F_51 ( V_29 -> V_7 ) ;
if ( V_7 && ! V_29 -> V_32 ) {
T_2 V_56 = V_29 -> V_8 ;
F_52 ( V_56 >= V_7 -> V_31 ) ;
F_53 ( V_7 -> V_57 [ V_56 ] ,
V_7 -> V_57 [ V_7 -> V_31 - 1 ] ) ;
V_55 = F_51 ( V_7 -> V_57 [ V_56 ] ) ;
V_55 -> V_8 = V_56 ;
-- V_7 -> V_31 ;
if ( V_54 ) {
F_53 ( V_29 -> V_7 , NULL ) ;
F_54 ( & V_29 -> V_51 ) ;
} else
F_44 ( V_7 , V_29 ) ;
F_55 () ;
F_15 ( V_7 , V_7 -> V_31 + 1 ) ;
F_48 ( V_29 ) ;
F_41 ( V_7 ) ;
} else if ( V_29 -> V_32 && V_54 ) {
V_7 = F_46 ( V_29 ) ;
F_54 ( & V_29 -> V_51 ) ;
}
if ( V_54 ) {
if ( V_7 && V_7 -> V_31 == 0 && V_7 -> V_50 == 0 ) {
F_56 ( V_7 -> V_36 ) ;
if ( ! ( V_7 -> V_58 & V_59 ) &&
V_7 -> V_36 -> V_60 == V_61 )
F_57 ( V_7 -> V_36 ) ;
}
F_52 ( ! F_58 ( V_62 ,
& V_29 -> V_63 . V_58 ) ) ;
F_59 ( & V_29 -> V_51 ) ;
}
}
static void F_60 ( struct V_28 * V_29 , bool V_54 )
{
F_61 () ;
F_50 ( V_29 , V_54 ) ;
F_62 () ;
}
static void F_63 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_27 ( V_36 ) ;
struct V_28 * V_29 , * V_64 ;
int V_16 , V_20 = V_7 -> V_31 ;
for ( V_16 = 0 ; V_16 < V_20 ; V_16 ++ ) {
V_29 = F_51 ( V_7 -> V_57 [ V_16 ] ) ;
F_52 ( ! V_29 ) ;
F_64 ( & V_29 -> V_65 . V_66 ) ;
F_53 ( V_29 -> V_7 , NULL ) ;
-- V_7 -> V_31 ;
}
F_65 (tfile, &tun->disabled, next) {
F_64 ( & V_29 -> V_65 . V_66 ) ;
F_53 ( V_29 -> V_7 , NULL ) ;
}
F_52 ( V_7 -> V_31 != 0 ) ;
F_55 () ;
for ( V_16 = 0 ; V_16 < V_20 ; V_16 ++ ) {
V_29 = F_51 ( V_7 -> V_57 [ V_16 ] ) ;
F_48 ( V_29 ) ;
F_54 ( & V_29 -> V_51 ) ;
}
F_66 (tfile, tmp, &tun->disabled, next) {
F_46 ( V_29 ) ;
F_48 ( V_29 ) ;
F_54 ( & V_29 -> V_51 ) ;
}
F_52 ( V_7 -> V_50 != 0 ) ;
if ( V_7 -> V_58 & V_59 )
F_67 ( V_67 ) ;
}
static int F_68 ( struct V_6 * V_7 , struct V_68 * V_68 , bool V_69 )
{
struct V_28 * V_29 = V_68 -> V_70 ;
int V_71 ;
V_71 = F_69 ( V_29 -> V_63 . V_51 , V_7 -> V_72 ) ;
if ( V_71 < 0 )
goto V_73;
V_71 = - V_74 ;
if ( F_51 ( V_29 -> V_7 ) && ! V_29 -> V_32 )
goto V_73;
V_71 = - V_75 ;
if ( ! ( V_7 -> V_58 & V_76 ) && V_7 -> V_31 == 1 )
goto V_73;
V_71 = - V_77 ;
if ( ! V_29 -> V_32 &&
V_7 -> V_31 + V_7 -> V_50 == V_78 )
goto V_73;
V_71 = 0 ;
if ( ! V_69 && ( V_7 -> V_79 == true ) ) {
V_71 = F_70 ( & V_7 -> V_80 , V_29 -> V_63 . V_51 ) ;
if ( ! V_71 )
goto V_73;
}
V_29 -> V_8 = V_7 -> V_31 ;
F_53 ( V_29 -> V_7 , V_7 ) ;
F_53 ( V_7 -> V_57 [ V_7 -> V_31 ] , V_29 ) ;
V_7 -> V_31 ++ ;
if ( V_29 -> V_32 )
F_46 ( V_29 ) ;
else
F_71 ( & V_29 -> V_51 ) ;
F_41 ( V_7 ) ;
V_73:
return V_71 ;
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
static struct V_6 * F_75 ( struct V_68 * V_68 )
{
return F_72 ( V_68 -> V_70 ) ;
}
static void F_76 ( struct V_6 * V_7 )
{
F_77 ( V_7 -> V_36 ) ;
}
static void F_78 ( T_1 * V_81 , const T_3 * V_82 )
{
int V_20 = F_79 ( V_83 , V_82 ) >> 26 ;
V_81 [ V_20 >> 5 ] |= ( 1 << ( V_20 & 31 ) ) ;
}
static unsigned int F_80 ( const T_1 * V_81 , const T_3 * V_82 )
{
int V_20 = F_79 ( V_83 , V_82 ) >> 26 ;
return V_81 [ V_20 >> 5 ] & ( 1 << ( V_20 & 31 ) ) ;
}
static int F_81 ( struct V_84 * V_85 , void T_4 * V_86 )
{
struct { T_3 V_87 [ V_83 ] ; } * V_82 ;
struct V_88 V_89 ;
int V_71 , V_90 , V_20 , V_91 ;
if ( F_82 ( & V_89 , V_86 , sizeof( V_89 ) ) )
return - V_92 ;
if ( ! V_89 . V_25 ) {
V_85 -> V_25 = 0 ;
return 0 ;
}
V_90 = V_83 * V_89 . V_25 ;
V_82 = F_5 ( V_90 , V_93 ) ;
if ( ! V_82 )
return - V_94 ;
if ( F_82 ( V_82 , V_86 + sizeof( V_89 ) , V_90 ) ) {
V_71 = - V_92 ;
goto V_95;
}
V_85 -> V_25 = 0 ;
F_83 () ;
for ( V_20 = 0 ; V_20 < V_89 . V_25 && V_20 < V_96 ; V_20 ++ )
memcpy ( V_85 -> V_82 [ V_20 ] , V_82 [ V_20 ] . V_87 , V_83 ) ;
V_91 = V_20 ;
memset ( V_85 -> V_81 , 0 , sizeof( V_85 -> V_81 ) ) ;
for (; V_20 < V_89 . V_25 ; V_20 ++ ) {
if ( ! F_84 ( V_82 [ V_20 ] . V_87 ) ) {
V_71 = 0 ;
goto V_95;
}
F_78 ( V_85 -> V_81 , V_82 [ V_20 ] . V_87 ) ;
}
if ( ( V_89 . V_58 & V_97 ) )
memset ( V_85 -> V_81 , ~ 0 , sizeof( V_85 -> V_81 ) ) ;
F_83 () ;
V_85 -> V_25 = V_91 ;
V_71 = V_91 ;
V_95:
F_85 ( V_82 ) ;
return V_71 ;
}
static int F_86 ( struct V_84 * V_85 , const struct V_37 * V_38 )
{
struct V_98 * V_99 = (struct V_98 * ) V_38 -> V_21 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_85 -> V_25 ; V_16 ++ )
if ( F_87 ( V_99 -> V_100 , V_85 -> V_82 [ V_16 ] ) )
return 1 ;
if ( F_84 ( V_99 -> V_100 ) )
return F_80 ( V_85 -> V_81 , V_99 -> V_100 ) ;
return 0 ;
}
static int F_88 ( struct V_84 * V_85 , const struct V_37 * V_38 )
{
if ( ! V_85 -> V_25 )
return 1 ;
return F_86 ( V_85 , V_38 ) ;
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
int V_39 = V_38 -> V_101 ;
struct V_28 * V_29 ;
F_22 () ;
V_29 = F_73 ( V_7 -> V_57 [ V_39 ] ) ;
if ( V_39 >= V_7 -> V_31 )
goto V_102;
F_6 ( V_10 , V_7 , L_4 , V_38 -> V_103 ) ;
F_52 ( ! V_29 ) ;
if ( ! F_88 ( & V_7 -> V_104 , V_38 ) )
goto V_102;
if ( V_29 -> V_63 . V_51 -> V_105 &&
V_105 ( V_29 -> V_63 . V_51 , V_38 ) )
goto V_102;
if ( F_95 ( & V_29 -> V_63 . V_51 -> V_52 )
>= V_36 -> V_106 / V_7 -> V_31 )
goto V_102;
if ( F_32 ( F_96 ( V_38 , V_9 ) ) )
goto V_102;
if ( V_38 -> V_51 ) {
F_97 ( V_38 -> V_51 , & F_98 ( V_38 ) -> V_107 ) ;
F_99 ( V_38 ) ;
}
F_100 ( V_38 ) ;
F_101 ( V_38 ) ;
F_102 ( & V_29 -> V_63 . V_51 -> V_52 , V_38 ) ;
if ( V_29 -> V_58 & V_108 )
F_103 ( & V_29 -> V_109 , V_110 , V_111 ) ;
F_104 ( & V_29 -> V_65 . V_66 , V_112 |
V_113 | V_114 ) ;
F_25 () ;
return V_115 ;
V_102:
V_36 -> V_116 . V_117 ++ ;
F_105 ( V_38 ) ;
F_106 ( V_38 ) ;
F_25 () ;
return V_115 ;
}
static void F_107 ( struct V_35 * V_36 )
{
}
static int
F_108 ( struct V_35 * V_36 , int V_118 )
{
if ( V_118 < V_119 || V_118 + V_36 -> V_120 > V_121 )
return - V_74 ;
V_36 -> V_122 = V_118 ;
return 0 ;
}
static T_6 F_109 ( struct V_35 * V_36 ,
T_6 V_123 )
{
struct V_6 * V_7 = F_27 ( V_36 ) ;
return ( V_123 & V_7 -> V_124 ) | ( V_123 & ~ V_125 ) ;
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
V_7 -> V_23 = V_126 ;
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
switch ( V_7 -> V_58 & V_127 ) {
case V_128 :
V_36 -> V_129 = & V_130 ;
V_36 -> V_120 = 0 ;
V_36 -> V_131 = 0 ;
V_36 -> V_122 = 1500 ;
V_36 -> type = V_132 ;
V_36 -> V_58 = V_133 | V_134 | V_135 ;
V_36 -> V_106 = V_136 ;
break;
case V_137 :
V_36 -> V_129 = & V_138 ;
F_117 ( V_36 ) ;
V_36 -> V_139 &= ~ V_140 ;
V_36 -> V_139 |= V_141 ;
F_118 ( V_36 ) ;
V_36 -> V_106 = V_136 ;
break;
}
}
static unsigned int F_119 ( struct V_68 * V_68 , T_7 * V_66 )
{
struct V_28 * V_29 = V_68 -> V_70 ;
struct V_6 * V_7 = F_72 ( V_29 ) ;
struct V_142 * V_51 ;
unsigned int V_81 = 0 ;
if ( ! V_7 )
return V_143 ;
V_51 = V_29 -> V_63 . V_51 ;
F_6 ( V_10 , V_7 , L_5 ) ;
F_120 ( V_68 , & V_29 -> V_65 . V_66 , V_66 ) ;
if ( ! F_121 ( & V_51 -> V_52 ) )
V_81 |= V_112 | V_113 ;
if ( F_122 ( V_51 ) ||
( ! F_123 ( V_144 , & V_51 -> V_145 -> V_58 ) &&
F_122 ( V_51 ) ) )
V_81 |= V_146 | V_147 ;
if ( V_7 -> V_36 -> V_60 != V_61 )
V_81 = V_143 ;
F_76 ( V_7 ) ;
return V_81 ;
}
static struct V_37 * F_124 ( struct V_28 * V_29 ,
T_8 V_148 , T_8 V_103 ,
T_8 V_149 , int V_150 )
{
struct V_142 * V_51 = V_29 -> V_63 . V_51 ;
struct V_37 * V_38 ;
int V_71 ;
if ( V_148 + V_103 < V_151 || ! V_149 )
V_149 = V_103 ;
V_38 = F_125 ( V_51 , V_148 + V_149 , V_103 - V_149 , V_150 ,
& V_71 , 0 ) ;
if ( ! V_38 )
return F_126 ( V_71 ) ;
F_127 ( V_38 , V_148 ) ;
F_128 ( V_38 , V_149 ) ;
V_38 -> V_152 = V_103 - V_149 ;
V_38 -> V_103 += V_103 - V_149 ;
return V_38 ;
}
static T_9 F_129 ( struct V_6 * V_7 , struct V_28 * V_29 ,
void * V_153 , const struct V_154 * V_155 ,
T_8 V_156 , T_8 V_25 , int V_150 )
{
struct V_157 V_158 = { 0 , F_130 (ETH_P_IP) } ;
struct V_37 * V_38 ;
T_8 V_103 = V_156 , V_159 = V_160 , V_149 ;
struct V_161 V_162 = { 0 } ;
int V_163 = 0 ;
int V_164 ;
bool V_165 = false ;
int V_71 ;
T_1 V_1 ;
if ( ! ( V_7 -> V_58 & V_166 ) ) {
if ( V_103 < sizeof( V_158 ) )
return - V_74 ;
V_103 -= sizeof( V_158 ) ;
if ( F_131 ( ( void * ) & V_158 , V_155 , 0 , sizeof( V_158 ) ) )
return - V_92 ;
V_163 += sizeof( V_158 ) ;
}
if ( V_7 -> V_58 & V_167 ) {
if ( V_103 < V_7 -> V_168 )
return - V_74 ;
V_103 -= V_7 -> V_168 ;
if ( F_131 ( ( void * ) & V_162 , V_155 , V_163 , sizeof( V_162 ) ) )
return - V_92 ;
if ( ( V_162 . V_58 & V_169 ) &&
V_162 . V_170 + V_162 . V_171 + 2 > V_162 . V_172 )
V_162 . V_172 = V_162 . V_170 + V_162 . V_171 + 2 ;
if ( V_162 . V_172 > V_103 )
return - V_74 ;
V_163 += V_7 -> V_168 ;
}
if ( ( V_7 -> V_58 & V_127 ) == V_137 ) {
V_159 += V_173 ;
if ( F_32 ( V_103 < V_174 ||
( V_162 . V_172 && V_162 . V_172 < V_174 ) ) )
return - V_74 ;
}
if ( V_153 ) {
V_164 = V_162 . V_172 ? V_162 . V_172 : V_175 ;
V_149 = V_164 ;
if ( F_132 ( V_155 , V_163 + V_164 , V_25 ) <= V_176 )
V_165 = true ;
}
if ( ! V_165 ) {
V_164 = V_103 ;
V_149 = V_162 . V_172 ;
}
V_38 = F_124 ( V_29 , V_159 , V_164 , V_149 , V_150 ) ;
if ( F_133 ( V_38 ) ) {
if ( F_134 ( V_38 ) != - V_177 )
V_7 -> V_36 -> V_116 . V_178 ++ ;
return F_134 ( V_38 ) ;
}
if ( V_165 )
V_71 = F_135 ( V_38 , V_155 , V_163 , V_25 ) ;
else {
V_71 = F_136 ( V_38 , 0 , V_155 , V_163 , V_103 ) ;
if ( ! V_71 && V_153 ) {
struct V_179 * V_180 = V_153 ;
V_180 -> V_181 ( V_180 , false ) ;
}
}
if ( V_71 ) {
V_7 -> V_36 -> V_116 . V_178 ++ ;
F_106 ( V_38 ) ;
return - V_92 ;
}
if ( V_162 . V_58 & V_169 ) {
if ( ! F_137 ( V_38 , V_162 . V_170 ,
V_162 . V_171 ) ) {
V_7 -> V_36 -> V_116 . V_182 ++ ;
F_106 ( V_38 ) ;
return - V_74 ;
}
}
switch ( V_7 -> V_58 & V_127 ) {
case V_128 :
if ( V_7 -> V_58 & V_166 ) {
switch ( V_38 -> V_21 [ 0 ] & 0xf0 ) {
case 0x40 :
V_158 . V_183 = F_138 ( V_184 ) ;
break;
case 0x60 :
V_158 . V_183 = F_138 ( V_185 ) ;
break;
default:
V_7 -> V_36 -> V_116 . V_178 ++ ;
F_106 ( V_38 ) ;
return - V_74 ;
}
}
F_139 ( V_38 ) ;
V_38 -> V_186 = V_158 . V_183 ;
V_38 -> V_36 = V_7 -> V_36 ;
break;
case V_137 :
V_38 -> V_186 = F_140 ( V_38 , V_7 -> V_36 ) ;
break;
}
if ( V_162 . V_187 != V_188 ) {
F_141 ( L_6 ) ;
switch ( V_162 . V_187 & ~ V_189 ) {
case V_190 :
F_98 ( V_38 ) -> V_187 = V_191 ;
break;
case V_192 :
F_98 ( V_38 ) -> V_187 = V_193 ;
break;
case V_194 :
F_98 ( V_38 ) -> V_187 = V_195 ;
break;
default:
V_7 -> V_36 -> V_116 . V_182 ++ ;
F_106 ( V_38 ) ;
return - V_74 ;
}
if ( V_162 . V_187 & V_189 )
F_98 ( V_38 ) -> V_187 |= V_196 ;
F_98 ( V_38 ) -> V_197 = V_162 . V_197 ;
if ( F_98 ( V_38 ) -> V_197 == 0 ) {
V_7 -> V_36 -> V_116 . V_182 ++ ;
F_106 ( V_38 ) ;
return - V_74 ;
}
F_98 ( V_38 ) -> V_187 |= V_198 ;
F_98 ( V_38 ) -> V_199 = 0 ;
}
if ( V_165 ) {
F_98 ( V_38 ) -> V_200 = V_153 ;
F_98 ( V_38 ) -> V_107 |= V_201 ;
F_98 ( V_38 ) -> V_107 |= V_202 ;
}
F_142 ( V_38 ) ;
F_143 ( V_38 , 0 ) ;
V_1 = F_29 ( V_38 ) ;
F_144 ( V_38 ) ;
V_7 -> V_36 -> V_116 . V_203 ++ ;
V_7 -> V_36 -> V_116 . V_204 += V_103 ;
F_21 ( V_7 , V_1 , V_29 ) ;
return V_156 ;
}
static T_9 F_145 ( struct V_205 * V_206 , const struct V_154 * V_155 ,
unsigned long V_25 , T_10 V_207 )
{
struct V_68 * V_68 = V_206 -> V_208 ;
struct V_6 * V_7 = F_75 ( V_68 ) ;
struct V_28 * V_29 = V_68 -> V_70 ;
T_9 V_209 ;
if ( ! V_7 )
return - V_210 ;
F_6 ( V_10 , V_7 , L_7 , V_25 ) ;
V_209 = F_129 ( V_7 , V_29 , NULL , V_155 , F_146 ( V_155 , V_25 ) ,
V_25 , V_68 -> V_211 & V_212 ) ;
F_76 ( V_7 ) ;
return V_209 ;
}
static T_9 F_147 ( struct V_6 * V_7 ,
struct V_28 * V_29 ,
struct V_37 * V_38 ,
const struct V_154 * V_155 , int V_103 )
{
struct V_157 V_158 = { 0 , V_38 -> V_186 } ;
T_9 V_213 = 0 ;
int V_214 = 0 ;
if ( ! ( V_7 -> V_58 & V_166 ) ) {
if ( ( V_103 -= sizeof( V_158 ) ) < 0 )
return - V_74 ;
if ( V_103 < V_38 -> V_103 ) {
V_158 . V_58 |= V_215 ;
}
if ( F_148 ( V_155 , ( void * ) & V_158 , 0 , sizeof( V_158 ) ) )
return - V_92 ;
V_213 += sizeof( V_158 ) ;
}
if ( V_7 -> V_58 & V_167 ) {
struct V_161 V_162 = { 0 } ;
if ( ( V_103 -= V_7 -> V_168 ) < 0 )
return - V_74 ;
if ( F_149 ( V_38 ) ) {
struct V_216 * V_217 = F_98 ( V_38 ) ;
V_162 . V_172 = F_150 ( V_38 ) ;
V_162 . V_197 = V_217 -> V_197 ;
if ( V_217 -> V_187 & V_191 )
V_162 . V_187 = V_190 ;
else if ( V_217 -> V_187 & V_193 )
V_162 . V_187 = V_192 ;
else if ( V_217 -> V_187 & V_195 )
V_162 . V_187 = V_194 ;
else {
F_151 ( L_8
L_9 ,
V_217 -> V_187 , V_162 . V_197 ,
V_162 . V_172 ) ;
F_152 ( V_218 , L_10 ,
V_219 ,
16 , 1 , V_38 -> V_4 ,
F_153 ( ( int ) V_162 . V_172 , 64 ) , true ) ;
F_154 ( 1 ) ;
return - V_74 ;
}
if ( V_217 -> V_187 & V_196 )
V_162 . V_187 |= V_189 ;
} else
V_162 . V_187 = V_188 ;
if ( V_38 -> V_220 == V_221 ) {
V_162 . V_58 = V_169 ;
V_162 . V_170 = F_155 ( V_38 ) ;
V_162 . V_171 = V_38 -> V_171 ;
} else if ( V_38 -> V_220 == V_222 ) {
V_162 . V_58 = V_223 ;
}
if ( F_32 ( F_148 ( V_155 , ( void * ) & V_162 , V_213 ,
sizeof( V_162 ) ) ) )
return - V_92 ;
V_213 += V_7 -> V_168 ;
}
if ( ! F_156 ( V_38 ) ) {
V_103 = F_157 ( int , V_38 -> V_103 , V_103 ) ;
} else {
int V_224 , V_225 ;
struct {
T_11 V_226 ;
T_11 V_227 ;
} V_228 ;
V_228 . V_226 = V_38 -> V_229 ;
V_228 . V_227 = F_138 ( F_158 ( V_38 ) ) ;
V_214 = F_159 ( struct V_230 , V_226 ) ;
V_103 = F_157 ( int , V_38 -> V_103 + V_231 , V_103 ) ;
V_224 = F_157 ( int , V_214 , V_103 ) ;
V_225 = F_160 ( V_38 , 0 , V_155 , V_213 , V_224 ) ;
V_103 -= V_224 ;
V_213 += V_224 ;
if ( V_225 || ! V_103 )
goto V_95;
V_224 = F_157 ( int , sizeof( V_228 ) , V_103 ) ;
V_225 = F_148 ( V_155 , ( void * ) & V_228 , V_213 , V_224 ) ;
V_103 -= V_224 ;
V_213 += V_224 ;
if ( V_225 || ! V_103 )
goto V_95;
}
F_160 ( V_38 , V_214 , V_155 , V_213 , V_103 ) ;
V_213 += V_103 ;
V_95:
V_7 -> V_36 -> V_116 . V_232 ++ ;
V_7 -> V_36 -> V_116 . V_233 += V_103 ;
return V_213 ;
}
static T_9 F_161 ( struct V_6 * V_7 , struct V_28 * V_29 ,
struct V_205 * V_206 , const struct V_154 * V_155 ,
T_9 V_103 , int V_150 )
{
F_162 ( V_66 , V_234 ) ;
struct V_37 * V_38 ;
T_9 V_225 = 0 ;
F_6 ( V_10 , V_7 , L_11 ) ;
if ( F_32 ( ! V_150 ) )
F_163 ( & V_29 -> V_65 . V_66 , & V_66 ) ;
while ( V_103 ) {
if ( F_32 ( ! V_150 ) )
V_234 -> V_235 = V_236 ;
if ( ! ( V_38 = F_164 ( & V_29 -> V_63 . V_51 -> V_52 ) ) ) {
if ( V_150 ) {
V_225 = - V_177 ;
break;
}
if ( F_165 ( V_234 ) ) {
V_225 = - V_237 ;
break;
}
if ( V_7 -> V_36 -> V_60 != V_61 ) {
V_225 = - V_238 ;
break;
}
F_166 () ;
continue;
}
V_225 = F_147 ( V_7 , V_29 , V_38 , V_155 , V_103 ) ;
F_106 ( V_38 ) ;
break;
}
if ( F_32 ( ! V_150 ) ) {
V_234 -> V_235 = V_239 ;
F_167 ( & V_29 -> V_65 . V_66 , & V_66 ) ;
}
return V_225 ;
}
static T_9 F_168 ( struct V_205 * V_206 , const struct V_154 * V_155 ,
unsigned long V_25 , T_10 V_207 )
{
struct V_68 * V_68 = V_206 -> V_208 ;
struct V_28 * V_29 = V_68 -> V_70 ;
struct V_6 * V_7 = F_72 ( V_29 ) ;
T_9 V_103 , V_225 ;
if ( ! V_7 )
return - V_210 ;
V_103 = F_146 ( V_155 , V_25 ) ;
if ( V_103 < 0 ) {
V_225 = - V_74 ;
goto V_73;
}
V_225 = F_161 ( V_7 , V_29 , V_206 , V_155 , V_103 ,
V_68 -> V_211 & V_212 ) ;
V_225 = F_157 ( T_9 , V_225 , V_103 ) ;
V_73:
F_76 ( V_7 ) ;
return V_225 ;
}
static void F_169 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_27 ( V_36 ) ;
F_52 ( ! ( F_170 ( & V_7 -> V_49 ) ) ) ;
F_114 ( V_7 ) ;
F_171 ( V_7 -> V_72 ) ;
F_172 ( V_36 ) ;
}
static void F_173 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_27 ( V_36 ) ;
V_7 -> V_43 = V_240 ;
V_7 -> V_45 = V_241 ;
V_36 -> V_242 = & V_243 ;
V_36 -> V_244 = F_169 ;
}
static int F_174 ( struct V_245 * V_246 [] , struct V_245 * V_21 [] )
{
return - V_74 ;
}
static void F_175 ( struct V_142 * V_51 )
{
struct V_28 * V_29 ;
T_12 * V_247 ;
if ( ! F_122 ( V_51 ) )
return;
if ( ! F_176 ( V_144 , & V_51 -> V_145 -> V_58 ) )
return;
V_247 = F_177 ( V_51 ) ;
if ( V_247 && F_178 ( V_247 ) )
F_179 ( V_247 , V_146 |
V_147 | V_248 ) ;
V_29 = F_180 ( V_51 , struct V_28 , V_51 ) ;
F_103 ( & V_29 -> V_109 , V_110 , V_249 ) ;
}
static int F_181 ( struct V_205 * V_206 , struct V_63 * V_142 ,
struct V_250 * V_251 , T_8 V_156 )
{
int V_225 ;
struct V_28 * V_29 = F_180 ( V_142 , struct V_28 , V_63 ) ;
struct V_6 * V_7 = F_72 ( V_29 ) ;
if ( ! V_7 )
return - V_210 ;
V_225 = F_129 ( V_7 , V_29 , V_251 -> V_153 , V_251 -> V_252 , V_156 ,
V_251 -> V_253 , V_251 -> V_254 & V_255 ) ;
F_76 ( V_7 ) ;
return V_225 ;
}
static int F_182 ( struct V_205 * V_206 , struct V_63 * V_142 ,
struct V_250 * V_251 , T_8 V_156 ,
int V_58 )
{
struct V_28 * V_29 = F_180 ( V_142 , struct V_28 , V_63 ) ;
struct V_6 * V_7 = F_72 ( V_29 ) ;
int V_225 ;
if ( ! V_7 )
return - V_210 ;
if ( V_58 & ~ ( V_255 | V_256 | V_257 ) ) {
V_225 = - V_74 ;
goto V_73;
}
if ( V_58 & V_257 ) {
V_225 = F_183 ( V_142 -> V_51 , V_251 , V_156 ,
V_258 , V_259 ) ;
goto V_73;
}
V_225 = F_161 ( V_7 , V_29 , V_206 , V_251 -> V_252 , V_156 ,
V_58 & V_255 ) ;
if ( V_225 > V_156 ) {
V_251 -> V_254 |= V_256 ;
V_225 = V_58 & V_256 ? V_225 : V_156 ;
}
V_73:
F_76 ( V_7 ) ;
return V_225 ;
}
static int F_184 ( struct V_63 * V_142 )
{
if ( V_142 -> V_51 )
F_54 ( V_142 -> V_51 ) ;
return 0 ;
}
static int F_185 ( struct V_6 * V_7 )
{
int V_58 = 0 ;
if ( V_7 -> V_58 & V_128 )
V_58 |= V_260 ;
else
V_58 |= V_261 ;
if ( V_7 -> V_58 & V_166 )
V_58 |= V_262 ;
if ( V_7 -> V_58 & V_263 )
V_58 |= V_264 ;
if ( V_7 -> V_58 & V_167 )
V_58 |= V_265 ;
if ( V_7 -> V_58 & V_76 )
V_58 |= V_266 ;
if ( V_7 -> V_58 & V_59 )
V_58 |= V_267 ;
return V_58 ;
}
static T_9 F_186 ( struct V_268 * V_36 , struct V_269 * V_270 ,
char * V_271 )
{
struct V_6 * V_7 = F_27 ( F_187 ( V_36 ) ) ;
return sprintf ( V_271 , L_12 , F_185 ( V_7 ) ) ;
}
static T_9 F_188 ( struct V_268 * V_36 , struct V_269 * V_270 ,
char * V_271 )
{
struct V_6 * V_7 = F_27 ( F_187 ( V_36 ) ) ;
return F_36 ( V_7 -> V_43 ) ?
sprintf ( V_271 , L_13 ,
F_189 ( F_190 () , V_7 -> V_43 ) ) :
sprintf ( V_271 , L_14 ) ;
}
static T_9 F_191 ( struct V_268 * V_36 , struct V_269 * V_270 ,
char * V_271 )
{
struct V_6 * V_7 = F_27 ( F_187 ( V_36 ) ) ;
return F_38 ( V_7 -> V_45 ) ?
sprintf ( V_271 , L_13 ,
F_192 ( F_190 () , V_7 -> V_45 ) ) :
sprintf ( V_271 , L_14 ) ;
}
static int F_193 ( struct V_42 * V_42 , struct V_68 * V_68 , struct V_272 * V_273 )
{
struct V_6 * V_7 ;
struct V_28 * V_29 = V_68 -> V_70 ;
struct V_35 * V_36 ;
int V_71 ;
if ( V_29 -> V_32 )
return - V_74 ;
V_36 = F_194 ( V_42 , V_273 -> V_274 ) ;
if ( V_36 ) {
if ( V_273 -> V_275 & V_276 )
return - V_75 ;
if ( ( V_273 -> V_275 & V_260 ) && V_36 -> V_129 == & V_130 )
V_7 = F_27 ( V_36 ) ;
else if ( ( V_273 -> V_275 & V_261 ) && V_36 -> V_129 == & V_138 )
V_7 = F_27 ( V_36 ) ;
else
return - V_74 ;
if ( ! ! ( V_273 -> V_275 & V_266 ) !=
! ! ( V_7 -> V_58 & V_76 ) )
return - V_74 ;
if ( F_33 ( V_7 ) )
return - V_277 ;
V_71 = F_195 ( V_7 -> V_72 ) ;
if ( V_71 < 0 )
return V_71 ;
V_71 = F_68 ( V_7 , V_68 , V_273 -> V_275 & V_278 ) ;
if ( V_71 < 0 )
return V_71 ;
if ( V_7 -> V_58 & V_76 &&
( V_7 -> V_31 + V_7 -> V_50 > 1 ) ) {
return 0 ;
}
}
else {
char * V_279 ;
unsigned long V_58 = 0 ;
int V_280 = V_273 -> V_275 & V_266 ?
V_78 : 1 ;
if ( ! F_40 ( V_42 -> V_46 , V_47 ) )
return - V_277 ;
V_71 = F_196 () ;
if ( V_71 < 0 )
return V_71 ;
if ( V_273 -> V_275 & V_260 ) {
V_58 |= V_128 ;
V_279 = L_15 ;
} else if ( V_273 -> V_275 & V_261 ) {
V_58 |= V_137 ;
V_279 = L_16 ;
} else
return - V_74 ;
if ( * V_273 -> V_274 )
V_279 = V_273 -> V_274 ;
V_36 = F_197 ( sizeof( struct V_6 ) , V_279 ,
F_173 , V_280 , V_280 ) ;
if ( ! V_36 )
return - V_94 ;
F_198 ( V_36 , V_42 ) ;
V_36 -> V_281 = & V_282 ;
V_36 -> V_283 = V_29 -> V_283 ;
V_7 = F_27 ( V_36 ) ;
V_7 -> V_36 = V_36 ;
V_7 -> V_58 = V_58 ;
V_7 -> V_104 . V_25 = 0 ;
V_7 -> V_168 = sizeof( struct V_161 ) ;
V_7 -> V_79 = false ;
V_7 -> V_284 = V_29 -> V_63 . V_51 -> V_285 ;
F_199 ( & V_7 -> V_17 ) ;
V_71 = F_200 ( & V_7 -> V_72 ) ;
if ( V_71 < 0 )
goto V_286;
F_116 ( V_36 ) ;
F_111 ( V_7 ) ;
V_36 -> V_287 = V_288 | V_289 |
V_125 | V_290 |
V_291 ;
V_36 -> V_123 = V_36 -> V_287 ;
V_36 -> V_292 = V_36 -> V_123 ;
F_201 ( & V_7 -> V_49 ) ;
V_71 = F_68 ( V_7 , V_68 , false ) ;
if ( V_71 < 0 )
goto V_293;
V_71 = F_202 ( V_7 -> V_36 ) ;
if ( V_71 < 0 )
goto V_294;
if ( F_203 ( & V_7 -> V_36 -> V_36 , & V_295 ) ||
F_203 ( & V_7 -> V_36 -> V_36 , & V_296 ) ||
F_203 ( & V_7 -> V_36 -> V_36 , & V_297 ) )
F_151 ( L_17 ) ;
}
F_204 ( V_7 -> V_36 ) ;
F_6 ( V_10 , V_7 , L_18 ) ;
if ( V_273 -> V_275 & V_262 )
V_7 -> V_58 |= V_166 ;
else
V_7 -> V_58 &= ~ V_166 ;
if ( V_273 -> V_275 & V_264 )
V_7 -> V_58 |= V_263 ;
else
V_7 -> V_58 &= ~ V_263 ;
if ( V_273 -> V_275 & V_265 )
V_7 -> V_58 |= V_167 ;
else
V_7 -> V_58 &= ~ V_167 ;
if ( V_273 -> V_275 & V_266 )
V_7 -> V_58 |= V_76 ;
else
V_7 -> V_58 &= ~ V_76 ;
if ( F_205 ( V_7 -> V_36 ) )
F_206 ( V_7 -> V_36 ) ;
strcpy ( V_273 -> V_274 , V_7 -> V_36 -> V_279 ) ;
return 0 ;
V_294:
F_63 ( V_36 ) ;
V_293:
F_114 ( V_7 ) ;
F_171 ( V_7 -> V_72 ) ;
V_286:
F_172 ( V_36 ) ;
return V_71 ;
}
static void F_207 ( struct V_42 * V_42 , struct V_6 * V_7 ,
struct V_272 * V_273 )
{
F_6 ( V_10 , V_7 , L_19 ) ;
strcpy ( V_273 -> V_274 , V_7 -> V_36 -> V_279 ) ;
V_273 -> V_275 = F_185 ( V_7 ) ;
}
static int F_208 ( struct V_6 * V_7 , unsigned long V_86 )
{
T_6 V_123 = 0 ;
if ( V_86 & V_298 ) {
V_123 |= V_299 ;
V_86 &= ~ V_298 ;
if ( V_86 & ( V_300 | V_301 ) ) {
if ( V_86 & V_302 ) {
V_123 |= V_303 ;
V_86 &= ~ V_302 ;
}
if ( V_86 & V_300 )
V_123 |= V_304 ;
if ( V_86 & V_301 )
V_123 |= V_305 ;
V_86 &= ~ ( V_300 | V_301 ) ;
}
if ( V_86 & V_306 ) {
V_123 |= V_307 ;
V_86 &= ~ V_306 ;
}
}
if ( V_86 )
return - V_74 ;
V_7 -> V_124 = V_123 ;
F_209 ( V_7 -> V_36 ) ;
return 0 ;
}
static void F_210 ( struct V_6 * V_7 , int V_20 )
{
int V_16 ;
struct V_28 * V_29 ;
for ( V_16 = 0 ; V_16 < V_20 ; V_16 ++ ) {
V_29 = F_51 ( V_7 -> V_57 [ V_16 ] ) ;
F_211 ( V_29 -> V_63 . V_51 ) ;
}
V_7 -> V_79 = false ;
}
static int F_212 ( struct V_6 * V_7 )
{
int V_16 , V_225 = 0 ;
struct V_28 * V_29 ;
for ( V_16 = 0 ; V_16 < V_7 -> V_31 ; V_16 ++ ) {
V_29 = F_51 ( V_7 -> V_57 [ V_16 ] ) ;
V_225 = F_70 ( & V_7 -> V_80 , V_29 -> V_63 . V_51 ) ;
if ( V_225 ) {
F_210 ( V_7 , V_16 ) ;
return V_225 ;
}
}
V_7 -> V_79 = true ;
return V_225 ;
}
static void F_213 ( struct V_6 * V_7 )
{
struct V_28 * V_29 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_7 -> V_31 ; V_16 ++ ) {
V_29 = F_51 ( V_7 -> V_57 [ V_16 ] ) ;
V_29 -> V_63 . V_51 -> V_285 = V_7 -> V_284 ;
}
}
static int F_214 ( struct V_68 * V_68 , struct V_272 * V_273 )
{
struct V_28 * V_29 = V_68 -> V_70 ;
struct V_6 * V_7 ;
int V_225 = 0 ;
F_61 () ;
if ( V_273 -> V_275 & V_308 ) {
V_7 = V_29 -> V_32 ;
if ( ! V_7 ) {
V_225 = - V_74 ;
goto V_33;
}
V_225 = F_215 ( V_7 -> V_72 ) ;
if ( V_225 < 0 )
goto V_33;
V_225 = F_68 ( V_7 , V_68 , false ) ;
} else if ( V_273 -> V_275 & V_309 ) {
V_7 = F_51 ( V_29 -> V_7 ) ;
if ( ! V_7 || ! ( V_7 -> V_58 & V_76 ) || V_29 -> V_32 )
V_225 = - V_74 ;
else
F_50 ( V_29 , false ) ;
} else
V_225 = - V_74 ;
V_33:
F_62 () ;
return V_225 ;
}
static long F_216 ( struct V_68 * V_68 , unsigned int V_310 ,
unsigned long V_86 , int V_311 )
{
struct V_28 * V_29 = V_68 -> V_70 ;
struct V_6 * V_7 ;
void T_4 * V_312 = ( void T_4 * ) V_86 ;
struct V_272 V_273 ;
T_13 V_43 ;
T_14 V_45 ;
int V_284 ;
int V_168 ;
unsigned int V_283 ;
int V_225 ;
if ( V_310 == V_313 || V_310 == V_314 || F_217 ( V_310 ) == 0x89 ) {
if ( F_82 ( & V_273 , V_312 , V_311 ) )
return - V_92 ;
} else {
memset ( & V_273 , 0 , sizeof( V_273 ) ) ;
}
if ( V_310 == V_315 ) {
return F_218 ( V_260 | V_261 | V_262 | V_264 |
V_265 | V_266 ,
( unsigned int T_4 * ) V_312 ) ;
} else if ( V_310 == V_314 )
return F_214 ( V_68 , & V_273 ) ;
V_225 = 0 ;
F_61 () ;
V_7 = F_72 ( V_29 ) ;
if ( V_310 == V_313 && ! V_7 ) {
V_273 . V_274 [ V_316 - 1 ] = '\0' ;
V_225 = F_193 ( V_29 -> V_42 , V_68 , & V_273 ) ;
if ( V_225 )
goto V_33;
if ( F_219 ( V_312 , & V_273 , V_311 ) )
V_225 = - V_92 ;
goto V_33;
}
if ( V_310 == V_317 ) {
V_225 = - V_277 ;
if ( V_7 )
goto V_33;
V_225 = - V_92 ;
if ( F_82 ( & V_283 , V_312 , sizeof( V_283 ) ) )
goto V_33;
V_225 = 0 ;
V_29 -> V_283 = V_283 ;
goto V_33;
}
V_225 = - V_210 ;
if ( ! V_7 )
goto V_33;
F_6 ( V_10 , V_7 , L_20 , V_310 ) ;
V_225 = 0 ;
switch ( V_310 ) {
case V_318 :
F_207 ( V_234 -> V_319 -> V_320 , V_7 , & V_273 ) ;
if ( V_29 -> V_32 )
V_273 . V_275 |= V_309 ;
if ( ! V_29 -> V_63 . V_51 -> V_105 )
V_273 . V_275 |= V_278 ;
if ( F_219 ( V_312 , & V_273 , V_311 ) )
V_225 = - V_92 ;
break;
case V_321 :
F_6 ( V_10 , V_7 , L_21 ,
V_86 ? L_22 : L_23 ) ;
break;
case V_322 :
if ( V_86 && ! ( V_7 -> V_58 & V_59 ) ) {
V_7 -> V_58 |= V_59 ;
F_220 ( V_67 ) ;
}
if ( ! V_86 && ( V_7 -> V_58 & V_59 ) ) {
V_7 -> V_58 &= ~ V_59 ;
F_67 ( V_67 ) ;
}
F_6 ( V_10 , V_7 , L_24 ,
V_86 ? L_23 : L_22 ) ;
break;
case V_323 :
V_43 = F_221 ( F_190 () , V_86 ) ;
if ( ! F_36 ( V_43 ) ) {
V_225 = - V_74 ;
break;
}
V_7 -> V_43 = V_43 ;
F_6 ( V_10 , V_7 , L_25 ,
F_222 ( & V_324 , V_7 -> V_43 ) ) ;
break;
case V_325 :
V_45 = F_223 ( F_190 () , V_86 ) ;
if ( ! F_38 ( V_45 ) ) {
V_225 = - V_74 ;
break;
}
V_7 -> V_45 = V_45 ;
F_6 ( V_10 , V_7 , L_26 ,
F_224 ( & V_324 , V_7 -> V_45 ) ) ;
break;
case V_326 :
if ( V_7 -> V_36 -> V_58 & V_327 ) {
F_6 ( V_10 , V_7 ,
L_27 ) ;
V_225 = - V_75 ;
} else {
V_7 -> V_36 -> type = ( int ) V_86 ;
F_6 ( V_10 , V_7 , L_28 ,
V_7 -> V_36 -> type ) ;
V_225 = 0 ;
}
break;
#ifdef F_225
case V_328 :
V_7 -> V_329 = V_86 ;
break;
#endif
case V_330 :
V_225 = F_208 ( V_7 , V_86 ) ;
break;
case V_331 :
V_225 = - V_74 ;
if ( ( V_7 -> V_58 & V_127 ) != V_137 )
break;
V_225 = F_81 ( & V_7 -> V_104 , ( void T_4 * ) V_86 ) ;
break;
case V_332 :
memcpy ( V_273 . V_333 . V_334 , V_7 -> V_36 -> V_335 , V_83 ) ;
V_273 . V_333 . V_336 = V_7 -> V_36 -> type ;
if ( F_219 ( V_312 , & V_273 , V_311 ) )
V_225 = - V_92 ;
break;
case V_337 :
F_6 ( V_338 , V_7 , L_29 ,
V_273 . V_333 . V_334 ) ;
V_225 = F_226 ( V_7 -> V_36 , & V_273 . V_333 ) ;
break;
case V_339 :
V_284 = V_29 -> V_63 . V_51 -> V_285 ;
if ( F_219 ( V_312 , & V_284 , sizeof( V_284 ) ) )
V_225 = - V_92 ;
break;
case V_340 :
if ( F_82 ( & V_284 , V_312 , sizeof( V_284 ) ) ) {
V_225 = - V_92 ;
break;
}
V_7 -> V_284 = V_284 ;
F_213 ( V_7 ) ;
break;
case V_341 :
V_168 = V_7 -> V_168 ;
if ( F_219 ( V_312 , & V_168 , sizeof( V_168 ) ) )
V_225 = - V_92 ;
break;
case V_342 :
if ( F_82 ( & V_168 , V_312 , sizeof( V_168 ) ) ) {
V_225 = - V_92 ;
break;
}
if ( V_168 < ( int ) sizeof( struct V_161 ) ) {
V_225 = - V_74 ;
break;
}
V_7 -> V_168 = V_168 ;
break;
case V_343 :
V_225 = - V_74 ;
if ( ( V_7 -> V_58 & V_127 ) != V_137 )
break;
V_225 = - V_92 ;
if ( F_82 ( & V_7 -> V_80 , V_312 , sizeof( V_7 -> V_80 ) ) )
break;
V_225 = F_212 ( V_7 ) ;
break;
case V_344 :
V_225 = - V_74 ;
if ( ( V_7 -> V_58 & V_127 ) != V_137 )
break;
V_225 = 0 ;
F_210 ( V_7 , V_7 -> V_31 ) ;
break;
case V_345 :
V_225 = - V_74 ;
if ( ( V_7 -> V_58 & V_127 ) != V_137 )
break;
V_225 = - V_92 ;
if ( F_219 ( V_312 , & V_7 -> V_80 , sizeof( V_7 -> V_80 ) ) )
break;
V_225 = 0 ;
break;
default:
V_225 = - V_74 ;
break;
}
V_33:
F_62 () ;
if ( V_7 )
F_76 ( V_7 ) ;
return V_225 ;
}
static long F_227 ( struct V_68 * V_68 ,
unsigned int V_310 , unsigned long V_86 )
{
return F_216 ( V_68 , V_310 , V_86 , sizeof ( struct V_272 ) ) ;
}
static long F_228 ( struct V_68 * V_68 ,
unsigned int V_310 , unsigned long V_86 )
{
switch ( V_310 ) {
case V_313 :
case V_318 :
case V_331 :
case V_339 :
case V_340 :
case V_332 :
case V_337 :
V_86 = ( unsigned long ) F_229 ( V_86 ) ;
break;
default:
V_86 = ( V_346 ) V_86 ;
break;
}
return F_216 ( V_68 , V_310 , V_86 , sizeof( struct V_347 ) ) ;
}
static int F_230 ( int V_348 , struct V_68 * V_68 , int V_349 )
{
struct V_28 * V_29 = V_68 -> V_70 ;
int V_225 ;
if ( ( V_225 = F_231 ( V_348 , V_68 , V_349 , & V_29 -> V_109 ) ) < 0 )
goto V_73;
if ( V_349 ) {
V_225 = F_232 ( V_68 , F_233 ( V_234 ) , V_350 , 0 ) ;
if ( V_225 )
goto V_73;
V_29 -> V_58 |= V_108 ;
} else
V_29 -> V_58 &= ~ V_108 ;
V_225 = 0 ;
V_73:
return V_225 ;
}
static int F_234 ( struct V_351 * V_351 , struct V_68 * V_68 )
{
struct V_28 * V_29 ;
F_235 ( V_10 , L_30 ) ;
V_29 = (struct V_28 * ) F_236 ( & V_352 , V_353 , V_93 ,
& V_354 ) ;
if ( ! V_29 )
return - V_94 ;
F_53 ( V_29 -> V_7 , NULL ) ;
V_29 -> V_42 = F_237 ( V_234 -> V_319 -> V_320 ) ;
V_29 -> V_58 = 0 ;
V_29 -> V_283 = 0 ;
F_53 ( V_29 -> V_63 . V_65 , & V_29 -> V_65 ) ;
F_238 ( & V_29 -> V_65 . V_66 ) ;
V_29 -> V_63 . V_68 = V_68 ;
V_29 -> V_63 . V_355 = & V_356 ;
F_239 ( & V_29 -> V_63 , & V_29 -> V_51 ) ;
F_240 ( & V_29 -> V_51 , V_29 -> V_42 ) ;
V_29 -> V_51 . V_357 = F_175 ;
V_29 -> V_51 . V_285 = V_358 ;
V_68 -> V_70 = V_29 ;
F_241 ( V_62 , & V_29 -> V_63 . V_58 ) ;
F_201 ( & V_29 -> V_48 ) ;
F_242 ( & V_29 -> V_51 , V_359 ) ;
return 0 ;
}
static int F_243 ( struct V_351 * V_351 , struct V_68 * V_68 )
{
struct V_28 * V_29 = V_68 -> V_70 ;
struct V_42 * V_42 = V_29 -> V_42 ;
F_60 ( V_29 , true ) ;
F_244 ( V_42 ) ;
return 0 ;
}
static int F_245 ( struct V_35 * V_36 , struct V_360 * V_310 )
{
V_310 -> V_361 = 0 ;
V_310 -> V_362 = 0 ;
F_246 ( V_310 , V_363 ) ;
V_310 -> V_364 = V_365 ;
V_310 -> V_366 = V_367 ;
V_310 -> V_368 = 0 ;
V_310 -> V_369 = V_370 ;
V_310 -> V_371 = V_372 ;
V_310 -> V_373 = 0 ;
V_310 -> V_374 = 0 ;
return 0 ;
}
static void F_247 ( struct V_35 * V_36 , struct V_375 * V_376 )
{
struct V_6 * V_7 = F_27 ( V_36 ) ;
F_248 ( V_376 -> V_377 , V_378 , sizeof( V_376 -> V_377 ) ) ;
F_248 ( V_376 -> V_379 , V_380 , sizeof( V_376 -> V_379 ) ) ;
switch ( V_7 -> V_58 & V_127 ) {
case V_128 :
F_248 ( V_376 -> V_381 , L_31 , sizeof( V_376 -> V_381 ) ) ;
break;
case V_137 :
F_248 ( V_376 -> V_381 , L_32 , sizeof( V_376 -> V_381 ) ) ;
break;
}
}
static T_1 F_249 ( struct V_35 * V_36 )
{
#ifdef F_225
struct V_6 * V_7 = F_27 ( V_36 ) ;
return V_7 -> V_329 ;
#else
return - V_382 ;
#endif
}
static void F_250 ( struct V_35 * V_36 , T_1 V_383 )
{
#ifdef F_225
struct V_6 * V_7 = F_27 ( V_36 ) ;
V_7 -> V_329 = V_383 ;
#endif
}
static int T_15 F_251 ( void )
{
int V_225 = 0 ;
F_252 ( L_33 , V_384 , V_380 ) ;
F_252 ( L_34 , V_385 ) ;
V_225 = F_253 ( & V_282 ) ;
if ( V_225 ) {
F_151 ( L_35 ) ;
goto V_386;
}
V_225 = F_254 ( & V_387 ) ;
if ( V_225 ) {
F_151 ( L_36 , V_388 ) ;
goto V_389;
}
return 0 ;
V_389:
F_255 ( & V_282 ) ;
V_386:
return V_225 ;
}
static void F_256 ( void )
{
F_257 ( & V_387 ) ;
F_255 ( & V_282 ) ;
}
struct V_63 * F_258 ( struct V_68 * V_68 )
{
struct V_28 * V_29 ;
if ( V_68 -> V_390 != & V_391 )
return F_126 ( - V_74 ) ;
V_29 = V_68 -> V_70 ;
if ( ! V_29 )
return F_126 ( - V_210 ) ;
return & V_29 -> V_63 ;
}
