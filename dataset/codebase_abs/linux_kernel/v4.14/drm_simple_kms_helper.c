static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
bool V_5 = V_4 -> V_6 &
F_2 ( F_3 ( V_2 -> V_7 ) ) ;
if ( V_5 != V_4 -> V_8 )
return - V_9 ;
return F_4 ( V_4 -> V_4 , V_2 ) ;
}
static void F_5 ( struct V_1 * V_2 ,
struct V_3 * V_10 )
{
struct V_11 * V_12 ;
V_12 = F_6 ( V_2 , struct V_11 , V_2 ) ;
if ( ! V_12 -> V_13 || ! V_12 -> V_13 -> V_8 )
return;
V_12 -> V_13 -> V_8 ( V_12 , V_2 -> V_4 ) ;
}
static void F_7 ( struct V_1 * V_2 ,
struct V_3 * V_10 )
{
struct V_11 * V_12 ;
V_12 = F_6 ( V_2 , struct V_11 , V_2 ) ;
if ( ! V_12 -> V_13 || ! V_12 -> V_13 -> V_14 )
return;
V_12 -> V_13 -> V_14 ( V_12 ) ;
}
static int F_8 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_19 V_20 = { 0 } ;
struct V_11 * V_12 ;
struct V_3 * V_21 ;
int V_22 ;
V_12 = F_6 ( V_16 , struct V_11 , V_16 ) ;
V_21 = F_9 ( V_18 -> V_4 ,
& V_12 -> V_2 ) ;
if ( ! V_21 -> V_8 )
return 0 ;
V_20 . V_23 = V_21 -> V_24 . V_25 ;
V_20 . V_26 = V_21 -> V_24 . V_27 ;
V_22 = F_10 ( V_18 , & V_20 ,
V_28 ,
V_28 ,
false , true ) ;
if ( V_22 )
return V_22 ;
if ( ! V_18 -> V_29 )
return - V_9 ;
if ( ! V_12 -> V_13 || ! V_12 -> V_13 -> V_30 )
return 0 ;
return V_12 -> V_13 -> V_30 ( V_12 , V_18 , V_21 ) ;
}
static void F_11 ( struct V_15 * V_16 ,
struct V_17 * V_31 )
{
struct V_11 * V_12 ;
V_12 = F_6 ( V_16 , struct V_11 , V_16 ) ;
if ( ! V_12 -> V_13 || ! V_12 -> V_13 -> V_32 )
return;
V_12 -> V_13 -> V_32 ( V_12 , V_31 ) ;
}
static int F_12 ( struct V_15 * V_16 ,
struct V_17 * V_4 )
{
struct V_11 * V_12 ;
V_12 = F_6 ( V_16 , struct V_11 , V_16 ) ;
if ( ! V_12 -> V_13 || ! V_12 -> V_13 -> V_33 )
return 0 ;
return V_12 -> V_13 -> V_33 ( V_12 , V_4 ) ;
}
static void F_13 ( struct V_15 * V_16 ,
struct V_17 * V_4 )
{
struct V_11 * V_12 ;
V_12 = F_6 ( V_16 , struct V_11 , V_16 ) ;
if ( ! V_12 -> V_13 || ! V_12 -> V_13 -> V_34 )
return;
V_12 -> V_13 -> V_34 ( V_12 , V_4 ) ;
}
int F_14 ( struct V_11 * V_12 ,
struct V_35 * V_36 )
{
return F_15 ( & V_12 -> V_37 , V_36 , NULL ) ;
}
int F_16 ( struct V_38 * V_39 ,
struct V_11 * V_12 ,
const struct V_40 * V_13 ,
const T_1 * V_41 , unsigned int V_42 ,
const T_2 * V_43 ,
struct V_44 * V_45 )
{
struct V_46 * V_37 = & V_12 -> V_37 ;
struct V_15 * V_16 = & V_12 -> V_16 ;
struct V_1 * V_2 = & V_12 -> V_2 ;
int V_22 ;
V_12 -> V_45 = V_45 ;
V_12 -> V_13 = V_13 ;
F_17 ( V_16 , & V_47 ) ;
V_22 = F_18 ( V_39 , V_16 , 0 ,
& V_48 ,
V_41 , V_42 ,
V_43 ,
V_49 , NULL ) ;
if ( V_22 )
return V_22 ;
F_19 ( V_2 , & V_50 ) ;
V_22 = F_20 ( V_39 , V_2 , V_16 , NULL ,
& V_51 , NULL ) ;
if ( V_22 )
return V_22 ;
V_37 -> V_52 = 1 << F_21 ( V_2 ) ;
V_22 = F_22 ( V_39 , V_37 , & V_53 ,
V_54 , NULL ) ;
if ( V_22 || ! V_45 )
return V_22 ;
return F_23 ( V_45 , V_37 ) ;
}
