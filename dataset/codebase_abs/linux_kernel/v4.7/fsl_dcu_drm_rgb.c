static int
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
return 0 ;
}
static void F_2 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 = V_8 -> V_11 ;
if ( V_10 -> V_12 )
F_3 ( V_10 -> V_12 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 = V_8 -> V_11 ;
if ( V_10 -> V_12 )
F_5 ( V_10 -> V_12 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_2 ) ;
}
int F_8 ( struct V_9 * V_10 ,
struct V_13 * V_14 )
{
struct V_1 * V_2 = & V_10 -> V_2 ;
int V_15 ;
V_2 -> V_16 = 1 ;
V_15 = F_9 ( V_10 -> V_17 , V_2 , & V_18 ,
V_19 , NULL ) ;
if ( V_15 < 0 )
return V_15 ;
F_10 ( V_2 , & V_20 ) ;
return 0 ;
}
static void F_11 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = F_12 ( V_22 ) ;
F_13 ( V_22 ) ;
F_14 ( V_24 -> V_25 ) ;
F_15 ( V_22 ) ;
}
static enum V_26
F_16 ( struct V_21 * V_22 , bool V_27 )
{
return V_28 ;
}
static struct V_1 *
F_17 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = F_12 ( V_22 ) ;
return V_24 -> V_2 ;
}
static int F_18 ( struct V_21 * V_22 )
{
struct V_23 * V_29 ;
int (* F_19)( struct V_30 * V_25 );
int V_31 = 0 ;
V_29 = F_12 ( V_22 ) ;
if ( V_29 -> V_25 && V_29 -> V_25 -> V_32 &&
V_29 -> V_25 -> V_32 -> F_19 ) {
F_19 = V_29 -> V_25 -> V_32 -> F_19 ;
V_31 = F_19 ( V_29 -> V_25 ) ;
}
return V_31 ;
}
static int F_20 ( struct V_21 * V_22 ,
struct V_33 * V_34 )
{
if ( V_34 -> V_35 & 0xf )
return V_36 ;
return V_37 ;
}
int F_21 ( struct V_9 * V_10 ,
struct V_1 * V_2 )
{
struct V_21 * V_22 = & V_10 -> V_22 . V_38 ;
struct V_39 * V_40 = & V_10 -> V_17 -> V_40 ;
struct V_41 * V_42 ;
int V_15 ;
V_10 -> V_22 . V_2 = V_2 ;
V_15 = F_22 ( V_10 -> V_17 , V_22 ,
& V_43 ,
V_44 ) ;
if ( V_15 < 0 )
return V_15 ;
F_23 ( V_22 , & V_45 ) ;
V_15 = F_24 ( V_22 ) ;
if ( V_15 < 0 )
goto V_46;
V_15 = F_25 ( V_22 , V_2 ) ;
if ( V_15 < 0 )
goto V_47;
F_26 ( & V_22 -> V_38 ,
V_40 -> V_48 ,
V_49 ) ;
V_42 = F_27 ( V_10 -> V_50 , L_1 , 0 ) ;
if ( ! V_42 ) {
F_28 ( V_10 -> V_8 , L_2 ) ;
V_15 = - V_51 ;
goto V_47;
}
V_10 -> V_22 . V_25 = F_29 ( V_42 ) ;
if ( ! V_10 -> V_22 . V_25 ) {
V_15 = - V_52 ;
goto V_53;
}
F_30 ( V_42 ) ;
V_15 = F_31 ( V_10 -> V_22 . V_25 , V_22 ) ;
if ( V_15 ) {
F_28 ( V_10 -> V_8 , L_3 ) ;
goto V_47;
}
return 0 ;
V_53:
F_30 ( V_42 ) ;
V_47:
F_13 ( V_22 ) ;
V_46:
F_15 ( V_22 ) ;
return V_15 ;
}
