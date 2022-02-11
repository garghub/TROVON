inline int F_1 ( void )
{
return V_1 ;
}
inline void F_2 ( T_1 V_2 , T_1 V_3 )
{
if ( V_4 ) {
struct V_5 * V_6 =
F_3 ( V_4 -> V_7 . V_8 ,
struct V_5 , V_6 ) ;
if ( V_6 -> V_9 == V_10 ) {
V_6 = F_4 ( sizeof( struct V_5 ) ,
V_11 ) ;
if ( ! V_6 ) {
F_5 ( V_12
L_1 ) ;
V_1 = - V_13 ;
return;
}
V_6 -> V_9 = 0 ;
F_6 ( & V_6 -> V_6 , & V_4 -> V_7 ) ;
}
V_6 -> V_14 [ V_6 -> V_9 ] . V_15 = V_2 ;
V_6 -> V_14 [ V_6 -> V_9 ] . V_16 = V_3 ;
V_6 -> V_9 ++ ;
} else
F_7 ( ( V_2 ) , ( V_3 ) ) ;
}
inline void F_8 ( void )
{
V_17 = F_9 ( L_2 ) ;
}
static void F_10 ( struct V_18 * V_19 )
{
struct V_5 * V_6 , * V_20 ;
F_11 ( V_19 -> V_21 , V_19 -> V_22 ) ;
F_12 (node, tmp, &job->roi_cmd_list, node) {
F_13 ( & V_6 -> V_6 ) ;
F_14 ( V_6 ) ;
}
F_14 ( V_19 ) ;
}
static void F_15 ( struct V_23 * V_24 )
{
struct V_18 * V_19 ;
F_16 ( L_3 ) ;
V_19 = F_17 ( V_24 , struct V_18 , V_25 . V_24 ) ;
if ( F_18 ( V_24 && V_19 ) )
F_10 ( V_19 ) ;
}
inline struct V_18 * F_19 ( void )
{
struct V_18 * V_19 ;
struct V_5 * V_6 ;
V_19 = F_4 ( sizeof( struct V_18 ) , V_11 ) ;
if ( ! V_19 )
return NULL ;
V_6 = F_4 ( sizeof( struct V_5 ) , V_11 ) ;
if ( ! V_6 ) {
F_14 ( V_19 ) ;
return NULL ;
}
F_20 ( V_4 ) ;
V_4 = V_19 ;
F_21 ( & V_4 -> V_7 ) ;
V_6 -> V_9 = 0 ;
F_21 ( & V_6 -> V_6 ) ;
F_6 ( & V_6 -> V_6 , & V_4 -> V_7 ) ;
F_22 ( & V_4 -> V_25 , F_15 ) ;
F_21 ( & V_4 -> V_26 ) ;
V_4 -> V_21 = 0 ;
V_4 -> V_22 = 0 ;
return V_19 ;
}
inline void F_23 ( void )
{
if ( F_18 ( V_4 ) ) {
F_10 ( V_4 ) ;
V_4 = NULL ;
}
}
static void F_24 ( void * V_27 )
{
unsigned long V_28 ;
struct V_18 * V_19 ;
while ( V_27 && F_25 ( 0 , ( unsigned long * ) V_27 ) ) {
F_26 ( & V_29 , V_28 ) ;
if ( F_27 ( & V_30 ) ) {
F_28 ( & V_29 , V_28 ) ;
break;
}
F_16 ( L_4 ) ;
V_19 = F_3 ( V_30 . V_31 ,
struct V_18 , V_26 ) ;
F_29 ( & V_19 -> V_26 ) ;
F_28 ( & V_29 , V_28 ) ;
F_30 ( V_19 -> V_32 , & V_19 -> V_33 , 1 ) ;
F_31 ( V_17 , & V_19 -> V_25 ,
V_34 ) ;
}
}
void F_32 ( void )
{
unsigned long V_28 ;
int V_27 = 1 ;
F_24 ( & V_35 ) ;
F_26 ( & V_36 , V_28 ) ;
if ( F_25 ( 0 , ( unsigned long * ) & V_35 ) ) {
F_33 ( 0 , ( unsigned long * ) & V_37 ) ;
F_34 ( V_38 ) ;
F_28 ( & V_36 , V_28 ) ;
F_16 ( L_5 ) ;
F_35 ( & V_38 ) ;
F_26 ( & V_36 , V_28 ) ;
if ( ! F_25 ( 0 , ( unsigned long * ) & V_35 ) &&
F_36 ( 0 , ( unsigned long * ) & V_39 ) )
F_37 ( V_40 ) ;
}
F_28 ( & V_36 , V_28 ) ;
F_24 ( & V_27 ) ;
}
static void F_38 ( struct V_41 * V_7 )
{
struct V_5 * V_6 ;
F_39 (node, roi_cmd_list, node) {
int V_42 = 0 ;
for (; V_42 < V_6 -> V_9 ; V_42 ++ ) {
F_16 ( L_6 ,
V_42 , V_6 -> V_14 [ V_42 ] . V_15 , V_6 -> V_14 [ V_42 ] . V_16 ) ;
F_7 ( V_6 -> V_14 [ V_42 ] . V_15 , V_6 -> V_14 [ V_42 ] . V_16 ) ;
}
}
F_16 ( L_7 ) ;
F_7 ( V_43 + 0x30 , 0x1000 ) ;
}
static void F_40 ( struct V_18 * V_19 )
{
if ( ! F_33 ( 0 , ( unsigned long * ) & V_39 ) )
F_41 ( V_40 ) ;
F_42 ( V_44 , V_45 , FALSE ) ;
F_42 ( V_46 , V_45 , FALSE ) ;
F_38 ( & V_19 -> V_7 ) ;
}
static inline void F_43 ( struct V_18 * V_19 )
{
unsigned long V_28 ;
F_26 ( & V_36 , V_28 ) ;
F_6 ( & V_19 -> V_26 , & V_47 ) ;
F_28 ( & V_36 , V_28 ) ;
}
void F_44 ( void )
{
F_43 ( V_4 ) ;
if ( ! F_33 ( 0 , ( unsigned long * ) & V_35 ) )
F_40 ( V_4 ) ;
V_4 = NULL ;
}
void F_45 ( void )
{
struct V_18 * V_48 , * V_31 ;
unsigned long V_28 ;
F_26 ( & V_36 , V_28 ) ;
V_48 = F_3 ( V_47 . V_31 , struct V_18 , V_26 ) ;
F_29 ( & V_48 -> V_26 ) ;
F_28 ( & V_36 , V_28 ) ;
F_26 ( & V_29 , V_28 ) ;
F_6 ( & V_48 -> V_26 , & V_30 ) ;
F_28 ( & V_29 , V_28 ) ;
F_26 ( & V_36 , V_28 ) ;
if ( ! F_27 ( & V_47 ) ) {
V_31 = F_3 ( V_47 . V_31 , struct V_18 ,
V_26 ) ;
F_28 ( & V_36 , V_28 ) ;
F_38 ( & V_31 -> V_7 ) ;
} else {
F_28 ( & V_36 , V_28 ) ;
F_42 ( V_46 , V_49 , TRUE ) ;
F_42 ( V_44 , V_49 , TRUE ) ;
if ( F_36 ( 0 , ( unsigned long * ) & V_37 ) )
F_46 ( & V_38 ) ;
F_36 ( 0 , ( unsigned long * ) & V_35 ) ;
}
}
