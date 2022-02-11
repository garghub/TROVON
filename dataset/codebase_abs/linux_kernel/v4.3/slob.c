static inline int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) ;
}
static void F_3 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_4 ( & V_2 -> V_5 , V_4 ) ;
F_5 ( V_2 ) ;
}
static inline void F_6 ( struct V_1 * V_2 )
{
F_7 ( & V_2 -> V_5 ) ;
F_8 ( V_2 ) ;
}
static void F_9 ( T_1 * V_6 , T_2 V_7 , T_1 * V_8 )
{
T_1 * V_9 = ( T_1 * ) ( ( unsigned long ) V_6 & V_10 ) ;
T_2 V_11 = V_8 - V_9 ;
if ( V_7 > 1 ) {
V_6 [ 0 ] . V_12 = V_7 ;
V_6 [ 1 ] . V_12 = V_11 ;
} else
V_6 [ 0 ] . V_12 = - V_11 ;
}
static T_2 F_10 ( T_1 * V_6 )
{
if ( V_6 -> V_12 > 0 )
return V_6 -> V_12 ;
return 1 ;
}
static T_1 * F_11 ( T_1 * V_6 )
{
T_1 * V_9 = ( T_1 * ) ( ( unsigned long ) V_6 & V_10 ) ;
T_2 V_8 ;
if ( V_6 [ 0 ] . V_12 < 0 )
V_8 = - V_6 [ 0 ] . V_12 ;
else
V_8 = V_6 [ 1 ] . V_12 ;
return V_9 + V_8 ;
}
static int F_12 ( T_1 * V_6 )
{
return ! ( ( unsigned long ) F_11 ( V_6 ) & ~ V_10 ) ;
}
static void * F_13 ( T_3 V_13 , int V_14 , int V_15 )
{
void * V_1 ;
#ifdef F_14
if ( V_15 != V_16 )
V_1 = F_15 ( V_15 , V_13 , V_14 ) ;
else
#endif
V_1 = F_16 ( V_13 , V_14 ) ;
if ( ! V_1 )
return NULL ;
return F_17 ( V_1 ) ;
}
static void F_18 ( void * V_17 , int V_14 )
{
if ( V_18 -> V_19 )
V_18 -> V_19 -> V_20 += 1 << V_14 ;
F_19 ( ( unsigned long ) V_17 , V_14 ) ;
}
static void * F_20 ( struct V_1 * V_2 , T_4 V_7 , int V_21 )
{
T_1 * V_22 , * V_23 , * V_24 = NULL ;
int V_25 = 0 , V_12 = F_21 ( V_7 ) ;
for ( V_22 = NULL , V_23 = V_2 -> V_26 ; ; V_22 = V_23 , V_23 = F_11 ( V_23 ) ) {
T_2 V_27 = F_10 ( V_23 ) ;
if ( V_21 ) {
V_24 = ( T_1 * ) F_22 ( ( unsigned long ) V_23 , V_21 ) ;
V_25 = V_24 - V_23 ;
}
if ( V_27 >= V_12 + V_25 ) {
T_1 * V_8 ;
if ( V_25 ) {
V_8 = F_11 ( V_23 ) ;
F_9 ( V_24 , V_27 - V_25 , V_8 ) ;
F_9 ( V_23 , V_25 , V_24 ) ;
V_22 = V_23 ;
V_23 = V_24 ;
V_27 = F_10 ( V_23 ) ;
}
V_8 = F_11 ( V_23 ) ;
if ( V_27 == V_12 ) {
if ( V_22 )
F_9 ( V_22 , F_10 ( V_22 ) , V_8 ) ;
else
V_2 -> V_26 = V_8 ;
} else {
if ( V_22 )
F_9 ( V_22 , F_10 ( V_22 ) , V_23 + V_12 ) ;
else
V_2 -> V_26 = V_23 + V_12 ;
F_9 ( V_23 + V_12 , V_27 - V_12 , V_8 ) ;
}
V_2 -> V_12 -= V_12 ;
if ( ! V_2 -> V_12 )
F_6 ( V_2 ) ;
return V_23 ;
}
if ( F_12 ( V_23 ) )
return NULL ;
}
}
static void * F_23 ( T_4 V_7 , T_3 V_13 , int V_21 , int V_15 )
{
struct V_1 * V_2 ;
struct V_3 * V_22 ;
struct V_3 * V_28 ;
T_1 * V_17 = NULL ;
unsigned long V_29 ;
if ( V_7 < V_30 )
V_28 = & V_31 ;
else if ( V_7 < V_32 )
V_28 = & V_33 ;
else
V_28 = & V_34 ;
F_24 ( & V_35 , V_29 ) ;
F_25 (sp, slob_list, lru) {
#ifdef F_14
if ( V_15 != V_16 && F_26 ( V_2 ) != V_15 )
continue;
#endif
if ( V_2 -> V_12 < F_21 ( V_7 ) )
continue;
V_22 = V_2 -> V_5 . V_22 ;
V_17 = F_20 ( V_2 , V_7 , V_21 ) ;
if ( ! V_17 )
continue;
if ( V_22 != V_28 -> V_22 &&
V_28 -> V_8 != V_22 -> V_8 )
F_27 ( V_28 , V_22 -> V_8 ) ;
break;
}
F_28 ( & V_35 , V_29 ) ;
if ( ! V_17 ) {
V_17 = F_13 ( V_13 & ~ V_36 , 0 , V_15 ) ;
if ( ! V_17 )
return NULL ;
V_2 = F_29 ( V_17 ) ;
F_30 ( V_2 ) ;
F_24 ( & V_35 , V_29 ) ;
V_2 -> V_12 = F_21 ( V_37 ) ;
V_2 -> V_26 = V_17 ;
F_31 ( & V_2 -> V_5 ) ;
F_9 ( V_17 , F_21 ( V_37 ) , V_17 + F_21 ( V_37 ) ) ;
F_3 ( V_2 , V_28 ) ;
V_17 = F_20 ( V_2 , V_7 , V_21 ) ;
F_32 ( ! V_17 ) ;
F_28 ( & V_35 , V_29 ) ;
}
if ( F_33 ( ( V_13 & V_36 ) && V_17 ) )
memset ( V_17 , 0 , V_7 ) ;
return V_17 ;
}
static void F_34 ( void * V_38 , int V_7 )
{
struct V_1 * V_2 ;
T_1 * V_22 , * V_8 , * V_17 = ( T_1 * ) V_38 ;
T_2 V_12 ;
unsigned long V_29 ;
struct V_3 * V_28 ;
if ( F_33 ( F_35 ( V_38 ) ) )
return;
F_32 ( ! V_7 ) ;
V_2 = F_29 ( V_38 ) ;
V_12 = F_21 ( V_7 ) ;
F_24 ( & V_35 , V_29 ) ;
if ( V_2 -> V_12 + V_12 == F_21 ( V_37 ) ) {
if ( F_1 ( V_2 ) )
F_6 ( V_2 ) ;
F_28 ( & V_35 , V_29 ) ;
F_36 ( V_2 ) ;
F_37 ( V_2 ) ;
F_18 ( V_17 , 0 ) ;
return;
}
if ( ! F_1 ( V_2 ) ) {
V_2 -> V_12 = V_12 ;
V_2 -> V_26 = V_17 ;
F_9 ( V_17 , V_12 ,
( void * ) ( ( unsigned long ) ( V_17 +
F_21 ( V_37 ) ) & V_10 ) ) ;
if ( V_7 < V_30 )
V_28 = & V_31 ;
else if ( V_7 < V_32 )
V_28 = & V_33 ;
else
V_28 = & V_34 ;
F_3 ( V_2 , V_28 ) ;
goto V_39;
}
V_2 -> V_12 += V_12 ;
if ( V_17 < ( T_1 * ) V_2 -> V_26 ) {
if ( V_17 + V_12 == V_2 -> V_26 ) {
V_12 += F_10 ( V_2 -> V_26 ) ;
V_2 -> V_26 = F_11 ( V_2 -> V_26 ) ;
}
F_9 ( V_17 , V_12 , V_2 -> V_26 ) ;
V_2 -> V_26 = V_17 ;
} else {
V_22 = V_2 -> V_26 ;
V_8 = F_11 ( V_22 ) ;
while ( V_17 > V_8 ) {
V_22 = V_8 ;
V_8 = F_11 ( V_22 ) ;
}
if ( ! F_12 ( V_22 ) && V_17 + V_12 == V_8 ) {
V_12 += F_10 ( V_8 ) ;
F_9 ( V_17 , V_12 , F_11 ( V_8 ) ) ;
} else
F_9 ( V_17 , V_12 , V_8 ) ;
if ( V_22 + F_10 ( V_22 ) == V_17 ) {
V_12 = F_10 ( V_17 ) + F_10 ( V_22 ) ;
F_9 ( V_22 , V_12 , F_11 ( V_17 ) ) ;
} else
F_9 ( V_22 , F_10 ( V_22 ) , V_17 ) ;
}
V_39:
F_28 ( & V_35 , V_29 ) ;
}
static T_5 void *
F_38 ( T_4 V_7 , T_3 V_13 , int V_15 , unsigned long V_40 )
{
unsigned int * V_41 ;
int V_21 = F_39 ( T_4 , V_42 , V_43 ) ;
void * V_44 ;
V_13 &= V_45 ;
F_40 ( V_13 ) ;
if ( V_7 < V_37 - V_21 ) {
if ( ! V_7 )
return V_46 ;
V_41 = F_23 ( V_7 + V_21 , V_13 , V_21 , V_15 ) ;
if ( ! V_41 )
return NULL ;
* V_41 = V_7 ;
V_44 = ( void * ) V_41 + V_21 ;
F_41 ( V_40 , V_44 ,
V_7 , V_7 + V_21 , V_13 , V_15 ) ;
} else {
unsigned int V_14 = F_42 ( V_7 ) ;
if ( F_43 ( V_14 ) )
V_13 |= V_47 ;
V_44 = F_13 ( V_13 , V_14 , V_15 ) ;
F_41 ( V_40 , V_44 ,
V_7 , V_37 << V_14 , V_13 , V_15 ) ;
}
F_44 ( V_44 , V_7 , 1 , V_13 ) ;
return V_44 ;
}
void * F_45 ( T_4 V_7 , T_3 V_13 )
{
return F_38 ( V_7 , V_13 , V_16 , V_48 ) ;
}
void * F_46 ( T_4 V_7 , T_3 V_13 , unsigned long V_40 )
{
return F_38 ( V_7 , V_13 , V_16 , V_40 ) ;
}
void * F_47 ( T_4 V_7 , T_3 V_13 ,
int V_15 , unsigned long V_40 )
{
return F_38 ( V_7 , V_13 , V_15 , V_40 ) ;
}
void F_48 ( const void * V_38 )
{
struct V_1 * V_2 ;
F_49 ( V_48 , V_38 ) ;
if ( F_33 ( F_35 ( V_38 ) ) )
return;
F_50 ( V_38 ) ;
V_2 = F_29 ( V_38 ) ;
if ( F_51 ( V_2 ) ) {
int V_21 = F_39 ( T_4 , V_42 , V_43 ) ;
unsigned int * V_41 = ( unsigned int * ) ( V_38 - V_21 ) ;
F_34 ( V_41 , * V_41 + V_21 ) ;
} else
F_52 ( V_2 , F_53 ( V_2 ) ) ;
}
T_4 F_54 ( const void * V_38 )
{
struct V_1 * V_2 ;
int V_21 ;
unsigned int * V_41 ;
F_32 ( ! V_38 ) ;
if ( F_33 ( V_38 == V_46 ) )
return 0 ;
V_2 = F_29 ( V_38 ) ;
if ( F_33 ( ! F_51 ( V_2 ) ) )
return V_37 << F_53 ( V_2 ) ;
V_21 = F_39 ( T_4 , V_42 , V_43 ) ;
V_41 = ( unsigned int * ) ( V_38 - V_21 ) ;
return F_21 ( * V_41 ) * V_49 ;
}
int F_55 ( struct V_50 * V_51 , unsigned long V_29 )
{
if ( V_29 & V_52 ) {
V_51 -> V_7 += sizeof( struct V_53 ) ;
}
V_51 -> V_29 = V_29 ;
return 0 ;
}
static void * F_56 ( struct V_50 * V_51 , T_3 V_29 , int V_15 )
{
void * V_17 ;
V_29 &= V_45 ;
F_40 ( V_29 ) ;
if ( V_51 -> V_7 < V_37 ) {
V_17 = F_23 ( V_51 -> V_7 , V_29 , V_51 -> V_21 , V_15 ) ;
F_57 ( V_48 , V_17 , V_51 -> V_54 ,
F_21 ( V_51 -> V_7 ) * V_49 ,
V_29 , V_15 ) ;
} else {
V_17 = F_13 ( V_29 , F_42 ( V_51 -> V_7 ) , V_15 ) ;
F_57 ( V_48 , V_17 , V_51 -> V_54 ,
V_37 << F_42 ( V_51 -> V_7 ) ,
V_29 , V_15 ) ;
}
if ( V_17 && V_51 -> V_55 )
V_51 -> V_55 ( V_17 ) ;
F_58 ( V_17 , V_51 -> V_7 , 1 , V_51 -> V_29 , V_29 ) ;
return V_17 ;
}
void * F_59 ( struct V_50 * V_56 , T_3 V_29 )
{
return F_56 ( V_56 , V_29 , V_16 ) ;
}
void * F_60 ( T_4 V_7 , T_3 V_13 , int V_15 )
{
return F_38 ( V_7 , V_13 , V_15 , V_48 ) ;
}
void * F_61 ( struct V_50 * V_56 , T_3 V_13 , int V_15 )
{
return F_56 ( V_56 , V_13 , V_15 ) ;
}
static void F_62 ( void * V_17 , int V_7 )
{
if ( V_7 < V_37 )
F_34 ( V_17 , V_7 ) ;
else
F_18 ( V_17 , F_42 ( V_7 ) ) ;
}
static void F_63 ( struct V_57 * V_58 )
{
struct V_53 * V_53 = (struct V_53 * ) V_58 ;
void * V_17 = ( void * ) V_53 - ( V_53 -> V_7 - sizeof( struct V_53 ) ) ;
F_62 ( V_17 , V_53 -> V_7 ) ;
}
void F_64 ( struct V_50 * V_51 , void * V_17 )
{
F_65 ( V_17 , V_51 -> V_29 ) ;
if ( F_33 ( V_51 -> V_29 & V_52 ) ) {
struct V_53 * V_53 ;
V_53 = V_17 + ( V_51 -> V_7 - sizeof( struct V_53 ) ) ;
V_53 -> V_7 = V_51 -> V_7 ;
F_66 ( & V_53 -> V_58 , F_63 ) ;
} else {
F_62 ( V_17 , V_51 -> V_7 ) ;
}
F_67 ( V_48 , V_17 ) ;
}
void F_68 ( struct V_50 * V_6 , T_4 V_7 , void * * V_59 )
{
F_69 ( V_6 , V_7 , V_59 ) ;
}
bool F_70 ( struct V_50 * V_6 , T_3 V_29 , T_4 V_7 ,
void * * V_59 )
{
return F_71 ( V_6 , V_29 , V_7 , V_59 ) ;
}
int F_72 ( struct V_50 * V_51 )
{
return 0 ;
}
int F_73 ( struct V_50 * V_60 , bool V_61 )
{
return 0 ;
}
void T_6 F_74 ( void )
{
V_50 = & V_62 ;
V_63 = V_64 ;
}
void T_6 F_75 ( void )
{
V_63 = V_65 ;
}
