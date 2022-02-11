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
struct V_3 * V_3 = NULL ;
unsigned int V_25 = F_19 ( V_20 ) >> V_7 ;
if ( F_20 ( V_5 , V_20 , V_21 , & V_22 ) )
return V_22 ;
V_11 = F_10 ( V_5 , V_11 ) ;
if ( F_21 ( V_26 ) && ! ( V_11 & V_27 ) )
V_3 = F_22 ( V_5 ,
V_25 , F_16 ( V_20 ) ) ;
if ( ! V_3 )
V_3 = F_23 ( V_11 , F_16 ( V_20 ) ) ;
if ( ! V_3 )
return NULL ;
V_22 = F_24 ( V_3 ) ;
memset ( V_22 , 0 , V_20 ) ;
* V_21 = F_17 ( V_5 , V_22 , V_20 ) ;
if ( ! F_8 ( V_5 ) ) {
F_25 ( ( unsigned long ) V_22 , V_20 ) ;
if ( ! V_28 )
V_22 = F_26 ( V_22 ) ;
}
return V_22 ;
}
void F_27 ( struct V_4 * V_5 , T_4 V_20 , void * V_29 ,
T_2 V_21 )
{
F_28 ( V_5 , V_21 , V_20 , V_30 ) ;
F_29 ( ( unsigned long ) V_29 , F_16 ( V_20 ) ) ;
}
static void F_30 ( struct V_4 * V_5 , T_4 V_20 , void * V_29 ,
T_2 V_21 , struct V_23 * V_24 )
{
unsigned long V_31 = ( unsigned long ) V_29 ;
int V_32 = F_16 ( V_20 ) ;
unsigned int V_25 = F_19 ( V_20 ) >> V_7 ;
struct V_3 * V_3 = NULL ;
if ( F_31 ( V_5 , V_32 , V_29 ) )
return;
F_28 ( V_5 , V_21 , V_20 , V_30 ) ;
if ( ! F_8 ( V_5 ) && ! V_28 )
V_31 = F_32 ( V_31 ) ;
V_3 = F_33 ( ( void * ) V_31 ) ;
if ( ! F_34 ( V_5 , V_3 , V_25 ) )
F_35 ( V_3 , F_16 ( V_20 ) ) ;
}
static inline void F_36 ( void * V_31 , T_4 V_20 ,
enum V_33 V_34 )
{
switch ( V_34 ) {
case V_35 :
F_37 ( ( unsigned long ) V_31 , V_20 ) ;
break;
case V_36 :
F_38 ( ( unsigned long ) V_31 , V_20 ) ;
break;
case V_30 :
F_25 ( ( unsigned long ) V_31 , V_20 ) ;
break;
default:
F_39 () ;
}
}
static inline void F_40 ( struct V_3 * V_3 ,
unsigned long V_37 , T_4 V_20 , enum V_33 V_34 )
{
T_4 V_38 = V_20 ;
do {
T_4 V_39 = V_38 ;
if ( F_41 ( V_3 ) ) {
void * V_31 ;
if ( V_37 + V_39 > V_40 ) {
if ( V_37 >= V_40 ) {
V_3 += V_37 >> V_7 ;
V_37 &= ~ V_41 ;
}
V_39 = V_40 - V_37 ;
}
V_31 = F_42 ( V_3 ) ;
F_36 ( V_31 + V_37 , V_39 , V_34 ) ;
F_43 ( V_31 ) ;
} else
F_36 ( F_24 ( V_3 ) + V_37 ,
V_20 , V_34 ) ;
V_37 = 0 ;
V_3 ++ ;
V_38 -= V_39 ;
} while ( V_38 );
}
static void F_44 ( struct V_4 * V_5 , T_2 V_6 ,
T_4 V_20 , enum V_33 V_34 , struct V_23 * V_24 )
{
if ( F_7 ( V_5 ) )
F_40 ( F_4 ( V_5 , V_6 ) ,
V_6 & ~ V_41 , V_20 , V_34 ) ;
F_45 ( V_5 ) ;
F_28 ( V_5 , V_6 , V_20 , V_34 ) ;
}
static int F_46 ( struct V_4 * V_5 , struct V_42 * V_43 ,
int V_44 , enum V_33 V_34 , struct V_23 * V_24 )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < V_44 ; V_45 ++ , V_43 ++ ) {
if ( ! F_8 ( V_5 ) )
F_40 ( F_47 ( V_43 ) , V_43 -> V_37 , V_43 -> V_46 ,
V_34 ) ;
#ifdef F_48
V_43 -> V_47 = V_43 -> V_46 ;
#endif
V_43 -> V_48 = F_49 ( V_5 , F_47 ( V_43 ) ) +
V_43 -> V_37 ;
}
return V_44 ;
}
static T_2 F_50 ( struct V_4 * V_5 , struct V_3 * V_3 ,
unsigned long V_37 , T_4 V_20 , enum V_33 V_34 ,
struct V_23 * V_24 )
{
if ( ! F_8 ( V_5 ) )
F_40 ( V_3 , V_37 , V_20 , V_34 ) ;
return F_49 ( V_5 , V_3 ) + V_37 ;
}
static void F_51 ( struct V_4 * V_5 , struct V_42 * V_43 ,
int V_49 , enum V_33 V_34 ,
struct V_23 * V_24 )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < V_49 ; V_45 ++ , V_43 ++ ) {
if ( ! F_8 ( V_5 ) &&
V_34 != V_35 )
F_40 ( F_47 ( V_43 ) , V_43 -> V_37 , V_43 -> V_46 ,
V_34 ) ;
F_28 ( V_5 , V_43 -> V_48 , V_43 -> V_46 , V_34 ) ;
}
}
static void F_52 ( struct V_4 * V_5 ,
T_2 V_21 , T_4 V_20 , enum V_33 V_34 )
{
if ( F_7 ( V_5 ) )
F_40 ( F_4 ( V_5 , V_21 ) ,
V_21 & ~ V_41 , V_20 , V_34 ) ;
F_45 ( V_5 ) ;
}
static void F_53 ( struct V_4 * V_5 ,
T_2 V_21 , T_4 V_20 , enum V_33 V_34 )
{
if ( ! F_8 ( V_5 ) )
F_40 ( F_4 ( V_5 , V_21 ) ,
V_21 & ~ V_41 , V_20 , V_34 ) ;
}
static void F_54 ( struct V_4 * V_5 ,
struct V_42 * V_43 , int V_50 , enum V_33 V_34 )
{
int V_45 ;
if ( F_7 ( V_5 ) )
for ( V_45 = 0 ; V_45 < V_50 ; V_45 ++ , V_43 ++ )
F_40 ( F_47 ( V_43 ) , V_43 -> V_37 , V_43 -> V_46 ,
V_34 ) ;
F_45 ( V_5 ) ;
}
static void F_55 ( struct V_4 * V_5 ,
struct V_42 * V_43 , int V_50 , enum V_33 V_34 )
{
int V_45 ;
if ( ! F_8 ( V_5 ) )
for ( V_45 = 0 ; V_45 < V_50 ; V_45 ++ , V_43 ++ )
F_40 ( F_47 ( V_43 ) , V_43 -> V_37 , V_43 -> V_46 ,
V_34 ) ;
}
int F_56 ( struct V_4 * V_5 , T_2 V_6 )
{
return 0 ;
}
int F_57 ( struct V_4 * V_5 , T_5 V_51 )
{
return F_58 ( V_5 , V_51 ) ;
}
void F_59 ( struct V_4 * V_5 , void * V_29 , T_4 V_20 ,
enum V_33 V_34 )
{
F_60 ( V_34 == V_52 ) ;
if ( ! F_8 ( V_5 ) )
F_36 ( V_29 , V_20 , V_34 ) ;
}
static int T_1 F_61 ( void )
{
F_62 ( V_53 ) ;
return 0 ;
}
