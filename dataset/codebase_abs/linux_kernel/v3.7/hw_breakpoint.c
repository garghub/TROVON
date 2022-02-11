__weak int F_1 ( struct V_1 * V_2 )
{
return 1 ;
}
static inline enum V_3 F_2 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 . V_5 & V_6 )
return V_7 ;
return V_8 ;
}
static unsigned int F_3 ( int V_9 , enum V_3 type )
{
int V_10 ;
unsigned int * V_11 = F_4 ( V_12 [ type ] , V_9 ) ;
for ( V_10 = V_13 [ type ] - 1 ; V_10 >= 0 ; V_10 -- ) {
if ( V_11 [ V_10 ] > 0 )
return V_10 + 1 ;
}
return 0 ;
}
static int F_5 ( int V_9 , struct V_1 * V_2 , enum V_3 type )
{
struct V_14 * V_15 = V_2 -> V_16 . V_17 ;
struct V_1 * V_18 ;
int V_19 = 0 ;
F_6 (iter, &bp_task_head, hw.bp_list) {
if ( V_18 -> V_16 . V_17 == V_15 &&
F_2 ( V_18 ) == type &&
V_9 == V_18 -> V_9 )
V_19 += F_1 ( V_18 ) ;
}
return V_19 ;
}
static void
F_7 ( struct V_20 * V_21 , struct V_1 * V_2 ,
enum V_3 type )
{
int V_9 = V_2 -> V_9 ;
struct V_14 * V_15 = V_2 -> V_16 . V_17 ;
if ( V_9 >= 0 ) {
V_21 -> V_22 = F_4 ( V_23 [ type ] , V_9 ) ;
if ( ! V_15 )
V_21 -> V_22 += F_3 ( V_9 , type ) ;
else
V_21 -> V_22 += F_5 ( V_9 , V_2 , type ) ;
V_21 -> V_24 = F_4 ( V_25 [ type ] , V_9 ) ;
return;
}
F_8 (cpu) {
unsigned int V_26 ;
V_26 = F_4 ( V_23 [ type ] , V_9 ) ;
if ( ! V_15 )
V_26 += F_3 ( V_9 , type ) ;
else
V_26 += F_5 ( V_9 , V_2 , type ) ;
if ( V_26 > V_21 -> V_22 )
V_21 -> V_22 = V_26 ;
V_26 = F_4 ( V_25 [ type ] , V_9 ) ;
if ( V_26 > V_21 -> V_24 )
V_21 -> V_24 = V_26 ;
}
}
static void
F_9 ( struct V_20 * V_21 , int V_27 )
{
V_21 -> V_22 += V_27 ;
}
static void F_10 ( struct V_1 * V_2 , int V_9 , bool V_28 ,
enum V_3 type , int V_27 )
{
unsigned int * V_11 ;
int V_29 = 0 ;
int V_30 = 0 ;
int V_31 = 0 ;
V_29 = F_5 ( V_9 , V_2 , type ) ;
V_30 = V_29 - 1 ;
V_31 = V_30 + V_27 ;
V_11 = F_4 ( V_12 [ type ] , V_9 ) ;
if ( V_28 ) {
V_11 [ V_31 ] ++ ;
if ( V_29 > 0 )
V_11 [ V_30 ] -- ;
} else {
V_11 [ V_31 ] -- ;
if ( V_29 > 0 )
V_11 [ V_30 ] ++ ;
}
}
static void
F_11 ( struct V_1 * V_2 , bool V_28 , enum V_3 type ,
int V_27 )
{
int V_9 = V_2 -> V_9 ;
struct V_14 * V_15 = V_2 -> V_16 . V_17 ;
if ( ! V_15 ) {
if ( V_28 )
F_4 ( V_23 [ type ] , V_2 -> V_9 ) += V_27 ;
else
F_4 ( V_23 [ type ] , V_2 -> V_9 ) -= V_27 ;
return;
}
if ( ! V_28 )
F_12 ( & V_2 -> V_16 . V_32 ) ;
if ( V_9 >= 0 ) {
F_10 ( V_2 , V_9 , V_28 , type , V_27 ) ;
} else {
F_8 (cpu)
F_10 ( V_2 , V_9 , V_28 , type , V_27 ) ;
}
if ( V_28 )
F_13 ( & V_2 -> V_16 . V_32 , & V_33 ) ;
}
__weak void F_14 ( struct V_1 * V_2 )
{
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_20 V_21 = { 0 } ;
enum V_3 type ;
int V_27 ;
if ( ! V_34 )
return - V_35 ;
if ( V_2 -> V_4 . V_5 == V_36 ||
V_2 -> V_4 . V_5 == V_37 )
return - V_38 ;
type = F_2 ( V_2 ) ;
V_27 = F_1 ( V_2 ) ;
F_7 ( & V_21 , V_2 , type ) ;
F_9 ( & V_21 , V_27 ) ;
if ( V_21 . V_22 + ( ! ! V_21 . V_24 ) > V_13 [ type ] )
return - V_39 ;
F_11 ( V_2 , true , type , V_27 ) ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 )
{
int V_40 ;
F_17 ( & V_41 ) ;
V_40 = F_15 ( V_2 ) ;
F_18 ( & V_41 ) ;
return V_40 ;
}
static void F_19 ( struct V_1 * V_2 )
{
enum V_3 type ;
int V_27 ;
type = F_2 ( V_2 ) ;
V_27 = F_1 ( V_2 ) ;
F_11 ( V_2 , false , type , V_27 ) ;
}
void F_20 ( struct V_1 * V_2 )
{
F_17 ( & V_41 ) ;
F_14 ( V_2 ) ;
F_19 ( V_2 ) ;
F_18 ( & V_41 ) ;
}
int F_21 ( struct V_1 * V_2 )
{
if ( F_22 ( & V_41 ) )
return - 1 ;
return F_15 ( V_2 ) ;
}
int F_23 ( struct V_1 * V_2 )
{
if ( F_22 ( & V_41 ) )
return - 1 ;
F_19 ( V_2 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
int V_40 ;
V_40 = F_25 ( V_2 ) ;
if ( V_40 )
return V_40 ;
if ( F_26 ( V_2 ) ) {
if ( V_2 -> V_4 . V_42 )
return - V_38 ;
if ( ! F_27 ( V_43 ) )
return - V_44 ;
}
return 0 ;
}
int F_28 ( struct V_1 * V_2 )
{
int V_40 ;
V_40 = F_16 ( V_2 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_24 ( V_2 ) ;
if ( V_40 )
F_20 ( V_2 ) ;
return V_40 ;
}
struct V_1 *
F_29 ( struct V_45 * V_4 ,
T_1 V_46 ,
void * V_47 ,
struct V_14 * V_15 )
{
return F_30 ( V_4 , - 1 , V_15 , V_46 ,
V_47 ) ;
}
int F_31 ( struct V_1 * V_2 , struct V_45 * V_4 )
{
T_2 V_48 = V_2 -> V_4 . V_49 ;
T_2 V_50 = V_2 -> V_4 . V_51 ;
int V_52 = V_2 -> V_4 . V_5 ;
int V_53 = 0 ;
if ( F_32 () && V_2 -> V_54 && V_2 -> V_54 -> V_55 == V_56 )
F_33 ( V_2 ) ;
else
F_34 ( V_2 ) ;
V_2 -> V_4 . V_49 = V_4 -> V_49 ;
V_2 -> V_4 . V_5 = V_4 -> V_5 ;
V_2 -> V_4 . V_51 = V_4 -> V_51 ;
if ( V_4 -> V_57 )
goto V_58;
V_53 = F_24 ( V_2 ) ;
if ( ! V_53 )
F_35 ( V_2 ) ;
if ( V_53 ) {
V_2 -> V_4 . V_49 = V_48 ;
V_2 -> V_4 . V_5 = V_52 ;
V_2 -> V_4 . V_51 = V_50 ;
if ( ! V_2 -> V_4 . V_57 )
F_35 ( V_2 ) ;
return V_53 ;
}
V_58:
V_2 -> V_4 . V_57 = V_4 -> V_57 ;
return 0 ;
}
void F_36 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_37 ( V_2 ) ;
}
struct V_1 * T_3 *
F_38 ( struct V_45 * V_4 ,
T_1 V_46 ,
void * V_47 )
{
struct V_1 * T_3 * V_59 , * * V_60 , * V_2 ;
long V_53 ;
int V_9 ;
V_59 = F_39 ( F_40 ( * V_59 ) ) ;
if ( ! V_59 )
return ( void T_3 V_61 * ) F_41 ( - V_35 ) ;
F_42 () ;
F_8 (cpu) {
V_60 = F_43 ( V_59 , V_9 ) ;
V_2 = F_30 ( V_4 , V_9 , NULL ,
V_46 , V_47 ) ;
* V_60 = V_2 ;
if ( F_44 ( V_2 ) ) {
V_53 = F_45 ( V_2 ) ;
goto V_62;
}
}
F_46 () ;
return V_59 ;
V_62:
F_8 (cpu) {
V_60 = F_43 ( V_59 , V_9 ) ;
if ( F_44 ( * V_60 ) )
break;
F_36 ( * V_60 ) ;
}
F_46 () ;
F_47 ( V_59 ) ;
return ( void T_3 V_61 * ) F_41 ( V_53 ) ;
}
void F_48 ( struct V_1 * T_3 * V_59 )
{
int V_9 ;
struct V_1 * * V_60 ;
F_49 (cpu) {
V_60 = F_43 ( V_59 , V_9 ) ;
F_36 ( * V_60 ) ;
}
F_47 ( V_59 ) ;
}
static void F_50 ( struct V_1 * V_63 )
{
F_20 ( V_63 ) ;
}
static int F_51 ( struct V_1 * V_2 )
{
int V_53 ;
if ( V_2 -> V_4 . type != V_64 )
return - V_65 ;
if ( F_52 ( V_2 ) )
return - V_66 ;
V_53 = F_28 ( V_2 ) ;
if ( V_53 )
return V_53 ;
V_2 -> V_67 = F_50 ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 , int V_68 )
{
if ( ! ( V_68 & V_69 ) )
V_2 -> V_16 . V_70 = V_71 ;
return F_54 ( V_2 ) ;
}
static void F_55 ( struct V_1 * V_2 , int V_68 )
{
F_56 ( V_2 ) ;
}
static void F_57 ( struct V_1 * V_2 , int V_68 )
{
V_2 -> V_16 . V_70 = 0 ;
}
static void F_58 ( struct V_1 * V_2 , int V_68 )
{
V_2 -> V_16 . V_70 = V_71 ;
}
static int F_59 ( struct V_1 * V_2 )
{
return 0 ;
}
int T_4 F_60 ( void )
{
unsigned int * * F_5 ;
int V_9 , V_72 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_73 ; V_10 ++ )
V_13 [ V_10 ] = F_61 ( V_10 ) ;
F_49 (cpu) {
for ( V_10 = 0 ; V_10 < V_73 ; V_10 ++ ) {
F_5 = & F_4 ( V_12 [ V_10 ] , V_9 ) ;
* F_5 = F_62 ( sizeof( int ) * V_13 [ V_10 ] ,
V_74 ) ;
if ( ! * F_5 )
goto V_75;
}
}
V_34 = 1 ;
F_63 ( & V_76 , L_1 , V_64 ) ;
return F_64 ( & V_77 ) ;
V_75:
F_49 (err_cpu) {
for ( V_10 = 0 ; V_10 < V_73 ; V_10 ++ )
F_65 ( F_4 ( V_12 [ V_10 ] , V_9 ) ) ;
if ( V_72 == V_9 )
break;
}
return - V_35 ;
}
