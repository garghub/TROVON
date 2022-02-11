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
static bool F_13 ( void T_2 * V_5 , void T_2 * V_28 ,
void T_2 * V_10 , void T_2 * V_11 ,
T_1 V_29 , T_1 * V_30 )
{
T_1 V_14 ;
T_3 V_15 = 10 ;
F_2 ( V_29 , V_5 ) ;
F_2 ( V_31 , V_10 ) ;
while ( ! ( V_14 = F_6 ( V_11 ) ) && V_15 -- )
F_7 ( 1 ) ;
if ( ! V_14 )
return false ;
* V_30 = F_6 ( V_28 ) ;
F_2 ( 0 , V_10 ) ;
return true ;
}
static void F_14 ( struct V_1 * V_2 ,
T_1 V_29 , T_1 * V_30 )
{
void T_2 * V_5 , * V_28 , * V_10 , * V_11 ;
V_5 = V_2 -> V_17 + V_18 ;
V_28 = V_2 -> V_17 + V_32 ;
V_10 = V_2 -> V_17 + V_20 ;
V_11 = V_2 -> V_17 + V_21 ;
if ( ! F_13 ( V_5 , V_28 , V_10 , V_11 , V_29 , V_30 ) )
F_9 ( V_2 -> V_22 , L_3 ,
V_29 ) ;
}
static bool F_15 ( struct V_1 * V_2 ,
T_1 V_29 , T_1 * V_30 )
{
void T_2 * V_5 , * V_28 , * V_10 , * V_11 ;
bool V_33 ;
V_5 = V_2 -> V_23 + V_24 ;
V_28 = V_2 -> V_23 + V_34 ;
V_10 = V_2 -> V_23 + V_26 ;
V_11 = V_2 -> V_23 + V_27 ;
V_33 = F_13 ( V_5 , V_28 , V_10 , V_11 , V_29 , V_30 ) ;
if ( ! V_33 )
F_9 ( V_2 -> V_22 , L_4 ,
V_29 ) ;
return V_33 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_35 * V_22 = V_2 -> V_22 ;
T_1 V_36 ;
T_3 V_15 = 10 ;
F_4 ( V_2 , V_37 , 0x0 ) ;
do {
F_17 ( 100 , 110 ) ;
F_12 ( V_2 , V_38 , & V_36 ) ;
} while ( ( V_36 != 0xffffffff ) && V_15 -- );
if ( V_36 != 0xffffffff ) {
F_9 ( V_22 , L_5 ) ;
return - V_39 ;
}
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_40 , 0 ) ;
F_3 ( V_2 , V_41 , 0 ) ;
F_3 ( V_2 , V_42 , 0 ) ;
F_3 ( V_2 , V_43 , 0 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_8 ( V_2 , V_44 , V_45 ) ;
F_8 ( V_2 , V_44 , 0 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
T_1 V_36 ;
if ( ! F_15 ( V_2 , V_46 , & V_36 ) )
return;
F_10 ( V_2 , V_46 , V_36 | V_47 ) ;
F_10 ( V_2 , V_46 , V_36 & ~ V_47 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
T_1 V_48 , V_49 ;
T_3 * V_50 = V_2 -> V_22 -> V_50 ;
V_48 = ( V_50 [ 3 ] << 24 ) | ( V_50 [ 2 ] << 16 ) |
( V_50 [ 1 ] << 8 ) | V_50 [ 0 ] ;
V_49 = ( V_50 [ 5 ] << 24 ) | ( V_50 [ 4 ] << 16 ) ;
F_8 ( V_2 , V_51 , V_48 ) ;
F_8 ( V_2 , V_52 , V_49 ) ;
}
static void F_22 ( struct V_1 * V_2 ,
T_4 V_53 , T_3 V_54 )
{
T_3 V_3 ;
T_1 V_36 ;
V_3 = ( V_54 < 2 ) ? 0 : 4 ;
F_11 ( V_2 , V_55 + V_3 , & V_36 ) ;
if ( ! ( V_54 & 0x1 ) )
V_36 = F_23 ( V_56 , V_36 >> V_57 ) |
F_23 ( V_58 , V_53 ) ;
else
V_36 = F_23 ( V_56 , V_53 ) | F_23 ( V_58 , V_36 ) ;
F_1 ( V_2 , V_55 + V_3 , V_36 ) ;
}
static T_1 F_24 ( struct V_1 * V_2 )
{
T_1 V_36 ;
F_11 ( V_2 , V_59 , & V_36 ) ;
return V_36 ;
}
static void F_25 ( struct V_1 * V_2 )
{
T_1 V_36 ;
F_19 ( V_2 ) ;
F_14 ( V_2 , V_60 , & V_36 ) ;
V_36 |= V_61 ;
V_36 &= ~ V_62 ;
F_8 ( V_2 , V_60 , V_36 ) ;
F_21 ( V_2 ) ;
F_11 ( V_2 , V_63 , & V_36 ) ;
V_36 |= V_64 ;
F_1 ( V_2 , V_63 , V_36 ) ;
F_11 ( V_2 , V_65 , & V_36 ) ;
V_36 |= F_26 ( 12 ) ;
F_1 ( V_2 , V_65 , V_36 ) ;
F_1 ( V_2 , V_66 , 0x82 ) ;
F_1 ( V_2 , V_67 , 0 ) ;
F_1 ( V_2 , V_68 , V_69 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
T_1 V_36 ;
F_14 ( V_2 , V_60 , & V_36 ) ;
F_8 ( V_2 , V_60 , V_36 | V_70 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
T_1 V_36 ;
F_14 ( V_2 , V_60 , & V_36 ) ;
F_8 ( V_2 , V_60 , V_36 | V_71 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
T_1 V_36 ;
F_14 ( V_2 , V_60 , & V_36 ) ;
F_8 ( V_2 , V_60 , V_36 & ~ V_70 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
T_1 V_36 ;
F_14 ( V_2 , V_60 , & V_36 ) ;
F_8 ( V_2 , V_60 , V_36 & ~ V_71 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_72 * V_73 = & V_2 -> V_74 -> V_73 ;
if ( ! F_32 ( V_2 ) )
return - V_39 ;
if ( V_73 -> V_75 ) {
F_33 ( V_2 -> V_76 ) ;
F_7 ( 5 ) ;
F_34 ( V_2 -> V_76 ) ;
F_7 ( 5 ) ;
F_33 ( V_2 -> V_76 ) ;
F_7 ( 5 ) ;
} else {
#ifdef F_35
if ( F_36 ( F_37 ( & V_2 -> V_74 -> V_73 ) , L_6 ) ) {
F_38 ( F_37 ( & V_2 -> V_74 -> V_73 ) ,
L_6 , NULL , NULL ) ;
} else if ( F_36 ( F_37 ( & V_2 -> V_74 -> V_73 ) ,
L_7 ) ) {
F_38 ( F_37 ( & V_2 -> V_74 -> V_73 ) ,
L_7 , NULL , NULL ) ;
}
#endif
}
F_16 ( V_2 ) ;
F_18 ( V_2 ) ;
return 0 ;
}
static void F_39 ( struct V_1 * V_2 ,
T_1 V_77 , T_4 V_78 )
{
T_1 V_79 , V_80 ;
F_11 ( V_2 , V_81 , & V_79 ) ;
V_79 |= V_82 ;
F_40 ( & V_79 , 3 ) ;
F_1 ( V_2 , V_81 , V_79 ) ;
V_80 = F_41 ( V_78 ) - 0x20 ;
F_11 ( V_2 , V_83 , & V_79 ) ;
F_42 ( & V_79 , V_77 ) ;
F_43 ( & V_79 , V_80 ) ;
F_1 ( V_2 , V_83 , V_79 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_72 * V_73 = & V_2 -> V_74 -> V_73 ;
struct V_84 * V_85 ;
T_1 V_86 , V_4 ;
int V_87 ;
V_86 = 0 ;
for ( V_87 = 0 ; V_87 < V_2 -> V_88 ; V_87 ++ ) {
V_85 = V_2 -> V_89 [ V_87 ] -> V_90 ;
V_4 = F_41 ( V_85 -> V_91 ) ;
V_86 |= F_26 ( V_4 - 0x20 ) ;
}
F_3 ( V_2 , V_92 , V_86 ) ;
V_86 = 0 ;
for ( V_87 = 0 ; V_87 < V_2 -> V_93 ; V_87 ++ ) {
V_85 = V_2 -> V_94 [ V_87 ] ;
V_4 = F_41 ( V_85 -> V_91 ) ;
V_86 |= F_26 ( V_4 ) ;
}
F_3 ( V_2 , V_95 , V_86 ) ;
if ( V_73 -> V_75 ) {
if ( ! F_45 ( V_2 -> V_76 ) )
F_34 ( V_2 -> V_76 ) ;
}
}
static void F_46 ( struct V_1 * V_2 ,
struct V_84 * V_85 )
{
T_1 V_5 , V_4 , V_36 ;
V_4 = F_41 ( V_85 -> V_91 ) ;
if ( F_47 ( V_85 -> V_91 ) ) {
V_5 = V_92 ;
V_36 = F_26 ( V_4 - 0x20 ) ;
} else {
V_5 = V_95 ;
V_36 = F_26 ( V_4 ) ;
}
F_3 ( V_2 , V_5 , V_36 ) ;
}
static void F_48 ( struct V_96 * V_97 )
{
struct V_1 * V_2 = F_49 ( F_50 ( V_97 ) ,
struct V_1 , V_98 ) ;
struct V_99 * V_100 = V_2 -> V_100 ;
struct V_35 * V_22 = V_2 -> V_22 ;
T_1 V_101 , V_102 ;
V_101 = F_24 ( V_2 ) ;
if ( V_101 && ! F_45 ( V_100 ) && ! F_51 ( V_100 ) )
V_101 = 0 ;
if ( V_101 ) {
if ( ! F_52 ( V_22 ) ) {
F_53 ( V_22 ) ;
F_27 ( V_2 ) ;
F_28 ( V_2 ) ;
F_54 ( V_22 , L_8 ) ;
}
V_102 = V_103 ;
} else {
if ( F_52 ( V_22 ) ) {
F_29 ( V_2 ) ;
F_30 ( V_2 ) ;
F_55 ( V_22 ) ;
F_54 ( V_22 , L_9 ) ;
}
V_102 = V_104 ;
F_20 ( V_2 ) ;
}
F_56 ( & V_2 -> V_98 , V_102 ) ;
}
