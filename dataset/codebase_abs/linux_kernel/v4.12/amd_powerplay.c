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
V_30 == V_32 ) ;
}
static int F_21 ( void * V_2 )
{
struct V_20 * V_12 ;
struct V_33 V_34 = { { 0 } } ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 == V_9 )
return 0 ;
else if ( V_13 != 0 )
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
return 0 ;
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
F_27 ( & V_14 -> V_41 ) ;
V_10 -> V_11 -> V_40 ( V_10 , V_39 ) ;
F_28 ( & V_14 -> V_41 ) ;
return 0 ;
}
static enum V_38 F_29 (
void * V_2 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
enum V_38 V_39 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
F_27 ( & V_14 -> V_41 ) ;
V_39 = V_10 -> V_42 ;
F_28 ( & V_14 -> V_41 ) ;
return V_39 ;
}
static int F_30 ( void * V_2 , bool V_43 )
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
F_27 ( & V_14 -> V_41 ) ;
V_13 = V_10 -> V_11 -> V_44 ( V_10 , V_43 ) ;
F_28 ( & V_14 -> V_41 ) ;
return V_13 ;
}
static int F_31 ( void * V_2 , bool V_43 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
if ( V_10 -> V_11 -> V_45 == NULL ) {
F_9 ( L_3 , V_28 ) ;
return 0 ;
}
F_27 ( & V_14 -> V_41 ) ;
V_13 = V_10 -> V_11 -> V_45 ( V_10 , V_43 ) ;
F_28 ( & V_14 -> V_41 ) ;
return V_13 ;
}
static int F_32 ( void * V_2 , bool V_46 )
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
F_27 ( & V_14 -> V_41 ) ;
V_13 = V_10 -> V_11 -> V_47 ( V_10 , V_46 ) ;
F_28 ( & V_14 -> V_41 ) ;
return V_13 ;
}
static int F_33 ( void * V_2 , bool V_46 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
if ( V_10 -> V_11 -> V_48 == NULL ) {
F_9 ( L_3 , V_28 ) ;
return 0 ;
}
F_27 ( & V_14 -> V_41 ) ;
V_13 = V_10 -> V_11 -> V_48 ( V_10 , V_46 ) ;
F_28 ( & V_14 -> V_41 ) ;
return V_13 ;
}
static enum V_49 F_34 ( enum V_50 V_30 )
{
switch ( V_30 ) {
case V_51 :
return V_52 ;
case V_53 :
return V_54 ;
case V_55 :
return V_56 ;
default:
return V_57 ;
}
}
static int F_35 ( void * V_2 , enum V_58 V_59 ,
void * V_60 , void * V_61 )
{
int V_13 = 0 ;
struct V_33 V_62 = { { 0 } } ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
F_27 ( & V_14 -> V_41 ) ;
switch ( V_59 ) {
case V_63 :
V_13 = F_22 ( V_14 -> V_12 , V_59 , & V_62 ) ;
break;
case V_64 :
{
enum V_50 V_65 ;
if ( V_60 == NULL ) {
V_13 = - V_5 ;
break;
}
V_65 = * ( unsigned long * ) V_60 ;
V_62 . V_66 = F_34 ( V_65 ) ;
V_13 = F_22 ( V_14 -> V_12 , V_59 , & V_62 ) ;
break;
}
case V_67 :
V_13 = F_22 ( V_14 -> V_12 , V_59 , & V_62 ) ;
break;
case V_68 :
V_13 = F_22 ( V_14 -> V_12 , V_59 , & V_62 ) ;
break;
default:
break;
}
F_28 ( & V_14 -> V_41 ) ;
return V_13 ;
}
static enum V_50 F_36 ( void * V_2 )
{
struct V_26 * V_10 ;
struct V_69 * V_30 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
enum V_50 V_70 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
if ( V_10 -> V_71 == NULL )
return - V_5 ;
F_27 ( & V_14 -> V_41 ) ;
V_30 = V_10 -> V_71 ;
switch ( V_30 -> V_72 . V_73 ) {
case V_52 :
V_70 = V_51 ;
break;
case V_54 :
V_70 = V_53 ;
break;
case V_56 :
V_70 = V_55 ;
break;
default:
if ( V_30 -> V_72 . V_74 & V_75 )
V_70 = V_76 ;
else
V_70 = V_77 ;
break;
}
F_28 ( & V_14 -> V_41 ) ;
return V_70 ;
}
static int F_37 ( void * V_2 , T_1 V_78 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
if ( V_10 -> V_11 -> V_79 == NULL ) {
F_9 ( L_3 , V_28 ) ;
return 0 ;
}
F_27 ( & V_14 -> V_41 ) ;
V_13 = V_10 -> V_11 -> V_79 ( V_10 , V_78 ) ;
F_28 ( & V_14 -> V_41 ) ;
return V_13 ;
}
static int F_38 ( void * V_2 )
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
F_27 ( & V_14 -> V_41 ) ;
V_13 = V_10 -> V_11 -> V_80 ( V_10 ) ;
F_28 ( & V_14 -> V_41 ) ;
return V_13 ;
}
static int F_39 ( void * V_2 , T_1 V_81 )
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
F_27 ( & V_14 -> V_41 ) ;
V_13 = V_10 -> V_11 -> V_82 ( V_10 , V_81 ) ;
F_28 ( & V_14 -> V_41 ) ;
return V_13 ;
}
static int F_40 ( void * V_2 , T_1 * V_83 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
if ( V_10 -> V_11 -> V_84 == NULL ) {
F_9 ( L_3 , V_28 ) ;
return 0 ;
}
F_27 ( & V_14 -> V_41 ) ;
V_13 = V_10 -> V_11 -> V_84 ( V_10 , V_83 ) ;
F_28 ( & V_14 -> V_41 ) ;
return V_13 ;
}
static int F_41 ( void * V_2 , T_1 * V_85 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
if ( V_10 -> V_11 -> V_86 == NULL )
return - V_5 ;
F_27 ( & V_14 -> V_41 ) ;
V_13 = V_10 -> V_11 -> V_86 ( V_10 , V_85 ) ;
F_28 ( & V_14 -> V_41 ) ;
return V_13 ;
}
static int F_42 ( void * V_2 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
if ( V_10 -> V_11 -> V_87 == NULL ) {
F_9 ( L_3 , V_28 ) ;
return 0 ;
}
F_27 ( & V_14 -> V_41 ) ;
V_13 = V_10 -> V_11 -> V_87 ( V_10 ) ;
F_28 ( & V_14 -> V_41 ) ;
return V_13 ;
}
static int F_43 ( void * V_2 ,
struct V_88 * V_62 )
{
struct V_26 * V_10 ;
int V_89 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
if ( V_10 -> V_65 == NULL )
return - V_5 ;
F_27 ( & V_14 -> V_41 ) ;
V_62 -> V_90 = V_10 -> V_91 ;
for ( V_89 = 0 ; V_89 < V_10 -> V_91 ; V_89 ++ ) {
struct V_69 * V_30 = (struct V_69 * )
( ( unsigned long ) V_10 -> V_65 + V_89 * V_10 -> V_92 ) ;
switch ( V_30 -> V_72 . V_73 ) {
case V_52 :
V_62 -> V_93 [ V_89 ] = V_51 ;
break;
case V_54 :
V_62 -> V_93 [ V_89 ] = V_53 ;
break;
case V_56 :
V_62 -> V_93 [ V_89 ] = V_55 ;
break;
default:
if ( V_30 -> V_72 . V_74 & V_75 )
V_62 -> V_93 [ V_89 ] = V_76 ;
else
V_62 -> V_93 [ V_89 ] = V_77 ;
}
}
F_28 ( & V_14 -> V_41 ) ;
return 0 ;
}
static int F_44 ( void * V_2 , char * * V_94 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
int V_95 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
if ( ! V_10 -> V_96 )
return - V_5 ;
F_27 ( & V_14 -> V_41 ) ;
* V_94 = ( char * ) V_10 -> V_96 ;
V_95 = V_10 -> V_97 ;
F_28 ( & V_14 -> V_41 ) ;
return V_95 ;
}
static int F_45 ( void * V_2 , const char * V_98 , T_2 V_95 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
F_27 ( & V_14 -> V_41 ) ;
if ( ! V_10 -> V_99 ) {
V_10 -> V_99 = F_46 ( V_10 -> V_96 ,
V_10 -> V_97 ,
V_100 ) ;
if ( ! V_10 -> V_99 ) {
F_28 ( & V_14 -> V_41 ) ;
return - V_101 ;
}
}
memcpy ( V_10 -> V_99 , V_98 , V_95 ) ;
V_10 -> V_96 = V_10 -> V_99 ;
F_28 ( & V_14 -> V_41 ) ;
V_13 = F_47 ( V_2 ) ;
if ( V_13 )
return V_13 ;
if ( V_10 -> V_11 -> V_102 ) {
V_13 = V_10 -> V_11 -> V_102 ( V_10 , false ) ;
if ( V_13 )
return V_13 ;
}
return 0 ;
}
static int F_48 ( void * V_2 ,
enum V_103 type , T_1 V_104 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
if ( V_10 -> V_11 -> V_105 == NULL ) {
F_9 ( L_3 , V_28 ) ;
return 0 ;
}
F_27 ( & V_14 -> V_41 ) ;
V_10 -> V_11 -> V_105 ( V_10 , type , V_104 ) ;
F_28 ( & V_14 -> V_41 ) ;
return V_13 ;
}
static int F_49 ( void * V_2 ,
enum V_103 type , char * V_98 )
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
F_27 ( & V_14 -> V_41 ) ;
V_13 = V_10 -> V_11 -> V_106 ( V_10 , type , V_98 ) ;
F_28 ( & V_14 -> V_41 ) ;
return V_13 ;
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
F_27 ( & V_14 -> V_41 ) ;
V_13 = V_10 -> V_11 -> V_107 ( V_10 ) ;
F_28 ( & V_14 -> V_41 ) ;
return V_13 ;
}
static int F_51 ( void * V_2 , T_1 V_108 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
if ( V_10 -> V_11 -> V_109 == NULL ) {
F_9 ( L_3 , V_28 ) ;
return 0 ;
}
F_27 ( & V_14 -> V_41 ) ;
V_13 = V_10 -> V_11 -> V_109 ( V_10 , V_108 ) ;
F_28 ( & V_14 -> V_41 ) ;
return V_13 ;
}
static int F_52 ( void * V_2 )
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
F_27 ( & V_14 -> V_41 ) ;
V_13 = V_10 -> V_11 -> V_110 ( V_10 ) ;
F_28 ( & V_14 -> V_41 ) ;
return V_13 ;
}
static int F_53 ( void * V_2 , T_1 V_108 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
if ( V_10 -> V_11 -> V_111 == NULL ) {
F_9 ( L_3 , V_28 ) ;
return 0 ;
}
F_27 ( & V_14 -> V_41 ) ;
V_13 = V_10 -> V_11 -> V_111 ( V_10 , V_108 ) ;
F_28 ( & V_14 -> V_41 ) ;
return V_13 ;
}
static int F_54 ( void * V_2 , int V_112 ,
void * V_108 , int * V_95 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
if ( V_10 -> V_11 -> V_113 == NULL ) {
F_9 ( L_3 , V_28 ) ;
return 0 ;
}
F_27 ( & V_14 -> V_41 ) ;
V_13 = V_10 -> V_11 -> V_113 ( V_10 , V_112 , V_108 , V_95 ) ;
F_28 ( & V_14 -> V_41 ) ;
return V_13 ;
}
static struct V_114 *
F_55 ( void * V_2 , unsigned V_112 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return NULL ;
V_10 = V_14 -> V_10 ;
if ( V_10 && V_112 < V_10 -> V_115 )
return & V_10 -> V_116 [ V_112 ] ;
return NULL ;
}
static int F_56 ( void * V_2 ,
struct V_117 * V_118 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
if ( ! V_118 || F_1 ( V_14 ) )
return - V_5 ;
V_10 = V_14 -> V_10 ;
if ( V_10 -> V_11 -> V_119 == NULL ) {
F_9 ( L_3 , V_28 ) ;
return 0 ;
}
if ( V_118 -> type == V_120 ) {
V_10 -> V_121 = V_10 -> V_122 ;
return V_10 -> V_11 -> V_119 ( V_10 ,
& V_10 -> V_121 ) ;
} else if ( V_118 -> type == V_123 ) {
V_10 -> V_124 =
V_10 -> V_125 ;
return V_10 -> V_11 -> V_119 ( V_10 ,
& V_10 -> V_124 ) ;
} else
return - V_5 ;
}
static int F_57 ( void * V_2 ,
struct V_117 * V_126 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
if ( ! V_126 || F_1 ( V_14 ) )
return - V_5 ;
V_10 = V_14 -> V_10 ;
if ( V_126 -> type == V_120 )
memcpy ( V_126 , & V_10 -> V_121 ,
sizeof( struct V_117 ) ) ;
else if ( V_126 -> type == V_123 )
memcpy ( V_126 , & V_10 -> V_124 ,
sizeof( struct V_117 ) ) ;
else
return - V_5 ;
return 0 ;
}
static int F_58 ( void * V_2 ,
struct V_117 * V_118 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = - 1 ;
if ( ! V_118 || F_1 ( V_14 ) )
return - V_5 ;
V_10 = V_14 -> V_10 ;
if ( V_10 -> V_11 -> V_119 == NULL ) {
F_9 ( L_3 , V_28 ) ;
return 0 ;
}
if ( V_118 -> V_127 ||
V_118 -> V_128 ||
V_118 -> V_129 ||
V_118 -> V_130 ||
V_118 -> V_131 ) {
if ( V_118 -> type == V_120 )
memcpy ( & V_10 -> V_121 , V_118 ,
sizeof( struct V_117 ) ) ;
else if ( V_118 -> type == V_123 )
memcpy ( & V_10 -> V_124 , V_118 ,
sizeof( struct V_117 ) ) ;
else
return - V_5 ;
if ( V_118 -> type == V_10 -> V_132 )
V_13 = V_10 -> V_11 -> V_119 (
V_10 ,
V_118 ) ;
} else {
switch ( V_118 -> type ) {
case V_120 :
V_13 = V_10 -> V_11 -> V_119 (
V_10 ,
& V_10 -> V_121 ) ;
break;
case V_123 :
V_13 = V_10 -> V_11 -> V_119 (
V_10 ,
& V_10 -> V_124 ) ;
break;
default:
return - V_5 ;
}
}
if ( ! V_13 )
V_10 -> V_132 = V_118 -> type ;
return 0 ;
}
static int F_59 ( void * V_2 ,
enum V_133 type )
{
struct V_26 * V_10 ;
struct V_117 V_118 = { 0 } ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
if ( F_1 ( V_14 ) )
return - V_5 ;
V_10 = V_14 -> V_10 ;
if ( V_10 -> V_132 != type ) {
V_118 . type = type ;
F_58 ( V_2 , & V_118 ) ;
}
return 0 ;
}
int F_60 ( struct V_134 * V_135 ,
void * * V_2 )
{
struct V_1 * V_136 ;
if ( V_135 == NULL || V_2 == NULL )
return - V_5 ;
V_136 = F_61 ( sizeof( struct V_1 ) , V_100 ) ;
if ( V_136 == NULL )
return - V_101 ;
V_136 -> V_3 = V_4 ;
V_136 -> V_137 = V_135 -> V_137 ;
V_136 -> V_138 = V_135 -> V_138 ;
V_136 -> V_8 = V_135 -> V_8 ;
V_136 -> V_139 = V_135 -> V_139 ;
V_136 -> V_15 = V_135 -> V_15 ;
F_62 ( & V_136 -> V_41 ) ;
* V_2 = V_136 ;
return 0 ;
}
int F_63 ( void * V_2 )
{
struct V_1 * V_136 = (struct V_1 * ) V_2 ;
if ( V_136 -> V_8 ) {
F_7 ( V_136 -> V_12 ) ;
F_7 ( V_136 -> V_10 ) ;
V_136 -> V_10 = NULL ;
V_136 -> V_12 = NULL ;
}
F_7 ( V_136 -> V_6 ) ;
V_136 -> V_6 = NULL ;
F_7 ( V_136 ) ;
V_136 = NULL ;
return 0 ;
}
int F_47 ( void * V_2 )
{
struct V_1 * V_136 = (struct V_1 * ) V_2 ;
struct V_20 * V_12 ;
struct V_33 V_34 = { { 0 } } ;
int V_13 ;
if ( F_4 ( V_136 -> V_6 -> V_15 ) )
return V_9 ;
V_13 = F_1 ( V_136 ) ;
if ( V_13 != 0 )
return V_13 ;
V_13 = F_14 ( V_2 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_13 ( V_136 ) ;
if ( V_13 )
return V_9 ;
V_12 = V_136 -> V_12 ;
if ( V_12 -> V_23 == NULL )
return V_9 ;
V_13 = V_12 -> V_23 ( V_12 ) ;
if ( V_13 )
return V_13 ;
return F_22 ( V_12 , V_67 , & V_34 ) ;
}
int F_64 ( void * V_2 ,
const struct V_140 * V_141 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
F_27 ( & V_14 -> V_41 ) ;
F_65 ( V_10 , V_141 ) ;
F_28 ( & V_14 -> V_41 ) ;
return 0 ;
}
int F_66 ( void * V_2 ,
struct V_142 * V_61 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
if ( V_61 == NULL )
return - V_5 ;
F_27 ( & V_14 -> V_41 ) ;
V_13 = F_67 ( V_10 , V_61 ) ;
F_28 ( & V_14 -> V_41 ) ;
return V_13 ;
}
int F_68 ( void * V_2 ,
struct V_143 * V_144 )
{
struct V_142 V_145 ;
struct V_146 V_147 ;
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
F_27 ( & V_14 -> V_41 ) ;
F_67 ( V_10 , & V_145 ) ;
if ( F_69 ( V_10 -> V_148 . V_149 ,
V_150 ) )
V_13 = F_70 ( V_10 , & V_10 -> V_71 -> V_151 ,
& V_147 , V_152 ) ;
else
V_13 = F_70 ( V_10 , & V_10 -> V_71 -> V_151 ,
& V_147 , V_153 ) ;
if ( V_13 != 0 ) {
F_9 ( L_4 ) ;
F_28 ( & V_14 -> V_41 ) ;
return - V_5 ;
}
V_144 -> V_154 = V_147 . V_155 ;
V_144 -> V_156 = V_147 . V_157 ;
V_144 -> V_158 = V_147 . V_159 ;
V_144 -> V_160 = V_147 . V_161 ;
V_144 -> V_162 = V_147 . V_162 ;
V_144 -> V_163 = V_147 . V_163 ;
V_144 -> V_164 = V_147 . V_157 ;
V_144 -> V_165 = V_147 . V_155 ;
V_144 -> V_166 = V_145 . V_39 ;
if ( 0 == F_71 ( V_10 , & V_10 -> V_71 -> V_151 , & V_147 ) ) {
V_144 -> V_164 = V_147 . V_157 ;
V_144 -> V_165 = V_147 . V_155 ;
}
F_28 ( & V_14 -> V_41 ) ;
return 0 ;
}
int F_72 ( void * V_2 , enum V_167 type , struct V_168 * V_144 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
if ( V_144 == NULL )
return - V_5 ;
F_27 ( & V_14 -> V_41 ) ;
V_13 = F_73 ( V_10 , type , V_144 ) ;
F_28 ( & V_14 -> V_41 ) ;
return V_13 ;
}
int F_74 ( void * V_2 ,
enum V_167 type ,
struct V_169 * V_144 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
if ( ! V_144 )
return - V_5 ;
F_27 ( & V_14 -> V_41 ) ;
V_10 = ( (struct V_1 * ) V_2 ) -> V_10 ;
V_13 = F_75 ( V_10 , type , V_144 ) ;
F_28 ( & V_14 -> V_41 ) ;
return V_13 ;
}
int F_76 ( void * V_2 ,
enum V_167 type ,
struct V_170 * V_144 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
if ( ! V_144 )
return - V_5 ;
V_10 = ( (struct V_1 * ) V_2 ) -> V_10 ;
F_27 ( & V_14 -> V_41 ) ;
V_13 = F_77 ( V_10 , type , V_144 ) ;
F_28 ( & V_14 -> V_41 ) ;
return V_13 ;
}
int F_78 ( void * V_2 ,
struct V_171 * V_172 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
if ( ! V_172 )
return - V_5 ;
V_10 = ( (struct V_1 * ) V_2 ) -> V_10 ;
F_27 ( & V_14 -> V_41 ) ;
V_13 = F_79 ( V_10 ,
V_172 ) ;
F_28 ( & V_14 -> V_41 ) ;
return V_13 ;
}
int F_80 ( void * V_2 ,
struct V_173 * clock )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
if ( ! clock )
return - V_5 ;
V_10 = ( (struct V_1 * ) V_2 ) -> V_10 ;
F_27 ( & V_14 -> V_41 ) ;
V_13 = F_81 ( V_10 , clock ) ;
F_28 ( & V_14 -> V_41 ) ;
return V_13 ;
}
int F_82 ( void * V_2 ,
struct V_142 * V_144 )
{
struct V_26 * V_10 ;
struct V_1 * V_14 = (struct V_1 * ) V_2 ;
int V_13 = 0 ;
V_13 = F_1 ( V_14 ) ;
if ( V_13 != 0 )
return V_13 ;
V_10 = V_14 -> V_10 ;
if ( V_144 == NULL )
return - V_5 ;
F_27 ( & V_14 -> V_41 ) ;
if ( F_69 ( V_10 -> V_148 . V_149 , V_174 ) )
V_13 = F_83 ( V_10 , V_144 ) ;
F_28 ( & V_14 -> V_41 ) ;
return V_13 ;
}
