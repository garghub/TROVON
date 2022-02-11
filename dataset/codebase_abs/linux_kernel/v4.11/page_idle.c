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
struct V_8 V_9 = {
. V_1 = V_1 ,
. V_5 = V_5 ,
. V_10 = V_6 ,
} ;
bool V_11 = false ;
while ( V_8 ( & V_9 ) ) {
V_6 = V_9 . V_10 ;
if ( V_9 . V_12 ) {
V_11 = F_13 ( V_5 , V_6 ,
V_9 . V_12 ) ;
} else if ( F_14 ( V_13 ) ) {
V_11 = F_15 ( V_5 , V_6 ,
V_9 . V_14 ) ;
} else {
F_16 ( 1 ) ;
}
}
if ( V_11 ) {
F_17 ( V_1 ) ;
F_18 ( V_1 ) ;
}
return V_15 ;
}
static void F_19 ( struct V_1 * V_1 )
{
static const struct V_16 V_17 = {
. V_18 = F_12 ,
. V_19 = V_20 ,
} ;
bool V_21 ;
if ( ! F_20 ( V_1 ) ||
! F_21 ( V_1 ) )
return;
V_21 = ! F_22 ( V_1 ) || F_23 ( V_1 ) ;
if ( V_21 && ! F_24 ( V_1 ) )
return;
F_25 ( V_1 , (struct V_16 * ) & V_17 ) ;
if ( V_21 )
F_26 ( V_1 ) ;
}
static T_1 F_27 ( struct V_22 * V_22 , struct V_23 * V_24 ,
struct V_25 * V_26 , char * V_27 ,
T_2 V_28 , T_3 V_29 )
{
T_4 * V_30 = ( T_4 * ) V_27 ;
struct V_1 * V_1 ;
unsigned long V_2 , V_31 ;
int V_32 ;
if ( V_28 % V_33 || V_29 % V_33 )
return - V_34 ;
V_2 = V_28 * V_35 ;
if ( V_2 >= V_36 )
return 0 ;
V_31 = V_2 + V_29 * V_35 ;
if ( V_31 > V_36 )
V_31 = F_28 ( V_36 , V_37 ) ;
for (; V_2 < V_31 ; V_2 ++ ) {
V_32 = V_2 % V_37 ;
if ( ! V_32 )
* V_30 = 0ULL ;
V_1 = F_1 ( V_2 ) ;
if ( V_1 ) {
if ( F_29 ( V_1 ) ) {
F_19 ( V_1 ) ;
if ( F_29 ( V_1 ) )
* V_30 |= 1ULL << V_32 ;
}
F_10 ( V_1 ) ;
}
if ( V_32 == V_37 - 1 )
V_30 ++ ;
F_30 () ;
}
return ( char * ) V_30 - V_27 ;
}
static T_1 F_31 ( struct V_22 * V_22 , struct V_23 * V_24 ,
struct V_25 * V_26 , char * V_27 ,
T_2 V_28 , T_3 V_29 )
{
const T_4 * V_38 = ( T_4 * ) V_27 ;
struct V_1 * V_1 ;
unsigned long V_2 , V_31 ;
int V_32 ;
if ( V_28 % V_33 || V_29 % V_33 )
return - V_34 ;
V_2 = V_28 * V_35 ;
if ( V_2 >= V_36 )
return - V_39 ;
V_31 = V_2 + V_29 * V_35 ;
if ( V_31 > V_36 )
V_31 = F_28 ( V_36 , V_37 ) ;
for (; V_2 < V_31 ; V_2 ++ ) {
V_32 = V_2 % V_37 ;
if ( ( * V_38 >> V_32 ) & 1 ) {
V_1 = F_1 ( V_2 ) ;
if ( V_1 ) {
F_19 ( V_1 ) ;
F_32 ( V_1 ) ;
F_10 ( V_1 ) ;
}
}
if ( V_32 == V_37 - 1 )
V_38 ++ ;
F_30 () ;
}
return ( char * ) V_38 - V_27 ;
}
static bool F_33 ( void )
{
return true ;
}
static int T_5 F_34 ( void )
{
int V_40 ;
V_40 = F_35 ( V_41 , & V_42 ) ;
if ( V_40 ) {
F_36 ( L_1 ) ;
return V_40 ;
}
return 0 ;
}
