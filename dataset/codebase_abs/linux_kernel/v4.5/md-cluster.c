static void F_1 ( void * V_1 )
{
struct V_2 * V_3 ;
V_3 = V_1 ;
F_2 ( & V_3 -> V_4 ) ;
}
static int F_3 ( struct V_2 * V_3 , int V_5 )
{
int V_6 = 0 ;
V_6 = F_4 ( V_3 -> V_7 , V_5 , & V_3 -> V_8 ,
V_3 -> V_9 , V_3 -> V_10 , strlen ( V_3 -> V_10 ) ,
0 , F_1 , V_3 , V_3 -> V_11 ) ;
if ( V_6 )
return V_6 ;
F_5 ( & V_3 -> V_4 ) ;
if ( V_3 -> V_8 . V_12 == 0 )
V_3 -> V_5 = V_5 ;
return V_3 -> V_8 . V_12 ;
}
static int F_6 ( struct V_2 * V_3 )
{
return F_3 ( V_3 , V_13 ) ;
}
static struct V_2 * F_7 ( struct V_14 * V_14 ,
char * V_10 , void (* F_8)( void * V_1 , int V_5 ) , int V_15 )
{
struct V_2 * V_3 = NULL ;
int V_6 , V_16 ;
struct V_17 * V_18 = V_14 -> V_19 ;
V_3 = F_9 ( sizeof( struct V_2 ) , V_20 ) ;
if ( ! V_3 )
return NULL ;
F_10 ( & V_3 -> V_4 ) ;
V_3 -> V_7 = V_18 -> V_21 ;
V_3 -> V_14 = V_14 ;
V_3 -> V_5 = V_22 ;
V_16 = strlen ( V_10 ) ;
V_3 -> V_10 = F_9 ( V_16 + 1 , V_20 ) ;
if ( ! V_3 -> V_10 ) {
F_11 ( L_1 , V_10 ) ;
goto V_23;
}
F_12 ( V_3 -> V_10 , V_10 , V_16 + 1 ) ;
if ( V_15 ) {
V_3 -> V_8 . V_24 = F_9 ( V_25 , V_20 ) ;
if ( ! V_3 -> V_8 . V_24 ) {
F_11 ( L_2 , V_10 ) ;
goto V_23;
}
V_3 -> V_9 = V_26 ;
}
if ( F_8 )
V_3 -> V_11 = F_8 ;
V_3 -> V_9 |= V_27 ;
V_6 = F_3 ( V_3 , V_13 ) ;
if ( V_6 ) {
F_11 ( L_3 , V_10 ) ;
goto V_23;
}
V_3 -> V_9 &= ~ V_27 ;
V_3 -> V_9 |= V_28 ;
return V_3 ;
V_23:
F_13 ( V_3 -> V_8 . V_24 ) ;
F_13 ( V_3 -> V_10 ) ;
F_13 ( V_3 ) ;
return NULL ;
}
static void F_14 ( struct V_2 * V_3 )
{
int V_6 ;
if ( ! V_3 )
return;
V_3 -> V_9 |= V_29 ;
V_30:
V_6 = F_15 ( V_3 -> V_7 , V_3 -> V_8 . V_31 , 0 , & V_3 -> V_8 , V_3 ) ;
if ( F_16 ( V_6 != 0 ) ) {
F_17 ( L_4 , V_32 , V_3 -> V_10 , V_6 ) ;
if ( V_6 == - V_33 )
goto V_30;
}
V_3 -> V_9 &= ~ V_29 ;
F_5 ( & V_3 -> V_4 ) ;
F_13 ( V_3 -> V_10 ) ;
F_13 ( V_3 -> V_8 . V_24 ) ;
F_13 ( V_3 ) ;
}
static void F_18 ( struct V_2 * V_34 ,
T_1 V_35 , T_1 V_36 )
{
struct V_37 * V_38 ;
V_38 = (struct V_37 * ) V_34 -> V_8 . V_24 ;
V_38 -> V_35 = F_19 ( V_35 ) ;
V_38 -> V_36 = F_19 ( V_36 ) ;
}
static struct V_39 * F_20 ( struct V_14 * V_14 , struct V_2 * V_34 )
{
struct V_37 V_38 ;
struct V_39 * V_40 = NULL ;
T_1 V_36 = 0 ;
F_3 ( V_34 , V_41 ) ;
memcpy ( & V_38 , V_34 -> V_8 . V_24 , sizeof( struct V_37 ) ) ;
V_36 = F_21 ( V_38 . V_36 ) ;
if ( V_36 > 0 ) {
V_40 = F_9 ( sizeof( struct V_39 ) , V_20 ) ;
if ( ! V_40 )
goto V_42;
V_40 -> V_36 = V_36 ;
V_40 -> V_35 = F_21 ( V_38 . V_35 ) ;
}
F_6 ( V_34 ) ;
V_42:
return V_40 ;
}
static void F_22 ( struct V_43 * V_44 )
{
struct V_14 * V_14 = V_44 -> V_14 ;
struct V_17 * V_18 = V_14 -> V_19 ;
struct V_2 * V_45 ;
char V_46 [ 64 ] ;
int V_47 , V_6 ;
struct V_39 * V_40 , * V_48 ;
T_1 V_35 , V_36 ;
while ( V_18 -> V_49 ) {
V_47 = F_23 ( ( V_50 ) V_18 -> V_49 ) - 1 ;
F_24 ( & V_18 -> V_51 ) ;
F_25 (s, tmp, &cinfo->suspend_list, list)
if ( V_47 == V_40 -> V_47 ) {
F_26 ( & V_40 -> V_52 ) ;
F_13 ( V_40 ) ;
}
F_27 ( & V_18 -> V_51 ) ;
snprintf ( V_46 , 64 , L_5 , V_47 ) ;
V_45 = F_7 ( V_14 , V_46 , NULL , 1 ) ;
if ( ! V_45 ) {
F_11 ( L_6 ) ;
goto V_53;
}
V_6 = F_3 ( V_45 , V_54 ) ;
if ( V_6 ) {
F_11 ( L_7 ,
V_46 , V_6 ) ;
goto V_53;
}
V_6 = F_28 ( V_14 , V_47 , & V_35 , & V_36 , true ) ;
if ( V_6 ) {
F_11 ( L_8 , V_47 ) ;
goto F_15;
}
if ( V_36 > 0 ) {
F_29 ( V_55 , & V_14 -> V_56 ) ;
if ( V_35 < V_14 -> V_57 )
V_14 -> V_57 = V_35 ;
F_30 ( V_14 ) ;
}
F_15:
F_6 ( V_45 ) ;
V_53:
F_14 ( V_45 ) ;
V_53 ( V_47 , & V_18 -> V_49 ) ;
}
}
static void F_31 ( void * V_1 )
{
struct V_14 * V_14 = V_1 ;
struct V_17 * V_18 = V_14 -> V_19 ;
F_29 ( V_58 , & V_18 -> V_59 ) ;
}
static void F_32 ( struct V_14 * V_14 , int V_47 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
F_29 ( V_47 , & V_18 -> V_49 ) ;
if ( ! V_18 -> V_60 ) {
V_18 -> V_60 = F_33 ( F_22 ,
V_14 , L_9 ) ;
if ( ! V_18 -> V_60 ) {
F_34 ( L_10 ) ;
return;
}
}
F_35 ( V_18 -> V_60 ) ;
}
static void F_36 ( void * V_1 , struct V_61 * V_47 )
{
struct V_14 * V_14 = V_1 ;
struct V_17 * V_18 = V_14 -> V_19 ;
F_17 ( L_11 ,
V_14 -> V_62 . V_63 ,
V_47 -> V_64 , V_47 -> V_47 ,
V_18 -> V_65 ) ;
F_32 ( V_14 , V_47 -> V_47 - 1 ) ;
}
static void F_37 ( void * V_1 , struct V_61 * V_66 ,
int V_67 , int V_68 ,
T_2 V_69 )
{
struct V_14 * V_14 = V_1 ;
struct V_17 * V_18 = V_14 -> V_19 ;
V_18 -> V_65 = V_68 ;
if ( F_38 ( V_70 , & V_18 -> V_59 ) ) {
F_2 ( & V_18 -> V_4 ) ;
V_53 ( V_70 , & V_18 -> V_59 ) ;
}
V_53 ( V_58 , & V_18 -> V_59 ) ;
}
static void F_39 ( void * V_1 , int V_5 )
{
struct V_2 * V_3 = V_1 ;
struct V_17 * V_18 = V_3 -> V_14 -> V_19 ;
if ( V_5 == V_71 )
F_35 ( V_18 -> V_72 ) ;
}
static void F_40 ( struct V_17 * V_18 , int V_47 )
{
struct V_39 * V_40 , * V_48 ;
F_25 (s, tmp, &cinfo->suspend_list, list)
if ( V_47 == V_40 -> V_47 ) {
F_26 ( & V_40 -> V_52 ) ;
F_13 ( V_40 ) ;
break;
}
}
static void F_41 ( struct V_14 * V_14 , int V_47 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
F_24 ( & V_18 -> V_51 ) ;
F_40 ( V_18 , V_47 ) ;
F_27 ( & V_18 -> V_51 ) ;
V_14 -> V_73 -> V_74 ( V_14 , 2 ) ;
}
static void F_42 ( struct V_14 * V_14 ,
int V_47 , T_1 V_35 , T_1 V_36 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
struct V_39 * V_40 ;
if ( ! V_36 ) {
F_41 ( V_14 , V_47 ) ;
F_29 ( V_55 , & V_14 -> V_56 ) ;
F_35 ( V_14 -> V_44 ) ;
return;
}
V_40 = F_9 ( sizeof( struct V_39 ) , V_20 ) ;
if ( ! V_40 )
return;
V_40 -> V_47 = V_47 ;
V_40 -> V_35 = V_35 ;
V_40 -> V_36 = V_36 ;
V_14 -> V_73 -> V_74 ( V_14 , 1 ) ;
V_14 -> V_73 -> V_74 ( V_14 , 0 ) ;
F_24 ( & V_18 -> V_51 ) ;
F_40 ( V_18 , V_47 ) ;
F_43 ( & V_40 -> V_52 , & V_18 -> V_75 ) ;
F_27 ( & V_18 -> V_51 ) ;
V_14 -> V_73 -> V_74 ( V_14 , 2 ) ;
}
static void F_44 ( struct V_14 * V_14 , struct V_76 * V_77 )
{
char V_78 [ 64 ] ;
struct V_17 * V_18 = V_14 -> V_19 ;
char V_79 [] = L_12 ;
char V_80 [ 16 ] ;
char * V_81 [] = { V_79 , V_78 , V_80 , NULL } ;
int V_82 ;
V_82 = snprintf ( V_78 , 64 , L_13 ) ;
sprintf ( V_78 + V_82 , L_14 , V_77 -> V_83 ) ;
snprintf ( V_80 , 16 , L_15 , F_45 ( V_77 -> V_80 ) ) ;
F_17 ( L_16 , V_32 , __LINE__ , V_78 , V_80 ) ;
F_10 ( & V_18 -> V_84 ) ;
F_29 ( V_85 , & V_18 -> V_59 ) ;
F_46 ( & F_47 ( V_14 -> V_86 ) -> V_87 , V_88 , V_81 ) ;
F_48 ( & V_18 -> V_84 ,
V_89 ) ;
V_53 ( V_85 , & V_18 -> V_59 ) ;
}
static void F_49 ( struct V_14 * V_14 , struct V_76 * V_90 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
V_14 -> V_91 = F_45 ( V_90 -> V_80 ) ;
F_29 ( V_92 , & V_14 -> V_9 ) ;
F_3 ( V_18 -> V_93 , V_41 ) ;
F_35 ( V_14 -> V_44 ) ;
}
static void F_50 ( struct V_14 * V_14 , struct V_76 * V_90 )
{
struct V_94 * V_95 = F_51 ( V_14 ,
F_45 ( V_90 -> V_80 ) ) ;
if ( V_95 ) {
F_29 ( V_96 , & V_95 -> V_9 ) ;
F_29 ( V_55 , & V_14 -> V_56 ) ;
F_35 ( V_14 -> V_44 ) ;
}
else
F_34 ( L_17 ,
V_32 , __LINE__ , F_45 ( V_90 -> V_80 ) ) ;
}
static void F_52 ( struct V_14 * V_14 , struct V_76 * V_90 )
{
struct V_94 * V_95 = F_51 ( V_14 ,
F_45 ( V_90 -> V_80 ) ) ;
if ( V_95 && F_38 ( V_97 , & V_95 -> V_9 ) )
V_53 ( V_97 , & V_95 -> V_9 ) ;
else
F_34 ( L_18 ,
V_32 , __LINE__ , F_45 ( V_90 -> V_80 ) ) ;
}
static void F_53 ( struct V_14 * V_14 , struct V_76 * V_90 )
{
if ( F_54 ( V_14 -> V_19 -> V_65 - 1 == F_45 ( V_90 -> V_47 ) ,
L_19 , F_45 ( V_90 -> V_47 ) ) )
return;
switch ( F_45 ( V_90 -> type ) ) {
case V_98 :
F_49 ( V_14 , V_90 ) ;
break;
case V_99 :
F_42 ( V_14 , F_45 ( V_90 -> V_47 ) ,
F_21 ( V_90 -> V_100 ) ,
F_21 ( V_90 -> V_101 ) ) ;
break;
case V_102 :
F_44 ( V_14 , V_90 ) ;
break;
case REMOVE :
F_50 ( V_14 , V_90 ) ;
break;
case V_103 :
F_52 ( V_14 , V_90 ) ;
break;
case V_104 :
F_32 ( V_14 , F_45 ( V_90 -> V_47 ) ) ;
break;
default:
F_34 ( L_20 ,
V_32 , __LINE__ , V_90 -> V_47 ) ;
}
}
static void F_55 ( struct V_43 * V_44 )
{
struct V_17 * V_18 = V_44 -> V_14 -> V_19 ;
struct V_2 * V_105 = V_18 -> V_105 ;
struct V_2 * V_106 = V_18 -> V_106 ;
struct V_76 V_90 ;
int V_6 ;
F_56 ( & V_18 -> V_107 ) ;
if ( F_3 ( V_106 , V_41 ) ) {
F_11 ( L_21 ) ;
F_57 ( & V_18 -> V_107 ) ;
return;
}
memcpy ( & V_90 , V_106 -> V_8 . V_24 , sizeof( struct V_76 ) ) ;
F_53 ( V_44 -> V_14 , & V_90 ) ;
V_6 = F_6 ( V_105 ) ;
if ( F_16 ( V_6 != 0 ) )
F_17 ( L_22 , V_6 ) ;
V_6 = F_3 ( V_106 , V_108 ) ;
if ( F_16 ( V_6 != 0 ) )
F_17 ( L_23 , V_6 ) ;
V_6 = F_3 ( V_105 , V_41 ) ;
if ( F_16 ( V_6 != 0 ) )
F_17 ( L_24 , V_6 ) ;
V_6 = F_6 ( V_106 ) ;
if ( F_16 ( V_6 != 0 ) )
F_17 ( L_25 , V_6 ) ;
F_57 ( & V_18 -> V_107 ) ;
}
static int F_58 ( struct V_17 * V_18 )
{
int error ;
error = F_3 ( V_18 -> V_109 , V_71 ) ;
if ( error )
F_11 ( L_26 ,
V_32 , __LINE__ , error ) ;
F_56 ( & V_18 -> V_107 ) ;
return error ;
}
static int F_59 ( struct V_17 * V_18 )
{
F_60 ( V_18 -> V_110 ,
! F_61 ( V_111 , & V_18 -> V_59 ) ) ;
return F_58 ( V_18 ) ;
}
static void F_62 ( struct V_17 * V_18 )
{
F_63 ( V_18 -> V_109 -> V_5 != V_71 ) ;
F_57 ( & V_18 -> V_107 ) ;
F_6 ( V_18 -> V_109 ) ;
V_53 ( V_111 , & V_18 -> V_59 ) ;
F_64 ( & V_18 -> V_110 ) ;
}
static int F_65 ( struct V_17 * V_18 , struct V_76 * V_77 )
{
int error ;
int V_47 = V_18 -> V_65 - 1 ;
V_77 -> V_47 = F_66 ( V_47 ) ;
error = F_3 ( V_18 -> V_106 , V_71 ) ;
if ( error ) {
F_11 ( L_27 , error ) ;
goto V_112;
}
memcpy ( V_18 -> V_106 -> V_8 . V_24 , ( void * ) V_77 ,
sizeof( struct V_76 ) ) ;
error = F_3 ( V_18 -> V_106 , V_113 ) ;
if ( error ) {
F_11 ( L_28 ,
error ) ;
goto V_114;
}
error = F_3 ( V_18 -> V_105 , V_71 ) ;
if ( error ) {
F_11 ( L_29 ,
error ) ;
goto V_114;
}
error = F_3 ( V_18 -> V_105 , V_41 ) ;
if ( error ) {
F_11 ( L_30 ,
error ) ;
goto V_114;
}
V_114:
error = F_6 ( V_18 -> V_106 ) ;
if ( F_16 ( error != 0 ) ) {
F_11 ( L_31 ,
error ) ;
goto V_114;
}
V_112:
return error ;
}
static int F_67 ( struct V_17 * V_18 , struct V_76 * V_77 )
{
int V_6 ;
F_59 ( V_18 ) ;
V_6 = F_65 ( V_18 , V_77 ) ;
F_62 ( V_18 ) ;
return V_6 ;
}
static int F_68 ( struct V_14 * V_14 , int V_115 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
int V_116 , V_6 = 0 ;
struct V_2 * V_45 ;
struct V_39 * V_40 ;
char V_46 [ 64 ] ;
T_1 V_35 , V_36 ;
for ( V_116 = 0 ; V_116 < V_115 ; V_116 ++ ) {
memset ( V_46 , '\0' , 64 ) ;
snprintf ( V_46 , 64 , L_5 , V_116 ) ;
V_45 = F_7 ( V_14 , V_46 , NULL , 1 ) ;
if ( ! V_45 )
return - V_117 ;
if ( V_116 == ( V_18 -> V_65 - 1 ) ) {
F_14 ( V_45 ) ;
continue;
}
V_45 -> V_9 |= V_118 ;
V_6 = F_3 ( V_45 , V_54 ) ;
if ( V_6 == - V_119 ) {
memset ( V_45 -> V_8 . V_24 , '\0' , V_25 ) ;
V_40 = F_20 ( V_14 , V_45 ) ;
if ( V_40 ) {
F_17 ( L_32 ,
V_32 , __LINE__ ,
( unsigned long long ) V_40 -> V_35 ,
( unsigned long long ) V_40 -> V_36 , V_116 ) ;
F_24 ( & V_18 -> V_51 ) ;
V_40 -> V_47 = V_116 ;
F_43 ( & V_40 -> V_52 , & V_18 -> V_75 ) ;
F_27 ( & V_18 -> V_51 ) ;
}
V_6 = 0 ;
F_14 ( V_45 ) ;
continue;
}
if ( V_6 ) {
F_14 ( V_45 ) ;
goto V_42;
}
V_6 = F_28 ( V_14 , V_116 , & V_35 , & V_36 , false ) ;
if ( V_6 ) {
F_34 ( L_33 , V_116 ) ;
F_14 ( V_45 ) ;
continue;
}
if ( ( V_36 > 0 ) && ( V_35 < V_14 -> V_57 ) ) {
F_29 ( V_55 , & V_14 -> V_56 ) ;
V_14 -> V_57 = V_35 ;
F_30 ( V_14 ) ;
}
F_6 ( V_45 ) ;
F_14 ( V_45 ) ;
}
V_42:
return V_6 ;
}
static int F_69 ( struct V_14 * V_14 , int V_120 )
{
struct V_17 * V_18 ;
int V_6 , V_121 ;
char V_46 [ 64 ] ;
V_18 = F_9 ( sizeof( struct V_17 ) , V_20 ) ;
if ( ! V_18 )
return - V_117 ;
F_70 ( & V_18 -> V_75 ) ;
F_71 ( & V_18 -> V_51 ) ;
F_10 ( & V_18 -> V_4 ) ;
F_29 ( V_70 , & V_18 -> V_59 ) ;
F_72 ( & V_18 -> V_110 ) ;
F_73 ( & V_18 -> V_107 ) ;
V_14 -> V_19 = V_18 ;
memset ( V_46 , 0 , 64 ) ;
sprintf ( V_46 , L_14 , V_14 -> V_83 ) ;
V_6 = F_74 ( V_46 , V_14 -> V_62 . V_63 ,
V_122 , V_25 ,
& V_123 , V_14 , & V_121 , & V_18 -> V_21 ) ;
if ( V_6 )
goto V_124;
F_5 ( & V_18 -> V_4 ) ;
if ( V_120 < V_18 -> V_65 ) {
F_11 ( L_34 ,
V_18 -> V_65 , V_120 ) ;
V_6 = - V_125 ;
goto V_124;
}
V_6 = - V_117 ;
V_18 -> V_72 = F_33 ( F_55 , V_14 , L_35 ) ;
if ( ! V_18 -> V_72 ) {
F_11 ( L_36 ) ;
goto V_124;
}
V_18 -> V_106 = F_7 ( V_14 , L_37 , NULL , 1 ) ;
if ( ! V_18 -> V_106 )
goto V_124;
V_18 -> V_109 = F_7 ( V_14 , L_38 , NULL , 0 ) ;
if ( ! V_18 -> V_109 )
goto V_124;
V_18 -> V_105 = F_7 ( V_14 , L_39 , F_39 , 0 ) ;
if ( ! V_18 -> V_105 )
goto V_124;
V_18 -> V_93 = F_7 ( V_14 , L_40 , NULL , 0 ) ;
if ( ! V_18 -> V_93 )
goto V_124;
if ( F_3 ( V_18 -> V_105 , V_41 ) )
F_11 ( L_41 ,
V_6 ) ;
if ( F_3 ( V_18 -> V_93 , V_41 ) )
F_11 ( L_42 , V_6 ) ;
F_17 ( L_43 , V_46 , V_18 -> V_65 ) ;
snprintf ( V_46 , 64 , L_5 , V_18 -> V_65 - 1 ) ;
V_18 -> V_126 = F_7 ( V_14 , V_46 , NULL , 1 ) ;
if ( ! V_18 -> V_126 )
goto V_124;
if ( F_3 ( V_18 -> V_126 , V_54 ) ) {
F_11 ( L_44 ) ;
V_6 = - V_127 ;
goto V_124;
}
V_18 -> V_128 = F_7 ( V_14 , L_45 , NULL , 0 ) ;
if ( ! V_18 -> V_128 )
goto V_124;
V_6 = F_68 ( V_14 , V_120 ) ;
if ( V_6 )
goto V_124;
return 0 ;
V_124:
F_14 ( V_18 -> V_106 ) ;
F_14 ( V_18 -> V_109 ) ;
F_14 ( V_18 -> V_105 ) ;
F_14 ( V_18 -> V_93 ) ;
F_14 ( V_18 -> V_128 ) ;
F_14 ( V_18 -> V_126 ) ;
if ( V_18 -> V_21 )
F_75 ( V_18 -> V_21 , 2 ) ;
V_14 -> V_19 = NULL ;
F_13 ( V_18 ) ;
return V_6 ;
}
static void F_76 ( struct V_14 * V_14 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
struct V_76 V_77 = { 0 } ;
int V_124 ;
V_77 . type = F_66 ( V_104 ) ;
V_124 = F_67 ( V_18 , & V_77 ) ;
if ( V_124 )
F_11 ( L_46 ,
V_32 , __LINE__ , V_124 ) ;
}
static int F_77 ( struct V_14 * V_14 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
if ( ! V_18 )
return 0 ;
if ( V_18 -> V_65 > 0 && V_14 -> V_57 != V_129 )
F_76 ( V_14 ) ;
F_78 ( & V_18 -> V_60 ) ;
F_78 ( & V_18 -> V_72 ) ;
F_14 ( V_18 -> V_106 ) ;
F_14 ( V_18 -> V_109 ) ;
F_14 ( V_18 -> V_105 ) ;
F_14 ( V_18 -> V_93 ) ;
F_14 ( V_18 -> V_128 ) ;
F_14 ( V_18 -> V_126 ) ;
F_79 ( V_14 ) ;
F_75 ( V_18 -> V_21 , 2 ) ;
return 0 ;
}
static int V_65 ( struct V_14 * V_14 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
return V_18 -> V_65 - 1 ;
}
static int F_80 ( struct V_14 * V_14 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
F_60 ( V_18 -> V_110 ,
! F_61 ( V_111 , & V_18 -> V_59 ) ||
F_81 ( V_130 , & V_18 -> V_59 ) ) ;
if ( V_18 -> V_109 -> V_5 == V_71 )
return 0 ;
return F_58 ( V_18 ) ;
}
static int F_82 ( struct V_14 * V_14 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
struct V_76 V_77 ;
struct V_94 * V_95 ;
int V_6 = 0 ;
int V_80 = - 1 ;
memset ( & V_77 , 0 , sizeof( V_77 ) ) ;
V_77 . type = F_66 ( V_98 ) ;
F_83 (rdev, mddev)
if ( V_95 -> V_131 > - 1 && ! F_38 ( V_97 , & V_95 -> V_9 ) ) {
V_80 = V_95 -> V_132 ;
break;
}
if ( V_80 >= 0 ) {
V_77 . V_80 = F_66 ( V_80 ) ;
V_6 = F_65 ( V_18 , & V_77 ) ;
} else
F_34 ( L_47 ) ;
V_53 ( V_130 , & V_18 -> V_59 ) ;
F_62 ( V_18 ) ;
return V_6 ;
}
static void F_84 ( struct V_14 * V_14 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
V_53 ( V_130 , & V_18 -> V_59 ) ;
F_62 ( V_18 ) ;
}
static int F_85 ( struct V_14 * V_14 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
V_18 -> V_128 -> V_9 |= V_118 ;
return F_3 ( V_18 -> V_128 , V_71 ) ;
}
static int F_86 ( struct V_14 * V_14 , T_1 V_35 , T_1 V_36 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
struct V_37 V_38 ;
struct V_76 V_77 = { 0 } ;
if ( V_36 == 0 ) {
memcpy ( & V_38 , V_18 -> V_126 -> V_8 . V_24 , sizeof( struct V_37 ) ) ;
if ( F_21 ( V_38 . V_36 ) == 0 )
return 0 ;
}
F_18 ( V_18 -> V_126 , V_35 , V_36 ) ;
F_3 ( V_18 -> V_126 , V_54 ) ;
V_77 . type = F_66 ( V_99 ) ;
V_77 . V_100 = F_19 ( V_35 ) ;
V_77 . V_101 = F_19 ( V_36 ) ;
return F_67 ( V_18 , & V_77 ) ;
}
static int F_87 ( struct V_14 * V_14 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
V_18 -> V_128 -> V_9 &= ~ V_118 ;
F_6 ( V_18 -> V_128 ) ;
return F_86 ( V_14 , 0 , 0 ) ;
}
static int F_88 ( struct V_14 * V_14 , int V_133 ,
T_1 V_35 , T_1 V_36 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
int V_6 = 0 ;
struct V_39 * V_40 ;
if ( ( V_133 == V_134 ) &&
F_38 ( V_58 , & V_18 -> V_59 ) )
return 1 ;
F_24 ( & V_18 -> V_51 ) ;
if ( F_89 ( & V_18 -> V_75 ) )
goto V_42;
F_90 (s, &cinfo->suspend_list, list)
if ( V_36 > V_40 -> V_35 && V_35 < V_40 -> V_36 ) {
V_6 = 1 ;
break;
}
V_42:
F_27 ( & V_18 -> V_51 ) ;
return V_6 ;
}
static int F_91 ( struct V_14 * V_14 , struct V_94 * V_95 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
struct V_76 V_77 ;
int V_6 = 0 ;
struct V_135 * V_136 = F_92 ( V_95 -> V_137 ) ;
char * V_83 = V_136 -> V_138 ;
memset ( & V_77 , 0 , sizeof( V_77 ) ) ;
V_77 . type = F_66 ( V_102 ) ;
memcpy ( V_77 . V_83 , V_83 , 16 ) ;
V_77 . V_80 = F_66 ( V_95 -> V_132 ) ;
F_59 ( V_18 ) ;
V_6 = F_65 ( V_18 , & V_77 ) ;
if ( V_6 )
return V_6 ;
V_18 -> V_93 -> V_9 |= V_118 ;
V_6 = F_3 ( V_18 -> V_93 , V_71 ) ;
V_18 -> V_93 -> V_9 &= ~ V_118 ;
if ( V_6 == - V_119 )
V_6 = - V_139 ;
if ( V_6 )
F_62 ( V_18 ) ;
else {
F_3 ( V_18 -> V_93 , V_41 ) ;
F_29 ( V_130 , & V_18 -> V_59 ) ;
F_64 ( & V_18 -> V_110 ) ;
}
return V_6 ;
}
static void F_93 ( struct V_14 * V_14 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
V_53 ( V_130 , & V_18 -> V_59 ) ;
F_62 ( V_18 ) ;
}
static int F_94 ( struct V_14 * V_14 , bool V_140 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
if ( ! F_38 ( V_85 , & V_18 -> V_59 ) ) {
F_34 ( L_48 , F_95 ( V_14 ) ) ;
return - V_127 ;
}
if ( V_140 )
F_6 ( V_18 -> V_93 ) ;
F_2 ( & V_18 -> V_84 ) ;
return 0 ;
}
static int F_96 ( struct V_14 * V_14 , struct V_94 * V_95 )
{
struct V_76 V_77 = { 0 } ;
struct V_17 * V_18 = V_14 -> V_19 ;
V_77 . type = F_66 ( REMOVE ) ;
V_77 . V_80 = F_66 ( V_95 -> V_132 ) ;
return F_67 ( V_18 , & V_77 ) ;
}
static int F_97 ( struct V_14 * V_14 )
{
int V_47 , V_141 , V_6 , V_142 = 1 , V_116 = 0 ;
char V_46 [ 64 ] ;
struct V_17 * V_18 = V_14 -> V_19 ;
V_18 -> V_143 = F_9 ( ( V_14 -> V_62 . V_120 - 1 ) *
sizeof( struct V_2 * ) ,
V_20 ) ;
if ( ! V_18 -> V_143 ) {
F_11 ( L_49 ) ;
return 0 ;
}
V_141 = V_65 ( V_14 ) ;
for ( V_47 = 0 ; V_47 < V_14 -> V_62 . V_120 ; V_47 ++ ) {
if ( V_47 == V_141 )
continue;
memset ( V_46 , '\0' , 64 ) ;
snprintf ( V_46 , 64 , L_5 , V_47 ) ;
V_18 -> V_143 [ V_116 ] = F_7 ( V_14 , V_46 , NULL , 1 ) ;
if ( ! V_18 -> V_143 [ V_116 ] )
return - V_117 ;
V_18 -> V_143 [ V_116 ] -> V_9 |= V_118 ;
V_6 = F_3 ( V_18 -> V_143 [ V_116 ] , V_54 ) ;
if ( V_6 )
V_142 = - 1 ;
V_116 ++ ;
}
return V_142 ;
}
static void F_79 ( struct V_14 * V_14 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
int V_116 ;
if ( V_18 -> V_143 ) {
for ( V_116 = 0 ; V_116 < V_14 -> V_62 . V_120 - 1 ; V_116 ++ ) {
if ( V_18 -> V_143 [ V_116 ] ) {
F_6 ( V_18 -> V_143 [ V_116 ] ) ;
F_14 ( V_18 -> V_143 [ V_116 ] ) ;
}
}
F_13 ( V_18 -> V_143 ) ;
}
}
static int F_98 ( struct V_94 * V_95 )
{
int V_144 , V_124 ;
T_1 V_35 , V_36 ;
struct V_76 V_77 = { 0 } ;
struct V_14 * V_14 = V_95 -> V_14 ;
struct V_17 * V_18 = V_14 -> V_19 ;
V_77 . type = F_66 ( V_103 ) ;
V_77 . V_80 = F_66 ( V_95 -> V_132 ) ;
V_124 = F_67 ( V_18 , & V_77 ) ;
if ( V_124 )
goto V_42;
for ( V_144 = 0 ; V_144 < V_14 -> V_62 . V_120 ; V_144 ++ ) {
if ( V_144 == ( V_18 -> V_65 - 1 ) )
continue;
V_124 = F_28 ( V_14 , V_144 , & V_35 , & V_36 , false ) ;
if ( V_124 ) {
F_34 ( L_33 , V_144 ) ;
goto V_42;
}
if ( ( V_36 > 0 ) && ( V_35 < V_14 -> V_57 ) )
V_14 -> V_57 = V_35 ;
}
V_42:
return V_124 ;
}
static int T_3 F_99 ( void )
{
F_34 ( L_50 ) ;
F_17 ( L_51 ) ;
F_100 ( & V_145 , V_146 ) ;
return 0 ;
}
static void F_101 ( void )
{
F_102 () ;
}
