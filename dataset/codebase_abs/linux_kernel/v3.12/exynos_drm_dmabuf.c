static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 ) ;
}
static int F_3 ( struct V_2 * V_5 ,
struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_10 * V_11 ;
V_11 = F_4 ( sizeof( * V_11 ) , V_12 ) ;
if ( ! V_11 )
return - V_13 ;
V_11 -> V_14 = V_15 ;
V_9 -> V_4 = V_11 ;
return 0 ;
}
static void F_5 ( struct V_2 * V_5 ,
struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_4 ;
struct V_16 * V_17 ;
if ( ! V_11 )
return;
V_17 = & V_11 -> V_17 ;
if ( V_11 -> V_14 != V_15 )
F_6 ( V_9 -> V_7 , V_17 -> V_18 , V_17 -> V_19 ,
V_11 -> V_14 ) ;
F_7 ( V_17 ) ;
F_8 ( V_11 ) ;
V_9 -> V_4 = NULL ;
}
static struct V_16 *
F_9 ( struct V_8 * V_9 ,
enum V_20 V_14 )
{
struct V_10 * V_11 = V_9 -> V_4 ;
struct V_1 * V_21 = F_1 ( V_9 -> V_5 ) ;
struct V_22 * V_7 = V_21 -> V_23 . V_7 ;
struct V_24 * V_3 ;
struct V_25 * V_26 , * V_27 ;
struct V_16 * V_17 = NULL ;
unsigned int V_28 ;
int V_19 , V_29 ;
if ( V_11 -> V_14 == V_14 && V_11 -> V_30 )
return & V_11 -> V_17 ;
V_3 = V_21 -> V_31 ;
if ( ! V_3 ) {
F_10 ( L_1 ) ;
return F_11 ( - V_13 ) ;
}
V_17 = & V_11 -> V_17 ;
V_29 = F_12 ( V_17 , V_3 -> V_17 -> V_32 , V_12 ) ;
if ( V_29 ) {
F_10 ( L_2 ) ;
return F_11 ( - V_13 ) ;
}
F_13 ( & V_7 -> V_33 ) ;
V_26 = V_3 -> V_17 -> V_18 ;
V_27 = V_17 -> V_18 ;
for ( V_28 = 0 ; V_28 < V_17 -> V_32 ; ++ V_28 ) {
F_14 ( V_27 , F_15 ( V_26 ) , V_26 -> V_34 , V_26 -> V_35 ) ;
V_26 = F_16 ( V_26 ) ;
V_27 = F_16 ( V_27 ) ;
}
if ( V_14 != V_15 ) {
V_19 = F_17 ( V_9 -> V_7 , V_17 -> V_18 , V_17 -> V_32 , V_14 ) ;
if ( ! V_19 ) {
F_10 ( L_3 ) ;
F_7 ( V_17 ) ;
V_17 = F_11 ( - V_36 ) ;
goto V_37;
}
}
V_11 -> V_30 = true ;
V_11 -> V_14 = V_14 ;
V_9 -> V_4 = V_11 ;
F_18 ( L_4 , V_3 -> V_38 ) ;
V_37:
F_19 ( & V_7 -> V_33 ) ;
return V_17 ;
}
static void F_20 ( struct V_8 * V_9 ,
struct V_16 * V_17 ,
enum V_20 V_14 )
{
}
static void * F_21 ( struct V_2 * V_2 ,
unsigned long V_39 )
{
return NULL ;
}
static void F_22 ( struct V_2 * V_2 ,
unsigned long V_39 ,
void * V_40 )
{
}
static void * F_23 ( struct V_2 * V_2 ,
unsigned long V_39 )
{
return NULL ;
}
static void F_24 ( struct V_2 * V_2 ,
unsigned long V_39 , void * V_40 )
{
}
static int F_25 ( struct V_2 * V_2 ,
struct V_41 * V_42 )
{
return - V_43 ;
}
struct V_2 * F_26 ( struct V_22 * V_44 ,
struct V_45 * V_46 , int V_47 )
{
struct V_1 * V_48 = F_2 ( V_46 ) ;
return F_27 ( V_46 , & V_49 ,
V_48 -> V_23 . V_38 , V_47 ) ;
}
struct V_45 * F_28 ( struct V_22 * V_44 ,
struct V_2 * V_2 )
{
struct V_8 * V_9 ;
struct V_16 * V_17 ;
struct V_25 * V_18 ;
struct V_1 * V_48 ;
struct V_24 * V_31 ;
int V_29 ;
if ( V_2 -> V_50 == & V_49 ) {
struct V_45 * V_46 ;
V_46 = V_2 -> V_4 ;
if ( V_46 -> V_7 == V_44 ) {
F_29 ( V_46 ) ;
return V_46 ;
}
}
V_9 = F_30 ( V_2 , V_44 -> V_7 ) ;
if ( F_31 ( V_9 ) )
return F_11 ( - V_51 ) ;
F_32 ( V_2 ) ;
V_17 = F_33 ( V_9 , V_52 ) ;
if ( F_34 ( V_17 ) ) {
V_29 = F_35 ( V_17 ) ;
goto V_53;
}
V_31 = F_4 ( sizeof( * V_31 ) , V_12 ) ;
if ( ! V_31 ) {
V_29 = - V_13 ;
goto V_54;
}
V_48 = F_36 ( V_44 , V_2 -> V_38 ) ;
if ( ! V_48 ) {
V_29 = - V_13 ;
goto V_55;
}
V_18 = V_17 -> V_18 ;
V_31 -> V_38 = V_2 -> V_38 ;
V_31 -> V_56 = F_37 ( V_18 ) ;
if ( V_17 -> V_19 == 1 ) {
V_48 -> V_47 |= V_57 ;
} else {
V_48 -> V_47 |= V_58 ;
}
V_48 -> V_31 = V_31 ;
V_31 -> V_17 = V_17 ;
V_48 -> V_23 . V_59 = V_9 ;
F_18 ( L_5 , V_31 -> V_56 ,
V_31 -> V_38 ) ;
return & V_48 -> V_23 ;
V_55:
F_8 ( V_31 ) ;
V_31 = NULL ;
V_54:
F_38 ( V_9 , V_17 , V_52 ) ;
V_53:
F_39 ( V_2 , V_9 ) ;
F_40 ( V_2 ) ;
return F_11 ( V_29 ) ;
}
