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
F_7 ( & V_3 -> V_4 ) ;
if ( F_8 ( ! F_4 ( V_1 ) ) ) {
F_9 ( V_1 ) ;
V_1 = NULL ;
}
F_10 ( & V_3 -> V_4 ) ;
return V_1 ;
}
static int F_11 ( struct V_1 * V_1 ,
struct V_5 * V_6 ,
unsigned long V_7 , void * V_8 )
{
struct V_9 * V_10 = V_6 -> V_11 ;
T_1 * V_12 ;
T_2 * V_13 ;
T_3 * V_14 ;
bool V_15 = false ;
if ( ! F_12 ( V_1 , V_10 , V_7 , & V_12 , & V_13 , & V_14 ) )
return V_16 ;
if ( V_13 ) {
V_15 = F_13 ( V_6 , V_7 , V_13 ) ;
F_14 ( V_13 ) ;
} else if ( F_15 ( V_17 ) ) {
V_15 = F_16 ( V_6 , V_7 , V_12 ) ;
} else {
F_17 ( 1 ) ;
}
F_18 ( V_14 ) ;
if ( V_15 ) {
F_19 ( V_1 ) ;
F_20 ( V_1 ) ;
}
return V_16 ;
}
static void F_21 ( struct V_1 * V_1 )
{
static const struct V_18 V_19 = {
. V_20 = F_11 ,
. V_21 = V_22 ,
} ;
bool V_23 ;
if ( ! F_22 ( V_1 ) ||
! F_23 ( V_1 ) )
return;
V_23 = ! F_24 ( V_1 ) || F_25 ( V_1 ) ;
if ( V_23 && ! F_26 ( V_1 ) )
return;
F_27 ( V_1 , (struct V_18 * ) & V_19 ) ;
if ( V_23 )
F_28 ( V_1 ) ;
}
static T_4 F_29 ( struct V_24 * V_24 , struct V_25 * V_26 ,
struct V_27 * V_28 , char * V_29 ,
T_5 V_30 , T_6 V_31 )
{
T_7 * V_32 = ( T_7 * ) V_29 ;
struct V_1 * V_1 ;
unsigned long V_2 , V_33 ;
int V_34 ;
if ( V_30 % V_35 || V_31 % V_35 )
return - V_36 ;
V_2 = V_30 * V_37 ;
if ( V_2 >= V_38 )
return 0 ;
V_33 = V_2 + V_31 * V_37 ;
if ( V_33 > V_38 )
V_33 = F_30 ( V_38 , V_39 ) ;
for (; V_2 < V_33 ; V_2 ++ ) {
V_34 = V_2 % V_39 ;
if ( ! V_34 )
* V_32 = 0ULL ;
V_1 = F_1 ( V_2 ) ;
if ( V_1 ) {
if ( F_31 ( V_1 ) ) {
F_21 ( V_1 ) ;
if ( F_31 ( V_1 ) )
* V_32 |= 1ULL << V_34 ;
}
F_9 ( V_1 ) ;
}
if ( V_34 == V_39 - 1 )
V_32 ++ ;
F_32 () ;
}
return ( char * ) V_32 - V_29 ;
}
static T_4 F_33 ( struct V_24 * V_24 , struct V_25 * V_26 ,
struct V_27 * V_28 , char * V_29 ,
T_5 V_30 , T_6 V_31 )
{
const T_7 * V_40 = ( T_7 * ) V_29 ;
struct V_1 * V_1 ;
unsigned long V_2 , V_33 ;
int V_34 ;
if ( V_30 % V_35 || V_31 % V_35 )
return - V_36 ;
V_2 = V_30 * V_37 ;
if ( V_2 >= V_38 )
return - V_41 ;
V_33 = V_2 + V_31 * V_37 ;
if ( V_33 > V_38 )
V_33 = F_30 ( V_38 , V_39 ) ;
for (; V_2 < V_33 ; V_2 ++ ) {
V_34 = V_2 % V_39 ;
if ( ( * V_40 >> V_34 ) & 1 ) {
V_1 = F_1 ( V_2 ) ;
if ( V_1 ) {
F_21 ( V_1 ) ;
F_34 ( V_1 ) ;
F_9 ( V_1 ) ;
}
}
if ( V_34 == V_39 - 1 )
V_40 ++ ;
F_32 () ;
}
return ( char * ) V_40 - V_29 ;
}
static bool F_35 ( void )
{
return true ;
}
static int T_8 F_36 ( void )
{
int V_42 ;
V_42 = F_37 ( V_43 , & V_44 ) ;
if ( V_42 ) {
F_38 ( L_1 ) ;
return V_42 ;
}
return 0 ;
}
