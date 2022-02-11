T_1 T_2 F_1 ( void )
{
return V_1 ? V_2 : V_3 ;
}
static inline T_3 F_2 ( T_3 V_4 , T_3 * V_5 )
{
return * V_5 = F_3 ( * V_5 , ( T_3 ) V_6 - V_4 ) ;
}
static unsigned long T_2 F_4 ( T_3 V_7 , T_3 V_8 ,
T_3 V_9 , T_3 V_10 )
{
return ( ( V_7 < ( V_9 + V_10 ) ) && ( V_9 < ( V_7 + V_8 ) ) ) ;
}
bool T_2 F_5 ( struct V_11 * type ,
T_3 V_4 , T_3 V_5 )
{
unsigned long V_12 ;
for ( V_12 = 0 ; V_12 < type -> V_13 ; V_12 ++ )
if ( F_4 ( V_4 , V_5 , type -> V_14 [ V_12 ] . V_4 ,
type -> V_14 [ V_12 ] . V_5 ) )
break;
return V_12 < type -> V_13 ;
}
static T_3 T_2
F_6 ( T_3 V_15 , T_3 V_16 ,
T_3 V_5 , T_3 V_17 , int V_18 ,
T_1 V_19 )
{
T_3 V_20 , V_21 , V_22 ;
T_4 V_12 ;
F_7 (i, nid, flags, &this_start, &this_end, NULL) {
V_20 = F_8 ( V_20 , V_15 , V_16 ) ;
V_21 = F_8 ( V_21 , V_15 , V_16 ) ;
V_22 = F_9 ( V_20 , V_17 ) ;
if ( V_22 < V_21 && V_21 - V_22 >= V_5 )
return V_22 ;
}
return 0 ;
}
static T_3 T_2
F_10 ( T_3 V_15 , T_3 V_16 ,
T_3 V_5 , T_3 V_17 , int V_18 ,
T_1 V_19 )
{
T_3 V_20 , V_21 , V_22 ;
T_4 V_12 ;
F_11 (i, nid, flags, &this_start, &this_end,
NULL) {
V_20 = F_8 ( V_20 , V_15 , V_16 ) ;
V_21 = F_8 ( V_21 , V_15 , V_16 ) ;
if ( V_21 < V_5 )
continue;
V_22 = F_12 ( V_21 - V_5 , V_17 ) ;
if ( V_22 >= V_20 )
return V_22 ;
}
return 0 ;
}
T_3 T_2 F_13 ( T_3 V_5 ,
T_3 V_17 , T_3 V_15 ,
T_3 V_16 , int V_18 , T_1 V_19 )
{
T_3 V_23 , V_24 ;
if ( V_16 == V_25 )
V_16 = V_26 . V_27 ;
V_15 = F_14 ( T_3 , V_15 , V_28 ) ;
V_16 = F_15 ( V_15 , V_16 ) ;
V_23 = F_16 ( V_29 ) ;
if ( F_17 () && V_16 > V_23 ) {
T_3 V_30 ;
V_30 = F_15 ( V_15 , V_23 ) ;
V_24 = F_6 ( V_30 , V_16 ,
V_5 , V_17 , V_18 , V_19 ) ;
if ( V_24 )
return V_24 ;
F_18 ( 1 , L_1 ) ;
}
return F_10 ( V_15 , V_16 , V_5 , V_17 , V_18 ,
V_19 ) ;
}
T_3 T_2 F_19 ( T_3 V_15 ,
T_3 V_16 , T_3 V_5 ,
T_3 V_17 )
{
T_3 V_24 ;
T_1 V_19 = F_1 () ;
V_31:
V_24 = F_13 ( V_5 , V_17 , V_15 , V_16 ,
V_32 , V_19 ) ;
if ( ! V_24 && ( V_19 & V_2 ) ) {
F_20 ( L_2 ,
& V_5 ) ;
V_19 &= ~ V_2 ;
goto V_31;
}
return V_24 ;
}
static void T_2 F_21 ( struct V_11 * type , unsigned long V_33 )
{
type -> V_34 -= type -> V_14 [ V_33 ] . V_5 ;
memmove ( & type -> V_14 [ V_33 ] , & type -> V_14 [ V_33 + 1 ] ,
( type -> V_13 - ( V_33 + 1 ) ) * sizeof( type -> V_14 [ V_33 ] ) ) ;
type -> V_13 -- ;
if ( type -> V_13 == 0 ) {
F_22 ( type -> V_34 != 0 ) ;
type -> V_13 = 1 ;
type -> V_14 [ 0 ] . V_4 = 0 ;
type -> V_14 [ 0 ] . V_5 = 0 ;
type -> V_14 [ 0 ] . V_19 = 0 ;
F_23 ( & type -> V_14 [ 0 ] , V_35 ) ;
}
}
T_3 T_2 F_24 (
T_3 * V_36 )
{
if ( V_26 . V_37 . V_14 == V_38 )
return 0 ;
* V_36 = F_25 ( V_26 . V_37 . V_14 ) ;
return F_26 ( sizeof( struct V_39 ) *
V_26 . V_37 . F_15 ) ;
}
T_3 T_2 F_27 (
T_3 * V_36 )
{
if ( V_26 . V_40 . V_14 == V_41 )
return 0 ;
* V_36 = F_25 ( V_26 . V_40 . V_14 ) ;
return F_26 ( sizeof( struct V_39 ) *
V_26 . V_40 . F_15 ) ;
}
static int T_2 F_28 ( struct V_11 * type ,
T_3 V_42 ,
T_3 V_43 )
{
struct V_39 * V_44 , * V_45 ;
T_3 V_46 , V_47 ;
T_3 V_48 , V_49 , V_36 ;
int V_50 = F_29 () ;
int * V_51 ;
if ( ! V_52 )
return - 1 ;
V_48 = type -> F_15 * sizeof( struct V_39 ) ;
V_49 = V_48 << 1 ;
V_46 = F_26 ( V_48 ) ;
V_47 = F_26 ( V_49 ) ;
if ( type == & V_26 . V_40 )
V_51 = & V_53 ;
else
V_51 = & V_54 ;
if ( V_50 ) {
V_44 = F_30 ( V_49 , V_55 ) ;
V_36 = V_44 ? F_25 ( V_44 ) : 0 ;
} else {
if ( type != & V_26 . V_37 )
V_42 = V_43 = 0 ;
V_36 = F_19 ( V_42 + V_43 ,
V_26 . V_27 ,
V_47 , V_28 ) ;
if ( ! V_36 && V_43 )
V_36 = F_19 ( 0 ,
F_3 ( V_42 , V_26 . V_27 ) ,
V_47 , V_28 ) ;
V_44 = V_36 ? F_31 ( V_36 ) : NULL ;
}
if ( ! V_36 ) {
F_32 ( L_3 ,
type -> V_56 , type -> F_15 , type -> F_15 * 2 ) ;
return - 1 ;
}
F_33 ( L_4 ,
type -> V_56 , type -> F_15 * 2 , ( T_4 ) V_36 ,
( T_4 ) V_36 + V_49 - 1 ) ;
memcpy ( V_44 , type -> V_14 , V_48 ) ;
memset ( V_44 + type -> F_15 , 0 , V_48 ) ;
V_45 = type -> V_14 ;
type -> V_14 = V_44 ;
type -> F_15 <<= 1 ;
if ( * V_51 )
F_34 ( V_45 ) ;
else if ( V_45 != V_41 &&
V_45 != V_38 )
F_35 ( F_25 ( V_45 ) , V_46 ) ;
if ( ! V_50 )
F_36 ( F_37 ( V_36 , V_47 ) ) ;
* V_51 = V_50 ;
return 0 ;
}
static void T_2 F_38 ( struct V_11 * type )
{
int V_12 = 0 ;
while ( V_12 < type -> V_13 - 1 ) {
struct V_39 * V_57 = & type -> V_14 [ V_12 ] ;
struct V_39 * V_58 = & type -> V_14 [ V_12 + 1 ] ;
if ( V_57 -> V_4 + V_57 -> V_5 != V_58 -> V_4 ||
F_39 ( V_57 ) !=
F_39 ( V_58 ) ||
V_57 -> V_19 != V_58 -> V_19 ) {
F_36 ( V_57 -> V_4 + V_57 -> V_5 > V_58 -> V_4 ) ;
V_12 ++ ;
continue;
}
V_57 -> V_5 += V_58 -> V_5 ;
memmove ( V_58 , V_58 + 1 , ( type -> V_13 - ( V_12 + 2 ) ) * sizeof( * V_58 ) ) ;
type -> V_13 -- ;
}
}
static void T_2 F_40 ( struct V_11 * type ,
int V_59 , T_3 V_4 ,
T_3 V_5 ,
int V_18 , unsigned long V_19 )
{
struct V_39 * V_60 = & type -> V_14 [ V_59 ] ;
F_36 ( type -> V_13 >= type -> F_15 ) ;
memmove ( V_60 + 1 , V_60 , ( type -> V_13 - V_59 ) * sizeof( * V_60 ) ) ;
V_60 -> V_4 = V_4 ;
V_60 -> V_5 = V_5 ;
V_60 -> V_19 = V_19 ;
F_23 ( V_60 , V_18 ) ;
type -> V_13 ++ ;
type -> V_34 += V_5 ;
}
int T_2 F_41 ( struct V_11 * type ,
T_3 V_4 , T_3 V_5 ,
int V_18 , unsigned long V_19 )
{
bool V_61 = false ;
T_3 V_62 = V_4 ;
T_3 V_16 = V_4 + F_2 ( V_4 , & V_5 ) ;
int V_59 , V_63 ;
struct V_39 * V_60 ;
if ( ! V_5 )
return 0 ;
if ( type -> V_14 [ 0 ] . V_5 == 0 ) {
F_22 ( type -> V_13 != 1 || type -> V_34 ) ;
type -> V_14 [ 0 ] . V_4 = V_4 ;
type -> V_14 [ 0 ] . V_5 = V_5 ;
type -> V_14 [ 0 ] . V_19 = V_19 ;
F_23 ( & type -> V_14 [ 0 ] , V_18 ) ;
type -> V_34 = V_5 ;
return 0 ;
}
V_64:
V_4 = V_62 ;
V_63 = 0 ;
F_42 (type, rgn) {
T_3 V_65 = V_60 -> V_4 ;
T_3 V_66 = V_65 + V_60 -> V_5 ;
if ( V_65 >= V_16 )
break;
if ( V_66 <= V_4 )
continue;
if ( V_65 > V_4 ) {
#ifdef F_43
F_22 ( V_18 != F_39 ( V_60 ) ) ;
#endif
F_22 ( V_19 != V_60 -> V_19 ) ;
V_63 ++ ;
if ( V_61 )
F_40 ( type , V_59 ++ , V_4 ,
V_65 - V_4 , V_18 ,
V_19 ) ;
}
V_4 = F_3 ( V_66 , V_16 ) ;
}
if ( V_4 < V_16 ) {
V_63 ++ ;
if ( V_61 )
F_40 ( type , V_59 , V_4 , V_16 - V_4 ,
V_18 , V_19 ) ;
}
if ( ! V_63 )
return 0 ;
if ( ! V_61 ) {
while ( type -> V_13 + V_63 > type -> F_15 )
if ( F_28 ( type , V_62 , V_5 ) < 0 )
return - V_67 ;
V_61 = true ;
goto V_64;
} else {
F_38 ( type ) ;
return 0 ;
}
}
int T_2 F_44 ( T_3 V_4 , T_3 V_5 ,
int V_18 )
{
return F_41 ( & V_26 . V_40 , V_4 , V_5 , V_18 , 0 ) ;
}
int T_2 F_45 ( T_3 V_4 , T_3 V_5 )
{
T_3 V_16 = V_4 + V_5 - 1 ;
F_33 ( L_5 ,
& V_4 , & V_16 , ( void * ) V_68 ) ;
return F_41 ( & V_26 . V_40 , V_4 , V_5 , V_35 , 0 ) ;
}
static int T_2 F_46 ( struct V_11 * type ,
T_3 V_4 , T_3 V_5 ,
int * V_69 , int * V_70 )
{
T_3 V_16 = V_4 + F_2 ( V_4 , & V_5 ) ;
int V_59 ;
struct V_39 * V_60 ;
* V_69 = * V_70 = 0 ;
if ( ! V_5 )
return 0 ;
while ( type -> V_13 + 2 > type -> F_15 )
if ( F_28 ( type , V_4 , V_5 ) < 0 )
return - V_67 ;
F_42 (type, rgn) {
T_3 V_65 = V_60 -> V_4 ;
T_3 V_66 = V_65 + V_60 -> V_5 ;
if ( V_65 >= V_16 )
break;
if ( V_66 <= V_4 )
continue;
if ( V_65 < V_4 ) {
V_60 -> V_4 = V_4 ;
V_60 -> V_5 -= V_4 - V_65 ;
type -> V_34 -= V_4 - V_65 ;
F_40 ( type , V_59 , V_65 , V_4 - V_65 ,
F_39 ( V_60 ) ,
V_60 -> V_19 ) ;
} else if ( V_66 > V_16 ) {
V_60 -> V_4 = V_16 ;
V_60 -> V_5 -= V_16 - V_65 ;
type -> V_34 -= V_16 - V_65 ;
F_40 ( type , V_59 -- , V_65 , V_16 - V_65 ,
F_39 ( V_60 ) ,
V_60 -> V_19 ) ;
} else {
if ( ! * V_70 )
* V_69 = V_59 ;
* V_70 = V_59 + 1 ;
}
}
return 0 ;
}
static int T_2 F_47 ( struct V_11 * type ,
T_3 V_4 , T_3 V_5 )
{
int V_69 , V_70 ;
int V_12 , V_24 ;
V_24 = F_46 ( type , V_4 , V_5 , & V_69 , & V_70 ) ;
if ( V_24 )
return V_24 ;
for ( V_12 = V_70 - 1 ; V_12 >= V_69 ; V_12 -- )
F_21 ( type , V_12 ) ;
return 0 ;
}
int T_2 F_48 ( T_3 V_4 , T_3 V_5 )
{
return F_47 ( & V_26 . V_40 , V_4 , V_5 ) ;
}
int T_2 F_35 ( T_3 V_4 , T_3 V_5 )
{
T_3 V_16 = V_4 + V_5 - 1 ;
F_33 ( L_6 ,
& V_4 , & V_16 , ( void * ) V_68 ) ;
F_49 ( V_4 , V_5 ) ;
return F_47 ( & V_26 . V_37 , V_4 , V_5 ) ;
}
int T_2 F_37 ( T_3 V_4 , T_3 V_5 )
{
T_3 V_16 = V_4 + V_5 - 1 ;
F_33 ( L_7 ,
& V_4 , & V_16 , ( void * ) V_68 ) ;
return F_41 ( & V_26 . V_37 , V_4 , V_5 , V_35 , 0 ) ;
}
static int T_2 F_50 ( T_3 V_4 ,
T_3 V_5 , int V_71 , int V_72 )
{
struct V_11 * type = & V_26 . V_40 ;
int V_12 , V_24 , V_69 , V_70 ;
V_24 = F_46 ( type , V_4 , V_5 , & V_69 , & V_70 ) ;
if ( V_24 )
return V_24 ;
for ( V_12 = V_69 ; V_12 < V_70 ; V_12 ++ )
if ( V_71 )
F_51 ( & type -> V_14 [ V_12 ] , V_72 ) ;
else
F_52 ( & type -> V_14 [ V_12 ] , V_72 ) ;
F_38 ( type ) ;
return 0 ;
}
int T_2 F_53 ( T_3 V_4 , T_3 V_5 )
{
return F_50 ( V_4 , V_5 , 1 , V_73 ) ;
}
int T_2 F_54 ( T_3 V_4 , T_3 V_5 )
{
return F_50 ( V_4 , V_5 , 0 , V_73 ) ;
}
int T_2 F_55 ( T_3 V_4 , T_3 V_5 )
{
V_1 = true ;
return F_50 ( V_4 , V_5 , 1 , V_2 ) ;
}
int T_2 F_56 ( T_3 V_4 , T_3 V_5 )
{
return F_50 ( V_4 , V_5 , 1 , V_74 ) ;
}
void T_2 F_57 ( T_4 * V_59 ,
T_3 * V_75 ,
T_3 * V_76 )
{
struct V_11 * type = & V_26 . V_37 ;
if ( * V_59 < type -> V_13 ) {
struct V_39 * V_33 = & type -> V_14 [ * V_59 ] ;
T_3 V_4 = V_33 -> V_4 ;
T_3 V_5 = V_33 -> V_5 ;
if ( V_75 )
* V_75 = V_4 ;
if ( V_76 )
* V_76 = V_4 + V_5 - 1 ;
* V_59 += 1 ;
return;
}
* V_59 = V_6 ;
}
void T_2 F_58 ( T_4 * V_59 , int V_18 , T_1 V_19 ,
struct V_11 * V_77 ,
struct V_11 * V_78 ,
T_3 * V_75 ,
T_3 * V_76 , int * V_79 )
{
int V_80 = * V_59 & 0xffffffff ;
int V_81 = * V_59 >> 32 ;
if ( F_18 ( V_18 == V_35 ,
L_8 ) )
V_18 = V_32 ;
for (; V_80 < V_77 -> V_13 ; V_80 ++ ) {
struct V_39 * V_82 = & V_77 -> V_14 [ V_80 ] ;
T_3 V_83 = V_82 -> V_4 ;
T_3 V_84 = V_82 -> V_4 + V_82 -> V_5 ;
int V_85 = F_39 ( V_82 ) ;
if ( V_18 != V_32 && V_18 != V_85 )
continue;
if ( F_59 () && F_60 ( V_82 ) )
continue;
if ( ( V_19 & V_2 ) && ! F_61 ( V_82 ) )
continue;
if ( ! ( V_19 & V_74 ) && F_62 ( V_82 ) )
continue;
if ( ! V_78 ) {
if ( V_75 )
* V_75 = V_83 ;
if ( V_76 )
* V_76 = V_84 ;
if ( V_79 )
* V_79 = V_85 ;
V_80 ++ ;
* V_59 = ( V_86 ) V_80 | ( T_4 ) V_81 << 32 ;
return;
}
for (; V_81 < V_78 -> V_13 + 1 ; V_81 ++ ) {
struct V_39 * V_33 ;
T_3 V_87 ;
T_3 V_88 ;
V_33 = & V_78 -> V_14 [ V_81 ] ;
V_87 = V_81 ? V_33 [ - 1 ] . V_4 + V_33 [ - 1 ] . V_5 : 0 ;
V_88 = V_81 < V_78 -> V_13 ?
V_33 -> V_4 : V_6 ;
if ( V_87 >= V_84 )
break;
if ( V_83 < V_88 ) {
if ( V_75 )
* V_75 =
F_15 ( V_83 , V_87 ) ;
if ( V_76 )
* V_76 = F_3 ( V_84 , V_88 ) ;
if ( V_79 )
* V_79 = V_85 ;
if ( V_84 <= V_88 )
V_80 ++ ;
else
V_81 ++ ;
* V_59 = ( V_86 ) V_80 | ( T_4 ) V_81 << 32 ;
return;
}
}
}
* V_59 = V_6 ;
}
void T_2 F_63 ( T_4 * V_59 , int V_18 , T_1 V_19 ,
struct V_11 * V_77 ,
struct V_11 * V_78 ,
T_3 * V_75 ,
T_3 * V_76 , int * V_79 )
{
int V_80 = * V_59 & 0xffffffff ;
int V_81 = * V_59 >> 32 ;
if ( F_18 ( V_18 == V_35 , L_8 ) )
V_18 = V_32 ;
if ( * V_59 == ( T_4 ) V_6 ) {
V_80 = V_77 -> V_13 - 1 ;
if ( V_78 != NULL )
V_81 = V_78 -> V_13 ;
else
V_81 = 0 ;
}
for (; V_80 >= 0 ; V_80 -- ) {
struct V_39 * V_82 = & V_77 -> V_14 [ V_80 ] ;
T_3 V_83 = V_82 -> V_4 ;
T_3 V_84 = V_82 -> V_4 + V_82 -> V_5 ;
int V_85 = F_39 ( V_82 ) ;
if ( V_18 != V_32 && V_18 != V_85 )
continue;
if ( F_59 () && F_60 ( V_82 ) )
continue;
if ( ( V_19 & V_2 ) && ! F_61 ( V_82 ) )
continue;
if ( ! ( V_19 & V_74 ) && F_62 ( V_82 ) )
continue;
if ( ! V_78 ) {
if ( V_75 )
* V_75 = V_83 ;
if ( V_76 )
* V_76 = V_84 ;
if ( V_79 )
* V_79 = V_85 ;
V_80 -- ;
* V_59 = ( V_86 ) V_80 | ( T_4 ) V_81 << 32 ;
return;
}
for (; V_81 >= 0 ; V_81 -- ) {
struct V_39 * V_33 ;
T_3 V_87 ;
T_3 V_88 ;
V_33 = & V_78 -> V_14 [ V_81 ] ;
V_87 = V_81 ? V_33 [ - 1 ] . V_4 + V_33 [ - 1 ] . V_5 : 0 ;
V_88 = V_81 < V_78 -> V_13 ?
V_33 -> V_4 : V_6 ;
if ( V_88 <= V_83 )
break;
if ( V_84 > V_87 ) {
if ( V_75 )
* V_75 = F_15 ( V_83 , V_87 ) ;
if ( V_76 )
* V_76 = F_3 ( V_84 , V_88 ) ;
if ( V_79 )
* V_79 = V_85 ;
if ( V_83 >= V_87 )
V_80 -- ;
else
V_81 -- ;
* V_59 = ( V_86 ) V_80 | ( T_4 ) V_81 << 32 ;
return;
}
}
}
* V_59 = V_6 ;
}
void T_2 F_64 ( int * V_59 , int V_18 ,
unsigned long * V_89 ,
unsigned long * V_90 , int * V_79 )
{
struct V_11 * type = & V_26 . V_40 ;
struct V_39 * V_33 ;
while ( ++ * V_59 < type -> V_13 ) {
V_33 = & type -> V_14 [ * V_59 ] ;
if ( F_65 ( V_33 -> V_4 ) >= F_66 ( V_33 -> V_4 + V_33 -> V_5 ) )
continue;
if ( V_18 == V_35 || V_18 == V_33 -> V_18 )
break;
}
if ( * V_59 >= type -> V_13 ) {
* V_59 = - 1 ;
return;
}
if ( V_89 )
* V_89 = F_65 ( V_33 -> V_4 ) ;
if ( V_90 )
* V_90 = F_66 ( V_33 -> V_4 + V_33 -> V_5 ) ;
if ( V_79 )
* V_79 = V_33 -> V_18 ;
}
unsigned long T_2 F_67 ( unsigned long V_91 ,
unsigned long V_92 )
{
struct V_11 * type = & V_26 . V_40 ;
unsigned int V_93 = type -> V_13 ;
unsigned int V_94 , V_95 = 0 ;
T_3 V_36 = F_68 ( V_91 + 1 ) ;
do {
V_94 = ( V_93 + V_95 ) / 2 ;
if ( V_36 < type -> V_14 [ V_94 ] . V_4 )
V_93 = V_94 ;
else if ( V_36 >= ( type -> V_14 [ V_94 ] . V_4 +
type -> V_14 [ V_94 ] . V_5 ) )
V_95 = V_94 + 1 ;
else {
return F_3 ( V_91 + 1 , V_92 ) ;
}
} while ( V_95 < V_93 );
if ( V_93 == type -> V_13 )
return V_92 ;
else
return F_3 ( F_69 ( type -> V_14 [ V_93 ] . V_4 ) , V_92 ) ;
}
int T_2 F_70 ( T_3 V_4 , T_3 V_5 ,
struct V_11 * type , int V_18 )
{
int V_69 , V_70 ;
int V_12 , V_24 ;
V_24 = F_46 ( type , V_4 , V_5 , & V_69 , & V_70 ) ;
if ( V_24 )
return V_24 ;
for ( V_12 = V_69 ; V_12 < V_70 ; V_12 ++ )
F_23 ( & type -> V_14 [ V_12 ] , V_18 ) ;
F_38 ( type ) ;
return 0 ;
}
static T_3 T_5 F_71 ( T_3 V_5 ,
T_3 V_17 , T_3 V_15 ,
T_3 V_16 , int V_18 , T_1 V_19 )
{
T_3 V_96 ;
if ( ! V_17 )
V_17 = V_97 ;
V_96 = F_13 ( V_5 , V_17 , V_15 , V_16 , V_18 ,
V_19 ) ;
if ( V_96 && ! F_37 ( V_96 , V_5 ) ) {
F_72 ( V_96 , V_5 , 0 , 0 ) ;
return V_96 ;
}
return 0 ;
}
T_3 T_5 F_73 ( T_3 V_5 , T_3 V_17 ,
T_3 V_15 , T_3 V_16 ,
T_1 V_19 )
{
return F_71 ( V_5 , V_17 , V_15 , V_16 , V_32 ,
V_19 ) ;
}
static T_3 T_5 F_74 ( T_3 V_5 ,
T_3 V_17 , T_3 V_98 ,
int V_18 , T_1 V_19 )
{
return F_71 ( V_5 , V_17 , 0 , V_98 , V_18 , V_19 ) ;
}
T_3 T_5 F_75 ( T_3 V_5 , T_3 V_17 , int V_18 )
{
T_1 V_19 = F_1 () ;
T_3 V_24 ;
V_31:
V_24 = F_74 ( V_5 , V_17 , V_25 ,
V_18 , V_19 ) ;
if ( ! V_24 && ( V_19 & V_2 ) ) {
V_19 &= ~ V_2 ;
goto V_31;
}
return V_24 ;
}
T_3 T_5 F_76 ( T_3 V_5 , T_3 V_17 , T_3 V_98 )
{
return F_74 ( V_5 , V_17 , V_98 , V_32 ,
V_3 ) ;
}
T_3 T_5 F_77 ( T_3 V_5 , T_3 V_17 , T_3 V_98 )
{
T_3 V_99 ;
V_99 = F_76 ( V_5 , V_17 , V_98 ) ;
if ( V_99 == 0 )
F_78 ( L_9 ,
& V_5 , & V_98 ) ;
return V_99 ;
}
T_3 T_5 F_79 ( T_3 V_5 , T_3 V_17 )
{
return F_77 ( V_5 , V_17 , V_25 ) ;
}
T_3 T_5 F_80 ( T_3 V_5 , T_3 V_17 , int V_18 )
{
T_3 V_100 = F_75 ( V_5 , V_17 , V_18 ) ;
if ( V_100 )
return V_100 ;
return F_77 ( V_5 , V_17 , V_25 ) ;
}
static void * T_5 F_81 (
T_3 V_5 , T_3 V_17 ,
T_3 V_101 , T_3 V_98 ,
int V_18 )
{
T_3 V_99 ;
void * V_102 ;
T_1 V_19 = F_1 () ;
if ( F_18 ( V_18 == V_35 , L_8 ) )
V_18 = V_32 ;
if ( F_82 ( F_29 () ) )
return F_83 ( V_5 , V_103 , V_18 ) ;
if ( ! V_17 )
V_17 = V_97 ;
if ( V_98 > V_26 . V_27 )
V_98 = V_26 . V_27 ;
V_31:
V_99 = F_13 ( V_5 , V_17 , V_101 , V_98 ,
V_18 , V_19 ) ;
if ( V_99 && ! F_37 ( V_99 , V_5 ) )
goto V_104;
if ( V_18 != V_32 ) {
V_99 = F_13 ( V_5 , V_17 , V_101 ,
V_98 , V_32 ,
V_19 ) ;
if ( V_99 && ! F_37 ( V_99 , V_5 ) )
goto V_104;
}
if ( V_101 ) {
V_101 = 0 ;
goto V_31;
}
if ( V_19 & V_2 ) {
V_19 &= ~ V_2 ;
F_20 ( L_2 ,
& V_5 ) ;
goto V_31;
}
return NULL ;
V_104:
V_102 = F_84 ( V_99 ) ;
memset ( V_102 , 0 , V_5 ) ;
F_85 ( V_102 , V_5 , 0 , 0 ) ;
return V_102 ;
}
void * T_5 F_86 (
T_3 V_5 , T_3 V_17 ,
T_3 V_101 , T_3 V_98 ,
int V_18 )
{
F_33 ( L_10 ,
V_105 , ( T_4 ) V_5 , ( T_4 ) V_17 , V_18 , ( T_4 ) V_101 ,
( T_4 ) V_98 , ( void * ) V_68 ) ;
return F_81 ( V_5 , V_17 , V_101 ,
V_98 , V_18 ) ;
}
void * T_5 F_87 (
T_3 V_5 , T_3 V_17 ,
T_3 V_101 , T_3 V_98 ,
int V_18 )
{
void * V_102 ;
F_33 ( L_10 ,
V_105 , ( T_4 ) V_5 , ( T_4 ) V_17 , V_18 , ( T_4 ) V_101 ,
( T_4 ) V_98 , ( void * ) V_68 ) ;
V_102 = F_81 ( V_5 , V_17 ,
V_101 , V_98 , V_18 ) ;
if ( V_102 )
return V_102 ;
F_78 ( L_11 ,
V_105 , ( T_4 ) V_5 , ( T_4 ) V_17 , V_18 , ( T_4 ) V_101 ,
( T_4 ) V_98 ) ;
return NULL ;
}
void T_5 F_88 ( T_3 V_4 , T_3 V_5 )
{
F_33 ( L_12 ,
V_105 , ( T_4 ) V_4 , ( T_4 ) V_4 + V_5 - 1 ,
( void * ) V_68 ) ;
F_49 ( V_4 , V_5 ) ;
F_47 ( & V_26 . V_37 , V_4 , V_5 ) ;
}
void T_5 F_89 ( T_3 V_4 , T_3 V_5 )
{
T_4 V_106 , V_16 ;
F_33 ( L_12 ,
V_105 , ( T_4 ) V_4 , ( T_4 ) V_4 + V_5 - 1 ,
( void * ) V_68 ) ;
F_49 ( V_4 , V_5 ) ;
V_106 = F_65 ( V_4 ) ;
V_16 = F_66 ( V_4 + V_5 ) ;
for (; V_106 < V_16 ; V_106 ++ ) {
F_90 ( F_91 ( V_106 ) , V_106 , 0 ) ;
V_107 ++ ;
}
}
T_3 T_2 F_92 ( void )
{
return V_26 . V_40 . V_34 ;
}
T_3 T_2 F_93 ( void )
{
return V_26 . V_37 . V_34 ;
}
T_3 T_5 F_94 ( unsigned long V_108 )
{
unsigned long V_109 = 0 ;
struct V_39 * V_33 ;
unsigned long V_110 , V_111 ;
F_95 (memory, r) {
V_110 = F_96 ( V_33 ) ;
V_111 = F_97 ( V_33 ) ;
V_110 = F_98 (unsigned long, start_pfn, limit_pfn) ;
V_111 = F_98 (unsigned long, end_pfn, limit_pfn) ;
V_109 += V_111 - V_110 ;
}
return F_68 ( V_109 ) ;
}
T_3 T_2 F_99 ( void )
{
return V_26 . V_40 . V_14 [ 0 ] . V_4 ;
}
T_3 T_2 F_100 ( void )
{
int V_59 = V_26 . V_40 . V_13 - 1 ;
return ( V_26 . V_40 . V_14 [ V_59 ] . V_4 + V_26 . V_40 . V_14 [ V_59 ] . V_5 ) ;
}
static T_3 T_2 F_101 ( T_3 V_112 )
{
T_3 V_98 = ( T_3 ) V_6 ;
struct V_39 * V_33 ;
F_95 (memory, r) {
if ( V_112 <= V_33 -> V_5 ) {
V_98 = V_33 -> V_4 + V_112 ;
break;
}
V_112 -= V_33 -> V_5 ;
}
return V_98 ;
}
void T_5 F_102 ( T_3 V_112 )
{
T_3 V_98 = ( T_3 ) V_6 ;
if ( ! V_112 )
return;
V_98 = F_101 ( V_112 ) ;
if ( V_98 == ( T_3 ) V_6 )
return;
F_47 ( & V_26 . V_40 , V_98 ,
( T_3 ) V_6 ) ;
F_47 ( & V_26 . V_37 , V_98 ,
( T_3 ) V_6 ) ;
}
void T_5 F_103 ( T_3 V_112 )
{
struct V_11 * type = & V_26 . V_40 ;
T_3 V_98 ;
int V_12 , V_24 , V_69 , V_70 ;
if ( ! V_112 )
return;
V_98 = F_101 ( V_112 ) ;
if ( V_98 == ( T_3 ) V_6 )
return;
V_24 = F_46 ( type , V_98 , ( T_3 ) V_6 ,
& V_69 , & V_70 ) ;
if ( V_24 )
return;
for ( V_12 = V_70 - 1 ; V_12 >= V_69 ; V_12 -- ) {
if ( ! F_62 ( & type -> V_14 [ V_12 ] ) )
F_21 ( type , V_12 ) ;
}
F_47 ( & V_26 . V_37 , V_98 ,
( T_3 ) V_6 ) ;
}
static int T_2 F_104 ( struct V_11 * type , T_3 V_36 )
{
unsigned int V_95 = 0 , V_93 = type -> V_13 ;
do {
unsigned int V_94 = ( V_93 + V_95 ) / 2 ;
if ( V_36 < type -> V_14 [ V_94 ] . V_4 )
V_93 = V_94 ;
else if ( V_36 >= ( type -> V_14 [ V_94 ] . V_4 +
type -> V_14 [ V_94 ] . V_5 ) )
V_95 = V_94 + 1 ;
else
return V_94 ;
} while ( V_95 < V_93 );
return - 1 ;
}
bool T_5 F_105 ( T_3 V_36 )
{
return F_104 ( & V_26 . V_37 , V_36 ) != - 1 ;
}
bool T_2 F_106 ( T_3 V_36 )
{
return F_104 ( & V_26 . V_40 , V_36 ) != - 1 ;
}
int T_2 F_107 ( T_3 V_36 )
{
int V_12 = F_104 ( & V_26 . V_40 , V_36 ) ;
if ( V_12 == - 1 )
return false ;
return ! F_62 ( & V_26 . V_40 . V_14 [ V_12 ] ) ;
}
int T_2 F_108 ( unsigned long V_91 ,
unsigned long * V_110 , unsigned long * V_111 )
{
struct V_11 * type = & V_26 . V_40 ;
int V_94 = F_104 ( type , F_68 ( V_91 ) ) ;
if ( V_94 == - 1 )
return - 1 ;
* V_110 = F_66 ( type -> V_14 [ V_94 ] . V_4 ) ;
* V_111 = F_66 ( type -> V_14 [ V_94 ] . V_4 + type -> V_14 [ V_94 ] . V_5 ) ;
return type -> V_14 [ V_94 ] . V_18 ;
}
int T_2 F_109 ( T_3 V_4 , T_3 V_5 )
{
int V_59 = F_104 ( & V_26 . V_40 , V_4 ) ;
T_3 V_16 = V_4 + F_2 ( V_4 , & V_5 ) ;
if ( V_59 == - 1 )
return 0 ;
return ( V_26 . V_40 . V_14 [ V_59 ] . V_4 +
V_26 . V_40 . V_14 [ V_59 ] . V_5 ) >= V_16 ;
}
bool T_2 F_110 ( T_3 V_4 , T_3 V_5 )
{
F_2 ( V_4 , & V_5 ) ;
return F_5 ( & V_26 . V_37 , V_4 , V_5 ) ;
}
void T_2 F_111 ( T_3 V_17 )
{
T_3 V_15 , V_16 , V_113 , V_114 ;
struct V_39 * V_33 ;
F_95 (memory, r) {
V_113 = V_33 -> V_4 ;
V_114 = V_33 -> V_4 + V_33 -> V_5 ;
V_15 = F_9 ( V_113 , V_17 ) ;
V_16 = F_12 ( V_114 , V_17 ) ;
if ( V_15 == V_113 && V_16 == V_114 )
continue;
if ( V_15 < V_16 ) {
V_33 -> V_4 = V_15 ;
V_33 -> V_5 = V_16 - V_15 ;
} else {
F_21 ( & V_26 . V_40 ,
V_33 - V_26 . V_40 . V_14 ) ;
V_33 -- ;
}
}
}
void T_2 F_112 ( T_3 V_112 )
{
V_26 . V_27 = V_112 ;
}
T_3 T_2 F_113 ( void )
{
return V_26 . V_27 ;
}
static void T_2 F_114 ( struct V_11 * type )
{
T_3 V_4 , V_16 , V_5 ;
unsigned long V_19 ;
int V_59 ;
struct V_39 * V_60 ;
F_115 ( L_13 , type -> V_56 , type -> V_13 ) ;
F_42 (type, rgn) {
char V_115 [ 32 ] = L_14 ;
V_4 = V_60 -> V_4 ;
V_5 = V_60 -> V_5 ;
V_16 = V_4 + V_5 - 1 ;
V_19 = V_60 -> V_19 ;
#ifdef F_43
if ( F_39 ( V_60 ) != V_35 )
snprintf ( V_115 , sizeof( V_115 ) , L_15 ,
F_39 ( V_60 ) ) ;
#endif
F_115 ( L_16 ,
type -> V_56 , V_59 , & V_4 , & V_16 , & V_5 , V_115 , V_19 ) ;
}
}
void T_2 F_116 ( void )
{
F_115 ( L_17 ) ;
F_115 ( L_18 ,
& V_26 . V_40 . V_34 ,
& V_26 . V_37 . V_34 ) ;
F_114 ( & V_26 . V_40 ) ;
F_114 ( & V_26 . V_37 ) ;
#ifdef F_117
F_114 ( & V_26 . V_116 ) ;
#endif
}
void T_5 F_118 ( void )
{
V_52 = 1 ;
}
static int T_5 F_119 ( char * V_117 )
{
if ( V_117 && strstr ( V_117 , L_19 ) )
V_118 = 1 ;
return 0 ;
}
static int F_120 ( struct V_119 * V_82 , void * V_120 )
{
struct V_11 * type = V_82 -> V_120 ;
struct V_39 * V_121 ;
int V_12 ;
T_3 V_16 ;
for ( V_12 = 0 ; V_12 < type -> V_13 ; V_12 ++ ) {
V_121 = & type -> V_14 [ V_12 ] ;
V_16 = V_121 -> V_4 + V_121 -> V_5 - 1 ;
F_121 ( V_82 , L_20 , V_12 ) ;
F_121 ( V_82 , L_21 , & V_121 -> V_4 , & V_16 ) ;
}
return 0 ;
}
static int F_122 ( struct V_122 * V_122 , struct V_123 * V_123 )
{
return F_123 ( V_123 , F_120 , V_122 -> V_124 ) ;
}
static int T_5 F_124 ( void )
{
struct V_125 * V_126 = F_125 ( L_22 , NULL ) ;
if ( ! V_126 )
return - V_127 ;
F_126 ( L_23 , V_128 , V_126 , & V_26 . V_40 , & V_129 ) ;
F_126 ( L_24 , V_128 , V_126 , & V_26 . V_37 , & V_129 ) ;
#ifdef F_117
F_126 ( L_25 , V_128 , V_126 , & V_26 . V_116 , & V_129 ) ;
#endif
return 0 ;
}
