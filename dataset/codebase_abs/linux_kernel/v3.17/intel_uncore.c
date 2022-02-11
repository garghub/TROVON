static void
F_1 ( struct V_1 * V_2 )
{
F_2 ( F_3 ( V_2 -> V_3 ) && V_2 -> V_4 . V_5 ,
L_1 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
T_1 V_6 ;
if ( F_5 ( V_2 -> V_3 ) )
V_6 = V_7 ;
else
V_6 = V_8 ;
if ( F_6 ( ( F_7 ( V_2 , V_9 ) & V_6 ) == 0 , 500 ) )
F_8 ( L_2 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_10 ( V_2 , V_10 , 0 ) ;
F_11 ( V_2 , V_11 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
int V_12 )
{
if ( F_13 ( ( F_7 ( V_2 , V_13 ) & 1 ) == 0 ,
V_14 ) )
F_8 ( L_3 ) ;
F_10 ( V_2 , V_10 , 1 ) ;
F_11 ( V_2 , V_11 ) ;
if ( F_13 ( ( F_7 ( V_2 , V_13 ) & 1 ) ,
V_14 ) )
F_8 ( L_4 ) ;
F_4 ( V_2 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_10 ( V_2 , V_15 , F_15 ( 0xffff ) ) ;
F_11 ( V_2 , V_11 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
int V_12 )
{
T_1 V_16 ;
if ( F_5 ( V_2 -> V_3 ) || F_17 ( V_2 -> V_3 ) )
V_16 = V_17 ;
else
V_16 = V_18 ;
if ( F_13 ( ( F_7 ( V_2 , V_16 ) & V_19 ) == 0 ,
V_14 ) )
F_8 ( L_3 ) ;
F_10 ( V_2 , V_15 ,
F_18 ( V_19 ) ) ;
F_11 ( V_2 , V_11 ) ;
if ( F_13 ( ( F_7 ( V_2 , V_16 ) & V_19 ) ,
V_14 ) )
F_8 ( L_4 ) ;
if ( F_19 ( V_2 -> V_3 ) -> V_20 < 8 )
F_4 ( V_2 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
T_1 V_21 ;
V_21 = F_7 ( V_2 , V_22 ) ;
if ( F_2 ( V_21 , L_5 , V_21 ) )
F_10 ( V_2 , V_22 , V_21 ) ;
}
static void F_21 ( struct V_1 * V_2 ,
int V_12 )
{
F_10 ( V_2 , V_10 , 0 ) ;
F_11 ( V_2 , V_11 ) ;
F_20 ( V_2 ) ;
}
static void F_22 ( struct V_1 * V_2 ,
int V_12 )
{
F_10 ( V_2 , V_15 ,
F_15 ( V_19 ) ) ;
F_11 ( V_2 , V_11 ) ;
if ( F_23 ( V_2 -> V_3 ) )
F_20 ( V_2 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
int V_23 = 0 ;
if ( F_25 ( V_2 -> V_3 ) )
V_2 -> V_24 . V_25 =
F_7 ( V_2 , V_26 ) &
V_27 ;
if ( V_2 -> V_24 . V_25 < V_28 ) {
int V_29 = 500 ;
T_1 V_30 = F_7 ( V_2 , V_26 ) & V_27 ;
while ( V_30 <= V_28 && V_29 -- ) {
F_26 ( 10 ) ;
V_30 = F_7 ( V_2 , V_26 ) & V_27 ;
}
if ( F_27 ( V_29 < 0 && V_30 <= V_28 ) )
++ V_23 ;
V_2 -> V_24 . V_25 = V_30 ;
}
V_2 -> V_24 . V_25 -- ;
return V_23 ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_10 ( V_2 , V_31 ,
F_15 ( 0xffff ) ) ;
F_10 ( V_2 , V_32 ,
F_15 ( 0xffff ) ) ;
F_11 ( V_2 , V_33 ) ;
}
static void F_29 ( struct V_1 * V_2 ,
int V_12 )
{
if ( V_34 & V_12 ) {
if ( F_13 ( ( F_7 ( V_2 ,
V_33 ) &
V_19 ) == 0 ,
V_14 ) )
F_8 ( L_6 ) ;
F_10 ( V_2 , V_31 ,
F_18 ( V_19 ) ) ;
if ( F_13 ( ( F_7 ( V_2 ,
V_33 ) &
V_19 ) ,
V_14 ) )
F_8 ( L_7 ) ;
}
if ( V_35 & V_12 ) {
if ( F_13 ( ( F_7 ( V_2 ,
V_36 ) &
V_19 ) == 0 ,
V_14 ) )
F_8 ( L_8 ) ;
F_10 ( V_2 , V_32 ,
F_18 ( V_19 ) ) ;
if ( F_13 ( ( F_7 ( V_2 ,
V_36 ) &
V_19 ) ,
V_14 ) )
F_8 ( L_9 ) ;
}
if ( ! F_30 ( V_2 -> V_3 ) )
F_4 ( V_2 ) ;
}
static void F_31 ( struct V_1 * V_2 ,
int V_12 )
{
if ( V_34 & V_12 )
F_10 ( V_2 , V_31 ,
F_15 ( V_19 ) ) ;
if ( V_35 & V_12 )
F_10 ( V_2 , V_32 ,
F_15 ( V_19 ) ) ;
F_11 ( V_2 , V_33 ) ;
if ( ! F_30 ( V_2 -> V_3 ) )
F_20 ( V_2 ) ;
}
static void F_32 ( struct V_1 * V_2 , int V_12 )
{
unsigned long V_37 ;
F_33 ( & V_2 -> V_24 . V_38 , V_37 ) ;
if ( V_12 & V_34 &&
V_2 -> V_24 . V_39 ++ != 0 )
V_12 &= ~ V_34 ;
if ( V_12 & V_35 &&
V_2 -> V_24 . V_40 ++ != 0 )
V_12 &= ~ V_35 ;
if ( V_12 )
V_2 -> V_24 . V_41 . V_42 ( V_2 , V_12 ) ;
F_34 ( & V_2 -> V_24 . V_38 , V_37 ) ;
}
static void F_35 ( struct V_1 * V_2 , int V_12 )
{
unsigned long V_37 ;
F_33 ( & V_2 -> V_24 . V_38 , V_37 ) ;
if ( V_12 & V_34 ) {
F_27 ( ! V_2 -> V_24 . V_39 ) ;
if ( -- V_2 -> V_24 . V_39 != 0 )
V_12 &= ~ V_34 ;
}
if ( V_12 & V_35 ) {
F_27 ( ! V_2 -> V_24 . V_40 ) ;
if ( -- V_2 -> V_24 . V_40 != 0 )
V_12 &= ~ V_35 ;
}
if ( V_12 )
V_2 -> V_24 . V_41 . V_43 ( V_2 , V_12 ) ;
F_34 ( & V_2 -> V_24 . V_38 , V_37 ) ;
}
static void F_36 ( unsigned long V_44 )
{
struct V_1 * V_2 = ( void * ) V_44 ;
unsigned long V_37 ;
F_1 ( V_2 ) ;
F_33 ( & V_2 -> V_24 . V_38 , V_37 ) ;
F_27 ( ! V_2 -> V_24 . V_45 ) ;
if ( -- V_2 -> V_24 . V_45 == 0 )
V_2 -> V_24 . V_41 . V_43 ( V_2 , V_46 ) ;
F_34 ( & V_2 -> V_24 . V_38 , V_37 ) ;
F_37 ( V_2 ) ;
}
void F_38 ( struct V_47 * V_3 , bool V_48 )
{
struct V_1 * V_2 = V_3 -> V_49 ;
unsigned long V_37 ;
if ( F_39 ( & V_2 -> V_24 . V_50 ) )
F_36 ( ( unsigned long ) V_2 ) ;
F_33 ( & V_2 -> V_24 . V_38 , V_37 ) ;
if ( F_25 ( V_3 ) )
F_28 ( V_2 ) ;
else if ( F_40 ( V_3 ) || F_23 ( V_3 ) )
F_9 ( V_2 ) ;
if ( F_41 ( V_3 ) || F_5 ( V_3 ) || F_17 ( V_3 ) )
F_14 ( V_2 ) ;
if ( V_48 ) {
unsigned V_51 = 0 ;
if ( F_25 ( V_3 ) ) {
if ( V_2 -> V_24 . V_39 )
V_51 |= V_34 ;
if ( V_2 -> V_24 . V_40 )
V_51 |= V_35 ;
} else {
if ( V_2 -> V_24 . V_45 )
V_51 = V_46 ;
}
if ( V_51 )
V_2 -> V_24 . V_41 . V_42 ( V_2 , V_51 ) ;
if ( F_40 ( V_3 ) || F_23 ( V_3 ) )
V_2 -> V_24 . V_25 =
F_7 ( V_2 , V_26 ) &
V_27 ;
}
F_34 ( & V_2 -> V_24 . V_38 , V_37 ) ;
}
void F_42 ( struct V_47 * V_3 , bool V_52 )
{
struct V_1 * V_2 = V_3 -> V_49 ;
if ( F_43 ( V_3 ) )
F_10 ( V_2 , V_53 , V_54 ) ;
if ( ( F_5 ( V_3 ) || F_44 ( V_3 ) ) &&
( F_7 ( V_2 , V_55 ) == 1 ) ) {
V_2 -> V_56 = 128 ;
F_45 ( L_10 , V_2 -> V_56 ) ;
}
if ( F_40 ( V_3 ) || F_23 ( V_3 ) )
F_10 ( V_2 , V_22 ,
F_7 ( V_2 , V_22 ) ) ;
F_38 ( V_3 , V_52 ) ;
}
void F_46 ( struct V_47 * V_3 )
{
F_47 ( V_3 ) ;
}
void F_48 ( struct V_1 * V_2 , int V_12 )
{
unsigned long V_37 ;
if ( ! V_2 -> V_24 . V_41 . V_42 )
return;
F_49 ( V_2 ) ;
if ( F_25 ( V_2 -> V_3 ) )
return F_32 ( V_2 , V_12 ) ;
F_33 ( & V_2 -> V_24 . V_38 , V_37 ) ;
if ( V_2 -> V_24 . V_45 ++ == 0 )
V_2 -> V_24 . V_41 . V_42 ( V_2 , V_46 ) ;
F_34 ( & V_2 -> V_24 . V_38 , V_37 ) ;
}
void F_50 ( struct V_1 * V_2 , int V_12 )
{
unsigned long V_37 ;
bool V_57 = false ;
if ( ! V_2 -> V_24 . V_41 . V_43 )
return;
if ( F_25 ( V_2 -> V_3 ) ) {
F_35 ( V_2 , V_12 ) ;
goto V_58;
}
F_33 ( & V_2 -> V_24 . V_38 , V_37 ) ;
F_27 ( ! V_2 -> V_24 . V_45 ) ;
if ( -- V_2 -> V_24 . V_45 == 0 ) {
V_2 -> V_24 . V_45 ++ ;
V_57 = true ;
F_51 ( & V_2 -> V_24 . V_50 ,
V_59 + 1 ) ;
}
F_34 ( & V_2 -> V_24 . V_38 , V_37 ) ;
V_58:
if ( ! V_57 )
F_37 ( V_2 ) ;
}
void F_52 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_24 . V_41 . V_42 )
return;
F_27 ( V_2 -> V_24 . V_45 > 0 ) ;
}
static void
F_53 ( struct V_1 * V_2 )
{
F_10 ( V_2 , V_60 , 0 ) ;
}
static void
F_54 ( struct V_1 * V_2 , T_1 V_61 , bool V_62 ,
bool V_63 )
{
const char * V_64 = V_62 ? L_11 : L_12 ;
const char * V_65 = V_63 ? L_13 : L_14 ;
if ( ! V_66 . V_67 )
return;
if ( F_7 ( V_2 , V_53 ) & V_54 ) {
F_2 ( 1 , L_15 ,
V_65 , V_64 , V_61 ) ;
F_10 ( V_2 , V_53 , V_54 ) ;
}
}
static void
F_55 ( struct V_1 * V_2 )
{
if ( V_66 . V_67 )
return;
if ( F_7 ( V_2 , V_53 ) & V_54 ) {
F_8 ( L_16 ) ;
F_10 ( V_2 , V_53 , V_54 ) ;
}
}
static bool F_56 ( struct V_1 * V_2 , T_1 V_61 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < F_57 ( V_69 ) ; V_68 ++ )
if ( V_61 == V_69 [ V_68 ] )
return true ;
return false ;
}
void F_58 ( struct V_47 * V_3 )
{
struct V_1 * V_2 = V_3 -> V_49 ;
F_59 ( & V_2 -> V_24 . V_50 ,
F_36 , ( unsigned long ) V_2 ) ;
F_42 ( V_3 , false ) ;
if ( F_25 ( V_3 ) ) {
V_2 -> V_24 . V_41 . V_42 = F_29 ;
V_2 -> V_24 . V_41 . V_43 = F_31 ;
} else if ( F_5 ( V_3 ) || F_17 ( V_3 ) ) {
V_2 -> V_24 . V_41 . V_42 = F_16 ;
V_2 -> V_24 . V_41 . V_43 = F_22 ;
} else if ( F_41 ( V_3 ) ) {
T_1 V_70 ;
F_60 ( & V_3 -> V_71 ) ;
F_16 ( V_2 , V_46 ) ;
V_70 = F_7 ( V_2 , V_11 ) ;
F_22 ( V_2 , V_46 ) ;
F_61 ( & V_3 -> V_71 ) ;
if ( V_70 & V_72 ) {
V_2 -> V_24 . V_41 . V_42 =
F_16 ;
V_2 -> V_24 . V_41 . V_43 =
F_22 ;
} else {
F_45 ( L_17 ) ;
F_45 ( L_18 ) ;
V_2 -> V_24 . V_41 . V_42 =
F_12 ;
V_2 -> V_24 . V_41 . V_43 =
F_21 ;
}
} else if ( F_40 ( V_3 ) ) {
V_2 -> V_24 . V_41 . V_42 =
F_12 ;
V_2 -> V_24 . V_41 . V_43 =
F_21 ;
}
switch ( F_19 ( V_3 ) -> V_20 ) {
default:
if ( F_30 ( V_3 ) ) {
V_2 -> V_24 . V_41 . V_73 = V_74 ;
V_2 -> V_24 . V_41 . V_75 = V_76 ;
V_2 -> V_24 . V_41 . V_77 = V_78 ;
V_2 -> V_24 . V_41 . V_79 = V_80 ;
V_2 -> V_24 . V_41 . V_81 = V_82 ;
V_2 -> V_24 . V_41 . V_83 = V_84 ;
V_2 -> V_24 . V_41 . V_85 = V_86 ;
V_2 -> V_24 . V_41 . V_87 = V_88 ;
} else {
V_2 -> V_24 . V_41 . V_73 = V_89 ;
V_2 -> V_24 . V_41 . V_75 = V_90 ;
V_2 -> V_24 . V_41 . V_77 = V_91 ;
V_2 -> V_24 . V_41 . V_79 = V_92 ;
V_2 -> V_24 . V_41 . V_81 = V_93 ;
V_2 -> V_24 . V_41 . V_83 = V_94 ;
V_2 -> V_24 . V_41 . V_85 = V_95 ;
V_2 -> V_24 . V_41 . V_87 = V_96 ;
}
break;
case 7 :
case 6 :
if ( F_5 ( V_3 ) ) {
V_2 -> V_24 . V_41 . V_73 = V_97 ;
V_2 -> V_24 . V_41 . V_75 = V_98 ;
V_2 -> V_24 . V_41 . V_77 = V_99 ;
V_2 -> V_24 . V_41 . V_79 = V_100 ;
} else {
V_2 -> V_24 . V_41 . V_73 = V_101 ;
V_2 -> V_24 . V_41 . V_75 = V_102 ;
V_2 -> V_24 . V_41 . V_77 = V_103 ;
V_2 -> V_24 . V_41 . V_79 = V_104 ;
}
if ( F_25 ( V_3 ) ) {
V_2 -> V_24 . V_41 . V_81 = V_105 ;
V_2 -> V_24 . V_41 . V_83 = V_106 ;
V_2 -> V_24 . V_41 . V_85 = V_107 ;
V_2 -> V_24 . V_41 . V_87 = V_108 ;
} else {
V_2 -> V_24 . V_41 . V_81 = V_93 ;
V_2 -> V_24 . V_41 . V_83 = V_94 ;
V_2 -> V_24 . V_41 . V_85 = V_95 ;
V_2 -> V_24 . V_41 . V_87 = V_96 ;
}
break;
case 5 :
V_2 -> V_24 . V_41 . V_73 = V_109 ;
V_2 -> V_24 . V_41 . V_75 = V_110 ;
V_2 -> V_24 . V_41 . V_77 = V_111 ;
V_2 -> V_24 . V_41 . V_79 = V_112 ;
V_2 -> V_24 . V_41 . V_81 = V_113 ;
V_2 -> V_24 . V_41 . V_83 = V_114 ;
V_2 -> V_24 . V_41 . V_85 = V_115 ;
V_2 -> V_24 . V_41 . V_87 = V_116 ;
break;
case 4 :
case 3 :
case 2 :
V_2 -> V_24 . V_41 . V_73 = V_117 ;
V_2 -> V_24 . V_41 . V_75 = V_118 ;
V_2 -> V_24 . V_41 . V_77 = V_119 ;
V_2 -> V_24 . V_41 . V_79 = V_120 ;
V_2 -> V_24 . V_41 . V_81 = V_121 ;
V_2 -> V_24 . V_41 . V_83 = V_122 ;
V_2 -> V_24 . V_41 . V_85 = V_123 ;
V_2 -> V_24 . V_41 . V_87 = V_124 ;
break;
}
}
void F_62 ( struct V_47 * V_3 )
{
F_46 ( V_3 ) ;
F_38 ( V_3 , false ) ;
}
int F_63 ( struct V_47 * V_3 ,
void * V_125 , struct V_126 * V_127 )
{
struct V_1 * V_2 = V_3 -> V_49 ;
struct V_128 * V_61 = V_125 ;
struct V_129 const * V_130 = V_131 ;
int V_68 , V_23 = 0 ;
for ( V_68 = 0 ; V_68 < F_57 ( V_131 ) ; V_68 ++ , V_130 ++ ) {
if ( V_130 -> V_132 == V_61 -> V_132 &&
( 1 << F_19 ( V_3 ) -> V_20 & V_130 -> V_133 ) )
break;
}
if ( V_68 == F_57 ( V_131 ) )
return - V_134 ;
F_49 ( V_2 ) ;
switch ( V_130 -> V_135 ) {
case 8 :
V_61 -> V_136 = F_64 ( V_61 -> V_132 ) ;
break;
case 4 :
V_61 -> V_136 = F_65 ( V_61 -> V_132 ) ;
break;
case 2 :
V_61 -> V_136 = F_66 ( V_61 -> V_132 ) ;
break;
case 1 :
V_61 -> V_136 = F_67 ( V_61 -> V_132 ) ;
break;
default:
F_27 ( 1 ) ;
V_23 = - V_134 ;
goto V_58;
}
V_58:
F_37 ( V_2 ) ;
return V_23 ;
}
int F_68 ( struct V_47 * V_3 ,
void * V_125 , struct V_126 * V_127 )
{
struct V_1 * V_2 = V_3 -> V_49 ;
struct V_137 * args = V_125 ;
struct V_138 * V_139 ;
struct V_140 * V_141 ;
int V_23 ;
if ( args -> V_142 || args -> V_143 )
return - V_134 ;
if ( args -> V_144 == V_145 && ! F_69 ( V_146 ) )
return - V_147 ;
V_23 = F_70 ( & V_3 -> V_71 ) ;
if ( V_23 )
return V_23 ;
V_141 = F_71 ( V_127 -> V_148 , args -> V_144 ) ;
if ( F_72 ( V_141 ) ) {
F_61 ( & V_3 -> V_71 ) ;
return F_73 ( V_141 ) ;
}
V_139 = & V_141 -> V_149 ;
if ( F_69 ( V_146 ) )
args -> V_150 = F_74 ( & V_2 -> V_151 ) ;
else
args -> V_150 = 0 ;
args -> V_152 = V_139 -> V_152 ;
args -> V_153 = V_139 -> V_153 ;
F_61 ( & V_3 -> V_71 ) ;
return 0 ;
}
static int F_75 ( struct V_47 * V_3 )
{
T_2 V_154 ;
F_76 ( V_3 -> V_155 , V_156 , & V_154 ) ;
return ( V_154 & V_157 ) == 0 ;
}
static int F_77 ( struct V_47 * V_3 )
{
int V_23 ;
return - V_158 ;
F_78 ( V_3 -> V_155 , V_156 ,
V_159 | V_157 ) ;
V_23 = F_79 ( F_75 ( V_3 ) , 500 ) ;
if ( V_23 )
return V_23 ;
F_78 ( V_3 -> V_155 , V_156 ,
V_160 | V_157 ) ;
V_23 = F_79 ( F_75 ( V_3 ) , 500 ) ;
if ( V_23 )
return V_23 ;
F_78 ( V_3 -> V_155 , V_156 , 0 ) ;
return 0 ;
}
static int F_80 ( struct V_47 * V_3 )
{
struct V_1 * V_2 = V_3 -> V_49 ;
int V_23 ;
F_78 ( V_3 -> V_155 , V_156 ,
V_159 | V_157 ) ;
V_23 = F_79 ( F_75 ( V_3 ) , 500 ) ;
if ( V_23 )
return V_23 ;
F_81 ( V_161 , F_65 ( V_161 ) | V_162 ) ;
F_82 ( V_161 ) ;
F_78 ( V_3 -> V_155 , V_156 ,
V_160 | V_157 ) ;
V_23 = F_79 ( F_75 ( V_3 ) , 500 ) ;
if ( V_23 )
return V_23 ;
F_81 ( V_161 , F_65 ( V_161 ) & ~ V_162 ) ;
F_82 ( V_161 ) ;
F_78 ( V_3 -> V_155 , V_156 , 0 ) ;
return 0 ;
}
static int F_83 ( struct V_47 * V_3 )
{
struct V_1 * V_2 = V_3 -> V_49 ;
int V_23 ;
F_81 ( V_163 + V_164 ,
V_165 | V_166 ) ;
V_23 = F_79 ( ( F_65 ( V_163 + V_164 ) &
V_166 ) == 0 , 500 ) ;
if ( V_23 )
return V_23 ;
F_81 ( V_163 + V_164 ,
V_167 | V_166 ) ;
V_23 = F_79 ( ( F_65 ( V_163 + V_164 ) &
V_166 ) == 0 , 500 ) ;
if ( V_23 )
return V_23 ;
F_81 ( V_163 + V_164 , 0 ) ;
return 0 ;
}
static int F_84 ( struct V_47 * V_3 )
{
struct V_1 * V_2 = V_3 -> V_49 ;
int V_23 ;
F_10 ( V_2 , V_168 , V_169 ) ;
V_23 = F_79 ( ( F_7 ( V_2 , V_168 ) & V_169 ) == 0 , 500 ) ;
F_38 ( V_3 , true ) ;
return V_23 ;
}
int F_85 ( struct V_47 * V_3 )
{
if ( F_19 ( V_3 ) -> V_20 >= 6 )
return F_84 ( V_3 ) ;
else if ( F_86 ( V_3 ) )
return F_83 ( V_3 ) ;
else if ( F_87 ( V_3 ) )
return F_80 ( V_3 ) ;
else if ( F_88 ( V_3 ) )
return F_77 ( V_3 ) ;
else
return - V_158 ;
}
void F_89 ( struct V_47 * V_3 )
{
struct V_1 * V_2 = V_3 -> V_49 ;
if ( F_43 ( V_3 ) &&
( F_7 ( V_2 , V_53 ) & V_54 ) ) {
F_8 ( L_19 ) ;
F_10 ( V_2 , V_53 , V_54 ) ;
}
}
