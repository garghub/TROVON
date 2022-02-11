static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_5 * V_6 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_3 ( V_4 ) ;
bool V_11 = false ;
bool V_12 = false ;
bool V_13 = false ;
if ( F_4 ( ! F_5 () ) )
goto V_14;
if ( ! V_10 -> V_15 )
goto V_14;
if ( ( V_8 -> V_16 . V_17 & V_18 ) == 0 &&
! F_6 ( & V_8 -> V_2 ) )
goto V_14;
for ( V_6 = V_10 -> V_15 ; V_6 -> V_19 != 0x0 ; V_6 ++ ) {
if ( V_6 -> V_19 == V_8 -> V_16 . V_19 &&
strcmp ( V_6 -> V_20 , V_8 -> V_16 . type ) == 0 ) {
if ( V_6 -> V_21 == V_8 -> V_16 . V_21 ) {
V_11 = true ;
if ( V_6 -> V_22 != V_8 -> V_16 . V_22 )
V_13 = true ;
} else {
V_12 = true ;
}
break;
}
}
if ( V_12 ) {
F_7 ( V_2 ,
L_1 ,
V_6 -> V_21 , V_6 -> V_22 ,
V_8 -> V_16 . V_21 ,
V_8 -> V_16 . V_22 ) ;
} else if ( V_13 ) {
F_7 ( V_2 ,
L_2 ,
V_6 -> V_21 , V_6 -> V_22 ,
V_8 -> V_16 . V_21 ,
V_8 -> V_16 . V_22 ) ;
}
V_14:
F_8 ( V_2 , L_3 , V_11 ? L_4 : L_5 ) ;
return V_11 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
F_10 ( L_6 , V_25 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
int error ;
if ( F_4 ( ! V_2 -> V_26 ) )
return - V_27 ;
V_10 = F_3 ( V_2 -> V_26 ) ;
if ( F_4 ( ! V_10 -> V_28 ) )
return - V_27 ;
error = V_10 -> V_28 ( V_8 ) ;
if ( error < 0 ) {
F_12 ( V_2 , L_7 ,
error ) ;
return error ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_3 ( V_2 -> V_26 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
int error ;
if ( F_4 ( ! V_2 -> V_26 ) )
return - V_27 ;
error = V_10 -> remove ( V_8 ) ;
if ( error < 0 ) {
F_12 ( V_2 ,
L_8 ,
error ) ;
return error ;
}
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_3 ( V_2 -> V_26 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_10 -> V_29 ( V_8 ) ;
}
int F_15 ( struct V_9 * V_30 ,
struct V_31 * V_32 )
{
int error ;
V_30 -> V_26 . V_32 = V_32 ;
V_30 -> V_26 . V_33 = & V_34 ;
if ( V_30 -> V_28 )
V_30 -> V_26 . V_28 = F_11 ;
if ( V_30 -> remove )
V_30 -> V_26 . remove = F_13 ;
if ( V_30 -> V_29 )
V_30 -> V_26 . V_29 = F_14 ;
error = F_16 ( & V_30 -> V_26 ) ;
if ( error < 0 ) {
F_17 ( L_9 ,
V_30 -> V_26 . V_35 , error ) ;
return error ;
}
F_18 ( L_10 ,
V_30 -> V_26 . V_35 ) ;
return 0 ;
}
void F_19 ( struct V_9 * V_30 )
{
F_20 ( & V_30 -> V_26 ) ;
}
bool F_5 ( void )
{
return F_21 ( & V_36 ) > 0 ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_1 * * V_37 )
{
if ( F_4 ( ! V_2 ) ) {
* V_37 = NULL ;
} else if ( F_4 ( V_2 -> V_33 != & V_34 ) ) {
* V_37 = NULL ;
} else {
* V_37 = V_2 ;
while ( ( * V_37 ) -> V_38 -> V_33 == & V_34 )
* V_37 = ( * V_37 ) -> V_38 ;
}
}
static bool F_6 ( struct V_1 * V_2 )
{
struct V_1 * V_37 ;
F_22 ( V_2 , & V_37 ) ;
if ( ! V_37 )
return false ;
else
return V_2 == V_37 ;
}
static int F_23 ( struct V_39 * V_40 ,
int V_41 , T_1 * V_42 )
{
T_1 V_43 ;
struct V_44 V_45 ;
int error ;
error = F_24 ( V_40 , 0 , V_41 , & V_43 ) ;
if ( error < 0 ) {
F_17 ( L_11 , error ) ;
return error ;
}
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
error = F_25 ( V_40 , 0 , V_43 , & V_45 ) ;
if ( error < 0 ) {
F_17 ( L_12 , error ) ;
goto V_46;
}
* V_42 = V_45 . V_42 ;
error = 0 ;
V_46:
( void ) F_26 ( V_40 , 0 , V_43 ) ;
return error ;
}
static int F_27 ( struct V_7 * V_8 ,
enum V_47 V_48 ,
T_2 V_49 , T_3 * V_50 )
{
int V_51 ;
struct V_1 * V_37 ;
struct V_52 * V_53 ;
F_22 ( & V_8 -> V_2 , & V_37 ) ;
if ( F_4 ( ! V_37 ) )
return - V_27 ;
V_53 = F_28 ( V_37 -> V_38 ) ;
if ( V_53 -> V_54 == 0 ) {
* V_50 = V_49 ;
return 0 ;
}
for ( V_51 = 0 ; V_51 < V_53 -> V_54 ; V_51 ++ ) {
struct V_55 * V_56 =
& V_53 -> V_57 [ V_51 ] ;
if ( V_48 == V_56 -> V_48 &&
V_49 >= V_56 -> V_58 &&
V_49 < V_56 -> V_59 ) {
* V_50 = V_56 -> V_60 +
( V_49 - V_56 -> V_58 ) ;
return 0 ;
}
}
return - V_61 ;
}
static int F_29 ( struct V_7 * V_8 ,
struct V_7 * V_62 )
{
int V_51 ;
int error ;
struct V_63 * V_64 ;
struct V_65 * V_16 = & V_8 -> V_16 ;
struct V_1 * V_66 = V_8 -> V_2 . V_38 ;
enum V_47 V_48 ;
if ( strcmp ( V_16 -> type , L_13 ) == 0 ||
strcmp ( V_16 -> type , L_14 ) == 0 ) {
V_48 = V_67 ;
} else if ( strcmp ( V_16 -> type , L_15 ) == 0 ) {
V_48 = V_68 ;
} else {
F_4 ( true ) ;
return - V_27 ;
}
V_64 = F_30 ( V_16 -> V_69 ,
sizeof( V_64 [ 0 ] ) , V_70 ) ;
if ( ! V_64 )
return - V_71 ;
for ( V_51 = 0 ; V_51 < V_16 -> V_69 ; V_51 ++ ) {
struct V_72 V_73 ;
error = F_31 ( V_62 -> V_40 ,
0 ,
V_62 -> V_74 ,
V_16 -> type ,
V_16 -> V_6 , V_51 , & V_73 ) ;
if ( error < 0 ) {
F_12 ( V_66 ,
L_16 , error ) ;
goto V_75;
}
F_4 ( V_73 . V_76 == 0 ) ;
error = F_27 ( V_8 , V_48 ,
V_73 . V_77 ,
& V_64 [ V_51 ] . V_78 ) ;
if ( error < 0 ) {
F_12 ( V_66 ,
L_17 ,
V_73 . V_77 ,
V_16 -> type , V_16 -> V_6 , V_51 ) ;
goto V_75;
}
V_64 [ V_51 ] . V_79 = V_64 [ V_51 ] . V_78 + V_73 . V_76 - 1 ;
V_64 [ V_51 ] . V_35 = L_18 ;
V_64 [ V_51 ] . V_80 = V_81 ;
}
V_8 -> V_64 = V_64 ;
return 0 ;
V_75:
F_32 ( V_64 ) ;
return error ;
}
int F_33 ( struct V_65 * V_16 ,
struct V_39 * V_40 ,
struct V_1 * V_66 ,
struct V_7 * * V_82 )
{
int error ;
struct V_7 * V_8 = NULL ;
struct V_83 * V_84 = NULL ;
struct V_7 * V_85 ;
if ( V_66 -> V_33 == & V_34 )
V_85 = F_2 ( V_66 ) ;
else
V_85 = NULL ;
if ( strcmp ( V_16 -> type , L_13 ) == 0 ) {
V_84 = F_34 ( V_66 , sizeof( * V_84 ) , V_70 ) ;
if ( ! V_84 )
return - V_71 ;
V_8 = & V_84 -> V_8 ;
} else {
V_8 = F_35 ( V_86 , V_70 ) ;
if ( ! V_8 )
return - V_71 ;
}
V_8 -> V_16 = * V_16 ;
V_8 -> V_40 = V_40 ;
F_36 ( & V_8 -> V_2 ) ;
V_8 -> V_2 . V_38 = V_66 ;
V_8 -> V_2 . V_33 = & V_34 ;
F_37 ( & V_8 -> V_2 , L_19 , V_16 -> type , V_16 -> V_6 ) ;
if ( strcmp ( V_16 -> type , L_13 ) == 0 ) {
struct V_39 * V_87 ;
V_8 -> V_80 |= V_88 ;
if ( V_85 ) {
V_87 = V_85 -> V_40 ;
} else {
if ( F_4 ( ! V_40 ) ) {
error = - V_27 ;
goto V_89;
}
V_87 = V_40 ;
F_38 ( & V_36 ) ;
}
error = F_23 ( V_87 , V_16 -> V_6 , & V_8 -> V_42 ) ;
if ( error < 0 )
goto V_89;
} else {
V_8 -> V_42 = V_85 -> V_42 ;
V_8 -> V_90 = V_91 ;
V_8 -> V_2 . V_90 = & V_8 -> V_90 ;
}
if ( V_85 && V_16 -> V_69 != 0 ) {
error = F_29 ( V_8 ,
V_85 ) ;
if ( error < 0 )
goto V_89;
}
error = F_39 ( & V_8 -> V_2 ) ;
if ( error < 0 ) {
F_12 ( V_66 ,
L_20 ,
F_40 ( & V_8 -> V_2 ) , error ) ;
goto V_89;
}
( void ) F_41 ( & V_8 -> V_2 ) ;
F_8 ( V_66 , L_21 ,
F_40 ( & V_8 -> V_2 ) ) ;
* V_82 = V_8 ;
return 0 ;
V_89:
F_32 ( V_8 -> V_64 ) ;
if ( V_84 )
F_42 ( V_66 , V_84 ) ;
else
F_43 ( V_86 , V_8 ) ;
return error ;
}
void F_44 ( struct V_7 * V_8 )
{
struct V_83 * V_84 = NULL ;
F_32 ( V_8 -> V_64 ) ;
F_45 ( & V_8 -> V_2 ) ;
F_46 ( & V_8 -> V_2 ) ;
if ( strcmp ( V_8 -> V_16 . type , L_13 ) == 0 ) {
V_84 = F_47 ( V_8 ) ;
if ( V_8 -> V_40 ) {
F_48 ( V_8 -> V_40 ) ;
V_8 -> V_40 = NULL ;
}
if ( F_6 ( & V_8 -> V_2 ) ) {
if ( F_21 ( & V_36 ) > 0 )
F_49 ( & V_36 ) ;
else
F_4 ( 1 ) ;
}
}
if ( V_84 )
F_42 ( V_8 -> V_2 . V_38 , V_84 ) ;
else
F_43 ( V_86 , V_8 ) ;
}
static int F_50 ( struct V_1 * V_2 ,
int * V_92 ,
int * V_93 ,
int * V_94 ,
const T_4 * * V_95 ,
T_5 * V_96 )
{
const T_4 * V_97 ;
int V_98 ;
int V_99 ;
int V_100 ;
struct V_101 * V_102 = V_2 -> V_103 ;
* V_95 = F_51 ( V_102 , L_22 , & V_99 ) ;
if ( ! ( * V_95 ) || ! V_99 ) {
F_7 ( V_2 ,
L_23 ,
V_102 -> V_35 ) ;
* V_96 = 0 ;
return 0 ;
}
* V_92 = F_52 ( V_102 ) ;
V_97 = F_51 ( V_102 , L_24 , NULL ) ;
if ( V_97 )
* V_93 = F_53 ( V_97 ) ;
else
* V_93 = * V_92 ;
V_97 = F_51 ( V_102 , L_25 , NULL ) ;
if ( V_97 )
* V_94 = F_53 ( V_97 ) ;
else
* V_94 = F_54 ( V_102 ) ;
V_98 = * V_92 + * V_93 +
* V_94 ;
V_100 = V_98 * sizeof( T_4 ) ;
if ( V_99 % V_100 != 0 ) {
F_12 ( V_2 , L_26 , V_102 -> V_35 ) ;
return - V_27 ;
}
* V_96 = V_99 / V_100 ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_55
* * V_104 ,
T_5 * V_96 )
{
int error ;
int V_92 ;
int V_93 ;
int V_94 ;
int V_51 ;
const T_4 * V_95 ;
const T_4 * V_105 ;
error = F_50 ( V_2 ,
& V_92 ,
& V_93 ,
& V_94 ,
& V_95 ,
V_96 ) ;
if ( error < 0 )
return error ;
if ( ! ( * V_96 ) ) {
* V_104 = NULL ;
return 0 ;
}
* V_104 = F_56 ( V_2 , * V_96 ,
sizeof( struct V_55 ) ,
V_70 ) ;
if ( ! ( * V_104 ) )
return - V_71 ;
V_105 = V_95 ;
for ( V_51 = 0 ; V_51 < * V_96 ; ++ V_51 ) {
struct V_55 * V_56 = & ( * V_104 ) [ V_51 ] ;
V_56 -> V_48 = F_57 ( V_105 , 1 ) ;
V_56 -> V_58 = F_57 ( V_105 + 1 ,
V_93 - 1 ) ;
V_105 += V_93 ;
V_56 -> V_60 = F_57 ( V_105 , V_92 ) ;
V_105 += V_92 ;
V_56 -> V_59 = V_56 -> V_58 +
F_57 ( V_105 , V_94 ) ;
V_105 += V_94 ;
}
return 0 ;
}
static int F_58 ( struct V_106 * V_107 )
{
struct V_65 V_16 ;
int error ;
struct V_52 * V_53 ;
struct V_7 * V_62 = NULL ;
struct V_39 * V_40 = NULL ;
int V_41 ;
T_3 V_108 ;
T_6 V_109 ;
struct V_110 V_110 ;
struct V_63 V_111 ;
F_59 ( & V_107 -> V_2 , L_27 ) ;
V_53 = F_34 ( & V_107 -> V_2 , sizeof( * V_53 ) , V_70 ) ;
if ( ! V_53 )
return - V_71 ;
F_60 ( V_107 , V_53 ) ;
error = F_61 ( V_107 -> V_2 . V_103 , 0 , & V_111 ) ;
if ( error < 0 ) {
F_12 ( & V_107 -> V_2 ,
L_28 ,
V_107 -> V_2 . V_103 -> V_112 ) ;
return error ;
}
V_108 = V_111 . V_78 ;
V_109 = F_62 ( & V_111 ) ;
error = F_63 ( & V_107 -> V_2 , V_108 ,
V_109 , NULL , 0 , & V_40 ) ;
if ( error < 0 )
return error ;
error = F_64 ( V_40 , 0 , & V_110 ) ;
if ( error != 0 ) {
F_12 ( & V_107 -> V_2 ,
L_29 , error ) ;
goto V_113;
}
F_59 ( & V_107 -> V_2 ,
L_30 ,
V_110 . V_114 , V_110 . V_115 , V_110 . V_116 ) ;
if ( V_110 . V_114 < V_117 ) {
F_12 ( & V_107 -> V_2 ,
L_31 ,
V_117 , V_118 ) ;
error = - V_119 ;
goto V_113;
}
if ( V_110 . V_114 > V_117 ) {
F_7 ( & V_107 -> V_2 ,
L_32 ,
V_117 , V_118 ) ;
}
error = F_55 ( & V_107 -> V_2 ,
& V_53 -> V_57 ,
& V_53 -> V_54 ) ;
if ( error < 0 )
goto V_113;
error = F_65 ( V_40 , 0 , & V_41 ) ;
if ( error < 0 ) {
F_12 ( & V_107 -> V_2 ,
L_33 , error ) ;
goto V_113;
}
V_16 . V_19 = V_120 ;
strcpy ( V_16 . type , L_13 ) ;
V_16 . V_6 = V_41 ;
V_16 . V_21 = V_121 ;
V_16 . V_22 = V_122 ;
V_16 . V_123 = 1 ;
V_16 . V_69 = 0 ;
error = F_33 ( & V_16 , V_40 , & V_107 -> V_2 , & V_62 ) ;
if ( error < 0 )
goto V_113;
V_53 -> V_124 = V_62 ;
return 0 ;
V_113:
F_48 ( V_40 ) ;
return error ;
}
static int F_66 ( struct V_106 * V_107 )
{
struct V_52 * V_53 = F_67 ( V_107 ) ;
if ( F_4 ( ! F_6 ( & V_53 -> V_124 -> V_2 ) ) )
return - V_27 ;
F_44 ( V_53 -> V_124 ) ;
F_59 ( & V_107 -> V_2 , L_34 ) ;
return 0 ;
}
static int T_7 F_68 ( void )
{
int error ;
V_86 = F_69 ( L_35 ,
sizeof( struct V_7 ) , 0 , 0 ,
NULL ) ;
if ( ! V_86 ) {
F_17 ( L_36 ) ;
return - V_71 ;
}
error = F_70 ( & V_34 ) ;
if ( error < 0 ) {
F_17 ( L_37 , error ) ;
goto V_125;
}
F_18 ( L_38 ) ;
error = F_71 ( & V_126 ) ;
if ( error < 0 ) {
F_17 ( L_39 , error ) ;
goto V_127;
}
error = F_72 () ;
if ( error < 0 )
goto V_128;
error = F_73 () ;
if ( error < 0 )
goto V_129;
return 0 ;
V_129:
F_74 () ;
V_128:
F_75 ( & V_126 ) ;
V_127:
F_76 ( & V_34 ) ;
V_125:
F_77 ( V_86 ) ;
return error ;
}
static void T_8 F_78 ( void )
{
if ( F_4 ( ! V_86 ) )
return;
F_79 () ;
F_74 () ;
F_75 ( & V_126 ) ;
F_76 ( & V_34 ) ;
F_77 ( V_86 ) ;
F_18 ( L_40 ) ;
}
