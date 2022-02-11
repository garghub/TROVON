static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
struct V_7 * V_8 = V_4 -> V_9 . V_10 ;
struct V_11 * V_12 = F_3 ( V_2 ) ;
int V_13 ;
if ( V_8 -> V_14 )
V_12 -> V_15 |= V_16 ;
if ( V_8 -> V_17 )
V_12 -> V_15 |= V_18 ;
if ( V_8 -> V_19 )
V_12 -> V_15 |= V_20 ;
F_4 ( V_12 ) ;
if ( V_8 -> V_21 )
V_12 -> V_21 = V_8 -> V_21 ;
V_13 = F_5 ( V_12 ) ;
return V_13 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_3 ( V_2 ) ;
int V_13 ;
V_13 = F_7 ( V_12 ) ;
if ( V_13 < 0 ) {
F_8 ( V_12 , L_1 ) ;
F_9 ( V_2 ) ;
}
return V_13 ;
}
static int F_10 ( struct V_3 * V_9 )
{
struct V_1 * V_2 ;
struct V_22 * V_23 ;
struct V_7 * V_8 = V_9 -> V_9 . V_10 ;
int V_24 ;
int V_13 = - V_25 ;
if ( ! V_8 ) {
F_11 ( 1 ) ;
return - V_26 ;
}
if ( F_12 () )
return - V_26 ;
V_24 = F_13 ( V_9 , 0 ) ;
if ( V_24 < 0 ) {
F_14 ( & V_9 -> V_9 , L_2 ) ;
return V_24 ;
}
V_23 = F_15 ( V_9 , V_27 , 0 ) ;
if ( ! V_23 ) {
F_14 ( & V_9 -> V_9 , L_3 ) ;
return - V_28 ;
}
if ( V_8 -> V_29 ) {
V_13 = V_8 -> V_29 ( V_9 ) ;
if ( V_13 < 0 )
return V_13 ;
}
V_2 = F_16 ( & V_30 , & V_9 -> V_9 ,
F_17 ( & V_9 -> V_9 ) ) ;
if ( ! V_2 ) {
V_13 = - V_25 ;
goto V_31;
}
V_2 -> V_32 = V_23 -> V_33 ;
V_2 -> V_34 = F_18 ( V_23 ) ;
V_2 -> V_35 = F_19 ( & V_9 -> V_9 , V_23 ) ;
if ( F_20 ( V_2 -> V_35 ) ) {
V_13 = F_21 ( V_2 -> V_35 ) ;
goto V_36;
}
V_13 = F_22 ( V_2 , V_24 , V_37 ) ;
if ( V_13 )
goto V_36;
F_23 ( V_9 , V_2 ) ;
return V_13 ;
V_36:
F_24 ( V_2 ) ;
V_31:
if ( V_8 -> V_38 )
V_8 -> V_38 ( V_9 ) ;
return V_13 ;
}
static int F_25 ( struct V_3 * V_9 )
{
struct V_1 * V_2 = F_26 ( V_9 ) ;
struct V_7 * V_8 = V_9 -> V_9 . V_10 ;
F_27 ( V_2 ) ;
F_24 ( V_2 ) ;
F_23 ( V_9 , NULL ) ;
if ( V_8 -> V_38 )
V_8 -> V_38 ( V_9 ) ;
return 0 ;
}
static int F_28 ( struct V_39 * V_9 )
{
struct V_7 * V_8 = V_9 -> V_10 ;
struct V_3 * V_4 =
F_29 ( V_9 , struct V_3 , V_9 ) ;
if ( V_8 -> V_40 )
V_8 -> V_40 ( V_4 ) ;
return 0 ;
}
static int F_30 ( struct V_39 * V_9 )
{
struct V_1 * V_2 = F_31 ( V_9 ) ;
struct V_7 * V_8 = V_9 -> V_10 ;
struct V_3 * V_4 =
F_29 ( V_9 , struct V_3 , V_9 ) ;
if ( V_8 -> V_29 ) {
int V_13 = V_8 -> V_29 ( V_4 ) ;
if ( V_13 < 0 )
return V_13 ;
}
F_32 ( V_2 , false ) ;
return 0 ;
}
