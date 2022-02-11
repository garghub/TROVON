static unsigned int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 ,
unsigned int V_4 )
{
int V_5 ;
long V_6 , V_7 ;
struct V_8 V_9 , V_10 ;
struct V_11 * V_12 = & F_2 ( V_13 , V_2 -> V_14 ) ;
struct V_15 * V_16 = V_2 -> V_17 ;
struct V_18 * V_19 = V_16 -> V_20 ;
struct V_21 * V_22 =
V_16 -> V_23 -> V_24 ( V_2 -> V_14 ) ;
if ( ! V_22 -> V_25 )
return V_3 ;
F_3 ( V_2 -> V_14 , V_26 ,
& V_9 . V_27 , & V_9 . V_28 ) ;
F_3 ( V_2 -> V_14 , V_29 ,
& V_10 . V_27 , & V_10 . V_28 ) ;
V_9 . V_28 &= 0x00ffffff ;
V_10 . V_28 &= 0x00ffffff ;
if ( V_9 . V_30 < V_12 -> V_9 || V_10 . V_30 < V_12 -> V_10 ) {
V_3 = V_2 -> V_31 ;
goto V_32;
}
V_6 = V_9 . V_30 - V_12 -> V_9 ;
V_7 = V_10 . V_30 - V_12 -> V_10 ;
if ( V_7 == 0 ) {
V_3 = V_2 -> V_31 ;
goto V_32;
}
V_5 = V_33 -
( V_33 * ( V_7 - V_6 ) / V_7 ) ;
F_4 ( V_5 , 0 , V_33 ) ;
if ( V_5 < V_19 -> V_34 ) {
if ( V_12 -> V_35 == V_2 -> V_31 )
V_3 = V_2 -> V_31 ;
if ( V_3 > V_2 -> V_31 )
V_3 = V_2 -> V_31 ;
else if ( V_3 < V_2 -> V_31 )
V_3 = V_2 -> V_36 ;
else {
unsigned int V_37 ;
F_5 ( V_2 ,
V_22 -> V_25 , V_2 -> V_31 - 1 ,
V_38 , & V_37 ) ;
V_3 = V_22 -> V_25 [ V_37 ] . V_39 ;
}
V_12 -> V_35 = V_3 ;
} else
V_12 -> V_35 = 0 ;
V_32:
V_12 -> V_9 = V_9 . V_30 ;
V_12 -> V_10 = V_10 . V_30 ;
return V_3 ;
}
static int T_1 F_6 ( void )
{
T_2 V_40 ;
if ( V_41 . V_42 != V_43 )
return - V_44 ;
if ( ! F_7 ( V_45 ) )
return - V_44 ;
if ( F_8 ( V_26 , & V_40 ) )
return - V_44 ;
if ( ! ( V_40 >> V_46 ) )
return - V_44 ;
F_9 ( F_1 ,
V_47 ) ;
return 0 ;
}
static void T_3 F_10 ( void )
{
F_11 () ;
}
