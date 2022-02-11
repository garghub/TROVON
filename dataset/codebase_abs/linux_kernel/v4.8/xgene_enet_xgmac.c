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
T_1 V_3 , T_1 * V_4 )
{
void T_2 * V_5 = V_2 -> V_6 + V_3 ;
* V_4 = F_6 ( V_5 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 * V_4 )
{
void T_2 * V_5 = V_2 -> V_8 + V_3 ;
* V_4 = F_6 ( V_5 ) ;
}
static bool F_12 ( void T_2 * V_5 , void T_2 * V_23 ,
void T_2 * V_10 , void T_2 * V_11 ,
T_1 V_24 , T_1 * V_25 )
{
T_1 V_14 ;
T_3 V_15 = 10 ;
F_2 ( V_24 , V_5 ) ;
F_2 ( V_26 , V_10 ) ;
while ( ! ( V_14 = F_6 ( V_11 ) ) && V_15 -- )
F_7 ( 1 ) ;
if ( ! V_14 )
return false ;
* V_25 = F_6 ( V_23 ) ;
F_2 ( 0 , V_10 ) ;
return true ;
}
static void F_13 ( struct V_1 * V_2 ,
T_1 V_24 , T_1 * V_25 )
{
void T_2 * V_5 , * V_23 , * V_10 , * V_11 ;
V_5 = V_2 -> V_17 + V_18 ;
V_23 = V_2 -> V_17 + V_27 ;
V_10 = V_2 -> V_17 + V_20 ;
V_11 = V_2 -> V_17 + V_21 ;
if ( ! F_12 ( V_5 , V_23 , V_10 , V_11 , V_24 , V_25 ) )
F_9 ( V_2 -> V_22 , L_2 ,
V_24 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_28 * V_22 = V_2 -> V_22 ;
T_1 V_29 ;
T_3 V_15 = 10 ;
F_4 ( V_2 , V_30 , 0x0 ) ;
do {
F_15 ( 100 , 110 ) ;
F_11 ( V_2 , V_31 , & V_29 ) ;
} while ( ( V_29 != 0xffffffff ) && V_15 -- );
if ( V_29 != 0xffffffff ) {
F_9 ( V_22 , L_3 ) ;
return - V_32 ;
}
return 0 ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_33 , 0 ) ;
F_3 ( V_2 , V_34 , 0 ) ;
F_3 ( V_2 , V_35 , 0 ) ;
F_3 ( V_2 , V_36 , 0 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_8 ( V_2 , V_37 , V_38 ) ;
F_8 ( V_2 , V_37 , 0 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
T_1 V_39 , V_40 ;
T_3 * V_41 = V_2 -> V_22 -> V_41 ;
V_39 = ( V_41 [ 3 ] << 24 ) | ( V_41 [ 2 ] << 16 ) |
( V_41 [ 1 ] << 8 ) | V_41 [ 0 ] ;
V_40 = ( V_41 [ 5 ] << 24 ) | ( V_41 [ 4 ] << 16 ) ;
F_8 ( V_2 , V_42 , V_39 ) ;
F_8 ( V_2 , V_43 , V_40 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_44 , V_2 -> V_45 ) ;
}
static T_1 F_20 ( struct V_1 * V_2 )
{
T_1 V_29 ;
F_10 ( V_2 , V_46 , & V_29 ) ;
return V_29 ;
}
static void F_21 ( struct V_1 * V_2 )
{
T_1 V_29 ;
F_17 ( V_2 ) ;
F_13 ( V_2 , V_47 , & V_29 ) ;
V_29 |= V_48 ;
V_29 &= ~ V_49 ;
F_8 ( V_2 , V_47 , V_29 ) ;
F_18 ( V_2 ) ;
F_19 ( V_2 ) ;
F_10 ( V_2 , V_50 , & V_29 ) ;
V_29 |= V_51 ;
F_1 ( V_2 , V_50 , V_29 ) ;
F_1 ( V_2 , V_52 , V_53 ) ;
F_1 ( V_2 , V_54 , 0 ) ;
F_10 ( V_2 , V_55 , & V_29 ) ;
V_29 |= F_22 ( 12 ) ;
F_1 ( V_2 , V_55 , V_29 ) ;
F_1 ( V_2 , V_56 , 0x82 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
T_1 V_29 ;
F_13 ( V_2 , V_47 , & V_29 ) ;
F_8 ( V_2 , V_47 , V_29 | V_57 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
T_1 V_29 ;
F_13 ( V_2 , V_47 , & V_29 ) ;
F_8 ( V_2 , V_47 , V_29 | V_58 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
T_1 V_29 ;
F_13 ( V_2 , V_47 , & V_29 ) ;
F_8 ( V_2 , V_47 , V_29 & ~ V_57 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
T_1 V_29 ;
F_13 ( V_2 , V_47 , & V_29 ) ;
F_8 ( V_2 , V_47 , V_29 & ~ V_58 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_59 * V_60 = & V_2 -> V_61 -> V_60 ;
if ( ! F_28 ( V_2 ) )
return - V_32 ;
if ( V_60 -> V_62 ) {
F_29 ( V_2 -> V_63 ) ;
F_7 ( 5 ) ;
F_30 ( V_2 -> V_63 ) ;
F_7 ( 5 ) ;
F_29 ( V_2 -> V_63 ) ;
F_7 ( 5 ) ;
} else {
#ifdef F_31
if ( F_32 ( F_33 ( & V_2 -> V_61 -> V_60 ) , L_4 ) ) {
F_34 ( F_33 ( & V_2 -> V_61 -> V_60 ) ,
L_4 , NULL , NULL ) ;
} else if ( F_32 ( F_33 ( & V_2 -> V_61 -> V_60 ) ,
L_5 ) ) {
F_34 ( F_33 ( & V_2 -> V_61 -> V_60 ) ,
L_5 , NULL , NULL ) ;
}
#endif
}
F_14 ( V_2 ) ;
F_16 ( V_2 ) ;
return 0 ;
}
static void F_35 ( struct V_1 * V_2 ,
T_1 V_64 , T_4 V_65 )
{
T_1 V_66 , V_67 ;
F_10 ( V_2 , V_68 , & V_66 ) ;
V_66 |= V_69 ;
F_36 ( & V_66 , 3 ) ;
F_1 ( V_2 , V_68 , V_66 ) ;
V_67 = F_37 ( V_65 ) - 0x20 ;
F_10 ( V_2 , V_70 , & V_66 ) ;
F_38 ( & V_66 , V_64 ) ;
F_39 ( & V_66 , V_67 ) ;
F_1 ( V_2 , V_70 , V_66 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_59 * V_60 = & V_2 -> V_61 -> V_60 ;
struct V_71 * V_72 ;
T_1 V_73 , V_4 ;
int V_74 ;
V_73 = 0 ;
for ( V_74 = 0 ; V_74 < V_2 -> V_75 ; V_74 ++ ) {
V_72 = V_2 -> V_76 [ V_74 ] -> V_77 ;
V_4 = F_37 ( V_72 -> V_78 ) ;
V_73 |= F_22 ( V_4 - 0x20 ) ;
}
F_3 ( V_2 , V_79 , V_73 ) ;
V_73 = 0 ;
for ( V_74 = 0 ; V_74 < V_2 -> V_80 ; V_74 ++ ) {
V_72 = V_2 -> V_81 [ V_74 ] ;
V_4 = F_37 ( V_72 -> V_78 ) ;
V_73 |= F_22 ( V_4 ) ;
}
F_3 ( V_2 , V_82 , V_73 ) ;
if ( V_60 -> V_62 ) {
if ( ! F_41 ( V_2 -> V_63 ) )
F_30 ( V_2 -> V_63 ) ;
}
}
static void F_42 ( struct V_1 * V_2 ,
struct V_71 * V_72 )
{
T_1 V_5 , V_4 , V_29 ;
V_4 = F_37 ( V_72 -> V_78 ) ;
if ( F_43 ( V_72 -> V_78 ) ) {
V_5 = V_79 ;
V_29 = F_22 ( V_4 - 0x20 ) ;
} else {
V_5 = V_82 ;
V_29 = F_22 ( V_4 ) ;
}
F_3 ( V_2 , V_5 , V_29 ) ;
}
static void F_44 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = F_45 ( F_46 ( V_84 ) ,
struct V_1 , V_85 ) ;
struct V_28 * V_22 = V_2 -> V_22 ;
T_1 V_86 , V_87 ;
V_86 = F_20 ( V_2 ) ;
if ( V_86 ) {
if ( ! F_47 ( V_22 ) ) {
F_48 ( V_22 ) ;
F_21 ( V_2 ) ;
F_23 ( V_2 ) ;
F_24 ( V_2 ) ;
F_49 ( V_22 , L_6 ) ;
}
V_87 = V_88 ;
} else {
if ( F_47 ( V_22 ) ) {
F_25 ( V_2 ) ;
F_26 ( V_2 ) ;
F_50 ( V_22 ) ;
F_49 ( V_22 , L_7 ) ;
}
V_87 = V_89 ;
}
F_51 ( & V_2 -> V_85 , V_87 ) ;
}
