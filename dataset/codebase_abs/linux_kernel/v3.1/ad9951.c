static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 ,
T_2 V_6 )
{
struct V_7 V_8 ;
struct V_9 V_10 ;
int V_11 ;
struct V_12 * V_13 = (struct V_12 * ) V_5 ;
struct V_14 * V_15 = F_2 ( V_2 ) ;
struct V_16 * V_17 = F_3 ( V_15 ) ;
V_10 . V_6 = 3 ;
V_10 . V_18 = & V_13 -> V_19 [ 0 ] ;
F_4 ( & V_17 -> V_20 ) ;
F_5 ( & V_8 ) ;
F_6 ( & V_10 , & V_8 ) ;
V_11 = F_7 ( V_17 -> V_21 , & V_8 ) ;
if ( V_11 )
goto V_22;
V_10 . V_6 = 2 ;
V_10 . V_18 = & V_13 -> V_23 [ 0 ] ;
F_5 ( & V_8 ) ;
F_6 ( & V_10 , & V_8 ) ;
V_11 = F_7 ( V_17 -> V_21 , & V_8 ) ;
if ( V_11 )
goto V_22;
V_10 . V_6 = 5 ;
V_10 . V_18 = & V_13 -> V_24 [ 0 ] ;
F_5 ( & V_8 ) ;
F_6 ( & V_10 , & V_8 ) ;
V_11 = F_7 ( V_17 -> V_21 , & V_8 ) ;
if ( V_11 )
goto V_22;
V_10 . V_6 = 3 ;
V_10 . V_18 = & V_13 -> V_25 [ 0 ] ;
F_5 ( & V_8 ) ;
F_6 ( & V_10 , & V_8 ) ;
V_11 = F_7 ( V_17 -> V_21 , & V_8 ) ;
if ( V_11 )
goto V_22;
V_22:
F_8 ( & V_17 -> V_20 ) ;
return V_11 ? V_11 : V_6 ;
}
static void F_9 ( struct V_16 * V_17 )
{
struct V_7 V_8 ;
struct V_9 V_10 ;
int V_11 ;
T_3 V_26 [ 5 ] ;
V_26 [ 0 ] = V_27 ;
V_26 [ 1 ] = 0 ;
V_26 [ 2 ] = V_28 | V_29 | V_30 | V_31 ;
V_26 [ 3 ] = V_32 | V_33 | V_34 ;
V_26 [ 4 ] = 0 ;
F_4 ( & V_17 -> V_20 ) ;
V_10 . V_6 = 5 ;
V_10 . V_18 = & V_26 ;
F_5 ( & V_8 ) ;
F_6 ( & V_10 , & V_8 ) ;
V_11 = F_7 ( V_17 -> V_21 , & V_8 ) ;
if ( V_11 )
goto V_22;
V_26 [ 0 ] = V_35 ;
V_26 [ 1 ] = V_36 ;
V_26 [ 2 ] = V_37 ;
V_26 [ 3 ] = 0 ;
V_10 . V_6 = 4 ;
V_10 . V_18 = & V_26 ;
F_5 ( & V_8 ) ;
F_6 ( & V_10 , & V_8 ) ;
V_11 = F_7 ( V_17 -> V_21 , & V_8 ) ;
if ( V_11 )
goto V_22;
V_22:
F_8 ( & V_17 -> V_20 ) ;
}
static int T_4 F_10 ( struct V_38 * V_39 )
{
struct V_16 * V_17 ;
struct V_14 * V_15 ;
int V_11 = 0 ;
V_15 = F_11 ( sizeof( * V_17 ) ) ;
if ( V_15 == NULL ) {
V_11 = - V_40 ;
goto V_22;
}
F_12 ( V_39 , V_15 ) ;
V_17 = F_3 ( V_15 ) ;
F_13 ( & V_17 -> V_20 ) ;
V_17 -> V_21 = V_39 ;
V_15 -> V_2 . V_41 = & V_39 -> V_2 ;
V_15 -> V_42 = & V_43 ;
V_15 -> V_44 = V_45 ;
V_11 = F_14 ( V_15 ) ;
if ( V_11 )
goto V_46;
V_39 -> V_47 = 2000000 ;
V_39 -> V_48 = V_49 ;
V_39 -> V_50 = 8 ;
F_15 ( V_39 ) ;
F_9 ( V_17 ) ;
return 0 ;
V_46:
F_16 ( V_15 ) ;
V_22:
return V_11 ;
}
static int T_5 F_17 ( struct V_38 * V_39 )
{
F_18 ( F_19 ( V_39 ) ) ;
return 0 ;
}
static T_6 int F_20 ( void )
{
return F_21 ( & V_51 ) ;
}
static T_7 void F_22 ( void )
{
F_23 ( & V_51 ) ;
}
