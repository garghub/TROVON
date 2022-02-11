static int F_1 ( const char * V_1 , char * V_2 )
{
char * V_3 = V_2 ;
while ( * V_1 == '/' || * V_1 == '.' )
V_1 ++ ;
if ( V_2 ) {
for (; * V_1 ; V_1 ++ ) {
if ( * V_1 == '/' )
* ( V_3 ) ++ = '.' ;
else if ( isspace ( * V_1 ) )
* ( V_3 ) ++ = '_' ;
else if ( isalnum ( * V_1 ) || strchr ( L_1 , * V_1 ) )
* ( V_3 ) ++ = * V_1 ;
}
* V_3 = 0 ;
} else {
int V_4 = 0 ;
for (; * V_1 ; V_1 ++ ) {
if ( isalnum ( * V_1 ) || isspace ( * V_1 ) ||
strchr ( L_2 , * V_1 ) )
V_4 ++ ;
}
return V_4 ;
}
return V_3 - V_2 ;
}
static struct V_5 * F_2 ( const char T_1 * V_6 ,
T_2 V_7 ,
T_2 V_8 ,
T_3 * V_9 )
{
struct V_5 * V_10 ;
F_3 ( V_8 > V_7 ) ;
if ( * V_9 != 0 )
return F_4 ( - V_11 ) ;
V_10 = F_5 ( sizeof( * V_10 ) + V_7 , V_12 ) ;
if ( V_10 == NULL )
return F_4 ( - V_13 ) ;
F_6 ( & V_10 -> V_14 ) ;
V_10 -> V_15 = V_8 ;
V_10 -> V_16 = NULL ;
V_10 -> V_17 = 0 ;
if ( F_7 ( V_10 -> V_10 , V_6 , V_8 ) ) {
F_8 ( V_10 ) ;
return F_4 ( - V_18 ) ;
}
return V_10 ;
}
static T_4 F_9 ( int V_19 , const char T_1 * V_20 , T_2 V_15 ,
T_3 * V_9 , struct V_21 * V_22 )
{
T_4 error ;
struct V_5 * V_10 ;
struct V_23 * V_24 = F_10 () ;
const char * V_25 = V_19 == V_26 ? V_27 : V_28 ;
error = F_11 ( V_24 , V_22 , V_25 ) ;
if ( error )
return error ;
V_10 = F_2 ( V_20 , V_15 , V_15 , V_9 ) ;
error = F_12 ( V_10 ) ;
if ( ! F_13 ( V_10 ) ) {
error = F_14 ( V_22 ? V_22 : V_24 -> V_22 , V_24 ,
V_19 , V_10 ) ;
F_15 ( V_10 ) ;
}
return error ;
}
static T_4 F_16 ( struct V_29 * V_30 , const char T_1 * V_20 , T_2 V_15 ,
T_3 * V_9 )
{
struct V_21 * V_22 = F_17 ( V_30 -> V_31 -> V_32 ) ;
int error = F_9 ( V_26 , V_20 , V_15 , V_9 , V_22 ) ;
F_18 ( V_22 ) ;
return error ;
}
static T_4 F_19 ( struct V_29 * V_30 , const char T_1 * V_20 ,
T_2 V_15 , T_3 * V_9 )
{
struct V_21 * V_22 = F_17 ( V_30 -> V_31 -> V_32 ) ;
int error = F_9 ( V_33 , V_20 , V_15 , V_9 , V_22 ) ;
F_18 ( V_22 ) ;
return error ;
}
static T_4 F_20 ( struct V_29 * V_30 , const char T_1 * V_20 ,
T_2 V_15 , T_3 * V_9 )
{
struct V_5 * V_10 ;
struct V_23 * V_24 ;
T_4 error ;
struct V_21 * V_22 = F_17 ( V_30 -> V_31 -> V_32 ) ;
V_24 = F_10 () ;
error = F_11 ( V_24 , V_22 , V_34 ) ;
if ( error )
goto V_35;
V_10 = F_2 ( V_20 , V_15 + 1 , V_15 , V_9 ) ;
error = F_12 ( V_10 ) ;
if ( ! F_13 ( V_10 ) ) {
V_10 -> V_10 [ V_15 ] = 0 ;
error = F_21 ( V_22 ? V_22 : V_24 -> V_22 , V_24 ,
V_10 -> V_10 , V_15 ) ;
F_15 ( V_10 ) ;
}
V_35:
F_18 ( V_22 ) ;
return error ;
}
static T_4 F_22 ( char * V_20 , T_2 V_36 ,
char * V_37 , T_2 V_38 )
{
char * V_35 ;
const char * V_39 ;
struct V_23 * V_24 ;
struct V_40 * V_10 ;
T_5 V_41 , V_42 ;
T_6 V_43 ;
if ( ! V_38 )
return - V_44 ;
V_39 = V_37 + F_23 ( V_37 , V_38 ) + 1 ;
if ( V_39 + 1 >= V_37 + V_38 )
return - V_44 ;
if ( V_39 + F_23 ( V_39 , V_37 + V_38 - V_39 ) >= V_37 + V_38 )
return - V_44 ;
if ( V_36 < sizeof( V_41 ) + sizeof( V_42 ) )
return - V_44 ;
V_24 = F_10 () ;
memset ( V_20 , 0 , sizeof( V_41 ) + sizeof( V_42 ) ) ;
V_35 = V_20 + sizeof( V_41 ) + sizeof( V_42 ) ;
V_42 = 0 ;
if ( V_24 -> V_10 ) {
V_10 = F_24 ( V_24 -> V_10 , & V_39 ,
V_24 -> V_10 -> V_45 ) ;
if ( V_10 ) {
if ( V_35 + sizeof( V_43 ) + V_10 -> V_15 > V_20 + V_36 )
return - V_44 ;
V_43 = F_25 ( V_10 -> V_15 ) ;
memcpy ( V_35 , & V_43 , sizeof( V_43 ) ) ;
V_35 += sizeof( V_43 ) ;
memcpy ( V_35 , V_10 -> V_10 , V_10 -> V_15 ) ;
V_35 += V_10 -> V_15 ;
V_42 ++ ;
}
}
V_43 = F_25 ( V_35 - V_20 - sizeof( V_41 ) ) ;
memcpy ( V_20 , & V_43 , sizeof( V_43 ) ) ;
V_43 = F_25 ( V_42 ) ;
memcpy ( V_20 + sizeof( V_41 ) , & V_43 , sizeof( V_43 ) ) ;
return V_35 - V_20 ;
}
static T_4 F_26 ( struct V_29 * V_29 , const char T_1 * V_46 ,
T_2 V_14 , T_3 * V_47 )
{
char * V_20 ;
T_4 V_4 ;
if ( * V_47 )
return - V_11 ;
V_20 = F_27 ( V_29 , V_46 , V_14 ) ;
if ( F_13 ( V_20 ) )
return F_12 ( V_20 ) ;
if ( V_14 > V_48 &&
! memcmp ( V_20 , V_49 , V_48 ) ) {
V_4 = F_22 ( V_20 , V_50 ,
V_20 + V_48 ,
V_14 - V_48 ) ;
} else
V_4 = - V_44 ;
if ( V_4 < 0 )
return V_4 ;
F_28 ( V_29 , V_4 ) ;
return V_14 ;
}
static int F_29 ( struct V_51 * V_52 , void * V_53 )
{
struct V_54 * V_55 = V_52 -> V_56 ;
if ( ! V_55 )
return 0 ;
switch ( V_55 -> V_57 ) {
case V_58 :
F_30 ( V_52 , L_3 , V_55 -> V_53 . boolean ? L_4 : L_5 ) ;
break;
case V_59 :
F_30 ( V_52 , L_3 , V_55 -> V_53 . string ) ;
break;
case V_60 :
F_30 ( V_52 , L_6 , V_55 -> V_53 . V_61 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_31 ( struct V_62 * V_62 , struct V_29 * V_29 )
{
return F_32 ( V_29 , F_29 , V_62 -> V_32 ) ;
}
static int F_33 ( struct V_62 * V_62 , struct V_29 * V_29 ,
int (* F_34)( struct V_51 * , void * ) )
{
struct V_63 * V_64 = F_35 ( V_62 -> V_32 ) ;
int error = F_32 ( V_29 , F_34 , V_64 ) ;
if ( error ) {
V_29 -> V_65 = NULL ;
F_36 ( V_64 ) ;
}
return error ;
}
static int F_37 ( struct V_62 * V_62 , struct V_29 * V_29 )
{
struct V_51 * V_52 = (struct V_51 * ) V_29 -> V_65 ;
if ( V_52 )
F_36 ( V_52 -> V_56 ) ;
return F_38 ( V_62 , V_29 ) ;
}
static int F_39 ( struct V_51 * V_52 , void * V_53 )
{
struct V_63 * V_64 = V_52 -> V_56 ;
struct V_23 * V_24 = F_40 ( & V_64 -> V_24 ) ;
F_30 ( V_52 , L_3 , V_24 -> V_66 . V_1 ) ;
F_41 ( V_24 ) ;
return 0 ;
}
static int F_42 ( struct V_62 * V_62 , struct V_29 * V_29 )
{
return F_33 ( V_62 , V_29 , F_39 ) ;
}
static int F_43 ( struct V_51 * V_52 , void * V_53 )
{
struct V_63 * V_64 = V_52 -> V_56 ;
struct V_23 * V_24 = F_40 ( & V_64 -> V_24 ) ;
F_30 ( V_52 , L_3 , V_67 [ V_24 -> V_68 ] ) ;
F_41 ( V_24 ) ;
return 0 ;
}
static int F_44 ( struct V_62 * V_62 , struct V_29 * V_29 )
{
return F_33 ( V_62 , V_29 , F_43 ) ;
}
static int F_45 ( struct V_51 * V_52 , void * V_53 )
{
struct V_63 * V_64 = V_52 -> V_56 ;
struct V_23 * V_24 = F_40 ( & V_64 -> V_24 ) ;
if ( V_24 -> V_69 )
F_30 ( V_52 , L_3 , V_24 -> V_69 ) ;
else if ( V_24 -> V_70 )
F_46 ( V_52 , L_7 ) ;
else
F_30 ( V_52 , L_3 , V_24 -> V_66 . V_1 ) ;
F_41 ( V_24 ) ;
return 0 ;
}
static int F_47 ( struct V_62 * V_62 , struct V_29 * V_29 )
{
return F_33 ( V_62 , V_29 , F_45 ) ;
}
static int F_48 ( struct V_51 * V_52 , void * V_53 )
{
struct V_63 * V_64 = V_52 -> V_56 ;
struct V_23 * V_24 = F_40 ( & V_64 -> V_24 ) ;
unsigned int V_71 , V_15 = F_49 () ;
if ( V_24 -> V_16 ) {
for ( V_71 = 0 ; V_71 < V_15 ; V_71 ++ )
F_30 ( V_52 , L_8 , V_24 -> V_16 [ V_71 ] ) ;
F_46 ( V_52 , L_9 ) ;
}
F_41 ( V_24 ) ;
return 0 ;
}
static int F_50 ( struct V_62 * V_62 , struct V_29 * V_29 )
{
return F_32 ( V_29 , F_48 , V_62 -> V_32 ) ;
}
static int F_51 ( struct V_51 * V_52 , void * V_53 )
{
struct V_21 * V_22 = F_10 () -> V_22 ;
F_30 ( V_52 , L_10 , V_22 -> V_72 ) ;
return 0 ;
}
static int F_52 ( struct V_62 * V_62 , struct V_29 * V_29 )
{
return F_32 ( V_29 , F_51 , V_62 -> V_32 ) ;
}
static int F_53 ( struct V_51 * V_52 , void * V_53 )
{
struct V_21 * V_22 = F_10 () -> V_22 ;
F_30 ( V_52 , L_3 , V_22 -> V_66 . V_1 ) ;
return 0 ;
}
static int F_54 ( struct V_62 * V_62 , struct V_29 * V_29 )
{
return F_32 ( V_29 , F_53 , V_62 -> V_32 ) ;
}
static int F_55 ( struct V_62 * V_62 , struct V_29 * V_29 )
{
F_15 ( V_29 -> V_65 ) ;
return 0 ;
}
static int F_56 ( struct V_51 * V_52 , void * V_53 )
{
struct V_63 * V_64 = V_52 -> V_56 ;
struct V_23 * V_24 = F_40 ( & V_64 -> V_24 ) ;
if ( V_24 -> V_73 -> V_17 ) {
F_30 ( V_52 , L_11 , V_24 -> V_73 -> V_17 ) ;
F_46 ( V_52 , L_9 ) ;
}
F_41 ( V_24 ) ;
return 0 ;
}
static int F_57 ( struct V_62 * V_62 , struct V_29 * V_29 )
{
return F_33 ( V_62 , V_29 , F_56 ) ;
}
static int F_58 ( struct V_51 * V_52 , void * V_53 )
{
struct V_63 * V_64 = V_52 -> V_56 ;
struct V_23 * V_24 = F_40 ( & V_64 -> V_24 ) ;
unsigned int V_71 , V_15 = F_49 () ;
if ( V_24 -> V_73 -> V_16 ) {
for ( V_71 = 0 ; V_71 < V_15 ; V_71 ++ )
F_30 ( V_52 , L_8 , V_24 -> V_73 -> V_16 [ V_71 ] ) ;
F_46 ( V_52 , L_9 ) ;
}
F_41 ( V_24 ) ;
return 0 ;
}
static int F_59 ( struct V_62 * V_62 , struct V_29 * V_29 )
{
return F_33 ( V_62 , V_29 , F_58 ) ;
}
static T_4 F_60 ( struct V_29 * V_29 , char T_1 * V_20 , T_2 V_15 ,
T_3 * V_47 )
{
struct V_5 * V_73 = V_29 -> V_65 ;
return F_61 ( V_20 , V_15 , V_47 , V_73 -> V_10 ,
V_73 -> V_15 ) ;
}
static int F_62 ( struct V_62 * V_62 , struct V_29 * V_29 )
{
struct V_63 * V_64 = V_62 -> V_32 ;
struct V_23 * V_24 ;
if ( ! F_63 ( NULL ) )
return - V_74 ;
V_24 = F_40 ( & V_64 -> V_24 ) ;
V_29 -> V_65 = F_64 ( V_24 -> V_73 ) ;
F_41 ( V_24 ) ;
return 0 ;
}
void F_65 ( struct V_23 * V_24 )
{
struct V_23 * V_75 ;
int V_71 ;
if ( ! V_24 )
return;
F_66 (child, &profile->base.profiles, base.list)
F_65 ( V_75 ) ;
for ( V_71 = V_76 - 1 ; V_71 >= 0 ; -- V_71 ) {
struct V_63 * V_64 ;
if ( ! V_24 -> V_77 [ V_71 ] )
continue;
V_64 = F_67 ( V_24 -> V_77 [ V_71 ] ) -> V_32 ;
F_68 ( V_24 -> V_77 [ V_71 ] ) ;
F_36 ( V_64 ) ;
V_24 -> V_77 [ V_71 ] = NULL ;
}
}
void F_69 ( struct V_23 * V_78 ,
struct V_23 * V_79 )
{
int V_71 ;
for ( V_71 = 0 ; V_71 < V_76 ; V_71 ++ ) {
V_79 -> V_77 [ V_71 ] = V_78 -> V_77 [ V_71 ] ;
if ( V_79 -> V_77 [ V_71 ] )
V_79 -> V_77 [ V_71 ] -> F_67 -> V_80 = F_70 ( V_79 -> V_77 [ V_71 ] -> F_67 ) ;
V_78 -> V_77 [ V_71 ] = NULL ;
}
}
static struct V_81 * F_71 ( struct V_81 * V_82 , const char * V_1 ,
struct V_23 * V_24 ,
const struct V_83 * V_84 )
{
struct V_63 * V_64 = F_35 ( V_24 -> V_64 ) ;
struct V_81 * V_85 ;
V_85 = F_72 ( V_1 , V_86 | 0444 , V_82 , V_64 , V_84 ) ;
if ( F_13 ( V_85 ) )
F_36 ( V_64 ) ;
return V_85 ;
}
int F_73 ( struct V_23 * V_24 , struct V_81 * V_87 )
{
struct V_23 * V_75 ;
struct V_81 * V_85 = NULL , * V_82 ;
int error ;
if ( ! V_87 ) {
struct V_23 * V_45 ;
V_45 = F_74 ( V_24 ) ;
V_85 = F_75 ( V_45 ) ;
V_85 = F_76 ( L_12 , V_85 ) ;
if ( F_13 ( V_85 ) )
goto V_88;
F_77 ( V_45 ) = V_87 = V_85 ;
}
if ( ! V_24 -> V_89 ) {
int V_4 , V_90 ;
V_4 = F_1 ( V_24 -> V_66 . V_1 , NULL ) ;
V_90 = snprintf ( NULL , 0 , L_13 , V_24 -> V_22 -> V_91 ) ;
V_24 -> V_89 = F_78 ( V_4 + V_90 + 1 , V_12 ) ;
if ( ! V_24 -> V_89 )
goto V_88;
F_1 ( V_24 -> V_66 . V_1 , V_24 -> V_89 ) ;
sprintf ( V_24 -> V_89 + V_4 , L_13 , V_24 -> V_22 -> V_91 ++ ) ;
}
V_85 = F_76 ( V_24 -> V_89 , V_87 ) ;
if ( F_13 ( V_85 ) )
goto V_88;
F_75 ( V_24 ) = V_82 = V_85 ;
V_85 = F_71 ( V_82 , L_14 , V_24 , & V_92 ) ;
if ( F_13 ( V_85 ) )
goto V_88;
V_24 -> V_77 [ V_93 ] = V_85 ;
V_85 = F_71 ( V_82 , L_15 , V_24 , & V_94 ) ;
if ( F_13 ( V_85 ) )
goto V_88;
V_24 -> V_77 [ V_95 ] = V_85 ;
V_85 = F_71 ( V_82 , L_16 , V_24 ,
& V_96 ) ;
if ( F_13 ( V_85 ) )
goto V_88;
V_24 -> V_77 [ V_97 ] = V_85 ;
if ( V_24 -> V_16 ) {
V_85 = F_71 ( V_82 , L_17 , V_24 ,
& V_98 ) ;
if ( F_13 ( V_85 ) )
goto V_88;
V_24 -> V_77 [ V_99 ] = V_85 ;
}
if ( V_24 -> V_73 ) {
V_85 = F_71 ( V_82 , L_18 , V_24 ,
& V_100 ) ;
if ( F_13 ( V_85 ) )
goto V_88;
V_24 -> V_77 [ V_101 ] = V_85 ;
V_85 = F_71 ( V_82 , L_19 , V_24 ,
& V_102 ) ;
if ( F_13 ( V_85 ) )
goto V_88;
V_24 -> V_77 [ V_103 ] = V_85 ;
V_85 = F_72 ( L_20 , V_86 | 0444 , V_82 ,
V_24 -> V_64 ,
& V_104 ) ;
if ( F_13 ( V_85 ) )
goto V_88;
V_24 -> V_77 [ V_105 ] = V_85 ;
F_67 ( V_85 ) -> V_106 = V_24 -> V_73 -> V_15 ;
F_35 ( V_24 -> V_64 ) ;
}
F_66 (child, &profile->base.profiles, base.list) {
error = F_73 ( V_75 , F_77 ( V_24 ) ) ;
if ( error )
goto V_107;
}
return 0 ;
V_88:
error = F_12 ( V_85 ) ;
V_107:
F_65 ( V_24 ) ;
return error ;
}
void F_79 ( struct V_21 * V_22 )
{
struct V_21 * V_108 ;
struct V_23 * V_75 ;
int V_71 ;
if ( ! V_22 )
return;
F_66 (child, &ns->base.profiles, base.list)
F_65 ( V_75 ) ;
F_66 (sub, &ns->sub_ns, base.list) {
F_80 ( & V_108 -> V_109 ) ;
F_79 ( V_108 ) ;
F_81 ( & V_108 -> V_109 ) ;
}
if ( F_82 ( V_22 ) ) {
V_108 = F_67 ( F_82 ( V_22 ) ) -> V_32 ;
F_18 ( V_108 ) ;
}
if ( F_83 ( V_22 ) ) {
V_108 = F_67 ( F_83 ( V_22 ) ) -> V_32 ;
F_18 ( V_108 ) ;
}
if ( F_84 ( V_22 ) ) {
V_108 = F_67 ( F_84 ( V_22 ) ) -> V_32 ;
F_18 ( V_108 ) ;
}
if ( F_85 ( V_22 ) ) {
V_108 = F_67 ( F_85 ( V_22 ) ) -> V_32 ;
F_18 ( V_108 ) ;
}
for ( V_71 = V_110 - 1 ; V_71 >= 0 ; -- V_71 ) {
F_68 ( V_22 -> V_77 [ V_71 ] ) ;
V_22 -> V_77 [ V_71 ] = NULL ;
}
}
static int F_86 ( struct V_21 * V_22 , struct V_81 * V_82 )
{
struct V_81 * V_85 ;
F_3 ( ! V_22 ) ;
F_3 ( ! V_82 ) ;
V_85 = F_76 ( L_12 , V_82 ) ;
if ( F_13 ( V_85 ) )
return F_12 ( V_85 ) ;
F_87 ( V_22 ) = V_85 ;
V_85 = F_76 ( L_20 , V_82 ) ;
if ( F_13 ( V_85 ) )
return F_12 ( V_85 ) ;
F_88 ( V_22 ) = V_85 ;
V_85 = F_72 ( L_21 , 0640 , V_82 , V_22 ,
& V_111 ) ;
if ( F_13 ( V_85 ) )
return F_12 ( V_85 ) ;
F_17 ( V_22 ) ;
F_83 ( V_22 ) = V_85 ;
V_85 = F_72 ( L_22 , 0640 , V_82 , V_22 ,
& V_112 ) ;
if ( F_13 ( V_85 ) )
return F_12 ( V_85 ) ;
F_17 ( V_22 ) ;
F_84 ( V_22 ) = V_85 ;
V_85 = F_72 ( L_23 , 0640 , V_82 , V_22 ,
& V_113 ) ;
if ( F_13 ( V_85 ) )
return F_12 ( V_85 ) ;
F_17 ( V_22 ) ;
F_85 ( V_22 ) = V_85 ;
V_85 = F_76 ( L_24 , V_82 ) ;
if ( F_13 ( V_85 ) )
return F_12 ( V_85 ) ;
F_17 ( V_22 ) ;
F_82 ( V_22 ) = V_85 ;
return 0 ;
}
int F_89 ( struct V_21 * V_22 , struct V_81 * V_87 , const char * V_1 )
{
struct V_21 * V_108 ;
struct V_23 * V_75 ;
struct V_81 * V_85 , * V_82 ;
int error ;
F_3 ( ! V_22 ) ;
F_3 ( ! V_87 ) ;
F_3 ( ! F_90 ( & V_22 -> V_109 ) ) ;
if ( ! V_1 )
V_1 = V_22 -> V_66 . V_1 ;
V_85 = F_76 ( V_1 , V_87 ) ;
if ( F_13 ( V_85 ) )
goto V_88;
F_91 ( V_22 ) = V_82 = V_85 ;
error = F_86 ( V_22 , V_82 ) ;
if ( error )
goto V_107;
F_66 (child, &ns->base.profiles, base.list) {
error = F_73 ( V_75 , F_87 ( V_22 ) ) ;
if ( error )
goto V_107;
}
F_66 (sub, &ns->sub_ns, base.list) {
F_80 ( & V_108 -> V_109 ) ;
error = F_89 ( V_108 , F_82 ( V_22 ) , NULL ) ;
F_81 ( & V_108 -> V_109 ) ;
if ( error )
goto V_107;
}
return 0 ;
V_88:
error = F_12 ( V_85 ) ;
V_107:
F_79 ( V_22 ) ;
return error ;
}
static struct V_21 * F_92 ( struct V_21 * V_114 , struct V_21 * V_22 )
{
struct V_21 * V_87 , * V_115 ;
if ( ! F_93 ( & V_22 -> V_116 ) ) {
V_115 = F_94 ( & V_22 -> V_116 , F_95 ( * V_22 ) , V_66 . V_117 ) ;
F_80 ( & V_115 -> V_109 ) ;
return V_115 ;
}
V_87 = V_22 -> V_87 ;
while ( V_22 != V_114 ) {
F_81 ( & V_22 -> V_109 ) ;
V_115 = F_96 ( V_22 , V_66 . V_117 ) ;
if ( ! F_97 ( V_115 , & V_87 -> V_116 , V_66 . V_117 ) ) {
F_80 ( & V_115 -> V_109 ) ;
return V_115 ;
}
V_22 = V_87 ;
V_87 = V_87 -> V_87 ;
}
return NULL ;
}
static struct V_23 * F_98 ( struct V_21 * V_114 ,
struct V_21 * V_22 )
{
for (; V_22 ; V_22 = F_92 ( V_114 , V_22 ) ) {
if ( ! F_93 ( & V_22 -> V_66 . V_118 ) )
return F_94 ( & V_22 -> V_66 . V_118 ,
struct V_23 , V_66 . V_117 ) ;
}
return NULL ;
}
static struct V_23 * F_99 ( struct V_23 * V_45 )
{
struct V_23 * V_87 ;
struct V_21 * V_22 = V_45 -> V_22 ;
if ( ! F_93 ( & V_45 -> V_66 . V_118 ) )
return F_94 ( & V_45 -> V_66 . V_118 , F_95 ( * V_45 ) ,
V_66 . V_117 ) ;
V_87 = F_100 ( V_45 -> V_87 ,
F_90 ( & V_45 -> V_22 -> V_109 ) ) ;
while ( V_87 ) {
V_45 = F_96 ( V_45 , V_66 . V_117 ) ;
if ( ! F_97 ( V_45 , & V_87 -> V_66 . V_118 , V_66 . V_117 ) )
return V_45 ;
V_45 = V_87 ;
V_87 = F_100 ( V_87 -> V_87 ,
F_90 ( & V_87 -> V_22 -> V_109 ) ) ;
}
V_45 = F_96 ( V_45 , V_66 . V_117 ) ;
if ( ! F_97 ( V_45 , & V_22 -> V_66 . V_118 , V_66 . V_117 ) )
return V_45 ;
return NULL ;
}
static struct V_23 * F_101 ( struct V_21 * V_114 ,
struct V_23 * V_24 )
{
struct V_23 * V_115 = F_99 ( V_24 ) ;
if ( V_115 )
return V_115 ;
return F_98 ( V_114 , F_92 ( V_114 , V_24 -> V_22 ) ) ;
}
static void * F_102 ( struct V_51 * V_30 , T_3 * V_9 )
{
struct V_23 * V_24 = NULL ;
struct V_21 * V_114 = F_10 () -> V_22 ;
T_3 V_119 = * V_9 ;
V_30 -> V_56 = F_17 ( V_114 ) ;
F_80 ( & V_114 -> V_109 ) ;
V_24 = F_98 ( V_114 , V_114 ) ;
for (; V_24 && V_119 > 0 ; V_119 -- )
V_24 = F_101 ( V_114 , V_24 ) ;
return V_24 ;
}
static void * F_103 ( struct V_51 * V_30 , void * V_45 , T_3 * V_9 )
{
struct V_23 * V_24 = V_45 ;
struct V_21 * V_22 = V_30 -> V_56 ;
( * V_9 ) ++ ;
return F_101 ( V_22 , V_24 ) ;
}
static void F_104 ( struct V_51 * V_30 , void * V_45 )
{
struct V_23 * V_24 = V_45 ;
struct V_21 * V_114 = V_30 -> V_56 , * V_22 ;
if ( V_24 ) {
for ( V_22 = V_24 -> V_22 ; V_22 && V_22 != V_114 ; V_22 = V_22 -> V_87 )
F_81 ( & V_22 -> V_109 ) ;
}
F_81 ( & V_114 -> V_109 ) ;
F_18 ( V_114 ) ;
}
static int F_105 ( struct V_51 * V_30 , void * V_45 )
{
struct V_23 * V_24 = (struct V_23 * ) V_45 ;
struct V_21 * V_114 = V_30 -> V_56 ;
if ( V_24 -> V_22 != V_114 )
F_30 ( V_30 , L_25 , F_106 ( V_114 , V_24 -> V_22 , true ) ) ;
F_30 ( V_30 , L_26 , V_24 -> V_66 . V_120 ,
V_67 [ V_24 -> V_68 ] ) ;
return 0 ;
}
static int F_107 ( struct V_62 * V_62 , struct V_29 * V_29 )
{
if ( ! F_63 ( NULL ) )
return - V_74 ;
return F_108 ( V_29 , & V_121 ) ;
}
static int F_109 ( struct V_62 * V_62 , struct V_29 * V_29 )
{
return F_110 ( V_62 , V_29 ) ;
}
static int T_7 F_111 ( struct V_54 * V_55 ,
struct V_81 * V_87 )
{
int error = 0 ;
V_55 -> V_81 = F_72 ( V_55 -> V_1 ,
V_86 | V_55 -> V_68 ,
V_87 , V_55 ,
V_55 -> V_122 ) ;
if ( F_13 ( V_55 -> V_81 ) ) {
error = F_12 ( V_55 -> V_81 ) ;
V_55 -> V_81 = NULL ;
}
return error ;
}
static int T_7 F_112 ( struct V_54 * V_123 ,
struct V_81 * V_87 )
{
struct V_54 * V_55 ;
struct V_81 * V_82 ;
int error ;
V_82 = F_76 ( V_123 -> V_1 , V_87 ) ;
if ( F_13 ( V_82 ) )
return F_12 ( V_82 ) ;
V_123 -> V_81 = V_82 ;
for ( V_55 = V_123 -> V_53 . V_124 ; V_55 && V_55 -> V_1 ; ++ V_55 ) {
if ( V_55 -> V_57 == V_125 )
error = F_112 ( V_55 , V_123 -> V_81 ) ;
else
error = F_111 ( V_55 , V_123 -> V_81 ) ;
if ( error )
goto V_126;
}
return 0 ;
V_126:
F_113 ( V_123 ) ;
return error ;
}
static void T_7 F_114 ( struct V_54 * V_55 )
{
if ( ! V_55 -> V_81 )
return;
F_68 ( V_55 -> V_81 ) ;
V_55 -> V_81 = NULL ;
}
static void T_7 F_113 ( struct V_54 * V_123 )
{
struct V_54 * V_55 ;
for ( V_55 = V_123 -> V_53 . V_124 ; V_55 && V_55 -> V_1 ; ++ V_55 ) {
if ( V_55 -> V_57 == V_125 )
F_113 ( V_55 ) ;
else
F_114 ( V_55 ) ;
}
F_114 ( V_123 ) ;
}
void T_7 F_115 ( void )
{
F_113 ( & V_54 ) ;
}
static int F_116 ( struct V_81 * V_87 )
{
struct V_127 * V_128 = NULL ;
struct V_81 * V_81 ;
struct V_62 * V_62 ;
int V_14 = 0 ;
int error = F_117 ( V_87 -> V_129 -> V_130 , & V_128 , & V_14 ) ;
if ( error )
return error ;
F_118 ( F_67 ( V_87 ) ) ;
V_81 = F_119 ( V_131 , V_87 , strlen ( V_131 ) ) ;
if ( F_13 ( V_81 ) ) {
error = F_12 ( V_81 ) ;
goto V_35;
}
V_62 = F_120 ( V_87 -> F_67 -> V_132 ) ;
if ( ! V_62 ) {
error = - V_13 ;
goto V_133;
}
V_62 -> V_134 = F_121 () ;
V_62 -> V_135 = V_136 | V_137 | V_138 ;
V_62 -> V_139 = V_62 -> V_80 = V_62 -> V_140 = F_70 ( V_62 ) ;
F_122 ( V_62 , V_136 | V_137 | V_138 ,
F_123 ( V_141 , 3 ) ) ;
F_124 ( V_81 , V_62 ) ;
V_142 . V_81 = F_125 ( V_81 ) ;
V_142 . V_143 = F_126 ( V_128 ) ;
error = 0 ;
V_133:
F_127 ( V_81 ) ;
V_35:
F_128 ( F_67 ( V_87 ) ) ;
F_129 ( & V_128 , & V_14 ) ;
return error ;
}
static int T_7 F_130 ( void )
{
struct V_81 * V_85 ;
int error ;
if ( ! V_144 )
return 0 ;
if ( V_54 . V_81 ) {
F_131 ( L_27 , V_145 ) ;
return - V_146 ;
}
error = F_112 ( & V_54 , NULL ) ;
if ( error )
goto error;
V_85 = F_72 ( L_21 , 0666 , V_54 . V_81 ,
NULL , & V_111 ) ;
if ( F_13 ( V_85 ) ) {
error = F_12 ( V_85 ) ;
goto error;
}
F_83 ( V_147 ) = V_85 ;
V_85 = F_72 ( L_22 , 0666 , V_54 . V_81 ,
NULL , & V_112 ) ;
if ( F_13 ( V_85 ) ) {
error = F_12 ( V_85 ) ;
goto error;
}
F_84 ( V_147 ) = V_85 ;
V_85 = F_72 ( L_23 , 0666 , V_54 . V_81 ,
NULL , & V_113 ) ;
if ( F_13 ( V_85 ) ) {
error = F_12 ( V_85 ) ;
goto error;
}
F_85 ( V_147 ) = V_85 ;
F_80 ( & V_147 -> V_109 ) ;
error = F_89 ( V_147 , V_54 . V_81 , L_28 ) ;
F_81 ( & V_147 -> V_109 ) ;
if ( error )
goto error;
error = F_116 ( V_54 . V_81 ) ;
if ( error )
goto error;
F_132 ( L_29 ) ;
return 0 ;
error:
F_115 () ;
F_131 ( L_30 ) ;
return error ;
}
