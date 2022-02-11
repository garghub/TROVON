static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_3 = F_3 ( V_6 -> V_7 ) ;
if ( V_3 ) {
F_4 ( V_2 -> V_8 , L_1 ) ;
return V_3 ;
}
F_5 ( & V_6 -> V_9 ) ;
V_4 = F_6 ( V_6 -> V_10 + V_11 ) ;
V_4 |= ( V_12 | V_13 ) ;
F_7 ( ( V_4 | V_14 ) ,
V_6 -> V_10 + V_11 ) ;
F_7 ( V_15 , V_6 -> V_10 + V_16 ) ;
F_8 ( & V_6 -> V_9 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
T_1 V_4 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_5 ( & V_6 -> V_9 ) ;
V_4 = F_6 ( V_6 -> V_10 + V_11 ) ;
F_7 ( ( V_4 & ~ V_14 ) ,
V_6 -> V_10 + V_11 ) ;
F_7 ( 0 , V_6 -> V_10 + V_16 ) ;
F_8 ( & V_6 -> V_9 ) ;
F_10 ( V_6 -> V_7 ) ;
F_11 ( L_2 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
T_1 V_4 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_5 ( & V_6 -> V_9 ) ;
V_4 = F_6 ( V_6 -> V_10 + V_11 ) ;
V_4 |= ( V_12 | V_13 ) ;
F_7 ( V_4 , V_6 -> V_10 + V_11 ) ;
F_8 ( & V_6 -> V_9 ) ;
return 0 ;
}
static T_1 F_13 ( struct V_5 * V_6 )
{
int V_17 ;
T_1 V_18 ;
T_1 V_19 ;
F_5 ( & V_6 -> V_9 ) ;
V_18 = F_6 ( V_6 -> V_10 + V_20 ) ;
V_19 = F_6 ( V_6 -> V_10 + V_20 ) ;
for ( V_17 = 0 ;
( ( V_17 <= V_21 ) &&
( V_19 == V_18 ) ) ; V_17 ++ ) {
V_19 = F_6 ( V_6 -> V_10 + V_20 ) ;
}
F_8 ( & V_6 -> V_9 ) ;
if ( V_19 != V_18 )
return ~ V_22 ;
else
return V_22 ;
}
static int F_14 ( struct V_23 * V_24 )
{
int V_25 ;
T_1 V_26 = 0 , V_27 = 0 ;
struct V_28 * V_29 ;
struct V_5 * V_6 ;
struct V_1 * V_30 ;
V_6 = F_15 ( & V_24 -> V_31 , sizeof( * V_6 ) , V_32 ) ;
if ( ! V_6 )
return - V_33 ;
V_30 = & V_6 -> V_30 ;
V_30 -> V_34 = & V_35 ;
V_30 -> V_36 = & V_37 ;
V_30 -> V_8 = & V_24 -> V_31 ;
V_29 = F_16 ( V_24 , V_38 , 0 ) ;
V_6 -> V_10 = F_17 ( & V_24 -> V_31 , V_29 ) ;
if ( F_18 ( V_6 -> V_10 ) )
return F_19 ( V_6 -> V_10 ) ;
V_25 = F_20 ( V_24 -> V_31 . V_39 , L_3 ,
& V_6 -> V_40 ) ;
if ( V_25 )
F_21 ( & V_24 -> V_31 ,
L_4 ) ;
V_25 = F_20 ( V_24 -> V_31 . V_39 , L_5 ,
& V_27 ) ;
if ( V_25 )
F_21 ( & V_24 -> V_31 ,
L_6 ) ;
F_22 ( V_30 , V_27 ) ;
V_6 -> V_7 = F_23 ( & V_24 -> V_31 , NULL ) ;
if ( F_18 ( V_6 -> V_7 ) ) {
if ( F_19 ( V_6 -> V_7 ) != - V_41 )
return F_19 ( V_6 -> V_7 ) ;
V_6 -> V_7 = NULL ;
V_25 = F_20 ( V_24 -> V_31 . V_39 , L_7 ,
& V_26 ) ;
if ( V_25 )
F_21 ( & V_24 -> V_31 ,
L_8 ) ;
} else {
V_26 = F_24 ( V_6 -> V_7 ) ;
}
if ( V_26 && V_6 -> V_40 )
V_30 -> V_42 = 2 * ( ( 1 << V_6 -> V_40 ) /
V_26 ) ;
F_25 ( & V_6 -> V_9 ) ;
F_26 ( V_30 , V_6 ) ;
V_25 = F_27 ( V_6 -> V_7 ) ;
if ( V_25 ) {
F_4 ( & V_24 -> V_31 , L_9 ) ;
return V_25 ;
}
V_25 = F_13 ( V_6 ) ;
if ( V_25 == V_22 ) {
F_4 ( & V_24 -> V_31 , L_10 ) ;
goto V_43;
}
V_25 = F_28 ( V_30 ) ;
if ( V_25 ) {
F_4 ( & V_24 -> V_31 , L_11 , V_25 ) ;
goto V_43;
}
F_10 ( V_6 -> V_7 ) ;
F_29 ( & V_24 -> V_31 , L_12 ,
V_6 -> V_10 , V_30 -> V_42 ) ;
F_30 ( V_24 , V_6 ) ;
return 0 ;
V_43:
F_31 ( V_6 -> V_7 ) ;
return V_25 ;
}
static int F_32 ( struct V_23 * V_24 )
{
struct V_5 * V_6 = F_33 ( V_24 ) ;
F_34 ( & V_6 -> V_30 ) ;
F_31 ( V_6 -> V_7 ) ;
return 0 ;
}
static int T_2 F_35 ( struct V_44 * V_31 )
{
struct V_23 * V_24 = F_36 ( V_31 ) ;
struct V_5 * V_6 = F_33 ( V_24 ) ;
if ( F_37 ( & V_6 -> V_30 ) )
F_9 ( & V_6 -> V_30 ) ;
return 0 ;
}
static int T_2 F_38 ( struct V_44 * V_31 )
{
struct V_23 * V_24 = F_36 ( V_31 ) ;
struct V_5 * V_6 = F_33 ( V_24 ) ;
int V_3 = 0 ;
if ( F_37 ( & V_6 -> V_30 ) )
V_3 = F_1 ( & V_6 -> V_30 ) ;
return V_3 ;
}
