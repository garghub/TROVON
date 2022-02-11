static struct V_1 * F_1 (
struct V_2 * V_3 , unsigned V_4 )
{
unsigned V_5 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_6 ; V_5 ++ ) {
if ( V_4 >= V_3 -> V_7 [ V_5 ] . V_8 [ 0 ] &&
V_4 < V_3 -> V_7 [ V_5 ] . V_8 [ 0 ] +
V_3 -> V_7 [ V_5 ] . V_9 )
return & V_3 -> V_7 [ V_5 ] ;
}
return NULL ;
}
static struct V_1 * F_2 (
struct V_2 * V_3 , const char * V_10 )
{
unsigned V_5 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_6 ; V_5 ++ ) {
if ( strcmp ( V_10 , V_3 -> V_7 [ V_5 ] . V_10 ) == 0 )
return & V_3 -> V_7 [ V_5 ] ;
}
return NULL ;
}
static struct V_11 * F_3 (
struct V_2 * V_3 , struct V_1 * V_12 ,
unsigned long V_13 )
{
unsigned V_5 ;
for ( V_5 = 0 ; V_5 < V_12 -> V_14 ; V_5 ++ ) {
if ( V_13 == V_12 -> V_15 [ V_5 ] . V_16 ) {
if ( ! V_3 -> V_17 || ( V_3 -> V_17 &
V_12 -> V_15 [ V_5 ] . V_17 ) )
return & V_12 -> V_15 [ V_5 ] ;
}
}
return NULL ;
}
static struct V_11 * F_4 (
struct V_2 * V_3 , struct V_1 * V_12 ,
const char * V_10 )
{
unsigned V_5 ;
for ( V_5 = 0 ; V_5 < V_12 -> V_14 ; V_5 ++ ) {
if ( strcmp ( V_10 , V_12 -> V_15 [ V_5 ] . V_10 ) == 0 ) {
if ( ! V_3 -> V_17 || ( V_3 -> V_17 &
V_12 -> V_15 [ V_5 ] . V_17 ) )
return & V_12 -> V_15 [ V_5 ] ;
}
}
return NULL ;
}
static struct V_11 * F_5 (
struct V_2 * V_3 , struct V_1 * V_12 )
{
unsigned V_5 ;
for ( V_5 = 0 ; V_5 < V_12 -> V_14 ; V_5 ++ ) {
if ( V_12 -> V_15 [ V_5 ] . V_18 &
( V_19 | V_20 ) ) {
if ( ! V_3 -> V_17 || ( V_3 -> V_17 &
V_12 -> V_15 [ V_5 ] . V_17 ) )
return & V_12 -> V_15 [ V_5 ] ;
}
}
return NULL ;
}
static struct V_21 * F_6 (
struct V_2 * V_3 , const char * V_10 )
{
unsigned V_5 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_22 ; V_5 ++ ) {
if ( strcmp ( V_10 , V_3 -> V_23 [ V_5 ] . V_10 ) == 0 )
return & V_3 -> V_23 [ V_5 ] ;
}
return NULL ;
}
static int F_7 ( struct V_24 * V_25 ,
unsigned V_26 , unsigned long * V_13 )
{
struct V_2 * V_3 = F_8 ( V_25 ) ;
struct V_1 * V_12 = & V_3 -> V_7 [ V_26 ] ;
if ( ! V_12 -> V_27 )
return - V_28 ;
return V_12 -> V_27 -> V_29 ( V_12 -> V_8 [ 0 ] , V_13 ) ;
}
static int F_9 ( struct V_24 * V_25 ,
unsigned V_26 , unsigned long * V_30 ,
unsigned V_31 )
{
struct V_2 * V_3 = F_8 ( V_25 ) ;
struct V_1 * V_12 = & V_3 -> V_7 [ V_26 ] ;
int V_32 , V_33 ;
if ( ! V_12 -> V_27 )
return - V_28 ;
for ( V_32 = 0 ; V_32 < V_31 ; V_32 ++ ) {
V_33 = V_12 -> V_27 -> V_34 ( V_12 -> V_8 [ 0 ] , V_30 [ V_32 ] ) ;
if ( V_33 )
return V_33 ;
}
return 0 ;
}
static void F_10 ( struct V_24 * V_25 ,
struct V_35 * V_36 , unsigned V_26 )
{
struct V_2 * V_3 = F_8 ( V_25 ) ;
struct V_1 * V_12 = & V_3 -> V_7 [ V_26 ] ;
struct V_11 * V_37 ;
unsigned long V_13 ;
unsigned V_5 ;
if ( F_7 ( V_25 , V_26 , & V_13 ) )
return;
V_37 = F_3 ( V_3 , V_12 , V_13 ) ;
if ( V_37 ) {
F_11 ( V_36 , L_1 , V_37 -> V_10 ) ;
if ( V_37 -> V_38 )
F_11 ( V_36 , L_2 , V_37 -> V_38 ) ;
if ( V_37 -> V_18 & ( V_19 | V_20 ) ) {
F_11 ( V_36 , L_3 ) ;
if ( V_37 -> V_18 & V_20 )
F_11 ( V_36 , L_4 ) ;
if ( V_37 -> V_18 & V_19 )
F_11 ( V_36 , L_5 ) ;
F_11 ( V_36 , L_6 ) ;
}
} else
F_11 ( V_36 , L_7 ) ;
if ( V_12 -> V_14 > 1 ) {
F_11 ( V_36 , L_8 ) ;
for ( V_5 = 0 ; V_5 < V_12 -> V_14 ; V_5 ++ ) {
if ( V_37 == & V_12 -> V_15 [ V_5 ] )
continue;
if ( V_3 -> V_17 &&
! ( V_3 -> V_17 & V_12 -> V_15 [ V_5 ] . V_17 ) )
continue;
F_11 ( V_36 , L_9 , V_12 -> V_15 [ V_5 ] . V_10 ) ;
if ( V_12 -> V_15 [ V_5 ] . V_38 )
F_11 ( V_36 , L_2 , V_12 -> V_15 [ V_5 ] . V_38 ) ;
if ( V_12 -> V_15 [ V_5 ] . V_18 &
( V_19 | V_20 ) ) {
F_11 ( V_36 , L_3 ) ;
if ( V_12 -> V_15 [ V_5 ] . V_18 & V_20 )
F_11 ( V_36 , L_4 ) ;
if ( V_12 -> V_15 [ V_5 ] . V_18 & V_19 )
F_11 ( V_36 , L_5 ) ;
F_11 ( V_36 , L_6 ) ;
}
}
F_11 ( V_36 , L_10 ) ;
}
return;
}
static int F_12 ( struct V_24 * V_25 )
{
struct V_2 * V_3 = F_8 ( V_25 ) ;
return V_3 -> V_22 ;
}
static const char * F_13 ( struct V_24 * V_25 ,
unsigned V_39 )
{
struct V_2 * V_3 = F_8 ( V_25 ) ;
return V_3 -> V_23 [ V_39 ] . V_10 ;
}
static int F_14 ( struct V_24 * V_25 , unsigned V_39 ,
const char * const * * V_7 ,
unsigned * const V_6 )
{
struct V_2 * V_3 = F_8 ( V_25 ) ;
* V_7 = V_3 -> V_23 [ V_39 ] . V_7 ;
* V_6 = V_3 -> V_23 [ V_39 ] . V_6 ;
return 0 ;
}
static int F_15 ( struct V_24 * V_25 , unsigned V_39 ,
unsigned V_26 )
{
struct V_2 * V_3 = F_8 ( V_25 ) ;
struct V_21 * V_40 = & V_3 -> V_23 [ V_39 ] ;
struct V_1 * V_12 = & V_3 -> V_7 [ V_26 ] ;
struct V_11 * V_41 ;
int V_33 ;
unsigned long V_13 ;
V_41 = F_4 ( V_3 , V_12 ,
V_40 -> V_10 ) ;
if ( ! V_41 ) {
F_16 ( V_3 -> V_42 ,
L_11 ,
V_40 -> V_10 , V_40 -> V_7 [ V_26 ] ) ;
return - V_28 ;
}
V_13 = V_41 -> V_16 ;
V_33 = F_9 ( V_25 , V_12 -> V_26 , & V_13 , 1 ) ;
if ( V_33 ) {
F_16 ( V_3 -> V_42 , L_12 ,
V_40 -> V_7 [ V_26 ] , V_40 -> V_10 ) ;
return V_33 ;
}
return 0 ;
}
static int F_17 ( struct V_24 * V_25 ,
struct V_43 * V_44 , unsigned V_45 )
{
struct V_2 * V_3 = F_8 ( V_25 ) ;
struct V_1 * V_12 ;
struct V_11 * V_41 ;
unsigned long V_13 ;
V_12 = F_1 ( V_3 , V_45 ) ;
if ( ! V_12 )
return - V_28 ;
if ( V_12 -> V_27 -> V_46 )
return V_12 -> V_27 -> V_46 ( V_45 ) ;
V_41 = F_5 ( V_3 , V_12 ) ;
if ( ! V_41 )
return - V_47 ;
V_13 = V_41 -> V_16 ;
return F_9 ( V_25 , V_12 -> V_26 , & V_13 , 1 ) ;
}
static int F_18 ( struct V_24 * V_25 ,
struct V_43 * V_44 , unsigned V_45 , bool V_48 )
{
struct V_2 * V_3 = F_8 ( V_25 ) ;
struct V_1 * V_12 ;
struct V_11 * V_41 ;
V_12 = F_1 ( V_3 , V_45 ) ;
if ( ! V_12 )
return - V_28 ;
if ( V_12 -> V_27 -> V_49 )
return V_12 -> V_27 -> V_49 ( V_45 , V_48 ) ;
V_41 = F_5 ( V_3 , V_12 ) ;
if ( ! V_41 )
return - V_47 ;
if ( ( V_48 && ( V_41 -> V_18 & V_20 ) ) ||
( ! V_48 && ( V_41 -> V_18 & V_19 ) ) )
return 0 ;
return - V_47 ;
}
static int F_19 ( struct V_24 * V_25 )
{
struct V_2 * V_3 = F_8 ( V_25 ) ;
return V_3 -> V_6 ;
}
static const char * F_20 ( struct V_24 * V_25 ,
unsigned V_26 )
{
struct V_2 * V_3 = F_8 ( V_25 ) ;
return V_3 -> V_7 [ V_26 ] . V_10 ;
}
static int F_21 ( struct V_24 * V_25 ,
unsigned V_26 , const unsigned * * V_8 ,
unsigned * V_50 )
{
struct V_2 * V_3 = F_8 ( V_25 ) ;
* V_8 = V_3 -> V_7 [ V_26 ] . V_8 ;
* V_50 = V_3 -> V_7 [ V_26 ] . V_9 ;
return 0 ;
}
static int F_22 ( struct V_24 * V_25 ,
struct V_51 * V_52 ,
struct V_53 * * V_54 ,
unsigned * V_55 )
{
struct V_2 * V_3 = F_8 ( V_25 ) ;
struct V_56 * V_57 ;
const char * V_58 ;
const char * V_59 ;
int V_33 , V_60 , V_5 ;
* V_54 = NULL ;
* V_55 = 0 ;
V_33 = F_23 ( V_52 , L_13 , & V_58 ) ;
if ( V_33 ) {
F_16 ( V_3 -> V_42 ,
L_14 , V_52 -> V_10 ) ;
return 0 ;
}
V_60 = F_24 ( V_52 , L_15 ) ;
if ( V_60 < 0 ) {
F_16 ( V_3 -> V_42 ,
L_16 , V_52 -> V_10 ) ;
return 0 ;
}
* V_54 = F_25 ( V_60 * sizeof( struct V_53 ) , V_61 ) ;
if ( * V_54 == NULL ) {
F_16 ( V_3 -> V_42 ,
L_17 ,
V_52 -> V_10 ) ;
return - V_62 ;
}
V_5 = 0 ;
F_26 (np, L_15 , prop, group) {
struct V_1 * V_12 =
F_2 ( V_3 , V_59 ) ;
if ( ! V_12 ) {
F_16 ( V_3 -> V_42 , L_18 , V_59 ) ;
continue;
}
if ( ! F_4 ( V_3 , V_12 , V_58 ) ) {
F_16 ( V_3 -> V_42 , L_19 ,
V_58 , V_59 ) ;
continue;
}
( * V_54 ) [ V_5 ] . type = V_63 ;
( * V_54 ) [ V_5 ] . V_64 . V_65 . V_59 = V_59 ;
( * V_54 ) [ V_5 ] . V_64 . V_65 . V_58 = V_58 ;
V_5 ++ ;
}
* V_55 = V_60 ;
return 0 ;
}
static void F_27 ( struct V_24 * V_25 ,
struct V_53 * V_54 , unsigned V_55 )
{
F_28 ( V_54 ) ;
}
static int F_29 ( struct V_21 * V_66 , int * V_67 ,
const char * V_10 )
{
if ( * V_67 <= 0 )
return - V_68 ;
while ( V_66 -> V_6 ) {
if ( strcmp ( V_66 -> V_10 , V_10 ) == 0 ) {
V_66 -> V_6 ++ ;
return - V_69 ;
}
V_66 ++ ;
}
V_66 -> V_10 = V_10 ;
V_66 -> V_6 = 1 ;
( * V_67 ) -- ;
return 0 ;
}
static int F_30 ( struct V_70 * V_71 ,
struct V_2 * V_3 )
{
struct V_21 * V_66 ;
int V_72 = 0 , V_67 = V_3 -> V_73 . V_9 ;
int V_5 , V_36 ;
V_66 = F_31 ( & V_71 -> V_42 , V_67 *
sizeof( struct V_21 ) , V_61 ) ;
if ( ! V_66 )
return - V_62 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_6 ; V_5 ++ ) {
struct V_1 * V_12 = & V_3 -> V_7 [ V_5 ] ;
for ( V_36 = 0 ; V_36 < V_12 -> V_14 ; V_36 ++ ) {
int V_33 ;
if ( V_3 -> V_17 &&
! ( V_3 -> V_17 & V_12 -> V_15 [ V_36 ] . V_17 ) )
continue;
V_33 = F_29 ( V_66 , & V_67 ,
V_12 -> V_15 [ V_36 ] . V_10 ) ;
if ( V_33 == - V_68 )
F_16 ( & V_71 -> V_42 ,
L_20 ,
V_3 -> V_73 . V_9 ) ;
if ( V_33 < 0 )
continue;
V_72 ++ ;
}
}
V_3 -> V_22 = V_72 ;
V_3 -> V_23 = V_66 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_6 ; V_5 ++ ) {
struct V_1 * V_12 = & V_3 -> V_7 [ V_5 ] ;
for ( V_36 = 0 ; V_36 < V_12 -> V_14 ; V_36 ++ ) {
struct V_21 * V_74 ;
const char * * V_7 ;
if ( V_3 -> V_17 &&
! ( V_3 -> V_17 & V_12 -> V_15 [ V_36 ] . V_17 ) )
continue;
V_74 = F_6 ( V_3 ,
V_12 -> V_15 [ V_36 ] . V_10 ) ;
if ( ! V_74 -> V_7 ) {
V_74 -> V_7 = F_31 ( & V_71 -> V_42 ,
V_74 -> V_6 * sizeof( char * ) ,
V_61 ) ;
if ( ! V_74 -> V_7 )
return - V_62 ;
}
V_7 = V_74 -> V_7 ;
while ( * V_7 )
V_7 ++ ;
* V_7 = V_12 -> V_10 ;
}
}
return 0 ;
}
int F_32 ( struct V_70 * V_71 )
{
struct V_75 * V_76 = F_33 ( & V_71 -> V_42 ) ;
struct V_2 * V_3 ;
struct V_77 * V_78 ;
unsigned V_26 , V_5 , V_79 ;
unsigned V_80 , V_81 = 0 ;
char * V_82 ;
void * V_83 ;
int V_33 ;
if ( ! V_76 || ! V_76 -> V_84 || ! V_76 -> V_85 ) {
F_16 ( & V_71 -> V_42 , L_21 ) ;
return - V_28 ;
}
V_3 = F_31 ( & V_71 -> V_42 , sizeof( struct V_2 ) ,
V_61 ) ;
if ( ! V_3 ) {
F_16 ( & V_71 -> V_42 , L_22 ) ;
return - V_62 ;
}
V_3 -> V_73 . V_10 = F_34 ( & V_71 -> V_42 ) ;
V_3 -> V_73 . V_86 = V_87 ;
V_3 -> V_73 . V_88 = & V_89 ;
V_3 -> V_73 . V_90 = & V_91 ;
V_3 -> V_73 . V_92 = & V_93 ;
V_3 -> V_17 = V_76 -> V_17 ;
V_3 -> V_42 = & V_71 -> V_42 ;
F_35 ( V_71 , V_3 ) ;
V_3 -> V_6 = 0 ;
V_3 -> V_73 . V_9 = 0 ;
for ( V_5 = 0 ; V_5 < V_76 -> V_94 ; V_5 ++ ) {
struct V_95 * V_27 = & V_76 -> V_84 [ V_5 ] ;
V_3 -> V_73 . V_9 += V_27 -> V_9 ;
for ( V_79 = 0 ; V_79 < V_27 -> V_9 ; V_79 ++ )
V_27 -> V_8 [ V_79 ] = V_27 -> V_4 + V_79 ;
if ( ! V_27 -> V_10 ) {
V_3 -> V_6 += V_27 -> V_9 ;
V_81 += V_27 -> V_9 ;
} else {
V_3 -> V_6 += 1 ;
}
}
V_78 = F_31 ( & V_71 -> V_42 , V_3 -> V_73 . V_9 *
sizeof( struct V_77 ) , V_61 ) ;
if ( ! V_78 ) {
F_16 ( & V_71 -> V_42 , L_23 ) ;
return - V_62 ;
}
for ( V_5 = 0 ; V_5 < V_3 -> V_73 . V_9 ; V_5 ++ )
V_78 [ V_5 ] . V_96 = V_5 ;
V_3 -> V_73 . V_8 = V_78 ;
V_80 = V_3 -> V_6 * sizeof( * V_3 -> V_7 ) + V_81 * 8 ;
V_83 = F_31 ( & V_71 -> V_42 , V_80 , V_61 ) ;
if ( ! V_83 ) {
F_16 ( & V_71 -> V_42 , L_24 ) ;
return - V_62 ;
}
V_3 -> V_7 = V_83 ;
V_82 = V_83 + V_3 -> V_6 * sizeof( * V_3 -> V_7 ) ;
V_26 = 0 ;
for ( V_5 = 0 ; V_5 < V_76 -> V_94 ; V_5 ++ ) {
struct V_95 * V_27 = & V_76 -> V_84 [ V_5 ] ;
V_3 -> V_7 [ V_26 ] . V_26 = V_26 ;
V_3 -> V_7 [ V_26 ] . V_27 = V_27 ;
V_3 -> V_7 [ V_26 ] . V_10 = V_27 -> V_10 ;
V_3 -> V_7 [ V_26 ] . V_8 = V_27 -> V_8 ;
V_3 -> V_7 [ V_26 ] . V_9 = V_27 -> V_9 ;
if ( ! V_27 -> V_10 ) {
V_3 -> V_7 [ V_26 ] . V_10 = V_82 ;
V_3 -> V_7 [ V_26 ] . V_9 = 1 ;
sprintf ( V_82 , L_25 , V_27 -> V_4 + 0 ) ;
V_82 += 8 ;
for ( V_79 = 1 ; V_79 < V_27 -> V_9 ; V_79 ++ ) {
V_26 ++ ;
V_3 -> V_7 [ V_26 ] . V_26 = V_26 ;
V_3 -> V_7 [ V_26 ] . V_27 = V_27 ;
V_3 -> V_7 [ V_26 ] . V_10 = V_82 ;
V_3 -> V_7 [ V_26 ] . V_8 = & V_27 -> V_8 [ V_79 ] ;
V_3 -> V_7 [ V_26 ] . V_9 = 1 ;
sprintf ( V_82 , L_25 , V_27 -> V_4 + V_79 ) ;
V_82 += 8 ;
}
}
V_26 ++ ;
}
for ( V_5 = 0 ; V_5 < V_76 -> V_97 ; V_5 ++ ) {
struct V_98 * V_99 = & V_76 -> V_85 [ V_5 ] ;
struct V_1 * V_12 =
F_1 ( V_3 , V_99 -> V_4 ) ;
unsigned V_14 ;
if ( ! V_12 ) {
F_36 ( & V_71 -> V_42 , L_26 ,
V_99 -> V_4 ) ;
continue;
}
for ( V_14 = 0 ; ; ) {
struct V_11 * V_100 =
& V_99 -> V_15 [ V_14 ] ;
if ( ! V_100 -> V_10 )
break;
V_14 ++ ;
if ( V_3 -> V_17 && ! ( V_3 -> V_17 & V_100 -> V_17 ) )
continue;
if ( strcmp ( V_100 -> V_10 , L_27 ) == 0 )
V_100 -> V_18 = V_20 |
V_19 ;
else if ( strcmp ( V_100 -> V_10 , L_28 ) == 0 )
V_100 -> V_18 = V_19 ;
else if ( strcmp ( V_100 -> V_10 , L_29 ) == 0 )
V_100 -> V_18 = V_20 ;
}
V_12 -> V_15 = V_99 -> V_15 ;
V_12 -> V_14 = V_14 ;
}
V_33 = F_30 ( V_71 , V_3 ) ;
if ( V_33 ) {
F_16 ( & V_71 -> V_42 , L_30 ) ;
return V_33 ;
}
V_3 -> V_25 = F_37 ( & V_3 -> V_73 , & V_71 -> V_42 , V_3 ) ;
if ( F_38 ( V_3 -> V_25 ) ) {
F_16 ( & V_71 -> V_42 , L_31 ) ;
return F_39 ( V_3 -> V_25 ) ;
}
F_40 ( & V_71 -> V_42 , L_32 ) ;
for ( V_5 = 0 ; V_5 < V_76 -> V_101 ; V_5 ++ )
F_41 ( V_3 -> V_25 , & V_76 -> V_102 [ V_5 ] ) ;
return 0 ;
}
int F_42 ( struct V_70 * V_71 )
{
struct V_2 * V_3 = F_43 ( V_71 ) ;
F_44 ( V_3 -> V_25 ) ;
return 0 ;
}
