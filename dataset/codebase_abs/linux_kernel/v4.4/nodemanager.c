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
static T_3 F_20 ( struct V_32 * V_33 , char * V_35 )
{
return sprintf ( V_35 , L_1 , F_17 ( V_33 ) -> V_36 ) ;
}
static struct V_12 * F_21 ( struct V_1 * V_3 )
{
return F_14 ( V_3 -> V_9 . V_37 -> V_37 ) ;
}
static T_3 F_22 ( struct V_32 * V_33 , const char * V_35 ,
T_4 V_38 )
{
struct V_1 * V_3 = F_17 ( V_33 ) ;
struct V_12 * V_13 = F_21 ( V_3 ) ;
unsigned long V_39 ;
char * V_20 = ( char * ) V_35 ;
int V_23 = 0 ;
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
V_23 = - V_44 ;
else if ( F_26 ( V_45 ,
& V_3 -> V_42 ) )
V_23 = - V_46 ;
else {
V_13 -> V_8 [ V_39 ] = V_3 ;
V_3 -> V_36 = V_39 ;
F_27 ( V_39 , V_13 -> V_14 ) ;
}
F_28 ( & V_13 -> V_7 ) ;
if ( V_23 )
return V_23 ;
return V_38 ;
}
static T_3 F_29 ( struct V_32 * V_33 , char * V_35 )
{
return sprintf ( V_35 , L_2 , F_30 ( F_17 ( V_33 ) -> V_47 ) ) ;
}
static T_3 F_31 ( struct V_32 * V_33 ,
const char * V_35 , T_4 V_38 )
{
struct V_1 * V_3 = F_17 ( V_33 ) ;
unsigned long V_39 ;
char * V_20 = ( char * ) V_35 ;
V_39 = F_23 ( V_20 , & V_20 , 0 ) ;
if ( ! V_20 || ( * V_20 && ( * V_20 != '\n' ) ) )
return - V_15 ;
if ( V_39 == 0 )
return - V_15 ;
if ( V_39 >= ( V_48 ) - 1 )
return - V_40 ;
if ( F_26 ( V_43 , & V_3 -> V_42 ) )
return - V_46 ;
V_3 -> V_47 = F_32 ( V_39 ) ;
return V_38 ;
}
static T_3 F_33 ( struct V_32 * V_33 , char * V_35 )
{
return sprintf ( V_35 , L_3 , & F_17 ( V_33 ) -> V_26 ) ;
}
static T_3 F_34 ( struct V_32 * V_33 ,
const char * V_35 ,
T_4 V_38 )
{
struct V_1 * V_3 = F_17 ( V_33 ) ;
struct V_12 * V_13 = F_21 ( V_3 ) ;
int V_23 , V_49 ;
struct V_17 * * V_20 , * V_22 ;
unsigned int V_50 [ 4 ] ;
T_2 V_51 = 0 ;
V_23 = sscanf ( V_35 , L_4 , & V_50 [ 3 ] , & V_50 [ 2 ] ,
& V_50 [ 1 ] , & V_50 [ 0 ] ) ;
if ( V_23 != 4 )
return - V_15 ;
for ( V_49 = 0 ; V_49 < F_35 ( V_50 ) ; V_49 ++ ) {
if ( V_50 [ V_49 ] > 255 )
return - V_40 ;
F_36 ( & V_51 , V_50 [ V_49 ] << ( V_49 * 8 ) ) ;
}
V_23 = 0 ;
F_25 ( & V_13 -> V_7 ) ;
if ( F_7 ( V_13 , V_51 , & V_20 , & V_22 ) )
V_23 = - V_44 ;
else if ( F_26 ( V_41 ,
& V_3 -> V_42 ) )
V_23 = - V_46 ;
else {
F_37 ( & V_3 -> V_25 , V_22 , V_20 ) ;
F_38 ( & V_3 -> V_25 , & V_13 -> V_21 ) ;
}
F_28 ( & V_13 -> V_7 ) ;
if ( V_23 )
return V_23 ;
memcpy ( & V_3 -> V_26 , & V_51 , sizeof( V_51 ) ) ;
return V_38 ;
}
static T_3 F_39 ( struct V_32 * V_33 , char * V_35 )
{
return sprintf ( V_35 , L_1 , F_17 ( V_33 ) -> V_52 ) ;
}
static T_3 F_40 ( struct V_32 * V_33 , const char * V_35 ,
T_4 V_38 )
{
struct V_1 * V_3 = F_17 ( V_33 ) ;
struct V_12 * V_13 = F_21 ( V_3 ) ;
unsigned long V_39 ;
char * V_20 = ( char * ) V_35 ;
T_3 V_23 ;
V_39 = F_23 ( V_20 , & V_20 , 0 ) ;
if ( ! V_20 || ( * V_20 && ( * V_20 != '\n' ) ) )
return - V_15 ;
V_39 = ! ! V_39 ;
if ( ! F_24 ( V_41 , & V_3 -> V_42 ) ||
! F_24 ( V_45 , & V_3 -> V_42 ) ||
! F_24 ( V_43 , & V_3 -> V_42 ) )
return - V_15 ;
if ( V_39 && V_39 == V_13 -> V_30 &&
V_13 -> V_31 != V_3 -> V_36 )
return - V_46 ;
if ( V_39 && ! V_13 -> V_30 ) {
V_23 = F_41 ( V_3 ) ;
if ( V_23 )
return V_23 ;
}
if ( ! V_39 && V_13 -> V_30 &&
V_13 -> V_31 == V_3 -> V_36 ) {
F_42 ( V_3 ) ;
V_13 -> V_31 = V_53 ;
}
V_3 -> V_52 = V_39 ;
if ( V_3 -> V_52 ) {
V_13 -> V_30 = V_39 ;
V_13 -> V_31 = V_3 -> V_36 ;
}
return V_38 ;
}
static T_3 F_43 ( const char * V_35 , T_3 V_38 ,
unsigned int * V_54 )
{
unsigned long V_39 ;
char * V_20 = ( char * ) V_35 ;
V_39 = F_23 ( V_20 , & V_20 , 0 ) ;
if ( ! V_20 || ( * V_20 && ( * V_20 != '\n' ) ) )
return - V_15 ;
if ( V_39 == 0 )
return - V_15 ;
if ( V_39 >= ( V_55 ) - 1 )
return - V_40 ;
* V_54 = V_39 ;
return V_38 ;
}
static T_3 F_44 ( struct V_32 * V_33 ,
char * V_35 )
{
return sprintf ( V_35 , L_2 , F_14 ( V_33 ) -> V_56 ) ;
}
static T_3 F_45 ( struct V_32 * V_33 ,
const char * V_35 , T_4 V_38 )
{
struct V_12 * V_13 = F_14 ( V_33 ) ;
T_3 V_23 ;
unsigned int V_54 ;
V_23 = F_43 ( V_35 , V_38 , & V_54 ) ;
if ( V_23 > 0 ) {
if ( V_13 -> V_56 != V_54
&& F_46 () ) {
F_47 ( V_57 ,
L_5
L_6
L_7 ,
F_46 () ) ;
V_23 = - V_15 ;
} else if ( V_54 <= V_13 -> V_58 ) {
F_47 ( V_57 , L_8
L_9 ) ;
V_23 = - V_15 ;
} else {
V_13 -> V_56 = V_54 ;
}
}
return V_23 ;
}
static T_3 F_48 (
struct V_32 * V_33 , char * V_35 )
{
return sprintf ( V_35 , L_2 ,
F_14 ( V_33 ) -> V_58 ) ;
}
static T_3 F_49 (
struct V_32 * V_33 , const char * V_35 , T_4 V_38 )
{
struct V_12 * V_13 = F_14 ( V_33 ) ;
T_3 V_23 ;
unsigned int V_54 ;
V_23 = F_43 ( V_35 , V_38 , & V_54 ) ;
if ( V_23 > 0 ) {
if ( V_13 -> V_58 != V_54
&& F_46 () ) {
F_47 ( V_57 ,
L_10
L_11
L_7 ,
F_46 () ) ;
V_23 = - V_15 ;
} else if ( V_54 >= V_13 -> V_56 ) {
F_47 ( V_57 , L_12
L_13 ) ;
V_23 = - V_15 ;
} else {
V_13 -> V_58 = V_54 ;
}
}
return V_23 ;
}
static T_3 F_50 (
struct V_32 * V_33 , char * V_35 )
{
return sprintf ( V_35 , L_2 ,
F_14 ( V_33 ) -> V_59 ) ;
}
static T_3 F_51 (
struct V_32 * V_33 , const char * V_35 , T_4 V_38 )
{
return F_43 ( V_35 , V_38 ,
& F_14 ( V_33 ) -> V_59 ) ;
}
static T_3 F_52 (
struct V_32 * V_33 , char * V_35 )
{
struct V_12 * V_13 = F_14 ( V_33 ) ;
T_3 V_23 = 0 ;
if ( V_13 )
V_23 = sprintf ( V_35 , L_14 ,
V_60 [ V_13 -> V_61 ] ) ;
return V_23 ;
}
static T_3 F_53 (
struct V_32 * V_33 , const char * V_35 , T_4 V_38 )
{
unsigned int V_49 ;
if ( V_35 [ V_38 - 1 ] != '\n' )
goto V_62;
for ( V_49 = 0 ; V_49 < V_63 ; ++ V_49 ) {
if ( V_38 != strlen ( V_60 [ V_49 ] ) + 1 )
continue;
if ( strncasecmp ( V_35 , V_60 [ V_49 ] , V_38 - 1 ) )
continue;
if ( F_14 ( V_33 ) -> V_61 != V_49 ) {
F_54 ( V_64 L_15 ,
V_60 [ V_49 ] ) ;
F_14 ( V_33 ) -> V_61 = V_49 ;
}
return V_38 ;
}
V_62:
return - V_15 ;
}
static struct V_32 * F_55 ( struct V_65 * V_66 ,
const char * V_67 )
{
struct V_1 * V_3 = NULL ;
if ( strlen ( V_67 ) > V_68 )
return F_56 ( - V_69 ) ;
V_3 = F_57 ( sizeof( struct V_1 ) , V_70 ) ;
if ( V_3 == NULL )
return F_56 ( - V_71 ) ;
strcpy ( V_3 -> V_72 , V_67 ) ;
F_58 ( & V_3 -> V_9 , V_67 , & V_73 ) ;
F_59 ( & V_3 -> V_74 ) ;
F_47 ( V_75 , L_16 , V_67 ) ;
return & V_3 -> V_9 ;
}
static void F_60 ( struct V_65 * V_66 ,
struct V_32 * V_33 )
{
struct V_1 * V_3 = F_17 ( V_33 ) ;
struct V_12 * V_13 = F_14 ( V_66 -> V_76 . V_37 ) ;
F_61 ( V_3 ) ;
if ( V_13 -> V_30 &&
( V_13 -> V_31 == V_3 -> V_36 ) ) {
V_13 -> V_30 = 0 ;
V_13 -> V_31 = V_53 ;
F_42 ( V_3 ) ;
}
F_25 ( & V_13 -> V_7 ) ;
if ( V_3 -> V_26 )
F_62 ( & V_3 -> V_25 , & V_13 -> V_21 ) ;
if ( V_13 -> V_8 [ V_3 -> V_36 ] == V_3 ) {
V_13 -> V_8 [ V_3 -> V_36 ] = NULL ;
F_63 ( V_3 -> V_36 , V_13 -> V_14 ) ;
}
F_28 ( & V_13 -> V_7 ) ;
F_47 ( V_75 , L_17 ,
F_64 ( & V_3 -> V_9 ) ) ;
F_11 ( V_33 ) ;
}
static void F_65 ( struct V_32 * V_33 )
{
struct V_12 * V_13 = F_14 ( V_33 ) ;
F_19 ( V_13 -> V_34 . V_77 ) ;
F_19 ( V_13 ) ;
}
static struct V_65 * F_66 ( struct V_65 * V_66 ,
const char * V_67 )
{
struct V_12 * V_13 = NULL ;
struct V_78 * V_79 = NULL ;
struct V_65 * V_80 = NULL , * V_23 = NULL ;
void * V_81 = NULL ;
if ( V_5 )
return F_56 ( - V_82 ) ;
V_13 = F_57 ( sizeof( struct V_12 ) , V_70 ) ;
V_79 = F_57 ( sizeof( struct V_78 ) , V_70 ) ;
V_81 = F_67 ( 3 , sizeof( struct V_65 * ) , V_70 ) ;
V_80 = F_68 () ;
if ( V_13 == NULL || V_79 == NULL || V_80 == NULL || V_81 == NULL )
goto V_6;
F_69 ( & V_13 -> V_34 , V_67 ,
& V_83 ) ;
F_69 ( & V_79 -> V_84 , L_18 ,
& V_85 ) ;
V_13 -> V_34 . V_77 = V_81 ;
V_13 -> V_34 . V_77 [ 0 ] = & V_79 -> V_84 ;
V_13 -> V_34 . V_77 [ 1 ] = V_80 ;
V_13 -> V_34 . V_77 [ 2 ] = NULL ;
F_70 ( & V_13 -> V_7 ) ;
V_13 -> V_21 = V_86 ;
V_13 -> V_59 = V_87 ;
V_13 -> V_56 = V_88 ;
V_13 -> V_58 = V_89 ;
V_13 -> V_61 = V_90 ;
V_23 = & V_13 -> V_34 ;
V_5 = V_13 ;
V_6:
if ( V_23 == NULL ) {
F_19 ( V_13 ) ;
F_19 ( V_79 ) ;
F_71 ( V_80 ) ;
F_19 ( V_81 ) ;
V_23 = F_56 ( - V_71 ) ;
}
return V_23 ;
}
static void F_72 ( struct V_65 * V_66 , struct V_32 * V_33 )
{
struct V_12 * V_13 = F_14 ( V_33 ) ;
int V_49 ;
struct V_32 * V_91 ;
F_6 ( V_5 != V_13 ) ;
V_5 = NULL ;
for ( V_49 = 0 ; V_13 -> V_34 . V_77 [ V_49 ] ; V_49 ++ ) {
V_91 = & V_13 -> V_34 . V_77 [ V_49 ] -> V_76 ;
V_13 -> V_34 . V_77 [ V_49 ] = NULL ;
F_11 ( V_91 ) ;
}
F_11 ( V_33 ) ;
}
int F_73 ( struct V_32 * V_33 )
{
return F_74 ( & V_92 . V_93 , V_33 ) ;
}
void F_75 ( struct V_32 * V_33 )
{
F_76 ( & V_92 . V_93 , V_33 ) ;
}
int F_77 ( void )
{
int V_23 = 0 ;
struct V_1 * V_94 ;
V_94 = F_1 ( F_13 () ) ;
if ( ! V_94 ) {
V_23 = - V_15 ;
goto V_6;
}
V_23 = F_73 ( & V_94 -> V_9 ) ;
F_10 ( V_94 ) ;
V_6:
return V_23 ;
}
void F_78 ( void )
{
struct V_1 * V_94 ;
V_94 = F_1 ( F_13 () ) ;
F_6 ( ! V_94 ) ;
F_75 ( & V_94 -> V_9 ) ;
F_10 ( V_94 ) ;
}
static void T_5 F_79 ( void )
{
F_80 () ;
F_81 ( & V_92 . V_93 ) ;
F_82 () ;
F_83 () ;
F_84 () ;
}
static int T_6 F_85 ( void )
{
int V_23 = - 1 ;
V_23 = F_86 () ;
if ( V_23 )
goto V_6;
V_23 = F_87 () ;
if ( V_23 )
goto V_95;
V_23 = F_88 () ;
if ( V_23 )
goto V_96;
F_89 ( & V_92 . V_93 . V_97 ) ;
F_90 ( & V_92 . V_93 . V_98 ) ;
V_23 = F_91 ( & V_92 . V_93 ) ;
if ( V_23 ) {
F_54 ( V_99 L_19 , V_23 ) ;
goto V_100;
}
V_23 = F_92 () ;
if ( ! V_23 )
goto V_6;
F_81 ( & V_92 . V_93 ) ;
V_100:
F_80 () ;
V_96:
F_83 () ;
V_95:
F_84 () ;
V_6:
return V_23 ;
}
