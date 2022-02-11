static inline void F_1 ( void )
{ F_2 ( sizeof( struct V_1 ) != sizeof( struct V_2 ) ) ; }
static inline void F_3 ( struct V_1 * V_3 )
{
F_4 ( & V_3 -> V_2 ) ;
V_3 -> V_2 . V_4 = NULL ;
}
static inline int F_5 ( struct V_1 * V_3 )
{
return F_6 ( (struct V_2 * ) V_3 ) ;
}
static inline void F_7 ( struct V_1 * V_3 )
{
F_8 ( (struct V_2 * ) V_3 ) ;
}
static inline void F_9 ( struct V_1 * V_3 )
{
F_10 ( (struct V_2 * ) V_3 ) ;
}
static inline struct V_1 * V_1 ( const void * V_5 )
{
return (struct V_1 * ) F_11 ( V_5 ) ;
}
static inline int F_12 ( struct V_1 * V_3 )
{
return F_13 ( (struct V_2 * ) V_3 ) ;
}
static void F_14 ( struct V_1 * V_3 , struct V_6 * V_7 )
{
F_15 ( & V_3 -> V_7 , V_7 ) ;
F_16 ( (struct V_2 * ) V_3 ) ;
}
static inline void F_17 ( struct V_1 * V_3 )
{
F_18 ( & V_3 -> V_7 ) ;
F_19 ( (struct V_2 * ) V_3 ) ;
}
static void F_20 ( T_1 * V_8 , T_2 V_9 , T_1 * V_10 )
{
T_1 * V_11 = ( T_1 * ) ( ( unsigned long ) V_8 & V_12 ) ;
T_2 V_13 = V_10 - V_11 ;
if ( V_9 > 1 ) {
V_8 [ 0 ] . V_14 = V_9 ;
V_8 [ 1 ] . V_14 = V_13 ;
} else
V_8 [ 0 ] . V_14 = - V_13 ;
}
static T_2 F_21 ( T_1 * V_8 )
{
if ( V_8 -> V_14 > 0 )
return V_8 -> V_14 ;
return 1 ;
}
static T_1 * F_22 ( T_1 * V_8 )
{
T_1 * V_11 = ( T_1 * ) ( ( unsigned long ) V_8 & V_12 ) ;
T_2 V_10 ;
if ( V_8 [ 0 ] . V_14 < 0 )
V_10 = - V_8 [ 0 ] . V_14 ;
else
V_10 = V_8 [ 1 ] . V_14 ;
return V_11 + V_10 ;
}
static int F_23 ( T_1 * V_8 )
{
return ! ( ( unsigned long ) F_22 ( V_8 ) & ~ V_12 ) ;
}
static void * F_24 ( T_3 V_15 , int V_16 , int V_17 )
{
void * V_2 ;
#ifdef F_25
if ( V_17 != - 1 )
V_2 = F_26 ( V_17 , V_15 , V_16 ) ;
else
#endif
V_2 = F_27 ( V_15 , V_16 ) ;
if ( ! V_2 )
return NULL ;
return F_28 ( V_2 ) ;
}
static void F_29 ( void * V_18 , int V_16 )
{
if ( V_19 -> V_20 )
V_19 -> V_20 -> V_21 += 1 << V_16 ;
F_30 ( ( unsigned long ) V_18 , V_16 ) ;
}
static void * F_31 ( struct V_1 * V_3 , T_4 V_9 , int V_22 )
{
T_1 * V_23 , * V_24 , * V_25 = NULL ;
int V_26 = 0 , V_14 = F_32 ( V_9 ) ;
for ( V_23 = NULL , V_24 = V_3 -> free ; ; V_23 = V_24 , V_24 = F_22 ( V_24 ) ) {
T_2 V_27 = F_21 ( V_24 ) ;
if ( V_22 ) {
V_25 = ( T_1 * ) F_33 ( ( unsigned long ) V_24 , V_22 ) ;
V_26 = V_25 - V_24 ;
}
if ( V_27 >= V_14 + V_26 ) {
T_1 * V_10 ;
if ( V_26 ) {
V_10 = F_22 ( V_24 ) ;
F_20 ( V_25 , V_27 - V_26 , V_10 ) ;
F_20 ( V_24 , V_26 , V_25 ) ;
V_23 = V_24 ;
V_24 = V_25 ;
V_27 = F_21 ( V_24 ) ;
}
V_10 = F_22 ( V_24 ) ;
if ( V_27 == V_14 ) {
if ( V_23 )
F_20 ( V_23 , F_21 ( V_23 ) , V_10 ) ;
else
V_3 -> free = V_10 ;
} else {
if ( V_23 )
F_20 ( V_23 , F_21 ( V_23 ) , V_24 + V_14 ) ;
else
V_3 -> free = V_24 + V_14 ;
F_20 ( V_24 + V_14 , V_27 - V_14 , V_10 ) ;
}
V_3 -> V_14 -= V_14 ;
if ( ! V_3 -> V_14 )
F_17 ( V_3 ) ;
return V_24 ;
}
if ( F_23 ( V_24 ) )
return NULL ;
}
}
static void * F_34 ( T_4 V_9 , T_3 V_15 , int V_22 , int V_17 )
{
struct V_1 * V_3 ;
struct V_6 * V_23 ;
struct V_6 * V_28 ;
T_1 * V_18 = NULL ;
unsigned long V_29 ;
if ( V_9 < V_30 )
V_28 = & V_31 ;
else if ( V_9 < V_32 )
V_28 = & V_33 ;
else
V_28 = & V_34 ;
F_35 ( & V_35 , V_29 ) ;
F_36 (sp, slob_list, list) {
#ifdef F_25
if ( V_17 != - 1 && F_37 ( & V_3 -> V_2 ) != V_17 )
continue;
#endif
if ( V_3 -> V_14 < F_32 ( V_9 ) )
continue;
V_23 = V_3 -> V_7 . V_23 ;
V_18 = F_31 ( V_3 , V_9 , V_22 ) ;
if ( ! V_18 )
continue;
if ( V_23 != V_28 -> V_23 &&
V_28 -> V_10 != V_23 -> V_10 )
F_38 ( V_28 , V_23 -> V_10 ) ;
break;
}
F_39 ( & V_35 , V_29 ) ;
if ( ! V_18 ) {
V_18 = F_24 ( V_15 & ~ V_36 , 0 , V_17 ) ;
if ( ! V_18 )
return NULL ;
V_3 = V_1 ( V_18 ) ;
F_7 ( V_3 ) ;
F_35 ( & V_35 , V_29 ) ;
V_3 -> V_14 = F_32 ( V_37 ) ;
V_3 -> free = V_18 ;
F_40 ( & V_3 -> V_7 ) ;
F_20 ( V_18 , F_32 ( V_37 ) , V_18 + F_32 ( V_37 ) ) ;
F_14 ( V_3 , V_28 ) ;
V_18 = F_31 ( V_3 , V_9 , V_22 ) ;
F_41 ( ! V_18 ) ;
F_39 ( & V_35 , V_29 ) ;
}
if ( F_42 ( ( V_15 & V_36 ) && V_18 ) )
memset ( V_18 , 0 , V_9 ) ;
return V_18 ;
}
static void F_43 ( void * V_38 , int V_9 )
{
struct V_1 * V_3 ;
T_1 * V_23 , * V_10 , * V_18 = ( T_1 * ) V_38 ;
T_2 V_14 ;
unsigned long V_29 ;
struct V_6 * V_28 ;
if ( F_42 ( F_44 ( V_38 ) ) )
return;
F_41 ( ! V_9 ) ;
V_3 = V_1 ( V_38 ) ;
V_14 = F_32 ( V_9 ) ;
F_35 ( & V_35 , V_29 ) ;
if ( V_3 -> V_14 + V_14 == F_32 ( V_37 ) ) {
if ( F_12 ( V_3 ) )
F_17 ( V_3 ) ;
F_39 ( & V_35 , V_29 ) ;
F_9 ( V_3 ) ;
F_3 ( V_3 ) ;
F_29 ( V_18 , 0 ) ;
return;
}
if ( ! F_12 ( V_3 ) ) {
V_3 -> V_14 = V_14 ;
V_3 -> free = V_18 ;
F_20 ( V_18 , V_14 ,
( void * ) ( ( unsigned long ) ( V_18 +
F_32 ( V_37 ) ) & V_12 ) ) ;
if ( V_9 < V_30 )
V_28 = & V_31 ;
else if ( V_9 < V_32 )
V_28 = & V_33 ;
else
V_28 = & V_34 ;
F_14 ( V_3 , V_28 ) ;
goto V_39;
}
V_3 -> V_14 += V_14 ;
if ( V_18 < V_3 -> free ) {
if ( V_18 + V_14 == V_3 -> free ) {
V_14 += F_21 ( V_3 -> free ) ;
V_3 -> free = F_22 ( V_3 -> free ) ;
}
F_20 ( V_18 , V_14 , V_3 -> free ) ;
V_3 -> free = V_18 ;
} else {
V_23 = V_3 -> free ;
V_10 = F_22 ( V_23 ) ;
while ( V_18 > V_10 ) {
V_23 = V_10 ;
V_10 = F_22 ( V_23 ) ;
}
if ( ! F_23 ( V_23 ) && V_18 + V_14 == V_10 ) {
V_14 += F_21 ( V_10 ) ;
F_20 ( V_18 , V_14 , F_22 ( V_10 ) ) ;
} else
F_20 ( V_18 , V_14 , V_10 ) ;
if ( V_23 + F_21 ( V_23 ) == V_18 ) {
V_14 = F_21 ( V_18 ) + F_21 ( V_23 ) ;
F_20 ( V_23 , V_14 , F_22 ( V_18 ) ) ;
} else
F_20 ( V_23 , F_21 ( V_23 ) , V_18 ) ;
}
V_39:
F_39 ( & V_35 , V_29 ) ;
}
void * F_45 ( T_4 V_9 , T_3 V_15 , int V_17 )
{
unsigned int * V_40 ;
int V_22 = F_46 ( V_41 , V_42 ) ;
void * V_43 ;
V_15 &= V_44 ;
F_47 ( V_15 ) ;
if ( V_9 < V_37 - V_22 ) {
if ( ! V_9 )
return V_45 ;
V_40 = F_34 ( V_9 + V_22 , V_15 , V_22 , V_17 ) ;
if ( ! V_40 )
return NULL ;
* V_40 = V_9 ;
V_43 = ( void * ) V_40 + V_22 ;
F_48 ( V_46 , V_43 ,
V_9 , V_9 + V_22 , V_15 , V_17 ) ;
} else {
unsigned int V_16 = F_49 ( V_9 ) ;
if ( F_50 ( V_16 ) )
V_15 |= V_47 ;
V_43 = F_24 ( V_15 , V_16 , V_17 ) ;
if ( V_43 ) {
struct V_2 * V_2 ;
V_2 = F_11 ( V_43 ) ;
V_2 -> V_48 = V_9 ;
}
F_48 ( V_46 , V_43 ,
V_9 , V_37 << V_16 , V_15 , V_17 ) ;
}
F_51 ( V_43 , V_9 , 1 , V_15 ) ;
return V_43 ;
}
void F_52 ( const void * V_38 )
{
struct V_1 * V_3 ;
F_53 ( V_46 , V_38 ) ;
if ( F_42 ( F_44 ( V_38 ) ) )
return;
F_54 ( V_38 ) ;
V_3 = V_1 ( V_38 ) ;
if ( F_5 ( V_3 ) ) {
int V_22 = F_46 ( V_41 , V_42 ) ;
unsigned int * V_40 = ( unsigned int * ) ( V_38 - V_22 ) ;
F_43 ( V_40 , * V_40 + V_22 ) ;
} else
F_55 ( & V_3 -> V_2 ) ;
}
T_4 F_56 ( const void * V_38 )
{
struct V_1 * V_3 ;
F_41 ( ! V_38 ) ;
if ( F_42 ( V_38 == V_45 ) )
return 0 ;
V_3 = V_1 ( V_38 ) ;
if ( F_5 ( V_3 ) ) {
int V_22 = F_46 ( V_41 , V_42 ) ;
unsigned int * V_40 = ( unsigned int * ) ( V_38 - V_22 ) ;
return F_32 ( * V_40 ) * V_49 ;
} else
return V_3 -> V_2 . V_48 ;
}
struct V_50 * F_57 ( const char * V_51 , T_4 V_9 ,
T_4 V_22 , unsigned long V_29 , void (* F_58)( void * ) )
{
struct V_50 * V_52 ;
V_52 = F_34 ( sizeof( struct V_50 ) ,
V_53 , V_41 , - 1 ) ;
if ( V_52 ) {
V_52 -> V_51 = V_51 ;
V_52 -> V_9 = V_9 ;
if ( V_29 & V_54 ) {
V_52 -> V_9 += sizeof( struct V_55 ) ;
}
V_52 -> V_29 = V_29 ;
V_52 -> F_58 = F_58 ;
V_52 -> V_22 = ( V_29 & V_56 ) ? V_57 : 0 ;
if ( V_52 -> V_22 < V_42 )
V_52 -> V_22 = V_42 ;
if ( V_52 -> V_22 < V_22 )
V_52 -> V_22 = V_22 ;
} else if ( V_29 & V_58 )
F_59 ( L_1 , V_51 ) ;
F_51 ( V_52 , sizeof( struct V_50 ) , 1 , V_53 ) ;
return V_52 ;
}
void F_60 ( struct V_50 * V_52 )
{
F_54 ( V_52 ) ;
if ( V_52 -> V_29 & V_54 )
F_61 () ;
F_43 ( V_52 , sizeof( struct V_50 ) ) ;
}
void * F_62 ( struct V_50 * V_52 , T_3 V_29 , int V_17 )
{
void * V_18 ;
V_29 &= V_44 ;
F_47 ( V_29 ) ;
if ( V_52 -> V_9 < V_37 ) {
V_18 = F_34 ( V_52 -> V_9 , V_29 , V_52 -> V_22 , V_17 ) ;
F_63 ( V_46 , V_18 , V_52 -> V_9 ,
F_32 ( V_52 -> V_9 ) * V_49 ,
V_29 , V_17 ) ;
} else {
V_18 = F_24 ( V_29 , F_49 ( V_52 -> V_9 ) , V_17 ) ;
F_63 ( V_46 , V_18 , V_52 -> V_9 ,
V_37 << F_49 ( V_52 -> V_9 ) ,
V_29 , V_17 ) ;
}
if ( V_52 -> F_58 )
V_52 -> F_58 ( V_18 ) ;
F_64 ( V_18 , V_52 -> V_9 , 1 , V_52 -> V_29 , V_29 ) ;
return V_18 ;
}
static void F_65 ( void * V_18 , int V_9 )
{
if ( V_9 < V_37 )
F_43 ( V_18 , V_9 ) ;
else
F_29 ( V_18 , F_49 ( V_9 ) ) ;
}
static void F_66 ( struct V_59 * V_60 )
{
struct V_55 * V_55 = (struct V_55 * ) V_60 ;
void * V_18 = ( void * ) V_55 - ( V_55 -> V_9 - sizeof( struct V_55 ) ) ;
F_65 ( V_18 , V_55 -> V_9 ) ;
}
void F_67 ( struct V_50 * V_52 , void * V_18 )
{
F_68 ( V_18 , V_52 -> V_29 ) ;
if ( F_42 ( V_52 -> V_29 & V_54 ) ) {
struct V_55 * V_55 ;
V_55 = V_18 + ( V_52 -> V_9 - sizeof( struct V_55 ) ) ;
V_55 -> V_9 = V_52 -> V_9 ;
F_69 ( & V_55 -> V_60 , F_66 ) ;
} else {
F_65 ( V_18 , V_52 -> V_9 ) ;
}
F_70 ( V_46 , V_18 ) ;
}
unsigned int F_71 ( struct V_50 * V_52 )
{
return V_52 -> V_9 ;
}
int F_72 ( struct V_50 * V_61 )
{
return 0 ;
}
int F_73 ( void )
{
return V_62 ;
}
void T_5 F_74 ( void )
{
V_62 = 1 ;
}
void T_5 F_75 ( void )
{
}
