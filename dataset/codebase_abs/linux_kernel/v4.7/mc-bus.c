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
F_9 ( L_4 , V_21 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
int error ;
if ( F_4 ( ! V_2 -> V_22 ) )
return - V_23 ;
V_10 = F_3 ( V_2 -> V_22 ) ;
if ( F_4 ( ! V_10 -> V_24 ) )
return - V_23 ;
error = V_10 -> V_24 ( V_8 ) ;
if ( error < 0 ) {
F_11 ( V_2 , L_5 ,
error ) ;
return error ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_3 ( V_2 -> V_22 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
int error ;
if ( F_4 ( ! V_2 -> V_22 ) )
return - V_23 ;
error = V_10 -> remove ( V_8 ) ;
if ( error < 0 ) {
F_11 ( V_2 ,
L_6 ,
error ) ;
return error ;
}
return 0 ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_3 ( V_2 -> V_22 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_10 -> V_25 ( V_8 ) ;
}
int F_14 ( struct V_9 * V_26 ,
struct V_27 * V_28 )
{
int error ;
V_26 -> V_22 . V_28 = V_28 ;
V_26 -> V_22 . V_29 = & V_30 ;
if ( V_26 -> V_24 )
V_26 -> V_22 . V_24 = F_10 ;
if ( V_26 -> remove )
V_26 -> V_22 . remove = F_12 ;
if ( V_26 -> V_25 )
V_26 -> V_22 . V_25 = F_13 ;
error = F_15 ( & V_26 -> V_22 ) ;
if ( error < 0 ) {
F_16 ( L_7 ,
V_26 -> V_22 . V_31 , error ) ;
return error ;
}
F_17 ( L_8 ,
V_26 -> V_22 . V_31 ) ;
return 0 ;
}
void F_18 ( struct V_9 * V_26 )
{
F_19 ( & V_26 -> V_22 ) ;
}
bool F_5 ( void )
{
return F_20 ( & V_32 ) > 0 ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_1 * * V_33 )
{
if ( F_4 ( ! V_2 ) ) {
* V_33 = NULL ;
} else if ( F_4 ( V_2 -> V_29 != & V_30 ) ) {
* V_33 = NULL ;
} else {
* V_33 = V_2 ;
while ( ( * V_33 ) -> V_34 -> V_29 == & V_30 )
* V_33 = ( * V_33 ) -> V_34 ;
}
}
static bool F_6 ( struct V_1 * V_2 )
{
struct V_1 * V_33 ;
F_21 ( V_2 , & V_33 ) ;
if ( ! V_33 )
return false ;
return V_2 == V_33 ;
}
static int F_22 ( struct V_35 * V_36 ,
int V_37 , struct V_38 * V_39 )
{
T_1 V_40 ;
int error ;
error = F_23 ( V_36 , 0 , V_37 , & V_40 ) ;
if ( error < 0 ) {
F_11 ( V_36 -> V_2 , L_9 , error ) ;
return error ;
}
memset ( V_39 , 0 , sizeof( struct V_38 ) ) ;
error = F_24 ( V_36 , 0 , V_40 , V_39 ) ;
if ( error < 0 ) {
F_11 ( V_36 -> V_2 , L_10 ,
error ) ;
goto V_41;
}
error = 0 ;
V_41:
( void ) F_25 ( V_36 , 0 , V_40 ) ;
return error ;
}
static int F_26 ( struct V_35 * V_36 ,
int V_37 , T_1 * V_42 )
{
struct V_38 V_39 ;
int error ;
error = F_22 ( V_36 , V_37 , & V_39 ) ;
if ( error == 0 )
* V_42 = V_39 . V_42 ;
return error ;
}
static int F_27 ( struct V_35 * V_36 ,
int V_37 , T_1 * V_43 , T_1 * V_44 )
{
struct V_38 V_39 ;
int error ;
error = F_22 ( V_36 , V_37 , & V_39 ) ;
if ( error == 0 ) {
* V_43 = V_39 . V_45 . V_43 ;
* V_44 = V_39 . V_45 . V_44 ;
}
return error ;
}
static int F_28 ( struct V_7 * V_8 ,
enum V_46 V_47 ,
T_2 V_48 , T_3 * V_49 )
{
int V_50 ;
struct V_1 * V_33 ;
struct V_51 * V_52 ;
F_21 ( & V_8 -> V_2 , & V_33 ) ;
if ( F_4 ( ! V_33 ) )
return - V_23 ;
V_52 = F_29 ( V_33 -> V_34 ) ;
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
struct V_1 * V_65 = V_8 -> V_2 . V_34 ;
enum V_46 V_47 ;
if ( strcmp ( V_14 -> type , L_11 ) == 0 ||
strcmp ( V_14 -> type , L_12 ) == 0 ) {
V_47 = V_66 ;
} else if ( strcmp ( V_14 -> type , L_13 ) == 0 ) {
V_47 = V_67 ;
} else {
F_4 ( true ) ;
return - V_23 ;
}
V_63 = F_31 ( V_14 -> V_68 ,
sizeof( V_63 [ 0 ] ) , V_69 ) ;
if ( ! V_63 )
return - V_70 ;
for ( V_50 = 0 ; V_50 < V_14 -> V_68 ; V_50 ++ ) {
struct V_71 V_72 ;
error = F_32 ( V_61 -> V_36 ,
0 ,
V_61 -> V_73 ,
V_14 -> type ,
V_14 -> V_6 , V_50 , & V_72 ) ;
if ( error < 0 ) {
F_11 ( V_65 ,
L_14 , error ) ;
goto V_74;
}
F_4 ( V_72 . V_75 == 0 ) ;
error = F_28 ( V_8 , V_47 ,
V_72 . V_76 ,
& V_63 [ V_50 ] . V_77 ) ;
if ( error < 0 ) {
F_11 ( V_65 ,
L_15 ,
V_72 . V_76 ,
V_14 -> type , V_14 -> V_6 , V_50 ) ;
goto V_74;
}
V_63 [ V_50 ] . V_78 = V_63 [ V_50 ] . V_77 + V_72 . V_75 - 1 ;
V_63 [ V_50 ] . V_31 = L_16 ;
V_63 [ V_50 ] . V_79 = V_80 ;
if ( V_72 . V_79 & V_81 )
V_63 [ V_50 ] . V_79 |= V_82 ;
}
V_8 -> V_63 = V_63 ;
return 0 ;
V_74:
F_33 ( V_63 ) ;
return error ;
}
int F_34 ( struct V_64 * V_14 ,
struct V_35 * V_36 ,
struct V_1 * V_65 ,
struct V_7 * * V_83 )
{
int error ;
struct V_7 * V_8 = NULL ;
struct V_84 * V_85 = NULL ;
struct V_7 * V_86 ;
if ( V_65 -> V_29 == & V_30 )
V_86 = F_2 ( V_65 ) ;
else
V_86 = NULL ;
if ( strcmp ( V_14 -> type , L_11 ) == 0 ) {
V_85 = F_35 ( V_65 , sizeof( * V_85 ) , V_69 ) ;
if ( ! V_85 )
return - V_70 ;
V_8 = & V_85 -> V_8 ;
} else {
V_8 = F_36 ( V_87 , V_69 ) ;
if ( ! V_8 )
return - V_70 ;
}
V_8 -> V_14 = * V_14 ;
V_8 -> V_36 = V_36 ;
F_37 ( & V_8 -> V_2 ) ;
V_8 -> V_2 . V_34 = V_65 ;
V_8 -> V_2 . V_29 = & V_30 ;
F_38 ( & V_8 -> V_2 , L_17 , V_14 -> type , V_14 -> V_6 ) ;
if ( strcmp ( V_14 -> type , L_11 ) == 0 ) {
struct V_35 * V_88 ;
V_8 -> V_79 |= V_89 ;
if ( V_86 ) {
V_88 = V_86 -> V_36 ;
} else {
if ( F_4 ( ! V_36 ) ) {
error = - V_23 ;
goto V_90;
}
V_88 = V_36 ;
F_39 ( & V_32 ) ;
}
error = F_26 ( V_88 , V_14 -> V_6 , & V_8 -> V_42 ) ;
if ( error < 0 )
goto V_90;
} else {
V_8 -> V_42 = V_86 -> V_42 ;
V_8 -> V_91 = V_92 ;
V_8 -> V_2 . V_91 = & V_8 -> V_91 ;
F_40 ( & V_8 -> V_2 ,
F_41 ( & V_86 -> V_2 ) ) ;
}
if ( V_86 && V_14 -> V_68 != 0 ) {
error = F_30 ( V_8 ,
V_86 ) ;
if ( error < 0 )
goto V_90;
}
if ( ! ( V_14 -> V_79 & V_93 ) )
F_42 ( & V_8 -> V_2 , 0 , 0 , NULL , true ) ;
error = F_43 ( & V_8 -> V_2 ) ;
if ( error < 0 ) {
F_11 ( V_65 ,
L_18 ,
F_44 ( & V_8 -> V_2 ) , error ) ;
goto V_90;
}
( void ) F_45 ( & V_8 -> V_2 ) ;
F_7 ( V_65 , L_19 ,
F_44 ( & V_8 -> V_2 ) ) ;
* V_83 = V_8 ;
return 0 ;
V_90:
F_33 ( V_8 -> V_63 ) ;
if ( V_85 )
F_46 ( V_65 , V_85 ) ;
else
F_47 ( V_87 , V_8 ) ;
return error ;
}
void F_48 ( struct V_7 * V_8 )
{
struct V_84 * V_85 = NULL ;
F_33 ( V_8 -> V_63 ) ;
F_49 ( & V_8 -> V_2 ) ;
F_50 ( & V_8 -> V_2 ) ;
if ( strcmp ( V_8 -> V_14 . type , L_11 ) == 0 ) {
V_85 = F_51 ( V_8 ) ;
if ( V_8 -> V_36 ) {
F_52 ( V_8 -> V_36 ) ;
V_8 -> V_36 = NULL ;
}
if ( F_6 ( & V_8 -> V_2 ) ) {
if ( F_20 ( & V_32 ) > 0 )
F_53 ( & V_32 ) ;
else
F_4 ( 1 ) ;
}
}
if ( V_85 )
F_46 ( V_8 -> V_2 . V_34 , V_85 ) ;
else
F_47 ( V_87 , V_8 ) ;
}
static int F_54 ( struct V_1 * V_2 ,
int * V_94 ,
int * V_95 ,
int * V_96 ,
const T_4 * * V_97 ,
T_5 * V_98 )
{
const T_4 * V_99 ;
int V_100 ;
int V_101 ;
int V_102 ;
struct V_103 * V_104 = V_2 -> V_105 ;
* V_97 = F_55 ( V_104 , L_20 , & V_101 ) ;
if ( ! ( * V_97 ) || ! V_101 ) {
F_56 ( V_2 ,
L_21 ,
V_104 -> V_31 ) ;
* V_98 = 0 ;
return 0 ;
}
* V_94 = F_57 ( V_104 ) ;
V_99 = F_55 ( V_104 , L_22 , NULL ) ;
if ( V_99 )
* V_95 = F_58 ( V_99 ) ;
else
* V_95 = * V_94 ;
V_99 = F_55 ( V_104 , L_23 , NULL ) ;
if ( V_99 )
* V_96 = F_58 ( V_99 ) ;
else
* V_96 = F_59 ( V_104 ) ;
V_100 = * V_94 + * V_95 +
* V_96 ;
V_102 = V_100 * sizeof( T_4 ) ;
if ( V_101 % V_102 != 0 ) {
F_11 ( V_2 , L_24 , V_104 -> V_31 ) ;
return - V_23 ;
}
* V_98 = V_101 / V_102 ;
return 0 ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_54
* * V_106 ,
T_5 * V_98 )
{
int error ;
int V_94 ;
int V_95 ;
int V_96 ;
int V_50 ;
const T_4 * V_97 ;
const T_4 * V_107 ;
error = F_54 ( V_2 ,
& V_94 ,
& V_95 ,
& V_96 ,
& V_97 ,
V_98 ) ;
if ( error < 0 )
return error ;
if ( ! ( * V_98 ) ) {
* V_106 = NULL ;
return 0 ;
}
* V_106 = F_61 ( V_2 , * V_98 ,
sizeof( struct V_54 ) ,
V_69 ) ;
if ( ! ( * V_106 ) )
return - V_70 ;
V_107 = V_97 ;
for ( V_50 = 0 ; V_50 < * V_98 ; ++ V_50 ) {
struct V_54 * V_55 = & ( * V_106 ) [ V_50 ] ;
V_55 -> V_47 = F_62 ( V_107 , 1 ) ;
V_55 -> V_57 = F_62 ( V_107 + 1 ,
V_95 - 1 ) ;
V_107 += V_95 ;
V_55 -> V_59 = F_62 ( V_107 , V_94 ) ;
V_107 += V_94 ;
V_55 -> V_58 = V_55 -> V_57 +
F_62 ( V_107 , V_96 ) ;
V_107 += V_96 ;
}
return 0 ;
}
static int F_63 ( struct V_108 * V_109 )
{
struct V_64 V_14 ;
int error ;
struct V_51 * V_52 ;
struct V_7 * V_61 = NULL ;
struct V_35 * V_36 = NULL ;
int V_37 ;
T_3 V_110 ;
T_6 V_111 ;
struct V_112 V_112 ;
struct V_62 V_113 ;
F_64 ( & V_109 -> V_2 , L_25 ) ;
V_52 = F_35 ( & V_109 -> V_2 , sizeof( * V_52 ) , V_69 ) ;
if ( ! V_52 )
return - V_70 ;
F_65 ( V_109 , V_52 ) ;
error = F_66 ( V_109 -> V_2 . V_105 , 0 , & V_113 ) ;
if ( error < 0 ) {
F_11 ( & V_109 -> V_2 ,
L_26 ,
V_109 -> V_2 . V_105 -> V_114 ) ;
return error ;
}
V_110 = V_113 . V_77 ;
V_111 = F_67 ( & V_113 ) ;
error = F_68 ( & V_109 -> V_2 , V_110 ,
V_111 , NULL ,
V_115 , & V_36 ) ;
if ( error < 0 )
return error ;
error = F_69 ( V_36 , 0 , & V_112 ) ;
if ( error != 0 ) {
F_11 ( & V_109 -> V_2 ,
L_27 , error ) ;
goto V_116;
}
F_64 ( & V_109 -> V_2 ,
L_28 ,
V_112 . V_43 , V_112 . V_44 , V_112 . V_117 ) ;
error = F_60 ( & V_109 -> V_2 ,
& V_52 -> V_56 ,
& V_52 -> V_53 ) ;
if ( error < 0 )
goto V_116;
error = F_70 ( V_36 , 0 , & V_37 ) ;
if ( error < 0 ) {
F_11 ( & V_109 -> V_2 ,
L_29 , error ) ;
goto V_116;
}
memset ( & V_14 , 0 , sizeof( struct V_64 ) ) ;
error = F_27 ( V_36 , V_37 ,
& V_14 . V_118 , & V_14 . V_119 ) ;
if ( error < 0 )
goto V_116;
V_14 . V_17 = V_120 ;
strcpy ( V_14 . type , L_11 ) ;
V_14 . V_6 = V_37 ;
V_14 . V_121 = 1 ;
V_14 . V_68 = 0 ;
error = F_34 ( & V_14 , V_36 , & V_109 -> V_2 , & V_61 ) ;
if ( error < 0 )
goto V_116;
V_52 -> V_122 = V_61 ;
return 0 ;
V_116:
F_52 ( V_36 ) ;
return error ;
}
static int F_71 ( struct V_108 * V_109 )
{
struct V_51 * V_52 = F_72 ( V_109 ) ;
if ( F_4 ( ! F_6 ( & V_52 -> V_122 -> V_2 ) ) )
return - V_23 ;
F_48 ( V_52 -> V_122 ) ;
F_64 ( & V_109 -> V_2 , L_30 ) ;
return 0 ;
}
static int T_7 F_73 ( void )
{
int error ;
V_87 = F_74 ( L_31 ,
sizeof( struct V_7 ) , 0 , 0 ,
NULL ) ;
if ( ! V_87 ) {
F_16 ( L_32 ) ;
return - V_70 ;
}
error = F_75 ( & V_30 ) ;
if ( error < 0 ) {
F_16 ( L_33 , error ) ;
goto V_123;
}
F_17 ( L_34 ) ;
error = F_76 ( & V_124 ) ;
if ( error < 0 ) {
F_16 ( L_35 , error ) ;
goto V_125;
}
error = F_77 () ;
if ( error < 0 )
goto V_126;
error = F_78 () ;
if ( error < 0 )
goto V_127;
error = F_79 () ;
if ( error < 0 )
goto V_128;
return 0 ;
V_128:
F_80 () ;
V_127:
F_81 () ;
V_126:
F_82 ( & V_124 ) ;
V_125:
F_83 ( & V_30 ) ;
V_123:
F_84 ( V_87 ) ;
return error ;
}
static void T_8 F_85 ( void )
{
if ( F_4 ( ! V_87 ) )
return;
F_86 () ;
F_80 () ;
F_81 () ;
F_82 ( & V_124 ) ;
F_83 ( & V_30 ) ;
F_84 ( V_87 ) ;
F_17 ( L_36 ) ;
}
