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
if ( V_5 -> V_36 ) {
if ( V_5 -> V_37 == V_38 ) {
F_11 ( V_5 -> V_36 ) ;
V_5 -> V_37 = V_39 ;
} else {
if ( ! V_5 -> V_40 )
F_8 ( V_3 , V_7 -> V_41 ,
F_4 ( V_3 , V_7 -> V_41 ) &
~ V_34 -> V_42 ) ;
else
F_8 ( V_3 , V_43 ,
V_34 -> V_42 ) ;
}
} else {
if ( ! V_5 -> V_40 )
F_8 ( V_3 , V_7 -> V_41 ,
F_4 ( V_3 , V_7 -> V_41 ) &
~ V_34 -> V_42 ) ;
else
F_8 ( V_3 , V_43 ,
V_34 -> V_42 ) ;
}
}
static void F_12 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = & V_5 -> V_3 ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_33 * V_34 = & V_5 -> V_8 -> V_35 ;
struct V_44 * V_45 = & V_3 -> V_46 -> V_45 ;
unsigned long V_47 ;
unsigned long V_48 ;
unsigned long V_49 ;
V_47 = F_13 ( V_45 -> V_50 , V_45 -> V_51 , V_52 ) ;
V_48 = ( unsigned long ) ( V_45 -> V_53 + V_45 -> V_51 ) ;
if ( F_14 ( V_45 ) || F_15 ( V_3 ) ||
! V_47 )
return;
if ( V_5 -> V_37 == V_39 ) {
F_16 ( V_5 -> V_36 ) ;
return;
}
if ( V_5 -> V_37 == V_38 )
return;
if ( ! V_5 -> V_40 )
F_8 ( V_3 , V_7 -> V_41 ,
F_4 ( V_3 , V_7 -> V_41 ) &
~ ( V_34 -> V_42 ) ) ;
else
F_8 ( V_3 , V_43 ,
V_34 -> V_42 ) ;
if ( V_47 < 4 || F_17 ( V_48 ) ) {
F_8 ( V_3 , V_7 -> V_54 , V_55 ) ;
F_8 ( V_3 , V_7 -> V_56 ,
F_4 ( V_3 , V_7 -> V_56 ) |
V_57 ) ;
if ( F_17 ( V_48 ) ) {
V_49 = F_18 ( V_5 ,
F_17 ( V_48 ) ) ;
V_47 -= V_49 ;
}
if ( V_47 < 4 )
F_18 ( V_5 , V_47 ) ;
if ( ! V_5 -> V_40 )
F_8 ( V_3 , V_7 -> V_41 ,
F_4 ( V_3 , V_7 -> V_41 ) |
V_34 -> V_42 ) ;
else
F_8 ( V_3 , V_7 -> V_41 ,
V_34 -> V_42 ) ;
F_8 ( V_3 , V_7 -> V_54 , V_58 ) ;
} else {
F_8 ( V_3 , V_7 -> V_54 , V_55 ) ;
F_8 ( V_3 , V_7 -> V_56 ,
F_4 ( V_3 , V_7 -> V_56 ) &
~ V_57 ) ;
F_8 ( V_3 , V_7 -> V_54 , V_58 ) ;
V_47 &= ~ ( 0x3 ) ;
V_5 -> V_59 = F_19 ( V_3 -> V_60 ,
V_45 -> V_53 + V_45 -> V_51 ,
V_47 , V_61 ) ;
V_5 -> V_62 = F_20 (
V_5 -> V_36 , V_5 -> V_59 ,
V_47 , V_63 , V_64 ) ;
if ( ! V_5 -> V_62 ) {
F_21 ( V_3 -> V_60 , L_1 ) ;
return;
}
V_5 -> V_62 -> V_65 =
V_66 ;
V_5 -> V_62 -> V_67 = ( void * ) V_5 ;
V_5 -> V_68 = V_47 ;
F_22 ( V_5 -> V_62 ) ;
F_23 ( V_5 -> V_36 ) ;
V_5 -> V_37 = V_38 ;
}
}
static void F_24 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_33 * V_34 = & V_5 -> V_8 -> V_35 ;
if ( V_5 -> V_36 )
F_12 ( V_5 ) ;
else {
F_18 ( V_5 ,
V_69 ) ;
F_8 ( V_3 , V_7 -> V_54 , V_58 ) ;
if ( ! V_5 -> V_40 )
F_8 ( V_3 , V_7 -> V_41 ,
F_4 ( V_3 , V_7 -> V_41 ) |
V_34 -> V_42 ) ;
else
F_8 ( V_3 , V_7 -> V_41 ,
V_34 -> V_42 ) ;
}
}
static void F_25 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_33 * V_34 = & V_5 -> V_8 -> V_35 ;
F_8 ( V_3 , V_7 -> V_70 , 0 ) ;
if ( V_5 -> V_71 ) {
if ( ! V_5 -> V_40 )
F_8 ( V_3 , V_7 -> V_41 ,
F_4 ( V_3 , V_7 -> V_41 ) &
~ ( F_26 ( V_3 , V_34 ) |
V_34 -> V_72 ) ) ;
else
F_8 ( V_3 , V_43 ,
F_26 ( V_3 , V_34 ) |
V_34 -> V_72 ) ;
F_27 ( V_5 -> V_71 ) ;
} else {
if ( ! V_5 -> V_40 )
F_8 ( V_3 , V_7 -> V_41 ,
F_4 ( V_3 , V_7 -> V_41 ) &
~ ( F_28 ( V_3 , V_34 ) ) ) ;
else
F_8 ( V_3 , V_43 ,
F_28 ( V_3 , V_34 ) ) ;
}
}
static void F_29 ( struct V_2 * V_3 )
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
if ( ! V_5 -> V_40 )
F_8 ( V_3 , V_7 -> V_41 ,
F_4 ( V_3 , V_7 -> V_41 ) &
~ V_34 -> V_73 ) ;
else
F_8 ( V_3 , V_43 ,
V_34 -> V_73 ) ;
} else
F_30 ( F_31 ( V_5 -> V_23 ) ) ;
}
static T_1 F_32 ( int V_74 , void * V_75 )
{
struct V_1 * V_5 = (struct V_1 * ) V_75 ;
struct V_2 * V_3 = & V_5 -> V_3 ;
F_33 ( & V_3 -> V_76 ) ;
if ( F_34 ( V_5 -> V_23 ) && V_5 -> V_16 )
F_35 ( V_3 ,
! F_6 ( V_5 -> V_23 ) ) ;
F_36 ( & V_3 -> V_76 ) ;
return V_77 ;
}
static void F_37 ( struct V_2 * V_3 )
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
if ( ! V_5 -> V_40 )
F_8 ( V_3 , V_7 -> V_41 ,
F_4 ( V_3 , V_7 -> V_41 )
| V_34 -> V_73 ) ;
else
F_8 ( V_3 , V_7 -> V_41 ,
V_34 -> V_73 ) ;
} else
F_38 ( F_31 ( V_5 -> V_23 ) ) ;
}
static void F_39 ( struct V_2 * V_3 , int V_80 )
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
F_40 ( struct V_2 * V_3 , unsigned int V_84 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_9 * V_10 = & V_5 -> V_8 -> V_11 ;
unsigned int V_85 , V_86 = 0 ;
struct V_87 * V_88 ;
V_88 = F_41 ( & V_3 -> V_46 -> V_3 ) ;
if ( ! V_88 )
return - V_89 ;
while ( ! ( F_4 ( V_3 , V_7 -> V_90 ) &
V_10 -> V_13 ( V_3 -> line ) ) ) {
V_85 = F_4 ( V_3 , V_7 -> V_91 ) |
V_92 ;
if ( F_42 ( F_43 ( V_3 , V_85 ) ) )
continue;
F_44 ( V_3 , 0 , 0 , V_85 , V_93 ) ;
V_86 ++ ;
if ( V_86 >= V_84 )
break;
}
V_5 -> V_94 += V_86 ;
V_3 -> V_95 . V_96 += V_86 ;
return V_86 ;
}
static unsigned int
F_18 ( struct V_1 * V_5 , int V_97 )
{
struct V_2 * V_3 = & V_5 -> V_3 ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_9 * V_10 = & V_5 -> V_8 -> V_11 ;
struct V_44 * V_45 = & V_3 -> V_46 -> V_45 ;
unsigned int V_98 = 0 ;
while ( ! F_14 ( V_45 ) &&
! ( F_4 ( V_3 , V_7 -> V_12 ) &
V_10 -> V_99 ( V_3 -> line ) ) &&
V_97 -- ) {
F_8 ( V_3 , V_7 -> V_100 ,
V_45 -> V_53 [ V_45 -> V_51 ] ) ;
V_45 -> V_51 = ( V_45 -> V_51 + 1 ) & ( V_52 - 1 ) ;
V_3 -> V_95 . V_101 ++ ;
V_98 ++ ;
}
if ( F_45 ( V_45 ) < V_102 )
F_46 ( V_3 ) ;
return V_98 ;
}
static void V_66 ( void * V_103 )
{
struct V_1 * V_5 = (struct V_1 * ) V_103 ;
struct V_2 * V_3 = & V_5 -> V_3 ;
struct V_44 * V_45 = & V_3 -> V_46 -> V_45 ;
unsigned long V_104 ;
F_47 ( & V_3 -> V_76 , V_104 ) ;
V_45 -> V_51 = ( V_45 -> V_51 + V_5 -> V_68 ) &
( V_52 - 1 ) ;
V_3 -> V_95 . V_101 += V_5 -> V_68 ;
if ( F_45 ( V_45 ) < V_102 )
F_46 ( V_3 ) ;
if ( V_5 -> V_59 )
F_48 ( V_3 -> V_60 , V_5 -> V_59 ,
V_5 -> V_68 , V_61 ) ;
V_5 -> V_37 = V_105 ;
F_12 ( V_5 ) ;
F_49 ( & V_3 -> V_76 , V_104 ) ;
}
static void F_50 (
struct V_1 * V_5 , int V_97 )
{
struct V_2 * V_3 = & V_5 -> V_3 ;
struct V_106 * V_107 = & V_3 -> V_46 -> V_3 ;
int V_108 ;
V_108 = F_51 ( V_107 ,
V_5 -> V_109 [ V_5 -> V_110 ] . V_45 . V_53 , V_97 ) ;
V_3 -> V_95 . V_96 += V_108 ;
}
static void F_52 ( struct V_2 * V_3 , int V_111 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
V_5 -> V_109 [ V_111 ] . V_45 . V_51 =
V_5 -> V_109 [ V_111 ] . V_45 . V_50 = 0 ;
V_5 -> V_109 [ V_111 ] . V_112 =
F_20 ( V_5 -> V_71 ,
V_5 -> V_109 [ V_111 ] . V_113 , V_114 ,
V_115 , V_64 ) ;
if ( ! V_5 -> V_109 [ V_111 ] . V_112 ) {
F_21 ( V_3 -> V_60 , L_2 ) ;
return;
}
V_5 -> V_109 [ V_111 ] . V_112 -> V_65 =
V_116 ;
V_5 -> V_109 [ V_111 ] . V_112 -> V_67 = V_5 ;
V_5 -> V_109 [ V_111 ] . V_117 =
F_22 ( V_5 -> V_109 [ V_111 ] . V_112 ) ;
F_23 ( V_5 -> V_71 ) ;
}
static void F_53 ( unsigned long V_103 )
{
struct V_1 * V_5 = (struct V_1 * ) V_103 ;
struct V_2 * V_3 = & V_5 -> V_3 ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_33 * V_34 = & V_5 -> V_8 -> V_35 ;
struct V_118 * V_119 = & V_5 -> V_8 -> V_120 ;
unsigned int V_97 ;
unsigned long V_104 ;
struct V_121 V_122 ;
F_47 ( & V_3 -> V_76 , V_104 ) ;
while ( V_123 == F_54 ( V_5 -> V_71 ,
V_5 -> V_109 [ V_5 -> V_110 ] . V_117 , & V_122 ) ) {
F_50 ( V_5 ,
V_114 ) ;
V_5 -> V_110 ++ ;
V_5 -> V_110 %= V_124 ;
}
V_97 = F_55 ( V_5 -> V_109 [ V_5 -> V_125 ] . V_45 . V_50 ,
V_5 -> V_109 [ V_5 -> V_125 ] . V_45 . V_51 ,
V_114 ) ;
if ( V_97 > 0 )
F_50 ( V_5 , V_97 ) ;
F_8 ( V_3 , V_7 -> V_126 ,
F_4 ( V_3 , V_7 -> V_126 ) |
V_57 ) ;
F_40 ( V_3 , 4 - V_5 -> V_94 ) ;
if ( V_5 -> V_94 == 4 ) {
V_5 -> V_94 = 0 ;
F_8 ( V_3 , V_7 -> V_127 ,
V_119 -> V_128 ) ;
if ( ! V_5 -> V_40 )
F_8 ( V_3 , V_7 -> V_41 ,
F_4 ( V_3 , V_7 -> V_41 ) &
~ ( V_34 -> V_72 ) ) ;
else
F_8 ( V_3 , V_43 ,
V_34 -> V_72 ) ;
F_56 ( V_3 ) ;
} else {
F_8 ( V_3 , V_7 -> V_127 ,
V_119 -> V_128 ) ;
if ( ! V_5 -> V_40 )
F_8 ( V_3 , V_7 -> V_41 ,
F_4 ( V_3 , V_7 -> V_41 ) |
( V_34 -> V_72 ) ) ;
else
F_8 ( V_3 , V_7 -> V_41 ,
V_34 -> V_72 ) ;
}
F_49 ( & V_3 -> V_76 , V_104 ) ;
F_57 ( & V_3 -> V_46 -> V_3 ) ;
}
static void F_58 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = & V_5 -> V_3 ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_33 * V_34 = & V_5 -> V_8 -> V_35 ;
struct V_121 V_122 ;
F_54 ( V_5 -> V_71 ,
V_5 -> V_109 [ V_5 -> V_125 ] . V_117 , & V_122 ) ;
F_27 ( V_5 -> V_71 ) ;
V_5 -> V_109 [ V_5 -> V_125 ] . V_45 . V_50 =
V_114 - V_122 . V_129 ;
if ( ! V_5 -> V_40 )
F_8 ( V_3 , V_7 -> V_41 ,
F_4 ( V_3 , V_7 -> V_41 ) &
~ ( V_34 -> V_130 ) ) ;
else
F_8 ( V_3 , V_43 ,
V_34 -> V_130 ) ;
F_59 ( & V_5 -> V_131 ) ;
}
static void F_60 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = & V_5 -> V_3 ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_33 * V_34 = & V_5 -> V_8 -> V_35 ;
struct V_118 * V_119 = & V_5 -> V_8 -> V_120 ;
F_40 ( V_3 , 4 - V_5 -> V_94 ) ;
if ( V_5 -> V_94 == 4 ) {
V_5 -> V_94 = 0 ;
if ( ! V_5 -> V_40 )
F_8 ( V_3 , V_7 -> V_41 ,
F_4 ( V_3 , V_7 -> V_41 ) &
~ ( V_34 -> V_72 ) ) ;
else
F_8 ( V_3 , V_43 ,
V_34 -> V_72 ) ;
F_8 ( V_3 , V_7 -> V_127 ,
V_119 -> V_132 ) ;
F_56 ( V_3 ) ;
}
}
static T_1 F_61 ( int V_74 , void * V_75 )
{
unsigned long V_133 ;
unsigned long V_134 ;
unsigned long V_135 = V_93 ;
struct V_1 * V_5 = (struct V_1 * ) V_75 ;
struct V_2 * V_3 = & V_5 -> V_3 ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_9 * V_10 = & V_5 -> V_8 -> V_11 ;
struct V_118 * V_119 = & V_5 -> V_8 -> V_120 ;
struct V_33 * V_34 = & V_5 -> V_8 -> V_35 ;
struct V_136 * V_46 = V_3 -> V_46 ;
struct V_44 * V_45 = & V_3 -> V_46 -> V_45 ;
F_33 ( & V_3 -> V_76 ) ;
V_133 = F_4 ( V_3 , V_7 -> V_127 ) ;
F_8 ( V_3 , V_7 -> V_127 , V_133 ) ;
V_133 &= F_4 ( V_3 , V_7 -> V_41 ) ;
if ( F_42 ( V_133 & ( F_62 ( V_3 , V_119 ) ) ) ) {
if ( V_133 & V_119 -> V_137 ) {
V_3 -> V_95 . V_138 ++ ;
if ( F_63 ( V_3 ) )
goto V_139;
}
if ( V_133 & V_119 -> V_140 )
V_3 -> V_95 . V_141 ++ ;
if ( V_133 & V_119 -> V_142 ) {
V_3 -> V_95 . V_143 ++ ;
V_135 = V_144 ;
}
if ( V_133 & V_119 -> V_145 )
V_135 = V_146 ;
F_8 ( V_3 , V_7 -> V_70 , V_147 ) ;
F_8 ( V_3 , V_7 -> V_70 , 0 ) ;
F_8 ( V_3 , V_7 -> V_70 , V_58 ) ;
V_133 &= V_3 -> V_148 ;
F_44 ( V_3 , V_133 ,
V_34 -> V_149 , 0 , V_135 ) ;
}
V_139:
if ( ( V_5 -> V_8 -> V_18 == V_19 ) &&
( V_133 & F_64 ( V_119 ) ) &&
! V_5 -> V_37 ) {
V_134 = F_4 ( V_3 , V_7 -> V_20 ) &
V_21 ;
if ( V_134 != 0 )
V_134 = 0 ;
else
V_134 = 1 ;
F_35 ( V_3 , V_134 ) ;
F_65 ( & V_46 -> V_3 . V_150 ) ;
}
if ( V_5 -> V_71 ) {
if ( V_133 & V_119 -> V_132 )
F_58 ( V_5 ) ;
if ( V_133 & V_119 -> V_128 )
F_60 ( V_5 ) ;
} else {
if ( V_133 & F_66 ( V_119 ) )
F_40 ( V_3 ,
V_151 ) ;
}
F_36 ( & V_3 -> V_76 ) ;
F_57 ( & V_46 -> V_3 ) ;
F_33 ( & V_3 -> V_76 ) ;
if ( V_133 & V_119 -> V_152 ) {
if ( V_5 -> V_36 )
F_12 ( V_5 ) ;
else {
if ( F_14 ( V_45 ) || F_15 ( V_3 ) ) {
F_36 ( & V_3 -> V_76 ) ;
return V_77 ;
} else {
F_18 ( V_5 ,
V_69 ) ;
if ( ( F_14 ( V_45 ) ) &&
( F_4 ( V_3 , V_7 -> V_12 ) &
V_10 -> V_13 ( V_3 -> line ) ) )
F_10 ( V_3 ) ;
}
}
}
F_36 ( & V_3 -> V_76 ) ;
return V_77 ;
}
static void F_67 ( unsigned long V_103 )
{
struct V_1 * V_5 = (struct V_1 * ) V_103 ;
struct V_2 * V_3 = & V_5 -> V_3 ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_33 * V_34 = & V_5 -> V_8 -> V_35 ;
unsigned long V_104 ;
struct V_121 V_122 ;
F_47 ( & V_3 -> V_76 , V_104 ) ;
while ( V_123 == F_54 ( V_5 -> V_71 ,
V_5 -> V_109 [ V_5 -> V_110 ] . V_117 , & V_122 ) ) {
F_50 ( V_5 ,
V_114 ) ;
if ( F_4 ( V_3 , V_7 -> V_41 ) &
V_34 -> V_130 )
F_52 ( V_3 ,
V_5 -> V_110 ++ ) ;
else
V_5 -> V_110 ++ ;
V_5 -> V_110 %= V_124 ;
}
F_49 ( & V_3 -> V_76 , V_104 ) ;
F_57 ( & V_3 -> V_46 -> V_3 ) ;
}
static void V_116 ( void * V_103 )
{
struct V_1 * V_5 = (struct V_1 * ) V_103 ;
unsigned long V_104 ;
F_47 ( & V_5 -> V_3 . V_76 , V_104 ) ;
V_5 -> V_125 ++ ;
V_5 -> V_125 %= V_124 ;
F_59 ( & V_5 -> V_153 ) ;
F_49 ( & V_5 -> V_3 . V_76 , V_104 ) ;
}
static void F_56 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_33 * V_34 = & V_5 -> V_8 -> V_35 ;
int V_154 ;
V_5 -> V_94 = 0 ;
F_8 ( V_3 , V_7 -> V_126 ,
F_4 ( V_3 , V_7 -> V_126 ) &
~ V_57 ) ;
for ( V_154 = 0 ; V_154 < V_124 ; V_154 ++ )
F_52 ( V_3 , V_154 ) ;
V_5 -> V_110 = V_5 -> V_125 = 0 ;
if ( ! V_5 -> V_40 )
F_8 ( V_3 , V_7 -> V_41 ,
F_4 ( V_3 , V_7 -> V_41 ) |
F_26 ( V_3 , V_34 ) ) ;
else
F_8 ( V_3 , V_7 -> V_41 ,
F_26 ( V_3 , V_34 ) ) ;
}
static void F_68 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_33 * V_34 = & V_5 -> V_8 -> V_35 ;
V_5 -> V_94 = 0 ;
F_8 ( V_3 , V_7 -> V_70 , V_147 ) ;
F_8 ( V_3 , V_7 -> V_70 , 0 ) ;
F_8 ( V_3 , V_7 -> V_70 , V_58 ) ;
if ( V_5 -> V_71 )
F_56 ( V_3 ) ;
else {
if ( ! V_5 -> V_40 )
F_8 ( V_3 , V_7 -> V_41 ,
F_4 ( V_3 , V_7 -> V_41 ) |
F_28 ( V_3 , V_34 ) ) ;
else
F_8 ( V_3 , V_7 -> V_41 ,
F_28 ( V_3 , V_34 ) ) ;
}
}
static unsigned int
F_69 ( unsigned long V_155 ,
unsigned long V_156 , unsigned long * V_157 )
{
unsigned long V_158 = ~ 0UL ;
unsigned short V_159 ;
unsigned long V_160 = 0 ;
unsigned long V_161 ;
for ( V_159 = V_162 ;
V_159 <= V_163 ; V_159 ++ ) {
V_161 = V_156 -
( V_156 + ( V_155 * V_159 ) / 2 )
/ ( V_155 * V_159 ) * V_155 * V_159 ;
V_161 = ( V_161 > 0 ) ? V_161 : - V_161 ;
if ( V_161 < V_158 ) {
V_160 = ( 2 * V_156 /
( V_155 * V_159 ) + 1 ) / 2 - 1 ;
if ( V_160 > V_164 )
continue;
V_158 = V_161 ;
* V_157 = V_159 ;
if ( ! V_161 )
break;
}
}
return V_160 ;
}
static unsigned int
F_70 ( unsigned long V_165 ,
unsigned long V_156 , unsigned long * V_166 )
{
unsigned long V_158 = ~ 0UL ;
unsigned short V_159 ;
unsigned int V_167 = 0 ;
unsigned long V_160 ;
unsigned long V_168 ;
int V_161 ;
for ( V_159 = V_162 ;
V_159 <= V_163 ; V_159 ++ ) {
V_160 = ( V_156 / ( V_165 * ( V_159 + 1 ) ) ) - 1 ;
if ( V_160 > V_164 )
continue;
V_168 = V_156 / ( ( V_160 + 1 ) * ( V_159 + 1 ) ) ;
V_161 = V_168 - V_165 ;
V_161 = ( V_161 > 0 ) ? V_161 : - V_161 ;
if ( V_161 < V_158 ) {
V_167 = V_167 & ( ~ V_169 ) ;
V_167 = V_167 | V_160 ;
V_167 = V_167 & ( ~ V_170 ) ;
V_167 = V_167 | ( V_159 << V_171 ) ;
V_158 = V_161 ;
* V_166 = V_168 ;
}
}
return V_167 ;
}
static void F_71 ( struct V_2 * V_3 ,
struct V_172 * V_173 ,
struct V_172 * V_174 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_33 * V_34 = & V_5 -> V_8 -> V_35 ;
unsigned long V_175 = 0 ;
unsigned long V_165 ;
unsigned long V_166 ;
unsigned long V_104 ;
unsigned long V_176 ;
unsigned int V_177 = 0 ;
unsigned long V_178 , V_156 ;
unsigned long V_179 ;
int V_180 ;
T_2 V_181 , V_182 , V_183 ;
unsigned long V_184 = 0xf ;
V_156 = V_3 -> V_185 ;
switch ( V_173 -> V_186 & V_187 ) {
default:
case V_188 :
V_181 = 8 ;
V_175 |= V_189 ;
break;
case V_190 :
V_181 = 7 ;
V_175 |= V_191 ;
break;
case V_192 :
V_181 = 6 ;
V_175 |= V_193 ;
break;
case V_194 :
V_181 = 5 ;
V_175 |= V_195 ;
break;
}
if ( V_173 -> V_186 & V_196 ) {
V_175 |= V_197 ;
V_182 = 2 ;
} else
V_182 = 1 ;
F_47 ( & V_3 -> V_76 , V_104 ) ;
V_3 -> V_148 = V_34 -> V_149 ;
V_3 -> V_198 = 0 ;
if ( V_5 -> V_8 -> V_18 == V_19 ) {
if ( V_173 -> V_199 & V_200 )
V_3 -> V_148 |= V_34 -> V_201 |
V_34 -> V_202 ;
} else {
if ( V_173 -> V_199 & V_200 )
V_3 -> V_148 |= V_34 -> V_201 ;
}
if ( V_173 -> V_199 & ( V_203 | V_204 | V_205 ) )
V_3 -> V_148 |= V_34 -> V_206 ;
if ( V_5 -> V_8 -> V_18 == V_19 ) {
if ( V_173 -> V_199 & V_207 )
V_3 -> V_198 |=
V_34 -> V_201 |
V_34 -> V_202 ;
if ( V_173 -> V_186 & V_208 ) {
if ( V_173 -> V_186 & V_209 ) {
if ( V_173 -> V_186 & V_210 )
V_175 |= V_211 ;
else
V_175 |= V_212 ;
} else if ( V_173 -> V_186 & V_210 ) {
V_175 |= V_213 ;
} else {
V_175 |= V_214 ;
}
}
} else {
if ( V_173 -> V_199 & V_207 )
V_3 -> V_198 |=
V_34 -> V_201 ;
if ( V_173 -> V_186 & V_208 )
F_72 ( V_3 -> V_60 ,
L_3 ) ;
}
if ( V_173 -> V_199 & V_203 ) {
V_3 -> V_198 |=
V_34 -> V_206 ;
if ( V_173 -> V_199 & V_207 )
V_3 -> V_198 |=
V_34 -> V_149 ;
}
if ( ( V_173 -> V_186 & V_215 ) == 0 )
V_3 -> V_198 |= V_92 ;
if ( F_73 ( V_3 , V_173 -> V_186 ) ) {
if ( ! V_5 -> V_16 )
F_37 ( V_3 ) ;
} else {
if ( V_5 -> V_16 )
F_29 ( V_3 ) ;
}
V_165 = F_74 ( V_3 , V_173 , V_174 , 0 , 4000000 ) ;
if ( V_156 == 150000000 ) {
for ( V_176 = 0 ; V_176 < V_216 ; V_176 ++ )
if ( V_165 == V_217 [ V_176 ] . V_165 )
V_177 = V_217 [ V_176 ] . V_218 ;
}
V_166 = V_165 ;
if ( V_5 -> V_8 -> V_18 == V_19 ) {
if ( F_42 ( V_177 == 0 ) )
V_177 = F_70 ( V_165 ,
V_156 , & V_166 ) ;
F_8 ( V_3 , V_7 -> V_219 , V_177 ) ;
} else {
V_177 = F_69 ( V_165 ,
V_156 , & V_184 ) ;
V_184 -- ;
V_166 = ( ( V_156 / ( V_177 + 1 ) - 1 ) /
( V_184 + 1 ) ) ;
V_183 = ( ( 1 << V_220 ) |
( 1 << V_221 ) ) ;
V_183 |= ( ( V_177 & V_222 )
<< V_223 ) ;
F_8 ( V_3 , V_7 -> V_224 , V_183 ) ;
}
if ( F_75 ( V_173 ) )
F_76 ( V_173 , V_166 , V_166 ) ;
V_179 = F_77 ( V_166 , 20000 ) ;
V_179 = F_78 ( V_179 ) ;
V_178 = F_4 ( V_3 , V_7 -> V_54 ) ;
F_8 ( V_3 , V_7 -> V_70 , V_55 ) ;
F_8 ( V_3 , V_7 -> V_54 ,
( V_178 & ~ V_58 ) ) ;
if ( V_5 -> V_8 -> V_18 == V_19 ) {
V_175 |= F_79 ( V_3 , V_179 ) ;
F_8 ( V_3 , V_7 -> V_82 , V_175 ) ;
} else {
V_183 = ( V_181 - 1 ) << V_225 ;
V_183 |= ( V_181 + 1 + V_182 - 1 ) <<
V_226 ;
V_183 |= ( ( V_181 - 1 ) <<
V_227 ) ;
V_183 |= ( ( ( V_177 & 0xc00 ) >> 10 ) <<
V_228 ) ;
F_8 ( V_3 , V_7 -> V_229 , V_183 ) ;
V_183 = ( V_181 - 1 ) << V_230 ;
V_183 |= ( V_181 + 1 + V_182 - 1 ) <<
V_231 ;
V_183 |= ( V_181 - 1 ) <<
V_232 ;
V_183 |= ( ( ( V_177 & 0xf000 ) >> 12 ) <<
V_233 ) ;
F_8 ( V_3 , V_7 -> V_234 , V_183 ) ;
F_8 ( V_3 , V_7 -> V_235 ,
( F_79 ( V_3 , V_179 ) ) |
( V_184 & V_236 ) <<
V_237 ) ;
}
if ( V_5 -> V_36 )
F_8 ( V_3 , V_7 -> V_56 , V_238 ) ;
else
F_8 ( V_3 , V_7 -> V_56 , V_57 ) ;
if ( V_5 -> V_71 )
F_8 ( V_3 , V_7 -> V_126 , V_238 ) ;
else
F_8 ( V_3 , V_7 -> V_126 , V_57 ) ;
if ( V_166 < 1000000 )
V_180 = 1 ;
else
V_180 = 2 ;
F_8 ( V_3 , V_7 -> V_239 ,
F_80 ( V_3 ) / V_180 ) ;
F_8 ( V_3 , V_7 -> V_240 ,
F_80 ( V_3 ) / V_180 ) ;
V_178 |= V_58 ;
F_8 ( V_3 , V_7 -> V_54 , V_178 ) ;
F_81 ( V_3 , V_173 -> V_186 , V_166 ) ;
F_68 ( V_3 ) ;
F_8 ( V_3 , V_7 -> V_241 , V_242 | V_243 ) ;
F_49 ( & V_3 -> V_76 , V_104 ) ;
}
static void F_82 ( struct V_2 * V_3 , unsigned int V_46 ,
unsigned int V_244 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( ! V_46 ) {
if ( V_5 -> V_245 ) {
F_83 ( V_5 -> V_246 ) ;
F_83 ( V_5 -> V_247 ) ;
}
F_83 ( V_5 -> V_248 ) ;
} else {
F_84 ( V_5 -> V_248 ) ;
if ( V_5 -> V_245 ) {
F_84 ( V_5 -> V_247 ) ;
F_84 ( V_5 -> V_246 ) ;
}
}
}
static int F_85 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
unsigned int V_111 = V_3 -> line ;
int V_249 ;
F_86 ( V_3 -> V_74 , V_250 | V_251 ) ;
V_249 = F_87 ( V_3 -> V_74 ,
F_61 ,
0 ,
V_252 ,
V_5 ) ;
if ( V_249 != 0 ) {
F_21 ( V_3 -> V_60 , L_4 ,
V_111 , V_3 -> V_74 ) ;
goto V_253;
}
F_8 ( V_3 , V_7 -> V_56 ,
F_4 ( V_3 , V_7 -> V_56 ) |
V_57 ) ;
F_8 ( V_3 , V_7 -> V_126 ,
F_4 ( V_3 , V_7 -> V_126 ) |
V_57 ) ;
F_8 ( V_3 , V_7 -> V_254 , 0 ) ;
F_8 ( V_3 , V_7 -> V_255 , 0 ) ;
F_8 ( V_3 , V_7 -> V_241 , V_243 | V_242 ) ;
if ( V_5 -> V_8 -> V_18 == V_256 )
F_8 ( V_3 , V_7 -> V_257 ,
V_258 |
V_259 ) ;
F_8 ( V_3 , V_7 -> V_54 , V_147 ) ;
F_8 ( V_3 , V_7 -> V_54 , 0 ) ;
F_8 ( V_3 , V_7 -> V_70 , V_147 ) ;
F_8 ( V_3 , V_7 -> V_70 , 0 ) ;
F_8 ( V_3 , V_7 -> V_239 , F_80 ( V_3 ) ) ;
F_8 ( V_3 , V_7 -> V_240 , F_80 ( V_3 ) ) ;
if ( V_5 -> V_71 )
F_8 ( V_3 , V_7 -> V_260 ,
F_88 ( V_3 -> line , 0x4 ) |
F_89 ( V_3 -> line , 0xe ) |
F_90 ( V_3 -> line , 0x1b ) ) ;
if ( V_5 -> V_36 ) {
V_5 -> V_37 = V_105 ;
F_8 ( V_3 , V_7 -> V_261 ,
F_91 ( V_3 -> line , 0x1b ) |
F_92 ( V_3 -> line , 0xe ) |
F_93 ( V_3 -> line , 0x4 ) ) ;
}
V_5 -> V_16 = false ;
if ( V_5 -> V_8 -> V_18 == V_256 &&
V_5 -> V_15 ) {
F_86 ( F_31 ( V_5 -> V_23 ) ,
V_250 | V_251 ) ;
V_249 = F_87 ( F_31 ( V_5 -> V_23 ) ,
F_32 , V_262 |
V_263 , L_5 , V_5 ) ;
if ( V_249 != 0 ) {
F_21 ( V_3 -> V_60 , L_6 ) ;
goto V_264;
}
}
F_38 ( V_3 -> V_74 ) ;
return 0 ;
V_264:
F_94 ( V_3 -> V_74 , V_5 ) ;
V_253:
return V_249 ;
}
static void F_95 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
if ( ! V_5 -> V_40 )
F_8 ( V_3 , V_7 -> V_41 , 0 ) ;
else
F_8 ( V_3 , V_43 , ~ 0UL ) ;
F_94 ( V_3 -> V_74 , V_5 ) ;
if ( V_5 -> V_16 )
F_29 ( V_3 ) ;
if ( V_5 -> V_8 -> V_18 == V_256 &&
V_5 -> V_15 ) {
F_9 ( V_5 -> V_32 , 1 ) ;
F_94 ( F_31 ( V_5 -> V_23 ) , V_5 ) ;
}
if ( V_5 -> V_36 )
V_5 -> V_37 = V_105 ;
}
static const char * F_96 ( struct V_2 * V_3 )
{
return V_3 -> type == V_265 ? V_252 : NULL ;
}
static int F_97 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_266 * V_267 = & V_5 -> V_8 -> V_267 ;
void * V_249 ;
V_249 = F_98 ( V_3 -> V_268 ,
V_269 , V_267 -> V_270 ) ;
return V_249 ? 0 : - V_271 ;
}
static void F_99 ( struct V_2 * V_3 )
{
F_100 ( V_3 -> V_268 , V_269 ) ;
}
static void F_101 ( struct V_2 * V_3 , int V_104 )
{
if ( V_104 & V_272 ) {
V_3 -> type = V_265 ;
F_97 ( V_3 ) ;
}
}
static int T_3
F_102 ( struct V_273 * V_274 , char * V_275 )
{
unsigned int V_276 = 115200 ;
unsigned int V_277 = 8 ;
unsigned int V_278 = 'n' ;
unsigned int V_279 = 'n' ;
struct V_2 * V_3 = & V_280 [ V_274 -> V_111 ] . V_3 ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
if ( V_274 -> V_111 < 0 || V_274 -> V_111 >= V_281 )
return - V_282 ;
if ( ! V_3 -> V_268 )
return - V_89 ;
if ( V_5 -> V_8 -> V_18 == V_256 )
F_8 ( V_3 , V_7 -> V_257 , V_259 |
V_258 ) ;
if ( V_275 )
F_103 ( V_275 , & V_276 , & V_278 , & V_277 , & V_279 ) ;
V_3 -> V_283 = V_274 ;
V_5 -> V_71 = NULL ;
V_5 -> V_36 = NULL ;
return F_104 ( V_3 , V_274 , V_276 , V_278 , V_277 , V_279 ) ;
}
static void F_105 ( struct V_2 * V_3 , int V_85 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_9 * V_10 = & V_5 -> V_8 -> V_11 ;
while ( F_4 ( V_3 ,
V_7 -> V_12 ) & V_10 -> V_99 ( V_3 -> line ) )
F_106 () ;
F_8 ( V_3 , V_7 -> V_100 , V_85 ) ;
}
static void F_107 ( struct V_273 * V_274 , const char * V_284 ,
unsigned int V_97 )
{
struct V_2 * V_3 = & V_280 [ V_274 -> V_111 ] . V_3 ;
F_108 ( V_3 , V_284 , V_97 , F_105 ) ;
}
static int T_3 F_109 ( void )
{
F_110 ( & V_285 ) ;
return 0 ;
}
static int F_111 ( struct V_286 * V_287 )
{
struct V_1 * V_5 ;
struct V_2 * V_3 ;
struct V_288 * V_289 ;
int V_249 ;
int V_154 , V_290 ;
struct V_291 V_292 = {
. V_293 = 2 ,
} ;
struct V_291 V_294 = {
. V_295 = 2 ,
} ;
const struct V_296 * V_297 ;
V_297 = F_112 ( V_298 , V_287 -> V_60 . V_299 ) ;
if ( F_113 ( V_287 -> V_60 . V_299 , L_7 , & V_287 -> V_300 ) ) {
F_21 ( & V_287 -> V_60 ,
L_8 ) ;
V_249 = - V_301 ;
goto V_302;
}
if ( F_114 ( V_287 -> V_60 . V_299 , L_9 ) )
V_287 -> V_300 += ( (struct V_303 * )
V_297 -> V_304 ) -> V_267 . V_305 ;
V_5 = & V_280 [ V_287 -> V_300 ] ;
V_3 = & V_5 -> V_3 ;
V_3 -> V_60 = & V_287 -> V_60 ;
V_3 -> V_306 = V_5 ;
V_5 -> V_8 = (struct V_303 * ) V_297 -> V_304 ;
V_5 -> V_15 = F_115 ( V_287 -> V_60 . V_299 ,
L_10 ) ;
if ( F_114 ( V_287 -> V_60 . V_299 , L_11 ) )
V_5 -> V_8 -> V_18 = V_19 ;
if ( F_114 ( V_287 -> V_60 . V_299 , L_9 ) ) {
V_5 -> V_8 -> V_18 = V_256 ;
if ( ! V_5 -> V_15 )
goto V_307;
if ( F_116 ( V_287 -> V_60 . V_299 , L_12 , NULL ) )
V_5 -> V_23 = F_117 (
V_287 -> V_60 . V_299 , L_12 , 0 ) ;
else
V_5 -> V_23 = - 1 ;
if ( F_116 ( V_287 -> V_60 . V_299 , L_13 , NULL ) )
V_5 -> V_32 = F_117 (
V_287 -> V_60 . V_299 , L_13 , 0 ) ;
else
V_5 -> V_32 = - 1 ;
if ( ( ! F_34 ( V_5 -> V_23 ) ||
! F_34 ( V_5 -> V_32 ) ) ) {
V_249 = - V_282 ;
F_21 ( & V_287 -> V_60 ,
L_14 ) ;
goto V_302;
}
V_249 = F_118 ( & V_287 -> V_60 , V_5 -> V_23 ,
L_15 ) ;
if ( V_249 ) {
F_21 ( & V_287 -> V_60 , L_16 ) ;
goto V_302;
}
F_119 ( V_5 -> V_23 ) ;
V_249 = F_118 ( & V_287 -> V_60 , V_5 -> V_32 ,
L_17 ) ;
if ( V_249 ) {
F_21 ( & V_287 -> V_60 , L_18 ) ;
goto V_302;
}
F_120 ( V_5 -> V_32 , 1 ) ;
}
V_307:
if ( F_114 ( V_287 -> V_60 . V_299 , L_19 ) )
V_5 -> V_40 = true ;
if ( F_113 ( V_287 -> V_60 . V_299 ,
L_20 ,
& V_3 -> V_308 ) ) {
F_21 ( & V_287 -> V_60 ,
L_21 ) ;
V_249 = - V_301 ;
goto V_302;
}
V_289 = F_121 ( V_287 , V_309 , 0 ) ;
if ( V_289 == NULL ) {
F_21 ( & V_287 -> V_60 , L_22 ) ;
V_249 = - V_301 ;
goto V_302;
}
F_122 ( & V_5 -> V_153 ,
F_67 , ( unsigned long ) V_5 ) ;
F_122 ( & V_5 -> V_131 ,
F_53 , ( unsigned long ) V_5 ) ;
V_3 -> V_268 = V_289 -> V_310 ;
V_3 -> V_311 = F_123 ( & V_287 -> V_60 , V_289 -> V_310 , F_124 ( V_289 ) ) ;
if ( ! V_3 -> V_311 ) {
F_21 ( & V_287 -> V_60 , L_23 ) ;
V_249 = - V_312 ;
goto V_302;
}
V_289 = F_121 ( V_287 , V_313 , 0 ) ;
if ( V_289 == NULL ) {
F_21 ( & V_287 -> V_60 , L_22 ) ;
V_249 = - V_301 ;
goto V_302;
}
V_3 -> V_74 = V_289 -> V_310 ;
V_5 -> V_248 = F_125 ( & V_287 -> V_60 , NULL ) ;
if ( F_126 ( V_5 -> V_248 ) ) {
V_249 = F_127 ( V_5 -> V_248 ) ;
goto V_302;
}
V_3 -> V_185 = F_128 ( V_5 -> V_248 ) ;
if ( F_114 ( V_287 -> V_60 . V_299 , L_24 ) ) {
V_5 -> V_247 = F_125 ( & V_287 -> V_60 , L_25 ) ;
if ( F_126 ( V_5 -> V_247 ) ) {
V_249 = F_127 ( V_5 -> V_247 ) ;
goto V_302;
}
V_5 -> V_246 = F_125 ( & V_287 -> V_60 , L_26 ) ;
if ( F_126 ( V_5 -> V_246 ) ) {
V_249 = F_127 ( V_5 -> V_246 ) ;
goto V_302;
}
V_5 -> V_245 = true ;
} else
V_5 -> V_245 = false ;
V_3 -> V_314 = & V_315 ;
F_129 ( & V_3 -> V_76 ) ;
F_130 ( V_287 , V_5 ) ;
V_249 = F_131 ( & V_316 , V_3 ) ;
if ( V_249 != 0 ) {
F_21 ( & V_287 -> V_60 , L_27 , V_287 -> V_300 ) ;
goto V_302;
}
V_5 -> V_71 = F_132 ( V_3 -> V_60 , L_28 ) ;
for ( V_154 = 0 ; V_5 -> V_71 && V_154 < V_124 ; V_154 ++ ) {
V_5 -> V_109 [ V_154 ] . V_45 . V_53 =
F_133 ( V_3 -> V_60 , V_114 ,
& V_5 -> V_109 [ V_154 ] . V_113 , V_317 ) ;
if ( ! V_5 -> V_109 [ V_154 ] . V_45 . V_53 ) {
F_21 ( V_3 -> V_60 , L_29 ) ;
V_249 = - V_312 ;
goto V_318;
}
V_5 -> V_109 [ V_154 ] . V_45 . V_50 =
V_5 -> V_109 [ V_154 ] . V_45 . V_51 = 0 ;
}
if ( V_5 -> V_71 )
F_134 ( V_5 -> V_71 , & V_292 ) ;
V_5 -> V_36 = F_132 ( V_3 -> V_60 , L_30 ) ;
if ( V_5 -> V_36 )
F_134 ( V_5 -> V_36 , & V_294 ) ;
return 0 ;
V_318:
for ( V_290 = 0 ; V_290 < V_154 ; V_290 ++ )
F_135 ( V_3 -> V_60 , V_114 ,
V_5 -> V_109 [ V_290 ] . V_45 . V_53 ,
V_5 -> V_109 [ V_290 ] . V_113 ) ;
F_136 ( V_5 -> V_71 ) ;
V_302:
return V_249 ;
}
static int F_137 ( struct V_286 * V_287 )
{
struct V_1 * V_5 = F_138 ( V_287 ) ;
struct V_2 * V_3 = & V_5 -> V_3 ;
F_139 ( & V_316 , V_3 ) ;
if ( V_5 -> V_71 ) {
int V_154 ;
F_27 ( V_5 -> V_71 ) ;
F_136 ( V_5 -> V_71 ) ;
for ( V_154 = 0 ; V_154 < V_124 ; V_154 ++ )
F_135 ( V_3 -> V_60 , V_114 ,
V_5 -> V_109 [ V_154 ] . V_45 . V_53 ,
V_5 -> V_109 [ V_154 ] . V_113 ) ;
}
if ( V_5 -> V_36 ) {
F_27 ( V_5 -> V_36 ) ;
F_136 ( V_5 -> V_36 ) ;
}
return 0 ;
}
static int
F_140 ( struct V_319 * V_287 )
{
struct V_1 * V_5 = F_141 ( V_287 ) ;
struct V_2 * V_3 = & V_5 -> V_3 ;
F_142 ( & V_316 , V_3 ) ;
return 0 ;
}
static int F_143 ( struct V_319 * V_287 )
{
struct V_1 * V_5 = F_141 ( V_287 ) ;
struct V_2 * V_3 = & V_5 -> V_3 ;
F_144 ( & V_316 , V_3 ) ;
return 0 ;
}
static int T_3 F_145 ( void )
{
int V_249 = 0 ;
V_249 = F_146 ( & V_316 ) ;
if ( V_249 )
goto V_320;
V_249 = F_147 ( & V_321 ) ;
if ( V_249 )
F_148 ( & V_316 ) ;
V_320:
return V_249 ;
}
static void T_4 F_149 ( void )
{
F_150 ( & V_321 ) ;
F_148 ( & V_316 ) ;
}
