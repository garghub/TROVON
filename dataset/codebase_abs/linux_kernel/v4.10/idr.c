static int F_1 ( int V_1 )
{
int V_2 = F_2 ( int , V_1 * V_3 , V_4 ) ;
return ( 1 << V_2 ) - 1 ;
}
static int F_3 ( int V_5 )
{
return ~ F_1 ( V_5 + 1 ) ;
}
static struct V_6 * F_4 ( struct V_7 * V_8 )
{
struct V_6 * V_9 ;
unsigned long V_10 ;
F_5 ( & V_8 -> V_11 , V_10 ) ;
if ( ( V_9 = V_8 -> V_12 ) ) {
V_8 -> V_12 = V_9 -> V_13 [ 0 ] ;
V_8 -> V_14 -- ;
V_9 -> V_13 [ 0 ] = NULL ;
}
F_6 ( & V_8 -> V_11 , V_10 ) ;
return ( V_9 ) ;
}
static struct V_6 * F_7 ( T_1 V_15 , struct V_7 * V_16 )
{
struct V_6 * V_17 ;
if ( V_16 )
return F_4 ( V_16 ) ;
V_17 = F_8 ( V_18 , V_15 | V_19 ) ;
if ( V_17 )
return V_17 ;
if ( ! F_9 () ) {
F_10 () ;
V_17 = F_11 ( V_20 ) ;
if ( V_17 ) {
F_12 ( V_20 , V_17 -> V_13 [ 0 ] ) ;
F_13 ( V_21 ) ;
V_17 -> V_13 [ 0 ] = NULL ;
}
F_14 () ;
if ( V_17 )
return V_17 ;
}
return F_8 ( V_18 , V_15 ) ;
}
static void F_15 ( struct V_22 * V_23 )
{
struct V_6 * V_5 ;
V_5 = F_16 ( V_23 , struct V_6 , V_22 ) ;
F_17 ( V_18 , V_5 ) ;
}
static inline void F_18 ( struct V_7 * V_7 , struct V_6 * V_9 )
{
if ( V_7 -> V_24 == V_9 )
F_19 ( V_7 -> V_24 , NULL ) ;
F_20 ( & V_9 -> V_22 , F_15 ) ;
}
static void F_21 ( struct V_7 * V_8 , struct V_6 * V_9 )
{
V_9 -> V_13 [ 0 ] = V_8 -> V_12 ;
V_8 -> V_12 = V_9 ;
V_8 -> V_14 ++ ;
}
static void F_22 ( struct V_7 * V_8 , struct V_6 * V_9 )
{
unsigned long V_10 ;
F_5 ( & V_8 -> V_11 , V_10 ) ;
F_21 ( V_8 , V_9 ) ;
F_6 ( & V_8 -> V_11 , V_10 ) ;
}
static void F_23 ( struct V_6 * * V_25 , int V_26 )
{
struct V_6 * V_9 = V_25 [ 0 ] ;
int V_27 = 0 ;
F_24 ( V_26 & V_28 , V_9 -> V_29 ) ;
while ( F_25 ( V_9 -> V_29 , V_30 ) ) {
if ( ! ( V_9 = V_25 [ ++ V_27 ] ) )
break;
V_26 = V_26 >> V_3 ;
F_24 ( ( V_26 & V_28 ) , V_9 -> V_29 ) ;
}
}
static int F_26 ( struct V_7 * V_8 , T_1 V_15 )
{
while ( V_8 -> V_14 < V_31 ) {
struct V_6 * V_17 ;
V_17 = F_8 ( V_18 , V_15 ) ;
if ( V_17 == NULL )
return ( 0 ) ;
F_22 ( V_8 , V_17 ) ;
}
return 1 ;
}
static int F_27 ( struct V_7 * V_8 , int * V_32 , struct V_6 * * V_25 ,
T_1 V_15 , struct V_7 * V_16 )
{
int V_33 , V_34 , V_35 ;
struct V_6 * V_9 , * V_17 ;
int V_27 , V_26 , V_36 ;
V_26 = * V_32 ;
V_37:
V_9 = V_8 -> V_38 ;
V_27 = V_8 -> V_1 ;
V_25 [ V_27 -- ] = NULL ;
while ( 1 ) {
V_33 = ( V_26 >> ( V_3 * V_27 ) ) & V_28 ;
V_34 = F_28 ( V_9 -> V_29 , V_30 , V_33 ) ;
if ( V_34 == V_30 ) {
V_27 ++ ;
V_36 = V_26 ;
V_26 = ( V_26 | ( ( 1 << ( V_3 * V_27 ) ) - 1 ) ) + 1 ;
if ( V_26 > F_1 ( V_8 -> V_1 ) ) {
* V_32 = V_26 ;
return - V_39 ;
}
V_9 = V_25 [ V_27 ] ;
F_29 ( ! V_9 ) ;
V_35 = V_3 * ( V_27 + 1 ) ;
if ( V_36 >> V_35 == V_26 >> V_35 )
continue;
else
goto V_37;
}
if ( V_34 != V_33 ) {
V_35 = V_3 * V_27 ;
V_26 = ( ( V_26 >> V_35 ) ^ V_33 ^ V_34 ) << V_35 ;
}
if ( ( V_26 >= V_40 ) || ( V_26 < 0 ) )
return - V_41 ;
if ( V_27 == 0 )
break;
if ( ! V_9 -> V_13 [ V_34 ] ) {
V_17 = F_7 ( V_15 , V_16 ) ;
if ( ! V_17 )
return - V_42 ;
V_17 -> V_5 = V_27 - 1 ;
V_17 -> V_43 = V_26 & F_3 ( V_17 -> V_5 ) ;
F_30 ( V_9 -> V_13 [ V_34 ] , V_17 ) ;
V_9 -> V_44 ++ ;
}
V_25 [ V_27 -- ] = V_9 ;
V_9 = V_9 -> V_13 [ V_34 ] ;
}
V_25 [ V_27 ] = V_9 ;
return V_26 ;
}
static int F_31 ( struct V_7 * V_8 , int V_32 ,
struct V_6 * * V_25 , T_1 V_15 ,
struct V_7 * V_16 )
{
struct V_6 * V_9 , * V_17 ;
int V_1 , V_45 , V_26 ;
unsigned long V_10 ;
V_26 = V_32 ;
V_46:
V_9 = V_8 -> V_38 ;
V_1 = V_8 -> V_1 ;
if ( F_32 ( ! V_9 ) ) {
if ( ! ( V_9 = F_7 ( V_15 , V_16 ) ) )
return - V_42 ;
V_9 -> V_5 = 0 ;
V_1 = 1 ;
}
while ( V_26 > F_1 ( V_1 ) ) {
V_1 ++ ;
if ( ! V_9 -> V_44 ) {
V_9 -> V_5 ++ ;
F_33 ( V_9 -> V_43 ) ;
continue;
}
if ( ! ( V_17 = F_7 ( V_15 , V_16 ) ) ) {
F_5 ( & V_8 -> V_11 , V_10 ) ;
for ( V_17 = V_9 ; V_9 && V_9 != V_8 -> V_38 ; V_17 = V_9 ) {
V_9 = V_9 -> V_13 [ 0 ] ;
V_17 -> V_13 [ 0 ] = NULL ;
V_17 -> V_44 = 0 ;
F_34 ( V_17 -> V_29 , 0 , V_30 ) ;
F_21 ( V_8 , V_17 ) ;
}
F_6 ( & V_8 -> V_11 , V_10 ) ;
return - V_42 ;
}
V_17 -> V_13 [ 0 ] = V_9 ;
V_17 -> V_44 = 1 ;
V_17 -> V_5 = V_1 - 1 ;
V_17 -> V_43 = V_26 & F_3 ( V_17 -> V_5 ) ;
if ( F_25 ( V_9 -> V_29 , V_30 ) )
F_24 ( 0 , V_17 -> V_29 ) ;
V_9 = V_17 ;
}
F_30 ( V_8 -> V_38 , V_9 ) ;
V_8 -> V_1 = V_1 ;
V_45 = F_27 ( V_8 , & V_26 , V_25 , V_15 , V_16 ) ;
if ( V_45 == - V_39 )
goto V_46;
return ( V_45 ) ;
}
static void F_35 ( struct V_7 * V_7 , void * V_47 , int V_26 ,
struct V_6 * * V_25 )
{
F_30 ( V_7 -> V_24 , V_25 [ 0 ] ) ;
F_30 ( V_25 [ 0 ] -> V_13 [ V_26 & V_28 ] , (struct V_6 * ) V_47 ) ;
V_25 [ 0 ] -> V_44 ++ ;
F_23 ( V_25 , V_26 ) ;
}
void F_36 ( T_1 V_15 )
{
F_33 ( F_9 () ) ;
F_37 ( F_38 ( V_15 ) ) ;
F_10 () ;
while ( F_11 ( V_21 ) < V_31 ) {
struct V_6 * V_17 ;
F_14 () ;
V_17 = F_8 ( V_18 , V_15 ) ;
F_10 () ;
if ( ! V_17 )
break;
V_17 -> V_13 [ 0 ] = F_11 ( V_20 ) ;
F_12 ( V_20 , V_17 ) ;
F_39 ( V_21 ) ;
}
}
int F_40 ( struct V_7 * V_7 , void * V_47 , int V_48 , int V_49 , T_1 V_15 )
{
int V_50 = V_49 > 0 ? V_49 - 1 : V_51 ;
struct V_6 * V_25 [ V_52 + 1 ] ;
int V_26 ;
F_37 ( F_38 ( V_15 ) ) ;
if ( F_33 ( V_48 < 0 ) )
return - V_53 ;
if ( F_32 ( V_50 < V_48 ) )
return - V_41 ;
V_26 = F_31 ( V_7 , V_48 , V_25 , V_15 , NULL ) ;
if ( F_32 ( V_26 < 0 ) )
return V_26 ;
if ( F_32 ( V_26 > V_50 ) )
return - V_41 ;
F_35 ( V_7 , V_47 , V_26 , V_25 ) ;
return V_26 ;
}
int F_41 ( struct V_7 * V_7 , void * V_47 , int V_48 , int V_49 ,
T_1 V_15 )
{
int V_26 ;
V_26 = F_40 ( V_7 , V_47 , V_50 ( V_48 , V_7 -> V_54 ) , V_49 , V_15 ) ;
if ( V_26 == - V_41 )
V_26 = F_40 ( V_7 , V_47 , V_48 , V_49 , V_15 ) ;
if ( F_42 ( V_26 >= 0 ) )
V_7 -> V_54 = V_26 + 1 ;
return V_26 ;
}
static void F_43 ( int V_26 )
{
F_44 ( 1 , L_1 , V_26 ) ;
}
static void F_45 ( struct V_7 * V_8 , int V_55 , int V_26 )
{
struct V_6 * V_9 = V_8 -> V_38 ;
struct V_6 * * V_25 [ V_52 + 1 ] ;
struct V_6 * * * V_56 = & V_25 [ 0 ] ;
struct V_6 * V_57 ;
int V_33 ;
* V_56 = NULL ;
* ++ V_56 = & V_8 -> V_38 ;
while ( ( V_55 > 0 ) && V_9 ) {
V_33 = ( V_26 >> V_55 ) & V_28 ;
F_46 ( V_33 , V_9 -> V_29 ) ;
* ++ V_56 = & V_9 -> V_13 [ V_33 ] ;
V_9 = V_9 -> V_13 [ V_33 ] ;
V_55 -= V_3 ;
}
V_33 = V_26 & V_28 ;
if ( F_42 ( V_9 != NULL && F_47 ( V_33 , V_9 -> V_29 ) ) ) {
F_46 ( V_33 , V_9 -> V_29 ) ;
F_19 ( V_9 -> V_13 [ V_33 ] , NULL ) ;
V_57 = NULL ;
while( * V_56 && ! -- ( ( * * V_56 ) -> V_44 ) ) {
if ( V_57 )
F_18 ( V_8 , V_57 ) ;
V_57 = * * V_56 ;
* * V_56 -- = NULL ;
}
if ( ! * V_56 )
V_8 -> V_1 = 0 ;
if ( V_57 )
F_18 ( V_8 , V_57 ) ;
} else
F_43 ( V_26 ) ;
}
void F_48 ( struct V_7 * V_8 , int V_26 )
{
struct V_6 * V_9 ;
struct V_6 * V_57 ;
if ( V_26 < 0 )
return;
if ( V_26 > F_1 ( V_8 -> V_1 ) ) {
F_43 ( V_26 ) ;
return;
}
F_45 ( V_8 , ( V_8 -> V_1 - 1 ) * V_3 , V_26 ) ;
if ( V_8 -> V_38 && V_8 -> V_38 -> V_44 == 1 && ( V_8 -> V_1 > 1 ) &&
V_8 -> V_38 -> V_13 [ 0 ] ) {
V_57 = V_8 -> V_38 ;
V_9 = V_8 -> V_38 -> V_13 [ 0 ] ;
F_30 ( V_8 -> V_38 , V_9 ) ;
-- V_8 -> V_1 ;
V_57 -> V_44 = 0 ;
F_34 ( V_57 -> V_29 , 0 , V_30 ) ;
F_18 ( V_8 , V_57 ) ;
}
}
static void F_49 ( struct V_7 * V_8 )
{
int V_33 , V_26 , V_50 ;
int V_58 ;
struct V_6 * V_9 ;
struct V_6 * V_25 [ V_52 + 1 ] ;
struct V_6 * * V_56 = & V_25 [ 0 ] ;
V_33 = V_8 -> V_1 * V_3 ;
* V_56 = V_8 -> V_38 ;
F_19 ( V_8 -> V_38 , NULL ) ;
V_50 = F_1 ( V_8 -> V_1 ) ;
V_26 = 0 ;
while ( V_26 >= 0 && V_26 <= V_50 ) {
V_9 = * V_56 ;
while ( V_33 > V_3 && V_9 ) {
V_33 -= V_3 ;
V_9 = V_9 -> V_13 [ ( V_26 >> V_33 ) & V_28 ] ;
* ++ V_56 = V_9 ;
}
V_58 = V_26 ;
V_26 += 1 << V_33 ;
while ( V_33 < F_50 ( V_26 ^ V_58 ) ) {
if ( * V_56 )
F_18 ( V_8 , * V_56 ) ;
V_33 += V_3 ;
-- V_56 ;
}
}
V_8 -> V_1 = 0 ;
}
void F_51 ( struct V_7 * V_8 )
{
F_49 ( V_8 ) ;
while ( V_8 -> V_14 ) {
struct V_6 * V_9 = F_4 ( V_8 ) ;
F_17 ( V_18 , V_9 ) ;
}
}
void * F_52 ( struct V_7 * V_8 , int V_26 )
{
int V_33 ;
struct V_6 * V_9 ;
if ( V_26 < 0 )
return NULL ;
V_9 = F_53 ( V_8 -> V_38 ) ;
if ( ! V_9 )
return NULL ;
V_33 = ( V_9 -> V_5 + 1 ) * V_3 ;
if ( V_26 > F_1 ( V_9 -> V_5 + 1 ) )
return NULL ;
F_29 ( V_33 == 0 ) ;
while ( V_33 > 0 && V_9 ) {
V_33 -= V_3 ;
F_29 ( V_33 != V_9 -> V_5 * V_3 ) ;
V_9 = F_53 ( V_9 -> V_13 [ ( V_26 >> V_33 ) & V_28 ] ) ;
}
return ( ( void * ) V_9 ) ;
}
int F_54 ( struct V_7 * V_8 ,
int (* F_55)( int V_26 , void * V_9 , void * V_59 ) , void * V_59 )
{
int V_33 , V_26 , V_50 , error = 0 ;
struct V_6 * V_9 ;
struct V_6 * V_25 [ V_52 + 1 ] ;
struct V_6 * * V_56 = & V_25 [ 0 ] ;
V_33 = V_8 -> V_1 * V_3 ;
* V_56 = F_53 ( V_8 -> V_38 ) ;
V_50 = F_1 ( V_8 -> V_1 ) ;
V_26 = 0 ;
while ( V_26 >= 0 && V_26 <= V_50 ) {
V_9 = * V_56 ;
while ( V_33 > 0 && V_9 ) {
V_33 -= V_3 ;
V_9 = F_53 ( V_9 -> V_13 [ ( V_26 >> V_33 ) & V_28 ] ) ;
* ++ V_56 = V_9 ;
}
if ( V_9 ) {
error = F_55 ( V_26 , ( void * ) V_9 , V_59 ) ;
if ( error )
break;
}
V_26 += 1 << V_33 ;
while ( V_33 < F_50 ( V_26 ) ) {
V_33 += V_3 ;
-- V_56 ;
}
}
return error ;
}
void * F_56 ( struct V_7 * V_8 , int * V_60 )
{
struct V_6 * V_9 , * V_25 [ V_52 + 1 ] ;
struct V_6 * * V_56 = & V_25 [ 0 ] ;
int V_26 = * V_60 ;
int V_33 , V_50 ;
V_9 = * V_56 = F_53 ( V_8 -> V_38 ) ;
if ( ! V_9 )
return NULL ;
V_33 = ( V_9 -> V_5 + 1 ) * V_3 ;
V_50 = F_1 ( V_9 -> V_5 + 1 ) ;
while ( V_26 >= 0 && V_26 <= V_50 ) {
V_9 = * V_56 ;
while ( V_33 > 0 && V_9 ) {
V_33 -= V_3 ;
V_9 = F_53 ( V_9 -> V_13 [ ( V_26 >> V_33 ) & V_28 ] ) ;
* ++ V_56 = V_9 ;
}
if ( V_9 ) {
* V_60 = V_26 ;
return V_9 ;
}
V_26 = F_57 ( V_26 + 1 , 1 << V_33 ) ;
while ( V_33 < F_50 ( V_26 ) ) {
V_33 += V_3 ;
-- V_56 ;
}
}
return NULL ;
}
void * F_58 ( struct V_7 * V_8 , void * V_47 , int V_26 )
{
int V_33 ;
struct V_6 * V_9 , * V_61 ;
if ( V_26 < 0 )
return F_59 ( - V_53 ) ;
V_9 = V_8 -> V_38 ;
if ( ! V_9 )
return F_59 ( - V_62 ) ;
if ( V_26 > F_1 ( V_9 -> V_5 + 1 ) )
return F_59 ( - V_62 ) ;
V_33 = V_9 -> V_5 * V_3 ;
while ( ( V_33 > 0 ) && V_9 ) {
V_9 = V_9 -> V_13 [ ( V_26 >> V_33 ) & V_28 ] ;
V_33 -= V_3 ;
}
V_33 = V_26 & V_28 ;
if ( F_32 ( V_9 == NULL || ! F_47 ( V_33 , V_9 -> V_29 ) ) )
return F_59 ( - V_62 ) ;
V_61 = V_9 -> V_13 [ V_33 ] ;
F_30 ( V_9 -> V_13 [ V_33 ] , V_47 ) ;
return V_61 ;
}
void T_2 F_60 ( void )
{
V_18 = F_61 ( L_2 ,
sizeof( struct V_6 ) , 0 , V_63 , NULL ) ;
}
void F_62 ( struct V_7 * V_8 )
{
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
F_63 ( & V_8 -> V_11 ) ;
}
static int F_64 ( int V_26 , void * V_9 , void * V_59 )
{
return 1 ;
}
bool F_65 ( struct V_7 * V_8 )
{
return ! F_54 ( V_8 , F_64 , NULL ) ;
}
static void F_66 ( struct V_64 * V_64 , struct V_65 * V_29 )
{
unsigned long V_10 ;
if ( ! V_64 -> F_66 ) {
F_5 ( & V_64 -> V_7 . V_11 , V_10 ) ;
if ( ! V_64 -> F_66 ) {
V_64 -> F_66 = V_29 ;
V_29 = NULL ;
}
F_6 ( & V_64 -> V_7 . V_11 , V_10 ) ;
}
F_67 ( V_29 ) ;
}
int F_68 ( struct V_64 * V_64 , T_1 V_15 )
{
if ( ! F_26 ( & V_64 -> V_7 , V_15 ) )
return 0 ;
if ( ! V_64 -> F_66 ) {
struct V_65 * V_29 ;
V_29 = F_69 ( sizeof( struct V_65 ) , V_15 ) ;
if ( ! V_29 )
return 0 ;
F_66 ( V_64 , V_29 ) ;
}
return 1 ;
}
int F_70 ( struct V_64 * V_64 , int V_32 , int * V_66 )
{
struct V_6 * V_25 [ V_52 + 1 ] ;
struct V_65 * V_29 ;
unsigned long V_10 ;
int V_67 = V_32 / V_68 ;
int V_69 = V_32 % V_68 ;
int V_70 , V_26 ;
V_37:
V_70 = F_31 ( & V_64 -> V_7 , V_67 , V_25 , 0 , & V_64 -> V_7 ) ;
if ( V_70 < 0 )
return V_70 == - V_42 ? - V_39 : V_70 ;
if ( V_70 * V_68 >= V_40 )
return - V_41 ;
if ( V_70 != V_67 )
V_69 = 0 ;
V_67 = V_70 ;
V_29 = ( void * ) V_25 [ 0 ] -> V_13 [ V_67 & V_28 ] ;
if ( ! V_29 ) {
F_5 ( & V_64 -> V_7 . V_11 , V_10 ) ;
V_29 = V_64 -> F_66 ;
V_64 -> F_66 = NULL ;
F_6 ( & V_64 -> V_7 . V_11 , V_10 ) ;
if ( ! V_29 )
return - V_39 ;
memset ( V_29 , 0 , sizeof( struct V_65 ) ) ;
F_30 ( V_25 [ 0 ] -> V_13 [ V_67 & V_28 ] ,
( void * ) V_29 ) ;
V_25 [ 0 ] -> V_44 ++ ;
}
V_70 = F_28 ( V_29 -> V_29 , V_68 , V_69 ) ;
if ( V_70 == V_68 ) {
V_67 ++ ;
V_69 = 0 ;
goto V_37;
}
V_26 = V_67 * V_68 + V_70 ;
if ( V_26 >= V_40 )
return - V_41 ;
F_24 ( V_70 , V_29 -> V_29 ) ;
if ( ++ V_29 -> V_71 == V_68 )
F_23 ( V_25 , V_67 ) ;
* V_66 = V_26 ;
if ( V_64 -> V_7 . V_14 || V_64 -> F_66 ) {
struct V_6 * V_9 = F_4 ( & V_64 -> V_7 ) ;
if ( V_9 )
F_17 ( V_18 , V_9 ) ;
}
return 0 ;
}
void F_71 ( struct V_64 * V_64 , int V_26 )
{
struct V_6 * V_9 = V_64 -> V_7 . V_38 ;
int V_55 = ( V_64 -> V_7 . V_1 - 1 ) * V_3 ;
int V_67 = V_26 / V_68 ;
int V_69 = V_26 % V_68 ;
int V_33 ;
struct V_65 * V_29 ;
if ( V_67 > F_1 ( V_64 -> V_7 . V_1 ) )
goto V_72;
while ( ( V_55 > 0 ) && V_9 ) {
V_33 = ( V_67 >> V_55 ) & V_28 ;
F_46 ( V_33 , V_9 -> V_29 ) ;
V_9 = V_9 -> V_13 [ V_33 ] ;
V_55 -= V_3 ;
}
if ( V_9 == NULL )
goto V_72;
V_33 = V_67 & V_28 ;
F_46 ( V_33 , V_9 -> V_29 ) ;
V_29 = ( void * ) V_9 -> V_13 [ V_33 ] ;
if ( ! V_29 || ! F_47 ( V_69 , V_29 -> V_29 ) )
goto V_72;
F_46 ( V_69 , V_29 -> V_29 ) ;
if ( -- V_29 -> V_71 == 0 ) {
F_24 ( V_33 , V_9 -> V_29 ) ;
F_48 ( & V_64 -> V_7 , V_67 ) ;
F_66 ( V_64 , V_29 ) ;
}
return;
V_72:
F_44 ( 1 , L_3 , V_26 ) ;
}
void F_72 ( struct V_64 * V_64 )
{
F_51 ( & V_64 -> V_7 ) ;
F_67 ( V_64 -> F_66 ) ;
}
int F_73 ( struct V_64 * V_64 , unsigned int V_48 , unsigned int V_49 ,
T_1 V_15 )
{
int V_73 , V_26 ;
unsigned int V_50 ;
unsigned long V_10 ;
F_29 ( ( int ) V_48 < 0 ) ;
F_29 ( ( int ) V_49 < 0 ) ;
if ( V_49 == 0 )
V_50 = 0x80000000 ;
else {
F_29 ( V_49 < V_48 ) ;
V_50 = V_49 - 1 ;
}
V_74:
if ( ! F_68 ( V_64 , V_15 ) )
return - V_42 ;
F_5 ( & V_75 , V_10 ) ;
V_73 = F_70 ( V_64 , V_48 , & V_26 ) ;
if ( ! V_73 ) {
if ( V_26 > V_50 ) {
F_71 ( V_64 , V_26 ) ;
V_73 = - V_41 ;
} else {
V_73 = V_26 ;
}
}
F_6 ( & V_75 , V_10 ) ;
if ( F_32 ( V_73 == - V_39 ) )
goto V_74;
return V_73 ;
}
void F_74 ( struct V_64 * V_64 , unsigned int V_26 )
{
unsigned long V_10 ;
F_29 ( ( int ) V_26 < 0 ) ;
F_5 ( & V_75 , V_10 ) ;
F_71 ( V_64 , V_26 ) ;
F_6 ( & V_75 , V_10 ) ;
}
void F_75 ( struct V_64 * V_64 )
{
memset ( V_64 , 0 , sizeof( struct V_64 ) ) ;
F_62 ( & V_64 -> V_7 ) ;
}
