static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , T_1 * V_5 )
{
T_1 V_6 , V_7 ;
int V_8 = F_2 ( V_2 , V_3 , & V_6 ) ;
if ( ! V_8 )
V_8 = F_2 ( V_2 , V_4 , & V_7 ) ;
if ( V_8 )
return V_8 ;
* V_5 = V_7 == 0 ? 0 : V_6 / V_7 ;
return V_8 ;
}
static int F_3 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = & V_10 -> V_13 . V_12 ;
struct V_1 * V_2 = & V_10 -> V_2 ;
int V_8 ;
V_8 = F_1 ( V_2 , V_14 ,
V_15 , & V_12 -> V_16 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_1 ( V_2 , V_17 , V_18 ,
& V_12 -> V_19 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_1 ( V_2 , V_20 , V_21 ,
& V_12 -> V_22 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_1 ( V_2 , V_23 , V_24 ,
& V_12 -> V_25 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_1 ( V_2 , V_26 , V_27 ,
& V_12 -> V_28 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_4 ( V_2 , V_29 , & V_12 -> V_30 ) ;
if ( ! V_8 )
V_8 = F_4 ( V_2 , V_31 , & V_12 -> V_32 ) ;
if ( ! V_8 )
V_8 = F_4 ( V_2 , V_33 , & V_12 -> V_34 ) ;
if ( ! V_8 )
V_8 = F_4 ( V_2 , V_35 , & V_12 -> V_36 ) ;
if ( V_8 )
return V_8 ;
if ( ! V_8 )
V_8 = F_2 ( V_2 , V_37 , & V_10 -> V_13 . main ) ;
if ( ! V_8 )
V_8 = F_2 ( V_2 , V_38 , & V_10 -> V_13 . V_39 ) ;
if ( ! V_8 )
V_10 -> V_13 . V_40 = V_10 -> V_13 . main + V_10 -> V_13 . V_39 ;
return V_8 ;
}
int F_5 ( struct V_9 * V_10 )
{
unsigned int V_41 = V_10 -> V_13 . V_42 - V_43 ;
struct V_1 * V_2 = & V_10 -> V_2 ;
int V_8 ;
V_8 = F_6 ( V_10 , V_44 ) ;
if ( ! V_8 )
V_8 = F_7 ( V_10 ) ;
if ( ! V_8 )
V_8 = F_8 ( V_2 , V_45 , V_46 ) ;
if ( ! V_8 )
V_8 = F_8 ( V_2 , V_47 , V_10 -> V_48 ) ;
if ( ! V_8 )
V_8 = F_8 ( V_2 , V_49 , V_41 ) ;
if ( ! V_8 )
V_8 = F_6 ( V_10 , V_50 ) ;
if ( ! V_8 )
V_8 = F_9 ( V_2 , V_51 , 2000 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_8 ( V_2 , V_52 , 1 ) ;
if ( ! V_8 )
V_8 = F_8 ( V_2 , V_53 , V_54 ) ;
if ( ! V_8 ) {
bool V_55 = false ;
unsigned int V_56 ;
V_8 = F_9 ( V_2 , V_51 , 2000 ) ;
if ( ! V_8 ) {
V_55 = true ;
V_8 = F_3 ( V_10 ) ;
}
V_56 = V_55 ? V_10 -> V_13 . main : 0 ;
F_10 ( 1 , V_57 , V_2 , L_1 ,
V_58 , V_56 , V_10 -> V_13 . V_39 ) ;
F_11 ( V_2 , V_59 , & V_56 ) ;
}
return V_8 ;
}
