static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_5 = F_2 ( V_2 -> V_6 ) ;
if ( ! V_5 ) {
F_3 ( & V_2 -> V_7 , L_1 , V_2 -> V_6 ) ;
return - V_8 ;
}
V_4 -> V_9 = F_4 ( V_5 ) ;
F_5 ( & V_2 -> V_7 , L_2 , V_4 -> V_9 ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_10 * V_11 = V_2 -> V_7 . V_12 ;
int V_13 ;
T_1 V_14 ;
V_13 = F_7 ( V_11 , L_3 , & V_14 ) ;
if ( ! V_13 ) {
V_4 -> V_15 = 1 ;
V_4 -> V_16 = V_14 ;
}
V_13 = F_7 ( V_11 , L_4 , & V_14 ) ;
if ( ! V_13 ) {
V_4 -> V_15 = 1 ;
V_4 -> V_17 = V_14 ;
}
V_13 = F_7 ( V_11 , L_5 , & V_14 ) ;
if ( ! V_13 )
V_4 -> V_18 = V_14 ;
else
V_4 -> V_18 = V_19 |
V_20 |
V_21 ;
if ( V_2 -> V_6 )
F_1 ( V_2 , V_4 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
const struct V_22 * V_23 )
{
struct V_24 * V_24 ;
struct V_3 * V_4 ;
struct V_10 * V_11 = V_2 -> V_7 . V_12 ;
int V_13 = 0 , V_25 ;
unsigned int V_26 , V_27 , * V_28 ;
int V_29 ;
const struct V_30 * V_31 ;
V_4 = F_9 ( & V_2 -> V_7 ) ;
if ( V_11 && ! V_4 ) {
V_4 = F_10 ( & V_2 -> V_7 , sizeof( * V_4 ) , V_32 ) ;
if ( ! V_4 )
return - V_33 ;
F_6 ( V_2 , V_4 ) ;
}
if ( ! V_4 )
return - V_8 ;
V_24 = F_10 ( & V_2 -> V_7 , sizeof( struct V_24 ) , V_32 ) ;
if ( V_24 == NULL )
return - V_33 ;
F_11 ( V_2 , V_24 ) ;
V_24 -> V_7 = & V_2 -> V_7 ;
V_24 -> V_6 = V_2 -> V_6 ;
V_31 = F_12 ( F_13 ( V_34 ) , & V_2 -> V_7 ) ;
if ( ! V_31 )
return - V_35 ;
V_28 = ( unsigned int * ) V_31 -> V_36 ;
V_24 -> V_28 = * V_28 ;
for ( V_25 = 0 ; V_25 < V_37 ; V_25 ++ ) {
if ( V_25 == 0 )
V_24 -> V_38 [ V_25 ] = V_2 ;
else {
V_24 -> V_38 [ V_25 ] =
F_14 ( V_2 -> V_39 ,
V_2 -> V_27 + V_25 ) ;
if ( ! V_24 -> V_38 [ V_25 ] ) {
F_3 ( V_24 -> V_7 ,
L_6 , V_25 ) ;
V_13 = - V_33 ;
goto V_40;
}
V_24 -> V_38 [ V_25 ] -> V_7 . V_12 = F_15 ( V_11 ) ;
}
V_24 -> V_41 [ V_25 ] = F_16 ( V_24 -> V_38 [ V_25 ] ,
& V_42 [ V_25 ] ) ;
if ( F_17 ( V_24 -> V_41 [ V_25 ] ) ) {
V_13 = F_18 ( V_24 -> V_41 [ V_25 ] ) ;
F_3 ( V_24 -> V_7 ,
L_7 ,
V_25 , V_13 ) ;
goto V_40;
}
}
if ( ! V_24 -> V_6 ) {
F_19 ( V_24 -> V_7 , L_8 ) ;
goto V_43;
}
if ( V_4 -> V_9 & V_44 )
V_26 = V_45 ;
else
V_26 = 0 ;
V_13 = F_20 ( V_24 , V_46 ,
V_47 , V_45 ,
V_26 ) ;
if ( V_13 < 0 ) {
F_3 ( V_24 -> V_7 , L_9 , V_13 ) ;
goto V_40;
}
V_29 = F_21 ( V_48 ) ;
V_27 = F_22 ( V_48 , V_49 ) ;
V_26 = V_50 ;
F_23 ( V_24 -> V_41 [ V_29 ] , V_27 , V_26 ) ;
V_13 = F_24 ( V_24 -> V_41 [ V_29 ] , V_24 -> V_6 ,
V_51 | V_4 -> V_9 , 0 , & V_52 ,
& V_24 -> V_5 ) ;
if ( V_13 < 0 )
goto V_40;
V_43:
V_29 = F_21 ( V_46 ) ;
V_27 = F_22 ( V_46 ,
V_53 ) ;
if ( V_4 -> V_15 ) {
V_26 = V_4 -> V_16 ;
V_13 = F_23 ( V_24 -> V_41 [ V_29 ] , V_27 , V_26 ) ;
if ( V_13 )
goto V_54;
} else {
V_13 = F_25 ( V_24 -> V_41 [ V_29 ] , V_27 , & V_26 ) ;
if ( V_13 )
goto V_54;
}
if ( ! ( V_26 & V_55 ) )
V_24 -> V_56 |= V_57 ;
if ( ! ( V_26 & V_58 ) )
V_24 -> V_56 |= V_59 ;
else if ( ( V_26 & V_58 ) ==
( 2 << V_60 ) )
V_24 -> V_61 |= V_62 ;
else if ( ( V_26 & V_58 ) ==
( 3 << V_60 ) )
V_24 -> V_63 |= V_64 ;
if ( ! ( V_26 & V_65 ) )
V_24 -> V_56 |= V_66 ;
else if ( ( V_26 & V_65 ) ==
( 2 << V_67 ) )
V_24 -> V_61 |= V_68 ;
else if ( ( V_26 & V_65 ) ==
( 3 << V_67 ) )
V_24 -> V_63 |= V_69 ;
if ( ! ( V_26 & V_70 ) )
V_24 -> V_56 |= V_71 ;
V_27 = F_22 ( V_46 ,
V_72 ) ;
if ( V_4 -> V_15 ) {
V_26 = V_4 -> V_17 ;
V_13 = F_23 ( V_24 -> V_41 [ V_29 ] , V_27 , V_26 ) ;
if ( V_13 )
goto V_54;
} else {
V_13 = F_25 ( V_24 -> V_41 [ V_29 ] , V_27 , & V_26 ) ;
if ( V_13 )
goto V_54;
}
if ( ! ( V_26 & V_73 ) )
V_24 -> V_56 |= V_74 ;
if ( ! ( V_26 & V_75 ) )
V_24 -> V_56 |= V_76 ;
if ( ! ( V_26 & V_77 ) )
V_24 -> V_56 |= V_78 ;
if ( ! ( V_26 & V_79 ) )
V_24 -> V_56 |= V_80 ;
F_5 ( V_24 -> V_7 , L_10 ,
V_24 -> V_56 , V_24 -> V_63 ,
V_24 -> V_61 ) ;
V_26 = V_4 -> V_18 ;
V_29 = F_21 ( V_81 ) ;
V_27 = F_22 ( V_81 , V_82 ) ;
V_13 = F_23 ( V_24 -> V_41 [ V_29 ] , V_27 , V_26 ) ;
if ( V_13 )
goto V_54;
if ( V_11 ) {
V_13 = F_26 ( V_11 , NULL , NULL , & V_2 -> V_7 ) ;
if ( V_13 < 0 )
goto V_54;
else
return V_13 ;
}
return V_13 ;
V_54:
F_27 ( V_24 -> V_6 , V_24 -> V_5 ) ;
V_40:
return V_13 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_24 * V_24 = F_29 ( V_2 ) ;
F_30 ( V_24 -> V_7 ) ;
F_27 ( V_24 -> V_6 , V_24 -> V_5 ) ;
return 0 ;
}
static int T_2 F_31 ( void )
{
return F_32 ( & V_83 ) ;
}
static void T_3 F_33 ( void )
{
F_34 ( & V_83 ) ;
}
