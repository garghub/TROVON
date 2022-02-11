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
#ifdef F_4
F_14 ( ( unsigned long ) V_2 -> V_4 -> V_32 . V_10 ) ;
#endif
F_15 ( V_2 -> V_4 ) ;
}
static void F_18 ( struct V_1 * V_2 , unsigned V_33 ,
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
F_19 ( & V_4 -> V_16 ) ;
++ V_4 -> V_40 ;
F_20 ( & V_4 -> V_16 ) ;
V_40 = V_4 -> V_40 & V_41 ;
V_39 = 0 ;
if ( V_4 -> V_19 == V_42 )
V_39 |= V_43 ;
if ( V_2 -> type -> V_44 == 1 ) {
F_21 ( V_37 [ 0 ] ,
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
F_21 ( V_37 [ 0 ] ,
V_45 , 0 ,
V_46 , 1 ,
V_47 , V_53 ,
V_48 , 0 ,
V_49 , V_40 ,
V_50 , V_39 ,
V_51 , ! V_4 -> V_25 ) ;
F_22 ( V_37 [ 1 ] ,
V_54 , V_33 ,
V_55 , V_35 ) ;
V_38 = 8 ;
}
#ifdef F_4
if ( V_4 -> V_12 && ! F_23 ( ! V_36 ) ) {
int V_56 = 0 ;
int V_57 ;
F_23 ( V_38 % 4 ) ;
F_23 ( V_35 % 4 ) ;
for ( V_57 = 0 ; V_57 < V_38 / 4 && V_56 < V_58 ; V_57 ++ )
V_56 += snprintf ( V_36 + V_56 , V_58 - V_56 ,
L_3 , F_24 ( V_37 [ V_57 ] . T_3 [ 0 ] ) ) ;
for ( V_57 = 0 ; V_57 < V_35 / 4 && V_56 < V_58 ; V_57 ++ )
V_56 += snprintf ( V_36 + V_56 , V_58 - V_56 ,
L_3 , F_24 ( V_34 [ V_57 ] . T_3 [ 0 ] ) ) ;
F_25 ( V_2 , V_59 , V_2 -> V_28 , L_4 , V_36 ) ;
}
#endif
V_2 -> type -> V_60 ( V_2 , V_37 , V_38 , V_34 , V_35 ) ;
V_4 -> V_25 = false ;
}
static int F_26 ( unsigned int V_61 )
{
switch ( V_61 ) {
case 0 :
return 0 ;
#define F_27 ( T_4 ) \
case MC_CMD_ERR_ ## name: \
return -name;
F_27 ( V_62 ) ;
F_27 ( V_63 ) ;
F_27 ( V_64 ) ;
F_27 ( V_65 ) ;
F_27 ( V_66 ) ;
F_27 ( V_67 ) ;
F_27 ( V_68 ) ;
F_27 ( V_69 ) ;
F_27 ( V_70 ) ;
F_27 ( V_71 ) ;
F_27 ( V_72 ) ;
F_27 ( V_73 ) ;
#undef F_27
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
static void F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
unsigned int V_81 , V_82 , error ;
#ifdef F_4
char * V_36 = V_4 -> V_10 ;
#endif
T_1 V_37 ;
V_2 -> type -> V_83 ( V_2 , & V_37 , 0 , 4 ) ;
V_81 = F_29 ( V_37 , V_49 ) ;
V_82 = F_29 ( V_37 , V_47 ) ;
error = F_29 ( V_37 , V_84 ) ;
if ( V_82 != V_53 ) {
V_4 -> V_85 = 4 ;
V_4 -> V_86 = F_29 ( V_37 , V_48 ) ;
} else {
V_2 -> type -> V_83 ( V_2 , & V_37 , 4 , 4 ) ;
V_4 -> V_85 = 8 ;
V_4 -> V_86 =
F_29 ( V_37 , V_55 ) ;
}
#ifdef F_4
if ( V_4 -> V_12 && ! F_23 ( ! V_36 ) ) {
T_2 V_38 , V_87 ;
int V_56 = 0 ;
int V_57 ;
F_23 ( V_4 -> V_85 % 4 ) ;
V_38 = V_4 -> V_85 / 4 ;
V_87 = F_30 ( V_4 -> V_86 , 4 ) ;
for ( V_57 = 0 ; V_57 < V_38 && V_56 < V_58 ; V_57 ++ ) {
V_2 -> type -> V_83 ( V_2 , & V_37 , ( V_57 * 4 ) , 4 ) ;
V_56 += snprintf ( V_36 + V_56 , V_58 - V_56 ,
L_3 , F_24 ( V_37 . T_3 [ 0 ] ) ) ;
}
for ( V_57 = 0 ; V_57 < V_87 && V_56 < V_58 ; V_57 ++ ) {
V_2 -> type -> V_83 ( V_2 , & V_37 ,
V_4 -> V_85 + ( V_57 * 4 ) , 4 ) ;
V_56 += snprintf ( V_36 + V_56 , V_58 - V_56 ,
L_3 , F_24 ( V_37 . T_3 [ 0 ] ) ) ;
}
F_25 ( V_2 , V_59 , V_2 -> V_28 , L_5 , V_36 ) ;
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
V_4 -> V_88 = F_29 ( V_37 , V_91 ) ;
V_4 -> V_89 = F_26 ( V_4 -> V_88 ) ;
} else {
V_4 -> V_89 = 0 ;
}
}
static bool F_31 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
F_32 () ;
if ( ! V_2 -> type -> V_92 ( V_2 ) )
return false ;
F_19 ( & V_4 -> V_16 ) ;
F_28 ( V_2 ) ;
F_20 ( & V_4 -> V_16 ) ;
return true ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
unsigned long time , V_93 ;
unsigned int V_94 ;
int V_6 ;
V_6 = F_10 ( V_2 ) ;
if ( V_6 ) {
F_19 ( & V_4 -> V_16 ) ;
V_4 -> V_89 = V_6 ;
V_4 -> V_85 = 0 ;
V_4 -> V_86 = 0 ;
F_20 ( & V_4 -> V_16 ) ;
return 0 ;
}
V_94 = V_95 ;
V_93 = V_96 + V_97 ;
while ( 1 ) {
if ( V_94 != 0 ) {
-- V_94 ;
F_34 ( 1 ) ;
} else {
F_35 ( 1 ) ;
}
time = V_96 ;
if ( F_31 ( V_2 ) )
break;
if ( F_36 ( time , V_93 ) )
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
static bool F_37 ( struct V_3 * V_4 )
{
return F_38 ( & V_4 -> V_17 ,
V_18 , V_100 ) ==
V_18 ;
}
static void F_39 ( struct V_3 * V_4 )
{
F_40 ( V_4 -> V_14 ,
F_38 ( & V_4 -> V_17 ,
V_18 , V_101 ) ==
V_18 ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
if ( F_42 ( V_4 -> V_14 , V_4 -> V_17 == V_102 ,
V_97 ) == 0 )
return - V_98 ;
if ( V_4 -> V_19 == V_20 )
return F_33 ( V_2 ) ;
return 0 ;
}
static bool F_43 ( struct V_3 * V_4 )
{
if ( F_38 ( & V_4 -> V_17 ,
V_101 , V_102 ) ==
V_101 ) {
F_44 ( & V_4 -> V_14 ) ;
return true ;
}
return false ;
}
static void F_45 ( struct V_3 * V_4 )
{
if ( V_4 -> V_19 == V_42 ) {
struct V_103 * V_104 ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_19 ( & V_4 -> V_21 ) ;
V_104 = F_46 (
& V_4 -> V_22 , struct V_103 , V_105 ) ;
if ( V_104 ) {
V_4 -> V_17 = V_100 ;
F_18 ( V_2 , V_104 -> V_33 ,
( const T_1 * ) ( V_104 + 1 ) ,
V_104 -> V_35 ) ;
F_47 ( & V_4 -> V_23 ,
V_96 + V_97 ) ;
}
F_20 ( & V_4 -> V_21 ) ;
if ( V_104 )
return;
}
V_4 -> V_17 = V_18 ;
F_44 ( & V_4 -> V_14 ) ;
}
static bool F_48 ( struct V_3 * V_4 , bool V_106 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_103 * V_104 ;
T_2 V_38 , V_87 , V_107 ;
T_1 * V_108 ;
F_49 ( V_109 ) ;
int V_6 ;
if ( F_38 ( & V_4 -> V_17 ,
V_100 , V_102 ) !=
V_100 )
return false ;
F_50 ( & V_4 -> V_16 ) ;
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
F_51 ( & V_4 -> V_16 ) ;
if ( ! V_106 )
F_52 ( & V_4 -> V_23 ) ;
F_50 ( & V_4 -> V_21 ) ;
V_104 = F_53 ( & V_4 -> V_22 ,
struct V_103 , V_105 ) ;
F_54 ( & V_104 -> V_105 ) ;
F_51 ( & V_4 -> V_21 ) ;
V_108 = ( T_1 * ) ( V_104 + 1 ) ;
V_2 -> type -> V_83 ( V_2 , V_108 , V_38 ,
F_55 ( V_104 -> V_111 , V_87 ) ) ;
if ( ! V_106 && V_6 && ! V_104 -> V_112 ) {
V_107 = F_55 ( sizeof( V_109 ) , V_87 ) ;
V_2 -> type -> V_83 ( V_2 , V_109 , V_38 ,
sizeof( V_109 ) ) ;
F_56 ( V_2 , V_104 -> V_33 , V_104 -> V_35 , V_109 ,
V_107 , V_6 ) ;
}
if ( V_104 -> V_113 )
V_104 -> V_113 ( V_2 , V_104 -> V_114 , V_6 , V_108 ,
F_55 ( V_104 -> V_111 , V_87 ) ) ;
F_15 ( V_104 ) ;
F_45 ( V_4 ) ;
return true ;
}
static void F_57 ( struct V_1 * V_2 , unsigned int V_40 ,
unsigned int V_115 , unsigned int V_61 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
bool V_116 = false ;
F_50 ( & V_4 -> V_16 ) ;
if ( ( V_40 ^ V_4 -> V_40 ) & V_41 ) {
if ( V_4 -> V_110 )
-- V_4 -> V_110 ;
else
F_13 ( V_2 , V_59 , V_2 -> V_28 ,
L_8
L_9 , V_40 , V_4 -> V_40 ) ;
} else {
if ( V_2 -> type -> V_44 >= 2 ) {
F_28 ( V_2 ) ;
} else {
V_4 -> V_89 = F_26 ( V_61 ) ;
V_4 -> V_85 = 4 ;
V_4 -> V_86 = V_115 ;
}
V_116 = true ;
}
F_51 ( & V_4 -> V_16 ) ;
if ( V_116 ) {
if ( ! F_48 ( V_4 , false ) )
( void ) F_43 ( V_4 ) ;
}
}
static void V_24 ( unsigned long V_117 )
{
struct V_3 * V_4 = (struct V_3 * ) V_117 ;
F_48 ( V_4 , true ) ;
}
static int
F_58 ( struct V_1 * V_2 , unsigned int V_33 , T_2 V_35 )
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
static bool F_59 ( struct V_1 * V_2 ,
T_2 V_38 , T_2 V_87 ,
T_3 * V_121 )
{
F_49 ( V_122 ) ;
const T_2 V_123 = sizeof( V_122 ) ;
if ( ! V_121 || V_87 < V_123 )
return false ;
V_2 -> type -> V_83 ( V_2 , V_122 , V_38 , V_123 ) ;
if ( F_60 ( V_122 , V_124 ) == V_125 ) {
* V_121 = F_60 ( V_122 , V_126 ) ;
return true ;
}
return false ;
}
static int F_61 ( struct V_1 * V_2 , unsigned int V_33 ,
T_2 V_35 ,
T_1 * V_108 , T_2 V_111 ,
T_2 * V_127 , bool V_112 ,
T_3 * V_121 , int * V_128 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
F_49 ( V_109 ) ;
int V_6 ;
if ( V_4 -> V_19 == V_20 )
V_6 = F_33 ( V_2 ) ;
else
V_6 = F_41 ( V_2 ) ;
if ( V_6 != 0 ) {
F_13 ( V_2 , V_59 , V_2 -> V_28 ,
L_10 ,
V_33 , ( int ) V_35 , V_4 -> V_19 ) ;
if ( V_4 -> V_19 == V_42 && F_31 ( V_2 ) ) {
F_13 ( V_2 , V_59 , V_2 -> V_28 ,
L_11 ) ;
V_6 = 0 ;
}
F_62 ( V_2 ) ;
F_19 ( & V_4 -> V_16 ) ;
++ V_4 -> V_40 ;
++ V_4 -> V_110 ;
F_20 ( & V_4 -> V_16 ) ;
}
if ( V_121 )
* V_121 = 0 ;
if ( V_6 != 0 ) {
if ( V_127 )
* V_127 = 0 ;
} else {
T_2 V_38 , V_87 , V_107 ;
F_19 ( & V_4 -> V_16 ) ;
V_6 = V_4 -> V_89 ;
if ( V_128 )
* V_128 = V_4 -> V_88 ;
V_38 = V_4 -> V_85 ;
V_87 = V_4 -> V_86 ;
V_107 = F_55 ( sizeof( V_109 ) , V_87 ) ;
F_20 ( & V_4 -> V_16 ) ;
F_17 ( V_6 > 0 ) ;
V_2 -> type -> V_83 ( V_2 , V_108 , V_38 ,
F_55 ( V_111 , V_87 ) ) ;
if ( V_127 )
* V_127 = V_87 ;
V_2 -> type -> V_83 ( V_2 , V_109 , V_38 , V_107 ) ;
if ( V_33 == V_129 && V_6 == - V_90 ) {
} else if ( V_6 == - V_90 || V_6 == - V_64 ) {
F_13 ( V_2 , V_59 , V_2 -> V_28 , L_12 ,
- V_6 ) ;
F_63 ( V_2 , V_130 ) ;
} else if ( V_121 && ( V_6 == - V_80 ) &&
F_59 ( V_2 , V_38 , V_87 ,
V_121 ) ) {
V_4 -> V_131 = 0 ;
V_4 -> V_132 = 0 ;
V_4 -> V_17 = V_133 ;
} else if ( V_6 && ! V_112 ) {
F_56 ( V_2 , V_33 , V_35 , V_109 , V_107 ,
V_6 ) ;
}
if ( V_6 == - V_90 || V_6 == - V_64 ) {
F_64 ( V_134 ) ;
F_10 ( V_2 ) ;
V_4 -> V_25 = true ;
}
}
if ( ! V_121 || ! * V_121 )
F_45 ( V_4 ) ;
return V_6 ;
}
static void F_65 ( struct V_3 * V_4 )
{
if ( V_4 -> V_17 == V_133 ) {
V_4 -> V_131 = - V_64 ;
F_44 ( & V_4 -> V_15 ) ;
}
}
static void F_66 ( struct V_1 * V_2 ,
T_3 V_135 , int V_136 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
F_67 ( V_4 -> V_17 != V_133 ) ;
V_4 -> V_131 = F_26 ( V_136 ) ;
F_68 () ;
V_4 -> V_132 = V_135 ;
F_44 ( & V_4 -> V_15 ) ;
}
static int F_69 ( struct V_1 * V_2 , T_3 V_135 , bool V_112 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
int V_6 ;
V_6 = F_42 ( V_4 -> V_15 ,
V_4 -> V_132 != 0 ||
V_4 -> V_131 == - V_64 ,
V_97 ) ;
if ( V_6 <= 0 ) {
F_70 ( V_2 , V_59 , V_2 -> V_28 ,
L_13 , V_135 ) ;
return - V_98 ;
} else if ( V_4 -> V_132 != V_135 ) {
F_71 ( V_2 , V_59 , V_2 -> V_28 ,
L_14 ,
V_4 -> V_132 , V_135 ) ;
return - V_68 ;
}
return V_4 -> V_131 ;
}
static int F_72 ( struct V_1 * V_2 , unsigned int V_33 ,
const T_1 * V_34 , T_2 V_35 ,
T_1 * V_108 , T_2 V_111 ,
T_2 * V_127 , bool V_112 , int * V_128 )
{
T_3 V_121 = 0 ;
int V_6 ;
if ( V_34 && V_35 && ( V_34 == V_108 ) ) {
F_67 ( 1 ) ;
return - V_68 ;
}
V_6 = F_73 ( V_2 , V_33 , V_34 , V_35 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_61 ( V_2 , V_33 , V_35 , V_108 , V_111 ,
V_127 , V_112 , & V_121 , V_128 ) ;
if ( V_121 ) {
struct V_3 * V_4 = F_3 ( V_2 ) ;
F_70 ( V_2 , V_59 , V_2 -> V_28 ,
L_15 ,
V_121 ) ;
V_6 = F_69 ( V_2 , V_121 , V_112 ) ;
if ( V_6 == 0 ) {
F_70 ( V_2 , V_59 , V_2 -> V_28 ,
L_16 , V_121 ) ;
V_4 -> V_17 = V_101 ;
F_18 ( V_2 , V_33 , V_34 , V_35 ) ;
V_6 = F_61 ( V_2 , V_33 , V_35 ,
V_108 , V_111 , V_127 ,
V_112 , NULL , V_128 ) ;
} else {
F_74 ( V_2 , V_59 ,
V_6 == - V_62 ? V_137 : V_138 ,
V_2 -> V_28 ,
L_17 ,
V_33 , V_6 ) ;
if ( V_6 == - V_64 || V_6 == - V_90 )
F_63 ( V_2 , V_130 ) ;
F_45 ( V_4 ) ;
}
}
return V_6 ;
}
static int F_75 ( struct V_1 * V_2 , unsigned V_33 ,
const T_1 * V_34 , T_2 V_35 ,
T_1 * V_108 , T_2 V_111 ,
T_2 * V_127 , bool V_112 )
{
int V_128 = 0 ;
int V_6 ;
V_6 = F_72 ( V_2 , V_33 , V_34 , V_35 ,
V_108 , V_111 , V_127 , true , & V_128 ) ;
if ( ( V_6 == - V_80 ) && ( V_128 == V_139 ) &&
V_2 -> type -> V_140 ) {
unsigned long V_141 = V_96 + V_97 ;
unsigned int V_142 = 10000 ;
F_70 ( V_2 , V_59 , V_2 -> V_28 ,
L_18 ,
V_143 ) ;
do {
F_76 ( V_142 , V_142 + 10000 ) ;
V_6 = F_72 ( V_2 , V_33 , V_34 , V_35 ,
V_108 , V_111 , V_127 ,
true , & V_128 ) ;
if ( V_142 < 100000 )
V_142 <<= 1 ;
} while ( ( V_6 == - V_80 ) &&
( V_128 == V_139 ) &&
F_77 ( V_96 , V_141 ) );
}
if ( V_6 && ! V_112 && ! ( V_33 == V_129 && V_6 == - V_90 ) )
F_56 ( V_2 , V_33 , V_35 ,
V_108 , V_111 , V_6 ) ;
return V_6 ;
}
int F_78 ( struct V_1 * V_2 , unsigned V_33 ,
const T_1 * V_34 , T_2 V_35 ,
T_1 * V_108 , T_2 V_111 ,
T_2 * V_127 )
{
return F_75 ( V_2 , V_33 , V_34 , V_35 , V_108 , V_111 ,
V_127 , false ) ;
}
int F_79 ( struct V_1 * V_2 , unsigned V_33 ,
const T_1 * V_34 , T_2 V_35 ,
T_1 * V_108 , T_2 V_111 ,
T_2 * V_127 )
{
return F_75 ( V_2 , V_33 , V_34 , V_35 , V_108 , V_111 ,
V_127 , true ) ;
}
int F_73 ( struct V_1 * V_2 , unsigned V_33 ,
const T_1 * V_34 , T_2 V_35 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
int V_6 ;
V_6 = F_58 ( V_2 , V_33 , V_35 ) ;
if ( V_6 )
return V_6 ;
if ( V_2 -> V_144 )
return - V_145 ;
if ( V_4 -> V_19 == V_146 )
return - V_145 ;
F_39 ( V_4 ) ;
F_18 ( V_2 , V_33 , V_34 , V_35 ) ;
return 0 ;
}
static int F_80 ( struct V_1 * V_2 , unsigned int V_33 ,
const T_1 * V_34 , T_2 V_35 ,
T_2 V_111 ,
T_5 * V_113 ,
unsigned long V_114 , bool V_112 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
struct V_103 * V_104 ;
int V_6 ;
V_6 = F_58 ( V_2 , V_33 , V_35 ) ;
if ( V_6 )
return V_6 ;
if ( V_2 -> V_144 )
return - V_145 ;
V_104 = F_81 ( sizeof( * V_104 ) + F_82 ( F_83 ( V_35 , V_111 ) , 4 ) ,
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
F_19 ( & V_4 -> V_21 ) ;
if ( V_4 -> V_19 == V_42 ) {
F_84 ( & V_104 -> V_105 , & V_4 -> V_22 ) ;
if ( V_4 -> V_22 . V_148 == & V_104 -> V_105 &&
F_37 ( V_4 ) ) {
F_18 ( V_2 , V_33 , V_34 , V_35 ) ;
F_47 ( & V_4 -> V_23 ,
V_96 + V_97 ) ;
}
} else {
F_15 ( V_104 ) ;
V_6 = - V_145 ;
}
F_20 ( & V_4 -> V_21 ) ;
return V_6 ;
}
int
F_85 ( struct V_1 * V_2 , unsigned int V_33 ,
const T_1 * V_34 , T_2 V_35 , T_2 V_111 ,
T_5 * V_113 , unsigned long V_114 )
{
return F_80 ( V_2 , V_33 , V_34 , V_35 , V_111 , V_113 ,
V_114 , false ) ;
}
int F_86 ( struct V_1 * V_2 , unsigned int V_33 ,
const T_1 * V_34 , T_2 V_35 ,
T_2 V_111 , T_5 * V_113 ,
unsigned long V_114 )
{
return F_80 ( V_2 , V_33 , V_34 , V_35 , V_111 , V_113 ,
V_114 , true ) ;
}
int F_87 ( struct V_1 * V_2 , unsigned V_33 , T_2 V_35 ,
T_1 * V_108 , T_2 V_111 ,
T_2 * V_127 )
{
return F_61 ( V_2 , V_33 , V_35 , V_108 , V_111 ,
V_127 , false , NULL , NULL ) ;
}
int F_88 ( struct V_1 * V_2 , unsigned V_33 , T_2 V_35 ,
T_1 * V_108 , T_2 V_111 ,
T_2 * V_127 )
{
return F_61 ( V_2 , V_33 , V_35 , V_108 , V_111 ,
V_127 , true , NULL , NULL ) ;
}
void F_56 ( struct V_1 * V_2 , unsigned V_33 ,
T_2 V_35 , T_1 * V_108 ,
T_2 V_111 , int V_6 )
{
int V_149 = 0 , V_150 = 0 ;
if ( V_111 >= V_151 + 4 )
V_149 = F_60 ( V_108 , V_124 ) ;
if ( V_111 >= V_152 + 4 )
V_150 = F_60 ( V_108 , V_153 ) ;
F_74 ( V_2 , V_59 , V_6 == - V_62 ? V_137 : V_138 ,
V_2 -> V_28 ,
L_19 ,
V_33 , V_35 , V_6 , V_149 , V_150 ) ;
}
void F_89 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( ! V_2 -> V_4 )
return;
V_4 = F_3 ( V_2 ) ;
if ( V_4 -> V_19 == V_20 || V_4 -> V_19 == V_146 )
return;
V_4 -> V_19 = V_20 ;
F_43 ( V_4 ) ;
}
void F_90 ( struct V_1 * V_2 )
{
struct V_103 * V_104 , * V_148 ;
struct V_3 * V_4 ;
if ( ! V_2 -> V_4 )
return;
V_4 = F_3 ( V_2 ) ;
F_17 ( V_4 -> V_19 == V_42 ) ;
F_52 ( & V_4 -> V_23 ) ;
if ( V_4 -> V_17 == V_100 ) {
F_33 ( V_2 ) ;
V_4 -> V_17 = V_18 ;
}
F_91 (async, next, &mcdi->async_list, list) {
if ( V_104 -> V_113 )
V_104 -> V_113 ( V_2 , V_104 -> V_114 , - V_145 , NULL , 0 ) ;
F_54 ( & V_104 -> V_105 ) ;
F_15 ( V_104 ) ;
}
}
void F_92 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( ! V_2 -> V_4 )
return;
V_4 = F_3 ( V_2 ) ;
if ( V_4 -> V_19 == V_42 || V_4 -> V_19 == V_146 )
return;
F_39 ( V_4 ) ;
V_4 -> V_19 = V_42 ;
F_45 ( V_4 ) ;
}
static void F_93 ( struct V_1 * V_2 , int V_6 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
F_50 ( & V_4 -> V_16 ) ;
F_65 ( V_4 ) ;
if ( F_43 ( V_4 ) ) {
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
F_34 ( V_156 ) ;
}
if ( ! V_6 && V_2 -> type -> V_157 )
V_2 -> type -> V_157 ( V_2 ) ;
V_4 -> V_25 = true ;
F_63 ( V_2 , V_130 ) ;
}
F_51 ( & V_4 -> V_16 ) ;
}
static void F_94 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
F_50 ( & V_4 -> V_16 ) ;
V_2 -> V_144 = true ;
F_65 ( V_4 ) ;
if ( F_43 ( V_4 ) ) {
if ( V_4 -> V_19 == V_42 ) {
V_4 -> V_89 = - V_90 ;
V_4 -> V_85 = 0 ;
V_4 -> V_86 = 0 ;
++ V_4 -> V_110 ;
}
}
V_4 -> V_25 = true ;
F_63 ( V_2 , V_158 ) ;
F_51 ( & V_4 -> V_16 ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
if ( F_95 ( & V_4 -> V_19 , V_146 ) == V_146 )
return;
F_70 ( V_2 , V_59 , V_2 -> V_28 , L_20 ) ;
F_63 ( V_2 , V_159 ) ;
}
void F_96 ( struct V_160 * V_161 ,
T_6 * V_162 )
{
struct V_1 * V_2 = V_161 -> V_2 ;
int V_149 = F_97 ( * V_162 , V_163 ) ;
T_3 V_164 = F_97 ( * V_162 , V_165 ) ;
switch ( V_149 ) {
case V_166 :
F_13 ( V_2 , V_59 , V_2 -> V_28 ,
L_21 , V_164 ) ;
F_93 ( V_2 , - V_64 ) ;
break;
case V_167 :
F_25 ( V_2 , V_168 , V_2 -> V_28 , L_22 ) ;
break;
case V_169 :
F_57 ( V_2 ,
F_98 ( * V_162 , V_170 ) ,
F_98 ( * V_162 , V_171 ) ,
F_98 ( * V_162 , V_172 ) ) ;
break;
case V_173 :
F_99 ( V_2 , V_162 ) ;
break;
case V_174 :
F_100 ( V_2 , V_162 ) ;
break;
case V_175 :
F_70 ( V_2 , V_59 , V_2 -> V_28 ,
L_23 , V_164 ) ;
break;
case V_176 :
case V_177 :
F_25 ( V_2 , V_59 , V_2 -> V_28 , L_24 ) ;
F_93 ( V_2 , - V_90 ) ;
break;
case V_178 :
F_25 ( V_2 , V_59 , V_2 -> V_28 , L_25 ) ;
F_94 ( V_2 ) ;
break;
case V_179 :
break;
case V_180 :
if ( V_2 -> type -> V_181 )
V_2 -> type -> V_181 ( V_2 ,
F_98 ( * V_162 , V_182 ) ) ;
break;
case V_183 :
case V_184 :
case V_185 :
F_101 ( V_2 , V_162 ) ;
break;
case V_186 :
F_102 ( V_161 , V_162 ) ;
break;
case V_187 :
case V_188 :
F_103 ( V_189 !=
V_190 ) ;
if ( ! F_98 ( * V_162 , V_191 ) )
F_104 ( V_2 ) ;
break;
case V_192 :
case V_193 :
F_13 ( V_2 , V_59 , V_2 -> V_28 ,
L_26 V_194 L_27 ,
V_149 == V_192 ? L_28 : L_29 ,
F_105 ( * V_162 ) ) ;
F_63 ( V_2 , V_195 ) ;
break;
case V_196 :
F_66 ( V_2 ,
F_98 ( * V_162 , V_197 ) ,
F_98 ( * V_162 , V_198 ) ) ;
break;
default:
F_13 ( V_2 , V_59 , V_2 -> V_28 , L_30 ,
V_149 ) ;
}
}
void F_106 ( struct V_1 * V_2 , char * V_36 , T_2 V_199 )
{
F_107 ( V_108 , V_200 ) ;
T_2 V_201 ;
const T_7 * V_202 ;
T_2 V_203 ;
int V_6 ;
F_103 ( V_204 != 0 ) ;
V_6 = F_78 ( V_2 , V_205 , NULL , 0 ,
V_108 , sizeof( V_108 ) , & V_201 ) ;
if ( V_6 )
goto V_9;
if ( V_201 < V_200 ) {
V_6 = - V_90 ;
goto V_9;
}
V_202 = ( T_7 * ) F_108 ( V_108 , V_206 ) ;
V_203 = snprintf ( V_36 , V_199 , L_31 ,
F_109 ( V_202 [ 0 ] ) , F_109 ( V_202 [ 1 ] ) ,
F_109 ( V_202 [ 2 ] ) , F_109 ( V_202 [ 3 ] ) ) ;
if ( F_110 ( V_2 ) >= V_207 ) {
struct V_208 * V_209 = V_2 -> V_209 ;
V_203 += snprintf ( V_36 + V_203 , V_199 - V_203 , L_32 ,
V_209 -> V_210 ,
V_209 -> V_211 ) ;
if ( F_67 ( V_203 >= V_199 ) )
V_36 [ 0 ] = 0 ;
}
return;
V_9:
F_13 ( V_2 , V_27 , V_2 -> V_28 , L_33 , V_143 , V_6 ) ;
V_36 [ 0 ] = 0 ;
}
static int F_12 ( struct V_1 * V_2 , bool V_212 ,
bool * V_213 )
{
F_107 ( V_34 , V_214 ) ;
F_107 ( V_108 , V_215 ) ;
T_2 V_111 ;
int V_6 ;
F_111 ( V_34 , V_216 ,
V_212 ? 1 : 0 ) ;
F_111 ( V_34 , V_217 , 1 ) ;
F_111 ( V_34 , V_218 , V_219 ) ;
V_6 = F_79 ( V_2 , V_220 , V_34 , sizeof( V_34 ) ,
V_108 , sizeof( V_108 ) , & V_111 ) ;
if ( V_6 == - V_62 ) {
F_70 ( V_2 , V_27 , V_2 -> V_28 ,
L_34 ) ;
F_111 ( V_34 , V_218 ,
V_221 ) ;
V_6 = F_79 ( V_2 , V_220 , V_34 ,
sizeof( V_34 ) , V_108 , sizeof( V_108 ) ,
& V_111 ) ;
}
if ( V_6 ) {
F_56 ( V_2 , V_220 , sizeof( V_34 ) ,
V_108 , V_111 , V_6 ) ;
goto V_9;
}
if ( V_111 < V_222 ) {
V_6 = - V_90 ;
goto V_9;
}
if ( V_212 ) {
if ( V_111 >= V_215 ) {
V_2 -> V_4 -> V_29 =
F_60 ( V_108 ,
V_223 ) ;
} else {
V_2 -> V_4 -> V_29 =
1 << V_224 |
1 << V_225 |
( F_112 ( V_2 ) == 0 ) <<
V_30 ;
}
}
if ( V_213 != NULL )
* V_213 = F_60 ( V_108 , V_226 ) ;
return 0 ;
V_9:
F_13 ( V_2 , V_27 , V_2 -> V_28 , L_33 , V_143 , V_6 ) ;
return V_6 ;
}
int F_113 ( struct V_1 * V_2 , T_8 * V_227 ,
T_9 * V_228 , T_3 * V_229 )
{
F_107 ( V_108 , V_230 ) ;
T_2 V_111 , V_57 ;
int V_231 = F_112 ( V_2 ) ;
int V_6 ;
F_103 ( V_232 != 0 ) ;
F_103 ( V_233 & 1 ) ;
F_103 ( V_234 & 1 ) ;
V_6 = F_78 ( V_2 , V_235 , NULL , 0 ,
V_108 , sizeof( V_108 ) , & V_111 ) ;
if ( V_6 )
goto V_9;
if ( V_111 < V_236 ) {
V_6 = - V_90 ;
goto V_9;
}
if ( V_227 )
F_114 ( V_227 ,
V_231 ?
F_108 ( V_108 , V_237 ) :
F_108 ( V_108 , V_238 ) ) ;
if ( V_228 ) {
for ( V_57 = 0 ;
V_57 < F_115 ( V_111 ,
V_239 ) ;
V_57 ++ )
V_228 [ V_57 ] = F_116 (
V_108 , V_239 , V_57 ) ;
for (; V_57 < V_240 ; V_57 ++ )
V_228 [ V_57 ] = 0 ;
}
if ( V_229 ) {
if ( V_231 )
* V_229 = F_60 ( V_108 ,
V_241 ) ;
else
* V_229 = F_60 ( V_108 ,
V_242 ) ;
}
return 0 ;
V_9:
F_13 ( V_2 , V_59 , V_2 -> V_28 , L_35 ,
V_143 , V_6 , ( int ) V_111 ) ;
return V_6 ;
}
int F_117 ( struct V_1 * V_2 , bool V_243 , bool V_244 , T_3 V_245 )
{
F_107 ( V_34 , V_246 ) ;
T_3 V_247 = 0 ;
int V_6 ;
if ( V_244 )
V_247 |= V_248 ;
if ( V_243 )
V_247 |= V_249 ;
F_111 ( V_34 , V_250 , V_247 ) ;
F_111 ( V_34 , V_251 , V_245 ) ;
F_103 ( V_252 != 0 ) ;
V_6 = F_78 ( V_2 , V_253 , V_34 , sizeof( V_34 ) ,
NULL , 0 , NULL ) ;
return V_6 ;
}
int F_118 ( struct V_1 * V_2 , T_3 * V_254 )
{
F_107 ( V_108 , V_255 ) ;
T_2 V_111 ;
int V_6 ;
F_103 ( V_256 != 0 ) ;
V_6 = F_78 ( V_2 , V_257 , NULL , 0 ,
V_108 , sizeof( V_108 ) , & V_111 ) ;
if ( V_6 )
goto V_9;
if ( V_111 < V_255 ) {
V_6 = - V_90 ;
goto V_9;
}
* V_254 = F_60 ( V_108 , V_258 ) ;
return 0 ;
V_9:
F_13 ( V_2 , V_59 , V_2 -> V_28 , L_33 ,
V_143 , V_6 ) ;
return V_6 ;
}
int F_119 ( struct V_1 * V_2 , unsigned int type ,
T_2 * V_259 , T_2 * V_260 ,
bool * V_261 )
{
F_107 ( V_34 , V_262 ) ;
F_107 ( V_108 , V_263 ) ;
T_2 V_111 ;
int V_6 ;
F_111 ( V_34 , V_264 , type ) ;
V_6 = F_78 ( V_2 , V_265 , V_34 , sizeof( V_34 ) ,
V_108 , sizeof( V_108 ) , & V_111 ) ;
if ( V_6 )
goto V_9;
if ( V_111 < V_263 ) {
V_6 = - V_90 ;
goto V_9;
}
* V_259 = F_60 ( V_108 , V_266 ) ;
* V_260 = F_60 ( V_108 , V_267 ) ;
* V_261 = ! ! ( F_60 ( V_108 , V_268 ) &
( 1 << V_269 ) ) ;
return 0 ;
V_9:
F_13 ( V_2 , V_59 , V_2 -> V_28 , L_33 , V_143 , V_6 ) ;
return V_6 ;
}
static int F_120 ( struct V_1 * V_2 , unsigned int type )
{
F_107 ( V_34 , V_270 ) ;
F_107 ( V_108 , V_271 ) ;
int V_6 ;
F_111 ( V_34 , V_272 , type ) ;
V_6 = F_78 ( V_2 , V_273 , V_34 , sizeof( V_34 ) ,
V_108 , sizeof( V_108 ) , NULL ) ;
if ( V_6 )
return V_6 ;
switch ( F_60 ( V_108 , V_274 ) ) {
case V_275 :
case V_276 :
return 0 ;
default:
return - V_90 ;
}
}
int F_121 ( struct V_1 * V_2 )
{
T_3 V_277 ;
unsigned int type ;
int V_6 ;
V_6 = F_118 ( V_2 , & V_277 ) ;
if ( V_6 )
goto V_11;
type = 0 ;
while ( V_277 != 0 ) {
if ( V_277 & 1 ) {
V_6 = F_120 ( V_2 , type ) ;
if ( V_6 )
goto V_26;
}
type ++ ;
V_277 >>= 1 ;
}
return 0 ;
V_26:
F_13 ( V_2 , V_59 , V_2 -> V_28 , L_36 ,
V_143 , type ) ;
V_11:
F_13 ( V_2 , V_59 , V_2 -> V_28 , L_33 , V_143 , V_6 ) ;
return V_6 ;
}
static int F_122 ( struct V_1 * V_2 )
{
F_107 ( V_34 , V_278 ) ;
F_107 ( V_108 , V_279 ) ;
unsigned int V_280 , V_281 ;
const char * V_282 ;
T_2 V_111 ;
int V_283 ;
int V_6 ;
V_283 = 2 ;
do {
F_111 ( V_34 , V_284 , 1 ) ;
V_6 = F_79 ( V_2 , V_285 ,
V_34 , V_278 ,
V_108 , sizeof( V_108 ) , & V_111 ) ;
if ( V_6 == - V_62 )
return 0 ;
} while ( ( V_6 == - V_64 || V_6 == - V_90 ) && V_283 -- > 0 );
if ( V_6 ) {
F_56 ( V_2 , V_285 ,
V_278 , V_108 ,
V_111 , V_6 ) ;
return V_6 ;
}
if ( V_111 < V_279 )
return - V_90 ;
V_280 = F_60 ( V_108 , V_286 ) ;
if ( V_280 == V_287 )
return 0 ;
V_282 = ( V_280 == V_288 )
? L_37
: ( V_280 == V_289 )
? L_38
: ( V_280 == V_290 )
? L_39
: L_40 ;
F_13 ( V_2 , V_59 , V_2 -> V_28 ,
L_41 , V_282 ,
F_60 ( V_108 , V_291 ) ,
F_60 ( V_108 , V_292 ) ) ;
for ( V_281 = 0 ;
V_281 < V_293 ;
V_281 ++ )
F_13 ( V_2 , V_59 , V_2 -> V_28 , L_42 ,
1 + V_281 ,
F_123 ( V_108 , V_294 ,
V_281 ) ) ;
return 1 ;
}
static int F_124 ( struct V_1 * V_2 )
{
F_107 ( V_34 , V_295 ) ;
int V_6 ;
F_103 ( V_296 != 0 ) ;
F_111 ( V_34 , V_297 ,
V_298 ) ;
V_6 = F_79 ( V_2 , V_129 , V_34 , V_295 ,
NULL , 0 , NULL ) ;
if ( V_6 == - V_90 )
V_6 = 0 ;
if ( V_6 )
F_56 ( V_2 , V_129 , V_295 ,
NULL , 0 , V_6 ) ;
return V_6 ;
}
int F_11 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_122 ( V_2 ) ;
if ( V_6 <= 0 )
return V_6 ;
return F_124 ( V_2 ) ;
}
void F_125 ( struct V_1 * V_2 , enum V_299 V_19 )
{
F_107 ( V_34 , V_300 ) ;
int V_6 ;
F_103 ( V_301 != V_302 ) ;
F_103 ( V_303 != V_304 ) ;
F_103 ( V_305 != V_306 ) ;
F_103 ( V_307 != 0 ) ;
F_111 ( V_34 , V_308 , V_19 ) ;
V_6 = F_78 ( V_2 , V_309 , V_34 , sizeof( V_34 ) ,
NULL , 0 , NULL ) ;
}
static int F_126 ( struct V_1 * V_2 )
{
F_107 ( V_34 , V_310 ) ;
int V_6 ;
F_103 ( V_311 != 0 ) ;
F_127 ( V_34 , V_312 ,
V_313 , 1 ) ;
V_6 = F_78 ( V_2 , V_314 , V_34 , sizeof( V_34 ) ,
NULL , 0 , NULL ) ;
return V_6 ;
}
static int F_128 ( struct V_1 * V_2 )
{
F_107 ( V_34 , V_295 ) ;
int V_6 ;
F_103 ( V_296 != 0 ) ;
F_111 ( V_34 , V_297 , 0 ) ;
V_6 = F_78 ( V_2 , V_129 , V_34 , sizeof( V_34 ) ,
NULL , 0 , NULL ) ;
if ( V_6 == - V_90 )
return 0 ;
if ( V_6 == 0 )
V_6 = - V_90 ;
return V_6 ;
}
enum V_315 F_129 ( enum V_315 V_282 )
{
return V_316 ;
}
int F_130 ( struct V_1 * V_2 , enum V_315 V_317 )
{
int V_6 ;
if ( V_317 == V_159 ) {
V_6 = F_131 ( V_2 -> V_318 ) ;
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
if ( V_317 == V_319 )
return 0 ;
else if ( V_317 == V_320 )
return F_128 ( V_2 ) ;
else
return F_126 ( V_2 ) ;
}
static int F_132 ( struct V_1 * V_2 , T_3 type ,
const T_8 * V_321 , int * V_322 )
{
F_107 ( V_34 , V_323 ) ;
F_107 ( V_108 , V_324 ) ;
T_2 V_111 ;
int V_6 ;
F_111 ( V_34 , V_325 , type ) ;
F_111 ( V_34 , V_326 ,
V_327 ) ;
F_114 ( F_108 ( V_34 , V_328 ) , V_321 ) ;
V_6 = F_78 ( V_2 , V_329 , V_34 , sizeof( V_34 ) ,
V_108 , sizeof( V_108 ) , & V_111 ) ;
if ( V_6 )
goto V_9;
if ( V_111 < V_324 ) {
V_6 = - V_90 ;
goto V_9;
}
* V_322 = ( int ) F_60 ( V_108 , V_330 ) ;
return 0 ;
V_9:
* V_322 = - 1 ;
F_13 ( V_2 , V_59 , V_2 -> V_28 , L_33 , V_143 , V_6 ) ;
return V_6 ;
}
int
F_133 ( struct V_1 * V_2 , const T_8 * V_321 , int * V_322 )
{
return F_132 ( V_2 , V_331 , V_321 , V_322 ) ;
}
int F_134 ( struct V_1 * V_2 , int * V_322 )
{
F_107 ( V_108 , V_332 ) ;
T_2 V_111 ;
int V_6 ;
V_6 = F_78 ( V_2 , V_333 , NULL , 0 ,
V_108 , sizeof( V_108 ) , & V_111 ) ;
if ( V_6 )
goto V_9;
if ( V_111 < V_332 ) {
V_6 = - V_90 ;
goto V_9;
}
* V_322 = ( int ) F_60 ( V_108 , V_334 ) ;
return 0 ;
V_9:
* V_322 = - 1 ;
F_13 ( V_2 , V_59 , V_2 -> V_28 , L_33 , V_143 , V_6 ) ;
return V_6 ;
}
int F_135 ( struct V_1 * V_2 , int V_335 )
{
F_107 ( V_34 , V_336 ) ;
int V_6 ;
F_111 ( V_34 , V_337 , ( T_3 ) V_335 ) ;
V_6 = F_78 ( V_2 , V_338 , V_34 , sizeof( V_34 ) ,
NULL , 0 , NULL ) ;
return V_6 ;
}
int F_136 ( struct V_1 * V_2 )
{
struct V_160 * V_161 ;
struct V_339 * V_340 ;
F_107 ( V_34 ,
F_137 ( V_341 ) ) ;
int V_6 , V_154 ;
F_103 ( V_341 >
V_342 ) ;
V_154 = 0 ;
F_138 (channel, efx) {
F_139 (rx_queue, channel) {
if ( V_340 -> V_343 ) {
V_340 -> V_343 = false ;
F_140 ( & V_2 -> V_344 ) ;
F_141 (
V_34 , V_345 ,
V_154 , F_142 ( V_340 ) ) ;
V_154 ++ ;
}
}
}
V_6 = F_78 ( V_2 , V_346 , V_34 ,
F_137 ( V_154 ) , NULL , 0 , NULL ) ;
F_67 ( V_6 < 0 ) ;
return V_6 ;
}
int F_143 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_78 ( V_2 , V_347 , NULL , 0 , NULL , 0 , NULL ) ;
return V_6 ;
}
int F_144 ( struct V_1 * V_2 , T_3 type , bool V_348 ,
unsigned int * V_280 )
{
F_107 ( V_34 , V_349 ) ;
F_107 ( V_108 , V_350 ) ;
T_2 V_111 ;
int V_6 ;
F_103 ( V_351 != 0 ) ;
F_111 ( V_34 , V_352 , type ) ;
F_111 ( V_34 , V_353 , V_348 ) ;
V_6 = F_78 ( V_2 , V_354 , V_34 , sizeof( V_34 ) ,
V_108 , sizeof( V_108 ) , & V_111 ) ;
if ( V_6 )
return V_6 ;
if ( ! V_280 )
return 0 ;
if ( V_111 >= V_350 )
* V_280 = F_60 ( V_108 , V_355 ) ;
else
* V_280 = 0 ;
return 0 ;
}
int F_145 ( struct V_1 * V_2 , unsigned int * V_356 ,
unsigned int * V_357 )
{
F_107 ( V_108 , V_358 ) ;
T_2 V_111 ;
int V_6 ;
V_6 = F_78 ( V_2 , V_359 , NULL , 0 ,
V_108 , sizeof( V_108 ) , & V_111 ) ;
if ( V_6 )
goto V_9;
if ( V_111 < V_358 ) {
V_6 = - V_90 ;
goto V_9;
}
if ( V_356 )
* V_356 = F_60 ( V_108 , V_360 ) ;
if ( V_357 )
* V_357 = F_60 ( V_108 , V_361 ) ;
return 0 ;
V_9:
F_74 ( V_2 , V_59 , V_6 == - V_70 ? V_137 : V_138 ,
V_2 -> V_28 , L_33 , V_143 , V_6 ) ;
return V_6 ;
}
static int F_146 ( struct V_1 * V_2 , unsigned int type )
{
F_107 ( V_34 , V_362 ) ;
int V_6 ;
F_111 ( V_34 , V_363 , type ) ;
F_103 ( V_364 != 0 ) ;
V_6 = F_78 ( V_2 , V_365 , V_34 , sizeof( V_34 ) ,
NULL , 0 , NULL ) ;
return V_6 ;
}
static int F_147 ( struct V_1 * V_2 , unsigned int type ,
T_10 V_203 , T_8 * V_366 , T_2 V_367 )
{
F_107 ( V_34 , V_368 ) ;
F_107 ( V_108 ,
F_148 ( V_369 ) ) ;
T_2 V_111 ;
int V_6 ;
F_111 ( V_34 , V_370 , type ) ;
F_111 ( V_34 , V_371 , V_203 ) ;
F_111 ( V_34 , V_372 , V_367 ) ;
V_6 = F_78 ( V_2 , V_373 , V_34 , sizeof( V_34 ) ,
V_108 , sizeof( V_108 ) , & V_111 ) ;
if ( V_6 )
return V_6 ;
memcpy ( V_366 , F_108 ( V_108 , V_374 ) , V_367 ) ;
return 0 ;
}
static int F_149 ( struct V_1 * V_2 , unsigned int type ,
T_10 V_203 , const T_8 * V_366 , T_2 V_367 )
{
F_107 ( V_34 ,
F_150 ( V_369 ) ) ;
int V_6 ;
F_111 ( V_34 , V_375 , type ) ;
F_111 ( V_34 , V_376 , V_203 ) ;
F_111 ( V_34 , V_377 , V_367 ) ;
memcpy ( F_108 ( V_34 , V_378 ) , V_366 , V_367 ) ;
F_103 ( V_379 != 0 ) ;
V_6 = F_78 ( V_2 , V_380 , V_34 ,
F_82 ( F_150 ( V_367 ) , 4 ) ,
NULL , 0 , NULL ) ;
return V_6 ;
}
static int F_151 ( struct V_1 * V_2 , unsigned int type ,
T_10 V_203 , T_2 V_367 )
{
F_107 ( V_34 , V_381 ) ;
int V_6 ;
F_111 ( V_34 , V_382 , type ) ;
F_111 ( V_34 , V_383 , V_203 ) ;
F_111 ( V_34 , V_384 , V_367 ) ;
F_103 ( V_385 != 0 ) ;
V_6 = F_78 ( V_2 , V_386 , V_34 , sizeof( V_34 ) ,
NULL , 0 , NULL ) ;
return V_6 ;
}
static int F_152 ( struct V_1 * V_2 , unsigned int type )
{
F_107 ( V_34 , V_387 ) ;
int V_6 ;
F_111 ( V_34 , V_388 , type ) ;
F_103 ( V_389 != 0 ) ;
V_6 = F_78 ( V_2 , V_390 , V_34 , sizeof( V_34 ) ,
NULL , 0 , NULL ) ;
return V_6 ;
}
int F_153 ( struct V_391 * V_392 , T_10 V_393 ,
T_2 V_199 , T_2 * V_394 , T_8 * V_366 )
{
struct V_395 * V_396 = F_154 ( V_392 ) ;
struct V_1 * V_2 = V_392 -> V_397 ;
T_10 V_203 = V_393 ;
T_10 V_398 = F_155 ( T_10 , V_393 + V_199 , V_392 -> V_399 ) ;
T_2 V_400 ;
int V_6 = 0 ;
while ( V_203 < V_398 ) {
V_400 = F_155 ( T_2 , V_398 - V_203 , V_369 ) ;
V_6 = F_147 ( V_2 , V_396 -> V_401 , V_203 ,
V_366 , V_400 ) ;
if ( V_6 )
goto V_402;
V_203 += V_400 ;
V_366 += V_400 ;
}
V_402:
* V_394 = V_203 - V_393 ;
return V_6 ;
}
int F_156 ( struct V_391 * V_392 , T_10 V_393 , T_2 V_199 )
{
struct V_395 * V_396 = F_154 ( V_392 ) ;
struct V_1 * V_2 = V_392 -> V_397 ;
T_10 V_203 = V_393 & ~ ( ( T_10 ) ( V_392 -> V_403 - 1 ) ) ;
T_10 V_398 = F_155 ( T_10 , V_393 + V_199 , V_392 -> V_399 ) ;
T_2 V_400 = V_396 -> V_404 . V_392 . V_403 ;
int V_6 = 0 ;
if ( ! V_396 -> V_405 ) {
V_6 = F_146 ( V_2 , V_396 -> V_401 ) ;
if ( V_6 )
goto V_402;
V_396 -> V_405 = true ;
}
while ( V_203 < V_398 ) {
V_6 = F_151 ( V_2 , V_396 -> V_401 , V_203 ,
V_400 ) ;
if ( V_6 )
goto V_402;
V_203 += V_400 ;
}
V_402:
return V_6 ;
}
int F_157 ( struct V_391 * V_392 , T_10 V_393 ,
T_2 V_199 , T_2 * V_394 , const T_8 * V_366 )
{
struct V_395 * V_396 = F_154 ( V_392 ) ;
struct V_1 * V_2 = V_392 -> V_397 ;
T_10 V_203 = V_393 ;
T_10 V_398 = F_155 ( T_10 , V_393 + V_199 , V_392 -> V_399 ) ;
T_2 V_400 ;
int V_6 = 0 ;
if ( ! V_396 -> V_405 ) {
V_6 = F_146 ( V_2 , V_396 -> V_401 ) ;
if ( V_6 )
goto V_402;
V_396 -> V_405 = true ;
}
while ( V_203 < V_398 ) {
V_400 = F_155 ( T_2 , V_398 - V_203 , V_369 ) ;
V_6 = F_149 ( V_2 , V_396 -> V_401 , V_203 ,
V_366 , V_400 ) ;
if ( V_6 )
goto V_402;
V_203 += V_400 ;
V_366 += V_400 ;
}
V_402:
* V_394 = V_203 - V_393 ;
return V_6 ;
}
int F_158 ( struct V_391 * V_392 )
{
struct V_395 * V_396 = F_154 ( V_392 ) ;
struct V_1 * V_2 = V_392 -> V_397 ;
int V_6 = 0 ;
if ( V_396 -> V_405 ) {
V_396 -> V_405 = false ;
V_6 = F_152 ( V_2 , V_396 -> V_401 ) ;
}
return V_6 ;
}
void F_159 ( struct V_406 * V_396 )
{
struct V_395 * V_407 =
F_160 ( V_396 , struct V_395 , V_404 ) ;
struct V_1 * V_2 = V_396 -> V_392 . V_397 ;
snprintf ( V_396 -> T_4 , sizeof( V_396 -> T_4 ) , L_43 ,
V_2 -> T_4 , V_396 -> V_408 , V_407 -> V_409 ) ;
}
