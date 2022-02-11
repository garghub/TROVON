static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
if ( V_3 < 750 ) {
V_3 = 750 ;
F_3 ( & V_2 -> V_6 , L_1 ) ;
}
if ( V_3 > 1875 ) {
V_3 = 1875 ;
F_3 ( & V_2 -> V_6 , L_2 ) ;
}
V_3 = ( V_3 - 750 ) / 75 ;
return F_4 ( V_5 -> V_8 , V_9 ,
V_10 , V_3 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_11 * V_12 , * V_13 ;
int V_14 ;
T_1 V_3 ;
V_12 = F_6 ( V_2 -> V_6 . V_7 -> V_15 ) ;
if ( ! V_12 )
return 0 ;
V_13 = F_7 ( V_12 , L_3 ) ;
if ( ! V_13 ) {
F_3 ( & V_2 -> V_6 , L_4 ) ;
} else {
V_14 = F_8 ( & V_2 -> V_6 , V_13 , V_16 ,
F_9 ( V_16 ) ) ;
if ( V_14 < 0 ) {
F_10 ( & V_2 -> V_6 , L_5 , V_14 ) ;
return V_14 ;
}
V_3 = 1500 ;
F_11 ( V_13 , L_6 , & V_3 ) ;
V_14 = F_1 ( V_2 , V_3 ) ;
if ( V_14 < 0 ) {
F_10 ( & V_2 -> V_6 , L_7 , V_14 ) ;
return V_14 ;
}
F_12 ( V_13 ) ;
}
return 0 ;
}
static int F_13 ( struct V_17 * V_18 , int V_19 , T_1 V_20 )
{
unsigned int V_21 = V_22 ;
if ( ( V_19 != V_23 ) && ( V_19 != V_24 ) )
return - V_25 ;
if ( V_19 == V_24 )
V_21 = V_26 ;
V_20 <<= F_14 ( V_21 ) - 1 ;
return F_4 ( V_18 -> V_8 , V_27 , V_21 , V_20 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_17 * V_18 ;
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
struct V_28 V_29 = { } ;
struct V_30 * V_31 ;
int V_14 , V_32 ;
T_1 V_20 ;
V_14 = F_5 ( V_2 ) ;
if ( V_14 )
return V_14 ;
for ( V_32 = 0 ; V_32 < V_33 ; V_32 ++ ) {
V_31 = V_16 [ V_32 ] . V_31 ;
V_29 . V_6 = & V_2 -> V_6 ;
V_29 . V_31 = V_31 ;
V_29 . V_8 = V_5 -> V_8 ;
V_29 . V_15 = V_16 [ V_32 ] . V_15 ;
V_18 = F_16 ( & V_2 -> V_6 , & V_34 [ V_32 ] ,
& V_29 ) ;
if ( F_17 ( V_18 ) ) {
F_10 ( & V_2 -> V_6 , L_8 ,
V_34 [ V_32 ] . V_35 ) ;
return F_18 ( V_18 ) ;
}
V_14 = F_11 ( V_16 [ V_32 ] . V_15 , L_9 ,
& V_20 ) ;
if ( ! V_14 ) {
if ( F_13 ( V_18 , V_32 , V_20 ) )
F_10 ( & V_2 -> V_6 , L_10 ,
V_34 [ V_32 ] . V_35 ) ;
}
}
return 0 ;
}
