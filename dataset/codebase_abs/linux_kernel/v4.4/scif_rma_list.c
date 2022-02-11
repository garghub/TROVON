void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_1 * V_5 = NULL ;
struct V_1 * V_6 = F_2 ( V_4 , struct V_1 , V_7 ) ;
struct V_3 * V_8 ;
F_3 ( & V_2 -> V_7 ) ;
if ( ! F_4 ( V_4 ) ) {
V_5 = F_2 ( V_4 -> V_6 , struct V_1 , V_7 ) ;
if ( V_5 -> V_9 < V_2 -> V_9 ) {
F_5 ( & V_2 -> V_7 , V_4 ) ;
return;
}
}
F_6 (item, head) {
V_5 = F_2 ( V_8 , struct V_1 , V_7 ) ;
if ( V_5 -> V_9 > V_2 -> V_9 )
break;
V_6 = V_5 ;
}
F_7 ( & V_2 -> V_7 , & V_6 -> V_7 ) ;
}
void F_8 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_1 * V_5 = NULL , * V_6 = NULL ;
struct V_3 * V_8 ;
F_3 ( & V_2 -> V_7 ) ;
F_6 (item, head) {
V_5 = F_2 ( V_8 , struct V_1 , V_7 ) ;
if ( V_5 -> V_10 > V_2 -> V_10 )
break;
V_6 = V_5 ;
}
if ( ! V_6 )
F_7 ( & V_2 -> V_7 , V_4 ) ;
else
F_7 ( & V_2 -> V_7 , & V_6 -> V_7 ) ;
F_9 ( V_2 , V_2 -> V_11 ) ;
}
int F_10 ( struct V_12 * V_13 , struct V_14 * V_15 )
{
struct V_3 * V_8 , * V_16 , * V_4 = V_15 -> V_4 ;
struct V_1 * V_2 ;
T_1 V_17 , V_18 = V_15 -> V_9 ;
T_1 V_19 , V_20 = V_18 + V_15 -> V_21 ;
if ( ! V_15 -> V_21 )
return - V_22 ;
if ( ! F_4 ( V_4 ) ) {
V_2 = F_11 ( V_4 , struct V_1 , V_7 ) ;
V_19 = V_2 -> V_9 +
( V_2 -> V_11 << V_23 ) ;
if ( V_18 > V_19 )
return - V_24 ;
}
F_12 (item, temp, head) {
V_2 = F_2 ( V_8 , struct V_1 , V_7 ) ;
V_17 = V_2 -> V_9 ;
V_19 = V_2 -> V_9 +
( V_2 -> V_11 << V_23 ) ;
if ( V_18 < V_17 &&
V_20 < V_17 )
break;
if ( V_18 >= V_19 )
continue;
if ( ( V_2 -> V_25 & V_15 -> V_25 ) == V_15 -> V_25 ) {
if ( V_18 >= V_17 &&
V_20 <= V_19 ) {
* V_15 -> V_26 = V_2 ;
return 0 ;
}
if ( V_18 < V_17 ) {
V_15 -> V_21 +=
V_17 - V_18 ;
V_15 -> V_9 = V_17 ;
}
if ( V_20 >= V_19 )
V_15 -> V_21 += V_19 - V_20 ;
}
F_13 ( V_2 ) ;
break;
}
return - V_24 ;
}
int F_14 ( struct V_14 * V_15 )
{
struct V_3 * V_8 ;
struct V_1 * V_2 ;
T_2 V_27 , V_10 = V_15 -> V_10 ;
T_1 V_28 , V_29 = V_15 -> V_21 ;
if ( ! V_15 -> V_21 )
return - V_22 ;
F_6 (item, req->head) {
V_2 = F_2 ( V_8 , struct V_1 , V_7 ) ;
V_27 = V_2 -> V_10 +
( V_2 -> V_11 << V_23 ) ;
if ( V_10 < V_2 -> V_10 )
return - V_24 ;
if ( V_10 >= V_27 )
continue;
if ( ( V_2 -> V_25 & V_15 -> V_25 ) != V_15 -> V_25 )
return - V_30 ;
if ( V_29 == V_15 -> V_21 )
* V_15 -> V_26 = V_2 ;
V_28 = F_15 ( ( T_1 ) V_27 - V_10 , V_29 ) ;
V_29 -= V_28 ;
V_10 += V_28 ;
if ( ! V_29 ) {
if ( V_15 -> type == V_31 ||
V_15 -> type == V_32 )
return 0 ;
if ( V_10 == V_27 )
return 0 ;
return - V_24 ;
}
if ( V_15 -> type == V_32 )
break;
}
F_16 ( V_33 . V_34 . V_35 ,
L_1 , V_36 , __LINE__ ) ;
return - V_24 ;
}
int F_17 ( struct V_1 * V_2 ,
T_2 V_10 , int V_11 )
{
struct V_12 * V_13 = (struct V_12 * ) V_2 -> V_13 ;
struct V_3 * V_4 = & V_13 -> V_37 . V_38 ;
T_2 V_27 ;
int V_39 = 0 ;
int V_40 ;
struct V_1 * V_41 ;
F_18 (window, _window, head, list) {
V_27 = V_2 -> V_10 + ( V_2 -> V_11 << V_23 ) ;
V_40 = F_15 ( ( int ) ( ( V_27 - V_10 ) >> V_23 ) ,
V_11 ) ;
V_39 = F_19 ( V_2 ) ;
if ( V_39 )
return V_39 ;
V_11 -= V_40 ;
V_10 += ( V_40 << V_23 ) ;
if ( ! V_11 )
break;
}
return 0 ;
}
void F_20 ( T_3 V_42 )
{
struct V_3 * V_8 , * V_43 ;
struct V_1 * V_2 ;
struct V_12 * V_13 = (struct V_12 * ) V_42 ;
struct V_3 * V_4 = & V_13 -> V_37 . V_38 ;
F_21 ( & V_13 -> V_37 . V_44 ) ;
F_12 (item, tmp, head) {
V_2 = F_2 ( V_8 , struct V_1 , V_7 ) ;
F_22 ( V_13 -> V_45 , V_2 ) ;
}
F_23 ( & V_13 -> V_37 . V_44 ) ;
}
int F_24 ( T_3 V_42 )
{
struct V_3 * V_8 , * V_43 ;
struct V_1 * V_2 ;
struct V_12 * V_13 = (struct V_12 * ) V_42 ;
struct V_3 * V_4 = & V_13 -> V_37 . V_38 ;
int V_39 = 0 ;
F_21 ( & V_13 -> V_37 . V_44 ) ;
V_46:
V_8 = NULL ;
V_43 = NULL ;
F_12 (item, tmp, head) {
V_2 = F_2 ( V_8 , struct V_1 , V_7 ) ;
V_13 -> V_37 . V_47 = 0 ;
V_39 = F_19 ( V_2 ) ;
if ( V_39 )
F_16 ( V_33 . V_34 . V_35 ,
L_2 ,
V_36 , __LINE__ , V_39 ) ;
if ( F_25 ( V_13 -> V_37 . V_47 ) )
goto V_46;
}
F_23 ( & V_13 -> V_37 . V_44 ) ;
if ( ! F_4 ( & V_13 -> V_37 . V_48 ) ) {
F_26 ( & V_33 . V_49 ) ;
F_5 ( & V_13 -> V_50 , & V_33 . V_51 ) ;
F_27 ( & V_33 . V_49 ) ;
F_28 ( & V_33 . V_52 ) ;
}
return V_39 ;
}
