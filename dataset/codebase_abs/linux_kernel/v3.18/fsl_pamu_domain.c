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
if ( ( V_24 & ( V_24 - 1 ) ) || V_24 < V_46 ) {
F_3 ( L_13 , V_47 ) ;
return - V_39 ;
}
if ( V_8 & ( V_24 - 1 ) ) {
F_3 ( L_14 , V_47 ) ;
return - V_39 ;
}
return 0 ;
}
static struct V_2 * F_22 ( void )
{
struct V_2 * V_48 ;
V_48 = F_23 ( V_1 , V_49 ) ;
if ( ! V_48 )
return NULL ;
V_48 -> V_34 = ~ ( T_4 ) 0 ;
V_48 -> V_33 = ~ ( T_4 ) 0 ;
V_48 -> V_9 = F_24 () ;
V_48 -> V_17 = 0 ;
F_25 ( & V_48 -> V_50 ) ;
F_26 ( & V_48 -> V_51 ) ;
return V_48 ;
}
static void F_27 ( struct V_6 * V_52 , T_4 V_9 )
{
unsigned long V_30 ;
F_28 ( & V_52 -> V_53 ) ;
F_8 ( & V_32 , V_30 ) ;
if ( V_9 > 1 )
F_29 ( V_52 -> V_25 ) ;
F_19 ( V_52 -> V_25 ) ;
F_10 ( & V_32 , V_30 ) ;
F_8 ( & V_54 , V_30 ) ;
V_52 -> V_41 -> V_55 . V_15 = NULL ;
F_30 ( V_5 , V_52 ) ;
F_10 ( & V_54 , V_30 ) ;
}
static void F_31 ( struct V_40 * V_41 , struct V_2 * V_7 )
{
struct V_6 * V_52 , * V_56 ;
unsigned long V_30 ;
F_8 ( & V_7 -> V_51 , V_30 ) ;
F_32 (info, tmp, &dma_domain->devices, link) {
if ( ! V_41 || ( V_52 -> V_41 == V_41 ) )
F_27 ( V_52 , V_7 -> V_9 ) ;
}
F_10 ( & V_7 -> V_51 , V_30 ) ;
}
static void F_33 ( struct V_2 * V_7 , int V_25 , struct V_40 * V_41 )
{
struct V_6 * V_52 , * V_57 ;
unsigned long V_30 ;
F_8 ( & V_54 , V_30 ) ;
V_57 = V_41 -> V_55 . V_15 ;
if ( V_57 && V_57 -> V_48 != V_7 ) {
F_10 ( & V_54 , V_30 ) ;
F_31 ( V_41 , V_57 -> V_48 ) ;
F_8 ( & V_54 , V_30 ) ;
}
V_52 = F_23 ( V_5 , V_58 ) ;
V_52 -> V_41 = V_41 ;
V_52 -> V_25 = V_25 ;
V_52 -> V_48 = V_7 ;
F_34 ( & V_52 -> V_53 , & V_7 -> V_50 ) ;
if ( ! V_41 -> V_55 . V_15 )
V_41 -> V_55 . V_15 = V_52 ;
F_10 ( & V_54 , V_30 ) ;
}
static T_2 F_35 ( struct V_15 * V_48 ,
T_3 V_8 )
{
struct V_2 * V_7 = V_48 -> V_59 ;
if ( ( V_8 < V_48 -> V_16 . V_21 ) ||
V_8 > ( V_48 -> V_16 . V_60 ) )
return 0 ;
return F_5 ( V_7 , V_8 ) ;
}
static bool F_36 ( enum V_61 V_62 )
{
return V_62 == V_63 ;
}
static void F_37 ( struct V_15 * V_48 )
{
struct V_2 * V_7 = V_48 -> V_59 ;
V_48 -> V_59 = NULL ;
F_31 ( NULL , V_7 ) ;
V_7 -> V_64 = 0 ;
V_7 -> V_65 = 0 ;
F_30 ( V_1 , V_7 ) ;
}
static int F_38 ( struct V_15 * V_48 )
{
struct V_2 * V_7 ;
V_7 = F_22 () ;
if ( ! V_7 ) {
F_3 ( L_15 ) ;
return - V_4 ;
}
V_48 -> V_59 = V_7 ;
V_7 -> V_15 = V_48 ;
V_48 -> V_16 . V_21 = 0 ;
V_48 -> V_16 . V_60 = ( 1ULL << 36 ) - 1 ;
V_48 -> V_16 . V_66 = true ;
return 0 ;
}
static int F_39 ( struct V_2 * V_7 ,
struct V_13 * V_42 ,
T_4 V_9 )
{
struct V_6 * V_52 ;
int V_28 = 0 ;
F_40 (info, &dma_domain->devices, link) {
V_28 = F_17 ( V_52 -> V_25 , V_52 -> V_41 , V_7 ,
V_42 , V_9 ) ;
if ( V_28 )
break;
}
return V_28 ;
}
static int F_41 ( struct V_2 * V_7 , T_4 V_38 )
{
struct V_6 * V_52 ;
int V_28 = 0 ;
F_40 (info, &dma_domain->devices, link) {
V_28 = F_15 ( V_52 -> V_25 , V_7 , V_38 ) ;
if ( V_28 )
break;
}
return V_28 ;
}
static int F_42 ( struct V_2 * V_7 , T_4 V_37 )
{
struct V_6 * V_52 ;
int V_28 = 0 ;
F_40 (info, &dma_domain->devices, link) {
V_28 = F_14 ( V_52 -> V_25 , V_7 , V_37 ) ;
if ( V_28 )
break;
}
return V_28 ;
}
static int F_43 ( struct V_2 * V_7 , T_4 V_37 )
{
struct V_6 * V_52 ;
int V_28 = 0 ;
F_40 (info, &dma_domain->devices, link) {
if ( V_7 -> V_9 == 1 && V_7 -> V_64 ) {
V_28 = F_19 ( V_52 -> V_25 ) ;
if ( ! V_28 )
V_7 -> V_64 = 0 ;
} else {
V_28 = F_20 ( V_52 -> V_25 , V_37 ) ;
}
}
return V_28 ;
}
static void F_44 ( struct V_15 * V_48 , T_4 V_37 )
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
V_28 = F_43 ( V_7 , V_37 ) ;
if ( ! V_28 ) {
V_7 -> V_12 [ V_37 ] . V_22 = 0 ;
V_7 -> V_65 -- ;
}
}
F_10 ( & V_7 -> V_51 , V_30 ) ;
}
static int F_45 ( struct V_15 * V_48 , T_4 V_37 ,
T_2 V_23 , T_5 V_24 , int V_35 )
{
struct V_2 * V_7 = V_48 -> V_59 ;
struct V_10 * V_20 ;
int V_67 = 0 ;
int V_28 ;
unsigned long V_30 ;
T_5 V_68 ;
if ( V_35 & V_69 )
V_67 |= V_70 ;
if ( V_35 & V_71 )
V_67 |= V_72 ;
F_8 ( & V_7 -> V_51 , V_30 ) ;
if ( ! V_7 -> V_12 ) {
F_3 ( L_16 ) ;
F_10 ( & V_7 -> V_51 , V_30 ) ;
return - V_73 ;
}
if ( V_37 >= V_7 -> V_9 ) {
F_3 ( L_17 ) ;
F_10 ( & V_7 -> V_51 , V_30 ) ;
return - V_39 ;
}
V_68 = V_7 -> V_17 >> F_6 ( V_7 -> V_9 ) ;
if ( V_24 > V_68 ) {
F_3 ( L_18 ) ;
F_10 ( & V_7 -> V_51 , V_30 ) ;
return - V_39 ;
}
if ( V_7 -> V_9 == 1 ) {
if ( V_7 -> V_64 ) {
F_3 ( L_19 ) ;
F_10 ( & V_7 -> V_51 , V_30 ) ;
return - V_74 ;
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
V_20 -> V_35 = V_67 ;
V_28 = F_42 ( V_7 , V_37 ) ;
if ( ! V_28 ) {
V_20 -> V_22 = 1 ;
V_7 -> V_65 ++ ;
}
} else {
F_3 ( L_19 ) ;
V_28 = - V_74 ;
}
F_10 ( & V_7 -> V_51 , V_30 ) ;
return V_28 ;
}
static int F_46 ( struct V_2 * V_7 ,
struct V_40 * V_41 , const T_4 * V_25 ,
int V_75 )
{
unsigned long V_30 ;
struct V_15 * V_48 = V_7 -> V_15 ;
int V_28 = 0 ;
int V_27 ;
F_8 ( & V_7 -> V_51 , V_30 ) ;
for ( V_27 = 0 ; V_27 < V_75 ; V_27 ++ ) {
if ( V_25 [ V_27 ] >= V_76 ) {
F_3 ( L_21 ,
V_25 [ V_27 ] , V_41 -> V_77 -> V_78 ) ;
V_28 = - V_39 ;
break;
}
F_33 ( V_7 , V_25 [ V_27 ] , V_41 ) ;
if ( V_7 -> V_12 ) {
T_4 V_9 = V_7 -> V_9 > 1 ? V_7 -> V_9 : 0 ;
V_28 = F_17 ( V_25 [ V_27 ] , V_41 , V_7 ,
& V_48 -> V_16 ,
V_9 ) ;
if ( V_28 )
break;
if ( V_7 -> V_65 ) {
V_28 = F_13 ( V_25 [ V_27 ] , V_7 ) ;
if ( V_28 )
break;
}
}
}
F_10 ( & V_7 -> V_51 , V_30 ) ;
return V_28 ;
}
static int F_47 ( struct V_15 * V_48 ,
struct V_40 * V_41 )
{
struct V_2 * V_7 = V_48 -> V_59 ;
const T_4 * V_25 ;
T_4 V_79 ;
int V_80 , V_28 = 0 ;
struct V_81 * V_82 = NULL ;
struct V_83 * V_84 ;
if ( F_48 ( V_41 ) ) {
V_82 = F_49 ( V_41 ) ;
V_84 = F_50 ( V_82 -> V_85 ) ;
V_41 = V_84 -> V_86 ;
}
V_25 = F_51 ( V_41 -> V_77 , L_22 , & V_80 ) ;
if ( V_25 ) {
V_79 = V_80 / sizeof( T_4 ) ;
V_28 = F_46 ( V_7 , V_41 ,
V_25 , V_79 ) ;
} else {
F_3 ( L_23 ,
V_41 -> V_77 -> V_78 ) ;
V_28 = - V_39 ;
}
return V_28 ;
}
static void F_52 ( struct V_15 * V_48 ,
struct V_40 * V_41 )
{
struct V_2 * V_7 = V_48 -> V_59 ;
const T_4 * V_87 ;
int V_80 ;
struct V_81 * V_82 = NULL ;
struct V_83 * V_84 ;
if ( F_48 ( V_41 ) ) {
V_82 = F_49 ( V_41 ) ;
V_84 = F_50 ( V_82 -> V_85 ) ;
V_41 = V_84 -> V_86 ;
}
V_87 = F_51 ( V_41 -> V_77 , L_22 , & V_80 ) ;
if ( V_87 )
F_31 ( V_41 , V_7 ) ;
else
F_3 ( L_23 ,
V_41 -> V_77 -> V_78 ) ;
}
static int F_53 ( struct V_15 * V_48 , void * V_88 )
{
struct V_13 * V_42 = V_88 ;
struct V_2 * V_7 = V_48 -> V_59 ;
T_3 V_17 ;
unsigned long V_30 ;
V_17 = V_42 -> V_60 - V_42 -> V_21 + 1 ;
if ( F_21 ( V_17 , V_42 -> V_21 ) ||
! V_42 -> V_66 ) {
F_3 ( L_24 ) ;
return - V_39 ;
}
F_8 ( & V_7 -> V_51 , V_30 ) ;
if ( V_7 -> V_64 ) {
F_3 ( L_25 ) ;
F_10 ( & V_7 -> V_51 , V_30 ) ;
return - V_74 ;
}
memcpy ( & V_48 -> V_16 , V_42 ,
sizeof( struct V_13 ) ) ;
V_7 -> V_17 = V_17 ;
F_10 ( & V_7 -> V_51 , V_30 ) ;
return 0 ;
}
static int F_54 ( struct V_2 * V_7 , void * V_88 )
{
struct V_89 * V_90 = V_88 ;
unsigned long V_30 ;
int V_28 ;
F_8 ( & V_7 -> V_51 , V_30 ) ;
memcpy ( & V_7 -> V_91 , V_90 ,
sizeof( struct V_89 ) ) ;
V_7 -> V_34 = F_55 ( V_90 -> V_92 ,
V_90 -> V_93 ) ;
if ( V_7 -> V_34 == ~ ( T_4 ) 0 ) {
F_3 ( L_26 ) ;
F_10 ( & V_7 -> V_51 , V_30 ) ;
return - V_39 ;
}
V_28 = F_41 ( V_7 , V_7 -> V_34 ) ;
F_10 ( & V_7 -> V_51 , V_30 ) ;
return V_28 ;
}
static int F_56 ( struct V_2 * V_7 , bool V_94 )
{
struct V_6 * V_52 ;
unsigned long V_30 ;
int V_28 ;
F_8 ( & V_7 -> V_51 , V_30 ) ;
if ( V_94 && ! V_7 -> V_65 ) {
F_3 ( L_27 ) ;
F_10 ( & V_7 -> V_51 , V_30 ) ;
return - V_73 ;
}
V_7 -> V_64 = V_94 ;
F_40 (info, &dma_domain->devices,
link) {
V_28 = ( V_94 ) ? F_57 ( V_52 -> V_25 ) :
F_19 ( V_52 -> V_25 ) ;
if ( V_28 )
F_3 ( L_28 ,
V_52 -> V_25 ) ;
}
F_10 ( & V_7 -> V_51 , V_30 ) ;
return 0 ;
}
static int F_58 ( struct V_15 * V_48 ,
enum V_95 V_96 , void * V_88 )
{
struct V_2 * V_7 = V_48 -> V_59 ;
int V_28 = 0 ;
switch ( V_96 ) {
case V_97 :
V_28 = F_53 ( V_48 , V_88 ) ;
break;
case V_98 :
V_28 = F_54 ( V_7 , V_88 ) ;
break;
case V_99 :
V_28 = F_56 ( V_7 , * ( int * ) V_88 ) ;
break;
default:
F_3 ( L_29 ) ;
V_28 = - V_39 ;
break;
} ;
return V_28 ;
}
static int F_59 ( struct V_15 * V_48 ,
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
* ( int * ) V_88 = V_7 -> V_64 ;
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
static struct V_101 * F_60 ( struct V_40 * V_41 )
{
struct V_101 * V_102 ;
V_102 = F_61 ( V_41 ) ;
if ( ! V_102 )
V_102 = F_62 () ;
return V_102 ;
}
static bool F_63 ( struct V_83 * V_84 )
{
T_4 V_103 ;
V_103 = F_64 ( V_84 -> V_104 + ( V_105 >> 2 ) ) ;
V_103 &= V_106 ;
if ( V_103 >= 0x204 )
return 1 ;
return 0 ;
}
static struct V_101 * F_65 ( struct V_81 * V_82 )
{
struct V_81 * V_56 ;
struct V_101 * V_102 ;
struct V_107 * V_85 = V_82 -> V_85 ;
while ( V_85 ) {
F_40 (tmp, &bus->devices, bus_list) {
if ( V_56 == V_82 )
continue;
V_102 = F_61 ( & V_56 -> V_41 ) ;
if ( V_102 )
return V_102 ;
}
V_85 = V_85 -> V_86 ;
}
return NULL ;
}
static struct V_101 * F_66 ( struct V_81 * V_82 )
{
struct V_83 * V_84 ;
bool V_108 ;
struct V_101 * V_102 = NULL ;
V_84 = F_50 ( V_82 -> V_85 ) ;
V_108 = F_63 ( V_84 ) ;
if ( V_108 ) {
V_102 = F_67 ( & V_82 -> V_41 ) ;
if ( V_84 -> V_86 -> V_101 )
F_68 ( V_84 -> V_86 ) ;
} else {
if ( V_84 -> V_86 -> V_101 ) {
V_102 = F_60 ( V_84 -> V_86 ) ;
F_68 ( V_84 -> V_86 ) ;
} else
V_102 = F_65 ( V_82 ) ;
}
if ( ! V_102 )
V_102 = F_69 ( - V_73 ) ;
return V_102 ;
}
static int F_70 ( struct V_40 * V_41 )
{
struct V_101 * V_102 = F_69 ( - V_73 ) ;
struct V_81 * V_82 ;
const T_4 * V_87 ;
int V_28 = 0 , V_80 ;
if ( F_48 ( V_41 ) ) {
V_82 = F_49 ( V_41 ) ;
if ( V_82 -> V_109 )
return 0 ;
V_102 = F_66 ( V_82 ) ;
} else {
V_87 = F_51 ( V_41 -> V_77 , L_22 , & V_80 ) ;
if ( V_87 )
V_102 = F_60 ( V_41 ) ;
}
if ( F_71 ( V_102 ) )
return F_72 ( V_102 ) ;
if ( ! V_41 -> V_101 )
V_28 = F_73 ( V_102 , V_41 ) ;
F_74 ( V_102 ) ;
return V_28 ;
}
static void F_75 ( struct V_40 * V_41 )
{
F_68 ( V_41 ) ;
}
static int F_76 ( struct V_15 * V_48 , T_4 V_110 )
{
struct V_2 * V_7 = V_48 -> V_59 ;
unsigned long V_30 ;
int V_28 ;
F_8 ( & V_7 -> V_51 , V_30 ) ;
if ( V_7 -> V_64 ) {
F_3 ( L_25 ) ;
F_10 ( & V_7 -> V_51 , V_30 ) ;
return - V_74 ;
}
if ( ! V_7 -> V_17 ) {
F_3 ( L_30 ) ;
F_10 ( & V_7 -> V_51 , V_30 ) ;
return - V_39 ;
}
if ( V_110 > F_24 () || ! F_77 ( V_110 ) ) {
F_3 ( L_31 ) ;
F_10 ( & V_7 -> V_51 , V_30 ) ;
return - V_39 ;
}
V_28 = F_39 ( V_7 , & V_48 -> V_16 ,
( ( V_110 > 1 ) ? V_110 : 0 ) ) ;
if ( ! V_28 ) {
F_78 ( V_7 -> V_12 ) ;
V_7 -> V_12 = F_79 ( sizeof( struct V_10 ) *
V_110 , V_58 ) ;
if ( ! V_7 -> V_12 ) {
F_10 ( & V_7 -> V_51 , V_30 ) ;
return - V_4 ;
}
V_7 -> V_9 = V_110 ;
}
F_10 ( & V_7 -> V_51 , V_30 ) ;
return V_28 ;
}
static T_4 F_80 ( struct V_15 * V_48 )
{
struct V_2 * V_7 = V_48 -> V_59 ;
return V_7 -> V_9 ;
}
int F_81 ( void )
{
int V_28 = 0 ;
V_28 = F_1 () ;
if ( V_28 )
return V_28 ;
F_82 ( & V_111 , & V_112 ) ;
F_82 ( & V_113 , & V_112 ) ;
return V_28 ;
}
