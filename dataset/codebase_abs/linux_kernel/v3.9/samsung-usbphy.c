int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( ! V_2 )
return - V_5 ;
if ( ! V_2 -> V_4 )
V_2 -> V_4 = V_4 ;
return 0 ;
}
static int F_2 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
V_9 = F_3 ( V_7 -> V_10 -> V_11 , L_1 ) ;
if ( ! V_9 ) {
F_4 ( V_7 -> V_10 , L_2 ) ;
return - V_5 ;
}
V_7 -> V_12 = F_5 ( V_9 , 0 ) ;
if ( V_7 -> V_12 == NULL ) {
F_4 ( V_7 -> V_10 , L_3 ) ;
goto V_13;
}
V_7 -> V_14 = F_5 ( V_9 , 1 ) ;
if ( V_7 -> V_14 == NULL )
F_6 ( V_7 -> V_10 , L_4 ) ;
F_7 ( V_9 ) ;
return 0 ;
V_13:
F_7 ( V_9 ) ;
return - V_15 ;
}
static void F_8 ( struct V_6 * V_7 , bool V_16 )
{
void T_1 * V_17 = NULL ;
T_2 V_18 ;
T_2 V_19 = 0 ;
if ( ! V_7 -> V_12 ) {
F_6 ( V_7 -> V_10 , L_5 ) ;
return;
}
switch ( V_7 -> V_20 -> V_21 ) {
case V_22 :
break;
case V_23 :
case V_24 :
if ( V_7 -> V_25 == V_26 ) {
V_17 = V_7 -> V_12 +
V_7 -> V_20 -> V_27 ;
V_19 = V_7 -> V_20 -> V_28 ;
} else if ( V_7 -> V_25 == V_29 ) {
V_17 = V_7 -> V_12 +
V_7 -> V_20 -> V_30 ;
V_19 = V_7 -> V_20 -> V_31 ;
}
break;
default:
F_4 ( V_7 -> V_10 , L_6 ) ;
return;
}
V_18 = F_9 ( V_17 ) ;
if ( V_16 )
V_18 &= ~ V_19 ;
else
V_18 |= V_19 ;
F_10 ( V_18 , V_17 ) ;
}
static void F_11 ( struct V_6 * V_7 )
{
T_2 V_17 ;
if ( ! V_7 -> V_14 ) {
F_6 ( V_7 -> V_10 , L_7 ) ;
return;
}
V_17 = F_9 ( V_7 -> V_14 ) ;
if ( V_7 -> V_25 == V_26 )
V_17 &= ~ V_32 ;
else if ( V_7 -> V_25 == V_29 )
V_17 |= V_32 ;
F_10 ( V_17 , V_7 -> V_14 ) ;
}
static int F_12 ( struct V_33 * V_34 ,
enum V_35 V_25 )
{
struct V_6 * V_7 = F_13 ( V_34 ) ;
V_7 -> V_25 = V_25 ;
return 0 ;
}
static int F_14 ( struct V_6 * V_7 )
{
struct V_36 * V_37 ;
int V_38 = 0 ;
if ( V_7 -> V_20 -> V_21 == V_24 )
V_37 = F_15 ( V_7 -> V_10 , L_8 ) ;
else
V_37 = F_15 ( V_7 -> V_10 , L_9 ) ;
if ( F_16 ( V_37 ) ) {
F_4 ( V_7 -> V_10 , L_10 ) ;
return F_17 ( V_37 ) ;
}
if ( V_7 -> V_20 -> V_21 == V_24 ) {
switch ( F_18 ( V_37 ) ) {
case 9600 * V_39 :
V_38 = V_40 ;
break;
case 10 * V_41 :
V_38 = V_42 ;
break;
case 12 * V_41 :
V_38 = V_43 ;
break;
case 19200 * V_39 :
V_38 = V_44 ;
break;
case 20 * V_41 :
V_38 = V_45 ;
break;
case 50 * V_41 :
V_38 = V_46 ;
break;
case 24 * V_41 :
default:
V_38 = V_47 ;
break;
}
} else {
switch ( F_18 ( V_37 ) ) {
case 12 * V_41 :
V_38 = V_48 ;
break;
case 24 * V_41 :
V_38 = V_49 ;
break;
case 48 * V_41 :
V_38 = V_50 ;
break;
default:
if ( V_7 -> V_20 -> V_21 == V_22 )
V_38 = V_50 ;
else
V_38 = V_49 ;
break;
}
}
F_19 ( V_37 ) ;
return V_38 ;
}
static bool F_20 ( void * V_51 )
{
T_2 V_17 ;
V_17 = F_9 ( V_51 + V_52 ) ;
return ! ( V_17 & V_53 ) ;
}
static void F_21 ( struct V_6 * V_7 )
{
void T_1 * V_51 = V_7 -> V_51 ;
T_2 V_54 = V_7 -> V_55 ;
T_2 V_56 ;
T_2 V_57 ;
T_2 V_58 ;
T_2 V_59 ;
T_2 V_60 ;
F_22 ( & V_7 -> V_61 ) ;
if ( F_20 ( V_51 ) ) {
F_23 ( V_7 -> V_10 , L_11 ) ;
return;
}
V_56 = F_9 ( V_51 + V_52 ) ;
V_56 &= ~ V_62 ;
V_56 |= F_24 ( V_54 ) ;
V_56 &= ~ ( V_63 |
V_64 |
V_53 |
V_65 |
V_66 ) ;
V_56 |= ( V_67 |
V_68 |
V_69 ) ;
F_10 ( V_56 , V_51 + V_52 ) ;
F_25 ( 10 ) ;
V_56 &= ~ ( V_67 |
V_68 ) ;
F_10 ( V_56 , V_51 + V_52 ) ;
V_57 = F_9 ( V_51 + V_70 ) ;
V_57 &= ~ V_71 ;
V_57 |= F_26 ( V_54 ) ;
V_57 &= ~ ( V_72 |
V_73 |
V_74 |
V_75 |
V_76 ) ;
V_57 |= ( V_77 |
V_78 |
V_79 |
V_80 |
V_81 ) ;
F_10 ( V_57 , V_51 + V_70 ) ;
F_25 ( 10 ) ;
V_57 &= ~ ( V_77 |
V_78 |
V_79 ) ;
F_10 ( V_57 , V_51 + V_70 ) ;
V_58 = ( V_82 |
V_83 |
V_84 ) ;
F_10 ( V_58 , V_51 + V_85 ) ;
F_10 ( V_58 , V_51 + V_86 ) ;
F_25 ( 10 ) ;
V_58 &= ~ V_84 ;
F_10 ( V_58 , V_51 + V_85 ) ;
F_10 ( V_58 , V_51 + V_86 ) ;
F_25 ( 80 ) ;
V_59 = F_9 ( V_51 + V_87 ) ;
V_59 |= ( V_88 |
V_89 |
V_90 |
V_91 ) ;
F_10 ( V_59 , V_51 + V_87 ) ;
V_60 = F_9 ( V_51 + V_92 ) ;
V_60 |= V_93 ;
F_10 ( V_60 , V_51 + V_92 ) ;
}
static void F_27 ( struct V_6 * V_7 )
{
void T_1 * V_51 = V_7 -> V_51 ;
T_2 V_94 ;
T_2 V_54 ;
T_2 V_95 ;
V_54 = V_7 -> V_55 ;
V_94 = F_9 ( V_51 + V_96 ) ;
V_95 = F_9 ( V_51 + V_97 ) ;
switch ( V_7 -> V_20 -> V_21 ) {
case V_22 :
V_54 &= ~ V_98 ;
V_94 &= ~ V_99 ;
V_95 |= V_100 ;
break;
case V_23 :
V_94 &= ~ V_101 ;
V_95 |= V_100 ;
default:
break;
}
F_10 ( V_54 , V_51 + V_102 ) ;
F_10 ( V_94 , V_51 + V_96 ) ;
F_10 ( V_95 , V_51 + V_97 ) ;
F_25 ( 10 ) ;
V_95 &= ~ V_100 ;
F_10 ( V_95 , V_51 + V_97 ) ;
}
static void F_28 ( struct V_6 * V_7 )
{
void T_1 * V_51 = V_7 -> V_51 ;
T_2 V_56 ;
T_2 V_57 ;
T_2 V_58 ;
if ( F_29 ( & V_7 -> V_61 ) > 0 ) {
F_23 ( V_7 -> V_10 , L_12 ) ;
return;
}
V_58 = ( V_82 |
V_83 |
V_103 |
V_104 |
V_105 ) ;
F_10 ( V_58 , V_51 + V_85 ) ;
F_10 ( V_58 , V_51 + V_86 ) ;
V_56 = F_9 ( V_51 + V_52 ) ;
V_56 |= ( V_53 |
V_65 |
V_66 |
V_63 |
V_64 ) ;
F_10 ( V_56 , V_51 + V_52 ) ;
V_57 = F_9 ( V_51 + V_70 ) ;
V_57 |= ( V_72 |
V_73 |
V_74 ) ;
F_10 ( V_57 , V_51 + V_70 ) ;
}
static void F_30 ( struct V_6 * V_7 )
{
void T_1 * V_51 = V_7 -> V_51 ;
T_2 V_94 ;
V_94 = F_9 ( V_51 + V_96 ) ;
switch ( V_7 -> V_20 -> V_21 ) {
case V_22 :
V_94 |= V_99 ;
break;
case V_23 :
V_94 |= V_101 ;
default:
break;
}
F_10 ( V_94 , V_51 + V_96 ) ;
}
static int F_31 ( struct V_33 * V_34 )
{
struct V_6 * V_7 ;
struct V_3 * V_4 = NULL ;
unsigned long V_106 ;
int V_107 = 0 ;
V_7 = F_13 ( V_34 ) ;
V_4 = V_34 -> V_2 -> V_4 ;
V_107 = F_32 ( V_7 -> V_36 ) ;
if ( V_107 ) {
F_4 ( V_7 -> V_10 , L_13 , V_108 ) ;
return V_107 ;
}
F_33 ( & V_7 -> V_109 , V_106 ) ;
if ( V_4 ) {
if ( ! strstr ( F_34 ( V_4 -> V_110 ) , L_14 ) ||
! strstr ( F_34 ( V_4 -> V_110 ) , L_15 ) )
F_12 ( & V_7 -> V_34 , V_29 ) ;
} else {
F_12 ( & V_7 -> V_34 , V_26 ) ;
}
if ( V_7 -> V_111 && V_7 -> V_111 -> V_112 )
V_7 -> V_111 -> V_112 ( false ) ;
else
F_8 ( V_7 , false ) ;
F_11 ( V_7 ) ;
if ( V_7 -> V_20 -> V_21 == V_24 )
F_21 ( V_7 ) ;
else
F_27 ( V_7 ) ;
F_35 ( & V_7 -> V_109 , V_106 ) ;
F_36 ( V_7 -> V_36 ) ;
return V_107 ;
}
static void F_37 ( struct V_33 * V_34 )
{
struct V_6 * V_7 ;
struct V_3 * V_4 = NULL ;
unsigned long V_106 ;
V_7 = F_13 ( V_34 ) ;
V_4 = V_34 -> V_2 -> V_4 ;
if ( F_32 ( V_7 -> V_36 ) ) {
F_4 ( V_7 -> V_10 , L_13 , V_108 ) ;
return;
}
F_33 ( & V_7 -> V_109 , V_106 ) ;
if ( V_4 ) {
if ( ! strstr ( F_34 ( V_4 -> V_110 ) , L_14 ) ||
! strstr ( F_34 ( V_4 -> V_110 ) , L_15 ) )
F_12 ( & V_7 -> V_34 , V_29 ) ;
} else {
F_12 ( & V_7 -> V_34 , V_26 ) ;
}
if ( V_7 -> V_20 -> V_21 == V_24 )
F_28 ( V_7 ) ;
else
F_30 ( V_7 ) ;
if ( V_7 -> V_111 && V_7 -> V_111 -> V_112 )
V_7 -> V_111 -> V_112 ( true ) ;
else
F_8 ( V_7 , true ) ;
F_35 ( & V_7 -> V_109 , V_106 ) ;
F_36 ( V_7 -> V_36 ) ;
}
static inline const struct V_113
* F_38 ( struct V_114 * V_115 )
{
if ( V_115 -> V_10 . V_11 ) {
const struct V_116 * V_117 ;
V_117 = F_39 ( V_118 ,
V_115 -> V_10 . V_11 ) ;
return V_117 -> V_119 ;
}
return (struct V_113 * )
F_40 ( V_115 ) -> V_120 ;
}
static int F_41 ( struct V_114 * V_115 )
{
struct V_6 * V_7 ;
struct V_1 * V_2 ;
struct V_121 * V_122 = V_115 -> V_10 . V_123 ;
const struct V_113 * V_20 ;
struct V_124 * V_10 = & V_115 -> V_10 ;
struct V_125 * V_126 ;
void T_1 * V_127 ;
struct V_36 * V_36 ;
int V_107 ;
V_126 = F_42 ( V_115 , V_128 , 0 ) ;
if ( ! V_126 ) {
F_4 ( V_10 , L_16 , V_108 ) ;
return - V_5 ;
}
V_127 = F_43 ( V_10 , V_126 ) ;
if ( F_16 ( V_127 ) )
return F_17 ( V_127 ) ;
V_7 = F_44 ( V_10 , sizeof( * V_7 ) , V_129 ) ;
if ( ! V_7 )
return - V_130 ;
V_2 = F_44 ( V_10 , sizeof( * V_2 ) , V_129 ) ;
if ( ! V_2 )
return - V_130 ;
V_20 = F_38 ( V_115 ) ;
if ( V_20 -> V_21 == V_24 )
V_36 = F_45 ( V_10 , L_17 ) ;
else
V_36 = F_45 ( V_10 , L_18 ) ;
if ( F_16 ( V_36 ) ) {
F_4 ( V_10 , L_19 ) ;
return F_17 ( V_36 ) ;
}
V_7 -> V_10 = V_10 ;
if ( V_10 -> V_11 ) {
V_107 = F_2 ( V_7 ) ;
if ( V_107 < 0 )
return V_107 ;
} else {
if ( ! V_122 ) {
F_4 ( V_10 , L_20 ) ;
return - V_131 ;
}
}
V_7 -> V_111 = V_122 ;
V_7 -> V_51 = V_127 ;
V_7 -> V_36 = V_36 ;
V_7 -> V_20 = V_20 ;
V_7 -> V_34 . V_10 = V_7 -> V_10 ;
V_7 -> V_34 . V_132 = L_21 ;
V_7 -> V_34 . V_133 = F_31 ;
V_7 -> V_34 . V_134 = F_37 ;
V_7 -> V_55 = F_14 ( V_7 ) ;
V_7 -> V_34 . V_2 = V_2 ;
V_7 -> V_34 . V_2 -> V_34 = & V_7 -> V_34 ;
V_7 -> V_34 . V_2 -> V_135 = F_1 ;
F_46 ( & V_7 -> V_109 ) ;
F_47 ( V_115 , V_7 ) ;
return F_48 ( & V_7 -> V_34 , V_136 ) ;
}
static int F_49 ( struct V_114 * V_115 )
{
struct V_6 * V_7 = F_50 ( V_115 ) ;
F_51 ( & V_7 -> V_34 ) ;
if ( V_7 -> V_12 )
F_52 ( V_7 -> V_12 ) ;
if ( V_7 -> V_14 )
F_52 ( V_7 -> V_14 ) ;
return 0 ;
}
