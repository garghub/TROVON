static void F_1 ( void * V_1 )
{
struct V_2 * V_3 ;
V_3 = (struct V_2 * ) V_1 ;
F_2 ( & V_3 -> V_4 ) ;
}
static int F_3 ( struct V_2 * V_3 , int V_5 )
{
int V_6 = 0 ;
F_4 ( & V_3 -> V_4 ) ;
V_6 = F_5 ( V_3 -> V_7 , V_5 , & V_3 -> V_8 ,
V_3 -> V_9 , V_3 -> V_10 , strlen ( V_3 -> V_10 ) ,
0 , F_1 , V_3 , V_3 -> V_11 ) ;
if ( V_6 )
return V_6 ;
F_6 ( & V_3 -> V_4 ) ;
return V_3 -> V_8 . V_12 ;
}
static int F_7 ( struct V_2 * V_3 )
{
return F_3 ( V_3 , V_13 ) ;
}
static struct V_2 * F_8 ( struct V_14 * V_14 ,
char * V_10 , void (* F_9)( void * V_1 , int V_5 ) , int V_15 )
{
struct V_2 * V_3 = NULL ;
int V_6 , V_16 ;
struct V_17 * V_18 = V_14 -> V_19 ;
V_3 = F_10 ( sizeof( struct V_2 ) , V_20 ) ;
if ( ! V_3 )
return NULL ;
V_3 -> V_7 = V_18 -> V_21 ;
V_3 -> V_14 = V_14 ;
V_16 = strlen ( V_10 ) ;
V_3 -> V_10 = F_10 ( V_16 + 1 , V_20 ) ;
if ( ! V_3 -> V_10 ) {
F_11 ( L_1 , V_10 ) ;
goto V_22;
}
F_12 ( V_3 -> V_10 , V_10 , V_16 + 1 ) ;
if ( V_15 ) {
V_3 -> V_8 . V_23 = F_10 ( V_24 , V_20 ) ;
if ( ! V_3 -> V_8 . V_23 ) {
F_11 ( L_2 , V_10 ) ;
goto V_22;
}
V_3 -> V_9 = V_25 ;
}
if ( F_9 )
V_3 -> V_11 = F_9 ;
V_3 -> V_9 |= V_26 ;
V_6 = F_3 ( V_3 , V_13 ) ;
if ( V_6 ) {
F_11 ( L_3 , V_10 ) ;
goto V_22;
}
V_3 -> V_9 &= ~ V_26 ;
V_3 -> V_9 |= V_27 ;
return V_3 ;
V_22:
F_13 ( V_3 -> V_8 . V_23 ) ;
F_13 ( V_3 -> V_10 ) ;
F_13 ( V_3 ) ;
return NULL ;
}
static void F_14 ( struct V_2 * V_3 )
{
if ( ! V_3 )
return;
F_4 ( & V_3 -> V_4 ) ;
F_15 ( V_3 -> V_7 , V_3 -> V_8 . V_28 , 0 , & V_3 -> V_8 , V_3 ) ;
F_6 ( & V_3 -> V_4 ) ;
F_13 ( V_3 -> V_10 ) ;
F_13 ( V_3 -> V_8 . V_23 ) ;
F_13 ( V_3 ) ;
}
static char * F_16 ( char * V_29 , char * V_30 )
{
int V_31 , V_32 = 0 ;
for ( V_31 = 0 ; V_31 < 16 ; V_31 ++ ) {
if ( V_31 == 4 || V_31 == 6 || V_31 == 8 || V_31 == 10 )
V_32 += sprintf ( V_29 + V_32 , L_4 ) ;
V_32 += sprintf ( V_29 + V_32 , L_5 , ( V_33 ) V_30 [ V_31 ] ) ;
}
return V_29 ;
}
static void F_17 ( struct V_14 * V_14 , struct V_2 * V_34 ,
T_1 V_35 , T_1 V_36 )
{
struct V_37 * V_38 ;
V_38 = (struct V_37 * ) V_34 -> V_8 . V_23 ;
V_38 -> V_35 = F_18 ( V_35 ) ;
V_38 -> V_36 = F_18 ( V_36 ) ;
}
static struct V_39 * F_19 ( struct V_14 * V_14 , struct V_2 * V_34 )
{
struct V_37 V_38 ;
struct V_39 * V_40 = NULL ;
T_1 V_36 = 0 ;
F_3 ( V_34 , V_41 ) ;
memcpy ( & V_38 , V_34 -> V_8 . V_23 , sizeof( struct V_37 ) ) ;
V_36 = F_20 ( V_38 . V_36 ) ;
if ( V_38 . V_36 > 0 ) {
V_40 = F_10 ( sizeof( struct V_39 ) , V_20 ) ;
if ( ! V_40 )
goto V_42;
V_40 -> V_36 = V_36 ;
V_40 -> V_35 = F_20 ( V_38 . V_35 ) ;
}
F_7 ( V_34 ) ;
V_42:
return V_40 ;
}
static void F_21 ( struct V_43 * V_44 )
{
struct V_14 * V_14 = V_44 -> V_14 ;
struct V_17 * V_18 = V_14 -> V_19 ;
struct V_2 * V_45 ;
char V_46 [ 64 ] ;
int V_47 , V_6 ;
struct V_39 * V_40 , * V_48 ;
T_1 V_35 , V_36 ;
while ( V_18 -> V_49 ) {
V_47 = F_22 ( ( V_50 ) V_18 -> V_49 ) - 1 ;
F_23 ( & V_18 -> V_51 ) ;
F_24 (s, tmp, &cinfo->suspend_list, list)
if ( V_47 == V_40 -> V_47 ) {
F_25 ( & V_40 -> V_52 ) ;
F_13 ( V_40 ) ;
}
F_26 ( & V_18 -> V_51 ) ;
snprintf ( V_46 , 64 , L_6 , V_47 ) ;
V_45 = F_8 ( V_14 , V_46 , NULL , 1 ) ;
if ( ! V_45 ) {
F_11 ( L_7 ) ;
goto V_53;
}
V_6 = F_3 ( V_45 , V_54 ) ;
if ( V_6 ) {
F_11 ( L_8 ,
V_46 , V_6 ) ;
goto V_53;
}
V_6 = F_27 ( V_14 , V_47 , & V_35 , & V_36 , true ) ;
if ( V_6 ) {
F_11 ( L_9 , V_47 ) ;
goto F_15;
}
if ( V_36 > 0 ) {
F_28 ( V_55 , & V_14 -> V_56 ) ;
if ( V_35 < V_14 -> V_57 )
V_14 -> V_57 = V_35 ;
F_29 ( V_14 ) ;
}
F_15:
F_7 ( V_45 ) ;
V_53:
V_53 ( V_47 , & V_18 -> V_49 ) ;
}
}
static void F_30 ( void * V_1 )
{
}
static void F_31 ( void * V_1 , struct V_58 * V_47 )
{
struct V_14 * V_14 = V_1 ;
struct V_17 * V_18 = V_14 -> V_19 ;
F_32 ( L_10 ,
V_14 -> V_59 . V_60 ,
V_47 -> V_61 , V_47 -> V_47 ,
V_18 -> V_62 ) ;
F_28 ( V_47 -> V_47 - 1 , & V_18 -> V_49 ) ;
if ( ! V_18 -> V_63 ) {
V_18 -> V_63 = F_33 ( F_21 ,
V_14 , L_11 ) ;
if ( ! V_18 -> V_63 ) {
F_34 ( L_12 ) ;
return;
}
}
F_35 ( V_18 -> V_63 ) ;
}
static void F_36 ( void * V_1 , struct V_58 * V_64 ,
int V_65 , int V_66 ,
T_2 V_67 )
{
struct V_14 * V_14 = V_1 ;
struct V_17 * V_18 = V_14 -> V_19 ;
V_18 -> V_62 = V_66 ;
F_2 ( & V_18 -> V_4 ) ;
}
static void F_37 ( void * V_1 , int V_5 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
struct V_17 * V_18 = V_3 -> V_14 -> V_19 ;
if ( V_5 == V_68 )
F_35 ( V_18 -> V_69 ) ;
}
static void F_38 ( struct V_17 * V_18 , int V_47 )
{
struct V_39 * V_40 , * V_48 ;
F_24 (s, tmp, &cinfo->suspend_list, list)
if ( V_47 == V_40 -> V_47 ) {
F_32 ( L_13 ,
V_70 , __LINE__ , V_47 ) ;
F_25 ( & V_40 -> V_52 ) ;
F_13 ( V_40 ) ;
break;
}
}
static void F_39 ( struct V_17 * V_18 , int V_47 )
{
F_23 ( & V_18 -> V_51 ) ;
F_38 ( V_18 , V_47 ) ;
F_26 ( & V_18 -> V_51 ) ;
}
static void F_40 ( struct V_17 * V_18 ,
int V_47 , T_1 V_35 , T_1 V_36 )
{
struct V_39 * V_40 ;
if ( ! V_36 ) {
F_39 ( V_18 , V_47 ) ;
return;
}
V_40 = F_10 ( sizeof( struct V_39 ) , V_20 ) ;
if ( ! V_40 )
return;
V_40 -> V_47 = V_47 ;
V_40 -> V_35 = V_35 ;
V_40 -> V_36 = V_36 ;
F_23 ( & V_18 -> V_51 ) ;
F_38 ( V_18 , V_47 ) ;
F_41 ( & V_40 -> V_52 , & V_18 -> V_71 ) ;
F_26 ( & V_18 -> V_51 ) ;
}
static void F_42 ( struct V_14 * V_14 , struct V_72 * V_73 )
{
char V_74 [ 64 ] ;
struct V_17 * V_18 = V_14 -> V_19 ;
char V_75 [] = L_14 ;
char V_76 [ 16 ] ;
char * V_77 [] = { V_75 , V_74 , V_76 , NULL } ;
int V_32 ;
V_32 = snprintf ( V_74 , 64 , L_15 ) ;
F_16 ( V_74 + V_32 , V_73 -> V_78 ) ;
snprintf ( V_76 , 16 , L_16 , V_73 -> V_76 ) ;
F_32 ( L_17 , V_70 , __LINE__ , V_74 , V_76 ) ;
F_4 ( & V_18 -> V_79 ) ;
F_28 ( V_80 , & V_18 -> V_81 ) ;
F_43 ( & F_44 ( V_14 -> V_82 ) -> V_83 , V_84 , V_77 ) ;
F_45 ( & V_18 -> V_79 ,
V_85 ) ;
V_53 ( V_80 , & V_18 -> V_81 ) ;
}
static void F_46 ( struct V_14 * V_14 , struct V_72 * V_86 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
F_47 ( V_14 ) ;
F_3 ( V_18 -> V_87 , V_41 ) ;
}
static void F_48 ( struct V_14 * V_14 , struct V_72 * V_86 )
{
struct V_88 * V_89 = F_49 ( V_14 , V_86 -> V_76 ) ;
if ( V_89 )
F_50 ( V_89 ) ;
else
F_34 ( L_18 , V_70 , __LINE__ , V_86 -> V_76 ) ;
}
static void F_51 ( struct V_14 * V_14 , struct V_72 * V_86 )
{
struct V_88 * V_89 = F_49 ( V_14 , V_86 -> V_76 ) ;
if ( V_89 && F_52 ( V_90 , & V_89 -> V_9 ) )
V_53 ( V_90 , & V_89 -> V_9 ) ;
else
F_34 ( L_19 , V_70 , __LINE__ , V_86 -> V_76 ) ;
}
static void F_53 ( struct V_14 * V_14 , struct V_72 * V_86 )
{
switch ( V_86 -> type ) {
case V_91 :
F_32 ( L_20 ,
V_70 , __LINE__ , V_86 -> V_47 ) ;
F_46 ( V_14 , V_86 ) ;
break;
case V_92 :
F_32 ( L_21 ,
V_70 , __LINE__ , V_86 -> V_47 ) ;
F_40 ( V_14 -> V_19 , V_86 -> V_47 ,
V_86 -> V_93 , V_86 -> V_94 ) ;
break;
case V_95 :
F_32 ( L_22 ,
V_70 , __LINE__ , V_86 -> V_47 ) ;
F_42 ( V_14 , V_86 ) ;
break;
case REMOVE :
F_32 ( L_23 ,
V_70 , __LINE__ , V_86 -> V_47 ) ;
F_48 ( V_14 , V_86 ) ;
break;
case V_96 :
F_32 ( L_24 ,
V_70 , __LINE__ , V_86 -> V_47 ) ;
F_51 ( V_14 , V_86 ) ;
break;
default:
F_34 ( L_25 ,
V_70 , __LINE__ , V_86 -> V_47 ) ;
}
}
static void F_54 ( struct V_43 * V_44 )
{
struct V_17 * V_18 = V_44 -> V_14 -> V_19 ;
struct V_2 * V_97 = V_18 -> V_97 ;
struct V_2 * V_98 = V_18 -> V_98 ;
struct V_72 V_86 ;
if ( F_3 ( V_98 , V_41 ) ) {
F_11 ( L_26 ) ;
return;
}
memcpy ( & V_86 , V_98 -> V_8 . V_23 , sizeof( struct V_72 ) ) ;
F_53 ( V_44 -> V_14 , & V_86 ) ;
F_7 ( V_97 ) ;
F_3 ( V_98 , V_68 ) ;
F_3 ( V_97 , V_41 ) ;
F_7 ( V_98 ) ;
}
static int F_55 ( struct V_17 * V_18 )
{
int error ;
error = F_3 ( V_18 -> V_99 , V_68 ) ;
if ( error )
F_11 ( L_27 ,
V_70 , __LINE__ , error ) ;
return error ;
}
static void F_56 ( struct V_17 * V_18 )
{
F_7 ( V_18 -> V_99 ) ;
}
static int F_57 ( struct V_17 * V_18 , struct V_72 * V_73 )
{
int error ;
int V_47 = V_18 -> V_62 - 1 ;
V_73 -> V_47 = F_58 ( V_47 ) ;
error = F_3 ( V_18 -> V_98 , V_68 ) ;
if ( error ) {
F_11 ( L_28 , error ) ;
goto V_100;
}
memcpy ( V_18 -> V_98 -> V_8 . V_23 , ( void * ) V_73 ,
sizeof( struct V_72 ) ) ;
error = F_3 ( V_18 -> V_98 , V_41 ) ;
if ( error ) {
F_11 ( L_29 ,
error ) ;
goto V_100;
}
error = F_3 ( V_18 -> V_97 , V_68 ) ;
if ( error ) {
F_11 ( L_30 ,
error ) ;
goto V_101;
}
error = F_3 ( V_18 -> V_97 , V_41 ) ;
if ( error ) {
F_11 ( L_31 ,
error ) ;
goto V_101;
}
V_101:
F_7 ( V_18 -> V_98 ) ;
V_100:
return error ;
}
static int F_59 ( struct V_17 * V_18 , struct V_72 * V_73 )
{
int V_6 ;
F_55 ( V_18 ) ;
V_6 = F_57 ( V_18 , V_73 ) ;
F_56 ( V_18 ) ;
return V_6 ;
}
static int F_60 ( struct V_14 * V_14 , int V_102 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
int V_31 , V_6 = 0 ;
struct V_2 * V_45 ;
struct V_39 * V_40 ;
char V_46 [ 64 ] ;
for ( V_31 = 0 ; V_31 < V_102 ; V_31 ++ ) {
memset ( V_46 , '\0' , 64 ) ;
snprintf ( V_46 , 64 , L_6 , V_31 ) ;
V_45 = F_8 ( V_14 , V_46 , NULL , 1 ) ;
if ( ! V_45 )
return - V_103 ;
if ( V_31 == ( V_18 -> V_62 - 1 ) )
continue;
V_45 -> V_9 |= V_104 ;
V_6 = F_3 ( V_45 , V_54 ) ;
if ( V_6 == - V_105 ) {
memset ( V_45 -> V_8 . V_23 , '\0' , V_24 ) ;
V_40 = F_19 ( V_14 , V_45 ) ;
if ( V_40 ) {
F_32 ( L_32 ,
V_70 , __LINE__ ,
( unsigned long long ) V_40 -> V_35 ,
( unsigned long long ) V_40 -> V_36 , V_31 ) ;
F_23 ( & V_18 -> V_51 ) ;
V_40 -> V_47 = V_31 ;
F_41 ( & V_40 -> V_52 , & V_18 -> V_71 ) ;
F_26 ( & V_18 -> V_51 ) ;
}
V_6 = 0 ;
F_14 ( V_45 ) ;
continue;
}
if ( V_6 )
goto V_42;
F_7 ( V_45 ) ;
F_14 ( V_45 ) ;
}
V_42:
return V_6 ;
}
static int F_61 ( struct V_14 * V_14 , int V_106 )
{
struct V_17 * V_18 ;
int V_6 , V_107 ;
char V_46 [ 64 ] ;
if ( ! F_62 ( V_108 ) )
return - V_109 ;
V_18 = F_10 ( sizeof( struct V_17 ) , V_20 ) ;
if ( ! V_18 )
return - V_103 ;
F_4 ( & V_18 -> V_4 ) ;
F_63 ( & V_18 -> V_110 ) ;
V_14 -> V_19 = V_18 ;
memset ( V_46 , 0 , 64 ) ;
F_16 ( V_46 , V_14 -> V_78 ) ;
V_6 = F_64 ( V_46 , V_14 -> V_59 . V_60 ,
V_111 , V_24 ,
& V_112 , V_14 , & V_107 , & V_18 -> V_21 ) ;
if ( V_6 )
goto V_113;
F_6 ( & V_18 -> V_4 ) ;
if ( V_106 < V_18 -> V_62 ) {
F_11 ( L_33 ,
V_18 -> V_62 , V_106 ) ;
V_6 = - V_114 ;
goto V_113;
}
V_18 -> V_115 = F_8 ( V_14 , L_34 ,
NULL , 0 ) ;
if ( ! V_18 -> V_115 ) {
V_6 = - V_103 ;
goto V_113;
}
V_6 = - V_103 ;
V_18 -> V_69 = F_33 ( F_54 , V_14 , L_35 ) ;
if ( ! V_18 -> V_69 ) {
F_11 ( L_36 ) ;
goto V_113;
}
V_18 -> V_98 = F_8 ( V_14 , L_37 , NULL , 1 ) ;
if ( ! V_18 -> V_98 )
goto V_113;
V_18 -> V_99 = F_8 ( V_14 , L_38 , NULL , 0 ) ;
if ( ! V_18 -> V_99 )
goto V_113;
V_18 -> V_97 = F_8 ( V_14 , L_39 , F_37 , 0 ) ;
if ( ! V_18 -> V_97 )
goto V_113;
V_18 -> V_87 = F_8 ( V_14 , L_40 , NULL , 0 ) ;
if ( ! V_18 -> V_87 )
goto V_113;
if ( F_3 ( V_18 -> V_97 , V_41 ) )
F_11 ( L_41 ,
V_6 ) ;
if ( F_3 ( V_18 -> V_87 , V_41 ) )
F_11 ( L_42 , V_6 ) ;
F_32 ( L_43 , V_46 , V_18 -> V_62 ) ;
snprintf ( V_46 , 64 , L_6 , V_18 -> V_62 - 1 ) ;
V_18 -> V_116 = F_8 ( V_14 , V_46 , NULL , 1 ) ;
if ( ! V_18 -> V_116 )
goto V_113;
if ( F_3 ( V_18 -> V_116 , V_54 ) ) {
F_11 ( L_44 ) ;
V_6 = - V_117 ;
goto V_113;
}
F_65 ( & V_18 -> V_71 ) ;
F_66 ( & V_18 -> V_51 ) ;
V_6 = F_60 ( V_14 , V_106 ) ;
if ( V_6 )
goto V_113;
return 0 ;
V_113:
F_14 ( V_18 -> V_98 ) ;
F_14 ( V_18 -> V_99 ) ;
F_14 ( V_18 -> V_97 ) ;
F_14 ( V_18 -> V_87 ) ;
F_14 ( V_18 -> V_116 ) ;
F_14 ( V_18 -> V_115 ) ;
if ( V_18 -> V_21 )
F_67 ( V_18 -> V_21 , 2 ) ;
V_14 -> V_19 = NULL ;
F_13 ( V_18 ) ;
F_68 ( V_108 ) ;
return V_6 ;
}
static int F_69 ( struct V_14 * V_14 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
if ( ! V_18 )
return 0 ;
F_70 ( & V_18 -> V_63 ) ;
F_70 ( & V_18 -> V_69 ) ;
F_14 ( V_18 -> V_98 ) ;
F_14 ( V_18 -> V_99 ) ;
F_14 ( V_18 -> V_97 ) ;
F_14 ( V_18 -> V_87 ) ;
F_14 ( V_18 -> V_115 ) ;
F_14 ( V_18 -> V_116 ) ;
F_67 ( V_18 -> V_21 , 2 ) ;
return 0 ;
}
static int V_62 ( struct V_14 * V_14 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
return V_18 -> V_62 - 1 ;
}
static void F_71 ( struct V_14 * V_14 , T_1 V_35 , T_1 V_36 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
F_17 ( V_14 , V_18 -> V_116 , V_35 , V_36 ) ;
F_3 ( V_18 -> V_116 , V_54 ) ;
}
static int F_72 ( struct V_14 * V_14 )
{
return F_55 ( V_14 -> V_19 ) ;
}
static int F_73 ( struct V_14 * V_14 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
struct V_72 V_73 ;
int V_6 ;
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
V_73 . type = F_58 ( V_91 ) ;
V_6 = F_57 ( V_18 , & V_73 ) ;
F_56 ( V_18 ) ;
return V_6 ;
}
static int F_74 ( struct V_14 * V_14 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
return F_7 ( V_18 -> V_99 ) ;
}
static int F_75 ( struct V_14 * V_14 , enum V_118 type ,
T_1 V_35 , T_1 V_36 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
struct V_72 V_73 ;
int V_47 = V_18 -> V_62 - 1 ;
F_32 ( L_45 , V_70 , __LINE__ ,
( unsigned long long ) V_35 ,
( unsigned long long ) V_36 ) ;
F_71 ( V_14 , V_35 , V_36 ) ;
V_73 . type = F_58 ( type ) ;
V_73 . V_47 = F_58 ( V_47 ) ;
V_73 . V_93 = F_18 ( V_35 ) ;
V_73 . V_94 = F_18 ( V_36 ) ;
return F_59 ( V_18 , & V_73 ) ;
}
static int F_76 ( struct V_14 * V_14 , T_1 V_35 , T_1 V_36 )
{
F_32 ( L_46 , V_70 , __LINE__ ) ;
return F_75 ( V_14 , V_92 , V_35 , V_36 ) ;
}
static void F_77 ( struct V_14 * V_14 )
{
F_32 ( L_46 , V_70 , __LINE__ ) ;
F_75 ( V_14 , V_92 , 0 , 0 ) ;
}
static int F_78 ( struct V_14 * V_14 , T_1 V_35 , T_1 V_36 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
int V_6 = 0 ;
struct V_39 * V_40 ;
F_23 ( & V_18 -> V_51 ) ;
if ( F_79 ( & V_18 -> V_71 ) )
goto V_42;
F_80 (s, &cinfo->suspend_list, list)
if ( V_36 > V_40 -> V_35 && V_35 < V_40 -> V_36 ) {
V_6 = 1 ;
break;
}
V_42:
F_26 ( & V_18 -> V_51 ) ;
return V_6 ;
}
static int F_81 ( struct V_14 * V_14 , struct V_88 * V_89 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
struct V_72 V_73 ;
int V_6 = 0 ;
struct V_119 * V_120 = F_82 ( V_89 -> V_121 ) ;
char * V_78 = V_120 -> V_122 ;
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
V_73 . type = F_58 ( V_95 ) ;
memcpy ( V_73 . V_78 , V_78 , 16 ) ;
V_73 . V_76 = V_89 -> V_123 ;
F_55 ( V_18 ) ;
V_6 = F_57 ( V_18 , & V_73 ) ;
if ( V_6 )
return V_6 ;
V_18 -> V_87 -> V_9 |= V_104 ;
V_6 = F_3 ( V_18 -> V_87 , V_68 ) ;
V_18 -> V_87 -> V_9 &= ~ V_104 ;
if ( V_6 == - V_105 )
V_6 = - V_109 ;
else
F_3 ( V_18 -> V_87 , V_41 ) ;
return V_6 ;
}
static int F_83 ( struct V_14 * V_14 )
{
struct V_72 V_73 ;
struct V_17 * V_18 = V_14 -> V_19 ;
int V_6 ;
F_84 ( V_14 , 1 ) ;
V_73 . type = V_91 ;
V_6 = F_57 ( V_18 , & V_73 ) ;
F_56 ( V_18 ) ;
return V_6 ;
}
static int F_85 ( struct V_14 * V_14 , bool V_124 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
if ( ! F_52 ( V_80 , & V_18 -> V_81 ) ) {
F_34 ( L_47 , F_86 ( V_14 ) ) ;
return - V_117 ;
}
if ( V_124 )
F_7 ( V_18 -> V_87 ) ;
F_2 ( & V_18 -> V_79 ) ;
return 0 ;
}
static int F_87 ( struct V_14 * V_14 , struct V_88 * V_89 )
{
struct V_72 V_73 ;
struct V_17 * V_18 = V_14 -> V_19 ;
V_73 . type = REMOVE ;
V_73 . V_76 = V_89 -> V_123 ;
return F_57 ( V_18 , & V_73 ) ;
}
static int F_88 ( struct V_88 * V_89 )
{
int V_125 , V_113 ;
T_1 V_35 , V_36 ;
struct V_72 V_73 ;
struct V_14 * V_14 = V_89 -> V_14 ;
struct V_17 * V_18 = V_14 -> V_19 ;
V_73 . type = V_96 ;
V_73 . V_76 = V_89 -> V_123 ;
V_113 = F_59 ( V_18 , & V_73 ) ;
if ( V_113 )
goto V_42;
for ( V_125 = 0 ; V_125 < V_14 -> V_59 . V_106 ; V_125 ++ ) {
if ( V_125 == ( V_18 -> V_62 - 1 ) )
continue;
V_113 = F_27 ( V_14 , V_125 , & V_35 , & V_36 , false ) ;
if ( V_113 ) {
F_34 ( L_48 , V_125 ) ;
goto V_42;
}
if ( ( V_36 > 0 ) && ( V_35 < V_14 -> V_57 ) )
V_14 -> V_57 = V_35 ;
}
V_42:
return V_113 ;
}
static int T_3 F_89 ( void )
{
F_34 ( L_49 ) ;
F_32 ( L_50 ) ;
F_90 ( & V_126 , V_108 ) ;
return 0 ;
}
static void F_91 ( void )
{
F_92 () ;
}
