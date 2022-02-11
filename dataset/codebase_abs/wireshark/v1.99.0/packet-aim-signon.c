static int F_1 ( T_1 * V_1 , T_2 * V_2 ,
T_3 * V_3 )
{
int V_4 = 0 ;
while ( F_2 ( V_1 , V_4 ) > 0 ) {
V_4 = F_3 ( V_1 , V_2 , V_4 , V_3 , V_5 ) ;
}
return V_4 ;
}
static int F_4 ( T_1 * V_1 ,
T_2 * V_2 ,
T_3 * V_3 )
{
int V_4 = 0 ;
while ( F_2 ( V_1 , V_4 ) > 0 ) {
V_4 = F_3 ( V_1 , V_2 , V_4 , V_3 , V_5 ) ;
}
return V_4 ;
}
static int F_5 ( T_1 * V_1 , T_2 * V_2 ,
T_3 * V_3 )
{
T_4 V_6 = 0 ;
int V_4 = 0 ;
T_4 * V_7 ;
F_6 ( V_3 , V_8 , V_1 , V_4 , 2 , V_9 ) ;
V_4 += 2 ;
V_4 += 1 ;
V_6 = F_7 ( & V_7 , V_1 , V_4 ) ;
F_8 ( V_2 -> V_10 , V_11 , L_1 ,
F_9 ( V_7 , V_6 ) ) ;
if( V_3 ) {
V_4 += F_10 ( V_1 , V_2 , V_4 , V_3 ) ;
}
return V_4 ;
}
static int F_11 ( T_1 * V_1 ,
T_2 * V_2 V_12 ,
T_3 * V_3 )
{
int V_4 = 0 ;
T_5 V_13 = 0 ;
V_13 = F_12 ( V_1 , V_4 ) ;
F_6 ( V_3 , V_14 , V_1 , V_4 , 2 , V_9 ) ;
V_4 += 2 ;
F_6 ( V_3 , V_15 , V_1 , V_4 , V_13 , V_16 | V_17 ) ;
V_4 += V_13 ;
return V_4 ;
}
static int F_13 ( T_6 * T_7 V_12 , T_5 T_8 V_12 , T_1 * V_1 V_12 , T_2 * V_2 V_12 )
{
return 0 ;
}
static int F_14 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
return F_3 ( V_1 , V_2 , 0 , V_3 , V_18 ) ;
}
void
F_15 ( void )
{
static T_9 V_19 [] = {
{ & V_8 ,
{ L_2 , L_3 , V_20 , V_21 , NULL , 0x0 , NULL , V_22 }
} ,
{ & V_14 ,
{ L_4 , L_5 , V_20 , V_23 , NULL , 0x0 , NULL , V_22 }
} ,
{ & V_15 ,
{ L_6 , L_7 , V_24 , V_25 , NULL , 0x0 , NULL , V_22 }
} ,
} ;
static T_10 * V_26 [] = {
& V_27 ,
} ;
V_28 = F_16 ( L_8 , L_8 , L_9 ) ;
F_17 ( V_28 , V_19 , F_18 ( V_19 ) ) ;
F_19 ( V_26 , F_18 ( V_26 ) ) ;
}
void
F_20 ( void )
{
F_21 ( V_28 , V_27 , V_29 , V_30 ) ;
}
