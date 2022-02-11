static inline T_1 F_1 ( T_1 V_1 )
{
return V_1 & 0x3ff ;
}
static struct V_2 * F_2 ( struct V_3 * V_4 , T_1 V_1 )
{
struct V_2 * V_5 ;
struct V_6 * V_7 ;
F_3 (e, n, head, hash_link) {
if ( V_5 -> V_1 == V_1 )
return V_5 ;
}
return NULL ;
}
static struct V_2 * F_4 ( struct V_8 * V_9 ,
struct V_3 * V_4 ,
T_1 V_1 , T_2 V_10 )
{
struct V_2 * V_5 = F_5 ( sizeof( * V_5 ) , V_11 ) ;
if ( V_5 ) {
F_6 ( V_12 , V_9 , L_1 ,
V_1 , V_10 ) ;
V_5 -> V_13 = V_14 ;
V_5 -> V_1 = V_1 ;
V_5 -> V_10 = V_10 ;
V_5 -> V_9 = V_9 ;
F_7 ( & V_5 -> V_15 , V_4 ) ;
++ V_9 -> V_16 ;
}
return V_5 ;
}
static void F_8 ( struct V_8 * V_9 , struct V_2 * V_5 )
{
F_6 ( V_12 , V_9 , L_2 ,
V_5 -> V_1 , V_5 -> V_10 ) ;
F_9 ( & V_5 -> V_15 ) ;
F_10 ( V_5 , V_17 ) ;
-- V_9 -> V_16 ;
}
static void F_11 ( struct V_8 * V_9 )
{
int V_18 ;
F_12 ( & V_9 -> V_19 ) ;
for ( V_18 = 0 ; V_18 < V_20 ; V_18 ++ ) {
struct V_2 * V_5 ;
struct V_6 * V_21 , * V_7 ;
F_13 (e, h, n, &tun->flows[i], hash_link)
F_8 ( V_9 , V_5 ) ;
}
F_14 ( & V_9 -> V_19 ) ;
}
static void F_15 ( struct V_8 * V_9 , T_2 V_10 )
{
int V_18 ;
F_12 ( & V_9 -> V_19 ) ;
for ( V_18 = 0 ; V_18 < V_20 ; V_18 ++ ) {
struct V_2 * V_5 ;
struct V_6 * V_21 , * V_7 ;
F_13 (e, h, n, &tun->flows[i], hash_link) {
if ( V_5 -> V_10 == V_10 )
F_8 ( V_9 , V_5 ) ;
}
}
F_14 ( & V_9 -> V_19 ) ;
}
static void F_16 ( unsigned long V_22 )
{
struct V_8 * V_9 = (struct V_8 * ) V_22 ;
unsigned long V_23 = V_9 -> V_24 ;
unsigned long V_25 = V_14 + V_23 ;
unsigned long V_26 = 0 ;
int V_18 ;
F_6 ( V_12 , V_9 , L_3 ) ;
F_12 ( & V_9 -> V_19 ) ;
for ( V_18 = 0 ; V_18 < V_20 ; V_18 ++ ) {
struct V_2 * V_5 ;
struct V_6 * V_21 , * V_7 ;
F_13 (e, h, n, &tun->flows[i], hash_link) {
unsigned long V_27 ;
V_26 ++ ;
V_27 = V_5 -> V_13 + V_23 ;
if ( F_17 ( V_27 , V_14 ) )
F_8 ( V_9 , V_5 ) ;
else if ( F_18 ( V_27 , V_25 ) )
V_25 = V_27 ;
}
}
if ( V_26 )
F_19 ( & V_9 -> V_28 , F_20 ( V_25 ) ) ;
F_14 ( & V_9 -> V_19 ) ;
}
static void F_21 ( struct V_8 * V_9 , T_1 V_1 ,
struct V_29 * V_30 )
{
struct V_3 * V_4 ;
struct V_2 * V_5 ;
unsigned long V_23 = V_9 -> V_24 ;
T_2 V_10 = V_30 -> V_10 ;
if ( ! V_1 )
return;
else
V_4 = & V_9 -> V_31 [ F_1 ( V_1 ) ] ;
F_22 () ;
if ( V_9 -> V_32 == 1 || V_30 -> V_33 )
goto V_34;
V_5 = F_2 ( V_4 , V_1 ) ;
if ( F_23 ( V_5 ) ) {
V_5 -> V_10 = V_10 ;
V_5 -> V_13 = V_14 ;
} else {
F_12 ( & V_9 -> V_19 ) ;
if ( ! F_2 ( V_4 , V_1 ) &&
V_9 -> V_16 < V_35 )
F_4 ( V_9 , V_4 , V_1 , V_10 ) ;
if ( ! F_24 ( & V_9 -> V_28 ) )
F_19 ( & V_9 -> V_28 ,
F_20 ( V_14 + V_23 ) ) ;
F_14 ( & V_9 -> V_19 ) ;
}
V_34:
F_25 () ;
}
static T_2 F_26 ( struct V_36 * V_37 , struct V_38 * V_39 )
{
struct V_8 * V_9 = F_27 ( V_37 ) ;
struct V_2 * V_5 ;
T_1 V_40 = 0 ;
T_1 V_32 = 0 ;
F_22 () ;
V_32 = V_9 -> V_32 ;
V_40 = F_28 ( V_39 ) ;
if ( V_40 ) {
V_5 = F_2 ( & V_9 -> V_31 [ F_1 ( V_40 ) ] , V_40 ) ;
if ( V_5 )
V_40 = V_5 -> V_10 ;
else
V_40 = ( ( V_41 ) V_40 * V_32 ) >> 32 ;
} else if ( F_23 ( F_29 ( V_39 ) ) ) {
V_40 = F_30 ( V_39 ) ;
while ( F_31 ( V_40 >= V_32 ) )
V_40 -= V_32 ;
}
F_25 () ;
return V_40 ;
}
static inline bool F_32 ( struct V_8 * V_9 )
{
const struct V_42 * V_42 = F_33 () ;
struct V_43 * V_43 = F_34 ( V_9 -> V_37 ) ;
return ( ( F_35 ( V_9 -> V_44 ) && ! F_36 ( V_42 -> V_45 , V_9 -> V_44 ) ) ||
( F_37 ( V_9 -> V_46 ) && ! F_38 ( V_9 -> V_46 ) ) ) &&
! F_39 ( V_43 -> V_47 , V_48 ) ;
}
static void F_40 ( struct V_8 * V_9 )
{
F_41 ( V_9 -> V_37 , V_9 -> V_32 ) ;
F_42 ( V_9 -> V_37 , V_9 -> V_32 ) ;
}
static void F_43 ( struct V_8 * V_9 , struct V_29 * V_30 )
{
V_30 -> V_33 = V_9 ;
F_44 ( & V_30 -> V_49 , & V_9 -> V_50 ) ;
++ V_9 -> V_51 ;
}
static struct V_8 * F_45 ( struct V_29 * V_30 )
{
struct V_8 * V_9 = V_30 -> V_33 ;
V_30 -> V_33 = NULL ;
F_46 ( & V_30 -> V_49 ) ;
-- V_9 -> V_51 ;
return V_9 ;
}
static void F_47 ( struct V_29 * V_30 , bool V_52 )
{
struct V_29 * V_53 ;
struct V_8 * V_9 ;
struct V_36 * V_37 ;
V_9 = F_48 ( V_30 -> V_9 ) ;
if ( V_9 && ! V_30 -> V_33 ) {
T_2 V_54 = V_30 -> V_10 ;
F_49 ( V_54 >= V_9 -> V_32 ) ;
V_37 = V_9 -> V_37 ;
F_50 ( V_9 -> V_55 [ V_54 ] ,
V_9 -> V_55 [ V_9 -> V_32 - 1 ] ) ;
V_53 = F_48 ( V_9 -> V_55 [ V_54 ] ) ;
V_53 -> V_10 = V_54 ;
-- V_9 -> V_32 ;
if ( V_52 ) {
F_50 ( V_30 -> V_9 , NULL ) ;
F_51 ( & V_30 -> V_56 ) ;
} else
F_43 ( V_9 , V_30 ) ;
F_52 () ;
F_15 ( V_9 , V_9 -> V_32 + 1 ) ;
F_53 ( & V_30 -> V_56 . V_57 ) ;
F_40 ( V_9 ) ;
} else if ( V_30 -> V_33 && V_52 ) {
V_9 = F_45 ( V_30 ) ;
F_51 ( & V_30 -> V_56 ) ;
}
if ( V_52 ) {
if ( V_9 && V_9 -> V_32 == 0 && V_9 -> V_51 == 0 ) {
F_54 ( V_9 -> V_37 ) ;
if ( ! ( V_9 -> V_58 & V_59 ) &&
V_9 -> V_37 -> V_60 == V_61 )
F_55 ( V_9 -> V_37 ) ;
}
F_49 ( ! F_56 ( V_62 ,
& V_30 -> V_63 . V_58 ) ) ;
F_57 ( & V_30 -> V_56 ) ;
}
}
static void F_58 ( struct V_29 * V_30 , bool V_52 )
{
F_59 () ;
F_47 ( V_30 , V_52 ) ;
F_60 () ;
}
static void F_61 ( struct V_36 * V_37 )
{
struct V_8 * V_9 = F_27 ( V_37 ) ;
struct V_29 * V_30 , * V_64 ;
int V_18 , V_7 = V_9 -> V_32 ;
for ( V_18 = 0 ; V_18 < V_7 ; V_18 ++ ) {
V_30 = F_48 ( V_9 -> V_55 [ V_18 ] ) ;
F_49 ( ! V_30 ) ;
F_62 ( & V_30 -> V_65 . V_66 ) ;
F_50 ( V_30 -> V_9 , NULL ) ;
-- V_9 -> V_32 ;
}
F_63 (tfile, &tun->disabled, next) {
F_62 ( & V_30 -> V_65 . V_66 ) ;
F_50 ( V_30 -> V_9 , NULL ) ;
}
F_49 ( V_9 -> V_32 != 0 ) ;
F_52 () ;
for ( V_18 = 0 ; V_18 < V_7 ; V_18 ++ ) {
V_30 = F_48 ( V_9 -> V_55 [ V_18 ] ) ;
F_53 ( & V_30 -> V_56 . V_57 ) ;
F_51 ( & V_30 -> V_56 ) ;
}
F_64 (tfile, tmp, &tun->disabled, next) {
F_45 ( V_30 ) ;
F_53 ( & V_30 -> V_56 . V_57 ) ;
F_51 ( & V_30 -> V_56 ) ;
}
F_49 ( V_9 -> V_51 != 0 ) ;
if ( V_9 -> V_58 & V_59 )
F_65 ( V_67 ) ;
}
static int F_66 ( struct V_8 * V_9 , struct V_68 * V_68 )
{
struct V_29 * V_30 = V_68 -> V_69 ;
int V_70 ;
V_70 = F_67 ( V_30 -> V_63 . V_56 , V_9 -> V_71 ) ;
if ( V_70 < 0 )
goto V_72;
V_70 = - V_73 ;
if ( F_48 ( V_30 -> V_9 ) && ! V_30 -> V_33 )
goto V_72;
V_70 = - V_74 ;
if ( ! ( V_9 -> V_58 & V_75 ) && V_9 -> V_32 == 1 )
goto V_72;
V_70 = - V_76 ;
if ( ! V_30 -> V_33 &&
V_9 -> V_32 + V_9 -> V_51 == V_77 )
goto V_72;
V_70 = 0 ;
if ( V_9 -> V_78 == true ) {
V_70 = F_68 ( & V_9 -> V_79 , V_30 -> V_63 . V_56 ) ;
if ( ! V_70 )
goto V_72;
}
V_30 -> V_10 = V_9 -> V_32 ;
F_50 ( V_30 -> V_9 , V_9 ) ;
F_50 ( V_9 -> V_55 [ V_9 -> V_32 ] , V_30 ) ;
V_9 -> V_32 ++ ;
if ( V_30 -> V_33 )
F_45 ( V_30 ) ;
else
F_69 ( & V_30 -> V_56 ) ;
F_40 ( V_9 ) ;
V_72:
return V_70 ;
}
static struct V_8 * F_70 ( struct V_29 * V_30 )
{
struct V_8 * V_9 ;
F_22 () ;
V_9 = F_71 ( V_30 -> V_9 ) ;
if ( V_9 )
F_72 ( V_9 -> V_37 ) ;
F_25 () ;
return V_9 ;
}
static struct V_8 * F_73 ( struct V_68 * V_68 )
{
return F_70 ( V_68 -> V_69 ) ;
}
static void F_74 ( struct V_8 * V_9 )
{
F_75 ( V_9 -> V_37 ) ;
}
static void F_76 ( T_1 * V_80 , const T_3 * V_81 )
{
int V_7 = F_77 ( V_82 , V_81 ) >> 26 ;
V_80 [ V_7 >> 5 ] |= ( 1 << ( V_7 & 31 ) ) ;
}
static unsigned int F_78 ( const T_1 * V_80 , const T_3 * V_81 )
{
int V_7 = F_77 ( V_82 , V_81 ) >> 26 ;
return V_80 [ V_7 >> 5 ] & ( 1 << ( V_7 & 31 ) ) ;
}
static int F_79 ( struct V_83 * V_84 , void T_4 * V_85 )
{
struct { T_3 V_86 [ V_82 ] ; } * V_81 ;
struct V_87 V_88 ;
int V_70 , V_89 , V_7 , V_90 ;
if ( F_80 ( & V_88 , V_85 , sizeof( V_88 ) ) )
return - V_91 ;
if ( ! V_88 . V_26 ) {
V_84 -> V_26 = 0 ;
return 0 ;
}
V_89 = V_82 * V_88 . V_26 ;
V_81 = F_5 ( V_89 , V_92 ) ;
if ( ! V_81 )
return - V_93 ;
if ( F_80 ( V_81 , V_85 + sizeof( V_88 ) , V_89 ) ) {
V_70 = - V_91 ;
goto V_94;
}
V_84 -> V_26 = 0 ;
F_81 () ;
for ( V_7 = 0 ; V_7 < V_88 . V_26 && V_7 < V_95 ; V_7 ++ )
memcpy ( V_84 -> V_81 [ V_7 ] , V_81 [ V_7 ] . V_86 , V_82 ) ;
V_90 = V_7 ;
memset ( V_84 -> V_80 , 0 , sizeof( V_84 -> V_80 ) ) ;
for (; V_7 < V_88 . V_26 ; V_7 ++ ) {
if ( ! F_82 ( V_81 [ V_7 ] . V_86 ) ) {
V_70 = 0 ;
goto V_94;
}
F_76 ( V_84 -> V_80 , V_81 [ V_7 ] . V_86 ) ;
}
if ( ( V_88 . V_58 & V_96 ) )
memset ( V_84 -> V_80 , ~ 0 , sizeof( V_84 -> V_80 ) ) ;
F_81 () ;
V_84 -> V_26 = V_90 ;
V_70 = V_90 ;
V_94:
F_83 ( V_81 ) ;
return V_70 ;
}
static int F_84 ( struct V_83 * V_84 , const struct V_38 * V_39 )
{
struct V_97 * V_98 = (struct V_97 * ) V_39 -> V_22 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_84 -> V_26 ; V_18 ++ )
if ( F_85 ( V_98 -> V_99 , V_84 -> V_81 [ V_18 ] ) )
return 1 ;
if ( F_82 ( V_98 -> V_99 ) )
return F_78 ( V_84 -> V_80 , V_98 -> V_99 ) ;
return 0 ;
}
static int F_86 ( struct V_83 * V_84 , const struct V_38 * V_39 )
{
if ( ! V_84 -> V_26 )
return 1 ;
return F_84 ( V_84 , V_39 ) ;
}
static void F_87 ( struct V_36 * V_37 )
{
F_61 ( V_37 ) ;
}
static int F_88 ( struct V_36 * V_37 )
{
F_89 ( V_37 ) ;
return 0 ;
}
static int F_90 ( struct V_36 * V_37 )
{
F_91 ( V_37 ) ;
return 0 ;
}
static T_5 F_92 ( struct V_38 * V_39 , struct V_36 * V_37 )
{
struct V_8 * V_9 = F_27 ( V_37 ) ;
int V_40 = V_39 -> V_100 ;
struct V_29 * V_30 ;
F_22 () ;
V_30 = F_71 ( V_9 -> V_55 [ V_40 ] ) ;
if ( V_40 >= V_9 -> V_32 )
goto V_101;
F_6 ( V_12 , V_9 , L_4 , V_39 -> V_102 ) ;
F_49 ( ! V_30 ) ;
if ( ! F_86 ( & V_9 -> V_103 , V_39 ) )
goto V_101;
if ( V_30 -> V_63 . V_56 -> V_104 &&
V_104 ( V_30 -> V_63 . V_56 , V_39 ) )
goto V_101;
if ( F_93 ( & V_30 -> V_63 . V_56 -> V_57 )
>= V_37 -> V_105 / V_9 -> V_32 )
goto V_101;
if ( F_31 ( F_94 ( V_39 , V_11 ) ) )
goto V_101;
F_95 ( V_39 ) ;
F_96 ( & V_30 -> V_63 . V_56 -> V_57 , V_39 ) ;
if ( V_30 -> V_58 & V_106 )
F_97 ( & V_30 -> V_107 , V_108 , V_109 ) ;
F_98 ( & V_30 -> V_65 . V_66 , V_110 |
V_111 | V_112 ) ;
F_25 () ;
return V_113 ;
V_101:
V_37 -> V_114 . V_115 ++ ;
F_99 ( V_39 ) ;
F_100 ( V_39 ) ;
F_25 () ;
return V_113 ;
}
static void F_101 ( struct V_36 * V_37 )
{
}
static int
F_102 ( struct V_36 * V_37 , int V_116 )
{
if ( V_116 < V_117 || V_116 + V_37 -> V_118 > V_119 )
return - V_73 ;
V_37 -> V_120 = V_116 ;
return 0 ;
}
static T_6 F_103 ( struct V_36 * V_37 ,
T_6 V_121 )
{
struct V_8 * V_9 = F_27 ( V_37 ) ;
return ( V_121 & V_9 -> V_122 ) | ( V_121 & ~ V_123 ) ;
}
static void F_104 ( struct V_36 * V_37 )
{
return;
}
static int F_105 ( struct V_8 * V_9 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_20 ; V_18 ++ )
F_106 ( & V_9 -> V_31 [ V_18 ] ) ;
V_9 -> V_24 = V_124 ;
F_107 ( & V_9 -> V_28 , F_16 , ( unsigned long ) V_9 ) ;
F_19 ( & V_9 -> V_28 ,
F_20 ( V_14 + V_9 -> V_24 ) ) ;
return 0 ;
}
static void F_108 ( struct V_8 * V_9 )
{
F_109 ( & V_9 -> V_28 ) ;
F_11 ( V_9 ) ;
}
static void F_110 ( struct V_36 * V_37 )
{
struct V_8 * V_9 = F_27 ( V_37 ) ;
switch ( V_9 -> V_58 & V_125 ) {
case V_126 :
V_37 -> V_127 = & V_128 ;
V_37 -> V_118 = 0 ;
V_37 -> V_129 = 0 ;
V_37 -> V_120 = 1500 ;
V_37 -> type = V_130 ;
V_37 -> V_58 = V_131 | V_132 | V_133 ;
V_37 -> V_105 = V_134 ;
break;
case V_135 :
V_37 -> V_127 = & V_136 ;
F_111 ( V_37 ) ;
V_37 -> V_137 &= ~ V_138 ;
V_37 -> V_137 |= V_139 ;
F_112 ( V_37 ) ;
V_37 -> V_105 = V_134 ;
break;
}
}
static unsigned int F_113 ( struct V_68 * V_68 , T_7 * V_66 )
{
struct V_29 * V_30 = V_68 -> V_69 ;
struct V_8 * V_9 = F_70 ( V_30 ) ;
struct V_140 * V_56 ;
unsigned int V_80 = 0 ;
if ( ! V_9 )
return V_141 ;
V_56 = V_30 -> V_63 . V_56 ;
F_6 ( V_12 , V_9 , L_5 ) ;
F_114 ( V_68 , & V_30 -> V_65 . V_66 , V_66 ) ;
if ( ! F_115 ( & V_56 -> V_57 ) )
V_80 |= V_110 | V_111 ;
if ( F_116 ( V_56 ) ||
( ! F_117 ( V_142 , & V_56 -> V_143 -> V_58 ) &&
F_116 ( V_56 ) ) )
V_80 |= V_144 | V_145 ;
if ( V_9 -> V_37 -> V_60 != V_61 )
V_80 = V_141 ;
F_74 ( V_9 ) ;
return V_80 ;
}
static struct V_38 * F_118 ( struct V_29 * V_30 ,
T_8 V_146 , T_8 V_102 ,
T_8 V_147 , int V_148 )
{
struct V_140 * V_56 = V_30 -> V_63 . V_56 ;
struct V_38 * V_39 ;
int V_70 ;
if ( V_146 + V_102 < V_149 || ! V_147 )
V_147 = V_102 ;
V_39 = F_119 ( V_56 , V_146 + V_147 , V_102 - V_147 , V_148 ,
& V_70 ) ;
if ( ! V_39 )
return F_120 ( V_70 ) ;
F_121 ( V_39 , V_146 ) ;
F_122 ( V_39 , V_147 ) ;
V_39 -> V_150 = V_102 - V_147 ;
V_39 -> V_102 += V_102 - V_147 ;
return V_39 ;
}
static int F_123 ( struct V_38 * V_39 , const struct V_151 * V_152 ,
int V_153 , T_8 V_26 )
{
int V_102 = F_124 ( V_152 , V_26 ) - V_153 ;
int V_154 = F_125 ( V_39 ) ;
int V_155 , V_156 = 0 ;
int V_18 = 0 ;
while ( V_26 && ( V_153 >= V_152 -> V_157 ) ) {
V_153 -= V_152 -> V_157 ;
++ V_152 ;
-- V_26 ;
}
while ( V_26 && ( V_154 > 0 ) ) {
V_155 = F_126 (unsigned int, copy, from->iov_len - offset) ;
if ( F_80 ( V_39 -> V_22 + V_156 , V_152 -> V_158 + V_153 ,
V_155 ) )
return - V_91 ;
if ( V_154 > V_155 ) {
++ V_152 ;
-- V_26 ;
V_153 = 0 ;
} else
V_153 += V_155 ;
V_154 -= V_155 ;
V_156 += V_155 ;
}
if ( V_102 == V_156 )
return 0 ;
while ( V_26 -- ) {
struct V_159 * V_159 [ V_160 ] ;
int V_161 ;
unsigned long V_162 ;
unsigned long V_163 ;
V_102 = V_152 -> V_157 - V_153 ;
if ( ! V_102 ) {
V_153 = 0 ;
++ V_152 ;
continue;
}
V_162 = ( unsigned long ) V_152 -> V_158 + V_153 ;
V_155 = ( ( V_162 & ~ V_164 ) + V_102 + ~ V_164 ) >> V_165 ;
if ( V_18 + V_155 > V_160 )
return - V_166 ;
V_161 = F_127 ( V_162 , V_155 , 0 , & V_159 [ V_18 ] ) ;
if ( V_161 != V_155 ) {
for ( V_18 = 0 ; V_18 < V_161 ; V_18 ++ )
F_128 ( V_159 [ V_18 ] ) ;
return - V_91 ;
}
V_163 = V_155 * V_149 ;
V_39 -> V_150 += V_102 ;
V_39 -> V_102 += V_102 ;
V_39 -> V_163 += V_163 ;
F_129 ( V_163 , & V_39 -> V_56 -> V_167 ) ;
while ( V_102 ) {
int V_168 = V_162 & ~ V_164 ;
int V_155 = F_126 ( int , V_102 , V_149 - V_168 ) ;
F_130 ( V_39 , V_18 , V_159 [ V_18 ] , V_168 , V_155 ) ;
F_131 ( V_39 ) -> V_169 ++ ;
V_162 += V_155 ;
V_102 -= V_155 ;
V_18 ++ ;
}
V_153 = 0 ;
++ V_152 ;
}
return 0 ;
}
static T_9 F_132 ( struct V_8 * V_9 , struct V_29 * V_30 ,
void * V_170 , const struct V_151 * V_171 ,
T_8 V_172 , T_8 V_26 , int V_148 )
{
struct V_173 V_174 = { 0 , F_133 (ETH_P_IP) } ;
struct V_38 * V_39 ;
T_8 V_102 = V_172 , V_175 = V_176 ;
struct V_177 V_178 = { 0 } ;
int V_153 = 0 ;
int V_179 ;
bool V_180 = false ;
int V_70 ;
T_1 V_1 ;
if ( ! ( V_9 -> V_58 & V_181 ) ) {
if ( ( V_102 -= sizeof( V_174 ) ) > V_172 )
return - V_73 ;
if ( F_134 ( ( void * ) & V_174 , V_171 , 0 , sizeof( V_174 ) ) )
return - V_91 ;
V_153 += sizeof( V_174 ) ;
}
if ( V_9 -> V_58 & V_182 ) {
if ( ( V_102 -= V_9 -> V_183 ) > V_172 )
return - V_73 ;
if ( F_134 ( ( void * ) & V_178 , V_171 , V_153 , sizeof( V_178 ) ) )
return - V_91 ;
if ( ( V_178 . V_58 & V_184 ) &&
V_178 . V_185 + V_178 . V_186 + 2 > V_178 . V_187 )
V_178 . V_187 = V_178 . V_185 + V_178 . V_186 + 2 ;
if ( V_178 . V_187 > V_102 )
return - V_73 ;
V_153 += V_9 -> V_183 ;
}
if ( ( V_9 -> V_58 & V_125 ) == V_135 ) {
V_175 += V_188 ;
if ( F_31 ( V_102 < V_189 ||
( V_178 . V_187 && V_178 . V_187 < V_189 ) ) )
return - V_73 ;
}
if ( V_170 )
V_180 = true ;
if ( V_180 ) {
if ( V_26 > V_160 ) {
V_179 = F_124 ( V_171 , V_26 - V_160 ) ;
if ( V_179 < V_153 )
V_179 = 0 ;
else
V_179 -= V_153 ;
} else
V_179 = 0 ;
if ( V_179 < V_178 . V_187 )
V_179 = V_178 . V_187 ;
if ( ! V_179 )
V_179 = V_190 ;
} else
V_179 = V_102 ;
V_39 = F_118 ( V_30 , V_175 , V_179 , V_178 . V_187 , V_148 ) ;
if ( F_135 ( V_39 ) ) {
if ( F_136 ( V_39 ) != - V_191 )
V_9 -> V_37 -> V_114 . V_192 ++ ;
return F_136 ( V_39 ) ;
}
if ( V_180 )
V_70 = F_123 ( V_39 , V_171 , V_153 , V_26 ) ;
else
V_70 = F_137 ( V_39 , 0 , V_171 , V_153 , V_102 ) ;
if ( V_70 ) {
V_9 -> V_37 -> V_114 . V_192 ++ ;
F_100 ( V_39 ) ;
return - V_91 ;
}
if ( V_178 . V_58 & V_184 ) {
if ( ! F_138 ( V_39 , V_178 . V_185 ,
V_178 . V_186 ) ) {
V_9 -> V_37 -> V_114 . V_193 ++ ;
F_100 ( V_39 ) ;
return - V_73 ;
}
}
switch ( V_9 -> V_58 & V_125 ) {
case V_126 :
if ( V_9 -> V_58 & V_181 ) {
switch ( V_39 -> V_22 [ 0 ] & 0xf0 ) {
case 0x40 :
V_174 . V_194 = F_139 ( V_195 ) ;
break;
case 0x60 :
V_174 . V_194 = F_139 ( V_196 ) ;
break;
default:
V_9 -> V_37 -> V_114 . V_192 ++ ;
F_100 ( V_39 ) ;
return - V_73 ;
}
}
F_140 ( V_39 ) ;
V_39 -> V_197 = V_174 . V_194 ;
V_39 -> V_37 = V_9 -> V_37 ;
break;
case V_135 :
V_39 -> V_197 = F_141 ( V_39 , V_9 -> V_37 ) ;
break;
}
if ( V_178 . V_198 != V_199 ) {
F_142 ( L_6 ) ;
switch ( V_178 . V_198 & ~ V_200 ) {
case V_201 :
F_131 ( V_39 ) -> V_198 = V_202 ;
break;
case V_203 :
F_131 ( V_39 ) -> V_198 = V_204 ;
break;
case V_205 :
F_131 ( V_39 ) -> V_198 = V_206 ;
break;
default:
V_9 -> V_37 -> V_114 . V_193 ++ ;
F_100 ( V_39 ) ;
return - V_73 ;
}
if ( V_178 . V_198 & V_200 )
F_131 ( V_39 ) -> V_198 |= V_207 ;
F_131 ( V_39 ) -> V_208 = V_178 . V_208 ;
if ( F_131 ( V_39 ) -> V_208 == 0 ) {
V_9 -> V_37 -> V_114 . V_193 ++ ;
F_100 ( V_39 ) ;
return - V_73 ;
}
F_131 ( V_39 ) -> V_198 |= V_209 ;
F_131 ( V_39 ) -> V_210 = 0 ;
}
if ( V_180 ) {
F_131 ( V_39 ) -> V_211 = V_170 ;
F_131 ( V_39 ) -> V_212 |= V_213 ;
}
F_143 ( V_39 ) ;
V_1 = F_28 ( V_39 ) ;
F_144 ( V_39 ) ;
V_9 -> V_37 -> V_114 . V_214 ++ ;
V_9 -> V_37 -> V_114 . V_215 += V_102 ;
F_21 ( V_9 , V_1 , V_30 ) ;
return V_172 ;
}
static T_9 F_145 ( struct V_216 * V_217 , const struct V_151 * V_171 ,
unsigned long V_26 , T_10 V_218 )
{
struct V_68 * V_68 = V_217 -> V_219 ;
struct V_8 * V_9 = F_73 ( V_68 ) ;
struct V_29 * V_30 = V_68 -> V_69 ;
T_9 V_220 ;
if ( ! V_9 )
return - V_221 ;
F_6 ( V_12 , V_9 , L_7 , V_26 ) ;
V_220 = F_132 ( V_9 , V_30 , NULL , V_171 , F_124 ( V_171 , V_26 ) ,
V_26 , V_68 -> V_222 & V_223 ) ;
F_74 ( V_9 ) ;
return V_220 ;
}
static T_9 F_146 ( struct V_8 * V_9 ,
struct V_29 * V_30 ,
struct V_38 * V_39 ,
const struct V_151 * V_171 , int V_102 )
{
struct V_173 V_174 = { 0 , V_39 -> V_197 } ;
T_9 V_224 = 0 ;
if ( ! ( V_9 -> V_58 & V_181 ) ) {
if ( ( V_102 -= sizeof( V_174 ) ) < 0 )
return - V_73 ;
if ( V_102 < V_39 -> V_102 ) {
V_174 . V_58 |= V_225 ;
}
if ( F_147 ( V_171 , ( void * ) & V_174 , 0 , sizeof( V_174 ) ) )
return - V_91 ;
V_224 += sizeof( V_174 ) ;
}
if ( V_9 -> V_58 & V_182 ) {
struct V_177 V_178 = { 0 } ;
if ( ( V_102 -= V_9 -> V_183 ) < 0 )
return - V_73 ;
if ( F_148 ( V_39 ) ) {
struct V_226 * V_227 = F_131 ( V_39 ) ;
V_178 . V_187 = F_125 ( V_39 ) ;
V_178 . V_208 = V_227 -> V_208 ;
if ( V_227 -> V_198 & V_202 )
V_178 . V_198 = V_201 ;
else if ( V_227 -> V_198 & V_204 )
V_178 . V_198 = V_203 ;
else if ( V_227 -> V_198 & V_206 )
V_178 . V_198 = V_205 ;
else {
F_149 ( L_8
L_9 ,
V_227 -> V_198 , V_178 . V_208 ,
V_178 . V_187 ) ;
F_150 ( V_228 , L_10 ,
V_229 ,
16 , 1 , V_39 -> V_4 ,
F_151 ( ( int ) V_178 . V_187 , 64 ) , true ) ;
F_152 ( 1 ) ;
return - V_73 ;
}
if ( V_227 -> V_198 & V_207 )
V_178 . V_198 |= V_200 ;
} else
V_178 . V_198 = V_199 ;
if ( V_39 -> V_230 == V_231 ) {
V_178 . V_58 = V_184 ;
V_178 . V_185 = F_153 ( V_39 ) ;
V_178 . V_186 = V_39 -> V_186 ;
} else if ( V_39 -> V_230 == V_232 ) {
V_178 . V_58 = V_233 ;
}
if ( F_31 ( F_147 ( V_171 , ( void * ) & V_178 , V_224 ,
sizeof( V_178 ) ) ) )
return - V_91 ;
V_224 += V_9 -> V_183 ;
}
V_102 = F_126 ( int , V_39 -> V_102 , V_102 ) ;
F_154 ( V_39 , 0 , V_171 , V_224 , V_102 ) ;
V_224 += V_39 -> V_102 ;
V_9 -> V_37 -> V_114 . V_234 ++ ;
V_9 -> V_37 -> V_114 . V_235 += V_102 ;
return V_224 ;
}
static T_9 F_155 ( struct V_8 * V_9 , struct V_29 * V_30 ,
struct V_216 * V_217 , const struct V_151 * V_171 ,
T_9 V_102 , int V_148 )
{
F_156 ( V_66 , V_236 ) ;
struct V_38 * V_39 ;
T_9 V_237 = 0 ;
F_6 ( V_12 , V_9 , L_11 ) ;
if ( F_31 ( ! V_148 ) )
F_157 ( & V_30 -> V_65 . V_66 , & V_66 ) ;
while ( V_102 ) {
V_236 -> V_238 = V_239 ;
if ( ! ( V_39 = F_158 ( & V_30 -> V_63 . V_56 -> V_57 ) ) ) {
if ( V_148 ) {
V_237 = - V_191 ;
break;
}
if ( F_159 ( V_236 ) ) {
V_237 = - V_240 ;
break;
}
if ( V_9 -> V_37 -> V_60 != V_61 ) {
V_237 = - V_241 ;
break;
}
F_160 () ;
continue;
}
V_237 = F_146 ( V_9 , V_30 , V_39 , V_171 , V_102 ) ;
F_100 ( V_39 ) ;
break;
}
V_236 -> V_238 = V_242 ;
if ( F_31 ( ! V_148 ) )
F_161 ( & V_30 -> V_65 . V_66 , & V_66 ) ;
return V_237 ;
}
static T_9 F_162 ( struct V_216 * V_217 , const struct V_151 * V_171 ,
unsigned long V_26 , T_10 V_218 )
{
struct V_68 * V_68 = V_217 -> V_219 ;
struct V_29 * V_30 = V_68 -> V_69 ;
struct V_8 * V_9 = F_70 ( V_30 ) ;
T_9 V_102 , V_237 ;
if ( ! V_9 )
return - V_221 ;
V_102 = F_124 ( V_171 , V_26 ) ;
if ( V_102 < 0 ) {
V_237 = - V_73 ;
goto V_72;
}
V_237 = F_155 ( V_9 , V_30 , V_217 , V_171 , V_102 ,
V_68 -> V_222 & V_223 ) ;
V_237 = F_126 ( T_9 , V_237 , V_102 ) ;
V_72:
F_74 ( V_9 ) ;
return V_237 ;
}
static void F_163 ( struct V_36 * V_37 )
{
struct V_8 * V_9 = F_27 ( V_37 ) ;
F_49 ( ! ( F_164 ( & V_9 -> V_50 ) ) ) ;
F_108 ( V_9 ) ;
F_165 ( V_9 -> V_71 ) ;
F_166 ( V_37 ) ;
}
static void F_167 ( struct V_36 * V_37 )
{
struct V_8 * V_9 = F_27 ( V_37 ) ;
V_9 -> V_44 = V_243 ;
V_9 -> V_46 = V_244 ;
V_37 -> V_245 = & V_246 ;
V_37 -> V_247 = F_163 ;
}
static int F_168 ( struct V_248 * V_249 [] , struct V_248 * V_22 [] )
{
return - V_73 ;
}
static void F_169 ( struct V_140 * V_56 )
{
struct V_29 * V_30 ;
T_11 * V_250 ;
if ( ! F_116 ( V_56 ) )
return;
if ( ! F_170 ( V_142 , & V_56 -> V_143 -> V_58 ) )
return;
V_250 = F_171 ( V_56 ) ;
if ( V_250 && F_172 ( V_250 ) )
F_173 ( V_250 , V_144 |
V_145 | V_251 ) ;
V_30 = F_174 ( V_56 , struct V_29 , V_56 ) ;
F_97 ( & V_30 -> V_107 , V_108 , V_252 ) ;
}
static int F_175 ( struct V_216 * V_217 , struct V_63 * V_140 ,
struct V_253 * V_254 , T_8 V_172 )
{
int V_237 ;
struct V_29 * V_30 = F_174 ( V_140 , struct V_29 , V_63 ) ;
struct V_8 * V_9 = F_70 ( V_30 ) ;
if ( ! V_9 )
return - V_221 ;
V_237 = F_132 ( V_9 , V_30 , V_254 -> V_170 , V_254 -> V_255 , V_172 ,
V_254 -> V_256 , V_254 -> V_257 & V_258 ) ;
F_74 ( V_9 ) ;
return V_237 ;
}
static int F_176 ( struct V_216 * V_217 , struct V_63 * V_140 ,
struct V_253 * V_254 , T_8 V_172 ,
int V_58 )
{
struct V_29 * V_30 = F_174 ( V_140 , struct V_29 , V_63 ) ;
struct V_8 * V_9 = F_70 ( V_30 ) ;
int V_237 ;
if ( ! V_9 )
return - V_221 ;
if ( V_58 & ~ ( V_258 | V_259 ) )
return - V_73 ;
V_237 = F_155 ( V_9 , V_30 , V_217 , V_254 -> V_255 , V_172 ,
V_58 & V_258 ) ;
if ( V_237 > V_172 ) {
V_254 -> V_257 |= V_259 ;
V_237 = V_58 & V_259 ? V_237 : V_172 ;
}
F_74 ( V_9 ) ;
return V_237 ;
}
static int F_177 ( struct V_63 * V_140 )
{
if ( V_140 -> V_56 )
F_51 ( V_140 -> V_56 ) ;
return 0 ;
}
static int F_178 ( struct V_8 * V_9 )
{
int V_58 = 0 ;
if ( V_9 -> V_58 & V_126 )
V_58 |= V_260 ;
else
V_58 |= V_261 ;
if ( V_9 -> V_58 & V_181 )
V_58 |= V_262 ;
if ( V_9 -> V_58 & V_263 )
V_58 |= V_264 ;
if ( V_9 -> V_58 & V_182 )
V_58 |= V_265 ;
if ( V_9 -> V_58 & V_75 )
V_58 |= V_266 ;
return V_58 ;
}
static T_9 F_179 ( struct V_267 * V_37 , struct V_268 * V_269 ,
char * V_270 )
{
struct V_8 * V_9 = F_27 ( F_180 ( V_37 ) ) ;
return sprintf ( V_270 , L_12 , F_178 ( V_9 ) ) ;
}
static T_9 F_181 ( struct V_267 * V_37 , struct V_268 * V_269 ,
char * V_270 )
{
struct V_8 * V_9 = F_27 ( F_180 ( V_37 ) ) ;
return F_35 ( V_9 -> V_44 ) ?
sprintf ( V_270 , L_13 ,
F_182 ( F_183 () , V_9 -> V_44 ) ) :
sprintf ( V_270 , L_14 ) ;
}
static T_9 F_184 ( struct V_267 * V_37 , struct V_268 * V_269 ,
char * V_270 )
{
struct V_8 * V_9 = F_27 ( F_180 ( V_37 ) ) ;
return F_37 ( V_9 -> V_46 ) ?
sprintf ( V_270 , L_13 ,
F_185 ( F_183 () , V_9 -> V_46 ) ) :
sprintf ( V_270 , L_14 ) ;
}
static int F_186 ( struct V_43 * V_43 , struct V_68 * V_68 , struct V_271 * V_272 )
{
struct V_8 * V_9 ;
struct V_29 * V_30 = V_68 -> V_69 ;
struct V_36 * V_37 ;
int V_70 ;
if ( V_30 -> V_33 )
return - V_73 ;
V_37 = F_187 ( V_43 , V_272 -> V_273 ) ;
if ( V_37 ) {
if ( V_272 -> V_274 & V_275 )
return - V_74 ;
if ( ( V_272 -> V_274 & V_260 ) && V_37 -> V_127 == & V_128 )
V_9 = F_27 ( V_37 ) ;
else if ( ( V_272 -> V_274 & V_261 ) && V_37 -> V_127 == & V_136 )
V_9 = F_27 ( V_37 ) ;
else
return - V_73 ;
if ( F_32 ( V_9 ) )
return - V_276 ;
V_70 = F_188 ( V_9 -> V_71 ) ;
if ( V_70 < 0 )
return V_70 ;
V_70 = F_66 ( V_9 , V_68 ) ;
if ( V_70 < 0 )
return V_70 ;
if ( V_9 -> V_58 & V_75 &&
( V_9 -> V_32 + V_9 -> V_51 > 1 ) )
return V_70 ;
}
else {
char * V_277 ;
unsigned long V_58 = 0 ;
int V_278 = V_272 -> V_274 & V_266 ?
V_77 : 1 ;
if ( ! F_39 ( V_43 -> V_47 , V_48 ) )
return - V_276 ;
V_70 = F_189 () ;
if ( V_70 < 0 )
return V_70 ;
if ( V_272 -> V_274 & V_260 ) {
V_58 |= V_126 ;
V_277 = L_15 ;
} else if ( V_272 -> V_274 & V_261 ) {
V_58 |= V_135 ;
V_277 = L_16 ;
} else
return - V_73 ;
if ( * V_272 -> V_273 )
V_277 = V_272 -> V_273 ;
V_37 = F_190 ( sizeof( struct V_8 ) , V_277 ,
F_167 , V_278 , V_278 ) ;
if ( ! V_37 )
return - V_93 ;
F_191 ( V_37 , V_43 ) ;
V_37 -> V_279 = & V_280 ;
V_9 = F_27 ( V_37 ) ;
V_9 -> V_37 = V_37 ;
V_9 -> V_58 = V_58 ;
V_9 -> V_103 . V_26 = 0 ;
V_9 -> V_183 = sizeof( struct V_177 ) ;
V_9 -> V_78 = false ;
V_9 -> V_281 = V_30 -> V_63 . V_56 -> V_282 ;
F_192 ( & V_9 -> V_19 ) ;
V_70 = F_193 ( & V_9 -> V_71 ) ;
if ( V_70 < 0 )
goto V_283;
F_110 ( V_37 ) ;
V_70 = F_105 ( V_9 ) ;
if ( V_70 < 0 )
goto V_283;
V_37 -> V_284 = V_285 | V_286 |
V_123 ;
V_37 -> V_121 = V_37 -> V_284 ;
F_194 ( & V_9 -> V_50 ) ;
V_70 = F_66 ( V_9 , V_68 ) ;
if ( V_70 < 0 )
goto V_283;
V_70 = F_195 ( V_9 -> V_37 ) ;
if ( V_70 < 0 )
goto V_283;
if ( F_196 ( & V_9 -> V_37 -> V_37 , & V_287 ) ||
F_196 ( & V_9 -> V_37 -> V_37 , & V_288 ) ||
F_196 ( & V_9 -> V_37 -> V_37 , & V_289 ) )
F_149 ( L_17 ) ;
}
F_197 ( V_9 -> V_37 ) ;
F_6 ( V_12 , V_9 , L_18 ) ;
if ( V_272 -> V_274 & V_262 )
V_9 -> V_58 |= V_181 ;
else
V_9 -> V_58 &= ~ V_181 ;
if ( V_272 -> V_274 & V_264 )
V_9 -> V_58 |= V_263 ;
else
V_9 -> V_58 &= ~ V_263 ;
if ( V_272 -> V_274 & V_265 )
V_9 -> V_58 |= V_182 ;
else
V_9 -> V_58 &= ~ V_182 ;
if ( V_272 -> V_274 & V_266 )
V_9 -> V_58 |= V_75 ;
else
V_9 -> V_58 &= ~ V_75 ;
if ( F_198 ( V_9 -> V_37 ) )
F_199 ( V_9 -> V_37 ) ;
strcpy ( V_272 -> V_273 , V_9 -> V_37 -> V_277 ) ;
return 0 ;
V_283:
F_166 ( V_37 ) ;
return V_70 ;
}
static void F_200 ( struct V_43 * V_43 , struct V_8 * V_9 ,
struct V_271 * V_272 )
{
F_6 ( V_12 , V_9 , L_19 ) ;
strcpy ( V_272 -> V_273 , V_9 -> V_37 -> V_277 ) ;
V_272 -> V_274 = F_178 ( V_9 ) ;
}
static int F_201 ( struct V_8 * V_9 , unsigned long V_85 )
{
T_6 V_121 = 0 ;
if ( V_85 & V_290 ) {
V_121 |= V_291 ;
V_85 &= ~ V_290 ;
if ( V_85 & ( V_292 | V_293 ) ) {
if ( V_85 & V_294 ) {
V_121 |= V_295 ;
V_85 &= ~ V_294 ;
}
if ( V_85 & V_292 )
V_121 |= V_296 ;
if ( V_85 & V_293 )
V_121 |= V_297 ;
V_85 &= ~ ( V_292 | V_293 ) ;
}
if ( V_85 & V_298 ) {
V_121 |= V_299 ;
V_85 &= ~ V_298 ;
}
}
if ( V_85 )
return - V_73 ;
V_9 -> V_122 = V_121 ;
F_202 ( V_9 -> V_37 ) ;
return 0 ;
}
static void F_203 ( struct V_8 * V_9 , int V_7 )
{
int V_18 ;
struct V_29 * V_30 ;
for ( V_18 = 0 ; V_18 < V_7 ; V_18 ++ ) {
V_30 = F_48 ( V_9 -> V_55 [ V_18 ] ) ;
F_204 ( V_30 -> V_63 . V_56 ) ;
}
V_9 -> V_78 = false ;
}
static int F_205 ( struct V_8 * V_9 )
{
int V_18 , V_237 = 0 ;
struct V_29 * V_30 ;
for ( V_18 = 0 ; V_18 < V_9 -> V_32 ; V_18 ++ ) {
V_30 = F_48 ( V_9 -> V_55 [ V_18 ] ) ;
V_237 = F_68 ( & V_9 -> V_79 , V_30 -> V_63 . V_56 ) ;
if ( V_237 ) {
F_203 ( V_9 , V_18 ) ;
return V_237 ;
}
}
V_9 -> V_78 = true ;
return V_237 ;
}
static void F_206 ( struct V_8 * V_9 )
{
struct V_29 * V_30 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_9 -> V_32 ; V_18 ++ ) {
V_30 = F_48 ( V_9 -> V_55 [ V_18 ] ) ;
V_30 -> V_63 . V_56 -> V_282 = V_9 -> V_281 ;
}
}
static int F_207 ( struct V_68 * V_68 , struct V_271 * V_272 )
{
struct V_29 * V_30 = V_68 -> V_69 ;
struct V_8 * V_9 ;
int V_237 = 0 ;
F_59 () ;
if ( V_272 -> V_274 & V_300 ) {
V_9 = V_30 -> V_33 ;
if ( ! V_9 ) {
V_237 = - V_73 ;
goto V_34;
}
V_237 = F_208 ( V_9 -> V_71 ) ;
if ( V_237 < 0 )
goto V_34;
V_237 = F_66 ( V_9 , V_68 ) ;
} else if ( V_272 -> V_274 & V_301 ) {
V_9 = F_48 ( V_30 -> V_9 ) ;
if ( ! V_9 || ! ( V_9 -> V_58 & V_75 ) || V_30 -> V_33 )
V_237 = - V_73 ;
else
F_47 ( V_30 , false ) ;
} else
V_237 = - V_73 ;
V_34:
F_60 () ;
return V_237 ;
}
static long F_209 ( struct V_68 * V_68 , unsigned int V_302 ,
unsigned long V_85 , int V_303 )
{
struct V_29 * V_30 = V_68 -> V_69 ;
struct V_8 * V_9 ;
void T_4 * V_304 = ( void T_4 * ) V_85 ;
struct V_271 V_272 ;
T_12 V_44 ;
T_13 V_46 ;
int V_281 ;
int V_183 ;
int V_237 ;
if ( V_302 == V_305 || V_302 == V_306 || F_210 ( V_302 ) == 0x89 ) {
if ( F_80 ( & V_272 , V_304 , V_303 ) )
return - V_91 ;
} else {
memset ( & V_272 , 0 , sizeof( V_272 ) ) ;
}
if ( V_302 == V_307 ) {
return F_211 ( V_260 | V_261 | V_262 | V_264 |
V_265 | V_266 ,
( unsigned int T_4 * ) V_304 ) ;
} else if ( V_302 == V_306 )
return F_207 ( V_68 , & V_272 ) ;
V_237 = 0 ;
F_59 () ;
V_9 = F_70 ( V_30 ) ;
if ( V_302 == V_305 && ! V_9 ) {
V_272 . V_273 [ V_308 - 1 ] = '\0' ;
V_237 = F_186 ( V_30 -> V_43 , V_68 , & V_272 ) ;
if ( V_237 )
goto V_34;
if ( F_212 ( V_304 , & V_272 , V_303 ) )
V_237 = - V_91 ;
goto V_34;
}
V_237 = - V_221 ;
if ( ! V_9 )
goto V_34;
F_6 ( V_12 , V_9 , L_20 , V_302 ) ;
V_237 = 0 ;
switch ( V_302 ) {
case V_309 :
F_200 ( V_236 -> V_310 -> V_311 , V_9 , & V_272 ) ;
if ( F_212 ( V_304 , & V_272 , V_303 ) )
V_237 = - V_91 ;
break;
case V_312 :
F_6 ( V_12 , V_9 , L_21 ,
V_85 ? L_22 : L_23 ) ;
break;
case V_313 :
if ( V_85 && ! ( V_9 -> V_58 & V_59 ) ) {
V_9 -> V_58 |= V_59 ;
F_213 ( V_67 ) ;
}
if ( ! V_85 && ( V_9 -> V_58 & V_59 ) ) {
V_9 -> V_58 &= ~ V_59 ;
F_65 ( V_67 ) ;
}
F_6 ( V_12 , V_9 , L_24 ,
V_85 ? L_23 : L_22 ) ;
break;
case V_314 :
V_44 = F_214 ( F_183 () , V_85 ) ;
if ( ! F_35 ( V_44 ) ) {
V_237 = - V_73 ;
break;
}
V_9 -> V_44 = V_44 ;
F_6 ( V_12 , V_9 , L_25 ,
F_215 ( & V_315 , V_9 -> V_44 ) ) ;
break;
case V_316 :
V_46 = F_216 ( F_183 () , V_85 ) ;
if ( ! F_37 ( V_46 ) ) {
V_237 = - V_73 ;
break;
}
V_9 -> V_46 = V_46 ;
F_6 ( V_12 , V_9 , L_26 ,
F_217 ( & V_315 , V_9 -> V_46 ) ) ;
break;
case V_317 :
if ( V_9 -> V_37 -> V_58 & V_318 ) {
F_6 ( V_12 , V_9 ,
L_27 ) ;
V_237 = - V_74 ;
} else {
V_9 -> V_37 -> type = ( int ) V_85 ;
F_6 ( V_12 , V_9 , L_28 ,
V_9 -> V_37 -> type ) ;
V_237 = 0 ;
}
break;
#ifdef F_218
case V_319 :
V_9 -> V_320 = V_85 ;
break;
#endif
case V_321 :
V_237 = F_201 ( V_9 , V_85 ) ;
break;
case V_322 :
V_237 = - V_73 ;
if ( ( V_9 -> V_58 & V_125 ) != V_135 )
break;
V_237 = F_79 ( & V_9 -> V_103 , ( void T_4 * ) V_85 ) ;
break;
case V_323 :
memcpy ( V_272 . V_324 . V_325 , V_9 -> V_37 -> V_326 , V_82 ) ;
V_272 . V_324 . V_327 = V_9 -> V_37 -> type ;
if ( F_212 ( V_304 , & V_272 , V_303 ) )
V_237 = - V_91 ;
break;
case V_328 :
F_6 ( V_329 , V_9 , L_29 ,
V_272 . V_324 . V_325 ) ;
V_237 = F_219 ( V_9 -> V_37 , & V_272 . V_324 ) ;
break;
case V_330 :
V_281 = V_30 -> V_63 . V_56 -> V_282 ;
if ( F_212 ( V_304 , & V_281 , sizeof( V_281 ) ) )
V_237 = - V_91 ;
break;
case V_331 :
if ( F_80 ( & V_281 , V_304 , sizeof( V_281 ) ) ) {
V_237 = - V_91 ;
break;
}
V_9 -> V_281 = V_281 ;
F_206 ( V_9 ) ;
break;
case V_332 :
V_183 = V_9 -> V_183 ;
if ( F_212 ( V_304 , & V_183 , sizeof( V_183 ) ) )
V_237 = - V_91 ;
break;
case V_333 :
if ( F_80 ( & V_183 , V_304 , sizeof( V_183 ) ) ) {
V_237 = - V_91 ;
break;
}
if ( V_183 < ( int ) sizeof( struct V_177 ) ) {
V_237 = - V_73 ;
break;
}
V_9 -> V_183 = V_183 ;
break;
case V_334 :
V_237 = - V_73 ;
if ( ( V_9 -> V_58 & V_125 ) != V_135 )
break;
V_237 = - V_91 ;
if ( F_80 ( & V_9 -> V_79 , V_304 , sizeof( V_9 -> V_79 ) ) )
break;
V_237 = F_205 ( V_9 ) ;
break;
case V_335 :
V_237 = - V_73 ;
if ( ( V_9 -> V_58 & V_125 ) != V_135 )
break;
V_237 = 0 ;
F_203 ( V_9 , V_9 -> V_32 ) ;
break;
default:
V_237 = - V_73 ;
break;
}
V_34:
F_60 () ;
if ( V_9 )
F_74 ( V_9 ) ;
return V_237 ;
}
static long F_220 ( struct V_68 * V_68 ,
unsigned int V_302 , unsigned long V_85 )
{
return F_209 ( V_68 , V_302 , V_85 , sizeof ( struct V_271 ) ) ;
}
static long F_221 ( struct V_68 * V_68 ,
unsigned int V_302 , unsigned long V_85 )
{
switch ( V_302 ) {
case V_305 :
case V_309 :
case V_322 :
case V_330 :
case V_331 :
case V_323 :
case V_328 :
V_85 = ( unsigned long ) F_222 ( V_85 ) ;
break;
default:
V_85 = ( V_336 ) V_85 ;
break;
}
return F_209 ( V_68 , V_302 , V_85 , sizeof( struct V_337 ) ) ;
}
static int F_223 ( int V_338 , struct V_68 * V_68 , int V_339 )
{
struct V_29 * V_30 = V_68 -> V_69 ;
int V_237 ;
if ( ( V_237 = F_224 ( V_338 , V_68 , V_339 , & V_30 -> V_107 ) ) < 0 )
goto V_72;
if ( V_339 ) {
V_237 = F_225 ( V_68 , F_226 ( V_236 ) , V_340 , 0 ) ;
if ( V_237 )
goto V_72;
V_30 -> V_58 |= V_106 ;
} else
V_30 -> V_58 &= ~ V_106 ;
V_237 = 0 ;
V_72:
return V_237 ;
}
static int F_227 ( struct V_341 * V_341 , struct V_68 * V_68 )
{
struct V_29 * V_30 ;
F_228 ( V_12 , L_30 ) ;
V_30 = (struct V_29 * ) F_229 ( & V_342 , V_343 , V_92 ,
& V_344 ) ;
if ( ! V_30 )
return - V_93 ;
F_50 ( V_30 -> V_9 , NULL ) ;
V_30 -> V_43 = F_230 ( V_236 -> V_310 -> V_311 ) ;
V_30 -> V_58 = 0 ;
F_50 ( V_30 -> V_63 . V_65 , & V_30 -> V_65 ) ;
F_231 ( & V_30 -> V_65 . V_66 ) ;
V_30 -> V_63 . V_68 = V_68 ;
V_30 -> V_63 . V_345 = & V_346 ;
F_232 ( & V_30 -> V_63 , & V_30 -> V_56 ) ;
F_233 ( & V_30 -> V_56 , V_30 -> V_43 ) ;
V_30 -> V_56 . V_347 = F_169 ;
V_30 -> V_56 . V_282 = V_348 ;
V_68 -> V_69 = V_30 ;
F_234 ( V_62 , & V_30 -> V_63 . V_58 ) ;
F_194 ( & V_30 -> V_49 ) ;
return 0 ;
}
static int F_235 ( struct V_341 * V_341 , struct V_68 * V_68 )
{
struct V_29 * V_30 = V_68 -> V_69 ;
struct V_43 * V_43 = V_30 -> V_43 ;
F_58 ( V_30 , true ) ;
F_236 ( V_43 ) ;
return 0 ;
}
static int F_237 ( struct V_36 * V_37 , struct V_349 * V_302 )
{
V_302 -> V_350 = 0 ;
V_302 -> V_351 = 0 ;
F_238 ( V_302 , V_352 ) ;
V_302 -> V_353 = V_354 ;
V_302 -> V_355 = V_356 ;
V_302 -> V_357 = 0 ;
V_302 -> V_358 = V_359 ;
V_302 -> V_360 = V_361 ;
V_302 -> V_362 = 0 ;
V_302 -> V_363 = 0 ;
return 0 ;
}
static void F_239 ( struct V_36 * V_37 , struct V_364 * V_365 )
{
struct V_8 * V_9 = F_27 ( V_37 ) ;
F_240 ( V_365 -> V_366 , V_367 , sizeof( V_365 -> V_366 ) ) ;
F_240 ( V_365 -> V_368 , V_369 , sizeof( V_365 -> V_368 ) ) ;
switch ( V_9 -> V_58 & V_125 ) {
case V_126 :
F_240 ( V_365 -> V_370 , L_31 , sizeof( V_365 -> V_370 ) ) ;
break;
case V_135 :
F_240 ( V_365 -> V_370 , L_32 , sizeof( V_365 -> V_370 ) ) ;
break;
}
}
static T_1 F_241 ( struct V_36 * V_37 )
{
#ifdef F_218
struct V_8 * V_9 = F_27 ( V_37 ) ;
return V_9 -> V_320 ;
#else
return - V_371 ;
#endif
}
static void F_242 ( struct V_36 * V_37 , T_1 V_372 )
{
#ifdef F_218
struct V_8 * V_9 = F_27 ( V_37 ) ;
V_9 -> V_320 = V_372 ;
#endif
}
static int T_14 F_243 ( void )
{
int V_237 = 0 ;
F_244 ( L_33 , V_373 , V_369 ) ;
F_244 ( L_34 , V_374 ) ;
V_237 = F_245 ( & V_280 ) ;
if ( V_237 ) {
F_149 ( L_35 ) ;
goto V_375;
}
V_237 = F_246 ( & V_376 ) ;
if ( V_237 ) {
F_149 ( L_36 , V_377 ) ;
goto V_378;
}
return 0 ;
V_378:
F_247 ( & V_280 ) ;
V_375:
return V_237 ;
}
static void F_248 ( void )
{
F_249 ( & V_376 ) ;
F_247 ( & V_280 ) ;
}
struct V_63 * F_250 ( struct V_68 * V_68 )
{
struct V_29 * V_30 ;
if ( V_68 -> V_379 != & V_380 )
return F_120 ( - V_73 ) ;
V_30 = V_68 -> V_69 ;
if ( ! V_30 )
return F_120 ( - V_221 ) ;
return & V_30 -> V_63 ;
}
