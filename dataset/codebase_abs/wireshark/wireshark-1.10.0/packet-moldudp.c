T_1
F_1 ( T_2 * V_1 , T_3 * V_2 , T_4 * V_3 ,
T_1 V_4 , T_5 V_5 )
{
T_6 * V_6 ;
T_4 * V_7 ;
T_7 V_8 , V_9 , V_10 ;
T_1 V_11 ;
if ( F_2 ( V_1 ) - V_4 < V_12 )
return 0 ;
V_8 = F_3 ( V_1 , V_4 ) ;
V_11 = F_2 ( V_1 ) - V_4 - V_12 ;
if ( V_8 == 0 )
F_4 ( V_2 -> V_13 , V_14 , L_1 ) ;
if ( F_2 ( V_1 ) < ( V_4 + V_12 ) )
V_9 = 0 ;
else if ( V_8 <= V_11 )
V_9 = V_8 ;
else
V_9 = V_11 ;
V_10 = V_9 + V_12 ;
V_6 = F_5 ( V_3 , V_15 ,
V_1 , V_4 , V_10 , V_16 ) ;
V_7 = F_6 ( V_6 , V_17 ) ;
V_6 = F_7 ( V_7 , V_18 ,
V_1 , V_4 , 0 , V_5 ) ;
F_8 ( V_6 ) ;
V_6 = F_5 ( V_7 , V_19 ,
V_1 , V_4 , V_12 , V_20 ) ;
if ( V_8 != V_9 )
F_9 ( V_2 , V_6 , V_21 , V_22 ,
L_2 ,
V_8 , V_9 ) ;
V_4 += V_12 ;
F_5 ( V_7 , V_23 ,
V_1 , V_4 , V_9 , V_16 ) ;
return V_10 ;
}
static int
F_10 ( T_2 * V_1 , T_3 * V_2 , T_4 * V_3 , void * T_8 V_24 )
{
T_6 * V_6 ;
T_4 * V_25 ;
T_1 V_4 = 0 ;
T_7 V_26 , V_27 = 0 ;
T_5 V_5 ;
if ( F_2 ( V_1 ) < ( V_28 +
V_29 +
V_30 ) )
return 0 ;
F_4 ( V_2 -> V_13 , V_31 , L_3 ) ;
F_11 ( V_2 -> V_13 , V_14 ) ;
V_26 = F_3 ( V_1 , V_28 + V_29 ) ;
if ( V_26 == V_32 )
F_4 ( V_2 -> V_13 , V_14 , L_4 ) ;
else
F_4 ( V_2 -> V_13 , V_14 , L_5 ) ;
V_6 = F_5 ( V_3 , V_33 ,
V_1 , V_4 , - 1 , V_16 ) ;
V_25 = F_6 ( V_6 , V_34 ) ;
F_5 ( V_25 , V_35 ,
V_1 , V_4 , V_28 , V_36 | V_16 ) ;
V_4 += V_28 ;
V_5 = F_12 ( V_1 , V_4 ) ;
F_5 ( V_25 , V_37 ,
V_1 , V_4 , V_29 , V_20 ) ;
V_4 += V_29 ;
V_6 = F_5 ( V_25 , V_38 ,
V_1 , V_4 , V_30 , V_20 ) ;
V_4 += V_30 ;
while ( F_2 ( V_1 ) >= V_4 + V_12 )
{
V_4 += F_1 ( V_1 , V_2 , V_25 ,
V_4 , V_5 ++ ) ;
V_27 ++ ;
}
if ( V_27 != V_26 )
{
F_9 ( V_2 , V_6 , V_21 , V_22 ,
L_6 ,
V_26 , V_27 ) ;
}
return F_13 ( V_1 ) ;
}
void
F_14 ( void )
{
T_9 * V_39 ;
static T_10 V_40 [] = {
{ & V_35 ,
{ L_7 , L_8 , V_41 , V_42 , NULL , 0 ,
L_9 , V_43 } } ,
{ & V_37 ,
{ L_10 , L_11 , V_44 , V_45 , NULL , 0 ,
L_12 , V_43 } } ,
{ & V_38 ,
{ L_13 , L_14 , V_46 , V_45 , NULL , 0 ,
L_15 , V_43 } } ,
{ & V_15 ,
{ L_16 , L_17 , V_47 , V_42 , NULL , 0 ,
L_18 , V_43 } } ,
{ & V_19 ,
{ L_19 , L_20 , V_46 , V_45 , NULL , 0 ,
L_21 , V_43 } } ,
{ & V_18 ,
{ L_10 , L_22 , V_44 , V_45 , NULL , 0 ,
L_23 , V_43 } } ,
{ & V_23 ,
{ L_24 , L_25 , V_48 , V_42 , NULL , 0 ,
L_26 , V_43 } }
} ;
static T_11 * V_49 [] = {
& V_34 ,
& V_17
} ;
V_33 = F_15 ( L_3 ,
L_3 , L_27 ) ;
F_16 ( V_33 , V_40 , F_17 ( V_40 ) ) ;
F_18 ( V_49 , F_17 ( V_49 ) ) ;
V_39 = F_19 ( V_33 ,
V_50 ) ;
F_20 ( V_39 , L_28 , L_29 ,
L_30 ,
10 , & V_51 ) ;
}
void
V_50 ( void )
{
static T_12 V_52 = FALSE ;
static T_13 V_53 ;
static int V_54 ;
if ( ! V_52 ) {
V_53 = F_21 ( F_10 ,
V_33 ) ;
V_52 = TRUE ;
} else {
F_22 ( L_28 , V_54 , V_53 ) ;
}
V_54 = V_51 ;
F_23 ( L_28 , V_54 , V_53 ) ;
}
