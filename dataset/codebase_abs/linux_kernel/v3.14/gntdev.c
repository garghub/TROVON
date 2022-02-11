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
unsigned long V_46 = ( unsigned long )
F_31 ( F_32 ( V_6 -> V_10 [ V_16 ] ) ) ;
F_26 ( F_33 ( V_6 -> V_10 [ V_16 ] ) ) ;
F_28 ( & V_6 -> V_14 [ V_16 ] , V_46 ,
V_6 -> V_26 | V_47 ,
V_6 -> V_11 [ V_16 ] . V_44 ,
V_6 -> V_11 [ V_16 ] . V_45 ) ;
}
}
F_3 ( L_5 , V_6 -> V_8 , V_6 -> V_9 ) ;
V_18 = F_34 ( V_6 -> V_12 , V_31 ? V_6 -> V_14 : NULL ,
V_6 -> V_10 , V_6 -> V_9 ) ;
if ( V_18 )
return V_18 ;
for ( V_16 = 0 ; V_16 < V_6 -> V_9 ; V_16 ++ ) {
if ( V_6 -> V_12 [ V_16 ] . V_48 )
V_18 = - V_49 ;
else {
F_26 ( V_6 -> V_12 [ V_16 ] . V_19 == - 1 ) ;
V_6 -> V_13 [ V_16 ] . V_19 = V_6 -> V_12 [ V_16 ] . V_19 ;
F_3 ( L_6 , V_6 -> V_12 [ V_16 ] . V_19 ) ;
}
}
return V_18 ;
}
static int F_35 ( struct V_5 * V_6 , int V_50 , int V_10 )
{
int V_16 , V_18 = 0 ;
if ( V_6 -> V_25 . V_26 & V_51 ) {
int V_52 = ( V_6 -> V_25 . V_34 >> V_39 ) ;
if ( V_52 >= V_50 && V_52 < V_50 + V_10 ) {
T_4 * V_53 = F_31 ( F_32 ( V_6 -> V_10 [ V_52 ] ) ) ;
V_53 [ V_6 -> V_25 . V_34 & ( V_54 - 1 ) ] = 0 ;
V_6 -> V_25 . V_26 &= ~ V_51 ;
}
}
V_18 = F_36 ( V_6 -> V_13 + V_50 ,
V_31 ? V_6 -> V_14 + V_50 : NULL , V_6 -> V_10 + V_50 ,
V_10 ) ;
if ( V_18 )
return V_18 ;
for ( V_16 = 0 ; V_16 < V_10 ; V_16 ++ ) {
if ( V_6 -> V_13 [ V_50 + V_16 ] . V_48 )
V_18 = - V_49 ;
F_3 ( L_7 ,
V_6 -> V_13 [ V_50 + V_16 ] . V_19 ,
V_6 -> V_13 [ V_50 + V_16 ] . V_48 ) ;
V_6 -> V_13 [ V_50 + V_16 ] . V_19 = - 1 ;
}
return V_18 ;
}
static int F_24 ( struct V_5 * V_6 , int V_50 , int V_10 )
{
int V_55 , V_18 = 0 ;
F_3 ( L_8 , V_6 -> V_8 , V_6 -> V_9 , V_50 , V_10 ) ;
while ( V_10 && ! V_18 ) {
while ( V_10 && V_6 -> V_13 [ V_50 ] . V_19 == - 1 ) {
V_50 ++ ;
V_10 -- ;
}
V_55 = 0 ;
while ( V_55 < V_10 ) {
if ( V_6 -> V_13 [ V_50 + V_55 ] . V_19 == - 1 ) {
V_55 -- ;
break;
}
V_55 ++ ;
}
V_18 = F_35 ( V_6 , V_50 , V_55 ) ;
V_50 += V_55 ;
V_10 -= V_55 ;
}
return V_18 ;
}
static void F_37 ( struct V_56 * V_37 )
{
struct V_5 * V_6 = V_37 -> V_57 ;
F_3 ( L_9 , V_37 ) ;
F_38 ( & V_6 -> V_20 ) ;
}
static void F_39 ( struct V_56 * V_37 )
{
struct V_5 * V_6 = V_37 -> V_57 ;
struct V_58 * V_58 = V_37 -> V_59 ;
struct V_1 * V_2 = V_58 -> V_60 ;
F_3 ( L_10 , V_37 ) ;
if ( V_31 ) {
F_21 ( & V_2 -> V_30 ) ;
V_6 -> V_37 = NULL ;
F_23 ( & V_2 -> V_30 ) ;
}
V_37 -> V_57 = NULL ;
F_16 ( V_2 , V_6 ) ;
}
static void F_40 ( struct V_5 * V_6 ,
unsigned long V_61 , unsigned long V_62 )
{
unsigned long V_63 , V_64 ;
int V_18 ;
if ( ! V_6 -> V_37 )
return;
if ( V_6 -> V_37 -> V_38 >= V_62 )
return;
if ( V_6 -> V_37 -> V_65 <= V_61 )
return;
V_63 = F_41 ( V_61 , V_6 -> V_37 -> V_38 ) ;
V_64 = F_42 ( V_62 , V_6 -> V_37 -> V_65 ) ;
F_3 ( L_11 ,
V_6 -> V_8 , V_6 -> V_9 ,
V_6 -> V_37 -> V_38 , V_6 -> V_37 -> V_65 ,
V_61 , V_62 , V_63 , V_64 ) ;
V_18 = F_24 ( V_6 ,
( V_63 - V_6 -> V_37 -> V_38 ) >> V_39 ,
( V_64 - V_63 ) >> V_39 ) ;
F_43 ( V_18 ) ;
}
static void F_44 ( struct V_66 * V_67 ,
struct V_68 * V_69 ,
unsigned long V_61 , unsigned long V_62 )
{
struct V_1 * V_2 = F_45 ( V_67 , struct V_1 , V_67 ) ;
struct V_5 * V_6 ;
F_21 ( & V_2 -> V_30 ) ;
F_4 (map, &priv->maps, next) {
F_40 ( V_6 , V_61 , V_62 ) ;
}
F_4 (map, &priv->freeable_maps, next) {
F_40 ( V_6 , V_61 , V_62 ) ;
}
F_23 ( & V_2 -> V_30 ) ;
}
static void F_46 ( struct V_66 * V_67 ,
struct V_68 * V_69 ,
unsigned long V_46 )
{
F_44 ( V_67 , V_69 , V_46 , V_46 + V_54 ) ;
}
static void F_47 ( struct V_66 * V_67 ,
struct V_68 * V_69 )
{
struct V_1 * V_2 = F_45 ( V_67 , struct V_1 , V_67 ) ;
struct V_5 * V_6 ;
int V_18 ;
F_21 ( & V_2 -> V_30 ) ;
F_4 (map, &priv->maps, next) {
if ( ! V_6 -> V_37 )
continue;
F_3 ( L_12 ,
V_6 -> V_8 , V_6 -> V_9 ,
V_6 -> V_37 -> V_38 , V_6 -> V_37 -> V_65 ) ;
V_18 = F_24 ( V_6 , 0 , V_6 -> V_9 ) ;
F_43 ( V_18 ) ;
}
F_4 (map, &priv->freeable_maps, next) {
if ( ! V_6 -> V_37 )
continue;
F_3 ( L_12 ,
V_6 -> V_8 , V_6 -> V_9 ,
V_6 -> V_37 -> V_38 , V_6 -> V_37 -> V_65 ) ;
V_18 = F_24 ( V_6 , 0 , V_6 -> V_9 ) ;
F_43 ( V_18 ) ;
}
F_23 ( & V_2 -> V_30 ) ;
}
static int F_48 ( struct V_70 * V_70 , struct V_58 * V_71 )
{
struct V_1 * V_2 ;
int V_72 = 0 ;
V_2 = F_9 ( sizeof( * V_2 ) , V_17 ) ;
if ( ! V_2 )
return - V_73 ;
F_49 ( & V_2 -> V_23 ) ;
F_49 ( & V_2 -> V_74 ) ;
F_50 ( & V_2 -> V_30 ) ;
if ( V_31 ) {
V_2 -> V_69 = F_51 ( V_75 ) ;
if ( ! V_2 -> V_69 ) {
F_7 ( V_2 ) ;
return - V_73 ;
}
V_2 -> V_67 . V_76 = & V_77 ;
V_72 = F_52 ( & V_2 -> V_67 , V_2 -> V_69 ) ;
F_53 ( V_2 -> V_69 ) ;
}
if ( V_72 ) {
F_7 ( V_2 ) ;
return V_72 ;
}
V_71 -> V_60 = V_2 ;
F_3 ( L_13 , V_2 ) ;
return 0 ;
}
static int F_54 ( struct V_70 * V_70 , struct V_58 * V_71 )
{
struct V_1 * V_2 = V_71 -> V_60 ;
struct V_5 * V_6 ;
F_3 ( L_13 , V_2 ) ;
while ( ! F_55 ( & V_2 -> V_23 ) ) {
V_6 = F_56 ( V_2 -> V_23 . V_21 , struct V_5 , V_21 ) ;
F_22 ( & V_6 -> V_21 ) ;
F_16 ( NULL , V_6 ) ;
}
F_43 ( ! F_55 ( & V_2 -> V_74 ) ) ;
if ( V_31 )
F_57 ( & V_2 -> V_67 , V_2 -> V_69 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static long F_58 ( struct V_1 * V_2 ,
struct V_78 T_5 * V_79 )
{
struct V_78 V_80 ;
struct V_5 * V_6 ;
int V_18 ;
if ( F_59 ( & V_80 , V_79 , sizeof( V_80 ) ) != 0 )
return - V_81 ;
F_3 ( L_14 , V_2 , V_80 . V_9 ) ;
if ( F_60 ( V_80 . V_9 <= 0 ) )
return - V_49 ;
V_18 = - V_73 ;
V_6 = F_8 ( V_2 , V_80 . V_9 ) ;
if ( ! V_6 )
return V_18 ;
if ( F_60 ( F_61 ( V_80 . V_9 , & V_24 ) > V_82 ) ) {
F_3 ( L_15 ) ;
F_16 ( NULL , V_6 ) ;
return V_18 ;
}
if ( F_59 ( V_6 -> V_11 , & V_79 -> V_83 ,
sizeof( V_6 -> V_11 [ 0 ] ) * V_80 . V_9 ) != 0 ) {
F_16 ( NULL , V_6 ) ;
return - V_81 ;
}
F_21 ( & V_2 -> V_30 ) ;
F_13 ( V_2 , V_6 ) ;
V_80 . V_8 = V_6 -> V_8 << V_39 ;
F_23 ( & V_2 -> V_30 ) ;
if ( F_62 ( V_79 , & V_80 , sizeof( V_80 ) ) != 0 )
return - V_81 ;
return 0 ;
}
static long F_63 ( struct V_1 * V_2 ,
struct V_84 T_5 * V_79 )
{
struct V_84 V_80 ;
struct V_5 * V_6 ;
int V_18 = - V_85 ;
if ( F_59 ( & V_80 , V_79 , sizeof( V_80 ) ) != 0 )
return - V_81 ;
F_3 ( L_16 , V_2 , ( int ) V_80 . V_8 , ( int ) V_80 . V_9 ) ;
F_21 ( & V_2 -> V_30 ) ;
V_6 = F_15 ( V_2 , V_80 . V_8 >> V_39 , V_80 . V_9 ) ;
if ( V_6 ) {
F_22 ( & V_6 -> V_21 ) ;
if ( V_29 )
F_14 ( & V_6 -> V_21 , & V_2 -> V_74 ) ;
V_18 = 0 ;
}
F_23 ( & V_2 -> V_30 ) ;
if ( V_6 )
F_16 ( V_2 , V_6 ) ;
return V_18 ;
}
static long F_64 ( struct V_1 * V_2 ,
struct V_86 T_5 * V_79 )
{
struct V_86 V_80 ;
struct V_56 * V_37 ;
struct V_5 * V_6 ;
int V_87 = - V_49 ;
if ( F_59 ( & V_80 , V_79 , sizeof( V_80 ) ) != 0 )
return - V_81 ;
F_3 ( L_17 , V_2 , ( unsigned long ) V_80 . V_88 ) ;
F_65 ( & V_75 -> V_69 -> V_89 ) ;
V_37 = F_66 ( V_75 -> V_69 , V_80 . V_88 ) ;
if ( ! V_37 || V_37 -> V_90 != & V_91 )
goto V_92;
V_6 = V_37 -> V_57 ;
if ( ! V_6 )
goto V_92;
V_80 . V_50 = V_6 -> V_8 << V_39 ;
V_80 . V_9 = V_6 -> V_9 ;
V_87 = 0 ;
V_92:
F_67 ( & V_75 -> V_69 -> V_89 ) ;
if ( V_87 == 0 && F_62 ( V_79 , & V_80 , sizeof( V_80 ) ) != 0 )
return - V_81 ;
return V_87 ;
}
static long F_68 ( struct V_1 * V_2 , void T_5 * V_79 )
{
struct V_93 V_80 ;
struct V_5 * V_6 ;
int V_94 ;
int V_95 ;
unsigned int V_96 ;
if ( F_59 ( & V_80 , V_79 , sizeof( V_80 ) ) )
return - V_81 ;
if ( V_80 . V_97 & ~ ( V_51 | V_27 ) )
return - V_49 ;
if ( V_80 . V_97 & V_27 ) {
if ( F_69 ( V_80 . V_98 ) )
return - V_49 ;
}
V_95 = V_80 . V_97 ;
V_96 = V_80 . V_98 ;
F_21 ( & V_2 -> V_30 ) ;
F_4 (map, &priv->maps, next) {
T_6 V_99 = V_6 -> V_8 << V_39 ;
T_6 V_62 = ( V_6 -> V_8 + V_6 -> V_9 ) << V_39 ;
if ( V_80 . V_8 >= V_99 && V_80 . V_8 < V_62 )
goto V_100;
}
V_94 = - V_85 ;
goto V_101;
V_100:
if ( ( V_80 . V_97 & V_51 ) &&
( V_6 -> V_26 & V_102 ) ) {
V_94 = - V_49 ;
goto V_101;
}
V_95 = V_6 -> V_25 . V_26 ;
V_96 = V_6 -> V_25 . V_28 ;
V_6 -> V_25 . V_26 = V_80 . V_97 ;
V_6 -> V_25 . V_34 = V_80 . V_8 - ( V_6 -> V_8 << V_39 ) ;
V_6 -> V_25 . V_28 = V_80 . V_98 ;
V_94 = 0 ;
V_101:
F_23 ( & V_2 -> V_30 ) ;
if ( V_95 & V_27 )
F_20 ( V_96 ) ;
return V_94 ;
}
static long F_70 ( struct V_58 * V_71 ,
unsigned int V_103 , unsigned long V_104 )
{
struct V_1 * V_2 = V_71 -> V_60 ;
void T_5 * V_105 = ( void T_5 * ) V_104 ;
switch ( V_103 ) {
case V_106 :
return F_58 ( V_2 , V_105 ) ;
case V_107 :
return F_63 ( V_2 , V_105 ) ;
case V_108 :
return F_64 ( V_2 , V_105 ) ;
case V_109 :
return F_68 ( V_2 , V_105 ) ;
default:
F_3 ( L_18 , V_2 , V_103 ) ;
return - V_110 ;
}
return 0 ;
}
static int F_71 ( struct V_58 * V_71 , struct V_56 * V_37 )
{
struct V_1 * V_2 = V_71 -> V_60 ;
int V_8 = V_37 -> V_111 ;
int V_9 = ( V_37 -> V_65 - V_37 -> V_38 ) >> V_39 ;
struct V_5 * V_6 ;
int V_16 , V_18 = - V_49 ;
if ( ( V_37 -> V_112 & V_113 ) && ! ( V_37 -> V_112 & V_114 ) )
return - V_49 ;
F_3 ( L_19 ,
V_8 , V_9 , V_37 -> V_38 , V_37 -> V_111 ) ;
F_21 ( & V_2 -> V_30 ) ;
V_6 = F_15 ( V_2 , V_8 , V_9 ) ;
if ( ! V_6 )
goto V_101;
if ( V_31 && V_6 -> V_37 )
goto V_101;
if ( V_31 && V_2 -> V_69 != V_37 -> V_115 ) {
F_72 ( L_20 ) ;
goto V_101;
}
F_38 ( & V_6 -> V_20 ) ;
V_37 -> V_90 = & V_91 ;
V_37 -> V_112 |= V_116 | V_117 ;
if ( V_31 )
V_37 -> V_112 |= V_118 ;
V_37 -> V_57 = V_6 ;
if ( V_31 )
V_6 -> V_37 = V_37 ;
if ( V_6 -> V_26 ) {
if ( ( V_37 -> V_112 & V_113 ) &&
( V_6 -> V_26 & V_102 ) )
goto V_119;
} else {
V_6 -> V_26 = V_47 ;
if ( ! ( V_37 -> V_112 & V_113 ) )
V_6 -> V_26 |= V_102 ;
}
F_23 ( & V_2 -> V_30 ) ;
if ( V_31 ) {
V_18 = F_73 ( V_37 -> V_115 , V_37 -> V_38 ,
V_37 -> V_65 - V_37 -> V_38 ,
F_25 , V_6 ) ;
if ( V_18 ) {
F_72 ( L_21 ) ;
goto V_120;
}
}
V_18 = F_30 ( V_6 ) ;
if ( V_18 )
goto V_120;
if ( ! V_31 ) {
for ( V_16 = 0 ; V_16 < V_9 ; V_16 ++ ) {
V_18 = F_74 ( V_37 , V_37 -> V_38 + V_16 * V_54 ,
V_6 -> V_10 [ V_16 ] ) ;
if ( V_18 )
goto V_120;
}
}
return 0 ;
V_101:
F_23 ( & V_2 -> V_30 ) ;
return V_18 ;
V_119:
F_23 ( & V_2 -> V_30 ) ;
V_120:
if ( V_31 )
V_6 -> V_37 = NULL ;
F_16 ( V_2 , V_6 ) ;
return V_18 ;
}
static int T_7 F_75 ( void )
{
int V_18 ;
if ( ! F_76 () )
return - V_121 ;
V_31 = ! F_77 ( V_122 ) ;
V_18 = F_78 ( & V_123 ) ;
if ( V_18 != 0 ) {
F_79 ( L_22 ) ;
return V_18 ;
}
return 0 ;
}
static void T_8 F_80 ( void )
{
F_81 ( & V_123 ) ;
}
