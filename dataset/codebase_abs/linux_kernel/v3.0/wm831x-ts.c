static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 =
F_2 ( V_2 , struct V_3 , V_4 ) ;
if ( V_3 -> V_5 ) {
F_3 ( V_3 -> V_6 ) ;
F_4 ( V_3 -> V_7 -> V_8 , L_1 ) ;
} else {
F_3 ( V_3 -> V_9 ) ;
F_4 ( V_3 -> V_7 -> V_8 , L_2 ) ;
}
}
static T_1 F_5 ( int V_10 , void * V_11 )
{
struct V_3 * V_3 = V_11 ;
struct V_7 * V_7 = V_3 -> V_7 ;
static int V_12 [] = { V_13 , V_14 , V_15 } ;
T_2 V_16 [ 3 ] ;
int V_17 ;
int V_18 , V_19 ;
if ( V_3 -> V_20 )
V_17 = 3 ;
else
V_17 = 2 ;
F_6 ( V_7 , V_21 ,
V_22 , V_22 ) ;
V_19 = F_7 ( V_7 , V_23 , V_17 ,
V_16 ) ;
if ( V_19 != 0 ) {
F_8 ( V_7 -> V_8 , L_3 ,
V_19 ) ;
return V_24 ;
}
V_3 -> V_5 = true ;
for ( V_18 = 0 ; V_18 < V_17 ; V_18 ++ ) {
if ( ! ( V_16 [ V_18 ] & V_25 ) ) {
V_3 -> V_5 = false ;
continue;
}
F_9 ( V_3 -> V_26 , V_12 [ V_18 ] ,
V_16 [ V_18 ] & V_27 ) ;
}
if ( ! V_3 -> V_5 ) {
F_4 ( V_7 -> V_8 , L_4 ) ;
F_10 ( V_3 -> V_6 ) ;
F_6 ( V_7 , V_28 ,
V_29 | V_30 |
V_31 , 0 ) ;
F_6 ( V_7 , V_21 ,
V_22 , V_22 ) ;
F_7 ( V_7 , V_23 , V_17 , V_16 ) ;
if ( V_3 -> V_20 )
F_9 ( V_3 -> V_26 ,
V_15 , 0 ) ;
F_11 ( V_3 -> V_26 , V_32 , 0 ) ;
F_12 ( & V_3 -> V_4 ) ;
} else {
F_11 ( V_3 -> V_26 , V_32 , 1 ) ;
}
F_13 ( V_3 -> V_26 ) ;
return V_33 ;
}
static T_1 F_14 ( int V_10 , void * V_11 )
{
struct V_3 * V_3 = V_11 ;
struct V_7 * V_7 = V_3 -> V_7 ;
int V_34 = 0 ;
if ( V_3 -> V_5 )
return V_33 ;
F_10 ( V_3 -> V_9 ) ;
if ( V_3 -> V_20 )
V_34 |= V_31 ;
F_6 ( V_7 , V_28 ,
V_29 | V_30 | V_31 ,
V_29 | V_30 | V_34 ) ;
F_6 ( V_7 , V_21 ,
V_35 , V_35 ) ;
V_3 -> V_5 = true ;
F_4 ( V_7 -> V_8 , L_5 ) ;
F_12 ( & V_3 -> V_4 ) ;
return V_33 ;
}
static int F_15 ( struct V_26 * V_36 )
{
struct V_3 * V_3 = F_16 ( V_36 ) ;
struct V_7 * V_7 = V_3 -> V_7 ;
F_6 ( V_7 , V_28 ,
V_37 | V_38 |
V_29 | V_30 |
V_31 , V_37 ) ;
F_6 ( V_7 , V_28 ,
V_38 , V_38 ) ;
return 0 ;
}
static void F_17 ( struct V_26 * V_36 )
{
struct V_3 * V_3 = F_16 ( V_36 ) ;
struct V_7 * V_7 = V_3 -> V_7 ;
F_6 ( V_7 , V_28 ,
V_37 | V_29 |
V_30 | V_31 , 0 ) ;
F_18 ( V_3 -> V_6 ) ;
F_18 ( V_3 -> V_9 ) ;
F_19 ( & V_3 -> V_4 ) ;
if ( V_3 -> V_5 ) {
F_20 ( V_3 -> V_6 ) ;
F_3 ( V_3 -> V_9 ) ;
V_3 -> V_5 = false ;
}
}
static T_3 int F_21 ( struct V_39 * V_40 )
{
struct V_3 * V_3 ;
struct V_7 * V_7 = F_22 ( V_40 -> V_8 . V_41 ) ;
struct V_42 * V_43 = F_23 ( V_40 -> V_8 . V_41 ) ;
struct V_44 * V_45 = NULL ;
struct V_26 * V_26 ;
int error , V_46 ;
if ( V_43 )
V_45 = V_43 -> V_47 ;
V_3 = F_24 ( sizeof( struct V_3 ) , V_48 ) ;
V_26 = F_25 () ;
if ( ! V_3 || ! V_26 ) {
error = - V_49 ;
goto V_50;
}
V_3 -> V_7 = V_7 ;
V_3 -> V_26 = V_26 ;
F_26 ( & V_3 -> V_4 , F_1 ) ;
if ( V_45 && V_45 -> V_6 )
V_3 -> V_6 = V_45 -> V_6 ;
else
V_3 -> V_6 = F_27 ( V_40 , L_6 ) ;
if ( V_45 && V_45 -> V_9 )
V_3 -> V_9 = V_45 -> V_9 ;
else
V_3 -> V_9 = F_27 ( V_40 , L_7 ) ;
if ( V_45 )
V_3 -> V_20 = V_45 -> V_20 ;
else
V_3 -> V_20 = true ;
if ( V_45 && V_45 -> V_51 ) {
F_6 ( V_7 , V_52 ,
V_53 , V_53 ) ;
F_28 ( V_45 -> V_20 && V_45 -> V_51 ) ;
V_3 -> V_20 = false ;
} else {
F_6 ( V_7 , V_52 ,
V_53 , 0 ) ;
}
if ( V_45 ) {
switch ( V_45 -> V_54 ) {
default:
F_8 ( & V_40 -> V_8 , L_8 ,
V_45 -> V_54 ) ;
case 200 :
case 0 :
F_6 ( V_7 , V_52 ,
V_55 , 0 ) ;
break;
case 400 :
F_6 ( V_7 , V_52 ,
V_55 , V_55 ) ;
break;
}
}
F_6 ( V_7 , V_52 ,
V_56 , 0 ) ;
F_6 ( V_7 , V_28 ,
V_57 , 6 ) ;
if ( V_45 && V_45 -> V_58 )
V_46 = V_45 -> V_58 ;
else
V_46 = V_59 ;
error = F_29 ( V_3 -> V_6 ,
NULL , F_5 ,
V_46 | V_60 ,
L_9 , V_3 ) ;
if ( error ) {
F_8 ( & V_40 -> V_8 , L_10 ,
V_3 -> V_6 , error ) ;
goto V_50;
}
F_20 ( V_3 -> V_6 ) ;
if ( V_45 && V_45 -> V_61 )
V_46 = V_45 -> V_61 ;
else
V_46 = V_59 ;
error = F_29 ( V_3 -> V_9 ,
NULL , F_14 ,
V_46 | V_60 ,
L_11 , V_3 ) ;
if ( error ) {
F_8 ( & V_40 -> V_8 , L_12 ,
V_3 -> V_9 , error ) ;
goto V_62;
}
V_26 -> V_63 = L_13 ;
V_26 -> V_64 = L_14 ;
V_26 -> V_65 = F_15 ;
V_26 -> V_66 = F_17 ;
F_30 ( V_67 , V_26 -> V_68 ) ;
F_30 ( V_69 , V_26 -> V_68 ) ;
F_30 ( V_32 , V_26 -> V_70 ) ;
F_31 ( V_26 , V_13 , 0 , 4095 , 5 , 0 ) ;
F_31 ( V_26 , V_14 , 0 , 4095 , 5 , 0 ) ;
if ( V_3 -> V_20 )
F_31 ( V_26 , V_15 , 0 , 4095 , 5 , 0 ) ;
F_32 ( V_26 , V_3 ) ;
V_26 -> V_8 . V_41 = & V_40 -> V_8 ;
error = F_33 ( V_26 ) ;
if ( error )
goto V_71;
F_34 ( V_40 , V_3 ) ;
return 0 ;
V_71:
F_35 ( V_3 -> V_9 , V_3 ) ;
V_62:
F_35 ( V_3 -> V_6 , V_3 ) ;
V_50:
F_36 ( V_26 ) ;
F_37 ( V_3 ) ;
return error ;
}
static T_4 int F_38 ( struct V_39 * V_40 )
{
struct V_3 * V_3 = F_39 ( V_40 ) ;
F_35 ( V_3 -> V_9 , V_3 ) ;
F_35 ( V_3 -> V_6 , V_3 ) ;
F_40 ( V_3 -> V_26 ) ;
F_37 ( V_3 ) ;
F_34 ( V_40 , NULL ) ;
return 0 ;
}
static int T_5 F_41 ( void )
{
return F_42 ( & V_72 ) ;
}
static void T_6 F_43 ( void )
{
F_44 ( & V_72 ) ;
}
