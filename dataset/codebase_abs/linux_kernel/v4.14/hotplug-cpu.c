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
if ( F_19 () )
F_20 () ;
else
F_21 () ;
if ( F_6 ( V_4 ) == V_14 ) {
F_5 ( V_4 , V_14 ) ;
if ( V_15 . V_16 )
V_15 . V_16 () ;
V_13 = 2 ;
F_22 () -> V_17 = 1 ;
if ( ! F_23 ( F_22 () ) )
F_22 () -> V_18 = 1 ;
while ( F_6 ( V_4 ) == V_14 ) {
while ( ! F_24 () ) {
F_25 () ;
F_10 () ;
}
F_26 ( V_13 ) ;
}
F_10 () ;
if ( ! F_23 ( F_22 () ) )
F_22 () -> V_18 = 0 ;
F_22 () -> V_17 = 0 ;
if ( F_6 ( V_4 ) == V_19 ) {
F_27 ( V_12 ) ;
F_28 () ;
F_29 () ;
}
}
F_30 ( F_6 ( V_4 ) != V_20 ) ;
F_5 ( V_4 , V_20 ) ;
F_27 ( V_12 ) ;
F_9 () ;
F_31 () ;
for(; ; ) ;
}
static int F_32 ( void )
{
int V_4 = F_13 () ;
F_33 ( V_4 , false ) ;
V_21 -> V_22 -- ;
if ( V_4 == V_23 )
V_23 = F_34 ( V_24 ) ;
if ( F_19 () )
F_35 () ;
else
F_36 () ;
return 0 ;
}
static void F_37 ( unsigned int V_4 )
{
int V_25 ;
int V_26 = 1 ;
unsigned int V_27 = F_38 ( V_4 ) ;
if ( F_6 ( V_4 ) == V_14 ) {
V_26 = 1 ;
for ( V_25 = 0 ; V_25 < 5000 ; V_25 ++ ) {
if ( F_3 ( V_4 ) == V_14 ) {
V_26 = 0 ;
break;
}
F_39 ( 1 ) ;
}
} else if ( F_6 ( V_4 ) == V_20 ) {
for ( V_25 = 0 ; V_25 < 25 ; V_25 ++ ) {
V_26 = F_40 ( V_27 ) ;
if ( V_26 == V_28 ||
V_26 == V_29 )
break;
F_41 () ;
}
}
if ( V_26 != 0 ) {
F_12 ( L_3 ,
V_4 , V_27 , V_26 ) ;
}
V_30 [ V_4 ] . V_31 = 0 ;
}
static int F_42 ( struct V_32 * V_33 )
{
unsigned int V_4 ;
T_3 V_34 , V_35 ;
int V_36 = - V_37 , V_38 , V_39 , V_40 ;
const T_4 * V_41 ;
V_41 = F_43 ( V_33 , L_4 , & V_38 ) ;
if ( ! V_41 )
return 0 ;
F_44 ( & V_34 , V_42 ) ;
F_44 ( & V_35 , V_42 ) ;
V_39 = V_38 / sizeof( V_43 ) ;
for ( V_40 = 0 ; V_40 < V_39 ; V_40 ++ )
F_45 ( V_40 , V_35 ) ;
F_46 () ;
F_11 ( ! F_47 ( V_44 , V_45 ) ) ;
F_48 ( V_34 , V_45 , V_44 ) ;
if ( F_49 ( V_34 ) ) {
F_12 ( V_46 L_5
L_6 , V_33 ,
F_50 () ) ;
goto V_47;
}
while ( ! F_49 ( V_35 ) )
if ( F_47 ( V_35 , V_34 ) )
break;
else
F_51 ( V_35 , V_35 , V_39 ) ;
if ( F_49 ( V_35 ) ) {
F_12 ( V_46 L_7
L_8 , V_33 -> V_48 ,
V_39 ) ;
goto V_47;
}
F_52 (cpu, tmp) {
F_11 ( F_53 ( V_4 ) ) ;
F_54 ( V_4 , true ) ;
F_55 ( V_4 , F_56 ( * V_41 ++ ) ) ;
}
V_36 = 0 ;
V_47:
F_57 () ;
F_58 ( V_34 ) ;
F_58 ( V_35 ) ;
return V_36 ;
}
static void F_59 ( struct V_32 * V_33 )
{
unsigned int V_4 ;
int V_38 , V_39 , V_40 ;
const T_4 * V_41 ;
V_43 V_49 ;
V_41 = F_43 ( V_33 , L_4 , & V_38 ) ;
if ( ! V_41 )
return;
V_39 = V_38 / sizeof( V_43 ) ;
F_46 () ;
for ( V_40 = 0 ; V_40 < V_39 ; V_40 ++ ) {
V_49 = F_56 ( V_41 [ V_40 ] ) ;
F_60 (cpu) {
if ( F_38 ( V_4 ) != V_49 )
continue;
F_11 ( F_61 ( V_4 ) ) ;
F_54 ( V_4 , false ) ;
F_55 ( V_4 , - 1 ) ;
break;
}
if ( V_4 >= V_50 )
F_12 ( V_51 L_9
L_10 , V_49 ) ;
}
F_57 () ;
}
static int F_62 ( struct V_32 * V_52 )
{
int V_53 = 0 ;
unsigned int V_4 ;
int V_38 , V_39 , V_40 ;
const T_4 * V_41 ;
V_43 V_49 ;
V_41 = F_43 ( V_52 , L_4 , & V_38 ) ;
if ( ! V_41 )
return - V_54 ;
V_39 = V_38 / sizeof( V_43 ) ;
F_46 () ;
for ( V_40 = 0 ; V_40 < V_39 ; V_40 ++ ) {
V_49 = F_56 ( V_41 [ V_40 ] ) ;
F_60 (cpu) {
if ( F_38 ( V_4 ) != V_49 )
continue;
F_11 ( F_3 ( V_4 )
!= V_20 ) ;
F_57 () ;
V_53 = F_63 ( F_64 ( V_4 ) ) ;
if ( V_53 )
goto V_55;
F_46 () ;
break;
}
if ( V_4 == F_50 () )
F_12 ( V_51 L_11
L_10 , V_49 ) ;
}
F_57 () ;
V_55:
return V_53 ;
}
static bool F_65 ( struct V_32 * V_56 , V_43 V_57 )
{
struct V_32 * V_58 = NULL ;
V_43 V_59 ;
bool V_60 ;
int V_53 ;
V_60 = false ;
F_66 (parent, child) {
V_53 = F_67 ( V_58 , L_12 ,
& V_59 ) ;
if ( V_53 )
continue;
if ( V_59 == V_57 ) {
F_68 ( V_58 ) ;
V_60 = true ;
break;
}
}
return V_60 ;
}
static bool F_69 ( struct V_32 * V_56 , V_43 V_57 )
{
bool V_60 = false ;
int V_53 , V_61 ;
V_61 = 0 ;
while ( ! V_60 ) {
V_43 V_62 ;
V_53 = F_70 ( V_56 , L_13 ,
V_61 ++ , & V_62 ) ;
if ( V_53 )
break;
if ( V_62 == V_57 )
V_60 = true ;
}
return V_60 ;
}
static T_5 F_71 ( V_43 V_57 )
{
struct V_32 * V_52 , * V_56 ;
int V_53 , V_63 ;
F_72 ( L_14 , V_57 ) ;
V_56 = F_73 ( L_15 ) ;
if ( ! V_56 ) {
F_74 ( L_16 ) ;
return - V_64 ;
}
if ( F_65 ( V_56 , V_57 ) ) {
F_68 ( V_56 ) ;
F_74 ( L_17 , V_57 ) ;
return - V_54 ;
}
if ( ! F_69 ( V_56 , V_57 ) ) {
F_68 ( V_56 ) ;
F_74 ( L_18 , V_57 ) ;
return - V_54 ;
}
V_53 = F_75 ( V_57 ) ;
if ( V_53 ) {
F_74 ( L_19 ,
V_53 , V_57 ) ;
F_68 ( V_56 ) ;
return - V_54 ;
}
V_52 = F_76 ( F_77 ( V_57 ) , V_56 ) ;
if ( ! V_52 ) {
F_74 ( L_20 ,
V_57 ) ;
F_78 ( V_57 ) ;
F_68 ( V_56 ) ;
return - V_54 ;
}
V_53 = F_79 ( V_52 , V_56 ) ;
F_68 ( V_56 ) ;
if ( V_53 ) {
V_63 = V_53 ;
F_74 ( L_21 ,
V_52 -> V_48 , V_53 , V_57 ) ;
V_53 = F_78 ( V_57 ) ;
if ( ! V_53 )
F_80 ( V_52 ) ;
return V_63 ;
}
V_53 = F_62 ( V_52 ) ;
if ( V_53 ) {
V_63 = V_53 ;
F_74 ( L_22 ,
V_52 -> V_48 , V_53 , V_57 ) ;
V_53 = F_81 ( V_52 ) ;
if ( ! V_53 )
F_78 ( V_57 ) ;
return V_63 ;
}
F_72 ( L_23 , V_52 -> V_48 ,
V_57 ) ;
return V_53 ;
}
static int F_82 ( struct V_32 * V_52 )
{
int V_53 = 0 ;
unsigned int V_4 ;
int V_38 , V_39 , V_40 ;
const T_4 * V_41 ;
V_43 V_49 ;
V_41 = F_43 ( V_52 , L_4 , & V_38 ) ;
if ( ! V_41 )
return - V_54 ;
V_39 = V_38 / sizeof( V_43 ) ;
F_46 () ;
for ( V_40 = 0 ; V_40 < V_39 ; V_40 ++ ) {
V_49 = F_56 ( V_41 [ V_40 ] ) ;
F_60 (cpu) {
if ( F_38 ( V_4 ) != V_49 )
continue;
if ( F_3 ( V_4 ) == V_20 )
break;
if ( F_3 ( V_4 ) == V_19 ) {
F_7 ( V_4 ,
V_20 ) ;
F_57 () ;
V_53 = F_83 ( F_64 ( V_4 ) ) ;
if ( V_53 )
goto V_55;
F_46 () ;
break;
}
F_7 ( V_4 , V_20 ) ;
F_11 ( F_84 ( V_65 , V_49 )
!= V_66 ) ;
F_85 ( V_4 ) ;
break;
}
if ( V_4 == F_50 () )
F_12 ( V_51 L_24 , V_49 ) ;
}
F_57 () ;
V_55:
return V_53 ;
}
static T_5 F_86 ( struct V_32 * V_52 , V_43 V_57 )
{
int V_53 ;
F_72 ( L_25 ,
V_52 -> V_48 , V_57 ) ;
V_53 = F_82 ( V_52 ) ;
if ( V_53 ) {
F_74 ( L_26 , V_52 -> V_48 , V_53 ) ;
return - V_54 ;
}
V_53 = F_78 ( V_57 ) ;
if ( V_53 ) {
F_74 ( L_27 ,
V_57 , V_52 -> V_48 , V_53 ) ;
F_62 ( V_52 ) ;
return V_53 ;
}
V_53 = F_81 ( V_52 ) ;
if ( V_53 ) {
int V_63 = V_53 ;
F_74 ( L_28 , V_52 -> V_48 , V_53 ) ;
V_53 = F_75 ( V_57 ) ;
if ( ! V_53 )
F_62 ( V_52 ) ;
return V_63 ;
}
F_72 ( L_29 , V_57 ) ;
return 0 ;
}
static struct V_32 * F_87 ( V_43 V_57 )
{
struct V_32 * V_52 ;
V_43 V_67 ;
int V_53 ;
F_88 (dn, L_30 ) {
V_53 = F_67 ( V_52 , L_12 , & V_67 ) ;
if ( V_53 )
continue;
if ( V_67 == V_57 )
break;
}
return V_52 ;
}
static int F_89 ( V_43 V_57 )
{
struct V_32 * V_52 ;
int V_53 ;
V_52 = F_87 ( V_57 ) ;
if ( ! V_52 ) {
F_74 ( L_31 ,
V_57 ) ;
return - V_64 ;
}
V_53 = F_86 ( V_52 , V_57 ) ;
F_68 ( V_52 ) ;
return V_53 ;
}
static int F_90 ( V_43 * V_68 , int V_69 )
{
struct V_32 * V_52 ;
int V_70 = 0 ;
int V_53 ;
F_88 (dn, L_30 ) {
V_70 ++ ;
if ( V_70 > V_69 ) {
F_68 ( V_52 ) ;
break;
}
V_53 = F_67 ( V_52 , L_12 ,
& V_68 [ V_70 - 1 ] ) ;
if ( V_53 ) {
F_74 ( L_32 ,
V_52 -> V_48 ) ;
F_68 ( V_52 ) ;
return - 1 ;
}
}
if ( V_70 < V_69 ) {
F_74 ( L_33 ,
V_70 , V_69 ) ;
} else if ( V_70 == V_69 ) {
F_74 ( L_34 ) ;
}
return V_70 ;
}
static int F_91 ( V_43 V_69 )
{
V_43 * V_68 ;
int V_70 ;
int V_71 = 0 ;
int V_40 , V_53 ;
F_72 ( L_35 , V_69 ) ;
V_68 = F_92 ( V_69 , sizeof( * V_68 ) , V_42 ) ;
if ( ! V_68 )
return - V_54 ;
V_70 = F_90 ( V_68 , V_69 ) ;
if ( V_70 <= V_69 ) {
F_93 ( V_68 ) ;
return - V_54 ;
}
for ( V_40 = 0 ; V_40 < V_69 ; V_40 ++ ) {
V_53 = F_89 ( V_68 [ V_40 ] ) ;
if ( V_53 )
break;
V_71 ++ ;
}
if ( V_71 != V_69 ) {
F_74 ( L_36 ) ;
for ( V_40 = 0 ; V_40 < V_71 ; V_40 ++ )
F_71 ( V_68 [ V_40 ] ) ;
V_53 = - V_54 ;
} else {
V_53 = 0 ;
}
F_93 ( V_68 ) ;
return V_53 ;
}
static int F_94 ( V_43 * V_68 , V_43 V_72 )
{
struct V_32 * V_56 ;
int V_70 = 0 ;
int V_61 , V_53 ;
V_56 = F_73 ( L_15 ) ;
if ( ! V_56 ) {
F_74 ( L_37 ) ;
F_93 ( V_68 ) ;
return - 1 ;
}
V_61 = 1 ;
while ( V_70 < V_72 ) {
V_43 V_62 ;
V_53 = F_70 ( V_56 , L_13 ,
V_61 ++ , & V_62 ) ;
if ( V_53 )
break;
if ( F_65 ( V_56 , V_62 ) )
continue;
V_68 [ V_70 ++ ] = V_62 ;
}
F_68 ( V_56 ) ;
return V_70 ;
}
static int F_95 ( V_43 V_72 )
{
V_43 * V_68 ;
int V_73 = 0 ;
int V_70 ;
int V_40 , V_53 ;
F_72 ( L_38 , V_72 ) ;
V_68 = F_92 ( V_72 , sizeof( * V_68 ) , V_42 ) ;
if ( ! V_68 )
return - V_54 ;
V_70 = F_94 ( V_68 , V_72 ) ;
if ( V_70 < V_72 ) {
F_74 ( L_39 ,
V_70 , V_72 ) ;
F_93 ( V_68 ) ;
return - V_54 ;
}
for ( V_40 = 0 ; V_40 < V_72 ; V_40 ++ ) {
V_53 = F_71 ( V_68 [ V_40 ] ) ;
if ( V_53 )
break;
V_73 ++ ;
}
if ( V_73 < V_72 ) {
F_74 ( L_40 ) ;
for ( V_40 = 0 ; V_40 < V_73 ; V_40 ++ )
F_89 ( V_68 [ V_40 ] ) ;
V_53 = - V_54 ;
} else {
V_53 = 0 ;
}
F_93 ( V_68 ) ;
return V_53 ;
}
int F_96 ( struct V_74 * V_75 )
{
V_43 V_76 , V_57 ;
int V_53 ;
V_76 = V_75 -> V_77 . V_78 ;
V_57 = V_75 -> V_77 . V_57 ;
F_97 () ;
switch ( V_75 -> V_79 ) {
case V_80 :
if ( V_75 -> V_81 == V_82 )
V_53 = F_91 ( V_76 ) ;
else if ( V_75 -> V_81 == V_83 )
V_53 = F_89 ( V_57 ) ;
else
V_53 = - V_54 ;
break;
case V_84 :
if ( V_75 -> V_81 == V_82 )
V_53 = F_95 ( V_76 ) ;
else if ( V_75 -> V_81 == V_83 )
V_53 = F_71 ( V_57 ) ;
else
V_53 = - V_54 ;
break;
default:
F_98 ( L_41 , V_75 -> V_79 ) ;
V_53 = - V_54 ;
break;
}
F_99 () ;
return V_53 ;
}
static T_5 F_100 ( const char * V_85 , T_6 V_76 )
{
V_43 V_57 ;
int V_53 ;
V_53 = F_101 ( V_85 , 0 , & V_57 ) ;
if ( V_53 )
return - V_54 ;
V_53 = F_71 ( V_57 ) ;
return V_53 ? V_53 : V_76 ;
}
static T_5 F_102 ( const char * V_85 , T_6 V_76 )
{
struct V_32 * V_52 ;
V_43 V_57 ;
int V_53 ;
V_52 = F_73 ( V_85 ) ;
if ( ! V_52 )
return - V_54 ;
V_53 = F_67 ( V_52 , L_12 , & V_57 ) ;
if ( V_53 ) {
F_68 ( V_52 ) ;
return - V_54 ;
}
V_53 = F_86 ( V_52 , V_57 ) ;
F_68 ( V_52 ) ;
return V_53 ? V_53 : V_76 ;
}
static int F_103 ( struct V_86 * V_87 ,
unsigned long V_79 , void * V_88 )
{
struct V_89 * V_90 = V_88 ;
int V_36 = 0 ;
switch ( V_79 ) {
case V_91 :
V_36 = F_42 ( V_90 -> V_52 ) ;
break;
case V_92 :
F_59 ( V_90 -> V_52 ) ;
break;
}
return F_104 ( V_36 ) ;
}
static int F_105 ( void )
{
memset ( V_93 , 0 , V_94 ) ;
return F_106 ( F_107 ( L_42 ) , 3 , 1 ,
NULL ,
V_95 ,
F_108 ( V_93 ) ,
V_94 ) ;
}
static int T_1 F_109 ( void )
{
int V_4 ;
int V_96 ;
#ifdef F_110
V_15 . V_97 = F_100 ;
V_15 . V_98 = F_102 ;
#endif
V_10 = F_107 ( L_43 ) ;
V_96 = F_107 ( L_44 ) ;
if ( V_10 == V_11 ||
V_96 == V_11 ) {
F_12 ( V_99 L_45
L_46 ) ;
return 0 ;
}
V_15 . V_100 = F_17 ;
V_101 -> V_102 = F_32 ;
V_101 -> V_100 = F_37 ;
if ( F_111 ( V_103 ) ) {
F_112 ( & V_104 ) ;
F_46 () ;
if ( V_2 && F_105 () == 0 ) {
V_8 = V_14 ;
F_113 (cpu)
F_8 ( V_4 ) ;
}
F_57 () ;
}
return 0 ;
}
