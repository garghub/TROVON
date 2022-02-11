static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( V_4 -> V_5 , V_1 ) ;
F_3 ( V_4 -> V_6 , & V_4 -> V_7 , 0 ) ;
return V_8 ;
}
static void F_4 ( struct V_3 * V_4 )
{
struct V_9 * V_10 = V_4 -> V_10 ;
int V_11 , V_12 , V_13 , y0 , y1 , V_14 ;
int V_15 , V_16 ;
V_11 = V_4 -> V_17 [ 0 ] & 0xfff ;
V_12 = V_4 -> V_17 [ 1 ] & 0xfff ;
V_13 = V_4 -> V_17 [ 2 ] & 0xfff ;
y0 = V_4 -> V_17 [ 3 ] & 0xfff ;
y1 = ( V_4 -> V_17 [ 0 ] >> 12 ) & 0xfff ;
V_14 = ( V_4 -> V_17 [ 1 ] >> 12 ) & 0xfff ;
V_15 = ( V_4 -> V_17 [ 2 ] >> 12 ) & 0xfff ;
V_16 = ( V_4 -> V_17 [ 3 ] >> 12 ) & 0xfff ;
F_5 ( & V_10 -> V_18 ,
L_1 ,
V_11 , V_12 , V_13 , y0 , y1 , V_14 , V_15 , V_16 ) ;
F_6 ( V_11 , V_12 , V_13 ) ;
F_6 ( y0 , y1 , V_14 ) ;
V_15 = ( V_15 + V_16 ) / 2 ;
if ( ! V_15 || ! V_19 ||
( V_13 - V_11 < V_19 &&
V_14 - y0 < V_19 ) ) {
if ( V_15 ) {
F_7 ( V_10 , V_20 , V_12 ) ;
F_7 ( V_10 , V_21 , y1 ) ;
F_5 ( & V_10 -> V_18 , L_2 ,
V_12 , y1 , 0x1000 - V_15 ) ;
F_3 ( V_4 -> V_6 , & V_4 -> V_7 , V_22 / 50 ) ;
} else
F_5 ( & V_10 -> V_18 , L_3 ) ;
F_7 ( V_10 , V_23 ,
V_15 ? 0x1000 - V_15 : V_15 ) ;
F_8 ( V_10 , V_24 , V_15 ) ;
F_9 ( V_10 ) ;
} else
F_5 ( & V_10 -> V_18 , L_4 ) ;
}
static void F_10 ( struct V_25 * V_7 )
{
struct V_3 * V_4 =
F_11 ( V_7 , struct V_3 , V_7 . V_7 ) ;
unsigned int V_26 = V_27 ;
unsigned int V_28 = 12 ;
if ( F_12 ( V_4 -> V_5 ,
V_26 , V_28 ,
V_4 -> V_29 -> V_30 , V_4 -> V_29 -> V_31 ,
V_4 -> V_17 ) == 0 )
F_4 ( V_4 ) ;
}
static int F_13 ( struct V_9 * V_18 )
{
struct V_3 * V_4 = F_14 ( V_18 ) ;
int V_32 ;
F_15 ( V_4 -> V_5 ) ;
F_2 ( V_4 -> V_5 , V_33 ) ;
V_32 = F_16 ( V_4 -> V_5 , V_33 ,
F_1 , V_34 , V_4 ) ;
if ( V_32 )
goto V_35;
V_32 = F_17 ( V_4 -> V_5 , V_36 ,
V_37 , V_38 ) ;
if ( V_32 )
F_18 ( V_4 -> V_5 , V_33 , V_4 ) ;
V_35:
F_19 ( V_4 -> V_5 ) ;
return V_32 ;
}
static void F_20 ( struct V_9 * V_18 )
{
struct V_3 * V_4 = F_14 ( V_18 ) ;
F_15 ( V_4 -> V_5 ) ;
F_17 ( V_4 -> V_5 , V_36 ,
V_37 , 0 ) ;
F_18 ( V_4 -> V_5 , V_33 , V_4 ) ;
F_19 ( V_4 -> V_5 ) ;
F_21 ( & V_4 -> V_7 ) ;
}
static int T_2 F_22 ( struct V_39 * V_40 )
{
struct V_3 * V_4 ;
struct V_9 * V_10 ;
int V_32 = - V_41 ;
V_4 = F_23 ( sizeof( * V_4 ) , V_42 ) ;
V_10 = F_24 () ;
if ( ! V_4 || ! V_10 )
goto V_43;
F_25 ( & V_4 -> V_7 , F_10 ) ;
V_4 -> V_5 = F_26 ( V_40 -> V_18 . V_44 ) ;
V_4 -> V_10 = V_10 ;
V_4 -> V_29 = F_27 ( & V_40 -> V_18 ) ;
if ( ! V_4 -> V_29 ) {
F_28 ( & V_40 -> V_18 , L_5 ) ;
V_32 = - V_45 ;
goto V_43;
}
V_4 -> V_6 = F_29 ( L_6 ) ;
if ( ! V_4 -> V_6 )
goto V_43;
V_10 -> V_46 = V_34 ;
V_10 -> V_18 . V_44 = & V_40 -> V_18 ;
V_10 -> V_47 [ 0 ] = F_30 ( V_48 ) | F_30 ( V_49 ) ;
V_10 -> V_50 [ F_31 ( V_24 ) ] = F_30 ( V_24 ) ;
F_32 ( V_10 , V_20 , 0 , 0xfff , 0 , 0 ) ;
F_32 ( V_10 , V_21 , 0 , 0xfff , 0 , 0 ) ;
F_32 ( V_10 , V_23 , 0 , 0xfff , 0 , 0 ) ;
V_10 -> V_51 = F_13 ;
V_10 -> V_52 = F_20 ;
F_33 ( V_10 , V_4 ) ;
V_32 = F_34 ( V_4 -> V_10 ) ;
if ( V_32 ) {
F_28 ( & V_40 -> V_18 ,
L_7 , V_32 ) ;
goto V_53;
}
F_35 ( V_40 , V_4 ) ;
return 0 ;
V_53:
F_36 ( V_4 -> V_6 ) ;
V_43:
F_37 ( V_10 ) ;
F_38 ( V_4 ) ;
return V_32 ;
}
static int F_39 ( struct V_39 * V_40 )
{
struct V_3 * V_4 = F_40 ( V_40 ) ;
F_35 ( V_40 , NULL ) ;
F_36 ( V_4 -> V_6 ) ;
F_41 ( V_4 -> V_10 ) ;
F_38 ( V_4 ) ;
return 0 ;
}
static int T_2 F_42 ( void )
{
return F_43 ( & V_54 , & F_22 ) ;
}
static void T_3 F_44 ( void )
{
F_45 ( & V_54 ) ;
}
