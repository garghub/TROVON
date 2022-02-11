static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 = - V_7 ;
if ( V_5 -> V_8 && ( V_3 < V_2 -> V_9 -> V_10 ) ) {
V_6 = V_5 -> V_8 [ V_3 ] ;
if ( V_5 -> V_11 )
V_6 <<= 1 ;
}
return V_6 ;
}
static int F_3 ( struct V_12 * V_13 ,
struct V_4 * V_5 ,
struct V_14 * V_15 )
{
struct V_16 * V_17 , * V_18 ;
V_17 = F_4 ( V_13 -> V_19 . V_20 -> V_21 ) ;
if ( ! V_17 )
return - V_22 ;
V_17 = F_5 ( V_17 , L_1 ) ;
if ( ! V_17 ) {
F_6 ( & V_13 -> V_19 , L_2 ) ;
return - V_22 ;
}
F_7 (nproot, np) {
if ( ! F_8 ( V_18 -> V_23 , V_5 -> V_9 . V_23 ) ) {
V_15 -> V_24 =
F_9 ( & V_13 -> V_19 , V_18 ) ;
V_15 -> V_21 = V_18 ;
break;
}
}
F_10 ( V_17 ) ;
return 0 ;
}
static int F_11 ( struct V_12 * V_13 )
{
struct V_25 * V_26 = F_12 ( V_13 -> V_19 . V_20 ) ;
struct V_4 * V_5 = NULL ;
struct V_27 * V_28 = F_13 ( & V_13 -> V_19 ) ;
struct V_14 V_15 = { } ;
struct V_29 * V_30 ;
int V_31 ;
V_30 = F_14 ( V_13 , V_32 , 0 ) ;
if ( V_30 ) {
for ( V_31 = 0 ; V_31 < F_15 ( V_4 ) ; V_31 ++ ) {
V_5 = & V_4 [ V_31 ] ;
if ( V_5 -> V_9 . V_33 == V_30 -> V_34 )
break;
}
if ( V_31 == F_15 ( V_4 ) ) {
F_6 ( & V_13 -> V_19 , L_3 ,
( unsigned long long ) V_30 -> V_34 ) ;
return - V_7 ;
}
} else {
V_5 = & V_35 [ 0 ] ;
V_31 = - 1 ;
}
V_5 -> V_36 = ( V_26 -> V_37 == V_38 ) ? V_26 -> V_39 : V_26 -> V_40 ;
V_5 -> V_41 = ( V_26 -> V_37 == V_38 ) ? V_26 -> V_40 :
V_26 -> V_39 ;
V_5 -> V_26 = V_26 ;
if ( ( V_31 == V_42 ) && V_5 -> V_26 -> V_43 )
V_5 -> V_11 = 1 ;
V_15 . V_19 = & V_13 -> V_19 ;
V_15 . V_44 = V_5 ;
if ( F_3 ( V_13 , V_5 , & V_15 ) )
if ( V_28 )
V_15 . V_24 = V_28 ;
if ( V_26 -> V_37 == V_38 )
V_15 . V_45 = V_26 -> V_45 ;
else
V_15 . V_45 = V_26 -> V_46 ;
V_5 -> V_47 = F_16 ( & V_13 -> V_19 , & V_5 -> V_9 ,
& V_15 ) ;
if ( F_17 ( V_5 -> V_47 ) ) {
F_6 ( & V_13 -> V_19 , L_4 ,
V_5 -> V_9 . V_23 ) ;
return F_18 ( V_5 -> V_47 ) ;
}
F_19 ( V_13 , V_5 ) ;
return 0 ;
}
static int T_1 F_20 ( void )
{
return F_21 ( & V_48 ) ;
}
static void T_2 F_22 ( void )
{
F_23 ( & V_48 ) ;
}
