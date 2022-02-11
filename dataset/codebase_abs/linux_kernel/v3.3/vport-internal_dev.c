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
static int F_6 ( struct V_2 * V_17 , void * V_18 )
{
struct V_19 * V_20 = V_18 ;
if ( ! F_7 ( V_20 -> V_21 ) )
return - V_22 ;
memcpy ( V_17 -> V_23 , V_20 -> V_21 , V_17 -> V_24 ) ;
return 0 ;
}
static int F_8 ( struct V_25 * V_26 , struct V_2 * V_3 )
{
F_9 () ;
F_10 ( F_1 ( V_3 ) -> V_6 , V_26 ) ;
F_11 () ;
return 0 ;
}
static int F_12 ( struct V_2 * V_3 )
{
F_13 ( V_3 ) ;
return 0 ;
}
static int F_14 ( struct V_2 * V_3 )
{
F_15 ( V_3 ) ;
return 0 ;
}
static void F_16 ( struct V_2 * V_3 ,
struct V_27 * V_28 )
{
strcpy ( V_28 -> V_29 , L_1 ) ;
}
static int F_17 ( struct V_2 * V_3 , int V_30 )
{
if ( V_30 < 68 )
return - V_31 ;
V_3 -> V_32 = V_30 ;
return 0 ;
}
static void F_18 ( struct V_2 * V_17 )
{
struct V_6 * V_6 = F_4 ( V_17 ) ;
F_19 ( V_6 ) ;
F_20 ( V_17 ) ;
}
static void F_21 ( struct V_2 * V_3 )
{
F_22 ( V_3 ) ;
V_3 -> V_33 = & V_34 ;
V_3 -> V_35 &= ~ V_36 ;
V_3 -> V_37 = F_18 ;
F_23 ( V_3 , & V_38 ) ;
V_3 -> V_39 = 0 ;
V_3 -> V_40 = V_41 | V_42 | V_43 |
V_44 | V_45 | V_46 ;
V_3 -> V_47 = V_3 -> V_40 ;
V_3 -> V_40 |= V_48 ;
V_3 -> V_49 = V_3 -> V_40 & ~ V_41 ;
F_24 ( V_3 -> V_23 ) ;
}
static struct V_6 * F_25 ( const struct V_50 * V_51 )
{
struct V_6 * V_6 ;
struct V_52 * V_52 ;
struct V_1 * V_1 ;
int V_53 ;
V_6 = F_26 ( sizeof( struct V_52 ) ,
& V_54 , V_51 ) ;
if ( F_27 ( V_6 ) ) {
V_53 = F_28 ( V_6 ) ;
goto error;
}
V_52 = F_29 ( V_6 ) ;
V_52 -> V_17 = F_30 ( sizeof( struct V_1 ) ,
V_51 -> V_55 , F_21 ) ;
if ( ! V_52 -> V_17 ) {
V_53 = - V_56 ;
goto V_57;
}
V_1 = F_1 ( V_52 -> V_17 ) ;
V_1 -> V_6 = V_6 ;
V_53 = F_31 ( V_52 -> V_17 ) ;
if ( V_53 )
goto V_58;
F_32 ( V_52 -> V_17 , 1 ) ;
F_13 ( V_52 -> V_17 ) ;
return V_6 ;
V_58:
F_20 ( V_52 -> V_17 ) ;
V_57:
F_19 ( V_6 ) ;
error:
return F_33 ( V_53 ) ;
}
static void F_34 ( struct V_6 * V_6 )
{
struct V_52 * V_52 = F_29 ( V_6 ) ;
F_15 ( V_52 -> V_17 ) ;
F_32 ( V_52 -> V_17 , - 1 ) ;
F_35 ( V_52 -> V_17 ) ;
}
static int F_36 ( struct V_6 * V_6 , struct V_25 * V_26 )
{
struct V_2 * V_3 = F_29 ( V_6 ) -> V_17 ;
int V_59 ;
V_59 = V_26 -> V_59 ;
V_26 -> V_17 = V_3 ;
V_26 -> V_60 = V_61 ;
V_26 -> V_62 = F_37 ( V_26 , V_3 ) ;
F_38 ( V_26 ) ;
return V_59 ;
}
int F_39 ( const struct V_2 * V_3 )
{
return V_3 -> V_33 == & V_34 ;
}
struct V_6 * F_4 ( struct V_2 * V_3 )
{
if ( ! F_39 ( V_3 ) )
return NULL ;
return F_1 ( V_3 ) -> V_6 ;
}
