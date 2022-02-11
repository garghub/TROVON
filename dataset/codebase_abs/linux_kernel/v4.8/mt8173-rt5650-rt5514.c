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
int V_9 ;
F_6 ( V_20 ,
V_21 |
V_22 ,
V_23 ) ;
V_9 = F_7 ( V_18 , L_1 ,
V_24 | V_25 |
V_26 | V_27 |
V_28 | V_29 ,
& V_30 , NULL , 0 ) ;
if ( V_9 ) {
F_8 ( V_18 -> V_31 , L_2 , V_9 ) ;
return V_9 ;
}
return F_9 ( V_20 ,
& V_30 ,
& V_30 ,
& V_30 ) ;
}
static int F_10 ( struct V_32 * V_33 )
{
struct V_17 * V_18 = & V_34 ;
struct V_35 * V_36 ;
int V_8 , V_9 ;
V_36 = F_11 ( V_33 -> V_31 . V_37 ,
L_3 , 0 ) ;
if ( ! V_36 ) {
F_8 ( & V_33 -> V_31 , L_4 ) ;
return - V_38 ;
}
for ( V_8 = 0 ; V_8 < V_18 -> V_39 ; V_8 ++ ) {
if ( V_40 [ V_8 ] . V_41 )
continue;
V_40 [ V_8 ] . V_42 = V_36 ;
}
V_43 [ 0 ] . V_37 =
F_11 ( V_33 -> V_31 . V_37 , L_5 , 0 ) ;
if ( ! V_43 [ 0 ] . V_37 ) {
F_8 ( & V_33 -> V_31 ,
L_6 ) ;
return - V_38 ;
}
V_43 [ 1 ] . V_37 =
F_11 ( V_33 -> V_31 . V_37 , L_5 , 1 ) ;
if ( ! V_43 [ 1 ] . V_37 ) {
F_8 ( & V_33 -> V_31 ,
L_6 ) ;
return - V_38 ;
}
V_44 [ 0 ] . V_37 =
V_43 [ 1 ] . V_37 ;
V_18 -> V_31 = & V_33 -> V_31 ;
F_12 ( V_33 , V_18 ) ;
V_9 = F_13 ( & V_33 -> V_31 , V_18 ) ;
if ( V_9 )
F_8 ( & V_33 -> V_31 , L_7 ,
V_45 , V_9 ) ;
return V_9 ;
}
