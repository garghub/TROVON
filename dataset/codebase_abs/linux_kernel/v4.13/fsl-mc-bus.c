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
static int F_19 ( struct V_36 * V_37 ,
T_2 V_38 ,
struct V_39 * V_40 )
{
struct V_41 V_42 = { 0 } ;
struct V_43 * V_44 ;
int V_45 ;
V_42 . V_46 = F_20 ( V_47 ,
V_38 ,
0 ) ;
V_45 = F_21 ( V_37 , & V_42 ) ;
if ( V_45 )
return V_45 ;
V_44 = (struct V_43 * ) V_42 . V_48 ;
V_40 -> V_49 = F_22 ( V_44 -> V_49 ) ;
V_40 -> V_50 = F_22 ( V_44 -> V_51 ) ;
V_40 -> V_52 = F_22 ( V_44 -> V_53 ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_1 * * V_54 )
{
if ( F_10 ( ! V_2 ) ) {
* V_54 = NULL ;
} else if ( F_10 ( ! F_24 ( V_2 ) ) ) {
* V_54 = NULL ;
} else {
* V_54 = V_2 ;
while ( F_24 ( ( * V_54 ) -> V_55 ) )
* V_54 = ( * V_54 ) -> V_55 ;
}
}
static int F_25 ( struct V_36 * V_37 ,
int V_56 , struct V_57 * V_23 )
{
T_3 V_58 ;
int error ;
error = F_26 ( V_37 , 0 , V_56 , & V_58 ) ;
if ( error < 0 ) {
F_11 ( V_37 -> V_2 , L_8 , error ) ;
return error ;
}
memset ( V_23 , 0 , sizeof( struct V_57 ) ) ;
error = F_27 ( V_37 , 0 , V_58 , V_23 ) ;
if ( error < 0 ) {
F_11 ( V_37 -> V_2 , L_9 ,
error ) ;
goto V_59;
}
error = 0 ;
V_59:
( void ) F_28 ( V_37 , 0 , V_58 ) ;
return error ;
}
static int F_29 ( struct V_36 * V_37 ,
int V_56 , T_3 * V_60 )
{
struct V_57 V_23 ;
int error ;
error = F_25 ( V_37 , V_56 , & V_23 ) ;
if ( error == 0 )
* V_60 = V_23 . V_60 ;
return error ;
}
static int F_30 ( struct V_7 * V_8 ,
enum V_61 V_62 ,
T_4 V_63 , T_5 * V_64 )
{
int V_65 ;
struct V_1 * V_54 ;
struct V_66 * V_67 ;
F_23 ( & V_8 -> V_2 , & V_54 ) ;
if ( F_10 ( ! V_54 ) )
return - V_26 ;
V_67 = F_31 ( V_54 -> V_55 ) ;
if ( V_67 -> V_68 == 0 ) {
* V_64 = V_63 ;
return 0 ;
}
for ( V_65 = 0 ; V_65 < V_67 -> V_68 ; V_65 ++ ) {
struct V_69 * V_70 =
& V_67 -> V_71 [ V_65 ] ;
if ( V_62 == V_70 -> V_62 &&
V_63 >= V_70 -> V_72 &&
V_63 < V_70 -> V_73 ) {
* V_64 = V_70 -> V_74 +
( V_63 - V_70 -> V_72 ) ;
return 0 ;
}
}
return - V_75 ;
}
static int F_32 ( struct V_7 * V_8 ,
struct V_7 * V_76 )
{
int V_65 ;
int error ;
struct V_77 * V_78 ;
struct V_79 * V_14 = & V_8 -> V_14 ;
struct V_1 * V_80 = V_8 -> V_2 . V_55 ;
enum V_61 V_62 ;
if ( strcmp ( V_14 -> type , L_10 ) == 0 ||
strcmp ( V_14 -> type , L_11 ) == 0 ) {
V_62 = V_81 ;
} else if ( strcmp ( V_14 -> type , L_12 ) == 0 ) {
V_62 = V_82 ;
} else {
F_10 ( true ) ;
return - V_26 ;
}
V_78 = F_33 ( V_14 -> V_83 ,
sizeof( V_78 [ 0 ] ) , V_84 ) ;
if ( ! V_78 )
return - V_21 ;
for ( V_65 = 0 ; V_65 < V_14 -> V_83 ; V_65 ++ ) {
struct V_85 V_86 ;
error = F_34 ( V_76 -> V_37 ,
0 ,
V_76 -> V_87 ,
V_14 -> type ,
V_14 -> V_6 , V_65 , & V_86 ) ;
if ( error < 0 ) {
F_11 ( V_80 ,
L_13 , error ) ;
goto V_88;
}
F_10 ( V_86 . V_89 == 0 ) ;
error = F_30 ( V_8 , V_62 ,
V_86 . V_90 ,
& V_78 [ V_65 ] . V_91 ) ;
if ( error < 0 ) {
F_11 ( V_80 ,
L_14 ,
V_86 . V_90 ,
V_14 -> type , V_14 -> V_6 , V_65 ) ;
goto V_88;
}
V_78 [ V_65 ] . V_92 = V_78 [ V_65 ] . V_91 + V_86 . V_89 - 1 ;
V_78 [ V_65 ] . V_35 = L_15 ;
V_78 [ V_65 ] . V_93 = V_94 ;
if ( V_86 . V_93 & V_95 )
V_78 [ V_65 ] . V_93 |= V_96 ;
}
V_8 -> V_78 = V_78 ;
return 0 ;
V_88:
F_35 ( V_78 ) ;
return error ;
}
bool F_4 ( struct V_1 * V_2 )
{
struct V_1 * V_54 ;
F_23 ( V_2 , & V_54 ) ;
if ( ! V_54 )
return false ;
return V_2 == V_54 ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_35 ( V_8 -> V_78 ) ;
if ( strcmp ( V_8 -> V_14 . type , L_10 ) == 0 )
F_35 ( F_37 ( V_8 ) ) ;
else
F_35 ( V_8 ) ;
}
int F_38 ( struct V_79 * V_14 ,
struct V_36 * V_37 ,
struct V_1 * V_80 ,
struct V_7 * * V_97 )
{
int error ;
struct V_7 * V_8 = NULL ;
struct V_98 * V_99 = NULL ;
struct V_7 * V_100 ;
if ( F_24 ( V_80 ) )
V_100 = F_2 ( V_80 ) ;
else
V_100 = NULL ;
if ( strcmp ( V_14 -> type , L_10 ) == 0 ) {
V_99 = F_39 ( sizeof( * V_99 ) , V_84 ) ;
if ( ! V_99 )
return - V_21 ;
V_8 = & V_99 -> V_8 ;
} else {
V_8 = F_39 ( sizeof( * V_8 ) , V_84 ) ;
if ( ! V_8 )
return - V_21 ;
}
V_8 -> V_14 = * V_14 ;
V_8 -> V_37 = V_37 ;
F_40 ( & V_8 -> V_2 ) ;
V_8 -> V_2 . V_55 = V_80 ;
V_8 -> V_2 . V_33 = & V_34 ;
V_8 -> V_2 . V_101 = F_36 ;
F_41 ( & V_8 -> V_2 , L_16 , V_14 -> type , V_14 -> V_6 ) ;
if ( strcmp ( V_14 -> type , L_10 ) == 0 ) {
struct V_36 * V_102 ;
V_8 -> V_93 |= V_103 ;
if ( V_100 ) {
V_102 = V_100 -> V_37 ;
} else {
if ( F_10 ( ! V_37 ) ) {
error = - V_26 ;
goto V_104;
}
V_102 = V_37 ;
}
error = F_29 ( V_102 , V_14 -> V_6 , & V_8 -> V_60 ) ;
if ( error < 0 )
goto V_104;
} else {
V_8 -> V_60 = V_100 -> V_60 ;
V_8 -> V_105 = V_106 ;
V_8 -> V_2 . V_105 = & V_8 -> V_105 ;
F_42 ( & V_8 -> V_2 ,
F_43 ( & V_100 -> V_2 ) ) ;
}
if ( V_100 && V_14 -> V_83 != 0 ) {
error = F_32 ( V_8 ,
V_100 ) ;
if ( error < 0 )
goto V_104;
}
if ( ! ( V_14 -> V_93 & V_107 ) )
F_44 ( & V_8 -> V_2 , 0 , 0 , NULL , true ) ;
error = F_45 ( & V_8 -> V_2 ) ;
if ( error < 0 ) {
F_11 ( V_80 ,
L_17 ,
F_46 ( & V_8 -> V_2 ) , error ) ;
goto V_104;
}
F_5 ( V_80 , L_18 , F_46 ( & V_8 -> V_2 ) ) ;
* V_97 = V_8 ;
return 0 ;
V_104:
F_35 ( V_8 -> V_78 ) ;
F_35 ( V_99 ) ;
F_35 ( V_8 ) ;
return error ;
}
void F_47 ( struct V_7 * V_8 )
{
F_48 ( & V_8 -> V_2 ) ;
F_49 ( & V_8 -> V_2 ) ;
}
static int F_50 ( struct V_1 * V_2 ,
int * V_108 ,
int * V_109 ,
int * V_110 ,
const T_6 * * V_111 )
{
const T_6 * V_112 ;
int V_113 ;
int V_114 ;
int V_115 ;
struct V_116 * V_117 = V_2 -> V_118 ;
* V_111 = F_51 ( V_117 , L_19 , & V_114 ) ;
if ( ! ( * V_111 ) || ! V_114 ) {
F_52 ( V_2 ,
L_20 ,
V_117 -> V_35 ) ;
return 0 ;
}
* V_108 = F_53 ( V_117 ) ;
V_112 = F_51 ( V_117 , L_21 , NULL ) ;
if ( V_112 )
* V_109 = F_54 ( V_112 ) ;
else
* V_109 = * V_108 ;
V_112 = F_51 ( V_117 , L_22 , NULL ) ;
if ( V_112 )
* V_110 = F_54 ( V_112 ) ;
else
* V_110 = F_55 ( V_117 ) ;
V_113 = * V_108 + * V_109 +
* V_110 ;
V_115 = V_113 * sizeof( T_6 ) ;
if ( V_114 % V_115 != 0 ) {
F_11 ( V_2 , L_23 , V_117 -> V_35 ) ;
return - V_26 ;
}
return V_114 / V_115 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_69
* * V_119 ,
T_7 * V_120 )
{
int V_121 ;
int V_108 ;
int V_109 ;
int V_110 ;
int V_65 ;
const T_6 * V_111 ;
const T_6 * V_122 ;
V_121 = F_50 ( V_2 ,
& V_108 ,
& V_109 ,
& V_110 ,
& V_111 ) ;
if ( V_121 < 0 )
return V_121 ;
* V_120 = V_121 ;
if ( ! V_121 ) {
* V_119 = NULL ;
return 0 ;
}
* V_119 = F_57 ( V_2 , * V_120 ,
sizeof( struct V_69 ) ,
V_84 ) ;
if ( ! ( * V_119 ) )
return - V_21 ;
V_122 = V_111 ;
for ( V_65 = 0 ; V_65 < * V_120 ; ++ V_65 ) {
struct V_69 * V_70 = & ( * V_119 ) [ V_65 ] ;
V_70 -> V_62 = F_58 ( V_122 , 1 ) ;
V_70 -> V_72 = F_58 ( V_122 + 1 ,
V_109 - 1 ) ;
V_122 += V_109 ;
V_70 -> V_74 = F_58 ( V_122 , V_108 ) ;
V_122 += V_108 ;
V_70 -> V_73 = V_70 -> V_72 +
F_58 ( V_122 , V_110 ) ;
V_122 += V_110 ;
}
return 0 ;
}
static int F_59 ( struct V_123 * V_124 )
{
struct V_79 V_14 ;
int error ;
struct V_66 * V_67 ;
struct V_7 * V_76 = NULL ;
struct V_36 * V_37 = NULL ;
int V_56 ;
T_5 V_125 ;
T_2 V_126 ;
struct V_39 V_39 ;
struct V_77 V_127 ;
V_67 = F_60 ( & V_124 -> V_2 , sizeof( * V_67 ) , V_84 ) ;
if ( ! V_67 )
return - V_21 ;
F_61 ( V_124 , V_67 ) ;
error = F_62 ( V_124 -> V_2 . V_118 , 0 , & V_127 ) ;
if ( error < 0 ) {
F_11 ( & V_124 -> V_2 ,
L_24 ,
V_124 -> V_2 . V_118 -> V_128 ) ;
return error ;
}
V_125 = V_127 . V_91 ;
V_126 = F_63 ( & V_127 ) ;
error = F_64 ( & V_124 -> V_2 , V_125 ,
V_126 , NULL ,
V_129 , & V_37 ) ;
if ( error < 0 )
return error ;
error = F_19 ( V_37 , 0 , & V_39 ) ;
if ( error != 0 ) {
F_11 ( & V_124 -> V_2 ,
L_25 , error ) ;
goto V_130;
}
F_65 ( & V_124 -> V_2 , L_26 ,
V_39 . V_50 , V_39 . V_52 , V_39 . V_49 ) ;
error = F_56 ( & V_124 -> V_2 ,
& V_67 -> V_71 ,
& V_67 -> V_68 ) ;
if ( error < 0 )
goto V_130;
error = F_66 ( V_37 , 0 , & V_56 ) ;
if ( error < 0 ) {
F_11 ( & V_124 -> V_2 ,
L_27 , error ) ;
goto V_130;
}
memset ( & V_14 , 0 , sizeof( struct V_79 ) ) ;
error = F_67 ( V_37 , 0 ,
& V_14 . V_131 ,
& V_14 . V_132 ) ;
if ( error < 0 )
goto V_130;
V_14 . V_17 = V_133 ;
strcpy ( V_14 . type , L_10 ) ;
V_14 . V_6 = V_56 ;
V_14 . V_134 = 1 ;
V_14 . V_83 = 0 ;
error = F_38 ( & V_14 , V_37 , & V_124 -> V_2 , & V_76 ) ;
if ( error < 0 )
goto V_130;
V_67 -> V_135 = V_76 ;
return 0 ;
V_130:
F_68 ( V_37 ) ;
return error ;
}
static int F_69 ( struct V_123 * V_124 )
{
struct V_66 * V_67 = F_70 ( V_124 ) ;
if ( F_10 ( ! F_4 ( & V_67 -> V_135 -> V_2 ) ) )
return - V_26 ;
F_47 ( V_67 -> V_135 ) ;
F_68 ( V_67 -> V_135 -> V_37 ) ;
V_67 -> V_135 -> V_37 = NULL ;
return 0 ;
}
static int T_8 F_71 ( void )
{
int error ;
error = F_72 ( & V_34 ) ;
if ( error < 0 ) {
F_16 ( L_28 , error ) ;
goto V_136;
}
error = F_73 ( & V_137 ) ;
if ( error < 0 ) {
F_16 ( L_29 , error ) ;
goto V_138;
}
error = F_74 () ;
if ( error < 0 )
goto V_139;
error = F_75 () ;
if ( error < 0 )
goto V_140;
error = F_76 () ;
if ( error < 0 )
goto V_141;
return 0 ;
V_141:
F_77 () ;
V_140:
F_78 () ;
V_139:
F_79 ( & V_137 ) ;
V_138:
F_80 ( & V_34 ) ;
V_136:
return error ;
}
