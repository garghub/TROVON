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
if ( V_42 >= F_27 ( V_43 ) - 1 ) {
F_28 ( 1 , L_4 , V_42 ) ;
return 0 ;
}
if ( ! V_18 -> V_24 [ V_42 ] -> V_25 -> V_22 )
return 0 ;
return V_41 -> V_44 ;
}
static inline int F_29 ( struct V_17 * V_18 )
{
int V_32 , V_22 = 0 ;
for ( V_32 = 0 ; V_32 < V_18 -> V_23 ; V_32 ++ )
V_22 += V_18 -> V_24 [ V_32 ] -> V_25 -> V_22 ;
return V_22 ;
}
static int F_30 ( struct V_45 * V_46 ,
struct V_17 * V_18 , int V_47 )
{
V_18 -> V_13 . type = & V_48 ;
V_18 -> V_13 . V_49 = V_46 -> V_49 ;
V_18 -> V_13 . V_50 = V_51 ;
F_31 ( & V_18 -> V_13 ) ;
V_18 -> V_13 . V_52 = & V_46 -> V_13 ;
V_18 -> V_46 = V_46 ;
F_32 ( & V_18 -> V_13 , L_5 , V_47 ) ;
F_33 ( & V_18 -> V_13 , V_18 ) ;
F_22 ( 0 , L_6 ,
F_23 ( & V_18 -> V_13 ) ) ;
return F_34 ( & V_18 -> V_13 ) ;
}
static int F_35 ( struct V_45 * V_46 )
{
int V_53 , V_21 ;
struct V_17 * V_18 ;
for ( V_21 = 0 ; V_21 < V_46 -> V_54 ; V_21 ++ ) {
V_18 = V_46 -> V_55 [ V_21 ] ;
if ( ! F_29 ( V_18 ) )
continue;
V_53 = F_30 ( V_46 , V_46 -> V_55 [ V_21 ] , V_21 ) ;
if ( V_53 < 0 ) {
F_22 ( 1 ,
L_7 ,
V_21 ) ;
goto error;
}
}
return 0 ;
error:
for ( -- V_21 ; V_21 >= 0 ; V_21 -- ) {
V_18 = V_46 -> V_55 [ V_21 ] ;
if ( ! F_29 ( V_18 ) )
continue;
F_36 ( & V_46 -> V_55 [ V_21 ] -> V_13 ) ;
}
return V_53 ;
}
static void F_37 ( struct V_45 * V_46 )
{
int V_21 ;
struct V_17 * V_18 ;
for ( V_21 = V_46 -> V_54 - 1 ; V_21 >= 0 ; V_21 -- ) {
V_18 = V_46 -> V_55 [ V_21 ] ;
if ( ! F_29 ( V_18 ) )
continue;
F_38 ( & V_46 -> V_55 [ V_21 ] -> V_13 ) ;
}
}
static T_1 F_39 ( struct V_12 * V_13 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_56 * V_25 = F_40 ( V_13 ) ;
return F_41 ( V_25 , V_16 , V_57 ) ;
}
static T_1 F_42 ( struct V_12 * V_13 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_56 * V_25 = F_40 ( V_13 ) ;
if ( ! V_25 -> V_35 [ 0 ] )
return 0 ;
return snprintf ( V_16 , sizeof( V_25 -> V_35 ) + 1 , L_2 , V_25 -> V_35 ) ;
}
static T_1 F_43 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
const char * V_16 ,
T_3 V_36 )
{
struct V_56 * V_25 = F_40 ( V_13 ) ;
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
static T_1 F_44 ( struct V_12 * V_13 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_56 * V_25 = F_40 ( V_13 ) ;
return sprintf ( V_16 , L_1 , F_12 ( V_25 -> V_22 ) ) ;
}
static T_1 F_45 ( struct V_12 * V_13 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_56 * V_25 = F_40 ( V_13 ) ;
return sprintf ( V_16 , L_2 , V_26 [ V_25 -> V_27 ] ) ;
}
static T_1 F_46 ( struct V_12 * V_13 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_56 * V_25 = F_40 ( V_13 ) ;
return sprintf ( V_16 , L_2 , V_28 [ V_25 -> V_29 ] ) ;
}
static T_1 F_47 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_56 * V_25 = F_40 ( V_13 ) ;
return sprintf ( V_16 , L_2 , V_30 [ V_25 -> V_31 ] ) ;
}
static T_1 F_48 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_56 * V_25 = F_40 ( V_13 ) ;
T_2 V_36 ;
int V_58 ;
V_58 = F_49 ( V_25 -> V_46 -> V_59 ,
V_25 -> V_46 -> V_60 ,
V_25 -> V_61 [ 0 ] ,
V_25 -> V_61 [ 1 ] ,
V_25 -> V_61 [ 2 ] ) ;
V_36 = V_25 -> V_46 -> V_62 [ V_25 -> V_46 -> V_60 - 1 ] [ V_58 ] ;
return sprintf ( V_16 , L_1 , V_36 ) ;
}
static T_1 F_50 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_56 * V_25 = F_40 ( V_13 ) ;
T_2 V_36 ;
int V_58 ;
V_58 = F_49 ( V_25 -> V_46 -> V_59 ,
V_25 -> V_46 -> V_60 ,
V_25 -> V_61 [ 0 ] ,
V_25 -> V_61 [ 1 ] ,
V_25 -> V_61 [ 2 ] ) ;
V_36 = V_25 -> V_46 -> V_63 [ V_25 -> V_46 -> V_60 - 1 ] [ V_58 ] ;
return sprintf ( V_16 , L_1 , V_36 ) ;
}
static void F_51 ( struct V_12 * V_13 )
{
struct V_56 * V_25 = F_21 ( V_13 , struct V_56 , V_13 ) ;
F_22 ( 1 , L_8 , F_23 ( V_13 ) ) ;
F_24 ( V_25 ) ;
}
static int F_52 ( struct V_45 * V_46 ,
struct V_56 * V_25 ,
int V_47 )
{
int V_53 ;
V_25 -> V_46 = V_46 ;
V_25 -> V_13 . type = & V_64 ;
V_25 -> V_13 . V_49 = V_46 -> V_49 ;
F_31 ( & V_25 -> V_13 ) ;
V_25 -> V_13 . V_52 = & V_46 -> V_13 ;
if ( V_46 -> V_65 )
F_32 ( & V_25 -> V_13 , L_9 , V_47 ) ;
else
F_32 ( & V_25 -> V_13 , L_10 , V_47 ) ;
F_33 ( & V_25 -> V_13 , V_25 ) ;
F_53 ( & V_46 -> V_13 ) ;
V_53 = F_34 ( & V_25 -> V_13 ) ;
F_22 ( 0 , L_11 , F_23 ( & V_25 -> V_13 ) ) ;
return V_53 ;
}
static T_1 F_54 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
const char * V_16 , T_3 V_36 )
{
struct V_45 * V_46 = F_55 ( V_13 ) ;
int V_66 , V_67 , V_32 , V_21 ;
V_46 -> V_68 = 0 ;
V_46 -> V_69 = 0 ;
V_46 -> V_70 = 0 ;
V_46 -> V_71 = 0 ;
for ( V_67 = 0 ; V_67 < V_46 -> V_54 ; V_67 ++ ) {
struct V_17 * V_72 = V_46 -> V_55 [ V_67 ] ;
V_72 -> V_19 = 0 ;
V_72 -> V_20 = 0 ;
for ( V_32 = 0 ; V_32 < V_72 -> V_23 ; V_32 ++ )
V_72 -> V_24 [ V_32 ] -> V_20 = 0 ;
}
V_66 = 1 ;
for ( V_21 = 0 ; V_21 < V_46 -> V_60 ; V_21 ++ ) {
V_66 *= V_46 -> V_59 [ V_21 ] . V_73 ;
memset ( V_46 -> V_62 [ V_21 ] , 0 , V_66 * sizeof( T_2 ) ) ;
memset ( V_46 -> V_63 [ V_21 ] , 0 , V_66 * sizeof( T_2 ) ) ;
}
V_46 -> V_74 = V_75 ;
return V_36 ;
}
static T_1 F_56 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
const char * V_16 , T_3 V_36 )
{
struct V_45 * V_46 = F_55 ( V_13 ) ;
unsigned long V_76 = 0 ;
int V_77 = 0 ;
if ( F_6 ( V_16 , 10 , & V_76 ) < 0 )
return - V_10 ;
V_77 = V_46 -> V_78 ( V_46 , V_76 ) ;
if ( V_77 < 0 ) {
F_57 ( V_79 , V_80 ,
L_12 , V_76 ) ;
return - V_10 ;
}
return V_36 ;
}
static T_1 F_58 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_45 * V_46 = F_55 ( V_13 ) ;
int V_76 = 0 ;
V_76 = V_46 -> V_81 ( V_46 ) ;
if ( V_76 < 0 ) {
F_57 ( V_82 , V_80 , L_13 ) ;
return V_76 ;
}
return sprintf ( V_16 , L_14 , V_76 ) ;
}
static T_1 F_59 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_45 * V_46 = F_55 ( V_13 ) ;
return sprintf ( V_16 , L_14 , V_46 -> V_68 ) ;
}
static T_1 F_60 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_45 * V_46 = F_55 ( V_13 ) ;
return sprintf ( V_16 , L_14 , V_46 -> V_69 ) ;
}
static T_1 F_61 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_45 * V_46 = F_55 ( V_13 ) ;
return sprintf ( V_16 , L_14 , V_46 -> V_71 ) ;
}
static T_1 F_62 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_45 * V_46 = F_55 ( V_13 ) ;
return sprintf ( V_16 , L_14 , V_46 -> V_70 ) ;
}
static T_1 F_63 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_45 * V_46 = F_55 ( V_13 ) ;
return sprintf ( V_16 , L_15 , ( V_75 - V_46 -> V_74 ) / V_83 ) ;
}
static T_1 F_64 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_45 * V_46 = F_55 ( V_13 ) ;
return sprintf ( V_16 , L_2 , V_46 -> V_84 ) ;
}
static T_1 F_65 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_45 * V_46 = F_55 ( V_13 ) ;
int V_85 = 0 , V_86 , V_87 ;
for ( V_86 = 0 ; V_86 < V_46 -> V_54 ; V_86 ++ ) {
struct V_17 * V_18 = V_46 -> V_55 [ V_86 ] ;
for ( V_87 = 0 ; V_87 < V_18 -> V_23 ; V_87 ++ ) {
struct V_56 * V_25 = V_18 -> V_24 [ V_87 ] -> V_25 ;
V_85 += V_25 -> V_22 ;
}
}
return sprintf ( V_16 , L_1 , F_12 ( V_85 ) ) ;
}
static T_1 F_66 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_45 * V_46 = F_55 ( V_13 ) ;
int V_21 ;
char * V_88 = V_16 ;
for ( V_21 = 0 ; V_21 < V_46 -> V_60 ; V_21 ++ ) {
V_88 += sprintf ( V_88 , L_16 ,
V_89 [ V_46 -> V_59 [ V_21 ] . type ] ,
V_46 -> V_59 [ V_21 ] . V_73 - 1 ) ;
}
return V_88 - V_16 ;
}
static T_4 F_67 ( struct V_38 * V_39 ,
struct V_40 * V_41 , int V_42 )
{
struct V_12 * V_13 = F_26 ( V_39 ) ;
struct V_45 * V_46 = F_55 ( V_13 ) ;
T_4 V_44 = 0 ;
if ( V_41 != & V_90 . V_41 )
return V_41 -> V_44 ;
if ( V_46 -> V_81 )
V_44 |= V_91 ;
if ( V_46 -> V_78 )
V_44 |= V_92 ;
return V_44 ;
}
static void F_68 ( struct V_12 * V_13 )
{
struct V_45 * V_46 = F_21 ( V_13 , struct V_45 , V_13 ) ;
F_22 ( 1 , L_3 , F_23 ( V_13 ) ) ;
F_24 ( V_46 ) ;
}
int F_69 ( struct V_45 * V_46 ,
const struct V_93 * * V_50 )
{
char * V_94 ;
int V_21 , V_53 ;
V_94 = F_70 ( V_95 , L_17 , V_46 -> V_96 ) ;
if ( ! V_94 )
return - V_97 ;
V_46 -> V_49 -> V_94 = V_94 ;
F_22 ( 0 , L_18 , V_46 -> V_49 -> V_94 ) ;
V_53 = F_71 ( V_46 -> V_49 ) ;
if ( V_53 < 0 ) {
F_24 ( V_94 ) ;
return V_53 ;
}
V_46 -> V_13 . type = & V_98 ;
F_31 ( & V_46 -> V_13 ) ;
V_46 -> V_13 . V_52 = V_99 ;
V_46 -> V_13 . V_49 = V_46 -> V_49 ;
V_46 -> V_13 . V_50 = V_50 ;
F_32 ( & V_46 -> V_13 , L_17 , V_46 -> V_96 ) ;
F_33 ( & V_46 -> V_13 , V_46 ) ;
F_53 ( & V_46 -> V_13 ) ;
F_22 ( 0 , L_19 , F_23 ( & V_46 -> V_13 ) ) ;
V_53 = F_34 ( & V_46 -> V_13 ) ;
if ( V_53 < 0 ) {
F_22 ( 1 , L_20 , F_23 ( & V_46 -> V_13 ) ) ;
goto V_100;
}
for ( V_21 = 0 ; V_21 < V_46 -> V_101 ; V_21 ++ ) {
struct V_56 * V_25 = V_46 -> V_102 [ V_21 ] ;
if ( ! V_25 -> V_22 )
continue;
#ifdef F_72
F_22 ( 1 , L_21 , V_21 ) ;
if ( V_103 >= 1 ) {
int V_104 ;
for ( V_104 = 0 ; V_104 < V_46 -> V_60 ; V_104 ++ )
F_73 ( V_105 L_16 ,
V_89 [ V_46 -> V_59 [ V_104 ] . type ] ,
V_25 -> V_61 [ V_104 ] ) ;
F_73 ( V_105 L_22 ) ;
}
#endif
V_53 = F_52 ( V_46 , V_25 , V_21 ) ;
if ( V_53 ) {
F_22 ( 1 , L_23 , V_21 ) ;
goto V_106;
}
}
#ifdef F_74
V_53 = F_35 ( V_46 ) ;
if ( V_53 < 0 )
goto V_106;
#endif
F_75 ( V_46 ) ;
return 0 ;
V_106:
for ( V_21 -- ; V_21 >= 0 ; V_21 -- ) {
struct V_56 * V_25 = V_46 -> V_102 [ V_21 ] ;
if ( ! V_25 -> V_22 )
continue;
F_38 ( & V_25 -> V_13 ) ;
}
F_38 ( & V_46 -> V_13 ) ;
V_100:
F_76 ( V_46 -> V_49 ) ;
F_24 ( V_94 ) ;
return V_53 ;
}
void F_77 ( struct V_45 * V_46 )
{
int V_21 ;
F_22 ( 0 , L_22 ) ;
#ifdef F_72
F_78 ( V_46 -> V_107 ) ;
#endif
#ifdef F_74
F_37 ( V_46 ) ;
#endif
for ( V_21 = 0 ; V_21 < V_46 -> V_101 ; V_21 ++ ) {
struct V_56 * V_25 = V_46 -> V_102 [ V_21 ] ;
if ( V_25 -> V_22 == 0 )
continue;
F_22 ( 0 , L_24 , F_23 ( & V_25 -> V_13 ) ) ;
F_38 ( & V_25 -> V_13 ) ;
}
}
void F_79 ( struct V_45 * V_46 )
{
struct V_108 * V_49 = V_46 -> V_49 ;
const char * V_94 = V_46 -> V_49 -> V_94 ;
F_22 ( 1 , L_25 , F_23 ( & V_46 -> V_13 ) ) ;
F_38 ( & V_46 -> V_13 ) ;
F_76 ( V_49 ) ;
F_24 ( V_94 ) ;
}
static void F_80 ( struct V_12 * V_13 )
{
F_22 ( 1 , L_26 , F_23 ( V_13 ) ) ;
F_24 ( V_13 ) ;
}
int T_5 F_81 ( void )
{
int V_53 ;
V_99 = F_82 ( sizeof( * V_99 ) , V_95 ) ;
if ( ! V_99 ) {
V_53 = - V_97 ;
goto V_109;
}
V_99 -> V_49 = F_83 () ;
V_99 -> type = & V_110 ;
F_31 ( V_99 ) ;
F_32 ( V_99 , L_27 ) ;
V_53 = F_34 ( V_99 ) ;
if ( V_53 < 0 )
goto V_111;
F_22 ( 0 , L_28 , F_23 ( V_99 ) ) ;
return 0 ;
V_111:
F_24 ( V_99 ) ;
V_109:
return V_53 ;
}
void F_84 ( void )
{
F_38 ( V_99 ) ;
}
