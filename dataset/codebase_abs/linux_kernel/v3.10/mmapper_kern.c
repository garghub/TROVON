static T_1 F_1 ( struct V_1 * V_1 , char T_2 * V_2 , T_3 V_3 ,
T_4 * V_4 )
{
return F_2 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
}
static T_1 F_3 ( struct V_1 * V_1 , const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
if ( * V_4 > V_6 )
return - V_7 ;
return F_4 ( V_5 , V_6 , V_4 , V_2 , V_3 ) ;
}
static long F_5 ( struct V_1 * V_1 , unsigned int V_8 , unsigned long V_9 )
{
return - V_10 ;
}
static int F_6 ( struct V_1 * V_1 , struct V_11 * V_12 )
{
int V_13 = - V_7 ;
int V_14 ;
if ( V_12 -> V_15 != 0 )
goto V_16;
V_14 = V_12 -> V_17 - V_12 -> V_18 ;
if ( V_14 > V_6 )
return - V_19 ;
if ( F_7 ( V_12 , V_12 -> V_18 , V_20 >> V_21 , V_14 ,
V_12 -> V_22 ) )
goto V_16;
V_13 = 0 ;
V_16:
return V_13 ;
}
static int F_8 ( struct V_23 * V_23 , struct V_1 * V_1 )
{
return 0 ;
}
static int F_9 ( struct V_23 * V_23 , struct V_1 * V_1 )
{
return 0 ;
}
static int T_5 F_10 ( void )
{
int V_24 ;
F_11 ( V_25 L_1 ) ;
V_5 = ( char * ) F_12 ( L_2 , & V_6 ) ;
if ( V_6 == 0 ) {
F_11 ( V_26 L_3 ) ;
return - V_27 ;
}
V_20 = F_13 ( V_5 ) ;
V_24 = F_14 ( & V_28 ) ;
if ( V_24 ) {
F_11 ( V_26 L_4 ,
V_24 ) ;
return V_24 ;
}
return 0 ;
}
static void F_15 ( void )
{
F_16 ( & V_28 ) ;
}
