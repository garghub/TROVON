static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , T_1 V_5 ,
T_2 V_6 , int V_7 , int V_8 )
{
int V_9 , V_10 ;
T_3 V_11 = V_5 ;
V_4 -> V_12 [ 0 ] = F_2 ( V_2 , ( V_13 ) V_11 ) ;
V_4 -> V_14 [ 0 ] = F_2 ( V_2 , ( V_13 ) ( V_11 >> 32 ) ) ;
V_10 = 0x1000 - ( V_5 & 0x0fff ) ;
if ( F_3 ( V_6 < V_10 ) )
V_10 = V_6 ;
else {
V_5 += 0x1000 ;
V_5 &= ~ 0x0fff ;
for ( V_9 = 1 ; V_10 < V_6 && V_9 < 5 ; V_9 ++ ) {
V_11 = V_5 ;
V_4 -> V_12 [ V_9 ] = F_2 ( V_2 , ( V_13 ) V_11 ) ;
V_4 -> V_14 [ V_9 ] = F_2 ( V_2 ,
( V_13 ) ( V_11 >> 32 ) ) ;
V_5 += 0x1000 ;
if ( ( V_10 + 0x1000 ) < V_6 )
V_10 += 0x1000 ;
else
V_10 = V_6 ;
}
if ( V_10 != V_6 )
V_10 -= ( V_10 % V_8 ) ;
}
V_4 -> V_15 = F_2 ( V_2 , ( V_10 << 16 ) | V_7 ) ;
V_4 -> V_16 = V_10 ;
return V_10 ;
}
static inline void
F_4 ( struct V_1 * V_2 , struct V_17 * V_18 , struct V_3 * V_4 )
{
struct V_19 * V_20 = V_18 -> V_20 ;
F_5 ( V_18 -> V_21 != V_22 ) ;
V_20 -> V_23 = F_6 ( V_2 , V_4 -> V_24 ) ;
V_20 -> V_25 = F_7 ( V_2 ) ;
if ( ! ( V_20 -> V_26 & F_2 ( V_2 , V_27 ) ) ) {
unsigned V_28 , V_29 ;
V_28 = V_18 -> V_28 ;
V_29 = ( F_8 ( V_2 , & V_20 -> V_26 ) >> 8 ) & 0x0f ;
if ( F_9 ( ! F_10 ( V_18 -> V_30 , V_29 , V_28 ) ) ) {
V_20 -> V_15 &= ~ F_2 ( V_2 , V_31 ) ;
F_11 ( V_18 -> V_30 , V_29 , V_28 , 1 ) ;
}
}
V_20 -> V_15 &= F_2 ( V_2 , V_31 | V_32 ) ;
}
static void
F_12 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
struct V_3 * V_4 ;
V_4 = F_13 ( V_18 -> V_33 . V_34 , struct V_3 , V_33 ) ;
if ( V_18 -> V_20 -> V_15 & F_14 ( V_2 ) )
V_18 -> V_20 -> V_23 = V_4 -> V_35 ;
else
F_4 ( V_2 , V_18 , V_4 ) ;
}
static void F_15 ( struct V_36 * V_37 ,
struct V_38 * V_39 )
{
struct V_1 * V_2 = F_16 ( V_37 ) ;
struct V_17 * V_18 = V_39 -> V_40 ;
unsigned long V_41 ;
F_17 ( & V_2 -> V_42 , V_41 ) ;
V_18 -> V_43 = 0 ;
if ( V_18 -> V_21 == V_22 && ! F_18 ( & V_18 -> V_33 )
&& V_2 -> V_44 == V_45 )
F_19 ( V_2 , V_18 ) ;
F_20 ( & V_2 -> V_42 , V_41 ) ;
}
static void F_21 ( struct V_1 * V_2 , struct V_17 * V_18 ,
struct V_46 * V_46 , V_13 V_7 )
{
if ( V_46 -> V_30 -> V_47 && ! F_22 ( V_46 -> V_48 ) && ! V_18 -> V_43 ) {
#ifdef F_23
struct V_49 * V_47 = V_46 -> V_30 -> V_47 -> V_50 ;
F_24 ( & V_47 -> V_30 ,
L_1 ,
V_46 -> V_30 -> V_51 , V_46 -> V_30 -> V_52 ,
F_25 ( V_46 -> V_48 ) , V_7 ) ;
#endif
if ( ! F_26 ( V_2 )
|| V_46 -> V_30 -> V_47 -> V_50 !=
F_27 ( V_2 ) -> V_53 . V_54 ) {
if ( F_28 ( V_46 ) == 0 )
V_18 -> V_43 = 1 ;
} else {
}
}
}
static int F_29 (
struct V_1 * V_2 ,
struct V_46 * V_46 ,
T_2 V_16 ,
V_13 V_7
)
{
int V_55 = - V_56 ;
if ( F_3 ( F_30 ( V_7 ) != 2 ) )
V_46 -> V_57 += V_16 - F_31 ( V_7 ) ;
if ( F_9 ( V_46 -> V_58 ) )
return V_55 ;
if ( F_9 ( F_32 ( V_7 ) ) )
V_55 = - V_59 ;
if ( V_7 & V_60 ) {
if ( V_7 & V_61 ) {
V_55 = - V_62 ;
} else if ( F_33 ( V_7 ) ) {
V_55 = - V_63 ;
} else if ( V_7 & V_64 ) {
V_55 = - V_65 ;
} else if ( V_7 & V_66 ) {
V_55 = ( F_30 ( V_7 ) == 1 )
? - V_67
: - V_68 ;
} else if ( V_7 & V_69 ) {
F_34 ( V_2 , L_2 ,
V_46 -> V_30 -> V_70 ,
F_25 ( V_46 -> V_48 ) ,
F_35 ( V_46 -> V_48 ) ? L_3 : L_4 ) ;
V_55 = - V_65 ;
} else {
V_55 = - V_65 ;
}
F_36 ( V_2 ,
L_5 ,
F_37 ( V_46 -> V_48 ) ,
F_25 ( V_46 -> V_48 ) ,
F_35 ( V_46 -> V_48 ) ? L_3 : L_4 ,
V_7 , V_55 ) ;
}
return V_55 ;
}
static void
F_38 ( struct V_1 * V_2 , struct V_46 * V_46 , int V_55 )
__releases( V_2 -> V_42 )
__acquires( V_2 -> V_42 )
{
if ( F_39 ( V_46 -> V_48 ) == V_71 ) {
F_27 ( V_2 ) -> V_53 . V_72 -- ;
}
if ( F_9 ( V_46 -> V_58 ) ) {
F_40 ( V_2 -> V_73 . V_74 ) ;
} else {
if ( V_55 == - V_56 || V_55 == - V_59 )
V_55 = 0 ;
F_40 ( V_2 -> V_73 . V_75 ) ;
}
#ifdef F_41
F_34 ( V_2 ,
L_6 ,
V_76 , V_46 -> V_30 -> V_70 , V_46 ,
F_25 ( V_46 -> V_48 ) ,
F_35 ( V_46 -> V_48 ) ? L_3 : L_4 ,
V_55 ,
V_46 -> V_57 , V_46 -> V_77 ) ;
#endif
F_42 ( F_27 ( V_2 ) , V_46 ) ;
F_43 ( & V_2 -> V_42 ) ;
F_44 ( F_27 ( V_2 ) , V_46 , V_55 ) ;
F_45 ( & V_2 -> V_42 ) ;
}
static unsigned
F_46 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
struct V_3 * V_78 , * V_79 = V_18 -> V_80 ;
struct V_81 * V_82 , * V_83 ;
int V_84 ;
int V_85 ;
T_4 V_86 ;
struct V_19 * V_20 = V_18 -> V_20 ;
V_86 = V_18 -> V_21 ;
V_18 -> V_21 = V_87 ;
V_85 = ( V_86 == V_22 ) ;
V_88:
V_78 = NULL ;
V_84 = - V_56 ;
V_18 -> V_89 = 0 ;
F_47 (entry, tmp, &qh->qtd_list) {
struct V_3 * V_4 ;
struct V_46 * V_46 ;
V_13 V_7 = 0 ;
V_4 = F_13 ( V_82 , struct V_3 , V_33 ) ;
V_46 = V_4 -> V_46 ;
if ( V_78 ) {
if ( F_3 ( V_78 -> V_46 != V_46 ) ) {
F_38 ( V_2 , V_78 -> V_46 , V_84 ) ;
V_84 = - V_56 ;
}
F_48 ( V_2 , V_78 ) ;
V_78 = NULL ;
}
if ( V_4 == V_79 )
break;
F_49 () ;
V_7 = F_50 ( V_2 , V_4 -> V_15 ) ;
V_90:
if ( ( V_7 & V_91 ) == 0 ) {
if ( V_7 & V_66 )
F_34 ( V_2 ,
L_7 ,
V_46 ,
F_51 ( & V_46 -> V_39 -> V_92 ) ,
F_52 ( & V_46 -> V_39 -> V_92 ) ? L_3 : L_4 ,
V_46 -> V_77 ,
V_4 ,
V_18 ) ;
if ( ( V_7 & V_60 ) != 0 ) {
if ( ( V_7 & V_69 ) &&
F_33 ( V_7 ) == 0 &&
++ V_18 -> V_93 < V_94 &&
! V_46 -> V_58 ) {
F_34 ( V_2 ,
L_8 ,
V_4 -> V_16 - F_31 ( V_7 ) , V_4 -> V_16 , V_18 -> V_93 ) ;
V_7 &= ~ V_60 ;
V_7 |= V_91 |
( V_95 << 10 ) ;
V_4 -> V_15 = F_2 ( V_2 ,
V_7 ) ;
F_53 () ;
V_20 -> V_15 = F_2 ( V_2 ,
V_7 ) ;
goto V_90;
}
V_85 = 1 ;
} else if ( F_32 ( V_7 )
&& ! ( V_4 -> V_25
& F_7 ( V_2 ) ) ) {
V_85 = 1 ;
}
} else if ( F_3 ( ! V_85
&& V_2 -> V_44 >= V_45 ) ) {
break;
} else {
V_85 = 1 ;
if ( V_2 -> V_44 < V_45 )
V_84 = - V_96 ;
else if ( V_84 == - V_56 && ! V_46 -> V_58 )
continue;
if ( V_86 == V_22 &&
V_18 -> V_33 . V_34 == & V_4 -> V_33 &&
( V_20 -> V_15 & F_14 ( V_2 ) ) ) {
V_7 = F_50 ( V_2 , V_20 -> V_15 ) ;
V_20 -> V_15 &= ~ F_14 ( V_2 ) ;
F_21 ( V_2 , V_18 , V_46 , V_7 ) ;
}
}
if ( V_84 == - V_56 ) {
V_84 = F_29 ( V_2 , V_46 ,
V_4 -> V_16 , V_7 ) ;
if ( V_84 == - V_59
&& ( V_4 -> V_25
& F_7 ( V_2 ) ) )
V_84 = - V_56 ;
if ( F_9 ( V_84 != - V_56 &&
V_84 != - V_59 ) ) {
if ( V_84 != - V_63 )
F_21 ( V_2 , V_18 , V_46 ,
V_7 ) ;
}
}
if ( V_85 && V_4 -> V_33 . V_97 != & V_18 -> V_33 ) {
V_78 = F_13 ( V_4 -> V_33 . V_97 ,
struct V_3 , V_33 ) ;
V_78 -> V_35 = V_4 -> V_35 ;
}
F_54 ( & V_4 -> V_33 ) ;
V_78 = V_4 ;
V_18 -> V_93 = 0 ;
}
if ( F_3 ( V_78 != NULL ) ) {
F_38 ( V_2 , V_78 -> V_46 , V_84 ) ;
F_48 ( V_2 , V_78 ) ;
}
if ( F_9 ( V_18 -> V_89 ) ) {
if ( V_86 == V_22 )
goto V_88;
}
V_18 -> V_21 = V_86 ;
if ( V_85 != 0 || V_20 -> V_23 == F_7 ( V_2 ) )
V_18 -> V_98 = 1 ;
return V_18 -> V_98 ;
}
static void F_55 (
struct V_1 * V_2 ,
struct V_46 * V_46 ,
struct V_81 * V_33
) {
struct V_81 * V_82 , * V_99 ;
F_47 (entry, temp, qtd_list) {
struct V_3 * V_4 ;
V_4 = F_13 ( V_82 , struct V_3 , V_33 ) ;
F_54 ( & V_4 -> V_33 ) ;
F_48 ( V_2 , V_4 ) ;
}
}
static struct V_81 *
F_56 (
struct V_1 * V_2 ,
struct V_46 * V_46 ,
struct V_81 * V_100 ,
T_5 V_41
) {
struct V_3 * V_4 , * V_101 ;
T_1 V_5 ;
int V_6 , V_102 , V_8 ;
int V_103 ;
V_13 V_7 ;
int V_9 ;
struct V_104 * V_105 ;
V_4 = F_57 ( V_2 , V_41 ) ;
if ( F_9 ( ! V_4 ) )
return NULL ;
F_58 ( & V_4 -> V_33 , V_100 ) ;
V_4 -> V_46 = V_46 ;
V_7 = V_91 ;
V_7 |= ( V_95 << 10 ) ;
V_6 = V_46 -> V_77 ;
V_103 = F_35 ( V_46 -> V_48 ) ;
if ( F_59 ( V_46 -> V_48 ) ) {
F_1 ( V_2 , V_4 , V_46 -> V_106 ,
sizeof ( struct V_107 ) ,
V_7 | ( 2 << 8 ) , 8 ) ;
V_7 ^= V_31 ;
V_101 = V_4 ;
V_4 = F_57 ( V_2 , V_41 ) ;
if ( F_9 ( ! V_4 ) )
goto V_108;
V_4 -> V_46 = V_46 ;
V_101 -> V_35 = F_6 ( V_2 , V_4 -> V_24 ) ;
F_58 ( & V_4 -> V_33 , V_100 ) ;
if ( V_6 == 0 )
V_7 |= ( 1 << 8 ) ;
}
V_9 = V_46 -> V_109 ;
if ( V_6 > 0 && V_9 > 0 ) {
V_105 = V_46 -> V_105 ;
V_5 = F_60 ( V_105 ) ;
V_102 = F_61 ( int , F_62 ( V_105 ) , V_6 ) ;
} else {
V_105 = NULL ;
V_5 = V_46 -> V_110 ;
V_102 = V_6 ;
}
if ( V_103 )
V_7 |= ( 1 << 8 ) ;
V_8 = F_63 ( F_64 ( V_46 -> V_30 , V_46 -> V_48 , ! V_103 ) ) ;
for (; ; ) {
int V_111 ;
V_111 = F_1 ( V_2 , V_4 , V_5 , V_102 , V_7 ,
V_8 ) ;
V_102 -= V_111 ;
V_6 -= V_111 ;
V_5 += V_111 ;
if ( V_103 )
V_4 -> V_25 = V_2 -> V_112 -> V_20 -> V_25 ;
if ( ( V_8 & ( V_111 + ( V_8 - 1 ) ) ) == 0 )
V_7 ^= V_31 ;
if ( F_3 ( V_102 <= 0 ) ) {
if ( -- V_9 <= 0 || V_6 <= 0 )
break;
V_105 = F_65 ( V_105 ) ;
V_5 = F_60 ( V_105 ) ;
V_102 = F_61 ( int , F_62 ( V_105 ) , V_6 ) ;
}
V_101 = V_4 ;
V_4 = F_57 ( V_2 , V_41 ) ;
if ( F_9 ( ! V_4 ) )
goto V_108;
V_4 -> V_46 = V_46 ;
V_101 -> V_35 = F_6 ( V_2 , V_4 -> V_24 ) ;
F_58 ( & V_4 -> V_33 , V_100 ) ;
}
if ( F_3 ( ( V_46 -> V_113 & V_114 ) == 0
|| F_59 ( V_46 -> V_48 ) ) )
V_4 -> V_25 = F_7 ( V_2 ) ;
if ( F_3 ( V_46 -> V_77 != 0 ) ) {
int V_115 = 0 ;
if ( F_59 ( V_46 -> V_48 ) ) {
V_115 = 1 ;
V_7 ^= 0x0100 ;
V_7 |= V_31 ;
} else if ( F_66 ( V_46 -> V_48 )
&& ( V_46 -> V_113 & V_116 )
&& ! ( V_46 -> V_77 % V_8 ) ) {
V_115 = 1 ;
}
if ( V_115 ) {
V_101 = V_4 ;
V_4 = F_57 ( V_2 , V_41 ) ;
if ( F_9 ( ! V_4 ) )
goto V_108;
V_4 -> V_46 = V_46 ;
V_101 -> V_35 = F_6 ( V_2 , V_4 -> V_24 ) ;
F_58 ( & V_4 -> V_33 , V_100 ) ;
F_1 ( V_2 , V_4 , 0 , 0 , V_7 , 0 ) ;
}
}
if ( F_3 ( ! ( V_46 -> V_113 & V_117 ) ) )
V_4 -> V_15 |= F_2 ( V_2 , V_118 ) ;
return V_100 ;
V_108:
F_55 ( V_2 , V_46 , V_100 ) ;
return NULL ;
}
static struct V_17 *
F_67 (
struct V_1 * V_2 ,
struct V_46 * V_46 ,
T_5 V_41
) {
struct V_17 * V_18 = F_68 ( V_2 , V_41 ) ;
V_13 V_119 = 0 , V_120 = 0 ;
int V_103 , type ;
int V_121 = 0 ;
struct V_122 * V_47 = V_46 -> V_30 -> V_47 ;
struct V_19 * V_20 ;
if ( ! V_18 )
return V_18 ;
V_119 |= F_25 ( V_46 -> V_48 ) << 8 ;
V_119 |= F_37 ( V_46 -> V_48 ) << 0 ;
V_103 = F_35 ( V_46 -> V_48 ) ;
type = F_39 ( V_46 -> V_48 ) ;
V_121 = F_64 ( V_46 -> V_30 , V_46 -> V_48 , ! V_103 ) ;
if ( F_63 ( V_121 ) > 1024 ) {
F_34 ( V_2 , L_9 , F_63 ( V_121 ) ) ;
goto V_123;
}
if ( type == V_71 ) {
V_18 -> V_124 = F_69 ( F_70 ( V_125 ,
V_103 , 0 ,
F_71 ( V_121 ) * F_63 ( V_121 ) ) ) ;
V_18 -> V_126 = V_127 ;
if ( V_46 -> V_30 -> V_128 == V_125 ) {
V_18 -> V_129 = 0 ;
V_18 -> V_130 = 0 ;
V_18 -> V_131 = V_46 -> V_132 >> 3 ;
if ( V_18 -> V_131 == 0 && V_46 -> V_132 != 1 ) {
V_46 -> V_132 = 1 ;
} else if ( V_18 -> V_131 > V_2 -> V_133 ) {
V_18 -> V_131 = V_2 -> V_133 ;
V_46 -> V_132 = V_18 -> V_131 << 3 ;
}
} else {
int V_134 ;
V_18 -> V_130 = 1 + F_70 ( V_46 -> V_30 -> V_128 ,
V_103 , 0 , V_121 ) / ( 125 * 1000 ) ;
if ( V_103 ) {
V_18 -> V_129 = V_18 -> V_124 + F_72 ( 0 ) ;
V_18 -> V_124 = F_72 ( 1 ) ;
} else {
V_18 -> V_124 += F_72 ( 1 ) ;
V_18 -> V_129 = F_72 ( 0 ) ;
}
V_134 = V_47 ? V_47 -> V_134 : 0 ;
V_18 -> V_135 = F_69 ( V_134 +
F_70 ( V_46 -> V_30 -> V_128 ,
V_103 , 0 , F_63 ( V_121 ) ) ) ;
V_18 -> V_131 = V_46 -> V_132 ;
if ( V_18 -> V_131 > V_2 -> V_133 ) {
V_18 -> V_131 = V_2 -> V_133 ;
V_46 -> V_132 = V_18 -> V_131 ;
}
}
}
V_18 -> V_30 = V_46 -> V_30 ;
switch ( V_46 -> V_30 -> V_128 ) {
case V_136 :
V_119 |= V_137 ;
case V_138 :
if ( type != V_71 )
V_119 |= ( V_139 << 28 ) ;
if ( type == V_140 ) {
V_119 |= V_141 ;
V_119 |= V_27 ;
}
V_119 |= V_121 << 16 ;
V_120 |= ( V_142 << 30 ) ;
if ( F_73 ( V_2 ) )
V_120 |= ( V_46 -> V_30 -> V_51 - 1 ) << 23 ;
else
V_120 |= V_46 -> V_30 -> V_51 << 23 ;
if ( V_47 && V_47 -> V_50 != F_27 ( V_2 ) -> V_53 . V_54 )
V_120 |= V_47 -> V_50 -> V_52 << 16 ;
break;
case V_125 :
V_119 |= V_143 ;
if ( type == V_140 ) {
V_119 |= ( V_144 << 28 ) ;
V_119 |= 64 << 16 ;
V_119 |= V_27 ;
V_120 |= ( V_145 << 30 ) ;
} else if ( type == V_146 ) {
V_119 |= ( V_144 << 28 ) ;
V_119 |= F_63 ( V_121 ) << 16 ;
V_120 |= ( V_145 << 30 ) ;
} else {
V_119 |= F_63 ( V_121 ) << 16 ;
V_120 |= F_71 ( V_121 ) << 30 ;
}
break;
default:
F_34 ( V_2 , L_10 , V_46 -> V_30 ,
V_46 -> V_30 -> V_128 ) ;
V_123:
F_74 ( V_2 , V_18 ) ;
return NULL ;
}
V_18 -> V_21 = V_22 ;
V_20 = V_18 -> V_20 ;
V_20 -> V_26 = F_2 ( V_2 , V_119 ) ;
V_20 -> V_147 = F_2 ( V_2 , V_120 ) ;
V_18 -> V_28 = ! V_103 ;
F_11 ( V_46 -> V_30 , F_25 ( V_46 -> V_48 ) , ! V_103 , 1 ) ;
return V_18 ;
}
static void F_75 ( struct V_1 * V_2 )
{
if ( V_2 -> V_148 ++ )
return;
V_2 -> V_149 &= ~ F_76 ( V_150 ) ;
F_77 ( V_2 ) ;
F_78 ( V_2 ) ;
}
static void F_79 ( struct V_1 * V_2 )
{
if ( -- V_2 -> V_148 )
return;
F_5 ( V_2 -> V_112 -> V_151 . V_18 || ! F_18 ( & V_2 -> V_152 ) ||
! F_18 ( & V_2 -> V_153 ) ) ;
F_77 ( V_2 ) ;
}
static void F_19 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
T_6 V_154 = F_80 ( V_2 , V_18 -> V_155 ) ;
struct V_17 * V_100 ;
if ( F_9 ( V_18 -> V_43 ) )
return;
F_5 ( V_18 -> V_21 != V_22 ) ;
F_12 ( V_2 , V_18 ) ;
V_100 = V_2 -> V_112 ;
V_18 -> V_151 = V_100 -> V_151 ;
V_18 -> V_20 -> V_35 = V_100 -> V_20 -> V_35 ;
F_53 () ;
V_100 -> V_151 . V_18 = V_18 ;
V_100 -> V_20 -> V_35 = V_154 ;
V_18 -> V_21 = V_156 ;
V_18 -> V_93 = 0 ;
V_18 -> V_98 = 0 ;
F_75 ( V_2 ) ;
}
static struct V_17 * F_81 (
struct V_1 * V_2 ,
struct V_46 * V_46 ,
struct V_81 * V_33 ,
int V_29 ,
void * * V_157
)
{
struct V_17 * V_18 = NULL ;
T_6 V_158 = F_2 ( V_2 , 0x7f ) ;
V_18 = (struct V_17 * ) * V_157 ;
if ( F_9 ( V_18 == NULL ) ) {
V_18 = F_67 ( V_2 , V_46 , V_159 ) ;
* V_157 = V_18 ;
}
if ( F_3 ( V_18 != NULL ) ) {
struct V_3 * V_4 ;
if ( F_9 ( F_18 ( V_33 ) ) )
V_4 = NULL ;
else
V_4 = F_13 ( V_33 -> V_34 , struct V_3 ,
V_33 ) ;
if ( F_9 ( V_29 == 0 ) ) {
if ( F_37 ( V_46 -> V_48 ) == 0 )
V_18 -> V_20 -> V_26 &= ~ V_158 ;
}
if ( F_3 ( V_4 != NULL ) ) {
struct V_3 * V_80 ;
T_1 V_154 ;
T_6 V_7 ;
V_7 = V_4 -> V_15 ;
V_4 -> V_15 = F_82 ( V_2 ) ;
V_80 = V_18 -> V_80 ;
V_154 = V_80 -> V_24 ;
* V_80 = * V_4 ;
V_80 -> V_24 = V_154 ;
F_54 ( & V_4 -> V_33 ) ;
F_83 ( & V_80 -> V_33 , V_33 ) ;
F_84 ( V_33 , & V_18 -> V_33 ) ;
F_85 ( V_2 , V_4 , V_4 -> V_24 ) ;
V_18 -> V_80 = V_4 ;
V_154 = V_4 -> V_24 ;
V_4 = F_13 ( V_18 -> V_33 . V_97 ,
struct V_3 , V_33 ) ;
V_4 -> V_35 = F_6 ( V_2 , V_154 ) ;
F_53 () ;
V_80 -> V_15 = V_7 ;
V_46 -> V_40 = V_18 ;
}
}
return V_18 ;
}
static int
F_86 (
struct V_1 * V_2 ,
struct V_46 * V_46 ,
struct V_81 * V_33 ,
T_5 V_160
) {
int V_29 ;
unsigned long V_41 ;
struct V_17 * V_18 = NULL ;
int V_161 ;
V_29 = V_46 -> V_39 -> V_92 . V_162 ;
#ifdef F_41
{
struct V_3 * V_4 ;
V_4 = F_13 ( V_33 -> V_34 , struct V_3 , V_33 ) ;
F_34 ( V_2 ,
L_11 ,
V_76 , V_46 -> V_30 -> V_70 , V_46 ,
V_29 & 0x0f , ( V_29 & V_163 ) ? L_3 : L_4 ,
V_46 -> V_77 ,
V_4 , V_46 -> V_39 -> V_40 ) ;
}
#endif
F_17 ( & V_2 -> V_42 , V_41 ) ;
if ( F_9 ( ! F_87 ( F_27 ( V_2 ) ) ) ) {
V_161 = - V_96 ;
goto V_123;
}
V_161 = F_88 ( F_27 ( V_2 ) , V_46 ) ;
if ( F_9 ( V_161 ) )
goto V_123;
V_18 = F_81 ( V_2 , V_46 , V_33 , V_29 , & V_46 -> V_39 -> V_40 ) ;
if ( F_9 ( V_18 == NULL ) ) {
F_42 ( F_27 ( V_2 ) , V_46 ) ;
V_161 = - V_164 ;
goto V_123;
}
if ( F_3 ( V_18 -> V_21 == V_22 ) )
F_19 ( V_2 , V_18 ) ;
V_123:
F_20 ( & V_2 -> V_42 , V_41 ) ;
if ( F_9 ( V_18 == NULL ) )
F_55 ( V_2 , V_46 , V_33 ) ;
return V_161 ;
}
static void F_89 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
struct V_17 * V_97 ;
V_18 -> V_21 = V_165 ;
F_58 ( & V_18 -> V_166 , & V_2 -> V_152 ) ;
V_97 = V_2 -> V_112 ;
while ( V_97 -> V_151 . V_18 != V_18 )
V_97 = V_97 -> V_151 . V_18 ;
V_97 -> V_20 -> V_35 = V_18 -> V_20 -> V_35 ;
V_97 -> V_151 = V_18 -> V_151 ;
if ( V_2 -> V_167 == V_18 )
V_2 -> V_167 = V_18 -> V_151 . V_18 ;
}
static void F_90 ( struct V_1 * V_2 )
{
if ( V_2 -> V_168 )
return;
V_2 -> V_168 = true ;
if ( F_9 ( V_2 -> V_44 < V_45 ) ) {
F_91 ( V_2 ) ;
} else if ( F_3 ( V_2 -> V_44 == V_45 ) ) {
F_53 () ;
F_92 ( V_2 , V_2 -> V_169 | V_170 ,
& V_2 -> V_171 -> V_169 ) ;
F_93 ( V_2 , & V_2 -> V_171 -> V_169 ) ;
F_94 ( V_2 , V_172 , true ) ;
}
}
static void F_91 ( struct V_1 * V_2 )
{
struct V_17 * V_18 ;
bool V_173 ;
if ( V_2 -> V_174 )
F_92 ( V_2 , ( V_13 ) V_2 -> V_112 -> V_155 ,
& V_2 -> V_171 -> V_175 ) ;
V_2 -> V_168 = false ;
if ( F_18 ( & V_2 -> V_152 ) )
return;
V_18 = F_95 ( & V_2 -> V_152 , struct V_17 ,
V_166 ) ;
V_173 = V_2 -> V_176 ;
if ( V_2 -> V_44 < V_45 )
F_96 ( & V_2 -> V_152 , & V_2 -> V_153 ) ;
else if ( V_18 -> V_21 == V_165 ) {
V_18 -> V_21 = V_177 ;
V_173 = true ;
}
else
F_97 ( & V_18 -> V_166 , & V_2 -> V_153 ) ;
if ( ! F_18 ( & V_2 -> V_152 ) )
F_90 ( V_2 ) ;
if ( V_173 )
return;
V_2 -> V_176 = true ;
while ( ! F_18 ( & V_2 -> V_153 ) ) {
V_18 = F_95 ( & V_2 -> V_153 , struct V_17 ,
V_166 ) ;
F_54 ( & V_18 -> V_166 ) ;
V_18 -> V_21 = V_22 ;
V_18 -> V_151 . V_18 = NULL ;
if ( ! F_18 ( & V_18 -> V_33 ) )
F_46 ( V_2 , V_18 ) ;
if ( ! F_18 ( & V_18 -> V_33 ) &&
V_2 -> V_44 == V_45 )
F_19 ( V_2 , V_18 ) ;
F_79 ( V_2 ) ;
}
V_2 -> V_176 = false ;
}
static void F_98 ( struct V_1 * V_2 )
{
struct V_17 * V_18 ;
struct V_17 * V_178 = NULL ;
int V_10 = 0 ;
for ( V_18 = V_2 -> V_112 -> V_151 . V_18 ; V_18 ; V_18 = V_18 -> V_151 . V_18 ) {
if ( F_18 ( & V_18 -> V_33 ) &&
V_18 -> V_21 == V_156 ) {
++ V_10 ;
if ( V_18 -> V_179 != V_2 -> V_180 )
V_178 = V_18 ;
}
}
if ( F_18 ( & V_2 -> V_152 ) && V_178 ) {
F_99 ( V_2 , V_178 ) ;
-- V_10 ;
}
if ( V_10 > 0 ) {
F_94 ( V_2 , V_181 , true ) ;
++ V_2 -> V_180 ;
}
}
static void T_7 F_100 ( struct V_1 * V_2 )
{
struct V_17 * V_18 ;
while ( V_2 -> V_112 -> V_151 . V_18 ) {
V_18 = V_2 -> V_112 -> V_151 . V_18 ;
F_5 ( ! F_18 ( & V_18 -> V_33 ) ) ;
F_89 ( V_2 , V_18 ) ;
}
F_90 ( V_2 ) ;
}
static void F_99 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
if ( V_18 -> V_21 != V_156 )
return;
F_89 ( V_2 , V_18 ) ;
F_90 ( V_2 ) ;
}
static void F_101 ( struct V_1 * V_2 )
{
struct V_17 * V_18 ;
bool V_182 = false ;
V_2 -> V_167 = V_2 -> V_112 -> V_151 . V_18 ;
while ( V_2 -> V_167 ) {
V_18 = V_2 -> V_167 ;
V_2 -> V_167 = V_18 -> V_151 . V_18 ;
if ( ! F_18 ( & V_18 -> V_33 ) ) {
int V_99 ;
V_99 = F_46 ( V_2 , V_18 ) ;
if ( F_9 ( V_99 ) ) {
F_99 ( V_2 , V_18 ) ;
} else if ( F_18 ( & V_18 -> V_33 )
&& V_18 -> V_21 == V_156 ) {
V_18 -> V_179 = V_2 -> V_180 ;
V_182 = true ;
}
}
}
if ( V_182 && V_2 -> V_44 == V_45 &&
! ( V_2 -> V_149 &
F_76 ( V_181 ) ) ) {
F_94 ( V_2 , V_181 , true ) ;
++ V_2 -> V_180 ;
}
}
