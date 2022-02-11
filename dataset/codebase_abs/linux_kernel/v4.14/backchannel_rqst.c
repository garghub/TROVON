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
F_15 ( V_16 , F_16 ( V_18 ) , V_20 ) ;
return 0 ;
}
static
struct V_6 * F_17 ( struct V_1 * V_2 , T_1 V_17 )
{
struct V_6 * V_7 ;
V_7 = F_18 ( sizeof( * V_7 ) , V_17 ) ;
if ( V_7 == NULL )
return NULL ;
V_7 -> V_21 = V_2 ;
F_19 ( & V_7 -> V_22 ) ;
F_19 ( & V_7 -> V_23 ) ;
if ( F_13 ( & V_7 -> V_12 , V_17 ) < 0 ) {
F_20 ( V_24 L_2 ) ;
goto V_25;
}
V_7 -> V_12 . V_26 = V_20 ;
if ( F_13 ( & V_7 -> V_15 , V_17 ) < 0 ) {
F_20 ( V_24 L_3 ) ;
goto V_25;
}
return V_7 ;
V_25:
F_7 ( V_7 ) ;
return NULL ;
}
int F_21 ( struct V_1 * V_2 , unsigned int V_27 )
{
if ( ! V_2 -> V_28 -> V_29 )
return 0 ;
return V_2 -> V_28 -> V_29 ( V_2 , V_27 ) ;
}
int F_22 ( struct V_1 * V_2 , unsigned int V_27 )
{
struct V_6 * V_7 ;
struct V_30 V_31 ;
int V_32 ;
F_8 ( L_4 ) ;
F_19 ( & V_31 ) ;
for ( V_32 = 0 ; V_32 < V_27 ; V_32 ++ ) {
V_7 = F_17 ( V_2 , V_33 ) ;
if ( V_7 == NULL ) {
F_20 ( V_24 L_5 ) ;
goto V_25;
}
F_8 ( L_6 , V_7 ) ;
F_23 ( & V_7 -> V_34 , & V_31 ) ;
}
F_24 ( & V_2 -> V_35 ) ;
F_25 ( & V_31 , & V_2 -> V_36 ) ;
F_3 ( V_2 , V_27 ) ;
F_26 ( & V_2 -> V_35 ) ;
F_8 ( L_7 ) ;
return 0 ;
V_25:
while ( ! F_27 ( & V_31 ) ) {
V_7 = F_28 ( & V_31 ,
struct V_6 ,
V_34 ) ;
F_29 ( & V_7 -> V_34 ) ;
F_7 ( V_7 ) ;
}
F_8 ( L_8 ) ;
return - V_19 ;
}
void F_30 ( struct V_1 * V_2 , unsigned int V_37 )
{
if ( V_2 -> V_28 -> V_38 )
V_2 -> V_28 -> V_38 ( V_2 , V_37 ) ;
}
void F_31 ( struct V_1 * V_2 , unsigned int V_37 )
{
struct V_6 * V_7 = NULL , * V_39 = NULL ;
F_8 ( L_9 ) ;
if ( V_37 == 0 )
goto V_40;
F_32 ( & V_2 -> V_35 ) ;
F_5 ( V_2 , V_37 ) ;
F_33 (req, tmp, &xprt->bc_pa_list, rq_bc_pa_list) {
F_8 ( L_10 , V_7 ) ;
F_29 ( & V_7 -> V_34 ) ;
F_7 ( V_7 ) ;
if ( -- V_37 == 0 )
break;
}
F_34 ( & V_2 -> V_35 ) ;
V_40:
F_8 ( L_11 ,
F_27 ( & V_2 -> V_36 ) ? L_12 : L_13 ) ;
}
static struct V_6 * F_35 ( struct V_1 * V_2 , T_2 V_41 )
{
struct V_6 * V_7 = NULL ;
F_8 ( L_14 ) ;
if ( F_2 ( & V_2 -> V_4 ) <= 0 )
goto V_42;
if ( F_27 ( & V_2 -> V_36 ) ) {
V_7 = F_17 ( V_2 , V_43 ) ;
if ( ! V_7 )
goto V_42;
F_36 ( & V_7 -> V_34 , & V_2 -> V_36 ) ;
V_2 -> V_3 ++ ;
}
V_7 = F_28 ( & V_2 -> V_36 , struct V_6 ,
V_34 ) ;
V_7 -> V_44 = 0 ;
V_7 -> V_45 = 0 ;
memcpy ( & V_7 -> V_46 , & V_7 -> V_12 ,
sizeof( V_7 -> V_46 ) ) ;
V_7 -> V_47 = V_41 ;
V_7 -> V_48 = V_2 -> V_49 ;
V_42:
F_8 ( L_15 , V_7 ) ;
return V_7 ;
}
void F_37 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_21 ;
V_2 -> V_28 -> V_50 ( V_7 ) ;
}
void F_38 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_21 ;
F_8 ( L_16 , V_7 ) ;
V_7 -> V_48 = V_2 -> V_49 - 1 ;
F_39 () ;
F_40 ( V_10 , & V_7 -> V_11 ) ;
F_41 () ;
F_32 ( & V_2 -> V_35 ) ;
if ( F_1 ( V_2 ) ) {
F_36 ( & V_7 -> V_34 , & V_2 -> V_36 ) ;
V_2 -> V_3 ++ ;
V_7 = NULL ;
}
F_34 ( & V_2 -> V_35 ) ;
if ( V_7 != NULL ) {
F_8 ( L_17 , V_7 ) ;
F_7 ( V_7 ) ;
return;
}
}
struct V_6 * F_42 ( struct V_1 * V_2 , T_2 V_41 )
{
struct V_6 * V_7 ;
F_24 ( & V_2 -> V_35 ) ;
F_43 (req, &xprt->bc_pa_list, rq_bc_pa_list) {
if ( V_7 -> V_48 != V_2 -> V_49 )
continue;
if ( V_7 -> V_47 == V_41 )
goto V_51;
}
V_7 = F_35 ( V_2 , V_41 ) ;
V_51:
F_26 ( & V_2 -> V_35 ) ;
return V_7 ;
}
void F_44 ( struct V_6 * V_7 , T_3 V_52 )
{
struct V_1 * V_2 = V_7 -> V_21 ;
struct V_53 * V_54 = V_2 -> V_54 ;
F_24 ( & V_2 -> V_35 ) ;
F_29 ( & V_7 -> V_34 ) ;
F_5 ( V_2 , 1 ) ;
F_26 ( & V_2 -> V_35 ) ;
V_7 -> V_46 . V_26 = V_52 ;
F_45 ( V_10 , & V_7 -> V_11 ) ;
F_8 ( L_18 ) ;
F_24 ( & V_54 -> V_55 ) ;
F_23 ( & V_7 -> V_23 , & V_54 -> V_56 ) ;
F_46 ( & V_54 -> V_57 ) ;
F_26 ( & V_54 -> V_55 ) ;
}
