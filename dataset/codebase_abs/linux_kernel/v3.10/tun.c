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
static void F_48 ( struct V_28 * V_29 , bool V_51 )
{
struct V_28 * V_52 ;
struct V_6 * V_7 ;
V_7 = F_49 ( V_29 -> V_7 ) ;
if ( V_7 && ! V_29 -> V_32 ) {
T_2 V_53 = V_29 -> V_8 ;
F_50 ( V_53 >= V_7 -> V_31 ) ;
F_51 ( V_7 -> V_54 [ V_53 ] ,
V_7 -> V_54 [ V_7 -> V_31 - 1 ] ) ;
V_52 = F_49 ( V_7 -> V_54 [ V_53 ] ) ;
V_52 -> V_8 = V_53 ;
-- V_7 -> V_31 ;
if ( V_51 ) {
F_51 ( V_29 -> V_7 , NULL ) ;
F_52 ( & V_29 -> V_55 ) ;
} else
F_44 ( V_7 , V_29 ) ;
F_53 () ;
F_15 ( V_7 , V_7 -> V_31 + 1 ) ;
F_54 ( & V_29 -> V_55 . V_56 ) ;
F_41 ( V_7 ) ;
} else if ( V_29 -> V_32 && V_51 ) {
V_7 = F_46 ( V_29 ) ;
F_52 ( & V_29 -> V_55 ) ;
}
if ( V_51 ) {
if ( V_7 && V_7 -> V_31 == 0 && V_7 -> V_50 == 0 ) {
F_55 ( V_7 -> V_36 ) ;
if ( ! ( V_7 -> V_57 & V_58 ) &&
V_7 -> V_36 -> V_59 == V_60 )
F_56 ( V_7 -> V_36 ) ;
}
F_50 ( ! F_57 ( V_61 ,
& V_29 -> V_62 . V_57 ) ) ;
F_58 ( & V_29 -> V_55 ) ;
}
}
static void F_59 ( struct V_28 * V_29 , bool V_51 )
{
F_60 () ;
F_48 ( V_29 , V_51 ) ;
F_61 () ;
}
static void F_62 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_27 ( V_36 ) ;
struct V_28 * V_29 , * V_63 ;
int V_16 , V_20 = V_7 -> V_31 ;
for ( V_16 = 0 ; V_16 < V_20 ; V_16 ++ ) {
V_29 = F_49 ( V_7 -> V_54 [ V_16 ] ) ;
F_50 ( ! V_29 ) ;
F_63 ( & V_29 -> V_64 . V_65 ) ;
F_51 ( V_29 -> V_7 , NULL ) ;
-- V_7 -> V_31 ;
}
F_64 (tfile, &tun->disabled, next) {
F_63 ( & V_29 -> V_64 . V_65 ) ;
F_51 ( V_29 -> V_7 , NULL ) ;
}
F_50 ( V_7 -> V_31 != 0 ) ;
F_53 () ;
for ( V_16 = 0 ; V_16 < V_20 ; V_16 ++ ) {
V_29 = F_49 ( V_7 -> V_54 [ V_16 ] ) ;
F_54 ( & V_29 -> V_55 . V_56 ) ;
F_52 ( & V_29 -> V_55 ) ;
}
F_65 (tfile, tmp, &tun->disabled, next) {
F_46 ( V_29 ) ;
F_54 ( & V_29 -> V_55 . V_56 ) ;
F_52 ( & V_29 -> V_55 ) ;
}
F_50 ( V_7 -> V_50 != 0 ) ;
if ( V_7 -> V_57 & V_58 )
F_66 ( V_66 ) ;
}
static int F_67 ( struct V_6 * V_7 , struct V_67 * V_67 )
{
struct V_28 * V_29 = V_67 -> V_68 ;
int V_69 ;
V_69 = F_68 ( V_29 -> V_62 . V_55 , V_7 -> V_70 ) ;
if ( V_69 < 0 )
goto V_71;
V_69 = - V_72 ;
if ( F_49 ( V_29 -> V_7 ) && ! V_29 -> V_32 )
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
V_69 = F_69 ( & V_7 -> V_78 , V_29 -> V_62 . V_55 ) ;
if ( ! V_69 )
goto V_71;
}
V_29 -> V_8 = V_7 -> V_31 ;
F_51 ( V_29 -> V_7 , V_7 ) ;
F_51 ( V_7 -> V_54 [ V_7 -> V_31 ] , V_29 ) ;
V_7 -> V_31 ++ ;
if ( V_29 -> V_32 )
F_46 ( V_29 ) ;
else
F_70 ( & V_29 -> V_55 ) ;
F_41 ( V_7 ) ;
V_71:
return V_69 ;
}
static struct V_6 * F_71 ( struct V_28 * V_29 )
{
struct V_6 * V_7 ;
F_22 () ;
V_7 = F_72 ( V_29 -> V_7 ) ;
if ( V_7 )
F_73 ( V_7 -> V_36 ) ;
F_25 () ;
return V_7 ;
}
static struct V_6 * F_74 ( struct V_67 * V_67 )
{
return F_71 ( V_67 -> V_68 ) ;
}
static void F_75 ( struct V_6 * V_7 )
{
F_76 ( V_7 -> V_36 ) ;
}
static void F_77 ( T_1 * V_79 , const T_3 * V_80 )
{
int V_20 = F_78 ( V_81 , V_80 ) >> 26 ;
V_79 [ V_20 >> 5 ] |= ( 1 << ( V_20 & 31 ) ) ;
}
static unsigned int F_79 ( const T_1 * V_79 , const T_3 * V_80 )
{
int V_20 = F_78 ( V_81 , V_80 ) >> 26 ;
return V_79 [ V_20 >> 5 ] & ( 1 << ( V_20 & 31 ) ) ;
}
static int F_80 ( struct V_82 * V_83 , void T_4 * V_84 )
{
struct { T_3 V_85 [ V_81 ] ; } * V_80 ;
struct V_86 V_87 ;
int V_69 , V_88 , V_20 , V_89 ;
if ( F_81 ( & V_87 , V_84 , sizeof( V_87 ) ) )
return - V_90 ;
if ( ! V_87 . V_25 ) {
V_83 -> V_25 = 0 ;
return 0 ;
}
V_88 = V_81 * V_87 . V_25 ;
V_80 = F_5 ( V_88 , V_91 ) ;
if ( ! V_80 )
return - V_92 ;
if ( F_81 ( V_80 , V_84 + sizeof( V_87 ) , V_88 ) ) {
V_69 = - V_90 ;
goto V_93;
}
V_83 -> V_25 = 0 ;
F_82 () ;
for ( V_20 = 0 ; V_20 < V_87 . V_25 && V_20 < V_94 ; V_20 ++ )
memcpy ( V_83 -> V_80 [ V_20 ] , V_80 [ V_20 ] . V_85 , V_81 ) ;
V_89 = V_20 ;
memset ( V_83 -> V_79 , 0 , sizeof( V_83 -> V_79 ) ) ;
for (; V_20 < V_87 . V_25 ; V_20 ++ ) {
if ( ! F_83 ( V_80 [ V_20 ] . V_85 ) ) {
V_69 = 0 ;
goto V_93;
}
F_77 ( V_83 -> V_79 , V_80 [ V_20 ] . V_85 ) ;
}
if ( ( V_87 . V_57 & V_95 ) )
memset ( V_83 -> V_79 , ~ 0 , sizeof( V_83 -> V_79 ) ) ;
F_82 () ;
V_83 -> V_25 = V_89 ;
V_69 = V_89 ;
V_93:
F_84 ( V_80 ) ;
return V_69 ;
}
static int F_85 ( struct V_82 * V_83 , const struct V_37 * V_38 )
{
struct V_96 * V_97 = (struct V_96 * ) V_38 -> V_21 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_83 -> V_25 ; V_16 ++ )
if ( F_86 ( V_97 -> V_98 , V_83 -> V_80 [ V_16 ] ) )
return 1 ;
if ( F_83 ( V_97 -> V_98 ) )
return F_79 ( V_83 -> V_79 , V_97 -> V_98 ) ;
return 0 ;
}
static int F_87 ( struct V_82 * V_83 , const struct V_37 * V_38 )
{
if ( ! V_83 -> V_25 )
return 1 ;
return F_85 ( V_83 , V_38 ) ;
}
static void F_88 ( struct V_35 * V_36 )
{
F_62 ( V_36 ) ;
}
static int F_89 ( struct V_35 * V_36 )
{
F_90 ( V_36 ) ;
return 0 ;
}
static int F_91 ( struct V_35 * V_36 )
{
F_92 ( V_36 ) ;
return 0 ;
}
static T_5 F_93 ( struct V_37 * V_38 , struct V_35 * V_36 )
{
struct V_6 * V_7 = F_27 ( V_36 ) ;
int V_39 = V_38 -> V_99 ;
struct V_28 * V_29 ;
F_22 () ;
V_29 = F_72 ( V_7 -> V_54 [ V_39 ] ) ;
if ( V_39 >= V_7 -> V_31 )
goto V_100;
F_6 ( V_10 , V_7 , L_4 , V_38 -> V_101 ) ;
F_50 ( ! V_29 ) ;
if ( ! F_87 ( & V_7 -> V_102 , V_38 ) )
goto V_100;
if ( V_29 -> V_62 . V_55 -> V_103 &&
V_103 ( V_29 -> V_62 . V_55 , V_38 ) )
goto V_100;
if ( F_94 ( & V_29 -> V_62 . V_55 -> V_56 )
>= V_36 -> V_104 / V_7 -> V_31 )
goto V_100;
if ( F_32 ( F_95 ( V_38 , V_9 ) ) )
goto V_100;
F_96 ( V_38 ) ;
F_97 ( V_38 ) ;
F_98 ( & V_29 -> V_62 . V_55 -> V_56 , V_38 ) ;
if ( V_29 -> V_57 & V_105 )
F_99 ( & V_29 -> V_106 , V_107 , V_108 ) ;
F_100 ( & V_29 -> V_64 . V_65 , V_109 |
V_110 | V_111 ) ;
F_25 () ;
return V_112 ;
V_100:
V_36 -> V_113 . V_114 ++ ;
F_101 ( V_38 ) ;
F_102 ( V_38 ) ;
F_25 () ;
return V_112 ;
}
static void F_103 ( struct V_35 * V_36 )
{
}
static int
F_104 ( struct V_35 * V_36 , int V_115 )
{
if ( V_115 < V_116 || V_115 + V_36 -> V_117 > V_118 )
return - V_72 ;
V_36 -> V_119 = V_115 ;
return 0 ;
}
static T_6 F_105 ( struct V_35 * V_36 ,
T_6 V_120 )
{
struct V_6 * V_7 = F_27 ( V_36 ) ;
return ( V_120 & V_7 -> V_121 ) | ( V_120 & ~ V_122 ) ;
}
static void F_106 ( struct V_35 * V_36 )
{
return;
}
static int F_107 ( struct V_6 * V_7 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_18 ; V_16 ++ )
F_108 ( & V_7 -> V_30 [ V_16 ] ) ;
V_7 -> V_23 = V_123 ;
F_109 ( & V_7 -> V_27 , F_16 , ( unsigned long ) V_7 ) ;
F_19 ( & V_7 -> V_27 ,
F_20 ( V_12 + V_7 -> V_23 ) ) ;
return 0 ;
}
static void F_110 ( struct V_6 * V_7 )
{
F_111 ( & V_7 -> V_27 ) ;
F_11 ( V_7 ) ;
}
static void F_112 ( struct V_35 * V_36 )
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
F_113 ( V_36 ) ;
V_36 -> V_136 &= ~ V_137 ;
V_36 -> V_136 |= V_138 ;
F_114 ( V_36 ) ;
V_36 -> V_104 = V_133 ;
break;
}
}
static unsigned int F_115 ( struct V_67 * V_67 , T_7 * V_65 )
{
struct V_28 * V_29 = V_67 -> V_68 ;
struct V_6 * V_7 = F_71 ( V_29 ) ;
struct V_139 * V_55 ;
unsigned int V_79 = 0 ;
if ( ! V_7 )
return V_140 ;
V_55 = V_29 -> V_62 . V_55 ;
F_6 ( V_10 , V_7 , L_5 ) ;
F_116 ( V_67 , & V_29 -> V_64 . V_65 , V_65 ) ;
if ( ! F_117 ( & V_55 -> V_56 ) )
V_79 |= V_109 | V_110 ;
if ( F_118 ( V_55 ) ||
( ! F_119 ( V_141 , & V_55 -> V_142 -> V_57 ) &&
F_118 ( V_55 ) ) )
V_79 |= V_143 | V_144 ;
if ( V_7 -> V_36 -> V_59 != V_60 )
V_79 = V_140 ;
F_75 ( V_7 ) ;
return V_79 ;
}
static struct V_37 * F_120 ( struct V_28 * V_29 ,
T_8 V_145 , T_8 V_101 ,
T_8 V_146 , int V_147 )
{
struct V_139 * V_55 = V_29 -> V_62 . V_55 ;
struct V_37 * V_38 ;
int V_69 ;
if ( V_145 + V_101 < V_148 || ! V_146 )
V_146 = V_101 ;
V_38 = F_121 ( V_55 , V_145 + V_146 , V_101 - V_146 , V_147 ,
& V_69 ) ;
if ( ! V_38 )
return F_122 ( V_69 ) ;
F_123 ( V_38 , V_145 ) ;
F_124 ( V_38 , V_146 ) ;
V_38 -> V_149 = V_101 - V_146 ;
V_38 -> V_101 += V_101 - V_146 ;
return V_38 ;
}
static int F_125 ( struct V_37 * V_38 , const struct V_150 * V_151 ,
int V_152 , T_8 V_25 )
{
int V_101 = F_126 ( V_151 , V_25 ) - V_152 ;
int V_153 = F_127 ( V_38 ) ;
int V_154 , V_155 = 0 ;
int V_16 = 0 ;
while ( V_25 && ( V_152 >= V_151 -> V_156 ) ) {
V_152 -= V_151 -> V_156 ;
++ V_151 ;
-- V_25 ;
}
while ( V_25 && ( V_153 > 0 ) ) {
V_154 = F_128 (unsigned int, copy, from->iov_len - offset) ;
if ( F_81 ( V_38 -> V_21 + V_155 , V_151 -> V_157 + V_152 ,
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
V_160 = F_129 ( V_161 , V_154 , 0 , & V_158 [ V_16 ] ) ;
if ( V_160 != V_154 ) {
int V_166 ;
for ( V_166 = 0 ; V_166 < V_160 ; V_166 ++ )
F_130 ( V_158 [ V_16 + V_166 ] ) ;
return - V_90 ;
}
V_162 = V_154 * V_148 ;
V_38 -> V_149 += V_101 ;
V_38 -> V_101 += V_101 ;
V_38 -> V_162 += V_162 ;
F_131 ( V_162 , & V_38 -> V_55 -> V_167 ) ;
while ( V_101 ) {
int V_168 = V_161 & ~ V_163 ;
int V_154 = F_128 ( int , V_101 , V_148 - V_168 ) ;
F_132 ( V_38 , V_16 , V_158 [ V_16 ] , V_168 , V_154 ) ;
F_133 ( V_38 ) -> V_169 ++ ;
V_161 += V_154 ;
V_101 -= V_154 ;
V_16 ++ ;
}
V_152 = 0 ;
++ V_151 ;
}
return 0 ;
}
static T_9 F_134 ( struct V_6 * V_7 , struct V_28 * V_29 ,
void * V_170 , const struct V_150 * V_171 ,
T_8 V_172 , T_8 V_25 , int V_147 )
{
struct V_173 V_174 = { 0 , F_135 (ETH_P_IP) } ;
struct V_37 * V_38 ;
T_8 V_101 = V_172 , V_175 = V_176 ;
struct V_177 V_178 = { 0 } ;
int V_152 = 0 ;
int V_179 ;
bool V_180 = false ;
int V_69 ;
T_1 V_1 ;
if ( ! ( V_7 -> V_57 & V_181 ) ) {
if ( ( V_101 -= sizeof( V_174 ) ) > V_172 )
return - V_72 ;
if ( F_136 ( ( void * ) & V_174 , V_171 , 0 , sizeof( V_174 ) ) )
return - V_90 ;
V_152 += sizeof( V_174 ) ;
}
if ( V_7 -> V_57 & V_182 ) {
if ( ( V_101 -= V_7 -> V_183 ) > V_172 )
return - V_72 ;
if ( F_136 ( ( void * ) & V_178 , V_171 , V_152 , sizeof( V_178 ) ) )
return - V_90 ;
if ( ( V_178 . V_57 & V_184 ) &&
V_178 . V_185 + V_178 . V_186 + 2 > V_178 . V_187 )
V_178 . V_187 = V_178 . V_185 + V_178 . V_186 + 2 ;
if ( V_178 . V_187 > V_101 )
return - V_72 ;
V_152 += V_7 -> V_183 ;
}
if ( ( V_7 -> V_57 & V_124 ) == V_134 ) {
V_175 += V_188 ;
if ( F_32 ( V_101 < V_189 ||
( V_178 . V_187 && V_178 . V_187 < V_189 ) ) )
return - V_72 ;
}
if ( V_170 )
V_180 = true ;
if ( V_180 ) {
if ( V_25 > V_159 ) {
V_179 = F_126 ( V_171 , V_25 - V_159 ) ;
if ( V_179 < V_152 )
V_179 = 0 ;
else
V_179 -= V_152 ;
} else
V_179 = 0 ;
if ( V_179 < V_178 . V_187 )
V_179 = V_178 . V_187 ;
if ( ! V_179 )
V_179 = V_190 ;
} else
V_179 = V_101 ;
V_38 = F_120 ( V_29 , V_175 , V_179 , V_178 . V_187 , V_147 ) ;
if ( F_137 ( V_38 ) ) {
if ( F_138 ( V_38 ) != - V_191 )
V_7 -> V_36 -> V_113 . V_192 ++ ;
return F_138 ( V_38 ) ;
}
if ( V_180 )
V_69 = F_125 ( V_38 , V_171 , V_152 , V_25 ) ;
else
V_69 = F_139 ( V_38 , 0 , V_171 , V_152 , V_101 ) ;
if ( V_69 ) {
V_7 -> V_36 -> V_113 . V_192 ++ ;
F_102 ( V_38 ) ;
return - V_90 ;
}
if ( V_178 . V_57 & V_184 ) {
if ( ! F_140 ( V_38 , V_178 . V_185 ,
V_178 . V_186 ) ) {
V_7 -> V_36 -> V_113 . V_193 ++ ;
F_102 ( V_38 ) ;
return - V_72 ;
}
}
switch ( V_7 -> V_57 & V_124 ) {
case V_125 :
if ( V_7 -> V_57 & V_181 ) {
switch ( V_38 -> V_21 [ 0 ] & 0xf0 ) {
case 0x40 :
V_174 . V_194 = F_141 ( V_195 ) ;
break;
case 0x60 :
V_174 . V_194 = F_141 ( V_196 ) ;
break;
default:
V_7 -> V_36 -> V_113 . V_192 ++ ;
F_102 ( V_38 ) ;
return - V_72 ;
}
}
F_142 ( V_38 ) ;
V_38 -> V_197 = V_174 . V_194 ;
V_38 -> V_36 = V_7 -> V_36 ;
break;
case V_134 :
V_38 -> V_197 = F_143 ( V_38 , V_7 -> V_36 ) ;
break;
}
if ( V_178 . V_198 != V_199 ) {
F_144 ( L_6 ) ;
switch ( V_178 . V_198 & ~ V_200 ) {
case V_201 :
F_133 ( V_38 ) -> V_198 = V_202 ;
break;
case V_203 :
F_133 ( V_38 ) -> V_198 = V_204 ;
break;
case V_205 :
F_133 ( V_38 ) -> V_198 = V_206 ;
break;
default:
V_7 -> V_36 -> V_113 . V_193 ++ ;
F_102 ( V_38 ) ;
return - V_72 ;
}
if ( V_178 . V_198 & V_200 )
F_133 ( V_38 ) -> V_198 |= V_207 ;
F_133 ( V_38 ) -> V_208 = V_178 . V_208 ;
if ( F_133 ( V_38 ) -> V_208 == 0 ) {
V_7 -> V_36 -> V_113 . V_193 ++ ;
F_102 ( V_38 ) ;
return - V_72 ;
}
F_133 ( V_38 ) -> V_198 |= V_209 ;
F_133 ( V_38 ) -> V_210 = 0 ;
}
if ( V_180 ) {
F_133 ( V_38 ) -> V_211 = V_170 ;
F_133 ( V_38 ) -> V_212 |= V_213 ;
F_133 ( V_38 ) -> V_212 |= V_214 ;
}
F_145 ( V_38 ) ;
F_146 ( V_38 , 0 ) ;
V_1 = F_29 ( V_38 ) ;
F_147 ( V_38 ) ;
V_7 -> V_36 -> V_113 . V_215 ++ ;
V_7 -> V_36 -> V_113 . V_216 += V_101 ;
F_21 ( V_7 , V_1 , V_29 ) ;
return V_172 ;
}
static T_9 F_148 ( struct V_217 * V_218 , const struct V_150 * V_171 ,
unsigned long V_25 , T_10 V_219 )
{
struct V_67 * V_67 = V_218 -> V_220 ;
struct V_6 * V_7 = F_74 ( V_67 ) ;
struct V_28 * V_29 = V_67 -> V_68 ;
T_9 V_221 ;
if ( ! V_7 )
return - V_222 ;
F_6 ( V_10 , V_7 , L_7 , V_25 ) ;
V_221 = F_134 ( V_7 , V_29 , NULL , V_171 , F_126 ( V_171 , V_25 ) ,
V_25 , V_67 -> V_223 & V_224 ) ;
F_75 ( V_7 ) ;
return V_221 ;
}
static T_9 F_149 ( struct V_6 * V_7 ,
struct V_28 * V_29 ,
struct V_37 * V_38 ,
const struct V_150 * V_171 , int V_101 )
{
struct V_173 V_174 = { 0 , V_38 -> V_197 } ;
T_9 V_225 = 0 ;
if ( ! ( V_7 -> V_57 & V_181 ) ) {
if ( ( V_101 -= sizeof( V_174 ) ) < 0 )
return - V_72 ;
if ( V_101 < V_38 -> V_101 ) {
V_174 . V_57 |= V_226 ;
}
if ( F_150 ( V_171 , ( void * ) & V_174 , 0 , sizeof( V_174 ) ) )
return - V_90 ;
V_225 += sizeof( V_174 ) ;
}
if ( V_7 -> V_57 & V_182 ) {
struct V_177 V_178 = { 0 } ;
if ( ( V_101 -= V_7 -> V_183 ) < 0 )
return - V_72 ;
if ( F_151 ( V_38 ) ) {
struct V_227 * V_228 = F_133 ( V_38 ) ;
V_178 . V_187 = F_127 ( V_38 ) ;
V_178 . V_208 = V_228 -> V_208 ;
if ( V_228 -> V_198 & V_202 )
V_178 . V_198 = V_201 ;
else if ( V_228 -> V_198 & V_204 )
V_178 . V_198 = V_203 ;
else if ( V_228 -> V_198 & V_206 )
V_178 . V_198 = V_205 ;
else {
F_152 ( L_8
L_9 ,
V_228 -> V_198 , V_178 . V_208 ,
V_178 . V_187 ) ;
F_153 ( V_229 , L_10 ,
V_230 ,
16 , 1 , V_38 -> V_4 ,
F_154 ( ( int ) V_178 . V_187 , 64 ) , true ) ;
F_155 ( 1 ) ;
return - V_72 ;
}
if ( V_228 -> V_198 & V_207 )
V_178 . V_198 |= V_200 ;
} else
V_178 . V_198 = V_199 ;
if ( V_38 -> V_231 == V_232 ) {
V_178 . V_57 = V_184 ;
V_178 . V_185 = F_156 ( V_38 ) ;
V_178 . V_186 = V_38 -> V_186 ;
} else if ( V_38 -> V_231 == V_233 ) {
V_178 . V_57 = V_234 ;
}
if ( F_32 ( F_150 ( V_171 , ( void * ) & V_178 , V_225 ,
sizeof( V_178 ) ) ) )
return - V_90 ;
V_225 += V_7 -> V_183 ;
}
V_101 = F_128 ( int , V_38 -> V_101 , V_101 ) ;
F_157 ( V_38 , 0 , V_171 , V_225 , V_101 ) ;
V_225 += V_38 -> V_101 ;
V_7 -> V_36 -> V_113 . V_235 ++ ;
V_7 -> V_36 -> V_113 . V_236 += V_101 ;
return V_225 ;
}
static T_9 F_158 ( struct V_6 * V_7 , struct V_28 * V_29 ,
struct V_217 * V_218 , const struct V_150 * V_171 ,
T_9 V_101 , int V_147 )
{
F_159 ( V_65 , V_237 ) ;
struct V_37 * V_38 ;
T_9 V_238 = 0 ;
F_6 ( V_10 , V_7 , L_11 ) ;
if ( F_32 ( ! V_147 ) )
F_160 ( & V_29 -> V_64 . V_65 , & V_65 ) ;
while ( V_101 ) {
V_237 -> V_239 = V_240 ;
if ( ! ( V_38 = F_161 ( & V_29 -> V_62 . V_55 -> V_56 ) ) ) {
if ( V_147 ) {
V_238 = - V_191 ;
break;
}
if ( F_162 ( V_237 ) ) {
V_238 = - V_241 ;
break;
}
if ( V_7 -> V_36 -> V_59 != V_60 ) {
V_238 = - V_242 ;
break;
}
F_163 () ;
continue;
}
V_238 = F_149 ( V_7 , V_29 , V_38 , V_171 , V_101 ) ;
F_102 ( V_38 ) ;
break;
}
V_237 -> V_239 = V_243 ;
if ( F_32 ( ! V_147 ) )
F_164 ( & V_29 -> V_64 . V_65 , & V_65 ) ;
return V_238 ;
}
static T_9 F_165 ( struct V_217 * V_218 , const struct V_150 * V_171 ,
unsigned long V_25 , T_10 V_219 )
{
struct V_67 * V_67 = V_218 -> V_220 ;
struct V_28 * V_29 = V_67 -> V_68 ;
struct V_6 * V_7 = F_71 ( V_29 ) ;
T_9 V_101 , V_238 ;
if ( ! V_7 )
return - V_222 ;
V_101 = F_126 ( V_171 , V_25 ) ;
if ( V_101 < 0 ) {
V_238 = - V_72 ;
goto V_71;
}
V_238 = F_158 ( V_7 , V_29 , V_218 , V_171 , V_101 ,
V_67 -> V_223 & V_224 ) ;
V_238 = F_128 ( T_9 , V_238 , V_101 ) ;
V_71:
F_75 ( V_7 ) ;
return V_238 ;
}
static void F_166 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_27 ( V_36 ) ;
F_50 ( ! ( F_167 ( & V_7 -> V_49 ) ) ) ;
F_110 ( V_7 ) ;
F_168 ( V_7 -> V_70 ) ;
F_169 ( V_36 ) ;
}
static void F_170 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_27 ( V_36 ) ;
V_7 -> V_43 = V_244 ;
V_7 -> V_45 = V_245 ;
V_36 -> V_246 = & V_247 ;
V_36 -> V_248 = F_166 ;
}
static int F_171 ( struct V_249 * V_250 [] , struct V_249 * V_21 [] )
{
return - V_72 ;
}
static void F_172 ( struct V_139 * V_55 )
{
struct V_28 * V_29 ;
T_11 * V_251 ;
if ( ! F_118 ( V_55 ) )
return;
if ( ! F_173 ( V_141 , & V_55 -> V_142 -> V_57 ) )
return;
V_251 = F_174 ( V_55 ) ;
if ( V_251 && F_175 ( V_251 ) )
F_176 ( V_251 , V_143 |
V_144 | V_252 ) ;
V_29 = F_177 ( V_55 , struct V_28 , V_55 ) ;
F_99 ( & V_29 -> V_106 , V_107 , V_253 ) ;
}
static int F_178 ( struct V_217 * V_218 , struct V_62 * V_139 ,
struct V_254 * V_255 , T_8 V_172 )
{
int V_238 ;
struct V_28 * V_29 = F_177 ( V_139 , struct V_28 , V_62 ) ;
struct V_6 * V_7 = F_71 ( V_29 ) ;
if ( ! V_7 )
return - V_222 ;
V_238 = F_134 ( V_7 , V_29 , V_255 -> V_170 , V_255 -> V_256 , V_172 ,
V_255 -> V_257 , V_255 -> V_258 & V_259 ) ;
F_75 ( V_7 ) ;
return V_238 ;
}
static int F_179 ( struct V_217 * V_218 , struct V_62 * V_139 ,
struct V_254 * V_255 , T_8 V_172 ,
int V_57 )
{
struct V_28 * V_29 = F_177 ( V_139 , struct V_28 , V_62 ) ;
struct V_6 * V_7 = F_71 ( V_29 ) ;
int V_238 ;
if ( ! V_7 )
return - V_222 ;
if ( V_57 & ~ ( V_259 | V_260 ) ) {
V_238 = - V_72 ;
goto V_71;
}
V_238 = F_158 ( V_7 , V_29 , V_218 , V_255 -> V_256 , V_172 ,
V_57 & V_259 ) ;
if ( V_238 > V_172 ) {
V_255 -> V_258 |= V_260 ;
V_238 = V_57 & V_260 ? V_238 : V_172 ;
}
V_71:
F_75 ( V_7 ) ;
return V_238 ;
}
static int F_180 ( struct V_62 * V_139 )
{
if ( V_139 -> V_55 )
F_52 ( V_139 -> V_55 ) ;
return 0 ;
}
static int F_181 ( struct V_6 * V_7 )
{
int V_57 = 0 ;
if ( V_7 -> V_57 & V_125 )
V_57 |= V_261 ;
else
V_57 |= V_262 ;
if ( V_7 -> V_57 & V_181 )
V_57 |= V_263 ;
if ( V_7 -> V_57 & V_264 )
V_57 |= V_265 ;
if ( V_7 -> V_57 & V_182 )
V_57 |= V_266 ;
if ( V_7 -> V_57 & V_74 )
V_57 |= V_267 ;
return V_57 ;
}
static T_9 F_182 ( struct V_268 * V_36 , struct V_269 * V_270 ,
char * V_271 )
{
struct V_6 * V_7 = F_27 ( F_183 ( V_36 ) ) ;
return sprintf ( V_271 , L_12 , F_181 ( V_7 ) ) ;
}
static T_9 F_184 ( struct V_268 * V_36 , struct V_269 * V_270 ,
char * V_271 )
{
struct V_6 * V_7 = F_27 ( F_183 ( V_36 ) ) ;
return F_36 ( V_7 -> V_43 ) ?
sprintf ( V_271 , L_13 ,
F_185 ( F_186 () , V_7 -> V_43 ) ) :
sprintf ( V_271 , L_14 ) ;
}
static T_9 F_187 ( struct V_268 * V_36 , struct V_269 * V_270 ,
char * V_271 )
{
struct V_6 * V_7 = F_27 ( F_183 ( V_36 ) ) ;
return F_38 ( V_7 -> V_45 ) ?
sprintf ( V_271 , L_13 ,
F_188 ( F_186 () , V_7 -> V_45 ) ) :
sprintf ( V_271 , L_14 ) ;
}
static int F_189 ( struct V_42 * V_42 , struct V_67 * V_67 , struct V_272 * V_273 )
{
struct V_6 * V_7 ;
struct V_28 * V_29 = V_67 -> V_68 ;
struct V_35 * V_36 ;
int V_69 ;
if ( V_29 -> V_32 )
return - V_72 ;
V_36 = F_190 ( V_42 , V_273 -> V_274 ) ;
if ( V_36 ) {
if ( V_273 -> V_275 & V_276 )
return - V_73 ;
if ( ( V_273 -> V_275 & V_261 ) && V_36 -> V_126 == & V_127 )
V_7 = F_27 ( V_36 ) ;
else if ( ( V_273 -> V_275 & V_262 ) && V_36 -> V_126 == & V_135 )
V_7 = F_27 ( V_36 ) ;
else
return - V_72 ;
if ( ! ! ( V_273 -> V_275 & V_267 ) !=
! ! ( V_7 -> V_57 & V_74 ) )
return - V_72 ;
if ( F_33 ( V_7 ) )
return - V_277 ;
V_69 = F_191 ( V_7 -> V_70 ) ;
if ( V_69 < 0 )
return V_69 ;
V_69 = F_67 ( V_7 , V_67 ) ;
if ( V_69 < 0 )
return V_69 ;
if ( V_7 -> V_57 & V_74 &&
( V_7 -> V_31 + V_7 -> V_50 > 1 ) ) {
return 0 ;
}
}
else {
char * V_278 ;
unsigned long V_57 = 0 ;
int V_279 = V_273 -> V_275 & V_267 ?
V_76 : 1 ;
if ( ! F_40 ( V_42 -> V_46 , V_47 ) )
return - V_277 ;
V_69 = F_192 () ;
if ( V_69 < 0 )
return V_69 ;
if ( V_273 -> V_275 & V_261 ) {
V_57 |= V_125 ;
V_278 = L_15 ;
} else if ( V_273 -> V_275 & V_262 ) {
V_57 |= V_134 ;
V_278 = L_16 ;
} else
return - V_72 ;
if ( * V_273 -> V_274 )
V_278 = V_273 -> V_274 ;
V_36 = F_193 ( sizeof( struct V_6 ) , V_278 ,
F_170 , V_279 , V_279 ) ;
if ( ! V_36 )
return - V_92 ;
F_194 ( V_36 , V_42 ) ;
V_36 -> V_280 = & V_281 ;
V_7 = F_27 ( V_36 ) ;
V_7 -> V_36 = V_36 ;
V_7 -> V_57 = V_57 ;
V_7 -> V_102 . V_25 = 0 ;
V_7 -> V_183 = sizeof( struct V_177 ) ;
V_7 -> V_77 = false ;
V_7 -> V_282 = V_29 -> V_62 . V_55 -> V_283 ;
F_195 ( & V_7 -> V_17 ) ;
V_69 = F_196 ( & V_7 -> V_70 ) ;
if ( V_69 < 0 )
goto V_284;
F_112 ( V_36 ) ;
V_69 = F_107 ( V_7 ) ;
if ( V_69 < 0 )
goto V_284;
V_36 -> V_285 = V_286 | V_287 |
V_122 ;
V_36 -> V_120 = V_36 -> V_285 ;
V_36 -> V_288 = V_36 -> V_120 ;
F_197 ( & V_7 -> V_49 ) ;
V_69 = F_67 ( V_7 , V_67 ) ;
if ( V_69 < 0 )
goto V_284;
V_69 = F_198 ( V_7 -> V_36 ) ;
if ( V_69 < 0 )
goto V_284;
if ( F_199 ( & V_7 -> V_36 -> V_36 , & V_289 ) ||
F_199 ( & V_7 -> V_36 -> V_36 , & V_290 ) ||
F_199 ( & V_7 -> V_36 -> V_36 , & V_291 ) )
F_152 ( L_17 ) ;
}
F_200 ( V_7 -> V_36 ) ;
F_6 ( V_10 , V_7 , L_18 ) ;
if ( V_273 -> V_275 & V_263 )
V_7 -> V_57 |= V_181 ;
else
V_7 -> V_57 &= ~ V_181 ;
if ( V_273 -> V_275 & V_265 )
V_7 -> V_57 |= V_264 ;
else
V_7 -> V_57 &= ~ V_264 ;
if ( V_273 -> V_275 & V_266 )
V_7 -> V_57 |= V_182 ;
else
V_7 -> V_57 &= ~ V_182 ;
if ( V_273 -> V_275 & V_267 )
V_7 -> V_57 |= V_74 ;
else
V_7 -> V_57 &= ~ V_74 ;
if ( F_201 ( V_7 -> V_36 ) )
F_202 ( V_7 -> V_36 ) ;
strcpy ( V_273 -> V_274 , V_7 -> V_36 -> V_278 ) ;
return 0 ;
V_284:
F_169 ( V_36 ) ;
return V_69 ;
}
static void F_203 ( struct V_42 * V_42 , struct V_6 * V_7 ,
struct V_272 * V_273 )
{
F_6 ( V_10 , V_7 , L_19 ) ;
strcpy ( V_273 -> V_274 , V_7 -> V_36 -> V_278 ) ;
V_273 -> V_275 = F_181 ( V_7 ) ;
}
static int F_204 ( struct V_6 * V_7 , unsigned long V_84 )
{
T_6 V_120 = 0 ;
if ( V_84 & V_292 ) {
V_120 |= V_293 ;
V_84 &= ~ V_292 ;
if ( V_84 & ( V_294 | V_295 ) ) {
if ( V_84 & V_296 ) {
V_120 |= V_297 ;
V_84 &= ~ V_296 ;
}
if ( V_84 & V_294 )
V_120 |= V_298 ;
if ( V_84 & V_295 )
V_120 |= V_299 ;
V_84 &= ~ ( V_294 | V_295 ) ;
}
if ( V_84 & V_300 ) {
V_120 |= V_301 ;
V_84 &= ~ V_300 ;
}
}
if ( V_84 )
return - V_72 ;
V_7 -> V_121 = V_120 ;
F_205 ( V_7 -> V_36 ) ;
return 0 ;
}
static void F_206 ( struct V_6 * V_7 , int V_20 )
{
int V_16 ;
struct V_28 * V_29 ;
for ( V_16 = 0 ; V_16 < V_20 ; V_16 ++ ) {
V_29 = F_49 ( V_7 -> V_54 [ V_16 ] ) ;
F_207 ( V_29 -> V_62 . V_55 ) ;
}
V_7 -> V_77 = false ;
}
static int F_208 ( struct V_6 * V_7 )
{
int V_16 , V_238 = 0 ;
struct V_28 * V_29 ;
for ( V_16 = 0 ; V_16 < V_7 -> V_31 ; V_16 ++ ) {
V_29 = F_49 ( V_7 -> V_54 [ V_16 ] ) ;
V_238 = F_69 ( & V_7 -> V_78 , V_29 -> V_62 . V_55 ) ;
if ( V_238 ) {
F_206 ( V_7 , V_16 ) ;
return V_238 ;
}
}
V_7 -> V_77 = true ;
return V_238 ;
}
static void F_209 ( struct V_6 * V_7 )
{
struct V_28 * V_29 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_7 -> V_31 ; V_16 ++ ) {
V_29 = F_49 ( V_7 -> V_54 [ V_16 ] ) ;
V_29 -> V_62 . V_55 -> V_283 = V_7 -> V_282 ;
}
}
static int F_210 ( struct V_67 * V_67 , struct V_272 * V_273 )
{
struct V_28 * V_29 = V_67 -> V_68 ;
struct V_6 * V_7 ;
int V_238 = 0 ;
F_60 () ;
if ( V_273 -> V_275 & V_302 ) {
V_7 = V_29 -> V_32 ;
if ( ! V_7 ) {
V_238 = - V_72 ;
goto V_33;
}
V_238 = F_211 ( V_7 -> V_70 ) ;
if ( V_238 < 0 )
goto V_33;
V_238 = F_67 ( V_7 , V_67 ) ;
} else if ( V_273 -> V_275 & V_303 ) {
V_7 = F_49 ( V_29 -> V_7 ) ;
if ( ! V_7 || ! ( V_7 -> V_57 & V_74 ) || V_29 -> V_32 )
V_238 = - V_72 ;
else
F_48 ( V_29 , false ) ;
} else
V_238 = - V_72 ;
V_33:
F_61 () ;
return V_238 ;
}
static long F_212 ( struct V_67 * V_67 , unsigned int V_304 ,
unsigned long V_84 , int V_305 )
{
struct V_28 * V_29 = V_67 -> V_68 ;
struct V_6 * V_7 ;
void T_4 * V_306 = ( void T_4 * ) V_84 ;
struct V_272 V_273 ;
T_12 V_43 ;
T_13 V_45 ;
int V_282 ;
int V_183 ;
int V_238 ;
if ( V_304 == V_307 || V_304 == V_308 || F_213 ( V_304 ) == 0x89 ) {
if ( F_81 ( & V_273 , V_306 , V_305 ) )
return - V_90 ;
} else {
memset ( & V_273 , 0 , sizeof( V_273 ) ) ;
}
if ( V_304 == V_309 ) {
return F_214 ( V_261 | V_262 | V_263 | V_265 |
V_266 | V_267 ,
( unsigned int T_4 * ) V_306 ) ;
} else if ( V_304 == V_308 )
return F_210 ( V_67 , & V_273 ) ;
V_238 = 0 ;
F_60 () ;
V_7 = F_71 ( V_29 ) ;
if ( V_304 == V_307 && ! V_7 ) {
V_273 . V_274 [ V_310 - 1 ] = '\0' ;
V_238 = F_189 ( V_29 -> V_42 , V_67 , & V_273 ) ;
if ( V_238 )
goto V_33;
if ( F_215 ( V_306 , & V_273 , V_305 ) )
V_238 = - V_90 ;
goto V_33;
}
V_238 = - V_222 ;
if ( ! V_7 )
goto V_33;
F_6 ( V_10 , V_7 , L_20 , V_304 ) ;
V_238 = 0 ;
switch ( V_304 ) {
case V_311 :
F_203 ( V_237 -> V_312 -> V_313 , V_7 , & V_273 ) ;
if ( F_215 ( V_306 , & V_273 , V_305 ) )
V_238 = - V_90 ;
break;
case V_314 :
F_6 ( V_10 , V_7 , L_21 ,
V_84 ? L_22 : L_23 ) ;
break;
case V_315 :
if ( V_84 && ! ( V_7 -> V_57 & V_58 ) ) {
V_7 -> V_57 |= V_58 ;
F_216 ( V_66 ) ;
}
if ( ! V_84 && ( V_7 -> V_57 & V_58 ) ) {
V_7 -> V_57 &= ~ V_58 ;
F_66 ( V_66 ) ;
}
F_6 ( V_10 , V_7 , L_24 ,
V_84 ? L_23 : L_22 ) ;
break;
case V_316 :
V_43 = F_217 ( F_186 () , V_84 ) ;
if ( ! F_36 ( V_43 ) ) {
V_238 = - V_72 ;
break;
}
V_7 -> V_43 = V_43 ;
F_6 ( V_10 , V_7 , L_25 ,
F_218 ( & V_317 , V_7 -> V_43 ) ) ;
break;
case V_318 :
V_45 = F_219 ( F_186 () , V_84 ) ;
if ( ! F_38 ( V_45 ) ) {
V_238 = - V_72 ;
break;
}
V_7 -> V_45 = V_45 ;
F_6 ( V_10 , V_7 , L_26 ,
F_220 ( & V_317 , V_7 -> V_45 ) ) ;
break;
case V_319 :
if ( V_7 -> V_36 -> V_57 & V_320 ) {
F_6 ( V_10 , V_7 ,
L_27 ) ;
V_238 = - V_73 ;
} else {
V_7 -> V_36 -> type = ( int ) V_84 ;
F_6 ( V_10 , V_7 , L_28 ,
V_7 -> V_36 -> type ) ;
V_238 = 0 ;
}
break;
#ifdef F_221
case V_321 :
V_7 -> V_322 = V_84 ;
break;
#endif
case V_323 :
V_238 = F_204 ( V_7 , V_84 ) ;
break;
case V_324 :
V_238 = - V_72 ;
if ( ( V_7 -> V_57 & V_124 ) != V_134 )
break;
V_238 = F_80 ( & V_7 -> V_102 , ( void T_4 * ) V_84 ) ;
break;
case V_325 :
memcpy ( V_273 . V_326 . V_327 , V_7 -> V_36 -> V_328 , V_81 ) ;
V_273 . V_326 . V_329 = V_7 -> V_36 -> type ;
if ( F_215 ( V_306 , & V_273 , V_305 ) )
V_238 = - V_90 ;
break;
case V_330 :
F_6 ( V_331 , V_7 , L_29 ,
V_273 . V_326 . V_327 ) ;
V_238 = F_222 ( V_7 -> V_36 , & V_273 . V_326 ) ;
break;
case V_332 :
V_282 = V_29 -> V_62 . V_55 -> V_283 ;
if ( F_215 ( V_306 , & V_282 , sizeof( V_282 ) ) )
V_238 = - V_90 ;
break;
case V_333 :
if ( F_81 ( & V_282 , V_306 , sizeof( V_282 ) ) ) {
V_238 = - V_90 ;
break;
}
V_7 -> V_282 = V_282 ;
F_209 ( V_7 ) ;
break;
case V_334 :
V_183 = V_7 -> V_183 ;
if ( F_215 ( V_306 , & V_183 , sizeof( V_183 ) ) )
V_238 = - V_90 ;
break;
case V_335 :
if ( F_81 ( & V_183 , V_306 , sizeof( V_183 ) ) ) {
V_238 = - V_90 ;
break;
}
if ( V_183 < ( int ) sizeof( struct V_177 ) ) {
V_238 = - V_72 ;
break;
}
V_7 -> V_183 = V_183 ;
break;
case V_336 :
V_238 = - V_72 ;
if ( ( V_7 -> V_57 & V_124 ) != V_134 )
break;
V_238 = - V_90 ;
if ( F_81 ( & V_7 -> V_78 , V_306 , sizeof( V_7 -> V_78 ) ) )
break;
V_238 = F_208 ( V_7 ) ;
break;
case V_337 :
V_238 = - V_72 ;
if ( ( V_7 -> V_57 & V_124 ) != V_134 )
break;
V_238 = 0 ;
F_206 ( V_7 , V_7 -> V_31 ) ;
break;
default:
V_238 = - V_72 ;
break;
}
V_33:
F_61 () ;
if ( V_7 )
F_75 ( V_7 ) ;
return V_238 ;
}
static long F_223 ( struct V_67 * V_67 ,
unsigned int V_304 , unsigned long V_84 )
{
return F_212 ( V_67 , V_304 , V_84 , sizeof ( struct V_272 ) ) ;
}
static long F_224 ( struct V_67 * V_67 ,
unsigned int V_304 , unsigned long V_84 )
{
switch ( V_304 ) {
case V_307 :
case V_311 :
case V_324 :
case V_332 :
case V_333 :
case V_325 :
case V_330 :
V_84 = ( unsigned long ) F_225 ( V_84 ) ;
break;
default:
V_84 = ( V_338 ) V_84 ;
break;
}
return F_212 ( V_67 , V_304 , V_84 , sizeof( struct V_339 ) ) ;
}
static int F_226 ( int V_340 , struct V_67 * V_67 , int V_341 )
{
struct V_28 * V_29 = V_67 -> V_68 ;
int V_238 ;
if ( ( V_238 = F_227 ( V_340 , V_67 , V_341 , & V_29 -> V_106 ) ) < 0 )
goto V_71;
if ( V_341 ) {
V_238 = F_228 ( V_67 , F_229 ( V_237 ) , V_342 , 0 ) ;
if ( V_238 )
goto V_71;
V_29 -> V_57 |= V_105 ;
} else
V_29 -> V_57 &= ~ V_105 ;
V_238 = 0 ;
V_71:
return V_238 ;
}
static int F_230 ( struct V_343 * V_343 , struct V_67 * V_67 )
{
struct V_28 * V_29 ;
F_231 ( V_10 , L_30 ) ;
V_29 = (struct V_28 * ) F_232 ( & V_344 , V_345 , V_91 ,
& V_346 ) ;
if ( ! V_29 )
return - V_92 ;
F_51 ( V_29 -> V_7 , NULL ) ;
V_29 -> V_42 = F_233 ( V_237 -> V_312 -> V_313 ) ;
V_29 -> V_57 = 0 ;
F_51 ( V_29 -> V_62 . V_64 , & V_29 -> V_64 ) ;
F_234 ( & V_29 -> V_64 . V_65 ) ;
V_29 -> V_62 . V_67 = V_67 ;
V_29 -> V_62 . V_347 = & V_348 ;
F_235 ( & V_29 -> V_62 , & V_29 -> V_55 ) ;
F_236 ( & V_29 -> V_55 , V_29 -> V_42 ) ;
V_29 -> V_55 . V_349 = F_172 ;
V_29 -> V_55 . V_283 = V_350 ;
V_67 -> V_68 = V_29 ;
F_237 ( V_61 , & V_29 -> V_62 . V_57 ) ;
F_197 ( & V_29 -> V_48 ) ;
F_238 ( & V_29 -> V_55 , V_351 ) ;
return 0 ;
}
static int F_239 ( struct V_343 * V_343 , struct V_67 * V_67 )
{
struct V_28 * V_29 = V_67 -> V_68 ;
struct V_42 * V_42 = V_29 -> V_42 ;
F_59 ( V_29 , true ) ;
F_240 ( V_42 ) ;
return 0 ;
}
static int F_241 ( struct V_35 * V_36 , struct V_352 * V_304 )
{
V_304 -> V_353 = 0 ;
V_304 -> V_354 = 0 ;
F_242 ( V_304 , V_355 ) ;
V_304 -> V_356 = V_357 ;
V_304 -> V_358 = V_359 ;
V_304 -> V_360 = 0 ;
V_304 -> V_361 = V_362 ;
V_304 -> V_363 = V_364 ;
V_304 -> V_365 = 0 ;
V_304 -> V_366 = 0 ;
return 0 ;
}
static void F_243 ( struct V_35 * V_36 , struct V_367 * V_368 )
{
struct V_6 * V_7 = F_27 ( V_36 ) ;
F_244 ( V_368 -> V_369 , V_370 , sizeof( V_368 -> V_369 ) ) ;
F_244 ( V_368 -> V_371 , V_372 , sizeof( V_368 -> V_371 ) ) ;
switch ( V_7 -> V_57 & V_124 ) {
case V_125 :
F_244 ( V_368 -> V_373 , L_31 , sizeof( V_368 -> V_373 ) ) ;
break;
case V_134 :
F_244 ( V_368 -> V_373 , L_32 , sizeof( V_368 -> V_373 ) ) ;
break;
}
}
static T_1 F_245 ( struct V_35 * V_36 )
{
#ifdef F_221
struct V_6 * V_7 = F_27 ( V_36 ) ;
return V_7 -> V_322 ;
#else
return - V_374 ;
#endif
}
static void F_246 ( struct V_35 * V_36 , T_1 V_375 )
{
#ifdef F_221
struct V_6 * V_7 = F_27 ( V_36 ) ;
V_7 -> V_322 = V_375 ;
#endif
}
static int T_14 F_247 ( void )
{
int V_238 = 0 ;
F_248 ( L_33 , V_376 , V_372 ) ;
F_248 ( L_34 , V_377 ) ;
V_238 = F_249 ( & V_281 ) ;
if ( V_238 ) {
F_152 ( L_35 ) ;
goto V_378;
}
V_238 = F_250 ( & V_379 ) ;
if ( V_238 ) {
F_152 ( L_36 , V_380 ) ;
goto V_381;
}
return 0 ;
V_381:
F_251 ( & V_281 ) ;
V_378:
return V_238 ;
}
static void F_252 ( void )
{
F_253 ( & V_379 ) ;
F_251 ( & V_281 ) ;
}
struct V_62 * F_254 ( struct V_67 * V_67 )
{
struct V_28 * V_29 ;
if ( V_67 -> V_382 != & V_383 )
return F_122 ( - V_72 ) ;
V_29 = V_67 -> V_68 ;
if ( ! V_29 )
return F_122 ( - V_222 ) ;
return & V_29 -> V_62 ;
}
