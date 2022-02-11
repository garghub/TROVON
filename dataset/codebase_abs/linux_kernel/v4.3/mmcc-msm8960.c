static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
int V_5 = 0 ;
T_2 V_6 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_9 = F_3 ( V_2 ) ;
for ( V_4 = 0 ; V_4 < V_9 ; V_4 ++ ) {
struct V_1 * V_10 = F_4 ( V_2 , V_4 ) ;
V_5 = F_5 ( V_10 -> V_11 ) ;
if ( V_5 )
goto V_12;
}
if ( V_3 == 2 )
V_6 = V_8 -> V_13 ;
else
V_6 = 0 ;
F_6 ( V_8 -> V_14 . V_15 , V_8 -> V_16 , V_8 -> V_13 , V_6 ) ;
F_7 ( 1 ) ;
if ( V_3 == 1 )
V_6 = V_8 -> V_17 ;
else
V_6 = 0 ;
F_6 ( V_8 -> V_14 . V_15 , V_8 -> V_18 , V_8 -> V_17 , V_6 ) ;
F_7 ( 1 ) ;
V_12:
for ( V_4 -- ; V_4 >= 0 ; V_4 -- ) {
struct V_1 * V_10 = F_4 ( V_2 , V_4 ) ;
F_8 ( V_10 -> V_11 ) ;
}
return V_5 ;
}
static T_1 F_9 ( struct V_1 * V_2 )
{
T_2 V_6 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_10 ( V_8 -> V_14 . V_15 , V_8 -> V_16 , & V_6 ) ;
if ( V_6 & V_8 -> V_13 )
return 2 ;
F_10 ( V_8 -> V_14 . V_15 , V_8 -> V_18 , & V_6 ) ;
if ( V_6 & V_8 -> V_17 )
return 1 ;
return 0 ;
}
static int F_11 ( struct V_19 * V_20 )
{
const struct V_21 * V_22 ;
struct V_15 * V_15 ;
bool V_23 ;
struct V_24 * V_25 = & V_20 -> V_25 ;
V_22 = F_12 ( V_26 , V_25 ) ;
if ( ! V_22 )
return - V_27 ;
V_23 = F_13 ( V_25 -> V_28 , L_1 ) ;
if ( V_23 ) {
V_29 . V_30 = V_31 ;
V_29 . V_14 . V_2 . V_32 = & V_33 ;
V_29 . V_34 [ 0 ] . V_35 = V_36 ;
V_29 . V_34 [ 1 ] . V_35 = V_36 ;
}
V_15 = F_14 ( V_20 , V_22 -> V_37 ) ;
if ( F_15 ( V_15 ) )
return F_16 ( V_15 ) ;
F_17 ( & V_38 , V_15 , & V_39 , false ) ;
return F_18 ( V_20 , V_22 -> V_37 , V_15 ) ;
}
static int F_19 ( struct V_19 * V_20 )
{
F_20 ( V_20 ) ;
return 0 ;
}
