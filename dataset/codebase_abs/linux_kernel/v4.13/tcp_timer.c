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
struct V_9 * V_10 = F_6 ( V_2 ) ;
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
if ( ! F_35 ( & V_10 -> V_69 . V_70 ) ) {
struct V_71 * V_72 ;
F_3 ( F_4 ( V_2 ) , V_73 ) ;
while ( ( V_72 = F_36 ( & V_10 -> V_69 . V_70 ) ) != NULL )
F_37 ( V_2 , V_72 ) ;
V_10 -> V_69 . V_74 = 0 ;
}
if ( F_38 ( V_2 ) ) {
if ( ! V_26 -> V_63 . V_75 ) {
V_26 -> V_63 . V_76 = F_13 ( V_26 -> V_63 . V_76 << 1 , V_26 -> V_59 ) ;
} else {
V_26 -> V_63 . V_75 = 0 ;
V_26 -> V_63 . V_76 = V_77 ;
}
F_39 ( V_2 ) ;
F_3 ( F_4 ( V_2 ) , V_78 ) ;
}
V_66:
if ( F_40 ( V_2 ) )
F_41 ( V_2 ) ;
}
static void F_42 ( unsigned long V_79 )
{
struct V_1 * V_2 = (struct V_1 * ) V_79 ;
F_43 ( V_2 ) ;
if ( ! F_44 ( V_2 ) ) {
F_31 ( V_2 ) ;
} else {
F_17 ( V_2 ) -> V_63 . V_80 = 1 ;
F_3 ( F_4 ( V_2 ) , V_81 ) ;
if ( ! F_45 ( V_82 , & V_2 -> V_83 ) )
F_46 ( V_2 ) ;
}
F_47 ( V_2 ) ;
F_48 ( V_2 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = F_17 ( V_2 ) ;
struct V_9 * V_10 = F_6 ( V_2 ) ;
int V_84 ;
T_1 V_42 ;
if ( V_10 -> V_18 || ! F_50 ( V_2 ) ) {
V_26 -> V_85 = 0 ;
return;
}
V_42 = F_19 ( F_50 ( V_2 ) ) ;
if ( ! V_42 )
F_50 ( V_2 ) -> V_86 = V_10 -> V_87 ;
else if ( V_26 -> V_60 &&
( V_12 ) ( F_23 ( V_10 ) - V_42 ) >
F_24 ( V_26 -> V_60 ) )
goto abort;
V_84 = F_4 ( V_2 ) -> V_23 . V_57 ;
if ( F_30 ( V_2 , V_58 ) ) {
const bool V_21 = F_51 ( V_26 , V_15 ) < V_15 ;
V_84 = F_9 ( V_2 , V_21 ) ;
if ( ! V_21 && V_26 -> V_88 >= V_84 )
goto abort;
if ( F_5 ( V_2 , true ) )
return;
}
if ( V_26 -> V_85 > V_84 ) {
abort: F_1 ( V_2 ) ;
} else {
F_52 ( V_2 ) ;
}
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = F_17 ( V_2 ) ;
int V_89 = V_26 -> V_53 ? :
F_4 ( V_2 ) -> V_23 . V_90 + 1 ;
struct V_91 * V_92 ;
V_92 = F_6 ( V_2 ) -> V_93 ;
V_92 -> V_94 -> V_95 ( V_92 ) ;
if ( V_92 -> V_96 >= V_89 ) {
F_1 ( V_2 ) ;
return;
}
F_54 ( V_2 , V_92 ) ;
V_92 -> V_96 ++ ;
V_26 -> V_43 ++ ;
F_55 ( V_2 , V_97 ,
V_98 << V_92 -> V_96 , V_15 ) ;
}
void F_56 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_6 ( V_2 ) ;
struct V_27 * V_27 = F_4 ( V_2 ) ;
struct V_25 * V_26 = F_17 ( V_2 ) ;
if ( V_10 -> V_93 ) {
F_57 ( V_2 -> V_47 != V_99 &&
V_2 -> V_47 != V_100 ) ;
F_53 ( V_2 ) ;
return;
}
if ( ! V_10 -> V_18 )
goto V_66;
F_58 ( F_59 ( V_2 ) ) ;
V_10 -> V_101 = 0 ;
if ( ! V_10 -> V_17 && ! F_30 ( V_2 , V_58 ) &&
! ( ( 1 << V_2 -> V_47 ) & ( V_48 | V_49 ) ) ) {
struct V_102 * V_103 = F_60 ( V_2 ) ;
if ( V_2 -> V_104 == V_105 ) {
F_61 ( L_1 ,
& V_103 -> V_106 ,
F_62 ( V_103 -> V_107 ) ,
V_103 -> V_108 ,
V_10 -> V_109 , V_10 -> V_110 ) ;
}
#if F_63 ( V_111 )
else if ( V_2 -> V_104 == V_112 ) {
F_61 ( L_2 ,
& V_2 -> V_113 ,
F_62 ( V_103 -> V_107 ) ,
V_103 -> V_108 ,
V_10 -> V_109 , V_10 -> V_110 ) ;
}
#endif
if ( V_13 - V_10 -> V_114 > V_15 ) {
F_1 ( V_2 ) ;
goto V_66;
}
F_64 ( V_2 ) ;
F_65 ( V_2 , F_20 ( V_2 ) , 1 ) ;
F_66 ( V_2 ) ;
goto V_115;
}
if ( F_25 ( V_2 ) )
goto V_66;
if ( V_26 -> V_43 == 0 ) {
int V_116 ;
if ( V_26 -> V_117 == V_118 ) {
if ( F_67 ( V_10 ) )
V_116 = V_119 ;
else
V_116 = V_120 ;
} else if ( V_26 -> V_117 == V_121 ) {
V_116 = V_122 ;
} else if ( ( V_26 -> V_117 == V_123 ) ||
V_10 -> V_124 ) {
if ( F_67 ( V_10 ) )
V_116 = V_125 ;
else
V_116 = V_126 ;
} else {
V_116 = V_127 ;
}
F_3 ( F_4 ( V_2 ) , V_116 ) ;
}
F_64 ( V_2 ) ;
if ( F_65 ( V_2 , F_20 ( V_2 ) , 1 ) > 0 ) {
if ( ! V_26 -> V_43 )
V_26 -> V_43 = 1 ;
F_55 ( V_2 , V_97 ,
F_13 ( V_26 -> V_59 , V_128 ) ,
V_15 ) ;
goto V_66;
}
V_26 -> V_88 ++ ;
V_26 -> V_43 ++ ;
V_115:
if ( V_2 -> V_47 == V_129 &&
( V_10 -> V_130 || V_131 ) &&
F_68 ( V_10 ) &&
V_26 -> V_43 <= V_132 ) {
V_26 -> V_88 = 0 ;
V_26 -> V_59 = F_13 ( F_69 ( V_10 ) , V_15 ) ;
} else {
V_26 -> V_59 = F_13 ( V_26 -> V_59 << 1 , V_15 ) ;
}
F_55 ( V_2 , V_97 , V_26 -> V_59 , V_15 ) ;
if ( F_16 ( V_2 , V_27 -> V_23 . V_55 + 1 , 0 ) )
F_66 ( V_2 ) ;
V_66: ;
}
void F_70 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = F_17 ( V_2 ) ;
int V_133 ;
if ( ( ( 1 << V_2 -> V_47 ) & ( V_61 | V_62 ) ) ||
! V_26 -> V_134 )
goto V_66;
if ( F_33 ( V_26 -> V_135 , V_67 ) ) {
F_34 ( V_2 , & V_26 -> V_136 , V_26 -> V_135 ) ;
goto V_66;
}
F_71 ( F_6 ( V_2 ) ) ;
V_133 = V_26 -> V_134 ;
switch ( V_133 ) {
case V_137 :
F_72 ( V_2 ) ;
break;
case V_138 :
F_73 ( V_2 ) ;
break;
case V_97 :
V_26 -> V_134 = 0 ;
F_56 ( V_2 ) ;
break;
case V_139 :
V_26 -> V_134 = 0 ;
F_49 ( V_2 ) ;
break;
}
V_66:
F_41 ( V_2 ) ;
}
static void F_74 ( unsigned long V_79 )
{
struct V_1 * V_2 = (struct V_1 * ) V_79 ;
F_43 ( V_2 ) ;
if ( ! F_44 ( V_2 ) ) {
F_70 ( V_2 ) ;
} else {
if ( ! F_45 ( V_140 , & V_2 -> V_83 ) )
F_46 ( V_2 ) ;
}
F_47 ( V_2 ) ;
F_48 ( V_2 ) ;
}
void F_75 ( const struct V_91 * V_92 )
{
struct V_27 * V_27 = F_76 ( & F_77 ( V_92 ) -> V_141 ) ;
F_3 ( V_27 , V_127 ) ;
}
void F_78 ( struct V_1 * V_2 , int V_142 )
{
if ( ( 1 << V_2 -> V_47 ) & ( V_61 | V_62 ) )
return;
if ( V_142 && ! F_30 ( V_2 , V_143 ) )
F_79 ( V_2 , F_80 ( F_6 ( V_2 ) ) ) ;
else if ( ! V_142 )
F_81 ( V_2 ) ;
}
static void F_82 ( unsigned long V_79 )
{
struct V_1 * V_2 = (struct V_1 * ) V_79 ;
struct V_25 * V_26 = F_17 ( V_2 ) ;
struct V_9 * V_10 = F_6 ( V_2 ) ;
T_1 V_144 ;
F_43 ( V_2 ) ;
if ( F_44 ( V_2 ) ) {
F_79 ( V_2 , V_145 / 20 ) ;
goto V_66;
}
if ( V_2 -> V_47 == V_146 ) {
F_83 ( L_3 ) ;
goto V_66;
}
if ( V_2 -> V_47 == V_147 && F_30 ( V_2 , V_58 ) ) {
if ( V_10 -> V_148 >= 0 ) {
const int V_149 = F_84 ( V_2 ) - V_16 ;
if ( V_149 > 0 ) {
F_85 ( V_2 , V_147 , V_149 ) ;
goto V_66;
}
}
F_8 ( V_2 , V_19 ) ;
goto V_150;
}
if ( ! F_30 ( V_2 , V_143 ) ||
( ( 1 << V_2 -> V_47 ) & ( V_61 | V_48 ) ) )
goto V_66;
V_144 = F_80 ( V_10 ) ;
if ( V_10 -> V_18 || F_50 ( V_2 ) )
goto V_151;
V_144 = F_86 ( V_10 ) ;
if ( V_144 >= F_80 ( V_10 ) ) {
if ( ( V_26 -> V_60 != 0 &&
V_144 >= V_26 -> V_60 &&
V_26 -> V_85 > 0 ) ||
( V_26 -> V_60 == 0 &&
V_26 -> V_85 >= F_87 ( V_10 ) ) ) {
F_8 ( V_2 , V_19 ) ;
F_1 ( V_2 ) ;
goto V_66;
}
if ( F_88 ( V_2 , V_152 ) <= 0 ) {
V_26 -> V_85 ++ ;
V_144 = F_89 ( V_10 ) ;
} else {
V_144 = V_128 ;
}
} else {
V_144 = F_80 ( V_10 ) - V_144 ;
}
F_41 ( V_2 ) ;
V_151:
F_79 ( V_2 , V_144 ) ;
goto V_66;
V_150:
F_2 ( V_2 ) ;
V_66:
F_47 ( V_2 ) ;
F_48 ( V_2 ) ;
}
void F_90 ( struct V_1 * V_2 )
{
F_91 ( V_2 , & F_74 , & F_42 ,
& F_82 ) ;
F_92 ( & F_6 ( V_2 ) -> V_153 , V_154 ,
V_155 ) ;
F_6 ( V_2 ) -> V_153 . V_156 = V_157 ;
}
