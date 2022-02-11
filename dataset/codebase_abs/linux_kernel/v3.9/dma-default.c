static inline struct V_1 * F_1 ( struct V_2 * V_3 ,
T_1 V_4 )
{
return F_2 (
F_3 ( V_3 , V_4 ) >> V_5 ) ;
}
static inline int F_4 ( struct V_2 * V_3 )
{
return ! F_5 ( V_3 ) &&
( F_6 () == V_6 ||
F_6 () == V_7 ) ;
}
static T_2 F_7 ( const struct V_2 * V_3 , T_2 V_8 )
{
T_2 V_9 ;
V_8 &= ~ ( V_10 | V_11 | V_12 ) ;
#ifdef F_8
if ( V_3 == NULL )
V_9 = V_10 ;
else
#endif
#if F_9 ( V_13 ) && F_9 ( V_14 )
if ( V_3 -> V_15 < F_10 ( 32 ) )
V_9 = V_10 ;
else if ( V_3 -> V_15 < F_10 ( 64 ) )
V_9 = V_11 ;
else
#endif
#if F_9 ( V_13 ) && ! F_9 ( V_14 )
if ( V_3 -> V_15 < F_10 ( 64 ) )
V_9 = V_11 ;
else
#endif
#if F_9 ( V_14 ) && ! F_9 ( V_13 )
if ( V_3 -> V_15 < F_10 ( 64 ) )
V_9 = V_10 ;
else
#endif
V_9 = 0 ;
V_8 |= V_16 ;
return V_8 | V_9 ;
}
void * F_11 ( struct V_2 * V_3 , T_3 V_17 ,
T_1 * V_18 , T_2 V_8 )
{
void * V_19 ;
V_8 = F_7 ( V_3 , V_8 ) ;
V_19 = ( void * ) F_12 ( V_8 , F_13 ( V_17 ) ) ;
if ( V_19 != NULL ) {
memset ( V_19 , 0 , V_17 ) ;
* V_18 = F_14 ( V_3 , V_19 , V_17 ) ;
}
return V_19 ;
}
static void * F_15 ( struct V_2 * V_3 , T_3 V_17 ,
T_1 * V_18 , T_2 V_8 , struct V_20 * V_21 )
{
void * V_19 ;
if ( F_16 ( V_3 , V_17 , V_18 , & V_19 ) )
return V_19 ;
V_8 = F_7 ( V_3 , V_8 ) ;
V_19 = ( void * ) F_12 ( V_8 , F_13 ( V_17 ) ) ;
if ( V_19 ) {
memset ( V_19 , 0 , V_17 ) ;
* V_18 = F_14 ( V_3 , V_19 , V_17 ) ;
if ( ! F_5 ( V_3 ) ) {
F_17 ( ( unsigned long ) V_19 , V_17 ) ;
V_19 = F_18 ( V_19 ) ;
}
}
return V_19 ;
}
void F_19 ( struct V_2 * V_3 , T_3 V_17 , void * V_22 ,
T_1 V_18 )
{
F_20 ( V_3 , V_18 , V_17 , V_23 ) ;
F_21 ( ( unsigned long ) V_22 , F_13 ( V_17 ) ) ;
}
static void F_22 ( struct V_2 * V_3 , T_3 V_17 , void * V_22 ,
T_1 V_18 , struct V_20 * V_21 )
{
unsigned long V_24 = ( unsigned long ) V_22 ;
int V_25 = F_13 ( V_17 ) ;
if ( F_23 ( V_3 , V_25 , V_22 ) )
return;
F_20 ( V_3 , V_18 , V_17 , V_23 ) ;
if ( ! F_5 ( V_3 ) )
V_24 = F_24 ( V_24 ) ;
F_21 ( V_24 , F_13 ( V_17 ) ) ;
}
static inline void F_25 ( void * V_24 , T_3 V_17 ,
enum V_26 V_27 )
{
switch ( V_27 ) {
case V_28 :
F_26 ( ( unsigned long ) V_24 , V_17 ) ;
break;
case V_29 :
F_27 ( ( unsigned long ) V_24 , V_17 ) ;
break;
case V_23 :
F_17 ( ( unsigned long ) V_24 , V_17 ) ;
break;
default:
F_28 () ;
}
}
static inline void F_29 ( struct V_1 * V_1 ,
unsigned long V_30 , T_3 V_17 , enum V_26 V_27 )
{
T_3 V_31 = V_17 ;
do {
T_3 V_32 = V_31 ;
if ( F_30 ( V_1 ) ) {
void * V_24 ;
if ( V_30 + V_32 > V_33 ) {
if ( V_30 >= V_33 ) {
V_1 += V_30 >> V_5 ;
V_30 &= ~ V_34 ;
}
V_32 = V_33 - V_30 ;
}
V_24 = F_31 ( V_1 ) ;
F_25 ( V_24 + V_30 , V_32 , V_27 ) ;
F_32 ( V_24 ) ;
} else
F_25 ( F_33 ( V_1 ) + V_30 ,
V_17 , V_27 ) ;
V_30 = 0 ;
V_1 ++ ;
V_31 -= V_32 ;
} while ( V_31 );
}
static void F_34 ( struct V_2 * V_3 , T_1 V_4 ,
T_3 V_17 , enum V_26 V_27 , struct V_20 * V_21 )
{
if ( F_4 ( V_3 ) )
F_29 ( F_1 ( V_3 , V_4 ) ,
V_4 & ~ V_34 , V_17 , V_27 ) ;
F_20 ( V_3 , V_4 , V_17 , V_27 ) ;
}
static int F_35 ( struct V_2 * V_3 , struct V_35 * V_36 ,
int V_37 , enum V_26 V_27 , struct V_20 * V_21 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < V_37 ; V_38 ++ , V_36 ++ ) {
if ( ! F_5 ( V_3 ) )
F_29 ( F_36 ( V_36 ) , V_36 -> V_30 , V_36 -> V_39 ,
V_27 ) ;
V_36 -> V_40 = F_37 ( V_3 , F_36 ( V_36 ) ) +
V_36 -> V_30 ;
}
return V_37 ;
}
static T_1 F_38 ( struct V_2 * V_3 , struct V_1 * V_1 ,
unsigned long V_30 , T_3 V_17 , enum V_26 V_27 ,
struct V_20 * V_21 )
{
if ( ! F_5 ( V_3 ) )
F_29 ( V_1 , V_30 , V_17 , V_27 ) ;
return F_37 ( V_3 , V_1 ) + V_30 ;
}
static void F_39 ( struct V_2 * V_3 , struct V_35 * V_36 ,
int V_41 , enum V_26 V_27 ,
struct V_20 * V_21 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < V_41 ; V_38 ++ , V_36 ++ ) {
if ( ! F_5 ( V_3 ) &&
V_27 != V_28 )
F_29 ( F_36 ( V_36 ) , V_36 -> V_30 , V_36 -> V_39 ,
V_27 ) ;
F_20 ( V_3 , V_36 -> V_40 , V_36 -> V_39 , V_27 ) ;
}
}
static void F_40 ( struct V_2 * V_3 ,
T_1 V_18 , T_3 V_17 , enum V_26 V_27 )
{
if ( F_4 ( V_3 ) )
F_29 ( F_1 ( V_3 , V_18 ) ,
V_18 & ~ V_34 , V_17 , V_27 ) ;
}
static void F_41 ( struct V_2 * V_3 ,
T_1 V_18 , T_3 V_17 , enum V_26 V_27 )
{
F_42 ( V_3 ) ;
if ( ! F_5 ( V_3 ) )
F_29 ( F_1 ( V_3 , V_18 ) ,
V_18 & ~ V_34 , V_17 , V_27 ) ;
}
static void F_43 ( struct V_2 * V_3 ,
struct V_35 * V_36 , int V_42 , enum V_26 V_27 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < V_42 ; V_38 ++ , V_36 ++ ) {
if ( F_4 ( V_3 ) )
F_29 ( F_36 ( V_36 ) , V_36 -> V_30 , V_36 -> V_39 ,
V_27 ) ;
}
}
static void F_44 ( struct V_2 * V_3 ,
struct V_35 * V_36 , int V_42 , enum V_26 V_27 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < V_42 ; V_38 ++ , V_36 ++ ) {
if ( ! F_5 ( V_3 ) )
F_29 ( F_36 ( V_36 ) , V_36 -> V_30 , V_36 -> V_39 ,
V_27 ) ;
}
}
int F_45 ( struct V_2 * V_3 , T_1 V_4 )
{
return F_46 ( V_3 , V_4 ) ;
}
int F_47 ( struct V_2 * V_3 , T_4 V_43 )
{
return F_48 ( V_3 , V_43 ) ;
}
void F_49 ( struct V_2 * V_3 , void * V_22 , T_3 V_17 ,
enum V_26 V_27 )
{
F_50 ( V_27 == V_44 ) ;
F_42 ( V_3 ) ;
if ( ! F_5 ( V_3 ) )
F_25 ( V_22 , V_17 , V_27 ) ;
}
static int T_5 F_51 ( void )
{
F_52 ( V_45 ) ;
return 0 ;
}
