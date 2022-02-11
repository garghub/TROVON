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
V_23 -> V_25 = V_25 ;
switch ( V_23 -> V_25 ) {
case V_30 :
V_29 = V_31 ;
break;
case V_32 :
V_29 = V_33 ;
break;
default:
F_17 () ;
}
V_27 = ( V_26 & V_34 ) >> V_35 ;
V_28 = ( ( V_26 + V_12 - 1 ) & V_34 ) >> V_35 ;
V_23 -> V_11 = V_26 & ~ V_34 ;
V_23 -> V_12 = V_12 ;
V_23 -> V_3 = V_28 - V_27 + 1 ;
V_23 -> V_10 = F_18 ( V_23 -> V_3 * sizeof( struct V_5 * ) , V_36 ) ;
if ( NULL == V_23 -> V_10 )
return - V_37 ;
F_12 ( 1 , L_3 ,
V_26 , V_12 , V_23 -> V_3 ) ;
V_9 = F_19 ( V_38 , V_38 -> V_39 ,
V_26 & V_34 , V_23 -> V_3 ,
V_29 == V_31 , 1 ,
V_23 -> V_10 , NULL ) ;
if ( V_9 != V_23 -> V_3 ) {
V_23 -> V_3 = ( V_9 >= 0 ) ? V_9 : 0 ;
F_12 ( 1 , L_4 , V_9 , V_23 -> V_3 ) ;
return V_9 < 0 ? V_9 : - V_40 ;
}
return 0 ;
}
static int F_20 ( struct V_15 * V_23 , int V_25 ,
unsigned long V_26 , unsigned long V_12 )
{
int V_41 ;
F_21 ( & V_38 -> V_39 -> V_42 ) ;
V_41 = F_16 ( V_23 , V_25 , V_26 , V_12 ) ;
F_22 ( & V_38 -> V_39 -> V_42 ) ;
return V_41 ;
}
static int F_23 ( struct V_15 * V_23 , int V_25 ,
int V_3 )
{
int V_7 ;
F_12 ( 1 , L_5 , V_3 ) ;
V_23 -> V_25 = V_25 ;
V_23 -> V_43 = F_24 ( V_3 , sizeof( * V_23 -> V_43 ) ,
V_36 ) ;
if ( ! V_23 -> V_43 )
return - V_37 ;
V_23 -> V_44 = F_24 ( V_3 , sizeof( * V_23 -> V_44 ) , V_36 ) ;
if ( ! V_23 -> V_44 ) {
F_25 ( V_23 -> V_43 ) ;
return - V_37 ;
}
for ( V_7 = 0 ; V_7 < V_3 ; V_7 ++ ) {
void * V_45 ;
V_45 = F_26 ( V_23 -> V_46 , V_8 ,
& ( V_23 -> V_44 [ V_7 ] ) , V_36 ) ;
if ( V_45 == NULL )
goto V_47;
V_23 -> V_43 [ V_7 ] = F_27 ( V_45 ) ;
}
V_23 -> V_48 = F_28 ( V_23 -> V_43 , V_3 , V_49 | V_50 ,
V_51 ) ;
if ( NULL == V_23 -> V_48 ) {
F_12 ( 1 , L_6 , V_3 ) ;
goto V_47;
}
F_12 ( 1 , L_7 ,
( unsigned long ) V_23 -> V_48 ,
V_3 << V_35 ) ;
memset ( V_23 -> V_48 , 0 , V_3 << V_35 ) ;
V_23 -> V_3 = V_3 ;
return 0 ;
V_47:
while ( V_7 > 0 ) {
void * V_45 ;
V_7 -- ;
V_45 = F_29 ( V_23 -> V_43 [ V_7 ] ) ;
F_30 ( V_23 -> V_46 , V_8 , V_45 , V_23 -> V_44 [ V_7 ] ) ;
}
F_25 ( V_23 -> V_44 ) ;
V_23 -> V_44 = NULL ;
F_25 ( V_23 -> V_43 ) ;
V_23 -> V_43 = NULL ;
return - V_37 ;
}
static int F_31 ( struct V_15 * V_23 , int V_25 ,
T_2 V_45 , int V_3 )
{
F_12 ( 1 , L_8 ,
V_3 , ( unsigned long ) V_45 ) ;
V_23 -> V_25 = V_25 ;
if ( 0 == V_45 )
return - V_40 ;
V_23 -> V_52 = V_45 ;
V_23 -> V_3 = V_3 ;
return 0 ;
}
static int F_32 ( struct V_53 * V_46 , struct V_15 * V_23 )
{
F_14 ( V_23 -> V_21 , V_24 ) ;
F_5 ( 0 == V_23 -> V_3 ) ;
if ( V_23 -> V_10 ) {
V_23 -> V_4 = F_9 ( V_23 -> V_10 , V_23 -> V_3 ,
V_23 -> V_11 , V_23 -> V_12 ) ;
}
if ( V_23 -> V_48 ) {
V_23 -> V_4 = F_1 ( V_23 -> V_48 ,
V_23 -> V_3 ) ;
}
if ( V_23 -> V_52 ) {
V_23 -> V_4 = F_10 ( sizeof( * V_23 -> V_4 ) ) ;
if ( NULL != V_23 -> V_4 ) {
V_23 -> V_54 = 1 ;
F_33 ( & V_23 -> V_4 [ 0 ] ) = V_23 -> V_52
& V_34 ;
V_23 -> V_4 [ 0 ] . V_11 = V_23 -> V_52 & ~ V_34 ;
F_34 ( & V_23 -> V_4 [ 0 ] ) = V_23 -> V_3 * V_8 ;
}
}
if ( NULL == V_23 -> V_4 ) {
F_12 ( 1 , L_9 ) ;
return - V_37 ;
}
if ( ! V_23 -> V_52 ) {
V_23 -> V_54 = F_35 ( V_46 , V_23 -> V_4 ,
V_23 -> V_3 , V_23 -> V_25 ) ;
if ( 0 == V_23 -> V_54 ) {
F_36 ( V_55
L_10 , V_56 ) ;
F_8 ( V_23 -> V_4 ) ;
V_23 -> V_4 = NULL ;
V_23 -> V_54 = 0 ;
return - V_37 ;
}
}
return 0 ;
}
int F_37 ( struct V_53 * V_46 , struct V_15 * V_23 )
{
F_14 ( V_23 -> V_21 , V_24 ) ;
if ( ! V_23 -> V_54 )
return 0 ;
F_38 ( V_46 , V_23 -> V_4 , V_23 -> V_54 , V_23 -> V_25 ) ;
F_8 ( V_23 -> V_4 ) ;
V_23 -> V_4 = NULL ;
V_23 -> V_54 = 0 ;
return 0 ;
}
int F_39 ( struct V_15 * V_23 )
{
int V_7 ;
F_14 ( V_23 -> V_21 , V_24 ) ;
F_5 ( V_23 -> V_54 ) ;
if ( V_23 -> V_10 ) {
for ( V_7 = 0 ; V_7 < V_23 -> V_3 ; V_7 ++ )
F_40 ( V_23 -> V_10 [ V_7 ] ) ;
F_25 ( V_23 -> V_10 ) ;
V_23 -> V_10 = NULL ;
}
if ( V_23 -> V_44 ) {
for ( V_7 = 0 ; V_7 < V_23 -> V_3 ; V_7 ++ ) {
void * V_45 ;
V_45 = F_29 ( V_23 -> V_43 [ V_7 ] ) ;
F_30 ( V_23 -> V_46 , V_8 , V_45 ,
V_23 -> V_44 [ V_7 ] ) ;
}
F_25 ( V_23 -> V_44 ) ;
V_23 -> V_44 = NULL ;
F_25 ( V_23 -> V_43 ) ;
V_23 -> V_43 = NULL ;
F_41 ( V_23 -> V_48 ) ;
V_23 -> V_48 = NULL ;
}
if ( V_23 -> V_52 )
V_23 -> V_52 = 0 ;
V_23 -> V_25 = V_57 ;
return 0 ;
}
static void F_42 ( struct V_58 * V_59 )
{
struct V_60 * V_61 = V_59 -> V_62 ;
F_12 ( 2 , L_11 , V_61 ,
V_61 -> V_63 , V_59 -> V_64 , V_59 -> V_65 ) ;
V_61 -> V_63 ++ ;
}
static void F_43 ( struct V_58 * V_59 )
{
struct V_60 * V_61 = V_59 -> V_62 ;
struct V_66 * V_67 = V_61 -> V_67 ;
struct V_18 * V_19 ;
int V_7 ;
F_12 ( 2 , L_12 , V_61 ,
V_61 -> V_63 , V_59 -> V_64 , V_59 -> V_65 ) ;
V_61 -> V_63 -- ;
if ( 0 == V_61 -> V_63 ) {
F_12 ( 1 , L_13 , V_61 , V_67 ) ;
F_44 ( V_67 ) ;
for ( V_7 = 0 ; V_7 < V_68 ; V_7 ++ ) {
if ( NULL == V_67 -> V_69 [ V_7 ] )
continue;
V_19 = V_67 -> V_69 [ V_7 ] -> V_20 ;
if ( ! V_19 )
continue;
F_14 ( V_19 -> V_21 , V_22 ) ;
if ( V_67 -> V_69 [ V_7 ] -> V_61 != V_61 )
continue;
V_67 -> V_69 [ V_7 ] -> V_61 = NULL ;
V_67 -> V_69 [ V_7 ] -> V_70 = 0 ;
V_67 -> V_71 -> V_72 ( V_67 , V_67 -> V_69 [ V_7 ] ) ;
}
F_45 ( V_67 ) ;
F_25 ( V_61 ) ;
}
return;
}
static int F_46 ( struct V_58 * V_59 , struct V_73 * V_74 )
{
struct V_5 * V_5 ;
F_12 ( 3 , L_14 ,
( unsigned long ) V_74 -> V_75 ,
V_59 -> V_64 , V_59 -> V_65 ) ;
V_5 = F_47 ( V_76 | V_77 ) ;
if ( ! V_5 )
return V_78 ;
F_48 ( V_5 , ( unsigned long ) V_74 -> V_75 ) ;
V_74 -> V_5 = V_5 ;
return 0 ;
}
static struct V_16 * F_49 ( T_1 V_12 )
{
struct V_18 * V_19 ;
struct V_16 * V_79 ;
V_79 = F_50 ( V_12 + sizeof( * V_19 ) , V_36 ) ;
if ( ! V_79 )
return V_79 ;
V_19 = V_79 -> V_20 = ( ( char * ) V_79 ) + V_12 ;
V_19 -> V_21 = V_22 ;
F_15 ( & V_19 -> V_23 ) ;
F_12 ( 1 , L_15 ,
V_56 , V_79 , ( long ) sizeof( * V_79 ) , ( long ) V_12 - sizeof( * V_79 ) ,
V_19 , ( long ) sizeof( * V_19 ) ) ;
return V_79 ;
}
static void * F_51 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
F_5 ( ! V_19 ) ;
F_14 ( V_19 -> V_21 , V_22 ) ;
return V_19 -> V_23 . V_48 ;
}
static int F_52 ( struct V_66 * V_67 ,
struct V_16 * V_79 ,
struct V_80 * V_81 )
{
int V_9 , V_10 ;
T_2 V_82 ;
struct V_18 * V_19 = V_79 -> V_20 ;
F_5 ( ! V_19 ) ;
F_14 ( V_19 -> V_21 , V_22 ) ;
if ( ! V_19 -> V_23 . V_46 )
V_19 -> V_23 . V_46 = V_67 -> V_46 ;
else
F_53 ( V_19 -> V_23 . V_46 != V_67 -> V_46 ) ;
switch ( V_79 -> V_83 ) {
case V_84 :
case V_85 :
if ( 0 == V_79 -> V_70 ) {
V_10 = F_54 ( V_79 -> V_12 ) >> V_35 ;
V_9 = F_23 ( & V_19 -> V_23 ,
V_30 ,
V_10 ) ;
if ( 0 != V_9 )
return V_9 ;
} else if ( V_79 -> V_83 == V_85 ) {
V_9 = F_20 ( & V_19 -> V_23 ,
V_30 ,
V_79 -> V_70 , V_79 -> V_86 ) ;
if ( 0 != V_9 )
return V_9 ;
} else {
V_9 = F_16 ( & V_19 -> V_23 ,
V_30 ,
V_79 -> V_70 , V_79 -> V_86 ) ;
if ( 0 != V_9 )
return V_9 ;
}
break;
case V_87 :
if ( NULL == V_81 )
return - V_40 ;
V_82 = ( T_2 ) ( unsigned long ) V_81 -> V_88 + V_79 -> V_89 ;
V_10 = F_54 ( V_79 -> V_12 ) >> V_35 ;
V_9 = F_31 ( & V_19 -> V_23 , V_30 ,
V_82 , V_10 ) ;
if ( 0 != V_9 )
return V_9 ;
break;
default:
F_17 () ;
}
V_9 = F_32 ( V_67 -> V_46 , & V_19 -> V_23 ) ;
if ( 0 != V_9 )
return V_9 ;
return 0 ;
}
static int F_55 ( struct V_66 * V_67 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
F_5 ( ! V_19 || ! V_19 -> V_23 . V_54 ) ;
F_14 ( V_19 -> V_21 , V_22 ) ;
F_14 ( V_19 -> V_23 . V_21 , V_24 ) ;
F_56 ( V_67 -> V_46 , V_19 -> V_23 . V_4 ,
V_19 -> V_23 . V_54 , V_19 -> V_23 . V_25 ) ;
return 0 ;
}
static int F_57 ( struct V_66 * V_67 ,
struct V_16 * V_17 ,
struct V_58 * V_59 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_60 * V_61 ;
unsigned int V_27 , V_28 , V_12 = 0 , V_7 ;
int V_90 ;
V_90 = - V_40 ;
F_5 ( ! V_19 ) ;
F_14 ( V_19 -> V_21 , V_22 ) ;
for ( V_27 = 0 ; V_27 < V_68 ; V_27 ++ ) {
if ( V_17 == V_67 -> V_69 [ V_27 ] ) {
V_12 = F_54 ( V_67 -> V_69 [ V_27 ] -> V_86 ) ;
break;
}
}
if ( ! V_12 ) {
F_12 ( 1 , L_16 ,
( V_59 -> V_91 << V_35 ) ) ;
goto V_92;
}
V_28 = V_27 ;
V_90 = - V_37 ;
V_61 = F_18 ( sizeof( struct V_60 ) , V_36 ) ;
if ( NULL == V_61 )
goto V_92;
V_12 = 0 ;
for ( V_7 = V_27 ; V_7 <= V_28 ; V_7 ++ ) {
if ( NULL == V_67 -> V_69 [ V_7 ] )
continue;
V_67 -> V_69 [ V_7 ] -> V_61 = V_61 ;
V_67 -> V_69 [ V_7 ] -> V_70 = V_59 -> V_64 + V_12 ;
V_12 += F_54 ( V_67 -> V_69 [ V_7 ] -> V_86 ) ;
}
V_61 -> V_63 = 1 ;
V_61 -> V_67 = V_67 ;
V_59 -> V_93 = & V_94 ;
V_59 -> V_95 |= V_96 | V_97 ;
V_59 -> V_95 &= ~ V_98 ;
V_59 -> V_62 = V_61 ;
F_12 ( 1 , L_17 ,
V_61 , V_67 , V_59 -> V_64 , V_59 -> V_65 , V_59 -> V_91 , V_27 , V_28 ) ;
V_90 = 0 ;
V_92:
return V_90 ;
}
void * F_58 ( T_1 V_12 )
{
struct V_66 V_67 ;
V_67 . V_99 = & V_100 ;
V_67 . V_101 = V_12 ;
return F_59 ( & V_67 ) ;
}
void F_60 ( struct V_66 * V_67 ,
const struct V_102 * V_71 ,
struct V_53 * V_46 ,
T_3 * V_103 ,
enum V_104 type ,
enum V_105 V_106 ,
unsigned int V_101 ,
void * V_20 ,
struct V_107 * V_108 )
{
F_61 ( V_67 , V_71 , V_46 , V_103 , type , V_106 , V_101 ,
V_20 , & V_100 , V_108 ) ;
}
