static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 = F_3 ( V_2 ) ;
int V_8 ;
F_4 ( F_5 ( V_2 ) , L_1 , V_9 , V_7 ) ;
F_6 ( V_4 -> V_10 ) ;
V_8 = F_7 ( V_4 -> V_10 , V_6 [ V_7 ] . V_11 ,
V_6 [ V_7 ] . V_12 ,
V_6 [ V_7 ] . V_12 ) ;
F_8 ( V_4 -> V_10 ) ;
return V_8 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 = F_3 ( V_2 ) ;
int V_8 ;
F_4 ( F_5 ( V_2 ) , L_1 , V_9 , V_7 ) ;
F_6 ( V_4 -> V_10 ) ;
V_8 = F_7 ( V_4 -> V_10 , V_6 [ V_7 ] . V_11 ,
V_6 [ V_7 ] . V_12 , 0 ) ;
F_8 ( V_4 -> V_10 ) ;
return V_8 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_8 , V_7 = F_3 ( V_2 ) ;
unsigned int V_13 ;
F_6 ( V_4 -> V_10 ) ;
V_8 = F_11 ( V_4 -> V_10 , V_6 [ V_7 ] . V_11 , & V_13 ) ;
F_8 ( V_4 -> V_10 ) ;
if ( V_8 )
return V_8 ;
return ( V_13 & V_6 [ V_7 ] . V_12 ) != 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
unsigned V_14 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 = F_3 ( V_2 ) ;
int V_8 ;
F_6 ( V_4 -> V_10 ) ;
V_8 = F_7 ( V_4 -> V_10 , V_6 [ V_7 ] . V_15 ,
V_6 [ V_7 ] . V_16 ,
V_14 << V_6 [ V_7 ] . V_17 ) ;
F_8 ( V_4 -> V_10 ) ;
return V_8 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_8 , V_7 = F_3 ( V_2 ) ;
unsigned int V_13 ;
F_4 ( F_5 ( V_2 ) , L_1 , V_9 , V_7 ) ;
F_6 ( V_4 -> V_10 ) ;
V_8 = F_11 ( V_4 -> V_10 ,
V_6 [ V_7 ] . V_15 , & V_13 ) ;
F_8 ( V_4 -> V_10 ) ;
if ( V_8 )
return V_8 ;
V_13 = ( V_13 & V_6 [ V_7 ] . V_16 )
>> V_6 [ V_7 ] . V_17 ;
F_4 ( F_5 ( V_2 ) , L_2 , V_9 , V_7 , V_13 ) ;
F_14 ( V_13 >= V_6 [ V_7 ] . V_18 . V_19 ) ;
return V_2 -> V_18 -> V_20 [ V_13 ] ;
}
int F_15 ( struct V_1 * V_2 , int V_21 ,
int V_22 , unsigned * V_14 )
{
int V_7 = F_3 ( V_2 ) ;
F_4 ( F_5 ( V_2 ) , L_3 ,
V_9 , V_7 , V_21 , V_22 ) ;
if ( V_21 <= V_2 -> V_18 -> V_20 [ 0 ] &&
V_2 -> V_18 -> V_20 [ 0 ] <= V_22 )
return 0 ;
else
return - V_23 ;
}
int F_16 ( struct V_1 * V_2 )
{
int V_7 = F_3 ( V_2 ) ;
F_4 ( F_5 ( V_2 ) , L_1 , V_9 , V_7 ) ;
return V_2 -> V_18 -> V_20 [ 0 ] ;
}
int T_1 F_17 ( struct V_24 * V_25 )
{
struct V_26 * V_27 , * V_28 ;
int V_29 = 0 ;
F_18 ( V_25 -> V_30 . V_27 -> V_31 ) ;
V_27 = F_19 ( V_25 -> V_30 . V_27 -> V_31 , L_4 ) ;
if ( ! V_27 )
return - V_32 ;
F_20 (parent, child)
V_29 ++ ;
return V_29 ;
}
struct V_33 * T_1 F_21 (
struct V_24 * V_25 , struct V_5 * V_34 ,
int V_35 )
{
struct V_3 * V_4 = F_22 ( V_25 ) ;
struct V_33 * V_36 , * V_37 ;
struct V_26 * V_27 , * V_28 ;
int V_38 ;
F_18 ( V_25 -> V_30 . V_27 -> V_31 ) ;
V_27 = F_19 ( V_25 -> V_30 . V_27 -> V_31 , L_4 ) ;
if ( ! V_27 )
return NULL ;
V_36 = F_23 ( & V_25 -> V_30 , sizeof( * V_36 ) * V_4 -> V_35 ,
V_39 ) ;
if ( ! V_36 )
return NULL ;
V_37 = V_36 ;
F_20 (parent, child) {
for ( V_38 = 0 ; V_38 < V_35 ; V_38 ++ ) {
if ( ! F_24 ( V_28 -> V_40 ,
V_34 [ V_38 ] . V_18 . V_40 ) ) {
V_37 -> V_7 = V_38 ;
V_37 -> V_41 = F_25 (
& V_25 -> V_30 , V_28 ) ;
V_37 -> V_42 = V_28 ;
V_37 ++ ;
break;
}
}
}
return V_36 ;
}
