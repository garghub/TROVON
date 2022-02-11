static int F_1 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 , bool V_5 )
{
T_2 V_6 [ V_7 ] ;
T_1 V_8 = V_4 < 8 ? V_4 : 8 ;
int V_9 ;
V_9 = F_2 ( V_10 , ( unsigned long * ) V_6 ) ;
if ( V_9 != V_11 ) {
F_3 ( L_1 , V_9 ) ;
return - V_12 ;
}
memcpy ( V_3 , V_6 , V_8 ) ;
return V_8 ;
}
static unsigned long F_4 ( struct V_13 * V_14 )
{
return 0 ;
}
static int F_5 ( struct V_13 * V_15 ,
const struct V_16 * V_17 )
{
return F_6 ( & V_18 ) ;
}
static int F_7 ( struct V_13 * V_15 )
{
F_8 ( & V_18 ) ;
return 0 ;
}
static int T_3 F_9 ( void )
{
F_10 ( L_2 ) ;
return F_11 ( & V_19 ) ;
}
static void T_4 F_12 ( void )
{
F_13 ( & V_19 ) ;
}
