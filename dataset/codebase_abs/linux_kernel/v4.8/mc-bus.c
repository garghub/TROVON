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
F_12 ( V_2 , L_6 ,
error ) ;
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
F_12 ( V_2 ,
L_7 ,
error ) ;
return error ;
}
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_3 ( V_2 -> V_25 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_10 -> V_28 ( V_8 ) ;
}
int F_15 ( struct V_9 * V_29 ,
struct V_30 * V_31 )
{
int error ;
V_29 -> V_25 . V_31 = V_31 ;
V_29 -> V_25 . V_32 = & V_33 ;
if ( V_29 -> V_27 )
V_29 -> V_25 . V_27 = F_11 ;
if ( V_29 -> remove )
V_29 -> V_25 . remove = F_13 ;
if ( V_29 -> V_28 )
V_29 -> V_25 . V_28 = F_14 ;
error = F_16 ( & V_29 -> V_25 ) ;
if ( error < 0 ) {
F_17 ( L_8 ,
V_29 -> V_25 . V_34 , error ) ;
return error ;
}
F_18 ( L_9 ,
V_29 -> V_25 . V_34 ) ;
return 0 ;
}
void F_19 ( struct V_9 * V_29 )
{
F_20 ( & V_29 -> V_25 ) ;
}
bool F_5 ( void )
{
return F_21 ( & V_35 ) > 0 ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_1 * * V_36 )
{
if ( F_4 ( ! V_2 ) ) {
* V_36 = NULL ;
} else if ( F_4 ( V_2 -> V_32 != & V_33 ) ) {
* V_36 = NULL ;
} else {
* V_36 = V_2 ;
while ( ( * V_36 ) -> V_37 -> V_32 == & V_33 )
* V_36 = ( * V_36 ) -> V_37 ;
}
}
static int F_23 ( struct V_38 * V_39 ,
int V_40 , struct V_41 * V_23 )
{
T_2 V_42 ;
int error ;
error = F_24 ( V_39 , 0 , V_40 , & V_42 ) ;
if ( error < 0 ) {
F_12 ( V_39 -> V_2 , L_10 , error ) ;
return error ;
}
memset ( V_23 , 0 , sizeof( struct V_41 ) ) ;
error = F_25 ( V_39 , 0 , V_42 , V_23 ) ;
if ( error < 0 ) {
F_12 ( V_39 -> V_2 , L_11 ,
error ) ;
goto V_43;
}
error = 0 ;
V_43:
( void ) F_26 ( V_39 , 0 , V_42 ) ;
return error ;
}
static int F_27 ( struct V_38 * V_39 ,
int V_40 , T_2 * V_44 )
{
struct V_41 V_23 ;
int error ;
error = F_23 ( V_39 , V_40 , & V_23 ) ;
if ( error == 0 )
* V_44 = V_23 . V_44 ;
return error ;
}
static int F_28 ( struct V_38 * V_39 ,
int V_40 , T_2 * V_45 , T_2 * V_46 )
{
struct V_41 V_23 ;
int error ;
error = F_23 ( V_39 , V_40 , & V_23 ) ;
if ( error == 0 ) {
* V_45 = V_23 . V_47 . V_45 ;
* V_46 = V_23 . V_47 . V_46 ;
}
return error ;
}
static int F_29 ( struct V_7 * V_8 ,
enum V_48 V_49 ,
T_3 V_50 , T_4 * V_51 )
{
int V_52 ;
struct V_1 * V_36 ;
struct V_53 * V_54 ;
F_22 ( & V_8 -> V_2 , & V_36 ) ;
if ( F_4 ( ! V_36 ) )
return - V_26 ;
V_54 = F_30 ( V_36 -> V_37 ) ;
if ( V_54 -> V_55 == 0 ) {
* V_51 = V_50 ;
return 0 ;
}
for ( V_52 = 0 ; V_52 < V_54 -> V_55 ; V_52 ++ ) {
struct V_56 * V_57 =
& V_54 -> V_58 [ V_52 ] ;
if ( V_49 == V_57 -> V_49 &&
V_50 >= V_57 -> V_59 &&
V_50 < V_57 -> V_60 ) {
* V_51 = V_57 -> V_61 +
( V_50 - V_57 -> V_59 ) ;
return 0 ;
}
}
return - V_62 ;
}
static int F_31 ( struct V_7 * V_8 ,
struct V_7 * V_63 )
{
int V_52 ;
int error ;
struct V_64 * V_65 ;
struct V_66 * V_14 = & V_8 -> V_14 ;
struct V_1 * V_67 = V_8 -> V_2 . V_37 ;
enum V_48 V_49 ;
if ( strcmp ( V_14 -> type , L_12 ) == 0 ||
strcmp ( V_14 -> type , L_13 ) == 0 ) {
V_49 = V_68 ;
} else if ( strcmp ( V_14 -> type , L_14 ) == 0 ) {
V_49 = V_69 ;
} else {
F_4 ( true ) ;
return - V_26 ;
}
V_65 = F_32 ( V_14 -> V_70 ,
sizeof( V_65 [ 0 ] ) , V_71 ) ;
if ( ! V_65 )
return - V_21 ;
for ( V_52 = 0 ; V_52 < V_14 -> V_70 ; V_52 ++ ) {
struct V_72 V_73 ;
error = F_33 ( V_63 -> V_39 ,
0 ,
V_63 -> V_74 ,
V_14 -> type ,
V_14 -> V_6 , V_52 , & V_73 ) ;
if ( error < 0 ) {
F_12 ( V_67 ,
L_15 , error ) ;
goto V_75;
}
F_4 ( V_73 . V_76 == 0 ) ;
error = F_29 ( V_8 , V_49 ,
V_73 . V_77 ,
& V_65 [ V_52 ] . V_78 ) ;
if ( error < 0 ) {
F_12 ( V_67 ,
L_16 ,
V_73 . V_77 ,
V_14 -> type , V_14 -> V_6 , V_52 ) ;
goto V_75;
}
V_65 [ V_52 ] . V_79 = V_65 [ V_52 ] . V_78 + V_73 . V_76 - 1 ;
V_65 [ V_52 ] . V_34 = L_17 ;
V_65 [ V_52 ] . V_80 = V_81 ;
if ( V_73 . V_80 & V_82 )
V_65 [ V_52 ] . V_80 |= V_83 ;
}
V_8 -> V_65 = V_65 ;
return 0 ;
V_75:
F_34 ( V_65 ) ;
return error ;
}
bool F_6 ( struct V_1 * V_2 )
{
struct V_1 * V_36 ;
F_22 ( V_2 , & V_36 ) ;
if ( ! V_36 )
return false ;
return V_2 == V_36 ;
}
int F_35 ( struct V_66 * V_14 ,
struct V_38 * V_39 ,
struct V_1 * V_67 ,
struct V_7 * * V_84 )
{
int error ;
struct V_7 * V_8 = NULL ;
struct V_85 * V_86 = NULL ;
struct V_7 * V_87 ;
if ( V_67 -> V_32 == & V_33 )
V_87 = F_2 ( V_67 ) ;
else
V_87 = NULL ;
if ( strcmp ( V_14 -> type , L_12 ) == 0 ) {
V_86 = F_36 ( V_67 , sizeof( * V_86 ) , V_71 ) ;
if ( ! V_86 )
return - V_21 ;
V_8 = & V_86 -> V_8 ;
} else {
V_8 = F_37 ( V_88 , V_71 ) ;
if ( ! V_8 )
return - V_21 ;
}
V_8 -> V_14 = * V_14 ;
V_8 -> V_39 = V_39 ;
F_38 ( & V_8 -> V_2 ) ;
V_8 -> V_2 . V_37 = V_67 ;
V_8 -> V_2 . V_32 = & V_33 ;
F_39 ( & V_8 -> V_2 , L_18 , V_14 -> type , V_14 -> V_6 ) ;
if ( strcmp ( V_14 -> type , L_12 ) == 0 ) {
struct V_38 * V_89 ;
V_8 -> V_80 |= V_90 ;
if ( V_87 ) {
V_89 = V_87 -> V_39 ;
} else {
if ( F_4 ( ! V_39 ) ) {
error = - V_26 ;
goto V_91;
}
V_89 = V_39 ;
F_40 ( & V_35 ) ;
}
error = F_27 ( V_89 , V_14 -> V_6 , & V_8 -> V_44 ) ;
if ( error < 0 )
goto V_91;
} else {
V_8 -> V_44 = V_87 -> V_44 ;
V_8 -> V_92 = V_93 ;
V_8 -> V_2 . V_92 = & V_8 -> V_92 ;
F_41 ( & V_8 -> V_2 ,
F_42 ( & V_87 -> V_2 ) ) ;
}
if ( V_87 && V_14 -> V_70 != 0 ) {
error = F_31 ( V_8 ,
V_87 ) ;
if ( error < 0 )
goto V_91;
}
if ( ! ( V_14 -> V_80 & V_94 ) )
F_43 ( & V_8 -> V_2 , 0 , 0 , NULL , true ) ;
error = F_44 ( & V_8 -> V_2 ) ;
if ( error < 0 ) {
F_12 ( V_67 ,
L_19 ,
F_45 ( & V_8 -> V_2 ) , error ) ;
goto V_91;
}
( void ) F_46 ( & V_8 -> V_2 ) ;
F_7 ( V_67 , L_20 ,
F_45 ( & V_8 -> V_2 ) ) ;
* V_84 = V_8 ;
return 0 ;
V_91:
F_34 ( V_8 -> V_65 ) ;
if ( V_86 )
F_47 ( V_67 , V_86 ) ;
else
F_48 ( V_88 , V_8 ) ;
return error ;
}
void F_49 ( struct V_7 * V_8 )
{
struct V_85 * V_86 = NULL ;
F_34 ( V_8 -> V_65 ) ;
F_50 ( & V_8 -> V_2 ) ;
F_51 ( & V_8 -> V_2 ) ;
if ( strcmp ( V_8 -> V_14 . type , L_12 ) == 0 ) {
V_86 = F_52 ( V_8 ) ;
if ( F_6 ( & V_8 -> V_2 ) ) {
if ( F_21 ( & V_35 ) > 0 )
F_53 ( & V_35 ) ;
else
F_4 ( 1 ) ;
}
}
if ( V_86 )
F_47 ( V_8 -> V_2 . V_37 , V_86 ) ;
else
F_48 ( V_88 , V_8 ) ;
}
static int F_54 ( struct V_1 * V_2 ,
int * V_95 ,
int * V_96 ,
int * V_97 ,
const T_5 * * V_98 ,
T_6 * V_99 )
{
const T_5 * V_100 ;
int V_101 ;
int V_102 ;
int V_103 ;
struct V_104 * V_105 = V_2 -> V_106 ;
* V_98 = F_55 ( V_105 , L_21 , & V_102 ) ;
if ( ! ( * V_98 ) || ! V_102 ) {
F_56 ( V_2 ,
L_22 ,
V_105 -> V_34 ) ;
* V_99 = 0 ;
return 0 ;
}
* V_95 = F_57 ( V_105 ) ;
V_100 = F_55 ( V_105 , L_23 , NULL ) ;
if ( V_100 )
* V_96 = F_58 ( V_100 ) ;
else
* V_96 = * V_95 ;
V_100 = F_55 ( V_105 , L_24 , NULL ) ;
if ( V_100 )
* V_97 = F_58 ( V_100 ) ;
else
* V_97 = F_59 ( V_105 ) ;
V_101 = * V_95 + * V_96 +
* V_97 ;
V_103 = V_101 * sizeof( T_5 ) ;
if ( V_102 % V_103 != 0 ) {
F_12 ( V_2 , L_25 , V_105 -> V_34 ) ;
return - V_26 ;
}
* V_99 = V_102 / V_103 ;
return 0 ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_56
* * V_107 ,
T_6 * V_99 )
{
int error ;
int V_95 ;
int V_96 ;
int V_97 ;
int V_52 ;
const T_5 * V_98 ;
const T_5 * V_108 ;
error = F_54 ( V_2 ,
& V_95 ,
& V_96 ,
& V_97 ,
& V_98 ,
V_99 ) ;
if ( error < 0 )
return error ;
if ( ! ( * V_99 ) ) {
* V_107 = NULL ;
return 0 ;
}
* V_107 = F_61 ( V_2 , * V_99 ,
sizeof( struct V_56 ) ,
V_71 ) ;
if ( ! ( * V_107 ) )
return - V_21 ;
V_108 = V_98 ;
for ( V_52 = 0 ; V_52 < * V_99 ; ++ V_52 ) {
struct V_56 * V_57 = & ( * V_107 ) [ V_52 ] ;
V_57 -> V_49 = F_62 ( V_108 , 1 ) ;
V_57 -> V_59 = F_62 ( V_108 + 1 ,
V_96 - 1 ) ;
V_108 += V_96 ;
V_57 -> V_61 = F_62 ( V_108 , V_95 ) ;
V_108 += V_95 ;
V_57 -> V_60 = V_57 -> V_59 +
F_62 ( V_108 , V_97 ) ;
V_108 += V_97 ;
}
return 0 ;
}
static int F_63 ( struct V_109 * V_110 )
{
struct V_66 V_14 ;
int error ;
struct V_53 * V_54 ;
struct V_7 * V_63 = NULL ;
struct V_38 * V_39 = NULL ;
int V_40 ;
T_4 V_111 ;
T_7 V_112 ;
struct V_113 V_113 ;
struct V_64 V_114 ;
F_64 ( & V_110 -> V_2 , L_26 ) ;
V_54 = F_36 ( & V_110 -> V_2 , sizeof( * V_54 ) , V_71 ) ;
if ( ! V_54 )
return - V_21 ;
F_65 ( V_110 , V_54 ) ;
error = F_66 ( V_110 -> V_2 . V_106 , 0 , & V_114 ) ;
if ( error < 0 ) {
F_12 ( & V_110 -> V_2 ,
L_27 ,
V_110 -> V_2 . V_106 -> V_115 ) ;
return error ;
}
V_111 = V_114 . V_78 ;
V_112 = F_67 ( & V_114 ) ;
error = F_68 ( & V_110 -> V_2 , V_111 ,
V_112 , NULL ,
V_116 , & V_39 ) ;
if ( error < 0 )
return error ;
error = F_69 ( V_39 , 0 , & V_113 ) ;
if ( error != 0 ) {
F_12 ( & V_110 -> V_2 ,
L_28 , error ) ;
goto V_117;
}
F_64 ( & V_110 -> V_2 ,
L_29 ,
V_113 . V_45 , V_113 . V_46 , V_113 . V_118 ) ;
error = F_60 ( & V_110 -> V_2 ,
& V_54 -> V_58 ,
& V_54 -> V_55 ) ;
if ( error < 0 )
goto V_117;
error = F_70 ( V_39 , 0 , & V_40 ) ;
if ( error < 0 ) {
F_12 ( & V_110 -> V_2 ,
L_30 , error ) ;
goto V_117;
}
memset ( & V_14 , 0 , sizeof( struct V_66 ) ) ;
error = F_28 ( V_39 , V_40 ,
& V_14 . V_119 , & V_14 . V_120 ) ;
if ( error < 0 )
goto V_117;
V_14 . V_17 = V_121 ;
strcpy ( V_14 . type , L_12 ) ;
V_14 . V_6 = V_40 ;
V_14 . V_122 = 1 ;
V_14 . V_70 = 0 ;
error = F_35 ( & V_14 , V_39 , & V_110 -> V_2 , & V_63 ) ;
if ( error < 0 )
goto V_117;
V_54 -> V_123 = V_63 ;
return 0 ;
V_117:
F_71 ( V_39 ) ;
return error ;
}
static int F_72 ( struct V_109 * V_110 )
{
struct V_53 * V_54 = F_73 ( V_110 ) ;
if ( F_4 ( ! F_6 ( & V_54 -> V_123 -> V_2 ) ) )
return - V_26 ;
F_49 ( V_54 -> V_123 ) ;
F_71 ( V_54 -> V_123 -> V_39 ) ;
V_54 -> V_123 -> V_39 = NULL ;
F_64 ( & V_110 -> V_2 , L_31 ) ;
return 0 ;
}
static int T_8 F_74 ( void )
{
int error ;
V_88 = F_75 ( L_32 ,
sizeof( struct V_7 ) , 0 , 0 ,
NULL ) ;
if ( ! V_88 ) {
F_17 ( L_33 ) ;
return - V_21 ;
}
error = F_76 ( & V_33 ) ;
if ( error < 0 ) {
F_17 ( L_34 , error ) ;
goto V_124;
}
F_18 ( L_35 ) ;
error = F_77 ( & V_125 ) ;
if ( error < 0 ) {
F_17 ( L_36 , error ) ;
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
F_84 ( & V_33 ) ;
V_124:
F_85 ( V_88 ) ;
return error ;
}
static void T_9 F_86 ( void )
{
if ( F_4 ( ! V_88 ) )
return;
F_87 () ;
F_81 () ;
F_82 () ;
F_83 ( & V_125 ) ;
F_84 ( & V_33 ) ;
F_85 ( V_88 ) ;
F_18 ( L_37 ) ;
}
