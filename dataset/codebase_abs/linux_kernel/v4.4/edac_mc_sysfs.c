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
return snprintf ( V_16 , sizeof( V_34 -> V_25 -> V_35 ) + 1 , L_2 ,
V_34 -> V_25 -> V_35 ) ;
}
static T_1 F_18 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
const char * V_16 , T_3 V_36 )
{
struct V_17 * V_18 = F_9 ( V_13 ) ;
unsigned V_32 = F_17 ( V_15 ) ;
struct V_33 * V_34 = V_18 -> V_24 [ V_32 ] ;
T_3 V_37 = V_36 ;
if ( V_36 == 0 )
return - V_10 ;
if ( V_16 [ V_36 - 1 ] == '\0' || V_16 [ V_36 - 1 ] == '\n' )
V_37 -= 1 ;
if ( V_37 == 0 || V_37 >= sizeof( V_34 -> V_25 -> V_35 ) )
return - V_10 ;
strncpy ( V_34 -> V_25 -> V_35 , V_16 , V_37 ) ;
V_34 -> V_25 -> V_35 [ V_37 ] = '\0' ;
return V_36 ;
}
static T_1 F_19 ( struct V_12 * V_13 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_17 * V_18 = F_9 ( V_13 ) ;
unsigned V_32 = F_17 ( V_15 ) ;
struct V_33 * V_34 = V_18 -> V_24 [ V_32 ] ;
return sprintf ( V_16 , L_1 , V_34 -> V_20 ) ;
}
static void F_20 ( struct V_12 * V_13 )
{
struct V_17 * V_18 = F_21 ( V_13 , struct V_17 , V_13 ) ;
F_22 ( 1 , L_3 , F_23 ( V_13 ) ) ;
F_24 ( V_18 ) ;
}
static T_4 F_25 ( struct V_38 * V_39 ,
struct V_40 * V_41 , int V_42 )
{
struct V_12 * V_13 = F_26 ( V_39 ) ;
struct V_17 * V_18 = F_21 ( V_13 , struct V_17 , V_13 ) ;
if ( V_42 >= V_18 -> V_23 )
return 0 ;
if ( ! V_18 -> V_24 [ V_42 ] -> V_25 -> V_22 )
return 0 ;
return V_41 -> V_43 ;
}
static inline int F_27 ( struct V_17 * V_18 )
{
int V_32 , V_22 = 0 ;
for ( V_32 = 0 ; V_32 < V_18 -> V_23 ; V_32 ++ )
V_22 += V_18 -> V_24 [ V_32 ] -> V_25 -> V_22 ;
return V_22 ;
}
static int F_28 ( struct V_44 * V_45 ,
struct V_17 * V_18 , int V_46 )
{
V_18 -> V_13 . type = & V_47 ;
V_18 -> V_13 . V_48 = V_45 -> V_48 ;
V_18 -> V_13 . V_49 = V_50 ;
F_29 ( & V_18 -> V_13 ) ;
V_18 -> V_13 . V_51 = & V_45 -> V_13 ;
V_18 -> V_45 = V_45 ;
F_30 ( & V_18 -> V_13 , L_4 , V_46 ) ;
F_31 ( & V_18 -> V_13 , V_18 ) ;
F_22 ( 0 , L_5 ,
F_23 ( & V_18 -> V_13 ) ) ;
return F_32 ( & V_18 -> V_13 ) ;
}
static int F_33 ( struct V_44 * V_45 )
{
int V_52 , V_21 ;
struct V_17 * V_18 ;
for ( V_21 = 0 ; V_21 < V_45 -> V_53 ; V_21 ++ ) {
V_18 = V_45 -> V_54 [ V_21 ] ;
if ( ! F_27 ( V_18 ) )
continue;
V_52 = F_28 ( V_45 , V_45 -> V_54 [ V_21 ] , V_21 ) ;
if ( V_52 < 0 ) {
F_22 ( 1 ,
L_6 ,
V_21 ) ;
goto error;
}
}
return 0 ;
error:
for ( -- V_21 ; V_21 >= 0 ; V_21 -- ) {
V_18 = V_45 -> V_54 [ V_21 ] ;
if ( ! F_27 ( V_18 ) )
continue;
F_34 ( & V_45 -> V_54 [ V_21 ] -> V_13 ) ;
}
return V_52 ;
}
static void F_35 ( struct V_44 * V_45 )
{
int V_21 ;
struct V_17 * V_18 ;
for ( V_21 = V_45 -> V_53 - 1 ; V_21 >= 0 ; V_21 -- ) {
V_18 = V_45 -> V_54 [ V_21 ] ;
if ( ! F_27 ( V_18 ) )
continue;
F_36 ( & V_45 -> V_54 [ V_21 ] -> V_13 ) ;
}
}
static T_1 F_37 ( struct V_12 * V_13 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_55 * V_25 = F_38 ( V_13 ) ;
return F_39 ( V_25 , V_16 , V_56 ) ;
}
static T_1 F_40 ( struct V_12 * V_13 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_55 * V_25 = F_38 ( V_13 ) ;
if ( ! V_25 -> V_35 [ 0 ] )
return 0 ;
return snprintf ( V_16 , sizeof( V_25 -> V_35 ) + 1 , L_2 , V_25 -> V_35 ) ;
}
static T_1 F_41 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
const char * V_16 ,
T_3 V_36 )
{
struct V_55 * V_25 = F_38 ( V_13 ) ;
T_3 V_37 = V_36 ;
if ( V_36 == 0 )
return - V_10 ;
if ( V_16 [ V_36 - 1 ] == '\0' || V_16 [ V_36 - 1 ] == '\n' )
V_37 -= 1 ;
if ( V_37 == 0 || V_37 >= sizeof( V_25 -> V_35 ) )
return - V_10 ;
strncpy ( V_25 -> V_35 , V_16 , V_37 ) ;
V_25 -> V_35 [ V_37 ] = '\0' ;
return V_36 ;
}
static T_1 F_42 ( struct V_12 * V_13 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_55 * V_25 = F_38 ( V_13 ) ;
return sprintf ( V_16 , L_1 , F_12 ( V_25 -> V_22 ) ) ;
}
static T_1 F_43 ( struct V_12 * V_13 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_55 * V_25 = F_38 ( V_13 ) ;
return sprintf ( V_16 , L_2 , V_26 [ V_25 -> V_27 ] ) ;
}
static T_1 F_44 ( struct V_12 * V_13 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_55 * V_25 = F_38 ( V_13 ) ;
return sprintf ( V_16 , L_2 , V_28 [ V_25 -> V_29 ] ) ;
}
static T_1 F_45 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_55 * V_25 = F_38 ( V_13 ) ;
return sprintf ( V_16 , L_2 , V_30 [ V_25 -> V_31 ] ) ;
}
static void F_46 ( struct V_12 * V_13 )
{
struct V_55 * V_25 = F_21 ( V_13 , struct V_55 , V_13 ) ;
F_22 ( 1 , L_7 , F_23 ( V_13 ) ) ;
F_24 ( V_25 ) ;
}
static int F_47 ( struct V_44 * V_45 ,
struct V_55 * V_25 ,
int V_46 )
{
int V_52 ;
V_25 -> V_45 = V_45 ;
V_25 -> V_13 . type = & V_57 ;
V_25 -> V_13 . V_48 = V_45 -> V_48 ;
F_29 ( & V_25 -> V_13 ) ;
V_25 -> V_13 . V_51 = & V_45 -> V_13 ;
if ( V_45 -> V_58 )
F_30 ( & V_25 -> V_13 , L_8 , V_46 ) ;
else
F_30 ( & V_25 -> V_13 , L_9 , V_46 ) ;
F_31 ( & V_25 -> V_13 , V_25 ) ;
F_48 ( & V_45 -> V_13 ) ;
V_52 = F_32 ( & V_25 -> V_13 ) ;
F_22 ( 0 , L_10 , F_23 ( & V_25 -> V_13 ) ) ;
return V_52 ;
}
static T_1 F_49 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
const char * V_16 , T_3 V_36 )
{
struct V_44 * V_45 = F_50 ( V_13 ) ;
int V_59 , V_60 , V_32 , V_21 ;
V_45 -> V_61 = 0 ;
V_45 -> V_62 = 0 ;
V_45 -> V_63 = 0 ;
V_45 -> V_64 = 0 ;
for ( V_60 = 0 ; V_60 < V_45 -> V_53 ; V_60 ++ ) {
struct V_17 * V_65 = V_45 -> V_54 [ V_60 ] ;
V_65 -> V_19 = 0 ;
V_65 -> V_20 = 0 ;
for ( V_32 = 0 ; V_32 < V_65 -> V_23 ; V_32 ++ )
V_65 -> V_24 [ V_32 ] -> V_20 = 0 ;
}
V_59 = 1 ;
for ( V_21 = 0 ; V_21 < V_45 -> V_66 ; V_21 ++ ) {
V_59 *= V_45 -> V_67 [ V_21 ] . V_68 ;
memset ( V_45 -> V_69 [ V_21 ] , 0 , V_59 * sizeof( T_2 ) ) ;
memset ( V_45 -> V_70 [ V_21 ] , 0 , V_59 * sizeof( T_2 ) ) ;
}
V_45 -> V_71 = V_72 ;
return V_36 ;
}
static T_1 F_51 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
const char * V_16 , T_3 V_36 )
{
struct V_44 * V_45 = F_50 ( V_13 ) ;
unsigned long V_73 = 0 ;
int V_74 = 0 ;
if ( F_6 ( V_16 , 10 , & V_73 ) < 0 )
return - V_10 ;
V_74 = V_45 -> V_75 ( V_45 , V_73 ) ;
if ( V_74 < 0 ) {
F_52 ( V_76 , V_77 ,
L_11 , V_73 ) ;
return - V_10 ;
}
return V_36 ;
}
static T_1 F_53 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_44 * V_45 = F_50 ( V_13 ) ;
int V_73 = 0 ;
V_73 = V_45 -> V_78 ( V_45 ) ;
if ( V_73 < 0 ) {
F_52 ( V_79 , V_77 , L_12 ) ;
return V_73 ;
}
return sprintf ( V_16 , L_13 , V_73 ) ;
}
static T_1 F_54 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_44 * V_45 = F_50 ( V_13 ) ;
return sprintf ( V_16 , L_13 , V_45 -> V_61 ) ;
}
static T_1 F_55 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_44 * V_45 = F_50 ( V_13 ) ;
return sprintf ( V_16 , L_13 , V_45 -> V_62 ) ;
}
static T_1 F_56 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_44 * V_45 = F_50 ( V_13 ) ;
return sprintf ( V_16 , L_13 , V_45 -> V_64 ) ;
}
static T_1 F_57 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_44 * V_45 = F_50 ( V_13 ) ;
return sprintf ( V_16 , L_13 , V_45 -> V_63 ) ;
}
static T_1 F_58 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_44 * V_45 = F_50 ( V_13 ) ;
return sprintf ( V_16 , L_14 , ( V_72 - V_45 -> V_71 ) / V_80 ) ;
}
static T_1 F_59 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_44 * V_45 = F_50 ( V_13 ) ;
return sprintf ( V_16 , L_2 , V_45 -> V_81 ) ;
}
static T_1 F_60 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_44 * V_45 = F_50 ( V_13 ) ;
int V_82 = 0 , V_83 , V_84 ;
for ( V_83 = 0 ; V_83 < V_45 -> V_53 ; V_83 ++ ) {
struct V_17 * V_18 = V_45 -> V_54 [ V_83 ] ;
for ( V_84 = 0 ; V_84 < V_18 -> V_23 ; V_84 ++ ) {
struct V_55 * V_25 = V_18 -> V_24 [ V_84 ] -> V_25 ;
V_82 += V_25 -> V_22 ;
}
}
return sprintf ( V_16 , L_1 , F_12 ( V_82 ) ) ;
}
static T_1 F_61 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_44 * V_45 = F_50 ( V_13 ) ;
int V_21 ;
char * V_85 = V_16 ;
for ( V_21 = 0 ; V_21 < V_45 -> V_66 ; V_21 ++ ) {
V_85 += sprintf ( V_85 , L_15 ,
V_86 [ V_45 -> V_67 [ V_21 ] . type ] ,
V_45 -> V_67 [ V_21 ] . V_68 - 1 ) ;
}
return V_85 - V_16 ;
}
static T_4 F_62 ( struct V_38 * V_39 ,
struct V_40 * V_41 , int V_42 )
{
struct V_12 * V_13 = F_26 ( V_39 ) ;
struct V_44 * V_45 = F_50 ( V_13 ) ;
T_4 V_43 = 0 ;
if ( V_41 != & V_87 . V_41 )
return V_41 -> V_43 ;
if ( V_45 -> V_78 )
V_43 |= V_88 ;
if ( V_45 -> V_75 )
V_43 |= V_89 ;
return V_43 ;
}
static void F_63 ( struct V_12 * V_13 )
{
struct V_44 * V_45 = F_21 ( V_13 , struct V_44 , V_13 ) ;
F_22 ( 1 , L_3 , F_23 ( V_13 ) ) ;
F_24 ( V_45 ) ;
}
int F_64 ( struct V_44 * V_45 ,
const struct V_90 * * V_49 )
{
int V_21 , V_52 ;
V_45 -> V_48 -> V_91 = F_65 ( V_92 , L_16 , V_45 -> V_93 ) ;
if ( ! V_45 -> V_48 -> V_91 )
return - V_94 ;
F_22 ( 0 , L_17 , V_45 -> V_48 -> V_91 ) ;
V_52 = F_66 ( V_45 -> V_48 ) ;
if ( V_52 < 0 )
goto V_95;
V_45 -> V_13 . type = & V_96 ;
F_29 ( & V_45 -> V_13 ) ;
V_45 -> V_13 . V_51 = V_97 ;
V_45 -> V_13 . V_48 = V_45 -> V_48 ;
V_45 -> V_13 . V_49 = V_49 ;
F_30 ( & V_45 -> V_13 , L_16 , V_45 -> V_93 ) ;
F_31 ( & V_45 -> V_13 , V_45 ) ;
F_48 ( & V_45 -> V_13 ) ;
F_22 ( 0 , L_18 , F_23 ( & V_45 -> V_13 ) ) ;
V_52 = F_32 ( & V_45 -> V_13 ) ;
if ( V_52 < 0 ) {
F_22 ( 1 , L_19 , F_23 ( & V_45 -> V_13 ) ) ;
goto V_98;
}
for ( V_21 = 0 ; V_21 < V_45 -> V_99 ; V_21 ++ ) {
struct V_55 * V_25 = V_45 -> V_100 [ V_21 ] ;
if ( ! V_25 -> V_22 )
continue;
#ifdef F_67
F_22 ( 1 , L_20 , V_21 ) ;
if ( V_101 >= 1 ) {
int V_102 ;
for ( V_102 = 0 ; V_102 < V_45 -> V_66 ; V_102 ++ )
F_68 ( V_103 L_15 ,
V_86 [ V_45 -> V_67 [ V_102 ] . type ] ,
V_25 -> V_104 [ V_102 ] ) ;
F_68 ( V_103 L_21 ) ;
}
#endif
V_52 = F_47 ( V_45 , V_25 , V_21 ) ;
if ( V_52 ) {
F_22 ( 1 , L_22 , V_21 ) ;
goto V_105;
}
}
#ifdef F_69
V_52 = F_33 ( V_45 ) ;
if ( V_52 < 0 )
goto V_105;
#endif
F_70 ( V_45 ) ;
return 0 ;
V_105:
for ( V_21 -- ; V_21 >= 0 ; V_21 -- ) {
struct V_55 * V_25 = V_45 -> V_100 [ V_21 ] ;
if ( ! V_25 -> V_22 )
continue;
F_36 ( & V_25 -> V_13 ) ;
}
F_36 ( & V_45 -> V_13 ) ;
V_98:
F_71 ( V_45 -> V_48 ) ;
V_95:
F_24 ( V_45 -> V_48 -> V_91 ) ;
return V_52 ;
}
void F_72 ( struct V_44 * V_45 )
{
int V_21 ;
F_22 ( 0 , L_21 ) ;
#ifdef F_67
F_73 ( V_45 -> V_106 ) ;
#endif
#ifdef F_69
F_35 ( V_45 ) ;
#endif
for ( V_21 = 0 ; V_21 < V_45 -> V_99 ; V_21 ++ ) {
struct V_55 * V_25 = V_45 -> V_100 [ V_21 ] ;
if ( V_25 -> V_22 == 0 )
continue;
F_22 ( 0 , L_23 , F_23 ( & V_25 -> V_13 ) ) ;
F_36 ( & V_25 -> V_13 ) ;
}
}
void F_74 ( struct V_44 * V_45 )
{
F_22 ( 1 , L_24 , F_23 ( & V_45 -> V_13 ) ) ;
F_36 ( & V_45 -> V_13 ) ;
F_71 ( V_45 -> V_48 ) ;
F_24 ( V_45 -> V_48 -> V_91 ) ;
}
static void F_75 ( struct V_12 * V_13 )
{
F_22 ( 1 , L_25 , F_23 ( V_13 ) ) ;
F_24 ( V_13 ) ;
}
int T_5 F_76 ( void )
{
struct V_107 * V_108 ;
int V_52 ;
V_108 = F_77 () ;
if ( V_108 == NULL ) {
F_22 ( 1 , L_26 ) ;
V_52 = - V_10 ;
goto V_109;
}
V_97 = F_78 ( sizeof( * V_97 ) , V_92 ) ;
if ( ! V_97 ) {
V_52 = - V_94 ;
goto V_110;
}
V_97 -> V_48 = V_108 ;
V_97 -> type = & V_111 ;
F_29 ( V_97 ) ;
F_30 ( V_97 , L_27 ) ;
V_52 = F_32 ( V_97 ) ;
if ( V_52 < 0 )
goto V_112;
F_22 ( 0 , L_28 , F_23 ( V_97 ) ) ;
return 0 ;
V_112:
F_24 ( V_97 ) ;
V_110:
F_79 () ;
V_109:
return V_52 ;
}
void F_80 ( void )
{
F_36 ( V_97 ) ;
F_79 () ;
}
