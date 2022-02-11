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
}
V_47 = V_27 -> V_23 . V_61 ;
if ( F_27 ( V_2 , V_62 ) ) {
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
void F_28 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_6 ( V_2 ) ;
struct V_25 * V_26 = F_17 ( V_2 ) ;
F_29 ( V_2 ) ;
if ( V_2 -> V_48 == V_65 || ! ( V_26 -> V_66 . V_67 & V_68 ) )
goto V_69;
if ( F_30 ( V_26 -> V_66 . V_38 , V_70 ) ) {
F_31 ( V_2 , & V_26 -> V_71 , V_26 -> V_66 . V_38 ) ;
goto V_69;
}
V_26 -> V_66 . V_67 &= ~ V_68 ;
if ( ! F_32 ( & V_10 -> V_72 . V_73 ) ) {
struct V_74 * V_75 ;
F_3 ( F_4 ( V_2 ) , V_76 ) ;
while ( ( V_75 = F_33 ( & V_10 -> V_72 . V_73 ) ) != NULL )
F_34 ( V_2 , V_75 ) ;
V_10 -> V_72 . V_77 = 0 ;
}
if ( F_35 ( V_2 ) ) {
if ( ! V_26 -> V_66 . V_78 ) {
V_26 -> V_66 . V_79 = F_13 ( V_26 -> V_66 . V_79 << 1 , V_26 -> V_63 ) ;
} else {
V_26 -> V_66 . V_78 = 0 ;
V_26 -> V_66 . V_79 = V_80 ;
}
F_36 ( V_2 ) ;
F_3 ( F_4 ( V_2 ) , V_81 ) ;
}
V_69:
if ( F_37 ( V_2 ) )
F_38 ( V_2 ) ;
}
static void F_39 ( unsigned long V_82 )
{
struct V_1 * V_2 = (struct V_1 * ) V_82 ;
F_40 ( V_2 ) ;
if ( ! F_41 ( V_2 ) ) {
F_28 ( V_2 ) ;
} else {
F_17 ( V_2 ) -> V_66 . V_83 = 1 ;
F_3 ( F_4 ( V_2 ) , V_84 ) ;
if ( ! F_42 ( V_85 , & F_6 ( V_2 ) -> V_86 ) )
F_43 ( V_2 ) ;
}
F_44 ( V_2 ) ;
F_45 ( V_2 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = F_17 ( V_2 ) ;
struct V_9 * V_10 = F_6 ( V_2 ) ;
int V_87 ;
T_1 V_41 ;
if ( V_10 -> V_18 || ! F_47 ( V_2 ) ) {
V_26 -> V_88 = 0 ;
return;
}
V_41 = F_19 ( F_47 ( V_2 ) ) ;
if ( ! V_41 )
F_48 ( & F_47 ( V_2 ) -> V_89 ) ;
else if ( V_26 -> V_64 &&
( V_12 ) ( V_13 - V_41 ) > V_26 -> V_64 )
goto abort;
V_87 = F_4 ( V_2 ) -> V_23 . V_61 ;
if ( F_27 ( V_2 , V_62 ) ) {
const bool V_21 = F_49 ( V_26 , V_15 ) < V_15 ;
V_87 = F_9 ( V_2 , V_21 ) ;
if ( ! V_21 && V_26 -> V_90 >= V_87 )
goto abort;
if ( F_5 ( V_2 , true ) )
return;
}
if ( V_26 -> V_88 > V_87 ) {
abort: F_1 ( V_2 ) ;
} else {
F_50 ( V_2 ) ;
}
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = F_17 ( V_2 ) ;
int V_91 = V_26 -> V_54 ? :
F_4 ( V_2 ) -> V_23 . V_92 + 1 ;
struct V_93 * V_94 ;
V_94 = F_6 ( V_2 ) -> V_95 ;
V_94 -> V_96 -> V_97 ( V_94 ) ;
if ( V_94 -> V_98 >= V_91 ) {
F_1 ( V_2 ) ;
return;
}
F_52 ( V_2 , V_94 ) ;
V_94 -> V_98 ++ ;
V_26 -> V_45 ++ ;
F_53 ( V_2 , V_99 ,
V_43 << V_94 -> V_98 , V_15 ) ;
}
void F_54 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_6 ( V_2 ) ;
struct V_27 * V_27 = F_4 ( V_2 ) ;
struct V_25 * V_26 = F_17 ( V_2 ) ;
if ( V_10 -> V_95 ) {
F_55 ( V_2 -> V_48 != V_100 &&
V_2 -> V_48 != V_101 ) ;
F_51 ( V_2 ) ;
return;
}
if ( ! V_10 -> V_18 )
goto V_69;
F_56 ( F_57 ( V_2 ) ) ;
V_10 -> V_102 = 0 ;
if ( ! V_10 -> V_17 && ! F_27 ( V_2 , V_62 ) &&
! ( ( 1 << V_2 -> V_48 ) & ( V_49 | V_50 ) ) ) {
struct V_103 * V_104 = F_58 ( V_2 ) ;
if ( V_2 -> V_105 == V_106 ) {
F_59 ( L_1 ,
& V_104 -> V_107 ,
F_60 ( V_104 -> V_108 ) ,
V_104 -> V_109 ,
V_10 -> V_110 , V_10 -> V_111 ) ;
}
#if F_61 ( V_112 )
else if ( V_2 -> V_105 == V_113 ) {
F_59 ( L_2 ,
& V_2 -> V_114 ,
F_60 ( V_104 -> V_108 ) ,
V_104 -> V_109 ,
V_10 -> V_110 , V_10 -> V_111 ) ;
}
#endif
if ( V_13 - V_10 -> V_115 > V_15 ) {
F_1 ( V_2 ) ;
goto V_69;
}
F_62 ( V_2 ) ;
F_63 ( V_2 , F_20 ( V_2 ) , 1 ) ;
F_64 ( V_2 ) ;
goto V_116;
}
if ( F_23 ( V_2 ) )
goto V_69;
if ( V_26 -> V_45 == 0 ) {
int V_117 ;
if ( V_26 -> V_118 == V_119 ) {
if ( F_65 ( V_10 ) )
V_117 = V_120 ;
else
V_117 = V_121 ;
} else if ( V_26 -> V_118 == V_122 ) {
V_117 = V_123 ;
} else if ( ( V_26 -> V_118 == V_124 ) ||
V_10 -> V_125 ) {
if ( F_65 ( V_10 ) )
V_117 = V_126 ;
else
V_117 = V_127 ;
} else {
V_117 = V_128 ;
}
F_3 ( F_4 ( V_2 ) , V_117 ) ;
}
F_62 ( V_2 ) ;
if ( F_63 ( V_2 , F_20 ( V_2 ) , 1 ) > 0 ) {
if ( ! V_26 -> V_45 )
V_26 -> V_45 = 1 ;
F_53 ( V_2 , V_99 ,
F_13 ( V_26 -> V_63 , V_129 ) ,
V_15 ) ;
goto V_69;
}
V_26 -> V_90 ++ ;
V_26 -> V_45 ++ ;
V_116:
if ( V_2 -> V_48 == V_130 &&
( V_10 -> V_131 || V_132 ) &&
F_66 ( V_10 ) &&
V_26 -> V_45 <= V_133 ) {
V_26 -> V_90 = 0 ;
V_26 -> V_63 = F_13 ( F_67 ( V_10 ) , V_15 ) ;
} else {
V_26 -> V_63 = F_13 ( V_26 -> V_63 << 1 , V_15 ) ;
}
F_53 ( V_2 , V_99 , V_26 -> V_63 , V_15 ) ;
if ( F_16 ( V_2 , V_27 -> V_23 . V_56 + 1 , 0 , 0 ) )
F_64 ( V_2 ) ;
V_69: ;
}
void F_68 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = F_17 ( V_2 ) ;
int V_134 ;
if ( V_2 -> V_48 == V_65 || ! V_26 -> V_135 )
goto V_69;
if ( F_30 ( V_26 -> V_136 , V_70 ) ) {
F_31 ( V_2 , & V_26 -> V_137 , V_26 -> V_136 ) ;
goto V_69;
}
V_134 = V_26 -> V_135 ;
switch ( V_134 ) {
case V_138 :
F_69 ( V_2 ) ;
break;
case V_139 :
F_70 ( V_2 ) ;
break;
case V_99 :
V_26 -> V_135 = 0 ;
F_54 ( V_2 ) ;
break;
case V_140 :
V_26 -> V_135 = 0 ;
F_46 ( V_2 ) ;
break;
}
V_69:
F_38 ( V_2 ) ;
}
static void F_71 ( unsigned long V_82 )
{
struct V_1 * V_2 = (struct V_1 * ) V_82 ;
F_40 ( V_2 ) ;
if ( ! F_41 ( V_2 ) ) {
F_68 ( V_2 ) ;
} else {
if ( ! F_42 ( V_141 , & F_6 ( V_2 ) -> V_86 ) )
F_43 ( V_2 ) ;
}
F_44 ( V_2 ) ;
F_45 ( V_2 ) ;
}
void F_72 ( const struct V_93 * V_94 )
{
struct V_27 * V_27 = F_73 ( & F_74 ( V_94 ) -> V_142 ) ;
F_3 ( V_27 , V_128 ) ;
}
void F_75 ( struct V_1 * V_2 , int V_143 )
{
if ( ( 1 << V_2 -> V_48 ) & ( V_144 | V_145 ) )
return;
if ( V_143 && ! F_27 ( V_2 , V_146 ) )
F_76 ( V_2 , F_77 ( F_6 ( V_2 ) ) ) ;
else if ( ! V_143 )
F_78 ( V_2 ) ;
}
static void F_79 ( unsigned long V_82 )
{
struct V_1 * V_2 = (struct V_1 * ) V_82 ;
struct V_25 * V_26 = F_17 ( V_2 ) ;
struct V_9 * V_10 = F_6 ( V_2 ) ;
T_1 V_147 ;
F_40 ( V_2 ) ;
if ( F_41 ( V_2 ) ) {
F_76 ( V_2 , V_148 / 20 ) ;
goto V_69;
}
if ( V_2 -> V_48 == V_149 ) {
F_80 ( L_3 ) ;
goto V_69;
}
if ( V_2 -> V_48 == V_150 && F_27 ( V_2 , V_62 ) ) {
if ( V_10 -> V_151 >= 0 ) {
const int V_152 = F_81 ( V_2 ) - V_16 ;
if ( V_152 > 0 ) {
F_82 ( V_2 , V_150 , V_152 ) ;
goto V_69;
}
}
F_8 ( V_2 , V_19 ) ;
goto V_153;
}
if ( ! F_27 ( V_2 , V_146 ) || V_2 -> V_48 == V_65 )
goto V_69;
V_147 = F_77 ( V_10 ) ;
if ( V_10 -> V_18 || F_47 ( V_2 ) )
goto V_154;
V_147 = F_83 ( V_10 ) ;
if ( V_147 >= F_77 ( V_10 ) ) {
if ( ( V_26 -> V_64 != 0 &&
V_147 >= V_26 -> V_64 &&
V_26 -> V_88 > 0 ) ||
( V_26 -> V_64 == 0 &&
V_26 -> V_88 >= F_84 ( V_10 ) ) ) {
F_8 ( V_2 , V_19 ) ;
F_1 ( V_2 ) ;
goto V_69;
}
if ( F_85 ( V_2 , V_155 ) <= 0 ) {
V_26 -> V_88 ++ ;
V_147 = F_86 ( V_10 ) ;
} else {
V_147 = V_129 ;
}
} else {
V_147 = F_77 ( V_10 ) - V_147 ;
}
F_38 ( V_2 ) ;
V_154:
F_76 ( V_2 , V_147 ) ;
goto V_69;
V_153:
F_2 ( V_2 ) ;
V_69:
F_44 ( V_2 ) ;
F_45 ( V_2 ) ;
}
void F_87 ( struct V_1 * V_2 )
{
F_88 ( V_2 , & F_71 , & F_39 ,
& F_79 ) ;
}
