static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 ;
unsigned int V_8 , V_9 ;
if ( V_3 >= V_5 -> V_10 )
return - V_11 ;
V_7 = & V_5 -> V_12 [ V_3 ] ;
if ( V_7 -> V_13 & V_14 )
return - V_15 ;
V_8 = F_3 ( V_7 -> V_16 ) ;
V_9 = ( V_7 -> V_13 & V_17 ) ? V_8 : 0x0 ;
return F_4 ( V_5 -> V_18 , V_7 -> V_19 , V_8 , V_9 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 ;
unsigned int V_8 , V_9 ;
if ( V_3 >= V_5 -> V_10 )
return - V_11 ;
V_7 = & V_5 -> V_12 [ V_3 ] ;
if ( V_7 -> V_13 & V_20 )
return - V_15 ;
V_8 = F_3 ( V_7 -> V_21 ) ;
V_9 = ( V_7 -> V_13 & V_22 ) ? V_8 : 0x0 ;
return F_4 ( V_5 -> V_18 , V_7 -> V_23 , V_8 , V_9 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 ;
unsigned int V_24 ;
int V_25 ;
if ( V_3 >= V_5 -> V_10 )
return - V_11 ;
V_7 = & V_5 -> V_12 [ V_3 ] ;
if ( V_7 -> V_13 & V_26 )
return - V_15 ;
V_25 = F_7 ( V_5 -> V_18 , V_7 -> V_27 , & V_24 ) ;
if ( V_25 )
return V_25 ;
return ( V_24 & F_3 ( V_7 -> V_28 ) ) &&
( V_7 -> V_13 & V_29 ) ;
}
static int F_8 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = & V_31 -> V_33 ;
struct V_34 * V_35 = V_33 -> V_36 ;
struct V_4 * V_5 ;
struct V_18 * V_18 ;
const T_1 * V_37 ;
struct V_6 * V_12 ;
int V_38 , V_10 , V_39 ;
V_5 = F_9 ( V_33 , sizeof( * V_5 ) , V_40 ) ;
if ( ! V_5 )
return - V_41 ;
V_18 = F_10 ( V_35 -> V_42 ) ;
if ( F_11 ( V_18 ) )
return F_12 ( V_18 ) ;
V_37 = F_13 ( V_35 , L_1 , & V_38 ) ;
if ( ! V_37 || ( V_38 / sizeof( * V_37 ) ) % 7 != 0 ) {
F_14 ( V_33 , L_2 ) ;
return - V_11 ;
}
V_10 = ( V_38 / sizeof( * V_37 ) ) / 7 ;
V_12 = F_9 ( V_33 , V_10 * sizeof( * V_12 ) , V_40 ) ;
if ( ! V_12 )
return - V_41 ;
for ( V_39 = 0 ; V_39 < V_10 ; V_39 ++ ) {
V_12 [ V_39 ] . V_19 = F_15 ( V_37 ++ ) ;
V_12 [ V_39 ] . V_16 = F_15 ( V_37 ++ ) ;
V_12 [ V_39 ] . V_23 = F_15 ( V_37 ++ ) ;
V_12 [ V_39 ] . V_21 = F_15 ( V_37 ++ ) ;
V_12 [ V_39 ] . V_27 = F_15 ( V_37 ++ ) ;
V_12 [ V_39 ] . V_28 = F_15 ( V_37 ++ ) ;
V_12 [ V_39 ] . V_13 = F_15 ( V_37 ++ ) ;
}
V_5 -> V_2 . V_43 = & V_44 ;
V_5 -> V_2 . V_45 = V_46 ;
V_5 -> V_2 . V_36 = V_35 ;
V_5 -> V_2 . V_47 = V_10 ;
V_5 -> V_18 = V_18 ;
V_5 -> V_12 = V_12 ;
V_5 -> V_10 = V_10 ;
F_16 ( V_31 , V_5 ) ;
return F_17 ( V_33 , & V_5 -> V_2 ) ;
}
