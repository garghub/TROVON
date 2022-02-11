struct V_1 * F_1 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( sizeof( * V_2 ) , V_3 ) ;
if ( ! V_2 )
return NULL ;
F_3 ( & V_2 -> V_4 ) ;
return V_2 ;
}
void F_4 ( struct V_1 * V_2 )
{
F_5 ( & V_5 ) ;
F_6 ( & V_2 -> V_4 ) ;
F_7 ( & V_5 ) ;
}
static void F_8 ( struct V_4 * V_4 )
{
struct V_1 * V_2 = F_9 ( V_4 , F_10 ( * V_2 ) , V_4 ) ;
F_11 ( V_2 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
F_5 ( & V_5 ) ;
F_13 ( & V_2 -> V_4 , F_8 ) ;
F_7 ( & V_5 ) ;
}
static int F_14 ( struct V_6 * V_7 ,
struct V_1 * V_2 )
{
F_15 ( F_16 ( V_8 , & V_2 -> V_9 ) ) ;
F_15 ( V_2 -> V_7 ) ;
F_5 ( & V_7 -> V_10 ) ;
if ( ! V_7 -> V_11 ) {
F_7 ( & V_7 -> V_10 ) ;
return - V_12 ;
}
V_2 -> V_7 = V_7 ;
F_17 ( & V_2 -> V_13 , & V_7 -> V_14 ) ;
F_18 ( V_8 , & V_2 -> V_9 ) ;
F_7 ( & V_7 -> V_10 ) ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
F_5 ( & V_7 -> V_10 ) ;
F_20 ( & V_2 -> V_13 ) ;
F_21 ( V_8 , & V_2 -> V_9 ) ;
if ( F_16 ( V_15 , & V_2 -> V_9 ) )
F_22 ( & V_16 ) ;
F_7 ( & V_7 -> V_10 ) ;
}
static bool F_23 ( struct V_1 * V_2 )
{
return F_16 ( V_8 , & V_2 -> V_9 ) ;
}
static struct V_1 *
F_24 ( struct V_6 * V_7 , struct V_17 * V_18 )
{
struct V_1 * V_2 ;
bool V_19 = false ;
F_5 ( & V_18 -> V_7 -> V_10 ) ;
F_25 (req, &pkg->ctl->request_queue, list) {
F_4 ( V_2 ) ;
if ( V_2 -> V_20 ( V_2 , V_18 ) ) {
V_19 = true ;
break;
}
F_12 ( V_2 ) ;
}
F_7 ( & V_18 -> V_7 -> V_10 ) ;
return V_19 ? V_2 : NULL ;
}
static int F_26 ( const struct V_17 * V_18 , T_1 V_21 ,
enum V_22 type , T_2 V_23 )
{
struct V_24 * V_25 = V_18 -> V_26 ;
if ( F_27 ( V_21 != V_18 -> V_27 . V_28 ,
L_1 ,
V_21 , V_18 -> V_27 . V_28 ) )
return - V_29 ;
if ( F_27 ( type != V_18 -> V_27 . V_30 , L_2 ,
type , V_18 -> V_27 . V_30 ) )
return - V_29 ;
if ( F_27 ( V_18 -> V_27 . V_31 , L_3 ,
V_18 -> V_27 . V_31 ) )
return - V_29 ;
if ( F_27 ( V_25 -> V_32 != 1 << 9 ,
L_4 , V_25 -> V_32 ) )
return - V_29 ;
if ( F_27 ( V_23 != F_28 ( V_25 ) ,
L_5 ,
V_23 , F_28 ( V_25 ) ) )
return - V_29 ;
return 0 ;
}
static int F_29 ( struct V_33 V_34 ,
enum V_35 V_36 , T_1 V_37 ,
T_1 V_38 )
{
if ( F_27 ( V_34 . V_39 , L_6 , V_34 . V_39 ) )
return - V_29 ;
if ( F_27 ( V_36 != V_34 . V_36 , L_7 ,
V_36 , V_34 . V_36 ) )
return - V_29 ;
if ( F_27 ( V_37 != V_34 . V_37 , L_8 ,
V_37 , V_34 . V_37 ) )
return - V_29 ;
if ( F_27 ( V_38 != V_34 . V_38 , L_7 ,
V_38 , V_34 . V_38 ) )
return - V_29 ;
return 0 ;
}
static struct V_40 F_30 ( const struct V_17 * V_41 )
{
struct V_42 * V_18 = V_41 -> V_26 ;
struct V_40 V_43 = { 0 } ;
V_43 . V_44 = F_28 ( & V_18 -> V_25 ) ;
V_43 . V_45 = 0 ;
V_43 . V_46 = F_26 ( V_41 , sizeof( * V_18 ) , V_47 ,
F_28 ( & V_18 -> V_25 ) ) ;
if ( V_43 . V_46 )
return V_43 ;
F_27 ( V_18 -> V_48 , L_9 , V_18 -> V_48 ) ;
F_27 ( V_18 -> V_49 , L_9 , V_18 -> V_48 ) ;
F_27 ( V_18 -> V_50 , L_9 , V_18 -> V_48 ) ;
V_43 . V_46 = 1 ;
V_43 . V_51 = V_18 -> error ;
V_43 . V_45 = V_18 -> V_52 ;
return V_43 ;
}
static struct V_40 F_31 ( const struct V_17 * V_18 , T_1 V_21 ,
enum V_22 type , T_2 V_23 )
{
struct V_24 * V_25 = V_18 -> V_26 ;
struct V_40 V_43 = { 0 } ;
if ( V_18 -> V_27 . V_30 == V_47 )
return F_30 ( V_18 ) ;
V_43 . V_45 = 0 ;
V_43 . V_44 = F_28 ( V_25 ) ;
V_43 . V_46 = F_26 ( V_18 , V_21 , type , V_23 ) ;
return V_43 ;
}
static void F_32 ( struct V_6 * V_7 ,
const struct V_40 * V_43 )
{
F_15 ( V_43 -> V_46 != 1 ) ;
switch ( V_43 -> V_51 ) {
case V_53 :
return;
case V_54 :
F_33 ( V_7 ,
L_10 ,
V_43 -> V_44 , V_43 -> V_45 ) ;
return;
case V_55 :
F_33 ( V_7 , L_11 ,
V_43 -> V_44 , V_43 -> V_45 ) ;
return;
case V_56 :
F_33 ( V_7 , L_12 ,
V_43 -> V_44 , V_43 -> V_45 ) ;
return;
default:
F_33 ( V_7 , L_13 ,
V_43 -> V_44 , V_43 -> V_45 ) ;
return;
}
}
static void F_34 ( T_3 * V_57 , const T_1 * V_58 , T_4 V_21 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < V_21 ; V_59 ++ )
V_57 [ V_59 ] = F_35 ( V_58 [ V_59 ] ) ;
}
static void F_36 ( T_1 * V_57 , T_3 * V_58 , T_4 V_21 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < V_21 ; V_59 ++ )
V_57 [ V_59 ] = F_37 ( V_58 [ V_59 ] ) ;
}
static T_3 F_38 ( const void * V_60 , T_4 V_21 )
{
return F_35 ( ~ F_39 ( ~ 0 , V_60 , V_21 ) ) ;
}
static void F_40 ( struct V_17 * V_18 )
{
if ( V_18 ) {
F_41 ( V_18 -> V_7 -> V_61 ,
V_18 -> V_26 , V_18 -> V_27 . V_62 ) ;
F_11 ( V_18 ) ;
}
}
static struct V_17 * F_42 ( struct V_6 * V_7 )
{
struct V_17 * V_18 = F_2 ( sizeof( * V_18 ) , V_3 ) ;
if ( ! V_18 )
return NULL ;
V_18 -> V_7 = V_7 ;
V_18 -> V_26 = F_43 ( V_7 -> V_61 , V_3 ,
& V_18 -> V_27 . V_62 ) ;
if ( ! V_18 -> V_26 ) {
F_11 ( V_18 ) ;
return NULL ;
}
return V_18 ;
}
static void F_44 ( struct V_63 * V_64 , struct V_65 * V_27 ,
bool V_66 )
{
struct V_17 * V_18 = F_9 ( V_27 , F_10 ( * V_18 ) , V_27 ) ;
F_40 ( V_18 ) ;
}
static int F_45 ( struct V_6 * V_7 , const void * V_60 , T_4 V_21 ,
enum V_22 type )
{
int V_43 ;
struct V_17 * V_18 ;
if ( V_21 % 4 != 0 ) {
F_33 ( V_7 , L_14 , V_21 ) ;
return - V_67 ;
}
if ( V_21 > V_68 - 4 ) {
F_33 ( V_7 , L_15 ,
V_21 , V_68 - 4 ) ;
return - V_67 ;
}
V_18 = F_42 ( V_7 ) ;
if ( ! V_18 )
return - V_69 ;
V_18 -> V_27 . V_70 = F_44 ;
V_18 -> V_27 . V_28 = V_21 + 4 ;
V_18 -> V_27 . V_31 = type ;
V_18 -> V_27 . V_30 = type ;
F_34 ( V_18 -> V_26 , V_60 , V_21 / 4 ) ;
* ( T_3 * ) ( V_18 -> V_26 + V_21 ) = F_38 ( V_18 -> V_26 , V_21 ) ;
V_43 = F_46 ( V_7 -> V_71 , & V_18 -> V_27 ) ;
if ( V_43 )
F_40 ( V_18 ) ;
return V_43 ;
}
static void F_47 ( struct V_6 * V_7 , enum V_22 type ,
struct V_17 * V_18 , T_4 V_28 )
{
V_7 -> V_70 ( V_7 -> V_72 , type , V_18 -> V_26 , V_28 ) ;
}
static void F_48 ( struct V_17 * V_18 )
{
F_49 ( V_18 -> V_7 -> V_73 , & V_18 -> V_27 ) ;
}
static int F_50 ( const struct V_17 * V_18 )
{
const struct V_42 * error = ( const struct V_42 * ) V_18 ;
if ( V_18 -> V_27 . V_30 != V_47 )
return false ;
switch ( error -> error ) {
case V_74 :
case V_75 :
case V_76 :
return true ;
default:
return false ;
}
}
static void F_51 ( struct V_63 * V_64 , struct V_65 * V_27 ,
bool V_66 )
{
struct V_17 * V_18 = F_9 ( V_27 , F_10 ( * V_18 ) , V_27 ) ;
struct V_1 * V_2 ;
T_3 V_77 ;
if ( V_66 )
return;
if ( V_27 -> V_28 < 4 || V_27 -> V_28 % 4 != 0 ) {
F_52 ( V_18 -> V_7 , L_16 ,
V_27 -> V_28 ) ;
goto V_73;
}
V_27 -> V_28 -= 4 ;
V_77 = F_38 ( V_18 -> V_26 , V_27 -> V_28 ) ;
F_36 ( V_18 -> V_26 , V_18 -> V_26 , V_27 -> V_28 / 4 ) ;
switch ( V_27 -> V_30 ) {
case V_78 :
case V_79 :
case V_47 :
case V_80 :
case V_81 :
if ( * ( T_3 * ) ( V_18 -> V_26 + V_27 -> V_28 ) != V_77 ) {
F_52 ( V_18 -> V_7 ,
L_17 ) ;
goto V_73;
}
if ( F_50 ( V_18 ) ) {
F_47 ( V_18 -> V_7 , V_27 -> V_30 ,
V_18 , V_27 -> V_28 ) ;
goto V_73;
}
break;
case V_82 :
if ( * ( T_3 * ) ( V_18 -> V_26 + V_27 -> V_28 ) != V_77 ) {
F_52 ( V_18 -> V_7 ,
L_17 ) ;
goto V_73;
}
case V_83 :
F_47 ( V_18 -> V_7 , V_27 -> V_30 , V_18 , V_27 -> V_28 ) ;
goto V_73;
default:
break;
}
V_2 = F_24 ( V_18 -> V_7 , V_18 ) ;
if ( V_2 ) {
if ( V_2 -> V_84 ( V_2 , V_18 ) )
F_53 ( & V_2 -> V_85 ) ;
F_12 ( V_2 ) ;
}
V_73:
F_48 ( V_18 ) ;
}
static void F_54 ( struct V_86 * V_85 )
{
struct V_1 * V_2 = F_9 ( V_85 , F_10 ( * V_2 ) , V_85 ) ;
if ( ! F_16 ( V_15 , & V_2 -> V_9 ) )
V_2 -> V_70 ( V_2 -> V_72 ) ;
F_19 ( V_2 ) ;
F_12 ( V_2 ) ;
}
int V_1 ( struct V_6 * V_7 , struct V_1 * V_2 ,
void (* V_70)( void * ) , void * V_72 )
{
int V_87 ;
V_2 -> V_9 = 0 ;
V_2 -> V_70 = V_70 ;
V_2 -> V_72 = V_72 ;
F_55 ( & V_2 -> V_85 , F_54 ) ;
F_56 ( & V_2 -> V_13 ) ;
F_4 ( V_2 ) ;
V_87 = F_14 ( V_7 , V_2 ) ;
if ( V_87 )
goto V_88;
V_87 = F_45 ( V_7 , V_2 -> V_89 , V_2 -> V_90 ,
V_2 -> V_91 ) ;
if ( V_87 )
goto V_92;
if ( ! V_2 -> V_41 )
F_53 ( & V_2 -> V_85 ) ;
return 0 ;
V_92:
F_19 ( V_2 ) ;
V_88:
F_12 ( V_2 ) ;
return V_87 ;
}
void F_57 ( struct V_1 * V_2 , int V_46 )
{
F_18 ( V_15 , & V_2 -> V_9 ) ;
F_53 ( & V_2 -> V_85 ) ;
F_58 ( V_16 , ! F_23 ( V_2 ) ) ;
V_2 -> V_93 . V_46 = V_46 ;
}
static void F_59 ( void * V_60 )
{
F_60 ( V_60 ) ;
}
struct V_40 F_61 ( struct V_6 * V_7 ,
struct V_1 * V_2 ,
int V_94 )
{
unsigned long V_95 = F_62 ( V_94 ) ;
struct V_40 V_43 = { 0 } ;
F_63 ( V_96 ) ;
int V_87 ;
V_87 = V_1 ( V_7 , V_2 , F_59 , & V_96 ) ;
if ( V_87 ) {
V_43 . V_46 = V_87 ;
return V_43 ;
}
if ( ! F_64 ( & V_96 , V_95 ) )
F_57 ( V_2 , - V_97 ) ;
F_65 ( & V_2 -> V_85 ) ;
return V_2 -> V_93 ;
}
struct V_6 * F_66 ( struct V_98 * V_99 , T_5 V_100 , void * V_101 )
{
int V_59 ;
struct V_6 * V_7 = F_2 ( sizeof( * V_7 ) , V_3 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_99 = V_99 ;
V_7 -> V_70 = V_100 ;
V_7 -> V_72 = V_101 ;
F_67 ( & V_7 -> V_10 ) ;
F_56 ( & V_7 -> V_14 ) ;
V_7 -> V_61 = F_68 ( L_18 , & V_99 -> V_102 -> V_103 ,
V_68 , 4 , 0 ) ;
if ( ! V_7 -> V_61 )
goto V_46;
V_7 -> V_71 = F_69 ( V_99 , 0 , 10 , V_104 ) ;
if ( ! V_7 -> V_71 )
goto V_46;
V_7 -> V_73 = F_70 ( V_99 , 0 , 10 , V_104 ) ;
if ( ! V_7 -> V_73 )
goto V_46;
for ( V_59 = 0 ; V_59 < V_105 ; V_59 ++ ) {
V_7 -> V_106 [ V_59 ] = F_42 ( V_7 ) ;
if ( ! V_7 -> V_106 [ V_59 ] )
goto V_46;
V_7 -> V_106 [ V_59 ] -> V_27 . V_70 = F_51 ;
}
F_71 ( V_7 , L_19 ) ;
return V_7 ;
V_46:
F_72 ( V_7 ) ;
return NULL ;
}
void F_72 ( struct V_6 * V_7 )
{
int V_59 ;
if ( ! V_7 )
return;
if ( V_7 -> V_73 )
F_73 ( V_7 -> V_73 ) ;
if ( V_7 -> V_71 )
F_73 ( V_7 -> V_71 ) ;
for ( V_59 = 0 ; V_59 < V_105 ; V_59 ++ )
F_40 ( V_7 -> V_106 [ V_59 ] ) ;
if ( V_7 -> V_61 )
F_74 ( V_7 -> V_61 ) ;
F_11 ( V_7 ) ;
}
void F_75 ( struct V_6 * V_7 )
{
int V_59 ;
F_71 ( V_7 , L_20 ) ;
F_76 ( V_7 -> V_71 ) ;
F_76 ( V_7 -> V_73 ) ;
for ( V_59 = 0 ; V_59 < V_105 ; V_59 ++ )
F_48 ( V_7 -> V_106 [ V_59 ] ) ;
V_7 -> V_11 = true ;
}
void F_77 ( struct V_6 * V_7 )
{
F_5 ( & V_7 -> V_10 ) ;
V_7 -> V_11 = false ;
F_7 ( & V_7 -> V_10 ) ;
F_78 ( V_7 -> V_73 ) ;
F_78 ( V_7 -> V_71 ) ;
if ( ! F_79 ( & V_7 -> V_14 ) )
F_33 ( V_7 , L_21 ) ;
F_56 ( & V_7 -> V_14 ) ;
F_71 ( V_7 , L_22 ) ;
}
int F_80 ( struct V_6 * V_7 , T_2 V_23 , T_1 V_52 ,
enum F_80 error )
{
struct V_42 V_18 = {
. V_25 = F_81 ( V_23 ) ,
. V_52 = V_52 ,
. error = error ,
} ;
F_71 ( V_7 , L_23 , V_23 , V_52 ) ;
return F_45 ( V_7 , & V_18 , sizeof( V_18 ) , V_47 ) ;
}
static bool F_82 ( const struct V_1 * V_2 ,
const struct V_17 * V_18 )
{
T_2 V_23 = F_28 ( V_18 -> V_26 ) & ~ F_83 ( 63 ) ;
if ( V_18 -> V_27 . V_30 == V_47 )
return true ;
if ( V_18 -> V_27 . V_30 != V_2 -> V_107 )
return false ;
if ( V_23 != F_28 ( V_2 -> V_89 ) )
return false ;
if ( V_18 -> V_27 . V_28 != V_2 -> V_108 )
return false ;
if ( V_18 -> V_27 . V_30 == V_78 ||
V_18 -> V_27 . V_30 == V_79 ) {
const struct V_109 * V_110 = V_2 -> V_89 ;
const struct V_109 * V_111 = V_18 -> V_26 ;
if ( V_110 -> V_34 . V_112 != V_111 -> V_34 . V_112 )
return false ;
}
return true ;
}
static bool F_84 ( struct V_1 * V_2 , const struct V_17 * V_18 )
{
struct V_40 V_43 ;
V_43 = F_31 ( V_18 , V_2 -> V_108 , V_2 -> V_107 ,
F_28 ( V_2 -> V_89 ) ) ;
if ( ! V_43 . V_46 )
memcpy ( V_2 -> V_41 , V_18 -> V_26 , V_2 -> V_108 ) ;
V_2 -> V_93 = V_43 ;
return true ;
}
struct V_40 F_85 ( struct V_6 * V_7 , T_2 V_23 ,
int V_94 )
{
struct V_113 V_89 = { . V_25 = F_81 (route) } ;
struct V_40 V_43 = { 0 } ;
struct V_24 V_114 ;
struct V_1 * V_2 ;
V_2 = F_1 () ;
if ( ! V_2 ) {
V_43 . V_46 = - V_69 ;
return V_43 ;
}
V_2 -> V_20 = F_82 ;
V_2 -> V_84 = F_84 ;
V_2 -> V_89 = & V_89 ;
V_2 -> V_90 = sizeof( V_89 ) ;
V_2 -> V_91 = V_81 ;
V_2 -> V_41 = & V_114 ;
V_2 -> V_108 = sizeof( V_114 ) ;
V_2 -> V_107 = sizeof( V_81 ) ;
V_43 = F_61 ( V_7 , V_2 , V_94 ) ;
F_12 ( V_2 ) ;
return V_43 ;
}
struct V_40 F_86 ( struct V_6 * V_7 , void * V_26 ,
T_2 V_23 , T_1 V_52 , enum V_35 V_36 ,
T_1 V_37 , T_1 V_38 , int V_94 )
{
struct V_40 V_43 = { 0 } ;
struct V_109 V_89 = {
. V_25 = F_81 ( V_23 ) ,
. V_34 = {
. V_52 = V_52 ,
. V_36 = V_36 ,
. V_37 = V_37 ,
. V_38 = V_38 ,
} ,
} ;
struct V_115 V_114 ;
int V_116 = 0 ;
while ( V_116 < V_117 ) {
struct V_1 * V_2 ;
V_2 = F_1 () ;
if ( ! V_2 ) {
V_43 . V_46 = - V_69 ;
return V_43 ;
}
V_89 . V_34 . V_112 = V_116 ++ ;
V_2 -> V_20 = F_82 ;
V_2 -> V_84 = F_84 ;
V_2 -> V_89 = & V_89 ;
V_2 -> V_90 = sizeof( V_89 ) ;
V_2 -> V_91 = V_78 ;
V_2 -> V_41 = & V_114 ;
V_2 -> V_108 = 12 + 4 * V_38 ;
V_2 -> V_107 = V_78 ;
V_43 = F_61 ( V_7 , V_2 , V_94 ) ;
F_12 ( V_2 ) ;
if ( V_43 . V_46 != - V_97 )
break;
F_87 ( 10 , 100 ) ;
}
if ( V_43 . V_46 )
return V_43 ;
V_43 . V_45 = V_114 . V_34 . V_52 ;
V_43 . V_46 = F_29 ( V_114 . V_34 , V_36 , V_37 , V_38 ) ;
if ( ! V_43 . V_46 )
memcpy ( V_26 , & V_114 . V_60 , 4 * V_38 ) ;
return V_43 ;
}
struct V_40 F_88 ( struct V_6 * V_7 , const void * V_26 ,
T_2 V_23 , T_1 V_52 , enum V_35 V_36 ,
T_1 V_37 , T_1 V_38 , int V_94 )
{
struct V_40 V_43 = { 0 } ;
struct V_115 V_89 = {
. V_25 = F_81 ( V_23 ) ,
. V_34 = {
. V_52 = V_52 ,
. V_36 = V_36 ,
. V_37 = V_37 ,
. V_38 = V_38 ,
} ,
} ;
struct V_109 V_114 ;
int V_116 = 0 ;
memcpy ( & V_89 . V_60 , V_26 , V_38 * 4 ) ;
while ( V_116 < V_117 ) {
struct V_1 * V_2 ;
V_2 = F_1 () ;
if ( ! V_2 ) {
V_43 . V_46 = - V_69 ;
return V_43 ;
}
V_89 . V_34 . V_112 = V_116 ++ ;
V_2 -> V_20 = F_82 ;
V_2 -> V_84 = F_84 ;
V_2 -> V_89 = & V_89 ;
V_2 -> V_90 = 12 + 4 * V_38 ;
V_2 -> V_91 = V_79 ;
V_2 -> V_41 = & V_114 ;
V_2 -> V_108 = sizeof( V_114 ) ;
V_2 -> V_107 = V_79 ;
V_43 = F_61 ( V_7 , V_2 , V_94 ) ;
F_12 ( V_2 ) ;
if ( V_43 . V_46 != - V_97 )
break;
F_87 ( 10 , 100 ) ;
}
if ( V_43 . V_46 )
return V_43 ;
V_43 . V_45 = V_114 . V_34 . V_52 ;
V_43 . V_46 = F_29 ( V_114 . V_34 , V_36 , V_37 , V_38 ) ;
return V_43 ;
}
int F_89 ( struct V_6 * V_7 , void * V_26 , T_2 V_23 , T_1 V_52 ,
enum V_35 V_36 , T_1 V_37 , T_1 V_38 )
{
struct V_40 V_43 = F_86 ( V_7 , V_26 , V_23 , V_52 ,
V_36 , V_37 , V_38 , V_118 ) ;
switch ( V_43 . V_46 ) {
case 0 :
break;
case 1 :
F_32 ( V_7 , & V_43 ) ;
return - V_29 ;
case - V_97 :
F_90 ( V_7 , L_24 ,
V_36 , V_37 ) ;
break;
default:
F_27 ( 1 , L_25 , V_43 . V_46 ) ;
break;
}
return V_43 . V_46 ;
}
int F_91 ( struct V_6 * V_7 , const void * V_26 , T_2 V_23 , T_1 V_52 ,
enum V_35 V_36 , T_1 V_37 , T_1 V_38 )
{
struct V_40 V_43 = F_88 ( V_7 , V_26 , V_23 , V_52 ,
V_36 , V_37 , V_38 , V_118 ) ;
switch ( V_43 . V_46 ) {
case 0 :
break;
case 1 :
F_32 ( V_7 , & V_43 ) ;
return - V_29 ;
case - V_97 :
F_90 ( V_7 , L_26 ,
V_36 , V_37 ) ;
break;
default:
F_27 ( 1 , L_27 , V_43 . V_46 ) ;
break;
}
return V_43 . V_46 ;
}
int F_92 ( struct V_6 * V_7 , T_2 V_23 )
{
T_1 V_119 ;
struct V_40 V_43 = F_86 ( V_7 , & V_119 , V_23 , 0 ,
V_120 , 0 , 1 ,
V_118 ) ;
if ( V_43 . V_46 == 1 )
return - V_29 ;
if ( V_43 . V_46 )
return V_43 . V_46 ;
return V_43 . V_45 ;
}
