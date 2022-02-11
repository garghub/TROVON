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
V_3 = 1500 ;
F_8 ( V_13 , L_5 , & V_3 ) ;
V_14 = F_1 ( V_2 , V_3 ) ;
if ( V_14 < 0 ) {
F_9 ( & V_2 -> V_6 , L_6 , V_14 ) ;
return V_14 ;
}
F_10 ( V_13 ) ;
}
return 0 ;
}
static int F_11 ( struct V_16 * V_17 , int V_18 , T_1 V_19 )
{
unsigned int V_20 = V_21 ;
if ( ( V_18 != V_22 ) && ( V_18 != V_23 ) )
return - V_24 ;
if ( V_18 == V_23 )
V_20 = V_25 ;
V_19 <<= F_12 ( V_20 ) - 1 ;
return F_4 ( V_17 -> V_8 , V_26 , V_20 , V_19 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
struct V_27 V_28 = {
. V_6 = V_2 -> V_6 . V_7 ,
. V_8 = V_5 -> V_8 ,
} ;
int V_14 , V_29 ;
T_1 V_19 ;
F_5 ( V_2 ) ;
for ( V_29 = 0 ; V_29 < V_30 ; V_29 ++ ) {
V_17 = F_14 ( & V_2 -> V_6 , & V_31 [ V_29 ] ,
& V_28 ) ;
if ( F_15 ( V_17 ) ) {
F_9 ( & V_2 -> V_6 , L_7 ,
V_31 [ V_29 ] . V_32 ) ;
return F_16 ( V_17 ) ;
}
V_14 = F_8 ( V_17 -> V_6 . V_15 ,
L_8 ,
& V_19 ) ;
if ( ! V_14 ) {
if ( F_11 ( V_17 , V_29 , V_19 ) )
F_9 ( & V_2 -> V_6 , L_9 ,
V_31 [ V_29 ] . V_32 ) ;
}
}
return 0 ;
}
