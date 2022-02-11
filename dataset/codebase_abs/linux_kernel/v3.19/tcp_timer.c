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
if ( V_26 ) {
if ( ! V_25 -> V_27 . V_28 ) {
V_25 -> V_27 . V_28 = 1 ;
F_11 ( V_2 , V_25 -> V_29 ) ;
} else {
struct V_9 * V_10 = F_6 ( V_2 ) ;
int V_30 ;
V_30 = F_12 ( V_2 , V_25 -> V_27 . V_31 ) >> 1 ;
V_30 = F_13 ( V_32 , V_30 ) ;
V_30 = F_14 ( V_30 , 68 - V_10 -> V_33 ) ;
V_25 -> V_27 . V_31 = F_15 ( V_2 , V_30 ) ;
F_11 ( V_2 , V_25 -> V_29 ) ;
}
}
}
static bool F_16 ( struct V_1 * V_2 ,
unsigned int V_34 ,
unsigned int V_35 ,
bool V_36 )
{
unsigned int V_37 , V_38 ;
unsigned int V_39 = V_36 ? V_40 : V_41 ;
if ( ! F_17 ( V_2 ) -> V_42 )
return false ;
V_38 = F_6 ( V_2 ) -> V_43 ;
if ( F_18 ( ! V_38 ) )
V_38 = F_19 ( F_20 ( V_2 ) ) ;
if ( F_21 ( V_35 == 0 ) ) {
V_37 = F_22 ( V_15 / V_39 ) ;
if ( V_34 <= V_37 )
V_35 = ( ( 2 << V_34 ) - 1 ) * V_39 ;
else
V_35 = ( ( 2 << V_37 ) - 1 ) * V_39 +
( V_34 - V_37 ) * V_15 ;
}
return ( V_13 - V_38 ) >= V_35 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = F_17 ( V_2 ) ;
struct V_9 * V_10 = F_6 ( V_2 ) ;
int V_44 ;
bool V_8 , V_36 = false ;
if ( ( 1 << V_2 -> V_45 ) & ( V_46 | V_47 ) ) {
if ( V_25 -> V_42 ) {
F_24 ( V_2 ) ;
if ( V_10 -> V_48 || V_10 -> V_49 )
F_25 ( V_2 , 0 , NULL , true ) ;
if ( V_10 -> V_49 )
F_3 ( F_4 ( V_2 ) ,
V_50 ) ;
}
V_44 = V_25 -> V_51 ? : V_52 ;
V_36 = true ;
} else {
if ( F_16 ( V_2 , V_53 , 0 , 0 ) ) {
F_10 ( V_25 , V_2 ) ;
F_24 ( V_2 ) ;
}
V_44 = V_54 ;
if ( F_26 ( V_2 , V_55 ) ) {
const int V_21 = V_25 -> V_56 < V_15 ;
V_44 = F_9 ( V_2 , V_21 ) ;
V_8 = V_21 ||
! F_16 ( V_2 , V_44 , 0 , 0 ) ;
if ( F_5 ( V_2 , V_8 ) )
return 1 ;
}
}
if ( F_16 ( V_2 , V_44 ,
V_36 ? 0 : V_25 -> V_57 , V_36 ) ) {
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
if ( V_2 -> V_45 == V_58 || ! ( V_25 -> V_59 . V_60 & V_61 ) )
goto V_62;
if ( F_29 ( V_25 -> V_59 . V_35 , V_63 ) ) {
F_30 ( V_2 , & V_25 -> V_64 , V_25 -> V_59 . V_35 ) ;
goto V_62;
}
V_25 -> V_59 . V_60 &= ~ V_61 ;
if ( ! F_31 ( & V_10 -> V_65 . V_66 ) ) {
struct V_67 * V_68 ;
F_3 ( F_4 ( V_2 ) , V_69 ) ;
while ( ( V_68 = F_32 ( & V_10 -> V_65 . V_66 ) ) != NULL )
F_33 ( V_2 , V_68 ) ;
V_10 -> V_65 . V_70 = 0 ;
}
if ( F_34 ( V_2 ) ) {
if ( ! V_25 -> V_59 . V_71 ) {
V_25 -> V_59 . V_72 = F_13 ( V_25 -> V_59 . V_72 << 1 , V_25 -> V_56 ) ;
} else {
V_25 -> V_59 . V_71 = 0 ;
V_25 -> V_59 . V_72 = V_73 ;
}
F_35 ( V_2 ) ;
F_3 ( F_4 ( V_2 ) , V_74 ) ;
}
V_62:
if ( F_36 ( V_2 ) )
F_37 ( V_2 ) ;
}
static void F_38 ( unsigned long V_75 )
{
struct V_1 * V_2 = (struct V_1 * ) V_75 ;
F_39 ( V_2 ) ;
if ( ! F_40 ( V_2 ) ) {
F_27 ( V_2 ) ;
} else {
F_17 ( V_2 ) -> V_59 . V_76 = 1 ;
F_3 ( F_4 ( V_2 ) , V_77 ) ;
if ( ! F_41 ( V_78 , & F_6 ( V_2 ) -> V_79 ) )
F_42 ( V_2 ) ;
}
F_43 ( V_2 ) ;
F_44 ( V_2 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = F_17 ( V_2 ) ;
struct V_9 * V_10 = F_6 ( V_2 ) ;
int V_80 ;
T_1 V_38 ;
if ( V_10 -> V_18 || ! F_46 ( V_2 ) ) {
V_25 -> V_81 = 0 ;
return;
}
V_38 = F_19 ( F_46 ( V_2 ) ) ;
if ( ! V_38 )
F_47 ( & F_46 ( V_2 ) -> V_82 ) ;
else if ( V_25 -> V_57 &&
( V_12 ) ( V_13 - V_38 ) > V_25 -> V_57 )
goto abort;
V_80 = V_54 ;
if ( F_26 ( V_2 , V_55 ) ) {
const int V_21 = F_48 ( V_25 , V_15 ) < V_15 ;
V_80 = F_9 ( V_2 , V_21 ) ;
if ( ! V_21 && V_25 -> V_83 >= V_80 )
goto abort;
if ( F_5 ( V_2 , true ) )
return;
}
if ( V_25 -> V_81 > V_80 ) {
abort: F_1 ( V_2 ) ;
} else {
F_49 ( V_2 ) ;
}
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = F_17 ( V_2 ) ;
int V_84 = V_25 -> V_51 ? :
V_85 + 1 ;
struct V_86 * V_87 ;
V_87 = F_6 ( V_2 ) -> V_88 ;
V_87 -> V_89 -> V_90 ( V_2 , V_87 ) ;
if ( V_87 -> V_91 >= V_84 ) {
F_1 ( V_2 ) ;
return;
}
F_51 ( V_2 , V_87 ) ;
V_87 -> V_91 ++ ;
F_52 ( V_2 , V_92 ,
V_40 << V_87 -> V_91 , V_15 ) ;
}
void F_53 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_6 ( V_2 ) ;
struct V_24 * V_25 = F_17 ( V_2 ) ;
if ( V_10 -> V_88 ) {
F_54 ( V_2 -> V_45 != V_93 &&
V_2 -> V_45 != V_94 ) ;
F_50 ( V_2 ) ;
return;
}
if ( ! V_10 -> V_18 )
goto V_62;
F_55 ( F_56 ( V_2 ) ) ;
V_10 -> V_95 = 0 ;
if ( ! V_10 -> V_17 && ! F_26 ( V_2 , V_55 ) &&
! ( ( 1 << V_2 -> V_45 ) & ( V_46 | V_47 ) ) ) {
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
goto V_62;
}
F_61 ( V_2 ) ;
F_62 ( V_2 , F_20 ( V_2 ) ) ;
F_63 ( V_2 ) ;
goto V_109;
}
if ( F_23 ( V_2 ) )
goto V_62;
if ( V_25 -> V_42 == 0 ) {
int V_110 ;
if ( V_25 -> V_111 == V_112 ) {
if ( F_64 ( V_10 ) )
V_110 = V_113 ;
else
V_110 = V_114 ;
} else if ( V_25 -> V_111 == V_115 ) {
V_110 = V_116 ;
} else if ( ( V_25 -> V_111 == V_117 ) ||
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
if ( F_62 ( V_2 , F_20 ( V_2 ) ) > 0 ) {
if ( ! V_25 -> V_42 )
V_25 -> V_42 = 1 ;
F_52 ( V_2 , V_92 ,
F_13 ( V_25 -> V_56 , V_122 ) ,
V_15 ) ;
goto V_62;
}
V_25 -> V_83 ++ ;
V_25 -> V_42 ++ ;
V_109:
if ( V_2 -> V_45 == V_123 &&
( V_10 -> V_124 || V_125 ) &&
F_65 ( V_10 ) &&
V_25 -> V_42 <= V_126 ) {
V_25 -> V_83 = 0 ;
V_25 -> V_56 = F_13 ( F_66 ( V_10 ) , V_15 ) ;
} else {
V_25 -> V_56 = F_13 ( V_25 -> V_56 << 1 , V_15 ) ;
}
F_52 ( V_2 , V_92 , V_25 -> V_56 , V_15 ) ;
if ( F_16 ( V_2 , V_53 + 1 , 0 , 0 ) )
F_63 ( V_2 ) ;
V_62: ;
}
void F_67 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = F_17 ( V_2 ) ;
int V_127 ;
if ( V_2 -> V_45 == V_58 || ! V_25 -> V_128 )
goto V_62;
if ( F_29 ( V_25 -> V_129 , V_63 ) ) {
F_30 ( V_2 , & V_25 -> V_130 , V_25 -> V_129 ) ;
goto V_62;
}
V_127 = V_25 -> V_128 ;
switch ( V_127 ) {
case V_131 :
F_68 ( V_2 ) ;
break;
case V_132 :
F_69 ( V_2 ) ;
break;
case V_92 :
V_25 -> V_128 = 0 ;
F_53 ( V_2 ) ;
break;
case V_133 :
V_25 -> V_128 = 0 ;
F_45 ( V_2 ) ;
break;
}
V_62:
F_37 ( V_2 ) ;
}
static void F_70 ( unsigned long V_75 )
{
struct V_1 * V_2 = (struct V_1 * ) V_75 ;
F_39 ( V_2 ) ;
if ( ! F_40 ( V_2 ) ) {
F_67 ( V_2 ) ;
} else {
if ( ! F_41 ( V_134 , & F_6 ( V_2 ) -> V_79 ) )
F_42 ( V_2 ) ;
}
F_43 ( V_2 ) ;
F_44 ( V_2 ) ;
}
static void F_71 ( struct V_1 * V_2 )
{
F_72 ( V_2 , V_135 ,
V_40 , V_15 ) ;
}
void F_73 ( struct V_1 * V_2 , struct V_86 * V_87 )
{
F_3 ( F_4 ( V_2 ) , V_121 ) ;
}
void F_74 ( struct V_1 * V_2 , int V_136 )
{
if ( ( 1 << V_2 -> V_45 ) & ( V_137 | V_138 ) )
return;
if ( V_136 && ! F_26 ( V_2 , V_139 ) )
F_75 ( V_2 , F_76 ( F_6 ( V_2 ) ) ) ;
else if ( ! V_136 )
F_77 ( V_2 ) ;
}
static void F_78 ( unsigned long V_75 )
{
struct V_1 * V_2 = (struct V_1 * ) V_75 ;
struct V_24 * V_25 = F_17 ( V_2 ) ;
struct V_9 * V_10 = F_6 ( V_2 ) ;
T_1 V_140 ;
F_39 ( V_2 ) ;
if ( F_40 ( V_2 ) ) {
F_75 ( V_2 , V_141 / 20 ) ;
goto V_62;
}
if ( V_2 -> V_45 == V_142 ) {
F_71 ( V_2 ) ;
goto V_62;
}
if ( V_2 -> V_45 == V_143 && F_26 ( V_2 , V_55 ) ) {
if ( V_10 -> V_144 >= 0 ) {
const int V_145 = F_79 ( V_2 ) - V_16 ;
if ( V_145 > 0 ) {
F_80 ( V_2 , V_143 , V_145 ) ;
goto V_62;
}
}
F_8 ( V_2 , V_19 ) ;
goto V_146;
}
if ( ! F_26 ( V_2 , V_139 ) || V_2 -> V_45 == V_58 )
goto V_62;
V_140 = F_76 ( V_10 ) ;
if ( V_10 -> V_18 || F_46 ( V_2 ) )
goto V_147;
V_140 = F_81 ( V_10 ) ;
if ( V_140 >= F_76 ( V_10 ) ) {
if ( ( V_25 -> V_57 != 0 &&
V_140 >= V_25 -> V_57 &&
V_25 -> V_81 > 0 ) ||
( V_25 -> V_57 == 0 &&
V_25 -> V_81 >= F_82 ( V_10 ) ) ) {
F_8 ( V_2 , V_19 ) ;
F_1 ( V_2 ) ;
goto V_62;
}
if ( F_83 ( V_2 ) <= 0 ) {
V_25 -> V_81 ++ ;
V_140 = F_84 ( V_10 ) ;
} else {
V_140 = V_122 ;
}
} else {
V_140 = F_76 ( V_10 ) - V_140 ;
}
F_37 ( V_2 ) ;
V_147:
F_75 ( V_2 , V_140 ) ;
goto V_62;
V_146:
F_2 ( V_2 ) ;
V_62:
F_43 ( V_2 ) ;
F_44 ( V_2 ) ;
}
void F_85 ( struct V_1 * V_2 )
{
F_86 ( V_2 , & F_70 , & F_38 ,
& F_78 ) ;
}
