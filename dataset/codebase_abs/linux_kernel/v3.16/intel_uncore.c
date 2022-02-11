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
F_4 ( V_2 ) ;
}
static void F_30 ( struct V_1 * V_2 ,
int V_12 )
{
if ( V_34 & V_12 )
F_10 ( V_2 , V_31 ,
F_15 ( V_19 ) ) ;
if ( V_35 & V_12 )
F_10 ( V_2 , V_32 ,
F_15 ( V_19 ) ) ;
F_20 ( V_2 ) ;
}
static void F_31 ( struct V_1 * V_2 , int V_12 )
{
unsigned long V_37 ;
F_32 ( & V_2 -> V_24 . V_38 , V_37 ) ;
if ( V_12 & V_34 &&
V_2 -> V_24 . V_39 ++ != 0 )
V_12 &= ~ V_34 ;
if ( V_12 & V_35 &&
V_2 -> V_24 . V_40 ++ != 0 )
V_12 &= ~ V_35 ;
if ( V_12 )
V_2 -> V_24 . V_41 . V_42 ( V_2 , V_12 ) ;
F_33 ( & V_2 -> V_24 . V_38 , V_37 ) ;
}
static void F_34 ( struct V_1 * V_2 , int V_12 )
{
unsigned long V_37 ;
F_32 ( & V_2 -> V_24 . V_38 , V_37 ) ;
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
F_33 ( & V_2 -> V_24 . V_38 , V_37 ) ;
}
static void F_35 ( unsigned long V_44 )
{
struct V_1 * V_2 = ( void * ) V_44 ;
unsigned long V_37 ;
F_1 ( V_2 ) ;
F_32 ( & V_2 -> V_24 . V_38 , V_37 ) ;
F_27 ( ! V_2 -> V_24 . V_45 ) ;
if ( -- V_2 -> V_24 . V_45 == 0 )
V_2 -> V_24 . V_41 . V_43 ( V_2 , V_46 ) ;
F_33 ( & V_2 -> V_24 . V_38 , V_37 ) ;
F_36 ( V_2 ) ;
}
static void F_37 ( struct V_47 * V_3 , bool V_48 )
{
struct V_1 * V_2 = V_3 -> V_49 ;
unsigned long V_37 ;
if ( F_38 ( & V_2 -> V_24 . V_50 ) )
F_35 ( ( unsigned long ) V_2 ) ;
F_32 ( & V_2 -> V_24 . V_38 , V_37 ) ;
if ( F_25 ( V_3 ) )
F_28 ( V_2 ) ;
else if ( F_39 ( V_3 ) || F_23 ( V_3 ) )
F_9 ( V_2 ) ;
if ( F_40 ( V_3 ) || F_5 ( V_3 ) || F_17 ( V_3 ) )
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
if ( F_39 ( V_3 ) || F_23 ( V_3 ) )
V_2 -> V_24 . V_25 =
F_7 ( V_2 , V_26 ) &
V_27 ;
} else {
V_2 -> V_24 . V_45 = 0 ;
V_2 -> V_24 . V_39 = 0 ;
V_2 -> V_24 . V_40 = 0 ;
}
F_33 ( & V_2 -> V_24 . V_38 , V_37 ) ;
}
void F_41 ( struct V_47 * V_3 )
{
struct V_1 * V_2 = V_3 -> V_49 ;
if ( F_42 ( V_3 ) )
F_10 ( V_2 , V_52 , V_53 ) ;
if ( ( F_5 ( V_3 ) || F_43 ( V_3 ) ) &&
( F_7 ( V_2 , V_54 ) == 1 ) ) {
V_2 -> V_55 = 128 ;
F_44 ( L_10 , V_2 -> V_55 ) ;
}
if ( F_39 ( V_3 ) || F_23 ( V_3 ) )
F_10 ( V_2 , V_22 ,
F_7 ( V_2 , V_22 ) ) ;
F_37 ( V_3 , false ) ;
}
void F_45 ( struct V_47 * V_3 )
{
F_46 ( V_3 ) ;
}
void F_47 ( struct V_1 * V_2 , int V_12 )
{
unsigned long V_37 ;
if ( ! V_2 -> V_24 . V_41 . V_42 )
return;
F_48 ( V_2 ) ;
if ( F_25 ( V_2 -> V_3 ) )
return F_31 ( V_2 , V_12 ) ;
F_32 ( & V_2 -> V_24 . V_38 , V_37 ) ;
if ( V_2 -> V_24 . V_45 ++ == 0 )
V_2 -> V_24 . V_41 . V_42 ( V_2 , V_46 ) ;
F_33 ( & V_2 -> V_24 . V_38 , V_37 ) ;
}
void F_49 ( struct V_1 * V_2 , int V_12 )
{
unsigned long V_37 ;
bool V_56 = false ;
if ( ! V_2 -> V_24 . V_41 . V_43 )
return;
if ( F_25 ( V_2 -> V_3 ) ) {
F_34 ( V_2 , V_12 ) ;
goto V_57;
}
F_32 ( & V_2 -> V_24 . V_38 , V_37 ) ;
F_27 ( ! V_2 -> V_24 . V_45 ) ;
if ( -- V_2 -> V_24 . V_45 == 0 ) {
V_2 -> V_24 . V_45 ++ ;
V_56 = true ;
F_50 ( & V_2 -> V_24 . V_50 ,
V_58 + 1 ) ;
}
F_33 ( & V_2 -> V_24 . V_38 , V_37 ) ;
V_57:
if ( ! V_56 )
F_36 ( V_2 ) ;
}
void F_51 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_24 . V_41 . V_42 )
return;
F_27 ( V_2 -> V_24 . V_45 > 0 ) ;
}
static void
F_52 ( struct V_1 * V_2 )
{
F_10 ( V_2 , V_59 , 0 ) ;
}
static void
F_53 ( struct V_1 * V_2 , T_1 V_60 )
{
if ( F_7 ( V_2 , V_52 ) & V_53 ) {
F_8 ( L_11 ,
V_60 ) ;
F_10 ( V_2 , V_52 , V_53 ) ;
}
}
static void
F_54 ( struct V_1 * V_2 , T_1 V_60 )
{
if ( F_7 ( V_2 , V_52 ) & V_53 ) {
F_8 ( L_12 , V_60 ) ;
F_10 ( V_2 , V_52 , V_53 ) ;
}
}
static bool F_55 ( struct V_1 * V_2 , T_1 V_60 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < F_56 ( V_62 ) ; V_61 ++ )
if ( V_60 == V_62 [ V_61 ] )
return true ;
return false ;
}
void F_57 ( struct V_47 * V_3 )
{
struct V_1 * V_2 = V_3 -> V_49 ;
F_58 ( & V_2 -> V_24 . V_50 ,
F_35 , ( unsigned long ) V_2 ) ;
F_41 ( V_3 ) ;
if ( F_25 ( V_3 ) ) {
V_2 -> V_24 . V_41 . V_42 = F_29 ;
V_2 -> V_24 . V_41 . V_43 = F_30 ;
} else if ( F_5 ( V_3 ) || F_17 ( V_3 ) ) {
V_2 -> V_24 . V_41 . V_42 = F_16 ;
V_2 -> V_24 . V_41 . V_43 = F_22 ;
} else if ( F_40 ( V_3 ) ) {
T_1 V_63 ;
F_59 ( & V_3 -> V_64 ) ;
F_16 ( V_2 , V_46 ) ;
V_63 = F_7 ( V_2 , V_11 ) ;
F_22 ( V_2 , V_46 ) ;
F_60 ( & V_3 -> V_64 ) ;
if ( V_63 & V_65 ) {
V_2 -> V_24 . V_41 . V_42 =
F_16 ;
V_2 -> V_24 . V_41 . V_43 =
F_22 ;
} else {
F_44 ( L_13 ) ;
F_44 ( L_14 ) ;
V_2 -> V_24 . V_41 . V_42 =
F_12 ;
V_2 -> V_24 . V_41 . V_43 =
F_21 ;
}
} else if ( F_39 ( V_3 ) ) {
V_2 -> V_24 . V_41 . V_42 =
F_12 ;
V_2 -> V_24 . V_41 . V_43 =
F_21 ;
}
switch ( F_19 ( V_3 ) -> V_20 ) {
default:
V_2 -> V_24 . V_41 . V_66 = V_67 ;
V_2 -> V_24 . V_41 . V_68 = V_69 ;
V_2 -> V_24 . V_41 . V_70 = V_71 ;
V_2 -> V_24 . V_41 . V_72 = V_73 ;
V_2 -> V_24 . V_41 . V_74 = V_75 ;
V_2 -> V_24 . V_41 . V_76 = V_77 ;
V_2 -> V_24 . V_41 . V_78 = V_79 ;
V_2 -> V_24 . V_41 . V_80 = V_81 ;
break;
case 7 :
case 6 :
if ( F_5 ( V_3 ) ) {
V_2 -> V_24 . V_41 . V_66 = V_82 ;
V_2 -> V_24 . V_41 . V_68 = V_83 ;
V_2 -> V_24 . V_41 . V_70 = V_84 ;
V_2 -> V_24 . V_41 . V_72 = V_85 ;
} else {
V_2 -> V_24 . V_41 . V_66 = V_86 ;
V_2 -> V_24 . V_41 . V_68 = V_87 ;
V_2 -> V_24 . V_41 . V_70 = V_88 ;
V_2 -> V_24 . V_41 . V_72 = V_89 ;
}
if ( F_25 ( V_3 ) ) {
V_2 -> V_24 . V_41 . V_74 = V_90 ;
V_2 -> V_24 . V_41 . V_76 = V_91 ;
V_2 -> V_24 . V_41 . V_78 = V_92 ;
V_2 -> V_24 . V_41 . V_80 = V_93 ;
} else {
V_2 -> V_24 . V_41 . V_74 = V_75 ;
V_2 -> V_24 . V_41 . V_76 = V_77 ;
V_2 -> V_24 . V_41 . V_78 = V_79 ;
V_2 -> V_24 . V_41 . V_80 = V_81 ;
}
break;
case 5 :
V_2 -> V_24 . V_41 . V_66 = V_94 ;
V_2 -> V_24 . V_41 . V_68 = V_95 ;
V_2 -> V_24 . V_41 . V_70 = V_96 ;
V_2 -> V_24 . V_41 . V_72 = V_97 ;
V_2 -> V_24 . V_41 . V_74 = V_98 ;
V_2 -> V_24 . V_41 . V_76 = V_99 ;
V_2 -> V_24 . V_41 . V_78 = V_100 ;
V_2 -> V_24 . V_41 . V_80 = V_101 ;
break;
case 4 :
case 3 :
case 2 :
V_2 -> V_24 . V_41 . V_66 = V_102 ;
V_2 -> V_24 . V_41 . V_68 = V_103 ;
V_2 -> V_24 . V_41 . V_70 = V_104 ;
V_2 -> V_24 . V_41 . V_72 = V_105 ;
V_2 -> V_24 . V_41 . V_74 = V_106 ;
V_2 -> V_24 . V_41 . V_76 = V_107 ;
V_2 -> V_24 . V_41 . V_78 = V_108 ;
V_2 -> V_24 . V_41 . V_80 = V_109 ;
break;
}
}
void F_61 ( struct V_47 * V_3 )
{
F_45 ( V_3 ) ;
F_37 ( V_3 , false ) ;
}
int F_62 ( struct V_47 * V_3 ,
void * V_110 , struct V_111 * V_112 )
{
struct V_1 * V_2 = V_3 -> V_49 ;
struct V_113 * V_60 = V_110 ;
struct V_114 const * V_115 = V_116 ;
int V_61 , V_23 = 0 ;
for ( V_61 = 0 ; V_61 < F_56 ( V_116 ) ; V_61 ++ , V_115 ++ ) {
if ( V_115 -> V_117 == V_60 -> V_117 &&
( 1 << F_19 ( V_3 ) -> V_20 & V_115 -> V_118 ) )
break;
}
if ( V_61 == F_56 ( V_116 ) )
return - V_119 ;
F_48 ( V_2 ) ;
switch ( V_115 -> V_120 ) {
case 8 :
V_60 -> V_121 = F_63 ( V_60 -> V_117 ) ;
break;
case 4 :
V_60 -> V_121 = F_64 ( V_60 -> V_117 ) ;
break;
case 2 :
V_60 -> V_121 = F_65 ( V_60 -> V_117 ) ;
break;
case 1 :
V_60 -> V_121 = F_66 ( V_60 -> V_117 ) ;
break;
default:
F_27 ( 1 ) ;
V_23 = - V_119 ;
goto V_57;
}
V_57:
F_36 ( V_2 ) ;
return V_23 ;
}
int F_67 ( struct V_47 * V_3 ,
void * V_110 , struct V_111 * V_112 )
{
struct V_1 * V_2 = V_3 -> V_49 ;
struct V_122 * args = V_110 ;
struct V_123 * V_124 ;
struct V_125 * V_126 ;
int V_23 ;
if ( args -> V_127 || args -> V_128 )
return - V_119 ;
if ( args -> V_129 == V_130 && ! F_68 ( V_131 ) )
return - V_132 ;
V_23 = F_69 ( & V_3 -> V_64 ) ;
if ( V_23 )
return V_23 ;
V_126 = F_70 ( V_112 -> V_133 , args -> V_129 ) ;
if ( F_71 ( V_126 ) ) {
F_60 ( & V_3 -> V_64 ) ;
return F_72 ( V_126 ) ;
}
V_124 = & V_126 -> V_134 ;
if ( F_68 ( V_131 ) )
args -> V_135 = F_73 ( & V_2 -> V_136 ) ;
else
args -> V_135 = 0 ;
args -> V_137 = V_124 -> V_137 ;
args -> V_138 = V_124 -> V_138 ;
F_60 ( & V_3 -> V_64 ) ;
return 0 ;
}
static int F_74 ( struct V_47 * V_3 )
{
T_2 V_139 ;
F_75 ( V_3 -> V_140 , V_141 , & V_139 ) ;
return ( V_139 & V_142 ) == 0 ;
}
static int F_76 ( struct V_47 * V_3 )
{
int V_23 ;
return - V_143 ;
F_77 ( V_3 -> V_140 , V_141 ,
V_144 | V_142 ) ;
V_23 = F_78 ( F_74 ( V_3 ) , 500 ) ;
if ( V_23 )
return V_23 ;
F_77 ( V_3 -> V_140 , V_141 ,
V_145 | V_142 ) ;
V_23 = F_78 ( F_74 ( V_3 ) , 500 ) ;
if ( V_23 )
return V_23 ;
F_77 ( V_3 -> V_140 , V_141 , 0 ) ;
return 0 ;
}
static int F_79 ( struct V_47 * V_3 )
{
struct V_1 * V_2 = V_3 -> V_49 ;
int V_23 ;
F_77 ( V_3 -> V_140 , V_141 ,
V_144 | V_142 ) ;
V_23 = F_78 ( F_74 ( V_3 ) , 500 ) ;
if ( V_23 )
return V_23 ;
F_80 ( V_146 , F_64 ( V_146 ) | V_147 ) ;
F_81 ( V_146 ) ;
F_77 ( V_3 -> V_140 , V_141 ,
V_145 | V_142 ) ;
V_23 = F_78 ( F_74 ( V_3 ) , 500 ) ;
if ( V_23 )
return V_23 ;
F_80 ( V_146 , F_64 ( V_146 ) & ~ V_147 ) ;
F_81 ( V_146 ) ;
F_77 ( V_3 -> V_140 , V_141 , 0 ) ;
return 0 ;
}
static int F_82 ( struct V_47 * V_3 )
{
struct V_1 * V_2 = V_3 -> V_49 ;
int V_23 ;
F_80 ( V_148 + V_149 ,
V_150 | V_151 ) ;
V_23 = F_78 ( ( F_64 ( V_148 + V_149 ) &
V_151 ) == 0 , 500 ) ;
if ( V_23 )
return V_23 ;
F_80 ( V_148 + V_149 ,
V_152 | V_151 ) ;
V_23 = F_78 ( ( F_64 ( V_148 + V_149 ) &
V_151 ) == 0 , 500 ) ;
if ( V_23 )
return V_23 ;
F_80 ( V_148 + V_149 , 0 ) ;
return 0 ;
}
static int F_83 ( struct V_47 * V_3 )
{
struct V_1 * V_2 = V_3 -> V_49 ;
int V_23 ;
F_10 ( V_2 , V_153 , V_154 ) ;
V_23 = F_78 ( ( F_7 ( V_2 , V_153 ) & V_154 ) == 0 , 500 ) ;
F_37 ( V_3 , true ) ;
return V_23 ;
}
int F_84 ( struct V_47 * V_3 )
{
switch ( F_19 ( V_3 ) -> V_20 ) {
case 8 :
case 7 :
case 6 : return F_83 ( V_3 ) ;
case 5 : return F_82 ( V_3 ) ;
case 4 :
if ( F_85 ( V_3 ) )
return F_79 ( V_3 ) ;
else
return F_76 ( V_3 ) ;
default: return - V_143 ;
}
}
void F_86 ( struct V_47 * V_3 )
{
struct V_1 * V_2 = V_3 -> V_49 ;
if ( F_42 ( V_3 ) &&
( F_7 ( V_2 , V_52 ) & V_53 ) ) {
F_8 ( L_15 ) ;
F_10 ( V_2 , V_52 , V_53 ) ;
}
}
