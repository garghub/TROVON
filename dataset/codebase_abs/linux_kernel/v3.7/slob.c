static inline int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) ;
}
static void F_3 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_4 ( & V_2 -> V_4 , V_4 ) ;
F_5 ( V_2 ) ;
}
static inline void F_6 ( struct V_1 * V_2 )
{
F_7 ( & V_2 -> V_4 ) ;
F_8 ( V_2 ) ;
}
static void F_9 ( T_1 * V_5 , T_2 V_6 , T_1 * V_7 )
{
T_1 * V_8 = ( T_1 * ) ( ( unsigned long ) V_5 & V_9 ) ;
T_2 V_10 = V_7 - V_8 ;
if ( V_6 > 1 ) {
V_5 [ 0 ] . V_11 = V_6 ;
V_5 [ 1 ] . V_11 = V_10 ;
} else
V_5 [ 0 ] . V_11 = - V_10 ;
}
static T_2 F_10 ( T_1 * V_5 )
{
if ( V_5 -> V_11 > 0 )
return V_5 -> V_11 ;
return 1 ;
}
static T_1 * F_11 ( T_1 * V_5 )
{
T_1 * V_8 = ( T_1 * ) ( ( unsigned long ) V_5 & V_9 ) ;
T_2 V_7 ;
if ( V_5 [ 0 ] . V_11 < 0 )
V_7 = - V_5 [ 0 ] . V_11 ;
else
V_7 = V_5 [ 1 ] . V_11 ;
return V_8 + V_7 ;
}
static int F_12 ( T_1 * V_5 )
{
return ! ( ( unsigned long ) F_11 ( V_5 ) & ~ V_9 ) ;
}
static void * F_13 ( T_3 V_12 , int V_13 , int V_14 )
{
void * V_1 ;
#ifdef F_14
if ( V_14 != V_15 )
V_1 = F_15 ( V_14 , V_12 , V_13 ) ;
else
#endif
V_1 = F_16 ( V_12 , V_13 ) ;
if ( ! V_1 )
return NULL ;
return F_17 ( V_1 ) ;
}
static void F_18 ( void * V_16 , int V_13 )
{
if ( V_17 -> V_18 )
V_17 -> V_18 -> V_19 += 1 << V_13 ;
F_19 ( ( unsigned long ) V_16 , V_13 ) ;
}
static void * F_20 ( struct V_1 * V_2 , T_4 V_6 , int V_20 )
{
T_1 * V_21 , * V_22 , * V_23 = NULL ;
int V_24 = 0 , V_11 = F_21 ( V_6 ) ;
for ( V_21 = NULL , V_22 = V_2 -> V_25 ; ; V_21 = V_22 , V_22 = F_11 ( V_22 ) ) {
T_2 V_26 = F_10 ( V_22 ) ;
if ( V_20 ) {
V_23 = ( T_1 * ) F_22 ( ( unsigned long ) V_22 , V_20 ) ;
V_24 = V_23 - V_22 ;
}
if ( V_26 >= V_11 + V_24 ) {
T_1 * V_7 ;
if ( V_24 ) {
V_7 = F_11 ( V_22 ) ;
F_9 ( V_23 , V_26 - V_24 , V_7 ) ;
F_9 ( V_22 , V_24 , V_23 ) ;
V_21 = V_22 ;
V_22 = V_23 ;
V_26 = F_10 ( V_22 ) ;
}
V_7 = F_11 ( V_22 ) ;
if ( V_26 == V_11 ) {
if ( V_21 )
F_9 ( V_21 , F_10 ( V_21 ) , V_7 ) ;
else
V_2 -> V_25 = V_7 ;
} else {
if ( V_21 )
F_9 ( V_21 , F_10 ( V_21 ) , V_22 + V_11 ) ;
else
V_2 -> V_25 = V_22 + V_11 ;
F_9 ( V_22 + V_11 , V_26 - V_11 , V_7 ) ;
}
V_2 -> V_11 -= V_11 ;
if ( ! V_2 -> V_11 )
F_6 ( V_2 ) ;
return V_22 ;
}
if ( F_12 ( V_22 ) )
return NULL ;
}
}
static void * F_23 ( T_4 V_6 , T_3 V_12 , int V_20 , int V_14 )
{
struct V_1 * V_2 ;
struct V_3 * V_21 ;
struct V_3 * V_27 ;
T_1 * V_16 = NULL ;
unsigned long V_28 ;
if ( V_6 < V_29 )
V_27 = & V_30 ;
else if ( V_6 < V_31 )
V_27 = & V_32 ;
else
V_27 = & V_33 ;
F_24 ( & V_34 , V_28 ) ;
F_25 (sp, slob_list, list) {
#ifdef F_14
if ( V_14 != V_15 && F_26 ( V_2 ) != V_14 )
continue;
#endif
if ( V_2 -> V_11 < F_21 ( V_6 ) )
continue;
V_21 = V_2 -> V_4 . V_21 ;
V_16 = F_20 ( V_2 , V_6 , V_20 ) ;
if ( ! V_16 )
continue;
if ( V_21 != V_27 -> V_21 &&
V_27 -> V_7 != V_21 -> V_7 )
F_27 ( V_27 , V_21 -> V_7 ) ;
break;
}
F_28 ( & V_34 , V_28 ) ;
if ( ! V_16 ) {
V_16 = F_13 ( V_12 & ~ V_35 , 0 , V_14 ) ;
if ( ! V_16 )
return NULL ;
V_2 = F_29 ( V_16 ) ;
F_30 ( V_2 ) ;
F_24 ( & V_34 , V_28 ) ;
V_2 -> V_11 = F_21 ( V_36 ) ;
V_2 -> V_25 = V_16 ;
F_31 ( & V_2 -> V_4 ) ;
F_9 ( V_16 , F_21 ( V_36 ) , V_16 + F_21 ( V_36 ) ) ;
F_3 ( V_2 , V_27 ) ;
V_16 = F_20 ( V_2 , V_6 , V_20 ) ;
F_32 ( ! V_16 ) ;
F_28 ( & V_34 , V_28 ) ;
}
if ( F_33 ( ( V_12 & V_35 ) && V_16 ) )
memset ( V_16 , 0 , V_6 ) ;
return V_16 ;
}
static void F_34 ( void * V_37 , int V_6 )
{
struct V_1 * V_2 ;
T_1 * V_21 , * V_7 , * V_16 = ( T_1 * ) V_37 ;
T_2 V_11 ;
unsigned long V_28 ;
struct V_3 * V_27 ;
if ( F_33 ( F_35 ( V_37 ) ) )
return;
F_32 ( ! V_6 ) ;
V_2 = F_29 ( V_37 ) ;
V_11 = F_21 ( V_6 ) ;
F_24 ( & V_34 , V_28 ) ;
if ( V_2 -> V_11 + V_11 == F_21 ( V_36 ) ) {
if ( F_1 ( V_2 ) )
F_6 ( V_2 ) ;
F_28 ( & V_34 , V_28 ) ;
F_36 ( V_2 ) ;
F_37 ( V_2 ) ;
F_18 ( V_16 , 0 ) ;
return;
}
if ( ! F_1 ( V_2 ) ) {
V_2 -> V_11 = V_11 ;
V_2 -> V_25 = V_16 ;
F_9 ( V_16 , V_11 ,
( void * ) ( ( unsigned long ) ( V_16 +
F_21 ( V_36 ) ) & V_9 ) ) ;
if ( V_6 < V_29 )
V_27 = & V_30 ;
else if ( V_6 < V_31 )
V_27 = & V_32 ;
else
V_27 = & V_33 ;
F_3 ( V_2 , V_27 ) ;
goto V_38;
}
V_2 -> V_11 += V_11 ;
if ( V_16 < ( T_1 * ) V_2 -> V_25 ) {
if ( V_16 + V_11 == V_2 -> V_25 ) {
V_11 += F_10 ( V_2 -> V_25 ) ;
V_2 -> V_25 = F_11 ( V_2 -> V_25 ) ;
}
F_9 ( V_16 , V_11 , V_2 -> V_25 ) ;
V_2 -> V_25 = V_16 ;
} else {
V_21 = V_2 -> V_25 ;
V_7 = F_11 ( V_21 ) ;
while ( V_16 > V_7 ) {
V_21 = V_7 ;
V_7 = F_11 ( V_21 ) ;
}
if ( ! F_12 ( V_21 ) && V_16 + V_11 == V_7 ) {
V_11 += F_10 ( V_7 ) ;
F_9 ( V_16 , V_11 , F_11 ( V_7 ) ) ;
} else
F_9 ( V_16 , V_11 , V_7 ) ;
if ( V_21 + F_10 ( V_21 ) == V_16 ) {
V_11 = F_10 ( V_16 ) + F_10 ( V_21 ) ;
F_9 ( V_21 , V_11 , F_11 ( V_16 ) ) ;
} else
F_9 ( V_21 , F_10 ( V_21 ) , V_16 ) ;
}
V_38:
F_28 ( & V_34 , V_28 ) ;
}
static T_5 void *
F_38 ( T_4 V_6 , T_3 V_12 , int V_14 , unsigned long V_39 )
{
unsigned int * V_40 ;
int V_20 = F_39 ( T_4 , V_41 , V_42 ) ;
void * V_43 ;
V_12 &= V_44 ;
F_40 ( V_12 ) ;
if ( V_6 < V_36 - V_20 ) {
if ( ! V_6 )
return V_45 ;
V_40 = F_23 ( V_6 + V_20 , V_12 , V_20 , V_14 ) ;
if ( ! V_40 )
return NULL ;
* V_40 = V_6 ;
V_43 = ( void * ) V_40 + V_20 ;
F_41 ( V_39 , V_43 ,
V_6 , V_6 + V_20 , V_12 , V_14 ) ;
} else {
unsigned int V_13 = F_42 ( V_6 ) ;
if ( F_43 ( V_13 ) )
V_12 |= V_46 ;
V_43 = F_13 ( V_12 , V_13 , V_14 ) ;
if ( V_43 ) {
struct V_1 * V_1 ;
V_1 = F_29 ( V_43 ) ;
V_1 -> V_47 = V_6 ;
}
F_41 ( V_39 , V_43 ,
V_6 , V_36 << V_13 , V_12 , V_14 ) ;
}
F_44 ( V_43 , V_6 , 1 , V_12 ) ;
return V_43 ;
}
void * F_45 ( T_4 V_6 , T_3 V_12 , int V_14 )
{
return F_38 ( V_6 , V_12 , V_14 , V_48 ) ;
}
void * F_46 ( T_4 V_6 , T_3 V_12 , unsigned long V_39 )
{
return F_38 ( V_6 , V_12 , V_15 , V_39 ) ;
}
void * F_47 ( T_4 V_6 , T_3 V_12 ,
int V_14 , unsigned long V_39 )
{
return F_38 ( V_6 , V_12 , V_14 , V_39 ) ;
}
void F_48 ( const void * V_37 )
{
struct V_1 * V_2 ;
F_49 ( V_48 , V_37 ) ;
if ( F_33 ( F_35 ( V_37 ) ) )
return;
F_50 ( V_37 ) ;
V_2 = F_29 ( V_37 ) ;
if ( F_51 ( V_2 ) ) {
int V_20 = F_39 ( T_4 , V_41 , V_42 ) ;
unsigned int * V_40 = ( unsigned int * ) ( V_37 - V_20 ) ;
F_34 ( V_40 , * V_40 + V_20 ) ;
} else
F_52 ( V_2 ) ;
}
T_4 F_53 ( const void * V_37 )
{
struct V_1 * V_2 ;
F_32 ( ! V_37 ) ;
if ( F_33 ( V_37 == V_45 ) )
return 0 ;
V_2 = F_29 ( V_37 ) ;
if ( F_51 ( V_2 ) ) {
int V_20 = F_39 ( T_4 , V_41 , V_42 ) ;
unsigned int * V_40 = ( unsigned int * ) ( V_37 - V_20 ) ;
return F_21 ( * V_40 ) * V_49 ;
} else
return V_2 -> V_47 ;
}
int F_54 ( struct V_50 * V_51 , unsigned long V_28 )
{
T_4 V_20 = V_51 -> V_6 ;
if ( V_28 & V_52 ) {
V_51 -> V_6 += sizeof( struct V_53 ) ;
}
V_51 -> V_28 = V_28 ;
V_51 -> V_20 = ( V_28 & V_54 ) ? V_55 : 0 ;
if ( V_51 -> V_20 < V_42 )
V_51 -> V_20 = V_42 ;
if ( V_51 -> V_20 < V_20 )
V_51 -> V_20 = V_20 ;
return 0 ;
}
void * F_55 ( struct V_50 * V_51 , T_3 V_28 , int V_14 )
{
void * V_16 ;
V_28 &= V_44 ;
F_40 ( V_28 ) ;
if ( V_51 -> V_6 < V_36 ) {
V_16 = F_23 ( V_51 -> V_6 , V_28 , V_51 -> V_20 , V_14 ) ;
F_56 ( V_48 , V_16 , V_51 -> V_6 ,
F_21 ( V_51 -> V_6 ) * V_49 ,
V_28 , V_14 ) ;
} else {
V_16 = F_13 ( V_28 , F_42 ( V_51 -> V_6 ) , V_14 ) ;
F_56 ( V_48 , V_16 , V_51 -> V_6 ,
V_36 << F_42 ( V_51 -> V_6 ) ,
V_28 , V_14 ) ;
}
if ( V_51 -> V_56 )
V_51 -> V_56 ( V_16 ) ;
F_57 ( V_16 , V_51 -> V_6 , 1 , V_51 -> V_28 , V_28 ) ;
return V_16 ;
}
static void F_58 ( void * V_16 , int V_6 )
{
if ( V_6 < V_36 )
F_34 ( V_16 , V_6 ) ;
else
F_18 ( V_16 , F_42 ( V_6 ) ) ;
}
static void F_59 ( struct V_57 * V_58 )
{
struct V_53 * V_53 = (struct V_53 * ) V_58 ;
void * V_16 = ( void * ) V_53 - ( V_53 -> V_6 - sizeof( struct V_53 ) ) ;
F_58 ( V_16 , V_53 -> V_6 ) ;
}
void F_60 ( struct V_50 * V_51 , void * V_16 )
{
F_61 ( V_16 , V_51 -> V_28 ) ;
if ( F_33 ( V_51 -> V_28 & V_52 ) ) {
struct V_53 * V_53 ;
V_53 = V_16 + ( V_51 -> V_6 - sizeof( struct V_53 ) ) ;
V_53 -> V_6 = V_51 -> V_6 ;
F_62 ( & V_53 -> V_58 , F_59 ) ;
} else {
F_58 ( V_16 , V_51 -> V_6 ) ;
}
F_63 ( V_48 , V_16 ) ;
}
unsigned int F_64 ( struct V_50 * V_51 )
{
return V_51 -> V_6 ;
}
int F_65 ( struct V_50 * V_51 )
{
return 0 ;
}
int F_66 ( struct V_50 * V_59 )
{
return 0 ;
}
void T_6 F_67 ( void )
{
V_50 = & V_60 ;
V_61 = V_62 ;
}
void T_6 F_68 ( void )
{
V_61 = V_63 ;
}
