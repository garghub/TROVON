static struct V_1 * F_1 ( unsigned char * V_2 ,
int V_3 )
{
struct V_1 * V_4 ;
struct V_5 * V_6 ;
int V_7 ;
V_4 = F_2 ( V_3 * sizeof( * V_4 ) ) ;
if ( NULL == V_4 )
return NULL ;
F_3 ( V_4 , V_3 ) ;
for ( V_7 = 0 ; V_7 < V_3 ; V_7 ++ , V_2 += V_8 ) {
V_6 = F_4 ( V_2 ) ;
if ( NULL == V_6 )
goto V_9;
F_5 ( F_6 ( V_6 ) ) ;
F_7 ( & V_4 [ V_7 ] , V_6 , V_8 , 0 ) ;
}
return V_4 ;
V_9:
F_8 ( V_4 ) ;
return NULL ;
}
static struct V_1 * F_9 ( struct V_5 * * V_10 ,
int V_3 , int V_11 , T_1 V_12 )
{
struct V_1 * V_4 ;
int V_7 ;
if ( NULL == V_10 [ 0 ] )
return NULL ;
V_4 = F_10 ( V_3 * sizeof( * V_4 ) ) ;
if ( NULL == V_4 )
return NULL ;
F_3 ( V_4 , V_3 ) ;
if ( F_6 ( V_10 [ 0 ] ) )
goto V_13;
F_7 ( & V_4 [ 0 ] , V_10 [ 0 ] ,
F_11 ( T_1 , V_8 - V_11 , V_12 ) , V_11 ) ;
V_12 -= F_11 ( T_1 , V_8 - V_11 , V_12 ) ;
for ( V_7 = 1 ; V_7 < V_3 ; V_7 ++ ) {
if ( NULL == V_10 [ V_7 ] )
goto V_14;
if ( F_6 ( V_10 [ V_7 ] ) )
goto V_13;
F_7 ( & V_4 [ V_7 ] , V_10 [ V_7 ] , F_11 ( T_1 , V_8 , V_12 ) , 0 ) ;
V_12 -= F_11 ( T_1 , V_8 , V_12 ) ;
}
return V_4 ;
V_14:
F_12 ( 2 , L_1 ) ;
F_8 ( V_4 ) ;
return NULL ;
V_13:
F_12 ( 2 , L_2 ) ;
F_8 ( V_4 ) ;
return NULL ;
}
struct V_15 * F_13 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
F_5 ( ! V_19 ) ;
F_14 ( V_19 -> V_21 , V_22 ) ;
return & V_19 -> V_23 ;
}
static void F_15 ( struct V_15 * V_23 )
{
memset ( V_23 , 0 , sizeof( * V_23 ) ) ;
V_23 -> V_21 = V_24 ;
}
static int F_16 ( struct V_15 * V_23 ,
int V_25 , unsigned long V_26 , unsigned long V_12 )
{
unsigned long V_27 , V_28 ;
int V_9 , V_29 = 0 ;
unsigned int V_30 = V_31 ;
V_23 -> V_25 = V_25 ;
switch ( V_23 -> V_25 ) {
case V_32 :
V_29 = V_33 ;
break;
case V_34 :
V_29 = V_35 ;
break;
default:
F_17 () ;
}
V_27 = ( V_26 & V_36 ) >> V_37 ;
V_28 = ( ( V_26 + V_12 - 1 ) & V_36 ) >> V_37 ;
V_23 -> V_11 = V_26 & ~ V_36 ;
V_23 -> V_12 = V_12 ;
V_23 -> V_3 = V_28 - V_27 + 1 ;
V_23 -> V_10 = F_18 ( V_23 -> V_3 * sizeof( struct V_5 * ) , V_38 ) ;
if ( NULL == V_23 -> V_10 )
return - V_39 ;
if ( V_29 == V_33 )
V_30 |= V_40 ;
F_12 ( 1 , L_3 ,
V_26 , V_12 , V_23 -> V_3 ) ;
V_9 = F_19 ( V_26 & V_36 , V_23 -> V_3 ,
V_30 , V_23 -> V_10 , NULL ) ;
if ( V_9 != V_23 -> V_3 ) {
V_23 -> V_3 = ( V_9 >= 0 ) ? V_9 : 0 ;
F_12 ( 1 , L_4 , V_9 , V_23 -> V_3 ) ;
return V_9 < 0 ? V_9 : - V_41 ;
}
return 0 ;
}
static int F_20 ( struct V_15 * V_23 , int V_25 ,
unsigned long V_26 , unsigned long V_12 )
{
int V_42 ;
F_21 ( & V_43 -> V_44 -> V_45 ) ;
V_42 = F_16 ( V_23 , V_25 , V_26 , V_12 ) ;
F_22 ( & V_43 -> V_44 -> V_45 ) ;
return V_42 ;
}
static int F_23 ( struct V_15 * V_23 , int V_25 ,
int V_3 )
{
int V_7 ;
F_12 ( 1 , L_5 , V_3 ) ;
V_23 -> V_25 = V_25 ;
V_23 -> V_46 = F_24 ( V_3 , sizeof( * V_23 -> V_46 ) ,
V_38 ) ;
if ( ! V_23 -> V_46 )
return - V_39 ;
V_23 -> V_47 = F_24 ( V_3 , sizeof( * V_23 -> V_47 ) , V_38 ) ;
if ( ! V_23 -> V_47 ) {
F_25 ( V_23 -> V_46 ) ;
return - V_39 ;
}
for ( V_7 = 0 ; V_7 < V_3 ; V_7 ++ ) {
void * V_48 ;
V_48 = F_26 ( V_23 -> V_49 , V_8 ,
& ( V_23 -> V_47 [ V_7 ] ) , V_38 ) ;
if ( V_48 == NULL )
goto V_50;
V_23 -> V_46 [ V_7 ] = F_27 ( V_48 ) ;
}
V_23 -> V_51 = F_28 ( V_23 -> V_46 , V_3 , V_52 | V_53 ,
V_54 ) ;
if ( NULL == V_23 -> V_51 ) {
F_12 ( 1 , L_6 , V_3 ) ;
goto V_50;
}
F_12 ( 1 , L_7 ,
( unsigned long ) V_23 -> V_51 ,
V_3 << V_37 ) ;
memset ( V_23 -> V_51 , 0 , V_3 << V_37 ) ;
V_23 -> V_3 = V_3 ;
return 0 ;
V_50:
while ( V_7 > 0 ) {
void * V_48 ;
V_7 -- ;
V_48 = F_29 ( V_23 -> V_46 [ V_7 ] ) ;
F_30 ( V_23 -> V_49 , V_8 , V_48 , V_23 -> V_47 [ V_7 ] ) ;
}
F_25 ( V_23 -> V_47 ) ;
V_23 -> V_47 = NULL ;
F_25 ( V_23 -> V_46 ) ;
V_23 -> V_46 = NULL ;
return - V_39 ;
}
static int F_31 ( struct V_15 * V_23 , int V_25 ,
T_2 V_48 , int V_3 )
{
F_12 ( 1 , L_8 ,
V_3 , ( unsigned long ) V_48 ) ;
V_23 -> V_25 = V_25 ;
if ( 0 == V_48 )
return - V_41 ;
V_23 -> V_55 = V_48 ;
V_23 -> V_3 = V_3 ;
return 0 ;
}
static int F_32 ( struct V_56 * V_49 , struct V_15 * V_23 )
{
F_14 ( V_23 -> V_21 , V_24 ) ;
F_5 ( 0 == V_23 -> V_3 ) ;
if ( V_23 -> V_10 ) {
V_23 -> V_4 = F_9 ( V_23 -> V_10 , V_23 -> V_3 ,
V_23 -> V_11 , V_23 -> V_12 ) ;
}
if ( V_23 -> V_51 ) {
V_23 -> V_4 = F_1 ( V_23 -> V_51 ,
V_23 -> V_3 ) ;
}
if ( V_23 -> V_55 ) {
V_23 -> V_4 = F_10 ( sizeof( * V_23 -> V_4 ) ) ;
if ( NULL != V_23 -> V_4 ) {
V_23 -> V_57 = 1 ;
F_33 ( & V_23 -> V_4 [ 0 ] ) = V_23 -> V_55
& V_36 ;
V_23 -> V_4 [ 0 ] . V_11 = V_23 -> V_55 & ~ V_36 ;
F_34 ( & V_23 -> V_4 [ 0 ] ) = V_23 -> V_3 * V_8 ;
}
}
if ( NULL == V_23 -> V_4 ) {
F_12 ( 1 , L_9 ) ;
return - V_39 ;
}
if ( ! V_23 -> V_55 ) {
V_23 -> V_57 = F_35 ( V_49 , V_23 -> V_4 ,
V_23 -> V_3 , V_23 -> V_25 ) ;
if ( 0 == V_23 -> V_57 ) {
F_36 ( V_58
L_10 , V_59 ) ;
F_8 ( V_23 -> V_4 ) ;
V_23 -> V_4 = NULL ;
V_23 -> V_57 = 0 ;
return - V_39 ;
}
}
return 0 ;
}
int F_37 ( struct V_56 * V_49 , struct V_15 * V_23 )
{
F_14 ( V_23 -> V_21 , V_24 ) ;
if ( ! V_23 -> V_57 )
return 0 ;
F_38 ( V_49 , V_23 -> V_4 , V_23 -> V_57 , V_23 -> V_25 ) ;
F_8 ( V_23 -> V_4 ) ;
V_23 -> V_4 = NULL ;
V_23 -> V_57 = 0 ;
return 0 ;
}
int F_39 ( struct V_15 * V_23 )
{
int V_7 ;
F_14 ( V_23 -> V_21 , V_24 ) ;
F_5 ( V_23 -> V_57 ) ;
if ( V_23 -> V_10 ) {
for ( V_7 = 0 ; V_7 < V_23 -> V_3 ; V_7 ++ )
F_40 ( V_23 -> V_10 [ V_7 ] ) ;
F_25 ( V_23 -> V_10 ) ;
V_23 -> V_10 = NULL ;
}
if ( V_23 -> V_47 ) {
for ( V_7 = 0 ; V_7 < V_23 -> V_3 ; V_7 ++ ) {
void * V_48 ;
V_48 = F_29 ( V_23 -> V_46 [ V_7 ] ) ;
F_30 ( V_23 -> V_49 , V_8 , V_48 ,
V_23 -> V_47 [ V_7 ] ) ;
}
F_25 ( V_23 -> V_47 ) ;
V_23 -> V_47 = NULL ;
F_25 ( V_23 -> V_46 ) ;
V_23 -> V_46 = NULL ;
F_41 ( V_23 -> V_51 ) ;
V_23 -> V_51 = NULL ;
}
if ( V_23 -> V_55 )
V_23 -> V_55 = 0 ;
V_23 -> V_25 = V_60 ;
return 0 ;
}
static void F_42 ( struct V_61 * V_62 )
{
struct V_63 * V_64 = V_62 -> V_65 ;
F_12 ( 2 , L_11 , V_64 ,
V_64 -> V_66 , V_62 -> V_67 , V_62 -> V_68 ) ;
V_64 -> V_66 ++ ;
}
static void F_43 ( struct V_61 * V_62 )
{
struct V_63 * V_64 = V_62 -> V_65 ;
struct V_69 * V_70 = V_64 -> V_70 ;
struct V_18 * V_19 ;
int V_7 ;
F_12 ( 2 , L_12 , V_64 ,
V_64 -> V_66 , V_62 -> V_67 , V_62 -> V_68 ) ;
V_64 -> V_66 -- ;
if ( 0 == V_64 -> V_66 ) {
F_12 ( 1 , L_13 , V_64 , V_70 ) ;
F_44 ( V_70 ) ;
for ( V_7 = 0 ; V_7 < V_71 ; V_7 ++ ) {
if ( NULL == V_70 -> V_72 [ V_7 ] )
continue;
V_19 = V_70 -> V_72 [ V_7 ] -> V_20 ;
if ( ! V_19 )
continue;
F_14 ( V_19 -> V_21 , V_22 ) ;
if ( V_70 -> V_72 [ V_7 ] -> V_64 != V_64 )
continue;
V_70 -> V_72 [ V_7 ] -> V_64 = NULL ;
V_70 -> V_72 [ V_7 ] -> V_73 = 0 ;
V_70 -> V_74 -> V_75 ( V_70 , V_70 -> V_72 [ V_7 ] ) ;
}
F_45 ( V_70 ) ;
F_25 ( V_64 ) ;
}
return;
}
static int F_46 ( struct V_76 * V_77 )
{
struct V_61 * V_62 = V_77 -> V_62 ;
struct V_5 * V_5 ;
F_12 ( 3 , L_14 ,
V_77 -> V_78 , V_62 -> V_67 , V_62 -> V_68 ) ;
V_5 = F_47 ( V_79 | V_80 ) ;
if ( ! V_5 )
return V_81 ;
F_48 ( V_5 , V_77 -> V_78 ) ;
V_77 -> V_5 = V_5 ;
return 0 ;
}
static struct V_16 * F_49 ( T_1 V_12 )
{
struct V_18 * V_19 ;
struct V_16 * V_82 ;
V_82 = F_50 ( V_12 + sizeof( * V_19 ) , V_38 ) ;
if ( ! V_82 )
return V_82 ;
V_19 = V_82 -> V_20 = ( ( char * ) V_82 ) + V_12 ;
V_19 -> V_21 = V_22 ;
F_15 ( & V_19 -> V_23 ) ;
F_12 ( 1 , L_15 ,
V_59 , V_82 , ( long ) sizeof( * V_82 ) , ( long ) V_12 - sizeof( * V_82 ) ,
V_19 , ( long ) sizeof( * V_19 ) ) ;
return V_82 ;
}
static void * F_51 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
F_5 ( ! V_19 ) ;
F_14 ( V_19 -> V_21 , V_22 ) ;
return V_19 -> V_23 . V_51 ;
}
static int F_52 ( struct V_69 * V_70 ,
struct V_16 * V_82 ,
struct V_83 * V_84 )
{
int V_9 , V_10 ;
T_2 V_85 ;
struct V_18 * V_19 = V_82 -> V_20 ;
F_5 ( ! V_19 ) ;
F_14 ( V_19 -> V_21 , V_22 ) ;
if ( ! V_19 -> V_23 . V_49 )
V_19 -> V_23 . V_49 = V_70 -> V_49 ;
else
F_53 ( V_19 -> V_23 . V_49 != V_70 -> V_49 ) ;
switch ( V_82 -> V_86 ) {
case V_87 :
case V_88 :
if ( 0 == V_82 -> V_73 ) {
V_10 = F_54 ( V_82 -> V_12 ) >> V_37 ;
V_9 = F_23 ( & V_19 -> V_23 ,
V_32 ,
V_10 ) ;
if ( 0 != V_9 )
return V_9 ;
} else if ( V_82 -> V_86 == V_88 ) {
V_9 = F_20 ( & V_19 -> V_23 ,
V_32 ,
V_82 -> V_73 , V_82 -> V_89 ) ;
if ( 0 != V_9 )
return V_9 ;
} else {
V_9 = F_16 ( & V_19 -> V_23 ,
V_32 ,
V_82 -> V_73 , V_82 -> V_89 ) ;
if ( 0 != V_9 )
return V_9 ;
}
break;
case V_90 :
if ( NULL == V_84 )
return - V_41 ;
V_85 = ( T_2 ) ( unsigned long ) V_84 -> V_91 + V_82 -> V_92 ;
V_10 = F_54 ( V_82 -> V_12 ) >> V_37 ;
V_9 = F_31 ( & V_19 -> V_23 , V_32 ,
V_85 , V_10 ) ;
if ( 0 != V_9 )
return V_9 ;
break;
default:
F_17 () ;
}
V_9 = F_32 ( V_70 -> V_49 , & V_19 -> V_23 ) ;
if ( 0 != V_9 )
return V_9 ;
return 0 ;
}
static int F_55 ( struct V_69 * V_70 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
F_5 ( ! V_19 || ! V_19 -> V_23 . V_57 ) ;
F_14 ( V_19 -> V_21 , V_22 ) ;
F_14 ( V_19 -> V_23 . V_21 , V_24 ) ;
F_56 ( V_70 -> V_49 , V_19 -> V_23 . V_4 ,
V_19 -> V_23 . V_57 , V_19 -> V_23 . V_25 ) ;
return 0 ;
}
static int F_57 ( struct V_69 * V_70 ,
struct V_16 * V_17 ,
struct V_61 * V_62 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_63 * V_64 ;
unsigned int V_27 , V_28 , V_12 = 0 , V_7 ;
int V_93 ;
V_93 = - V_41 ;
F_5 ( ! V_19 ) ;
F_14 ( V_19 -> V_21 , V_22 ) ;
for ( V_27 = 0 ; V_27 < V_71 ; V_27 ++ ) {
if ( V_17 == V_70 -> V_72 [ V_27 ] ) {
V_12 = F_54 ( V_70 -> V_72 [ V_27 ] -> V_89 ) ;
break;
}
}
if ( ! V_12 ) {
F_12 ( 1 , L_16 ,
( V_62 -> V_94 << V_37 ) ) ;
goto V_95;
}
V_28 = V_27 ;
V_93 = - V_39 ;
V_64 = F_18 ( sizeof( struct V_63 ) , V_38 ) ;
if ( NULL == V_64 )
goto V_95;
V_12 = 0 ;
for ( V_7 = V_27 ; V_7 <= V_28 ; V_7 ++ ) {
if ( NULL == V_70 -> V_72 [ V_7 ] )
continue;
V_70 -> V_72 [ V_7 ] -> V_64 = V_64 ;
V_70 -> V_72 [ V_7 ] -> V_73 = V_62 -> V_67 + V_12 ;
V_12 += F_54 ( V_70 -> V_72 [ V_7 ] -> V_89 ) ;
}
V_64 -> V_66 = 1 ;
V_64 -> V_70 = V_70 ;
V_62 -> V_96 = & V_97 ;
V_62 -> V_98 |= V_99 | V_100 ;
V_62 -> V_98 &= ~ V_101 ;
V_62 -> V_65 = V_64 ;
F_12 ( 1 , L_17 ,
V_64 , V_70 , V_62 -> V_67 , V_62 -> V_68 , V_62 -> V_94 , V_27 , V_28 ) ;
V_93 = 0 ;
V_95:
return V_93 ;
}
void * F_58 ( T_1 V_12 )
{
struct V_69 V_70 ;
V_70 . V_102 = & V_103 ;
V_70 . V_104 = V_12 ;
return F_59 ( & V_70 ) ;
}
void F_60 ( struct V_69 * V_70 ,
const struct V_105 * V_74 ,
struct V_56 * V_49 ,
T_3 * V_106 ,
enum V_107 type ,
enum V_108 V_109 ,
unsigned int V_104 ,
void * V_20 ,
struct V_110 * V_111 )
{
F_61 ( V_70 , V_74 , V_49 , V_106 , type , V_109 , V_104 ,
V_20 , & V_103 , V_111 ) ;
}
