static inline int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 > 0 ;
}
static inline void F_2 ( struct V_1 * V_2 , unsigned int V_4 )
{
V_2 -> V_3 += V_4 ;
}
static inline int F_3 ( struct V_1 * V_2 , unsigned int V_4 )
{
return V_2 -> V_3 -= V_4 ;
}
static void F_4 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
F_5 ( L_1 , V_6 ) ;
F_6 ( F_7 ( V_9 , & V_6 -> V_10 ) ) ;
V_8 = & V_6 -> V_11 ;
F_8 ( ( unsigned long ) V_8 -> V_12 [ 0 ] . V_13 ) ;
V_8 = & V_6 -> V_14 ;
F_8 ( ( unsigned long ) V_8 -> V_12 [ 0 ] . V_13 ) ;
F_9 ( V_6 ) ;
}
int F_10 ( struct V_1 * V_2 , unsigned int V_15 )
{
struct V_16 * V_17 = NULL , * V_18 = NULL ;
struct V_7 * V_8 = NULL ;
struct V_5 * V_6 , * V_19 ;
struct V_20 V_21 ;
int V_22 ;
F_5 ( L_2 ) ;
F_11 ( & V_21 ) ;
for ( V_22 = 0 ; V_22 < V_15 ; V_22 ++ ) {
V_6 = F_12 ( sizeof( struct V_5 ) , V_23 ) ;
if ( V_6 == NULL ) {
F_13 ( V_24 L_3 ) ;
goto V_25;
}
F_5 ( L_4 , V_6 ) ;
F_14 ( & V_6 -> V_26 , & V_21 ) ;
V_6 -> V_27 = V_2 ;
F_11 ( & V_6 -> V_28 ) ;
F_11 ( & V_6 -> V_29 ) ;
V_17 = F_15 ( V_23 ) ;
if ( V_17 == NULL ) {
F_13 ( V_24 L_5 ) ;
goto V_25;
}
V_8 = & V_6 -> V_30 ;
V_8 -> V_12 [ 0 ] . V_13 = F_16 ( V_17 ) ;
V_8 -> V_12 [ 0 ] . V_31 = V_32 ;
V_8 -> V_33 [ 0 ] . V_13 = NULL ;
V_8 -> V_33 [ 0 ] . V_31 = 0 ;
V_8 -> V_34 = 0 ;
V_8 -> V_35 = V_32 ;
V_8 -> V_36 = V_32 ;
V_18 = F_15 ( V_23 ) ;
if ( V_18 == NULL ) {
F_13 ( V_24 L_6 ) ;
goto V_25;
}
V_8 = & V_6 -> V_14 ;
V_8 -> V_12 [ 0 ] . V_13 = F_16 ( V_18 ) ;
V_8 -> V_12 [ 0 ] . V_31 = 0 ;
V_8 -> V_33 [ 0 ] . V_13 = NULL ;
V_8 -> V_33 [ 0 ] . V_31 = 0 ;
V_8 -> V_34 = 0 ;
V_8 -> V_35 = 0 ;
V_8 -> V_36 = V_32 ;
}
F_17 ( & V_2 -> V_37 ) ;
F_18 ( & V_21 , & V_2 -> V_38 ) ;
F_2 ( V_2 , V_15 ) ;
F_19 ( & V_2 -> V_37 ) ;
F_5 ( L_7 ) ;
return 0 ;
V_25:
F_20 (req, tmp, &tmp_list, rq_bc_pa_list) {
F_21 ( & V_6 -> V_26 ) ;
F_4 ( V_6 ) ;
}
F_5 ( L_8 ) ;
return - V_39 ;
}
void F_22 ( struct V_1 * V_2 , unsigned int V_40 )
{
struct V_5 * V_6 = NULL , * V_19 = NULL ;
F_5 ( L_9 ) ;
if ( V_40 == 0 )
goto V_41;
F_17 ( & V_2 -> V_37 ) ;
F_3 ( V_2 , V_40 ) ;
F_20 (req, tmp, &xprt->bc_pa_list, rq_bc_pa_list) {
F_5 ( L_10 , V_6 ) ;
F_21 ( & V_6 -> V_26 ) ;
F_4 ( V_6 ) ;
if ( -- V_40 == 0 )
break;
}
F_19 ( & V_2 -> V_37 ) ;
V_41:
F_5 ( L_11 ,
F_23 ( & V_2 -> V_38 ) ? L_12 : L_13 ) ;
}
struct V_5 * F_24 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
F_5 ( L_14 ) ;
F_25 ( & V_2 -> V_37 ) ;
if ( ! F_23 ( & V_2 -> V_38 ) ) {
V_6 = F_26 ( & V_2 -> V_38 , struct V_5 ,
V_26 ) ;
F_21 ( & V_6 -> V_26 ) ;
} else {
V_6 = NULL ;
}
F_27 ( & V_2 -> V_37 ) ;
if ( V_6 != NULL ) {
F_28 ( V_9 , & V_6 -> V_10 ) ;
V_6 -> V_42 = 0 ;
V_6 -> V_43 = 0 ;
memcpy ( & V_6 -> V_11 , & V_6 -> V_30 ,
sizeof( V_6 -> V_11 ) ) ;
}
F_5 ( L_15 , V_6 ) ;
return V_6 ;
}
void F_29 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_27 ;
F_5 ( L_16 , V_6 ) ;
F_30 () ;
F_6 ( ! F_7 ( V_9 , & V_6 -> V_10 ) ) ;
F_31 ( V_9 , & V_6 -> V_10 ) ;
F_32 () ;
if ( ! F_1 ( V_2 ) ) {
F_5 ( L_17 , V_6 ) ;
F_4 ( V_6 ) ;
return;
}
F_17 ( & V_2 -> V_37 ) ;
F_14 ( & V_6 -> V_26 , & V_2 -> V_38 ) ;
F_19 ( & V_2 -> V_37 ) ;
}
