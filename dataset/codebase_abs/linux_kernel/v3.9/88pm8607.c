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
static int F_3 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_4 ( V_5 -> V_12 , V_2 -> V_9 -> V_13 ,
1 << V_2 -> V_9 -> V_14 , 0 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_4 ( V_5 -> V_12 , V_2 -> V_9 -> V_13 ,
1 << V_2 -> V_9 -> V_14 ,
1 << V_2 -> V_9 -> V_14 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 ;
V_6 = F_7 ( V_5 -> V_12 , V_2 -> V_9 -> V_13 ) ;
if ( V_6 < 0 )
return V_6 ;
return ! ( ( unsigned char ) V_6 & ( 1 << V_2 -> V_9 -> V_14 ) ) ;
}
static int F_8 ( struct V_15 * V_16 ,
struct V_4 * V_5 ,
struct V_17 * V_18 )
{
struct V_19 * V_20 , * V_21 ;
V_20 = F_9 ( V_16 -> V_22 . V_23 -> V_24 ) ;
if ( ! V_20 )
return - V_25 ;
V_20 = F_10 ( V_20 , L_1 ) ;
if ( ! V_20 ) {
F_11 ( & V_16 -> V_22 , L_2 ) ;
return - V_25 ;
}
F_12 (nproot, np) {
if ( ! F_13 ( V_21 -> V_26 , V_5 -> V_9 . V_26 ) ) {
V_18 -> V_27 =
F_14 ( & V_16 -> V_22 , V_21 ) ;
V_18 -> V_24 = V_21 ;
break;
}
}
F_15 ( V_20 ) ;
return 0 ;
}
static int F_16 ( struct V_15 * V_16 )
{
struct V_28 * V_29 = F_17 ( V_16 -> V_22 . V_23 ) ;
struct V_4 * V_5 = NULL ;
struct V_30 * V_31 = V_16 -> V_22 . V_32 ;
struct V_17 V_18 = { } ;
struct V_33 * V_34 ;
int V_35 ;
V_34 = F_18 ( V_16 , V_36 , 0 ) ;
if ( V_34 ) {
for ( V_35 = 0 ; V_35 < F_19 ( V_4 ) ; V_35 ++ ) {
V_5 = & V_4 [ V_35 ] ;
if ( V_5 -> V_9 . V_37 == V_34 -> V_38 )
break;
}
if ( V_35 == F_19 ( V_4 ) ) {
F_11 ( & V_16 -> V_22 , L_3 ,
( unsigned long long ) V_34 -> V_38 ) ;
return - V_7 ;
}
} else {
V_5 = & V_39 [ 0 ] ;
V_35 = - 1 ;
}
V_5 -> V_12 = ( V_29 -> V_40 == V_41 ) ? V_29 -> V_42 : V_29 -> V_43 ;
V_5 -> V_44 = ( V_29 -> V_40 == V_41 ) ? V_29 -> V_43 :
V_29 -> V_42 ;
V_5 -> V_29 = V_29 ;
if ( ( V_35 == V_45 ) && V_5 -> V_29 -> V_46 )
V_5 -> V_11 = 1 ;
V_18 . V_22 = & V_16 -> V_22 ;
V_18 . V_47 = V_5 ;
if ( F_8 ( V_16 , V_5 , & V_18 ) )
if ( V_31 )
V_18 . V_27 = V_31 ;
if ( V_29 -> V_40 == V_41 )
V_18 . V_48 = V_29 -> V_48 ;
else
V_18 . V_48 = V_29 -> V_49 ;
V_5 -> V_50 = F_20 ( & V_5 -> V_9 , & V_18 ) ;
if ( F_21 ( V_5 -> V_50 ) ) {
F_11 ( & V_16 -> V_22 , L_4 ,
V_5 -> V_9 . V_26 ) ;
return F_22 ( V_5 -> V_50 ) ;
}
F_23 ( V_16 , V_5 ) ;
return 0 ;
}
static int F_24 ( struct V_15 * V_16 )
{
struct V_4 * V_5 = F_25 ( V_16 ) ;
F_23 ( V_16 , NULL ) ;
F_26 ( V_5 -> V_50 ) ;
return 0 ;
}
static int T_1 F_27 ( void )
{
return F_28 ( & V_51 ) ;
}
static void T_2 F_29 ( void )
{
F_30 ( & V_51 ) ;
}
