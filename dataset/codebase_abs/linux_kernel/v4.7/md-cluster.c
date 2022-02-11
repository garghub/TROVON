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
if ( V_35 < V_14 -> V_55 )
V_14 -> V_55 = V_35 ;
if ( V_14 -> V_55 != V_56 ) {
F_29 ( V_57 , & V_14 -> V_58 ) ;
F_30 ( V_14 -> V_44 ) ;
}
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
F_29 ( V_59 , & V_18 -> V_60 ) ;
}
static void F_32 ( struct V_14 * V_14 , int V_47 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
F_29 ( V_47 , & V_18 -> V_49 ) ;
if ( ! V_18 -> V_61 ) {
V_18 -> V_61 = F_33 ( F_22 ,
V_14 , L_9 ) ;
if ( ! V_18 -> V_61 ) {
F_34 ( L_10 ) ;
return;
}
}
F_30 ( V_18 -> V_61 ) ;
}
static void F_35 ( void * V_1 , struct V_62 * V_47 )
{
struct V_14 * V_14 = V_1 ;
struct V_17 * V_18 = V_14 -> V_19 ;
F_17 ( L_11 ,
V_14 -> V_63 . V_64 ,
V_47 -> V_65 , V_47 -> V_47 ,
V_18 -> V_66 ) ;
F_32 ( V_14 , V_47 -> V_47 - 1 ) ;
}
static void F_36 ( void * V_1 , struct V_62 * V_67 ,
int V_68 , int V_69 ,
T_2 V_70 )
{
struct V_14 * V_14 = V_1 ;
struct V_17 * V_18 = V_14 -> V_19 ;
V_18 -> V_66 = V_69 ;
if ( F_37 ( V_71 , & V_18 -> V_60 ) ) {
F_2 ( & V_18 -> V_4 ) ;
V_53 ( V_71 , & V_18 -> V_60 ) ;
}
V_53 ( V_59 , & V_18 -> V_60 ) ;
}
static void F_38 ( void * V_1 , int V_5 )
{
struct V_2 * V_3 = V_1 ;
struct V_17 * V_18 = V_3 -> V_14 -> V_19 ;
if ( V_5 == V_72 ) {
if ( F_37 ( V_73 , & V_18 -> V_60 ) )
F_30 ( V_18 -> V_74 ) ;
else
F_29 ( V_75 , & V_18 -> V_60 ) ;
}
}
static void F_39 ( struct V_17 * V_18 , int V_47 )
{
struct V_39 * V_40 , * V_48 ;
F_25 (s, tmp, &cinfo->suspend_list, list)
if ( V_47 == V_40 -> V_47 ) {
F_26 ( & V_40 -> V_52 ) ;
F_13 ( V_40 ) ;
break;
}
}
static void F_40 ( struct V_14 * V_14 , int V_47 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
F_24 ( & V_18 -> V_51 ) ;
F_39 ( V_18 , V_47 ) ;
F_27 ( & V_18 -> V_51 ) ;
V_14 -> V_76 -> V_77 ( V_14 , 2 ) ;
}
static void F_41 ( struct V_14 * V_14 ,
int V_47 , T_1 V_35 , T_1 V_36 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
struct V_39 * V_40 ;
if ( ! V_36 ) {
F_40 ( V_14 , V_47 ) ;
F_29 ( V_57 , & V_14 -> V_58 ) ;
F_30 ( V_14 -> V_44 ) ;
return;
}
F_42 ( V_14 , V_18 -> V_78 ,
V_18 -> V_79 ,
V_35 , V_36 ) ;
V_18 -> V_78 = V_35 ;
V_18 -> V_79 = V_36 ;
V_40 = F_9 ( sizeof( struct V_39 ) , V_20 ) ;
if ( ! V_40 )
return;
V_40 -> V_47 = V_47 ;
V_40 -> V_35 = V_35 ;
V_40 -> V_36 = V_36 ;
V_14 -> V_76 -> V_77 ( V_14 , 1 ) ;
V_14 -> V_76 -> V_77 ( V_14 , 0 ) ;
F_24 ( & V_18 -> V_51 ) ;
F_39 ( V_18 , V_47 ) ;
F_43 ( & V_40 -> V_52 , & V_18 -> V_80 ) ;
F_27 ( & V_18 -> V_51 ) ;
V_14 -> V_76 -> V_77 ( V_14 , 2 ) ;
}
static void F_44 ( struct V_14 * V_14 , struct V_81 * V_82 )
{
char V_83 [ 64 ] ;
struct V_17 * V_18 = V_14 -> V_19 ;
char V_84 [] = L_12 ;
char V_85 [ 16 ] ;
char * V_86 [] = { V_84 , V_83 , V_85 , NULL } ;
int V_87 ;
V_87 = snprintf ( V_83 , 64 , L_13 ) ;
sprintf ( V_83 + V_87 , L_14 , V_82 -> V_88 ) ;
snprintf ( V_85 , 16 , L_15 , F_45 ( V_82 -> V_85 ) ) ;
F_17 ( L_16 , V_32 , __LINE__ , V_83 , V_85 ) ;
F_10 ( & V_18 -> V_89 ) ;
F_29 ( V_90 , & V_18 -> V_60 ) ;
F_46 ( & F_47 ( V_14 -> V_91 ) -> V_92 , V_93 , V_86 ) ;
F_48 ( & V_18 -> V_89 ,
V_94 ) ;
V_53 ( V_90 , & V_18 -> V_60 ) ;
}
static void F_49 ( struct V_14 * V_14 , struct V_81 * V_95 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
V_14 -> V_96 = F_45 ( V_95 -> V_85 ) ;
F_29 ( V_97 , & V_14 -> V_9 ) ;
F_3 ( V_18 -> V_98 , V_41 ) ;
F_30 ( V_14 -> V_44 ) ;
}
static void F_50 ( struct V_14 * V_14 , struct V_81 * V_95 )
{
struct V_99 * V_100 = F_51 ( V_14 ,
F_45 ( V_95 -> V_85 ) ) ;
if ( V_100 ) {
F_29 ( V_101 , & V_100 -> V_9 ) ;
F_29 ( V_57 , & V_14 -> V_58 ) ;
F_30 ( V_14 -> V_44 ) ;
}
else
F_34 ( L_17 ,
V_32 , __LINE__ , F_45 ( V_95 -> V_85 ) ) ;
}
static void F_52 ( struct V_14 * V_14 , struct V_81 * V_95 )
{
struct V_99 * V_100 = F_51 ( V_14 ,
F_45 ( V_95 -> V_85 ) ) ;
if ( V_100 && F_37 ( V_102 , & V_100 -> V_9 ) )
V_53 ( V_102 , & V_100 -> V_9 ) ;
else
F_34 ( L_18 ,
V_32 , __LINE__ , F_45 ( V_95 -> V_85 ) ) ;
}
static int F_53 ( struct V_14 * V_14 , struct V_81 * V_95 )
{
int V_6 = 0 ;
if ( F_54 ( V_14 -> V_19 -> V_66 - 1 == F_45 ( V_95 -> V_47 ) ,
L_19 , F_45 ( V_95 -> V_47 ) ) )
return - 1 ;
switch ( F_45 ( V_95 -> type ) ) {
case V_103 :
F_49 ( V_14 , V_95 ) ;
break;
case V_104 :
F_41 ( V_14 , F_45 ( V_95 -> V_47 ) ,
F_21 ( V_95 -> V_105 ) ,
F_21 ( V_95 -> V_106 ) ) ;
break;
case V_107 :
F_44 ( V_14 , V_95 ) ;
break;
case REMOVE :
F_50 ( V_14 , V_95 ) ;
break;
case V_108 :
F_52 ( V_14 , V_95 ) ;
break;
case V_109 :
F_32 ( V_14 , F_45 ( V_95 -> V_47 ) ) ;
break;
default:
V_6 = - 1 ;
F_34 ( L_20 ,
V_32 , __LINE__ , V_95 -> V_47 ) ;
}
return V_6 ;
}
static void F_55 ( struct V_43 * V_44 )
{
struct V_17 * V_18 = V_44 -> V_14 -> V_19 ;
struct V_2 * V_110 = V_18 -> V_110 ;
struct V_2 * V_111 = V_18 -> V_111 ;
struct V_81 V_95 ;
int V_6 ;
F_56 ( & V_18 -> V_112 ) ;
if ( F_3 ( V_111 , V_41 ) ) {
F_11 ( L_21 ) ;
F_57 ( & V_18 -> V_112 ) ;
return;
}
memcpy ( & V_95 , V_111 -> V_8 . V_24 , sizeof( struct V_81 ) ) ;
V_6 = F_53 ( V_44 -> V_14 , & V_95 ) ;
if ( V_6 )
goto V_42;
V_6 = F_6 ( V_110 ) ;
if ( F_16 ( V_6 != 0 ) )
F_17 ( L_22 , V_6 ) ;
V_6 = F_3 ( V_111 , V_113 ) ;
if ( F_16 ( V_6 != 0 ) )
F_17 ( L_23 , V_6 ) ;
V_6 = F_3 ( V_110 , V_41 ) ;
if ( F_16 ( V_6 != 0 ) )
F_17 ( L_24 , V_6 ) ;
V_42:
V_6 = F_6 ( V_111 ) ;
if ( F_16 ( V_6 != 0 ) )
F_17 ( L_25 , V_6 ) ;
F_57 ( & V_18 -> V_112 ) ;
}
static int F_58 ( struct V_17 * V_18 )
{
int error ;
error = F_3 ( V_18 -> V_114 , V_72 ) ;
if ( error )
F_11 ( L_26 ,
V_32 , __LINE__ , error ) ;
F_56 ( & V_18 -> V_112 ) ;
return error ;
}
static int F_59 ( struct V_17 * V_18 )
{
F_60 ( V_18 -> V_115 ,
! F_61 ( V_116 , & V_18 -> V_60 ) ) ;
return F_58 ( V_18 ) ;
}
static void F_62 ( struct V_17 * V_18 )
{
F_63 ( V_18 -> V_114 -> V_5 != V_72 ) ;
F_57 ( & V_18 -> V_112 ) ;
F_6 ( V_18 -> V_114 ) ;
V_53 ( V_116 , & V_18 -> V_60 ) ;
F_64 ( & V_18 -> V_115 ) ;
}
static int F_65 ( struct V_17 * V_18 , struct V_81 * V_82 )
{
int error ;
int V_47 = V_18 -> V_66 - 1 ;
V_82 -> V_47 = F_66 ( V_47 ) ;
error = F_3 ( V_18 -> V_111 , V_72 ) ;
if ( error ) {
F_11 ( L_27 , error ) ;
goto V_117;
}
memcpy ( V_18 -> V_111 -> V_8 . V_24 , ( void * ) V_82 ,
sizeof( struct V_81 ) ) ;
error = F_3 ( V_18 -> V_111 , V_118 ) ;
if ( error ) {
F_11 ( L_28 ,
error ) ;
goto V_119;
}
error = F_3 ( V_18 -> V_110 , V_72 ) ;
if ( error ) {
F_11 ( L_29 ,
error ) ;
goto V_119;
}
error = F_3 ( V_18 -> V_110 , V_41 ) ;
if ( error ) {
F_11 ( L_30 ,
error ) ;
goto V_119;
}
V_119:
error = F_6 ( V_18 -> V_111 ) ;
if ( F_16 ( error != 0 ) ) {
F_11 ( L_31 ,
error ) ;
goto V_119;
}
V_117:
return error ;
}
static int F_67 ( struct V_17 * V_18 , struct V_81 * V_82 )
{
int V_6 ;
F_59 ( V_18 ) ;
V_6 = F_65 ( V_18 , V_82 ) ;
F_62 ( V_18 ) ;
return V_6 ;
}
static int F_68 ( struct V_14 * V_14 , int V_120 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
int V_121 , V_6 = 0 ;
struct V_2 * V_45 ;
struct V_39 * V_40 ;
char V_46 [ 64 ] ;
T_1 V_35 , V_36 ;
for ( V_121 = 0 ; V_121 < V_120 ; V_121 ++ ) {
memset ( V_46 , '\0' , 64 ) ;
snprintf ( V_46 , 64 , L_5 , V_121 ) ;
V_45 = F_7 ( V_14 , V_46 , NULL , 1 ) ;
if ( ! V_45 )
return - V_122 ;
if ( V_121 == ( V_18 -> V_66 - 1 ) ) {
F_14 ( V_45 ) ;
continue;
}
V_45 -> V_9 |= V_123 ;
V_6 = F_3 ( V_45 , V_54 ) ;
if ( V_6 == - V_124 ) {
memset ( V_45 -> V_8 . V_24 , '\0' , V_25 ) ;
V_40 = F_20 ( V_14 , V_45 ) ;
if ( V_40 ) {
F_17 ( L_32 ,
V_32 , __LINE__ ,
( unsigned long long ) V_40 -> V_35 ,
( unsigned long long ) V_40 -> V_36 , V_121 ) ;
F_24 ( & V_18 -> V_51 ) ;
V_40 -> V_47 = V_121 ;
F_43 ( & V_40 -> V_52 , & V_18 -> V_80 ) ;
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
V_6 = F_28 ( V_14 , V_121 , & V_35 , & V_36 , false ) ;
if ( V_6 ) {
F_34 ( L_33 , V_121 ) ;
F_14 ( V_45 ) ;
continue;
}
if ( ( V_36 > 0 ) && ( V_35 < V_14 -> V_55 ) ) {
F_29 ( V_57 , & V_14 -> V_58 ) ;
V_14 -> V_55 = V_35 ;
F_69 ( V_14 ) ;
}
F_6 ( V_45 ) ;
F_14 ( V_45 ) ;
}
V_42:
return V_6 ;
}
static int F_70 ( struct V_14 * V_14 , int V_125 )
{
struct V_17 * V_18 ;
int V_6 , V_126 ;
char V_46 [ 64 ] ;
V_18 = F_9 ( sizeof( struct V_17 ) , V_20 ) ;
if ( ! V_18 )
return - V_122 ;
F_71 ( & V_18 -> V_80 ) ;
F_72 ( & V_18 -> V_51 ) ;
F_10 ( & V_18 -> V_4 ) ;
F_29 ( V_71 , & V_18 -> V_60 ) ;
F_73 ( & V_18 -> V_115 ) ;
F_74 ( & V_18 -> V_112 ) ;
V_14 -> V_19 = V_18 ;
memset ( V_46 , 0 , 64 ) ;
sprintf ( V_46 , L_14 , V_14 -> V_88 ) ;
V_6 = F_75 ( V_46 , V_14 -> V_63 . V_64 ,
V_127 , V_25 ,
& V_128 , V_14 , & V_126 , & V_18 -> V_21 ) ;
if ( V_6 )
goto V_129;
F_5 ( & V_18 -> V_4 ) ;
if ( V_125 < V_18 -> V_66 ) {
F_11 ( L_34 ,
V_18 -> V_66 , V_125 ) ;
V_6 = - V_130 ;
goto V_129;
}
V_6 = - V_122 ;
V_18 -> V_74 = F_33 ( F_55 , V_14 , L_35 ) ;
if ( ! V_18 -> V_74 ) {
F_11 ( L_36 ) ;
goto V_129;
}
V_18 -> V_111 = F_7 ( V_14 , L_37 , NULL , 1 ) ;
if ( ! V_18 -> V_111 )
goto V_129;
V_18 -> V_114 = F_7 ( V_14 , L_38 , NULL , 0 ) ;
if ( ! V_18 -> V_114 )
goto V_129;
V_18 -> V_98 = F_7 ( V_14 , L_39 , NULL , 0 ) ;
if ( ! V_18 -> V_98 )
goto V_129;
V_6 = F_3 ( V_18 -> V_114 , V_72 ) ;
if ( V_6 ) {
V_6 = - V_124 ;
F_11 ( L_40 ) ;
goto V_129;
}
V_18 -> V_110 = F_7 ( V_14 , L_41 , F_38 , 0 ) ;
if ( ! V_18 -> V_110 )
goto V_129;
if ( F_3 ( V_18 -> V_110 , V_41 ) )
F_11 ( L_42 ,
V_6 ) ;
F_6 ( V_18 -> V_114 ) ;
if ( F_3 ( V_18 -> V_98 , V_41 ) )
F_11 ( L_43 , V_6 ) ;
F_17 ( L_44 , V_46 , V_18 -> V_66 ) ;
snprintf ( V_46 , 64 , L_5 , V_18 -> V_66 - 1 ) ;
V_18 -> V_131 = F_7 ( V_14 , V_46 , NULL , 1 ) ;
if ( ! V_18 -> V_131 )
goto V_129;
if ( F_3 ( V_18 -> V_131 , V_54 ) ) {
F_11 ( L_45 ) ;
V_6 = - V_132 ;
goto V_129;
}
V_18 -> V_133 = F_7 ( V_14 , L_46 , NULL , 0 ) ;
if ( ! V_18 -> V_133 )
goto V_129;
return 0 ;
V_129:
F_76 ( & V_18 -> V_61 ) ;
F_76 ( & V_18 -> V_74 ) ;
F_14 ( V_18 -> V_111 ) ;
F_14 ( V_18 -> V_114 ) ;
F_14 ( V_18 -> V_110 ) ;
F_14 ( V_18 -> V_98 ) ;
F_14 ( V_18 -> V_133 ) ;
F_14 ( V_18 -> V_131 ) ;
if ( V_18 -> V_21 )
F_77 ( V_18 -> V_21 , 2 ) ;
V_14 -> V_19 = NULL ;
F_13 ( V_18 ) ;
return V_6 ;
}
static void F_78 ( struct V_14 * V_14 , int V_120 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
if ( F_68 ( V_14 , V_120 ) )
F_11 ( L_47 ) ;
F_29 ( V_73 , & V_18 -> V_60 ) ;
if ( F_79 ( V_75 , & V_18 -> V_60 ) )
F_30 ( V_18 -> V_74 ) ;
}
static void F_80 ( struct V_14 * V_14 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
struct V_81 V_82 = { 0 } ;
int V_129 ;
V_82 . type = F_66 ( V_109 ) ;
V_129 = F_67 ( V_18 , & V_82 ) ;
if ( V_129 )
F_11 ( L_48 ,
V_32 , __LINE__ , V_129 ) ;
}
static int F_81 ( struct V_14 * V_14 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
if ( ! V_18 )
return 0 ;
if ( V_18 -> V_66 > 0 && V_14 -> V_55 != V_56 )
F_80 ( V_14 ) ;
F_76 ( & V_18 -> V_61 ) ;
F_76 ( & V_18 -> V_74 ) ;
F_14 ( V_18 -> V_111 ) ;
F_14 ( V_18 -> V_114 ) ;
F_14 ( V_18 -> V_110 ) ;
F_14 ( V_18 -> V_98 ) ;
F_14 ( V_18 -> V_133 ) ;
F_14 ( V_18 -> V_131 ) ;
F_82 ( V_14 ) ;
F_77 ( V_18 -> V_21 , 2 ) ;
return 0 ;
}
static int V_66 ( struct V_14 * V_14 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
return V_18 -> V_66 - 1 ;
}
static int F_83 ( struct V_14 * V_14 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
F_60 ( V_18 -> V_115 ,
! F_61 ( V_116 , & V_18 -> V_60 ) ||
F_79 ( V_134 , & V_18 -> V_60 ) ) ;
if ( V_18 -> V_114 -> V_5 == V_72 )
return 0 ;
return F_58 ( V_18 ) ;
}
static int F_84 ( struct V_14 * V_14 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
struct V_81 V_82 ;
struct V_99 * V_100 ;
int V_6 = 0 ;
int V_85 = - 1 ;
memset ( & V_82 , 0 , sizeof( V_82 ) ) ;
V_82 . type = F_66 ( V_103 ) ;
F_85 (rdev, mddev)
if ( V_100 -> V_135 > - 1 && ! F_37 ( V_102 , & V_100 -> V_9 ) ) {
V_85 = V_100 -> V_136 ;
break;
}
if ( V_85 >= 0 ) {
V_82 . V_85 = F_66 ( V_85 ) ;
V_6 = F_65 ( V_18 , & V_82 ) ;
} else
F_34 ( L_49 ) ;
V_53 ( V_134 , & V_18 -> V_60 ) ;
F_62 ( V_18 ) ;
return V_6 ;
}
static void F_86 ( struct V_14 * V_14 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
V_53 ( V_134 , & V_18 -> V_60 ) ;
F_62 ( V_18 ) ;
}
static int F_87 ( struct V_14 * V_14 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
return F_3 ( V_18 -> V_133 , V_72 ) ;
}
static int F_88 ( struct V_14 * V_14 , T_1 V_35 , T_1 V_36 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
struct V_37 V_38 ;
struct V_81 V_82 = { 0 } ;
if ( V_36 == 0 ) {
memcpy ( & V_38 , V_18 -> V_131 -> V_8 . V_24 , sizeof( struct V_37 ) ) ;
if ( F_21 ( V_38 . V_36 ) == 0 )
return 0 ;
}
F_18 ( V_18 -> V_131 , V_35 , V_36 ) ;
F_3 ( V_18 -> V_131 , V_54 ) ;
V_82 . type = F_66 ( V_104 ) ;
V_82 . V_105 = F_19 ( V_35 ) ;
V_82 . V_106 = F_19 ( V_36 ) ;
return F_67 ( V_18 , & V_82 ) ;
}
static int F_89 ( struct V_14 * V_14 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
F_6 ( V_18 -> V_133 ) ;
return F_88 ( V_14 , 0 , 0 ) ;
}
static int F_90 ( struct V_14 * V_14 , int V_137 ,
T_1 V_35 , T_1 V_36 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
int V_6 = 0 ;
struct V_39 * V_40 ;
if ( ( V_137 == V_138 ) &&
F_37 ( V_59 , & V_18 -> V_60 ) )
return 1 ;
F_24 ( & V_18 -> V_51 ) ;
if ( F_91 ( & V_18 -> V_80 ) )
goto V_42;
F_92 (s, &cinfo->suspend_list, list)
if ( V_36 > V_40 -> V_35 && V_35 < V_40 -> V_36 ) {
V_6 = 1 ;
break;
}
V_42:
F_27 ( & V_18 -> V_51 ) ;
return V_6 ;
}
static int F_93 ( struct V_14 * V_14 , struct V_99 * V_100 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
struct V_81 V_82 ;
int V_6 = 0 ;
struct V_139 * V_140 = F_94 ( V_100 -> V_141 ) ;
char * V_88 = V_140 -> V_142 ;
memset ( & V_82 , 0 , sizeof( V_82 ) ) ;
V_82 . type = F_66 ( V_107 ) ;
memcpy ( V_82 . V_88 , V_88 , 16 ) ;
V_82 . V_85 = F_66 ( V_100 -> V_136 ) ;
F_59 ( V_18 ) ;
V_6 = F_65 ( V_18 , & V_82 ) ;
if ( V_6 )
return V_6 ;
V_18 -> V_98 -> V_9 |= V_123 ;
V_6 = F_3 ( V_18 -> V_98 , V_72 ) ;
V_18 -> V_98 -> V_9 &= ~ V_123 ;
if ( V_6 == - V_124 )
V_6 = - V_143 ;
if ( V_6 )
F_62 ( V_18 ) ;
else {
F_3 ( V_18 -> V_98 , V_41 ) ;
F_29 ( V_134 , & V_18 -> V_60 ) ;
F_64 ( & V_18 -> V_115 ) ;
}
return V_6 ;
}
static void F_95 ( struct V_14 * V_14 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
V_53 ( V_134 , & V_18 -> V_60 ) ;
F_62 ( V_18 ) ;
}
static int F_96 ( struct V_14 * V_14 , bool V_144 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
if ( ! F_37 ( V_90 , & V_18 -> V_60 ) ) {
F_34 ( L_50 , F_97 ( V_14 ) ) ;
return - V_132 ;
}
if ( V_144 )
F_6 ( V_18 -> V_98 ) ;
F_2 ( & V_18 -> V_89 ) ;
return 0 ;
}
static int F_98 ( struct V_14 * V_14 , struct V_99 * V_100 )
{
struct V_81 V_82 = { 0 } ;
struct V_17 * V_18 = V_14 -> V_19 ;
V_82 . type = F_66 ( REMOVE ) ;
V_82 . V_85 = F_66 ( V_100 -> V_136 ) ;
return F_67 ( V_18 , & V_82 ) ;
}
static int F_99 ( struct V_14 * V_14 )
{
int V_47 , V_145 , V_6 , V_146 = 1 , V_121 = 0 ;
char V_46 [ 64 ] ;
struct V_17 * V_18 = V_14 -> V_19 ;
V_18 -> V_147 = F_9 ( ( V_14 -> V_63 . V_125 - 1 ) *
sizeof( struct V_2 * ) ,
V_20 ) ;
if ( ! V_18 -> V_147 ) {
F_11 ( L_51 ) ;
return 0 ;
}
V_145 = V_66 ( V_14 ) ;
for ( V_47 = 0 ; V_47 < V_14 -> V_63 . V_125 ; V_47 ++ ) {
if ( V_47 == V_145 )
continue;
memset ( V_46 , '\0' , 64 ) ;
snprintf ( V_46 , 64 , L_5 , V_47 ) ;
V_18 -> V_147 [ V_121 ] = F_7 ( V_14 , V_46 , NULL , 1 ) ;
if ( ! V_18 -> V_147 [ V_121 ] )
return - V_122 ;
V_18 -> V_147 [ V_121 ] -> V_9 |= V_123 ;
V_6 = F_3 ( V_18 -> V_147 [ V_121 ] , V_54 ) ;
if ( V_6 )
V_146 = - 1 ;
V_121 ++ ;
}
return V_146 ;
}
static void F_82 ( struct V_14 * V_14 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
int V_121 ;
if ( V_18 -> V_147 ) {
for ( V_121 = 0 ; V_121 < V_14 -> V_63 . V_125 - 1 ; V_121 ++ ) {
if ( V_18 -> V_147 [ V_121 ] ) {
F_6 ( V_18 -> V_147 [ V_121 ] ) ;
F_14 ( V_18 -> V_147 [ V_121 ] ) ;
}
}
F_13 ( V_18 -> V_147 ) ;
}
}
static int F_100 ( struct V_99 * V_100 )
{
int V_148 , V_129 ;
T_1 V_35 , V_36 ;
struct V_81 V_82 = { 0 } ;
struct V_14 * V_14 = V_100 -> V_14 ;
struct V_17 * V_18 = V_14 -> V_19 ;
V_82 . type = F_66 ( V_108 ) ;
V_82 . V_85 = F_66 ( V_100 -> V_136 ) ;
V_129 = F_67 ( V_18 , & V_82 ) ;
if ( V_129 )
goto V_42;
for ( V_148 = 0 ; V_148 < V_14 -> V_63 . V_125 ; V_148 ++ ) {
if ( V_148 == ( V_18 -> V_66 - 1 ) )
continue;
V_129 = F_28 ( V_14 , V_148 , & V_35 , & V_36 , false ) ;
if ( V_129 ) {
F_34 ( L_33 , V_148 ) ;
goto V_42;
}
if ( ( V_36 > 0 ) && ( V_35 < V_14 -> V_55 ) )
V_14 -> V_55 = V_35 ;
}
V_42:
return V_129 ;
}
static int T_3 F_101 ( void )
{
F_34 ( L_52 ) ;
F_17 ( L_53 ) ;
F_102 ( & V_149 , V_150 ) ;
return 0 ;
}
static void F_103 ( void )
{
F_104 () ;
}
