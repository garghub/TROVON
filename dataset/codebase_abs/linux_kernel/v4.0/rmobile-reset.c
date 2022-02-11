static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
F_2 ( L_1 , V_5 , V_3 ) ;
F_3 ( V_6 , V_7 + V_8 ) ;
return V_9 ;
}
static int F_4 ( struct V_10 * V_11 )
{
int error ;
V_7 = F_5 ( V_11 -> V_12 . V_13 , 1 ) ;
if ( ! V_7 )
return - V_14 ;
error = F_6 ( & V_15 ) ;
if ( error ) {
F_7 ( & V_11 -> V_12 ,
L_2 , error ) ;
goto V_16;
}
return 0 ;
V_16:
F_8 ( V_7 ) ;
return error ;
}
static int F_9 ( struct V_10 * V_11 )
{
F_10 ( & V_15 ) ;
F_8 ( V_7 ) ;
return 0 ;
}
