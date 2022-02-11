static int T_1 F_1 ( char * V_1 )
{
if ( ! strcmp ( V_1 , L_1 ) )
V_2 = 0 ;
else if ( ! strcmp ( V_1 , L_2 ) )
V_2 = 1 ;
else
return 0 ;
return 1 ;
}
enum V_3 F_2 ( int V_4 )
{
return F_3 ( V_5 , V_4 ) ;
}
void F_4 ( int V_4 , enum V_3 V_6 )
{
F_3 ( V_5 , V_4 ) = V_6 ;
}
enum V_3 F_5 ( int V_4 )
{
return F_3 ( V_7 , V_4 ) ;
}
void F_6 ( int V_4 , enum V_3 V_6 )
{
F_3 ( V_7 , V_4 ) = V_6 ;
}
void F_7 ( int V_4 )
{
F_3 ( V_7 , V_4 ) = V_8 ;
}
static void F_8 ( void )
{
static struct V_9 args ;
F_9 () ;
F_10 ( V_10 == V_11 ) ;
F_11 ( L_3 ,
F_12 () , F_13 () ) ;
F_14 ( & args , V_10 , 0 , 1 , NULL ) ;
F_15 ( L_4 ) ;
}
static void F_16 ( void )
{
unsigned int V_4 = F_12 () ;
unsigned int V_12 = F_13 () ;
T_2 V_13 = 0 ;
F_9 () ;
F_17 () ;
F_18 () ;
if ( F_5 ( V_4 ) == V_14 ) {
F_4 ( V_4 , V_14 ) ;
if ( V_15 . V_16 )
V_15 . V_16 () ;
V_13 = 2 ;
F_19 () -> V_17 = 1 ;
if ( ! F_20 ( F_19 () ) )
F_19 () -> V_18 = 1 ;
while ( F_5 ( V_4 ) == V_14 ) {
while ( ! F_21 () ) {
F_22 () ;
F_9 () ;
}
F_23 ( V_13 ) ;
}
F_9 () ;
if ( ! F_20 ( F_19 () ) )
F_19 () -> V_18 = 0 ;
F_19 () -> V_17 = 0 ;
if ( F_5 ( V_4 ) == V_19 ) {
F_24 ( V_12 ) ;
F_25 () ;
F_26 () ;
}
}
F_27 ( F_5 ( V_4 ) != V_20 ) ;
F_4 ( V_4 , V_20 ) ;
F_24 ( V_12 ) ;
F_8 () ;
F_28 () ;
for(; ; ) ;
}
static int F_29 ( void )
{
int V_4 = F_12 () ;
F_30 ( V_4 , false ) ;
V_21 -> V_22 -- ;
if ( V_4 == V_23 )
V_23 = F_31 ( V_24 ) ;
F_32 () ;
return 0 ;
}
static void F_33 ( unsigned int V_4 )
{
int V_25 ;
int V_26 = 1 ;
unsigned int V_27 = F_34 ( V_4 ) ;
if ( F_5 ( V_4 ) == V_14 ) {
V_26 = 1 ;
for ( V_25 = 0 ; V_25 < 5000 ; V_25 ++ ) {
if ( F_2 ( V_4 ) == V_14 ) {
V_26 = 0 ;
break;
}
F_35 ( 1 ) ;
}
} else if ( F_5 ( V_4 ) == V_20 ) {
for ( V_25 = 0 ; V_25 < 25 ; V_25 ++ ) {
V_26 = F_36 ( V_27 ) ;
if ( V_26 == V_28 ||
V_26 == V_29 )
break;
F_37 () ;
}
}
if ( V_26 != 0 ) {
F_11 ( L_5 ,
V_4 , V_27 , V_26 ) ;
}
V_30 [ V_4 ] . V_31 = 0 ;
}
static int F_38 ( struct V_32 * V_33 )
{
unsigned int V_4 ;
T_3 V_34 , V_35 ;
int V_36 = - V_37 , V_38 , V_39 , V_40 ;
const T_4 * V_41 ;
V_41 = F_39 ( V_33 , L_6 , & V_38 ) ;
if ( ! V_41 )
return 0 ;
F_40 ( & V_34 , V_42 ) ;
F_40 ( & V_35 , V_42 ) ;
V_39 = V_38 / sizeof( V_43 ) ;
for ( V_40 = 0 ; V_40 < V_39 ; V_40 ++ )
F_41 ( V_40 , V_35 ) ;
F_42 () ;
F_10 ( ! F_43 ( V_44 , V_45 ) ) ;
F_44 ( V_34 , V_45 , V_44 ) ;
if ( F_45 ( V_34 ) ) {
F_11 ( V_46 L_7
L_8 , V_33 -> V_47 ,
F_46 () ) ;
goto V_48;
}
while ( ! F_45 ( V_35 ) )
if ( F_43 ( V_35 , V_34 ) )
break;
else
F_47 ( V_35 , V_35 , V_39 ) ;
if ( F_45 ( V_35 ) ) {
F_11 ( V_46 L_9
L_10 , V_33 -> V_49 ,
V_39 ) ;
goto V_48;
}
F_48 (cpu, tmp) {
F_10 ( F_49 ( V_4 ) ) ;
F_50 ( V_4 , true ) ;
F_51 ( V_4 , F_52 ( * V_41 ++ ) ) ;
}
V_36 = 0 ;
V_48:
F_53 () ;
F_54 ( V_34 ) ;
F_54 ( V_35 ) ;
return V_36 ;
}
static void F_55 ( struct V_32 * V_33 )
{
unsigned int V_4 ;
int V_38 , V_39 , V_40 ;
const T_4 * V_41 ;
V_43 V_50 ;
V_41 = F_39 ( V_33 , L_6 , & V_38 ) ;
if ( ! V_41 )
return;
V_39 = V_38 / sizeof( V_43 ) ;
F_42 () ;
for ( V_40 = 0 ; V_40 < V_39 ; V_40 ++ ) {
V_50 = F_52 ( V_41 [ V_40 ] ) ;
F_56 (cpu) {
if ( F_34 ( V_4 ) != V_50 )
continue;
F_10 ( F_57 ( V_4 ) ) ;
F_50 ( V_4 , false ) ;
F_51 ( V_4 , - 1 ) ;
break;
}
if ( V_4 >= V_51 )
F_11 ( V_52 L_11
L_12 , V_50 ) ;
}
F_53 () ;
}
static int F_58 ( struct V_32 * V_53 )
{
int V_54 = 0 ;
unsigned int V_4 ;
int V_38 , V_39 , V_40 ;
const T_4 * V_41 ;
V_43 V_50 ;
V_41 = F_39 ( V_53 , L_6 , & V_38 ) ;
if ( ! V_41 )
return - V_55 ;
V_39 = V_38 / sizeof( V_43 ) ;
F_42 () ;
for ( V_40 = 0 ; V_40 < V_39 ; V_40 ++ ) {
V_50 = F_52 ( V_41 [ V_40 ] ) ;
F_56 (cpu) {
if ( F_34 ( V_4 ) != V_50 )
continue;
F_10 ( F_2 ( V_4 )
!= V_20 ) ;
F_53 () ;
V_54 = F_59 ( F_60 ( V_4 ) ) ;
if ( V_54 )
goto V_56;
F_42 () ;
break;
}
if ( V_4 == F_46 () )
F_11 ( V_52 L_13
L_12 , V_50 ) ;
}
F_53 () ;
V_56:
return V_54 ;
}
static bool F_61 ( struct V_32 * V_57 , V_43 V_58 )
{
struct V_32 * V_59 = NULL ;
V_43 V_60 ;
bool V_61 ;
int V_54 ;
V_61 = false ;
F_62 (parent, child) {
V_54 = F_63 ( V_59 , L_14 ,
& V_60 ) ;
if ( V_54 )
continue;
if ( V_60 == V_58 ) {
F_64 ( V_59 ) ;
V_61 = true ;
break;
}
}
return V_61 ;
}
static bool F_65 ( struct V_32 * V_57 , V_43 V_58 )
{
bool V_61 = false ;
int V_54 , V_62 ;
V_62 = 0 ;
while ( ! V_61 ) {
V_43 V_63 ;
V_54 = F_66 ( V_57 , L_15 ,
V_62 ++ , & V_63 ) ;
if ( V_54 )
break;
if ( V_63 == V_58 )
V_61 = true ;
}
return V_61 ;
}
static T_5 F_67 ( V_43 V_58 )
{
struct V_32 * V_53 , * V_57 ;
int V_54 , V_64 ;
F_68 ( L_16 , V_58 ) ;
V_57 = F_69 ( L_17 ) ;
if ( ! V_57 ) {
F_70 ( L_18 ) ;
return - V_65 ;
}
if ( F_61 ( V_57 , V_58 ) ) {
F_64 ( V_57 ) ;
F_70 ( L_19 , V_58 ) ;
return - V_55 ;
}
if ( ! F_65 ( V_57 , V_58 ) ) {
F_64 ( V_57 ) ;
F_70 ( L_20 , V_58 ) ;
return - V_55 ;
}
V_54 = F_71 ( V_58 ) ;
if ( V_54 ) {
F_70 ( L_21 ,
V_54 , V_58 ) ;
F_64 ( V_57 ) ;
return - V_55 ;
}
V_53 = F_72 ( F_73 ( V_58 ) , V_57 ) ;
F_64 ( V_57 ) ;
if ( ! V_53 ) {
F_70 ( L_22 ,
V_58 ) ;
F_74 ( V_58 ) ;
return - V_55 ;
}
V_54 = F_75 ( V_53 ) ;
if ( V_54 ) {
V_64 = V_54 ;
F_70 ( L_23 ,
V_53 -> V_49 , V_54 , V_58 ) ;
V_54 = F_74 ( V_58 ) ;
if ( ! V_54 )
F_76 ( V_53 ) ;
return V_64 ;
}
V_54 = F_58 ( V_53 ) ;
if ( V_54 ) {
V_64 = V_54 ;
F_70 ( L_24 ,
V_53 -> V_49 , V_54 , V_58 ) ;
V_54 = F_77 ( V_53 ) ;
if ( ! V_54 )
F_74 ( V_58 ) ;
return V_64 ;
}
F_68 ( L_25 , V_53 -> V_49 ,
V_58 ) ;
return V_54 ;
}
static int F_78 ( struct V_32 * V_53 )
{
int V_54 = 0 ;
unsigned int V_4 ;
int V_38 , V_39 , V_40 ;
const T_4 * V_41 ;
V_43 V_50 ;
V_41 = F_39 ( V_53 , L_6 , & V_38 ) ;
if ( ! V_41 )
return - V_55 ;
V_39 = V_38 / sizeof( V_43 ) ;
F_42 () ;
for ( V_40 = 0 ; V_40 < V_39 ; V_40 ++ ) {
V_50 = F_52 ( V_41 [ V_40 ] ) ;
F_56 (cpu) {
if ( F_34 ( V_4 ) != V_50 )
continue;
if ( F_2 ( V_4 ) == V_20 )
break;
if ( F_2 ( V_4 ) == V_19 ) {
F_6 ( V_4 ,
V_20 ) ;
F_53 () ;
V_54 = F_79 ( F_60 ( V_4 ) ) ;
if ( V_54 )
goto V_56;
F_42 () ;
break;
}
F_6 ( V_4 , V_20 ) ;
F_10 ( F_80 ( V_66 , V_50 )
!= V_67 ) ;
F_81 ( V_4 ) ;
break;
}
if ( V_4 == F_46 () )
F_11 ( V_52 L_26 , V_50 ) ;
}
F_53 () ;
V_56:
return V_54 ;
}
static T_5 F_82 ( struct V_32 * V_53 , V_43 V_58 )
{
int V_54 ;
F_68 ( L_27 ,
V_53 -> V_49 , V_58 ) ;
V_54 = F_78 ( V_53 ) ;
if ( V_54 ) {
F_70 ( L_28 , V_53 -> V_49 , V_54 ) ;
return - V_55 ;
}
V_54 = F_74 ( V_58 ) ;
if ( V_54 ) {
F_70 ( L_29 ,
V_58 , V_53 -> V_49 , V_54 ) ;
F_58 ( V_53 ) ;
return V_54 ;
}
V_54 = F_77 ( V_53 ) ;
if ( V_54 ) {
int V_64 = V_54 ;
F_70 ( L_30 , V_53 -> V_49 , V_54 ) ;
V_54 = F_71 ( V_58 ) ;
if ( ! V_54 )
F_58 ( V_53 ) ;
return V_64 ;
}
F_68 ( L_31 , V_58 ) ;
return 0 ;
}
static struct V_32 * F_83 ( V_43 V_58 )
{
struct V_32 * V_53 ;
V_43 V_68 ;
int V_54 ;
F_84 (dn, L_32 ) {
V_54 = F_63 ( V_53 , L_14 , & V_68 ) ;
if ( V_54 )
continue;
if ( V_68 == V_58 )
break;
}
return V_53 ;
}
static int F_85 ( V_43 V_58 )
{
struct V_32 * V_53 ;
int V_54 ;
V_53 = F_83 ( V_58 ) ;
if ( ! V_53 ) {
F_70 ( L_33 ,
V_58 ) ;
return - V_65 ;
}
V_54 = F_82 ( V_53 , V_58 ) ;
F_64 ( V_53 ) ;
return V_54 ;
}
static int F_86 ( V_43 * V_69 , int V_70 )
{
struct V_32 * V_53 ;
int V_71 = 0 ;
int V_54 ;
F_84 (dn, L_32 ) {
V_71 ++ ;
if ( V_71 > V_70 ) {
F_64 ( V_53 ) ;
break;
}
V_54 = F_63 ( V_53 , L_14 ,
& V_69 [ V_71 - 1 ] ) ;
if ( V_54 ) {
F_70 ( L_34 ,
V_53 -> V_49 ) ;
F_64 ( V_53 ) ;
return - 1 ;
}
}
if ( V_71 < V_70 ) {
F_70 ( L_35 ,
V_71 , V_70 ) ;
} else if ( V_71 == V_70 ) {
F_70 ( L_36 ) ;
}
return V_71 ;
}
static int F_87 ( V_43 V_70 )
{
V_43 * V_69 ;
int V_71 ;
int V_72 = 0 ;
int V_40 , V_54 ;
F_68 ( L_37 , V_70 ) ;
V_69 = F_88 ( V_70 , sizeof( * V_69 ) , V_42 ) ;
if ( ! V_69 )
return - V_55 ;
V_71 = F_86 ( V_69 , V_70 ) ;
if ( V_71 <= V_70 ) {
F_89 ( V_69 ) ;
return - V_55 ;
}
for ( V_40 = 0 ; V_40 < V_70 ; V_40 ++ ) {
V_54 = F_85 ( V_69 [ V_40 ] ) ;
if ( V_54 )
break;
V_72 ++ ;
}
if ( V_72 != V_70 ) {
F_70 ( L_38 ) ;
for ( V_40 = 0 ; V_40 < V_72 ; V_40 ++ )
F_67 ( V_69 [ V_40 ] ) ;
V_54 = - V_55 ;
} else {
V_54 = 0 ;
}
F_89 ( V_69 ) ;
return V_54 ;
}
static int F_90 ( V_43 * V_69 , V_43 V_73 )
{
struct V_32 * V_57 ;
int V_71 = 0 ;
int V_62 , V_54 ;
V_57 = F_69 ( L_17 ) ;
if ( ! V_57 ) {
F_70 ( L_39 ) ;
F_89 ( V_69 ) ;
return - 1 ;
}
V_62 = 1 ;
while ( V_71 < V_73 ) {
V_43 V_63 ;
V_54 = F_66 ( V_57 , L_15 ,
V_62 ++ , & V_63 ) ;
if ( V_54 )
break;
if ( F_61 ( V_57 , V_63 ) )
continue;
V_69 [ V_71 ++ ] = V_63 ;
}
F_64 ( V_57 ) ;
return V_71 ;
}
static int F_91 ( V_43 V_73 )
{
V_43 * V_69 ;
int V_74 = 0 ;
int V_71 ;
int V_40 , V_54 ;
F_68 ( L_40 , V_73 ) ;
V_69 = F_88 ( V_73 , sizeof( * V_69 ) , V_42 ) ;
if ( ! V_69 )
return - V_55 ;
V_71 = F_90 ( V_69 , V_73 ) ;
if ( V_71 < V_73 ) {
F_70 ( L_41 ,
V_71 , V_73 ) ;
F_89 ( V_69 ) ;
return - V_55 ;
}
for ( V_40 = 0 ; V_40 < V_73 ; V_40 ++ ) {
V_54 = F_67 ( V_69 [ V_40 ] ) ;
if ( V_54 )
break;
V_74 ++ ;
}
if ( V_74 < V_73 ) {
F_70 ( L_42 ) ;
for ( V_40 = 0 ; V_40 < V_74 ; V_40 ++ )
F_85 ( V_69 [ V_40 ] ) ;
V_54 = - V_55 ;
} else {
V_54 = 0 ;
}
F_89 ( V_69 ) ;
return V_54 ;
}
int F_92 ( struct V_75 * V_76 )
{
V_43 V_77 , V_58 ;
int V_54 ;
V_77 = V_76 -> V_78 . V_79 ;
V_58 = V_76 -> V_78 . V_58 ;
F_93 () ;
switch ( V_76 -> V_80 ) {
case V_81 :
if ( V_76 -> V_82 == V_83 )
V_54 = F_87 ( V_77 ) ;
else if ( V_76 -> V_82 == V_84 )
V_54 = F_85 ( V_58 ) ;
else
V_54 = - V_55 ;
break;
case V_85 :
if ( V_76 -> V_82 == V_83 )
V_54 = F_91 ( V_77 ) ;
else if ( V_76 -> V_82 == V_84 )
V_54 = F_67 ( V_58 ) ;
else
V_54 = - V_55 ;
break;
default:
F_94 ( L_43 , V_76 -> V_80 ) ;
V_54 = - V_55 ;
break;
}
F_95 () ;
return V_54 ;
}
static T_5 F_96 ( const char * V_86 , T_6 V_77 )
{
V_43 V_58 ;
int V_54 ;
V_54 = F_97 ( V_86 , 0 , & V_58 ) ;
if ( V_54 )
return - V_55 ;
V_54 = F_67 ( V_58 ) ;
return V_54 ? V_54 : V_77 ;
}
static T_5 F_98 ( const char * V_86 , T_6 V_77 )
{
struct V_32 * V_53 ;
V_43 V_58 ;
int V_54 ;
V_53 = F_69 ( V_86 ) ;
if ( ! V_53 )
return - V_55 ;
V_54 = F_63 ( V_53 , L_14 , & V_58 ) ;
if ( V_54 ) {
F_64 ( V_53 ) ;
return - V_55 ;
}
V_54 = F_82 ( V_53 , V_58 ) ;
F_64 ( V_53 ) ;
return V_54 ? V_54 : V_77 ;
}
static int F_99 ( struct V_87 * V_88 ,
unsigned long V_80 , void * V_89 )
{
struct V_90 * V_91 = V_89 ;
int V_36 = 0 ;
switch ( V_80 ) {
case V_92 :
V_36 = F_38 ( V_91 -> V_53 ) ;
break;
case V_93 :
F_55 ( V_91 -> V_53 ) ;
break;
}
return F_100 ( V_36 ) ;
}
static int F_101 ( void )
{
memset ( V_94 , 0 , V_95 ) ;
return F_102 ( F_103 ( L_44 ) , 3 , 1 ,
NULL ,
V_96 ,
F_104 ( V_94 ) ,
V_95 ) ;
}
static int T_1 F_105 ( void )
{
struct V_32 * V_33 ;
const char * V_97 ;
int V_4 ;
int V_98 ;
#ifdef F_106
V_15 . V_99 = F_96 ;
V_15 . V_100 = F_98 ;
#endif
F_107 (np, L_45 ) {
V_97 = F_39 ( V_33 , L_46 , NULL ) ;
if ( strstr ( V_97 , L_47 ) ) {
F_64 ( V_33 ) ;
F_11 ( V_101 L_48
L_49 ) ;
return 0 ;
}
}
V_10 = F_103 ( L_50 ) ;
V_98 = F_103 ( L_51 ) ;
if ( V_10 == V_11 ||
V_98 == V_11 ) {
F_11 ( V_101 L_52
L_53 ) ;
return 0 ;
}
V_15 . V_102 = F_16 ;
V_103 -> V_104 = F_29 ;
V_103 -> V_102 = F_33 ;
if ( F_108 ( V_105 ) ) {
F_109 ( & V_106 ) ;
F_42 () ;
if ( V_2 && F_101 () == 0 ) {
V_8 = V_14 ;
F_110 (cpu)
F_7 ( V_4 ) ;
}
F_53 () ;
}
return 0 ;
}
