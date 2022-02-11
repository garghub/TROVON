static int F_1 ( unsigned long V_1 , unsigned long V_2 )
{
if ( V_1 & 0xf )
return 0 ;
if ( ! F_2 ( V_1 , V_3 , V_4 ) )
return 0 ;
if ( V_1 >= V_2 + V_4 )
return 1 ;
if ( ( V_1 & ~ ( V_5 - 1 ) ) != ( V_2 & ~ ( V_5 - 1 ) ) )
return 1 ;
return 0 ;
}
void
F_3 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
unsigned long V_1 , V_10 ;
unsigned long V_11 ;
unsigned long V_12 ;
long V_13 = 0 ;
unsigned long * V_14 ;
V_12 = V_9 -> V_15 ;
V_1 = V_9 -> V_16 [ 1 ] ;
F_4 ( V_7 , V_9 -> V_17 ) ;
if ( ! F_2 ( V_1 , V_3 , V_4 ) )
return;
for (; ; ) {
V_14 = ( unsigned long * ) V_1 ;
V_10 = V_14 [ 0 ] ;
if ( V_10 == V_1 + V_18 &&
V_14 [ V_19 ] == V_20 ) {
V_9 = (struct V_8 * ) ( V_1 + V_4 ) ;
V_11 = V_9 -> V_17 ;
V_12 = V_9 -> V_15 ;
V_13 = 0 ;
F_4 ( V_7 , V_21 ) ;
} else {
if ( V_13 == 0 )
V_11 = V_12 ;
else
V_11 = V_14 [ V_22 ] ;
if ( ( V_13 == 1 && V_11 == V_12 ) ||
( V_13 <= 1 && ! F_5 ( V_11 ) ) )
V_11 = 0 ;
++ V_13 ;
}
F_4 ( V_7 , V_11 ) ;
if ( ! F_1 ( V_10 , V_1 ) )
return;
V_1 = V_10 ;
}
}
static int F_6 ( void T_1 * V_23 , void * V_24 , int V_25 )
{
T_2 * V_26 ;
T_3 * V_27 , V_28 ;
unsigned V_29 ;
unsigned long V_30 = ( unsigned long ) V_23 ;
unsigned long V_31 ;
unsigned long V_32 ;
void * V_33 ;
V_26 = V_3 -> V_34 -> V_35 ;
if ( ! V_26 )
return - V_36 ;
V_27 = F_7 ( V_26 , V_30 , & V_29 ) ;
if ( ! V_29 )
V_29 = V_37 ;
V_31 = V_30 & ( ( 1UL << V_29 ) - 1 ) ;
V_30 -= V_31 ;
if ( V_27 == NULL )
return - V_36 ;
V_28 = * V_27 ;
if ( ! F_8 ( V_28 ) || ! ( F_9 ( V_28 ) & V_38 ) )
return - V_36 ;
V_32 = F_10 ( V_28 ) ;
if ( ! F_11 ( V_32 ) )
return - V_36 ;
V_33 = F_12 ( V_32 ) ;
memcpy ( V_24 , V_33 + V_31 , V_25 ) ;
return 0 ;
}
static int F_13 ( unsigned long T_1 * V_23 , unsigned long * V_24 )
{
if ( ( unsigned long ) V_23 > V_39 - sizeof( unsigned long ) ||
( ( unsigned long ) V_23 & 7 ) )
return - V_36 ;
F_14 () ;
if ( ! F_15 ( * V_24 , V_23 ) ) {
F_16 () ;
return 0 ;
}
F_16 () ;
return F_6 ( V_23 , V_24 , 8 ) ;
}
static int F_17 ( unsigned int T_1 * V_23 , unsigned int * V_24 )
{
if ( ( unsigned long ) V_23 > V_39 - sizeof( unsigned int ) ||
( ( unsigned long ) V_23 & 3 ) )
return - V_36 ;
F_14 () ;
if ( ! F_15 ( * V_24 , V_23 ) ) {
F_16 () ;
return 0 ;
}
F_16 () ;
return F_6 ( V_23 , V_24 , 4 ) ;
}
static inline int F_18 ( unsigned long V_1 , int V_40 )
{
if ( ! V_1 || ( V_1 & 7 ) || V_1 > ( V_40 ? V_39 : 0x100000000UL ) - 32 )
return 0 ;
return 1 ;
}
static int F_19 ( unsigned long V_17 , unsigned long V_14 )
{
if ( V_17 == V_14 + F_20 ( struct V_41 , V_42 ) )
return 1 ;
if ( V_43 && V_3 -> V_34 -> V_44 . V_45 &&
V_17 == V_3 -> V_34 -> V_44 . V_45 + V_43 )
return 1 ;
return 0 ;
}
static int F_21 ( unsigned long V_1 )
{
struct V_41 T_1 * V_46 ;
unsigned long V_47 , V_48 ;
V_46 = (struct V_41 T_1 * ) V_1 ;
if ( F_13 ( ( unsigned long T_1 * ) & V_46 -> V_47 , & V_47 ) ||
F_13 ( ( unsigned long T_1 * ) & V_46 -> V_48 , & V_48 ) )
return 0 ;
return V_47 == ( unsigned long ) & V_46 -> V_49 &&
V_48 == ( unsigned long ) & V_46 -> V_50 ;
}
static void F_22 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
unsigned long V_1 , V_10 ;
unsigned long V_11 ;
unsigned long V_12 ;
long V_13 = 0 ;
struct V_41 T_1 * V_51 ;
unsigned long T_1 * V_14 , * V_52 ;
V_11 = V_9 -> V_17 ;
V_12 = V_9 -> V_15 ;
V_1 = V_9 -> V_16 [ 1 ] ;
F_4 ( V_7 , V_11 ) ;
for (; ; ) {
V_14 = ( unsigned long T_1 * ) V_1 ;
if ( ! F_18 ( V_1 , 1 ) || F_13 ( V_14 , & V_10 ) )
return;
if ( V_13 > 0 && F_13 ( & V_14 [ 2 ] , & V_11 ) )
return;
if ( V_10 - V_1 >= sizeof( struct V_41 ) &&
( F_19 ( V_11 , V_1 ) ||
( V_13 <= 1 && F_19 ( V_12 , V_1 ) ) ) &&
F_21 ( V_1 ) ) {
V_51 = (struct V_41 T_1 * ) V_1 ;
V_52 = V_51 -> V_50 . V_53 . V_54 ;
if ( F_13 ( & V_52 [ V_55 ] , & V_11 ) ||
F_13 ( & V_52 [ V_56 ] , & V_12 ) ||
F_13 ( & V_52 [ V_57 ] , & V_1 ) )
return;
V_13 = 0 ;
F_4 ( V_7 , V_58 ) ;
F_4 ( V_7 , V_11 ) ;
continue;
}
if ( V_13 == 0 )
V_11 = V_12 ;
F_4 ( V_7 , V_11 ) ;
++ V_13 ;
V_1 = V_10 ;
}
}
static inline int F_23 ( void )
{
return ! F_24 ( F_25 ( V_3 ) , V_59 ) ;
}
static int F_17 ( unsigned int T_1 * V_23 , unsigned int * V_24 )
{
int V_60 ;
if ( ( unsigned long ) V_23 > V_39 - sizeof( unsigned int ) ||
( ( unsigned long ) V_23 & 3 ) )
return - V_36 ;
F_14 () ;
V_60 = F_15 ( * V_24 , V_23 ) ;
F_16 () ;
return V_60 ;
}
static inline void F_22 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
}
static inline int F_23 ( void )
{
return 0 ;
}
static inline int F_18 ( unsigned long V_1 , int V_40 )
{
if ( ! V_1 || ( V_1 & 7 ) || V_1 > V_39 - 32 )
return 0 ;
return 1 ;
}
static int F_26 ( unsigned int V_17 , unsigned int V_14 )
{
if ( V_17 == V_14 + F_20 ( struct V_61 , V_62 . V_63 ) )
return 1 ;
if ( V_64 && V_3 -> V_34 -> V_44 . V_45 &&
V_17 == V_3 -> V_34 -> V_44 . V_45 + V_64 )
return 1 ;
return 0 ;
}
static int F_27 ( unsigned int V_17 , unsigned int V_14 )
{
if ( V_17 == V_14 + F_20 ( struct V_65 ,
V_50 . V_53 . V_63 ) )
return 1 ;
if ( V_66 && V_3 -> V_34 -> V_44 . V_45 &&
V_17 == V_3 -> V_34 -> V_44 . V_45 + V_66 )
return 1 ;
return 0 ;
}
static int F_28 ( unsigned int V_1 )
{
struct V_61 T_1 * V_46 ;
unsigned int V_9 ;
V_46 = (struct V_61 T_1 * ) ( unsigned long ) V_1 ;
if ( F_17 ( ( unsigned int T_1 * ) & V_46 -> V_67 . V_9 , & V_9 ) )
return 0 ;
return V_9 == ( unsigned long ) & V_46 -> V_62 ;
}
static int F_29 ( unsigned int V_1 )
{
struct V_65 T_1 * V_46 ;
unsigned int V_9 ;
V_46 = (struct V_65 T_1 * ) ( unsigned long ) V_1 ;
if ( F_17 ( ( unsigned int T_1 * ) & V_46 -> V_50 . V_68 , & V_9 ) )
return 0 ;
return V_9 == ( unsigned long ) & V_46 -> V_50 . V_53 ;
}
static unsigned int T_1 * F_30 ( unsigned int V_1 ,
unsigned int V_10 , unsigned int V_11 )
{
struct V_69 T_1 * V_62 = NULL ;
struct V_61 T_1 * V_46 ;
struct V_65 T_1 * V_70 ;
if ( V_10 - V_1 >= sizeof( struct V_61 ) &&
F_26 ( V_11 , V_1 ) &&
F_28 ( V_1 ) ) {
V_46 = (struct V_61 T_1 * ) ( unsigned long ) V_1 ;
V_62 = & V_46 -> V_62 ;
}
if ( ! V_62 && V_10 - V_1 >= sizeof( struct V_65 ) &&
F_27 ( V_11 , V_1 ) &&
F_29 ( V_1 ) ) {
V_70 = (struct V_65 T_1 * ) ( unsigned long ) V_1 ;
V_62 = & V_70 -> V_50 . V_53 ;
}
if ( ! V_62 )
return NULL ;
return V_62 -> V_71 ;
}
static void F_31 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
unsigned int V_1 , V_10 ;
unsigned int V_11 ;
unsigned int V_12 ;
long V_13 = 0 ;
unsigned int T_1 * V_14 , * V_52 ;
V_11 = V_9 -> V_17 ;
V_12 = V_9 -> V_15 ;
V_1 = V_9 -> V_16 [ 1 ] ;
F_4 ( V_7 , V_11 ) ;
while ( V_7 -> V_72 < V_73 ) {
V_14 = ( unsigned int T_1 * ) ( unsigned long ) V_1 ;
if ( ! F_18 ( V_1 , 0 ) || F_17 ( V_14 , & V_10 ) )
return;
if ( V_13 > 0 && F_17 ( & V_14 [ 1 ] , & V_11 ) )
return;
V_52 = F_30 ( V_1 , V_10 , V_11 ) ;
if ( ! V_52 && V_13 <= 1 )
V_52 = F_30 ( V_1 , V_10 , V_12 ) ;
if ( V_52 ) {
if ( F_17 ( & V_52 [ V_55 ] , & V_11 ) ||
F_17 ( & V_52 [ V_56 ] , & V_12 ) ||
F_17 ( & V_52 [ V_57 ] , & V_1 ) )
return;
V_13 = 0 ;
F_4 ( V_7 , V_58 ) ;
F_4 ( V_7 , V_11 ) ;
continue;
}
if ( V_13 == 0 )
V_11 = V_12 ;
F_4 ( V_7 , V_11 ) ;
++ V_13 ;
V_1 = V_10 ;
}
}
void
F_32 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
if ( F_23 () )
F_22 ( V_7 , V_9 ) ;
else
F_31 ( V_7 , V_9 ) ;
}
