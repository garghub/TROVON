T_1 T_2 F_1 ( void )
{
return V_1 ? V_2 : V_3 ;
}
static T_2 const char *
F_2 ( struct V_4 * type )
{
if ( type == & V_5 . V_6 )
return L_1 ;
else if ( type == & V_5 . V_7 )
return L_2 ;
else
return L_3 ;
}
static inline T_3 F_3 ( T_3 V_8 , T_3 * V_9 )
{
return * V_9 = F_4 ( * V_9 , ( T_3 ) V_10 - V_8 ) ;
}
static unsigned long T_2 F_5 ( T_3 V_11 , T_3 V_12 ,
T_3 V_13 , T_3 V_14 )
{
return ( ( V_11 < ( V_13 + V_14 ) ) && ( V_13 < ( V_11 + V_12 ) ) ) ;
}
bool T_2 F_6 ( struct V_4 * type ,
T_3 V_8 , T_3 V_9 )
{
unsigned long V_15 ;
for ( V_15 = 0 ; V_15 < type -> V_16 ; V_15 ++ )
if ( F_5 ( V_8 , V_9 , type -> V_17 [ V_15 ] . V_8 ,
type -> V_17 [ V_15 ] . V_9 ) )
break;
return V_15 < type -> V_16 ;
}
static T_3 T_2
F_7 ( T_3 V_18 , T_3 V_19 ,
T_3 V_9 , T_3 V_20 , int V_21 ,
T_1 V_22 )
{
T_3 V_23 , V_24 , V_25 ;
T_4 V_15 ;
F_8 (i, nid, flags, &this_start, &this_end, NULL) {
V_23 = F_9 ( V_23 , V_18 , V_19 ) ;
V_24 = F_9 ( V_24 , V_18 , V_19 ) ;
V_25 = F_10 ( V_23 , V_20 ) ;
if ( V_25 < V_24 && V_24 - V_25 >= V_9 )
return V_25 ;
}
return 0 ;
}
static T_3 T_2
F_11 ( T_3 V_18 , T_3 V_19 ,
T_3 V_9 , T_3 V_20 , int V_21 ,
T_1 V_22 )
{
T_3 V_23 , V_24 , V_25 ;
T_4 V_15 ;
F_12 (i, nid, flags, &this_start, &this_end,
NULL) {
V_23 = F_9 ( V_23 , V_18 , V_19 ) ;
V_24 = F_9 ( V_24 , V_18 , V_19 ) ;
if ( V_24 < V_9 )
continue;
V_25 = F_13 ( V_24 - V_9 , V_20 ) ;
if ( V_25 >= V_23 )
return V_25 ;
}
return 0 ;
}
T_3 T_2 F_14 ( T_3 V_9 ,
T_3 V_20 , T_3 V_18 ,
T_3 V_19 , int V_21 , T_1 V_22 )
{
T_3 V_26 , V_27 ;
if ( V_19 == V_28 )
V_19 = V_5 . V_29 ;
V_18 = F_15 ( T_3 , V_18 , V_30 ) ;
V_19 = F_16 ( V_18 , V_19 ) ;
V_26 = F_17 ( V_31 ) ;
if ( F_18 () && V_19 > V_26 ) {
T_3 V_32 ;
V_32 = F_16 ( V_18 , V_26 ) ;
V_27 = F_7 ( V_32 , V_19 ,
V_9 , V_20 , V_21 , V_22 ) ;
if ( V_27 )
return V_27 ;
F_19 ( 1 , L_4 ) ;
}
return F_11 ( V_18 , V_19 , V_9 , V_20 , V_21 ,
V_22 ) ;
}
T_3 T_2 F_20 ( T_3 V_18 ,
T_3 V_19 , T_3 V_9 ,
T_3 V_20 )
{
T_3 V_27 ;
T_1 V_22 = F_1 () ;
V_33:
V_27 = F_14 ( V_9 , V_20 , V_18 , V_19 ,
V_34 , V_22 ) ;
if ( ! V_27 && ( V_22 & V_2 ) ) {
F_21 ( L_5 ,
& V_9 ) ;
V_22 &= ~ V_2 ;
goto V_33;
}
return V_27 ;
}
static void T_2 F_22 ( struct V_4 * type , unsigned long V_35 )
{
type -> V_36 -= type -> V_17 [ V_35 ] . V_9 ;
memmove ( & type -> V_17 [ V_35 ] , & type -> V_17 [ V_35 + 1 ] ,
( type -> V_16 - ( V_35 + 1 ) ) * sizeof( type -> V_17 [ V_35 ] ) ) ;
type -> V_16 -- ;
if ( type -> V_16 == 0 ) {
F_23 ( type -> V_36 != 0 ) ;
type -> V_16 = 1 ;
type -> V_17 [ 0 ] . V_8 = 0 ;
type -> V_17 [ 0 ] . V_9 = 0 ;
type -> V_17 [ 0 ] . V_22 = 0 ;
F_24 ( & type -> V_17 [ 0 ] , V_37 ) ;
}
}
T_3 T_2 F_25 (
T_3 * V_38 )
{
if ( V_5 . V_7 . V_17 == V_39 )
return 0 ;
* V_38 = F_26 ( V_5 . V_7 . V_17 ) ;
return F_27 ( sizeof( struct V_40 ) *
V_5 . V_7 . F_16 ) ;
}
T_3 T_2 F_28 (
T_3 * V_38 )
{
if ( V_5 . V_6 . V_17 == V_41 )
return 0 ;
* V_38 = F_26 ( V_5 . V_6 . V_17 ) ;
return F_27 ( sizeof( struct V_40 ) *
V_5 . V_6 . F_16 ) ;
}
static int T_2 F_29 ( struct V_4 * type ,
T_3 V_42 ,
T_3 V_43 )
{
struct V_40 * V_44 , * V_45 ;
T_3 V_46 , V_47 ;
T_3 V_48 , V_49 , V_38 ;
int V_50 = F_30 () ;
int * V_51 ;
if ( ! V_52 )
return - 1 ;
V_48 = type -> F_16 * sizeof( struct V_40 ) ;
V_49 = V_48 << 1 ;
V_46 = F_27 ( V_48 ) ;
V_47 = F_27 ( V_49 ) ;
if ( type == & V_5 . V_6 )
V_51 = & V_53 ;
else
V_51 = & V_54 ;
if ( V_50 ) {
V_44 = F_31 ( V_49 , V_55 ) ;
V_38 = V_44 ? F_26 ( V_44 ) : 0 ;
} else {
if ( type != & V_5 . V_7 )
V_42 = V_43 = 0 ;
V_38 = F_20 ( V_42 + V_43 ,
V_5 . V_29 ,
V_47 , V_30 ) ;
if ( ! V_38 && V_43 )
V_38 = F_20 ( 0 ,
F_4 ( V_42 , V_5 . V_29 ) ,
V_47 , V_30 ) ;
V_44 = V_38 ? F_32 ( V_38 ) : NULL ;
}
if ( ! V_38 ) {
F_33 ( L_6 ,
F_2 ( type ) , type -> F_16 , type -> F_16 * 2 ) ;
return - 1 ;
}
F_34 ( L_7 ,
F_2 ( type ) , type -> F_16 * 2 , ( T_4 ) V_38 ,
( T_4 ) V_38 + V_49 - 1 ) ;
memcpy ( V_44 , type -> V_17 , V_48 ) ;
memset ( V_44 + type -> F_16 , 0 , V_48 ) ;
V_45 = type -> V_17 ;
type -> V_17 = V_44 ;
type -> F_16 <<= 1 ;
if ( * V_51 )
F_35 ( V_45 ) ;
else if ( V_45 != V_41 &&
V_45 != V_39 )
F_36 ( F_26 ( V_45 ) , V_46 ) ;
if ( ! V_50 )
F_37 ( F_38 ( V_38 , V_47 ) ) ;
* V_51 = V_50 ;
return 0 ;
}
static void T_2 F_39 ( struct V_4 * type )
{
int V_15 = 0 ;
while ( V_15 < type -> V_16 - 1 ) {
struct V_40 * V_56 = & type -> V_17 [ V_15 ] ;
struct V_40 * V_57 = & type -> V_17 [ V_15 + 1 ] ;
if ( V_56 -> V_8 + V_56 -> V_9 != V_57 -> V_8 ||
F_40 ( V_56 ) !=
F_40 ( V_57 ) ||
V_56 -> V_22 != V_57 -> V_22 ) {
F_37 ( V_56 -> V_8 + V_56 -> V_9 > V_57 -> V_8 ) ;
V_15 ++ ;
continue;
}
V_56 -> V_9 += V_57 -> V_9 ;
memmove ( V_57 , V_57 + 1 , ( type -> V_16 - ( V_15 + 2 ) ) * sizeof( * V_57 ) ) ;
type -> V_16 -- ;
}
}
static void T_2 F_41 ( struct V_4 * type ,
int V_58 , T_3 V_8 ,
T_3 V_9 ,
int V_21 , unsigned long V_22 )
{
struct V_40 * V_59 = & type -> V_17 [ V_58 ] ;
F_37 ( type -> V_16 >= type -> F_16 ) ;
memmove ( V_59 + 1 , V_59 , ( type -> V_16 - V_58 ) * sizeof( * V_59 ) ) ;
V_59 -> V_8 = V_8 ;
V_59 -> V_9 = V_9 ;
V_59 -> V_22 = V_22 ;
F_24 ( V_59 , V_21 ) ;
type -> V_16 ++ ;
type -> V_36 += V_9 ;
}
int T_2 F_42 ( struct V_4 * type ,
T_3 V_8 , T_3 V_9 ,
int V_21 , unsigned long V_22 )
{
bool V_60 = false ;
T_3 V_61 = V_8 ;
T_3 V_19 = V_8 + F_3 ( V_8 , & V_9 ) ;
int V_58 , V_62 ;
struct V_40 * V_59 ;
if ( ! V_9 )
return 0 ;
if ( type -> V_17 [ 0 ] . V_9 == 0 ) {
F_23 ( type -> V_16 != 1 || type -> V_36 ) ;
type -> V_17 [ 0 ] . V_8 = V_8 ;
type -> V_17 [ 0 ] . V_9 = V_9 ;
type -> V_17 [ 0 ] . V_22 = V_22 ;
F_24 ( & type -> V_17 [ 0 ] , V_21 ) ;
type -> V_36 = V_9 ;
return 0 ;
}
V_63:
V_8 = V_61 ;
V_62 = 0 ;
F_43 (type, rgn) {
T_3 V_64 = V_59 -> V_8 ;
T_3 V_65 = V_64 + V_59 -> V_9 ;
if ( V_64 >= V_19 )
break;
if ( V_65 <= V_8 )
continue;
if ( V_64 > V_8 ) {
#ifdef F_44
F_23 ( V_21 != F_40 ( V_59 ) ) ;
#endif
F_23 ( V_22 != V_59 -> V_22 ) ;
V_62 ++ ;
if ( V_60 )
F_41 ( type , V_58 ++ , V_8 ,
V_64 - V_8 , V_21 ,
V_22 ) ;
}
V_8 = F_4 ( V_65 , V_19 ) ;
}
if ( V_8 < V_19 ) {
V_62 ++ ;
if ( V_60 )
F_41 ( type , V_58 , V_8 , V_19 - V_8 ,
V_21 , V_22 ) ;
}
if ( ! V_60 ) {
while ( type -> V_16 + V_62 > type -> F_16 )
if ( F_29 ( type , V_61 , V_9 ) < 0 )
return - V_66 ;
V_60 = true ;
goto V_63;
} else {
F_39 ( type ) ;
return 0 ;
}
}
int T_2 F_45 ( T_3 V_8 , T_3 V_9 ,
int V_21 )
{
return F_42 ( & V_5 . V_6 , V_8 , V_9 , V_21 , 0 ) ;
}
static int T_2 F_46 ( T_3 V_8 ,
T_3 V_9 ,
int V_21 ,
unsigned long V_22 )
{
F_34 ( L_8 ,
( unsigned long long ) V_8 ,
( unsigned long long ) V_8 + V_9 - 1 ,
V_22 , ( void * ) V_67 ) ;
return F_42 ( & V_5 . V_6 , V_8 , V_9 , V_21 , V_22 ) ;
}
int T_2 F_47 ( T_3 V_8 , T_3 V_9 )
{
return F_46 ( V_8 , V_9 , V_37 , 0 ) ;
}
static int T_2 F_48 ( struct V_4 * type ,
T_3 V_8 , T_3 V_9 ,
int * V_68 , int * V_69 )
{
T_3 V_19 = V_8 + F_3 ( V_8 , & V_9 ) ;
int V_58 ;
struct V_40 * V_59 ;
* V_68 = * V_69 = 0 ;
if ( ! V_9 )
return 0 ;
while ( type -> V_16 + 2 > type -> F_16 )
if ( F_29 ( type , V_8 , V_9 ) < 0 )
return - V_66 ;
F_43 (type, rgn) {
T_3 V_64 = V_59 -> V_8 ;
T_3 V_65 = V_64 + V_59 -> V_9 ;
if ( V_64 >= V_19 )
break;
if ( V_65 <= V_8 )
continue;
if ( V_64 < V_8 ) {
V_59 -> V_8 = V_8 ;
V_59 -> V_9 -= V_8 - V_64 ;
type -> V_36 -= V_8 - V_64 ;
F_41 ( type , V_58 , V_64 , V_8 - V_64 ,
F_40 ( V_59 ) ,
V_59 -> V_22 ) ;
} else if ( V_65 > V_19 ) {
V_59 -> V_8 = V_19 ;
V_59 -> V_9 -= V_19 - V_64 ;
type -> V_36 -= V_19 - V_64 ;
F_41 ( type , V_58 -- , V_64 , V_19 - V_64 ,
F_40 ( V_59 ) ,
V_59 -> V_22 ) ;
} else {
if ( ! * V_69 )
* V_68 = V_58 ;
* V_69 = V_58 + 1 ;
}
}
return 0 ;
}
static int T_2 F_49 ( struct V_4 * type ,
T_3 V_8 , T_3 V_9 )
{
int V_68 , V_69 ;
int V_15 , V_27 ;
V_27 = F_48 ( type , V_8 , V_9 , & V_68 , & V_69 ) ;
if ( V_27 )
return V_27 ;
for ( V_15 = V_69 - 1 ; V_15 >= V_68 ; V_15 -- )
F_22 ( type , V_15 ) ;
return 0 ;
}
int T_2 F_50 ( T_3 V_8 , T_3 V_9 )
{
return F_49 ( & V_5 . V_6 , V_8 , V_9 ) ;
}
int T_2 F_36 ( T_3 V_8 , T_3 V_9 )
{
F_34 ( L_9 ,
( unsigned long long ) V_8 ,
( unsigned long long ) V_8 + V_9 - 1 ,
( void * ) V_67 ) ;
F_51 ( F_32 ( V_8 ) , V_9 ) ;
return F_49 ( & V_5 . V_7 , V_8 , V_9 ) ;
}
static int T_2 F_52 ( T_3 V_8 ,
T_3 V_9 ,
int V_21 ,
unsigned long V_22 )
{
F_34 ( L_10 ,
( unsigned long long ) V_8 ,
( unsigned long long ) V_8 + V_9 - 1 ,
V_22 , ( void * ) V_67 ) ;
return F_42 ( & V_5 . V_7 , V_8 , V_9 , V_21 , V_22 ) ;
}
int T_2 F_38 ( T_3 V_8 , T_3 V_9 )
{
return F_52 ( V_8 , V_9 , V_37 , 0 ) ;
}
static int T_2 F_53 ( T_3 V_8 ,
T_3 V_9 , int V_70 , int V_71 )
{
struct V_4 * type = & V_5 . V_6 ;
int V_15 , V_27 , V_68 , V_69 ;
V_27 = F_48 ( type , V_8 , V_9 , & V_68 , & V_69 ) ;
if ( V_27 )
return V_27 ;
for ( V_15 = V_68 ; V_15 < V_69 ; V_15 ++ )
if ( V_70 )
F_54 ( & type -> V_17 [ V_15 ] , V_71 ) ;
else
F_55 ( & type -> V_17 [ V_15 ] , V_71 ) ;
F_39 ( type ) ;
return 0 ;
}
int T_2 F_56 ( T_3 V_8 , T_3 V_9 )
{
return F_53 ( V_8 , V_9 , 1 , V_72 ) ;
}
int T_2 F_57 ( T_3 V_8 , T_3 V_9 )
{
return F_53 ( V_8 , V_9 , 0 , V_72 ) ;
}
int T_2 F_58 ( T_3 V_8 , T_3 V_9 )
{
V_1 = true ;
return F_53 ( V_8 , V_9 , 1 , V_2 ) ;
}
int T_2 F_59 ( T_3 V_8 , T_3 V_9 )
{
return F_53 ( V_8 , V_9 , 1 , V_73 ) ;
}
void T_2 F_60 ( T_4 * V_58 ,
T_3 * V_74 ,
T_3 * V_75 )
{
struct V_4 * type = & V_5 . V_7 ;
if ( * V_58 >= 0 && * V_58 < type -> V_16 ) {
struct V_40 * V_35 = & type -> V_17 [ * V_58 ] ;
T_3 V_8 = V_35 -> V_8 ;
T_3 V_9 = V_35 -> V_9 ;
if ( V_74 )
* V_74 = V_8 ;
if ( V_75 )
* V_75 = V_8 + V_9 - 1 ;
* V_58 += 1 ;
return;
}
* V_58 = V_10 ;
}
void T_2 F_61 ( T_4 * V_58 , int V_21 , T_1 V_22 ,
struct V_4 * V_76 ,
struct V_4 * V_77 ,
T_3 * V_74 ,
T_3 * V_75 , int * V_78 )
{
int V_79 = * V_58 & 0xffffffff ;
int V_80 = * V_58 >> 32 ;
if ( F_19 ( V_21 == V_37 ,
L_11 ) )
V_21 = V_34 ;
for (; V_79 < V_76 -> V_16 ; V_79 ++ ) {
struct V_40 * V_81 = & V_76 -> V_17 [ V_79 ] ;
T_3 V_82 = V_81 -> V_8 ;
T_3 V_83 = V_81 -> V_8 + V_81 -> V_9 ;
int V_84 = F_40 ( V_81 ) ;
if ( V_21 != V_34 && V_21 != V_84 )
continue;
if ( F_62 () && F_63 ( V_81 ) )
continue;
if ( ( V_22 & V_2 ) && ! F_64 ( V_81 ) )
continue;
if ( ! ( V_22 & V_73 ) && F_65 ( V_81 ) )
continue;
if ( ! V_77 ) {
if ( V_74 )
* V_74 = V_82 ;
if ( V_75 )
* V_75 = V_83 ;
if ( V_78 )
* V_78 = V_84 ;
V_79 ++ ;
* V_58 = ( V_85 ) V_79 | ( T_4 ) V_80 << 32 ;
return;
}
for (; V_80 < V_77 -> V_16 + 1 ; V_80 ++ ) {
struct V_40 * V_35 ;
T_3 V_86 ;
T_3 V_87 ;
V_35 = & V_77 -> V_17 [ V_80 ] ;
V_86 = V_80 ? V_35 [ - 1 ] . V_8 + V_35 [ - 1 ] . V_9 : 0 ;
V_87 = V_80 < V_77 -> V_16 ?
V_35 -> V_8 : V_10 ;
if ( V_86 >= V_83 )
break;
if ( V_82 < V_87 ) {
if ( V_74 )
* V_74 =
F_16 ( V_82 , V_86 ) ;
if ( V_75 )
* V_75 = F_4 ( V_83 , V_87 ) ;
if ( V_78 )
* V_78 = V_84 ;
if ( V_83 <= V_87 )
V_79 ++ ;
else
V_80 ++ ;
* V_58 = ( V_85 ) V_79 | ( T_4 ) V_80 << 32 ;
return;
}
}
}
* V_58 = V_10 ;
}
void T_2 F_66 ( T_4 * V_58 , int V_21 , T_1 V_22 ,
struct V_4 * V_76 ,
struct V_4 * V_77 ,
T_3 * V_74 ,
T_3 * V_75 , int * V_78 )
{
int V_79 = * V_58 & 0xffffffff ;
int V_80 = * V_58 >> 32 ;
if ( F_19 ( V_21 == V_37 , L_11 ) )
V_21 = V_34 ;
if ( * V_58 == ( T_4 ) V_10 ) {
V_79 = V_76 -> V_16 - 1 ;
V_80 = V_77 -> V_16 ;
}
for (; V_79 >= 0 ; V_79 -- ) {
struct V_40 * V_81 = & V_76 -> V_17 [ V_79 ] ;
T_3 V_82 = V_81 -> V_8 ;
T_3 V_83 = V_81 -> V_8 + V_81 -> V_9 ;
int V_84 = F_40 ( V_81 ) ;
if ( V_21 != V_34 && V_21 != V_84 )
continue;
if ( F_62 () && F_63 ( V_81 ) )
continue;
if ( ( V_22 & V_2 ) && ! F_64 ( V_81 ) )
continue;
if ( ! ( V_22 & V_73 ) && F_65 ( V_81 ) )
continue;
if ( ! V_77 ) {
if ( V_74 )
* V_74 = V_82 ;
if ( V_75 )
* V_75 = V_83 ;
if ( V_78 )
* V_78 = V_84 ;
V_79 ++ ;
* V_58 = ( V_85 ) V_79 | ( T_4 ) V_80 << 32 ;
return;
}
for (; V_80 >= 0 ; V_80 -- ) {
struct V_40 * V_35 ;
T_3 V_86 ;
T_3 V_87 ;
V_35 = & V_77 -> V_17 [ V_80 ] ;
V_86 = V_80 ? V_35 [ - 1 ] . V_8 + V_35 [ - 1 ] . V_9 : 0 ;
V_87 = V_80 < V_77 -> V_16 ?
V_35 -> V_8 : V_10 ;
if ( V_87 <= V_82 )
break;
if ( V_83 > V_86 ) {
if ( V_74 )
* V_74 = F_16 ( V_82 , V_86 ) ;
if ( V_75 )
* V_75 = F_4 ( V_83 , V_87 ) ;
if ( V_78 )
* V_78 = V_84 ;
if ( V_82 >= V_86 )
V_79 -- ;
else
V_80 -- ;
* V_58 = ( V_85 ) V_79 | ( T_4 ) V_80 << 32 ;
return;
}
}
}
* V_58 = V_10 ;
}
void T_2 F_67 ( int * V_58 , int V_21 ,
unsigned long * V_88 ,
unsigned long * V_89 , int * V_78 )
{
struct V_4 * type = & V_5 . V_6 ;
struct V_40 * V_35 ;
while ( ++ * V_58 < type -> V_16 ) {
V_35 = & type -> V_17 [ * V_58 ] ;
if ( F_68 ( V_35 -> V_8 ) >= F_69 ( V_35 -> V_8 + V_35 -> V_9 ) )
continue;
if ( V_21 == V_37 || V_21 == V_35 -> V_21 )
break;
}
if ( * V_58 >= type -> V_16 ) {
* V_58 = - 1 ;
return;
}
if ( V_88 )
* V_88 = F_68 ( V_35 -> V_8 ) ;
if ( V_89 )
* V_89 = F_69 ( V_35 -> V_8 + V_35 -> V_9 ) ;
if ( V_78 )
* V_78 = V_35 -> V_21 ;
}
int T_2 F_70 ( T_3 V_8 , T_3 V_9 ,
struct V_4 * type , int V_21 )
{
int V_68 , V_69 ;
int V_15 , V_27 ;
V_27 = F_48 ( type , V_8 , V_9 , & V_68 , & V_69 ) ;
if ( V_27 )
return V_27 ;
for ( V_15 = V_68 ; V_15 < V_69 ; V_15 ++ )
F_24 ( & type -> V_17 [ V_15 ] , V_21 ) ;
F_39 ( type ) ;
return 0 ;
}
static T_3 T_5 F_71 ( T_3 V_9 ,
T_3 V_20 , T_3 V_18 ,
T_3 V_19 , int V_21 , T_1 V_22 )
{
T_3 V_90 ;
if ( ! V_20 )
V_20 = V_91 ;
V_90 = F_14 ( V_9 , V_20 , V_18 , V_19 , V_21 ,
V_22 ) ;
if ( V_90 && ! F_38 ( V_90 , V_9 ) ) {
F_72 ( F_32 ( V_90 ) , V_9 , 0 , 0 ) ;
return V_90 ;
}
return 0 ;
}
T_3 T_5 F_73 ( T_3 V_9 , T_3 V_20 ,
T_3 V_18 , T_3 V_19 ,
T_1 V_22 )
{
return F_71 ( V_9 , V_20 , V_18 , V_19 , V_34 ,
V_22 ) ;
}
static T_3 T_5 F_74 ( T_3 V_9 ,
T_3 V_20 , T_3 V_92 ,
int V_21 , T_1 V_22 )
{
return F_71 ( V_9 , V_20 , 0 , V_92 , V_21 , V_22 ) ;
}
T_3 T_5 F_75 ( T_3 V_9 , T_3 V_20 , int V_21 )
{
T_1 V_22 = F_1 () ;
T_3 V_27 ;
V_33:
V_27 = F_74 ( V_9 , V_20 , V_28 ,
V_21 , V_22 ) ;
if ( ! V_27 && ( V_22 & V_2 ) ) {
V_22 &= ~ V_2 ;
goto V_33;
}
return V_27 ;
}
T_3 T_5 F_76 ( T_3 V_9 , T_3 V_20 , T_3 V_92 )
{
return F_74 ( V_9 , V_20 , V_92 , V_34 ,
V_3 ) ;
}
T_3 T_5 F_77 ( T_3 V_9 , T_3 V_20 , T_3 V_92 )
{
T_3 V_93 ;
V_93 = F_76 ( V_9 , V_20 , V_92 ) ;
if ( V_93 == 0 )
F_78 ( L_12 ,
( unsigned long long ) V_9 , ( unsigned long long ) V_92 ) ;
return V_93 ;
}
T_3 T_5 F_79 ( T_3 V_9 , T_3 V_20 )
{
return F_77 ( V_9 , V_20 , V_28 ) ;
}
T_3 T_5 F_80 ( T_3 V_9 , T_3 V_20 , int V_21 )
{
T_3 V_94 = F_75 ( V_9 , V_20 , V_21 ) ;
if ( V_94 )
return V_94 ;
return F_77 ( V_9 , V_20 , V_28 ) ;
}
static void * T_5 F_81 (
T_3 V_9 , T_3 V_20 ,
T_3 V_95 , T_3 V_92 ,
int V_21 )
{
T_3 V_93 ;
void * V_96 ;
T_1 V_22 = F_1 () ;
if ( F_19 ( V_21 == V_37 , L_11 ) )
V_21 = V_34 ;
if ( F_82 ( F_30 () ) )
return F_83 ( V_9 , V_97 , V_21 ) ;
if ( ! V_20 )
V_20 = V_91 ;
if ( V_92 > V_5 . V_29 )
V_92 = V_5 . V_29 ;
V_33:
V_93 = F_14 ( V_9 , V_20 , V_95 , V_92 ,
V_21 , V_22 ) ;
if ( V_93 )
goto V_98;
if ( V_21 != V_34 ) {
V_93 = F_14 ( V_9 , V_20 , V_95 ,
V_92 , V_34 ,
V_22 ) ;
if ( V_93 )
goto V_98;
}
if ( V_95 ) {
V_95 = 0 ;
goto V_33;
}
if ( V_22 & V_2 ) {
V_22 &= ~ V_2 ;
F_21 ( L_5 ,
& V_9 ) ;
goto V_33;
}
return NULL ;
V_98:
F_38 ( V_93 , V_9 ) ;
V_96 = F_84 ( V_93 ) ;
memset ( V_96 , 0 , V_9 ) ;
F_72 ( V_96 , V_9 , 0 , 0 ) ;
return V_96 ;
}
void * T_5 F_85 (
T_3 V_9 , T_3 V_20 ,
T_3 V_95 , T_3 V_92 ,
int V_21 )
{
F_34 ( L_13 ,
V_99 , ( T_4 ) V_9 , ( T_4 ) V_20 , V_21 , ( T_4 ) V_95 ,
( T_4 ) V_92 , ( void * ) V_67 ) ;
return F_81 ( V_9 , V_20 , V_95 ,
V_92 , V_21 ) ;
}
void * T_5 F_86 (
T_3 V_9 , T_3 V_20 ,
T_3 V_95 , T_3 V_92 ,
int V_21 )
{
void * V_96 ;
F_34 ( L_13 ,
V_99 , ( T_4 ) V_9 , ( T_4 ) V_20 , V_21 , ( T_4 ) V_95 ,
( T_4 ) V_92 , ( void * ) V_67 ) ;
V_96 = F_81 ( V_9 , V_20 ,
V_95 , V_92 , V_21 ) ;
if ( V_96 )
return V_96 ;
F_78 ( L_14 ,
V_99 , ( T_4 ) V_9 , ( T_4 ) V_20 , V_21 , ( T_4 ) V_95 ,
( T_4 ) V_92 ) ;
return NULL ;
}
void T_5 F_87 ( T_3 V_8 , T_3 V_9 )
{
F_34 ( L_15 ,
V_99 , ( T_4 ) V_8 , ( T_4 ) V_8 + V_9 - 1 ,
( void * ) V_67 ) ;
F_51 ( F_32 ( V_8 ) , V_9 ) ;
F_49 ( & V_5 . V_7 , V_8 , V_9 ) ;
}
void T_5 F_88 ( T_3 V_8 , T_3 V_9 )
{
T_4 V_100 , V_19 ;
F_34 ( L_15 ,
V_99 , ( T_4 ) V_8 , ( T_4 ) V_8 + V_9 - 1 ,
( void * ) V_67 ) ;
F_51 ( F_32 ( V_8 ) , V_9 ) ;
V_100 = F_68 ( V_8 ) ;
V_19 = F_69 ( V_8 + V_9 ) ;
for (; V_100 < V_19 ; V_100 ++ ) {
F_89 ( F_90 ( V_100 ) , V_100 , 0 ) ;
V_101 ++ ;
}
}
T_3 T_2 F_91 ( void )
{
return V_5 . V_6 . V_36 ;
}
T_3 T_5 F_92 ( unsigned long V_102 )
{
unsigned long V_103 = 0 ;
struct V_40 * V_35 ;
unsigned long V_104 , V_105 ;
F_93 (memory, r) {
V_104 = F_94 ( V_35 ) ;
V_105 = F_95 ( V_35 ) ;
V_104 = F_96 (unsigned long, start_pfn, limit_pfn) ;
V_105 = F_96 (unsigned long, end_pfn, limit_pfn) ;
V_103 += V_105 - V_104 ;
}
return F_97 ( V_103 ) ;
}
T_3 T_2 F_98 ( void )
{
return V_5 . V_6 . V_17 [ 0 ] . V_8 ;
}
T_3 T_2 F_99 ( void )
{
int V_58 = V_5 . V_6 . V_16 - 1 ;
return ( V_5 . V_6 . V_17 [ V_58 ] . V_8 + V_5 . V_6 . V_17 [ V_58 ] . V_9 ) ;
}
void T_5 F_100 ( T_3 V_106 )
{
T_3 V_92 = ( T_3 ) V_10 ;
struct V_40 * V_35 ;
if ( ! V_106 )
return;
F_93 (memory, r) {
if ( V_106 <= V_35 -> V_9 ) {
V_92 = V_35 -> V_8 + V_106 ;
break;
}
V_106 -= V_35 -> V_9 ;
}
F_49 ( & V_5 . V_6 , V_92 ,
( T_3 ) V_10 ) ;
F_49 ( & V_5 . V_7 , V_92 ,
( T_3 ) V_10 ) ;
}
static int T_2 F_101 ( struct V_4 * type , T_3 V_38 )
{
unsigned int V_107 = 0 , V_108 = type -> V_16 ;
do {
unsigned int V_109 = ( V_108 + V_107 ) / 2 ;
if ( V_38 < type -> V_17 [ V_109 ] . V_8 )
V_108 = V_109 ;
else if ( V_38 >= ( type -> V_17 [ V_109 ] . V_8 +
type -> V_17 [ V_109 ] . V_9 ) )
V_107 = V_109 + 1 ;
else
return V_109 ;
} while ( V_107 < V_108 );
return - 1 ;
}
bool T_5 F_102 ( T_3 V_38 )
{
return F_101 ( & V_5 . V_7 , V_38 ) != - 1 ;
}
bool T_2 F_103 ( T_3 V_38 )
{
return F_101 ( & V_5 . V_6 , V_38 ) != - 1 ;
}
int T_2 F_104 ( T_3 V_38 )
{
int V_15 = F_101 ( & V_5 . V_6 , V_38 ) ;
if ( V_15 == - 1 )
return false ;
return ! F_65 ( & V_5 . V_6 . V_17 [ V_15 ] ) ;
}
int T_2 F_105 ( unsigned long V_110 ,
unsigned long * V_104 , unsigned long * V_105 )
{
struct V_4 * type = & V_5 . V_6 ;
int V_109 = F_101 ( type , F_97 ( V_110 ) ) ;
if ( V_109 == - 1 )
return - 1 ;
* V_104 = F_69 ( type -> V_17 [ V_109 ] . V_8 ) ;
* V_105 = F_69 ( type -> V_17 [ V_109 ] . V_8 + type -> V_17 [ V_109 ] . V_9 ) ;
return type -> V_17 [ V_109 ] . V_21 ;
}
int T_2 F_106 ( T_3 V_8 , T_3 V_9 )
{
int V_58 = F_101 ( & V_5 . V_6 , V_8 ) ;
T_3 V_19 = V_8 + F_3 ( V_8 , & V_9 ) ;
if ( V_58 == - 1 )
return 0 ;
return V_5 . V_6 . V_17 [ V_58 ] . V_8 <= V_8 &&
( V_5 . V_6 . V_17 [ V_58 ] . V_8 +
V_5 . V_6 . V_17 [ V_58 ] . V_9 ) >= V_19 ;
}
bool T_2 F_107 ( T_3 V_8 , T_3 V_9 )
{
F_3 ( V_8 , & V_9 ) ;
return F_6 ( & V_5 . V_7 , V_8 , V_9 ) ;
}
void T_2 F_108 ( T_3 V_20 )
{
T_3 V_18 , V_19 , V_111 , V_112 ;
struct V_40 * V_35 ;
F_93 (memory, r) {
V_111 = V_35 -> V_8 ;
V_112 = V_35 -> V_8 + V_35 -> V_9 ;
V_18 = F_10 ( V_111 , V_20 ) ;
V_19 = F_13 ( V_112 , V_20 ) ;
if ( V_18 == V_111 && V_19 == V_112 )
continue;
if ( V_18 < V_19 ) {
V_35 -> V_8 = V_18 ;
V_35 -> V_9 = V_19 - V_18 ;
} else {
F_22 ( & V_5 . V_6 ,
V_35 - V_5 . V_6 . V_17 ) ;
V_35 -- ;
}
}
}
void T_2 F_109 ( T_3 V_106 )
{
V_5 . V_29 = V_106 ;
}
T_3 T_2 F_110 ( void )
{
return V_5 . V_29 ;
}
static void T_2 F_111 ( struct V_4 * type , char * V_113 )
{
unsigned long long V_8 , V_9 ;
unsigned long V_22 ;
int V_58 ;
struct V_40 * V_59 ;
F_112 ( L_16 , V_113 , type -> V_16 ) ;
F_43 (type, rgn) {
char V_114 [ 32 ] = L_17 ;
V_8 = V_59 -> V_8 ;
V_9 = V_59 -> V_9 ;
V_22 = V_59 -> V_22 ;
#ifdef F_44
if ( F_40 ( V_59 ) != V_37 )
snprintf ( V_114 , sizeof( V_114 ) , L_18 ,
F_40 ( V_59 ) ) ;
#endif
F_112 ( L_19 ,
V_113 , V_58 , V_8 , V_8 + V_9 - 1 , V_9 , V_114 , V_22 ) ;
}
}
void T_2 F_113 ( void )
{
F_112 ( L_20 ) ;
F_112 ( L_21 ,
( unsigned long long ) V_5 . V_6 . V_36 ,
( unsigned long long ) V_5 . V_7 . V_36 ) ;
F_111 ( & V_5 . V_6 , L_1 ) ;
F_111 ( & V_5 . V_7 , L_2 ) ;
}
void T_5 F_114 ( void )
{
V_52 = 1 ;
}
static int T_5 F_115 ( char * V_115 )
{
if ( V_115 && strstr ( V_115 , L_22 ) )
V_116 = 1 ;
return 0 ;
}
static int F_116 ( struct V_117 * V_81 , void * V_118 )
{
struct V_4 * type = V_81 -> V_118 ;
struct V_40 * V_119 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < type -> V_16 ; V_15 ++ ) {
V_119 = & type -> V_17 [ V_15 ] ;
F_117 ( V_81 , L_23 , V_15 ) ;
if ( sizeof( T_3 ) == 4 )
F_117 ( V_81 , L_24 ,
( unsigned long ) V_119 -> V_8 ,
( unsigned long ) ( V_119 -> V_8 + V_119 -> V_9 - 1 ) ) ;
else
F_117 ( V_81 , L_25 ,
( unsigned long long ) V_119 -> V_8 ,
( unsigned long long ) ( V_119 -> V_8 + V_119 -> V_9 - 1 ) ) ;
}
return 0 ;
}
static int F_118 ( struct V_120 * V_120 , struct V_121 * V_121 )
{
return F_119 ( V_121 , F_116 , V_120 -> V_122 ) ;
}
static int T_5 F_120 ( void )
{
struct V_123 * V_124 = F_121 ( L_26 , NULL ) ;
if ( ! V_124 )
return - V_125 ;
F_122 ( L_1 , V_126 , V_124 , & V_5 . V_6 , & V_127 ) ;
F_122 ( L_2 , V_126 , V_124 , & V_5 . V_7 , & V_127 ) ;
#ifdef F_123
F_122 ( L_27 , V_126 , V_124 , & V_5 . V_128 , & V_127 ) ;
#endif
return 0 ;
}
