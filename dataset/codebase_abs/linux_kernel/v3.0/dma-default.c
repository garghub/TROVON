static inline unsigned long F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
unsigned long V_4 = F_2 ( V_2 , V_3 ) ;
return ( unsigned long ) F_3 ( V_4 ) ;
}
static inline int F_4 ( struct V_1 * V_2 )
{
return ! F_5 ( V_2 ) &&
( F_6 () == V_5 ||
F_6 () == V_6 ) ;
}
static T_2 F_7 ( const struct V_1 * V_2 , T_2 V_7 )
{
T_2 V_8 ;
V_7 &= ~ ( V_9 | V_10 | V_11 ) ;
#ifdef F_8
if ( V_2 == NULL )
V_8 = V_9 ;
else
#endif
#if F_9 ( V_12 ) && F_9 ( V_13 )
if ( V_2 -> V_14 < F_10 ( 32 ) )
V_8 = V_9 ;
else if ( V_2 -> V_14 < F_10 ( 64 ) )
V_8 = V_10 ;
else
#endif
#if F_9 ( V_12 ) && ! F_9 ( V_13 )
if ( V_2 -> V_14 < F_10 ( 64 ) )
V_8 = V_10 ;
else
#endif
#if F_9 ( V_13 ) && ! F_9 ( V_12 )
if ( V_2 -> V_14 < F_10 ( 64 ) )
V_8 = V_9 ;
else
#endif
V_8 = 0 ;
V_7 |= V_15 ;
return V_7 | V_8 ;
}
void * F_11 ( struct V_1 * V_2 , T_3 V_16 ,
T_1 * V_17 , T_2 V_7 )
{
void * V_18 ;
V_7 = F_7 ( V_2 , V_7 ) ;
V_18 = ( void * ) F_12 ( V_7 , F_13 ( V_16 ) ) ;
if ( V_18 != NULL ) {
memset ( V_18 , 0 , V_16 ) ;
* V_17 = F_14 ( V_2 , V_18 , V_16 ) ;
}
return V_18 ;
}
static void * F_15 ( struct V_1 * V_2 , T_3 V_16 ,
T_1 * V_17 , T_2 V_7 )
{
void * V_18 ;
if ( F_16 ( V_2 , V_16 , V_17 , & V_18 ) )
return V_18 ;
V_7 = F_7 ( V_2 , V_7 ) ;
V_18 = ( void * ) F_12 ( V_7 , F_13 ( V_16 ) ) ;
if ( V_18 ) {
memset ( V_18 , 0 , V_16 ) ;
* V_17 = F_14 ( V_2 , V_18 , V_16 ) ;
if ( ! F_5 ( V_2 ) ) {
F_17 ( ( unsigned long ) V_18 , V_16 ) ;
V_18 = F_18 ( V_18 ) ;
}
}
return V_18 ;
}
void F_19 ( struct V_1 * V_2 , T_3 V_16 , void * V_19 ,
T_1 V_17 )
{
F_20 ( V_2 , V_17 , V_16 , V_20 ) ;
F_21 ( ( unsigned long ) V_19 , F_13 ( V_16 ) ) ;
}
static void F_22 ( struct V_1 * V_2 , T_3 V_16 , void * V_19 ,
T_1 V_17 )
{
unsigned long V_4 = ( unsigned long ) V_19 ;
int V_21 = F_13 ( V_16 ) ;
if ( F_23 ( V_2 , V_21 , V_19 ) )
return;
F_20 ( V_2 , V_17 , V_16 , V_20 ) ;
if ( ! F_5 ( V_2 ) )
V_4 = F_24 ( V_4 ) ;
F_21 ( V_4 , F_13 ( V_16 ) ) ;
}
static inline void F_25 ( unsigned long V_4 , T_3 V_16 ,
enum V_22 V_23 )
{
switch ( V_23 ) {
case V_24 :
F_26 ( V_4 , V_16 ) ;
break;
case V_25 :
F_27 ( V_4 , V_16 ) ;
break;
case V_20 :
F_17 ( V_4 , V_16 ) ;
break;
default:
F_28 () ;
}
}
static void F_29 ( struct V_1 * V_2 , T_1 V_3 ,
T_3 V_16 , enum V_22 V_23 , struct V_26 * V_27 )
{
if ( F_4 ( V_2 ) )
F_25 ( F_1 ( V_2 , V_3 ) , V_16 ,
V_23 ) ;
F_20 ( V_2 , V_3 , V_16 , V_23 ) ;
}
static int F_30 ( struct V_1 * V_2 , struct V_28 * V_29 ,
int V_30 , enum V_22 V_23 , struct V_26 * V_27 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < V_30 ; V_31 ++ , V_29 ++ ) {
unsigned long V_4 ;
V_4 = ( unsigned long ) F_31 ( V_29 ) ;
if ( ! F_5 ( V_2 ) && V_4 )
F_25 ( V_4 , V_29 -> V_32 , V_23 ) ;
V_29 -> V_33 = F_14 ( V_2 ,
( void * ) V_4 , V_29 -> V_32 ) ;
}
return V_30 ;
}
static T_1 F_32 ( struct V_1 * V_2 , struct V_34 * V_34 ,
unsigned long V_35 , T_3 V_16 , enum V_22 V_23 ,
struct V_26 * V_27 )
{
unsigned long V_4 ;
V_4 = ( unsigned long ) F_33 ( V_34 ) + V_35 ;
if ( ! F_5 ( V_2 ) )
F_25 ( V_4 , V_16 , V_23 ) ;
return F_14 ( V_2 , ( void * ) V_4 , V_16 ) ;
}
static void F_34 ( struct V_1 * V_2 , struct V_28 * V_29 ,
int V_36 , enum V_22 V_23 ,
struct V_26 * V_27 )
{
unsigned long V_4 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_36 ; V_31 ++ , V_29 ++ ) {
if ( ! F_5 ( V_2 ) &&
V_23 != V_24 ) {
V_4 = ( unsigned long ) F_31 ( V_29 ) ;
if ( V_4 )
F_25 ( V_4 , V_29 -> V_32 , V_23 ) ;
}
F_20 ( V_2 , V_29 -> V_33 , V_29 -> V_32 , V_23 ) ;
}
}
static void F_35 ( struct V_1 * V_2 ,
T_1 V_17 , T_3 V_16 , enum V_22 V_23 )
{
if ( F_4 ( V_2 ) ) {
unsigned long V_4 ;
V_4 = F_1 ( V_2 , V_17 ) ;
F_25 ( V_4 , V_16 , V_23 ) ;
}
}
static void F_36 ( struct V_1 * V_2 ,
T_1 V_17 , T_3 V_16 , enum V_22 V_23 )
{
F_37 ( V_2 ) ;
if ( ! F_5 ( V_2 ) ) {
unsigned long V_4 ;
V_4 = F_1 ( V_2 , V_17 ) ;
F_25 ( V_4 , V_16 , V_23 ) ;
}
}
static void F_38 ( struct V_1 * V_2 ,
struct V_28 * V_29 , int V_37 , enum V_22 V_23 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < V_37 ; V_31 ++ , V_29 ++ ) {
if ( F_4 ( V_2 ) )
F_25 ( ( unsigned long ) F_33 ( F_39 ( V_29 ) ) ,
V_29 -> V_32 , V_23 ) ;
}
}
static void F_40 ( struct V_1 * V_2 ,
struct V_28 * V_29 , int V_37 , enum V_22 V_23 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < V_37 ; V_31 ++ , V_29 ++ ) {
if ( ! F_5 ( V_2 ) )
F_25 ( ( unsigned long ) F_33 ( F_39 ( V_29 ) ) ,
V_29 -> V_32 , V_23 ) ;
}
}
int F_41 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_42 ( V_2 , V_3 ) ;
}
int F_43 ( struct V_1 * V_2 , T_4 V_38 )
{
return F_44 ( V_2 , V_38 ) ;
}
void F_45 ( struct V_1 * V_2 , void * V_19 , T_3 V_16 ,
enum V_22 V_23 )
{
F_46 ( V_23 == V_39 ) ;
F_37 ( V_2 ) ;
if ( ! F_5 ( V_2 ) )
F_25 ( ( unsigned long ) V_19 , V_16 , V_23 ) ;
}
static int T_5 F_47 ( void )
{
F_48 ( V_40 ) ;
return 0 ;
}
