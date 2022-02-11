static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 ,
V_5 . V_6 . V_2 . V_2 ) ;
struct V_7 * V_6 = & V_4 -> V_5 . V_6 ;
unsigned long V_8 = V_9 ;
struct V_10 * V_11 ;
struct V_10 * V_12 ;
int V_13 = 0 ;
F_3 ( & V_6 -> V_14 ) ;
F_4 ( & V_6 -> V_15 , & V_6 -> V_16 ) ;
if ( ! F_5 ( & V_6 -> V_16 ) )
F_6 ( V_6 -> V_17 , & V_6 -> V_2 , V_18 ) ;
F_7 ( & V_6 -> V_14 ) ;
F_8 (counter, tmp, &fc_stats->list, list) {
struct V_19 * V_20 = & V_11 -> V_21 ;
T_1 V_22 ;
T_1 V_23 ;
if ( V_11 -> V_24 ) {
F_9 ( & V_11 -> V_16 ) ;
F_10 ( V_4 , V_11 -> V_25 ) ;
F_11 ( V_11 ) ;
continue;
}
if ( F_12 ( V_8 , V_6 -> V_26 ) )
continue;
V_13 = F_13 ( V_4 , V_11 -> V_25 , & V_22 , & V_23 ) ;
if ( V_13 ) {
F_14 ( L_1 ,
V_11 -> V_25 ) ;
continue;
}
if ( V_22 == V_20 -> V_22 )
continue;
V_20 -> V_27 = V_9 ;
V_20 -> V_22 = V_22 ;
V_20 -> V_23 = V_23 ;
}
if ( F_15 ( V_8 , V_6 -> V_26 ) )
V_6 -> V_26 = V_8 + V_18 ;
}
struct V_10 * F_16 ( struct V_3 * V_4 , bool V_28 )
{
struct V_7 * V_6 = & V_4 -> V_5 . V_6 ;
struct V_10 * V_11 ;
int V_13 ;
V_11 = F_17 ( sizeof( * V_11 ) , V_29 ) ;
if ( ! V_11 )
return F_18 ( - V_30 ) ;
V_13 = F_19 ( V_4 , & V_11 -> V_25 ) ;
if ( V_13 )
goto V_31;
if ( V_28 ) {
V_11 -> V_28 = true ;
F_3 ( & V_6 -> V_14 ) ;
F_20 ( & V_11 -> V_16 , & V_6 -> V_15 ) ;
F_7 ( & V_6 -> V_14 ) ;
F_21 ( V_6 -> V_17 , & V_6 -> V_2 , 0 ) ;
}
return V_11 ;
V_31:
F_11 ( V_11 ) ;
return F_18 ( V_13 ) ;
}
void F_22 ( struct V_3 * V_4 , struct V_10 * V_11 )
{
struct V_7 * V_6 = & V_4 -> V_5 . V_6 ;
if ( ! V_11 )
return;
if ( V_11 -> V_28 ) {
V_11 -> V_24 = true ;
F_21 ( V_6 -> V_17 , & V_6 -> V_2 , 0 ) ;
return;
}
F_10 ( V_4 , V_11 -> V_25 ) ;
F_11 ( V_11 ) ;
}
int F_23 ( struct V_3 * V_4 )
{
struct V_7 * V_6 = & V_4 -> V_5 . V_6 ;
F_24 ( & V_6 -> V_16 ) ;
F_24 ( & V_6 -> V_15 ) ;
F_25 ( & V_6 -> V_14 ) ;
V_6 -> V_17 = F_26 ( L_2 ) ;
if ( ! V_6 -> V_17 )
return - V_30 ;
F_27 ( & V_6 -> V_2 , F_1 ) ;
return 0 ;
}
void F_28 ( struct V_3 * V_4 )
{
struct V_7 * V_6 = & V_4 -> V_5 . V_6 ;
struct V_10 * V_11 ;
struct V_10 * V_12 ;
F_29 ( & V_4 -> V_5 . V_6 . V_2 ) ;
F_30 ( V_4 -> V_5 . V_6 . V_17 ) ;
V_4 -> V_5 . V_6 . V_17 = NULL ;
F_4 ( & V_6 -> V_15 , & V_6 -> V_16 ) ;
F_8 (counter, tmp, &fc_stats->list, list) {
F_9 ( & V_11 -> V_16 ) ;
F_10 ( V_4 , V_11 -> V_25 ) ;
F_11 ( V_11 ) ;
}
}
void F_31 ( struct V_10 * V_11 ,
T_1 * V_23 , T_1 * V_22 , T_1 * V_27 )
{
struct V_19 V_20 ;
V_20 = V_11 -> V_21 ;
* V_23 = V_20 . V_23 - V_11 -> V_32 ;
* V_22 = V_20 . V_22 - V_11 -> V_33 ;
* V_27 = V_20 . V_27 ;
V_11 -> V_32 = V_20 . V_23 ;
V_11 -> V_33 = V_20 . V_22 ;
}
