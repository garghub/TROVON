struct V_1 *
F_1 ( struct V_2 * V_3 , int V_4 )
{
struct V_1 * V_5 ;
F_2 (head, &disp->head, head) {
if ( V_5 -> V_4 == V_4 )
return V_5 ;
}
return NULL ;
}
int
F_3 ( struct V_6 * V_7 ,
struct V_1 * V_5 , void * V_8 , T_1 V_9 )
{
union {
struct V_10 V_11 ;
} * args = V_8 ;
int V_12 = - V_13 ;
F_4 ( V_7 , L_1 , V_9 ) ;
if ( ! ( V_12 = F_5 ( V_12 , & V_8 , & V_9 , args -> V_11 , 0 , 0 , false ) ) ) {
F_4 ( V_7 , L_2 ,
args -> V_11 . V_14 ) ;
V_5 -> V_15 -> V_16 ( V_5 , & V_5 -> V_17 ) ;
args -> V_11 . V_18 = V_5 -> V_17 . V_18 ;
args -> V_11 . V_19 = V_5 -> V_17 . V_19 ;
args -> V_11 . V_20 = V_5 -> V_17 . V_20 ;
args -> V_11 . V_21 = V_5 -> V_17 . V_21 ;
args -> V_11 . V_22 = V_5 -> V_17 . V_22 ;
args -> V_11 . V_23 = V_5 -> V_17 . V_23 ;
if ( ! args -> V_11 . V_18 || ! args -> V_11 . V_21 )
return - V_24 ;
args -> V_11 . time [ 0 ] = F_6 ( F_7 () ) ;
V_5 -> V_15 -> V_25 ( V_5 , & args -> V_11 . V_26 , & args -> V_11 . V_27 ) ;
args -> V_11 . time [ 1 ] = F_6 ( F_7 () ) ;
} else
return V_12 ;
return 0 ;
}
void
F_8 ( struct V_1 * * V_28 )
{
struct V_1 * V_5 = * V_28 ;
if ( V_5 ) {
F_9 ( V_5 , L_3 ) ;
F_10 ( & V_5 -> V_5 ) ;
F_11 ( * V_28 ) ;
* V_28 = NULL ;
}
}
int
F_12 ( const struct V_29 * V_15 ,
struct V_2 * V_3 , int V_4 )
{
struct V_1 * V_5 ;
if ( ! ( V_5 = F_13 ( sizeof( * V_5 ) , V_30 ) ) )
return - V_31 ;
V_5 -> V_15 = V_15 ;
V_5 -> V_3 = V_3 ;
V_5 -> V_4 = V_4 ;
F_14 ( & V_5 -> V_5 , & V_3 -> V_5 ) ;
F_9 ( V_5 , L_4 ) ;
return 0 ;
}
