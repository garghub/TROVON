static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 , V_9 ;
for ( V_8 = 0 ; V_8 < V_6 -> V_10 ; V_8 ++ ) {
struct V_11 * V_12 = V_6 -> V_13 [ V_8 ] ;
V_9 = F_2 ( V_12 , 0 , 0 , V_14 ,
F_3 ( V_4 ) * 512 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_4 ( V_12 , 1 ,
F_3 ( V_4 ) * 512 ,
V_15 ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
static int F_5 ( struct V_5 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_18 ;
struct V_19 * V_20 = V_16 -> V_13 [ 0 ] -> V_20 ;
struct V_19 * V_21 = V_16 -> V_13 [ 1 ] -> V_20 ;
int V_9 ;
F_6 ( V_20 ,
V_22 |
V_23 ,
V_24 ) ;
F_7 ( V_21 ,
V_25 |
V_26 ,
V_27 ) ;
F_7 ( V_21 ,
V_28 |
V_29 ,
V_30 ) ;
V_9 = F_8 ( V_18 , L_1 ,
V_31 | V_32 |
V_33 | V_34 |
V_35 | V_36 ,
& V_37 , NULL , 0 ) ;
if ( V_9 ) {
F_9 ( V_18 -> V_38 , L_2 , V_9 ) ;
return V_9 ;
}
return F_10 ( V_20 ,
& V_37 ,
& V_37 ,
& V_37 ) ;
}
static int F_11 ( struct V_39 * V_40 )
{
struct V_17 * V_18 = & V_41 ;
struct V_42 * V_43 ;
int V_8 , V_9 ;
V_43 = F_12 ( V_40 -> V_38 . V_44 ,
L_3 , 0 ) ;
if ( ! V_43 ) {
F_9 ( & V_40 -> V_38 , L_4 ) ;
return - V_45 ;
}
for ( V_8 = 0 ; V_8 < V_18 -> V_46 ; V_8 ++ ) {
if ( V_47 [ V_8 ] . V_48 )
continue;
V_47 [ V_8 ] . V_49 = V_43 ;
}
V_50 [ 0 ] . V_44 =
F_12 ( V_40 -> V_38 . V_44 , L_5 , 0 ) ;
if ( ! V_50 [ 0 ] . V_44 ) {
F_9 ( & V_40 -> V_38 ,
L_6 ) ;
return - V_45 ;
}
V_50 [ 1 ] . V_44 =
F_12 ( V_40 -> V_38 . V_44 , L_5 , 1 ) ;
if ( ! V_50 [ 1 ] . V_44 ) {
F_9 ( & V_40 -> V_38 ,
L_6 ) ;
return - V_45 ;
}
V_51 [ 0 ] . V_44 =
V_50 [ 1 ] . V_44 ;
V_47 [ 3 ] . V_52 =
V_50 [ 1 ] . V_44 ;
V_18 -> V_38 = & V_40 -> V_38 ;
F_13 ( V_40 , V_18 ) ;
V_9 = F_14 ( V_18 ) ;
if ( V_9 )
F_9 ( & V_40 -> V_38 , L_7 ,
V_53 , V_9 ) ;
return V_9 ;
}
static int F_15 ( struct V_39 * V_40 )
{
struct V_17 * V_18 = F_16 ( V_40 ) ;
F_17 ( V_18 ) ;
return 0 ;
}
