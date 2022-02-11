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
if ( F_6 ( V_12 , & V_2 -> V_13 -> V_11 ) &&
F_3 ( V_10 , & V_9 -> V_11 ) )
F_7 ( V_7 ) ;
F_8 ( & V_2 -> V_13 -> V_14 , V_15 ) ;
}
static int F_9 ( struct V_6 * V_7 , const unsigned char * V_16 , T_1 V_17 )
{
struct V_9 * V_9 = F_2 ( V_7 ) ;
struct V_18 * V_13 = V_9 -> V_13 ;
if ( ! F_3 ( V_10 , & V_9 -> V_11 ) )
return 0 ;
F_10 ( V_12 , & V_13 -> V_11 ) ;
return V_13 -> V_19 -> V_20 ( V_9 -> V_13 , V_16 , V_17 ) ;
}
static void F_11 ( struct V_6 * V_7 )
{
struct V_9 * V_9 = F_2 ( V_7 ) ;
struct V_18 * V_13 = V_9 -> V_13 ;
F_12 ( V_13 ) ;
}
static int F_13 ( struct V_6 * V_7 )
{
struct V_9 * V_9 = F_2 ( V_7 ) ;
struct V_18 * V_13 = V_9 -> V_13 ;
return F_14 ( V_13 ) ;
}
static int F_15 ( struct V_6 * V_7 )
{
struct V_9 * V_9 = F_2 ( V_7 ) ;
struct V_18 * V_13 ;
struct V_21 V_21 ;
V_13 = F_16 ( V_9 -> V_22 , V_9 -> V_23 ) ;
if ( F_17 ( V_13 ) )
return F_18 ( V_13 ) ;
V_9 -> V_13 = V_13 ;
if ( V_13 -> V_19 -> V_24 )
V_13 -> V_19 -> V_24 ( V_9 -> V_13 , NULL ) ;
else
F_19 ( V_9 -> V_2 , V_13 , NULL ) ;
V_21 = V_13 -> V_25 ;
V_21 . V_26 &= ~ ( V_27 | V_28 | V_29 | V_30 |
V_31 | V_32 | V_33 | V_34 ) ;
V_21 . V_35 &= ~ V_36 ;
V_21 . V_37 &= ~ ( V_38 | V_39 | V_40 | V_41 | V_42 ) ;
V_21 . V_43 &= ~ ( V_44 | V_45 ) ;
V_21 . V_43 |= V_46 ;
V_21 . V_43 |= V_47 ;
F_20 ( V_13 , & V_21 ) ;
F_10 ( V_10 , & V_9 -> V_11 ) ;
F_21 ( V_9 -> V_13 ) ;
return 0 ;
}
static void F_22 ( struct V_6 * V_7 )
{
struct V_9 * V_9 = F_2 ( V_7 ) ;
struct V_18 * V_13 = V_9 -> V_13 ;
F_23 ( V_10 , & V_9 -> V_11 ) ;
if ( V_13 -> V_19 -> V_48 )
V_13 -> V_19 -> V_48 ( V_13 , NULL ) ;
F_24 ( V_13 , V_9 -> V_23 ) ;
}
static unsigned int F_25 ( struct V_6 * V_7 , unsigned int V_49 )
{
struct V_9 * V_9 = F_2 ( V_7 ) ;
struct V_18 * V_13 = V_9 -> V_13 ;
struct V_21 V_21 = V_13 -> V_25 ;
V_21 . V_43 &= ~ V_50 ;
F_26 ( & V_21 , V_49 , V_49 ) ;
F_20 ( V_13 , & V_21 ) ;
return V_49 ;
}
static void F_27 ( struct V_6 * V_7 , bool V_51 )
{
struct V_9 * V_9 = F_2 ( V_7 ) ;
struct V_18 * V_13 = V_9 -> V_13 ;
struct V_21 V_21 = V_13 -> V_25 ;
if ( V_51 )
V_21 . V_43 |= V_47 ;
else
V_21 . V_43 &= ~ V_47 ;
F_20 ( V_13 , & V_21 ) ;
}
static void F_28 ( struct V_6 * V_7 , long V_52 )
{
struct V_9 * V_9 = F_2 ( V_7 ) ;
struct V_18 * V_13 = V_9 -> V_13 ;
F_29 ( V_13 , V_52 ) ;
}
static int F_30 ( struct V_6 * V_7 )
{
struct V_9 * V_9 = F_2 ( V_7 ) ;
struct V_18 * V_13 = V_9 -> V_13 ;
if ( ! V_13 -> V_19 -> V_53 )
return - V_54 ;
return V_13 -> V_55 -> V_19 -> V_53 ( V_13 ) ;
}
static int F_31 ( struct V_6 * V_7 , unsigned int V_56 , unsigned int V_57 )
{
struct V_9 * V_9 = F_2 ( V_7 ) ;
struct V_18 * V_13 = V_9 -> V_13 ;
if ( ! V_13 -> V_19 -> V_58 )
return - V_54 ;
return V_13 -> V_55 -> V_19 -> V_58 ( V_13 , V_56 , V_57 ) ;
}
struct V_59 * F_32 ( struct V_1 * V_2 ,
struct V_59 * V_60 ,
struct V_61 * V_62 , int V_63 )
{
const struct V_64 * V_65 ;
struct V_6 * V_7 ;
struct V_9 * V_9 ;
int V_66 ;
if ( ! V_2 || ! V_62 || ! V_60 )
return F_33 ( - V_67 ) ;
V_7 = F_34 ( V_60 , sizeof( struct V_9 ) ) ;
if ( ! V_7 )
return F_33 ( - V_68 ) ;
V_9 = F_2 ( V_7 ) ;
V_9 -> V_2 = V_2 ;
V_9 -> V_23 = V_63 ;
V_9 -> V_22 = V_62 ;
V_7 -> V_19 = & V_69 ;
V_65 = V_2 -> V_70 ;
V_2 -> V_70 = & V_70 ;
V_2 -> V_8 = V_7 ;
V_66 = F_35 ( V_7 ) ;
if ( V_66 )
goto V_71;
F_36 ( & V_7 -> V_72 , L_1 , V_62 -> V_73 , V_63 ) ;
return & V_7 -> V_72 ;
V_71:
V_2 -> V_8 = NULL ;
V_2 -> V_70 = V_65 ;
F_37 ( V_7 ) ;
return F_33 ( V_66 ) ;
}
int F_38 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_9 = F_2 ( V_7 ) ;
if ( ! V_9 )
return - V_67 ;
F_39 ( V_7 ) ;
V_2 -> V_70 = NULL ;
V_2 -> V_8 = NULL ;
F_37 ( V_7 ) ;
return 0 ;
}
