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
static int F_3 ( struct V_1 * V_2 , unsigned V_12 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_13 ;
int V_6 ;
V_13 = ( T_1 ) ( V_12 << ( F_4 ( V_2 -> V_9 -> V_14 ) - 1 ) ) ;
V_6 = F_5 ( V_5 -> V_15 , V_2 -> V_9 -> V_16 ,
V_2 -> V_9 -> V_14 , V_13 ) ;
if ( V_6 )
return V_6 ;
switch ( V_5 -> V_9 . V_17 ) {
case V_18 :
case V_19 :
V_6 = F_5 ( V_5 -> V_15 , V_5 -> V_20 ,
1 << V_5 -> V_21 ,
1 << V_5 -> V_21 ) ;
break;
}
return V_6 ;
}
static int T_2 F_6 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = F_7 ( V_23 -> V_26 . V_27 ) ;
struct V_4 * V_5 = NULL ;
struct V_28 * V_29 = V_23 -> V_26 . V_30 ;
struct V_31 V_32 = { } ;
struct V_33 * V_34 ;
int V_35 ;
V_34 = F_8 ( V_23 , V_36 , 0 ) ;
if ( V_34 == NULL ) {
F_9 ( & V_23 -> V_26 , L_1 ) ;
return - V_7 ;
}
for ( V_35 = 0 ; V_35 < F_10 ( V_4 ) ; V_35 ++ ) {
V_5 = & V_4 [ V_35 ] ;
if ( V_5 -> V_9 . V_17 == V_34 -> V_37 )
break;
}
if ( V_35 == F_10 ( V_4 ) ) {
F_9 ( & V_23 -> V_26 , L_2 ,
( unsigned long long ) V_34 -> V_37 ) ;
return - V_7 ;
}
V_5 -> V_15 = ( V_25 -> V_17 == V_38 ) ? V_25 -> V_39 : V_25 -> V_40 ;
V_5 -> V_25 = V_25 ;
if ( ( V_35 == V_19 ) && V_5 -> V_25 -> V_41 )
V_5 -> V_11 = 1 ;
V_32 . V_26 = & V_23 -> V_26 ;
V_32 . V_42 = V_29 ;
V_32 . V_43 = V_5 ;
if ( V_25 -> V_17 == V_38 )
V_32 . V_44 = V_25 -> V_44 ;
else
V_32 . V_44 = V_25 -> V_45 ;
V_5 -> V_46 = F_11 ( & V_5 -> V_9 , & V_32 ) ;
if ( F_12 ( V_5 -> V_46 ) ) {
F_9 ( & V_23 -> V_26 , L_3 ,
V_5 -> V_9 . V_47 ) ;
return F_13 ( V_5 -> V_46 ) ;
}
F_14 ( V_23 , V_5 ) ;
return 0 ;
}
static int T_3 F_15 ( struct V_22 * V_23 )
{
struct V_4 * V_5 = F_16 ( V_23 ) ;
F_14 ( V_23 , NULL ) ;
F_17 ( V_5 -> V_46 ) ;
return 0 ;
}
static int T_4 F_18 ( void )
{
return F_19 ( & V_48 ) ;
}
static void T_5 F_20 ( void )
{
F_21 ( & V_48 ) ;
}
