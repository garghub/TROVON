static inline const char * F_1 ( struct V_1 * type )
{
if ( type == & V_2 . V_3 )
return L_1 ;
else if ( type == & V_2 . V_4 )
return L_2 ;
else
return L_3 ;
}
static inline T_1 F_2 ( T_1 V_5 , T_1 * V_6 )
{
return * V_6 = F_3 ( * V_6 , ( T_1 ) V_7 - V_5 ) ;
}
static unsigned long T_2 F_4 ( T_1 V_8 , T_1 V_9 ,
T_1 V_10 , T_1 V_11 )
{
return ( ( V_8 < ( V_10 + V_11 ) ) && ( V_10 < ( V_8 + V_9 ) ) ) ;
}
static long T_2 F_5 ( struct V_1 * type ,
T_1 V_5 , T_1 V_6 )
{
unsigned long V_12 ;
for ( V_12 = 0 ; V_12 < type -> V_13 ; V_12 ++ ) {
T_1 V_14 = type -> V_15 [ V_12 ] . V_5 ;
T_1 V_16 = type -> V_15 [ V_12 ] . V_6 ;
if ( F_4 ( V_5 , V_6 , V_14 , V_16 ) )
break;
}
return ( V_12 < type -> V_13 ) ? V_12 : - 1 ;
}
T_1 T_2 F_6 ( T_1 V_17 ,
T_1 V_18 , T_1 V_6 ,
T_1 V_19 , int V_20 )
{
T_1 V_21 , V_22 , V_23 ;
T_3 V_12 ;
if ( V_18 == V_24 )
V_18 = V_2 . V_25 ;
V_17 = F_7 ( T_1 , V_17 , V_26 ) ;
V_18 = F_8 ( V_17 , V_18 ) ;
F_9 (i, nid, &this_start, &this_end, NULL) {
V_21 = F_10 ( V_21 , V_17 , V_18 ) ;
V_22 = F_10 ( V_22 , V_17 , V_18 ) ;
if ( V_22 < V_6 )
continue;
V_23 = F_11 ( V_22 - V_6 , V_19 ) ;
if ( V_23 >= V_21 )
return V_23 ;
}
return 0 ;
}
T_1 T_2 F_12 ( T_1 V_17 ,
T_1 V_18 , T_1 V_6 ,
T_1 V_19 )
{
return F_6 ( V_17 , V_18 , V_6 , V_19 ,
V_27 ) ;
}
int T_2 F_13 ( void )
{
if ( V_2 . V_4 . V_15 == V_28 )
return 0 ;
return F_14 ( F_15 ( V_2 . V_4 . V_15 ) ,
sizeof( struct V_29 ) * V_2 . V_4 . F_8 ) ;
}
int T_2 F_16 ( void )
{
if ( V_2 . V_4 . V_15 == V_28 )
return 0 ;
return F_17 ( F_15 ( V_2 . V_4 . V_15 ) ,
sizeof( struct V_29 ) * V_2 . V_4 . F_8 ) ;
}
static void T_2 F_18 ( struct V_1 * type , unsigned long V_30 )
{
type -> V_31 -= type -> V_15 [ V_30 ] . V_6 ;
memmove ( & type -> V_15 [ V_30 ] , & type -> V_15 [ V_30 + 1 ] ,
( type -> V_13 - ( V_30 + 1 ) ) * sizeof( type -> V_15 [ V_30 ] ) ) ;
type -> V_13 -- ;
if ( type -> V_13 == 0 ) {
F_19 ( type -> V_31 != 0 ) ;
type -> V_13 = 1 ;
type -> V_15 [ 0 ] . V_5 = 0 ;
type -> V_15 [ 0 ] . V_6 = 0 ;
F_20 ( & type -> V_15 [ 0 ] , V_27 ) ;
}
}
static int T_2 F_21 ( struct V_1 * type )
{
struct V_29 * V_32 , * V_33 ;
T_1 V_34 , V_35 , V_36 ;
int V_37 = F_22 () ;
if ( ! V_38 )
return - 1 ;
V_34 = type -> F_8 * sizeof( struct V_29 ) ;
V_35 = V_34 << 1 ;
if ( V_37 ) {
V_32 = F_23 ( V_35 , V_39 ) ;
V_36 = V_32 ? F_15 ( V_32 ) : 0 ;
} else
V_36 = F_12 ( 0 , V_24 , V_35 , sizeof( T_1 ) ) ;
if ( ! V_36 ) {
F_24 ( L_4 ,
F_1 ( type ) , type -> F_8 , type -> F_8 * 2 ) ;
return - 1 ;
}
V_32 = F_25 ( V_36 ) ;
F_26 ( L_5 ,
F_1 ( type ) , type -> F_8 * 2 , ( T_3 ) V_36 , ( T_3 ) V_36 + V_35 - 1 ) ;
memcpy ( V_32 , type -> V_15 , V_34 ) ;
memset ( V_32 + type -> F_8 , 0 , V_34 ) ;
V_33 = type -> V_15 ;
type -> V_15 = V_32 ;
type -> F_8 <<= 1 ;
if ( V_37 )
return 0 ;
F_27 ( F_17 ( V_36 , V_35 ) ) ;
if ( V_33 != V_40 &&
V_33 != V_28 )
F_14 ( F_15 ( V_33 ) , V_34 ) ;
return 0 ;
}
static void T_2 F_28 ( struct V_1 * type )
{
int V_12 = 0 ;
while ( V_12 < type -> V_13 - 1 ) {
struct V_29 * V_41 = & type -> V_15 [ V_12 ] ;
struct V_29 * V_42 = & type -> V_15 [ V_12 + 1 ] ;
if ( V_41 -> V_5 + V_41 -> V_6 != V_42 -> V_5 ||
F_29 ( V_41 ) !=
F_29 ( V_42 ) ) {
F_27 ( V_41 -> V_5 + V_41 -> V_6 > V_42 -> V_5 ) ;
V_12 ++ ;
continue;
}
V_41 -> V_6 += V_42 -> V_6 ;
memmove ( V_42 , V_42 + 1 , ( type -> V_13 - ( V_12 + 1 ) ) * sizeof( * V_42 ) ) ;
type -> V_13 -- ;
}
}
static void T_2 F_30 ( struct V_1 * type ,
int V_43 , T_1 V_5 ,
T_1 V_6 , int V_20 )
{
struct V_29 * V_44 = & type -> V_15 [ V_43 ] ;
F_27 ( type -> V_13 >= type -> F_8 ) ;
memmove ( V_44 + 1 , V_44 , ( type -> V_13 - V_43 ) * sizeof( * V_44 ) ) ;
V_44 -> V_5 = V_5 ;
V_44 -> V_6 = V_6 ;
F_20 ( V_44 , V_20 ) ;
type -> V_13 ++ ;
type -> V_31 += V_6 ;
}
static int T_2 F_31 ( struct V_1 * type ,
T_1 V_5 , T_1 V_6 , int V_20 )
{
bool V_45 = false ;
T_1 V_46 = V_5 ;
T_1 V_18 = V_5 + F_2 ( V_5 , & V_6 ) ;
int V_12 , V_47 ;
if ( type -> V_15 [ 0 ] . V_6 == 0 ) {
F_19 ( type -> V_13 != 1 || type -> V_31 ) ;
type -> V_15 [ 0 ] . V_5 = V_5 ;
type -> V_15 [ 0 ] . V_6 = V_6 ;
F_20 ( & type -> V_15 [ 0 ] , V_20 ) ;
type -> V_31 = V_6 ;
return 0 ;
}
V_48:
V_5 = V_46 ;
V_47 = 0 ;
for ( V_12 = 0 ; V_12 < type -> V_13 ; V_12 ++ ) {
struct V_29 * V_44 = & type -> V_15 [ V_12 ] ;
T_1 V_49 = V_44 -> V_5 ;
T_1 V_50 = V_49 + V_44 -> V_6 ;
if ( V_49 >= V_18 )
break;
if ( V_50 <= V_5 )
continue;
if ( V_49 > V_5 ) {
V_47 ++ ;
if ( V_45 )
F_30 ( type , V_12 ++ , V_5 ,
V_49 - V_5 , V_20 ) ;
}
V_5 = F_3 ( V_50 , V_18 ) ;
}
if ( V_5 < V_18 ) {
V_47 ++ ;
if ( V_45 )
F_30 ( type , V_12 , V_5 , V_18 - V_5 , V_20 ) ;
}
if ( ! V_45 ) {
while ( type -> V_13 + V_47 > type -> F_8 )
if ( F_21 ( type ) < 0 )
return - V_51 ;
V_45 = true ;
goto V_48;
} else {
F_28 ( type ) ;
return 0 ;
}
}
int T_2 F_32 ( T_1 V_5 , T_1 V_6 ,
int V_20 )
{
return F_31 ( & V_2 . V_3 , V_5 , V_6 , V_20 ) ;
}
int T_2 F_33 ( T_1 V_5 , T_1 V_6 )
{
return F_31 ( & V_2 . V_3 , V_5 , V_6 , V_27 ) ;
}
static int T_2 F_34 ( struct V_1 * type ,
T_1 V_5 , T_1 V_6 ,
int * V_52 , int * V_53 )
{
T_1 V_18 = V_5 + F_2 ( V_5 , & V_6 ) ;
int V_12 ;
* V_52 = * V_53 = 0 ;
while ( type -> V_13 + 2 > type -> F_8 )
if ( F_21 ( type ) < 0 )
return - V_51 ;
for ( V_12 = 0 ; V_12 < type -> V_13 ; V_12 ++ ) {
struct V_29 * V_44 = & type -> V_15 [ V_12 ] ;
T_1 V_49 = V_44 -> V_5 ;
T_1 V_50 = V_49 + V_44 -> V_6 ;
if ( V_49 >= V_18 )
break;
if ( V_50 <= V_5 )
continue;
if ( V_49 < V_5 ) {
V_44 -> V_5 = V_5 ;
V_44 -> V_6 -= V_5 - V_49 ;
type -> V_31 -= V_5 - V_49 ;
F_30 ( type , V_12 , V_49 , V_5 - V_49 ,
F_29 ( V_44 ) ) ;
} else if ( V_50 > V_18 ) {
V_44 -> V_5 = V_18 ;
V_44 -> V_6 -= V_18 - V_49 ;
type -> V_31 -= V_18 - V_49 ;
F_30 ( type , V_12 -- , V_49 , V_18 - V_49 ,
F_29 ( V_44 ) ) ;
} else {
if ( ! * V_53 )
* V_52 = V_12 ;
* V_53 = V_12 + 1 ;
}
}
return 0 ;
}
static int T_2 F_35 ( struct V_1 * type ,
T_1 V_5 , T_1 V_6 )
{
int V_52 , V_53 ;
int V_12 , V_54 ;
V_54 = F_34 ( type , V_5 , V_6 , & V_52 , & V_53 ) ;
if ( V_54 )
return V_54 ;
for ( V_12 = V_53 - 1 ; V_12 >= V_52 ; V_12 -- )
F_18 ( type , V_12 ) ;
return 0 ;
}
int T_2 F_36 ( T_1 V_5 , T_1 V_6 )
{
return F_35 ( & V_2 . V_3 , V_5 , V_6 ) ;
}
int T_2 F_14 ( T_1 V_5 , T_1 V_6 )
{
F_26 ( L_6 ,
( unsigned long long ) V_5 ,
( unsigned long long ) V_5 + V_6 ,
( void * ) V_55 ) ;
return F_35 ( & V_2 . V_4 , V_5 , V_6 ) ;
}
int T_2 F_17 ( T_1 V_5 , T_1 V_6 )
{
struct V_1 * V_56 = & V_2 . V_4 ;
F_26 ( L_7 ,
( unsigned long long ) V_5 ,
( unsigned long long ) V_5 + V_6 ,
( void * ) V_55 ) ;
F_27 ( 0 == V_6 ) ;
return F_31 ( V_56 , V_5 , V_6 , V_27 ) ;
}
void T_2 F_37 ( T_3 * V_43 , int V_20 ,
T_1 * V_57 ,
T_1 * V_58 , int * V_59 )
{
struct V_1 * V_60 = & V_2 . V_3 ;
struct V_1 * V_61 = & V_2 . V_4 ;
int V_62 = * V_43 & 0xffffffff ;
int V_63 = * V_43 >> 32 ;
for ( ; V_62 < V_60 -> V_13 ; V_62 ++ ) {
struct V_29 * V_64 = & V_60 -> V_15 [ V_62 ] ;
T_1 V_65 = V_64 -> V_5 ;
T_1 V_66 = V_64 -> V_5 + V_64 -> V_6 ;
if ( V_20 != V_27 && V_20 != F_29 ( V_64 ) )
continue;
for ( ; V_63 < V_61 -> V_13 + 1 ; V_63 ++ ) {
struct V_29 * V_30 = & V_61 -> V_15 [ V_63 ] ;
T_1 V_67 = V_63 ? V_30 [ - 1 ] . V_5 + V_30 [ - 1 ] . V_6 : 0 ;
T_1 V_68 = V_63 < V_61 -> V_13 ? V_30 -> V_5 : V_7 ;
if ( V_67 >= V_66 )
break;
if ( V_65 < V_68 ) {
if ( V_57 )
* V_57 = F_8 ( V_65 , V_67 ) ;
if ( V_58 )
* V_58 = F_3 ( V_66 , V_68 ) ;
if ( V_59 )
* V_59 = F_29 ( V_64 ) ;
if ( V_66 <= V_68 )
V_62 ++ ;
else
V_63 ++ ;
* V_43 = ( V_69 ) V_62 | ( T_3 ) V_63 << 32 ;
return;
}
}
}
* V_43 = V_7 ;
}
void T_2 F_38 ( T_3 * V_43 , int V_20 ,
T_1 * V_57 ,
T_1 * V_58 , int * V_59 )
{
struct V_1 * V_60 = & V_2 . V_3 ;
struct V_1 * V_61 = & V_2 . V_4 ;
int V_62 = * V_43 & 0xffffffff ;
int V_63 = * V_43 >> 32 ;
if ( * V_43 == ( T_3 ) V_7 ) {
V_62 = V_60 -> V_13 - 1 ;
V_63 = V_61 -> V_13 ;
}
for ( ; V_62 >= 0 ; V_62 -- ) {
struct V_29 * V_64 = & V_60 -> V_15 [ V_62 ] ;
T_1 V_65 = V_64 -> V_5 ;
T_1 V_66 = V_64 -> V_5 + V_64 -> V_6 ;
if ( V_20 != V_27 && V_20 != F_29 ( V_64 ) )
continue;
for ( ; V_63 >= 0 ; V_63 -- ) {
struct V_29 * V_30 = & V_61 -> V_15 [ V_63 ] ;
T_1 V_67 = V_63 ? V_30 [ - 1 ] . V_5 + V_30 [ - 1 ] . V_6 : 0 ;
T_1 V_68 = V_63 < V_61 -> V_13 ? V_30 -> V_5 : V_7 ;
if ( V_68 <= V_65 )
break;
if ( V_66 > V_67 ) {
if ( V_57 )
* V_57 = F_8 ( V_65 , V_67 ) ;
if ( V_58 )
* V_58 = F_3 ( V_66 , V_68 ) ;
if ( V_59 )
* V_59 = F_29 ( V_64 ) ;
if ( V_65 >= V_67 )
V_62 -- ;
else
V_63 -- ;
* V_43 = ( V_69 ) V_62 | ( T_3 ) V_63 << 32 ;
return;
}
}
}
* V_43 = V_7 ;
}
void T_2 F_39 ( int * V_43 , int V_20 ,
unsigned long * V_70 ,
unsigned long * V_71 , int * V_59 )
{
struct V_1 * type = & V_2 . V_3 ;
struct V_29 * V_30 ;
while ( ++ * V_43 < type -> V_13 ) {
V_30 = & type -> V_15 [ * V_43 ] ;
if ( F_40 ( V_30 -> V_5 ) >= F_41 ( V_30 -> V_5 + V_30 -> V_6 ) )
continue;
if ( V_20 == V_27 || V_20 == V_30 -> V_20 )
break;
}
if ( * V_43 >= type -> V_13 ) {
* V_43 = - 1 ;
return;
}
if ( V_70 )
* V_70 = F_40 ( V_30 -> V_5 ) ;
if ( V_71 )
* V_71 = F_41 ( V_30 -> V_5 + V_30 -> V_6 ) ;
if ( V_59 )
* V_59 = V_30 -> V_20 ;
}
int T_2 F_42 ( T_1 V_5 , T_1 V_6 ,
int V_20 )
{
struct V_1 * type = & V_2 . V_3 ;
int V_52 , V_53 ;
int V_12 , V_54 ;
V_54 = F_34 ( type , V_5 , V_6 , & V_52 , & V_53 ) ;
if ( V_54 )
return V_54 ;
for ( V_12 = V_52 ; V_12 < V_53 ; V_12 ++ )
type -> V_15 [ V_12 ] . V_20 = V_20 ;
F_28 ( type ) ;
return 0 ;
}
static T_1 T_4 F_43 ( T_1 V_6 ,
T_1 V_19 , T_1 V_72 ,
int V_20 )
{
T_1 V_73 ;
V_6 = F_44 ( V_6 , V_19 ) ;
V_73 = F_6 ( 0 , V_72 , V_6 , V_19 , V_20 ) ;
if ( V_73 && ! F_17 ( V_73 , V_6 ) )
return V_73 ;
return 0 ;
}
T_1 T_4 F_45 ( T_1 V_6 , T_1 V_19 , int V_20 )
{
return F_43 ( V_6 , V_19 , V_24 , V_20 ) ;
}
T_1 T_4 F_46 ( T_1 V_6 , T_1 V_19 , T_1 V_72 )
{
return F_43 ( V_6 , V_19 , V_72 , V_27 ) ;
}
T_1 T_4 F_47 ( T_1 V_6 , T_1 V_19 , T_1 V_72 )
{
T_1 V_74 ;
V_74 = F_46 ( V_6 , V_19 , V_72 ) ;
if ( V_74 == 0 )
F_48 ( L_8 ,
( unsigned long long ) V_6 , ( unsigned long long ) V_72 ) ;
return V_74 ;
}
T_1 T_4 F_49 ( T_1 V_6 , T_1 V_19 )
{
return F_47 ( V_6 , V_19 , V_24 ) ;
}
T_1 T_4 F_50 ( T_1 V_6 , T_1 V_19 , int V_20 )
{
T_1 V_75 = F_45 ( V_6 , V_19 , V_20 ) ;
if ( V_75 )
return V_75 ;
return F_47 ( V_6 , V_19 , V_24 ) ;
}
T_1 T_4 F_51 ( void )
{
return V_2 . V_3 . V_31 ;
}
T_1 T_2 F_52 ( void )
{
return V_2 . V_3 . V_15 [ 0 ] . V_5 ;
}
T_1 T_2 F_53 ( void )
{
int V_43 = V_2 . V_3 . V_13 - 1 ;
return ( V_2 . V_3 . V_15 [ V_43 ] . V_5 + V_2 . V_3 . V_15 [ V_43 ] . V_6 ) ;
}
void T_4 F_54 ( T_1 V_76 )
{
unsigned long V_12 ;
T_1 V_72 = ( T_1 ) V_7 ;
if ( ! V_76 )
return;
for ( V_12 = 0 ; V_12 < V_2 . V_3 . V_13 ; V_12 ++ ) {
struct V_29 * V_30 = & V_2 . V_3 . V_15 [ V_12 ] ;
if ( V_76 <= V_30 -> V_6 ) {
V_72 = V_30 -> V_5 + V_76 ;
break;
}
V_76 -= V_30 -> V_6 ;
}
F_35 ( & V_2 . V_3 , V_72 , ( T_1 ) V_7 ) ;
F_35 ( & V_2 . V_4 , V_72 , ( T_1 ) V_7 ) ;
}
static int T_2 F_55 ( struct V_1 * type , T_1 V_36 )
{
unsigned int V_77 = 0 , V_78 = type -> V_13 ;
do {
unsigned int V_79 = ( V_78 + V_77 ) / 2 ;
if ( V_36 < type -> V_15 [ V_79 ] . V_5 )
V_78 = V_79 ;
else if ( V_36 >= ( type -> V_15 [ V_79 ] . V_5 +
type -> V_15 [ V_79 ] . V_6 ) )
V_77 = V_79 + 1 ;
else
return V_79 ;
} while ( V_77 < V_78 );
return - 1 ;
}
int T_4 F_56 ( T_1 V_36 )
{
return F_55 ( & V_2 . V_4 , V_36 ) != - 1 ;
}
int T_2 F_57 ( T_1 V_36 )
{
return F_55 ( & V_2 . V_3 , V_36 ) != - 1 ;
}
int T_2 F_58 ( T_1 V_5 , T_1 V_6 )
{
int V_43 = F_55 ( & V_2 . V_3 , V_5 ) ;
T_1 V_18 = V_5 + F_2 ( V_5 , & V_6 ) ;
if ( V_43 == - 1 )
return 0 ;
return V_2 . V_3 . V_15 [ V_43 ] . V_5 <= V_5 &&
( V_2 . V_3 . V_15 [ V_43 ] . V_5 +
V_2 . V_3 . V_15 [ V_43 ] . V_6 ) >= V_18 ;
}
int T_2 F_59 ( T_1 V_5 , T_1 V_6 )
{
F_2 ( V_5 , & V_6 ) ;
return F_5 ( & V_2 . V_4 , V_5 , V_6 ) >= 0 ;
}
void T_2 F_60 ( T_1 V_76 )
{
V_2 . V_25 = V_76 ;
}
static void T_2 F_61 ( struct V_1 * type , char * V_80 )
{
unsigned long long V_5 , V_6 ;
int V_12 ;
F_62 ( L_9 , V_80 , type -> V_13 ) ;
for ( V_12 = 0 ; V_12 < type -> V_13 ; V_12 ++ ) {
struct V_29 * V_44 = & type -> V_15 [ V_12 ] ;
char V_81 [ 32 ] = L_10 ;
V_5 = V_44 -> V_5 ;
V_6 = V_44 -> V_6 ;
#ifdef F_63
if ( F_29 ( V_44 ) != V_27 )
snprintf ( V_81 , sizeof( V_81 ) , L_11 ,
F_29 ( V_44 ) ) ;
#endif
F_62 ( L_12 ,
V_80 , V_12 , V_5 , V_5 + V_6 - 1 , V_6 , V_81 ) ;
}
}
void T_2 F_64 ( void )
{
F_62 ( L_13 ) ;
F_62 ( L_14 ,
( unsigned long long ) V_2 . V_3 . V_31 ,
( unsigned long long ) V_2 . V_4 . V_31 ) ;
F_61 ( & V_2 . V_3 , L_1 ) ;
F_61 ( & V_2 . V_4 , L_2 ) ;
}
void T_4 F_65 ( void )
{
V_38 = 1 ;
}
static int T_4 F_66 ( char * V_82 )
{
if ( V_82 && strstr ( V_82 , L_15 ) )
V_83 = 1 ;
return 0 ;
}
static int F_67 ( struct V_84 * V_64 , void * V_85 )
{
struct V_1 * type = V_64 -> V_85 ;
struct V_29 * V_86 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < type -> V_13 ; V_12 ++ ) {
V_86 = & type -> V_15 [ V_12 ] ;
F_68 ( V_64 , L_16 , V_12 ) ;
if ( sizeof( T_1 ) == 4 )
F_68 ( V_64 , L_17 ,
( unsigned long ) V_86 -> V_5 ,
( unsigned long ) ( V_86 -> V_5 + V_86 -> V_6 - 1 ) ) ;
else
F_68 ( V_64 , L_18 ,
( unsigned long long ) V_86 -> V_5 ,
( unsigned long long ) ( V_86 -> V_5 + V_86 -> V_6 - 1 ) ) ;
}
return 0 ;
}
static int F_69 ( struct V_87 * V_87 , struct V_88 * V_88 )
{
return F_70 ( V_88 , F_67 , V_87 -> V_89 ) ;
}
static int T_4 F_71 ( void )
{
struct V_90 * V_91 = F_72 ( L_19 , NULL ) ;
if ( ! V_91 )
return - V_92 ;
F_73 ( L_1 , V_93 , V_91 , & V_2 . V_3 , & V_94 ) ;
F_73 ( L_2 , V_93 , V_91 , & V_2 . V_4 , & V_94 ) ;
return 0 ;
}
