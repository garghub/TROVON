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
T_1 V_3 , T_1 V_4 )
{
void T_2 * V_5 = V_2 -> V_23 + V_3 ;
F_2 ( V_4 , V_5 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 * V_4 )
{
void T_2 * V_5 = V_2 -> V_6 + V_3 ;
* V_4 = F_6 ( V_5 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 * V_4 )
{
void T_2 * V_5 = V_2 -> V_8 + V_3 ;
* V_4 = F_6 ( V_5 ) ;
}
static bool F_13 ( void T_2 * V_5 , void T_2 * V_24 ,
void T_2 * V_10 , void T_2 * V_11 ,
T_1 V_25 , T_1 * V_26 )
{
T_1 V_14 ;
T_3 V_15 = 10 ;
F_2 ( V_25 , V_5 ) ;
F_2 ( V_27 , V_10 ) ;
while ( ! ( V_14 = F_6 ( V_11 ) ) && V_15 -- )
F_7 ( 1 ) ;
if ( ! V_14 )
return false ;
* V_26 = F_6 ( V_24 ) ;
F_2 ( 0 , V_10 ) ;
return true ;
}
static bool F_14 ( struct V_1 * V_2 ,
T_1 V_25 , T_1 * V_26 )
{
void T_2 * V_5 , * V_24 , * V_10 , * V_11 ;
bool V_28 ;
V_5 = V_2 -> V_17 + V_18 ;
V_24 = V_2 -> V_17 + V_29 ;
V_10 = V_2 -> V_17 + V_20 ;
V_11 = V_2 -> V_17 + V_21 ;
V_28 = F_13 ( V_5 , V_24 , V_10 , V_11 , V_25 , V_26 ) ;
if ( ! V_28 )
F_9 ( V_2 -> V_22 , L_2 ,
V_25 ) ;
return V_28 ;
}
static void F_15 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 * V_4 )
{
void T_2 * V_5 = V_2 -> V_23 + V_3 ;
* V_4 = F_6 ( V_5 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_30 * V_22 = V_2 -> V_22 ;
T_1 V_31 ;
T_3 V_15 = 10 ;
F_4 ( V_2 , V_32 , 0x0 ) ;
do {
F_17 ( 100 , 110 ) ;
F_12 ( V_2 , V_33 , & V_31 ) ;
} while ( ( V_31 != 0xffffffff ) && V_15 -- );
if ( V_31 != 0xffffffff ) {
F_9 ( V_22 , L_3 ) ;
return - V_34 ;
}
return 0 ;
}
static void F_18 ( struct V_1 * V_2 ,
T_1 * V_35 , T_1 * V_36 )
{
T_1 V_37 ;
F_15 ( V_2 , V_38 , & V_37 ) ;
* V_35 = F_19 ( V_37 ) ;
* V_36 = F_20 ( V_37 ) ;
F_15 ( V_2 , V_39 , & V_37 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_40 , 0 ) ;
F_3 ( V_2 , V_41 , 0 ) ;
F_3 ( V_2 , V_42 , 0 ) ;
F_3 ( V_2 , V_43 , 0 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_23 ( V_2 , V_44 , V_45 ) ;
F_23 ( V_2 , V_44 , 0 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
T_1 V_31 ;
if ( ! F_14 ( V_2 , V_46 , & V_31 ) )
return;
F_8 ( V_2 , V_46 , V_31 | V_47 ) ;
F_8 ( V_2 , V_46 , V_31 & ~ V_47 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
T_1 V_48 , V_49 ;
T_3 * V_50 = V_2 -> V_22 -> V_50 ;
V_48 = ( V_50 [ 3 ] << 24 ) | ( V_50 [ 2 ] << 16 ) |
( V_50 [ 1 ] << 8 ) | V_50 [ 0 ] ;
V_49 = ( V_50 [ 5 ] << 24 ) | ( V_50 [ 4 ] << 16 ) ;
F_23 ( V_2 , V_51 , V_48 ) ;
F_23 ( V_2 , V_52 , V_49 ) ;
}
static void F_26 ( struct V_1 * V_2 ,
T_4 V_53 , T_3 V_54 )
{
T_3 V_3 ;
T_1 V_31 ;
V_3 = ( V_54 < 2 ) ? 0 : 4 ;
F_11 ( V_2 , V_55 + V_3 , & V_31 ) ;
if ( ! ( V_54 & 0x1 ) )
V_31 = F_27 ( V_56 , V_31 >> V_57 ) |
F_27 ( V_58 , V_53 ) ;
else
V_31 = F_27 ( V_56 , V_53 ) | F_27 ( V_58 , V_31 ) ;
F_1 ( V_2 , V_55 + V_3 , V_31 ) ;
}
static void F_28 ( struct V_1 * V_2 , int V_59 )
{
F_23 ( V_2 , V_60 ,
( ( ( ( V_59 + 2 ) >> 2 ) << 16 ) | V_59 ) ) ;
}
static T_1 F_29 ( struct V_1 * V_2 )
{
T_1 V_31 ;
F_11 ( V_2 , V_61 , & V_31 ) ;
return V_31 ;
}
static void F_30 ( struct V_1 * V_2 ,
bool V_62 )
{
T_1 V_31 ;
F_15 ( V_2 , V_63 , & V_31 ) ;
if ( V_62 )
V_31 |= V_64 | V_65 ;
else
V_31 &= ~ ( V_64 | V_65 ) ;
F_10 ( V_2 , V_63 , V_31 ) ;
}
static void F_31 ( struct V_1 * V_2 , bool V_62 )
{
T_1 V_31 ;
V_31 = F_32 ( V_2 , V_66 ) ;
if ( V_62 )
V_31 |= V_67 ;
else
V_31 &= ~ V_67 ;
F_23 ( V_2 , V_66 , V_31 ) ;
V_2 -> V_68 -> V_69 ( V_2 , V_62 ) ;
}
static void F_33 ( struct V_1 * V_2 , bool V_62 )
{
T_1 V_31 ;
V_31 = F_32 ( V_2 , V_66 ) ;
if ( V_62 )
V_31 |= V_70 ;
else
V_31 &= ~ V_70 ;
F_23 ( V_2 , V_66 , V_31 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
T_1 V_31 ;
F_22 ( V_2 ) ;
V_31 = F_32 ( V_2 , V_66 ) ;
V_31 |= V_71 ;
V_31 &= ~ V_72 ;
F_23 ( V_2 , V_66 , V_31 ) ;
F_25 ( V_2 ) ;
F_11 ( V_2 , V_73 , & V_31 ) ;
V_31 |= V_74 ;
F_35 ( & V_31 , V_75 ) ;
F_1 ( V_2 , V_73 , V_31 ) ;
F_11 ( V_2 , V_76 , & V_31 ) ;
F_36 ( & V_31 , V_77 ) ;
F_1 ( V_2 , V_76 , V_31 ) ;
F_11 ( V_2 , V_78 , & V_31 ) ;
V_31 |= F_37 ( 12 ) ;
F_1 ( V_2 , V_78 , V_31 ) ;
F_1 ( V_2 , V_79 , 0x82 ) ;
F_1 ( V_2 , V_80 , 0 ) ;
F_1 ( V_2 , V_81 , V_82 ) ;
F_15 ( V_2 , V_83 , & V_31 ) ;
V_31 = ( V_84 << 16 ) | ( V_31 & 0xFFFF ) ;
F_10 ( V_2 , V_83 , V_31 ) ;
if ( V_2 -> V_85 != V_86 ) {
F_15 ( V_2 , V_87 , & V_31 ) ;
V_31 = ( V_88 << 16 ) | ( V_31 & 0xFFFF ) ;
F_10 ( V_2 , V_87 , V_31 ) ;
}
V_31 = ( V_89 << 16 ) | V_90 ;
F_1 ( V_2 , V_91 , V_31 ) ;
F_31 ( V_2 , V_2 -> V_92 ) ;
F_33 ( V_2 , V_2 -> V_93 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
T_1 V_31 ;
V_31 = F_32 ( V_2 , V_66 ) ;
F_23 ( V_2 , V_66 , V_31 | V_94 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
T_1 V_31 ;
V_31 = F_32 ( V_2 , V_66 ) ;
F_23 ( V_2 , V_66 , V_31 | V_95 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
T_1 V_31 ;
V_31 = F_32 ( V_2 , V_66 ) ;
F_23 ( V_2 , V_66 , V_31 & ~ V_94 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
T_1 V_31 ;
V_31 = F_32 ( V_2 , V_66 ) ;
F_23 ( V_2 , V_66 , V_31 & ~ V_95 ) ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_96 * V_97 = & V_2 -> V_98 -> V_97 ;
if ( ! F_43 ( V_2 ) )
return - V_34 ;
if ( V_97 -> V_99 ) {
F_44 ( V_2 -> V_100 ) ;
F_7 ( 5 ) ;
F_45 ( V_2 -> V_100 ) ;
F_7 ( 5 ) ;
F_44 ( V_2 -> V_100 ) ;
F_7 ( 5 ) ;
} else {
#ifdef F_46
if ( F_47 ( F_48 ( & V_2 -> V_98 -> V_97 ) , L_4 ) ) {
F_49 ( F_48 ( & V_2 -> V_98 -> V_97 ) ,
L_4 , NULL , NULL ) ;
} else if ( F_47 ( F_48 ( & V_2 -> V_98 -> V_97 ) ,
L_5 ) ) {
F_49 ( F_48 ( & V_2 -> V_98 -> V_97 ) ,
L_5 , NULL , NULL ) ;
}
#endif
}
F_16 ( V_2 ) ;
F_21 ( V_2 ) ;
return 0 ;
}
static void F_50 ( struct V_1 * V_2 ,
T_1 V_101 , T_4 V_102 ,
T_4 V_103 )
{
T_1 V_104 , V_105 , V_106 ;
F_11 ( V_2 , V_107 , & V_104 ) ;
V_104 |= V_108 ;
F_51 ( & V_104 , 3 ) ;
F_1 ( V_2 , V_107 , V_104 ) ;
V_105 = F_52 ( V_102 ) ;
V_106 = F_52 ( V_103 ) ;
F_11 ( V_2 , V_109 , & V_104 ) ;
F_53 ( & V_104 , V_101 ) ;
F_54 ( & V_104 , V_105 ) ;
F_55 ( & V_104 , V_106 ) ;
F_1 ( V_2 , V_109 , V_104 ) ;
F_56 ( L_6 , V_105 , V_106 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_96 * V_97 = & V_2 -> V_98 -> V_97 ;
if ( V_97 -> V_99 ) {
if ( ! F_58 ( V_2 -> V_100 ) )
F_45 ( V_2 -> V_100 ) ;
}
}
static void F_59 ( struct V_1 * V_2 ,
struct V_110 * V_111 )
{
T_1 V_5 , V_31 ;
if ( F_60 ( V_111 -> V_112 ) ) {
V_5 = V_113 ;
V_31 = F_37 ( F_52 ( V_111 -> V_112 ) ) ;
} else {
V_5 = V_114 ;
V_31 = F_37 ( F_61 ( V_111 -> V_112 ) ) ;
}
F_3 ( V_2 , V_5 , V_31 ) ;
}
static int F_62 ( struct V_1 * V_2 )
{
struct V_96 * V_97 = & V_2 -> V_98 -> V_97 ;
V_2 -> V_115 = F_63 ( V_97 , L_7 , V_116 ) ;
if ( F_58 ( V_2 -> V_115 ) )
V_2 -> V_115 = F_63 ( V_97 , L_8 , V_116 ) ;
if ( F_58 ( V_2 -> V_115 ) )
return - V_34 ;
return 0 ;
}
static void F_64 ( struct V_117 * V_118 )
{
struct V_1 * V_2 = F_65 ( F_66 ( V_118 ) ,
struct V_1 , V_119 ) ;
struct V_30 * V_22 = V_2 -> V_22 ;
T_1 V_120 , V_121 ;
V_120 = F_29 ( V_2 ) ;
if ( V_2 -> V_122 && V_120 &&
( ! F_58 ( V_2 -> V_115 ) || ! F_62 ( V_2 ) ) &&
! F_67 ( V_2 -> V_115 ) )
V_120 = 0 ;
if ( V_120 ) {
if ( ! F_68 ( V_22 ) ) {
F_69 ( V_22 ) ;
F_38 ( V_2 ) ;
F_39 ( V_2 ) ;
F_70 ( V_22 , L_9 ) ;
}
V_121 = V_123 ;
} else {
if ( F_68 ( V_22 ) ) {
F_40 ( V_2 ) ;
F_41 ( V_2 ) ;
F_71 ( V_22 ) ;
F_70 ( V_22 , L_10 ) ;
}
V_121 = V_124 ;
F_24 ( V_2 ) ;
}
F_72 ( & V_2 -> V_119 , V_121 ) ;
}
