static int F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
int V_4 = 0 ;
while( F_2 ( V_1 , V_4 ) > 0 ) {
V_4 = F_3 ( V_1 , V_2 , V_4 , V_3 ) ;
}
return V_4 ;
}
static int F_4 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 V_5 )
{
T_4 * V_6 ;
T_5 * V_7 ;
int V_8 ;
V_7 = ( T_5 * ) F_5 ( F_6 () , 1000 ) ;
V_8 = F_7 ( & V_6 , V_1 , 30 ) ;
F_8 ( V_7 , V_1 , 40 + V_8 , F_9 ( V_1 )
- 40 - V_8 ) ;
F_10 ( V_2 -> V_9 , V_10 , L_1 , V_7 ) ;
return F_9 ( V_1 ) ;
}
static int F_11 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_4 * V_6 ;
T_5 * V_7 ;
int V_8 ;
V_7 = ( T_5 * ) F_5 ( F_6 () , 1000 ) ;
V_8 = F_7 ( & V_6 , V_1 , 30 ) ;
F_8 ( V_7 , V_1 , 36 + V_8 , F_9 ( V_1 )
- 36 - V_8 ) ;
F_10 ( V_2 -> V_9 , V_10 , L_2 , V_6 ) ;
F_10 ( V_2 -> V_9 , V_10 , L_1 , V_7 ) ;
F_12 ( V_3 , V_11 , V_1 , 31 , V_8 , V_6 ) ;
return F_9 ( V_1 ) ;
}
void
F_13 ( void )
{
static T_6 V_12 [] = {
{ & V_11 ,
{ L_3 , L_4 , V_13 , V_14 , NULL , 0x0 , NULL , V_15 } ,
} ,
} ;
static T_7 * V_16 [] = {
& V_17 ,
} ;
V_18 = F_14 ( L_5 , L_6 , L_7 ) ;
F_15 ( V_18 , V_12 , F_16 ( V_12 ) ) ;
F_17 ( V_16 , F_16 ( V_16 ) ) ;
}
void
F_18 ( void )
{
F_19 ( V_18 , V_17 , V_19 , V_20 ) ;
}
