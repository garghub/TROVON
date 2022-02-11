static inline const char * F_1 ( struct V_1 * type )
{
if ( type == & V_2 . V_3 )
return L_1 ;
else if ( type == & V_2 . V_4 )
return L_2 ;
else
return L_3 ;
}
static T_1 T_2 F_2 ( T_1 V_5 , T_1 V_6 )
{
return V_5 & ~ ( V_6 - 1 ) ;
}
static T_1 T_2 F_3 ( T_1 V_5 , T_1 V_6 )
{
return ( V_5 + ( V_6 - 1 ) ) & ~ ( V_6 - 1 ) ;
}
static unsigned long T_2 F_4 ( T_1 V_7 , T_1 V_8 ,
T_1 V_9 , T_1 V_10 )
{
return ( ( V_7 < ( V_9 + V_10 ) ) && ( V_9 < ( V_7 + V_8 ) ) ) ;
}
long T_2 F_5 ( struct V_1 * type , T_1 V_11 , T_1 V_6 )
{
unsigned long V_12 ;
for ( V_12 = 0 ; V_12 < type -> V_13 ; V_12 ++ ) {
T_1 V_14 = type -> V_15 [ V_12 ] . V_11 ;
T_1 V_16 = type -> V_15 [ V_12 ] . V_6 ;
if ( F_4 ( V_11 , V_6 , V_14 , V_16 ) )
break;
}
return ( V_12 < type -> V_13 ) ? V_12 : - 1 ;
}
static T_1 T_2 F_6 ( T_1 V_17 , T_1 V_18 ,
T_1 V_6 , T_1 V_19 )
{
T_1 V_11 , V_20 ;
long V_21 ;
if ( V_18 < V_6 )
return V_22 ;
V_11 = F_2 ( ( V_18 - V_6 ) , V_19 ) ;
if ( V_17 == 0 )
V_17 = V_23 ;
while ( V_17 <= V_11 ) {
V_21 = F_5 ( & V_2 . V_4 , V_11 , V_6 ) ;
if ( V_21 < 0 )
return V_11 ;
V_20 = V_2 . V_4 . V_15 [ V_21 ] . V_11 ;
if ( V_20 < V_6 )
break;
V_11 = F_2 ( V_20 - V_6 , V_19 ) ;
}
return V_22 ;
}
static T_1 T_2 F_7 ( T_1 V_6 ,
T_1 V_19 , T_1 V_17 , T_1 V_18 )
{
long V_12 ;
F_8 ( 0 == V_6 ) ;
if ( V_18 == V_24 )
V_18 = V_2 . V_25 ;
for ( V_12 = V_2 . V_3 . V_13 - 1 ; V_12 >= 0 ; V_12 -- ) {
T_1 V_26 = V_2 . V_3 . V_15 [ V_12 ] . V_11 ;
T_1 V_27 = V_2 . V_3 . V_15 [ V_12 ] . V_6 ;
T_1 V_28 , V_29 , V_30 ;
if ( V_27 < V_6 )
continue;
if ( ( V_26 + V_27 ) <= V_17 )
break;
V_28 = F_9 ( V_26 , V_17 ) ;
V_29 = F_10 ( V_26 + V_27 , V_18 ) ;
if ( V_28 >= V_29 )
continue;
V_30 = F_6 ( V_28 , V_29 , V_6 , V_19 ) ;
if ( V_30 != V_22 )
return V_30 ;
}
return V_22 ;
}
T_3 T_2 F_11 ( T_3 V_17 , T_3 V_18 , T_3 V_6 , T_3 V_19 )
{
return F_7 ( V_6 , V_19 , V_17 , V_18 ) ;
}
int T_2 F_12 ( void )
{
if ( V_2 . V_4 . V_15 == V_31 )
return 0 ;
return F_13 ( F_14 ( V_2 . V_4 . V_15 ) ,
sizeof( struct V_32 ) * V_2 . V_4 . F_9 ) ;
}
int T_2 F_15 ( void )
{
if ( V_2 . V_4 . V_15 == V_31 )
return 0 ;
return F_16 ( F_14 ( V_2 . V_4 . V_15 ) ,
sizeof( struct V_32 ) * V_2 . V_4 . F_9 ) ;
}
static void T_2 F_17 ( struct V_1 * type , unsigned long V_33 )
{
unsigned long V_12 ;
for ( V_12 = V_33 ; V_12 < type -> V_13 - 1 ; V_12 ++ ) {
type -> V_15 [ V_12 ] . V_11 = type -> V_15 [ V_12 + 1 ] . V_11 ;
type -> V_15 [ V_12 ] . V_6 = type -> V_15 [ V_12 + 1 ] . V_6 ;
}
type -> V_13 -- ;
if ( type -> V_13 == 0 ) {
type -> V_13 = 1 ;
type -> V_15 [ 0 ] . V_11 = 0 ;
type -> V_15 [ 0 ] . V_6 = 0 ;
}
}
static int T_2 F_18 ( struct V_1 * type )
{
struct V_32 * V_34 , * V_35 ;
T_1 V_36 , V_37 , V_5 ;
int V_38 = F_19 () ;
if ( ! V_39 )
return - 1 ;
V_36 = type -> F_9 * sizeof( struct V_32 ) ;
V_37 = V_36 << 1 ;
if ( V_38 ) {
V_34 = F_20 ( V_37 , V_40 ) ;
V_5 = V_34 == NULL ? V_22 : F_14 ( V_34 ) ;
} else
V_5 = F_7 ( V_37 , sizeof( T_1 ) , 0 , V_24 ) ;
if ( V_5 == V_22 ) {
F_21 ( L_4 ,
F_1 ( type ) , type -> F_9 , type -> F_9 * 2 ) ;
return - 1 ;
}
V_34 = F_22 ( V_5 ) ;
F_23 ( L_5 ,
F_1 ( type ) , type -> F_9 * 2 , ( T_3 ) V_5 , ( T_3 ) V_5 + V_37 - 1 ) ;
memcpy ( V_34 , type -> V_15 , V_36 ) ;
memset ( V_34 + type -> F_9 , 0 , V_36 ) ;
V_35 = type -> V_15 ;
type -> V_15 = V_34 ;
type -> F_9 <<= 1 ;
if ( V_38 )
return 0 ;
F_8 ( F_24 ( & V_2 . V_4 , V_5 , V_37 ) ) ;
if ( V_35 != V_41 &&
V_35 != V_31 )
F_13 ( F_14 ( V_35 ) , V_36 ) ;
return 0 ;
}
extern int T_2 __weak F_25 ( T_1 V_42 , T_1 V_8 ,
T_1 V_43 , T_1 V_10 )
{
return 1 ;
}
static long T_2 F_24 ( struct V_1 * type ,
T_1 V_11 , T_1 V_6 )
{
T_1 V_18 = V_11 + V_6 ;
int V_12 , V_44 = - 1 ;
for ( V_12 = 0 ; V_12 < type -> V_13 ; V_12 ++ ) {
struct V_32 * V_45 = & type -> V_15 [ V_12 ] ;
T_1 V_46 = V_45 -> V_11 + V_45 -> V_6 ;
if ( V_45 -> V_11 > V_18 || V_45 -> V_6 == 0 )
break;
if ( V_45 -> V_11 <= V_11 && V_46 >= V_18 )
return 0 ;
if ( V_11 < V_45 -> V_11 && V_18 >= V_45 -> V_11 ) {
if ( ! F_25 ( V_11 , V_6 ,
V_45 -> V_11 ,
V_45 -> V_6 ) ) {
F_26 ( V_18 != V_45 -> V_11 ) ;
goto V_47;
}
V_45 -> V_11 = V_11 ;
V_45 -> V_6 = V_46 - V_11 ;
if ( V_46 >= V_18 )
return 0 ;
V_11 = V_46 ;
V_6 = V_18 - V_11 ;
}
if ( V_11 <= V_46 && V_18 >= V_46 ) {
if ( ! F_25 ( V_45 -> V_11 ,
V_45 -> V_6 ,
V_11 , V_6 ) ) {
F_26 ( V_46 != V_11 ) ;
goto V_47;
}
V_6 += ( V_11 - V_45 -> V_11 ) ;
V_11 = V_45 -> V_11 ;
F_17 ( type , V_12 -- ) ;
}
}
if ( ( type -> V_13 == 1 ) && ( type -> V_15 [ 0 ] . V_6 == 0 ) ) {
type -> V_15 [ 0 ] . V_11 = V_11 ;
type -> V_15 [ 0 ] . V_6 = V_6 ;
return 0 ;
}
V_47:
if ( F_26 ( type -> V_13 >= type -> F_9 ) )
return - 1 ;
for ( V_12 = type -> V_13 - 1 ; V_12 >= 0 ; V_12 -- ) {
if ( V_11 < type -> V_15 [ V_12 ] . V_11 ) {
type -> V_15 [ V_12 + 1 ] . V_11 = type -> V_15 [ V_12 ] . V_11 ;
type -> V_15 [ V_12 + 1 ] . V_6 = type -> V_15 [ V_12 ] . V_6 ;
} else {
type -> V_15 [ V_12 + 1 ] . V_11 = V_11 ;
type -> V_15 [ V_12 + 1 ] . V_6 = V_6 ;
V_44 = V_12 + 1 ;
break;
}
}
if ( V_11 < type -> V_15 [ 0 ] . V_11 ) {
type -> V_15 [ 0 ] . V_11 = V_11 ;
type -> V_15 [ 0 ] . V_6 = V_6 ;
V_44 = 0 ;
}
type -> V_13 ++ ;
if ( type -> V_13 == type -> F_9 && F_18 ( type ) ) {
F_8 ( V_44 < 0 ) ;
F_17 ( type , V_44 ) ;
return - 1 ;
}
return 0 ;
}
long T_2 F_27 ( T_1 V_11 , T_1 V_6 )
{
return F_24 ( & V_2 . V_3 , V_11 , V_6 ) ;
}
static long T_2 F_28 ( struct V_1 * type ,
T_1 V_11 , T_1 V_6 )
{
T_1 V_18 = V_11 + V_6 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < type -> V_13 ; V_12 ++ ) {
struct V_32 * V_45 = & type -> V_15 [ V_12 ] ;
T_1 V_46 = V_45 -> V_11 + V_45 -> V_6 ;
if ( V_45 -> V_11 > V_18 || V_45 -> V_6 == 0 )
break;
if ( V_11 <= V_45 -> V_11 && V_18 >= V_46 ) {
F_17 ( type , V_12 -- ) ;
continue;
}
if ( V_11 > V_45 -> V_11 && V_18 < V_46 ) {
V_45 -> V_6 = V_11 - V_45 -> V_11 ;
if ( ! F_24 ( type , V_18 , V_46 - V_18 ) )
return 0 ;
V_45 -> V_6 = V_46 - V_45 -> V_11 ;
F_26 ( 1 ) ;
return - 1 ;
}
if ( V_45 -> V_11 < V_18 && V_46 > V_18 ) {
V_45 -> V_6 -= V_18 - V_45 -> V_11 ;
V_45 -> V_11 = V_18 ;
break;
}
if ( V_11 < V_46 )
V_45 -> V_6 -= V_46 - V_11 ;
}
return 0 ;
}
long T_2 F_29 ( T_1 V_11 , T_1 V_6 )
{
return F_28 ( & V_2 . V_3 , V_11 , V_6 ) ;
}
long T_2 F_13 ( T_1 V_11 , T_1 V_6 )
{
return F_28 ( & V_2 . V_4 , V_11 , V_6 ) ;
}
long T_2 F_16 ( T_1 V_11 , T_1 V_6 )
{
struct V_1 * V_48 = & V_2 . V_4 ;
F_8 ( 0 == V_6 ) ;
return F_24 ( V_48 , V_11 , V_6 ) ;
}
T_1 T_4 F_30 ( T_1 V_6 , T_1 V_19 , T_1 V_49 )
{
T_1 V_30 ;
V_6 = F_3 ( V_6 , V_19 ) ;
V_30 = F_7 ( V_6 , V_19 , 0 , V_49 ) ;
if ( V_30 != V_22 &&
! F_24 ( & V_2 . V_4 , V_30 , V_6 ) )
return V_30 ;
return 0 ;
}
T_1 T_4 F_31 ( T_1 V_6 , T_1 V_19 , T_1 V_49 )
{
T_1 V_50 ;
V_50 = F_30 ( V_6 , V_19 , V_49 ) ;
if ( V_50 == 0 )
F_32 ( L_6 ,
( unsigned long long ) V_6 , ( unsigned long long ) V_49 ) ;
return V_50 ;
}
T_1 T_4 F_33 ( T_1 V_6 , T_1 V_19 )
{
return F_31 ( V_6 , V_19 , V_24 ) ;
}
T_1 __weak T_4 F_34 ( T_1 V_17 , T_1 V_18 , int * V_51 )
{
#ifdef F_35
unsigned long V_52 , V_53 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_54 ; V_12 ++ ) {
F_36 ( V_12 , & V_52 , & V_53 ) ;
if ( V_17 < F_37 ( V_52 ) || V_17 >= F_37 ( V_53 ) )
continue;
* V_51 = V_12 ;
return F_10 ( V_18 , F_37 ( V_53 ) ) ;
}
#endif
* V_51 = 0 ;
return V_18 ;
}
static T_1 T_4 F_38 ( struct V_32 * V_55 ,
T_1 V_6 ,
T_1 V_19 , int V_51 )
{
T_1 V_17 , V_18 ;
V_17 = V_55 -> V_11 ;
V_18 = V_17 + V_55 -> V_6 ;
V_17 = F_3 ( V_17 , V_19 ) ;
while ( V_17 < V_18 ) {
T_1 V_56 ;
int V_57 ;
V_56 = F_34 ( V_17 , V_18 , & V_57 ) ;
if ( V_57 == V_51 ) {
T_1 V_58 = F_6 ( V_17 , V_56 , V_6 , V_19 ) ;
if ( V_58 != V_22 &&
! F_24 ( & V_2 . V_4 , V_58 , V_6 ) )
return V_58 ;
}
V_17 = V_56 ;
}
return V_22 ;
}
T_1 T_4 F_39 ( T_1 V_6 , T_1 V_19 , int V_51 )
{
struct V_1 * V_59 = & V_2 . V_3 ;
int V_12 ;
F_8 ( 0 == V_6 ) ;
V_6 = F_3 ( V_6 , V_19 ) ;
for ( V_12 = 0 ; V_12 < V_59 -> V_13 ; V_12 ++ ) {
T_1 V_58 = F_38 ( & V_59 -> V_15 [ V_12 ] ,
V_6 , V_19 , V_51 ) ;
if ( V_58 != V_22 )
return V_58 ;
}
return 0 ;
}
T_1 T_4 F_40 ( T_1 V_6 , T_1 V_19 , int V_51 )
{
T_1 V_60 = F_39 ( V_6 , V_19 , V_51 ) ;
if ( V_60 )
return V_60 ;
return F_31 ( V_6 , V_19 , V_61 ) ;
}
T_1 T_4 F_41 ( void )
{
return V_2 . V_62 ;
}
T_1 T_2 F_42 ( void )
{
int V_63 = V_2 . V_3 . V_13 - 1 ;
return ( V_2 . V_3 . V_15 [ V_63 ] . V_11 + V_2 . V_3 . V_15 [ V_63 ] . V_6 ) ;
}
void T_4 F_43 ( T_1 V_64 )
{
unsigned long V_12 ;
T_1 V_65 ;
struct V_32 * V_66 ;
if ( ! V_64 )
return;
V_65 = V_64 ;
for ( V_12 = 0 ; V_12 < V_2 . V_3 . V_13 ; V_12 ++ ) {
if ( V_65 > V_2 . V_3 . V_15 [ V_12 ] . V_6 ) {
V_65 -= V_2 . V_3 . V_15 [ V_12 ] . V_6 ;
continue;
}
V_2 . V_3 . V_15 [ V_12 ] . V_6 = V_65 ;
V_2 . V_3 . V_13 = V_12 + 1 ;
break;
}
V_64 = F_42 () ;
for ( V_12 = 0 ; V_12 < V_2 . V_4 . V_13 ; V_12 ++ ) {
V_66 = & V_2 . V_4 . V_15 [ V_12 ] ;
if ( V_66 -> V_11 > V_64 )
V_66 -> V_6 = 0 ;
else if ( ( V_66 -> V_11 + V_66 -> V_6 ) > V_64 )
V_66 -> V_6 = V_64 - V_66 -> V_11 ;
if ( V_66 -> V_6 == 0 ) {
F_17 ( & V_2 . V_4 , V_12 ) ;
V_12 -- ;
}
}
}
static int T_2 F_44 ( struct V_1 * type , T_1 V_5 )
{
unsigned int V_67 = 0 , V_68 = type -> V_13 ;
do {
unsigned int V_69 = ( V_68 + V_67 ) / 2 ;
if ( V_5 < type -> V_15 [ V_69 ] . V_11 )
V_68 = V_69 ;
else if ( V_5 >= ( type -> V_15 [ V_69 ] . V_11 +
type -> V_15 [ V_69 ] . V_6 ) )
V_67 = V_69 + 1 ;
else
return V_69 ;
} while ( V_67 < V_68 );
return - 1 ;
}
int T_4 F_45 ( T_1 V_5 )
{
return F_44 ( & V_2 . V_4 , V_5 ) != - 1 ;
}
int T_2 F_46 ( T_1 V_5 )
{
return F_44 ( & V_2 . V_3 , V_5 ) != - 1 ;
}
int T_2 F_47 ( T_1 V_11 , T_1 V_6 )
{
int V_63 = F_44 ( & V_2 . V_3 , V_11 ) ;
if ( V_63 == - 1 )
return 0 ;
return V_2 . V_3 . V_15 [ V_63 ] . V_11 <= V_11 &&
( V_2 . V_3 . V_15 [ V_63 ] . V_11 +
V_2 . V_3 . V_15 [ V_63 ] . V_6 ) >= ( V_11 + V_6 ) ;
}
int T_2 F_48 ( T_1 V_11 , T_1 V_6 )
{
return F_5 ( & V_2 . V_4 , V_11 , V_6 ) >= 0 ;
}
void T_2 F_49 ( T_1 V_65 )
{
V_2 . V_25 = V_65 ;
}
static void T_2 F_50 ( struct V_1 * V_70 , char * V_71 )
{
unsigned long long V_11 , V_6 ;
int V_12 ;
F_51 ( L_7 , V_71 , V_70 -> V_13 ) ;
for ( V_12 = 0 ; V_12 < V_70 -> V_13 ; V_12 ++ ) {
V_11 = V_70 -> V_15 [ V_12 ] . V_11 ;
V_6 = V_70 -> V_15 [ V_12 ] . V_6 ;
F_51 ( L_8 ,
V_71 , V_12 , V_11 , V_11 + V_6 - 1 , V_6 ) ;
}
}
void T_2 F_52 ( void )
{
if ( ! V_72 )
return;
F_51 ( L_9 ) ;
F_51 ( L_10 , ( unsigned long long ) V_2 . V_62 ) ;
F_50 ( & V_2 . V_3 , L_1 ) ;
F_50 ( & V_2 . V_4 , L_2 ) ;
}
void T_4 F_53 ( void )
{
int V_12 ;
F_26 ( V_41 [ V_73 ] . V_11
!= V_74 ) ;
F_26 ( V_31 [ V_73 ] . V_11
!= V_74 ) ;
V_2 . V_62 = 0 ;
for ( V_12 = 0 ; V_12 < V_2 . V_3 . V_13 ; V_12 ++ )
V_2 . V_62 += V_2 . V_3 . V_15 [ V_12 ] . V_6 ;
V_39 = 1 ;
}
void T_4 F_54 ( void )
{
static int T_5 V_75 = 0 ;
if ( T_5 )
return;
T_5 = 1 ;
V_2 . V_3 . V_15 = V_41 ;
V_2 . V_3 . F_9 = V_73 ;
V_2 . V_4 . V_15 = V_31 ;
V_2 . V_4 . F_9 = V_73 ;
V_2 . V_3 . V_15 [ V_73 ] . V_11 = V_74 ;
V_2 . V_4 . V_15 [ V_73 ] . V_11 = V_74 ;
V_2 . V_3 . V_15 [ 0 ] . V_11 = 0 ;
V_2 . V_3 . V_15 [ 0 ] . V_6 = 0 ;
V_2 . V_3 . V_13 = 1 ;
V_2 . V_4 . V_15 [ 0 ] . V_11 = 0 ;
V_2 . V_4 . V_15 [ 0 ] . V_6 = 0 ;
V_2 . V_4 . V_13 = 1 ;
V_2 . V_25 = V_61 ;
}
static int T_4 F_55 ( char * V_66 )
{
if ( V_66 && strstr ( V_66 , L_11 ) )
V_72 = 1 ;
return 0 ;
}
static int F_56 ( struct V_76 * V_77 , void * V_78 )
{
struct V_1 * type = V_77 -> V_78 ;
struct V_32 * V_79 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < type -> V_13 ; V_12 ++ ) {
V_79 = & type -> V_15 [ V_12 ] ;
F_57 ( V_77 , L_12 , V_12 ) ;
if ( sizeof( T_1 ) == 4 )
F_57 ( V_77 , L_13 ,
( unsigned long ) V_79 -> V_11 ,
( unsigned long ) ( V_79 -> V_11 + V_79 -> V_6 - 1 ) ) ;
else
F_57 ( V_77 , L_14 ,
( unsigned long long ) V_79 -> V_11 ,
( unsigned long long ) ( V_79 -> V_11 + V_79 -> V_6 - 1 ) ) ;
}
return 0 ;
}
static int F_58 ( struct V_80 * V_80 , struct V_81 * V_81 )
{
return F_59 ( V_81 , F_56 , V_80 -> V_82 ) ;
}
static int T_4 F_60 ( void )
{
struct V_83 * V_84 = F_61 ( L_15 , NULL ) ;
if ( ! V_84 )
return - V_85 ;
F_62 ( L_1 , V_86 , V_84 , & V_2 . V_3 , & V_87 ) ;
F_62 ( L_2 , V_86 , V_84 , & V_2 . V_4 , & V_87 ) ;
return 0 ;
}
