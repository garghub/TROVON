void F_1 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 ,
enum V_5 V_6 )
{
switch ( V_6 ) {
case V_7 :
F_2 ( ( unsigned long ) V_3 , V_4 ) ;
break;
case V_8 :
F_3 ( ( unsigned long ) V_3 , V_4 ) ;
break;
case V_9 :
F_4 ( ( unsigned long ) V_3 , V_4 ) ;
break;
case V_10 :
F_5 () ;
break;
}
}
static void F_6 ( T_2 V_11 , T_1 V_4 ,
void (* F_7)( unsigned long , unsigned long ) )
{
unsigned long V_12 = V_11 & ( V_13 - 1 ) ;
unsigned long V_14 = F_8 ( V_11 ) ;
struct V_15 * V_15 = F_9 ( V_14 ) ;
if ( ! F_10 ( V_15 ) )
F_7 ( ( unsigned long ) F_11 ( V_11 ) , V_4 ) ;
else
while ( V_4 > 0 ) {
T_1 V_16 = F_12 ( T_1 , V_4 , V_13 - V_12 ) ;
void * V_3 = F_13 ( V_15 ) ;
F_7 ( ( unsigned long ) V_3 + V_12 , V_16 ) ;
F_14 ( V_3 ) ;
V_12 = 0 ;
++ V_15 ;
V_4 -= V_16 ;
}
}
static void F_15 ( struct V_1 * V_2 ,
T_2 V_11 , T_1 V_4 ,
enum V_5 V_6 )
{
switch ( V_6 ) {
case V_7 :
case V_8 :
F_6 ( V_11 , V_4 , F_3 ) ;
break;
case V_10 :
F_5 () ;
break;
default:
break;
}
}
static void F_16 ( struct V_1 * V_2 ,
T_2 V_11 , T_1 V_4 ,
enum V_5 V_6 )
{
switch ( V_6 ) {
case V_7 :
case V_9 :
if ( V_17 )
F_6 ( V_11 , V_4 , F_4 ) ;
break;
case V_10 :
F_5 () ;
break;
default:
break;
}
}
static void F_17 ( struct V_1 * V_2 ,
struct V_18 * V_19 , int V_20 ,
enum V_5 V_6 )
{
struct V_18 * V_21 ;
int V_22 ;
F_18 (sg, s, nents, i) {
F_15 ( V_2 , F_19 ( V_21 ) ,
F_20 ( V_21 ) , V_6 ) ;
}
}
static void F_21 ( struct V_1 * V_2 ,
struct V_18 * V_19 , int V_20 ,
enum V_5 V_6 )
{
struct V_18 * V_21 ;
int V_22 ;
F_18 (sg, s, nents, i) {
F_16 ( V_2 , F_19 ( V_21 ) ,
F_20 ( V_21 ) , V_6 ) ;
}
}
static void * F_22 ( struct V_1 * V_2 , T_1 V_4 ,
T_2 * V_23 , T_3 V_24 ,
unsigned long V_25 )
{
unsigned long V_26 ;
unsigned long V_27 = 0 ;
unsigned long V_28 = F_23 ( V_4 ) >> V_29 ;
struct V_15 * V_15 = NULL ;
V_24 &= ~ ( V_30 | V_31 ) ;
if ( V_2 == NULL || ( V_2 -> V_32 < 0xffffffff ) )
V_24 |= V_33 ;
if ( F_24 ( V_24 ) )
V_15 = F_25 ( V_2 , V_28 , F_26 ( V_4 ) ,
V_24 ) ;
if ( ! V_15 )
V_15 = F_27 ( V_24 , F_26 ( V_4 ) ) ;
if ( ! V_15 )
return NULL ;
V_26 = ( unsigned long ) F_28 ( V_15 ) ;
F_29 ( V_26 < V_34 ||
V_26 > V_34 + V_35 - 1 ) ;
V_27 = V_26 + V_36 - V_34 ;
* V_23 = F_30 ( ( void * ) V_26 ) ;
F_3 ( V_26 , V_4 ) ;
return ( void * ) V_27 ;
}
static void F_31 ( struct V_1 * V_2 , T_1 V_4 , void * V_3 ,
T_2 V_11 , unsigned long V_25 )
{
unsigned long V_37 = ( unsigned long ) V_3 +
V_34 - V_36 ;
struct V_15 * V_15 = F_32 ( V_37 ) ;
unsigned long V_28 = F_23 ( V_4 ) >> V_29 ;
F_29 ( V_37 < V_34 ||
V_37 > V_34 + V_35 - 1 ) ;
if ( ! F_33 ( V_2 , V_15 , V_28 ) )
F_34 ( V_15 , F_26 ( V_4 ) ) ;
}
static T_2 F_35 ( struct V_1 * V_2 , struct V_15 * V_15 ,
unsigned long V_38 , T_1 V_4 ,
enum V_5 V_6 ,
unsigned long V_25 )
{
T_2 V_11 = F_36 ( V_15 ) + V_38 ;
if ( ! ( V_25 & V_39 ) )
F_16 ( V_2 , V_11 , V_4 , V_6 ) ;
return V_11 ;
}
static void F_37 ( struct V_1 * V_2 , T_2 V_11 ,
T_1 V_4 , enum V_5 V_6 ,
unsigned long V_25 )
{
if ( ! ( V_25 & V_39 ) )
F_15 ( V_2 , V_11 , V_4 , V_6 ) ;
}
static int F_38 ( struct V_1 * V_2 , struct V_18 * V_19 ,
int V_20 , enum V_5 V_6 ,
unsigned long V_25 )
{
struct V_18 * V_21 ;
int V_22 ;
F_18 (sg, s, nents, i) {
V_21 -> V_40 = F_35 ( V_2 , F_39 ( V_21 ) , V_21 -> V_38 ,
V_21 -> V_41 , V_6 , V_25 ) ;
}
return V_20 ;
}
static void F_40 ( struct V_1 * V_2 ,
struct V_18 * V_19 , int V_20 ,
enum V_5 V_6 ,
unsigned long V_25 )
{
struct V_18 * V_21 ;
int V_22 ;
F_18 (sg, s, nents, i) {
F_37 ( V_2 , F_19 ( V_21 ) ,
F_20 ( V_21 ) , V_6 , V_25 ) ;
}
}
int F_41 ( struct V_1 * V_2 , T_2 V_42 )
{
return 0 ;
}
static int T_4 F_42 ( void )
{
F_43 ( V_43 ) ;
return 0 ;
}
