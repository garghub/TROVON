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
F_50 ( & V_5 -> V_123 , V_105 ) ;
while ( V_5 -> V_112 != V_5 -> V_124 ) {
F_52 ( V_5 ,
V_116 ) ;
F_54 ( V_3 , V_5 -> V_112 ++ ) ;
V_5 -> V_112 %= V_125 ;
}
V_98 = F_56 ( V_5 -> V_111 [ V_5 -> V_124 ] . V_46 . V_51 ,
V_5 -> V_111 [ V_5 -> V_124 ] . V_46 . V_52 ,
V_116 ) ;
if ( V_98 > 0 )
F_52 ( V_5 , V_98 ) ;
F_8 ( V_3 , V_7 -> V_126 ,
F_4 ( V_3 , V_7 -> V_126 ) |
V_58 ) ;
F_39 ( V_3 , 4 - V_5 -> V_94 ) ;
F_51 ( & V_5 -> V_123 , V_105 ) ;
if ( V_5 -> V_94 == 4 ) {
F_50 ( & V_5 -> V_123 , V_105 ) ;
V_5 -> V_94 = 0 ;
F_8 ( V_3 , V_7 -> V_127 ,
V_121 -> V_128 ) ;
if ( ! V_5 -> V_41 )
F_8 ( V_3 , V_7 -> V_42 ,
F_4 ( V_3 , V_7 -> V_42 ) &
~ ( V_34 -> V_72 ) ) ;
else
F_8 ( V_3 , V_44 ,
V_34 -> V_72 ) ;
F_51 ( & V_5 -> V_123 , V_105 ) ;
F_57 ( V_3 ) ;
} else {
F_50 ( & V_5 -> V_123 , V_105 ) ;
F_8 ( V_3 , V_7 -> V_127 ,
V_121 -> V_128 ) ;
if ( ! V_5 -> V_41 )
F_8 ( V_3 , V_7 -> V_42 ,
F_4 ( V_3 , V_7 -> V_42 ) |
( V_34 -> V_72 ) ) ;
else
F_8 ( V_3 , V_7 -> V_42 ,
V_34 -> V_72 ) ;
F_51 ( & V_5 -> V_123 , V_105 ) ;
}
}
static void F_58 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = & V_5 -> V_3 ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_33 * V_34 = & V_5 -> V_8 -> V_35 ;
struct V_129 V_130 ;
F_46 ( & V_5 -> V_123 ) ;
F_59 ( V_5 -> V_73 ,
V_5 -> V_111 [ V_5 -> V_124 ] . V_119 , & V_130 ) ;
F_28 ( V_5 -> V_73 ) ;
V_5 -> V_111 [ V_5 -> V_124 ] . V_46 . V_51 =
V_116 - V_130 . V_131 ;
if ( ! V_5 -> V_41 )
F_8 ( V_3 , V_7 -> V_42 ,
F_4 ( V_3 , V_7 -> V_42 ) &
~ ( V_34 -> V_132 ) ) ;
else
F_8 ( V_3 , V_44 ,
V_34 -> V_132 ) ;
F_44 ( & V_5 -> V_123 ) ;
F_60 ( & V_5 -> V_133 ) ;
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
F_8 ( V_3 , V_7 -> V_127 ,
V_121 -> V_134 ) ;
F_57 ( V_3 ) ;
}
}
static T_1 F_62 ( int V_75 , void * V_76 )
{
unsigned long V_135 ;
unsigned long V_136 ;
unsigned long V_137 = V_93 ;
struct V_1 * V_5 = (struct V_1 * ) V_76 ;
struct V_2 * V_3 = & V_5 -> V_3 ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_9 * V_10 = & V_5 -> V_8 -> V_11 ;
struct V_120 * V_121 = & V_5 -> V_8 -> V_122 ;
struct V_33 * V_34 = & V_5 -> V_8 -> V_35 ;
struct V_138 * V_47 = V_3 -> V_47 ;
struct V_45 * V_46 = & V_3 -> V_47 -> V_46 ;
F_46 ( & V_3 -> V_97 ) ;
V_135 = F_4 ( V_3 , V_7 -> V_127 ) ;
F_8 ( V_3 , V_7 -> V_127 , V_135 ) ;
V_135 &= F_4 ( V_3 , V_7 -> V_42 ) ;
if ( F_41 ( V_135 & ( F_63 ( V_3 , V_121 ) ) ) ) {
if ( V_135 & V_121 -> V_139 ) {
V_3 -> V_95 . V_140 ++ ;
if ( F_64 ( V_3 ) )
goto V_141;
}
if ( V_135 & V_121 -> V_142 )
V_3 -> V_95 . V_143 ++ ;
if ( V_135 & V_121 -> V_144 ) {
V_3 -> V_95 . V_145 ++ ;
V_137 = V_146 ;
}
if ( V_135 & V_121 -> V_147 )
V_137 = V_148 ;
F_8 ( V_3 , V_7 -> V_70 , V_149 ) ;
F_8 ( V_3 , V_7 -> V_70 , 0 ) ;
F_8 ( V_3 , V_7 -> V_70 , V_59 ) ;
V_135 &= V_3 -> V_150 ;
F_43 ( V_3 , V_135 ,
V_34 -> V_151 , 0 , V_137 ) ;
F_45 ( & V_47 -> V_3 ) ;
}
V_141:
if ( ( V_5 -> V_8 -> V_18 == V_19 ) &&
( V_135 & F_65 ( V_121 ) ) &&
! V_5 -> V_37 ) {
V_136 = F_4 ( V_3 , V_7 -> V_20 ) &
V_21 ;
if ( V_136 != 0 )
V_136 = 0 ;
else
V_136 = 1 ;
F_35 ( V_3 , V_136 ) ;
F_66 ( & V_47 -> V_3 . V_152 ) ;
}
if ( F_11 ( V_5 -> V_71 ) ) {
if ( V_135 & V_121 -> V_134 )
F_58 ( V_5 ) ;
if ( V_135 & V_121 -> V_128 )
F_61 ( V_5 ) ;
} else {
if ( V_135 & F_67 ( V_121 ) )
F_39 ( V_3 ,
V_153 ) ;
}
if ( V_135 & V_121 -> V_154 ) {
if ( F_11 ( V_5 -> V_36 ) )
F_13 ( V_5 ) ;
else {
if ( F_15 ( V_46 ) || F_16 ( V_3 ) ) {
F_44 ( & V_3 -> V_97 ) ;
return V_77 ;
} else {
F_19 ( V_5 ,
V_155 ) ;
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
unsigned long V_105 ;
F_50 ( & V_5 -> V_123 , V_105 ) ;
while ( V_5 -> V_112 != V_5 -> V_124 ) {
F_52 ( V_5 ,
V_116 ) ;
F_54 ( V_3 , V_5 -> V_112 ++ ) ;
V_5 -> V_112 %= V_125 ;
}
F_51 ( & V_5 -> V_123 , V_105 ) ;
}
static void V_118 ( void * V_104 )
{
struct V_1 * V_5 = (struct V_1 * ) V_104 ;
F_46 ( & V_5 -> V_123 ) ;
V_5 -> V_124 ++ ;
V_5 -> V_124 %= V_125 ;
F_44 ( & V_5 -> V_123 ) ;
F_60 ( & V_5 -> V_156 ) ;
}
static void F_57 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_33 * V_34 = & V_5 -> V_8 -> V_35 ;
unsigned long V_105 ;
int V_157 ;
F_50 ( & V_5 -> V_123 , V_105 ) ;
V_5 -> V_94 = 0 ;
F_8 ( V_3 , V_7 -> V_126 ,
F_4 ( V_3 , V_7 -> V_126 ) &
~ V_58 ) ;
F_51 ( & V_5 -> V_123 , V_105 ) ;
for ( V_157 = 0 ; V_157 < V_125 ; V_157 ++ )
F_54 ( V_3 , V_157 ) ;
V_5 -> V_112 = V_5 -> V_124 = 0 ;
F_50 ( & V_5 -> V_123 , V_105 ) ;
if ( ! V_5 -> V_41 )
F_8 ( V_3 , V_7 -> V_42 ,
F_4 ( V_3 , V_7 -> V_42 ) |
F_27 ( V_3 , V_34 ) ) ;
else
F_8 ( V_3 , V_7 -> V_42 ,
F_27 ( V_3 , V_34 ) ) ;
F_51 ( & V_5 -> V_123 , V_105 ) ;
}
static void F_69 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_33 * V_34 = & V_5 -> V_8 -> V_35 ;
V_5 -> V_94 = 0 ;
F_8 ( V_3 , V_7 -> V_70 , V_149 ) ;
F_8 ( V_3 , V_7 -> V_70 , 0 ) ;
F_8 ( V_3 , V_7 -> V_70 , V_59 ) ;
if ( F_11 ( V_5 -> V_71 ) )
F_57 ( V_3 ) ;
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
F_70 ( unsigned long V_158 ,
unsigned long V_159 , unsigned long * V_160 )
{
unsigned long V_161 = ~ 0UL ;
unsigned short V_162 ;
unsigned long V_163 = 0 ;
unsigned long V_164 ;
for ( V_162 = V_165 ;
V_162 <= V_166 ; V_162 ++ ) {
V_164 = V_159 -
( V_159 + ( V_158 * V_162 ) / 2 )
/ ( V_158 * V_162 ) * V_158 * V_162 ;
V_164 = ( V_164 > 0 ) ? V_164 : - V_164 ;
if ( V_164 < V_161 ) {
V_163 = ( 2 * V_159 /
( V_158 * V_162 ) + 1 ) / 2 - 1 ;
if ( V_163 > V_167 )
continue;
V_161 = V_164 ;
* V_160 = V_162 ;
if ( ! V_164 )
break;
}
}
return V_163 ;
}
static unsigned int
F_71 ( unsigned long V_168 ,
unsigned long V_159 , unsigned long * V_169 )
{
unsigned long V_161 = ~ 0UL ;
unsigned short V_162 ;
unsigned int V_170 = 0 ;
unsigned long V_163 ;
unsigned long V_171 ;
int V_164 ;
for ( V_162 = V_165 ;
V_162 <= V_166 ; V_162 ++ ) {
V_163 = ( V_159 / ( V_168 * ( V_162 + 1 ) ) ) - 1 ;
if ( V_163 > V_167 )
continue;
V_171 = V_159 / ( ( V_163 + 1 ) * ( V_162 + 1 ) ) ;
V_164 = V_171 - V_168 ;
V_164 = ( V_164 > 0 ) ? V_164 : - V_164 ;
if ( V_164 < V_161 ) {
V_170 = V_170 & ( ~ V_172 ) ;
V_170 = V_170 | V_163 ;
V_170 = V_170 & ( ~ V_173 ) ;
V_170 = V_170 | ( V_162 << V_174 ) ;
V_161 = V_164 ;
* V_169 = V_171 ;
}
}
return V_170 ;
}
static void F_72 ( struct V_2 * V_3 ,
struct V_175 * V_176 ,
struct V_175 * V_177 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_33 * V_34 = & V_5 -> V_8 -> V_35 ;
unsigned long V_178 = 0 ;
unsigned long V_168 ;
unsigned long V_169 ;
unsigned long V_105 ;
unsigned long V_179 ;
unsigned int V_180 = 0 ;
unsigned long V_181 , V_159 ;
unsigned long V_182 ;
int V_183 ;
T_2 V_184 , V_185 , V_186 ;
unsigned long V_187 = 0xf ;
V_159 = V_3 -> V_188 ;
switch ( V_176 -> V_189 & V_190 ) {
default:
case V_191 :
V_184 = 8 ;
V_178 |= V_192 ;
break;
case V_193 :
V_184 = 7 ;
V_178 |= V_194 ;
break;
case V_195 :
V_184 = 6 ;
V_178 |= V_196 ;
break;
case V_197 :
V_184 = 5 ;
V_178 |= V_198 ;
break;
}
if ( V_176 -> V_189 & V_199 ) {
V_178 |= V_200 ;
V_185 = 2 ;
} else
V_185 = 1 ;
F_50 ( & V_3 -> V_97 , V_105 ) ;
V_3 -> V_150 = V_34 -> V_151 ;
V_3 -> V_201 = 0 ;
if ( V_5 -> V_8 -> V_18 == V_19 ) {
if ( V_176 -> V_202 & V_203 )
V_3 -> V_150 |= V_34 -> V_204 |
V_34 -> V_205 ;
} else {
if ( V_176 -> V_202 & V_203 )
V_3 -> V_150 |= V_34 -> V_204 ;
}
if ( V_176 -> V_202 & ( V_206 | V_207 ) )
V_3 -> V_150 |= V_34 -> V_208 ;
if ( V_5 -> V_8 -> V_18 == V_19 ) {
if ( V_176 -> V_202 & V_209 )
V_3 -> V_201 |=
V_34 -> V_204 |
V_34 -> V_205 ;
if ( V_176 -> V_189 & V_210 ) {
if ( V_176 -> V_189 & V_211 ) {
if ( V_176 -> V_189 & V_212 )
V_178 |= V_213 ;
else
V_178 |= V_214 ;
} else if ( V_176 -> V_189 & V_212 ) {
V_178 |= V_215 ;
} else {
V_178 |= V_216 ;
}
}
} else {
if ( V_176 -> V_202 & V_209 )
V_3 -> V_201 |=
V_34 -> V_204 ;
if ( V_176 -> V_189 & V_210 )
F_73 ( V_3 -> V_61 ,
L_3 ) ;
}
if ( V_176 -> V_202 & V_217 ) {
V_3 -> V_201 |=
V_34 -> V_208 ;
if ( V_176 -> V_202 & V_209 )
V_3 -> V_201 |=
V_34 -> V_151 ;
}
if ( ( V_176 -> V_189 & V_218 ) == 0 )
V_3 -> V_201 |= V_92 ;
if ( F_74 ( V_3 , V_176 -> V_189 ) ) {
if ( ! V_5 -> V_16 )
F_36 ( V_3 ) ;
} else {
if ( V_5 -> V_16 )
F_30 ( V_3 ) ;
}
V_168 = F_75 ( V_3 , V_176 , V_177 , 0 , 4000000 ) ;
if ( V_159 == 150000000 ) {
for ( V_179 = 0 ; V_179 < V_219 ; V_179 ++ )
if ( V_168 == V_220 [ V_179 ] . V_168 )
V_180 = V_220 [ V_179 ] . V_221 ;
}
V_169 = V_168 ;
if ( V_5 -> V_8 -> V_18 == V_19 ) {
if ( F_41 ( V_180 == 0 ) )
V_180 = F_71 ( V_168 ,
V_159 , & V_169 ) ;
F_8 ( V_3 , V_7 -> V_222 , V_180 ) ;
} else {
V_180 = F_70 ( V_168 ,
V_159 , & V_187 ) ;
V_187 -- ;
V_169 = ( ( V_159 / ( V_180 + 1 ) - 1 ) /
( V_187 + 1 ) ) ;
V_186 = ( ( 1 << V_223 ) |
( 1 << V_224 ) ) ;
V_186 |= ( ( V_180 & V_225 )
<< V_226 ) ;
F_8 ( V_3 , V_7 -> V_227 , V_186 ) ;
}
if ( F_76 ( V_176 ) )
F_77 ( V_176 , V_169 , V_169 ) ;
V_182 = F_78 ( V_169 , 20000 ) ;
V_182 = F_79 ( V_182 ) ;
V_181 = F_4 ( V_3 , V_7 -> V_55 ) ;
F_8 ( V_3 , V_7 -> V_70 , V_56 ) ;
F_8 ( V_3 , V_7 -> V_55 ,
( V_181 & ~ V_59 ) ) ;
if ( V_5 -> V_8 -> V_18 == V_19 ) {
V_178 |= F_80 ( V_3 , V_182 ) ;
F_8 ( V_3 , V_7 -> V_82 , V_178 ) ;
} else {
V_186 = ( V_184 - 1 ) << V_228 ;
V_186 |= ( V_184 + 1 + V_185 - 1 ) <<
V_229 ;
V_186 |= ( ( V_184 - 1 ) <<
V_230 ) ;
V_186 |= ( ( ( V_180 & 0xc00 ) >> 10 ) <<
V_231 ) ;
F_8 ( V_3 , V_7 -> V_232 , V_186 ) ;
V_186 = ( V_184 - 1 ) << V_233 ;
V_186 |= ( V_184 + 1 + V_185 - 1 ) <<
V_234 ;
V_186 |= ( V_184 - 1 ) <<
V_235 ;
V_186 |= ( ( ( V_180 & 0xf000 ) >> 12 ) <<
V_236 ) ;
F_8 ( V_3 , V_7 -> V_237 , V_186 ) ;
F_8 ( V_3 , V_7 -> V_238 ,
( F_80 ( V_3 , V_182 ) ) |
( V_187 & V_239 ) <<
V_240 ) ;
}
if ( F_11 ( V_5 -> V_36 ) )
F_8 ( V_3 , V_7 -> V_57 , V_241 ) ;
else
F_8 ( V_3 , V_7 -> V_57 , V_58 ) ;
if ( F_11 ( V_5 -> V_71 ) )
F_8 ( V_3 , V_7 -> V_126 , V_241 ) ;
else
F_8 ( V_3 , V_7 -> V_126 , V_58 ) ;
if ( V_169 < 1000000 )
V_183 = 1 ;
else
V_183 = 2 ;
F_8 ( V_3 , V_7 -> V_242 ,
F_81 ( V_3 ) / V_183 ) ;
F_8 ( V_3 , V_7 -> V_243 ,
F_81 ( V_3 ) / V_183 ) ;
V_181 |= V_59 ;
F_8 ( V_3 , V_7 -> V_55 , V_181 ) ;
F_82 ( V_3 , V_176 -> V_189 , V_169 ) ;
F_69 ( V_3 ) ;
F_8 ( V_3 , V_7 -> V_244 , V_245 | V_246 ) ;
F_51 ( & V_3 -> V_97 , V_105 ) ;
}
static unsigned int F_83 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_3 V_247 ;
struct V_248 V_249 = {
. V_250 = 2 ,
} ;
F_84 ( V_247 ) ;
F_85 ( V_251 , V_247 ) ;
V_5 -> V_39 = F_86 ( V_247 ,
( V_252 ) V_253 ,
( void * ) V_5 -> V_36 ) ;
if ( ! V_5 -> V_39 ) {
F_22 ( V_3 -> V_61 , L_4 ,
V_5 -> V_36 ) ;
return - V_254 ;
}
F_87 ( V_5 -> V_39 , & V_249 ) ;
return 0 ;
}
static unsigned int F_88 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_3 V_247 ;
int V_255 ;
int V_157 , V_256 ;
struct V_248 V_257 = {
. V_258 = 2 ,
} ;
F_84 ( V_247 ) ;
F_85 ( V_251 , V_247 ) ;
V_5 -> V_73 = F_86 ( V_247 ,
( V_252 ) V_253 ,
( void * ) V_5 -> V_71 ) ;
if ( ! V_5 -> V_73 ) {
F_22 ( V_3 -> V_61 , L_4 ,
V_5 -> V_71 ) ;
V_255 = - V_254 ;
goto V_259;
}
for ( V_157 = 0 ; V_157 < V_125 ; V_157 ++ ) {
V_5 -> V_111 [ V_157 ] . V_46 . V_54 =
F_89 ( V_3 -> V_61 , V_116 ,
& V_5 -> V_111 [ V_157 ] . V_115 , V_260 ) ;
if ( ! V_5 -> V_111 [ V_157 ] . V_46 . V_54 ) {
F_22 ( V_3 -> V_61 , L_5 ) ;
V_255 = - V_261 ;
goto V_262;
}
V_5 -> V_111 [ V_157 ] . V_46 . V_51 =
V_5 -> V_111 [ V_157 ] . V_46 . V_52 = 0 ;
}
F_87 ( V_5 -> V_73 , & V_257 ) ;
return 0 ;
V_262:
for ( V_256 = 0 ; V_256 < V_157 ; V_256 ++ )
F_90 ( V_3 -> V_61 , V_116 ,
V_5 -> V_111 [ V_256 ] . V_46 . V_54 ,
V_5 -> V_111 [ V_256 ] . V_115 ) ;
F_91 ( V_5 -> V_73 ) ;
V_259:
return V_255 ;
}
static void F_92 ( struct V_1 * V_5 )
{
F_28 ( V_5 -> V_39 ) ;
F_91 ( V_5 -> V_39 ) ;
}
static void F_93 ( struct V_1 * V_5 )
{
int V_157 ;
struct V_2 * V_3 = & V_5 -> V_3 ;
F_28 ( V_5 -> V_73 ) ;
F_91 ( V_5 -> V_73 ) ;
for ( V_157 = 0 ; V_157 < V_125 ; V_157 ++ )
F_90 ( V_3 -> V_61 , V_116 ,
V_5 -> V_111 [ V_157 ] . V_46 . V_54 ,
V_5 -> V_111 [ V_157 ] . V_115 ) ;
}
static int F_94 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
unsigned int V_113 = V_3 -> line ;
int V_255 ;
F_95 ( V_3 -> V_75 , V_263 | V_264 ) ;
V_255 = F_96 ( V_3 -> V_75 ,
F_62 ,
0 ,
V_265 ,
V_5 ) ;
if ( V_255 != 0 ) {
F_22 ( V_3 -> V_61 , L_6 ,
V_113 , V_3 -> V_75 ) ;
goto V_266;
}
F_8 ( V_3 , V_7 -> V_57 ,
F_4 ( V_3 , V_7 -> V_57 ) |
V_58 ) ;
F_8 ( V_3 , V_7 -> V_126 ,
F_4 ( V_3 , V_7 -> V_126 ) |
V_58 ) ;
F_8 ( V_3 , V_7 -> V_267 , 0 ) ;
F_8 ( V_3 , V_7 -> V_268 , 0 ) ;
F_8 ( V_3 , V_7 -> V_244 , V_246 | V_245 ) ;
if ( V_5 -> V_8 -> V_18 == V_269 )
F_8 ( V_3 , V_7 -> V_270 ,
V_271 |
V_272 ) ;
F_8 ( V_3 , V_7 -> V_55 , V_149 ) ;
F_8 ( V_3 , V_7 -> V_55 , 0 ) ;
F_8 ( V_3 , V_7 -> V_70 , V_149 ) ;
F_8 ( V_3 , V_7 -> V_70 , 0 ) ;
F_8 ( V_3 , V_7 -> V_242 , F_81 ( V_3 ) ) ;
F_8 ( V_3 , V_7 -> V_243 , F_81 ( V_3 ) ) ;
if ( F_11 ( V_5 -> V_71 ) ) {
V_255 = F_88 ( V_3 ) ;
if ( V_255 )
goto V_273;
F_8 ( V_3 , V_7 -> V_274 ,
F_97 ( V_3 -> line , 0x4 ) |
F_98 ( V_3 -> line , 0xe ) |
F_99 ( V_3 -> line , 0x1b ) ) ;
}
if ( F_11 ( V_5 -> V_36 ) ) {
F_83 ( V_3 ) ;
V_5 -> V_37 = V_107 ;
F_8 ( V_3 , V_7 -> V_275 ,
F_100 ( V_3 -> line , 0x1b ) |
F_101 ( V_3 -> line , 0xe ) |
F_102 ( V_3 -> line , 0x4 ) ) ;
}
V_5 -> V_16 = false ;
if ( V_5 -> V_8 -> V_18 == V_269 &&
V_5 -> V_15 ) {
F_95 ( F_32 ( V_5 -> V_23 ) ,
V_263 | V_264 ) ;
V_255 = F_96 ( F_32 ( V_5 -> V_23 ) ,
F_33 , V_276 |
V_277 , L_7 , V_5 ) ;
if ( V_255 != 0 ) {
F_22 ( V_3 -> V_61 , L_8 ) ;
goto V_273;
}
}
F_37 ( V_3 -> V_75 ) ;
return 0 ;
V_273:
F_103 ( V_3 -> V_75 , V_5 ) ;
V_266:
return V_255 ;
}
static void F_104 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
if ( ! V_5 -> V_41 )
F_8 ( V_3 , V_7 -> V_42 , 0 ) ;
else
F_8 ( V_3 , V_44 , ~ 0UL ) ;
F_103 ( V_3 -> V_75 , V_5 ) ;
if ( V_5 -> V_16 )
F_30 ( V_3 ) ;
if ( V_5 -> V_8 -> V_18 == V_269 &&
V_5 -> V_15 ) {
F_9 ( V_5 -> V_32 , 1 ) ;
F_103 ( F_32 ( V_5 -> V_23 ) , V_5 ) ;
}
if ( F_11 ( V_5 -> V_71 ) )
F_93 ( V_5 ) ;
if ( F_11 ( V_5 -> V_36 ) ) {
F_92 ( V_5 ) ;
V_5 -> V_37 = V_107 ;
}
}
static const char * F_105 ( struct V_2 * V_3 )
{
return V_3 -> type == V_278 ? V_265 : NULL ;
}
static int F_106 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_279 * V_280 = & V_5 -> V_8 -> V_280 ;
void * V_255 ;
V_255 = F_107 ( V_3 -> V_281 ,
V_282 , V_280 -> V_283 ) ;
return V_255 ? 0 : - V_284 ;
}
static void F_108 ( struct V_2 * V_3 )
{
F_109 ( V_3 -> V_281 , V_282 ) ;
}
static void F_110 ( struct V_2 * V_3 , int V_105 )
{
if ( V_105 & V_285 ) {
V_3 -> type = V_278 ;
F_106 ( V_3 ) ;
}
}
static int T_4
F_111 ( struct V_286 * V_287 , char * V_288 )
{
unsigned int V_289 = 115200 ;
unsigned int V_290 = 8 ;
unsigned int V_291 = 'n' ;
unsigned int V_292 = 'n' ;
struct V_2 * V_3 = & V_293 [ V_287 -> V_113 ] . V_3 ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
if ( V_287 -> V_113 < 0 || V_287 -> V_113 >= V_294 )
return - V_295 ;
if ( ! V_3 -> V_281 )
return - V_89 ;
if ( V_5 -> V_8 -> V_18 == V_269 )
F_8 ( V_3 , V_7 -> V_270 , V_272 |
V_271 ) ;
if ( V_288 )
F_112 ( V_288 , & V_289 , & V_291 , & V_290 , & V_292 ) ;
V_3 -> V_296 = V_287 ;
V_5 -> V_71 = V_297 ;
V_5 -> V_36 = V_297 ;
return F_113 ( V_3 , V_287 , V_289 , V_291 , V_290 , V_292 ) ;
}
static void F_114 ( struct V_2 * V_3 , int V_85 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_9 * V_10 = & V_5 -> V_8 -> V_11 ;
while ( F_4 ( V_3 ,
V_7 -> V_12 ) & V_10 -> V_100 ( V_3 -> line ) )
F_115 () ;
F_116 ( V_3 , V_7 -> V_101 , V_85 ) ;
}
static void F_117 ( struct V_286 * V_287 , const char * V_298 ,
unsigned int V_98 )
{
struct V_2 * V_3 = & V_293 [ V_287 -> V_113 ] . V_3 ;
F_118 ( V_3 , V_298 , V_98 , F_114 ) ;
}
static int T_4 F_119 ( void )
{
F_120 ( & V_299 ) ;
return 0 ;
}
static int F_121 ( struct V_300 * V_301 )
{
struct V_1 * V_5 ;
struct V_2 * V_3 ;
struct V_302 * V_303 ;
int V_255 ;
const struct V_304 * V_305 ;
V_305 = F_122 ( V_306 , V_301 -> V_61 . V_307 ) ;
if ( F_123 ( V_301 -> V_61 . V_307 , L_9 , & V_301 -> V_308 ) ) {
F_22 ( & V_301 -> V_61 ,
L_10 ) ;
V_255 = - V_309 ;
goto V_310;
}
if ( F_124 ( V_301 -> V_61 . V_307 , L_11 ) )
V_301 -> V_308 += ( (struct V_311 * )
V_305 -> V_312 ) -> V_280 . V_313 ;
V_5 = & V_293 [ V_301 -> V_308 ] ;
V_3 = & V_5 -> V_3 ;
V_3 -> V_61 = & V_301 -> V_61 ;
V_3 -> V_314 = V_5 ;
V_5 -> V_8 = (struct V_311 * ) V_305 -> V_312 ;
V_5 -> V_15 = F_125 ( V_301 -> V_61 . V_307 ,
L_12 ) ;
if ( F_124 ( V_301 -> V_61 . V_307 , L_13 ) ) {
V_5 -> V_8 -> V_18 = V_19 ;
if ( F_123 ( V_301 -> V_61 . V_307 ,
L_14 ,
& V_5 -> V_71 ) )
V_5 -> V_71 = V_297 ;
if ( F_123 ( V_301 -> V_61 . V_307 ,
L_15 ,
& V_5 -> V_36 ) )
V_5 -> V_36 = V_297 ;
}
if ( F_124 ( V_301 -> V_61 . V_307 , L_11 ) ) {
V_5 -> V_8 -> V_18 = V_269 ;
if ( F_123 ( V_301 -> V_61 . V_307 ,
L_16 ,
& V_5 -> V_71 ) )
V_5 -> V_71 = V_297 ;
if ( F_123 ( V_301 -> V_61 . V_307 ,
L_17 ,
& V_5 -> V_36 ) )
V_5 -> V_36 = V_297 ;
if ( ! V_5 -> V_15 )
goto V_315;
if ( F_126 ( V_301 -> V_61 . V_307 , L_18 , NULL ) )
V_5 -> V_23 = F_127 (
V_301 -> V_61 . V_307 , L_18 , 0 ) ;
else
V_5 -> V_23 = - 1 ;
if ( F_126 ( V_301 -> V_61 . V_307 , L_19 , NULL ) )
V_5 -> V_32 = F_127 (
V_301 -> V_61 . V_307 , L_19 , 0 ) ;
else
V_5 -> V_32 = - 1 ;
if ( ( ! F_34 ( V_5 -> V_23 ) ||
! F_34 ( V_5 -> V_32 ) ) ) {
V_255 = - V_295 ;
F_22 ( & V_301 -> V_61 ,
L_20 ) ;
goto V_310;
}
V_255 = F_128 ( & V_301 -> V_61 , V_5 -> V_23 ,
L_21 ) ;
if ( V_255 ) {
F_22 ( & V_301 -> V_61 , L_22 ) ;
goto V_310;
}
F_129 ( V_5 -> V_23 ) ;
V_255 = F_128 ( & V_301 -> V_61 , V_5 -> V_32 ,
L_23 ) ;
if ( V_255 ) {
F_22 ( & V_301 -> V_61 , L_24 ) ;
goto V_310;
}
F_130 ( V_5 -> V_32 , 1 ) ;
}
V_315:
if ( F_124 ( V_301 -> V_61 . V_307 , L_25 ) )
V_5 -> V_41 = true ;
if ( F_123 ( V_301 -> V_61 . V_307 ,
L_26 ,
& V_3 -> V_316 ) ) {
F_22 ( & V_301 -> V_61 ,
L_27 ) ;
V_255 = - V_309 ;
goto V_310;
}
V_303 = F_131 ( V_301 , V_317 , 0 ) ;
if ( V_303 == NULL ) {
F_22 ( & V_301 -> V_61 , L_28 ) ;
V_255 = - V_309 ;
goto V_310;
}
F_132 ( & V_5 -> V_123 ) ;
F_132 ( & V_5 -> V_106 ) ;
F_133 ( & V_5 -> V_156 ,
F_68 , ( unsigned long ) V_5 ) ;
F_133 ( & V_5 -> V_133 ,
F_55 , ( unsigned long ) V_5 ) ;
V_3 -> V_281 = V_303 -> V_318 ;
V_3 -> V_319 = F_134 ( & V_301 -> V_61 , V_303 -> V_318 , F_135 ( V_303 ) ) ;
if ( ! V_3 -> V_319 ) {
F_22 ( & V_301 -> V_61 , L_29 ) ;
V_255 = - V_261 ;
goto V_310;
}
V_303 = F_131 ( V_301 , V_320 , 0 ) ;
if ( V_303 == NULL ) {
F_22 ( & V_301 -> V_61 , L_28 ) ;
V_255 = - V_309 ;
goto V_310;
}
V_3 -> V_75 = V_303 -> V_318 ;
V_5 -> V_321 = F_136 ( & V_301 -> V_61 , NULL ) ;
if ( F_137 ( V_5 -> V_321 ) ) {
V_255 = F_138 ( V_5 -> V_321 ) ;
goto V_310;
}
F_139 ( V_5 -> V_321 ) ;
V_3 -> V_188 = F_140 ( V_5 -> V_321 ) ;
V_3 -> V_322 = & V_323 ;
F_132 ( & V_3 -> V_97 ) ;
F_141 ( V_301 , V_5 ) ;
V_255 = F_142 ( & V_324 , V_3 ) ;
if ( V_255 != 0 ) {
F_22 ( & V_301 -> V_61 , L_30 , V_301 -> V_308 ) ;
goto V_325;
}
return 0 ;
V_325:
F_143 ( V_5 -> V_321 ) ;
F_144 ( V_5 -> V_321 ) ;
V_310:
return V_255 ;
}
static int F_145 ( struct V_300 * V_301 )
{
struct V_1 * V_5 = F_146 ( V_301 ) ;
struct V_2 * V_3 = & V_5 -> V_3 ;
F_143 ( V_5 -> V_321 ) ;
F_144 ( V_5 -> V_321 ) ;
F_147 ( & V_324 , V_3 ) ;
return 0 ;
}
static int
F_148 ( struct V_300 * V_301 , T_5 V_47 )
{
struct V_1 * V_5 = F_146 ( V_301 ) ;
struct V_2 * V_3 = & V_5 -> V_3 ;
F_149 ( & V_324 , V_3 ) ;
return 0 ;
}
static int F_150 ( struct V_300 * V_301 )
{
struct V_1 * V_5 = F_146 ( V_301 ) ;
struct V_2 * V_3 = & V_5 -> V_3 ;
F_151 ( & V_324 , V_3 ) ;
return 0 ;
}
static int T_4 F_152 ( void )
{
int V_255 = 0 ;
V_255 = F_153 ( & V_324 ) ;
if ( V_255 )
goto V_326;
V_255 = F_154 ( & V_327 ) ;
if ( V_255 )
F_155 ( & V_324 ) ;
V_326:
return V_255 ;
}
static void T_6 F_156 ( void )
{
F_157 ( & V_327 ) ;
F_155 ( & V_324 ) ;
}
