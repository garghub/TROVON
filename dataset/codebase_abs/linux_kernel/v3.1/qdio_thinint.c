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
struct V_11 * V_12 ;
int V_1 ;
F_8 ( & V_13 ) ;
F_9 (irq_ptr, q, i)
F_10 ( & V_12 -> V_14 , & V_15 ) ;
F_11 ( & V_13 ) ;
F_12 ( V_10 -> V_16 , 1 << 7 ) ;
}
void F_13 ( struct V_9 * V_10 )
{
struct V_11 * V_12 ;
int V_1 ;
for ( V_1 = 0 ; V_1 < V_10 -> V_17 ; V_1 ++ ) {
V_12 = V_10 -> V_18 [ V_1 ] ;
if ( ! V_12 || ! V_12 -> V_14 . V_19 || ! V_12 -> V_14 . V_20 )
continue;
F_8 ( & V_13 ) ;
F_14 ( & V_12 -> V_14 ) ;
F_11 ( & V_13 ) ;
F_15 () ;
}
}
static inline T_1 F_16 ( void )
{
if ( ! F_2 ( & V_3 [ V_6 ] . V_4 ) )
return 0 ;
return F_12 ( & V_3 [ V_6 ] . V_5 , 0 ) ;
}
static void F_17 ( void * V_21 , void * V_22 )
{
T_1 V_23 = F_16 () ;
struct V_11 * V_12 ;
V_24 = V_25 . V_26 ;
F_18 ( F_19 () ) . V_27 [ V_28 ] ++ ;
F_20 () ;
F_21 (q, &tiq_list, entry) {
if ( F_22 ( F_23 ( V_12 -> V_10 -> V_16 ) ) ) {
if ( ! V_23 )
continue;
} else if ( ! * V_12 -> V_10 -> V_16 )
continue;
if ( V_12 -> V_29 . V_30 . V_31 ) {
if ( F_24 ( V_32 ,
& V_12 -> V_29 . V_30 . V_33 ) ) {
F_25 ( V_12 , V_34 ) ;
continue;
}
V_12 -> V_29 . V_30 . V_31 ( V_12 -> V_10 -> V_35 , V_12 -> V_36 ,
V_12 -> V_10 -> V_37 ) ;
} else {
if ( ! F_23 ( V_12 -> V_10 -> V_16 ) )
F_12 ( V_12 -> V_10 -> V_16 , 0 ) ;
F_26 ( & V_12 -> V_38 ) ;
}
F_25 ( V_12 , V_39 ) ;
}
F_27 () ;
}
static int F_28 ( struct V_9 * V_10 , int V_40 )
{
struct V_41 * V_41 ;
int V_42 ;
V_41 = (struct V_41 * ) V_10 -> V_43 ;
memset ( V_41 , 0 , V_44 ) ;
if ( V_40 ) {
V_41 -> V_45 = 0 ;
V_41 -> V_46 = 0 ;
} else {
V_41 -> V_45 = F_29 ( V_47 ) ;
V_41 -> V_46 =
F_29 ( V_10 -> V_16 ) ;
}
V_41 -> V_48 = (struct V_49 ) {
. V_50 = 0x0fe0 ,
. V_51 = 0x0021 ,
} ;
V_41 -> V_52 = 0 ;
V_41 -> V_53 = V_54 >> 4 ;
V_41 -> V_55 = V_54 >> 4 ;
V_41 -> V_56 = V_57 ;
V_41 -> V_58 = V_10 -> V_58 ;
if ( V_59 . V_60 )
V_41 -> V_61 = 0x10000000 ;
V_42 = F_30 ( V_41 ) ;
if ( V_42 )
return - V_62 ;
V_42 = F_31 ( V_41 -> V_63 . V_51 ) ;
if ( V_42 ) {
F_32 ( L_1 , V_10 -> V_58 . V_64 ,
V_41 -> V_63 . V_51 ) ;
F_33 ( & V_41 -> V_63 , sizeof( void * ) ) ;
return V_42 ;
}
F_34 ( L_2 ) ;
F_35 ( & V_41 -> V_45 , sizeof( unsigned long ) ) ;
F_35 ( & V_41 -> V_46 , sizeof( unsigned long ) ) ;
return 0 ;
}
int T_2 F_36 ( void )
{
V_3 = F_37 ( sizeof( struct V_8 ) * V_65 ,
V_66 ) ;
if ( ! V_3 )
return - V_67 ;
return 0 ;
}
void F_38 ( void )
{
F_39 ( V_3 ) ;
}
int T_2 F_40 ( void )
{
F_41 ( V_57 ) ;
V_47 = F_42 ( & F_17 ,
NULL , V_57 ) ;
if ( F_43 ( V_47 ) ) {
F_34 ( L_3 , F_44 ( V_47 ) ) ;
V_47 = NULL ;
F_45 ( V_57 ) ;
return - V_67 ;
}
return 0 ;
}
int F_46 ( struct V_9 * V_10 )
{
if ( ! F_47 ( V_10 ) )
return 0 ;
return F_28 ( V_10 , 0 ) ;
}
void F_48 ( struct V_9 * V_10 )
{
if ( ! F_47 ( V_10 ) )
return;
V_10 -> V_16 = F_1 () ;
F_35 ( & V_10 -> V_16 , sizeof( void * ) ) ;
}
void F_49 ( struct V_9 * V_10 )
{
if ( ! F_47 ( V_10 ) )
return;
F_28 ( V_10 , 1 ) ;
F_5 ( V_10 -> V_16 ) ;
}
void T_3 F_50 ( void )
{
F_51 ( ! F_52 ( & V_15 ) ) ;
if ( V_47 ) {
F_53 ( V_47 , V_57 ) ;
F_45 ( V_57 ) ;
}
}
