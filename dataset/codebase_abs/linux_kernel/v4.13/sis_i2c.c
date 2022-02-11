static int F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned int * V_4 ,
unsigned int * V_5 )
{
int V_6 ;
int V_7 ;
T_2 V_8 ;
T_2 V_9 , V_10 ;
T_1 V_11 ;
V_7 = F_2 ( V_2 , V_3 , V_12 ) ;
if ( V_7 <= 0 )
return - V_13 ;
V_8 = F_3 ( & V_3 [ V_14 ] ) ;
if ( V_8 > V_12 ) {
F_4 ( & V_2 -> V_15 ,
L_1 ,
V_16 , V_8 , V_12 ) ;
return - V_17 ;
}
if ( V_8 < 10 )
return - V_18 ;
V_11 = V_3 [ V_19 ] ;
V_6 = V_8 - 1 ;
* V_5 = V_20 ;
if ( V_11 != V_21 ) {
if ( F_5 ( V_11 ) ) {
V_9 = F_6 ( 0 , V_3 + 2 , V_8 - 2 - 2 ) ;
V_10 = F_3 ( & V_3 [ V_8 - 2 ] ) ;
if ( V_9 != V_10 ) {
F_4 ( & V_2 -> V_15 ,
L_2 ,
V_16 , V_9 , V_10 ) ;
return - V_18 ;
}
V_6 -= 2 ;
} else if ( ! F_7 ( V_11 ) ) {
F_4 ( & V_2 -> V_15 ,
L_3 ,
V_16 , V_11 ) ;
return - V_18 ;
}
if ( F_8 ( V_11 ) )
V_6 -= V_22 ;
if ( F_9 ( V_11 ) )
* V_5 += V_23 ;
if ( F_10 ( V_11 ) )
* V_5 += V_24 ;
}
* V_4 = V_3 [ V_6 ] ;
return 0 ;
}
static int F_11 ( struct V_25 * V_26 , const T_1 * V_27 , T_1 V_28 )
{
struct V_29 * V_30 = V_26 -> V_30 ;
int V_31 ;
T_1 V_32 = V_27 [ V_33 ] ;
T_1 V_34 ;
T_1 V_35 , V_36 ;
T_2 V_37 , V_38 ;
if ( V_32 != V_39 && V_32 != V_40 ) {
F_4 ( & V_26 -> V_2 -> V_15 , L_4 ,
V_27 [ V_33 ] ) ;
return - V_18 ;
}
V_31 = F_12 ( V_30 , V_27 [ V_41 ] ) ;
if ( V_31 < 0 )
return - V_42 ;
F_13 ( V_30 , V_31 ) ;
F_14 ( V_30 , V_43 ,
V_32 == V_39 ) ;
if ( V_32 == V_39 ) {
V_34 = V_35 = V_36 = 1 ;
if ( V_28 != V_21 ) {
if ( F_9 ( V_28 ) ) {
V_36 = V_27 [ V_44 ] ;
V_35 = V_27 [ V_45 ] ;
}
if ( F_10 ( V_28 ) )
V_34 =
V_27 [ F_15 ( V_28 ) ] ;
}
V_37 = F_3 ( & V_27 [ V_46 ] ) ;
V_38 = F_3 ( & V_27 [ V_47 ] ) ;
F_16 ( V_30 , V_48 ,
V_36 * V_49 ) ;
F_16 ( V_30 , V_50 ,
V_35 * V_49 ) ;
F_16 ( V_30 , V_51 , V_34 ) ;
F_16 ( V_30 , V_52 , V_37 ) ;
F_16 ( V_30 , V_53 , V_38 ) ;
}
return 0 ;
}
static void F_17 ( struct V_25 * V_26 )
{
const T_1 * V_54 ;
unsigned int V_55 = 0 ;
unsigned int V_4 ;
unsigned int V_56 ;
unsigned int V_5 ;
int error ;
T_1 V_11 ;
do {
error = F_1 ( V_26 -> V_2 , V_26 -> V_57 ,
& V_4 , & V_5 ) ;
if ( error )
break;
if ( V_55 == 0 ) {
V_55 = V_4 ;
} else if ( V_4 != 0 ) {
F_4 ( & V_26 -> V_2 -> V_15 ,
L_5 ,
V_16 , V_4 ) ;
break;
}
V_11 = V_26 -> V_57 [ V_19 ] ;
V_54 = & V_26 -> V_57 [ V_58 ] ;
V_56 = 0 ;
while ( V_55 > 0 ) {
error = F_11 ( V_26 , V_54 , V_11 ) ;
if ( error )
break;
V_54 += V_5 ;
V_55 -- ;
V_56 ++ ;
if ( V_11 != V_21 &&
V_56 >= 5 ) {
break;
}
}
} while ( V_55 > 0 );
F_18 ( V_26 -> V_30 ) ;
F_19 ( V_26 -> V_30 ) ;
}
static T_3 F_20 ( int V_59 , void * V_60 )
{
struct V_25 * V_26 = V_60 ;
do {
F_17 ( V_26 ) ;
} while ( V_26 -> V_61 && F_21 ( V_26 -> V_61 ) );
return V_62 ;
}
static void F_22 ( struct V_25 * V_26 )
{
if ( V_26 -> V_63 ) {
F_23 ( 1000 , 2000 ) ;
F_24 ( V_26 -> V_63 , 1 ) ;
F_23 ( 1000 , 2000 ) ;
F_24 ( V_26 -> V_63 , 0 ) ;
F_25 ( 100 ) ;
}
}
static int F_26 ( struct V_1 * V_2 ,
const struct V_64 * V_28 )
{
struct V_25 * V_26 ;
struct V_29 * V_30 ;
int error ;
V_26 = F_27 ( & V_2 -> V_15 , sizeof( * V_26 ) , V_65 ) ;
if ( ! V_26 )
return - V_66 ;
V_26 -> V_2 = V_2 ;
V_26 -> V_61 = F_28 ( & V_2 -> V_15 ,
L_6 , V_67 ) ;
if ( F_29 ( V_26 -> V_61 ) ) {
error = F_30 ( V_26 -> V_61 ) ;
if ( error != - V_68 )
F_4 ( & V_2 -> V_15 ,
L_7 , error ) ;
return error ;
}
V_26 -> V_63 = F_28 ( & V_2 -> V_15 ,
L_8 , V_69 ) ;
if ( F_29 ( V_26 -> V_63 ) ) {
error = F_30 ( V_26 -> V_63 ) ;
if ( error != - V_68 )
F_4 ( & V_2 -> V_15 ,
L_9 , error ) ;
return error ;
}
F_22 ( V_26 ) ;
V_26 -> V_30 = V_30 = F_31 ( & V_2 -> V_15 ) ;
if ( ! V_30 ) {
F_4 ( & V_2 -> V_15 , L_10 ) ;
return - V_66 ;
}
V_30 -> V_70 = L_11 ;
V_30 -> V_28 . V_71 = V_72 ;
F_32 ( V_30 , V_52 , 0 , V_73 , 0 , 0 ) ;
F_32 ( V_30 , V_53 , 0 , V_74 , 0 , 0 ) ;
F_32 ( V_30 , V_51 , 0 , V_75 , 0 , 0 ) ;
F_32 ( V_30 , V_48 ,
0 , V_76 , 0 , 0 ) ;
F_32 ( V_30 , V_50 ,
0 , V_77 , 0 , 0 ) ;
error = F_33 ( V_30 , V_78 , V_79 ) ;
if ( error ) {
F_4 ( & V_2 -> V_15 ,
L_12 , error ) ;
return error ;
}
error = F_34 ( & V_2 -> V_15 , V_2 -> V_59 ,
NULL , F_20 ,
V_80 ,
V_2 -> V_70 , V_26 ) ;
if ( error ) {
F_4 ( & V_2 -> V_15 , L_13 , error ) ;
return error ;
}
error = F_35 ( V_26 -> V_30 ) ;
if ( error ) {
F_4 ( & V_2 -> V_15 ,
L_14 , error ) ;
return error ;
}
return 0 ;
}
