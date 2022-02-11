static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline unsigned int F_3 ( struct V_2 * V_3 )
{
unsigned long V_4 ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_9 * V_10 = & V_5 -> V_8 -> V_11 ;
V_4 = F_4 ( V_3 , V_7 -> V_12 ) ;
return ( V_4 & V_10 -> V_13 ( V_3 -> line ) ) ? V_14 : 0 ;
}
static unsigned int F_5 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
if ( ! V_5 -> V_15 || ! V_5 -> V_16 )
goto V_17;
if ( V_5 -> V_8 -> V_18 == V_19 ) {
if ( ! ( F_4 ( V_3 , V_7 -> V_20 ) &
V_21 ) )
goto V_17;
else
goto V_22;
} else {
if ( ! F_6 ( V_5 -> V_23 ) )
goto V_17;
else
goto V_22;
}
V_22:
return V_24 | V_25 ;
V_17:
return V_24 | V_25 | V_26 ;
}
static void F_7 ( struct V_2 * V_3 , unsigned int V_27 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
unsigned int assert = V_27 & V_28 ;
unsigned int V_29 = assert ? V_30 : 0x0 ;
unsigned int V_31 ;
if ( ! V_5 -> V_15 || ! V_5 -> V_16 )
return;
if ( V_5 -> V_8 -> V_18 == V_19 ) {
V_31 = F_4 ( V_3 , V_7 -> V_20 ) & ~ 0xFF ;
V_29 |= V_31 ;
F_8 ( V_3 , V_7 -> V_20 , V_29 ) ;
} else {
if ( ! V_29 )
F_9 ( V_5 -> V_32 , 1 ) ;
else
F_9 ( V_5 -> V_32 , 0 ) ;
}
}
static void F_10 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_33 * V_34 = & V_5 -> V_8 -> V_35 ;
if ( F_11 ( V_5 -> V_36 ) ) {
if ( V_5 -> V_37 == V_38 ) {
F_12 ( V_5 -> V_39 ) ;
V_5 -> V_37 = V_40 ;
} else {
if ( ! V_5 -> V_41 )
F_8 ( V_3 , V_7 -> V_42 ,
F_4 ( V_3 , V_7 -> V_42 ) &
~ V_34 -> V_43 ) ;
else
F_8 ( V_3 , V_44 ,
V_34 -> V_43 ) ;
}
} else {
if ( ! V_5 -> V_41 )
F_8 ( V_3 , V_7 -> V_42 ,
F_4 ( V_3 , V_7 -> V_42 ) &
~ V_34 -> V_43 ) ;
else
F_8 ( V_3 , V_44 ,
V_34 -> V_43 ) ;
}
}
static void F_13 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = & V_5 -> V_3 ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_33 * V_34 = & V_5 -> V_8 -> V_35 ;
struct V_45 * V_46 = & V_3 -> V_47 -> V_46 ;
unsigned long V_48 ;
unsigned long V_49 ;
unsigned long V_50 ;
V_48 = F_14 ( V_46 -> V_51 , V_46 -> V_52 , V_53 ) ;
V_49 = ( unsigned long ) ( V_46 -> V_54 + V_46 -> V_52 ) ;
if ( F_15 ( V_46 ) || F_16 ( V_3 ) ||
! V_48 )
return;
if ( V_5 -> V_37 == V_40 ) {
F_17 ( V_5 -> V_39 ) ;
return;
}
if ( V_5 -> V_37 == V_38 )
return;
if ( ! V_5 -> V_41 )
F_8 ( V_3 , V_7 -> V_42 ,
F_4 ( V_3 , V_7 -> V_42 ) &
~ ( V_34 -> V_43 ) ) ;
else
F_8 ( V_3 , V_44 ,
V_34 -> V_43 ) ;
if ( V_48 < 4 || F_18 ( V_49 ) ) {
F_8 ( V_3 , V_7 -> V_55 , V_56 ) ;
F_8 ( V_3 , V_7 -> V_57 ,
F_4 ( V_3 , V_7 -> V_57 ) |
V_58 ) ;
if ( F_18 ( V_49 ) ) {
V_50 = F_19 ( V_5 ,
F_18 ( V_49 ) ) ;
V_48 -= V_50 ;
}
if ( V_48 < 4 )
F_19 ( V_5 , V_48 ) ;
if ( ! V_5 -> V_41 )
F_8 ( V_3 , V_7 -> V_42 ,
F_4 ( V_3 , V_7 -> V_42 ) |
V_34 -> V_43 ) ;
else
F_8 ( V_3 , V_7 -> V_42 ,
V_34 -> V_43 ) ;
F_8 ( V_3 , V_7 -> V_55 , V_59 ) ;
} else {
F_8 ( V_3 , V_7 -> V_55 , V_56 ) ;
F_8 ( V_3 , V_7 -> V_57 ,
F_4 ( V_3 , V_7 -> V_57 ) &
~ V_58 ) ;
F_8 ( V_3 , V_7 -> V_55 , V_59 ) ;
V_48 &= ~ ( 0x3 ) ;
V_5 -> V_60 = F_20 ( V_3 -> V_61 ,
V_46 -> V_54 + V_46 -> V_52 ,
V_48 , V_62 ) ;
V_5 -> V_63 = F_21 (
V_5 -> V_39 , V_5 -> V_60 ,
V_48 , V_64 , V_65 ) ;
if ( ! V_5 -> V_63 ) {
F_22 ( V_3 -> V_61 , L_1 ) ;
return;
}
V_5 -> V_63 -> V_66 =
V_67 ;
V_5 -> V_63 -> V_68 = ( void * ) V_5 ;
V_5 -> V_69 = V_48 ;
F_23 ( V_5 -> V_63 ) ;
F_24 ( V_5 -> V_39 ) ;
V_5 -> V_37 = V_38 ;
}
}
static void F_25 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_33 * V_34 = & V_5 -> V_8 -> V_35 ;
if ( F_11 ( V_5 -> V_36 ) )
F_13 ( V_5 ) ;
else {
F_19 ( V_5 , 1 ) ;
F_8 ( V_3 , V_7 -> V_55 , V_59 ) ;
if ( ! V_5 -> V_41 )
F_8 ( V_3 , V_7 -> V_42 ,
F_4 ( V_3 , V_7 -> V_42 ) |
V_34 -> V_43 ) ;
else
F_8 ( V_3 , V_7 -> V_42 ,
V_34 -> V_43 ) ;
}
}
static void F_26 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_33 * V_34 = & V_5 -> V_8 -> V_35 ;
F_8 ( V_3 , V_7 -> V_70 , 0 ) ;
if ( F_11 ( V_5 -> V_71 ) ) {
if ( ! V_5 -> V_41 )
F_8 ( V_3 , V_7 -> V_42 ,
F_4 ( V_3 , V_7 -> V_42 ) &
~ ( F_27 ( V_3 , V_34 ) |
V_34 -> V_72 ) ) ;
else
F_8 ( V_3 , V_44 ,
F_27 ( V_3 , V_34 ) |
V_34 -> V_72 ) ;
F_28 ( V_5 -> V_73 ) ;
} else {
if ( ! V_5 -> V_41 )
F_8 ( V_3 , V_7 -> V_42 ,
F_4 ( V_3 , V_7 -> V_42 ) &
~ ( F_29 ( V_3 , V_34 ) ) ) ;
else
F_8 ( V_3 , V_44 ,
F_29 ( V_3 , V_34 ) ) ;
}
}
static void F_30 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_33 * V_34 = & V_5 -> V_8 -> V_35 ;
if ( ! V_5 -> V_15 )
return;
V_5 -> V_16 = false ;
if ( V_5 -> V_8 -> V_18 == V_19 ) {
F_8 ( V_3 , V_7 -> V_20 ,
F_4 ( V_3 , V_7 -> V_20 ) & ~ 0x3FF ) ;
if ( ! V_5 -> V_41 )
F_8 ( V_3 , V_7 -> V_42 ,
F_4 ( V_3 , V_7 -> V_42 ) &
~ V_34 -> V_74 ) ;
else
F_8 ( V_3 , V_44 ,
V_34 -> V_74 ) ;
} else
F_31 ( F_32 ( V_5 -> V_23 ) ) ;
}
static T_1 F_33 ( int V_75 , void * V_76 )
{
struct V_1 * V_5 = (struct V_1 * ) V_76 ;
struct V_2 * V_3 = & V_5 -> V_3 ;
if ( F_34 ( V_5 -> V_23 ) && V_5 -> V_16 )
F_35 ( V_3 ,
! F_6 ( V_5 -> V_23 ) ) ;
return V_77 ;
}
static void F_36 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_33 * V_34 = & V_5 -> V_8 -> V_35 ;
if ( ! V_5 -> V_15 )
return;
V_5 -> V_16 = true ;
if ( V_5 -> V_8 -> V_18 == V_19 ) {
F_8 ( V_3 , V_7 -> V_20 ,
F_4 ( V_3 , V_7 -> V_20 ) |
V_78 | V_79 ) ;
if ( ! V_5 -> V_41 )
F_8 ( V_3 , V_7 -> V_42 ,
F_4 ( V_3 , V_7 -> V_42 )
| V_34 -> V_74 ) ;
else
F_8 ( V_3 , V_7 -> V_42 ,
V_34 -> V_74 ) ;
} else
F_37 ( F_32 ( V_5 -> V_23 ) ) ;
}
static void F_38 ( struct V_2 * V_3 , int V_80 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
if ( V_5 -> V_8 -> V_18 == V_19 ) {
unsigned long V_81 = F_4 ( V_3 , V_7 -> V_82 ) ;
if ( V_80 )
V_81 |= V_83 ;
else
V_81 &= ~ V_83 ;
F_8 ( V_3 , V_7 -> V_82 , V_81 ) ;
}
}
static unsigned int
F_39 ( struct V_2 * V_3 , unsigned int V_84 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_9 * V_10 = & V_5 -> V_8 -> V_11 ;
unsigned int V_85 , V_86 = 0 ;
struct V_87 * V_88 ;
V_88 = F_40 ( & V_3 -> V_47 -> V_3 ) ;
if ( ! V_88 )
return - V_89 ;
while ( ! ( F_4 ( V_3 , V_7 -> V_90 ) &
V_10 -> V_13 ( V_3 -> line ) ) ) {
V_85 = F_4 ( V_3 , V_7 -> V_91 ) |
V_92 ;
if ( F_41 ( F_42 ( V_3 , V_85 ) ) )
continue;
F_43 ( V_3 , 0 , 0 , V_85 , V_93 ) ;
V_86 ++ ;
if ( V_86 >= V_84 )
break;
}
V_5 -> V_94 += V_86 ;
V_3 -> V_95 . V_96 += V_86 ;
F_44 ( & V_3 -> V_97 ) ;
F_45 ( & V_3 -> V_47 -> V_3 ) ;
F_46 ( & V_3 -> V_97 ) ;
return V_86 ;
}
static unsigned int
F_19 ( struct V_1 * V_5 , int V_98 )
{
struct V_2 * V_3 = & V_5 -> V_3 ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_9 * V_10 = & V_5 -> V_8 -> V_11 ;
struct V_45 * V_46 = & V_3 -> V_47 -> V_46 ;
unsigned int V_99 = 0 ;
while ( ! F_15 ( V_46 ) &&
! ( F_4 ( V_3 , V_7 -> V_12 ) &
V_10 -> V_100 ( V_3 -> line ) ) &&
V_98 -- ) {
F_8 ( V_3 , V_7 -> V_101 ,
V_46 -> V_54 [ V_46 -> V_52 ] ) ;
V_46 -> V_52 = ( V_46 -> V_52 + 1 ) & ( V_53 - 1 ) ;
V_3 -> V_95 . V_102 ++ ;
V_99 ++ ;
}
if ( F_47 ( V_46 ) < V_103 )
F_48 ( V_3 ) ;
return V_99 ;
}
static void V_67 ( void * V_104 )
{
struct V_1 * V_5 = (struct V_1 * ) V_104 ;
struct V_2 * V_3 = & V_5 -> V_3 ;
struct V_45 * V_46 = & V_3 -> V_47 -> V_46 ;
unsigned long V_105 ;
V_46 -> V_52 = ( V_46 -> V_52 + V_5 -> V_69 ) &
( V_53 - 1 ) ;
V_3 -> V_95 . V_102 += V_5 -> V_69 ;
if ( F_47 ( V_46 ) < V_103 )
F_48 ( V_3 ) ;
if ( V_5 -> V_60 )
F_49 ( V_3 -> V_61 , V_5 -> V_60 ,
V_5 -> V_69 , V_62 ) ;
F_50 ( & V_5 -> V_106 , V_105 ) ;
V_5 -> V_37 = V_107 ;
F_13 ( V_5 ) ;
F_51 ( & V_5 -> V_106 , V_105 ) ;
}
static void F_52 (
struct V_1 * V_5 , int V_98 )
{
struct V_2 * V_3 = & V_5 -> V_3 ;
struct V_108 * V_109 = & V_3 -> V_47 -> V_3 ;
int V_110 ;
V_110 = F_53 ( V_109 ,
V_5 -> V_111 [ V_5 -> V_112 ] . V_46 . V_54 , V_98 ) ;
V_3 -> V_95 . V_96 += V_110 ;
F_45 ( V_109 ) ;
}
static void F_54 ( struct V_2 * V_3 , int V_113 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
V_5 -> V_111 [ V_113 ] . V_46 . V_52 =
V_5 -> V_111 [ V_113 ] . V_46 . V_51 = 0 ;
V_5 -> V_111 [ V_113 ] . V_114 =
F_21 ( V_5 -> V_73 ,
V_5 -> V_111 [ V_113 ] . V_115 , V_116 ,
V_117 , V_65 ) ;
if ( ! V_5 -> V_111 [ V_113 ] . V_114 ) {
F_22 ( V_3 -> V_61 , L_2 ) ;
return;
}
V_5 -> V_111 [ V_113 ] . V_114 -> V_66 =
V_118 ;
V_5 -> V_111 [ V_113 ] . V_114 -> V_68 = V_5 ;
V_5 -> V_111 [ V_113 ] . V_119 =
F_23 ( V_5 -> V_111 [ V_113 ] . V_114 ) ;
F_24 ( V_5 -> V_73 ) ;
}
static void F_55 ( unsigned long V_104 )
{
struct V_1 * V_5 = (struct V_1 * ) V_104 ;
struct V_2 * V_3 = & V_5 -> V_3 ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_33 * V_34 = & V_5 -> V_8 -> V_35 ;
struct V_120 * V_121 = & V_5 -> V_8 -> V_122 ;
unsigned int V_98 ;
unsigned long V_105 ;
struct V_123 V_124 ;
F_50 ( & V_5 -> V_125 , V_105 ) ;
while ( V_126 == F_56 ( V_5 -> V_73 ,
V_5 -> V_111 [ V_5 -> V_112 ] . V_119 , & V_124 ) ) {
F_52 ( V_5 ,
V_116 ) ;
V_5 -> V_112 ++ ;
V_5 -> V_112 %= V_127 ;
}
V_98 = F_57 ( V_5 -> V_111 [ V_5 -> V_128 ] . V_46 . V_51 ,
V_5 -> V_111 [ V_5 -> V_128 ] . V_46 . V_52 ,
V_116 ) ;
if ( V_98 > 0 )
F_52 ( V_5 , V_98 ) ;
F_8 ( V_3 , V_7 -> V_129 ,
F_4 ( V_3 , V_7 -> V_129 ) |
V_58 ) ;
F_51 ( & V_5 -> V_125 , V_105 ) ;
F_46 ( & V_3 -> V_97 ) ;
F_39 ( V_3 , 4 - V_5 -> V_94 ) ;
F_44 ( & V_3 -> V_97 ) ;
if ( V_5 -> V_94 == 4 ) {
F_50 ( & V_5 -> V_125 , V_105 ) ;
V_5 -> V_94 = 0 ;
F_8 ( V_3 , V_7 -> V_130 ,
V_121 -> V_131 ) ;
if ( ! V_5 -> V_41 )
F_8 ( V_3 , V_7 -> V_42 ,
F_4 ( V_3 , V_7 -> V_42 ) &
~ ( V_34 -> V_72 ) ) ;
else
F_8 ( V_3 , V_44 ,
V_34 -> V_72 ) ;
F_51 ( & V_5 -> V_125 , V_105 ) ;
F_58 ( V_3 ) ;
} else {
F_50 ( & V_5 -> V_125 , V_105 ) ;
F_8 ( V_3 , V_7 -> V_130 ,
V_121 -> V_131 ) ;
if ( ! V_5 -> V_41 )
F_8 ( V_3 , V_7 -> V_42 ,
F_4 ( V_3 , V_7 -> V_42 ) |
( V_34 -> V_72 ) ) ;
else
F_8 ( V_3 , V_7 -> V_42 ,
V_34 -> V_72 ) ;
F_51 ( & V_5 -> V_125 , V_105 ) ;
}
}
static void F_59 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = & V_5 -> V_3 ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_33 * V_34 = & V_5 -> V_8 -> V_35 ;
struct V_123 V_124 ;
F_46 ( & V_5 -> V_125 ) ;
F_56 ( V_5 -> V_73 ,
V_5 -> V_111 [ V_5 -> V_128 ] . V_119 , & V_124 ) ;
F_28 ( V_5 -> V_73 ) ;
V_5 -> V_111 [ V_5 -> V_128 ] . V_46 . V_51 =
V_116 - V_124 . V_132 ;
if ( ! V_5 -> V_41 )
F_8 ( V_3 , V_7 -> V_42 ,
F_4 ( V_3 , V_7 -> V_42 ) &
~ ( V_34 -> V_133 ) ) ;
else
F_8 ( V_3 , V_44 ,
V_34 -> V_133 ) ;
F_44 ( & V_5 -> V_125 ) ;
F_60 ( & V_5 -> V_134 ) ;
}
static void F_61 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = & V_5 -> V_3 ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_33 * V_34 = & V_5 -> V_8 -> V_35 ;
struct V_120 * V_121 = & V_5 -> V_8 -> V_122 ;
F_39 ( V_3 , 4 - V_5 -> V_94 ) ;
if ( V_5 -> V_94 == 4 ) {
V_5 -> V_94 = 0 ;
if ( ! V_5 -> V_41 )
F_8 ( V_3 , V_7 -> V_42 ,
F_4 ( V_3 , V_7 -> V_42 ) &
~ ( V_34 -> V_72 ) ) ;
else
F_8 ( V_3 , V_44 ,
V_34 -> V_72 ) ;
F_8 ( V_3 , V_7 -> V_130 ,
V_121 -> V_135 ) ;
F_58 ( V_3 ) ;
}
}
static T_1 F_62 ( int V_75 , void * V_76 )
{
unsigned long V_136 ;
unsigned long V_137 ;
unsigned long V_138 = V_93 ;
struct V_1 * V_5 = (struct V_1 * ) V_76 ;
struct V_2 * V_3 = & V_5 -> V_3 ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_9 * V_10 = & V_5 -> V_8 -> V_11 ;
struct V_120 * V_121 = & V_5 -> V_8 -> V_122 ;
struct V_33 * V_34 = & V_5 -> V_8 -> V_35 ;
struct V_139 * V_47 = V_3 -> V_47 ;
struct V_45 * V_46 = & V_3 -> V_47 -> V_46 ;
F_46 ( & V_3 -> V_97 ) ;
V_136 = F_4 ( V_3 , V_7 -> V_130 ) ;
F_8 ( V_3 , V_7 -> V_130 , V_136 ) ;
V_136 &= F_4 ( V_3 , V_7 -> V_42 ) ;
if ( F_41 ( V_136 & ( F_63 ( V_3 , V_121 ) ) ) ) {
if ( V_136 & V_121 -> V_140 ) {
V_3 -> V_95 . V_141 ++ ;
if ( F_64 ( V_3 ) )
goto V_142;
}
if ( V_136 & V_121 -> V_143 )
V_3 -> V_95 . V_144 ++ ;
if ( V_136 & V_121 -> V_145 ) {
V_3 -> V_95 . V_146 ++ ;
V_138 = V_147 ;
}
if ( V_136 & V_121 -> V_148 )
V_138 = V_149 ;
F_8 ( V_3 , V_7 -> V_70 , V_150 ) ;
F_8 ( V_3 , V_7 -> V_70 , 0 ) ;
F_8 ( V_3 , V_7 -> V_70 , V_59 ) ;
V_136 &= V_3 -> V_151 ;
F_43 ( V_3 , V_136 ,
V_34 -> V_152 , 0 , V_138 ) ;
F_45 ( & V_47 -> V_3 ) ;
}
V_142:
if ( ( V_5 -> V_8 -> V_18 == V_19 ) &&
( V_136 & F_65 ( V_121 ) ) &&
! V_5 -> V_37 ) {
V_137 = F_4 ( V_3 , V_7 -> V_20 ) &
V_21 ;
if ( V_137 != 0 )
V_137 = 0 ;
else
V_137 = 1 ;
F_35 ( V_3 , V_137 ) ;
F_66 ( & V_47 -> V_3 . V_153 ) ;
}
if ( F_11 ( V_5 -> V_71 ) ) {
if ( V_136 & V_121 -> V_135 )
F_59 ( V_5 ) ;
if ( V_136 & V_121 -> V_131 )
F_61 ( V_5 ) ;
} else {
if ( V_136 & F_67 ( V_121 ) )
F_39 ( V_3 ,
V_154 ) ;
}
if ( V_136 & V_121 -> V_155 ) {
if ( F_11 ( V_5 -> V_36 ) )
F_13 ( V_5 ) ;
else {
if ( F_15 ( V_46 ) || F_16 ( V_3 ) ) {
F_44 ( & V_3 -> V_97 ) ;
return V_77 ;
} else {
F_19 ( V_5 ,
V_156 ) ;
if ( ( F_15 ( V_46 ) ) &&
( F_4 ( V_3 , V_7 -> V_12 ) &
V_10 -> V_13 ( V_3 -> line ) ) )
F_10 ( V_3 ) ;
}
}
}
F_44 ( & V_3 -> V_97 ) ;
return V_77 ;
}
static void F_68 ( unsigned long V_104 )
{
struct V_1 * V_5 = (struct V_1 * ) V_104 ;
struct V_2 * V_3 = & V_5 -> V_3 ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_33 * V_34 = & V_5 -> V_8 -> V_35 ;
unsigned long V_105 ;
struct V_123 V_124 ;
F_50 ( & V_5 -> V_125 , V_105 ) ;
while ( V_126 == F_56 ( V_5 -> V_73 ,
V_5 -> V_111 [ V_5 -> V_112 ] . V_119 , & V_124 ) ) {
F_52 ( V_5 ,
V_116 ) ;
if ( F_4 ( V_3 , V_7 -> V_42 ) &
V_34 -> V_133 )
F_54 ( V_3 ,
V_5 -> V_112 ++ ) ;
else
V_5 -> V_112 ++ ;
V_5 -> V_112 %= V_127 ;
}
F_51 ( & V_5 -> V_125 , V_105 ) ;
}
static void V_118 ( void * V_104 )
{
struct V_1 * V_5 = (struct V_1 * ) V_104 ;
F_46 ( & V_5 -> V_125 ) ;
V_5 -> V_128 ++ ;
V_5 -> V_128 %= V_127 ;
F_44 ( & V_5 -> V_125 ) ;
F_60 ( & V_5 -> V_157 ) ;
}
static void F_58 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_33 * V_34 = & V_5 -> V_8 -> V_35 ;
unsigned long V_105 ;
int V_158 ;
F_50 ( & V_5 -> V_125 , V_105 ) ;
V_5 -> V_94 = 0 ;
F_8 ( V_3 , V_7 -> V_129 ,
F_4 ( V_3 , V_7 -> V_129 ) &
~ V_58 ) ;
F_51 ( & V_5 -> V_125 , V_105 ) ;
for ( V_158 = 0 ; V_158 < V_127 ; V_158 ++ )
F_54 ( V_3 , V_158 ) ;
V_5 -> V_112 = V_5 -> V_128 = 0 ;
F_50 ( & V_5 -> V_125 , V_105 ) ;
if ( ! V_5 -> V_41 )
F_8 ( V_3 , V_7 -> V_42 ,
F_4 ( V_3 , V_7 -> V_42 ) |
F_27 ( V_3 , V_34 ) ) ;
else
F_8 ( V_3 , V_7 -> V_42 ,
F_27 ( V_3 , V_34 ) ) ;
F_51 ( & V_5 -> V_125 , V_105 ) ;
}
static void F_69 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_33 * V_34 = & V_5 -> V_8 -> V_35 ;
V_5 -> V_94 = 0 ;
F_8 ( V_3 , V_7 -> V_70 , V_150 ) ;
F_8 ( V_3 , V_7 -> V_70 , 0 ) ;
F_8 ( V_3 , V_7 -> V_70 , V_59 ) ;
if ( F_11 ( V_5 -> V_71 ) )
F_58 ( V_3 ) ;
else {
if ( ! V_5 -> V_41 )
F_8 ( V_3 , V_7 -> V_42 ,
F_4 ( V_3 , V_7 -> V_42 ) |
F_29 ( V_3 , V_34 ) ) ;
else
F_8 ( V_3 , V_7 -> V_42 ,
F_29 ( V_3 , V_34 ) ) ;
}
}
static unsigned int
F_70 ( unsigned long V_159 ,
unsigned long V_160 , unsigned long * V_161 )
{
unsigned long V_162 = ~ 0UL ;
unsigned short V_163 ;
unsigned long V_164 = 0 ;
unsigned long V_165 ;
for ( V_163 = V_166 ;
V_163 <= V_167 ; V_163 ++ ) {
V_165 = V_160 -
( V_160 + ( V_159 * V_163 ) / 2 )
/ ( V_159 * V_163 ) * V_159 * V_163 ;
V_165 = ( V_165 > 0 ) ? V_165 : - V_165 ;
if ( V_165 < V_162 ) {
V_164 = ( 2 * V_160 /
( V_159 * V_163 ) + 1 ) / 2 - 1 ;
if ( V_164 > V_168 )
continue;
V_162 = V_165 ;
* V_161 = V_163 ;
if ( ! V_165 )
break;
}
}
return V_164 ;
}
static unsigned int
F_71 ( unsigned long V_169 ,
unsigned long V_160 , unsigned long * V_170 )
{
unsigned long V_162 = ~ 0UL ;
unsigned short V_163 ;
unsigned int V_171 = 0 ;
unsigned long V_164 ;
unsigned long V_172 ;
int V_165 ;
for ( V_163 = V_166 ;
V_163 <= V_167 ; V_163 ++ ) {
V_164 = ( V_160 / ( V_169 * ( V_163 + 1 ) ) ) - 1 ;
if ( V_164 > V_168 )
continue;
V_172 = V_160 / ( ( V_164 + 1 ) * ( V_163 + 1 ) ) ;
V_165 = V_172 - V_169 ;
V_165 = ( V_165 > 0 ) ? V_165 : - V_165 ;
if ( V_165 < V_162 ) {
V_171 = V_171 & ( ~ V_173 ) ;
V_171 = V_171 | V_164 ;
V_171 = V_171 & ( ~ V_174 ) ;
V_171 = V_171 | ( V_163 << V_175 ) ;
V_162 = V_165 ;
* V_170 = V_172 ;
}
}
return V_171 ;
}
static void F_72 ( struct V_2 * V_3 ,
struct V_176 * V_177 ,
struct V_176 * V_178 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_33 * V_34 = & V_5 -> V_8 -> V_35 ;
unsigned long V_179 = 0 ;
unsigned long V_169 ;
unsigned long V_170 ;
unsigned long V_105 ;
unsigned long V_180 ;
unsigned int V_181 = 0 ;
unsigned long V_182 , V_160 ;
unsigned long V_183 ;
int V_184 ;
T_2 V_185 , V_186 , V_187 ;
unsigned long V_188 = 0xf ;
V_160 = V_3 -> V_189 ;
switch ( V_177 -> V_190 & V_191 ) {
default:
case V_192 :
V_185 = 8 ;
V_179 |= V_193 ;
break;
case V_194 :
V_185 = 7 ;
V_179 |= V_195 ;
break;
case V_196 :
V_185 = 6 ;
V_179 |= V_197 ;
break;
case V_198 :
V_185 = 5 ;
V_179 |= V_199 ;
break;
}
if ( V_177 -> V_190 & V_200 ) {
V_179 |= V_201 ;
V_186 = 2 ;
} else
V_186 = 1 ;
F_50 ( & V_3 -> V_97 , V_105 ) ;
V_3 -> V_151 = V_34 -> V_152 ;
V_3 -> V_202 = 0 ;
if ( V_5 -> V_8 -> V_18 == V_19 ) {
if ( V_177 -> V_203 & V_204 )
V_3 -> V_151 |= V_34 -> V_205 |
V_34 -> V_206 ;
} else {
if ( V_177 -> V_203 & V_204 )
V_3 -> V_151 |= V_34 -> V_205 ;
}
if ( V_177 -> V_203 & ( V_207 | V_208 ) )
V_3 -> V_151 |= V_34 -> V_209 ;
if ( V_5 -> V_8 -> V_18 == V_19 ) {
if ( V_177 -> V_203 & V_210 )
V_3 -> V_202 |=
V_34 -> V_205 |
V_34 -> V_206 ;
if ( V_177 -> V_190 & V_211 ) {
if ( V_177 -> V_190 & V_212 ) {
if ( V_177 -> V_190 & V_213 )
V_179 |= V_214 ;
else
V_179 |= V_215 ;
} else if ( V_177 -> V_190 & V_213 ) {
V_179 |= V_216 ;
} else {
V_179 |= V_217 ;
}
}
} else {
if ( V_177 -> V_203 & V_210 )
V_3 -> V_202 |=
V_34 -> V_205 ;
if ( V_177 -> V_190 & V_211 )
F_73 ( V_3 -> V_61 ,
L_3 ) ;
}
if ( V_177 -> V_203 & V_218 ) {
V_3 -> V_202 |=
V_34 -> V_209 ;
if ( V_177 -> V_203 & V_210 )
V_3 -> V_202 |=
V_34 -> V_152 ;
}
if ( ( V_177 -> V_190 & V_219 ) == 0 )
V_3 -> V_202 |= V_92 ;
if ( F_74 ( V_3 , V_177 -> V_190 ) ) {
if ( ! V_5 -> V_16 )
F_36 ( V_3 ) ;
} else {
if ( V_5 -> V_16 )
F_30 ( V_3 ) ;
}
V_169 = F_75 ( V_3 , V_177 , V_178 , 0 , 4000000 ) ;
if ( V_160 == 150000000 ) {
for ( V_180 = 0 ; V_180 < V_220 ; V_180 ++ )
if ( V_169 == V_221 [ V_180 ] . V_169 )
V_181 = V_221 [ V_180 ] . V_222 ;
}
V_170 = V_169 ;
if ( V_5 -> V_8 -> V_18 == V_19 ) {
if ( F_41 ( V_181 == 0 ) )
V_181 = F_71 ( V_169 ,
V_160 , & V_170 ) ;
F_8 ( V_3 , V_7 -> V_223 , V_181 ) ;
} else {
V_181 = F_70 ( V_169 ,
V_160 , & V_188 ) ;
V_188 -- ;
V_170 = ( ( V_160 / ( V_181 + 1 ) - 1 ) /
( V_188 + 1 ) ) ;
V_187 = ( ( 1 << V_224 ) |
( 1 << V_225 ) ) ;
V_187 |= ( ( V_181 & V_226 )
<< V_227 ) ;
F_8 ( V_3 , V_7 -> V_228 , V_187 ) ;
}
if ( F_76 ( V_177 ) )
F_77 ( V_177 , V_170 , V_170 ) ;
V_183 = F_78 ( V_170 , 20000 ) ;
V_183 = F_79 ( V_183 ) ;
V_182 = F_4 ( V_3 , V_7 -> V_55 ) ;
F_8 ( V_3 , V_7 -> V_70 , V_56 ) ;
F_8 ( V_3 , V_7 -> V_55 ,
( V_182 & ~ V_59 ) ) ;
if ( V_5 -> V_8 -> V_18 == V_19 ) {
V_179 |= F_80 ( V_3 , V_183 ) ;
F_8 ( V_3 , V_7 -> V_82 , V_179 ) ;
} else {
V_187 = ( V_185 - 1 ) << V_229 ;
V_187 |= ( V_185 + 1 + V_186 - 1 ) <<
V_230 ;
V_187 |= ( ( V_185 - 1 ) <<
V_231 ) ;
V_187 |= ( ( ( V_181 & 0xc00 ) >> 10 ) <<
V_232 ) ;
F_8 ( V_3 , V_7 -> V_233 , V_187 ) ;
V_187 = ( V_185 - 1 ) << V_234 ;
V_187 |= ( V_185 + 1 + V_186 - 1 ) <<
V_235 ;
V_187 |= ( V_185 - 1 ) <<
V_236 ;
V_187 |= ( ( ( V_181 & 0xf000 ) >> 12 ) <<
V_237 ) ;
F_8 ( V_3 , V_7 -> V_238 , V_187 ) ;
F_8 ( V_3 , V_7 -> V_239 ,
( F_80 ( V_3 , V_183 ) ) |
( V_188 & V_240 ) <<
V_241 ) ;
}
if ( F_11 ( V_5 -> V_36 ) )
F_8 ( V_3 , V_7 -> V_57 , V_242 ) ;
else
F_8 ( V_3 , V_7 -> V_57 , V_58 ) ;
if ( F_11 ( V_5 -> V_71 ) )
F_8 ( V_3 , V_7 -> V_129 , V_242 ) ;
else
F_8 ( V_3 , V_7 -> V_129 , V_58 ) ;
if ( V_170 < 1000000 )
V_184 = 1 ;
else
V_184 = 2 ;
F_8 ( V_3 , V_7 -> V_243 ,
F_81 ( V_3 ) / V_184 ) ;
F_8 ( V_3 , V_7 -> V_244 ,
F_81 ( V_3 ) / V_184 ) ;
V_182 |= V_59 ;
F_8 ( V_3 , V_7 -> V_55 , V_182 ) ;
F_82 ( V_3 , V_177 -> V_190 , V_170 ) ;
F_69 ( V_3 ) ;
F_8 ( V_3 , V_7 -> V_245 , V_246 | V_247 ) ;
F_51 ( & V_3 -> V_97 , V_105 ) ;
}
static void F_83 ( struct V_2 * V_3 , unsigned int V_47 ,
unsigned int V_248 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( ! V_47 )
F_84 ( V_5 -> V_249 ) ;
else
F_85 ( V_5 -> V_249 ) ;
}
static unsigned int F_86 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_3 V_250 ;
struct V_251 V_252 = {
. V_253 = 2 ,
} ;
F_87 ( V_250 ) ;
F_88 ( V_254 , V_250 ) ;
V_5 -> V_39 = F_89 ( V_250 ,
( V_255 ) V_256 ,
( void * ) V_5 -> V_36 ) ;
if ( ! V_5 -> V_39 ) {
F_22 ( V_3 -> V_61 , L_4 ,
V_5 -> V_36 ) ;
return - V_257 ;
}
F_90 ( V_5 -> V_39 , & V_252 ) ;
return 0 ;
}
static unsigned int F_91 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_3 V_250 ;
int V_258 ;
int V_158 , V_259 ;
struct V_251 V_260 = {
. V_261 = 2 ,
} ;
F_87 ( V_250 ) ;
F_88 ( V_254 , V_250 ) ;
V_5 -> V_73 = F_89 ( V_250 ,
( V_255 ) V_256 ,
( void * ) V_5 -> V_71 ) ;
if ( ! V_5 -> V_73 ) {
F_22 ( V_3 -> V_61 , L_4 ,
V_5 -> V_71 ) ;
V_258 = - V_257 ;
goto V_262;
}
for ( V_158 = 0 ; V_158 < V_127 ; V_158 ++ ) {
V_5 -> V_111 [ V_158 ] . V_46 . V_54 =
F_92 ( V_3 -> V_61 , V_116 ,
& V_5 -> V_111 [ V_158 ] . V_115 , V_263 ) ;
if ( ! V_5 -> V_111 [ V_158 ] . V_46 . V_54 ) {
F_22 ( V_3 -> V_61 , L_5 ) ;
V_258 = - V_264 ;
goto V_265;
}
V_5 -> V_111 [ V_158 ] . V_46 . V_51 =
V_5 -> V_111 [ V_158 ] . V_46 . V_52 = 0 ;
}
F_90 ( V_5 -> V_73 , & V_260 ) ;
return 0 ;
V_265:
for ( V_259 = 0 ; V_259 < V_158 ; V_259 ++ )
F_93 ( V_3 -> V_61 , V_116 ,
V_5 -> V_111 [ V_259 ] . V_46 . V_54 ,
V_5 -> V_111 [ V_259 ] . V_115 ) ;
F_94 ( V_5 -> V_73 ) ;
V_262:
return V_258 ;
}
static void F_95 ( struct V_1 * V_5 )
{
F_28 ( V_5 -> V_39 ) ;
F_94 ( V_5 -> V_39 ) ;
}
static void F_96 ( struct V_1 * V_5 )
{
int V_158 ;
struct V_2 * V_3 = & V_5 -> V_3 ;
F_28 ( V_5 -> V_73 ) ;
F_94 ( V_5 -> V_73 ) ;
for ( V_158 = 0 ; V_158 < V_127 ; V_158 ++ )
F_93 ( V_3 -> V_61 , V_116 ,
V_5 -> V_111 [ V_158 ] . V_46 . V_54 ,
V_5 -> V_111 [ V_158 ] . V_115 ) ;
}
static int F_97 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
unsigned int V_113 = V_3 -> line ;
int V_258 ;
F_98 ( V_3 -> V_75 , V_266 | V_267 ) ;
V_258 = F_99 ( V_3 -> V_75 ,
F_62 ,
0 ,
V_268 ,
V_5 ) ;
if ( V_258 != 0 ) {
F_22 ( V_3 -> V_61 , L_6 ,
V_113 , V_3 -> V_75 ) ;
goto V_269;
}
F_8 ( V_3 , V_7 -> V_57 ,
F_4 ( V_3 , V_7 -> V_57 ) |
V_58 ) ;
F_8 ( V_3 , V_7 -> V_129 ,
F_4 ( V_3 , V_7 -> V_129 ) |
V_58 ) ;
F_8 ( V_3 , V_7 -> V_270 , 0 ) ;
F_8 ( V_3 , V_7 -> V_271 , 0 ) ;
F_8 ( V_3 , V_7 -> V_245 , V_247 | V_246 ) ;
if ( V_5 -> V_8 -> V_18 == V_272 )
F_8 ( V_3 , V_7 -> V_273 ,
V_274 |
V_275 ) ;
F_8 ( V_3 , V_7 -> V_55 , V_150 ) ;
F_8 ( V_3 , V_7 -> V_55 , 0 ) ;
F_8 ( V_3 , V_7 -> V_70 , V_150 ) ;
F_8 ( V_3 , V_7 -> V_70 , 0 ) ;
F_8 ( V_3 , V_7 -> V_243 , F_81 ( V_3 ) ) ;
F_8 ( V_3 , V_7 -> V_244 , F_81 ( V_3 ) ) ;
if ( F_11 ( V_5 -> V_71 ) ) {
V_258 = F_91 ( V_3 ) ;
if ( V_258 )
goto V_276;
F_8 ( V_3 , V_7 -> V_277 ,
F_100 ( V_3 -> line , 0x4 ) |
F_101 ( V_3 -> line , 0xe ) |
F_102 ( V_3 -> line , 0x1b ) ) ;
}
if ( F_11 ( V_5 -> V_36 ) ) {
F_86 ( V_3 ) ;
V_5 -> V_37 = V_107 ;
F_8 ( V_3 , V_7 -> V_278 ,
F_103 ( V_3 -> line , 0x1b ) |
F_104 ( V_3 -> line , 0xe ) |
F_105 ( V_3 -> line , 0x4 ) ) ;
}
V_5 -> V_16 = false ;
if ( V_5 -> V_8 -> V_18 == V_272 &&
V_5 -> V_15 ) {
F_98 ( F_32 ( V_5 -> V_23 ) ,
V_266 | V_267 ) ;
V_258 = F_99 ( F_32 ( V_5 -> V_23 ) ,
F_33 , V_279 |
V_280 , L_7 , V_5 ) ;
if ( V_258 != 0 ) {
F_22 ( V_3 -> V_61 , L_8 ) ;
goto V_276;
}
}
F_37 ( V_3 -> V_75 ) ;
return 0 ;
V_276:
F_106 ( V_3 -> V_75 , V_5 ) ;
V_269:
return V_258 ;
}
static void F_107 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
if ( ! V_5 -> V_41 )
F_8 ( V_3 , V_7 -> V_42 , 0 ) ;
else
F_8 ( V_3 , V_44 , ~ 0UL ) ;
F_106 ( V_3 -> V_75 , V_5 ) ;
if ( V_5 -> V_16 )
F_30 ( V_3 ) ;
if ( V_5 -> V_8 -> V_18 == V_272 &&
V_5 -> V_15 ) {
F_9 ( V_5 -> V_32 , 1 ) ;
F_106 ( F_32 ( V_5 -> V_23 ) , V_5 ) ;
}
if ( F_11 ( V_5 -> V_71 ) )
F_96 ( V_5 ) ;
if ( F_11 ( V_5 -> V_36 ) ) {
F_95 ( V_5 ) ;
V_5 -> V_37 = V_107 ;
}
}
static const char * F_108 ( struct V_2 * V_3 )
{
return V_3 -> type == V_281 ? V_268 : NULL ;
}
static int F_109 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_282 * V_283 = & V_5 -> V_8 -> V_283 ;
void * V_258 ;
V_258 = F_110 ( V_3 -> V_284 ,
V_285 , V_283 -> V_286 ) ;
return V_258 ? 0 : - V_287 ;
}
static void F_111 ( struct V_2 * V_3 )
{
F_112 ( V_3 -> V_284 , V_285 ) ;
}
static void F_113 ( struct V_2 * V_3 , int V_105 )
{
if ( V_105 & V_288 ) {
V_3 -> type = V_281 ;
F_109 ( V_3 ) ;
}
}
static int T_4
F_114 ( struct V_289 * V_290 , char * V_291 )
{
unsigned int V_292 = 115200 ;
unsigned int V_293 = 8 ;
unsigned int V_294 = 'n' ;
unsigned int V_295 = 'n' ;
struct V_2 * V_3 = & V_296 [ V_290 -> V_113 ] . V_3 ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
if ( V_290 -> V_113 < 0 || V_290 -> V_113 >= V_297 )
return - V_298 ;
if ( ! V_3 -> V_284 )
return - V_89 ;
if ( V_5 -> V_8 -> V_18 == V_272 )
F_8 ( V_3 , V_7 -> V_273 , V_275 |
V_274 ) ;
if ( V_291 )
F_115 ( V_291 , & V_292 , & V_294 , & V_293 , & V_295 ) ;
V_3 -> V_299 = V_290 ;
V_5 -> V_71 = V_300 ;
V_5 -> V_36 = V_300 ;
return F_116 ( V_3 , V_290 , V_292 , V_294 , V_293 , V_295 ) ;
}
static void F_117 ( struct V_2 * V_3 , int V_85 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_9 * V_10 = & V_5 -> V_8 -> V_11 ;
while ( F_4 ( V_3 ,
V_7 -> V_12 ) & V_10 -> V_100 ( V_3 -> line ) )
F_118 () ;
F_119 ( V_3 , V_7 -> V_101 , V_85 ) ;
}
static void F_120 ( struct V_289 * V_290 , const char * V_301 ,
unsigned int V_98 )
{
struct V_2 * V_3 = & V_296 [ V_290 -> V_113 ] . V_3 ;
F_121 ( V_3 , V_301 , V_98 , F_117 ) ;
}
static int T_4 F_122 ( void )
{
F_123 ( & V_302 ) ;
return 0 ;
}
static int F_124 ( struct V_303 * V_304 )
{
struct V_1 * V_5 ;
struct V_2 * V_3 ;
struct V_305 * V_306 ;
int V_258 ;
const struct V_307 * V_308 ;
V_308 = F_125 ( V_309 , V_304 -> V_61 . V_310 ) ;
if ( F_126 ( V_304 -> V_61 . V_310 , L_9 , & V_304 -> V_311 ) ) {
F_22 ( & V_304 -> V_61 ,
L_10 ) ;
V_258 = - V_312 ;
goto V_313;
}
if ( F_127 ( V_304 -> V_61 . V_310 , L_11 ) )
V_304 -> V_311 += ( (struct V_314 * )
V_308 -> V_315 ) -> V_283 . V_316 ;
V_5 = & V_296 [ V_304 -> V_311 ] ;
V_3 = & V_5 -> V_3 ;
V_3 -> V_61 = & V_304 -> V_61 ;
V_3 -> V_317 = V_5 ;
V_5 -> V_8 = (struct V_314 * ) V_308 -> V_315 ;
V_5 -> V_15 = F_128 ( V_304 -> V_61 . V_310 ,
L_12 ) ;
if ( F_127 ( V_304 -> V_61 . V_310 , L_13 ) ) {
V_5 -> V_8 -> V_18 = V_19 ;
if ( F_126 ( V_304 -> V_61 . V_310 ,
L_14 ,
& V_5 -> V_71 ) )
V_5 -> V_71 = V_300 ;
if ( F_126 ( V_304 -> V_61 . V_310 ,
L_15 ,
& V_5 -> V_36 ) )
V_5 -> V_36 = V_300 ;
}
if ( F_127 ( V_304 -> V_61 . V_310 , L_11 ) ) {
V_5 -> V_8 -> V_18 = V_272 ;
if ( F_126 ( V_304 -> V_61 . V_310 ,
L_16 ,
& V_5 -> V_71 ) )
V_5 -> V_71 = V_300 ;
if ( F_126 ( V_304 -> V_61 . V_310 ,
L_17 ,
& V_5 -> V_36 ) )
V_5 -> V_36 = V_300 ;
if ( ! V_5 -> V_15 )
goto V_318;
if ( F_129 ( V_304 -> V_61 . V_310 , L_18 , NULL ) )
V_5 -> V_23 = F_130 (
V_304 -> V_61 . V_310 , L_18 , 0 ) ;
else
V_5 -> V_23 = - 1 ;
if ( F_129 ( V_304 -> V_61 . V_310 , L_19 , NULL ) )
V_5 -> V_32 = F_130 (
V_304 -> V_61 . V_310 , L_19 , 0 ) ;
else
V_5 -> V_32 = - 1 ;
if ( ( ! F_34 ( V_5 -> V_23 ) ||
! F_34 ( V_5 -> V_32 ) ) ) {
V_258 = - V_298 ;
F_22 ( & V_304 -> V_61 ,
L_20 ) ;
goto V_313;
}
V_258 = F_131 ( & V_304 -> V_61 , V_5 -> V_23 ,
L_21 ) ;
if ( V_258 ) {
F_22 ( & V_304 -> V_61 , L_22 ) ;
goto V_313;
}
F_132 ( V_5 -> V_23 ) ;
V_258 = F_131 ( & V_304 -> V_61 , V_5 -> V_32 ,
L_23 ) ;
if ( V_258 ) {
F_22 ( & V_304 -> V_61 , L_24 ) ;
goto V_313;
}
F_133 ( V_5 -> V_32 , 1 ) ;
}
V_318:
if ( F_127 ( V_304 -> V_61 . V_310 , L_25 ) )
V_5 -> V_41 = true ;
if ( F_126 ( V_304 -> V_61 . V_310 ,
L_26 ,
& V_3 -> V_319 ) ) {
F_22 ( & V_304 -> V_61 ,
L_27 ) ;
V_258 = - V_312 ;
goto V_313;
}
V_306 = F_134 ( V_304 , V_320 , 0 ) ;
if ( V_306 == NULL ) {
F_22 ( & V_304 -> V_61 , L_28 ) ;
V_258 = - V_312 ;
goto V_313;
}
F_135 ( & V_5 -> V_125 ) ;
F_135 ( & V_5 -> V_106 ) ;
F_136 ( & V_5 -> V_157 ,
F_68 , ( unsigned long ) V_5 ) ;
F_136 ( & V_5 -> V_134 ,
F_55 , ( unsigned long ) V_5 ) ;
V_3 -> V_284 = V_306 -> V_321 ;
V_3 -> V_322 = F_137 ( & V_304 -> V_61 , V_306 -> V_321 , F_138 ( V_306 ) ) ;
if ( ! V_3 -> V_322 ) {
F_22 ( & V_304 -> V_61 , L_29 ) ;
V_258 = - V_264 ;
goto V_313;
}
V_306 = F_134 ( V_304 , V_323 , 0 ) ;
if ( V_306 == NULL ) {
F_22 ( & V_304 -> V_61 , L_28 ) ;
V_258 = - V_312 ;
goto V_313;
}
V_3 -> V_75 = V_306 -> V_321 ;
V_5 -> V_249 = F_139 ( & V_304 -> V_61 , NULL ) ;
if ( F_140 ( V_5 -> V_249 ) ) {
V_258 = F_141 ( V_5 -> V_249 ) ;
goto V_313;
}
V_3 -> V_189 = F_142 ( V_5 -> V_249 ) ;
V_3 -> V_324 = & V_325 ;
F_135 ( & V_3 -> V_97 ) ;
F_143 ( V_304 , V_5 ) ;
V_258 = F_144 ( & V_326 , V_3 ) ;
if ( V_258 != 0 ) {
F_22 ( & V_304 -> V_61 , L_30 , V_304 -> V_311 ) ;
goto V_327;
}
return 0 ;
V_327:
F_145 ( V_5 -> V_249 ) ;
V_313:
return V_258 ;
}
static int F_146 ( struct V_303 * V_304 )
{
struct V_1 * V_5 = F_147 ( V_304 ) ;
struct V_2 * V_3 = & V_5 -> V_3 ;
F_145 ( V_5 -> V_249 ) ;
F_148 ( & V_326 , V_3 ) ;
return 0 ;
}
static int
F_149 ( struct V_328 * V_304 )
{
struct V_1 * V_5 = F_150 ( V_304 ) ;
struct V_2 * V_3 = & V_5 -> V_3 ;
F_151 ( & V_326 , V_3 ) ;
return 0 ;
}
static int F_152 ( struct V_328 * V_304 )
{
struct V_1 * V_5 = F_150 ( V_304 ) ;
struct V_2 * V_3 = & V_5 -> V_3 ;
F_153 ( & V_326 , V_3 ) ;
return 0 ;
}
static int T_4 F_154 ( void )
{
int V_258 = 0 ;
V_258 = F_155 ( & V_326 ) ;
if ( V_258 )
goto V_329;
V_258 = F_156 ( & V_330 ) ;
if ( V_258 )
F_157 ( & V_326 ) ;
V_329:
return V_258 ;
}
static void T_5 F_158 ( void )
{
F_159 ( & V_330 ) ;
F_157 ( & V_326 ) ;
}
