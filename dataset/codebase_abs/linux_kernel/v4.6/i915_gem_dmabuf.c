static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 ) ;
}
static struct V_5 * F_3 ( struct V_6 * V_7 ,
enum V_8 V_9 )
{
struct V_1 * V_10 = F_1 ( V_7 -> V_11 ) ;
struct V_5 * V_12 ;
struct V_13 * V_14 , * V_15 ;
int V_16 , V_17 ;
V_16 = F_4 ( V_10 -> V_18 . V_19 ) ;
if ( V_16 )
goto V_20;
V_16 = F_5 ( V_10 ) ;
if ( V_16 )
goto V_21;
F_6 ( V_10 ) ;
V_12 = F_7 ( sizeof( struct V_5 ) , V_22 ) ;
if ( V_12 == NULL ) {
V_16 = - V_23 ;
goto V_24;
}
V_16 = F_8 ( V_12 , V_10 -> V_25 -> V_26 , V_22 ) ;
if ( V_16 )
goto V_27;
V_14 = V_10 -> V_25 -> V_28 ;
V_15 = V_12 -> V_28 ;
for ( V_17 = 0 ; V_17 < V_10 -> V_25 -> V_26 ; V_17 ++ ) {
F_9 ( V_15 , F_10 ( V_14 ) , V_14 -> V_29 , 0 ) ;
V_15 = F_11 ( V_15 ) ;
V_14 = F_11 ( V_14 ) ;
}
if ( ! F_12 ( V_7 -> V_19 , V_12 -> V_28 , V_12 -> V_26 , V_9 ) ) {
V_16 = - V_23 ;
goto V_30;
}
F_13 ( & V_10 -> V_18 . V_19 -> V_31 ) ;
return V_12 ;
V_30:
F_14 ( V_12 ) ;
V_27:
F_15 ( V_12 ) ;
V_24:
F_16 ( V_10 ) ;
V_21:
F_13 ( & V_10 -> V_18 . V_19 -> V_31 ) ;
V_20:
return F_17 ( V_16 ) ;
}
static void F_18 ( struct V_6 * V_7 ,
struct V_5 * V_32 ,
enum V_8 V_9 )
{
struct V_1 * V_10 = F_1 ( V_7 -> V_11 ) ;
F_19 ( & V_10 -> V_18 . V_19 -> V_31 ) ;
F_20 ( V_7 -> V_19 , V_32 -> V_28 , V_32 -> V_26 , V_9 ) ;
F_14 ( V_32 ) ;
F_15 ( V_32 ) ;
F_16 ( V_10 ) ;
F_13 ( & V_10 -> V_18 . V_19 -> V_31 ) ;
}
static void * F_21 ( struct V_2 * V_2 )
{
struct V_1 * V_10 = F_1 ( V_2 ) ;
struct V_33 * V_19 = V_10 -> V_18 . V_19 ;
struct V_34 V_35 ;
struct V_36 * * V_25 ;
int V_16 , V_17 ;
V_16 = F_4 ( V_19 ) ;
if ( V_16 )
return F_17 ( V_16 ) ;
if ( V_10 -> V_37 ) {
V_10 -> V_38 ++ ;
goto V_39;
}
V_16 = F_5 ( V_10 ) ;
if ( V_16 )
goto V_20;
F_6 ( V_10 ) ;
V_16 = - V_23 ;
V_25 = F_22 ( V_10 -> V_18 . V_40 >> V_41 , sizeof( * V_25 ) ) ;
if ( V_25 == NULL )
goto V_24;
V_17 = 0 ;
F_23 (obj->pages->sgl, &sg_iter, obj->pages->nents, 0 )
V_25 [ V_17 ++ ] = F_24 ( & V_35 ) ;
V_10 -> V_37 = F_25 ( V_25 , V_17 , 0 , V_42 ) ;
F_26 ( V_25 ) ;
if ( ! V_10 -> V_37 )
goto V_24;
V_10 -> V_38 = 1 ;
V_39:
F_13 ( & V_19 -> V_31 ) ;
return V_10 -> V_37 ;
V_24:
F_16 ( V_10 ) ;
V_20:
F_13 ( & V_19 -> V_31 ) ;
return F_17 ( V_16 ) ;
}
static void F_27 ( struct V_2 * V_2 , void * V_43 )
{
struct V_1 * V_10 = F_1 ( V_2 ) ;
struct V_33 * V_19 = V_10 -> V_18 . V_19 ;
F_19 ( & V_19 -> V_31 ) ;
if ( -- V_10 -> V_38 == 0 ) {
F_28 ( V_10 -> V_37 ) ;
V_10 -> V_37 = NULL ;
F_16 ( V_10 ) ;
}
F_13 ( & V_19 -> V_31 ) ;
}
static void * F_29 ( struct V_2 * V_2 , unsigned long V_44 )
{
return NULL ;
}
static void F_30 ( struct V_2 * V_2 , unsigned long V_44 , void * V_45 )
{
}
static void * F_31 ( struct V_2 * V_2 , unsigned long V_44 )
{
return NULL ;
}
static void F_32 ( struct V_2 * V_2 , unsigned long V_44 , void * V_45 )
{
}
static int F_33 ( struct V_2 * V_2 , struct V_46 * V_47 )
{
struct V_1 * V_10 = F_1 ( V_2 ) ;
int V_16 ;
if ( V_10 -> V_18 . V_40 < V_47 -> V_48 - V_47 -> V_49 )
return - V_50 ;
if ( ! V_10 -> V_18 . V_51 )
return - V_52 ;
V_16 = V_10 -> V_18 . V_51 -> V_53 -> V_54 ( V_10 -> V_18 . V_51 , V_47 ) ;
if ( V_16 )
return V_16 ;
F_34 ( V_47 -> V_55 ) ;
V_47 -> V_55 = F_35 ( V_10 -> V_18 . V_51 ) ;
return 0 ;
}
static int F_36 ( struct V_2 * V_2 , enum V_8 V_56 )
{
struct V_1 * V_10 = F_1 ( V_2 ) ;
struct V_33 * V_19 = V_10 -> V_18 . V_19 ;
int V_16 ;
bool V_57 = ( V_56 == V_58 || V_56 == V_59 ) ;
V_16 = F_4 ( V_19 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_37 ( V_10 , V_57 ) ;
F_13 ( & V_19 -> V_31 ) ;
return V_16 ;
}
static int F_38 ( struct V_2 * V_2 , enum V_8 V_56 )
{
struct V_1 * V_10 = F_1 ( V_2 ) ;
struct V_33 * V_19 = V_10 -> V_18 . V_19 ;
int V_16 ;
V_16 = F_4 ( V_19 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_39 ( V_10 , false ) ;
F_13 ( & V_19 -> V_31 ) ;
return V_16 ;
}
struct V_2 * F_40 ( struct V_33 * V_19 ,
struct V_60 * V_61 , int V_62 )
{
struct V_1 * V_10 = F_2 ( V_61 ) ;
F_41 ( V_63 ) ;
V_63 . V_64 = & V_65 ;
V_63 . V_40 = V_61 -> V_40 ;
V_63 . V_62 = V_62 ;
V_63 . V_4 = V_61 ;
if ( V_10 -> V_64 -> V_66 ) {
int V_16 = V_10 -> V_64 -> V_66 ( V_10 ) ;
if ( V_16 )
return F_17 ( V_16 ) ;
}
return F_42 ( & V_63 ) ;
}
static int F_43 ( struct V_1 * V_10 )
{
struct V_5 * V_32 ;
V_32 = F_44 ( V_10 -> V_18 . V_67 , V_58 ) ;
if ( F_45 ( V_32 ) )
return F_46 ( V_32 ) ;
V_10 -> V_25 = V_32 ;
return 0 ;
}
static void F_47 ( struct V_1 * V_10 )
{
F_48 ( V_10 -> V_18 . V_67 ,
V_10 -> V_25 , V_58 ) ;
}
struct V_60 * F_49 ( struct V_33 * V_19 ,
struct V_2 * V_2 )
{
struct V_6 * V_68 ;
struct V_1 * V_10 ;
int V_16 ;
if ( V_2 -> V_64 == & V_65 ) {
V_10 = F_1 ( V_2 ) ;
if ( V_10 -> V_18 . V_19 == V_19 ) {
F_50 ( & V_10 -> V_18 ) ;
return & V_10 -> V_18 ;
}
}
V_68 = F_51 ( V_2 , V_19 -> V_19 ) ;
if ( F_45 ( V_68 ) )
return F_52 ( V_68 ) ;
F_53 ( V_2 ) ;
V_10 = F_54 ( V_19 ) ;
if ( V_10 == NULL ) {
V_16 = - V_23 ;
goto V_69;
}
F_55 ( V_19 , & V_10 -> V_18 , V_2 -> V_40 ) ;
F_56 ( V_10 , & V_70 ) ;
V_10 -> V_18 . V_67 = V_68 ;
return & V_10 -> V_18 ;
V_69:
F_57 ( V_2 , V_68 ) ;
F_58 ( V_2 ) ;
return F_17 ( V_16 ) ;
}
