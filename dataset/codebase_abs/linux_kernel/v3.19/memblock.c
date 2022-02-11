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
T_2 V_24 , V_25 ;
if ( V_18 == V_26 )
V_18 = V_2 . V_27 ;
V_17 = F_14 ( T_2 , V_17 , V_28 ) ;
V_18 = F_15 ( V_17 , V_18 ) ;
V_24 = F_16 ( V_29 ) ;
if ( F_17 () && V_18 > V_24 ) {
T_2 V_30 ;
V_30 = F_15 ( V_17 , V_24 ) ;
V_25 = F_6 ( V_30 , V_18 ,
V_6 , V_19 , V_20 ) ;
if ( V_25 )
return V_25 ;
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
int T_1 F_40 ( struct V_1 * type ,
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
int T_1 F_44 ( struct V_1 * type ,
T_2 V_5 , T_2 V_6 )
{
int V_65 , V_66 ;
int V_12 , V_25 ;
V_25 = F_43 ( type , V_5 , V_6 , & V_65 , & V_66 ) ;
if ( V_25 )
return V_25 ;
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
F_46 ( F_30 ( V_5 ) , V_6 ) ;
return F_44 ( & V_2 . V_4 , V_5 , V_6 ) ;
}
static int T_1 F_47 ( T_2 V_5 ,
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
return F_47 ( V_5 , V_6 , V_35 , 0 ) ;
}
static int T_1 F_48 ( T_2 V_5 ,
T_2 V_6 , int V_69 , int V_70 )
{
struct V_1 * type = & V_2 . V_3 ;
int V_12 , V_25 , V_65 , V_66 ;
V_25 = F_43 ( type , V_5 , V_6 , & V_65 , & V_66 ) ;
if ( V_25 )
return V_25 ;
for ( V_12 = V_65 ; V_12 < V_66 ; V_12 ++ )
if ( V_69 )
F_49 ( & type -> V_15 [ V_12 ] , V_70 ) ;
else
F_50 ( & type -> V_15 [ V_12 ] , V_70 ) ;
F_37 ( type ) ;
return 0 ;
}
int T_1 F_51 ( T_2 V_5 , T_2 V_6 )
{
return F_48 ( V_5 , V_6 , 1 , V_71 ) ;
}
int T_1 F_52 ( T_2 V_5 , T_2 V_6 )
{
return F_48 ( V_5 , V_6 , 0 , V_71 ) ;
}
void T_1 F_53 ( T_3 * V_56 , int V_20 ,
struct V_1 * V_72 ,
struct V_1 * V_73 ,
T_2 * V_74 ,
T_2 * V_75 , int * V_76 )
{
int V_77 = * V_56 & 0xffffffff ;
int V_78 = * V_56 >> 32 ;
if ( F_18 ( V_20 == V_35 ,
L_10 ) )
V_20 = V_31 ;
for (; V_77 < V_72 -> V_13 ; V_77 ++ ) {
struct V_38 * V_79 = & V_72 -> V_15 [ V_77 ] ;
T_2 V_80 = V_79 -> V_5 ;
T_2 V_81 = V_79 -> V_5 + V_79 -> V_6 ;
int V_82 = F_38 ( V_79 ) ;
if ( V_20 != V_31 && V_20 != V_82 )
continue;
if ( F_54 () && F_55 ( V_79 ) )
continue;
if ( ! V_73 ) {
if ( V_74 )
* V_74 = V_80 ;
if ( V_75 )
* V_75 = V_81 ;
if ( V_76 )
* V_76 = V_82 ;
V_77 ++ ;
* V_56 = ( V_83 ) V_77 | ( T_3 ) V_78 << 32 ;
return;
}
for (; V_78 < V_73 -> V_13 + 1 ; V_78 ++ ) {
struct V_38 * V_32 ;
T_2 V_84 ;
T_2 V_85 ;
V_32 = & V_73 -> V_15 [ V_78 ] ;
V_84 = V_78 ? V_32 [ - 1 ] . V_5 + V_32 [ - 1 ] . V_6 : 0 ;
V_85 = V_78 < V_73 -> V_13 ?
V_32 -> V_5 : V_7 ;
if ( V_84 >= V_81 )
break;
if ( V_80 < V_85 ) {
if ( V_74 )
* V_74 =
F_15 ( V_80 , V_84 ) ;
if ( V_75 )
* V_75 = F_3 ( V_81 , V_85 ) ;
if ( V_76 )
* V_76 = V_82 ;
if ( V_81 <= V_85 )
V_77 ++ ;
else
V_78 ++ ;
* V_56 = ( V_83 ) V_77 | ( T_3 ) V_78 << 32 ;
return;
}
}
}
* V_56 = V_7 ;
}
void T_1 F_56 ( T_3 * V_56 , int V_20 ,
struct V_1 * V_72 ,
struct V_1 * V_73 ,
T_2 * V_74 ,
T_2 * V_75 , int * V_76 )
{
int V_77 = * V_56 & 0xffffffff ;
int V_78 = * V_56 >> 32 ;
if ( F_18 ( V_20 == V_35 , L_10 ) )
V_20 = V_31 ;
if ( * V_56 == ( T_3 ) V_7 ) {
V_77 = V_72 -> V_13 - 1 ;
V_78 = V_73 -> V_13 ;
}
for (; V_77 >= 0 ; V_77 -- ) {
struct V_38 * V_79 = & V_72 -> V_15 [ V_77 ] ;
T_2 V_80 = V_79 -> V_5 ;
T_2 V_81 = V_79 -> V_5 + V_79 -> V_6 ;
int V_82 = F_38 ( V_79 ) ;
if ( V_20 != V_31 && V_20 != V_82 )
continue;
if ( F_54 () && F_55 ( V_79 ) )
continue;
if ( ! V_73 ) {
if ( V_74 )
* V_74 = V_80 ;
if ( V_75 )
* V_75 = V_81 ;
if ( V_76 )
* V_76 = V_82 ;
V_77 ++ ;
* V_56 = ( V_83 ) V_77 | ( T_3 ) V_78 << 32 ;
return;
}
for (; V_78 >= 0 ; V_78 -- ) {
struct V_38 * V_32 ;
T_2 V_84 ;
T_2 V_85 ;
V_32 = & V_73 -> V_15 [ V_78 ] ;
V_84 = V_78 ? V_32 [ - 1 ] . V_5 + V_32 [ - 1 ] . V_6 : 0 ;
V_85 = V_78 < V_73 -> V_13 ?
V_32 -> V_5 : V_7 ;
if ( V_85 <= V_80 )
break;
if ( V_81 > V_84 ) {
if ( V_74 )
* V_74 = F_15 ( V_80 , V_84 ) ;
if ( V_75 )
* V_75 = F_3 ( V_81 , V_85 ) ;
if ( V_76 )
* V_76 = V_82 ;
if ( V_80 >= V_84 )
V_77 -- ;
else
V_78 -- ;
* V_56 = ( V_83 ) V_77 | ( T_3 ) V_78 << 32 ;
return;
}
}
}
* V_56 = V_7 ;
}
void T_1 F_57 ( int * V_56 , int V_20 ,
unsigned long * V_86 ,
unsigned long * V_87 , int * V_76 )
{
struct V_1 * type = & V_2 . V_3 ;
struct V_38 * V_32 ;
while ( ++ * V_56 < type -> V_13 ) {
V_32 = & type -> V_15 [ * V_56 ] ;
if ( F_58 ( V_32 -> V_5 ) >= F_59 ( V_32 -> V_5 + V_32 -> V_6 ) )
continue;
if ( V_20 == V_35 || V_20 == V_32 -> V_20 )
break;
}
if ( * V_56 >= type -> V_13 ) {
* V_56 = - 1 ;
return;
}
if ( V_86 )
* V_86 = F_58 ( V_32 -> V_5 ) ;
if ( V_87 )
* V_87 = F_59 ( V_32 -> V_5 + V_32 -> V_6 ) ;
if ( V_76 )
* V_76 = V_32 -> V_20 ;
}
int T_1 F_60 ( T_2 V_5 , T_2 V_6 ,
struct V_1 * type , int V_20 )
{
int V_65 , V_66 ;
int V_12 , V_25 ;
V_25 = F_43 ( type , V_5 , V_6 , & V_65 , & V_66 ) ;
if ( V_25 )
return V_25 ;
for ( V_12 = V_65 ; V_12 < V_66 ; V_12 ++ )
F_22 ( & type -> V_15 [ V_12 ] , V_20 ) ;
F_37 ( type ) ;
return 0 ;
}
static T_2 T_4 F_61 ( T_2 V_6 ,
T_2 V_19 , T_2 V_17 ,
T_2 V_18 , int V_20 )
{
T_2 V_88 ;
if ( ! V_19 )
V_19 = V_89 ;
V_88 = F_13 ( V_6 , V_19 , V_17 , V_18 , V_20 ) ;
if ( V_88 && ! F_36 ( V_88 , V_6 ) ) {
F_62 ( F_30 ( V_88 ) , V_6 , 0 , 0 ) ;
return V_88 ;
}
return 0 ;
}
T_2 T_4 F_63 ( T_2 V_6 , T_2 V_19 ,
T_2 V_17 , T_2 V_18 )
{
return F_61 ( V_6 , V_19 , V_17 , V_18 , V_31 ) ;
}
static T_2 T_4 F_64 ( T_2 V_6 ,
T_2 V_19 , T_2 V_90 ,
int V_20 )
{
return F_61 ( V_6 , V_19 , 0 , V_90 , V_20 ) ;
}
T_2 T_4 F_65 ( T_2 V_6 , T_2 V_19 , int V_20 )
{
return F_64 ( V_6 , V_19 , V_26 , V_20 ) ;
}
T_2 T_4 F_66 ( T_2 V_6 , T_2 V_19 , T_2 V_90 )
{
return F_64 ( V_6 , V_19 , V_90 , V_31 ) ;
}
T_2 T_4 F_67 ( T_2 V_6 , T_2 V_19 , T_2 V_90 )
{
T_2 V_91 ;
V_91 = F_66 ( V_6 , V_19 , V_90 ) ;
if ( V_91 == 0 )
F_68 ( L_11 ,
( unsigned long long ) V_6 , ( unsigned long long ) V_90 ) ;
return V_91 ;
}
T_2 T_4 F_69 ( T_2 V_6 , T_2 V_19 )
{
return F_67 ( V_6 , V_19 , V_26 ) ;
}
T_2 T_4 F_70 ( T_2 V_6 , T_2 V_19 , int V_20 )
{
T_2 V_92 = F_65 ( V_6 , V_19 , V_20 ) ;
if ( V_92 )
return V_92 ;
return F_67 ( V_6 , V_19 , V_26 ) ;
}
static void * T_4 F_71 (
T_2 V_6 , T_2 V_19 ,
T_2 V_93 , T_2 V_90 ,
int V_20 )
{
T_2 V_91 ;
void * V_94 ;
if ( F_18 ( V_20 == V_35 , L_10 ) )
V_20 = V_31 ;
if ( F_72 ( F_28 () ) )
return F_73 ( V_6 , V_95 , V_20 ) ;
if ( ! V_19 )
V_19 = V_89 ;
if ( V_90 > V_2 . V_27 )
V_90 = V_2 . V_27 ;
V_96:
V_91 = F_13 ( V_6 , V_19 , V_93 , V_90 ,
V_20 ) ;
if ( V_91 )
goto V_97;
if ( V_20 != V_31 ) {
V_91 = F_13 ( V_6 , V_19 , V_93 ,
V_90 , V_31 ) ;
if ( V_91 )
goto V_97;
}
if ( V_93 ) {
V_93 = 0 ;
goto V_96;
} else {
goto error;
}
V_97:
F_36 ( V_91 , V_6 ) ;
V_94 = F_74 ( V_91 ) ;
memset ( V_94 , 0 , V_6 ) ;
F_62 ( V_94 , V_6 , 0 , 0 ) ;
return V_94 ;
error:
return NULL ;
}
void * T_4 F_75 (
T_2 V_6 , T_2 V_19 ,
T_2 V_93 , T_2 V_90 ,
int V_20 )
{
F_32 ( L_12 ,
V_98 , ( T_3 ) V_6 , ( T_3 ) V_19 , V_20 , ( T_3 ) V_93 ,
( T_3 ) V_90 , ( void * ) V_67 ) ;
return F_71 ( V_6 , V_19 , V_93 ,
V_90 , V_20 ) ;
}
void * T_4 F_76 (
T_2 V_6 , T_2 V_19 ,
T_2 V_93 , T_2 V_90 ,
int V_20 )
{
void * V_94 ;
F_32 ( L_12 ,
V_98 , ( T_3 ) V_6 , ( T_3 ) V_19 , V_20 , ( T_3 ) V_93 ,
( T_3 ) V_90 , ( void * ) V_67 ) ;
V_94 = F_71 ( V_6 , V_19 ,
V_93 , V_90 , V_20 ) ;
if ( V_94 )
return V_94 ;
F_68 ( L_13 ,
V_98 , ( T_3 ) V_6 , ( T_3 ) V_19 , V_20 , ( T_3 ) V_93 ,
( T_3 ) V_90 ) ;
return NULL ;
}
void T_4 F_77 ( T_2 V_5 , T_2 V_6 )
{
F_32 ( L_14 ,
V_98 , ( T_3 ) V_5 , ( T_3 ) V_5 + V_6 - 1 ,
( void * ) V_67 ) ;
F_46 ( F_30 ( V_5 ) , V_6 ) ;
F_44 ( & V_2 . V_4 , V_5 , V_6 ) ;
}
void T_4 F_78 ( T_2 V_5 , T_2 V_6 )
{
T_3 V_99 , V_18 ;
F_32 ( L_14 ,
V_98 , ( T_3 ) V_5 , ( T_3 ) V_5 + V_6 - 1 ,
( void * ) V_67 ) ;
F_46 ( F_30 ( V_5 ) , V_6 ) ;
V_99 = F_58 ( V_5 ) ;
V_18 = F_59 ( V_5 + V_6 ) ;
for (; V_99 < V_18 ; V_99 ++ ) {
F_79 ( F_80 ( V_99 ) , 0 ) ;
V_100 ++ ;
}
}
T_2 T_4 F_81 ( void )
{
return V_2 . V_3 . V_33 ;
}
T_2 T_4 F_82 ( unsigned long V_101 )
{
unsigned long V_102 = 0 ;
struct V_38 * V_32 ;
unsigned long V_103 , V_104 ;
F_83 (memory, r) {
V_103 = F_84 ( V_32 ) ;
V_104 = F_85 ( V_32 ) ;
V_103 = F_86 (unsigned long, start_pfn, limit_pfn) ;
V_104 = F_86 (unsigned long, end_pfn, limit_pfn) ;
V_102 += V_104 - V_103 ;
}
return F_87 ( V_102 ) ;
}
T_2 T_1 F_88 ( void )
{
return V_2 . V_3 . V_15 [ 0 ] . V_5 ;
}
T_2 T_1 F_89 ( void )
{
int V_56 = V_2 . V_3 . V_13 - 1 ;
return ( V_2 . V_3 . V_15 [ V_56 ] . V_5 + V_2 . V_3 . V_15 [ V_56 ] . V_6 ) ;
}
void T_4 F_90 ( T_2 V_105 )
{
T_2 V_90 = ( T_2 ) V_7 ;
struct V_38 * V_32 ;
if ( ! V_105 )
return;
F_83 (memory, r) {
if ( V_105 <= V_32 -> V_6 ) {
V_90 = V_32 -> V_5 + V_105 ;
break;
}
V_105 -= V_32 -> V_6 ;
}
F_44 ( & V_2 . V_3 , V_90 ,
( T_2 ) V_7 ) ;
F_44 ( & V_2 . V_4 , V_90 ,
( T_2 ) V_7 ) ;
}
static int T_1 F_91 ( struct V_1 * type , T_2 V_36 )
{
unsigned int V_106 = 0 , V_107 = type -> V_13 ;
do {
unsigned int V_108 = ( V_107 + V_106 ) / 2 ;
if ( V_36 < type -> V_15 [ V_108 ] . V_5 )
V_107 = V_108 ;
else if ( V_36 >= ( type -> V_15 [ V_108 ] . V_5 +
type -> V_15 [ V_108 ] . V_6 ) )
V_106 = V_108 + 1 ;
else
return V_108 ;
} while ( V_106 < V_107 );
return - 1 ;
}
int T_4 F_92 ( T_2 V_36 )
{
return F_91 ( & V_2 . V_4 , V_36 ) != - 1 ;
}
int T_1 F_93 ( T_2 V_36 )
{
return F_91 ( & V_2 . V_3 , V_36 ) != - 1 ;
}
int T_1 F_94 ( unsigned long V_109 ,
unsigned long * V_103 , unsigned long * V_104 )
{
struct V_1 * type = & V_2 . V_3 ;
int V_108 = F_91 ( type , F_87 ( V_109 ) ) ;
if ( V_108 == - 1 )
return - 1 ;
* V_103 = F_59 ( type -> V_15 [ V_108 ] . V_5 ) ;
* V_104 = F_59 ( type -> V_15 [ V_108 ] . V_5 + type -> V_15 [ V_108 ] . V_6 ) ;
return type -> V_15 [ V_108 ] . V_20 ;
}
int T_1 F_95 ( T_2 V_5 , T_2 V_6 )
{
int V_56 = F_91 ( & V_2 . V_3 , V_5 ) ;
T_2 V_18 = V_5 + F_2 ( V_5 , & V_6 ) ;
if ( V_56 == - 1 )
return 0 ;
return V_2 . V_3 . V_15 [ V_56 ] . V_5 <= V_5 &&
( V_2 . V_3 . V_15 [ V_56 ] . V_5 +
V_2 . V_3 . V_15 [ V_56 ] . V_6 ) >= V_18 ;
}
int T_1 F_96 ( T_2 V_5 , T_2 V_6 )
{
F_2 ( V_5 , & V_6 ) ;
return F_5 ( & V_2 . V_4 , V_5 , V_6 ) >= 0 ;
}
void T_1 F_97 ( T_2 V_19 )
{
T_2 V_17 , V_18 , V_110 , V_111 ;
struct V_38 * V_32 ;
F_83 (memory, r) {
V_110 = V_32 -> V_5 ;
V_111 = V_32 -> V_5 + V_32 -> V_6 ;
V_17 = F_9 ( V_110 , V_19 ) ;
V_18 = F_12 ( V_111 , V_19 ) ;
if ( V_17 == V_110 && V_18 == V_111 )
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
void T_1 F_98 ( T_2 V_105 )
{
V_2 . V_27 = V_105 ;
}
T_2 T_1 F_99 ( void )
{
return V_2 . V_27 ;
}
static void T_1 F_100 ( struct V_1 * type , char * V_112 )
{
unsigned long long V_5 , V_6 ;
unsigned long V_34 ;
int V_12 ;
F_101 ( L_15 , V_112 , type -> V_13 ) ;
for ( V_12 = 0 ; V_12 < type -> V_13 ; V_12 ++ ) {
struct V_38 * V_57 = & type -> V_15 [ V_12 ] ;
char V_113 [ 32 ] = L_16 ;
V_5 = V_57 -> V_5 ;
V_6 = V_57 -> V_6 ;
V_34 = V_57 -> V_34 ;
#ifdef F_102
if ( F_38 ( V_57 ) != V_35 )
snprintf ( V_113 , sizeof( V_113 ) , L_17 ,
F_38 ( V_57 ) ) ;
#endif
F_101 ( L_18 ,
V_112 , V_12 , V_5 , V_5 + V_6 - 1 , V_6 , V_113 , V_34 ) ;
}
}
void T_1 F_103 ( void )
{
F_101 ( L_19 ) ;
F_101 ( L_20 ,
( unsigned long long ) V_2 . V_3 . V_33 ,
( unsigned long long ) V_2 . V_4 . V_33 ) ;
F_100 ( & V_2 . V_3 , L_1 ) ;
F_100 ( & V_2 . V_4 , L_2 ) ;
}
void T_4 F_104 ( void )
{
V_50 = 1 ;
}
static int T_4 F_105 ( char * V_114 )
{
if ( V_114 && strstr ( V_114 , L_21 ) )
V_115 = 1 ;
return 0 ;
}
static int F_106 ( struct V_116 * V_79 , void * V_117 )
{
struct V_1 * type = V_79 -> V_117 ;
struct V_38 * V_118 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < type -> V_13 ; V_12 ++ ) {
V_118 = & type -> V_15 [ V_12 ] ;
F_107 ( V_79 , L_22 , V_12 ) ;
if ( sizeof( T_2 ) == 4 )
F_107 ( V_79 , L_23 ,
( unsigned long ) V_118 -> V_5 ,
( unsigned long ) ( V_118 -> V_5 + V_118 -> V_6 - 1 ) ) ;
else
F_107 ( V_79 , L_24 ,
( unsigned long long ) V_118 -> V_5 ,
( unsigned long long ) ( V_118 -> V_5 + V_118 -> V_6 - 1 ) ) ;
}
return 0 ;
}
static int F_108 ( struct V_119 * V_119 , struct V_120 * V_120 )
{
return F_109 ( V_120 , F_106 , V_119 -> V_121 ) ;
}
static int T_4 F_110 ( void )
{
struct V_122 * V_123 = F_111 ( L_25 , NULL ) ;
if ( ! V_123 )
return - V_124 ;
F_112 ( L_1 , V_125 , V_123 , & V_2 . V_3 , & V_126 ) ;
F_112 ( L_2 , V_125 , V_123 , & V_2 . V_4 , & V_126 ) ;
#ifdef F_113
F_112 ( L_26 , V_125 , V_123 , & V_2 . V_127 , & V_126 ) ;
#endif
return 0 ;
}
