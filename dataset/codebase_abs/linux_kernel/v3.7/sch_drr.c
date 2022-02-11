static struct V_1 * F_1 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_7 * V_8 ;
V_8 = F_3 ( & V_6 -> V_9 , V_4 ) ;
if ( V_8 == NULL )
return NULL ;
return F_4 ( V_8 , struct V_1 , V_10 ) ;
}
static void F_5 ( struct V_1 * V_11 )
{
unsigned int V_12 = V_11 -> V_13 -> V_6 . V_14 ;
F_6 ( V_11 -> V_13 ) ;
F_7 ( V_11 -> V_13 , V_12 ) ;
}
static int F_8 ( struct V_2 * V_3 , T_1 V_4 , T_1 V_15 ,
struct V_16 * * V_17 , unsigned long * V_18 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 = (struct V_1 * ) * V_18 ;
struct V_16 * V_19 = V_17 [ V_20 ] ;
struct V_16 * V_21 [ V_22 + 1 ] ;
T_1 V_23 ;
int V_24 ;
if ( ! V_19 )
return - V_25 ;
V_24 = F_9 ( V_21 , V_22 , V_19 , V_26 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_21 [ V_27 ] ) {
V_23 = F_10 ( V_21 [ V_27 ] ) ;
if ( V_23 == 0 )
return - V_25 ;
} else
V_23 = F_11 ( F_12 ( V_3 ) ) ;
if ( V_11 != NULL ) {
if ( V_17 [ V_28 ] ) {
V_24 = F_13 ( & V_11 -> V_29 , & V_11 -> V_30 ,
F_14 ( V_3 ) ,
V_17 [ V_28 ] ) ;
if ( V_24 )
return V_24 ;
}
F_15 ( V_3 ) ;
if ( V_21 [ V_27 ] )
V_11 -> V_23 = V_23 ;
F_16 ( V_3 ) ;
return 0 ;
}
V_11 = F_17 ( sizeof( struct V_1 ) , V_31 ) ;
if ( V_11 == NULL )
return - V_32 ;
V_11 -> V_33 = 1 ;
V_11 -> V_10 . V_4 = V_4 ;
V_11 -> V_23 = V_23 ;
V_11 -> V_13 = F_18 ( V_3 -> V_34 ,
& V_35 , V_4 ) ;
if ( V_11 -> V_13 == NULL )
V_11 -> V_13 = & V_36 ;
if ( V_17 [ V_28 ] ) {
V_24 = F_13 ( & V_11 -> V_29 , & V_11 -> V_30 ,
F_14 ( V_3 ) ,
V_17 [ V_28 ] ) ;
if ( V_24 ) {
F_19 ( V_11 -> V_13 ) ;
F_20 ( V_11 ) ;
return V_24 ;
}
}
F_15 ( V_3 ) ;
F_21 ( & V_6 -> V_9 , & V_11 -> V_10 ) ;
F_16 ( V_3 ) ;
F_22 ( V_3 , & V_6 -> V_9 ) ;
* V_18 = ( unsigned long ) V_11 ;
return 0 ;
}
static void F_23 ( struct V_2 * V_3 , struct V_1 * V_11 )
{
F_24 ( & V_11 -> V_29 , & V_11 -> V_30 ) ;
F_19 ( V_11 -> V_13 ) ;
F_20 ( V_11 ) ;
}
static int F_25 ( struct V_2 * V_3 , unsigned long V_18 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 = (struct V_1 * ) V_18 ;
if ( V_11 -> V_37 > 0 )
return - V_38 ;
F_15 ( V_3 ) ;
F_5 ( V_11 ) ;
F_26 ( & V_6 -> V_9 , & V_11 -> V_10 ) ;
F_27 ( -- V_11 -> V_33 == 0 ) ;
F_16 ( V_3 ) ;
return 0 ;
}
static unsigned long F_28 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_1 * V_11 = F_1 ( V_3 , V_4 ) ;
if ( V_11 != NULL )
V_11 -> V_33 ++ ;
return ( unsigned long ) V_11 ;
}
static void F_29 ( struct V_2 * V_3 , unsigned long V_18 )
{
struct V_1 * V_11 = (struct V_1 * ) V_18 ;
if ( -- V_11 -> V_33 == 0 )
F_23 ( V_3 , V_11 ) ;
}
static struct V_39 * * F_30 ( struct V_2 * V_3 , unsigned long V_11 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
if ( V_11 )
return NULL ;
return & V_6 -> V_40 ;
}
static unsigned long F_31 ( struct V_2 * V_3 , unsigned long V_41 ,
T_1 V_4 )
{
struct V_1 * V_11 = F_1 ( V_3 , V_4 ) ;
if ( V_11 != NULL )
V_11 -> V_37 ++ ;
return ( unsigned long ) V_11 ;
}
static void F_32 ( struct V_2 * V_3 , unsigned long V_18 )
{
struct V_1 * V_11 = (struct V_1 * ) V_18 ;
V_11 -> V_37 -- ;
}
static int F_33 ( struct V_2 * V_3 , unsigned long V_18 ,
struct V_2 * V_42 , struct V_2 * * V_43 )
{
struct V_1 * V_11 = (struct V_1 * ) V_18 ;
if ( V_42 == NULL ) {
V_42 = F_18 ( V_3 -> V_34 ,
& V_35 , V_11 -> V_10 . V_4 ) ;
if ( V_42 == NULL )
V_42 = & V_36 ;
}
F_15 ( V_3 ) ;
F_5 ( V_11 ) ;
* V_43 = V_11 -> V_13 ;
V_11 -> V_13 = V_42 ;
F_16 ( V_3 ) ;
return 0 ;
}
static struct V_2 * F_34 ( struct V_2 * V_3 , unsigned long V_18 )
{
struct V_1 * V_11 = (struct V_1 * ) V_18 ;
return V_11 -> V_13 ;
}
static void F_35 ( struct V_2 * V_44 , unsigned long V_18 )
{
struct V_1 * V_11 = (struct V_1 * ) V_18 ;
if ( V_11 -> V_13 -> V_6 . V_14 == 0 )
F_36 ( & V_11 -> V_45 ) ;
}
static int F_37 ( struct V_2 * V_3 , unsigned long V_18 ,
struct V_46 * V_47 , struct V_48 * V_49 )
{
struct V_1 * V_11 = (struct V_1 * ) V_18 ;
struct V_16 * V_50 ;
V_49 -> V_51 = V_52 ;
V_49 -> V_53 = V_11 -> V_10 . V_4 ;
V_49 -> V_54 = V_11 -> V_13 -> V_55 ;
V_50 = F_38 ( V_47 , V_20 ) ;
if ( V_50 == NULL )
goto V_56;
if ( F_39 ( V_47 , V_27 , V_11 -> V_23 ) )
goto V_56;
return F_40 ( V_47 , V_50 ) ;
V_56:
F_41 ( V_47 , V_50 ) ;
return - V_57 ;
}
static int F_42 ( struct V_2 * V_3 , unsigned long V_18 ,
struct V_58 * V_59 )
{
struct V_1 * V_11 = (struct V_1 * ) V_18 ;
struct V_60 V_61 ;
memset ( & V_61 , 0 , sizeof( V_61 ) ) ;
if ( V_11 -> V_13 -> V_6 . V_14 ) {
V_61 . V_62 = V_11 -> V_62 ;
V_11 -> V_13 -> V_63 . V_14 = V_11 -> V_13 -> V_6 . V_14 ;
}
if ( F_43 ( V_59 , & V_11 -> V_29 ) < 0 ||
F_44 ( V_59 , & V_11 -> V_29 , & V_11 -> V_30 ) < 0 ||
F_45 ( V_59 , & V_11 -> V_13 -> V_63 ) < 0 )
return - 1 ;
return F_46 ( V_59 , & V_61 , sizeof( V_61 ) ) ;
}
static void F_47 ( struct V_2 * V_3 , struct V_64 * V_18 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
struct V_65 * V_66 ;
unsigned int V_67 ;
if ( V_18 -> V_68 )
return;
for ( V_67 = 0 ; V_67 < V_6 -> V_9 . V_69 ; V_67 ++ ) {
F_48 (cl, n, &q->clhash.hash[i], common.hnode) {
if ( V_18 -> V_70 < V_18 -> V_71 ) {
V_18 -> V_70 ++ ;
continue;
}
if ( V_18 -> V_72 ( V_3 , ( unsigned long ) V_11 , V_18 ) < 0 ) {
V_18 -> V_68 = 1 ;
return;
}
V_18 -> V_70 ++ ;
}
}
}
static struct V_1 * F_49 ( struct V_46 * V_47 , struct V_2 * V_3 ,
int * V_73 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
struct V_74 V_75 ;
int V_76 ;
if ( F_50 ( V_47 -> V_77 ^ V_3 -> V_55 ) == 0 ) {
V_11 = F_1 ( V_3 , V_47 -> V_77 ) ;
if ( V_11 != NULL )
return V_11 ;
}
* V_73 = V_78 | V_79 ;
V_76 = F_51 ( V_47 , V_6 -> V_40 , & V_75 ) ;
if ( V_76 >= 0 ) {
#ifdef F_52
switch ( V_76 ) {
case V_80 :
case V_81 :
* V_73 = V_78 | V_82 ;
case V_83 :
return NULL ;
}
#endif
V_11 = (struct V_1 * ) V_75 . V_84 ;
if ( V_11 == NULL )
V_11 = F_1 ( V_3 , V_75 . V_4 ) ;
return V_11 ;
}
return NULL ;
}
static int F_53 ( struct V_46 * V_47 , struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
int V_24 = 0 ;
V_11 = F_49 ( V_47 , V_3 , & V_24 ) ;
if ( V_11 == NULL ) {
if ( V_24 & V_79 )
V_3 -> V_63 . V_85 ++ ;
F_54 ( V_47 ) ;
return V_24 ;
}
V_24 = F_55 ( V_47 , V_11 -> V_13 ) ;
if ( F_56 ( V_24 != V_78 ) ) {
if ( F_57 ( V_24 ) ) {
V_11 -> V_63 . V_85 ++ ;
V_3 -> V_63 . V_85 ++ ;
}
return V_24 ;
}
if ( V_11 -> V_13 -> V_6 . V_14 == 1 ) {
F_58 ( & V_11 -> V_45 , & V_6 -> V_86 ) ;
V_11 -> V_62 = V_11 -> V_23 ;
}
V_3 -> V_6 . V_14 ++ ;
return V_24 ;
}
static struct V_46 * F_59 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
struct V_46 * V_47 ;
unsigned int V_12 ;
if ( F_60 ( & V_6 -> V_86 ) )
goto V_87;
while ( 1 ) {
V_11 = F_61 ( & V_6 -> V_86 , struct V_1 , V_45 ) ;
V_47 = V_11 -> V_13 -> V_88 -> V_89 ( V_11 -> V_13 ) ;
if ( V_47 == NULL )
goto V_87;
V_12 = F_62 ( V_47 ) ;
if ( V_12 <= V_11 -> V_62 ) {
V_11 -> V_62 -= V_12 ;
V_47 = F_63 ( V_11 -> V_13 ) ;
if ( V_11 -> V_13 -> V_6 . V_14 == 0 )
F_36 ( & V_11 -> V_45 ) ;
F_64 ( & V_11 -> V_29 , V_47 ) ;
F_65 ( V_3 , V_47 ) ;
V_3 -> V_6 . V_14 -- ;
return V_47 ;
}
V_11 -> V_62 += V_11 -> V_23 ;
F_66 ( & V_11 -> V_45 , & V_6 -> V_86 ) ;
}
V_87:
return NULL ;
}
static unsigned int F_67 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
unsigned int V_12 ;
F_68 (cl, &q->active, alist) {
if ( V_11 -> V_13 -> V_88 -> V_90 ) {
V_12 = V_11 -> V_13 -> V_88 -> V_90 ( V_11 -> V_13 ) ;
if ( V_12 > 0 ) {
V_3 -> V_6 . V_14 -- ;
if ( V_11 -> V_13 -> V_6 . V_14 == 0 )
F_36 ( & V_11 -> V_45 ) ;
return V_12 ;
}
}
}
return 0 ;
}
static int F_69 ( struct V_2 * V_3 , struct V_16 * V_19 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
int V_24 ;
V_24 = F_70 ( & V_6 -> V_9 ) ;
if ( V_24 < 0 )
return V_24 ;
F_71 ( & V_6 -> V_86 ) ;
return 0 ;
}
static void F_72 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
struct V_65 * V_66 ;
unsigned int V_67 ;
for ( V_67 = 0 ; V_67 < V_6 -> V_9 . V_69 ; V_67 ++ ) {
F_48 (cl, n, &q->clhash.hash[i], common.hnode) {
if ( V_11 -> V_13 -> V_6 . V_14 )
F_36 ( & V_11 -> V_45 ) ;
F_6 ( V_11 -> V_13 ) ;
}
}
V_3 -> V_6 . V_14 = 0 ;
}
static void F_73 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
struct V_65 * V_66 , * V_91 ;
unsigned int V_67 ;
F_74 ( & V_6 -> V_40 ) ;
for ( V_67 = 0 ; V_67 < V_6 -> V_9 . V_69 ; V_67 ++ ) {
F_75 (cl, n, next, &q->clhash.hash[i],
common.hnode)
F_23 ( V_3 , V_11 ) ;
}
F_76 ( & V_6 -> V_9 ) ;
}
static int T_2 F_77 ( void )
{
return F_78 ( & V_92 ) ;
}
static void T_3 F_79 ( void )
{
F_80 ( & V_92 ) ;
}
