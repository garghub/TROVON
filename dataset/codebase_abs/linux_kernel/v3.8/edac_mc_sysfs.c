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
long V_8 ;
int V_9 ;
if ( ! V_5 )
return - V_10 ;
V_9 = F_6 ( V_5 , 0 , & V_8 ) ;
if ( V_9 == - V_10 || ( ( int ) V_8 != V_8 ) )
return - V_10 ;
* ( ( int * ) V_7 -> V_11 ) = V_8 ;
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
if ( V_18 -> V_23 -> V_24 )
return sprintf ( V_16 , L_1 , F_12 ( V_18 -> V_22 ) ) ;
for ( V_21 = 0 ; V_21 < V_18 -> V_25 ; V_21 ++ )
V_22 += V_18 -> V_26 [ V_21 ] -> V_27 -> V_22 ;
return sprintf ( V_16 , L_1 , F_12 ( V_22 ) ) ;
}
static T_1 F_13 ( struct V_12 * V_13 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_17 * V_18 = F_9 ( V_13 ) ;
return sprintf ( V_16 , L_2 , V_28 [ V_18 -> V_26 [ 0 ] -> V_27 -> V_29 ] ) ;
}
static T_1 F_14 ( struct V_12 * V_13 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_17 * V_18 = F_9 ( V_13 ) ;
return sprintf ( V_16 , L_2 , V_30 [ V_18 -> V_26 [ 0 ] -> V_27 -> V_31 ] ) ;
}
static T_1 F_15 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_17 * V_18 = F_9 ( V_13 ) ;
return sprintf ( V_16 , L_2 , V_32 [ V_18 -> V_26 [ 0 ] -> V_27 -> V_33 ] ) ;
}
static T_1 F_16 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_17 * V_18 = F_9 ( V_13 ) ;
unsigned V_34 = F_17 ( V_15 ) ;
struct V_35 * V_36 = V_18 -> V_26 [ V_34 ] ;
if ( ! V_36 -> V_27 -> V_37 [ 0 ] )
return 0 ;
return snprintf ( V_16 , V_38 , L_2 ,
V_36 -> V_27 -> V_37 ) ;
}
static T_1 F_18 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
const char * V_16 , T_3 V_39 )
{
struct V_17 * V_18 = F_9 ( V_13 ) ;
unsigned V_34 = F_17 ( V_15 ) ;
struct V_35 * V_36 = V_18 -> V_26 [ V_34 ] ;
T_1 V_40 = 0 ;
V_40 = F_19 ( ( T_1 ) V_39 , ( T_1 ) V_38 - 1 ) ;
strncpy ( V_36 -> V_27 -> V_37 , V_16 , V_40 ) ;
V_36 -> V_27 -> V_37 [ V_40 ] = '\0' ;
return V_40 ;
}
static T_1 F_20 ( struct V_12 * V_13 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_17 * V_18 = F_9 ( V_13 ) ;
unsigned V_34 = F_17 ( V_15 ) ;
struct V_35 * V_36 = V_18 -> V_26 [ V_34 ] ;
return sprintf ( V_16 , L_1 , V_36 -> V_20 ) ;
}
static void F_21 ( struct V_12 * V_13 )
{
struct V_17 * V_18 = F_22 ( V_13 , struct V_17 , V_13 ) ;
F_23 ( 1 , L_3 , F_24 ( V_13 ) ) ;
F_25 ( V_18 ) ;
}
static inline int F_26 ( struct V_17 * V_18 )
{
int V_34 , V_22 = 0 ;
for ( V_34 = 0 ; V_34 < V_18 -> V_25 ; V_34 ++ )
V_22 += V_18 -> V_26 [ V_34 ] -> V_27 -> V_22 ;
return V_22 ;
}
static int F_27 ( struct V_41 * V_23 ,
struct V_17 * V_18 , int V_42 )
{
int V_43 , V_34 ;
if ( V_18 -> V_25 >= V_44 )
return - V_45 ;
V_18 -> V_13 . type = & V_46 ;
V_18 -> V_13 . V_47 = & V_23 -> V_47 ;
F_28 ( & V_18 -> V_13 ) ;
V_18 -> V_13 . V_48 = & V_23 -> V_13 ;
V_18 -> V_23 = V_23 ;
F_29 ( & V_18 -> V_13 , L_4 , V_42 ) ;
F_30 ( & V_18 -> V_13 , V_18 ) ;
F_23 ( 0 , L_5 ,
F_24 ( & V_18 -> V_13 ) ) ;
V_43 = F_31 ( & V_18 -> V_13 ) ;
if ( V_43 < 0 )
return V_43 ;
for ( V_34 = 0 ; V_34 < V_18 -> V_25 ; V_34 ++ ) {
if ( ! V_18 -> V_26 [ V_34 ] -> V_27 -> V_22 )
continue;
V_43 = F_32 ( & V_18 -> V_13 ,
V_49 [ V_34 ] ) ;
if ( V_43 < 0 )
goto error;
V_43 = F_32 ( & V_18 -> V_13 ,
V_50 [ V_34 ] ) ;
if ( V_43 < 0 ) {
F_33 ( & V_18 -> V_13 ,
V_49 [ V_34 ] ) ;
goto error;
}
}
return 0 ;
error:
for ( -- V_34 ; V_34 >= 0 ; V_34 -- ) {
F_33 ( & V_18 -> V_13 ,
V_49 [ V_34 ] ) ;
F_33 ( & V_18 -> V_13 ,
V_50 [ V_34 ] ) ;
}
F_34 ( & V_18 -> V_13 ) ;
return V_43 ;
}
static int F_35 ( struct V_41 * V_23 )
{
int V_43 , V_21 , V_34 ;
struct V_17 * V_18 ;
for ( V_21 = 0 ; V_21 < V_23 -> V_51 ; V_21 ++ ) {
V_18 = V_23 -> V_52 [ V_21 ] ;
if ( ! F_26 ( V_18 ) )
continue;
V_43 = F_27 ( V_23 , V_23 -> V_52 [ V_21 ] , V_21 ) ;
if ( V_43 < 0 )
goto error;
}
return 0 ;
error:
for ( -- V_21 ; V_21 >= 0 ; V_21 -- ) {
V_18 = V_23 -> V_52 [ V_21 ] ;
if ( ! F_26 ( V_18 ) )
continue;
for ( V_34 = V_18 -> V_25 - 1 ; V_34 >= 0 ; V_34 -- ) {
if ( ! V_18 -> V_26 [ V_34 ] -> V_27 -> V_22 )
continue;
F_33 ( & V_18 -> V_13 ,
V_49 [ V_34 ] ) ;
F_33 ( & V_18 -> V_13 ,
V_50 [ V_34 ] ) ;
}
F_34 ( & V_23 -> V_52 [ V_21 ] -> V_13 ) ;
}
return V_43 ;
}
static void F_36 ( struct V_41 * V_23 )
{
int V_21 , V_34 ;
struct V_17 * V_18 ;
for ( V_21 = V_23 -> V_51 - 1 ; V_21 >= 0 ; V_21 -- ) {
V_18 = V_23 -> V_52 [ V_21 ] ;
if ( ! F_26 ( V_18 ) )
continue;
for ( V_34 = V_18 -> V_25 - 1 ; V_34 >= 0 ; V_34 -- ) {
if ( ! V_18 -> V_26 [ V_34 ] -> V_27 -> V_22 )
continue;
F_23 ( 1 , L_6 ,
V_21 , V_34 ) ;
F_33 ( & V_18 -> V_13 ,
V_49 [ V_34 ] ) ;
F_33 ( & V_18 -> V_13 ,
V_50 [ V_34 ] ) ;
}
F_37 ( & V_23 -> V_52 [ V_21 ] -> V_13 ) ;
}
}
static T_1 F_38 ( struct V_12 * V_13 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_53 * V_27 = F_39 ( V_13 ) ;
return F_40 ( V_27 , V_16 , V_54 ) ;
}
static T_1 F_41 ( struct V_12 * V_13 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_53 * V_27 = F_39 ( V_13 ) ;
if ( ! V_27 -> V_37 [ 0 ] )
return 0 ;
return snprintf ( V_16 , V_38 , L_2 , V_27 -> V_37 ) ;
}
static T_1 F_42 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
const char * V_16 ,
T_3 V_39 )
{
struct V_53 * V_27 = F_39 ( V_13 ) ;
T_1 V_40 = 0 ;
V_40 = F_19 ( ( T_1 ) V_39 , ( T_1 ) V_38 - 1 ) ;
strncpy ( V_27 -> V_37 , V_16 , V_40 ) ;
V_27 -> V_37 [ V_40 ] = '\0' ;
return V_40 ;
}
static T_1 F_43 ( struct V_12 * V_13 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_53 * V_27 = F_39 ( V_13 ) ;
return sprintf ( V_16 , L_1 , F_12 ( V_27 -> V_22 ) ) ;
}
static T_1 F_44 ( struct V_12 * V_13 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_53 * V_27 = F_39 ( V_13 ) ;
return sprintf ( V_16 , L_2 , V_28 [ V_27 -> V_29 ] ) ;
}
static T_1 F_45 ( struct V_12 * V_13 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_53 * V_27 = F_39 ( V_13 ) ;
return sprintf ( V_16 , L_2 , V_30 [ V_27 -> V_31 ] ) ;
}
static T_1 F_46 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_53 * V_27 = F_39 ( V_13 ) ;
return sprintf ( V_16 , L_2 , V_32 [ V_27 -> V_33 ] ) ;
}
static void F_47 ( struct V_12 * V_13 )
{
struct V_53 * V_27 = F_22 ( V_13 , struct V_53 , V_13 ) ;
F_23 ( 1 , L_7 , F_24 ( V_13 ) ) ;
F_25 ( V_27 ) ;
}
static int F_48 ( struct V_41 * V_23 ,
struct V_53 * V_27 ,
int V_42 )
{
int V_43 ;
V_27 -> V_23 = V_23 ;
V_27 -> V_13 . type = & V_55 ;
V_27 -> V_13 . V_47 = & V_23 -> V_47 ;
F_28 ( & V_27 -> V_13 ) ;
V_27 -> V_13 . V_48 = & V_23 -> V_13 ;
if ( V_23 -> V_56 )
F_29 ( & V_27 -> V_13 , L_8 , V_42 ) ;
else
F_29 ( & V_27 -> V_13 , L_9 , V_42 ) ;
F_30 ( & V_27 -> V_13 , V_27 ) ;
F_49 ( & V_23 -> V_13 ) ;
V_43 = F_31 ( & V_27 -> V_13 ) ;
F_23 ( 0 , L_10 , F_24 ( & V_27 -> V_13 ) ) ;
return V_43 ;
}
static T_1 F_50 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
const char * V_16 , T_3 V_39 )
{
struct V_41 * V_23 = F_51 ( V_13 ) ;
int V_57 , V_58 , V_34 , V_21 ;
V_23 -> V_59 = 0 ;
V_23 -> V_60 = 0 ;
V_23 -> V_61 = 0 ;
V_23 -> V_62 = 0 ;
for ( V_58 = 0 ; V_58 < V_23 -> V_51 ; V_58 ++ ) {
struct V_17 * V_63 = V_23 -> V_52 [ V_58 ] ;
V_63 -> V_19 = 0 ;
V_63 -> V_20 = 0 ;
for ( V_34 = 0 ; V_34 < V_63 -> V_25 ; V_34 ++ )
V_63 -> V_26 [ V_34 ] -> V_20 = 0 ;
}
V_57 = 1 ;
for ( V_21 = 0 ; V_21 < V_23 -> V_64 ; V_21 ++ ) {
V_57 *= V_23 -> V_65 [ V_21 ] . V_66 ;
memset ( V_23 -> V_67 [ V_21 ] , 0 , V_57 * sizeof( T_2 ) ) ;
memset ( V_23 -> V_68 [ V_21 ] , 0 , V_57 * sizeof( T_2 ) ) ;
}
V_23 -> V_69 = V_70 ;
return V_39 ;
}
static T_1 F_52 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
const char * V_16 , T_3 V_39 )
{
struct V_41 * V_23 = F_51 ( V_13 ) ;
unsigned long V_71 = 0 ;
int V_72 = 0 ;
if ( ! V_23 -> V_73 )
return - V_45 ;
if ( F_53 ( V_16 , 10 , & V_71 ) < 0 )
return - V_10 ;
V_72 = V_23 -> V_73 ( V_23 , V_71 ) ;
if ( V_72 < 0 ) {
F_54 ( V_74 , V_75 ,
L_11 , V_71 ) ;
return - V_10 ;
}
return V_39 ;
}
static T_1 F_55 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_41 * V_23 = F_51 ( V_13 ) ;
int V_71 = 0 ;
if ( ! V_23 -> V_76 )
return - V_45 ;
V_71 = V_23 -> V_76 ( V_23 ) ;
if ( V_71 < 0 ) {
F_54 ( V_77 , V_75 , L_12 ) ;
return V_71 ;
}
return sprintf ( V_16 , L_13 , V_71 ) ;
}
static T_1 F_56 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_41 * V_23 = F_51 ( V_13 ) ;
return sprintf ( V_16 , L_13 , V_23 -> V_59 ) ;
}
static T_1 F_57 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_41 * V_23 = F_51 ( V_13 ) ;
return sprintf ( V_16 , L_13 , V_23 -> V_60 ) ;
}
static T_1 F_58 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_41 * V_23 = F_51 ( V_13 ) ;
return sprintf ( V_16 , L_13 , V_23 -> V_62 ) ;
}
static T_1 F_59 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_41 * V_23 = F_51 ( V_13 ) ;
return sprintf ( V_16 , L_13 , V_23 -> V_61 ) ;
}
static T_1 F_60 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_41 * V_23 = F_51 ( V_13 ) ;
return sprintf ( V_16 , L_14 , ( V_70 - V_23 -> V_69 ) / V_78 ) ;
}
static T_1 F_61 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_41 * V_23 = F_51 ( V_13 ) ;
return sprintf ( V_16 , L_2 , V_23 -> V_79 ) ;
}
static T_1 F_62 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_41 * V_23 = F_51 ( V_13 ) ;
int V_80 = 0 , V_81 , V_82 ;
for ( V_81 = 0 ; V_81 < V_23 -> V_51 ; V_81 ++ ) {
struct V_17 * V_18 = V_23 -> V_52 [ V_81 ] ;
if ( V_18 -> V_23 -> V_24 ) {
V_80 += V_18 -> V_22 ;
} else {
for ( V_82 = 0 ; V_82 < V_18 -> V_25 ; V_82 ++ ) {
struct V_53 * V_27 = V_18 -> V_26 [ V_82 ] -> V_27 ;
V_80 += V_27 -> V_22 ;
}
}
}
return sprintf ( V_16 , L_1 , F_12 ( V_80 ) ) ;
}
static T_1 F_63 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_41 * V_23 = F_51 ( V_13 ) ;
int V_21 ;
char * V_83 = V_16 ;
for ( V_21 = 0 ; V_21 < V_23 -> V_64 ; V_21 ++ ) {
V_83 += sprintf ( V_83 , L_15 ,
V_84 [ V_23 -> V_65 [ V_21 ] . type ] ,
V_23 -> V_65 [ V_21 ] . V_66 - 1 ) ;
}
return V_83 - V_16 ;
}
static T_1 F_64 ( struct V_85 * V_85 ,
const char T_4 * V_16 ,
T_3 V_39 , T_5 * V_86 )
{
struct V_12 * V_13 = V_85 -> V_87 ;
struct V_41 * V_23 = F_51 ( V_13 ) ;
static enum V_88 type ;
T_6 V_89 = V_23 -> V_90 ;
if ( ! V_89 )
V_89 = 1 ;
type = V_23 -> V_91 ? V_92
: V_93 ;
F_65 ( V_77
L_16 ,
V_89 ,
( type == V_92 ) ? L_17 : L_18 ,
V_89 > 1 ? L_19 : L_20 ,
V_23 -> V_94 [ 0 ] ,
V_23 -> V_94 [ 1 ] ,
V_23 -> V_94 [ 2 ]
) ;
F_66 ( type , V_23 , V_89 , 0 , 0 , 0 ,
V_23 -> V_94 [ 0 ] ,
V_23 -> V_94 [ 1 ] ,
V_23 -> V_94 [ 2 ] ,
L_21 , L_22 ) ;
return V_39 ;
}
static void F_67 ( struct V_12 * V_13 )
{
struct V_41 * V_23 = F_22 ( V_13 , struct V_41 , V_13 ) ;
F_23 ( 1 , L_3 , F_24 ( V_13 ) ) ;
F_25 ( V_23 ) ;
}
int T_7 F_68 ( void )
{
V_95 = F_69 ( L_23 , NULL ) ;
if ( F_70 ( V_95 ) ) {
V_95 = NULL ;
return - V_96 ;
}
return 0 ;
}
void T_8 F_71 ( void )
{
F_72 ( V_95 ) ;
}
int F_73 ( struct V_41 * V_23 )
{
struct V_97 * V_98 , * V_48 ;
char V_99 [ 80 ] ;
int V_21 ;
if ( ! V_95 )
return - V_45 ;
V_98 = F_69 ( V_23 -> V_13 . V_100 . V_99 , V_95 ) ;
if ( ! V_98 )
return - V_96 ;
V_48 = V_98 ;
for ( V_21 = 0 ; V_21 < V_23 -> V_64 ; V_21 ++ ) {
sprintf ( V_99 , L_24 ,
V_84 [ V_23 -> V_65 [ V_21 ] . type ] ) ;
V_98 = F_74 ( V_99 , V_101 | V_102 , V_48 ,
& V_23 -> V_94 [ V_21 ] ) ;
if ( ! V_98 )
goto V_103;
}
V_98 = F_75 ( L_25 , V_101 | V_102 , V_48 ,
& V_23 -> V_91 ) ;
if ( ! V_98 )
goto V_103;
V_98 = F_76 ( L_26 , V_101 | V_102 , V_48 ,
& V_23 -> V_90 ) ;
if ( ! V_98 )
goto V_103;
V_98 = F_77 ( L_27 , V_102 , V_48 ,
& V_23 -> V_13 ,
& V_104 ) ;
if ( ! V_98 )
goto V_103;
V_23 -> V_105 = V_48 ;
return 0 ;
V_103:
F_72 ( V_23 -> V_105 ) ;
return - V_96 ;
}
int F_78 ( struct V_41 * V_23 )
{
int V_21 , V_43 ;
V_23 -> V_47 . V_99 = F_79 ( V_106 , L_28 , V_23 -> V_107 ) ;
if ( ! V_23 -> V_47 . V_99 )
return - V_96 ;
F_23 ( 0 , L_29 , V_23 -> V_47 . V_99 ) ;
V_43 = F_80 ( & V_23 -> V_47 ) ;
if ( V_43 < 0 )
return V_43 ;
V_23 -> V_13 . type = & V_108 ;
F_28 ( & V_23 -> V_13 ) ;
V_23 -> V_13 . V_48 = V_109 ;
V_23 -> V_13 . V_47 = & V_23 -> V_47 ;
F_29 ( & V_23 -> V_13 , L_28 , V_23 -> V_107 ) ;
F_30 ( & V_23 -> V_13 , V_23 ) ;
F_49 ( & V_23 -> V_13 ) ;
F_23 ( 0 , L_30 , F_24 ( & V_23 -> V_13 ) ) ;
V_43 = F_31 ( & V_23 -> V_13 ) ;
if ( V_43 < 0 ) {
F_81 ( & V_23 -> V_47 ) ;
F_25 ( V_23 -> V_47 . V_99 ) ;
return V_43 ;
}
for ( V_21 = 0 ; V_21 < V_23 -> V_110 ; V_21 ++ ) {
struct V_53 * V_27 = V_23 -> V_111 [ V_21 ] ;
if ( V_27 -> V_22 == 0 )
continue;
#ifdef F_82
F_23 ( 1 , L_31 , V_21 ) ;
if ( V_112 >= 1 ) {
int V_113 ;
for ( V_113 = 0 ; V_113 < V_23 -> V_64 ; V_113 ++ )
F_65 ( V_114 L_15 ,
V_84 [ V_23 -> V_65 [ V_113 ] . type ] ,
V_27 -> V_115 [ V_113 ] ) ;
F_65 ( V_114 L_32 ) ;
}
#endif
V_43 = F_48 ( V_23 , V_27 , V_21 ) ;
if ( V_43 ) {
F_23 ( 1 , L_33 , V_21 ) ;
goto V_116;
}
}
#ifdef F_83
V_43 = F_35 ( V_23 ) ;
if ( V_43 < 0 )
goto V_116;
#endif
#ifdef F_82
F_73 ( V_23 ) ;
#endif
return 0 ;
V_116:
for ( V_21 -- ; V_21 >= 0 ; V_21 -- ) {
struct V_53 * V_27 = V_23 -> V_111 [ V_21 ] ;
if ( V_27 -> V_22 == 0 )
continue;
F_37 ( & V_27 -> V_13 ) ;
}
F_37 ( & V_23 -> V_13 ) ;
F_81 ( & V_23 -> V_47 ) ;
F_25 ( V_23 -> V_47 . V_99 ) ;
return V_43 ;
}
void F_84 ( struct V_41 * V_23 )
{
int V_21 ;
F_23 ( 0 , L_32 ) ;
#ifdef F_82
F_72 ( V_23 -> V_105 ) ;
#endif
#ifdef F_83
F_36 ( V_23 ) ;
#endif
for ( V_21 = 0 ; V_21 < V_23 -> V_110 ; V_21 ++ ) {
struct V_53 * V_27 = V_23 -> V_111 [ V_21 ] ;
if ( V_27 -> V_22 == 0 )
continue;
F_23 ( 0 , L_34 , F_24 ( & V_27 -> V_13 ) ) ;
F_37 ( & V_27 -> V_13 ) ;
}
}
void F_85 ( struct V_41 * V_23 )
{
F_23 ( 1 , L_35 , F_24 ( & V_23 -> V_13 ) ) ;
F_37 ( & V_23 -> V_13 ) ;
F_81 ( & V_23 -> V_47 ) ;
F_25 ( V_23 -> V_47 . V_99 ) ;
}
static void F_86 ( struct V_12 * V_13 )
{
F_23 ( 1 , L_36 , F_24 ( V_13 ) ) ;
F_25 ( V_13 ) ;
}
int T_7 F_87 ( void )
{
struct V_117 * V_118 ;
int V_43 ;
V_118 = F_88 () ;
if ( V_118 == NULL ) {
F_23 ( 1 , L_37 ) ;
V_43 = - V_10 ;
goto V_119;
}
V_109 = F_89 ( sizeof( * V_109 ) , V_106 ) ;
if ( ! V_109 ) {
V_43 = - V_96 ;
goto V_120;
}
V_109 -> V_47 = V_118 ;
V_109 -> type = & V_121 ;
F_28 ( V_109 ) ;
F_29 ( V_109 , L_38 ) ;
V_43 = F_31 ( V_109 ) ;
if ( V_43 < 0 )
goto V_122;
F_23 ( 0 , L_39 , F_24 ( V_109 ) ) ;
return 0 ;
V_122:
F_25 ( V_109 ) ;
V_120:
F_90 () ;
V_119:
return V_43 ;
}
void T_8 F_91 ( void )
{
F_37 ( V_109 ) ;
F_90 () ;
}
