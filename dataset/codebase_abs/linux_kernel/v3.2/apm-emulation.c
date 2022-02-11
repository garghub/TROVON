static void F_1 ( struct V_1 * V_2 )
{
}
static inline int F_2 ( struct V_3 * V_4 )
{
return V_4 -> V_5 == V_4 -> V_6 ;
}
static inline T_1 F_3 ( struct V_3 * V_4 )
{
V_4 -> V_6 = ( V_4 -> V_6 + 1 ) % V_7 ;
return V_4 -> V_8 [ V_4 -> V_6 ] ;
}
static void F_4 ( struct V_3 * V_4 , T_1 V_9 )
{
V_4 -> V_5 = ( V_4 -> V_5 + 1 ) % V_7 ;
if ( V_4 -> V_5 == V_4 -> V_6 ) {
static int V_10 ;
if ( V_10 ++ == 0 )
F_5 ( V_11 L_1 ) ;
V_4 -> V_6 = ( V_4 -> V_6 + 1 ) % V_7 ;
}
V_4 -> V_8 [ V_4 -> V_5 ] = V_9 ;
}
static void F_6 ( T_1 V_9 )
{
struct V_12 * V_13 ;
F_7 ( & V_14 ) ;
F_8 (as, &apm_user_list, list) {
if ( V_13 -> V_15 )
F_4 ( & V_13 -> V_16 , V_9 ) ;
}
F_9 ( & V_14 ) ;
F_10 ( & V_17 ) ;
}
static T_2 F_11 ( struct V_18 * V_19 , char T_3 * V_20 , T_4 V_21 , T_5 * V_22 )
{
struct V_12 * V_13 = V_19 -> V_23 ;
T_1 V_9 ;
int V_24 = V_21 , V_25 = 0 ;
if ( V_21 < sizeof( T_1 ) )
return - V_26 ;
if ( F_2 ( & V_13 -> V_16 ) && V_19 -> V_27 & V_28 )
return - V_29 ;
F_12 ( V_17 , ! F_2 ( & V_13 -> V_16 ) ) ;
while ( ( V_24 >= sizeof( V_9 ) ) && ! F_2 ( & V_13 -> V_16 ) ) {
V_9 = F_3 ( & V_13 -> V_16 ) ;
V_25 = - V_30 ;
if ( F_13 ( V_20 , & V_9 , sizeof( V_9 ) ) )
break;
F_14 ( & V_31 ) ;
if ( V_13 -> V_32 == V_33 &&
( V_9 == V_34 || V_9 == V_35 ) )
V_13 -> V_32 = V_36 ;
F_15 ( & V_31 ) ;
V_20 += sizeof( V_9 ) ;
V_24 -= sizeof( V_9 ) ;
}
if ( V_24 < V_21 )
V_25 = V_21 - V_24 ;
return V_25 ;
}
static unsigned int F_16 ( struct V_18 * V_19 , T_6 * V_37 )
{
struct V_12 * V_13 = V_19 -> V_23 ;
F_17 ( V_19 , & V_17 , V_37 ) ;
return F_2 ( & V_13 -> V_16 ) ? 0 : V_38 | V_39 ;
}
static long
F_18 ( struct V_18 * V_40 , T_7 V_41 , T_8 V_42 )
{
struct V_12 * V_13 = V_40 -> V_23 ;
int V_43 = - V_26 ;
if ( ! V_13 -> V_44 || ! V_13 -> V_45 )
return - V_46 ;
switch ( V_41 ) {
case V_47 :
F_14 ( & V_31 ) ;
V_13 -> V_48 = - V_49 ;
switch ( V_13 -> V_32 ) {
case V_36 :
V_13 -> V_32 = V_50 ;
F_19 ( & V_51 ) ;
F_15 ( & V_31 ) ;
F_20 ( & V_52 ) ;
while ( F_21 ( V_52 ,
V_13 -> V_32 == V_53 ) )
F_22 ( 10 ) ;
break;
case V_54 :
V_13 -> V_48 = - V_55 ;
F_15 ( & V_31 ) ;
break;
default:
V_13 -> V_32 = V_56 ;
F_15 ( & V_31 ) ;
V_13 -> V_48 = F_23 ( V_57 ) ;
}
F_14 ( & V_31 ) ;
V_43 = V_13 -> V_48 ;
V_13 -> V_32 = V_58 ;
F_15 ( & V_31 ) ;
break;
}
return V_43 ;
}
static int F_24 ( struct V_59 * V_59 , struct V_18 * V_40 )
{
struct V_12 * V_13 = V_40 -> V_23 ;
V_40 -> V_23 = NULL ;
F_25 ( & V_14 ) ;
F_26 ( & V_13 -> V_60 ) ;
F_27 ( & V_14 ) ;
F_14 ( & V_31 ) ;
if ( V_13 -> V_32 == V_33 ||
V_13 -> V_32 == V_36 )
F_19 ( & V_51 ) ;
F_15 ( & V_31 ) ;
F_20 ( & V_52 ) ;
F_28 ( V_13 ) ;
return 0 ;
}
static int F_29 ( struct V_59 * V_59 , struct V_18 * V_40 )
{
struct V_12 * V_13 ;
V_13 = F_30 ( sizeof( * V_13 ) , V_61 ) ;
if ( V_13 ) {
V_13 -> V_44 = F_31 ( V_62 ) ;
V_13 -> V_45 = ( V_40 -> V_63 & V_64 ) == V_64 ;
V_13 -> V_15 = ( V_40 -> V_63 & V_65 ) == V_65 ;
F_25 ( & V_14 ) ;
F_32 ( & V_13 -> V_60 , & V_66 ) ;
F_27 ( & V_14 ) ;
V_40 -> V_23 = V_13 ;
}
return V_13 ? 0 : - V_67 ;
}
static int F_33 ( struct V_68 * V_69 , void * V_70 )
{
struct V_1 V_2 ;
char * V_71 ;
V_2 . V_72 = 0xff ;
V_2 . V_73 = 0xff ;
V_2 . V_74 = 0xff ;
V_2 . V_75 = - 1 ;
V_2 . time = - 1 ;
V_2 . V_71 = - 1 ;
if ( V_76 )
V_76 ( & V_2 ) ;
switch ( V_2 . V_71 ) {
default: V_71 = L_2 ; break;
case 0 : V_71 = L_3 ; break;
case 1 : V_71 = L_4 ; break;
}
F_34 ( V_69 , L_5 ,
V_77 , V_78 ,
V_2 . V_72 , V_2 . V_73 ,
V_2 . V_74 , V_2 . V_75 ,
V_2 . time , V_71 ) ;
return 0 ;
}
static int F_35 ( struct V_59 * V_59 , struct V_18 * V_18 )
{
return F_36 ( V_18 , F_33 , NULL ) ;
}
static int F_37 ( void * V_42 )
{
do {
T_1 V_9 ;
F_12 ( V_79 ,
! F_2 ( & V_80 ) || F_38 () ) ;
if ( F_38 () )
break;
F_39 ( & V_81 ) ;
V_9 = 0 ;
if ( ! F_2 ( & V_80 ) )
V_9 = F_3 ( & V_80 ) ;
F_40 ( & V_81 ) ;
switch ( V_9 ) {
case 0 :
break;
case V_82 :
case V_83 :
F_6 ( V_9 ) ;
break;
case V_35 :
case V_34 :
F_23 ( V_57 ) ;
break;
case V_84 :
F_41 ( & V_85 ) ;
F_23 ( V_57 ) ;
F_19 ( & V_85 ) ;
break;
}
} while ( 1 );
return 0 ;
}
static int F_42 ( struct V_86 * V_87 ,
unsigned long V_9 ,
void * V_88 )
{
struct V_12 * V_13 ;
int V_43 ;
if ( F_43 ( & V_85 ) )
return V_89 ;
switch ( V_9 ) {
case V_90 :
F_14 ( & V_31 ) ;
F_7 ( & V_14 ) ;
F_8 (as, &apm_user_list, list) {
if ( V_13 -> V_32 != V_56 && V_13 -> V_15 &&
V_13 -> V_45 && V_13 -> V_44 ) {
V_13 -> V_32 = V_33 ;
F_41 ( & V_51 ) ;
F_4 ( & V_13 -> V_16 , V_35 ) ;
}
}
F_9 ( & V_14 ) ;
F_15 ( & V_31 ) ;
F_10 ( & V_17 ) ;
V_43 = F_44 (
V_52 ,
F_43 ( & V_51 ) == 0 ,
5 * V_91 ) ;
if ( V_43 == 0 ) {
F_14 ( & V_31 ) ;
F_7 ( & V_14 ) ;
F_8 (as, &apm_user_list, list) {
if ( V_13 -> V_32 == V_33 ||
V_13 -> V_32 == V_36 ) {
V_13 -> V_32 = V_54 ;
F_19 ( & V_51 ) ;
}
}
F_9 ( & V_14 ) ;
F_15 ( & V_31 ) ;
}
if ( V_43 >= 0 )
return V_92 ;
return F_45 ( V_43 ) ;
case V_93 :
F_6 ( V_94 ) ;
F_14 ( & V_31 ) ;
F_7 ( & V_14 ) ;
F_8 (as, &apm_user_list, list) {
if ( V_13 -> V_32 == V_50 ) {
V_13 -> V_48 = 0 ;
V_13 -> V_32 = V_53 ;
}
}
F_9 ( & V_14 ) ;
F_15 ( & V_31 ) ;
F_20 ( & V_52 ) ;
return V_92 ;
default:
return V_89 ;
}
}
static int T_9 F_46 ( void )
{
int V_25 ;
if ( V_95 ) {
F_5 ( V_96 L_6 ) ;
return - V_97 ;
}
V_98 = F_47 ( F_37 , NULL , L_7 ) ;
if ( F_48 ( V_98 ) ) {
V_25 = F_49 ( V_98 ) ;
V_98 = NULL ;
goto V_99;
}
F_50 ( V_98 ) ;
#ifdef F_51
F_52 ( L_8 , 0 , NULL , & V_100 ) ;
#endif
V_25 = F_53 ( & V_101 ) ;
if ( V_25 )
goto V_102;
V_25 = F_54 ( & V_103 ) ;
if ( V_25 )
goto V_104;
return 0 ;
V_104:
F_55 ( & V_101 ) ;
V_102:
F_56 ( L_8 , NULL ) ;
F_57 ( V_98 ) ;
V_99:
return V_25 ;
}
static void T_10 F_58 ( void )
{
F_59 ( & V_103 ) ;
F_55 ( & V_101 ) ;
F_56 ( L_8 , NULL ) ;
F_57 ( V_98 ) ;
}
static int T_9 F_60 ( char * V_105 )
{
while ( ( V_105 != NULL ) && ( * V_105 != '\0' ) ) {
if ( strncmp ( V_105 , L_9 , 3 ) == 0 )
V_95 = 1 ;
if ( strncmp ( V_105 , L_10 , 2 ) == 0 )
V_95 = 0 ;
V_105 = strchr ( V_105 , ',' ) ;
if ( V_105 != NULL )
V_105 += strspn ( V_105 , L_11 ) ;
}
return 1 ;
}
void F_61 ( T_1 V_9 )
{
unsigned long V_106 ;
F_62 ( & V_81 , V_106 ) ;
F_4 ( & V_80 , V_9 ) ;
F_63 ( & V_81 , V_106 ) ;
F_10 ( & V_79 ) ;
}
