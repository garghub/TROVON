static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
unsigned long V_5 ;
F_2 ( & V_3 -> V_6 , V_5 ) ;
if ( ( V_4 = V_3 -> V_7 ) ) {
V_3 -> V_7 = V_4 -> V_8 [ 0 ] ;
V_3 -> V_9 -- ;
V_4 -> V_8 [ 0 ] = NULL ;
}
F_3 ( & V_3 -> V_6 , V_5 ) ;
return ( V_4 ) ;
}
static void F_4 ( struct V_10 * V_11 )
{
struct V_1 * V_12 ;
V_12 = F_5 ( V_11 , struct V_1 , V_10 ) ;
F_6 ( V_13 , V_12 ) ;
}
static inline void F_7 ( struct V_1 * V_4 )
{
F_8 ( & V_4 -> V_10 , F_4 ) ;
}
static void F_9 ( struct V_2 * V_3 , struct V_1 * V_4 )
{
V_4 -> V_8 [ 0 ] = V_3 -> V_7 ;
V_3 -> V_7 = V_4 ;
V_3 -> V_9 ++ ;
}
static void F_10 ( struct V_2 * V_3 , struct V_1 * V_4 )
{
unsigned long V_5 ;
F_2 ( & V_3 -> V_6 , V_5 ) ;
F_9 ( V_3 , V_4 ) ;
F_3 ( & V_3 -> V_6 , V_5 ) ;
}
static void F_11 ( struct V_1 * * V_14 , int V_15 )
{
struct V_1 * V_4 = V_14 [ 0 ] ;
int V_16 = 0 ;
F_12 ( V_15 & V_17 , & V_4 -> V_18 ) ;
while ( V_4 -> V_18 == V_19 ) {
if ( ! ( V_4 = V_14 [ ++ V_16 ] ) )
break;
V_15 = V_15 >> V_20 ;
F_12 ( ( V_15 & V_17 ) , & V_4 -> V_18 ) ;
}
}
int F_13 ( struct V_2 * V_3 , T_1 V_21 )
{
while ( V_3 -> V_9 < V_22 ) {
struct V_1 * V_23 ;
V_23 = F_14 ( V_13 , V_21 ) ;
if ( V_23 == NULL )
return ( 0 ) ;
F_10 ( V_3 , V_23 ) ;
}
return 1 ;
}
static int F_15 ( struct V_2 * V_3 , int * V_24 , struct V_1 * * V_14 )
{
int V_25 , V_26 , V_27 ;
struct V_1 * V_4 , * V_23 ;
int V_16 , V_15 , V_28 ;
unsigned long V_29 ;
V_15 = * V_24 ;
V_30:
V_4 = V_3 -> V_31 ;
V_16 = V_3 -> V_32 ;
V_14 [ V_16 -- ] = NULL ;
while ( 1 ) {
V_25 = ( V_15 >> ( V_20 * V_16 ) ) & V_17 ;
V_29 = ~ V_4 -> V_18 ;
V_26 = F_16 ( & V_29 , V_33 , V_25 ) ;
if ( V_26 == V_33 ) {
V_16 ++ ;
V_28 = V_15 ;
V_15 = ( V_15 | ( ( 1 << ( V_20 * V_16 ) ) - 1 ) ) + 1 ;
if ( V_15 >= 1 << ( V_3 -> V_32 * V_20 ) ) {
* V_24 = V_15 ;
return V_34 ;
}
V_4 = V_14 [ V_16 ] ;
F_17 ( ! V_4 ) ;
V_27 = V_20 * ( V_16 + 1 ) ;
if ( V_28 >> V_27 == V_15 >> V_27 )
continue;
else
goto V_30;
}
if ( V_26 != V_25 ) {
V_27 = V_20 * V_16 ;
V_15 = ( ( V_15 >> V_27 ) ^ V_25 ^ V_26 ) << V_27 ;
}
if ( ( V_15 >= V_35 ) || ( V_15 < 0 ) )
return V_36 ;
if ( V_16 == 0 )
break;
if ( ! V_4 -> V_8 [ V_26 ] ) {
V_23 = F_1 ( V_3 ) ;
if ( ! V_23 )
return - 1 ;
V_23 -> V_12 = V_16 - 1 ;
F_18 ( V_4 -> V_8 [ V_26 ] , V_23 ) ;
V_4 -> V_37 ++ ;
}
V_14 [ V_16 -- ] = V_4 ;
V_4 = V_4 -> V_8 [ V_26 ] ;
}
V_14 [ V_16 ] = V_4 ;
return V_15 ;
}
static int F_19 ( struct V_2 * V_3 , int V_24 ,
struct V_1 * * V_14 )
{
struct V_1 * V_4 , * V_23 ;
int V_32 , V_38 , V_15 ;
unsigned long V_5 ;
V_15 = V_24 ;
V_39:
V_4 = V_3 -> V_31 ;
V_32 = V_3 -> V_32 ;
if ( F_20 ( ! V_4 ) ) {
if ( ! ( V_4 = F_1 ( V_3 ) ) )
return - 1 ;
V_4 -> V_12 = 0 ;
V_32 = 1 ;
}
while ( ( V_32 < ( V_40 - 1 ) ) && ( V_15 >= ( 1 << ( V_32 * V_20 ) ) ) ) {
V_32 ++ ;
if ( ! V_4 -> V_37 ) {
V_4 -> V_12 ++ ;
continue;
}
if ( ! ( V_23 = F_1 ( V_3 ) ) ) {
F_2 ( & V_3 -> V_6 , V_5 ) ;
for ( V_23 = V_4 ; V_4 && V_4 != V_3 -> V_31 ; V_23 = V_4 ) {
V_4 = V_4 -> V_8 [ 0 ] ;
V_23 -> V_8 [ 0 ] = NULL ;
V_23 -> V_18 = V_23 -> V_37 = 0 ;
F_9 ( V_3 , V_23 ) ;
}
F_3 ( & V_3 -> V_6 , V_5 ) ;
return - 1 ;
}
V_23 -> V_8 [ 0 ] = V_4 ;
V_23 -> V_37 = 1 ;
V_23 -> V_12 = V_32 - 1 ;
if ( V_4 -> V_18 == V_19 )
F_12 ( 0 , & V_23 -> V_18 ) ;
V_4 = V_23 ;
}
F_18 ( V_3 -> V_31 , V_4 ) ;
V_3 -> V_32 = V_32 ;
V_38 = F_15 ( V_3 , & V_15 , V_14 ) ;
if ( V_38 == V_34 )
goto V_39;
return ( V_38 ) ;
}
static int F_21 ( struct V_2 * V_3 , void * V_41 , int V_24 )
{
struct V_1 * V_14 [ V_40 ] ;
int V_15 ;
V_15 = F_19 ( V_3 , V_24 , V_14 ) ;
if ( V_15 >= 0 ) {
F_18 ( V_14 [ 0 ] -> V_8 [ V_15 & V_17 ] ,
(struct V_1 * ) V_41 ) ;
V_14 [ 0 ] -> V_37 ++ ;
F_11 ( V_14 , V_15 ) ;
}
return V_15 ;
}
int F_22 ( struct V_2 * V_3 , void * V_41 , int V_24 , int * V_15 )
{
int V_42 ;
V_42 = F_21 ( V_3 , V_41 , V_24 ) ;
if ( V_42 < 0 )
return F_23 ( V_42 ) ;
* V_15 = V_42 ;
return 0 ;
}
int F_24 ( struct V_2 * V_3 , void * V_41 , int * V_15 )
{
int V_42 ;
V_42 = F_21 ( V_3 , V_41 , 0 ) ;
if ( V_42 < 0 )
return F_23 ( V_42 ) ;
* V_15 = V_42 ;
return 0 ;
}
static void F_25 ( int V_15 )
{
F_26 ( V_43
L_1 , V_15 ) ;
F_27 () ;
}
static void F_28 ( struct V_2 * V_3 , int V_44 , int V_15 )
{
struct V_1 * V_4 = V_3 -> V_31 ;
struct V_1 * * V_14 [ V_40 ] ;
struct V_1 * * * V_45 = & V_14 [ 0 ] ;
struct V_1 * V_46 ;
int V_25 ;
* V_45 = NULL ;
* ++ V_45 = & V_3 -> V_31 ;
while ( ( V_44 > 0 ) && V_4 ) {
V_25 = ( V_15 >> V_44 ) & V_17 ;
F_29 ( V_25 , & V_4 -> V_18 ) ;
* ++ V_45 = & V_4 -> V_8 [ V_25 ] ;
V_4 = V_4 -> V_8 [ V_25 ] ;
V_44 -= V_20 ;
}
V_25 = V_15 & V_17 ;
if ( F_30 ( V_4 != NULL && F_31 ( V_25 , & V_4 -> V_18 ) ) ) {
F_29 ( V_25 , & V_4 -> V_18 ) ;
F_18 ( V_4 -> V_8 [ V_25 ] , NULL ) ;
V_46 = NULL ;
while( * V_45 && ! -- ( ( * * V_45 ) -> V_37 ) ) {
if ( V_46 )
F_7 ( V_46 ) ;
V_46 = * * V_45 ;
* * V_45 -- = NULL ;
}
if ( ! * V_45 )
V_3 -> V_32 = 0 ;
if ( V_46 )
F_7 ( V_46 ) ;
} else
F_25 ( V_15 ) ;
}
void F_32 ( struct V_2 * V_3 , int V_15 )
{
struct V_1 * V_4 ;
struct V_1 * V_46 ;
V_15 &= V_47 ;
F_28 ( V_3 , ( V_3 -> V_32 - 1 ) * V_20 , V_15 ) ;
if ( V_3 -> V_31 && V_3 -> V_31 -> V_37 == 1 && ( V_3 -> V_32 > 1 ) &&
V_3 -> V_31 -> V_8 [ 0 ] ) {
V_46 = V_3 -> V_31 ;
V_4 = V_3 -> V_31 -> V_8 [ 0 ] ;
F_18 ( V_3 -> V_31 , V_4 ) ;
-- V_3 -> V_32 ;
V_46 -> V_18 = V_46 -> V_37 = 0 ;
F_7 ( V_46 ) ;
}
while ( V_3 -> V_9 >= V_22 ) {
V_4 = F_1 ( V_3 ) ;
F_6 ( V_13 , V_4 ) ;
}
return;
}
void F_33 ( struct V_2 * V_3 )
{
int V_25 , V_15 , V_48 ;
int V_49 ;
struct V_1 * V_4 ;
struct V_1 * V_14 [ V_40 ] ;
struct V_1 * * V_45 = & V_14 [ 0 ] ;
V_25 = V_3 -> V_32 * V_20 ;
V_4 = V_3 -> V_31 ;
F_18 ( V_3 -> V_31 , NULL ) ;
V_48 = 1 << V_25 ;
V_15 = 0 ;
while ( V_15 < V_48 ) {
while ( V_25 > V_20 && V_4 ) {
V_25 -= V_20 ;
* V_45 ++ = V_4 ;
V_4 = V_4 -> V_8 [ ( V_15 >> V_25 ) & V_17 ] ;
}
V_49 = V_15 ;
V_15 += 1 << V_25 ;
while ( V_25 < F_34 ( V_15 ^ V_49 ) ) {
if ( V_4 )
F_7 ( V_4 ) ;
V_25 += V_20 ;
V_4 = * -- V_45 ;
}
}
V_3 -> V_32 = 0 ;
}
void F_35 ( struct V_2 * V_3 )
{
while ( V_3 -> V_9 ) {
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_6 ( V_13 , V_4 ) ;
}
}
void * F_36 ( struct V_2 * V_3 , int V_15 )
{
int V_25 ;
struct V_1 * V_4 ;
V_4 = F_37 ( V_3 -> V_31 ) ;
if ( ! V_4 )
return NULL ;
V_25 = ( V_4 -> V_12 + 1 ) * V_20 ;
V_15 &= V_47 ;
if ( V_15 >= ( 1 << V_25 ) )
return NULL ;
F_17 ( V_25 == 0 ) ;
while ( V_25 > 0 && V_4 ) {
V_25 -= V_20 ;
F_17 ( V_25 != V_4 -> V_12 * V_20 ) ;
V_4 = F_37 ( V_4 -> V_8 [ ( V_15 >> V_25 ) & V_17 ] ) ;
}
return ( ( void * ) V_4 ) ;
}
int F_38 ( struct V_2 * V_3 ,
int (* F_39)( int V_15 , void * V_4 , void * V_50 ) , void * V_50 )
{
int V_25 , V_15 , V_48 , error = 0 ;
struct V_1 * V_4 ;
struct V_1 * V_14 [ V_40 ] ;
struct V_1 * * V_45 = & V_14 [ 0 ] ;
V_25 = V_3 -> V_32 * V_20 ;
V_4 = F_37 ( V_3 -> V_31 ) ;
V_48 = 1 << V_25 ;
V_15 = 0 ;
while ( V_15 < V_48 ) {
while ( V_25 > 0 && V_4 ) {
V_25 -= V_20 ;
* V_45 ++ = V_4 ;
V_4 = F_37 ( V_4 -> V_8 [ ( V_15 >> V_25 ) & V_17 ] ) ;
}
if ( V_4 ) {
error = F_39 ( V_15 , ( void * ) V_4 , V_50 ) ;
if ( error )
break;
}
V_15 += 1 << V_25 ;
while ( V_25 < F_34 ( V_15 ) ) {
V_25 += V_20 ;
V_4 = * -- V_45 ;
}
}
return error ;
}
void * F_40 ( struct V_2 * V_3 , int * V_51 )
{
struct V_1 * V_4 , * V_14 [ V_40 ] ;
struct V_1 * * V_45 = & V_14 [ 0 ] ;
int V_15 = * V_51 ;
int V_25 , V_48 ;
V_4 = F_37 ( V_3 -> V_31 ) ;
if ( ! V_4 )
return NULL ;
V_25 = ( V_4 -> V_12 + 1 ) * V_20 ;
V_48 = 1 << V_25 ;
while ( V_15 < V_48 ) {
while ( V_25 > 0 && V_4 ) {
V_25 -= V_20 ;
* V_45 ++ = V_4 ;
V_4 = F_37 ( V_4 -> V_8 [ ( V_15 >> V_25 ) & V_17 ] ) ;
}
if ( V_4 ) {
* V_51 = V_15 ;
return V_4 ;
}
V_15 += 1 << V_25 ;
while ( V_25 < F_34 ( V_15 ) ) {
V_25 += V_20 ;
V_4 = * -- V_45 ;
}
}
return NULL ;
}
void * F_41 ( struct V_2 * V_3 , void * V_41 , int V_15 )
{
int V_25 ;
struct V_1 * V_4 , * V_52 ;
V_4 = V_3 -> V_31 ;
if ( ! V_4 )
return F_42 ( - V_53 ) ;
V_25 = ( V_4 -> V_12 + 1 ) * V_20 ;
V_15 &= V_47 ;
if ( V_15 >= ( 1 << V_25 ) )
return F_42 ( - V_53 ) ;
V_25 -= V_20 ;
while ( ( V_25 > 0 ) && V_4 ) {
V_4 = V_4 -> V_8 [ ( V_15 >> V_25 ) & V_17 ] ;
V_25 -= V_20 ;
}
V_25 = V_15 & V_17 ;
if ( F_20 ( V_4 == NULL || ! F_31 ( V_25 , & V_4 -> V_18 ) ) )
return F_42 ( - V_54 ) ;
V_52 = V_4 -> V_8 [ V_25 ] ;
F_18 ( V_4 -> V_8 [ V_25 ] , V_41 ) ;
return V_52 ;
}
void T_2 F_43 ( void )
{
V_13 = F_44 ( L_2 ,
sizeof( struct V_1 ) , 0 , V_55 , NULL ) ;
}
void F_45 ( struct V_2 * V_3 )
{
memset ( V_3 , 0 , sizeof( struct V_2 ) ) ;
F_46 ( & V_3 -> V_6 ) ;
}
static void F_47 ( struct V_56 * V_56 , struct V_57 * V_18 )
{
unsigned long V_5 ;
if ( ! V_56 -> F_47 ) {
F_2 ( & V_56 -> V_2 . V_6 , V_5 ) ;
if ( ! V_56 -> F_47 ) {
V_56 -> F_47 = V_18 ;
V_18 = NULL ;
}
F_3 ( & V_56 -> V_2 . V_6 , V_5 ) ;
}
F_48 ( V_18 ) ;
}
int F_49 ( struct V_56 * V_56 , T_1 V_21 )
{
if ( ! F_13 ( & V_56 -> V_2 , V_21 ) )
return 0 ;
if ( ! V_56 -> F_47 ) {
struct V_57 * V_18 ;
V_18 = F_50 ( sizeof( struct V_57 ) , V_21 ) ;
if ( ! V_18 )
return 0 ;
F_47 ( V_56 , V_18 ) ;
}
return 1 ;
}
int F_51 ( struct V_56 * V_56 , int V_24 , int * V_58 )
{
struct V_1 * V_14 [ V_40 ] ;
struct V_57 * V_18 ;
unsigned long V_5 ;
int V_59 = V_24 / V_60 ;
int V_61 = V_24 % V_60 ;
int V_62 , V_15 ;
V_30:
V_62 = F_19 ( & V_56 -> V_2 , V_59 , V_14 ) ;
if ( V_62 < 0 )
return F_23 ( V_62 ) ;
if ( V_62 * V_60 >= V_35 )
return - V_63 ;
if ( V_62 != V_59 )
V_61 = 0 ;
V_59 = V_62 ;
V_18 = ( void * ) V_14 [ 0 ] -> V_8 [ V_59 & V_17 ] ;
if ( ! V_18 ) {
F_2 ( & V_56 -> V_2 . V_6 , V_5 ) ;
V_18 = V_56 -> F_47 ;
V_56 -> F_47 = NULL ;
F_3 ( & V_56 -> V_2 . V_6 , V_5 ) ;
if ( ! V_18 )
return - V_64 ;
memset ( V_18 , 0 , sizeof( struct V_57 ) ) ;
F_18 ( V_14 [ 0 ] -> V_8 [ V_59 & V_17 ] ,
( void * ) V_18 ) ;
V_14 [ 0 ] -> V_37 ++ ;
}
V_62 = F_52 ( V_18 -> V_18 , V_60 , V_61 ) ;
if ( V_62 == V_60 ) {
V_59 ++ ;
V_61 = 0 ;
goto V_30;
}
V_15 = V_59 * V_60 + V_62 ;
if ( V_15 >= V_35 )
return - V_63 ;
F_12 ( V_62 , V_18 -> V_18 ) ;
if ( ++ V_18 -> V_65 == V_60 )
F_11 ( V_14 , V_59 ) ;
* V_58 = V_15 ;
if ( V_56 -> V_2 . V_9 || V_56 -> F_47 ) {
struct V_1 * V_4 = F_1 ( & V_56 -> V_2 ) ;
if ( V_4 )
F_6 ( V_13 , V_4 ) ;
}
return 0 ;
}
int F_53 ( struct V_56 * V_56 , int * V_58 )
{
return F_51 ( V_56 , 0 , V_58 ) ;
}
void F_54 ( struct V_56 * V_56 , int V_15 )
{
struct V_1 * V_4 = V_56 -> V_2 . V_31 ;
int V_44 = ( V_56 -> V_2 . V_32 - 1 ) * V_20 ;
int V_59 = V_15 / V_60 ;
int V_61 = V_15 % V_60 ;
int V_25 ;
struct V_57 * V_18 ;
while ( ( V_44 > 0 ) && V_4 ) {
V_25 = ( V_59 >> V_44 ) & V_17 ;
F_29 ( V_25 , & V_4 -> V_18 ) ;
V_4 = V_4 -> V_8 [ V_25 ] ;
V_44 -= V_20 ;
}
if ( V_4 == NULL )
goto V_66;
V_25 = V_59 & V_17 ;
F_29 ( V_25 , & V_4 -> V_18 ) ;
V_18 = ( void * ) V_4 -> V_8 [ V_25 ] ;
if ( ! F_31 ( V_61 , V_18 -> V_18 ) )
goto V_66;
F_29 ( V_61 , V_18 -> V_18 ) ;
if ( -- V_18 -> V_65 == 0 ) {
F_12 ( V_25 , & V_4 -> V_18 ) ;
F_32 ( & V_56 -> V_2 , V_59 ) ;
F_47 ( V_56 , V_18 ) ;
}
return;
V_66:
F_26 ( V_43
L_3 , V_15 ) ;
}
void F_55 ( struct V_56 * V_56 )
{
F_35 ( & V_56 -> V_2 ) ;
F_48 ( V_56 -> F_47 ) ;
}
int F_56 ( struct V_56 * V_56 , unsigned int V_67 , unsigned int V_68 ,
T_1 V_21 )
{
int V_69 , V_15 ;
unsigned int V_48 ;
unsigned long V_5 ;
F_17 ( ( int ) V_67 < 0 ) ;
F_17 ( ( int ) V_68 < 0 ) ;
if ( V_68 == 0 )
V_48 = 0x80000000 ;
else {
F_17 ( V_68 < V_67 ) ;
V_48 = V_68 - 1 ;
}
V_70:
if ( ! F_49 ( V_56 , V_21 ) )
return - V_71 ;
F_2 ( & V_72 , V_5 ) ;
V_69 = F_51 ( V_56 , V_67 , & V_15 ) ;
if ( ! V_69 ) {
if ( V_15 > V_48 ) {
F_54 ( V_56 , V_15 ) ;
V_69 = - V_63 ;
} else {
V_69 = V_15 ;
}
}
F_3 ( & V_72 , V_5 ) ;
if ( F_20 ( V_69 == - V_64 ) )
goto V_70;
return V_69 ;
}
void F_57 ( struct V_56 * V_56 , unsigned int V_15 )
{
unsigned long V_5 ;
F_17 ( ( int ) V_15 < 0 ) ;
F_2 ( & V_72 , V_5 ) ;
F_54 ( V_56 , V_15 ) ;
F_3 ( & V_72 , V_5 ) ;
}
void F_58 ( struct V_56 * V_56 )
{
memset ( V_56 , 0 , sizeof( struct V_56 ) ) ;
F_45 ( & V_56 -> V_2 ) ;
}
