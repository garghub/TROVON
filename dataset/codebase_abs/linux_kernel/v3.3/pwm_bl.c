static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
int V_6 = V_2 -> V_7 . V_6 ;
int V_8 = V_2 -> V_7 . V_9 ;
if ( V_2 -> V_7 . V_10 != V_11 )
V_6 = 0 ;
if ( V_2 -> V_7 . V_12 != V_11 )
V_6 = 0 ;
if ( V_4 -> V_13 )
V_6 = V_4 -> V_13 ( V_4 -> V_5 , V_6 ) ;
if ( V_6 == 0 ) {
F_3 ( V_4 -> V_14 , 0 , V_4 -> V_15 ) ;
F_4 ( V_4 -> V_14 ) ;
} else {
V_6 = V_4 -> V_16 +
( V_6 * ( V_4 -> V_15 - V_4 -> V_16 ) / V_8 ) ;
F_3 ( V_4 -> V_14 , V_6 , V_4 -> V_15 ) ;
F_5 ( V_4 -> V_14 ) ;
}
if ( V_4 -> V_17 )
V_4 -> V_17 ( V_4 -> V_5 , V_6 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
return V_2 -> V_7 . V_6 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
return ! V_4 -> V_20 || V_4 -> V_20 ( V_4 -> V_5 , V_19 ) ;
}
static int F_8 ( struct V_21 * V_22 )
{
struct V_23 V_7 ;
struct V_24 * V_25 = V_22 -> V_5 . V_26 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_27 ;
if ( ! V_25 ) {
F_9 ( & V_22 -> V_5 , L_1 ) ;
return - V_28 ;
}
if ( V_25 -> V_29 ) {
V_27 = V_25 -> V_29 ( & V_22 -> V_5 ) ;
if ( V_27 < 0 )
return V_27 ;
}
V_4 = F_10 ( sizeof( * V_4 ) , V_30 ) ;
if ( ! V_4 ) {
F_9 ( & V_22 -> V_5 , L_2 ) ;
V_27 = - V_31 ;
goto V_32;
}
V_4 -> V_15 = V_25 -> V_33 ;
V_4 -> V_13 = V_25 -> V_13 ;
V_4 -> V_17 = V_25 -> V_17 ;
V_4 -> V_20 = V_25 -> V_20 ;
V_4 -> V_16 = V_25 -> V_16 *
( V_25 -> V_33 / V_25 -> V_9 ) ;
V_4 -> V_5 = & V_22 -> V_5 ;
V_4 -> V_14 = F_11 ( V_25 -> V_34 , L_3 ) ;
if ( F_12 ( V_4 -> V_14 ) ) {
F_9 ( & V_22 -> V_5 , L_4 ) ;
V_27 = F_13 ( V_4 -> V_14 ) ;
goto V_35;
} else
F_14 ( & V_22 -> V_5 , L_5 ) ;
memset ( & V_7 , 0 , sizeof( struct V_23 ) ) ;
V_7 . type = V_36 ;
V_7 . V_9 = V_25 -> V_9 ;
V_2 = F_15 ( F_16 ( & V_22 -> V_5 ) , & V_22 -> V_5 , V_4 ,
& V_37 , & V_7 ) ;
if ( F_12 ( V_2 ) ) {
F_9 ( & V_22 -> V_5 , L_6 ) ;
V_27 = F_13 ( V_2 ) ;
goto V_38;
}
V_2 -> V_7 . V_6 = V_25 -> V_39 ;
F_17 ( V_2 ) ;
F_18 ( V_22 , V_2 ) ;
return 0 ;
V_38:
F_19 ( V_4 -> V_14 ) ;
V_35:
F_20 ( V_4 ) ;
V_32:
if ( V_25 -> exit )
V_25 -> exit ( & V_22 -> V_5 ) ;
return V_27 ;
}
static int F_21 ( struct V_21 * V_22 )
{
struct V_24 * V_25 = V_22 -> V_5 . V_26 ;
struct V_1 * V_2 = F_22 ( V_22 ) ;
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
F_23 ( V_2 ) ;
F_3 ( V_4 -> V_14 , 0 , V_4 -> V_15 ) ;
F_4 ( V_4 -> V_14 ) ;
F_19 ( V_4 -> V_14 ) ;
F_20 ( V_4 ) ;
if ( V_25 -> exit )
V_25 -> exit ( & V_22 -> V_5 ) ;
return 0 ;
}
static int F_24 ( struct V_40 * V_5 )
{
struct V_1 * V_2 = F_2 ( V_5 ) ;
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
if ( V_4 -> V_13 )
V_4 -> V_13 ( V_4 -> V_5 , 0 ) ;
F_3 ( V_4 -> V_14 , 0 , V_4 -> V_15 ) ;
F_4 ( V_4 -> V_14 ) ;
if ( V_4 -> V_17 )
V_4 -> V_17 ( V_4 -> V_5 , 0 ) ;
return 0 ;
}
static int F_25 ( struct V_40 * V_5 )
{
struct V_1 * V_2 = F_2 ( V_5 ) ;
F_17 ( V_2 ) ;
return 0 ;
}
