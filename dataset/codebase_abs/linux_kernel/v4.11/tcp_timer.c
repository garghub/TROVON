static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_2 -> V_4 ? : V_5 ;
V_2 -> V_6 ( V_2 ) ;
F_2 ( V_2 ) ;
F_3 ( F_4 ( V_2 ) , V_7 ) ;
}
static int F_5 ( struct V_1 * V_2 , bool V_8 )
{
struct V_9 * V_10 = F_6 ( V_2 ) ;
int V_11 = 0 ;
if ( ( V_12 ) ( V_13 - V_10 -> V_14 ) > 2 * V_15 || ! V_8 )
V_11 ++ ;
if ( V_2 -> V_4 )
V_11 ++ ;
if ( F_7 ( V_2 , V_11 ) ) {
if ( ( V_12 ) ( V_13 - V_10 -> V_14 ) <= V_16 ||
( ! V_10 -> V_17 && ! V_10 -> V_18 ) )
V_8 = true ;
if ( V_8 )
F_8 ( V_2 , V_19 ) ;
F_2 ( V_2 ) ;
F_3 ( F_4 ( V_2 ) , V_20 ) ;
return 1 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , bool V_21 )
{
int V_22 = F_4 ( V_2 ) -> V_23 . V_24 ;
if ( V_2 -> V_4 && ! V_21 )
V_22 = 0 ;
if ( V_22 == 0 && V_21 )
V_22 = 8 ;
return V_22 ;
}
static void F_10 ( struct V_25 * V_26 , struct V_1 * V_2 )
{
struct V_27 * V_27 = F_4 ( V_2 ) ;
if ( V_27 -> V_23 . V_28 ) {
if ( ! V_26 -> V_29 . V_30 ) {
V_26 -> V_29 . V_30 = 1 ;
V_26 -> V_29 . V_31 = V_13 ;
F_11 ( V_2 , V_26 -> V_32 ) ;
} else {
struct V_27 * V_27 = F_4 ( V_2 ) ;
struct V_9 * V_10 = F_6 ( V_2 ) ;
int V_33 ;
V_33 = F_12 ( V_2 , V_26 -> V_29 . V_34 ) >> 1 ;
V_33 = F_13 ( V_27 -> V_23 . V_35 , V_33 ) ;
V_33 = F_14 ( V_33 , 68 - V_10 -> V_36 ) ;
V_26 -> V_29 . V_34 = F_15 ( V_2 , V_33 ) ;
F_11 ( V_2 , V_26 -> V_32 ) ;
}
}
}
static bool F_16 ( struct V_1 * V_2 ,
unsigned int V_37 ,
unsigned int V_38 ,
bool V_39 )
{
unsigned int V_40 , V_41 ;
unsigned int V_42 = V_39 ? V_43 : V_44 ;
if ( ! F_17 ( V_2 ) -> V_45 )
return false ;
V_41 = F_6 ( V_2 ) -> V_46 ;
if ( F_18 ( ! V_41 ) )
V_41 = F_19 ( F_20 ( V_2 ) ) ;
if ( F_21 ( V_38 == 0 ) ) {
V_40 = F_22 ( V_15 / V_42 ) ;
if ( V_37 <= V_40 )
V_38 = ( ( 2 << V_37 ) - 1 ) * V_42 ;
else
V_38 = ( ( 2 << V_40 ) - 1 ) * V_42 +
( V_37 - V_40 ) * V_15 ;
}
return ( V_13 - V_41 ) >= V_38 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = F_17 ( V_2 ) ;
struct V_9 * V_10 = F_6 ( V_2 ) ;
struct V_27 * V_27 = F_4 ( V_2 ) ;
int V_47 ;
bool V_8 , V_39 = false ;
if ( ( 1 << V_2 -> V_48 ) & ( V_49 | V_50 ) ) {
if ( V_26 -> V_45 ) {
F_24 ( V_2 ) ;
if ( V_10 -> V_51 || V_10 -> V_52 )
F_25 ( V_2 , 0 , NULL , true , 0 ) ;
if ( V_10 -> V_52 && V_26 -> V_45 == 1 )
F_26 ( F_4 ( V_2 ) ,
V_53 ) ;
} else if ( ! V_10 -> V_52 && ! V_10 -> V_51 ) {
F_27 ( V_2 ) ;
}
V_47 = V_26 -> V_54 ? : V_27 -> V_23 . V_55 ;
V_39 = true ;
} else {
if ( F_16 ( V_2 , V_27 -> V_23 . V_56 , 0 , 0 ) ) {
if ( V_10 -> V_57 &&
V_10 -> V_58 <= V_10 -> V_59 . V_60 ) {
F_25 ( V_2 , 0 , NULL , true , 0 ) ;
if ( V_26 -> V_45 == V_27 -> V_23 . V_56 )
F_26 ( F_4 ( V_2 ) ,
V_53 ) ;
}
F_10 ( V_26 , V_2 ) ;
F_24 ( V_2 ) ;
} else {
F_27 ( V_2 ) ;
}
V_47 = V_27 -> V_23 . V_61 ;
if ( F_28 ( V_2 , V_62 ) ) {
const bool V_21 = V_26 -> V_63 < V_15 ;
V_47 = F_9 ( V_2 , V_21 ) ;
V_8 = V_21 ||
! F_16 ( V_2 , V_47 , 0 , 0 ) ;
if ( F_5 ( V_2 , V_8 ) )
return 1 ;
}
}
if ( F_16 ( V_2 , V_47 ,
V_39 ? 0 : V_26 -> V_64 , V_39 ) ) {
F_1 ( V_2 ) ;
return 1 ;
}
return 0 ;
}
void F_29 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_6 ( V_2 ) ;
struct V_25 * V_26 = F_17 ( V_2 ) ;
F_30 ( V_2 ) ;
if ( ( ( 1 << V_2 -> V_48 ) & ( V_65 | V_66 ) ) ||
! ( V_26 -> V_67 . V_68 & V_69 ) )
goto V_70;
if ( F_31 ( V_26 -> V_67 . V_38 , V_71 ) ) {
F_32 ( V_2 , & V_26 -> V_72 , V_26 -> V_67 . V_38 ) ;
goto V_70;
}
V_26 -> V_67 . V_68 &= ~ V_69 ;
if ( ! F_33 ( & V_10 -> V_73 . V_74 ) ) {
struct V_75 * V_76 ;
F_3 ( F_4 ( V_2 ) , V_77 ) ;
while ( ( V_76 = F_34 ( & V_10 -> V_73 . V_74 ) ) != NULL )
F_35 ( V_2 , V_76 ) ;
V_10 -> V_73 . V_78 = 0 ;
}
if ( F_36 ( V_2 ) ) {
if ( ! V_26 -> V_67 . V_79 ) {
V_26 -> V_67 . V_80 = F_13 ( V_26 -> V_67 . V_80 << 1 , V_26 -> V_63 ) ;
} else {
V_26 -> V_67 . V_79 = 0 ;
V_26 -> V_67 . V_80 = V_81 ;
}
F_37 ( V_2 ) ;
F_3 ( F_4 ( V_2 ) , V_82 ) ;
}
V_70:
if ( F_38 ( V_2 ) )
F_39 ( V_2 ) ;
}
static void F_40 ( unsigned long V_83 )
{
struct V_1 * V_2 = (struct V_1 * ) V_83 ;
F_41 ( V_2 ) ;
if ( ! F_42 ( V_2 ) ) {
F_29 ( V_2 ) ;
} else {
F_17 ( V_2 ) -> V_67 . V_84 = 1 ;
F_3 ( F_4 ( V_2 ) , V_85 ) ;
if ( ! F_43 ( V_86 , & V_2 -> V_87 ) )
F_44 ( V_2 ) ;
}
F_45 ( V_2 ) ;
F_46 ( V_2 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = F_17 ( V_2 ) ;
struct V_9 * V_10 = F_6 ( V_2 ) ;
int V_88 ;
T_1 V_41 ;
if ( V_10 -> V_18 || ! F_48 ( V_2 ) ) {
V_26 -> V_89 = 0 ;
return;
}
V_41 = F_19 ( F_48 ( V_2 ) ) ;
if ( ! V_41 )
F_49 ( & F_48 ( V_2 ) -> V_90 ) ;
else if ( V_26 -> V_64 &&
( V_12 ) ( V_13 - V_41 ) > V_26 -> V_64 )
goto abort;
V_88 = F_4 ( V_2 ) -> V_23 . V_61 ;
if ( F_28 ( V_2 , V_62 ) ) {
const bool V_21 = F_50 ( V_26 , V_15 ) < V_15 ;
V_88 = F_9 ( V_2 , V_21 ) ;
if ( ! V_21 && V_26 -> V_91 >= V_88 )
goto abort;
if ( F_5 ( V_2 , true ) )
return;
}
if ( V_26 -> V_89 > V_88 ) {
abort: F_1 ( V_2 ) ;
} else {
F_51 ( V_2 ) ;
}
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = F_17 ( V_2 ) ;
int V_92 = V_26 -> V_54 ? :
F_4 ( V_2 ) -> V_23 . V_93 + 1 ;
struct V_94 * V_95 ;
V_95 = F_6 ( V_2 ) -> V_96 ;
V_95 -> V_97 -> V_98 ( V_95 ) ;
if ( V_95 -> V_99 >= V_92 ) {
F_1 ( V_2 ) ;
return;
}
F_53 ( V_2 , V_95 ) ;
V_95 -> V_99 ++ ;
V_26 -> V_45 ++ ;
F_54 ( V_2 , V_100 ,
V_43 << V_95 -> V_99 , V_15 ) ;
}
void F_55 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_6 ( V_2 ) ;
struct V_27 * V_27 = F_4 ( V_2 ) ;
struct V_25 * V_26 = F_17 ( V_2 ) ;
if ( V_10 -> V_96 ) {
F_56 ( V_2 -> V_48 != V_101 &&
V_2 -> V_48 != V_102 ) ;
F_52 ( V_2 ) ;
return;
}
if ( ! V_10 -> V_18 )
goto V_70;
F_57 ( F_58 ( V_2 ) ) ;
V_10 -> V_103 = 0 ;
if ( ! V_10 -> V_17 && ! F_28 ( V_2 , V_62 ) &&
! ( ( 1 << V_2 -> V_48 ) & ( V_49 | V_50 ) ) ) {
struct V_104 * V_105 = F_59 ( V_2 ) ;
if ( V_2 -> V_106 == V_107 ) {
F_60 ( L_1 ,
& V_105 -> V_108 ,
F_61 ( V_105 -> V_109 ) ,
V_105 -> V_110 ,
V_10 -> V_111 , V_10 -> V_112 ) ;
}
#if F_62 ( V_113 )
else if ( V_2 -> V_106 == V_114 ) {
F_60 ( L_2 ,
& V_2 -> V_115 ,
F_61 ( V_105 -> V_109 ) ,
V_105 -> V_110 ,
V_10 -> V_111 , V_10 -> V_112 ) ;
}
#endif
if ( V_13 - V_10 -> V_116 > V_15 ) {
F_1 ( V_2 ) ;
goto V_70;
}
F_63 ( V_2 ) ;
F_64 ( V_2 , F_20 ( V_2 ) , 1 ) ;
F_65 ( V_2 ) ;
goto V_117;
}
if ( F_23 ( V_2 ) )
goto V_70;
if ( V_26 -> V_45 == 0 ) {
int V_118 ;
if ( V_26 -> V_119 == V_120 ) {
if ( F_66 ( V_10 ) )
V_118 = V_121 ;
else
V_118 = V_122 ;
} else if ( V_26 -> V_119 == V_123 ) {
V_118 = V_124 ;
} else if ( ( V_26 -> V_119 == V_125 ) ||
V_10 -> V_126 ) {
if ( F_66 ( V_10 ) )
V_118 = V_127 ;
else
V_118 = V_128 ;
} else {
V_118 = V_129 ;
}
F_3 ( F_4 ( V_2 ) , V_118 ) ;
}
F_63 ( V_2 ) ;
if ( F_64 ( V_2 , F_20 ( V_2 ) , 1 ) > 0 ) {
if ( ! V_26 -> V_45 )
V_26 -> V_45 = 1 ;
F_54 ( V_2 , V_100 ,
F_13 ( V_26 -> V_63 , V_130 ) ,
V_15 ) ;
goto V_70;
}
V_26 -> V_91 ++ ;
V_26 -> V_45 ++ ;
V_117:
if ( V_2 -> V_48 == V_131 &&
( V_10 -> V_132 || V_133 ) &&
F_67 ( V_10 ) &&
V_26 -> V_45 <= V_134 ) {
V_26 -> V_91 = 0 ;
V_26 -> V_63 = F_13 ( F_68 ( V_10 ) , V_15 ) ;
} else {
V_26 -> V_63 = F_13 ( V_26 -> V_63 << 1 , V_15 ) ;
}
F_54 ( V_2 , V_100 , V_26 -> V_63 , V_15 ) ;
if ( F_16 ( V_2 , V_27 -> V_23 . V_56 + 1 , 0 , 0 ) )
F_65 ( V_2 ) ;
V_70: ;
}
void F_69 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = F_17 ( V_2 ) ;
int V_135 ;
if ( ( ( 1 << V_2 -> V_48 ) & ( V_65 | V_66 ) ) ||
! V_26 -> V_136 )
goto V_70;
if ( F_31 ( V_26 -> V_137 , V_71 ) ) {
F_32 ( V_2 , & V_26 -> V_138 , V_26 -> V_137 ) ;
goto V_70;
}
V_135 = V_26 -> V_136 ;
switch ( V_135 ) {
case V_139 :
F_70 ( V_2 ) ;
break;
case V_140 :
F_71 ( V_2 ) ;
break;
case V_100 :
V_26 -> V_136 = 0 ;
F_55 ( V_2 ) ;
break;
case V_141 :
V_26 -> V_136 = 0 ;
F_47 ( V_2 ) ;
break;
}
V_70:
F_39 ( V_2 ) ;
}
static void F_72 ( unsigned long V_83 )
{
struct V_1 * V_2 = (struct V_1 * ) V_83 ;
F_41 ( V_2 ) ;
if ( ! F_42 ( V_2 ) ) {
F_69 ( V_2 ) ;
} else {
if ( ! F_43 ( V_142 , & V_2 -> V_87 ) )
F_44 ( V_2 ) ;
}
F_45 ( V_2 ) ;
F_46 ( V_2 ) ;
}
void F_73 ( const struct V_94 * V_95 )
{
struct V_27 * V_27 = F_74 ( & F_75 ( V_95 ) -> V_143 ) ;
F_3 ( V_27 , V_129 ) ;
}
void F_76 ( struct V_1 * V_2 , int V_144 )
{
if ( ( 1 << V_2 -> V_48 ) & ( V_65 | V_66 ) )
return;
if ( V_144 && ! F_28 ( V_2 , V_145 ) )
F_77 ( V_2 , F_78 ( F_6 ( V_2 ) ) ) ;
else if ( ! V_144 )
F_79 ( V_2 ) ;
}
static void F_80 ( unsigned long V_83 )
{
struct V_1 * V_2 = (struct V_1 * ) V_83 ;
struct V_25 * V_26 = F_17 ( V_2 ) ;
struct V_9 * V_10 = F_6 ( V_2 ) ;
T_1 V_146 ;
F_41 ( V_2 ) ;
if ( F_42 ( V_2 ) ) {
F_77 ( V_2 , V_147 / 20 ) ;
goto V_70;
}
if ( V_2 -> V_48 == V_148 ) {
F_81 ( L_3 ) ;
goto V_70;
}
if ( V_2 -> V_48 == V_149 && F_28 ( V_2 , V_62 ) ) {
if ( V_10 -> V_150 >= 0 ) {
const int V_151 = F_82 ( V_2 ) - V_16 ;
if ( V_151 > 0 ) {
F_83 ( V_2 , V_149 , V_151 ) ;
goto V_70;
}
}
F_8 ( V_2 , V_19 ) ;
goto V_152;
}
if ( ! F_28 ( V_2 , V_145 ) || V_2 -> V_48 == V_153 )
goto V_70;
V_146 = F_78 ( V_10 ) ;
if ( V_10 -> V_18 || F_48 ( V_2 ) )
goto V_154;
V_146 = F_84 ( V_10 ) ;
if ( V_146 >= F_78 ( V_10 ) ) {
if ( ( V_26 -> V_64 != 0 &&
V_146 >= V_26 -> V_64 &&
V_26 -> V_89 > 0 ) ||
( V_26 -> V_64 == 0 &&
V_26 -> V_89 >= F_85 ( V_10 ) ) ) {
F_8 ( V_2 , V_19 ) ;
F_1 ( V_2 ) ;
goto V_70;
}
if ( F_86 ( V_2 , V_155 ) <= 0 ) {
V_26 -> V_89 ++ ;
V_146 = F_87 ( V_10 ) ;
} else {
V_146 = V_130 ;
}
} else {
V_146 = F_78 ( V_10 ) - V_146 ;
}
F_39 ( V_2 ) ;
V_154:
F_77 ( V_2 , V_146 ) ;
goto V_70;
V_152:
F_2 ( V_2 ) ;
V_70:
F_45 ( V_2 ) ;
F_46 ( V_2 ) ;
}
void F_88 ( struct V_1 * V_2 )
{
F_89 ( V_2 , & F_72 , & F_40 ,
& F_80 ) ;
}
