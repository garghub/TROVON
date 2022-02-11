int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
bool V_5 ;
int V_6 = - V_7 ;
V_2 -> V_4 = F_2 ( sizeof( * V_2 -> V_4 ) , V_8 ) ;
if ( ! V_2 -> V_4 )
goto V_9;
V_4 = F_3 ( V_2 ) ;
V_4 -> V_2 = V_2 ;
#ifdef F_4
V_4 -> V_10 = ( char * ) F_5 ( V_8 ) ;
if ( ! V_4 -> V_10 )
goto V_11;
V_4 -> V_12 = V_13 ;
#endif
F_6 ( & V_4 -> V_14 ) ;
F_6 ( & V_4 -> V_15 ) ;
F_7 ( & V_4 -> V_16 ) ;
V_4 -> V_17 = V_18 ;
V_4 -> V_19 = V_20 ;
F_7 ( & V_4 -> V_21 ) ;
F_8 ( & V_4 -> V_22 ) ;
F_9 ( & V_4 -> V_23 , V_24 ,
( unsigned long ) V_4 ) ;
( void ) F_10 ( V_2 ) ;
V_4 -> V_25 = true ;
V_6 = F_11 ( V_2 ) ;
if ( V_6 )
goto V_26;
V_6 = F_12 ( V_2 , true , & V_5 ) ;
if ( V_6 ) {
F_13 ( V_2 , V_27 , V_2 -> V_28 ,
L_1 ) ;
goto V_26;
}
if ( V_5 )
F_13 ( V_2 , V_27 , V_2 -> V_28 ,
L_2 ) ;
if ( V_2 -> V_4 -> V_29 &
( 1 << V_30 ) )
V_2 -> V_31 = V_2 ;
return 0 ;
V_26:
#ifdef F_4
F_14 ( ( unsigned long ) V_4 -> V_10 ) ;
V_11:
#endif
F_15 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
V_9:
return V_6 ;
}
void F_16 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_4 )
return;
F_17 ( V_2 -> V_4 -> V_32 . V_17 != V_18 ) ;
F_12 ( V_2 , false , NULL ) ;
}
void F_18 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_4 )
return;
#ifdef F_4
F_14 ( ( unsigned long ) V_2 -> V_4 -> V_32 . V_10 ) ;
#endif
F_15 ( V_2 -> V_4 ) ;
}
static void F_19 ( struct V_1 * V_2 , unsigned V_33 ,
const T_1 * V_34 , T_2 V_35 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
#ifdef F_4
char * V_36 = V_4 -> V_10 ;
#endif
T_1 V_37 [ 2 ] ;
T_2 V_38 ;
T_3 V_39 , V_40 ;
F_17 ( V_4 -> V_17 == V_18 ) ;
F_20 ( & V_4 -> V_16 ) ;
++ V_4 -> V_40 ;
F_21 ( & V_4 -> V_16 ) ;
V_40 = V_4 -> V_40 & V_41 ;
V_39 = 0 ;
if ( V_4 -> V_19 == V_42 )
V_39 |= V_43 ;
if ( V_2 -> type -> V_44 == 1 ) {
F_22 ( V_37 [ 0 ] ,
V_45 , 0 ,
V_46 , 1 ,
V_47 , V_33 ,
V_48 , V_35 ,
V_49 , V_40 ,
V_50 , V_39 ,
V_51 , ! V_4 -> V_25 ) ;
V_38 = 4 ;
} else {
F_17 ( V_35 > V_52 ) ;
F_22 ( V_37 [ 0 ] ,
V_45 , 0 ,
V_46 , 1 ,
V_47 , V_53 ,
V_48 , 0 ,
V_49 , V_40 ,
V_50 , V_39 ,
V_51 , ! V_4 -> V_25 ) ;
F_23 ( V_37 [ 1 ] ,
V_54 , V_33 ,
V_55 , V_35 ) ;
V_38 = 8 ;
}
#ifdef F_4
if ( V_4 -> V_12 && ! F_24 ( ! V_36 ) ) {
int V_56 = 0 ;
int V_57 ;
F_24 ( V_38 % 4 ) ;
F_24 ( V_35 % 4 ) ;
for ( V_57 = 0 ; V_57 < V_38 / 4 && V_56 < V_58 ; V_57 ++ )
V_56 += snprintf ( V_36 + V_56 , V_58 - V_56 ,
L_3 , F_25 ( V_37 [ V_57 ] . T_3 [ 0 ] ) ) ;
for ( V_57 = 0 ; V_57 < V_35 / 4 && V_56 < V_58 ; V_57 ++ )
V_56 += snprintf ( V_36 + V_56 , V_58 - V_56 ,
L_3 , F_25 ( V_34 [ V_57 ] . T_3 [ 0 ] ) ) ;
F_26 ( V_2 , V_59 , V_2 -> V_28 , L_4 , V_36 ) ;
}
#endif
V_2 -> type -> V_60 ( V_2 , V_37 , V_38 , V_34 , V_35 ) ;
V_4 -> V_25 = false ;
}
static int F_27 ( unsigned int V_61 )
{
switch ( V_61 ) {
case 0 :
return 0 ;
#define F_28 ( T_4 ) \
case MC_CMD_ERR_ ## name: \
return -name;
F_28 ( V_62 ) ;
F_28 ( V_63 ) ;
F_28 ( V_64 ) ;
F_28 ( V_65 ) ;
F_28 ( V_66 ) ;
F_28 ( V_67 ) ;
F_28 ( V_68 ) ;
F_28 ( V_69 ) ;
F_28 ( V_70 ) ;
F_28 ( V_71 ) ;
F_28 ( V_72 ) ;
F_28 ( V_73 ) ;
#undef F_28
case V_74 :
return - V_75 ;
case V_76 :
return - V_77 ;
case V_78 :
return - V_79 ;
default:
return - V_80 ;
}
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
unsigned int V_81 , V_82 , error ;
#ifdef F_4
char * V_36 = V_4 -> V_10 ;
#endif
T_1 V_37 ;
V_2 -> type -> V_83 ( V_2 , & V_37 , 0 , 4 ) ;
V_81 = F_30 ( V_37 , V_49 ) ;
V_82 = F_30 ( V_37 , V_47 ) ;
error = F_30 ( V_37 , V_84 ) ;
if ( V_82 != V_53 ) {
V_4 -> V_85 = 4 ;
V_4 -> V_86 = F_30 ( V_37 , V_48 ) ;
} else {
V_2 -> type -> V_83 ( V_2 , & V_37 , 4 , 4 ) ;
V_4 -> V_85 = 8 ;
V_4 -> V_86 =
F_30 ( V_37 , V_55 ) ;
}
#ifdef F_4
if ( V_4 -> V_12 && ! F_24 ( ! V_36 ) ) {
T_2 V_38 , V_87 ;
int V_56 = 0 ;
int V_57 ;
F_24 ( V_4 -> V_85 % 4 ) ;
V_38 = V_4 -> V_85 / 4 ;
V_87 = F_31 ( V_4 -> V_86 , 4 ) ;
for ( V_57 = 0 ; V_57 < V_38 && V_56 < V_58 ; V_57 ++ ) {
V_2 -> type -> V_83 ( V_2 , & V_37 , ( V_57 * 4 ) , 4 ) ;
V_56 += snprintf ( V_36 + V_56 , V_58 - V_56 ,
L_3 , F_25 ( V_37 . T_3 [ 0 ] ) ) ;
}
for ( V_57 = 0 ; V_57 < V_87 && V_56 < V_58 ; V_57 ++ ) {
V_2 -> type -> V_83 ( V_2 , & V_37 ,
V_4 -> V_85 + ( V_57 * 4 ) , 4 ) ;
V_56 += snprintf ( V_36 + V_56 , V_58 - V_56 ,
L_3 , F_25 ( V_37 . T_3 [ 0 ] ) ) ;
}
F_26 ( V_2 , V_59 , V_2 -> V_28 , L_5 , V_36 ) ;
}
#endif
V_4 -> V_88 = 0 ;
if ( error && V_4 -> V_86 == 0 ) {
F_13 ( V_2 , V_59 , V_2 -> V_28 , L_6 ) ;
V_4 -> V_89 = - V_90 ;
} else if ( ( V_81 ^ V_4 -> V_40 ) & V_41 ) {
F_13 ( V_2 , V_59 , V_2 -> V_28 ,
L_7 ,
V_81 , V_4 -> V_40 ) ;
V_4 -> V_89 = - V_90 ;
} else if ( error ) {
V_2 -> type -> V_83 ( V_2 , & V_37 , V_4 -> V_85 , 4 ) ;
V_4 -> V_88 = F_30 ( V_37 , V_91 ) ;
V_4 -> V_89 = F_27 ( V_4 -> V_88 ) ;
} else {
V_4 -> V_89 = 0 ;
}
}
static bool F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
F_33 () ;
if ( ! V_2 -> type -> V_92 ( V_2 ) )
return false ;
F_20 ( & V_4 -> V_16 ) ;
F_29 ( V_2 ) ;
F_21 ( & V_4 -> V_16 ) ;
return true ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
unsigned long time , V_93 ;
unsigned int V_94 ;
int V_6 ;
V_6 = F_10 ( V_2 ) ;
if ( V_6 ) {
F_20 ( & V_4 -> V_16 ) ;
V_4 -> V_89 = V_6 ;
V_4 -> V_85 = 0 ;
V_4 -> V_86 = 0 ;
F_21 ( & V_4 -> V_16 ) ;
return 0 ;
}
V_94 = V_95 ;
V_93 = V_96 + V_97 ;
while ( 1 ) {
if ( V_94 != 0 ) {
-- V_94 ;
F_35 ( 1 ) ;
} else {
F_36 ( 1 ) ;
}
time = V_96 ;
if ( F_32 ( V_2 ) )
break;
if ( F_37 ( time , V_93 ) )
return - V_98 ;
}
return 0 ;
}
int F_10 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_4 )
return 0 ;
return V_2 -> type -> V_99 ( V_2 ) ;
}
static bool F_38 ( struct V_3 * V_4 )
{
return F_39 ( & V_4 -> V_17 ,
V_18 , V_100 ) ==
V_18 ;
}
static void F_40 ( struct V_3 * V_4 )
{
F_41 ( V_4 -> V_14 ,
F_39 ( & V_4 -> V_17 ,
V_18 , V_101 ) ==
V_18 ) ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
if ( F_43 ( V_4 -> V_14 , V_4 -> V_17 == V_102 ,
V_97 ) == 0 )
return - V_98 ;
if ( V_4 -> V_19 == V_20 )
return F_34 ( V_2 ) ;
return 0 ;
}
static bool F_44 ( struct V_3 * V_4 )
{
if ( F_39 ( & V_4 -> V_17 ,
V_101 , V_102 ) ==
V_101 ) {
F_45 ( & V_4 -> V_14 ) ;
return true ;
}
return false ;
}
static void F_46 ( struct V_3 * V_4 )
{
if ( V_4 -> V_19 == V_42 ) {
struct V_103 * V_104 ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_20 ( & V_4 -> V_21 ) ;
V_104 = F_47 (
& V_4 -> V_22 , struct V_103 , V_105 ) ;
if ( V_104 ) {
V_4 -> V_17 = V_100 ;
F_19 ( V_2 , V_104 -> V_33 ,
( const T_1 * ) ( V_104 + 1 ) ,
V_104 -> V_35 ) ;
F_48 ( & V_4 -> V_23 ,
V_96 + V_97 ) ;
}
F_21 ( & V_4 -> V_21 ) ;
if ( V_104 )
return;
}
V_4 -> V_17 = V_18 ;
F_45 ( & V_4 -> V_14 ) ;
}
static bool F_49 ( struct V_3 * V_4 , bool V_106 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_103 * V_104 ;
T_2 V_38 , V_87 , V_107 ;
T_1 * V_108 ;
F_50 ( V_109 ) ;
int V_6 ;
if ( F_39 ( & V_4 -> V_17 ,
V_100 , V_102 ) !=
V_100 )
return false ;
F_51 ( & V_4 -> V_16 ) ;
if ( V_106 ) {
++ V_4 -> V_40 ;
++ V_4 -> V_110 ;
V_6 = - V_98 ;
V_38 = 0 ;
V_87 = 0 ;
} else {
V_6 = V_4 -> V_89 ;
V_38 = V_4 -> V_85 ;
V_87 = V_4 -> V_86 ;
}
F_52 ( & V_4 -> V_16 ) ;
if ( ! V_106 )
F_53 ( & V_4 -> V_23 ) ;
F_51 ( & V_4 -> V_21 ) ;
V_104 = F_54 ( & V_4 -> V_22 ,
struct V_103 , V_105 ) ;
F_55 ( & V_104 -> V_105 ) ;
F_52 ( & V_4 -> V_21 ) ;
V_108 = ( T_1 * ) ( V_104 + 1 ) ;
V_2 -> type -> V_83 ( V_2 , V_108 , V_38 ,
F_56 ( V_104 -> V_111 , V_87 ) ) ;
if ( ! V_106 && V_6 && ! V_104 -> V_112 ) {
V_107 = F_56 ( sizeof( V_109 ) , V_87 ) ;
V_2 -> type -> V_83 ( V_2 , V_109 , V_38 ,
sizeof( V_109 ) ) ;
F_57 ( V_2 , V_104 -> V_33 , V_104 -> V_35 , V_109 ,
V_107 , V_6 ) ;
}
if ( V_104 -> V_113 )
V_104 -> V_113 ( V_2 , V_104 -> V_114 , V_6 , V_108 ,
F_56 ( V_104 -> V_111 , V_87 ) ) ;
F_15 ( V_104 ) ;
F_46 ( V_4 ) ;
return true ;
}
static void F_58 ( struct V_1 * V_2 , unsigned int V_40 ,
unsigned int V_115 , unsigned int V_61 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
bool V_116 = false ;
F_51 ( & V_4 -> V_16 ) ;
if ( ( V_40 ^ V_4 -> V_40 ) & V_41 ) {
if ( V_4 -> V_110 )
-- V_4 -> V_110 ;
else
F_13 ( V_2 , V_59 , V_2 -> V_28 ,
L_8
L_9 , V_40 , V_4 -> V_40 ) ;
} else {
if ( V_2 -> type -> V_44 >= 2 ) {
F_29 ( V_2 ) ;
} else {
V_4 -> V_89 = F_27 ( V_61 ) ;
V_4 -> V_85 = 4 ;
V_4 -> V_86 = V_115 ;
}
V_116 = true ;
}
F_52 ( & V_4 -> V_16 ) ;
if ( V_116 ) {
if ( ! F_49 ( V_4 , false ) )
( void ) F_44 ( V_4 ) ;
}
}
static void V_24 ( unsigned long V_117 )
{
struct V_3 * V_4 = (struct V_3 * ) V_117 ;
F_49 ( V_4 , true ) ;
}
static int
F_59 ( struct V_1 * V_2 , unsigned int V_33 , T_2 V_35 )
{
if ( V_2 -> type -> V_44 < 0 ||
( V_2 -> type -> V_44 < 2 &&
V_33 > V_118 ) )
return - V_68 ;
if ( V_35 > V_52 ||
( V_2 -> type -> V_44 < 2 &&
V_35 > V_119 ) )
return - V_120 ;
return 0 ;
}
static bool F_60 ( struct V_1 * V_2 ,
T_2 V_38 , T_2 V_87 ,
T_3 * V_121 )
{
F_50 ( V_122 ) ;
const T_2 V_123 = sizeof( V_122 ) ;
if ( ! V_121 || V_87 < V_123 )
return false ;
V_2 -> type -> V_83 ( V_2 , V_122 , V_38 , V_123 ) ;
if ( F_61 ( V_122 , V_124 ) == V_125 ) {
* V_121 = F_61 ( V_122 , V_126 ) ;
return true ;
}
return false ;
}
static int F_62 ( struct V_1 * V_2 , unsigned int V_33 ,
T_2 V_35 ,
T_1 * V_108 , T_2 V_111 ,
T_2 * V_127 , bool V_112 ,
T_3 * V_121 , int * V_128 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
F_50 ( V_109 ) ;
int V_6 ;
if ( V_4 -> V_19 == V_20 )
V_6 = F_34 ( V_2 ) ;
else
V_6 = F_42 ( V_2 ) ;
if ( V_6 != 0 ) {
F_13 ( V_2 , V_59 , V_2 -> V_28 ,
L_10 ,
V_33 , ( int ) V_35 , V_4 -> V_19 ) ;
if ( V_4 -> V_19 == V_42 && F_32 ( V_2 ) ) {
F_13 ( V_2 , V_59 , V_2 -> V_28 ,
L_11 ) ;
V_6 = 0 ;
}
F_63 ( V_2 ) ;
F_20 ( & V_4 -> V_16 ) ;
++ V_4 -> V_40 ;
++ V_4 -> V_110 ;
F_21 ( & V_4 -> V_16 ) ;
}
if ( V_121 )
* V_121 = 0 ;
if ( V_6 != 0 ) {
if ( V_127 )
* V_127 = 0 ;
} else {
T_2 V_38 , V_87 , V_107 ;
F_20 ( & V_4 -> V_16 ) ;
V_6 = V_4 -> V_89 ;
if ( V_128 )
* V_128 = V_4 -> V_88 ;
V_38 = V_4 -> V_85 ;
V_87 = V_4 -> V_86 ;
V_107 = F_56 ( sizeof( V_109 ) , V_87 ) ;
F_21 ( & V_4 -> V_16 ) ;
F_17 ( V_6 > 0 ) ;
V_2 -> type -> V_83 ( V_2 , V_108 , V_38 ,
F_56 ( V_111 , V_87 ) ) ;
if ( V_127 )
* V_127 = V_87 ;
V_2 -> type -> V_83 ( V_2 , V_109 , V_38 , V_107 ) ;
if ( V_33 == V_129 && V_6 == - V_90 ) {
} else if ( V_6 == - V_90 || V_6 == - V_64 ) {
F_13 ( V_2 , V_59 , V_2 -> V_28 , L_12 ) ;
F_64 ( V_2 , V_59 , V_2 -> V_28 , L_13 ,
V_33 , - V_6 ) ;
if ( V_2 -> type -> V_130 )
V_2 -> type -> V_130 ( V_2 ) ;
F_65 ( V_2 , V_131 ) ;
} else if ( V_121 && ( V_6 == - V_80 ) &&
F_60 ( V_2 , V_38 , V_87 ,
V_121 ) ) {
V_4 -> V_132 = 0 ;
V_4 -> V_133 = 0 ;
V_4 -> V_17 = V_134 ;
} else if ( V_6 && ! V_112 ) {
F_57 ( V_2 , V_33 , V_35 , V_109 , V_107 ,
V_6 ) ;
}
if ( V_6 == - V_90 || V_6 == - V_64 ) {
F_66 ( V_135 ) ;
F_10 ( V_2 ) ;
V_4 -> V_25 = true ;
}
}
if ( ! V_121 || ! * V_121 )
F_46 ( V_4 ) ;
return V_6 ;
}
static void F_67 ( struct V_3 * V_4 )
{
if ( V_4 -> V_17 == V_134 ) {
V_4 -> V_132 = - V_64 ;
F_45 ( & V_4 -> V_15 ) ;
}
}
static void F_68 ( struct V_1 * V_2 ,
T_3 V_136 , int V_137 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
F_69 ( V_4 -> V_17 != V_134 ) ;
V_4 -> V_132 = F_27 ( V_137 ) ;
F_70 () ;
V_4 -> V_133 = V_136 ;
F_45 ( & V_4 -> V_15 ) ;
}
static int F_71 ( struct V_1 * V_2 , T_3 V_136 , bool V_112 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
int V_6 ;
V_6 = F_43 ( V_4 -> V_15 ,
V_4 -> V_133 != 0 ||
V_4 -> V_132 == - V_64 ,
V_97 ) ;
if ( V_6 <= 0 ) {
F_64 ( V_2 , V_59 , V_2 -> V_28 ,
L_14 , V_136 ) ;
return - V_98 ;
} else if ( V_4 -> V_133 != V_136 ) {
F_72 ( V_2 , V_59 , V_2 -> V_28 ,
L_15 ,
V_4 -> V_133 , V_136 ) ;
return - V_68 ;
}
return V_4 -> V_132 ;
}
static int F_73 ( struct V_1 * V_2 , unsigned int V_33 ,
const T_1 * V_34 , T_2 V_35 ,
T_1 * V_108 , T_2 V_111 ,
T_2 * V_127 , bool V_112 , int * V_128 )
{
T_3 V_121 = 0 ;
int V_6 ;
if ( V_34 && V_35 && ( V_34 == V_108 ) ) {
F_69 ( 1 ) ;
return - V_68 ;
}
V_6 = F_74 ( V_2 , V_33 , V_34 , V_35 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_62 ( V_2 , V_33 , V_35 , V_108 , V_111 ,
V_127 , V_112 , & V_121 , V_128 ) ;
if ( V_121 ) {
struct V_3 * V_4 = F_3 ( V_2 ) ;
F_64 ( V_2 , V_59 , V_2 -> V_28 ,
L_16 ,
V_121 ) ;
V_6 = F_71 ( V_2 , V_121 , V_112 ) ;
if ( V_6 == 0 ) {
F_64 ( V_2 , V_59 , V_2 -> V_28 ,
L_17 , V_121 ) ;
V_4 -> V_17 = V_101 ;
F_19 ( V_2 , V_33 , V_34 , V_35 ) ;
V_6 = F_62 ( V_2 , V_33 , V_35 ,
V_108 , V_111 , V_127 ,
V_112 , NULL , V_128 ) ;
} else {
F_75 ( V_2 , V_59 , V_2 -> V_28 , V_6 == - V_62 , V_138 ,
L_18 ,
V_33 , V_6 ) ;
if ( V_6 == - V_64 || V_6 == - V_90 )
F_65 ( V_2 , V_131 ) ;
F_46 ( V_4 ) ;
}
}
return V_6 ;
}
static int F_76 ( struct V_1 * V_2 , unsigned V_33 ,
const T_1 * V_34 , T_2 V_35 ,
T_1 * V_108 , T_2 V_111 ,
T_2 * V_127 , bool V_112 )
{
int V_128 = 0 ;
int V_6 ;
V_6 = F_73 ( V_2 , V_33 , V_34 , V_35 ,
V_108 , V_111 , V_127 , true , & V_128 ) ;
if ( ( V_6 == - V_80 ) && ( V_128 == V_139 ) &&
V_2 -> type -> V_140 ) {
unsigned long V_141 = V_96 + V_97 ;
unsigned int V_142 = 10000 ;
F_64 ( V_2 , V_59 , V_2 -> V_28 ,
L_19 ,
V_143 ) ;
do {
F_77 ( V_142 , V_142 + 10000 ) ;
V_6 = F_73 ( V_2 , V_33 , V_34 , V_35 ,
V_108 , V_111 , V_127 ,
true , & V_128 ) ;
if ( V_142 < 100000 )
V_142 <<= 1 ;
} while ( ( V_6 == - V_80 ) &&
( V_128 == V_139 ) &&
F_78 ( V_96 , V_141 ) );
}
if ( V_6 && ! V_112 && ! ( V_33 == V_129 && V_6 == - V_90 ) )
F_57 ( V_2 , V_33 , V_35 ,
V_108 , V_111 , V_6 ) ;
return V_6 ;
}
int F_79 ( struct V_1 * V_2 , unsigned V_33 ,
const T_1 * V_34 , T_2 V_35 ,
T_1 * V_108 , T_2 V_111 ,
T_2 * V_127 )
{
return F_76 ( V_2 , V_33 , V_34 , V_35 , V_108 , V_111 ,
V_127 , false ) ;
}
int F_80 ( struct V_1 * V_2 , unsigned V_33 ,
const T_1 * V_34 , T_2 V_35 ,
T_1 * V_108 , T_2 V_111 ,
T_2 * V_127 )
{
return F_76 ( V_2 , V_33 , V_34 , V_35 , V_108 , V_111 ,
V_127 , true ) ;
}
int F_74 ( struct V_1 * V_2 , unsigned V_33 ,
const T_1 * V_34 , T_2 V_35 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
int V_6 ;
V_6 = F_59 ( V_2 , V_33 , V_35 ) ;
if ( V_6 )
return V_6 ;
if ( V_2 -> V_144 )
return - V_145 ;
if ( V_4 -> V_19 == V_146 )
return - V_145 ;
F_40 ( V_4 ) ;
F_19 ( V_2 , V_33 , V_34 , V_35 ) ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 , unsigned int V_33 ,
const T_1 * V_34 , T_2 V_35 ,
T_2 V_111 ,
T_5 * V_113 ,
unsigned long V_114 , bool V_112 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
struct V_103 * V_104 ;
int V_6 ;
V_6 = F_59 ( V_2 , V_33 , V_35 ) ;
if ( V_6 )
return V_6 ;
if ( V_2 -> V_144 )
return - V_145 ;
V_104 = F_82 ( sizeof( * V_104 ) + F_83 ( F_84 ( V_35 , V_111 ) , 4 ) ,
V_147 ) ;
if ( ! V_104 )
return - V_7 ;
V_104 -> V_33 = V_33 ;
V_104 -> V_35 = V_35 ;
V_104 -> V_111 = V_111 ;
V_104 -> V_112 = V_112 ;
V_104 -> V_113 = V_113 ;
V_104 -> V_114 = V_114 ;
memcpy ( V_104 + 1 , V_34 , V_35 ) ;
F_20 ( & V_4 -> V_21 ) ;
if ( V_4 -> V_19 == V_42 ) {
F_85 ( & V_104 -> V_105 , & V_4 -> V_22 ) ;
if ( V_4 -> V_22 . V_148 == & V_104 -> V_105 &&
F_38 ( V_4 ) ) {
F_19 ( V_2 , V_33 , V_34 , V_35 ) ;
F_48 ( & V_4 -> V_23 ,
V_96 + V_97 ) ;
}
} else {
F_15 ( V_104 ) ;
V_6 = - V_145 ;
}
F_21 ( & V_4 -> V_21 ) ;
return V_6 ;
}
int
F_86 ( struct V_1 * V_2 , unsigned int V_33 ,
const T_1 * V_34 , T_2 V_35 , T_2 V_111 ,
T_5 * V_113 , unsigned long V_114 )
{
return F_81 ( V_2 , V_33 , V_34 , V_35 , V_111 , V_113 ,
V_114 , false ) ;
}
int F_87 ( struct V_1 * V_2 , unsigned int V_33 ,
const T_1 * V_34 , T_2 V_35 ,
T_2 V_111 , T_5 * V_113 ,
unsigned long V_114 )
{
return F_81 ( V_2 , V_33 , V_34 , V_35 , V_111 , V_113 ,
V_114 , true ) ;
}
int F_88 ( struct V_1 * V_2 , unsigned V_33 , T_2 V_35 ,
T_1 * V_108 , T_2 V_111 ,
T_2 * V_127 )
{
return F_62 ( V_2 , V_33 , V_35 , V_108 , V_111 ,
V_127 , false , NULL , NULL ) ;
}
int F_89 ( struct V_1 * V_2 , unsigned V_33 , T_2 V_35 ,
T_1 * V_108 , T_2 V_111 ,
T_2 * V_127 )
{
return F_62 ( V_2 , V_33 , V_35 , V_108 , V_111 ,
V_127 , true , NULL , NULL ) ;
}
void F_57 ( struct V_1 * V_2 , unsigned V_33 ,
T_2 V_35 , T_1 * V_108 ,
T_2 V_111 , int V_6 )
{
int V_149 = 0 , V_150 = 0 ;
if ( V_111 >= V_151 + 4 )
V_149 = F_61 ( V_108 , V_124 ) ;
if ( V_111 >= V_152 + 4 )
V_150 = F_61 ( V_108 , V_153 ) ;
F_75 ( V_2 , V_59 , V_2 -> V_28 , V_6 == - V_62 , V_138 ,
L_20 ,
V_33 , V_35 , V_6 , V_149 , V_150 ) ;
}
void F_90 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( ! V_2 -> V_4 )
return;
V_4 = F_3 ( V_2 ) ;
if ( V_4 -> V_19 == V_20 || V_4 -> V_19 == V_146 )
return;
V_4 -> V_19 = V_20 ;
F_44 ( V_4 ) ;
}
void F_91 ( struct V_1 * V_2 )
{
struct V_103 * V_104 , * V_148 ;
struct V_3 * V_4 ;
if ( ! V_2 -> V_4 )
return;
V_4 = F_3 ( V_2 ) ;
F_17 ( V_4 -> V_19 == V_42 ) ;
F_53 ( & V_4 -> V_23 ) ;
if ( V_4 -> V_17 == V_100 ) {
F_34 ( V_2 ) ;
V_4 -> V_17 = V_18 ;
}
F_92 (async, next, &mcdi->async_list, list) {
if ( V_104 -> V_113 )
V_104 -> V_113 ( V_2 , V_104 -> V_114 , - V_145 , NULL , 0 ) ;
F_55 ( & V_104 -> V_105 ) ;
F_15 ( V_104 ) ;
}
}
void F_93 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( ! V_2 -> V_4 )
return;
V_4 = F_3 ( V_2 ) ;
if ( V_4 -> V_19 == V_42 || V_4 -> V_19 == V_146 )
return;
F_40 ( V_4 ) ;
V_4 -> V_19 = V_42 ;
F_46 ( V_4 ) ;
}
static void F_94 ( struct V_1 * V_2 , int V_6 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
F_51 ( & V_4 -> V_16 ) ;
F_67 ( V_4 ) ;
if ( F_44 ( V_4 ) ) {
if ( V_4 -> V_19 == V_42 ) {
V_4 -> V_89 = V_6 ;
V_4 -> V_85 = 0 ;
V_4 -> V_86 = 0 ;
++ V_4 -> V_110 ;
}
} else {
int V_154 ;
for ( V_154 = 0 ; V_154 < V_155 ; ++ V_154 ) {
V_6 = F_10 ( V_2 ) ;
if ( V_6 )
break;
F_35 ( V_156 ) ;
}
if ( ! V_6 && V_2 -> type -> V_130 )
V_2 -> type -> V_130 ( V_2 ) ;
V_4 -> V_25 = true ;
F_65 ( V_2 , V_131 ) ;
}
F_52 ( & V_4 -> V_16 ) ;
}
static void F_95 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
F_51 ( & V_4 -> V_16 ) ;
V_2 -> V_144 = true ;
F_67 ( V_4 ) ;
if ( F_44 ( V_4 ) ) {
if ( V_4 -> V_19 == V_42 ) {
V_4 -> V_89 = - V_90 ;
V_4 -> V_85 = 0 ;
V_4 -> V_86 = 0 ;
++ V_4 -> V_110 ;
}
}
V_4 -> V_25 = true ;
F_65 ( V_2 , V_157 ) ;
F_52 ( & V_4 -> V_16 ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
if ( F_96 ( & V_4 -> V_19 , V_146 ) == V_146 )
return;
F_64 ( V_2 , V_59 , V_2 -> V_28 , L_21 ) ;
F_65 ( V_2 , V_158 ) ;
}
void F_97 ( struct V_159 * V_160 ,
T_6 * V_161 )
{
struct V_1 * V_2 = V_160 -> V_2 ;
int V_149 = F_98 ( * V_161 , V_162 ) ;
T_3 V_163 = F_98 ( * V_161 , V_164 ) ;
switch ( V_149 ) {
case V_165 :
F_13 ( V_2 , V_59 , V_2 -> V_28 ,
L_22 , V_163 ) ;
F_94 ( V_2 , - V_64 ) ;
break;
case V_166 :
F_26 ( V_2 , V_167 , V_2 -> V_28 , L_23 ) ;
break;
case V_168 :
F_58 ( V_2 ,
F_99 ( * V_161 , V_169 ) ,
F_99 ( * V_161 , V_170 ) ,
F_99 ( * V_161 , V_171 ) ) ;
break;
case V_172 :
F_100 ( V_2 , V_161 ) ;
break;
case V_173 :
F_101 ( V_2 , V_161 ) ;
break;
case V_174 :
F_64 ( V_2 , V_59 , V_2 -> V_28 ,
L_24 , V_163 ) ;
break;
case V_175 :
case V_176 :
F_26 ( V_2 , V_59 , V_2 -> V_28 , L_25 ) ;
F_94 ( V_2 , - V_90 ) ;
break;
case V_177 :
F_26 ( V_2 , V_59 , V_2 -> V_28 , L_26 ) ;
F_95 ( V_2 ) ;
break;
case V_178 :
break;
case V_179 :
if ( V_2 -> type -> V_180 )
V_2 -> type -> V_180 ( V_2 ,
F_99 ( * V_161 , V_181 ) ) ;
break;
case V_182 :
case V_183 :
case V_184 :
F_102 ( V_2 , V_161 ) ;
break;
case V_185 :
F_103 ( V_160 , V_161 ) ;
break;
case V_186 :
case V_187 :
F_104 ( V_188 !=
V_189 ) ;
if ( ! F_99 ( * V_161 , V_190 ) )
F_105 ( V_2 ) ;
break;
case V_191 :
case V_192 :
F_13 ( V_2 , V_59 , V_2 -> V_28 ,
L_27 V_193 L_28 ,
V_149 == V_191 ? L_29 : L_30 ,
F_106 ( * V_161 ) ) ;
F_65 ( V_2 , V_194 ) ;
break;
case V_195 :
F_68 ( V_2 ,
F_99 ( * V_161 , V_196 ) ,
F_99 ( * V_161 , V_197 ) ) ;
break;
default:
F_13 ( V_2 , V_59 , V_2 -> V_28 , L_31 ,
V_149 ) ;
}
}
void F_107 ( struct V_1 * V_2 , char * V_36 , T_2 V_198 )
{
F_108 ( V_108 , V_199 ) ;
T_2 V_200 ;
const T_7 * V_201 ;
T_2 V_202 ;
int V_6 ;
F_104 ( V_203 != 0 ) ;
V_6 = F_79 ( V_2 , V_204 , NULL , 0 ,
V_108 , sizeof( V_108 ) , & V_200 ) ;
if ( V_6 )
goto V_9;
if ( V_200 < V_199 ) {
V_6 = - V_90 ;
goto V_9;
}
V_201 = ( T_7 * ) F_109 ( V_108 , V_205 ) ;
V_202 = snprintf ( V_36 , V_198 , L_32 ,
F_110 ( V_201 [ 0 ] ) , F_110 ( V_201 [ 1 ] ) ,
F_110 ( V_201 [ 2 ] ) , F_110 ( V_201 [ 3 ] ) ) ;
if ( F_111 ( V_2 ) >= V_206 ) {
struct V_207 * V_208 = V_2 -> V_208 ;
V_202 += snprintf ( V_36 + V_202 , V_198 - V_202 , L_33 ,
V_208 -> V_209 ,
V_208 -> V_210 ) ;
if ( F_69 ( V_202 >= V_198 ) )
V_36 [ 0 ] = 0 ;
}
return;
V_9:
F_13 ( V_2 , V_27 , V_2 -> V_28 , L_34 , V_143 , V_6 ) ;
V_36 [ 0 ] = 0 ;
}
static int F_12 ( struct V_1 * V_2 , bool V_211 ,
bool * V_212 )
{
F_108 ( V_34 , V_213 ) ;
F_108 ( V_108 , V_214 ) ;
T_2 V_111 ;
int V_6 ;
F_112 ( V_34 , V_215 ,
V_211 ? 1 : 0 ) ;
F_112 ( V_34 , V_216 , 1 ) ;
F_112 ( V_34 , V_217 , V_218 ) ;
V_6 = F_80 ( V_2 , V_219 , V_34 , sizeof( V_34 ) ,
V_108 , sizeof( V_108 ) , & V_111 ) ;
if ( V_6 == - V_62 ) {
F_64 ( V_2 , V_27 , V_2 -> V_28 ,
L_35 ) ;
F_112 ( V_34 , V_217 ,
V_220 ) ;
V_6 = F_80 ( V_2 , V_219 , V_34 ,
sizeof( V_34 ) , V_108 , sizeof( V_108 ) ,
& V_111 ) ;
}
if ( V_6 ) {
F_57 ( V_2 , V_219 , sizeof( V_34 ) ,
V_108 , V_111 , V_6 ) ;
goto V_9;
}
if ( V_111 < V_221 ) {
V_6 = - V_90 ;
goto V_9;
}
if ( V_211 ) {
if ( V_111 >= V_214 ) {
V_2 -> V_4 -> V_29 =
F_61 ( V_108 ,
V_222 ) ;
} else {
V_2 -> V_4 -> V_29 =
1 << V_223 |
1 << V_224 |
( F_113 ( V_2 ) == 0 ) <<
V_30 ;
}
}
if ( V_212 != NULL )
* V_212 = F_61 ( V_108 , V_225 ) ;
return 0 ;
V_9:
F_13 ( V_2 , V_27 , V_2 -> V_28 , L_34 , V_143 , V_6 ) ;
return V_6 ;
}
int F_114 ( struct V_1 * V_2 , T_8 * V_226 ,
T_9 * V_227 , T_3 * V_228 )
{
F_108 ( V_108 , V_229 ) ;
T_2 V_111 , V_57 ;
int V_230 = F_113 ( V_2 ) ;
int V_6 ;
F_104 ( V_231 != 0 ) ;
F_104 ( V_232 & 1 ) ;
F_104 ( V_233 & 1 ) ;
V_6 = F_79 ( V_2 , V_234 , NULL , 0 ,
V_108 , sizeof( V_108 ) , & V_111 ) ;
if ( V_6 )
goto V_9;
if ( V_111 < V_235 ) {
V_6 = - V_90 ;
goto V_9;
}
if ( V_226 )
F_115 ( V_226 ,
V_230 ?
F_109 ( V_108 , V_236 ) :
F_109 ( V_108 , V_237 ) ) ;
if ( V_227 ) {
for ( V_57 = 0 ;
V_57 < F_116 ( V_111 ,
V_238 ) ;
V_57 ++ )
V_227 [ V_57 ] = F_117 (
V_108 , V_238 , V_57 ) ;
for (; V_57 < V_239 ; V_57 ++ )
V_227 [ V_57 ] = 0 ;
}
if ( V_228 ) {
if ( V_230 )
* V_228 = F_61 ( V_108 ,
V_240 ) ;
else
* V_228 = F_61 ( V_108 ,
V_241 ) ;
}
return 0 ;
V_9:
F_13 ( V_2 , V_59 , V_2 -> V_28 , L_36 ,
V_143 , V_6 , ( int ) V_111 ) ;
return V_6 ;
}
int F_118 ( struct V_1 * V_2 , bool V_242 , bool V_243 , T_3 V_244 )
{
F_108 ( V_34 , V_245 ) ;
T_3 V_246 = 0 ;
int V_6 ;
if ( V_243 )
V_246 |= V_247 ;
if ( V_242 )
V_246 |= V_248 ;
F_112 ( V_34 , V_249 , V_246 ) ;
F_112 ( V_34 , V_250 , V_244 ) ;
F_104 ( V_251 != 0 ) ;
V_6 = F_79 ( V_2 , V_252 , V_34 , sizeof( V_34 ) ,
NULL , 0 , NULL ) ;
return V_6 ;
}
int F_119 ( struct V_1 * V_2 , T_3 * V_253 )
{
F_108 ( V_108 , V_254 ) ;
T_2 V_111 ;
int V_6 ;
F_104 ( V_255 != 0 ) ;
V_6 = F_79 ( V_2 , V_256 , NULL , 0 ,
V_108 , sizeof( V_108 ) , & V_111 ) ;
if ( V_6 )
goto V_9;
if ( V_111 < V_254 ) {
V_6 = - V_90 ;
goto V_9;
}
* V_253 = F_61 ( V_108 , V_257 ) ;
return 0 ;
V_9:
F_13 ( V_2 , V_59 , V_2 -> V_28 , L_34 ,
V_143 , V_6 ) ;
return V_6 ;
}
int F_120 ( struct V_1 * V_2 , unsigned int type ,
T_2 * V_258 , T_2 * V_259 ,
bool * V_260 )
{
F_108 ( V_34 , V_261 ) ;
F_108 ( V_108 , V_262 ) ;
T_2 V_111 ;
int V_6 ;
F_112 ( V_34 , V_263 , type ) ;
V_6 = F_79 ( V_2 , V_264 , V_34 , sizeof( V_34 ) ,
V_108 , sizeof( V_108 ) , & V_111 ) ;
if ( V_6 )
goto V_9;
if ( V_111 < V_262 ) {
V_6 = - V_90 ;
goto V_9;
}
* V_258 = F_61 ( V_108 , V_265 ) ;
* V_259 = F_61 ( V_108 , V_266 ) ;
* V_260 = ! ! ( F_61 ( V_108 , V_267 ) &
( 1 << V_268 ) ) ;
return 0 ;
V_9:
F_13 ( V_2 , V_59 , V_2 -> V_28 , L_34 , V_143 , V_6 ) ;
return V_6 ;
}
static int F_121 ( struct V_1 * V_2 , unsigned int type )
{
F_108 ( V_34 , V_269 ) ;
F_108 ( V_108 , V_270 ) ;
int V_6 ;
F_112 ( V_34 , V_271 , type ) ;
V_6 = F_79 ( V_2 , V_272 , V_34 , sizeof( V_34 ) ,
V_108 , sizeof( V_108 ) , NULL ) ;
if ( V_6 )
return V_6 ;
switch ( F_61 ( V_108 , V_273 ) ) {
case V_274 :
case V_275 :
return 0 ;
default:
return - V_90 ;
}
}
int F_122 ( struct V_1 * V_2 )
{
T_3 V_276 ;
unsigned int type ;
int V_6 ;
V_6 = F_119 ( V_2 , & V_276 ) ;
if ( V_6 )
goto V_11;
type = 0 ;
while ( V_276 != 0 ) {
if ( V_276 & 1 ) {
V_6 = F_121 ( V_2 , type ) ;
if ( V_6 )
goto V_26;
}
type ++ ;
V_276 >>= 1 ;
}
return 0 ;
V_26:
F_13 ( V_2 , V_59 , V_2 -> V_28 , L_37 ,
V_143 , type ) ;
V_11:
F_13 ( V_2 , V_59 , V_2 -> V_28 , L_34 , V_143 , V_6 ) ;
return V_6 ;
}
static int F_123 ( struct V_1 * V_2 )
{
F_108 ( V_34 , V_277 ) ;
F_108 ( V_108 , V_278 ) ;
unsigned int V_279 , V_280 ;
const char * V_281 ;
T_2 V_111 ;
int V_282 ;
int V_6 ;
V_282 = 2 ;
do {
F_112 ( V_34 , V_283 , 1 ) ;
V_6 = F_80 ( V_2 , V_284 ,
V_34 , V_277 ,
V_108 , sizeof( V_108 ) , & V_111 ) ;
if ( V_6 == - V_62 )
return 0 ;
} while ( ( V_6 == - V_64 || V_6 == - V_90 ) && V_282 -- > 0 );
if ( V_6 ) {
F_57 ( V_2 , V_284 ,
V_277 , V_108 ,
V_111 , V_6 ) ;
return V_6 ;
}
if ( V_111 < V_278 )
return - V_90 ;
V_279 = F_61 ( V_108 , V_285 ) ;
if ( V_279 == V_286 )
return 0 ;
V_281 = ( V_279 == V_287 )
? L_38
: ( V_279 == V_288 )
? L_39
: ( V_279 == V_289 )
? L_40
: L_41 ;
F_13 ( V_2 , V_59 , V_2 -> V_28 ,
L_42 , V_281 ,
F_61 ( V_108 , V_290 ) ,
F_61 ( V_108 , V_291 ) ) ;
for ( V_280 = 0 ;
V_280 < V_292 ;
V_280 ++ )
F_13 ( V_2 , V_59 , V_2 -> V_28 , L_43 ,
1 + V_280 ,
F_124 ( V_108 , V_293 ,
V_280 ) ) ;
return 1 ;
}
static int F_125 ( struct V_1 * V_2 )
{
F_108 ( V_34 , V_294 ) ;
int V_6 ;
F_104 ( V_295 != 0 ) ;
F_112 ( V_34 , V_296 ,
V_297 ) ;
V_6 = F_80 ( V_2 , V_129 , V_34 , V_294 ,
NULL , 0 , NULL ) ;
if ( V_6 == - V_90 )
V_6 = 0 ;
if ( V_6 )
F_57 ( V_2 , V_129 , V_294 ,
NULL , 0 , V_6 ) ;
return V_6 ;
}
int F_11 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_123 ( V_2 ) ;
if ( V_6 <= 0 )
return V_6 ;
return F_125 ( V_2 ) ;
}
void F_126 ( struct V_1 * V_2 , enum V_298 V_19 )
{
F_108 ( V_34 , V_299 ) ;
int V_6 ;
F_104 ( V_300 != V_301 ) ;
F_104 ( V_302 != V_303 ) ;
F_104 ( V_304 != V_305 ) ;
F_104 ( V_306 != 0 ) ;
F_112 ( V_34 , V_307 , V_19 ) ;
V_6 = F_79 ( V_2 , V_308 , V_34 , sizeof( V_34 ) ,
NULL , 0 , NULL ) ;
}
static int F_127 ( struct V_1 * V_2 )
{
F_108 ( V_34 , V_309 ) ;
int V_6 ;
F_104 ( V_310 != 0 ) ;
F_128 ( V_34 , V_311 ,
V_312 , 1 ) ;
V_6 = F_79 ( V_2 , V_313 , V_34 , sizeof( V_34 ) ,
NULL , 0 , NULL ) ;
return V_6 ;
}
static int F_129 ( struct V_1 * V_2 )
{
F_108 ( V_34 , V_294 ) ;
int V_6 ;
F_104 ( V_295 != 0 ) ;
F_112 ( V_34 , V_296 , 0 ) ;
V_6 = F_79 ( V_2 , V_129 , V_34 , sizeof( V_34 ) ,
NULL , 0 , NULL ) ;
if ( V_6 == - V_90 )
return 0 ;
if ( V_6 == 0 )
V_6 = - V_90 ;
return V_6 ;
}
enum V_314 F_130 ( enum V_314 V_281 )
{
return V_315 ;
}
int F_131 ( struct V_1 * V_2 , enum V_314 V_316 )
{
int V_6 ;
if ( V_316 == V_158 ) {
V_6 = F_132 ( V_2 -> V_317 ) ;
if ( V_6 )
return V_6 ;
if ( V_2 -> V_4 ) {
struct V_3 * V_4 = F_3 ( V_2 ) ;
V_4 -> V_19 = V_20 ;
}
return 0 ;
}
V_6 = F_11 ( V_2 ) ;
if ( V_6 )
return V_6 ;
if ( V_316 == V_318 )
return 0 ;
else if ( V_316 == V_319 )
return F_129 ( V_2 ) ;
else
return F_127 ( V_2 ) ;
}
static int F_133 ( struct V_1 * V_2 , T_3 type ,
const T_8 * V_320 , int * V_321 )
{
F_108 ( V_34 , V_322 ) ;
F_108 ( V_108 , V_323 ) ;
T_2 V_111 ;
int V_6 ;
F_112 ( V_34 , V_324 , type ) ;
F_112 ( V_34 , V_325 ,
V_326 ) ;
F_115 ( F_109 ( V_34 , V_327 ) , V_320 ) ;
V_6 = F_79 ( V_2 , V_328 , V_34 , sizeof( V_34 ) ,
V_108 , sizeof( V_108 ) , & V_111 ) ;
if ( V_6 )
goto V_9;
if ( V_111 < V_323 ) {
V_6 = - V_90 ;
goto V_9;
}
* V_321 = ( int ) F_61 ( V_108 , V_329 ) ;
return 0 ;
V_9:
* V_321 = - 1 ;
F_13 ( V_2 , V_59 , V_2 -> V_28 , L_34 , V_143 , V_6 ) ;
return V_6 ;
}
int
F_134 ( struct V_1 * V_2 , const T_8 * V_320 , int * V_321 )
{
return F_133 ( V_2 , V_330 , V_320 , V_321 ) ;
}
int F_135 ( struct V_1 * V_2 , int * V_321 )
{
F_108 ( V_108 , V_331 ) ;
T_2 V_111 ;
int V_6 ;
V_6 = F_79 ( V_2 , V_332 , NULL , 0 ,
V_108 , sizeof( V_108 ) , & V_111 ) ;
if ( V_6 )
goto V_9;
if ( V_111 < V_331 ) {
V_6 = - V_90 ;
goto V_9;
}
* V_321 = ( int ) F_61 ( V_108 , V_333 ) ;
return 0 ;
V_9:
* V_321 = - 1 ;
F_13 ( V_2 , V_59 , V_2 -> V_28 , L_34 , V_143 , V_6 ) ;
return V_6 ;
}
int F_136 ( struct V_1 * V_2 , int V_334 )
{
F_108 ( V_34 , V_335 ) ;
int V_6 ;
F_112 ( V_34 , V_336 , ( T_3 ) V_334 ) ;
V_6 = F_79 ( V_2 , V_337 , V_34 , sizeof( V_34 ) ,
NULL , 0 , NULL ) ;
return V_6 ;
}
int F_137 ( struct V_1 * V_2 )
{
struct V_159 * V_160 ;
struct V_338 * V_339 ;
F_108 ( V_34 ,
F_138 ( V_340 ) ) ;
int V_6 , V_154 ;
F_104 ( V_340 >
V_341 ) ;
V_154 = 0 ;
F_139 (channel, efx) {
F_140 (rx_queue, channel) {
if ( V_339 -> V_342 ) {
V_339 -> V_342 = false ;
F_141 ( & V_2 -> V_343 ) ;
F_142 (
V_34 , V_344 ,
V_154 , F_143 ( V_339 ) ) ;
V_154 ++ ;
}
}
}
V_6 = F_79 ( V_2 , V_345 , V_34 ,
F_138 ( V_154 ) , NULL , 0 , NULL ) ;
F_69 ( V_6 < 0 ) ;
return V_6 ;
}
int F_144 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_79 ( V_2 , V_346 , NULL , 0 , NULL , 0 , NULL ) ;
return V_6 ;
}
int F_145 ( struct V_1 * V_2 , T_3 type , bool V_347 ,
unsigned int * V_279 )
{
F_108 ( V_34 , V_348 ) ;
F_108 ( V_108 , V_349 ) ;
T_2 V_111 ;
int V_6 ;
F_104 ( V_350 != 0 ) ;
F_112 ( V_34 , V_351 , type ) ;
F_112 ( V_34 , V_352 , V_347 ) ;
V_6 = F_79 ( V_2 , V_353 , V_34 , sizeof( V_34 ) ,
V_108 , sizeof( V_108 ) , & V_111 ) ;
if ( V_6 )
return V_6 ;
if ( ! V_279 )
return 0 ;
if ( V_111 >= V_349 )
* V_279 = F_61 ( V_108 , V_354 ) ;
else
* V_279 = 0 ;
return 0 ;
}
int F_146 ( struct V_1 * V_2 , unsigned int * V_355 ,
unsigned int * V_356 )
{
F_108 ( V_108 , V_357 ) ;
T_2 V_111 ;
int V_6 ;
V_6 = F_79 ( V_2 , V_358 , NULL , 0 ,
V_108 , sizeof( V_108 ) , & V_111 ) ;
if ( V_6 )
goto V_9;
if ( V_111 < V_357 ) {
V_6 = - V_90 ;
goto V_9;
}
if ( V_355 )
* V_355 = F_61 ( V_108 , V_359 ) ;
if ( V_356 )
* V_356 = F_61 ( V_108 , V_360 ) ;
return 0 ;
V_9:
F_75 ( V_2 , V_59 , V_2 -> V_28 , V_6 == - V_70 , V_138 ,
L_34 , V_143 , V_6 ) ;
return V_6 ;
}
static int F_147 ( struct V_1 * V_2 , unsigned int type )
{
F_108 ( V_34 , V_361 ) ;
int V_6 ;
F_112 ( V_34 , V_362 , type ) ;
F_104 ( V_363 != 0 ) ;
V_6 = F_79 ( V_2 , V_364 , V_34 , sizeof( V_34 ) ,
NULL , 0 , NULL ) ;
return V_6 ;
}
static int F_148 ( struct V_1 * V_2 , unsigned int type ,
T_10 V_202 , T_8 * V_365 , T_2 V_366 )
{
F_108 ( V_34 , V_367 ) ;
F_108 ( V_108 ,
F_149 ( V_368 ) ) ;
T_2 V_111 ;
int V_6 ;
F_112 ( V_34 , V_369 , type ) ;
F_112 ( V_34 , V_370 , V_202 ) ;
F_112 ( V_34 , V_371 , V_366 ) ;
V_6 = F_79 ( V_2 , V_372 , V_34 , sizeof( V_34 ) ,
V_108 , sizeof( V_108 ) , & V_111 ) ;
if ( V_6 )
return V_6 ;
memcpy ( V_365 , F_109 ( V_108 , V_373 ) , V_366 ) ;
return 0 ;
}
static int F_150 ( struct V_1 * V_2 , unsigned int type ,
T_10 V_202 , const T_8 * V_365 , T_2 V_366 )
{
F_108 ( V_34 ,
F_151 ( V_368 ) ) ;
int V_6 ;
F_112 ( V_34 , V_374 , type ) ;
F_112 ( V_34 , V_375 , V_202 ) ;
F_112 ( V_34 , V_376 , V_366 ) ;
memcpy ( F_109 ( V_34 , V_377 ) , V_365 , V_366 ) ;
F_104 ( V_378 != 0 ) ;
V_6 = F_79 ( V_2 , V_379 , V_34 ,
F_83 ( F_151 ( V_366 ) , 4 ) ,
NULL , 0 , NULL ) ;
return V_6 ;
}
static int F_152 ( struct V_1 * V_2 , unsigned int type ,
T_10 V_202 , T_2 V_366 )
{
F_108 ( V_34 , V_380 ) ;
int V_6 ;
F_112 ( V_34 , V_381 , type ) ;
F_112 ( V_34 , V_382 , V_202 ) ;
F_112 ( V_34 , V_383 , V_366 ) ;
F_104 ( V_384 != 0 ) ;
V_6 = F_79 ( V_2 , V_385 , V_34 , sizeof( V_34 ) ,
NULL , 0 , NULL ) ;
return V_6 ;
}
static int F_153 ( struct V_1 * V_2 , unsigned int type )
{
F_108 ( V_34 , V_386 ) ;
int V_6 ;
F_112 ( V_34 , V_387 , type ) ;
F_104 ( V_388 != 0 ) ;
V_6 = F_79 ( V_2 , V_389 , V_34 , sizeof( V_34 ) ,
NULL , 0 , NULL ) ;
return V_6 ;
}
int F_154 ( struct V_390 * V_391 , T_10 V_392 ,
T_2 V_198 , T_2 * V_393 , T_8 * V_365 )
{
struct V_394 * V_395 = F_155 ( V_391 ) ;
struct V_1 * V_2 = V_391 -> V_396 ;
T_10 V_202 = V_392 ;
T_10 V_397 = F_156 ( T_10 , V_392 + V_198 , V_391 -> V_398 ) ;
T_2 V_399 ;
int V_6 = 0 ;
while ( V_202 < V_397 ) {
V_399 = F_156 ( T_2 , V_397 - V_202 , V_368 ) ;
V_6 = F_148 ( V_2 , V_395 -> V_400 , V_202 ,
V_365 , V_399 ) ;
if ( V_6 )
goto V_401;
V_202 += V_399 ;
V_365 += V_399 ;
}
V_401:
* V_393 = V_202 - V_392 ;
return V_6 ;
}
int F_157 ( struct V_390 * V_391 , T_10 V_392 , T_2 V_198 )
{
struct V_394 * V_395 = F_155 ( V_391 ) ;
struct V_1 * V_2 = V_391 -> V_396 ;
T_10 V_202 = V_392 & ~ ( ( T_10 ) ( V_391 -> V_402 - 1 ) ) ;
T_10 V_397 = F_156 ( T_10 , V_392 + V_198 , V_391 -> V_398 ) ;
T_2 V_399 = V_395 -> V_403 . V_391 . V_402 ;
int V_6 = 0 ;
if ( ! V_395 -> V_404 ) {
V_6 = F_147 ( V_2 , V_395 -> V_400 ) ;
if ( V_6 )
goto V_401;
V_395 -> V_404 = true ;
}
while ( V_202 < V_397 ) {
V_6 = F_152 ( V_2 , V_395 -> V_400 , V_202 ,
V_399 ) ;
if ( V_6 )
goto V_401;
V_202 += V_399 ;
}
V_401:
return V_6 ;
}
int F_158 ( struct V_390 * V_391 , T_10 V_392 ,
T_2 V_198 , T_2 * V_393 , const T_8 * V_365 )
{
struct V_394 * V_395 = F_155 ( V_391 ) ;
struct V_1 * V_2 = V_391 -> V_396 ;
T_10 V_202 = V_392 ;
T_10 V_397 = F_156 ( T_10 , V_392 + V_198 , V_391 -> V_398 ) ;
T_2 V_399 ;
int V_6 = 0 ;
if ( ! V_395 -> V_404 ) {
V_6 = F_147 ( V_2 , V_395 -> V_400 ) ;
if ( V_6 )
goto V_401;
V_395 -> V_404 = true ;
}
while ( V_202 < V_397 ) {
V_399 = F_156 ( T_2 , V_397 - V_202 , V_368 ) ;
V_6 = F_150 ( V_2 , V_395 -> V_400 , V_202 ,
V_365 , V_399 ) ;
if ( V_6 )
goto V_401;
V_202 += V_399 ;
V_365 += V_399 ;
}
V_401:
* V_393 = V_202 - V_392 ;
return V_6 ;
}
int F_159 ( struct V_390 * V_391 )
{
struct V_394 * V_395 = F_155 ( V_391 ) ;
struct V_1 * V_2 = V_391 -> V_396 ;
int V_6 = 0 ;
if ( V_395 -> V_404 ) {
V_395 -> V_404 = false ;
V_6 = F_153 ( V_2 , V_395 -> V_400 ) ;
}
return V_6 ;
}
void F_160 ( struct V_405 * V_395 )
{
struct V_394 * V_406 =
F_161 ( V_395 , struct V_394 , V_403 ) ;
struct V_1 * V_2 = V_395 -> V_391 . V_396 ;
snprintf ( V_395 -> T_4 , sizeof( V_395 -> T_4 ) , L_44 ,
V_2 -> T_4 , V_395 -> V_407 , V_406 -> V_408 ) ;
}
