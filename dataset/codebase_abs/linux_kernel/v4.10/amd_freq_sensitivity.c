static unsigned int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 ,
unsigned int V_4 )
{
int V_5 ;
long V_6 , V_7 ;
struct V_8 V_9 , V_10 ;
struct V_11 * V_12 = & F_2 ( V_13 , V_2 -> V_14 ) ;
struct V_15 * V_16 = V_2 -> V_17 ;
struct V_18 * V_19 = V_16 -> V_18 ;
struct V_20 * V_21 = V_19 -> V_22 ;
if ( ! V_2 -> V_23 )
return V_3 ;
F_3 ( V_2 -> V_14 , V_24 ,
& V_9 . V_25 , & V_9 . V_26 ) ;
F_3 ( V_2 -> V_14 , V_27 ,
& V_10 . V_25 , & V_10 . V_26 ) ;
V_9 . V_26 &= 0x00ffffff ;
V_10 . V_26 &= 0x00ffffff ;
if ( V_9 . V_28 < V_12 -> V_9 || V_10 . V_28 < V_12 -> V_10 ) {
V_3 = V_2 -> V_29 ;
goto V_30;
}
V_6 = V_9 . V_28 - V_12 -> V_9 ;
V_7 = V_10 . V_28 - V_12 -> V_10 ;
if ( V_7 == 0 ) {
V_3 = V_2 -> V_29 ;
goto V_30;
}
V_5 = V_31 -
( V_31 * ( V_7 - V_6 ) / V_7 ) ;
F_4 ( V_5 , 0 , V_31 ) ;
if ( V_5 < V_21 -> V_32 ) {
if ( V_12 -> V_33 == V_2 -> V_29 )
V_3 = V_2 -> V_29 ;
if ( V_3 > V_2 -> V_29 )
V_3 = V_2 -> V_29 ;
else if ( V_3 < V_2 -> V_29 )
V_3 = V_2 -> V_34 ;
else {
unsigned int V_35 ;
V_35 = F_5 ( V_2 ,
V_2 -> V_29 - 1 ) ;
V_3 = V_2 -> V_23 [ V_35 ] . V_36 ;
}
V_12 -> V_33 = V_3 ;
} else
V_12 -> V_33 = 0 ;
V_30:
V_12 -> V_9 = V_9 . V_28 ;
V_12 -> V_10 = V_10 . V_28 ;
return V_3 ;
}
static int T_1 F_6 ( void )
{
T_2 V_37 ;
if ( V_38 . V_39 != V_40 )
return - V_41 ;
if ( ! F_7 ( V_42 ) )
return - V_41 ;
if ( F_8 ( V_24 , & V_37 ) )
return - V_41 ;
if ( ! ( V_37 >> V_43 ) )
return - V_41 ;
F_9 ( F_1 ,
V_44 ) ;
return 0 ;
}
static void T_3 F_10 ( void )
{
F_11 () ;
}
