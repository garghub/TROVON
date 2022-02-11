static struct V_1 * F_1 ( struct V_2 * V_3 ,
enum V_4 V_5 )
{
struct V_6 * V_7 = V_3 -> V_8 -> V_9 ;
struct V_1 * V_10 ;
struct V_11 * V_12 , * V_13 ;
int V_14 , V_15 ;
V_14 = F_2 ( V_7 -> V_16 . V_17 ) ;
if ( V_14 )
return F_3 ( V_14 ) ;
V_14 = F_4 ( V_7 ) ;
if ( V_14 ) {
V_10 = F_3 ( V_14 ) ;
goto V_18;
}
V_10 = F_5 ( sizeof( struct V_1 ) , V_19 ) ;
if ( V_10 == NULL ) {
V_10 = F_3 ( - V_20 ) ;
goto V_18;
}
V_14 = F_6 ( V_10 , V_7 -> V_21 -> V_22 , V_19 ) ;
if ( V_14 ) {
F_7 ( V_10 ) ;
V_10 = F_3 ( V_14 ) ;
goto V_18;
}
V_12 = V_7 -> V_21 -> V_23 ;
V_13 = V_10 -> V_23 ;
for ( V_15 = 0 ; V_15 < V_7 -> V_21 -> V_22 ; V_15 ++ ) {
F_8 ( V_13 , F_9 ( V_12 ) , V_12 -> V_24 , 0 ) ;
V_13 = F_10 ( V_13 ) ;
V_12 = F_10 ( V_12 ) ;
}
if ( ! F_11 ( V_3 -> V_17 , V_10 -> V_23 , V_10 -> V_22 , V_5 ) ) {
F_12 ( V_10 ) ;
F_7 ( V_10 ) ;
V_10 = F_3 ( - V_20 ) ;
goto V_18;
}
F_13 ( V_7 ) ;
V_18:
F_14 ( & V_7 -> V_16 . V_17 -> V_25 ) ;
return V_10 ;
}
static void F_15 ( struct V_2 * V_3 ,
struct V_1 * V_26 ,
enum V_4 V_5 )
{
F_16 ( V_3 -> V_17 , V_26 -> V_23 , V_26 -> V_22 , V_5 ) ;
F_12 ( V_26 ) ;
F_7 ( V_26 ) ;
}
static void F_17 ( struct V_27 * V_27 )
{
struct V_6 * V_7 = V_27 -> V_9 ;
if ( V_7 -> V_16 . V_28 == V_27 ) {
V_7 -> V_16 . V_28 = NULL ;
F_18 ( & V_7 -> V_16 ) ;
}
}
static void * F_19 ( struct V_27 * V_27 )
{
struct V_6 * V_7 = V_27 -> V_9 ;
struct V_29 * V_17 = V_7 -> V_16 . V_17 ;
struct V_30 V_31 ;
struct V_32 * * V_21 ;
int V_14 , V_15 ;
V_14 = F_2 ( V_17 ) ;
if ( V_14 )
return F_3 ( V_14 ) ;
if ( V_7 -> V_33 ) {
V_7 -> V_34 ++ ;
goto V_35;
}
V_14 = F_4 ( V_7 ) ;
if ( V_14 )
goto error;
V_14 = - V_20 ;
V_21 = F_20 ( V_7 -> V_16 . V_36 >> V_37 , sizeof( * V_21 ) ) ;
if ( V_21 == NULL )
goto error;
V_15 = 0 ;
F_21 (obj->pages->sgl, &sg_iter, obj->pages->nents, 0 )
V_21 [ V_15 ++ ] = F_22 ( & V_31 ) ;
V_7 -> V_33 = F_23 ( V_21 , V_15 , 0 , V_38 ) ;
F_24 ( V_21 ) ;
if ( ! V_7 -> V_33 )
goto error;
V_7 -> V_34 = 1 ;
F_13 ( V_7 ) ;
V_35:
F_14 ( & V_17 -> V_25 ) ;
return V_7 -> V_33 ;
error:
F_14 ( & V_17 -> V_25 ) ;
return F_3 ( V_14 ) ;
}
static void F_25 ( struct V_27 * V_27 , void * V_39 )
{
struct V_6 * V_7 = V_27 -> V_9 ;
struct V_29 * V_17 = V_7 -> V_16 . V_17 ;
int V_14 ;
V_14 = F_2 ( V_17 ) ;
if ( V_14 )
return;
if ( -- V_7 -> V_34 == 0 ) {
F_26 ( V_7 -> V_33 ) ;
V_7 -> V_33 = NULL ;
F_27 ( V_7 ) ;
}
F_14 ( & V_17 -> V_25 ) ;
}
static void * F_28 ( struct V_27 * V_27 , unsigned long V_40 )
{
return NULL ;
}
static void F_29 ( struct V_27 * V_27 , unsigned long V_40 , void * V_41 )
{
}
static void * F_30 ( struct V_27 * V_27 , unsigned long V_40 )
{
return NULL ;
}
static void F_31 ( struct V_27 * V_27 , unsigned long V_40 , void * V_41 )
{
}
static int F_32 ( struct V_27 * V_27 , struct V_42 * V_43 )
{
return - V_44 ;
}
static int F_33 ( struct V_27 * V_27 , T_1 V_45 , T_1 V_24 , enum V_4 V_46 )
{
struct V_6 * V_7 = V_27 -> V_9 ;
struct V_29 * V_17 = V_7 -> V_16 . V_17 ;
int V_14 ;
bool V_47 = ( V_46 == V_48 || V_46 == V_49 ) ;
V_14 = F_2 ( V_17 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_34 ( V_7 , V_47 ) ;
F_14 ( & V_17 -> V_25 ) ;
return V_14 ;
}
struct V_27 * F_35 ( struct V_29 * V_17 ,
struct V_50 * V_51 , int V_52 )
{
struct V_6 * V_7 = F_36 ( V_51 ) ;
return F_37 ( V_7 , & V_53 , V_7 -> V_16 . V_36 , V_52 ) ;
}
static int F_38 ( struct V_6 * V_7 )
{
struct V_1 * V_26 ;
V_26 = F_39 ( V_7 -> V_16 . V_54 , V_48 ) ;
if ( F_40 ( V_26 ) )
return F_41 ( V_26 ) ;
V_7 -> V_21 = V_26 ;
V_7 -> V_55 = true ;
return 0 ;
}
static void F_42 ( struct V_6 * V_7 )
{
F_43 ( V_7 -> V_16 . V_54 ,
V_7 -> V_21 , V_48 ) ;
V_7 -> V_55 = false ;
}
struct V_50 * F_44 ( struct V_29 * V_17 ,
struct V_27 * V_27 )
{
struct V_2 * V_56 ;
struct V_6 * V_7 ;
int V_14 ;
if ( V_27 -> V_57 == & V_53 ) {
V_7 = V_27 -> V_9 ;
if ( V_7 -> V_16 . V_17 == V_17 ) {
F_45 ( & V_7 -> V_16 ) ;
return & V_7 -> V_16 ;
}
}
V_56 = F_46 ( V_27 , V_17 -> V_17 ) ;
if ( F_40 ( V_56 ) )
return F_47 ( V_56 ) ;
F_48 ( V_27 ) ;
V_7 = F_49 ( V_17 ) ;
if ( V_7 == NULL ) {
V_14 = - V_20 ;
goto V_58;
}
V_14 = F_50 ( V_17 , & V_7 -> V_16 , V_27 -> V_36 ) ;
if ( V_14 ) {
F_51 ( V_7 ) ;
goto V_58;
}
F_52 ( V_7 , & V_59 ) ;
V_7 -> V_16 . V_54 = V_56 ;
return & V_7 -> V_16 ;
V_58:
F_53 ( V_27 , V_56 ) ;
F_54 ( V_27 ) ;
return F_3 ( V_14 ) ;
}
