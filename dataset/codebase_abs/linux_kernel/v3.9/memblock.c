static T_1 const char *
F_1 ( struct V_1 * type )
{
if ( type == & V_2 . V_3 )
return L_1 ;
else if ( type == & V_2 . V_4 )
return L_2 ;
else
return L_3 ;
}
static inline T_2 F_2 ( T_2 V_5 , T_2 * V_6 )
{
return * V_6 = F_3 ( * V_6 , ( T_2 ) V_7 - V_5 ) ;
}
static unsigned long T_1 F_4 ( T_2 V_8 , T_2 V_9 ,
T_2 V_10 , T_2 V_11 )
{
return ( ( V_8 < ( V_10 + V_11 ) ) && ( V_10 < ( V_8 + V_9 ) ) ) ;
}
static long T_1 F_5 ( struct V_1 * type ,
T_2 V_5 , T_2 V_6 )
{
unsigned long V_12 ;
for ( V_12 = 0 ; V_12 < type -> V_13 ; V_12 ++ ) {
T_2 V_14 = type -> V_15 [ V_12 ] . V_5 ;
T_2 V_16 = type -> V_15 [ V_12 ] . V_6 ;
if ( F_4 ( V_5 , V_6 , V_14 , V_16 ) )
break;
}
return ( V_12 < type -> V_13 ) ? V_12 : - 1 ;
}
T_2 T_1 F_6 ( T_2 V_17 ,
T_2 V_18 , T_2 V_6 ,
T_2 V_19 , int V_20 )
{
T_2 V_21 , V_22 , V_23 ;
T_3 V_12 ;
if ( V_18 == V_24 )
V_18 = V_2 . V_25 ;
V_17 = F_7 ( T_2 , V_17 , V_26 ) ;
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
T_2 T_1 F_12 ( T_2 V_17 ,
T_2 V_18 , T_2 V_6 ,
T_2 V_19 )
{
return F_6 ( V_17 , V_18 , V_6 , V_19 ,
V_27 ) ;
}
static void T_1 F_13 ( struct V_1 * type , unsigned long V_28 )
{
type -> V_29 -= type -> V_15 [ V_28 ] . V_6 ;
memmove ( & type -> V_15 [ V_28 ] , & type -> V_15 [ V_28 + 1 ] ,
( type -> V_13 - ( V_28 + 1 ) ) * sizeof( type -> V_15 [ V_28 ] ) ) ;
type -> V_13 -- ;
if ( type -> V_13 == 0 ) {
F_14 ( type -> V_29 != 0 ) ;
type -> V_13 = 1 ;
type -> V_15 [ 0 ] . V_5 = 0 ;
type -> V_15 [ 0 ] . V_6 = 0 ;
F_15 ( & type -> V_15 [ 0 ] , V_27 ) ;
}
}
T_2 T_1 F_16 (
T_2 * V_30 )
{
if ( V_2 . V_4 . V_15 == V_31 )
return 0 ;
* V_30 = F_17 ( V_2 . V_4 . V_15 ) ;
return F_18 ( sizeof( struct V_32 ) *
V_2 . V_4 . F_8 ) ;
}
static int T_1 F_19 ( struct V_1 * type ,
T_2 V_33 ,
T_2 V_34 )
{
struct V_32 * V_35 , * V_36 ;
T_2 V_37 , V_38 ;
T_2 V_39 , V_40 , V_30 ;
int V_41 = F_20 () ;
int * V_42 ;
if ( ! V_43 )
return - 1 ;
V_39 = type -> F_8 * sizeof( struct V_32 ) ;
V_40 = V_39 << 1 ;
V_37 = F_18 ( V_39 ) ;
V_38 = F_18 ( V_40 ) ;
if ( type == & V_2 . V_3 )
V_42 = & V_44 ;
else
V_42 = & V_45 ;
if ( V_41 ) {
V_35 = F_21 ( V_40 , V_46 ) ;
V_30 = V_35 ? F_17 ( V_35 ) : 0 ;
} else {
if ( type != & V_2 . V_4 )
V_33 = V_34 = 0 ;
V_30 = F_12 ( V_33 + V_34 ,
V_2 . V_25 ,
V_38 , V_26 ) ;
if ( ! V_30 && V_34 )
V_30 = F_12 ( 0 ,
F_3 ( V_33 , V_2 . V_25 ) ,
V_38 , V_26 ) ;
V_35 = V_30 ? F_22 ( V_30 ) : NULL ;
}
if ( ! V_30 ) {
F_23 ( L_4 ,
F_1 ( type ) , type -> F_8 , type -> F_8 * 2 ) ;
return - 1 ;
}
F_24 ( L_5 ,
F_1 ( type ) , type -> F_8 * 2 , ( T_3 ) V_30 ,
( T_3 ) V_30 + V_40 - 1 ) ;
memcpy ( V_35 , type -> V_15 , V_39 ) ;
memset ( V_35 + type -> F_8 , 0 , V_39 ) ;
V_36 = type -> V_15 ;
type -> V_15 = V_35 ;
type -> F_8 <<= 1 ;
if ( * V_42 )
F_25 ( V_36 ) ;
else if ( V_36 != V_47 &&
V_36 != V_31 )
F_26 ( F_17 ( V_36 ) , V_37 ) ;
if ( ! V_41 )
F_27 ( F_28 ( V_30 , V_38 ) ) ;
* V_42 = V_41 ;
return 0 ;
}
static void T_1 F_29 ( struct V_1 * type )
{
int V_12 = 0 ;
while ( V_12 < type -> V_13 - 1 ) {
struct V_32 * V_48 = & type -> V_15 [ V_12 ] ;
struct V_32 * V_49 = & type -> V_15 [ V_12 + 1 ] ;
if ( V_48 -> V_5 + V_48 -> V_6 != V_49 -> V_5 ||
F_30 ( V_48 ) !=
F_30 ( V_49 ) ) {
F_27 ( V_48 -> V_5 + V_48 -> V_6 > V_49 -> V_5 ) ;
V_12 ++ ;
continue;
}
V_48 -> V_6 += V_49 -> V_6 ;
memmove ( V_49 , V_49 + 1 , ( type -> V_13 - ( V_12 + 2 ) ) * sizeof( * V_49 ) ) ;
type -> V_13 -- ;
}
}
static void T_1 F_31 ( struct V_1 * type ,
int V_50 , T_2 V_5 ,
T_2 V_6 , int V_20 )
{
struct V_32 * V_51 = & type -> V_15 [ V_50 ] ;
F_27 ( type -> V_13 >= type -> F_8 ) ;
memmove ( V_51 + 1 , V_51 , ( type -> V_13 - V_50 ) * sizeof( * V_51 ) ) ;
V_51 -> V_5 = V_5 ;
V_51 -> V_6 = V_6 ;
F_15 ( V_51 , V_20 ) ;
type -> V_13 ++ ;
type -> V_29 += V_6 ;
}
static int T_1 F_32 ( struct V_1 * type ,
T_2 V_5 , T_2 V_6 , int V_20 )
{
bool V_52 = false ;
T_2 V_53 = V_5 ;
T_2 V_18 = V_5 + F_2 ( V_5 , & V_6 ) ;
int V_12 , V_54 ;
if ( ! V_6 )
return 0 ;
if ( type -> V_15 [ 0 ] . V_6 == 0 ) {
F_14 ( type -> V_13 != 1 || type -> V_29 ) ;
type -> V_15 [ 0 ] . V_5 = V_5 ;
type -> V_15 [ 0 ] . V_6 = V_6 ;
F_15 ( & type -> V_15 [ 0 ] , V_20 ) ;
type -> V_29 = V_6 ;
return 0 ;
}
V_55:
V_5 = V_53 ;
V_54 = 0 ;
for ( V_12 = 0 ; V_12 < type -> V_13 ; V_12 ++ ) {
struct V_32 * V_51 = & type -> V_15 [ V_12 ] ;
T_2 V_56 = V_51 -> V_5 ;
T_2 V_57 = V_56 + V_51 -> V_6 ;
if ( V_56 >= V_18 )
break;
if ( V_57 <= V_5 )
continue;
if ( V_56 > V_5 ) {
V_54 ++ ;
if ( V_52 )
F_31 ( type , V_12 ++ , V_5 ,
V_56 - V_5 , V_20 ) ;
}
V_5 = F_3 ( V_57 , V_18 ) ;
}
if ( V_5 < V_18 ) {
V_54 ++ ;
if ( V_52 )
F_31 ( type , V_12 , V_5 , V_18 - V_5 , V_20 ) ;
}
if ( ! V_52 ) {
while ( type -> V_13 + V_54 > type -> F_8 )
if ( F_19 ( type , V_53 , V_6 ) < 0 )
return - V_58 ;
V_52 = true ;
goto V_55;
} else {
F_29 ( type ) ;
return 0 ;
}
}
int T_1 F_33 ( T_2 V_5 , T_2 V_6 ,
int V_20 )
{
return F_32 ( & V_2 . V_3 , V_5 , V_6 , V_20 ) ;
}
int T_1 F_34 ( T_2 V_5 , T_2 V_6 )
{
return F_32 ( & V_2 . V_3 , V_5 , V_6 , V_27 ) ;
}
static int T_1 F_35 ( struct V_1 * type ,
T_2 V_5 , T_2 V_6 ,
int * V_59 , int * V_60 )
{
T_2 V_18 = V_5 + F_2 ( V_5 , & V_6 ) ;
int V_12 ;
* V_59 = * V_60 = 0 ;
if ( ! V_6 )
return 0 ;
while ( type -> V_13 + 2 > type -> F_8 )
if ( F_19 ( type , V_5 , V_6 ) < 0 )
return - V_58 ;
for ( V_12 = 0 ; V_12 < type -> V_13 ; V_12 ++ ) {
struct V_32 * V_51 = & type -> V_15 [ V_12 ] ;
T_2 V_56 = V_51 -> V_5 ;
T_2 V_57 = V_56 + V_51 -> V_6 ;
if ( V_56 >= V_18 )
break;
if ( V_57 <= V_5 )
continue;
if ( V_56 < V_5 ) {
V_51 -> V_5 = V_5 ;
V_51 -> V_6 -= V_5 - V_56 ;
type -> V_29 -= V_5 - V_56 ;
F_31 ( type , V_12 , V_56 , V_5 - V_56 ,
F_30 ( V_51 ) ) ;
} else if ( V_57 > V_18 ) {
V_51 -> V_5 = V_18 ;
V_51 -> V_6 -= V_18 - V_56 ;
type -> V_29 -= V_18 - V_56 ;
F_31 ( type , V_12 -- , V_56 , V_18 - V_56 ,
F_30 ( V_51 ) ) ;
} else {
if ( ! * V_60 )
* V_59 = V_12 ;
* V_60 = V_12 + 1 ;
}
}
return 0 ;
}
static int T_1 F_36 ( struct V_1 * type ,
T_2 V_5 , T_2 V_6 )
{
int V_59 , V_60 ;
int V_12 , V_61 ;
V_61 = F_35 ( type , V_5 , V_6 , & V_59 , & V_60 ) ;
if ( V_61 )
return V_61 ;
for ( V_12 = V_60 - 1 ; V_12 >= V_59 ; V_12 -- )
F_13 ( type , V_12 ) ;
return 0 ;
}
int T_1 F_37 ( T_2 V_5 , T_2 V_6 )
{
return F_36 ( & V_2 . V_3 , V_5 , V_6 ) ;
}
int T_1 F_26 ( T_2 V_5 , T_2 V_6 )
{
F_24 ( L_6 ,
( unsigned long long ) V_5 ,
( unsigned long long ) V_5 + V_6 ,
( void * ) V_62 ) ;
return F_36 ( & V_2 . V_4 , V_5 , V_6 ) ;
}
int T_1 F_28 ( T_2 V_5 , T_2 V_6 )
{
struct V_1 * V_63 = & V_2 . V_4 ;
F_24 ( L_7 ,
( unsigned long long ) V_5 ,
( unsigned long long ) V_5 + V_6 ,
( void * ) V_62 ) ;
return F_32 ( V_63 , V_5 , V_6 , V_27 ) ;
}
void T_1 F_38 ( T_3 * V_50 , int V_20 ,
T_2 * V_64 ,
T_2 * V_65 , int * V_66 )
{
struct V_1 * V_67 = & V_2 . V_3 ;
struct V_1 * V_68 = & V_2 . V_4 ;
int V_69 = * V_50 & 0xffffffff ;
int V_70 = * V_50 >> 32 ;
for ( ; V_69 < V_67 -> V_13 ; V_69 ++ ) {
struct V_32 * V_71 = & V_67 -> V_15 [ V_69 ] ;
T_2 V_72 = V_71 -> V_5 ;
T_2 V_73 = V_71 -> V_5 + V_71 -> V_6 ;
if ( V_20 != V_27 && V_20 != F_30 ( V_71 ) )
continue;
for ( ; V_70 < V_68 -> V_13 + 1 ; V_70 ++ ) {
struct V_32 * V_28 = & V_68 -> V_15 [ V_70 ] ;
T_2 V_74 = V_70 ? V_28 [ - 1 ] . V_5 + V_28 [ - 1 ] . V_6 : 0 ;
T_2 V_75 = V_70 < V_68 -> V_13 ? V_28 -> V_5 : V_7 ;
if ( V_74 >= V_73 )
break;
if ( V_72 < V_75 ) {
if ( V_64 )
* V_64 = F_8 ( V_72 , V_74 ) ;
if ( V_65 )
* V_65 = F_3 ( V_73 , V_75 ) ;
if ( V_66 )
* V_66 = F_30 ( V_71 ) ;
if ( V_73 <= V_75 )
V_69 ++ ;
else
V_70 ++ ;
* V_50 = ( V_76 ) V_69 | ( T_3 ) V_70 << 32 ;
return;
}
}
}
* V_50 = V_7 ;
}
void T_1 F_39 ( T_3 * V_50 , int V_20 ,
T_2 * V_64 ,
T_2 * V_65 , int * V_66 )
{
struct V_1 * V_67 = & V_2 . V_3 ;
struct V_1 * V_68 = & V_2 . V_4 ;
int V_69 = * V_50 & 0xffffffff ;
int V_70 = * V_50 >> 32 ;
if ( * V_50 == ( T_3 ) V_7 ) {
V_69 = V_67 -> V_13 - 1 ;
V_70 = V_68 -> V_13 ;
}
for ( ; V_69 >= 0 ; V_69 -- ) {
struct V_32 * V_71 = & V_67 -> V_15 [ V_69 ] ;
T_2 V_72 = V_71 -> V_5 ;
T_2 V_73 = V_71 -> V_5 + V_71 -> V_6 ;
if ( V_20 != V_27 && V_20 != F_30 ( V_71 ) )
continue;
for ( ; V_70 >= 0 ; V_70 -- ) {
struct V_32 * V_28 = & V_68 -> V_15 [ V_70 ] ;
T_2 V_74 = V_70 ? V_28 [ - 1 ] . V_5 + V_28 [ - 1 ] . V_6 : 0 ;
T_2 V_75 = V_70 < V_68 -> V_13 ? V_28 -> V_5 : V_7 ;
if ( V_75 <= V_72 )
break;
if ( V_73 > V_74 ) {
if ( V_64 )
* V_64 = F_8 ( V_72 , V_74 ) ;
if ( V_65 )
* V_65 = F_3 ( V_73 , V_75 ) ;
if ( V_66 )
* V_66 = F_30 ( V_71 ) ;
if ( V_72 >= V_74 )
V_69 -- ;
else
V_70 -- ;
* V_50 = ( V_76 ) V_69 | ( T_3 ) V_70 << 32 ;
return;
}
}
}
* V_50 = V_7 ;
}
void T_1 F_40 ( int * V_50 , int V_20 ,
unsigned long * V_77 ,
unsigned long * V_78 , int * V_66 )
{
struct V_1 * type = & V_2 . V_3 ;
struct V_32 * V_28 ;
while ( ++ * V_50 < type -> V_13 ) {
V_28 = & type -> V_15 [ * V_50 ] ;
if ( F_41 ( V_28 -> V_5 ) >= F_42 ( V_28 -> V_5 + V_28 -> V_6 ) )
continue;
if ( V_20 == V_27 || V_20 == V_28 -> V_20 )
break;
}
if ( * V_50 >= type -> V_13 ) {
* V_50 = - 1 ;
return;
}
if ( V_77 )
* V_77 = F_41 ( V_28 -> V_5 ) ;
if ( V_78 )
* V_78 = F_42 ( V_28 -> V_5 + V_28 -> V_6 ) ;
if ( V_66 )
* V_66 = V_28 -> V_20 ;
}
int T_1 F_43 ( T_2 V_5 , T_2 V_6 ,
int V_20 )
{
struct V_1 * type = & V_2 . V_3 ;
int V_59 , V_60 ;
int V_12 , V_61 ;
V_61 = F_35 ( type , V_5 , V_6 , & V_59 , & V_60 ) ;
if ( V_61 )
return V_61 ;
for ( V_12 = V_59 ; V_12 < V_60 ; V_12 ++ )
F_15 ( & type -> V_15 [ V_12 ] , V_20 ) ;
F_29 ( type ) ;
return 0 ;
}
static T_2 T_4 F_44 ( T_2 V_6 ,
T_2 V_19 , T_2 V_79 ,
int V_20 )
{
T_2 V_80 ;
V_6 = F_45 ( V_6 , V_19 ) ;
V_80 = F_6 ( 0 , V_79 , V_6 , V_19 , V_20 ) ;
if ( V_80 && ! F_28 ( V_80 , V_6 ) )
return V_80 ;
return 0 ;
}
T_2 T_4 F_46 ( T_2 V_6 , T_2 V_19 , int V_20 )
{
return F_44 ( V_6 , V_19 , V_24 , V_20 ) ;
}
T_2 T_4 F_47 ( T_2 V_6 , T_2 V_19 , T_2 V_79 )
{
return F_44 ( V_6 , V_19 , V_79 , V_27 ) ;
}
T_2 T_4 F_48 ( T_2 V_6 , T_2 V_19 , T_2 V_79 )
{
T_2 V_81 ;
V_81 = F_47 ( V_6 , V_19 , V_79 ) ;
if ( V_81 == 0 )
F_49 ( L_8 ,
( unsigned long long ) V_6 , ( unsigned long long ) V_79 ) ;
return V_81 ;
}
T_2 T_4 F_50 ( T_2 V_6 , T_2 V_19 )
{
return F_48 ( V_6 , V_19 , V_24 ) ;
}
T_2 T_4 F_51 ( T_2 V_6 , T_2 V_19 , int V_20 )
{
T_2 V_82 = F_46 ( V_6 , V_19 , V_20 ) ;
if ( V_82 )
return V_82 ;
return F_48 ( V_6 , V_19 , V_24 ) ;
}
T_2 T_4 F_52 ( void )
{
return V_2 . V_3 . V_29 ;
}
T_2 T_4 F_53 ( unsigned long V_83 )
{
unsigned long V_84 = 0 ;
struct V_32 * V_28 ;
unsigned long V_85 , V_86 ;
F_54 (memory, r) {
V_85 = F_55 ( V_28 ) ;
V_86 = F_56 ( V_28 ) ;
V_85 = F_57 (unsigned long, start_pfn, limit_pfn) ;
V_86 = F_57 (unsigned long, end_pfn, limit_pfn) ;
V_84 += V_86 - V_85 ;
}
return ( T_2 ) V_84 << V_87 ;
}
T_2 T_1 F_58 ( void )
{
return V_2 . V_3 . V_15 [ 0 ] . V_5 ;
}
T_2 T_1 F_59 ( void )
{
int V_50 = V_2 . V_3 . V_13 - 1 ;
return ( V_2 . V_3 . V_15 [ V_50 ] . V_5 + V_2 . V_3 . V_15 [ V_50 ] . V_6 ) ;
}
void T_4 F_60 ( T_2 V_88 )
{
unsigned long V_12 ;
T_2 V_79 = ( T_2 ) V_7 ;
if ( ! V_88 )
return;
for ( V_12 = 0 ; V_12 < V_2 . V_3 . V_13 ; V_12 ++ ) {
struct V_32 * V_28 = & V_2 . V_3 . V_15 [ V_12 ] ;
if ( V_88 <= V_28 -> V_6 ) {
V_79 = V_28 -> V_5 + V_88 ;
break;
}
V_88 -= V_28 -> V_6 ;
}
F_36 ( & V_2 . V_3 , V_79 , ( T_2 ) V_7 ) ;
F_36 ( & V_2 . V_4 , V_79 , ( T_2 ) V_7 ) ;
}
static int T_1 F_61 ( struct V_1 * type , T_2 V_30 )
{
unsigned int V_89 = 0 , V_90 = type -> V_13 ;
do {
unsigned int V_91 = ( V_90 + V_89 ) / 2 ;
if ( V_30 < type -> V_15 [ V_91 ] . V_5 )
V_90 = V_91 ;
else if ( V_30 >= ( type -> V_15 [ V_91 ] . V_5 +
type -> V_15 [ V_91 ] . V_6 ) )
V_89 = V_91 + 1 ;
else
return V_91 ;
} while ( V_89 < V_90 );
return - 1 ;
}
int T_4 F_62 ( T_2 V_30 )
{
return F_61 ( & V_2 . V_4 , V_30 ) != - 1 ;
}
int T_1 F_63 ( T_2 V_30 )
{
return F_61 ( & V_2 . V_3 , V_30 ) != - 1 ;
}
int T_1 F_64 ( T_2 V_5 , T_2 V_6 )
{
int V_50 = F_61 ( & V_2 . V_3 , V_5 ) ;
T_2 V_18 = V_5 + F_2 ( V_5 , & V_6 ) ;
if ( V_50 == - 1 )
return 0 ;
return V_2 . V_3 . V_15 [ V_50 ] . V_5 <= V_5 &&
( V_2 . V_3 . V_15 [ V_50 ] . V_5 +
V_2 . V_3 . V_15 [ V_50 ] . V_6 ) >= V_18 ;
}
int T_1 F_65 ( T_2 V_5 , T_2 V_6 )
{
F_2 ( V_5 , & V_6 ) ;
return F_5 ( & V_2 . V_4 , V_5 , V_6 ) >= 0 ;
}
void T_1 F_66 ( T_2 V_19 )
{
int V_12 ;
T_2 V_17 , V_18 , V_92 , V_93 ;
struct V_1 * V_67 = & V_2 . V_3 ;
for ( V_12 = 0 ; V_12 < V_67 -> V_13 ; V_12 ++ ) {
V_92 = V_67 -> V_15 [ V_12 ] . V_5 ;
V_93 = V_67 -> V_15 [ V_12 ] . V_5 + V_67 -> V_15 [ V_12 ] . V_6 ;
V_17 = F_45 ( V_92 , V_19 ) ;
V_18 = F_11 ( V_93 , V_19 ) ;
if ( V_17 == V_92 && V_18 == V_93 )
continue;
if ( V_17 < V_18 ) {
V_67 -> V_15 [ V_12 ] . V_5 = V_17 ;
V_67 -> V_15 [ V_12 ] . V_6 = V_18 - V_17 ;
} else {
F_13 ( V_67 , V_12 ) ;
V_12 -- ;
}
}
}
void T_1 F_67 ( T_2 V_88 )
{
V_2 . V_25 = V_88 ;
}
static void T_1 F_68 ( struct V_1 * type , char * V_94 )
{
unsigned long long V_5 , V_6 ;
int V_12 ;
F_69 ( L_9 , V_94 , type -> V_13 ) ;
for ( V_12 = 0 ; V_12 < type -> V_13 ; V_12 ++ ) {
struct V_32 * V_51 = & type -> V_15 [ V_12 ] ;
char V_95 [ 32 ] = L_10 ;
V_5 = V_51 -> V_5 ;
V_6 = V_51 -> V_6 ;
#ifdef F_70
if ( F_30 ( V_51 ) != V_27 )
snprintf ( V_95 , sizeof( V_95 ) , L_11 ,
F_30 ( V_51 ) ) ;
#endif
F_69 ( L_12 ,
V_94 , V_12 , V_5 , V_5 + V_6 - 1 , V_6 , V_95 ) ;
}
}
void T_1 F_71 ( void )
{
F_69 ( L_13 ) ;
F_69 ( L_14 ,
( unsigned long long ) V_2 . V_3 . V_29 ,
( unsigned long long ) V_2 . V_4 . V_29 ) ;
F_68 ( & V_2 . V_3 , L_1 ) ;
F_68 ( & V_2 . V_4 , L_2 ) ;
}
void T_4 F_72 ( void )
{
V_43 = 1 ;
}
static int T_4 F_73 ( char * V_96 )
{
if ( V_96 && strstr ( V_96 , L_15 ) )
V_97 = 1 ;
return 0 ;
}
static int F_74 ( struct V_98 * V_71 , void * V_99 )
{
struct V_1 * type = V_71 -> V_99 ;
struct V_32 * V_100 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < type -> V_13 ; V_12 ++ ) {
V_100 = & type -> V_15 [ V_12 ] ;
F_75 ( V_71 , L_16 , V_12 ) ;
if ( sizeof( T_2 ) == 4 )
F_75 ( V_71 , L_17 ,
( unsigned long ) V_100 -> V_5 ,
( unsigned long ) ( V_100 -> V_5 + V_100 -> V_6 - 1 ) ) ;
else
F_75 ( V_71 , L_18 ,
( unsigned long long ) V_100 -> V_5 ,
( unsigned long long ) ( V_100 -> V_5 + V_100 -> V_6 - 1 ) ) ;
}
return 0 ;
}
static int F_76 ( struct V_101 * V_101 , struct V_102 * V_102 )
{
return F_77 ( V_102 , F_74 , V_101 -> V_103 ) ;
}
static int T_4 F_78 ( void )
{
struct V_104 * V_105 = F_79 ( L_19 , NULL ) ;
if ( ! V_105 )
return - V_106 ;
F_80 ( L_1 , V_107 , V_105 , & V_2 . V_3 , & V_108 ) ;
F_80 ( L_2 , V_107 , V_105 , & V_2 . V_4 , & V_108 ) ;
return 0 ;
}
