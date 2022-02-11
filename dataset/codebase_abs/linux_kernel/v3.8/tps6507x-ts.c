static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
int V_5 ;
V_5 = V_2 -> V_6 -> V_7 ( V_2 -> V_6 , V_3 , 1 , V_4 ) ;
if ( V_5 )
return V_5 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
return V_2 -> V_6 -> V_8 ( V_2 -> V_6 , V_3 , 1 , & V_4 ) ;
}
static T_2 F_3 ( struct V_1 * V_2 ,
T_1 V_9 , T_3 * V_10 )
{
T_2 V_11 ;
T_1 V_12 ;
T_1 V_13 ;
V_11 = F_2 ( V_2 , V_14 , V_9 ) ;
if ( V_11 ) {
F_4 ( V_2 -> V_15 , L_1 ) ;
goto V_5;
}
V_11 = F_2 ( V_2 , V_16 ,
V_17 ) ;
if ( V_11 ) {
F_4 ( V_2 -> V_15 , L_2 ) ;
return V_11 ;
}
do {
V_11 = F_1 ( V_2 , V_16 ,
& V_12 ) ;
if ( V_11 ) {
F_4 ( V_2 -> V_15 , L_3 ) ;
goto V_5;
}
} while ( V_12 & V_18 );
V_11 = F_1 ( V_2 , V_19 , & V_13 ) ;
if ( V_11 ) {
F_4 ( V_2 -> V_15 , L_4 ) ;
goto V_5;
}
* V_10 = ( V_13 & V_20 ) << 8 ;
V_11 = F_1 ( V_2 , V_21 , & V_13 ) ;
if ( V_11 ) {
F_4 ( V_2 -> V_15 , L_5 ) ;
goto V_5;
}
* V_10 |= V_13 ;
F_5 ( V_2 -> V_15 , L_6 , V_9 , * V_10 ) ;
V_5:
return V_11 ;
}
static T_2 F_6 ( struct V_1 * V_2 )
{
T_2 V_11 ;
T_2 V_22 = 0 ;
T_1 V_23 ;
V_11 = F_2 ( V_2 , V_16 ,
V_24 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_2 ( V_2 , V_14 ,
V_25 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_1 ( V_2 , V_26 , & V_23 ) ;
if ( V_11 )
return V_11 ;
while ( V_23 & V_27 ) {
F_7 ( 10 ) ;
V_11 = F_1 ( V_2 , V_26 , & V_23 ) ;
if ( V_11 )
return V_11 ;
V_22 ++ ;
}
return V_11 ;
}
static void F_8 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_9 ( V_29 ,
struct V_1 , V_29 . V_29 ) ;
struct V_30 * V_30 = V_2 -> V_30 ;
int V_31 ;
int V_32 ;
int V_33 = 0 ;
T_2 V_11 ;
V_11 = F_3 ( V_2 , V_34 ,
& V_2 -> V_35 . V_36 ) ;
if ( V_11 )
goto V_37;
V_31 = V_2 -> V_35 . V_36 > V_2 -> V_38 ;
if ( F_10 ( ! V_31 && V_2 -> V_31 ) ) {
F_5 ( V_2 -> V_15 , L_7 ) ;
F_11 ( V_30 , V_39 , 0 ) ;
F_12 ( V_30 , V_40 , 0 ) ;
F_13 ( V_30 ) ;
V_2 -> V_31 = 0 ;
}
if ( V_31 ) {
if ( ! V_2 -> V_31 ) {
F_5 ( V_2 -> V_15 , L_8 ) ;
F_11 ( V_30 , V_39 , 1 ) ;
} else
F_5 ( V_2 -> V_15 , L_9 ) ;
V_11 = F_3 ( V_2 , V_41 ,
& V_2 -> V_35 . V_42 ) ;
if ( V_11 )
goto V_37;
V_11 = F_3 ( V_2 , V_43 ,
& V_2 -> V_35 . V_44 ) ;
if ( V_11 )
goto V_37;
F_12 ( V_30 , V_45 , V_2 -> V_35 . V_42 ) ;
F_12 ( V_30 , V_46 , V_2 -> V_35 . V_44 ) ;
F_12 ( V_30 , V_40 , V_2 -> V_35 . V_36 ) ;
F_13 ( V_30 ) ;
V_2 -> V_31 = 1 ;
V_33 = 1 ;
}
V_37:
V_33 = 1 ;
if ( V_33 ) {
V_32 = F_14 ( & V_2 -> V_29 ,
F_15 ( V_2 -> V_47 ) ) ;
if ( V_32 )
V_2 -> V_48 = 1 ;
else {
V_2 -> V_48 = 0 ;
F_4 ( V_2 -> V_15 , L_10 ) ;
}
} else
V_2 -> V_48 = 0 ;
V_11 = F_6 ( V_2 ) ;
}
static int F_16 ( struct V_49 * V_50 )
{
int error ;
struct V_1 * V_2 ;
struct V_51 * V_51 = F_17 ( V_50 -> V_15 . V_52 ) ;
struct V_53 * V_54 ;
struct V_30 * V_30 ;
struct V_55 * V_56 ;
int V_32 ;
V_56 = (struct V_55 * ) V_51 -> V_15 -> V_57 ;
if ( ! V_56 ) {
F_4 ( V_51 -> V_15 ,
L_11 ) ;
return - V_58 ;
}
V_54 = V_56 -> V_59 ;
V_2 = F_18 ( sizeof( struct V_1 ) , V_60 ) ;
if ( ! V_2 ) {
F_4 ( V_51 -> V_15 , L_12 ) ;
error = - V_61 ;
goto V_62;
}
V_51 -> V_63 = V_2 ;
V_2 -> V_6 = V_51 ;
V_2 -> V_15 = V_51 -> V_15 ;
V_30 = F_19 () ;
if ( ! V_30 ) {
F_4 ( V_2 -> V_15 , L_13 ) ;
error = - V_61 ;
goto V_64;
}
V_30 -> V_65 [ 0 ] = F_20 ( V_66 ) | F_20 ( V_67 ) ;
V_30 -> V_68 [ F_21 ( V_39 ) ] = F_20 ( V_39 ) ;
F_22 ( V_30 , V_45 , 0 , V_69 , 0 , 0 ) ;
F_22 ( V_30 , V_46 , 0 , V_69 , 0 , 0 ) ;
F_22 ( V_30 , V_40 , 0 , V_69 , 0 , 0 ) ;
V_30 -> V_70 = L_14 ;
V_30 -> V_71 . V_72 = V_73 ;
V_30 -> V_15 . V_52 = V_2 -> V_15 ;
snprintf ( V_2 -> V_74 , sizeof( V_2 -> V_74 ) ,
L_15 , F_23 ( V_2 -> V_15 ) ) ;
V_30 -> V_74 = V_2 -> V_74 ;
F_5 ( V_2 -> V_15 , L_16 , V_30 -> V_74 ) ;
F_24 ( V_30 , V_2 ) ;
V_2 -> V_30 = V_30 ;
F_25 ( & V_2 -> V_29 , F_8 ) ;
if ( V_54 ) {
V_2 -> V_47 = V_54 -> V_47 ;
V_2 -> V_75 = V_54 -> V_75 ;
V_2 -> V_38 = V_54 -> V_38 ;
V_30 -> V_71 . V_76 = V_54 -> V_76 ;
V_30 -> V_71 . V_77 = V_54 -> V_77 ;
V_30 -> V_71 . V_78 = V_54 -> V_78 ;
} else {
V_2 -> V_47 = V_79 ;
V_2 -> V_38 = V_80 ;
}
error = F_6 ( V_2 ) ;
if ( error )
goto V_81;
error = F_26 ( V_30 ) ;
if ( error )
goto V_81;
V_32 = F_14 ( & V_2 -> V_29 ,
F_15 ( V_2 -> V_47 ) ) ;
if ( V_32 )
V_2 -> V_48 = 1 ;
else {
V_2 -> V_48 = 0 ;
F_4 ( V_2 -> V_15 , L_17 ) ;
goto V_81;
}
F_27 ( V_50 , V_51 ) ;
return 0 ;
V_81:
F_28 ( & V_2 -> V_29 ) ;
F_29 ( V_30 ) ;
V_64:
F_30 ( V_2 ) ;
V_51 -> V_63 = NULL ;
V_62:
return error ;
}
static int F_31 ( struct V_49 * V_50 )
{
struct V_51 * V_51 = F_32 ( V_50 ) ;
struct V_1 * V_2 = V_51 -> V_63 ;
struct V_30 * V_30 = V_2 -> V_30 ;
F_28 ( & V_2 -> V_29 ) ;
F_33 ( V_30 ) ;
V_51 -> V_63 = NULL ;
F_30 ( V_2 ) ;
return 0 ;
}
