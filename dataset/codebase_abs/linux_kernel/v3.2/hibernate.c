void F_1 ( const struct V_1 * V_2 )
{
if ( V_2 && ! ( V_2 -> V_3 && V_2 -> V_4 && V_2 -> V_5
&& V_2 -> V_6 && V_2 -> V_7 && V_2 -> V_8 && V_2 -> V_9
&& V_2 -> V_10 && V_2 -> V_11 ) ) {
F_2 ( 1 ) ;
return;
}
F_3 ( & V_12 ) ;
V_13 = V_2 ;
if ( V_2 )
V_14 = V_15 ;
else if ( V_14 == V_15 )
V_14 = V_16 ;
F_4 ( & V_12 ) ;
}
bool F_5 ( void )
{
return V_17 ;
}
static void F_6 ( void )
{
F_7 ( V_18 L_1 ) ;
F_8 ( 5000 ) ;
}
static int F_9 ( int V_19 )
{
if ( V_14 == V_19 ) {
F_6 () ;
return 1 ;
}
return 0 ;
}
static int F_10 ( int V_20 )
{
if ( V_21 == V_20 ) {
F_6 () ;
return 1 ;
}
return 0 ;
}
static int F_9 ( int V_19 ) { return 0 ; }
static int F_10 ( int V_20 ) { return 0 ; }
static int F_11 ( int V_22 )
{
return ( V_22 && V_13 ) ?
V_13 -> V_3 () : 0 ;
}
static void F_12 ( int V_22 )
{
if ( V_22 && V_13 )
V_13 -> V_4 () ;
}
static int F_13 ( int V_22 )
{
return ( V_22 && V_13 ) ?
V_13 -> V_5 () : 0 ;
}
static void F_14 ( int V_22 )
{
if ( V_22 && V_13 )
V_13 -> V_11 () ;
}
static void F_15 ( int V_22 )
{
if ( V_22 && V_13 )
V_13 -> V_7 () ;
}
static int F_16 ( int V_22 )
{
return ( V_22 && V_13 ) ?
V_13 -> V_9 () : 0 ;
}
static void F_17 ( int V_22 )
{
if ( V_22 && V_13 )
V_13 -> V_10 () ;
}
static void F_18 ( int V_22 )
{
if ( V_22 && V_13 && V_13 -> V_23 )
V_13 -> V_23 () ;
}
void F_19 ( struct V_24 * V_25 , struct V_24 * V_26 ,
unsigned V_27 , char * V_28 )
{
T_1 V_29 ;
int V_30 ;
int V_31 ;
int V_32 ;
V_29 = F_20 ( V_26 ) - F_20 ( V_25 ) ;
F_21 ( V_29 , V_33 / 100 ) ;
V_30 = V_29 ;
if ( V_30 == 0 )
V_30 = 1 ;
V_31 = V_27 * ( V_34 / 1024 ) ;
V_32 = ( V_31 * 100 ) / V_30 ;
F_7 ( V_18 L_2 ,
V_28 , V_31 ,
V_30 / 100 , V_30 % 100 ,
V_32 / 1000 , ( V_32 % 1000 ) / 10 ) ;
}
static int F_22 ( int V_22 )
{
int error ;
error = F_23 ( V_35 ) ;
if ( error ) {
F_7 ( V_36 L_3
L_4 ) ;
return error ;
}
error = F_13 ( V_22 ) ;
if ( error || F_10 ( V_37 ) )
goto V_38;
error = F_24 () ;
if ( error || F_10 ( V_39 )
|| F_9 ( V_40 ) )
goto V_41;
F_25 () ;
error = F_26 () ;
if ( error ) {
F_7 ( V_36 L_5
L_4 ) ;
goto V_42;
}
if ( F_10 ( V_43 ) || F_27 () )
goto V_44;
V_45 = 1 ;
F_28 () ;
error = F_29 () ;
if ( error )
F_7 ( V_36 L_6 ,
error ) ;
F_30 () ;
if ( ! V_45 ) {
V_46 = false ;
F_14 ( V_22 ) ;
}
V_44:
F_31 () ;
V_42:
F_32 () ;
V_41:
F_33 () ;
V_38:
F_15 ( V_22 ) ;
F_34 ( V_45 ?
( error ? V_47 : V_48 ) : V_49 ) ;
return error ;
}
int F_35 ( int V_22 )
{
T_2 V_28 = V_47 ;
int error ;
error = F_11 ( V_22 ) ;
if ( error )
goto V_50;
error = F_36 () ;
if ( error )
goto V_50;
error = F_37 () ;
if ( error )
goto V_51;
if ( F_10 ( V_52 ) ||
F_9 ( V_53 ) ) {
V_54 = true ;
goto V_51;
}
error = F_38 ( V_35 ) ;
if ( error ) {
F_39 ( V_28 ) ;
goto V_51;
}
F_40 () ;
F_41 () ;
error = F_42 ( V_35 ) ;
if ( error )
goto V_55;
if ( F_10 ( V_56 ) )
goto V_55;
error = F_22 ( V_22 ) ;
V_57:
if ( error || ! V_45 )
F_43 () ;
V_28 = V_45 ? ( error ? V_47 : V_48 ) : V_49 ;
F_44 ( V_28 ) ;
if ( error || ! V_45 )
F_45 () ;
F_46 () ;
F_39 ( V_28 ) ;
V_50:
F_12 ( V_22 ) ;
return error ;
V_55:
F_18 ( V_22 ) ;
goto V_57;
V_51:
F_43 () ;
goto V_50;
}
static int F_47 ( bool V_22 )
{
int error ;
error = F_23 ( V_58 ) ;
if ( error ) {
F_7 ( V_36 L_3
L_7 ) ;
return error ;
}
error = F_16 ( V_22 ) ;
if ( error )
goto V_51;
error = F_24 () ;
if ( error )
goto V_41;
F_25 () ;
error = F_26 () ;
if ( error )
goto V_42;
F_28 () ;
error = F_48 () ;
if ( ! error ) {
error = F_49 () ;
F_50 ( ! error ) ;
F_48 () ;
}
F_43 () ;
F_30 () ;
F_51 () ;
F_31 () ;
V_42:
F_32 () ;
V_41:
F_33 () ;
V_51:
F_17 ( V_22 ) ;
F_34 ( V_47 ) ;
return error ;
}
int F_52 ( int V_22 )
{
int error ;
F_53 () ;
F_40 () ;
F_41 () ;
error = F_54 ( V_58 ) ;
if ( ! error ) {
error = F_47 ( V_22 ) ;
F_55 ( V_47 ) ;
}
F_45 () ;
F_46 () ;
F_56 () ;
return error ;
}
int F_57 ( void )
{
int error ;
if ( ! V_13 )
return - V_59 ;
error = V_13 -> V_3 () ;
if ( error )
goto V_50;
V_17 = true ;
F_40 () ;
error = F_54 ( V_60 ) ;
if ( error ) {
if ( V_13 -> V_23 )
V_13 -> V_23 () ;
goto V_57;
}
error = F_23 ( V_60 ) ;
if ( error )
goto V_57;
error = V_13 -> V_6 () ;
if ( error )
goto V_38;
error = F_24 () ;
if ( error )
goto V_38;
F_25 () ;
F_26 () ;
if ( F_27 () ) {
error = - V_61 ;
goto V_44;
}
V_13 -> V_8 () ;
while ( 1 ) ;
V_44:
F_31 () ;
F_32 () ;
F_33 () ;
V_38:
V_13 -> V_7 () ;
F_34 ( V_49 ) ;
V_57:
V_17 = false ;
F_55 ( V_49 ) ;
F_46 () ;
V_50:
V_13 -> V_4 () ;
return error ;
}
static void F_58 ( void )
{
switch ( V_14 ) {
case V_40 :
case V_53 :
break;
case V_62 :
F_59 ( NULL ) ;
break;
case V_15 :
F_57 () ;
case V_16 :
F_60 () ;
break;
}
F_61 () ;
F_7 ( V_63 L_8 ) ;
while( 1 ) ;
}
static int F_62 ( void )
{
int error = 0 ;
if ( F_63 () ) {
error = - V_64 ;
F_64 () ;
}
return error ;
}
int F_65 ( void )
{
int error ;
F_3 ( & V_12 ) ;
if ( ! F_66 ( & V_65 , - 1 , 0 ) ) {
error = - V_64 ;
goto V_66;
}
F_53 () ;
error = F_67 ( V_67 ) ;
if ( error )
goto Exit;
error = F_68 () ;
if ( error )
goto Exit;
error = F_69 () ;
if ( error )
goto Exit;
F_7 ( V_18 L_9 ) ;
F_70 () ;
F_7 ( L_10 ) ;
error = F_62 () ;
if ( error )
goto V_68;
error = F_35 ( V_14 == V_15 ) ;
if ( error )
goto V_69;
if ( V_54 ) {
V_54 = false ;
goto V_69;
}
if ( V_45 ) {
unsigned int V_70 = 0 ;
if ( V_14 == V_15 )
V_70 |= V_71 ;
if ( V_72 )
V_70 |= V_73 ;
else
V_70 |= V_74 ;
F_71 ( L_11 ) ;
error = F_72 ( V_70 ) ;
F_43 () ;
if ( ! error )
F_58 () ;
V_45 = 0 ;
F_45 () ;
} else {
F_71 ( L_12 ) ;
}
V_69:
F_64 () ;
V_68:
F_73 () ;
F_74 () ;
Exit:
F_67 ( V_75 ) ;
F_56 () ;
F_75 ( & V_65 ) ;
V_66:
F_4 ( & V_12 ) ;
return error ;
}
static int F_76 ( void )
{
int error ;
unsigned int V_70 ;
if ( V_76 )
return 0 ;
F_77 ( & V_12 , V_77 ) ;
if ( V_78 )
goto V_79;
if ( ! strlen ( V_80 ) ) {
error = - V_81 ;
goto V_66;
}
F_71 ( L_13 , V_80 ) ;
if ( V_82 ) {
F_7 ( V_18 L_14 ,
V_82 ) ;
F_78 ( V_82 ) ;
}
V_78 = F_79 ( V_80 ) ;
if ( ! V_78 ) {
F_80 () ;
if ( V_83 ) {
while ( ( V_78 = F_79 ( V_80 ) ) == 0 )
F_81 ( 10 ) ;
F_82 () ;
}
F_83 () ;
V_78 = F_79 ( V_80 ) ;
if ( ! V_78 ) {
error = - V_84 ;
goto V_66;
}
}
V_79:
F_71 ( L_15 ,
F_84 ( V_78 ) , F_85 ( V_78 ) ) ;
F_71 ( L_16 ) ;
error = F_86 () ;
if ( error )
goto V_66;
if ( ! F_66 ( & V_65 , - 1 , 0 ) ) {
error = - V_64 ;
F_87 ( V_85 ) ;
goto V_66;
}
F_53 () ;
error = F_67 ( V_86 ) ;
if ( error )
goto V_87;
error = F_68 () ;
if ( error )
goto V_87;
error = F_69 () ;
if ( error )
goto V_87;
F_71 ( L_17 ) ;
error = F_62 () ;
if ( error ) {
F_87 ( V_85 ) ;
goto V_88;
}
F_71 ( L_18 ) ;
error = F_88 ( & V_70 ) ;
F_87 ( V_85 ) ;
if ( ! error )
F_52 ( V_70 & V_71 ) ;
F_7 ( V_36 L_19 ) ;
F_43 () ;
F_64 () ;
V_88:
F_73 () ;
F_74 () ;
V_68:
F_67 ( V_89 ) ;
F_56 () ;
F_75 ( & V_65 ) ;
V_66:
F_4 ( & V_12 ) ;
F_71 ( L_20 ) ;
return error ;
V_87:
F_87 ( V_85 ) ;
goto V_68;
}
static T_3 F_89 ( struct V_90 * V_91 , struct V_92 * V_93 ,
char * V_94 )
{
int V_95 ;
char * V_25 = V_94 ;
for ( V_95 = V_96 ; V_95 <= V_97 ; V_95 ++ ) {
if ( ! V_98 [ V_95 ] )
continue;
switch ( V_95 ) {
case V_16 :
case V_62 :
case V_40 :
case V_53 :
break;
case V_15 :
if ( V_13 )
break;
continue;
}
if ( V_95 == V_14 )
V_94 += sprintf ( V_94 , L_21 , V_98 [ V_95 ] ) ;
else
V_94 += sprintf ( V_94 , L_22 , V_98 [ V_95 ] ) ;
}
V_94 += sprintf ( V_94 , L_23 ) ;
return V_94 - V_25 ;
}
static T_3 F_90 ( struct V_90 * V_91 , struct V_92 * V_93 ,
const char * V_94 , T_4 V_99 )
{
int error = 0 ;
int V_95 ;
int V_100 ;
char * V_101 ;
int V_19 = V_102 ;
V_101 = memchr ( V_94 , '\n' , V_99 ) ;
V_100 = V_101 ? V_101 - V_94 : V_99 ;
F_3 ( & V_12 ) ;
for ( V_95 = V_96 ; V_95 <= V_97 ; V_95 ++ ) {
if ( V_100 == strlen ( V_98 [ V_95 ] )
&& ! strncmp ( V_94 , V_98 [ V_95 ] , V_100 ) ) {
V_19 = V_95 ;
break;
}
}
if ( V_19 != V_102 ) {
switch ( V_19 ) {
case V_16 :
case V_62 :
case V_40 :
case V_53 :
V_14 = V_19 ;
break;
case V_15 :
if ( V_13 )
V_14 = V_19 ;
else
error = - V_103 ;
}
} else
error = - V_103 ;
if ( ! error )
F_71 ( L_24 ,
V_98 [ V_19 ] ) ;
F_4 ( & V_12 ) ;
return error ? error : V_99 ;
}
static T_3 F_91 ( struct V_90 * V_91 , struct V_92 * V_93 ,
char * V_94 )
{
return sprintf ( V_94 , L_25 , F_84 ( V_78 ) ,
F_85 ( V_78 ) ) ;
}
static T_3 F_92 ( struct V_90 * V_91 , struct V_92 * V_93 ,
const char * V_94 , T_4 V_99 )
{
unsigned int V_104 , V_105 ;
T_5 V_106 ;
int V_107 = - V_103 ;
if ( sscanf ( V_94 , L_26 , & V_104 , & V_105 ) != 2 )
goto V_108;
V_106 = F_93 ( V_104 , V_105 ) ;
if ( V_104 != F_84 ( V_106 ) || V_105 != F_85 ( V_106 ) )
goto V_108;
F_3 ( & V_12 ) ;
V_78 = V_106 ;
F_4 ( & V_12 ) ;
F_7 ( V_18 L_27 ) ;
V_76 = 0 ;
F_76 () ;
V_107 = V_99 ;
V_108:
return V_107 ;
}
static T_3 F_94 ( struct V_90 * V_91 , struct V_92 * V_93 ,
char * V_94 )
{
return sprintf ( V_94 , L_28 , V_109 ) ;
}
static T_3 F_95 ( struct V_90 * V_91 , struct V_92 * V_93 ,
const char * V_94 , T_4 V_99 )
{
unsigned long V_110 ;
if ( sscanf ( V_94 , L_29 , & V_110 ) == 1 ) {
V_109 = V_110 ;
return V_99 ;
}
return - V_103 ;
}
static T_3 F_96 ( struct V_90 * V_91 ,
struct V_92 * V_93 , char * V_94 )
{
return sprintf ( V_94 , L_28 , V_111 ) ;
}
static T_3 F_97 ( struct V_90 * V_91 ,
struct V_92 * V_93 ,
const char * V_94 , T_4 V_99 )
{
unsigned long V_110 ;
if ( sscanf ( V_94 , L_29 , & V_110 ) == 1 ) {
V_111 = V_110 ;
return V_99 ;
}
return - V_103 ;
}
static int T_6 F_98 ( void )
{
return F_99 ( V_112 , & V_113 ) ;
}
static int T_6 F_100 ( char * V_114 )
{
if ( V_76 )
return 1 ;
strncpy ( V_80 , V_114 , 255 ) ;
return 1 ;
}
static int T_6 F_101 ( char * V_114 )
{
unsigned long long V_115 ;
if ( V_76 )
return 1 ;
if ( sscanf ( V_114 , L_30 , & V_115 ) == 1 )
V_116 = V_115 ;
return 1 ;
}
static int T_6 F_102 ( char * V_114 )
{
if ( ! strncmp ( V_114 , L_31 , 8 ) )
V_76 = 1 ;
else if ( ! strncmp ( V_114 , L_32 , 10 ) )
V_72 = 1 ;
return 1 ;
}
static int T_6 F_103 ( char * V_114 )
{
V_76 = 1 ;
return 1 ;
}
static int T_6 F_104 ( char * V_114 )
{
V_83 = 1 ;
return 1 ;
}
static int T_6 F_105 ( char * V_114 )
{
V_82 = F_106 ( V_114 , NULL , 0 ) ;
return 1 ;
}
