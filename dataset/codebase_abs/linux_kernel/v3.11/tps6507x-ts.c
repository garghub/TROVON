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
struct V_1 * V_2 = V_29 -> V_30 ;
struct V_31 * V_31 = V_29 -> V_32 ;
bool V_33 ;
T_2 V_11 ;
V_11 = F_3 ( V_2 , V_34 ,
& V_2 -> V_35 . V_36 ) ;
if ( V_11 )
goto V_37;
V_33 = V_2 -> V_35 . V_36 > V_2 -> V_38 ;
if ( F_9 ( ! V_33 && V_2 -> V_33 ) ) {
F_5 ( V_2 -> V_15 , L_7 ) ;
F_10 ( V_31 , V_39 , 0 ) ;
F_11 ( V_31 , V_40 , 0 ) ;
F_12 ( V_31 ) ;
V_2 -> V_33 = false ;
}
if ( V_33 ) {
if ( ! V_2 -> V_33 ) {
F_5 ( V_2 -> V_15 , L_8 ) ;
F_10 ( V_31 , V_39 , 1 ) ;
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
F_11 ( V_31 , V_45 , V_2 -> V_35 . V_42 ) ;
F_11 ( V_31 , V_46 , V_2 -> V_35 . V_44 ) ;
F_11 ( V_31 , V_40 , V_2 -> V_35 . V_36 ) ;
F_12 ( V_31 ) ;
V_2 -> V_33 = true ;
}
V_37:
F_6 ( V_2 ) ;
}
static int F_13 ( struct V_47 * V_48 )
{
struct V_49 * V_49 = F_14 ( V_48 -> V_15 . V_50 ) ;
const struct V_51 * V_52 ;
const struct V_53 * V_54 ;
struct V_1 * V_2 ;
struct V_28 * V_29 ;
struct V_31 * V_31 ;
int error ;
V_52 = F_15 ( V_49 -> V_15 ) ;
if ( ! V_52 ) {
F_4 ( V_49 -> V_15 ,
L_10 ) ;
return - V_55 ;
}
V_54 = V_52 -> V_56 ;
V_2 = F_16 ( sizeof( struct V_1 ) , V_57 ) ;
if ( ! V_2 ) {
F_4 ( V_49 -> V_15 , L_11 ) ;
return - V_58 ;
}
V_2 -> V_6 = V_49 ;
V_2 -> V_15 = V_49 -> V_15 ;
V_2 -> V_38 = V_54 ?
V_54 -> V_38 : V_59 ;
snprintf ( V_2 -> V_60 , sizeof( V_2 -> V_60 ) ,
L_12 , F_17 ( V_2 -> V_15 ) ) ;
V_29 = F_18 () ;
if ( ! V_29 ) {
F_4 ( V_2 -> V_15 , L_13 ) ;
error = - V_58 ;
goto V_61;
}
V_2 -> V_29 = V_29 ;
V_29 -> V_30 = V_2 ;
V_29 -> V_62 = F_8 ;
V_29 -> V_63 = V_54 ?
V_54 -> V_64 : V_65 ;
V_31 = V_29 -> V_32 ;
V_31 -> V_66 [ 0 ] = F_19 ( V_67 ) | F_19 ( V_68 ) ;
V_31 -> V_69 [ F_20 ( V_39 ) ] = F_19 ( V_39 ) ;
F_21 ( V_31 , V_45 , 0 , V_70 , 0 , 0 ) ;
F_21 ( V_31 , V_46 , 0 , V_70 , 0 , 0 ) ;
F_21 ( V_31 , V_40 , 0 , V_70 , 0 , 0 ) ;
V_31 -> V_71 = L_14 ;
V_31 -> V_60 = V_2 -> V_60 ;
V_31 -> V_15 . V_50 = V_2 -> V_15 ;
V_31 -> V_72 . V_73 = V_74 ;
if ( V_54 ) {
V_31 -> V_72 . V_75 = V_54 -> V_75 ;
V_31 -> V_72 . V_76 = V_54 -> V_76 ;
V_31 -> V_72 . V_77 = V_54 -> V_77 ;
}
error = F_6 ( V_2 ) ;
if ( error )
goto V_78;
error = F_22 ( V_29 ) ;
if ( error )
goto V_78;
F_23 ( V_48 , V_2 ) ;
return 0 ;
V_78:
F_24 ( V_29 ) ;
V_61:
F_25 ( V_2 ) ;
return error ;
}
static int F_26 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_27 ( V_48 ) ;
struct V_28 * V_29 = V_2 -> V_29 ;
F_28 ( V_29 ) ;
F_24 ( V_29 ) ;
F_25 ( V_2 ) ;
return 0 ;
}
