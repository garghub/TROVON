static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_5 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
static char * V_8 [ 2 ] = { L_1 , NULL } ;
static char * V_9 [ 2 ] = { L_2 , NULL } ;
static char * V_10 [ 2 ] = { L_3 , NULL } ;
char * * V_11 = NULL ;
unsigned long V_12 ;
F_3 ( & V_7 -> V_13 , V_12 ) ;
if ( V_7 -> V_14 )
V_11 = V_10 ;
else if ( V_4 -> V_9 != V_4 -> V_15 )
V_11 = V_4 -> V_9 ? V_9 : V_8 ;
V_4 -> V_15 = V_4 -> V_9 ;
F_4 ( & V_7 -> V_13 , V_12 ) ;
if ( V_11 ) {
F_5 ( & V_4 -> V_4 -> V_16 , V_17 , V_11 ) ;
F_6 ( L_4 , V_18 , V_11 [ 0 ] ) ;
} else {
F_6 ( L_5 , V_18 ,
V_4 -> V_9 , V_4 -> V_15 , V_7 -> V_14 ) ;
}
}
static struct V_19 * F_7 ( struct V_3 * V_4 ,
const char * V_20 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_4 -> V_22 ; V_21 ++ )
if ( strcmp ( V_4 -> V_23 [ V_21 ] . V_24 , V_20 ) == 0 )
return & V_4 -> V_23 [ V_21 ] ;
return NULL ;
}
static bool F_8 ( struct V_3 * V_4 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_4 -> V_22 ; V_21 ++ )
if ( V_4 -> V_23 [ V_21 ] . V_25 && ! V_4 -> V_23 [ V_21 ] . V_26 )
return false ;
return true ;
}
static int F_9 ( struct V_27 * V_28 )
{
struct V_19 * V_19 ;
int V_29 ;
F_10 ( & V_30 -> V_31 ) ;
V_19 = V_28 -> V_32 ;
if ( ! V_19 ) {
V_29 = - V_33 ;
goto V_34;
}
if ( F_11 ( V_19 -> V_26 ) ) {
V_29 = - V_35 ;
goto V_34;
}
V_19 -> V_27 = V_28 ;
if ( F_8 ( V_30 ) ) {
V_29 = - V_35 ;
goto V_34;
}
V_19 -> V_26 = true ;
V_34:
F_12 ( & V_30 -> V_31 ) ;
return V_29 ;
}
static void F_13 ( struct V_3 * V_4 )
{
F_14 ( V_4 -> V_7 -> V_36 -> V_37 , V_4 -> V_7 -> V_38 ) ;
F_15 ( V_4 -> V_7 , & V_39 ) ;
V_4 -> V_40 = false ;
F_16 ( V_4 -> V_7 -> V_36 ) ;
}
static void F_17 ( struct V_27 * V_28 )
{
struct V_19 * V_19 ;
F_10 ( & V_30 -> V_31 ) ;
V_19 = V_28 -> V_32 ;
if ( ! V_19 )
goto V_34;
V_19 -> V_26 = false ;
if ( V_30 -> V_40 )
F_13 ( V_30 ) ;
V_34:
F_12 ( & V_30 -> V_31 ) ;
}
static void * F_18 ( const char * V_20 )
{
struct V_19 * V_41 ;
F_10 ( & V_30 -> V_31 ) ;
V_41 = F_7 ( V_30 , V_20 ) ;
if ( ! V_41 ) {
V_41 = F_19 ( - V_42 ) ;
goto V_34;
}
if ( V_41 -> V_43 ) {
V_41 = F_19 ( - V_35 ) ;
goto V_34;
}
V_41 -> V_43 = true ;
V_34:
F_12 ( & V_30 -> V_31 ) ;
return V_41 ;
}
static void F_20 ( struct V_27 * V_27 )
{
struct V_19 * V_41 ;
F_10 ( & V_30 -> V_31 ) ;
V_41 = V_27 -> V_32 ;
if ( V_41 )
V_41 -> V_43 = false ;
F_12 ( & V_30 -> V_31 ) ;
}
static int F_21 ( struct V_44 * V_45 ,
struct V_6 * V_7 )
{
return F_22 () ;
}
static void F_23 ( struct V_44 * V_45 )
{
F_24 () ;
}
static int F_25 ( struct V_44 * V_45 ,
struct V_46 * V_47 )
{
struct V_3 * V_4 = V_30 ;
int V_21 , V_29 ;
for ( V_21 = V_4 -> V_22 ; V_21 -- ; ) {
if ( ! V_4 -> V_23 [ V_21 ] . V_25 )
continue;
V_29 = F_26 ( V_4 -> V_23 [ V_21 ] . V_27 , V_47 -> V_7 ) ;
if ( F_27 ( V_29 < 0 ) ) {
while ( ++ V_21 < V_4 -> V_22 )
F_28 ( V_4 -> V_23 [ V_21 ] . V_27 ) ;
return V_29 ;
}
}
for ( V_21 = V_4 -> V_22 ; V_21 -- ; ) {
if ( ! V_4 -> V_23 [ V_21 ] . V_25 )
continue;
V_29 = F_29 ( V_47 -> V_7 , V_47 ,
V_4 -> V_23 [ V_21 ] . V_27 ) ;
if ( F_27 ( V_29 < 0 ) )
return V_29 ;
}
return 0 ;
}
static void F_30 ( struct V_44 * V_45 ,
struct V_46 * V_47 )
{
struct V_3 * V_4 = V_30 ;
int V_21 ;
for ( V_21 = V_4 -> V_22 ; V_21 -- ; )
if ( V_4 -> V_23 [ V_21 ] . V_27 )
F_28 ( V_4 -> V_23 [ V_21 ] . V_27 ) ;
}
static T_1 F_31 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
char * V_52 )
{
struct V_3 * V_4 = V_30 ;
char * V_53 = V_52 ;
int V_21 ;
F_10 ( & V_4 -> V_31 ) ;
for ( V_21 = 0 ; V_21 < V_4 -> V_22 ; V_21 ++ )
V_53 += snprintf ( V_53 , V_54 + V_52 - V_53 , L_6 ,
V_4 -> V_23 [ V_21 ] . V_24 ) ;
F_12 ( & V_4 -> V_31 ) ;
if ( V_53 != V_52 )
* ( V_53 - 1 ) = '\n' ;
return V_53 - V_52 ;
}
static T_1 F_32 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char * V_53 , T_2 V_55 )
{
struct V_3 * V_4 = V_30 ;
char * V_24 , * V_56 ;
T_1 V_29 = V_55 ;
int V_21 ;
V_53 = F_33 ( V_53 ) ;
if ( ! * V_53 )
return - V_33 ;
F_10 ( & V_4 -> V_31 ) ;
if ( V_4 -> V_40 ) {
V_29 = - V_35 ;
goto V_57;
}
for ( V_21 = 0 ; V_21 < V_4 -> V_22 ; V_21 ++ )
if ( V_4 -> V_23 [ V_21 ] . V_43 ) {
V_29 = - V_35 ;
goto V_57;
}
F_34 ( V_58 , V_53 , sizeof( V_58 ) ) ;
V_56 = F_35 ( V_58 ) ;
V_4 -> V_22 = 0 ;
while ( V_56 ) {
V_24 = F_36 ( & V_56 , L_7 ) ;
if ( V_4 -> V_22 == V_59 ) {
V_29 = - V_60 ;
goto V_57;
}
if ( F_7 ( V_4 , V_24 ) ) {
V_29 = - V_61 ;
continue;
}
V_4 -> V_23 [ V_4 -> V_22 ++ ] . V_24 = V_24 ;
}
V_57:
F_12 ( & V_4 -> V_31 ) ;
return V_29 ;
}
static T_1 F_37 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
char * V_52 )
{
return sprintf ( V_52 , L_8 , V_59 ) ;
}
static int
F_38 ( struct V_44 * V_45 , struct V_6 * V_7 )
{
V_45 -> V_14 = F_39 ( sizeof( struct V_62 ) , V_63 ) ;
if ( ! V_45 -> V_14 )
return - V_64 ;
return F_40 ( V_7 -> V_36 , V_65 ) ;
}
static void F_41 ( struct V_44 * V_45 )
{
F_42 () ;
F_43 ( V_45 -> V_14 ) ;
V_45 -> V_14 = NULL ;
}
static int
F_44 ( struct V_44 * V_45 ,
struct V_46 * V_47 )
{
int V_21 ;
int V_29 = 0 ;
struct V_62 * V_14 = V_45 -> V_14 ;
for ( V_21 = 0 ; V_21 < V_14 -> V_66 ; V_21 ++ ) {
V_29 = F_45 ( V_47 , V_21 ) ;
if ( V_29 ) {
F_46 ( L_9 , V_21 ) ;
break;
}
}
return V_29 ;
}
static T_1 F_47 ( struct V_48 * V_4 ,
struct V_50 * V_51 , char * V_52 )
{
struct V_44 * V_45 = F_48 ( V_4 ) ;
struct V_62 * V_14 = V_45 -> V_14 ;
return sprintf ( V_52 , L_10 , V_14 -> V_66 ) ;
}
static T_1 F_49 ( struct V_48 * V_4 ,
struct V_50 * V_51 , const char * V_52 , T_2 V_55 )
{
struct V_44 * V_45 = F_48 ( V_4 ) ;
struct V_62 * V_14 = V_45 -> V_14 ;
int V_67 ;
int V_29 = 0 ;
V_29 = F_50 ( V_52 , 10 , & V_67 ) ;
if ( V_29 )
return V_29 ;
if ( V_67 > V_65 )
return - V_33 ;
V_14 -> V_66 = V_67 ;
return V_55 ;
}
static int F_51 ( struct V_44 * V_45 ,
struct V_6 * V_7 )
{
V_45 -> V_14 = F_39 ( sizeof( struct V_68 ) , V_63 ) ;
if ( ! V_45 -> V_14 )
return - V_64 ;
return 0 ;
}
static void F_52 ( struct V_44 * V_45 )
{
F_43 ( V_45 -> V_14 ) ;
V_45 -> V_14 = NULL ;
}
static int F_53 ( struct V_44 * V_45 ,
struct V_46 * V_47 )
{
int V_29 ;
struct V_68 * V_69 = V_45 -> V_14 ;
if ( ! V_69 ) {
F_46 ( L_11 , V_18 ) ;
return - 1 ;
}
F_6 ( L_12 , V_18 , V_69 -> V_70 ) ;
V_29 = F_54 ( V_47 -> V_7 -> V_36 , V_69 -> V_70 , L_13 ) ;
if ( V_29 ) {
F_46 ( L_14 , V_18 ) ;
return V_29 ;
}
if ( V_69 -> V_71 ) {
V_72 . V_73 =
V_74 ;
V_72 . V_75 = 0x01 ;
V_72 . V_76 = 0x03 ;
V_77 . V_78 =
V_74 ;
V_77 . V_79 = 0x01 ;
V_77 . V_80 = 0x03 ;
}
return F_55 ( V_47 , V_69 -> V_70 , V_69 -> V_81 ,
V_69 -> V_82 ) ;
}
static void F_56 ( struct V_44 * V_45 ,
struct V_46 * V_47 )
{
F_57 () ;
}
static T_1 F_58 ( struct V_48 * V_4 ,
struct V_50 * V_51 , char * V_52 )
{
struct V_44 * V_45 = F_48 ( V_4 ) ;
struct V_68 * V_14 = V_45 -> V_14 ;
return sprintf ( V_52 , L_15 , V_14 -> V_82 ) ;
}
static T_1 F_59 ( struct V_48 * V_4 ,
struct V_50 * V_51 , const char * V_52 , T_2 V_55 )
{
struct V_44 * V_45 = F_48 ( V_4 ) ;
struct V_68 * V_14 = V_45 -> V_14 ;
if ( V_55 >= sizeof( V_14 -> V_82 ) )
return - V_33 ;
memcpy ( V_14 -> V_82 , V_52 , V_55 ) ;
V_14 -> V_82 [ V_55 ] = 0 ;
return V_55 ;
}
static T_1 F_60 ( struct V_48 * V_4 ,
struct V_50 * V_51 , char * V_52 )
{
struct V_44 * V_45 = F_48 ( V_4 ) ;
struct V_68 * V_14 = V_45 -> V_14 ;
return sprintf ( V_52 , L_10 , V_14 -> V_71 ) ;
}
static T_1 F_61 ( struct V_48 * V_4 ,
struct V_50 * V_51 , const char * V_52 , T_2 V_55 )
{
struct V_44 * V_45 = F_48 ( V_4 ) ;
struct V_68 * V_14 = V_45 -> V_14 ;
int V_67 ;
int V_29 ;
V_29 = F_50 ( V_52 , 10 , & V_67 ) ;
if ( V_29 )
return V_29 ;
V_14 -> V_71 = V_67 ;
return V_55 ;
}
static T_1 F_62 ( struct V_48 * V_4 ,
struct V_50 * V_51 , char * V_52 )
{
struct V_44 * V_45 = F_48 ( V_4 ) ;
struct V_68 * V_69 = V_45 -> V_14 ;
return sprintf ( V_52 , L_16 , V_69 -> V_70 ) ;
}
static T_1 F_63 ( struct V_48 * V_4 ,
struct V_50 * V_51 , const char * V_52 , T_2 V_55 )
{
struct V_44 * V_45 = F_48 ( V_4 ) ;
struct V_68 * V_69 = V_45 -> V_14 ;
unsigned char V_83 [ 6 ] ;
if ( sscanf ( V_52 , L_17 ,
V_83 + 0 , V_83 + 1 , V_83 + 2 , V_83 + 3 , V_83 + 4 , V_83 + 5 ) !=
V_84 )
return - V_33 ;
memcpy ( V_69 -> V_70 , V_83 , V_84 ) ;
return V_84 ;
}
static T_1 F_64 ( struct V_48 * V_4 ,
struct V_50 * V_51 , char * V_52 )
{
struct V_44 * V_45 = F_48 ( V_4 ) ;
struct V_68 * V_14 = V_45 -> V_14 ;
return sprintf ( V_52 , L_18 , V_14 -> V_81 ) ;
}
static T_1 F_65 ( struct V_48 * V_4 ,
struct V_50 * V_51 , const char * V_52 , T_2 V_55 )
{
struct V_44 * V_45 = F_48 ( V_4 ) ;
struct V_68 * V_14 = V_45 -> V_14 ;
int V_67 ;
int V_29 ;
V_29 = F_66 ( V_52 , 16 , & V_67 ) ;
if ( V_29 )
return V_29 ;
V_14 -> V_81 = V_67 ;
return V_55 ;
}
static int F_67 ( struct V_44 * V_45 ,
struct V_6 * V_7 )
{
struct V_85 V_86 ;
struct V_87 * V_88 ;
int V_89 ;
memset ( & V_86 , 0 , sizeof( V_86 ) ) ;
V_86 . V_90 = 1 ;
V_86 . V_91 [ 0 ] . V_92 = 1 ;
V_86 . V_93 = V_94 ;
V_86 . V_95 = V_96 ;
V_88 = F_68 ( NULL , V_7 , & V_86 ) ;
if ( F_69 ( V_88 ) )
return F_70 ( V_88 ) ;
V_89 = F_71 ( & V_45 -> V_4 -> V_16 ,
& V_88 -> V_91 [ 0 ] . V_4 . V_16 ,
L_19 ) ;
if ( V_89 ) {
F_72 ( V_88 ) ;
return V_89 ;
}
V_45 -> V_14 = V_88 ;
return 0 ;
}
static void F_73 ( struct V_44 * V_45 )
{
F_72 ( V_45 -> V_14 ) ;
V_45 -> V_14 = NULL ;
}
static int F_74 ( struct V_44 * V_45 ,
struct V_46 * V_47 )
{
struct V_87 * V_88 = V_45 -> V_14 ;
return F_75 ( V_47 -> V_7 , V_47 , V_88 ) ;
}
static int F_76 ( struct V_44 * * V_97 ,
struct V_6 * V_7 )
{
struct V_3 * V_4 = V_30 ;
struct V_44 * V_45 ;
struct V_50 * * V_98 ;
struct V_50 * V_51 ;
int V_89 ;
int V_99 = 0 ;
for (; ( V_45 = * V_97 ++ ) ; V_99 ++ ) {
V_45 -> V_20 = F_77 ( V_63 , L_20 , V_45 -> V_24 ) ;
if ( ! V_45 -> V_20 ) {
F_46 ( L_21 , V_18 ,
V_45 -> V_24 ) ;
V_89 = - V_64 ;
goto V_100;
}
V_45 -> V_4 = F_78 ( V_101 , V_4 -> V_4 ,
F_79 ( 0 , V_99 ) , V_45 , V_45 -> V_20 ) ;
if ( F_69 ( V_45 -> V_4 ) ) {
F_46 ( L_22 , V_18 ,
V_45 -> V_20 ) ;
V_89 = F_70 ( V_45 -> V_4 ) ;
V_45 -> V_4 = NULL ;
goto V_102;
}
if ( V_45 -> V_103 ) {
V_89 = V_45 -> V_103 ( V_45 , V_7 ) ;
if ( V_89 ) {
F_46 ( L_23 , V_18 ,
V_45 -> V_24 ) ;
goto V_104;
}
}
V_98 = V_45 -> V_105 ;
if ( V_98 ) {
while ( ( V_51 = * V_98 ++ ) && ! V_89 )
V_89 = F_80 ( V_45 -> V_4 , V_51 ) ;
}
if ( V_89 ) {
F_46 ( L_24 ,
V_18 , V_45 -> V_24 ) ;
goto V_106;
}
}
return 0 ;
V_106:
if ( V_45 -> V_107 )
V_45 -> V_107 ( V_45 ) ;
V_104:
F_81 ( V_101 , V_45 -> V_4 -> V_108 ) ;
V_45 -> V_4 = NULL ;
V_102:
F_43 ( V_45 -> V_20 ) ;
V_100:
return V_89 ;
}
static void F_82 ( struct V_44 * * V_97 )
{
struct V_44 * V_45 ;
while ( * V_97 ) {
V_45 = * V_97 ++ ;
if ( V_45 -> V_4 ) {
if ( V_45 -> V_107 )
V_45 -> V_107 ( V_45 ) ;
F_81 ( V_101 , V_45 -> V_4 -> V_108 ) ;
F_43 ( V_45 -> V_20 ) ;
}
}
}
static int F_83 ( struct V_3 * V_4 ,
struct V_46 * V_47 )
{
struct V_44 * V_45 ;
int V_29 ;
F_84 (f, &dev->enabled_functions, enabled_list) {
V_29 = V_45 -> V_109 ( V_45 , V_47 ) ;
if ( V_29 ) {
F_46 ( L_25 , V_18 , V_45 -> V_24 ) ;
return V_29 ;
}
}
return 0 ;
}
static void F_85 ( struct V_3 * V_4 ,
struct V_46 * V_47 )
{
struct V_44 * V_45 ;
F_84 (f, &dev->enabled_functions, enabled_list)
if ( V_45 -> V_110 )
V_45 -> V_110 ( V_45 , V_47 ) ;
}
static int F_86 ( struct V_3 * V_4 , char * V_24 )
{
struct V_44 * * V_97 = V_4 -> V_97 ;
struct V_44 * V_45 ;
while ( ( V_45 = * V_97 ++ ) ) {
if ( ! strcmp ( V_24 , V_45 -> V_24 ) ) {
F_87 ( & V_45 -> V_111 ,
& V_4 -> V_112 ) ;
return 0 ;
}
}
return - V_33 ;
}
static T_1
F_88 ( struct V_48 * V_113 , struct V_50 * V_51 , char * V_52 )
{
struct V_3 * V_4 = F_48 ( V_113 ) ;
struct V_44 * V_45 ;
char * V_53 = V_52 ;
int V_21 ;
F_10 ( & V_4 -> V_31 ) ;
F_84 (f, &dev->enabled_functions, enabled_list)
V_53 += sprintf ( V_53 , L_6 , V_45 -> V_24 ) ;
for ( V_21 = 0 ; V_21 < V_4 -> V_22 ; V_21 ++ )
if ( V_4 -> V_23 [ V_21 ] . V_25 )
V_53 += sprintf ( V_53 , L_26 , V_4 -> V_23 [ V_21 ] . V_24 ) ;
F_12 ( & V_4 -> V_31 ) ;
if ( V_53 != V_52 )
* ( V_53 - 1 ) = '\n' ;
return V_53 - V_52 ;
}
static T_1
F_89 ( struct V_48 * V_113 , struct V_50 * V_51 ,
const char * V_53 , T_2 V_55 )
{
struct V_3 * V_4 = F_48 ( V_113 ) ;
char * V_24 ;
char V_52 [ 256 ] , * V_56 ;
int V_89 , V_21 ;
bool V_114 ;
V_53 = F_33 ( V_53 ) ;
if ( ! * V_53 )
return - V_33 ;
F_10 ( & V_4 -> V_31 ) ;
if ( V_4 -> V_40 ) {
F_12 ( & V_4 -> V_31 ) ;
return - V_35 ;
}
F_90 ( & V_4 -> V_112 ) ;
V_114 = false ;
for ( V_21 = 0 ; V_21 < V_4 -> V_22 ; V_21 ++ )
V_4 -> V_23 [ V_21 ] . V_25 = false ;
F_34 ( V_52 , V_53 , sizeof( V_52 ) ) ;
V_56 = F_35 ( V_52 ) ;
while ( V_56 ) {
struct V_19 * V_115 ;
V_24 = F_36 ( & V_56 , L_7 ) ;
if ( ! strcmp ( V_24 , V_116 . V_24 ) ) {
F_46 ( L_27 , V_24 ) ;
continue;
}
V_115 = F_7 ( V_4 , V_24 ) ;
if ( V_115 )
V_24 = V_116 . V_24 ;
V_89 = 0 ;
if ( ! V_115 || ! V_114 )
V_89 = F_86 ( V_4 , V_24 ) ;
if ( V_89 )
F_46 ( L_28 , V_24 ) ;
else if ( V_115 ) {
V_115 -> V_25 = true ;
V_4 -> V_117 ++ ;
V_114 = true ;
}
}
F_12 ( & V_4 -> V_31 ) ;
return V_55 ;
}
static T_1 F_91 ( struct V_48 * V_113 , struct V_50 * V_51 ,
char * V_52 )
{
struct V_3 * V_4 = F_48 ( V_113 ) ;
return sprintf ( V_52 , L_10 , V_4 -> V_40 ) ;
}
static T_1 F_92 ( struct V_48 * V_113 , struct V_50 * V_51 ,
const char * V_53 , T_2 V_55 )
{
struct V_3 * V_4 = F_48 ( V_113 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_40 = 0 ;
F_10 ( & V_4 -> V_31 ) ;
sscanf ( V_53 , L_8 , & V_40 ) ;
if ( V_40 && V_4 -> V_117 && ! F_8 ( V_4 ) ) {
F_12 ( & V_4 -> V_31 ) ;
return - V_42 ;
}
if ( V_40 && ! V_4 -> V_40 ) {
int V_29 ;
V_7 -> V_118 = 0 ;
V_7 -> V_119 . V_120 = V_121 . V_120 ;
V_7 -> V_119 . V_122 = V_121 . V_122 ;
V_7 -> V_119 . V_123 = V_121 . V_123 ;
V_7 -> V_119 . V_124 = V_124 ;
V_7 -> V_119 . V_125 = V_125 ;
V_7 -> V_119 . V_126 = V_126 ;
F_93 ( V_7 , & V_39 , V_127 ) ;
V_4 -> V_40 = true ;
V_29 = F_94 ( V_7 -> V_36 ) ;
if ( V_29 ) {
V_4 -> V_40 = false ;
F_15 ( V_7 , & V_39 ) ;
}
} else if ( ! V_40 && V_4 -> V_40 ) {
F_13 ( V_4 ) ;
} else {
F_46 ( L_29 ,
V_4 -> V_40 ? L_30 : L_31 ) ;
}
F_12 ( & V_4 -> V_31 ) ;
return V_55 ;
}
static T_1 F_95 ( struct V_48 * V_113 , struct V_50 * V_51 ,
char * V_52 )
{
struct V_3 * V_4 = F_48 ( V_113 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
char * V_128 = L_32 ;
unsigned long V_12 ;
if ( ! V_7 )
goto V_129;
F_3 ( & V_7 -> V_13 , V_12 ) ;
if ( V_7 -> V_14 )
V_128 = L_33 ;
else if ( V_4 -> V_9 )
V_128 = L_34 ;
F_4 ( & V_7 -> V_13 , V_12 ) ;
V_129:
return sprintf ( V_52 , L_15 , V_128 ) ;
}
static int V_127 ( struct V_46 * V_47 )
{
struct V_3 * V_4 = V_30 ;
return F_83 ( V_4 , V_47 ) ;
}
static void F_96 ( struct V_46 * V_47 )
{
struct V_3 * V_4 = V_30 ;
F_85 ( V_4 , V_47 ) ;
F_97 ( V_4 -> V_7 -> V_36 ) ;
}
static int F_98 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = V_30 ;
struct V_130 * V_36 = V_7 -> V_36 ;
int V_131 , V_29 ;
F_16 ( V_36 ) ;
V_29 = F_76 ( V_4 -> V_97 , V_7 ) ;
if ( V_29 )
return V_29 ;
V_131 = F_99 ( V_36 ) ;
if ( V_131 >= 0 )
V_121 . V_126 = F_100 ( 0x0200 + V_131 ) ;
else {
F_101 ( L_35 ,
V_132 , V_36 -> V_24 ) ;
V_121 . V_126 = F_102 ( 0x9999 ) ;
}
F_103 ( V_36 ) ;
V_4 -> V_7 = V_7 ;
return 0 ;
}
static int F_104 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = V_30 ;
F_105 ( & V_4 -> V_5 ) ;
F_82 ( V_4 -> V_97 ) ;
return 0 ;
}
static int F_106 ( struct V_130 * V_36 , const struct V_133 * V_47 )
{
struct V_3 * V_4 = V_30 ;
struct V_6 * V_7 = F_107 ( V_36 ) ;
struct V_134 * V_38 = V_7 -> V_38 ;
struct V_44 * V_45 ;
int V_67 = - V_135 ;
unsigned long V_12 ;
V_38 -> V_136 = 0 ;
V_38 -> V_137 = V_138 ;
V_38 -> V_139 = 0 ;
V_36 -> V_37 -> V_140 = V_7 ;
F_84 (f, &dev->enabled_functions, enabled_list) {
if ( V_45 -> V_141 ) {
V_67 = V_45 -> V_141 ( V_45 , V_7 , V_47 ) ;
if ( V_67 >= 0 )
break;
}
}
if ( V_67 < 0 )
V_67 = F_108 ( V_36 , V_47 ) ;
F_3 ( & V_7 -> V_13 , V_12 ) ;
if ( ! V_4 -> V_9 ) {
V_4 -> V_9 = 1 ;
F_109 ( & V_4 -> V_5 ) ;
} else if ( V_47 -> V_142 == V_143 &&
V_7 -> V_14 ) {
F_109 ( & V_4 -> V_5 ) ;
}
F_4 ( & V_7 -> V_13 , V_12 ) ;
return V_67 ;
}
static void F_110 ( struct V_130 * V_36 )
{
struct V_3 * V_4 = V_30 ;
struct V_6 * V_7 = F_107 ( V_36 ) ;
unsigned long V_12 ;
F_111 ( V_36 ) ;
F_3 ( & V_7 -> V_13 , V_12 ) ;
V_4 -> V_9 = 0 ;
F_109 ( & V_4 -> V_5 ) ;
F_4 ( & V_7 -> V_13 , V_12 ) ;
}
static int F_112 ( struct V_3 * V_4 )
{
struct V_50 * * V_98 = V_144 ;
struct V_50 * V_51 ;
int V_89 ;
V_4 -> V_4 = F_78 ( V_101 , NULL , F_79 ( 0 , 0 ) , NULL , L_36 ) ;
if ( F_69 ( V_4 -> V_4 ) )
return F_70 ( V_4 -> V_4 ) ;
F_113 ( V_4 -> V_4 , V_4 ) ;
while ( ( V_51 = * V_98 ++ ) ) {
V_89 = F_80 ( V_4 -> V_4 , V_51 ) ;
if ( V_89 ) {
F_81 ( V_101 , V_4 -> V_4 -> V_108 ) ;
return V_89 ;
}
}
return 0 ;
}
static int T_3 V_103 ( void )
{
struct V_3 * V_4 ;
int V_89 ;
V_101 = F_114 ( V_145 , L_37 ) ;
if ( F_69 ( V_101 ) )
return F_70 ( V_101 ) ;
V_4 = F_39 ( sizeof( * V_4 ) , V_63 ) ;
if ( ! V_4 ) {
F_115 ( V_101 ) ;
return - V_64 ;
}
V_4 -> V_97 = V_146 ;
F_90 ( & V_4 -> V_112 ) ;
F_116 ( & V_4 -> V_5 , F_1 ) ;
F_117 ( & V_4 -> V_31 ) ;
V_89 = F_112 ( V_4 ) ;
if ( V_89 ) {
F_115 ( V_101 ) ;
F_43 ( V_4 ) ;
return V_89 ;
}
V_30 = V_4 ;
V_147 . V_148 = F_106 ;
V_147 . V_149 = F_110 ;
V_89 = F_118 ( & V_150 ) ;
if ( V_89 ) {
F_115 ( V_101 ) ;
F_43 ( V_4 ) ;
}
return V_89 ;
}
static void T_4 V_107 ( void )
{
F_119 ( & V_150 ) ;
F_115 ( V_101 ) ;
F_43 ( V_30 ) ;
V_30 = NULL ;
}
