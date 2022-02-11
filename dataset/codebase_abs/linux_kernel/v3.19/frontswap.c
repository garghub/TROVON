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
struct V_5 * F_5 ( struct V_5 * V_6 )
{
struct V_5 * V_7 = V_5 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_9 ; V_8 ++ ) {
if ( F_6 ( V_8 , V_10 ) ) {
struct V_11 * V_12 = V_13 [ V_8 ] ;
if ( ! V_12 -> V_14 )
return F_7 ( - V_15 ) ;
V_6 -> V_16 ( V_8 ) ;
}
}
F_8 () ;
V_5 = V_6 ;
return V_7 ;
}
void F_9 ( bool V_17 )
{
V_18 = V_17 ;
}
void F_10 ( bool V_17 )
{
V_19 = V_17 ;
}
void F_11 ( unsigned type , unsigned long * V_20 )
{
struct V_11 * V_12 = V_13 [ type ] ;
F_12 ( V_12 == NULL ) ;
if ( F_13 ( ! V_20 ) )
return;
F_14 ( V_12 , V_20 ) ;
if ( V_5 )
V_5 -> V_16 ( type ) ;
else {
F_12 ( type >= V_9 ) ;
F_15 ( type , V_10 ) ;
}
}
bool F_16 ( struct V_11 * V_12 ,
T_1 V_21 )
{
bool V_22 = false ;
if ( V_5 && V_12 -> V_14 )
V_22 = F_17 ( V_21 , V_12 -> V_14 ) ;
return V_22 ;
}
static inline void F_18 ( struct V_11 * V_12 ,
T_1 V_21 )
{
F_19 ( V_21 , V_12 -> V_14 ) ;
F_20 ( & V_12 -> V_23 ) ;
}
int F_21 ( struct V_24 * V_24 )
{
int V_22 = - 1 , V_25 = 0 ;
T_2 V_26 = { . V_27 = F_22 ( V_24 ) , } ;
int type = F_23 ( V_26 ) ;
struct V_11 * V_12 = V_13 [ type ] ;
T_1 V_21 = F_24 ( V_26 ) ;
if ( ! V_5 )
return V_22 ;
F_12 ( ! F_25 ( V_24 ) ) ;
F_12 ( V_12 == NULL ) ;
if ( F_16 ( V_12 , V_21 ) )
V_25 = 1 ;
V_22 = V_5 -> V_28 ( type , V_21 , V_24 ) ;
if ( V_22 == 0 ) {
F_15 ( V_21 , V_12 -> V_14 ) ;
F_2 () ;
if ( ! V_25 )
F_26 ( & V_12 -> V_23 ) ;
} else {
F_3 () ;
if ( V_25 ) {
F_18 ( V_12 , V_21 ) ;
V_5 -> V_29 ( type , V_21 ) ;
}
}
if ( V_18 )
V_22 = - 1 ;
return V_22 ;
}
int F_27 ( struct V_24 * V_24 )
{
int V_22 = - 1 ;
T_2 V_26 = { . V_27 = F_22 ( V_24 ) , } ;
int type = F_23 ( V_26 ) ;
struct V_11 * V_12 = V_13 [ type ] ;
T_1 V_21 = F_24 ( V_26 ) ;
F_12 ( ! F_25 ( V_24 ) ) ;
F_12 ( V_12 == NULL ) ;
if ( F_16 ( V_12 , V_21 ) )
V_22 = V_5 -> V_30 ( type , V_21 , V_24 ) ;
if ( V_22 == 0 ) {
F_1 () ;
if ( V_19 ) {
F_28 ( V_24 ) ;
F_18 ( V_12 , V_21 ) ;
}
}
return V_22 ;
}
void F_29 ( unsigned type , T_1 V_21 )
{
struct V_11 * V_12 = V_13 [ type ] ;
F_12 ( V_12 == NULL ) ;
if ( F_16 ( V_12 , V_21 ) ) {
V_5 -> V_29 ( type , V_21 ) ;
F_18 ( V_12 , V_21 ) ;
F_4 () ;
}
}
void F_30 ( unsigned type )
{
struct V_11 * V_12 = V_13 [ type ] ;
if ( V_5 ) {
F_12 ( V_12 == NULL ) ;
if ( V_12 -> V_14 == NULL )
return;
V_5 -> V_31 ( type ) ;
F_31 ( & V_12 -> V_23 , 0 ) ;
F_32 ( V_12 -> V_14 , V_12 -> V_32 ) ;
}
F_19 ( type , V_10 ) ;
}
static unsigned long F_33 ( void )
{
unsigned long V_33 = 0 ;
struct V_11 * V_34 = NULL ;
F_34 ( & V_35 ) ;
F_35 (si, &swap_active_head, list)
V_33 += F_36 ( & V_34 -> V_23 ) ;
return V_33 ;
}
static int F_37 ( unsigned long V_36 , unsigned long * V_37 ,
int * V_38 )
{
int V_22 = - V_15 ;
struct V_11 * V_34 = NULL ;
int V_39 ;
unsigned long V_40 = V_36 ;
unsigned long V_41 = 0 , V_42 = 0 ;
F_34 ( & V_35 ) ;
F_35 (si, &swap_active_head, list) {
V_39 = F_36 ( & V_34 -> V_23 ) ;
if ( V_40 < V_39 ) {
V_41 = V_42 = V_40 ;
} else {
V_41 = V_39 ;
V_42 = 0 ;
}
if ( F_38 ( V_43 -> V_44 , V_41 ) ) {
V_22 = - V_45 ;
continue;
}
F_39 ( V_41 ) ;
* V_37 = V_42 ;
* V_38 = V_34 -> type ;
V_22 = 0 ;
break;
}
return V_22 ;
}
static int F_40 ( unsigned long V_46 ,
unsigned long * V_42 ,
int * type )
{
unsigned long V_47 = 0 , V_40 ;
F_34 ( & V_35 ) ;
V_47 = F_33 () ;
if ( V_47 <= V_46 ) {
* V_42 = 0 ;
return 1 ;
}
V_40 = V_47 - V_46 ;
return F_37 ( V_40 , V_42 , type ) ;
}
void F_41 ( unsigned long V_46 )
{
unsigned long V_42 = 0 ;
int V_48 ( type ) , V_22 ;
F_42 ( & V_35 ) ;
V_22 = F_40 ( V_46 , & V_42 , & type ) ;
F_43 ( & V_35 ) ;
if ( V_22 == 0 )
F_44 ( type , true , V_42 ) ;
return;
}
unsigned long F_45 ( void )
{
unsigned long V_33 = 0 ;
F_42 ( & V_35 ) ;
V_33 = F_33 () ;
F_43 ( & V_35 ) ;
return V_33 ;
}
static int T_3 F_46 ( void )
{
#ifdef F_47
struct V_49 * V_50 = F_48 ( L_1 , NULL ) ;
if ( V_50 == NULL )
return - V_51 ;
F_49 ( L_2 , V_52 , V_50 , & V_1 ) ;
F_49 ( L_3 , V_52 , V_50 , & V_2 ) ;
F_49 ( L_4 , V_52 , V_50 ,
& V_3 ) ;
F_49 ( L_5 , V_52 ,
V_50 , & V_4 ) ;
#endif
return 0 ;
}
