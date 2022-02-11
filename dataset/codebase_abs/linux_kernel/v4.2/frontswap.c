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
F_8 ( & V_13 ) ;
F_9 (si, &swap_active_head, list) {
if ( V_11 -> V_14 )
F_11 ( V_11 -> type , V_9 ) ;
}
F_12 ( & V_13 ) ;
if ( F_15 ( ! F_16 ( V_7 , V_9 , V_8 ) ) ) {
for ( V_12 = 0 ; V_12 < V_8 ; V_12 ++ ) {
if ( ! F_17 ( V_12 , V_7 ) && F_17 ( V_12 , V_9 ) )
V_6 -> V_15 ( V_12 ) ;
else if ( F_17 ( V_12 , V_7 ) && ! F_17 ( V_12 , V_9 ) )
V_6 -> V_17 ( V_12 ) ;
}
}
}
void F_18 ( bool V_18 )
{
V_19 = V_18 ;
}
void F_19 ( bool V_18 )
{
V_20 = V_18 ;
}
void F_20 ( unsigned type , unsigned long * V_21 )
{
struct V_10 * V_22 = V_23 [ type ] ;
struct V_5 * V_6 ;
F_21 ( V_22 == NULL ) ;
if ( F_10 ( ! V_21 ) )
return;
F_22 ( V_22 , V_21 ) ;
F_23 (ops)
V_6 -> V_15 ( type ) ;
}
bool F_24 ( struct V_10 * V_22 ,
T_1 V_24 )
{
if ( V_22 -> V_14 )
return F_17 ( V_24 , V_22 -> V_14 ) ;
return false ;
}
static inline void F_25 ( struct V_10 * V_22 ,
T_1 V_24 )
{
F_11 ( V_24 , V_22 -> V_14 ) ;
F_26 ( & V_22 -> V_25 ) ;
}
static inline void F_27 ( struct V_10 * V_22 ,
T_1 V_24 )
{
F_28 ( V_24 , V_22 -> V_14 ) ;
F_29 ( & V_22 -> V_25 ) ;
}
int F_30 ( struct V_26 * V_26 )
{
int V_27 = - 1 ;
T_2 V_28 = { . V_29 = F_31 ( V_26 ) , } ;
int type = F_32 ( V_28 ) ;
struct V_10 * V_22 = V_23 [ type ] ;
T_1 V_24 = F_33 ( V_28 ) ;
struct V_5 * V_6 ;
if ( ! V_5 )
return - 1 ;
F_21 ( ! F_34 ( V_26 ) ) ;
F_21 ( V_22 == NULL ) ;
if ( F_24 ( V_22 , V_24 ) ) {
F_27 ( V_22 , V_24 ) ;
F_23 (ops)
V_6 -> V_30 ( type , V_24 ) ;
}
F_23 (ops) {
V_27 = V_6 -> V_31 ( type , V_24 , V_26 ) ;
if ( ! V_27 )
break;
}
if ( V_27 == 0 ) {
F_25 ( V_22 , V_24 ) ;
F_2 () ;
} else {
F_3 () ;
}
if ( V_19 )
V_27 = - 1 ;
return V_27 ;
}
int F_35 ( struct V_26 * V_26 )
{
int V_27 = - 1 ;
T_2 V_28 = { . V_29 = F_31 ( V_26 ) , } ;
int type = F_32 ( V_28 ) ;
struct V_10 * V_22 = V_23 [ type ] ;
T_1 V_24 = F_33 ( V_28 ) ;
struct V_5 * V_6 ;
if ( ! V_5 )
return - 1 ;
F_21 ( ! F_34 ( V_26 ) ) ;
F_21 ( V_22 == NULL ) ;
if ( ! F_24 ( V_22 , V_24 ) )
return - 1 ;
F_23 (ops) {
V_27 = V_6 -> V_32 ( type , V_24 , V_26 ) ;
if ( ! V_27 )
break;
}
if ( V_27 == 0 ) {
F_1 () ;
if ( V_20 ) {
F_36 ( V_26 ) ;
F_27 ( V_22 , V_24 ) ;
}
}
return V_27 ;
}
void F_37 ( unsigned type , T_1 V_24 )
{
struct V_10 * V_22 = V_23 [ type ] ;
struct V_5 * V_6 ;
if ( ! V_5 )
return;
F_21 ( V_22 == NULL ) ;
if ( ! F_24 ( V_22 , V_24 ) )
return;
F_23 (ops)
V_6 -> V_30 ( type , V_24 ) ;
F_27 ( V_22 , V_24 ) ;
F_4 () ;
}
void F_38 ( unsigned type )
{
struct V_10 * V_22 = V_23 [ type ] ;
struct V_5 * V_6 ;
if ( ! V_5 )
return;
F_21 ( V_22 == NULL ) ;
if ( V_22 -> V_14 == NULL )
return;
F_23 (ops)
V_6 -> V_17 ( type ) ;
F_39 ( & V_22 -> V_25 , 0 ) ;
F_7 ( V_22 -> V_14 , V_22 -> V_33 ) ;
}
static unsigned long F_40 ( void )
{
unsigned long V_34 = 0 ;
struct V_10 * V_11 = NULL ;
F_41 ( & V_13 ) ;
F_9 (si, &swap_active_head, list)
V_34 += F_42 ( & V_11 -> V_25 ) ;
return V_34 ;
}
static int F_43 ( unsigned long V_35 , unsigned long * V_36 ,
int * V_37 )
{
int V_27 = - V_38 ;
struct V_10 * V_11 = NULL ;
int V_39 ;
unsigned long V_40 = V_35 ;
unsigned long V_41 = 0 , V_42 = 0 ;
F_41 ( & V_13 ) ;
F_9 (si, &swap_active_head, list) {
V_39 = F_42 ( & V_11 -> V_25 ) ;
if ( V_40 < V_39 ) {
V_41 = V_42 = V_40 ;
} else {
V_41 = V_39 ;
V_42 = 0 ;
}
if ( F_44 ( V_43 -> V_44 , V_41 ) ) {
V_27 = - V_45 ;
continue;
}
F_45 ( V_41 ) ;
* V_36 = V_42 ;
* V_37 = V_11 -> type ;
V_27 = 0 ;
break;
}
return V_27 ;
}
static int F_46 ( unsigned long V_46 ,
unsigned long * V_42 ,
int * type )
{
unsigned long V_47 = 0 , V_40 ;
F_41 ( & V_13 ) ;
V_47 = F_40 () ;
if ( V_47 <= V_46 ) {
* V_42 = 0 ;
return 1 ;
}
V_40 = V_47 - V_46 ;
return F_43 ( V_40 , V_42 , type ) ;
}
void F_47 ( unsigned long V_46 )
{
unsigned long V_42 = 0 ;
int V_48 ( type ) , V_27 ;
F_8 ( & V_13 ) ;
V_27 = F_46 ( V_46 , & V_42 , & type ) ;
F_12 ( & V_13 ) ;
if ( V_27 == 0 )
F_48 ( type , true , V_42 ) ;
return;
}
unsigned long F_49 ( void )
{
unsigned long V_34 = 0 ;
F_8 ( & V_13 ) ;
V_34 = F_40 () ;
F_12 ( & V_13 ) ;
return V_34 ;
}
static int T_3 F_50 ( void )
{
#ifdef F_51
struct V_49 * V_50 = F_52 ( L_1 , NULL ) ;
if ( V_50 == NULL )
return - V_51 ;
F_53 ( L_2 , V_52 , V_50 , & V_1 ) ;
F_53 ( L_3 , V_52 , V_50 , & V_2 ) ;
F_53 ( L_4 , V_52 , V_50 ,
& V_3 ) ;
F_53 ( L_5 , V_52 ,
V_50 , & V_4 ) ;
#endif
return 0 ;
}
