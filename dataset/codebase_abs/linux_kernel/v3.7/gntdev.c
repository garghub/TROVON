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
static void F_16 ( struct V_5 * V_6 )
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
if ( V_6 -> V_10 && ! V_29 )
F_21 ( V_6 , 0 , V_6 -> V_9 ) ;
F_5 ( V_6 ) ;
}
static int F_22 ( T_1 * V_30 , T_2 V_31 ,
unsigned long V_32 , void * V_33 )
{
struct V_5 * V_6 = V_33 ;
unsigned int V_34 = ( V_32 - V_6 -> V_35 -> V_36 ) >> V_37 ;
int V_26 = V_6 -> V_26 | V_38 | V_39 ;
T_3 V_40 ;
F_23 ( V_34 >= V_6 -> V_9 ) ;
V_40 = F_24 ( V_30 ) . V_41 ;
F_25 ( & V_6 -> V_12 [ V_34 ] , V_40 , V_26 ,
V_6 -> V_11 [ V_34 ] . V_42 ,
V_6 -> V_11 [ V_34 ] . V_43 ) ;
F_26 ( & V_6 -> V_13 [ V_34 ] , V_40 , V_26 ,
- 1 ) ;
return 0 ;
}
static int F_27 ( struct V_5 * V_6 )
{
int V_16 , V_18 = 0 ;
if ( ! V_29 ) {
if ( V_6 -> V_12 [ 0 ] . V_19 != - 1 )
return 0 ;
for ( V_16 = 0 ; V_16 < V_6 -> V_9 ; V_16 ++ ) {
unsigned long V_32 = ( unsigned long )
F_28 ( F_29 ( V_6 -> V_10 [ V_16 ] ) ) ;
F_25 ( & V_6 -> V_12 [ V_16 ] , V_32 , V_6 -> V_26 ,
V_6 -> V_11 [ V_16 ] . V_42 ,
V_6 -> V_11 [ V_16 ] . V_43 ) ;
F_26 ( & V_6 -> V_13 [ V_16 ] , V_32 ,
V_6 -> V_26 , - 1 ) ;
}
} else {
for ( V_16 = 0 ; V_16 < V_6 -> V_9 ; V_16 ++ ) {
unsigned V_44 ;
unsigned long V_45 = ( unsigned long )
F_28 ( F_29 ( V_6 -> V_10 [ V_16 ] ) ) ;
T_1 * V_46 ;
T_3 V_40 = 0 ;
F_23 ( F_30 ( V_6 -> V_10 [ V_16 ] ) ) ;
V_46 = F_31 ( V_45 , & V_44 ) ;
V_40 = F_24 ( V_46 ) . V_41 ;
F_25 ( & V_6 -> V_14 [ V_16 ] , V_40 ,
V_6 -> V_26 |
V_47 |
V_39 ,
V_6 -> V_11 [ V_16 ] . V_42 ,
V_6 -> V_11 [ V_16 ] . V_43 ) ;
}
}
F_3 ( L_5 , V_6 -> V_8 , V_6 -> V_9 ) ;
V_18 = F_32 ( V_6 -> V_12 , V_29 ? V_6 -> V_14 : NULL ,
V_6 -> V_10 , V_6 -> V_9 ) ;
if ( V_18 )
return V_18 ;
for ( V_16 = 0 ; V_16 < V_6 -> V_9 ; V_16 ++ ) {
if ( V_6 -> V_12 [ V_16 ] . V_48 )
V_18 = - V_49 ;
else {
F_23 ( V_6 -> V_12 [ V_16 ] . V_19 == - 1 ) ;
V_6 -> V_13 [ V_16 ] . V_19 = V_6 -> V_12 [ V_16 ] . V_19 ;
F_3 ( L_6 , V_6 -> V_12 [ V_16 ] . V_19 ) ;
}
}
return V_18 ;
}
static int F_33 ( struct V_5 * V_6 , int V_50 , int V_10 )
{
int V_16 , V_18 = 0 ;
if ( V_6 -> V_25 . V_26 & V_51 ) {
int V_52 = ( V_6 -> V_25 . V_32 >> V_37 ) ;
if ( V_52 >= V_50 && V_52 < V_50 + V_10 && V_29 ) {
void T_4 * V_53 = ( void T_4 * )
V_6 -> V_35 -> V_36 + V_6 -> V_25 . V_32 ;
V_18 = F_34 ( V_53 , & V_18 , 1 ) ;
if ( V_18 )
return - V_54 ;
V_6 -> V_25 . V_26 &= ~ V_51 ;
} else if ( V_52 >= V_50 && V_52 < V_50 + V_10 ) {
T_5 * V_53 = F_35 ( V_6 -> V_10 [ V_52 ] ) ;
V_53 [ V_6 -> V_25 . V_32 & ( V_55 - 1 ) ] = 0 ;
F_36 ( V_6 -> V_10 [ V_52 ] ) ;
V_6 -> V_25 . V_26 &= ~ V_51 ;
}
}
V_18 = F_37 ( V_6 -> V_13 + V_50 ,
V_29 ? V_6 -> V_14 + V_50 : NULL , V_6 -> V_10 + V_50 ,
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
static int F_21 ( struct V_5 * V_6 , int V_50 , int V_10 )
{
int V_56 , V_18 = 0 ;
F_3 ( L_8 , V_6 -> V_8 , V_6 -> V_9 , V_50 , V_10 ) ;
while ( V_10 && ! V_18 ) {
while ( V_10 && V_6 -> V_13 [ V_50 ] . V_19 == - 1 ) {
V_50 ++ ;
V_10 -- ;
}
V_56 = 0 ;
while ( V_56 < V_10 ) {
if ( V_6 -> V_13 [ V_50 + V_56 ] . V_19 == - 1 ) {
V_56 -- ;
break;
}
V_56 ++ ;
}
V_18 = F_33 ( V_6 , V_50 , V_56 ) ;
V_50 += V_56 ;
V_10 -= V_56 ;
}
return V_18 ;
}
static void F_38 ( struct V_57 * V_35 )
{
struct V_5 * V_6 = V_35 -> V_58 ;
F_3 ( L_9 , V_35 ) ;
F_39 ( & V_6 -> V_20 ) ;
}
static void F_40 ( struct V_57 * V_35 )
{
struct V_5 * V_6 = V_35 -> V_58 ;
F_3 ( L_10 , V_35 ) ;
V_6 -> V_35 = NULL ;
V_35 -> V_58 = NULL ;
F_16 ( V_6 ) ;
}
static void F_41 ( struct V_59 * V_60 ,
struct V_61 * V_62 ,
unsigned long V_63 , unsigned long V_64 )
{
struct V_1 * V_2 = F_42 ( V_60 , struct V_1 , V_60 ) ;
struct V_5 * V_6 ;
unsigned long V_65 , V_66 ;
int V_18 ;
F_43 ( & V_2 -> V_67 ) ;
F_4 (map, &priv->maps, next) {
if ( ! V_6 -> V_35 )
continue;
if ( V_6 -> V_35 -> V_36 >= V_64 )
continue;
if ( V_6 -> V_35 -> V_68 <= V_63 )
continue;
V_65 = F_44 ( V_63 , V_6 -> V_35 -> V_36 ) ;
V_66 = F_45 ( V_64 , V_6 -> V_35 -> V_68 ) ;
F_3 ( L_11 ,
V_6 -> V_8 , V_6 -> V_9 ,
V_6 -> V_35 -> V_36 , V_6 -> V_35 -> V_68 ,
V_63 , V_64 , V_65 , V_66 ) ;
V_18 = F_21 ( V_6 ,
( V_65 - V_6 -> V_35 -> V_36 ) >> V_37 ,
( V_66 - V_65 ) >> V_37 ) ;
F_46 ( V_18 ) ;
}
F_47 ( & V_2 -> V_67 ) ;
}
static void F_48 ( struct V_59 * V_60 ,
struct V_61 * V_62 ,
unsigned long V_45 )
{
F_41 ( V_60 , V_62 , V_45 , V_45 + V_55 ) ;
}
static void F_49 ( struct V_59 * V_60 ,
struct V_61 * V_62 )
{
struct V_1 * V_2 = F_42 ( V_60 , struct V_1 , V_60 ) ;
struct V_5 * V_6 ;
int V_18 ;
F_43 ( & V_2 -> V_67 ) ;
F_4 (map, &priv->maps, next) {
if ( ! V_6 -> V_35 )
continue;
F_3 ( L_12 ,
V_6 -> V_8 , V_6 -> V_9 ,
V_6 -> V_35 -> V_36 , V_6 -> V_35 -> V_68 ) ;
V_18 = F_21 ( V_6 , 0 , V_6 -> V_9 ) ;
F_46 ( V_18 ) ;
}
F_47 ( & V_2 -> V_67 ) ;
}
static int F_50 ( struct V_69 * V_69 , struct V_70 * V_71 )
{
struct V_1 * V_2 ;
int V_72 = 0 ;
V_2 = F_9 ( sizeof( * V_2 ) , V_17 ) ;
if ( ! V_2 )
return - V_73 ;
F_51 ( & V_2 -> V_23 ) ;
F_52 ( & V_2 -> V_67 ) ;
if ( V_29 ) {
V_2 -> V_62 = F_53 ( V_74 ) ;
if ( ! V_2 -> V_62 ) {
F_7 ( V_2 ) ;
return - V_73 ;
}
V_2 -> V_60 . V_75 = & V_76 ;
V_72 = F_54 ( & V_2 -> V_60 , V_2 -> V_62 ) ;
F_55 ( V_2 -> V_62 ) ;
}
if ( V_72 ) {
F_7 ( V_2 ) ;
return V_72 ;
}
V_71 -> V_77 = V_2 ;
F_3 ( L_13 , V_2 ) ;
return 0 ;
}
static int F_56 ( struct V_69 * V_69 , struct V_70 * V_71 )
{
struct V_1 * V_2 = V_71 -> V_77 ;
struct V_5 * V_6 ;
F_3 ( L_13 , V_2 ) ;
while ( ! F_57 ( & V_2 -> V_23 ) ) {
V_6 = F_58 ( V_2 -> V_23 . V_21 , struct V_5 , V_21 ) ;
F_59 ( & V_6 -> V_21 ) ;
F_16 ( V_6 ) ;
}
if ( V_29 )
F_60 ( & V_2 -> V_60 , V_2 -> V_62 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static long F_61 ( struct V_1 * V_2 ,
struct V_78 T_4 * V_79 )
{
struct V_78 V_80 ;
struct V_5 * V_6 ;
int V_18 ;
if ( F_62 ( & V_80 , V_79 , sizeof( V_80 ) ) != 0 )
return - V_54 ;
F_3 ( L_14 , V_2 , V_80 . V_9 ) ;
if ( F_63 ( V_80 . V_9 <= 0 ) )
return - V_49 ;
V_18 = - V_73 ;
V_6 = F_8 ( V_2 , V_80 . V_9 ) ;
if ( ! V_6 )
return V_18 ;
if ( F_63 ( F_64 ( V_80 . V_9 , & V_24 ) > V_81 ) ) {
F_3 ( L_15 ) ;
F_16 ( V_6 ) ;
return V_18 ;
}
if ( F_62 ( V_6 -> V_11 , & V_79 -> V_82 ,
sizeof( V_6 -> V_11 [ 0 ] ) * V_80 . V_9 ) != 0 ) {
F_16 ( V_6 ) ;
return V_18 ;
}
F_43 ( & V_2 -> V_67 ) ;
F_13 ( V_2 , V_6 ) ;
V_80 . V_8 = V_6 -> V_8 << V_37 ;
F_47 ( & V_2 -> V_67 ) ;
if ( F_34 ( V_79 , & V_80 , sizeof( V_80 ) ) != 0 )
return - V_54 ;
return 0 ;
}
static long F_65 ( struct V_1 * V_2 ,
struct V_83 T_4 * V_79 )
{
struct V_83 V_80 ;
struct V_5 * V_6 ;
int V_18 = - V_84 ;
if ( F_62 ( & V_80 , V_79 , sizeof( V_80 ) ) != 0 )
return - V_54 ;
F_3 ( L_16 , V_2 , ( int ) V_80 . V_8 , ( int ) V_80 . V_9 ) ;
F_43 ( & V_2 -> V_67 ) ;
V_6 = F_15 ( V_2 , V_80 . V_8 >> V_37 , V_80 . V_9 ) ;
if ( V_6 ) {
F_59 ( & V_6 -> V_21 ) ;
V_18 = 0 ;
}
F_47 ( & V_2 -> V_67 ) ;
if ( V_6 )
F_16 ( V_6 ) ;
return V_18 ;
}
static long F_66 ( struct V_1 * V_2 ,
struct V_85 T_4 * V_79 )
{
struct V_85 V_80 ;
struct V_57 * V_35 ;
struct V_5 * V_6 ;
if ( F_62 ( & V_80 , V_79 , sizeof( V_80 ) ) != 0 )
return - V_54 ;
F_3 ( L_17 , V_2 , ( unsigned long ) V_80 . V_86 ) ;
V_35 = F_67 ( V_74 -> V_62 , V_80 . V_86 ) ;
if ( ! V_35 || V_35 -> V_87 != & V_88 )
return - V_49 ;
V_6 = V_35 -> V_58 ;
if ( ! V_6 )
return - V_49 ;
V_80 . V_50 = V_6 -> V_8 << V_37 ;
V_80 . V_9 = V_6 -> V_9 ;
if ( F_34 ( V_79 , & V_80 , sizeof( V_80 ) ) != 0 )
return - V_54 ;
return 0 ;
}
static long F_68 ( struct V_1 * V_2 , void T_4 * V_79 )
{
struct V_89 V_80 ;
struct V_5 * V_6 ;
int V_90 ;
int V_91 ;
unsigned int V_92 ;
if ( F_62 ( & V_80 , V_79 , sizeof( V_80 ) ) )
return - V_54 ;
if ( V_80 . V_93 & ~ ( V_51 | V_27 ) )
return - V_49 ;
if ( V_80 . V_93 & V_27 ) {
if ( F_69 ( V_80 . V_94 ) )
return - V_49 ;
}
V_91 = V_80 . V_93 ;
V_92 = V_80 . V_94 ;
F_43 ( & V_2 -> V_67 ) ;
F_4 (map, &priv->maps, next) {
T_6 V_95 = V_6 -> V_8 << V_37 ;
T_6 V_64 = ( V_6 -> V_8 + V_6 -> V_9 ) << V_37 ;
if ( V_80 . V_8 >= V_95 && V_80 . V_8 < V_64 )
goto V_96;
}
V_90 = - V_84 ;
goto V_97;
V_96:
if ( ( V_80 . V_93 & V_51 ) &&
( V_6 -> V_26 & V_98 ) ) {
V_90 = - V_49 ;
goto V_97;
}
V_91 = V_6 -> V_25 . V_26 ;
V_92 = V_6 -> V_25 . V_28 ;
V_6 -> V_25 . V_26 = V_80 . V_93 ;
V_6 -> V_25 . V_32 = V_80 . V_8 - ( V_6 -> V_8 << V_37 ) ;
V_6 -> V_25 . V_28 = V_80 . V_94 ;
V_90 = 0 ;
V_97:
F_47 ( & V_2 -> V_67 ) ;
if ( V_91 & V_27 )
F_20 ( V_92 ) ;
return V_90 ;
}
static long F_70 ( struct V_70 * V_71 ,
unsigned int V_99 , unsigned long V_100 )
{
struct V_1 * V_2 = V_71 -> V_77 ;
void T_4 * V_101 = ( void T_4 * ) V_100 ;
switch ( V_99 ) {
case V_102 :
return F_61 ( V_2 , V_101 ) ;
case V_103 :
return F_65 ( V_2 , V_101 ) ;
case V_104 :
return F_66 ( V_2 , V_101 ) ;
case V_105 :
return F_68 ( V_2 , V_101 ) ;
default:
F_3 ( L_18 , V_2 , V_99 ) ;
return - V_106 ;
}
return 0 ;
}
static int F_71 ( struct V_70 * V_71 , struct V_57 * V_35 )
{
struct V_1 * V_2 = V_71 -> V_77 ;
int V_8 = V_35 -> V_107 ;
int V_9 = ( V_35 -> V_68 - V_35 -> V_36 ) >> V_37 ;
struct V_5 * V_6 ;
int V_16 , V_18 = - V_49 ;
if ( ( V_35 -> V_108 & V_109 ) && ! ( V_35 -> V_108 & V_110 ) )
return - V_49 ;
F_3 ( L_19 ,
V_8 , V_9 , V_35 -> V_36 , V_35 -> V_107 ) ;
F_43 ( & V_2 -> V_67 ) ;
V_6 = F_15 ( V_2 , V_8 , V_9 ) ;
if ( ! V_6 )
goto V_97;
if ( V_29 && V_6 -> V_35 )
goto V_97;
if ( V_29 && V_2 -> V_62 != V_35 -> V_111 ) {
F_72 ( V_112 L_20 ) ;
goto V_97;
}
F_39 ( & V_6 -> V_20 ) ;
V_35 -> V_87 = & V_88 ;
V_35 -> V_108 |= V_113 | V_114 ;
if ( V_29 )
V_35 -> V_108 |= V_115 ;
V_35 -> V_58 = V_6 ;
if ( V_29 )
V_6 -> V_35 = V_35 ;
if ( V_6 -> V_26 ) {
if ( ( V_35 -> V_108 & V_109 ) &&
( V_6 -> V_26 & V_98 ) )
goto V_116;
} else {
V_6 -> V_26 = V_47 ;
if ( ! ( V_35 -> V_108 & V_109 ) )
V_6 -> V_26 |= V_98 ;
}
F_47 ( & V_2 -> V_67 ) ;
if ( V_29 ) {
V_18 = F_73 ( V_35 -> V_111 , V_35 -> V_36 ,
V_35 -> V_68 - V_35 -> V_36 ,
F_22 , V_6 ) ;
if ( V_18 ) {
F_72 ( V_112 L_21 ) ;
goto V_117;
}
}
V_18 = F_27 ( V_6 ) ;
if ( V_18 )
goto V_117;
if ( ! V_29 ) {
for ( V_16 = 0 ; V_16 < V_9 ; V_16 ++ ) {
V_18 = F_74 ( V_35 , V_35 -> V_36 + V_16 * V_55 ,
V_6 -> V_10 [ V_16 ] ) ;
if ( V_18 )
goto V_117;
}
}
return 0 ;
V_97:
F_47 ( & V_2 -> V_67 ) ;
return V_18 ;
V_116:
F_47 ( & V_2 -> V_67 ) ;
V_117:
if ( V_29 )
V_6 -> V_35 = NULL ;
F_16 ( V_6 ) ;
return V_18 ;
}
static int T_7 F_75 ( void )
{
int V_18 ;
if ( ! F_76 () )
return - V_118 ;
V_29 = F_77 () ;
V_18 = F_78 ( & V_119 ) ;
if ( V_18 != 0 ) {
F_72 ( V_120 L_22 ) ;
return V_18 ;
}
return 0 ;
}
static void T_8 F_79 ( void )
{
F_80 ( & V_119 ) ;
}
