static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
void T_1 * V_5 = V_2 -> V_6 [ 3 ] . V_7 + V_8 ;
V_4 -> V_9 |= F_2 ( V_5 ) ;
F_3 ( 0 , V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
void T_1 * V_5 = V_2 -> V_6 [ 3 ] . V_7 + V_8 ;
F_3 ( F_2 ( V_5 ) | V_4 -> V_9 , V_5 ) ;
V_4 -> V_9 = 0 ;
}
static T_2 F_5 ( int V_10 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
void T_1 * V_11 = V_2 -> V_6 [ 3 ] . V_7 + V_12 ;
void T_1 * V_5 = V_2 -> V_6 [ 3 ] . V_7 + V_8 ;
if ( ! ( F_2 ( V_11 ) & F_2 ( V_5 ) ) )
return V_13 ;
F_6 ( & V_4 -> V_14 ) ;
F_1 ( V_2 , V_4 ) ;
F_7 ( & V_4 -> V_14 ) ;
return V_15 ;
}
static int F_8 ( struct V_1 * V_2 , T_3 V_16 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_9 ( & V_4 -> V_14 ) ;
if ( V_16 )
F_4 ( V_2 , V_4 ) ;
else
F_1 ( V_2 , V_4 ) ;
F_10 ( & V_4 -> V_14 ) ;
return 0 ;
}
static int F_11 ( struct V_17 * V_18 , struct V_1 * V_2 ,
int V_19 , int V_20 )
{
V_2 -> V_6 [ V_19 ] . V_21 = F_12 ( V_18 , V_20 ) ;
if ( ! V_2 -> V_6 [ V_19 ] . V_21 )
return - 1 ;
V_2 -> V_6 [ V_19 ] . V_7 = F_13 ( F_12 ( V_18 , V_20 ) ,
F_14 ( V_18 , V_20 ) ) ;
if ( ! V_2 -> V_6 [ V_19 ] . V_7 )
return - 1 ;
V_2 -> V_6 [ V_19 ] . V_22 = F_14 ( V_18 , V_20 ) ;
V_2 -> V_6 [ V_19 ] . V_23 = V_24 ;
return 0 ;
}
static int T_4 F_15 ( struct V_17 * V_18 ,
const struct V_25 * V_26 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_27 ;
V_2 = F_16 ( sizeof( struct V_1 ) , V_28 ) ;
if ( ! V_2 )
return - V_29 ;
V_4 = F_16 ( sizeof( struct V_3 ) , V_28 ) ;
if ( ! V_4 )
goto V_30;
if ( F_17 ( V_18 ) )
goto V_31;
if ( F_18 ( V_18 , L_1 ) )
goto V_32;
if ( F_11 ( V_18 , V_2 , 0 , 0 ) )
goto V_33;
if ( F_11 ( V_18 , V_2 , 1 , 2 ) )
goto V_33;
if ( F_11 ( V_18 , V_2 , 2 , 3 ) )
goto V_33;
if ( F_11 ( V_18 , V_2 , 3 , 4 ) )
goto V_33;
if ( F_11 ( V_18 , V_2 , 4 , 5 ) )
goto V_33;
F_19 ( & V_4 -> V_14 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_34 = L_2 ;
V_2 -> V_35 = L_3 ;
V_2 -> V_10 = V_18 -> V_10 ;
V_2 -> V_36 = V_37 ;
V_2 -> V_38 = F_5 ;
V_2 -> V_39 = F_8 ;
F_20 ( V_18 , V_2 ) ;
if ( F_21 ( & V_18 -> V_18 , V_2 ) )
goto V_33;
return 0 ;
V_33:
for ( V_27 = 0 ; V_27 < 5 ; V_27 ++ ) {
if ( V_2 -> V_6 [ V_27 ] . V_7 )
F_22 ( V_2 -> V_6 [ V_27 ] . V_7 ) ;
}
F_23 ( V_18 ) ;
V_32:
F_24 ( V_18 ) ;
V_31:
F_25 ( V_4 ) ;
V_30:
F_25 ( V_2 ) ;
return - V_40 ;
}
static void F_26 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_27 ( V_18 ) ;
int V_27 ;
F_28 ( V_2 ) ;
F_23 ( V_18 ) ;
F_24 ( V_18 ) ;
F_20 ( V_18 , NULL ) ;
for ( V_27 = 0 ; V_27 < 5 ; V_27 ++ ) {
if ( V_2 -> V_6 [ V_27 ] . V_7 )
F_22 ( V_2 -> V_6 [ V_27 ] . V_7 ) ;
}
F_25 ( V_2 -> V_4 ) ;
F_25 ( V_2 ) ;
}
static int T_5 F_29 ( void )
{
return F_30 ( & V_41 ) ;
}
static void T_6 F_31 ( void )
{
F_32 ( & V_41 ) ;
}
