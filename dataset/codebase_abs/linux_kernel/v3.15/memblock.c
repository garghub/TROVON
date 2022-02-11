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
T_2 T_1 F_13 ( T_2 V_6 ,
T_2 V_19 , T_2 V_17 ,
T_2 V_18 , int V_20 )
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
return F_13 ( V_6 , V_19 , V_17 , V_18 ,
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
type -> V_15 [ 0 ] . V_34 = 0 ;
F_22 ( & type -> V_15 [ 0 ] , V_35 ) ;
}
}
T_2 T_1 F_23 (
T_2 * V_36 )
{
if ( V_2 . V_4 . V_15 == V_37 )
return 0 ;
* V_36 = F_24 ( V_2 . V_4 . V_15 ) ;
return F_25 ( sizeof( struct V_38 ) *
V_2 . V_4 . F_15 ) ;
}
T_2 T_1 F_26 (
T_2 * V_36 )
{
if ( V_2 . V_3 . V_15 == V_39 )
return 0 ;
* V_36 = F_24 ( V_2 . V_3 . V_15 ) ;
return F_25 ( sizeof( struct V_38 ) *
V_2 . V_3 . F_15 ) ;
}
static int T_1 F_27 ( struct V_1 * type ,
T_2 V_40 ,
T_2 V_41 )
{
struct V_38 * V_42 , * V_43 ;
T_2 V_44 , V_45 ;
T_2 V_46 , V_47 , V_36 ;
int V_48 = F_28 () ;
int * V_49 ;
if ( ! V_50 )
return - 1 ;
V_46 = type -> F_15 * sizeof( struct V_38 ) ;
V_47 = V_46 << 1 ;
V_44 = F_25 ( V_46 ) ;
V_45 = F_25 ( V_47 ) ;
if ( type == & V_2 . V_3 )
V_49 = & V_51 ;
else
V_49 = & V_52 ;
if ( V_48 ) {
V_42 = F_29 ( V_47 , V_53 ) ;
V_36 = V_42 ? F_24 ( V_42 ) : 0 ;
} else {
if ( type != & V_2 . V_4 )
V_40 = V_41 = 0 ;
V_36 = F_19 ( V_40 + V_41 ,
V_2 . V_27 ,
V_45 , V_28 ) ;
if ( ! V_36 && V_41 )
V_36 = F_19 ( 0 ,
F_3 ( V_40 , V_2 . V_27 ) ,
V_45 , V_28 ) ;
V_42 = V_36 ? F_30 ( V_36 ) : NULL ;
}
if ( ! V_36 ) {
F_31 ( L_6 ,
F_1 ( type ) , type -> F_15 , type -> F_15 * 2 ) ;
return - 1 ;
}
F_32 ( L_7 ,
F_1 ( type ) , type -> F_15 * 2 , ( T_3 ) V_36 ,
( T_3 ) V_36 + V_47 - 1 ) ;
memcpy ( V_42 , type -> V_15 , V_46 ) ;
memset ( V_42 + type -> F_15 , 0 , V_46 ) ;
V_43 = type -> V_15 ;
type -> V_15 = V_42 ;
type -> F_15 <<= 1 ;
if ( * V_49 )
F_33 ( V_43 ) ;
else if ( V_43 != V_39 &&
V_43 != V_37 )
F_34 ( F_24 ( V_43 ) , V_44 ) ;
if ( ! V_48 )
F_35 ( F_36 ( V_36 , V_45 ) ) ;
* V_49 = V_48 ;
return 0 ;
}
static void T_1 F_37 ( struct V_1 * type )
{
int V_12 = 0 ;
while ( V_12 < type -> V_13 - 1 ) {
struct V_38 * V_54 = & type -> V_15 [ V_12 ] ;
struct V_38 * V_55 = & type -> V_15 [ V_12 + 1 ] ;
if ( V_54 -> V_5 + V_54 -> V_6 != V_55 -> V_5 ||
F_38 ( V_54 ) !=
F_38 ( V_55 ) ||
V_54 -> V_34 != V_55 -> V_34 ) {
F_35 ( V_54 -> V_5 + V_54 -> V_6 > V_55 -> V_5 ) ;
V_12 ++ ;
continue;
}
V_54 -> V_6 += V_55 -> V_6 ;
memmove ( V_55 , V_55 + 1 , ( type -> V_13 - ( V_12 + 2 ) ) * sizeof( * V_55 ) ) ;
type -> V_13 -- ;
}
}
static void T_1 F_39 ( struct V_1 * type ,
int V_56 , T_2 V_5 ,
T_2 V_6 ,
int V_20 , unsigned long V_34 )
{
struct V_38 * V_57 = & type -> V_15 [ V_56 ] ;
F_35 ( type -> V_13 >= type -> F_15 ) ;
memmove ( V_57 + 1 , V_57 , ( type -> V_13 - V_56 ) * sizeof( * V_57 ) ) ;
V_57 -> V_5 = V_5 ;
V_57 -> V_6 = V_6 ;
V_57 -> V_34 = V_34 ;
F_22 ( V_57 , V_20 ) ;
type -> V_13 ++ ;
type -> V_33 += V_6 ;
}
static int T_1 F_40 ( struct V_1 * type ,
T_2 V_5 , T_2 V_6 ,
int V_20 , unsigned long V_34 )
{
bool V_58 = false ;
T_2 V_59 = V_5 ;
T_2 V_18 = V_5 + F_2 ( V_5 , & V_6 ) ;
int V_12 , V_60 ;
if ( ! V_6 )
return 0 ;
if ( type -> V_15 [ 0 ] . V_6 == 0 ) {
F_21 ( type -> V_13 != 1 || type -> V_33 ) ;
type -> V_15 [ 0 ] . V_5 = V_5 ;
type -> V_15 [ 0 ] . V_6 = V_6 ;
type -> V_15 [ 0 ] . V_34 = V_34 ;
F_22 ( & type -> V_15 [ 0 ] , V_20 ) ;
type -> V_33 = V_6 ;
return 0 ;
}
V_61:
V_5 = V_59 ;
V_60 = 0 ;
for ( V_12 = 0 ; V_12 < type -> V_13 ; V_12 ++ ) {
struct V_38 * V_57 = & type -> V_15 [ V_12 ] ;
T_2 V_62 = V_57 -> V_5 ;
T_2 V_63 = V_62 + V_57 -> V_6 ;
if ( V_62 >= V_18 )
break;
if ( V_63 <= V_5 )
continue;
if ( V_62 > V_5 ) {
V_60 ++ ;
if ( V_58 )
F_39 ( type , V_12 ++ , V_5 ,
V_62 - V_5 , V_20 ,
V_34 ) ;
}
V_5 = F_3 ( V_63 , V_18 ) ;
}
if ( V_5 < V_18 ) {
V_60 ++ ;
if ( V_58 )
F_39 ( type , V_12 , V_5 , V_18 - V_5 ,
V_20 , V_34 ) ;
}
if ( ! V_58 ) {
while ( type -> V_13 + V_60 > type -> F_15 )
if ( F_27 ( type , V_59 , V_6 ) < 0 )
return - V_64 ;
V_58 = true ;
goto V_61;
} else {
F_37 ( type ) ;
return 0 ;
}
}
int T_1 F_41 ( T_2 V_5 , T_2 V_6 ,
int V_20 )
{
return F_40 ( & V_2 . V_3 , V_5 , V_6 , V_20 , 0 ) ;
}
int T_1 F_42 ( T_2 V_5 , T_2 V_6 )
{
return F_40 ( & V_2 . V_3 , V_5 , V_6 ,
V_35 , 0 ) ;
}
static int T_1 F_43 ( struct V_1 * type ,
T_2 V_5 , T_2 V_6 ,
int * V_65 , int * V_66 )
{
T_2 V_18 = V_5 + F_2 ( V_5 , & V_6 ) ;
int V_12 ;
* V_65 = * V_66 = 0 ;
if ( ! V_6 )
return 0 ;
while ( type -> V_13 + 2 > type -> F_15 )
if ( F_27 ( type , V_5 , V_6 ) < 0 )
return - V_64 ;
for ( V_12 = 0 ; V_12 < type -> V_13 ; V_12 ++ ) {
struct V_38 * V_57 = & type -> V_15 [ V_12 ] ;
T_2 V_62 = V_57 -> V_5 ;
T_2 V_63 = V_62 + V_57 -> V_6 ;
if ( V_62 >= V_18 )
break;
if ( V_63 <= V_5 )
continue;
if ( V_62 < V_5 ) {
V_57 -> V_5 = V_5 ;
V_57 -> V_6 -= V_5 - V_62 ;
type -> V_33 -= V_5 - V_62 ;
F_39 ( type , V_12 , V_62 , V_5 - V_62 ,
F_38 ( V_57 ) ,
V_57 -> V_34 ) ;
} else if ( V_63 > V_18 ) {
V_57 -> V_5 = V_18 ;
V_57 -> V_6 -= V_18 - V_62 ;
type -> V_33 -= V_18 - V_62 ;
F_39 ( type , V_12 -- , V_62 , V_18 - V_62 ,
F_38 ( V_57 ) ,
V_57 -> V_34 ) ;
} else {
if ( ! * V_66 )
* V_65 = V_12 ;
* V_66 = V_12 + 1 ;
}
}
return 0 ;
}
static int T_1 F_44 ( struct V_1 * type ,
T_2 V_5 , T_2 V_6 )
{
int V_65 , V_66 ;
int V_12 , V_24 ;
V_24 = F_43 ( type , V_5 , V_6 , & V_65 , & V_66 ) ;
if ( V_24 )
return V_24 ;
for ( V_12 = V_66 - 1 ; V_12 >= V_65 ; V_12 -- )
F_20 ( type , V_12 ) ;
return 0 ;
}
int T_1 F_45 ( T_2 V_5 , T_2 V_6 )
{
return F_44 ( & V_2 . V_3 , V_5 , V_6 ) ;
}
int T_1 F_34 ( T_2 V_5 , T_2 V_6 )
{
F_32 ( L_8 ,
( unsigned long long ) V_5 ,
( unsigned long long ) V_5 + V_6 - 1 ,
( void * ) V_67 ) ;
return F_44 ( & V_2 . V_4 , V_5 , V_6 ) ;
}
static int T_1 F_46 ( T_2 V_5 ,
T_2 V_6 ,
int V_20 ,
unsigned long V_34 )
{
struct V_1 * V_68 = & V_2 . V_4 ;
F_32 ( L_9 ,
( unsigned long long ) V_5 ,
( unsigned long long ) V_5 + V_6 - 1 ,
V_34 , ( void * ) V_67 ) ;
return F_40 ( V_68 , V_5 , V_6 , V_20 , V_34 ) ;
}
int T_1 F_36 ( T_2 V_5 , T_2 V_6 )
{
return F_46 ( V_5 , V_6 , V_35 , 0 ) ;
}
int T_1 F_47 ( T_2 V_5 , T_2 V_6 )
{
struct V_1 * type = & V_2 . V_3 ;
int V_12 , V_24 , V_65 , V_66 ;
V_24 = F_43 ( type , V_5 , V_6 , & V_65 , & V_66 ) ;
if ( V_24 )
return V_24 ;
for ( V_12 = V_65 ; V_12 < V_66 ; V_12 ++ )
F_48 ( & type -> V_15 [ V_12 ] , V_69 ) ;
F_37 ( type ) ;
return 0 ;
}
int T_1 F_49 ( T_2 V_5 , T_2 V_6 )
{
struct V_1 * type = & V_2 . V_3 ;
int V_12 , V_24 , V_65 , V_66 ;
V_24 = F_43 ( type , V_5 , V_6 , & V_65 , & V_66 ) ;
if ( V_24 )
return V_24 ;
for ( V_12 = V_65 ; V_12 < V_66 ; V_12 ++ )
F_50 ( & type -> V_15 [ V_12 ] ,
V_69 ) ;
F_37 ( type ) ;
return 0 ;
}
void T_1 F_51 ( T_3 * V_56 , int V_20 ,
T_2 * V_70 ,
T_2 * V_71 , int * V_72 )
{
struct V_1 * V_73 = & V_2 . V_3 ;
struct V_1 * V_74 = & V_2 . V_4 ;
int V_75 = * V_56 & 0xffffffff ;
int V_76 = * V_56 >> 32 ;
if ( F_18 ( V_20 == V_35 , L_10 ) )
V_20 = V_31 ;
for ( ; V_75 < V_73 -> V_13 ; V_75 ++ ) {
struct V_38 * V_77 = & V_73 -> V_15 [ V_75 ] ;
T_2 V_78 = V_77 -> V_5 ;
T_2 V_79 = V_77 -> V_5 + V_77 -> V_6 ;
if ( V_20 != V_31 && V_20 != F_38 ( V_77 ) )
continue;
for ( ; V_76 < V_74 -> V_13 + 1 ; V_76 ++ ) {
struct V_38 * V_32 = & V_74 -> V_15 [ V_76 ] ;
T_2 V_80 = V_76 ? V_32 [ - 1 ] . V_5 + V_32 [ - 1 ] . V_6 : 0 ;
T_2 V_81 = V_76 < V_74 -> V_13 ? V_32 -> V_5 : V_7 ;
if ( V_80 >= V_79 )
break;
if ( V_78 < V_81 ) {
if ( V_70 )
* V_70 = F_15 ( V_78 , V_80 ) ;
if ( V_71 )
* V_71 = F_3 ( V_79 , V_81 ) ;
if ( V_72 )
* V_72 = F_38 ( V_77 ) ;
if ( V_79 <= V_81 )
V_75 ++ ;
else
V_76 ++ ;
* V_56 = ( V_82 ) V_75 | ( T_3 ) V_76 << 32 ;
return;
}
}
}
* V_56 = V_7 ;
}
void T_1 F_52 ( T_3 * V_56 , int V_20 ,
T_2 * V_70 ,
T_2 * V_71 , int * V_72 )
{
struct V_1 * V_73 = & V_2 . V_3 ;
struct V_1 * V_74 = & V_2 . V_4 ;
int V_75 = * V_56 & 0xffffffff ;
int V_76 = * V_56 >> 32 ;
if ( F_18 ( V_20 == V_35 , L_10 ) )
V_20 = V_31 ;
if ( * V_56 == ( T_3 ) V_7 ) {
V_75 = V_73 -> V_13 - 1 ;
V_76 = V_74 -> V_13 ;
}
for ( ; V_75 >= 0 ; V_75 -- ) {
struct V_38 * V_77 = & V_73 -> V_15 [ V_75 ] ;
T_2 V_78 = V_77 -> V_5 ;
T_2 V_79 = V_77 -> V_5 + V_77 -> V_6 ;
if ( V_20 != V_31 && V_20 != F_38 ( V_77 ) )
continue;
if ( F_53 () && F_54 ( V_77 ) )
continue;
for ( ; V_76 >= 0 ; V_76 -- ) {
struct V_38 * V_32 = & V_74 -> V_15 [ V_76 ] ;
T_2 V_80 = V_76 ? V_32 [ - 1 ] . V_5 + V_32 [ - 1 ] . V_6 : 0 ;
T_2 V_81 = V_76 < V_74 -> V_13 ? V_32 -> V_5 : V_7 ;
if ( V_81 <= V_78 )
break;
if ( V_79 > V_80 ) {
if ( V_70 )
* V_70 = F_15 ( V_78 , V_80 ) ;
if ( V_71 )
* V_71 = F_3 ( V_79 , V_81 ) ;
if ( V_72 )
* V_72 = F_38 ( V_77 ) ;
if ( V_78 >= V_80 )
V_75 -- ;
else
V_76 -- ;
* V_56 = ( V_82 ) V_75 | ( T_3 ) V_76 << 32 ;
return;
}
}
}
* V_56 = V_7 ;
}
void T_1 F_55 ( int * V_56 , int V_20 ,
unsigned long * V_83 ,
unsigned long * V_84 , int * V_72 )
{
struct V_1 * type = & V_2 . V_3 ;
struct V_38 * V_32 ;
while ( ++ * V_56 < type -> V_13 ) {
V_32 = & type -> V_15 [ * V_56 ] ;
if ( F_56 ( V_32 -> V_5 ) >= F_57 ( V_32 -> V_5 + V_32 -> V_6 ) )
continue;
if ( V_20 == V_35 || V_20 == V_32 -> V_20 )
break;
}
if ( * V_56 >= type -> V_13 ) {
* V_56 = - 1 ;
return;
}
if ( V_83 )
* V_83 = F_56 ( V_32 -> V_5 ) ;
if ( V_84 )
* V_84 = F_57 ( V_32 -> V_5 + V_32 -> V_6 ) ;
if ( V_72 )
* V_72 = V_32 -> V_20 ;
}
int T_1 F_58 ( T_2 V_5 , T_2 V_6 ,
struct V_1 * type , int V_20 )
{
int V_65 , V_66 ;
int V_12 , V_24 ;
V_24 = F_43 ( type , V_5 , V_6 , & V_65 , & V_66 ) ;
if ( V_24 )
return V_24 ;
for ( V_12 = V_65 ; V_12 < V_66 ; V_12 ++ )
F_22 ( & type -> V_15 [ V_12 ] , V_20 ) ;
F_37 ( type ) ;
return 0 ;
}
static T_2 T_4 F_59 ( T_2 V_6 ,
T_2 V_19 , T_2 V_85 ,
int V_20 )
{
T_2 V_86 ;
if ( ! V_19 )
V_19 = V_87 ;
V_86 = F_13 ( V_6 , V_19 , 0 , V_85 , V_20 ) ;
if ( V_86 && ! F_36 ( V_86 , V_6 ) )
return V_86 ;
return 0 ;
}
T_2 T_4 F_60 ( T_2 V_6 , T_2 V_19 , int V_20 )
{
return F_59 ( V_6 , V_19 , V_26 , V_20 ) ;
}
T_2 T_4 F_61 ( T_2 V_6 , T_2 V_19 , T_2 V_85 )
{
return F_59 ( V_6 , V_19 , V_85 , V_31 ) ;
}
T_2 T_4 F_62 ( T_2 V_6 , T_2 V_19 , T_2 V_85 )
{
T_2 V_88 ;
V_88 = F_61 ( V_6 , V_19 , V_85 ) ;
if ( V_88 == 0 )
F_63 ( L_11 ,
( unsigned long long ) V_6 , ( unsigned long long ) V_85 ) ;
return V_88 ;
}
T_2 T_4 F_64 ( T_2 V_6 , T_2 V_19 )
{
return F_62 ( V_6 , V_19 , V_26 ) ;
}
T_2 T_4 F_65 ( T_2 V_6 , T_2 V_19 , int V_20 )
{
T_2 V_89 = F_60 ( V_6 , V_19 , V_20 ) ;
if ( V_89 )
return V_89 ;
return F_62 ( V_6 , V_19 , V_26 ) ;
}
static void * T_4 F_66 (
T_2 V_6 , T_2 V_19 ,
T_2 V_90 , T_2 V_85 ,
int V_20 )
{
T_2 V_88 ;
void * V_91 ;
if ( F_18 ( V_20 == V_35 , L_10 ) )
V_20 = V_31 ;
if ( F_67 ( F_28 () ) )
return F_68 ( V_6 , V_92 , V_20 ) ;
if ( ! V_19 )
V_19 = V_87 ;
if ( V_85 > V_2 . V_27 )
V_85 = V_2 . V_27 ;
V_93:
V_88 = F_13 ( V_6 , V_19 , V_90 , V_85 ,
V_20 ) ;
if ( V_88 )
goto V_94;
if ( V_20 != V_31 ) {
V_88 = F_13 ( V_6 , V_19 , V_90 ,
V_85 , V_31 ) ;
if ( V_88 )
goto V_94;
}
if ( V_90 ) {
V_90 = 0 ;
goto V_93;
} else {
goto error;
}
V_94:
F_36 ( V_88 , V_6 ) ;
V_91 = F_69 ( V_88 ) ;
memset ( V_91 , 0 , V_6 ) ;
F_70 ( V_91 , V_6 , 0 , 0 ) ;
return V_91 ;
error:
return NULL ;
}
void * T_4 F_71 (
T_2 V_6 , T_2 V_19 ,
T_2 V_90 , T_2 V_85 ,
int V_20 )
{
F_32 ( L_12 ,
V_95 , ( T_3 ) V_6 , ( T_3 ) V_19 , V_20 , ( T_3 ) V_90 ,
( T_3 ) V_85 , ( void * ) V_67 ) ;
return F_66 ( V_6 , V_19 , V_90 ,
V_85 , V_20 ) ;
}
void * T_4 F_72 (
T_2 V_6 , T_2 V_19 ,
T_2 V_90 , T_2 V_85 ,
int V_20 )
{
void * V_91 ;
F_32 ( L_12 ,
V_95 , ( T_3 ) V_6 , ( T_3 ) V_19 , V_20 , ( T_3 ) V_90 ,
( T_3 ) V_85 , ( void * ) V_67 ) ;
V_91 = F_66 ( V_6 , V_19 ,
V_90 , V_85 , V_20 ) ;
if ( V_91 )
return V_91 ;
F_63 ( L_13 ,
V_95 , ( T_3 ) V_6 , ( T_3 ) V_19 , V_20 , ( T_3 ) V_90 ,
( T_3 ) V_85 ) ;
return NULL ;
}
void T_4 F_73 ( T_2 V_5 , T_2 V_6 )
{
F_32 ( L_14 ,
V_95 , ( T_3 ) V_5 , ( T_3 ) V_5 + V_6 - 1 ,
( void * ) V_67 ) ;
F_74 ( F_30 ( V_5 ) , V_6 ) ;
F_44 ( & V_2 . V_4 , V_5 , V_6 ) ;
}
void T_4 F_75 ( T_2 V_5 , T_2 V_6 )
{
T_3 V_96 , V_18 ;
F_32 ( L_14 ,
V_95 , ( T_3 ) V_5 , ( T_3 ) V_5 + V_6 - 1 ,
( void * ) V_67 ) ;
F_74 ( F_30 ( V_5 ) , V_6 ) ;
V_96 = F_56 ( V_5 ) ;
V_18 = F_57 ( V_5 + V_6 ) ;
for (; V_96 < V_18 ; V_96 ++ ) {
F_76 ( F_77 ( V_96 ) , 0 ) ;
V_97 ++ ;
}
}
T_2 T_4 F_78 ( void )
{
return V_2 . V_3 . V_33 ;
}
T_2 T_4 F_79 ( unsigned long V_98 )
{
unsigned long V_99 = 0 ;
struct V_38 * V_32 ;
unsigned long V_100 , V_101 ;
F_80 (memory, r) {
V_100 = F_81 ( V_32 ) ;
V_101 = F_82 ( V_32 ) ;
V_100 = F_83 (unsigned long, start_pfn, limit_pfn) ;
V_101 = F_83 (unsigned long, end_pfn, limit_pfn) ;
V_99 += V_101 - V_100 ;
}
return F_84 ( V_99 ) ;
}
T_2 T_1 F_85 ( void )
{
return V_2 . V_3 . V_15 [ 0 ] . V_5 ;
}
T_2 T_1 F_86 ( void )
{
int V_56 = V_2 . V_3 . V_13 - 1 ;
return ( V_2 . V_3 . V_15 [ V_56 ] . V_5 + V_2 . V_3 . V_15 [ V_56 ] . V_6 ) ;
}
void T_4 F_87 ( T_2 V_102 )
{
T_2 V_85 = ( T_2 ) V_7 ;
struct V_38 * V_32 ;
if ( ! V_102 )
return;
F_80 (memory, r) {
if ( V_102 <= V_32 -> V_6 ) {
V_85 = V_32 -> V_5 + V_102 ;
break;
}
V_102 -= V_32 -> V_6 ;
}
F_44 ( & V_2 . V_3 , V_85 , ( T_2 ) V_7 ) ;
F_44 ( & V_2 . V_4 , V_85 , ( T_2 ) V_7 ) ;
}
static int T_1 F_88 ( struct V_1 * type , T_2 V_36 )
{
unsigned int V_103 = 0 , V_104 = type -> V_13 ;
do {
unsigned int V_105 = ( V_104 + V_103 ) / 2 ;
if ( V_36 < type -> V_15 [ V_105 ] . V_5 )
V_104 = V_105 ;
else if ( V_36 >= ( type -> V_15 [ V_105 ] . V_5 +
type -> V_15 [ V_105 ] . V_6 ) )
V_103 = V_105 + 1 ;
else
return V_105 ;
} while ( V_103 < V_104 );
return - 1 ;
}
int T_4 F_89 ( T_2 V_36 )
{
return F_88 ( & V_2 . V_4 , V_36 ) != - 1 ;
}
int T_1 F_90 ( T_2 V_36 )
{
return F_88 ( & V_2 . V_3 , V_36 ) != - 1 ;
}
int T_1 F_91 ( unsigned long V_106 ,
unsigned long * V_100 , unsigned long * V_101 )
{
struct V_1 * type = & V_2 . V_3 ;
int V_105 = F_88 ( type , F_84 ( V_106 ) ) ;
if ( V_105 == - 1 )
return - 1 ;
* V_100 = type -> V_15 [ V_105 ] . V_5 >> V_107 ;
* V_101 = ( type -> V_15 [ V_105 ] . V_5 + type -> V_15 [ V_105 ] . V_6 )
>> V_107 ;
return type -> V_15 [ V_105 ] . V_20 ;
}
int T_1 F_92 ( T_2 V_5 , T_2 V_6 )
{
int V_56 = F_88 ( & V_2 . V_3 , V_5 ) ;
T_2 V_18 = V_5 + F_2 ( V_5 , & V_6 ) ;
if ( V_56 == - 1 )
return 0 ;
return V_2 . V_3 . V_15 [ V_56 ] . V_5 <= V_5 &&
( V_2 . V_3 . V_15 [ V_56 ] . V_5 +
V_2 . V_3 . V_15 [ V_56 ] . V_6 ) >= V_18 ;
}
int T_1 F_93 ( T_2 V_5 , T_2 V_6 )
{
F_2 ( V_5 , & V_6 ) ;
return F_5 ( & V_2 . V_4 , V_5 , V_6 ) >= 0 ;
}
void T_1 F_94 ( T_2 V_19 )
{
T_2 V_17 , V_18 , V_108 , V_109 ;
struct V_38 * V_32 ;
F_80 (memory, r) {
V_108 = V_32 -> V_5 ;
V_109 = V_32 -> V_5 + V_32 -> V_6 ;
V_17 = F_9 ( V_108 , V_19 ) ;
V_18 = F_12 ( V_109 , V_19 ) ;
if ( V_17 == V_108 && V_18 == V_109 )
continue;
if ( V_17 < V_18 ) {
V_32 -> V_5 = V_17 ;
V_32 -> V_6 = V_18 - V_17 ;
} else {
F_20 ( & V_2 . V_3 ,
V_32 - V_2 . V_3 . V_15 ) ;
V_32 -- ;
}
}
}
void T_1 F_95 ( T_2 V_102 )
{
V_2 . V_27 = V_102 ;
}
T_2 T_1 F_96 ( void )
{
return V_2 . V_27 ;
}
static void T_1 F_97 ( struct V_1 * type , char * V_110 )
{
unsigned long long V_5 , V_6 ;
unsigned long V_34 ;
int V_12 ;
F_98 ( L_15 , V_110 , type -> V_13 ) ;
for ( V_12 = 0 ; V_12 < type -> V_13 ; V_12 ++ ) {
struct V_38 * V_57 = & type -> V_15 [ V_12 ] ;
char V_111 [ 32 ] = L_16 ;
V_5 = V_57 -> V_5 ;
V_6 = V_57 -> V_6 ;
V_34 = V_57 -> V_34 ;
#ifdef F_99
if ( F_38 ( V_57 ) != V_35 )
snprintf ( V_111 , sizeof( V_111 ) , L_17 ,
F_38 ( V_57 ) ) ;
#endif
F_98 ( L_18 ,
V_110 , V_12 , V_5 , V_5 + V_6 - 1 , V_6 , V_111 , V_34 ) ;
}
}
void T_1 F_100 ( void )
{
F_98 ( L_19 ) ;
F_98 ( L_20 ,
( unsigned long long ) V_2 . V_3 . V_33 ,
( unsigned long long ) V_2 . V_4 . V_33 ) ;
F_97 ( & V_2 . V_3 , L_1 ) ;
F_97 ( & V_2 . V_4 , L_2 ) ;
}
void T_4 F_101 ( void )
{
V_50 = 1 ;
}
static int T_4 F_102 ( char * V_112 )
{
if ( V_112 && strstr ( V_112 , L_21 ) )
V_113 = 1 ;
return 0 ;
}
static int F_103 ( struct V_114 * V_77 , void * V_115 )
{
struct V_1 * type = V_77 -> V_115 ;
struct V_38 * V_116 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < type -> V_13 ; V_12 ++ ) {
V_116 = & type -> V_15 [ V_12 ] ;
F_104 ( V_77 , L_22 , V_12 ) ;
if ( sizeof( T_2 ) == 4 )
F_104 ( V_77 , L_23 ,
( unsigned long ) V_116 -> V_5 ,
( unsigned long ) ( V_116 -> V_5 + V_116 -> V_6 - 1 ) ) ;
else
F_104 ( V_77 , L_24 ,
( unsigned long long ) V_116 -> V_5 ,
( unsigned long long ) ( V_116 -> V_5 + V_116 -> V_6 - 1 ) ) ;
}
return 0 ;
}
static int F_105 ( struct V_117 * V_117 , struct V_118 * V_118 )
{
return F_106 ( V_118 , F_103 , V_117 -> V_119 ) ;
}
static int T_4 F_107 ( void )
{
struct V_120 * V_121 = F_108 ( L_25 , NULL ) ;
if ( ! V_121 )
return - V_122 ;
F_109 ( L_1 , V_123 , V_121 , & V_2 . V_3 , & V_124 ) ;
F_109 ( L_2 , V_123 , V_121 , & V_2 . V_4 , & V_124 ) ;
return 0 ;
}
