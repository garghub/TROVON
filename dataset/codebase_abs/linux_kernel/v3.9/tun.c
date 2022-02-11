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
V_31 = V_7 -> V_31 ;
V_39 = F_28 ( V_38 ) ;
if ( V_39 ) {
V_5 = F_2 ( & V_7 -> V_30 [ F_1 ( V_39 ) ] , V_39 ) ;
if ( V_5 )
V_39 = V_5 -> V_8 ;
else
V_39 = ( ( V_40 ) V_39 * V_31 ) >> 32 ;
} else if ( F_23 ( F_29 ( V_38 ) ) ) {
V_39 = F_30 ( V_38 ) ;
while ( F_31 ( V_39 >= V_31 ) )
V_39 -= V_31 ;
}
F_25 () ;
return V_39 ;
}
static inline bool F_32 ( struct V_6 * V_7 )
{
const struct V_41 * V_41 = F_33 () ;
struct V_42 * V_42 = F_34 ( V_7 -> V_36 ) ;
return ( ( F_35 ( V_7 -> V_43 ) && ! F_36 ( V_41 -> V_44 , V_7 -> V_43 ) ) ||
( F_37 ( V_7 -> V_45 ) && ! F_38 ( V_7 -> V_45 ) ) ) &&
! F_39 ( V_42 -> V_46 , V_47 ) ;
}
static void F_40 ( struct V_6 * V_7 )
{
F_41 ( V_7 -> V_36 , V_7 -> V_31 ) ;
F_42 ( V_7 -> V_36 , V_7 -> V_31 ) ;
}
static void F_43 ( struct V_6 * V_7 , struct V_28 * V_29 )
{
V_29 -> V_32 = V_7 ;
F_44 ( & V_29 -> V_48 , & V_7 -> V_49 ) ;
++ V_7 -> V_50 ;
}
static struct V_6 * F_45 ( struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_32 ;
V_29 -> V_32 = NULL ;
F_46 ( & V_29 -> V_48 ) ;
-- V_7 -> V_50 ;
return V_7 ;
}
static void F_47 ( struct V_28 * V_29 , bool V_51 )
{
struct V_28 * V_52 ;
struct V_6 * V_7 ;
struct V_35 * V_36 ;
V_7 = F_48 ( V_29 -> V_7 ) ;
if ( V_7 && ! V_29 -> V_32 ) {
T_2 V_53 = V_29 -> V_8 ;
F_49 ( V_53 >= V_7 -> V_31 ) ;
V_36 = V_7 -> V_36 ;
F_50 ( V_7 -> V_54 [ V_53 ] ,
V_7 -> V_54 [ V_7 -> V_31 - 1 ] ) ;
V_52 = F_48 ( V_7 -> V_54 [ V_53 ] ) ;
V_52 -> V_8 = V_53 ;
-- V_7 -> V_31 ;
if ( V_51 ) {
F_50 ( V_29 -> V_7 , NULL ) ;
F_51 ( & V_29 -> V_55 ) ;
} else
F_43 ( V_7 , V_29 ) ;
F_52 () ;
F_15 ( V_7 , V_7 -> V_31 + 1 ) ;
F_53 ( & V_29 -> V_55 . V_56 ) ;
F_40 ( V_7 ) ;
} else if ( V_29 -> V_32 && V_51 ) {
V_7 = F_45 ( V_29 ) ;
F_51 ( & V_29 -> V_55 ) ;
}
if ( V_51 ) {
if ( V_7 && V_7 -> V_31 == 0 && V_7 -> V_50 == 0 ) {
F_54 ( V_7 -> V_36 ) ;
if ( ! ( V_7 -> V_57 & V_58 ) &&
V_7 -> V_36 -> V_59 == V_60 )
F_55 ( V_7 -> V_36 ) ;
}
F_49 ( ! F_56 ( V_61 ,
& V_29 -> V_62 . V_57 ) ) ;
F_57 ( & V_29 -> V_55 ) ;
}
}
static void F_58 ( struct V_28 * V_29 , bool V_51 )
{
F_59 () ;
F_47 ( V_29 , V_51 ) ;
F_60 () ;
}
static void F_61 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_27 ( V_36 ) ;
struct V_28 * V_29 , * V_63 ;
int V_16 , V_20 = V_7 -> V_31 ;
for ( V_16 = 0 ; V_16 < V_20 ; V_16 ++ ) {
V_29 = F_48 ( V_7 -> V_54 [ V_16 ] ) ;
F_49 ( ! V_29 ) ;
F_62 ( & V_29 -> V_64 . V_65 ) ;
F_50 ( V_29 -> V_7 , NULL ) ;
-- V_7 -> V_31 ;
}
F_63 (tfile, &tun->disabled, next) {
F_62 ( & V_29 -> V_64 . V_65 ) ;
F_50 ( V_29 -> V_7 , NULL ) ;
}
F_49 ( V_7 -> V_31 != 0 ) ;
F_52 () ;
for ( V_16 = 0 ; V_16 < V_20 ; V_16 ++ ) {
V_29 = F_48 ( V_7 -> V_54 [ V_16 ] ) ;
F_53 ( & V_29 -> V_55 . V_56 ) ;
F_51 ( & V_29 -> V_55 ) ;
}
F_64 (tfile, tmp, &tun->disabled, next) {
F_45 ( V_29 ) ;
F_53 ( & V_29 -> V_55 . V_56 ) ;
F_51 ( & V_29 -> V_55 ) ;
}
F_49 ( V_7 -> V_50 != 0 ) ;
if ( V_7 -> V_57 & V_58 )
F_65 ( V_66 ) ;
}
static int F_66 ( struct V_6 * V_7 , struct V_67 * V_67 )
{
struct V_28 * V_29 = V_67 -> V_68 ;
int V_69 ;
V_69 = F_67 ( V_29 -> V_62 . V_55 , V_7 -> V_70 ) ;
if ( V_69 < 0 )
goto V_71;
V_69 = - V_72 ;
if ( F_48 ( V_29 -> V_7 ) && ! V_29 -> V_32 )
goto V_71;
V_69 = - V_73 ;
if ( ! ( V_7 -> V_57 & V_74 ) && V_7 -> V_31 == 1 )
goto V_71;
V_69 = - V_75 ;
if ( ! V_29 -> V_32 &&
V_7 -> V_31 + V_7 -> V_50 == V_76 )
goto V_71;
V_69 = 0 ;
if ( V_7 -> V_77 == true ) {
V_69 = F_68 ( & V_7 -> V_78 , V_29 -> V_62 . V_55 ) ;
if ( ! V_69 )
goto V_71;
}
V_29 -> V_8 = V_7 -> V_31 ;
F_50 ( V_29 -> V_7 , V_7 ) ;
F_50 ( V_7 -> V_54 [ V_7 -> V_31 ] , V_29 ) ;
V_7 -> V_31 ++ ;
if ( V_29 -> V_32 )
F_45 ( V_29 ) ;
else
F_69 ( & V_29 -> V_55 ) ;
F_40 ( V_7 ) ;
V_71:
return V_69 ;
}
static struct V_6 * F_70 ( struct V_28 * V_29 )
{
struct V_6 * V_7 ;
F_22 () ;
V_7 = F_71 ( V_29 -> V_7 ) ;
if ( V_7 )
F_72 ( V_7 -> V_36 ) ;
F_25 () ;
return V_7 ;
}
static struct V_6 * F_73 ( struct V_67 * V_67 )
{
return F_70 ( V_67 -> V_68 ) ;
}
static void F_74 ( struct V_6 * V_7 )
{
F_75 ( V_7 -> V_36 ) ;
}
static void F_76 ( T_1 * V_79 , const T_3 * V_80 )
{
int V_20 = F_77 ( V_81 , V_80 ) >> 26 ;
V_79 [ V_20 >> 5 ] |= ( 1 << ( V_20 & 31 ) ) ;
}
static unsigned int F_78 ( const T_1 * V_79 , const T_3 * V_80 )
{
int V_20 = F_77 ( V_81 , V_80 ) >> 26 ;
return V_79 [ V_20 >> 5 ] & ( 1 << ( V_20 & 31 ) ) ;
}
static int F_79 ( struct V_82 * V_83 , void T_4 * V_84 )
{
struct { T_3 V_85 [ V_81 ] ; } * V_80 ;
struct V_86 V_87 ;
int V_69 , V_88 , V_20 , V_89 ;
if ( F_80 ( & V_87 , V_84 , sizeof( V_87 ) ) )
return - V_90 ;
if ( ! V_87 . V_25 ) {
V_83 -> V_25 = 0 ;
return 0 ;
}
V_88 = V_81 * V_87 . V_25 ;
V_80 = F_5 ( V_88 , V_91 ) ;
if ( ! V_80 )
return - V_92 ;
if ( F_80 ( V_80 , V_84 + sizeof( V_87 ) , V_88 ) ) {
V_69 = - V_90 ;
goto V_93;
}
V_83 -> V_25 = 0 ;
F_81 () ;
for ( V_20 = 0 ; V_20 < V_87 . V_25 && V_20 < V_94 ; V_20 ++ )
memcpy ( V_83 -> V_80 [ V_20 ] , V_80 [ V_20 ] . V_85 , V_81 ) ;
V_89 = V_20 ;
memset ( V_83 -> V_79 , 0 , sizeof( V_83 -> V_79 ) ) ;
for (; V_20 < V_87 . V_25 ; V_20 ++ ) {
if ( ! F_82 ( V_80 [ V_20 ] . V_85 ) ) {
V_69 = 0 ;
goto V_93;
}
F_76 ( V_83 -> V_79 , V_80 [ V_20 ] . V_85 ) ;
}
if ( ( V_87 . V_57 & V_95 ) )
memset ( V_83 -> V_79 , ~ 0 , sizeof( V_83 -> V_79 ) ) ;
F_81 () ;
V_83 -> V_25 = V_89 ;
V_69 = V_89 ;
V_93:
F_83 ( V_80 ) ;
return V_69 ;
}
static int F_84 ( struct V_82 * V_83 , const struct V_37 * V_38 )
{
struct V_96 * V_97 = (struct V_96 * ) V_38 -> V_21 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_83 -> V_25 ; V_16 ++ )
if ( F_85 ( V_97 -> V_98 , V_83 -> V_80 [ V_16 ] ) )
return 1 ;
if ( F_82 ( V_97 -> V_98 ) )
return F_78 ( V_83 -> V_79 , V_97 -> V_98 ) ;
return 0 ;
}
static int F_86 ( struct V_82 * V_83 , const struct V_37 * V_38 )
{
if ( ! V_83 -> V_25 )
return 1 ;
return F_84 ( V_83 , V_38 ) ;
}
static void F_87 ( struct V_35 * V_36 )
{
F_61 ( V_36 ) ;
}
static int F_88 ( struct V_35 * V_36 )
{
F_89 ( V_36 ) ;
return 0 ;
}
static int F_90 ( struct V_35 * V_36 )
{
F_91 ( V_36 ) ;
return 0 ;
}
static T_5 F_92 ( struct V_37 * V_38 , struct V_35 * V_36 )
{
struct V_6 * V_7 = F_27 ( V_36 ) ;
int V_39 = V_38 -> V_99 ;
struct V_28 * V_29 ;
F_22 () ;
V_29 = F_71 ( V_7 -> V_54 [ V_39 ] ) ;
if ( V_39 >= V_7 -> V_31 )
goto V_100;
F_6 ( V_10 , V_7 , L_4 , V_38 -> V_101 ) ;
F_49 ( ! V_29 ) ;
if ( ! F_86 ( & V_7 -> V_102 , V_38 ) )
goto V_100;
if ( V_29 -> V_62 . V_55 -> V_103 &&
V_103 ( V_29 -> V_62 . V_55 , V_38 ) )
goto V_100;
if ( F_93 ( & V_29 -> V_62 . V_55 -> V_56 )
>= V_36 -> V_104 / V_7 -> V_31 )
goto V_100;
if ( F_31 ( F_94 ( V_38 , V_9 ) ) )
goto V_100;
F_95 ( V_38 ) ;
F_96 ( V_38 ) ;
F_97 ( & V_29 -> V_62 . V_55 -> V_56 , V_38 ) ;
if ( V_29 -> V_57 & V_105 )
F_98 ( & V_29 -> V_106 , V_107 , V_108 ) ;
F_99 ( & V_29 -> V_64 . V_65 , V_109 |
V_110 | V_111 ) ;
F_25 () ;
return V_112 ;
V_100:
V_36 -> V_113 . V_114 ++ ;
F_100 ( V_38 ) ;
F_101 ( V_38 ) ;
F_25 () ;
return V_112 ;
}
static void F_102 ( struct V_35 * V_36 )
{
}
static int
F_103 ( struct V_35 * V_36 , int V_115 )
{
if ( V_115 < V_116 || V_115 + V_36 -> V_117 > V_118 )
return - V_72 ;
V_36 -> V_119 = V_115 ;
return 0 ;
}
static T_6 F_104 ( struct V_35 * V_36 ,
T_6 V_120 )
{
struct V_6 * V_7 = F_27 ( V_36 ) ;
return ( V_120 & V_7 -> V_121 ) | ( V_120 & ~ V_122 ) ;
}
static void F_105 ( struct V_35 * V_36 )
{
return;
}
static int F_106 ( struct V_6 * V_7 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_18 ; V_16 ++ )
F_107 ( & V_7 -> V_30 [ V_16 ] ) ;
V_7 -> V_23 = V_123 ;
F_108 ( & V_7 -> V_27 , F_16 , ( unsigned long ) V_7 ) ;
F_19 ( & V_7 -> V_27 ,
F_20 ( V_12 + V_7 -> V_23 ) ) ;
return 0 ;
}
static void F_109 ( struct V_6 * V_7 )
{
F_110 ( & V_7 -> V_27 ) ;
F_11 ( V_7 ) ;
}
static void F_111 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_27 ( V_36 ) ;
switch ( V_7 -> V_57 & V_124 ) {
case V_125 :
V_36 -> V_126 = & V_127 ;
V_36 -> V_117 = 0 ;
V_36 -> V_128 = 0 ;
V_36 -> V_119 = 1500 ;
V_36 -> type = V_129 ;
V_36 -> V_57 = V_130 | V_131 | V_132 ;
V_36 -> V_104 = V_133 ;
break;
case V_134 :
V_36 -> V_126 = & V_135 ;
F_112 ( V_36 ) ;
V_36 -> V_136 &= ~ V_137 ;
V_36 -> V_136 |= V_138 ;
F_113 ( V_36 ) ;
V_36 -> V_104 = V_133 ;
break;
}
}
static unsigned int F_114 ( struct V_67 * V_67 , T_7 * V_65 )
{
struct V_28 * V_29 = V_67 -> V_68 ;
struct V_6 * V_7 = F_70 ( V_29 ) ;
struct V_139 * V_55 ;
unsigned int V_79 = 0 ;
if ( ! V_7 )
return V_140 ;
V_55 = V_29 -> V_62 . V_55 ;
F_6 ( V_10 , V_7 , L_5 ) ;
F_115 ( V_67 , & V_29 -> V_64 . V_65 , V_65 ) ;
if ( ! F_116 ( & V_55 -> V_56 ) )
V_79 |= V_109 | V_110 ;
if ( F_117 ( V_55 ) ||
( ! F_118 ( V_141 , & V_55 -> V_142 -> V_57 ) &&
F_117 ( V_55 ) ) )
V_79 |= V_143 | V_144 ;
if ( V_7 -> V_36 -> V_59 != V_60 )
V_79 = V_140 ;
F_74 ( V_7 ) ;
return V_79 ;
}
static struct V_37 * F_119 ( struct V_28 * V_29 ,
T_8 V_145 , T_8 V_101 ,
T_8 V_146 , int V_147 )
{
struct V_139 * V_55 = V_29 -> V_62 . V_55 ;
struct V_37 * V_38 ;
int V_69 ;
if ( V_145 + V_101 < V_148 || ! V_146 )
V_146 = V_101 ;
V_38 = F_120 ( V_55 , V_145 + V_146 , V_101 - V_146 , V_147 ,
& V_69 ) ;
if ( ! V_38 )
return F_121 ( V_69 ) ;
F_122 ( V_38 , V_145 ) ;
F_123 ( V_38 , V_146 ) ;
V_38 -> V_149 = V_101 - V_146 ;
V_38 -> V_101 += V_101 - V_146 ;
return V_38 ;
}
static int F_124 ( struct V_37 * V_38 , const struct V_150 * V_151 ,
int V_152 , T_8 V_25 )
{
int V_101 = F_125 ( V_151 , V_25 ) - V_152 ;
int V_153 = F_126 ( V_38 ) ;
int V_154 , V_155 = 0 ;
int V_16 = 0 ;
while ( V_25 && ( V_152 >= V_151 -> V_156 ) ) {
V_152 -= V_151 -> V_156 ;
++ V_151 ;
-- V_25 ;
}
while ( V_25 && ( V_153 > 0 ) ) {
V_154 = F_127 (unsigned int, copy, from->iov_len - offset) ;
if ( F_80 ( V_38 -> V_21 + V_155 , V_151 -> V_157 + V_152 ,
V_154 ) )
return - V_90 ;
if ( V_153 > V_154 ) {
++ V_151 ;
-- V_25 ;
V_152 = 0 ;
} else
V_152 += V_154 ;
V_153 -= V_154 ;
V_155 += V_154 ;
}
if ( V_101 == V_155 )
return 0 ;
while ( V_25 -- ) {
struct V_158 * V_158 [ V_159 ] ;
int V_160 ;
unsigned long V_161 ;
unsigned long V_162 ;
V_101 = V_151 -> V_156 - V_152 ;
if ( ! V_101 ) {
V_152 = 0 ;
++ V_151 ;
continue;
}
V_161 = ( unsigned long ) V_151 -> V_157 + V_152 ;
V_154 = ( ( V_161 & ~ V_163 ) + V_101 + ~ V_163 ) >> V_164 ;
if ( V_16 + V_154 > V_159 )
return - V_165 ;
V_160 = F_128 ( V_161 , V_154 , 0 , & V_158 [ V_16 ] ) ;
if ( V_160 != V_154 ) {
for ( V_16 = 0 ; V_16 < V_160 ; V_16 ++ )
F_129 ( V_158 [ V_16 ] ) ;
return - V_90 ;
}
V_162 = V_154 * V_148 ;
V_38 -> V_149 += V_101 ;
V_38 -> V_101 += V_101 ;
V_38 -> V_162 += V_162 ;
F_130 ( V_162 , & V_38 -> V_55 -> V_166 ) ;
while ( V_101 ) {
int V_167 = V_161 & ~ V_163 ;
int V_154 = F_127 ( int , V_101 , V_148 - V_167 ) ;
F_131 ( V_38 , V_16 , V_158 [ V_16 ] , V_167 , V_154 ) ;
F_132 ( V_38 ) -> V_168 ++ ;
V_161 += V_154 ;
V_101 -= V_154 ;
V_16 ++ ;
}
V_152 = 0 ;
++ V_151 ;
}
return 0 ;
}
static T_9 F_133 ( struct V_6 * V_7 , struct V_28 * V_29 ,
void * V_169 , const struct V_150 * V_170 ,
T_8 V_171 , T_8 V_25 , int V_147 )
{
struct V_172 V_173 = { 0 , F_134 (ETH_P_IP) } ;
struct V_37 * V_38 ;
T_8 V_101 = V_171 , V_174 = V_175 ;
struct V_176 V_177 = { 0 } ;
int V_152 = 0 ;
int V_178 ;
bool V_179 = false ;
int V_69 ;
T_1 V_1 ;
if ( ! ( V_7 -> V_57 & V_180 ) ) {
if ( ( V_101 -= sizeof( V_173 ) ) > V_171 )
return - V_72 ;
if ( F_135 ( ( void * ) & V_173 , V_170 , 0 , sizeof( V_173 ) ) )
return - V_90 ;
V_152 += sizeof( V_173 ) ;
}
if ( V_7 -> V_57 & V_181 ) {
if ( ( V_101 -= V_7 -> V_182 ) > V_171 )
return - V_72 ;
if ( F_135 ( ( void * ) & V_177 , V_170 , V_152 , sizeof( V_177 ) ) )
return - V_90 ;
if ( ( V_177 . V_57 & V_183 ) &&
V_177 . V_184 + V_177 . V_185 + 2 > V_177 . V_186 )
V_177 . V_186 = V_177 . V_184 + V_177 . V_185 + 2 ;
if ( V_177 . V_186 > V_101 )
return - V_72 ;
V_152 += V_7 -> V_182 ;
}
if ( ( V_7 -> V_57 & V_124 ) == V_134 ) {
V_174 += V_187 ;
if ( F_31 ( V_101 < V_188 ||
( V_177 . V_186 && V_177 . V_186 < V_188 ) ) )
return - V_72 ;
}
if ( V_169 )
V_179 = true ;
if ( V_179 ) {
if ( V_25 > V_159 ) {
V_178 = F_125 ( V_170 , V_25 - V_159 ) ;
if ( V_178 < V_152 )
V_178 = 0 ;
else
V_178 -= V_152 ;
} else
V_178 = 0 ;
if ( V_178 < V_177 . V_186 )
V_178 = V_177 . V_186 ;
if ( ! V_178 )
V_178 = V_189 ;
} else
V_178 = V_101 ;
V_38 = F_119 ( V_29 , V_174 , V_178 , V_177 . V_186 , V_147 ) ;
if ( F_136 ( V_38 ) ) {
if ( F_137 ( V_38 ) != - V_190 )
V_7 -> V_36 -> V_113 . V_191 ++ ;
return F_137 ( V_38 ) ;
}
if ( V_179 )
V_69 = F_124 ( V_38 , V_170 , V_152 , V_25 ) ;
else
V_69 = F_138 ( V_38 , 0 , V_170 , V_152 , V_101 ) ;
if ( V_69 ) {
V_7 -> V_36 -> V_113 . V_191 ++ ;
F_101 ( V_38 ) ;
return - V_90 ;
}
if ( V_177 . V_57 & V_183 ) {
if ( ! F_139 ( V_38 , V_177 . V_184 ,
V_177 . V_185 ) ) {
V_7 -> V_36 -> V_113 . V_192 ++ ;
F_101 ( V_38 ) ;
return - V_72 ;
}
}
switch ( V_7 -> V_57 & V_124 ) {
case V_125 :
if ( V_7 -> V_57 & V_180 ) {
switch ( V_38 -> V_21 [ 0 ] & 0xf0 ) {
case 0x40 :
V_173 . V_193 = F_140 ( V_194 ) ;
break;
case 0x60 :
V_173 . V_193 = F_140 ( V_195 ) ;
break;
default:
V_7 -> V_36 -> V_113 . V_191 ++ ;
F_101 ( V_38 ) ;
return - V_72 ;
}
}
F_141 ( V_38 ) ;
V_38 -> V_196 = V_173 . V_193 ;
V_38 -> V_36 = V_7 -> V_36 ;
break;
case V_134 :
V_38 -> V_196 = F_142 ( V_38 , V_7 -> V_36 ) ;
break;
}
if ( V_177 . V_197 != V_198 ) {
F_143 ( L_6 ) ;
switch ( V_177 . V_197 & ~ V_199 ) {
case V_200 :
F_132 ( V_38 ) -> V_197 = V_201 ;
break;
case V_202 :
F_132 ( V_38 ) -> V_197 = V_203 ;
break;
case V_204 :
F_132 ( V_38 ) -> V_197 = V_205 ;
break;
default:
V_7 -> V_36 -> V_113 . V_192 ++ ;
F_101 ( V_38 ) ;
return - V_72 ;
}
if ( V_177 . V_197 & V_199 )
F_132 ( V_38 ) -> V_197 |= V_206 ;
F_132 ( V_38 ) -> V_207 = V_177 . V_207 ;
if ( F_132 ( V_38 ) -> V_207 == 0 ) {
V_7 -> V_36 -> V_113 . V_192 ++ ;
F_101 ( V_38 ) ;
return - V_72 ;
}
F_132 ( V_38 ) -> V_197 |= V_208 ;
F_132 ( V_38 ) -> V_209 = 0 ;
}
if ( V_179 ) {
F_132 ( V_38 ) -> V_210 = V_169 ;
F_132 ( V_38 ) -> V_211 |= V_212 ;
F_132 ( V_38 ) -> V_211 |= V_213 ;
}
F_144 ( V_38 ) ;
V_1 = F_28 ( V_38 ) ;
F_145 ( V_38 ) ;
V_7 -> V_36 -> V_113 . V_214 ++ ;
V_7 -> V_36 -> V_113 . V_215 += V_101 ;
F_21 ( V_7 , V_1 , V_29 ) ;
return V_171 ;
}
static T_9 F_146 ( struct V_216 * V_217 , const struct V_150 * V_170 ,
unsigned long V_25 , T_10 V_218 )
{
struct V_67 * V_67 = V_217 -> V_219 ;
struct V_6 * V_7 = F_73 ( V_67 ) ;
struct V_28 * V_29 = V_67 -> V_68 ;
T_9 V_220 ;
if ( ! V_7 )
return - V_221 ;
F_6 ( V_10 , V_7 , L_7 , V_25 ) ;
V_220 = F_133 ( V_7 , V_29 , NULL , V_170 , F_125 ( V_170 , V_25 ) ,
V_25 , V_67 -> V_222 & V_223 ) ;
F_74 ( V_7 ) ;
return V_220 ;
}
static T_9 F_147 ( struct V_6 * V_7 ,
struct V_28 * V_29 ,
struct V_37 * V_38 ,
const struct V_150 * V_170 , int V_101 )
{
struct V_172 V_173 = { 0 , V_38 -> V_196 } ;
T_9 V_224 = 0 ;
if ( ! ( V_7 -> V_57 & V_180 ) ) {
if ( ( V_101 -= sizeof( V_173 ) ) < 0 )
return - V_72 ;
if ( V_101 < V_38 -> V_101 ) {
V_173 . V_57 |= V_225 ;
}
if ( F_148 ( V_170 , ( void * ) & V_173 , 0 , sizeof( V_173 ) ) )
return - V_90 ;
V_224 += sizeof( V_173 ) ;
}
if ( V_7 -> V_57 & V_181 ) {
struct V_176 V_177 = { 0 } ;
if ( ( V_101 -= V_7 -> V_182 ) < 0 )
return - V_72 ;
if ( F_149 ( V_38 ) ) {
struct V_226 * V_227 = F_132 ( V_38 ) ;
V_177 . V_186 = F_126 ( V_38 ) ;
V_177 . V_207 = V_227 -> V_207 ;
if ( V_227 -> V_197 & V_201 )
V_177 . V_197 = V_200 ;
else if ( V_227 -> V_197 & V_203 )
V_177 . V_197 = V_202 ;
else if ( V_227 -> V_197 & V_205 )
V_177 . V_197 = V_204 ;
else {
F_150 ( L_8
L_9 ,
V_227 -> V_197 , V_177 . V_207 ,
V_177 . V_186 ) ;
F_151 ( V_228 , L_10 ,
V_229 ,
16 , 1 , V_38 -> V_4 ,
F_152 ( ( int ) V_177 . V_186 , 64 ) , true ) ;
F_153 ( 1 ) ;
return - V_72 ;
}
if ( V_227 -> V_197 & V_206 )
V_177 . V_197 |= V_199 ;
} else
V_177 . V_197 = V_198 ;
if ( V_38 -> V_230 == V_231 ) {
V_177 . V_57 = V_183 ;
V_177 . V_184 = F_154 ( V_38 ) ;
V_177 . V_185 = V_38 -> V_185 ;
} else if ( V_38 -> V_230 == V_232 ) {
V_177 . V_57 = V_233 ;
}
if ( F_31 ( F_148 ( V_170 , ( void * ) & V_177 , V_224 ,
sizeof( V_177 ) ) ) )
return - V_90 ;
V_224 += V_7 -> V_182 ;
}
V_101 = F_127 ( int , V_38 -> V_101 , V_101 ) ;
F_155 ( V_38 , 0 , V_170 , V_224 , V_101 ) ;
V_224 += V_38 -> V_101 ;
V_7 -> V_36 -> V_113 . V_234 ++ ;
V_7 -> V_36 -> V_113 . V_235 += V_101 ;
return V_224 ;
}
static T_9 F_156 ( struct V_6 * V_7 , struct V_28 * V_29 ,
struct V_216 * V_217 , const struct V_150 * V_170 ,
T_9 V_101 , int V_147 )
{
F_157 ( V_65 , V_236 ) ;
struct V_37 * V_38 ;
T_9 V_237 = 0 ;
F_6 ( V_10 , V_7 , L_11 ) ;
if ( F_31 ( ! V_147 ) )
F_158 ( & V_29 -> V_64 . V_65 , & V_65 ) ;
while ( V_101 ) {
V_236 -> V_238 = V_239 ;
if ( ! ( V_38 = F_159 ( & V_29 -> V_62 . V_55 -> V_56 ) ) ) {
if ( V_147 ) {
V_237 = - V_190 ;
break;
}
if ( F_160 ( V_236 ) ) {
V_237 = - V_240 ;
break;
}
if ( V_7 -> V_36 -> V_59 != V_60 ) {
V_237 = - V_241 ;
break;
}
F_161 () ;
continue;
}
V_237 = F_147 ( V_7 , V_29 , V_38 , V_170 , V_101 ) ;
F_101 ( V_38 ) ;
break;
}
V_236 -> V_238 = V_242 ;
if ( F_31 ( ! V_147 ) )
F_162 ( & V_29 -> V_64 . V_65 , & V_65 ) ;
return V_237 ;
}
static T_9 F_163 ( struct V_216 * V_217 , const struct V_150 * V_170 ,
unsigned long V_25 , T_10 V_218 )
{
struct V_67 * V_67 = V_217 -> V_219 ;
struct V_28 * V_29 = V_67 -> V_68 ;
struct V_6 * V_7 = F_70 ( V_29 ) ;
T_9 V_101 , V_237 ;
if ( ! V_7 )
return - V_221 ;
V_101 = F_125 ( V_170 , V_25 ) ;
if ( V_101 < 0 ) {
V_237 = - V_72 ;
goto V_71;
}
V_237 = F_156 ( V_7 , V_29 , V_217 , V_170 , V_101 ,
V_67 -> V_222 & V_223 ) ;
V_237 = F_127 ( T_9 , V_237 , V_101 ) ;
V_71:
F_74 ( V_7 ) ;
return V_237 ;
}
static void F_164 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_27 ( V_36 ) ;
F_49 ( ! ( F_165 ( & V_7 -> V_49 ) ) ) ;
F_109 ( V_7 ) ;
F_166 ( V_7 -> V_70 ) ;
F_167 ( V_36 ) ;
}
static void F_168 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_27 ( V_36 ) ;
V_7 -> V_43 = V_243 ;
V_7 -> V_45 = V_244 ;
V_36 -> V_245 = & V_246 ;
V_36 -> V_247 = F_164 ;
}
static int F_169 ( struct V_248 * V_249 [] , struct V_248 * V_21 [] )
{
return - V_72 ;
}
static void F_170 ( struct V_139 * V_55 )
{
struct V_28 * V_29 ;
T_11 * V_250 ;
if ( ! F_117 ( V_55 ) )
return;
if ( ! F_171 ( V_141 , & V_55 -> V_142 -> V_57 ) )
return;
V_250 = F_172 ( V_55 ) ;
if ( V_250 && F_173 ( V_250 ) )
F_174 ( V_250 , V_143 |
V_144 | V_251 ) ;
V_29 = F_175 ( V_55 , struct V_28 , V_55 ) ;
F_98 ( & V_29 -> V_106 , V_107 , V_252 ) ;
}
static int F_176 ( struct V_216 * V_217 , struct V_62 * V_139 ,
struct V_253 * V_254 , T_8 V_171 )
{
int V_237 ;
struct V_28 * V_29 = F_175 ( V_139 , struct V_28 , V_62 ) ;
struct V_6 * V_7 = F_70 ( V_29 ) ;
if ( ! V_7 )
return - V_221 ;
V_237 = F_133 ( V_7 , V_29 , V_254 -> V_169 , V_254 -> V_255 , V_171 ,
V_254 -> V_256 , V_254 -> V_257 & V_258 ) ;
F_74 ( V_7 ) ;
return V_237 ;
}
static int F_177 ( struct V_216 * V_217 , struct V_62 * V_139 ,
struct V_253 * V_254 , T_8 V_171 ,
int V_57 )
{
struct V_28 * V_29 = F_175 ( V_139 , struct V_28 , V_62 ) ;
struct V_6 * V_7 = F_70 ( V_29 ) ;
int V_237 ;
if ( ! V_7 )
return - V_221 ;
if ( V_57 & ~ ( V_258 | V_259 ) )
return - V_72 ;
V_237 = F_156 ( V_7 , V_29 , V_217 , V_254 -> V_255 , V_171 ,
V_57 & V_258 ) ;
if ( V_237 > V_171 ) {
V_254 -> V_257 |= V_259 ;
V_237 = V_57 & V_259 ? V_237 : V_171 ;
}
F_74 ( V_7 ) ;
return V_237 ;
}
static int F_178 ( struct V_62 * V_139 )
{
if ( V_139 -> V_55 )
F_51 ( V_139 -> V_55 ) ;
return 0 ;
}
static int F_179 ( struct V_6 * V_7 )
{
int V_57 = 0 ;
if ( V_7 -> V_57 & V_125 )
V_57 |= V_260 ;
else
V_57 |= V_261 ;
if ( V_7 -> V_57 & V_180 )
V_57 |= V_262 ;
if ( V_7 -> V_57 & V_263 )
V_57 |= V_264 ;
if ( V_7 -> V_57 & V_181 )
V_57 |= V_265 ;
if ( V_7 -> V_57 & V_74 )
V_57 |= V_266 ;
return V_57 ;
}
static T_9 F_180 ( struct V_267 * V_36 , struct V_268 * V_269 ,
char * V_270 )
{
struct V_6 * V_7 = F_27 ( F_181 ( V_36 ) ) ;
return sprintf ( V_270 , L_12 , F_179 ( V_7 ) ) ;
}
static T_9 F_182 ( struct V_267 * V_36 , struct V_268 * V_269 ,
char * V_270 )
{
struct V_6 * V_7 = F_27 ( F_181 ( V_36 ) ) ;
return F_35 ( V_7 -> V_43 ) ?
sprintf ( V_270 , L_13 ,
F_183 ( F_184 () , V_7 -> V_43 ) ) :
sprintf ( V_270 , L_14 ) ;
}
static T_9 F_185 ( struct V_267 * V_36 , struct V_268 * V_269 ,
char * V_270 )
{
struct V_6 * V_7 = F_27 ( F_181 ( V_36 ) ) ;
return F_37 ( V_7 -> V_45 ) ?
sprintf ( V_270 , L_13 ,
F_186 ( F_184 () , V_7 -> V_45 ) ) :
sprintf ( V_270 , L_14 ) ;
}
static int F_187 ( struct V_42 * V_42 , struct V_67 * V_67 , struct V_271 * V_272 )
{
struct V_6 * V_7 ;
struct V_28 * V_29 = V_67 -> V_68 ;
struct V_35 * V_36 ;
int V_69 ;
if ( V_29 -> V_32 )
return - V_72 ;
V_36 = F_188 ( V_42 , V_272 -> V_273 ) ;
if ( V_36 ) {
if ( V_272 -> V_274 & V_275 )
return - V_73 ;
if ( ( V_272 -> V_274 & V_260 ) && V_36 -> V_126 == & V_127 )
V_7 = F_27 ( V_36 ) ;
else if ( ( V_272 -> V_274 & V_261 ) && V_36 -> V_126 == & V_135 )
V_7 = F_27 ( V_36 ) ;
else
return - V_72 ;
if ( F_32 ( V_7 ) )
return - V_276 ;
V_69 = F_189 ( V_7 -> V_70 ) ;
if ( V_69 < 0 )
return V_69 ;
V_69 = F_66 ( V_7 , V_67 ) ;
if ( V_69 < 0 )
return V_69 ;
if ( V_7 -> V_57 & V_74 &&
( V_7 -> V_31 + V_7 -> V_50 > 1 ) )
return - V_73 ;
}
else {
char * V_277 ;
unsigned long V_57 = 0 ;
int V_278 = V_272 -> V_274 & V_266 ?
V_76 : 1 ;
if ( ! F_39 ( V_42 -> V_46 , V_47 ) )
return - V_276 ;
V_69 = F_190 () ;
if ( V_69 < 0 )
return V_69 ;
if ( V_272 -> V_274 & V_260 ) {
V_57 |= V_125 ;
V_277 = L_15 ;
} else if ( V_272 -> V_274 & V_261 ) {
V_57 |= V_134 ;
V_277 = L_16 ;
} else
return - V_72 ;
if ( * V_272 -> V_273 )
V_277 = V_272 -> V_273 ;
V_36 = F_191 ( sizeof( struct V_6 ) , V_277 ,
F_168 , V_278 , V_278 ) ;
if ( ! V_36 )
return - V_92 ;
F_192 ( V_36 , V_42 ) ;
V_36 -> V_279 = & V_280 ;
V_7 = F_27 ( V_36 ) ;
V_7 -> V_36 = V_36 ;
V_7 -> V_57 = V_57 ;
V_7 -> V_102 . V_25 = 0 ;
V_7 -> V_182 = sizeof( struct V_176 ) ;
V_7 -> V_77 = false ;
V_7 -> V_281 = V_29 -> V_62 . V_55 -> V_282 ;
F_193 ( & V_7 -> V_17 ) ;
V_69 = F_194 ( & V_7 -> V_70 ) ;
if ( V_69 < 0 )
goto V_283;
F_111 ( V_36 ) ;
V_69 = F_106 ( V_7 ) ;
if ( V_69 < 0 )
goto V_283;
V_36 -> V_284 = V_285 | V_286 |
V_122 ;
V_36 -> V_120 = V_36 -> V_284 ;
F_195 ( & V_7 -> V_49 ) ;
V_69 = F_66 ( V_7 , V_67 ) ;
if ( V_69 < 0 )
goto V_283;
V_69 = F_196 ( V_7 -> V_36 ) ;
if ( V_69 < 0 )
goto V_283;
if ( F_197 ( & V_7 -> V_36 -> V_36 , & V_287 ) ||
F_197 ( & V_7 -> V_36 -> V_36 , & V_288 ) ||
F_197 ( & V_7 -> V_36 -> V_36 , & V_289 ) )
F_150 ( L_17 ) ;
}
F_198 ( V_7 -> V_36 ) ;
F_6 ( V_10 , V_7 , L_18 ) ;
if ( V_272 -> V_274 & V_262 )
V_7 -> V_57 |= V_180 ;
else
V_7 -> V_57 &= ~ V_180 ;
if ( V_272 -> V_274 & V_264 )
V_7 -> V_57 |= V_263 ;
else
V_7 -> V_57 &= ~ V_263 ;
if ( V_272 -> V_274 & V_265 )
V_7 -> V_57 |= V_181 ;
else
V_7 -> V_57 &= ~ V_181 ;
if ( V_272 -> V_274 & V_266 )
V_7 -> V_57 |= V_74 ;
else
V_7 -> V_57 &= ~ V_74 ;
if ( F_199 ( V_7 -> V_36 ) )
F_200 ( V_7 -> V_36 ) ;
strcpy ( V_272 -> V_273 , V_7 -> V_36 -> V_277 ) ;
return 0 ;
V_283:
F_167 ( V_36 ) ;
return V_69 ;
}
static void F_201 ( struct V_42 * V_42 , struct V_6 * V_7 ,
struct V_271 * V_272 )
{
F_6 ( V_10 , V_7 , L_19 ) ;
strcpy ( V_272 -> V_273 , V_7 -> V_36 -> V_277 ) ;
V_272 -> V_274 = F_179 ( V_7 ) ;
}
static int F_202 ( struct V_6 * V_7 , unsigned long V_84 )
{
T_6 V_120 = 0 ;
if ( V_84 & V_290 ) {
V_120 |= V_291 ;
V_84 &= ~ V_290 ;
if ( V_84 & ( V_292 | V_293 ) ) {
if ( V_84 & V_294 ) {
V_120 |= V_295 ;
V_84 &= ~ V_294 ;
}
if ( V_84 & V_292 )
V_120 |= V_296 ;
if ( V_84 & V_293 )
V_120 |= V_297 ;
V_84 &= ~ ( V_292 | V_293 ) ;
}
if ( V_84 & V_298 ) {
V_120 |= V_299 ;
V_84 &= ~ V_298 ;
}
}
if ( V_84 )
return - V_72 ;
V_7 -> V_121 = V_120 ;
F_203 ( V_7 -> V_36 ) ;
return 0 ;
}
static void F_204 ( struct V_6 * V_7 , int V_20 )
{
int V_16 ;
struct V_28 * V_29 ;
for ( V_16 = 0 ; V_16 < V_20 ; V_16 ++ ) {
V_29 = F_48 ( V_7 -> V_54 [ V_16 ] ) ;
F_205 ( V_29 -> V_62 . V_55 ) ;
}
V_7 -> V_77 = false ;
}
static int F_206 ( struct V_6 * V_7 )
{
int V_16 , V_237 = 0 ;
struct V_28 * V_29 ;
for ( V_16 = 0 ; V_16 < V_7 -> V_31 ; V_16 ++ ) {
V_29 = F_48 ( V_7 -> V_54 [ V_16 ] ) ;
V_237 = F_68 ( & V_7 -> V_78 , V_29 -> V_62 . V_55 ) ;
if ( V_237 ) {
F_204 ( V_7 , V_16 ) ;
return V_237 ;
}
}
V_7 -> V_77 = true ;
return V_237 ;
}
static void F_207 ( struct V_6 * V_7 )
{
struct V_28 * V_29 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_7 -> V_31 ; V_16 ++ ) {
V_29 = F_48 ( V_7 -> V_54 [ V_16 ] ) ;
V_29 -> V_62 . V_55 -> V_282 = V_7 -> V_281 ;
}
}
static int F_208 ( struct V_67 * V_67 , struct V_271 * V_272 )
{
struct V_28 * V_29 = V_67 -> V_68 ;
struct V_6 * V_7 ;
int V_237 = 0 ;
F_59 () ;
if ( V_272 -> V_274 & V_300 ) {
V_7 = V_29 -> V_32 ;
if ( ! V_7 ) {
V_237 = - V_72 ;
goto V_33;
}
V_237 = F_209 ( V_7 -> V_70 ) ;
if ( V_237 < 0 )
goto V_33;
V_237 = F_66 ( V_7 , V_67 ) ;
} else if ( V_272 -> V_274 & V_301 ) {
V_7 = F_48 ( V_29 -> V_7 ) ;
if ( ! V_7 || ! ( V_7 -> V_57 & V_74 ) || V_29 -> V_32 )
V_237 = - V_72 ;
else
F_47 ( V_29 , false ) ;
} else
V_237 = - V_72 ;
V_33:
F_60 () ;
return V_237 ;
}
static long F_210 ( struct V_67 * V_67 , unsigned int V_302 ,
unsigned long V_84 , int V_303 )
{
struct V_28 * V_29 = V_67 -> V_68 ;
struct V_6 * V_7 ;
void T_4 * V_304 = ( void T_4 * ) V_84 ;
struct V_271 V_272 ;
T_12 V_43 ;
T_13 V_45 ;
int V_281 ;
int V_182 ;
int V_237 ;
if ( V_302 == V_305 || V_302 == V_306 || F_211 ( V_302 ) == 0x89 ) {
if ( F_80 ( & V_272 , V_304 , V_303 ) )
return - V_90 ;
} else {
memset ( & V_272 , 0 , sizeof( V_272 ) ) ;
}
if ( V_302 == V_307 ) {
return F_212 ( V_260 | V_261 | V_262 | V_264 |
V_265 | V_266 ,
( unsigned int T_4 * ) V_304 ) ;
} else if ( V_302 == V_306 )
return F_208 ( V_67 , & V_272 ) ;
V_237 = 0 ;
F_59 () ;
V_7 = F_70 ( V_29 ) ;
if ( V_302 == V_305 && ! V_7 ) {
V_272 . V_273 [ V_308 - 1 ] = '\0' ;
V_237 = F_187 ( V_29 -> V_42 , V_67 , & V_272 ) ;
if ( V_237 )
goto V_33;
if ( F_213 ( V_304 , & V_272 , V_303 ) )
V_237 = - V_90 ;
goto V_33;
}
V_237 = - V_221 ;
if ( ! V_7 )
goto V_33;
F_6 ( V_10 , V_7 , L_20 , V_302 ) ;
V_237 = 0 ;
switch ( V_302 ) {
case V_309 :
F_201 ( V_236 -> V_310 -> V_311 , V_7 , & V_272 ) ;
if ( F_213 ( V_304 , & V_272 , V_303 ) )
V_237 = - V_90 ;
break;
case V_312 :
F_6 ( V_10 , V_7 , L_21 ,
V_84 ? L_22 : L_23 ) ;
break;
case V_313 :
if ( V_84 && ! ( V_7 -> V_57 & V_58 ) ) {
V_7 -> V_57 |= V_58 ;
F_214 ( V_66 ) ;
}
if ( ! V_84 && ( V_7 -> V_57 & V_58 ) ) {
V_7 -> V_57 &= ~ V_58 ;
F_65 ( V_66 ) ;
}
F_6 ( V_10 , V_7 , L_24 ,
V_84 ? L_23 : L_22 ) ;
break;
case V_314 :
V_43 = F_215 ( F_184 () , V_84 ) ;
if ( ! F_35 ( V_43 ) ) {
V_237 = - V_72 ;
break;
}
V_7 -> V_43 = V_43 ;
F_6 ( V_10 , V_7 , L_25 ,
F_216 ( & V_315 , V_7 -> V_43 ) ) ;
break;
case V_316 :
V_45 = F_217 ( F_184 () , V_84 ) ;
if ( ! F_37 ( V_45 ) ) {
V_237 = - V_72 ;
break;
}
V_7 -> V_45 = V_45 ;
F_6 ( V_10 , V_7 , L_26 ,
F_218 ( & V_315 , V_7 -> V_45 ) ) ;
break;
case V_317 :
if ( V_7 -> V_36 -> V_57 & V_318 ) {
F_6 ( V_10 , V_7 ,
L_27 ) ;
V_237 = - V_73 ;
} else {
V_7 -> V_36 -> type = ( int ) V_84 ;
F_6 ( V_10 , V_7 , L_28 ,
V_7 -> V_36 -> type ) ;
V_237 = 0 ;
}
break;
#ifdef F_219
case V_319 :
V_7 -> V_320 = V_84 ;
break;
#endif
case V_321 :
V_237 = F_202 ( V_7 , V_84 ) ;
break;
case V_322 :
V_237 = - V_72 ;
if ( ( V_7 -> V_57 & V_124 ) != V_134 )
break;
V_237 = F_79 ( & V_7 -> V_102 , ( void T_4 * ) V_84 ) ;
break;
case V_323 :
memcpy ( V_272 . V_324 . V_325 , V_7 -> V_36 -> V_326 , V_81 ) ;
V_272 . V_324 . V_327 = V_7 -> V_36 -> type ;
if ( F_213 ( V_304 , & V_272 , V_303 ) )
V_237 = - V_90 ;
break;
case V_328 :
F_6 ( V_329 , V_7 , L_29 ,
V_272 . V_324 . V_325 ) ;
V_237 = F_220 ( V_7 -> V_36 , & V_272 . V_324 ) ;
break;
case V_330 :
V_281 = V_29 -> V_62 . V_55 -> V_282 ;
if ( F_213 ( V_304 , & V_281 , sizeof( V_281 ) ) )
V_237 = - V_90 ;
break;
case V_331 :
if ( F_80 ( & V_281 , V_304 , sizeof( V_281 ) ) ) {
V_237 = - V_90 ;
break;
}
V_7 -> V_281 = V_281 ;
F_207 ( V_7 ) ;
break;
case V_332 :
V_182 = V_7 -> V_182 ;
if ( F_213 ( V_304 , & V_182 , sizeof( V_182 ) ) )
V_237 = - V_90 ;
break;
case V_333 :
if ( F_80 ( & V_182 , V_304 , sizeof( V_182 ) ) ) {
V_237 = - V_90 ;
break;
}
if ( V_182 < ( int ) sizeof( struct V_176 ) ) {
V_237 = - V_72 ;
break;
}
V_7 -> V_182 = V_182 ;
break;
case V_334 :
V_237 = - V_72 ;
if ( ( V_7 -> V_57 & V_124 ) != V_134 )
break;
V_237 = - V_90 ;
if ( F_80 ( & V_7 -> V_78 , V_304 , sizeof( V_7 -> V_78 ) ) )
break;
V_237 = F_206 ( V_7 ) ;
break;
case V_335 :
V_237 = - V_72 ;
if ( ( V_7 -> V_57 & V_124 ) != V_134 )
break;
V_237 = 0 ;
F_204 ( V_7 , V_7 -> V_31 ) ;
break;
default:
V_237 = - V_72 ;
break;
}
V_33:
F_60 () ;
if ( V_7 )
F_74 ( V_7 ) ;
return V_237 ;
}
static long F_221 ( struct V_67 * V_67 ,
unsigned int V_302 , unsigned long V_84 )
{
return F_210 ( V_67 , V_302 , V_84 , sizeof ( struct V_271 ) ) ;
}
static long F_222 ( struct V_67 * V_67 ,
unsigned int V_302 , unsigned long V_84 )
{
switch ( V_302 ) {
case V_305 :
case V_309 :
case V_322 :
case V_330 :
case V_331 :
case V_323 :
case V_328 :
V_84 = ( unsigned long ) F_223 ( V_84 ) ;
break;
default:
V_84 = ( V_336 ) V_84 ;
break;
}
return F_210 ( V_67 , V_302 , V_84 , sizeof( struct V_337 ) ) ;
}
static int F_224 ( int V_338 , struct V_67 * V_67 , int V_339 )
{
struct V_28 * V_29 = V_67 -> V_68 ;
int V_237 ;
if ( ( V_237 = F_225 ( V_338 , V_67 , V_339 , & V_29 -> V_106 ) ) < 0 )
goto V_71;
if ( V_339 ) {
V_237 = F_226 ( V_67 , F_227 ( V_236 ) , V_340 , 0 ) ;
if ( V_237 )
goto V_71;
V_29 -> V_57 |= V_105 ;
} else
V_29 -> V_57 &= ~ V_105 ;
V_237 = 0 ;
V_71:
return V_237 ;
}
static int F_228 ( struct V_341 * V_341 , struct V_67 * V_67 )
{
struct V_28 * V_29 ;
F_229 ( V_10 , L_30 ) ;
V_29 = (struct V_28 * ) F_230 ( & V_342 , V_343 , V_91 ,
& V_344 ) ;
if ( ! V_29 )
return - V_92 ;
F_50 ( V_29 -> V_7 , NULL ) ;
V_29 -> V_42 = F_231 ( V_236 -> V_310 -> V_311 ) ;
V_29 -> V_57 = 0 ;
F_50 ( V_29 -> V_62 . V_64 , & V_29 -> V_64 ) ;
F_232 ( & V_29 -> V_64 . V_65 ) ;
V_29 -> V_62 . V_67 = V_67 ;
V_29 -> V_62 . V_345 = & V_346 ;
F_233 ( & V_29 -> V_62 , & V_29 -> V_55 ) ;
F_234 ( & V_29 -> V_55 , V_29 -> V_42 ) ;
V_29 -> V_55 . V_347 = F_170 ;
V_29 -> V_55 . V_282 = V_348 ;
V_67 -> V_68 = V_29 ;
F_235 ( V_61 , & V_29 -> V_62 . V_57 ) ;
F_195 ( & V_29 -> V_48 ) ;
return 0 ;
}
static int F_236 ( struct V_341 * V_341 , struct V_67 * V_67 )
{
struct V_28 * V_29 = V_67 -> V_68 ;
struct V_42 * V_42 = V_29 -> V_42 ;
F_58 ( V_29 , true ) ;
F_237 ( V_42 ) ;
return 0 ;
}
static int F_238 ( struct V_35 * V_36 , struct V_349 * V_302 )
{
V_302 -> V_350 = 0 ;
V_302 -> V_351 = 0 ;
F_239 ( V_302 , V_352 ) ;
V_302 -> V_353 = V_354 ;
V_302 -> V_355 = V_356 ;
V_302 -> V_357 = 0 ;
V_302 -> V_358 = V_359 ;
V_302 -> V_360 = V_361 ;
V_302 -> V_362 = 0 ;
V_302 -> V_363 = 0 ;
return 0 ;
}
static void F_240 ( struct V_35 * V_36 , struct V_364 * V_365 )
{
struct V_6 * V_7 = F_27 ( V_36 ) ;
F_241 ( V_365 -> V_366 , V_367 , sizeof( V_365 -> V_366 ) ) ;
F_241 ( V_365 -> V_368 , V_369 , sizeof( V_365 -> V_368 ) ) ;
switch ( V_7 -> V_57 & V_124 ) {
case V_125 :
F_241 ( V_365 -> V_370 , L_31 , sizeof( V_365 -> V_370 ) ) ;
break;
case V_134 :
F_241 ( V_365 -> V_370 , L_32 , sizeof( V_365 -> V_370 ) ) ;
break;
}
}
static T_1 F_242 ( struct V_35 * V_36 )
{
#ifdef F_219
struct V_6 * V_7 = F_27 ( V_36 ) ;
return V_7 -> V_320 ;
#else
return - V_371 ;
#endif
}
static void F_243 ( struct V_35 * V_36 , T_1 V_372 )
{
#ifdef F_219
struct V_6 * V_7 = F_27 ( V_36 ) ;
V_7 -> V_320 = V_372 ;
#endif
}
static int T_14 F_244 ( void )
{
int V_237 = 0 ;
F_245 ( L_33 , V_373 , V_369 ) ;
F_245 ( L_34 , V_374 ) ;
V_237 = F_246 ( & V_280 ) ;
if ( V_237 ) {
F_150 ( L_35 ) ;
goto V_375;
}
V_237 = F_247 ( & V_376 ) ;
if ( V_237 ) {
F_150 ( L_36 , V_377 ) ;
goto V_378;
}
return 0 ;
V_378:
F_248 ( & V_280 ) ;
V_375:
return V_237 ;
}
static void F_249 ( void )
{
F_250 ( & V_376 ) ;
F_248 ( & V_280 ) ;
}
struct V_62 * F_251 ( struct V_67 * V_67 )
{
struct V_28 * V_29 ;
if ( V_67 -> V_379 != & V_380 )
return F_121 ( - V_72 ) ;
V_29 = V_67 -> V_68 ;
if ( ! V_29 )
return F_121 ( - V_221 ) ;
return & V_29 -> V_62 ;
}
