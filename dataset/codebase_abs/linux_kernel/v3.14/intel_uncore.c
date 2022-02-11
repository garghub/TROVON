static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
if ( F_2 ( V_2 -> V_4 ) )
V_3 = V_5 ;
else
V_3 = V_6 ;
if ( F_3 ( ( F_4 ( V_2 , V_7 ) & V_3 ) == 0 , 500 ) )
F_5 ( L_1 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_8 , 0 ) ;
F_8 ( V_2 , V_9 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
int V_10 )
{
if ( F_10 ( ( F_4 ( V_2 , V_11 ) & 1 ) == 0 ,
V_12 ) )
F_5 ( L_2 ) ;
F_7 ( V_2 , V_8 , 1 ) ;
F_8 ( V_2 , V_9 ) ;
if ( F_10 ( ( F_4 ( V_2 , V_11 ) & 1 ) ,
V_12 ) )
F_5 ( L_3 ) ;
F_1 ( V_2 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_13 , F_12 ( 0xffff ) ) ;
F_8 ( V_2 , V_9 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
int V_10 )
{
T_1 V_14 ;
if ( F_2 ( V_2 -> V_4 ) || F_14 ( V_2 -> V_4 ) )
V_14 = V_15 ;
else
V_14 = V_16 ;
if ( F_10 ( ( F_4 ( V_2 , V_14 ) & V_17 ) == 0 ,
V_12 ) )
F_5 ( L_2 ) ;
F_7 ( V_2 , V_13 ,
F_15 ( V_17 ) ) ;
F_8 ( V_2 , V_9 ) ;
if ( F_10 ( ( F_4 ( V_2 , V_14 ) & V_17 ) ,
V_12 ) )
F_5 ( L_3 ) ;
if ( F_16 ( V_2 -> V_4 ) -> V_18 < 8 )
F_1 ( V_2 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
T_1 V_19 ;
V_19 = F_4 ( V_2 , V_20 ) ;
if ( F_18 ( V_19 , L_4 , V_19 ) )
F_7 ( V_2 , V_20 , V_19 ) ;
}
static void F_19 ( struct V_1 * V_2 ,
int V_10 )
{
F_7 ( V_2 , V_8 , 0 ) ;
F_8 ( V_2 , V_9 ) ;
F_17 ( V_2 ) ;
}
static void F_20 ( struct V_1 * V_2 ,
int V_10 )
{
F_7 ( V_2 , V_13 ,
F_12 ( V_17 ) ) ;
F_8 ( V_2 , V_9 ) ;
F_17 ( V_2 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_21 = 0 ;
if ( F_22 ( V_2 -> V_4 ) )
V_2 -> V_22 . V_23 =
F_4 ( V_2 , V_24 ) &
V_25 ;
if ( V_2 -> V_22 . V_23 < V_26 ) {
int V_27 = 500 ;
T_1 V_28 = F_4 ( V_2 , V_24 ) & V_25 ;
while ( V_28 <= V_26 && V_27 -- ) {
F_23 ( 10 ) ;
V_28 = F_4 ( V_2 , V_24 ) & V_25 ;
}
if ( F_24 ( V_27 < 0 && V_28 <= V_26 ) )
++ V_21 ;
V_2 -> V_22 . V_23 = V_28 ;
}
V_2 -> V_22 . V_23 -- ;
return V_21 ;
}
static void F_25 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_29 ,
F_12 ( 0xffff ) ) ;
F_8 ( V_2 , V_30 ) ;
}
static void F_26 ( struct V_1 * V_2 ,
int V_10 )
{
if ( V_31 & V_10 ) {
if ( F_10 ( ( F_4 ( V_2 ,
V_30 ) &
V_17 ) == 0 ,
V_12 ) )
F_5 ( L_5 ) ;
F_7 ( V_2 , V_29 ,
F_15 ( V_17 ) ) ;
if ( F_10 ( ( F_4 ( V_2 ,
V_30 ) &
V_17 ) ,
V_12 ) )
F_5 ( L_6 ) ;
}
if ( V_32 & V_10 ) {
if ( F_10 ( ( F_4 ( V_2 ,
V_33 ) &
V_17 ) == 0 ,
V_12 ) )
F_5 ( L_7 ) ;
F_7 ( V_2 , V_34 ,
F_15 ( V_17 ) ) ;
if ( F_10 ( ( F_4 ( V_2 ,
V_33 ) &
V_17 ) ,
V_12 ) )
F_5 ( L_8 ) ;
}
F_1 ( V_2 ) ;
}
static void F_27 ( struct V_1 * V_2 ,
int V_10 )
{
if ( V_31 & V_10 )
F_7 ( V_2 , V_29 ,
F_12 ( V_17 ) ) ;
if ( V_32 & V_10 )
F_7 ( V_2 , V_34 ,
F_12 ( V_17 ) ) ;
F_17 ( V_2 ) ;
}
void F_28 ( struct V_1 * V_2 ,
int V_10 )
{
unsigned long V_35 ;
F_29 ( & V_2 -> V_22 . V_36 , V_35 ) ;
if ( V_31 & V_10 ) {
if ( V_2 -> V_22 . V_37 ++ == 0 )
V_2 -> V_22 . V_38 . V_39 ( V_2 ,
V_31 ) ;
}
if ( V_32 & V_10 ) {
if ( V_2 -> V_22 . V_40 ++ == 0 )
V_2 -> V_22 . V_38 . V_39 ( V_2 ,
V_32 ) ;
}
F_30 ( & V_2 -> V_22 . V_36 , V_35 ) ;
}
void F_31 ( struct V_1 * V_2 ,
int V_10 )
{
unsigned long V_35 ;
F_29 ( & V_2 -> V_22 . V_36 , V_35 ) ;
if ( V_31 & V_10 ) {
F_24 ( V_2 -> V_22 . V_37 == 0 ) ;
if ( -- V_2 -> V_22 . V_37 == 0 )
V_2 -> V_22 . V_38 . V_41 ( V_2 ,
V_31 ) ;
}
if ( V_32 & V_10 ) {
F_24 ( V_2 -> V_22 . V_40 == 0 ) ;
if ( -- V_2 -> V_22 . V_40 == 0 )
V_2 -> V_22 . V_38 . V_41 ( V_2 ,
V_32 ) ;
}
F_30 ( & V_2 -> V_22 . V_36 , V_35 ) ;
}
static void F_32 ( struct V_42 * V_43 )
{
struct V_1 * V_2 =
F_33 ( V_43 , F_34 ( * V_2 ) , V_22 . V_44 . V_43 ) ;
unsigned long V_35 ;
F_29 ( & V_2 -> V_22 . V_36 , V_35 ) ;
if ( -- V_2 -> V_22 . V_45 == 0 )
V_2 -> V_22 . V_38 . V_41 ( V_2 , V_46 ) ;
F_30 ( & V_2 -> V_22 . V_36 , V_35 ) ;
}
static void F_35 ( struct V_47 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_48 ;
if ( F_22 ( V_4 ) ) {
F_25 ( V_2 ) ;
} else if ( F_16 ( V_4 ) -> V_18 >= 6 ) {
F_6 ( V_2 ) ;
if ( F_36 ( V_4 ) || F_2 ( V_4 ) )
F_11 ( V_2 ) ;
}
}
void F_37 ( struct V_47 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_48 ;
if ( F_38 ( V_4 ) )
F_7 ( V_2 , V_49 , V_50 ) ;
if ( F_2 ( V_4 ) &&
( F_4 ( V_2 , V_51 ) == 1 ) ) {
V_2 -> V_52 = 128 ;
F_39 ( L_9 , V_2 -> V_52 ) ;
}
if ( F_40 ( V_4 ) || F_41 ( V_4 ) )
F_7 ( V_2 , V_20 ,
F_4 ( V_2 , V_20 ) ) ;
F_35 ( V_4 ) ;
}
void F_42 ( struct V_47 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_48 ;
T_1 V_53 ;
F_43 ( V_4 ) ;
if ( F_22 ( V_4 ) ) {
F_44 ( & V_2 -> V_54 . V_55 ) ;
V_53 = F_45 ( V_2 , V_56 ) ;
if ( V_53 & ( V_57 | V_58 | V_59 ) )
F_46 ( V_2 , V_60 , 0x0 ) ;
F_47 ( & V_2 -> V_54 . V_55 ) ;
}
}
void F_48 ( struct V_1 * V_2 , int V_10 )
{
unsigned long V_35 ;
if ( ! V_2 -> V_22 . V_38 . V_39 )
return;
F_49 ( V_2 ) ;
if ( F_22 ( V_2 -> V_4 ) )
return F_28 ( V_2 , V_10 ) ;
F_29 ( & V_2 -> V_22 . V_36 , V_35 ) ;
if ( V_2 -> V_22 . V_45 ++ == 0 )
V_2 -> V_22 . V_38 . V_39 ( V_2 , V_46 ) ;
F_30 ( & V_2 -> V_22 . V_36 , V_35 ) ;
}
void F_50 ( struct V_1 * V_2 , int V_10 )
{
unsigned long V_35 ;
if ( ! V_2 -> V_22 . V_38 . V_41 )
return;
if ( F_22 ( V_2 -> V_4 ) )
return F_31 ( V_2 , V_10 ) ;
F_29 ( & V_2 -> V_22 . V_36 , V_35 ) ;
if ( -- V_2 -> V_22 . V_45 == 0 ) {
V_2 -> V_22 . V_45 ++ ;
F_51 ( V_2 -> V_61 ,
& V_2 -> V_22 . V_44 ,
1 ) ;
}
F_30 ( & V_2 -> V_22 . V_36 , V_35 ) ;
F_52 ( V_2 ) ;
}
static void
F_53 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_62 , 0 ) ;
}
static void
F_54 ( struct V_1 * V_2 , T_1 V_63 )
{
if ( F_4 ( V_2 , V_49 ) & V_50 ) {
F_5 ( L_10 ,
V_63 ) ;
F_7 ( V_2 , V_49 , V_50 ) ;
}
}
static void
F_55 ( struct V_1 * V_2 , T_1 V_63 )
{
if ( F_4 ( V_2 , V_49 ) & V_50 ) {
F_5 ( L_11 , V_63 ) ;
F_7 ( V_2 , V_49 , V_50 ) ;
}
}
static void
F_56 ( struct V_1 * V_2 )
{
F_18 ( F_57 ( V_2 -> V_4 ) && V_2 -> V_64 . V_65 ,
L_12 ) ;
}
static bool F_58 ( struct V_1 * V_2 , T_1 V_63 )
{
int V_66 ;
for ( V_66 = 0 ; V_66 < F_59 ( V_67 ) ; V_66 ++ )
if ( V_63 == V_67 [ V_66 ] )
return true ;
return false ;
}
void F_60 ( struct V_47 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_48 ;
F_61 ( & V_2 -> V_22 . V_44 ,
F_32 ) ;
if ( F_22 ( V_4 ) ) {
V_2 -> V_22 . V_38 . V_39 = F_26 ;
V_2 -> V_22 . V_38 . V_41 = F_27 ;
} else if ( F_2 ( V_4 ) || F_14 ( V_4 ) ) {
V_2 -> V_22 . V_38 . V_39 = F_13 ;
V_2 -> V_22 . V_38 . V_41 = F_20 ;
} else if ( F_36 ( V_4 ) ) {
T_1 V_68 ;
F_44 ( & V_4 -> V_69 ) ;
F_13 ( V_2 , V_46 ) ;
V_68 = F_4 ( V_2 , V_9 ) ;
F_20 ( V_2 , V_46 ) ;
F_47 ( & V_4 -> V_69 ) ;
if ( V_68 & V_70 ) {
V_2 -> V_22 . V_38 . V_39 =
F_13 ;
V_2 -> V_22 . V_38 . V_41 =
F_20 ;
} else {
F_39 ( L_13 ) ;
F_39 ( L_14 ) ;
V_2 -> V_22 . V_38 . V_39 =
F_9 ;
V_2 -> V_22 . V_38 . V_41 =
F_19 ;
}
} else if ( F_40 ( V_4 ) ) {
V_2 -> V_22 . V_38 . V_39 =
F_9 ;
V_2 -> V_22 . V_38 . V_41 =
F_19 ;
}
switch ( F_16 ( V_4 ) -> V_18 ) {
default:
V_2 -> V_22 . V_38 . V_71 = V_72 ;
V_2 -> V_22 . V_38 . V_73 = V_74 ;
V_2 -> V_22 . V_38 . V_75 = V_76 ;
V_2 -> V_22 . V_38 . V_77 = V_78 ;
V_2 -> V_22 . V_38 . V_79 = V_80 ;
V_2 -> V_22 . V_38 . V_81 = V_82 ;
V_2 -> V_22 . V_38 . V_83 = V_84 ;
V_2 -> V_22 . V_38 . V_85 = V_86 ;
break;
case 7 :
case 6 :
if ( F_2 ( V_4 ) ) {
V_2 -> V_22 . V_38 . V_71 = V_87 ;
V_2 -> V_22 . V_38 . V_73 = V_88 ;
V_2 -> V_22 . V_38 . V_75 = V_89 ;
V_2 -> V_22 . V_38 . V_77 = V_90 ;
} else {
V_2 -> V_22 . V_38 . V_71 = V_91 ;
V_2 -> V_22 . V_38 . V_73 = V_92 ;
V_2 -> V_22 . V_38 . V_75 = V_93 ;
V_2 -> V_22 . V_38 . V_77 = V_94 ;
}
if ( F_22 ( V_4 ) ) {
V_2 -> V_22 . V_38 . V_79 = V_95 ;
V_2 -> V_22 . V_38 . V_81 = V_96 ;
V_2 -> V_22 . V_38 . V_83 = V_97 ;
V_2 -> V_22 . V_38 . V_85 = V_98 ;
} else {
V_2 -> V_22 . V_38 . V_79 = V_80 ;
V_2 -> V_22 . V_38 . V_81 = V_82 ;
V_2 -> V_22 . V_38 . V_83 = V_84 ;
V_2 -> V_22 . V_38 . V_85 = V_86 ;
}
break;
case 5 :
V_2 -> V_22 . V_38 . V_71 = V_99 ;
V_2 -> V_22 . V_38 . V_73 = V_100 ;
V_2 -> V_22 . V_38 . V_75 = V_101 ;
V_2 -> V_22 . V_38 . V_77 = V_102 ;
V_2 -> V_22 . V_38 . V_79 = V_103 ;
V_2 -> V_22 . V_38 . V_81 = V_104 ;
V_2 -> V_22 . V_38 . V_83 = V_105 ;
V_2 -> V_22 . V_38 . V_85 = V_106 ;
break;
case 4 :
case 3 :
case 2 :
V_2 -> V_22 . V_38 . V_71 = V_107 ;
V_2 -> V_22 . V_38 . V_73 = V_108 ;
V_2 -> V_22 . V_38 . V_75 = V_109 ;
V_2 -> V_22 . V_38 . V_77 = V_110 ;
V_2 -> V_22 . V_38 . V_79 = V_111 ;
V_2 -> V_22 . V_38 . V_81 = V_112 ;
V_2 -> V_22 . V_38 . V_83 = V_113 ;
V_2 -> V_22 . V_38 . V_85 = V_114 ;
break;
}
}
void F_62 ( struct V_47 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_48 ;
F_63 ( & V_2 -> V_22 . V_44 ) ;
F_42 ( V_4 ) ;
}
int F_64 ( struct V_47 * V_4 ,
void * V_115 , struct V_116 * V_117 )
{
struct V_1 * V_2 = V_4 -> V_48 ;
struct V_118 * V_63 = V_115 ;
struct V_119 const * V_120 = V_121 ;
int V_66 ;
for ( V_66 = 0 ; V_66 < F_59 ( V_121 ) ; V_66 ++ , V_120 ++ ) {
if ( V_120 -> V_122 == V_63 -> V_122 &&
( 1 << F_16 ( V_4 ) -> V_18 & V_120 -> V_123 ) )
break;
}
if ( V_66 == F_59 ( V_121 ) )
return - V_124 ;
switch ( V_120 -> V_125 ) {
case 8 :
V_63 -> V_126 = F_65 ( V_63 -> V_122 ) ;
break;
case 4 :
V_63 -> V_126 = F_66 ( V_63 -> V_122 ) ;
break;
case 2 :
V_63 -> V_126 = F_67 ( V_63 -> V_122 ) ;
break;
case 1 :
V_63 -> V_126 = F_68 ( V_63 -> V_122 ) ;
break;
default:
F_24 ( 1 ) ;
return - V_124 ;
}
return 0 ;
}
int F_69 ( struct V_47 * V_4 ,
void * V_115 , struct V_116 * V_117 )
{
struct V_1 * V_2 = V_4 -> V_48 ;
struct V_127 * args = V_115 ;
struct V_128 * V_129 ;
int V_21 ;
if ( args -> V_130 || args -> V_131 )
return - V_124 ;
if ( args -> V_132 == V_133 && ! F_70 ( V_134 ) )
return - V_135 ;
V_21 = F_71 ( & V_4 -> V_69 ) ;
if ( V_21 )
return V_21 ;
V_129 = F_72 ( V_4 , V_117 , args -> V_132 ) ;
if ( F_73 ( V_129 ) ) {
F_47 ( & V_4 -> V_69 ) ;
return F_74 ( V_129 ) ;
}
if ( F_70 ( V_134 ) )
args -> V_136 = F_75 ( & V_2 -> V_137 ) ;
else
args -> V_136 = 0 ;
args -> V_138 = V_129 -> V_138 ;
args -> V_139 = V_129 -> V_139 ;
F_47 ( & V_4 -> V_69 ) ;
return 0 ;
}
static int F_76 ( struct V_47 * V_4 )
{
T_2 V_140 ;
F_77 ( V_4 -> V_141 , V_142 , & V_140 ) ;
return ( V_140 & V_143 ) == 0 ;
}
static int F_78 ( struct V_47 * V_4 )
{
int V_21 ;
F_79 ( V_4 -> V_141 , V_142 ,
V_144 | V_143 ) ;
V_21 = F_80 ( F_76 ( V_4 ) , 500 ) ;
if ( V_21 )
return V_21 ;
F_79 ( V_4 -> V_141 , V_142 ,
V_145 | V_143 ) ;
V_21 = F_80 ( F_76 ( V_4 ) , 500 ) ;
if ( V_21 )
return V_21 ;
F_79 ( V_4 -> V_141 , V_142 , 0 ) ;
return 0 ;
}
static int F_81 ( struct V_47 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_48 ;
T_1 V_140 ;
int V_21 ;
V_140 = F_66 ( V_146 + V_147 ) ;
V_140 &= ~ V_148 ;
F_82 ( V_146 + V_147 ,
V_140 | V_144 | V_143 ) ;
V_21 = F_80 ( F_66 ( V_146 + V_147 ) & 0x1 , 500 ) ;
if ( V_21 )
return V_21 ;
V_140 = F_66 ( V_146 + V_147 ) ;
V_140 &= ~ V_148 ;
F_82 ( V_146 + V_147 ,
V_140 | V_145 | V_143 ) ;
return F_80 ( F_66 ( V_146 + V_147 ) & 0x1 , 500 ) ;
}
static int F_83 ( struct V_47 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_48 ;
int V_21 ;
unsigned long V_35 ;
F_29 ( & V_2 -> V_22 . V_36 , V_35 ) ;
F_7 ( V_2 , V_149 , V_150 ) ;
V_21 = F_80 ( ( F_4 ( V_2 , V_149 ) & V_150 ) == 0 , 500 ) ;
F_35 ( V_4 ) ;
if ( V_2 -> V_22 . V_45 )
V_2 -> V_22 . V_38 . V_39 ( V_2 , V_46 ) ;
else
V_2 -> V_22 . V_38 . V_41 ( V_2 , V_46 ) ;
V_2 -> V_22 . V_23 = F_4 ( V_2 , V_24 ) & V_25 ;
F_30 ( & V_2 -> V_22 . V_36 , V_35 ) ;
return V_21 ;
}
int F_84 ( struct V_47 * V_4 )
{
switch ( F_16 ( V_4 ) -> V_18 ) {
case 8 :
case 7 :
case 6 : return F_83 ( V_4 ) ;
case 5 : return F_81 ( V_4 ) ;
case 4 : return F_78 ( V_4 ) ;
default: return - V_151 ;
}
}
void F_85 ( struct V_47 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_48 ;
if ( F_38 ( V_4 ) &&
( F_4 ( V_2 , V_49 ) & V_50 ) ) {
F_5 ( L_15 ) ;
F_7 ( V_2 , V_49 , V_50 ) ;
}
}
