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
struct V_27 * V_28 = V_13 -> V_19 . V_29 ;
struct V_14 V_15 = { } ;
struct V_30 * V_31 ;
int V_32 ;
V_31 = F_13 ( V_13 , V_33 , 0 ) ;
if ( V_31 ) {
for ( V_32 = 0 ; V_32 < F_14 ( V_4 ) ; V_32 ++ ) {
V_5 = & V_4 [ V_32 ] ;
if ( V_5 -> V_9 . V_34 == V_31 -> V_35 )
break;
}
if ( V_32 == F_14 ( V_4 ) ) {
F_6 ( & V_13 -> V_19 , L_3 ,
( unsigned long long ) V_31 -> V_35 ) ;
return - V_7 ;
}
} else {
V_5 = & V_36 [ 0 ] ;
V_32 = - 1 ;
}
V_5 -> V_37 = ( V_26 -> V_38 == V_39 ) ? V_26 -> V_40 : V_26 -> V_41 ;
V_5 -> V_42 = ( V_26 -> V_38 == V_39 ) ? V_26 -> V_41 :
V_26 -> V_40 ;
V_5 -> V_26 = V_26 ;
if ( ( V_32 == V_43 ) && V_5 -> V_26 -> V_44 )
V_5 -> V_11 = 1 ;
V_15 . V_19 = & V_13 -> V_19 ;
V_15 . V_45 = V_5 ;
if ( F_3 ( V_13 , V_5 , & V_15 ) )
if ( V_28 )
V_15 . V_24 = V_28 ;
if ( V_26 -> V_38 == V_39 )
V_15 . V_46 = V_26 -> V_46 ;
else
V_15 . V_46 = V_26 -> V_47 ;
V_5 -> V_48 = F_15 ( & V_5 -> V_9 , & V_15 ) ;
if ( F_16 ( V_5 -> V_48 ) ) {
F_6 ( & V_13 -> V_19 , L_4 ,
V_5 -> V_9 . V_23 ) ;
return F_17 ( V_5 -> V_48 ) ;
}
F_18 ( V_13 , V_5 ) ;
return 0 ;
}
static int F_19 ( struct V_12 * V_13 )
{
struct V_4 * V_5 = F_20 ( V_13 ) ;
F_21 ( V_5 -> V_48 ) ;
return 0 ;
}
static int T_1 F_22 ( void )
{
return F_23 ( & V_49 ) ;
}
static void T_2 F_24 ( void )
{
F_25 ( & V_49 ) ;
}
