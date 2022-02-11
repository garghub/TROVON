static struct V_1 * F_1 ( unsigned long V_2 )
{
struct V_1 * V_1 ;
struct V_3 * V_3 ;
if ( ! F_2 ( V_2 ) )
return NULL ;
V_1 = F_3 ( V_2 ) ;
if ( ! V_1 || ! F_4 ( V_1 ) ||
! F_5 ( V_1 ) )
return NULL ;
V_3 = F_6 ( V_1 ) ;
F_7 ( F_8 ( V_3 ) ) ;
if ( F_9 ( ! F_4 ( V_1 ) ) ) {
F_10 ( V_1 ) ;
V_1 = NULL ;
}
F_11 ( F_8 ( V_3 ) ) ;
return V_1 ;
}
static int F_12 ( struct V_1 * V_1 ,
struct V_4 * V_5 ,
unsigned long V_6 , void * V_7 )
{
struct V_8 * V_9 = V_5 -> V_10 ;
T_1 * V_11 ;
T_2 * V_12 ;
T_3 * V_13 ;
bool V_14 = false ;
if ( ! F_13 ( V_1 , V_9 , V_6 , & V_11 , & V_12 , & V_13 ) )
return V_15 ;
if ( V_12 ) {
V_14 = F_14 ( V_5 , V_6 , V_12 ) ;
F_15 ( V_12 ) ;
} else if ( F_16 ( V_16 ) ) {
V_14 = F_17 ( V_5 , V_6 , V_11 ) ;
} else {
F_18 ( 1 ) ;
}
F_19 ( V_13 ) ;
if ( V_14 ) {
F_20 ( V_1 ) ;
F_21 ( V_1 ) ;
}
return V_15 ;
}
static void F_22 ( struct V_1 * V_1 )
{
static const struct V_17 V_18 = {
. V_19 = F_12 ,
. V_20 = V_21 ,
} ;
bool V_22 ;
if ( ! F_23 ( V_1 ) ||
! F_24 ( V_1 ) )
return;
V_22 = ! F_25 ( V_1 ) || F_26 ( V_1 ) ;
if ( V_22 && ! F_27 ( V_1 ) )
return;
F_28 ( V_1 , (struct V_17 * ) & V_18 ) ;
if ( V_22 )
F_29 ( V_1 ) ;
}
static T_4 F_30 ( struct V_23 * V_23 , struct V_24 * V_25 ,
struct V_26 * V_27 , char * V_28 ,
T_5 V_29 , T_6 V_30 )
{
T_7 * V_31 = ( T_7 * ) V_28 ;
struct V_1 * V_1 ;
unsigned long V_2 , V_32 ;
int V_33 ;
if ( V_29 % V_34 || V_30 % V_34 )
return - V_35 ;
V_2 = V_29 * V_36 ;
if ( V_2 >= V_37 )
return 0 ;
V_32 = V_2 + V_30 * V_36 ;
if ( V_32 > V_37 )
V_32 = F_31 ( V_37 , V_38 ) ;
for (; V_2 < V_32 ; V_2 ++ ) {
V_33 = V_2 % V_38 ;
if ( ! V_33 )
* V_31 = 0ULL ;
V_1 = F_1 ( V_2 ) ;
if ( V_1 ) {
if ( F_32 ( V_1 ) ) {
F_22 ( V_1 ) ;
if ( F_32 ( V_1 ) )
* V_31 |= 1ULL << V_33 ;
}
F_10 ( V_1 ) ;
}
if ( V_33 == V_38 - 1 )
V_31 ++ ;
F_33 () ;
}
return ( char * ) V_31 - V_28 ;
}
static T_4 F_34 ( struct V_23 * V_23 , struct V_24 * V_25 ,
struct V_26 * V_27 , char * V_28 ,
T_5 V_29 , T_6 V_30 )
{
const T_7 * V_39 = ( T_7 * ) V_28 ;
struct V_1 * V_1 ;
unsigned long V_2 , V_32 ;
int V_33 ;
if ( V_29 % V_34 || V_30 % V_34 )
return - V_35 ;
V_2 = V_29 * V_36 ;
if ( V_2 >= V_37 )
return - V_40 ;
V_32 = V_2 + V_30 * V_36 ;
if ( V_32 > V_37 )
V_32 = F_31 ( V_37 , V_38 ) ;
for (; V_2 < V_32 ; V_2 ++ ) {
V_33 = V_2 % V_38 ;
if ( ( * V_39 >> V_33 ) & 1 ) {
V_1 = F_1 ( V_2 ) ;
if ( V_1 ) {
F_22 ( V_1 ) ;
F_35 ( V_1 ) ;
F_10 ( V_1 ) ;
}
}
if ( V_33 == V_38 - 1 )
V_39 ++ ;
F_33 () ;
}
return ( char * ) V_39 - V_28 ;
}
static bool F_36 ( void )
{
return true ;
}
static int T_8 F_37 ( void )
{
int V_41 ;
V_41 = F_38 ( V_42 , & V_43 ) ;
if ( V_41 ) {
F_39 ( L_1 ) ;
return V_41 ;
}
return 0 ;
}
