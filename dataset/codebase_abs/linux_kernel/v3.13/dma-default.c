static int T_1 F_1 ( char * V_1 )
{
V_2 = 1 ;
F_2 ( L_1 ) ;
return 0 ;
}
static int T_1 F_3 ( char * V_1 )
{
V_2 = 0 ;
F_2 ( L_2 ) ;
return 0 ;
}
static inline struct V_3 * F_4 ( struct V_4 * V_5 ,
T_2 V_6 )
{
return F_5 (
F_6 ( V_5 , V_6 ) >> V_7 ) ;
}
static inline int F_7 ( struct V_4 * V_5 )
{
return ! F_8 ( V_5 ) &&
( F_9 () == V_8 ||
F_9 () == V_9 ||
F_9 () == V_10 ) ;
}
static T_3 F_10 ( const struct V_4 * V_5 , T_3 V_11 )
{
T_3 V_12 ;
V_11 &= ~ ( V_13 | V_14 | V_15 ) ;
#ifdef F_11
if ( V_5 == NULL )
V_12 = V_13 ;
else
#endif
#if F_12 ( V_16 ) && F_12 ( V_17 )
if ( V_5 -> V_18 < F_13 ( 32 ) )
V_12 = V_13 ;
else if ( V_5 -> V_18 < F_13 ( 64 ) )
V_12 = V_14 ;
else
#endif
#if F_12 ( V_16 ) && ! F_12 ( V_17 )
if ( V_5 -> V_18 < F_13 ( 64 ) )
V_12 = V_14 ;
else
#endif
#if F_12 ( V_17 ) && ! F_12 ( V_16 )
if ( V_5 -> V_18 < F_13 ( 64 ) )
V_12 = V_13 ;
else
#endif
V_12 = 0 ;
V_11 |= V_19 ;
return V_11 | V_12 ;
}
void * F_14 ( struct V_4 * V_5 , T_4 V_20 ,
T_2 * V_21 , T_3 V_11 )
{
void * V_22 ;
V_11 = F_10 ( V_5 , V_11 ) ;
V_22 = ( void * ) F_15 ( V_11 , F_16 ( V_20 ) ) ;
if ( V_22 != NULL ) {
memset ( V_22 , 0 , V_20 ) ;
* V_21 = F_17 ( V_5 , V_22 , V_20 ) ;
}
return V_22 ;
}
static void * F_18 ( struct V_4 * V_5 , T_4 V_20 ,
T_2 * V_21 , T_3 V_11 , struct V_23 * V_24 )
{
void * V_22 ;
if ( F_19 ( V_5 , V_20 , V_21 , & V_22 ) )
return V_22 ;
V_11 = F_10 ( V_5 , V_11 ) ;
V_22 = ( void * ) F_15 ( V_11 , F_16 ( V_20 ) ) ;
if ( V_22 ) {
memset ( V_22 , 0 , V_20 ) ;
* V_21 = F_17 ( V_5 , V_22 , V_20 ) ;
if ( ! F_8 ( V_5 ) ) {
F_20 ( ( unsigned long ) V_22 , V_20 ) ;
if ( ! V_25 )
V_22 = F_21 ( V_22 ) ;
}
}
return V_22 ;
}
void F_22 ( struct V_4 * V_5 , T_4 V_20 , void * V_26 ,
T_2 V_21 )
{
F_23 ( V_5 , V_21 , V_20 , V_27 ) ;
F_24 ( ( unsigned long ) V_26 , F_16 ( V_20 ) ) ;
}
static void F_25 ( struct V_4 * V_5 , T_4 V_20 , void * V_26 ,
T_2 V_21 , struct V_23 * V_24 )
{
unsigned long V_28 = ( unsigned long ) V_26 ;
int V_29 = F_16 ( V_20 ) ;
if ( F_26 ( V_5 , V_29 , V_26 ) )
return;
F_23 ( V_5 , V_21 , V_20 , V_27 ) ;
if ( ! F_8 ( V_5 ) && ! V_25 )
V_28 = F_27 ( V_28 ) ;
F_24 ( V_28 , F_16 ( V_20 ) ) ;
}
static inline void F_28 ( void * V_28 , T_4 V_20 ,
enum V_30 V_31 )
{
switch ( V_31 ) {
case V_32 :
F_29 ( ( unsigned long ) V_28 , V_20 ) ;
break;
case V_33 :
F_30 ( ( unsigned long ) V_28 , V_20 ) ;
break;
case V_27 :
F_20 ( ( unsigned long ) V_28 , V_20 ) ;
break;
default:
F_31 () ;
}
}
static inline void F_32 ( struct V_3 * V_3 ,
unsigned long V_34 , T_4 V_20 , enum V_30 V_31 )
{
T_4 V_35 = V_20 ;
do {
T_4 V_36 = V_35 ;
if ( F_33 ( V_3 ) ) {
void * V_28 ;
if ( V_34 + V_36 > V_37 ) {
if ( V_34 >= V_37 ) {
V_3 += V_34 >> V_7 ;
V_34 &= ~ V_38 ;
}
V_36 = V_37 - V_34 ;
}
V_28 = F_34 ( V_3 ) ;
F_28 ( V_28 + V_34 , V_36 , V_31 ) ;
F_35 ( V_28 ) ;
} else
F_28 ( F_36 ( V_3 ) + V_34 ,
V_20 , V_31 ) ;
V_34 = 0 ;
V_3 ++ ;
V_35 -= V_36 ;
} while ( V_35 );
}
static void F_37 ( struct V_4 * V_5 , T_2 V_6 ,
T_4 V_20 , enum V_30 V_31 , struct V_23 * V_24 )
{
if ( F_7 ( V_5 ) )
F_32 ( F_4 ( V_5 , V_6 ) ,
V_6 & ~ V_38 , V_20 , V_31 ) ;
F_23 ( V_5 , V_6 , V_20 , V_31 ) ;
}
static int F_38 ( struct V_4 * V_5 , struct V_39 * V_40 ,
int V_41 , enum V_30 V_31 , struct V_23 * V_24 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_41 ; V_42 ++ , V_40 ++ ) {
if ( ! F_8 ( V_5 ) )
F_32 ( F_39 ( V_40 ) , V_40 -> V_34 , V_40 -> V_43 ,
V_31 ) ;
#ifdef F_40
V_40 -> V_44 = V_40 -> V_43 ;
#endif
V_40 -> V_45 = F_41 ( V_5 , F_39 ( V_40 ) ) +
V_40 -> V_34 ;
}
return V_41 ;
}
static T_2 F_42 ( struct V_4 * V_5 , struct V_3 * V_3 ,
unsigned long V_34 , T_4 V_20 , enum V_30 V_31 ,
struct V_23 * V_24 )
{
if ( ! F_8 ( V_5 ) )
F_32 ( V_3 , V_34 , V_20 , V_31 ) ;
return F_41 ( V_5 , V_3 ) + V_34 ;
}
static void F_43 ( struct V_4 * V_5 , struct V_39 * V_40 ,
int V_46 , enum V_30 V_31 ,
struct V_23 * V_24 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_46 ; V_42 ++ , V_40 ++ ) {
if ( ! F_8 ( V_5 ) &&
V_31 != V_32 )
F_32 ( F_39 ( V_40 ) , V_40 -> V_34 , V_40 -> V_43 ,
V_31 ) ;
F_23 ( V_5 , V_40 -> V_45 , V_40 -> V_43 , V_31 ) ;
}
}
static void F_44 ( struct V_4 * V_5 ,
T_2 V_21 , T_4 V_20 , enum V_30 V_31 )
{
if ( F_7 ( V_5 ) )
F_32 ( F_4 ( V_5 , V_21 ) ,
V_21 & ~ V_38 , V_20 , V_31 ) ;
}
static void F_45 ( struct V_4 * V_5 ,
T_2 V_21 , T_4 V_20 , enum V_30 V_31 )
{
if ( ! F_8 ( V_5 ) )
F_32 ( F_4 ( V_5 , V_21 ) ,
V_21 & ~ V_38 , V_20 , V_31 ) ;
}
static void F_46 ( struct V_4 * V_5 ,
struct V_39 * V_40 , int V_47 , enum V_30 V_31 )
{
int V_42 ;
if ( F_7 ( V_5 ) )
for ( V_42 = 0 ; V_42 < V_47 ; V_42 ++ , V_40 ++ )
F_32 ( F_39 ( V_40 ) , V_40 -> V_34 , V_40 -> V_43 ,
V_31 ) ;
}
static void F_47 ( struct V_4 * V_5 ,
struct V_39 * V_40 , int V_47 , enum V_30 V_31 )
{
int V_42 ;
if ( ! F_8 ( V_5 ) )
for ( V_42 = 0 ; V_42 < V_47 ; V_42 ++ , V_40 ++ )
F_32 ( F_39 ( V_40 ) , V_40 -> V_34 , V_40 -> V_43 ,
V_31 ) ;
}
int F_48 ( struct V_4 * V_5 , T_2 V_6 )
{
return 0 ;
}
int F_49 ( struct V_4 * V_5 , T_5 V_48 )
{
return F_50 ( V_5 , V_48 ) ;
}
void F_51 ( struct V_4 * V_5 , void * V_26 , T_4 V_20 ,
enum V_30 V_31 )
{
F_52 ( V_31 == V_49 ) ;
if ( ! F_8 ( V_5 ) )
F_28 ( V_26 , V_20 , V_31 ) ;
}
static int T_1 F_53 ( void )
{
F_54 ( V_50 ) ;
return 0 ;
}
