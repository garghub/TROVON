static void F_1 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
T_1 V_4 ;
int V_5 ;
if ( V_3 -> V_6 . V_7 )
goto V_8;
V_4 = F_2 ( V_3 -> V_4 ) ;
switch ( V_4 ) {
case V_9 :
F_3 ( & V_3 -> V_10 -> V_11 , L_1 ) ;
F_4 ( NULL ) ;
case V_12 :
F_3 ( & V_3 -> V_10 -> V_11 , L_2 ) ;
F_5 () ;
break;
case V_13 :
F_3 ( & V_3 -> V_10 -> V_11 , L_3 ) ;
F_6 () ;
break;
case V_14 :
F_3 ( & V_3 -> V_10 -> V_11 , L_4 ) ;
F_7 ( V_15 ) ;
break;
default:
F_8 ( & V_3 -> V_10 -> V_11 , L_5 , V_4 ) ;
break;
}
V_5 = F_9 ( V_3 ) ;
if ( V_5 )
goto V_8;
return;
V_8:
F_3 ( & V_3 -> V_10 -> V_11 , L_6 ) ;
F_10 ( & V_3 -> V_16 ) ;
}
static
int F_9 ( struct V_2 * V_3 )
{
int V_5 ;
F_11 ( & V_3 -> V_6 , & V_3 -> V_17 , 1 ) ;
V_3 -> V_6 . F_10 = F_1 ;
V_3 -> V_6 . V_18 = V_3 ;
V_5 = F_12 ( V_3 -> V_10 , & V_3 -> V_6 ) ;
if ( V_5 )
F_13 ( & V_3 -> V_10 -> V_11 , L_7 , V_5 ) ;
return V_5 ;
}
static int F_14 ( struct V_19 * V_10 )
{
struct V_2 * V_3 ;
int V_5 ;
V_3 = F_15 ( & V_10 -> V_11 , sizeof( * V_3 ) , V_20 ) ;
if ( ! V_3 )
return - V_21 ;
V_3 -> V_10 = V_10 ;
F_16 ( & V_3 -> V_16 ) ;
V_3 -> V_17 . V_22 = & V_3 -> V_4 ;
V_3 -> V_17 . V_23 = sizeof( V_3 -> V_4 ) ;
V_5 = F_9 ( V_3 ) ;
if ( V_5 )
return V_5 ;
F_17 ( V_10 , V_3 ) ;
return 0 ;
}
static int F_18 ( struct V_19 * V_10 )
{
struct V_2 * V_3 = F_19 ( V_10 ) ;
F_20 ( V_10 ) ;
F_21 ( & V_3 -> V_16 ) ;
return 0 ;
}
