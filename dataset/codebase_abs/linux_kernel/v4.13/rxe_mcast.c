int F_1 ( struct V_1 * V_2 , union V_3 * V_4 ,
struct V_5 * * V_6 )
{
int V_7 ;
struct V_5 * V_8 ;
if ( V_2 -> V_9 . V_10 == 0 ) {
V_7 = - V_11 ;
goto V_12;
}
V_8 = F_2 ( & V_2 -> V_13 , V_4 ) ;
if ( V_8 )
goto V_14;
V_8 = F_3 ( & V_2 -> V_13 ) ;
if ( ! V_8 ) {
V_7 = - V_15 ;
goto V_12;
}
F_4 ( & V_8 -> V_16 ) ;
F_5 ( & V_8 -> V_17 ) ;
V_8 -> V_2 = V_2 ;
F_6 ( V_8 , V_4 ) ;
V_7 = F_7 ( V_2 , V_4 ) ;
if ( V_7 )
goto V_18;
V_14:
* V_6 = V_8 ;
return 0 ;
V_18:
F_8 ( V_8 ) ;
V_12:
return V_7 ;
}
int F_9 ( struct V_1 * V_2 , struct V_19 * V_20 ,
struct V_5 * V_8 )
{
int V_7 ;
struct V_21 * V_22 ;
F_10 ( & V_20 -> V_23 ) ;
F_10 ( & V_8 -> V_17 ) ;
F_11 (elem, &grp->qp_list, qp_list) {
if ( V_22 -> V_20 == V_20 ) {
V_7 = 0 ;
goto V_24;
}
}
if ( V_8 -> V_25 >= V_2 -> V_9 . V_10 ) {
V_7 = - V_15 ;
goto V_24;
}
V_22 = F_3 ( & V_2 -> V_26 ) ;
if ( ! V_22 ) {
V_7 = - V_15 ;
goto V_24;
}
F_12 ( V_8 ) ;
V_8 -> V_25 ++ ;
V_22 -> V_20 = V_20 ;
V_22 -> V_8 = V_8 ;
F_13 ( & V_22 -> V_16 , & V_8 -> V_16 ) ;
F_13 ( & V_22 -> V_27 , & V_20 -> V_27 ) ;
V_7 = 0 ;
V_24:
F_14 ( & V_8 -> V_17 ) ;
F_14 ( & V_20 -> V_23 ) ;
return V_7 ;
}
int F_15 ( struct V_1 * V_2 , struct V_19 * V_20 ,
union V_3 * V_4 )
{
struct V_5 * V_8 ;
struct V_21 * V_22 , * V_28 ;
V_8 = F_2 ( & V_2 -> V_13 , V_4 ) ;
if ( ! V_8 )
goto V_12;
F_10 ( & V_20 -> V_23 ) ;
F_10 ( & V_8 -> V_17 ) ;
F_16 (elem, tmp, &grp->qp_list, qp_list) {
if ( V_22 -> V_20 == V_20 ) {
F_17 ( & V_22 -> V_16 ) ;
F_17 ( & V_22 -> V_27 ) ;
V_8 -> V_25 -- ;
F_14 ( & V_8 -> V_17 ) ;
F_14 ( & V_20 -> V_23 ) ;
F_8 ( V_22 ) ;
F_8 ( V_8 ) ;
F_8 ( V_8 ) ;
return 0 ;
}
}
F_14 ( & V_8 -> V_17 ) ;
F_14 ( & V_20 -> V_23 ) ;
F_8 ( V_8 ) ;
V_12:
return - V_11 ;
}
void F_18 ( struct V_19 * V_20 )
{
struct V_5 * V_8 ;
struct V_21 * V_22 ;
while ( 1 ) {
F_10 ( & V_20 -> V_23 ) ;
if ( F_19 ( & V_20 -> V_27 ) ) {
F_14 ( & V_20 -> V_23 ) ;
break;
}
V_22 = F_20 ( & V_20 -> V_27 , struct V_21 ,
V_27 ) ;
F_17 ( & V_22 -> V_27 ) ;
F_14 ( & V_20 -> V_23 ) ;
V_8 = V_22 -> V_8 ;
F_10 ( & V_8 -> V_17 ) ;
F_17 ( & V_22 -> V_16 ) ;
V_8 -> V_25 -- ;
F_14 ( & V_8 -> V_17 ) ;
F_8 ( V_8 ) ;
F_8 ( V_22 ) ;
}
}
void F_21 ( struct V_29 * V_30 )
{
struct V_5 * V_8 = F_22 ( V_30 , F_23 ( * V_8 ) , V_31 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
F_24 ( V_8 ) ;
F_25 ( V_2 , & V_8 -> V_4 ) ;
}
