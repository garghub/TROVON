static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
if ( V_4 )
F_3 () ;
F_4 ( & V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
}
static void F_6 ( void )
{
F_7 ( F_5 ) ;
}
static void F_8 ( void )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 , * V_11 ;
unsigned int V_12 ;
bool V_13 = false ;
if ( V_14 == V_15 ) {
F_9 ( V_4 ) ;
F_6 () ;
}
if ( V_4 -> V_16 )
goto V_17;
F_10 (klp_transition_patch, obj) {
F_11 (obj, func) {
V_8 -> V_18 = false ;
if ( V_8 -> V_16 )
V_13 = true ;
}
}
if ( V_14 == V_15 && ! V_13 )
F_12 ( V_4 -> V_19 ) ;
if ( V_14 == V_20 )
F_6 () ;
F_13 ( & V_21 ) ;
F_14 (g, task) {
F_15 ( F_16 ( V_11 , V_22 ) ) ;
V_11 -> V_23 = V_24 ;
}
F_17 ( & V_21 ) ;
F_18 (cpu) {
V_11 = F_19 ( V_12 ) ;
F_15 ( F_16 ( V_11 , V_22 ) ) ;
V_11 -> V_23 = V_24 ;
}
V_17:
V_14 = V_24 ;
V_4 = NULL ;
}
void F_20 ( void )
{
if ( F_15 ( V_14 != V_20 ) )
return;
V_14 = V_15 ;
F_8 () ;
}
void F_21 ( struct V_9 * V_11 )
{
F_22 () ;
if ( F_23 ( V_11 , V_22 ) )
V_11 -> V_23 = F_24 ( V_14 ) ;
F_25 () ;
}
static int F_26 ( struct V_7 * V_8 ,
struct V_25 * V_26 )
{
unsigned long V_27 , V_28 , V_29 ;
struct V_30 * V_31 ;
int V_32 ;
if ( V_8 -> V_16 )
return 0 ;
for ( V_32 = 0 ; V_32 < V_26 -> V_33 ; V_32 ++ ) {
V_29 = V_26 -> V_34 [ V_32 ] ;
if ( V_14 == V_15 ) {
V_27 = ( unsigned long ) V_8 -> V_35 ;
V_28 = V_8 -> V_36 ;
} else {
V_31 = F_27 ( V_8 -> V_37 ) ;
if ( F_28 ( & V_31 -> V_38 ) ) {
V_27 = V_8 -> V_37 ;
V_28 = V_8 -> V_39 ;
} else {
struct V_7 * V_40 ;
V_40 = F_29 ( V_8 , V_41 ) ;
V_27 = ( unsigned long ) V_40 -> V_35 ;
V_28 = V_40 -> V_36 ;
}
}
if ( V_29 >= V_27 && V_29 < V_27 + V_28 )
return - V_42 ;
}
return 0 ;
}
static int F_30 ( struct V_9 * V_11 , char * V_43 )
{
static unsigned long V_34 [ V_44 ] ;
struct V_25 V_26 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_45 ;
V_26 . V_46 = 0 ;
V_26 . V_33 = 0 ;
V_26 . V_47 = V_44 ;
V_26 . V_34 = V_34 ;
V_45 = F_31 ( V_11 , & V_26 ) ;
F_15 ( V_45 == - V_48 ) ;
if ( V_45 ) {
snprintf ( V_43 , V_49 ,
L_1 ,
V_50 , V_11 -> V_51 , V_11 -> V_52 ) ;
return V_45 ;
}
F_10 (klp_transition_patch, obj) {
if ( ! V_6 -> V_53 )
continue;
F_11 (obj, func) {
V_45 = F_26 ( V_8 , & V_26 ) ;
if ( V_45 ) {
snprintf ( V_43 , V_49 ,
L_2 ,
V_50 , V_11 -> V_51 , V_11 -> V_52 ,
V_8 -> V_54 ) ;
return V_45 ;
}
}
}
return 0 ;
}
static bool F_32 ( struct V_9 * V_11 )
{
struct V_55 * V_55 ;
struct V_56 V_57 ;
int V_45 ;
bool V_58 = false ;
char V_43 [ V_49 ] ;
V_43 [ 0 ] = '\0' ;
if ( V_11 -> V_23 == V_14 )
return true ;
if ( ! F_33 () )
return false ;
V_55 = F_34 ( V_11 , & V_57 ) ;
if ( F_35 ( V_55 , V_11 ) && V_11 != V_59 ) {
snprintf ( V_43 , V_49 ,
L_3 , V_50 , V_11 -> V_51 ,
V_11 -> V_52 ) ;
goto V_17;
}
V_45 = F_30 ( V_11 , V_43 ) ;
if ( V_45 )
goto V_17;
V_58 = true ;
F_36 ( V_11 , V_22 ) ;
V_11 -> V_23 = V_14 ;
V_17:
F_37 ( V_55 , V_11 , & V_57 ) ;
if ( V_43 [ 0 ] != '\0' )
F_38 ( L_4 , V_43 ) ;
return V_58 ;
}
void F_3 ( void )
{
unsigned int V_12 ;
struct V_9 * V_10 , * V_11 ;
bool V_60 = true ;
F_15 ( V_14 == V_24 ) ;
if ( V_4 -> V_16 )
goto V_58;
F_13 ( & V_21 ) ;
F_14 (g, task)
if ( ! F_32 ( V_11 ) )
V_60 = false ;
F_17 ( & V_21 ) ;
F_39 () ;
F_18 (cpu) {
V_11 = F_19 ( V_12 ) ;
if ( F_40 ( V_12 ) ) {
if ( ! F_32 ( V_11 ) )
V_60 = false ;
} else if ( V_11 -> V_23 != V_14 ) {
F_36 ( V_11 , V_22 ) ;
V_11 -> V_23 = V_14 ;
}
}
F_41 () ;
if ( ! V_60 ) {
F_42 ( & V_61 ,
F_43 ( V_62 ) ) ;
return;
}
V_58:
F_44 ( L_5 , V_4 -> V_19 -> V_63 ,
V_14 == V_20 ? L_6 : L_7 ) ;
F_8 () ;
}
void F_45 ( void )
{
struct V_9 * V_10 , * V_11 ;
unsigned int V_12 ;
F_15 ( V_14 == V_24 ) ;
F_44 ( L_8 , V_4 -> V_19 -> V_63 ,
V_14 == V_20 ? L_6 : L_7 ) ;
if ( V_4 -> V_16 )
return;
F_13 ( & V_21 ) ;
F_14 (g, task)
if ( V_11 -> V_23 != V_14 )
F_46 ( V_11 , V_22 ) ;
F_17 ( & V_21 ) ;
F_18 (cpu) {
V_11 = F_19 ( V_12 ) ;
if ( V_11 -> V_23 != V_14 )
F_46 ( V_11 , V_22 ) ;
}
}
void F_47 ( struct V_64 * V_65 , int V_66 )
{
struct V_9 * V_10 , * V_11 ;
unsigned int V_12 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_67 = ! V_66 ;
F_15 ( V_14 != V_24 ) ;
V_4 = V_65 ;
V_14 = V_66 ;
if ( V_65 -> V_16 )
return;
F_13 ( & V_21 ) ;
F_14 (g, task) {
F_15 ( V_11 -> V_23 != V_24 ) ;
V_11 -> V_23 = V_67 ;
}
F_17 ( & V_21 ) ;
F_18 (cpu) {
V_11 = F_19 ( V_12 ) ;
F_15 ( V_11 -> V_23 != V_24 ) ;
V_11 -> V_23 = V_67 ;
}
F_48 () ;
F_10 (patch, obj)
F_11 (obj, func)
V_8 -> V_18 = true ;
}
void F_49 ( void )
{
unsigned int V_12 ;
struct V_9 * V_10 , * V_11 ;
V_4 -> V_68 = ! V_4 -> V_68 ;
V_14 = ! V_14 ;
F_13 ( & V_21 ) ;
F_14 (g, task)
F_36 ( V_11 , V_22 ) ;
F_17 ( & V_21 ) ;
F_18 (cpu)
F_36 ( F_19 ( V_12 ) , V_22 ) ;
F_6 () ;
F_45 () ;
}
void F_50 ( struct V_9 * V_69 )
{
V_69 -> V_23 = V_59 -> V_23 ;
}
