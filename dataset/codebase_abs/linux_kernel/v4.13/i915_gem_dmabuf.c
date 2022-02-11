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
V_16 = F_4 ( V_10 ) ;
if ( V_16 )
goto V_18;
V_12 = F_5 ( sizeof( struct V_5 ) , V_19 ) ;
if ( V_12 == NULL ) {
V_16 = - V_20 ;
goto V_21;
}
V_16 = F_6 ( V_12 , V_10 -> V_22 . V_23 -> V_24 , V_19 ) ;
if ( V_16 )
goto V_25;
V_14 = V_10 -> V_22 . V_23 -> V_26 ;
V_15 = V_12 -> V_26 ;
for ( V_17 = 0 ; V_17 < V_10 -> V_22 . V_23 -> V_24 ; V_17 ++ ) {
F_7 ( V_15 , F_8 ( V_14 ) , V_14 -> V_27 , 0 ) ;
V_15 = F_9 ( V_15 ) ;
V_14 = F_9 ( V_14 ) ;
}
if ( ! F_10 ( V_7 -> V_28 , V_12 -> V_26 , V_12 -> V_24 , V_9 ) ) {
V_16 = - V_20 ;
goto V_29;
}
return V_12 ;
V_29:
F_11 ( V_12 ) ;
V_25:
F_12 ( V_12 ) ;
V_21:
F_13 ( V_10 ) ;
V_18:
return F_14 ( V_16 ) ;
}
static void F_15 ( struct V_6 * V_7 ,
struct V_5 * V_30 ,
enum V_8 V_9 )
{
struct V_1 * V_10 = F_1 ( V_7 -> V_11 ) ;
F_16 ( V_7 -> V_28 , V_30 -> V_26 , V_30 -> V_24 , V_9 ) ;
F_11 ( V_30 ) ;
F_12 ( V_30 ) ;
F_13 ( V_10 ) ;
}
static void * F_17 ( struct V_2 * V_2 )
{
struct V_1 * V_10 = F_1 ( V_2 ) ;
return F_18 ( V_10 , V_31 ) ;
}
static void F_19 ( struct V_2 * V_2 , void * V_32 )
{
struct V_1 * V_10 = F_1 ( V_2 ) ;
F_20 ( V_10 ) ;
}
static void * F_21 ( struct V_2 * V_2 , unsigned long V_33 )
{
return NULL ;
}
static void F_22 ( struct V_2 * V_2 , unsigned long V_33 , void * V_34 )
{
}
static void * F_23 ( struct V_2 * V_2 , unsigned long V_33 )
{
struct V_1 * V_10 = F_1 ( V_2 ) ;
struct V_35 * V_35 ;
if ( V_33 >= V_10 -> V_36 . V_37 >> V_38 )
return NULL ;
if ( ! F_24 ( V_10 ) )
return NULL ;
if ( F_4 ( V_10 ) )
return NULL ;
V_35 = F_25 ( V_10 , V_33 ) ;
if ( F_26 ( V_35 ) )
goto V_39;
return F_27 ( V_35 ) ;
V_39:
F_13 ( V_10 ) ;
return NULL ;
}
static void F_28 ( struct V_2 * V_2 , unsigned long V_33 , void * V_34 )
{
struct V_1 * V_10 = F_1 ( V_2 ) ;
F_29 ( F_30 ( V_34 ) ) ;
F_13 ( V_10 ) ;
}
static int F_31 ( struct V_2 * V_2 , struct V_40 * V_41 )
{
struct V_1 * V_10 = F_1 ( V_2 ) ;
int V_16 ;
if ( V_10 -> V_36 . V_37 < V_41 -> V_42 - V_41 -> V_43 )
return - V_44 ;
if ( ! V_10 -> V_36 . V_45 )
return - V_46 ;
V_16 = F_32 ( V_10 -> V_36 . V_45 , V_41 ) ;
if ( V_16 )
return V_16 ;
F_33 ( V_41 -> V_47 ) ;
V_41 -> V_47 = F_34 ( V_10 -> V_36 . V_45 ) ;
return 0 ;
}
static int F_35 ( struct V_2 * V_2 , enum V_8 V_48 )
{
struct V_1 * V_10 = F_1 ( V_2 ) ;
struct V_49 * V_28 = V_10 -> V_36 . V_28 ;
bool V_50 = ( V_48 == V_51 || V_48 == V_52 ) ;
int V_18 ;
V_18 = F_4 ( V_10 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_36 ( V_28 ) ;
if ( V_18 )
goto V_53;
V_18 = F_37 ( V_10 , V_50 ) ;
F_38 ( & V_28 -> V_54 ) ;
V_53:
F_13 ( V_10 ) ;
return V_18 ;
}
static int F_39 ( struct V_2 * V_2 , enum V_8 V_48 )
{
struct V_1 * V_10 = F_1 ( V_2 ) ;
struct V_49 * V_28 = V_10 -> V_36 . V_28 ;
int V_18 ;
V_18 = F_4 ( V_10 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_36 ( V_28 ) ;
if ( V_18 )
goto V_53;
V_18 = F_40 ( V_10 , false ) ;
F_38 ( & V_28 -> V_54 ) ;
V_53:
F_13 ( V_10 ) ;
return V_18 ;
}
struct V_2 * F_41 ( struct V_49 * V_28 ,
struct V_55 * V_56 , int V_57 )
{
struct V_1 * V_10 = F_2 ( V_56 ) ;
F_42 ( V_58 ) ;
V_58 . V_59 = & V_60 ;
V_58 . V_37 = V_56 -> V_37 ;
V_58 . V_57 = V_57 ;
V_58 . V_4 = V_56 ;
V_58 . V_61 = V_10 -> V_61 ;
if ( V_10 -> V_59 -> V_62 ) {
int V_16 = V_10 -> V_59 -> V_62 ( V_10 ) ;
if ( V_16 )
return F_14 ( V_16 ) ;
}
return F_43 ( V_28 , & V_58 ) ;
}
static struct V_5 *
F_44 ( struct V_1 * V_10 )
{
return F_45 ( V_10 -> V_36 . V_63 ,
V_51 ) ;
}
static void F_46 ( struct V_1 * V_10 ,
struct V_5 * V_23 )
{
F_47 ( V_10 -> V_36 . V_63 , V_23 ,
V_51 ) ;
}
struct V_55 * F_48 ( struct V_49 * V_28 ,
struct V_2 * V_2 )
{
struct V_6 * V_64 ;
struct V_1 * V_10 ;
int V_16 ;
if ( V_2 -> V_59 == & V_60 ) {
V_10 = F_1 ( V_2 ) ;
if ( V_10 -> V_36 . V_28 == V_28 ) {
return & F_49 ( V_10 ) -> V_36 ;
}
}
V_64 = F_50 ( V_2 , V_28 -> V_28 ) ;
if ( F_26 ( V_64 ) )
return F_51 ( V_64 ) ;
F_52 ( V_2 ) ;
V_10 = F_53 ( F_54 ( V_28 ) ) ;
if ( V_10 == NULL ) {
V_16 = - V_20 ;
goto V_65;
}
F_55 ( V_28 , & V_10 -> V_36 , V_2 -> V_37 ) ;
F_56 ( V_10 , & V_66 ) ;
V_10 -> V_36 . V_63 = V_64 ;
V_10 -> V_61 = V_2 -> V_61 ;
V_10 -> V_36 . V_67 = V_68 ;
V_10 -> V_36 . V_69 = 0 ;
return & V_10 -> V_36 ;
V_65:
F_57 ( V_2 , V_64 ) ;
F_58 ( V_2 ) ;
return F_14 ( V_16 ) ;
}
