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
V_25 -> V_29 . V_31 = V_13 ;
F_11 ( V_2 , V_25 -> V_32 ) ;
} else {
struct V_26 * V_26 = F_4 ( V_2 ) ;
struct V_9 * V_10 = F_6 ( V_2 ) ;
int V_33 ;
V_33 = F_12 ( V_2 , V_25 -> V_29 . V_34 ) >> 1 ;
V_33 = F_13 ( V_26 -> V_27 . V_35 , V_33 ) ;
V_33 = F_14 ( V_33 , 68 - V_10 -> V_36 ) ;
V_25 -> V_29 . V_34 = F_15 ( V_2 , V_33 ) ;
F_11 ( V_2 , V_25 -> V_32 ) ;
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
struct V_24 * V_25 = F_17 ( V_2 ) ;
struct V_9 * V_10 = F_6 ( V_2 ) ;
int V_47 ;
bool V_8 , V_39 = false ;
if ( ( 1 << V_2 -> V_48 ) & ( V_49 | V_50 ) ) {
if ( V_25 -> V_45 ) {
F_24 ( V_2 ) ;
if ( V_10 -> V_51 || V_10 -> V_52 )
F_25 ( V_2 , 0 , NULL , true , 0 ) ;
if ( V_10 -> V_52 )
F_3 ( F_4 ( V_2 ) ,
V_53 ) ;
}
V_47 = V_25 -> V_54 ? : V_55 ;
V_39 = true ;
} else {
if ( F_16 ( V_2 , V_56 , 0 , 0 ) ) {
F_10 ( V_25 , V_2 ) ;
F_24 ( V_2 ) ;
}
V_47 = V_57 ;
if ( F_26 ( V_2 , V_58 ) ) {
const int V_21 = V_25 -> V_59 < V_15 ;
V_47 = F_9 ( V_2 , V_21 ) ;
V_8 = V_21 ||
! F_16 ( V_2 , V_47 , 0 , 0 ) ;
if ( F_5 ( V_2 , V_8 ) )
return 1 ;
}
}
if ( F_16 ( V_2 , V_47 ,
V_39 ? 0 : V_25 -> V_60 , V_39 ) ) {
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
if ( V_2 -> V_48 == V_61 || ! ( V_25 -> V_62 . V_63 & V_64 ) )
goto V_65;
if ( F_29 ( V_25 -> V_62 . V_38 , V_66 ) ) {
F_30 ( V_2 , & V_25 -> V_67 , V_25 -> V_62 . V_38 ) ;
goto V_65;
}
V_25 -> V_62 . V_63 &= ~ V_64 ;
if ( ! F_31 ( & V_10 -> V_68 . V_69 ) ) {
struct V_70 * V_71 ;
F_3 ( F_4 ( V_2 ) , V_72 ) ;
while ( ( V_71 = F_32 ( & V_10 -> V_68 . V_69 ) ) != NULL )
F_33 ( V_2 , V_71 ) ;
V_10 -> V_68 . V_73 = 0 ;
}
if ( F_34 ( V_2 ) ) {
if ( ! V_25 -> V_62 . V_74 ) {
V_25 -> V_62 . V_75 = F_13 ( V_25 -> V_62 . V_75 << 1 , V_25 -> V_59 ) ;
} else {
V_25 -> V_62 . V_74 = 0 ;
V_25 -> V_62 . V_75 = V_76 ;
}
F_35 ( V_2 ) ;
F_3 ( F_4 ( V_2 ) , V_77 ) ;
}
V_65:
if ( F_36 ( V_2 ) )
F_37 ( V_2 ) ;
}
static void F_38 ( unsigned long V_78 )
{
struct V_1 * V_2 = (struct V_1 * ) V_78 ;
F_39 ( V_2 ) ;
if ( ! F_40 ( V_2 ) ) {
F_27 ( V_2 ) ;
} else {
F_17 ( V_2 ) -> V_62 . V_79 = 1 ;
F_3 ( F_4 ( V_2 ) , V_80 ) ;
if ( ! F_41 ( V_81 , & F_6 ( V_2 ) -> V_82 ) )
F_42 ( V_2 ) ;
}
F_43 ( V_2 ) ;
F_44 ( V_2 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = F_17 ( V_2 ) ;
struct V_9 * V_10 = F_6 ( V_2 ) ;
int V_83 ;
T_1 V_41 ;
if ( V_10 -> V_18 || ! F_46 ( V_2 ) ) {
V_25 -> V_84 = 0 ;
return;
}
V_41 = F_19 ( F_46 ( V_2 ) ) ;
if ( ! V_41 )
F_47 ( & F_46 ( V_2 ) -> V_85 ) ;
else if ( V_25 -> V_60 &&
( V_12 ) ( V_13 - V_41 ) > V_25 -> V_60 )
goto abort;
V_83 = V_57 ;
if ( F_26 ( V_2 , V_58 ) ) {
const int V_21 = F_48 ( V_25 , V_15 ) < V_15 ;
V_83 = F_9 ( V_2 , V_21 ) ;
if ( ! V_21 && V_25 -> V_86 >= V_83 )
goto abort;
if ( F_5 ( V_2 , true ) )
return;
}
if ( V_25 -> V_84 > V_83 ) {
abort: F_1 ( V_2 ) ;
} else {
F_49 ( V_2 ) ;
}
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = F_17 ( V_2 ) ;
int V_87 = V_25 -> V_54 ? :
V_88 + 1 ;
struct V_89 * V_90 ;
V_90 = F_6 ( V_2 ) -> V_91 ;
V_90 -> V_92 -> V_93 ( V_90 ) ;
if ( V_90 -> V_94 >= V_87 ) {
F_1 ( V_2 ) ;
return;
}
F_51 ( V_2 , V_90 ) ;
V_90 -> V_94 ++ ;
F_52 ( V_2 , V_95 ,
V_43 << V_90 -> V_94 , V_15 ) ;
}
void F_53 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_6 ( V_2 ) ;
struct V_24 * V_25 = F_17 ( V_2 ) ;
if ( V_10 -> V_91 ) {
F_54 ( V_2 -> V_48 != V_96 &&
V_2 -> V_48 != V_97 ) ;
F_50 ( V_2 ) ;
return;
}
if ( ! V_10 -> V_18 )
goto V_65;
F_55 ( F_56 ( V_2 ) ) ;
V_10 -> V_98 = 0 ;
if ( ! V_10 -> V_17 && ! F_26 ( V_2 , V_58 ) &&
! ( ( 1 << V_2 -> V_48 ) & ( V_49 | V_50 ) ) ) {
struct V_99 * V_100 = F_57 ( V_2 ) ;
if ( V_2 -> V_101 == V_102 ) {
F_58 ( L_1 ,
& V_100 -> V_103 ,
F_59 ( V_100 -> V_104 ) ,
V_100 -> V_105 ,
V_10 -> V_106 , V_10 -> V_107 ) ;
}
#if F_60 ( V_108 )
else if ( V_2 -> V_101 == V_109 ) {
F_58 ( L_2 ,
& V_2 -> V_110 ,
F_59 ( V_100 -> V_104 ) ,
V_100 -> V_105 ,
V_10 -> V_106 , V_10 -> V_107 ) ;
}
#endif
if ( V_13 - V_10 -> V_111 > V_15 ) {
F_1 ( V_2 ) ;
goto V_65;
}
F_61 ( V_2 ) ;
F_62 ( V_2 , F_20 ( V_2 ) ) ;
F_63 ( V_2 ) ;
goto V_112;
}
if ( F_23 ( V_2 ) )
goto V_65;
if ( V_25 -> V_45 == 0 ) {
int V_113 ;
if ( V_25 -> V_114 == V_115 ) {
if ( F_64 ( V_10 ) )
V_113 = V_116 ;
else
V_113 = V_117 ;
} else if ( V_25 -> V_114 == V_118 ) {
V_113 = V_119 ;
} else if ( ( V_25 -> V_114 == V_120 ) ||
V_10 -> V_121 ) {
if ( F_64 ( V_10 ) )
V_113 = V_122 ;
else
V_113 = V_123 ;
} else {
V_113 = V_124 ;
}
F_3 ( F_4 ( V_2 ) , V_113 ) ;
}
F_61 ( V_2 ) ;
if ( F_62 ( V_2 , F_20 ( V_2 ) ) > 0 ) {
if ( ! V_25 -> V_45 )
V_25 -> V_45 = 1 ;
F_52 ( V_2 , V_95 ,
F_13 ( V_25 -> V_59 , V_125 ) ,
V_15 ) ;
goto V_65;
}
V_25 -> V_86 ++ ;
V_25 -> V_45 ++ ;
V_112:
if ( V_2 -> V_48 == V_126 &&
( V_10 -> V_127 || V_128 ) &&
F_65 ( V_10 ) &&
V_25 -> V_45 <= V_129 ) {
V_25 -> V_86 = 0 ;
V_25 -> V_59 = F_13 ( F_66 ( V_10 ) , V_15 ) ;
} else {
V_25 -> V_59 = F_13 ( V_25 -> V_59 << 1 , V_15 ) ;
}
F_52 ( V_2 , V_95 , V_25 -> V_59 , V_15 ) ;
if ( F_16 ( V_2 , V_56 + 1 , 0 , 0 ) )
F_63 ( V_2 ) ;
V_65: ;
}
void F_67 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = F_17 ( V_2 ) ;
int V_130 ;
if ( V_2 -> V_48 == V_61 || ! V_25 -> V_131 )
goto V_65;
if ( F_29 ( V_25 -> V_132 , V_66 ) ) {
F_30 ( V_2 , & V_25 -> V_133 , V_25 -> V_132 ) ;
goto V_65;
}
V_130 = V_25 -> V_131 ;
switch ( V_130 ) {
case V_134 :
F_68 ( V_2 ) ;
break;
case V_135 :
F_69 ( V_2 ) ;
break;
case V_95 :
V_25 -> V_131 = 0 ;
F_53 ( V_2 ) ;
break;
case V_136 :
V_25 -> V_131 = 0 ;
F_45 ( V_2 ) ;
break;
}
V_65:
F_37 ( V_2 ) ;
}
static void F_70 ( unsigned long V_78 )
{
struct V_1 * V_2 = (struct V_1 * ) V_78 ;
F_39 ( V_2 ) ;
if ( ! F_40 ( V_2 ) ) {
F_67 ( V_2 ) ;
} else {
if ( ! F_41 ( V_137 , & F_6 ( V_2 ) -> V_82 ) )
F_42 ( V_2 ) ;
}
F_43 ( V_2 ) ;
F_44 ( V_2 ) ;
}
void F_71 ( const struct V_89 * V_90 )
{
struct V_26 * V_26 = F_72 ( & F_73 ( V_90 ) -> V_138 ) ;
F_3 ( V_26 , V_124 ) ;
}
void F_74 ( struct V_1 * V_2 , int V_139 )
{
if ( ( 1 << V_2 -> V_48 ) & ( V_140 | V_141 ) )
return;
if ( V_139 && ! F_26 ( V_2 , V_142 ) )
F_75 ( V_2 , F_76 ( F_6 ( V_2 ) ) ) ;
else if ( ! V_139 )
F_77 ( V_2 ) ;
}
static void F_78 ( unsigned long V_78 )
{
struct V_1 * V_2 = (struct V_1 * ) V_78 ;
struct V_24 * V_25 = F_17 ( V_2 ) ;
struct V_9 * V_10 = F_6 ( V_2 ) ;
T_1 V_143 ;
F_39 ( V_2 ) ;
if ( F_40 ( V_2 ) ) {
F_75 ( V_2 , V_144 / 20 ) ;
goto V_65;
}
if ( V_2 -> V_48 == V_145 ) {
F_79 ( L_3 ) ;
goto V_65;
}
if ( V_2 -> V_48 == V_146 && F_26 ( V_2 , V_58 ) ) {
if ( V_10 -> V_147 >= 0 ) {
const int V_148 = F_80 ( V_2 ) - V_16 ;
if ( V_148 > 0 ) {
F_81 ( V_2 , V_146 , V_148 ) ;
goto V_65;
}
}
F_8 ( V_2 , V_19 ) ;
goto V_149;
}
if ( ! F_26 ( V_2 , V_142 ) || V_2 -> V_48 == V_61 )
goto V_65;
V_143 = F_76 ( V_10 ) ;
if ( V_10 -> V_18 || F_46 ( V_2 ) )
goto V_150;
V_143 = F_82 ( V_10 ) ;
if ( V_143 >= F_76 ( V_10 ) ) {
if ( ( V_25 -> V_60 != 0 &&
V_143 >= V_25 -> V_60 &&
V_25 -> V_84 > 0 ) ||
( V_25 -> V_60 == 0 &&
V_25 -> V_84 >= F_83 ( V_10 ) ) ) {
F_8 ( V_2 , V_19 ) ;
F_1 ( V_2 ) ;
goto V_65;
}
if ( F_84 ( V_2 ) <= 0 ) {
V_25 -> V_84 ++ ;
V_143 = F_85 ( V_10 ) ;
} else {
V_143 = V_125 ;
}
} else {
V_143 = F_76 ( V_10 ) - V_143 ;
}
F_37 ( V_2 ) ;
V_150:
F_75 ( V_2 , V_143 ) ;
goto V_65;
V_149:
F_2 ( V_2 ) ;
V_65:
F_43 ( V_2 ) ;
F_44 ( V_2 ) ;
}
void F_86 ( struct V_1 * V_2 )
{
F_87 ( V_2 , & F_70 , & F_38 ,
& F_78 ) ;
}
