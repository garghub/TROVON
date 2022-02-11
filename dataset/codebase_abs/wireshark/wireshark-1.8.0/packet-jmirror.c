static T_1
F_1 ( T_2 * V_1 )
{
int V_2 = V_3 ;
int V_4 , V_5 , V_6 , V_7 ;
if ( ! F_2 ( V_1 , V_2 , 4 ) )
return NULL ;
V_4 = F_3 ( V_1 , V_2 + 0 ) ;
V_5 = F_3 ( V_1 , V_2 + 1 ) ;
V_6 = F_3 ( V_1 , V_2 + 2 ) ;
V_7 = F_3 ( V_1 , V_2 + 3 ) ;
if ( V_4 == 0x45 && V_8 )
return V_8 ;
else if ( F_4 ( V_4 ) == 6 && F_5 ( V_5 ) == 0 && V_6 == 0 && V_7 == 0 && V_9 )
return V_9 ;
else if ( V_4 == 0xff && V_5 == 0x03 && F_5 ( V_6 ) == 0 && V_7 == 0x21 && V_10 )
return V_10 ;
else
return NULL ;
}
static int
F_6 ( T_2 * V_1 , T_3 * V_11 , T_4 * V_12 )
{
int V_2 = 0 ;
T_1 V_13 ;
unsigned int V_14 , V_15 ;
T_5 * V_16 = NULL ;
T_4 * V_17 = NULL ;
T_2 * V_18 = NULL ;
if ( ! ( V_13 = F_1 ( V_1 ) ) )
return 0 ;
F_7 ( V_11 -> V_19 , V_20 , L_1 ) ;
V_14 = F_8 ( V_1 , V_2 ) ;
V_15 = F_8 ( V_1 , V_2 + V_21 ) ;
F_9 ( V_11 -> V_19 , V_22 , L_2 , V_14 , V_14 , V_15 , V_15 ) ;
V_16 = F_10 ( V_12 , V_23 , V_1 , V_2 , V_3 ,
L_3 , V_14 , V_14 , V_15 , V_15 ) ;
V_17 = F_11 ( V_16 , V_24 ) ;
F_12 ( V_17 , V_25 , V_1 , V_2 , V_21 , V_26 ) ;
V_2 += V_21 ;
F_12 ( V_17 , V_27 , V_1 , V_2 , V_28 , V_26 ) ;
V_2 += V_28 ;
V_18 = F_13 ( V_1 , V_2 , - 1 , - 1 ) ;
return V_3 + F_14 ( V_13 , V_18 , V_11 , V_12 ) ;
}
void
F_15 ( void )
{
T_6 * V_29 = NULL ;
static T_7 V_30 [] = {
{ & V_25 ,
{ L_4 , L_5 , V_31 , V_32 , NULL , 0x0 ,
L_6 , V_33 }
} ,
{ & V_27 ,
{ L_7 , L_8 , V_31 , V_32 , NULL , 0x0 ,
L_9 , V_33 }
}
} ;
static T_8 * V_34 [] = {
& V_24
} ;
V_23 = F_16 ( L_10 , L_1 , L_11 ) ;
V_29 = F_17 ( V_23 , V_35 ) ;
F_18 ( V_29 , L_12 , L_13 ,
L_14 ,
10 , & V_36 ) ;
F_19 ( V_23 , V_30 , F_20 ( V_30 ) ) ;
F_21 ( V_34 , F_20 ( V_34 ) ) ;
}
void
V_35 ( void )
{
static int V_37 = FALSE ;
static T_9 V_38 ;
static T_1 V_39 ;
if ( ! V_37 )
{
V_39 = F_22 ( F_6 , V_23 ) ;
V_8 = F_23 ( L_15 ) ;
V_9 = F_23 ( L_16 ) ;
V_10 = F_23 ( L_17 ) ;
V_37 = TRUE ;
} else {
F_24 ( L_12 , V_38 , V_39 ) ;
}
V_38 = V_36 ;
F_25 ( L_12 , V_38 , V_39 ) ;
}
