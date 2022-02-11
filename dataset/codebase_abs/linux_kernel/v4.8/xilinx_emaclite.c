static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_2 -> V_4 + V_5 ) ;
F_3 ( V_3 | V_6 ,
V_2 -> V_4 + V_5 ) ;
F_3 ( V_7 , V_2 -> V_4 + V_8 ) ;
F_3 ( V_9 , V_2 -> V_4 + V_10 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_3 ( V_9 , V_2 -> V_4 + V_10 ) ;
V_3 = F_2 ( V_2 -> V_4 + V_5 ) ;
F_3 ( V_3 & ( ~ V_6 ) ,
V_2 -> V_4 + V_5 ) ;
V_3 = F_2 ( V_2 -> V_4 + V_8 ) ;
F_3 ( V_3 & ( ~ V_7 ) ,
V_2 -> V_4 + V_8 ) ;
}
static void F_5 ( void * V_11 , T_1 * V_12 ,
unsigned V_13 )
{
T_1 V_14 ;
T_1 * V_15 ;
T_2 * V_16 , * V_17 ;
V_15 = V_12 ;
V_16 = V_11 ;
V_14 = 0 ;
for (; V_13 > 3 ; V_13 -= 4 ) {
V_17 = ( T_2 * ) & V_14 ;
* V_17 ++ = * V_16 ++ ;
* V_17 ++ = * V_16 ++ ;
F_6 () ;
* V_15 ++ = V_14 ;
}
if ( V_13 ) {
T_3 * V_18 , * V_19 ;
V_14 = 0 ;
V_19 = ( T_3 * ) & V_14 ;
V_18 = ( T_3 * ) V_16 ;
for (; V_13 > 0 ; V_13 -- )
* V_19 ++ = * V_18 ++ ;
F_6 () ;
* V_15 = V_14 ;
}
}
static void F_7 ( T_1 * V_11 , T_3 * V_12 ,
unsigned V_13 )
{
T_2 * V_17 , * V_16 ;
T_1 * V_20 ;
T_1 V_14 ;
V_20 = V_11 ;
V_17 = ( T_2 * ) V_12 ;
for (; V_13 > 3 ; V_13 -= 4 ) {
V_14 = * V_20 ++ ;
V_16 = ( T_2 * ) & V_14 ;
* V_17 ++ = * V_16 ++ ;
* V_17 ++ = * V_16 ++ ;
}
if ( V_13 ) {
T_3 * V_19 , * V_18 ;
V_19 = ( T_3 * ) V_17 ;
V_14 = * V_20 ++ ;
V_18 = ( T_3 * ) & V_14 ;
for (; V_13 > 0 ; V_13 -- )
* V_19 = * V_18 ;
}
}
static int F_8 ( struct V_1 * V_2 , T_3 * V_21 ,
unsigned int V_22 )
{
T_1 V_3 ;
void T_4 * V_23 ;
V_23 = V_2 -> V_4 + V_2 -> V_24 ;
if ( V_22 > V_25 )
V_22 = V_25 ;
V_3 = F_2 ( V_23 + V_5 ) ;
if ( ( V_3 & ( V_26 |
V_27 ) ) == 0 ) {
if ( V_2 -> V_28 != 0 )
V_2 -> V_24 ^= V_29 ;
} else if ( V_2 -> V_28 != 0 ) {
V_23 = ( void T_4 V_30 * ) ( ( T_1 V_30 ) V_23 ^
V_29 ) ;
V_3 = F_2 ( V_23 + V_5 ) ;
if ( ( V_3 & ( V_26 |
V_27 ) ) != 0 )
return - 1 ;
} else
return - 1 ;
F_5 ( V_21 , ( T_1 V_30 * ) V_23 , V_22 ) ;
F_3 ( ( V_22 & V_31 ) ,
V_23 + V_32 ) ;
V_3 = F_2 ( V_23 + V_5 ) ;
V_3 |= ( V_26 | V_27 ) ;
F_3 ( V_3 , V_23 + V_5 ) ;
return 0 ;
}
static T_2 F_9 ( struct V_1 * V_2 , T_3 * V_21 )
{
void T_4 * V_23 ;
T_2 V_13 , V_33 ;
T_1 V_3 ;
V_23 = ( V_2 -> V_4 + V_2 -> V_34 ) ;
V_3 = F_2 ( V_23 + V_8 ) ;
if ( ( V_3 & V_35 ) == V_35 ) {
if ( V_2 -> V_36 != 0 )
V_2 -> V_34 ^= V_29 ;
} else {
if ( V_2 -> V_36 != 0 )
V_23 = ( void T_4 V_30 * ) ( ( T_1 V_30 ) V_23 ^
V_29 ) ;
else
return 0 ;
V_3 = F_2 ( V_23 + V_8 ) ;
if ( ( V_3 & V_35 ) !=
V_35 )
return 0 ;
}
V_33 = ( ( F_10 ( F_2 ( V_23 + V_37 +
V_38 ) ) >> V_39 ) &
V_40 ) ;
if ( V_33 > ( V_25 + V_41 ) ) {
if ( V_33 == V_42 ) {
V_13 = ( ( F_10 ( F_2 ( V_23 +
V_43 +
V_38 ) ) >>
V_39 ) &
V_40 ) ;
V_13 += V_44 + V_41 ;
} else if ( V_33 == V_45 )
V_13 = V_46 + V_44 + V_41 ;
else
V_13 = V_25 + V_41 ;
} else
V_13 = V_33 + V_44 + V_41 ;
F_7 ( ( T_1 V_30 * ) ( V_23 + V_38 ) ,
V_21 , V_13 ) ;
V_3 = F_2 ( V_23 + V_8 ) ;
V_3 &= ~ V_35 ;
F_3 ( V_3 , V_23 + V_8 ) ;
return V_13 ;
}
static void F_11 ( struct V_1 * V_2 ,
T_3 * V_47 )
{
void T_4 * V_23 ;
T_1 V_3 ;
V_23 = V_2 -> V_4 + V_2 -> V_24 ;
F_5 ( V_47 , ( T_1 V_30 * ) V_23 , V_48 ) ;
F_3 ( V_48 , V_23 + V_32 ) ;
V_3 = F_2 ( V_23 + V_5 ) ;
F_3 ( V_3 | V_49 , V_23 + V_5 ) ;
while ( ( F_2 ( V_23 + V_5 ) &
V_49 ) != 0 )
;
}
static int F_12 ( struct V_50 * V_51 , void * V_52 )
{
struct V_1 * V_53 = F_13 ( V_51 ) ;
struct V_54 * V_23 = V_52 ;
if ( F_14 ( V_51 ) )
return - V_55 ;
memcpy ( V_51 -> V_56 , V_23 -> V_57 , V_51 -> V_58 ) ;
F_11 ( V_53 , V_51 -> V_56 ) ;
return 0 ;
}
static void F_15 ( struct V_50 * V_51 )
{
struct V_1 * V_53 = F_13 ( V_51 ) ;
unsigned long V_59 ;
F_16 ( & V_53 -> V_60 -> V_51 , L_1 ,
V_61 * 1000UL / V_62 ) ;
V_51 -> V_63 . V_64 ++ ;
F_17 ( & V_53 -> V_65 , V_59 ) ;
F_18 ( V_51 ) ;
F_4 ( V_53 ) ;
F_1 ( V_53 ) ;
if ( V_53 -> V_66 ) {
F_19 ( V_53 -> V_66 ) ;
V_53 -> V_66 = NULL ;
V_51 -> V_63 . V_64 ++ ;
}
F_20 ( V_51 ) ;
F_21 ( V_51 ) ;
F_22 ( & V_53 -> V_65 , V_59 ) ;
}
static void F_23 ( struct V_50 * V_51 )
{
struct V_1 * V_53 = F_13 ( V_51 ) ;
V_51 -> V_63 . V_67 ++ ;
if ( V_53 -> V_66 ) {
if ( F_8 ( V_53 ,
( T_3 * ) V_53 -> V_66 -> V_21 ,
V_53 -> V_66 -> V_68 ) != 0 )
return;
else {
V_51 -> V_63 . V_69 += V_53 -> V_66 -> V_68 ;
F_24 ( V_53 -> V_66 ) ;
V_53 -> V_66 = NULL ;
F_20 ( V_51 ) ;
F_21 ( V_51 ) ;
}
}
}
static void F_25 ( struct V_50 * V_51 )
{
struct V_1 * V_53 = F_13 ( V_51 ) ;
struct V_70 * V_71 ;
unsigned int V_72 ;
T_1 V_68 ;
V_68 = V_25 + V_41 ;
V_71 = F_26 ( V_51 , V_68 + V_73 ) ;
if ( ! V_71 ) {
V_51 -> V_63 . V_74 ++ ;
F_16 ( & V_53 -> V_60 -> V_51 , L_2 ) ;
return;
}
V_72 = F_27 ( V_71 -> V_21 ) ;
if ( V_72 )
F_28 ( V_71 , V_72 ) ;
F_28 ( V_71 , 2 ) ;
V_68 = F_9 ( V_53 , ( T_3 * ) V_71 -> V_21 ) ;
if ( ! V_68 ) {
V_51 -> V_63 . V_75 ++ ;
F_24 ( V_71 ) ;
return;
}
F_29 ( V_71 , V_68 ) ;
V_71 -> V_76 = F_30 ( V_71 , V_51 ) ;
F_31 ( V_71 ) ;
V_51 -> V_63 . V_77 ++ ;
V_51 -> V_63 . V_78 += V_68 ;
if ( ! F_32 ( V_71 ) )
F_33 ( V_71 ) ;
}
static T_5 F_34 ( int V_79 , void * V_80 )
{
bool V_81 = false ;
struct V_50 * V_51 = V_80 ;
struct V_1 * V_53 = F_13 ( V_51 ) ;
void T_4 * V_4 = V_53 -> V_4 ;
T_1 V_82 ;
if ( ( F_2 ( V_4 + V_8 ) &
V_35 ) ||
( F_2 ( V_4 + V_29 + V_8 )
& V_35 ) )
F_25 ( V_51 ) ;
V_82 = F_2 ( V_4 + V_5 ) ;
if ( ( ( V_82 & V_26 ) == 0 ) &&
( V_82 & V_27 ) != 0 ) {
V_82 &= ~ V_27 ;
F_3 ( V_82 , V_4 + V_5 ) ;
V_81 = true ;
}
V_82 = F_2 ( V_4 + V_29 + V_5 ) ;
if ( ( ( V_82 & V_26 ) == 0 ) &&
( V_82 & V_27 ) != 0 ) {
V_82 &= ~ V_27 ;
F_3 ( V_82 , V_4 + V_29 +
V_5 ) ;
V_81 = true ;
}
if ( V_81 != 0 )
F_23 ( V_51 ) ;
return V_83 ;
}
static int F_35 ( struct V_1 * V_53 )
{
unsigned long V_84 = V_85 + 2 ;
while ( F_2 ( V_53 -> V_4 + V_86 ) &
V_87 ) {
if ( F_36 ( V_84 , V_85 ) ) {
F_37 ( 1 ) ;
return - V_88 ;
}
F_38 ( 1 ) ;
}
return 0 ;
}
static int F_39 ( struct V_89 * V_90 , int V_91 , int V_92 )
{
struct V_1 * V_53 = V_90 -> V_93 ;
T_1 V_94 ;
T_1 V_95 ;
if ( F_35 ( V_53 ) )
return - V_88 ;
V_94 = F_2 ( V_53 -> V_4 + V_86 ) ;
F_3 ( V_96 |
( ( V_91 << V_97 ) | V_92 ) ,
V_53 -> V_4 + V_98 ) ;
F_3 ( V_94 | V_87 ,
V_53 -> V_4 + V_86 ) ;
if ( F_35 ( V_53 ) )
return - V_88 ;
V_95 = F_2 ( V_53 -> V_4 + V_99 ) ;
F_40 ( & V_53 -> V_60 -> V_51 ,
L_3 ,
V_91 , V_92 , V_95 ) ;
return V_95 ;
}
static int F_41 ( struct V_89 * V_90 , int V_91 , int V_92 ,
T_2 V_100 )
{
struct V_1 * V_53 = V_90 -> V_93 ;
T_1 V_94 ;
F_40 ( & V_53 -> V_60 -> V_51 ,
L_4 ,
V_91 , V_92 , V_100 ) ;
if ( F_35 ( V_53 ) )
return - V_88 ;
V_94 = F_2 ( V_53 -> V_4 + V_86 ) ;
F_3 ( ~ V_96 &
( ( V_91 << V_97 ) | V_92 ) ,
V_53 -> V_4 + V_98 ) ;
F_3 ( V_100 , V_53 -> V_4 + V_101 ) ;
F_3 ( V_94 | V_87 ,
V_53 -> V_4 + V_86 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_53 , struct V_102 * V_51 )
{
struct V_89 * V_90 ;
int V_95 ;
struct V_103 V_104 ;
struct V_105 * V_106 = F_43 ( V_53 -> V_107 ) ;
struct V_105 * V_108 ;
if ( ! V_106 ) {
F_16 ( V_51 , L_5 ) ;
return - V_109 ;
}
V_108 = F_43 ( V_106 ) ;
F_44 ( V_108 , 0 , & V_104 ) ;
if ( V_53 -> V_60 -> V_110 != V_104 . V_111 ) {
struct V_112 * V_113 ;
V_113 = F_45 ( V_53 -> V_107 ) ;
if ( ! V_113 )
F_46 ( V_51 ,
L_6 ) ;
else
F_47 ( & V_113 -> V_114 . V_51 ) ;
return 0 ;
}
F_3 ( V_115 ,
V_53 -> V_4 + V_86 ) ;
V_90 = F_48 () ;
if ( ! V_90 ) {
F_16 ( V_51 , L_7 ) ;
return - V_116 ;
}
snprintf ( V_90 -> V_117 , V_118 , L_8 ,
( unsigned long long ) V_104 . V_111 ) ;
V_90 -> V_93 = V_53 ;
V_90 -> V_119 = L_9 ;
V_90 -> V_120 = F_39 ;
V_90 -> V_121 = F_41 ;
V_90 -> V_122 = V_51 ;
V_53 -> V_89 = V_90 ;
V_95 = F_49 ( V_90 , V_106 ) ;
if ( V_95 ) {
F_16 ( V_51 , L_5 ) ;
goto V_123;
}
return 0 ;
V_123:
F_50 ( V_90 ) ;
return V_95 ;
}
static void F_51 ( struct V_50 * V_60 )
{
struct V_1 * V_53 = F_13 ( V_60 ) ;
struct V_112 * V_124 = V_53 -> V_125 ;
int V_126 ;
V_126 = V_124 -> V_127 | ( V_124 -> V_128 << 1 ) | V_124 -> V_129 ;
if ( V_53 -> V_130 != V_126 ) {
V_53 -> V_130 = V_126 ;
F_52 ( V_124 ) ;
}
}
static int F_53 ( struct V_50 * V_51 )
{
struct V_1 * V_53 = F_13 ( V_51 ) ;
int V_131 ;
F_4 ( V_53 ) ;
if ( V_53 -> V_107 ) {
T_1 V_132 ;
V_53 -> V_125 = F_54 ( V_53 -> V_60 , V_53 -> V_107 ,
F_51 , 0 ,
V_133 ) ;
if ( ! V_53 -> V_125 ) {
F_16 ( & V_53 -> V_60 -> V_51 , L_10 ) ;
return - V_109 ;
}
V_53 -> V_125 -> V_134 &= ( V_135 ) ;
V_53 -> V_125 -> V_136 = V_53 -> V_125 -> V_134 ;
F_55 ( V_53 -> V_125 , V_137 , 0 ) ;
F_55 ( V_53 -> V_125 , V_138 , V_139 |
V_140 ) ;
V_132 = F_56 ( V_53 -> V_125 , V_141 ) ;
V_132 |= ( V_142 | V_143 ) ;
F_55 ( V_53 -> V_125 , V_141 , V_132 ) ;
F_57 ( V_53 -> V_125 ) ;
}
F_11 ( V_53 , V_51 -> V_56 ) ;
V_131 = F_58 ( V_51 -> V_79 , F_34 , 0 , V_51 -> V_119 , V_51 ) ;
if ( V_131 ) {
F_16 ( & V_53 -> V_60 -> V_51 , L_11 ,
V_51 -> V_79 ) ;
if ( V_53 -> V_125 )
F_59 ( V_53 -> V_125 ) ;
V_53 -> V_125 = NULL ;
return V_131 ;
}
F_1 ( V_53 ) ;
F_60 ( V_51 ) ;
return 0 ;
}
static int F_61 ( struct V_50 * V_51 )
{
struct V_1 * V_53 = F_13 ( V_51 ) ;
F_18 ( V_51 ) ;
F_4 ( V_53 ) ;
F_62 ( V_51 -> V_79 , V_51 ) ;
if ( V_53 -> V_125 )
F_59 ( V_53 -> V_125 ) ;
V_53 -> V_125 = NULL ;
return 0 ;
}
static int F_63 ( struct V_70 * V_144 , struct V_50 * V_51 )
{
struct V_1 * V_53 = F_13 ( V_51 ) ;
struct V_70 * V_145 ;
unsigned int V_68 ;
unsigned long V_59 ;
V_68 = V_144 -> V_68 ;
V_145 = V_144 ;
F_17 ( & V_53 -> V_65 , V_59 ) ;
if ( F_8 ( V_53 , ( T_3 * ) V_145 -> V_21 , V_68 ) != 0 ) {
F_18 ( V_51 ) ;
V_53 -> V_66 = V_145 ;
F_64 ( V_145 ) ;
F_22 ( & V_53 -> V_65 , V_59 ) ;
return 0 ;
}
F_22 ( & V_53 -> V_65 , V_59 ) ;
F_64 ( V_145 ) ;
V_51 -> V_63 . V_69 += V_68 ;
F_65 ( V_145 ) ;
return 0 ;
}
static void F_66 ( struct V_50 * V_60 )
{
if ( V_60 ) {
F_67 ( V_60 ) ;
}
}
static bool F_68 ( struct V_146 * V_147 , const char * V_148 )
{
T_1 * V_149 = ( T_1 * ) F_69 ( V_147 -> V_51 . V_150 , V_148 , NULL ) ;
if ( V_149 ) {
return ( bool ) * V_149 ;
} else {
F_70 ( & V_147 -> V_51 , L_12
L_13 , V_148 ) ;
return false ;
}
}
static int F_71 ( struct V_146 * V_147 )
{
struct V_103 * V_104 ;
struct V_50 * V_60 = NULL ;
struct V_1 * V_53 = NULL ;
struct V_102 * V_51 = & V_147 -> V_51 ;
const void * V_151 ;
int V_95 = 0 ;
F_46 ( V_51 , L_14 ) ;
V_60 = F_72 ( sizeof( struct V_1 ) ) ;
if ( ! V_60 )
return - V_116 ;
F_73 ( V_51 , V_60 ) ;
F_74 ( V_60 , & V_147 -> V_51 ) ;
V_53 = F_13 ( V_60 ) ;
V_53 -> V_60 = V_60 ;
V_104 = F_75 ( V_147 , V_152 , 0 ) ;
if ( ! V_104 ) {
F_16 ( V_51 , L_15 ) ;
V_95 = - V_153 ;
goto error;
}
V_60 -> V_79 = V_104 -> V_111 ;
V_104 = F_75 ( V_147 , V_154 , 0 ) ;
V_53 -> V_4 = F_76 ( & V_147 -> V_51 , V_104 ) ;
if ( F_77 ( V_53 -> V_4 ) ) {
V_95 = F_78 ( V_53 -> V_4 ) ;
goto error;
}
V_60 -> V_110 = V_104 -> V_111 ;
V_60 -> V_155 = V_104 -> V_84 ;
F_79 ( & V_53 -> V_65 ) ;
V_53 -> V_24 = 0x0 ;
V_53 -> V_34 = 0x0 ;
V_53 -> V_28 = F_68 ( V_147 , L_16 ) ;
V_53 -> V_36 = F_68 ( V_147 , L_17 ) ;
V_151 = F_80 ( V_147 -> V_51 . V_150 ) ;
if ( V_151 ) {
memcpy ( V_60 -> V_56 , V_151 , V_48 ) ;
} else {
F_70 ( V_51 , L_18 ) ;
F_81 ( V_60 ) ;
}
F_3 ( 0 , V_53 -> V_4 + V_5 ) ;
F_3 ( 0 , V_53 -> V_4 + V_29 + V_5 ) ;
F_11 ( V_53 , V_60 -> V_56 ) ;
V_53 -> V_107 = F_82 ( V_147 -> V_51 . V_150 , L_19 , 0 ) ;
V_95 = F_42 ( V_53 , & V_147 -> V_51 ) ;
if ( V_95 )
F_70 ( & V_147 -> V_51 , L_20 ) ;
F_46 ( V_51 , L_21 , V_60 -> V_56 ) ;
V_60 -> V_156 = & V_157 ;
V_60 -> V_59 &= ~ V_158 ;
V_60 -> V_159 = V_61 ;
V_95 = F_83 ( V_60 ) ;
if ( V_95 ) {
F_16 ( V_51 ,
L_22 ) ;
goto error;
}
F_46 ( V_51 ,
L_23 ,
( unsigned int V_30 ) V_60 -> V_110 ,
( unsigned int V_30 ) V_53 -> V_4 , V_60 -> V_79 ) ;
return 0 ;
error:
F_66 ( V_60 ) ;
return V_95 ;
}
static int F_84 ( struct V_146 * V_160 )
{
struct V_50 * V_60 = F_85 ( V_160 ) ;
struct V_1 * V_53 = F_13 ( V_60 ) ;
if ( V_53 -> V_161 ) {
F_86 ( V_53 -> V_89 ) ;
F_50 ( V_53 -> V_89 ) ;
V_53 -> V_89 = NULL ;
}
F_87 ( V_60 ) ;
F_88 ( V_53 -> V_107 ) ;
V_53 -> V_107 = NULL ;
F_66 ( V_60 ) ;
return 0 ;
}
static void
F_89 ( struct V_50 * V_60 )
{
F_90 ( V_60 -> V_79 ) ;
F_34 ( V_60 -> V_79 , V_60 ) ;
F_91 ( V_60 -> V_79 ) ;
}
