static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 = F_3 ( V_2 ) ;
F_4 ( F_5 ( V_2 ) , L_1 , V_8 , V_7 ) ;
return F_6 ( V_4 -> V_9 , V_6 [ V_7 ] . V_10 ,
V_6 [ V_7 ] . V_11 ,
V_6 [ V_7 ] . V_11 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 = F_3 ( V_2 ) ;
F_4 ( F_5 ( V_2 ) , L_1 , V_8 , V_7 ) ;
return F_6 ( V_4 -> V_9 , V_6 [ V_7 ] . V_10 ,
V_6 [ V_7 ] . V_11 , 0 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_12 , V_7 = F_3 ( V_2 ) ;
unsigned int V_13 ;
V_12 = F_9 ( V_4 -> V_9 , V_6 [ V_7 ] . V_10 , & V_13 ) ;
if ( V_12 )
return V_12 ;
return ( V_13 & V_6 [ V_7 ] . V_11 ) != 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned V_14 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 = F_3 ( V_2 ) ;
return F_6 ( V_4 -> V_9 , V_6 [ V_7 ] . V_15 ,
V_6 [ V_7 ] . V_16 ,
V_14 << V_6 [ V_7 ] . V_17 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_12 , V_7 = F_3 ( V_2 ) ;
unsigned int V_13 ;
F_4 ( F_5 ( V_2 ) , L_1 , V_8 , V_7 ) ;
V_12 = F_9 ( V_4 -> V_9 ,
V_6 [ V_7 ] . V_15 , & V_13 ) ;
if ( V_12 )
return V_12 ;
V_13 = ( V_13 & V_6 [ V_7 ] . V_16 )
>> V_6 [ V_7 ] . V_17 ;
F_4 ( F_5 ( V_2 ) , L_2 , V_8 , V_7 , V_13 ) ;
F_12 ( V_13 >= V_6 [ V_7 ] . V_18 . V_19 ) ;
return V_2 -> V_18 -> V_20 [ V_13 ] ;
}
int F_13 ( struct V_1 * V_2 , int V_21 ,
int V_22 , unsigned * V_14 )
{
int V_7 = F_3 ( V_2 ) ;
F_4 ( F_5 ( V_2 ) , L_3 ,
V_8 , V_7 , V_21 , V_22 ) ;
if ( V_21 <= V_2 -> V_18 -> V_20 [ 0 ] &&
V_2 -> V_18 -> V_20 [ 0 ] <= V_22 ) {
* V_14 = 0 ;
return 0 ;
} else {
return - V_23 ;
}
}
int F_14 ( struct V_24 * V_25 )
{
struct V_26 * V_27 ;
int V_28 ;
if ( ! V_25 -> V_29 . V_27 -> V_30 )
return - V_31 ;
V_27 = F_15 ( V_25 -> V_29 . V_27 -> V_30 , L_4 ) ;
if ( ! V_27 )
return - V_31 ;
V_28 = F_16 ( V_27 ) ;
F_17 ( V_27 ) ;
return V_28 ;
}
struct V_32 * F_18 (
struct V_24 * V_25 , struct V_5 * V_33 ,
int V_34 )
{
struct V_3 * V_4 = F_19 ( V_25 ) ;
struct V_32 * V_35 , * V_36 ;
struct V_26 * V_27 , * V_37 ;
int V_38 , V_39 = 0 ;
if ( ! V_25 -> V_29 . V_27 -> V_30 )
return NULL ;
V_27 = F_15 ( V_25 -> V_29 . V_27 -> V_30 , L_4 ) ;
if ( ! V_27 )
return NULL ;
V_35 = F_20 ( & V_25 -> V_29 , sizeof( * V_35 ) * V_4 -> V_34 ,
V_40 ) ;
if ( ! V_35 ) {
F_17 ( V_27 ) ;
return NULL ;
}
V_36 = V_35 ;
F_21 (parent, child) {
int V_41 = 0 ;
for ( V_38 = 0 ; V_38 < V_34 ; V_38 ++ ) {
if ( ! V_33 [ V_38 ] . V_18 . V_42 )
continue;
if ( ! F_22 ( V_37 -> V_42 ,
V_33 [ V_38 ] . V_18 . V_42 ) ) {
V_36 -> V_7 = V_38 ;
V_36 -> V_43 = F_23 (
& V_25 -> V_29 , V_37 ,
& V_33 [ V_38 ] . V_18 ) ;
V_36 -> V_44 = V_37 ;
V_36 ++ ;
V_39 ++ ;
V_41 = 1 ;
break;
}
}
if ( ! V_41 )
F_24 ( & V_25 -> V_29 ,
L_5 , V_37 -> V_42 ) ;
}
F_17 ( V_27 ) ;
V_4 -> V_34 = V_39 ;
return V_35 ;
}
