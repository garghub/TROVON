static int F_1 ( void * V_1 , int * V_2 )
{
const struct V_3 * V_4 = V_1 ;
struct V_5 * V_6 = V_4 -> V_6 ;
return V_6 -> V_7 -> V_8 ( V_6 , V_4 -> V_9 , V_2 ) ;
}
static int F_2 ( void * V_10 , int V_11 , enum V_12 * V_13 )
{
const struct V_3 * V_4 = V_10 ;
struct V_5 * V_6 = V_4 -> V_6 ;
if ( V_6 -> V_7 -> V_14 )
return V_6 -> V_7 -> V_14 ( V_6 , V_4 -> V_9 , V_13 ) ;
return - V_15 ;
}
static int T_1 F_3 ( struct V_16 * V_17 )
{
struct V_5 * V_6 = F_4 ( V_17 ) ;
if ( V_6 -> V_7 && V_6 -> V_7 -> V_18 )
return V_6 -> V_7 -> V_18 ( V_6 ) ;
return 0 ;
}
static int T_1 F_5 ( struct V_16 * V_17 )
{
struct V_5 * V_6 = F_4 ( V_17 ) ;
if ( V_6 -> V_7 && V_6 -> V_7 -> V_19 )
return V_6 -> V_7 -> V_19 ( V_6 ) ;
return 0 ;
}
static int F_6 ( struct V_5 * V_6 )
{
int V_20 ;
struct V_21 * V_22 ;
T_2 * V_23 , V_24 = V_6 -> V_25 ;
V_23 = F_7 ( V_6 -> V_17 , V_24 , sizeof( T_2 ) , V_26 ) ;
if ( ! V_23 )
return - V_27 ;
for ( V_20 = 0 ; V_20 < V_6 -> V_25 ; V_20 ++ ) {
V_6 -> V_28 [ V_20 ] . V_6 = V_6 ;
V_6 -> V_28 [ V_20 ] . V_9 = V_20 ;
V_22 = F_8 ( V_6 -> V_17 , V_20 ,
& V_6 -> V_28 [ V_20 ] ,
& V_29 ) ;
if ( F_9 ( V_22 ) )
continue;
V_6 -> V_28 [ V_20 ] . V_22 = V_22 ;
if ( V_6 -> V_7 -> V_30 )
V_6 -> V_7 -> V_30 ( V_6 , V_20 ) ;
}
return 0 ;
}
static int F_10 ( struct V_31 * V_32 )
{
int V_33 , V_20 ;
struct V_16 * V_17 ;
struct V_34 * V_35 ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
const struct V_36 * V_1 ;
const struct V_37 * V_9 ;
if ( V_32 -> V_17 . V_38 )
V_17 = & V_32 -> V_17 ;
else
V_17 = V_32 -> V_17 . V_39 ;
V_35 = V_17 -> V_38 ;
V_9 = F_11 ( V_40 , V_35 ) ;
if ( V_9 )
V_1 = V_9 -> V_1 ;
else
V_1 = & V_41 ;
if ( V_1 -> V_25 <= 0 ) {
F_12 ( V_17 , L_1 ) ;
return - V_42 ;
}
V_6 = F_13 ( V_17 , sizeof( * V_6 ) +
V_1 -> V_25 * sizeof( * V_4 ) , V_26 ) ;
if ( ! V_6 )
return - V_27 ;
V_6 -> V_17 = V_17 ;
V_6 -> V_25 = V_1 -> V_25 ;
V_6 -> V_7 = V_1 -> V_7 ;
for ( V_20 = 0 ; V_20 < V_6 -> V_25 ; V_20 ++ ) {
if ( V_1 -> V_43 )
V_6 -> V_28 [ V_20 ] . V_23 = V_1 -> V_43 [ V_20 ] ;
else
V_6 -> V_28 [ V_20 ] . V_23 = V_20 ;
}
if ( ! V_6 -> V_7 || ! V_6 -> V_7 -> V_44 || ! V_6 -> V_7 -> V_8 )
return - V_42 ;
V_33 = V_6 -> V_7 -> V_44 ( V_6 ) ;
if ( V_33 < 0 ) {
F_12 ( V_17 , L_2 ) ;
return V_33 ;
}
if ( V_6 -> V_7 -> V_45 ) {
V_33 = V_6 -> V_7 -> V_45 ( V_6 ) ;
if ( V_33 < 0 ) {
F_12 ( V_17 , L_3 ) ;
return V_33 ;
}
}
V_33 = F_6 ( V_6 ) ;
F_14 ( V_32 , V_6 ) ;
return V_33 ;
}
static int F_15 ( struct V_31 * V_32 )
{
struct V_5 * V_6 = F_16 ( V_32 ) ;
if ( V_6 -> V_7 -> V_46 )
V_6 -> V_7 -> V_46 ( V_6 ) ;
return 0 ;
}
