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
F_18 ( V_5 , 1 ) ;
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
F_8 ( V_3 , V_7 -> V_69 , 0 ) ;
if ( V_5 -> V_70 ) {
if ( ! V_5 -> V_40 )
F_8 ( V_3 , V_7 -> V_41 ,
F_4 ( V_3 , V_7 -> V_41 ) &
~ ( F_26 ( V_3 , V_34 ) |
V_34 -> V_71 ) ) ;
else
F_8 ( V_3 , V_43 ,
F_26 ( V_3 , V_34 ) |
V_34 -> V_71 ) ;
F_27 ( V_5 -> V_70 ) ;
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
~ V_34 -> V_72 ) ;
else
F_8 ( V_3 , V_43 ,
V_34 -> V_72 ) ;
} else
F_30 ( F_31 ( V_5 -> V_23 ) ) ;
}
static T_1 F_32 ( int V_73 , void * V_74 )
{
struct V_1 * V_5 = (struct V_1 * ) V_74 ;
struct V_2 * V_3 = & V_5 -> V_3 ;
F_33 ( & V_3 -> V_75 ) ;
if ( F_34 ( V_5 -> V_23 ) && V_5 -> V_16 )
F_35 ( V_3 ,
! F_6 ( V_5 -> V_23 ) ) ;
F_36 ( & V_3 -> V_75 ) ;
return V_76 ;
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
V_77 | V_78 ) ;
if ( ! V_5 -> V_40 )
F_8 ( V_3 , V_7 -> V_41 ,
F_4 ( V_3 , V_7 -> V_41 )
| V_34 -> V_72 ) ;
else
F_8 ( V_3 , V_7 -> V_41 ,
V_34 -> V_72 ) ;
} else
F_38 ( F_31 ( V_5 -> V_23 ) ) ;
}
static void F_39 ( struct V_2 * V_3 , int V_79 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
if ( V_5 -> V_8 -> V_18 == V_19 ) {
unsigned long V_80 = F_4 ( V_3 , V_7 -> V_81 ) ;
if ( V_79 )
V_80 |= V_82 ;
else
V_80 &= ~ V_82 ;
F_8 ( V_3 , V_7 -> V_81 , V_80 ) ;
}
}
static unsigned int
F_40 ( struct V_2 * V_3 , unsigned int V_83 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_9 * V_10 = & V_5 -> V_8 -> V_11 ;
unsigned int V_84 , V_85 = 0 ;
struct V_86 * V_87 ;
V_87 = F_41 ( & V_3 -> V_46 -> V_3 ) ;
if ( ! V_87 )
return - V_88 ;
while ( ! ( F_4 ( V_3 , V_7 -> V_89 ) &
V_10 -> V_13 ( V_3 -> line ) ) ) {
V_84 = F_4 ( V_3 , V_7 -> V_90 ) |
V_91 ;
if ( F_42 ( F_43 ( V_3 , V_84 ) ) )
continue;
F_44 ( V_3 , 0 , 0 , V_84 , V_92 ) ;
V_85 ++ ;
if ( V_85 >= V_83 )
break;
}
V_5 -> V_93 += V_85 ;
V_3 -> V_94 . V_95 += V_85 ;
return V_85 ;
}
static unsigned int
F_18 ( struct V_1 * V_5 , int V_96 )
{
struct V_2 * V_3 = & V_5 -> V_3 ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_9 * V_10 = & V_5 -> V_8 -> V_11 ;
struct V_44 * V_45 = & V_3 -> V_46 -> V_45 ;
unsigned int V_97 = 0 ;
while ( ! F_14 ( V_45 ) &&
! ( F_4 ( V_3 , V_7 -> V_12 ) &
V_10 -> V_98 ( V_3 -> line ) ) &&
V_96 -- ) {
F_8 ( V_3 , V_7 -> V_99 ,
V_45 -> V_53 [ V_45 -> V_51 ] ) ;
V_45 -> V_51 = ( V_45 -> V_51 + 1 ) & ( V_52 - 1 ) ;
V_3 -> V_94 . V_100 ++ ;
V_97 ++ ;
}
if ( F_45 ( V_45 ) < V_101 )
F_46 ( V_3 ) ;
return V_97 ;
}
static void V_66 ( void * V_102 )
{
struct V_1 * V_5 = (struct V_1 * ) V_102 ;
struct V_2 * V_3 = & V_5 -> V_3 ;
struct V_44 * V_45 = & V_3 -> V_46 -> V_45 ;
unsigned long V_103 ;
F_47 ( & V_3 -> V_75 , V_103 ) ;
V_45 -> V_51 = ( V_45 -> V_51 + V_5 -> V_68 ) &
( V_52 - 1 ) ;
V_3 -> V_94 . V_100 += V_5 -> V_68 ;
if ( F_45 ( V_45 ) < V_101 )
F_46 ( V_3 ) ;
if ( V_5 -> V_59 )
F_48 ( V_3 -> V_60 , V_5 -> V_59 ,
V_5 -> V_68 , V_61 ) ;
V_5 -> V_37 = V_104 ;
F_12 ( V_5 ) ;
F_49 ( & V_3 -> V_75 , V_103 ) ;
}
static void F_50 (
struct V_1 * V_5 , int V_96 )
{
struct V_2 * V_3 = & V_5 -> V_3 ;
struct V_105 * V_106 = & V_3 -> V_46 -> V_3 ;
int V_107 ;
V_107 = F_51 ( V_106 ,
V_5 -> V_108 [ V_5 -> V_109 ] . V_45 . V_53 , V_96 ) ;
V_3 -> V_94 . V_95 += V_107 ;
}
static void F_52 ( struct V_2 * V_3 , int V_110 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
V_5 -> V_108 [ V_110 ] . V_45 . V_51 =
V_5 -> V_108 [ V_110 ] . V_45 . V_50 = 0 ;
V_5 -> V_108 [ V_110 ] . V_111 =
F_20 ( V_5 -> V_70 ,
V_5 -> V_108 [ V_110 ] . V_112 , V_113 ,
V_114 , V_64 ) ;
if ( ! V_5 -> V_108 [ V_110 ] . V_111 ) {
F_21 ( V_3 -> V_60 , L_2 ) ;
return;
}
V_5 -> V_108 [ V_110 ] . V_111 -> V_65 =
V_115 ;
V_5 -> V_108 [ V_110 ] . V_111 -> V_67 = V_5 ;
V_5 -> V_108 [ V_110 ] . V_116 =
F_22 ( V_5 -> V_108 [ V_110 ] . V_111 ) ;
F_23 ( V_5 -> V_70 ) ;
}
static void F_53 ( unsigned long V_102 )
{
struct V_1 * V_5 = (struct V_1 * ) V_102 ;
struct V_2 * V_3 = & V_5 -> V_3 ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_33 * V_34 = & V_5 -> V_8 -> V_35 ;
struct V_117 * V_118 = & V_5 -> V_8 -> V_119 ;
unsigned int V_96 ;
unsigned long V_103 ;
struct V_120 V_121 ;
F_47 ( & V_3 -> V_75 , V_103 ) ;
while ( V_122 == F_54 ( V_5 -> V_70 ,
V_5 -> V_108 [ V_5 -> V_109 ] . V_116 , & V_121 ) ) {
F_50 ( V_5 ,
V_113 ) ;
V_5 -> V_109 ++ ;
V_5 -> V_109 %= V_123 ;
}
V_96 = F_55 ( V_5 -> V_108 [ V_5 -> V_124 ] . V_45 . V_50 ,
V_5 -> V_108 [ V_5 -> V_124 ] . V_45 . V_51 ,
V_113 ) ;
if ( V_96 > 0 )
F_50 ( V_5 , V_96 ) ;
F_8 ( V_3 , V_7 -> V_125 ,
F_4 ( V_3 , V_7 -> V_125 ) |
V_57 ) ;
F_40 ( V_3 , 4 - V_5 -> V_93 ) ;
if ( V_5 -> V_93 == 4 ) {
V_5 -> V_93 = 0 ;
F_8 ( V_3 , V_7 -> V_126 ,
V_118 -> V_127 ) ;
if ( ! V_5 -> V_40 )
F_8 ( V_3 , V_7 -> V_41 ,
F_4 ( V_3 , V_7 -> V_41 ) &
~ ( V_34 -> V_71 ) ) ;
else
F_8 ( V_3 , V_43 ,
V_34 -> V_71 ) ;
F_56 ( V_3 ) ;
} else {
F_8 ( V_3 , V_7 -> V_126 ,
V_118 -> V_127 ) ;
if ( ! V_5 -> V_40 )
F_8 ( V_3 , V_7 -> V_41 ,
F_4 ( V_3 , V_7 -> V_41 ) |
( V_34 -> V_71 ) ) ;
else
F_8 ( V_3 , V_7 -> V_41 ,
V_34 -> V_71 ) ;
}
F_49 ( & V_3 -> V_75 , V_103 ) ;
F_57 ( & V_3 -> V_46 -> V_3 ) ;
}
static void F_58 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = & V_5 -> V_3 ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_33 * V_34 = & V_5 -> V_8 -> V_35 ;
struct V_120 V_121 ;
F_54 ( V_5 -> V_70 ,
V_5 -> V_108 [ V_5 -> V_124 ] . V_116 , & V_121 ) ;
F_27 ( V_5 -> V_70 ) ;
V_5 -> V_108 [ V_5 -> V_124 ] . V_45 . V_50 =
V_113 - V_121 . V_128 ;
if ( ! V_5 -> V_40 )
F_8 ( V_3 , V_7 -> V_41 ,
F_4 ( V_3 , V_7 -> V_41 ) &
~ ( V_34 -> V_129 ) ) ;
else
F_8 ( V_3 , V_43 ,
V_34 -> V_129 ) ;
F_59 ( & V_5 -> V_130 ) ;
}
static void F_60 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = & V_5 -> V_3 ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_33 * V_34 = & V_5 -> V_8 -> V_35 ;
struct V_117 * V_118 = & V_5 -> V_8 -> V_119 ;
F_40 ( V_3 , 4 - V_5 -> V_93 ) ;
if ( V_5 -> V_93 == 4 ) {
V_5 -> V_93 = 0 ;
if ( ! V_5 -> V_40 )
F_8 ( V_3 , V_7 -> V_41 ,
F_4 ( V_3 , V_7 -> V_41 ) &
~ ( V_34 -> V_71 ) ) ;
else
F_8 ( V_3 , V_43 ,
V_34 -> V_71 ) ;
F_8 ( V_3 , V_7 -> V_126 ,
V_118 -> V_131 ) ;
F_56 ( V_3 ) ;
}
}
static T_1 F_61 ( int V_73 , void * V_74 )
{
unsigned long V_132 ;
unsigned long V_133 ;
unsigned long V_134 = V_92 ;
struct V_1 * V_5 = (struct V_1 * ) V_74 ;
struct V_2 * V_3 = & V_5 -> V_3 ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_9 * V_10 = & V_5 -> V_8 -> V_11 ;
struct V_117 * V_118 = & V_5 -> V_8 -> V_119 ;
struct V_33 * V_34 = & V_5 -> V_8 -> V_35 ;
struct V_135 * V_46 = V_3 -> V_46 ;
struct V_44 * V_45 = & V_3 -> V_46 -> V_45 ;
F_33 ( & V_3 -> V_75 ) ;
V_132 = F_4 ( V_3 , V_7 -> V_126 ) ;
F_8 ( V_3 , V_7 -> V_126 , V_132 ) ;
V_132 &= F_4 ( V_3 , V_7 -> V_41 ) ;
if ( F_42 ( V_132 & ( F_62 ( V_3 , V_118 ) ) ) ) {
if ( V_132 & V_118 -> V_136 ) {
V_3 -> V_94 . V_137 ++ ;
if ( F_63 ( V_3 ) )
goto V_138;
}
if ( V_132 & V_118 -> V_139 )
V_3 -> V_94 . V_140 ++ ;
if ( V_132 & V_118 -> V_141 ) {
V_3 -> V_94 . V_142 ++ ;
V_134 = V_143 ;
}
if ( V_132 & V_118 -> V_144 )
V_134 = V_145 ;
F_8 ( V_3 , V_7 -> V_69 , V_146 ) ;
F_8 ( V_3 , V_7 -> V_69 , 0 ) ;
F_8 ( V_3 , V_7 -> V_69 , V_58 ) ;
V_132 &= V_3 -> V_147 ;
F_44 ( V_3 , V_132 ,
V_34 -> V_148 , 0 , V_134 ) ;
}
V_138:
if ( ( V_5 -> V_8 -> V_18 == V_19 ) &&
( V_132 & F_64 ( V_118 ) ) &&
! V_5 -> V_37 ) {
V_133 = F_4 ( V_3 , V_7 -> V_20 ) &
V_21 ;
if ( V_133 != 0 )
V_133 = 0 ;
else
V_133 = 1 ;
F_35 ( V_3 , V_133 ) ;
F_65 ( & V_46 -> V_3 . V_149 ) ;
}
if ( V_5 -> V_70 ) {
if ( V_132 & V_118 -> V_131 )
F_58 ( V_5 ) ;
if ( V_132 & V_118 -> V_127 )
F_60 ( V_5 ) ;
} else {
if ( V_132 & F_66 ( V_118 ) )
F_40 ( V_3 ,
V_150 ) ;
}
F_36 ( & V_3 -> V_75 ) ;
F_57 ( & V_46 -> V_3 ) ;
F_33 ( & V_3 -> V_75 ) ;
if ( V_132 & V_118 -> V_151 ) {
if ( V_5 -> V_36 )
F_12 ( V_5 ) ;
else {
if ( F_14 ( V_45 ) || F_15 ( V_3 ) ) {
F_36 ( & V_3 -> V_75 ) ;
return V_76 ;
} else {
F_18 ( V_5 ,
V_152 ) ;
if ( ( F_14 ( V_45 ) ) &&
( F_4 ( V_3 , V_7 -> V_12 ) &
V_10 -> V_13 ( V_3 -> line ) ) )
F_10 ( V_3 ) ;
}
}
}
F_36 ( & V_3 -> V_75 ) ;
return V_76 ;
}
static void F_67 ( unsigned long V_102 )
{
struct V_1 * V_5 = (struct V_1 * ) V_102 ;
struct V_2 * V_3 = & V_5 -> V_3 ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_33 * V_34 = & V_5 -> V_8 -> V_35 ;
unsigned long V_103 ;
struct V_120 V_121 ;
F_47 ( & V_3 -> V_75 , V_103 ) ;
while ( V_122 == F_54 ( V_5 -> V_70 ,
V_5 -> V_108 [ V_5 -> V_109 ] . V_116 , & V_121 ) ) {
F_50 ( V_5 ,
V_113 ) ;
if ( F_4 ( V_3 , V_7 -> V_41 ) &
V_34 -> V_129 )
F_52 ( V_3 ,
V_5 -> V_109 ++ ) ;
else
V_5 -> V_109 ++ ;
V_5 -> V_109 %= V_123 ;
}
F_49 ( & V_3 -> V_75 , V_103 ) ;
F_57 ( & V_3 -> V_46 -> V_3 ) ;
}
static void V_115 ( void * V_102 )
{
struct V_1 * V_5 = (struct V_1 * ) V_102 ;
unsigned long V_103 ;
F_47 ( & V_5 -> V_3 . V_75 , V_103 ) ;
V_5 -> V_124 ++ ;
V_5 -> V_124 %= V_123 ;
F_59 ( & V_5 -> V_153 ) ;
F_49 ( & V_5 -> V_3 . V_75 , V_103 ) ;
}
static void F_56 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_33 * V_34 = & V_5 -> V_8 -> V_35 ;
int V_154 ;
V_5 -> V_93 = 0 ;
F_8 ( V_3 , V_7 -> V_125 ,
F_4 ( V_3 , V_7 -> V_125 ) &
~ V_57 ) ;
for ( V_154 = 0 ; V_154 < V_123 ; V_154 ++ )
F_52 ( V_3 , V_154 ) ;
V_5 -> V_109 = V_5 -> V_124 = 0 ;
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
V_5 -> V_93 = 0 ;
F_8 ( V_3 , V_7 -> V_69 , V_146 ) ;
F_8 ( V_3 , V_7 -> V_69 , 0 ) ;
F_8 ( V_3 , V_7 -> V_69 , V_58 ) ;
if ( V_5 -> V_70 )
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
unsigned long V_103 ;
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
F_47 ( & V_3 -> V_75 , V_103 ) ;
V_3 -> V_147 = V_34 -> V_148 ;
V_3 -> V_198 = 0 ;
if ( V_5 -> V_8 -> V_18 == V_19 ) {
if ( V_173 -> V_199 & V_200 )
V_3 -> V_147 |= V_34 -> V_201 |
V_34 -> V_202 ;
} else {
if ( V_173 -> V_199 & V_200 )
V_3 -> V_147 |= V_34 -> V_201 ;
}
if ( V_173 -> V_199 & ( V_203 | V_204 | V_205 ) )
V_3 -> V_147 |= V_34 -> V_206 ;
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
V_34 -> V_148 ;
}
if ( ( V_173 -> V_186 & V_215 ) == 0 )
V_3 -> V_198 |= V_91 ;
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
F_8 ( V_3 , V_7 -> V_69 , V_55 ) ;
F_8 ( V_3 , V_7 -> V_54 ,
( V_178 & ~ V_58 ) ) ;
if ( V_5 -> V_8 -> V_18 == V_19 ) {
V_175 |= F_79 ( V_3 , V_179 ) ;
F_8 ( V_3 , V_7 -> V_81 , V_175 ) ;
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
if ( V_5 -> V_70 )
F_8 ( V_3 , V_7 -> V_125 , V_238 ) ;
else
F_8 ( V_3 , V_7 -> V_125 , V_57 ) ;
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
F_49 ( & V_3 -> V_75 , V_103 ) ;
}
static void F_82 ( struct V_2 * V_3 , unsigned int V_46 ,
unsigned int V_244 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( ! V_46 )
F_83 ( V_5 -> V_245 ) ;
else
F_84 ( V_5 -> V_245 ) ;
}
static int F_85 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
unsigned int V_110 = V_3 -> line ;
int V_246 ;
F_86 ( V_3 -> V_73 , V_247 | V_248 ) ;
V_246 = F_87 ( V_3 -> V_73 ,
F_61 ,
0 ,
V_249 ,
V_5 ) ;
if ( V_246 != 0 ) {
F_21 ( V_3 -> V_60 , L_4 ,
V_110 , V_3 -> V_73 ) ;
goto V_250;
}
F_8 ( V_3 , V_7 -> V_56 ,
F_4 ( V_3 , V_7 -> V_56 ) |
V_57 ) ;
F_8 ( V_3 , V_7 -> V_125 ,
F_4 ( V_3 , V_7 -> V_125 ) |
V_57 ) ;
F_8 ( V_3 , V_7 -> V_251 , 0 ) ;
F_8 ( V_3 , V_7 -> V_252 , 0 ) ;
F_8 ( V_3 , V_7 -> V_241 , V_243 | V_242 ) ;
if ( V_5 -> V_8 -> V_18 == V_253 )
F_8 ( V_3 , V_7 -> V_254 ,
V_255 |
V_256 ) ;
F_8 ( V_3 , V_7 -> V_54 , V_146 ) ;
F_8 ( V_3 , V_7 -> V_54 , 0 ) ;
F_8 ( V_3 , V_7 -> V_69 , V_146 ) ;
F_8 ( V_3 , V_7 -> V_69 , 0 ) ;
F_8 ( V_3 , V_7 -> V_239 , F_80 ( V_3 ) ) ;
F_8 ( V_3 , V_7 -> V_240 , F_80 ( V_3 ) ) ;
if ( V_5 -> V_70 )
F_8 ( V_3 , V_7 -> V_257 ,
F_88 ( V_3 -> line , 0x4 ) |
F_89 ( V_3 -> line , 0xe ) |
F_90 ( V_3 -> line , 0x1b ) ) ;
if ( V_5 -> V_36 ) {
V_5 -> V_37 = V_104 ;
F_8 ( V_3 , V_7 -> V_258 ,
F_91 ( V_3 -> line , 0x1b ) |
F_92 ( V_3 -> line , 0xe ) |
F_93 ( V_3 -> line , 0x4 ) ) ;
}
V_5 -> V_16 = false ;
if ( V_5 -> V_8 -> V_18 == V_253 &&
V_5 -> V_15 ) {
F_86 ( F_31 ( V_5 -> V_23 ) ,
V_247 | V_248 ) ;
V_246 = F_87 ( F_31 ( V_5 -> V_23 ) ,
F_32 , V_259 |
V_260 , L_5 , V_5 ) ;
if ( V_246 != 0 ) {
F_21 ( V_3 -> V_60 , L_6 ) ;
goto V_261;
}
}
F_38 ( V_3 -> V_73 ) ;
return 0 ;
V_261:
F_94 ( V_3 -> V_73 , V_5 ) ;
V_250:
return V_246 ;
}
static void F_95 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
if ( ! V_5 -> V_40 )
F_8 ( V_3 , V_7 -> V_41 , 0 ) ;
else
F_8 ( V_3 , V_43 , ~ 0UL ) ;
F_94 ( V_3 -> V_73 , V_5 ) ;
if ( V_5 -> V_16 )
F_29 ( V_3 ) ;
if ( V_5 -> V_8 -> V_18 == V_253 &&
V_5 -> V_15 ) {
F_9 ( V_5 -> V_32 , 1 ) ;
F_94 ( F_31 ( V_5 -> V_23 ) , V_5 ) ;
}
if ( V_5 -> V_36 )
V_5 -> V_37 = V_104 ;
}
static const char * F_96 ( struct V_2 * V_3 )
{
return V_3 -> type == V_262 ? V_249 : NULL ;
}
static int F_97 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_263 * V_264 = & V_5 -> V_8 -> V_264 ;
void * V_246 ;
V_246 = F_98 ( V_3 -> V_265 ,
V_266 , V_264 -> V_267 ) ;
return V_246 ? 0 : - V_268 ;
}
static void F_99 ( struct V_2 * V_3 )
{
F_100 ( V_3 -> V_265 , V_266 ) ;
}
static void F_101 ( struct V_2 * V_3 , int V_103 )
{
if ( V_103 & V_269 ) {
V_3 -> type = V_262 ;
F_97 ( V_3 ) ;
}
}
static int T_3
F_102 ( struct V_270 * V_271 , char * V_272 )
{
unsigned int V_273 = 115200 ;
unsigned int V_274 = 8 ;
unsigned int V_275 = 'n' ;
unsigned int V_276 = 'n' ;
struct V_2 * V_3 = & V_277 [ V_271 -> V_110 ] . V_3 ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
if ( V_271 -> V_110 < 0 || V_271 -> V_110 >= V_278 )
return - V_279 ;
if ( ! V_3 -> V_265 )
return - V_88 ;
if ( V_5 -> V_8 -> V_18 == V_253 )
F_8 ( V_3 , V_7 -> V_254 , V_256 |
V_255 ) ;
if ( V_272 )
F_103 ( V_272 , & V_273 , & V_275 , & V_274 , & V_276 ) ;
V_3 -> V_280 = V_271 ;
V_5 -> V_70 = NULL ;
V_5 -> V_36 = NULL ;
return F_104 ( V_3 , V_271 , V_273 , V_275 , V_274 , V_276 ) ;
}
static void F_105 ( struct V_2 * V_3 , int V_84 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_9 * V_10 = & V_5 -> V_8 -> V_11 ;
while ( F_4 ( V_3 ,
V_7 -> V_12 ) & V_10 -> V_98 ( V_3 -> line ) )
F_106 () ;
F_8 ( V_3 , V_7 -> V_99 , V_84 ) ;
}
static void F_107 ( struct V_270 * V_271 , const char * V_281 ,
unsigned int V_96 )
{
struct V_2 * V_3 = & V_277 [ V_271 -> V_110 ] . V_3 ;
F_108 ( V_3 , V_281 , V_96 , F_105 ) ;
}
static int T_3 F_109 ( void )
{
F_110 ( & V_282 ) ;
return 0 ;
}
static int F_111 ( struct V_283 * V_284 )
{
struct V_1 * V_5 ;
struct V_2 * V_3 ;
struct V_285 * V_286 ;
int V_246 ;
int V_154 , V_287 ;
struct V_288 V_289 = {
. V_290 = 2 ,
} ;
struct V_288 V_291 = {
. V_292 = 2 ,
} ;
const struct V_293 * V_294 ;
V_294 = F_112 ( V_295 , V_284 -> V_60 . V_296 ) ;
if ( F_113 ( V_284 -> V_60 . V_296 , L_7 , & V_284 -> V_297 ) ) {
F_21 ( & V_284 -> V_60 ,
L_8 ) ;
V_246 = - V_298 ;
goto V_299;
}
if ( F_114 ( V_284 -> V_60 . V_296 , L_9 ) )
V_284 -> V_297 += ( (struct V_300 * )
V_294 -> V_301 ) -> V_264 . V_302 ;
V_5 = & V_277 [ V_284 -> V_297 ] ;
V_3 = & V_5 -> V_3 ;
V_3 -> V_60 = & V_284 -> V_60 ;
V_3 -> V_303 = V_5 ;
V_5 -> V_8 = (struct V_300 * ) V_294 -> V_301 ;
V_5 -> V_15 = F_115 ( V_284 -> V_60 . V_296 ,
L_10 ) ;
if ( F_114 ( V_284 -> V_60 . V_296 , L_11 ) )
V_5 -> V_8 -> V_18 = V_19 ;
if ( F_114 ( V_284 -> V_60 . V_296 , L_9 ) ) {
V_5 -> V_8 -> V_18 = V_253 ;
if ( ! V_5 -> V_15 )
goto V_304;
if ( F_116 ( V_284 -> V_60 . V_296 , L_12 , NULL ) )
V_5 -> V_23 = F_117 (
V_284 -> V_60 . V_296 , L_12 , 0 ) ;
else
V_5 -> V_23 = - 1 ;
if ( F_116 ( V_284 -> V_60 . V_296 , L_13 , NULL ) )
V_5 -> V_32 = F_117 (
V_284 -> V_60 . V_296 , L_13 , 0 ) ;
else
V_5 -> V_32 = - 1 ;
if ( ( ! F_34 ( V_5 -> V_23 ) ||
! F_34 ( V_5 -> V_32 ) ) ) {
V_246 = - V_279 ;
F_21 ( & V_284 -> V_60 ,
L_14 ) ;
goto V_299;
}
V_246 = F_118 ( & V_284 -> V_60 , V_5 -> V_23 ,
L_15 ) ;
if ( V_246 ) {
F_21 ( & V_284 -> V_60 , L_16 ) ;
goto V_299;
}
F_119 ( V_5 -> V_23 ) ;
V_246 = F_118 ( & V_284 -> V_60 , V_5 -> V_32 ,
L_17 ) ;
if ( V_246 ) {
F_21 ( & V_284 -> V_60 , L_18 ) ;
goto V_299;
}
F_120 ( V_5 -> V_32 , 1 ) ;
}
V_304:
if ( F_114 ( V_284 -> V_60 . V_296 , L_19 ) )
V_5 -> V_40 = true ;
if ( F_113 ( V_284 -> V_60 . V_296 ,
L_20 ,
& V_3 -> V_305 ) ) {
F_21 ( & V_284 -> V_60 ,
L_21 ) ;
V_246 = - V_298 ;
goto V_299;
}
V_286 = F_121 ( V_284 , V_306 , 0 ) ;
if ( V_286 == NULL ) {
F_21 ( & V_284 -> V_60 , L_22 ) ;
V_246 = - V_298 ;
goto V_299;
}
F_122 ( & V_5 -> V_153 ,
F_67 , ( unsigned long ) V_5 ) ;
F_122 ( & V_5 -> V_130 ,
F_53 , ( unsigned long ) V_5 ) ;
V_3 -> V_265 = V_286 -> V_307 ;
V_3 -> V_308 = F_123 ( & V_284 -> V_60 , V_286 -> V_307 , F_124 ( V_286 ) ) ;
if ( ! V_3 -> V_308 ) {
F_21 ( & V_284 -> V_60 , L_23 ) ;
V_246 = - V_309 ;
goto V_299;
}
V_286 = F_121 ( V_284 , V_310 , 0 ) ;
if ( V_286 == NULL ) {
F_21 ( & V_284 -> V_60 , L_22 ) ;
V_246 = - V_298 ;
goto V_299;
}
V_3 -> V_73 = V_286 -> V_307 ;
V_5 -> V_245 = F_125 ( & V_284 -> V_60 , NULL ) ;
if ( F_126 ( V_5 -> V_245 ) ) {
V_246 = F_127 ( V_5 -> V_245 ) ;
goto V_299;
}
V_3 -> V_185 = F_128 ( V_5 -> V_245 ) ;
V_3 -> V_311 = & V_312 ;
F_129 ( & V_3 -> V_75 ) ;
F_130 ( V_284 , V_5 ) ;
V_246 = F_131 ( & V_313 , V_3 ) ;
if ( V_246 != 0 ) {
F_21 ( & V_284 -> V_60 , L_24 , V_284 -> V_297 ) ;
goto V_314;
}
V_5 -> V_70 = F_132 ( V_3 -> V_60 , L_25 ) ;
for ( V_154 = 0 ; V_5 -> V_70 && V_154 < V_123 ; V_154 ++ ) {
V_5 -> V_108 [ V_154 ] . V_45 . V_53 =
F_133 ( V_3 -> V_60 , V_113 ,
& V_5 -> V_108 [ V_154 ] . V_112 , V_315 ) ;
if ( ! V_5 -> V_108 [ V_154 ] . V_45 . V_53 ) {
F_21 ( V_3 -> V_60 , L_26 ) ;
V_246 = - V_309 ;
goto V_316;
}
V_5 -> V_108 [ V_154 ] . V_45 . V_50 =
V_5 -> V_108 [ V_154 ] . V_45 . V_51 = 0 ;
}
if ( V_5 -> V_70 )
F_134 ( V_5 -> V_70 , & V_289 ) ;
V_5 -> V_36 = F_132 ( V_3 -> V_60 , L_27 ) ;
if ( V_5 -> V_36 )
F_134 ( V_5 -> V_36 , & V_291 ) ;
return 0 ;
V_316:
for ( V_287 = 0 ; V_287 < V_154 ; V_287 ++ )
F_135 ( V_3 -> V_60 , V_113 ,
V_5 -> V_108 [ V_287 ] . V_45 . V_53 ,
V_5 -> V_108 [ V_287 ] . V_112 ) ;
F_136 ( V_5 -> V_70 ) ;
V_314:
F_137 ( V_5 -> V_245 ) ;
V_299:
return V_246 ;
}
static int F_138 ( struct V_283 * V_284 )
{
struct V_1 * V_5 = F_139 ( V_284 ) ;
struct V_2 * V_3 = & V_5 -> V_3 ;
F_137 ( V_5 -> V_245 ) ;
F_140 ( & V_313 , V_3 ) ;
if ( V_5 -> V_70 ) {
int V_154 ;
F_27 ( V_5 -> V_70 ) ;
F_136 ( V_5 -> V_70 ) ;
for ( V_154 = 0 ; V_154 < V_123 ; V_154 ++ )
F_135 ( V_3 -> V_60 , V_113 ,
V_5 -> V_108 [ V_154 ] . V_45 . V_53 ,
V_5 -> V_108 [ V_154 ] . V_112 ) ;
}
if ( V_5 -> V_36 ) {
F_27 ( V_5 -> V_36 ) ;
F_136 ( V_5 -> V_36 ) ;
}
return 0 ;
}
static int
F_141 ( struct V_317 * V_284 )
{
struct V_1 * V_5 = F_142 ( V_284 ) ;
struct V_2 * V_3 = & V_5 -> V_3 ;
F_143 ( & V_313 , V_3 ) ;
return 0 ;
}
static int F_144 ( struct V_317 * V_284 )
{
struct V_1 * V_5 = F_142 ( V_284 ) ;
struct V_2 * V_3 = & V_5 -> V_3 ;
F_145 ( & V_313 , V_3 ) ;
return 0 ;
}
static int T_3 F_146 ( void )
{
int V_246 = 0 ;
V_246 = F_147 ( & V_313 ) ;
if ( V_246 )
goto V_318;
V_246 = F_148 ( & V_319 ) ;
if ( V_246 )
F_149 ( & V_313 ) ;
V_318:
return V_246 ;
}
static void T_4 F_150 ( void )
{
F_151 ( & V_319 ) ;
F_149 ( & V_313 ) ;
}
