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
static int F_9 ( struct V_1 * V_2 , int V_21 )
{
int V_22 = V_23 ;
if ( V_2 -> V_4 && ! V_21 )
V_22 = 0 ;
if ( V_22 == 0 && V_21 )
V_22 = 8 ;
return V_22 ;
}
static void F_10 ( struct V_24 * V_25 , struct V_1 * V_2 )
{
struct V_26 * V_26 = F_4 ( V_2 ) ;
if ( V_26 -> V_27 . V_28 ) {
if ( ! V_25 -> V_29 . V_30 ) {
V_25 -> V_29 . V_30 = 1 ;
F_11 ( V_2 , V_25 -> V_31 ) ;
} else {
struct V_26 * V_26 = F_4 ( V_2 ) ;
struct V_9 * V_10 = F_6 ( V_2 ) ;
int V_32 ;
V_32 = F_12 ( V_2 , V_25 -> V_29 . V_33 ) >> 1 ;
V_32 = F_13 ( V_26 -> V_27 . V_34 , V_32 ) ;
V_32 = F_14 ( V_32 , 68 - V_10 -> V_35 ) ;
V_25 -> V_29 . V_33 = F_15 ( V_2 , V_32 ) ;
F_11 ( V_2 , V_25 -> V_31 ) ;
}
}
}
static bool F_16 ( struct V_1 * V_2 ,
unsigned int V_36 ,
unsigned int V_37 ,
bool V_38 )
{
unsigned int V_39 , V_40 ;
unsigned int V_41 = V_38 ? V_42 : V_43 ;
if ( ! F_17 ( V_2 ) -> V_44 )
return false ;
V_40 = F_6 ( V_2 ) -> V_45 ;
if ( F_18 ( ! V_40 ) )
V_40 = F_19 ( F_20 ( V_2 ) ) ;
if ( F_21 ( V_37 == 0 ) ) {
V_39 = F_22 ( V_15 / V_41 ) ;
if ( V_36 <= V_39 )
V_37 = ( ( 2 << V_36 ) - 1 ) * V_41 ;
else
V_37 = ( ( 2 << V_39 ) - 1 ) * V_41 +
( V_36 - V_39 ) * V_15 ;
}
return ( V_13 - V_40 ) >= V_37 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = F_17 ( V_2 ) ;
struct V_9 * V_10 = F_6 ( V_2 ) ;
int V_46 ;
bool V_8 , V_38 = false ;
if ( ( 1 << V_2 -> V_47 ) & ( V_48 | V_49 ) ) {
if ( V_25 -> V_44 ) {
F_24 ( V_2 ) ;
if ( V_10 -> V_50 || V_10 -> V_51 )
F_25 ( V_2 , 0 , NULL , true ) ;
if ( V_10 -> V_51 )
F_3 ( F_4 ( V_2 ) ,
V_52 ) ;
}
V_46 = V_25 -> V_53 ? : V_54 ;
V_38 = true ;
} else {
if ( F_16 ( V_2 , V_55 , 0 , 0 ) ) {
F_10 ( V_25 , V_2 ) ;
F_24 ( V_2 ) ;
}
V_46 = V_56 ;
if ( F_26 ( V_2 , V_57 ) ) {
const int V_21 = V_25 -> V_58 < V_15 ;
V_46 = F_9 ( V_2 , V_21 ) ;
V_8 = V_21 ||
! F_16 ( V_2 , V_46 , 0 , 0 ) ;
if ( F_5 ( V_2 , V_8 ) )
return 1 ;
}
}
if ( F_16 ( V_2 , V_46 ,
V_38 ? 0 : V_25 -> V_59 , V_38 ) ) {
F_1 ( V_2 ) ;
return 1 ;
}
return 0 ;
}
void F_27 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_6 ( V_2 ) ;
struct V_24 * V_25 = F_17 ( V_2 ) ;
F_28 ( V_2 ) ;
if ( V_2 -> V_47 == V_60 || ! ( V_25 -> V_61 . V_62 & V_63 ) )
goto V_64;
if ( F_29 ( V_25 -> V_61 . V_37 , V_65 ) ) {
F_30 ( V_2 , & V_25 -> V_66 , V_25 -> V_61 . V_37 ) ;
goto V_64;
}
V_25 -> V_61 . V_62 &= ~ V_63 ;
if ( ! F_31 ( & V_10 -> V_67 . V_68 ) ) {
struct V_69 * V_70 ;
F_3 ( F_4 ( V_2 ) , V_71 ) ;
while ( ( V_70 = F_32 ( & V_10 -> V_67 . V_68 ) ) != NULL )
F_33 ( V_2 , V_70 ) ;
V_10 -> V_67 . V_72 = 0 ;
}
if ( F_34 ( V_2 ) ) {
if ( ! V_25 -> V_61 . V_73 ) {
V_25 -> V_61 . V_74 = F_13 ( V_25 -> V_61 . V_74 << 1 , V_25 -> V_58 ) ;
} else {
V_25 -> V_61 . V_73 = 0 ;
V_25 -> V_61 . V_74 = V_75 ;
}
F_35 ( V_2 ) ;
F_3 ( F_4 ( V_2 ) , V_76 ) ;
}
V_64:
if ( F_36 ( V_2 ) )
F_37 ( V_2 ) ;
}
static void F_38 ( unsigned long V_77 )
{
struct V_1 * V_2 = (struct V_1 * ) V_77 ;
F_39 ( V_2 ) ;
if ( ! F_40 ( V_2 ) ) {
F_27 ( V_2 ) ;
} else {
F_17 ( V_2 ) -> V_61 . V_78 = 1 ;
F_3 ( F_4 ( V_2 ) , V_79 ) ;
if ( ! F_41 ( V_80 , & F_6 ( V_2 ) -> V_81 ) )
F_42 ( V_2 ) ;
}
F_43 ( V_2 ) ;
F_44 ( V_2 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = F_17 ( V_2 ) ;
struct V_9 * V_10 = F_6 ( V_2 ) ;
int V_82 ;
T_1 V_40 ;
if ( V_10 -> V_18 || ! F_46 ( V_2 ) ) {
V_25 -> V_83 = 0 ;
return;
}
V_40 = F_19 ( F_46 ( V_2 ) ) ;
if ( ! V_40 )
F_47 ( & F_46 ( V_2 ) -> V_84 ) ;
else if ( V_25 -> V_59 &&
( V_12 ) ( V_13 - V_40 ) > V_25 -> V_59 )
goto abort;
V_82 = V_56 ;
if ( F_26 ( V_2 , V_57 ) ) {
const int V_21 = F_48 ( V_25 , V_15 ) < V_15 ;
V_82 = F_9 ( V_2 , V_21 ) ;
if ( ! V_21 && V_25 -> V_85 >= V_82 )
goto abort;
if ( F_5 ( V_2 , true ) )
return;
}
if ( V_25 -> V_83 > V_82 ) {
abort: F_1 ( V_2 ) ;
} else {
F_49 ( V_2 ) ;
}
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = F_17 ( V_2 ) ;
int V_86 = V_25 -> V_53 ? :
V_87 + 1 ;
struct V_88 * V_89 ;
V_89 = F_6 ( V_2 ) -> V_90 ;
V_89 -> V_91 -> V_92 ( V_2 , V_89 ) ;
if ( V_89 -> V_93 >= V_86 ) {
F_1 ( V_2 ) ;
return;
}
F_51 ( V_2 , V_89 ) ;
V_89 -> V_93 ++ ;
F_52 ( V_2 , V_94 ,
V_42 << V_89 -> V_93 , V_15 ) ;
}
void F_53 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_6 ( V_2 ) ;
struct V_24 * V_25 = F_17 ( V_2 ) ;
if ( V_10 -> V_90 ) {
F_54 ( V_2 -> V_47 != V_95 &&
V_2 -> V_47 != V_96 ) ;
F_50 ( V_2 ) ;
return;
}
if ( ! V_10 -> V_18 )
goto V_64;
F_55 ( F_56 ( V_2 ) ) ;
V_10 -> V_97 = 0 ;
if ( ! V_10 -> V_17 && ! F_26 ( V_2 , V_57 ) &&
! ( ( 1 << V_2 -> V_47 ) & ( V_48 | V_49 ) ) ) {
struct V_98 * V_99 = F_57 ( V_2 ) ;
if ( V_2 -> V_100 == V_101 ) {
F_58 ( L_1 ,
& V_99 -> V_102 ,
F_59 ( V_99 -> V_103 ) ,
V_99 -> V_104 ,
V_10 -> V_105 , V_10 -> V_106 ) ;
}
#if F_60 ( V_107 )
else if ( V_2 -> V_100 == V_108 ) {
F_58 ( L_2 ,
& V_2 -> V_109 ,
F_59 ( V_99 -> V_103 ) ,
V_99 -> V_104 ,
V_10 -> V_105 , V_10 -> V_106 ) ;
}
#endif
if ( V_13 - V_10 -> V_110 > V_15 ) {
F_1 ( V_2 ) ;
goto V_64;
}
F_61 ( V_2 ) ;
F_62 ( V_2 , F_20 ( V_2 ) ) ;
F_63 ( V_2 ) ;
goto V_111;
}
if ( F_23 ( V_2 ) )
goto V_64;
if ( V_25 -> V_44 == 0 ) {
int V_112 ;
if ( V_25 -> V_113 == V_114 ) {
if ( F_64 ( V_10 ) )
V_112 = V_115 ;
else
V_112 = V_116 ;
} else if ( V_25 -> V_113 == V_117 ) {
V_112 = V_118 ;
} else if ( ( V_25 -> V_113 == V_119 ) ||
V_10 -> V_120 ) {
if ( F_64 ( V_10 ) )
V_112 = V_121 ;
else
V_112 = V_122 ;
} else {
V_112 = V_123 ;
}
F_3 ( F_4 ( V_2 ) , V_112 ) ;
}
F_61 ( V_2 ) ;
if ( F_62 ( V_2 , F_20 ( V_2 ) ) > 0 ) {
if ( ! V_25 -> V_44 )
V_25 -> V_44 = 1 ;
F_52 ( V_2 , V_94 ,
F_13 ( V_25 -> V_58 , V_124 ) ,
V_15 ) ;
goto V_64;
}
V_25 -> V_85 ++ ;
V_25 -> V_44 ++ ;
V_111:
if ( V_2 -> V_47 == V_125 &&
( V_10 -> V_126 || V_127 ) &&
F_65 ( V_10 ) &&
V_25 -> V_44 <= V_128 ) {
V_25 -> V_85 = 0 ;
V_25 -> V_58 = F_13 ( F_66 ( V_10 ) , V_15 ) ;
} else {
V_25 -> V_58 = F_13 ( V_25 -> V_58 << 1 , V_15 ) ;
}
F_52 ( V_2 , V_94 , V_25 -> V_58 , V_15 ) ;
if ( F_16 ( V_2 , V_55 + 1 , 0 , 0 ) )
F_63 ( V_2 ) ;
V_64: ;
}
void F_67 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = F_17 ( V_2 ) ;
int V_129 ;
if ( V_2 -> V_47 == V_60 || ! V_25 -> V_130 )
goto V_64;
if ( F_29 ( V_25 -> V_131 , V_65 ) ) {
F_30 ( V_2 , & V_25 -> V_132 , V_25 -> V_131 ) ;
goto V_64;
}
V_129 = V_25 -> V_130 ;
switch ( V_129 ) {
case V_133 :
F_68 ( V_2 ) ;
break;
case V_134 :
F_69 ( V_2 ) ;
break;
case V_94 :
V_25 -> V_130 = 0 ;
F_53 ( V_2 ) ;
break;
case V_135 :
V_25 -> V_130 = 0 ;
F_45 ( V_2 ) ;
break;
}
V_64:
F_37 ( V_2 ) ;
}
static void F_70 ( unsigned long V_77 )
{
struct V_1 * V_2 = (struct V_1 * ) V_77 ;
F_39 ( V_2 ) ;
if ( ! F_40 ( V_2 ) ) {
F_67 ( V_2 ) ;
} else {
if ( ! F_41 ( V_136 , & F_6 ( V_2 ) -> V_81 ) )
F_42 ( V_2 ) ;
}
F_43 ( V_2 ) ;
F_44 ( V_2 ) ;
}
static void F_71 ( struct V_1 * V_2 )
{
F_72 ( V_2 , V_137 ,
V_42 , V_15 ) ;
}
void F_73 ( struct V_1 * V_2 , struct V_88 * V_89 )
{
F_3 ( F_4 ( V_2 ) , V_123 ) ;
}
void F_74 ( struct V_1 * V_2 , int V_138 )
{
if ( ( 1 << V_2 -> V_47 ) & ( V_139 | V_140 ) )
return;
if ( V_138 && ! F_26 ( V_2 , V_141 ) )
F_75 ( V_2 , F_76 ( F_6 ( V_2 ) ) ) ;
else if ( ! V_138 )
F_77 ( V_2 ) ;
}
static void F_78 ( unsigned long V_77 )
{
struct V_1 * V_2 = (struct V_1 * ) V_77 ;
struct V_24 * V_25 = F_17 ( V_2 ) ;
struct V_9 * V_10 = F_6 ( V_2 ) ;
T_1 V_142 ;
F_39 ( V_2 ) ;
if ( F_40 ( V_2 ) ) {
F_75 ( V_2 , V_143 / 20 ) ;
goto V_64;
}
if ( V_2 -> V_47 == V_144 ) {
F_71 ( V_2 ) ;
goto V_64;
}
if ( V_2 -> V_47 == V_145 && F_26 ( V_2 , V_57 ) ) {
if ( V_10 -> V_146 >= 0 ) {
const int V_147 = F_79 ( V_2 ) - V_16 ;
if ( V_147 > 0 ) {
F_80 ( V_2 , V_145 , V_147 ) ;
goto V_64;
}
}
F_8 ( V_2 , V_19 ) ;
goto V_148;
}
if ( ! F_26 ( V_2 , V_141 ) || V_2 -> V_47 == V_60 )
goto V_64;
V_142 = F_76 ( V_10 ) ;
if ( V_10 -> V_18 || F_46 ( V_2 ) )
goto V_149;
V_142 = F_81 ( V_10 ) ;
if ( V_142 >= F_76 ( V_10 ) ) {
if ( ( V_25 -> V_59 != 0 &&
V_142 >= V_25 -> V_59 &&
V_25 -> V_83 > 0 ) ||
( V_25 -> V_59 == 0 &&
V_25 -> V_83 >= F_82 ( V_10 ) ) ) {
F_8 ( V_2 , V_19 ) ;
F_1 ( V_2 ) ;
goto V_64;
}
if ( F_83 ( V_2 ) <= 0 ) {
V_25 -> V_83 ++ ;
V_142 = F_84 ( V_10 ) ;
} else {
V_142 = V_124 ;
}
} else {
V_142 = F_76 ( V_10 ) - V_142 ;
}
F_37 ( V_2 ) ;
V_149:
F_75 ( V_2 , V_142 ) ;
goto V_64;
V_148:
F_2 ( V_2 ) ;
V_64:
F_43 ( V_2 ) ;
F_44 ( V_2 ) ;
}
void F_85 ( struct V_1 * V_2 )
{
F_86 ( V_2 , & F_70 , & F_38 ,
& F_78 ) ;
}
