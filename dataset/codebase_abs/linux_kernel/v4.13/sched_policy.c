static bool F_1 ( struct V_1 * V_2 )
{
enum V_3 V_4 ;
struct V_5 * V_6 ;
F_2 (engine, vgpu->gvt->dev_priv, i) {
if ( ! F_3 ( F_4 ( V_2 , V_4 ) ) )
return true ;
}
return false ;
}
static void F_5 ( struct V_1 * V_7 )
{
T_1 V_8 ;
struct V_9 * V_10 = V_7 -> V_11 ;
V_8 = V_10 -> V_12 - V_10 -> V_13 ;
V_10 -> V_14 += V_8 ;
V_10 -> V_15 -= V_8 ;
}
static void F_6 ( struct V_16 * V_11 )
{
struct V_9 * V_10 ;
struct V_17 * V_18 ;
static T_2 V_19 ;
int V_20 = V_19 ++ % V_21 ;
if ( V_20 == 0 ) {
int V_22 = 0 ;
T_1 V_23 ;
F_7 (pos, &sched_data->lru_runq_head) {
V_10 = F_8 ( V_18 , struct V_9 , V_24 ) ;
V_22 += V_10 -> V_25 . V_26 ;
}
F_7 (pos, &sched_data->lru_runq_head) {
V_10 = F_8 ( V_18 , struct V_9 , V_24 ) ;
V_23 = F_9 ( V_27 ) *
V_10 -> V_25 . V_26 /
V_22 ;
V_10 -> V_28 = V_23 ;
V_10 -> V_15 = V_10 -> V_28 ;
}
} else {
F_7 (pos, &sched_data->lru_runq_head) {
V_10 = F_8 ( V_18 , struct V_9 , V_24 ) ;
V_10 -> V_15 += V_10 -> V_28 ;
}
}
}
static void F_10 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = & V_30 -> V_32 ;
enum V_3 V_4 ;
struct V_5 * V_6 ;
struct V_9 * V_10 ;
T_1 V_33 ;
if ( V_32 -> V_34 == V_32 -> V_35 ) {
V_32 -> V_34 = NULL ;
return;
}
V_32 -> V_36 = true ;
F_2 (engine, gvt->dev_priv, i) {
if ( V_32 -> V_37 [ V_4 ] )
return;
}
V_33 = F_11 () ;
if ( V_32 -> V_35 ) {
V_10 = V_32 -> V_35 -> V_11 ;
V_10 -> V_12 = V_33 ;
F_5 ( V_32 -> V_35 ) ;
}
V_10 = V_32 -> V_34 -> V_11 ;
V_10 -> V_13 = V_33 ;
V_32 -> V_35 = V_32 -> V_34 ;
V_32 -> V_34 = NULL ;
V_32 -> V_36 = false ;
F_2 (engine, gvt->dev_priv, i)
F_12 ( & V_32 -> V_38 [ V_4 ] ) ;
}
static struct V_1 * F_13 ( struct V_16 * V_11 )
{
struct V_9 * V_10 ;
struct V_1 * V_2 = NULL ;
struct V_17 * V_39 = & V_11 -> V_40 ;
struct V_17 * V_18 ;
F_7 (pos, head) {
V_10 = F_8 ( V_18 , struct V_9 , V_24 ) ;
if ( ! F_1 ( V_10 -> V_2 ) )
continue;
if ( V_10 -> V_15 > 0 ) {
V_2 = V_10 -> V_2 ;
break;
}
}
return V_2 ;
}
static void F_14 ( struct V_16 * V_11 )
{
struct V_29 * V_30 = V_11 -> V_30 ;
struct V_31 * V_32 = & V_30 -> V_32 ;
struct V_9 * V_10 ;
struct V_1 * V_2 = NULL ;
if ( F_3 ( & V_11 -> V_40 ) || V_32 -> V_34 )
goto V_41;
V_2 = F_13 ( V_11 ) ;
if ( V_2 ) {
V_32 -> V_34 = V_2 ;
V_10 = V_2 -> V_11 ;
F_15 ( & V_10 -> V_24 ) ;
F_16 ( & V_10 -> V_24 ,
& V_11 -> V_40 ) ;
} else {
V_32 -> V_34 = V_30 -> V_42 ;
}
V_41:
if ( V_32 -> V_34 )
F_10 ( V_30 ) ;
}
void F_17 ( struct V_29 * V_30 )
{
struct V_16 * V_11 = V_30 -> V_32 . V_11 ;
static T_2 V_43 ;
F_18 ( & V_30 -> V_44 ) ;
if ( F_19 ( V_45 ,
( void * ) & V_30 -> V_46 ) ) {
if ( ! ( V_43 ++ % V_27 ) )
F_6 ( V_11 ) ;
}
F_20 ( V_47 , ( void * ) & V_30 -> V_46 ) ;
F_14 ( V_11 ) ;
F_21 ( & V_30 -> V_44 ) ;
}
static enum V_48 F_22 ( struct V_49 * V_50 )
{
struct V_16 * V_51 ;
V_51 = F_8 ( V_50 , struct V_16 , V_52 ) ;
F_23 ( V_51 -> V_30 , V_45 ) ;
F_24 ( & V_51 -> V_52 , V_51 -> V_53 ) ;
return V_54 ;
}
static int F_25 ( struct V_29 * V_30 )
{
struct V_31 * V_32 =
& V_30 -> V_32 ;
struct V_16 * V_51 ;
V_51 = F_26 ( sizeof( * V_51 ) , V_55 ) ;
if ( ! V_51 )
return - V_56 ;
F_27 ( & V_51 -> V_40 ) ;
F_28 ( & V_51 -> V_52 , V_57 , V_58 ) ;
V_51 -> V_52 . V_59 = F_22 ;
V_51 -> V_53 = V_60 ;
V_51 -> V_30 = V_30 ;
V_32 -> V_11 = V_51 ;
return 0 ;
}
static void F_29 ( struct V_29 * V_30 )
{
struct V_31 * V_32 =
& V_30 -> V_32 ;
struct V_16 * V_51 = V_32 -> V_11 ;
F_30 ( & V_51 -> V_52 ) ;
F_31 ( V_51 ) ;
V_32 -> V_11 = NULL ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_9 * V_51 ;
V_51 = F_26 ( sizeof( * V_51 ) , V_55 ) ;
if ( ! V_51 )
return - V_56 ;
V_51 -> V_25 . V_26 = V_2 -> V_25 . V_26 ;
V_51 -> V_2 = V_2 ;
F_27 ( & V_51 -> V_24 ) ;
V_2 -> V_11 = V_51 ;
return 0 ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = & V_2 -> V_30 -> V_32 ;
int V_61 ;
F_31 ( V_2 -> V_11 ) ;
V_2 -> V_11 = NULL ;
F_34 ( & V_32 -> V_62 ) ;
for ( V_61 = 0 ; V_61 < V_63 ; V_61 ++ ) {
if ( V_32 -> V_64 [ V_61 ] == V_2 ) {
F_35 ( V_2 , NULL , V_61 ) ;
V_32 -> V_64 [ V_61 ] = NULL ;
}
}
F_36 ( & V_32 -> V_62 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_16 * V_11 = V_2 -> V_30 -> V_32 . V_11 ;
struct V_9 * V_10 = V_2 -> V_11 ;
if ( ! F_3 ( & V_10 -> V_24 ) )
return;
F_16 ( & V_10 -> V_24 , & V_11 -> V_40 ) ;
if ( ! F_38 ( & V_11 -> V_52 ) )
F_39 ( & V_11 -> V_52 , F_40 ( F_11 () ,
V_11 -> V_53 ) , V_58 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
F_15 ( & V_10 -> V_24 ) ;
}
int F_42 ( struct V_29 * V_30 )
{
V_30 -> V_32 . V_65 = & V_66 ;
return V_30 -> V_32 . V_65 -> V_67 ( V_30 ) ;
}
void F_43 ( struct V_29 * V_30 )
{
V_30 -> V_32 . V_65 -> V_68 ( V_30 ) ;
}
int F_44 ( struct V_1 * V_2 )
{
return V_2 -> V_30 -> V_32 . V_65 -> V_69 ( V_2 ) ;
}
void F_45 ( struct V_1 * V_2 )
{
V_2 -> V_30 -> V_32 . V_65 -> V_70 ( V_2 ) ;
}
void F_46 ( struct V_1 * V_2 )
{
F_47 ( L_1 , V_2 -> V_71 ) ;
V_2 -> V_30 -> V_32 . V_65 -> V_72 ( V_2 ) ;
}
void F_48 ( struct V_1 * V_2 )
{
struct V_31 * V_32 =
& V_2 -> V_30 -> V_32 ;
F_47 ( L_2 , V_2 -> V_71 ) ;
V_32 -> V_65 -> V_73 ( V_2 ) ;
if ( V_32 -> V_34 == V_2 )
V_32 -> V_34 = NULL ;
if ( V_32 -> V_35 == V_2 ) {
V_32 -> V_36 = true ;
V_32 -> V_35 = NULL ;
}
}
