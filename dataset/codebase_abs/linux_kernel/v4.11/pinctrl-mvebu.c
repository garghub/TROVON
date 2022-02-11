int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned long * V_4 )
{
unsigned V_5 = ( V_3 / V_6 ) * V_7 ;
unsigned V_8 = ( V_3 % V_6 ) * V_7 ;
* V_4 = ( F_2 ( V_2 -> V_9 + V_5 ) >> V_8 ) & V_10 ;
return 0 ;
}
int F_3 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned long V_4 )
{
unsigned V_5 = ( V_3 / V_6 ) * V_7 ;
unsigned V_8 = ( V_3 % V_6 ) * V_7 ;
unsigned long V_11 ;
V_11 = F_2 ( V_2 -> V_9 + V_5 ) & ~ ( V_10 << V_8 ) ;
F_4 ( V_11 | ( V_4 << V_8 ) , V_2 -> V_9 + V_5 ) ;
return 0 ;
}
static struct V_12 * F_5 (
struct V_13 * V_14 , unsigned V_3 )
{
unsigned V_15 ;
for ( V_15 = 0 ; V_15 < V_14 -> V_16 ; V_15 ++ ) {
if ( V_3 >= V_14 -> V_17 [ V_15 ] . V_18 [ 0 ] &&
V_3 < V_14 -> V_17 [ V_15 ] . V_18 [ 0 ] +
V_14 -> V_17 [ V_15 ] . V_19 )
return & V_14 -> V_17 [ V_15 ] ;
}
return NULL ;
}
static struct V_12 * F_6 (
struct V_13 * V_14 , const char * V_20 )
{
unsigned V_15 ;
for ( V_15 = 0 ; V_15 < V_14 -> V_16 ; V_15 ++ ) {
if ( strcmp ( V_20 , V_14 -> V_17 [ V_15 ] . V_20 ) == 0 )
return & V_14 -> V_17 [ V_15 ] ;
}
return NULL ;
}
static struct V_21 * F_7 (
struct V_13 * V_14 , struct V_12 * V_22 ,
unsigned long V_4 )
{
unsigned V_15 ;
for ( V_15 = 0 ; V_15 < V_22 -> V_23 ; V_15 ++ ) {
if ( V_4 == V_22 -> V_24 [ V_15 ] . V_25 ) {
if ( ! V_14 -> V_26 || ( V_14 -> V_26 &
V_22 -> V_24 [ V_15 ] . V_26 ) )
return & V_22 -> V_24 [ V_15 ] ;
}
}
return NULL ;
}
static struct V_21 * F_8 (
struct V_13 * V_14 , struct V_12 * V_22 ,
const char * V_20 )
{
unsigned V_15 ;
for ( V_15 = 0 ; V_15 < V_22 -> V_23 ; V_15 ++ ) {
if ( strcmp ( V_20 , V_22 -> V_24 [ V_15 ] . V_20 ) == 0 ) {
if ( ! V_14 -> V_26 || ( V_14 -> V_26 &
V_22 -> V_24 [ V_15 ] . V_26 ) )
return & V_22 -> V_24 [ V_15 ] ;
}
}
return NULL ;
}
static struct V_21 * F_9 (
struct V_13 * V_14 , struct V_12 * V_22 )
{
unsigned V_15 ;
for ( V_15 = 0 ; V_15 < V_22 -> V_23 ; V_15 ++ ) {
if ( V_22 -> V_24 [ V_15 ] . V_27 &
( V_28 | V_29 ) ) {
if ( ! V_14 -> V_26 || ( V_14 -> V_26 &
V_22 -> V_24 [ V_15 ] . V_26 ) )
return & V_22 -> V_24 [ V_15 ] ;
}
}
return NULL ;
}
static struct V_30 * F_10 (
struct V_13 * V_14 , const char * V_20 )
{
unsigned V_15 ;
for ( V_15 = 0 ; V_15 < V_14 -> V_31 ; V_15 ++ ) {
if ( strcmp ( V_20 , V_14 -> V_32 [ V_15 ] . V_20 ) == 0 )
return & V_14 -> V_32 [ V_15 ] ;
}
return NULL ;
}
static int F_11 ( struct V_33 * V_34 ,
unsigned V_35 , unsigned long * V_4 )
{
struct V_13 * V_14 = F_12 ( V_34 ) ;
struct V_12 * V_22 = & V_14 -> V_17 [ V_35 ] ;
if ( ! V_22 -> V_36 )
return - V_37 ;
return V_22 -> V_36 -> V_38 ( V_22 -> V_2 , V_22 -> V_18 [ 0 ] , V_4 ) ;
}
static int F_13 ( struct V_33 * V_34 ,
unsigned V_35 , unsigned long * V_39 ,
unsigned V_40 )
{
struct V_13 * V_14 = F_12 ( V_34 ) ;
struct V_12 * V_22 = & V_14 -> V_17 [ V_35 ] ;
int V_41 , V_42 ;
if ( ! V_22 -> V_36 )
return - V_37 ;
for ( V_41 = 0 ; V_41 < V_40 ; V_41 ++ ) {
V_42 = V_22 -> V_36 -> V_43 ( V_22 -> V_2 , V_22 -> V_18 [ 0 ] , V_39 [ V_41 ] ) ;
if ( V_42 )
return V_42 ;
}
return 0 ;
}
static void F_14 ( struct V_33 * V_34 ,
struct V_44 * V_45 , unsigned V_35 )
{
struct V_13 * V_14 = F_12 ( V_34 ) ;
struct V_12 * V_22 = & V_14 -> V_17 [ V_35 ] ;
struct V_21 * V_46 ;
unsigned long V_4 ;
unsigned V_15 ;
if ( F_11 ( V_34 , V_35 , & V_4 ) )
return;
V_46 = F_7 ( V_14 , V_22 , V_4 ) ;
if ( V_46 ) {
F_15 ( V_45 , L_1 , V_46 -> V_20 ) ;
if ( V_46 -> V_47 )
F_15 ( V_45 , L_2 , V_46 -> V_47 ) ;
if ( V_46 -> V_27 & ( V_28 | V_29 ) ) {
F_16 ( V_45 , '(' ) ;
if ( V_46 -> V_27 & V_29 )
F_16 ( V_45 , 'i' ) ;
if ( V_46 -> V_27 & V_28 )
F_16 ( V_45 , 'o' ) ;
F_16 ( V_45 , ')' ) ;
}
} else {
F_17 ( V_45 , L_3 ) ;
}
if ( V_22 -> V_23 > 1 ) {
F_17 ( V_45 , L_4 ) ;
for ( V_15 = 0 ; V_15 < V_22 -> V_23 ; V_15 ++ ) {
if ( V_46 == & V_22 -> V_24 [ V_15 ] )
continue;
if ( V_14 -> V_26 &&
! ( V_14 -> V_26 & V_22 -> V_24 [ V_15 ] . V_26 ) )
continue;
F_15 ( V_45 , L_5 , V_22 -> V_24 [ V_15 ] . V_20 ) ;
if ( V_22 -> V_24 [ V_15 ] . V_47 )
F_15 ( V_45 , L_2 , V_22 -> V_24 [ V_15 ] . V_47 ) ;
if ( V_22 -> V_24 [ V_15 ] . V_27 &
( V_28 | V_29 ) ) {
F_16 ( V_45 , '(' ) ;
if ( V_22 -> V_24 [ V_15 ] . V_27 & V_29 )
F_16 ( V_45 , 'i' ) ;
if ( V_22 -> V_24 [ V_15 ] . V_27 & V_28 )
F_16 ( V_45 , 'o' ) ;
F_16 ( V_45 , ')' ) ;
}
}
F_17 ( V_45 , L_6 ) ;
}
}
static int F_18 ( struct V_33 * V_34 )
{
struct V_13 * V_14 = F_12 ( V_34 ) ;
return V_14 -> V_31 ;
}
static const char * F_19 ( struct V_33 * V_34 ,
unsigned V_48 )
{
struct V_13 * V_14 = F_12 ( V_34 ) ;
return V_14 -> V_32 [ V_48 ] . V_20 ;
}
static int F_20 ( struct V_33 * V_34 , unsigned V_48 ,
const char * const * * V_17 ,
unsigned * const V_16 )
{
struct V_13 * V_14 = F_12 ( V_34 ) ;
* V_17 = V_14 -> V_32 [ V_48 ] . V_17 ;
* V_16 = V_14 -> V_32 [ V_48 ] . V_16 ;
return 0 ;
}
static int F_21 ( struct V_33 * V_34 , unsigned V_48 ,
unsigned V_35 )
{
struct V_13 * V_14 = F_12 ( V_34 ) ;
struct V_30 * V_49 = & V_14 -> V_32 [ V_48 ] ;
struct V_12 * V_22 = & V_14 -> V_17 [ V_35 ] ;
struct V_21 * V_50 ;
int V_42 ;
unsigned long V_4 ;
V_50 = F_8 ( V_14 , V_22 ,
V_49 -> V_20 ) ;
if ( ! V_50 ) {
F_22 ( V_14 -> V_51 ,
L_7 ,
V_49 -> V_20 , V_49 -> V_17 [ V_35 ] ) ;
return - V_37 ;
}
V_4 = V_50 -> V_25 ;
V_42 = F_13 ( V_34 , V_22 -> V_35 , & V_4 , 1 ) ;
if ( V_42 ) {
F_22 ( V_14 -> V_51 , L_8 ,
V_49 -> V_17 [ V_35 ] , V_49 -> V_20 ) ;
return V_42 ;
}
return 0 ;
}
static int F_23 ( struct V_33 * V_34 ,
struct V_52 * V_53 , unsigned V_54 )
{
struct V_13 * V_14 = F_12 ( V_34 ) ;
struct V_12 * V_22 ;
struct V_21 * V_50 ;
unsigned long V_4 ;
V_22 = F_5 ( V_14 , V_54 ) ;
if ( ! V_22 )
return - V_37 ;
if ( V_22 -> V_36 -> V_55 )
return V_22 -> V_36 -> V_55 ( V_22 -> V_2 , V_54 ) ;
V_50 = F_9 ( V_14 , V_22 ) ;
if ( ! V_50 )
return - V_56 ;
V_4 = V_50 -> V_25 ;
return F_13 ( V_34 , V_22 -> V_35 , & V_4 , 1 ) ;
}
static int F_24 ( struct V_33 * V_34 ,
struct V_52 * V_53 , unsigned V_54 , bool V_57 )
{
struct V_13 * V_14 = F_12 ( V_34 ) ;
struct V_12 * V_22 ;
struct V_21 * V_50 ;
V_22 = F_5 ( V_14 , V_54 ) ;
if ( ! V_22 )
return - V_37 ;
if ( V_22 -> V_36 -> V_58 )
return V_22 -> V_36 -> V_58 ( V_22 -> V_2 , V_54 , V_57 ) ;
V_50 = F_9 ( V_14 , V_22 ) ;
if ( ! V_50 )
return - V_56 ;
if ( ( V_57 && ( V_50 -> V_27 & V_29 ) ) ||
( ! V_57 && ( V_50 -> V_27 & V_28 ) ) )
return 0 ;
return - V_56 ;
}
static int F_25 ( struct V_33 * V_34 )
{
struct V_13 * V_14 = F_12 ( V_34 ) ;
return V_14 -> V_16 ;
}
static const char * F_26 ( struct V_33 * V_34 ,
unsigned V_35 )
{
struct V_13 * V_14 = F_12 ( V_34 ) ;
return V_14 -> V_17 [ V_35 ] . V_20 ;
}
static int F_27 ( struct V_33 * V_34 ,
unsigned V_35 , const unsigned * * V_18 ,
unsigned * V_59 )
{
struct V_13 * V_14 = F_12 ( V_34 ) ;
* V_18 = V_14 -> V_17 [ V_35 ] . V_18 ;
* V_59 = V_14 -> V_17 [ V_35 ] . V_19 ;
return 0 ;
}
static int F_28 ( struct V_33 * V_34 ,
struct V_60 * V_61 ,
struct V_62 * * V_63 ,
unsigned * V_64 )
{
struct V_13 * V_14 = F_12 ( V_34 ) ;
struct V_65 * V_66 ;
const char * V_67 ;
const char * V_68 ;
int V_42 , V_69 , V_15 ;
* V_63 = NULL ;
* V_64 = 0 ;
V_42 = F_29 ( V_61 , L_9 , & V_67 ) ;
if ( V_42 ) {
F_22 ( V_14 -> V_51 ,
L_10 , V_61 -> V_20 ) ;
return 0 ;
}
V_69 = F_30 ( V_61 , L_11 ) ;
if ( V_69 < 0 ) {
F_22 ( V_14 -> V_51 ,
L_12 , V_61 -> V_20 ) ;
return 0 ;
}
* V_63 = F_31 ( V_69 , sizeof( * * V_63 ) , V_70 ) ;
if ( ! * V_63 )
return - V_71 ;
V_15 = 0 ;
F_32 (np, L_11 , prop, group) {
struct V_12 * V_22 =
F_6 ( V_14 , V_68 ) ;
if ( ! V_22 ) {
F_22 ( V_14 -> V_51 , L_13 , V_68 ) ;
continue;
}
if ( ! F_8 ( V_14 , V_22 , V_67 ) ) {
F_22 ( V_14 -> V_51 , L_14 ,
V_67 , V_68 ) ;
continue;
}
( * V_63 ) [ V_15 ] . type = V_72 ;
( * V_63 ) [ V_15 ] . V_2 . V_73 . V_68 = V_68 ;
( * V_63 ) [ V_15 ] . V_2 . V_73 . V_67 = V_67 ;
V_15 ++ ;
}
* V_64 = V_69 ;
return 0 ;
}
static void F_33 ( struct V_33 * V_34 ,
struct V_62 * V_63 , unsigned V_64 )
{
F_34 ( V_63 ) ;
}
static int F_35 ( struct V_30 * V_74 , int * V_75 ,
const char * V_20 )
{
if ( * V_75 <= 0 )
return - V_76 ;
while ( V_74 -> V_16 ) {
if ( strcmp ( V_74 -> V_20 , V_20 ) == 0 ) {
V_74 -> V_16 ++ ;
return - V_77 ;
}
V_74 ++ ;
}
V_74 -> V_20 = V_20 ;
V_74 -> V_16 = 1 ;
( * V_75 ) -- ;
return 0 ;
}
static int F_36 ( struct V_78 * V_79 ,
struct V_13 * V_14 )
{
struct V_30 * V_74 ;
int V_80 = 0 , V_75 = V_14 -> V_81 . V_19 ;
int V_15 , V_45 ;
V_74 = F_37 ( & V_79 -> V_51 , V_75 *
sizeof( struct V_30 ) , V_70 ) ;
if ( ! V_74 )
return - V_71 ;
for ( V_15 = 0 ; V_15 < V_14 -> V_16 ; V_15 ++ ) {
struct V_12 * V_22 = & V_14 -> V_17 [ V_15 ] ;
for ( V_45 = 0 ; V_45 < V_22 -> V_23 ; V_45 ++ ) {
int V_42 ;
if ( V_14 -> V_26 &&
! ( V_14 -> V_26 & V_22 -> V_24 [ V_45 ] . V_26 ) )
continue;
V_42 = F_35 ( V_74 , & V_75 ,
V_22 -> V_24 [ V_45 ] . V_20 ) ;
if ( V_42 == - V_76 )
F_22 ( & V_79 -> V_51 ,
L_15 ,
V_14 -> V_81 . V_19 ) ;
if ( V_42 < 0 )
continue;
V_80 ++ ;
}
}
V_14 -> V_31 = V_80 ;
V_14 -> V_32 = V_74 ;
for ( V_15 = 0 ; V_15 < V_14 -> V_16 ; V_15 ++ ) {
struct V_12 * V_22 = & V_14 -> V_17 [ V_15 ] ;
for ( V_45 = 0 ; V_45 < V_22 -> V_23 ; V_45 ++ ) {
struct V_30 * V_82 ;
const char * * V_17 ;
if ( V_14 -> V_26 &&
! ( V_14 -> V_26 & V_22 -> V_24 [ V_45 ] . V_26 ) )
continue;
V_82 = F_10 ( V_14 ,
V_22 -> V_24 [ V_45 ] . V_20 ) ;
if ( ! V_82 -> V_17 ) {
V_82 -> V_17 = F_37 ( & V_79 -> V_51 ,
V_82 -> V_16 * sizeof( char * ) ,
V_70 ) ;
if ( ! V_82 -> V_17 )
return - V_71 ;
}
V_17 = V_82 -> V_17 ;
while ( * V_17 )
V_17 ++ ;
* V_17 = V_22 -> V_20 ;
}
}
return 0 ;
}
int F_38 ( struct V_78 * V_79 )
{
struct V_83 * V_84 = F_39 ( & V_79 -> V_51 ) ;
struct V_13 * V_14 ;
struct V_85 * V_86 ;
unsigned V_35 , V_15 , V_87 ;
unsigned V_88 , V_89 = 0 ;
char * V_90 ;
void * V_91 ;
int V_42 ;
if ( ! V_84 || ! V_84 -> V_92 || ! V_84 -> V_93 ) {
F_22 ( & V_79 -> V_51 , L_16 ) ;
return - V_37 ;
}
V_14 = F_37 ( & V_79 -> V_51 , sizeof( struct V_13 ) ,
V_70 ) ;
if ( ! V_14 )
return - V_71 ;
V_14 -> V_81 . V_20 = F_40 ( & V_79 -> V_51 ) ;
V_14 -> V_81 . V_94 = V_95 ;
V_14 -> V_81 . V_96 = & V_97 ;
V_14 -> V_81 . V_98 = & V_99 ;
V_14 -> V_81 . V_100 = & V_101 ;
V_14 -> V_26 = V_84 -> V_26 ;
V_14 -> V_51 = & V_79 -> V_51 ;
F_41 ( V_79 , V_14 ) ;
V_14 -> V_16 = 0 ;
V_14 -> V_81 . V_19 = 0 ;
for ( V_15 = 0 ; V_15 < V_84 -> V_102 ; V_15 ++ ) {
const struct V_103 * V_36 = & V_84 -> V_92 [ V_15 ] ;
V_14 -> V_81 . V_19 += V_36 -> V_19 ;
for ( V_87 = 0 ; V_87 < V_36 -> V_19 ; V_87 ++ )
V_36 -> V_18 [ V_87 ] = V_36 -> V_3 + V_87 ;
if ( ! V_36 -> V_20 ) {
V_14 -> V_16 += V_36 -> V_19 ;
V_89 += V_36 -> V_19 ;
} else {
V_14 -> V_16 += 1 ;
}
}
V_86 = F_37 ( & V_79 -> V_51 , V_14 -> V_81 . V_19 *
sizeof( struct V_85 ) , V_70 ) ;
if ( ! V_86 )
return - V_71 ;
for ( V_15 = 0 ; V_15 < V_14 -> V_81 . V_19 ; V_15 ++ )
V_86 [ V_15 ] . V_104 = V_15 ;
V_14 -> V_81 . V_18 = V_86 ;
V_88 = V_14 -> V_16 * sizeof( * V_14 -> V_17 ) + V_89 * 8 ;
V_91 = F_37 ( & V_79 -> V_51 , V_88 , V_70 ) ;
if ( ! V_91 ) {
F_22 ( & V_79 -> V_51 , L_17 ) ;
return - V_71 ;
}
V_14 -> V_17 = V_91 ;
V_90 = V_91 + V_14 -> V_16 * sizeof( * V_14 -> V_17 ) ;
V_35 = 0 ;
for ( V_15 = 0 ; V_15 < V_84 -> V_102 ; V_15 ++ ) {
const struct V_103 * V_36 = & V_84 -> V_92 [ V_15 ] ;
struct V_1 * V_2 = V_84 -> V_105 ?
& V_84 -> V_105 [ V_15 ] : NULL ;
V_14 -> V_17 [ V_35 ] . V_35 = V_35 ;
V_14 -> V_17 [ V_35 ] . V_36 = V_36 ;
V_14 -> V_17 [ V_35 ] . V_2 = V_2 ;
V_14 -> V_17 [ V_35 ] . V_20 = V_36 -> V_20 ;
V_14 -> V_17 [ V_35 ] . V_18 = V_36 -> V_18 ;
V_14 -> V_17 [ V_35 ] . V_19 = V_36 -> V_19 ;
if ( ! V_36 -> V_20 ) {
V_14 -> V_17 [ V_35 ] . V_20 = V_90 ;
V_14 -> V_17 [ V_35 ] . V_19 = 1 ;
sprintf ( V_90 , L_18 , V_36 -> V_3 + 0 ) ;
V_90 += 8 ;
for ( V_87 = 1 ; V_87 < V_36 -> V_19 ; V_87 ++ ) {
V_35 ++ ;
V_14 -> V_17 [ V_35 ] . V_35 = V_35 ;
V_14 -> V_17 [ V_35 ] . V_36 = V_36 ;
V_14 -> V_17 [ V_35 ] . V_2 = V_2 ;
V_14 -> V_17 [ V_35 ] . V_20 = V_90 ;
V_14 -> V_17 [ V_35 ] . V_18 = & V_36 -> V_18 [ V_87 ] ;
V_14 -> V_17 [ V_35 ] . V_19 = 1 ;
sprintf ( V_90 , L_18 , V_36 -> V_3 + V_87 ) ;
V_90 += 8 ;
}
}
V_35 ++ ;
}
for ( V_15 = 0 ; V_15 < V_84 -> V_106 ; V_15 ++ ) {
struct V_107 * V_108 = & V_84 -> V_93 [ V_15 ] ;
struct V_21 * V_109 = & V_108 -> V_24 [ 0 ] ;
struct V_12 * V_22 ;
unsigned V_23 ;
unsigned V_110 ;
for ( V_23 = 0 , V_110 = 0 ; ; V_109 ++ ) {
if ( ! V_109 -> V_20 )
break;
V_23 ++ ;
if ( V_14 -> V_26 && ! ( V_14 -> V_26 & V_109 -> V_26 ) )
continue;
V_110 ++ ;
if ( strcmp ( V_109 -> V_20 , L_19 ) == 0 )
V_109 -> V_27 = V_29 |
V_28 ;
else if ( strcmp ( V_109 -> V_20 , L_20 ) == 0 )
V_109 -> V_27 = V_28 ;
else if ( strcmp ( V_109 -> V_20 , L_21 ) == 0 )
V_109 -> V_27 = V_29 ;
}
if ( ! V_110 )
continue;
V_22 = F_5 ( V_14 , V_108 -> V_3 ) ;
if ( ! V_22 ) {
F_42 ( & V_79 -> V_51 , L_22 ,
V_108 -> V_3 ) ;
continue;
}
V_22 -> V_24 = V_108 -> V_24 ;
V_22 -> V_23 = V_23 ;
}
V_42 = F_36 ( V_79 , V_14 ) ;
if ( V_42 ) {
F_22 ( & V_79 -> V_51 , L_23 ) ;
return V_42 ;
}
V_14 -> V_34 = F_43 ( & V_79 -> V_51 , & V_14 -> V_81 , V_14 ) ;
if ( F_44 ( V_14 -> V_34 ) ) {
F_22 ( & V_79 -> V_51 , L_24 ) ;
return F_45 ( V_14 -> V_34 ) ;
}
F_46 ( & V_79 -> V_51 , L_25 ) ;
for ( V_15 = 0 ; V_15 < V_84 -> V_111 ; V_15 ++ )
F_47 ( V_14 -> V_34 , & V_84 -> V_112 [ V_15 ] ) ;
return 0 ;
}
int F_48 ( struct V_78 * V_79 )
{
struct V_83 * V_84 = F_39 ( & V_79 -> V_51 ) ;
struct V_1 * V_113 ;
struct V_114 * V_115 ;
void T_1 * V_9 ;
int V_41 ;
V_115 = F_49 ( V_79 , V_116 , 0 ) ;
V_9 = F_50 ( & V_79 -> V_51 , V_115 ) ;
if ( F_44 ( V_9 ) )
return F_45 ( V_9 ) ;
V_113 = F_51 ( & V_79 -> V_51 , V_84 -> V_102 , sizeof( * V_113 ) ,
V_70 ) ;
if ( ! V_113 )
return - V_71 ;
for ( V_41 = 0 ; V_41 < V_84 -> V_102 ; V_41 ++ )
V_113 [ V_41 ] . V_9 = V_9 ;
V_84 -> V_105 = V_113 ;
return F_38 ( V_79 ) ;
}
int F_52 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned long * V_4 )
{
unsigned V_5 = ( V_3 / V_6 ) * V_7 ;
unsigned V_8 = ( V_3 % V_6 ) * V_7 ;
unsigned int V_25 ;
int V_117 ;
V_117 = F_53 ( V_2 -> V_118 . V_63 , V_2 -> V_118 . V_54 + V_5 , & V_25 ) ;
if ( V_117 )
return V_117 ;
* V_4 = ( V_25 >> V_8 ) & V_10 ;
return 0 ;
}
int F_54 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned long V_4 )
{
unsigned V_5 = ( V_3 / V_6 ) * V_7 ;
unsigned V_8 = ( V_3 % V_6 ) * V_7 ;
return F_55 ( V_2 -> V_118 . V_63 , V_2 -> V_118 . V_54 + V_5 ,
V_10 << V_8 , V_4 << V_8 ) ;
}
int F_56 ( struct V_78 * V_79 ,
struct V_119 * V_120 )
{
struct V_83 * V_84 = F_39 ( & V_79 -> V_51 ) ;
struct V_1 * V_113 ;
struct V_118 * V_118 ;
T_2 V_54 ;
int V_41 ;
V_118 = F_57 ( V_120 -> V_121 ) ;
if ( F_44 ( V_118 ) )
return F_45 ( V_118 ) ;
if ( F_58 ( V_79 -> V_51 . V_121 , L_26 , & V_54 ) )
return - V_37 ;
V_113 = F_51 ( & V_79 -> V_51 , V_84 -> V_102 , sizeof( * V_113 ) ,
V_70 ) ;
if ( ! V_113 )
return - V_71 ;
for ( V_41 = 0 ; V_41 < V_84 -> V_102 ; V_41 ++ ) {
V_113 [ V_41 ] . V_118 . V_63 = V_118 ;
V_113 [ V_41 ] . V_118 . V_54 = V_54 ;
}
V_84 -> V_105 = V_113 ;
return F_38 ( V_79 ) ;
}
