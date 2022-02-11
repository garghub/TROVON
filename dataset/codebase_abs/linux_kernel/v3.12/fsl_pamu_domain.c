static int T_1 F_1 ( void )
{
V_1 = F_2 ( L_1 ,
sizeof( struct V_2 ) ,
0 ,
V_3 ,
NULL ) ;
if ( ! V_1 ) {
F_3 ( L_2 ) ;
return - V_4 ;
}
V_5 = F_2 ( L_3 ,
sizeof( struct V_6 ) ,
0 ,
V_3 ,
NULL ) ;
if ( ! V_5 ) {
F_3 ( L_4 ) ;
F_4 ( V_1 ) ;
return - V_4 ;
}
return 0 ;
}
static T_2 F_5 ( struct V_2 * V_7 , T_3 V_8 )
{
T_4 V_9 = V_7 -> V_9 ;
struct V_10 * V_11 =
& V_7 -> V_12 [ 0 ] ;
struct V_13 * V_14 ;
V_14 = & V_7 -> V_15 -> V_16 ;
if ( ! V_9 || ! V_7 -> V_17 ) {
F_3 ( L_5 ) ;
return 0 ;
}
if ( V_9 > 1 ) {
T_5 V_18 ;
T_3 V_19 ;
T_4 V_20 ;
V_18 = V_7 -> V_17 >> F_6 ( V_9 ) ;
V_19 = V_8 & ~ ( V_18 - 1 ) ;
V_20 = ( V_19 - V_14 -> V_21 ) >> F_6 ( V_18 ) ;
V_11 = & V_7 -> V_12 [ V_20 ] ;
}
if ( V_11 -> V_22 )
return ( V_11 -> V_23 + ( V_8 & ( V_11 -> V_24 - 1 ) ) ) ;
return 0 ;
}
static int F_7 ( int V_25 , struct V_2 * V_7 )
{
struct V_10 * V_26 =
& V_7 -> V_12 [ 0 ] ;
int V_27 , V_28 ;
unsigned long V_29 , V_30 ;
for ( V_27 = 0 ; V_27 < V_7 -> V_9 ; V_27 ++ ) {
if ( V_26 [ V_27 ] . V_22 ) {
V_29 = V_26 [ V_27 ] . V_23 >>
V_31 ;
F_8 ( & V_32 , V_30 ) ;
V_28 = F_9 ( V_25 , V_7 -> V_9 , V_27 ,
V_26 [ V_27 ] . V_24 ,
~ ( T_4 ) 0 ,
V_29 ,
V_7 -> V_33 ,
V_7 -> V_34 ,
( V_27 > 0 ) ? 1 : 0 ,
V_26 [ V_27 ] . V_35 ) ;
F_10 ( & V_32 , V_30 ) ;
if ( V_28 ) {
F_3 ( L_6 ,
V_25 ) ;
return V_28 ;
}
}
}
return V_28 ;
}
static int F_11 ( int V_25 , struct V_2 * V_7 )
{
int V_28 ;
struct V_10 * V_20 = & V_7 -> V_12 [ 0 ] ;
T_2 V_36 = V_7 -> V_15 -> V_16 . V_21 ;
unsigned long V_30 ;
F_8 ( & V_32 , V_30 ) ;
V_28 = F_12 ( V_25 , V_36 ,
V_20 -> V_24 ,
~ ( T_4 ) 0 ,
V_20 -> V_23 >> V_31 ,
V_7 -> V_33 , V_7 -> V_34 ,
0 , V_20 -> V_35 ) ;
F_10 ( & V_32 , V_30 ) ;
if ( V_28 )
F_3 ( L_7 ,
V_25 ) ;
return V_28 ;
}
static int F_13 ( int V_25 , struct V_2 * V_7 )
{
if ( V_7 -> V_9 > 1 )
return F_7 ( V_25 , V_7 ) ;
else
return F_11 ( V_25 , V_7 ) ;
}
static int F_14 ( int V_25 , struct V_2 * V_7 , T_4 V_37 )
{
int V_28 ;
struct V_10 * V_20 = & V_7 -> V_12 [ V_37 ] ;
unsigned long V_30 ;
F_8 ( & V_32 , V_30 ) ;
if ( V_7 -> V_9 > 1 ) {
V_28 = F_9 ( V_25 , V_7 -> V_9 , V_37 ,
V_20 -> V_24 ,
~ ( T_4 ) 0 ,
V_20 -> V_23 >> V_31 ,
V_7 -> V_33 ,
V_7 -> V_34 ,
( V_37 > 0 ) ? 1 : 0 ,
V_20 -> V_35 ) ;
if ( V_28 )
F_3 ( L_8 , V_25 ) ;
} else {
T_2 V_36 ;
V_36 = V_7 -> V_15 -> V_16 . V_21 ;
V_28 = F_12 ( V_25 , V_36 ,
V_20 -> V_24 ,
~ ( T_4 ) 0 ,
V_20 -> V_23 >> V_31 ,
V_7 -> V_33 , V_7 -> V_34 ,
0 , V_20 -> V_35 ) ;
if ( V_28 )
F_3 ( L_9 , V_25 ) ;
}
F_10 ( & V_32 , V_30 ) ;
return V_28 ;
}
static int F_15 ( int V_25 , struct V_2 * V_7 ,
T_4 V_38 )
{
int V_28 = 0 , V_27 ;
unsigned long V_30 ;
F_8 ( & V_32 , V_30 ) ;
if ( ! V_7 -> V_12 ) {
F_3 ( L_10 , V_25 ) ;
F_10 ( & V_32 , V_30 ) ;
return - V_39 ;
}
for ( V_27 = 0 ; V_27 < V_7 -> V_9 ; V_27 ++ ) {
V_28 = F_16 ( V_25 , V_27 , V_38 ) ;
if ( V_28 ) {
F_3 ( L_11 , V_27 , V_25 ) ;
F_10 ( & V_32 , V_30 ) ;
return V_28 ;
}
}
F_10 ( & V_32 , V_30 ) ;
return V_28 ;
}
static int F_17 ( int V_25 , struct V_40 * V_41 ,
struct V_2 * V_7 ,
struct V_13 * V_42 ,
T_4 V_9 )
{
T_2 V_43 , V_44 ;
T_2 V_18 ;
int V_28 = 0 , V_27 ;
T_4 V_45 = ~ ( T_4 ) 0 ;
unsigned long V_30 ;
F_18 ( & V_45 , V_41 ) ;
V_43 = V_42 -> V_21 ;
V_44 = V_7 -> V_17 ;
F_8 ( & V_32 , V_30 ) ;
V_28 = F_19 ( V_25 ) ;
if ( ! V_28 )
V_28 = F_12 ( V_25 , V_43 , V_44 , V_45 ,
0 , V_7 -> V_33 ,
V_7 -> V_34 , V_9 , 0 ) ;
F_10 ( & V_32 , V_30 ) ;
if ( V_28 ) {
F_3 ( L_12 , V_25 , V_9 ) ;
return V_28 ;
}
if ( V_9 > 1 ) {
V_18 = V_44 >> F_6 ( V_9 ) ;
for ( V_27 = 0 ; V_27 < V_9 ; V_27 ++ ) {
F_8 ( & V_32 , V_30 ) ;
V_28 = F_20 ( V_25 , V_27 ) ;
if ( ! V_28 )
V_28 = F_9 ( V_25 , V_9 , V_27 ,
V_18 , V_45 ,
0 , V_7 -> V_33 ,
V_7 -> V_34 ,
0 , 0 ) ;
F_10 ( & V_32 , V_30 ) ;
if ( V_28 ) {
F_3 ( L_6 , V_25 ) ;
return V_28 ;
}
}
}
return V_28 ;
}
static int F_21 ( T_5 V_24 , T_3 V_8 )
{
if ( ! F_22 ( V_24 ) || V_24 < V_46 ) {
F_3 ( L_13 , V_47 ) ;
return - V_39 ;
}
if ( V_8 & ( V_24 - 1 ) ) {
F_3 ( L_14 , V_47 ) ;
return - V_39 ;
}
return 0 ;
}
static struct V_2 * F_23 ( void )
{
struct V_2 * V_48 ;
V_48 = F_24 ( V_1 , V_49 ) ;
if ( ! V_48 )
return NULL ;
V_48 -> V_34 = ~ ( T_4 ) 0 ;
V_48 -> V_33 = ~ ( T_4 ) 0 ;
V_48 -> V_9 = F_25 () ;
V_48 -> V_17 = 0 ;
F_26 ( & V_48 -> V_50 ) ;
F_27 ( & V_48 -> V_51 ) ;
return V_48 ;
}
static inline struct V_6 * F_28 ( struct V_40 * V_41 )
{
return V_41 -> V_52 . V_15 ;
}
static void F_29 ( struct V_6 * V_53 , T_4 V_9 )
{
unsigned long V_30 ;
F_30 ( & V_53 -> V_54 ) ;
F_8 ( & V_32 , V_30 ) ;
if ( V_9 > 1 )
F_31 ( V_53 -> V_25 ) ;
F_19 ( V_53 -> V_25 ) ;
F_10 ( & V_32 , V_30 ) ;
F_8 ( & V_55 , V_30 ) ;
V_53 -> V_41 -> V_52 . V_15 = NULL ;
F_32 ( V_5 , V_53 ) ;
F_10 ( & V_55 , V_30 ) ;
}
static void F_33 ( struct V_40 * V_41 , struct V_2 * V_7 )
{
struct V_6 * V_53 , * V_56 ;
unsigned long V_30 ;
F_8 ( & V_7 -> V_51 , V_30 ) ;
F_34 (info, tmp, &dma_domain->devices, link) {
if ( ! V_41 || ( V_53 -> V_41 == V_41 ) )
F_29 ( V_53 , V_7 -> V_9 ) ;
}
F_10 ( & V_7 -> V_51 , V_30 ) ;
}
static void F_35 ( struct V_2 * V_7 , int V_25 , struct V_40 * V_41 )
{
struct V_6 * V_53 , * V_57 ;
unsigned long V_30 ;
F_8 ( & V_55 , V_30 ) ;
V_57 = F_28 ( V_41 ) ;
if ( V_57 && V_57 -> V_48 != V_7 ) {
F_10 ( & V_55 , V_30 ) ;
F_33 ( V_41 , V_57 -> V_48 ) ;
F_8 ( & V_55 , V_30 ) ;
}
V_53 = F_24 ( V_5 , V_58 ) ;
V_53 -> V_41 = V_41 ;
V_53 -> V_25 = V_25 ;
V_53 -> V_48 = V_7 ;
F_36 ( & V_53 -> V_54 , & V_7 -> V_50 ) ;
if ( ! V_57 )
V_41 -> V_52 . V_15 = V_53 ;
F_10 ( & V_55 , V_30 ) ;
}
static T_2 F_37 ( struct V_15 * V_48 ,
T_3 V_8 )
{
struct V_2 * V_7 = V_48 -> V_59 ;
if ( ( V_8 < V_48 -> V_16 . V_21 ) ||
V_8 > ( V_48 -> V_16 . V_60 ) )
return 0 ;
return F_5 ( V_7 , V_8 ) ;
}
static int F_38 ( struct V_15 * V_48 ,
unsigned long V_61 )
{
return V_61 == V_62 ;
}
static void F_39 ( struct V_15 * V_48 )
{
struct V_2 * V_7 = V_48 -> V_59 ;
V_48 -> V_59 = NULL ;
F_33 ( NULL , V_7 ) ;
V_7 -> V_63 = 0 ;
V_7 -> V_64 = 0 ;
F_32 ( V_1 , V_7 ) ;
}
static int F_40 ( struct V_15 * V_48 )
{
struct V_2 * V_7 ;
V_7 = F_23 () ;
if ( ! V_7 ) {
F_3 ( L_15 ) ;
return - V_4 ;
}
V_48 -> V_59 = V_7 ;
V_7 -> V_15 = V_48 ;
V_48 -> V_16 . V_21 = 0 ;
V_48 -> V_16 . V_60 = ( 1ULL << 36 ) - 1 ;
V_48 -> V_16 . V_65 = true ;
return 0 ;
}
static int F_41 ( struct V_2 * V_7 ,
struct V_13 * V_42 ,
T_4 V_9 )
{
struct V_6 * V_53 ;
int V_28 = 0 ;
F_42 (info, &dma_domain->devices, link) {
V_28 = F_17 ( V_53 -> V_25 , V_53 -> V_41 , V_7 ,
V_42 , V_9 ) ;
if ( V_28 )
break;
}
return V_28 ;
}
static int F_43 ( struct V_2 * V_7 , T_4 V_38 )
{
struct V_6 * V_53 ;
int V_28 = 0 ;
F_42 (info, &dma_domain->devices, link) {
V_28 = F_15 ( V_53 -> V_25 , V_7 , V_38 ) ;
if ( V_28 )
break;
}
return V_28 ;
}
static int F_44 ( struct V_2 * V_7 , T_4 V_37 )
{
struct V_6 * V_53 ;
int V_28 = 0 ;
F_42 (info, &dma_domain->devices, link) {
V_28 = F_14 ( V_53 -> V_25 , V_7 , V_37 ) ;
if ( V_28 )
break;
}
return V_28 ;
}
static int F_45 ( struct V_2 * V_7 , T_4 V_37 )
{
struct V_6 * V_53 ;
int V_28 = 0 ;
F_42 (info, &dma_domain->devices, link) {
if ( V_7 -> V_9 == 1 && V_7 -> V_63 ) {
V_28 = F_19 ( V_53 -> V_25 ) ;
if ( ! V_28 )
V_7 -> V_63 = 0 ;
} else {
V_28 = F_20 ( V_53 -> V_25 , V_37 ) ;
}
}
return V_28 ;
}
static void F_46 ( struct V_15 * V_48 , T_4 V_37 )
{
struct V_2 * V_7 = V_48 -> V_59 ;
unsigned long V_30 ;
int V_28 ;
F_8 ( & V_7 -> V_51 , V_30 ) ;
if ( ! V_7 -> V_12 ) {
F_3 ( L_16 ) ;
F_10 ( & V_7 -> V_51 , V_30 ) ;
return;
}
if ( V_37 >= V_7 -> V_9 ) {
F_3 ( L_17 ) ;
F_10 ( & V_7 -> V_51 , V_30 ) ;
return;
}
if ( V_7 -> V_12 [ V_37 ] . V_22 ) {
V_28 = F_45 ( V_7 , V_37 ) ;
if ( ! V_28 ) {
V_7 -> V_12 [ V_37 ] . V_22 = 0 ;
V_7 -> V_64 -- ;
}
}
F_10 ( & V_7 -> V_51 , V_30 ) ;
}
static int F_47 ( struct V_15 * V_48 , T_4 V_37 ,
T_2 V_23 , T_5 V_24 , int V_35 )
{
struct V_2 * V_7 = V_48 -> V_59 ;
struct V_10 * V_20 ;
int V_66 = 0 ;
int V_28 ;
unsigned long V_30 ;
T_5 V_67 ;
if ( V_35 & V_68 )
V_66 |= V_69 ;
if ( V_35 & V_70 )
V_66 |= V_71 ;
F_8 ( & V_7 -> V_51 , V_30 ) ;
if ( ! V_7 -> V_12 ) {
F_3 ( L_16 ) ;
F_10 ( & V_7 -> V_51 , V_30 ) ;
return - V_72 ;
}
if ( V_37 >= V_7 -> V_9 ) {
F_3 ( L_17 ) ;
F_10 ( & V_7 -> V_51 , V_30 ) ;
return - V_39 ;
}
V_67 = V_7 -> V_17 >> F_6 ( V_7 -> V_9 ) ;
if ( V_24 > V_67 ) {
F_3 ( L_18 ) ;
F_10 ( & V_7 -> V_51 , V_30 ) ;
return - V_39 ;
}
if ( V_7 -> V_9 == 1 ) {
if ( V_7 -> V_63 ) {
F_3 ( L_19 ) ;
F_10 ( & V_7 -> V_51 , V_30 ) ;
return - V_73 ;
}
V_28 = F_21 ( V_24 , V_48 -> V_16 . V_21 ) ;
if ( V_28 ) {
F_3 ( L_20 ) ;
F_10 ( & V_7 -> V_51 , V_30 ) ;
return - V_39 ;
}
}
V_20 = & V_7 -> V_12 [ V_37 ] ;
if ( ! V_20 -> V_22 ) {
V_20 -> V_23 = V_23 ;
V_20 -> V_24 = V_24 ;
V_20 -> V_35 = V_66 ;
V_28 = F_44 ( V_7 , V_37 ) ;
if ( ! V_28 ) {
V_20 -> V_22 = 1 ;
V_7 -> V_64 ++ ;
}
} else {
F_3 ( L_19 ) ;
V_28 = - V_73 ;
}
F_10 ( & V_7 -> V_51 , V_30 ) ;
return V_28 ;
}
static int F_48 ( struct V_2 * V_7 ,
struct V_40 * V_41 , const T_4 * V_25 ,
int V_74 )
{
unsigned long V_30 ;
struct V_15 * V_48 = V_7 -> V_15 ;
int V_28 = 0 ;
int V_27 ;
F_8 ( & V_7 -> V_51 , V_30 ) ;
for ( V_27 = 0 ; V_27 < V_74 ; V_27 ++ ) {
if ( V_25 [ V_27 ] >= V_75 ) {
F_3 ( L_21 ,
V_25 [ V_27 ] , V_41 -> V_76 -> V_77 ) ;
V_28 = - V_39 ;
break;
}
F_35 ( V_7 , V_25 [ V_27 ] , V_41 ) ;
if ( V_7 -> V_12 ) {
T_4 V_9 = V_7 -> V_9 > 1 ? V_7 -> V_9 : 0 ;
V_28 = F_17 ( V_25 [ V_27 ] , V_41 , V_7 ,
& V_48 -> V_16 ,
V_9 ) ;
if ( V_28 )
break;
if ( V_7 -> V_64 ) {
V_28 = F_13 ( V_25 [ V_27 ] , V_7 ) ;
if ( V_28 )
break;
}
}
}
F_10 ( & V_7 -> V_51 , V_30 ) ;
return V_28 ;
}
static int F_49 ( struct V_15 * V_48 ,
struct V_40 * V_41 )
{
struct V_2 * V_7 = V_48 -> V_59 ;
const T_4 * V_25 ;
T_4 V_78 ;
int V_79 , V_28 = 0 ;
struct V_80 * V_81 = NULL ;
struct V_82 * V_83 ;
if ( V_41 -> V_84 == & V_85 ) {
V_81 = F_50 ( V_41 ) ;
V_83 = F_51 ( V_81 -> V_84 ) ;
V_41 = V_83 -> V_86 ;
}
V_25 = F_52 ( V_41 -> V_76 , L_22 , & V_79 ) ;
if ( V_25 ) {
V_78 = V_79 / sizeof( T_4 ) ;
V_28 = F_48 ( V_7 , V_41 ,
V_25 , V_78 ) ;
} else {
F_3 ( L_23 ,
V_41 -> V_76 -> V_77 ) ;
V_28 = - V_39 ;
}
return V_28 ;
}
static void F_53 ( struct V_15 * V_48 ,
struct V_40 * V_41 )
{
struct V_2 * V_7 = V_48 -> V_59 ;
const T_4 * V_87 ;
int V_79 ;
struct V_80 * V_81 = NULL ;
struct V_82 * V_83 ;
if ( V_41 -> V_84 == & V_85 ) {
V_81 = F_50 ( V_41 ) ;
V_83 = F_51 ( V_81 -> V_84 ) ;
V_41 = V_83 -> V_86 ;
}
V_87 = F_52 ( V_41 -> V_76 , L_22 , & V_79 ) ;
if ( V_87 )
F_33 ( V_41 , V_7 ) ;
else
F_3 ( L_23 ,
V_41 -> V_76 -> V_77 ) ;
}
static int F_54 ( struct V_15 * V_48 , void * V_88 )
{
struct V_13 * V_42 = V_88 ;
struct V_2 * V_7 = V_48 -> V_59 ;
T_3 V_17 ;
unsigned long V_30 ;
V_17 = V_42 -> V_60 - V_42 -> V_21 + 1 ;
if ( F_21 ( V_17 , V_42 -> V_21 ) ||
! V_42 -> V_65 ) {
F_3 ( L_24 ) ;
return - V_39 ;
}
F_8 ( & V_7 -> V_51 , V_30 ) ;
if ( V_7 -> V_63 ) {
F_3 ( L_25 ) ;
F_10 ( & V_7 -> V_51 , V_30 ) ;
return - V_73 ;
}
memcpy ( & V_48 -> V_16 , V_42 ,
sizeof( struct V_13 ) ) ;
V_7 -> V_17 = V_17 ;
F_10 ( & V_7 -> V_51 , V_30 ) ;
return 0 ;
}
static int F_55 ( struct V_2 * V_7 , void * V_88 )
{
struct V_89 * V_90 = V_88 ;
unsigned long V_30 ;
int V_28 ;
F_8 ( & V_7 -> V_51 , V_30 ) ;
memcpy ( & V_7 -> V_91 , V_90 ,
sizeof( struct V_89 ) ) ;
V_7 -> V_34 = F_56 ( V_90 -> V_92 ,
V_90 -> V_93 ) ;
if ( V_7 -> V_34 == ~ ( T_4 ) 0 ) {
F_3 ( L_26 ) ;
F_10 ( & V_7 -> V_51 , V_30 ) ;
return - V_39 ;
}
V_28 = F_43 ( V_7 , V_7 -> V_34 ) ;
F_10 ( & V_7 -> V_51 , V_30 ) ;
return V_28 ;
}
static int F_57 ( struct V_2 * V_7 , bool V_94 )
{
struct V_6 * V_53 ;
unsigned long V_30 ;
int V_28 ;
F_8 ( & V_7 -> V_51 , V_30 ) ;
if ( V_94 && ! V_7 -> V_64 ) {
F_3 ( L_27 ) ;
F_10 ( & V_7 -> V_51 , V_30 ) ;
return - V_72 ;
}
V_7 -> V_63 = V_94 ;
F_42 (info, &dma_domain->devices,
link) {
V_28 = ( V_94 ) ? F_58 ( V_53 -> V_25 ) :
F_19 ( V_53 -> V_25 ) ;
if ( V_28 )
F_3 ( L_28 ,
V_53 -> V_25 ) ;
}
F_10 ( & V_7 -> V_51 , V_30 ) ;
return 0 ;
}
static int F_59 ( struct V_15 * V_48 ,
enum V_95 V_96 , void * V_88 )
{
struct V_2 * V_7 = V_48 -> V_59 ;
int V_28 = 0 ;
switch ( V_96 ) {
case V_97 :
V_28 = F_54 ( V_48 , V_88 ) ;
break;
case V_98 :
V_28 = F_55 ( V_7 , V_88 ) ;
break;
case V_99 :
V_28 = F_57 ( V_7 , * ( int * ) V_88 ) ;
break;
default:
F_3 ( L_29 ) ;
V_28 = - V_39 ;
break;
} ;
return V_28 ;
}
static int F_60 ( struct V_15 * V_48 ,
enum V_95 V_96 , void * V_88 )
{
struct V_2 * V_7 = V_48 -> V_59 ;
int V_28 = 0 ;
switch ( V_96 ) {
case V_98 :
memcpy ( (struct V_89 * ) V_88 , & V_7 -> V_91 ,
sizeof( struct V_89 ) ) ;
break;
case V_99 :
* ( int * ) V_88 = V_7 -> V_63 ;
break;
case V_100 :
* ( int * ) V_88 = V_100 ;
break;
default:
F_3 ( L_29 ) ;
V_28 = - V_39 ;
break;
} ;
return V_28 ;
}
static struct V_101 * F_61 ( struct V_40 * V_41 )
{
struct V_101 * V_102 ;
V_102 = F_62 ( V_41 ) ;
if ( ! V_102 )
V_102 = F_63 () ;
return V_102 ;
}
static bool F_64 ( struct V_82 * V_83 )
{
T_4 V_103 ;
V_103 = F_65 ( V_83 -> V_104 + ( V_105 >> 2 ) ) ;
V_103 &= V_106 ;
if ( V_103 >= 0x204 )
return 1 ;
return 0 ;
}
static struct V_101 * F_66 ( struct V_80 * V_81 )
{
struct V_80 * V_56 ;
struct V_101 * V_102 ;
struct V_107 * V_84 = V_81 -> V_84 ;
while ( V_84 ) {
F_42 (tmp, &bus->devices, bus_list) {
if ( V_56 == V_81 )
continue;
V_102 = F_62 ( & V_56 -> V_41 ) ;
if ( V_102 )
return V_102 ;
}
V_84 = V_84 -> V_86 ;
}
return NULL ;
}
static struct V_101 * F_67 ( struct V_80 * V_81 )
{
struct V_82 * V_83 ;
bool V_108 ;
struct V_101 * V_102 = NULL ;
struct V_80 * V_109 , * V_110 = NULL ;
V_83 = F_51 ( V_81 -> V_84 ) ;
V_108 = F_64 ( V_83 ) ;
if ( V_108 ) {
V_109 = F_68 ( V_81 ) ;
if ( V_109 ) {
if ( F_69 ( V_109 ) )
V_110 = F_70 (
F_71 ( V_81 -> V_84 ) ,
V_109 -> V_111 -> V_112 , 0 ) ;
if ( ! V_110 )
V_110 = F_72 ( V_109 ) ;
} else
V_110 = F_72 ( V_81 ) ;
F_73 ( & V_110 , F_74 ( V_110 ) ) ;
if ( V_110 -> V_113 &&
! F_75 ( V_110 , V_114 ) ) {
T_6 V_27 , V_115 = F_76 ( V_110 -> V_116 ) ;
for ( V_27 = 0 ; V_27 < 8 ; V_27 ++ ) {
struct V_80 * V_56 ;
V_56 = F_77 ( V_110 -> V_84 , F_78 ( V_115 , V_27 ) ) ;
if ( ! V_56 )
continue;
if ( ! F_75 ( V_56 , V_114 ) ) {
F_73 ( & V_110 , V_56 ) ;
break;
}
F_79 ( V_56 ) ;
}
}
while ( ! F_80 ( V_110 -> V_84 ) ) {
struct V_107 * V_84 = V_110 -> V_84 ;
while ( ! V_84 -> V_117 ) {
if ( ! F_80 ( V_84 ) )
V_84 = V_84 -> V_86 ;
else
goto V_118;
}
if ( F_81 ( V_84 -> V_117 , NULL , V_114 ) )
break;
F_73 ( & V_110 , F_72 ( V_84 -> V_117 ) ) ;
}
V_118:
V_102 = F_61 ( & V_110 -> V_41 ) ;
F_79 ( V_110 ) ;
if ( V_83 -> V_86 -> V_101 )
F_82 ( V_83 -> V_86 ) ;
} else {
if ( V_83 -> V_86 -> V_101 ) {
V_102 = F_61 ( V_83 -> V_86 ) ;
F_82 ( V_83 -> V_86 ) ;
} else
V_102 = F_66 ( V_81 ) ;
}
return V_102 ;
}
static int F_83 ( struct V_40 * V_41 )
{
struct V_101 * V_102 = NULL ;
struct V_80 * V_81 ;
const T_4 * V_87 ;
int V_28 , V_79 ;
if ( V_41 -> V_84 == & V_85 ) {
V_81 = F_50 ( V_41 ) ;
if ( V_81 -> V_111 )
return 0 ;
V_102 = F_67 ( V_81 ) ;
} else {
V_87 = F_52 ( V_41 -> V_76 , L_22 , & V_79 ) ;
if ( V_87 )
V_102 = F_61 ( V_41 ) ;
}
if ( ! V_102 || F_84 ( V_102 ) )
return F_85 ( V_102 ) ;
V_28 = F_86 ( V_102 , V_41 ) ;
F_87 ( V_102 ) ;
return V_28 ;
}
static void F_88 ( struct V_40 * V_41 )
{
F_82 ( V_41 ) ;
}
static int F_89 ( struct V_15 * V_48 , T_4 V_119 )
{
struct V_2 * V_7 = V_48 -> V_59 ;
unsigned long V_30 ;
int V_28 ;
F_8 ( & V_7 -> V_51 , V_30 ) ;
if ( V_7 -> V_63 ) {
F_3 ( L_25 ) ;
F_10 ( & V_7 -> V_51 , V_30 ) ;
return - V_73 ;
}
if ( ! V_7 -> V_17 ) {
F_3 ( L_30 ) ;
F_10 ( & V_7 -> V_51 , V_30 ) ;
return - V_39 ;
}
if ( V_119 > F_25 () || ! F_22 ( V_119 ) ) {
F_3 ( L_31 ) ;
F_10 ( & V_7 -> V_51 , V_30 ) ;
return - V_39 ;
}
V_28 = F_41 ( V_7 , & V_48 -> V_16 ,
( ( V_119 > 1 ) ? V_119 : 0 ) ) ;
if ( ! V_28 ) {
if ( V_7 -> V_12 )
F_90 ( V_7 -> V_12 ) ;
V_7 -> V_12 = F_91 ( sizeof( struct V_10 ) *
V_119 , V_58 ) ;
if ( ! V_7 -> V_12 ) {
F_10 ( & V_7 -> V_51 , V_30 ) ;
return - V_4 ;
}
V_7 -> V_9 = V_119 ;
}
F_10 ( & V_7 -> V_51 , V_30 ) ;
return V_28 ;
}
static T_4 F_92 ( struct V_15 * V_48 )
{
struct V_2 * V_7 = V_48 -> V_59 ;
return V_7 -> V_9 ;
}
int F_93 ()
{
int V_28 = 0 ;
V_28 = F_1 () ;
if ( V_28 )
return V_28 ;
F_94 ( & V_120 , & V_121 ) ;
F_94 ( & V_85 , & V_121 ) ;
return V_28 ;
}
