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
static enum V_18
F_11 ( struct V_13 * V_14 , bool V_19 )
{
return V_20 ;
}
static int F_12 ( struct V_13 * V_14 )
{
struct V_15 * V_21 ;
int (* F_13)( struct V_22 * V_17 );
int V_23 = 0 ;
V_21 = F_7 ( V_14 ) ;
if ( V_21 -> V_17 && V_21 -> V_17 -> V_24 &&
V_21 -> V_17 -> V_24 -> F_13 ) {
F_13 = V_21 -> V_17 -> V_24 -> F_13 ;
V_23 = F_13 ( V_21 -> V_17 ) ;
}
return V_23 ;
}
static int F_14 ( struct V_13 * V_14 ,
struct V_25 * V_26 )
{
if ( V_26 -> V_27 & 0xf )
return V_28 ;
return V_29 ;
}
static int F_15 ( struct V_3 * V_4 ,
struct V_22 * V_17 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
struct V_13 * V_14 = & V_4 -> V_14 . V_30 ;
struct V_31 * V_32 = & V_4 -> V_10 -> V_32 ;
int V_7 ;
V_4 -> V_14 . V_2 = V_2 ;
V_7 = F_16 ( V_4 -> V_10 , V_14 ,
& V_33 ,
V_34 ) ;
if ( V_7 < 0 )
return V_7 ;
F_17 ( V_14 , & V_35 ) ;
V_7 = F_18 ( V_14 ) ;
if ( V_7 < 0 )
goto V_36;
V_7 = F_19 ( V_14 , V_2 ) ;
if ( V_7 < 0 )
goto V_37;
F_20 ( & V_14 -> V_30 ,
V_32 -> V_38 ,
V_39 ) ;
V_7 = F_21 ( V_17 , V_14 ) ;
if ( V_7 ) {
F_22 ( V_4 -> V_40 , L_1 ) ;
goto V_37;
}
return 0 ;
V_37:
F_8 ( V_14 ) ;
V_36:
F_10 ( V_14 ) ;
return V_7 ;
}
static int F_23 ( struct V_3 * V_4 ,
const struct V_41 * V_42 )
{
struct V_43 * V_44 ;
struct V_45 * V_46 ;
V_46 = F_24 ( V_42 -> V_47 ) ;
V_4 -> V_14 . V_17 = F_25 ( V_46 ) ;
if ( V_4 -> V_14 . V_17 ) {
F_26 ( V_46 ) ;
return F_15 ( V_4 , V_4 -> V_14 . V_17 ) ;
}
V_44 = F_27 ( V_46 ) ;
F_26 ( V_46 ) ;
if ( ! V_44 )
return - V_48 ;
V_4 -> V_2 . V_44 = V_44 ;
V_44 -> V_2 = & V_4 -> V_2 ;
return F_28 ( V_4 -> V_10 , V_44 ) ;
}
int F_29 ( struct V_3 * V_4 )
{
struct V_41 V_42 ;
struct V_45 * V_49 , * V_50 ;
int V_7 ;
V_50 = F_30 ( V_4 -> V_46 , L_2 , 0 ) ;
if ( V_50 ) {
V_4 -> V_14 . V_17 = F_25 ( V_50 ) ;
F_26 ( V_50 ) ;
if ( ! V_4 -> V_14 . V_17 )
return - V_51 ;
return F_15 ( V_4 , V_4 -> V_14 . V_17 ) ;
}
V_49 = F_31 ( V_4 -> V_46 , NULL ) ;
if ( ! V_49 )
return - V_48 ;
V_7 = F_32 ( V_49 , & V_42 ) ;
F_26 ( V_49 ) ;
if ( V_7 )
return - V_48 ;
return F_23 ( V_4 , & V_42 ) ;
}
