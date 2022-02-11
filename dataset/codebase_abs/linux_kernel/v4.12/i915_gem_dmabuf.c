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
return NULL ;
}
static void F_24 ( struct V_2 * V_2 , unsigned long V_33 , void * V_34 )
{
}
static int F_25 ( struct V_2 * V_2 , struct V_35 * V_36 )
{
struct V_1 * V_10 = F_1 ( V_2 ) ;
int V_16 ;
if ( V_10 -> V_37 . V_38 < V_36 -> V_39 - V_36 -> V_40 )
return - V_41 ;
if ( ! V_10 -> V_37 . V_42 )
return - V_43 ;
V_16 = F_26 ( V_10 -> V_37 . V_42 , V_36 ) ;
if ( V_16 )
return V_16 ;
F_27 ( V_36 -> V_44 ) ;
V_36 -> V_44 = F_28 ( V_10 -> V_37 . V_42 ) ;
return 0 ;
}
static int F_29 ( struct V_2 * V_2 , enum V_8 V_45 )
{
struct V_1 * V_10 = F_1 ( V_2 ) ;
struct V_46 * V_28 = V_10 -> V_37 . V_28 ;
bool V_47 = ( V_45 == V_48 || V_45 == V_49 ) ;
int V_18 ;
V_18 = F_4 ( V_10 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_30 ( V_28 ) ;
if ( V_18 )
goto V_50;
V_18 = F_31 ( V_10 , V_47 ) ;
F_32 ( & V_28 -> V_51 ) ;
V_50:
F_13 ( V_10 ) ;
return V_18 ;
}
static int F_33 ( struct V_2 * V_2 , enum V_8 V_45 )
{
struct V_1 * V_10 = F_1 ( V_2 ) ;
struct V_46 * V_28 = V_10 -> V_37 . V_28 ;
int V_18 ;
V_18 = F_4 ( V_10 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_30 ( V_28 ) ;
if ( V_18 )
goto V_50;
V_18 = F_34 ( V_10 , false ) ;
F_32 ( & V_28 -> V_51 ) ;
V_50:
F_13 ( V_10 ) ;
return V_18 ;
}
struct V_2 * F_35 ( struct V_46 * V_28 ,
struct V_52 * V_53 , int V_54 )
{
struct V_1 * V_10 = F_2 ( V_53 ) ;
F_36 ( V_55 ) ;
V_55 . V_56 = & V_57 ;
V_55 . V_38 = V_53 -> V_38 ;
V_55 . V_54 = V_54 ;
V_55 . V_4 = V_53 ;
V_55 . V_58 = V_10 -> V_58 ;
if ( V_10 -> V_56 -> V_59 ) {
int V_16 = V_10 -> V_56 -> V_59 ( V_10 ) ;
if ( V_16 )
return F_14 ( V_16 ) ;
}
return F_37 ( V_28 , & V_55 ) ;
}
static struct V_5 *
F_38 ( struct V_1 * V_10 )
{
return F_39 ( V_10 -> V_37 . V_60 ,
V_48 ) ;
}
static void F_40 ( struct V_1 * V_10 ,
struct V_5 * V_23 )
{
F_41 ( V_10 -> V_37 . V_60 , V_23 ,
V_48 ) ;
}
struct V_52 * F_42 ( struct V_46 * V_28 ,
struct V_2 * V_2 )
{
struct V_6 * V_61 ;
struct V_1 * V_10 ;
int V_16 ;
if ( V_2 -> V_56 == & V_57 ) {
V_10 = F_1 ( V_2 ) ;
if ( V_10 -> V_37 . V_28 == V_28 ) {
return & F_43 ( V_10 ) -> V_37 ;
}
}
V_61 = F_44 ( V_2 , V_28 -> V_28 ) ;
if ( F_45 ( V_61 ) )
return F_46 ( V_61 ) ;
F_47 ( V_2 ) ;
V_10 = F_48 ( F_49 ( V_28 ) ) ;
if ( V_10 == NULL ) {
V_16 = - V_20 ;
goto V_62;
}
F_50 ( V_28 , & V_10 -> V_37 , V_2 -> V_38 ) ;
F_51 ( V_10 , & V_63 ) ;
V_10 -> V_37 . V_60 = V_61 ;
V_10 -> V_58 = V_2 -> V_58 ;
V_10 -> V_37 . V_64 = V_65 ;
V_10 -> V_37 . V_66 = 0 ;
return & V_10 -> V_37 ;
V_62:
F_52 ( V_2 , V_61 ) ;
F_53 ( V_2 ) ;
return F_14 ( V_16 ) ;
}
