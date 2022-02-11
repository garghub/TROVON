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
static long T_2 F_6 ( struct V_4 * type ,
T_3 V_8 , T_3 V_9 )
{
unsigned long V_15 ;
for ( V_15 = 0 ; V_15 < type -> V_16 ; V_15 ++ ) {
T_3 V_17 = type -> V_18 [ V_15 ] . V_8 ;
T_3 V_19 = type -> V_18 [ V_15 ] . V_9 ;
if ( F_5 ( V_8 , V_9 , V_17 , V_19 ) )
break;
}
return ( V_15 < type -> V_16 ) ? V_15 : - 1 ;
}
static T_3 T_2
F_7 ( T_3 V_20 , T_3 V_21 ,
T_3 V_9 , T_3 V_22 , int V_23 ,
T_1 V_24 )
{
T_3 V_25 , V_26 , V_27 ;
T_4 V_15 ;
F_8 (i, nid, flags, &this_start, &this_end, NULL) {
V_25 = F_9 ( V_25 , V_20 , V_21 ) ;
V_26 = F_9 ( V_26 , V_20 , V_21 ) ;
V_27 = F_10 ( V_25 , V_22 ) ;
if ( V_27 < V_26 && V_26 - V_27 >= V_9 )
return V_27 ;
}
return 0 ;
}
static T_3 T_2
F_11 ( T_3 V_20 , T_3 V_21 ,
T_3 V_9 , T_3 V_22 , int V_23 ,
T_1 V_24 )
{
T_3 V_25 , V_26 , V_27 ;
T_4 V_15 ;
F_12 (i, nid, flags, &this_start, &this_end,
NULL) {
V_25 = F_9 ( V_25 , V_20 , V_21 ) ;
V_26 = F_9 ( V_26 , V_20 , V_21 ) ;
if ( V_26 < V_9 )
continue;
V_27 = F_13 ( V_26 - V_9 , V_22 ) ;
if ( V_27 >= V_25 )
return V_27 ;
}
return 0 ;
}
T_3 T_2 F_14 ( T_3 V_9 ,
T_3 V_22 , T_3 V_20 ,
T_3 V_21 , int V_23 , T_1 V_24 )
{
T_3 V_28 , V_29 ;
if ( V_21 == V_30 )
V_21 = V_5 . V_31 ;
V_20 = F_15 ( T_3 , V_20 , V_32 ) ;
V_21 = F_16 ( V_20 , V_21 ) ;
V_28 = F_17 ( V_33 ) ;
if ( F_18 () && V_21 > V_28 ) {
T_3 V_34 ;
V_34 = F_16 ( V_20 , V_28 ) ;
V_29 = F_7 ( V_34 , V_21 ,
V_9 , V_22 , V_23 , V_24 ) ;
if ( V_29 )
return V_29 ;
F_19 ( 1 , L_4
L_5 ) ;
}
return F_11 ( V_20 , V_21 , V_9 , V_22 , V_23 ,
V_24 ) ;
}
T_3 T_2 F_20 ( T_3 V_20 ,
T_3 V_21 , T_3 V_9 ,
T_3 V_22 )
{
T_3 V_29 ;
T_1 V_24 = F_1 () ;
V_35:
V_29 = F_14 ( V_9 , V_22 , V_20 , V_21 ,
V_36 , V_24 ) ;
if ( ! V_29 && ( V_24 & V_2 ) ) {
F_21 ( L_6 ,
& V_9 ) ;
V_24 &= ~ V_2 ;
goto V_35;
}
return V_29 ;
}
static void T_2 F_22 ( struct V_4 * type , unsigned long V_37 )
{
type -> V_38 -= type -> V_18 [ V_37 ] . V_9 ;
memmove ( & type -> V_18 [ V_37 ] , & type -> V_18 [ V_37 + 1 ] ,
( type -> V_16 - ( V_37 + 1 ) ) * sizeof( type -> V_18 [ V_37 ] ) ) ;
type -> V_16 -- ;
if ( type -> V_16 == 0 ) {
F_23 ( type -> V_38 != 0 ) ;
type -> V_16 = 1 ;
type -> V_18 [ 0 ] . V_8 = 0 ;
type -> V_18 [ 0 ] . V_9 = 0 ;
type -> V_18 [ 0 ] . V_24 = 0 ;
F_24 ( & type -> V_18 [ 0 ] , V_39 ) ;
}
}
T_3 T_2 F_25 (
T_3 * V_40 )
{
if ( V_5 . V_7 . V_18 == V_41 )
return 0 ;
* V_40 = F_26 ( V_5 . V_7 . V_18 ) ;
return F_27 ( sizeof( struct V_42 ) *
V_5 . V_7 . F_16 ) ;
}
T_3 T_2 F_28 (
T_3 * V_40 )
{
if ( V_5 . V_6 . V_18 == V_43 )
return 0 ;
* V_40 = F_26 ( V_5 . V_6 . V_18 ) ;
return F_27 ( sizeof( struct V_42 ) *
V_5 . V_6 . F_16 ) ;
}
static int T_2 F_29 ( struct V_4 * type ,
T_3 V_44 ,
T_3 V_45 )
{
struct V_42 * V_46 , * V_47 ;
T_3 V_48 , V_49 ;
T_3 V_50 , V_51 , V_40 ;
int V_52 = F_30 () ;
int * V_53 ;
if ( ! V_54 )
return - 1 ;
V_50 = type -> F_16 * sizeof( struct V_42 ) ;
V_51 = V_50 << 1 ;
V_48 = F_27 ( V_50 ) ;
V_49 = F_27 ( V_51 ) ;
if ( type == & V_5 . V_6 )
V_53 = & V_55 ;
else
V_53 = & V_56 ;
if ( V_52 ) {
V_46 = F_31 ( V_51 , V_57 ) ;
V_40 = V_46 ? F_26 ( V_46 ) : 0 ;
} else {
if ( type != & V_5 . V_7 )
V_44 = V_45 = 0 ;
V_40 = F_20 ( V_44 + V_45 ,
V_5 . V_31 ,
V_49 , V_32 ) ;
if ( ! V_40 && V_45 )
V_40 = F_20 ( 0 ,
F_4 ( V_44 , V_5 . V_31 ) ,
V_49 , V_32 ) ;
V_46 = V_40 ? F_32 ( V_40 ) : NULL ;
}
if ( ! V_40 ) {
F_33 ( L_7 ,
F_2 ( type ) , type -> F_16 , type -> F_16 * 2 ) ;
return - 1 ;
}
F_34 ( L_8 ,
F_2 ( type ) , type -> F_16 * 2 , ( T_4 ) V_40 ,
( T_4 ) V_40 + V_51 - 1 ) ;
memcpy ( V_46 , type -> V_18 , V_50 ) ;
memset ( V_46 + type -> F_16 , 0 , V_50 ) ;
V_47 = type -> V_18 ;
type -> V_18 = V_46 ;
type -> F_16 <<= 1 ;
if ( * V_53 )
F_35 ( V_47 ) ;
else if ( V_47 != V_43 &&
V_47 != V_41 )
F_36 ( F_26 ( V_47 ) , V_48 ) ;
if ( ! V_52 )
F_37 ( F_38 ( V_40 , V_49 ) ) ;
* V_53 = V_52 ;
return 0 ;
}
static void T_2 F_39 ( struct V_4 * type )
{
int V_15 = 0 ;
while ( V_15 < type -> V_16 - 1 ) {
struct V_42 * V_58 = & type -> V_18 [ V_15 ] ;
struct V_42 * V_59 = & type -> V_18 [ V_15 + 1 ] ;
if ( V_58 -> V_8 + V_58 -> V_9 != V_59 -> V_8 ||
F_40 ( V_58 ) !=
F_40 ( V_59 ) ||
V_58 -> V_24 != V_59 -> V_24 ) {
F_37 ( V_58 -> V_8 + V_58 -> V_9 > V_59 -> V_8 ) ;
V_15 ++ ;
continue;
}
V_58 -> V_9 += V_59 -> V_9 ;
memmove ( V_59 , V_59 + 1 , ( type -> V_16 - ( V_15 + 2 ) ) * sizeof( * V_59 ) ) ;
type -> V_16 -- ;
}
}
static void T_2 F_41 ( struct V_4 * type ,
int V_60 , T_3 V_8 ,
T_3 V_9 ,
int V_23 , unsigned long V_24 )
{
struct V_42 * V_61 = & type -> V_18 [ V_60 ] ;
F_37 ( type -> V_16 >= type -> F_16 ) ;
memmove ( V_61 + 1 , V_61 , ( type -> V_16 - V_60 ) * sizeof( * V_61 ) ) ;
V_61 -> V_8 = V_8 ;
V_61 -> V_9 = V_9 ;
V_61 -> V_24 = V_24 ;
F_24 ( V_61 , V_23 ) ;
type -> V_16 ++ ;
type -> V_38 += V_9 ;
}
int T_2 F_42 ( struct V_4 * type ,
T_3 V_8 , T_3 V_9 ,
int V_23 , unsigned long V_24 )
{
bool V_62 = false ;
T_3 V_63 = V_8 ;
T_3 V_21 = V_8 + F_3 ( V_8 , & V_9 ) ;
int V_15 , V_64 ;
if ( ! V_9 )
return 0 ;
if ( type -> V_18 [ 0 ] . V_9 == 0 ) {
F_23 ( type -> V_16 != 1 || type -> V_38 ) ;
type -> V_18 [ 0 ] . V_8 = V_8 ;
type -> V_18 [ 0 ] . V_9 = V_9 ;
type -> V_18 [ 0 ] . V_24 = V_24 ;
F_24 ( & type -> V_18 [ 0 ] , V_23 ) ;
type -> V_38 = V_9 ;
return 0 ;
}
V_65:
V_8 = V_63 ;
V_64 = 0 ;
for ( V_15 = 0 ; V_15 < type -> V_16 ; V_15 ++ ) {
struct V_42 * V_61 = & type -> V_18 [ V_15 ] ;
T_3 V_66 = V_61 -> V_8 ;
T_3 V_67 = V_66 + V_61 -> V_9 ;
if ( V_66 >= V_21 )
break;
if ( V_67 <= V_8 )
continue;
if ( V_66 > V_8 ) {
V_64 ++ ;
if ( V_62 )
F_41 ( type , V_15 ++ , V_8 ,
V_66 - V_8 , V_23 ,
V_24 ) ;
}
V_8 = F_4 ( V_67 , V_21 ) ;
}
if ( V_8 < V_21 ) {
V_64 ++ ;
if ( V_62 )
F_41 ( type , V_15 , V_8 , V_21 - V_8 ,
V_23 , V_24 ) ;
}
if ( ! V_62 ) {
while ( type -> V_16 + V_64 > type -> F_16 )
if ( F_29 ( type , V_63 , V_9 ) < 0 )
return - V_68 ;
V_62 = true ;
goto V_65;
} else {
F_39 ( type ) ;
return 0 ;
}
}
int T_2 F_43 ( T_3 V_8 , T_3 V_9 ,
int V_23 )
{
return F_42 ( & V_5 . V_6 , V_8 , V_9 , V_23 , 0 ) ;
}
static int T_2 F_44 ( T_3 V_8 ,
T_3 V_9 ,
int V_23 ,
unsigned long V_24 )
{
struct V_4 * V_69 = & V_5 . V_6 ;
F_34 ( L_9 ,
( unsigned long long ) V_8 ,
( unsigned long long ) V_8 + V_9 - 1 ,
V_24 , ( void * ) V_70 ) ;
return F_42 ( V_69 , V_8 , V_9 , V_23 , V_24 ) ;
}
int T_2 F_45 ( T_3 V_8 , T_3 V_9 )
{
return F_44 ( V_8 , V_9 , V_39 , 0 ) ;
}
static int T_2 F_46 ( struct V_4 * type ,
T_3 V_8 , T_3 V_9 ,
int * V_71 , int * V_72 )
{
T_3 V_21 = V_8 + F_3 ( V_8 , & V_9 ) ;
int V_15 ;
* V_71 = * V_72 = 0 ;
if ( ! V_9 )
return 0 ;
while ( type -> V_16 + 2 > type -> F_16 )
if ( F_29 ( type , V_8 , V_9 ) < 0 )
return - V_68 ;
for ( V_15 = 0 ; V_15 < type -> V_16 ; V_15 ++ ) {
struct V_42 * V_61 = & type -> V_18 [ V_15 ] ;
T_3 V_66 = V_61 -> V_8 ;
T_3 V_67 = V_66 + V_61 -> V_9 ;
if ( V_66 >= V_21 )
break;
if ( V_67 <= V_8 )
continue;
if ( V_66 < V_8 ) {
V_61 -> V_8 = V_8 ;
V_61 -> V_9 -= V_8 - V_66 ;
type -> V_38 -= V_8 - V_66 ;
F_41 ( type , V_15 , V_66 , V_8 - V_66 ,
F_40 ( V_61 ) ,
V_61 -> V_24 ) ;
} else if ( V_67 > V_21 ) {
V_61 -> V_8 = V_21 ;
V_61 -> V_9 -= V_21 - V_66 ;
type -> V_38 -= V_21 - V_66 ;
F_41 ( type , V_15 -- , V_66 , V_21 - V_66 ,
F_40 ( V_61 ) ,
V_61 -> V_24 ) ;
} else {
if ( ! * V_72 )
* V_71 = V_15 ;
* V_72 = V_15 + 1 ;
}
}
return 0 ;
}
int T_2 F_47 ( struct V_4 * type ,
T_3 V_8 , T_3 V_9 )
{
int V_71 , V_72 ;
int V_15 , V_29 ;
V_29 = F_46 ( type , V_8 , V_9 , & V_71 , & V_72 ) ;
if ( V_29 )
return V_29 ;
for ( V_15 = V_72 - 1 ; V_15 >= V_71 ; V_15 -- )
F_22 ( type , V_15 ) ;
return 0 ;
}
int T_2 F_48 ( T_3 V_8 , T_3 V_9 )
{
return F_47 ( & V_5 . V_6 , V_8 , V_9 ) ;
}
int T_2 F_36 ( T_3 V_8 , T_3 V_9 )
{
F_34 ( L_10 ,
( unsigned long long ) V_8 ,
( unsigned long long ) V_8 + V_9 - 1 ,
( void * ) V_70 ) ;
F_49 ( F_32 ( V_8 ) , V_9 ) ;
return F_47 ( & V_5 . V_7 , V_8 , V_9 ) ;
}
static int T_2 F_50 ( T_3 V_8 ,
T_3 V_9 ,
int V_23 ,
unsigned long V_24 )
{
struct V_4 * type = & V_5 . V_7 ;
F_34 ( L_11 ,
( unsigned long long ) V_8 ,
( unsigned long long ) V_8 + V_9 - 1 ,
V_24 , ( void * ) V_70 ) ;
return F_42 ( type , V_8 , V_9 , V_23 , V_24 ) ;
}
int T_2 F_38 ( T_3 V_8 , T_3 V_9 )
{
return F_50 ( V_8 , V_9 , V_39 , 0 ) ;
}
static int T_2 F_51 ( T_3 V_8 ,
T_3 V_9 , int V_73 , int V_74 )
{
struct V_4 * type = & V_5 . V_6 ;
int V_15 , V_29 , V_71 , V_72 ;
V_29 = F_46 ( type , V_8 , V_9 , & V_71 , & V_72 ) ;
if ( V_29 )
return V_29 ;
for ( V_15 = V_71 ; V_15 < V_72 ; V_15 ++ )
if ( V_73 )
F_52 ( & type -> V_18 [ V_15 ] , V_74 ) ;
else
F_53 ( & type -> V_18 [ V_15 ] , V_74 ) ;
F_39 ( type ) ;
return 0 ;
}
int T_2 F_54 ( T_3 V_8 , T_3 V_9 )
{
return F_51 ( V_8 , V_9 , 1 , V_75 ) ;
}
int T_2 F_55 ( T_3 V_8 , T_3 V_9 )
{
return F_51 ( V_8 , V_9 , 0 , V_75 ) ;
}
int T_2 F_56 ( T_3 V_8 , T_3 V_9 )
{
V_1 = true ;
return F_51 ( V_8 , V_9 , 1 , V_2 ) ;
}
void T_2 F_57 ( T_4 * V_60 ,
T_3 * V_76 ,
T_3 * V_77 )
{
struct V_4 * V_78 = & V_5 . V_7 ;
if ( * V_60 >= 0 && * V_60 < V_78 -> V_16 ) {
struct V_42 * V_37 = & V_78 -> V_18 [ * V_60 ] ;
T_3 V_8 = V_37 -> V_8 ;
T_3 V_9 = V_37 -> V_9 ;
if ( V_76 )
* V_76 = V_8 ;
if ( V_77 )
* V_77 = V_8 + V_9 - 1 ;
* V_60 += 1 ;
return;
}
* V_60 = V_10 ;
}
void T_2 F_58 ( T_4 * V_60 , int V_23 , T_1 V_24 ,
struct V_4 * V_79 ,
struct V_4 * V_80 ,
T_3 * V_76 ,
T_3 * V_77 , int * V_81 )
{
int V_82 = * V_60 & 0xffffffff ;
int V_83 = * V_60 >> 32 ;
if ( F_19 ( V_23 == V_39 ,
L_12 ) )
V_23 = V_36 ;
for (; V_82 < V_79 -> V_16 ; V_82 ++ ) {
struct V_42 * V_84 = & V_79 -> V_18 [ V_82 ] ;
T_3 V_85 = V_84 -> V_8 ;
T_3 V_86 = V_84 -> V_8 + V_84 -> V_9 ;
int V_87 = F_40 ( V_84 ) ;
if ( V_23 != V_36 && V_23 != V_87 )
continue;
if ( F_59 () && F_60 ( V_84 ) )
continue;
if ( ( V_24 & V_2 ) && ! F_61 ( V_84 ) )
continue;
if ( ! V_80 ) {
if ( V_76 )
* V_76 = V_85 ;
if ( V_77 )
* V_77 = V_86 ;
if ( V_81 )
* V_81 = V_87 ;
V_82 ++ ;
* V_60 = ( V_88 ) V_82 | ( T_4 ) V_83 << 32 ;
return;
}
for (; V_83 < V_80 -> V_16 + 1 ; V_83 ++ ) {
struct V_42 * V_37 ;
T_3 V_89 ;
T_3 V_90 ;
V_37 = & V_80 -> V_18 [ V_83 ] ;
V_89 = V_83 ? V_37 [ - 1 ] . V_8 + V_37 [ - 1 ] . V_9 : 0 ;
V_90 = V_83 < V_80 -> V_16 ?
V_37 -> V_8 : V_10 ;
if ( V_89 >= V_86 )
break;
if ( V_85 < V_90 ) {
if ( V_76 )
* V_76 =
F_16 ( V_85 , V_89 ) ;
if ( V_77 )
* V_77 = F_4 ( V_86 , V_90 ) ;
if ( V_81 )
* V_81 = V_87 ;
if ( V_86 <= V_90 )
V_82 ++ ;
else
V_83 ++ ;
* V_60 = ( V_88 ) V_82 | ( T_4 ) V_83 << 32 ;
return;
}
}
}
* V_60 = V_10 ;
}
void T_2 F_62 ( T_4 * V_60 , int V_23 , T_1 V_24 ,
struct V_4 * V_79 ,
struct V_4 * V_80 ,
T_3 * V_76 ,
T_3 * V_77 , int * V_81 )
{
int V_82 = * V_60 & 0xffffffff ;
int V_83 = * V_60 >> 32 ;
if ( F_19 ( V_23 == V_39 , L_12 ) )
V_23 = V_36 ;
if ( * V_60 == ( T_4 ) V_10 ) {
V_82 = V_79 -> V_16 - 1 ;
V_83 = V_80 -> V_16 ;
}
for (; V_82 >= 0 ; V_82 -- ) {
struct V_42 * V_84 = & V_79 -> V_18 [ V_82 ] ;
T_3 V_85 = V_84 -> V_8 ;
T_3 V_86 = V_84 -> V_8 + V_84 -> V_9 ;
int V_87 = F_40 ( V_84 ) ;
if ( V_23 != V_36 && V_23 != V_87 )
continue;
if ( F_59 () && F_60 ( V_84 ) )
continue;
if ( ( V_24 & V_2 ) && ! F_61 ( V_84 ) )
continue;
if ( ! V_80 ) {
if ( V_76 )
* V_76 = V_85 ;
if ( V_77 )
* V_77 = V_86 ;
if ( V_81 )
* V_81 = V_87 ;
V_82 ++ ;
* V_60 = ( V_88 ) V_82 | ( T_4 ) V_83 << 32 ;
return;
}
for (; V_83 >= 0 ; V_83 -- ) {
struct V_42 * V_37 ;
T_3 V_89 ;
T_3 V_90 ;
V_37 = & V_80 -> V_18 [ V_83 ] ;
V_89 = V_83 ? V_37 [ - 1 ] . V_8 + V_37 [ - 1 ] . V_9 : 0 ;
V_90 = V_83 < V_80 -> V_16 ?
V_37 -> V_8 : V_10 ;
if ( V_90 <= V_85 )
break;
if ( V_86 > V_89 ) {
if ( V_76 )
* V_76 = F_16 ( V_85 , V_89 ) ;
if ( V_77 )
* V_77 = F_4 ( V_86 , V_90 ) ;
if ( V_81 )
* V_81 = V_87 ;
if ( V_85 >= V_89 )
V_82 -- ;
else
V_83 -- ;
* V_60 = ( V_88 ) V_82 | ( T_4 ) V_83 << 32 ;
return;
}
}
}
* V_60 = V_10 ;
}
void T_2 F_63 ( int * V_60 , int V_23 ,
unsigned long * V_91 ,
unsigned long * V_92 , int * V_81 )
{
struct V_4 * type = & V_5 . V_6 ;
struct V_42 * V_37 ;
while ( ++ * V_60 < type -> V_16 ) {
V_37 = & type -> V_18 [ * V_60 ] ;
if ( F_64 ( V_37 -> V_8 ) >= F_65 ( V_37 -> V_8 + V_37 -> V_9 ) )
continue;
if ( V_23 == V_39 || V_23 == V_37 -> V_23 )
break;
}
if ( * V_60 >= type -> V_16 ) {
* V_60 = - 1 ;
return;
}
if ( V_91 )
* V_91 = F_64 ( V_37 -> V_8 ) ;
if ( V_92 )
* V_92 = F_65 ( V_37 -> V_8 + V_37 -> V_9 ) ;
if ( V_81 )
* V_81 = V_37 -> V_23 ;
}
int T_2 F_66 ( T_3 V_8 , T_3 V_9 ,
struct V_4 * type , int V_23 )
{
int V_71 , V_72 ;
int V_15 , V_29 ;
V_29 = F_46 ( type , V_8 , V_9 , & V_71 , & V_72 ) ;
if ( V_29 )
return V_29 ;
for ( V_15 = V_71 ; V_15 < V_72 ; V_15 ++ )
F_24 ( & type -> V_18 [ V_15 ] , V_23 ) ;
F_39 ( type ) ;
return 0 ;
}
static T_3 T_5 F_67 ( T_3 V_9 ,
T_3 V_22 , T_3 V_20 ,
T_3 V_21 , int V_23 , T_1 V_24 )
{
T_3 V_93 ;
if ( ! V_22 )
V_22 = V_94 ;
V_93 = F_14 ( V_9 , V_22 , V_20 , V_21 , V_23 ,
V_24 ) ;
if ( V_93 && ! F_38 ( V_93 , V_9 ) ) {
F_68 ( F_32 ( V_93 ) , V_9 , 0 , 0 ) ;
return V_93 ;
}
return 0 ;
}
T_3 T_5 F_69 ( T_3 V_9 , T_3 V_22 ,
T_3 V_20 , T_3 V_21 ,
T_1 V_24 )
{
return F_67 ( V_9 , V_22 , V_20 , V_21 , V_36 ,
V_24 ) ;
}
static T_3 T_5 F_70 ( T_3 V_9 ,
T_3 V_22 , T_3 V_95 ,
int V_23 , T_1 V_24 )
{
return F_67 ( V_9 , V_22 , 0 , V_95 , V_23 , V_24 ) ;
}
T_3 T_5 F_71 ( T_3 V_9 , T_3 V_22 , int V_23 )
{
T_1 V_24 = F_1 () ;
T_3 V_29 ;
V_35:
V_29 = F_70 ( V_9 , V_22 , V_30 ,
V_23 , V_24 ) ;
if ( ! V_29 && ( V_24 & V_2 ) ) {
V_24 &= ~ V_2 ;
goto V_35;
}
return V_29 ;
}
T_3 T_5 F_72 ( T_3 V_9 , T_3 V_22 , T_3 V_95 )
{
return F_70 ( V_9 , V_22 , V_95 , V_36 ,
V_3 ) ;
}
T_3 T_5 F_73 ( T_3 V_9 , T_3 V_22 , T_3 V_95 )
{
T_3 V_96 ;
V_96 = F_72 ( V_9 , V_22 , V_95 ) ;
if ( V_96 == 0 )
F_74 ( L_13 ,
( unsigned long long ) V_9 , ( unsigned long long ) V_95 ) ;
return V_96 ;
}
T_3 T_5 F_75 ( T_3 V_9 , T_3 V_22 )
{
return F_73 ( V_9 , V_22 , V_30 ) ;
}
T_3 T_5 F_76 ( T_3 V_9 , T_3 V_22 , int V_23 )
{
T_3 V_97 = F_71 ( V_9 , V_22 , V_23 ) ;
if ( V_97 )
return V_97 ;
return F_73 ( V_9 , V_22 , V_30 ) ;
}
static void * T_5 F_77 (
T_3 V_9 , T_3 V_22 ,
T_3 V_98 , T_3 V_95 ,
int V_23 )
{
T_3 V_96 ;
void * V_99 ;
T_1 V_24 = F_1 () ;
if ( F_19 ( V_23 == V_39 , L_12 ) )
V_23 = V_36 ;
if ( F_78 ( F_30 () ) )
return F_79 ( V_9 , V_100 , V_23 ) ;
if ( ! V_22 )
V_22 = V_94 ;
if ( V_95 > V_5 . V_31 )
V_95 = V_5 . V_31 ;
V_35:
V_96 = F_14 ( V_9 , V_22 , V_98 , V_95 ,
V_23 , V_24 ) ;
if ( V_96 )
goto V_101;
if ( V_23 != V_36 ) {
V_96 = F_14 ( V_9 , V_22 , V_98 ,
V_95 , V_36 ,
V_24 ) ;
if ( V_96 )
goto V_101;
}
if ( V_98 ) {
V_98 = 0 ;
goto V_35;
}
if ( V_24 & V_2 ) {
V_24 &= ~ V_2 ;
F_21 ( L_6 ,
& V_9 ) ;
goto V_35;
}
return NULL ;
V_101:
F_38 ( V_96 , V_9 ) ;
V_99 = F_80 ( V_96 ) ;
memset ( V_99 , 0 , V_9 ) ;
F_68 ( V_99 , V_9 , 0 , 0 ) ;
return V_99 ;
}
void * T_5 F_81 (
T_3 V_9 , T_3 V_22 ,
T_3 V_98 , T_3 V_95 ,
int V_23 )
{
F_34 ( L_14 ,
V_102 , ( T_4 ) V_9 , ( T_4 ) V_22 , V_23 , ( T_4 ) V_98 ,
( T_4 ) V_95 , ( void * ) V_70 ) ;
return F_77 ( V_9 , V_22 , V_98 ,
V_95 , V_23 ) ;
}
void * T_5 F_82 (
T_3 V_9 , T_3 V_22 ,
T_3 V_98 , T_3 V_95 ,
int V_23 )
{
void * V_99 ;
F_34 ( L_14 ,
V_102 , ( T_4 ) V_9 , ( T_4 ) V_22 , V_23 , ( T_4 ) V_98 ,
( T_4 ) V_95 , ( void * ) V_70 ) ;
V_99 = F_77 ( V_9 , V_22 ,
V_98 , V_95 , V_23 ) ;
if ( V_99 )
return V_99 ;
F_74 ( L_15 ,
V_102 , ( T_4 ) V_9 , ( T_4 ) V_22 , V_23 , ( T_4 ) V_98 ,
( T_4 ) V_95 ) ;
return NULL ;
}
void T_5 F_83 ( T_3 V_8 , T_3 V_9 )
{
F_34 ( L_16 ,
V_102 , ( T_4 ) V_8 , ( T_4 ) V_8 + V_9 - 1 ,
( void * ) V_70 ) ;
F_49 ( F_32 ( V_8 ) , V_9 ) ;
F_47 ( & V_5 . V_7 , V_8 , V_9 ) ;
}
void T_5 F_84 ( T_3 V_8 , T_3 V_9 )
{
T_4 V_103 , V_21 ;
F_34 ( L_16 ,
V_102 , ( T_4 ) V_8 , ( T_4 ) V_8 + V_9 - 1 ,
( void * ) V_70 ) ;
F_49 ( F_32 ( V_8 ) , V_9 ) ;
V_103 = F_64 ( V_8 ) ;
V_21 = F_65 ( V_8 + V_9 ) ;
for (; V_103 < V_21 ; V_103 ++ ) {
F_85 ( F_86 ( V_103 ) , V_103 , 0 ) ;
V_104 ++ ;
}
}
T_3 T_5 F_87 ( void )
{
return V_5 . V_6 . V_38 ;
}
T_3 T_5 F_88 ( unsigned long V_105 )
{
unsigned long V_106 = 0 ;
struct V_42 * V_37 ;
unsigned long V_107 , V_108 ;
F_89 (memory, r) {
V_107 = F_90 ( V_37 ) ;
V_108 = F_91 ( V_37 ) ;
V_107 = F_92 (unsigned long, start_pfn, limit_pfn) ;
V_108 = F_92 (unsigned long, end_pfn, limit_pfn) ;
V_106 += V_108 - V_107 ;
}
return F_93 ( V_106 ) ;
}
T_3 T_2 F_94 ( void )
{
return V_5 . V_6 . V_18 [ 0 ] . V_8 ;
}
T_3 T_2 F_95 ( void )
{
int V_60 = V_5 . V_6 . V_16 - 1 ;
return ( V_5 . V_6 . V_18 [ V_60 ] . V_8 + V_5 . V_6 . V_18 [ V_60 ] . V_9 ) ;
}
void T_5 F_96 ( T_3 V_109 )
{
T_3 V_95 = ( T_3 ) V_10 ;
struct V_42 * V_37 ;
if ( ! V_109 )
return;
F_89 (memory, r) {
if ( V_109 <= V_37 -> V_9 ) {
V_95 = V_37 -> V_8 + V_109 ;
break;
}
V_109 -= V_37 -> V_9 ;
}
F_47 ( & V_5 . V_6 , V_95 ,
( T_3 ) V_10 ) ;
F_47 ( & V_5 . V_7 , V_95 ,
( T_3 ) V_10 ) ;
}
static int T_2 F_97 ( struct V_4 * type , T_3 V_40 )
{
unsigned int V_110 = 0 , V_111 = type -> V_16 ;
do {
unsigned int V_112 = ( V_111 + V_110 ) / 2 ;
if ( V_40 < type -> V_18 [ V_112 ] . V_8 )
V_111 = V_112 ;
else if ( V_40 >= ( type -> V_18 [ V_112 ] . V_8 +
type -> V_18 [ V_112 ] . V_9 ) )
V_110 = V_112 + 1 ;
else
return V_112 ;
} while ( V_110 < V_111 );
return - 1 ;
}
int T_5 F_98 ( T_3 V_40 )
{
return F_97 ( & V_5 . V_7 , V_40 ) != - 1 ;
}
int T_2 F_99 ( T_3 V_40 )
{
return F_97 ( & V_5 . V_6 , V_40 ) != - 1 ;
}
int T_2 F_100 ( unsigned long V_113 ,
unsigned long * V_107 , unsigned long * V_108 )
{
struct V_4 * type = & V_5 . V_6 ;
int V_112 = F_97 ( type , F_93 ( V_113 ) ) ;
if ( V_112 == - 1 )
return - 1 ;
* V_107 = F_65 ( type -> V_18 [ V_112 ] . V_8 ) ;
* V_108 = F_65 ( type -> V_18 [ V_112 ] . V_8 + type -> V_18 [ V_112 ] . V_9 ) ;
return type -> V_18 [ V_112 ] . V_23 ;
}
int T_2 F_101 ( T_3 V_8 , T_3 V_9 )
{
int V_60 = F_97 ( & V_5 . V_6 , V_8 ) ;
T_3 V_21 = V_8 + F_3 ( V_8 , & V_9 ) ;
if ( V_60 == - 1 )
return 0 ;
return V_5 . V_6 . V_18 [ V_60 ] . V_8 <= V_8 &&
( V_5 . V_6 . V_18 [ V_60 ] . V_8 +
V_5 . V_6 . V_18 [ V_60 ] . V_9 ) >= V_21 ;
}
int T_2 F_102 ( T_3 V_8 , T_3 V_9 )
{
F_3 ( V_8 , & V_9 ) ;
return F_6 ( & V_5 . V_7 , V_8 , V_9 ) >= 0 ;
}
void T_2 F_103 ( T_3 V_22 )
{
T_3 V_20 , V_21 , V_114 , V_115 ;
struct V_42 * V_37 ;
F_89 (memory, r) {
V_114 = V_37 -> V_8 ;
V_115 = V_37 -> V_8 + V_37 -> V_9 ;
V_20 = F_10 ( V_114 , V_22 ) ;
V_21 = F_13 ( V_115 , V_22 ) ;
if ( V_20 == V_114 && V_21 == V_115 )
continue;
if ( V_20 < V_21 ) {
V_37 -> V_8 = V_20 ;
V_37 -> V_9 = V_21 - V_20 ;
} else {
F_22 ( & V_5 . V_6 ,
V_37 - V_5 . V_6 . V_18 ) ;
V_37 -- ;
}
}
}
void T_2 F_104 ( T_3 V_109 )
{
V_5 . V_31 = V_109 ;
}
T_3 T_2 F_105 ( void )
{
return V_5 . V_31 ;
}
static void T_2 F_106 ( struct V_4 * type , char * V_116 )
{
unsigned long long V_8 , V_9 ;
unsigned long V_24 ;
int V_15 ;
F_107 ( L_17 , V_116 , type -> V_16 ) ;
for ( V_15 = 0 ; V_15 < type -> V_16 ; V_15 ++ ) {
struct V_42 * V_61 = & type -> V_18 [ V_15 ] ;
char V_117 [ 32 ] = L_18 ;
V_8 = V_61 -> V_8 ;
V_9 = V_61 -> V_9 ;
V_24 = V_61 -> V_24 ;
#ifdef F_108
if ( F_40 ( V_61 ) != V_39 )
snprintf ( V_117 , sizeof( V_117 ) , L_19 ,
F_40 ( V_61 ) ) ;
#endif
F_107 ( L_20 ,
V_116 , V_15 , V_8 , V_8 + V_9 - 1 , V_9 , V_117 , V_24 ) ;
}
}
void T_2 F_109 ( void )
{
F_107 ( L_21 ) ;
F_107 ( L_22 ,
( unsigned long long ) V_5 . V_6 . V_38 ,
( unsigned long long ) V_5 . V_7 . V_38 ) ;
F_106 ( & V_5 . V_6 , L_1 ) ;
F_106 ( & V_5 . V_7 , L_2 ) ;
}
void T_5 F_110 ( void )
{
V_54 = 1 ;
}
static int T_5 F_111 ( char * V_118 )
{
if ( V_118 && strstr ( V_118 , L_23 ) )
V_119 = 1 ;
return 0 ;
}
static int F_112 ( struct V_120 * V_84 , void * V_121 )
{
struct V_4 * type = V_84 -> V_121 ;
struct V_42 * V_122 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < type -> V_16 ; V_15 ++ ) {
V_122 = & type -> V_18 [ V_15 ] ;
F_113 ( V_84 , L_24 , V_15 ) ;
if ( sizeof( T_3 ) == 4 )
F_113 ( V_84 , L_25 ,
( unsigned long ) V_122 -> V_8 ,
( unsigned long ) ( V_122 -> V_8 + V_122 -> V_9 - 1 ) ) ;
else
F_113 ( V_84 , L_26 ,
( unsigned long long ) V_122 -> V_8 ,
( unsigned long long ) ( V_122 -> V_8 + V_122 -> V_9 - 1 ) ) ;
}
return 0 ;
}
static int F_114 ( struct V_123 * V_123 , struct V_124 * V_124 )
{
return F_115 ( V_124 , F_112 , V_123 -> V_125 ) ;
}
static int T_5 F_116 ( void )
{
struct V_126 * V_127 = F_117 ( L_27 , NULL ) ;
if ( ! V_127 )
return - V_128 ;
F_118 ( L_1 , V_129 , V_127 , & V_5 . V_6 , & V_130 ) ;
F_118 ( L_2 , V_129 , V_127 , & V_5 . V_7 , & V_130 ) ;
#ifdef F_119
F_118 ( L_28 , V_129 , V_127 , & V_5 . V_131 , & V_130 ) ;
#endif
return 0 ;
}
