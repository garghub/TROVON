static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
if ( ! V_4 -> V_5 || ! V_4 -> V_5 -> V_6 )
return;
V_4 -> V_5 -> V_6 ( V_4 , V_2 -> V_7 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
if ( ! V_4 -> V_5 || ! V_4 -> V_5 -> V_8 )
return;
V_4 -> V_5 -> V_8 ( V_4 ) ;
}
static int F_4 ( struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_13 V_14 = {
. V_15 = V_12 -> V_16 ,
. y1 = V_12 -> V_17 ,
. V_18 = V_12 -> V_16 + V_12 -> V_19 ,
. V_20 = V_12 -> V_17 + V_12 -> V_21 ,
} ;
struct V_13 V_22 = {
. V_15 = V_12 -> V_23 ,
. y1 = V_12 -> V_24 ,
. V_18 = V_12 -> V_23 + V_12 -> V_25 ,
. V_20 = V_12 -> V_24 + V_12 -> V_26 ,
} ;
struct V_13 V_27 = { 0 } ;
struct V_3 * V_4 ;
struct V_28 * V_29 ;
bool V_30 ;
int V_31 ;
V_4 = F_2 ( V_10 , struct V_3 , V_10 ) ;
V_29 = F_5 ( V_12 -> V_7 ,
& V_4 -> V_2 ) ;
if ( V_29 -> V_6 != ! ! V_12 -> V_2 )
return - V_32 ;
if ( ! V_29 -> V_6 )
return 0 ;
V_27 . V_18 = V_29 -> V_33 . V_34 ;
V_27 . V_20 = V_29 -> V_33 . V_35 ;
V_31 = F_6 ( V_10 , & V_4 -> V_2 ,
V_12 -> V_36 ,
& V_14 , & V_22 , & V_27 ,
V_12 -> V_37 ,
V_38 ,
V_38 ,
false , true , & V_30 ) ;
if ( V_31 )
return V_31 ;
if ( ! V_30 )
return - V_32 ;
if ( ! V_4 -> V_5 || ! V_4 -> V_5 -> V_39 )
return 0 ;
return V_4 -> V_5 -> V_39 ( V_4 , V_12 , V_29 ) ;
}
static void F_7 ( struct V_9 * V_10 ,
struct V_11 * V_40 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_10 , struct V_3 , V_10 ) ;
if ( ! V_4 -> V_5 || ! V_4 -> V_5 -> V_41 )
return;
V_4 -> V_5 -> V_41 ( V_4 , V_40 ) ;
}
int F_8 ( struct V_42 * V_43 ,
struct V_3 * V_4 ,
const struct V_44 * V_5 ,
const T_1 * V_45 , unsigned int V_46 ,
struct V_47 * V_48 )
{
struct V_49 * V_50 = & V_4 -> V_50 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
struct V_1 * V_2 = & V_4 -> V_2 ;
int V_31 ;
V_4 -> V_48 = V_48 ;
V_4 -> V_5 = V_5 ;
F_9 ( V_10 , & V_51 ) ;
V_31 = F_10 ( V_43 , V_10 , 0 ,
& V_52 ,
V_45 , V_46 ,
V_53 , NULL ) ;
if ( V_31 )
return V_31 ;
F_11 ( V_2 , & V_54 ) ;
V_31 = F_12 ( V_43 , V_2 , V_10 , NULL ,
& V_55 , NULL ) ;
if ( V_31 )
return V_31 ;
V_50 -> V_56 = 1 << F_13 ( V_2 ) ;
V_31 = F_14 ( V_43 , V_50 , & V_57 ,
V_58 , NULL ) ;
if ( V_31 )
return V_31 ;
return F_15 ( V_48 , V_50 ) ;
}
