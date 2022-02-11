static inline int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 < F_2 ( & V_2 -> V_4 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , unsigned int V_5 )
{
F_4 ( V_5 , & V_2 -> V_4 ) ;
V_2 -> V_3 += V_5 ;
}
static inline int F_5 ( struct V_1 * V_2 , unsigned int V_5 )
{
F_6 ( V_5 , & V_2 -> V_4 ) ;
return V_2 -> V_3 -= V_5 ;
}
static void F_7 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
F_8 ( L_1 , V_7 ) ;
F_9 ( F_10 ( V_10 , & V_7 -> V_11 ) ) ;
V_9 = & V_7 -> V_12 ;
F_11 ( ( unsigned long ) V_9 -> V_13 [ 0 ] . V_14 ) ;
V_9 = & V_7 -> V_15 ;
F_11 ( ( unsigned long ) V_9 -> V_13 [ 0 ] . V_14 ) ;
F_12 ( V_7 ) ;
}
static int F_13 ( struct V_8 * V_16 , T_1 V_17 )
{
struct V_18 * V_18 ;
V_18 = F_14 ( V_17 ) ;
if ( V_18 == NULL )
return - V_19 ;
V_16 -> V_13 [ 0 ] . V_14 = F_15 ( V_18 ) ;
V_16 -> V_13 [ 0 ] . V_20 = V_21 ;
V_16 -> V_22 [ 0 ] . V_14 = NULL ;
V_16 -> V_22 [ 0 ] . V_20 = 0 ;
V_16 -> V_23 = 0 ;
V_16 -> V_24 = 0 ;
V_16 -> V_25 = V_21 ;
return 0 ;
}
static
struct V_6 * F_16 ( struct V_1 * V_2 , T_1 V_17 )
{
struct V_6 * V_7 ;
V_7 = F_17 ( sizeof( * V_7 ) , V_17 ) ;
if ( V_7 == NULL )
return NULL ;
V_7 -> V_26 = V_2 ;
F_18 ( & V_7 -> V_27 ) ;
F_18 ( & V_7 -> V_28 ) ;
if ( F_13 ( & V_7 -> V_12 , V_17 ) < 0 ) {
F_19 ( V_29 L_2 ) ;
goto V_30;
}
V_7 -> V_12 . V_24 = V_21 ;
if ( F_13 ( & V_7 -> V_15 , V_17 ) < 0 ) {
F_19 ( V_29 L_3 ) ;
goto V_30;
}
return V_7 ;
V_30:
F_7 ( V_7 ) ;
return NULL ;
}
int F_20 ( struct V_1 * V_2 , unsigned int V_31 )
{
struct V_6 * V_7 ;
struct V_32 V_33 ;
int V_34 ;
F_8 ( L_4 ) ;
F_18 ( & V_33 ) ;
for ( V_34 = 0 ; V_34 < V_31 ; V_34 ++ ) {
V_7 = F_16 ( V_2 , V_35 ) ;
if ( V_7 == NULL ) {
F_19 ( V_29 L_5 ) ;
goto V_30;
}
F_8 ( L_6 , V_7 ) ;
F_21 ( & V_7 -> V_36 , & V_33 ) ;
}
F_22 ( & V_2 -> V_37 ) ;
F_23 ( & V_33 , & V_2 -> V_38 ) ;
F_3 ( V_2 , V_31 ) ;
F_24 ( & V_2 -> V_37 ) ;
F_8 ( L_7 ) ;
return 0 ;
V_30:
while ( ! F_25 ( & V_33 ) ) {
V_7 = F_26 ( & V_33 ,
struct V_6 ,
V_36 ) ;
F_27 ( & V_7 -> V_36 ) ;
F_7 ( V_7 ) ;
}
F_8 ( L_8 ) ;
return - V_19 ;
}
void F_28 ( struct V_1 * V_2 , unsigned int V_39 )
{
struct V_6 * V_7 = NULL , * V_40 = NULL ;
F_8 ( L_9 ) ;
if ( V_39 == 0 )
goto V_41;
F_22 ( & V_2 -> V_37 ) ;
F_5 ( V_2 , V_39 ) ;
F_29 (req, tmp, &xprt->bc_pa_list, rq_bc_pa_list) {
F_8 ( L_10 , V_7 ) ;
F_27 ( & V_7 -> V_36 ) ;
F_7 ( V_7 ) ;
if ( -- V_39 == 0 )
break;
}
F_24 ( & V_2 -> V_37 ) ;
V_41:
F_8 ( L_11 ,
F_25 ( & V_2 -> V_38 ) ? L_12 : L_13 ) ;
}
static struct V_6 * F_30 ( struct V_1 * V_2 , T_2 V_42 )
{
struct V_6 * V_7 = NULL ;
F_8 ( L_14 ) ;
if ( F_2 ( & V_2 -> V_4 ) <= 0 )
goto V_43;
if ( F_25 ( & V_2 -> V_38 ) ) {
V_7 = F_16 ( V_2 , V_44 ) ;
if ( ! V_7 )
goto V_43;
F_31 ( & V_7 -> V_36 , & V_2 -> V_38 ) ;
V_2 -> V_3 ++ ;
}
V_7 = F_26 ( & V_2 -> V_38 , struct V_6 ,
V_36 ) ;
V_7 -> V_45 = 0 ;
V_7 -> V_46 = 0 ;
memcpy ( & V_7 -> V_47 , & V_7 -> V_12 ,
sizeof( V_7 -> V_47 ) ) ;
V_7 -> V_48 = V_42 ;
V_7 -> V_49 = V_2 -> V_50 ;
V_43:
F_8 ( L_15 , V_7 ) ;
return V_7 ;
}
void F_32 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_26 ;
F_8 ( L_16 , V_7 ) ;
V_7 -> V_49 = V_2 -> V_50 - 1 ;
F_33 () ;
F_34 ( V_10 , & V_7 -> V_11 ) ;
F_35 () ;
F_22 ( & V_2 -> V_37 ) ;
if ( F_1 ( V_2 ) ) {
F_31 ( & V_7 -> V_36 , & V_2 -> V_38 ) ;
V_2 -> V_3 ++ ;
V_7 = NULL ;
}
F_24 ( & V_2 -> V_37 ) ;
if ( V_7 != NULL ) {
F_8 ( L_17 , V_7 ) ;
F_7 ( V_7 ) ;
return;
}
}
struct V_6 * F_36 ( struct V_1 * V_2 , T_2 V_42 )
{
struct V_6 * V_7 ;
F_37 ( & V_2 -> V_37 ) ;
F_38 (req, &xprt->bc_pa_list, rq_bc_pa_list) {
if ( V_7 -> V_49 != V_2 -> V_50 )
continue;
if ( V_7 -> V_48 == V_42 )
goto V_51;
}
V_7 = F_30 ( V_2 , V_42 ) ;
V_51:
F_39 ( & V_2 -> V_37 ) ;
return V_7 ;
}
void F_40 ( struct V_6 * V_7 , T_3 V_52 )
{
struct V_1 * V_2 = V_7 -> V_26 ;
struct V_53 * V_54 = V_2 -> V_54 ;
F_37 ( & V_2 -> V_37 ) ;
F_27 ( & V_7 -> V_36 ) ;
F_5 ( V_2 , 1 ) ;
F_39 ( & V_2 -> V_37 ) ;
V_7 -> V_47 . V_24 = V_52 ;
F_41 ( V_10 , & V_7 -> V_11 ) ;
F_8 ( L_18 ) ;
F_37 ( & V_54 -> V_55 ) ;
F_21 ( & V_7 -> V_28 , & V_54 -> V_56 ) ;
F_42 ( & V_54 -> V_57 ) ;
F_39 ( & V_54 -> V_55 ) ;
}
