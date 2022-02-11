static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
void T_2 * V_4 = V_2 -> V_5 ;
unsigned long V_6 ;
if ( V_2 -> V_7 -> V_8 ) {
V_6 = F_2 ( V_4 + V_9 ) ;
V_6 &= ~ F_3 ( ~ 0 ) ;
V_6 |= F_3 ( V_3 ) ;
F_4 ( V_6 , V_4 + V_9 ) ;
} else {
V_6 = F_2 ( V_4 + V_10 ) & ~ V_11 ;
V_6 &= ~ F_5 ( ~ 0 ) ;
V_6 |= F_5 ( V_3 ) ;
F_4 ( V_6 , V_4 + V_10 ) ;
}
}
static void F_6 ( struct V_1 * V_2 , bool V_12 )
{
void T_2 * V_4 = V_2 -> V_5 ;
unsigned long V_6 ;
if ( V_2 -> V_7 -> V_8 ) {
V_6 = F_2 ( V_4 + V_9 ) ;
if ( V_12 )
V_6 |= V_13 ;
else
V_6 &= ~ V_13 ;
F_4 ( V_6 , V_4 + V_9 ) ;
} else {
V_6 = F_2 ( V_4 + V_10 ) & ~ V_14 ;
if ( V_12 )
V_6 |= V_15 ;
else
V_6 &= ~ V_15 ;
F_4 ( V_6 , V_4 + V_10 ) ;
}
}
static int F_7 ( struct V_1 * V_2 )
{
V_2 -> V_16 = F_8 ( V_2 -> V_17 . V_18 , L_1 ) ;
if ( F_9 ( V_2 -> V_16 ) ) {
F_10 ( L_2 , V_19 ) ;
return F_11 ( V_2 -> V_16 ) ;
}
return 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
unsigned long V_6 , V_20 ;
void T_2 * V_4 = V_2 -> V_21 ;
struct V_22 * V_23 = V_2 -> V_23 ;
F_13 ( V_2 -> V_16 ) ;
F_14 ( & V_24 , V_20 ) ;
if ( V_25 ++ == 0 ) {
V_6 = F_2 ( V_4 + V_26 ) ;
V_6 &= ~ ( V_27 | V_28 ) ;
if ( V_2 -> V_7 -> V_29 ) {
V_6 &= ~ ( F_15 ( ~ 0 ) |
F_16 ( ~ 0 ) |
F_17 ( ~ 0 ) ) ;
V_6 |= F_15 ( V_23 -> V_30 ) ;
V_6 |= F_16 ( V_23 -> V_31 ) ;
V_6 |= F_17 ( V_23 -> V_31 ) ;
}
F_4 ( V_6 , V_4 + V_26 ) ;
}
F_18 ( & V_24 , V_20 ) ;
F_19 ( V_2 -> V_16 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
unsigned long V_6 , V_20 ;
void T_2 * V_4 = V_2 -> V_21 ;
if ( ! V_25 ) {
F_10 ( L_3 , V_19 ) ;
return - V_32 ;
}
F_13 ( V_2 -> V_16 ) ;
F_14 ( & V_24 , V_20 ) ;
if ( -- V_25 == 0 ) {
V_6 = F_2 ( V_4 + V_26 ) ;
V_6 |= V_27 | V_28 ;
F_4 ( V_6 , V_4 + V_26 ) ;
}
F_18 ( & V_24 , V_20 ) ;
F_19 ( V_2 -> V_16 ) ;
return 0 ;
}
static int F_21 ( void T_2 * V_33 , T_3 V_34 , T_3 V_35 )
{
unsigned long V_36 = 2000 ;
do {
if ( ( F_2 ( V_33 ) & V_34 ) == V_35 )
return 0 ;
F_22 ( 1 ) ;
V_36 -- ;
} while ( V_36 );
return - 1 ;
}
static void F_23 ( struct V_1 * V_2 )
{
unsigned long V_6 ;
void T_2 * V_4 = V_2 -> V_5 ;
if ( V_2 -> V_37 ) {
V_6 = F_2 ( V_4 + V_38 ) ;
V_6 |= V_39 ;
F_4 ( V_6 , V_4 + V_38 ) ;
F_22 ( 10 ) ;
V_6 = F_2 ( V_4 + V_38 ) ;
V_6 &= ~ V_39 ;
F_4 ( V_6 , V_4 + V_38 ) ;
} else
F_6 ( V_2 , true ) ;
if ( F_21 ( V_4 + V_38 , V_40 , 0 ) < 0 )
F_10 ( L_4 , V_19 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
unsigned long V_6 ;
void T_2 * V_4 = V_2 -> V_5 ;
if ( V_2 -> V_37 ) {
V_6 = F_2 ( V_4 + V_38 ) ;
V_6 |= V_41 ;
F_4 ( V_6 , V_4 + V_38 ) ;
F_22 ( 10 ) ;
V_6 = F_2 ( V_4 + V_38 ) ;
V_6 &= ~ V_41 ;
F_4 ( V_6 , V_4 + V_38 ) ;
} else
F_6 ( V_2 , false ) ;
if ( F_21 ( V_4 + V_38 , V_40 ,
V_40 ) )
F_10 ( L_4 , V_19 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
unsigned long V_6 ;
void T_2 * V_4 = V_2 -> V_5 ;
struct V_22 * V_23 = V_2 -> V_23 ;
V_6 = F_2 ( V_4 + V_38 ) ;
V_6 |= V_42 ;
F_4 ( V_6 , V_4 + V_38 ) ;
if ( V_2 -> V_37 ) {
V_6 = F_2 ( V_4 + V_43 ) ;
V_6 |= V_44 ;
F_4 ( V_6 , V_4 + V_43 ) ;
}
V_6 = F_2 ( V_4 + V_45 ) ;
V_6 |= V_46 ;
F_4 ( V_6 , V_4 + V_45 ) ;
V_6 = F_2 ( V_4 + V_47 ) ;
V_6 &= ~ ( F_26 ( ~ 0 ) | F_27 ( ~ 0 ) ) ;
V_6 |= F_26 ( V_23 -> V_48 ) ;
V_6 |= F_27 ( V_23 -> V_49 ) ;
F_4 ( V_6 , V_4 + V_47 ) ;
V_6 = F_2 ( V_4 + V_50 ) ;
V_6 &= ~ F_28 ( ~ 0 ) ;
V_6 |= F_28 ( V_23 -> V_51 ) ;
F_4 ( V_6 , V_4 + V_50 ) ;
V_6 = F_2 ( V_4 + V_52 ) ;
V_6 &= ~ F_29 ( ~ 0 ) ;
V_6 |= F_29 ( V_2 -> V_53 -> V_54 ) ;
F_4 ( V_6 , V_4 + V_52 ) ;
V_6 = F_2 ( V_4 + V_55 ) ;
V_6 &= ~ V_56 ;
F_4 ( V_6 , V_4 + V_55 ) ;
if ( ! V_2 -> V_7 -> V_57 ) {
V_6 = F_2 ( V_4 + V_58 ) ;
V_6 &= ~ ( F_30 ( ~ 0 ) |
F_31 ( ~ 0 ) ) ;
V_6 |= F_30 ( V_2 -> V_53 -> V_59 ) |
F_31 ( V_2 -> V_53 -> V_60 ) ;
F_4 ( V_6 , V_4 + V_58 ) ;
V_6 = F_2 ( V_4 + V_61 ) ;
V_6 &= ~ ( F_32 ( ~ 0 ) |
F_33 ( ~ 0 ) ) ;
V_6 |= F_32 ( V_2 -> V_53 -> V_62 ) |
F_33 ( V_2 -> V_53 -> V_63 ) ;
F_4 ( V_6 , V_4 + V_61 ) ;
}
if ( V_2 -> V_64 == V_65 ) {
V_6 = F_2 ( V_4 + V_38 ) ;
V_6 &= ~ ( V_66 | V_67 ) ;
F_4 ( V_6 , V_4 + V_38 ) ;
V_6 = F_2 ( V_4 + V_68 ) ;
V_6 &= ~ V_69 ;
F_4 ( V_6 , V_4 + V_68 ) ;
} else {
V_6 = F_2 ( V_4 + V_68 ) ;
V_6 |= V_69 ;
F_4 ( V_6 , V_4 + V_68 ) ;
}
F_12 ( V_2 ) ;
V_6 = F_2 ( V_4 + V_70 ) ;
V_6 &= ~ ( V_71 | V_72 |
V_73 | V_74 |
F_34 ( ~ 0 ) | F_35 ( ~ 0 ) |
F_36 ( ~ 0 ) | F_37 ( ~ 0 ) ) ;
if ( ! V_23 -> V_75 ) {
V_6 |= F_34 ( V_23 -> V_76 ) ;
V_6 |= F_35 ( V_23 -> V_76 ) ;
}
V_6 |= F_36 ( V_23 -> V_77 ) ;
V_6 |= F_37 ( V_23 -> V_78 ) ;
if ( V_2 -> V_7 -> V_29 ) {
V_6 &= ~ ( F_38 ( ~ 0 ) | F_39 ( ~ 0 ) ) ;
V_6 |= F_38 ( V_23 -> V_79 ) ;
V_6 |= F_39 ( V_23 -> V_79 ) ;
}
F_4 ( V_6 , V_4 + V_70 ) ;
V_6 = F_2 ( V_4 + V_80 ) ;
V_6 &= ~ ( V_81 | V_82 |
V_83 | F_40 ( ~ 0 ) ) ;
V_6 |= F_40 ( V_23 -> V_84 ) ;
F_4 ( V_6 , V_4 + V_80 ) ;
V_6 = F_2 ( V_4 + V_85 ) ;
V_6 &= ~ F_41 ( ~ 0 ) ;
V_6 |= F_41 ( 0x5 ) ;
F_4 ( V_6 , V_4 + V_85 ) ;
V_6 = F_2 ( V_4 + V_86 ) ;
if ( V_23 -> V_75 )
V_6 |= V_87 ;
else
V_6 &= ~ V_87 ;
F_4 ( V_6 , V_4 + V_86 ) ;
if ( ! V_2 -> V_37 ) {
V_6 = F_2 ( V_4 + V_38 ) ;
V_6 |= V_88 ;
F_4 ( V_6 , V_4 + V_38 ) ;
}
V_6 = F_2 ( V_4 + V_38 ) ;
V_6 &= ~ V_42 ;
F_4 ( V_6 , V_4 + V_38 ) ;
if ( V_2 -> V_37 ) {
V_6 = F_2 ( V_4 + V_43 ) ;
V_6 &= ~ V_89 ;
V_6 |= V_90 ;
F_4 ( V_6 , V_4 + V_43 ) ;
V_6 = F_2 ( V_4 + V_38 ) ;
V_6 &= ~ V_39 ;
F_4 ( V_6 , V_4 + V_38 ) ;
}
F_24 ( V_2 ) ;
if ( V_2 -> V_7 -> V_91 ) {
V_6 = F_2 ( V_4 + V_92 ) ;
V_6 &= ~ V_93 ;
if ( V_2 -> V_64 == V_94 )
V_6 |= V_95 ;
else
V_6 |= V_96 ;
F_4 ( V_6 , V_4 + V_92 ) ;
}
if ( ! V_2 -> V_37 )
F_1 ( V_2 , 0 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
unsigned long V_6 ;
void T_2 * V_4 = V_2 -> V_5 ;
F_23 ( V_2 ) ;
if ( V_2 -> V_64 == V_65 ) {
V_6 = F_2 ( V_4 + V_38 ) ;
V_6 &= ~ F_43 ( ~ 0 ) ;
V_6 |= V_66 | F_43 ( 5 ) ;
F_4 ( V_6 , V_4 + V_38 ) ;
}
V_6 = F_2 ( V_4 + V_38 ) ;
V_6 |= V_42 ;
F_4 ( V_6 , V_4 + V_38 ) ;
V_6 = F_2 ( V_4 + V_68 ) ;
V_6 |= V_69 ;
F_4 ( V_6 , V_4 + V_68 ) ;
V_6 = F_2 ( V_4 + V_70 ) ;
V_6 |= V_71 | V_72 |
V_73 ;
F_4 ( V_6 , V_4 + V_70 ) ;
V_6 = F_2 ( V_4 + V_80 ) ;
V_6 |= V_81 | V_82 |
V_83 ;
F_4 ( V_6 , V_4 + V_80 ) ;
return F_20 ( V_2 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
unsigned long V_6 ;
void T_2 * V_4 = V_2 -> V_5 ;
V_6 = F_2 ( V_4 + V_45 ) ;
V_6 |= V_97 ;
F_4 ( V_6 , V_4 + V_45 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
unsigned long V_6 ;
void T_2 * V_4 = V_2 -> V_5 ;
V_6 = F_2 ( V_4 + V_45 ) ;
V_6 &= ~ V_97 ;
F_4 ( V_6 , V_4 + V_45 ) ;
}
static void F_46 ( struct V_1 * V_2 ,
enum V_98 V_99 )
{
unsigned long V_6 ;
void T_2 * V_4 = V_2 -> V_5 ;
V_6 = F_2 ( V_4 + V_55 ) ;
V_6 &= ~ F_47 ( ~ 0 ) ;
if ( V_99 == V_100 )
V_6 |= V_101 ;
else
V_6 |= V_102 ;
F_4 ( V_6 , V_4 + V_55 ) ;
F_22 ( 1 ) ;
V_6 = F_2 ( V_4 + V_55 ) ;
V_6 |= V_103 ;
F_4 ( V_6 , V_4 + V_55 ) ;
F_22 ( 10 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
unsigned long V_6 ;
void T_2 * V_4 = V_2 -> V_5 ;
V_6 = F_2 ( V_4 + V_55 ) ;
V_6 &= ~ V_103 ;
F_4 ( V_6 , V_4 + V_55 ) ;
F_22 ( 10 ) ;
}
static int F_49 ( struct V_1 * V_2 )
{
int V_104 ;
unsigned long V_6 ;
void T_2 * V_4 = V_2 -> V_5 ;
V_104 = F_50 ( V_2 -> V_105 , 0 ) ;
if ( V_104 < 0 ) {
F_51 ( V_2 -> V_17 . V_18 , L_5 ,
V_2 -> V_105 ) ;
return V_104 ;
}
F_52 ( 5 ) ;
V_104 = F_50 ( V_2 -> V_105 , 1 ) ;
if ( V_104 < 0 ) {
F_51 ( V_2 -> V_17 . V_18 , L_6 ,
V_2 -> V_105 ) ;
return V_104 ;
}
F_13 ( V_2 -> V_106 ) ;
F_52 ( 1 ) ;
V_6 = F_2 ( V_4 + V_38 ) ;
V_6 |= V_107 ;
F_4 ( V_6 , V_4 + V_38 ) ;
V_6 = F_2 ( V_4 + V_108 ) ;
V_6 |= V_109 | V_110 ;
F_4 ( V_6 , V_4 + V_108 ) ;
V_6 = F_2 ( V_4 + V_38 ) ;
V_6 |= V_111 ;
F_4 ( V_6 , V_4 + V_38 ) ;
V_6 = 0 ;
F_4 ( V_6 , V_4 + V_112 ) ;
V_6 |= F_53 ( 4 ) ;
V_6 |= F_54 ( 4 ) ;
V_6 |= F_55 ( 4 ) ;
F_4 ( V_6 , V_4 + V_112 ) ;
F_22 ( 10 ) ;
V_6 |= V_113 ;
V_6 |= V_114 ;
V_6 |= V_115 ;
F_4 ( V_6 , V_4 + V_112 ) ;
V_104 = F_56 ( V_2 -> V_116 , 0x40 , 0x08 ) ;
if ( V_104 ) {
F_10 ( L_7 , V_19 ) ;
return V_104 ;
}
V_104 = F_56 ( V_2 -> V_116 , 0x80 , 0x0B ) ;
if ( V_104 ) {
F_10 ( L_7 , V_19 ) ;
return V_104 ;
}
V_6 = F_2 ( V_4 + V_38 ) ;
V_6 |= V_41 ;
F_4 ( V_6 , V_4 + V_38 ) ;
F_22 ( 100 ) ;
V_6 = F_2 ( V_4 + V_38 ) ;
V_6 &= ~ V_41 ;
F_4 ( V_6 , V_4 + V_38 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 )
{
F_58 ( V_2 -> V_106 ) ;
return F_50 ( V_2 -> V_105 , 0 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
if ( ! F_9 ( V_2 -> V_117 ) )
F_60 ( V_2 -> V_117 ) ;
F_19 ( V_2 -> V_118 ) ;
}
static int F_61 ( struct V_1 * V_2 )
{
if ( V_2 -> V_119 )
return F_49 ( V_2 ) ;
else
return F_25 ( V_2 ) ;
}
static int F_62 ( struct V_1 * V_2 )
{
if ( V_2 -> V_119 )
return F_57 ( V_2 ) ;
else
return F_42 ( V_2 ) ;
}
static int F_63 ( struct V_120 * V_121 , int V_122 )
{
struct V_1 * V_2 = F_64 ( V_121 , struct V_1 , V_17 ) ;
if ( V_122 )
return F_62 ( V_2 ) ;
else
return F_61 ( V_2 ) ;
}
static int F_65 ( struct V_1 * V_2 )
{
int V_123 ;
V_2 -> V_106 = F_8 ( V_2 -> V_17 . V_18 , L_8 ) ;
if ( F_9 ( V_2 -> V_106 ) ) {
F_10 ( L_9 , V_19 ) ;
return F_11 ( V_2 -> V_106 ) ;
}
V_123 = F_66 ( V_2 -> V_17 . V_18 , V_2 -> V_105 ,
L_10 ) ;
if ( V_123 < 0 ) {
F_51 ( V_2 -> V_17 . V_18 , L_11 ,
V_2 -> V_105 ) ;
return V_123 ;
}
V_123 = F_50 ( V_2 -> V_105 , 0 ) ;
if ( V_123 < 0 ) {
F_51 ( V_2 -> V_17 . V_18 , L_12 ,
V_2 -> V_105 ) ;
return V_123 ;
}
V_2 -> V_116 = F_67 ( & V_124 , 0 ) ;
if ( ! V_2 -> V_116 ) {
F_51 ( V_2 -> V_17 . V_18 , L_13 ) ;
V_123 = - V_125 ;
return V_123 ;
}
V_2 -> V_116 -> V_126 = V_2 -> V_5 + V_127 ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 )
{
unsigned long V_128 ;
int V_129 ;
int V_123 ;
V_2 -> V_118 = F_8 ( V_2 -> V_17 . V_18 , L_14 ) ;
if ( F_9 ( V_2 -> V_118 ) ) {
F_10 ( L_15 ) ;
return F_11 ( V_2 -> V_118 ) ;
}
V_123 = F_13 ( V_2 -> V_118 ) ;
if ( V_123 )
return V_123 ;
V_128 = F_69 ( F_70 ( V_2 -> V_118 ) ) ;
for ( V_129 = 0 ; V_129 < F_71 ( V_130 ) ; V_129 ++ ) {
if ( V_130 [ V_129 ] . V_53 == V_128 ) {
V_2 -> V_53 = & V_130 [ V_129 ] ;
break;
}
}
if ( ! V_2 -> V_53 ) {
F_10 ( L_16 , V_128 ) ;
V_123 = - V_32 ;
goto V_131;
}
if ( ! F_9 ( V_2 -> V_117 ) ) {
V_123 = F_72 ( V_2 -> V_117 ) ;
if ( V_123 ) {
F_51 ( V_2 -> V_17 . V_18 ,
L_17 ,
V_123 ) ;
goto V_131;
}
}
if ( V_2 -> V_119 )
V_123 = F_65 ( V_2 ) ;
else
V_123 = F_7 ( V_2 ) ;
if ( V_123 < 0 )
goto V_131;
return 0 ;
V_131:
F_19 ( V_2 -> V_118 ) ;
return V_123 ;
}
void F_73 ( struct V_120 * V_121 )
{
struct V_1 * V_2 = F_64 ( V_121 , struct V_1 , V_17 ) ;
if ( ! V_2 -> V_119 )
F_44 ( V_2 ) ;
}
void F_74 ( struct V_120 * V_121 )
{
struct V_1 * V_2 = F_64 ( V_121 , struct V_1 , V_17 ) ;
if ( ! V_2 -> V_119 )
F_45 ( V_2 ) ;
}
void F_75 ( struct V_120 * V_121 ,
enum V_98 V_99 )
{
struct V_1 * V_2 = F_64 ( V_121 , struct V_1 , V_17 ) ;
if ( ! V_2 -> V_119 )
F_46 ( V_2 , V_99 ) ;
}
void F_76 ( struct V_120 * V_121 )
{
struct V_1 * V_2 = F_64 ( V_121 , struct V_1 , V_17 ) ;
if ( ! V_2 -> V_119 )
F_48 ( V_2 ) ;
}
static int F_77 ( struct V_132 * V_133 , const char * V_134 ,
T_1 * V_135 )
{
T_3 V_136 ;
int V_123 = F_78 ( V_133 -> V_18 . V_137 , V_134 , & V_136 ) ;
* V_135 = ( T_1 ) V_136 ;
if ( V_123 < 0 )
F_51 ( & V_133 -> V_18 , L_18 ,
V_134 , V_123 ) ;
return V_123 ;
}
static int F_79 ( struct V_1 * V_138 ,
struct V_132 * V_133 )
{
struct V_139 * V_140 ;
int V_123 ;
struct V_22 * V_23 ;
V_138 -> V_119 = false ;
V_140 = F_80 ( V_133 , V_141 , 1 ) ;
if ( ! V_140 ) {
F_51 ( & V_133 -> V_18 , L_19 ) ;
return - V_142 ;
}
V_138 -> V_21 = F_81 ( & V_133 -> V_18 , V_140 -> V_143 ,
F_82 ( V_140 ) ) ;
if ( ! V_138 -> V_21 ) {
F_51 ( & V_133 -> V_18 , L_20 ) ;
return - V_125 ;
}
V_138 -> V_23 = F_83 ( & V_133 -> V_18 , sizeof( * V_23 ) ,
V_144 ) ;
if ( ! V_138 -> V_23 ) {
F_51 ( & V_133 -> V_18 ,
L_21 ) ;
return - V_125 ;
}
V_23 = V_138 -> V_23 ;
V_123 = F_77 ( V_133 , L_22 ,
& V_23 -> V_51 ) ;
if ( V_123 < 0 )
return V_123 ;
V_123 = F_77 ( V_133 , L_23 ,
& V_23 -> V_49 ) ;
if ( V_123 < 0 )
return V_123 ;
V_123 = F_77 ( V_133 , L_24 ,
& V_23 -> V_48 ) ;
if ( V_123 < 0 )
return V_123 ;
V_123 = F_77 ( V_133 , L_25 ,
& V_23 -> V_84 ) ;
if ( V_123 < 0 )
return V_123 ;
V_123 = F_77 ( V_133 , L_26 ,
& V_23 -> V_77 ) ;
if ( V_123 < 0 )
return V_123 ;
V_123 = F_77 ( V_133 , L_27 ,
& V_23 -> V_78 ) ;
if ( V_123 < 0 )
return V_123 ;
if ( V_138 -> V_7 -> V_29 ) {
V_123 = F_77 ( V_133 , L_28 ,
& V_23 -> V_79 ) ;
if ( V_123 < 0 )
return V_123 ;
V_123 = F_77 ( V_133 , L_29 ,
& V_23 -> V_30 ) ;
if ( V_123 < 0 )
return V_123 ;
V_123 = F_77 ( V_133 , L_30 ,
& V_23 -> V_31 ) ;
if ( V_123 < 0 )
return V_123 ;
}
V_23 -> V_75 = F_84 (
V_133 -> V_18 . V_137 , L_31 ) ;
if ( ! V_23 -> V_75 ) {
V_123 = F_77 ( V_133 , L_32 ,
& V_23 -> V_76 ) ;
if ( V_123 < 0 )
return V_123 ;
}
return 0 ;
}
static int F_85 ( struct V_132 * V_133 )
{
const struct V_145 * V_146 ;
struct V_139 * V_140 ;
struct V_1 * V_138 = NULL ;
struct V_147 * V_148 = V_133 -> V_18 . V_137 ;
enum V_149 V_150 ;
int V_123 ;
V_138 = F_83 ( & V_133 -> V_18 , sizeof( * V_138 ) , V_144 ) ;
if ( ! V_138 ) {
F_51 ( & V_133 -> V_18 , L_33 ) ;
return - V_125 ;
}
V_146 = F_86 ( V_151 , & V_133 -> V_18 ) ;
if ( ! V_146 ) {
F_51 ( & V_133 -> V_18 , L_34 ) ;
return - V_152 ;
}
V_138 -> V_7 = V_146 -> V_153 ;
V_140 = F_80 ( V_133 , V_141 , 0 ) ;
if ( ! V_140 ) {
F_51 ( & V_133 -> V_18 , L_35 ) ;
return - V_142 ;
}
V_138 -> V_5 = F_81 ( & V_133 -> V_18 , V_140 -> V_143 ,
F_82 ( V_140 ) ) ;
if ( ! V_138 -> V_5 ) {
F_51 ( & V_133 -> V_18 , L_36 ) ;
return - V_125 ;
}
V_138 -> V_37 =
F_84 ( V_148 , L_37 ) ;
V_150 = F_87 ( V_148 ) ;
switch ( V_150 ) {
case V_154 :
V_123 = F_79 ( V_138 , V_133 ) ;
if ( V_123 < 0 )
return V_123 ;
break;
case V_155 :
V_138 -> V_119 = true ;
V_138 -> V_105 =
F_88 ( V_148 , L_38 , 0 ) ;
if ( ! F_89 ( V_138 -> V_105 ) ) {
F_51 ( & V_133 -> V_18 , L_39 ,
V_138 -> V_105 ) ;
return V_138 -> V_105 ;
}
V_138 -> V_23 = NULL ;
break;
default:
F_51 ( & V_133 -> V_18 , L_40 ) ;
return - V_32 ;
}
if ( F_90 ( V_148 , L_41 , NULL ) )
V_138 -> V_64 = F_91 ( V_148 ) ;
else
V_138 -> V_64 = V_94 ;
if ( V_138 -> V_64 == V_156 ) {
F_51 ( & V_133 -> V_18 , L_42 ) ;
return - V_32 ;
}
if ( F_90 ( V_148 , L_43 , NULL ) ) {
V_138 -> V_117 = F_92 ( & V_133 -> V_18 , L_44 ) ;
if ( F_9 ( V_138 -> V_117 ) )
return F_11 ( V_138 -> V_117 ) ;
} else {
F_93 ( & V_133 -> V_18 , L_45 ) ;
V_138 -> V_117 = F_94 ( - V_152 ) ;
}
V_138 -> V_17 . V_18 = & V_133 -> V_18 ;
V_123 = F_68 ( V_138 ) ;
if ( V_123 < 0 )
return V_123 ;
V_138 -> V_17 . V_157 = F_63 ;
F_95 ( V_133 , V_138 ) ;
V_123 = F_96 ( & V_138 -> V_17 ) ;
if ( V_123 < 0 ) {
F_59 ( V_138 ) ;
return V_123 ;
}
return 0 ;
}
static int F_97 ( struct V_132 * V_133 )
{
struct V_1 * V_138 = F_98 ( V_133 ) ;
F_99 ( & V_138 -> V_17 ) ;
F_59 ( V_138 ) ;
return 0 ;
}
