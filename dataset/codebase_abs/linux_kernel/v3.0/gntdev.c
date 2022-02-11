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
static struct V_5 * F_5 ( struct V_1 * V_2 , int V_9 )
{
struct V_5 * V_10 ;
int V_11 ;
V_10 = F_6 ( sizeof( struct V_5 ) , V_12 ) ;
if ( NULL == V_10 )
return NULL ;
V_10 -> V_13 = F_6 ( sizeof( V_10 -> V_13 [ 0 ] ) * V_9 , V_12 ) ;
V_10 -> V_14 = F_6 ( sizeof( V_10 -> V_14 [ 0 ] ) * V_9 , V_12 ) ;
V_10 -> V_15 = F_6 ( sizeof( V_10 -> V_15 [ 0 ] ) * V_9 , V_12 ) ;
V_10 -> V_16 = F_6 ( sizeof( V_10 -> V_16 [ 0 ] ) * V_9 , V_12 ) ;
if ( NULL == V_10 -> V_13 ||
NULL == V_10 -> V_14 ||
NULL == V_10 -> V_15 ||
NULL == V_10 -> V_16 )
goto V_17;
if ( F_7 ( V_9 , V_10 -> V_16 ) )
goto V_17;
for ( V_11 = 0 ; V_11 < V_9 ; V_11 ++ ) {
V_10 -> V_14 [ V_11 ] . V_18 = - 1 ;
V_10 -> V_15 [ V_11 ] . V_18 = - 1 ;
}
V_10 -> V_8 = 0 ;
V_10 -> V_9 = V_9 ;
F_8 ( & V_10 -> V_19 , 1 ) ;
return V_10 ;
V_17:
F_9 ( V_10 -> V_16 ) ;
F_9 ( V_10 -> V_13 ) ;
F_9 ( V_10 -> V_14 ) ;
F_9 ( V_10 -> V_15 ) ;
F_9 ( V_10 ) ;
return NULL ;
}
static void F_10 ( struct V_1 * V_2 , struct V_5 * V_10 )
{
struct V_5 * V_6 ;
F_4 (map, &priv->maps, next) {
if ( V_10 -> V_8 + V_10 -> V_9 < V_6 -> V_8 ) {
F_11 ( & V_10 -> V_20 , & V_6 -> V_20 ) ;
goto V_21;
}
V_10 -> V_8 = V_6 -> V_8 + V_6 -> V_9 ;
}
F_11 ( & V_10 -> V_20 , & V_2 -> V_22 ) ;
V_21:
F_1 ( V_2 , L_4 , V_10 -> V_8 ) ;
}
static struct V_5 * F_12 ( struct V_1 * V_2 ,
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
static void F_13 ( struct V_5 * V_6 )
{
if ( ! V_6 )
return;
if ( ! F_14 ( & V_6 -> V_19 ) )
return;
F_15 ( V_6 -> V_9 , & V_23 ) ;
if ( V_6 -> V_24 . V_25 & V_26 ) {
F_16 ( V_6 -> V_24 . V_27 ) ;
}
if ( V_6 -> V_16 ) {
if ( ! V_28 )
F_17 ( V_6 , 0 , V_6 -> V_9 ) ;
F_18 ( V_6 -> V_9 , V_6 -> V_16 ) ;
}
F_9 ( V_6 -> V_16 ) ;
F_9 ( V_6 -> V_13 ) ;
F_9 ( V_6 -> V_14 ) ;
F_9 ( V_6 -> V_15 ) ;
F_9 ( V_6 ) ;
}
static int F_19 ( T_1 * V_29 , T_2 V_30 ,
unsigned long V_31 , void * V_32 )
{
struct V_5 * V_6 = V_32 ;
unsigned int V_33 = ( V_31 - V_6 -> V_34 -> V_35 ) >> V_36 ;
int V_25 = V_6 -> V_25 | V_37 | V_38 ;
T_3 V_39 ;
F_20 ( V_33 >= V_6 -> V_9 ) ;
V_39 = F_21 ( V_29 ) . V_40 ;
F_22 ( & V_6 -> V_14 [ V_33 ] , V_39 , V_25 ,
V_6 -> V_13 [ V_33 ] . V_41 ,
V_6 -> V_13 [ V_33 ] . V_42 ) ;
F_23 ( & V_6 -> V_15 [ V_33 ] , V_39 , V_25 ,
- 1 ) ;
return 0 ;
}
static int F_24 ( struct V_5 * V_6 )
{
int V_11 , V_17 = 0 ;
if ( ! V_28 ) {
if ( V_6 -> V_14 [ 0 ] . V_18 != - 1 )
return 0 ;
for ( V_11 = 0 ; V_11 < V_6 -> V_9 ; V_11 ++ ) {
unsigned long V_31 = ( unsigned long )
F_25 ( F_26 ( V_6 -> V_16 [ V_11 ] ) ) ;
F_22 ( & V_6 -> V_14 [ V_11 ] , V_31 , V_6 -> V_25 ,
V_6 -> V_13 [ V_11 ] . V_41 ,
V_6 -> V_13 [ V_11 ] . V_42 ) ;
F_23 ( & V_6 -> V_15 [ V_11 ] , V_31 ,
V_6 -> V_25 , - 1 ) ;
}
}
F_3 ( L_5 , V_6 -> V_8 , V_6 -> V_9 ) ;
V_17 = F_27 ( V_6 -> V_14 , V_6 -> V_16 , V_6 -> V_9 ) ;
if ( V_17 )
return V_17 ;
for ( V_11 = 0 ; V_11 < V_6 -> V_9 ; V_11 ++ ) {
if ( V_6 -> V_14 [ V_11 ] . V_43 )
V_17 = - V_44 ;
else {
F_20 ( V_6 -> V_14 [ V_11 ] . V_18 == - 1 ) ;
V_6 -> V_15 [ V_11 ] . V_18 = V_6 -> V_14 [ V_11 ] . V_18 ;
F_3 ( L_6 , V_6 -> V_14 [ V_11 ] . V_18 ) ;
}
}
return V_17 ;
}
static int F_28 ( struct V_5 * V_6 , int V_45 , int V_16 )
{
int V_11 , V_17 = 0 ;
if ( V_6 -> V_24 . V_25 & V_46 ) {
int V_47 = ( V_6 -> V_24 . V_31 >> V_36 ) ;
if ( V_47 >= V_45 && V_47 < V_45 + V_16 && V_28 ) {
void T_4 * V_48 = ( void T_4 * )
V_6 -> V_34 -> V_35 + V_6 -> V_24 . V_31 ;
V_17 = F_29 ( V_48 , & V_17 , 1 ) ;
if ( V_17 )
return - V_49 ;
V_6 -> V_24 . V_25 &= ~ V_46 ;
} else if ( V_47 >= V_45 && V_47 < V_45 + V_16 ) {
T_5 * V_48 = F_30 ( V_6 -> V_16 [ V_47 ] ) ;
V_48 [ V_6 -> V_24 . V_31 & ( V_50 - 1 ) ] = 0 ;
F_31 ( V_6 -> V_16 [ V_47 ] ) ;
V_6 -> V_24 . V_25 &= ~ V_46 ;
}
}
V_17 = F_32 ( V_6 -> V_15 + V_45 , V_6 -> V_16 + V_45 , V_16 ) ;
if ( V_17 )
return V_17 ;
for ( V_11 = 0 ; V_11 < V_16 ; V_11 ++ ) {
if ( V_6 -> V_15 [ V_45 + V_11 ] . V_43 )
V_17 = - V_44 ;
F_3 ( L_7 ,
V_6 -> V_15 [ V_45 + V_11 ] . V_18 ,
V_6 -> V_15 [ V_45 + V_11 ] . V_43 ) ;
V_6 -> V_15 [ V_45 + V_11 ] . V_18 = - 1 ;
}
return V_17 ;
}
static int F_17 ( struct V_5 * V_6 , int V_45 , int V_16 )
{
int V_51 , V_17 = 0 ;
F_3 ( L_8 , V_6 -> V_8 , V_6 -> V_9 , V_45 , V_16 ) ;
while ( V_16 && ! V_17 ) {
while ( V_16 && V_6 -> V_15 [ V_45 ] . V_18 == - 1 ) {
V_45 ++ ;
V_16 -- ;
}
V_51 = 0 ;
while ( V_51 < V_16 ) {
if ( V_6 -> V_15 [ V_45 + V_51 ] . V_18 == - 1 ) {
V_51 -- ;
break;
}
V_51 ++ ;
}
V_17 = F_28 ( V_6 , V_45 , V_51 ) ;
V_45 += V_51 ;
V_16 -= V_51 ;
}
return V_17 ;
}
static void F_33 ( struct V_52 * V_34 )
{
struct V_5 * V_6 = V_34 -> V_53 ;
F_3 ( L_9 , V_34 ) ;
F_34 ( & V_6 -> V_19 ) ;
}
static void F_35 ( struct V_52 * V_34 )
{
struct V_5 * V_6 = V_34 -> V_53 ;
F_3 ( L_10 , V_34 ) ;
V_6 -> V_34 = NULL ;
V_34 -> V_53 = NULL ;
F_13 ( V_6 ) ;
}
static void F_36 ( struct V_54 * V_55 ,
struct V_56 * V_57 ,
unsigned long V_58 , unsigned long V_59 )
{
struct V_1 * V_2 = F_37 ( V_55 , struct V_1 , V_55 ) ;
struct V_5 * V_6 ;
unsigned long V_60 , V_61 ;
int V_17 ;
F_38 ( & V_2 -> V_62 ) ;
F_4 (map, &priv->maps, next) {
if ( ! V_6 -> V_34 )
continue;
if ( V_6 -> V_34 -> V_35 >= V_59 )
continue;
if ( V_6 -> V_34 -> V_63 <= V_58 )
continue;
V_60 = F_39 ( V_58 , V_6 -> V_34 -> V_35 ) ;
V_61 = F_40 ( V_59 , V_6 -> V_34 -> V_63 ) ;
F_3 ( L_11 ,
V_6 -> V_8 , V_6 -> V_9 ,
V_6 -> V_34 -> V_35 , V_6 -> V_34 -> V_63 ,
V_58 , V_59 , V_60 , V_61 ) ;
V_17 = F_17 ( V_6 ,
( V_60 - V_6 -> V_34 -> V_35 ) >> V_36 ,
( V_61 - V_60 ) >> V_36 ) ;
F_41 ( V_17 ) ;
}
F_42 ( & V_2 -> V_62 ) ;
}
static void F_43 ( struct V_54 * V_55 ,
struct V_56 * V_57 ,
unsigned long V_64 )
{
F_36 ( V_55 , V_57 , V_64 , V_64 + V_50 ) ;
}
static void F_44 ( struct V_54 * V_55 ,
struct V_56 * V_57 )
{
struct V_1 * V_2 = F_37 ( V_55 , struct V_1 , V_55 ) ;
struct V_5 * V_6 ;
int V_17 ;
F_38 ( & V_2 -> V_62 ) ;
F_4 (map, &priv->maps, next) {
if ( ! V_6 -> V_34 )
continue;
F_3 ( L_12 ,
V_6 -> V_8 , V_6 -> V_9 ,
V_6 -> V_34 -> V_35 , V_6 -> V_34 -> V_63 ) ;
V_17 = F_17 ( V_6 , 0 , V_6 -> V_9 ) ;
F_41 ( V_17 ) ;
}
F_42 ( & V_2 -> V_62 ) ;
}
static int F_45 ( struct V_65 * V_65 , struct V_66 * V_67 )
{
struct V_1 * V_2 ;
int V_68 = 0 ;
V_2 = F_6 ( sizeof( * V_2 ) , V_12 ) ;
if ( ! V_2 )
return - V_69 ;
F_46 ( & V_2 -> V_22 ) ;
F_47 ( & V_2 -> V_62 ) ;
if ( V_28 ) {
V_2 -> V_57 = F_48 ( V_70 ) ;
if ( ! V_2 -> V_57 ) {
F_9 ( V_2 ) ;
return - V_69 ;
}
V_2 -> V_55 . V_71 = & V_72 ;
V_68 = F_49 ( & V_2 -> V_55 , V_2 -> V_57 ) ;
F_50 ( V_2 -> V_57 ) ;
}
if ( V_68 ) {
F_9 ( V_2 ) ;
return V_68 ;
}
V_67 -> V_73 = V_2 ;
F_3 ( L_13 , V_2 ) ;
return 0 ;
}
static int F_51 ( struct V_65 * V_65 , struct V_66 * V_67 )
{
struct V_1 * V_2 = V_67 -> V_73 ;
struct V_5 * V_6 ;
F_3 ( L_13 , V_2 ) ;
F_38 ( & V_2 -> V_62 ) ;
while ( ! F_52 ( & V_2 -> V_22 ) ) {
V_6 = F_53 ( V_2 -> V_22 . V_20 , struct V_5 , V_20 ) ;
F_54 ( & V_6 -> V_20 ) ;
F_13 ( V_6 ) ;
}
F_42 ( & V_2 -> V_62 ) ;
if ( V_28 )
F_55 ( & V_2 -> V_55 , V_2 -> V_57 ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static long F_56 ( struct V_1 * V_2 ,
struct V_74 T_4 * V_75 )
{
struct V_74 V_76 ;
struct V_5 * V_6 ;
int V_17 ;
if ( F_57 ( & V_76 , V_75 , sizeof( V_76 ) ) != 0 )
return - V_49 ;
F_3 ( L_14 , V_2 , V_76 . V_9 ) ;
if ( F_58 ( V_76 . V_9 <= 0 ) )
return - V_44 ;
V_17 = - V_69 ;
V_6 = F_5 ( V_2 , V_76 . V_9 ) ;
if ( ! V_6 )
return V_17 ;
if ( F_58 ( F_59 ( V_76 . V_9 , & V_23 ) > V_77 ) ) {
F_3 ( L_15 ) ;
F_13 ( V_6 ) ;
return V_17 ;
}
if ( F_57 ( V_6 -> V_13 , & V_75 -> V_78 ,
sizeof( V_6 -> V_13 [ 0 ] ) * V_76 . V_9 ) != 0 ) {
F_13 ( V_6 ) ;
return V_17 ;
}
F_38 ( & V_2 -> V_62 ) ;
F_10 ( V_2 , V_6 ) ;
V_76 . V_8 = V_6 -> V_8 << V_36 ;
F_42 ( & V_2 -> V_62 ) ;
if ( F_29 ( V_75 , & V_76 , sizeof( V_76 ) ) != 0 )
return - V_49 ;
return 0 ;
}
static long F_60 ( struct V_1 * V_2 ,
struct V_79 T_4 * V_75 )
{
struct V_79 V_76 ;
struct V_5 * V_6 ;
int V_17 = - V_80 ;
if ( F_57 ( & V_76 , V_75 , sizeof( V_76 ) ) != 0 )
return - V_49 ;
F_3 ( L_16 , V_2 , ( int ) V_76 . V_8 , ( int ) V_76 . V_9 ) ;
F_38 ( & V_2 -> V_62 ) ;
V_6 = F_12 ( V_2 , V_76 . V_8 >> V_36 , V_76 . V_9 ) ;
if ( V_6 ) {
F_54 ( & V_6 -> V_20 ) ;
F_13 ( V_6 ) ;
V_17 = 0 ;
}
F_42 ( & V_2 -> V_62 ) ;
return V_17 ;
}
static long F_61 ( struct V_1 * V_2 ,
struct V_81 T_4 * V_75 )
{
struct V_81 V_76 ;
struct V_52 * V_34 ;
struct V_5 * V_6 ;
if ( F_57 ( & V_76 , V_75 , sizeof( V_76 ) ) != 0 )
return - V_49 ;
F_3 ( L_17 , V_2 , ( unsigned long ) V_76 . V_82 ) ;
V_34 = F_62 ( V_70 -> V_57 , V_76 . V_82 ) ;
if ( ! V_34 || V_34 -> V_83 != & V_84 )
return - V_44 ;
V_6 = V_34 -> V_53 ;
if ( ! V_6 )
return - V_44 ;
V_76 . V_45 = V_6 -> V_8 << V_36 ;
V_76 . V_9 = V_6 -> V_9 ;
if ( F_29 ( V_75 , & V_76 , sizeof( V_76 ) ) != 0 )
return - V_49 ;
return 0 ;
}
static long F_63 ( struct V_1 * V_2 , void T_4 * V_75 )
{
struct V_85 V_76 ;
struct V_5 * V_6 ;
int V_86 ;
if ( F_57 ( & V_76 , V_75 , sizeof( V_76 ) ) )
return - V_49 ;
if ( V_76 . V_87 & ~ ( V_46 | V_26 ) )
return - V_44 ;
F_38 ( & V_2 -> V_62 ) ;
F_4 (map, &priv->maps, next) {
T_6 V_88 = V_6 -> V_8 << V_36 ;
T_6 V_59 = ( V_6 -> V_8 + V_6 -> V_9 ) << V_36 ;
if ( V_76 . V_8 >= V_88 && V_76 . V_8 < V_59 )
goto V_89;
}
V_86 = - V_80 ;
goto V_90;
V_89:
if ( ( V_76 . V_87 & V_46 ) &&
( V_6 -> V_25 & V_91 ) ) {
V_86 = - V_44 ;
goto V_90;
}
V_6 -> V_24 . V_25 = V_76 . V_87 ;
V_6 -> V_24 . V_31 = V_76 . V_8 - ( V_6 -> V_8 << V_36 ) ;
V_6 -> V_24 . V_27 = V_76 . V_92 ;
V_86 = 0 ;
V_90:
F_42 ( & V_2 -> V_62 ) ;
return V_86 ;
}
static long F_64 ( struct V_66 * V_67 ,
unsigned int V_93 , unsigned long V_94 )
{
struct V_1 * V_2 = V_67 -> V_73 ;
void T_4 * V_95 = ( void T_4 * ) V_94 ;
switch ( V_93 ) {
case V_96 :
return F_56 ( V_2 , V_95 ) ;
case V_97 :
return F_60 ( V_2 , V_95 ) ;
case V_98 :
return F_61 ( V_2 , V_95 ) ;
case V_99 :
return F_63 ( V_2 , V_95 ) ;
default:
F_3 ( L_18 , V_2 , V_93 ) ;
return - V_100 ;
}
return 0 ;
}
static int F_65 ( struct V_66 * V_67 , struct V_52 * V_34 )
{
struct V_1 * V_2 = V_67 -> V_73 ;
int V_8 = V_34 -> V_101 ;
int V_9 = ( V_34 -> V_63 - V_34 -> V_35 ) >> V_36 ;
struct V_5 * V_6 ;
int V_11 , V_17 = - V_44 ;
if ( ( V_34 -> V_102 & V_103 ) && ! ( V_34 -> V_102 & V_104 ) )
return - V_44 ;
F_3 ( L_19 ,
V_8 , V_9 , V_34 -> V_35 , V_34 -> V_101 ) ;
F_38 ( & V_2 -> V_62 ) ;
V_6 = F_12 ( V_2 , V_8 , V_9 ) ;
if ( ! V_6 )
goto V_90;
if ( V_28 && V_6 -> V_34 )
goto V_90;
if ( V_28 && V_2 -> V_57 != V_34 -> V_105 ) {
F_66 ( V_106 L_20 ) ;
goto V_90;
}
F_34 ( & V_6 -> V_19 ) ;
V_34 -> V_83 = & V_84 ;
V_34 -> V_102 |= V_107 | V_108 ;
if ( V_28 )
V_34 -> V_102 |= V_109 | V_110 ;
V_34 -> V_53 = V_6 ;
if ( V_28 )
V_6 -> V_34 = V_34 ;
if ( V_6 -> V_25 ) {
if ( ( V_34 -> V_102 & V_103 ) &&
( V_6 -> V_25 & V_91 ) )
goto V_111;
} else {
V_6 -> V_25 = V_112 ;
if ( ! ( V_34 -> V_102 & V_103 ) )
V_6 -> V_25 |= V_91 ;
}
F_42 ( & V_2 -> V_62 ) ;
if ( V_28 ) {
V_17 = F_67 ( V_34 -> V_105 , V_34 -> V_35 ,
V_34 -> V_63 - V_34 -> V_35 ,
F_19 , V_6 ) ;
if ( V_17 ) {
F_66 ( V_106 L_21 ) ;
goto V_113;
}
}
V_17 = F_24 ( V_6 ) ;
if ( V_17 )
goto V_113;
if ( ! V_28 ) {
for ( V_11 = 0 ; V_11 < V_9 ; V_11 ++ ) {
V_17 = F_68 ( V_34 , V_34 -> V_35 + V_11 * V_50 ,
V_6 -> V_16 [ V_11 ] ) ;
if ( V_17 )
goto V_113;
}
}
return 0 ;
V_90:
F_42 ( & V_2 -> V_62 ) ;
return V_17 ;
V_111:
F_42 ( & V_2 -> V_62 ) ;
V_113:
if ( V_28 )
V_6 -> V_34 = NULL ;
F_13 ( V_6 ) ;
return V_17 ;
}
static int T_7 F_69 ( void )
{
int V_17 ;
if ( ! F_70 () )
return - V_114 ;
V_28 = F_71 () ;
V_17 = F_72 ( & V_115 ) ;
if ( V_17 != 0 ) {
F_66 ( V_116 L_22 ) ;
return V_17 ;
}
return 0 ;
}
static void T_8 F_73 ( void )
{
F_74 ( & V_115 ) ;
}
