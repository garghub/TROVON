int F_1 ( void )
{
return V_1 ;
}
int F_2 ( void )
{
return V_2 ;
}
int F_3 ( void )
{
return V_3 ;
}
int F_4 ( void )
{
return V_4 ;
}
static int F_5 ( const char * V_5 , struct V_6 * V_7 )
{
unsigned long V_8 ;
int V_9 ;
if ( ! V_5 )
return - V_10 ;
V_9 = F_6 ( V_5 , 0 , & V_8 ) ;
if ( V_9 )
return V_9 ;
if ( V_8 < 1000 )
return - V_10 ;
* ( ( unsigned long * ) V_7 -> V_11 ) = V_8 ;
F_7 ( V_8 ) ;
return 0 ;
}
static T_1 F_8 ( struct V_12 * V_13 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_17 * V_18 = F_9 ( V_13 ) ;
return sprintf ( V_16 , L_1 , V_18 -> V_19 ) ;
}
static T_1 F_10 ( struct V_12 * V_13 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_17 * V_18 = F_9 ( V_13 ) ;
return sprintf ( V_16 , L_1 , V_18 -> V_20 ) ;
}
static T_1 F_11 ( struct V_12 * V_13 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_17 * V_18 = F_9 ( V_13 ) ;
int V_21 ;
T_2 V_22 = 0 ;
for ( V_21 = 0 ; V_21 < V_18 -> V_23 ; V_21 ++ )
V_22 += V_18 -> V_24 [ V_21 ] -> V_25 -> V_22 ;
return sprintf ( V_16 , L_1 , F_12 ( V_22 ) ) ;
}
static T_1 F_13 ( struct V_12 * V_13 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_17 * V_18 = F_9 ( V_13 ) ;
return sprintf ( V_16 , L_2 , V_26 [ V_18 -> V_24 [ 0 ] -> V_25 -> V_27 ] ) ;
}
static T_1 F_14 ( struct V_12 * V_13 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_17 * V_18 = F_9 ( V_13 ) ;
return sprintf ( V_16 , L_2 , V_28 [ V_18 -> V_24 [ 0 ] -> V_25 -> V_29 ] ) ;
}
static T_1 F_15 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_17 * V_18 = F_9 ( V_13 ) ;
return sprintf ( V_16 , L_2 , V_30 [ V_18 -> V_24 [ 0 ] -> V_25 -> V_31 ] ) ;
}
static T_1 F_16 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_17 * V_18 = F_9 ( V_13 ) ;
unsigned V_32 = F_17 ( V_15 ) ;
struct V_33 * V_34 = V_18 -> V_24 [ V_32 ] ;
if ( ! V_34 -> V_25 -> V_35 [ 0 ] )
return 0 ;
return snprintf ( V_16 , V_36 , L_2 ,
V_34 -> V_25 -> V_35 ) ;
}
static T_1 F_18 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
const char * V_16 , T_3 V_37 )
{
struct V_17 * V_18 = F_9 ( V_13 ) ;
unsigned V_32 = F_17 ( V_15 ) ;
struct V_33 * V_34 = V_18 -> V_24 [ V_32 ] ;
T_1 V_38 = 0 ;
V_38 = F_19 ( ( T_1 ) V_37 , ( T_1 ) V_36 - 1 ) ;
strncpy ( V_34 -> V_25 -> V_35 , V_16 , V_38 ) ;
V_34 -> V_25 -> V_35 [ V_38 ] = '\0' ;
return V_38 ;
}
static T_1 F_20 ( struct V_12 * V_13 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_17 * V_18 = F_9 ( V_13 ) ;
unsigned V_32 = F_17 ( V_15 ) ;
struct V_33 * V_34 = V_18 -> V_24 [ V_32 ] ;
return sprintf ( V_16 , L_1 , V_34 -> V_20 ) ;
}
static void F_21 ( struct V_12 * V_13 )
{
struct V_17 * V_18 = F_22 ( V_13 , struct V_17 , V_13 ) ;
F_23 ( 1 , L_3 , F_24 ( V_13 ) ) ;
F_25 ( V_18 ) ;
}
static inline int F_26 ( struct V_17 * V_18 )
{
int V_32 , V_22 = 0 ;
for ( V_32 = 0 ; V_32 < V_18 -> V_23 ; V_32 ++ )
V_22 += V_18 -> V_24 [ V_32 ] -> V_25 -> V_22 ;
return V_22 ;
}
static int F_27 ( struct V_39 * V_40 ,
struct V_17 * V_18 , int V_41 )
{
int V_42 , V_32 ;
if ( V_18 -> V_23 >= V_43 )
return - V_44 ;
V_18 -> V_13 . type = & V_45 ;
V_18 -> V_13 . V_46 = V_40 -> V_46 ;
F_28 ( & V_18 -> V_13 ) ;
V_18 -> V_13 . V_47 = & V_40 -> V_13 ;
V_18 -> V_40 = V_40 ;
F_29 ( & V_18 -> V_13 , L_4 , V_41 ) ;
F_30 ( & V_18 -> V_13 , V_18 ) ;
F_23 ( 0 , L_5 ,
F_24 ( & V_18 -> V_13 ) ) ;
V_42 = F_31 ( & V_18 -> V_13 ) ;
if ( V_42 < 0 )
return V_42 ;
for ( V_32 = 0 ; V_32 < V_18 -> V_23 ; V_32 ++ ) {
if ( ! V_18 -> V_24 [ V_32 ] -> V_25 -> V_22 )
continue;
V_42 = F_32 ( & V_18 -> V_13 ,
V_48 [ V_32 ] ) ;
if ( V_42 < 0 )
goto error;
V_42 = F_32 ( & V_18 -> V_13 ,
V_49 [ V_32 ] ) ;
if ( V_42 < 0 ) {
F_33 ( & V_18 -> V_13 ,
V_48 [ V_32 ] ) ;
goto error;
}
}
return 0 ;
error:
for ( -- V_32 ; V_32 >= 0 ; V_32 -- ) {
F_33 ( & V_18 -> V_13 ,
V_48 [ V_32 ] ) ;
F_33 ( & V_18 -> V_13 ,
V_49 [ V_32 ] ) ;
}
F_34 ( & V_18 -> V_13 ) ;
return V_42 ;
}
static int F_35 ( struct V_39 * V_40 )
{
int V_42 , V_21 , V_32 ;
struct V_17 * V_18 ;
for ( V_21 = 0 ; V_21 < V_40 -> V_50 ; V_21 ++ ) {
V_18 = V_40 -> V_51 [ V_21 ] ;
if ( ! F_26 ( V_18 ) )
continue;
V_42 = F_27 ( V_40 , V_40 -> V_51 [ V_21 ] , V_21 ) ;
if ( V_42 < 0 ) {
F_23 ( 1 ,
L_6 ,
V_21 ) ;
goto error;
}
}
return 0 ;
error:
for ( -- V_21 ; V_21 >= 0 ; V_21 -- ) {
V_18 = V_40 -> V_51 [ V_21 ] ;
if ( ! F_26 ( V_18 ) )
continue;
for ( V_32 = V_18 -> V_23 - 1 ; V_32 >= 0 ; V_32 -- ) {
if ( ! V_18 -> V_24 [ V_32 ] -> V_25 -> V_22 )
continue;
F_33 ( & V_18 -> V_13 ,
V_48 [ V_32 ] ) ;
F_33 ( & V_18 -> V_13 ,
V_49 [ V_32 ] ) ;
}
F_34 ( & V_40 -> V_51 [ V_21 ] -> V_13 ) ;
}
return V_42 ;
}
static void F_36 ( struct V_39 * V_40 )
{
int V_21 , V_32 ;
struct V_17 * V_18 ;
for ( V_21 = V_40 -> V_50 - 1 ; V_21 >= 0 ; V_21 -- ) {
V_18 = V_40 -> V_51 [ V_21 ] ;
if ( ! F_26 ( V_18 ) )
continue;
for ( V_32 = V_18 -> V_23 - 1 ; V_32 >= 0 ; V_32 -- ) {
if ( ! V_18 -> V_24 [ V_32 ] -> V_25 -> V_22 )
continue;
F_23 ( 1 , L_7 ,
V_21 , V_32 ) ;
F_33 ( & V_18 -> V_13 ,
V_48 [ V_32 ] ) ;
F_33 ( & V_18 -> V_13 ,
V_49 [ V_32 ] ) ;
}
F_37 ( & V_40 -> V_51 [ V_21 ] -> V_13 ) ;
}
}
static T_1 F_38 ( struct V_12 * V_13 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_52 * V_25 = F_39 ( V_13 ) ;
return F_40 ( V_25 , V_16 , V_53 ) ;
}
static T_1 F_41 ( struct V_12 * V_13 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_52 * V_25 = F_39 ( V_13 ) ;
if ( ! V_25 -> V_35 [ 0 ] )
return 0 ;
return snprintf ( V_16 , V_36 , L_2 , V_25 -> V_35 ) ;
}
static T_1 F_42 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
const char * V_16 ,
T_3 V_37 )
{
struct V_52 * V_25 = F_39 ( V_13 ) ;
T_1 V_38 = 0 ;
V_38 = F_19 ( ( T_1 ) V_37 , ( T_1 ) V_36 - 1 ) ;
strncpy ( V_25 -> V_35 , V_16 , V_38 ) ;
V_25 -> V_35 [ V_38 ] = '\0' ;
return V_38 ;
}
static T_1 F_43 ( struct V_12 * V_13 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_52 * V_25 = F_39 ( V_13 ) ;
return sprintf ( V_16 , L_1 , F_12 ( V_25 -> V_22 ) ) ;
}
static T_1 F_44 ( struct V_12 * V_13 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_52 * V_25 = F_39 ( V_13 ) ;
return sprintf ( V_16 , L_2 , V_26 [ V_25 -> V_27 ] ) ;
}
static T_1 F_45 ( struct V_12 * V_13 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_52 * V_25 = F_39 ( V_13 ) ;
return sprintf ( V_16 , L_2 , V_28 [ V_25 -> V_29 ] ) ;
}
static T_1 F_46 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_52 * V_25 = F_39 ( V_13 ) ;
return sprintf ( V_16 , L_2 , V_30 [ V_25 -> V_31 ] ) ;
}
static void F_47 ( struct V_12 * V_13 )
{
struct V_52 * V_25 = F_22 ( V_13 , struct V_52 , V_13 ) ;
F_23 ( 1 , L_8 , F_24 ( V_13 ) ) ;
F_25 ( V_25 ) ;
}
static int F_48 ( struct V_39 * V_40 ,
struct V_52 * V_25 ,
int V_41 )
{
int V_42 ;
V_25 -> V_40 = V_40 ;
V_25 -> V_13 . type = & V_54 ;
V_25 -> V_13 . V_46 = V_40 -> V_46 ;
F_28 ( & V_25 -> V_13 ) ;
V_25 -> V_13 . V_47 = & V_40 -> V_13 ;
if ( V_40 -> V_55 )
F_29 ( & V_25 -> V_13 , L_9 , V_41 ) ;
else
F_29 ( & V_25 -> V_13 , L_10 , V_41 ) ;
F_30 ( & V_25 -> V_13 , V_25 ) ;
F_49 ( & V_40 -> V_13 ) ;
V_42 = F_31 ( & V_25 -> V_13 ) ;
F_23 ( 0 , L_11 , F_24 ( & V_25 -> V_13 ) ) ;
return V_42 ;
}
static T_1 F_50 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
const char * V_16 , T_3 V_37 )
{
struct V_39 * V_40 = F_51 ( V_13 ) ;
int V_56 , V_57 , V_32 , V_21 ;
V_40 -> V_58 = 0 ;
V_40 -> V_59 = 0 ;
V_40 -> V_60 = 0 ;
V_40 -> V_61 = 0 ;
for ( V_57 = 0 ; V_57 < V_40 -> V_50 ; V_57 ++ ) {
struct V_17 * V_62 = V_40 -> V_51 [ V_57 ] ;
V_62 -> V_19 = 0 ;
V_62 -> V_20 = 0 ;
for ( V_32 = 0 ; V_32 < V_62 -> V_23 ; V_32 ++ )
V_62 -> V_24 [ V_32 ] -> V_20 = 0 ;
}
V_56 = 1 ;
for ( V_21 = 0 ; V_21 < V_40 -> V_63 ; V_21 ++ ) {
V_56 *= V_40 -> V_64 [ V_21 ] . V_65 ;
memset ( V_40 -> V_66 [ V_21 ] , 0 , V_56 * sizeof( T_2 ) ) ;
memset ( V_40 -> V_67 [ V_21 ] , 0 , V_56 * sizeof( T_2 ) ) ;
}
V_40 -> V_68 = V_69 ;
return V_37 ;
}
static T_1 F_52 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
const char * V_16 , T_3 V_37 )
{
struct V_39 * V_40 = F_51 ( V_13 ) ;
unsigned long V_70 = 0 ;
int V_71 = 0 ;
if ( F_6 ( V_16 , 10 , & V_70 ) < 0 )
return - V_10 ;
V_71 = V_40 -> V_72 ( V_40 , V_70 ) ;
if ( V_71 < 0 ) {
F_53 ( V_73 , V_74 ,
L_12 , V_70 ) ;
return - V_10 ;
}
return V_37 ;
}
static T_1 F_54 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_39 * V_40 = F_51 ( V_13 ) ;
int V_70 = 0 ;
V_70 = V_40 -> V_75 ( V_40 ) ;
if ( V_70 < 0 ) {
F_53 ( V_76 , V_74 , L_13 ) ;
return V_70 ;
}
return sprintf ( V_16 , L_14 , V_70 ) ;
}
static T_1 F_55 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_39 * V_40 = F_51 ( V_13 ) ;
return sprintf ( V_16 , L_14 , V_40 -> V_58 ) ;
}
static T_1 F_56 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_39 * V_40 = F_51 ( V_13 ) ;
return sprintf ( V_16 , L_14 , V_40 -> V_59 ) ;
}
static T_1 F_57 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_39 * V_40 = F_51 ( V_13 ) ;
return sprintf ( V_16 , L_14 , V_40 -> V_61 ) ;
}
static T_1 F_58 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_39 * V_40 = F_51 ( V_13 ) ;
return sprintf ( V_16 , L_14 , V_40 -> V_60 ) ;
}
static T_1 F_59 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_39 * V_40 = F_51 ( V_13 ) ;
return sprintf ( V_16 , L_15 , ( V_69 - V_40 -> V_68 ) / V_77 ) ;
}
static T_1 F_60 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_39 * V_40 = F_51 ( V_13 ) ;
return sprintf ( V_16 , L_2 , V_40 -> V_78 ) ;
}
static T_1 F_61 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_39 * V_40 = F_51 ( V_13 ) ;
int V_79 = 0 , V_80 , V_81 ;
for ( V_80 = 0 ; V_80 < V_40 -> V_50 ; V_80 ++ ) {
struct V_17 * V_18 = V_40 -> V_51 [ V_80 ] ;
for ( V_81 = 0 ; V_81 < V_18 -> V_23 ; V_81 ++ ) {
struct V_52 * V_25 = V_18 -> V_24 [ V_81 ] -> V_25 ;
V_79 += V_25 -> V_22 ;
}
}
return sprintf ( V_16 , L_1 , F_12 ( V_79 ) ) ;
}
static T_1 F_62 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_39 * V_40 = F_51 ( V_13 ) ;
int V_21 ;
char * V_82 = V_16 ;
for ( V_21 = 0 ; V_21 < V_40 -> V_63 ; V_21 ++ ) {
V_82 += sprintf ( V_82 , L_16 ,
V_83 [ V_40 -> V_64 [ V_21 ] . type ] ,
V_40 -> V_64 [ V_21 ] . V_65 - 1 ) ;
}
return V_82 - V_16 ;
}
static T_1 F_63 ( struct V_84 * V_84 ,
const char T_4 * V_16 ,
T_3 V_37 , T_5 * V_85 )
{
struct V_12 * V_13 = V_84 -> V_86 ;
struct V_39 * V_40 = F_51 ( V_13 ) ;
static enum V_87 type ;
T_6 V_88 = V_40 -> V_89 ;
if ( ! V_88 )
V_88 = 1 ;
type = V_40 -> V_90 ? V_91
: V_92 ;
F_64 ( V_76
L_17 ,
V_88 ,
( type == V_91 ) ? L_18 : L_19 ,
V_88 > 1 ? L_20 : L_21 ,
V_40 -> V_93 [ 0 ] ,
V_40 -> V_93 [ 1 ] ,
V_40 -> V_93 [ 2 ]
) ;
F_65 ( type , V_40 , V_88 , 0 , 0 , 0 ,
V_40 -> V_93 [ 0 ] ,
V_40 -> V_93 [ 1 ] ,
V_40 -> V_93 [ 2 ] ,
L_22 , L_23 ) ;
return V_37 ;
}
static void F_66 ( struct V_12 * V_13 )
{
struct V_39 * V_40 = F_22 ( V_13 , struct V_39 , V_13 ) ;
F_23 ( 1 , L_3 , F_24 ( V_13 ) ) ;
F_25 ( V_40 ) ;
}
int T_7 F_67 ( void )
{
V_94 = F_68 ( L_24 , NULL ) ;
if ( F_69 ( V_94 ) ) {
V_94 = NULL ;
return - V_95 ;
}
return 0 ;
}
void T_8 F_70 ( void )
{
F_71 ( V_94 ) ;
}
static int F_72 ( struct V_39 * V_40 )
{
struct V_96 * V_97 , * V_47 ;
char V_98 [ 80 ] ;
int V_21 ;
if ( ! V_94 )
return - V_44 ;
V_97 = F_68 ( V_40 -> V_13 . V_99 . V_98 , V_94 ) ;
if ( ! V_97 )
return - V_95 ;
V_47 = V_97 ;
for ( V_21 = 0 ; V_21 < V_40 -> V_63 ; V_21 ++ ) {
sprintf ( V_98 , L_25 ,
V_83 [ V_40 -> V_64 [ V_21 ] . type ] ) ;
V_97 = F_73 ( V_98 , V_100 | V_101 , V_47 ,
& V_40 -> V_93 [ V_21 ] ) ;
if ( ! V_97 )
goto V_102;
}
V_97 = F_74 ( L_26 , V_100 | V_101 , V_47 ,
& V_40 -> V_90 ) ;
if ( ! V_97 )
goto V_102;
V_97 = F_75 ( L_27 , V_100 | V_101 , V_47 ,
& V_40 -> V_89 ) ;
if ( ! V_97 )
goto V_102;
V_97 = F_76 ( L_28 , V_101 , V_47 ,
& V_40 -> V_13 ,
& V_103 ) ;
if ( ! V_97 )
goto V_102;
V_40 -> V_104 = V_47 ;
return 0 ;
V_102:
F_71 ( V_40 -> V_104 ) ;
return - V_95 ;
}
int F_77 ( struct V_39 * V_40 )
{
int V_21 , V_42 ;
V_40 -> V_46 -> V_98 = F_78 ( V_105 , L_29 , V_40 -> V_106 ) ;
if ( ! V_40 -> V_46 -> V_98 )
return - V_95 ;
F_23 ( 0 , L_30 , V_40 -> V_46 -> V_98 ) ;
V_42 = F_79 ( V_40 -> V_46 ) ;
if ( V_42 < 0 )
return V_42 ;
V_40 -> V_13 . type = & V_107 ;
F_28 ( & V_40 -> V_13 ) ;
V_40 -> V_13 . V_47 = V_108 ;
V_40 -> V_13 . V_46 = V_40 -> V_46 ;
F_29 ( & V_40 -> V_13 , L_29 , V_40 -> V_106 ) ;
F_30 ( & V_40 -> V_13 , V_40 ) ;
F_49 ( & V_40 -> V_13 ) ;
F_23 ( 0 , L_31 , F_24 ( & V_40 -> V_13 ) ) ;
V_42 = F_31 ( & V_40 -> V_13 ) ;
if ( V_42 < 0 ) {
F_23 ( 1 , L_32 , F_24 ( & V_40 -> V_13 ) ) ;
F_80 ( V_40 -> V_46 ) ;
F_25 ( V_40 -> V_46 -> V_98 ) ;
return V_42 ;
}
if ( V_40 -> V_72 || V_40 -> V_75 ) {
if ( V_40 -> V_75 ) {
V_109 . V_110 . V_111 |= V_100 ;
V_109 . V_112 = & F_54 ;
}
if ( V_40 -> V_72 ) {
V_109 . V_110 . V_111 |= V_101 ;
V_109 . V_113 = & F_52 ;
}
V_42 = F_32 ( & V_40 -> V_13 ,
& V_109 ) ;
if ( V_42 ) {
F_23 ( 1 , L_33 ) ;
goto V_114;
}
}
for ( V_21 = 0 ; V_21 < V_40 -> V_115 ; V_21 ++ ) {
struct V_52 * V_25 = V_40 -> V_116 [ V_21 ] ;
if ( V_25 -> V_22 == 0 )
continue;
#ifdef F_81
F_23 ( 1 , L_34 , V_21 ) ;
if ( V_117 >= 1 ) {
int V_118 ;
for ( V_118 = 0 ; V_118 < V_40 -> V_63 ; V_118 ++ )
F_64 ( V_119 L_16 ,
V_83 [ V_40 -> V_64 [ V_118 ] . type ] ,
V_25 -> V_120 [ V_118 ] ) ;
F_64 ( V_119 L_35 ) ;
}
#endif
V_42 = F_48 ( V_40 , V_25 , V_21 ) ;
if ( V_42 ) {
F_23 ( 1 , L_36 , V_21 ) ;
goto V_121;
}
}
#ifdef F_82
V_42 = F_35 ( V_40 ) ;
if ( V_42 < 0 )
goto V_121;
#endif
#ifdef F_81
F_72 ( V_40 ) ;
#endif
return 0 ;
V_121:
for ( V_21 -- ; V_21 >= 0 ; V_21 -- ) {
struct V_52 * V_25 = V_40 -> V_116 [ V_21 ] ;
if ( V_25 -> V_22 == 0 )
continue;
F_37 ( & V_25 -> V_13 ) ;
}
V_114:
F_37 ( & V_40 -> V_13 ) ;
F_80 ( V_40 -> V_46 ) ;
F_25 ( V_40 -> V_46 -> V_98 ) ;
return V_42 ;
}
void F_83 ( struct V_39 * V_40 )
{
int V_21 ;
F_23 ( 0 , L_35 ) ;
#ifdef F_81
F_71 ( V_40 -> V_104 ) ;
#endif
#ifdef F_82
F_36 ( V_40 ) ;
#endif
for ( V_21 = 0 ; V_21 < V_40 -> V_115 ; V_21 ++ ) {
struct V_52 * V_25 = V_40 -> V_116 [ V_21 ] ;
if ( V_25 -> V_22 == 0 )
continue;
F_23 ( 0 , L_37 , F_24 ( & V_25 -> V_13 ) ) ;
F_37 ( & V_25 -> V_13 ) ;
}
}
void F_84 ( struct V_39 * V_40 )
{
F_23 ( 1 , L_38 , F_24 ( & V_40 -> V_13 ) ) ;
F_37 ( & V_40 -> V_13 ) ;
F_80 ( V_40 -> V_46 ) ;
F_25 ( V_40 -> V_46 -> V_98 ) ;
}
static void F_85 ( struct V_12 * V_13 )
{
F_23 ( 1 , L_39 , F_24 ( V_13 ) ) ;
F_25 ( V_13 ) ;
}
int T_7 F_86 ( void )
{
struct V_122 * V_123 ;
int V_42 ;
V_123 = F_87 () ;
if ( V_123 == NULL ) {
F_23 ( 1 , L_40 ) ;
V_42 = - V_10 ;
goto V_124;
}
V_108 = F_88 ( sizeof( * V_108 ) , V_105 ) ;
if ( ! V_108 ) {
V_42 = - V_95 ;
goto V_125;
}
V_108 -> V_46 = V_123 ;
V_108 -> type = & V_126 ;
F_28 ( V_108 ) ;
F_29 ( V_108 , L_41 ) ;
V_42 = F_31 ( V_108 ) ;
if ( V_42 < 0 )
goto V_127;
F_23 ( 0 , L_42 , F_24 ( V_108 ) ) ;
return 0 ;
V_127:
F_25 ( V_108 ) ;
V_125:
F_89 () ;
V_124:
return V_42 ;
}
void T_8 F_90 ( void )
{
F_37 ( V_108 ) ;
F_89 () ;
}
