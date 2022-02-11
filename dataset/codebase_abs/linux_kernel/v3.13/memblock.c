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
static T_2 T_1
F_6 ( T_2 V_17 , T_2 V_18 ,
T_2 V_6 , T_2 V_19 , int V_20 )
{
T_2 V_21 , V_22 , V_23 ;
T_3 V_12 ;
F_7 (i, nid, &this_start, &this_end, NULL) {
V_21 = F_8 ( V_21 , V_17 , V_18 ) ;
V_22 = F_8 ( V_22 , V_17 , V_18 ) ;
V_23 = F_9 ( V_21 , V_19 ) ;
if ( V_23 < V_22 && V_22 - V_23 >= V_6 )
return V_23 ;
}
return 0 ;
}
static T_2 T_1
F_10 ( T_2 V_17 , T_2 V_18 ,
T_2 V_6 , T_2 V_19 , int V_20 )
{
T_2 V_21 , V_22 , V_23 ;
T_3 V_12 ;
F_11 (i, nid, &this_start, &this_end, NULL) {
V_21 = F_8 ( V_21 , V_17 , V_18 ) ;
V_22 = F_8 ( V_22 , V_17 , V_18 ) ;
if ( V_22 < V_6 )
continue;
V_23 = F_12 ( V_22 - V_6 , V_19 ) ;
if ( V_23 >= V_21 )
return V_23 ;
}
return 0 ;
}
T_2 T_1 F_13 ( T_2 V_17 ,
T_2 V_18 , T_2 V_6 ,
T_2 V_19 , int V_20 )
{
int V_24 ;
T_2 V_25 ;
if ( V_18 == V_26 )
V_18 = V_2 . V_27 ;
V_17 = F_14 ( T_2 , V_17 , V_28 ) ;
V_18 = F_15 ( V_17 , V_18 ) ;
V_25 = F_16 ( V_29 ) ;
if ( F_17 () && V_18 > V_25 ) {
T_2 V_30 ;
V_30 = F_15 ( V_17 , V_25 ) ;
V_24 = F_6 ( V_30 , V_18 ,
V_6 , V_19 , V_20 ) ;
if ( V_24 )
return V_24 ;
F_18 ( 1 , L_4
L_5 ) ;
}
return F_10 ( V_17 , V_18 , V_6 , V_19 , V_20 ) ;
}
T_2 T_1 F_19 ( T_2 V_17 ,
T_2 V_18 , T_2 V_6 ,
T_2 V_19 )
{
return F_13 ( V_17 , V_18 , V_6 , V_19 ,
V_31 ) ;
}
static void T_1 F_20 ( struct V_1 * type , unsigned long V_32 )
{
type -> V_33 -= type -> V_15 [ V_32 ] . V_6 ;
memmove ( & type -> V_15 [ V_32 ] , & type -> V_15 [ V_32 + 1 ] ,
( type -> V_13 - ( V_32 + 1 ) ) * sizeof( type -> V_15 [ V_32 ] ) ) ;
type -> V_13 -- ;
if ( type -> V_13 == 0 ) {
F_21 ( type -> V_33 != 0 ) ;
type -> V_13 = 1 ;
type -> V_15 [ 0 ] . V_5 = 0 ;
type -> V_15 [ 0 ] . V_6 = 0 ;
F_22 ( & type -> V_15 [ 0 ] , V_31 ) ;
}
}
T_2 T_1 F_23 (
T_2 * V_34 )
{
if ( V_2 . V_4 . V_15 == V_35 )
return 0 ;
* V_34 = F_24 ( V_2 . V_4 . V_15 ) ;
return F_25 ( sizeof( struct V_36 ) *
V_2 . V_4 . F_15 ) ;
}
static int T_1 F_26 ( struct V_1 * type ,
T_2 V_37 ,
T_2 V_38 )
{
struct V_36 * V_39 , * V_40 ;
T_2 V_41 , V_42 ;
T_2 V_43 , V_44 , V_34 ;
int V_45 = F_27 () ;
int * V_46 ;
if ( ! V_47 )
return - 1 ;
V_43 = type -> F_15 * sizeof( struct V_36 ) ;
V_44 = V_43 << 1 ;
V_41 = F_25 ( V_43 ) ;
V_42 = F_25 ( V_44 ) ;
if ( type == & V_2 . V_3 )
V_46 = & V_48 ;
else
V_46 = & V_49 ;
if ( V_45 ) {
V_39 = F_28 ( V_44 , V_50 ) ;
V_34 = V_39 ? F_24 ( V_39 ) : 0 ;
} else {
if ( type != & V_2 . V_4 )
V_37 = V_38 = 0 ;
V_34 = F_19 ( V_37 + V_38 ,
V_2 . V_27 ,
V_42 , V_28 ) ;
if ( ! V_34 && V_38 )
V_34 = F_19 ( 0 ,
F_3 ( V_37 , V_2 . V_27 ) ,
V_42 , V_28 ) ;
V_39 = V_34 ? F_29 ( V_34 ) : NULL ;
}
if ( ! V_34 ) {
F_30 ( L_6 ,
F_1 ( type ) , type -> F_15 , type -> F_15 * 2 ) ;
return - 1 ;
}
F_31 ( L_7 ,
F_1 ( type ) , type -> F_15 * 2 , ( T_3 ) V_34 ,
( T_3 ) V_34 + V_44 - 1 ) ;
memcpy ( V_39 , type -> V_15 , V_43 ) ;
memset ( V_39 + type -> F_15 , 0 , V_43 ) ;
V_40 = type -> V_15 ;
type -> V_15 = V_39 ;
type -> F_15 <<= 1 ;
if ( * V_46 )
F_32 ( V_40 ) ;
else if ( V_40 != V_51 &&
V_40 != V_35 )
F_33 ( F_24 ( V_40 ) , V_41 ) ;
if ( ! V_45 )
F_34 ( F_35 ( V_34 , V_42 ) ) ;
* V_46 = V_45 ;
return 0 ;
}
static void T_1 F_36 ( struct V_1 * type )
{
int V_12 = 0 ;
while ( V_12 < type -> V_13 - 1 ) {
struct V_36 * V_52 = & type -> V_15 [ V_12 ] ;
struct V_36 * V_53 = & type -> V_15 [ V_12 + 1 ] ;
if ( V_52 -> V_5 + V_52 -> V_6 != V_53 -> V_5 ||
F_37 ( V_52 ) !=
F_37 ( V_53 ) ) {
F_34 ( V_52 -> V_5 + V_52 -> V_6 > V_53 -> V_5 ) ;
V_12 ++ ;
continue;
}
V_52 -> V_6 += V_53 -> V_6 ;
memmove ( V_53 , V_53 + 1 , ( type -> V_13 - ( V_12 + 2 ) ) * sizeof( * V_53 ) ) ;
type -> V_13 -- ;
}
}
static void T_1 F_38 ( struct V_1 * type ,
int V_54 , T_2 V_5 ,
T_2 V_6 , int V_20 )
{
struct V_36 * V_55 = & type -> V_15 [ V_54 ] ;
F_34 ( type -> V_13 >= type -> F_15 ) ;
memmove ( V_55 + 1 , V_55 , ( type -> V_13 - V_54 ) * sizeof( * V_55 ) ) ;
V_55 -> V_5 = V_5 ;
V_55 -> V_6 = V_6 ;
F_22 ( V_55 , V_20 ) ;
type -> V_13 ++ ;
type -> V_33 += V_6 ;
}
static int T_1 F_39 ( struct V_1 * type ,
T_2 V_5 , T_2 V_6 , int V_20 )
{
bool V_56 = false ;
T_2 V_57 = V_5 ;
T_2 V_18 = V_5 + F_2 ( V_5 , & V_6 ) ;
int V_12 , V_58 ;
if ( ! V_6 )
return 0 ;
if ( type -> V_15 [ 0 ] . V_6 == 0 ) {
F_21 ( type -> V_13 != 1 || type -> V_33 ) ;
type -> V_15 [ 0 ] . V_5 = V_5 ;
type -> V_15 [ 0 ] . V_6 = V_6 ;
F_22 ( & type -> V_15 [ 0 ] , V_20 ) ;
type -> V_33 = V_6 ;
return 0 ;
}
V_59:
V_5 = V_57 ;
V_58 = 0 ;
for ( V_12 = 0 ; V_12 < type -> V_13 ; V_12 ++ ) {
struct V_36 * V_55 = & type -> V_15 [ V_12 ] ;
T_2 V_60 = V_55 -> V_5 ;
T_2 V_61 = V_60 + V_55 -> V_6 ;
if ( V_60 >= V_18 )
break;
if ( V_61 <= V_5 )
continue;
if ( V_60 > V_5 ) {
V_58 ++ ;
if ( V_56 )
F_38 ( type , V_12 ++ , V_5 ,
V_60 - V_5 , V_20 ) ;
}
V_5 = F_3 ( V_61 , V_18 ) ;
}
if ( V_5 < V_18 ) {
V_58 ++ ;
if ( V_56 )
F_38 ( type , V_12 , V_5 , V_18 - V_5 , V_20 ) ;
}
if ( ! V_56 ) {
while ( type -> V_13 + V_58 > type -> F_15 )
if ( F_26 ( type , V_57 , V_6 ) < 0 )
return - V_62 ;
V_56 = true ;
goto V_59;
} else {
F_36 ( type ) ;
return 0 ;
}
}
int T_1 F_40 ( T_2 V_5 , T_2 V_6 ,
int V_20 )
{
return F_39 ( & V_2 . V_3 , V_5 , V_6 , V_20 ) ;
}
int T_1 F_41 ( T_2 V_5 , T_2 V_6 )
{
return F_39 ( & V_2 . V_3 , V_5 , V_6 , V_31 ) ;
}
static int T_1 F_42 ( struct V_1 * type ,
T_2 V_5 , T_2 V_6 ,
int * V_63 , int * V_64 )
{
T_2 V_18 = V_5 + F_2 ( V_5 , & V_6 ) ;
int V_12 ;
* V_63 = * V_64 = 0 ;
if ( ! V_6 )
return 0 ;
while ( type -> V_13 + 2 > type -> F_15 )
if ( F_26 ( type , V_5 , V_6 ) < 0 )
return - V_62 ;
for ( V_12 = 0 ; V_12 < type -> V_13 ; V_12 ++ ) {
struct V_36 * V_55 = & type -> V_15 [ V_12 ] ;
T_2 V_60 = V_55 -> V_5 ;
T_2 V_61 = V_60 + V_55 -> V_6 ;
if ( V_60 >= V_18 )
break;
if ( V_61 <= V_5 )
continue;
if ( V_60 < V_5 ) {
V_55 -> V_5 = V_5 ;
V_55 -> V_6 -= V_5 - V_60 ;
type -> V_33 -= V_5 - V_60 ;
F_38 ( type , V_12 , V_60 , V_5 - V_60 ,
F_37 ( V_55 ) ) ;
} else if ( V_61 > V_18 ) {
V_55 -> V_5 = V_18 ;
V_55 -> V_6 -= V_18 - V_60 ;
type -> V_33 -= V_18 - V_60 ;
F_38 ( type , V_12 -- , V_60 , V_18 - V_60 ,
F_37 ( V_55 ) ) ;
} else {
if ( ! * V_64 )
* V_63 = V_12 ;
* V_64 = V_12 + 1 ;
}
}
return 0 ;
}
static int T_1 F_43 ( struct V_1 * type ,
T_2 V_5 , T_2 V_6 )
{
int V_63 , V_64 ;
int V_12 , V_24 ;
V_24 = F_42 ( type , V_5 , V_6 , & V_63 , & V_64 ) ;
if ( V_24 )
return V_24 ;
for ( V_12 = V_64 - 1 ; V_12 >= V_63 ; V_12 -- )
F_20 ( type , V_12 ) ;
return 0 ;
}
int T_1 F_44 ( T_2 V_5 , T_2 V_6 )
{
return F_43 ( & V_2 . V_3 , V_5 , V_6 ) ;
}
int T_1 F_33 ( T_2 V_5 , T_2 V_6 )
{
F_31 ( L_8 ,
( unsigned long long ) V_5 ,
( unsigned long long ) V_5 + V_6 ,
( void * ) V_65 ) ;
return F_43 ( & V_2 . V_4 , V_5 , V_6 ) ;
}
int T_1 F_35 ( T_2 V_5 , T_2 V_6 )
{
struct V_1 * V_66 = & V_2 . V_4 ;
F_31 ( L_9 ,
( unsigned long long ) V_5 ,
( unsigned long long ) V_5 + V_6 ,
( void * ) V_65 ) ;
return F_39 ( V_66 , V_5 , V_6 , V_31 ) ;
}
void T_1 F_45 ( T_3 * V_54 , int V_20 ,
T_2 * V_67 ,
T_2 * V_68 , int * V_69 )
{
struct V_1 * V_70 = & V_2 . V_3 ;
struct V_1 * V_71 = & V_2 . V_4 ;
int V_72 = * V_54 & 0xffffffff ;
int V_73 = * V_54 >> 32 ;
for ( ; V_72 < V_70 -> V_13 ; V_72 ++ ) {
struct V_36 * V_74 = & V_70 -> V_15 [ V_72 ] ;
T_2 V_75 = V_74 -> V_5 ;
T_2 V_76 = V_74 -> V_5 + V_74 -> V_6 ;
if ( V_20 != V_31 && V_20 != F_37 ( V_74 ) )
continue;
for ( ; V_73 < V_71 -> V_13 + 1 ; V_73 ++ ) {
struct V_36 * V_32 = & V_71 -> V_15 [ V_73 ] ;
T_2 V_77 = V_73 ? V_32 [ - 1 ] . V_5 + V_32 [ - 1 ] . V_6 : 0 ;
T_2 V_78 = V_73 < V_71 -> V_13 ? V_32 -> V_5 : V_7 ;
if ( V_77 >= V_76 )
break;
if ( V_75 < V_78 ) {
if ( V_67 )
* V_67 = F_15 ( V_75 , V_77 ) ;
if ( V_68 )
* V_68 = F_3 ( V_76 , V_78 ) ;
if ( V_69 )
* V_69 = F_37 ( V_74 ) ;
if ( V_76 <= V_78 )
V_72 ++ ;
else
V_73 ++ ;
* V_54 = ( V_79 ) V_72 | ( T_3 ) V_73 << 32 ;
return;
}
}
}
* V_54 = V_7 ;
}
void T_1 F_46 ( T_3 * V_54 , int V_20 ,
T_2 * V_67 ,
T_2 * V_68 , int * V_69 )
{
struct V_1 * V_70 = & V_2 . V_3 ;
struct V_1 * V_71 = & V_2 . V_4 ;
int V_72 = * V_54 & 0xffffffff ;
int V_73 = * V_54 >> 32 ;
if ( * V_54 == ( T_3 ) V_7 ) {
V_72 = V_70 -> V_13 - 1 ;
V_73 = V_71 -> V_13 ;
}
for ( ; V_72 >= 0 ; V_72 -- ) {
struct V_36 * V_74 = & V_70 -> V_15 [ V_72 ] ;
T_2 V_75 = V_74 -> V_5 ;
T_2 V_76 = V_74 -> V_5 + V_74 -> V_6 ;
if ( V_20 != V_31 && V_20 != F_37 ( V_74 ) )
continue;
for ( ; V_73 >= 0 ; V_73 -- ) {
struct V_36 * V_32 = & V_71 -> V_15 [ V_73 ] ;
T_2 V_77 = V_73 ? V_32 [ - 1 ] . V_5 + V_32 [ - 1 ] . V_6 : 0 ;
T_2 V_78 = V_73 < V_71 -> V_13 ? V_32 -> V_5 : V_7 ;
if ( V_78 <= V_75 )
break;
if ( V_76 > V_77 ) {
if ( V_67 )
* V_67 = F_15 ( V_75 , V_77 ) ;
if ( V_68 )
* V_68 = F_3 ( V_76 , V_78 ) ;
if ( V_69 )
* V_69 = F_37 ( V_74 ) ;
if ( V_75 >= V_77 )
V_72 -- ;
else
V_73 -- ;
* V_54 = ( V_79 ) V_72 | ( T_3 ) V_73 << 32 ;
return;
}
}
}
* V_54 = V_7 ;
}
void T_1 F_47 ( int * V_54 , int V_20 ,
unsigned long * V_80 ,
unsigned long * V_81 , int * V_69 )
{
struct V_1 * type = & V_2 . V_3 ;
struct V_36 * V_32 ;
while ( ++ * V_54 < type -> V_13 ) {
V_32 = & type -> V_15 [ * V_54 ] ;
if ( F_48 ( V_32 -> V_5 ) >= F_49 ( V_32 -> V_5 + V_32 -> V_6 ) )
continue;
if ( V_20 == V_31 || V_20 == V_32 -> V_20 )
break;
}
if ( * V_54 >= type -> V_13 ) {
* V_54 = - 1 ;
return;
}
if ( V_80 )
* V_80 = F_48 ( V_32 -> V_5 ) ;
if ( V_81 )
* V_81 = F_49 ( V_32 -> V_5 + V_32 -> V_6 ) ;
if ( V_69 )
* V_69 = V_32 -> V_20 ;
}
int T_1 F_50 ( T_2 V_5 , T_2 V_6 ,
int V_20 )
{
struct V_1 * type = & V_2 . V_3 ;
int V_63 , V_64 ;
int V_12 , V_24 ;
V_24 = F_42 ( type , V_5 , V_6 , & V_63 , & V_64 ) ;
if ( V_24 )
return V_24 ;
for ( V_12 = V_63 ; V_12 < V_64 ; V_12 ++ )
F_22 ( & type -> V_15 [ V_12 ] , V_20 ) ;
F_36 ( type ) ;
return 0 ;
}
static T_2 T_4 F_51 ( T_2 V_6 ,
T_2 V_19 , T_2 V_82 ,
int V_20 )
{
T_2 V_83 ;
if ( F_21 ( ! V_19 ) )
V_19 = F_52 (long long) ;
V_6 = F_9 ( V_6 , V_19 ) ;
V_83 = F_13 ( 0 , V_82 , V_6 , V_19 , V_20 ) ;
if ( V_83 && ! F_35 ( V_83 , V_6 ) )
return V_83 ;
return 0 ;
}
T_2 T_4 F_53 ( T_2 V_6 , T_2 V_19 , int V_20 )
{
return F_51 ( V_6 , V_19 , V_26 , V_20 ) ;
}
T_2 T_4 F_54 ( T_2 V_6 , T_2 V_19 , T_2 V_82 )
{
return F_51 ( V_6 , V_19 , V_82 , V_31 ) ;
}
T_2 T_4 F_55 ( T_2 V_6 , T_2 V_19 , T_2 V_82 )
{
T_2 V_84 ;
V_84 = F_54 ( V_6 , V_19 , V_82 ) ;
if ( V_84 == 0 )
F_56 ( L_10 ,
( unsigned long long ) V_6 , ( unsigned long long ) V_82 ) ;
return V_84 ;
}
T_2 T_4 F_57 ( T_2 V_6 , T_2 V_19 )
{
return F_55 ( V_6 , V_19 , V_26 ) ;
}
T_2 T_4 F_58 ( T_2 V_6 , T_2 V_19 , int V_20 )
{
T_2 V_85 = F_53 ( V_6 , V_19 , V_20 ) ;
if ( V_85 )
return V_85 ;
return F_55 ( V_6 , V_19 , V_26 ) ;
}
T_2 T_4 F_59 ( void )
{
return V_2 . V_3 . V_33 ;
}
T_2 T_4 F_60 ( unsigned long V_86 )
{
unsigned long V_87 = 0 ;
struct V_36 * V_32 ;
unsigned long V_88 , V_89 ;
F_61 (memory, r) {
V_88 = F_62 ( V_32 ) ;
V_89 = F_63 ( V_32 ) ;
V_88 = F_64 (unsigned long, start_pfn, limit_pfn) ;
V_89 = F_64 (unsigned long, end_pfn, limit_pfn) ;
V_87 += V_89 - V_88 ;
}
return ( T_2 ) V_87 << V_90 ;
}
T_2 T_1 F_65 ( void )
{
return V_2 . V_3 . V_15 [ 0 ] . V_5 ;
}
T_2 T_1 F_66 ( void )
{
int V_54 = V_2 . V_3 . V_13 - 1 ;
return ( V_2 . V_3 . V_15 [ V_54 ] . V_5 + V_2 . V_3 . V_15 [ V_54 ] . V_6 ) ;
}
void T_4 F_67 ( T_2 V_91 )
{
unsigned long V_12 ;
T_2 V_82 = ( T_2 ) V_7 ;
if ( ! V_91 )
return;
for ( V_12 = 0 ; V_12 < V_2 . V_3 . V_13 ; V_12 ++ ) {
struct V_36 * V_32 = & V_2 . V_3 . V_15 [ V_12 ] ;
if ( V_91 <= V_32 -> V_6 ) {
V_82 = V_32 -> V_5 + V_91 ;
break;
}
V_91 -= V_32 -> V_6 ;
}
F_43 ( & V_2 . V_3 , V_82 , ( T_2 ) V_7 ) ;
F_43 ( & V_2 . V_4 , V_82 , ( T_2 ) V_7 ) ;
}
static int T_1 F_68 ( struct V_1 * type , T_2 V_34 )
{
unsigned int V_92 = 0 , V_93 = type -> V_13 ;
do {
unsigned int V_94 = ( V_93 + V_92 ) / 2 ;
if ( V_34 < type -> V_15 [ V_94 ] . V_5 )
V_93 = V_94 ;
else if ( V_34 >= ( type -> V_15 [ V_94 ] . V_5 +
type -> V_15 [ V_94 ] . V_6 ) )
V_92 = V_94 + 1 ;
else
return V_94 ;
} while ( V_92 < V_93 );
return - 1 ;
}
int T_4 F_69 ( T_2 V_34 )
{
return F_68 ( & V_2 . V_4 , V_34 ) != - 1 ;
}
int T_1 F_70 ( T_2 V_34 )
{
return F_68 ( & V_2 . V_3 , V_34 ) != - 1 ;
}
int T_1 F_71 ( unsigned long V_95 ,
unsigned long * V_88 , unsigned long * V_89 )
{
struct V_1 * type = & V_2 . V_3 ;
int V_94 = F_68 ( type , ( T_2 ) V_95 << V_90 ) ;
if ( V_94 == - 1 )
return - 1 ;
* V_88 = type -> V_15 [ V_94 ] . V_5 >> V_90 ;
* V_89 = ( type -> V_15 [ V_94 ] . V_5 + type -> V_15 [ V_94 ] . V_6 )
>> V_90 ;
return type -> V_15 [ V_94 ] . V_20 ;
}
int T_1 F_72 ( T_2 V_5 , T_2 V_6 )
{
int V_54 = F_68 ( & V_2 . V_3 , V_5 ) ;
T_2 V_18 = V_5 + F_2 ( V_5 , & V_6 ) ;
if ( V_54 == - 1 )
return 0 ;
return V_2 . V_3 . V_15 [ V_54 ] . V_5 <= V_5 &&
( V_2 . V_3 . V_15 [ V_54 ] . V_5 +
V_2 . V_3 . V_15 [ V_54 ] . V_6 ) >= V_18 ;
}
int T_1 F_73 ( T_2 V_5 , T_2 V_6 )
{
F_2 ( V_5 , & V_6 ) ;
return F_5 ( & V_2 . V_4 , V_5 , V_6 ) >= 0 ;
}
void T_1 F_74 ( T_2 V_19 )
{
int V_12 ;
T_2 V_17 , V_18 , V_96 , V_97 ;
struct V_1 * V_70 = & V_2 . V_3 ;
for ( V_12 = 0 ; V_12 < V_70 -> V_13 ; V_12 ++ ) {
V_96 = V_70 -> V_15 [ V_12 ] . V_5 ;
V_97 = V_70 -> V_15 [ V_12 ] . V_5 + V_70 -> V_15 [ V_12 ] . V_6 ;
V_17 = F_9 ( V_96 , V_19 ) ;
V_18 = F_12 ( V_97 , V_19 ) ;
if ( V_17 == V_96 && V_18 == V_97 )
continue;
if ( V_17 < V_18 ) {
V_70 -> V_15 [ V_12 ] . V_5 = V_17 ;
V_70 -> V_15 [ V_12 ] . V_6 = V_18 - V_17 ;
} else {
F_20 ( V_70 , V_12 ) ;
V_12 -- ;
}
}
}
void T_1 F_75 ( T_2 V_91 )
{
V_2 . V_27 = V_91 ;
}
static void T_1 F_76 ( struct V_1 * type , char * V_98 )
{
unsigned long long V_5 , V_6 ;
int V_12 ;
F_77 ( L_11 , V_98 , type -> V_13 ) ;
for ( V_12 = 0 ; V_12 < type -> V_13 ; V_12 ++ ) {
struct V_36 * V_55 = & type -> V_15 [ V_12 ] ;
char V_99 [ 32 ] = L_12 ;
V_5 = V_55 -> V_5 ;
V_6 = V_55 -> V_6 ;
#ifdef F_78
if ( F_37 ( V_55 ) != V_31 )
snprintf ( V_99 , sizeof( V_99 ) , L_13 ,
F_37 ( V_55 ) ) ;
#endif
F_77 ( L_14 ,
V_98 , V_12 , V_5 , V_5 + V_6 - 1 , V_6 , V_99 ) ;
}
}
void T_1 F_79 ( void )
{
F_77 ( L_15 ) ;
F_77 ( L_16 ,
( unsigned long long ) V_2 . V_3 . V_33 ,
( unsigned long long ) V_2 . V_4 . V_33 ) ;
F_76 ( & V_2 . V_3 , L_1 ) ;
F_76 ( & V_2 . V_4 , L_2 ) ;
}
void T_4 F_80 ( void )
{
V_47 = 1 ;
}
static int T_4 F_81 ( char * V_100 )
{
if ( V_100 && strstr ( V_100 , L_17 ) )
V_101 = 1 ;
return 0 ;
}
static int F_82 ( struct V_102 * V_74 , void * V_103 )
{
struct V_1 * type = V_74 -> V_103 ;
struct V_36 * V_104 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < type -> V_13 ; V_12 ++ ) {
V_104 = & type -> V_15 [ V_12 ] ;
F_83 ( V_74 , L_18 , V_12 ) ;
if ( sizeof( T_2 ) == 4 )
F_83 ( V_74 , L_19 ,
( unsigned long ) V_104 -> V_5 ,
( unsigned long ) ( V_104 -> V_5 + V_104 -> V_6 - 1 ) ) ;
else
F_83 ( V_74 , L_20 ,
( unsigned long long ) V_104 -> V_5 ,
( unsigned long long ) ( V_104 -> V_5 + V_104 -> V_6 - 1 ) ) ;
}
return 0 ;
}
static int F_84 ( struct V_105 * V_105 , struct V_106 * V_106 )
{
return F_85 ( V_106 , F_82 , V_105 -> V_107 ) ;
}
static int T_4 F_86 ( void )
{
struct V_108 * V_109 = F_87 ( L_21 , NULL ) ;
if ( ! V_109 )
return - V_110 ;
F_88 ( L_1 , V_111 , V_109 , & V_2 . V_3 , & V_112 ) ;
F_88 ( L_2 , V_111 , V_109 , & V_2 . V_4 , & V_112 ) ;
return 0 ;
}
