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
if ( V_14 != - 1 )
V_1 = F_15 ( V_14 , V_12 , V_13 ) ;
else
#endif
V_1 = F_16 ( V_12 , V_13 ) ;
if ( ! V_1 )
return NULL ;
return F_17 ( V_1 ) ;
}
static void F_18 ( void * V_15 , int V_13 )
{
if ( V_16 -> V_17 )
V_16 -> V_17 -> V_18 += 1 << V_13 ;
F_19 ( ( unsigned long ) V_15 , V_13 ) ;
}
static void * F_20 ( struct V_1 * V_2 , T_4 V_6 , int V_19 )
{
T_1 * V_20 , * V_21 , * V_22 = NULL ;
int V_23 = 0 , V_11 = F_21 ( V_6 ) ;
for ( V_20 = NULL , V_21 = V_2 -> V_24 ; ; V_20 = V_21 , V_21 = F_11 ( V_21 ) ) {
T_2 V_25 = F_10 ( V_21 ) ;
if ( V_19 ) {
V_22 = ( T_1 * ) F_22 ( ( unsigned long ) V_21 , V_19 ) ;
V_23 = V_22 - V_21 ;
}
if ( V_25 >= V_11 + V_23 ) {
T_1 * V_7 ;
if ( V_23 ) {
V_7 = F_11 ( V_21 ) ;
F_9 ( V_22 , V_25 - V_23 , V_7 ) ;
F_9 ( V_21 , V_23 , V_22 ) ;
V_20 = V_21 ;
V_21 = V_22 ;
V_25 = F_10 ( V_21 ) ;
}
V_7 = F_11 ( V_21 ) ;
if ( V_25 == V_11 ) {
if ( V_20 )
F_9 ( V_20 , F_10 ( V_20 ) , V_7 ) ;
else
V_2 -> V_24 = V_7 ;
} else {
if ( V_20 )
F_9 ( V_20 , F_10 ( V_20 ) , V_21 + V_11 ) ;
else
V_2 -> V_24 = V_21 + V_11 ;
F_9 ( V_21 + V_11 , V_25 - V_11 , V_7 ) ;
}
V_2 -> V_11 -= V_11 ;
if ( ! V_2 -> V_11 )
F_6 ( V_2 ) ;
return V_21 ;
}
if ( F_12 ( V_21 ) )
return NULL ;
}
}
static void * F_23 ( T_4 V_6 , T_3 V_12 , int V_19 , int V_14 )
{
struct V_1 * V_2 ;
struct V_3 * V_20 ;
struct V_3 * V_26 ;
T_1 * V_15 = NULL ;
unsigned long V_27 ;
if ( V_6 < V_28 )
V_26 = & V_29 ;
else if ( V_6 < V_30 )
V_26 = & V_31 ;
else
V_26 = & V_32 ;
F_24 ( & V_33 , V_27 ) ;
F_25 (sp, slob_list, list) {
#ifdef F_14
if ( V_14 != - 1 && F_26 ( V_2 ) != V_14 )
continue;
#endif
if ( V_2 -> V_11 < F_21 ( V_6 ) )
continue;
V_20 = V_2 -> V_4 . V_20 ;
V_15 = F_20 ( V_2 , V_6 , V_19 ) ;
if ( ! V_15 )
continue;
if ( V_20 != V_26 -> V_20 &&
V_26 -> V_7 != V_20 -> V_7 )
F_27 ( V_26 , V_20 -> V_7 ) ;
break;
}
F_28 ( & V_33 , V_27 ) ;
if ( ! V_15 ) {
V_15 = F_13 ( V_12 & ~ V_34 , 0 , V_14 ) ;
if ( ! V_15 )
return NULL ;
V_2 = F_29 ( V_15 ) ;
F_30 ( V_2 ) ;
F_24 ( & V_33 , V_27 ) ;
V_2 -> V_11 = F_21 ( V_35 ) ;
V_2 -> V_24 = V_15 ;
F_31 ( & V_2 -> V_4 ) ;
F_9 ( V_15 , F_21 ( V_35 ) , V_15 + F_21 ( V_35 ) ) ;
F_3 ( V_2 , V_26 ) ;
V_15 = F_20 ( V_2 , V_6 , V_19 ) ;
F_32 ( ! V_15 ) ;
F_28 ( & V_33 , V_27 ) ;
}
if ( F_33 ( ( V_12 & V_34 ) && V_15 ) )
memset ( V_15 , 0 , V_6 ) ;
return V_15 ;
}
static void F_34 ( void * V_36 , int V_6 )
{
struct V_1 * V_2 ;
T_1 * V_20 , * V_7 , * V_15 = ( T_1 * ) V_36 ;
T_2 V_11 ;
unsigned long V_27 ;
struct V_3 * V_26 ;
if ( F_33 ( F_35 ( V_36 ) ) )
return;
F_32 ( ! V_6 ) ;
V_2 = F_29 ( V_36 ) ;
V_11 = F_21 ( V_6 ) ;
F_24 ( & V_33 , V_27 ) ;
if ( V_2 -> V_11 + V_11 == F_21 ( V_35 ) ) {
if ( F_1 ( V_2 ) )
F_6 ( V_2 ) ;
F_28 ( & V_33 , V_27 ) ;
F_36 ( V_2 ) ;
F_37 ( V_2 ) ;
F_18 ( V_15 , 0 ) ;
return;
}
if ( ! F_1 ( V_2 ) ) {
V_2 -> V_11 = V_11 ;
V_2 -> V_24 = V_15 ;
F_9 ( V_15 , V_11 ,
( void * ) ( ( unsigned long ) ( V_15 +
F_21 ( V_35 ) ) & V_9 ) ) ;
if ( V_6 < V_28 )
V_26 = & V_29 ;
else if ( V_6 < V_30 )
V_26 = & V_31 ;
else
V_26 = & V_32 ;
F_3 ( V_2 , V_26 ) ;
goto V_37;
}
V_2 -> V_11 += V_11 ;
if ( V_15 < ( T_1 * ) V_2 -> V_24 ) {
if ( V_15 + V_11 == V_2 -> V_24 ) {
V_11 += F_10 ( V_2 -> V_24 ) ;
V_2 -> V_24 = F_11 ( V_2 -> V_24 ) ;
}
F_9 ( V_15 , V_11 , V_2 -> V_24 ) ;
V_2 -> V_24 = V_15 ;
} else {
V_20 = V_2 -> V_24 ;
V_7 = F_11 ( V_20 ) ;
while ( V_15 > V_7 ) {
V_20 = V_7 ;
V_7 = F_11 ( V_20 ) ;
}
if ( ! F_12 ( V_20 ) && V_15 + V_11 == V_7 ) {
V_11 += F_10 ( V_7 ) ;
F_9 ( V_15 , V_11 , F_11 ( V_7 ) ) ;
} else
F_9 ( V_15 , V_11 , V_7 ) ;
if ( V_20 + F_10 ( V_20 ) == V_15 ) {
V_11 = F_10 ( V_15 ) + F_10 ( V_20 ) ;
F_9 ( V_20 , V_11 , F_11 ( V_15 ) ) ;
} else
F_9 ( V_20 , F_10 ( V_20 ) , V_15 ) ;
}
V_37:
F_28 ( & V_33 , V_27 ) ;
}
void * F_38 ( T_4 V_6 , T_3 V_12 , int V_14 )
{
unsigned int * V_38 ;
int V_19 = F_39 ( V_39 , V_40 ) ;
void * V_41 ;
V_12 &= V_42 ;
F_40 ( V_12 ) ;
if ( V_6 < V_35 - V_19 ) {
if ( ! V_6 )
return V_43 ;
V_38 = F_23 ( V_6 + V_19 , V_12 , V_19 , V_14 ) ;
if ( ! V_38 )
return NULL ;
* V_38 = V_6 ;
V_41 = ( void * ) V_38 + V_19 ;
F_41 ( V_44 , V_41 ,
V_6 , V_6 + V_19 , V_12 , V_14 ) ;
} else {
unsigned int V_13 = F_42 ( V_6 ) ;
if ( F_43 ( V_13 ) )
V_12 |= V_45 ;
V_41 = F_13 ( V_12 , V_13 , V_14 ) ;
if ( V_41 ) {
struct V_1 * V_1 ;
V_1 = F_29 ( V_41 ) ;
V_1 -> V_46 = V_6 ;
}
F_41 ( V_44 , V_41 ,
V_6 , V_35 << V_13 , V_12 , V_14 ) ;
}
F_44 ( V_41 , V_6 , 1 , V_12 ) ;
return V_41 ;
}
void F_45 ( const void * V_36 )
{
struct V_1 * V_2 ;
F_46 ( V_44 , V_36 ) ;
if ( F_33 ( F_35 ( V_36 ) ) )
return;
F_47 ( V_36 ) ;
V_2 = F_29 ( V_36 ) ;
if ( F_48 ( V_2 ) ) {
int V_19 = F_39 ( V_39 , V_40 ) ;
unsigned int * V_38 = ( unsigned int * ) ( V_36 - V_19 ) ;
F_34 ( V_38 , * V_38 + V_19 ) ;
} else
F_49 ( V_2 ) ;
}
T_4 F_50 ( const void * V_36 )
{
struct V_1 * V_2 ;
F_32 ( ! V_36 ) ;
if ( F_33 ( V_36 == V_43 ) )
return 0 ;
V_2 = F_29 ( V_36 ) ;
if ( F_48 ( V_2 ) ) {
int V_19 = F_39 ( V_39 , V_40 ) ;
unsigned int * V_38 = ( unsigned int * ) ( V_36 - V_19 ) ;
return F_21 ( * V_38 ) * V_47 ;
} else
return V_2 -> V_46 ;
}
struct V_48 * F_51 ( const char * V_49 , T_4 V_6 ,
T_4 V_19 , unsigned long V_27 , void (* F_52)( void * ) )
{
struct V_48 * V_50 ;
V_50 = F_23 ( sizeof( struct V_48 ) ,
V_51 , V_39 , - 1 ) ;
if ( V_50 ) {
V_50 -> V_49 = V_49 ;
V_50 -> V_6 = V_6 ;
if ( V_27 & V_52 ) {
V_50 -> V_6 += sizeof( struct V_53 ) ;
}
V_50 -> V_27 = V_27 ;
V_50 -> F_52 = F_52 ;
V_50 -> V_19 = ( V_27 & V_54 ) ? V_55 : 0 ;
if ( V_50 -> V_19 < V_40 )
V_50 -> V_19 = V_40 ;
if ( V_50 -> V_19 < V_19 )
V_50 -> V_19 = V_19 ;
F_44 ( V_50 , sizeof( struct V_48 ) , 1 , V_51 ) ;
V_50 -> V_56 = 1 ;
}
return V_50 ;
}
void F_53 ( struct V_48 * V_50 )
{
F_47 ( V_50 ) ;
if ( V_50 -> V_27 & V_52 )
F_54 () ;
F_34 ( V_50 , sizeof( struct V_48 ) ) ;
}
void * F_55 ( struct V_48 * V_50 , T_3 V_27 , int V_14 )
{
void * V_15 ;
V_27 &= V_42 ;
F_40 ( V_27 ) ;
if ( V_50 -> V_6 < V_35 ) {
V_15 = F_23 ( V_50 -> V_6 , V_27 , V_50 -> V_19 , V_14 ) ;
F_56 ( V_44 , V_15 , V_50 -> V_6 ,
F_21 ( V_50 -> V_6 ) * V_47 ,
V_27 , V_14 ) ;
} else {
V_15 = F_13 ( V_27 , F_42 ( V_50 -> V_6 ) , V_14 ) ;
F_56 ( V_44 , V_15 , V_50 -> V_6 ,
V_35 << F_42 ( V_50 -> V_6 ) ,
V_27 , V_14 ) ;
}
if ( V_50 -> F_52 )
V_50 -> F_52 ( V_15 ) ;
F_57 ( V_15 , V_50 -> V_6 , 1 , V_50 -> V_27 , V_27 ) ;
return V_15 ;
}
static void F_58 ( void * V_15 , int V_6 )
{
if ( V_6 < V_35 )
F_34 ( V_15 , V_6 ) ;
else
F_18 ( V_15 , F_42 ( V_6 ) ) ;
}
static void F_59 ( struct V_57 * V_58 )
{
struct V_53 * V_53 = (struct V_53 * ) V_58 ;
void * V_15 = ( void * ) V_53 - ( V_53 -> V_6 - sizeof( struct V_53 ) ) ;
F_58 ( V_15 , V_53 -> V_6 ) ;
}
void F_60 ( struct V_48 * V_50 , void * V_15 )
{
F_61 ( V_15 , V_50 -> V_27 ) ;
if ( F_33 ( V_50 -> V_27 & V_52 ) ) {
struct V_53 * V_53 ;
V_53 = V_15 + ( V_50 -> V_6 - sizeof( struct V_53 ) ) ;
V_53 -> V_6 = V_50 -> V_6 ;
F_62 ( & V_53 -> V_58 , F_59 ) ;
} else {
F_58 ( V_15 , V_50 -> V_6 ) ;
}
F_63 ( V_44 , V_15 ) ;
}
unsigned int F_64 ( struct V_48 * V_50 )
{
return V_50 -> V_6 ;
}
int F_65 ( struct V_48 * V_59 )
{
return 0 ;
}
void T_5 F_66 ( void )
{
V_60 = V_61 ;
}
void T_5 F_67 ( void )
{
V_60 = V_62 ;
}
