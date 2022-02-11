static inline int F_1 ( struct V_1 * V_2 )
{
if ( V_2 == NULL || V_2 -> V_3 != V_4 )
return - V_5 ;
if ( V_2 -> V_6 == NULL || V_2 -> V_6 -> V_7 == NULL )
return - V_5 ;
if ( V_2 -> V_8 == 0 )
return V_9 ;
if ( V_2 -> V_10 == NULL || V_2 -> V_10 -> V_11 == NULL
|| V_2 -> V_12 == NULL )
return V_9 ;
return 0 ;
}
static int F_2 ( void * V_2 )
{
int V_13 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
V_13 = F_3 ( V_14 ) ;
if ( V_13 )
return V_13 ;
if ( ( V_14 -> V_8 == 0 )
|| F_4 ( V_14 -> V_15 ) )
return V_9 ;
V_13 = F_5 ( V_14 ) ;
if ( V_13 ) {
V_14 -> V_8 = 0 ;
return V_9 ;
}
V_13 = F_6 ( V_14 ) ;
if ( V_13 ) {
F_7 ( V_14 -> V_10 ) ;
V_14 -> V_10 = NULL ;
V_14 -> V_8 = 0 ;
return V_9 ;
}
return 0 ;
}
static int F_8 ( void * V_2 )
{
struct V_16 * V_17 ;
int V_13 = 0 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 == 0 || V_13 == V_9 ) {
V_17 = V_14 -> V_6 ;
if ( V_17 -> V_7 -> V_18 == NULL )
return - V_5 ;
V_13 = V_17 -> V_7 -> V_18 ( V_17 ) ;
F_9 ( L_1 ) ;
}
return V_13 ;
}
static int F_10 ( void * V_2 )
{
struct V_16 * V_17 ;
int V_13 = 0 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 == 0 || V_13 == V_9 ) {
V_17 = V_14 -> V_6 ;
if ( V_17 -> V_7 -> V_19 == NULL )
return - V_5 ;
V_13 = V_17 -> V_7 -> V_19 ( V_17 ) ;
}
return V_13 ;
}
static int F_11 ( void * V_2 )
{
struct V_16 * V_17 ;
struct V_20 * V_12 ;
int V_13 = 0 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 == 0 || V_13 == V_9 ) {
V_17 = V_14 -> V_6 ;
if ( V_17 -> V_7 -> V_21 == NULL )
return - V_5 ;
if( V_17 -> V_7 -> V_21 ( V_17 ) ) {
F_12 ( L_2 ) ;
V_17 -> V_7 -> V_19 ( V_17 ) ;
return - V_5 ; ;
}
if ( V_13 == V_9 )
return V_9 ;
}
V_13 = F_13 ( V_14 ) ;
if ( V_13 )
goto V_22;
V_12 = V_14 -> V_12 ;
if ( V_12 -> V_23 == NULL ||
V_12 -> V_23 ( V_12 ) )
goto V_22;
return 0 ;
V_22:
V_14 -> V_8 = 0 ;
F_7 ( V_14 -> V_12 ) ;
F_7 ( V_14 -> V_10 ) ;
V_14 -> V_10 = NULL ;
V_14 -> V_12 = NULL ;
return V_9 ;
}
static int F_14 ( void * V_2 )
{
struct V_20 * V_12 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 == 0 ) {
V_12 = V_14 -> V_12 ;
if ( V_12 -> V_24 != NULL )
V_12 -> V_24 ( V_12 ) ;
F_15 ( V_14 ) ;
}
return 0 ;
}
static bool F_16 ( void * V_2 )
{
return false ;
}
static int F_17 ( void * V_2 )
{
return 0 ;
}
static int F_18 ( void * V_2 )
{
return 0 ;
}
int F_19 ( void * V_2 , T_1 V_25 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
if ( V_10 -> V_11 -> V_27 == NULL ) {
F_9 ( L_3 , V_28 ) ;
return 0 ;
}
return V_10 -> V_11 -> V_27 ( V_10 , & V_25 ) ;
}
static int F_20 ( void * V_2 ,
enum V_29 V_30 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
if ( V_10 -> V_11 -> V_31 == NULL ) {
F_9 ( L_3 , V_28 ) ;
return 0 ;
}
return V_10 -> V_11 -> V_31 ( V_10 ,
V_30 == V_32 ? true : false ) ;
}
static int F_21 ( void * V_2 )
{
struct V_20 * V_12 ;
struct V_33 V_34 = { { 0 } } ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_12 = V_14 -> V_12 ;
F_22 ( V_12 , V_35 , & V_34 ) ;
return 0 ;
}
static int F_23 ( void * V_2 )
{
struct V_20 * V_12 ;
struct V_33 V_34 = { { 0 } } ;
struct V_16 * V_17 ;
int V_13 , V_36 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
V_36 = F_1 ( V_14 ) ;
if ( V_36 != 0 && V_36 != V_9 )
return V_36 ;
V_17 = V_14 -> V_6 ;
if ( V_17 -> V_7 -> V_21 == NULL )
return - V_5 ;
V_13 = V_17 -> V_7 -> V_21 ( V_17 ) ;
if ( V_13 ) {
F_12 ( L_2 ) ;
V_17 -> V_7 -> V_19 ( V_17 ) ;
return V_13 ;
}
if ( V_36 == V_9 )
return V_36 ;
V_12 = V_14 -> V_12 ;
F_22 ( V_12 , V_37 , & V_34 ) ;
return 0 ;
}
static int F_24 ( void * V_2 )
{
return 0 ;
}
static int F_25 ( void * V_2 )
{
return 0 ;
}
static int F_26 ( void * V_2 ,
enum V_38 V_39 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
if ( V_10 -> V_11 -> V_40 == NULL ) {
F_9 ( L_3 , V_28 ) ;
return 0 ;
}
V_10 -> V_11 -> V_40 ( V_10 , V_39 ) ;
return 0 ;
}
static enum V_38 F_27 (
void * V_2 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
return V_10 -> V_41 ;
}
static int F_28 ( void * V_2 , bool V_42 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
if ( V_10 -> V_11 -> V_43 == NULL ) {
F_9 ( L_3 , V_28 ) ;
return 0 ;
}
return V_10 -> V_11 -> V_43 ( V_10 , V_42 ) ;
}
static int F_29 ( void * V_2 , bool V_42 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
if ( V_10 -> V_11 -> V_44 == NULL ) {
F_9 ( L_3 , V_28 ) ;
return 0 ;
}
return V_10 -> V_11 -> V_44 ( V_10 , V_42 ) ;
}
static int F_30 ( void * V_2 , bool V_45 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
if ( V_10 -> V_11 -> V_46 == NULL ) {
F_9 ( L_3 , V_28 ) ;
return 0 ;
}
return V_10 -> V_11 -> V_46 ( V_10 , V_45 ) ;
}
static int F_31 ( void * V_2 , bool V_45 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
if ( V_10 -> V_11 -> V_47 == NULL ) {
F_9 ( L_3 , V_28 ) ;
return 0 ;
}
return V_10 -> V_11 -> V_47 ( V_10 , V_45 ) ;
}
static enum V_48 F_32 ( enum V_49 V_30 )
{
switch ( V_30 ) {
case V_50 :
return V_51 ;
case V_52 :
return V_53 ;
case V_54 :
return V_55 ;
default:
return V_56 ;
}
}
static int F_33 ( void * V_2 , enum V_57 V_58 ,
void * V_59 , void * V_60 )
{
int V_13 = 0 ;
struct V_33 V_61 = { { 0 } } ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
switch ( V_58 ) {
case V_62 :
V_13 = F_22 ( V_14 -> V_12 , V_58 , & V_61 ) ;
break;
case V_63 :
{
enum V_49 V_64 ;
if ( V_59 == NULL )
return - V_5 ;
V_64 = * ( unsigned long * ) V_59 ;
V_61 . V_65 = F_32 ( V_64 ) ;
V_13 = F_22 ( V_14 -> V_12 , V_58 , & V_61 ) ;
break;
}
case V_66 :
V_13 = F_22 ( V_14 -> V_12 , V_58 , & V_61 ) ;
break;
case V_67 :
V_13 = F_22 ( V_14 -> V_12 , V_58 , & V_61 ) ;
break;
default:
break;
}
return V_13 ;
}
static enum V_49 F_34 ( void * V_2 )
{
struct V_26 * V_10 ;
struct V_68 * V_30 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
if ( V_10 -> V_69 == NULL )
return - V_5 ;
V_30 = V_10 -> V_69 ;
switch ( V_30 -> V_70 . V_71 ) {
case V_51 :
return V_50 ;
case V_53 :
return V_52 ;
case V_55 :
return V_54 ;
default:
if ( V_30 -> V_70 . V_72 & V_73 )
return V_74 ;
else
return V_75 ;
}
}
static int F_35 ( void * V_2 , T_1 V_76 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
if ( V_10 -> V_11 -> V_77 == NULL ) {
F_9 ( L_3 , V_28 ) ;
return 0 ;
}
return V_10 -> V_11 -> V_77 ( V_10 , V_76 ) ;
}
static int F_36 ( void * V_2 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
if ( V_10 -> V_11 -> V_78 == NULL ) {
F_9 ( L_3 , V_28 ) ;
return 0 ;
}
return V_10 -> V_11 -> V_78 ( V_10 ) ;
}
static int F_37 ( void * V_2 , T_1 V_79 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
if ( V_10 -> V_11 -> V_80 == NULL ) {
F_9 ( L_3 , V_28 ) ;
return 0 ;
}
return V_10 -> V_11 -> V_80 ( V_10 , V_79 ) ;
}
static int F_38 ( void * V_2 , T_1 * V_81 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
if ( V_10 -> V_11 -> V_82 == NULL ) {
F_9 ( L_3 , V_28 ) ;
return 0 ;
}
return V_10 -> V_11 -> V_82 ( V_10 , V_81 ) ;
}
static int F_39 ( void * V_2 , T_1 * V_83 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
if ( V_10 -> V_11 -> V_84 == NULL )
return - V_5 ;
return V_10 -> V_11 -> V_84 ( V_10 , V_83 ) ;
}
static int F_40 ( void * V_2 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
if ( V_10 -> V_11 -> V_85 == NULL ) {
F_9 ( L_3 , V_28 ) ;
return 0 ;
}
return V_10 -> V_11 -> V_85 ( V_10 ) ;
}
static int F_41 ( void * V_2 ,
struct V_86 * V_61 )
{
struct V_26 * V_10 ;
int V_87 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
if ( V_10 -> V_64 == NULL )
return - V_5 ;
V_61 -> V_88 = V_10 -> V_89 ;
for ( V_87 = 0 ; V_87 < V_10 -> V_89 ; V_87 ++ ) {
struct V_68 * V_30 = (struct V_68 * )
( ( unsigned long ) V_10 -> V_64 + V_87 * V_10 -> V_90 ) ;
switch ( V_30 -> V_70 . V_71 ) {
case V_51 :
V_61 -> V_91 [ V_87 ] = V_50 ;
break;
case V_53 :
V_61 -> V_91 [ V_87 ] = V_52 ;
break;
case V_55 :
V_61 -> V_91 [ V_87 ] = V_54 ;
break;
default:
if ( V_30 -> V_70 . V_72 & V_73 )
V_61 -> V_91 [ V_87 ] = V_74 ;
else
V_61 -> V_91 [ V_87 ] = V_75 ;
}
}
return 0 ;
}
static int F_42 ( void * V_2 , char * * V_92 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
if ( ! V_10 -> V_93 )
return - V_5 ;
* V_92 = ( char * ) V_10 -> V_93 ;
return V_10 -> V_94 ;
}
static int F_43 ( void * V_2 , const char * V_95 , T_2 V_96 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
if ( ! V_10 -> V_97 ) {
V_10 -> V_97 = F_44 ( V_10 -> V_93 ,
V_10 -> V_94 ,
V_98 ) ;
if ( ! V_10 -> V_97 )
return - V_99 ;
}
memcpy ( V_10 -> V_97 , V_95 , V_96 ) ;
V_10 -> V_93 = V_10 -> V_97 ;
return F_45 ( V_2 ) ;
}
static int F_46 ( void * V_2 ,
enum V_100 type , T_1 V_101 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
if ( V_10 -> V_11 -> V_102 == NULL ) {
F_9 ( L_3 , V_28 ) ;
return 0 ;
}
return V_10 -> V_11 -> V_102 ( V_10 , type , V_101 ) ;
}
static int F_47 ( void * V_2 ,
enum V_100 type , char * V_95 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
if ( V_10 -> V_11 -> V_103 == NULL ) {
F_9 ( L_3 , V_28 ) ;
return 0 ;
}
return V_10 -> V_11 -> V_103 ( V_10 , type , V_95 ) ;
}
static int F_48 ( void * V_2 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
if ( V_10 -> V_11 -> V_104 == NULL ) {
F_9 ( L_3 , V_28 ) ;
return 0 ;
}
return V_10 -> V_11 -> V_104 ( V_10 ) ;
}
static int F_49 ( void * V_2 , T_1 V_105 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
if ( V_10 -> V_11 -> V_106 == NULL ) {
F_9 ( L_3 , V_28 ) ;
return 0 ;
}
return V_10 -> V_11 -> V_106 ( V_10 , V_105 ) ;
}
static int F_50 ( void * V_2 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
if ( V_10 -> V_11 -> V_107 == NULL ) {
F_9 ( L_3 , V_28 ) ;
return 0 ;
}
return V_10 -> V_11 -> V_107 ( V_10 ) ;
}
static int F_51 ( void * V_2 , T_1 V_105 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
if ( V_10 -> V_11 -> V_108 == NULL ) {
F_9 ( L_3 , V_28 ) ;
return 0 ;
}
return V_10 -> V_11 -> V_108 ( V_10 , V_105 ) ;
}
static int F_52 ( void * V_2 , int V_109 , T_3 * V_105 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
if ( V_10 -> V_11 -> V_110 == NULL ) {
F_9 ( L_3 , V_28 ) ;
return 0 ;
}
return V_10 -> V_11 -> V_110 ( V_10 , V_109 , V_105 ) ;
}
static struct V_111 *
F_53 ( void * V_2 , unsigned V_109 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return NULL ;
V_10 = V_14 -> V_10 ;
if ( V_10 && V_109 < V_10 -> V_112 )
return & V_10 -> V_113 [ V_109 ] ;
return NULL ;
}
int F_54 ( struct V_114 * V_115 ,
void * * V_2 )
{
struct V_1 * V_116 ;
if ( V_115 == NULL || V_2 == NULL )
return - V_5 ;
V_116 = F_55 ( sizeof( struct V_1 ) , V_98 ) ;
if ( V_116 == NULL )
return - V_99 ;
V_116 -> V_3 = V_4 ;
V_116 -> V_117 = V_115 -> V_117 ;
V_116 -> V_118 = V_115 -> V_118 ;
V_116 -> V_8 = V_115 -> V_8 ;
V_116 -> V_119 = V_115 -> V_119 ;
V_116 -> V_15 = V_115 -> V_15 ;
* V_2 = V_116 ;
return 0 ;
}
int F_56 ( void * V_2 )
{
struct V_1 * V_116 = (struct V_1 * ) V_2 ;
if ( V_116 -> V_8 ) {
F_7 ( V_116 -> V_12 ) ;
F_7 ( V_116 -> V_10 ) ;
V_116 -> V_10 = NULL ;
V_116 -> V_12 = NULL ;
}
F_7 ( V_116 -> V_6 ) ;
V_116 -> V_6 = NULL ;
F_7 ( V_116 ) ;
V_116 = NULL ;
return 0 ;
}
int F_45 ( void * V_2 )
{
struct V_1 * V_116 = (struct V_1 * ) V_2 ;
struct V_20 * V_12 ;
struct V_33 V_34 = { { 0 } } ;
int V_13 ;
if ( F_4 ( V_116 -> V_6 -> V_15 ) )
return V_9 ;
V_13 = F_1 ( V_116 ) ;
if ( V_13 != 0 )
return V_13 ;
V_13 = F_14 ( V_2 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_13 ( V_116 ) ;
if ( V_13 )
return V_9 ;
V_12 = V_116 -> V_12 ;
if ( V_12 -> V_23 == NULL )
return V_9 ;
V_13 = V_12 -> V_23 ( V_12 ) ;
if ( V_13 )
return V_13 ;
return F_22 ( V_12 , V_66 , & V_34 ) ;
}
int F_57 ( void * V_2 ,
const struct V_120 * V_121 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
F_58 ( V_10 , V_121 ) ;
return 0 ;
}
int F_59 ( void * V_2 ,
struct V_122 * V_60 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
if ( V_60 == NULL )
return - V_5 ;
return F_60 ( V_10 , V_60 ) ;
}
int F_61 ( void * V_2 ,
struct V_123 * V_124 )
{
struct V_122 V_125 ;
struct V_126 V_127 ;
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
F_60 ( V_10 , & V_125 ) ;
if ( F_62 ( V_10 -> V_128 . V_129 , V_130 ) ) {
if ( 0 != F_63 ( V_10 , & V_10 -> V_69 -> V_131 , & V_127 , V_132 ) )
F_64 ( 0 , L_4 , return -1 ) ;
} else {
if ( 0 != F_63 ( V_10 , & V_10 -> V_69 -> V_131 , & V_127 , V_133 ) )
F_64 ( 0 , L_5 , return -1 ) ;
}
V_124 -> V_134 = V_127 . V_135 ;
V_124 -> V_136 = V_127 . V_137 ;
V_124 -> V_138 = V_127 . V_139 ;
V_124 -> V_140 = V_127 . V_141 ;
V_124 -> V_142 = V_127 . V_142 ;
V_124 -> V_143 = V_127 . V_143 ;
V_124 -> V_144 = V_127 . V_137 ;
V_124 -> V_145 = V_127 . V_135 ;
V_124 -> V_146 = V_125 . V_39 ;
if ( 0 == F_65 ( V_10 , & V_10 -> V_69 -> V_131 , & V_127 ) ) {
V_124 -> V_144 = V_127 . V_137 ;
V_124 -> V_145 = V_127 . V_135 ;
}
return 0 ;
}
int F_66 ( void * V_2 , enum V_147 type , struct V_148 * V_124 )
{
int V_149 = - 1 ;
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
if ( V_124 == NULL )
return - V_5 ;
V_149 = F_67 ( V_10 , type , V_124 ) ;
return V_149 ;
}
int F_68 ( void * V_2 ,
struct V_122 * V_124 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
if ( V_124 == NULL )
return - V_5 ;
if ( F_62 ( V_10 -> V_128 . V_129 , V_150 ) )
V_13 = F_69 ( V_10 , V_124 ) ;
return V_13 ;
}
