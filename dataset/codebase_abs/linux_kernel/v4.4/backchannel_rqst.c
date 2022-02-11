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
if ( ! V_2 -> V_32 -> V_33 )
return 0 ;
return V_2 -> V_32 -> V_33 ( V_2 , V_31 ) ;
}
int F_21 ( struct V_1 * V_2 , unsigned int V_31 )
{
struct V_6 * V_7 ;
struct V_34 V_35 ;
int V_36 ;
F_8 ( L_4 ) ;
F_18 ( & V_35 ) ;
for ( V_36 = 0 ; V_36 < V_31 ; V_36 ++ ) {
V_7 = F_16 ( V_2 , V_37 ) ;
if ( V_7 == NULL ) {
F_19 ( V_29 L_5 ) ;
goto V_30;
}
F_8 ( L_6 , V_7 ) ;
F_22 ( & V_7 -> V_38 , & V_35 ) ;
}
F_23 ( & V_2 -> V_39 ) ;
F_24 ( & V_35 , & V_2 -> V_40 ) ;
F_3 ( V_2 , V_31 ) ;
F_25 ( & V_2 -> V_39 ) ;
F_8 ( L_7 ) ;
return 0 ;
V_30:
while ( ! F_26 ( & V_35 ) ) {
V_7 = F_27 ( & V_35 ,
struct V_6 ,
V_38 ) ;
F_28 ( & V_7 -> V_38 ) ;
F_7 ( V_7 ) ;
}
F_8 ( L_8 ) ;
return - V_19 ;
}
void F_29 ( struct V_1 * V_2 , unsigned int V_41 )
{
if ( V_2 -> V_32 -> V_42 )
V_2 -> V_32 -> V_42 ( V_2 , V_41 ) ;
}
void F_30 ( struct V_1 * V_2 , unsigned int V_41 )
{
struct V_6 * V_7 = NULL , * V_43 = NULL ;
F_8 ( L_9 ) ;
if ( V_41 == 0 )
goto V_44;
F_23 ( & V_2 -> V_39 ) ;
F_5 ( V_2 , V_41 ) ;
F_31 (req, tmp, &xprt->bc_pa_list, rq_bc_pa_list) {
F_8 ( L_10 , V_7 ) ;
F_28 ( & V_7 -> V_38 ) ;
F_7 ( V_7 ) ;
if ( -- V_41 == 0 )
break;
}
F_25 ( & V_2 -> V_39 ) ;
V_44:
F_8 ( L_11 ,
F_26 ( & V_2 -> V_40 ) ? L_12 : L_13 ) ;
}
static struct V_6 * F_32 ( struct V_1 * V_2 , T_2 V_45 )
{
struct V_6 * V_7 = NULL ;
F_8 ( L_14 ) ;
if ( F_2 ( & V_2 -> V_4 ) <= 0 )
goto V_46;
if ( F_26 ( & V_2 -> V_40 ) ) {
V_7 = F_16 ( V_2 , V_47 ) ;
if ( ! V_7 )
goto V_46;
F_33 ( & V_7 -> V_38 , & V_2 -> V_40 ) ;
V_2 -> V_3 ++ ;
}
V_7 = F_27 ( & V_2 -> V_40 , struct V_6 ,
V_38 ) ;
V_7 -> V_48 = 0 ;
V_7 -> V_49 = 0 ;
memcpy ( & V_7 -> V_50 , & V_7 -> V_12 ,
sizeof( V_7 -> V_50 ) ) ;
V_7 -> V_51 = V_45 ;
V_7 -> V_52 = V_2 -> V_53 ;
V_46:
F_8 ( L_15 , V_7 ) ;
return V_7 ;
}
void F_34 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_26 ;
V_2 -> V_32 -> V_54 ( V_7 ) ;
}
void F_35 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_26 ;
F_8 ( L_16 , V_7 ) ;
V_7 -> V_52 = V_2 -> V_53 - 1 ;
F_36 () ;
F_37 ( V_10 , & V_7 -> V_11 ) ;
F_38 () ;
F_23 ( & V_2 -> V_39 ) ;
if ( F_1 ( V_2 ) ) {
F_33 ( & V_7 -> V_38 , & V_2 -> V_40 ) ;
V_2 -> V_3 ++ ;
V_7 = NULL ;
}
F_25 ( & V_2 -> V_39 ) ;
if ( V_7 != NULL ) {
F_8 ( L_17 , V_7 ) ;
F_7 ( V_7 ) ;
return;
}
}
struct V_6 * F_39 ( struct V_1 * V_2 , T_2 V_45 )
{
struct V_6 * V_7 ;
F_40 ( & V_2 -> V_39 ) ;
F_41 (req, &xprt->bc_pa_list, rq_bc_pa_list) {
if ( V_7 -> V_52 != V_2 -> V_53 )
continue;
if ( V_7 -> V_51 == V_45 )
goto V_55;
}
V_7 = F_32 ( V_2 , V_45 ) ;
V_55:
F_42 ( & V_2 -> V_39 ) ;
return V_7 ;
}
void F_43 ( struct V_6 * V_7 , T_3 V_56 )
{
struct V_1 * V_2 = V_7 -> V_26 ;
struct V_57 * V_58 = V_2 -> V_58 ;
F_40 ( & V_2 -> V_39 ) ;
F_28 ( & V_7 -> V_38 ) ;
F_5 ( V_2 , 1 ) ;
F_42 ( & V_2 -> V_39 ) ;
V_7 -> V_50 . V_24 = V_56 ;
F_44 ( V_10 , & V_7 -> V_11 ) ;
F_8 ( L_18 ) ;
F_40 ( & V_58 -> V_59 ) ;
F_22 ( & V_7 -> V_28 , & V_58 -> V_60 ) ;
F_45 ( & V_58 -> V_61 ) ;
F_42 ( & V_58 -> V_59 ) ;
}
