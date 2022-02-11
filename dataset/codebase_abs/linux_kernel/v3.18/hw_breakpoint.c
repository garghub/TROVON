static struct V_1 * F_1 ( int V_2 , enum V_3 type )
{
return F_2 ( V_1 + type , V_2 ) ;
}
__weak int F_3 ( struct V_4 * V_5 )
{
return 1 ;
}
static inline enum V_3 F_4 ( struct V_4 * V_5 )
{
if ( V_5 -> V_6 . V_7 & V_8 )
return V_9 ;
return V_10 ;
}
static unsigned int F_5 ( int V_2 , enum V_3 type )
{
unsigned int * V_11 = F_1 ( V_2 , type ) -> V_11 ;
int V_12 ;
for ( V_12 = V_13 [ type ] - 1 ; V_12 >= 0 ; V_12 -- ) {
if ( V_11 [ V_12 ] > 0 )
return V_12 + 1 ;
}
return 0 ;
}
static int F_6 ( int V_2 , struct V_4 * V_5 , enum V_3 type )
{
struct V_14 * V_15 = V_5 -> V_16 . V_17 ;
struct V_4 * V_18 ;
int V_19 = 0 ;
F_7 (iter, &bp_task_head, hw.bp_list) {
if ( V_18 -> V_16 . V_17 == V_15 &&
F_4 ( V_18 ) == type &&
( V_18 -> V_2 < 0 || V_2 == V_18 -> V_2 ) )
V_19 += F_3 ( V_18 ) ;
}
return V_19 ;
}
static const struct V_20 * F_8 ( struct V_4 * V_5 )
{
if ( V_5 -> V_2 >= 0 )
return F_9 ( V_5 -> V_2 ) ;
return V_21 ;
}
static void
F_10 ( struct V_22 * V_23 , struct V_4 * V_5 ,
enum V_3 type )
{
const struct V_20 * V_20 = F_8 ( V_5 ) ;
int V_2 ;
F_11 (cpu, cpumask) {
struct V_1 * V_24 = F_1 ( V_2 , type ) ;
int V_25 ;
V_25 = V_24 -> V_26 ;
if ( ! V_5 -> V_16 . V_17 )
V_25 += F_5 ( V_2 , type ) ;
else
V_25 += F_6 ( V_2 , V_5 , type ) ;
if ( V_25 > V_23 -> V_27 )
V_23 -> V_27 = V_25 ;
V_25 = V_24 -> V_28 ;
if ( V_25 > V_23 -> V_28 )
V_23 -> V_28 = V_25 ;
}
}
static void
F_12 ( struct V_22 * V_23 , int V_29 )
{
V_23 -> V_27 += V_29 ;
}
static void F_13 ( struct V_4 * V_5 , int V_2 ,
enum V_3 type , int V_29 )
{
unsigned int * V_11 = F_1 ( V_2 , type ) -> V_11 ;
int V_30 , V_31 ;
V_30 = F_6 ( V_2 , V_5 , type ) - 1 ;
V_31 = V_30 + V_29 ;
if ( V_30 >= 0 )
V_11 [ V_30 ] -- ;
if ( V_31 >= 0 )
V_11 [ V_31 ] ++ ;
}
static void
F_14 ( struct V_4 * V_5 , bool V_32 , enum V_3 type ,
int V_29 )
{
const struct V_20 * V_20 = F_8 ( V_5 ) ;
int V_2 ;
if ( ! V_32 )
V_29 = - V_29 ;
if ( ! V_5 -> V_16 . V_17 ) {
F_1 ( V_5 -> V_2 , type ) -> V_26 += V_29 ;
return;
}
F_11 (cpu, cpumask)
F_13 ( V_5 , V_2 , type , V_29 ) ;
if ( V_32 )
F_15 ( & V_5 -> V_16 . V_33 , & V_34 ) ;
else
F_16 ( & V_5 -> V_16 . V_33 ) ;
}
__weak void F_17 ( struct V_4 * V_5 )
{
}
static int F_18 ( struct V_4 * V_5 )
{
struct V_22 V_23 = { 0 } ;
enum V_3 type ;
int V_29 ;
if ( ! V_35 )
return - V_36 ;
if ( V_5 -> V_6 . V_7 == V_37 ||
V_5 -> V_6 . V_7 == V_38 )
return - V_39 ;
type = F_4 ( V_5 ) ;
V_29 = F_3 ( V_5 ) ;
F_10 ( & V_23 , V_5 , type ) ;
F_12 ( & V_23 , V_29 ) ;
if ( V_23 . V_27 + ( ! ! V_23 . V_28 ) > V_13 [ type ] )
return - V_40 ;
F_14 ( V_5 , true , type , V_29 ) ;
return 0 ;
}
int F_19 ( struct V_4 * V_5 )
{
int V_41 ;
F_20 ( & V_42 ) ;
V_41 = F_18 ( V_5 ) ;
F_21 ( & V_42 ) ;
return V_41 ;
}
static void F_22 ( struct V_4 * V_5 )
{
enum V_3 type ;
int V_29 ;
type = F_4 ( V_5 ) ;
V_29 = F_3 ( V_5 ) ;
F_14 ( V_5 , false , type , V_29 ) ;
}
void F_23 ( struct V_4 * V_5 )
{
F_20 ( & V_42 ) ;
F_17 ( V_5 ) ;
F_22 ( V_5 ) ;
F_21 ( & V_42 ) ;
}
int F_24 ( struct V_4 * V_5 )
{
if ( F_25 ( & V_42 ) )
return - 1 ;
return F_18 ( V_5 ) ;
}
int F_26 ( struct V_4 * V_5 )
{
if ( F_25 ( & V_42 ) )
return - 1 ;
F_22 ( V_5 ) ;
return 0 ;
}
static int F_27 ( struct V_4 * V_5 )
{
int V_41 ;
V_41 = F_28 ( V_5 ) ;
if ( V_41 )
return V_41 ;
if ( F_29 ( V_5 ) ) {
if ( V_5 -> V_6 . V_43 )
return - V_39 ;
if ( ! F_30 ( V_44 ) )
return - V_45 ;
}
return 0 ;
}
int F_31 ( struct V_4 * V_5 )
{
int V_41 ;
V_41 = F_19 ( V_5 ) ;
if ( V_41 )
return V_41 ;
V_41 = F_27 ( V_5 ) ;
if ( V_41 )
F_23 ( V_5 ) ;
return V_41 ;
}
struct V_4 *
F_32 ( struct V_46 * V_6 ,
T_1 V_47 ,
void * V_48 ,
struct V_14 * V_15 )
{
return F_33 ( V_6 , - 1 , V_15 , V_47 ,
V_48 ) ;
}
int F_34 ( struct V_4 * V_5 , struct V_46 * V_6 )
{
T_2 V_49 = V_5 -> V_6 . V_50 ;
T_2 V_51 = V_5 -> V_6 . V_52 ;
int V_53 = V_5 -> V_6 . V_7 ;
int V_54 = 0 ;
if ( F_35 () && V_5 -> V_55 && V_5 -> V_55 -> V_56 == V_57 )
F_36 ( V_5 ) ;
else
F_37 ( V_5 ) ;
V_5 -> V_6 . V_50 = V_6 -> V_50 ;
V_5 -> V_6 . V_7 = V_6 -> V_7 ;
V_5 -> V_6 . V_52 = V_6 -> V_52 ;
if ( V_6 -> V_58 )
goto V_59;
V_54 = F_27 ( V_5 ) ;
if ( ! V_54 )
F_38 ( V_5 ) ;
if ( V_54 ) {
V_5 -> V_6 . V_50 = V_49 ;
V_5 -> V_6 . V_7 = V_53 ;
V_5 -> V_6 . V_52 = V_51 ;
if ( ! V_5 -> V_6 . V_58 )
F_38 ( V_5 ) ;
return V_54 ;
}
V_59:
V_5 -> V_6 . V_58 = V_6 -> V_58 ;
return 0 ;
}
void F_39 ( struct V_4 * V_5 )
{
if ( ! V_5 )
return;
F_40 ( V_5 ) ;
}
struct V_4 * T_3 *
F_41 ( struct V_46 * V_6 ,
T_1 V_47 ,
void * V_48 )
{
struct V_4 * T_3 * V_60 , * V_5 ;
long V_54 = 0 ;
int V_2 ;
V_60 = F_42 ( F_43 ( * V_60 ) ) ;
if ( ! V_60 )
return ( void T_3 V_61 * ) F_44 ( - V_36 ) ;
F_45 () ;
F_46 (cpu) {
V_5 = F_33 ( V_6 , V_2 , NULL ,
V_47 , V_48 ) ;
if ( F_47 ( V_5 ) ) {
V_54 = F_48 ( V_5 ) ;
break;
}
F_49 ( * V_60 , V_2 ) = V_5 ;
}
F_50 () ;
if ( F_51 ( ! V_54 ) )
return V_60 ;
F_52 ( V_60 ) ;
return ( void T_3 V_61 * ) F_44 ( V_54 ) ;
}
void F_52 ( struct V_4 * T_3 * V_60 )
{
int V_2 ;
F_53 (cpu)
F_39 ( F_49 ( * V_60 , V_2 ) ) ;
F_54 ( V_60 ) ;
}
static void F_55 ( struct V_4 * V_62 )
{
F_23 ( V_62 ) ;
}
static int F_56 ( struct V_4 * V_5 )
{
int V_54 ;
if ( V_5 -> V_6 . type != V_63 )
return - V_64 ;
if ( F_57 ( V_5 ) )
return - V_65 ;
V_54 = F_31 ( V_5 ) ;
if ( V_54 )
return V_54 ;
V_5 -> V_66 = F_55 ;
return 0 ;
}
static int F_58 ( struct V_4 * V_5 , int V_67 )
{
if ( ! ( V_67 & V_68 ) )
V_5 -> V_16 . V_69 = V_70 ;
if ( F_59 ( V_5 ) ) {
V_5 -> V_16 . V_71 = V_5 -> V_16 . V_72 ;
F_60 ( V_5 ) ;
}
return F_61 ( V_5 ) ;
}
static void F_62 ( struct V_4 * V_5 , int V_67 )
{
F_63 ( V_5 ) ;
}
static void F_64 ( struct V_4 * V_5 , int V_67 )
{
V_5 -> V_16 . V_69 = 0 ;
}
static void F_65 ( struct V_4 * V_5 , int V_67 )
{
V_5 -> V_16 . V_69 = V_70 ;
}
int T_4 F_66 ( void )
{
int V_2 , V_73 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_74 ; V_12 ++ )
V_13 [ V_12 ] = F_67 ( V_12 ) ;
F_53 (cpu) {
for ( V_12 = 0 ; V_12 < V_74 ; V_12 ++ ) {
struct V_1 * V_24 = F_1 ( V_2 , V_12 ) ;
V_24 -> V_11 = F_68 ( V_13 [ V_12 ] , sizeof( int ) ,
V_75 ) ;
if ( ! V_24 -> V_11 )
goto V_76;
}
}
V_35 = 1 ;
F_69 ( & V_77 , L_1 , V_63 ) ;
return F_70 ( & V_78 ) ;
V_76:
F_53 (err_cpu) {
for ( V_12 = 0 ; V_12 < V_74 ; V_12 ++ )
F_71 ( F_1 ( V_73 , V_12 ) -> V_11 ) ;
if ( V_73 == V_2 )
break;
}
return - V_36 ;
}
