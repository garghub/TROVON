static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_5 * V_6 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_3 ( V_4 ) ;
bool V_11 = false ;
if ( ! V_10 -> V_12 )
goto V_13;
if ( ( V_8 -> V_14 . V_15 & V_16 ) == 0 &&
! F_4 ( & V_8 -> V_2 ) )
goto V_13;
for ( V_6 = V_10 -> V_12 ; V_6 -> V_17 != 0x0 ; V_6 ++ ) {
if ( V_6 -> V_17 == V_8 -> V_14 . V_17 &&
strcmp ( V_6 -> V_18 , V_8 -> V_14 . type ) == 0 ) {
V_11 = true ;
break;
}
}
V_13:
F_5 ( V_2 , L_1 , V_11 ? L_2 : L_3 ) ;
return V_11 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_7 ( V_20 , L_4 ,
V_8 -> V_14 . V_17 ,
V_8 -> V_14 . type ) )
return - V_21 ;
return 0 ;
}
static T_1 F_8 ( struct V_1 * V_2 , struct V_22 * V_23 ,
char * V_24 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return sprintf ( V_24 , L_5 , V_8 -> V_14 . V_17 ,
V_8 -> V_14 . type ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
int error ;
if ( F_10 ( ! V_2 -> V_25 ) )
return - V_26 ;
V_10 = F_3 ( V_2 -> V_25 ) ;
if ( F_10 ( ! V_10 -> V_27 ) )
return - V_26 ;
error = V_10 -> V_27 ( V_8 ) ;
if ( error < 0 ) {
F_11 ( V_2 , L_6 , V_28 , error ) ;
return error ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_3 ( V_2 -> V_25 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
int error ;
if ( F_10 ( ! V_2 -> V_25 ) )
return - V_26 ;
error = V_10 -> remove ( V_8 ) ;
if ( error < 0 ) {
F_11 ( V_2 , L_6 , V_28 , error ) ;
return error ;
}
return 0 ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_3 ( V_2 -> V_25 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_10 -> V_29 ( V_8 ) ;
}
int F_14 ( struct V_9 * V_30 ,
struct V_31 * V_32 )
{
int error ;
V_30 -> V_25 . V_32 = V_32 ;
V_30 -> V_25 . V_33 = & V_34 ;
if ( V_30 -> V_27 )
V_30 -> V_25 . V_27 = F_9 ;
if ( V_30 -> remove )
V_30 -> V_25 . remove = F_12 ;
if ( V_30 -> V_29 )
V_30 -> V_25 . V_29 = F_13 ;
error = F_15 ( & V_30 -> V_25 ) ;
if ( error < 0 ) {
F_16 ( L_7 ,
V_30 -> V_25 . V_35 , error ) ;
return error ;
}
return 0 ;
}
void F_17 ( struct V_9 * V_30 )
{
F_18 ( & V_30 -> V_25 ) ;
}
void F_19 ( struct V_1 * V_2 ,
struct V_1 * * V_36 )
{
if ( F_10 ( ! V_2 ) ) {
* V_36 = NULL ;
} else if ( F_10 ( ! F_20 ( V_2 ) ) ) {
* V_36 = NULL ;
} else {
* V_36 = V_2 ;
while ( F_20 ( ( * V_36 ) -> V_37 ) )
* V_36 = ( * V_36 ) -> V_37 ;
}
}
static int F_21 ( struct V_38 * V_39 ,
int V_40 , struct V_41 * V_23 )
{
T_2 V_42 ;
int error ;
error = F_22 ( V_39 , 0 , V_40 , & V_42 ) ;
if ( error < 0 ) {
F_11 ( V_39 -> V_2 , L_8 , error ) ;
return error ;
}
memset ( V_23 , 0 , sizeof( struct V_41 ) ) ;
error = F_23 ( V_39 , 0 , V_42 , V_23 ) ;
if ( error < 0 ) {
F_11 ( V_39 -> V_2 , L_9 ,
error ) ;
goto V_43;
}
error = 0 ;
V_43:
( void ) F_24 ( V_39 , 0 , V_42 ) ;
return error ;
}
static int F_25 ( struct V_38 * V_39 ,
int V_40 , T_2 * V_44 )
{
struct V_41 V_23 ;
int error ;
error = F_21 ( V_39 , V_40 , & V_23 ) ;
if ( error == 0 )
* V_44 = V_23 . V_44 ;
return error ;
}
static int F_26 ( struct V_7 * V_8 ,
enum V_45 V_46 ,
T_3 V_47 , T_4 * V_48 )
{
int V_49 ;
struct V_1 * V_36 ;
struct V_50 * V_51 ;
F_19 ( & V_8 -> V_2 , & V_36 ) ;
if ( F_10 ( ! V_36 ) )
return - V_26 ;
V_51 = F_27 ( V_36 -> V_37 ) ;
if ( V_51 -> V_52 == 0 ) {
* V_48 = V_47 ;
return 0 ;
}
for ( V_49 = 0 ; V_49 < V_51 -> V_52 ; V_49 ++ ) {
struct V_53 * V_54 =
& V_51 -> V_55 [ V_49 ] ;
if ( V_46 == V_54 -> V_46 &&
V_47 >= V_54 -> V_56 &&
V_47 < V_54 -> V_57 ) {
* V_48 = V_54 -> V_58 +
( V_47 - V_54 -> V_56 ) ;
return 0 ;
}
}
return - V_59 ;
}
static int F_28 ( struct V_7 * V_8 ,
struct V_7 * V_60 )
{
int V_49 ;
int error ;
struct V_61 * V_62 ;
struct V_63 * V_14 = & V_8 -> V_14 ;
struct V_1 * V_64 = V_8 -> V_2 . V_37 ;
enum V_45 V_46 ;
if ( strcmp ( V_14 -> type , L_10 ) == 0 ||
strcmp ( V_14 -> type , L_11 ) == 0 ) {
V_46 = V_65 ;
} else if ( strcmp ( V_14 -> type , L_12 ) == 0 ) {
V_46 = V_66 ;
} else {
F_10 ( true ) ;
return - V_26 ;
}
V_62 = F_29 ( V_14 -> V_67 ,
sizeof( V_62 [ 0 ] ) , V_68 ) ;
if ( ! V_62 )
return - V_21 ;
for ( V_49 = 0 ; V_49 < V_14 -> V_67 ; V_49 ++ ) {
struct V_69 V_70 ;
error = F_30 ( V_60 -> V_39 ,
0 ,
V_60 -> V_71 ,
V_14 -> type ,
V_14 -> V_6 , V_49 , & V_70 ) ;
if ( error < 0 ) {
F_11 ( V_64 ,
L_13 , error ) ;
goto V_72;
}
F_10 ( V_70 . V_73 == 0 ) ;
error = F_26 ( V_8 , V_46 ,
V_70 . V_74 ,
& V_62 [ V_49 ] . V_75 ) ;
if ( error < 0 ) {
F_11 ( V_64 ,
L_14 ,
V_70 . V_74 ,
V_14 -> type , V_14 -> V_6 , V_49 ) ;
goto V_72;
}
V_62 [ V_49 ] . V_76 = V_62 [ V_49 ] . V_75 + V_70 . V_73 - 1 ;
V_62 [ V_49 ] . V_35 = L_15 ;
V_62 [ V_49 ] . V_77 = V_78 ;
if ( V_70 . V_77 & V_79 )
V_62 [ V_49 ] . V_77 |= V_80 ;
}
V_8 -> V_62 = V_62 ;
return 0 ;
V_72:
F_31 ( V_62 ) ;
return error ;
}
bool F_4 ( struct V_1 * V_2 )
{
struct V_1 * V_36 ;
F_19 ( V_2 , & V_36 ) ;
if ( ! V_36 )
return false ;
return V_2 == V_36 ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_81 * V_82 = NULL ;
F_31 ( V_8 -> V_62 ) ;
if ( strcmp ( V_8 -> V_14 . type , L_10 ) == 0 )
V_82 = F_33 ( V_8 ) ;
if ( V_82 )
F_31 ( V_82 ) ;
else
F_31 ( V_8 ) ;
}
int F_34 ( struct V_63 * V_14 ,
struct V_38 * V_39 ,
struct V_1 * V_64 ,
struct V_7 * * V_83 )
{
int error ;
struct V_7 * V_8 = NULL ;
struct V_81 * V_82 = NULL ;
struct V_7 * V_84 ;
if ( F_20 ( V_64 ) )
V_84 = F_2 ( V_64 ) ;
else
V_84 = NULL ;
if ( strcmp ( V_14 -> type , L_10 ) == 0 ) {
V_82 = F_35 ( sizeof( * V_82 ) , V_68 ) ;
if ( ! V_82 )
return - V_21 ;
V_8 = & V_82 -> V_8 ;
} else {
V_8 = F_35 ( sizeof( * V_8 ) , V_68 ) ;
if ( ! V_8 )
return - V_21 ;
}
V_8 -> V_14 = * V_14 ;
V_8 -> V_39 = V_39 ;
F_36 ( & V_8 -> V_2 ) ;
V_8 -> V_2 . V_37 = V_64 ;
V_8 -> V_2 . V_33 = & V_34 ;
V_8 -> V_2 . V_85 = F_32 ;
F_37 ( & V_8 -> V_2 , L_16 , V_14 -> type , V_14 -> V_6 ) ;
if ( strcmp ( V_14 -> type , L_10 ) == 0 ) {
struct V_38 * V_86 ;
V_8 -> V_77 |= V_87 ;
if ( V_84 ) {
V_86 = V_84 -> V_39 ;
} else {
if ( F_10 ( ! V_39 ) ) {
error = - V_26 ;
goto V_88;
}
V_86 = V_39 ;
}
error = F_25 ( V_86 , V_14 -> V_6 , & V_8 -> V_44 ) ;
if ( error < 0 )
goto V_88;
} else {
V_8 -> V_44 = V_84 -> V_44 ;
V_8 -> V_89 = V_90 ;
V_8 -> V_2 . V_89 = & V_8 -> V_89 ;
F_38 ( & V_8 -> V_2 ,
F_39 ( & V_84 -> V_2 ) ) ;
}
if ( V_84 && V_14 -> V_67 != 0 ) {
error = F_28 ( V_8 ,
V_84 ) ;
if ( error < 0 )
goto V_88;
}
if ( ! ( V_14 -> V_77 & V_91 ) )
F_40 ( & V_8 -> V_2 , 0 , 0 , NULL , true ) ;
error = F_41 ( & V_8 -> V_2 ) ;
if ( error < 0 ) {
F_11 ( V_64 ,
L_17 ,
F_42 ( & V_8 -> V_2 ) , error ) ;
goto V_88;
}
F_5 ( V_64 , L_18 , F_42 ( & V_8 -> V_2 ) ) ;
* V_83 = V_8 ;
return 0 ;
V_88:
F_31 ( V_8 -> V_62 ) ;
if ( V_82 )
F_31 ( V_82 ) ;
else
F_31 ( V_8 ) ;
return error ;
}
void F_43 ( struct V_7 * V_8 )
{
F_44 ( & V_8 -> V_2 ) ;
F_45 ( & V_8 -> V_2 ) ;
}
static int F_46 ( struct V_1 * V_2 ,
int * V_92 ,
int * V_93 ,
int * V_94 ,
const T_5 * * V_95 )
{
const T_5 * V_96 ;
int V_97 ;
int V_98 ;
int V_99 ;
struct V_100 * V_101 = V_2 -> V_102 ;
* V_95 = F_47 ( V_101 , L_19 , & V_98 ) ;
if ( ! ( * V_95 ) || ! V_98 ) {
F_48 ( V_2 ,
L_20 ,
V_101 -> V_35 ) ;
return 0 ;
}
* V_92 = F_49 ( V_101 ) ;
V_96 = F_47 ( V_101 , L_21 , NULL ) ;
if ( V_96 )
* V_93 = F_50 ( V_96 ) ;
else
* V_93 = * V_92 ;
V_96 = F_47 ( V_101 , L_22 , NULL ) ;
if ( V_96 )
* V_94 = F_50 ( V_96 ) ;
else
* V_94 = F_51 ( V_101 ) ;
V_97 = * V_92 + * V_93 +
* V_94 ;
V_99 = V_97 * sizeof( T_5 ) ;
if ( V_98 % V_99 != 0 ) {
F_11 ( V_2 , L_23 , V_101 -> V_35 ) ;
return - V_26 ;
}
return V_98 / V_99 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_53
* * V_103 ,
T_6 * V_104 )
{
int V_105 ;
int V_92 ;
int V_93 ;
int V_94 ;
int V_49 ;
const T_5 * V_95 ;
const T_5 * V_106 ;
V_105 = F_46 ( V_2 ,
& V_92 ,
& V_93 ,
& V_94 ,
& V_95 ) ;
if ( V_105 < 0 )
return V_105 ;
* V_104 = V_105 ;
if ( ! V_105 ) {
* V_103 = NULL ;
return 0 ;
}
* V_103 = F_53 ( V_2 , * V_104 ,
sizeof( struct V_53 ) ,
V_68 ) ;
if ( ! ( * V_103 ) )
return - V_21 ;
V_106 = V_95 ;
for ( V_49 = 0 ; V_49 < * V_104 ; ++ V_49 ) {
struct V_53 * V_54 = & ( * V_103 ) [ V_49 ] ;
V_54 -> V_46 = F_54 ( V_106 , 1 ) ;
V_54 -> V_56 = F_54 ( V_106 + 1 ,
V_93 - 1 ) ;
V_106 += V_93 ;
V_54 -> V_58 = F_54 ( V_106 , V_92 ) ;
V_106 += V_92 ;
V_54 -> V_57 = V_54 -> V_56 +
F_54 ( V_106 , V_94 ) ;
V_106 += V_94 ;
}
return 0 ;
}
static int F_55 ( struct V_107 * V_108 )
{
struct V_63 V_14 ;
int error ;
struct V_50 * V_51 ;
struct V_7 * V_60 = NULL ;
struct V_38 * V_39 = NULL ;
int V_40 ;
T_4 V_109 ;
T_7 V_110 ;
struct V_111 V_111 ;
struct V_61 V_112 ;
V_51 = F_56 ( & V_108 -> V_2 , sizeof( * V_51 ) , V_68 ) ;
if ( ! V_51 )
return - V_21 ;
F_57 ( V_108 , V_51 ) ;
error = F_58 ( V_108 -> V_2 . V_102 , 0 , & V_112 ) ;
if ( error < 0 ) {
F_11 ( & V_108 -> V_2 ,
L_24 ,
V_108 -> V_2 . V_102 -> V_113 ) ;
return error ;
}
V_109 = V_112 . V_75 ;
V_110 = F_59 ( & V_112 ) ;
error = F_60 ( & V_108 -> V_2 , V_109 ,
V_110 , NULL ,
V_114 , & V_39 ) ;
if ( error < 0 )
return error ;
error = F_61 ( V_39 , 0 , & V_111 ) ;
if ( error != 0 ) {
F_11 ( & V_108 -> V_2 ,
L_25 , error ) ;
goto V_115;
}
F_62 ( & V_108 -> V_2 , L_26 ,
V_111 . V_116 , V_111 . V_117 , V_111 . V_118 ) ;
error = F_52 ( & V_108 -> V_2 ,
& V_51 -> V_55 ,
& V_51 -> V_52 ) ;
if ( error < 0 )
goto V_115;
error = F_63 ( V_39 , 0 , & V_40 ) ;
if ( error < 0 ) {
F_11 ( & V_108 -> V_2 ,
L_27 , error ) ;
goto V_115;
}
memset ( & V_14 , 0 , sizeof( struct V_63 ) ) ;
error = F_64 ( V_39 , 0 ,
& V_14 . V_119 ,
& V_14 . V_120 ) ;
if ( error < 0 )
goto V_115;
V_14 . V_17 = V_121 ;
strcpy ( V_14 . type , L_10 ) ;
V_14 . V_6 = V_40 ;
V_14 . V_122 = 1 ;
V_14 . V_67 = 0 ;
error = F_34 ( & V_14 , V_39 , & V_108 -> V_2 , & V_60 ) ;
if ( error < 0 )
goto V_115;
V_51 -> V_123 = V_60 ;
return 0 ;
V_115:
F_65 ( V_39 ) ;
return error ;
}
static int F_66 ( struct V_107 * V_108 )
{
struct V_50 * V_51 = F_67 ( V_108 ) ;
if ( F_10 ( ! F_4 ( & V_51 -> V_123 -> V_2 ) ) )
return - V_26 ;
F_43 ( V_51 -> V_123 ) ;
F_65 ( V_51 -> V_123 -> V_39 ) ;
V_51 -> V_123 -> V_39 = NULL ;
return 0 ;
}
static int T_8 F_68 ( void )
{
int error ;
error = F_69 ( & V_34 ) ;
if ( error < 0 ) {
F_16 ( L_28 , error ) ;
goto V_124;
}
error = F_70 ( & V_125 ) ;
if ( error < 0 ) {
F_16 ( L_29 , error ) ;
goto V_126;
}
error = F_71 () ;
if ( error < 0 )
goto V_127;
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
F_75 () ;
V_127:
F_76 ( & V_125 ) ;
V_126:
F_77 ( & V_34 ) ;
V_124:
return error ;
}
