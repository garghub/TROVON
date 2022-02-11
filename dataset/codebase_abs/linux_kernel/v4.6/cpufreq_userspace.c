static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_4 = - V_5 ;
F_2 ( L_1 , V_2 -> V_6 , V_3 ) ;
F_3 ( & V_7 ) ;
if ( ! F_4 ( V_8 , V_2 -> V_6 ) )
goto V_9;
V_4 = F_5 ( V_2 , V_3 , V_10 ) ;
V_9:
F_6 ( & V_7 ) ;
return V_4 ;
}
static T_1 F_7 ( struct V_1 * V_2 , char * V_11 )
{
return sprintf ( V_11 , L_2 , V_2 -> V_12 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned int V_13 )
{
unsigned int V_6 = V_2 -> V_6 ;
int V_14 = 0 ;
switch ( V_13 ) {
case V_15 :
F_9 ( ! V_2 -> V_12 ) ;
F_2 ( L_3 , V_6 ) ;
F_3 ( & V_7 ) ;
F_4 ( V_8 , V_6 ) = 1 ;
F_6 ( & V_7 ) ;
break;
case V_16 :
F_2 ( L_4 , V_6 ) ;
F_3 ( & V_7 ) ;
F_4 ( V_8 , V_6 ) = 0 ;
F_6 ( & V_7 ) ;
break;
case V_17 :
F_3 ( & V_7 ) ;
F_2 ( L_5 ,
V_6 , V_2 -> V_18 , V_2 -> V_19 ,
V_2 -> V_12 ) ;
if ( V_2 -> V_19 < V_2 -> V_12 )
F_5 ( V_2 , V_2 -> V_19 ,
V_20 ) ;
else if ( V_2 -> V_18 > V_2 -> V_12 )
F_5 ( V_2 , V_2 -> V_18 ,
V_10 ) ;
F_6 ( & V_7 ) ;
break;
}
return V_14 ;
}
static int T_2 F_10 ( void )
{
return F_11 ( & V_21 ) ;
}
static void T_3 F_12 ( void )
{
F_13 ( & V_21 ) ;
}
struct V_22 * F_14 ( void )
{
return & V_21 ;
}
