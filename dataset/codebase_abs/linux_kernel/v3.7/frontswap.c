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
struct V_5 F_5 ( struct V_5 * V_6 )
{
struct V_5 V_7 = V_5 ;
V_5 = * V_6 ;
V_8 = true ;
return V_7 ;
}
void F_6 ( bool V_9 )
{
V_10 = V_9 ;
}
void F_7 ( bool V_9 )
{
V_11 = V_9 ;
}
void F_8 ( unsigned type )
{
struct V_12 * V_13 = V_14 [ type ] ;
F_9 ( V_13 == NULL ) ;
if ( V_13 -> V_15 == NULL )
return;
V_5 . V_16 ( type ) ;
}
static inline void F_10 ( struct V_12 * V_13 , T_1 V_17 )
{
F_11 ( V_13 , V_17 ) ;
F_12 ( & V_13 -> V_18 ) ;
}
int F_13 ( struct V_19 * V_19 )
{
int V_20 = - 1 , V_21 = 0 ;
T_2 V_22 = { . V_23 = F_14 ( V_19 ) , } ;
int type = F_15 ( V_22 ) ;
struct V_12 * V_13 = V_14 [ type ] ;
T_1 V_17 = F_16 ( V_22 ) ;
F_9 ( ! F_17 ( V_19 ) ) ;
F_9 ( V_13 == NULL ) ;
if ( F_18 ( V_13 , V_17 ) )
V_21 = 1 ;
V_20 = V_5 . V_24 ( type , V_17 , V_19 ) ;
if ( V_20 == 0 ) {
F_19 ( V_13 , V_17 ) ;
F_2 () ;
if ( ! V_21 )
F_20 ( & V_13 -> V_18 ) ;
} else {
F_3 () ;
if ( V_21 )
F_10 ( V_13 , V_17 ) ;
}
if ( V_10 )
V_20 = - 1 ;
return V_20 ;
}
int F_21 ( struct V_19 * V_19 )
{
int V_20 = - 1 ;
T_2 V_22 = { . V_23 = F_14 ( V_19 ) , } ;
int type = F_15 ( V_22 ) ;
struct V_12 * V_13 = V_14 [ type ] ;
T_1 V_17 = F_16 ( V_22 ) ;
F_9 ( ! F_17 ( V_19 ) ) ;
F_9 ( V_13 == NULL ) ;
if ( F_18 ( V_13 , V_17 ) )
V_20 = V_5 . V_25 ( type , V_17 , V_19 ) ;
if ( V_20 == 0 ) {
F_1 () ;
if ( V_11 ) {
F_22 ( V_19 ) ;
F_11 ( V_13 , V_17 ) ;
}
}
return V_20 ;
}
void F_23 ( unsigned type , T_1 V_17 )
{
struct V_12 * V_13 = V_14 [ type ] ;
F_9 ( V_13 == NULL ) ;
if ( F_18 ( V_13 , V_17 ) ) {
V_5 . V_26 ( type , V_17 ) ;
F_10 ( V_13 , V_17 ) ;
F_4 () ;
}
}
void F_24 ( unsigned type )
{
struct V_12 * V_13 = V_14 [ type ] ;
F_9 ( V_13 == NULL ) ;
if ( V_13 -> V_15 == NULL )
return;
V_5 . V_27 ( type ) ;
F_25 ( & V_13 -> V_18 , 0 ) ;
memset ( V_13 -> V_15 , 0 , V_13 -> V_28 / sizeof( long ) ) ;
}
static unsigned long F_26 ( void )
{
int type ;
unsigned long V_29 = 0 ;
struct V_12 * V_30 = NULL ;
F_27 ( & V_31 ) ;
for ( type = V_32 . V_33 ; type >= 0 ; type = V_30 -> V_34 ) {
V_30 = V_14 [ type ] ;
V_29 += F_28 ( & V_30 -> V_18 ) ;
}
return V_29 ;
}
static int F_29 ( unsigned long V_35 , unsigned long * V_36 ,
int * V_37 )
{
int V_20 = - V_38 ;
struct V_12 * V_30 = NULL ;
int V_39 ;
unsigned long V_40 = V_35 ;
unsigned long V_41 = 0 , V_42 = 0 ;
int type ;
F_27 ( & V_31 ) ;
for ( type = V_32 . V_33 ; type >= 0 ; type = V_30 -> V_34 ) {
V_30 = V_14 [ type ] ;
V_39 = F_28 ( & V_30 -> V_18 ) ;
if ( V_40 < V_39 ) {
V_41 = V_42 = V_40 ;
} else {
V_41 = V_39 ;
V_42 = 0 ;
}
if ( F_30 ( V_43 -> V_44 , V_41 ) ) {
V_20 = - V_45 ;
continue;
}
F_31 ( V_41 ) ;
* V_36 = V_42 ;
* V_37 = type ;
V_20 = 0 ;
break;
}
return V_20 ;
}
static int F_32 ( unsigned long V_46 ,
unsigned long * V_42 ,
int * type )
{
unsigned long V_47 = 0 , V_40 ;
F_27 ( & V_31 ) ;
V_47 = F_26 () ;
if ( V_47 <= V_46 ) {
* V_42 = 0 ;
return 1 ;
}
V_40 = V_47 - V_46 ;
return F_29 ( V_40 , V_42 , type ) ;
}
void F_33 ( unsigned long V_46 )
{
unsigned long V_42 = 0 ;
int V_48 ( type ) , V_20 ;
F_34 ( & V_31 ) ;
V_20 = F_32 ( V_46 , & V_42 , & type ) ;
F_35 ( & V_31 ) ;
if ( V_20 == 0 )
F_36 ( type , true , V_42 ) ;
return;
}
unsigned long F_37 ( void )
{
unsigned long V_29 = 0 ;
F_34 ( & V_31 ) ;
V_29 = F_26 () ;
F_35 ( & V_31 ) ;
return V_29 ;
}
static int T_3 F_38 ( void )
{
#ifdef F_39
struct V_49 * V_50 = F_40 ( L_1 , NULL ) ;
if ( V_50 == NULL )
return - V_51 ;
F_41 ( L_2 , V_52 , V_50 , & V_1 ) ;
F_41 ( L_3 , V_52 , V_50 , & V_2 ) ;
F_41 ( L_4 , V_52 , V_50 ,
& V_3 ) ;
F_41 ( L_5 , V_52 ,
V_50 , & V_4 ) ;
#endif
return 0 ;
}
