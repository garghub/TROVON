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
return ( V_4 & V_10 -> V_13 ( V_3 ) ) ? V_14 : 0 ;
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
if ( V_27 & V_32 ) {
if ( V_5 -> V_8 -> V_18 == V_19 )
F_8 ( V_3 , V_7 -> V_33 ,
F_4 ( V_3 , V_7 -> V_33 ) |
V_34 ) ;
else
F_8 ( V_3 , V_7 -> V_35 ,
F_4 ( V_3 , V_7 -> V_35 ) |
V_36 ) ;
} else {
if ( V_5 -> V_8 -> V_18 == V_19 )
F_8 ( V_3 , V_7 -> V_33 ,
F_4 ( V_3 , V_7 -> V_33 ) &
~ V_34 ) ;
else
F_8 ( V_3 , V_7 -> V_35 ,
F_4 ( V_3 , V_7 -> V_35 ) &
~ V_36 ) ;
}
if ( ! V_5 -> V_15 || ! V_5 -> V_16 )
return;
if ( V_5 -> V_8 -> V_18 == V_19 ) {
V_31 = F_4 ( V_3 , V_7 -> V_20 ) & ~ 0xFF ;
V_29 |= V_31 ;
F_8 ( V_3 , V_7 -> V_20 , V_29 ) ;
} else {
if ( ! V_29 )
F_9 ( V_5 -> V_37 , 1 ) ;
else
F_9 ( V_5 -> V_37 , 0 ) ;
}
}
static void F_10 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_38 * V_39 = & V_5 -> V_8 -> V_40 ;
if ( V_5 -> V_41 ) {
if ( V_5 -> V_42 == V_43 ) {
F_11 ( V_5 -> V_41 ) ;
V_5 -> V_42 = V_44 ;
} else {
if ( ! V_5 -> V_45 )
F_8 ( V_3 , V_7 -> V_46 ,
F_4 ( V_3 , V_7 -> V_46 ) &
~ V_39 -> V_47 ) ;
else
F_8 ( V_3 , V_7 -> V_48 ,
V_39 -> V_47 ) ;
}
} else {
if ( V_5 -> V_8 -> V_18 == V_49 )
F_8 ( V_3 , V_7 -> V_50 , F_4 ( V_3 ,
V_7 -> V_50 ) & ~ V_51 ) ;
if ( ! V_5 -> V_45 )
F_8 ( V_3 , V_7 -> V_46 ,
F_4 ( V_3 , V_7 -> V_46 ) &
~ V_39 -> V_47 ) ;
else
F_8 ( V_3 , V_7 -> V_48 ,
V_39 -> V_47 ) ;
}
}
static void F_12 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = & V_5 -> V_3 ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_38 * V_39 = & V_5 -> V_8 -> V_40 ;
struct V_52 * V_53 = & V_3 -> V_54 -> V_53 ;
unsigned long V_55 ;
unsigned long V_56 ;
unsigned long V_57 ;
V_55 = F_13 ( V_53 -> V_58 , V_53 -> V_59 , V_60 ) ;
V_56 = ( unsigned long ) ( V_53 -> V_61 + V_53 -> V_59 ) ;
if ( F_14 ( V_53 ) || F_15 ( V_3 ) ||
! V_55 )
return;
if ( V_5 -> V_42 == V_44 ) {
F_16 ( V_5 -> V_41 ) ;
return;
}
if ( V_5 -> V_42 == V_43 )
return;
if ( ! V_5 -> V_45 )
F_8 ( V_3 , V_7 -> V_46 ,
F_4 ( V_3 , V_7 -> V_46 ) &
~ ( V_39 -> V_47 ) ) ;
else
F_8 ( V_3 , V_7 -> V_48 ,
V_39 -> V_47 ) ;
if ( V_55 < 4 || F_17 ( V_56 ) ) {
F_8 ( V_3 , V_7 -> V_62 , V_63 ) ;
F_8 ( V_3 , V_7 -> V_64 ,
F_4 ( V_3 , V_7 -> V_64 ) |
V_65 ) ;
if ( F_17 ( V_56 ) ) {
V_57 = F_18 ( V_5 ,
F_17 ( V_56 ) ) ;
V_55 -= V_57 ;
}
if ( V_55 < 4 )
F_18 ( V_5 , V_55 ) ;
if ( ! V_5 -> V_45 )
F_8 ( V_3 , V_7 -> V_46 ,
F_4 ( V_3 , V_7 -> V_46 ) |
V_39 -> V_47 ) ;
else
F_8 ( V_3 , V_7 -> V_46 ,
V_39 -> V_47 ) ;
F_8 ( V_3 , V_7 -> V_62 , V_66 ) ;
} else {
F_8 ( V_3 , V_7 -> V_62 , V_63 ) ;
F_8 ( V_3 , V_7 -> V_64 ,
F_4 ( V_3 , V_7 -> V_64 ) &
~ V_65 ) ;
F_8 ( V_3 , V_7 -> V_62 , V_66 ) ;
V_55 &= ~ ( 0x3 ) ;
V_5 -> V_67 = F_19 ( V_3 -> V_68 ,
V_53 -> V_61 + V_53 -> V_59 ,
V_55 , V_69 ) ;
V_5 -> V_70 = F_20 (
V_5 -> V_41 , V_5 -> V_67 ,
V_55 , V_71 , V_72 ) ;
if ( ! V_5 -> V_70 ) {
F_21 ( V_3 -> V_68 , L_1 ) ;
return;
}
V_5 -> V_70 -> V_73 =
V_74 ;
V_5 -> V_70 -> V_75 = ( void * ) V_5 ;
V_5 -> V_76 = V_55 ;
F_22 ( V_5 -> V_70 ) ;
F_23 ( V_5 -> V_41 ) ;
V_5 -> V_42 = V_43 ;
}
}
static void F_24 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_38 * V_39 = & V_5 -> V_8 -> V_40 ;
if ( V_5 -> V_41 )
F_12 ( V_5 ) ;
else {
if ( V_5 -> V_8 -> V_18 == V_49 )
F_8 ( V_3 , V_7 -> V_50 , F_4 ( V_3 ,
V_7 -> V_50 ) | V_51 ) ;
F_8 ( V_3 , V_7 -> V_62 , V_63 ) ;
F_18 ( V_5 , V_3 -> V_77 ) ;
F_8 ( V_3 , V_7 -> V_62 , V_66 ) ;
if ( ! V_5 -> V_45 )
F_8 ( V_3 , V_7 -> V_46 ,
F_4 ( V_3 , V_7 -> V_46 ) |
V_39 -> V_47 ) ;
else
F_8 ( V_3 , V_7 -> V_46 ,
V_39 -> V_47 ) ;
}
}
static void F_25 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_38 * V_39 = & V_5 -> V_8 -> V_40 ;
F_8 ( V_3 , V_7 -> V_78 , 0 ) ;
if ( V_5 -> V_79 ) {
if ( ! V_5 -> V_45 )
F_8 ( V_3 , V_7 -> V_46 ,
F_4 ( V_3 , V_7 -> V_46 ) &
~ ( F_26 ( V_39 ,
V_5 -> V_8 -> V_18 ) |
V_39 -> V_80 ) ) ;
else
F_8 ( V_3 , V_7 -> V_48 ,
F_26 ( V_39 ,
V_5 -> V_8 -> V_18 ) |
V_39 -> V_80 ) ;
F_27 ( V_5 -> V_79 ) ;
} else {
if ( ! V_5 -> V_45 )
F_8 ( V_3 , V_7 -> V_46 ,
F_4 ( V_3 , V_7 -> V_46 ) &
~ ( F_28 ( V_39 ,
V_5 -> V_8 -> V_18 ) ) ) ;
else
F_8 ( V_3 , V_7 -> V_48 ,
F_28 ( V_39 ,
V_5 -> V_8 -> V_18 ) ) ;
}
}
static void F_29 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_38 * V_39 = & V_5 -> V_8 -> V_40 ;
if ( ! V_5 -> V_15 )
return;
V_5 -> V_16 = false ;
if ( V_5 -> V_8 -> V_18 == V_19 ) {
F_8 ( V_3 , V_7 -> V_20 ,
F_4 ( V_3 , V_7 -> V_20 ) & ~ 0x3FF ) ;
if ( ! V_5 -> V_45 )
F_8 ( V_3 , V_7 -> V_46 ,
F_4 ( V_3 , V_7 -> V_46 ) &
~ V_39 -> V_81 ) ;
else
F_8 ( V_3 , V_7 -> V_48 ,
V_39 -> V_81 ) ;
} else
F_30 ( F_31 ( V_5 -> V_23 ) ) ;
}
static T_1 F_32 ( int V_82 , void * V_83 )
{
struct V_1 * V_5 = (struct V_1 * ) V_83 ;
struct V_2 * V_3 = & V_5 -> V_3 ;
F_33 ( & V_3 -> V_84 ) ;
if ( F_34 ( V_5 -> V_23 ) && V_5 -> V_16 )
F_35 ( V_3 ,
! F_6 ( V_5 -> V_23 ) ) ;
F_36 ( & V_3 -> V_84 ) ;
return V_85 ;
}
static void F_37 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_38 * V_39 = & V_5 -> V_8 -> V_40 ;
if ( ! V_5 -> V_15 )
return;
V_5 -> V_16 = true ;
if ( V_5 -> V_8 -> V_18 == V_19 ) {
F_8 ( V_3 , V_7 -> V_20 ,
F_4 ( V_3 , V_7 -> V_20 ) |
V_86 | V_87 |
V_30 ) ;
if ( ! V_5 -> V_45 )
F_8 ( V_3 , V_7 -> V_46 ,
F_4 ( V_3 , V_7 -> V_46 )
| V_39 -> V_81 ) ;
else
F_8 ( V_3 , V_7 -> V_46 ,
V_39 -> V_81 ) ;
} else
F_38 ( F_31 ( V_5 -> V_23 ) ) ;
}
static void F_39 ( struct V_2 * V_3 , int V_88 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
if ( V_5 -> V_8 -> V_18 == V_19 ) {
unsigned long V_89 = F_4 ( V_3 , V_7 -> V_33 ) ;
if ( V_88 )
V_89 |= V_90 ;
else
V_89 &= ~ V_90 ;
F_8 ( V_3 , V_7 -> V_33 , V_89 ) ;
}
}
static unsigned int
F_40 ( struct V_2 * V_3 , unsigned int V_91 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_9 * V_10 = & V_5 -> V_8 -> V_11 ;
unsigned int V_92 , V_93 = 0 ;
struct V_94 * V_95 ;
V_95 = F_41 ( & V_3 -> V_54 -> V_3 ) ;
if ( ! V_95 )
return - V_96 ;
while ( ! ( F_4 ( V_3 , V_7 -> V_97 ) &
V_10 -> V_13 ( V_3 ) ) ) {
V_92 = F_4 ( V_3 , V_7 -> V_98 ) |
V_99 ;
if ( F_42 ( F_43 ( V_3 , V_92 ) ) )
continue;
F_44 ( V_3 , 0 , 0 , V_92 , V_100 ) ;
V_93 ++ ;
if ( V_93 >= V_91 )
break;
}
V_5 -> V_101 += V_93 ;
V_3 -> V_102 . V_103 += V_93 ;
return V_93 ;
}
static unsigned int
F_18 ( struct V_1 * V_5 , int V_104 )
{
struct V_2 * V_3 = & V_5 -> V_3 ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_9 * V_10 = & V_5 -> V_8 -> V_11 ;
struct V_52 * V_53 = & V_3 -> V_54 -> V_53 ;
unsigned int V_105 = 0 ;
while ( ! F_14 ( V_53 ) &&
! ( F_4 ( V_3 , V_7 -> V_12 ) &
V_10 -> V_106 ( V_3 ) ) &&
V_104 -- ) {
F_8 ( V_3 , V_7 -> V_107 ,
V_53 -> V_61 [ V_53 -> V_59 ] ) ;
V_53 -> V_59 = ( V_53 -> V_59 + 1 ) & ( V_60 - 1 ) ;
V_3 -> V_102 . V_108 ++ ;
V_105 ++ ;
}
if ( F_45 ( V_53 ) < V_109 )
F_46 ( V_3 ) ;
return V_105 ;
}
static void V_74 ( void * V_110 )
{
struct V_1 * V_5 = (struct V_1 * ) V_110 ;
struct V_2 * V_3 = & V_5 -> V_3 ;
struct V_52 * V_53 = & V_3 -> V_54 -> V_53 ;
unsigned long V_111 ;
F_47 ( & V_3 -> V_84 , V_111 ) ;
V_53 -> V_59 = ( V_53 -> V_59 + V_5 -> V_76 ) &
( V_60 - 1 ) ;
V_3 -> V_102 . V_108 += V_5 -> V_76 ;
if ( F_45 ( V_53 ) < V_109 )
F_46 ( V_3 ) ;
if ( V_5 -> V_67 )
F_48 ( V_3 -> V_68 , V_5 -> V_67 ,
V_5 -> V_76 , V_69 ) ;
V_5 -> V_42 = V_112 ;
F_12 ( V_5 ) ;
F_49 ( & V_3 -> V_84 , V_111 ) ;
}
static T_1 F_50 ( int V_82 , void * V_83 )
{
unsigned long V_113 ;
unsigned long V_114 ;
unsigned long V_115 = V_100 ;
struct V_1 * V_5 = (struct V_1 * ) V_83 ;
struct V_2 * V_3 = & V_5 -> V_3 ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_9 * V_10 = & V_5 -> V_8 -> V_11 ;
struct V_116 * V_117 = & V_5 -> V_8 -> V_118 ;
struct V_38 * V_39 = & V_5 -> V_8 -> V_40 ;
struct V_119 * V_54 = V_3 -> V_54 ;
struct V_52 * V_53 = & V_3 -> V_54 -> V_53 ;
F_33 ( & V_3 -> V_84 ) ;
V_113 = F_4 ( V_3 , V_7 -> V_120 ) ;
F_8 ( V_3 , V_7 -> V_120 , V_113 ) ;
V_113 &= F_4 ( V_3 , V_7 -> V_46 ) ;
if ( F_42 ( V_113 & ( F_51 ( V_117 ,
V_5 -> V_8 -> V_18 ) ) ) ) {
if ( V_113 & V_117 -> V_121 ) {
V_3 -> V_102 . V_122 ++ ;
if ( F_52 ( V_3 ) )
goto V_123;
}
if ( V_113 & V_117 -> V_124 ) {
V_3 -> V_102 . V_125 ++ ;
V_115 = V_126 ;
}
if ( V_113 & V_117 -> V_127 ) {
V_3 -> V_102 . V_128 ++ ;
V_115 = V_129 ;
}
if ( V_113 & V_117 -> V_130 ) {
V_3 -> V_102 . V_131 ++ ;
V_115 = V_132 ;
}
F_8 ( V_3 , V_7 -> V_78 , V_133 ) ;
F_8 ( V_3 , V_7 -> V_78 , 0 ) ;
F_8 ( V_3 , V_7 -> V_78 , V_66 ) ;
V_113 &= V_3 -> V_134 ;
F_44 ( V_3 , V_113 ,
V_39 -> V_135 , 0 , V_115 ) ;
}
V_123:
if ( ( V_5 -> V_8 -> V_18 == V_19 ) &&
( V_113 & F_53 ( V_117 ) ) &&
! V_5 -> V_42 ) {
V_114 = F_4 ( V_3 , V_7 -> V_20 ) &
V_21 ;
if ( V_114 != 0 )
V_114 = 0 ;
else
V_114 = 1 ;
F_35 ( V_3 , V_114 ) ;
F_54 ( & V_54 -> V_3 . V_136 ) ;
}
if ( ! V_5 -> V_79 &&
( V_113 & F_55 ( V_117 ) ) ) {
if ( V_113 & V_117 -> V_137 ) {
if ( ! V_5 -> V_45 ) {
F_8 ( V_3 , V_7 -> V_46 ,
F_4 ( V_3 , V_7 -> V_46 )
& ~ ( V_39 -> V_80 ) ) ;
F_8 ( V_3 , V_7 -> V_46 ,
F_4 ( V_3 , V_7 -> V_46 )
| ( V_39 -> V_138 ) ) ;
} else {
F_8 ( V_3 , V_7 -> V_48 ,
V_39 -> V_80 ) ;
F_8 ( V_3 , V_7 -> V_46 ,
V_39 -> V_138 ) ;
}
} else {
if ( V_113 & V_117 -> V_139 ) {
if ( ! V_5 -> V_45 ) {
F_8 ( V_3 , V_7 -> V_46 ,
F_4 ( V_3 , V_7 -> V_46 )
& ~ ( V_39 -> V_138 ) ) ;
F_8 ( V_3 , V_7 -> V_46 ,
F_4 ( V_3 , V_7 -> V_46 )
| ( V_39 -> V_80 ) ) ;
} else {
F_8 ( V_3 ,
V_7 -> V_48 ,
V_39 -> V_138 ) ;
F_8 ( V_3 , V_7 -> V_46 ,
V_39 -> V_80 ) ;
}
}
F_40 ( V_3 , V_3 -> V_77 ) ;
}
}
F_36 ( & V_3 -> V_84 ) ;
F_56 ( & V_54 -> V_3 ) ;
F_33 ( & V_3 -> V_84 ) ;
if ( V_113 & V_117 -> V_140 ) {
if ( V_5 -> V_41 )
F_12 ( V_5 ) ;
else {
if ( F_14 ( V_53 ) || F_15 ( V_3 ) ) {
F_36 ( & V_3 -> V_84 ) ;
return V_85 ;
} else {
F_18 ( V_5 ,
V_3 -> V_77 ) ;
if ( ( F_14 ( V_53 ) ) &&
( F_4 ( V_3 , V_7 -> V_12 ) &
V_10 -> V_13 ( V_3 ) ) )
F_10 ( V_3 ) ;
}
}
}
F_36 ( & V_3 -> V_84 ) ;
return V_85 ;
}
static void F_57 ( void * V_110 )
{
}
static void F_58 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_38 * V_39 = & V_5 -> V_8 -> V_40 ;
V_5 -> V_101 = 0 ;
F_8 ( V_3 , V_7 -> V_141 ,
F_4 ( V_3 , V_7 -> V_141 ) &
~ V_65 ) ;
V_5 -> V_142 . V_53 . V_59 =
V_5 -> V_142 . V_53 . V_58 = 0 ;
V_5 -> V_142 . V_143 =
F_59 ( V_5 -> V_79 ,
V_5 -> V_142 . V_144 , V_145 ,
V_145 / 2 ,
V_146 , V_72 ) ;
if ( F_60 ( V_5 -> V_142 . V_143 ) ) {
F_21 ( V_3 -> V_68 , L_2 ) ;
return;
}
V_5 -> V_142 . V_143 -> V_73 =
F_57 ;
V_5 -> V_142 . V_143 -> V_75 = V_5 ;
V_5 -> V_142 . V_147 =
F_22 ( V_5 -> V_142 . V_143 ) ;
F_23 ( V_5 -> V_79 ) ;
if ( ! V_5 -> V_45 )
F_8 ( V_3 , V_7 -> V_46 ,
F_4 ( V_3 , V_7 -> V_46 ) |
F_26 ( V_39 ,
V_5 -> V_8 -> V_18 ) ) ;
else
F_8 ( V_3 , V_7 -> V_46 ,
F_26 ( V_39 ,
V_5 -> V_8 -> V_18 ) ) ;
}
static void F_61 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_38 * V_39 = & V_5 -> V_8 -> V_40 ;
V_5 -> V_101 = 0 ;
F_8 ( V_3 , V_7 -> V_78 , V_133 ) ;
F_8 ( V_3 , V_7 -> V_78 , 0 ) ;
F_8 ( V_3 , V_7 -> V_78 , V_66 ) ;
if ( V_5 -> V_79 )
F_58 ( V_3 ) ;
else {
if ( ! V_5 -> V_45 )
F_8 ( V_3 , V_7 -> V_46 ,
F_4 ( V_3 , V_7 -> V_46 ) |
F_28 ( V_39 ,
V_5 -> V_8 -> V_18 ) ) ;
else
F_8 ( V_3 , V_7 -> V_46 ,
F_28 ( V_39 ,
V_5 -> V_8 -> V_18 ) ) ;
}
}
static unsigned int
F_62 ( unsigned long V_148 ,
unsigned long V_149 , unsigned long * V_150 )
{
unsigned long V_151 = ~ 0UL ;
unsigned short V_152 ;
unsigned long V_153 = 0 ;
unsigned long V_154 ;
for ( V_152 = V_155 ;
V_152 <= V_156 ; V_152 ++ ) {
V_154 = V_149 -
( V_149 + ( V_148 * V_152 ) / 2 )
/ ( V_148 * V_152 ) * V_148 * V_152 ;
V_154 = ( V_154 > 0 ) ? V_154 : - V_154 ;
if ( V_154 < V_151 ) {
V_153 = ( 2 * V_149 /
( V_148 * V_152 ) + 1 ) / 2 - 1 ;
if ( V_153 > V_157 )
continue;
V_151 = V_154 ;
* V_150 = V_152 ;
if ( ! V_154 )
break;
}
}
return V_153 ;
}
static unsigned int
F_63 ( unsigned long V_158 ,
unsigned long V_149 , unsigned long * V_159 )
{
unsigned long V_151 = ~ 0UL ;
unsigned short V_152 ;
unsigned int V_160 = 0 ;
unsigned long V_153 ;
unsigned long V_161 ;
int V_154 ;
for ( V_152 = V_162 ;
V_152 <= V_156 ; V_152 ++ ) {
V_153 = ( V_149 / ( V_158 * ( V_152 + 1 ) ) ) - 1 ;
if ( V_153 > V_157 )
continue;
V_161 = V_149 / ( ( V_153 + 1 ) * ( V_152 + 1 ) ) ;
V_154 = V_161 - V_158 ;
V_154 = ( V_154 > 0 ) ? V_154 : - V_154 ;
if ( V_154 < V_151 ) {
V_160 = V_160 & ( ~ V_163 ) ;
V_160 = V_160 | V_153 ;
V_160 = V_160 & ( ~ V_164 ) ;
V_160 = V_160 | ( V_152 << V_165 ) ;
V_151 = V_154 ;
* V_159 = V_161 ;
}
}
return V_160 ;
}
static void F_64 ( struct V_2 * V_3 ,
struct V_166 * V_167 ,
struct V_166 * V_168 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_38 * V_39 = & V_5 -> V_8 -> V_40 ;
unsigned long V_169 = 0 ;
unsigned long V_158 ;
unsigned long V_159 ;
unsigned long V_111 ;
unsigned long V_170 ;
unsigned int V_171 = 0 ;
unsigned long V_172 , V_149 ;
unsigned long V_173 ;
int V_174 ;
T_2 V_175 , V_176 , V_177 ;
unsigned long V_178 = 0xf ;
V_149 = V_3 -> V_179 ;
switch ( V_167 -> V_180 & V_181 ) {
default:
case V_182 :
V_175 = 8 ;
V_169 |= V_183 ;
break;
case V_184 :
V_175 = 7 ;
V_169 |= V_185 ;
break;
case V_186 :
V_175 = 6 ;
V_169 |= V_187 ;
break;
case V_188 :
V_175 = 5 ;
V_169 |= V_189 ;
break;
}
if ( V_167 -> V_180 & V_190 ) {
V_169 |= V_191 ;
V_176 = 2 ;
} else
V_176 = 1 ;
F_47 ( & V_3 -> V_84 , V_111 ) ;
V_3 -> V_134 = V_39 -> V_135 ;
V_3 -> V_192 = 0 ;
if ( V_5 -> V_8 -> V_18 == V_19 ) {
if ( V_167 -> V_193 & V_194 )
V_3 -> V_134 |= V_39 -> V_195 |
V_39 -> V_196 ;
} else {
if ( V_167 -> V_193 & V_194 )
V_3 -> V_134 |= V_39 -> V_195 ;
}
if ( V_167 -> V_193 & ( V_197 | V_198 | V_199 ) )
V_3 -> V_134 |= V_39 -> V_200 ;
if ( V_5 -> V_8 -> V_18 == V_19 ) {
if ( V_167 -> V_193 & V_201 )
V_3 -> V_192 |=
V_39 -> V_195 |
V_39 -> V_196 ;
if ( V_167 -> V_180 & V_202 ) {
if ( V_167 -> V_180 & V_203 ) {
if ( V_167 -> V_180 & V_204 )
V_169 |= V_205 ;
else
V_169 |= V_206 ;
} else {
if ( V_167 -> V_180 & V_204 )
V_169 |= V_207 ;
else
V_169 |= V_208 ;
}
}
} else {
if ( V_167 -> V_193 & V_201 )
V_3 -> V_192 |=
V_39 -> V_195 ;
if ( V_167 -> V_180 & V_202 )
F_65 ( V_3 -> V_68 ,
L_3 ) ;
}
if ( V_167 -> V_193 & V_197 ) {
V_3 -> V_192 |=
V_39 -> V_200 ;
if ( V_167 -> V_193 & V_201 )
V_3 -> V_192 |=
V_39 -> V_135 ;
}
if ( ( V_167 -> V_180 & V_209 ) == 0 )
V_3 -> V_192 |= V_99 ;
if ( F_66 ( V_3 , V_167 -> V_180 ) ) {
if ( ! V_5 -> V_16 )
F_37 ( V_3 ) ;
} else {
if ( V_5 -> V_16 )
F_29 ( V_3 ) ;
}
V_158 = F_67 ( V_3 , V_167 , V_168 , 0 , 4000000 ) ;
if ( V_149 == 150000000 ) {
for ( V_170 = 0 ; V_170 < V_210 ; V_170 ++ )
if ( V_158 == V_211 [ V_170 ] . V_158 )
V_171 = V_211 [ V_170 ] . V_212 ;
}
V_159 = V_158 ;
if ( V_5 -> V_8 -> V_18 == V_19 ) {
if ( F_42 ( V_171 == 0 ) )
V_171 = F_63 ( V_158 ,
V_149 , & V_159 ) ;
F_8 ( V_3 , V_7 -> V_213 , V_171 ) ;
} else {
V_171 = F_62 ( V_158 ,
V_149 , & V_178 ) ;
V_178 -- ;
V_159 = ( ( V_149 / ( V_171 + 1 ) - 1 ) /
( V_178 + 1 ) ) ;
V_177 = ( ( 1 << V_214 ) |
( 1 << V_215 ) ) ;
V_177 |= ( ( V_171 & V_216 )
<< V_217 ) ;
F_8 ( V_3 , V_7 -> V_218 , V_177 ) ;
}
if ( F_68 ( V_167 ) )
F_69 ( V_167 , V_159 , V_159 ) ;
V_173 = F_70 ( V_159 , 20000 ) ;
V_173 = F_71 ( V_173 ) ;
V_172 = F_4 ( V_3 , V_7 -> V_62 ) ;
F_8 ( V_3 , V_7 -> V_78 , V_63 ) ;
F_8 ( V_3 , V_7 -> V_62 ,
( V_172 & ~ V_66 ) ) ;
if ( V_5 -> V_8 -> V_18 == V_19 ) {
V_169 |= F_72 ( V_173 ) ;
F_8 ( V_3 , V_7 -> V_33 , V_169 ) ;
} else {
V_177 = ( V_175 - 1 ) << V_219 ;
V_177 |= ( V_175 + 1 + V_176 - 1 ) <<
V_220 ;
V_177 |= ( ( V_175 - 1 ) <<
V_221 ) ;
V_177 |= ( ( ( V_171 & 0xc00 ) >> 10 ) <<
V_222 ) ;
F_8 ( V_3 , V_7 -> V_223 , V_177 ) ;
V_177 = ( V_175 - 1 ) << V_224 ;
V_177 |= ( V_175 + 1 + V_176 - 1 ) <<
V_225 ;
V_177 |= ( V_175 - 1 ) <<
V_226 ;
V_177 |= ( ( ( V_171 & 0xf000 ) >> 12 ) <<
V_227 ) ;
F_8 ( V_3 , V_7 -> V_228 , V_177 ) ;
F_8 ( V_3 , V_7 -> V_229 ,
( F_73 ( V_173 ) ) |
( V_178 & V_230 ) <<
V_231 ) ;
}
if ( V_5 -> V_41 )
F_8 ( V_3 , V_7 -> V_64 , V_232 ) ;
else
F_8 ( V_3 , V_7 -> V_64 , V_65 ) ;
if ( V_5 -> V_79 )
F_8 ( V_3 , V_7 -> V_141 , V_232 ) ;
else
F_8 ( V_3 , V_7 -> V_141 , V_65 ) ;
V_5 -> V_233 = 20000000 ;
if ( V_159 < 1000000 )
V_174 = 1 ;
else
V_174 = 2 ;
F_8 ( V_3 , V_7 -> V_234 ,
F_74 ( V_3 ) / V_174 ) ;
F_8 ( V_3 , V_7 -> V_235 ,
F_74 ( V_3 ) / V_174 ) ;
V_172 |= V_66 ;
F_8 ( V_3 , V_7 -> V_62 , V_172 ) ;
F_75 ( V_3 , V_167 -> V_180 , V_159 ) ;
F_61 ( V_3 ) ;
F_8 ( V_3 , V_7 -> V_50 , V_51 | V_236 ) ;
F_49 ( & V_3 -> V_84 , V_111 ) ;
}
static void F_76 ( struct V_2 * V_3 , unsigned int V_54 ,
unsigned int V_237 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( ! V_54 )
F_77 ( V_5 -> V_238 ) ;
else
F_78 ( V_5 -> V_238 ) ;
}
static int F_79 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
unsigned int V_239 = V_3 -> line ;
int V_240 ;
F_80 ( V_3 -> V_82 , V_241 , V_242 ) ;
V_240 = F_81 ( V_3 -> V_82 ,
F_50 ,
0 ,
V_243 ,
V_5 ) ;
if ( V_240 != 0 ) {
F_21 ( V_3 -> V_68 , L_4 ,
V_239 , V_3 -> V_82 ) ;
goto V_244;
}
F_8 ( V_3 , V_7 -> V_64 ,
F_4 ( V_3 , V_7 -> V_64 ) |
V_65 ) ;
F_8 ( V_3 , V_7 -> V_141 ,
F_4 ( V_3 , V_7 -> V_141 ) |
V_65 ) ;
F_8 ( V_3 , V_7 -> V_141 ,
F_4 ( V_3 , V_7 -> V_141 ) &
~ V_245 ) ;
F_8 ( V_3 , V_7 -> V_246 , 0 ) ;
F_8 ( V_3 , V_7 -> V_247 , 0 ) ;
F_8 ( V_3 , V_7 -> V_50 , V_236 | V_51 ) ;
if ( V_5 -> V_8 -> V_18 == V_49 )
F_8 ( V_3 , V_7 -> V_35 ,
V_248 |
V_249 ) ;
F_8 ( V_3 , V_7 -> V_62 , V_133 ) ;
F_8 ( V_3 , V_7 -> V_78 , V_133 ) ;
F_8 ( V_3 , V_7 -> V_78 , 0 ) ;
F_8 ( V_3 , V_7 -> V_234 , F_74 ( V_3 ) ) ;
F_8 ( V_3 , V_7 -> V_235 , F_74 ( V_3 ) ) ;
if ( V_5 -> V_79 )
F_8 ( V_3 , V_7 -> V_250 ,
F_82 ( V_3 -> line , 0x4 ) |
F_83 ( V_3 -> line , 0xe ) |
F_84 ( V_3 -> line , 0x1b ) ) ;
if ( V_5 -> V_41 ) {
V_5 -> V_42 = V_112 ;
F_8 ( V_3 , V_7 -> V_251 ,
F_85 ( V_3 -> line , 0x1b ) |
F_86 ( V_3 -> line , 0xe ) |
F_87 ( V_3 -> line , 0x4 ) ) ;
}
V_5 -> V_16 = false ;
if ( V_5 -> V_8 -> V_18 == V_49 &&
V_5 -> V_15 ) {
F_80 ( F_31 ( V_5 -> V_23 ) ,
V_241 , V_242 ) ;
V_240 = F_81 ( F_31 ( V_5 -> V_23 ) ,
F_32 , V_252 |
V_253 , L_5 , V_5 ) ;
if ( V_240 != 0 ) {
F_21 ( V_3 -> V_68 , L_6 ) ;
goto V_254;
}
}
F_38 ( V_3 -> V_82 ) ;
if ( V_5 -> V_79 && ! V_5 -> V_255 ) {
V_5 -> V_255 = true ;
V_5 -> V_233 = 20000000 ;
V_5 -> V_142 . V_53 . V_59 =
V_5 -> V_142 . V_53 . V_58 = 0 ;
F_88 ( & V_5 -> V_256 ,
F_89 ( V_5 -> V_233 ) ,
V_257 ) ;
}
return 0 ;
V_254:
F_90 ( V_3 -> V_82 , V_5 ) ;
V_244:
return V_240 ;
}
static void F_91 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
if ( ! V_5 -> V_45 )
F_8 ( V_3 , V_7 -> V_46 , 0 ) ;
else
F_8 ( V_3 , V_7 -> V_48 , ~ 0UL ) ;
F_90 ( V_3 -> V_82 , V_5 ) ;
if ( V_5 -> V_16 )
F_29 ( V_3 ) ;
if ( V_5 -> V_8 -> V_18 == V_49 &&
V_5 -> V_15 ) {
F_9 ( V_5 -> V_37 , 1 ) ;
F_90 ( F_31 ( V_5 -> V_23 ) , V_5 ) ;
}
if ( V_5 -> V_41 )
V_5 -> V_42 = V_112 ;
if ( V_5 -> V_79 && V_5 -> V_255 ) {
while ( ( F_4 ( V_3 , V_7 -> V_97 ) &
V_258 ) > 0 )
;
V_5 -> V_255 = false ;
F_92 ( & V_5 -> V_256 ) ;
}
}
static const char * F_93 ( struct V_2 * V_3 )
{
return V_3 -> type == V_259 ? V_243 : NULL ;
}
static int F_94 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_260 * V_261 = & V_5 -> V_8 -> V_261 ;
void * V_240 ;
V_240 = F_95 ( V_3 -> V_262 ,
V_263 , V_261 -> V_264 ) ;
return V_240 ? 0 : - V_265 ;
}
static void F_96 ( struct V_2 * V_3 )
{
F_97 ( V_3 -> V_262 , V_263 ) ;
}
static void F_98 ( struct V_2 * V_3 , int V_111 )
{
if ( V_111 & V_266 ) {
V_3 -> type = V_259 ;
F_94 ( V_3 ) ;
}
}
static int T_3
F_99 ( struct V_267 * V_268 , char * V_269 )
{
unsigned int V_270 = 115200 ;
unsigned int V_271 = 8 ;
unsigned int V_131 = 'n' ;
unsigned int V_272 = 'n' ;
struct V_1 * V_5 ;
struct V_6 * V_7 ;
if ( V_268 -> V_239 < 0 || V_268 -> V_239 >= V_273 )
V_268 -> V_239 = 1 ;
V_5 = V_274 [ V_268 -> V_239 ] ;
if ( ! V_5 )
return - V_96 ;
V_7 = & V_5 -> V_8 -> V_8 ;
if ( ! V_5 -> V_3 . V_262 )
return - V_96 ;
if ( V_5 -> V_8 -> V_18 == V_49 )
F_8 ( & V_5 -> V_3 , V_7 -> V_35 , V_249 |
V_248 ) ;
if ( V_269 )
F_100 ( V_269 , & V_270 , & V_131 , & V_271 , & V_272 ) ;
V_5 -> V_3 . V_275 = V_268 ;
V_5 -> V_79 = NULL ;
V_5 -> V_41 = NULL ;
return F_101 ( & V_5 -> V_3 , V_268 , V_270 , V_131 , V_271 , V_272 ) ;
}
static void F_102 ( struct V_2 * V_3 , int V_92 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_8 ;
struct V_9 * V_10 = & V_5 -> V_8 -> V_11 ;
while ( F_4 ( V_3 , V_7 -> V_12 ) &
V_10 -> V_106 ( V_3 ) )
F_103 () ;
F_8 ( V_3 , V_7 -> V_107 , V_92 ) ;
}
static void F_104 ( struct V_267 * V_268 , const char * V_276 ,
unsigned int V_104 )
{
struct V_1 * V_5 = V_274 [ V_268 -> V_239 ] ;
F_105 ( & V_5 -> V_3 , V_276 , V_104 ,
F_102 ) ;
}
static int T_3 F_106 ( void )
{
F_107 ( & V_277 ) ;
return 0 ;
}
static enum V_278
F_108 ( struct V_279 * V_256 )
{
struct V_1 * V_5 ;
struct V_2 * V_3 ;
int V_104 , V_280 ;
struct V_281 V_282 ;
struct V_94 * V_95 ;
struct V_6 * V_7 ;
struct V_52 * V_53 ;
V_5 = F_2 ( V_256 , struct V_1 , V_256 ) ;
V_3 = & V_5 -> V_3 ;
V_280 = 0 ;
V_95 = V_3 -> V_54 -> V_3 . V_95 ;
V_7 = & V_5 -> V_8 -> V_8 ;
V_53 = & V_5 -> V_142 . V_53 ;
F_109 ( V_5 -> V_79 ,
V_5 -> V_142 . V_147 , & V_282 ) ;
V_53 -> V_58 = V_145 - V_282 . V_283 ;
V_104 = F_13 ( V_53 -> V_58 , V_53 -> V_59 ,
V_145 ) ;
while ( V_104 > 0 ) {
V_280 = F_110 ( V_95 -> V_3 ,
( const unsigned char * ) & V_53 -> V_61 [ V_53 -> V_59 ] , V_104 ) ;
if ( ! V_280 )
goto V_284;
V_3 -> V_102 . V_103 += V_280 ;
V_53 -> V_59 = ( V_53 -> V_59 + V_280 ) &
( V_145 - 1 ) ;
V_104 = F_13 ( V_53 -> V_58 , V_53 -> V_59 ,
V_145 ) ;
F_56 ( V_95 -> V_3 ) ;
}
if ( ! V_280 && ! V_104 &&
( ( F_4 ( V_3 , V_7 -> V_97 ) &
V_258 ) > 0 ) ) {
F_8 ( V_3 , V_7 -> V_141 ,
F_4 ( V_3 , V_7 -> V_141 ) |
V_65 ) ;
while ( ( F_4 ( V_3 , V_7 -> V_97 ) &
V_258 ) > 0 ) {
if ( F_40 ( V_3 , 16 ) > 0 )
F_56 ( V_95 -> V_3 ) ;
}
F_8 ( V_3 , V_7 -> V_78 , V_133 ) ;
F_8 ( V_3 , V_7 -> V_78 , 0 ) ;
F_8 ( V_3 , V_7 -> V_78 , V_66 ) ;
F_8 ( V_3 , V_7 -> V_141 ,
F_4 ( V_3 , V_7 -> V_141 ) &
~ V_65 ) ;
}
V_284:
F_111 ( V_256 , F_89 ( V_5 -> V_233 ) ) ;
return V_285 ;
}
static int F_112 ( struct V_286 * V_287 )
{
struct V_1 * V_5 ;
struct V_2 * V_3 ;
struct V_288 * V_289 ;
int V_240 ;
struct V_290 V_291 = {
. V_292 = 2 ,
} ;
struct V_290 V_293 = {
. V_294 = 2 ,
} ;
const struct V_295 * V_296 ;
V_296 = F_113 ( V_297 , V_287 -> V_68 . V_298 ) ;
V_5 = F_114 ( & V_287 -> V_68 , sizeof( * V_5 ) , V_299 ) ;
if ( ! V_5 ) {
V_240 = - V_300 ;
goto V_301;
}
V_5 -> V_3 . line = F_115 ( V_287 -> V_68 . V_298 , L_7 ) ;
V_274 [ V_5 -> V_3 . line ] = V_5 ;
V_5 -> V_3 . V_302 = V_303 ;
V_5 -> V_3 . V_111 = V_304 ;
V_3 = & V_5 -> V_3 ;
V_3 -> V_68 = & V_287 -> V_68 ;
V_3 -> V_305 = V_5 ;
V_5 -> V_8 = (struct V_306 * ) V_296 -> V_307 ;
V_5 -> V_15 = F_116 ( V_287 -> V_68 . V_298 ,
L_8 ) ;
if ( F_117 ( V_287 -> V_68 . V_298 , L_9 ) ||
F_117 ( V_287 -> V_68 . V_298 , L_10 ) )
V_5 -> V_8 -> V_18 = V_19 ;
if ( F_117 ( V_287 -> V_68 . V_298 ,
L_11 ) || F_117 (
V_287 -> V_68 . V_298 , L_12 ) ) {
V_5 -> V_8 -> V_18 = V_49 ;
if ( ! V_5 -> V_15 )
goto V_308;
if ( F_118 ( V_287 -> V_68 . V_298 , L_13 , NULL ) )
V_5 -> V_23 = F_119 (
V_287 -> V_68 . V_298 , L_13 , 0 ) ;
else
V_5 -> V_23 = - 1 ;
if ( F_118 ( V_287 -> V_68 . V_298 , L_14 , NULL ) )
V_5 -> V_37 = F_119 (
V_287 -> V_68 . V_298 , L_14 , 0 ) ;
else
V_5 -> V_37 = - 1 ;
if ( ( ! F_34 ( V_5 -> V_23 ) ||
! F_34 ( V_5 -> V_37 ) ) ) {
V_240 = - V_309 ;
F_21 ( & V_287 -> V_68 ,
L_15 ) ;
goto V_301;
}
V_240 = F_120 ( & V_287 -> V_68 , V_5 -> V_23 ,
L_16 ) ;
if ( V_240 ) {
F_21 ( & V_287 -> V_68 , L_17 ) ;
goto V_301;
}
F_121 ( V_5 -> V_23 ) ;
V_240 = F_120 ( & V_287 -> V_68 , V_5 -> V_37 ,
L_18 ) ;
if ( V_240 ) {
F_21 ( & V_287 -> V_68 , L_19 ) ;
goto V_301;
}
F_122 ( V_5 -> V_37 , 1 ) ;
}
V_308:
if ( F_117 ( V_287 -> V_68 . V_298 , L_10 ) ||
F_117 ( V_287 -> V_68 . V_298 , L_12 ) )
V_5 -> V_45 = true ;
if ( F_123 ( V_287 -> V_68 . V_298 ,
L_20 ,
& V_3 -> V_77 ) ) {
F_21 ( & V_287 -> V_68 ,
L_21 ) ;
V_240 = - V_310 ;
goto V_301;
}
V_289 = F_124 ( V_287 , V_311 , 0 ) ;
if ( V_289 == NULL ) {
F_21 ( & V_287 -> V_68 , L_22 ) ;
V_240 = - V_310 ;
goto V_301;
}
V_3 -> V_262 = V_289 -> V_312 ;
V_3 -> V_313 = F_125 ( & V_287 -> V_68 ,
V_289 -> V_312 , F_126 ( V_289 ) ) ;
if ( ! V_3 -> V_313 ) {
F_21 ( & V_287 -> V_68 , L_23 ) ;
V_240 = - V_300 ;
goto V_301;
}
V_289 = F_124 ( V_287 , V_314 , 0 ) ;
if ( V_289 == NULL ) {
F_21 ( & V_287 -> V_68 , L_22 ) ;
V_240 = - V_310 ;
goto V_301;
}
V_3 -> V_82 = V_289 -> V_312 ;
V_5 -> V_238 = F_127 ( & V_287 -> V_68 , NULL ) ;
if ( F_128 ( V_5 -> V_238 ) ) {
V_240 = F_129 ( V_5 -> V_238 ) ;
goto V_301;
}
V_3 -> V_179 = F_130 ( V_5 -> V_238 ) ;
V_3 -> V_315 = & V_316 ;
F_131 ( & V_3 -> V_84 ) ;
F_132 ( V_287 , V_5 ) ;
V_240 = F_133 ( & V_317 , V_3 ) ;
if ( V_240 != 0 ) {
F_21 ( & V_287 -> V_68 , L_24 , V_287 -> V_318 ) ;
goto V_301;
}
V_5 -> V_79 = F_134 ( V_3 -> V_68 , L_25 ) ;
V_5 -> V_142 . V_53 . V_61 =
F_135 ( V_3 -> V_68 , V_145 ,
& V_5 -> V_142 . V_144 , V_299 ) ;
if ( ! V_5 -> V_142 . V_53 . V_61 ) {
F_21 ( V_3 -> V_68 , L_26 ) ;
V_240 = - V_300 ;
goto V_319;
}
V_5 -> V_142 . V_53 . V_58 =
V_5 -> V_142 . V_53 . V_59 = 0 ;
if ( V_5 -> V_79 )
F_136 ( V_5 -> V_79 , & V_291 ) ;
V_5 -> V_41 = F_134 ( V_3 -> V_68 , L_27 ) ;
if ( V_5 -> V_41 )
F_136 ( V_5 -> V_41 , & V_293 ) ;
if ( V_5 -> V_79 ) {
F_137 ( & V_5 -> V_256 , V_320 , V_257 ) ;
V_5 -> V_256 . V_321 = F_108 ;
V_5 -> V_255 = false ;
}
return 0 ;
V_319:
F_138 ( V_3 -> V_68 , V_145 ,
V_5 -> V_142 . V_53 . V_61 ,
V_5 -> V_142 . V_144 ) ;
F_139 ( V_5 -> V_79 ) ;
V_301:
return V_240 ;
}
static int F_140 ( struct V_286 * V_287 )
{
struct V_1 * V_5 = F_141 ( V_287 ) ;
struct V_2 * V_3 = & V_5 -> V_3 ;
F_142 ( & V_317 , V_3 ) ;
if ( V_5 -> V_79 ) {
F_27 ( V_5 -> V_79 ) ;
F_139 ( V_5 -> V_79 ) ;
F_138 ( V_3 -> V_68 , V_145 ,
V_5 -> V_142 . V_53 . V_61 ,
V_5 -> V_142 . V_144 ) ;
}
if ( V_5 -> V_41 ) {
F_27 ( V_5 -> V_41 ) ;
F_139 ( V_5 -> V_41 ) ;
}
return 0 ;
}
static int
F_143 ( struct V_322 * V_287 )
{
struct V_1 * V_5 = F_144 ( V_287 ) ;
struct V_2 * V_3 = & V_5 -> V_3 ;
F_145 ( & V_317 , V_3 ) ;
return 0 ;
}
static int F_146 ( struct V_322 * V_287 )
{
struct V_1 * V_5 = F_144 ( V_287 ) ;
struct V_2 * V_3 = & V_5 -> V_3 ;
F_147 ( & V_317 , V_3 ) ;
return 0 ;
}
static int T_3 F_148 ( void )
{
int V_240 = 0 ;
V_240 = F_149 ( & V_317 ) ;
if ( V_240 )
goto V_323;
V_240 = F_150 ( & V_324 ) ;
if ( V_240 )
F_151 ( & V_317 ) ;
V_323:
return V_240 ;
}
static void T_4 F_152 ( void )
{
F_153 ( & V_324 ) ;
F_151 ( & V_317 ) ;
}
