int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 ;
struct V_12 V_13 ;
int V_14 ;
V_11 = F_3 ( V_8 -> V_15 , V_2 ) ;
if ( ! V_11 )
return 0 ;
V_14 = F_4 ( V_2 , V_4 , & V_13 ) ;
if ( V_14 )
return V_14 ;
F_5 ( V_2 ,
F_3 ( V_8 -> V_15 , V_2 ) ,
& V_13 ) ;
V_14 = F_6 ( V_6 , & V_13 ) ;
if ( V_14 )
return V_14 ;
F_7 ( V_2 , & V_2 -> V_16 ) ;
return 0 ;
}
int F_8 ( struct V_1 * V_2 )
{
F_7 ( V_2 , NULL ) ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 , int V_17 )
{
return F_10 ( V_2 , V_17 ) ;
}
T_1
F_11 ( struct V_1 * V_2 )
{
return F_12 ( V_2 ) ;
}
int F_13 ( struct V_1 * V_2 )
{
return 0 ;
}
int F_14 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_10 * V_11 ;
int V_14 ;
V_19 -> V_20 = V_21 ;
V_11 = F_3 ( V_8 -> V_15 , V_2 ) ;
if ( ! V_11 )
return 0 ;
V_14 = F_15 ( V_19 , 0 ,
V_22 , 32 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_15 ( V_19 , 0 ,
V_23 , 32 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_16 ( V_19 ,
V_24 ) ;
if ( V_14 < 0 )
return V_14 ;
return F_17 ( V_2 ,
V_25 ,
V_11 -> V_26 ) ;
}
int F_18 ( struct V_1 * V_2 )
{
return F_19 ( V_2 ) ;
}
int F_20 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
return F_21 ( V_2 -> V_29 -> V_30 -> V_31 , V_28 ,
V_19 -> V_32 ,
V_19 -> V_33 ,
V_19 -> V_34 ) ;
}
int F_22 ( struct V_35 * V_29 , int V_36 )
{
struct V_1 * V_2 = V_29 -> V_37 [ V_36 ] . V_2 ;
struct V_38 * V_39 = & V_2 -> V_16 ;
T_2 V_40 = V_21 . V_41 ;
V_39 -> V_31 . type = V_42 ;
V_39 -> V_31 . V_31 = V_29 -> V_30 -> V_31 ;
V_39 -> V_9 = NULL ;
V_39 -> V_43 = F_23 ( V_29 -> V_30 -> V_31 , V_40 ,
& V_39 -> V_44 , V_45 ) ;
if ( ! V_39 -> V_43 )
return - V_46 ;
V_39 -> V_47 = V_40 ;
return 0 ;
}
void F_24 ( struct V_35 * V_29 )
{
struct V_1 * V_2 ;
struct V_38 * V_39 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < 2 ; V_36 ++ ) {
V_2 = V_29 -> V_37 [ V_36 ] . V_2 ;
if ( ! V_2 )
continue;
V_39 = & V_2 -> V_16 ;
if ( ! V_39 -> V_43 )
continue;
F_25 ( V_29 -> V_30 -> V_31 , V_39 -> V_47 ,
V_39 -> V_43 , V_39 -> V_44 ) ;
V_39 -> V_43 = NULL ;
}
}
