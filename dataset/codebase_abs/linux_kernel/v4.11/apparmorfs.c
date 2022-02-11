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
V_10 = F_5 ( sizeof( * V_10 ) + V_7 ) ;
if ( V_10 == NULL )
return F_4 ( - V_12 ) ;
F_6 ( & V_10 -> V_13 ) ;
V_10 -> V_14 = V_8 ;
V_10 -> V_15 = NULL ;
V_10 -> V_16 = 0 ;
if ( F_7 ( V_10 -> V_10 , V_6 , V_8 ) ) {
F_8 ( V_10 ) ;
return F_4 ( - V_17 ) ;
}
return V_10 ;
}
static T_4 F_9 ( int V_18 , const char T_1 * V_19 , T_2 V_14 ,
T_3 * V_9 , struct V_20 * V_21 )
{
T_4 error ;
struct V_5 * V_10 ;
struct V_22 * V_23 = F_10 () ;
const char * V_24 = V_18 == V_25 ? V_26 : V_27 ;
error = F_11 ( V_23 , V_21 , V_24 ) ;
if ( error )
return error ;
V_10 = F_2 ( V_19 , V_14 , V_14 , V_9 ) ;
error = F_12 ( V_10 ) ;
if ( ! F_13 ( V_10 ) ) {
error = F_14 ( V_21 ? V_21 : V_23 -> V_21 , V_23 ,
V_18 , V_10 ) ;
F_15 ( V_10 ) ;
}
return error ;
}
static T_4 F_16 ( struct V_28 * V_29 , const char T_1 * V_19 , T_2 V_14 ,
T_3 * V_9 )
{
struct V_20 * V_21 = F_17 ( V_29 -> V_30 -> V_31 ) ;
int error = F_9 ( V_25 , V_19 , V_14 , V_9 , V_21 ) ;
F_18 ( V_21 ) ;
return error ;
}
static T_4 F_19 ( struct V_28 * V_29 , const char T_1 * V_19 ,
T_2 V_14 , T_3 * V_9 )
{
struct V_20 * V_21 = F_17 ( V_29 -> V_30 -> V_31 ) ;
int error = F_9 ( V_32 , V_19 , V_14 , V_9 , V_21 ) ;
F_18 ( V_21 ) ;
return error ;
}
static T_4 F_20 ( struct V_28 * V_29 , const char T_1 * V_19 ,
T_2 V_14 , T_3 * V_9 )
{
struct V_5 * V_10 ;
struct V_22 * V_23 ;
T_4 error ;
struct V_20 * V_21 = F_17 ( V_29 -> V_30 -> V_31 ) ;
V_23 = F_10 () ;
error = F_11 ( V_23 , V_21 , V_33 ) ;
if ( error )
goto V_34;
V_10 = F_2 ( V_19 , V_14 + 1 , V_14 , V_9 ) ;
error = F_12 ( V_10 ) ;
if ( ! F_13 ( V_10 ) ) {
V_10 -> V_10 [ V_14 ] = 0 ;
error = F_21 ( V_21 ? V_21 : V_23 -> V_21 , V_23 ,
V_10 -> V_10 , V_14 ) ;
F_15 ( V_10 ) ;
}
V_34:
F_18 ( V_21 ) ;
return error ;
}
static T_4 F_22 ( char * V_19 , T_2 V_35 ,
char * V_36 , T_2 V_37 )
{
char * V_34 ;
const char * V_38 ;
struct V_22 * V_23 ;
struct V_39 * V_10 ;
T_5 V_40 , V_41 ;
T_6 V_42 ;
if ( ! V_37 )
return - V_43 ;
V_38 = V_36 + F_23 ( V_36 , V_37 ) + 1 ;
if ( V_38 + 1 >= V_36 + V_37 )
return - V_43 ;
if ( V_38 + F_23 ( V_38 , V_36 + V_37 - V_38 ) >= V_36 + V_37 )
return - V_43 ;
if ( V_35 < sizeof( V_40 ) + sizeof( V_41 ) )
return - V_43 ;
V_23 = F_10 () ;
memset ( V_19 , 0 , sizeof( V_40 ) + sizeof( V_41 ) ) ;
V_34 = V_19 + sizeof( V_40 ) + sizeof( V_41 ) ;
V_41 = 0 ;
if ( V_23 -> V_10 ) {
V_10 = F_24 ( V_23 -> V_10 , & V_38 ,
V_23 -> V_10 -> V_44 ) ;
if ( V_10 ) {
if ( V_34 + sizeof( V_42 ) + V_10 -> V_14 > V_19 + V_35 )
return - V_43 ;
V_42 = F_25 ( V_10 -> V_14 ) ;
memcpy ( V_34 , & V_42 , sizeof( V_42 ) ) ;
V_34 += sizeof( V_42 ) ;
memcpy ( V_34 , V_10 -> V_10 , V_10 -> V_14 ) ;
V_34 += V_10 -> V_14 ;
V_41 ++ ;
}
}
V_42 = F_25 ( V_34 - V_19 - sizeof( V_40 ) ) ;
memcpy ( V_19 , & V_42 , sizeof( V_42 ) ) ;
V_42 = F_25 ( V_41 ) ;
memcpy ( V_19 + sizeof( V_40 ) , & V_42 , sizeof( V_42 ) ) ;
return V_34 - V_19 ;
}
static T_4 F_26 ( struct V_28 * V_28 , const char T_1 * V_45 ,
T_2 V_13 , T_3 * V_46 )
{
char * V_19 ;
T_4 V_4 ;
if ( * V_46 )
return - V_11 ;
V_19 = F_27 ( V_28 , V_45 , V_13 ) ;
if ( F_13 ( V_19 ) )
return F_12 ( V_19 ) ;
if ( V_13 > V_47 &&
! memcmp ( V_19 , V_48 , V_47 ) ) {
V_4 = F_22 ( V_19 , V_49 ,
V_19 + V_47 ,
V_13 - V_47 ) ;
} else
V_4 = - V_43 ;
if ( V_4 < 0 )
return V_4 ;
F_28 ( V_28 , V_4 ) ;
return V_13 ;
}
static int F_29 ( struct V_50 * V_51 , void * V_52 )
{
struct V_53 * V_54 = V_51 -> V_55 ;
if ( ! V_54 )
return 0 ;
switch ( V_54 -> V_56 ) {
case V_57 :
F_30 ( V_51 , L_3 , V_54 -> V_52 . boolean ? L_4 : L_5 ) ;
break;
case V_58 :
F_30 ( V_51 , L_3 , V_54 -> V_52 . string ) ;
break;
case V_59 :
F_30 ( V_51 , L_6 , V_54 -> V_52 . V_60 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_31 ( struct V_61 * V_61 , struct V_28 * V_28 )
{
return F_32 ( V_28 , F_29 , V_61 -> V_31 ) ;
}
static int F_33 ( struct V_61 * V_61 , struct V_28 * V_28 ,
int (* F_34)( struct V_50 * , void * ) )
{
struct V_62 * V_63 = F_35 ( V_61 -> V_31 ) ;
int error = F_32 ( V_28 , F_34 , V_63 ) ;
if ( error ) {
V_28 -> V_64 = NULL ;
F_36 ( V_63 ) ;
}
return error ;
}
static int F_37 ( struct V_61 * V_61 , struct V_28 * V_28 )
{
struct V_50 * V_51 = (struct V_50 * ) V_28 -> V_64 ;
if ( V_51 )
F_36 ( V_51 -> V_55 ) ;
return F_38 ( V_61 , V_28 ) ;
}
static int F_39 ( struct V_50 * V_51 , void * V_52 )
{
struct V_62 * V_63 = V_51 -> V_55 ;
struct V_22 * V_23 = F_40 ( & V_63 -> V_23 ) ;
F_30 ( V_51 , L_3 , V_23 -> V_65 . V_1 ) ;
F_41 ( V_23 ) ;
return 0 ;
}
static int F_42 ( struct V_61 * V_61 , struct V_28 * V_28 )
{
return F_33 ( V_61 , V_28 , F_39 ) ;
}
static int F_43 ( struct V_50 * V_51 , void * V_52 )
{
struct V_62 * V_63 = V_51 -> V_55 ;
struct V_22 * V_23 = F_40 ( & V_63 -> V_23 ) ;
F_30 ( V_51 , L_3 , V_66 [ V_23 -> V_67 ] ) ;
F_41 ( V_23 ) ;
return 0 ;
}
static int F_44 ( struct V_61 * V_61 , struct V_28 * V_28 )
{
return F_33 ( V_61 , V_28 , F_43 ) ;
}
static int F_45 ( struct V_50 * V_51 , void * V_52 )
{
struct V_62 * V_63 = V_51 -> V_55 ;
struct V_22 * V_23 = F_40 ( & V_63 -> V_23 ) ;
if ( V_23 -> V_68 )
F_30 ( V_51 , L_3 , V_23 -> V_68 ) ;
else if ( V_23 -> V_69 )
F_46 ( V_51 , L_7 ) ;
else
F_30 ( V_51 , L_3 , V_23 -> V_65 . V_1 ) ;
F_41 ( V_23 ) ;
return 0 ;
}
static int F_47 ( struct V_61 * V_61 , struct V_28 * V_28 )
{
return F_33 ( V_61 , V_28 , F_45 ) ;
}
static int F_48 ( struct V_50 * V_51 , void * V_52 )
{
struct V_62 * V_63 = V_51 -> V_55 ;
struct V_22 * V_23 = F_40 ( & V_63 -> V_23 ) ;
unsigned int V_70 , V_14 = F_49 () ;
if ( V_23 -> V_15 ) {
for ( V_70 = 0 ; V_70 < V_14 ; V_70 ++ )
F_30 ( V_51 , L_8 , V_23 -> V_15 [ V_70 ] ) ;
F_46 ( V_51 , L_9 ) ;
}
F_41 ( V_23 ) ;
return 0 ;
}
static int F_50 ( struct V_61 * V_61 , struct V_28 * V_28 )
{
return F_32 ( V_28 , F_48 , V_61 -> V_31 ) ;
}
static int F_51 ( struct V_50 * V_51 , void * V_52 )
{
struct V_20 * V_21 = F_10 () -> V_21 ;
F_30 ( V_51 , L_10 , V_21 -> V_71 ) ;
return 0 ;
}
static int F_52 ( struct V_61 * V_61 , struct V_28 * V_28 )
{
return F_32 ( V_28 , F_51 , V_61 -> V_31 ) ;
}
static int F_53 ( struct V_50 * V_51 , void * V_52 )
{
struct V_20 * V_21 = F_10 () -> V_21 ;
F_30 ( V_51 , L_3 , V_21 -> V_65 . V_1 ) ;
return 0 ;
}
static int F_54 ( struct V_61 * V_61 , struct V_28 * V_28 )
{
return F_32 ( V_28 , F_53 , V_61 -> V_31 ) ;
}
static int F_55 ( struct V_61 * V_61 , struct V_28 * V_28 )
{
F_15 ( V_28 -> V_64 ) ;
return 0 ;
}
static int F_56 ( struct V_50 * V_51 , void * V_52 )
{
struct V_62 * V_63 = V_51 -> V_55 ;
struct V_22 * V_23 = F_40 ( & V_63 -> V_23 ) ;
if ( V_23 -> V_72 -> V_16 ) {
F_30 ( V_51 , L_11 , V_23 -> V_72 -> V_16 ) ;
F_46 ( V_51 , L_9 ) ;
}
F_41 ( V_23 ) ;
return 0 ;
}
static int F_57 ( struct V_61 * V_61 , struct V_28 * V_28 )
{
return F_33 ( V_61 , V_28 , F_56 ) ;
}
static int F_58 ( struct V_50 * V_51 , void * V_52 )
{
struct V_62 * V_63 = V_51 -> V_55 ;
struct V_22 * V_23 = F_40 ( & V_63 -> V_23 ) ;
unsigned int V_70 , V_14 = F_49 () ;
if ( V_23 -> V_72 -> V_15 ) {
for ( V_70 = 0 ; V_70 < V_14 ; V_70 ++ )
F_30 ( V_51 , L_8 , V_23 -> V_72 -> V_15 [ V_70 ] ) ;
F_46 ( V_51 , L_9 ) ;
}
F_41 ( V_23 ) ;
return 0 ;
}
static int F_59 ( struct V_61 * V_61 , struct V_28 * V_28 )
{
return F_33 ( V_61 , V_28 , F_58 ) ;
}
static T_4 F_60 ( struct V_28 * V_28 , char T_1 * V_19 , T_2 V_14 ,
T_3 * V_46 )
{
struct V_5 * V_72 = V_28 -> V_64 ;
return F_61 ( V_19 , V_14 , V_46 , V_72 -> V_10 ,
V_72 -> V_14 ) ;
}
static int F_62 ( struct V_61 * V_61 , struct V_28 * V_28 )
{
struct V_62 * V_63 = V_61 -> V_31 ;
struct V_22 * V_23 ;
if ( ! F_63 ( NULL ) )
return - V_73 ;
V_23 = F_40 ( & V_63 -> V_23 ) ;
V_28 -> V_64 = F_64 ( V_23 -> V_72 ) ;
F_41 ( V_23 ) ;
return 0 ;
}
void F_65 ( struct V_22 * V_23 )
{
struct V_22 * V_74 ;
int V_70 ;
if ( ! V_23 )
return;
F_66 (child, &profile->base.profiles, base.list)
F_65 ( V_74 ) ;
for ( V_70 = V_75 - 1 ; V_70 >= 0 ; -- V_70 ) {
struct V_62 * V_63 ;
if ( ! V_23 -> V_76 [ V_70 ] )
continue;
V_63 = F_67 ( V_23 -> V_76 [ V_70 ] ) -> V_31 ;
F_68 ( V_23 -> V_76 [ V_70 ] ) ;
F_36 ( V_63 ) ;
V_23 -> V_76 [ V_70 ] = NULL ;
}
}
void F_69 ( struct V_22 * V_77 ,
struct V_22 * V_78 )
{
int V_70 ;
for ( V_70 = 0 ; V_70 < V_75 ; V_70 ++ ) {
V_78 -> V_76 [ V_70 ] = V_77 -> V_76 [ V_70 ] ;
if ( V_78 -> V_76 [ V_70 ] )
V_78 -> V_76 [ V_70 ] -> F_67 -> V_79 = F_70 ( V_78 -> V_76 [ V_70 ] -> F_67 ) ;
V_77 -> V_76 [ V_70 ] = NULL ;
}
}
static struct V_80 * F_71 ( struct V_80 * V_81 , const char * V_1 ,
struct V_22 * V_23 ,
const struct V_82 * V_83 )
{
struct V_62 * V_63 = F_35 ( V_23 -> V_63 ) ;
struct V_80 * V_84 ;
V_84 = F_72 ( V_1 , V_85 | 0444 , V_81 , V_63 , V_83 ) ;
if ( F_13 ( V_84 ) )
F_36 ( V_63 ) ;
return V_84 ;
}
int F_73 ( struct V_22 * V_23 , struct V_80 * V_86 )
{
struct V_22 * V_74 ;
struct V_80 * V_84 = NULL , * V_81 ;
int error ;
if ( ! V_86 ) {
struct V_22 * V_44 ;
V_44 = F_74 ( V_23 ) ;
V_84 = F_75 ( V_44 ) ;
V_84 = F_76 ( L_12 , V_84 ) ;
if ( F_13 ( V_84 ) )
goto V_87;
F_77 ( V_44 ) = V_86 = V_84 ;
}
if ( ! V_23 -> V_88 ) {
int V_4 , V_89 ;
V_4 = F_1 ( V_23 -> V_65 . V_1 , NULL ) ;
V_89 = snprintf ( NULL , 0 , L_13 , V_23 -> V_21 -> V_90 ) ;
V_23 -> V_88 = F_78 ( V_4 + V_89 + 1 , V_91 ) ;
if ( ! V_23 -> V_88 )
goto V_87;
F_1 ( V_23 -> V_65 . V_1 , V_23 -> V_88 ) ;
sprintf ( V_23 -> V_88 + V_4 , L_13 , V_23 -> V_21 -> V_90 ++ ) ;
}
V_84 = F_76 ( V_23 -> V_88 , V_86 ) ;
if ( F_13 ( V_84 ) )
goto V_87;
F_75 ( V_23 ) = V_81 = V_84 ;
V_84 = F_71 ( V_81 , L_14 , V_23 , & V_92 ) ;
if ( F_13 ( V_84 ) )
goto V_87;
V_23 -> V_76 [ V_93 ] = V_84 ;
V_84 = F_71 ( V_81 , L_15 , V_23 , & V_94 ) ;
if ( F_13 ( V_84 ) )
goto V_87;
V_23 -> V_76 [ V_95 ] = V_84 ;
V_84 = F_71 ( V_81 , L_16 , V_23 ,
& V_96 ) ;
if ( F_13 ( V_84 ) )
goto V_87;
V_23 -> V_76 [ V_97 ] = V_84 ;
if ( V_23 -> V_15 ) {
V_84 = F_71 ( V_81 , L_17 , V_23 ,
& V_98 ) ;
if ( F_13 ( V_84 ) )
goto V_87;
V_23 -> V_76 [ V_99 ] = V_84 ;
}
if ( V_23 -> V_72 ) {
V_84 = F_71 ( V_81 , L_18 , V_23 ,
& V_100 ) ;
if ( F_13 ( V_84 ) )
goto V_87;
V_23 -> V_76 [ V_101 ] = V_84 ;
V_84 = F_71 ( V_81 , L_19 , V_23 ,
& V_102 ) ;
if ( F_13 ( V_84 ) )
goto V_87;
V_23 -> V_76 [ V_103 ] = V_84 ;
V_84 = F_72 ( L_20 , V_85 | 0444 , V_81 ,
V_23 -> V_63 ,
& V_104 ) ;
if ( F_13 ( V_84 ) )
goto V_87;
V_23 -> V_76 [ V_105 ] = V_84 ;
F_67 ( V_84 ) -> V_106 = V_23 -> V_72 -> V_14 ;
F_35 ( V_23 -> V_63 ) ;
}
F_66 (child, &profile->base.profiles, base.list) {
error = F_73 ( V_74 , F_77 ( V_23 ) ) ;
if ( error )
goto V_107;
}
return 0 ;
V_87:
error = F_12 ( V_84 ) ;
V_107:
F_65 ( V_23 ) ;
return error ;
}
void F_79 ( struct V_20 * V_21 )
{
struct V_20 * V_108 ;
struct V_22 * V_74 ;
int V_70 ;
if ( ! V_21 )
return;
F_66 (child, &ns->base.profiles, base.list)
F_65 ( V_74 ) ;
F_66 (sub, &ns->sub_ns, base.list) {
F_80 ( & V_108 -> V_109 ) ;
F_79 ( V_108 ) ;
F_81 ( & V_108 -> V_109 ) ;
}
if ( F_82 ( V_21 ) ) {
V_108 = F_67 ( F_82 ( V_21 ) ) -> V_31 ;
F_18 ( V_108 ) ;
}
if ( F_83 ( V_21 ) ) {
V_108 = F_67 ( F_83 ( V_21 ) ) -> V_31 ;
F_18 ( V_108 ) ;
}
if ( F_84 ( V_21 ) ) {
V_108 = F_67 ( F_84 ( V_21 ) ) -> V_31 ;
F_18 ( V_108 ) ;
}
if ( F_85 ( V_21 ) ) {
V_108 = F_67 ( F_85 ( V_21 ) ) -> V_31 ;
F_18 ( V_108 ) ;
}
for ( V_70 = V_110 - 1 ; V_70 >= 0 ; -- V_70 ) {
F_68 ( V_21 -> V_76 [ V_70 ] ) ;
V_21 -> V_76 [ V_70 ] = NULL ;
}
}
static int F_86 ( struct V_20 * V_21 , struct V_80 * V_81 )
{
struct V_80 * V_84 ;
F_3 ( ! V_21 ) ;
F_3 ( ! V_81 ) ;
V_84 = F_76 ( L_12 , V_81 ) ;
if ( F_13 ( V_84 ) )
return F_12 ( V_84 ) ;
F_87 ( V_21 ) = V_84 ;
V_84 = F_76 ( L_20 , V_81 ) ;
if ( F_13 ( V_84 ) )
return F_12 ( V_84 ) ;
F_88 ( V_21 ) = V_84 ;
V_84 = F_72 ( L_21 , 0640 , V_81 , V_21 ,
& V_111 ) ;
if ( F_13 ( V_84 ) )
return F_12 ( V_84 ) ;
F_17 ( V_21 ) ;
F_83 ( V_21 ) = V_84 ;
V_84 = F_72 ( L_22 , 0640 , V_81 , V_21 ,
& V_112 ) ;
if ( F_13 ( V_84 ) )
return F_12 ( V_84 ) ;
F_17 ( V_21 ) ;
F_84 ( V_21 ) = V_84 ;
V_84 = F_72 ( L_23 , 0640 , V_81 , V_21 ,
& V_113 ) ;
if ( F_13 ( V_84 ) )
return F_12 ( V_84 ) ;
F_17 ( V_21 ) ;
F_85 ( V_21 ) = V_84 ;
V_84 = F_76 ( L_24 , V_81 ) ;
if ( F_13 ( V_84 ) )
return F_12 ( V_84 ) ;
F_17 ( V_21 ) ;
F_82 ( V_21 ) = V_84 ;
return 0 ;
}
int F_89 ( struct V_20 * V_21 , struct V_80 * V_86 , const char * V_1 )
{
struct V_20 * V_108 ;
struct V_22 * V_74 ;
struct V_80 * V_84 , * V_81 ;
int error ;
F_3 ( ! V_21 ) ;
F_3 ( ! V_86 ) ;
F_3 ( ! F_90 ( & V_21 -> V_109 ) ) ;
if ( ! V_1 )
V_1 = V_21 -> V_65 . V_1 ;
V_84 = F_76 ( V_1 , V_86 ) ;
if ( F_13 ( V_84 ) )
goto V_87;
F_91 ( V_21 ) = V_81 = V_84 ;
error = F_86 ( V_21 , V_81 ) ;
if ( error )
goto V_107;
F_66 (child, &ns->base.profiles, base.list) {
error = F_73 ( V_74 , F_87 ( V_21 ) ) ;
if ( error )
goto V_107;
}
F_66 (sub, &ns->sub_ns, base.list) {
F_80 ( & V_108 -> V_109 ) ;
error = F_89 ( V_108 , F_82 ( V_21 ) , NULL ) ;
F_81 ( & V_108 -> V_109 ) ;
if ( error )
goto V_107;
}
return 0 ;
V_87:
error = F_12 ( V_84 ) ;
V_107:
F_79 ( V_21 ) ;
return error ;
}
static struct V_20 * F_92 ( struct V_20 * V_114 , struct V_20 * V_21 )
{
struct V_20 * V_86 , * V_115 ;
if ( ! F_93 ( & V_21 -> V_116 ) ) {
V_115 = F_94 ( & V_21 -> V_116 , F_95 ( * V_21 ) , V_65 . V_117 ) ;
F_80 ( & V_115 -> V_109 ) ;
return V_115 ;
}
V_86 = V_21 -> V_86 ;
while ( V_21 != V_114 ) {
F_81 ( & V_21 -> V_109 ) ;
V_115 = F_96 ( V_21 , V_65 . V_117 ) ;
if ( ! F_97 ( V_115 , & V_86 -> V_116 , V_65 . V_117 ) ) {
F_80 ( & V_115 -> V_109 ) ;
return V_115 ;
}
V_21 = V_86 ;
V_86 = V_86 -> V_86 ;
}
return NULL ;
}
static struct V_22 * F_98 ( struct V_20 * V_114 ,
struct V_20 * V_21 )
{
for (; V_21 ; V_21 = F_92 ( V_114 , V_21 ) ) {
if ( ! F_93 ( & V_21 -> V_65 . V_118 ) )
return F_94 ( & V_21 -> V_65 . V_118 ,
struct V_22 , V_65 . V_117 ) ;
}
return NULL ;
}
static struct V_22 * F_99 ( struct V_22 * V_44 )
{
struct V_22 * V_86 ;
struct V_20 * V_21 = V_44 -> V_21 ;
if ( ! F_93 ( & V_44 -> V_65 . V_118 ) )
return F_94 ( & V_44 -> V_65 . V_118 , F_95 ( * V_44 ) ,
V_65 . V_117 ) ;
V_86 = F_100 ( V_44 -> V_86 ,
F_90 ( & V_44 -> V_21 -> V_109 ) ) ;
while ( V_86 ) {
V_44 = F_96 ( V_44 , V_65 . V_117 ) ;
if ( ! F_97 ( V_44 , & V_86 -> V_65 . V_118 , V_65 . V_117 ) )
return V_44 ;
V_44 = V_86 ;
V_86 = F_100 ( V_86 -> V_86 ,
F_90 ( & V_86 -> V_21 -> V_109 ) ) ;
}
V_44 = F_96 ( V_44 , V_65 . V_117 ) ;
if ( ! F_97 ( V_44 , & V_21 -> V_65 . V_118 , V_65 . V_117 ) )
return V_44 ;
return NULL ;
}
static struct V_22 * F_101 ( struct V_20 * V_114 ,
struct V_22 * V_23 )
{
struct V_22 * V_115 = F_99 ( V_23 ) ;
if ( V_115 )
return V_115 ;
return F_98 ( V_114 , F_92 ( V_114 , V_23 -> V_21 ) ) ;
}
static void * F_102 ( struct V_50 * V_29 , T_3 * V_9 )
{
struct V_22 * V_23 = NULL ;
struct V_20 * V_114 = F_10 () -> V_21 ;
T_3 V_119 = * V_9 ;
V_29 -> V_55 = F_17 ( V_114 ) ;
F_80 ( & V_114 -> V_109 ) ;
V_23 = F_98 ( V_114 , V_114 ) ;
for (; V_23 && V_119 > 0 ; V_119 -- )
V_23 = F_101 ( V_114 , V_23 ) ;
return V_23 ;
}
static void * F_103 ( struct V_50 * V_29 , void * V_44 , T_3 * V_9 )
{
struct V_22 * V_23 = V_44 ;
struct V_20 * V_21 = V_29 -> V_55 ;
( * V_9 ) ++ ;
return F_101 ( V_21 , V_23 ) ;
}
static void F_104 ( struct V_50 * V_29 , void * V_44 )
{
struct V_22 * V_23 = V_44 ;
struct V_20 * V_114 = V_29 -> V_55 , * V_21 ;
if ( V_23 ) {
for ( V_21 = V_23 -> V_21 ; V_21 && V_21 != V_114 ; V_21 = V_21 -> V_86 )
F_81 ( & V_21 -> V_109 ) ;
}
F_81 ( & V_114 -> V_109 ) ;
F_18 ( V_114 ) ;
}
static int F_105 ( struct V_50 * V_29 , void * V_44 )
{
struct V_22 * V_23 = (struct V_22 * ) V_44 ;
struct V_20 * V_114 = V_29 -> V_55 ;
if ( V_23 -> V_21 != V_114 )
F_30 ( V_29 , L_25 , F_106 ( V_114 , V_23 -> V_21 , true ) ) ;
F_30 ( V_29 , L_26 , V_23 -> V_65 . V_120 ,
V_66 [ V_23 -> V_67 ] ) ;
return 0 ;
}
static int F_107 ( struct V_61 * V_61 , struct V_28 * V_28 )
{
if ( ! F_63 ( NULL ) )
return - V_73 ;
return F_108 ( V_28 , & V_121 ) ;
}
static int F_109 ( struct V_61 * V_61 , struct V_28 * V_28 )
{
return F_110 ( V_61 , V_28 ) ;
}
static int T_7 F_111 ( struct V_53 * V_54 ,
struct V_80 * V_86 )
{
int error = 0 ;
V_54 -> V_80 = F_72 ( V_54 -> V_1 ,
V_85 | V_54 -> V_67 ,
V_86 , V_54 ,
V_54 -> V_122 ) ;
if ( F_13 ( V_54 -> V_80 ) ) {
error = F_12 ( V_54 -> V_80 ) ;
V_54 -> V_80 = NULL ;
}
return error ;
}
static int T_7 F_112 ( struct V_53 * V_123 ,
struct V_80 * V_86 )
{
struct V_53 * V_54 ;
struct V_80 * V_81 ;
int error ;
V_81 = F_76 ( V_123 -> V_1 , V_86 ) ;
if ( F_13 ( V_81 ) )
return F_12 ( V_81 ) ;
V_123 -> V_80 = V_81 ;
for ( V_54 = V_123 -> V_52 . V_124 ; V_54 && V_54 -> V_1 ; ++ V_54 ) {
if ( V_54 -> V_56 == V_125 )
error = F_112 ( V_54 , V_123 -> V_80 ) ;
else
error = F_111 ( V_54 , V_123 -> V_80 ) ;
if ( error )
goto V_126;
}
return 0 ;
V_126:
F_113 ( V_123 ) ;
return error ;
}
static void T_7 F_114 ( struct V_53 * V_54 )
{
if ( ! V_54 -> V_80 )
return;
F_68 ( V_54 -> V_80 ) ;
V_54 -> V_80 = NULL ;
}
static void T_7 F_113 ( struct V_53 * V_123 )
{
struct V_53 * V_54 ;
for ( V_54 = V_123 -> V_52 . V_124 ; V_54 && V_54 -> V_1 ; ++ V_54 ) {
if ( V_54 -> V_56 == V_125 )
F_113 ( V_54 ) ;
else
F_114 ( V_54 ) ;
}
F_114 ( V_123 ) ;
}
void T_7 F_115 ( void )
{
F_113 ( & V_53 ) ;
}
static int F_116 ( struct V_80 * V_86 )
{
struct V_127 * V_128 = NULL ;
struct V_80 * V_80 ;
struct V_61 * V_61 ;
int V_13 = 0 ;
int error = F_117 ( V_86 -> V_129 -> V_130 , & V_128 , & V_13 ) ;
if ( error )
return error ;
F_118 ( F_67 ( V_86 ) ) ;
V_80 = F_119 ( V_131 , V_86 , strlen ( V_131 ) ) ;
if ( F_13 ( V_80 ) ) {
error = F_12 ( V_80 ) ;
goto V_34;
}
V_61 = F_120 ( V_86 -> F_67 -> V_132 ) ;
if ( ! V_61 ) {
error = - V_12 ;
goto V_133;
}
V_61 -> V_134 = F_121 () ;
V_61 -> V_135 = V_136 | V_137 | V_138 ;
V_61 -> V_139 = V_61 -> V_79 = V_61 -> V_140 = V_141 ;
F_122 ( V_61 , V_136 | V_137 | V_138 ,
F_123 ( V_142 , 3 ) ) ;
F_124 ( V_80 , V_61 ) ;
V_143 . V_80 = F_125 ( V_80 ) ;
V_143 . V_144 = F_126 ( V_128 ) ;
error = 0 ;
V_133:
F_127 ( V_80 ) ;
V_34:
F_128 ( F_67 ( V_86 ) ) ;
F_129 ( & V_128 , & V_13 ) ;
return error ;
}
static int T_7 F_130 ( void )
{
struct V_80 * V_84 ;
int error ;
if ( ! V_145 )
return 0 ;
if ( V_53 . V_80 ) {
F_131 ( L_27 , V_146 ) ;
return - V_147 ;
}
error = F_112 ( & V_53 , NULL ) ;
if ( error )
goto error;
V_84 = F_72 ( L_21 , 0666 , V_53 . V_80 ,
NULL , & V_111 ) ;
if ( F_13 ( V_84 ) ) {
error = F_12 ( V_84 ) ;
goto error;
}
F_83 ( V_148 ) = V_84 ;
V_84 = F_72 ( L_22 , 0666 , V_53 . V_80 ,
NULL , & V_112 ) ;
if ( F_13 ( V_84 ) ) {
error = F_12 ( V_84 ) ;
goto error;
}
F_84 ( V_148 ) = V_84 ;
V_84 = F_72 ( L_23 , 0666 , V_53 . V_80 ,
NULL , & V_113 ) ;
if ( F_13 ( V_84 ) ) {
error = F_12 ( V_84 ) ;
goto error;
}
F_85 ( V_148 ) = V_84 ;
F_80 ( & V_148 -> V_109 ) ;
error = F_89 ( V_148 , V_53 . V_80 , L_28 ) ;
F_81 ( & V_148 -> V_109 ) ;
if ( error )
goto error;
error = F_116 ( V_53 . V_80 ) ;
if ( error )
goto error;
F_132 ( L_29 ) ;
return 0 ;
error:
F_115 () ;
F_131 ( L_30 ) ;
return error ;
}
