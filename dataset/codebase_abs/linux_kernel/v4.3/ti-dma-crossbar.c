static inline void F_1 ( void T_1 * V_1 , int V_2 , T_2 V_3 )
{
F_2 ( V_3 , V_1 + ( V_2 * 2 ) ) ;
}
static void F_3 ( struct V_4 * V_5 , void * V_6 )
{
struct V_7 * V_2 = F_4 ( V_5 ) ;
struct V_8 * V_9 = V_6 ;
F_5 ( V_5 , L_1 ,
V_9 -> V_10 , V_9 -> V_11 ) ;
F_1 ( V_2 -> V_1 , V_9 -> V_11 , V_2 -> V_12 ) ;
F_6 ( & V_2 -> V_13 , V_9 -> V_11 ) ;
F_7 ( V_9 ) ;
}
static void * F_8 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 = F_9 ( V_17 -> V_20 ) ;
struct V_7 * V_2 = F_10 ( V_19 ) ;
struct V_8 * V_9 ;
if ( V_15 -> args [ 0 ] >= V_2 -> V_21 ) {
F_11 ( & V_19 -> V_5 , L_2 ,
V_15 -> args [ 0 ] ) ;
return F_12 ( - V_22 ) ;
}
V_15 -> V_23 = F_13 ( V_17 -> V_20 , L_3 , 0 ) ;
if ( ! V_15 -> V_23 ) {
F_11 ( & V_19 -> V_5 , L_4 ) ;
return F_12 ( - V_22 ) ;
}
V_9 = F_14 ( sizeof( * V_9 ) , V_24 ) ;
if ( ! V_9 ) {
F_15 ( V_15 -> V_23 ) ;
return F_12 ( - V_25 ) ;
}
V_9 -> V_11 = F_16 ( & V_2 -> V_13 , NULL , 0 , V_2 -> V_26 ,
V_24 ) ;
V_9 -> V_10 = ( T_2 ) V_15 -> args [ 0 ] ;
V_15 -> args [ 0 ] = V_9 -> V_11 + V_2 -> V_27 ;
F_5 ( & V_19 -> V_5 , L_5 ,
V_9 -> V_10 , V_9 -> V_11 ) ;
F_1 ( V_2 -> V_1 , V_9 -> V_11 , V_9 -> V_10 ) ;
return V_9 ;
}
static int F_17 ( struct V_18 * V_19 )
{
struct V_28 * V_29 = V_19 -> V_5 . V_20 ;
const struct V_30 * V_31 ;
struct V_28 * V_32 ;
struct V_7 * V_2 ;
struct V_33 * V_34 ;
T_3 V_12 ;
void T_1 * V_1 ;
int V_35 , V_36 ;
if ( ! V_29 )
return - V_37 ;
V_2 = F_18 ( & V_19 -> V_5 , sizeof( * V_2 ) , V_24 ) ;
if ( ! V_2 )
return - V_25 ;
F_19 ( & V_2 -> V_13 ) ;
V_32 = F_13 ( V_29 , L_3 , 0 ) ;
if ( ! V_32 ) {
F_11 ( & V_19 -> V_5 , L_6 ) ;
return - V_37 ;
}
V_31 = F_20 ( V_38 , V_32 ) ;
if ( ! V_31 ) {
F_11 ( & V_19 -> V_5 , L_7 ) ;
return - V_22 ;
}
if ( F_21 ( V_32 , L_8 ,
& V_2 -> V_26 ) ) {
F_22 ( & V_19 -> V_5 ,
L_9 ,
V_39 ) ;
V_2 -> V_26 = V_39 ;
}
F_15 ( V_32 ) ;
if ( F_21 ( V_29 , L_8 , & V_2 -> V_21 ) ) {
F_22 ( & V_19 -> V_5 ,
L_10 ,
V_40 ) ;
V_2 -> V_21 = V_40 ;
}
if ( ! F_21 ( V_29 , L_11 , & V_12 ) )
V_2 -> V_12 = ( T_2 ) V_12 ;
V_34 = F_23 ( V_19 , V_41 , 0 ) ;
V_1 = F_24 ( & V_19 -> V_5 , V_34 ) ;
if ( F_25 ( V_1 ) )
return F_26 ( V_1 ) ;
V_2 -> V_1 = V_1 ;
V_2 -> V_42 . V_5 = & V_19 -> V_5 ;
V_2 -> V_42 . V_43 = F_3 ;
V_2 -> V_27 = ( T_3 ) V_31 -> V_44 ;
F_27 ( V_19 , V_2 ) ;
for ( V_35 = 0 ; V_35 < V_2 -> V_26 ; V_35 ++ )
F_1 ( V_2 -> V_1 , V_35 , V_2 -> V_12 ) ;
V_36 = F_28 ( V_29 , F_8 ,
& V_2 -> V_42 ) ;
if ( V_36 ) {
for ( V_35 = 0 ; V_35 < V_2 -> V_26 ; V_35 ++ )
F_1 ( V_2 -> V_1 , V_35 , V_35 ) ;
}
return V_36 ;
}
int F_29 ( void )
{
return F_30 ( & V_45 ) ;
}
