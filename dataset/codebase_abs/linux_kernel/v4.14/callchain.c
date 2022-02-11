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
F_6 ( V_8 , V_22 ) ;
} else {
if ( V_14 == 0 )
V_12 = V_13 ;
else
V_12 = V_15 [ V_23 ] ;
if ( ( V_14 == 1 && V_12 == V_13 ) ||
( V_14 <= 1 && ! F_7 ( V_12 ) ) )
V_12 = 0 ;
++ V_14 ;
}
F_4 ( V_8 , V_12 ) ;
if ( ! F_1 ( V_11 , V_1 ) )
return;
V_1 = V_11 ;
}
}
static int F_8 ( void T_1 * V_24 , void * V_25 , int V_26 )
{
int V_27 = - V_28 ;
T_2 * V_29 ;
T_3 * V_30 , V_31 ;
unsigned V_32 ;
unsigned long V_33 = ( unsigned long ) V_24 ;
unsigned long V_34 ;
unsigned long V_35 , V_36 ;
void * V_37 ;
V_29 = V_3 -> V_38 -> V_39 ;
if ( ! V_29 )
return - V_28 ;
F_9 ( V_36 ) ;
V_30 = F_10 ( V_29 , V_33 , NULL , & V_32 ) ;
if ( ! V_30 )
goto V_40;
if ( ! V_32 )
V_32 = V_41 ;
V_34 = V_33 & ( ( 1UL << V_32 ) - 1 ) ;
V_31 = F_11 ( * V_30 ) ;
if ( ! F_12 ( V_31 ) || ! F_13 ( V_31 ) )
goto V_40;
V_35 = F_14 ( V_31 ) ;
if ( ! F_15 ( V_35 ) )
goto V_40;
V_37 = F_16 ( V_35 ) ;
memcpy ( V_25 , V_37 + V_34 , V_26 ) ;
V_27 = 0 ;
V_40:
F_17 ( V_36 ) ;
return V_27 ;
}
static int F_18 ( unsigned long T_1 * V_24 , unsigned long * V_27 )
{
if ( ( unsigned long ) V_24 > V_42 - sizeof( unsigned long ) ||
( ( unsigned long ) V_24 & 7 ) )
return - V_28 ;
F_19 () ;
if ( ! F_20 ( * V_27 , V_24 ) ) {
F_21 () ;
return 0 ;
}
F_21 () ;
return F_8 ( V_24 , V_27 , 8 ) ;
}
static int F_22 ( unsigned int T_1 * V_24 , unsigned int * V_27 )
{
if ( ( unsigned long ) V_24 > V_42 - sizeof( unsigned int ) ||
( ( unsigned long ) V_24 & 3 ) )
return - V_28 ;
F_19 () ;
if ( ! F_20 ( * V_27 , V_24 ) ) {
F_21 () ;
return 0 ;
}
F_21 () ;
return F_8 ( V_24 , V_27 , 4 ) ;
}
static inline int F_23 ( unsigned long V_1 , int V_43 )
{
if ( ! V_1 || ( V_1 & 7 ) || V_1 > ( V_43 ? V_42 : 0x100000000UL ) - 32 )
return 0 ;
return 1 ;
}
static int F_24 ( unsigned long V_21 , unsigned long V_15 )
{
if ( V_21 == V_15 + F_25 ( struct V_44 , V_45 ) )
return 1 ;
if ( V_46 && V_3 -> V_38 -> V_47 . V_48 &&
V_21 == V_3 -> V_38 -> V_47 . V_48 + V_46 )
return 1 ;
return 0 ;
}
static int F_26 ( unsigned long V_1 )
{
struct V_44 T_1 * V_49 ;
unsigned long V_50 , V_51 ;
V_49 = (struct V_44 T_1 * ) V_1 ;
if ( F_18 ( ( unsigned long T_1 * ) & V_49 -> V_50 , & V_50 ) ||
F_18 ( ( unsigned long T_1 * ) & V_49 -> V_51 , & V_51 ) )
return 0 ;
return V_50 == ( unsigned long ) & V_49 -> V_52 &&
V_51 == ( unsigned long ) & V_49 -> V_53 ;
}
static void F_27 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
unsigned long V_1 , V_11 ;
unsigned long V_12 ;
unsigned long V_13 ;
long V_14 = 0 ;
struct V_44 T_1 * V_54 ;
unsigned long T_1 * V_15 , * V_55 ;
V_12 = F_5 ( V_10 ) ;
V_13 = V_10 -> V_16 ;
V_1 = V_10 -> V_17 [ 1 ] ;
F_4 ( V_8 , V_12 ) ;
while ( V_8 -> V_56 < V_8 -> V_57 ) {
V_15 = ( unsigned long T_1 * ) V_1 ;
if ( ! F_23 ( V_1 , 1 ) || F_18 ( V_15 , & V_11 ) )
return;
if ( V_14 > 0 && F_18 ( & V_15 [ 2 ] , & V_12 ) )
return;
if ( V_11 - V_1 >= sizeof( struct V_44 ) &&
( F_24 ( V_12 , V_1 ) ||
( V_14 <= 1 && F_24 ( V_13 , V_1 ) ) ) &&
F_26 ( V_1 ) ) {
V_54 = (struct V_44 T_1 * ) V_1 ;
V_55 = V_54 -> V_53 . V_58 . V_59 ;
if ( F_18 ( & V_55 [ V_60 ] , & V_12 ) ||
F_18 ( & V_55 [ V_61 ] , & V_13 ) ||
F_18 ( & V_55 [ V_62 ] , & V_1 ) )
return;
V_14 = 0 ;
F_6 ( V_8 , V_63 ) ;
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
static inline int F_28 ( void )
{
return ! F_29 ( F_30 ( V_3 ) , V_64 ) ;
}
static int F_22 ( unsigned int T_1 * V_24 , unsigned int * V_27 )
{
int V_65 ;
if ( ( unsigned long ) V_24 > V_42 - sizeof( unsigned int ) ||
( ( unsigned long ) V_24 & 3 ) )
return - V_28 ;
F_19 () ;
V_65 = F_20 ( * V_27 , V_24 ) ;
F_21 () ;
return V_65 ;
}
static inline void F_27 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
}
static inline int F_28 ( void )
{
return 0 ;
}
static inline int F_23 ( unsigned long V_1 , int V_43 )
{
if ( ! V_1 || ( V_1 & 7 ) || V_1 > V_42 - 32 )
return 0 ;
return 1 ;
}
static int F_31 ( unsigned int V_21 , unsigned int V_15 )
{
if ( V_21 == V_15 + F_25 ( struct V_66 , V_67 . V_68 ) )
return 1 ;
if ( V_69 && V_3 -> V_38 -> V_47 . V_48 &&
V_21 == V_3 -> V_38 -> V_47 . V_48 + V_69 )
return 1 ;
return 0 ;
}
static int F_32 ( unsigned int V_21 , unsigned int V_15 )
{
if ( V_21 == V_15 + F_25 ( struct V_70 ,
V_53 . V_58 . V_68 ) )
return 1 ;
if ( V_71 && V_3 -> V_38 -> V_47 . V_48 &&
V_21 == V_3 -> V_38 -> V_47 . V_48 + V_71 )
return 1 ;
return 0 ;
}
static int F_33 ( unsigned int V_1 )
{
struct V_66 T_1 * V_49 ;
unsigned int V_10 ;
V_49 = (struct V_66 T_1 * ) ( unsigned long ) V_1 ;
if ( F_22 ( ( unsigned int T_1 * ) & V_49 -> V_72 . V_10 , & V_10 ) )
return 0 ;
return V_10 == ( unsigned long ) & V_49 -> V_67 ;
}
static int F_34 ( unsigned int V_1 )
{
struct V_70 T_1 * V_49 ;
unsigned int V_10 ;
V_49 = (struct V_70 T_1 * ) ( unsigned long ) V_1 ;
if ( F_22 ( ( unsigned int T_1 * ) & V_49 -> V_53 . V_73 , & V_10 ) )
return 0 ;
return V_10 == ( unsigned long ) & V_49 -> V_53 . V_58 ;
}
static unsigned int T_1 * F_35 ( unsigned int V_1 ,
unsigned int V_11 , unsigned int V_12 )
{
struct V_74 T_1 * V_67 = NULL ;
struct V_66 T_1 * V_49 ;
struct V_70 T_1 * V_75 ;
if ( V_11 - V_1 >= sizeof( struct V_66 ) &&
F_31 ( V_12 , V_1 ) &&
F_33 ( V_1 ) ) {
V_49 = (struct V_66 T_1 * ) ( unsigned long ) V_1 ;
V_67 = & V_49 -> V_67 ;
}
if ( ! V_67 && V_11 - V_1 >= sizeof( struct V_70 ) &&
F_32 ( V_12 , V_1 ) &&
F_34 ( V_1 ) ) {
V_75 = (struct V_70 T_1 * ) ( unsigned long ) V_1 ;
V_67 = & V_75 -> V_53 . V_58 ;
}
if ( ! V_67 )
return NULL ;
return V_67 -> V_76 ;
}
static void F_36 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
unsigned int V_1 , V_11 ;
unsigned int V_12 ;
unsigned int V_13 ;
long V_14 = 0 ;
unsigned int T_1 * V_15 , * V_55 ;
V_12 = F_5 ( V_10 ) ;
V_13 = V_10 -> V_16 ;
V_1 = V_10 -> V_17 [ 1 ] ;
F_4 ( V_8 , V_12 ) ;
while ( V_8 -> V_56 < V_8 -> V_57 ) {
V_15 = ( unsigned int T_1 * ) ( unsigned long ) V_1 ;
if ( ! F_23 ( V_1 , 0 ) || F_22 ( V_15 , & V_11 ) )
return;
if ( V_14 > 0 && F_22 ( & V_15 [ 1 ] , & V_12 ) )
return;
V_55 = F_35 ( V_1 , V_11 , V_12 ) ;
if ( ! V_55 && V_14 <= 1 )
V_55 = F_35 ( V_1 , V_11 , V_13 ) ;
if ( V_55 ) {
if ( F_22 ( & V_55 [ V_60 ] , & V_12 ) ||
F_22 ( & V_55 [ V_61 ] , & V_13 ) ||
F_22 ( & V_55 [ V_62 ] , & V_1 ) )
return;
V_14 = 0 ;
F_6 ( V_8 , V_63 ) ;
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
F_37 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
if ( F_28 () )
F_27 ( V_8 , V_10 ) ;
else
F_36 ( V_8 , V_10 ) ;
}
