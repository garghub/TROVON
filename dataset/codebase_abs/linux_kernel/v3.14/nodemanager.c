struct V_1 * F_1 ( T_1 V_2 )
{
struct V_1 * V_3 = NULL ;
if ( V_2 >= V_4 || V_5 == NULL )
goto V_6;
F_2 ( & V_5 -> V_7 ) ;
V_3 = V_5 -> V_8 [ V_2 ] ;
if ( V_3 )
F_3 ( & V_3 -> V_9 ) ;
F_4 ( & V_5 -> V_7 ) ;
V_6:
return V_3 ;
}
int F_5 ( unsigned long * V_10 , unsigned V_11 )
{
struct V_12 * V_13 = V_5 ;
F_6 ( V_11 < ( sizeof( V_13 -> V_14 ) ) ) ;
if ( V_13 == NULL )
return - V_15 ;
F_2 ( & V_13 -> V_7 ) ;
memcpy ( V_10 , V_13 -> V_14 , sizeof( V_13 -> V_14 ) ) ;
F_4 ( & V_13 -> V_7 ) ;
return 0 ;
}
static struct V_1 * F_7 ( struct V_12 * V_13 ,
T_2 V_16 ,
struct V_17 * * * V_18 ,
struct V_17 * * V_19 )
{
struct V_17 * * V_20 = & V_13 -> V_21 . V_17 ;
struct V_17 * V_22 = NULL ;
struct V_1 * V_3 , * V_23 = NULL ;
while ( * V_20 ) {
int V_24 ;
V_22 = * V_20 ;
V_3 = F_8 ( V_22 , struct V_1 , V_25 ) ;
V_24 = memcmp ( & V_16 , & V_3 -> V_26 ,
sizeof( V_16 ) ) ;
if ( V_24 < 0 )
V_20 = & ( * V_20 ) -> V_27 ;
else if ( V_24 > 0 )
V_20 = & ( * V_20 ) -> V_28 ;
else {
V_23 = V_3 ;
break;
}
}
if ( V_18 != NULL )
* V_18 = V_20 ;
if ( V_19 != NULL )
* V_19 = V_22 ;
return V_23 ;
}
struct V_1 * F_9 ( T_2 V_29 )
{
struct V_1 * V_3 = NULL ;
struct V_12 * V_13 = V_5 ;
if ( V_13 == NULL )
goto V_6;
F_2 ( & V_13 -> V_7 ) ;
V_3 = F_7 ( V_13 , V_29 , NULL , NULL ) ;
if ( V_3 )
F_3 ( & V_3 -> V_9 ) ;
F_4 ( & V_13 -> V_7 ) ;
V_6:
return V_3 ;
}
void F_10 ( struct V_1 * V_3 )
{
F_11 ( & V_3 -> V_9 ) ;
}
void F_12 ( struct V_1 * V_3 )
{
F_3 ( & V_3 -> V_9 ) ;
}
T_1 F_13 ( void )
{
T_1 V_2 = V_4 ;
if ( V_5 && V_5 -> V_30 )
V_2 = V_5 -> V_31 ;
return V_2 ;
}
static struct V_12 * F_14 ( struct V_32 * V_33 )
{
return V_33 ?
F_15 ( F_16 ( V_33 ) , struct V_12 ,
V_34 )
: NULL ;
}
static struct V_1 * F_17 ( struct V_32 * V_33 )
{
return V_33 ? F_15 ( V_33 , struct V_1 , V_9 ) : NULL ;
}
static void F_18 ( struct V_32 * V_33 )
{
struct V_1 * V_3 = F_17 ( V_33 ) ;
F_19 ( V_3 ) ;
}
static T_3 F_20 ( struct V_1 * V_3 , char * V_35 )
{
return sprintf ( V_35 , L_1 , V_3 -> V_36 ) ;
}
static struct V_12 * F_21 ( struct V_1 * V_3 )
{
return F_14 ( V_3 -> V_9 . V_37 -> V_37 ) ;
}
static T_3 F_22 ( struct V_1 * V_3 , const char * V_35 ,
T_4 V_38 )
{
struct V_12 * V_13 = F_21 ( V_3 ) ;
unsigned long V_39 ;
char * V_20 = ( char * ) V_35 ;
V_39 = F_23 ( V_20 , & V_20 , 0 ) ;
if ( ! V_20 || ( * V_20 && ( * V_20 != '\n' ) ) )
return - V_15 ;
if ( V_39 >= V_4 )
return - V_40 ;
if ( ! F_24 ( V_41 , & V_3 -> V_42 ) ||
! F_24 ( V_43 , & V_3 -> V_42 ) )
return - V_15 ;
F_25 ( & V_13 -> V_7 ) ;
if ( V_13 -> V_8 [ V_39 ] )
V_20 = NULL ;
else {
V_13 -> V_8 [ V_39 ] = V_3 ;
V_3 -> V_36 = V_39 ;
F_26 ( V_39 , V_13 -> V_14 ) ;
}
F_27 ( & V_13 -> V_7 ) ;
if ( V_20 == NULL )
return - V_44 ;
return V_38 ;
}
static T_3 F_28 ( struct V_1 * V_3 , char * V_35 )
{
return sprintf ( V_35 , L_2 , F_29 ( V_3 -> V_45 ) ) ;
}
static T_3 F_30 ( struct V_1 * V_3 ,
const char * V_35 , T_4 V_38 )
{
unsigned long V_39 ;
char * V_20 = ( char * ) V_35 ;
V_39 = F_23 ( V_20 , & V_20 , 0 ) ;
if ( ! V_20 || ( * V_20 && ( * V_20 != '\n' ) ) )
return - V_15 ;
if ( V_39 == 0 )
return - V_15 ;
if ( V_39 >= ( V_46 ) - 1 )
return - V_40 ;
V_3 -> V_45 = F_31 ( V_39 ) ;
return V_38 ;
}
static T_3 F_32 ( struct V_1 * V_3 , char * V_35 )
{
return sprintf ( V_35 , L_3 , & V_3 -> V_26 ) ;
}
static T_3 F_33 ( struct V_1 * V_3 ,
const char * V_35 ,
T_4 V_38 )
{
struct V_12 * V_13 = F_21 ( V_3 ) ;
int V_23 , V_47 ;
struct V_17 * * V_20 , * V_22 ;
unsigned int V_48 [ 4 ] ;
T_2 V_49 = 0 ;
V_23 = sscanf ( V_35 , L_4 , & V_48 [ 3 ] , & V_48 [ 2 ] ,
& V_48 [ 1 ] , & V_48 [ 0 ] ) ;
if ( V_23 != 4 )
return - V_15 ;
for ( V_47 = 0 ; V_47 < F_34 ( V_48 ) ; V_47 ++ ) {
if ( V_48 [ V_47 ] > 255 )
return - V_40 ;
F_35 ( & V_49 , V_48 [ V_47 ] << ( V_47 * 8 ) ) ;
}
V_23 = 0 ;
F_25 ( & V_13 -> V_7 ) ;
if ( F_7 ( V_13 , V_49 , & V_20 , & V_22 ) )
V_23 = - V_44 ;
else {
F_36 ( & V_3 -> V_25 , V_22 , V_20 ) ;
F_37 ( & V_3 -> V_25 , & V_13 -> V_21 ) ;
}
F_27 ( & V_13 -> V_7 ) ;
if ( V_23 )
return V_23 ;
memcpy ( & V_3 -> V_26 , & V_49 , sizeof( V_49 ) ) ;
return V_38 ;
}
static T_3 F_38 ( struct V_1 * V_3 , char * V_35 )
{
return sprintf ( V_35 , L_1 , V_3 -> V_50 ) ;
}
static T_3 F_39 ( struct V_1 * V_3 , const char * V_35 ,
T_4 V_38 )
{
struct V_12 * V_13 = F_21 ( V_3 ) ;
unsigned long V_39 ;
char * V_20 = ( char * ) V_35 ;
T_3 V_23 ;
V_39 = F_23 ( V_20 , & V_20 , 0 ) ;
if ( ! V_20 || ( * V_20 && ( * V_20 != '\n' ) ) )
return - V_15 ;
V_39 = ! ! V_39 ;
if ( ! F_24 ( V_41 , & V_3 -> V_42 ) ||
! F_24 ( V_51 , & V_3 -> V_42 ) ||
! F_24 ( V_43 , & V_3 -> V_42 ) )
return - V_15 ;
if ( V_39 && V_39 == V_13 -> V_30 &&
V_13 -> V_31 != V_3 -> V_36 )
return - V_52 ;
if ( V_39 && ! V_13 -> V_30 ) {
V_23 = F_40 ( V_3 ) ;
if ( V_23 )
return V_23 ;
}
if ( ! V_39 && V_13 -> V_30 &&
V_13 -> V_31 == V_3 -> V_36 ) {
F_41 ( V_3 ) ;
V_13 -> V_31 = V_53 ;
}
V_3 -> V_50 = V_39 ;
if ( V_3 -> V_50 ) {
V_13 -> V_30 = V_39 ;
V_13 -> V_31 = V_3 -> V_36 ;
}
return V_38 ;
}
static int F_42 ( struct V_54 * V_55 )
{
int V_47 ;
for ( V_47 = 0 ; V_47 < F_34 ( V_56 ) ; V_47 ++ ) {
if ( V_55 == V_56 [ V_47 ] )
return V_47 ;
}
F_43 () ;
return 0 ;
}
static T_3 F_44 ( struct V_32 * V_33 ,
struct V_54 * V_55 ,
char * V_35 )
{
struct V_1 * V_3 = F_17 ( V_33 ) ;
struct V_57 * V_58 =
F_15 ( V_55 , struct V_57 , V_55 ) ;
T_3 V_23 = 0 ;
if ( V_58 -> V_59 )
V_23 = V_58 -> V_59 ( V_3 , V_35 ) ;
return V_23 ;
}
static T_3 F_45 ( struct V_32 * V_33 ,
struct V_54 * V_55 ,
const char * V_35 , T_4 V_38 )
{
struct V_1 * V_3 = F_17 ( V_33 ) ;
struct V_57 * V_58 =
F_15 ( V_55 , struct V_57 , V_55 ) ;
T_3 V_23 ;
int V_60 = F_42 ( V_55 ) ;
if ( V_58 -> V_61 == NULL ) {
V_23 = - V_15 ;
goto V_6;
}
if ( F_24 ( V_60 , & V_3 -> V_42 ) )
return - V_52 ;
V_23 = V_58 -> V_61 ( V_3 , V_35 , V_38 ) ;
if ( V_23 < V_38 )
goto V_6;
F_26 ( V_60 , & V_3 -> V_42 ) ;
V_6:
return V_23 ;
}
static T_3 F_46 ( const char * V_35 , T_3 V_38 ,
unsigned int * V_62 )
{
unsigned long V_39 ;
char * V_20 = ( char * ) V_35 ;
V_39 = F_23 ( V_20 , & V_20 , 0 ) ;
if ( ! V_20 || ( * V_20 && ( * V_20 != '\n' ) ) )
return - V_15 ;
if ( V_39 == 0 )
return - V_15 ;
if ( V_39 >= ( V_63 ) - 1 )
return - V_40 ;
* V_62 = V_39 ;
return V_38 ;
}
static T_3 F_47 (
struct V_12 * V_13 , char * V_35 )
{
return sprintf ( V_35 , L_2 , V_13 -> V_64 ) ;
}
static T_3 F_48 (
struct V_12 * V_13 , const char * V_35 , T_4 V_38 )
{
T_3 V_23 ;
unsigned int V_62 ;
V_23 = F_46 ( V_35 , V_38 , & V_62 ) ;
if ( V_23 > 0 ) {
if ( V_13 -> V_64 != V_62
&& F_49 () ) {
F_50 ( V_65 ,
L_5
L_6
L_7 ,
F_49 () ) ;
V_23 = - V_15 ;
} else if ( V_62 <= V_13 -> V_66 ) {
F_50 ( V_65 , L_8
L_9 ) ;
V_23 = - V_15 ;
} else {
V_13 -> V_64 = V_62 ;
}
}
return V_23 ;
}
static T_3 F_51 (
struct V_12 * V_13 , char * V_35 )
{
return sprintf ( V_35 , L_2 , V_13 -> V_66 ) ;
}
static T_3 F_52 (
struct V_12 * V_13 , const char * V_35 , T_4 V_38 )
{
T_3 V_23 ;
unsigned int V_62 ;
V_23 = F_46 ( V_35 , V_38 , & V_62 ) ;
if ( V_23 > 0 ) {
if ( V_13 -> V_66 != V_62
&& F_49 () ) {
F_50 ( V_65 ,
L_10
L_11
L_7 ,
F_49 () ) ;
V_23 = - V_15 ;
} else if ( V_62 >= V_13 -> V_64 ) {
F_50 ( V_65 , L_12
L_13 ) ;
V_23 = - V_15 ;
} else {
V_13 -> V_66 = V_62 ;
}
}
return V_23 ;
}
static T_3 F_53 (
struct V_12 * V_13 , char * V_35 )
{
return sprintf ( V_35 , L_2 , V_13 -> V_67 ) ;
}
static T_3 F_54 (
struct V_12 * V_13 , const char * V_35 , T_4 V_38 )
{
return F_46 ( V_35 , V_38 ,
& V_13 -> V_67 ) ;
}
static T_3 F_55 (
struct V_12 * V_13 , char * V_35 )
{
T_3 V_23 = 0 ;
if ( V_13 )
V_23 = sprintf ( V_35 , L_14 ,
V_68 [ V_13 -> V_69 ] ) ;
return V_23 ;
}
static T_3 F_56 (
struct V_12 * V_13 , const char * V_35 , T_4 V_38 )
{
unsigned int V_47 ;
if ( V_35 [ V_38 - 1 ] != '\n' )
goto V_70;
for ( V_47 = 0 ; V_47 < V_71 ; ++ V_47 ) {
if ( V_38 != strlen ( V_68 [ V_47 ] ) + 1 )
continue;
if ( strncasecmp ( V_35 , V_68 [ V_47 ] , V_38 - 1 ) )
continue;
if ( V_13 -> V_69 != V_47 ) {
F_57 ( V_72 L_15 ,
V_68 [ V_47 ] ) ;
V_13 -> V_69 = V_47 ;
}
return V_38 ;
}
V_70:
return - V_15 ;
}
static T_3 F_58 ( struct V_32 * V_33 ,
struct V_54 * V_55 ,
char * V_35 )
{
struct V_12 * V_13 = F_14 ( V_33 ) ;
struct V_73 * V_74 =
F_15 ( V_55 , struct V_73 , V_55 ) ;
T_3 V_23 = 0 ;
if ( V_74 -> V_59 )
V_23 = V_74 -> V_59 ( V_13 , V_35 ) ;
return V_23 ;
}
static T_3 F_59 ( struct V_32 * V_33 ,
struct V_54 * V_55 ,
const char * V_35 , T_4 V_38 )
{
struct V_12 * V_13 = F_14 ( V_33 ) ;
struct V_73 * V_74 =
F_15 ( V_55 , struct V_73 , V_55 ) ;
T_3 V_23 ;
if ( V_74 -> V_61 == NULL ) {
V_23 = - V_15 ;
goto V_6;
}
V_23 = V_74 -> V_61 ( V_13 , V_35 , V_38 ) ;
if ( V_23 < V_38 )
goto V_6;
V_6:
return V_23 ;
}
static struct V_32 * F_60 ( struct V_75 * V_76 ,
const char * V_77 )
{
struct V_1 * V_3 = NULL ;
if ( strlen ( V_77 ) > V_78 )
return F_61 ( - V_79 ) ;
V_3 = F_62 ( sizeof( struct V_1 ) , V_80 ) ;
if ( V_3 == NULL )
return F_61 ( - V_81 ) ;
strcpy ( V_3 -> V_82 , V_77 ) ;
F_63 ( & V_3 -> V_9 , V_77 , & V_83 ) ;
F_64 ( & V_3 -> V_84 ) ;
F_50 ( V_85 , L_16 , V_77 ) ;
return & V_3 -> V_9 ;
}
static void F_65 ( struct V_75 * V_76 ,
struct V_32 * V_33 )
{
struct V_1 * V_3 = F_17 ( V_33 ) ;
struct V_12 * V_13 = F_14 ( V_76 -> V_86 . V_37 ) ;
F_66 ( V_3 ) ;
if ( V_13 -> V_30 &&
( V_13 -> V_31 == V_3 -> V_36 ) ) {
V_13 -> V_30 = 0 ;
V_13 -> V_31 = V_53 ;
F_41 ( V_3 ) ;
}
F_25 ( & V_13 -> V_7 ) ;
if ( V_3 -> V_26 )
F_67 ( & V_3 -> V_25 , & V_13 -> V_21 ) ;
if ( V_13 -> V_8 [ V_3 -> V_36 ] == V_3 ) {
V_13 -> V_8 [ V_3 -> V_36 ] = NULL ;
F_68 ( V_3 -> V_36 , V_13 -> V_14 ) ;
}
F_27 ( & V_13 -> V_7 ) ;
F_50 ( V_85 , L_17 ,
F_69 ( & V_3 -> V_9 ) ) ;
F_11 ( V_33 ) ;
}
static void F_70 ( struct V_32 * V_33 )
{
struct V_12 * V_13 = F_14 ( V_33 ) ;
F_19 ( V_13 -> V_34 . V_87 ) ;
F_19 ( V_13 ) ;
}
static struct V_75 * F_71 ( struct V_75 * V_76 ,
const char * V_77 )
{
struct V_12 * V_13 = NULL ;
struct V_88 * V_89 = NULL ;
struct V_75 * V_90 = NULL , * V_23 = NULL ;
void * V_91 = NULL ;
if ( V_5 )
return F_61 ( - V_92 ) ;
V_13 = F_62 ( sizeof( struct V_12 ) , V_80 ) ;
V_89 = F_62 ( sizeof( struct V_88 ) , V_80 ) ;
V_91 = F_72 ( 3 , sizeof( struct V_75 * ) , V_80 ) ;
V_90 = F_73 () ;
if ( V_13 == NULL || V_89 == NULL || V_90 == NULL || V_91 == NULL )
goto V_6;
F_74 ( & V_13 -> V_34 , V_77 ,
& V_93 ) ;
F_74 ( & V_89 -> V_94 , L_18 ,
& V_95 ) ;
V_13 -> V_34 . V_87 = V_91 ;
V_13 -> V_34 . V_87 [ 0 ] = & V_89 -> V_94 ;
V_13 -> V_34 . V_87 [ 1 ] = V_90 ;
V_13 -> V_34 . V_87 [ 2 ] = NULL ;
F_75 ( & V_13 -> V_7 ) ;
V_13 -> V_21 = V_96 ;
V_13 -> V_67 = V_97 ;
V_13 -> V_64 = V_98 ;
V_13 -> V_66 = V_99 ;
V_13 -> V_69 = V_100 ;
V_23 = & V_13 -> V_34 ;
V_5 = V_13 ;
V_6:
if ( V_23 == NULL ) {
F_19 ( V_13 ) ;
F_19 ( V_89 ) ;
F_76 ( V_90 ) ;
F_19 ( V_91 ) ;
V_23 = F_61 ( - V_81 ) ;
}
return V_23 ;
}
static void F_77 ( struct V_75 * V_76 , struct V_32 * V_33 )
{
struct V_12 * V_13 = F_14 ( V_33 ) ;
int V_47 ;
struct V_32 * V_101 ;
F_6 ( V_5 != V_13 ) ;
V_5 = NULL ;
for ( V_47 = 0 ; V_13 -> V_34 . V_87 [ V_47 ] ; V_47 ++ ) {
V_101 = & V_13 -> V_34 . V_87 [ V_47 ] -> V_86 ;
V_13 -> V_34 . V_87 [ V_47 ] = NULL ;
F_11 ( V_101 ) ;
}
F_11 ( V_33 ) ;
}
int F_78 ( struct V_32 * V_33 )
{
return F_79 ( & V_102 . V_103 , V_33 ) ;
}
void F_80 ( struct V_32 * V_33 )
{
F_81 ( & V_102 . V_103 , V_33 ) ;
}
int F_82 ( void )
{
int V_23 = 0 ;
struct V_1 * V_104 ;
V_104 = F_1 ( F_13 () ) ;
if ( ! V_104 ) {
V_23 = - V_15 ;
goto V_6;
}
V_23 = F_78 ( & V_104 -> V_9 ) ;
F_10 ( V_104 ) ;
V_6:
return V_23 ;
}
void F_83 ( void )
{
struct V_1 * V_104 ;
V_104 = F_1 ( F_13 () ) ;
F_6 ( ! V_104 ) ;
F_80 ( & V_104 -> V_9 ) ;
F_10 ( V_104 ) ;
}
static void T_5 F_84 ( void )
{
F_85 () ;
F_86 ( & V_102 . V_103 ) ;
F_87 () ;
F_88 () ;
F_89 () ;
}
static int T_6 F_90 ( void )
{
int V_23 = - 1 ;
V_23 = F_91 () ;
if ( V_23 )
goto V_6;
V_23 = F_92 () ;
if ( V_23 )
goto V_105;
V_23 = F_93 () ;
if ( V_23 )
goto V_106;
F_94 ( & V_102 . V_103 . V_107 ) ;
F_95 ( & V_102 . V_103 . V_108 ) ;
V_23 = F_96 ( & V_102 . V_103 ) ;
if ( V_23 ) {
F_57 ( V_109 L_19 , V_23 ) ;
goto V_110;
}
V_23 = F_97 () ;
if ( ! V_23 )
goto V_6;
F_86 ( & V_102 . V_103 ) ;
V_110:
F_85 () ;
V_106:
F_88 () ;
V_105:
F_89 () ;
V_6:
return V_23 ;
}
