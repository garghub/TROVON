static void F_1 ( void * V_1 )
{
struct V_2 * V_3 ;
V_3 = V_1 ;
V_3 -> V_4 = true ;
F_2 ( & V_3 -> V_5 ) ;
}
static int F_3 ( struct V_2 * V_3 , int V_6 )
{
int V_7 = 0 ;
V_7 = F_4 ( V_3 -> V_8 , V_6 , & V_3 -> V_9 ,
V_3 -> V_10 , V_3 -> V_11 , strlen ( V_3 -> V_11 ) ,
0 , F_1 , V_3 , V_3 -> V_12 ) ;
if ( V_7 )
return V_7 ;
F_5 ( V_3 -> V_5 , V_3 -> V_4 ) ;
V_3 -> V_4 = false ;
if ( V_3 -> V_9 . V_13 == 0 )
V_3 -> V_6 = V_6 ;
return V_3 -> V_9 . V_13 ;
}
static int F_6 ( struct V_2 * V_3 )
{
return F_3 ( V_3 , V_14 ) ;
}
static int F_7 ( struct V_2 * V_3 , int V_6 ,
struct V_15 * V_15 )
{
int V_7 = 0 ;
V_7 = F_4 ( V_3 -> V_8 , V_6 , & V_3 -> V_9 ,
V_3 -> V_10 , V_3 -> V_11 , strlen ( V_3 -> V_11 ) ,
0 , F_1 , V_3 , V_3 -> V_12 ) ;
if ( V_7 )
return V_7 ;
F_5 ( V_3 -> V_5 , V_3 -> V_4
|| F_8 ()
|| F_9 ( V_16 , & V_15 -> V_10 ) ) ;
if ( ! V_3 -> V_4 ) {
V_7 = F_10 ( V_3 -> V_8 , V_3 -> V_9 . V_17 , V_18 ,
& V_3 -> V_9 , V_3 ) ;
V_3 -> V_4 = false ;
if ( F_11 ( V_7 != 0 ) )
F_12 ( L_1
L_2 , V_3 -> V_11 , V_7 ) ;
return - V_19 ;
} else
V_3 -> V_4 = false ;
if ( V_3 -> V_9 . V_13 == 0 )
V_3 -> V_6 = V_6 ;
return V_3 -> V_9 . V_13 ;
}
static struct V_2 * F_13 ( struct V_15 * V_15 ,
char * V_11 , void (* F_14)( void * V_1 , int V_6 ) , int V_20 )
{
struct V_2 * V_3 = NULL ;
int V_7 , V_21 ;
struct V_22 * V_23 = V_15 -> V_24 ;
V_3 = F_15 ( sizeof( struct V_2 ) , V_25 ) ;
if ( ! V_3 )
return NULL ;
F_16 ( & V_3 -> V_5 ) ;
V_3 -> V_4 = false ;
V_3 -> V_8 = V_23 -> V_26 ;
V_3 -> V_15 = V_15 ;
V_3 -> V_6 = V_27 ;
V_21 = strlen ( V_11 ) ;
V_3 -> V_11 = F_15 ( V_21 + 1 , V_25 ) ;
if ( ! V_3 -> V_11 ) {
F_17 ( L_3 , V_11 ) ;
goto V_28;
}
F_18 ( V_3 -> V_11 , V_11 , V_21 + 1 ) ;
if ( V_20 ) {
V_3 -> V_9 . V_29 = F_15 ( V_30 , V_25 ) ;
if ( ! V_3 -> V_9 . V_29 ) {
F_17 ( L_4 , V_11 ) ;
goto V_28;
}
V_3 -> V_10 = V_31 ;
}
if ( F_14 )
V_3 -> V_12 = F_14 ;
V_3 -> V_10 |= V_32 ;
V_7 = F_3 ( V_3 , V_14 ) ;
if ( V_7 ) {
F_17 ( L_5 , V_11 ) ;
goto V_28;
}
V_3 -> V_10 &= ~ V_32 ;
V_3 -> V_10 |= V_33 ;
return V_3 ;
V_28:
F_19 ( V_3 -> V_9 . V_29 ) ;
F_19 ( V_3 -> V_11 ) ;
F_19 ( V_3 ) ;
return NULL ;
}
static void F_20 ( struct V_2 * V_3 )
{
int V_7 = 0 ;
if ( ! V_3 )
return;
V_7 = F_10 ( V_3 -> V_8 , V_3 -> V_9 . V_17 , V_34 ,
& V_3 -> V_9 , V_3 ) ;
if ( F_11 ( V_7 != 0 ) )
F_17 ( L_6 , V_3 -> V_11 , V_7 ) ;
else
F_5 ( V_3 -> V_5 , V_3 -> V_4 ) ;
F_19 ( V_3 -> V_11 ) ;
F_19 ( V_3 -> V_9 . V_29 ) ;
F_19 ( V_3 ) ;
}
static void F_21 ( struct V_2 * V_35 ,
T_1 V_36 , T_1 V_37 )
{
struct V_38 * V_39 ;
V_39 = (struct V_38 * ) V_35 -> V_9 . V_29 ;
V_39 -> V_36 = F_22 ( V_36 ) ;
V_39 -> V_37 = F_22 ( V_37 ) ;
}
static struct V_40 * F_23 ( struct V_15 * V_15 , struct V_2 * V_35 )
{
struct V_38 V_39 ;
struct V_40 * V_41 = NULL ;
T_1 V_37 = 0 ;
F_3 ( V_35 , V_42 ) ;
memcpy ( & V_39 , V_35 -> V_9 . V_29 , sizeof( struct V_38 ) ) ;
V_37 = F_24 ( V_39 . V_37 ) ;
if ( V_37 > 0 ) {
V_41 = F_15 ( sizeof( struct V_40 ) , V_25 ) ;
if ( ! V_41 )
goto V_43;
V_41 -> V_37 = V_37 ;
V_41 -> V_36 = F_24 ( V_39 . V_36 ) ;
}
F_6 ( V_35 ) ;
V_43:
return V_41 ;
}
static void F_25 ( struct V_44 * V_45 )
{
struct V_15 * V_15 = V_45 -> V_15 ;
struct V_22 * V_23 = V_15 -> V_24 ;
struct V_2 * V_46 ;
char V_47 [ 64 ] ;
int V_48 , V_7 ;
struct V_40 * V_41 , * V_49 ;
T_1 V_36 , V_37 ;
while ( V_23 -> V_50 ) {
V_48 = F_26 ( ( V_51 ) V_23 -> V_50 ) - 1 ;
F_27 ( & V_23 -> V_52 ) ;
F_28 (s, tmp, &cinfo->suspend_list, list)
if ( V_48 == V_41 -> V_48 ) {
F_29 ( & V_41 -> V_53 ) ;
F_19 ( V_41 ) ;
}
F_30 ( & V_23 -> V_52 ) ;
snprintf ( V_47 , 64 , L_7 , V_48 ) ;
V_46 = F_13 ( V_15 , V_47 , NULL , 1 ) ;
if ( ! V_46 ) {
F_17 ( L_8 ) ;
goto V_54;
}
V_7 = F_7 ( V_46 , V_55 , V_15 ) ;
if ( V_7 ) {
F_17 ( L_9 ,
V_47 , V_7 ) ;
goto V_54;
}
V_7 = F_31 ( V_15 , V_48 , & V_36 , & V_37 , true ) ;
if ( V_7 ) {
F_17 ( L_10 , V_48 ) ;
goto V_54;
}
if ( V_37 > 0 ) {
if ( V_36 < V_15 -> V_56 )
V_15 -> V_56 = V_36 ;
if ( V_15 -> V_56 != V_57 ) {
F_32 ( V_58 , & V_15 -> V_59 ) ;
F_33 ( V_15 -> V_45 ) ;
}
}
V_54:
F_20 ( V_46 ) ;
V_54 ( V_48 , & V_23 -> V_50 ) ;
}
}
static void F_34 ( void * V_1 )
{
struct V_15 * V_15 = V_1 ;
struct V_22 * V_23 = V_15 -> V_24 ;
F_32 ( V_60 , & V_23 -> V_61 ) ;
}
static void F_35 ( struct V_15 * V_15 , int V_48 )
{
struct V_22 * V_23 = V_15 -> V_24 ;
F_32 ( V_48 , & V_23 -> V_50 ) ;
if ( ! V_23 -> V_62 ) {
V_23 -> V_62 = F_36 ( F_25 ,
V_15 , L_11 ) ;
if ( ! V_23 -> V_62 ) {
F_37 ( L_12 ) ;
return;
}
}
F_33 ( V_23 -> V_62 ) ;
}
static void F_38 ( void * V_1 , struct V_63 * V_48 )
{
struct V_15 * V_15 = V_1 ;
struct V_22 * V_23 = V_15 -> V_24 ;
F_12 ( L_13 ,
V_15 -> V_64 . V_65 ,
V_48 -> V_66 , V_48 -> V_48 ,
V_23 -> V_67 ) ;
F_35 ( V_15 , V_48 -> V_48 - 1 ) ;
}
static void F_39 ( void * V_1 , struct V_63 * V_68 ,
int V_69 , int V_70 ,
T_2 V_71 )
{
struct V_15 * V_15 = V_1 ;
struct V_22 * V_23 = V_15 -> V_24 ;
V_23 -> V_67 = V_70 ;
if ( F_9 ( V_72 , & V_23 -> V_61 ) ) {
F_40 ( & V_23 -> V_73 ) ;
V_54 ( V_72 , & V_23 -> V_61 ) ;
}
V_54 ( V_60 , & V_23 -> V_61 ) ;
}
static void F_41 ( void * V_1 , int V_6 )
{
struct V_2 * V_3 = V_1 ;
struct V_22 * V_23 = V_3 -> V_15 -> V_24 ;
if ( V_6 == V_74 ) {
if ( F_9 ( V_75 , & V_23 -> V_61 ) )
F_33 ( V_23 -> V_76 ) ;
else
F_32 ( V_77 , & V_23 -> V_61 ) ;
}
}
static void F_42 ( struct V_22 * V_23 , int V_48 )
{
struct V_40 * V_41 , * V_49 ;
F_28 (s, tmp, &cinfo->suspend_list, list)
if ( V_48 == V_41 -> V_48 ) {
F_29 ( & V_41 -> V_53 ) ;
F_19 ( V_41 ) ;
break;
}
}
static void F_43 ( struct V_15 * V_15 , int V_48 )
{
struct V_22 * V_23 = V_15 -> V_24 ;
F_27 ( & V_23 -> V_52 ) ;
F_42 ( V_23 , V_48 ) ;
F_30 ( & V_23 -> V_52 ) ;
V_15 -> V_78 -> V_79 ( V_15 , 2 ) ;
}
static void F_44 ( struct V_15 * V_15 ,
int V_48 , T_1 V_36 , T_1 V_37 )
{
struct V_22 * V_23 = V_15 -> V_24 ;
struct V_40 * V_41 ;
if ( ! V_37 ) {
F_43 ( V_15 , V_48 ) ;
F_32 ( V_58 , & V_15 -> V_59 ) ;
F_33 ( V_15 -> V_45 ) ;
return;
}
F_45 ( V_15 , V_23 -> V_80 ,
V_23 -> V_81 ,
V_36 , V_37 ) ;
V_23 -> V_80 = V_36 ;
V_23 -> V_81 = V_37 ;
V_41 = F_15 ( sizeof( struct V_40 ) , V_25 ) ;
if ( ! V_41 )
return;
V_41 -> V_48 = V_48 ;
V_41 -> V_36 = V_36 ;
V_41 -> V_37 = V_37 ;
V_15 -> V_78 -> V_79 ( V_15 , 1 ) ;
V_15 -> V_78 -> V_79 ( V_15 , 0 ) ;
F_27 ( & V_23 -> V_52 ) ;
F_42 ( V_23 , V_48 ) ;
F_46 ( & V_41 -> V_53 , & V_23 -> V_82 ) ;
F_30 ( & V_23 -> V_52 ) ;
V_15 -> V_78 -> V_79 ( V_15 , 2 ) ;
}
static void F_47 ( struct V_15 * V_15 , struct V_83 * V_84 )
{
char V_85 [ 64 ] ;
struct V_22 * V_23 = V_15 -> V_24 ;
char V_86 [] = L_14 ;
char V_87 [ 16 ] ;
char * V_88 [] = { V_86 , V_85 , V_87 , NULL } ;
int V_89 ;
V_89 = snprintf ( V_85 , 64 , L_15 ) ;
sprintf ( V_85 + V_89 , L_16 , V_84 -> V_90 ) ;
snprintf ( V_87 , 16 , L_17 , F_48 ( V_84 -> V_87 ) ) ;
F_12 ( L_18 , V_91 , __LINE__ , V_85 , V_87 ) ;
F_49 ( & V_23 -> V_92 ) ;
F_32 ( V_93 , & V_23 -> V_61 ) ;
F_50 ( & F_51 ( V_15 -> V_94 ) -> V_95 , V_96 , V_88 ) ;
F_52 ( & V_23 -> V_92 ,
V_97 ) ;
V_54 ( V_93 , & V_23 -> V_61 ) ;
}
static void F_53 ( struct V_15 * V_15 , struct V_83 * V_98 )
{
struct V_22 * V_23 = V_15 -> V_24 ;
V_15 -> V_99 = F_48 ( V_98 -> V_87 ) ;
F_32 ( V_100 , & V_15 -> V_10 ) ;
F_3 ( V_23 -> V_101 , V_42 ) ;
F_33 ( V_15 -> V_45 ) ;
}
static void F_54 ( struct V_15 * V_15 , struct V_83 * V_98 )
{
struct V_102 * V_103 ;
F_55 () ;
V_103 = F_56 ( V_15 , F_48 ( V_98 -> V_87 ) ) ;
if ( V_103 ) {
F_32 ( V_104 , & V_103 -> V_10 ) ;
F_32 ( V_58 , & V_15 -> V_59 ) ;
F_33 ( V_15 -> V_45 ) ;
}
else
F_37 ( L_19 ,
V_91 , __LINE__ , F_48 ( V_98 -> V_87 ) ) ;
F_57 () ;
}
static void F_58 ( struct V_15 * V_15 , struct V_83 * V_98 )
{
struct V_102 * V_103 ;
F_55 () ;
V_103 = F_56 ( V_15 , F_48 ( V_98 -> V_87 ) ) ;
if ( V_103 && F_9 ( V_105 , & V_103 -> V_10 ) )
V_54 ( V_105 , & V_103 -> V_10 ) ;
else
F_37 ( L_20 ,
V_91 , __LINE__ , F_48 ( V_98 -> V_87 ) ) ;
F_57 () ;
}
static int F_59 ( struct V_15 * V_15 , struct V_83 * V_98 )
{
int V_7 = 0 ;
if ( F_60 ( V_15 -> V_24 -> V_67 - 1 == F_48 ( V_98 -> V_48 ) ,
L_21 , F_48 ( V_98 -> V_48 ) ) )
return - 1 ;
switch ( F_48 ( V_98 -> type ) ) {
case V_106 :
F_53 ( V_15 , V_98 ) ;
break;
case V_107 :
F_44 ( V_15 , F_48 ( V_98 -> V_48 ) ,
F_24 ( V_98 -> V_108 ) ,
F_24 ( V_98 -> V_109 ) ) ;
break;
case V_110 :
F_47 ( V_15 , V_98 ) ;
break;
case REMOVE :
F_54 ( V_15 , V_98 ) ;
break;
case V_111 :
F_58 ( V_15 , V_98 ) ;
break;
case V_112 :
F_35 ( V_15 , F_48 ( V_98 -> V_48 ) ) ;
break;
default:
V_7 = - 1 ;
F_37 ( L_22 ,
V_91 , __LINE__ , V_98 -> V_48 ) ;
}
return V_7 ;
}
static void F_61 ( struct V_44 * V_45 )
{
struct V_22 * V_23 = V_45 -> V_15 -> V_24 ;
struct V_2 * V_113 = V_23 -> V_113 ;
struct V_2 * V_114 = V_23 -> V_114 ;
struct V_83 V_98 ;
int V_7 ;
F_62 ( & V_23 -> V_115 ) ;
if ( F_3 ( V_114 , V_42 ) ) {
F_17 ( L_23 ) ;
F_63 ( & V_23 -> V_115 ) ;
return;
}
memcpy ( & V_98 , V_114 -> V_9 . V_29 , sizeof( struct V_83 ) ) ;
V_7 = F_59 ( V_45 -> V_15 , & V_98 ) ;
if ( V_7 )
goto V_43;
V_7 = F_6 ( V_113 ) ;
if ( F_11 ( V_7 != 0 ) )
F_12 ( L_24 , V_7 ) ;
V_7 = F_3 ( V_114 , V_116 ) ;
if ( F_11 ( V_7 != 0 ) )
F_12 ( L_25 , V_7 ) ;
V_7 = F_3 ( V_113 , V_42 ) ;
if ( F_11 ( V_7 != 0 ) )
F_12 ( L_26 , V_7 ) ;
V_43:
V_7 = F_6 ( V_114 ) ;
if ( F_11 ( V_7 != 0 ) )
F_12 ( L_27 , V_7 ) ;
F_63 ( & V_23 -> V_115 ) ;
}
static int F_64 ( struct V_22 * V_23 )
{
int error ;
error = F_3 ( V_23 -> V_117 , V_74 ) ;
if ( error )
F_17 ( L_28 ,
V_91 , __LINE__ , error ) ;
F_62 ( & V_23 -> V_115 ) ;
return error ;
}
static int F_65 ( struct V_22 * V_23 )
{
F_5 ( V_23 -> V_118 ,
! F_66 ( V_119 , & V_23 -> V_61 ) ) ;
return F_64 ( V_23 ) ;
}
static void F_67 ( struct V_22 * V_23 )
{
F_68 ( V_23 -> V_117 -> V_6 != V_74 ) ;
F_63 ( & V_23 -> V_115 ) ;
F_6 ( V_23 -> V_117 ) ;
V_54 ( V_119 , & V_23 -> V_61 ) ;
F_2 ( & V_23 -> V_118 ) ;
}
static int F_69 ( struct V_22 * V_23 , struct V_83 * V_84 )
{
int error ;
int V_48 = V_23 -> V_67 - 1 ;
V_84 -> V_48 = F_70 ( V_48 ) ;
error = F_3 ( V_23 -> V_114 , V_74 ) ;
if ( error ) {
F_17 ( L_29 , error ) ;
goto V_120;
}
memcpy ( V_23 -> V_114 -> V_9 . V_29 , ( void * ) V_84 ,
sizeof( struct V_83 ) ) ;
error = F_3 ( V_23 -> V_114 , V_121 ) ;
if ( error ) {
F_17 ( L_30 ,
error ) ;
goto V_122;
}
error = F_3 ( V_23 -> V_113 , V_74 ) ;
if ( error ) {
F_17 ( L_31 ,
error ) ;
goto V_122;
}
error = F_3 ( V_23 -> V_113 , V_42 ) ;
if ( error ) {
F_17 ( L_32 ,
error ) ;
goto V_122;
}
V_122:
error = F_6 ( V_23 -> V_114 ) ;
if ( F_11 ( error != 0 ) ) {
F_17 ( L_33 ,
error ) ;
goto V_122;
}
V_120:
return error ;
}
static int F_71 ( struct V_22 * V_23 , struct V_83 * V_84 )
{
int V_7 ;
F_65 ( V_23 ) ;
V_7 = F_69 ( V_23 , V_84 ) ;
F_67 ( V_23 ) ;
return V_7 ;
}
static int F_72 ( struct V_15 * V_15 , int V_123 )
{
struct V_22 * V_23 = V_15 -> V_24 ;
int V_124 , V_7 = 0 ;
struct V_2 * V_46 ;
struct V_40 * V_41 ;
char V_47 [ 64 ] ;
T_1 V_36 , V_37 ;
for ( V_124 = 0 ; V_124 < V_123 ; V_124 ++ ) {
memset ( V_47 , '\0' , 64 ) ;
snprintf ( V_47 , 64 , L_7 , V_124 ) ;
V_46 = F_13 ( V_15 , V_47 , NULL , 1 ) ;
if ( ! V_46 )
return - V_125 ;
if ( V_124 == ( V_23 -> V_67 - 1 ) ) {
F_20 ( V_46 ) ;
continue;
}
V_46 -> V_10 |= V_126 ;
V_7 = F_3 ( V_46 , V_55 ) ;
if ( V_7 == - V_127 ) {
V_41 = F_23 ( V_15 , V_46 ) ;
if ( V_41 ) {
F_12 ( L_34 ,
V_91 , __LINE__ ,
( unsigned long long ) V_41 -> V_36 ,
( unsigned long long ) V_41 -> V_37 , V_124 ) ;
F_27 ( & V_23 -> V_52 ) ;
V_41 -> V_48 = V_124 ;
F_46 ( & V_41 -> V_53 , & V_23 -> V_82 ) ;
F_30 ( & V_23 -> V_52 ) ;
}
V_7 = 0 ;
F_20 ( V_46 ) ;
continue;
}
if ( V_7 ) {
F_20 ( V_46 ) ;
goto V_43;
}
V_7 = F_31 ( V_15 , V_124 , & V_36 , & V_37 , false ) ;
if ( V_7 ) {
F_37 ( L_35 , V_124 ) ;
F_20 ( V_46 ) ;
continue;
}
if ( ( V_37 > 0 ) && ( V_36 < V_15 -> V_56 ) ) {
F_32 ( V_58 , & V_15 -> V_59 ) ;
V_15 -> V_56 = V_36 ;
F_73 ( V_15 ) ;
}
F_20 ( V_46 ) ;
}
V_43:
return V_7 ;
}
static int F_74 ( struct V_15 * V_15 , int V_128 )
{
struct V_22 * V_23 ;
int V_7 , V_129 ;
char V_47 [ 64 ] ;
V_23 = F_15 ( sizeof( struct V_22 ) , V_25 ) ;
if ( ! V_23 )
return - V_125 ;
F_75 ( & V_23 -> V_82 ) ;
F_76 ( & V_23 -> V_52 ) ;
F_49 ( & V_23 -> V_73 ) ;
F_32 ( V_72 , & V_23 -> V_61 ) ;
F_16 ( & V_23 -> V_118 ) ;
F_77 ( & V_23 -> V_115 ) ;
V_15 -> V_24 = V_23 ;
memset ( V_47 , 0 , 64 ) ;
sprintf ( V_47 , L_16 , V_15 -> V_90 ) ;
V_7 = F_78 ( V_47 , V_15 -> V_64 . V_65 ,
V_130 , V_30 ,
& V_131 , V_15 , & V_129 , & V_23 -> V_26 ) ;
if ( V_7 )
goto V_132;
F_79 ( & V_23 -> V_73 ) ;
if ( V_128 < V_23 -> V_67 ) {
F_17 ( L_36 ,
V_23 -> V_67 , V_128 ) ;
V_7 = - V_133 ;
goto V_132;
}
V_7 = - V_125 ;
V_23 -> V_76 = F_36 ( F_61 , V_15 , L_37 ) ;
if ( ! V_23 -> V_76 ) {
F_17 ( L_38 ) ;
goto V_132;
}
V_23 -> V_114 = F_13 ( V_15 , L_39 , NULL , 1 ) ;
if ( ! V_23 -> V_114 )
goto V_132;
V_23 -> V_117 = F_13 ( V_15 , L_40 , NULL , 0 ) ;
if ( ! V_23 -> V_117 )
goto V_132;
V_23 -> V_101 = F_13 ( V_15 , L_41 , NULL , 0 ) ;
if ( ! V_23 -> V_101 )
goto V_132;
V_7 = F_3 ( V_23 -> V_117 , V_74 ) ;
if ( V_7 ) {
V_7 = - V_127 ;
F_17 ( L_42 ) ;
goto V_132;
}
V_23 -> V_113 = F_13 ( V_15 , L_43 , F_41 , 0 ) ;
if ( ! V_23 -> V_113 ) {
V_7 = - V_125 ;
goto V_132;
}
if ( F_3 ( V_23 -> V_113 , V_42 ) )
F_17 ( L_44 ,
V_7 ) ;
F_6 ( V_23 -> V_117 ) ;
if ( F_3 ( V_23 -> V_101 , V_42 ) )
F_17 ( L_45 , V_7 ) ;
F_12 ( L_46 , V_47 , V_23 -> V_67 ) ;
snprintf ( V_47 , 64 , L_7 , V_23 -> V_67 - 1 ) ;
V_23 -> V_134 = F_13 ( V_15 , V_47 , NULL , 1 ) ;
if ( ! V_23 -> V_134 ) {
V_7 = - V_125 ;
goto V_132;
}
if ( F_3 ( V_23 -> V_134 , V_55 ) ) {
F_17 ( L_47 ) ;
V_7 = - V_135 ;
goto V_132;
}
V_23 -> V_136 = F_13 ( V_15 , L_48 , NULL , 0 ) ;
if ( ! V_23 -> V_136 ) {
V_7 = - V_125 ;
goto V_132;
}
return 0 ;
V_132:
F_80 ( & V_23 -> V_62 ) ;
F_80 ( & V_23 -> V_76 ) ;
F_20 ( V_23 -> V_114 ) ;
F_20 ( V_23 -> V_117 ) ;
F_20 ( V_23 -> V_113 ) ;
F_20 ( V_23 -> V_101 ) ;
F_20 ( V_23 -> V_136 ) ;
F_20 ( V_23 -> V_134 ) ;
if ( V_23 -> V_26 )
F_81 ( V_23 -> V_26 , 2 ) ;
V_15 -> V_24 = NULL ;
F_19 ( V_23 ) ;
return V_7 ;
}
static void F_82 ( struct V_15 * V_15 , int V_123 )
{
struct V_22 * V_23 = V_15 -> V_24 ;
if ( F_72 ( V_15 , V_123 ) )
F_17 ( L_49 ) ;
F_32 ( V_75 , & V_23 -> V_61 ) ;
if ( F_83 ( V_77 , & V_23 -> V_61 ) )
F_33 ( V_23 -> V_76 ) ;
}
static void F_84 ( struct V_15 * V_15 )
{
struct V_22 * V_23 = V_15 -> V_24 ;
struct V_83 V_84 = { 0 } ;
int V_132 ;
V_84 . type = F_70 ( V_112 ) ;
V_132 = F_71 ( V_23 , & V_84 ) ;
if ( V_132 )
F_17 ( L_50 ,
V_91 , __LINE__ , V_132 ) ;
}
static int F_85 ( struct V_15 * V_15 )
{
struct V_22 * V_23 = V_15 -> V_24 ;
if ( ! V_23 )
return 0 ;
if ( V_23 -> V_67 > 0 && V_15 -> V_56 != V_57 )
F_84 ( V_15 ) ;
F_80 ( & V_23 -> V_62 ) ;
F_80 ( & V_23 -> V_76 ) ;
F_20 ( V_23 -> V_114 ) ;
F_20 ( V_23 -> V_117 ) ;
F_20 ( V_23 -> V_113 ) ;
F_20 ( V_23 -> V_101 ) ;
F_20 ( V_23 -> V_136 ) ;
F_20 ( V_23 -> V_134 ) ;
F_86 ( V_15 ) ;
F_81 ( V_23 -> V_26 , 2 ) ;
F_19 ( V_23 ) ;
return 0 ;
}
static int V_67 ( struct V_15 * V_15 )
{
struct V_22 * V_23 = V_15 -> V_24 ;
return V_23 -> V_67 - 1 ;
}
static int F_87 ( struct V_15 * V_15 )
{
struct V_22 * V_23 = V_15 -> V_24 ;
F_5 ( V_23 -> V_118 ,
! F_66 ( V_119 , & V_23 -> V_61 ) ||
F_83 ( V_137 , & V_23 -> V_61 ) ) ;
if ( V_23 -> V_117 -> V_6 == V_74 )
return 0 ;
return F_64 ( V_23 ) ;
}
static int F_88 ( struct V_15 * V_15 )
{
struct V_22 * V_23 = V_15 -> V_24 ;
struct V_83 V_84 ;
struct V_102 * V_103 ;
int V_7 = 0 ;
int V_87 = - 1 ;
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
V_84 . type = F_70 ( V_106 ) ;
F_89 (rdev, mddev)
if ( V_103 -> V_138 > - 1 && ! F_9 ( V_105 , & V_103 -> V_10 ) ) {
V_87 = V_103 -> V_139 ;
break;
}
if ( V_87 >= 0 ) {
V_84 . V_87 = F_70 ( V_87 ) ;
V_7 = F_69 ( V_23 , & V_84 ) ;
} else
F_37 ( L_51 ) ;
V_54 ( V_137 , & V_23 -> V_61 ) ;
F_67 ( V_23 ) ;
return V_7 ;
}
static void F_90 ( struct V_15 * V_15 )
{
struct V_22 * V_23 = V_15 -> V_24 ;
V_54 ( V_137 , & V_23 -> V_61 ) ;
F_67 ( V_23 ) ;
}
static int F_91 ( struct V_15 * V_15 )
{
struct V_22 * V_23 = V_15 -> V_24 ;
return F_7 ( V_23 -> V_136 , V_74 , V_15 ) ;
}
static int F_92 ( struct V_15 * V_15 , T_1 V_36 , T_1 V_37 )
{
struct V_22 * V_23 = V_15 -> V_24 ;
struct V_38 V_39 ;
struct V_83 V_84 = { 0 } ;
if ( V_37 == 0 ) {
memcpy ( & V_39 , V_23 -> V_134 -> V_9 . V_29 , sizeof( struct V_38 ) ) ;
if ( F_24 ( V_39 . V_37 ) == 0 )
return 0 ;
}
F_21 ( V_23 -> V_134 , V_36 , V_37 ) ;
F_3 ( V_23 -> V_134 , V_55 ) ;
V_84 . type = F_70 ( V_107 ) ;
V_84 . V_108 = F_22 ( V_36 ) ;
V_84 . V_109 = F_22 ( V_37 ) ;
return F_71 ( V_23 , & V_84 ) ;
}
static int F_93 ( struct V_15 * V_15 )
{
struct V_22 * V_23 = V_15 -> V_24 ;
F_6 ( V_23 -> V_136 ) ;
return F_92 ( V_15 , 0 , 0 ) ;
}
static int F_94 ( struct V_15 * V_15 , int V_140 ,
T_1 V_36 , T_1 V_37 )
{
struct V_22 * V_23 = V_15 -> V_24 ;
int V_7 = 0 ;
struct V_40 * V_41 ;
if ( ( V_140 == V_141 ) &&
F_9 ( V_60 , & V_23 -> V_61 ) )
return 1 ;
F_27 ( & V_23 -> V_52 ) ;
if ( F_95 ( & V_23 -> V_82 ) )
goto V_43;
F_96 (s, &cinfo->suspend_list, list)
if ( V_37 > V_41 -> V_36 && V_36 < V_41 -> V_37 ) {
V_7 = 1 ;
break;
}
V_43:
F_30 ( & V_23 -> V_52 ) ;
return V_7 ;
}
static int F_97 ( struct V_15 * V_15 , struct V_102 * V_103 )
{
struct V_22 * V_23 = V_15 -> V_24 ;
struct V_83 V_84 ;
int V_7 = 0 ;
struct V_142 * V_143 = F_98 ( V_103 -> V_144 ) ;
char * V_90 = V_143 -> V_145 ;
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
V_84 . type = F_70 ( V_110 ) ;
memcpy ( V_84 . V_90 , V_90 , 16 ) ;
V_84 . V_87 = F_70 ( V_103 -> V_139 ) ;
F_65 ( V_23 ) ;
V_7 = F_69 ( V_23 , & V_84 ) ;
if ( V_7 )
return V_7 ;
V_23 -> V_101 -> V_10 |= V_126 ;
V_7 = F_3 ( V_23 -> V_101 , V_74 ) ;
V_23 -> V_101 -> V_10 &= ~ V_126 ;
if ( V_7 == - V_127 )
V_7 = - V_146 ;
if ( V_7 )
F_67 ( V_23 ) ;
else {
F_3 ( V_23 -> V_101 , V_42 ) ;
F_32 ( V_137 , & V_23 -> V_61 ) ;
F_2 ( & V_23 -> V_118 ) ;
}
return V_7 ;
}
static void F_99 ( struct V_15 * V_15 )
{
struct V_22 * V_23 = V_15 -> V_24 ;
V_54 ( V_137 , & V_23 -> V_61 ) ;
F_67 ( V_23 ) ;
}
static int F_100 ( struct V_15 * V_15 , bool V_147 )
{
struct V_22 * V_23 = V_15 -> V_24 ;
if ( ! F_9 ( V_93 , & V_23 -> V_61 ) ) {
F_37 ( L_52 , F_101 ( V_15 ) ) ;
return - V_135 ;
}
if ( V_147 )
F_6 ( V_23 -> V_101 ) ;
F_40 ( & V_23 -> V_92 ) ;
return 0 ;
}
static int F_102 ( struct V_15 * V_15 , struct V_102 * V_103 )
{
struct V_83 V_84 = { 0 } ;
struct V_22 * V_23 = V_15 -> V_24 ;
V_84 . type = F_70 ( REMOVE ) ;
V_84 . V_87 = F_70 ( V_103 -> V_139 ) ;
return F_71 ( V_23 , & V_84 ) ;
}
static int F_103 ( struct V_15 * V_15 )
{
int V_48 , V_148 , V_7 , V_149 = 1 , V_124 = 0 ;
char V_47 [ 64 ] ;
struct V_22 * V_23 = V_15 -> V_24 ;
V_23 -> V_150 = F_15 ( ( V_15 -> V_64 . V_128 - 1 ) *
sizeof( struct V_2 * ) ,
V_25 ) ;
if ( ! V_23 -> V_150 ) {
F_17 ( L_53 ) ;
return 0 ;
}
V_148 = V_67 ( V_15 ) ;
for ( V_48 = 0 ; V_48 < V_15 -> V_64 . V_128 ; V_48 ++ ) {
if ( V_48 == V_148 )
continue;
memset ( V_47 , '\0' , 64 ) ;
snprintf ( V_47 , 64 , L_7 , V_48 ) ;
V_23 -> V_150 [ V_124 ] = F_13 ( V_15 , V_47 , NULL , 1 ) ;
if ( ! V_23 -> V_150 [ V_124 ] )
return - V_125 ;
V_23 -> V_150 [ V_124 ] -> V_10 |= V_126 ;
V_7 = F_3 ( V_23 -> V_150 [ V_124 ] , V_55 ) ;
if ( V_7 )
V_149 = - 1 ;
V_124 ++ ;
}
return V_149 ;
}
static void F_86 ( struct V_15 * V_15 )
{
struct V_22 * V_23 = V_15 -> V_24 ;
int V_124 ;
if ( V_23 -> V_150 ) {
for ( V_124 = 0 ; V_124 < V_15 -> V_64 . V_128 - 1 ; V_124 ++ ) {
if ( V_23 -> V_150 [ V_124 ] ) {
F_20 ( V_23 -> V_150 [ V_124 ] ) ;
}
}
F_19 ( V_23 -> V_150 ) ;
}
}
static int F_104 ( struct V_102 * V_103 )
{
int V_151 , V_132 ;
T_1 V_36 , V_37 ;
struct V_83 V_84 = { 0 } ;
struct V_15 * V_15 = V_103 -> V_15 ;
struct V_22 * V_23 = V_15 -> V_24 ;
V_84 . type = F_70 ( V_111 ) ;
V_84 . V_87 = F_70 ( V_103 -> V_139 ) ;
V_132 = F_71 ( V_23 , & V_84 ) ;
if ( V_132 )
goto V_43;
for ( V_151 = 0 ; V_151 < V_15 -> V_64 . V_128 ; V_151 ++ ) {
if ( V_151 == ( V_23 -> V_67 - 1 ) )
continue;
V_132 = F_31 ( V_15 , V_151 , & V_36 , & V_37 , false ) ;
if ( V_132 ) {
F_37 ( L_35 , V_151 ) ;
goto V_43;
}
if ( ( V_37 > 0 ) && ( V_36 < V_15 -> V_56 ) )
V_15 -> V_56 = V_36 ;
}
V_43:
return V_132 ;
}
static int T_3 F_105 ( void )
{
F_37 ( L_54 ) ;
F_12 ( L_55 ) ;
F_106 ( & V_152 , V_153 ) ;
return 0 ;
}
static void F_107 ( void )
{
F_108 () ;
}
