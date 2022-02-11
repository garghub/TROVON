static void F_1 ( struct V_1 * V_2 ,
char * V_3 , int V_4 )
{
#ifdef F_2
struct V_5 * V_6 ;
F_3 ( L_1 , V_7 , V_2 ) ;
F_4 (map, &priv->maps, next)
F_3 ( L_2 ,
V_6 -> V_8 , V_6 -> V_9 ,
V_6 -> V_8 == V_4 && V_3 ? V_3 : L_3 ) ;
#endif
}
static void F_5 ( struct V_5 * V_6 )
{
if ( V_6 == NULL )
return;
if ( V_6 -> V_10 )
F_6 ( V_6 -> V_9 , V_6 -> V_10 ) ;
F_7 ( V_6 -> V_10 ) ;
F_7 ( V_6 -> V_11 ) ;
F_7 ( V_6 -> V_12 ) ;
F_7 ( V_6 -> V_13 ) ;
F_7 ( V_6 -> V_14 ) ;
F_7 ( V_6 -> V_15 ) ;
F_7 ( V_6 ) ;
}
static struct V_5 * F_8 ( struct V_1 * V_2 , int V_9 )
{
struct V_5 * V_16 ;
int V_17 ;
V_16 = F_9 ( sizeof( struct V_5 ) , V_18 ) ;
if ( NULL == V_16 )
return NULL ;
V_16 -> V_11 = F_10 ( V_9 , sizeof( V_16 -> V_11 [ 0 ] ) , V_18 ) ;
V_16 -> V_12 = F_10 ( V_9 , sizeof( V_16 -> V_12 [ 0 ] ) , V_18 ) ;
V_16 -> V_13 = F_10 ( V_9 , sizeof( V_16 -> V_13 [ 0 ] ) , V_18 ) ;
V_16 -> V_14 = F_10 ( V_9 , sizeof( V_16 -> V_14 [ 0 ] ) , V_18 ) ;
V_16 -> V_15 = F_10 ( V_9 , sizeof( V_16 -> V_15 [ 0 ] ) , V_18 ) ;
V_16 -> V_10 = F_10 ( V_9 , sizeof( V_16 -> V_10 [ 0 ] ) , V_18 ) ;
if ( NULL == V_16 -> V_11 ||
NULL == V_16 -> V_12 ||
NULL == V_16 -> V_13 ||
NULL == V_16 -> V_14 ||
NULL == V_16 -> V_15 ||
NULL == V_16 -> V_10 )
goto V_19;
if ( F_11 ( V_9 , V_16 -> V_10 ) )
goto V_19;
for ( V_17 = 0 ; V_17 < V_9 ; V_17 ++ ) {
V_16 -> V_12 [ V_17 ] . V_20 = - 1 ;
V_16 -> V_13 [ V_17 ] . V_20 = - 1 ;
V_16 -> V_14 [ V_17 ] . V_20 = - 1 ;
V_16 -> V_15 [ V_17 ] . V_20 = - 1 ;
}
V_16 -> V_8 = 0 ;
V_16 -> V_9 = V_9 ;
F_12 ( & V_16 -> V_21 , 1 ) ;
return V_16 ;
V_19:
F_5 ( V_16 ) ;
return NULL ;
}
static void F_13 ( struct V_1 * V_2 , struct V_5 * V_16 )
{
struct V_5 * V_6 ;
F_4 (map, &priv->maps, next) {
if ( V_16 -> V_8 + V_16 -> V_9 < V_6 -> V_8 ) {
F_14 ( & V_16 -> V_22 , & V_6 -> V_22 ) ;
goto V_23;
}
V_16 -> V_8 = V_6 -> V_8 + V_6 -> V_9 ;
}
F_14 ( & V_16 -> V_22 , & V_2 -> V_24 ) ;
V_23:
F_1 ( V_2 , L_4 , V_16 -> V_8 ) ;
}
static struct V_5 * F_15 ( struct V_1 * V_2 ,
int V_8 , int V_9 )
{
struct V_5 * V_6 ;
F_4 (map, &priv->maps, next) {
if ( V_6 -> V_8 != V_8 )
continue;
if ( V_9 && V_6 -> V_9 != V_9 )
continue;
return V_6 ;
}
return NULL ;
}
static void F_16 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
if ( ! V_6 )
return;
if ( ! F_17 ( & V_6 -> V_21 ) )
return;
F_18 ( V_6 -> V_9 , & V_25 ) ;
if ( V_6 -> V_26 . V_27 & V_28 ) {
F_19 ( V_6 -> V_26 . V_29 ) ;
F_20 ( V_6 -> V_26 . V_29 ) ;
}
if ( V_30 && V_2 ) {
F_21 ( & V_2 -> V_31 ) ;
F_22 ( & V_6 -> V_22 ) ;
F_23 ( & V_2 -> V_31 ) ;
}
if ( V_6 -> V_10 && ! V_32 )
F_24 ( V_6 , 0 , V_6 -> V_9 ) ;
F_5 ( V_6 ) ;
}
static int F_25 ( T_1 * V_33 , T_2 V_34 ,
unsigned long V_35 , void * V_36 )
{
struct V_5 * V_6 = V_36 ;
unsigned int V_37 = ( V_35 - V_6 -> V_38 -> V_39 ) >> V_40 ;
int V_27 = V_6 -> V_27 | V_41 | V_42 ;
T_3 V_43 ;
F_26 ( V_37 >= V_6 -> V_9 ) ;
V_43 = F_27 ( V_33 ) . V_44 ;
if ( F_28 ( V_45 ) )
V_27 |= ( 1 << V_46 ) ;
F_29 ( & V_6 -> V_12 [ V_37 ] , V_43 , V_27 ,
V_6 -> V_11 [ V_37 ] . V_47 ,
V_6 -> V_11 [ V_37 ] . V_48 ) ;
F_30 ( & V_6 -> V_13 [ V_37 ] , V_43 , V_27 ,
- 1 ) ;
return 0 ;
}
static int F_31 ( T_1 * V_33 , T_2 V_34 ,
unsigned long V_35 , void * V_36 )
{
F_32 ( V_49 -> V_50 , V_35 , V_33 , F_33 ( * V_33 ) ) ;
return 0 ;
}
static int F_34 ( struct V_5 * V_6 )
{
int V_17 , V_19 = 0 ;
if ( ! V_32 ) {
if ( V_6 -> V_12 [ 0 ] . V_20 != - 1 )
return 0 ;
for ( V_17 = 0 ; V_17 < V_6 -> V_9 ; V_17 ++ ) {
unsigned long V_35 = ( unsigned long )
F_35 ( F_36 ( V_6 -> V_10 [ V_17 ] ) ) ;
F_29 ( & V_6 -> V_12 [ V_17 ] , V_35 , V_6 -> V_27 ,
V_6 -> V_11 [ V_17 ] . V_47 ,
V_6 -> V_11 [ V_17 ] . V_48 ) ;
F_30 ( & V_6 -> V_13 [ V_17 ] , V_35 ,
V_6 -> V_27 , - 1 ) ;
}
} else {
for ( V_17 = 0 ; V_17 < V_6 -> V_9 ; V_17 ++ ) {
unsigned long V_51 = ( unsigned long )
F_35 ( F_36 ( V_6 -> V_10 [ V_17 ] ) ) ;
F_26 ( F_37 ( V_6 -> V_10 [ V_17 ] ) ) ;
F_29 ( & V_6 -> V_14 [ V_17 ] , V_51 ,
V_6 -> V_27 | V_52 ,
V_6 -> V_11 [ V_17 ] . V_47 ,
V_6 -> V_11 [ V_17 ] . V_48 ) ;
F_30 ( & V_6 -> V_15 [ V_17 ] , V_51 ,
V_6 -> V_27 | V_52 , - 1 ) ;
}
}
F_3 ( L_5 , V_6 -> V_8 , V_6 -> V_9 ) ;
V_19 = F_38 ( V_6 -> V_12 , V_32 ? V_6 -> V_14 : NULL ,
V_6 -> V_10 , V_6 -> V_9 ) ;
if ( V_19 )
return V_19 ;
for ( V_17 = 0 ; V_17 < V_6 -> V_9 ; V_17 ++ ) {
if ( V_6 -> V_12 [ V_17 ] . V_53 ) {
V_19 = - V_54 ;
continue;
}
V_6 -> V_13 [ V_17 ] . V_20 = V_6 -> V_12 [ V_17 ] . V_20 ;
if ( V_32 )
V_6 -> V_15 [ V_17 ] . V_20 = V_6 -> V_14 [ V_17 ] . V_20 ;
}
return V_19 ;
}
static int F_39 ( struct V_5 * V_6 , int V_55 , int V_10 )
{
int V_17 , V_19 = 0 ;
struct V_56 V_57 ;
if ( V_6 -> V_26 . V_27 & V_58 ) {
int V_59 = ( V_6 -> V_26 . V_35 >> V_40 ) ;
if ( V_59 >= V_55 && V_59 < V_55 + V_10 ) {
T_4 * V_60 = F_35 ( F_36 ( V_6 -> V_10 [ V_59 ] ) ) ;
V_60 [ V_6 -> V_26 . V_35 & ( V_61 - 1 ) ] = 0 ;
V_6 -> V_26 . V_27 &= ~ V_58 ;
}
}
V_57 . V_13 = V_6 -> V_13 + V_55 ;
V_57 . V_15 = V_32 ? V_6 -> V_15 + V_55 : NULL ;
V_57 . V_10 = V_6 -> V_10 + V_55 ;
V_57 . V_9 = V_10 ;
V_19 = F_40 ( & V_57 ) ;
if ( V_19 )
return V_19 ;
for ( V_17 = 0 ; V_17 < V_10 ; V_17 ++ ) {
if ( V_6 -> V_13 [ V_55 + V_17 ] . V_53 )
V_19 = - V_54 ;
F_3 ( L_6 ,
V_6 -> V_13 [ V_55 + V_17 ] . V_20 ,
V_6 -> V_13 [ V_55 + V_17 ] . V_53 ) ;
V_6 -> V_13 [ V_55 + V_17 ] . V_20 = - 1 ;
}
return V_19 ;
}
static int F_24 ( struct V_5 * V_6 , int V_55 , int V_10 )
{
int V_62 , V_19 = 0 ;
F_3 ( L_7 , V_6 -> V_8 , V_6 -> V_9 , V_55 , V_10 ) ;
while ( V_10 && ! V_19 ) {
while ( V_10 && V_6 -> V_13 [ V_55 ] . V_20 == - 1 ) {
V_55 ++ ;
V_10 -- ;
}
V_62 = 0 ;
while ( V_62 < V_10 ) {
if ( V_6 -> V_13 [ V_55 + V_62 ] . V_20 == - 1 ) {
V_62 -- ;
break;
}
V_62 ++ ;
}
V_19 = F_39 ( V_6 , V_55 , V_62 ) ;
V_55 += V_62 ;
V_10 -= V_62 ;
}
return V_19 ;
}
static void F_41 ( struct V_63 * V_38 )
{
struct V_5 * V_6 = V_38 -> V_64 ;
F_3 ( L_8 , V_38 ) ;
F_42 ( & V_6 -> V_21 ) ;
}
static void F_43 ( struct V_63 * V_38 )
{
struct V_5 * V_6 = V_38 -> V_64 ;
struct V_65 * V_65 = V_38 -> V_66 ;
struct V_1 * V_2 = V_65 -> V_67 ;
F_3 ( L_9 , V_38 ) ;
if ( V_32 ) {
F_21 ( & V_2 -> V_31 ) ;
V_6 -> V_38 = NULL ;
F_23 ( & V_2 -> V_31 ) ;
}
V_38 -> V_64 = NULL ;
F_16 ( V_2 , V_6 ) ;
}
static struct V_68 * F_44 ( struct V_63 * V_38 ,
unsigned long V_35 )
{
struct V_5 * V_6 = V_38 -> V_64 ;
return V_6 -> V_10 [ ( V_35 - V_6 -> V_69 ) >> V_40 ] ;
}
static void F_45 ( struct V_5 * V_6 ,
unsigned long V_70 , unsigned long V_71 )
{
unsigned long V_72 , V_73 ;
int V_19 ;
if ( ! V_6 -> V_38 )
return;
if ( V_6 -> V_38 -> V_39 >= V_71 )
return;
if ( V_6 -> V_38 -> V_74 <= V_70 )
return;
V_72 = F_46 ( V_70 , V_6 -> V_38 -> V_39 ) ;
V_73 = F_47 ( V_71 , V_6 -> V_38 -> V_74 ) ;
F_3 ( L_10 ,
V_6 -> V_8 , V_6 -> V_9 ,
V_6 -> V_38 -> V_39 , V_6 -> V_38 -> V_74 ,
V_70 , V_71 , V_72 , V_73 ) ;
V_19 = F_24 ( V_6 ,
( V_72 - V_6 -> V_38 -> V_39 ) >> V_40 ,
( V_73 - V_72 ) >> V_40 ) ;
F_48 ( V_19 ) ;
}
static void F_49 ( struct V_75 * V_76 ,
struct V_77 * V_50 ,
unsigned long V_70 , unsigned long V_71 )
{
struct V_1 * V_2 = F_50 ( V_76 , struct V_1 , V_76 ) ;
struct V_5 * V_6 ;
F_21 ( & V_2 -> V_31 ) ;
F_4 (map, &priv->maps, next) {
F_45 ( V_6 , V_70 , V_71 ) ;
}
F_4 (map, &priv->freeable_maps, next) {
F_45 ( V_6 , V_70 , V_71 ) ;
}
F_23 ( & V_2 -> V_31 ) ;
}
static void F_51 ( struct V_75 * V_76 ,
struct V_77 * V_50 ,
unsigned long V_51 )
{
F_49 ( V_76 , V_50 , V_51 , V_51 + V_61 ) ;
}
static void F_52 ( struct V_75 * V_76 ,
struct V_77 * V_50 )
{
struct V_1 * V_2 = F_50 ( V_76 , struct V_1 , V_76 ) ;
struct V_5 * V_6 ;
int V_19 ;
F_21 ( & V_2 -> V_31 ) ;
F_4 (map, &priv->maps, next) {
if ( ! V_6 -> V_38 )
continue;
F_3 ( L_11 ,
V_6 -> V_8 , V_6 -> V_9 ,
V_6 -> V_38 -> V_39 , V_6 -> V_38 -> V_74 ) ;
V_19 = F_24 ( V_6 , 0 , V_6 -> V_9 ) ;
F_48 ( V_19 ) ;
}
F_4 (map, &priv->freeable_maps, next) {
if ( ! V_6 -> V_38 )
continue;
F_3 ( L_11 ,
V_6 -> V_8 , V_6 -> V_9 ,
V_6 -> V_38 -> V_39 , V_6 -> V_38 -> V_74 ) ;
V_19 = F_24 ( V_6 , 0 , V_6 -> V_9 ) ;
F_48 ( V_19 ) ;
}
F_23 ( & V_2 -> V_31 ) ;
}
static int F_53 ( struct V_78 * V_78 , struct V_65 * V_79 )
{
struct V_1 * V_2 ;
int V_80 = 0 ;
V_2 = F_9 ( sizeof( * V_2 ) , V_18 ) ;
if ( ! V_2 )
return - V_81 ;
F_54 ( & V_2 -> V_24 ) ;
F_54 ( & V_2 -> V_82 ) ;
F_55 ( & V_2 -> V_31 ) ;
if ( V_32 ) {
V_2 -> V_50 = F_56 ( V_49 ) ;
if ( ! V_2 -> V_50 ) {
F_7 ( V_2 ) ;
return - V_81 ;
}
V_2 -> V_76 . V_83 = & V_84 ;
V_80 = F_57 ( & V_2 -> V_76 , V_2 -> V_50 ) ;
F_58 ( V_2 -> V_50 ) ;
}
if ( V_80 ) {
F_7 ( V_2 ) ;
return V_80 ;
}
V_79 -> V_67 = V_2 ;
F_3 ( L_12 , V_2 ) ;
return 0 ;
}
static int F_59 ( struct V_78 * V_78 , struct V_65 * V_79 )
{
struct V_1 * V_2 = V_79 -> V_67 ;
struct V_5 * V_6 ;
F_3 ( L_12 , V_2 ) ;
F_21 ( & V_2 -> V_31 ) ;
while ( ! F_60 ( & V_2 -> V_24 ) ) {
V_6 = F_61 ( V_2 -> V_24 . V_22 , struct V_5 , V_22 ) ;
F_22 ( & V_6 -> V_22 ) ;
F_16 ( NULL , V_6 ) ;
}
F_48 ( ! F_60 ( & V_2 -> V_82 ) ) ;
F_23 ( & V_2 -> V_31 ) ;
if ( V_32 )
F_62 ( & V_2 -> V_76 , V_2 -> V_50 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static long F_63 ( struct V_1 * V_2 ,
struct V_85 T_5 * V_86 )
{
struct V_85 V_87 ;
struct V_5 * V_6 ;
int V_19 ;
if ( F_64 ( & V_87 , V_86 , sizeof( V_87 ) ) != 0 )
return - V_88 ;
F_3 ( L_13 , V_2 , V_87 . V_9 ) ;
if ( F_65 ( V_87 . V_9 <= 0 ) )
return - V_54 ;
V_19 = - V_81 ;
V_6 = F_8 ( V_2 , V_87 . V_9 ) ;
if ( ! V_6 )
return V_19 ;
if ( F_65 ( F_66 ( V_87 . V_9 , & V_25 ) > V_89 ) ) {
F_3 ( L_14 ) ;
F_16 ( NULL , V_6 ) ;
return V_19 ;
}
if ( F_64 ( V_6 -> V_11 , & V_86 -> V_90 ,
sizeof( V_6 -> V_11 [ 0 ] ) * V_87 . V_9 ) != 0 ) {
F_16 ( NULL , V_6 ) ;
return - V_88 ;
}
F_21 ( & V_2 -> V_31 ) ;
F_13 ( V_2 , V_6 ) ;
V_87 . V_8 = V_6 -> V_8 << V_40 ;
F_23 ( & V_2 -> V_31 ) ;
if ( F_67 ( V_86 , & V_87 , sizeof( V_87 ) ) != 0 )
return - V_88 ;
return 0 ;
}
static long F_68 ( struct V_1 * V_2 ,
struct V_91 T_5 * V_86 )
{
struct V_91 V_87 ;
struct V_5 * V_6 ;
int V_19 = - V_92 ;
if ( F_64 ( & V_87 , V_86 , sizeof( V_87 ) ) != 0 )
return - V_88 ;
F_3 ( L_15 , V_2 , ( int ) V_87 . V_8 , ( int ) V_87 . V_9 ) ;
F_21 ( & V_2 -> V_31 ) ;
V_6 = F_15 ( V_2 , V_87 . V_8 >> V_40 , V_87 . V_9 ) ;
if ( V_6 ) {
F_22 ( & V_6 -> V_22 ) ;
if ( V_30 )
F_14 ( & V_6 -> V_22 , & V_2 -> V_82 ) ;
V_19 = 0 ;
}
F_23 ( & V_2 -> V_31 ) ;
if ( V_6 )
F_16 ( V_2 , V_6 ) ;
return V_19 ;
}
static long F_69 ( struct V_1 * V_2 ,
struct V_93 T_5 * V_86 )
{
struct V_93 V_87 ;
struct V_63 * V_38 ;
struct V_5 * V_6 ;
int V_94 = - V_54 ;
if ( F_64 ( & V_87 , V_86 , sizeof( V_87 ) ) != 0 )
return - V_88 ;
F_3 ( L_16 , V_2 , ( unsigned long ) V_87 . V_95 ) ;
F_70 ( & V_49 -> V_50 -> V_96 ) ;
V_38 = F_71 ( V_49 -> V_50 , V_87 . V_95 ) ;
if ( ! V_38 || V_38 -> V_97 != & V_98 )
goto V_99;
V_6 = V_38 -> V_64 ;
if ( ! V_6 )
goto V_99;
V_87 . V_55 = V_6 -> V_8 << V_40 ;
V_87 . V_9 = V_6 -> V_9 ;
V_94 = 0 ;
V_99:
F_72 ( & V_49 -> V_50 -> V_96 ) ;
if ( V_94 == 0 && F_67 ( V_86 , & V_87 , sizeof( V_87 ) ) != 0 )
return - V_88 ;
return V_94 ;
}
static long F_73 ( struct V_1 * V_2 , void T_5 * V_86 )
{
struct V_100 V_87 ;
struct V_5 * V_6 ;
int V_101 ;
int V_102 ;
unsigned int V_103 ;
if ( F_64 ( & V_87 , V_86 , sizeof( V_87 ) ) )
return - V_88 ;
if ( V_87 . V_104 & ~ ( V_58 | V_28 ) )
return - V_54 ;
if ( V_87 . V_104 & V_28 ) {
if ( F_74 ( V_87 . V_105 ) )
return - V_54 ;
}
V_102 = V_87 . V_104 ;
V_103 = V_87 . V_105 ;
F_21 ( & V_2 -> V_31 ) ;
F_4 (map, &priv->maps, next) {
T_6 V_106 = V_6 -> V_8 << V_40 ;
T_6 V_71 = ( V_6 -> V_8 + V_6 -> V_9 ) << V_40 ;
if ( V_87 . V_8 >= V_106 && V_87 . V_8 < V_71 )
goto V_107;
}
V_101 = - V_92 ;
goto V_108;
V_107:
if ( ( V_87 . V_104 & V_58 ) &&
( V_6 -> V_27 & V_109 ) ) {
V_101 = - V_54 ;
goto V_108;
}
V_102 = V_6 -> V_26 . V_27 ;
V_103 = V_6 -> V_26 . V_29 ;
V_6 -> V_26 . V_27 = V_87 . V_104 ;
V_6 -> V_26 . V_35 = V_87 . V_8 - ( V_6 -> V_8 << V_40 ) ;
V_6 -> V_26 . V_29 = V_87 . V_105 ;
V_101 = 0 ;
V_108:
F_23 ( & V_2 -> V_31 ) ;
if ( V_102 & V_28 )
F_20 ( V_103 ) ;
return V_101 ;
}
static long F_75 ( struct V_65 * V_79 ,
unsigned int V_110 , unsigned long V_111 )
{
struct V_1 * V_2 = V_79 -> V_67 ;
void T_5 * V_112 = ( void T_5 * ) V_111 ;
switch ( V_110 ) {
case V_113 :
return F_63 ( V_2 , V_112 ) ;
case V_114 :
return F_68 ( V_2 , V_112 ) ;
case V_115 :
return F_69 ( V_2 , V_112 ) ;
case V_116 :
return F_73 ( V_2 , V_112 ) ;
default:
F_3 ( L_17 , V_2 , V_110 ) ;
return - V_117 ;
}
return 0 ;
}
static int F_76 ( struct V_65 * V_79 , struct V_63 * V_38 )
{
struct V_1 * V_2 = V_79 -> V_67 ;
int V_8 = V_38 -> V_118 ;
int V_9 = ( V_38 -> V_74 - V_38 -> V_39 ) >> V_40 ;
struct V_5 * V_6 ;
int V_17 , V_19 = - V_54 ;
if ( ( V_38 -> V_119 & V_120 ) && ! ( V_38 -> V_119 & V_121 ) )
return - V_54 ;
F_3 ( L_18 ,
V_8 , V_9 , V_38 -> V_39 , V_38 -> V_118 ) ;
F_21 ( & V_2 -> V_31 ) ;
V_6 = F_15 ( V_2 , V_8 , V_9 ) ;
if ( ! V_6 )
goto V_108;
if ( V_32 && V_6 -> V_38 )
goto V_108;
if ( V_32 && V_2 -> V_50 != V_38 -> V_122 ) {
F_77 ( L_19 ) ;
goto V_108;
}
F_42 ( & V_6 -> V_21 ) ;
V_38 -> V_97 = & V_98 ;
V_38 -> V_119 |= V_123 | V_124 | V_125 ;
if ( V_32 )
V_38 -> V_119 |= V_126 ;
V_38 -> V_64 = V_6 ;
if ( V_32 )
V_6 -> V_38 = V_38 ;
if ( V_6 -> V_27 ) {
if ( ( V_38 -> V_119 & V_120 ) &&
( V_6 -> V_27 & V_109 ) )
goto V_127;
} else {
V_6 -> V_27 = V_52 ;
if ( ! ( V_38 -> V_119 & V_120 ) )
V_6 -> V_27 |= V_109 ;
}
F_23 ( & V_2 -> V_31 ) ;
if ( V_32 ) {
V_19 = F_78 ( V_38 -> V_122 , V_38 -> V_39 ,
V_38 -> V_74 - V_38 -> V_39 ,
F_25 , V_6 ) ;
if ( V_19 ) {
F_77 ( L_20 ) ;
goto V_128;
}
}
V_19 = F_34 ( V_6 ) ;
if ( V_19 )
goto V_128;
if ( ! V_32 ) {
for ( V_17 = 0 ; V_17 < V_9 ; V_17 ++ ) {
V_19 = F_79 ( V_38 , V_38 -> V_39 + V_17 * V_61 ,
V_6 -> V_10 [ V_17 ] ) ;
if ( V_19 )
goto V_128;
}
} else {
#ifdef F_80
if ( ! F_28 ( V_45 ) ) {
F_78 ( V_38 -> V_122 , V_38 -> V_39 ,
V_38 -> V_74 - V_38 -> V_39 ,
F_31 , NULL ) ;
}
#endif
V_6 -> V_69 = V_38 -> V_39 ;
}
return 0 ;
V_108:
F_23 ( & V_2 -> V_31 ) ;
return V_19 ;
V_127:
F_23 ( & V_2 -> V_31 ) ;
V_128:
if ( V_32 )
V_6 -> V_38 = NULL ;
F_16 ( V_2 , V_6 ) ;
return V_19 ;
}
static int T_7 F_81 ( void )
{
int V_19 ;
if ( ! F_82 () )
return - V_129 ;
V_32 = ! F_28 ( V_130 ) ;
V_19 = F_83 ( & V_131 ) ;
if ( V_19 != 0 ) {
F_84 ( L_21 ) ;
return V_19 ;
}
return 0 ;
}
static void T_8 F_85 ( void )
{
F_86 ( & V_131 ) ;
}
