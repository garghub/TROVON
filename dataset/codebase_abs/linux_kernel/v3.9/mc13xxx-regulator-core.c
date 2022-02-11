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
V_2 -> V_18 -> V_20 [ 0 ] <= V_22 ) {
* V_14 = 0 ;
return 0 ;
} else {
return - V_23 ;
}
}
int F_16 ( struct V_24 * V_25 )
{
struct V_26 * V_27 ;
int V_28 ;
F_17 ( V_25 -> V_29 . V_27 -> V_30 ) ;
V_27 = F_18 ( V_25 -> V_29 . V_27 -> V_30 , L_4 ) ;
if ( ! V_27 )
return - V_31 ;
V_28 = F_19 ( V_27 ) ;
F_20 ( V_27 ) ;
return V_28 ;
}
struct V_32 * F_21 (
struct V_24 * V_25 , struct V_5 * V_33 ,
int V_34 , int * V_35 )
{
struct V_3 * V_4 = F_22 ( V_25 ) ;
struct V_32 * V_36 , * V_37 ;
struct V_26 * V_27 , * V_38 ;
int V_39 , V_40 = 0 ;
* V_35 = 0 ;
F_17 ( V_25 -> V_29 . V_27 -> V_30 ) ;
V_27 = F_18 ( V_25 -> V_29 . V_27 -> V_30 , L_4 ) ;
if ( ! V_27 )
return NULL ;
V_36 = F_23 ( & V_25 -> V_29 , sizeof( * V_36 ) * V_4 -> V_34 ,
V_41 ) ;
if ( ! V_36 ) {
F_20 ( V_27 ) ;
return NULL ;
}
V_37 = V_36 ;
F_24 (parent, child) {
for ( V_39 = 0 ; V_39 < V_34 ; V_39 ++ ) {
if ( ! F_25 ( V_38 -> V_42 ,
V_33 [ V_39 ] . V_18 . V_42 ) ) {
V_37 -> V_7 = V_39 ;
V_37 -> V_43 = F_26 (
& V_25 -> V_29 , V_38 ) ;
V_37 -> V_44 = V_38 ;
V_37 ++ ;
V_40 ++ ;
break;
}
}
}
F_20 ( V_27 ) ;
* V_35 = V_40 ;
return V_36 ;
}
