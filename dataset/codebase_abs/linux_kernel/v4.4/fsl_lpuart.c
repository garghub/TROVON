static T_1 F_1 ( void T_2 * V_1 )
{
return F_2 ( V_1 ) ;
}
static void F_3 ( T_1 V_2 , void T_2 * V_1 )
{
F_4 ( V_2 , V_1 ) ;
}
static void F_5 ( struct V_3 * V_4 )
{
unsigned char V_5 ;
V_5 = F_6 ( V_4 -> V_6 + V_7 ) ;
V_5 &= ~ ( V_8 | V_9 ) ;
F_7 ( V_5 , V_4 -> V_6 + V_7 ) ;
}
static void F_8 ( struct V_3 * V_4 )
{
unsigned long V_5 ;
V_5 = F_1 ( V_4 -> V_6 + V_10 ) ;
V_5 &= ~ ( V_11 | V_12 ) ;
F_3 ( V_5 , V_4 -> V_6 + V_10 ) ;
}
static void F_9 ( struct V_3 * V_4 )
{
unsigned char V_5 ;
V_5 = F_6 ( V_4 -> V_6 + V_7 ) ;
F_7 ( V_5 & ~ V_13 , V_4 -> V_6 + V_7 ) ;
}
static void F_10 ( struct V_3 * V_4 )
{
unsigned long V_5 ;
V_5 = F_1 ( V_4 -> V_6 + V_10 ) ;
F_3 ( V_5 & ~ V_14 , V_4 -> V_6 + V_10 ) ;
}
static void F_11 ( struct V_15 * V_16 ,
struct V_17 * V_18 , int V_19 )
{
int V_20 ;
V_16 -> V_4 . V_21 . V_22 += V_19 ;
if ( ! V_18 ) {
F_12 ( V_16 -> V_4 . V_23 , L_1 ) ;
return;
}
F_13 ( V_16 -> V_4 . V_23 , V_16 -> V_24 ,
V_25 , V_26 ) ;
V_20 = F_14 ( V_18 ,
( ( unsigned char * ) ( V_16 -> V_27 ) ) , V_19 ) ;
if ( V_20 != V_19 ) {
F_15 ( 1 ) ;
F_12 ( V_16 -> V_4 . V_23 , L_2 ) ;
}
F_16 ( V_16 -> V_4 . V_23 , V_16 -> V_24 ,
V_25 , V_28 ) ;
}
static void F_17 ( struct V_15 * V_16 )
{
struct V_29 * V_30 = & V_16 -> V_4 . V_31 -> V_30 ;
unsigned long V_32 ;
F_18 ( & V_16 -> V_4 . V_33 , V_32 ) ;
while ( ! F_19 ( V_30 ) &&
F_6 ( V_16 -> V_4 . V_6 + V_34 ) < V_16 -> V_35 ) {
F_7 ( V_30 -> V_36 [ V_30 -> V_37 ] , V_16 -> V_4 . V_6 + V_38 ) ;
V_30 -> V_37 = ( V_30 -> V_37 + 1 ) & ( V_39 - 1 ) ;
V_16 -> V_4 . V_21 . V_40 ++ ;
}
if ( F_20 ( V_30 ) < V_41 )
F_21 ( & V_16 -> V_4 ) ;
if ( F_19 ( V_30 ) )
F_7 ( F_6 ( V_16 -> V_4 . V_6 + V_42 ) | V_43 ,
V_16 -> V_4 . V_6 + V_42 ) ;
F_22 ( & V_16 -> V_4 . V_33 , V_32 ) ;
}
static int F_23 ( struct V_15 * V_16 , unsigned long V_19 )
{
struct V_29 * V_30 = & V_16 -> V_4 . V_31 -> V_30 ;
T_3 V_44 ;
F_16 ( V_16 -> V_4 . V_23 , V_16 -> V_45 ,
V_39 , V_28 ) ;
V_16 -> V_46 = V_19 & ~ ( V_16 -> V_35 - 1 ) ;
V_44 = V_16 -> V_45 + V_30 -> V_37 ;
V_16 -> V_47 = F_24 ( V_16 -> V_48 ,
V_44 , V_16 -> V_46 ,
V_49 , V_50 ) ;
if ( ! V_16 -> V_47 ) {
F_12 ( V_16 -> V_4 . V_23 , L_3 ) ;
return - V_51 ;
}
V_16 -> V_47 -> V_52 = V_53 ;
V_16 -> V_47 -> V_54 = V_16 ;
V_16 -> V_55 = 1 ;
V_16 -> V_56 = F_25 ( V_16 -> V_47 ) ;
F_26 ( V_16 -> V_48 ) ;
return 0 ;
}
static void F_27 ( struct V_15 * V_16 )
{
struct V_29 * V_30 = & V_16 -> V_4 . V_31 -> V_30 ;
unsigned long V_19 = F_28 ( V_30 -> V_57 ,
V_30 -> V_37 , V_39 ) ;
if ( ! V_19 )
return;
if ( V_19 < V_16 -> V_35 )
F_7 ( F_6 ( V_16 -> V_4 . V_6 + V_42 ) & ~ V_43 ,
V_16 -> V_4 . V_6 + V_42 ) ;
else {
F_7 ( F_6 ( V_16 -> V_4 . V_6 + V_42 ) | V_43 ,
V_16 -> V_4 . V_6 + V_42 ) ;
F_23 ( V_16 , V_19 ) ;
}
}
static void V_53 ( void * V_58 )
{
struct V_15 * V_16 = V_58 ;
struct V_29 * V_30 = & V_16 -> V_4 . V_31 -> V_30 ;
unsigned long V_32 ;
F_29 ( V_16 -> V_47 ) ;
F_18 ( & V_16 -> V_4 . V_33 , V_32 ) ;
V_30 -> V_37 = ( V_30 -> V_37 + V_16 -> V_46 ) & ( V_39 - 1 ) ;
V_16 -> V_55 = 0 ;
if ( F_20 ( V_30 ) < V_41 )
F_21 ( & V_16 -> V_4 ) ;
F_27 ( V_16 ) ;
F_22 ( & V_16 -> V_4 . V_33 , V_32 ) ;
}
static int F_30 ( struct V_15 * V_16 )
{
F_16 ( V_16 -> V_4 . V_23 , V_16 -> V_24 ,
V_25 , V_28 ) ;
V_16 -> V_59 = F_24 ( V_16 -> V_60 ,
V_16 -> V_24 , V_25 ,
V_61 , V_50 ) ;
if ( ! V_16 -> V_59 ) {
F_12 ( V_16 -> V_4 . V_23 , L_4 ) ;
return - V_51 ;
}
V_16 -> V_59 -> V_52 = V_62 ;
V_16 -> V_59 -> V_54 = V_16 ;
V_16 -> V_63 = 1 ;
V_16 -> V_64 = F_25 ( V_16 -> V_59 ) ;
F_26 ( V_16 -> V_60 ) ;
return 0 ;
}
static void F_31 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = F_32 ( V_4 , struct V_15 , V_4 ) ;
if ( V_16 -> V_65 ) {
F_33 ( V_16 -> V_48 ) ;
V_16 -> V_55 = 0 ;
}
}
static void V_62 ( void * V_58 )
{
struct V_15 * V_16 = V_58 ;
struct V_17 * V_4 = & V_16 -> V_4 . V_31 -> V_4 ;
unsigned long V_32 ;
F_29 ( V_16 -> V_59 ) ;
F_34 ( & V_16 -> V_66 , V_67 + V_16 -> V_68 ) ;
F_18 ( & V_16 -> V_4 . V_33 , V_32 ) ;
V_16 -> V_63 = 0 ;
F_11 ( V_16 , V_4 , V_25 ) ;
F_35 ( V_4 ) ;
F_30 ( V_16 ) ;
F_22 ( & V_16 -> V_4 . V_33 , V_32 ) ;
}
static void F_36 ( unsigned long V_69 )
{
struct V_15 * V_16 = (struct V_15 * ) V_69 ;
struct V_17 * V_4 = & V_16 -> V_4 . V_31 -> V_4 ;
struct V_70 V_31 ;
unsigned long V_32 ;
unsigned char V_5 ;
int V_19 ;
F_37 ( & V_16 -> V_66 ) ;
F_38 ( V_16 -> V_60 ) ;
F_39 ( V_16 -> V_60 , V_16 -> V_64 , & V_31 ) ;
F_33 ( V_16 -> V_60 ) ;
V_19 = V_25 - V_31 . V_71 ;
F_29 ( V_16 -> V_59 ) ;
F_18 ( & V_16 -> V_4 . V_33 , V_32 ) ;
V_16 -> V_63 = 0 ;
F_11 ( V_16 , V_4 , V_19 ) ;
F_35 ( V_4 ) ;
V_5 = F_6 ( V_16 -> V_4 . V_6 + V_42 ) ;
F_7 ( V_5 & ~ V_72 , V_16 -> V_4 . V_6 + V_42 ) ;
F_22 ( & V_16 -> V_4 . V_33 , V_32 ) ;
}
static inline void F_40 ( struct V_15 * V_16 )
{
unsigned long V_32 ;
unsigned char V_5 ;
F_18 ( & V_16 -> V_4 . V_33 , V_32 ) ;
V_16 -> V_66 . V_73 = V_67 + V_16 -> V_68 ;
F_41 ( & V_16 -> V_66 ) ;
F_30 ( V_16 ) ;
V_5 = F_6 ( V_16 -> V_4 . V_6 + V_42 ) ;
F_7 ( V_5 | V_72 , V_16 -> V_4 . V_6 + V_42 ) ;
F_22 ( & V_16 -> V_4 . V_33 , V_32 ) ;
}
static inline void F_42 ( struct V_15 * V_16 )
{
struct V_29 * V_30 = & V_16 -> V_4 . V_31 -> V_30 ;
while ( ! F_19 ( V_30 ) &&
( F_6 ( V_16 -> V_4 . V_6 + V_34 ) < V_16 -> V_35 ) ) {
F_7 ( V_30 -> V_36 [ V_30 -> V_37 ] , V_16 -> V_4 . V_6 + V_38 ) ;
V_30 -> V_37 = ( V_30 -> V_37 + 1 ) & ( V_39 - 1 ) ;
V_16 -> V_4 . V_21 . V_40 ++ ;
}
if ( F_20 ( V_30 ) < V_41 )
F_21 ( & V_16 -> V_4 ) ;
if ( F_19 ( V_30 ) )
F_5 ( & V_16 -> V_4 ) ;
}
static inline void F_43 ( struct V_15 * V_16 )
{
struct V_29 * V_30 = & V_16 -> V_4 . V_31 -> V_30 ;
unsigned long V_74 ;
V_74 = F_1 ( V_16 -> V_4 . V_6 + V_75 ) ;
V_74 = V_74 >> V_76 ;
V_74 &= V_77 ;
while ( ! F_19 ( V_30 ) && ( V_74 < V_16 -> V_35 ) ) {
F_3 ( V_30 -> V_36 [ V_30 -> V_37 ] , V_16 -> V_4 . V_6 + V_78 ) ;
V_30 -> V_37 = ( V_30 -> V_37 + 1 ) & ( V_39 - 1 ) ;
V_16 -> V_4 . V_21 . V_40 ++ ;
V_74 = F_1 ( V_16 -> V_4 . V_6 + V_75 ) ;
V_74 = V_74 >> V_76 ;
V_74 &= V_77 ;
}
if ( F_20 ( V_30 ) < V_41 )
F_21 ( & V_16 -> V_4 ) ;
if ( F_19 ( V_30 ) )
F_8 ( & V_16 -> V_4 ) ;
}
static void F_44 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = F_32 ( V_4 ,
struct V_15 , V_4 ) ;
struct V_29 * V_30 = & V_16 -> V_4 . V_31 -> V_30 ;
unsigned char V_5 ;
V_5 = F_6 ( V_4 -> V_6 + V_7 ) ;
F_7 ( V_5 | V_8 , V_4 -> V_6 + V_7 ) ;
if ( V_16 -> V_65 ) {
if ( ! F_19 ( V_30 ) && ! V_16 -> V_55 )
F_27 ( V_16 ) ;
} else {
if ( F_6 ( V_4 -> V_6 + V_79 ) & V_80 )
F_42 ( V_16 ) ;
}
}
static void F_45 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = F_32 ( V_4 , struct V_15 , V_4 ) ;
unsigned long V_5 ;
V_5 = F_1 ( V_4 -> V_6 + V_10 ) ;
F_3 ( V_5 | V_11 , V_4 -> V_6 + V_10 ) ;
if ( F_1 ( V_4 -> V_6 + V_81 ) & V_82 )
F_43 ( V_16 ) ;
}
static T_4 F_46 ( int V_83 , void * V_84 )
{
struct V_15 * V_16 = V_84 ;
struct V_29 * V_30 = & V_16 -> V_4 . V_31 -> V_30 ;
unsigned long V_32 ;
F_18 ( & V_16 -> V_4 . V_33 , V_32 ) ;
if ( V_16 -> V_4 . V_85 ) {
if ( V_16 -> V_86 )
F_3 ( V_16 -> V_4 . V_85 , V_16 -> V_4 . V_6 + V_78 ) ;
else
F_7 ( V_16 -> V_4 . V_85 , V_16 -> V_4 . V_6 + V_38 ) ;
goto V_87;
}
if ( F_19 ( V_30 ) || F_47 ( & V_16 -> V_4 ) ) {
if ( V_16 -> V_86 )
F_8 ( & V_16 -> V_4 ) ;
else
F_5 ( & V_16 -> V_4 ) ;
goto V_87;
}
if ( V_16 -> V_86 )
F_43 ( V_16 ) ;
else
F_42 ( V_16 ) ;
if ( F_20 ( V_30 ) < V_41 )
F_21 ( & V_16 -> V_4 ) ;
V_87:
F_22 ( & V_16 -> V_4 . V_33 , V_32 ) ;
return V_88 ;
}
static T_4 F_48 ( int V_83 , void * V_84 )
{
struct V_15 * V_16 = V_84 ;
unsigned int V_89 , V_90 = 0 ;
struct V_17 * V_4 = & V_16 -> V_4 . V_31 -> V_4 ;
unsigned long V_32 ;
unsigned char V_22 , V_91 ;
F_18 ( & V_16 -> V_4 . V_33 , V_32 ) ;
while ( ! ( F_6 ( V_16 -> V_4 . V_6 + V_92 ) & V_93 ) ) {
V_89 = V_94 ;
V_16 -> V_4 . V_21 . V_22 ++ ;
V_91 = F_6 ( V_16 -> V_4 . V_6 + V_79 ) ;
V_22 = F_6 ( V_16 -> V_4 . V_6 + V_38 ) ;
if ( F_49 ( & V_16 -> V_4 , ( unsigned char ) V_22 ) )
continue;
if ( V_91 & ( V_95 | V_96 | V_97 ) ) {
if ( V_91 & V_95 )
V_16 -> V_4 . V_21 . V_98 ++ ;
else if ( V_91 & V_97 )
V_16 -> V_4 . V_21 . V_99 ++ ;
if ( V_91 & V_96 )
V_16 -> V_4 . V_21 . V_100 ++ ;
if ( V_91 & V_16 -> V_4 . V_101 ) {
if ( ++ V_90 > 100 )
goto V_87;
continue;
}
V_91 &= V_16 -> V_4 . V_102 ;
if ( V_91 & V_95 )
V_89 = V_103 ;
else if ( V_91 & V_97 )
V_89 = V_104 ;
if ( V_91 & V_96 )
V_89 = V_105 ;
#ifdef F_50
V_16 -> V_4 . V_106 = 0 ;
#endif
}
F_51 ( V_4 , V_22 , V_89 ) ;
}
V_87:
F_22 ( & V_16 -> V_4 . V_33 , V_32 ) ;
F_35 ( V_4 ) ;
return V_88 ;
}
static T_4 F_52 ( int V_83 , void * V_84 )
{
struct V_15 * V_16 = V_84 ;
unsigned int V_89 , V_90 = 0 ;
struct V_17 * V_4 = & V_16 -> V_4 . V_31 -> V_4 ;
unsigned long V_32 ;
unsigned long V_22 , V_91 ;
F_18 ( & V_16 -> V_4 . V_33 , V_32 ) ;
while ( ! ( F_1 ( V_16 -> V_4 . V_6 + V_107 ) & V_108 ) ) {
V_89 = V_94 ;
V_16 -> V_4 . V_21 . V_22 ++ ;
V_91 = F_1 ( V_16 -> V_4 . V_6 + V_81 ) ;
V_22 = F_1 ( V_16 -> V_4 . V_6 + V_78 ) ;
V_22 &= 0x3ff ;
if ( F_49 ( & V_16 -> V_4 , ( unsigned char ) V_22 ) )
continue;
if ( V_91 & ( V_109 | V_110 | V_111 ) ) {
if ( V_91 & V_109 )
V_16 -> V_4 . V_21 . V_98 ++ ;
else if ( V_91 & V_111 )
V_16 -> V_4 . V_21 . V_99 ++ ;
if ( V_91 & V_110 )
V_16 -> V_4 . V_21 . V_100 ++ ;
if ( V_91 & V_16 -> V_4 . V_101 ) {
if ( ++ V_90 > 100 )
goto V_87;
continue;
}
V_91 &= V_16 -> V_4 . V_102 ;
if ( V_91 & V_109 )
V_89 = V_103 ;
else if ( V_91 & V_111 )
V_89 = V_104 ;
if ( V_91 & V_110 )
V_89 = V_105 ;
#ifdef F_50
V_16 -> V_4 . V_106 = 0 ;
#endif
}
F_51 ( V_4 , V_22 , V_89 ) ;
}
V_87:
F_22 ( & V_16 -> V_4 . V_33 , V_32 ) ;
F_35 ( V_4 ) ;
return V_88 ;
}
static T_4 F_53 ( int V_83 , void * V_84 )
{
struct V_15 * V_16 = V_84 ;
unsigned char V_112 , V_113 ;
V_112 = F_6 ( V_16 -> V_4 . V_6 + V_79 ) ;
V_113 = F_6 ( V_16 -> V_4 . V_6 + V_42 ) ;
if ( V_112 & V_114 && ! ( V_113 & V_72 ) ) {
if ( V_16 -> V_115 )
F_40 ( V_16 ) ;
else
F_48 ( V_83 , V_84 ) ;
}
if ( V_112 & V_80 && ! ( V_113 & V_43 ) ) {
if ( V_16 -> V_65 )
F_17 ( V_16 ) ;
else
F_46 ( V_83 , V_84 ) ;
}
return V_88 ;
}
static T_4 F_54 ( int V_83 , void * V_84 )
{
struct V_15 * V_16 = V_84 ;
unsigned long V_112 , V_116 ;
V_112 = F_1 ( V_16 -> V_4 . V_6 + V_81 ) ;
V_116 = F_1 ( V_16 -> V_4 . V_6 + V_75 ) ;
V_116 = V_116 >> V_117 ;
if ( V_112 & V_118 || V_116 > 0 )
F_52 ( V_83 , V_84 ) ;
if ( ( V_112 & V_82 ) &&
! ( F_1 ( V_16 -> V_4 . V_6 + V_119 ) & V_120 ) )
F_46 ( V_83 , V_84 ) ;
F_3 ( V_112 , V_16 -> V_4 . V_6 + V_81 ) ;
return V_88 ;
}
static unsigned int F_55 ( struct V_3 * V_4 )
{
return ( F_6 ( V_4 -> V_6 + V_79 ) & V_121 ) ?
V_122 : 0 ;
}
static unsigned int F_56 ( struct V_3 * V_4 )
{
return ( F_1 ( V_4 -> V_6 + V_81 ) & V_123 ) ?
V_122 : 0 ;
}
static unsigned int F_57 ( struct V_3 * V_4 )
{
unsigned int V_5 = 0 ;
unsigned char V_124 ;
V_124 = F_6 ( V_4 -> V_6 + V_125 ) ;
if ( V_124 & V_126 )
V_5 |= V_127 ;
if ( V_124 & V_128 )
V_5 |= V_129 ;
return V_5 ;
}
static unsigned int F_58 ( struct V_3 * V_4 )
{
unsigned int V_5 = 0 ;
unsigned long V_124 ;
V_124 = F_1 ( V_4 -> V_6 + V_130 ) ;
if ( V_124 & V_131 )
V_5 |= V_127 ;
if ( V_124 & V_132 )
V_5 |= V_129 ;
return V_5 ;
}
static void F_59 ( struct V_3 * V_4 , unsigned int V_133 )
{
unsigned char V_5 ;
V_5 = F_6 ( V_4 -> V_6 + V_125 ) &
~ ( V_128 | V_126 ) ;
if ( V_133 & V_129 )
V_5 |= V_128 ;
if ( V_133 & V_127 )
V_5 |= V_126 ;
F_7 ( V_5 , V_4 -> V_6 + V_125 ) ;
}
static void F_60 ( struct V_3 * V_4 , unsigned int V_133 )
{
unsigned long V_5 ;
V_5 = F_1 ( V_4 -> V_6 + V_130 ) &
~ ( V_132 | V_131 ) ;
if ( V_133 & V_129 )
V_5 |= V_132 ;
if ( V_133 & V_127 )
V_5 |= V_131 ;
F_3 ( V_5 , V_4 -> V_6 + V_130 ) ;
}
static void F_61 ( struct V_3 * V_4 , int V_134 )
{
unsigned char V_5 ;
V_5 = F_6 ( V_4 -> V_6 + V_7 ) & ~ V_135 ;
if ( V_134 != 0 )
V_5 |= V_135 ;
F_7 ( V_5 , V_4 -> V_6 + V_7 ) ;
}
static void F_62 ( struct V_3 * V_4 , int V_134 )
{
unsigned long V_5 ;
V_5 = F_1 ( V_4 -> V_6 + V_10 ) & ~ V_136 ;
if ( V_134 != 0 )
V_5 |= V_136 ;
F_3 ( V_5 , V_4 -> V_6 + V_10 ) ;
}
static void F_63 ( struct V_15 * V_16 )
{
unsigned char V_2 , V_137 ;
unsigned char V_138 ;
V_137 = F_6 ( V_16 -> V_4 . V_6 + V_7 ) ;
V_138 = V_137 ;
V_137 &= ~ ( V_8 | V_9 | V_139 |
V_140 | V_13 ) ;
F_7 ( V_137 , V_16 -> V_4 . V_6 + V_7 ) ;
V_2 = F_6 ( V_16 -> V_4 . V_6 + V_141 ) ;
F_7 ( V_2 | V_142 | V_143 ,
V_16 -> V_4 . V_6 + V_141 ) ;
F_6 ( V_16 -> V_4 . V_6 + V_79 ) ;
F_7 ( V_144 | V_145 ,
V_16 -> V_4 . V_6 + V_146 ) ;
F_7 ( 0 , V_16 -> V_4 . V_6 + V_147 ) ;
F_7 ( 1 , V_16 -> V_4 . V_6 + V_148 ) ;
F_7 ( V_138 , V_16 -> V_4 . V_6 + V_7 ) ;
}
static void F_64 ( struct V_15 * V_16 )
{
unsigned long V_2 , V_149 ;
unsigned long V_150 ;
V_149 = F_1 ( V_16 -> V_4 . V_6 + V_10 ) ;
V_150 = V_149 ;
V_149 &= ~ ( V_11 | V_12 | V_151 |
V_152 | V_14 ) ;
F_3 ( V_149 , V_16 -> V_4 . V_6 + V_10 ) ;
V_2 = F_1 ( V_16 -> V_4 . V_6 + V_107 ) ;
V_2 |= V_153 | V_154 ;
V_2 |= V_155 | V_156 ;
F_3 ( V_2 , V_16 -> V_4 . V_6 + V_107 ) ;
V_2 = ( 0x1 << V_157 ) | ( 0x0 << V_158 ) ;
F_3 ( V_2 , V_16 -> V_4 . V_6 + V_75 ) ;
F_3 ( V_150 , V_16 -> V_4 . V_6 + V_10 ) ;
}
static int F_65 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = F_32 ( V_4 ,
struct V_15 , V_4 ) ;
struct V_159 V_160 ;
T_3 V_161 ;
unsigned char * V_162 ;
int V_163 ;
V_161 = F_66 ( V_16 -> V_48 -> V_164 -> V_23 ,
V_16 -> V_4 . V_31 -> V_30 . V_36 ,
V_39 , V_28 ) ;
if ( F_67 ( V_16 -> V_48 -> V_164 -> V_23 , V_161 ) ) {
F_12 ( V_16 -> V_4 . V_23 , L_5 ) ;
return - V_165 ;
}
V_162 = V_16 -> V_4 . V_31 -> V_30 . V_36 ;
V_160 . V_166 = V_16 -> V_4 . V_167 + V_38 ;
V_160 . V_168 = V_169 ;
V_160 . V_170 = V_16 -> V_35 ;
V_160 . V_171 = V_49 ;
V_163 = F_68 ( V_16 -> V_48 , & V_160 ) ;
if ( V_163 < 0 ) {
F_12 ( V_16 -> V_4 . V_23 ,
L_6 , V_163 ) ;
return V_163 ;
}
V_16 -> V_172 = V_162 ;
V_16 -> V_45 = V_161 ;
V_16 -> V_55 = 0 ;
return 0 ;
}
static int F_69 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = F_32 ( V_4 ,
struct V_15 , V_4 ) ;
struct V_159 V_173 ;
T_3 V_161 ;
unsigned char * V_162 ;
int V_163 ;
V_162 = F_70 ( V_16 -> V_4 . V_23 ,
V_25 , V_174 ) ;
if ( ! V_162 ) {
F_12 ( V_16 -> V_4 . V_23 , L_7 ) ;
return - V_165 ;
}
V_161 = F_66 ( V_16 -> V_60 -> V_164 -> V_23 , V_162 ,
V_25 , V_26 ) ;
if ( F_67 ( V_16 -> V_60 -> V_164 -> V_23 , V_161 ) ) {
F_12 ( V_16 -> V_4 . V_23 , L_8 ) ;
return - V_165 ;
}
V_173 . V_175 = V_16 -> V_4 . V_167 + V_38 ;
V_173 . V_176 = V_169 ;
V_173 . V_177 = 1 ;
V_173 . V_171 = V_61 ;
V_163 = F_68 ( V_16 -> V_60 , & V_173 ) ;
if ( V_163 < 0 ) {
F_12 ( V_16 -> V_4 . V_23 ,
L_6 , V_163 ) ;
return V_163 ;
}
V_16 -> V_27 = V_162 ;
V_16 -> V_24 = V_161 ;
V_16 -> V_63 = 0 ;
return 0 ;
}
static void F_71 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = F_32 ( V_4 ,
struct V_15 , V_4 ) ;
F_72 ( V_16 -> V_4 . V_23 , V_16 -> V_45 ,
V_39 , V_28 ) ;
V_16 -> V_45 = 0 ;
V_16 -> V_172 = NULL ;
}
static void F_73 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = F_32 ( V_4 ,
struct V_15 , V_4 ) ;
F_72 ( V_16 -> V_4 . V_23 , V_16 -> V_24 ,
V_25 , V_26 ) ;
V_16 -> V_24 = 0 ;
V_16 -> V_27 = NULL ;
}
static int F_74 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = F_32 ( V_4 , struct V_15 , V_4 ) ;
int V_163 ;
unsigned long V_32 ;
unsigned char V_5 ;
V_5 = F_6 ( V_16 -> V_4 . V_6 + V_141 ) ;
V_16 -> V_35 = 0x1 << ( ( ( V_5 >> V_178 ) &
V_179 ) + 1 ) ;
V_16 -> V_4 . V_180 = V_16 -> V_35 ;
V_16 -> V_181 = 0x1 << ( ( ( V_5 >> V_182 ) &
V_179 ) + 1 ) ;
if ( V_16 -> V_60 && ! F_69 ( V_4 ) ) {
V_16 -> V_115 = true ;
F_75 ( & V_16 -> V_66 , F_36 ,
( unsigned long ) V_16 ) ;
} else
V_16 -> V_115 = false ;
if ( V_16 -> V_48 && ! F_65 ( V_4 ) ) {
V_16 -> V_65 = true ;
V_5 = F_6 ( V_4 -> V_6 + V_42 ) ;
V_5 &= ~ V_72 ;
F_7 ( V_5 | V_43 , V_4 -> V_6 + V_42 ) ;
} else
V_16 -> V_65 = false ;
V_163 = F_76 ( V_4 -> V_23 , V_4 -> V_83 , F_53 , 0 ,
V_183 , V_16 ) ;
if ( V_163 )
return V_163 ;
F_18 ( & V_16 -> V_4 . V_33 , V_32 ) ;
F_63 ( V_16 ) ;
V_5 = F_6 ( V_16 -> V_4 . V_6 + V_7 ) ;
V_5 |= ( V_140 | V_8 | V_13 | V_139 ) ;
F_7 ( V_5 , V_16 -> V_4 . V_6 + V_7 ) ;
F_22 ( & V_16 -> V_4 . V_33 , V_32 ) ;
return 0 ;
}
static int F_77 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = F_32 ( V_4 , struct V_15 , V_4 ) ;
int V_163 ;
unsigned long V_32 ;
unsigned long V_5 ;
V_5 = F_1 ( V_16 -> V_4 . V_6 + V_107 ) ;
V_16 -> V_35 = 0x1 << ( ( ( V_5 >> V_184 ) &
V_185 ) - 1 ) ;
V_16 -> V_181 = 0x1 << ( ( ( V_5 >> V_186 ) &
V_185 ) - 1 ) ;
V_163 = F_76 ( V_4 -> V_23 , V_4 -> V_83 , F_54 , 0 ,
V_183 , V_16 ) ;
if ( V_163 )
return V_163 ;
F_18 ( & V_16 -> V_4 . V_33 , V_32 ) ;
F_64 ( V_16 ) ;
V_5 = F_1 ( V_16 -> V_4 . V_6 + V_10 ) ;
V_5 |= ( V_152 | V_11 | V_14 | V_151 ) ;
V_5 |= V_187 ;
F_3 ( V_5 , V_16 -> V_4 . V_6 + V_10 ) ;
F_22 ( & V_16 -> V_4 . V_33 , V_32 ) ;
return 0 ;
}
static void F_78 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = F_32 ( V_4 , struct V_15 , V_4 ) ;
unsigned char V_5 ;
unsigned long V_32 ;
F_18 ( & V_4 -> V_33 , V_32 ) ;
V_5 = F_6 ( V_4 -> V_6 + V_7 ) ;
V_5 &= ~ ( V_139 | V_13 |
V_8 | V_9 | V_140 ) ;
F_7 ( V_5 , V_4 -> V_6 + V_7 ) ;
F_22 ( & V_4 -> V_33 , V_32 ) ;
F_79 ( V_4 -> V_23 , V_4 -> V_83 , V_16 ) ;
if ( V_16 -> V_115 ) {
F_73 ( & V_16 -> V_4 ) ;
F_80 ( & V_16 -> V_66 ) ;
}
if ( V_16 -> V_65 )
F_71 ( & V_16 -> V_4 ) ;
}
static void F_81 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = F_32 ( V_4 , struct V_15 , V_4 ) ;
unsigned long V_5 ;
unsigned long V_32 ;
F_18 ( & V_4 -> V_33 , V_32 ) ;
V_5 = F_1 ( V_4 -> V_6 + V_10 ) ;
V_5 &= ~ ( V_151 | V_14 |
V_11 | V_12 | V_152 ) ;
F_3 ( V_5 , V_4 -> V_6 + V_10 ) ;
F_22 ( & V_4 -> V_33 , V_32 ) ;
F_79 ( V_4 -> V_23 , V_4 -> V_83 , V_16 ) ;
}
static void
F_82 ( struct V_3 * V_4 , struct V_188 * V_189 ,
struct V_188 * V_190 )
{
struct V_15 * V_16 = F_32 ( V_4 , struct V_15 , V_4 ) ;
unsigned long V_32 ;
unsigned char V_191 , V_192 , V_193 , V_194 , V_195 , V_196 ;
unsigned int V_197 ;
unsigned int V_198 = V_190 ? V_190 -> V_199 & V_200 : V_201 ;
unsigned int V_202 , V_203 ;
V_191 = V_192 = F_6 ( V_16 -> V_4 . V_6 + V_204 ) ;
V_193 = F_6 ( V_16 -> V_4 . V_6 + V_7 ) ;
V_194 = F_6 ( V_16 -> V_4 . V_6 + V_205 ) ;
V_195 = F_6 ( V_16 -> V_4 . V_6 + V_206 ) ;
V_196 = F_6 ( V_16 -> V_4 . V_6 + V_125 ) ;
while ( ( V_189 -> V_199 & V_200 ) != V_201 &&
( V_189 -> V_199 & V_200 ) != V_207 ) {
V_189 -> V_199 &= ~ V_200 ;
V_189 -> V_199 |= V_198 ;
V_198 = V_201 ;
}
if ( ( V_189 -> V_199 & V_200 ) == V_201 ||
( V_189 -> V_199 & V_200 ) == V_207 )
V_191 = V_192 & ~ V_208 ;
if ( V_189 -> V_199 & V_209 ) {
if ( ( V_189 -> V_199 & V_200 ) != V_201 ) {
V_189 -> V_199 &= ~ V_200 ;
V_189 -> V_199 |= V_201 ;
}
V_191 |= V_208 ;
}
if ( V_189 -> V_199 & V_210 ) {
V_196 |= ( V_128 | V_126 ) ;
} else {
V_189 -> V_199 &= ~ V_210 ;
V_196 &= ~ ( V_128 | V_126 ) ;
}
if ( V_189 -> V_199 & V_211 )
V_189 -> V_199 &= ~ V_211 ;
if ( ( V_189 -> V_199 & V_200 ) == V_207 )
V_189 -> V_199 |= V_212 ;
if ( ( V_189 -> V_199 & V_212 ) ) {
if ( V_189 -> V_199 & V_209 ) {
V_191 &= ~ V_213 ;
V_191 |= V_208 ;
} else {
V_191 |= V_213 ;
if ( ( V_189 -> V_199 & V_200 ) == V_201 )
V_191 |= V_208 ;
if ( V_189 -> V_199 & V_214 )
V_191 |= V_215 ;
else
V_191 &= ~ V_215 ;
}
}
V_197 = F_83 ( V_4 , V_189 , V_190 , 50 , V_4 -> V_216 / 16 ) ;
F_18 ( & V_16 -> V_4 . V_33 , V_32 ) ;
V_16 -> V_4 . V_102 = 0 ;
if ( V_189 -> V_217 & V_218 )
V_16 -> V_4 . V_102 |= ( V_97 | V_95 ) ;
if ( V_189 -> V_217 & ( V_219 | V_220 | V_221 ) )
V_16 -> V_4 . V_102 |= V_97 ;
V_16 -> V_4 . V_101 = 0 ;
if ( V_189 -> V_217 & V_222 )
V_16 -> V_4 . V_101 |= V_95 ;
if ( V_189 -> V_217 & V_219 ) {
V_16 -> V_4 . V_101 |= V_97 ;
if ( V_189 -> V_217 & V_222 )
V_16 -> V_4 . V_101 |= V_96 ;
}
F_84 ( V_4 , V_189 -> V_199 , V_197 ) ;
if ( V_16 -> V_115 ) {
V_16 -> V_68 = ( V_16 -> V_4 . V_223 - V_224 / 50 ) *
V_25 * 3 /
V_16 -> V_181 / 2 ;
F_85 ( V_4 -> V_23 , L_9 ,
V_16 -> V_68 * 1000 / V_224 , V_16 -> V_4 . V_223 ) ;
if ( V_16 -> V_68 < F_86 ( 20 ) )
V_16 -> V_68 = F_86 ( 20 ) ;
}
while ( ! ( F_6 ( V_16 -> V_4 . V_6 + V_79 ) & V_121 ) )
F_87 () ;
F_7 ( V_193 & ~ ( V_139 | V_13 ) ,
V_16 -> V_4 . V_6 + V_7 ) ;
V_202 = V_16 -> V_4 . V_216 / ( 16 * V_197 ) ;
V_203 = ( ( V_16 -> V_4 . V_216 - ( 16 * V_202 * V_197 ) ) * 2 ) / V_197 ;
V_195 &= ~ V_225 ;
V_195 |= ( V_202 >> 8 ) & 0x1F ;
V_194 &= ~ V_226 ;
V_203 &= V_226 ;
F_7 ( V_194 | V_203 , V_16 -> V_4 . V_6 + V_205 ) ;
F_7 ( V_195 , V_16 -> V_4 . V_6 + V_206 ) ;
F_7 ( V_202 & 0xFF , V_16 -> V_4 . V_6 + V_227 ) ;
F_7 ( V_191 , V_16 -> V_4 . V_6 + V_204 ) ;
F_7 ( V_196 , V_16 -> V_4 . V_6 + V_125 ) ;
F_7 ( V_193 , V_16 -> V_4 . V_6 + V_7 ) ;
F_22 ( & V_16 -> V_4 . V_33 , V_32 ) ;
}
static void
F_88 ( struct V_3 * V_4 , struct V_188 * V_189 ,
struct V_188 * V_190 )
{
struct V_15 * V_16 = F_32 ( V_4 , struct V_15 , V_4 ) ;
unsigned long V_32 ;
unsigned long V_149 , V_228 , V_229 , V_196 ;
unsigned int V_197 ;
unsigned int V_198 = V_190 ? V_190 -> V_199 & V_200 : V_201 ;
unsigned int V_202 ;
V_149 = V_228 = F_1 ( V_16 -> V_4 . V_6 + V_10 ) ;
V_229 = F_1 ( V_16 -> V_4 . V_6 + V_119 ) ;
V_196 = F_1 ( V_16 -> V_4 . V_6 + V_130 ) ;
while ( ( V_189 -> V_199 & V_200 ) != V_201 &&
( V_189 -> V_199 & V_200 ) != V_207 ) {
V_189 -> V_199 &= ~ V_200 ;
V_189 -> V_199 |= V_198 ;
V_198 = V_201 ;
}
if ( ( V_189 -> V_199 & V_200 ) == V_201 ||
( V_189 -> V_199 & V_200 ) == V_207 )
V_149 = V_228 & ~ V_230 ;
if ( V_189 -> V_199 & V_209 ) {
if ( ( V_189 -> V_199 & V_200 ) != V_201 ) {
V_189 -> V_199 &= ~ V_200 ;
V_189 -> V_199 |= V_201 ;
}
V_149 |= V_230 ;
}
if ( V_189 -> V_199 & V_210 ) {
V_196 |= ( V_128 | V_126 ) ;
} else {
V_189 -> V_199 &= ~ V_210 ;
V_196 &= ~ ( V_128 | V_126 ) ;
}
if ( V_189 -> V_199 & V_211 )
V_189 -> V_199 &= ~ V_211 ;
if ( ( V_189 -> V_199 & V_200 ) == V_207 )
V_189 -> V_199 |= V_212 ;
if ( ( V_189 -> V_199 & V_212 ) ) {
if ( V_189 -> V_199 & V_209 ) {
V_149 &= ~ V_231 ;
V_149 |= V_230 ;
} else {
V_149 |= V_213 ;
if ( ( V_189 -> V_199 & V_200 ) == V_201 )
V_149 |= V_230 ;
if ( V_189 -> V_199 & V_214 )
V_149 |= V_232 ;
else
V_149 &= ~ V_232 ;
}
}
V_197 = F_83 ( V_4 , V_189 , V_190 , 50 , V_4 -> V_216 / 16 ) ;
F_18 ( & V_16 -> V_4 . V_33 , V_32 ) ;
V_16 -> V_4 . V_102 = 0 ;
if ( V_189 -> V_217 & V_218 )
V_16 -> V_4 . V_102 |= ( V_111 | V_109 ) ;
if ( V_189 -> V_217 & ( V_219 | V_220 | V_221 ) )
V_16 -> V_4 . V_102 |= V_111 ;
V_16 -> V_4 . V_101 = 0 ;
if ( V_189 -> V_217 & V_222 )
V_16 -> V_4 . V_101 |= V_109 ;
if ( V_189 -> V_217 & V_219 ) {
V_16 -> V_4 . V_101 |= V_111 ;
if ( V_189 -> V_217 & V_222 )
V_16 -> V_4 . V_101 |= V_110 ;
}
F_84 ( V_4 , V_189 -> V_199 , V_197 ) ;
while ( ! ( F_1 ( V_16 -> V_4 . V_6 + V_81 ) & V_123 ) )
F_87 () ;
F_3 ( V_228 & ~ ( V_151 | V_14 ) ,
V_16 -> V_4 . V_6 + V_10 ) ;
V_202 = V_16 -> V_4 . V_216 / ( 16 * V_197 ) ;
V_229 &= ~ V_233 ;
V_229 |= V_202 & V_233 ;
V_229 |= V_234 ;
V_229 &= ~ ( V_120 | V_235 ) ;
F_3 ( V_229 , V_16 -> V_4 . V_6 + V_119 ) ;
F_3 ( V_196 , V_16 -> V_4 . V_6 + V_130 ) ;
F_3 ( V_149 , V_16 -> V_4 . V_6 + V_10 ) ;
F_22 ( & V_16 -> V_4 . V_33 , V_32 ) ;
}
static const char * F_89 ( struct V_3 * V_4 )
{
return L_10 ;
}
static void F_90 ( struct V_3 * V_4 )
{
}
static int F_91 ( struct V_3 * V_4 )
{
return 0 ;
}
static void F_92 ( struct V_3 * V_4 , int V_32 )
{
if ( V_32 & V_236 )
V_4 -> type = V_237 ;
}
static int F_93 ( struct V_3 * V_4 , struct V_238 * V_239 )
{
int V_163 = 0 ;
if ( V_239 -> type != V_240 && V_239 -> type != V_237 )
V_163 = - V_241 ;
if ( V_4 -> V_83 != V_239 -> V_83 )
V_163 = - V_241 ;
if ( V_239 -> V_242 != V_243 )
V_163 = - V_241 ;
if ( V_4 -> V_216 / 16 != V_239 -> V_244 )
V_163 = - V_241 ;
if ( V_4 -> V_245 != V_239 -> V_4 )
V_163 = - V_241 ;
if ( V_239 -> V_246 != 0 )
V_163 = - V_241 ;
return V_163 ;
}
static void F_94 ( struct V_3 * V_4 , int V_247 )
{
while ( ! ( F_6 ( V_4 -> V_6 + V_79 ) & V_80 ) )
F_87 () ;
F_7 ( V_247 , V_4 -> V_6 + V_38 ) ;
}
static void F_95 ( struct V_3 * V_4 , int V_247 )
{
while ( ! ( F_1 ( V_4 -> V_6 + V_81 ) & V_82 ) )
F_87 () ;
F_3 ( V_247 , V_4 -> V_6 + V_78 ) ;
}
static void
F_96 ( struct V_248 * V_249 , const char * V_250 , unsigned int V_19 )
{
struct V_15 * V_16 = V_251 [ V_249 -> V_252 ] ;
unsigned char V_193 , V_137 ;
V_137 = V_193 = F_6 ( V_16 -> V_4 . V_6 + V_7 ) ;
V_137 |= ( V_139 | V_13 ) ;
V_137 &= ~ ( V_8 | V_9 | V_140 ) ;
F_7 ( V_137 , V_16 -> V_4 . V_6 + V_7 ) ;
F_97 ( & V_16 -> V_4 , V_250 , V_19 , F_94 ) ;
while ( ! ( F_6 ( V_16 -> V_4 . V_6 + V_79 ) & V_121 ) )
F_87 () ;
F_7 ( V_193 , V_16 -> V_4 . V_6 + V_7 ) ;
}
static void
F_98 ( struct V_248 * V_249 , const char * V_250 , unsigned int V_19 )
{
struct V_15 * V_16 = V_251 [ V_249 -> V_252 ] ;
unsigned long V_253 , V_254 ;
V_254 = V_253 = F_1 ( V_16 -> V_4 . V_6 + V_10 ) ;
V_254 |= ( V_151 | V_14 ) ;
V_254 &= ~ ( V_11 | V_12 | V_152 ) ;
F_3 ( V_254 , V_16 -> V_4 . V_6 + V_10 ) ;
F_97 ( & V_16 -> V_4 , V_250 , V_19 , F_95 ) ;
while ( ! ( F_1 ( V_16 -> V_4 . V_6 + V_81 ) & V_123 ) )
F_87 () ;
F_3 ( V_253 , V_16 -> V_4 . V_6 + V_10 ) ;
}
static void T_5
F_99 ( struct V_15 * V_16 , int * V_197 ,
int * V_98 , int * V_255 )
{
unsigned char V_254 , V_195 , V_256 , V_203 ;
unsigned int V_202 , V_216 , V_257 ;
V_254 = F_6 ( V_16 -> V_4 . V_6 + V_7 ) ;
V_254 &= V_139 | V_13 ;
if ( ! V_254 )
return;
V_254 = F_6 ( V_16 -> V_4 . V_6 + V_204 ) ;
* V_98 = 'n' ;
if ( V_254 & V_213 ) {
if ( V_254 & V_215 )
* V_98 = 'o' ;
else
* V_98 = 'e' ;
}
if ( V_254 & V_208 )
* V_255 = 9 ;
else
* V_255 = 8 ;
V_195 = F_6 ( V_16 -> V_4 . V_6 + V_206 ) ;
V_195 &= V_225 ;
V_256 = F_6 ( V_16 -> V_4 . V_6 + V_227 ) ;
V_202 = V_195 ;
V_202 <<= 8 ;
V_202 |= V_256 ;
V_203 = F_6 ( V_16 -> V_4 . V_6 + V_205 ) ;
V_203 &= V_226 ;
V_216 = F_100 ( V_16 -> V_258 ) ;
V_257 = V_216 / ( 16 * ( V_202 + V_203 / 32 ) ) ;
if ( * V_197 != V_257 )
F_101 ( V_259 L_11
L_12 , V_257 , * V_197 ) ;
}
static void T_5
F_102 ( struct V_15 * V_16 , int * V_197 ,
int * V_98 , int * V_255 )
{
unsigned long V_254 , V_229 ;
unsigned int V_202 , V_216 , V_257 ;
V_254 = F_1 ( V_16 -> V_4 . V_6 + V_10 ) ;
V_254 &= V_151 | V_14 ;
if ( ! V_254 )
return;
V_254 = F_1 ( V_16 -> V_4 . V_6 + V_10 ) ;
* V_98 = 'n' ;
if ( V_254 & V_231 ) {
if ( V_254 & V_232 )
* V_98 = 'o' ;
else
* V_98 = 'e' ;
}
if ( V_254 & V_230 )
* V_255 = 9 ;
else
* V_255 = 8 ;
V_229 = F_1 ( V_16 -> V_4 . V_6 + V_119 ) ;
V_229 &= V_233 ;
V_202 = V_229 ;
V_216 = F_100 ( V_16 -> V_258 ) ;
V_257 = V_216 / ( 16 * V_202 ) ;
if ( * V_197 != V_257 )
F_101 ( V_259 L_11
L_12 , V_257 , * V_197 ) ;
}
static int T_5 F_103 ( struct V_248 * V_249 , char * V_260 )
{
struct V_15 * V_16 ;
int V_197 = 115200 ;
int V_255 = 8 ;
int V_98 = 'n' ;
int V_261 = 'n' ;
if ( V_249 -> V_252 == - 1 || V_249 -> V_252 >= F_104 ( V_251 ) )
V_249 -> V_252 = 0 ;
V_16 = V_251 [ V_249 -> V_252 ] ;
if ( V_16 == NULL )
return - V_262 ;
if ( V_260 )
F_105 ( V_260 , & V_197 , & V_98 , & V_255 , & V_261 ) ;
else
if ( V_16 -> V_86 )
F_102 ( V_16 , & V_197 , & V_98 , & V_255 ) ;
else
F_99 ( V_16 , & V_197 , & V_98 , & V_255 ) ;
if ( V_16 -> V_86 )
F_64 ( V_16 ) ;
else
F_63 ( V_16 ) ;
return F_106 ( & V_16 -> V_4 , V_249 , V_197 , V_98 , V_255 , V_261 ) ;
}
static void F_107 ( struct V_248 * V_263 , const char * V_250 , unsigned V_264 )
{
struct V_265 * V_23 = V_263 -> V_69 ;
F_97 ( & V_23 -> V_4 , V_250 , V_264 , F_94 ) ;
}
static void F_108 ( struct V_248 * V_263 , const char * V_250 , unsigned V_264 )
{
struct V_265 * V_23 = V_263 -> V_69 ;
F_97 ( & V_23 -> V_4 , V_250 , V_264 , F_95 ) ;
}
static int T_5 F_109 ( struct V_265 * V_164 ,
const char * V_266 )
{
if ( ! V_164 -> V_4 . V_6 )
return - V_262 ;
V_164 -> V_263 -> V_267 = F_107 ;
return 0 ;
}
static int T_5 F_110 ( struct V_265 * V_164 ,
const char * V_266 )
{
if ( ! V_164 -> V_4 . V_6 )
return - V_262 ;
V_164 -> V_263 -> V_267 = F_108 ;
return 0 ;
}
static int F_111 ( struct V_268 * V_269 )
{
struct V_270 * V_271 = V_269 -> V_23 . V_272 ;
struct V_15 * V_16 ;
struct V_273 * V_274 ;
int V_163 ;
V_16 = F_70 ( & V_269 -> V_23 , sizeof( * V_16 ) , V_174 ) ;
if ( ! V_16 )
return - V_165 ;
V_269 -> V_23 . V_275 = 0 ;
V_163 = F_112 ( V_271 , L_13 ) ;
if ( V_163 < 0 ) {
F_12 ( & V_269 -> V_23 , L_14 , V_163 ) ;
return V_163 ;
}
V_16 -> V_4 . line = V_163 ;
V_16 -> V_86 = F_113 ( V_271 , L_15 ) ;
V_274 = F_114 ( V_269 , V_276 , 0 ) ;
V_16 -> V_4 . V_6 = F_115 ( & V_269 -> V_23 , V_274 ) ;
if ( F_116 ( V_16 -> V_4 . V_6 ) )
return F_117 ( V_16 -> V_4 . V_6 ) ;
V_16 -> V_4 . V_167 = V_274 -> V_277 ;
V_16 -> V_4 . V_23 = & V_269 -> V_23 ;
V_16 -> V_4 . type = V_237 ;
V_16 -> V_4 . V_278 = V_243 ;
V_16 -> V_4 . V_83 = F_118 ( V_269 , 0 ) ;
if ( V_16 -> V_86 )
V_16 -> V_4 . V_279 = & V_280 ;
else
V_16 -> V_4 . V_279 = & V_281 ;
V_16 -> V_4 . V_32 = V_282 ;
V_16 -> V_258 = F_119 ( & V_269 -> V_23 , L_16 ) ;
if ( F_116 ( V_16 -> V_258 ) ) {
V_163 = F_117 ( V_16 -> V_258 ) ;
F_12 ( & V_269 -> V_23 , L_17 , V_163 ) ;
return V_163 ;
}
V_163 = F_120 ( V_16 -> V_258 ) ;
if ( V_163 ) {
F_12 ( & V_269 -> V_23 , L_18 , V_163 ) ;
return V_163 ;
}
V_16 -> V_4 . V_216 = F_100 ( V_16 -> V_258 ) ;
V_251 [ V_16 -> V_4 . line ] = V_16 ;
F_121 ( V_269 , & V_16 -> V_4 ) ;
if ( V_16 -> V_86 )
V_283 . V_284 = V_285 ;
else
V_283 . V_284 = V_286 ;
V_163 = F_122 ( & V_283 , & V_16 -> V_4 ) ;
if ( V_163 ) {
F_123 ( V_16 -> V_258 ) ;
return V_163 ;
}
V_16 -> V_48 = F_124 ( V_16 -> V_4 . V_23 , L_19 ) ;
if ( ! V_16 -> V_48 )
F_125 ( V_16 -> V_4 . V_23 , L_20
L_21 ) ;
V_16 -> V_60 = F_124 ( V_16 -> V_4 . V_23 , L_22 ) ;
if ( ! V_16 -> V_60 )
F_125 ( V_16 -> V_4 . V_23 , L_23
L_24 ) ;
return 0 ;
}
static int F_126 ( struct V_268 * V_269 )
{
struct V_15 * V_16 = F_127 ( V_269 ) ;
F_128 ( & V_283 , & V_16 -> V_4 ) ;
F_123 ( V_16 -> V_258 ) ;
if ( V_16 -> V_48 )
F_129 ( V_16 -> V_48 ) ;
if ( V_16 -> V_60 )
F_129 ( V_16 -> V_60 ) ;
return 0 ;
}
static int F_130 ( struct V_164 * V_23 )
{
struct V_15 * V_16 = F_131 ( V_23 ) ;
unsigned long V_5 ;
if ( V_16 -> V_86 ) {
V_5 = F_1 ( V_16 -> V_4 . V_6 + V_10 ) ;
V_5 &= ~ ( V_151 | V_11 | V_12 ) ;
F_3 ( V_5 , V_16 -> V_4 . V_6 + V_10 ) ;
} else {
V_5 = F_6 ( V_16 -> V_4 . V_6 + V_7 ) ;
V_5 &= ~ ( V_139 | V_8 | V_9 ) ;
F_7 ( V_5 , V_16 -> V_4 . V_6 + V_7 ) ;
}
F_132 ( & V_283 , & V_16 -> V_4 ) ;
return 0 ;
}
static int F_133 ( struct V_164 * V_23 )
{
struct V_15 * V_16 = F_131 ( V_23 ) ;
unsigned long V_5 ;
if ( V_16 -> V_86 ) {
F_64 ( V_16 ) ;
V_5 = F_1 ( V_16 -> V_4 . V_6 + V_10 ) ;
V_5 |= ( V_152 | V_11 | V_14 |
V_151 | V_187 ) ;
F_3 ( V_5 , V_16 -> V_4 . V_6 + V_10 ) ;
} else {
F_63 ( V_16 ) ;
V_5 = F_6 ( V_16 -> V_4 . V_6 + V_7 ) ;
V_5 |= ( V_140 | V_8 | V_13 | V_139 ) ;
F_7 ( V_5 , V_16 -> V_4 . V_6 + V_7 ) ;
}
F_134 ( & V_283 , & V_16 -> V_4 ) ;
return 0 ;
}
static int T_5 F_135 ( void )
{
int V_163 = F_136 ( & V_283 ) ;
if ( V_163 )
return V_163 ;
V_163 = F_137 ( & V_287 ) ;
if ( V_163 )
F_138 ( & V_283 ) ;
return V_163 ;
}
static void T_6 F_139 ( void )
{
F_140 ( & V_287 ) ;
F_138 ( & V_283 ) ;
}
