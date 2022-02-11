static T_1 * F_1 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_2 ; V_1 ++ )
if ( ! F_2 ( & V_3 [ V_1 ] . V_4 ) ) {
F_3 ( & V_3 [ V_1 ] . V_4 , 1 ) ;
return & V_3 [ V_1 ] . V_5 ;
}
F_4 ( & V_3 [ V_6 ] . V_4 ) ;
return & V_3 [ V_6 ] . V_5 ;
}
static void F_5 ( T_1 * V_7 )
{
int V_1 ;
if ( ! V_7 )
return;
V_1 = ( ( unsigned long ) V_7 - ( unsigned long ) V_3 ) /
sizeof( struct V_8 ) ;
F_6 ( & V_3 [ V_1 ] . V_4 ) ;
}
void F_7 ( struct V_9 * V_10 )
{
F_8 ( & V_11 ) ;
F_9 ( V_10 -> V_12 < 1 ) ;
F_10 ( & V_10 -> V_13 [ 0 ] -> V_14 , & V_15 ) ;
F_11 ( & V_11 ) ;
F_12 ( V_10 -> V_16 , 1 << 7 ) ;
}
void F_13 ( struct V_9 * V_10 )
{
struct V_17 * V_18 ;
F_9 ( V_10 -> V_12 < 1 ) ;
V_18 = V_10 -> V_13 [ 0 ] ;
if ( ! V_18 || ! V_18 -> V_14 . V_19 || ! V_18 -> V_14 . V_20 )
return;
F_8 ( & V_11 ) ;
F_14 ( & V_18 -> V_14 ) ;
F_11 ( & V_11 ) ;
F_15 () ;
}
static inline int F_16 ( struct V_9 * V_10 )
{
return V_10 -> V_12 > 1 ;
}
static inline int F_17 ( struct V_9 * V_10 )
{
return V_10 -> V_16 == & V_3 [ V_6 ] . V_5 ;
}
static inline int F_18 ( struct V_9 * V_10 )
{
return F_17 ( V_10 ) ||
F_16 ( V_10 ) ;
}
void F_19 ( struct V_9 * V_10 )
{
if ( ! F_20 ( V_10 ) )
return;
if ( F_18 ( V_10 ) )
return;
F_12 ( V_10 -> V_16 , 0 ) ;
}
int F_21 ( struct V_9 * V_10 )
{
if ( ! F_20 ( V_10 ) )
return 0 ;
if ( F_18 ( V_10 ) )
return 0 ;
if ( * V_10 -> V_16 )
return 1 ;
else
return 0 ;
}
static inline T_1 F_22 ( void )
{
if ( ! F_2 ( & V_3 [ V_6 ] . V_4 ) )
return 0 ;
return F_12 ( & V_3 [ V_6 ] . V_5 , 0 ) ;
}
static inline void F_23 ( struct V_9 * V_21 )
{
struct V_17 * V_18 ;
int V_1 ;
F_24 (irq, q, i) {
if ( ! F_17 ( V_21 ) &&
F_16 ( V_21 ) )
F_12 ( V_18 -> V_10 -> V_16 , 0 ) ;
if ( V_18 -> V_22 . V_23 . V_24 ) {
if ( F_25 ( V_25 ,
& V_18 -> V_22 . V_23 . V_26 ) ) {
F_26 ( V_18 , V_27 ) ;
continue;
}
V_18 -> V_22 . V_23 . V_24 ( V_18 -> V_10 -> V_28 , V_18 -> V_29 ,
V_18 -> V_10 -> V_30 ) ;
} else {
if ( ! F_18 ( V_18 -> V_10 ) )
F_12 ( V_18 -> V_10 -> V_16 , 0 ) ;
F_27 ( & V_18 -> V_31 ) ;
}
}
}
static void F_28 ( void * V_32 , void * V_33 )
{
T_1 V_34 = F_22 () ;
struct V_17 * V_18 ;
V_35 = V_36 . V_37 ;
F_29 ( F_30 () ) . V_38 [ V_39 ] ++ ;
F_31 () ;
F_32 (q, &tiq_list, entry) {
struct V_9 * V_21 ;
V_21 = V_18 -> V_10 ;
if ( F_33 ( F_17 ( V_21 ) ) ) {
if ( ! V_34 )
continue;
} else if ( ! * V_21 -> V_16 )
continue;
F_23 ( V_21 ) ;
F_26 ( V_18 , V_40 ) ;
}
F_34 () ;
}
static int F_35 ( struct V_9 * V_10 , int V_41 )
{
struct V_42 * V_42 ;
int V_43 ;
V_42 = (struct V_42 * ) V_10 -> V_44 ;
memset ( V_42 , 0 , V_45 ) ;
if ( V_41 ) {
V_42 -> V_46 = 0 ;
V_42 -> V_47 = 0 ;
} else {
V_42 -> V_46 = F_36 ( V_48 ) ;
V_42 -> V_47 =
F_36 ( V_10 -> V_16 ) ;
}
V_42 -> V_49 = (struct V_50 ) {
. V_51 = 0x0fe0 ,
. V_52 = 0x0021 ,
} ;
V_42 -> V_53 = 0 ;
V_42 -> V_54 = V_55 >> 4 ;
V_42 -> V_56 = V_55 >> 4 ;
V_42 -> V_57 = V_58 ;
V_42 -> V_59 = V_10 -> V_59 ;
if ( V_60 . V_61 )
V_42 -> V_62 = 0x10000000 ;
V_43 = F_37 ( V_42 ) ;
if ( V_43 )
return - V_63 ;
V_43 = F_38 ( V_42 -> V_64 . V_52 ) ;
if ( V_43 ) {
F_39 ( L_1 , V_10 -> V_59 . V_65 ,
V_42 -> V_64 . V_52 ) ;
F_40 ( & V_42 -> V_64 , sizeof( void * ) ) ;
return V_43 ;
}
F_41 ( L_2 ) ;
F_42 ( & V_42 -> V_46 , sizeof( unsigned long ) ) ;
F_42 ( & V_42 -> V_47 , sizeof( unsigned long ) ) ;
return 0 ;
}
int T_2 F_43 ( void )
{
V_3 = F_44 ( sizeof( struct V_8 ) * V_66 ,
V_67 ) ;
if ( ! V_3 )
return - V_68 ;
return 0 ;
}
void F_45 ( void )
{
F_46 ( V_3 ) ;
}
int T_2 F_47 ( void )
{
F_48 ( V_58 ) ;
V_48 = F_49 ( & F_28 ,
NULL , V_58 ) ;
if ( F_50 ( V_48 ) ) {
F_41 ( L_3 , F_51 ( V_48 ) ) ;
V_48 = NULL ;
F_52 ( V_58 ) ;
return - V_68 ;
}
return 0 ;
}
int F_53 ( struct V_9 * V_10 )
{
if ( ! F_20 ( V_10 ) )
return 0 ;
return F_35 ( V_10 , 0 ) ;
}
void F_54 ( struct V_9 * V_10 )
{
if ( ! F_20 ( V_10 ) )
return;
V_10 -> V_16 = F_1 () ;
F_42 ( & V_10 -> V_16 , sizeof( void * ) ) ;
}
void F_55 ( struct V_9 * V_10 )
{
if ( ! F_20 ( V_10 ) )
return;
F_35 ( V_10 , 1 ) ;
F_5 ( V_10 -> V_16 ) ;
}
void T_3 F_56 ( void )
{
F_57 ( ! F_58 ( & V_15 ) ) ;
if ( V_48 ) {
F_59 ( V_48 , V_58 ) ;
F_52 ( V_58 ) ;
}
}
