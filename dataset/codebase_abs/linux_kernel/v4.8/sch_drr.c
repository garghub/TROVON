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
unsigned int V_15 = V_11 -> V_13 -> V_16 . V_15 ;
F_6 ( V_11 -> V_13 ) ;
F_7 ( V_11 -> V_13 , V_12 , V_15 ) ;
}
static int F_8 ( struct V_2 * V_3 , T_1 V_4 , T_1 V_17 ,
struct V_18 * * V_19 , unsigned long * V_20 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 = (struct V_1 * ) * V_20 ;
struct V_18 * V_21 = V_19 [ V_22 ] ;
struct V_18 * V_23 [ V_24 + 1 ] ;
T_1 V_25 ;
int V_26 ;
if ( ! V_21 )
return - V_27 ;
V_26 = F_9 ( V_23 , V_24 , V_21 , V_28 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_23 [ V_29 ] ) {
V_25 = F_10 ( V_23 [ V_29 ] ) ;
if ( V_25 == 0 )
return - V_27 ;
} else
V_25 = F_11 ( F_12 ( V_3 ) ) ;
if ( V_11 != NULL ) {
if ( V_19 [ V_30 ] ) {
V_26 = F_13 ( & V_11 -> V_31 , NULL ,
& V_11 -> V_32 ,
NULL ,
F_14 ( V_3 ) ,
V_19 [ V_30 ] ) ;
if ( V_26 )
return V_26 ;
}
F_15 ( V_3 ) ;
if ( V_23 [ V_29 ] )
V_11 -> V_25 = V_25 ;
F_16 ( V_3 ) ;
return 0 ;
}
V_11 = F_17 ( sizeof( struct V_1 ) , V_33 ) ;
if ( V_11 == NULL )
return - V_34 ;
V_11 -> V_35 = 1 ;
V_11 -> V_10 . V_4 = V_4 ;
V_11 -> V_25 = V_25 ;
V_11 -> V_13 = F_18 ( V_3 -> V_36 ,
& V_37 , V_4 ) ;
if ( V_11 -> V_13 == NULL )
V_11 -> V_13 = & V_38 ;
if ( V_19 [ V_30 ] ) {
V_26 = F_13 ( & V_11 -> V_31 , NULL , & V_11 -> V_32 ,
NULL ,
F_14 ( V_3 ) ,
V_19 [ V_30 ] ) ;
if ( V_26 ) {
F_19 ( V_11 -> V_13 ) ;
F_20 ( V_11 ) ;
return V_26 ;
}
}
F_15 ( V_3 ) ;
F_21 ( & V_6 -> V_9 , & V_11 -> V_10 ) ;
F_16 ( V_3 ) ;
F_22 ( V_3 , & V_6 -> V_9 ) ;
* V_20 = ( unsigned long ) V_11 ;
return 0 ;
}
static void F_23 ( struct V_2 * V_3 , struct V_1 * V_11 )
{
F_24 ( & V_11 -> V_31 , & V_11 -> V_32 ) ;
F_19 ( V_11 -> V_13 ) ;
F_20 ( V_11 ) ;
}
static int F_25 ( struct V_2 * V_3 , unsigned long V_20 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 = (struct V_1 * ) V_20 ;
if ( V_11 -> V_39 > 0 )
return - V_40 ;
F_15 ( V_3 ) ;
F_5 ( V_11 ) ;
F_26 ( & V_6 -> V_9 , & V_11 -> V_10 ) ;
F_27 ( -- V_11 -> V_35 == 0 ) ;
F_16 ( V_3 ) ;
return 0 ;
}
static unsigned long F_28 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_1 * V_11 = F_1 ( V_3 , V_4 ) ;
if ( V_11 != NULL )
V_11 -> V_35 ++ ;
return ( unsigned long ) V_11 ;
}
static void F_29 ( struct V_2 * V_3 , unsigned long V_20 )
{
struct V_1 * V_11 = (struct V_1 * ) V_20 ;
if ( -- V_11 -> V_35 == 0 )
F_23 ( V_3 , V_11 ) ;
}
static struct V_41 T_2 * * F_30 ( struct V_2 * V_3 ,
unsigned long V_11 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
if ( V_11 )
return NULL ;
return & V_6 -> V_42 ;
}
static unsigned long F_31 ( struct V_2 * V_3 , unsigned long V_43 ,
T_1 V_4 )
{
struct V_1 * V_11 = F_1 ( V_3 , V_4 ) ;
if ( V_11 != NULL )
V_11 -> V_39 ++ ;
return ( unsigned long ) V_11 ;
}
static void F_32 ( struct V_2 * V_3 , unsigned long V_20 )
{
struct V_1 * V_11 = (struct V_1 * ) V_20 ;
V_11 -> V_39 -- ;
}
static int F_33 ( struct V_2 * V_3 , unsigned long V_20 ,
struct V_2 * V_44 , struct V_2 * * V_45 )
{
struct V_1 * V_11 = (struct V_1 * ) V_20 ;
if ( V_44 == NULL ) {
V_44 = F_18 ( V_3 -> V_36 ,
& V_37 , V_11 -> V_10 . V_4 ) ;
if ( V_44 == NULL )
V_44 = & V_38 ;
}
* V_45 = F_34 ( V_3 , V_44 , & V_11 -> V_13 ) ;
return 0 ;
}
static struct V_2 * F_35 ( struct V_2 * V_3 , unsigned long V_20 )
{
struct V_1 * V_11 = (struct V_1 * ) V_20 ;
return V_11 -> V_13 ;
}
static void F_36 ( struct V_2 * V_46 , unsigned long V_20 )
{
struct V_1 * V_11 = (struct V_1 * ) V_20 ;
if ( V_11 -> V_13 -> V_6 . V_14 == 0 )
F_37 ( & V_11 -> V_47 ) ;
}
static int F_38 ( struct V_2 * V_3 , unsigned long V_20 ,
struct V_48 * V_49 , struct V_50 * V_51 )
{
struct V_1 * V_11 = (struct V_1 * ) V_20 ;
struct V_18 * V_52 ;
V_51 -> V_53 = V_54 ;
V_51 -> V_55 = V_11 -> V_10 . V_4 ;
V_51 -> V_56 = V_11 -> V_13 -> V_57 ;
V_52 = F_39 ( V_49 , V_22 ) ;
if ( V_52 == NULL )
goto V_58;
if ( F_40 ( V_49 , V_29 , V_11 -> V_25 ) )
goto V_58;
return F_41 ( V_49 , V_52 ) ;
V_58:
F_42 ( V_49 , V_52 ) ;
return - V_59 ;
}
static int F_43 ( struct V_2 * V_3 , unsigned long V_20 ,
struct V_60 * V_61 )
{
struct V_1 * V_11 = (struct V_1 * ) V_20 ;
T_3 V_14 = V_11 -> V_13 -> V_6 . V_14 ;
struct V_62 V_63 ;
memset ( & V_63 , 0 , sizeof( V_63 ) ) ;
if ( V_14 )
V_63 . V_64 = V_11 -> V_64 ;
if ( F_44 ( F_14 ( V_3 ) ,
V_61 , NULL , & V_11 -> V_31 ) < 0 ||
F_45 ( V_61 , & V_11 -> V_31 , & V_11 -> V_32 ) < 0 ||
F_46 ( V_61 , NULL , & V_11 -> V_13 -> V_16 , V_14 ) < 0 )
return - 1 ;
return F_47 ( V_61 , & V_63 , sizeof( V_63 ) ) ;
}
static void F_48 ( struct V_2 * V_3 , struct V_65 * V_20 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
unsigned int V_66 ;
if ( V_20 -> V_67 )
return;
for ( V_66 = 0 ; V_66 < V_6 -> V_9 . V_68 ; V_66 ++ ) {
F_49 (cl, &q->clhash.hash[i], common.hnode) {
if ( V_20 -> V_69 < V_20 -> V_70 ) {
V_20 -> V_69 ++ ;
continue;
}
if ( V_20 -> V_71 ( V_3 , ( unsigned long ) V_11 , V_20 ) < 0 ) {
V_20 -> V_67 = 1 ;
return;
}
V_20 -> V_69 ++ ;
}
}
}
static struct V_1 * F_50 ( struct V_48 * V_49 , struct V_2 * V_3 ,
int * V_72 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
struct V_73 V_74 ;
struct V_41 * V_75 ;
int V_76 ;
if ( F_51 ( V_49 -> V_77 ^ V_3 -> V_57 ) == 0 ) {
V_11 = F_1 ( V_3 , V_49 -> V_77 ) ;
if ( V_11 != NULL )
return V_11 ;
}
* V_72 = V_78 | V_79 ;
V_75 = F_52 ( V_6 -> V_42 ) ;
V_76 = F_53 ( V_49 , V_75 , & V_74 , false ) ;
if ( V_76 >= 0 ) {
#ifdef F_54
switch ( V_76 ) {
case V_80 :
case V_81 :
* V_72 = V_78 | V_82 ;
case V_83 :
return NULL ;
}
#endif
V_11 = (struct V_1 * ) V_74 . V_84 ;
if ( V_11 == NULL )
V_11 = F_1 ( V_3 , V_74 . V_4 ) ;
return V_11 ;
}
return NULL ;
}
static int F_55 ( struct V_48 * V_49 , struct V_2 * V_3 ,
struct V_48 * * V_85 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
int V_26 = 0 ;
V_11 = F_50 ( V_49 , V_3 , & V_26 ) ;
if ( V_11 == NULL ) {
if ( V_26 & V_79 )
F_56 ( V_3 ) ;
F_57 ( V_49 , V_85 ) ;
return V_26 ;
}
V_26 = F_58 ( V_49 , V_11 -> V_13 , V_85 ) ;
if ( F_59 ( V_26 != V_78 ) ) {
if ( F_60 ( V_26 ) ) {
V_11 -> V_16 . V_86 ++ ;
F_56 ( V_3 ) ;
}
return V_26 ;
}
if ( V_11 -> V_13 -> V_6 . V_14 == 1 ) {
F_61 ( & V_11 -> V_47 , & V_6 -> V_87 ) ;
V_11 -> V_64 = V_11 -> V_25 ;
}
F_62 ( V_3 , V_49 ) ;
V_3 -> V_6 . V_14 ++ ;
return V_26 ;
}
static struct V_48 * F_63 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
struct V_48 * V_49 ;
unsigned int V_12 ;
if ( F_64 ( & V_6 -> V_87 ) )
goto V_88;
while ( 1 ) {
V_11 = F_65 ( & V_6 -> V_87 , struct V_1 , V_47 ) ;
V_49 = V_11 -> V_13 -> V_89 -> V_90 ( V_11 -> V_13 ) ;
if ( V_49 == NULL ) {
F_66 ( V_91 , V_11 -> V_13 ) ;
goto V_88;
}
V_12 = F_67 ( V_49 ) ;
if ( V_12 <= V_11 -> V_64 ) {
V_11 -> V_64 -= V_12 ;
V_49 = F_68 ( V_11 -> V_13 ) ;
if ( F_59 ( V_49 == NULL ) )
goto V_88;
if ( V_11 -> V_13 -> V_6 . V_14 == 0 )
F_37 ( & V_11 -> V_47 ) ;
F_69 ( & V_11 -> V_31 , V_49 ) ;
F_70 ( V_3 , V_49 ) ;
F_71 ( V_3 , V_49 ) ;
V_3 -> V_6 . V_14 -- ;
return V_49 ;
}
V_11 -> V_64 += V_11 -> V_25 ;
F_72 ( & V_11 -> V_47 , & V_6 -> V_87 ) ;
}
V_88:
return NULL ;
}
static int F_73 ( struct V_2 * V_3 , struct V_18 * V_21 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
int V_26 ;
V_26 = F_74 ( & V_6 -> V_9 ) ;
if ( V_26 < 0 )
return V_26 ;
F_75 ( & V_6 -> V_87 ) ;
return 0 ;
}
static void F_76 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
unsigned int V_66 ;
for ( V_66 = 0 ; V_66 < V_6 -> V_9 . V_68 ; V_66 ++ ) {
F_49 (cl, &q->clhash.hash[i], common.hnode) {
if ( V_11 -> V_13 -> V_6 . V_14 )
F_37 ( & V_11 -> V_47 ) ;
F_6 ( V_11 -> V_13 ) ;
}
}
V_3 -> V_16 . V_15 = 0 ;
V_3 -> V_6 . V_14 = 0 ;
}
static void F_77 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
struct V_92 * V_93 ;
unsigned int V_66 ;
F_78 ( & V_6 -> V_42 ) ;
for ( V_66 = 0 ; V_66 < V_6 -> V_9 . V_68 ; V_66 ++ ) {
F_79 (cl, next, &q->clhash.hash[i],
common.hnode)
F_23 ( V_3 , V_11 ) ;
}
F_80 ( & V_6 -> V_9 ) ;
}
static int T_4 F_81 ( void )
{
return F_82 ( & V_94 ) ;
}
static void T_5 F_83 ( void )
{
F_84 ( & V_94 ) ;
}
