static int F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
int V_4 = 0 ;
while ( F_2 ( V_1 , V_4 ) > 0 ) {
V_4 = F_3 ( V_1 , V_2 , V_4 , V_3 ) ;
}
return V_4 ;
}
static int F_4 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
return F_5 ( V_1 , V_2 , 0 , V_3 , V_5 ) ;
}
static int F_6 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
return F_3 ( V_1 , V_2 , 0 , V_3 ) ;
}
static int F_7 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_4 * V_6 ;
int V_4 = 0 ;
int V_7 = F_8 ( & V_6 , V_1 , V_4 ) ;
F_9 ( V_2 -> V_8 , V_9 , L_1 ) ;
F_10 ( V_2 -> V_8 , V_9 , L_2 ,
F_11 ( V_6 , V_7 ) ) ;
V_4 += F_3 ( V_1 , V_2 , V_4 , V_3 ) ;
F_12 ( V_3 , V_10 , V_1 , V_4 ,
2 , V_11 ) ;
V_4 += 2 ;
V_4 = F_13 ( V_1 , V_2 , V_4 , V_3 , V_12 ) ;
return V_4 ;
}
static int F_14 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_4 * V_6 ;
int V_4 = 0 ;
int V_7 = F_8 ( & V_6 , V_1 , V_4 ) ;
F_9 ( V_2 -> V_8 , V_9 , L_3 ) ;
F_10 ( V_2 -> V_8 , V_9 , L_2 ,
F_11 ( V_6 , V_7 ) ) ;
V_4 += F_3 ( V_1 , V_2 , V_4 , V_3 ) ;
F_12 ( V_3 , V_10 , V_1 , V_4 ,
2 , V_11 ) ;
V_4 += 2 ;
return F_13 ( V_1 , V_2 , V_4 , V_3 , V_12 ) ;
}
void
F_15 ( void )
{
static T_5 V_13 [] = {
{ & V_10 ,
{ L_4 , L_5 , V_14 , V_15 , NULL , 0x0 , NULL , V_16 } ,
} ,
} ;
static T_6 * V_17 [] = {
& V_18 ,
} ;
V_19 = F_16 ( L_6 , L_7 , L_8 ) ;
F_17 ( V_19 , V_13 , F_18 ( V_13 ) ) ;
F_19 ( V_17 , F_18 ( V_17 ) ) ;
}
void
F_20 ( void )
{
F_21 ( V_19 , V_18 , V_20 , V_21 ) ;
}
