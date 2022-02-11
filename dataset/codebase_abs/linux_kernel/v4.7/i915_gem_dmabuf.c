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
F_19 ( V_7 -> V_19 , V_32 -> V_28 , V_32 -> V_26 , V_9 ) ;
F_14 ( V_32 ) ;
F_15 ( V_32 ) ;
F_20 ( & V_10 -> V_18 . V_19 -> V_31 ) ;
F_16 ( V_10 ) ;
F_13 ( & V_10 -> V_18 . V_19 -> V_31 ) ;
}
static void * F_21 ( struct V_2 * V_2 )
{
struct V_1 * V_10 = F_1 ( V_2 ) ;
struct V_33 * V_19 = V_10 -> V_18 . V_19 ;
void * V_34 ;
int V_16 ;
V_16 = F_4 ( V_19 ) ;
if ( V_16 )
return F_17 ( V_16 ) ;
V_34 = F_22 ( V_10 ) ;
F_13 ( & V_19 -> V_31 ) ;
return V_34 ;
}
static void F_23 ( struct V_2 * V_2 , void * V_35 )
{
struct V_1 * V_10 = F_1 ( V_2 ) ;
struct V_33 * V_19 = V_10 -> V_18 . V_19 ;
F_20 ( & V_19 -> V_31 ) ;
F_24 ( V_10 ) ;
F_13 ( & V_19 -> V_31 ) ;
}
static void * F_25 ( struct V_2 * V_2 , unsigned long V_36 )
{
return NULL ;
}
static void F_26 ( struct V_2 * V_2 , unsigned long V_36 , void * V_34 )
{
}
static void * F_27 ( struct V_2 * V_2 , unsigned long V_36 )
{
return NULL ;
}
static void F_28 ( struct V_2 * V_2 , unsigned long V_36 , void * V_34 )
{
}
static int F_29 ( struct V_2 * V_2 , struct V_37 * V_38 )
{
struct V_1 * V_10 = F_1 ( V_2 ) ;
int V_16 ;
if ( V_10 -> V_18 . V_39 < V_38 -> V_40 - V_38 -> V_41 )
return - V_42 ;
if ( ! V_10 -> V_18 . V_43 )
return - V_44 ;
V_16 = V_10 -> V_18 . V_43 -> V_45 -> V_46 ( V_10 -> V_18 . V_43 , V_38 ) ;
if ( V_16 )
return V_16 ;
F_30 ( V_38 -> V_47 ) ;
V_38 -> V_47 = F_31 ( V_10 -> V_18 . V_43 ) ;
return 0 ;
}
static int F_32 ( struct V_2 * V_2 , enum V_8 V_48 )
{
struct V_1 * V_10 = F_1 ( V_2 ) ;
struct V_33 * V_19 = V_10 -> V_18 . V_19 ;
int V_16 ;
bool V_49 = ( V_48 == V_50 || V_48 == V_51 ) ;
V_16 = F_4 ( V_19 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_33 ( V_10 , V_49 ) ;
F_13 ( & V_19 -> V_31 ) ;
return V_16 ;
}
static int F_34 ( struct V_2 * V_2 , enum V_8 V_48 )
{
struct V_1 * V_10 = F_1 ( V_2 ) ;
struct V_33 * V_19 = V_10 -> V_18 . V_19 ;
int V_16 ;
V_16 = F_4 ( V_19 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_35 ( V_10 , false ) ;
F_13 ( & V_19 -> V_31 ) ;
return V_16 ;
}
struct V_2 * F_36 ( struct V_33 * V_19 ,
struct V_52 * V_53 , int V_54 )
{
struct V_1 * V_10 = F_2 ( V_53 ) ;
F_37 ( V_55 ) ;
V_55 . V_56 = & V_57 ;
V_55 . V_39 = V_53 -> V_39 ;
V_55 . V_54 = V_54 ;
V_55 . V_4 = V_53 ;
if ( V_10 -> V_56 -> V_58 ) {
int V_16 = V_10 -> V_56 -> V_58 ( V_10 ) ;
if ( V_16 )
return F_17 ( V_16 ) ;
}
return F_38 ( & V_55 ) ;
}
static int F_39 ( struct V_1 * V_10 )
{
struct V_5 * V_32 ;
V_32 = F_40 ( V_10 -> V_18 . V_59 , V_50 ) ;
if ( F_41 ( V_32 ) )
return F_42 ( V_32 ) ;
V_10 -> V_25 = V_32 ;
return 0 ;
}
static void F_43 ( struct V_1 * V_10 )
{
F_44 ( V_10 -> V_18 . V_59 ,
V_10 -> V_25 , V_50 ) ;
}
struct V_52 * F_45 ( struct V_33 * V_19 ,
struct V_2 * V_2 )
{
struct V_6 * V_60 ;
struct V_1 * V_10 ;
int V_16 ;
if ( V_2 -> V_56 == & V_57 ) {
V_10 = F_1 ( V_2 ) ;
if ( V_10 -> V_18 . V_19 == V_19 ) {
F_46 ( & V_10 -> V_18 ) ;
return & V_10 -> V_18 ;
}
}
V_60 = F_47 ( V_2 , V_19 -> V_19 ) ;
if ( F_41 ( V_60 ) )
return F_48 ( V_60 ) ;
F_49 ( V_2 ) ;
V_10 = F_50 ( V_19 ) ;
if ( V_10 == NULL ) {
V_16 = - V_23 ;
goto V_61;
}
F_51 ( V_19 , & V_10 -> V_18 , V_2 -> V_39 ) ;
F_52 ( V_10 , & V_62 ) ;
V_10 -> V_18 . V_59 = V_60 ;
return & V_10 -> V_18 ;
V_61:
F_53 ( V_2 , V_60 ) ;
F_54 ( V_2 ) ;
return F_17 ( V_16 ) ;
}
