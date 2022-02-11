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
T_4 * V_7 ;
int V_8 ;
V_6 = ( T_4 * ) F_5 ( V_9 + 1 ) ;
V_7 = ( T_4 * ) F_5 ( 1000 ) ;
V_8 = F_6 ( V_6 , V_1 , 30 , 31 ) ;
F_7 ( V_7 , V_1 , 40 + V_8 , F_8 ( V_1 )
- 40 - V_8 ) ;
F_9 ( V_2 -> V_10 , V_11 , L_1 , V_7 ) ;
return F_8 ( V_1 ) ;
}
static int F_10 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_4 * V_6 ;
T_4 * V_7 ;
int V_8 ;
V_6 = ( T_4 * ) F_5 ( V_9 + 1 ) ;
V_7 = ( T_4 * ) F_5 ( 1000 ) ;
V_8 = F_6 ( V_6 , V_1 , 30 , 31 ) ;
F_7 ( V_7 , V_1 , 36 + V_8 , F_8 ( V_1 )
- 36 - V_8 ) ;
F_9 ( V_2 -> V_10 , V_11 , L_2 , V_6 ) ;
F_9 ( V_2 -> V_10 , V_11 , L_1 , V_7 ) ;
if( V_3 ) {
F_11 ( V_3 , V_1 , 31 , V_8 ,
L_3 ,
F_12 ( V_6 , V_8 ) ) ;
}
return F_8 ( V_1 ) ;
}
void
F_13 ( void )
{
#if 0
static hf_register_info hf[] = {
};
#endif
static T_5 * V_12 [] = {
& V_13 ,
} ;
V_14 = F_14 ( L_4 , L_5 , L_6 ) ;
F_15 ( V_12 , F_16 ( V_12 ) ) ;
}
void
F_17 ( void )
{
F_18 ( V_14 , V_13 , V_15 , V_16 ) ;
}
