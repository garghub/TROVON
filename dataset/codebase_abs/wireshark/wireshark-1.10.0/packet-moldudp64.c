T_1
F_1 ( T_2 * V_1 , T_3 * V_2 , T_4 * V_3 ,
T_1 V_4 , T_5 V_5 )
{
T_6 * V_6 ;
T_4 * V_7 ;
T_7 V_8 , V_9 , V_10 ;
T_1 V_11 ;
if ( F_2 ( V_1 , V_4 ) < V_12 )
return 0 ;
V_8 = F_3 ( V_1 , V_4 ) ;
V_11 = F_4 ( V_1 ) - V_4 - V_12 ;
if ( V_11 < ( V_4 + V_12 ) )
V_9 = 0 ;
else if ( V_8 <= V_11 )
V_9 = V_8 ;
else
V_9 = V_11 ;
V_10 = V_9 + V_12 ;
V_6 = F_5 ( V_3 , V_13 ,
V_1 , V_4 , V_10 , V_14 ) ;
V_7 = F_6 ( V_6 , V_15 ) ;
V_6 = F_7 ( V_7 , V_16 ,
V_1 , V_4 , 0 , V_5 ) ;
F_8 ( V_6 ) ;
V_6 = F_5 ( V_7 , V_17 ,
V_1 , V_4 , V_12 , V_18 ) ;
if ( V_8 != V_9 )
F_9 ( V_2 , V_6 , V_19 , V_20 ,
L_1 ,
V_8 , V_9 ) ;
V_4 += V_12 ;
F_5 ( V_7 , V_21 ,
V_1 , V_4 , V_9 , V_14 ) ;
return V_10 ;
}
static int
F_10 ( T_2 * V_1 , T_3 * V_2 , T_4 * V_3 , void * T_8 V_22 )
{
T_6 * V_6 ;
T_4 * V_23 ;
T_1 V_4 = 0 ;
T_7 V_24 , V_25 = 0 ;
T_5 V_5 ;
if ( F_4 ( V_1 ) < ( V_26 +
V_27 +
V_28 ) )
return 0 ;
F_11 ( V_2 -> V_29 , V_30 , L_2 ) ;
F_12 ( V_2 -> V_29 , V_31 ) ;
V_5 = F_13 ( V_1 , V_26 ) ;
V_24 = F_3 ( V_1 , V_26 + V_27 ) ;
if ( V_24 == V_32 )
F_11 ( V_2 -> V_29 , V_31 , L_3 ) ;
else if ( V_24 == V_33 )
F_11 ( V_2 -> V_29 , V_31 , L_4 ) ;
else
F_11 ( V_2 -> V_29 , V_31 , L_5 ) ;
V_6 = F_5 ( V_3 , V_34 ,
V_1 , V_4 , - 1 , V_14 ) ;
V_23 = F_6 ( V_6 , V_35 ) ;
F_5 ( V_23 , V_36 ,
V_1 , V_4 , V_26 , V_37 | V_14 ) ;
V_4 += V_26 ;
F_5 ( V_23 , V_38 ,
V_1 , V_4 , V_27 , V_18 ) ;
V_4 += V_27 ;
V_6 = F_5 ( V_23 , V_39 ,
V_1 , V_4 , V_28 , V_18 ) ;
V_4 += V_28 ;
while ( F_4 ( V_1 ) >= V_4 + V_12 )
{
V_4 += F_1 ( V_1 , V_2 , V_23 ,
V_4 , V_5 ++ ) ;
V_25 ++ ;
}
if ( V_24 == V_33 )
{
if ( V_25 != 0 )
{
F_9 ( V_2 , V_6 , V_19 , V_20 ,
L_6 ) ;
}
}
else if ( V_25 != V_24 )
{
F_9 ( V_2 , V_6 , V_19 , V_20 ,
L_7 ,
V_24 , V_25 ) ;
}
return F_14 ( V_1 ) ;
}
void
F_15 ( void )
{
T_9 * V_40 ;
static T_10 V_41 [] = {
{ & V_36 ,
{ L_8 , L_9 , V_42 , V_43 , NULL , 0 ,
L_10 , V_44 } } ,
{ & V_38 ,
{ L_11 , L_12 , V_45 , V_46 , NULL , 0 ,
L_13 , V_44 } } ,
{ & V_39 ,
{ L_14 , L_15 , V_47 , V_46 , NULL , 0 ,
L_16 , V_44 } } ,
{ & V_13 ,
{ L_17 , L_18 , V_48 , V_43 , NULL , 0 ,
L_19 , V_44 } } ,
{ & V_17 ,
{ L_20 , L_21 , V_47 , V_46 , NULL , 0 ,
L_22 , V_44 } } ,
{ & V_16 ,
{ L_11 , L_23 , V_45 , V_46 , NULL , 0 ,
L_24 , V_44 } } ,
{ & V_21 ,
{ L_25 , L_26 , V_49 , V_43 , NULL , 0 ,
L_27 , V_44 } }
} ;
static T_11 * V_50 [] = {
& V_35 ,
& V_15
} ;
V_34 = F_16 ( L_2 ,
L_2 , L_28 ) ;
F_17 ( V_34 , V_41 , F_18 ( V_41 ) ) ;
F_19 ( V_50 , F_18 ( V_50 ) ) ;
V_40 = F_20 ( V_34 ,
V_51 ) ;
F_21 ( V_40 , L_29 , L_30 ,
L_31 ,
10 , & V_52 ) ;
}
void
V_51 ( void )
{
static T_12 V_53 = FALSE ;
static T_13 V_54 ;
static int V_55 ;
if ( ! V_53 ) {
V_54 = F_22 ( F_10 ,
V_34 ) ;
V_53 = TRUE ;
} else {
F_23 ( L_29 , V_55 , V_54 ) ;
}
V_55 = V_52 ;
F_24 ( L_29 , V_55 , V_54 ) ;
}
