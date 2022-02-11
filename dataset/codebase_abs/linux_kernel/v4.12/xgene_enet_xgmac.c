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
F_32 ( & V_37 , V_76 ) ;
F_1 ( V_2 , V_74 , V_37 ) ;
F_12 ( V_2 , V_77 , & V_37 ) ;
F_33 ( & V_37 , V_78 ) ;
F_1 ( V_2 , V_77 , V_37 ) ;
F_12 ( V_2 , V_79 , & V_37 ) ;
V_37 |= F_34 ( 12 ) ;
F_1 ( V_2 , V_79 , V_37 ) ;
F_1 ( V_2 , V_80 , 0x82 ) ;
F_1 ( V_2 , V_81 , 0 ) ;
F_1 ( V_2 , V_82 , V_83 ) ;
F_17 ( V_2 , V_84 , & V_37 ) ;
V_37 = ( V_85 << 16 ) | ( V_37 & 0xFFFF ) ;
F_11 ( V_2 , V_84 , V_37 ) ;
if ( V_2 -> V_86 != V_87 ) {
F_17 ( V_2 , V_88 , & V_37 ) ;
V_37 = ( V_89 << 16 ) | ( V_37 & 0xFFFF ) ;
F_11 ( V_2 , V_88 , V_37 ) ;
}
V_37 = ( V_90 << 16 ) | V_91 ;
F_1 ( V_2 , V_92 , V_37 ) ;
F_29 ( V_2 , V_2 -> V_93 ) ;
F_30 ( V_2 , V_2 -> V_94 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
T_1 V_37 ;
F_15 ( V_2 , V_67 , & V_37 ) ;
F_8 ( V_2 , V_67 , V_37 | V_95 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
T_1 V_37 ;
F_15 ( V_2 , V_67 , & V_37 ) ;
F_8 ( V_2 , V_67 , V_37 | V_96 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
T_1 V_37 ;
F_15 ( V_2 , V_67 , & V_37 ) ;
F_8 ( V_2 , V_67 , V_37 & ~ V_95 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
T_1 V_37 ;
F_15 ( V_2 , V_67 , & V_37 ) ;
F_8 ( V_2 , V_67 , V_37 & ~ V_96 ) ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_97 * V_98 = & V_2 -> V_99 -> V_98 ;
if ( ! F_40 ( V_2 ) )
return - V_40 ;
if ( V_98 -> V_100 ) {
F_41 ( V_2 -> V_101 ) ;
F_7 ( 5 ) ;
F_42 ( V_2 -> V_101 ) ;
F_7 ( 5 ) ;
F_41 ( V_2 -> V_101 ) ;
F_7 ( 5 ) ;
} else {
#ifdef F_43
if ( F_44 ( F_45 ( & V_2 -> V_99 -> V_98 ) , L_6 ) ) {
F_46 ( F_45 ( & V_2 -> V_99 -> V_98 ) ,
L_6 , NULL , NULL ) ;
} else if ( F_44 ( F_45 ( & V_2 -> V_99 -> V_98 ) ,
L_7 ) ) {
F_46 ( F_45 ( & V_2 -> V_99 -> V_98 ) ,
L_7 , NULL , NULL ) ;
}
#endif
}
F_18 ( V_2 ) ;
F_20 ( V_2 ) ;
return 0 ;
}
static void F_47 ( struct V_1 * V_2 ,
T_1 V_102 , T_4 V_103 ,
T_4 V_104 )
{
T_1 V_105 , V_106 , V_107 ;
F_12 ( V_2 , V_108 , & V_105 ) ;
V_105 |= V_109 ;
F_48 ( & V_105 , 3 ) ;
F_1 ( V_2 , V_108 , V_105 ) ;
V_106 = F_49 ( V_103 ) ;
V_107 = F_49 ( V_104 ) ;
F_12 ( V_2 , V_110 , & V_105 ) ;
F_50 ( & V_105 , V_102 ) ;
F_51 ( & V_105 , V_106 ) ;
F_52 ( & V_105 , V_107 ) ;
F_1 ( V_2 , V_110 , V_105 ) ;
F_53 ( L_8 , V_106 , V_107 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_97 * V_98 = & V_2 -> V_99 -> V_98 ;
struct V_111 * V_112 ;
T_1 V_113 ;
int V_114 ;
V_113 = 0 ;
for ( V_114 = 0 ; V_114 < V_2 -> V_115 ; V_114 ++ ) {
V_112 = V_2 -> V_116 [ V_114 ] -> V_117 ;
V_113 |= F_34 ( F_49 ( V_112 -> V_118 ) ) ;
V_112 = V_2 -> V_116 [ V_114 ] -> V_119 ;
if ( V_112 )
V_113 |= F_34 ( F_49 ( V_112 -> V_118 ) ) ;
}
F_3 ( V_2 , V_120 , V_113 ) ;
V_113 = 0 ;
for ( V_114 = 0 ; V_114 < V_2 -> V_121 ; V_114 ++ ) {
V_112 = V_2 -> V_122 [ V_114 ] ;
V_113 |= F_34 ( F_55 ( V_112 -> V_118 ) ) ;
}
F_3 ( V_2 , V_123 , V_113 ) ;
if ( V_98 -> V_100 ) {
if ( ! F_56 ( V_2 -> V_101 ) )
F_42 ( V_2 -> V_101 ) ;
}
}
static void F_57 ( struct V_1 * V_2 ,
struct V_111 * V_112 )
{
T_1 V_5 , V_37 ;
if ( F_58 ( V_112 -> V_118 ) ) {
V_5 = V_120 ;
V_37 = F_34 ( F_49 ( V_112 -> V_118 ) ) ;
} else {
V_5 = V_123 ;
V_37 = F_34 ( F_55 ( V_112 -> V_118 ) ) ;
}
F_3 ( V_2 , V_5 , V_37 ) ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_97 * V_98 = & V_2 -> V_99 -> V_98 ;
V_2 -> V_124 = F_60 ( V_98 , L_9 , V_125 ) ;
if ( F_56 ( V_2 -> V_124 ) )
V_2 -> V_124 = F_60 ( V_98 , L_10 , V_125 ) ;
if ( F_56 ( V_2 -> V_124 ) )
return - V_40 ;
return 0 ;
}
static void F_61 ( struct V_126 * V_127 )
{
struct V_1 * V_2 = F_62 ( F_63 ( V_127 ) ,
struct V_1 , V_128 ) ;
struct V_36 * V_22 = V_2 -> V_22 ;
T_1 V_129 , V_130 ;
V_129 = F_27 ( V_2 ) ;
if ( V_2 -> V_131 && V_129 &&
( ! F_56 ( V_2 -> V_124 ) || ! F_59 ( V_2 ) ) &&
! F_64 ( V_2 -> V_124 ) )
V_129 = 0 ;
if ( V_129 ) {
if ( ! F_65 ( V_22 ) ) {
F_66 ( V_22 ) ;
F_35 ( V_2 ) ;
F_36 ( V_2 ) ;
F_67 ( V_22 , L_11 ) ;
}
V_130 = V_132 ;
} else {
if ( F_65 ( V_22 ) ) {
F_37 ( V_2 ) ;
F_38 ( V_2 ) ;
F_68 ( V_22 ) ;
F_67 ( V_22 , L_12 ) ;
}
V_130 = V_133 ;
F_22 ( V_2 ) ;
}
F_69 ( & V_2 -> V_128 , V_130 ) ;
}
