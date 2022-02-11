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
error = F_36 ( V_35 ) ;
if ( error )
goto V_51;
error = F_37 () ;
if ( error )
goto V_51;
F_38 () ;
F_39 () ;
error = F_40 ( V_35 ) ;
if ( error )
goto V_52;
if ( F_10 ( V_53 ) )
goto V_52;
error = F_22 ( V_22 ) ;
V_54:
if ( error || ! V_45 )
F_41 () ;
V_28 = V_45 ? ( error ? V_47 : V_48 ) : V_49 ;
F_42 ( V_28 ) ;
if ( error || ! V_45 )
F_43 () ;
F_44 () ;
V_51:
F_45 ( V_28 ) ;
V_50:
F_12 ( V_22 ) ;
return error ;
V_52:
F_18 ( V_22 ) ;
goto V_54;
}
static int F_46 ( bool V_22 )
{
int error ;
error = F_23 ( V_55 ) ;
if ( error ) {
F_7 ( V_36 L_3
L_7 ) ;
return error ;
}
error = F_16 ( V_22 ) ;
if ( error )
goto V_56;
error = F_24 () ;
if ( error )
goto V_41;
F_25 () ;
error = F_26 () ;
if ( error )
goto V_42;
F_28 () ;
error = F_47 () ;
if ( ! error ) {
error = F_48 () ;
F_49 ( ! error ) ;
F_47 () ;
}
F_41 () ;
F_30 () ;
F_50 () ;
F_31 () ;
V_42:
F_32 () ;
V_41:
F_33 () ;
V_56:
F_17 ( V_22 ) ;
F_34 ( V_47 ) ;
return error ;
}
int F_51 ( int V_22 )
{
int error ;
F_52 () ;
F_38 () ;
F_39 () ;
error = F_53 ( V_55 ) ;
if ( ! error ) {
error = F_46 ( V_22 ) ;
F_54 ( V_47 ) ;
}
F_43 () ;
F_44 () ;
F_55 () ;
return error ;
}
int F_56 ( void )
{
int error ;
if ( ! V_13 )
return - V_57 ;
error = V_13 -> V_3 () ;
if ( error )
goto V_50;
V_17 = true ;
F_38 () ;
error = F_53 ( V_58 ) ;
if ( error ) {
if ( V_13 -> V_23 )
V_13 -> V_23 () ;
goto V_54;
}
error = F_23 ( V_58 ) ;
if ( error )
goto V_54;
error = V_13 -> V_6 () ;
if ( error )
goto V_38;
error = F_24 () ;
if ( error )
goto V_38;
F_25 () ;
F_26 () ;
if ( F_27 () ) {
error = - V_59 ;
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
V_54:
V_17 = false ;
F_54 ( V_49 ) ;
F_44 () ;
V_50:
V_13 -> V_4 () ;
return error ;
}
static void F_57 ( void )
{
switch ( V_14 ) {
case V_40 :
case V_60 :
break;
case V_61 :
F_58 ( NULL ) ;
break;
case V_15 :
F_56 () ;
case V_16 :
F_59 () ;
break;
}
F_60 () ;
F_7 ( V_62 L_8 ) ;
while( 1 ) ;
}
static int F_61 ( void )
{
int error = 0 ;
if ( F_62 () ) {
error = - V_63 ;
F_63 () ;
}
return error ;
}
int F_64 ( void )
{
int error ;
F_3 ( & V_12 ) ;
if ( ! F_65 ( & V_64 , - 1 , 0 ) ) {
error = - V_63 ;
goto V_65;
}
F_52 () ;
error = F_66 ( V_66 ) ;
if ( error )
goto Exit;
error = F_67 () ;
if ( error )
goto Exit;
error = F_68 () ;
if ( error )
goto Exit;
F_7 ( V_18 L_9 ) ;
F_69 () ;
F_7 ( L_10 ) ;
error = F_61 () ;
if ( error )
goto V_67;
if ( F_10 ( V_68 ) )
goto V_69;
if ( F_9 ( V_60 ) )
goto V_69;
error = F_35 ( V_14 == V_15 ) ;
if ( error )
goto V_69;
if ( V_45 ) {
unsigned int V_70 = 0 ;
if ( V_14 == V_15 )
V_70 |= V_71 ;
if ( V_72 )
V_70 |= V_73 ;
F_70 ( L_11 ) ;
error = F_71 ( V_70 ) ;
F_41 () ;
if ( ! error )
F_57 () ;
V_45 = 0 ;
F_43 () ;
} else {
F_70 ( L_12 ) ;
}
V_69:
F_63 () ;
V_67:
F_72 () ;
F_73 () ;
Exit:
F_66 ( V_74 ) ;
F_55 () ;
F_74 ( & V_64 ) ;
V_65:
F_4 ( & V_12 ) ;
return error ;
}
static int F_75 ( void )
{
int error ;
unsigned int V_70 ;
if ( V_75 )
return 0 ;
F_76 ( & V_12 , V_76 ) ;
if ( V_77 )
goto V_78;
if ( ! strlen ( V_79 ) ) {
error = - V_80 ;
goto V_65;
}
F_70 ( L_13 , V_79 ) ;
V_77 = F_77 ( V_79 ) ;
if ( ! V_77 ) {
F_78 () ;
F_79 () ;
V_77 = F_77 ( V_79 ) ;
if ( ! V_77 ) {
error = - V_81 ;
goto V_65;
}
}
V_78:
F_70 ( L_14 ,
F_80 ( V_77 ) , F_81 ( V_77 ) ) ;
F_70 ( L_15 ) ;
error = F_82 () ;
if ( error )
goto V_65;
if ( ! F_65 ( & V_64 , - 1 , 0 ) ) {
error = - V_63 ;
F_83 ( V_82 ) ;
goto V_65;
}
F_52 () ;
error = F_66 ( V_83 ) ;
if ( error )
goto V_84;
error = F_67 () ;
if ( error )
goto V_84;
error = F_68 () ;
if ( error )
goto V_84;
F_70 ( L_16 ) ;
error = F_61 () ;
if ( error ) {
F_83 ( V_82 ) ;
goto V_85;
}
F_70 ( L_17 ) ;
error = F_84 ( & V_70 ) ;
F_83 ( V_82 ) ;
if ( ! error )
F_51 ( V_70 & V_71 ) ;
F_7 ( V_36 L_18 ) ;
F_41 () ;
F_63 () ;
V_85:
F_72 () ;
F_73 () ;
V_67:
F_66 ( V_86 ) ;
F_55 () ;
F_74 ( & V_64 ) ;
V_65:
F_4 ( & V_12 ) ;
F_70 ( L_19 ) ;
return error ;
V_84:
F_83 ( V_82 ) ;
goto V_67;
}
static T_3 F_85 ( struct V_87 * V_88 , struct V_89 * V_90 ,
char * V_91 )
{
int V_92 ;
char * V_25 = V_91 ;
for ( V_92 = V_93 ; V_92 <= V_94 ; V_92 ++ ) {
if ( ! V_95 [ V_92 ] )
continue;
switch ( V_92 ) {
case V_16 :
case V_61 :
case V_40 :
case V_60 :
break;
case V_15 :
if ( V_13 )
break;
continue;
}
if ( V_92 == V_14 )
V_91 += sprintf ( V_91 , L_20 , V_95 [ V_92 ] ) ;
else
V_91 += sprintf ( V_91 , L_21 , V_95 [ V_92 ] ) ;
}
V_91 += sprintf ( V_91 , L_22 ) ;
return V_91 - V_25 ;
}
static T_3 F_86 ( struct V_87 * V_88 , struct V_89 * V_90 ,
const char * V_91 , T_4 V_96 )
{
int error = 0 ;
int V_92 ;
int V_97 ;
char * V_98 ;
int V_19 = V_99 ;
V_98 = memchr ( V_91 , '\n' , V_96 ) ;
V_97 = V_98 ? V_98 - V_91 : V_96 ;
F_3 ( & V_12 ) ;
for ( V_92 = V_93 ; V_92 <= V_94 ; V_92 ++ ) {
if ( V_97 == strlen ( V_95 [ V_92 ] )
&& ! strncmp ( V_91 , V_95 [ V_92 ] , V_97 ) ) {
V_19 = V_92 ;
break;
}
}
if ( V_19 != V_99 ) {
switch ( V_19 ) {
case V_16 :
case V_61 :
case V_40 :
case V_60 :
V_14 = V_19 ;
break;
case V_15 :
if ( V_13 )
V_14 = V_19 ;
else
error = - V_100 ;
}
} else
error = - V_100 ;
if ( ! error )
F_70 ( L_23 ,
V_95 [ V_19 ] ) ;
F_4 ( & V_12 ) ;
return error ? error : V_96 ;
}
static T_3 F_87 ( struct V_87 * V_88 , struct V_89 * V_90 ,
char * V_91 )
{
return sprintf ( V_91 , L_24 , F_80 ( V_77 ) ,
F_81 ( V_77 ) ) ;
}
static T_3 F_88 ( struct V_87 * V_88 , struct V_89 * V_90 ,
const char * V_91 , T_4 V_96 )
{
unsigned int V_101 , V_102 ;
T_5 V_103 ;
int V_104 = - V_100 ;
if ( sscanf ( V_91 , L_25 , & V_101 , & V_102 ) != 2 )
goto V_105;
V_103 = F_89 ( V_101 , V_102 ) ;
if ( V_101 != F_80 ( V_103 ) || V_102 != F_81 ( V_103 ) )
goto V_105;
F_3 ( & V_12 ) ;
V_77 = V_103 ;
F_4 ( & V_12 ) ;
F_7 ( V_18 L_26 ) ;
V_75 = 0 ;
F_75 () ;
V_104 = V_96 ;
V_105:
return V_104 ;
}
static T_3 F_90 ( struct V_87 * V_88 , struct V_89 * V_90 ,
char * V_91 )
{
return sprintf ( V_91 , L_27 , V_106 ) ;
}
static T_3 F_91 ( struct V_87 * V_88 , struct V_89 * V_90 ,
const char * V_91 , T_4 V_96 )
{
unsigned long V_107 ;
if ( sscanf ( V_91 , L_28 , & V_107 ) == 1 ) {
V_106 = V_107 ;
return V_96 ;
}
return - V_100 ;
}
static T_3 F_92 ( struct V_87 * V_88 ,
struct V_89 * V_90 , char * V_91 )
{
return sprintf ( V_91 , L_27 , V_108 ) ;
}
static T_3 F_93 ( struct V_87 * V_88 ,
struct V_89 * V_90 ,
const char * V_91 , T_4 V_96 )
{
unsigned long V_107 ;
if ( sscanf ( V_91 , L_28 , & V_107 ) == 1 ) {
V_108 = V_107 ;
return V_96 ;
}
return - V_100 ;
}
static int T_6 F_94 ( void )
{
return F_95 ( V_109 , & V_110 ) ;
}
static int T_6 F_96 ( char * V_111 )
{
if ( V_75 )
return 1 ;
strncpy ( V_79 , V_111 , 255 ) ;
return 1 ;
}
static int T_6 F_97 ( char * V_111 )
{
unsigned long long V_112 ;
if ( V_75 )
return 1 ;
if ( sscanf ( V_111 , L_29 , & V_112 ) == 1 )
V_113 = V_112 ;
return 1 ;
}
static int T_6 F_98 ( char * V_111 )
{
if ( ! strncmp ( V_111 , L_30 , 8 ) )
V_75 = 1 ;
else if ( ! strncmp ( V_111 , L_31 , 10 ) )
V_72 = 1 ;
return 1 ;
}
static int T_6 F_99 ( char * V_111 )
{
V_75 = 1 ;
return 1 ;
}
