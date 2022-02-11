void F_1 ( const struct V_1 * V_2 )
{
if ( V_2 && ! ( V_2 -> V_3 && V_2 -> V_4 && V_2 -> V_5
&& V_2 -> V_6 && V_2 -> V_7 && V_2 -> V_8 && V_2 -> V_9
&& V_2 -> V_10 && V_2 -> V_11 ) ) {
F_2 ( 1 ) ;
return;
}
F_3 () ;
V_12 = V_2 ;
if ( V_2 )
V_13 = V_14 ;
else if ( V_13 == V_14 )
V_13 = V_15 ;
F_4 () ;
}
bool F_5 ( void )
{
return V_16 ;
}
static void F_6 ( void )
{
F_7 ( V_17 L_1 ) ;
F_8 ( 5000 ) ;
}
static int F_9 ( int V_18 )
{
if ( V_19 == V_18 ) {
F_6 () ;
return 1 ;
}
return 0 ;
}
static int F_9 ( int V_18 ) { return 0 ; }
static int F_10 ( int V_20 )
{
return ( V_20 && V_12 ) ?
V_12 -> V_3 () : 0 ;
}
static void F_11 ( int V_20 )
{
if ( V_20 && V_12 )
V_12 -> V_4 () ;
}
static int F_12 ( int V_20 )
{
return ( V_20 && V_12 ) ?
V_12 -> V_5 () : 0 ;
}
static void F_13 ( int V_20 )
{
if ( V_20 && V_12 )
V_12 -> V_11 () ;
}
static void F_14 ( int V_20 )
{
if ( V_20 && V_12 )
V_12 -> V_7 () ;
}
static int F_15 ( int V_20 )
{
return ( V_20 && V_12 ) ?
V_12 -> V_9 () : 0 ;
}
static void F_16 ( int V_20 )
{
if ( V_20 && V_12 )
V_12 -> V_10 () ;
}
static void F_17 ( int V_20 )
{
if ( V_20 && V_12 && V_12 -> V_21 )
V_12 -> V_21 () ;
}
void F_18 ( struct V_22 * V_23 , struct V_22 * V_24 ,
unsigned V_25 , char * V_26 )
{
T_1 V_27 ;
int V_28 ;
int V_29 ;
int V_30 ;
V_27 = F_19 ( V_24 ) - F_19 ( V_23 ) ;
F_20 ( V_27 , V_31 / 100 ) ;
V_28 = V_27 ;
if ( V_28 == 0 )
V_28 = 1 ;
V_29 = V_25 * ( V_32 / 1024 ) ;
V_30 = ( V_29 * 100 ) / V_28 ;
F_7 ( V_17 L_2 ,
V_26 , V_29 ,
V_28 / 100 , V_28 % 100 ,
V_30 / 1000 , ( V_30 % 1000 ) / 10 ) ;
}
static int F_21 ( int V_20 )
{
int error ;
error = F_22 ( V_33 ) ;
if ( error ) {
F_7 ( V_34 L_3
L_4 ) ;
return error ;
}
error = F_12 ( V_20 ) ;
if ( error || F_9 ( V_35 ) )
goto V_36;
error = F_23 () ;
if ( error || F_9 ( V_37 ) )
goto V_38;
F_24 () ;
error = F_25 () ;
if ( error ) {
F_7 ( V_34 L_5
L_4 ) ;
goto V_39;
}
if ( F_9 ( V_40 ) || F_26 () )
goto V_41;
V_42 = 1 ;
F_27 () ;
error = F_28 () ;
if ( error )
F_7 ( V_34 L_6 ,
error ) ;
F_29 () ;
if ( ! V_42 ) {
V_43 = false ;
F_13 ( V_20 ) ;
}
V_41:
F_30 () ;
V_39:
F_31 () ;
V_38:
F_32 () ;
V_36:
F_14 ( V_20 ) ;
F_33 ( V_42 ?
( error ? V_44 : V_45 ) : V_46 ) ;
return error ;
}
int F_34 ( int V_20 )
{
T_2 V_26 ;
int error ;
error = F_10 ( V_20 ) ;
if ( error )
goto V_47;
error = F_35 () ;
if ( error )
goto V_47;
error = F_36 () ;
if ( error )
goto V_48;
if ( F_9 ( V_49 ) ) {
V_50 = true ;
goto V_51;
}
error = F_37 ( V_33 ) ;
if ( error ) {
F_38 ( V_44 ) ;
goto V_51;
}
F_39 () ;
F_40 () ;
error = F_41 ( V_33 ) ;
if ( error || F_9 ( V_52 ) )
F_17 ( V_20 ) ;
else
error = F_21 ( V_20 ) ;
if ( error || ! V_42 )
F_42 () ;
V_26 = V_42 ? ( error ? V_44 : V_45 ) : V_46 ;
F_43 ( V_26 ) ;
if ( error || ! V_42 )
F_44 () ;
F_45 () ;
F_38 ( V_26 ) ;
V_47:
F_11 ( V_20 ) ;
return error ;
V_51:
F_46 () ;
V_48:
F_42 () ;
goto V_47;
}
static int F_47 ( bool V_20 )
{
int error ;
error = F_22 ( V_53 ) ;
if ( error ) {
F_7 ( V_34 L_3
L_7 ) ;
return error ;
}
error = F_15 ( V_20 ) ;
if ( error )
goto V_48;
error = F_23 () ;
if ( error )
goto V_38;
F_24 () ;
error = F_25 () ;
if ( error )
goto V_39;
F_27 () ;
error = F_48 () ;
if ( ! error ) {
error = F_49 () ;
F_50 ( ! error ) ;
F_48 () ;
}
F_42 () ;
F_29 () ;
F_51 () ;
F_30 () ;
V_39:
F_31 () ;
V_38:
F_32 () ;
V_48:
F_16 ( V_20 ) ;
F_33 ( V_44 ) ;
return error ;
}
int F_52 ( int V_20 )
{
int error ;
F_53 () ;
F_39 () ;
F_40 () ;
error = F_54 ( V_53 ) ;
if ( ! error ) {
error = F_47 ( V_20 ) ;
F_55 ( V_44 ) ;
}
F_44 () ;
F_45 () ;
F_56 () ;
return error ;
}
int F_57 ( void )
{
int error ;
if ( ! V_12 )
return - V_54 ;
error = V_12 -> V_3 () ;
if ( error )
goto V_47;
V_16 = true ;
F_39 () ;
error = F_54 ( V_55 ) ;
if ( error ) {
if ( V_12 -> V_21 )
V_12 -> V_21 () ;
goto V_56;
}
error = F_22 ( V_55 ) ;
if ( error )
goto V_56;
error = V_12 -> V_6 () ;
if ( error )
goto V_36;
error = F_23 () ;
if ( error )
goto V_36;
F_24 () ;
F_25 () ;
if ( F_26 () ) {
error = - V_57 ;
goto V_41;
}
V_12 -> V_8 () ;
while ( 1 ) ;
V_41:
F_30 () ;
F_31 () ;
F_32 () ;
V_36:
V_12 -> V_7 () ;
F_33 ( V_46 ) ;
V_56:
V_16 = false ;
F_55 ( V_46 ) ;
F_45 () ;
V_47:
V_12 -> V_4 () ;
return error ;
}
static void F_58 ( void )
{
switch ( V_13 ) {
case V_58 :
F_59 ( NULL ) ;
break;
case V_14 :
F_57 () ;
case V_15 :
F_60 () ;
break;
}
F_61 () ;
F_7 ( V_59 L_8 ) ;
while( 1 ) ;
}
int F_62 ( void )
{
int error ;
F_3 () ;
if ( ! F_63 ( & V_60 , - 1 , 0 ) ) {
error = - V_61 ;
goto V_62;
}
F_53 () ;
error = F_64 ( V_63 ) ;
if ( error )
goto Exit;
error = F_65 () ;
if ( error )
goto Exit;
F_7 ( V_17 L_9 ) ;
F_66 () ;
F_7 ( L_10 ) ;
error = F_67 () ;
if ( error )
goto V_64;
error = F_34 ( V_13 == V_14 ) ;
if ( error || V_50 )
goto V_51;
if ( V_42 ) {
unsigned int V_65 = 0 ;
if ( V_13 == V_14 )
V_65 |= V_66 ;
if ( V_67 )
V_65 |= V_68 ;
else
V_65 |= V_69 ;
F_68 ( L_11 ) ;
error = F_69 ( V_65 ) ;
F_42 () ;
if ( ! error )
F_58 () ;
V_42 = 0 ;
F_44 () ;
} else {
F_68 ( L_12 ) ;
}
V_51:
F_70 () ;
V_50 = false ;
V_64:
F_71 () ;
Exit:
F_64 ( V_70 ) ;
F_56 () ;
F_72 ( & V_60 ) ;
V_62:
F_4 () ;
return error ;
}
static int F_73 ( void )
{
int error ;
unsigned int V_65 ;
if ( V_71 )
return 0 ;
F_74 ( & V_72 , V_73 ) ;
if ( V_74 )
goto V_75;
if ( ! strlen ( V_76 ) ) {
error = - V_77 ;
goto V_62;
}
F_68 ( L_13 , V_76 ) ;
if ( V_78 ) {
F_7 ( V_17 L_14 ,
V_78 ) ;
F_75 ( V_78 ) ;
}
V_74 = F_76 ( V_76 ) ;
if ( isdigit ( V_76 [ 0 ] ) && V_79 ) {
int V_80 ;
while ( ! F_77 ( V_74 , & V_80 ) )
F_78 ( 10 ) ;
}
if ( ! V_74 ) {
F_79 () ;
if ( V_79 ) {
while ( ( V_74 = F_76 ( V_76 ) ) == 0 )
F_78 ( 10 ) ;
F_80 () ;
}
V_74 = F_76 ( V_76 ) ;
if ( ! V_74 ) {
error = - V_81 ;
goto V_62;
}
}
V_75:
F_68 ( L_15 ,
F_81 ( V_74 ) , F_82 ( V_74 ) ) ;
F_68 ( L_16 ) ;
error = F_83 () ;
if ( error )
goto V_62;
if ( ! F_63 ( & V_60 , - 1 , 0 ) ) {
error = - V_61 ;
F_84 ( V_82 ) ;
goto V_62;
}
F_53 () ;
error = F_64 ( V_83 ) ;
if ( error )
goto V_84;
error = F_65 () ;
if ( error )
goto V_84;
F_68 ( L_17 ) ;
error = F_67 () ;
if ( error ) {
F_84 ( V_82 ) ;
goto V_85;
}
F_68 ( L_18 ) ;
error = F_85 ( & V_65 ) ;
F_84 ( V_82 ) ;
if ( ! error )
F_52 ( V_65 & V_66 ) ;
F_7 ( V_34 L_19 ) ;
F_42 () ;
F_70 () ;
V_85:
F_71 () ;
V_86:
F_64 ( V_87 ) ;
F_56 () ;
F_72 ( & V_60 ) ;
V_62:
F_86 ( & V_72 ) ;
F_68 ( L_20 ) ;
return error ;
V_84:
F_84 ( V_82 ) ;
goto V_86;
}
static T_3 F_87 ( struct V_88 * V_89 , struct V_90 * V_91 ,
char * V_92 )
{
int V_93 ;
char * V_23 = V_92 ;
for ( V_93 = V_94 ; V_93 <= V_95 ; V_93 ++ ) {
if ( ! V_96 [ V_93 ] )
continue;
switch ( V_93 ) {
case V_15 :
case V_58 :
break;
case V_14 :
if ( V_12 )
break;
continue;
}
if ( V_93 == V_13 )
V_92 += sprintf ( V_92 , L_21 , V_96 [ V_93 ] ) ;
else
V_92 += sprintf ( V_92 , L_22 , V_96 [ V_93 ] ) ;
}
V_92 += sprintf ( V_92 , L_23 ) ;
return V_92 - V_23 ;
}
static T_3 F_88 ( struct V_88 * V_89 , struct V_90 * V_91 ,
const char * V_92 , T_4 V_97 )
{
int error = 0 ;
int V_93 ;
int V_98 ;
char * V_99 ;
int V_100 = V_101 ;
V_99 = memchr ( V_92 , '\n' , V_97 ) ;
V_98 = V_99 ? V_99 - V_92 : V_97 ;
F_3 () ;
for ( V_93 = V_94 ; V_93 <= V_95 ; V_93 ++ ) {
if ( V_98 == strlen ( V_96 [ V_93 ] )
&& ! strncmp ( V_92 , V_96 [ V_93 ] , V_98 ) ) {
V_100 = V_93 ;
break;
}
}
if ( V_100 != V_101 ) {
switch ( V_100 ) {
case V_15 :
case V_58 :
V_13 = V_100 ;
break;
case V_14 :
if ( V_12 )
V_13 = V_100 ;
else
error = - V_102 ;
}
} else
error = - V_102 ;
if ( ! error )
F_68 ( L_24 ,
V_96 [ V_100 ] ) ;
F_4 () ;
return error ? error : V_97 ;
}
static T_3 F_89 ( struct V_88 * V_89 , struct V_90 * V_91 ,
char * V_92 )
{
return sprintf ( V_92 , L_25 , F_81 ( V_74 ) ,
F_82 ( V_74 ) ) ;
}
static T_3 F_90 ( struct V_88 * V_89 , struct V_90 * V_91 ,
const char * V_92 , T_4 V_97 )
{
unsigned int V_103 , V_104 ;
T_5 V_105 ;
int V_106 = - V_102 ;
if ( sscanf ( V_92 , L_26 , & V_103 , & V_104 ) != 2 )
goto V_107;
V_105 = F_91 ( V_103 , V_104 ) ;
if ( V_103 != F_81 ( V_105 ) || V_104 != F_82 ( V_105 ) )
goto V_107;
F_3 () ;
V_74 = V_105 ;
F_4 () ;
F_7 ( V_17 L_27 ) ;
V_71 = 0 ;
F_73 () ;
V_106 = V_97 ;
V_107:
return V_106 ;
}
static T_3 F_92 ( struct V_88 * V_89 , struct V_90 * V_91 ,
char * V_92 )
{
return sprintf ( V_92 , L_28 , V_108 ) ;
}
static T_3 F_93 ( struct V_88 * V_89 , struct V_90 * V_91 ,
const char * V_92 , T_4 V_97 )
{
unsigned long V_109 ;
if ( sscanf ( V_92 , L_29 , & V_109 ) == 1 ) {
V_108 = V_109 ;
return V_97 ;
}
return - V_102 ;
}
static T_3 F_94 ( struct V_88 * V_89 ,
struct V_90 * V_91 , char * V_92 )
{
return sprintf ( V_92 , L_28 , V_110 ) ;
}
static T_3 F_95 ( struct V_88 * V_89 ,
struct V_90 * V_91 ,
const char * V_92 , T_4 V_97 )
{
unsigned long V_109 ;
if ( sscanf ( V_92 , L_29 , & V_109 ) == 1 ) {
V_110 = V_109 ;
return V_97 ;
}
return - V_102 ;
}
static int T_6 F_96 ( void )
{
return F_97 ( V_111 , & V_112 ) ;
}
static int T_6 F_98 ( char * V_113 )
{
if ( V_71 )
return 1 ;
strncpy ( V_76 , V_113 , 255 ) ;
return 1 ;
}
static int T_6 F_99 ( char * V_113 )
{
unsigned long long V_114 ;
if ( V_71 )
return 1 ;
if ( sscanf ( V_113 , L_30 , & V_114 ) == 1 )
V_115 = V_114 ;
return 1 ;
}
static int T_6 F_100 ( char * V_113 )
{
if ( ! strncmp ( V_113 , L_31 , 8 ) )
V_71 = 1 ;
else if ( ! strncmp ( V_113 , L_32 , 10 ) )
V_67 = 1 ;
return 1 ;
}
static int T_6 F_101 ( char * V_113 )
{
V_71 = 1 ;
return 1 ;
}
static int T_6 F_102 ( char * V_113 )
{
V_79 = 1 ;
return 1 ;
}
static int T_6 F_103 ( char * V_113 )
{
V_78 = F_104 ( V_113 , NULL , 0 ) ;
return 1 ;
}
