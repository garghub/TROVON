static T_1 T_2 F_1 ( void )
{
T_1 V_1 ;
V_1 = F_2 ( V_2 ) ;
V_1 |= ( ( T_1 ) ( F_2 ( V_3 ) & 0xff ) << 32 ) ;
return V_1 ;
}
T_3 F_3 ( struct V_4 * V_5 )
{
T_1 V_1 ;
V_1 = F_2 ( V_2 ) ;
V_1 |= ( ( T_1 ) ( F_2 ( V_3 ) & 0xff ) << 32 ) ;
return ( T_3 ) V_1 ;
}
static int F_4 ( unsigned long V_6 ,
struct V_7 * V_8 )
{
T_4 V_9 = V_10 |
V_11 ;
F_5 ( V_9 , V_12 ) ;
F_5 ( V_6 , V_13 ) ;
F_5 ( V_9 | V_14 ,
V_12 ) ;
return 0 ;
}
static int F_6 ( struct V_7 * V_8 )
{
F_5 ( 0 , V_12 ) ;
return 0 ;
}
static T_5 F_7 ( int V_15 , void * V_16 )
{
struct V_7 * V_8 = V_16 ;
F_5 ( 1 , V_17 ) ;
V_8 -> V_18 ( V_8 ) ;
return V_19 ;
}
void T_6 F_8 ( void )
{
F_5 ( V_20 ,
V_3 ) ;
F_9 ( NULL , L_1 ,
V_21 , 200 , 40 ,
F_3 ) ;
F_10 ( F_1 , 40 ,
V_21 ) ;
F_11 ( V_22 , & V_23 ) ;
F_12 ( & V_24 ,
V_25 ,
1 ,
0xffffffffU ) ;
}
