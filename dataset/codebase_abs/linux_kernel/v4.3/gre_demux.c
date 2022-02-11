int F_1 ( const struct V_1 * V_2 , T_1 V_3 )
{
if ( V_3 >= V_4 )
return - V_5 ;
return ( F_2 ( ( const struct V_1 * * ) & V_6 [ V_3 ] , NULL , V_2 ) == NULL ) ?
0 : - V_7 ;
}
int F_3 ( const struct V_1 * V_2 , T_1 V_3 )
{
int V_8 ;
if ( V_3 >= V_4 )
return - V_5 ;
V_8 = ( F_2 ( ( const struct V_1 * * ) & V_6 [ V_3 ] , V_2 , NULL ) == V_2 ) ?
0 : - V_7 ;
if ( V_8 )
return V_8 ;
F_4 () ;
return 0 ;
}
static int F_5 ( struct V_9 * V_10 )
{
const struct V_1 * V_2 ;
T_1 V_11 ;
int V_8 ;
if ( ! F_6 ( V_10 , 12 ) )
goto V_12;
V_11 = V_10 -> V_13 [ 1 ] & 0x7f ;
if ( V_11 >= V_4 )
goto V_12;
F_7 () ;
V_2 = F_8 ( V_6 [ V_11 ] ) ;
if ( ! V_2 || ! V_2 -> V_14 )
goto V_15;
V_8 = V_2 -> V_14 ( V_10 ) ;
F_9 () ;
return V_8 ;
V_15:
F_9 () ;
V_12:
F_10 ( V_10 ) ;
return V_16 ;
}
static void F_11 ( struct V_9 * V_10 , T_2 V_17 )
{
const struct V_1 * V_2 ;
const struct V_18 * V_19 = ( const struct V_18 * ) V_10 -> V_13 ;
T_1 V_11 = V_10 -> V_13 [ ( V_19 -> V_20 << 2 ) + 1 ] & 0x7f ;
if ( V_11 >= V_4 )
return;
F_7 () ;
V_2 = F_8 ( V_6 [ V_11 ] ) ;
if ( V_2 && V_2 -> V_21 )
V_2 -> V_21 ( V_10 , V_17 ) ;
F_9 () ;
}
static int T_3 F_12 ( void )
{
F_13 ( L_1 ) ;
if ( F_14 ( & V_22 , V_23 ) < 0 ) {
F_15 ( L_2 ) ;
return - V_24 ;
}
return 0 ;
}
static void T_4 F_16 ( void )
{
F_17 ( & V_22 , V_23 ) ;
}
