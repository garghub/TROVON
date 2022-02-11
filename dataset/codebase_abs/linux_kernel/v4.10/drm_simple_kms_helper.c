static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return F_2 ( V_4 -> V_4 , V_2 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
V_6 = F_4 ( V_2 , struct V_5 , V_2 ) ;
if ( ! V_6 -> V_7 || ! V_6 -> V_7 -> V_8 )
return;
V_6 -> V_7 -> V_8 ( V_6 , V_2 -> V_4 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
V_6 = F_4 ( V_2 , struct V_5 , V_2 ) ;
if ( ! V_6 -> V_7 || ! V_6 -> V_7 -> V_9 )
return;
V_6 -> V_7 -> V_9 ( V_6 ) ;
}
static int F_6 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
struct V_14 V_15 = { 0 } ;
struct V_5 * V_6 ;
struct V_3 * V_16 ;
int V_17 ;
V_6 = F_4 ( V_11 , struct V_5 , V_11 ) ;
V_16 = F_7 ( V_13 -> V_4 ,
& V_6 -> V_2 ) ;
if ( V_16 -> V_8 != ! ! V_13 -> V_2 )
return - V_18 ;
if ( ! V_16 -> V_8 )
return 0 ;
V_15 . V_19 = V_16 -> V_20 . V_21 ;
V_15 . V_22 = V_16 -> V_20 . V_23 ;
V_17 = F_8 ( V_13 , & V_15 ,
V_24 ,
V_24 ,
false , true ) ;
if ( V_17 )
return V_17 ;
if ( ! V_13 -> V_25 )
return - V_18 ;
if ( ! V_6 -> V_7 || ! V_6 -> V_7 -> V_26 )
return 0 ;
return V_6 -> V_7 -> V_26 ( V_6 , V_13 , V_16 ) ;
}
static void F_9 ( struct V_10 * V_11 ,
struct V_12 * V_27 )
{
struct V_5 * V_6 ;
V_6 = F_4 ( V_11 , struct V_5 , V_11 ) ;
if ( ! V_6 -> V_7 || ! V_6 -> V_7 -> V_28 )
return;
V_6 -> V_7 -> V_28 ( V_6 , V_27 ) ;
}
static int F_10 ( struct V_10 * V_11 ,
struct V_12 * V_4 )
{
struct V_5 * V_6 ;
V_6 = F_4 ( V_11 , struct V_5 , V_11 ) ;
if ( ! V_6 -> V_7 || ! V_6 -> V_7 -> V_29 )
return 0 ;
return V_6 -> V_7 -> V_29 ( V_6 , V_4 ) ;
}
static void F_11 ( struct V_10 * V_11 ,
struct V_12 * V_4 )
{
struct V_5 * V_6 ;
V_6 = F_4 ( V_11 , struct V_5 , V_11 ) ;
if ( ! V_6 -> V_7 || ! V_6 -> V_7 -> V_30 )
return;
V_6 -> V_7 -> V_30 ( V_6 , V_4 ) ;
}
int F_12 ( struct V_5 * V_6 ,
struct V_31 * V_32 )
{
V_32 -> V_33 = & V_6 -> V_33 ;
V_6 -> V_33 . V_32 = V_32 ;
return F_13 ( V_6 -> V_33 . V_34 , V_32 ) ;
}
void F_14 ( struct V_5 * V_6 )
{
if ( F_15 ( ! V_6 -> V_33 . V_32 ) )
return;
F_16 ( V_6 -> V_33 . V_32 ) ;
V_6 -> V_33 . V_32 = NULL ;
}
int F_17 ( struct V_35 * V_34 ,
struct V_5 * V_6 ,
const struct V_36 * V_7 ,
const T_1 * V_37 , unsigned int V_38 ,
struct V_39 * V_40 )
{
struct V_41 * V_33 = & V_6 -> V_33 ;
struct V_10 * V_11 = & V_6 -> V_11 ;
struct V_1 * V_2 = & V_6 -> V_2 ;
int V_17 ;
V_6 -> V_40 = V_40 ;
V_6 -> V_7 = V_7 ;
F_18 ( V_11 , & V_42 ) ;
V_17 = F_19 ( V_34 , V_11 , 0 ,
& V_43 ,
V_37 , V_38 ,
V_44 , NULL ) ;
if ( V_17 )
return V_17 ;
F_20 ( V_2 , & V_45 ) ;
V_17 = F_21 ( V_34 , V_2 , V_11 , NULL ,
& V_46 , NULL ) ;
if ( V_17 )
return V_17 ;
V_33 -> V_47 = 1 << F_22 ( V_2 ) ;
V_17 = F_23 ( V_34 , V_33 , & V_48 ,
V_49 , NULL ) ;
if ( V_17 || ! V_40 )
return V_17 ;
return F_24 ( V_40 , V_33 ) ;
}
