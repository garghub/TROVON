static int F_1 ( struct V_1 * V_1 ,
struct V_2 const * V_3 ,
int * V_4 ,
int * V_5 ,
long V_6 )
{
struct V_7 * V_8 = F_2 ( V_1 ) ;
int V_9 ;
T_1 V_10 ;
switch ( V_6 ) {
case V_11 :
V_10 = F_3 ( V_8 -> V_12 + V_3 -> V_13 * 4 ) ;
if ( F_4 ( V_10 ) ) {
F_5 ( & V_1 -> V_14 ,
L_1 ,
V_3 -> V_13 ) ;
return - V_15 ;
}
* V_4 = F_6 ( V_10 ) ;
V_9 = V_16 ;
break;
default:
V_9 = - V_17 ;
break;
}
return V_9 ;
}
static void F_7 ( void T_2 * V_18 )
{
int V_19 ;
T_3 V_20 ;
T_3 V_21 ;
V_21 = F_8 ( V_18 + V_22 ) ;
V_21 |= V_23 ;
F_9 ( V_21 , V_18 + V_22 ) ;
for ( V_19 = 0 ; V_19 < V_24 ; V_19 ++ ) {
V_20 = F_8 ( V_18 + V_19 ) ;
V_20 &= ~ V_25 ;
V_20 |= V_26 ;
F_9 ( V_20 , V_18 + V_19 ) ;
}
}
static int F_10 ( struct V_27 * V_14 ,
const struct V_28 * V_29 )
{
struct V_7 * V_8 ;
struct V_1 * V_30 ;
struct V_31 * V_32 ;
V_30 = F_11 ( & V_14 -> V_14 , sizeof( struct V_7 ) ) ;
if ( ! V_30 )
return - V_33 ;
V_8 = F_2 ( V_30 ) ;
V_30 -> V_34 = L_2 ;
V_30 -> V_14 . V_35 = & V_14 -> V_14 ;
V_30 -> V_6 = & V_36 ;
V_30 -> V_37 = V_38 ;
V_30 -> V_39 = V_40 ;
V_30 -> V_41 = F_12 ( V_40 ) ;
V_32 = F_13 ( V_14 , L_2 ) ;
if ( ! V_32 )
return - V_33 ;
V_8 -> V_12 = F_14 ( V_32 -> V_42 , F_15 ( V_32 ) ) ;
if ( V_8 -> V_12 == NULL )
goto V_43;
F_7 ( V_8 -> V_12 ) ;
V_8 -> V_32 = V_32 ;
F_16 ( V_14 , V_30 ) ;
return F_17 ( V_30 ) ;
V_43:
F_18 ( V_32 ) ;
return - V_44 ;
}
static void F_19 ( struct V_27 * V_14 )
{
struct V_1 * V_30 = F_20 ( V_14 ) ;
struct V_7 * V_8 = F_2 ( V_30 ) ;
F_21 ( V_30 ) ;
F_22 ( V_8 -> V_12 ) ;
F_18 ( V_8 -> V_32 ) ;
}
