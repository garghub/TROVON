static void F_1 ( void * V_1 )
{
struct V_2 * V_3 ;
V_3 = (struct V_2 * ) V_1 ;
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
V_16 = strlen ( V_10 ) ;
V_3 -> V_10 = F_9 ( V_16 + 1 , V_20 ) ;
if ( ! V_3 -> V_10 ) {
F_11 ( L_1 , V_10 ) ;
goto V_22;
}
F_12 ( V_3 -> V_10 , V_10 , V_16 + 1 ) ;
if ( V_15 ) {
V_3 -> V_8 . V_23 = F_9 ( V_24 , V_20 ) ;
if ( ! V_3 -> V_8 . V_23 ) {
F_11 ( L_2 , V_10 ) ;
goto V_22;
}
V_3 -> V_9 = V_25 ;
}
if ( F_8 )
V_3 -> V_11 = F_8 ;
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
int V_6 ;
if ( ! V_3 )
return;
V_3 -> V_9 |= V_28 ;
V_29:
V_6 = F_15 ( V_3 -> V_7 , V_3 -> V_8 . V_30 , 0 , & V_3 -> V_8 , V_3 ) ;
if ( F_16 ( V_6 != 0 ) ) {
F_17 ( L_4 , V_31 , V_3 -> V_10 , V_6 ) ;
if ( V_6 == - V_32 )
goto V_29;
}
V_3 -> V_9 &= ~ V_28 ;
F_5 ( & V_3 -> V_4 ) ;
F_13 ( V_3 -> V_10 ) ;
F_13 ( V_3 -> V_8 . V_23 ) ;
F_13 ( V_3 ) ;
}
static void F_18 ( struct V_14 * V_14 , struct V_2 * V_33 ,
T_1 V_34 , T_1 V_35 )
{
struct V_36 * V_37 ;
V_37 = (struct V_36 * ) V_33 -> V_8 . V_23 ;
V_37 -> V_34 = F_19 ( V_34 ) ;
V_37 -> V_35 = F_19 ( V_35 ) ;
}
static struct V_38 * F_20 ( struct V_14 * V_14 , struct V_2 * V_33 )
{
struct V_36 V_37 ;
struct V_38 * V_39 = NULL ;
T_1 V_35 = 0 ;
F_3 ( V_33 , V_40 ) ;
memcpy ( & V_37 , V_33 -> V_8 . V_23 , sizeof( struct V_36 ) ) ;
V_35 = F_21 ( V_37 . V_35 ) ;
if ( V_37 . V_35 > 0 ) {
V_39 = F_9 ( sizeof( struct V_38 ) , V_20 ) ;
if ( ! V_39 )
goto V_41;
V_39 -> V_35 = V_35 ;
V_39 -> V_34 = F_21 ( V_37 . V_34 ) ;
}
F_6 ( V_33 ) ;
V_41:
return V_39 ;
}
static void F_22 ( struct V_42 * V_43 )
{
struct V_14 * V_14 = V_43 -> V_14 ;
struct V_17 * V_18 = V_14 -> V_19 ;
struct V_2 * V_44 ;
char V_45 [ 64 ] ;
int V_46 , V_6 ;
struct V_38 * V_39 , * V_47 ;
T_1 V_34 , V_35 ;
while ( V_18 -> V_48 ) {
V_46 = F_23 ( ( V_49 ) V_18 -> V_48 ) - 1 ;
F_24 ( & V_18 -> V_50 ) ;
F_25 (s, tmp, &cinfo->suspend_list, list)
if ( V_46 == V_39 -> V_46 ) {
F_26 ( & V_39 -> V_51 ) ;
F_13 ( V_39 ) ;
}
F_27 ( & V_18 -> V_50 ) ;
snprintf ( V_45 , 64 , L_5 , V_46 ) ;
V_44 = F_7 ( V_14 , V_45 , NULL , 1 ) ;
if ( ! V_44 ) {
F_11 ( L_6 ) ;
goto V_52;
}
V_6 = F_3 ( V_44 , V_53 ) ;
if ( V_6 ) {
F_11 ( L_7 ,
V_45 , V_6 ) ;
goto V_52;
}
V_6 = F_28 ( V_14 , V_46 , & V_34 , & V_35 , true ) ;
if ( V_6 ) {
F_11 ( L_8 , V_46 ) ;
goto F_15;
}
if ( V_35 > 0 ) {
F_29 ( V_54 , & V_14 -> V_55 ) ;
if ( V_34 < V_14 -> V_56 )
V_14 -> V_56 = V_34 ;
F_30 ( V_14 ) ;
}
F_15:
F_6 ( V_44 ) ;
V_52:
V_52 ( V_46 , & V_18 -> V_48 ) ;
}
}
static void F_31 ( void * V_1 )
{
struct V_14 * V_14 = V_1 ;
struct V_17 * V_18 = V_14 -> V_19 ;
F_29 ( V_57 , & V_18 -> V_58 ) ;
}
static void F_32 ( struct V_14 * V_14 , int V_46 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
F_29 ( V_46 , & V_18 -> V_48 ) ;
if ( ! V_18 -> V_59 ) {
V_18 -> V_59 = F_33 ( F_22 ,
V_14 , L_9 ) ;
if ( ! V_18 -> V_59 ) {
F_34 ( L_10 ) ;
return;
}
}
F_35 ( V_18 -> V_59 ) ;
}
static void F_36 ( void * V_1 , struct V_60 * V_46 )
{
struct V_14 * V_14 = V_1 ;
struct V_17 * V_18 = V_14 -> V_19 ;
F_17 ( L_11 ,
V_14 -> V_61 . V_62 ,
V_46 -> V_63 , V_46 -> V_46 ,
V_18 -> V_64 ) ;
F_32 ( V_14 , V_46 -> V_46 - 1 ) ;
}
static void F_37 ( void * V_1 , struct V_60 * V_65 ,
int V_66 , int V_67 ,
T_2 V_68 )
{
struct V_14 * V_14 = V_1 ;
struct V_17 * V_18 = V_14 -> V_19 ;
V_18 -> V_64 = V_67 ;
if ( F_38 ( V_69 , & V_18 -> V_58 ) ) {
F_2 ( & V_18 -> V_4 ) ;
V_52 ( V_69 , & V_18 -> V_58 ) ;
}
V_52 ( V_57 , & V_18 -> V_58 ) ;
}
static void F_39 ( void * V_1 , int V_5 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
struct V_17 * V_18 = V_3 -> V_14 -> V_19 ;
if ( V_5 == V_70 )
F_35 ( V_18 -> V_71 ) ;
}
static void F_40 ( struct V_17 * V_18 , int V_46 )
{
struct V_38 * V_39 , * V_47 ;
F_25 (s, tmp, &cinfo->suspend_list, list)
if ( V_46 == V_39 -> V_46 ) {
F_17 ( L_12 ,
V_31 , __LINE__ , V_46 ) ;
F_26 ( & V_39 -> V_51 ) ;
F_13 ( V_39 ) ;
break;
}
}
static void F_41 ( struct V_17 * V_18 , int V_46 )
{
F_24 ( & V_18 -> V_50 ) ;
F_40 ( V_18 , V_46 ) ;
F_27 ( & V_18 -> V_50 ) ;
}
static void F_42 ( struct V_17 * V_18 ,
int V_46 , T_1 V_34 , T_1 V_35 )
{
struct V_38 * V_39 ;
if ( ! V_35 ) {
F_41 ( V_18 , V_46 ) ;
return;
}
V_39 = F_9 ( sizeof( struct V_38 ) , V_20 ) ;
if ( ! V_39 )
return;
V_39 -> V_46 = V_46 ;
V_39 -> V_34 = V_34 ;
V_39 -> V_35 = V_35 ;
F_24 ( & V_18 -> V_50 ) ;
F_40 ( V_18 , V_46 ) ;
F_43 ( & V_39 -> V_51 , & V_18 -> V_72 ) ;
F_27 ( & V_18 -> V_50 ) ;
}
static void F_44 ( struct V_14 * V_14 , struct V_73 * V_74 )
{
char V_75 [ 64 ] ;
struct V_17 * V_18 = V_14 -> V_19 ;
char V_76 [] = L_13 ;
char V_77 [ 16 ] ;
char * V_78 [] = { V_76 , V_75 , V_77 , NULL } ;
int V_79 ;
V_79 = snprintf ( V_75 , 64 , L_14 ) ;
sprintf ( V_75 + V_79 , L_15 , V_74 -> V_80 ) ;
snprintf ( V_77 , 16 , L_16 , V_74 -> V_77 ) ;
F_17 ( L_17 , V_31 , __LINE__ , V_75 , V_77 ) ;
F_10 ( & V_18 -> V_81 ) ;
F_29 ( V_82 , & V_18 -> V_58 ) ;
F_45 ( & F_46 ( V_14 -> V_83 ) -> V_84 , V_85 , V_78 ) ;
F_47 ( & V_18 -> V_81 ,
V_86 ) ;
V_52 ( V_82 , & V_18 -> V_58 ) ;
}
static void F_48 ( struct V_14 * V_14 , struct V_73 * V_87 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
F_49 ( V_14 ) ;
F_3 ( V_18 -> V_88 , V_40 ) ;
}
static void F_50 ( struct V_14 * V_14 , struct V_73 * V_87 )
{
struct V_89 * V_90 = F_51 ( V_14 , V_87 -> V_77 ) ;
if ( V_90 )
F_52 ( V_90 ) ;
else
F_34 ( L_18 , V_31 , __LINE__ , V_87 -> V_77 ) ;
}
static void F_53 ( struct V_14 * V_14 , struct V_73 * V_87 )
{
struct V_89 * V_90 = F_51 ( V_14 , V_87 -> V_77 ) ;
if ( V_90 && F_38 ( V_91 , & V_90 -> V_9 ) )
V_52 ( V_91 , & V_90 -> V_9 ) ;
else
F_34 ( L_19 , V_31 , __LINE__ , V_87 -> V_77 ) ;
}
static void F_54 ( struct V_14 * V_14 , struct V_73 * V_87 )
{
switch ( V_87 -> type ) {
case V_92 :
F_17 ( L_20 ,
V_31 , __LINE__ , V_87 -> V_46 ) ;
F_48 ( V_14 , V_87 ) ;
break;
case V_93 :
F_17 ( L_21 ,
V_31 , __LINE__ , V_87 -> V_46 ) ;
F_42 ( V_14 -> V_19 , V_87 -> V_46 ,
V_87 -> V_94 , V_87 -> V_95 ) ;
break;
case V_96 :
F_17 ( L_22 ,
V_31 , __LINE__ , V_87 -> V_46 ) ;
F_44 ( V_14 , V_87 ) ;
break;
case REMOVE :
F_17 ( L_23 ,
V_31 , __LINE__ , V_87 -> V_46 ) ;
F_50 ( V_14 , V_87 ) ;
break;
case V_97 :
F_17 ( L_24 ,
V_31 , __LINE__ , V_87 -> V_46 ) ;
F_53 ( V_14 , V_87 ) ;
break;
case V_98 :
F_17 ( L_25 ,
V_31 , __LINE__ , V_87 -> V_46 ) ;
F_32 ( V_14 , V_87 -> V_46 ) ;
break;
default:
F_34 ( L_26 ,
V_31 , __LINE__ , V_87 -> V_46 ) ;
}
}
static void F_55 ( struct V_42 * V_43 )
{
struct V_17 * V_18 = V_43 -> V_14 -> V_19 ;
struct V_2 * V_99 = V_18 -> V_99 ;
struct V_2 * V_100 = V_18 -> V_100 ;
struct V_73 V_87 ;
int V_6 ;
if ( F_3 ( V_100 , V_40 ) ) {
F_11 ( L_27 ) ;
return;
}
memcpy ( & V_87 , V_100 -> V_8 . V_23 , sizeof( struct V_73 ) ) ;
F_54 ( V_43 -> V_14 , & V_87 ) ;
V_6 = F_6 ( V_99 ) ;
if ( F_16 ( V_6 != 0 ) )
F_17 ( L_28 , V_6 ) ;
V_6 = F_3 ( V_100 , V_101 ) ;
if ( F_16 ( V_6 != 0 ) )
F_17 ( L_29 , V_6 ) ;
V_6 = F_3 ( V_99 , V_40 ) ;
if ( F_16 ( V_6 != 0 ) )
F_17 ( L_30 , V_6 ) ;
V_6 = F_6 ( V_100 ) ;
if ( F_16 ( V_6 != 0 ) )
F_17 ( L_31 , V_6 ) ;
}
static int F_56 ( struct V_17 * V_18 )
{
int error ;
error = F_3 ( V_18 -> V_102 , V_70 ) ;
if ( error )
F_11 ( L_32 ,
V_31 , __LINE__ , error ) ;
return error ;
}
static void F_57 ( struct V_17 * V_18 )
{
F_6 ( V_18 -> V_102 ) ;
}
static int F_58 ( struct V_17 * V_18 , struct V_73 * V_74 )
{
int error ;
int V_46 = V_18 -> V_64 - 1 ;
V_74 -> V_46 = F_59 ( V_46 ) ;
error = F_3 ( V_18 -> V_100 , V_70 ) ;
if ( error ) {
F_11 ( L_33 , error ) ;
goto V_103;
}
memcpy ( V_18 -> V_100 -> V_8 . V_23 , ( void * ) V_74 ,
sizeof( struct V_73 ) ) ;
error = F_3 ( V_18 -> V_100 , V_104 ) ;
if ( error ) {
F_11 ( L_34 ,
error ) ;
goto V_105;
}
error = F_3 ( V_18 -> V_99 , V_70 ) ;
if ( error ) {
F_11 ( L_35 ,
error ) ;
goto V_105;
}
error = F_3 ( V_18 -> V_99 , V_40 ) ;
if ( error ) {
F_11 ( L_36 ,
error ) ;
goto V_105;
}
V_105:
error = F_6 ( V_18 -> V_100 ) ;
if ( F_16 ( error != 0 ) ) {
F_11 ( L_37 ,
error ) ;
goto V_105;
}
V_103:
return error ;
}
static int F_60 ( struct V_17 * V_18 , struct V_73 * V_74 )
{
int V_6 ;
F_56 ( V_18 ) ;
V_6 = F_58 ( V_18 , V_74 ) ;
F_57 ( V_18 ) ;
return V_6 ;
}
static int F_61 ( struct V_14 * V_14 , int V_106 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
int V_107 , V_6 = 0 ;
struct V_2 * V_44 ;
struct V_38 * V_39 ;
char V_45 [ 64 ] ;
T_1 V_34 , V_35 ;
for ( V_107 = 0 ; V_107 < V_106 ; V_107 ++ ) {
memset ( V_45 , '\0' , 64 ) ;
snprintf ( V_45 , 64 , L_5 , V_107 ) ;
V_44 = F_7 ( V_14 , V_45 , NULL , 1 ) ;
if ( ! V_44 )
return - V_108 ;
if ( V_107 == ( V_18 -> V_64 - 1 ) )
continue;
V_44 -> V_9 |= V_109 ;
V_6 = F_3 ( V_44 , V_53 ) ;
if ( V_6 == - V_110 ) {
memset ( V_44 -> V_8 . V_23 , '\0' , V_24 ) ;
V_39 = F_20 ( V_14 , V_44 ) ;
if ( V_39 ) {
F_17 ( L_38 ,
V_31 , __LINE__ ,
( unsigned long long ) V_39 -> V_34 ,
( unsigned long long ) V_39 -> V_35 , V_107 ) ;
F_24 ( & V_18 -> V_50 ) ;
V_39 -> V_46 = V_107 ;
F_43 ( & V_39 -> V_51 , & V_18 -> V_72 ) ;
F_27 ( & V_18 -> V_50 ) ;
}
V_6 = 0 ;
F_14 ( V_44 ) ;
continue;
}
if ( V_6 ) {
F_14 ( V_44 ) ;
goto V_41;
}
V_6 = F_28 ( V_14 , V_107 , & V_34 , & V_35 , false ) ;
if ( V_6 ) {
F_34 ( L_39 , V_107 ) ;
F_14 ( V_44 ) ;
continue;
}
if ( ( V_35 > 0 ) && ( V_34 < V_14 -> V_56 ) ) {
F_29 ( V_54 , & V_14 -> V_55 ) ;
V_14 -> V_56 = V_34 ;
F_30 ( V_14 ) ;
}
F_6 ( V_44 ) ;
F_14 ( V_44 ) ;
}
V_41:
return V_6 ;
}
static int F_62 ( struct V_14 * V_14 , int V_111 )
{
struct V_17 * V_18 ;
int V_6 , V_112 ;
char V_45 [ 64 ] ;
V_18 = F_9 ( sizeof( struct V_17 ) , V_20 ) ;
if ( ! V_18 )
return - V_108 ;
F_63 ( & V_18 -> V_72 ) ;
F_64 ( & V_18 -> V_50 ) ;
F_10 ( & V_18 -> V_4 ) ;
F_29 ( V_69 , & V_18 -> V_58 ) ;
F_65 ( & V_18 -> V_113 ) ;
V_14 -> V_19 = V_18 ;
memset ( V_45 , 0 , 64 ) ;
sprintf ( V_45 , L_15 , V_14 -> V_80 ) ;
V_6 = F_66 ( V_45 , V_14 -> V_61 . V_62 ,
V_114 , V_24 ,
& V_115 , V_14 , & V_112 , & V_18 -> V_21 ) ;
if ( V_6 )
goto V_116;
F_5 ( & V_18 -> V_4 ) ;
if ( V_111 < V_18 -> V_64 ) {
F_11 ( L_40 ,
V_18 -> V_64 , V_111 ) ;
V_6 = - V_117 ;
goto V_116;
}
V_6 = - V_108 ;
V_18 -> V_71 = F_33 ( F_55 , V_14 , L_41 ) ;
if ( ! V_18 -> V_71 ) {
F_11 ( L_42 ) ;
goto V_116;
}
V_18 -> V_100 = F_7 ( V_14 , L_43 , NULL , 1 ) ;
if ( ! V_18 -> V_100 )
goto V_116;
V_18 -> V_102 = F_7 ( V_14 , L_44 , NULL , 0 ) ;
if ( ! V_18 -> V_102 )
goto V_116;
V_18 -> V_99 = F_7 ( V_14 , L_45 , F_39 , 0 ) ;
if ( ! V_18 -> V_99 )
goto V_116;
V_18 -> V_88 = F_7 ( V_14 , L_46 , NULL , 0 ) ;
if ( ! V_18 -> V_88 )
goto V_116;
if ( F_3 ( V_18 -> V_99 , V_40 ) )
F_11 ( L_47 ,
V_6 ) ;
if ( F_3 ( V_18 -> V_88 , V_40 ) )
F_11 ( L_48 , V_6 ) ;
F_17 ( L_49 , V_45 , V_18 -> V_64 ) ;
snprintf ( V_45 , 64 , L_5 , V_18 -> V_64 - 1 ) ;
V_18 -> V_118 = F_7 ( V_14 , V_45 , NULL , 1 ) ;
if ( ! V_18 -> V_118 )
goto V_116;
if ( F_3 ( V_18 -> V_118 , V_53 ) ) {
F_11 ( L_50 ) ;
V_6 = - V_119 ;
goto V_116;
}
V_6 = F_61 ( V_14 , V_111 ) ;
if ( V_6 )
goto V_116;
return 0 ;
V_116:
F_14 ( V_18 -> V_100 ) ;
F_14 ( V_18 -> V_102 ) ;
F_14 ( V_18 -> V_99 ) ;
F_14 ( V_18 -> V_88 ) ;
F_14 ( V_18 -> V_118 ) ;
if ( V_18 -> V_21 )
F_67 ( V_18 -> V_21 , 2 ) ;
V_14 -> V_19 = NULL ;
F_13 ( V_18 ) ;
return V_6 ;
}
static int F_68 ( struct V_14 * V_14 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
if ( ! V_18 )
return 0 ;
F_69 ( & V_18 -> V_59 ) ;
F_69 ( & V_18 -> V_71 ) ;
F_14 ( V_18 -> V_100 ) ;
F_14 ( V_18 -> V_102 ) ;
F_14 ( V_18 -> V_99 ) ;
F_14 ( V_18 -> V_88 ) ;
F_14 ( V_18 -> V_118 ) ;
F_67 ( V_18 -> V_21 , 2 ) ;
return 0 ;
}
static int V_64 ( struct V_14 * V_14 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
return V_18 -> V_64 - 1 ;
}
static void F_70 ( struct V_14 * V_14 , T_1 V_34 , T_1 V_35 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
F_18 ( V_14 , V_18 -> V_118 , V_34 , V_35 ) ;
F_3 ( V_18 -> V_118 , V_53 ) ;
}
static int F_71 ( struct V_14 * V_14 )
{
return F_56 ( V_14 -> V_19 ) ;
}
static int F_72 ( struct V_14 * V_14 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
struct V_73 V_74 ;
int V_6 ;
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
V_74 . type = F_59 ( V_92 ) ;
V_6 = F_58 ( V_18 , & V_74 ) ;
F_57 ( V_18 ) ;
return V_6 ;
}
static int F_73 ( struct V_14 * V_14 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
return F_6 ( V_18 -> V_102 ) ;
}
static int F_74 ( struct V_14 * V_14 , enum V_120 type ,
T_1 V_34 , T_1 V_35 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
struct V_73 V_74 ;
int V_46 = V_18 -> V_64 - 1 ;
F_17 ( L_51 , V_31 , __LINE__ ,
( unsigned long long ) V_34 ,
( unsigned long long ) V_35 ) ;
F_70 ( V_14 , V_34 , V_35 ) ;
V_74 . type = F_59 ( type ) ;
V_74 . V_46 = F_59 ( V_46 ) ;
V_74 . V_94 = F_19 ( V_34 ) ;
V_74 . V_95 = F_19 ( V_35 ) ;
return F_60 ( V_18 , & V_74 ) ;
}
static int F_75 ( struct V_14 * V_14 , T_1 V_34 , T_1 V_35 )
{
F_17 ( L_52 , V_31 , __LINE__ ) ;
return F_74 ( V_14 , V_93 , V_34 , V_35 ) ;
}
static void F_76 ( struct V_14 * V_14 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
struct V_73 V_74 ;
int V_46 = V_18 -> V_64 - 1 ;
F_17 ( L_52 , V_31 , __LINE__ ) ;
F_74 ( V_14 , V_93 , 0 , 0 ) ;
if ( F_38 ( V_121 , & V_14 -> V_55 ) ) {
V_74 . type = F_59 ( V_98 ) ;
V_74 . V_46 = F_59 ( V_46 ) ;
F_60 ( V_18 , & V_74 ) ;
}
}
static int F_77 ( struct V_14 * V_14 , int V_122 ,
T_1 V_34 , T_1 V_35 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
int V_6 = 0 ;
struct V_38 * V_39 ;
if ( ( V_122 == V_123 ) &&
F_38 ( V_57 , & V_18 -> V_58 ) )
return 1 ;
F_24 ( & V_18 -> V_50 ) ;
if ( F_78 ( & V_18 -> V_72 ) )
goto V_41;
F_79 (s, &cinfo->suspend_list, list)
if ( V_35 > V_39 -> V_34 && V_34 < V_39 -> V_35 ) {
V_6 = 1 ;
break;
}
V_41:
F_27 ( & V_18 -> V_50 ) ;
return V_6 ;
}
static int F_80 ( struct V_14 * V_14 , struct V_89 * V_90 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
struct V_73 V_74 ;
int V_6 = 0 ;
struct V_124 * V_125 = F_81 ( V_90 -> V_126 ) ;
char * V_80 = V_125 -> V_127 ;
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
V_74 . type = F_59 ( V_96 ) ;
memcpy ( V_74 . V_80 , V_80 , 16 ) ;
V_74 . V_77 = V_90 -> V_128 ;
F_56 ( V_18 ) ;
V_6 = F_58 ( V_18 , & V_74 ) ;
if ( V_6 )
return V_6 ;
V_18 -> V_88 -> V_9 |= V_109 ;
V_6 = F_3 ( V_18 -> V_88 , V_70 ) ;
V_18 -> V_88 -> V_9 &= ~ V_109 ;
if ( V_6 == - V_110 )
V_6 = - V_129 ;
else
F_3 ( V_18 -> V_88 , V_40 ) ;
return V_6 ;
}
static int F_82 ( struct V_14 * V_14 )
{
struct V_73 V_74 ;
struct V_17 * V_18 = V_14 -> V_19 ;
int V_6 ;
F_83 ( V_14 , 1 ) ;
V_74 . type = V_92 ;
V_6 = F_58 ( V_18 , & V_74 ) ;
F_57 ( V_18 ) ;
return V_6 ;
}
static int F_84 ( struct V_14 * V_14 , bool V_130 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
if ( ! F_38 ( V_82 , & V_18 -> V_58 ) ) {
F_34 ( L_53 , F_85 ( V_14 ) ) ;
return - V_119 ;
}
if ( V_130 )
F_6 ( V_18 -> V_88 ) ;
F_2 ( & V_18 -> V_81 ) ;
return 0 ;
}
static int F_86 ( struct V_14 * V_14 , struct V_89 * V_90 )
{
struct V_73 V_74 ;
struct V_17 * V_18 = V_14 -> V_19 ;
V_74 . type = REMOVE ;
V_74 . V_77 = V_90 -> V_128 ;
return F_58 ( V_18 , & V_74 ) ;
}
static int F_87 ( struct V_89 * V_90 )
{
int V_131 , V_116 ;
T_1 V_34 , V_35 ;
struct V_73 V_74 ;
struct V_14 * V_14 = V_90 -> V_14 ;
struct V_17 * V_18 = V_14 -> V_19 ;
V_74 . type = V_97 ;
V_74 . V_77 = V_90 -> V_128 ;
V_116 = F_60 ( V_18 , & V_74 ) ;
if ( V_116 )
goto V_41;
for ( V_131 = 0 ; V_131 < V_14 -> V_61 . V_111 ; V_131 ++ ) {
if ( V_131 == ( V_18 -> V_64 - 1 ) )
continue;
V_116 = F_28 ( V_14 , V_131 , & V_34 , & V_35 , false ) ;
if ( V_116 ) {
F_34 ( L_39 , V_131 ) ;
goto V_41;
}
if ( ( V_35 > 0 ) && ( V_34 < V_14 -> V_56 ) )
V_14 -> V_56 = V_34 ;
}
V_41:
return V_116 ;
}
static int T_3 F_88 ( void )
{
F_34 ( L_54 ) ;
F_17 ( L_55 ) ;
F_89 ( & V_132 , V_133 ) ;
return 0 ;
}
static void F_90 ( void )
{
F_91 () ;
}
