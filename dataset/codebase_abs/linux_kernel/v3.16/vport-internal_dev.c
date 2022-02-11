static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 ) ;
}
static struct V_4 * F_3 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_6 = F_4 ( V_3 ) ;
struct V_7 V_8 ;
F_5 ( V_6 , & V_8 ) ;
V_5 -> V_9 = V_8 . V_10 ;
V_5 -> V_10 = V_8 . V_9 ;
V_5 -> V_11 = V_8 . V_12 ;
V_5 -> V_12 = V_8 . V_11 ;
V_5 -> V_13 = V_8 . V_14 ;
V_5 -> V_14 = V_8 . V_13 ;
V_5 -> V_15 = V_8 . V_16 ;
V_5 -> V_16 = V_8 . V_15 ;
return V_5 ;
}
static int F_6 ( struct V_17 * V_18 , struct V_2 * V_3 )
{
F_7 () ;
F_8 ( F_1 ( V_3 ) -> V_6 , V_18 , NULL ) ;
F_9 () ;
return 0 ;
}
static int F_10 ( struct V_2 * V_3 )
{
F_11 ( V_3 ) ;
return 0 ;
}
static int F_12 ( struct V_2 * V_3 )
{
F_13 ( V_3 ) ;
return 0 ;
}
static void F_14 ( struct V_2 * V_3 ,
struct V_19 * V_20 )
{
F_15 ( V_20 -> V_21 , L_1 , sizeof( V_20 -> V_21 ) ) ;
}
static int F_16 ( struct V_2 * V_3 , int V_22 )
{
if ( V_22 < 68 )
return - V_23 ;
V_3 -> V_24 = V_22 ;
return 0 ;
}
static void F_17 ( struct V_2 * V_25 )
{
struct V_6 * V_6 = F_4 ( V_25 ) ;
F_18 ( V_6 ) ;
F_19 ( V_25 ) ;
}
static void F_20 ( struct V_2 * V_3 )
{
F_21 ( V_3 ) ;
V_3 -> V_26 = & V_27 ;
V_3 -> V_28 &= ~ V_29 ;
V_3 -> V_28 |= V_30 ;
V_3 -> V_31 = F_17 ;
V_3 -> V_32 = & V_33 ;
V_3 -> V_34 = 0 ;
V_3 -> V_35 = V_36 | V_37 | V_38 |
V_39 | V_40 | V_41 ;
V_3 -> V_42 = V_3 -> V_35 ;
V_3 -> V_35 |= V_43 ;
V_3 -> V_44 = V_3 -> V_35 & ~ V_36 ;
F_22 ( V_3 ) ;
}
static struct V_6 * F_23 ( const struct V_45 * V_46 )
{
struct V_6 * V_6 ;
struct V_47 * V_47 ;
struct V_1 * V_1 ;
int V_48 ;
V_6 = F_24 ( sizeof( struct V_47 ) ,
& V_49 , V_46 ) ;
if ( F_25 ( V_6 ) ) {
V_48 = F_26 ( V_6 ) ;
goto error;
}
V_47 = F_27 ( V_6 ) ;
V_47 -> V_25 = F_28 ( sizeof( struct V_1 ) ,
V_46 -> V_50 , F_20 ) ;
if ( ! V_47 -> V_25 ) {
V_48 = - V_51 ;
goto V_52;
}
F_29 ( V_47 -> V_25 , F_30 ( V_6 -> V_53 ) ) ;
V_1 = F_1 ( V_47 -> V_25 ) ;
V_1 -> V_6 = V_6 ;
if ( V_6 -> V_54 == V_55 )
V_47 -> V_25 -> V_35 |= V_56 ;
F_31 () ;
V_48 = F_32 ( V_47 -> V_25 ) ;
if ( V_48 )
goto V_57;
F_33 ( V_47 -> V_25 , 1 ) ;
F_34 () ;
F_11 ( V_47 -> V_25 ) ;
return V_6 ;
V_57:
F_34 () ;
F_19 ( V_47 -> V_25 ) ;
V_52:
F_18 ( V_6 ) ;
error:
return F_35 ( V_48 ) ;
}
static void F_36 ( struct V_6 * V_6 )
{
struct V_47 * V_47 = F_27 ( V_6 ) ;
F_13 ( V_47 -> V_25 ) ;
F_31 () ;
F_33 ( V_47 -> V_25 , - 1 ) ;
F_37 ( V_47 -> V_25 ) ;
F_34 () ;
}
static int F_38 ( struct V_6 * V_6 , struct V_17 * V_18 )
{
struct V_2 * V_3 = F_27 ( V_6 ) -> V_25 ;
int V_58 ;
V_58 = V_18 -> V_58 ;
F_39 ( V_18 ) ;
F_40 ( V_18 ) ;
F_41 ( V_18 ) ;
V_18 -> V_25 = V_3 ;
V_18 -> V_59 = V_60 ;
V_18 -> V_61 = F_42 ( V_18 , V_3 ) ;
F_43 ( V_18 , F_44 ( V_18 ) , V_62 ) ;
F_45 ( V_18 ) ;
return V_58 ;
}
int F_46 ( const struct V_2 * V_3 )
{
return V_3 -> V_26 == & V_27 ;
}
struct V_6 * F_4 ( struct V_2 * V_3 )
{
if ( ! F_46 ( V_3 ) )
return NULL ;
return F_1 ( V_3 ) -> V_6 ;
}
