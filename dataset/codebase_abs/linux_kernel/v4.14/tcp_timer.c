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
unsigned int V_38 )
{
const unsigned int V_39 = V_40 ;
unsigned int V_41 , V_42 ;
if ( ! F_17 ( V_2 ) -> V_43 )
return false ;
V_42 = F_6 ( V_2 ) -> V_44 ;
if ( F_18 ( ! V_42 ) )
V_42 = F_19 ( F_20 ( V_2 ) ) ;
if ( F_21 ( V_38 == 0 ) ) {
V_41 = F_22 ( V_15 / V_39 ) ;
if ( V_37 <= V_41 )
V_38 = ( ( 2 << V_37 ) - 1 ) * V_39 ;
else
V_38 = ( ( 2 << V_41 ) - 1 ) * V_39 +
( V_37 - V_41 ) * V_15 ;
}
return ( F_23 ( F_6 ( V_2 ) ) - V_42 ) >= F_24 ( V_38 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = F_17 ( V_2 ) ;
struct V_9 * V_10 = F_6 ( V_2 ) ;
struct V_27 * V_27 = F_4 ( V_2 ) ;
bool V_45 , V_8 ;
int V_46 ;
if ( ( 1 << V_2 -> V_47 ) & ( V_48 | V_49 ) ) {
if ( V_26 -> V_43 ) {
F_26 ( V_2 ) ;
if ( V_10 -> V_50 || V_10 -> V_51 )
F_27 ( V_2 , 0 , NULL , true , 0 ) ;
if ( V_10 -> V_51 && V_26 -> V_43 == 1 )
F_28 ( F_4 ( V_2 ) ,
V_52 ) ;
} else if ( ! V_10 -> V_51 && ! V_10 -> V_50 ) {
F_29 ( V_2 ) ;
}
V_46 = V_26 -> V_53 ? : V_27 -> V_23 . V_54 ;
V_45 = V_26 -> V_43 >= V_46 ;
} else {
if ( F_16 ( V_2 , V_27 -> V_23 . V_55 , 0 ) ) {
if ( V_10 -> V_56 ) {
F_27 ( V_2 , 0 , NULL , true , 0 ) ;
if ( V_26 -> V_43 == V_27 -> V_23 . V_55 )
F_28 ( F_4 ( V_2 ) ,
V_52 ) ;
}
F_10 ( V_26 , V_2 ) ;
F_26 ( V_2 ) ;
} else {
F_29 ( V_2 ) ;
}
V_46 = V_27 -> V_23 . V_57 ;
if ( F_30 ( V_2 , V_58 ) ) {
const bool V_21 = V_26 -> V_59 < V_15 ;
V_46 = F_9 ( V_2 , V_21 ) ;
V_8 = V_21 ||
! F_16 ( V_2 , V_46 , 0 ) ;
if ( F_5 ( V_2 , V_8 ) )
return 1 ;
}
V_45 = F_16 ( V_2 , V_46 ,
V_26 -> V_60 ) ;
}
if ( V_45 ) {
F_1 ( V_2 ) ;
return 1 ;
}
return 0 ;
}
void F_31 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = F_17 ( V_2 ) ;
F_32 ( V_2 ) ;
if ( ( ( 1 << V_2 -> V_47 ) & ( V_61 | V_62 ) ) ||
! ( V_26 -> V_63 . V_64 & V_65 ) )
goto V_66;
if ( F_33 ( V_26 -> V_63 . V_38 , V_67 ) ) {
F_34 ( V_2 , & V_26 -> V_68 , V_26 -> V_63 . V_38 ) ;
goto V_66;
}
V_26 -> V_63 . V_64 &= ~ V_65 ;
if ( F_35 ( V_2 ) ) {
if ( ! V_26 -> V_63 . V_69 ) {
V_26 -> V_63 . V_70 = F_13 ( V_26 -> V_63 . V_70 << 1 , V_26 -> V_59 ) ;
} else {
V_26 -> V_63 . V_69 = 0 ;
V_26 -> V_63 . V_70 = V_71 ;
}
F_36 ( V_2 ) ;
F_3 ( F_4 ( V_2 ) , V_72 ) ;
}
V_66:
if ( F_37 ( V_2 ) )
F_38 ( V_2 ) ;
}
static void F_39 ( unsigned long V_73 )
{
struct V_1 * V_2 = (struct V_1 * ) V_73 ;
F_40 ( V_2 ) ;
if ( ! F_41 ( V_2 ) ) {
F_31 ( V_2 ) ;
} else {
F_17 ( V_2 ) -> V_63 . V_74 = 1 ;
F_3 ( F_4 ( V_2 ) , V_75 ) ;
if ( ! F_42 ( V_76 , & V_2 -> V_77 ) )
F_43 ( V_2 ) ;
}
F_44 ( V_2 ) ;
F_45 ( V_2 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = F_17 ( V_2 ) ;
struct V_9 * V_10 = F_6 ( V_2 ) ;
int V_78 ;
T_1 V_42 ;
if ( V_10 -> V_18 || ! F_47 ( V_2 ) ) {
V_26 -> V_79 = 0 ;
return;
}
V_42 = F_19 ( F_47 ( V_2 ) ) ;
if ( ! V_42 )
F_47 ( V_2 ) -> V_80 = V_10 -> V_81 ;
else if ( V_26 -> V_60 &&
( V_12 ) ( F_23 ( V_10 ) - V_42 ) >
F_24 ( V_26 -> V_60 ) )
goto abort;
V_78 = F_4 ( V_2 ) -> V_23 . V_57 ;
if ( F_30 ( V_2 , V_58 ) ) {
const bool V_21 = F_48 ( V_26 , V_15 ) < V_15 ;
V_78 = F_9 ( V_2 , V_21 ) ;
if ( ! V_21 && V_26 -> V_82 >= V_78 )
goto abort;
if ( F_5 ( V_2 , true ) )
return;
}
if ( V_26 -> V_79 > V_78 ) {
abort: F_1 ( V_2 ) ;
} else {
F_49 ( V_2 ) ;
}
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = F_17 ( V_2 ) ;
int V_83 = V_26 -> V_53 ? :
F_4 ( V_2 ) -> V_23 . V_84 + 1 ;
struct V_85 * V_86 ;
V_86 = F_6 ( V_2 ) -> V_87 ;
V_86 -> V_88 -> V_89 ( V_86 ) ;
if ( V_86 -> V_90 >= V_83 ) {
F_1 ( V_2 ) ;
return;
}
F_51 ( V_2 , V_86 ) ;
V_86 -> V_90 ++ ;
V_26 -> V_43 ++ ;
F_52 ( V_2 , V_91 ,
V_92 << V_86 -> V_90 , V_15 ) ;
}
void F_53 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_6 ( V_2 ) ;
struct V_27 * V_27 = F_4 ( V_2 ) ;
struct V_25 * V_26 = F_17 ( V_2 ) ;
if ( V_10 -> V_87 ) {
F_54 ( V_2 -> V_47 != V_93 &&
V_2 -> V_47 != V_94 ) ;
F_50 ( V_2 ) ;
return;
}
if ( ! V_10 -> V_18 )
goto V_66;
F_55 ( F_56 ( V_2 ) ) ;
V_10 -> V_95 = 0 ;
if ( ! V_10 -> V_17 && ! F_30 ( V_2 , V_58 ) &&
! ( ( 1 << V_2 -> V_47 ) & ( V_48 | V_49 ) ) ) {
struct V_96 * V_97 = F_57 ( V_2 ) ;
if ( V_2 -> V_98 == V_99 ) {
F_58 ( L_1 ,
& V_97 -> V_100 ,
F_59 ( V_97 -> V_101 ) ,
V_97 -> V_102 ,
V_10 -> V_103 , V_10 -> V_104 ) ;
}
#if F_60 ( V_105 )
else if ( V_2 -> V_98 == V_106 ) {
F_58 ( L_2 ,
& V_2 -> V_107 ,
F_59 ( V_97 -> V_101 ) ,
V_97 -> V_102 ,
V_10 -> V_103 , V_10 -> V_104 ) ;
}
#endif
if ( V_13 - V_10 -> V_108 > V_15 ) {
F_1 ( V_2 ) ;
goto V_66;
}
F_61 ( V_2 ) ;
F_62 ( V_2 , F_20 ( V_2 ) , 1 ) ;
F_63 ( V_2 ) ;
goto V_109;
}
if ( F_25 ( V_2 ) )
goto V_66;
if ( V_26 -> V_43 == 0 ) {
int V_110 ;
if ( V_26 -> V_111 == V_112 ) {
if ( F_64 ( V_10 ) )
V_110 = V_113 ;
else
V_110 = V_114 ;
} else if ( V_26 -> V_111 == V_115 ) {
V_110 = V_116 ;
} else if ( ( V_26 -> V_111 == V_117 ) ||
V_10 -> V_118 ) {
if ( F_64 ( V_10 ) )
V_110 = V_119 ;
else
V_110 = V_120 ;
} else {
V_110 = V_121 ;
}
F_3 ( F_4 ( V_2 ) , V_110 ) ;
}
F_61 ( V_2 ) ;
if ( F_62 ( V_2 , F_20 ( V_2 ) , 1 ) > 0 ) {
if ( ! V_26 -> V_43 )
V_26 -> V_43 = 1 ;
F_52 ( V_2 , V_91 ,
F_13 ( V_26 -> V_59 , V_122 ) ,
V_15 ) ;
goto V_66;
}
V_26 -> V_82 ++ ;
V_26 -> V_43 ++ ;
V_109:
if ( V_2 -> V_47 == V_123 &&
( V_10 -> V_124 || V_125 ) &&
F_65 ( V_10 ) &&
V_26 -> V_43 <= V_126 ) {
V_26 -> V_82 = 0 ;
V_26 -> V_59 = F_13 ( F_66 ( V_10 ) , V_15 ) ;
} else {
V_26 -> V_59 = F_13 ( V_26 -> V_59 << 1 , V_15 ) ;
}
F_52 ( V_2 , V_91 , V_26 -> V_59 , V_15 ) ;
if ( F_16 ( V_2 , V_27 -> V_23 . V_55 + 1 , 0 ) )
F_63 ( V_2 ) ;
V_66: ;
}
void F_67 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = F_17 ( V_2 ) ;
int V_127 ;
if ( ( ( 1 << V_2 -> V_47 ) & ( V_61 | V_62 ) ) ||
! V_26 -> V_128 )
goto V_66;
if ( F_33 ( V_26 -> V_129 , V_67 ) ) {
F_34 ( V_2 , & V_26 -> V_130 , V_26 -> V_129 ) ;
goto V_66;
}
F_68 ( F_6 ( V_2 ) ) ;
V_127 = V_26 -> V_128 ;
switch ( V_127 ) {
case V_131 :
F_69 ( V_2 ) ;
break;
case V_132 :
F_70 ( V_2 ) ;
break;
case V_91 :
V_26 -> V_128 = 0 ;
F_53 ( V_2 ) ;
break;
case V_133 :
V_26 -> V_128 = 0 ;
F_46 ( V_2 ) ;
break;
}
V_66:
F_38 ( V_2 ) ;
}
static void F_71 ( unsigned long V_73 )
{
struct V_1 * V_2 = (struct V_1 * ) V_73 ;
F_40 ( V_2 ) ;
if ( ! F_41 ( V_2 ) ) {
F_67 ( V_2 ) ;
} else {
if ( ! F_42 ( V_134 , & V_2 -> V_77 ) )
F_43 ( V_2 ) ;
}
F_44 ( V_2 ) ;
F_45 ( V_2 ) ;
}
void F_72 ( const struct V_85 * V_86 )
{
struct V_27 * V_27 = F_73 ( & F_74 ( V_86 ) -> V_135 ) ;
F_3 ( V_27 , V_121 ) ;
}
void F_75 ( struct V_1 * V_2 , int V_136 )
{
if ( ( 1 << V_2 -> V_47 ) & ( V_61 | V_62 ) )
return;
if ( V_136 && ! F_30 ( V_2 , V_137 ) )
F_76 ( V_2 , F_77 ( F_6 ( V_2 ) ) ) ;
else if ( ! V_136 )
F_78 ( V_2 ) ;
}
static void F_79 ( unsigned long V_73 )
{
struct V_1 * V_2 = (struct V_1 * ) V_73 ;
struct V_25 * V_26 = F_17 ( V_2 ) ;
struct V_9 * V_10 = F_6 ( V_2 ) ;
T_1 V_138 ;
F_40 ( V_2 ) ;
if ( F_41 ( V_2 ) ) {
F_76 ( V_2 , V_139 / 20 ) ;
goto V_66;
}
if ( V_2 -> V_47 == V_140 ) {
F_80 ( L_3 ) ;
goto V_66;
}
if ( V_2 -> V_47 == V_141 && F_30 ( V_2 , V_58 ) ) {
if ( V_10 -> V_142 >= 0 ) {
const int V_143 = F_81 ( V_2 ) - V_16 ;
if ( V_143 > 0 ) {
F_82 ( V_2 , V_141 , V_143 ) ;
goto V_66;
}
}
F_8 ( V_2 , V_19 ) ;
goto V_144;
}
if ( ! F_30 ( V_2 , V_137 ) ||
( ( 1 << V_2 -> V_47 ) & ( V_61 | V_48 ) ) )
goto V_66;
V_138 = F_77 ( V_10 ) ;
if ( V_10 -> V_18 || F_47 ( V_2 ) )
goto V_145;
V_138 = F_83 ( V_10 ) ;
if ( V_138 >= F_77 ( V_10 ) ) {
if ( ( V_26 -> V_60 != 0 &&
V_138 >= V_26 -> V_60 &&
V_26 -> V_79 > 0 ) ||
( V_26 -> V_60 == 0 &&
V_26 -> V_79 >= F_84 ( V_10 ) ) ) {
F_8 ( V_2 , V_19 ) ;
F_1 ( V_2 ) ;
goto V_66;
}
if ( F_85 ( V_2 , V_146 ) <= 0 ) {
V_26 -> V_79 ++ ;
V_138 = F_86 ( V_10 ) ;
} else {
V_138 = V_122 ;
}
} else {
V_138 = F_77 ( V_10 ) - V_138 ;
}
F_38 ( V_2 ) ;
V_145:
F_76 ( V_2 , V_138 ) ;
goto V_66;
V_144:
F_2 ( V_2 ) ;
V_66:
F_44 ( V_2 ) ;
F_45 ( V_2 ) ;
}
void F_87 ( struct V_1 * V_2 )
{
F_88 ( V_2 , & F_71 , & F_39 ,
& F_79 ) ;
F_89 ( & F_6 ( V_2 ) -> V_147 , V_148 ,
V_149 ) ;
F_6 ( V_2 ) -> V_147 . V_150 = V_151 ;
}
