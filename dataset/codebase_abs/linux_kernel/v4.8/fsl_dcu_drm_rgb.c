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
static int F_17 ( struct V_21 * V_22 )
{
struct V_23 * V_29 ;
int (* F_18)( struct V_30 * V_25 );
int V_31 = 0 ;
V_29 = F_12 ( V_22 ) ;
if ( V_29 -> V_25 && V_29 -> V_25 -> V_32 &&
V_29 -> V_25 -> V_32 -> F_18 ) {
F_18 = V_29 -> V_25 -> V_32 -> F_18 ;
V_31 = F_18 ( V_29 -> V_25 ) ;
}
return V_31 ;
}
static int F_19 ( struct V_21 * V_22 ,
struct V_33 * V_34 )
{
if ( V_34 -> V_35 & 0xf )
return V_36 ;
return V_37 ;
}
static int F_20 ( struct V_9 * V_10 ,
struct V_30 * V_25 )
{
struct V_1 * V_2 = & V_10 -> V_2 ;
struct V_21 * V_22 = & V_10 -> V_22 . V_38 ;
struct V_39 * V_40 = & V_10 -> V_17 -> V_40 ;
int V_15 ;
V_10 -> V_22 . V_2 = V_2 ;
V_15 = F_21 ( V_10 -> V_17 , V_22 ,
& V_41 ,
V_42 ) ;
if ( V_15 < 0 )
return V_15 ;
F_22 ( V_22 , & V_43 ) ;
V_15 = F_23 ( V_22 ) ;
if ( V_15 < 0 )
goto V_44;
V_15 = F_24 ( V_22 , V_2 ) ;
if ( V_15 < 0 )
goto V_45;
F_25 ( & V_22 -> V_38 ,
V_40 -> V_46 ,
V_47 ) ;
V_15 = F_26 ( V_25 , V_22 ) ;
if ( V_15 ) {
F_27 ( V_10 -> V_8 , L_1 ) ;
goto V_45;
}
return 0 ;
V_45:
F_13 ( V_22 ) ;
V_44:
F_15 ( V_22 ) ;
return V_15 ;
}
static int F_28 ( struct V_9 * V_10 ,
const struct V_48 * V_49 )
{
struct V_50 * V_51 ;
struct V_52 * V_53 ;
V_53 = F_29 ( V_49 -> V_54 ) ;
V_10 -> V_22 . V_25 = F_30 ( V_53 ) ;
if ( V_10 -> V_22 . V_25 ) {
F_31 ( V_53 ) ;
return F_20 ( V_10 , V_10 -> V_22 . V_25 ) ;
}
V_51 = F_32 ( V_53 ) ;
F_31 ( V_53 ) ;
if ( ! V_51 )
return - V_55 ;
V_10 -> V_2 . V_51 = V_51 ;
V_51 -> V_2 = & V_10 -> V_2 ;
return F_33 ( V_10 -> V_17 , V_51 ) ;
}
int F_34 ( struct V_9 * V_10 )
{
struct V_48 V_49 ;
struct V_52 * V_56 , * V_57 ;
int V_15 ;
V_57 = F_35 ( V_10 -> V_53 , L_2 , 0 ) ;
if ( V_57 ) {
V_10 -> V_22 . V_25 = F_30 ( V_57 ) ;
F_31 ( V_57 ) ;
if ( ! V_10 -> V_22 . V_25 )
return - V_58 ;
return F_20 ( V_10 , V_10 -> V_22 . V_25 ) ;
}
V_56 = F_36 ( V_10 -> V_53 , NULL ) ;
if ( ! V_56 )
return - V_55 ;
V_15 = F_37 ( V_56 , & V_49 ) ;
F_31 ( V_56 ) ;
if ( V_15 )
return - V_55 ;
return F_28 ( V_10 , & V_49 ) ;
}
