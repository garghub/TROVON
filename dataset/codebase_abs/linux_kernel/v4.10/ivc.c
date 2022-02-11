static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( ! V_2 -> V_4 )
return;
F_2 ( V_2 -> V_4 , V_3 , V_5 ,
V_6 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( ! V_2 -> V_4 )
return;
F_4 ( V_2 -> V_4 , V_3 , V_5 ,
V_7 ) ;
}
static inline bool F_5 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
T_2 V_10 = F_6 ( V_9 -> V_10 . V_11 ) ;
T_2 V_12 = F_6 ( V_9 -> V_12 . V_11 ) ;
if ( V_10 - V_12 > V_2 -> V_13 )
return true ;
return V_10 == V_12 ;
}
static inline bool F_7 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
T_2 V_10 = F_6 ( V_9 -> V_10 . V_11 ) ;
T_2 V_12 = F_6 ( V_9 -> V_12 . V_11 ) ;
return V_10 - V_12 >= V_2 -> V_13 ;
}
static inline T_2 F_8 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
T_2 V_10 = F_6 ( V_9 -> V_10 . V_11 ) ;
T_2 V_12 = F_6 ( V_9 -> V_12 . V_11 ) ;
return V_10 - V_12 ;
}
static inline void F_9 ( struct V_1 * V_2 )
{
F_6 ( V_2 -> V_10 . V_14 -> V_10 . V_11 ) =
F_6 ( V_2 -> V_10 . V_14 -> V_10 . V_11 ) + 1 ;
if ( V_2 -> V_10 . V_15 == V_2 -> V_13 - 1 )
V_2 -> V_10 . V_15 = 0 ;
else
V_2 -> V_10 . V_15 ++ ;
}
static inline void F_10 ( struct V_1 * V_2 )
{
F_6 ( V_2 -> V_12 . V_14 -> V_12 . V_11 ) =
F_6 ( V_2 -> V_12 . V_14 -> V_12 . V_11 ) + 1 ;
if ( V_2 -> V_12 . V_15 == V_2 -> V_13 - 1 )
V_2 -> V_12 . V_15 = 0 ;
else
V_2 -> V_12 . V_15 ++ ;
}
static inline int F_11 ( struct V_1 * V_2 )
{
unsigned int V_16 = F_12 ( struct V_8 , V_10 . V_11 ) ;
if ( V_2 -> V_10 . V_14 -> V_10 . V_17 != V_18 )
return - V_19 ;
if ( ! F_5 ( V_2 , V_2 -> V_12 . V_14 ) )
return 0 ;
F_1 ( V_2 , V_2 -> V_12 . V_3 + V_16 ) ;
if ( F_5 ( V_2 , V_2 -> V_12 . V_14 ) )
return - V_20 ;
return 0 ;
}
static inline int F_13 ( struct V_1 * V_2 )
{
unsigned int V_16 = F_12 ( struct V_8 , V_12 . V_11 ) ;
if ( V_2 -> V_10 . V_14 -> V_10 . V_17 != V_18 )
return - V_19 ;
if ( ! F_7 ( V_2 , V_2 -> V_10 . V_14 ) )
return 0 ;
F_1 ( V_2 , V_2 -> V_10 . V_3 + V_16 ) ;
if ( F_7 ( V_2 , V_2 -> V_10 . V_14 ) )
return - V_20 ;
return 0 ;
}
static void * F_14 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
unsigned int V_21 )
{
if ( F_15 ( V_21 >= V_2 -> V_13 ) )
return F_16 ( - V_22 ) ;
return ( void * ) ( V_9 + 1 ) + V_2 -> V_23 * V_21 ;
}
static inline T_1 F_17 ( struct V_1 * V_2 ,
T_1 V_3 ,
unsigned int V_21 )
{
unsigned long V_16 ;
V_16 = sizeof( struct V_8 ) + V_2 -> V_23 * V_21 ;
return V_3 + V_16 ;
}
static inline void F_18 ( struct V_1 * V_2 ,
T_1 V_3 ,
unsigned int V_21 ,
unsigned int V_16 ,
T_3 V_24 )
{
if ( ! V_2 -> V_4 || F_15 ( V_21 >= V_2 -> V_13 ) )
return;
V_3 = F_17 ( V_2 , V_3 , V_21 ) + V_16 ;
F_2 ( V_2 -> V_4 , V_3 , V_24 , V_6 ) ;
}
static inline void F_19 ( struct V_1 * V_2 ,
T_1 V_3 ,
unsigned int V_21 ,
unsigned int V_16 ,
T_3 V_24 )
{
if ( ! V_2 -> V_4 || F_15 ( V_21 >= V_2 -> V_13 ) )
return;
V_3 = F_17 ( V_2 , V_3 , V_21 ) + V_16 ;
F_4 ( V_2 -> V_4 , V_3 , V_24 , V_7 ) ;
}
void * F_20 ( struct V_1 * V_2 )
{
int V_25 ;
if ( F_15 ( V_2 == NULL ) )
return F_16 ( - V_22 ) ;
V_25 = F_11 ( V_2 ) ;
if ( V_25 < 0 )
return F_16 ( V_25 ) ;
F_21 () ;
F_18 ( V_2 , V_2 -> V_12 . V_3 , V_2 -> V_12 . V_15 , 0 ,
V_2 -> V_23 ) ;
return F_14 ( V_2 , V_2 -> V_12 . V_14 , V_2 -> V_12 . V_15 ) ;
}
int F_22 ( struct V_1 * V_2 )
{
unsigned int V_12 = F_12 ( struct V_8 , V_12 . V_11 ) ;
unsigned int V_10 = F_12 ( struct V_8 , V_10 . V_11 ) ;
int V_25 ;
V_25 = F_11 ( V_2 ) ;
if ( V_25 < 0 )
return V_25 ;
F_10 ( V_2 ) ;
F_3 ( V_2 , V_2 -> V_12 . V_3 + V_12 ) ;
F_23 () ;
F_1 ( V_2 , V_2 -> V_12 . V_3 + V_10 ) ;
if ( F_8 ( V_2 , V_2 -> V_12 . V_14 ) == V_2 -> V_13 - 1 )
V_2 -> V_26 ( V_2 , V_2 -> V_27 ) ;
return 0 ;
}
void * F_24 ( struct V_1 * V_2 )
{
int V_25 ;
V_25 = F_13 ( V_2 ) ;
if ( V_25 < 0 )
return F_16 ( V_25 ) ;
return F_14 ( V_2 , V_2 -> V_10 . V_14 , V_2 -> V_10 . V_15 ) ;
}
int F_25 ( struct V_1 * V_2 )
{
unsigned int V_10 = F_12 ( struct V_8 , V_10 . V_11 ) ;
unsigned int V_12 = F_12 ( struct V_8 , V_12 . V_11 ) ;
int V_25 ;
V_25 = F_13 ( V_2 ) ;
if ( V_25 < 0 )
return V_25 ;
F_19 ( V_2 , V_2 -> V_10 . V_3 , V_2 -> V_10 . V_15 , 0 ,
V_2 -> V_23 ) ;
F_26 () ;
F_9 ( V_2 ) ;
F_3 ( V_2 , V_2 -> V_10 . V_3 + V_10 ) ;
F_23 () ;
F_1 ( V_2 , V_2 -> V_10 . V_3 + V_12 ) ;
if ( F_8 ( V_2 , V_2 -> V_10 . V_14 ) == 1 )
V_2 -> V_26 ( V_2 , V_2 -> V_27 ) ;
return 0 ;
}
void F_27 ( struct V_1 * V_2 )
{
unsigned int V_16 = F_12 ( struct V_8 , V_10 . V_11 ) ;
V_2 -> V_10 . V_14 -> V_10 . V_17 = V_28 ;
F_3 ( V_2 , V_2 -> V_10 . V_3 + V_16 ) ;
V_2 -> V_26 ( V_2 , V_2 -> V_27 ) ;
}
int F_28 ( struct V_1 * V_2 )
{
unsigned int V_16 = F_12 ( struct V_8 , V_10 . V_11 ) ;
enum V_29 V_17 ;
F_1 ( V_2 , V_2 -> V_12 . V_3 + V_16 ) ;
V_17 = F_6 ( V_2 -> V_12 . V_14 -> V_10 . V_17 ) ;
if ( V_17 == V_28 ) {
V_16 = F_12 ( struct V_8 , V_10 . V_11 ) ;
F_21 () ;
V_2 -> V_10 . V_14 -> V_10 . V_11 = 0 ;
V_2 -> V_12 . V_14 -> V_12 . V_11 = 0 ;
V_2 -> V_10 . V_15 = 0 ;
V_2 -> V_12 . V_15 = 0 ;
F_26 () ;
V_2 -> V_10 . V_14 -> V_10 . V_17 = V_30 ;
F_3 ( V_2 , V_2 -> V_10 . V_3 + V_16 ) ;
V_2 -> V_26 ( V_2 , V_2 -> V_27 ) ;
} else if ( V_2 -> V_10 . V_14 -> V_10 . V_17 == V_28 &&
V_17 == V_30 ) {
V_16 = F_12 ( struct V_8 , V_10 . V_11 ) ;
F_21 () ;
V_2 -> V_10 . V_14 -> V_10 . V_11 = 0 ;
V_2 -> V_12 . V_14 -> V_12 . V_11 = 0 ;
V_2 -> V_10 . V_15 = 0 ;
V_2 -> V_12 . V_15 = 0 ;
F_26 () ;
V_2 -> V_10 . V_14 -> V_10 . V_17 = V_18 ;
F_3 ( V_2 , V_2 -> V_10 . V_3 + V_16 ) ;
V_2 -> V_26 ( V_2 , V_2 -> V_27 ) ;
} else if ( V_2 -> V_10 . V_14 -> V_10 . V_17 == V_30 ) {
V_16 = F_12 ( struct V_8 , V_10 . V_11 ) ;
F_21 () ;
V_2 -> V_10 . V_14 -> V_10 . V_17 = V_18 ;
F_3 ( V_2 , V_2 -> V_10 . V_3 + V_16 ) ;
V_2 -> V_26 ( V_2 , V_2 -> V_27 ) ;
} else {
}
if ( V_2 -> V_10 . V_14 -> V_10 . V_17 != V_18 )
return - V_31 ;
return 0 ;
}
T_3 F_29 ( T_3 V_24 )
{
return F_30 ( V_24 , V_5 ) ;
}
unsigned F_31 ( unsigned V_32 )
{
if ( ! F_32 ( V_32 , V_5 ) ) {
F_33 ( L_1 ,
V_33 , V_32 , V_5 ) ;
return 0 ;
}
return V_32 + sizeof( struct V_8 ) ;
}
static int F_34 ( unsigned long V_12 , unsigned long V_10 ,
unsigned int V_13 , T_3 V_23 )
{
F_35 ( ! F_32 ( F_12 ( struct V_8 , V_10 . V_11 ) ,
V_5 ) ) ;
F_35 ( ! F_32 ( F_12 ( struct V_8 , V_12 . V_11 ) ,
V_5 ) ) ;
F_35 ( ! F_32 ( sizeof( struct V_8 ) ,
V_5 ) ) ;
if ( ( V_34 ) V_13 * ( V_34 ) V_23 >= 0x100000000UL ) {
F_33 ( L_2 ) ;
return - V_22 ;
}
if ( ! F_32 ( V_23 , V_5 ) ) {
F_33 ( L_3 , V_23 ) ;
return - V_22 ;
}
if ( ! F_32 ( V_12 , V_5 ) ) {
F_33 ( L_4 , V_12 ) ;
return - V_22 ;
}
if ( ! F_32 ( V_10 , V_5 ) ) {
F_33 ( L_4 , V_10 ) ;
return - V_22 ;
}
if ( V_12 < V_10 ) {
if ( V_12 + V_23 * V_13 > V_10 ) {
F_33 ( L_5 ,
V_12 , V_23 * V_13 , V_10 ) ;
return - V_22 ;
}
} else {
if ( V_10 + V_23 * V_13 > V_12 ) {
F_33 ( L_5 ,
V_10 , V_23 * V_13 , V_12 ) ;
return - V_22 ;
}
}
return 0 ;
}
int F_36 ( struct V_1 * V_2 , struct V_35 * V_4 , void * V_12 ,
T_1 V_36 , void * V_10 , T_1 V_37 ,
unsigned int V_13 , T_3 V_23 ,
void (* V_26)( struct V_1 * V_2 , void * V_38 ) ,
void * V_38 )
{
T_3 V_32 ;
int V_25 ;
if ( F_15 ( ! V_2 || ! V_26 ) )
return - V_22 ;
if ( V_23 > V_39 )
return - V_40 ;
V_25 = F_34 ( ( unsigned long ) V_12 , ( unsigned long ) V_10 ,
V_13 , V_23 ) ;
if ( V_25 < 0 )
return V_25 ;
V_32 = F_31 ( V_13 * V_23 ) ;
if ( V_4 ) {
V_2 -> V_12 . V_3 = F_37 ( V_4 , V_12 , V_32 ,
V_41 ) ;
if ( V_2 -> V_12 . V_3 == V_42 )
return - V_43 ;
V_2 -> V_10 . V_3 = F_37 ( V_4 , V_10 , V_32 ,
V_41 ) ;
if ( V_2 -> V_10 . V_3 == V_42 ) {
F_38 ( V_4 , V_2 -> V_12 . V_3 , V_32 ,
V_41 ) ;
return - V_43 ;
}
} else {
V_2 -> V_12 . V_3 = V_36 ;
V_2 -> V_10 . V_3 = V_37 ;
}
V_2 -> V_12 . V_14 = V_12 ;
V_2 -> V_10 . V_14 = V_10 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_26 = V_26 ;
V_2 -> V_27 = V_38 ;
V_2 -> V_23 = V_23 ;
V_2 -> V_13 = V_13 ;
V_2 -> V_10 . V_15 = 0 ;
V_2 -> V_12 . V_15 = 0 ;
return 0 ;
}
void F_39 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 ) {
T_3 V_24 = F_31 ( V_2 -> V_13 *
V_2 -> V_23 ) ;
F_38 ( V_2 -> V_4 , V_2 -> V_12 . V_3 , V_24 ,
V_41 ) ;
F_38 ( V_2 -> V_4 , V_2 -> V_10 . V_3 , V_24 ,
V_41 ) ;
}
}
