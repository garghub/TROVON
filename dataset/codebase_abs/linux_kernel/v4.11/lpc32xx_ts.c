static void F_1 ( struct V_1 * V_2 )
{
while ( ! ( F_2 ( V_2 , V_3 ) &
V_4 ) )
F_2 ( V_2 , V_5 ) ;
}
static T_1 F_3 ( int V_6 , void * V_7 )
{
T_2 V_8 , V_9 [ 4 ] , V_10 [ 4 ] , V_11 [ 4 ] ;
int V_12 ;
struct V_1 * V_2 = V_7 ;
struct V_13 * V_14 = V_2 -> V_15 ;
V_8 = F_2 ( V_2 , V_3 ) ;
if ( V_8 & V_16 ) {
F_1 ( V_2 ) ;
return V_17 ;
}
V_12 = 0 ;
while ( V_12 < 4 &&
! ( F_2 ( V_2 , V_3 ) &
V_4 ) ) {
V_8 = F_2 ( V_2 , V_5 ) ;
V_10 [ V_12 ] = V_18 -
F_4 ( V_8 ) ;
V_11 [ V_12 ] = V_18 -
F_5 ( V_8 ) ;
V_9 [ V_12 ] = V_8 ;
V_12 ++ ;
}
if ( ! ( V_9 [ 3 ] & V_19 ) && V_12 == 4 ) {
F_6 ( V_14 , V_20 , ( V_10 [ 1 ] + V_10 [ 2 ] ) / 2 ) ;
F_6 ( V_14 , V_21 , ( V_11 [ 1 ] + V_11 [ 2 ] ) / 2 ) ;
F_7 ( V_14 , V_22 , 1 ) ;
} else {
F_7 ( V_14 , V_22 , 0 ) ;
}
F_8 ( V_14 ) ;
return V_17 ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_10 ( V_2 , V_23 ,
F_2 ( V_2 , V_23 ) &
~ V_24 ) ;
F_11 ( V_2 -> V_25 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
T_2 V_8 ;
F_13 ( V_2 -> V_25 ) ;
V_8 = F_2 ( V_2 , V_23 ) & ~ V_26 ;
V_8 = V_27 |
F_14 ( 10 ) |
F_15 ( 10 ) ;
F_10 ( V_2 , V_23 , V_8 ) ;
F_10 ( V_2 , V_28 , V_29 ) ;
F_10 ( V_2 , V_30 , V_31 ) ;
F_10 ( V_2 , V_32 , V_33 ) ;
F_10 ( V_2 , V_34 , V_31 ) ;
F_10 ( V_2 , V_35 , V_33 ) ;
F_10 ( V_2 , V_36 , 0 ) ;
F_10 ( V_2 , V_37 , 0 ) ;
F_10 ( V_2 , V_38 , 0 ) ;
F_10 ( V_2 , V_39 , 0x2 ) ;
F_10 ( V_2 , V_40 , 0x2 ) ;
F_10 ( V_2 , V_41 , 0x10 ) ;
F_10 ( V_2 , V_42 , 0x4 ) ;
F_10 ( V_2 , V_43 , 88 ) ;
F_1 ( V_2 ) ;
F_10 ( V_2 , V_23 , V_8 | V_24 ) ;
}
static int F_16 ( struct V_13 * V_15 )
{
struct V_1 * V_2 = F_17 ( V_15 ) ;
F_12 ( V_2 ) ;
return 0 ;
}
static void F_18 ( struct V_13 * V_15 )
{
struct V_1 * V_2 = F_17 ( V_15 ) ;
F_9 ( V_2 ) ;
}
static int F_19 ( struct V_44 * V_45 )
{
struct V_1 * V_2 ;
struct V_13 * V_14 ;
struct V_46 * V_47 ;
T_3 V_48 ;
int V_6 ;
int error ;
V_47 = F_20 ( V_45 , V_49 , 0 ) ;
if ( ! V_47 ) {
F_21 ( & V_45 -> V_15 , L_1 ) ;
return - V_50 ;
}
V_6 = F_22 ( V_45 , 0 ) ;
if ( V_6 < 0 ) {
F_21 ( & V_45 -> V_15 , L_2 ) ;
return V_6 ;
}
V_2 = F_23 ( sizeof( * V_2 ) , V_51 ) ;
V_14 = F_24 () ;
if ( ! V_2 || ! V_14 ) {
F_21 ( & V_45 -> V_15 , L_3 ) ;
error = - V_52 ;
goto V_53;
}
V_2 -> V_15 = V_14 ;
V_2 -> V_6 = V_6 ;
V_48 = F_25 ( V_47 ) ;
if ( ! F_26 ( V_47 -> V_54 , V_48 , V_45 -> V_55 ) ) {
F_21 ( & V_45 -> V_15 , L_4 ) ;
error = - V_56 ;
goto V_53;
}
V_2 -> V_57 = F_27 ( V_47 -> V_54 , V_48 ) ;
if ( ! V_2 -> V_57 ) {
F_21 ( & V_45 -> V_15 , L_5 ) ;
error = - V_52 ;
goto V_58;
}
V_2 -> V_25 = F_28 ( & V_45 -> V_15 , NULL ) ;
if ( F_29 ( V_2 -> V_25 ) ) {
F_21 ( & V_45 -> V_15 , L_6 ) ;
error = F_30 ( V_2 -> V_25 ) ;
goto V_59;
}
V_14 -> V_55 = V_60 ;
V_14 -> V_61 = L_7 ;
V_14 -> V_62 . V_63 = V_64 ;
V_14 -> V_62 . V_65 = 0x0001 ;
V_14 -> V_62 . V_66 = 0x0002 ;
V_14 -> V_62 . V_67 = 0x0100 ;
V_14 -> V_15 . V_68 = & V_45 -> V_15 ;
V_14 -> V_69 = F_16 ;
V_14 -> V_70 = F_18 ;
V_14 -> V_71 [ 0 ] = F_31 ( V_72 ) | F_31 ( V_73 ) ;
V_14 -> V_74 [ F_32 ( V_22 ) ] = F_31 ( V_22 ) ;
F_33 ( V_14 , V_20 , V_31 ,
V_33 , 0 , 0 ) ;
F_33 ( V_14 , V_21 , V_31 ,
V_33 , 0 , 0 ) ;
F_34 ( V_14 , V_2 ) ;
error = F_35 ( V_2 -> V_6 , F_3 ,
0 , V_45 -> V_55 , V_2 ) ;
if ( error ) {
F_21 ( & V_45 -> V_15 , L_8 ) ;
goto V_75;
}
error = F_36 ( V_14 ) ;
if ( error ) {
F_21 ( & V_45 -> V_15 , L_9 ) ;
goto V_76;
}
F_37 ( V_45 , V_2 ) ;
F_38 ( & V_45 -> V_15 , 1 ) ;
return 0 ;
V_76:
F_39 ( V_2 -> V_6 , V_2 ) ;
V_75:
F_40 ( V_2 -> V_25 ) ;
V_59:
F_41 ( V_2 -> V_57 ) ;
V_58:
F_42 ( V_47 -> V_54 , V_48 ) ;
V_53:
F_43 ( V_14 ) ;
F_44 ( V_2 ) ;
return error ;
}
static int F_45 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = F_46 ( V_45 ) ;
struct V_46 * V_47 ;
F_39 ( V_2 -> V_6 , V_2 ) ;
F_47 ( V_2 -> V_15 ) ;
F_40 ( V_2 -> V_25 ) ;
F_41 ( V_2 -> V_57 ) ;
V_47 = F_20 ( V_45 , V_49 , 0 ) ;
F_42 ( V_47 -> V_54 , F_25 ( V_47 ) ) ;
F_44 ( V_2 ) ;
return 0 ;
}
static int F_48 ( struct V_77 * V_15 )
{
struct V_1 * V_2 = F_49 ( V_15 ) ;
struct V_13 * V_14 = V_2 -> V_15 ;
F_50 ( & V_14 -> V_78 ) ;
if ( V_14 -> V_79 ) {
if ( F_51 ( V_15 ) )
F_52 ( V_2 -> V_6 ) ;
else
F_9 ( V_2 ) ;
}
F_53 ( & V_14 -> V_78 ) ;
return 0 ;
}
static int F_54 ( struct V_77 * V_15 )
{
struct V_1 * V_2 = F_49 ( V_15 ) ;
struct V_13 * V_14 = V_2 -> V_15 ;
F_50 ( & V_14 -> V_78 ) ;
if ( V_14 -> V_79 ) {
if ( F_51 ( V_15 ) )
F_55 ( V_2 -> V_6 ) ;
else
F_12 ( V_2 ) ;
}
F_53 ( & V_14 -> V_78 ) ;
return 0 ;
}
