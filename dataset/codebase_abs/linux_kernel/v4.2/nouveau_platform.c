static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 -> V_4 ) ;
if ( V_3 )
goto V_5;
V_3 = F_3 ( V_2 -> V_6 ) ;
if ( V_3 )
goto V_7;
V_3 = F_3 ( V_2 -> V_8 ) ;
if ( V_3 )
goto V_9;
F_4 ( V_2 -> V_8 , 204000000 ) ;
F_5 ( 10 ) ;
F_6 ( V_2 -> V_10 ) ;
F_5 ( 10 ) ;
V_3 = F_7 ( V_11 ) ;
if ( V_3 )
goto V_12;
F_5 ( 10 ) ;
F_8 ( V_2 -> V_10 ) ;
F_5 ( 10 ) ;
return 0 ;
V_12:
F_9 ( V_2 -> V_8 ) ;
V_9:
F_9 ( V_2 -> V_6 ) ;
V_7:
F_10 ( V_2 -> V_4 ) ;
V_5:
return V_3 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_3 ;
F_6 ( V_2 -> V_10 ) ;
F_5 ( 10 ) ;
F_9 ( V_2 -> V_8 ) ;
F_9 ( V_2 -> V_6 ) ;
F_5 ( 10 ) ;
V_3 = F_10 ( V_2 -> V_4 ) ;
if ( V_3 )
return V_3 ;
return 0 ;
}
static void F_12 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
int V_3 ;
unsigned long V_15 ;
F_13 ( & V_2 -> V_16 . V_17 ) ;
if ( F_14 ( & V_18 ) ) {
V_2 -> V_16 . V_19 = F_15 ( & V_18 ) ;
if ( F_16 ( V_2 -> V_16 . V_19 ) )
goto error;
V_15 = V_2 -> V_16 . V_19 -> V_20 -> V_15 ;
if ( V_15 & V_21 ) {
V_2 -> V_16 . V_22 = V_23 ;
} else {
V_2 -> V_16 . V_22 = F_17 ( V_15 & ~ V_24 ) ;
if ( V_2 -> V_16 . V_22 == 0 ) {
F_18 ( V_14 , L_1 ) ;
goto V_25;
}
V_2 -> V_16 . V_22 -= 1 ;
}
V_3 = F_19 ( V_2 -> V_16 . V_19 , V_14 ) ;
if ( V_3 )
goto V_25;
V_3 = F_20 ( & V_2 -> V_16 . V_26 , 0 ,
( 1ULL << 40 ) >> V_2 -> V_16 . V_22 , 1 ) ;
if ( V_3 )
goto V_27;
V_2 -> V_16 . V_28 = & V_2 -> V_16 . V_26 ;
}
return;
V_27:
F_21 ( V_2 -> V_16 . V_19 , V_14 ) ;
V_25:
F_22 ( V_2 -> V_16 . V_19 ) ;
error:
V_2 -> V_16 . V_19 = NULL ;
V_2 -> V_16 . V_22 = 0 ;
F_23 ( V_14 , L_2 ) ;
}
static void F_24 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
if ( V_2 -> V_16 . V_19 ) {
F_25 ( & V_2 -> V_16 . V_26 ) ;
F_21 ( V_2 -> V_16 . V_19 , V_14 ) ;
F_22 ( V_2 -> V_16 . V_19 ) ;
}
}
static void F_12 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
}
static void F_24 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
}
static int F_26 ( struct V_29 * V_30 )
{
struct V_1 * V_2 ;
struct V_31 * V_13 ;
struct V_32 * V_33 ;
int V_3 ;
V_2 = F_27 ( & V_30 -> V_14 , sizeof( * V_2 ) , V_34 ) ;
if ( ! V_2 )
return - V_35 ;
V_2 -> V_4 = F_28 ( & V_30 -> V_14 , L_3 ) ;
if ( F_16 ( V_2 -> V_4 ) )
return F_29 ( V_2 -> V_4 ) ;
V_2 -> V_10 = F_30 ( & V_30 -> V_14 , L_4 ) ;
if ( F_16 ( V_2 -> V_10 ) )
return F_29 ( V_2 -> V_10 ) ;
V_2 -> V_6 = F_31 ( & V_30 -> V_14 , L_4 ) ;
if ( F_16 ( V_2 -> V_6 ) )
return F_29 ( V_2 -> V_6 ) ;
V_2 -> V_8 = F_31 ( & V_30 -> V_14 , L_5 ) ;
if ( F_16 ( V_2 -> V_8 ) )
return F_29 ( V_2 -> V_8 ) ;
F_12 ( & V_30 -> V_14 , V_2 ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 )
return V_3 ;
V_33 = F_32 ( V_30 , & V_13 ) ;
if ( F_16 ( V_33 ) ) {
V_3 = F_29 ( V_33 ) ;
goto V_36;
}
V_13 -> V_2 = V_2 ;
V_13 -> V_37 = V_38 . V_39 ;
V_3 = F_33 ( V_33 , 0 ) ;
if ( V_3 < 0 )
goto V_40;
return 0 ;
V_40:
F_34 ( V_33 ) ;
V_36:
F_11 ( V_2 ) ;
F_24 ( & V_30 -> V_14 , V_2 ) ;
return V_3 ;
}
static int F_35 ( struct V_29 * V_30 )
{
struct V_32 * V_41 = F_36 ( V_30 ) ;
struct V_42 * V_33 = V_42 ( V_41 ) ;
struct V_43 * V_13 = F_37 ( & V_33 -> V_13 ) ;
struct V_1 * V_2 = F_38 ( V_13 ) -> V_2 ;
int V_3 ;
F_39 ( V_41 ) ;
V_3 = F_11 ( V_2 ) ;
F_24 ( & V_30 -> V_14 , V_2 ) ;
return V_3 ;
}
