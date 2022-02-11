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
F_41 () ;
error = F_42 ( V_33 ) ;
if ( error || F_9 ( V_52 ) )
F_17 ( V_20 ) ;
else
error = F_21 ( V_20 ) ;
if ( error || ! V_42 )
F_43 () ;
V_26 = V_42 ? ( error ? V_44 : V_45 ) : V_46 ;
F_44 ( V_26 ) ;
if ( error || ! V_42 )
F_45 () ;
F_46 () ;
F_47 () ;
F_38 ( V_26 ) ;
V_47:
F_11 ( V_20 ) ;
return error ;
V_51:
F_48 () ;
V_48:
F_43 () ;
goto V_47;
}
static int F_49 ( bool V_20 )
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
error = F_50 () ;
if ( ! error ) {
error = F_51 () ;
F_52 ( ! error ) ;
F_50 () ;
}
F_43 () ;
F_29 () ;
F_53 () ;
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
int F_54 ( int V_20 )
{
int error ;
F_55 () ;
F_39 () ;
F_40 () ;
F_41 () ;
error = F_56 ( V_53 ) ;
if ( ! error ) {
error = F_49 ( V_20 ) ;
F_57 ( V_44 ) ;
}
F_45 () ;
F_46 () ;
F_47 () ;
F_58 () ;
return error ;
}
int F_59 ( void )
{
int error ;
if ( ! V_12 )
return - V_54 ;
error = V_12 -> V_3 () ;
if ( error )
goto V_47;
V_16 = true ;
F_39 () ;
F_40 () ;
error = F_56 ( V_55 ) ;
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
F_57 ( V_46 ) ;
F_46 () ;
F_47 () ;
V_47:
V_12 -> V_4 () ;
return error ;
}
static void F_60 ( void )
{
#ifdef F_61
int error ;
#endif
switch ( V_13 ) {
case V_58 :
F_62 ( NULL ) ;
break;
case V_14 :
F_59 () ;
case V_15 :
F_63 () ;
break;
#ifdef F_61
case V_59 :
error = F_64 ( V_60 ) ;
if ( error ) {
if ( V_12 )
V_13 = V_14 ;
else
V_13 = V_15 ;
F_60 () ;
}
error = F_65 () ;
if ( error )
F_7 ( V_34 L_8
L_9 ) ;
return;
#endif
}
F_66 () ;
F_7 ( V_61 L_10 ) ;
while( 1 ) ;
}
int F_67 ( void )
{
int error ;
F_3 () ;
if ( ! F_68 ( & V_62 , - 1 , 0 ) ) {
error = - V_63 ;
goto V_64;
}
F_55 () ;
error = F_69 ( V_65 ) ;
if ( error )
goto Exit;
error = F_70 () ;
if ( error )
goto Exit;
F_7 ( V_17 L_11 ) ;
F_71 () ;
F_7 ( L_12 ) ;
error = F_72 () ;
if ( error )
goto V_66;
error = F_34 ( V_13 == V_14 ) ;
if ( error || V_50 )
goto V_51;
if ( V_42 ) {
unsigned int V_67 = 0 ;
if ( V_13 == V_14 )
V_67 |= V_68 ;
if ( V_69 )
V_67 |= V_70 ;
else
V_67 |= V_71 ;
F_73 ( L_13 ) ;
error = F_74 ( V_67 ) ;
F_43 () ;
if ( ! error )
F_60 () ;
V_42 = 0 ;
F_45 () ;
} else {
F_73 ( L_14 ) ;
}
V_51:
F_75 () ;
V_50 = false ;
V_66:
F_76 () ;
Exit:
F_69 ( V_72 ) ;
F_58 () ;
F_77 ( & V_62 ) ;
V_64:
F_4 () ;
return error ;
}
static int F_78 ( void )
{
int error ;
unsigned int V_67 ;
if ( V_73 )
return 0 ;
F_79 ( & V_74 , V_75 ) ;
if ( V_76 )
goto V_77;
if ( ! strlen ( V_78 ) ) {
error = - V_79 ;
goto V_64;
}
F_73 ( L_15 , V_78 ) ;
if ( V_80 ) {
F_7 ( V_17 L_16 ,
V_80 ) ;
F_80 ( V_80 ) ;
}
V_76 = F_81 ( V_78 ) ;
if ( isdigit ( V_78 [ 0 ] ) && V_81 ) {
int V_82 ;
while ( ! F_82 ( V_76 , & V_82 ) )
F_83 ( 10 ) ;
}
if ( ! V_76 ) {
F_84 () ;
if ( V_81 ) {
while ( ( V_76 = F_81 ( V_78 ) ) == 0 )
F_83 ( 10 ) ;
F_85 () ;
}
V_76 = F_81 ( V_78 ) ;
if ( ! V_76 ) {
error = - V_83 ;
goto V_64;
}
}
V_77:
F_73 ( L_17 ,
F_86 ( V_76 ) , F_87 ( V_76 ) ) ;
F_73 ( L_18 ) ;
error = F_88 () ;
if ( error )
goto V_64;
if ( ! F_68 ( & V_62 , - 1 , 0 ) ) {
error = - V_63 ;
F_89 ( V_84 ) ;
goto V_64;
}
F_55 () ;
error = F_69 ( V_85 ) ;
if ( error )
goto V_86;
error = F_70 () ;
if ( error )
goto V_86;
F_73 ( L_19 ) ;
error = F_72 () ;
if ( error ) {
F_89 ( V_84 ) ;
goto V_87;
}
F_73 ( L_20 ) ;
error = F_90 ( & V_67 ) ;
F_89 ( V_84 ) ;
if ( ! error )
F_54 ( V_67 & V_68 ) ;
F_7 ( V_34 L_21 ) ;
F_43 () ;
F_75 () ;
V_87:
F_76 () ;
V_88:
F_69 ( V_89 ) ;
F_58 () ;
F_77 ( & V_62 ) ;
V_64:
F_91 ( & V_74 ) ;
F_73 ( L_22 ) ;
return error ;
V_86:
F_89 ( V_84 ) ;
goto V_88;
}
static T_3 F_92 ( struct V_90 * V_91 , struct V_92 * V_93 ,
char * V_94 )
{
int V_95 ;
char * V_23 = V_94 ;
for ( V_95 = V_96 ; V_95 <= V_97 ; V_95 ++ ) {
if ( ! V_98 [ V_95 ] )
continue;
switch ( V_95 ) {
case V_15 :
case V_58 :
#ifdef F_61
case V_59 :
#endif
break;
case V_14 :
if ( V_12 )
break;
continue;
}
if ( V_95 == V_13 )
V_94 += sprintf ( V_94 , L_23 , V_98 [ V_95 ] ) ;
else
V_94 += sprintf ( V_94 , L_24 , V_98 [ V_95 ] ) ;
}
V_94 += sprintf ( V_94 , L_25 ) ;
return V_94 - V_23 ;
}
static T_3 F_93 ( struct V_90 * V_91 , struct V_92 * V_93 ,
const char * V_94 , T_4 V_99 )
{
int error = 0 ;
int V_95 ;
int V_100 ;
char * V_101 ;
int V_102 = V_103 ;
V_101 = memchr ( V_94 , '\n' , V_99 ) ;
V_100 = V_101 ? V_101 - V_94 : V_99 ;
F_3 () ;
for ( V_95 = V_96 ; V_95 <= V_97 ; V_95 ++ ) {
if ( V_100 == strlen ( V_98 [ V_95 ] )
&& ! strncmp ( V_94 , V_98 [ V_95 ] , V_100 ) ) {
V_102 = V_95 ;
break;
}
}
if ( V_102 != V_103 ) {
switch ( V_102 ) {
case V_15 :
case V_58 :
#ifdef F_61
case V_59 :
#endif
V_13 = V_102 ;
break;
case V_14 :
if ( V_12 )
V_13 = V_102 ;
else
error = - V_104 ;
}
} else
error = - V_104 ;
if ( ! error )
F_73 ( L_26 ,
V_98 [ V_102 ] ) ;
F_4 () ;
return error ? error : V_99 ;
}
static T_3 F_94 ( struct V_90 * V_91 , struct V_92 * V_93 ,
char * V_94 )
{
return sprintf ( V_94 , L_27 , F_86 ( V_76 ) ,
F_87 ( V_76 ) ) ;
}
static T_3 F_95 ( struct V_90 * V_91 , struct V_92 * V_93 ,
const char * V_94 , T_4 V_99 )
{
unsigned int V_105 , V_106 ;
T_5 V_107 ;
int V_108 = - V_104 ;
if ( sscanf ( V_94 , L_28 , & V_105 , & V_106 ) != 2 )
goto V_109;
V_107 = F_96 ( V_105 , V_106 ) ;
if ( V_105 != F_86 ( V_107 ) || V_106 != F_87 ( V_107 ) )
goto V_109;
F_3 () ;
V_76 = V_107 ;
F_4 () ;
F_7 ( V_17 L_29 ) ;
V_73 = 0 ;
F_78 () ;
V_108 = V_99 ;
V_109:
return V_108 ;
}
static T_3 F_97 ( struct V_90 * V_91 , struct V_92 * V_93 ,
char * V_94 )
{
return sprintf ( V_94 , L_30 , V_110 ) ;
}
static T_3 F_98 ( struct V_90 * V_91 , struct V_92 * V_93 ,
const char * V_94 , T_4 V_99 )
{
unsigned long V_111 ;
if ( sscanf ( V_94 , L_31 , & V_111 ) == 1 ) {
V_110 = V_111 ;
return V_99 ;
}
return - V_104 ;
}
static T_3 F_99 ( struct V_90 * V_91 ,
struct V_92 * V_93 , char * V_94 )
{
return sprintf ( V_94 , L_30 , V_112 ) ;
}
static T_3 F_100 ( struct V_90 * V_91 ,
struct V_92 * V_93 ,
const char * V_94 , T_4 V_99 )
{
unsigned long V_111 ;
if ( sscanf ( V_94 , L_31 , & V_111 ) == 1 ) {
V_112 = V_111 ;
return V_99 ;
}
return - V_104 ;
}
static int T_6 F_101 ( void )
{
return F_102 ( V_113 , & V_114 ) ;
}
static int T_6 F_103 ( char * V_115 )
{
if ( V_73 )
return 1 ;
strncpy ( V_78 , V_115 , 255 ) ;
return 1 ;
}
static int T_6 F_104 ( char * V_115 )
{
unsigned long long V_116 ;
if ( V_73 )
return 1 ;
if ( sscanf ( V_115 , L_32 , & V_116 ) == 1 )
V_117 = V_116 ;
return 1 ;
}
static int T_6 F_105 ( char * V_115 )
{
if ( ! strncmp ( V_115 , L_33 , 8 ) )
V_73 = 1 ;
else if ( ! strncmp ( V_115 , L_34 , 10 ) )
V_69 = 1 ;
return 1 ;
}
static int T_6 F_106 ( char * V_115 )
{
V_73 = 1 ;
return 1 ;
}
static int T_6 F_107 ( char * V_115 )
{
V_81 = 1 ;
return 1 ;
}
static int T_6 F_108 ( char * V_115 )
{
V_80 = F_109 ( V_115 , NULL , 0 ) ;
return 1 ;
}
