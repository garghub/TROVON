T_1
F_1 ( T_1 V_1 )
{
return F_2 (
V_2 +
( V_1 * sizeof( T_1 ) ) ) ;
}
static void
F_3 ( T_1 V_1 , T_1 V_3 )
{
F_4 ( ( V_2 +
( V_1 * sizeof( T_1 ) ) ) ,
V_3 ) ;
}
void F_5 ( T_2 V_4 )
{
F_3 ( V_5 , 1 ) ;
F_3 ( F_6 ( V_4 ) , 1 ) ;
F_3 ( F_7 ( V_4 ) , V_6 ) ;
F_3 ( F_8 ( V_4 ) , V_7 ) ;
F_3 ( V_8 , 0xFF ) ;
}
T_1
F_9 ( T_2 V_4 )
{
return F_1 ( F_10 ( V_4 ) ) ;
}
