static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 ;
F_2 ( L_1 , F_3 ( V_6 -> V_4 ) ,
V_6 -> V_2 -> V_9 ) ;
V_8 = F_4 ( sizeof( * V_8 ) , V_10 ) ;
if ( ! V_8 )
return - V_11 ;
V_8 -> V_12 = V_13 ;
V_6 -> V_14 = V_8 ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_14 ;
struct V_15 * V_16 ;
if ( ! V_8 )
return;
F_2 ( L_1 , F_3 ( V_6 -> V_4 ) ,
V_6 -> V_2 -> V_9 ) ;
V_16 = & V_8 -> V_16 ;
if ( V_8 -> V_12 != V_13 )
F_6 ( V_6 -> V_4 , V_16 -> V_17 , V_16 -> V_18 ,
V_8 -> V_12 ) ;
F_7 ( V_16 ) ;
F_8 ( V_8 ) ;
V_6 -> V_14 = NULL ;
}
static struct V_15 * F_9 ( struct V_5 * V_6 ,
enum V_19 V_12 )
{
struct V_7 * V_8 = V_6 -> V_14 ;
struct V_20 * V_21 = F_10 ( V_6 -> V_2 -> V_14 ) ;
struct V_22 * V_4 = V_21 -> V_23 . V_4 ;
struct V_24 * V_25 , * V_26 ;
struct V_15 * V_16 = NULL ;
unsigned int V_27 ;
int V_28 ;
int V_18 , V_29 ;
F_2 ( L_2 , F_3 ( V_6 -> V_4 ) ,
V_6 -> V_2 -> V_9 , V_12 ) ;
if ( V_8 -> V_12 == V_12 && V_8 -> V_30 )
return & V_8 -> V_16 ;
if ( ! V_21 -> V_31 ) {
V_29 = F_11 ( V_21 ) ;
if ( V_29 ) {
F_12 ( L_3 ) ;
return F_13 ( V_29 ) ;
}
}
V_28 = V_21 -> V_23 . V_9 / V_32 ;
V_21 -> V_33 = F_14 ( V_21 -> V_31 , V_28 ) ;
if ( F_15 ( V_21 -> V_33 ) ) {
F_12 ( L_4 ) ;
return F_16 ( V_21 -> V_33 ) ;
}
V_16 = & V_8 -> V_16 ;
V_29 = F_17 ( V_16 , V_21 -> V_33 -> V_34 , V_10 ) ;
if ( V_29 ) {
F_12 ( L_5 ) ;
return F_13 ( - V_11 ) ;
}
F_18 ( & V_4 -> V_35 ) ;
V_25 = V_21 -> V_33 -> V_17 ;
V_26 = V_16 -> V_17 ;
for ( V_27 = 0 ; V_27 < V_16 -> V_34 ; ++ V_27 ) {
F_19 ( V_26 , F_20 ( V_25 ) , V_25 -> V_36 , V_25 -> V_37 ) ;
V_25 = F_21 ( V_25 ) ;
V_26 = F_21 ( V_26 ) ;
}
if ( V_12 != V_13 ) {
V_18 = F_22 ( V_6 -> V_4 , V_16 -> V_17 , V_16 -> V_34 , V_12 ) ;
if ( ! V_18 ) {
F_12 ( L_6 ) ;
F_7 ( V_16 ) ;
V_16 = F_13 ( - V_38 ) ;
goto V_39;
}
}
V_8 -> V_30 = true ;
V_8 -> V_12 = V_12 ;
V_6 -> V_14 = V_8 ;
V_39:
F_23 ( & V_4 -> V_35 ) ;
return V_16 ;
}
static void F_24 ( struct V_5 * V_6 ,
struct V_15 * V_16 ,
enum V_19 V_12 )
{
F_2 ( L_7 , F_3 ( V_6 -> V_4 ) ,
V_6 -> V_2 -> V_9 , V_12 ) ;
}
static void * F_25 ( struct V_1 * V_1 , unsigned long V_40 )
{
return NULL ;
}
static void * F_26 ( struct V_1 * V_1 ,
unsigned long V_40 )
{
return NULL ;
}
static void F_27 ( struct V_1 * V_1 ,
unsigned long V_40 , void * V_41 )
{
}
static void F_28 ( struct V_1 * V_1 ,
unsigned long V_40 ,
void * V_41 )
{
}
static int F_29 ( struct V_1 * V_1 ,
struct V_42 * V_43 )
{
return - V_44 ;
}
struct V_1 * F_30 ( struct V_22 * V_4 ,
struct V_45 * V_21 , int V_46 )
{
F_31 ( V_47 ) ;
V_47 . V_48 = & V_49 ;
V_47 . V_9 = V_21 -> V_9 ;
V_47 . V_46 = V_46 ;
V_47 . V_14 = V_21 ;
return F_32 ( V_4 , & V_47 ) ;
}
static int F_33 ( struct V_22 * V_4 ,
T_1 V_9 ,
struct V_15 * V_33 ,
struct V_20 * * V_50 )
{
struct V_20 * V_21 ;
int V_51 ;
V_51 = V_9 / V_32 ;
* V_50 = NULL ;
V_21 = F_34 ( V_4 , V_51 * V_32 ) ;
if ( ! V_21 )
return - V_11 ;
V_21 -> V_33 = V_33 ;
V_21 -> V_31 = F_35 ( V_51 , sizeof( struct V_52 * ) ) ;
if ( V_21 -> V_31 == NULL ) {
F_12 ( L_8 , V_51 ) ;
return - V_11 ;
}
F_36 ( V_33 , V_21 -> V_31 , NULL , V_51 ) ;
* V_50 = V_21 ;
return 0 ;
}
struct V_45 * F_37 ( struct V_22 * V_4 ,
struct V_1 * V_1 )
{
struct V_5 * V_6 ;
struct V_15 * V_33 ;
struct V_20 * V_53 ;
int V_29 ;
F_38 ( V_4 -> V_4 ) ;
V_6 = F_39 ( V_1 , V_4 -> V_4 ) ;
if ( F_15 ( V_6 ) ) {
F_40 ( V_4 -> V_4 ) ;
return F_16 ( V_6 ) ;
}
F_41 ( V_1 ) ;
V_33 = F_42 ( V_6 , V_54 ) ;
if ( F_15 ( V_33 ) ) {
V_29 = F_43 ( V_33 ) ;
goto V_55;
}
V_29 = F_33 ( V_4 , V_1 -> V_9 , V_33 , & V_53 ) ;
if ( V_29 )
goto V_56;
V_53 -> V_23 . V_57 = V_6 ;
V_53 -> V_46 = V_58 ;
return & V_53 -> V_23 ;
V_56:
F_44 ( V_6 , V_33 , V_54 ) ;
V_55:
F_45 ( V_1 , V_6 ) ;
F_46 ( V_1 ) ;
F_40 ( V_4 -> V_4 ) ;
return F_13 ( V_29 ) ;
}
