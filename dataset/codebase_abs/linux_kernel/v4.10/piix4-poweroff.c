static void F_1 ( void )
{
int V_1 ;
T_1 V_2 ;
while ( 1 ) {
V_2 = F_2 ( V_3 + V_4 ) ;
if ( ! ( V_2 & V_5 ) )
break;
F_3 ( V_2 , V_3 + V_4 ) ;
}
F_3 ( V_6 | V_7 ,
V_3 + V_8 ) ;
F_4 ( 10 ) ;
V_1 = F_5 ( 0 , F_6 ( 0x1f , 0x7 ) ) ;
F_7 ( V_9 -> V_10 , V_1 , 0 ,
V_11 ) ;
F_4 ( 1000 ) ;
F_8 ( L_1 ) ;
}
static int F_9 ( struct V_12 * V_13 ,
const struct V_14 * V_15 )
{
int V_16 ;
if ( V_9 )
return - V_17 ;
V_16 = F_10 ( V_13 , V_18 ,
L_2 ) ;
if ( V_16 ) {
F_11 ( & V_13 -> V_13 , L_3 ,
V_16 ) ;
return V_16 ;
}
V_9 = V_13 ;
V_3 = F_12 ( V_13 , V_18 ) ;
V_19 = F_1 ;
return 0 ;
}
static void F_13 ( struct V_12 * V_13 )
{
if ( V_19 == F_1 )
V_19 = NULL ;
F_14 ( V_13 , V_18 ) ;
V_9 = NULL ;
}
