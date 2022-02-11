static int
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
return 0 ;
}
static void F_2 ( struct V_1 * V_2 )
{
}
static void F_3 ( struct V_1 * V_2 )
{
}
static void F_4 ( struct V_1 * V_2 )
{
F_5 ( V_2 ) ;
}
int F_6 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
int V_11 ;
V_2 -> V_12 = 1 ;
V_11 = F_7 ( V_8 -> V_13 , V_2 , & V_14 ,
V_15 , NULL ) ;
if ( V_11 < 0 )
return V_11 ;
F_8 ( V_2 , & V_16 ) ;
return 0 ;
}
static void F_9 ( struct V_17 * V_18 )
{
F_10 ( V_18 ) ;
F_11 ( V_18 ) ;
}
static enum V_19
F_12 ( struct V_17 * V_18 , bool V_20 )
{
return V_21 ;
}
static struct V_1 *
F_13 ( struct V_17 * V_18 )
{
struct V_22 * V_23 = F_14 ( V_18 ) ;
return V_23 -> V_2 ;
}
static int F_15 ( struct V_17 * V_18 )
{
struct V_22 * V_24 ;
int (* F_16)( struct V_25 * V_26 );
int V_27 = 0 ;
V_24 = F_14 ( V_18 ) ;
if ( V_24 -> V_26 && V_24 -> V_26 -> V_28 &&
V_24 -> V_26 -> V_28 -> F_16 ) {
F_16 = V_24 -> V_26 -> V_28 -> F_16 ;
V_27 = F_16 ( V_24 -> V_26 ) ;
}
return V_27 ;
}
static int F_17 ( struct V_17 * V_18 ,
struct V_29 * V_30 )
{
if ( V_30 -> V_31 & 0xf )
return V_32 ;
return V_33 ;
}
int F_18 ( struct V_7 * V_8 ,
struct V_1 * V_2 )
{
struct V_17 * V_18 = & V_8 -> V_18 . V_34 ;
struct V_35 V_36 = V_8 -> V_13 -> V_36 ;
struct V_37 * V_38 ;
int V_11 ;
V_8 -> V_18 . V_2 = V_2 ;
V_11 = F_19 ( V_8 -> V_13 , V_18 ,
& V_39 ,
V_40 ) ;
if ( V_11 < 0 )
return V_11 ;
F_20 ( V_18 , & V_41 ) ;
V_11 = F_21 ( V_18 ) ;
if ( V_11 < 0 )
goto V_42;
V_11 = F_22 ( V_18 , V_2 ) ;
if ( V_11 < 0 )
goto V_43;
F_23 ( & V_18 -> V_34 ,
V_36 . V_44 ,
V_45 ) ;
V_38 = F_24 ( V_8 -> V_46 , L_1 , 0 ) ;
if ( V_38 ) {
V_8 -> V_18 . V_26 = F_25 ( V_38 ) ;
if ( ! V_8 -> V_18 . V_26 ) {
V_11 = - V_47 ;
goto V_43;
}
F_26 ( V_38 ) ;
}
V_11 = F_27 ( V_8 -> V_18 . V_26 , V_18 ) ;
if ( V_11 ) {
F_28 ( V_8 -> V_48 , L_2 ) ;
goto V_43;
}
return 0 ;
V_43:
F_10 ( V_18 ) ;
V_42:
F_11 ( V_18 ) ;
return V_11 ;
}
