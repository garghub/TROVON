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
V_7 = V_2 -> V_18 -> V_19 ( V_2 , V_4 ) ;
if ( V_7 )
goto V_20;
V_14:
* V_6 = V_8 ;
return 0 ;
V_20:
F_7 ( V_8 ) ;
V_12:
return V_7 ;
}
int F_8 ( struct V_1 * V_2 , struct V_21 * V_22 ,
struct V_5 * V_8 )
{
int V_7 ;
struct V_23 * V_24 ;
F_9 ( & V_22 -> V_25 ) ;
F_9 ( & V_8 -> V_17 ) ;
F_10 (elem, &grp->qp_list, qp_list) {
if ( V_24 -> V_22 == V_22 ) {
V_7 = 0 ;
goto V_26;
}
}
if ( V_8 -> V_27 >= V_2 -> V_9 . V_10 ) {
V_7 = - V_15 ;
goto V_26;
}
V_24 = F_3 ( & V_2 -> V_28 ) ;
if ( ! V_24 ) {
V_7 = - V_15 ;
goto V_26;
}
F_11 ( V_8 ) ;
V_8 -> V_27 ++ ;
V_24 -> V_22 = V_22 ;
V_24 -> V_8 = V_8 ;
F_12 ( & V_24 -> V_16 , & V_8 -> V_16 ) ;
F_12 ( & V_24 -> V_29 , & V_22 -> V_29 ) ;
V_7 = 0 ;
V_26:
F_13 ( & V_8 -> V_17 ) ;
F_13 ( & V_22 -> V_25 ) ;
return V_7 ;
}
int F_14 ( struct V_1 * V_2 , struct V_21 * V_22 ,
union V_3 * V_4 )
{
struct V_5 * V_8 ;
struct V_23 * V_24 , * V_30 ;
V_8 = F_2 ( & V_2 -> V_13 , V_4 ) ;
if ( ! V_8 )
goto V_12;
F_9 ( & V_22 -> V_25 ) ;
F_9 ( & V_8 -> V_17 ) ;
F_15 (elem, tmp, &grp->qp_list, qp_list) {
if ( V_24 -> V_22 == V_22 ) {
F_16 ( & V_24 -> V_16 ) ;
F_16 ( & V_24 -> V_29 ) ;
V_8 -> V_27 -- ;
F_13 ( & V_8 -> V_17 ) ;
F_13 ( & V_22 -> V_25 ) ;
F_7 ( V_24 ) ;
F_7 ( V_8 ) ;
F_7 ( V_8 ) ;
return 0 ;
}
}
F_13 ( & V_8 -> V_17 ) ;
F_13 ( & V_22 -> V_25 ) ;
F_7 ( V_8 ) ;
V_12:
return - V_11 ;
}
void F_17 ( struct V_21 * V_22 )
{
struct V_5 * V_8 ;
struct V_23 * V_24 ;
while ( 1 ) {
F_9 ( & V_22 -> V_25 ) ;
if ( F_18 ( & V_22 -> V_29 ) ) {
F_13 ( & V_22 -> V_25 ) ;
break;
}
V_24 = F_19 ( & V_22 -> V_29 , struct V_23 ,
V_29 ) ;
F_16 ( & V_24 -> V_29 ) ;
F_13 ( & V_22 -> V_25 ) ;
V_8 = V_24 -> V_8 ;
F_9 ( & V_8 -> V_17 ) ;
F_16 ( & V_24 -> V_16 ) ;
V_8 -> V_27 -- ;
F_13 ( & V_8 -> V_17 ) ;
F_7 ( V_8 ) ;
F_7 ( V_24 ) ;
}
}
void F_20 ( void * V_31 )
{
struct V_5 * V_8 = V_31 ;
struct V_1 * V_2 = V_8 -> V_2 ;
F_21 ( V_8 ) ;
V_2 -> V_18 -> V_32 ( V_2 , & V_8 -> V_4 ) ;
}
