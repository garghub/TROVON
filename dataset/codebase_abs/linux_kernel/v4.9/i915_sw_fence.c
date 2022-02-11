static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
T_1 V_5 ;
V_5 = ( T_1 ) ( V_2 -> V_6 & V_7 ) ;
return V_5 ( V_2 , V_4 ) ;
}
static void F_2 ( struct V_8 * V_8 )
{
struct V_1 * V_2 = F_3 ( V_8 , F_4 ( * V_2 ) , V_8 ) ;
F_5 ( F_6 ( & V_2 -> V_9 ) > 0 ) ;
if ( V_2 -> V_6 & V_7 )
F_1 ( V_2 , V_10 ) ;
else
F_7 ( V_2 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_9 ( & V_2 -> V_8 , F_2 ) ;
}
static struct V_1 * F_10 ( struct V_1 * V_2 )
{
F_11 ( & V_2 -> V_8 ) ;
return V_2 ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
T_2 * V_13 = & V_2 -> V_14 ;
T_3 * V_15 , * V_16 ;
unsigned long V_6 ;
F_13 ( & V_2 -> V_9 , - 1 ) ;
F_14 ( & V_13 -> V_17 , V_6 , 1 + ! ! V_12 ) ;
if ( V_12 ) {
F_15 (pos, next, &x->task_list, task_list) {
if ( V_15 -> V_18 == V_19 )
V_15 -> V_18 ( V_15 , V_20 , 0 , V_12 ) ;
else
F_16 ( & V_15 -> V_21 , V_12 ) ;
}
} else {
F_17 ( V_22 ) ;
do {
F_15 (pos, next,
&x->task_list, task_list)
V_15 -> V_18 ( V_15 , V_20 , 0 , & V_22 ) ;
if ( F_18 ( & V_22 ) )
break;
F_19 ( & V_22 , & V_13 -> V_21 ) ;
} while ( 1 );
}
F_20 ( & V_13 -> V_17 , V_6 ) ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
if ( ! F_22 ( & V_2 -> V_9 ) )
return;
if ( V_2 -> V_6 & V_7 &&
F_1 ( V_2 , V_23 ) != V_24 )
return;
F_12 ( V_2 , V_12 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
if ( F_5 ( F_24 ( V_2 ) ) )
return;
F_21 ( V_2 , NULL ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
F_5 ( F_26 ( & V_2 -> V_9 ) <= 1 ) ;
}
void F_27 ( struct V_1 * V_2 , T_1 V_5 )
{
F_28 ( ( unsigned long ) V_5 & ~ V_7 ) ;
F_29 ( & V_2 -> V_14 ) ;
F_30 ( & V_2 -> V_8 ) ;
F_31 ( & V_2 -> V_9 , 1 ) ;
V_2 -> V_6 = ( unsigned long ) V_5 ;
}
void F_32 ( struct V_1 * V_2 )
{
F_23 ( V_2 ) ;
F_8 ( V_2 ) ;
}
static int F_33 ( T_3 * V_25 , unsigned V_26 , int V_6 , void * V_27 )
{
F_34 ( & V_25 -> V_21 ) ;
F_21 ( V_25 -> V_28 , V_27 ) ;
F_8 ( V_25 -> V_28 ) ;
return 0 ;
}
static bool F_35 ( struct V_1 * V_2 ,
const struct V_1 * const V_29 )
{
T_3 * V_25 ;
if ( F_36 ( V_30 , & V_2 -> V_6 ) )
return false ;
if ( V_2 == V_29 )
return true ;
F_37 (wq, &fence->wait.task_list, task_list) {
if ( V_25 -> V_18 != F_33 )
continue;
if ( F_35 ( V_25 -> V_28 , V_29 ) )
return true ;
}
return false ;
}
static void F_38 ( struct V_1 * V_2 )
{
T_3 * V_25 ;
if ( ! F_39 ( V_30 , & V_2 -> V_6 ) )
return;
F_37 (wq, &fence->wait.task_list, task_list) {
if ( V_25 -> V_18 != F_33 )
continue;
F_38 ( V_25 -> V_28 ) ;
}
}
static bool F_40 ( struct V_1 * V_2 ,
const struct V_1 * const V_29 )
{
unsigned long V_6 ;
bool V_31 ;
if ( ! F_41 ( V_32 ) )
return false ;
F_42 ( & V_33 , V_6 ) ;
V_31 = F_35 ( V_2 , V_29 ) ;
F_38 ( V_2 ) ;
F_20 ( & V_33 , V_6 ) ;
return V_31 ;
}
int F_43 ( struct V_1 * V_2 ,
struct V_1 * V_29 ,
T_3 * V_25 )
{
unsigned long V_6 ;
int V_9 ;
if ( F_24 ( V_29 ) )
return 0 ;
if ( F_44 ( F_40 ( V_2 , V_29 ) ) )
return - V_34 ;
F_45 ( & V_25 -> V_21 ) ;
V_25 -> V_6 = 0 ;
V_25 -> V_18 = F_33 ;
V_25 -> V_28 = F_10 ( V_2 ) ;
F_25 ( V_2 ) ;
F_42 ( & V_29 -> V_14 . V_17 , V_6 ) ;
if ( F_46 ( ! F_24 ( V_29 ) ) ) {
F_47 ( & V_29 -> V_14 , V_25 ) ;
V_9 = 1 ;
} else {
F_33 ( V_25 , 0 , 0 , NULL ) ;
V_9 = 0 ;
}
F_20 ( & V_29 -> V_14 . V_17 , V_6 ) ;
return V_9 ;
}
static void F_48 ( unsigned long V_35 )
{
struct V_36 * V_37 = (struct V_36 * ) V_35 ;
F_49 ( V_38 L_1 ,
V_37 -> V_39 -> V_40 -> V_41 ( V_37 -> V_39 ) ,
V_37 -> V_39 -> V_40 -> V_42 ( V_37 -> V_39 ) ,
V_37 -> V_39 -> V_43 ) ;
F_50 ( V_37 -> V_39 ) ;
V_37 -> V_39 = NULL ;
F_32 ( V_37 -> V_2 ) ;
V_37 -> V_44 . V_45 = NULL ;
}
static void F_51 ( struct V_2 * V_39 , struct V_46 * V_35 )
{
struct V_36 * V_37 = F_3 ( V_35 , F_4 ( * V_37 ) , V_47 ) ;
F_52 ( & V_37 -> V_44 ) ;
if ( V_37 -> V_44 . V_45 )
F_32 ( V_37 -> V_2 ) ;
F_50 ( V_37 -> V_39 ) ;
F_7 ( V_37 ) ;
}
int F_53 ( struct V_1 * V_2 ,
struct V_2 * V_39 ,
unsigned long V_48 ,
T_4 V_49 )
{
struct V_36 * V_37 ;
int V_50 ;
if ( F_54 ( V_39 ) )
return 0 ;
V_37 = F_55 ( sizeof( * V_37 ) , V_49 ) ;
if ( ! V_37 ) {
if ( ! F_56 ( V_49 ) )
return - V_51 ;
return F_57 ( V_39 , false ) ;
}
V_37 -> V_2 = F_10 ( V_2 ) ;
F_25 ( V_2 ) ;
V_37 -> V_39 = NULL ;
F_58 ( & V_37 -> V_44 ,
F_48 , ( unsigned long ) V_37 ,
V_52 ) ;
if ( V_48 ) {
V_37 -> V_39 = F_59 ( V_39 ) ;
F_60 ( & V_37 -> V_44 , F_61 ( V_53 + V_48 ) ) ;
}
V_50 = F_62 ( V_39 , & V_37 -> V_47 , F_51 ) ;
if ( V_50 == 0 ) {
V_50 = 1 ;
} else {
F_51 ( V_39 , & V_37 -> V_47 ) ;
if ( V_50 == - V_54 )
V_50 = 0 ;
}
return V_50 ;
}
int F_63 ( struct V_1 * V_2 ,
struct V_55 * V_56 ,
const struct V_57 * V_58 ,
bool V_59 ,
unsigned long V_48 ,
T_4 V_49 )
{
struct V_2 * V_60 ;
int V_50 = 0 , V_9 ;
if ( V_59 ) {
struct V_2 * * V_61 ;
unsigned int V_62 , V_63 ;
V_50 = F_64 ( V_56 ,
& V_60 , & V_62 , & V_61 ) ;
if ( V_50 )
return V_50 ;
for ( V_63 = 0 ; V_63 < V_62 ; V_63 ++ ) {
if ( V_61 [ V_63 ] -> V_40 == V_58 )
continue;
V_9 = F_53 ( V_2 ,
V_61 [ V_63 ] ,
V_48 ,
V_49 ) ;
if ( V_9 < 0 ) {
V_50 = V_9 ;
break;
}
V_50 |= V_9 ;
}
for ( V_63 = 0 ; V_63 < V_62 ; V_63 ++ )
F_50 ( V_61 [ V_63 ] ) ;
F_7 ( V_61 ) ;
} else {
V_60 = F_65 ( V_56 ) ;
}
if ( V_50 >= 0 && V_60 && V_60 -> V_40 != V_58 ) {
V_9 = F_53 ( V_2 ,
V_60 ,
V_48 ,
V_49 ) ;
if ( V_9 < 0 )
V_50 = V_9 ;
else
V_50 |= V_9 ;
}
F_50 ( V_60 ) ;
return V_50 ;
}
