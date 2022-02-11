static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_3 * V_5 )
{
int V_6 , V_7 = 0 , V_8 = 0 ;
int error ;
F_2 ( V_4 , 1 ) ;
F_2 ( V_5 , 1 ) ;
F_3 ( V_9 , V_10 ) ;
for ( V_6 = 0 ; V_6 < V_11 ; V_6 ++ ) {
error = F_4 ( V_2 , & V_8 ) ;
if ( error < 0 ) {
V_7 = error ;
goto V_12;
}
V_7 += V_8 ;
}
V_7 /= V_11 ;
V_12:
F_2 ( V_4 , 0 ) ;
F_2 ( V_5 , 0 ) ;
return V_7 ;
}
static void F_5 ( struct V_13 * V_14 )
{
F_2 ( V_14 -> V_15 , 1 ) ;
F_6 ( & V_14 -> V_16 -> V_17 ) ;
F_3 ( V_18 , V_19 ) ;
}
static T_1 F_7 ( int V_20 , void * V_21 )
{
struct V_13 * V_14 = V_21 ;
struct V_22 * V_17 = & V_14 -> V_16 -> V_17 ;
int V_23 , V_24 , V_25 , V_26 , V_27 = 0 ;
bool V_28 = true ;
F_2 ( V_14 -> V_15 , 0 ) ;
F_8 ( V_17 ) ;
while ( ! V_14 -> V_29 ) {
V_23 = F_1 ( & V_14 -> V_30 [ 0 ] ,
V_14 -> V_31 , V_14 -> V_32 ) ;
if ( V_23 < 0 )
break;
V_24 = F_1 ( & V_14 -> V_30 [ 1 ] ,
V_14 -> V_33 , V_14 -> V_15 ) ;
if ( V_24 < 0 )
break;
V_25 = F_1 ( & V_14 -> V_30 [ 2 ] ,
V_14 -> V_33 , V_14 -> V_32 ) ;
if ( V_25 < 0 )
break;
V_26 = F_1 ( & V_14 -> V_30 [ 3 ] ,
V_14 -> V_33 , V_14 -> V_32 ) ;
if ( V_26 < 0 )
break;
if ( V_25 > 64 && V_23 > 64 ) {
int V_34 = ( 1000 * V_23 ) / V_35 ;
V_27 = ( V_34 * V_26 ) / V_25 - V_34 ;
} else {
V_27 = 2000 ;
}
V_27 = 2000 - V_27 ;
F_9 ( V_17 ,
L_1 ,
V_23 , V_24 , V_25 , V_26 , V_27 ) ;
if ( V_27 < V_14 -> V_36 || V_27 > 2000 )
break;
if ( V_28 ) {
V_28 = false ;
} else {
F_10 ( V_14 -> V_37 ,
V_38 , V_35 - V_23 ) ;
F_10 ( V_14 -> V_37 ,
V_39 , V_35 - V_24 ) ;
F_10 ( V_14 -> V_37 ,
V_40 , V_27 ) ;
F_11 ( V_14 -> V_37 , V_41 , 1 ) ;
F_12 ( V_14 -> V_37 ) ;
}
F_3 ( V_18 ,
V_19 ) ;
}
F_10 ( V_14 -> V_37 , V_40 , 0 ) ;
F_11 ( V_14 -> V_37 , V_41 , 0 ) ;
F_12 ( V_14 -> V_37 ) ;
F_5 ( V_14 ) ;
return V_42 ;
}
static int F_13 ( struct V_43 * V_44 )
{
struct V_13 * V_45 = F_14 ( V_44 ) ;
struct V_22 * V_17 = & V_45 -> V_16 -> V_17 ;
F_9 ( V_17 , L_2 ,
V_44 -> V_46 ) ;
V_45 -> V_29 = false ;
F_5 ( V_45 ) ;
return 0 ;
}
static void F_15 ( struct V_43 * V_44 )
{
struct V_13 * V_45 = F_14 ( V_44 ) ;
struct V_22 * V_17 = & V_45 -> V_16 -> V_17 ;
V_45 -> V_29 = true ;
F_16 () ;
F_17 ( V_45 -> V_47 ) ;
F_2 ( V_45 -> V_15 , 0 ) ;
F_8 ( V_17 ) ;
F_9 ( V_17 , L_3 ,
V_44 -> V_46 ) ;
}
static int F_18 ( struct V_22 * V_17 , struct V_3 * * V_48 ,
const char * V_49 , enum V_50 V_51 )
{
int error ;
* V_48 = F_19 ( V_17 , V_49 , V_51 ) ;
if ( F_20 ( * V_48 ) ) {
error = F_21 ( * V_48 ) ;
F_22 ( V_17 , L_4 , V_49 , error ) ;
return error ;
}
return 0 ;
}
static void F_23 ( void * V_52 )
{
struct V_1 * V_30 = V_52 ;
F_24 ( V_30 ) ;
}
static int F_25 ( struct V_53 * V_16 )
{
struct V_43 * V_54 ;
struct V_1 * V_30 ;
struct V_22 * V_17 = & V_16 -> V_17 ;
struct V_13 * V_45 ;
int V_55 ;
int error ;
V_30 = F_26 ( V_17 ) ;
if ( F_20 ( V_30 ) )
return F_21 ( V_30 ) ;
error = F_27 ( V_17 , F_23 , V_30 ) ;
if ( error ) {
F_24 ( V_30 ) ;
F_22 ( V_17 , L_5 ) ;
return error ;
}
V_55 = 0 ;
while ( V_30 [ V_55 ] . V_56 )
V_55 ++ ;
if ( V_55 != V_57 ) {
F_22 ( V_17 , L_6 ) ;
return - V_58 ;
}
V_45 = F_28 ( V_17 , sizeof( * V_45 ) , V_59 ) ;
if ( ! V_45 )
return - V_60 ;
V_45 -> V_16 = V_16 ;
V_45 -> V_30 = V_30 ;
error = F_29 ( V_17 -> V_61 , L_7 ,
& V_45 -> V_36 ) ;
if ( error )
return error ;
V_54 = F_30 ( V_17 ) ;
if ( ! V_54 ) {
F_22 ( V_17 , L_8 ) ;
return - V_60 ;
}
V_54 -> V_46 = V_62 ;
V_54 -> V_63 . V_64 = V_65 ;
V_54 -> V_17 . V_66 = V_17 ;
V_54 -> V_67 = F_13 ;
V_54 -> V_68 = F_15 ;
F_31 ( V_54 , V_69 , V_41 ) ;
F_32 ( V_54 , V_38 , 0 , V_35 , 0 , 0 ) ;
F_32 ( V_54 , V_39 , 0 , V_35 , 0 , 0 ) ;
F_32 ( V_54 , V_40 , 0 , V_35 , 0 , 0 ) ;
V_45 -> V_37 = V_54 ;
F_33 ( V_54 , V_45 ) ;
error = F_34 ( V_54 ) ;
if ( error ) {
F_22 ( V_17 , L_9 ) ;
return error ;
}
error = F_18 ( V_17 , & V_45 -> V_31 , L_10 , V_70 ) ;
if ( error )
return error ;
error = F_18 ( V_17 , & V_45 -> V_32 ,
L_11 , V_70 ) ;
if ( error )
return error ;
error = F_18 ( V_17 , & V_45 -> V_33 , L_12 , V_70 ) ;
if ( error )
return error ;
error = F_18 ( V_17 , & V_45 -> V_15 , L_13 , V_70 ) ;
if ( error )
return error ;
V_45 -> V_47 = F_35 ( V_16 , 0 ) ;
if ( V_45 -> V_47 < 0 )
return V_45 -> V_47 ;
error = F_36 ( V_17 , V_45 -> V_47 ,
NULL , F_7 , V_71 ,
L_14 , V_45 ) ;
if ( error ) {
F_22 ( V_17 , L_15 ,
V_45 -> V_47 , error ) ;
return error ;
}
return 0 ;
}
