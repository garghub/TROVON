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
if ( F_33 ( V_5 -> V_23 ) && V_5 -> V_16 )
F_34 ( V_3 ,
! F_6 ( V_5 -> V_23 ) ) ;
return V_75 ;
}
static void F_35 ( struct V_2 * V_3 )
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
V_76 | V_77 ) ;
if ( ! V_5 -> V_40 )
F_8 ( V_3 , V_7 -> V_41 ,
F_4 ( V_3 , V_7 -> V_41 )
| V_34 -> V_72 ) ;
else
F_8 ( V_3 , V_7 -> V_41 ,
V_34 -> V_72 ) ;
} else
F_36 ( F_31 ( V_5 -> V_23 ) ) ;
}
static void F_37 ( struct V_2 * V_3 , int V_78 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
if ( V_5 -> V_8 -> V_18 == V_19 ) {
unsigned long V_79 = F_4 ( V_3 , V_7 -> V_80 ) ;
if ( V_78 )
V_79 |= V_81 ;
else
V_79 &= ~ V_81 ;
F_8 ( V_3 , V_7 -> V_80 , V_79 ) ;
}
}
static unsigned int
F_38 ( struct V_2 * V_3 , unsigned int V_82 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_9 * V_10 = & V_5 -> V_8 -> V_11 ;
unsigned int V_83 , V_84 = 0 ;
struct V_85 * V_86 ;
V_86 = F_39 ( & V_3 -> V_46 -> V_3 ) ;
if ( ! V_86 )
return - V_87 ;
while ( ! ( F_4 ( V_3 , V_7 -> V_88 ) &
V_10 -> V_13 ( V_3 -> line ) ) ) {
V_83 = F_4 ( V_3 , V_7 -> V_89 ) |
V_90 ;
if ( F_40 ( F_41 ( V_3 , V_83 ) ) )
continue;
F_42 ( V_3 , 0 , 0 , V_83 , V_91 ) ;
V_84 ++ ;
if ( V_84 >= V_82 )
break;
}
V_5 -> V_92 += V_84 ;
V_3 -> V_93 . V_94 += V_84 ;
F_43 ( & V_3 -> V_95 ) ;
F_44 ( & V_3 -> V_46 -> V_3 ) ;
F_45 ( & V_3 -> V_95 ) ;
return V_84 ;
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
V_3 -> V_93 . V_100 ++ ;
V_97 ++ ;
}
if ( F_46 ( V_45 ) < V_101 )
F_47 ( V_3 ) ;
return V_97 ;
}
static void V_66 ( void * V_102 )
{
struct V_1 * V_5 = (struct V_1 * ) V_102 ;
struct V_2 * V_3 = & V_5 -> V_3 ;
struct V_44 * V_45 = & V_3 -> V_46 -> V_45 ;
unsigned long V_103 ;
V_45 -> V_51 = ( V_45 -> V_51 + V_5 -> V_68 ) &
( V_52 - 1 ) ;
V_3 -> V_93 . V_100 += V_5 -> V_68 ;
if ( F_46 ( V_45 ) < V_101 )
F_47 ( V_3 ) ;
if ( V_5 -> V_59 )
F_48 ( V_3 -> V_60 , V_5 -> V_59 ,
V_5 -> V_68 , V_61 ) ;
F_49 ( & V_5 -> V_104 , V_103 ) ;
V_5 -> V_37 = V_105 ;
F_12 ( V_5 ) ;
F_50 ( & V_5 -> V_104 , V_103 ) ;
}
static void F_51 (
struct V_1 * V_5 , int V_96 )
{
struct V_2 * V_3 = & V_5 -> V_3 ;
struct V_106 * V_107 = & V_3 -> V_46 -> V_3 ;
int V_108 ;
V_108 = F_52 ( V_107 ,
V_5 -> V_109 [ V_5 -> V_110 ] . V_45 . V_53 , V_96 ) ;
V_3 -> V_93 . V_94 += V_108 ;
F_44 ( V_107 ) ;
}
static void F_53 ( struct V_2 * V_3 , int V_111 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
V_5 -> V_109 [ V_111 ] . V_45 . V_51 =
V_5 -> V_109 [ V_111 ] . V_45 . V_50 = 0 ;
V_5 -> V_109 [ V_111 ] . V_112 =
F_20 ( V_5 -> V_70 ,
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
F_23 ( V_5 -> V_70 ) ;
}
static void F_54 ( unsigned long V_102 )
{
struct V_1 * V_5 = (struct V_1 * ) V_102 ;
struct V_2 * V_3 = & V_5 -> V_3 ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_33 * V_34 = & V_5 -> V_8 -> V_35 ;
struct V_118 * V_119 = & V_5 -> V_8 -> V_120 ;
unsigned int V_96 ;
unsigned long V_103 ;
struct V_121 V_122 ;
F_49 ( & V_5 -> V_123 , V_103 ) ;
while ( V_124 == F_55 ( V_5 -> V_70 ,
V_5 -> V_109 [ V_5 -> V_110 ] . V_117 , & V_122 ) ) {
F_51 ( V_5 ,
V_114 ) ;
V_5 -> V_110 ++ ;
V_5 -> V_110 %= V_125 ;
}
V_96 = F_56 ( V_5 -> V_109 [ V_5 -> V_126 ] . V_45 . V_50 ,
V_5 -> V_109 [ V_5 -> V_126 ] . V_45 . V_51 ,
V_114 ) ;
if ( V_96 > 0 )
F_51 ( V_5 , V_96 ) ;
F_8 ( V_3 , V_7 -> V_127 ,
F_4 ( V_3 , V_7 -> V_127 ) |
V_57 ) ;
F_50 ( & V_5 -> V_123 , V_103 ) ;
F_45 ( & V_3 -> V_95 ) ;
F_38 ( V_3 , 4 - V_5 -> V_92 ) ;
F_43 ( & V_3 -> V_95 ) ;
if ( V_5 -> V_92 == 4 ) {
F_49 ( & V_5 -> V_123 , V_103 ) ;
V_5 -> V_92 = 0 ;
F_8 ( V_3 , V_7 -> V_128 ,
V_119 -> V_129 ) ;
if ( ! V_5 -> V_40 )
F_8 ( V_3 , V_7 -> V_41 ,
F_4 ( V_3 , V_7 -> V_41 ) &
~ ( V_34 -> V_71 ) ) ;
else
F_8 ( V_3 , V_43 ,
V_34 -> V_71 ) ;
F_50 ( & V_5 -> V_123 , V_103 ) ;
F_57 ( V_3 ) ;
} else {
F_49 ( & V_5 -> V_123 , V_103 ) ;
F_8 ( V_3 , V_7 -> V_128 ,
V_119 -> V_129 ) ;
if ( ! V_5 -> V_40 )
F_8 ( V_3 , V_7 -> V_41 ,
F_4 ( V_3 , V_7 -> V_41 ) |
( V_34 -> V_71 ) ) ;
else
F_8 ( V_3 , V_7 -> V_41 ,
V_34 -> V_71 ) ;
F_50 ( & V_5 -> V_123 , V_103 ) ;
}
}
static void F_58 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = & V_5 -> V_3 ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_33 * V_34 = & V_5 -> V_8 -> V_35 ;
struct V_121 V_122 ;
F_45 ( & V_5 -> V_123 ) ;
F_55 ( V_5 -> V_70 ,
V_5 -> V_109 [ V_5 -> V_126 ] . V_117 , & V_122 ) ;
F_27 ( V_5 -> V_70 ) ;
V_5 -> V_109 [ V_5 -> V_126 ] . V_45 . V_50 =
V_114 - V_122 . V_130 ;
if ( ! V_5 -> V_40 )
F_8 ( V_3 , V_7 -> V_41 ,
F_4 ( V_3 , V_7 -> V_41 ) &
~ ( V_34 -> V_131 ) ) ;
else
F_8 ( V_3 , V_43 ,
V_34 -> V_131 ) ;
F_43 ( & V_5 -> V_123 ) ;
F_59 ( & V_5 -> V_132 ) ;
}
static void F_60 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = & V_5 -> V_3 ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_33 * V_34 = & V_5 -> V_8 -> V_35 ;
struct V_118 * V_119 = & V_5 -> V_8 -> V_120 ;
F_38 ( V_3 , 4 - V_5 -> V_92 ) ;
if ( V_5 -> V_92 == 4 ) {
V_5 -> V_92 = 0 ;
if ( ! V_5 -> V_40 )
F_8 ( V_3 , V_7 -> V_41 ,
F_4 ( V_3 , V_7 -> V_41 ) &
~ ( V_34 -> V_71 ) ) ;
else
F_8 ( V_3 , V_43 ,
V_34 -> V_71 ) ;
F_8 ( V_3 , V_7 -> V_128 ,
V_119 -> V_133 ) ;
F_57 ( V_3 ) ;
}
}
static T_1 F_61 ( int V_73 , void * V_74 )
{
unsigned long V_134 ;
unsigned long V_135 ;
unsigned long V_136 = V_91 ;
struct V_1 * V_5 = (struct V_1 * ) V_74 ;
struct V_2 * V_3 = & V_5 -> V_3 ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_9 * V_10 = & V_5 -> V_8 -> V_11 ;
struct V_118 * V_119 = & V_5 -> V_8 -> V_120 ;
struct V_33 * V_34 = & V_5 -> V_8 -> V_35 ;
struct V_137 * V_46 = V_3 -> V_46 ;
struct V_44 * V_45 = & V_3 -> V_46 -> V_45 ;
F_45 ( & V_3 -> V_95 ) ;
V_134 = F_4 ( V_3 , V_7 -> V_128 ) ;
F_8 ( V_3 , V_7 -> V_128 , V_134 ) ;
V_134 &= F_4 ( V_3 , V_7 -> V_41 ) ;
if ( F_40 ( V_134 & ( F_62 ( V_3 , V_119 ) ) ) ) {
if ( V_134 & V_119 -> V_138 ) {
V_3 -> V_93 . V_139 ++ ;
if ( F_63 ( V_3 ) )
goto V_140;
}
if ( V_134 & V_119 -> V_141 )
V_3 -> V_93 . V_142 ++ ;
if ( V_134 & V_119 -> V_143 ) {
V_3 -> V_93 . V_144 ++ ;
V_136 = V_145 ;
}
if ( V_134 & V_119 -> V_146 )
V_136 = V_147 ;
F_8 ( V_3 , V_7 -> V_69 , V_148 ) ;
F_8 ( V_3 , V_7 -> V_69 , 0 ) ;
F_8 ( V_3 , V_7 -> V_69 , V_58 ) ;
V_134 &= V_3 -> V_149 ;
F_42 ( V_3 , V_134 ,
V_34 -> V_150 , 0 , V_136 ) ;
F_44 ( & V_46 -> V_3 ) ;
}
V_140:
if ( ( V_5 -> V_8 -> V_18 == V_19 ) &&
( V_134 & F_64 ( V_119 ) ) &&
! V_5 -> V_37 ) {
V_135 = F_4 ( V_3 , V_7 -> V_20 ) &
V_21 ;
if ( V_135 != 0 )
V_135 = 0 ;
else
V_135 = 1 ;
F_34 ( V_3 , V_135 ) ;
F_65 ( & V_46 -> V_3 . V_151 ) ;
}
if ( V_5 -> V_70 ) {
if ( V_134 & V_119 -> V_133 )
F_58 ( V_5 ) ;
if ( V_134 & V_119 -> V_129 )
F_60 ( V_5 ) ;
} else {
if ( V_134 & F_66 ( V_119 ) )
F_38 ( V_3 ,
V_152 ) ;
}
if ( V_134 & V_119 -> V_153 ) {
if ( V_5 -> V_36 )
F_12 ( V_5 ) ;
else {
if ( F_14 ( V_45 ) || F_15 ( V_3 ) ) {
F_43 ( & V_3 -> V_95 ) ;
return V_75 ;
} else {
F_18 ( V_5 ,
V_154 ) ;
if ( ( F_14 ( V_45 ) ) &&
( F_4 ( V_3 , V_7 -> V_12 ) &
V_10 -> V_13 ( V_3 -> line ) ) )
F_10 ( V_3 ) ;
}
}
}
F_43 ( & V_3 -> V_95 ) ;
return V_75 ;
}
static void F_67 ( unsigned long V_102 )
{
struct V_1 * V_5 = (struct V_1 * ) V_102 ;
struct V_2 * V_3 = & V_5 -> V_3 ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_33 * V_34 = & V_5 -> V_8 -> V_35 ;
unsigned long V_103 ;
struct V_121 V_122 ;
F_49 ( & V_5 -> V_123 , V_103 ) ;
while ( V_124 == F_55 ( V_5 -> V_70 ,
V_5 -> V_109 [ V_5 -> V_110 ] . V_117 , & V_122 ) ) {
F_51 ( V_5 ,
V_114 ) ;
if ( F_4 ( V_3 , V_7 -> V_41 ) &
V_34 -> V_131 )
F_53 ( V_3 ,
V_5 -> V_110 ++ ) ;
else
V_5 -> V_110 ++ ;
V_5 -> V_110 %= V_125 ;
}
F_50 ( & V_5 -> V_123 , V_103 ) ;
}
static void V_116 ( void * V_102 )
{
struct V_1 * V_5 = (struct V_1 * ) V_102 ;
F_45 ( & V_5 -> V_123 ) ;
V_5 -> V_126 ++ ;
V_5 -> V_126 %= V_125 ;
F_43 ( & V_5 -> V_123 ) ;
F_59 ( & V_5 -> V_155 ) ;
}
static void F_57 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_33 * V_34 = & V_5 -> V_8 -> V_35 ;
unsigned long V_103 ;
int V_156 ;
F_49 ( & V_5 -> V_123 , V_103 ) ;
V_5 -> V_92 = 0 ;
F_8 ( V_3 , V_7 -> V_127 ,
F_4 ( V_3 , V_7 -> V_127 ) &
~ V_57 ) ;
F_50 ( & V_5 -> V_123 , V_103 ) ;
for ( V_156 = 0 ; V_156 < V_125 ; V_156 ++ )
F_53 ( V_3 , V_156 ) ;
V_5 -> V_110 = V_5 -> V_126 = 0 ;
F_49 ( & V_5 -> V_123 , V_103 ) ;
if ( ! V_5 -> V_40 )
F_8 ( V_3 , V_7 -> V_41 ,
F_4 ( V_3 , V_7 -> V_41 ) |
F_26 ( V_3 , V_34 ) ) ;
else
F_8 ( V_3 , V_7 -> V_41 ,
F_26 ( V_3 , V_34 ) ) ;
F_50 ( & V_5 -> V_123 , V_103 ) ;
}
static void F_68 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_33 * V_34 = & V_5 -> V_8 -> V_35 ;
V_5 -> V_92 = 0 ;
F_8 ( V_3 , V_7 -> V_69 , V_148 ) ;
F_8 ( V_3 , V_7 -> V_69 , 0 ) ;
F_8 ( V_3 , V_7 -> V_69 , V_58 ) ;
if ( V_5 -> V_70 )
F_57 ( V_3 ) ;
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
F_69 ( unsigned long V_157 ,
unsigned long V_158 , unsigned long * V_159 )
{
unsigned long V_160 = ~ 0UL ;
unsigned short V_161 ;
unsigned long V_162 = 0 ;
unsigned long V_163 ;
for ( V_161 = V_164 ;
V_161 <= V_165 ; V_161 ++ ) {
V_163 = V_158 -
( V_158 + ( V_157 * V_161 ) / 2 )
/ ( V_157 * V_161 ) * V_157 * V_161 ;
V_163 = ( V_163 > 0 ) ? V_163 : - V_163 ;
if ( V_163 < V_160 ) {
V_162 = ( 2 * V_158 /
( V_157 * V_161 ) + 1 ) / 2 - 1 ;
if ( V_162 > V_166 )
continue;
V_160 = V_163 ;
* V_159 = V_161 ;
if ( ! V_163 )
break;
}
}
return V_162 ;
}
static unsigned int
F_70 ( unsigned long V_167 ,
unsigned long V_158 , unsigned long * V_168 )
{
unsigned long V_160 = ~ 0UL ;
unsigned short V_161 ;
unsigned int V_169 = 0 ;
unsigned long V_162 ;
unsigned long V_170 ;
int V_163 ;
for ( V_161 = V_164 ;
V_161 <= V_165 ; V_161 ++ ) {
V_162 = ( V_158 / ( V_167 * ( V_161 + 1 ) ) ) - 1 ;
if ( V_162 > V_166 )
continue;
V_170 = V_158 / ( ( V_162 + 1 ) * ( V_161 + 1 ) ) ;
V_163 = V_170 - V_167 ;
V_163 = ( V_163 > 0 ) ? V_163 : - V_163 ;
if ( V_163 < V_160 ) {
V_169 = V_169 & ( ~ V_171 ) ;
V_169 = V_169 | V_162 ;
V_169 = V_169 & ( ~ V_172 ) ;
V_169 = V_169 | ( V_161 << V_173 ) ;
V_160 = V_163 ;
* V_168 = V_170 ;
}
}
return V_169 ;
}
static void F_71 ( struct V_2 * V_3 ,
struct V_174 * V_175 ,
struct V_174 * V_176 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_33 * V_34 = & V_5 -> V_8 -> V_35 ;
unsigned long V_177 = 0 ;
unsigned long V_167 ;
unsigned long V_168 ;
unsigned long V_103 ;
unsigned long V_178 ;
unsigned int V_179 = 0 ;
unsigned long V_180 , V_158 ;
unsigned long V_181 ;
int V_182 ;
T_2 V_183 , V_184 , V_185 ;
unsigned long V_186 = 0xf ;
V_158 = V_3 -> V_187 ;
switch ( V_175 -> V_188 & V_189 ) {
default:
case V_190 :
V_183 = 8 ;
V_177 |= V_191 ;
break;
case V_192 :
V_183 = 7 ;
V_177 |= V_193 ;
break;
case V_194 :
V_183 = 6 ;
V_177 |= V_195 ;
break;
case V_196 :
V_183 = 5 ;
V_177 |= V_197 ;
break;
}
if ( V_175 -> V_188 & V_198 ) {
V_177 |= V_199 ;
V_184 = 2 ;
} else
V_184 = 1 ;
F_49 ( & V_3 -> V_95 , V_103 ) ;
V_3 -> V_149 = V_34 -> V_150 ;
V_3 -> V_200 = 0 ;
if ( V_5 -> V_8 -> V_18 == V_19 ) {
if ( V_175 -> V_201 & V_202 )
V_3 -> V_149 |= V_34 -> V_203 |
V_34 -> V_204 ;
} else {
if ( V_175 -> V_201 & V_202 )
V_3 -> V_149 |= V_34 -> V_203 ;
}
if ( V_175 -> V_201 & ( V_205 | V_206 ) )
V_3 -> V_149 |= V_34 -> V_207 ;
if ( V_5 -> V_8 -> V_18 == V_19 ) {
if ( V_175 -> V_201 & V_208 )
V_3 -> V_200 |=
V_34 -> V_203 |
V_34 -> V_204 ;
if ( V_175 -> V_188 & V_209 ) {
if ( V_175 -> V_188 & V_210 ) {
if ( V_175 -> V_188 & V_211 )
V_177 |= V_212 ;
else
V_177 |= V_213 ;
} else if ( V_175 -> V_188 & V_211 ) {
V_177 |= V_214 ;
} else {
V_177 |= V_215 ;
}
}
} else {
if ( V_175 -> V_201 & V_208 )
V_3 -> V_200 |=
V_34 -> V_203 ;
if ( V_175 -> V_188 & V_209 )
F_72 ( V_3 -> V_60 ,
L_3 ) ;
}
if ( V_175 -> V_201 & V_216 ) {
V_3 -> V_200 |=
V_34 -> V_207 ;
if ( V_175 -> V_201 & V_208 )
V_3 -> V_200 |=
V_34 -> V_150 ;
}
if ( ( V_175 -> V_188 & V_217 ) == 0 )
V_3 -> V_200 |= V_90 ;
if ( F_73 ( V_3 , V_175 -> V_188 ) ) {
if ( ! V_5 -> V_16 )
F_35 ( V_3 ) ;
} else {
if ( V_5 -> V_16 )
F_29 ( V_3 ) ;
}
V_167 = F_74 ( V_3 , V_175 , V_176 , 0 , 4000000 ) ;
if ( V_158 == 150000000 ) {
for ( V_178 = 0 ; V_178 < V_218 ; V_178 ++ )
if ( V_167 == V_219 [ V_178 ] . V_167 )
V_179 = V_219 [ V_178 ] . V_220 ;
}
V_168 = V_167 ;
if ( V_5 -> V_8 -> V_18 == V_19 ) {
if ( F_40 ( V_179 == 0 ) )
V_179 = F_70 ( V_167 ,
V_158 , & V_168 ) ;
F_8 ( V_3 , V_7 -> V_221 , V_179 ) ;
} else {
V_179 = F_69 ( V_167 ,
V_158 , & V_186 ) ;
V_186 -- ;
V_168 = ( ( V_158 / ( V_179 + 1 ) - 1 ) /
( V_186 + 1 ) ) ;
V_185 = ( ( 1 << V_222 ) |
( 1 << V_223 ) ) ;
V_185 |= ( ( V_179 & V_224 )
<< V_225 ) ;
F_8 ( V_3 , V_7 -> V_226 , V_185 ) ;
}
if ( F_75 ( V_175 ) )
F_76 ( V_175 , V_168 , V_168 ) ;
V_181 = F_77 ( V_168 , 20000 ) ;
V_181 = F_78 ( V_181 ) ;
V_180 = F_4 ( V_3 , V_7 -> V_54 ) ;
F_8 ( V_3 , V_7 -> V_69 , V_55 ) ;
F_8 ( V_3 , V_7 -> V_54 ,
( V_180 & ~ V_58 ) ) ;
if ( V_5 -> V_8 -> V_18 == V_19 ) {
V_177 |= F_79 ( V_3 , V_181 ) ;
F_8 ( V_3 , V_7 -> V_80 , V_177 ) ;
} else {
V_185 = ( V_183 - 1 ) << V_227 ;
V_185 |= ( V_183 + 1 + V_184 - 1 ) <<
V_228 ;
V_185 |= ( ( V_183 - 1 ) <<
V_229 ) ;
V_185 |= ( ( ( V_179 & 0xc00 ) >> 10 ) <<
V_230 ) ;
F_8 ( V_3 , V_7 -> V_231 , V_185 ) ;
V_185 = ( V_183 - 1 ) << V_232 ;
V_185 |= ( V_183 + 1 + V_184 - 1 ) <<
V_233 ;
V_185 |= ( V_183 - 1 ) <<
V_234 ;
V_185 |= ( ( ( V_179 & 0xf000 ) >> 12 ) <<
V_235 ) ;
F_8 ( V_3 , V_7 -> V_236 , V_185 ) ;
F_8 ( V_3 , V_7 -> V_237 ,
( F_79 ( V_3 , V_181 ) ) |
( V_186 & V_238 ) <<
V_239 ) ;
}
if ( V_5 -> V_36 )
F_8 ( V_3 , V_7 -> V_56 , V_240 ) ;
else
F_8 ( V_3 , V_7 -> V_56 , V_57 ) ;
if ( V_5 -> V_70 )
F_8 ( V_3 , V_7 -> V_127 , V_240 ) ;
else
F_8 ( V_3 , V_7 -> V_127 , V_57 ) ;
if ( V_168 < 1000000 )
V_182 = 1 ;
else
V_182 = 2 ;
F_8 ( V_3 , V_7 -> V_241 ,
F_80 ( V_3 ) / V_182 ) ;
F_8 ( V_3 , V_7 -> V_242 ,
F_80 ( V_3 ) / V_182 ) ;
V_180 |= V_58 ;
F_8 ( V_3 , V_7 -> V_54 , V_180 ) ;
F_81 ( V_3 , V_175 -> V_188 , V_168 ) ;
F_68 ( V_3 ) ;
F_8 ( V_3 , V_7 -> V_243 , V_244 | V_245 ) ;
F_50 ( & V_3 -> V_95 , V_103 ) ;
}
static void F_82 ( struct V_2 * V_3 , unsigned int V_46 ,
unsigned int V_246 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( ! V_46 )
F_83 ( V_5 -> V_247 ) ;
else
F_84 ( V_5 -> V_247 ) ;
}
static int F_85 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
unsigned int V_111 = V_3 -> line ;
int V_248 ;
F_86 ( V_3 -> V_73 , V_249 | V_250 ) ;
V_248 = F_87 ( V_3 -> V_73 ,
F_61 ,
0 ,
V_251 ,
V_5 ) ;
if ( V_248 != 0 ) {
F_21 ( V_3 -> V_60 , L_4 ,
V_111 , V_3 -> V_73 ) ;
goto V_252;
}
F_8 ( V_3 , V_7 -> V_56 ,
F_4 ( V_3 , V_7 -> V_56 ) |
V_57 ) ;
F_8 ( V_3 , V_7 -> V_127 ,
F_4 ( V_3 , V_7 -> V_127 ) |
V_57 ) ;
F_8 ( V_3 , V_7 -> V_253 , 0 ) ;
F_8 ( V_3 , V_7 -> V_254 , 0 ) ;
F_8 ( V_3 , V_7 -> V_243 , V_245 | V_244 ) ;
if ( V_5 -> V_8 -> V_18 == V_255 )
F_8 ( V_3 , V_7 -> V_256 ,
V_257 |
V_258 ) ;
F_8 ( V_3 , V_7 -> V_54 , V_148 ) ;
F_8 ( V_3 , V_7 -> V_54 , 0 ) ;
F_8 ( V_3 , V_7 -> V_69 , V_148 ) ;
F_8 ( V_3 , V_7 -> V_69 , 0 ) ;
F_8 ( V_3 , V_7 -> V_241 , F_80 ( V_3 ) ) ;
F_8 ( V_3 , V_7 -> V_242 , F_80 ( V_3 ) ) ;
if ( V_5 -> V_70 )
F_8 ( V_3 , V_7 -> V_259 ,
F_88 ( V_3 -> line , 0x4 ) |
F_89 ( V_3 -> line , 0xe ) |
F_90 ( V_3 -> line , 0x1b ) ) ;
if ( V_5 -> V_36 ) {
V_5 -> V_37 = V_105 ;
F_8 ( V_3 , V_7 -> V_260 ,
F_91 ( V_3 -> line , 0x1b ) |
F_92 ( V_3 -> line , 0xe ) |
F_93 ( V_3 -> line , 0x4 ) ) ;
}
V_5 -> V_16 = false ;
if ( V_5 -> V_8 -> V_18 == V_255 &&
V_5 -> V_15 ) {
F_86 ( F_31 ( V_5 -> V_23 ) ,
V_249 | V_250 ) ;
V_248 = F_87 ( F_31 ( V_5 -> V_23 ) ,
F_32 , V_261 |
V_262 , L_5 , V_5 ) ;
if ( V_248 != 0 ) {
F_21 ( V_3 -> V_60 , L_6 ) ;
goto V_263;
}
}
F_36 ( V_3 -> V_73 ) ;
return 0 ;
V_263:
F_94 ( V_3 -> V_73 , V_5 ) ;
V_252:
return V_248 ;
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
if ( V_5 -> V_8 -> V_18 == V_255 &&
V_5 -> V_15 ) {
F_9 ( V_5 -> V_32 , 1 ) ;
F_94 ( F_31 ( V_5 -> V_23 ) , V_5 ) ;
}
if ( V_5 -> V_36 )
V_5 -> V_37 = V_105 ;
}
static const char * F_96 ( struct V_2 * V_3 )
{
return V_3 -> type == V_264 ? V_251 : NULL ;
}
static int F_97 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_265 * V_266 = & V_5 -> V_8 -> V_266 ;
void * V_248 ;
V_248 = F_98 ( V_3 -> V_267 ,
V_268 , V_266 -> V_269 ) ;
return V_248 ? 0 : - V_270 ;
}
static void F_99 ( struct V_2 * V_3 )
{
F_100 ( V_3 -> V_267 , V_268 ) ;
}
static void F_101 ( struct V_2 * V_3 , int V_103 )
{
if ( V_103 & V_271 ) {
V_3 -> type = V_264 ;
F_97 ( V_3 ) ;
}
}
static int T_3
F_102 ( struct V_272 * V_273 , char * V_274 )
{
unsigned int V_275 = 115200 ;
unsigned int V_276 = 8 ;
unsigned int V_277 = 'n' ;
unsigned int V_278 = 'n' ;
struct V_2 * V_3 = & V_279 [ V_273 -> V_111 ] . V_3 ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
if ( V_273 -> V_111 < 0 || V_273 -> V_111 >= V_280 )
return - V_281 ;
if ( ! V_3 -> V_267 )
return - V_87 ;
if ( V_5 -> V_8 -> V_18 == V_255 )
F_8 ( V_3 , V_7 -> V_256 , V_258 |
V_257 ) ;
if ( V_274 )
F_103 ( V_274 , & V_275 , & V_277 , & V_276 , & V_278 ) ;
V_3 -> V_282 = V_273 ;
V_5 -> V_70 = NULL ;
V_5 -> V_36 = NULL ;
return F_104 ( V_3 , V_273 , V_275 , V_277 , V_276 , V_278 ) ;
}
static void F_105 ( struct V_2 * V_3 , int V_83 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_9 * V_10 = & V_5 -> V_8 -> V_11 ;
while ( F_4 ( V_3 ,
V_7 -> V_12 ) & V_10 -> V_98 ( V_3 -> line ) )
F_106 () ;
F_107 ( V_3 , V_7 -> V_99 , V_83 ) ;
}
static void F_108 ( struct V_272 * V_273 , const char * V_283 ,
unsigned int V_96 )
{
struct V_2 * V_3 = & V_279 [ V_273 -> V_111 ] . V_3 ;
F_109 ( V_3 , V_283 , V_96 , F_105 ) ;
}
static int T_3 F_110 ( void )
{
F_111 ( & V_284 ) ;
return 0 ;
}
static int F_112 ( struct V_285 * V_286 )
{
struct V_1 * V_5 ;
struct V_2 * V_3 ;
struct V_287 * V_288 ;
int V_248 ;
int V_156 , V_289 ;
struct V_290 V_291 = {
. V_292 = 2 ,
} ;
struct V_290 V_293 = {
. V_294 = 2 ,
} ;
const struct V_295 * V_296 ;
V_296 = F_113 ( V_297 , V_286 -> V_60 . V_298 ) ;
if ( F_114 ( V_286 -> V_60 . V_298 , L_7 , & V_286 -> V_299 ) ) {
F_21 ( & V_286 -> V_60 ,
L_8 ) ;
V_248 = - V_300 ;
goto V_301;
}
if ( F_115 ( V_286 -> V_60 . V_298 , L_9 ) )
V_286 -> V_299 += ( (struct V_302 * )
V_296 -> V_303 ) -> V_266 . V_304 ;
V_5 = & V_279 [ V_286 -> V_299 ] ;
V_3 = & V_5 -> V_3 ;
V_3 -> V_60 = & V_286 -> V_60 ;
V_3 -> V_305 = V_5 ;
V_5 -> V_8 = (struct V_302 * ) V_296 -> V_303 ;
V_5 -> V_15 = F_116 ( V_286 -> V_60 . V_298 ,
L_10 ) ;
if ( F_115 ( V_286 -> V_60 . V_298 , L_11 ) )
V_5 -> V_8 -> V_18 = V_19 ;
if ( F_115 ( V_286 -> V_60 . V_298 , L_9 ) ) {
V_5 -> V_8 -> V_18 = V_255 ;
if ( ! V_5 -> V_15 )
goto V_306;
if ( F_117 ( V_286 -> V_60 . V_298 , L_12 , NULL ) )
V_5 -> V_23 = F_118 (
V_286 -> V_60 . V_298 , L_12 , 0 ) ;
else
V_5 -> V_23 = - 1 ;
if ( F_117 ( V_286 -> V_60 . V_298 , L_13 , NULL ) )
V_5 -> V_32 = F_118 (
V_286 -> V_60 . V_298 , L_13 , 0 ) ;
else
V_5 -> V_32 = - 1 ;
if ( ( ! F_33 ( V_5 -> V_23 ) ||
! F_33 ( V_5 -> V_32 ) ) ) {
V_248 = - V_281 ;
F_21 ( & V_286 -> V_60 ,
L_14 ) ;
goto V_301;
}
V_248 = F_119 ( & V_286 -> V_60 , V_5 -> V_23 ,
L_15 ) ;
if ( V_248 ) {
F_21 ( & V_286 -> V_60 , L_16 ) ;
goto V_301;
}
F_120 ( V_5 -> V_23 ) ;
V_248 = F_119 ( & V_286 -> V_60 , V_5 -> V_32 ,
L_17 ) ;
if ( V_248 ) {
F_21 ( & V_286 -> V_60 , L_18 ) ;
goto V_301;
}
F_121 ( V_5 -> V_32 , 1 ) ;
}
V_306:
if ( F_115 ( V_286 -> V_60 . V_298 , L_19 ) )
V_5 -> V_40 = true ;
if ( F_114 ( V_286 -> V_60 . V_298 ,
L_20 ,
& V_3 -> V_307 ) ) {
F_21 ( & V_286 -> V_60 ,
L_21 ) ;
V_248 = - V_300 ;
goto V_301;
}
V_288 = F_122 ( V_286 , V_308 , 0 ) ;
if ( V_288 == NULL ) {
F_21 ( & V_286 -> V_60 , L_22 ) ;
V_248 = - V_300 ;
goto V_301;
}
F_123 ( & V_5 -> V_123 ) ;
F_123 ( & V_5 -> V_104 ) ;
F_124 ( & V_5 -> V_155 ,
F_67 , ( unsigned long ) V_5 ) ;
F_124 ( & V_5 -> V_132 ,
F_54 , ( unsigned long ) V_5 ) ;
V_3 -> V_267 = V_288 -> V_309 ;
V_3 -> V_310 = F_125 ( & V_286 -> V_60 , V_288 -> V_309 , F_126 ( V_288 ) ) ;
if ( ! V_3 -> V_310 ) {
F_21 ( & V_286 -> V_60 , L_23 ) ;
V_248 = - V_311 ;
goto V_301;
}
V_288 = F_122 ( V_286 , V_312 , 0 ) ;
if ( V_288 == NULL ) {
F_21 ( & V_286 -> V_60 , L_22 ) ;
V_248 = - V_300 ;
goto V_301;
}
V_3 -> V_73 = V_288 -> V_309 ;
V_5 -> V_247 = F_127 ( & V_286 -> V_60 , NULL ) ;
if ( F_128 ( V_5 -> V_247 ) ) {
V_248 = F_129 ( V_5 -> V_247 ) ;
goto V_301;
}
V_3 -> V_187 = F_130 ( V_5 -> V_247 ) ;
V_3 -> V_313 = & V_314 ;
F_123 ( & V_3 -> V_95 ) ;
F_131 ( V_286 , V_5 ) ;
V_248 = F_132 ( & V_315 , V_3 ) ;
if ( V_248 != 0 ) {
F_21 ( & V_286 -> V_60 , L_24 , V_286 -> V_299 ) ;
goto V_316;
}
V_5 -> V_70 = F_133 ( V_3 -> V_60 , L_25 ) ;
for ( V_156 = 0 ; V_5 -> V_70 && V_156 < V_125 ; V_156 ++ ) {
V_5 -> V_109 [ V_156 ] . V_45 . V_53 =
F_134 ( V_3 -> V_60 , V_114 ,
& V_5 -> V_109 [ V_156 ] . V_113 , V_317 ) ;
if ( ! V_5 -> V_109 [ V_156 ] . V_45 . V_53 ) {
F_21 ( V_3 -> V_60 , L_26 ) ;
V_248 = - V_311 ;
goto V_318;
}
V_5 -> V_109 [ V_156 ] . V_45 . V_50 =
V_5 -> V_109 [ V_156 ] . V_45 . V_51 = 0 ;
}
if ( V_5 -> V_70 )
F_135 ( V_5 -> V_70 , & V_291 ) ;
V_5 -> V_36 = F_133 ( V_3 -> V_60 , L_27 ) ;
if ( V_5 -> V_36 )
F_135 ( V_5 -> V_36 , & V_293 ) ;
return 0 ;
V_318:
for ( V_289 = 0 ; V_289 < V_156 ; V_289 ++ )
F_136 ( V_3 -> V_60 , V_114 ,
V_5 -> V_109 [ V_289 ] . V_45 . V_53 ,
V_5 -> V_109 [ V_289 ] . V_113 ) ;
F_137 ( V_5 -> V_70 ) ;
V_316:
F_138 ( V_5 -> V_247 ) ;
V_301:
return V_248 ;
}
static int F_139 ( struct V_285 * V_286 )
{
struct V_1 * V_5 = F_140 ( V_286 ) ;
struct V_2 * V_3 = & V_5 -> V_3 ;
F_138 ( V_5 -> V_247 ) ;
F_141 ( & V_315 , V_3 ) ;
if ( V_5 -> V_70 ) {
int V_156 ;
F_27 ( V_5 -> V_70 ) ;
F_137 ( V_5 -> V_70 ) ;
for ( V_156 = 0 ; V_156 < V_125 ; V_156 ++ )
F_136 ( V_3 -> V_60 , V_114 ,
V_5 -> V_109 [ V_156 ] . V_45 . V_53 ,
V_5 -> V_109 [ V_156 ] . V_113 ) ;
}
if ( V_5 -> V_36 ) {
F_27 ( V_5 -> V_36 ) ;
F_137 ( V_5 -> V_36 ) ;
}
return 0 ;
}
static int
F_142 ( struct V_319 * V_286 )
{
struct V_1 * V_5 = F_143 ( V_286 ) ;
struct V_2 * V_3 = & V_5 -> V_3 ;
F_144 ( & V_315 , V_3 ) ;
return 0 ;
}
static int F_145 ( struct V_319 * V_286 )
{
struct V_1 * V_5 = F_143 ( V_286 ) ;
struct V_2 * V_3 = & V_5 -> V_3 ;
F_146 ( & V_315 , V_3 ) ;
return 0 ;
}
static int T_3 F_147 ( void )
{
int V_248 = 0 ;
V_248 = F_148 ( & V_315 ) ;
if ( V_248 )
goto V_320;
V_248 = F_149 ( & V_321 ) ;
if ( V_248 )
F_150 ( & V_315 ) ;
V_320:
return V_248 ;
}
static void T_4 F_151 ( void )
{
F_152 ( & V_321 ) ;
F_150 ( & V_315 ) ;
}
