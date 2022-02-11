int F_1 ( void * V_1 , void * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 , V_6 ;
V_6 = - V_7 ;
F_2 ( & V_8 ) ;
V_5 = F_3 ( & V_9 , V_10 ) ;
if ( V_5 != V_11 )
goto error;
V_9 . V_12 = V_1 ;
V_9 . V_13 = V_3 ;
V_9 . V_14 = 0 ;
V_9 . V_15 = V_2 ;
V_9 . V_16 = V_4 ;
V_9 . V_17 = 0 ;
V_5 = F_4 ( & V_9 , V_18 ) ;
if ( V_5 != V_19 )
goto error;
V_5 = F_5 ( & V_9 ) ;
if ( V_5 != V_11 )
goto error;
if ( V_9 . V_17 >= V_9 . V_14 )
goto error;
V_6 = V_9 . V_17 ;
error:
F_6 ( & V_8 ) ;
return V_6 ;
}
int F_7 ( void * V_1 , void * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 , V_6 ;
V_6 = - V_7 ;
F_2 ( & V_8 ) ;
V_5 = F_8 ( & V_9 ) ;
if ( V_5 != V_11 )
goto error;
V_9 . V_12 = V_1 ;
V_9 . V_13 = V_3 ;
V_9 . V_14 = 0 ;
V_9 . V_15 = V_2 ;
V_9 . V_16 = V_4 ;
V_9 . V_17 = 0 ;
V_5 = F_9 ( & V_9 , V_18 ) ;
if ( V_5 != V_19 )
goto error;
V_5 = F_10 ( & V_9 ) ;
if ( V_5 != V_11 )
goto error;
V_6 = 0 ;
error:
F_6 ( & V_8 ) ;
return V_6 ;
}
int T_2 F_11 ( void )
{
T_1 V_20 = F_12 ( F_13 ( V_21 , V_22 ) ,
F_14 () ) ;
V_9 . V_23 = F_15 ( V_20 ) ;
if ( ! V_9 . V_23 )
return - V_24 ;
return 0 ;
}
void F_16 ( void )
{
F_17 ( V_9 . V_23 ) ;
}
