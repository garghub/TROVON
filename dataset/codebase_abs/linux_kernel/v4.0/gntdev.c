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
static void F_39 ( int V_55 ,
struct V_56 * V_36 )
{
struct V_57 * V_58 = V_36 -> V_36 ;
V_58 -> V_55 = V_55 ;
F_40 ( & V_58 -> V_59 ) ;
}
static int F_41 ( struct V_5 * V_6 , int V_60 , int V_10 )
{
int V_17 , V_19 = 0 ;
struct V_56 V_61 ;
struct V_57 V_36 ;
F_42 ( & V_36 . V_59 ) ;
V_61 . V_36 = & V_36 ;
V_61 . V_23 = & F_39 ;
if ( V_6 -> V_26 . V_27 & V_62 ) {
int V_63 = ( V_6 -> V_26 . V_35 >> V_40 ) ;
if ( V_63 >= V_60 && V_63 < V_60 + V_10 ) {
T_4 * V_64 = F_35 ( F_36 ( V_6 -> V_10 [ V_63 ] ) ) ;
V_64 [ V_6 -> V_26 . V_35 & ( V_65 - 1 ) ] = 0 ;
V_6 -> V_26 . V_27 &= ~ V_62 ;
}
}
V_61 . V_13 = V_6 -> V_13 + V_60 ;
V_61 . V_15 = V_32 ? V_6 -> V_15 + V_60 : NULL ;
V_61 . V_10 = V_6 -> V_10 + V_60 ;
V_61 . V_9 = V_10 ;
F_43 ( & V_61 ) ;
F_44 ( & V_36 . V_59 ) ;
if ( V_36 . V_55 )
return V_36 . V_55 ;
for ( V_17 = 0 ; V_17 < V_10 ; V_17 ++ ) {
if ( V_6 -> V_13 [ V_60 + V_17 ] . V_53 )
V_19 = - V_54 ;
F_3 ( L_6 ,
V_6 -> V_13 [ V_60 + V_17 ] . V_20 ,
V_6 -> V_13 [ V_60 + V_17 ] . V_53 ) ;
V_6 -> V_13 [ V_60 + V_17 ] . V_20 = - 1 ;
}
return V_19 ;
}
static int F_24 ( struct V_5 * V_6 , int V_60 , int V_10 )
{
int V_66 , V_19 = 0 ;
F_3 ( L_7 , V_6 -> V_8 , V_6 -> V_9 , V_60 , V_10 ) ;
while ( V_10 && ! V_19 ) {
while ( V_10 && V_6 -> V_13 [ V_60 ] . V_20 == - 1 ) {
V_60 ++ ;
V_10 -- ;
}
V_66 = 0 ;
while ( V_66 < V_10 ) {
if ( V_6 -> V_13 [ V_60 + V_66 ] . V_20 == - 1 ) {
V_66 -- ;
break;
}
V_66 ++ ;
}
V_19 = F_41 ( V_6 , V_60 , V_66 ) ;
V_60 += V_66 ;
V_10 -= V_66 ;
}
return V_19 ;
}
static void F_45 ( struct V_67 * V_38 )
{
struct V_5 * V_6 = V_38 -> V_68 ;
F_3 ( L_8 , V_38 ) ;
F_46 ( & V_6 -> V_21 ) ;
}
static void F_47 ( struct V_67 * V_38 )
{
struct V_5 * V_6 = V_38 -> V_68 ;
struct V_69 * V_69 = V_38 -> V_70 ;
struct V_1 * V_2 = V_69 -> V_71 ;
F_3 ( L_9 , V_38 ) ;
if ( V_32 ) {
F_21 ( & V_2 -> V_31 ) ;
V_6 -> V_38 = NULL ;
F_23 ( & V_2 -> V_31 ) ;
}
V_38 -> V_68 = NULL ;
F_16 ( V_2 , V_6 ) ;
}
static struct V_72 * F_48 ( struct V_67 * V_38 ,
unsigned long V_35 )
{
struct V_5 * V_6 = V_38 -> V_68 ;
return V_6 -> V_10 [ ( V_35 - V_6 -> V_73 ) >> V_40 ] ;
}
static void F_49 ( struct V_5 * V_6 ,
unsigned long V_74 , unsigned long V_75 )
{
unsigned long V_76 , V_77 ;
int V_19 ;
if ( ! V_6 -> V_38 )
return;
if ( V_6 -> V_38 -> V_39 >= V_75 )
return;
if ( V_6 -> V_38 -> V_78 <= V_74 )
return;
V_76 = F_50 ( V_74 , V_6 -> V_38 -> V_39 ) ;
V_77 = F_51 ( V_75 , V_6 -> V_38 -> V_78 ) ;
F_3 ( L_10 ,
V_6 -> V_8 , V_6 -> V_9 ,
V_6 -> V_38 -> V_39 , V_6 -> V_38 -> V_78 ,
V_74 , V_75 , V_76 , V_77 ) ;
V_19 = F_24 ( V_6 ,
( V_76 - V_6 -> V_38 -> V_39 ) >> V_40 ,
( V_77 - V_76 ) >> V_40 ) ;
F_52 ( V_19 ) ;
}
static void F_53 ( struct V_79 * V_80 ,
struct V_81 * V_50 ,
unsigned long V_74 , unsigned long V_75 )
{
struct V_1 * V_2 = F_54 ( V_80 , struct V_1 , V_80 ) ;
struct V_5 * V_6 ;
F_21 ( & V_2 -> V_31 ) ;
F_4 (map, &priv->maps, next) {
F_49 ( V_6 , V_74 , V_75 ) ;
}
F_4 (map, &priv->freeable_maps, next) {
F_49 ( V_6 , V_74 , V_75 ) ;
}
F_23 ( & V_2 -> V_31 ) ;
}
static void F_55 ( struct V_79 * V_80 ,
struct V_81 * V_50 ,
unsigned long V_51 )
{
F_53 ( V_80 , V_50 , V_51 , V_51 + V_65 ) ;
}
static void F_56 ( struct V_79 * V_80 ,
struct V_81 * V_50 )
{
struct V_1 * V_2 = F_54 ( V_80 , struct V_1 , V_80 ) ;
struct V_5 * V_6 ;
int V_19 ;
F_21 ( & V_2 -> V_31 ) ;
F_4 (map, &priv->maps, next) {
if ( ! V_6 -> V_38 )
continue;
F_3 ( L_11 ,
V_6 -> V_8 , V_6 -> V_9 ,
V_6 -> V_38 -> V_39 , V_6 -> V_38 -> V_78 ) ;
V_19 = F_24 ( V_6 , 0 , V_6 -> V_9 ) ;
F_52 ( V_19 ) ;
}
F_4 (map, &priv->freeable_maps, next) {
if ( ! V_6 -> V_38 )
continue;
F_3 ( L_11 ,
V_6 -> V_8 , V_6 -> V_9 ,
V_6 -> V_38 -> V_39 , V_6 -> V_38 -> V_78 ) ;
V_19 = F_24 ( V_6 , 0 , V_6 -> V_9 ) ;
F_52 ( V_19 ) ;
}
F_23 ( & V_2 -> V_31 ) ;
}
static int F_57 ( struct V_82 * V_82 , struct V_69 * V_83 )
{
struct V_1 * V_2 ;
int V_84 = 0 ;
V_2 = F_9 ( sizeof( * V_2 ) , V_18 ) ;
if ( ! V_2 )
return - V_85 ;
F_58 ( & V_2 -> V_24 ) ;
F_58 ( & V_2 -> V_86 ) ;
F_59 ( & V_2 -> V_31 ) ;
if ( V_32 ) {
V_2 -> V_50 = F_60 ( V_49 ) ;
if ( ! V_2 -> V_50 ) {
F_7 ( V_2 ) ;
return - V_85 ;
}
V_2 -> V_80 . V_87 = & V_88 ;
V_84 = F_61 ( & V_2 -> V_80 , V_2 -> V_50 ) ;
F_62 ( V_2 -> V_50 ) ;
}
if ( V_84 ) {
F_7 ( V_2 ) ;
return V_84 ;
}
V_83 -> V_71 = V_2 ;
F_3 ( L_12 , V_2 ) ;
return 0 ;
}
static int F_63 ( struct V_82 * V_82 , struct V_69 * V_83 )
{
struct V_1 * V_2 = V_83 -> V_71 ;
struct V_5 * V_6 ;
F_3 ( L_12 , V_2 ) ;
while ( ! F_64 ( & V_2 -> V_24 ) ) {
V_6 = F_65 ( V_2 -> V_24 . V_22 , struct V_5 , V_22 ) ;
F_22 ( & V_6 -> V_22 ) ;
F_16 ( NULL , V_6 ) ;
}
F_52 ( ! F_64 ( & V_2 -> V_86 ) ) ;
if ( V_32 )
F_66 ( & V_2 -> V_80 , V_2 -> V_50 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static long F_67 ( struct V_1 * V_2 ,
struct V_89 T_5 * V_90 )
{
struct V_89 V_91 ;
struct V_5 * V_6 ;
int V_19 ;
if ( F_68 ( & V_91 , V_90 , sizeof( V_91 ) ) != 0 )
return - V_92 ;
F_3 ( L_13 , V_2 , V_91 . V_9 ) ;
if ( F_69 ( V_91 . V_9 <= 0 ) )
return - V_54 ;
V_19 = - V_85 ;
V_6 = F_8 ( V_2 , V_91 . V_9 ) ;
if ( ! V_6 )
return V_19 ;
if ( F_69 ( F_70 ( V_91 . V_9 , & V_25 ) > V_93 ) ) {
F_3 ( L_14 ) ;
F_16 ( NULL , V_6 ) ;
return V_19 ;
}
if ( F_68 ( V_6 -> V_11 , & V_90 -> V_94 ,
sizeof( V_6 -> V_11 [ 0 ] ) * V_91 . V_9 ) != 0 ) {
F_16 ( NULL , V_6 ) ;
return - V_92 ;
}
F_21 ( & V_2 -> V_31 ) ;
F_13 ( V_2 , V_6 ) ;
V_91 . V_8 = V_6 -> V_8 << V_40 ;
F_23 ( & V_2 -> V_31 ) ;
if ( F_71 ( V_90 , & V_91 , sizeof( V_91 ) ) != 0 )
return - V_92 ;
return 0 ;
}
static long F_72 ( struct V_1 * V_2 ,
struct V_95 T_5 * V_90 )
{
struct V_95 V_91 ;
struct V_5 * V_6 ;
int V_19 = - V_96 ;
if ( F_68 ( & V_91 , V_90 , sizeof( V_91 ) ) != 0 )
return - V_92 ;
F_3 ( L_15 , V_2 , ( int ) V_91 . V_8 , ( int ) V_91 . V_9 ) ;
F_21 ( & V_2 -> V_31 ) ;
V_6 = F_15 ( V_2 , V_91 . V_8 >> V_40 , V_91 . V_9 ) ;
if ( V_6 ) {
F_22 ( & V_6 -> V_22 ) ;
if ( V_30 )
F_14 ( & V_6 -> V_22 , & V_2 -> V_86 ) ;
V_19 = 0 ;
}
F_23 ( & V_2 -> V_31 ) ;
if ( V_6 )
F_16 ( V_2 , V_6 ) ;
return V_19 ;
}
static long F_73 ( struct V_1 * V_2 ,
struct V_97 T_5 * V_90 )
{
struct V_97 V_91 ;
struct V_67 * V_38 ;
struct V_5 * V_6 ;
int V_98 = - V_54 ;
if ( F_68 ( & V_91 , V_90 , sizeof( V_91 ) ) != 0 )
return - V_92 ;
F_3 ( L_16 , V_2 , ( unsigned long ) V_91 . V_99 ) ;
F_74 ( & V_49 -> V_50 -> V_100 ) ;
V_38 = F_75 ( V_49 -> V_50 , V_91 . V_99 ) ;
if ( ! V_38 || V_38 -> V_101 != & V_102 )
goto V_103;
V_6 = V_38 -> V_68 ;
if ( ! V_6 )
goto V_103;
V_91 . V_60 = V_6 -> V_8 << V_40 ;
V_91 . V_9 = V_6 -> V_9 ;
V_98 = 0 ;
V_103:
F_76 ( & V_49 -> V_50 -> V_100 ) ;
if ( V_98 == 0 && F_71 ( V_90 , & V_91 , sizeof( V_91 ) ) != 0 )
return - V_92 ;
return V_98 ;
}
static long F_77 ( struct V_1 * V_2 , void T_5 * V_90 )
{
struct V_104 V_91 ;
struct V_5 * V_6 ;
int V_105 ;
int V_106 ;
unsigned int V_107 ;
if ( F_68 ( & V_91 , V_90 , sizeof( V_91 ) ) )
return - V_92 ;
if ( V_91 . V_108 & ~ ( V_62 | V_28 ) )
return - V_54 ;
if ( V_91 . V_108 & V_28 ) {
if ( F_78 ( V_91 . V_109 ) )
return - V_54 ;
}
V_106 = V_91 . V_108 ;
V_107 = V_91 . V_109 ;
F_21 ( & V_2 -> V_31 ) ;
F_4 (map, &priv->maps, next) {
T_6 V_110 = V_6 -> V_8 << V_40 ;
T_6 V_75 = ( V_6 -> V_8 + V_6 -> V_9 ) << V_40 ;
if ( V_91 . V_8 >= V_110 && V_91 . V_8 < V_75 )
goto V_111;
}
V_105 = - V_96 ;
goto V_112;
V_111:
if ( ( V_91 . V_108 & V_62 ) &&
( V_6 -> V_27 & V_113 ) ) {
V_105 = - V_54 ;
goto V_112;
}
V_106 = V_6 -> V_26 . V_27 ;
V_107 = V_6 -> V_26 . V_29 ;
V_6 -> V_26 . V_27 = V_91 . V_108 ;
V_6 -> V_26 . V_35 = V_91 . V_8 - ( V_6 -> V_8 << V_40 ) ;
V_6 -> V_26 . V_29 = V_91 . V_109 ;
V_105 = 0 ;
V_112:
F_23 ( & V_2 -> V_31 ) ;
if ( V_106 & V_28 )
F_20 ( V_107 ) ;
return V_105 ;
}
static long F_79 ( struct V_69 * V_83 ,
unsigned int V_114 , unsigned long V_115 )
{
struct V_1 * V_2 = V_83 -> V_71 ;
void T_5 * V_116 = ( void T_5 * ) V_115 ;
switch ( V_114 ) {
case V_117 :
return F_67 ( V_2 , V_116 ) ;
case V_118 :
return F_72 ( V_2 , V_116 ) ;
case V_119 :
return F_73 ( V_2 , V_116 ) ;
case V_120 :
return F_77 ( V_2 , V_116 ) ;
default:
F_3 ( L_17 , V_2 , V_114 ) ;
return - V_121 ;
}
return 0 ;
}
static int F_80 ( struct V_69 * V_83 , struct V_67 * V_38 )
{
struct V_1 * V_2 = V_83 -> V_71 ;
int V_8 = V_38 -> V_122 ;
int V_9 = ( V_38 -> V_78 - V_38 -> V_39 ) >> V_40 ;
struct V_5 * V_6 ;
int V_17 , V_19 = - V_54 ;
if ( ( V_38 -> V_123 & V_124 ) && ! ( V_38 -> V_123 & V_125 ) )
return - V_54 ;
F_3 ( L_18 ,
V_8 , V_9 , V_38 -> V_39 , V_38 -> V_122 ) ;
F_21 ( & V_2 -> V_31 ) ;
V_6 = F_15 ( V_2 , V_8 , V_9 ) ;
if ( ! V_6 )
goto V_112;
if ( V_32 && V_6 -> V_38 )
goto V_112;
if ( V_32 && V_2 -> V_50 != V_38 -> V_126 ) {
F_81 ( L_19 ) ;
goto V_112;
}
F_46 ( & V_6 -> V_21 ) ;
V_38 -> V_101 = & V_102 ;
V_38 -> V_123 |= V_127 | V_128 ;
if ( V_32 )
V_38 -> V_123 |= V_129 ;
V_38 -> V_68 = V_6 ;
if ( V_32 )
V_6 -> V_38 = V_38 ;
if ( V_6 -> V_27 ) {
if ( ( V_38 -> V_123 & V_124 ) &&
( V_6 -> V_27 & V_113 ) )
goto V_130;
} else {
V_6 -> V_27 = V_52 ;
if ( ! ( V_38 -> V_123 & V_124 ) )
V_6 -> V_27 |= V_113 ;
}
F_23 ( & V_2 -> V_31 ) ;
if ( V_32 ) {
V_19 = F_82 ( V_38 -> V_126 , V_38 -> V_39 ,
V_38 -> V_78 - V_38 -> V_39 ,
F_25 , V_6 ) ;
if ( V_19 ) {
F_81 ( L_20 ) ;
goto V_131;
}
}
V_19 = F_34 ( V_6 ) ;
if ( V_19 )
goto V_131;
if ( ! V_32 ) {
for ( V_17 = 0 ; V_17 < V_9 ; V_17 ++ ) {
V_19 = F_83 ( V_38 , V_38 -> V_39 + V_17 * V_65 ,
V_6 -> V_10 [ V_17 ] ) ;
if ( V_19 )
goto V_131;
}
} else {
#ifdef F_84
if ( ! F_28 ( V_45 ) ) {
F_82 ( V_38 -> V_126 , V_38 -> V_39 ,
V_38 -> V_78 - V_38 -> V_39 ,
F_31 , NULL ) ;
}
#endif
V_6 -> V_73 = V_38 -> V_39 ;
}
return 0 ;
V_112:
F_23 ( & V_2 -> V_31 ) ;
return V_19 ;
V_130:
F_23 ( & V_2 -> V_31 ) ;
V_131:
if ( V_32 )
V_6 -> V_38 = NULL ;
F_16 ( V_2 , V_6 ) ;
return V_19 ;
}
static int T_7 F_85 ( void )
{
int V_19 ;
if ( ! F_86 () )
return - V_132 ;
V_32 = ! F_28 ( V_133 ) ;
V_19 = F_87 ( & V_134 ) ;
if ( V_19 != 0 ) {
F_88 ( L_21 ) ;
return V_19 ;
}
return 0 ;
}
static void T_8 F_89 ( void )
{
F_90 ( & V_134 ) ;
}
