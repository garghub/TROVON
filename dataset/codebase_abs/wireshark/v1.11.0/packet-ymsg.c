static int F_1 ( T_1 * V_1 , int V_2 )
{
int V_3 = V_2 ;
while ( F_2 ( V_1 , V_2 ) >= 2 ) {
if ( F_3 ( V_1 , V_2 ) == 0xc080 ) {
break;
}
V_2 += 1 ;
}
return V_2 - V_3 ;
}
static T_2
F_4 ( T_1 * V_1 , T_3 * V_4 , T_4 * V_5 , void * T_5 V_6 )
{
if ( F_5 ( V_1 ) < 4 ) {
return FALSE ;
}
if ( F_6 ( V_1 , 0 , L_1 , 4 ) == - 1 ) {
return FALSE ;
}
F_7 ( V_1 , V_4 , V_5 , V_7 , 10 , V_8 ,
V_9 ) ;
return TRUE ;
}
static T_6
V_8 ( T_3 * V_4 V_6 , T_1 * V_1 , int V_2 )
{
T_6 V_10 ;
V_10 = F_3 ( V_1 , V_2 + 8 ) ;
return V_10 + V_11 ;
}
static void
V_9 ( T_1 * V_1 , T_3 * V_4 , T_4 * V_5 )
{
T_4 * V_12 , * V_13 ;
T_7 * V_14 ;
T_4 * V_15 ;
char * V_16 ;
char * V_17 ;
int V_18 ;
int V_19 ;
int V_20 ;
int V_2 = 0 ;
F_8 ( V_4 -> V_21 , V_22 , L_1 ) ;
F_9 ( V_4 -> V_21 , V_23 ,
L_2 ,
F_10 ( F_3 ( V_1 , V_2 + 10 ) ,
V_24 , L_3 ) ,
F_10 ( F_11 ( V_1 , V_2 + 12 ) ,
V_25 , L_4 )
) ;
if ( V_5 ) {
V_13 = F_12 ( V_5 , V_26 , V_1 , V_2 , - 1 , V_27 ) ;
V_12 = F_13 ( V_13 , V_28 ) ;
V_2 += 4 ;
F_12 ( V_12 , V_29 , V_1 , V_2 , 2 , V_30 ) ;
V_2 += 2 ;
F_12 ( V_12 , V_31 , V_1 , V_2 , 2 , V_30 ) ;
V_2 += 2 ;
V_20 = F_3 ( V_1 , V_2 ) ;
F_12 ( V_12 , V_32 , V_1 , V_2 , 2 , V_30 ) ;
V_2 += 2 ;
F_14 ( V_13 , L_5 ,
F_15 ( F_3 ( V_1 , V_2 ) ,
V_24 ,
L_6 ) ) ;
F_12 ( V_12 , V_33 , V_1 , V_2 , 2 , V_30 ) ;
V_2 += 2 ;
F_12 ( V_12 , V_34 , V_1 , V_2 , 4 , V_30 ) ;
V_2 += 4 ;
F_12 ( V_12 , V_35 , V_1 , V_2 , 4 , V_36 ) ;
V_2 += 4 ;
if ( V_20 ) {
V_14 = F_12 ( V_12 , V_37 , V_1 ,
V_2 , - 1 , V_38 | V_27 ) ;
V_15 = F_13 ( V_14 , V_39 ) ;
for (; ; )
{
T_7 * V_40 ;
T_4 * V_41 ;
if ( V_2 >= ( V_11 + V_20 - 4 ) )
{
break;
}
V_18 = F_1 ( V_1 , V_2 ) ;
V_16 = F_16 ( V_1 , V_2 , V_18 ) ;
V_19 = F_1 ( V_1 , V_2 + V_18 + 2 ) ;
V_17 = F_16 ( V_1 , V_2 + V_18 + 2 , V_19 ) ;
V_40 = F_17 ( V_15 , V_42 , V_1 ,
V_2 , V_18 + 2 + V_19 + 2 ,
L_7 , L_8 , V_16 , V_17 ) ;
V_41 = F_13 ( V_40 , V_43 ) ;
F_12 ( V_41 , V_44 , V_1 ,
V_2 , V_18 , V_38 | V_27 ) ;
F_12 ( V_41 , V_45 , V_1 ,
V_2 + V_18 + 2 , V_19 , V_38 | V_27 ) ;
V_2 += V_18 + 2 + V_19 + 2 ;
}
}
}
F_18 ( V_4 -> V_21 , V_23 ) ;
return;
}
void
F_19 ( void )
{
static T_8 V_46 [] = {
{ & V_29 , {
L_9 , L_10 , V_47 , V_48 ,
NULL , 0 , L_11 , V_49 } } ,
{ & V_31 , {
L_12 , L_13 , V_47 , V_48 ,
NULL , 0 , L_14 , V_49 } } ,
{ & V_32 , {
L_15 , L_16 , V_47 , V_48 ,
NULL , 0 , NULL , V_49 } } ,
{ & V_33 , {
L_17 , L_18 , V_47 , V_48 ,
F_20 ( V_24 ) , 0 , L_19 , V_49 } } ,
{ & V_34 , {
L_20 , L_21 , V_50 , V_48 ,
F_20 ( V_25 ) , 0 , L_22 , V_49 } } ,
{ & V_35 , {
L_23 , L_24 , V_50 , V_51 ,
NULL , 0 , L_25 , V_49 } } ,
{ & V_37 , {
L_26 , L_27 , V_52 , V_53 ,
NULL , 0 , L_28 , V_49 } } ,
{ & V_42 , {
L_29 , L_30 , V_52 , V_53 ,
NULL , 0 , L_28 , V_49 } } ,
{ & V_44 , {
L_31 , L_32 , V_52 , V_53 ,
NULL , 0 , L_33 , V_49 } } ,
{ & V_45 , {
L_34 , L_35 , V_52 , V_53 ,
NULL , 0 , L_36 , V_49 } }
} ;
static T_9 * V_54 [] = {
& V_28 ,
& V_39 ,
& V_43
} ;
T_10 * V_55 ;
V_26 = F_21 ( L_37 ,
L_1 , L_38 ) ;
F_22 ( V_26 , V_46 , F_23 ( V_46 ) ) ;
F_24 ( V_54 , F_23 ( V_54 ) ) ;
V_55 = F_25 ( V_26 , NULL ) ;
F_26 ( V_55 , L_39 ,
L_40 ,
L_41
L_42
L_43 ,
& V_7 ) ;
}
void
F_27 ( void )
{
F_28 ( L_44 , F_4 , V_26 ) ;
}
