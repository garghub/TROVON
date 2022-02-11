static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
}
int F_3 ( struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
int V_7 ;
V_2 -> V_8 = 1 ;
if ( V_4 -> V_9 )
F_4 ( V_4 -> V_9 ) ;
V_7 = F_5 ( V_4 -> V_10 , V_2 , & V_11 ,
V_12 , NULL ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static void F_6 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_7 ( V_14 ) ;
F_8 ( V_14 ) ;
F_9 ( V_16 -> V_17 ) ;
F_10 ( V_14 ) ;
}
static int F_11 ( struct V_13 * V_14 )
{
struct V_15 * V_18 ;
int (* F_12)( struct V_19 * V_17 );
int V_20 = 0 ;
V_18 = F_7 ( V_14 ) ;
if ( V_18 -> V_17 && V_18 -> V_17 -> V_21 &&
V_18 -> V_17 -> V_21 -> F_12 ) {
F_12 = V_18 -> V_17 -> V_21 -> F_12 ;
V_20 = F_12 ( V_18 -> V_17 ) ;
}
return V_20 ;
}
static int F_13 ( struct V_13 * V_14 ,
struct V_22 * V_23 )
{
if ( V_23 -> V_24 & 0xf )
return V_25 ;
return V_26 ;
}
static int F_14 ( struct V_3 * V_4 ,
struct V_19 * V_17 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
struct V_13 * V_14 = & V_4 -> V_14 . V_27 ;
struct V_28 * V_29 = & V_4 -> V_10 -> V_29 ;
int V_7 ;
V_4 -> V_14 . V_2 = V_2 ;
V_7 = F_15 ( V_4 -> V_10 , V_14 ,
& V_30 ,
V_31 ) ;
if ( V_7 < 0 )
return V_7 ;
F_16 ( V_14 , & V_32 ) ;
V_7 = F_17 ( V_14 ) ;
if ( V_7 < 0 )
goto V_33;
V_7 = F_18 ( V_14 , V_2 ) ;
if ( V_7 < 0 )
goto V_34;
F_19 ( & V_14 -> V_27 ,
V_29 -> V_35 ,
V_36 ) ;
V_7 = F_20 ( V_17 , V_14 ) ;
if ( V_7 ) {
F_21 ( V_4 -> V_37 , L_1 ) ;
goto V_34;
}
return 0 ;
V_34:
F_8 ( V_14 ) ;
V_33:
F_10 ( V_14 ) ;
return V_7 ;
}
int F_22 ( struct V_3 * V_4 )
{
struct V_38 * V_39 ;
struct V_19 * V_17 ;
struct V_40 * V_41 ;
int V_7 ;
V_39 = F_23 ( V_4 -> V_42 , L_2 , 0 ) ;
if ( V_39 ) {
V_4 -> V_14 . V_17 = F_24 ( V_39 ) ;
F_25 ( V_39 ) ;
if ( ! V_4 -> V_14 . V_17 )
return - V_43 ;
return F_14 ( V_4 , V_4 -> V_14 . V_17 ) ;
}
V_7 = F_26 ( V_4 -> V_42 , 0 , 0 , & V_17 , & V_41 ) ;
if ( V_7 )
return V_7 ;
if ( V_17 ) {
V_4 -> V_14 . V_17 = V_17 ;
return F_14 ( V_4 , V_17 ) ;
}
return F_27 ( & V_4 -> V_2 , V_41 , NULL ) ;
}
