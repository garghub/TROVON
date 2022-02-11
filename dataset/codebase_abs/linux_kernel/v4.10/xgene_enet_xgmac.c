static void F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
void T_2 * V_5 = V_2 -> V_6 + V_3 ;
F_2 ( V_4 , V_5 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
void T_2 * V_5 = V_2 -> V_7 + V_3 ;
F_2 ( V_4 , V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
void T_2 * V_5 = V_2 -> V_8 + V_3 ;
F_2 ( V_4 , V_5 ) ;
}
static bool F_5 ( void T_2 * V_5 , void T_2 * V_9 ,
void T_2 * V_10 , void T_2 * V_11 ,
T_1 V_12 , T_1 V_13 )
{
T_1 V_14 ;
T_3 V_15 = 10 ;
F_2 ( V_12 , V_5 ) ;
F_2 ( V_13 , V_9 ) ;
F_2 ( V_16 , V_10 ) ;
while ( ! ( V_14 = F_6 ( V_11 ) ) && V_15 -- )
F_7 ( 1 ) ;
if ( ! V_14 )
return false ;
F_2 ( 0 , V_10 ) ;
return true ;
}
static void F_8 ( struct V_1 * V_2 ,
T_1 V_12 , T_1 V_13 )
{
void T_2 * V_5 , * V_9 , * V_10 , * V_11 ;
V_5 = V_2 -> V_17 + V_18 ;
V_9 = V_2 -> V_17 + V_19 ;
V_10 = V_2 -> V_17 + V_20 ;
V_11 = V_2 -> V_17 + V_21 ;
if ( ! F_5 ( V_5 , V_9 , V_10 , V_11 , V_12 , V_13 ) )
F_9 ( V_2 -> V_22 , L_1 ,
V_12 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
T_1 V_12 , T_1 V_13 )
{
void T_2 * V_5 , * V_9 , * V_10 , * V_11 ;
V_5 = V_2 -> V_23 + V_24 ;
V_9 = V_2 -> V_23 + V_25 ;
V_10 = V_2 -> V_23 + V_26 ;
V_11 = V_2 -> V_23 + V_27 ;
if ( ! F_5 ( V_5 , V_9 , V_10 , V_11 , V_12 , V_13 ) )
F_9 ( V_2 -> V_22 , L_2 ,
V_12 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
void T_2 * V_5 = V_2 -> V_28 + V_3 ;
F_2 ( V_4 , V_5 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 * V_4 )
{
void T_2 * V_5 = V_2 -> V_6 + V_3 ;
* V_4 = F_6 ( V_5 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 * V_4 )
{
void T_2 * V_5 = V_2 -> V_8 + V_3 ;
* V_4 = F_6 ( V_5 ) ;
}
static bool F_14 ( void T_2 * V_5 , void T_2 * V_29 ,
void T_2 * V_10 , void T_2 * V_11 ,
T_1 V_30 , T_1 * V_31 )
{
T_1 V_14 ;
T_3 V_15 = 10 ;
F_2 ( V_30 , V_5 ) ;
F_2 ( V_32 , V_10 ) ;
while ( ! ( V_14 = F_6 ( V_11 ) ) && V_15 -- )
F_7 ( 1 ) ;
if ( ! V_14 )
return false ;
* V_31 = F_6 ( V_29 ) ;
F_2 ( 0 , V_10 ) ;
return true ;
}
static void F_15 ( struct V_1 * V_2 ,
T_1 V_30 , T_1 * V_31 )
{
void T_2 * V_5 , * V_29 , * V_10 , * V_11 ;
V_5 = V_2 -> V_17 + V_18 ;
V_29 = V_2 -> V_17 + V_33 ;
V_10 = V_2 -> V_17 + V_20 ;
V_11 = V_2 -> V_17 + V_21 ;
if ( ! F_14 ( V_5 , V_29 , V_10 , V_11 , V_30 , V_31 ) )
F_9 ( V_2 -> V_22 , L_3 ,
V_30 ) ;
}
static bool F_16 ( struct V_1 * V_2 ,
T_1 V_30 , T_1 * V_31 )
{
void T_2 * V_5 , * V_29 , * V_10 , * V_11 ;
bool V_34 ;
V_5 = V_2 -> V_23 + V_24 ;
V_29 = V_2 -> V_23 + V_35 ;
V_10 = V_2 -> V_23 + V_26 ;
V_11 = V_2 -> V_23 + V_27 ;
V_34 = F_14 ( V_5 , V_29 , V_10 , V_11 , V_30 , V_31 ) ;
if ( ! V_34 )
F_9 ( V_2 -> V_22 , L_4 ,
V_30 ) ;
return V_34 ;
}
static void F_17 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 * V_4 )
{
void T_2 * V_5 = V_2 -> V_28 + V_3 ;
* V_4 = F_6 ( V_5 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_36 * V_22 = V_2 -> V_22 ;
T_1 V_37 ;
T_3 V_15 = 10 ;
F_4 ( V_2 , V_38 , 0x0 ) ;
do {
F_19 ( 100 , 110 ) ;
F_13 ( V_2 , V_39 , & V_37 ) ;
} while ( ( V_37 != 0xffffffff ) && V_15 -- );
if ( V_37 != 0xffffffff ) {
F_9 ( V_22 , L_5 ) ;
return - V_40 ;
}
return 0 ;
}
static void F_20 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_41 , 0 ) ;
F_3 ( V_2 , V_42 , 0 ) ;
F_3 ( V_2 , V_43 , 0 ) ;
F_3 ( V_2 , V_44 , 0 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_8 ( V_2 , V_45 , V_46 ) ;
F_8 ( V_2 , V_45 , 0 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
T_1 V_37 ;
if ( ! F_16 ( V_2 , V_47 , & V_37 ) )
return;
F_10 ( V_2 , V_47 , V_37 | V_48 ) ;
F_10 ( V_2 , V_47 , V_37 & ~ V_48 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
T_1 V_49 , V_50 ;
T_3 * V_51 = V_2 -> V_22 -> V_51 ;
V_49 = ( V_51 [ 3 ] << 24 ) | ( V_51 [ 2 ] << 16 ) |
( V_51 [ 1 ] << 8 ) | V_51 [ 0 ] ;
V_50 = ( V_51 [ 5 ] << 24 ) | ( V_51 [ 4 ] << 16 ) ;
F_8 ( V_2 , V_52 , V_49 ) ;
F_8 ( V_2 , V_53 , V_50 ) ;
}
static void F_24 ( struct V_1 * V_2 ,
T_4 V_54 , T_3 V_55 )
{
T_3 V_3 ;
T_1 V_37 ;
V_3 = ( V_55 < 2 ) ? 0 : 4 ;
F_12 ( V_2 , V_56 + V_3 , & V_37 ) ;
if ( ! ( V_55 & 0x1 ) )
V_37 = F_25 ( V_57 , V_37 >> V_58 ) |
F_25 ( V_59 , V_54 ) ;
else
V_37 = F_25 ( V_57 , V_54 ) | F_25 ( V_59 , V_37 ) ;
F_1 ( V_2 , V_56 + V_3 , V_37 ) ;
}
static void F_26 ( struct V_1 * V_2 , int V_60 )
{
F_8 ( V_2 , V_61 ,
( ( ( ( V_60 + 2 ) >> 2 ) << 16 ) | V_60 ) ) ;
}
static T_1 F_27 ( struct V_1 * V_2 )
{
T_1 V_37 ;
F_12 ( V_2 , V_62 , & V_37 ) ;
return V_37 ;
}
static void F_28 ( struct V_1 * V_2 ,
bool V_63 )
{
T_1 V_37 ;
F_17 ( V_2 , V_64 , & V_37 ) ;
if ( V_63 )
V_37 |= V_65 | V_66 ;
else
V_37 &= ~ ( V_65 | V_66 ) ;
F_11 ( V_2 , V_64 , V_37 ) ;
}
static void F_29 ( struct V_1 * V_2 , bool V_63 )
{
T_1 V_37 ;
F_15 ( V_2 , V_67 , & V_37 ) ;
if ( V_63 )
V_37 |= V_68 ;
else
V_37 &= ~ V_68 ;
F_8 ( V_2 , V_67 , V_37 ) ;
V_2 -> V_69 -> V_70 ( V_2 , V_63 ) ;
}
static void F_30 ( struct V_1 * V_2 , bool V_63 )
{
T_1 V_37 ;
F_15 ( V_2 , V_67 , & V_37 ) ;
if ( V_63 )
V_37 |= V_71 ;
else
V_37 &= ~ V_71 ;
F_8 ( V_2 , V_67 , V_37 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
T_1 V_37 ;
F_21 ( V_2 ) ;
F_15 ( V_2 , V_67 , & V_37 ) ;
V_37 |= V_72 ;
V_37 &= ~ V_73 ;
F_8 ( V_2 , V_67 , V_37 ) ;
F_23 ( V_2 ) ;
F_12 ( V_2 , V_74 , & V_37 ) ;
V_37 |= V_75 ;
F_1 ( V_2 , V_74 , V_37 ) ;
F_12 ( V_2 , V_76 , & V_37 ) ;
V_37 |= F_32 ( 12 ) ;
F_1 ( V_2 , V_76 , V_37 ) ;
F_1 ( V_2 , V_77 , 0x82 ) ;
F_1 ( V_2 , V_78 , 0 ) ;
F_1 ( V_2 , V_79 , V_80 ) ;
F_17 ( V_2 , V_81 , & V_37 ) ;
V_37 = ( V_82 << 16 ) | ( V_37 & 0xFFFF ) ;
F_11 ( V_2 , V_81 , V_37 ) ;
if ( V_2 -> V_83 != V_84 ) {
F_17 ( V_2 , V_85 , & V_37 ) ;
V_37 = ( V_86 << 16 ) | ( V_37 & 0xFFFF ) ;
F_11 ( V_2 , V_85 , V_37 ) ;
}
V_37 = ( V_87 << 16 ) | V_88 ;
F_1 ( V_2 , V_89 , V_37 ) ;
F_29 ( V_2 , V_2 -> V_90 ) ;
F_30 ( V_2 , V_2 -> V_91 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
T_1 V_37 ;
F_15 ( V_2 , V_67 , & V_37 ) ;
F_8 ( V_2 , V_67 , V_37 | V_92 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
T_1 V_37 ;
F_15 ( V_2 , V_67 , & V_37 ) ;
F_8 ( V_2 , V_67 , V_37 | V_93 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
T_1 V_37 ;
F_15 ( V_2 , V_67 , & V_37 ) ;
F_8 ( V_2 , V_67 , V_37 & ~ V_92 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
T_1 V_37 ;
F_15 ( V_2 , V_67 , & V_37 ) ;
F_8 ( V_2 , V_67 , V_37 & ~ V_93 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_94 * V_95 = & V_2 -> V_96 -> V_95 ;
if ( ! F_38 ( V_2 ) )
return - V_40 ;
if ( V_95 -> V_97 ) {
F_39 ( V_2 -> V_98 ) ;
F_7 ( 5 ) ;
F_40 ( V_2 -> V_98 ) ;
F_7 ( 5 ) ;
F_39 ( V_2 -> V_98 ) ;
F_7 ( 5 ) ;
} else {
#ifdef F_41
if ( F_42 ( F_43 ( & V_2 -> V_96 -> V_95 ) , L_6 ) ) {
F_44 ( F_43 ( & V_2 -> V_96 -> V_95 ) ,
L_6 , NULL , NULL ) ;
} else if ( F_42 ( F_43 ( & V_2 -> V_96 -> V_95 ) ,
L_7 ) ) {
F_44 ( F_43 ( & V_2 -> V_96 -> V_95 ) ,
L_7 , NULL , NULL ) ;
}
#endif
}
F_18 ( V_2 ) ;
F_20 ( V_2 ) ;
return 0 ;
}
static void F_45 ( struct V_1 * V_2 ,
T_1 V_99 , T_4 V_100 ,
T_4 V_101 )
{
T_1 V_102 , V_103 , V_104 ;
F_12 ( V_2 , V_105 , & V_102 ) ;
V_102 |= V_106 ;
F_46 ( & V_102 , 3 ) ;
F_1 ( V_2 , V_105 , V_102 ) ;
V_103 = F_47 ( V_100 ) ;
V_104 = F_47 ( V_101 ) ;
F_12 ( V_2 , V_107 , & V_102 ) ;
F_48 ( & V_102 , V_99 ) ;
F_49 ( & V_102 , V_103 ) ;
F_50 ( & V_102 , V_104 ) ;
F_1 ( V_2 , V_107 , V_102 ) ;
F_51 ( L_8 , V_103 , V_104 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_94 * V_95 = & V_2 -> V_96 -> V_95 ;
struct V_108 * V_109 ;
T_1 V_110 ;
int V_111 ;
V_110 = 0 ;
for ( V_111 = 0 ; V_111 < V_2 -> V_112 ; V_111 ++ ) {
V_109 = V_2 -> V_113 [ V_111 ] -> V_114 ;
V_110 |= F_32 ( F_47 ( V_109 -> V_115 ) ) ;
V_109 = V_2 -> V_113 [ V_111 ] -> V_116 ;
if ( V_109 )
V_110 |= F_32 ( F_47 ( V_109 -> V_115 ) ) ;
}
F_3 ( V_2 , V_117 , V_110 ) ;
V_110 = 0 ;
for ( V_111 = 0 ; V_111 < V_2 -> V_118 ; V_111 ++ ) {
V_109 = V_2 -> V_119 [ V_111 ] ;
V_110 |= F_32 ( F_53 ( V_109 -> V_115 ) ) ;
}
F_3 ( V_2 , V_120 , V_110 ) ;
if ( V_95 -> V_97 ) {
if ( ! F_54 ( V_2 -> V_98 ) )
F_40 ( V_2 -> V_98 ) ;
}
}
static void F_55 ( struct V_1 * V_2 ,
struct V_108 * V_109 )
{
T_1 V_5 , V_37 ;
if ( F_56 ( V_109 -> V_115 ) ) {
V_5 = V_117 ;
V_37 = F_32 ( F_47 ( V_109 -> V_115 ) ) ;
} else {
V_5 = V_120 ;
V_37 = F_32 ( F_53 ( V_109 -> V_115 ) ) ;
}
F_3 ( V_2 , V_5 , V_37 ) ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_94 * V_95 = & V_2 -> V_96 -> V_95 ;
V_2 -> V_121 = F_58 ( V_95 , L_9 , V_122 ) ;
if ( F_54 ( V_2 -> V_121 ) )
V_2 -> V_121 = F_58 ( V_95 , L_10 , V_122 ) ;
if ( F_54 ( V_2 -> V_121 ) )
return - V_40 ;
return 0 ;
}
static void F_59 ( struct V_123 * V_124 )
{
struct V_1 * V_2 = F_60 ( F_61 ( V_124 ) ,
struct V_1 , V_125 ) ;
struct V_36 * V_22 = V_2 -> V_22 ;
T_1 V_126 , V_127 ;
V_126 = F_27 ( V_2 ) ;
if ( V_2 -> V_128 && V_126 &&
( ! F_54 ( V_2 -> V_121 ) || ! F_57 ( V_2 ) ) &&
! F_62 ( V_2 -> V_121 ) )
V_126 = 0 ;
if ( V_126 ) {
if ( ! F_63 ( V_22 ) ) {
F_64 ( V_22 ) ;
F_33 ( V_2 ) ;
F_34 ( V_2 ) ;
F_65 ( V_22 , L_11 ) ;
}
V_127 = V_129 ;
} else {
if ( F_63 ( V_22 ) ) {
F_35 ( V_2 ) ;
F_36 ( V_2 ) ;
F_66 ( V_22 ) ;
F_65 ( V_22 , L_12 ) ;
}
V_127 = V_130 ;
F_22 ( V_2 ) ;
}
F_67 ( & V_2 -> V_125 , V_127 ) ;
}
