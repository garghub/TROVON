void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , & V_3 , & V_4 ,
& V_5 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
V_2 -> V_6 = V_2 -> V_7 ? : V_8 ;
V_2 -> V_9 ( V_2 ) ;
F_4 ( V_2 ) ;
F_5 ( F_6 ( V_2 ) , V_10 ) ;
}
static int F_7 ( struct V_1 * V_2 , int V_11 )
{
struct V_12 * V_13 = F_8 ( V_2 ) ;
int V_14 = 0 ;
if ( ( V_15 ) ( V_16 - V_13 -> V_17 ) > 2 * V_18 || ! V_11 )
V_14 ++ ;
if ( V_2 -> V_7 )
V_14 ++ ;
if ( F_9 ( V_2 , V_14 ) ) {
if ( F_10 () )
F_11 ( V_19 L_1 ) ;
if ( ( V_15 ) ( V_16 - V_13 -> V_17 ) <= V_20 ||
( ! V_13 -> V_21 && ! V_13 -> V_22 ) )
V_11 = 1 ;
if ( V_11 )
F_12 ( V_2 , V_23 ) ;
F_4 ( V_2 ) ;
F_5 ( F_6 ( V_2 ) , V_24 ) ;
return 1 ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , int V_25 )
{
int V_26 = V_27 ;
if ( V_2 -> V_7 && ! V_25 )
V_26 = 0 ;
if ( V_26 == 0 && V_25 )
V_26 = 8 ;
return V_26 ;
}
static void F_14 ( struct V_28 * V_29 , struct V_1 * V_2 )
{
if ( V_30 ) {
if ( ! V_29 -> V_31 . V_32 ) {
V_29 -> V_31 . V_32 = 1 ;
F_15 ( V_2 , V_29 -> V_33 ) ;
} else {
struct V_12 * V_13 = F_8 ( V_2 ) ;
int V_34 ;
V_34 = F_16 ( V_2 , V_29 -> V_31 . V_35 ) >> 1 ;
V_34 = F_17 ( V_36 , V_34 ) ;
V_34 = F_18 ( V_34 , 68 - V_13 -> V_37 ) ;
V_29 -> V_31 . V_35 = F_19 ( V_2 , V_34 ) ;
F_15 ( V_2 , V_29 -> V_33 ) ;
}
}
}
static bool F_20 ( struct V_1 * V_2 ,
unsigned int V_38 ,
unsigned int V_39 ,
bool V_40 )
{
unsigned int V_41 , V_42 ;
unsigned int V_43 = V_40 ? V_44 : V_45 ;
if ( ! F_21 ( V_2 ) -> V_46 )
return false ;
if ( F_22 ( ! F_8 ( V_2 ) -> V_47 ) )
V_42 = F_23 ( F_24 ( V_2 ) ) -> V_48 ;
else
V_42 = F_8 ( V_2 ) -> V_47 ;
if ( F_25 ( V_39 == 0 ) ) {
V_41 = F_26 ( V_18 / V_43 ) ;
if ( V_38 <= V_41 )
V_39 = ( ( 2 << V_38 ) - 1 ) * V_43 ;
else
V_39 = ( ( 2 << V_41 ) - 1 ) * V_43 +
( V_38 - V_41 ) * V_18 ;
}
return ( V_16 - V_42 ) >= V_39 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = F_21 ( V_2 ) ;
int V_49 ;
bool V_11 , V_40 = 0 ;
if ( ( 1 << V_2 -> V_50 ) & ( V_51 | V_52 ) ) {
if ( V_29 -> V_46 )
F_28 ( V_2 ) ;
V_49 = V_29 -> V_53 ? : V_54 ;
V_40 = 1 ;
} else {
if ( F_20 ( V_2 , V_55 , 0 , 0 ) ) {
F_14 ( V_29 , V_2 ) ;
F_28 ( V_2 ) ;
}
V_49 = V_56 ;
if ( F_29 ( V_2 , V_57 ) ) {
const int V_25 = ( V_29 -> V_58 < V_18 ) ;
V_49 = F_13 ( V_2 , V_25 ) ;
V_11 = V_25 ||
! F_20 ( V_2 , V_49 , 0 , 0 ) ;
if ( F_7 ( V_2 , V_11 ) )
return 1 ;
}
}
if ( F_20 ( V_2 , V_49 ,
V_40 ? 0 : V_29 -> V_59 , V_40 ) ) {
F_3 ( V_2 ) ;
return 1 ;
}
return 0 ;
}
static void V_4 ( unsigned long V_60 )
{
struct V_1 * V_2 = (struct V_1 * ) V_60 ;
struct V_12 * V_13 = F_8 ( V_2 ) ;
struct V_28 * V_29 = F_21 ( V_2 ) ;
F_30 ( V_2 ) ;
if ( F_31 ( V_2 ) ) {
V_29 -> V_61 . V_62 = 1 ;
F_5 ( F_6 ( V_2 ) , V_63 ) ;
F_32 ( V_2 , & V_29 -> V_64 , V_65 + V_66 ) ;
goto V_67;
}
F_33 ( V_2 ) ;
if ( V_2 -> V_50 == V_68 || ! ( V_29 -> V_61 . V_69 & V_70 ) )
goto V_71;
if ( F_34 ( V_29 -> V_61 . V_39 , V_65 ) ) {
F_32 ( V_2 , & V_29 -> V_64 , V_29 -> V_61 . V_39 ) ;
goto V_71;
}
V_29 -> V_61 . V_69 &= ~ V_70 ;
if ( ! F_35 ( & V_13 -> V_72 . V_73 ) ) {
struct V_74 * V_75 ;
F_5 ( F_6 ( V_2 ) , V_76 ) ;
while ( ( V_75 = F_36 ( & V_13 -> V_72 . V_73 ) ) != NULL )
F_37 ( V_2 , V_75 ) ;
V_13 -> V_72 . V_77 = 0 ;
}
if ( F_38 ( V_2 ) ) {
if ( ! V_29 -> V_61 . V_78 ) {
V_29 -> V_61 . V_79 = F_17 ( V_29 -> V_61 . V_79 << 1 , V_29 -> V_58 ) ;
} else {
V_29 -> V_61 . V_78 = 0 ;
V_29 -> V_61 . V_79 = V_80 ;
}
F_39 ( V_2 ) ;
F_5 ( F_6 ( V_2 ) , V_81 ) ;
}
V_71:
if ( V_82 )
F_40 ( V_2 ) ;
V_67:
F_41 ( V_2 ) ;
F_42 ( V_2 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = F_21 ( V_2 ) ;
struct V_12 * V_13 = F_8 ( V_2 ) ;
int V_83 ;
if ( V_13 -> V_22 || ! F_44 ( V_2 ) ) {
V_29 -> V_84 = 0 ;
return;
}
V_83 = V_56 ;
if ( F_29 ( V_2 , V_57 ) ) {
const int V_25 = ( ( V_29 -> V_58 << V_29 -> V_85 ) < V_18 ) ;
V_83 = F_13 ( V_2 , V_25 ) ;
if ( F_7 ( V_2 , V_25 || V_29 -> V_84 <= V_83 ) )
return;
}
if ( V_29 -> V_84 > V_83 ) {
F_3 ( V_2 ) ;
} else {
F_45 ( V_2 ) ;
}
}
void F_46 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_8 ( V_2 ) ;
struct V_28 * V_29 = F_21 ( V_2 ) ;
if ( ! V_13 -> V_22 )
goto V_71;
F_47 ( F_48 ( V_2 ) ) ;
if ( ! V_13 -> V_21 && ! F_29 ( V_2 , V_57 ) &&
! ( ( 1 << V_2 -> V_50 ) & ( V_51 | V_52 ) ) ) {
#ifdef F_49
struct V_86 * V_87 = F_50 ( V_2 ) ;
if ( V_2 -> V_88 == V_89 ) {
F_51 ( V_90 L_2 ,
& V_87 -> V_91 , F_52 ( V_87 -> V_92 ) ,
V_87 -> V_93 , V_13 -> V_94 , V_13 -> V_95 ) ;
}
#if F_53 ( V_96 ) || F_53 ( V_97 )
else if ( V_2 -> V_88 == V_98 ) {
struct V_99 * V_100 = F_54 ( V_2 ) ;
F_51 ( V_90 L_3 ,
& V_100 -> V_101 , F_52 ( V_87 -> V_92 ) ,
V_87 -> V_93 , V_13 -> V_94 , V_13 -> V_95 ) ;
}
#endif
#endif
if ( V_16 - V_13 -> V_102 > V_18 ) {
F_3 ( V_2 ) ;
goto V_71;
}
F_55 ( V_2 , 0 ) ;
F_56 ( V_2 , F_24 ( V_2 ) ) ;
F_57 ( V_2 ) ;
goto V_103;
}
if ( F_27 ( V_2 ) )
goto V_71;
if ( V_29 -> V_46 == 0 ) {
int V_104 ;
if ( V_29 -> V_105 == V_106 ) {
if ( F_58 ( V_13 ) )
V_104 = V_107 ;
else
V_104 = V_108 ;
} else if ( V_29 -> V_105 == V_109 ) {
V_104 = V_110 ;
} else if ( ( V_29 -> V_105 == V_111 ) ||
V_13 -> V_112 ) {
if ( F_58 ( V_13 ) )
V_104 = V_113 ;
else
V_104 = V_114 ;
} else {
V_104 = V_115 ;
}
F_5 ( F_6 ( V_2 ) , V_104 ) ;
}
if ( F_59 ( V_2 ) ) {
F_60 ( V_2 ) ;
} else {
F_55 ( V_2 , 0 ) ;
}
if ( F_56 ( V_2 , F_24 ( V_2 ) ) > 0 ) {
if ( ! V_29 -> V_46 )
V_29 -> V_46 = 1 ;
F_61 ( V_2 , V_116 ,
F_17 ( V_29 -> V_58 , V_117 ) ,
V_18 ) ;
goto V_71;
}
V_29 -> V_85 ++ ;
V_29 -> V_46 ++ ;
V_103:
if ( V_2 -> V_50 == V_118 &&
( V_13 -> V_119 || V_120 ) &&
F_62 ( V_13 ) &&
V_29 -> V_46 <= V_121 ) {
V_29 -> V_85 = 0 ;
V_29 -> V_58 = F_17 ( F_63 ( V_13 ) , V_18 ) ;
} else {
V_29 -> V_58 = F_17 ( V_29 -> V_58 << 1 , V_18 ) ;
}
F_61 ( V_2 , V_116 , V_29 -> V_58 , V_18 ) ;
if ( F_20 ( V_2 , V_55 + 1 , 0 , 0 ) )
F_57 ( V_2 ) ;
V_71: ;
}
static void V_3 ( unsigned long V_60 )
{
struct V_1 * V_2 = (struct V_1 * ) V_60 ;
struct V_28 * V_29 = F_21 ( V_2 ) ;
int V_122 ;
F_30 ( V_2 ) ;
if ( F_31 ( V_2 ) ) {
F_32 ( V_2 , & V_29 -> V_123 , V_65 + ( V_124 / 20 ) ) ;
goto V_67;
}
if ( V_2 -> V_50 == V_68 || ! V_29 -> V_125 )
goto V_71;
if ( F_34 ( V_29 -> V_126 , V_65 ) ) {
F_32 ( V_2 , & V_29 -> V_123 , V_29 -> V_126 ) ;
goto V_71;
}
V_122 = V_29 -> V_125 ;
V_29 -> V_125 = 0 ;
switch ( V_122 ) {
case V_116 :
F_46 ( V_2 ) ;
break;
case V_127 :
F_43 ( V_2 ) ;
break;
}
V_71:
F_40 ( V_2 ) ;
V_67:
F_41 ( V_2 ) ;
F_42 ( V_2 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
F_65 ( V_2 , V_128 ,
V_44 , V_18 ) ;
}
void F_66 ( struct V_1 * V_2 , struct V_129 * V_130 )
{
F_5 ( F_6 ( V_2 ) , V_115 ) ;
}
void F_67 ( struct V_1 * V_2 , int V_131 )
{
if ( ( 1 << V_2 -> V_50 ) & ( V_132 | V_133 ) )
return;
if ( V_131 && ! F_29 ( V_2 , V_134 ) )
F_68 ( V_2 , F_69 ( F_8 ( V_2 ) ) ) ;
else if ( ! V_131 )
F_70 ( V_2 ) ;
}
static void V_5 ( unsigned long V_60 )
{
struct V_1 * V_2 = (struct V_1 * ) V_60 ;
struct V_28 * V_29 = F_21 ( V_2 ) ;
struct V_12 * V_13 = F_8 ( V_2 ) ;
T_1 V_135 ;
F_30 ( V_2 ) ;
if ( F_31 ( V_2 ) ) {
F_68 ( V_2 , V_124 / 20 ) ;
goto V_71;
}
if ( V_2 -> V_50 == V_136 ) {
F_64 ( V_2 ) ;
goto V_71;
}
if ( V_2 -> V_50 == V_137 && F_29 ( V_2 , V_57 ) ) {
if ( V_13 -> V_138 >= 0 ) {
const int V_139 = F_71 ( V_2 ) - V_20 ;
if ( V_139 > 0 ) {
F_72 ( V_2 , V_137 , V_139 ) ;
goto V_71;
}
}
F_12 ( V_2 , V_23 ) ;
goto V_140;
}
if ( ! F_29 ( V_2 , V_134 ) || V_2 -> V_50 == V_68 )
goto V_71;
V_135 = F_69 ( V_13 ) ;
if ( V_13 -> V_22 || F_44 ( V_2 ) )
goto V_141;
V_135 = F_73 ( V_13 ) ;
if ( V_135 >= F_69 ( V_13 ) ) {
if ( ( V_29 -> V_59 != 0 &&
V_135 >= V_29 -> V_59 &&
V_29 -> V_84 > 0 ) ||
( V_29 -> V_59 == 0 &&
V_29 -> V_84 >= F_74 ( V_13 ) ) ) {
F_12 ( V_2 , V_23 ) ;
F_3 ( V_2 ) ;
goto V_71;
}
if ( F_75 ( V_2 ) <= 0 ) {
V_29 -> V_84 ++ ;
V_135 = F_76 ( V_13 ) ;
} else {
V_135 = V_117 ;
}
} else {
V_135 = F_69 ( V_13 ) - V_135 ;
}
F_40 ( V_2 ) ;
V_141:
F_68 ( V_2 , V_135 ) ;
goto V_71;
V_140:
F_4 ( V_2 ) ;
V_71:
F_41 ( V_2 ) ;
F_42 ( V_2 ) ;
}
