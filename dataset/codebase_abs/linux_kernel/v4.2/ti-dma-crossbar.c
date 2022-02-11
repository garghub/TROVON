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
F_6 ( & V_13 , V_9 -> V_11 ) ;
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
V_9 -> V_11 = F_16 ( & V_13 , NULL , 0 , V_2 -> V_26 ,
V_24 ) ;
V_9 -> V_10 = ( T_2 ) V_15 -> args [ 0 ] ;
V_15 -> args [ 0 ] = V_9 -> V_11 + 1 ;
F_5 ( & V_19 -> V_5 , L_5 ,
V_9 -> V_10 , V_9 -> V_11 ) ;
F_1 ( V_2 -> V_1 , V_9 -> V_11 , V_9 -> V_10 ) ;
return V_9 ;
}
static int F_17 ( struct V_18 * V_19 )
{
struct V_27 * V_28 = V_19 -> V_5 . V_20 ;
struct V_27 * V_29 ;
struct V_7 * V_2 ;
struct V_30 * V_31 ;
T_3 V_12 ;
void T_1 * V_1 ;
int V_32 , V_33 ;
if ( ! V_28 )
return - V_34 ;
V_2 = F_18 ( & V_19 -> V_5 , sizeof( * V_2 ) , V_24 ) ;
if ( ! V_2 )
return - V_25 ;
V_29 = F_13 ( V_28 , L_3 , 0 ) ;
if ( ! V_29 ) {
F_11 ( & V_19 -> V_5 , L_6 ) ;
return - V_34 ;
}
if ( F_19 ( V_29 , L_7 ,
& V_2 -> V_26 ) ) {
F_20 ( & V_19 -> V_5 ,
L_8 ,
V_35 ) ;
V_2 -> V_26 = V_35 ;
}
F_15 ( V_29 ) ;
if ( F_19 ( V_28 , L_7 , & V_2 -> V_21 ) ) {
F_20 ( & V_19 -> V_5 ,
L_9 ,
V_36 ) ;
V_2 -> V_21 = V_36 ;
}
if ( ! F_19 ( V_28 , L_10 , & V_12 ) )
V_2 -> V_12 = ( T_2 ) V_12 ;
V_31 = F_21 ( V_19 , V_37 , 0 ) ;
if ( ! V_31 )
return - V_34 ;
V_1 = F_22 ( & V_19 -> V_5 , V_31 ) ;
if ( ! V_1 )
return - V_25 ;
V_2 -> V_1 = V_1 ;
V_2 -> V_38 . V_5 = & V_19 -> V_5 ;
V_2 -> V_38 . V_39 = F_3 ;
F_23 ( V_19 , V_2 ) ;
for ( V_32 = 0 ; V_32 < V_2 -> V_26 ; V_32 ++ )
F_1 ( V_2 -> V_1 , V_32 , V_2 -> V_12 ) ;
V_33 = F_24 ( V_28 , F_8 ,
& V_2 -> V_38 ) ;
if ( V_33 ) {
for ( V_32 = 0 ; V_32 < V_2 -> V_26 ; V_32 ++ )
F_1 ( V_2 -> V_1 , V_32 , V_32 ) ;
}
return V_33 ;
}
int F_25 ( void )
{
return F_26 ( & V_40 ) ;
}
