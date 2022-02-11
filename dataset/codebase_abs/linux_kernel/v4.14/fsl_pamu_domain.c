static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_2 ) ;
}
static int T_1 F_3 ( void )
{
V_4 = F_4 ( L_1 ,
sizeof( struct V_1 ) ,
0 ,
V_5 ,
NULL ) ;
if ( ! V_4 ) {
F_5 ( L_2 ) ;
return - V_6 ;
}
V_7 = F_4 ( L_3 ,
sizeof( struct V_8 ) ,
0 ,
V_5 ,
NULL ) ;
if ( ! V_7 ) {
F_5 ( L_4 ) ;
F_6 ( V_4 ) ;
return - V_6 ;
}
return 0 ;
}
static T_2 F_7 ( struct V_1 * V_9 , T_3 V_10 )
{
T_4 V_11 = V_9 -> V_11 ;
struct V_12 * V_13 = & V_9 -> V_14 [ 0 ] ;
struct V_15 * V_16 ;
V_16 = & V_9 -> V_2 . V_17 ;
if ( ! V_11 || ! V_9 -> V_18 ) {
F_5 ( L_5 ) ;
return 0 ;
}
if ( V_11 > 1 ) {
T_5 V_19 ;
T_3 V_20 ;
T_4 V_21 ;
V_19 = V_9 -> V_18 >> F_8 ( V_11 ) ;
V_20 = V_10 & ~ ( V_19 - 1 ) ;
V_21 = ( V_20 - V_16 -> V_22 ) >> F_8 ( V_19 ) ;
V_13 = & V_9 -> V_14 [ V_21 ] ;
}
if ( V_13 -> V_23 )
return V_13 -> V_24 + ( V_10 & ( V_13 -> V_25 - 1 ) ) ;
return 0 ;
}
static int F_9 ( int V_26 , struct V_1 * V_9 )
{
struct V_12 * V_27 = & V_9 -> V_14 [ 0 ] ;
int V_28 , V_29 ;
unsigned long V_30 , V_31 ;
for ( V_28 = 0 ; V_28 < V_9 -> V_11 ; V_28 ++ ) {
if ( V_27 [ V_28 ] . V_23 ) {
V_30 = V_27 [ V_28 ] . V_24 >> V_32 ;
F_10 ( & V_33 , V_31 ) ;
V_29 = F_11 ( V_26 , V_9 -> V_11 , V_28 ,
V_27 [ V_28 ] . V_25 ,
~ ( T_4 ) 0 ,
V_30 ,
V_9 -> V_34 ,
V_9 -> V_35 ,
( V_28 > 0 ) ? 1 : 0 ,
V_27 [ V_28 ] . V_36 ) ;
F_12 ( & V_33 , V_31 ) ;
if ( V_29 ) {
F_5 ( L_6 ,
V_26 ) ;
return V_29 ;
}
}
}
return V_29 ;
}
static int F_13 ( int V_26 , struct V_1 * V_9 )
{
int V_29 ;
struct V_12 * V_21 = & V_9 -> V_14 [ 0 ] ;
T_2 V_37 = V_9 -> V_2 . V_17 . V_22 ;
unsigned long V_31 ;
F_10 ( & V_33 , V_31 ) ;
V_29 = F_14 ( V_26 , V_37 ,
V_21 -> V_25 ,
~ ( T_4 ) 0 ,
V_21 -> V_24 >> V_32 ,
V_9 -> V_34 , V_9 -> V_35 ,
0 , V_21 -> V_36 ) ;
F_12 ( & V_33 , V_31 ) ;
if ( V_29 )
F_5 ( L_7 , V_26 ) ;
return V_29 ;
}
static int F_15 ( int V_26 , struct V_1 * V_9 )
{
if ( V_9 -> V_11 > 1 )
return F_9 ( V_26 , V_9 ) ;
else
return F_13 ( V_26 , V_9 ) ;
}
static int F_16 ( int V_26 , struct V_1 * V_9 , T_4 V_38 )
{
int V_29 ;
struct V_12 * V_21 = & V_9 -> V_14 [ V_38 ] ;
unsigned long V_31 ;
F_10 ( & V_33 , V_31 ) ;
if ( V_9 -> V_11 > 1 ) {
V_29 = F_11 ( V_26 , V_9 -> V_11 , V_38 ,
V_21 -> V_25 ,
~ ( T_4 ) 0 ,
V_21 -> V_24 >> V_32 ,
V_9 -> V_34 ,
V_9 -> V_35 ,
( V_38 > 0 ) ? 1 : 0 ,
V_21 -> V_36 ) ;
if ( V_29 )
F_5 ( L_8 ,
V_26 ) ;
} else {
T_2 V_37 ;
V_37 = V_9 -> V_2 . V_17 . V_22 ;
V_29 = F_14 ( V_26 , V_37 ,
V_21 -> V_25 ,
~ ( T_4 ) 0 ,
V_21 -> V_24 >> V_32 ,
V_9 -> V_34 , V_9 -> V_35 ,
0 , V_21 -> V_36 ) ;
if ( V_29 )
F_5 ( L_9 ,
V_26 ) ;
}
F_12 ( & V_33 , V_31 ) ;
return V_29 ;
}
static int F_17 ( int V_26 , struct V_1 * V_9 ,
T_4 V_39 )
{
int V_29 = 0 , V_28 ;
unsigned long V_31 ;
F_10 ( & V_33 , V_31 ) ;
if ( ! V_9 -> V_14 ) {
F_5 ( L_10 ,
V_26 ) ;
F_12 ( & V_33 , V_31 ) ;
return - V_40 ;
}
for ( V_28 = 0 ; V_28 < V_9 -> V_11 ; V_28 ++ ) {
V_29 = F_18 ( V_26 , V_28 , V_39 ) ;
if ( V_29 ) {
F_5 ( L_11 ,
V_28 , V_26 ) ;
F_12 ( & V_33 , V_31 ) ;
return V_29 ;
}
}
F_12 ( & V_33 , V_31 ) ;
return V_29 ;
}
static int F_19 ( int V_26 , struct V_41 * V_42 ,
struct V_1 * V_9 ,
struct V_15 * V_43 ,
T_4 V_11 )
{
T_2 V_44 , V_45 ;
T_2 V_19 ;
int V_29 = 0 , V_28 ;
T_4 V_46 = ~ ( T_4 ) 0 ;
unsigned long V_31 ;
F_20 ( & V_46 , V_42 ) ;
V_44 = V_43 -> V_22 ;
V_45 = V_9 -> V_18 ;
F_10 ( & V_33 , V_31 ) ;
V_29 = F_21 ( V_26 ) ;
if ( ! V_29 )
V_29 = F_14 ( V_26 , V_44 , V_45 , V_46 ,
0 , V_9 -> V_34 ,
V_9 -> V_35 , V_11 , 0 ) ;
F_12 ( & V_33 , V_31 ) ;
if ( V_29 ) {
F_5 ( L_12 ,
V_26 , V_11 ) ;
return V_29 ;
}
if ( V_11 > 1 ) {
V_19 = V_45 >> F_8 ( V_11 ) ;
for ( V_28 = 0 ; V_28 < V_11 ; V_28 ++ ) {
F_10 ( & V_33 , V_31 ) ;
V_29 = F_22 ( V_26 , V_28 ) ;
if ( ! V_29 )
V_29 = F_11 ( V_26 , V_11 , V_28 ,
V_19 , V_46 ,
0 , V_9 -> V_34 ,
V_9 -> V_35 ,
0 , 0 ) ;
F_12 ( & V_33 , V_31 ) ;
if ( V_29 ) {
F_5 ( L_6 ,
V_26 ) ;
return V_29 ;
}
}
}
return V_29 ;
}
static int F_23 ( T_5 V_25 , T_3 V_10 )
{
if ( ( V_25 & ( V_25 - 1 ) ) || V_25 < V_47 ) {
F_5 ( L_13 ) ;
return - V_40 ;
}
if ( V_10 & ( V_25 - 1 ) ) {
F_5 ( L_14 ) ;
return - V_40 ;
}
return 0 ;
}
static struct V_1 * F_24 ( void )
{
struct V_1 * V_48 ;
V_48 = F_25 ( V_4 , V_49 ) ;
if ( ! V_48 )
return NULL ;
V_48 -> V_35 = ~ ( T_4 ) 0 ;
V_48 -> V_34 = ~ ( T_4 ) 0 ;
V_48 -> V_11 = F_26 () ;
V_48 -> V_18 = 0 ;
F_27 ( & V_48 -> V_50 ) ;
F_28 ( & V_48 -> V_51 ) ;
return V_48 ;
}
static void F_29 ( struct V_8 * V_52 , T_4 V_11 )
{
unsigned long V_31 ;
F_30 ( & V_52 -> V_53 ) ;
F_10 ( & V_33 , V_31 ) ;
if ( V_11 > 1 )
F_31 ( V_52 -> V_26 ) ;
F_21 ( V_52 -> V_26 ) ;
F_12 ( & V_33 , V_31 ) ;
F_10 ( & V_54 , V_31 ) ;
V_52 -> V_42 -> V_55 . V_2 = NULL ;
F_32 ( V_7 , V_52 ) ;
F_12 ( & V_54 , V_31 ) ;
}
static void F_33 ( struct V_41 * V_42 , struct V_1 * V_9 )
{
struct V_8 * V_52 , * V_56 ;
unsigned long V_31 ;
F_10 ( & V_9 -> V_51 , V_31 ) ;
F_34 (info, tmp, &dma_domain->devices, link) {
if ( ! V_42 || ( V_52 -> V_42 == V_42 ) )
F_29 ( V_52 , V_9 -> V_11 ) ;
}
F_12 ( & V_9 -> V_51 , V_31 ) ;
}
static void F_35 ( struct V_1 * V_9 , int V_26 , struct V_41 * V_42 )
{
struct V_8 * V_52 , * V_57 ;
unsigned long V_31 ;
F_10 ( & V_54 , V_31 ) ;
V_57 = V_42 -> V_55 . V_2 ;
if ( V_57 && V_57 -> V_48 != V_9 ) {
F_12 ( & V_54 , V_31 ) ;
F_33 ( V_42 , V_57 -> V_48 ) ;
F_10 ( & V_54 , V_31 ) ;
}
V_52 = F_25 ( V_7 , V_58 ) ;
V_52 -> V_42 = V_42 ;
V_52 -> V_26 = V_26 ;
V_52 -> V_48 = V_9 ;
F_36 ( & V_52 -> V_53 , & V_9 -> V_50 ) ;
if ( ! V_42 -> V_55 . V_2 )
V_42 -> V_55 . V_2 = V_52 ;
F_12 ( & V_54 , V_31 ) ;
}
static T_2 F_37 ( struct V_2 * V_48 ,
T_3 V_10 )
{
struct V_1 * V_9 = F_1 ( V_48 ) ;
if ( V_10 < V_48 -> V_17 . V_22 ||
V_10 > V_48 -> V_17 . V_59 )
return 0 ;
return F_7 ( V_9 , V_10 ) ;
}
static bool F_38 ( enum V_60 V_61 )
{
return V_61 == V_62 ;
}
static void F_39 ( struct V_2 * V_48 )
{
struct V_1 * V_9 = F_1 ( V_48 ) ;
F_33 ( NULL , V_9 ) ;
V_9 -> V_63 = 0 ;
V_9 -> V_64 = 0 ;
F_32 ( V_4 , V_9 ) ;
}
static struct V_2 * F_40 ( unsigned type )
{
struct V_1 * V_9 ;
if ( type != V_65 )
return NULL ;
V_9 = F_24 () ;
if ( ! V_9 ) {
F_5 ( L_15 ) ;
return NULL ;
}
V_9 -> V_2 . V_17 . V_22 = 0 ;
V_9 -> V_2 . V_17 . V_59 = ( 1ULL << 36 ) - 1 ;
V_9 -> V_2 . V_17 . V_66 = true ;
return & V_9 -> V_2 ;
}
static int F_41 ( struct V_1 * V_9 ,
struct V_15 * V_43 ,
T_4 V_11 )
{
struct V_8 * V_52 ;
int V_29 = 0 ;
F_42 (info, &dma_domain->devices, link) {
V_29 = F_19 ( V_52 -> V_26 , V_52 -> V_42 , V_9 ,
V_43 , V_11 ) ;
if ( V_29 )
break;
}
return V_29 ;
}
static int F_43 ( struct V_1 * V_9 , T_4 V_39 )
{
struct V_8 * V_52 ;
int V_29 = 0 ;
F_42 (info, &dma_domain->devices, link) {
V_29 = F_17 ( V_52 -> V_26 , V_9 , V_39 ) ;
if ( V_29 )
break;
}
return V_29 ;
}
static int F_44 ( struct V_1 * V_9 , T_4 V_38 )
{
struct V_8 * V_52 ;
int V_29 = 0 ;
F_42 (info, &dma_domain->devices, link) {
V_29 = F_16 ( V_52 -> V_26 , V_9 , V_38 ) ;
if ( V_29 )
break;
}
return V_29 ;
}
static int F_45 ( struct V_1 * V_9 , T_4 V_38 )
{
struct V_8 * V_52 ;
int V_29 = 0 ;
F_42 (info, &dma_domain->devices, link) {
if ( V_9 -> V_11 == 1 && V_9 -> V_63 ) {
V_29 = F_21 ( V_52 -> V_26 ) ;
if ( ! V_29 )
V_9 -> V_63 = 0 ;
} else {
V_29 = F_22 ( V_52 -> V_26 , V_38 ) ;
}
}
return V_29 ;
}
static void F_46 ( struct V_2 * V_48 , T_4 V_38 )
{
struct V_1 * V_9 = F_1 ( V_48 ) ;
unsigned long V_31 ;
int V_29 ;
F_10 ( & V_9 -> V_51 , V_31 ) ;
if ( ! V_9 -> V_14 ) {
F_5 ( L_16 ) ;
F_12 ( & V_9 -> V_51 , V_31 ) ;
return;
}
if ( V_38 >= V_9 -> V_11 ) {
F_5 ( L_17 ) ;
F_12 ( & V_9 -> V_51 , V_31 ) ;
return;
}
if ( V_9 -> V_14 [ V_38 ] . V_23 ) {
V_29 = F_45 ( V_9 , V_38 ) ;
if ( ! V_29 ) {
V_9 -> V_14 [ V_38 ] . V_23 = 0 ;
V_9 -> V_64 -- ;
}
}
F_12 ( & V_9 -> V_51 , V_31 ) ;
}
static int F_47 ( struct V_2 * V_48 , T_4 V_38 ,
T_2 V_24 , T_5 V_25 , int V_36 )
{
struct V_1 * V_9 = F_1 ( V_48 ) ;
struct V_12 * V_21 ;
int V_67 = 0 ;
int V_29 ;
unsigned long V_31 ;
T_5 V_68 ;
if ( V_36 & V_69 )
V_67 |= V_70 ;
if ( V_36 & V_71 )
V_67 |= V_72 ;
F_10 ( & V_9 -> V_51 , V_31 ) ;
if ( ! V_9 -> V_14 ) {
F_5 ( L_16 ) ;
F_12 ( & V_9 -> V_51 , V_31 ) ;
return - V_73 ;
}
if ( V_38 >= V_9 -> V_11 ) {
F_5 ( L_17 ) ;
F_12 ( & V_9 -> V_51 , V_31 ) ;
return - V_40 ;
}
V_68 = V_9 -> V_18 >> F_8 ( V_9 -> V_11 ) ;
if ( V_25 > V_68 ) {
F_5 ( L_18 ) ;
F_12 ( & V_9 -> V_51 , V_31 ) ;
return - V_40 ;
}
if ( V_9 -> V_11 == 1 ) {
if ( V_9 -> V_63 ) {
F_5 ( L_19 ) ;
F_12 ( & V_9 -> V_51 , V_31 ) ;
return - V_74 ;
}
V_29 = F_23 ( V_25 , V_48 -> V_17 . V_22 ) ;
if ( V_29 ) {
F_5 ( L_20 ) ;
F_12 ( & V_9 -> V_51 , V_31 ) ;
return - V_40 ;
}
}
V_21 = & V_9 -> V_14 [ V_38 ] ;
if ( ! V_21 -> V_23 ) {
V_21 -> V_24 = V_24 ;
V_21 -> V_25 = V_25 ;
V_21 -> V_36 = V_67 ;
V_29 = F_44 ( V_9 , V_38 ) ;
if ( ! V_29 ) {
V_21 -> V_23 = 1 ;
V_9 -> V_64 ++ ;
}
} else {
F_5 ( L_19 ) ;
V_29 = - V_74 ;
}
F_12 ( & V_9 -> V_51 , V_31 ) ;
return V_29 ;
}
static int F_48 ( struct V_1 * V_9 ,
struct V_41 * V_42 , const T_4 * V_26 ,
int V_75 )
{
unsigned long V_31 ;
struct V_2 * V_48 = & V_9 -> V_2 ;
int V_29 = 0 ;
int V_28 ;
F_10 ( & V_9 -> V_51 , V_31 ) ;
for ( V_28 = 0 ; V_28 < V_75 ; V_28 ++ ) {
if ( V_26 [ V_28 ] >= V_76 ) {
F_5 ( L_21 ,
V_26 [ V_28 ] , V_42 -> V_77 ) ;
V_29 = - V_40 ;
break;
}
F_35 ( V_9 , V_26 [ V_28 ] , V_42 ) ;
if ( V_9 -> V_14 ) {
T_4 V_11 = V_9 -> V_11 > 1 ? V_9 -> V_11 : 0 ;
V_29 = F_19 ( V_26 [ V_28 ] , V_42 , V_9 ,
& V_48 -> V_17 , V_11 ) ;
if ( V_29 )
break;
if ( V_9 -> V_64 ) {
V_29 = F_15 ( V_26 [ V_28 ] , V_9 ) ;
if ( V_29 )
break;
}
}
}
F_12 ( & V_9 -> V_51 , V_31 ) ;
return V_29 ;
}
static int F_49 ( struct V_2 * V_48 ,
struct V_41 * V_42 )
{
struct V_1 * V_9 = F_1 ( V_48 ) ;
const T_4 * V_26 ;
T_4 V_78 ;
int V_79 , V_29 = 0 ;
struct V_80 * V_81 = NULL ;
struct V_82 * V_83 ;
if ( F_50 ( V_42 ) ) {
V_81 = F_51 ( V_42 ) ;
V_83 = F_52 ( V_81 -> V_84 ) ;
V_42 = V_83 -> V_85 ;
}
V_26 = F_53 ( V_42 -> V_77 , L_22 , & V_79 ) ;
if ( V_26 ) {
V_78 = V_79 / sizeof( T_4 ) ;
V_29 = F_48 ( V_9 , V_42 , V_26 , V_78 ) ;
} else {
F_5 ( L_23 , V_42 -> V_77 ) ;
V_29 = - V_40 ;
}
return V_29 ;
}
static void F_54 ( struct V_2 * V_48 ,
struct V_41 * V_42 )
{
struct V_1 * V_9 = F_1 ( V_48 ) ;
const T_4 * V_86 ;
int V_79 ;
struct V_80 * V_81 = NULL ;
struct V_82 * V_83 ;
if ( F_50 ( V_42 ) ) {
V_81 = F_51 ( V_42 ) ;
V_83 = F_52 ( V_81 -> V_84 ) ;
V_42 = V_83 -> V_85 ;
}
V_86 = F_53 ( V_42 -> V_77 , L_22 , & V_79 ) ;
if ( V_86 )
F_33 ( V_42 , V_9 ) ;
else
F_5 ( L_23 , V_42 -> V_77 ) ;
}
static int F_55 ( struct V_2 * V_48 , void * V_87 )
{
struct V_15 * V_43 = V_87 ;
struct V_1 * V_9 = F_1 ( V_48 ) ;
T_3 V_18 ;
unsigned long V_31 ;
V_18 = V_43 -> V_59 - V_43 -> V_22 + 1 ;
if ( F_23 ( V_18 , V_43 -> V_22 ) ||
! V_43 -> V_66 ) {
F_5 ( L_24 ) ;
return - V_40 ;
}
F_10 ( & V_9 -> V_51 , V_31 ) ;
if ( V_9 -> V_63 ) {
F_5 ( L_25 ) ;
F_12 ( & V_9 -> V_51 , V_31 ) ;
return - V_74 ;
}
memcpy ( & V_48 -> V_17 , V_43 ,
sizeof( struct V_15 ) ) ;
V_9 -> V_18 = V_18 ;
F_12 ( & V_9 -> V_51 , V_31 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_9 , void * V_87 )
{
struct V_88 * V_89 = V_87 ;
unsigned long V_31 ;
int V_29 ;
F_10 ( & V_9 -> V_51 , V_31 ) ;
memcpy ( & V_9 -> V_90 , V_89 ,
sizeof( struct V_88 ) ) ;
V_9 -> V_35 = F_57 ( V_89 -> V_91 ,
V_89 -> V_92 ) ;
if ( V_9 -> V_35 == ~ ( T_4 ) 0 ) {
F_5 ( L_26 ) ;
F_12 ( & V_9 -> V_51 , V_31 ) ;
return - V_40 ;
}
V_29 = F_43 ( V_9 , V_9 -> V_35 ) ;
F_12 ( & V_9 -> V_51 , V_31 ) ;
return V_29 ;
}
static int F_58 ( struct V_1 * V_9 , bool V_93 )
{
struct V_8 * V_52 ;
unsigned long V_31 ;
int V_29 ;
F_10 ( & V_9 -> V_51 , V_31 ) ;
if ( V_93 && ! V_9 -> V_64 ) {
F_5 ( L_27 ) ;
F_12 ( & V_9 -> V_51 , V_31 ) ;
return - V_73 ;
}
V_9 -> V_63 = V_93 ;
F_42 (info, &dma_domain->devices, link) {
V_29 = ( V_93 ) ? F_59 ( V_52 -> V_26 ) :
F_21 ( V_52 -> V_26 ) ;
if ( V_29 )
F_5 ( L_28 ,
V_52 -> V_26 ) ;
}
F_12 ( & V_9 -> V_51 , V_31 ) ;
return 0 ;
}
static int F_60 ( struct V_2 * V_48 ,
enum V_94 V_95 , void * V_87 )
{
struct V_1 * V_9 = F_1 ( V_48 ) ;
int V_29 = 0 ;
switch ( V_95 ) {
case V_96 :
V_29 = F_55 ( V_48 , V_87 ) ;
break;
case V_97 :
V_29 = F_56 ( V_9 , V_87 ) ;
break;
case V_98 :
V_29 = F_58 ( V_9 , * ( int * ) V_87 ) ;
break;
default:
F_5 ( L_29 ) ;
V_29 = - V_40 ;
break;
}
return V_29 ;
}
static int F_61 ( struct V_2 * V_48 ,
enum V_94 V_95 , void * V_87 )
{
struct V_1 * V_9 = F_1 ( V_48 ) ;
int V_29 = 0 ;
switch ( V_95 ) {
case V_97 :
memcpy ( V_87 , & V_9 -> V_90 ,
sizeof( struct V_88 ) ) ;
break;
case V_98 :
* ( int * ) V_87 = V_9 -> V_63 ;
break;
case V_99 :
* ( int * ) V_87 = V_99 ;
break;
default:
F_5 ( L_29 ) ;
V_29 = - V_40 ;
break;
}
return V_29 ;
}
static struct V_100 * F_62 ( struct V_41 * V_42 )
{
struct V_100 * V_101 ;
V_101 = F_63 ( V_42 ) ;
if ( ! V_101 )
V_101 = F_64 () ;
return V_101 ;
}
static bool F_65 ( struct V_82 * V_83 )
{
T_4 V_102 ;
V_102 = F_66 ( V_83 -> V_103 + ( V_104 >> 2 ) ) ;
V_102 &= V_105 ;
return V_102 >= 0x204 ;
}
static struct V_100 * F_67 ( struct V_80 * V_81 )
{
struct V_80 * V_56 ;
struct V_100 * V_101 ;
struct V_106 * V_84 = V_81 -> V_84 ;
while ( V_84 ) {
F_42 (tmp, &bus->devices, bus_list) {
if ( V_56 == V_81 )
continue;
V_101 = F_63 ( & V_56 -> V_42 ) ;
if ( V_101 )
return V_101 ;
}
V_84 = V_84 -> V_85 ;
}
return NULL ;
}
static struct V_100 * F_68 ( struct V_80 * V_81 )
{
struct V_82 * V_83 ;
bool V_107 ;
struct V_100 * V_101 = NULL ;
V_83 = F_52 ( V_81 -> V_84 ) ;
V_107 = F_65 ( V_83 ) ;
if ( V_107 ) {
V_101 = F_69 ( & V_81 -> V_42 ) ;
if ( V_83 -> V_85 -> V_100 )
F_70 ( V_83 -> V_85 ) ;
} else {
if ( V_83 -> V_85 -> V_100 ) {
V_101 = F_62 ( V_83 -> V_85 ) ;
F_70 ( V_83 -> V_85 ) ;
} else {
V_101 = F_67 ( V_81 ) ;
}
}
if ( ! V_101 )
V_101 = F_71 ( - V_73 ) ;
return V_101 ;
}
static struct V_100 * F_72 ( struct V_41 * V_42 )
{
struct V_100 * V_101 = F_71 ( - V_73 ) ;
int V_79 ;
if ( F_50 ( V_42 ) )
V_101 = F_68 ( F_51 ( V_42 ) ) ;
else if ( F_53 ( V_42 -> V_77 , L_22 , & V_79 ) )
V_101 = F_62 ( V_42 ) ;
return V_101 ;
}
static int F_73 ( struct V_41 * V_42 )
{
struct V_100 * V_101 ;
V_101 = F_74 ( V_42 ) ;
if ( F_75 ( V_101 ) )
return F_76 ( V_101 ) ;
F_77 ( V_101 ) ;
F_78 ( & V_108 , V_42 ) ;
return 0 ;
}
static void F_79 ( struct V_41 * V_42 )
{
F_80 ( & V_108 , V_42 ) ;
F_70 ( V_42 ) ;
}
static int F_81 ( struct V_2 * V_48 , T_4 V_109 )
{
struct V_1 * V_9 = F_1 ( V_48 ) ;
unsigned long V_31 ;
int V_29 ;
F_10 ( & V_9 -> V_51 , V_31 ) ;
if ( V_9 -> V_63 ) {
F_5 ( L_25 ) ;
F_12 ( & V_9 -> V_51 , V_31 ) ;
return - V_74 ;
}
if ( ! V_9 -> V_18 ) {
F_5 ( L_30 ) ;
F_12 ( & V_9 -> V_51 , V_31 ) ;
return - V_40 ;
}
if ( V_109 > F_26 () || ! F_82 ( V_109 ) ) {
F_5 ( L_31 ) ;
F_12 ( & V_9 -> V_51 , V_31 ) ;
return - V_40 ;
}
V_29 = F_41 ( V_9 , & V_48 -> V_17 ,
V_109 > 1 ? V_109 : 0 ) ;
if ( ! V_29 ) {
F_83 ( V_9 -> V_14 ) ;
V_9 -> V_14 = F_84 ( V_109 ,
sizeof( * V_9 -> V_14 ) ,
V_58 ) ;
if ( ! V_9 -> V_14 ) {
F_12 ( & V_9 -> V_51 , V_31 ) ;
return - V_6 ;
}
V_9 -> V_11 = V_109 ;
}
F_12 ( & V_9 -> V_51 , V_31 ) ;
return V_29 ;
}
static T_4 F_85 ( struct V_2 * V_48 )
{
struct V_1 * V_9 = F_1 ( V_48 ) ;
return V_9 -> V_11 ;
}
int T_1 F_86 ( void )
{
int V_29 = 0 ;
V_29 = F_3 () ;
if ( V_29 )
return V_29 ;
V_29 = F_87 ( & V_108 , NULL , NULL , L_32 ) ;
if ( V_29 )
return V_29 ;
F_88 ( & V_108 , & V_110 ) ;
V_29 = F_89 ( & V_108 ) ;
if ( V_29 ) {
F_90 ( & V_108 ) ;
F_91 ( L_33 ) ;
return V_29 ;
}
F_92 ( & V_111 , & V_110 ) ;
F_92 ( & V_112 , & V_110 ) ;
return V_29 ;
}
