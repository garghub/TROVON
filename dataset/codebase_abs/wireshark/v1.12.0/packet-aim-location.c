static int F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
return F_2 ( V_1 , V_2 , 0 , V_3 , V_4 ) ;
}
static int F_3 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
return F_2 ( V_1 , V_2 , 0 , V_3 , V_5 ) ;
}
static int F_4 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
int V_6 = 0 ;
while ( F_5 ( V_1 , V_6 ) > 0 ) {
V_6 = F_6 ( V_1 , V_2 , V_6 , V_3 ) ;
}
return V_6 ;
}
static int F_7 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
return F_6 ( V_1 , V_2 , 4 , V_3 ) ;
}
static int F_8 ( T_1 * V_1 , T_2 * V_2 V_7 , T_3 * V_8 )
{
int V_6 = 0 ;
T_4 V_9 = 0 ;
F_9 ( V_8 , V_10 ,
V_1 , V_6 , 2 , V_11 ) ;
V_6 += 2 ;
V_9 = F_10 ( V_1 , V_6 ) ;
F_9 ( V_8 , V_12 , V_1 , V_6 , 1 , V_11 ) ;
V_6 += 1 ;
F_9 ( V_8 , V_13 , V_1 , V_6 , V_9 , V_14 | V_15 ) ;
V_6 += V_9 ;
return V_6 ;
}
static int F_11 ( T_1 * V_1 , T_2 * V_2 V_7 , T_3 * V_8 )
{
int V_6 = 0 ;
T_4 V_9 = 0 ;
V_9 = F_10 ( V_1 , V_6 ) ;
F_9 ( V_8 , V_12 , V_1 , V_6 , 1 , V_11 ) ;
V_6 += 1 ;
F_9 ( V_8 , V_13 , V_1 , V_6 , V_9 , V_14 | V_15 ) ;
V_6 += V_9 ;
F_9 ( V_8 , V_16 , V_1 , V_6 , 2 , V_11 ) ;
V_6 += 2 ;
V_6 = F_12 ( V_1 , V_2 , V_6 , V_8 , V_17 ) ;
return F_2 ( V_1 , V_2 , V_6 , V_8 , V_5 ) ;
}
void
F_13 ( void )
{
static T_5 V_18 [] = {
{ & V_12 ,
{ L_1 , L_2 , V_19 , V_20 , NULL , 0x0 , NULL , V_21 }
} ,
{ & V_13 ,
{ L_3 , L_4 , V_22 , V_23 , NULL , 0x0 , NULL , V_21 }
} ,
{ & V_16 ,
{ L_5 , L_6 , V_24 , V_20 , NULL , 0x0 , NULL , V_21 } ,
} ,
{ & V_10 ,
{ L_7 , L_8 , V_24 , V_25 , F_14 ( V_26 ) , 0x0 ,
NULL , V_21 }
} ,
} ;
static T_6 * V_27 [] = {
& V_28 ,
} ;
V_29 = F_15 ( L_9 , L_9 , L_10 ) ;
F_16 ( V_29 , V_18 , F_17 ( V_18 ) ) ;
F_18 ( V_27 , F_17 ( V_27 ) ) ;
}
void
F_19 ( void )
{
F_20 ( V_29 , V_28 , V_30 , V_31 ) ;
}
