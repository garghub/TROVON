static int F_1 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 , bool V_5 )
{
T_2 V_6 [ V_7 ] ;
int V_8 ;
V_8 = F_2 ( V_9 , ( unsigned long * ) V_6 ) ;
if ( V_8 != V_10 ) {
F_3 ( L_1 , V_8 ) ;
return - V_11 ;
}
memcpy ( V_3 , V_6 , 8 ) ;
return 8 ;
}
static unsigned long F_4 ( struct V_12 * V_13 )
{
return 0 ;
}
static int F_5 ( struct V_12 * V_14 ,
const struct V_15 * V_16 )
{
return F_6 ( & V_17 ) ;
}
static int F_7 ( struct V_12 * V_14 )
{
F_8 ( & V_17 ) ;
return 0 ;
}
static int T_3 F_9 ( void )
{
F_10 ( L_2 ) ;
return F_11 ( & V_18 ) ;
}
static void T_4 F_12 ( void )
{
F_13 ( & V_18 ) ;
}
