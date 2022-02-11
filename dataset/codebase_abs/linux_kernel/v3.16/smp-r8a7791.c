static void T_1 F_1 ( unsigned int V_1 )
{
void T_2 * V_2 ;
T_3 V_3 ;
F_2 ( V_1 ) ;
V_2 = F_3 ( V_4 , V_5 ) ;
F_4 ( V_2 , V_6 , V_5 ) ;
F_5 ( V_2 ) ;
V_2 = F_3 ( V_7 , 0x63 ) ;
V_3 = ( V_4 >> 8 ) & 0xfffffc00 ;
F_6 ( V_3 , V_2 + V_8 ) ;
F_6 ( V_3 | 0x10 , V_2 + V_8 ) ;
F_6 ( ( F_7 ( V_2 + V_9 ) & ~ 0x0f ) | 0xa5a50000 ,
V_2 + V_9 ) ;
F_5 ( V_2 ) ;
}
static int F_8 ( unsigned int V_10 ,
struct V_11 * V_12 )
{
if ( F_9 () & F_10 ( 21 ) ) {
F_11 ( L_1 , V_10 ) ;
return - V_13 ;
}
return F_12 ( V_10 , V_12 ) ;
}
