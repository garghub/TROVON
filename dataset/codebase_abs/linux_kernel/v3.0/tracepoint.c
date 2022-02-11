static inline void * F_1 ( int V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 * sizeof( struct V_4 )
+ sizeof( struct V_2 ) , V_5 ) ;
return V_3 == NULL ? NULL : V_3 -> V_6 ;
}
static void F_3 ( struct V_7 * V_8 )
{
F_4 ( F_5 ( V_8 , struct V_2 , V_9 . V_10 ) ) ;
}
static inline void F_6 ( struct V_4 * V_11 )
{
if ( V_11 ) {
struct V_2 * V_2 = F_5 ( V_11 ,
struct V_2 , V_6 [ 0 ] ) ;
F_7 ( & V_2 -> V_9 . V_10 , F_3 ) ;
}
}
static void F_8 ( struct V_12 * V_13 )
{
int V_14 ;
if ( ! V_15 || ! V_13 -> V_16 )
return;
for ( V_14 = 0 ; V_13 -> V_16 [ V_14 ] . V_17 ; V_14 ++ )
F_9 ( V_18 L_1 , V_14 , V_13 -> V_16 [ V_14 ] . V_17 ) ;
}
static struct V_4 *
F_10 ( struct V_12 * V_13 ,
void * V_19 , void * V_20 )
{
int V_21 = 0 ;
struct V_4 * V_11 , * V_22 ;
F_11 ( ! V_19 ) ;
F_8 ( V_13 ) ;
V_11 = V_13 -> V_16 ;
if ( V_11 ) {
for ( V_21 = 0 ; V_11 [ V_21 ] . V_17 ; V_21 ++ )
if ( V_11 [ V_21 ] . V_17 == V_19 &&
V_11 [ V_21 ] . V_20 == V_20 )
return F_12 ( - V_23 ) ;
}
V_22 = F_1 ( V_21 + 2 ) ;
if ( V_22 == NULL )
return F_12 ( - V_24 ) ;
if ( V_11 )
memcpy ( V_22 , V_11 , V_21 * sizeof( struct V_4 ) ) ;
V_22 [ V_21 ] . V_17 = V_19 ;
V_22 [ V_21 ] . V_20 = V_20 ;
V_22 [ V_21 + 1 ] . V_17 = NULL ;
V_13 -> V_25 = V_21 + 1 ;
V_13 -> V_16 = V_22 ;
F_8 ( V_13 ) ;
return V_11 ;
}
static void *
F_13 ( struct V_12 * V_13 ,
void * V_19 , void * V_20 )
{
int V_21 = 0 , V_26 = 0 , V_14 ;
struct V_4 * V_11 , * V_22 ;
V_11 = V_13 -> V_16 ;
if ( ! V_11 )
return F_12 ( - V_27 ) ;
F_8 ( V_13 ) ;
for ( V_21 = 0 ; V_11 [ V_21 ] . V_17 ; V_21 ++ ) {
if ( ! V_19 ||
( V_11 [ V_21 ] . V_17 == V_19 &&
V_11 [ V_21 ] . V_20 == V_20 ) )
V_26 ++ ;
}
if ( V_21 - V_26 == 0 ) {
V_13 -> V_16 = NULL ;
V_13 -> V_25 = 0 ;
F_8 ( V_13 ) ;
return V_11 ;
} else {
int V_28 = 0 ;
V_22 = F_1 ( V_21 - V_26 + 1 ) ;
if ( V_22 == NULL )
return F_12 ( - V_24 ) ;
for ( V_14 = 0 ; V_11 [ V_14 ] . V_17 ; V_14 ++ )
if ( V_19 &&
( V_11 [ V_14 ] . V_17 != V_19 || V_11 [ V_14 ] . V_20 != V_20 ) )
V_22 [ V_28 ++ ] = V_11 [ V_14 ] ;
V_22 [ V_21 - V_26 ] . V_17 = NULL ;
V_13 -> V_25 = V_21 - V_26 ;
V_13 -> V_16 = V_22 ;
}
F_8 ( V_13 ) ;
return V_11 ;
}
static struct V_12 * F_14 ( const char * V_29 )
{
struct V_30 * V_8 ;
struct V_31 * V_32 ;
struct V_12 * V_33 ;
T_1 V_34 = F_15 ( V_29 , strlen ( V_29 ) , 0 ) ;
V_8 = & V_35 [ V_34 & ( V_36 - 1 ) ] ;
F_16 (e, node, head, hlist) {
if ( ! strcmp ( V_29 , V_33 -> V_29 ) )
return V_33 ;
}
return NULL ;
}
static struct V_12 * F_17 ( const char * V_29 )
{
struct V_30 * V_8 ;
struct V_31 * V_32 ;
struct V_12 * V_33 ;
T_2 V_37 = strlen ( V_29 ) + 1 ;
T_1 V_34 = F_15 ( V_29 , V_37 - 1 , 0 ) ;
V_8 = & V_35 [ V_34 & ( V_36 - 1 ) ] ;
F_16 (e, node, head, hlist) {
if ( ! strcmp ( V_29 , V_33 -> V_29 ) ) {
F_9 ( V_38
L_2 , V_29 ) ;
return F_12 ( - V_23 ) ;
}
}
V_33 = F_2 ( sizeof( struct V_12 ) + V_37 , V_5 ) ;
if ( ! V_33 )
return F_12 ( - V_24 ) ;
memcpy ( & V_33 -> V_29 [ 0 ] , V_29 , V_37 ) ;
V_33 -> V_16 = NULL ;
V_33 -> V_25 = 0 ;
F_18 ( & V_33 -> V_39 , V_8 ) ;
return V_33 ;
}
static inline void F_19 ( struct V_12 * V_33 )
{
F_20 ( & V_33 -> V_39 ) ;
F_4 ( V_33 ) ;
}
static void F_21 ( struct V_12 * * V_13 ,
struct V_40 * V_41 , int V_42 )
{
F_11 ( strcmp ( ( * V_13 ) -> V_29 , V_41 -> V_29 ) != 0 ) ;
if ( V_41 -> V_43 && ! F_22 ( & V_41 -> V_44 ) && V_42 )
V_41 -> V_43 () ;
else if ( V_41 -> V_45 && F_22 ( & V_41 -> V_44 ) && ! V_42 )
V_41 -> V_45 () ;
F_23 ( V_41 -> V_16 , ( * V_13 ) -> V_16 ) ;
if ( V_42 && ! F_22 ( & V_41 -> V_44 ) )
F_24 ( & V_41 -> V_44 ) ;
else if ( ! V_42 && F_22 ( & V_41 -> V_44 ) )
F_25 ( & V_41 -> V_44 ) ;
}
static void F_26 ( struct V_40 * V_41 )
{
if ( V_41 -> V_45 && F_22 ( & V_41 -> V_44 ) )
V_41 -> V_45 () ;
if ( F_22 ( & V_41 -> V_44 ) )
F_25 ( & V_41 -> V_44 ) ;
F_23 ( V_41 -> V_16 , NULL ) ;
}
void F_27 ( struct V_40 * const * V_46 ,
struct V_40 * const * V_47 )
{
struct V_40 * const * V_48 ;
struct V_12 * V_49 ;
if ( ! V_46 )
return;
F_28 ( & V_50 ) ;
for ( V_48 = V_46 ; V_48 < V_47 ; V_48 ++ ) {
V_49 = F_14 ( ( * V_48 ) -> V_29 ) ;
if ( V_49 ) {
F_21 ( & V_49 , * V_48 ,
! ! V_49 -> V_25 ) ;
} else {
F_26 ( * V_48 ) ;
}
}
F_29 ( & V_50 ) ;
}
static void F_30 ( void )
{
F_27 ( V_51 ,
V_52 ) ;
F_31 () ;
}
static struct V_4 *
F_32 ( const char * V_29 , void * V_19 , void * V_20 )
{
struct V_12 * V_13 ;
struct V_4 * V_11 ;
V_13 = F_14 ( V_29 ) ;
if ( ! V_13 ) {
V_13 = F_17 ( V_29 ) ;
if ( F_33 ( V_13 ) )
return (struct V_4 * ) V_13 ;
}
V_11 = F_10 ( V_13 , V_19 , V_20 ) ;
if ( F_33 ( V_11 ) && ! V_13 -> V_25 )
F_19 ( V_13 ) ;
return V_11 ;
}
int F_34 ( const char * V_29 , void * V_19 , void * V_20 )
{
struct V_4 * V_11 ;
F_28 ( & V_50 ) ;
V_11 = F_32 ( V_29 , V_19 , V_20 ) ;
F_29 ( & V_50 ) ;
if ( F_33 ( V_11 ) )
return F_35 ( V_11 ) ;
F_30 () ;
F_6 ( V_11 ) ;
return 0 ;
}
static struct V_4 *
F_36 ( const char * V_29 , void * V_19 , void * V_20 )
{
struct V_12 * V_13 ;
struct V_4 * V_11 ;
V_13 = F_14 ( V_29 ) ;
if ( ! V_13 )
return F_12 ( - V_27 ) ;
V_11 = F_13 ( V_13 , V_19 , V_20 ) ;
if ( F_33 ( V_11 ) )
return V_11 ;
if ( ! V_13 -> V_25 )
F_19 ( V_13 ) ;
return V_11 ;
}
int F_37 ( const char * V_29 , void * V_19 , void * V_20 )
{
struct V_4 * V_11 ;
F_28 ( & V_50 ) ;
V_11 = F_36 ( V_29 , V_19 , V_20 ) ;
F_29 ( & V_50 ) ;
if ( F_33 ( V_11 ) )
return F_35 ( V_11 ) ;
F_30 () ;
F_6 ( V_11 ) ;
return 0 ;
}
static void F_38 ( void * V_11 )
{
V_53 = 1 ;
if ( V_11 ) {
struct V_2 * V_2 = F_5 ( V_11 ,
struct V_2 , V_6 [ 0 ] ) ;
F_39 ( & V_2 -> V_9 . V_54 , & V_55 ) ;
}
}
int F_40 ( const char * V_29 , void * V_19 ,
void * V_20 )
{
struct V_4 * V_11 ;
F_28 ( & V_50 ) ;
V_11 = F_32 ( V_29 , V_19 , V_20 ) ;
if ( F_33 ( V_11 ) ) {
F_29 ( & V_50 ) ;
return F_35 ( V_11 ) ;
}
F_38 ( V_11 ) ;
F_29 ( & V_50 ) ;
return 0 ;
}
int F_41 ( const char * V_29 , void * V_19 ,
void * V_20 )
{
struct V_4 * V_11 ;
F_28 ( & V_50 ) ;
V_11 = F_36 ( V_29 , V_19 , V_20 ) ;
if ( F_33 ( V_11 ) ) {
F_29 ( & V_50 ) ;
return F_35 ( V_11 ) ;
}
F_38 ( V_11 ) ;
F_29 ( & V_50 ) ;
return 0 ;
}
void F_42 ( void )
{
F_43 ( F_6 ) ;
struct V_2 * V_56 , * V_57 ;
F_28 ( & V_50 ) ;
if ( ! V_53 ) {
F_29 ( & V_50 ) ;
return;
}
if ( ! F_44 ( & V_55 ) )
F_45 ( & V_55 , & F_6 ) ;
V_53 = 0 ;
F_29 ( & V_50 ) ;
F_30 () ;
F_46 (pos, next, &release_probes, u.list) {
F_47 ( & V_56 -> V_9 . V_54 ) ;
F_7 ( & V_56 -> V_9 . V_10 , F_3 ) ;
}
}
int F_48 ( struct V_40 * const * * V_40 ,
struct V_40 * const * V_46 , struct V_40 * const * V_47 )
{
if ( ! * V_40 && V_46 != V_47 ) {
* V_40 = V_46 ;
return 1 ;
}
if ( * V_40 >= V_46 && * V_40 < V_47 )
return 1 ;
return 0 ;
}
static void F_49 ( struct V_58 * V_48 )
{
int V_59 = 0 ;
if ( ! V_48 -> V_60 ) {
V_59 = F_48 ( & V_48 -> V_40 ,
V_51 ,
V_52 ) ;
if ( V_59 )
goto V_47;
}
V_59 = F_50 ( V_48 ) ;
V_47:
if ( ! V_59 )
F_51 ( V_48 ) ;
}
void F_52 ( struct V_58 * V_48 )
{
F_49 ( V_48 ) ;
}
void F_53 ( struct V_58 * V_48 )
{
V_48 -> V_40 ++ ;
F_49 ( V_48 ) ;
}
void F_54 ( struct V_58 * V_48 )
{
}
void F_51 ( struct V_58 * V_48 )
{
V_48 -> V_60 = NULL ;
V_48 -> V_40 = NULL ;
}
int F_55 ( struct V_61 * V_62 ,
unsigned long V_63 , void * V_20 )
{
struct V_60 * V_64 = V_20 ;
switch ( V_63 ) {
case V_65 :
case V_66 :
F_27 ( V_64 -> V_67 ,
V_64 -> V_67 + V_64 -> V_68 ) ;
break;
}
return 0 ;
}
static int F_56 ( void )
{
return F_57 ( & V_69 ) ;
}
void F_58 ( void )
{
unsigned long V_70 ;
struct V_71 * V_72 , * V_73 ;
if ( ! V_74 ) {
F_59 ( & V_75 , V_70 ) ;
F_60 (g, t) {
if ( V_73 -> V_76 )
F_61 ( V_73 , V_77 ) ;
} F_62 ( V_72 , V_73 ) ;
F_63 ( & V_75 , V_70 ) ;
}
V_74 ++ ;
}
void F_64 ( void )
{
unsigned long V_70 ;
struct V_71 * V_72 , * V_73 ;
V_74 -- ;
if ( ! V_74 ) {
F_59 ( & V_75 , V_70 ) ;
F_60 (g, t) {
F_65 ( V_73 , V_77 ) ;
} F_62 ( V_72 , V_73 ) ;
F_63 ( & V_75 , V_70 ) ;
}
}
