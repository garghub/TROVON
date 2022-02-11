static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_5 * V_6 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_3 ( V_4 ) ;
bool V_11 = false ;
if ( F_4 ( ! F_5 () ) )
goto V_12;
if ( ! V_10 -> V_13 )
goto V_12;
if ( ( V_8 -> V_14 . V_15 & V_16 ) == 0 &&
! F_6 ( & V_8 -> V_2 ) )
goto V_12;
for ( V_6 = V_10 -> V_13 ; V_6 -> V_17 != 0x0 ; V_6 ++ ) {
if ( V_6 -> V_17 == V_8 -> V_14 . V_17 &&
strcmp ( V_6 -> V_18 , V_8 -> V_14 . type ) == 0 ) {
V_11 = true ;
break;
}
}
V_12:
F_7 ( V_2 , L_1 , V_11 ? L_2 : L_3 ) ;
return V_11 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_9 ( V_20 , L_4 ,
V_8 -> V_14 . V_17 ,
V_8 -> V_14 . type ) )
return - V_21 ;
return 0 ;
}
static T_1 F_10 ( struct V_1 * V_2 , struct V_22 * V_23 ,
char * V_24 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return sprintf ( V_24 , L_5 , V_8 -> V_14 . V_17 ,
V_8 -> V_14 . type ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
int error ;
if ( F_4 ( ! V_2 -> V_25 ) )
return - V_26 ;
V_10 = F_3 ( V_2 -> V_25 ) ;
if ( F_4 ( ! V_10 -> V_27 ) )
return - V_26 ;
error = V_10 -> V_27 ( V_8 ) ;
if ( error < 0 ) {
F_12 ( V_2 , L_6 , V_28 , error ) ;
return error ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_3 ( V_2 -> V_25 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
int error ;
if ( F_4 ( ! V_2 -> V_25 ) )
return - V_26 ;
error = V_10 -> remove ( V_8 ) ;
if ( error < 0 ) {
F_12 ( V_2 , L_6 , V_28 , error ) ;
return error ;
}
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_3 ( V_2 -> V_25 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_10 -> V_29 ( V_8 ) ;
}
int F_15 ( struct V_9 * V_30 ,
struct V_31 * V_32 )
{
int error ;
V_30 -> V_25 . V_32 = V_32 ;
V_30 -> V_25 . V_33 = & V_34 ;
if ( V_30 -> V_27 )
V_30 -> V_25 . V_27 = F_11 ;
if ( V_30 -> remove )
V_30 -> V_25 . remove = F_13 ;
if ( V_30 -> V_29 )
V_30 -> V_25 . V_29 = F_14 ;
error = F_16 ( & V_30 -> V_25 ) ;
if ( error < 0 ) {
F_17 ( L_7 ,
V_30 -> V_25 . V_35 , error ) ;
return error ;
}
return 0 ;
}
void F_18 ( struct V_9 * V_30 )
{
F_19 ( & V_30 -> V_25 ) ;
}
bool F_5 ( void )
{
return F_20 ( & V_36 ) > 0 ;
}
void F_21 ( struct V_1 * V_2 ,
struct V_1 * * V_37 )
{
if ( F_4 ( ! V_2 ) ) {
* V_37 = NULL ;
} else if ( F_4 ( ! F_22 ( V_2 ) ) ) {
* V_37 = NULL ;
} else {
* V_37 = V_2 ;
while ( F_22 ( ( * V_37 ) -> V_38 ) )
* V_37 = ( * V_37 ) -> V_38 ;
}
}
static int F_23 ( struct V_39 * V_40 ,
int V_41 , struct V_42 * V_23 )
{
T_2 V_43 ;
int error ;
error = F_24 ( V_40 , 0 , V_41 , & V_43 ) ;
if ( error < 0 ) {
F_12 ( V_40 -> V_2 , L_8 , error ) ;
return error ;
}
memset ( V_23 , 0 , sizeof( struct V_42 ) ) ;
error = F_25 ( V_40 , 0 , V_43 , V_23 ) ;
if ( error < 0 ) {
F_12 ( V_40 -> V_2 , L_9 ,
error ) ;
goto V_44;
}
error = 0 ;
V_44:
( void ) F_26 ( V_40 , 0 , V_43 ) ;
return error ;
}
static int F_27 ( struct V_39 * V_40 ,
int V_41 , T_2 * V_45 )
{
struct V_42 V_23 ;
int error ;
error = F_23 ( V_40 , V_41 , & V_23 ) ;
if ( error == 0 )
* V_45 = V_23 . V_45 ;
return error ;
}
static int F_28 ( struct V_7 * V_8 ,
enum V_46 V_47 ,
T_3 V_48 , T_4 * V_49 )
{
int V_50 ;
struct V_1 * V_37 ;
struct V_51 * V_52 ;
F_21 ( & V_8 -> V_2 , & V_37 ) ;
if ( F_4 ( ! V_37 ) )
return - V_26 ;
V_52 = F_29 ( V_37 -> V_38 ) ;
if ( V_52 -> V_53 == 0 ) {
* V_49 = V_48 ;
return 0 ;
}
for ( V_50 = 0 ; V_50 < V_52 -> V_53 ; V_50 ++ ) {
struct V_54 * V_55 =
& V_52 -> V_56 [ V_50 ] ;
if ( V_47 == V_55 -> V_47 &&
V_48 >= V_55 -> V_57 &&
V_48 < V_55 -> V_58 ) {
* V_49 = V_55 -> V_59 +
( V_48 - V_55 -> V_57 ) ;
return 0 ;
}
}
return - V_60 ;
}
static int F_30 ( struct V_7 * V_8 ,
struct V_7 * V_61 )
{
int V_50 ;
int error ;
struct V_62 * V_63 ;
struct V_64 * V_14 = & V_8 -> V_14 ;
struct V_1 * V_65 = V_8 -> V_2 . V_38 ;
enum V_46 V_47 ;
if ( strcmp ( V_14 -> type , L_10 ) == 0 ||
strcmp ( V_14 -> type , L_11 ) == 0 ) {
V_47 = V_66 ;
} else if ( strcmp ( V_14 -> type , L_12 ) == 0 ) {
V_47 = V_67 ;
} else {
F_4 ( true ) ;
return - V_26 ;
}
V_63 = F_31 ( V_14 -> V_68 ,
sizeof( V_63 [ 0 ] ) , V_69 ) ;
if ( ! V_63 )
return - V_21 ;
for ( V_50 = 0 ; V_50 < V_14 -> V_68 ; V_50 ++ ) {
struct V_70 V_71 ;
error = F_32 ( V_61 -> V_40 ,
0 ,
V_61 -> V_72 ,
V_14 -> type ,
V_14 -> V_6 , V_50 , & V_71 ) ;
if ( error < 0 ) {
F_12 ( V_65 ,
L_13 , error ) ;
goto V_73;
}
F_4 ( V_71 . V_74 == 0 ) ;
error = F_28 ( V_8 , V_47 ,
V_71 . V_75 ,
& V_63 [ V_50 ] . V_76 ) ;
if ( error < 0 ) {
F_12 ( V_65 ,
L_14 ,
V_71 . V_75 ,
V_14 -> type , V_14 -> V_6 , V_50 ) ;
goto V_73;
}
V_63 [ V_50 ] . V_77 = V_63 [ V_50 ] . V_76 + V_71 . V_74 - 1 ;
V_63 [ V_50 ] . V_35 = L_15 ;
V_63 [ V_50 ] . V_78 = V_79 ;
if ( V_71 . V_78 & V_80 )
V_63 [ V_50 ] . V_78 |= V_81 ;
}
V_8 -> V_63 = V_63 ;
return 0 ;
V_73:
F_33 ( V_63 ) ;
return error ;
}
bool F_6 ( struct V_1 * V_2 )
{
struct V_1 * V_37 ;
F_21 ( V_2 , & V_37 ) ;
if ( ! V_37 )
return false ;
return V_2 == V_37 ;
}
int F_34 ( struct V_64 * V_14 ,
struct V_39 * V_40 ,
struct V_1 * V_65 ,
struct V_7 * * V_82 )
{
int error ;
struct V_7 * V_8 = NULL ;
struct V_83 * V_84 = NULL ;
struct V_7 * V_85 ;
if ( F_22 ( V_65 ) )
V_85 = F_2 ( V_65 ) ;
else
V_85 = NULL ;
if ( strcmp ( V_14 -> type , L_10 ) == 0 ) {
V_84 = F_35 ( V_65 , sizeof( * V_84 ) , V_69 ) ;
if ( ! V_84 )
return - V_21 ;
V_8 = & V_84 -> V_8 ;
} else {
V_8 = F_36 ( V_86 , V_69 ) ;
if ( ! V_8 )
return - V_21 ;
}
V_8 -> V_14 = * V_14 ;
V_8 -> V_40 = V_40 ;
F_37 ( & V_8 -> V_2 ) ;
V_8 -> V_2 . V_38 = V_65 ;
V_8 -> V_2 . V_33 = & V_34 ;
F_38 ( & V_8 -> V_2 , L_16 , V_14 -> type , V_14 -> V_6 ) ;
if ( strcmp ( V_14 -> type , L_10 ) == 0 ) {
struct V_39 * V_87 ;
V_8 -> V_78 |= V_88 ;
if ( V_85 ) {
V_87 = V_85 -> V_40 ;
} else {
if ( F_4 ( ! V_40 ) ) {
error = - V_26 ;
goto V_89;
}
V_87 = V_40 ;
F_39 ( & V_36 ) ;
}
error = F_27 ( V_87 , V_14 -> V_6 , & V_8 -> V_45 ) ;
if ( error < 0 )
goto V_89;
} else {
V_8 -> V_45 = V_85 -> V_45 ;
V_8 -> V_90 = V_91 ;
V_8 -> V_2 . V_90 = & V_8 -> V_90 ;
F_40 ( & V_8 -> V_2 ,
F_41 ( & V_85 -> V_2 ) ) ;
}
if ( V_85 && V_14 -> V_68 != 0 ) {
error = F_30 ( V_8 ,
V_85 ) ;
if ( error < 0 )
goto V_89;
}
if ( ! ( V_14 -> V_78 & V_92 ) )
F_42 ( & V_8 -> V_2 , 0 , 0 , NULL , true ) ;
error = F_43 ( & V_8 -> V_2 ) ;
if ( error < 0 ) {
F_12 ( V_65 ,
L_17 ,
F_44 ( & V_8 -> V_2 ) , error ) ;
goto V_89;
}
( void ) F_45 ( & V_8 -> V_2 ) ;
F_7 ( V_65 , L_18 , F_44 ( & V_8 -> V_2 ) ) ;
* V_82 = V_8 ;
return 0 ;
V_89:
F_33 ( V_8 -> V_63 ) ;
if ( V_84 )
F_46 ( V_65 , V_84 ) ;
else
F_47 ( V_86 , V_8 ) ;
return error ;
}
void F_48 ( struct V_7 * V_8 )
{
struct V_83 * V_84 = NULL ;
F_33 ( V_8 -> V_63 ) ;
F_49 ( & V_8 -> V_2 ) ;
F_50 ( & V_8 -> V_2 ) ;
if ( strcmp ( V_8 -> V_14 . type , L_10 ) == 0 ) {
V_84 = F_51 ( V_8 ) ;
if ( F_6 ( & V_8 -> V_2 ) ) {
if ( F_20 ( & V_36 ) > 0 )
F_52 ( & V_36 ) ;
else
F_4 ( 1 ) ;
}
}
if ( V_84 )
F_46 ( V_8 -> V_2 . V_38 , V_84 ) ;
else
F_47 ( V_86 , V_8 ) ;
}
static int F_53 ( struct V_1 * V_2 ,
int * V_93 ,
int * V_94 ,
int * V_95 ,
const T_5 * * V_96 ,
T_6 * V_97 )
{
const T_5 * V_98 ;
int V_99 ;
int V_100 ;
int V_101 ;
struct V_102 * V_103 = V_2 -> V_104 ;
* V_96 = F_54 ( V_103 , L_19 , & V_100 ) ;
if ( ! ( * V_96 ) || ! V_100 ) {
F_55 ( V_2 ,
L_20 ,
V_103 -> V_35 ) ;
* V_97 = 0 ;
return 0 ;
}
* V_93 = F_56 ( V_103 ) ;
V_98 = F_54 ( V_103 , L_21 , NULL ) ;
if ( V_98 )
* V_94 = F_57 ( V_98 ) ;
else
* V_94 = * V_93 ;
V_98 = F_54 ( V_103 , L_22 , NULL ) ;
if ( V_98 )
* V_95 = F_57 ( V_98 ) ;
else
* V_95 = F_58 ( V_103 ) ;
V_99 = * V_93 + * V_94 +
* V_95 ;
V_101 = V_99 * sizeof( T_5 ) ;
if ( V_100 % V_101 != 0 ) {
F_12 ( V_2 , L_23 , V_103 -> V_35 ) ;
return - V_26 ;
}
* V_97 = V_100 / V_101 ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_54
* * V_105 ,
T_6 * V_97 )
{
int error ;
int V_93 ;
int V_94 ;
int V_95 ;
int V_50 ;
const T_5 * V_96 ;
const T_5 * V_106 ;
error = F_53 ( V_2 ,
& V_93 ,
& V_94 ,
& V_95 ,
& V_96 ,
V_97 ) ;
if ( error < 0 )
return error ;
if ( ! ( * V_97 ) ) {
* V_105 = NULL ;
return 0 ;
}
* V_105 = F_60 ( V_2 , * V_97 ,
sizeof( struct V_54 ) ,
V_69 ) ;
if ( ! ( * V_105 ) )
return - V_21 ;
V_106 = V_96 ;
for ( V_50 = 0 ; V_50 < * V_97 ; ++ V_50 ) {
struct V_54 * V_55 = & ( * V_105 ) [ V_50 ] ;
V_55 -> V_47 = F_61 ( V_106 , 1 ) ;
V_55 -> V_57 = F_61 ( V_106 + 1 ,
V_94 - 1 ) ;
V_106 += V_94 ;
V_55 -> V_59 = F_61 ( V_106 , V_93 ) ;
V_106 += V_93 ;
V_55 -> V_58 = V_55 -> V_57 +
F_61 ( V_106 , V_95 ) ;
V_106 += V_95 ;
}
return 0 ;
}
static int F_62 ( struct V_107 * V_108 )
{
struct V_64 V_14 ;
int error ;
struct V_51 * V_52 ;
struct V_7 * V_61 = NULL ;
struct V_39 * V_40 = NULL ;
int V_41 ;
T_4 V_109 ;
T_7 V_110 ;
struct V_111 V_111 ;
struct V_62 V_112 ;
V_52 = F_35 ( & V_108 -> V_2 , sizeof( * V_52 ) , V_69 ) ;
if ( ! V_52 )
return - V_21 ;
F_63 ( V_108 , V_52 ) ;
error = F_64 ( V_108 -> V_2 . V_104 , 0 , & V_112 ) ;
if ( error < 0 ) {
F_12 ( & V_108 -> V_2 ,
L_24 ,
V_108 -> V_2 . V_104 -> V_113 ) ;
return error ;
}
V_109 = V_112 . V_76 ;
V_110 = F_65 ( & V_112 ) ;
error = F_66 ( & V_108 -> V_2 , V_109 ,
V_110 , NULL ,
V_114 , & V_40 ) ;
if ( error < 0 )
return error ;
error = F_67 ( V_40 , 0 , & V_111 ) ;
if ( error != 0 ) {
F_12 ( & V_108 -> V_2 ,
L_25 , error ) ;
goto V_115;
}
F_68 ( & V_108 -> V_2 , L_26 ,
V_111 . V_116 , V_111 . V_117 , V_111 . V_118 ) ;
error = F_59 ( & V_108 -> V_2 ,
& V_52 -> V_56 ,
& V_52 -> V_53 ) ;
if ( error < 0 )
goto V_115;
error = F_69 ( V_40 , 0 , & V_41 ) ;
if ( error < 0 ) {
F_12 ( & V_108 -> V_2 ,
L_27 , error ) ;
goto V_115;
}
memset ( & V_14 , 0 , sizeof( struct V_64 ) ) ;
error = F_70 ( V_40 , 0 ,
& V_14 . V_119 ,
& V_14 . V_120 ) ;
if ( error < 0 )
goto V_115;
V_14 . V_17 = V_121 ;
strcpy ( V_14 . type , L_10 ) ;
V_14 . V_6 = V_41 ;
V_14 . V_122 = 1 ;
V_14 . V_68 = 0 ;
error = F_34 ( & V_14 , V_40 , & V_108 -> V_2 , & V_61 ) ;
if ( error < 0 )
goto V_115;
V_52 -> V_123 = V_61 ;
return 0 ;
V_115:
F_71 ( V_40 ) ;
return error ;
}
static int F_72 ( struct V_107 * V_108 )
{
struct V_51 * V_52 = F_73 ( V_108 ) ;
if ( F_4 ( ! F_6 ( & V_52 -> V_123 -> V_2 ) ) )
return - V_26 ;
F_48 ( V_52 -> V_123 ) ;
F_71 ( V_52 -> V_123 -> V_40 ) ;
V_52 -> V_123 -> V_40 = NULL ;
return 0 ;
}
static int T_8 F_74 ( void )
{
int error ;
V_86 = F_75 ( L_28 ,
sizeof( struct V_7 ) , 0 , 0 ,
NULL ) ;
if ( ! V_86 ) {
F_17 ( L_29 ) ;
return - V_21 ;
}
error = F_76 ( & V_34 ) ;
if ( error < 0 ) {
F_17 ( L_30 , error ) ;
goto V_124;
}
error = F_77 ( & V_125 ) ;
if ( error < 0 ) {
F_17 ( L_31 , error ) ;
goto V_126;
}
error = F_78 () ;
if ( error < 0 )
goto V_127;
error = F_79 () ;
if ( error < 0 )
goto V_128;
error = F_80 () ;
if ( error < 0 )
goto V_129;
return 0 ;
V_129:
F_81 () ;
V_128:
F_82 () ;
V_127:
F_83 ( & V_125 ) ;
V_126:
F_84 ( & V_34 ) ;
V_124:
F_85 ( V_86 ) ;
return error ;
}
