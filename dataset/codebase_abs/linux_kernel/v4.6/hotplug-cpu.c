static int T_1 F_1 ( char * V_1 )
{
return ( F_2 ( V_1 , & V_2 ) == 0 ) ;
}
enum V_3 F_3 ( int V_4 )
{
return F_4 ( V_5 , V_4 ) ;
}
void F_5 ( int V_4 , enum V_3 V_6 )
{
F_4 ( V_5 , V_4 ) = V_6 ;
}
enum V_3 F_6 ( int V_4 )
{
return F_4 ( V_7 , V_4 ) ;
}
void F_7 ( int V_4 , enum V_3 V_6 )
{
F_4 ( V_7 , V_4 ) = V_6 ;
}
void F_8 ( int V_4 )
{
F_4 ( V_7 , V_4 ) = V_8 ;
}
static void F_9 ( void )
{
static struct V_9 args ;
F_10 () ;
F_11 ( V_10 == V_11 ) ;
F_12 ( L_1 ,
F_13 () , F_14 () ) ;
F_15 ( & args , V_10 , 0 , 1 , NULL ) ;
F_16 ( L_2 ) ;
}
static void F_17 ( void )
{
unsigned int V_4 = F_13 () ;
unsigned int V_12 = F_14 () ;
T_2 V_13 = 0 ;
F_10 () ;
F_18 () ;
F_19 () ;
if ( F_6 ( V_4 ) == V_14 ) {
F_5 ( V_4 , V_14 ) ;
if ( V_15 . V_16 )
V_15 . V_16 () ;
V_13 = 2 ;
F_20 () -> V_17 = 1 ;
if ( ! F_21 ( F_20 () ) )
F_20 () -> V_18 = 1 ;
while ( F_6 ( V_4 ) == V_14 ) {
while ( ! F_22 () ) {
F_23 () ;
F_10 () ;
}
F_24 ( V_13 ) ;
}
F_10 () ;
if ( ! F_21 ( F_20 () ) )
F_20 () -> V_18 = 0 ;
F_20 () -> V_17 = 0 ;
if ( F_6 ( V_4 ) == V_19 ) {
F_25 ( V_12 ) ;
F_26 () ;
F_27 () ;
}
}
F_28 ( F_6 ( V_4 ) != V_20 ) ;
F_5 ( V_4 , V_20 ) ;
F_25 ( V_12 ) ;
F_9 () ;
F_29 () ;
for(; ; ) ;
}
static int F_30 ( void )
{
int V_4 = F_13 () ;
F_31 ( V_4 , false ) ;
V_21 -> V_22 -- ;
if ( V_4 == V_23 )
V_23 = F_32 ( V_24 ) ;
F_33 () ;
return 0 ;
}
static void F_34 ( unsigned int V_4 )
{
int V_25 ;
int V_26 = 1 ;
unsigned int V_27 = F_35 ( V_4 ) ;
if ( F_6 ( V_4 ) == V_14 ) {
V_26 = 1 ;
for ( V_25 = 0 ; V_25 < 5000 ; V_25 ++ ) {
if ( F_3 ( V_4 ) == V_14 ) {
V_26 = 0 ;
break;
}
F_36 ( 1 ) ;
}
} else if ( F_6 ( V_4 ) == V_20 ) {
for ( V_25 = 0 ; V_25 < 25 ; V_25 ++ ) {
V_26 = F_37 ( V_27 ) ;
if ( V_26 == V_28 ||
V_26 == V_29 )
break;
F_38 () ;
}
}
if ( V_26 != 0 ) {
F_12 ( L_3 ,
V_4 , V_27 , V_26 ) ;
}
V_30 [ V_4 ] . V_31 = 0 ;
}
static int F_39 ( struct V_32 * V_33 )
{
unsigned int V_4 ;
T_3 V_34 , V_35 ;
int V_36 = - V_37 , V_38 , V_39 , V_40 ;
const T_4 * V_41 ;
V_41 = F_40 ( V_33 , L_4 , & V_38 ) ;
if ( ! V_41 )
return 0 ;
F_41 ( & V_34 , V_42 ) ;
F_41 ( & V_35 , V_42 ) ;
V_39 = V_38 / sizeof( V_43 ) ;
for ( V_40 = 0 ; V_40 < V_39 ; V_40 ++ )
F_42 ( V_40 , V_35 ) ;
F_43 () ;
F_11 ( ! F_44 ( V_44 , V_45 ) ) ;
F_45 ( V_34 , V_45 , V_44 ) ;
if ( F_46 ( V_34 ) ) {
F_12 ( V_46 L_5
L_6 , V_33 -> V_47 ,
F_47 () ) ;
goto V_48;
}
while ( ! F_46 ( V_35 ) )
if ( F_44 ( V_35 , V_34 ) )
break;
else
F_48 ( V_35 , V_35 , V_39 ) ;
if ( F_46 ( V_35 ) ) {
F_12 ( V_46 L_7
L_8 , V_33 -> V_49 ,
V_39 ) ;
goto V_48;
}
F_49 (cpu, tmp) {
F_11 ( F_50 ( V_4 ) ) ;
F_51 ( V_4 , true ) ;
F_52 ( V_4 , F_53 ( * V_41 ++ ) ) ;
}
V_36 = 0 ;
V_48:
F_54 () ;
F_55 ( V_34 ) ;
F_55 ( V_35 ) ;
return V_36 ;
}
static void F_56 ( struct V_32 * V_33 )
{
unsigned int V_4 ;
int V_38 , V_39 , V_40 ;
const T_4 * V_41 ;
V_43 V_50 ;
V_41 = F_40 ( V_33 , L_4 , & V_38 ) ;
if ( ! V_41 )
return;
V_39 = V_38 / sizeof( V_43 ) ;
F_43 () ;
for ( V_40 = 0 ; V_40 < V_39 ; V_40 ++ ) {
V_50 = F_53 ( V_41 [ V_40 ] ) ;
F_57 (cpu) {
if ( F_35 ( V_4 ) != V_50 )
continue;
F_11 ( F_58 ( V_4 ) ) ;
F_51 ( V_4 , false ) ;
F_52 ( V_4 , - 1 ) ;
break;
}
if ( V_4 >= V_51 )
F_12 ( V_52 L_9
L_10 , V_50 ) ;
}
F_54 () ;
}
static int F_59 ( struct V_32 * V_53 )
{
int V_54 = 0 ;
unsigned int V_4 ;
int V_38 , V_39 , V_40 ;
const T_4 * V_41 ;
V_43 V_50 ;
V_41 = F_40 ( V_53 , L_4 , & V_38 ) ;
if ( ! V_41 )
return - V_55 ;
V_39 = V_38 / sizeof( V_43 ) ;
F_43 () ;
for ( V_40 = 0 ; V_40 < V_39 ; V_40 ++ ) {
V_50 = F_53 ( V_41 [ V_40 ] ) ;
F_57 (cpu) {
if ( F_35 ( V_4 ) != V_50 )
continue;
F_11 ( F_3 ( V_4 )
!= V_20 ) ;
F_54 () ;
V_54 = F_60 ( F_61 ( V_4 ) ) ;
if ( V_54 )
goto V_56;
F_43 () ;
break;
}
if ( V_4 == F_47 () )
F_12 ( V_52 L_11
L_10 , V_50 ) ;
}
F_54 () ;
V_56:
return V_54 ;
}
static bool F_62 ( struct V_32 * V_57 , V_43 V_58 )
{
struct V_32 * V_59 = NULL ;
V_43 V_60 ;
bool V_61 ;
int V_54 ;
V_61 = false ;
F_63 (parent, child) {
V_54 = F_64 ( V_59 , L_12 ,
& V_60 ) ;
if ( V_54 )
continue;
if ( V_60 == V_58 ) {
F_65 ( V_59 ) ;
V_61 = true ;
break;
}
}
return V_61 ;
}
static bool F_66 ( struct V_32 * V_57 , V_43 V_58 )
{
bool V_61 = false ;
int V_54 , V_62 ;
V_62 = 0 ;
while ( ! V_61 ) {
V_43 V_63 ;
V_54 = F_67 ( V_57 , L_13 ,
V_62 ++ , & V_63 ) ;
if ( V_54 )
break;
if ( V_63 == V_58 )
V_61 = true ;
}
return V_61 ;
}
static T_5 F_68 ( V_43 V_58 )
{
struct V_32 * V_53 , * V_57 ;
int V_54 , V_64 ;
F_69 ( L_14 , V_58 ) ;
V_57 = F_70 ( L_15 ) ;
if ( ! V_57 ) {
F_71 ( L_16 ) ;
return - V_65 ;
}
if ( F_62 ( V_57 , V_58 ) ) {
F_65 ( V_57 ) ;
F_71 ( L_17 , V_58 ) ;
return - V_55 ;
}
if ( ! F_66 ( V_57 , V_58 ) ) {
F_65 ( V_57 ) ;
F_71 ( L_18 , V_58 ) ;
return - V_55 ;
}
V_54 = F_72 ( V_58 ) ;
if ( V_54 ) {
F_71 ( L_19 ,
V_54 , V_58 ) ;
F_65 ( V_57 ) ;
return - V_55 ;
}
V_53 = F_73 ( F_74 ( V_58 ) , V_57 ) ;
F_65 ( V_57 ) ;
if ( ! V_53 ) {
F_71 ( L_20 ,
V_58 ) ;
F_75 ( V_58 ) ;
return - V_55 ;
}
V_54 = F_76 ( V_53 ) ;
if ( V_54 ) {
V_64 = V_54 ;
F_71 ( L_21 ,
V_53 -> V_49 , V_54 , V_58 ) ;
V_54 = F_75 ( V_58 ) ;
if ( ! V_54 )
F_77 ( V_53 ) ;
return V_64 ;
}
V_54 = F_59 ( V_53 ) ;
if ( V_54 ) {
V_64 = V_54 ;
F_71 ( L_22 ,
V_53 -> V_49 , V_54 , V_58 ) ;
V_54 = F_78 ( V_53 ) ;
if ( ! V_54 )
F_75 ( V_58 ) ;
return V_64 ;
}
F_69 ( L_23 , V_53 -> V_49 ,
V_58 ) ;
return V_54 ;
}
static int F_79 ( struct V_32 * V_53 )
{
int V_54 = 0 ;
unsigned int V_4 ;
int V_38 , V_39 , V_40 ;
const T_4 * V_41 ;
V_43 V_50 ;
V_41 = F_40 ( V_53 , L_4 , & V_38 ) ;
if ( ! V_41 )
return - V_55 ;
V_39 = V_38 / sizeof( V_43 ) ;
F_43 () ;
for ( V_40 = 0 ; V_40 < V_39 ; V_40 ++ ) {
V_50 = F_53 ( V_41 [ V_40 ] ) ;
F_57 (cpu) {
if ( F_35 ( V_4 ) != V_50 )
continue;
if ( F_3 ( V_4 ) == V_20 )
break;
if ( F_3 ( V_4 ) == V_19 ) {
F_7 ( V_4 ,
V_20 ) ;
F_54 () ;
V_54 = F_80 ( F_61 ( V_4 ) ) ;
if ( V_54 )
goto V_56;
F_43 () ;
break;
}
F_7 ( V_4 , V_20 ) ;
F_11 ( F_81 ( V_66 , V_50 )
!= V_67 ) ;
F_82 ( V_4 ) ;
break;
}
if ( V_4 == F_47 () )
F_12 ( V_52 L_24 , V_50 ) ;
}
F_54 () ;
V_56:
return V_54 ;
}
static T_5 F_83 ( struct V_32 * V_53 , V_43 V_58 )
{
int V_54 ;
F_69 ( L_25 ,
V_53 -> V_49 , V_58 ) ;
V_54 = F_79 ( V_53 ) ;
if ( V_54 ) {
F_71 ( L_26 , V_53 -> V_49 , V_54 ) ;
return - V_55 ;
}
V_54 = F_75 ( V_58 ) ;
if ( V_54 ) {
F_71 ( L_27 ,
V_58 , V_53 -> V_49 , V_54 ) ;
F_59 ( V_53 ) ;
return V_54 ;
}
V_54 = F_78 ( V_53 ) ;
if ( V_54 ) {
int V_64 = V_54 ;
F_71 ( L_28 , V_53 -> V_49 , V_54 ) ;
V_54 = F_72 ( V_58 ) ;
if ( ! V_54 )
F_59 ( V_53 ) ;
return V_64 ;
}
F_69 ( L_29 , V_58 ) ;
return 0 ;
}
static struct V_32 * F_84 ( V_43 V_58 )
{
struct V_32 * V_53 ;
V_43 V_68 ;
int V_54 ;
F_85 (dn, L_30 ) {
V_54 = F_64 ( V_53 , L_12 , & V_68 ) ;
if ( V_54 )
continue;
if ( V_68 == V_58 )
break;
}
return V_53 ;
}
static int F_86 ( V_43 V_58 )
{
struct V_32 * V_53 ;
int V_54 ;
V_53 = F_84 ( V_58 ) ;
if ( ! V_53 ) {
F_71 ( L_31 ,
V_58 ) ;
return - V_65 ;
}
V_54 = F_83 ( V_53 , V_58 ) ;
F_65 ( V_53 ) ;
return V_54 ;
}
static int F_87 ( V_43 * V_69 , int V_70 )
{
struct V_32 * V_53 ;
int V_71 = 0 ;
int V_54 ;
F_85 (dn, L_30 ) {
V_71 ++ ;
if ( V_71 > V_70 ) {
F_65 ( V_53 ) ;
break;
}
V_54 = F_64 ( V_53 , L_12 ,
& V_69 [ V_71 - 1 ] ) ;
if ( V_54 ) {
F_71 ( L_32 ,
V_53 -> V_49 ) ;
F_65 ( V_53 ) ;
return - 1 ;
}
}
if ( V_71 < V_70 ) {
F_71 ( L_33 ,
V_71 , V_70 ) ;
} else if ( V_71 == V_70 ) {
F_71 ( L_34 ) ;
}
return V_71 ;
}
static int F_88 ( V_43 V_70 )
{
V_43 * V_69 ;
int V_71 ;
int V_72 = 0 ;
int V_40 , V_54 ;
F_69 ( L_35 , V_70 ) ;
V_69 = F_89 ( V_70 , sizeof( * V_69 ) , V_42 ) ;
if ( ! V_69 )
return - V_55 ;
V_71 = F_87 ( V_69 , V_70 ) ;
if ( V_71 <= V_70 ) {
F_90 ( V_69 ) ;
return - V_55 ;
}
for ( V_40 = 0 ; V_40 < V_70 ; V_40 ++ ) {
V_54 = F_86 ( V_69 [ V_40 ] ) ;
if ( V_54 )
break;
V_72 ++ ;
}
if ( V_72 != V_70 ) {
F_71 ( L_36 ) ;
for ( V_40 = 0 ; V_40 < V_72 ; V_40 ++ )
F_68 ( V_69 [ V_40 ] ) ;
V_54 = - V_55 ;
} else {
V_54 = 0 ;
}
F_90 ( V_69 ) ;
return V_54 ;
}
static int F_91 ( V_43 * V_69 , V_43 V_73 )
{
struct V_32 * V_57 ;
int V_71 = 0 ;
int V_62 , V_54 ;
V_57 = F_70 ( L_15 ) ;
if ( ! V_57 ) {
F_71 ( L_37 ) ;
F_90 ( V_69 ) ;
return - 1 ;
}
V_62 = 1 ;
while ( V_71 < V_73 ) {
V_43 V_63 ;
V_54 = F_67 ( V_57 , L_13 ,
V_62 ++ , & V_63 ) ;
if ( V_54 )
break;
if ( F_62 ( V_57 , V_63 ) )
continue;
V_69 [ V_71 ++ ] = V_63 ;
}
F_65 ( V_57 ) ;
return V_71 ;
}
static int F_92 ( V_43 V_73 )
{
V_43 * V_69 ;
int V_74 = 0 ;
int V_71 ;
int V_40 , V_54 ;
F_69 ( L_38 , V_73 ) ;
V_69 = F_89 ( V_73 , sizeof( * V_69 ) , V_42 ) ;
if ( ! V_69 )
return - V_55 ;
V_71 = F_91 ( V_69 , V_73 ) ;
if ( V_71 < V_73 ) {
F_71 ( L_39 ,
V_71 , V_73 ) ;
F_90 ( V_69 ) ;
return - V_55 ;
}
for ( V_40 = 0 ; V_40 < V_73 ; V_40 ++ ) {
V_54 = F_68 ( V_69 [ V_40 ] ) ;
if ( V_54 )
break;
V_74 ++ ;
}
if ( V_74 < V_73 ) {
F_71 ( L_40 ) ;
for ( V_40 = 0 ; V_40 < V_74 ; V_40 ++ )
F_86 ( V_69 [ V_40 ] ) ;
V_54 = - V_55 ;
} else {
V_54 = 0 ;
}
F_90 ( V_69 ) ;
return V_54 ;
}
int F_93 ( struct V_75 * V_76 )
{
V_43 V_77 , V_58 ;
int V_54 ;
V_77 = V_76 -> V_78 . V_79 ;
V_58 = V_76 -> V_78 . V_58 ;
F_94 () ;
switch ( V_76 -> V_80 ) {
case V_81 :
if ( V_76 -> V_82 == V_83 )
V_54 = F_88 ( V_77 ) ;
else if ( V_76 -> V_82 == V_84 )
V_54 = F_86 ( V_58 ) ;
else
V_54 = - V_55 ;
break;
case V_85 :
if ( V_76 -> V_82 == V_83 )
V_54 = F_92 ( V_77 ) ;
else if ( V_76 -> V_82 == V_84 )
V_54 = F_68 ( V_58 ) ;
else
V_54 = - V_55 ;
break;
default:
F_95 ( L_41 , V_76 -> V_80 ) ;
V_54 = - V_55 ;
break;
}
F_96 () ;
return V_54 ;
}
static T_5 F_97 ( const char * V_86 , T_6 V_77 )
{
V_43 V_58 ;
int V_54 ;
V_54 = F_98 ( V_86 , 0 , & V_58 ) ;
if ( V_54 )
return - V_55 ;
V_54 = F_68 ( V_58 ) ;
return V_54 ? V_54 : V_77 ;
}
static T_5 F_99 ( const char * V_86 , T_6 V_77 )
{
struct V_32 * V_53 ;
V_43 V_58 ;
int V_54 ;
V_53 = F_70 ( V_86 ) ;
if ( ! V_53 )
return - V_55 ;
V_54 = F_64 ( V_53 , L_12 , & V_58 ) ;
if ( V_54 ) {
F_65 ( V_53 ) ;
return - V_55 ;
}
V_54 = F_83 ( V_53 , V_58 ) ;
F_65 ( V_53 ) ;
return V_54 ? V_54 : V_77 ;
}
static int F_100 ( struct V_87 * V_88 ,
unsigned long V_80 , void * V_89 )
{
struct V_90 * V_91 = V_89 ;
int V_36 = 0 ;
switch ( V_80 ) {
case V_92 :
V_36 = F_39 ( V_91 -> V_53 ) ;
break;
case V_93 :
F_56 ( V_91 -> V_53 ) ;
break;
}
return F_101 ( V_36 ) ;
}
static int F_102 ( void )
{
memset ( V_94 , 0 , V_95 ) ;
return F_103 ( F_104 ( L_42 ) , 3 , 1 ,
NULL ,
V_96 ,
F_105 ( V_94 ) ,
V_95 ) ;
}
static int T_1 F_106 ( void )
{
struct V_32 * V_33 ;
const char * V_97 ;
int V_4 ;
int V_98 ;
#ifdef F_107
V_15 . V_99 = F_97 ;
V_15 . V_100 = F_99 ;
#endif
F_108 (np, L_43 ) {
V_97 = F_40 ( V_33 , L_44 , NULL ) ;
if ( strstr ( V_97 , L_45 ) ) {
F_65 ( V_33 ) ;
F_12 ( V_101 L_46
L_47 ) ;
return 0 ;
}
}
V_10 = F_104 ( L_48 ) ;
V_98 = F_104 ( L_49 ) ;
if ( V_10 == V_11 ||
V_98 == V_11 ) {
F_12 ( V_101 L_50
L_51 ) ;
return 0 ;
}
V_15 . V_102 = F_17 ;
V_103 -> V_104 = F_30 ;
V_103 -> V_102 = F_34 ;
if ( F_109 ( V_105 ) ) {
F_110 ( & V_106 ) ;
F_43 () ;
if ( V_2 && F_102 () == 0 ) {
V_8 = V_14 ;
F_111 (cpu)
F_8 ( V_4 ) ;
}
F_54 () ;
}
return 0 ;
}
