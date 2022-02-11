static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 ;
V_8 = F_2 ( sizeof( * V_8 ) , V_9 ) ;
if ( ! V_8 )
return - V_10 ;
V_8 -> V_11 = V_12 ;
V_6 -> V_13 = V_8 ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_13 ;
struct V_14 * V_15 ;
if ( ! V_8 )
return;
V_15 = & V_8 -> V_15 ;
if ( V_8 -> V_11 != V_12 )
F_4 ( V_6 -> V_4 , V_15 -> V_16 , V_15 -> V_17 ,
V_8 -> V_11 ) ;
F_5 ( V_15 ) ;
F_6 ( V_8 ) ;
V_6 -> V_13 = NULL ;
}
static struct V_14 *
F_7 ( struct V_5 * V_6 ,
enum V_18 V_11 )
{
struct V_7 * V_8 = V_6 -> V_13 ;
struct V_19 * V_20 = V_6 -> V_2 -> V_13 ;
struct V_21 * V_4 = V_20 -> V_22 . V_4 ;
struct V_23 * V_24 ;
struct V_25 * V_26 , * V_27 ;
struct V_14 * V_15 = NULL ;
unsigned int V_28 ;
int V_17 , V_29 ;
F_8 ( L_1 , __FILE__ ) ;
if ( V_8 -> V_11 == V_11 && V_8 -> V_30 )
return & V_8 -> V_15 ;
V_24 = V_20 -> V_31 ;
if ( ! V_24 ) {
F_9 ( L_2 ) ;
return F_10 ( - V_10 ) ;
}
V_15 = & V_8 -> V_15 ;
V_29 = F_11 ( V_15 , V_24 -> V_15 -> V_32 , V_9 ) ;
if ( V_29 ) {
F_9 ( L_3 ) ;
return F_10 ( - V_10 ) ;
}
F_12 ( & V_4 -> V_33 ) ;
V_26 = V_24 -> V_15 -> V_16 ;
V_27 = V_15 -> V_16 ;
for ( V_28 = 0 ; V_28 < V_15 -> V_32 ; ++ V_28 ) {
F_13 ( V_27 , F_14 ( V_26 ) , V_26 -> V_34 , V_26 -> V_35 ) ;
V_26 = F_15 ( V_26 ) ;
V_27 = F_15 ( V_27 ) ;
}
if ( V_11 != V_12 ) {
V_17 = F_16 ( V_6 -> V_4 , V_15 -> V_16 , V_15 -> V_32 , V_11 ) ;
if ( ! V_17 ) {
F_9 ( L_4 ) ;
F_5 ( V_15 ) ;
V_15 = F_10 ( - V_36 ) ;
goto V_37;
}
}
V_8 -> V_30 = true ;
V_8 -> V_11 = V_11 ;
V_6 -> V_13 = V_8 ;
F_8 ( L_5 , V_24 -> V_38 ) ;
V_37:
F_17 ( & V_4 -> V_33 ) ;
return V_15 ;
}
static void F_18 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
enum V_18 V_11 )
{
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_19 * V_39 = V_2 -> V_13 ;
F_8 ( L_1 , __FILE__ ) ;
if ( V_39 -> V_22 . V_40 == V_2 ) {
V_39 -> V_22 . V_40 = NULL ;
F_20 ( & V_39 -> V_22 ) ;
}
}
static void * F_21 ( struct V_1 * V_1 ,
unsigned long V_41 )
{
return NULL ;
}
static void F_22 ( struct V_1 * V_1 ,
unsigned long V_41 ,
void * V_42 )
{
}
static void * F_23 ( struct V_1 * V_1 ,
unsigned long V_41 )
{
return NULL ;
}
static void F_24 ( struct V_1 * V_1 ,
unsigned long V_41 , void * V_42 )
{
}
static int F_25 ( struct V_1 * V_1 ,
struct V_43 * V_44 )
{
return - V_45 ;
}
struct V_1 * F_26 ( struct V_21 * V_46 ,
struct V_47 * V_48 , int V_49 )
{
struct V_19 * V_39 = F_27 ( V_48 ) ;
return F_28 ( V_39 , & V_50 ,
V_39 -> V_22 . V_38 , V_49 ) ;
}
struct V_47 * F_29 ( struct V_21 * V_46 ,
struct V_1 * V_1 )
{
struct V_5 * V_6 ;
struct V_14 * V_15 ;
struct V_25 * V_16 ;
struct V_19 * V_39 ;
struct V_23 * V_31 ;
int V_29 ;
F_8 ( L_1 , __FILE__ ) ;
if ( V_1 -> V_51 == & V_50 ) {
struct V_47 * V_48 ;
V_39 = V_1 -> V_13 ;
V_48 = & V_39 -> V_22 ;
if ( V_48 -> V_4 == V_46 ) {
F_30 ( V_48 ) ;
return V_48 ;
}
}
V_6 = F_31 ( V_1 , V_46 -> V_4 ) ;
if ( F_32 ( V_6 ) )
return F_10 ( - V_52 ) ;
F_33 ( V_1 ) ;
V_15 = F_34 ( V_6 , V_53 ) ;
if ( F_35 ( V_15 ) ) {
V_29 = F_36 ( V_15 ) ;
goto V_54;
}
V_31 = F_2 ( sizeof( * V_31 ) , V_9 ) ;
if ( ! V_31 ) {
F_9 ( L_6 ) ;
V_29 = - V_10 ;
goto V_55;
}
V_39 = F_37 ( V_46 , V_1 -> V_38 ) ;
if ( ! V_39 ) {
V_29 = - V_10 ;
goto V_56;
}
V_16 = V_15 -> V_16 ;
V_31 -> V_38 = V_1 -> V_38 ;
V_31 -> V_57 = F_38 ( V_16 ) ;
if ( V_15 -> V_17 == 1 ) {
V_39 -> V_49 |= V_58 ;
} else {
V_39 -> V_49 |= V_59 ;
}
V_39 -> V_31 = V_31 ;
V_31 -> V_15 = V_15 ;
V_39 -> V_22 . V_60 = V_6 ;
F_8 ( L_7 , V_31 -> V_57 ,
V_31 -> V_38 ) ;
return & V_39 -> V_22 ;
V_56:
F_6 ( V_31 ) ;
V_31 = NULL ;
V_55:
F_39 ( V_6 , V_15 , V_53 ) ;
V_54:
F_40 ( V_1 , V_6 ) ;
F_41 ( V_1 ) ;
return F_10 ( V_29 ) ;
}
