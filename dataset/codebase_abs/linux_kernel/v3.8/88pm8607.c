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
static int F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_5 ( V_5 -> V_15 , V_2 -> V_9 -> V_22 ,
1 << V_2 -> V_9 -> V_23 , 0 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_5 ( V_5 -> V_15 , V_2 -> V_9 -> V_22 ,
1 << V_2 -> V_9 -> V_23 ,
1 << V_2 -> V_9 -> V_23 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 ;
V_6 = F_9 ( V_5 -> V_15 , V_2 -> V_9 -> V_22 ) ;
if ( V_6 < 0 )
return V_6 ;
return ! ( ( unsigned char ) V_6 & ( 1 << V_2 -> V_9 -> V_23 ) ) ;
}
static int F_10 ( struct V_24 * V_25 ,
struct V_4 * V_5 ,
struct V_26 * V_27 )
{
struct V_28 * V_29 , * V_30 ;
V_29 = V_25 -> V_31 . V_32 -> V_33 ;
if ( ! V_29 )
return - V_34 ;
V_29 = F_11 ( V_29 , L_1 ) ;
if ( ! V_29 ) {
F_12 ( & V_25 -> V_31 , L_2 ) ;
return - V_34 ;
}
F_13 (nproot, np) {
if ( ! F_14 ( V_30 -> V_35 , V_5 -> V_9 . V_35 ) ) {
V_27 -> V_36 =
F_15 ( & V_25 -> V_31 , V_30 ) ;
V_27 -> V_33 = V_30 ;
break;
}
}
return 0 ;
}
static int F_16 ( struct V_24 * V_25 )
{
struct V_37 * V_38 = F_17 ( V_25 -> V_31 . V_32 ) ;
struct V_4 * V_5 = NULL ;
struct V_39 * V_40 = V_25 -> V_31 . V_41 ;
struct V_26 V_27 = { } ;
struct V_42 * V_43 ;
int V_44 ;
V_43 = F_18 ( V_25 , V_45 , 0 ) ;
if ( V_43 ) {
for ( V_44 = 0 ; V_44 < F_19 ( V_4 ) ; V_44 ++ ) {
V_5 = & V_4 [ V_44 ] ;
if ( V_5 -> V_9 . V_16 == V_43 -> V_46 )
break;
}
if ( V_44 == F_19 ( V_4 ) ) {
F_12 ( & V_25 -> V_31 , L_3 ,
( unsigned long long ) V_43 -> V_46 ) ;
return - V_7 ;
}
} else {
V_5 = & V_47 [ 0 ] ;
V_44 = - 1 ;
}
V_5 -> V_15 = ( V_38 -> V_17 == V_48 ) ? V_38 -> V_49 : V_38 -> V_50 ;
V_5 -> V_51 = ( V_38 -> V_17 == V_48 ) ? V_38 -> V_50 :
V_38 -> V_49 ;
V_5 -> V_38 = V_38 ;
if ( ( V_44 == V_19 ) && V_5 -> V_38 -> V_52 )
V_5 -> V_11 = 1 ;
V_27 . V_31 = & V_25 -> V_31 ;
V_27 . V_53 = V_5 ;
if ( F_10 ( V_25 , V_5 , & V_27 ) )
if ( V_40 )
V_27 . V_36 = V_40 ;
if ( V_38 -> V_17 == V_48 )
V_27 . V_54 = V_38 -> V_54 ;
else
V_27 . V_54 = V_38 -> V_55 ;
V_5 -> V_56 = F_20 ( & V_5 -> V_9 , & V_27 ) ;
if ( F_21 ( V_5 -> V_56 ) ) {
F_12 ( & V_25 -> V_31 , L_4 ,
V_5 -> V_9 . V_35 ) ;
return F_22 ( V_5 -> V_56 ) ;
}
F_23 ( V_25 , V_5 ) ;
return 0 ;
}
static int F_24 ( struct V_24 * V_25 )
{
struct V_4 * V_5 = F_25 ( V_25 ) ;
F_23 ( V_25 , NULL ) ;
F_26 ( V_5 -> V_56 ) ;
return 0 ;
}
static int T_2 F_27 ( void )
{
return F_28 ( & V_57 ) ;
}
static void T_3 F_29 ( void )
{
F_30 ( & V_57 ) ;
}
