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
memmove ( V_49 , V_49 + 1 , ( type -> V_13 - ( V_12 + 1 ) ) * sizeof( * V_49 ) ) ;
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
T_2 T_1 F_53 ( void )
{
return V_2 . V_3 . V_15 [ 0 ] . V_5 ;
}
T_2 T_1 F_54 ( void )
{
int V_50 = V_2 . V_3 . V_13 - 1 ;
return ( V_2 . V_3 . V_15 [ V_50 ] . V_5 + V_2 . V_3 . V_15 [ V_50 ] . V_6 ) ;
}
void T_4 F_55 ( T_2 V_83 )
{
unsigned long V_12 ;
T_2 V_79 = ( T_2 ) V_7 ;
if ( ! V_83 )
return;
for ( V_12 = 0 ; V_12 < V_2 . V_3 . V_13 ; V_12 ++ ) {
struct V_32 * V_28 = & V_2 . V_3 . V_15 [ V_12 ] ;
if ( V_83 <= V_28 -> V_6 ) {
V_79 = V_28 -> V_5 + V_83 ;
break;
}
V_83 -= V_28 -> V_6 ;
}
F_36 ( & V_2 . V_3 , V_79 , ( T_2 ) V_7 ) ;
F_36 ( & V_2 . V_4 , V_79 , ( T_2 ) V_7 ) ;
}
static int T_1 F_56 ( struct V_1 * type , T_2 V_30 )
{
unsigned int V_84 = 0 , V_85 = type -> V_13 ;
do {
unsigned int V_86 = ( V_85 + V_84 ) / 2 ;
if ( V_30 < type -> V_15 [ V_86 ] . V_5 )
V_85 = V_86 ;
else if ( V_30 >= ( type -> V_15 [ V_86 ] . V_5 +
type -> V_15 [ V_86 ] . V_6 ) )
V_84 = V_86 + 1 ;
else
return V_86 ;
} while ( V_84 < V_85 );
return - 1 ;
}
int T_4 F_57 ( T_2 V_30 )
{
return F_56 ( & V_2 . V_4 , V_30 ) != - 1 ;
}
int T_1 F_58 ( T_2 V_30 )
{
return F_56 ( & V_2 . V_3 , V_30 ) != - 1 ;
}
int T_1 F_59 ( T_2 V_5 , T_2 V_6 )
{
int V_50 = F_56 ( & V_2 . V_3 , V_5 ) ;
T_2 V_18 = V_5 + F_2 ( V_5 , & V_6 ) ;
if ( V_50 == - 1 )
return 0 ;
return V_2 . V_3 . V_15 [ V_50 ] . V_5 <= V_5 &&
( V_2 . V_3 . V_15 [ V_50 ] . V_5 +
V_2 . V_3 . V_15 [ V_50 ] . V_6 ) >= V_18 ;
}
int T_1 F_60 ( T_2 V_5 , T_2 V_6 )
{
F_2 ( V_5 , & V_6 ) ;
return F_5 ( & V_2 . V_4 , V_5 , V_6 ) >= 0 ;
}
void T_1 F_61 ( T_2 V_19 )
{
int V_12 ;
T_2 V_17 , V_18 , V_87 , V_88 ;
struct V_1 * V_67 = & V_2 . V_3 ;
for ( V_12 = 0 ; V_12 < V_67 -> V_13 ; V_12 ++ ) {
V_87 = V_67 -> V_15 [ V_12 ] . V_5 ;
V_88 = V_67 -> V_15 [ V_12 ] . V_5 + V_67 -> V_15 [ V_12 ] . V_6 ;
V_17 = F_45 ( V_87 , V_19 ) ;
V_18 = F_11 ( V_88 , V_19 ) ;
if ( V_17 == V_87 && V_18 == V_88 )
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
void T_1 F_62 ( T_2 V_83 )
{
V_2 . V_25 = V_83 ;
}
static void T_1 F_63 ( struct V_1 * type , char * V_89 )
{
unsigned long long V_5 , V_6 ;
int V_12 ;
F_64 ( L_9 , V_89 , type -> V_13 ) ;
for ( V_12 = 0 ; V_12 < type -> V_13 ; V_12 ++ ) {
struct V_32 * V_51 = & type -> V_15 [ V_12 ] ;
char V_90 [ 32 ] = L_10 ;
V_5 = V_51 -> V_5 ;
V_6 = V_51 -> V_6 ;
#ifdef F_65
if ( F_30 ( V_51 ) != V_27 )
snprintf ( V_90 , sizeof( V_90 ) , L_11 ,
F_30 ( V_51 ) ) ;
#endif
F_64 ( L_12 ,
V_89 , V_12 , V_5 , V_5 + V_6 - 1 , V_6 , V_90 ) ;
}
}
void T_1 F_66 ( void )
{
F_64 ( L_13 ) ;
F_64 ( L_14 ,
( unsigned long long ) V_2 . V_3 . V_29 ,
( unsigned long long ) V_2 . V_4 . V_29 ) ;
F_63 ( & V_2 . V_3 , L_1 ) ;
F_63 ( & V_2 . V_4 , L_2 ) ;
}
void T_4 F_67 ( void )
{
V_43 = 1 ;
}
static int T_4 F_68 ( char * V_91 )
{
if ( V_91 && strstr ( V_91 , L_15 ) )
V_92 = 1 ;
return 0 ;
}
static int F_69 ( struct V_93 * V_71 , void * V_94 )
{
struct V_1 * type = V_71 -> V_94 ;
struct V_32 * V_95 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < type -> V_13 ; V_12 ++ ) {
V_95 = & type -> V_15 [ V_12 ] ;
F_70 ( V_71 , L_16 , V_12 ) ;
if ( sizeof( T_2 ) == 4 )
F_70 ( V_71 , L_17 ,
( unsigned long ) V_95 -> V_5 ,
( unsigned long ) ( V_95 -> V_5 + V_95 -> V_6 - 1 ) ) ;
else
F_70 ( V_71 , L_18 ,
( unsigned long long ) V_95 -> V_5 ,
( unsigned long long ) ( V_95 -> V_5 + V_95 -> V_6 - 1 ) ) ;
}
return 0 ;
}
static int F_71 ( struct V_96 * V_96 , struct V_97 * V_97 )
{
return F_72 ( V_97 , F_69 , V_96 -> V_98 ) ;
}
static int T_4 F_73 ( void )
{
struct V_99 * V_100 = F_74 ( L_19 , NULL ) ;
if ( ! V_100 )
return - V_101 ;
F_75 ( L_1 , V_102 , V_100 , & V_2 . V_3 , & V_103 ) ;
F_75 ( L_2 , V_102 , V_100 , & V_2 . V_4 , & V_103 ) ;
return 0 ;
}
