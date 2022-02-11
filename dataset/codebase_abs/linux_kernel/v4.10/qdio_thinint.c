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
F_9 ( & V_10 -> V_12 [ 0 ] -> V_13 , & V_14 ) ;
F_10 ( & V_11 ) ;
F_11 ( V_10 -> V_15 , 1 << 7 ) ;
}
void F_12 ( struct V_9 * V_10 )
{
struct V_16 * V_17 ;
V_17 = V_10 -> V_12 [ 0 ] ;
if ( ! V_17 || ! V_17 -> V_13 . V_18 || ! V_17 -> V_13 . V_19 )
return;
F_8 ( & V_11 ) ;
F_13 ( & V_17 -> V_13 ) ;
F_10 ( & V_11 ) ;
F_14 () ;
}
static inline int F_15 ( struct V_9 * V_10 )
{
return V_10 -> V_20 > 1 ;
}
static inline int F_16 ( struct V_9 * V_10 )
{
return V_10 -> V_15 == & V_3 [ V_6 ] . V_5 ;
}
static inline int F_17 ( struct V_9 * V_10 )
{
return F_16 ( V_10 ) ||
F_15 ( V_10 ) ;
}
void F_18 ( struct V_9 * V_10 )
{
if ( ! F_19 ( V_10 ) )
return;
if ( F_17 ( V_10 ) )
return;
F_11 ( V_10 -> V_15 , 0 ) ;
}
int F_20 ( struct V_9 * V_10 )
{
if ( ! F_19 ( V_10 ) )
return 0 ;
if ( F_17 ( V_10 ) )
return 0 ;
if ( * V_10 -> V_15 )
return 1 ;
else
return 0 ;
}
static inline T_1 F_21 ( void )
{
if ( ! F_2 ( & V_3 [ V_6 ] . V_4 ) )
return 0 ;
return F_11 ( & V_3 [ V_6 ] . V_5 , 0 ) ;
}
static inline void F_22 ( struct V_9 * V_21 )
{
struct V_16 * V_17 ;
int V_1 ;
F_23 (irq, q, i) {
if ( ! F_16 ( V_21 ) &&
F_15 ( V_21 ) )
F_11 ( V_17 -> V_10 -> V_15 , 0 ) ;
if ( V_17 -> V_22 . V_23 . V_24 ) {
if ( F_24 ( V_25 ,
& V_17 -> V_22 . V_23 . V_26 ) ) {
F_25 ( V_17 , V_27 ) ;
continue;
}
V_17 -> V_22 . V_23 . V_24 ( V_17 -> V_10 -> V_28 , V_17 -> V_29 ,
V_17 -> V_10 -> V_30 ) ;
} else {
if ( ! F_17 ( V_17 -> V_10 ) )
F_11 ( V_17 -> V_10 -> V_15 , 0 ) ;
F_26 ( & V_17 -> V_31 ) ;
}
}
}
static void F_27 ( struct V_32 * V_33 )
{
T_1 V_34 = F_21 () ;
struct V_16 * V_17 ;
V_35 = V_36 . V_37 ;
F_28 ( V_38 ) ;
F_29 () ;
F_30 (q, &tiq_list, entry) {
struct V_9 * V_21 ;
V_21 = V_17 -> V_10 ;
if ( F_31 ( F_16 ( V_21 ) ) ) {
if ( ! V_34 )
continue;
} else if ( ! * V_21 -> V_15 )
continue;
F_22 ( V_21 ) ;
F_25 ( V_17 , V_39 ) ;
}
F_32 () ;
}
static int F_33 ( struct V_9 * V_10 , int V_40 )
{
struct V_41 * V_42 = ( void * ) V_10 -> V_43 ;
T_2 V_44 , V_45 ;
int V_46 ;
if ( V_40 ) {
V_44 = 0 ;
V_45 = 0 ;
} else {
V_44 = F_34 ( V_47 . V_48 ) ;
V_45 = F_34 ( V_10 -> V_15 ) ;
}
V_46 = F_35 ( V_10 -> V_49 , V_42 , V_44 ,
V_45 ) ;
if ( V_46 ) {
F_36 ( L_1 , V_10 -> V_49 . V_50 ,
V_42 -> V_51 . V_52 ) ;
goto V_53;
}
F_37 ( L_2 ) ;
F_38 ( & V_44 , sizeof( V_44 ) ) ;
F_38 ( & V_45 , sizeof( V_45 ) ) ;
V_53:
return V_46 ;
}
int T_3 F_39 ( void )
{
V_3 = F_40 ( sizeof( struct V_8 ) * V_54 ,
V_55 ) ;
if ( ! V_3 )
return - V_56 ;
return 0 ;
}
void F_41 ( void )
{
F_42 ( V_3 ) ;
}
int T_3 F_43 ( void )
{
int V_46 ;
V_46 = F_44 ( & V_47 ) ;
if ( V_46 ) {
F_37 ( L_3 , V_46 ) ;
return V_46 ;
}
return 0 ;
}
int F_45 ( struct V_9 * V_10 )
{
if ( ! F_19 ( V_10 ) )
return 0 ;
return F_33 ( V_10 , 0 ) ;
}
void F_46 ( struct V_9 * V_10 )
{
if ( ! F_19 ( V_10 ) )
return;
V_10 -> V_15 = F_1 () ;
F_38 ( & V_10 -> V_15 , sizeof( void * ) ) ;
}
void F_47 ( struct V_9 * V_10 )
{
if ( ! F_19 ( V_10 ) )
return;
F_33 ( V_10 , 1 ) ;
F_5 ( V_10 -> V_15 ) ;
}
void T_4 F_48 ( void )
{
F_49 ( ! F_50 ( & V_14 ) ) ;
F_51 ( & V_47 ) ;
}
