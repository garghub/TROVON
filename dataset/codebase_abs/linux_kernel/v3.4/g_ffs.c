static int T_1 F_1 ( void )
{
F_2 () ;
return F_3 () ;
}
static void T_2 F_4 ( void )
{
F_2 () ;
if ( F_5 ( 0 , & V_1 ) )
F_6 ( & V_2 ) ;
F_7 () ;
}
static int F_8 ( struct V_3 * V_4 )
{
int V_5 ;
F_2 () ;
if ( F_9 ( F_10 ( 0 , & V_1 ) ) )
return - V_6 ;
V_7 = V_4 ;
V_5 = F_11 ( & V_2 , V_8 ) ;
if ( F_12 ( V_5 < 0 ) )
F_13 ( 0 , & V_1 ) ;
return V_5 ;
}
static void F_14 ( struct V_3 * V_4 )
{
F_2 () ;
if ( F_5 ( 0 , & V_1 ) )
F_6 ( & V_2 ) ;
}
static int F_15 ( const char * V_9 )
{
return 0 ;
}
static int V_8 ( struct V_10 * V_11 )
{
int V_5 , V_12 ;
F_2 () ;
if ( F_9 ( ! V_7 ) )
return - V_13 ;
V_5 = F_16 ( V_11 -> V_14 , V_15 ) ;
if ( F_12 ( V_5 < 0 ) )
goto V_16;
V_5 = F_17 ( V_11 , V_17 ) ;
if ( F_12 ( V_5 < 0 ) )
goto error;
V_5 = F_18 ( V_7 , V_11 ) ;
if ( F_12 ( V_5 < 0 ) )
goto error;
for ( V_12 = 0 ; V_12 < F_19 ( V_18 ) ; ++ V_12 ) {
struct V_19 * V_20 = V_18 + V_12 ;
V_20 -> V_20 . V_21 = V_17 [ V_12 ] . V_22 ;
V_20 -> V_20 . V_23 = V_17 [ V_12 ] . V_24 ;
V_20 -> V_20 . V_25 = 1 + V_12 ;
V_20 -> V_20 . V_26 = V_27 ;
V_5 = F_20 ( V_11 , & V_20 -> V_20 , V_28 ) ;
if ( F_12 ( V_5 < 0 ) )
goto V_29;
}
return 0 ;
V_29:
F_21 ( V_7 ) ;
error:
F_22 () ;
V_16:
V_7 = NULL ;
return V_5 ;
}
static int F_23 ( struct V_10 * V_11 )
{
F_2 () ;
if ( V_7 ) {
F_22 () ;
F_21 ( V_7 ) ;
V_7 = NULL ;
}
return 0 ;
}
static int V_28 ( struct V_30 * V_20 )
{
struct V_19 * V_31 =
F_24 ( V_20 , struct V_19 , V_20 ) ;
int V_5 ;
if ( F_9 ( ! V_7 ) )
return - V_13 ;
if ( F_25 ( V_20 -> V_11 -> V_14 ) ) {
V_20 -> V_32 = V_33 ;
V_20 -> V_26 |= V_34 ;
}
if ( V_31 -> V_35 ) {
V_5 = V_31 -> V_35 ( V_20 , V_15 ) ;
if ( F_12 ( V_5 < 0 ) )
return V_5 ;
}
V_5 = F_26 ( V_20 -> V_11 , V_20 , V_7 ) ;
if ( F_12 ( V_5 < 0 ) )
return V_5 ;
if ( V_20 -> V_36 < F_19 ( V_20 -> V_37 ) )
V_20 -> V_37 [ V_20 -> V_36 ] = NULL ;
return 0 ;
}
static int F_27 ( struct V_30 * V_20 , T_3 V_38 [ V_39 ] )
{
return F_28 ( V_20 -> V_11 -> V_14 )
? F_29 ( V_20 , V_38 )
: F_30 ( V_20 , V_38 ) ;
}
