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
else if ( F_4 ( V_4 ) == 6 && V_9 )
return V_9 ;
else if ( V_4 == 0xff && V_5 == 0x03 && F_5 ( V_6 ) == 0 && V_7 == 0x21 && V_10 )
return V_10 ;
else if ( V_4 == 0xff && V_5 == 0x03 && V_6 == 0 && V_7 == 0x57 && V_10 )
return V_10 ;
else
return NULL ;
}
static int
F_6 ( T_2 * V_1 , T_3 * V_11 , T_4 * V_12 , void * T_5 V_13 )
{
int V_2 = 0 ;
T_1 V_14 ;
unsigned int V_15 , V_16 ;
T_6 * V_17 = NULL ;
T_4 * V_18 = NULL ;
T_2 * V_19 = NULL ;
if ( ! ( V_14 = F_1 ( V_1 ) ) )
return 0 ;
F_7 ( V_11 -> V_20 , V_21 , L_1 ) ;
V_15 = F_8 ( V_1 , V_2 ) ;
V_16 = F_8 ( V_1 , V_2 + V_22 ) ;
F_9 ( V_11 -> V_20 , V_23 , L_2 , V_15 , V_15 , V_16 , V_16 ) ;
V_17 = F_10 ( V_12 , V_24 , V_1 , V_2 , V_3 ,
L_3 , V_15 , V_15 , V_16 , V_16 ) ;
V_18 = F_11 ( V_17 , V_25 ) ;
F_12 ( V_18 , V_26 , V_1 , V_2 , V_22 , V_27 ) ;
V_2 += V_22 ;
F_12 ( V_18 , V_28 , V_1 , V_2 , V_29 , V_27 ) ;
V_2 += V_29 ;
V_19 = F_13 ( V_1 , V_2 ) ;
return V_3 + F_14 ( V_14 , V_19 , V_11 , V_12 ) ;
}
void
F_15 ( void )
{
T_7 * V_30 = NULL ;
static T_8 V_31 [] = {
{ & V_26 ,
{ L_4 , L_5 , V_32 , V_33 , NULL , 0x0 ,
L_6 , V_34 }
} ,
{ & V_28 ,
{ L_7 , L_8 , V_32 , V_33 , NULL , 0x0 ,
L_9 , V_34 }
}
} ;
static T_9 * V_35 [] = {
& V_25
} ;
V_24 = F_16 ( L_10 , L_1 , L_11 ) ;
V_30 = F_17 ( V_24 , V_36 ) ;
F_18 ( V_30 , L_12 , L_13 ,
L_14 ,
10 , & V_37 ) ;
F_19 ( V_24 , V_31 , F_20 ( V_31 ) ) ;
F_21 ( V_35 , F_20 ( V_35 ) ) ;
}
void
V_36 ( void )
{
static int V_38 = FALSE ;
static T_10 V_39 ;
static T_1 V_40 ;
if ( ! V_38 )
{
V_40 = F_22 ( F_6 , V_24 ) ;
V_8 = F_23 ( L_15 ) ;
V_9 = F_23 ( L_16 ) ;
V_10 = F_23 ( L_17 ) ;
V_38 = TRUE ;
} else {
F_24 ( L_12 , V_39 , V_40 ) ;
}
V_39 = V_37 ;
F_25 ( L_12 , V_39 , V_40 ) ;
}
