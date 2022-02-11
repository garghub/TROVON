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
V_26 = F_9 ( V_23 , V_24 , V_21 , V_28 , NULL ) ;
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
V_11 -> V_10 . V_4 = V_4 ;
V_11 -> V_25 = V_25 ;
V_11 -> V_13 = F_18 ( V_3 -> V_35 ,
& V_36 , V_4 ) ;
if ( V_11 -> V_13 == NULL )
V_11 -> V_13 = & V_37 ;
else
F_19 ( V_11 -> V_13 , true ) ;
if ( V_19 [ V_30 ] ) {
V_26 = F_13 ( & V_11 -> V_31 , NULL , & V_11 -> V_32 ,
NULL ,
F_14 ( V_3 ) ,
V_19 [ V_30 ] ) ;
if ( V_26 ) {
F_20 ( V_11 -> V_13 ) ;
F_21 ( V_11 ) ;
return V_26 ;
}
}
F_15 ( V_3 ) ;
F_22 ( & V_6 -> V_9 , & V_11 -> V_10 ) ;
F_16 ( V_3 ) ;
F_23 ( V_3 , & V_6 -> V_9 ) ;
* V_20 = ( unsigned long ) V_11 ;
return 0 ;
}
static void F_24 ( struct V_2 * V_3 , struct V_1 * V_11 )
{
F_25 ( & V_11 -> V_32 ) ;
F_20 ( V_11 -> V_13 ) ;
F_21 ( V_11 ) ;
}
static int F_26 ( struct V_2 * V_3 , unsigned long V_20 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 = (struct V_1 * ) V_20 ;
if ( V_11 -> V_38 > 0 )
return - V_39 ;
F_15 ( V_3 ) ;
F_5 ( V_11 ) ;
F_27 ( & V_6 -> V_9 , & V_11 -> V_10 ) ;
F_16 ( V_3 ) ;
F_24 ( V_3 , V_11 ) ;
return 0 ;
}
static unsigned long F_28 ( struct V_2 * V_3 , T_1 V_4 )
{
return ( unsigned long ) F_1 ( V_3 , V_4 ) ;
}
static struct V_40 * F_29 ( struct V_2 * V_3 , unsigned long V_11 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
if ( V_11 )
return NULL ;
return V_6 -> V_41 ;
}
static unsigned long F_30 ( struct V_2 * V_3 , unsigned long V_42 ,
T_1 V_4 )
{
struct V_1 * V_11 = F_1 ( V_3 , V_4 ) ;
if ( V_11 != NULL )
V_11 -> V_38 ++ ;
return ( unsigned long ) V_11 ;
}
static void F_31 ( struct V_2 * V_3 , unsigned long V_20 )
{
struct V_1 * V_11 = (struct V_1 * ) V_20 ;
V_11 -> V_38 -- ;
}
static int F_32 ( struct V_2 * V_3 , unsigned long V_20 ,
struct V_2 * V_43 , struct V_2 * * V_44 )
{
struct V_1 * V_11 = (struct V_1 * ) V_20 ;
if ( V_43 == NULL ) {
V_43 = F_18 ( V_3 -> V_35 ,
& V_36 , V_11 -> V_10 . V_4 ) ;
if ( V_43 == NULL )
V_43 = & V_37 ;
}
* V_44 = F_33 ( V_3 , V_43 , & V_11 -> V_13 ) ;
return 0 ;
}
static struct V_2 * F_34 ( struct V_2 * V_3 , unsigned long V_20 )
{
struct V_1 * V_11 = (struct V_1 * ) V_20 ;
return V_11 -> V_13 ;
}
static void F_35 ( struct V_2 * V_45 , unsigned long V_20 )
{
struct V_1 * V_11 = (struct V_1 * ) V_20 ;
F_36 ( & V_11 -> V_46 ) ;
}
static int F_37 ( struct V_2 * V_3 , unsigned long V_20 ,
struct V_47 * V_48 , struct V_49 * V_50 )
{
struct V_1 * V_11 = (struct V_1 * ) V_20 ;
struct V_18 * V_51 ;
V_50 -> V_52 = V_53 ;
V_50 -> V_54 = V_11 -> V_10 . V_4 ;
V_50 -> V_55 = V_11 -> V_13 -> V_56 ;
V_51 = F_38 ( V_48 , V_22 ) ;
if ( V_51 == NULL )
goto V_57;
if ( F_39 ( V_48 , V_29 , V_11 -> V_25 ) )
goto V_57;
return F_40 ( V_48 , V_51 ) ;
V_57:
F_41 ( V_48 , V_51 ) ;
return - V_58 ;
}
static int F_42 ( struct V_2 * V_3 , unsigned long V_20 ,
struct V_59 * V_60 )
{
struct V_1 * V_11 = (struct V_1 * ) V_20 ;
T_2 V_14 = V_11 -> V_13 -> V_6 . V_14 ;
struct V_61 V_62 ;
memset ( & V_62 , 0 , sizeof( V_62 ) ) ;
if ( V_14 )
V_62 . V_63 = V_11 -> V_63 ;
if ( F_43 ( F_14 ( V_3 ) ,
V_60 , NULL , & V_11 -> V_31 ) < 0 ||
F_44 ( V_60 , & V_11 -> V_32 ) < 0 ||
F_45 ( V_60 , NULL , & V_11 -> V_13 -> V_16 , V_14 ) < 0 )
return - 1 ;
return F_46 ( V_60 , & V_62 , sizeof( V_62 ) ) ;
}
static void F_47 ( struct V_2 * V_3 , struct V_64 * V_20 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
unsigned int V_65 ;
if ( V_20 -> V_66 )
return;
for ( V_65 = 0 ; V_65 < V_6 -> V_9 . V_67 ; V_65 ++ ) {
F_48 (cl, &q->clhash.hash[i], common.hnode) {
if ( V_20 -> V_68 < V_20 -> V_69 ) {
V_20 -> V_68 ++ ;
continue;
}
if ( V_20 -> V_70 ( V_3 , ( unsigned long ) V_11 , V_20 ) < 0 ) {
V_20 -> V_66 = 1 ;
return;
}
V_20 -> V_68 ++ ;
}
}
}
static struct V_1 * F_49 ( struct V_47 * V_48 , struct V_2 * V_3 ,
int * V_71 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
struct V_72 V_73 ;
struct V_74 * V_75 ;
int V_76 ;
if ( F_50 ( V_48 -> V_77 ^ V_3 -> V_56 ) == 0 ) {
V_11 = F_1 ( V_3 , V_48 -> V_77 ) ;
if ( V_11 != NULL )
return V_11 ;
}
* V_71 = V_78 | V_79 ;
V_75 = F_51 ( V_6 -> V_80 ) ;
V_76 = F_52 ( V_48 , V_75 , & V_73 , false ) ;
if ( V_76 >= 0 ) {
#ifdef F_53
switch ( V_76 ) {
case V_81 :
case V_82 :
case V_83 :
* V_71 = V_78 | V_84 ;
case V_85 :
return NULL ;
}
#endif
V_11 = (struct V_1 * ) V_73 . V_86 ;
if ( V_11 == NULL )
V_11 = F_1 ( V_3 , V_73 . V_4 ) ;
return V_11 ;
}
return NULL ;
}
static int F_54 ( struct V_47 * V_48 , struct V_2 * V_3 ,
struct V_47 * * V_87 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
int V_26 = 0 ;
V_11 = F_49 ( V_48 , V_3 , & V_26 ) ;
if ( V_11 == NULL ) {
if ( V_26 & V_79 )
F_55 ( V_3 ) ;
F_56 ( V_48 , V_87 ) ;
return V_26 ;
}
V_26 = F_57 ( V_48 , V_11 -> V_13 , V_87 ) ;
if ( F_58 ( V_26 != V_78 ) ) {
if ( F_59 ( V_26 ) ) {
V_11 -> V_16 . V_88 ++ ;
F_55 ( V_3 ) ;
}
return V_26 ;
}
if ( V_11 -> V_13 -> V_6 . V_14 == 1 ) {
F_60 ( & V_11 -> V_46 , & V_6 -> V_89 ) ;
V_11 -> V_63 = V_11 -> V_25 ;
}
F_61 ( V_3 , V_48 ) ;
V_3 -> V_6 . V_14 ++ ;
return V_26 ;
}
static struct V_47 * F_62 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
struct V_47 * V_48 ;
unsigned int V_12 ;
if ( F_63 ( & V_6 -> V_89 ) )
goto V_90;
while ( 1 ) {
V_11 = F_64 ( & V_6 -> V_89 , struct V_1 , V_46 ) ;
V_48 = V_11 -> V_13 -> V_91 -> V_92 ( V_11 -> V_13 ) ;
if ( V_48 == NULL ) {
F_65 ( V_93 , V_11 -> V_13 ) ;
goto V_90;
}
V_12 = F_66 ( V_48 ) ;
if ( V_12 <= V_11 -> V_63 ) {
V_11 -> V_63 -= V_12 ;
V_48 = F_67 ( V_11 -> V_13 ) ;
if ( F_58 ( V_48 == NULL ) )
goto V_90;
if ( V_11 -> V_13 -> V_6 . V_14 == 0 )
F_36 ( & V_11 -> V_46 ) ;
F_68 ( & V_11 -> V_31 , V_48 ) ;
F_69 ( V_3 , V_48 ) ;
F_70 ( V_3 , V_48 ) ;
V_3 -> V_6 . V_14 -- ;
return V_48 ;
}
V_11 -> V_63 += V_11 -> V_25 ;
F_71 ( & V_11 -> V_46 , & V_6 -> V_89 ) ;
}
V_90:
return NULL ;
}
static int F_72 ( struct V_2 * V_3 , struct V_18 * V_21 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
int V_26 ;
V_26 = F_73 ( & V_6 -> V_41 , & V_6 -> V_80 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_74 ( & V_6 -> V_9 ) ;
if ( V_26 < 0 )
return V_26 ;
F_75 ( & V_6 -> V_89 ) ;
return 0 ;
}
static void F_76 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_11 ;
unsigned int V_65 ;
for ( V_65 = 0 ; V_65 < V_6 -> V_9 . V_67 ; V_65 ++ ) {
F_48 (cl, &q->clhash.hash[i], common.hnode) {
if ( V_11 -> V_13 -> V_6 . V_14 )
F_36 ( & V_11 -> V_46 ) ;
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
struct V_94 * V_95 ;
unsigned int V_65 ;
F_78 ( V_6 -> V_41 ) ;
for ( V_65 = 0 ; V_65 < V_6 -> V_9 . V_67 ; V_65 ++ ) {
F_79 (cl, next, &q->clhash.hash[i],
common.hnode)
F_24 ( V_3 , V_11 ) ;
}
F_80 ( & V_6 -> V_9 ) ;
}
static int T_3 F_81 ( void )
{
return F_82 ( & V_96 ) ;
}
static void T_4 F_83 ( void )
{
F_84 ( & V_96 ) ;
}
