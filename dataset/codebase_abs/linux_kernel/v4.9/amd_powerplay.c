static int F_1 ( void * V_1 )
{
return 0 ;
}
static int F_2 ( void * V_1 )
{
struct V_2 * V_3 ;
struct V_4 * V_5 ;
int V_6 = 0 ;
if ( V_1 == NULL )
return - V_7 ;
V_3 = (struct V_2 * ) V_1 ;
V_5 = V_3 -> V_5 ;
F_3 ( V_5 ) ;
if ( V_5 -> V_8 == NULL ||
V_5 -> V_8 -> V_9 == NULL ||
V_5 -> V_10 -> V_11 == NULL )
return - V_7 ;
V_6 = V_5 -> V_8 -> V_9 ( V_5 ) ;
if ( V_6 )
goto V_12;
V_6 = V_5 -> V_10 -> V_11 ( V_5 ) ;
if ( V_6 )
goto V_13;
F_4 ( L_1 ) ;
return 0 ;
V_13:
if ( V_5 -> V_8 -> V_14 )
V_5 -> V_8 -> V_14 ( V_5 ) ;
V_12:
F_5 ( L_2 ) ;
return V_6 ;
}
static int F_6 ( void * V_1 )
{
struct V_2 * V_3 ;
struct V_4 * V_5 ;
int V_6 = 0 ;
if ( V_1 == NULL )
return - V_7 ;
V_3 = (struct V_2 * ) V_1 ;
V_5 = V_3 -> V_5 ;
F_3 ( V_5 ) ;
if ( V_5 -> V_10 -> V_15 != NULL )
V_6 = V_5 -> V_10 -> V_15 ( V_5 ) ;
if ( V_5 -> V_8 -> V_14 )
V_5 -> V_8 -> V_14 ( V_5 ) ;
return V_6 ;
}
static int F_7 ( void * V_1 )
{
struct V_2 * V_3 ;
struct V_16 * V_17 ;
struct V_18 * V_19 ;
int V_6 = 0 ;
if ( V_1 == NULL )
return - V_7 ;
V_3 = (struct V_2 * ) V_1 ;
V_17 = V_3 -> V_20 ;
if ( V_17 == NULL || V_17 -> V_21 == NULL ||
V_17 -> V_21 -> V_22 == NULL ||
V_17 -> V_21 -> V_23 == NULL )
return - V_7 ;
V_6 = V_17 -> V_21 -> V_22 ( V_17 ) ;
if ( V_6 ) {
F_8 ( V_24 L_3 ) ;
return V_6 ;
}
V_6 = V_17 -> V_21 -> V_23 ( V_17 ) ;
if ( V_6 ) {
F_8 ( V_24 L_4 ) ;
V_17 -> V_21 -> V_25 ( V_17 ) ;
return V_6 ;
}
F_9 ( V_3 -> V_5 ) ;
V_19 = V_3 -> V_19 ;
if ( V_19 == NULL || V_19 -> V_26 == NULL )
return - V_7 ;
V_6 = V_19 -> V_26 ( V_19 ) ;
return 0 ;
}
static int F_10 ( void * V_1 )
{
struct V_2 * V_3 ;
struct V_16 * V_17 ;
struct V_18 * V_19 ;
if ( V_1 == NULL )
return - V_7 ;
V_3 = (struct V_2 * ) V_1 ;
V_19 = V_3 -> V_19 ;
if ( V_19 != NULL && V_19 -> V_27 != NULL )
V_19 -> V_27 ( V_19 ) ;
V_17 = V_3 -> V_20 ;
if ( V_17 != NULL && V_17 -> V_21 != NULL &&
V_17 -> V_21 -> V_25 != NULL )
V_17 -> V_21 -> V_25 ( V_17 ) ;
return 0 ;
}
static bool F_11 ( void * V_1 )
{
return false ;
}
static int F_12 ( void * V_1 )
{
return 0 ;
}
static int F_13 ( void * V_1 )
{
return 0 ;
}
int F_14 ( void * V_1 , T_1 V_28 )
{
struct V_4 * V_5 ;
if ( V_1 == NULL )
return - V_7 ;
V_5 = ( (struct V_2 * ) V_1 ) -> V_5 ;
F_3 ( V_5 ) ;
if ( V_5 -> V_10 -> V_29 == NULL ) {
F_8 ( V_30 L_5 , V_31 ) ;
return 0 ;
}
return V_5 -> V_10 -> V_29 ( V_5 , & V_28 ) ;
}
static int F_15 ( void * V_1 ,
enum V_32 V_33 )
{
struct V_4 * V_5 ;
if ( V_1 == NULL )
return - V_7 ;
V_5 = ( (struct V_2 * ) V_1 ) -> V_5 ;
F_3 ( V_5 ) ;
if ( V_5 -> V_10 -> V_34 == NULL ) {
F_8 ( V_30 L_5 , V_31 ) ;
return 0 ;
}
return V_5 -> V_10 -> V_34 ( V_5 ,
V_33 == V_35 ? true : false ) ;
}
static int F_16 ( void * V_1 )
{
struct V_2 * V_3 ;
struct V_18 * V_19 ;
struct V_36 V_37 = { { 0 } } ;
if ( V_1 == NULL )
return - V_7 ;
V_3 = (struct V_2 * ) V_1 ;
V_19 = V_3 -> V_19 ;
F_17 ( V_19 , V_38 , & V_37 ) ;
return 0 ;
}
static int F_18 ( void * V_1 )
{
struct V_2 * V_3 ;
struct V_18 * V_19 ;
struct V_36 V_37 = { { 0 } } ;
struct V_16 * V_17 ;
int V_6 ;
if ( V_1 == NULL )
return - V_7 ;
V_3 = (struct V_2 * ) V_1 ;
V_17 = V_3 -> V_20 ;
if ( V_17 == NULL || V_17 -> V_21 == NULL ||
V_17 -> V_21 -> V_23 == NULL )
return - V_7 ;
V_6 = V_17 -> V_21 -> V_23 ( V_17 ) ;
if ( V_6 ) {
F_8 ( V_24 L_4 ) ;
V_17 -> V_21 -> V_25 ( V_17 ) ;
return V_6 ;
}
V_19 = V_3 -> V_19 ;
F_17 ( V_19 , V_39 , & V_37 ) ;
return 0 ;
}
static int F_19 ( void * V_1 )
{
return 0 ;
}
static int F_20 ( void * V_1 )
{
return 0 ;
}
static int F_21 ( void * V_1 ,
enum V_40 V_41 )
{
struct V_2 * V_3 ;
struct V_4 * V_5 ;
if ( V_1 == NULL )
return - V_7 ;
V_3 = (struct V_2 * ) V_1 ;
V_5 = V_3 -> V_5 ;
F_3 ( V_5 ) ;
if ( V_5 -> V_10 -> V_42 == NULL ) {
F_8 ( V_30 L_5 , V_31 ) ;
return 0 ;
}
V_5 -> V_10 -> V_42 ( V_5 , V_41 ) ;
return 0 ;
}
static enum V_40 F_22 (
void * V_1 )
{
struct V_4 * V_5 ;
if ( V_1 == NULL )
return - V_7 ;
V_5 = ( (struct V_2 * ) V_1 ) -> V_5 ;
if ( V_5 == NULL )
return - V_7 ;
return ( ( (struct V_2 * ) V_1 ) -> V_5 -> V_43 ) ;
}
static int F_23 ( void * V_1 , bool V_44 )
{
struct V_4 * V_5 ;
if ( V_1 == NULL )
return - V_7 ;
V_5 = ( (struct V_2 * ) V_1 ) -> V_5 ;
F_3 ( V_5 ) ;
if ( V_5 -> V_10 -> V_45 == NULL ) {
F_8 ( V_30 L_5 , V_31 ) ;
return 0 ;
}
return V_5 -> V_10 -> V_45 ( V_5 , V_44 ) ;
}
static int F_24 ( void * V_1 , bool V_44 )
{
struct V_4 * V_5 ;
if ( V_1 == NULL )
return - V_7 ;
V_5 = ( (struct V_2 * ) V_1 ) -> V_5 ;
F_3 ( V_5 ) ;
if ( V_5 -> V_10 -> V_46 == NULL ) {
F_8 ( V_30 L_5 , V_31 ) ;
return 0 ;
}
return V_5 -> V_10 -> V_46 ( V_5 , V_44 ) ;
}
static int F_25 ( void * V_1 , bool V_47 )
{
struct V_4 * V_5 ;
if ( V_1 == NULL )
return - V_7 ;
V_5 = ( (struct V_2 * ) V_1 ) -> V_5 ;
F_3 ( V_5 ) ;
if ( V_5 -> V_10 -> V_48 == NULL ) {
F_8 ( V_30 L_5 , V_31 ) ;
return 0 ;
}
return V_5 -> V_10 -> V_48 ( V_5 , V_47 ) ;
}
static int F_26 ( void * V_1 , bool V_47 )
{
struct V_4 * V_5 ;
if ( V_1 == NULL )
return - V_7 ;
V_5 = ( (struct V_2 * ) V_1 ) -> V_5 ;
F_3 ( V_5 ) ;
if ( V_5 -> V_10 -> V_49 == NULL ) {
F_8 ( V_30 L_5 , V_31 ) ;
return 0 ;
}
return V_5 -> V_10 -> V_49 ( V_5 , V_47 ) ;
}
static enum V_50 F_27 ( enum V_51 V_33 )
{
switch ( V_33 ) {
case V_52 :
return V_53 ;
case V_54 :
return V_55 ;
case V_56 :
return V_57 ;
default:
return V_58 ;
}
}
int F_28 ( void * V_1 , enum V_59 V_60 , void * V_61 , void * V_62 )
{
int V_6 = 0 ;
struct V_2 * V_3 ;
struct V_36 V_63 = { { 0 } } ;
V_3 = (struct V_2 * ) V_1 ;
if ( V_3 == NULL )
return - V_7 ;
switch ( V_60 ) {
case V_64 :
V_6 = F_17 ( V_3 -> V_19 , V_60 , & V_63 ) ;
break;
case V_65 :
{
enum V_51 V_66 ;
if ( V_61 == NULL )
return - V_7 ;
V_66 = * ( unsigned long * ) V_61 ;
V_63 . V_67 = F_27 ( V_66 ) ;
V_6 = F_17 ( V_3 -> V_19 , V_60 , & V_63 ) ;
break;
}
case V_68 :
V_6 = F_17 ( V_3 -> V_19 , V_60 , & V_63 ) ;
break;
case V_69 :
V_6 = F_17 ( V_3 -> V_19 , V_60 , & V_63 ) ;
break;
default:
break;
}
return V_6 ;
}
enum V_51 F_29 ( void * V_1 )
{
struct V_4 * V_5 ;
struct V_70 * V_33 ;
if ( V_1 == NULL )
return - V_7 ;
V_5 = ( (struct V_2 * ) V_1 ) -> V_5 ;
if ( V_5 == NULL || V_5 -> V_71 == NULL )
return - V_7 ;
V_33 = V_5 -> V_71 ;
switch ( V_33 -> V_72 . V_73 ) {
case V_53 :
return V_52 ;
case V_55 :
return V_54 ;
case V_57 :
return V_56 ;
default:
if ( V_33 -> V_72 . V_74 & V_75 )
return V_76 ;
else
return V_77 ;
}
}
static int F_30 ( void * V_1 , T_1 V_78 )
{
struct V_4 * V_5 ;
if ( V_1 == NULL )
return - V_7 ;
V_5 = ( (struct V_2 * ) V_1 ) -> V_5 ;
F_3 ( V_5 ) ;
if ( V_5 -> V_10 -> V_79 == NULL ) {
F_8 ( V_30 L_5 , V_31 ) ;
return 0 ;
}
return V_5 -> V_10 -> V_79 ( V_5 , V_78 ) ;
}
static int F_31 ( void * V_1 )
{
struct V_4 * V_5 ;
if ( V_1 == NULL )
return - V_7 ;
V_5 = ( (struct V_2 * ) V_1 ) -> V_5 ;
F_3 ( V_5 ) ;
if ( V_5 -> V_10 -> V_80 == NULL ) {
F_8 ( V_30 L_5 , V_31 ) ;
return 0 ;
}
return V_5 -> V_10 -> V_80 ( V_5 ) ;
}
static int F_32 ( void * V_1 , T_1 V_81 )
{
struct V_4 * V_5 ;
if ( V_1 == NULL )
return - V_7 ;
V_5 = ( (struct V_2 * ) V_1 ) -> V_5 ;
F_3 ( V_5 ) ;
if ( V_5 -> V_10 -> V_82 == NULL ) {
F_8 ( V_30 L_5 , V_31 ) ;
return 0 ;
}
return V_5 -> V_10 -> V_82 ( V_5 , V_81 ) ;
}
static int F_33 ( void * V_1 , T_1 * V_83 )
{
struct V_4 * V_5 ;
if ( V_1 == NULL )
return - V_7 ;
V_5 = ( (struct V_2 * ) V_1 ) -> V_5 ;
F_3 ( V_5 ) ;
if ( V_5 -> V_10 -> V_84 == NULL ) {
F_8 ( V_30 L_5 , V_31 ) ;
return 0 ;
}
return V_5 -> V_10 -> V_84 ( V_5 , V_83 ) ;
}
static int F_34 ( void * V_1 )
{
struct V_4 * V_5 ;
if ( V_1 == NULL )
return - V_7 ;
V_5 = ( (struct V_2 * ) V_1 ) -> V_5 ;
F_3 ( V_5 ) ;
if ( V_5 -> V_10 -> V_85 == NULL ) {
F_8 ( V_30 L_5 , V_31 ) ;
return 0 ;
}
return V_5 -> V_10 -> V_85 ( V_5 ) ;
}
static int F_35 ( void * V_1 ,
struct V_86 * V_63 )
{
struct V_4 * V_5 ;
int V_87 ;
if ( ! V_1 )
return - V_7 ;
V_5 = ( (struct V_2 * ) V_1 ) -> V_5 ;
if ( V_5 == NULL || V_5 -> V_66 == NULL )
return - V_7 ;
V_63 -> V_88 = V_5 -> V_89 ;
for ( V_87 = 0 ; V_87 < V_5 -> V_89 ; V_87 ++ ) {
struct V_70 * V_33 = (struct V_70 * )
( ( unsigned long ) V_5 -> V_66 + V_87 * V_5 -> V_90 ) ;
switch ( V_33 -> V_72 . V_73 ) {
case V_53 :
V_63 -> V_91 [ V_87 ] = V_52 ;
break;
case V_55 :
V_63 -> V_91 [ V_87 ] = V_54 ;
break;
case V_57 :
V_63 -> V_91 [ V_87 ] = V_56 ;
break;
default:
if ( V_33 -> V_72 . V_74 & V_75 )
V_63 -> V_91 [ V_87 ] = V_76 ;
else
V_63 -> V_91 [ V_87 ] = V_77 ;
}
}
return 0 ;
}
static int F_36 ( void * V_1 , char * * V_92 )
{
struct V_4 * V_5 ;
if ( ! V_1 )
return - V_7 ;
V_5 = ( (struct V_2 * ) V_1 ) -> V_5 ;
F_3 ( V_5 ) ;
if ( ! V_5 -> V_93 )
return - V_7 ;
* V_92 = ( char * ) V_5 -> V_93 ;
return V_5 -> V_94 ;
}
static int F_37 ( void * V_1 , const char * V_95 , T_2 V_96 )
{
struct V_4 * V_5 ;
if ( ! V_1 )
return - V_7 ;
V_5 = ( (struct V_2 * ) V_1 ) -> V_5 ;
F_3 ( V_5 ) ;
if ( ! V_5 -> V_97 ) {
V_5 -> V_97 = F_38 ( V_5 -> V_93 ,
V_5 -> V_94 ,
V_98 ) ;
if ( ! V_5 -> V_97 )
return - V_99 ;
}
memcpy ( V_5 -> V_97 , V_95 , V_96 ) ;
V_5 -> V_93 = V_5 -> V_97 ;
return F_39 ( V_1 ) ;
}
static int F_40 ( void * V_1 ,
enum V_100 type , T_1 V_101 )
{
struct V_4 * V_5 ;
if ( ! V_1 )
return - V_7 ;
V_5 = ( (struct V_2 * ) V_1 ) -> V_5 ;
F_3 ( V_5 ) ;
if ( V_5 -> V_10 -> V_102 == NULL ) {
F_8 ( V_30 L_5 , V_31 ) ;
return 0 ;
}
return V_5 -> V_10 -> V_102 ( V_5 , type , V_101 ) ;
}
static int F_41 ( void * V_1 ,
enum V_100 type , char * V_95 )
{
struct V_4 * V_5 ;
if ( ! V_1 )
return - V_7 ;
V_5 = ( (struct V_2 * ) V_1 ) -> V_5 ;
F_3 ( V_5 ) ;
if ( V_5 -> V_10 -> V_103 == NULL ) {
F_8 ( V_30 L_5 , V_31 ) ;
return 0 ;
}
return V_5 -> V_10 -> V_103 ( V_5 , type , V_95 ) ;
}
static int F_42 ( void * V_1 )
{
struct V_4 * V_5 ;
if ( ! V_1 )
return - V_7 ;
V_5 = ( (struct V_2 * ) V_1 ) -> V_5 ;
F_3 ( V_5 ) ;
if ( V_5 -> V_10 -> V_104 == NULL ) {
F_8 ( V_30 L_5 , V_31 ) ;
return 0 ;
}
return V_5 -> V_10 -> V_104 ( V_5 ) ;
}
static int F_43 ( void * V_1 , T_1 V_105 )
{
struct V_4 * V_5 ;
if ( ! V_1 )
return - V_7 ;
V_5 = ( (struct V_2 * ) V_1 ) -> V_5 ;
F_3 ( V_5 ) ;
if ( V_5 -> V_10 -> V_106 == NULL ) {
F_8 ( V_30 L_5 , V_31 ) ;
return 0 ;
}
return V_5 -> V_10 -> V_106 ( V_5 , V_105 ) ;
}
static int F_44 ( void * V_1 )
{
struct V_4 * V_5 ;
if ( ! V_1 )
return - V_7 ;
V_5 = ( (struct V_2 * ) V_1 ) -> V_5 ;
F_3 ( V_5 ) ;
if ( V_5 -> V_10 -> V_107 == NULL ) {
F_8 ( V_30 L_5 , V_31 ) ;
return 0 ;
}
return V_5 -> V_10 -> V_107 ( V_5 ) ;
}
static int F_45 ( void * V_1 , T_1 V_105 )
{
struct V_4 * V_5 ;
if ( ! V_1 )
return - V_7 ;
V_5 = ( (struct V_2 * ) V_1 ) -> V_5 ;
F_3 ( V_5 ) ;
if ( V_5 -> V_10 -> V_108 == NULL ) {
F_8 ( V_30 L_5 , V_31 ) ;
return 0 ;
}
return V_5 -> V_10 -> V_108 ( V_5 , V_105 ) ;
}
static int F_46 ( void * V_1 , int V_109 , T_3 * V_105 )
{
struct V_4 * V_5 ;
if ( ! V_1 )
return - V_7 ;
V_5 = ( (struct V_2 * ) V_1 ) -> V_5 ;
F_3 ( V_5 ) ;
if ( V_5 -> V_10 -> V_110 == NULL ) {
F_8 ( V_30 L_5 , V_31 ) ;
return 0 ;
}
return V_5 -> V_10 -> V_110 ( V_5 , V_109 , V_105 ) ;
}
static int F_47 ( struct V_111 * V_112 ,
struct V_113 * V_114 )
{
int V_6 ;
struct V_2 * V_1 ;
V_1 = F_48 ( sizeof( struct V_2 ) , V_98 ) ;
if ( V_1 == NULL )
return - V_99 ;
V_1 -> V_115 = V_116 ;
V_6 = F_49 ( V_112 , V_1 ) ;
if ( V_6 )
goto V_117;
V_6 = F_50 ( V_112 , V_1 ) ;
if ( V_6 )
goto V_118;
V_6 = F_51 ( V_1 ) ;
if ( V_6 )
goto V_119;
V_114 -> V_3 = V_1 ;
return 0 ;
V_119:
F_52 ( V_1 -> V_5 ) ;
V_118:
F_53 ( V_1 -> V_20 ) ;
V_117:
F_54 ( V_1 ) ;
return V_6 ;
}
static int F_55 ( void * V_1 )
{
struct V_2 * V_120 = (struct V_2 * ) V_1 ;
if ( V_120 == NULL )
return - V_7 ;
F_56 ( V_120 -> V_19 ) ;
F_52 ( V_120 -> V_5 ) ;
F_53 ( V_120 -> V_20 ) ;
F_54 ( V_1 ) ;
return 0 ;
}
int F_57 ( struct V_111 * V_112 ,
struct V_113 * V_114 )
{
int V_6 ;
if ( V_112 == NULL || V_114 == NULL )
return - V_7 ;
V_6 = F_47 ( V_112 , V_114 ) ;
if ( V_6 )
return V_6 ;
V_114 -> V_121 = & V_122 ;
V_114 -> V_123 = & V_124 ;
return 0 ;
}
int F_58 ( void * V_1 )
{
F_55 ( V_1 ) ;
return 0 ;
}
int F_39 ( void * V_1 )
{
struct V_2 * V_120 = (struct V_2 * ) V_1 ;
struct V_18 * V_19 ;
struct V_36 V_37 = { { 0 } } ;
int V_6 ;
if ( V_120 == NULL )
return - V_7 ;
V_19 = V_120 -> V_19 ;
if ( ! V_19 || ! V_19 -> V_27 )
return - V_7 ;
V_19 -> V_27 ( V_19 ) ;
V_6 = F_6 ( V_1 ) ;
if ( V_6 )
return V_6 ;
F_54 ( V_120 -> V_5 -> V_66 ) ;
V_6 = F_2 ( V_1 ) ;
if ( V_6 )
return V_6 ;
F_9 ( V_120 -> V_5 ) ;
if ( V_19 == NULL || V_19 -> V_26 == NULL )
return - V_7 ;
V_6 = V_19 -> V_26 ( V_19 ) ;
if ( V_6 )
return V_6 ;
return F_17 ( V_19 , V_68 , & V_37 ) ;
}
int F_59 ( void * V_1 ,
const struct V_125 * V_126 )
{
struct V_4 * V_5 ;
F_60 ( (struct V_2 * ) V_1 ) ;
V_5 = ( (struct V_2 * ) V_1 ) -> V_5 ;
F_61 ( V_5 , V_126 ) ;
return 0 ;
}
int F_62 ( void * V_1 ,
struct V_127 * V_62 )
{
struct V_4 * V_5 ;
F_60 ( (struct V_2 * ) V_1 ) ;
if ( V_62 == NULL )
return - V_7 ;
V_5 = ( (struct V_2 * ) V_1 ) -> V_5 ;
return F_63 ( V_5 , V_62 ) ;
}
int F_64 ( void * V_1 ,
struct V_128 * V_129 )
{
struct V_4 * V_5 ;
struct V_127 V_130 ;
struct V_131 V_132 ;
F_60 ( (struct V_2 * ) V_1 ) ;
if ( V_129 == NULL )
return - V_7 ;
V_5 = ( (struct V_2 * ) V_1 ) -> V_5 ;
F_63 ( V_5 , & V_130 ) ;
if ( F_65 ( V_5 -> V_133 . V_134 , V_135 ) ) {
if ( 0 != F_66 ( V_5 , & V_5 -> V_71 -> V_136 , & V_132 , V_137 ) )
F_67 ( 0 , L_6 , return -1 ) ;
} else {
if ( 0 != F_66 ( V_5 , & V_5 -> V_71 -> V_136 , & V_132 , V_138 ) )
F_67 ( 0 , L_7 , return -1 ) ;
}
V_129 -> V_139 = V_132 . V_140 ;
V_129 -> V_141 = V_132 . V_142 ;
V_129 -> V_143 = V_132 . V_144 ;
V_129 -> V_145 = V_132 . V_146 ;
V_129 -> V_147 = V_132 . V_147 ;
V_129 -> V_148 = V_132 . V_148 ;
V_129 -> V_149 = V_132 . V_142 ;
V_129 -> V_150 = V_132 . V_140 ;
V_129 -> V_151 = V_130 . V_41 ;
if ( 0 == F_68 ( V_5 , & V_5 -> V_71 -> V_136 , & V_132 ) ) {
V_129 -> V_149 = V_132 . V_142 ;
V_129 -> V_150 = V_132 . V_140 ;
}
return 0 ;
}
int F_69 ( void * V_1 , enum V_152 type , struct V_153 * V_129 )
{
int V_154 = - 1 ;
struct V_4 * V_5 ;
F_60 ( (struct V_2 * ) V_1 ) ;
if ( V_129 == NULL )
return - V_7 ;
V_5 = ( (struct V_2 * ) V_1 ) -> V_5 ;
V_154 = F_70 ( V_5 , type , V_129 ) ;
return V_154 ;
}
int F_71 ( void * V_1 ,
struct V_127 * V_129 )
{
int V_154 = - 1 ;
struct V_4 * V_5 ;
F_60 ( (struct V_2 * ) V_1 ) ;
if ( V_129 == NULL )
return - V_7 ;
V_5 = ( (struct V_2 * ) V_1 ) -> V_5 ;
if ( F_65 ( V_5 -> V_133 . V_134 , V_155 ) )
V_154 = F_72 ( V_5 , V_129 ) ;
return V_154 ;
}
