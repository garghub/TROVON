static int F_1 ( struct V_1 * V_2 , const unsigned char * V_3 ,
const unsigned char * V_4 , T_1 V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_9 = F_2 ( V_7 ) ;
if ( ! F_3 ( V_10 , & V_9 -> V_11 ) )
return 0 ;
return F_4 ( V_7 , V_3 , V_5 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_9 = F_2 ( V_7 ) ;
if ( ! F_6 ( V_12 , & V_2 -> V_13 -> V_11 ) )
return;
if ( F_3 ( V_10 , & V_9 -> V_11 ) )
F_7 ( V_7 ) ;
}
static int F_8 ( struct V_6 * V_7 , const unsigned char * V_14 , T_1 V_15 )
{
struct V_9 * V_9 = F_2 ( V_7 ) ;
struct V_16 * V_13 = V_9 -> V_13 ;
if ( ! F_3 ( V_10 , & V_9 -> V_11 ) )
return 0 ;
F_9 ( V_12 , & V_13 -> V_11 ) ;
return V_13 -> V_17 -> V_18 ( V_9 -> V_13 , V_14 , V_15 ) ;
}
static void F_10 ( struct V_6 * V_7 )
{
struct V_9 * V_9 = F_2 ( V_7 ) ;
struct V_16 * V_13 = V_9 -> V_13 ;
F_11 ( V_13 ) ;
}
static int F_12 ( struct V_6 * V_7 )
{
struct V_9 * V_9 = F_2 ( V_7 ) ;
struct V_16 * V_13 = V_9 -> V_13 ;
return F_13 ( V_13 ) ;
}
static int F_14 ( struct V_6 * V_7 )
{
struct V_9 * V_9 = F_2 ( V_7 ) ;
struct V_16 * V_13 ;
struct V_19 V_19 ;
V_13 = F_15 ( V_9 -> V_20 , V_9 -> V_21 ) ;
if ( F_16 ( V_13 ) )
return F_17 ( V_13 ) ;
V_9 -> V_13 = V_13 ;
V_9 -> V_2 -> V_22 = & V_22 ;
V_9 -> V_2 -> V_8 = V_7 ;
if ( V_13 -> V_17 -> V_23 )
V_13 -> V_17 -> V_23 ( V_9 -> V_13 , NULL ) ;
else
F_18 ( V_9 -> V_2 , V_13 , NULL ) ;
V_19 = V_13 -> V_24 ;
V_19 . V_25 &= ~ ( V_26 | V_27 | V_28 | V_29 |
V_30 | V_31 | V_32 | V_33 ) ;
V_19 . V_34 &= ~ V_35 ;
V_19 . V_36 &= ~ ( V_37 | V_38 | V_39 | V_40 | V_41 ) ;
V_19 . V_42 &= ~ ( V_43 | V_44 ) ;
V_19 . V_42 |= V_45 ;
V_19 . V_42 |= V_46 ;
F_19 ( V_13 , & V_19 ) ;
F_9 ( V_10 , & V_9 -> V_11 ) ;
F_20 ( V_9 -> V_13 ) ;
return 0 ;
}
static void F_21 ( struct V_6 * V_7 )
{
struct V_9 * V_9 = F_2 ( V_7 ) ;
struct V_16 * V_13 = V_9 -> V_13 ;
F_22 ( V_10 , & V_9 -> V_11 ) ;
if ( V_13 -> V_17 -> V_47 )
V_13 -> V_17 -> V_47 ( V_13 , NULL ) ;
F_23 ( V_13 , V_9 -> V_21 ) ;
}
static unsigned int F_24 ( struct V_6 * V_7 , unsigned int V_48 )
{
struct V_9 * V_9 = F_2 ( V_7 ) ;
struct V_16 * V_13 = V_9 -> V_13 ;
struct V_19 V_19 = V_13 -> V_24 ;
V_19 . V_42 &= ~ V_49 ;
F_25 ( & V_19 , V_48 , V_48 ) ;
F_19 ( V_13 , & V_19 ) ;
return V_48 ;
}
static void F_26 ( struct V_6 * V_7 , bool V_50 )
{
struct V_9 * V_9 = F_2 ( V_7 ) ;
struct V_16 * V_13 = V_9 -> V_13 ;
struct V_19 V_19 = V_13 -> V_24 ;
if ( V_50 )
V_19 . V_42 |= V_46 ;
else
V_19 . V_42 &= ~ V_46 ;
F_19 ( V_13 , & V_19 ) ;
}
struct V_51 * F_27 ( struct V_1 * V_2 ,
struct V_51 * V_52 ,
struct V_53 * V_54 , int V_55 )
{
struct V_6 * V_7 ;
struct V_9 * V_9 ;
int V_56 ;
if ( ! V_2 || ! V_54 || ! V_52 )
return F_28 ( - V_57 ) ;
V_7 = F_29 ( V_52 , sizeof( struct V_9 ) ) ;
if ( ! V_7 )
return F_28 ( - V_58 ) ;
V_9 = F_2 ( V_7 ) ;
V_9 -> V_2 = V_2 ;
V_9 -> V_21 = V_55 ;
V_9 -> V_20 = V_54 ;
V_7 -> V_17 = & V_59 ;
V_56 = F_30 ( V_7 ) ;
if ( V_56 )
goto V_60;
F_31 ( & V_7 -> V_61 , L_1 , V_54 -> V_62 , V_55 ) ;
return & V_7 -> V_61 ;
V_60:
F_32 ( V_7 ) ;
return F_28 ( V_56 ) ;
}
void F_33 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_9 = F_2 ( V_7 ) ;
if ( ! V_9 )
return;
F_34 ( V_7 ) ;
V_2 -> V_22 = NULL ;
V_2 -> V_8 = NULL ;
F_32 ( V_7 ) ;
}
