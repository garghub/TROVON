static int F_1 ( unsigned long V_1 , unsigned long V_2 )
{
if ( V_1 & 0xf )
return 0 ;
if ( ! F_2 ( V_1 , V_3 , V_4 ) )
return 0 ;
if ( V_1 >= V_2 + V_5 )
return 1 ;
if ( ( V_1 & ~ ( V_6 - 1 ) ) != ( V_2 & ~ ( V_6 - 1 ) ) )
return 1 ;
return 0 ;
}
void
F_3 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
unsigned long V_1 , V_11 ;
unsigned long V_12 ;
unsigned long V_13 ;
long V_14 = 0 ;
unsigned long * V_15 ;
V_13 = V_10 -> V_16 ;
V_1 = V_10 -> V_17 [ 1 ] ;
F_4 ( V_8 , F_5 ( V_10 ) ) ;
if ( ! F_2 ( V_1 , V_3 , V_4 ) )
return;
for (; ; ) {
V_15 = ( unsigned long * ) V_1 ;
V_11 = V_15 [ 0 ] ;
if ( V_11 == V_1 + V_18 &&
V_15 [ V_19 ] == V_20 ) {
V_10 = (struct V_9 * ) ( V_1 + V_4 ) ;
V_12 = V_10 -> V_21 ;
V_13 = V_10 -> V_16 ;
V_14 = 0 ;
F_4 ( V_8 , V_22 ) ;
} else {
if ( V_14 == 0 )
V_12 = V_13 ;
else
V_12 = V_15 [ V_23 ] ;
if ( ( V_14 == 1 && V_12 == V_13 ) ||
( V_14 <= 1 && ! F_6 ( V_12 ) ) )
V_12 = 0 ;
++ V_14 ;
}
F_4 ( V_8 , V_12 ) ;
if ( ! F_1 ( V_11 , V_1 ) )
return;
V_1 = V_11 ;
}
}
static int F_7 ( void T_1 * V_24 , void * V_25 , int V_26 )
{
T_2 * V_27 ;
T_3 * V_28 , V_29 ;
unsigned V_30 ;
unsigned long V_31 = ( unsigned long ) V_24 ;
unsigned long V_32 ;
unsigned long V_33 ;
void * V_34 ;
V_27 = V_3 -> V_35 -> V_36 ;
if ( ! V_27 )
return - V_37 ;
V_28 = F_8 ( V_27 , V_31 , & V_30 ) ;
if ( ! V_30 )
V_30 = V_38 ;
V_32 = V_31 & ( ( 1UL << V_30 ) - 1 ) ;
V_31 -= V_32 ;
if ( V_28 == NULL )
return - V_37 ;
V_29 = * V_28 ;
if ( ! F_9 ( V_29 ) || ! ( F_10 ( V_29 ) & V_39 ) )
return - V_37 ;
V_33 = F_11 ( V_29 ) ;
if ( ! F_12 ( V_33 ) )
return - V_37 ;
V_34 = F_13 ( V_33 ) ;
memcpy ( V_25 , V_34 + V_32 , V_26 ) ;
return 0 ;
}
static int F_14 ( unsigned long T_1 * V_24 , unsigned long * V_25 )
{
if ( ( unsigned long ) V_24 > V_40 - sizeof( unsigned long ) ||
( ( unsigned long ) V_24 & 7 ) )
return - V_37 ;
F_15 () ;
if ( ! F_16 ( * V_25 , V_24 ) ) {
F_17 () ;
return 0 ;
}
F_17 () ;
return F_7 ( V_24 , V_25 , 8 ) ;
}
static int F_18 ( unsigned int T_1 * V_24 , unsigned int * V_25 )
{
if ( ( unsigned long ) V_24 > V_40 - sizeof( unsigned int ) ||
( ( unsigned long ) V_24 & 3 ) )
return - V_37 ;
F_15 () ;
if ( ! F_16 ( * V_25 , V_24 ) ) {
F_17 () ;
return 0 ;
}
F_17 () ;
return F_7 ( V_24 , V_25 , 4 ) ;
}
static inline int F_19 ( unsigned long V_1 , int V_41 )
{
if ( ! V_1 || ( V_1 & 7 ) || V_1 > ( V_41 ? V_40 : 0x100000000UL ) - 32 )
return 0 ;
return 1 ;
}
static int F_20 ( unsigned long V_21 , unsigned long V_15 )
{
if ( V_21 == V_15 + F_21 ( struct V_42 , V_43 ) )
return 1 ;
if ( V_44 && V_3 -> V_35 -> V_45 . V_46 &&
V_21 == V_3 -> V_35 -> V_45 . V_46 + V_44 )
return 1 ;
return 0 ;
}
static int F_22 ( unsigned long V_1 )
{
struct V_42 T_1 * V_47 ;
unsigned long V_48 , V_49 ;
V_47 = (struct V_42 T_1 * ) V_1 ;
if ( F_14 ( ( unsigned long T_1 * ) & V_47 -> V_48 , & V_48 ) ||
F_14 ( ( unsigned long T_1 * ) & V_47 -> V_49 , & V_49 ) )
return 0 ;
return V_48 == ( unsigned long ) & V_47 -> V_50 &&
V_49 == ( unsigned long ) & V_47 -> V_51 ;
}
static void F_23 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
unsigned long V_1 , V_11 ;
unsigned long V_12 ;
unsigned long V_13 ;
long V_14 = 0 ;
struct V_42 T_1 * V_52 ;
unsigned long T_1 * V_15 , * V_53 ;
V_12 = F_5 ( V_10 ) ;
V_13 = V_10 -> V_16 ;
V_1 = V_10 -> V_17 [ 1 ] ;
F_4 ( V_8 , V_12 ) ;
for (; ; ) {
V_15 = ( unsigned long T_1 * ) V_1 ;
if ( ! F_19 ( V_1 , 1 ) || F_14 ( V_15 , & V_11 ) )
return;
if ( V_14 > 0 && F_14 ( & V_15 [ 2 ] , & V_12 ) )
return;
if ( V_11 - V_1 >= sizeof( struct V_42 ) &&
( F_20 ( V_12 , V_1 ) ||
( V_14 <= 1 && F_20 ( V_13 , V_1 ) ) ) &&
F_22 ( V_1 ) ) {
V_52 = (struct V_42 T_1 * ) V_1 ;
V_53 = V_52 -> V_51 . V_54 . V_55 ;
if ( F_14 ( & V_53 [ V_56 ] , & V_12 ) ||
F_14 ( & V_53 [ V_57 ] , & V_13 ) ||
F_14 ( & V_53 [ V_58 ] , & V_1 ) )
return;
V_14 = 0 ;
F_4 ( V_8 , V_59 ) ;
F_4 ( V_8 , V_12 ) ;
continue;
}
if ( V_14 == 0 )
V_12 = V_13 ;
F_4 ( V_8 , V_12 ) ;
++ V_14 ;
V_1 = V_11 ;
}
}
static inline int F_24 ( void )
{
return ! F_25 ( F_26 ( V_3 ) , V_60 ) ;
}
static int F_18 ( unsigned int T_1 * V_24 , unsigned int * V_25 )
{
int V_61 ;
if ( ( unsigned long ) V_24 > V_40 - sizeof( unsigned int ) ||
( ( unsigned long ) V_24 & 3 ) )
return - V_37 ;
F_15 () ;
V_61 = F_16 ( * V_25 , V_24 ) ;
F_17 () ;
return V_61 ;
}
static inline void F_23 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
}
static inline int F_24 ( void )
{
return 0 ;
}
static inline int F_19 ( unsigned long V_1 , int V_41 )
{
if ( ! V_1 || ( V_1 & 7 ) || V_1 > V_40 - 32 )
return 0 ;
return 1 ;
}
static int F_27 ( unsigned int V_21 , unsigned int V_15 )
{
if ( V_21 == V_15 + F_21 ( struct V_62 , V_63 . V_64 ) )
return 1 ;
if ( V_65 && V_3 -> V_35 -> V_45 . V_46 &&
V_21 == V_3 -> V_35 -> V_45 . V_46 + V_65 )
return 1 ;
return 0 ;
}
static int F_28 ( unsigned int V_21 , unsigned int V_15 )
{
if ( V_21 == V_15 + F_21 ( struct V_66 ,
V_51 . V_54 . V_64 ) )
return 1 ;
if ( V_67 && V_3 -> V_35 -> V_45 . V_46 &&
V_21 == V_3 -> V_35 -> V_45 . V_46 + V_67 )
return 1 ;
return 0 ;
}
static int F_29 ( unsigned int V_1 )
{
struct V_62 T_1 * V_47 ;
unsigned int V_10 ;
V_47 = (struct V_62 T_1 * ) ( unsigned long ) V_1 ;
if ( F_18 ( ( unsigned int T_1 * ) & V_47 -> V_68 . V_10 , & V_10 ) )
return 0 ;
return V_10 == ( unsigned long ) & V_47 -> V_63 ;
}
static int F_30 ( unsigned int V_1 )
{
struct V_66 T_1 * V_47 ;
unsigned int V_10 ;
V_47 = (struct V_66 T_1 * ) ( unsigned long ) V_1 ;
if ( F_18 ( ( unsigned int T_1 * ) & V_47 -> V_51 . V_69 , & V_10 ) )
return 0 ;
return V_10 == ( unsigned long ) & V_47 -> V_51 . V_54 ;
}
static unsigned int T_1 * F_31 ( unsigned int V_1 ,
unsigned int V_11 , unsigned int V_12 )
{
struct V_70 T_1 * V_63 = NULL ;
struct V_62 T_1 * V_47 ;
struct V_66 T_1 * V_71 ;
if ( V_11 - V_1 >= sizeof( struct V_62 ) &&
F_27 ( V_12 , V_1 ) &&
F_29 ( V_1 ) ) {
V_47 = (struct V_62 T_1 * ) ( unsigned long ) V_1 ;
V_63 = & V_47 -> V_63 ;
}
if ( ! V_63 && V_11 - V_1 >= sizeof( struct V_66 ) &&
F_28 ( V_12 , V_1 ) &&
F_30 ( V_1 ) ) {
V_71 = (struct V_66 T_1 * ) ( unsigned long ) V_1 ;
V_63 = & V_71 -> V_51 . V_54 ;
}
if ( ! V_63 )
return NULL ;
return V_63 -> V_72 ;
}
static void F_32 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
unsigned int V_1 , V_11 ;
unsigned int V_12 ;
unsigned int V_13 ;
long V_14 = 0 ;
unsigned int T_1 * V_15 , * V_53 ;
V_12 = F_5 ( V_10 ) ;
V_13 = V_10 -> V_16 ;
V_1 = V_10 -> V_17 [ 1 ] ;
F_4 ( V_8 , V_12 ) ;
while ( V_8 -> V_73 < V_74 ) {
V_15 = ( unsigned int T_1 * ) ( unsigned long ) V_1 ;
if ( ! F_19 ( V_1 , 0 ) || F_18 ( V_15 , & V_11 ) )
return;
if ( V_14 > 0 && F_18 ( & V_15 [ 1 ] , & V_12 ) )
return;
V_53 = F_31 ( V_1 , V_11 , V_12 ) ;
if ( ! V_53 && V_14 <= 1 )
V_53 = F_31 ( V_1 , V_11 , V_13 ) ;
if ( V_53 ) {
if ( F_18 ( & V_53 [ V_56 ] , & V_12 ) ||
F_18 ( & V_53 [ V_57 ] , & V_13 ) ||
F_18 ( & V_53 [ V_58 ] , & V_1 ) )
return;
V_14 = 0 ;
F_4 ( V_8 , V_59 ) ;
F_4 ( V_8 , V_12 ) ;
continue;
}
if ( V_14 == 0 )
V_12 = V_13 ;
F_4 ( V_8 , V_12 ) ;
++ V_14 ;
V_1 = V_11 ;
}
}
void
F_33 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
if ( F_24 () )
F_23 ( V_8 , V_10 ) ;
else
F_32 ( V_8 , V_10 ) ;
}
