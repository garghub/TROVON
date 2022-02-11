static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
void T_2 * V_4 = V_2 -> V_5 ;
unsigned long V_6 ;
V_6 = F_2 ( V_4 + V_7 ) & ~ V_8 ;
V_6 &= ~ F_3 ( 3 ) ;
V_6 |= F_3 ( V_3 & 3 ) ;
F_4 ( V_6 , V_4 + V_7 ) ;
}
static void F_5 ( struct V_1 * V_2 , bool V_9 )
{
void T_2 * V_4 = V_2 -> V_5 ;
unsigned long V_6 ;
V_6 = F_2 ( V_4 + V_7 ) & ~ V_8 ;
if ( V_9 )
V_6 |= V_10 ;
else
V_6 &= ~ V_10 ;
F_4 ( V_6 , V_4 + V_7 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
V_2 -> V_11 = F_7 ( V_2 -> V_12 , L_1 ) ;
if ( F_8 ( V_2 -> V_11 ) ) {
F_9 ( L_2 , V_13 ) ;
return F_10 ( V_2 -> V_11 ) ;
}
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
unsigned long V_6 , V_14 ;
void T_2 * V_4 = V_2 -> V_15 ;
F_12 ( V_2 -> V_11 ) ;
F_13 ( & V_16 , V_14 ) ;
if ( V_17 ++ == 0 ) {
V_6 = F_2 ( V_4 + V_18 ) ;
V_6 &= ~ ( V_19 | V_20 ) ;
F_4 ( V_6 , V_4 + V_18 ) ;
}
F_14 ( & V_16 , V_14 ) ;
F_15 ( V_2 -> V_11 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
unsigned long V_6 , V_14 ;
void T_2 * V_4 = V_2 -> V_15 ;
if ( ! V_17 ) {
F_9 ( L_3 , V_13 ) ;
return - V_21 ;
}
F_12 ( V_2 -> V_11 ) ;
F_13 ( & V_16 , V_14 ) ;
if ( -- V_17 == 0 ) {
V_6 = F_2 ( V_4 + V_18 ) ;
V_6 |= V_19 | V_20 ;
F_4 ( V_6 , V_4 + V_18 ) ;
}
F_14 ( & V_16 , V_14 ) ;
F_15 ( V_2 -> V_11 ) ;
return 0 ;
}
static int F_17 ( void T_2 * V_22 , T_3 V_23 , T_3 V_24 )
{
unsigned long V_25 = 2000 ;
do {
if ( ( F_2 ( V_22 ) & V_23 ) == V_24 )
return 0 ;
F_18 ( 1 ) ;
V_25 -- ;
} while ( V_25 );
return - 1 ;
}
static void F_19 ( struct V_1 * V_2 )
{
unsigned long V_6 ;
void T_2 * V_4 = V_2 -> V_5 ;
if ( V_2 -> V_26 ) {
V_6 = F_2 ( V_4 + V_27 ) ;
V_6 |= V_28 ;
F_4 ( V_6 , V_4 + V_27 ) ;
F_18 ( 10 ) ;
V_6 = F_2 ( V_4 + V_27 ) ;
V_6 &= ~ V_28 ;
F_4 ( V_6 , V_4 + V_27 ) ;
} else
F_5 ( V_2 , true ) ;
if ( F_17 ( V_4 + V_27 , V_29 , 0 ) < 0 )
F_9 ( L_4 , V_13 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
unsigned long V_6 ;
void T_2 * V_4 = V_2 -> V_5 ;
if ( V_2 -> V_26 ) {
V_6 = F_2 ( V_4 + V_27 ) ;
V_6 |= V_30 ;
F_4 ( V_6 , V_4 + V_27 ) ;
F_18 ( 10 ) ;
V_6 = F_2 ( V_4 + V_27 ) ;
V_6 &= ~ V_30 ;
F_4 ( V_6 , V_4 + V_27 ) ;
} else
F_5 ( V_2 , false ) ;
if ( F_17 ( V_4 + V_27 , V_29 ,
V_29 ) )
F_9 ( L_4 , V_13 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
unsigned long V_6 ;
void T_2 * V_4 = V_2 -> V_5 ;
struct V_31 * V_32 = V_2 -> V_32 ;
V_6 = F_2 ( V_4 + V_27 ) ;
V_6 |= V_33 ;
F_4 ( V_6 , V_4 + V_27 ) ;
if ( V_2 -> V_26 ) {
V_6 = F_2 ( V_4 + V_34 ) ;
V_6 |= V_35 ;
F_4 ( V_6 , V_4 + V_34 ) ;
}
V_6 = F_2 ( V_4 + V_36 ) ;
V_6 &= ~ V_37 ;
F_4 ( V_6 , V_4 + V_36 ) ;
V_6 = F_2 ( V_4 + V_38 ) ;
V_6 &= ~ ( F_22 ( ~ 0 ) | F_23 ( ~ 0 ) ) ;
V_6 |= F_22 ( V_32 -> V_39 ) ;
V_6 |= F_23 ( V_32 -> V_40 ) ;
F_4 ( V_6 , V_4 + V_38 ) ;
V_6 = F_2 ( V_4 + V_41 ) ;
V_6 &= ~ F_24 ( ~ 0 ) ;
V_6 |= F_24 ( V_32 -> V_42 ) ;
F_4 ( V_6 , V_4 + V_41 ) ;
V_6 = F_2 ( V_4 + V_43 ) ;
V_6 &= ~ F_25 ( ~ 0 ) ;
V_6 |= F_25 ( V_2 -> V_44 -> V_45 ) ;
F_4 ( V_6 , V_4 + V_43 ) ;
V_6 = F_2 ( V_4 + V_46 ) ;
V_6 &= ~ V_47 ;
F_4 ( V_6 , V_4 + V_46 ) ;
V_6 = F_2 ( V_4 + V_48 ) ;
V_6 &= ~ ( F_26 ( ~ 0 ) | F_27 ( ~ 0 ) ) ;
V_6 |= F_26 ( V_2 -> V_44 -> V_49 ) |
F_27 ( V_2 -> V_44 -> V_50 ) ;
F_4 ( V_6 , V_4 + V_48 ) ;
V_6 = F_2 ( V_4 + V_51 ) ;
V_6 &= ~ ( F_28 ( ~ 0 ) | F_29 ( ~ 0 ) ) ;
V_6 |= F_28 ( V_2 -> V_44 -> V_52 ) |
F_29 ( V_2 -> V_44 -> V_53 ) ;
F_4 ( V_6 , V_4 + V_51 ) ;
if ( V_2 -> V_54 == V_55 ) {
V_6 = F_2 ( V_4 + V_27 ) ;
V_6 &= ~ ( V_56 | V_57 ) ;
F_4 ( V_6 , V_4 + V_27 ) ;
}
F_11 ( V_2 ) ;
V_6 = F_2 ( V_4 + V_58 ) ;
V_6 &= ~ ( V_59 | V_60 |
V_61 | F_30 ( ~ 0 ) |
F_31 ( ~ 0 ) | F_32 ( ~ 0 ) |
F_33 ( ~ 0 ) ) ;
V_6 |= F_30 ( V_32 -> V_62 ) ;
V_6 |= F_31 ( V_32 -> V_63 ) ;
V_6 |= F_32 ( V_32 -> V_64 ) ;
F_4 ( V_6 , V_4 + V_58 ) ;
V_6 = F_2 ( V_4 + V_65 ) ;
V_6 &= ~ ( V_66 | V_67 |
V_68 | F_34 ( ~ 0 ) ) ;
V_6 |= F_34 ( V_32 -> V_69 ) ;
F_4 ( V_6 , V_4 + V_65 ) ;
V_6 = F_2 ( V_4 + V_70 ) ;
V_6 &= ~ V_71 ;
F_4 ( V_6 , V_4 + V_70 ) ;
V_6 = F_2 ( V_4 + V_72 ) ;
V_6 &= ~ F_35 ( ~ 0 ) ;
V_6 |= F_35 ( 0x5 ) ;
F_4 ( V_6 , V_4 + V_72 ) ;
if ( V_2 -> V_26 ) {
V_6 = F_2 ( V_4 + V_73 ) ;
if ( V_2 -> V_54 == V_55 )
V_6 &= ~ V_74 ;
else
V_6 |= V_74 ;
F_4 ( V_6 , V_4 + V_73 ) ;
} else {
V_6 = F_2 ( V_4 + V_27 ) ;
V_6 |= V_75 ;
F_4 ( V_6 , V_4 + V_27 ) ;
}
V_6 = F_2 ( V_4 + V_27 ) ;
V_6 &= ~ V_33 ;
F_4 ( V_6 , V_4 + V_27 ) ;
if ( V_2 -> V_26 ) {
V_6 = F_2 ( V_4 + V_34 ) ;
V_6 &= ~ V_76 ;
V_6 |= V_77 ;
F_4 ( V_6 , V_4 + V_34 ) ;
V_6 = F_2 ( V_4 + V_27 ) ;
V_6 &= ~ V_28 ;
F_4 ( V_6 , V_4 + V_27 ) ;
}
F_20 ( V_2 ) ;
if ( ! V_2 -> V_26 )
F_1 ( V_2 , 0 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
unsigned long V_6 ;
void T_2 * V_4 = V_2 -> V_5 ;
F_19 ( V_2 ) ;
if ( V_2 -> V_54 == V_55 ) {
V_6 = F_2 ( V_4 + V_27 ) ;
V_6 &= ~ F_37 ( ~ 0 ) ;
V_6 |= V_56 | F_37 ( 5 ) ;
F_4 ( V_6 , V_4 + V_27 ) ;
}
V_6 = F_2 ( V_4 + V_27 ) ;
V_6 |= V_33 ;
F_4 ( V_6 , V_4 + V_27 ) ;
V_6 = F_2 ( V_4 + V_70 ) ;
V_6 |= V_71 ;
F_4 ( V_6 , V_4 + V_70 ) ;
V_6 = F_2 ( V_4 + V_58 ) ;
V_6 |= V_59 | V_60 |
V_61 ;
F_4 ( V_6 , V_4 + V_58 ) ;
V_6 = F_2 ( V_4 + V_65 ) ;
V_6 |= V_66 | V_67 |
V_68 ;
F_4 ( V_6 , V_4 + V_65 ) ;
return F_16 ( V_2 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
unsigned long V_6 ;
void T_2 * V_4 = V_2 -> V_5 ;
V_6 = F_2 ( V_4 + V_36 ) ;
V_6 |= V_78 ;
F_4 ( V_6 , V_4 + V_36 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
unsigned long V_6 ;
void T_2 * V_4 = V_2 -> V_5 ;
V_6 = F_2 ( V_4 + V_36 ) ;
V_6 &= ~ V_78 ;
F_4 ( V_6 , V_4 + V_36 ) ;
}
static void F_40 ( struct V_1 * V_2 ,
enum V_79 V_80 )
{
unsigned long V_6 ;
void T_2 * V_4 = V_2 -> V_5 ;
V_6 = F_2 ( V_4 + V_46 ) ;
V_6 &= ~ F_41 ( ~ 0 ) ;
if ( V_80 == V_81 )
V_6 |= V_82 ;
else
V_6 |= V_83 ;
F_4 ( V_6 , V_4 + V_46 ) ;
F_18 ( 1 ) ;
V_6 = F_2 ( V_4 + V_46 ) ;
V_6 |= V_84 ;
F_4 ( V_6 , V_4 + V_46 ) ;
F_18 ( 10 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
unsigned long V_6 ;
void T_2 * V_4 = V_2 -> V_5 ;
V_6 = F_2 ( V_4 + V_46 ) ;
V_6 &= ~ V_84 ;
F_4 ( V_6 , V_4 + V_46 ) ;
F_18 ( 10 ) ;
}
static int F_43 ( struct V_1 * V_2 )
{
int V_85 ;
unsigned long V_6 ;
void T_2 * V_4 = V_2 -> V_5 ;
V_85 = F_44 ( V_2 -> V_86 , 0 ) ;
if ( V_85 < 0 ) {
F_45 ( V_2 -> V_12 , L_5 , V_2 -> V_86 ) ;
return V_85 ;
}
F_46 ( 5 ) ;
V_85 = F_44 ( V_2 -> V_86 , 1 ) ;
if ( V_85 < 0 ) {
F_45 ( V_2 -> V_12 , L_6 , V_2 -> V_86 ) ;
return V_85 ;
}
F_12 ( V_2 -> V_87 ) ;
F_46 ( 1 ) ;
V_6 = F_2 ( V_4 + V_27 ) ;
V_6 |= V_88 ;
F_4 ( V_6 , V_4 + V_27 ) ;
V_6 = F_2 ( V_4 + V_89 ) ;
V_6 |= V_90 | V_91 ;
F_4 ( V_6 , V_4 + V_89 ) ;
V_6 = F_2 ( V_4 + V_27 ) ;
V_6 |= V_92 ;
F_4 ( V_6 , V_4 + V_27 ) ;
V_6 = 0 ;
F_4 ( V_6 , V_4 + V_93 ) ;
V_6 |= F_47 ( 4 ) ;
V_6 |= F_48 ( 4 ) ;
V_6 |= F_49 ( 4 ) ;
F_4 ( V_6 , V_4 + V_93 ) ;
F_18 ( 10 ) ;
V_6 |= V_94 ;
V_6 |= V_95 ;
V_6 |= V_96 ;
F_4 ( V_6 , V_4 + V_93 ) ;
V_85 = F_50 ( V_2 -> V_97 , 0x40 , 0x08 ) ;
if ( V_85 ) {
F_9 ( L_7 , V_13 ) ;
return V_85 ;
}
V_85 = F_50 ( V_2 -> V_97 , 0x80 , 0x0B ) ;
if ( V_85 ) {
F_9 ( L_7 , V_13 ) ;
return V_85 ;
}
V_6 = F_2 ( V_4 + V_27 ) ;
V_6 |= V_30 ;
F_4 ( V_6 , V_4 + V_27 ) ;
F_18 ( 100 ) ;
V_6 = F_2 ( V_4 + V_27 ) ;
V_6 &= ~ V_30 ;
F_4 ( V_6 , V_4 + V_27 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 )
{
F_52 ( V_2 -> V_87 ) ;
return F_44 ( V_2 -> V_86 , 0 ) ;
}
static void F_53 ( struct V_98 * V_99 )
{
struct V_1 * V_2 = F_54 ( V_99 , struct V_1 , V_100 ) ;
F_15 ( V_2 -> V_101 ) ;
}
static int F_55 ( struct V_1 * V_2 )
{
if ( V_2 -> V_102 )
return F_43 ( V_2 ) ;
else
return F_21 ( V_2 ) ;
}
static int F_56 ( struct V_1 * V_2 )
{
if ( V_2 -> V_102 )
return F_51 ( V_2 ) ;
else
return F_36 ( V_2 ) ;
}
static int F_57 ( struct V_98 * V_99 , int V_103 )
{
struct V_1 * V_2 = F_54 ( V_99 , struct V_1 , V_100 ) ;
if ( V_103 )
return F_56 ( V_2 ) ;
else
return F_55 ( V_2 ) ;
}
static int F_58 ( struct V_1 * V_2 )
{
int V_104 ;
V_2 -> V_87 = F_7 ( V_2 -> V_12 , L_8 ) ;
if ( F_8 ( V_2 -> V_87 ) ) {
F_9 ( L_9 , V_13 ) ;
return F_10 ( V_2 -> V_87 ) ;
}
V_104 = F_59 ( V_2 -> V_12 , V_2 -> V_86 , L_10 ) ;
if ( V_104 < 0 ) {
F_45 ( V_2 -> V_12 , L_11 ,
V_2 -> V_86 ) ;
return V_104 ;
}
V_104 = F_44 ( V_2 -> V_86 , 0 ) ;
if ( V_104 < 0 ) {
F_45 ( V_2 -> V_12 , L_12 ,
V_2 -> V_86 ) ;
return V_104 ;
}
V_2 -> V_97 = F_60 ( & V_105 , 0 ) ;
if ( ! V_2 -> V_97 ) {
F_45 ( V_2 -> V_12 , L_13 ) ;
V_104 = - V_106 ;
return V_104 ;
}
V_2 -> V_97 -> V_107 = V_2 -> V_5 + V_108 ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 )
{
unsigned long V_109 ;
int V_110 ;
int V_104 ;
if ( ! V_2 -> V_102 ) {
if ( V_2 -> V_26 )
V_2 -> V_32 = & V_111 [ 0 ] ;
else
V_2 -> V_32 = & V_111 [ 2 ] ;
}
V_2 -> V_101 = F_7 ( V_2 -> V_12 , L_14 ) ;
if ( F_8 ( V_2 -> V_101 ) ) {
F_9 ( L_15 ) ;
return F_10 ( V_2 -> V_101 ) ;
}
V_104 = F_12 ( V_2 -> V_101 ) ;
if ( V_104 )
return V_104 ;
V_109 = F_62 ( F_63 ( V_2 -> V_101 ) ) ;
for ( V_110 = 0 ; V_110 < F_64 ( V_112 ) ; V_110 ++ ) {
if ( V_112 [ V_110 ] . V_44 == V_109 ) {
V_2 -> V_44 = & V_112 [ V_110 ] ;
break;
}
}
if ( ! V_2 -> V_44 ) {
F_9 ( L_16 , V_109 ) ;
V_104 = - V_21 ;
goto V_113;
}
if ( V_2 -> V_102 )
V_104 = F_58 ( V_2 ) ;
else
V_104 = F_6 ( V_2 ) ;
if ( V_104 < 0 )
goto V_113;
return 0 ;
V_113:
F_15 ( V_2 -> V_101 ) ;
return V_104 ;
}
void F_65 ( struct V_98 * V_99 )
{
struct V_1 * V_2 = F_54 ( V_99 , struct V_1 , V_100 ) ;
if ( ! V_2 -> V_102 )
F_38 ( V_2 ) ;
}
void F_66 ( struct V_98 * V_99 )
{
struct V_1 * V_2 = F_54 ( V_99 , struct V_1 , V_100 ) ;
if ( ! V_2 -> V_102 )
F_39 ( V_2 ) ;
}
void F_67 ( struct V_98 * V_99 ,
enum V_79 V_80 )
{
struct V_1 * V_2 = F_54 ( V_99 , struct V_1 , V_100 ) ;
if ( ! V_2 -> V_102 )
F_40 ( V_2 , V_80 ) ;
}
void F_68 ( struct V_98 * V_99 )
{
struct V_1 * V_2 = F_54 ( V_99 , struct V_1 , V_100 ) ;
if ( ! V_2 -> V_102 )
F_42 ( V_2 ) ;
}
static int F_69 ( struct V_114 * V_115 )
{
struct V_116 * V_117 ;
struct V_1 * V_118 = NULL ;
struct V_119 * V_120 = V_115 -> V_12 . V_121 ;
int V_104 ;
V_118 = F_70 ( & V_115 -> V_12 , sizeof( * V_118 ) , V_122 ) ;
if ( ! V_118 ) {
F_45 ( & V_115 -> V_12 , L_17 ) ;
return - V_106 ;
}
V_117 = F_71 ( V_115 , V_123 , 0 ) ;
if ( ! V_117 ) {
F_45 ( & V_115 -> V_12 , L_18 ) ;
return - V_124 ;
}
V_118 -> V_5 = F_72 ( & V_115 -> V_12 , V_117 -> V_125 ,
F_73 ( V_117 ) ) ;
if ( ! V_118 -> V_5 ) {
F_45 ( & V_115 -> V_12 , L_19 ) ;
return - V_106 ;
}
V_118 -> V_26 =
F_74 ( V_120 , L_20 ) ;
V_104 = F_75 ( V_120 , L_21 , L_22 ) ;
if ( V_104 < 0 ) {
V_118 -> V_102 = false ;
V_117 = F_71 ( V_115 , V_123 , 1 ) ;
if ( ! V_117 ) {
F_45 ( & V_115 -> V_12 , L_23 ) ;
return - V_124 ;
}
V_118 -> V_15 = F_72 ( & V_115 -> V_12 , V_117 -> V_125 ,
F_73 ( V_117 ) ) ;
if ( ! V_118 -> V_5 ) {
F_45 ( & V_115 -> V_12 , L_24 ) ;
return - V_106 ;
}
} else {
V_118 -> V_102 = true ;
V_118 -> V_86 =
F_76 ( V_120 , L_25 , 0 ) ;
if ( ! F_77 ( V_118 -> V_86 ) ) {
F_45 ( & V_115 -> V_12 , L_26 ,
V_118 -> V_86 ) ;
return V_118 -> V_86 ;
}
}
V_104 = F_75 ( V_120 , L_27 , L_28 ) ;
if ( V_104 < 0 ) {
V_104 = F_75 ( V_120 , L_27 , L_29 ) ;
if ( V_104 < 0 )
V_118 -> V_54 = V_126 ;
else
V_118 -> V_54 = V_55 ;
} else
V_118 -> V_54 = V_127 ;
V_118 -> V_12 = & V_115 -> V_12 ;
V_104 = F_61 ( V_118 ) ;
if ( V_104 < 0 )
return V_104 ;
V_118 -> V_100 . V_128 = F_53 ;
V_118 -> V_100 . V_129 = F_57 ;
F_78 ( & V_115 -> V_12 , V_118 ) ;
return 0 ;
}
static int F_79 ( struct V_130 * V_12 , void * V_131 )
{
struct V_1 * V_118 = F_80 ( V_12 ) ;
struct V_119 * V_132 = V_131 ;
return ( V_118 -> V_12 -> V_121 == V_132 ) ? 1 : 0 ;
}
struct V_98 * F_81 ( struct V_119 * V_132 )
{
struct V_130 * V_12 ;
struct V_1 * V_118 ;
V_12 = F_82 ( & V_133 . V_134 , NULL , V_132 ,
F_79 ) ;
if ( ! V_12 )
return F_83 ( - V_135 ) ;
V_118 = F_80 ( V_12 ) ;
return & V_118 -> V_100 ;
}
