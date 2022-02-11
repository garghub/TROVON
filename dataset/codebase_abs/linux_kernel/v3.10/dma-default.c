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
F_9 () == V_9 ) ;
}
static T_3 F_10 ( const struct V_4 * V_5 , T_3 V_10 )
{
T_3 V_11 ;
V_10 &= ~ ( V_12 | V_13 | V_14 ) ;
#ifdef F_11
if ( V_5 == NULL )
V_11 = V_12 ;
else
#endif
#if F_12 ( V_15 ) && F_12 ( V_16 )
if ( V_5 -> V_17 < F_13 ( 32 ) )
V_11 = V_12 ;
else if ( V_5 -> V_17 < F_13 ( 64 ) )
V_11 = V_13 ;
else
#endif
#if F_12 ( V_15 ) && ! F_12 ( V_16 )
if ( V_5 -> V_17 < F_13 ( 64 ) )
V_11 = V_13 ;
else
#endif
#if F_12 ( V_16 ) && ! F_12 ( V_15 )
if ( V_5 -> V_17 < F_13 ( 64 ) )
V_11 = V_12 ;
else
#endif
V_11 = 0 ;
V_10 |= V_18 ;
return V_10 | V_11 ;
}
void * F_14 ( struct V_4 * V_5 , T_4 V_19 ,
T_2 * V_20 , T_3 V_10 )
{
void * V_21 ;
V_10 = F_10 ( V_5 , V_10 ) ;
V_21 = ( void * ) F_15 ( V_10 , F_16 ( V_19 ) ) ;
if ( V_21 != NULL ) {
memset ( V_21 , 0 , V_19 ) ;
* V_20 = F_17 ( V_5 , V_21 , V_19 ) ;
}
return V_21 ;
}
static void * F_18 ( struct V_4 * V_5 , T_4 V_19 ,
T_2 * V_20 , T_3 V_10 , struct V_22 * V_23 )
{
void * V_21 ;
if ( F_19 ( V_5 , V_19 , V_20 , & V_21 ) )
return V_21 ;
V_10 = F_10 ( V_5 , V_10 ) ;
V_21 = ( void * ) F_15 ( V_10 , F_16 ( V_19 ) ) ;
if ( V_21 ) {
memset ( V_21 , 0 , V_19 ) ;
* V_20 = F_17 ( V_5 , V_21 , V_19 ) ;
if ( ! F_8 ( V_5 ) ) {
F_20 ( ( unsigned long ) V_21 , V_19 ) ;
if ( ! V_24 )
V_21 = F_21 ( V_21 ) ;
}
}
return V_21 ;
}
void F_22 ( struct V_4 * V_5 , T_4 V_19 , void * V_25 ,
T_2 V_20 )
{
F_23 ( V_5 , V_20 , V_19 , V_26 ) ;
F_24 ( ( unsigned long ) V_25 , F_16 ( V_19 ) ) ;
}
static void F_25 ( struct V_4 * V_5 , T_4 V_19 , void * V_25 ,
T_2 V_20 , struct V_22 * V_23 )
{
unsigned long V_27 = ( unsigned long ) V_25 ;
int V_28 = F_16 ( V_19 ) ;
if ( F_26 ( V_5 , V_28 , V_25 ) )
return;
F_23 ( V_5 , V_20 , V_19 , V_26 ) ;
if ( ! F_8 ( V_5 ) && ! V_24 )
V_27 = F_27 ( V_27 ) ;
F_24 ( V_27 , F_16 ( V_19 ) ) ;
}
static inline void F_28 ( void * V_27 , T_4 V_19 ,
enum V_29 V_30 )
{
switch ( V_30 ) {
case V_31 :
F_29 ( ( unsigned long ) V_27 , V_19 ) ;
break;
case V_32 :
F_30 ( ( unsigned long ) V_27 , V_19 ) ;
break;
case V_26 :
F_20 ( ( unsigned long ) V_27 , V_19 ) ;
break;
default:
F_31 () ;
}
}
static inline void F_32 ( struct V_3 * V_3 ,
unsigned long V_33 , T_4 V_19 , enum V_29 V_30 )
{
T_4 V_34 = V_19 ;
do {
T_4 V_35 = V_34 ;
if ( F_33 ( V_3 ) ) {
void * V_27 ;
if ( V_33 + V_35 > V_36 ) {
if ( V_33 >= V_36 ) {
V_3 += V_33 >> V_7 ;
V_33 &= ~ V_37 ;
}
V_35 = V_36 - V_33 ;
}
V_27 = F_34 ( V_3 ) ;
F_28 ( V_27 + V_33 , V_35 , V_30 ) ;
F_35 ( V_27 ) ;
} else
F_28 ( F_36 ( V_3 ) + V_33 ,
V_19 , V_30 ) ;
V_33 = 0 ;
V_3 ++ ;
V_34 -= V_35 ;
} while ( V_34 );
}
static void F_37 ( struct V_4 * V_5 , T_2 V_6 ,
T_4 V_19 , enum V_29 V_30 , struct V_22 * V_23 )
{
if ( F_7 ( V_5 ) )
F_32 ( F_4 ( V_5 , V_6 ) ,
V_6 & ~ V_37 , V_19 , V_30 ) ;
F_23 ( V_5 , V_6 , V_19 , V_30 ) ;
}
static int F_38 ( struct V_4 * V_5 , struct V_38 * V_39 ,
int V_40 , enum V_29 V_30 , struct V_22 * V_23 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < V_40 ; V_41 ++ , V_39 ++ ) {
if ( ! F_8 ( V_5 ) )
F_32 ( F_39 ( V_39 ) , V_39 -> V_33 , V_39 -> V_42 ,
V_30 ) ;
V_39 -> V_43 = F_40 ( V_5 , F_39 ( V_39 ) ) +
V_39 -> V_33 ;
}
return V_40 ;
}
static T_2 F_41 ( struct V_4 * V_5 , struct V_3 * V_3 ,
unsigned long V_33 , T_4 V_19 , enum V_29 V_30 ,
struct V_22 * V_23 )
{
if ( ! F_8 ( V_5 ) )
F_32 ( V_3 , V_33 , V_19 , V_30 ) ;
return F_40 ( V_5 , V_3 ) + V_33 ;
}
static void F_42 ( struct V_4 * V_5 , struct V_38 * V_39 ,
int V_44 , enum V_29 V_30 ,
struct V_22 * V_23 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < V_44 ; V_41 ++ , V_39 ++ ) {
if ( ! F_8 ( V_5 ) &&
V_30 != V_31 )
F_32 ( F_39 ( V_39 ) , V_39 -> V_33 , V_39 -> V_42 ,
V_30 ) ;
F_23 ( V_5 , V_39 -> V_43 , V_39 -> V_42 , V_30 ) ;
}
}
static void F_43 ( struct V_4 * V_5 ,
T_2 V_20 , T_4 V_19 , enum V_29 V_30 )
{
if ( F_7 ( V_5 ) )
F_32 ( F_4 ( V_5 , V_20 ) ,
V_20 & ~ V_37 , V_19 , V_30 ) ;
}
static void F_44 ( struct V_4 * V_5 ,
T_2 V_20 , T_4 V_19 , enum V_29 V_30 )
{
F_45 ( V_5 ) ;
if ( ! F_8 ( V_5 ) )
F_32 ( F_4 ( V_5 , V_20 ) ,
V_20 & ~ V_37 , V_19 , V_30 ) ;
}
static void F_46 ( struct V_4 * V_5 ,
struct V_38 * V_39 , int V_45 , enum V_29 V_30 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < V_45 ; V_41 ++ , V_39 ++ ) {
if ( F_7 ( V_5 ) )
F_32 ( F_39 ( V_39 ) , V_39 -> V_33 , V_39 -> V_42 ,
V_30 ) ;
}
}
static void F_47 ( struct V_4 * V_5 ,
struct V_38 * V_39 , int V_45 , enum V_29 V_30 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < V_45 ; V_41 ++ , V_39 ++ ) {
if ( ! F_8 ( V_5 ) )
F_32 ( F_39 ( V_39 ) , V_39 -> V_33 , V_39 -> V_42 ,
V_30 ) ;
}
}
int F_48 ( struct V_4 * V_5 , T_2 V_6 )
{
return F_49 ( V_5 , V_6 ) ;
}
int F_50 ( struct V_4 * V_5 , T_5 V_46 )
{
return F_51 ( V_5 , V_46 ) ;
}
void F_52 ( struct V_4 * V_5 , void * V_25 , T_4 V_19 ,
enum V_29 V_30 )
{
F_53 ( V_30 == V_47 ) ;
F_45 ( V_5 ) ;
if ( ! F_8 ( V_5 ) )
F_28 ( V_25 , V_19 , V_30 ) ;
}
static int T_1 F_54 ( void )
{
F_55 ( V_48 ) ;
return 0 ;
}
