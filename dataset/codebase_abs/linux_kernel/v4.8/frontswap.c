static inline void F_1 ( void ) {
V_1 ++ ;
}
static inline void F_2 ( void ) {
V_2 ++ ;
}
static inline void F_3 ( void ) {
V_3 ++ ;
}
static inline void F_4 ( void ) {
V_4 ++ ;
}
static inline void F_1 ( void ) { }
static inline void F_2 ( void ) { }
static inline void F_3 ( void ) { }
static inline void F_4 ( void ) { }
void F_5 ( struct V_5 * V_6 )
{
F_6 ( V_7 , V_8 ) ;
F_6 ( V_9 , V_8 ) ;
struct V_10 * V_11 ;
unsigned int V_12 ;
F_7 ( V_7 , V_8 ) ;
F_7 ( V_9 , V_8 ) ;
F_8 ( & V_13 ) ;
F_9 (si, &swap_active_head, list) {
if ( ! F_10 ( ! V_11 -> V_14 ) )
F_11 ( V_11 -> type , V_7 ) ;
}
F_12 ( & V_13 ) ;
F_13 (i, a, MAX_SWAPFILES)
V_6 -> V_15 ( V_12 ) ;
do {
V_6 -> V_16 = V_5 ;
} while ( F_14 ( & V_5 , V_6 -> V_16 , V_6 ) != V_6 -> V_16 );
F_15 ( & V_17 ) ;
F_8 ( & V_13 ) ;
F_9 (si, &swap_active_head, list) {
if ( V_11 -> V_14 )
F_11 ( V_11 -> type , V_9 ) ;
}
F_12 ( & V_13 ) ;
if ( F_16 ( ! F_17 ( V_7 , V_9 , V_8 ) ) ) {
for ( V_12 = 0 ; V_12 < V_8 ; V_12 ++ ) {
if ( ! F_18 ( V_12 , V_7 ) && F_18 ( V_12 , V_9 ) )
V_6 -> V_15 ( V_12 ) ;
else if ( F_18 ( V_12 , V_7 ) && ! F_18 ( V_12 , V_9 ) )
V_6 -> V_18 ( V_12 ) ;
}
}
}
void F_19 ( bool V_19 )
{
V_20 = V_19 ;
}
void F_20 ( bool V_19 )
{
V_21 = V_19 ;
}
void F_21 ( unsigned type , unsigned long * V_22 )
{
struct V_10 * V_23 = V_24 [ type ] ;
struct V_5 * V_6 ;
F_22 ( V_23 == NULL ) ;
if ( F_10 ( ! V_22 ) )
return;
F_23 ( V_23 , V_22 ) ;
F_24 (ops)
V_6 -> V_15 ( type ) ;
}
bool F_25 ( struct V_10 * V_23 ,
T_1 V_25 )
{
if ( V_23 -> V_14 )
return F_18 ( V_25 , V_23 -> V_14 ) ;
return false ;
}
static inline void F_26 ( struct V_10 * V_23 ,
T_1 V_25 )
{
F_11 ( V_25 , V_23 -> V_14 ) ;
F_27 ( & V_23 -> V_26 ) ;
}
static inline void F_28 ( struct V_10 * V_23 ,
T_1 V_25 )
{
F_29 ( V_25 , V_23 -> V_14 ) ;
F_30 ( & V_23 -> V_26 ) ;
}
int F_31 ( struct V_27 * V_27 )
{
int V_28 = - 1 ;
T_2 V_29 = { . V_30 = F_32 ( V_27 ) , } ;
int type = F_33 ( V_29 ) ;
struct V_10 * V_23 = V_24 [ type ] ;
T_1 V_25 = F_34 ( V_29 ) ;
struct V_5 * V_6 ;
F_22 ( ! V_5 ) ;
F_22 ( ! F_35 ( V_27 ) ) ;
F_22 ( V_23 == NULL ) ;
if ( F_25 ( V_23 , V_25 ) ) {
F_28 ( V_23 , V_25 ) ;
F_24 (ops)
V_6 -> V_31 ( type , V_25 ) ;
}
F_24 (ops) {
V_28 = V_6 -> V_32 ( type , V_25 , V_27 ) ;
if ( ! V_28 )
break;
}
if ( V_28 == 0 ) {
F_26 ( V_23 , V_25 ) ;
F_2 () ;
} else {
F_3 () ;
}
if ( V_20 )
V_28 = - 1 ;
return V_28 ;
}
int F_36 ( struct V_27 * V_27 )
{
int V_28 = - 1 ;
T_2 V_29 = { . V_30 = F_32 ( V_27 ) , } ;
int type = F_33 ( V_29 ) ;
struct V_10 * V_23 = V_24 [ type ] ;
T_1 V_25 = F_34 ( V_29 ) ;
struct V_5 * V_6 ;
F_22 ( ! V_5 ) ;
F_22 ( ! F_35 ( V_27 ) ) ;
F_22 ( V_23 == NULL ) ;
if ( ! F_25 ( V_23 , V_25 ) )
return - 1 ;
F_24 (ops) {
V_28 = V_6 -> V_33 ( type , V_25 , V_27 ) ;
if ( ! V_28 )
break;
}
if ( V_28 == 0 ) {
F_1 () ;
if ( V_21 ) {
F_37 ( V_27 ) ;
F_28 ( V_23 , V_25 ) ;
}
}
return V_28 ;
}
void F_38 ( unsigned type , T_1 V_25 )
{
struct V_10 * V_23 = V_24 [ type ] ;
struct V_5 * V_6 ;
F_22 ( ! V_5 ) ;
F_22 ( V_23 == NULL ) ;
if ( ! F_25 ( V_23 , V_25 ) )
return;
F_24 (ops)
V_6 -> V_31 ( type , V_25 ) ;
F_28 ( V_23 , V_25 ) ;
F_4 () ;
}
void F_39 ( unsigned type )
{
struct V_10 * V_23 = V_24 [ type ] ;
struct V_5 * V_6 ;
F_22 ( ! V_5 ) ;
F_22 ( V_23 == NULL ) ;
if ( V_23 -> V_14 == NULL )
return;
F_24 (ops)
V_6 -> V_18 ( type ) ;
F_40 ( & V_23 -> V_26 , 0 ) ;
F_7 ( V_23 -> V_14 , V_23 -> V_34 ) ;
}
static unsigned long F_41 ( void )
{
unsigned long V_35 = 0 ;
struct V_10 * V_11 = NULL ;
F_42 ( & V_13 ) ;
F_9 (si, &swap_active_head, list)
V_35 += F_43 ( & V_11 -> V_26 ) ;
return V_35 ;
}
static int F_44 ( unsigned long V_36 , unsigned long * V_37 ,
int * V_38 )
{
int V_28 = - V_39 ;
struct V_10 * V_11 = NULL ;
int V_40 ;
unsigned long V_41 = V_36 ;
unsigned long V_42 = 0 , V_43 = 0 ;
F_42 ( & V_13 ) ;
F_9 (si, &swap_active_head, list) {
V_40 = F_43 ( & V_11 -> V_26 ) ;
if ( V_41 < V_40 ) {
V_42 = V_43 = V_41 ;
} else {
V_42 = V_40 ;
V_43 = 0 ;
}
if ( F_45 ( V_44 -> V_45 , V_42 ) ) {
V_28 = - V_46 ;
continue;
}
F_46 ( V_42 ) ;
* V_37 = V_43 ;
* V_38 = V_11 -> type ;
V_28 = 0 ;
break;
}
return V_28 ;
}
static int F_47 ( unsigned long V_47 ,
unsigned long * V_43 ,
int * type )
{
unsigned long V_48 = 0 , V_41 ;
F_42 ( & V_13 ) ;
V_48 = F_41 () ;
if ( V_48 <= V_47 ) {
* V_43 = 0 ;
return 1 ;
}
V_41 = V_48 - V_47 ;
return F_44 ( V_41 , V_43 , type ) ;
}
void F_48 ( unsigned long V_47 )
{
unsigned long V_43 = 0 ;
int V_49 ( type ) , V_28 ;
F_8 ( & V_13 ) ;
V_28 = F_47 ( V_47 , & V_43 , & type ) ;
F_12 ( & V_13 ) ;
if ( V_28 == 0 )
F_49 ( type , true , V_43 ) ;
return;
}
unsigned long F_50 ( void )
{
unsigned long V_35 = 0 ;
F_8 ( & V_13 ) ;
V_35 = F_41 () ;
F_12 ( & V_13 ) ;
return V_35 ;
}
static int T_3 F_51 ( void )
{
#ifdef F_52
struct V_50 * V_51 = F_53 ( L_1 , NULL ) ;
if ( V_51 == NULL )
return - V_52 ;
F_54 ( L_2 , V_53 , V_51 , & V_1 ) ;
F_54 ( L_3 , V_53 , V_51 , & V_2 ) ;
F_54 ( L_4 , V_53 , V_51 ,
& V_3 ) ;
F_54 ( L_5 , V_53 ,
V_51 , & V_4 ) ;
#endif
return 0 ;
}
