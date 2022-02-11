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
F_7 ( V_6 ) ;
}
static struct V_5 * F_8 ( struct V_1 * V_2 , int V_9 )
{
struct V_5 * V_15 ;
int V_16 ;
V_15 = F_9 ( sizeof( struct V_5 ) , V_17 ) ;
if ( NULL == V_15 )
return NULL ;
V_15 -> V_11 = F_10 ( V_9 , sizeof( V_15 -> V_11 [ 0 ] ) , V_17 ) ;
V_15 -> V_12 = F_10 ( V_9 , sizeof( V_15 -> V_12 [ 0 ] ) , V_17 ) ;
V_15 -> V_13 = F_10 ( V_9 , sizeof( V_15 -> V_13 [ 0 ] ) , V_17 ) ;
V_15 -> V_14 = F_10 ( V_9 , sizeof( V_15 -> V_14 [ 0 ] ) , V_17 ) ;
V_15 -> V_10 = F_10 ( V_9 , sizeof( V_15 -> V_10 [ 0 ] ) , V_17 ) ;
if ( NULL == V_15 -> V_11 ||
NULL == V_15 -> V_12 ||
NULL == V_15 -> V_13 ||
NULL == V_15 -> V_14 ||
NULL == V_15 -> V_10 )
goto V_18;
if ( F_11 ( V_9 , V_15 -> V_10 , false ) )
goto V_18;
for ( V_16 = 0 ; V_16 < V_9 ; V_16 ++ ) {
V_15 -> V_12 [ V_16 ] . V_19 = - 1 ;
V_15 -> V_13 [ V_16 ] . V_19 = - 1 ;
V_15 -> V_14 [ V_16 ] . V_19 = - 1 ;
}
V_15 -> V_8 = 0 ;
V_15 -> V_9 = V_9 ;
F_12 ( & V_15 -> V_20 , 1 ) ;
return V_15 ;
V_18:
F_5 ( V_15 ) ;
return NULL ;
}
static void F_13 ( struct V_1 * V_2 , struct V_5 * V_15 )
{
struct V_5 * V_6 ;
F_4 (map, &priv->maps, next) {
if ( V_15 -> V_8 + V_15 -> V_9 < V_6 -> V_8 ) {
F_14 ( & V_15 -> V_21 , & V_6 -> V_21 ) ;
goto V_22;
}
V_15 -> V_8 = V_6 -> V_8 + V_6 -> V_9 ;
}
F_14 ( & V_15 -> V_21 , & V_2 -> V_23 ) ;
V_22:
F_1 ( V_2 , L_4 , V_15 -> V_8 ) ;
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
if ( ! F_17 ( & V_6 -> V_20 ) )
return;
F_18 ( V_6 -> V_9 , & V_24 ) ;
if ( V_6 -> V_25 . V_26 & V_27 ) {
F_19 ( V_6 -> V_25 . V_28 ) ;
F_20 ( V_6 -> V_25 . V_28 ) ;
}
if ( V_29 && V_2 ) {
F_21 ( & V_2 -> V_30 ) ;
F_22 ( & V_6 -> V_21 ) ;
F_23 ( & V_2 -> V_30 ) ;
}
if ( V_6 -> V_10 && ! V_31 )
F_24 ( V_6 , 0 , V_6 -> V_9 ) ;
F_5 ( V_6 ) ;
}
static int F_25 ( T_1 * V_32 , T_2 V_33 ,
unsigned long V_34 , void * V_35 )
{
struct V_5 * V_6 = V_35 ;
unsigned int V_36 = ( V_34 - V_6 -> V_37 -> V_38 ) >> V_39 ;
int V_26 = V_6 -> V_26 | V_40 | V_41 ;
T_3 V_42 ;
F_26 ( V_36 >= V_6 -> V_9 ) ;
V_42 = F_27 ( V_32 ) . V_43 ;
F_28 ( & V_6 -> V_12 [ V_36 ] , V_42 , V_26 ,
V_6 -> V_11 [ V_36 ] . V_44 ,
V_6 -> V_11 [ V_36 ] . V_45 ) ;
F_29 ( & V_6 -> V_13 [ V_36 ] , V_42 , V_26 ,
- 1 ) ;
return 0 ;
}
static int F_30 ( struct V_5 * V_6 )
{
int V_16 , V_18 = 0 ;
if ( ! V_31 ) {
if ( V_6 -> V_12 [ 0 ] . V_19 != - 1 )
return 0 ;
for ( V_16 = 0 ; V_16 < V_6 -> V_9 ; V_16 ++ ) {
unsigned long V_34 = ( unsigned long )
F_31 ( F_32 ( V_6 -> V_10 [ V_16 ] ) ) ;
F_28 ( & V_6 -> V_12 [ V_16 ] , V_34 , V_6 -> V_26 ,
V_6 -> V_11 [ V_16 ] . V_44 ,
V_6 -> V_11 [ V_16 ] . V_45 ) ;
F_29 ( & V_6 -> V_13 [ V_16 ] , V_34 ,
V_6 -> V_26 , - 1 ) ;
}
} else {
for ( V_16 = 0 ; V_16 < V_6 -> V_9 ; V_16 ++ ) {
unsigned V_46 ;
unsigned long V_47 = ( unsigned long )
F_31 ( F_32 ( V_6 -> V_10 [ V_16 ] ) ) ;
T_1 * V_48 ;
T_3 V_42 = 0 ;
F_26 ( F_33 ( V_6 -> V_10 [ V_16 ] ) ) ;
V_48 = F_34 ( V_47 , & V_46 ) ;
V_42 = F_27 ( V_48 ) . V_43 ;
F_28 ( & V_6 -> V_14 [ V_16 ] , V_42 ,
V_6 -> V_26 |
V_49 |
V_41 ,
V_6 -> V_11 [ V_16 ] . V_44 ,
V_6 -> V_11 [ V_16 ] . V_45 ) ;
}
}
F_3 ( L_5 , V_6 -> V_8 , V_6 -> V_9 ) ;
V_18 = F_35 ( V_6 -> V_12 , V_31 ? V_6 -> V_14 : NULL ,
V_6 -> V_10 , V_6 -> V_9 ) ;
if ( V_18 )
return V_18 ;
for ( V_16 = 0 ; V_16 < V_6 -> V_9 ; V_16 ++ ) {
if ( V_6 -> V_12 [ V_16 ] . V_50 )
V_18 = - V_51 ;
else {
F_26 ( V_6 -> V_12 [ V_16 ] . V_19 == - 1 ) ;
V_6 -> V_13 [ V_16 ] . V_19 = V_6 -> V_12 [ V_16 ] . V_19 ;
F_3 ( L_6 , V_6 -> V_12 [ V_16 ] . V_19 ) ;
}
}
return V_18 ;
}
static int F_36 ( struct V_5 * V_6 , int V_52 , int V_10 )
{
int V_16 , V_18 = 0 ;
if ( V_6 -> V_25 . V_26 & V_53 ) {
int V_54 = ( V_6 -> V_25 . V_34 >> V_39 ) ;
if ( V_54 >= V_52 && V_54 < V_52 + V_10 ) {
T_4 * V_55 = F_31 ( F_32 ( V_6 -> V_10 [ V_54 ] ) ) ;
V_55 [ V_6 -> V_25 . V_34 & ( V_56 - 1 ) ] = 0 ;
V_6 -> V_25 . V_26 &= ~ V_53 ;
}
}
V_18 = F_37 ( V_6 -> V_13 + V_52 ,
V_31 ? V_6 -> V_14 + V_52 : NULL , V_6 -> V_10 + V_52 ,
V_10 ) ;
if ( V_18 )
return V_18 ;
for ( V_16 = 0 ; V_16 < V_10 ; V_16 ++ ) {
if ( V_6 -> V_13 [ V_52 + V_16 ] . V_50 )
V_18 = - V_51 ;
F_3 ( L_7 ,
V_6 -> V_13 [ V_52 + V_16 ] . V_19 ,
V_6 -> V_13 [ V_52 + V_16 ] . V_50 ) ;
V_6 -> V_13 [ V_52 + V_16 ] . V_19 = - 1 ;
}
return V_18 ;
}
static int F_24 ( struct V_5 * V_6 , int V_52 , int V_10 )
{
int V_57 , V_18 = 0 ;
F_3 ( L_8 , V_6 -> V_8 , V_6 -> V_9 , V_52 , V_10 ) ;
while ( V_10 && ! V_18 ) {
while ( V_10 && V_6 -> V_13 [ V_52 ] . V_19 == - 1 ) {
V_52 ++ ;
V_10 -- ;
}
V_57 = 0 ;
while ( V_57 < V_10 ) {
if ( V_6 -> V_13 [ V_52 + V_57 ] . V_19 == - 1 ) {
V_57 -- ;
break;
}
V_57 ++ ;
}
V_18 = F_36 ( V_6 , V_52 , V_57 ) ;
V_52 += V_57 ;
V_10 -= V_57 ;
}
return V_18 ;
}
static void F_38 ( struct V_58 * V_37 )
{
struct V_5 * V_6 = V_37 -> V_59 ;
F_3 ( L_9 , V_37 ) ;
F_39 ( & V_6 -> V_20 ) ;
}
static void F_40 ( struct V_58 * V_37 )
{
struct V_5 * V_6 = V_37 -> V_59 ;
struct V_60 * V_60 = V_37 -> V_61 ;
struct V_1 * V_2 = V_60 -> V_62 ;
F_3 ( L_10 , V_37 ) ;
if ( V_31 ) {
F_21 ( & V_2 -> V_30 ) ;
V_6 -> V_37 = NULL ;
F_23 ( & V_2 -> V_30 ) ;
}
V_37 -> V_59 = NULL ;
F_16 ( V_2 , V_6 ) ;
}
static void F_41 ( struct V_5 * V_6 ,
unsigned long V_63 , unsigned long V_64 )
{
unsigned long V_65 , V_66 ;
int V_18 ;
if ( ! V_6 -> V_37 )
return;
if ( V_6 -> V_37 -> V_38 >= V_64 )
return;
if ( V_6 -> V_37 -> V_67 <= V_63 )
return;
V_65 = F_42 ( V_63 , V_6 -> V_37 -> V_38 ) ;
V_66 = F_43 ( V_64 , V_6 -> V_37 -> V_67 ) ;
F_3 ( L_11 ,
V_6 -> V_8 , V_6 -> V_9 ,
V_6 -> V_37 -> V_38 , V_6 -> V_37 -> V_67 ,
V_63 , V_64 , V_65 , V_66 ) ;
V_18 = F_24 ( V_6 ,
( V_65 - V_6 -> V_37 -> V_38 ) >> V_39 ,
( V_66 - V_65 ) >> V_39 ) ;
F_44 ( V_18 ) ;
}
static void F_45 ( struct V_68 * V_69 ,
struct V_70 * V_71 ,
unsigned long V_63 , unsigned long V_64 )
{
struct V_1 * V_2 = F_46 ( V_69 , struct V_1 , V_69 ) ;
struct V_5 * V_6 ;
F_21 ( & V_2 -> V_30 ) ;
F_4 (map, &priv->maps, next) {
F_41 ( V_6 , V_63 , V_64 ) ;
}
F_4 (map, &priv->freeable_maps, next) {
F_41 ( V_6 , V_63 , V_64 ) ;
}
F_23 ( & V_2 -> V_30 ) ;
}
static void F_47 ( struct V_68 * V_69 ,
struct V_70 * V_71 ,
unsigned long V_47 )
{
F_45 ( V_69 , V_71 , V_47 , V_47 + V_56 ) ;
}
static void F_48 ( struct V_68 * V_69 ,
struct V_70 * V_71 )
{
struct V_1 * V_2 = F_46 ( V_69 , struct V_1 , V_69 ) ;
struct V_5 * V_6 ;
int V_18 ;
F_21 ( & V_2 -> V_30 ) ;
F_4 (map, &priv->maps, next) {
if ( ! V_6 -> V_37 )
continue;
F_3 ( L_12 ,
V_6 -> V_8 , V_6 -> V_9 ,
V_6 -> V_37 -> V_38 , V_6 -> V_37 -> V_67 ) ;
V_18 = F_24 ( V_6 , 0 , V_6 -> V_9 ) ;
F_44 ( V_18 ) ;
}
F_4 (map, &priv->freeable_maps, next) {
if ( ! V_6 -> V_37 )
continue;
F_3 ( L_12 ,
V_6 -> V_8 , V_6 -> V_9 ,
V_6 -> V_37 -> V_38 , V_6 -> V_37 -> V_67 ) ;
V_18 = F_24 ( V_6 , 0 , V_6 -> V_9 ) ;
F_44 ( V_18 ) ;
}
F_23 ( & V_2 -> V_30 ) ;
}
static int F_49 ( struct V_72 * V_72 , struct V_60 * V_73 )
{
struct V_1 * V_2 ;
int V_74 = 0 ;
V_2 = F_9 ( sizeof( * V_2 ) , V_17 ) ;
if ( ! V_2 )
return - V_75 ;
F_50 ( & V_2 -> V_23 ) ;
F_50 ( & V_2 -> V_76 ) ;
F_51 ( & V_2 -> V_30 ) ;
if ( V_31 ) {
V_2 -> V_71 = F_52 ( V_77 ) ;
if ( ! V_2 -> V_71 ) {
F_7 ( V_2 ) ;
return - V_75 ;
}
V_2 -> V_69 . V_78 = & V_79 ;
V_74 = F_53 ( & V_2 -> V_69 , V_2 -> V_71 ) ;
F_54 ( V_2 -> V_71 ) ;
}
if ( V_74 ) {
F_7 ( V_2 ) ;
return V_74 ;
}
V_73 -> V_62 = V_2 ;
F_3 ( L_13 , V_2 ) ;
return 0 ;
}
static int F_55 ( struct V_72 * V_72 , struct V_60 * V_73 )
{
struct V_1 * V_2 = V_73 -> V_62 ;
struct V_5 * V_6 ;
F_3 ( L_13 , V_2 ) ;
while ( ! F_56 ( & V_2 -> V_23 ) ) {
V_6 = F_57 ( V_2 -> V_23 . V_21 , struct V_5 , V_21 ) ;
F_22 ( & V_6 -> V_21 ) ;
F_16 ( NULL , V_6 ) ;
}
F_44 ( ! F_56 ( & V_2 -> V_76 ) ) ;
if ( V_31 )
F_58 ( & V_2 -> V_69 , V_2 -> V_71 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static long F_59 ( struct V_1 * V_2 ,
struct V_80 T_5 * V_81 )
{
struct V_80 V_82 ;
struct V_5 * V_6 ;
int V_18 ;
if ( F_60 ( & V_82 , V_81 , sizeof( V_82 ) ) != 0 )
return - V_83 ;
F_3 ( L_14 , V_2 , V_82 . V_9 ) ;
if ( F_61 ( V_82 . V_9 <= 0 ) )
return - V_51 ;
V_18 = - V_75 ;
V_6 = F_8 ( V_2 , V_82 . V_9 ) ;
if ( ! V_6 )
return V_18 ;
if ( F_61 ( F_62 ( V_82 . V_9 , & V_24 ) > V_84 ) ) {
F_3 ( L_15 ) ;
F_16 ( NULL , V_6 ) ;
return V_18 ;
}
if ( F_60 ( V_6 -> V_11 , & V_81 -> V_85 ,
sizeof( V_6 -> V_11 [ 0 ] ) * V_82 . V_9 ) != 0 ) {
F_16 ( NULL , V_6 ) ;
return - V_83 ;
}
F_21 ( & V_2 -> V_30 ) ;
F_13 ( V_2 , V_6 ) ;
V_82 . V_8 = V_6 -> V_8 << V_39 ;
F_23 ( & V_2 -> V_30 ) ;
if ( F_63 ( V_81 , & V_82 , sizeof( V_82 ) ) != 0 )
return - V_83 ;
return 0 ;
}
static long F_64 ( struct V_1 * V_2 ,
struct V_86 T_5 * V_81 )
{
struct V_86 V_82 ;
struct V_5 * V_6 ;
int V_18 = - V_87 ;
if ( F_60 ( & V_82 , V_81 , sizeof( V_82 ) ) != 0 )
return - V_83 ;
F_3 ( L_16 , V_2 , ( int ) V_82 . V_8 , ( int ) V_82 . V_9 ) ;
F_21 ( & V_2 -> V_30 ) ;
V_6 = F_15 ( V_2 , V_82 . V_8 >> V_39 , V_82 . V_9 ) ;
if ( V_6 ) {
F_22 ( & V_6 -> V_21 ) ;
if ( V_29 )
F_14 ( & V_6 -> V_21 , & V_2 -> V_76 ) ;
V_18 = 0 ;
}
F_23 ( & V_2 -> V_30 ) ;
if ( V_6 )
F_16 ( V_2 , V_6 ) ;
return V_18 ;
}
static long F_65 ( struct V_1 * V_2 ,
struct V_88 T_5 * V_81 )
{
struct V_88 V_82 ;
struct V_58 * V_37 ;
struct V_5 * V_6 ;
int V_89 = - V_51 ;
if ( F_60 ( & V_82 , V_81 , sizeof( V_82 ) ) != 0 )
return - V_83 ;
F_3 ( L_17 , V_2 , ( unsigned long ) V_82 . V_90 ) ;
F_66 ( & V_77 -> V_71 -> V_91 ) ;
V_37 = F_67 ( V_77 -> V_71 , V_82 . V_90 ) ;
if ( ! V_37 || V_37 -> V_92 != & V_93 )
goto V_94;
V_6 = V_37 -> V_59 ;
if ( ! V_6 )
goto V_94;
V_82 . V_52 = V_6 -> V_8 << V_39 ;
V_82 . V_9 = V_6 -> V_9 ;
V_89 = 0 ;
V_94:
F_68 ( & V_77 -> V_71 -> V_91 ) ;
if ( V_89 == 0 && F_63 ( V_81 , & V_82 , sizeof( V_82 ) ) != 0 )
return - V_83 ;
return V_89 ;
}
static long F_69 ( struct V_1 * V_2 , void T_5 * V_81 )
{
struct V_95 V_82 ;
struct V_5 * V_6 ;
int V_96 ;
int V_97 ;
unsigned int V_98 ;
if ( F_60 ( & V_82 , V_81 , sizeof( V_82 ) ) )
return - V_83 ;
if ( V_82 . V_99 & ~ ( V_53 | V_27 ) )
return - V_51 ;
if ( V_82 . V_99 & V_27 ) {
if ( F_70 ( V_82 . V_100 ) )
return - V_51 ;
}
V_97 = V_82 . V_99 ;
V_98 = V_82 . V_100 ;
F_21 ( & V_2 -> V_30 ) ;
F_4 (map, &priv->maps, next) {
T_6 V_101 = V_6 -> V_8 << V_39 ;
T_6 V_64 = ( V_6 -> V_8 + V_6 -> V_9 ) << V_39 ;
if ( V_82 . V_8 >= V_101 && V_82 . V_8 < V_64 )
goto V_102;
}
V_96 = - V_87 ;
goto V_103;
V_102:
if ( ( V_82 . V_99 & V_53 ) &&
( V_6 -> V_26 & V_104 ) ) {
V_96 = - V_51 ;
goto V_103;
}
V_97 = V_6 -> V_25 . V_26 ;
V_98 = V_6 -> V_25 . V_28 ;
V_6 -> V_25 . V_26 = V_82 . V_99 ;
V_6 -> V_25 . V_34 = V_82 . V_8 - ( V_6 -> V_8 << V_39 ) ;
V_6 -> V_25 . V_28 = V_82 . V_100 ;
V_96 = 0 ;
V_103:
F_23 ( & V_2 -> V_30 ) ;
if ( V_97 & V_27 )
F_20 ( V_98 ) ;
return V_96 ;
}
static long F_71 ( struct V_60 * V_73 ,
unsigned int V_105 , unsigned long V_106 )
{
struct V_1 * V_2 = V_73 -> V_62 ;
void T_5 * V_107 = ( void T_5 * ) V_106 ;
switch ( V_105 ) {
case V_108 :
return F_59 ( V_2 , V_107 ) ;
case V_109 :
return F_64 ( V_2 , V_107 ) ;
case V_110 :
return F_65 ( V_2 , V_107 ) ;
case V_111 :
return F_69 ( V_2 , V_107 ) ;
default:
F_3 ( L_18 , V_2 , V_105 ) ;
return - V_112 ;
}
return 0 ;
}
static int F_72 ( struct V_60 * V_73 , struct V_58 * V_37 )
{
struct V_1 * V_2 = V_73 -> V_62 ;
int V_8 = V_37 -> V_113 ;
int V_9 = ( V_37 -> V_67 - V_37 -> V_38 ) >> V_39 ;
struct V_5 * V_6 ;
int V_16 , V_18 = - V_51 ;
if ( ( V_37 -> V_114 & V_115 ) && ! ( V_37 -> V_114 & V_116 ) )
return - V_51 ;
F_3 ( L_19 ,
V_8 , V_9 , V_37 -> V_38 , V_37 -> V_113 ) ;
F_21 ( & V_2 -> V_30 ) ;
V_6 = F_15 ( V_2 , V_8 , V_9 ) ;
if ( ! V_6 )
goto V_103;
if ( V_31 && V_6 -> V_37 )
goto V_103;
if ( V_31 && V_2 -> V_71 != V_37 -> V_117 ) {
F_73 ( L_20 ) ;
goto V_103;
}
F_39 ( & V_6 -> V_20 ) ;
V_37 -> V_92 = & V_93 ;
V_37 -> V_114 |= V_118 | V_119 ;
if ( V_31 )
V_37 -> V_114 |= V_120 ;
V_37 -> V_59 = V_6 ;
if ( V_31 )
V_6 -> V_37 = V_37 ;
if ( V_6 -> V_26 ) {
if ( ( V_37 -> V_114 & V_115 ) &&
( V_6 -> V_26 & V_104 ) )
goto V_121;
} else {
V_6 -> V_26 = V_49 ;
if ( ! ( V_37 -> V_114 & V_115 ) )
V_6 -> V_26 |= V_104 ;
}
F_23 ( & V_2 -> V_30 ) ;
if ( V_31 ) {
V_18 = F_74 ( V_37 -> V_117 , V_37 -> V_38 ,
V_37 -> V_67 - V_37 -> V_38 ,
F_25 , V_6 ) ;
if ( V_18 ) {
F_73 ( L_21 ) ;
goto V_122;
}
}
V_18 = F_30 ( V_6 ) ;
if ( V_18 )
goto V_122;
if ( ! V_31 ) {
for ( V_16 = 0 ; V_16 < V_9 ; V_16 ++ ) {
V_18 = F_75 ( V_37 , V_37 -> V_38 + V_16 * V_56 ,
V_6 -> V_10 [ V_16 ] ) ;
if ( V_18 )
goto V_122;
}
}
return 0 ;
V_103:
F_23 ( & V_2 -> V_30 ) ;
return V_18 ;
V_121:
F_23 ( & V_2 -> V_30 ) ;
V_122:
if ( V_31 )
V_6 -> V_37 = NULL ;
F_16 ( V_2 , V_6 ) ;
return V_18 ;
}
static int T_7 F_76 ( void )
{
int V_18 ;
if ( ! F_77 () )
return - V_123 ;
V_31 = F_78 () ;
V_18 = F_79 ( & V_124 ) ;
if ( V_18 != 0 ) {
F_80 ( L_22 ) ;
return V_18 ;
}
return 0 ;
}
static void T_8 F_81 ( void )
{
F_82 ( & V_124 ) ;
}
