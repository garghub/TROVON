int F_1 ( const struct V_1 * V_2 , T_1 V_3 )
{
if ( V_3 >= V_4 )
goto V_5;
F_2 ( & V_6 ) ;
if ( V_7 [ V_3 ] )
goto V_8;
F_3 ( V_7 [ V_3 ] , V_2 ) ;
F_4 ( & V_6 ) ;
return 0 ;
V_8:
F_4 ( & V_6 ) ;
V_5:
return - 1 ;
}
int F_5 ( const struct V_1 * V_2 , T_1 V_3 )
{
if ( V_3 >= V_4 )
goto V_5;
F_2 ( & V_6 ) ;
if ( F_6 ( V_7 [ V_3 ] ,
F_7 ( & V_6 ) ) != V_2 )
goto V_8;
F_3 ( V_7 [ V_3 ] , NULL ) ;
F_4 ( & V_6 ) ;
F_8 () ;
return 0 ;
V_8:
F_4 ( & V_6 ) ;
V_5:
return - 1 ;
}
static int F_9 ( struct V_9 * V_10 )
{
const struct V_1 * V_2 ;
T_1 V_11 ;
int V_12 ;
if ( ! F_10 ( V_10 , 12 ) )
goto V_13;
V_11 = V_10 -> V_14 [ 1 ] & 0x7f ;
if ( V_11 >= V_4 )
goto V_13;
F_11 () ;
V_2 = F_12 ( V_7 [ V_11 ] ) ;
if ( ! V_2 || ! V_2 -> V_15 )
goto V_16;
V_12 = V_2 -> V_15 ( V_10 ) ;
F_13 () ;
return V_12 ;
V_16:
F_13 () ;
V_13:
F_14 ( V_10 ) ;
return V_17 ;
}
static void F_15 ( struct V_9 * V_10 , T_2 V_18 )
{
const struct V_1 * V_2 ;
const struct V_19 * V_20 = ( const struct V_19 * ) V_10 -> V_14 ;
T_1 V_11 = V_10 -> V_14 [ ( V_20 -> V_21 << 2 ) + 1 ] & 0x7f ;
if ( V_11 >= V_4 )
return;
F_11 () ;
V_2 = F_12 ( V_7 [ V_11 ] ) ;
if ( V_2 && V_2 -> V_22 )
V_2 -> V_22 ( V_10 , V_18 ) ;
F_13 () ;
}
static int T_3 F_16 ( void )
{
F_17 ( L_1 ) ;
if ( F_18 ( & V_23 , V_24 ) < 0 ) {
F_19 ( L_2 ) ;
return - V_25 ;
}
return 0 ;
}
static void T_4 F_20 ( void )
{
F_21 ( & V_23 , V_24 ) ;
}
