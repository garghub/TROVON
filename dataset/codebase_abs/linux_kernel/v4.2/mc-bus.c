static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_5 * V_6 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_3 ( V_4 ) ;
bool V_11 = false ;
bool V_12 = false ;
bool V_13 = false ;
if ( F_4 ( ! V_14 . V_15 ) )
goto V_16;
if ( ! V_10 -> V_17 )
goto V_16;
if ( ( V_8 -> V_18 . V_19 & V_20 ) == 0 &&
& V_8 -> V_2 != V_14 . V_15 )
goto V_16;
for ( V_6 = V_10 -> V_17 ; V_6 -> V_21 != 0x0 ; V_6 ++ ) {
if ( V_6 -> V_21 == V_8 -> V_18 . V_21 &&
strcmp ( V_6 -> V_22 , V_8 -> V_18 . type ) == 0 ) {
if ( V_6 -> V_23 == V_8 -> V_18 . V_23 ) {
V_11 = true ;
if ( V_6 -> V_24 != V_8 -> V_18 . V_24 )
V_13 = true ;
} else {
V_12 = true ;
}
break;
}
}
if ( V_12 ) {
F_5 ( V_2 ,
L_1 ,
V_6 -> V_23 , V_6 -> V_24 ,
V_8 -> V_18 . V_23 ,
V_8 -> V_18 . V_24 ) ;
} else if ( V_13 ) {
F_5 ( V_2 ,
L_2 ,
V_6 -> V_23 , V_6 -> V_24 ,
V_8 -> V_18 . V_23 ,
V_8 -> V_18 . V_24 ) ;
}
V_16:
F_6 ( V_2 , L_3 , V_11 ? L_4 : L_5 ) ;
return V_11 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
F_8 ( L_6 , V_27 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
int error ;
if ( F_4 ( ! V_2 -> V_28 ) )
return - V_29 ;
V_10 = F_3 ( V_2 -> V_28 ) ;
if ( F_4 ( ! V_10 -> V_30 ) )
return - V_29 ;
error = V_10 -> V_30 ( V_8 ) ;
if ( error < 0 ) {
F_10 ( V_2 , L_7 ,
error ) ;
return error ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_3 ( V_2 -> V_28 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
int error ;
if ( F_4 ( ! V_2 -> V_28 ) )
return - V_29 ;
error = V_10 -> remove ( V_8 ) ;
if ( error < 0 ) {
F_10 ( V_2 ,
L_8 ,
error ) ;
return error ;
}
return 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_3 ( V_2 -> V_28 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_10 -> V_31 ( V_8 ) ;
}
int F_13 ( struct V_9 * V_32 ,
struct V_33 * V_34 )
{
int error ;
V_32 -> V_28 . V_34 = V_34 ;
V_32 -> V_28 . V_35 = & V_14 ;
if ( V_32 -> V_30 )
V_32 -> V_28 . V_30 = F_9 ;
if ( V_32 -> remove )
V_32 -> V_28 . remove = F_11 ;
if ( V_32 -> V_31 )
V_32 -> V_28 . V_31 = F_12 ;
error = F_14 ( & V_32 -> V_28 ) ;
if ( error < 0 ) {
F_15 ( L_9 ,
V_32 -> V_28 . V_36 , error ) ;
return error ;
}
F_16 ( L_10 ,
V_32 -> V_28 . V_36 ) ;
return 0 ;
}
void F_17 ( struct V_9 * V_32 )
{
F_18 ( & V_32 -> V_28 ) ;
}
static int F_19 ( struct V_37 * V_38 ,
int V_39 , T_1 * V_40 )
{
T_1 V_41 ;
struct V_42 V_43 ;
int error ;
error = F_20 ( V_38 , V_39 , & V_41 ) ;
if ( error < 0 ) {
F_15 ( L_11 , error ) ;
return error ;
}
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
error = F_21 ( V_38 , V_41 , & V_43 ) ;
if ( error < 0 ) {
F_15 ( L_12 , error ) ;
goto V_44;
}
* V_40 = V_43 . V_40 ;
error = 0 ;
V_44:
( void ) F_22 ( V_38 , V_41 ) ;
return error ;
}
static int F_23 ( T_2 V_45 , T_3 * V_46 )
{
int V_47 ;
struct V_48 * V_49 = F_24 ( V_14 . V_15 -> V_50 ) ;
if ( V_49 -> V_51 == 0 ) {
* V_46 = V_45 ;
return 0 ;
}
for ( V_47 = 0 ; V_47 < V_49 -> V_51 ; V_47 ++ ) {
struct V_52 * V_53 =
& V_49 -> V_54 [ V_47 ] ;
if ( V_45 >= V_53 -> V_55 &&
V_45 < V_53 -> V_56 ) {
* V_46 = V_53 -> V_57 +
( V_45 - V_53 -> V_55 ) ;
return 0 ;
}
}
return - V_58 ;
}
static int F_25 ( struct V_7 * V_8 ,
struct V_7 * V_59 )
{
int V_47 ;
int error ;
struct V_60 * V_61 ;
struct V_62 * V_18 = & V_8 -> V_18 ;
struct V_1 * V_63 = V_8 -> V_2 . V_50 ;
V_61 = F_26 ( V_18 -> V_64 ,
sizeof( V_61 [ 0 ] ) , V_65 ) ;
if ( ! V_61 )
return - V_66 ;
for ( V_47 = 0 ; V_47 < V_18 -> V_64 ; V_47 ++ ) {
struct V_67 V_68 ;
error = F_27 ( V_59 -> V_38 ,
V_59 -> V_69 ,
V_18 -> type ,
V_18 -> V_6 , V_47 , & V_68 ) ;
if ( error < 0 ) {
F_10 ( V_63 ,
L_13 , error ) ;
goto V_70;
}
F_4 ( V_68 . V_71 == 0x0 ) ;
F_4 ( V_68 . V_72 == 0 ) ;
error = F_23 ( V_68 . V_71 ,
& V_61 [ V_47 ] . V_73 ) ;
if ( error < 0 ) {
F_10 ( V_63 ,
L_14 ,
V_68 . V_71 ) ;
goto V_70;
}
V_61 [ V_47 ] . V_74 = V_61 [ V_47 ] . V_73 + V_68 . V_72 - 1 ;
V_61 [ V_47 ] . V_36 = L_15 ;
V_61 [ V_47 ] . V_75 = V_76 ;
}
V_8 -> V_61 = V_61 ;
return 0 ;
V_70:
F_28 ( V_61 ) ;
return error ;
}
int F_29 ( struct V_62 * V_18 ,
struct V_37 * V_38 ,
struct V_1 * V_63 ,
struct V_7 * * V_77 )
{
int error ;
struct V_7 * V_8 = NULL ;
struct V_78 * V_79 = NULL ;
struct V_7 * V_80 ;
if ( V_63 -> V_35 == & V_14 )
V_80 = F_2 ( V_63 ) ;
else
V_80 = NULL ;
if ( strcmp ( V_18 -> type , L_16 ) == 0 ) {
V_79 = F_30 ( V_63 , sizeof( * V_79 ) , V_65 ) ;
if ( ! V_79 )
return - V_66 ;
V_8 = & V_79 -> V_8 ;
} else {
V_8 = F_31 ( V_81 , V_65 ) ;
if ( ! V_8 )
return - V_66 ;
}
V_8 -> V_18 = * V_18 ;
V_8 -> V_38 = V_38 ;
F_32 ( & V_8 -> V_2 ) ;
V_8 -> V_2 . V_50 = V_63 ;
V_8 -> V_2 . V_35 = & V_14 ;
F_33 ( & V_8 -> V_2 , L_17 , V_18 -> type , V_18 -> V_6 ) ;
if ( strcmp ( V_18 -> type , L_16 ) == 0 ) {
struct V_37 * V_82 ;
V_8 -> V_75 |= V_83 ;
if ( V_80 ) {
V_82 = V_80 -> V_38 ;
} else {
if ( F_4 ( ! V_38 ) ) {
error = - V_29 ;
goto V_84;
}
V_82 = V_38 ;
if ( ! V_14 . V_15 )
V_14 . V_15 = & V_8 -> V_2 ;
}
error = F_19 ( V_82 , V_18 -> V_6 , & V_8 -> V_40 ) ;
if ( error < 0 )
goto V_84;
} else {
V_8 -> V_40 = V_80 -> V_40 ;
V_8 -> V_85 = V_86 ;
V_8 -> V_2 . V_85 = & V_8 -> V_85 ;
}
if ( V_80 && V_18 -> V_64 != 0 ) {
error = F_25 ( V_8 ,
V_80 ) ;
if ( error < 0 )
goto V_84;
}
error = F_34 ( & V_8 -> V_2 ) ;
if ( error < 0 ) {
F_10 ( V_63 ,
L_18 ,
F_35 ( & V_8 -> V_2 ) , error ) ;
goto V_84;
}
( void ) F_36 ( & V_8 -> V_2 ) ;
F_6 ( V_63 , L_19 ,
F_35 ( & V_8 -> V_2 ) ) ;
* V_77 = V_8 ;
return 0 ;
V_84:
F_28 ( V_8 -> V_61 ) ;
if ( V_79 )
F_37 ( V_63 , V_79 ) ;
else
F_38 ( V_81 , V_8 ) ;
return error ;
}
void F_39 ( struct V_7 * V_8 )
{
struct V_78 * V_79 = NULL ;
F_28 ( V_8 -> V_61 ) ;
F_40 ( & V_8 -> V_2 ) ;
F_41 ( & V_8 -> V_2 ) ;
if ( strcmp ( V_8 -> V_18 . type , L_16 ) == 0 ) {
V_79 = F_42 ( V_8 ) ;
if ( V_8 -> V_38 ) {
F_43 ( V_8 -> V_38 ) ;
V_8 -> V_38 = NULL ;
}
if ( & V_8 -> V_2 == V_14 . V_15 )
V_14 . V_15 = NULL ;
}
if ( V_79 )
F_37 ( V_8 -> V_2 . V_50 , V_79 ) ;
else
F_38 ( V_81 , V_8 ) ;
}
static int F_44 ( struct V_1 * V_2 ,
int * V_87 ,
int * V_88 ,
int * V_89 ,
const T_4 * * V_90 ,
T_5 * V_91 )
{
const T_4 * V_92 ;
int V_93 ;
int V_94 ;
int V_95 ;
struct V_96 * V_97 = V_2 -> V_98 ;
* V_90 = F_45 ( V_97 , L_20 , & V_94 ) ;
if ( ! ( * V_90 ) || ! V_94 ) {
F_5 ( V_2 ,
L_21 ,
V_97 -> V_36 ) ;
* V_91 = 0 ;
return 0 ;
}
* V_87 = F_46 ( V_97 ) ;
V_92 = F_45 ( V_97 , L_22 , NULL ) ;
if ( V_92 )
* V_88 = F_47 ( V_92 ) ;
else
* V_88 = * V_87 ;
V_92 = F_45 ( V_97 , L_23 , NULL ) ;
if ( V_92 )
* V_89 = F_47 ( V_92 ) ;
else
* V_89 = F_48 ( V_97 ) ;
V_93 = * V_87 + * V_88 +
* V_89 ;
V_95 = V_93 * sizeof( T_4 ) ;
if ( V_94 % V_95 != 0 ) {
F_10 ( V_2 , L_24 , V_97 -> V_36 ) ;
return - V_29 ;
}
* V_91 = V_94 / V_95 ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_52
* * V_99 ,
T_5 * V_91 )
{
int error ;
int V_87 ;
int V_88 ;
int V_89 ;
int V_47 ;
const T_4 * V_90 ;
const T_4 * V_100 ;
error = F_44 ( V_2 ,
& V_87 ,
& V_88 ,
& V_89 ,
& V_90 ,
V_91 ) ;
if ( error < 0 )
return error ;
if ( ! ( * V_91 ) ) {
* V_99 = NULL ;
return 0 ;
}
* V_99 = F_50 ( V_2 , * V_91 ,
sizeof( struct V_52 ) ,
V_65 ) ;
if ( ! ( * V_99 ) )
return - V_66 ;
V_100 = V_90 ;
for ( V_47 = 0 ; V_47 < * V_91 ; ++ V_47 ) {
struct V_52 * V_53 = & ( * V_99 ) [ V_47 ] ;
V_53 -> V_55 = F_51 ( V_100 , V_88 ) ;
V_100 += V_88 ;
V_53 -> V_57 = F_51 ( V_100 , V_87 ) ;
V_100 += V_87 ;
V_53 -> V_56 = V_53 -> V_55 +
F_51 ( V_100 , V_89 ) ;
V_100 += V_89 ;
}
return 0 ;
}
static int F_52 ( struct V_101 * V_102 )
{
struct V_62 V_18 ;
int error ;
struct V_48 * V_49 ;
struct V_7 * V_59 = NULL ;
struct V_37 * V_38 = NULL ;
int V_39 ;
T_3 V_103 ;
T_6 V_104 ;
struct V_105 V_105 ;
struct V_60 V_106 ;
F_53 ( & V_102 -> V_2 , L_25 ) ;
V_49 = F_30 ( & V_102 -> V_2 , sizeof( * V_49 ) , V_65 ) ;
if ( ! V_49 )
return - V_66 ;
F_54 ( V_102 , V_49 ) ;
error = F_55 ( V_102 -> V_2 . V_98 , 0 , & V_106 ) ;
if ( error < 0 ) {
F_10 ( & V_102 -> V_2 ,
L_26 ,
V_102 -> V_2 . V_98 -> V_107 ) ;
return error ;
}
V_103 = V_106 . V_73 ;
V_104 = F_56 ( & V_106 ) ;
error = F_57 ( & V_102 -> V_2 , V_103 ,
V_104 , NULL , 0 , & V_38 ) ;
if ( error < 0 )
return error ;
error = F_58 ( V_38 , & V_105 ) ;
if ( error != 0 ) {
F_10 ( & V_102 -> V_2 ,
L_27 , error ) ;
goto V_108;
}
F_53 ( & V_102 -> V_2 ,
L_28 ,
V_105 . V_109 , V_105 . V_110 , V_105 . V_111 ) ;
if ( V_105 . V_109 < V_112 ) {
F_10 ( & V_102 -> V_2 ,
L_29 ,
V_112 , V_113 ) ;
error = - V_114 ;
goto V_108;
}
if ( V_105 . V_109 > V_112 ) {
F_5 ( & V_102 -> V_2 ,
L_30 ,
V_112 , V_113 ) ;
}
error = F_49 ( & V_102 -> V_2 ,
& V_49 -> V_54 ,
& V_49 -> V_51 ) ;
if ( error < 0 )
goto V_108;
error = F_59 ( V_38 , & V_39 ) ;
if ( error < 0 ) {
F_10 ( & V_102 -> V_2 ,
L_31 , error ) ;
goto V_108;
}
V_18 . V_21 = V_115 ;
strcpy ( V_18 . type , L_16 ) ;
V_18 . V_6 = V_39 ;
V_18 . V_23 = V_116 ;
V_18 . V_24 = V_117 ;
V_18 . V_64 = 0 ;
error = F_29 ( & V_18 , V_38 , & V_102 -> V_2 , & V_59 ) ;
if ( error < 0 )
goto V_108;
V_49 -> V_118 = V_59 ;
return 0 ;
V_108:
F_43 ( V_38 ) ;
return error ;
}
static int F_60 ( struct V_101 * V_102 )
{
struct V_48 * V_49 = F_61 ( V_102 ) ;
if ( F_4 ( & V_49 -> V_118 -> V_2 != V_14 . V_15 ) )
return - V_29 ;
F_39 ( V_49 -> V_118 ) ;
F_53 ( & V_102 -> V_2 , L_32 ) ;
return 0 ;
}
static int T_7 F_62 ( void )
{
int error ;
V_81 = F_63 ( L_33 ,
sizeof( struct V_7 ) , 0 , 0 ,
NULL ) ;
if ( ! V_81 ) {
F_15 ( L_34 ) ;
return - V_66 ;
}
error = F_64 ( & V_14 ) ;
if ( error < 0 ) {
F_15 ( L_35 , error ) ;
goto V_119;
}
F_16 ( L_36 ) ;
error = F_65 ( & V_120 ) ;
if ( error < 0 ) {
F_15 ( L_37 , error ) ;
goto V_121;
}
error = F_66 () ;
if ( error < 0 )
goto V_122;
error = F_67 () ;
if ( error < 0 )
goto V_123;
return 0 ;
V_123:
F_68 () ;
V_122:
F_69 ( & V_120 ) ;
V_121:
F_70 ( & V_14 ) ;
V_119:
F_71 ( V_81 ) ;
return error ;
}
static void T_8 F_72 ( void )
{
if ( F_4 ( ! V_81 ) )
return;
F_73 () ;
F_68 () ;
F_69 ( & V_120 ) ;
F_70 ( & V_14 ) ;
F_71 ( V_81 ) ;
F_16 ( L_38 ) ;
}
