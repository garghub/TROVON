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
void F_15 ( struct V_15 * V_23 )
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
int F_20 ( struct V_15 * V_23 , int V_25 ,
unsigned long V_26 , unsigned long V_12 )
{
int V_41 ;
F_21 ( & V_38 -> V_39 -> V_42 ) ;
V_41 = F_16 ( V_23 , V_25 , V_26 , V_12 ) ;
F_22 ( & V_38 -> V_39 -> V_42 ) ;
return V_41 ;
}
int F_23 ( struct V_15 * V_23 , int V_25 ,
int V_3 )
{
F_12 ( 1 , L_5 , V_3 ) ;
V_23 -> V_25 = V_25 ;
V_23 -> V_43 = F_24 ( V_3 << V_35 ) ;
if ( NULL == V_23 -> V_43 ) {
F_12 ( 1 , L_6 , V_3 ) ;
return - V_37 ;
}
F_12 ( 1 , L_7 ,
( unsigned long ) V_23 -> V_43 ,
V_3 << V_35 ) ;
memset ( V_23 -> V_43 , 0 , V_3 << V_35 ) ;
V_23 -> V_3 = V_3 ;
return 0 ;
}
int F_25 ( struct V_15 * V_23 , int V_25 ,
T_2 V_44 , int V_3 )
{
F_12 ( 1 , L_8 ,
V_3 , ( unsigned long ) V_44 ) ;
V_23 -> V_25 = V_25 ;
if ( 0 == V_44 )
return - V_40 ;
V_23 -> V_45 = V_44 ;
V_23 -> V_3 = V_3 ;
return 0 ;
}
int F_26 ( struct V_46 * V_47 , struct V_15 * V_23 )
{
F_14 ( V_23 -> V_21 , V_24 ) ;
F_5 ( 0 == V_23 -> V_3 ) ;
if ( V_23 -> V_10 ) {
V_23 -> V_4 = F_9 ( V_23 -> V_10 , V_23 -> V_3 ,
V_23 -> V_11 , V_23 -> V_12 ) ;
}
if ( V_23 -> V_43 ) {
V_23 -> V_4 = F_1 ( V_23 -> V_43 ,
V_23 -> V_3 ) ;
}
if ( V_23 -> V_45 ) {
V_23 -> V_4 = F_10 ( sizeof( * V_23 -> V_4 ) ) ;
if ( NULL != V_23 -> V_4 ) {
V_23 -> V_48 = 1 ;
F_27 ( & V_23 -> V_4 [ 0 ] ) = V_23 -> V_45
& V_34 ;
V_23 -> V_4 [ 0 ] . V_11 = V_23 -> V_45 & ~ V_34 ;
F_28 ( & V_23 -> V_4 [ 0 ] ) = V_23 -> V_3 * V_8 ;
}
}
if ( NULL == V_23 -> V_4 ) {
F_12 ( 1 , L_9 ) ;
return - V_37 ;
}
if ( ! V_23 -> V_45 ) {
V_23 -> V_48 = F_29 ( V_47 , V_23 -> V_4 ,
V_23 -> V_3 , V_23 -> V_25 ) ;
if ( 0 == V_23 -> V_48 ) {
F_30 ( V_49
L_10 , V_50 ) ;
F_8 ( V_23 -> V_4 ) ;
V_23 -> V_4 = NULL ;
V_23 -> V_48 = 0 ;
return - V_37 ;
}
}
return 0 ;
}
int F_31 ( struct V_46 * V_47 , struct V_15 * V_23 )
{
F_14 ( V_23 -> V_21 , V_24 ) ;
if ( ! V_23 -> V_48 )
return 0 ;
F_32 ( V_47 , V_23 -> V_4 , V_23 -> V_48 , V_23 -> V_25 ) ;
F_8 ( V_23 -> V_4 ) ;
V_23 -> V_4 = NULL ;
V_23 -> V_48 = 0 ;
return 0 ;
}
int F_33 ( struct V_15 * V_23 )
{
int V_7 ;
F_14 ( V_23 -> V_21 , V_24 ) ;
F_5 ( V_23 -> V_48 ) ;
if ( V_23 -> V_10 ) {
for ( V_7 = 0 ; V_7 < V_23 -> V_3 ; V_7 ++ )
F_34 ( V_23 -> V_10 [ V_7 ] ) ;
F_35 ( V_23 -> V_10 ) ;
V_23 -> V_10 = NULL ;
}
F_8 ( V_23 -> V_43 ) ;
V_23 -> V_43 = NULL ;
if ( V_23 -> V_45 )
V_23 -> V_45 = 0 ;
V_23 -> V_25 = V_51 ;
return 0 ;
}
static void F_36 ( struct V_52 * V_53 )
{
struct V_54 * V_55 = V_53 -> V_56 ;
struct V_57 * V_58 = V_55 -> V_58 ;
F_12 ( 2 , L_11 , V_55 ,
V_55 -> V_59 , V_53 -> V_60 , V_53 -> V_61 ) ;
F_37 ( V_58 ) ;
V_55 -> V_59 ++ ;
F_38 ( V_58 ) ;
}
static void F_39 ( struct V_52 * V_53 )
{
struct V_54 * V_55 = V_53 -> V_56 ;
struct V_57 * V_58 = V_55 -> V_58 ;
struct V_18 * V_19 ;
int V_7 ;
F_12 ( 2 , L_12 , V_55 ,
V_55 -> V_59 , V_53 -> V_60 , V_53 -> V_61 ) ;
F_37 ( V_58 ) ;
if ( ! -- V_55 -> V_59 ) {
F_12 ( 1 , L_13 , V_55 , V_58 ) ;
for ( V_7 = 0 ; V_7 < V_62 ; V_7 ++ ) {
if ( NULL == V_58 -> V_63 [ V_7 ] )
continue;
V_19 = V_58 -> V_63 [ V_7 ] -> V_20 ;
if ( ! V_19 )
continue;
F_14 ( V_19 -> V_21 , V_22 ) ;
if ( V_58 -> V_63 [ V_7 ] -> V_55 != V_55 )
continue;
V_58 -> V_63 [ V_7 ] -> V_55 = NULL ;
V_58 -> V_63 [ V_7 ] -> V_64 = 0 ;
V_58 -> V_65 -> V_66 ( V_58 , V_58 -> V_63 [ V_7 ] ) ;
}
F_35 ( V_55 ) ;
}
F_38 ( V_58 ) ;
return;
}
static int F_40 ( struct V_52 * V_53 , struct V_67 * V_68 )
{
struct V_5 * V_5 ;
F_12 ( 3 , L_14 ,
( unsigned long ) V_68 -> V_69 ,
V_53 -> V_60 , V_53 -> V_61 ) ;
V_5 = F_41 ( V_70 | V_71 ) ;
if ( ! V_5 )
return V_72 ;
F_42 ( V_5 , ( unsigned long ) V_68 -> V_69 ) ;
V_68 -> V_5 = V_5 ;
return 0 ;
}
static struct V_16 * F_43 ( T_1 V_12 )
{
struct V_18 * V_19 ;
struct V_16 * V_73 ;
V_73 = F_44 ( V_12 + sizeof( * V_19 ) , V_36 ) ;
if ( ! V_73 )
return V_73 ;
V_19 = V_73 -> V_20 = ( ( char * ) V_73 ) + V_12 ;
V_19 -> V_21 = V_22 ;
F_15 ( & V_19 -> V_23 ) ;
F_12 ( 1 , L_15 ,
V_50 , V_73 , ( long ) sizeof( * V_73 ) , ( long ) V_12 - sizeof( * V_73 ) ,
V_19 , ( long ) sizeof( * V_19 ) ) ;
return V_73 ;
}
static void * F_45 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
F_5 ( ! V_19 ) ;
F_14 ( V_19 -> V_21 , V_22 ) ;
return V_19 -> V_23 . V_43 ;
}
static int F_46 ( struct V_57 * V_58 ,
struct V_16 * V_73 ,
struct V_74 * V_75 )
{
int V_9 , V_10 ;
T_2 V_76 ;
struct V_18 * V_19 = V_73 -> V_20 ;
F_5 ( ! V_19 ) ;
F_14 ( V_19 -> V_21 , V_22 ) ;
switch ( V_73 -> V_77 ) {
case V_78 :
case V_79 :
if ( 0 == V_73 -> V_64 ) {
V_10 = F_47 ( V_73 -> V_12 ) >> V_35 ;
V_9 = F_23 ( & V_19 -> V_23 ,
V_30 ,
V_10 ) ;
if ( 0 != V_9 )
return V_9 ;
} else if ( V_73 -> V_77 == V_79 ) {
V_9 = F_20 ( & V_19 -> V_23 ,
V_30 ,
V_73 -> V_64 , V_73 -> V_80 ) ;
if ( 0 != V_9 )
return V_9 ;
} else {
V_9 = F_16 ( & V_19 -> V_23 ,
V_30 ,
V_73 -> V_64 , V_73 -> V_80 ) ;
if ( 0 != V_9 )
return V_9 ;
}
break;
case V_81 :
if ( NULL == V_75 )
return - V_40 ;
V_76 = ( T_2 ) ( unsigned long ) V_75 -> V_82 + V_73 -> V_83 ;
V_10 = F_47 ( V_73 -> V_12 ) >> V_35 ;
V_9 = F_25 ( & V_19 -> V_23 , V_30 ,
V_76 , V_10 ) ;
if ( 0 != V_9 )
return V_9 ;
break;
default:
F_17 () ;
}
V_9 = F_26 ( V_58 -> V_47 , & V_19 -> V_23 ) ;
if ( 0 != V_9 )
return V_9 ;
return 0 ;
}
static int F_48 ( struct V_57 * V_58 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
F_5 ( ! V_19 || ! V_19 -> V_23 . V_48 ) ;
F_14 ( V_19 -> V_21 , V_22 ) ;
F_14 ( V_19 -> V_23 . V_21 , V_24 ) ;
F_49 ( V_58 -> V_47 , V_19 -> V_23 . V_4 ,
V_19 -> V_23 . V_48 , V_19 -> V_23 . V_25 ) ;
return 0 ;
}
static int F_50 ( struct V_57 * V_58 ,
struct V_16 * V_17 ,
struct V_52 * V_53 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_54 * V_55 ;
unsigned int V_27 , V_28 , V_12 = 0 , V_7 ;
int V_84 ;
V_84 = - V_40 ;
F_5 ( ! V_19 ) ;
F_14 ( V_19 -> V_21 , V_22 ) ;
for ( V_27 = 0 ; V_27 < V_62 ; V_27 ++ ) {
if ( V_17 == V_58 -> V_63 [ V_27 ] ) {
V_12 = F_47 ( V_58 -> V_63 [ V_27 ] -> V_80 ) ;
break;
}
}
if ( ! V_12 ) {
F_12 ( 1 , L_16 ,
( V_53 -> V_85 << V_35 ) ) ;
goto V_86;
}
V_28 = V_27 ;
V_84 = - V_37 ;
V_55 = F_18 ( sizeof( struct V_54 ) , V_36 ) ;
if ( NULL == V_55 )
goto V_86;
V_12 = 0 ;
for ( V_7 = V_27 ; V_7 <= V_28 ; V_7 ++ ) {
if ( NULL == V_58 -> V_63 [ V_7 ] )
continue;
V_58 -> V_63 [ V_7 ] -> V_55 = V_55 ;
V_58 -> V_63 [ V_7 ] -> V_64 = V_53 -> V_60 + V_12 ;
V_12 += F_47 ( V_58 -> V_63 [ V_7 ] -> V_80 ) ;
}
V_55 -> V_59 = 1 ;
V_55 -> V_58 = V_58 ;
V_53 -> V_87 = & V_88 ;
V_53 -> V_89 |= V_90 | V_91 ;
V_53 -> V_89 &= ~ V_92 ;
V_53 -> V_56 = V_55 ;
F_12 ( 1 , L_17 ,
V_55 , V_58 , V_53 -> V_60 , V_53 -> V_61 , V_53 -> V_85 , V_27 , V_28 ) ;
V_84 = 0 ;
V_86:
return V_84 ;
}
void * F_51 ( T_1 V_12 )
{
struct V_57 V_58 ;
V_58 . V_93 = & V_94 ;
V_58 . V_95 = V_12 ;
return F_52 ( & V_58 ) ;
}
void F_53 ( struct V_57 * V_58 ,
const struct V_96 * V_65 ,
struct V_46 * V_47 ,
T_3 * V_97 ,
enum V_98 type ,
enum V_99 V_100 ,
unsigned int V_95 ,
void * V_20 ,
struct V_101 * V_102 )
{
F_54 ( V_58 , V_65 , V_47 , V_97 , type , V_100 , V_95 ,
V_20 , & V_94 , V_102 ) ;
}
