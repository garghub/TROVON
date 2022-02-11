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
void F_7 ( unsigned type )
{
struct V_11 * V_12 = V_13 [ type ] ;
F_8 ( V_12 == NULL ) ;
if ( V_12 -> V_14 == NULL )
return;
V_5 . V_15 ( type ) ;
}
static inline void F_9 ( struct V_11 * V_12 , T_1 V_16 )
{
F_10 ( V_12 , V_16 ) ;
F_11 ( & V_12 -> V_17 ) ;
}
int F_12 ( struct V_18 * V_18 )
{
int V_19 = - 1 , V_20 = 0 ;
T_2 V_21 = { . V_22 = F_13 ( V_18 ) , } ;
int type = F_14 ( V_21 ) ;
struct V_11 * V_12 = V_13 [ type ] ;
T_1 V_16 = F_15 ( V_21 ) ;
F_8 ( ! F_16 ( V_18 ) ) ;
F_8 ( V_12 == NULL ) ;
if ( F_17 ( V_12 , V_16 ) )
V_20 = 1 ;
V_19 = V_5 . V_23 ( type , V_16 , V_18 ) ;
if ( V_19 == 0 ) {
F_18 ( V_12 , V_16 ) ;
F_2 () ;
if ( ! V_20 )
F_19 ( & V_12 -> V_17 ) ;
} else {
F_3 () ;
if ( V_20 )
F_9 ( V_12 , V_16 ) ;
}
if ( V_10 )
V_19 = - 1 ;
return V_19 ;
}
int F_20 ( struct V_18 * V_18 )
{
int V_19 = - 1 ;
T_2 V_21 = { . V_22 = F_13 ( V_18 ) , } ;
int type = F_14 ( V_21 ) ;
struct V_11 * V_12 = V_13 [ type ] ;
T_1 V_16 = F_15 ( V_21 ) ;
F_8 ( ! F_16 ( V_18 ) ) ;
F_8 ( V_12 == NULL ) ;
if ( F_17 ( V_12 , V_16 ) )
V_19 = V_5 . V_24 ( type , V_16 , V_18 ) ;
if ( V_19 == 0 )
F_1 () ;
return V_19 ;
}
void F_21 ( unsigned type , T_1 V_16 )
{
struct V_11 * V_12 = V_13 [ type ] ;
F_8 ( V_12 == NULL ) ;
if ( F_17 ( V_12 , V_16 ) ) {
V_5 . V_25 ( type , V_16 ) ;
F_9 ( V_12 , V_16 ) ;
F_4 () ;
}
}
void F_22 ( unsigned type )
{
struct V_11 * V_12 = V_13 [ type ] ;
F_8 ( V_12 == NULL ) ;
if ( V_12 -> V_14 == NULL )
return;
V_5 . V_26 ( type ) ;
F_23 ( & V_12 -> V_17 , 0 ) ;
memset ( V_12 -> V_14 , 0 , V_12 -> V_27 / sizeof( long ) ) ;
}
static unsigned long F_24 ( void )
{
int type ;
unsigned long V_28 = 0 ;
struct V_11 * V_29 = NULL ;
F_25 ( & V_30 ) ;
for ( type = V_31 . V_32 ; type >= 0 ; type = V_29 -> V_33 ) {
V_29 = V_13 [ type ] ;
V_28 += F_26 ( & V_29 -> V_17 ) ;
}
return V_28 ;
}
static int F_27 ( unsigned long V_34 , unsigned long * V_35 ,
int * V_36 )
{
int V_19 = - V_37 ;
struct V_11 * V_29 = NULL ;
int V_38 ;
unsigned long V_39 = V_34 ;
unsigned long V_40 = 0 , V_41 = 0 ;
int type ;
F_25 ( & V_30 ) ;
for ( type = V_31 . V_32 ; type >= 0 ; type = V_29 -> V_33 ) {
V_29 = V_13 [ type ] ;
V_38 = F_26 ( & V_29 -> V_17 ) ;
if ( V_39 < V_38 ) {
V_40 = V_41 = V_39 ;
} else {
V_40 = V_38 ;
V_41 = 0 ;
}
if ( F_28 ( V_42 -> V_43 , V_40 ) ) {
V_19 = - V_44 ;
continue;
}
F_29 ( V_40 ) ;
* V_35 = V_41 ;
* V_36 = type ;
V_19 = 0 ;
break;
}
return V_19 ;
}
static int F_30 ( unsigned long V_45 ,
unsigned long * V_41 ,
int * type )
{
unsigned long V_46 = 0 , V_39 ;
F_25 ( & V_30 ) ;
V_46 = F_24 () ;
if ( V_46 <= V_45 ) {
* V_41 = 0 ;
return 0 ;
}
V_39 = V_46 - V_45 ;
return F_27 ( V_39 , V_41 , type ) ;
}
void F_31 ( unsigned long V_45 )
{
unsigned long V_41 = 0 ;
int type , V_19 ;
F_32 ( & V_30 ) ;
V_19 = F_30 ( V_45 , & V_41 , & type ) ;
F_33 ( & V_30 ) ;
if ( V_19 == 0 && V_41 )
F_34 ( type , true , V_41 ) ;
return;
}
unsigned long F_35 ( void )
{
unsigned long V_28 = 0 ;
F_32 ( & V_30 ) ;
V_28 = F_24 () ;
F_33 ( & V_30 ) ;
return V_28 ;
}
static int T_3 F_36 ( void )
{
#ifdef F_37
struct V_47 * V_48 = F_38 ( L_1 , NULL ) ;
if ( V_48 == NULL )
return - V_49 ;
F_39 ( L_2 , V_50 , V_48 , & V_1 ) ;
F_39 ( L_3 , V_50 , V_48 , & V_2 ) ;
F_39 ( L_4 , V_50 , V_48 ,
& V_3 ) ;
F_39 ( L_5 , V_50 ,
V_48 , & V_4 ) ;
#endif
return 0 ;
}
