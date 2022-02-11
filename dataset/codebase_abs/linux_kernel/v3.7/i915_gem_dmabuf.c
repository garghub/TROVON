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
F_8 ( V_13 , F_9 ( V_12 ) , V_24 , 0 ) ;
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
struct V_11 * V_26 ;
struct V_30 * * V_21 ;
int V_14 , V_15 ;
V_14 = F_2 ( V_17 ) ;
if ( V_14 )
return F_3 ( V_14 ) ;
if ( V_7 -> V_31 ) {
V_7 -> V_32 ++ ;
goto V_33;
}
V_14 = F_4 ( V_7 ) ;
if ( V_14 )
goto error;
V_14 = - V_20 ;
V_21 = F_20 ( V_7 -> V_21 -> V_22 , sizeof( struct V_30 * ) ) ;
if ( V_21 == NULL )
goto error;
F_21 (obj->pages->sgl, sg, obj->pages->nents, i)
V_21 [ V_15 ] = F_9 ( V_26 ) ;
V_7 -> V_31 = F_22 ( V_21 , V_7 -> V_21 -> V_22 , 0 , V_34 ) ;
F_23 ( V_21 ) ;
if ( ! V_7 -> V_31 )
goto error;
V_7 -> V_32 = 1 ;
F_13 ( V_7 ) ;
V_33:
F_14 ( & V_17 -> V_25 ) ;
return V_7 -> V_31 ;
error:
F_14 ( & V_17 -> V_25 ) ;
return F_3 ( V_14 ) ;
}
static void F_24 ( struct V_27 * V_27 , void * V_35 )
{
struct V_6 * V_7 = V_27 -> V_9 ;
struct V_29 * V_17 = V_7 -> V_16 . V_17 ;
int V_14 ;
V_14 = F_2 ( V_17 ) ;
if ( V_14 )
return;
if ( -- V_7 -> V_32 == 0 ) {
F_25 ( V_7 -> V_31 ) ;
V_7 -> V_31 = NULL ;
F_26 ( V_7 ) ;
}
F_14 ( & V_17 -> V_25 ) ;
}
static void * F_27 ( struct V_27 * V_27 , unsigned long V_36 )
{
return NULL ;
}
static void F_28 ( struct V_27 * V_27 , unsigned long V_36 , void * V_37 )
{
}
static void * F_29 ( struct V_27 * V_27 , unsigned long V_36 )
{
return NULL ;
}
static void F_30 ( struct V_27 * V_27 , unsigned long V_36 , void * V_37 )
{
}
static int F_31 ( struct V_27 * V_27 , struct V_38 * V_39 )
{
return - V_40 ;
}
static int F_32 ( struct V_27 * V_27 , T_1 V_41 , T_1 V_42 , enum V_4 V_43 )
{
struct V_6 * V_7 = V_27 -> V_9 ;
struct V_29 * V_17 = V_7 -> V_16 . V_17 ;
int V_14 ;
bool V_44 = ( V_43 == V_45 || V_43 == V_46 ) ;
V_14 = F_2 ( V_17 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_33 ( V_7 , V_44 ) ;
F_14 ( & V_17 -> V_25 ) ;
return V_14 ;
}
struct V_27 * F_34 ( struct V_29 * V_17 ,
struct V_47 * V_48 , int V_49 )
{
struct V_6 * V_7 = F_35 ( V_48 ) ;
return F_36 ( V_7 , & V_50 , V_7 -> V_16 . V_51 , 0600 ) ;
}
static int F_37 ( struct V_6 * V_7 )
{
struct V_1 * V_26 ;
V_26 = F_38 ( V_7 -> V_16 . V_52 , V_45 ) ;
if ( F_39 ( V_26 ) )
return F_40 ( V_26 ) ;
V_7 -> V_21 = V_26 ;
V_7 -> V_53 = true ;
return 0 ;
}
static void F_41 ( struct V_6 * V_7 )
{
F_42 ( V_7 -> V_16 . V_52 ,
V_7 -> V_21 , V_45 ) ;
V_7 -> V_53 = false ;
}
struct V_47 * F_43 ( struct V_29 * V_17 ,
struct V_27 * V_27 )
{
struct V_2 * V_54 ;
struct V_6 * V_7 ;
int V_14 ;
if ( V_27 -> V_55 == & V_50 ) {
V_7 = V_27 -> V_9 ;
if ( V_7 -> V_16 . V_17 == V_17 ) {
F_44 ( & V_7 -> V_16 ) ;
return & V_7 -> V_16 ;
}
}
V_54 = F_45 ( V_27 , V_17 -> V_17 ) ;
if ( F_39 ( V_54 ) )
return F_46 ( V_54 ) ;
V_7 = F_47 ( sizeof( * V_7 ) , V_19 ) ;
if ( V_7 == NULL ) {
V_14 = - V_20 ;
goto V_56;
}
V_14 = F_48 ( V_17 , & V_7 -> V_16 , V_27 -> V_51 ) ;
if ( V_14 ) {
F_7 ( V_7 ) ;
goto V_56;
}
F_49 ( V_7 , & V_57 ) ;
V_7 -> V_16 . V_52 = V_54 ;
return & V_7 -> V_16 ;
V_56:
F_50 ( V_27 , V_54 ) ;
return F_3 ( V_14 ) ;
}
