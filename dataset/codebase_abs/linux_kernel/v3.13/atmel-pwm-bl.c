static void F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( ! F_2 ( V_2 -> V_4 ) )
return;
F_3 ( V_2 -> V_4 , V_3 ^ V_2 -> V_5 -> V_6 ) ;
}
static int F_4 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_5 ( V_8 ) ;
int V_9 = V_8 -> V_10 . V_11 ;
int V_12 ;
if ( V_8 -> V_10 . V_13 != V_14 )
V_9 = 0 ;
if ( V_8 -> V_10 . V_15 != V_14 )
V_9 = 0 ;
if ( V_2 -> V_5 -> V_16 )
V_12 = V_2 -> V_5 -> V_17 + V_9 ;
else
V_12 = V_2 -> V_5 -> V_18 - V_9 ;
if ( V_12 > V_2 -> V_5 -> V_18 )
V_12 = V_2 -> V_5 -> V_18 ;
if ( V_12 < V_2 -> V_5 -> V_17 )
V_12 = V_2 -> V_5 -> V_17 ;
if ( ! V_9 ) {
F_1 ( V_2 , 0 ) ;
F_6 ( & V_2 -> V_19 , V_20 , V_12 ) ;
F_7 ( & V_2 -> V_19 ) ;
} else {
F_8 ( & V_2 -> V_19 ) ;
F_6 ( & V_2 -> V_19 , V_20 , V_12 ) ;
F_1 ( V_2 , 1 ) ;
}
return 0 ;
}
static int F_9 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_5 ( V_8 ) ;
T_1 V_21 ;
T_1 V_9 ;
V_21 = F_10 ( & V_2 -> V_19 , V_22 ) ;
if ( V_2 -> V_5 -> V_16 )
V_9 = V_21 - V_2 -> V_5 -> V_17 ;
else
V_9 = V_2 -> V_5 -> V_18 - V_21 ;
return V_9 & 0xffff ;
}
static int F_11 ( struct V_1 * V_2 )
{
unsigned long V_23 = V_2 -> V_19 . V_24 ;
unsigned long V_25 = F_12 ( V_23 ,
( V_2 -> V_5 -> V_26 *
V_2 -> V_5 -> V_27 ) ) - 1 ;
V_25 = F_13 ( V_25 ) ;
if ( V_25 > 0xf )
V_25 = 0xf ;
F_6 ( & V_2 -> V_19 , V_28 , V_25 ) ;
F_6 ( & V_2 -> V_19 , V_22 ,
V_2 -> V_5 -> V_17 +
V_2 -> V_29 -> V_10 . V_11 ) ;
F_6 ( & V_2 -> V_19 , V_30 ,
V_2 -> V_5 -> V_27 ) ;
F_14 ( & V_2 -> V_31 -> V_32 , L_1 ,
V_2 -> V_19 . V_24 / V_2 -> V_5 -> V_27 /
( 1 << V_25 ) ) ;
return F_8 ( & V_2 -> V_19 ) ;
}
static int F_15 ( struct V_33 * V_31 )
{
struct V_34 V_10 ;
const struct V_35 * V_5 ;
struct V_7 * V_29 ;
struct V_1 * V_2 ;
unsigned long V_36 ;
int V_37 ;
V_5 = F_16 ( & V_31 -> V_32 ) ;
if ( ! V_5 )
return - V_38 ;
if ( V_5 -> V_27 < V_5 -> V_18 ||
V_5 -> V_17 > V_5 -> V_18 ||
V_5 -> V_26 == 0 )
return - V_39 ;
V_2 = F_17 ( & V_31 -> V_32 , sizeof( struct V_1 ) ,
V_40 ) ;
if ( ! V_2 )
return - V_41 ;
V_2 -> V_31 = V_31 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_4 = V_5 -> V_4 ;
V_37 = F_18 ( V_5 -> V_42 , & V_2 -> V_19 ) ;
if ( V_37 )
return V_37 ;
if ( F_2 ( V_2 -> V_4 ) ) {
if ( V_5 -> V_6 )
V_36 = V_43 ;
else
V_36 = V_44 ;
V_37 = F_19 ( & V_31 -> V_32 , V_2 -> V_4 ,
V_36 , L_2 ) ;
if ( V_37 )
goto V_45;
}
memset ( & V_10 , 0 , sizeof( struct V_34 ) ) ;
V_10 . type = V_46 ;
V_10 . V_47 = V_5 -> V_18 - V_5 -> V_17 ;
V_29 = F_20 ( & V_31 -> V_32 , L_3 ,
& V_31 -> V_32 , V_2 , & V_48 ,
& V_10 ) ;
if ( F_21 ( V_29 ) ) {
V_37 = F_22 ( V_29 ) ;
goto V_45;
}
V_2 -> V_29 = V_29 ;
F_23 ( V_31 , V_2 ) ;
V_29 -> V_10 . V_13 = V_14 ;
V_29 -> V_10 . V_11 = V_29 -> V_10 . V_47 / 2 ;
V_37 = F_11 ( V_2 ) ;
if ( V_37 )
goto V_45;
F_4 ( V_29 ) ;
return 0 ;
V_45:
F_24 ( & V_2 -> V_19 ) ;
return V_37 ;
}
static int F_25 ( struct V_33 * V_31 )
{
struct V_1 * V_2 = F_26 ( V_31 ) ;
F_1 ( V_2 , 0 ) ;
F_7 ( & V_2 -> V_19 ) ;
F_24 ( & V_2 -> V_19 ) ;
return 0 ;
}
