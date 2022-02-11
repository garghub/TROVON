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
F_7 ( & V_4 -> V_15 ) ;
V_4 -> V_16 = V_17 ;
V_4 -> V_18 = V_19 ;
F_7 ( & V_4 -> V_20 ) ;
F_8 ( & V_4 -> V_21 ) ;
F_9 ( & V_4 -> V_22 , V_23 ,
( unsigned long ) V_4 ) ;
( void ) F_10 ( V_2 ) ;
V_4 -> V_24 = true ;
V_6 = F_11 ( V_2 ) ;
if ( V_6 )
goto V_25;
V_6 = F_12 ( V_2 , true , & V_5 ) ;
if ( V_6 ) {
F_13 ( V_2 , V_26 , V_2 -> V_27 ,
L_1 ) ;
goto V_25;
}
if ( V_5 )
F_13 ( V_2 , V_26 , V_2 -> V_27 ,
L_2 ) ;
if ( V_2 -> V_4 -> V_28 &
( 1 << V_29 ) )
V_2 -> V_30 = V_2 ;
return 0 ;
V_25:
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
F_17 ( V_2 -> V_4 -> V_31 . V_16 != V_17 ) ;
F_12 ( V_2 , false , NULL ) ;
#ifdef F_4
F_14 ( ( unsigned long ) V_2 -> V_4 -> V_31 . V_10 ) ;
#endif
F_15 ( V_2 -> V_4 ) ;
}
static void F_18 ( struct V_1 * V_2 , unsigned V_32 ,
const T_1 * V_33 , T_2 V_34 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
#ifdef F_4
char * V_35 = V_4 -> V_10 ;
#endif
T_1 V_36 [ 2 ] ;
T_2 V_37 ;
T_3 V_38 , V_39 ;
F_17 ( V_4 -> V_16 == V_17 ) ;
F_19 ( & V_4 -> V_15 ) ;
++ V_4 -> V_39 ;
F_20 ( & V_4 -> V_15 ) ;
V_39 = V_4 -> V_39 & V_40 ;
V_38 = 0 ;
if ( V_4 -> V_18 == V_41 )
V_38 |= V_42 ;
if ( V_2 -> type -> V_43 == 1 ) {
F_21 ( V_36 [ 0 ] ,
V_44 , 0 ,
V_45 , 1 ,
V_46 , V_32 ,
V_47 , V_34 ,
V_48 , V_39 ,
V_49 , V_38 ,
V_50 , ! V_4 -> V_24 ) ;
V_37 = 4 ;
} else {
F_17 ( V_34 > V_51 ) ;
F_21 ( V_36 [ 0 ] ,
V_44 , 0 ,
V_45 , 1 ,
V_46 , V_52 ,
V_47 , 0 ,
V_48 , V_39 ,
V_49 , V_38 ,
V_50 , ! V_4 -> V_24 ) ;
F_22 ( V_36 [ 1 ] ,
V_53 , V_32 ,
V_54 , V_34 ) ;
V_37 = 8 ;
}
#ifdef F_4
if ( V_4 -> V_12 && ! F_23 ( ! V_35 ) ) {
int V_55 = 0 ;
int V_56 ;
F_23 ( V_37 % 4 ) ;
F_23 ( V_34 % 4 ) ;
for ( V_56 = 0 ; V_56 < V_37 / 4 && V_55 < V_57 ; V_56 ++ )
V_55 += snprintf ( V_35 + V_55 , V_57 - V_55 ,
L_3 , F_24 ( V_36 [ V_56 ] . T_3 [ 0 ] ) ) ;
for ( V_56 = 0 ; V_56 < V_34 / 4 && V_55 < V_57 ; V_56 ++ )
V_55 += snprintf ( V_35 + V_55 , V_57 - V_55 ,
L_3 , F_24 ( V_33 [ V_56 ] . T_3 [ 0 ] ) ) ;
F_25 ( V_2 , V_58 , V_2 -> V_27 , L_4 , V_35 ) ;
}
#endif
V_2 -> type -> V_59 ( V_2 , V_36 , V_37 , V_33 , V_34 ) ;
V_4 -> V_24 = false ;
}
static int F_26 ( unsigned int V_60 )
{
switch ( V_60 ) {
case 0 :
return 0 ;
#define F_27 ( T_4 ) \
case MC_CMD_ERR_ ## name: \
return -name;
F_27 ( V_61 ) ;
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
#undef F_27
case V_73 :
return - V_74 ;
case V_75 :
return - V_76 ;
case V_77 :
return - V_78 ;
default:
return - V_79 ;
}
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
unsigned int V_80 , V_81 , error ;
#ifdef F_4
char * V_35 = V_4 -> V_10 ;
#endif
T_1 V_36 ;
V_2 -> type -> V_82 ( V_2 , & V_36 , 0 , 4 ) ;
V_80 = F_29 ( V_36 , V_48 ) ;
V_81 = F_29 ( V_36 , V_46 ) ;
error = F_29 ( V_36 , V_83 ) ;
if ( V_81 != V_52 ) {
V_4 -> V_84 = 4 ;
V_4 -> V_85 = F_29 ( V_36 , V_47 ) ;
} else {
V_2 -> type -> V_82 ( V_2 , & V_36 , 4 , 4 ) ;
V_4 -> V_84 = 8 ;
V_4 -> V_85 =
F_29 ( V_36 , V_54 ) ;
}
#ifdef F_4
if ( V_4 -> V_12 && ! F_23 ( ! V_35 ) ) {
T_2 V_37 , V_86 ;
int V_55 = 0 ;
int V_56 ;
F_23 ( V_4 -> V_84 % 4 ) ;
V_37 = V_4 -> V_84 / 4 ;
V_86 = F_30 ( V_4 -> V_85 , 4 ) ;
for ( V_56 = 0 ; V_56 < V_37 && V_55 < V_57 ; V_56 ++ ) {
V_2 -> type -> V_82 ( V_2 , & V_36 , ( V_56 * 4 ) , 4 ) ;
V_55 += snprintf ( V_35 + V_55 , V_57 - V_55 ,
L_3 , F_24 ( V_36 . T_3 [ 0 ] ) ) ;
}
for ( V_56 = 0 ; V_56 < V_86 && V_55 < V_57 ; V_56 ++ ) {
V_2 -> type -> V_82 ( V_2 , & V_36 ,
V_4 -> V_84 + ( V_56 * 4 ) , 4 ) ;
V_55 += snprintf ( V_35 + V_55 , V_57 - V_55 ,
L_3 , F_24 ( V_36 . T_3 [ 0 ] ) ) ;
}
F_25 ( V_2 , V_58 , V_2 -> V_27 , L_5 , V_35 ) ;
}
#endif
if ( error && V_4 -> V_85 == 0 ) {
F_13 ( V_2 , V_58 , V_2 -> V_27 , L_6 ) ;
V_4 -> V_87 = - V_88 ;
} else if ( ( V_80 ^ V_4 -> V_39 ) & V_40 ) {
F_13 ( V_2 , V_58 , V_2 -> V_27 ,
L_7 ,
V_80 , V_4 -> V_39 ) ;
V_4 -> V_87 = - V_88 ;
} else if ( error ) {
V_2 -> type -> V_82 ( V_2 , & V_36 , V_4 -> V_84 , 4 ) ;
V_4 -> V_87 =
F_26 ( F_29 ( V_36 , V_89 ) ) ;
} else {
V_4 -> V_87 = 0 ;
}
}
static bool F_31 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
F_32 () ;
if ( ! V_2 -> type -> V_90 ( V_2 ) )
return false ;
F_19 ( & V_4 -> V_15 ) ;
F_28 ( V_2 ) ;
F_20 ( & V_4 -> V_15 ) ;
return true ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
unsigned long time , V_91 ;
unsigned int V_92 ;
int V_6 ;
V_6 = F_10 ( V_2 ) ;
if ( V_6 ) {
F_19 ( & V_4 -> V_15 ) ;
V_4 -> V_87 = V_6 ;
V_4 -> V_84 = 0 ;
V_4 -> V_85 = 0 ;
F_20 ( & V_4 -> V_15 ) ;
return 0 ;
}
V_92 = V_93 ;
V_91 = V_94 + V_95 ;
while ( 1 ) {
if ( V_92 != 0 ) {
-- V_92 ;
F_34 ( 1 ) ;
} else {
F_35 ( 1 ) ;
}
time = V_94 ;
if ( F_31 ( V_2 ) )
break;
if ( F_36 ( time , V_91 ) )
return - V_96 ;
}
return 0 ;
}
int F_10 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_4 )
return 0 ;
return V_2 -> type -> V_97 ( V_2 ) ;
}
static bool F_37 ( struct V_3 * V_4 )
{
return F_38 ( & V_4 -> V_16 ,
V_17 , V_98 ) ==
V_17 ;
}
static void F_39 ( struct V_3 * V_4 )
{
F_40 ( V_4 -> V_14 ,
F_38 ( & V_4 -> V_16 ,
V_17 , V_99 ) ==
V_17 ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
if ( F_42 ( V_4 -> V_14 , V_4 -> V_16 == V_100 ,
V_95 ) == 0 )
return - V_96 ;
if ( V_4 -> V_18 == V_19 )
return F_33 ( V_2 ) ;
return 0 ;
}
static bool F_43 ( struct V_3 * V_4 )
{
if ( F_38 ( & V_4 -> V_16 ,
V_99 , V_100 ) ==
V_99 ) {
F_44 ( & V_4 -> V_14 ) ;
return true ;
}
return false ;
}
static void F_45 ( struct V_3 * V_4 )
{
if ( V_4 -> V_18 == V_41 ) {
struct V_101 * V_102 ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_19 ( & V_4 -> V_20 ) ;
V_102 = F_46 (
& V_4 -> V_21 , struct V_101 , V_103 ) ;
if ( V_102 ) {
V_4 -> V_16 = V_98 ;
F_18 ( V_2 , V_102 -> V_32 ,
( const T_1 * ) ( V_102 + 1 ) ,
V_102 -> V_34 ) ;
F_47 ( & V_4 -> V_22 ,
V_94 + V_95 ) ;
}
F_20 ( & V_4 -> V_20 ) ;
if ( V_102 )
return;
}
V_4 -> V_16 = V_17 ;
F_44 ( & V_4 -> V_14 ) ;
}
static bool F_48 ( struct V_3 * V_4 , bool V_104 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_101 * V_102 ;
T_2 V_37 , V_86 , V_105 ;
T_1 * V_106 ;
F_49 ( V_107 ) ;
int V_6 ;
if ( F_38 ( & V_4 -> V_16 ,
V_98 , V_100 ) !=
V_98 )
return false ;
F_50 ( & V_4 -> V_15 ) ;
if ( V_104 ) {
++ V_4 -> V_39 ;
++ V_4 -> V_108 ;
V_6 = - V_96 ;
V_37 = 0 ;
V_86 = 0 ;
} else {
V_6 = V_4 -> V_87 ;
V_37 = V_4 -> V_84 ;
V_86 = V_4 -> V_85 ;
}
F_51 ( & V_4 -> V_15 ) ;
if ( ! V_104 )
F_52 ( & V_4 -> V_22 ) ;
F_50 ( & V_4 -> V_20 ) ;
V_102 = F_53 ( & V_4 -> V_21 ,
struct V_101 , V_103 ) ;
F_54 ( & V_102 -> V_103 ) ;
F_51 ( & V_4 -> V_20 ) ;
V_106 = ( T_1 * ) ( V_102 + 1 ) ;
V_2 -> type -> V_82 ( V_2 , V_106 , V_37 ,
F_55 ( V_102 -> V_109 , V_86 ) ) ;
if ( ! V_104 && V_6 && ! V_102 -> V_110 ) {
V_105 = F_55 ( sizeof( V_107 ) , V_86 ) ;
V_2 -> type -> V_82 ( V_2 , V_107 , V_37 ,
sizeof( V_107 ) ) ;
F_56 ( V_2 , V_102 -> V_32 , V_102 -> V_34 , V_107 ,
V_105 , V_6 ) ;
}
V_102 -> V_111 ( V_2 , V_102 -> V_112 , V_6 , V_106 , V_86 ) ;
F_15 ( V_102 ) ;
F_45 ( V_4 ) ;
return true ;
}
static void F_57 ( struct V_1 * V_2 , unsigned int V_39 ,
unsigned int V_113 , unsigned int V_60 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
bool V_114 = false ;
F_50 ( & V_4 -> V_15 ) ;
if ( ( V_39 ^ V_4 -> V_39 ) & V_40 ) {
if ( V_4 -> V_108 )
-- V_4 -> V_108 ;
else
F_13 ( V_2 , V_58 , V_2 -> V_27 ,
L_8
L_9 , V_39 , V_4 -> V_39 ) ;
} else {
if ( V_2 -> type -> V_43 >= 2 ) {
F_28 ( V_2 ) ;
} else {
V_4 -> V_87 = F_26 ( V_60 ) ;
V_4 -> V_84 = 4 ;
V_4 -> V_85 = V_113 ;
}
V_114 = true ;
}
F_51 ( & V_4 -> V_15 ) ;
if ( V_114 ) {
if ( ! F_48 ( V_4 , false ) )
( void ) F_43 ( V_4 ) ;
}
}
static void V_23 ( unsigned long V_115 )
{
struct V_3 * V_4 = (struct V_3 * ) V_115 ;
F_48 ( V_4 , true ) ;
}
static int
F_58 ( struct V_1 * V_2 , unsigned int V_32 , T_2 V_34 )
{
if ( V_2 -> type -> V_43 < 0 ||
( V_2 -> type -> V_43 < 2 &&
V_32 > V_116 ) )
return - V_67 ;
if ( V_34 > V_51 ||
( V_2 -> type -> V_43 < 2 &&
V_34 > V_117 ) )
return - V_118 ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 , unsigned V_32 , T_2 V_34 ,
T_1 * V_106 , T_2 V_109 ,
T_2 * V_119 , bool V_110 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
F_49 ( V_107 ) ;
int V_6 ;
if ( V_4 -> V_18 == V_19 )
V_6 = F_33 ( V_2 ) ;
else
V_6 = F_41 ( V_2 ) ;
if ( V_6 != 0 ) {
F_13 ( V_2 , V_58 , V_2 -> V_27 ,
L_10 ,
V_32 , ( int ) V_34 , V_4 -> V_18 ) ;
if ( V_4 -> V_18 == V_41 && F_31 ( V_2 ) ) {
F_13 ( V_2 , V_58 , V_2 -> V_27 ,
L_11 ) ;
V_6 = 0 ;
}
F_60 ( V_2 ) ;
F_19 ( & V_4 -> V_15 ) ;
++ V_4 -> V_39 ;
++ V_4 -> V_108 ;
F_20 ( & V_4 -> V_15 ) ;
}
if ( V_6 != 0 ) {
if ( V_119 )
* V_119 = 0 ;
} else {
T_2 V_37 , V_86 , V_105 ;
F_19 ( & V_4 -> V_15 ) ;
V_6 = V_4 -> V_87 ;
V_37 = V_4 -> V_84 ;
V_86 = V_4 -> V_85 ;
V_105 = F_55 ( sizeof( V_107 ) , V_86 ) ;
F_20 ( & V_4 -> V_15 ) ;
F_17 ( V_6 > 0 ) ;
V_2 -> type -> V_82 ( V_2 , V_106 , V_37 ,
F_55 ( V_109 , V_86 ) ) ;
if ( V_119 )
* V_119 = V_86 ;
V_2 -> type -> V_82 ( V_2 , V_107 , V_37 , V_105 ) ;
if ( V_32 == V_120 && V_6 == - V_88 ) {
} else if ( V_6 == - V_88 || V_6 == - V_63 ) {
F_13 ( V_2 , V_58 , V_2 -> V_27 , L_12 ,
- V_6 ) ;
F_61 ( V_2 , V_121 ) ;
} else if ( V_6 && ! V_110 ) {
F_56 ( V_2 , V_32 , V_34 , V_107 , V_105 ,
V_6 ) ;
}
if ( V_6 == - V_88 || V_6 == - V_63 ) {
F_62 ( V_122 ) ;
F_10 ( V_2 ) ;
V_4 -> V_24 = true ;
}
}
F_45 ( V_4 ) ;
return V_6 ;
}
static int F_63 ( struct V_1 * V_2 , unsigned V_32 ,
const T_1 * V_33 , T_2 V_34 ,
T_1 * V_106 , T_2 V_109 ,
T_2 * V_119 , bool V_110 )
{
int V_6 ;
V_6 = F_64 ( V_2 , V_32 , V_33 , V_34 ) ;
if ( V_6 ) {
if ( V_119 )
* V_119 = 0 ;
return V_6 ;
}
return F_59 ( V_2 , V_32 , V_34 , V_106 , V_109 ,
V_119 , V_110 ) ;
}
int F_65 ( struct V_1 * V_2 , unsigned V_32 ,
const T_1 * V_33 , T_2 V_34 ,
T_1 * V_106 , T_2 V_109 ,
T_2 * V_119 )
{
return F_63 ( V_2 , V_32 , V_33 , V_34 , V_106 , V_109 ,
V_119 , false ) ;
}
int F_66 ( struct V_1 * V_2 , unsigned V_32 ,
const T_1 * V_33 , T_2 V_34 ,
T_1 * V_106 , T_2 V_109 ,
T_2 * V_119 )
{
return F_63 ( V_2 , V_32 , V_33 , V_34 , V_106 , V_109 ,
V_119 , true ) ;
}
int F_64 ( struct V_1 * V_2 , unsigned V_32 ,
const T_1 * V_33 , T_2 V_34 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
int V_6 ;
V_6 = F_58 ( V_2 , V_32 , V_34 ) ;
if ( V_6 )
return V_6 ;
if ( V_2 -> V_123 )
return - V_124 ;
if ( V_4 -> V_18 == V_125 )
return - V_124 ;
F_39 ( V_4 ) ;
F_18 ( V_2 , V_32 , V_33 , V_34 ) ;
return 0 ;
}
static int F_67 ( struct V_1 * V_2 , unsigned int V_32 ,
const T_1 * V_33 , T_2 V_34 ,
T_2 V_109 ,
T_5 * V_111 ,
unsigned long V_112 , bool V_110 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
struct V_101 * V_102 ;
int V_6 ;
V_6 = F_58 ( V_2 , V_32 , V_34 ) ;
if ( V_6 )
return V_6 ;
if ( V_2 -> V_123 )
return - V_124 ;
V_102 = F_68 ( sizeof( * V_102 ) + F_69 ( F_70 ( V_34 , V_109 ) , 4 ) ,
V_126 ) ;
if ( ! V_102 )
return - V_7 ;
V_102 -> V_32 = V_32 ;
V_102 -> V_34 = V_34 ;
V_102 -> V_109 = V_109 ;
V_102 -> V_110 = V_110 ;
V_102 -> V_111 = V_111 ;
V_102 -> V_112 = V_112 ;
memcpy ( V_102 + 1 , V_33 , V_34 ) ;
F_19 ( & V_4 -> V_20 ) ;
if ( V_4 -> V_18 == V_41 ) {
F_71 ( & V_102 -> V_103 , & V_4 -> V_21 ) ;
if ( V_4 -> V_21 . V_127 == & V_102 -> V_103 &&
F_37 ( V_4 ) ) {
F_18 ( V_2 , V_32 , V_33 , V_34 ) ;
F_47 ( & V_4 -> V_22 ,
V_94 + V_95 ) ;
}
} else {
F_15 ( V_102 ) ;
V_6 = - V_124 ;
}
F_20 ( & V_4 -> V_20 ) ;
return V_6 ;
}
int
F_72 ( struct V_1 * V_2 , unsigned int V_32 ,
const T_1 * V_33 , T_2 V_34 , T_2 V_109 ,
T_5 * V_111 , unsigned long V_112 )
{
return F_67 ( V_2 , V_32 , V_33 , V_34 , V_109 , V_111 ,
V_112 , false ) ;
}
int F_73 ( struct V_1 * V_2 , unsigned int V_32 ,
const T_1 * V_33 , T_2 V_34 ,
T_2 V_109 , T_5 * V_111 ,
unsigned long V_112 )
{
return F_67 ( V_2 , V_32 , V_33 , V_34 , V_109 , V_111 ,
V_112 , true ) ;
}
int F_74 ( struct V_1 * V_2 , unsigned V_32 , T_2 V_34 ,
T_1 * V_106 , T_2 V_109 ,
T_2 * V_119 )
{
return F_59 ( V_2 , V_32 , V_34 , V_106 , V_109 ,
V_119 , false ) ;
}
int F_75 ( struct V_1 * V_2 , unsigned V_32 , T_2 V_34 ,
T_1 * V_106 , T_2 V_109 ,
T_2 * V_119 )
{
return F_59 ( V_2 , V_32 , V_34 , V_106 , V_109 ,
V_119 , true ) ;
}
void F_56 ( struct V_1 * V_2 , unsigned V_32 ,
T_2 V_34 , T_1 * V_106 ,
T_2 V_109 , int V_6 )
{
int V_128 = 0 , V_129 = 0 ;
if ( V_109 >= V_130 + 4 )
V_128 = F_76 ( V_106 , V_131 ) ;
if ( V_109 >= V_132 + 4 )
V_129 = F_76 ( V_106 , V_133 ) ;
F_13 ( V_2 , V_58 , V_2 -> V_27 ,
L_13 ,
V_32 , ( int ) V_34 , V_6 , V_128 , V_129 ) ;
}
void F_77 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( ! V_2 -> V_4 )
return;
V_4 = F_3 ( V_2 ) ;
if ( V_4 -> V_18 == V_19 || V_4 -> V_18 == V_125 )
return;
V_4 -> V_18 = V_19 ;
F_43 ( V_4 ) ;
}
void F_78 ( struct V_1 * V_2 )
{
struct V_101 * V_102 , * V_127 ;
struct V_3 * V_4 ;
if ( ! V_2 -> V_4 )
return;
V_4 = F_3 ( V_2 ) ;
F_17 ( V_4 -> V_18 == V_41 ) ;
F_52 ( & V_4 -> V_22 ) ;
if ( V_4 -> V_16 == V_98 ) {
F_33 ( V_2 ) ;
V_4 -> V_16 = V_17 ;
}
F_79 (async, next, &mcdi->async_list, list) {
V_102 -> V_111 ( V_2 , V_102 -> V_112 , - V_124 , NULL , 0 ) ;
F_54 ( & V_102 -> V_103 ) ;
F_15 ( V_102 ) ;
}
}
void F_80 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( ! V_2 -> V_4 )
return;
V_4 = F_3 ( V_2 ) ;
if ( V_4 -> V_18 == V_41 || V_4 -> V_18 == V_125 )
return;
F_39 ( V_4 ) ;
V_4 -> V_18 = V_41 ;
F_45 ( V_4 ) ;
}
static void F_81 ( struct V_1 * V_2 , int V_6 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
F_50 ( & V_4 -> V_15 ) ;
if ( F_43 ( V_4 ) ) {
if ( V_4 -> V_18 == V_41 ) {
V_4 -> V_87 = V_6 ;
V_4 -> V_84 = 0 ;
V_4 -> V_85 = 0 ;
++ V_4 -> V_108 ;
}
} else {
int V_134 ;
for ( V_134 = 0 ; V_134 < V_135 ; ++ V_134 ) {
if ( F_10 ( V_2 ) )
break;
F_34 ( V_136 ) ;
}
V_4 -> V_24 = true ;
F_61 ( V_2 , V_121 ) ;
}
F_51 ( & V_4 -> V_15 ) ;
}
static void F_82 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
F_50 ( & V_4 -> V_15 ) ;
V_2 -> V_123 = true ;
if ( F_43 ( V_4 ) ) {
if ( V_4 -> V_18 == V_41 ) {
V_4 -> V_87 = - V_88 ;
V_4 -> V_84 = 0 ;
V_4 -> V_85 = 0 ;
++ V_4 -> V_108 ;
}
}
V_4 -> V_24 = true ;
F_61 ( V_2 , V_137 ) ;
F_51 ( & V_4 -> V_15 ) ;
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
if ( F_83 ( & V_4 -> V_18 , V_125 ) == V_125 )
return;
F_84 ( V_2 , V_58 , V_2 -> V_27 , L_14 ) ;
F_61 ( V_2 , V_138 ) ;
}
void F_85 ( struct V_139 * V_140 ,
T_6 * V_141 )
{
struct V_1 * V_2 = V_140 -> V_2 ;
int V_128 = F_86 ( * V_141 , V_142 ) ;
T_3 V_143 = F_86 ( * V_141 , V_144 ) ;
switch ( V_128 ) {
case V_145 :
F_13 ( V_2 , V_58 , V_2 -> V_27 ,
L_15 , V_143 ) ;
F_81 ( V_2 , - V_63 ) ;
break;
case V_146 :
F_25 ( V_2 , V_147 , V_2 -> V_27 , L_16 ) ;
break;
case V_148 :
F_57 ( V_2 ,
F_87 ( * V_141 , V_149 ) ,
F_87 ( * V_141 , V_150 ) ,
F_87 ( * V_141 , V_151 ) ) ;
break;
case V_152 :
F_88 ( V_2 , V_141 ) ;
break;
case V_153 :
F_89 ( V_2 , V_141 ) ;
break;
case V_154 :
F_84 ( V_2 , V_58 , V_2 -> V_27 ,
L_17 , V_143 ) ;
break;
case V_155 :
case V_156 :
F_25 ( V_2 , V_58 , V_2 -> V_27 , L_18 ) ;
F_81 ( V_2 , - V_88 ) ;
break;
case V_157 :
F_25 ( V_2 , V_58 , V_2 -> V_27 , L_19 ) ;
F_82 ( V_2 ) ;
break;
case V_158 :
break;
case V_159 :
if ( V_2 -> type -> V_160 )
V_2 -> type -> V_160 ( V_2 ,
F_87 ( * V_141 , V_161 ) ) ;
break;
case V_162 :
case V_163 :
case V_164 :
F_90 ( V_2 , V_141 ) ;
break;
case V_165 :
F_91 ( V_140 , V_141 ) ;
break;
case V_166 :
case V_167 :
F_92 ( V_168 !=
V_169 ) ;
if ( ! F_87 ( * V_141 , V_170 ) )
F_93 ( V_2 ) ;
break;
case V_171 :
case V_172 :
F_13 ( V_2 , V_58 , V_2 -> V_27 ,
L_20 V_173 L_21 ,
V_128 == V_171 ? L_22 : L_23 ,
F_94 ( * V_141 ) ) ;
F_61 ( V_2 , V_174 ) ;
break;
default:
F_13 ( V_2 , V_58 , V_2 -> V_27 , L_24 ,
V_128 ) ;
}
}
void F_95 ( struct V_1 * V_2 , char * V_35 , T_2 V_175 )
{
F_96 ( V_106 , V_176 ) ;
T_2 V_177 ;
const T_7 * V_178 ;
T_2 V_179 ;
int V_6 ;
F_92 ( V_180 != 0 ) ;
V_6 = F_65 ( V_2 , V_181 , NULL , 0 ,
V_106 , sizeof( V_106 ) , & V_177 ) ;
if ( V_6 )
goto V_9;
if ( V_177 < V_176 ) {
V_6 = - V_88 ;
goto V_9;
}
V_178 = ( T_7 * ) F_97 ( V_106 , V_182 ) ;
V_179 = snprintf ( V_35 , V_175 , L_25 ,
F_98 ( V_178 [ 0 ] ) , F_98 ( V_178 [ 1 ] ) ,
F_98 ( V_178 [ 2 ] ) , F_98 ( V_178 [ 3 ] ) ) ;
if ( F_99 ( V_2 ) >= V_183 ) {
struct V_184 * V_185 = V_2 -> V_185 ;
V_179 += snprintf ( V_35 + V_179 , V_175 - V_179 , L_26 ,
V_185 -> V_186 ,
V_185 -> V_187 ) ;
if ( F_100 ( V_179 >= V_175 ) )
V_35 [ 0 ] = 0 ;
}
return;
V_9:
F_13 ( V_2 , V_26 , V_2 -> V_27 , L_27 , V_188 , V_6 ) ;
V_35 [ 0 ] = 0 ;
}
static int F_12 ( struct V_1 * V_2 , bool V_189 ,
bool * V_190 )
{
F_96 ( V_33 , V_191 ) ;
F_96 ( V_106 , V_192 ) ;
T_2 V_109 ;
int V_6 ;
F_101 ( V_33 , V_193 ,
V_189 ? 1 : 0 ) ;
F_101 ( V_33 , V_194 , 1 ) ;
F_101 ( V_33 , V_195 , V_196 ) ;
V_6 = F_66 ( V_2 , V_197 , V_33 , sizeof( V_33 ) ,
V_106 , sizeof( V_106 ) , & V_109 ) ;
if ( V_6 == - V_61 ) {
F_84 ( V_2 , V_26 , V_2 -> V_27 ,
L_28 ) ;
F_101 ( V_33 , V_195 ,
V_198 ) ;
V_6 = F_66 ( V_2 , V_197 , V_33 ,
sizeof( V_33 ) , V_106 , sizeof( V_106 ) ,
& V_109 ) ;
}
if ( V_6 ) {
F_56 ( V_2 , V_197 , sizeof( V_33 ) ,
V_106 , V_109 , V_6 ) ;
goto V_9;
}
if ( V_109 < V_199 ) {
V_6 = - V_88 ;
goto V_9;
}
if ( V_189 ) {
if ( V_109 >= V_192 ) {
V_2 -> V_4 -> V_28 =
F_76 ( V_106 ,
V_200 ) ;
} else {
V_2 -> V_4 -> V_28 =
1 << V_201 |
1 << V_202 |
( F_102 ( V_2 ) == 0 ) <<
V_29 ;
}
}
if ( V_190 != NULL )
* V_190 = F_76 ( V_106 , V_203 ) ;
return 0 ;
V_9:
F_13 ( V_2 , V_26 , V_2 -> V_27 , L_27 , V_188 , V_6 ) ;
return V_6 ;
}
int F_103 ( struct V_1 * V_2 , T_8 * V_204 ,
T_9 * V_205 , T_3 * V_206 )
{
F_96 ( V_106 , V_207 ) ;
T_2 V_109 , V_56 ;
int V_208 = F_102 ( V_2 ) ;
int V_6 ;
F_92 ( V_209 != 0 ) ;
F_92 ( V_210 & 1 ) ;
F_92 ( V_211 & 1 ) ;
V_6 = F_65 ( V_2 , V_212 , NULL , 0 ,
V_106 , sizeof( V_106 ) , & V_109 ) ;
if ( V_6 )
goto V_9;
if ( V_109 < V_213 ) {
V_6 = - V_88 ;
goto V_9;
}
if ( V_204 )
F_104 ( V_204 ,
V_208 ?
F_97 ( V_106 , V_214 ) :
F_97 ( V_106 , V_215 ) ) ;
if ( V_205 ) {
for ( V_56 = 0 ;
V_56 < F_105 ( V_109 ,
V_216 ) ;
V_56 ++ )
V_205 [ V_56 ] = F_106 (
V_106 , V_216 , V_56 ) ;
for (; V_56 < V_217 ; V_56 ++ )
V_205 [ V_56 ] = 0 ;
}
if ( V_206 ) {
if ( V_208 )
* V_206 = F_76 ( V_106 ,
V_218 ) ;
else
* V_206 = F_76 ( V_106 ,
V_219 ) ;
}
return 0 ;
V_9:
F_13 ( V_2 , V_58 , V_2 -> V_27 , L_29 ,
V_188 , V_6 , ( int ) V_109 ) ;
return V_6 ;
}
int F_107 ( struct V_1 * V_2 , bool V_220 , bool V_221 , T_3 V_222 )
{
F_96 ( V_33 , V_223 ) ;
T_3 V_224 = 0 ;
int V_6 ;
if ( V_221 )
V_224 |= V_225 ;
if ( V_220 )
V_224 |= V_226 ;
F_101 ( V_33 , V_227 , V_224 ) ;
F_101 ( V_33 , V_228 , V_222 ) ;
F_92 ( V_229 != 0 ) ;
V_6 = F_65 ( V_2 , V_230 , V_33 , sizeof( V_33 ) ,
NULL , 0 , NULL ) ;
return V_6 ;
}
int F_108 ( struct V_1 * V_2 , T_3 * V_231 )
{
F_96 ( V_106 , V_232 ) ;
T_2 V_109 ;
int V_6 ;
F_92 ( V_233 != 0 ) ;
V_6 = F_65 ( V_2 , V_234 , NULL , 0 ,
V_106 , sizeof( V_106 ) , & V_109 ) ;
if ( V_6 )
goto V_9;
if ( V_109 < V_232 ) {
V_6 = - V_88 ;
goto V_9;
}
* V_231 = F_76 ( V_106 , V_235 ) ;
return 0 ;
V_9:
F_13 ( V_2 , V_58 , V_2 -> V_27 , L_27 ,
V_188 , V_6 ) ;
return V_6 ;
}
int F_109 ( struct V_1 * V_2 , unsigned int type ,
T_2 * V_236 , T_2 * V_237 ,
bool * V_238 )
{
F_96 ( V_33 , V_239 ) ;
F_96 ( V_106 , V_240 ) ;
T_2 V_109 ;
int V_6 ;
F_101 ( V_33 , V_241 , type ) ;
V_6 = F_65 ( V_2 , V_242 , V_33 , sizeof( V_33 ) ,
V_106 , sizeof( V_106 ) , & V_109 ) ;
if ( V_6 )
goto V_9;
if ( V_109 < V_240 ) {
V_6 = - V_88 ;
goto V_9;
}
* V_236 = F_76 ( V_106 , V_243 ) ;
* V_237 = F_76 ( V_106 , V_244 ) ;
* V_238 = ! ! ( F_76 ( V_106 , V_245 ) &
( 1 << V_246 ) ) ;
return 0 ;
V_9:
F_13 ( V_2 , V_58 , V_2 -> V_27 , L_27 , V_188 , V_6 ) ;
return V_6 ;
}
static int F_110 ( struct V_1 * V_2 , unsigned int type )
{
F_96 ( V_33 , V_247 ) ;
F_96 ( V_106 , V_248 ) ;
int V_6 ;
F_101 ( V_33 , V_249 , type ) ;
V_6 = F_65 ( V_2 , V_250 , V_33 , sizeof( V_33 ) ,
V_106 , sizeof( V_106 ) , NULL ) ;
if ( V_6 )
return V_6 ;
switch ( F_76 ( V_106 , V_251 ) ) {
case V_252 :
case V_253 :
return 0 ;
default:
return - V_88 ;
}
}
int F_111 ( struct V_1 * V_2 )
{
T_3 V_254 ;
unsigned int type ;
int V_6 ;
V_6 = F_108 ( V_2 , & V_254 ) ;
if ( V_6 )
goto V_11;
type = 0 ;
while ( V_254 != 0 ) {
if ( V_254 & 1 ) {
V_6 = F_110 ( V_2 , type ) ;
if ( V_6 )
goto V_25;
}
type ++ ;
V_254 >>= 1 ;
}
return 0 ;
V_25:
F_13 ( V_2 , V_58 , V_2 -> V_27 , L_30 ,
V_188 , type ) ;
V_11:
F_13 ( V_2 , V_58 , V_2 -> V_27 , L_27 , V_188 , V_6 ) ;
return V_6 ;
}
static int F_112 ( struct V_1 * V_2 )
{
F_96 ( V_33 , V_255 ) ;
F_96 ( V_106 , V_256 ) ;
unsigned int V_257 , V_258 ;
const char * V_259 ;
T_2 V_109 ;
int V_260 ;
int V_6 ;
V_260 = 2 ;
do {
F_101 ( V_33 , V_261 , 1 ) ;
V_6 = F_66 ( V_2 , V_262 ,
V_33 , V_255 ,
V_106 , sizeof( V_106 ) , & V_109 ) ;
if ( V_6 == - V_61 )
return 0 ;
} while ( ( V_6 == - V_63 || V_6 == - V_88 ) && V_260 -- > 0 );
if ( V_6 ) {
F_56 ( V_2 , V_262 ,
V_255 , V_106 ,
V_109 , V_6 ) ;
return V_6 ;
}
if ( V_109 < V_256 )
return - V_88 ;
V_257 = F_76 ( V_106 , V_263 ) ;
if ( V_257 == V_264 )
return 0 ;
V_259 = ( V_257 == V_265 )
? L_31
: ( V_257 == V_266 )
? L_32
: ( V_257 == V_267 )
? L_33
: L_34 ;
F_13 ( V_2 , V_58 , V_2 -> V_27 ,
L_35 , V_259 ,
F_76 ( V_106 , V_268 ) ,
F_76 ( V_106 , V_269 ) ) ;
for ( V_258 = 0 ;
V_258 < V_270 ;
V_258 ++ )
F_13 ( V_2 , V_58 , V_2 -> V_27 , L_36 ,
1 + V_258 ,
F_113 ( V_106 , V_271 ,
V_258 ) ) ;
return 1 ;
}
static int F_114 ( struct V_1 * V_2 )
{
F_96 ( V_33 , V_272 ) ;
int V_6 ;
F_92 ( V_273 != 0 ) ;
F_101 ( V_33 , V_274 ,
V_275 ) ;
V_6 = F_66 ( V_2 , V_120 , V_33 , V_272 ,
NULL , 0 , NULL ) ;
if ( V_6 == - V_88 )
V_6 = 0 ;
if ( V_6 )
F_56 ( V_2 , V_120 , V_272 ,
NULL , 0 , V_6 ) ;
return V_6 ;
}
int F_11 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_112 ( V_2 ) ;
if ( V_6 <= 0 )
return V_6 ;
return F_114 ( V_2 ) ;
}
void F_115 ( struct V_1 * V_2 , enum V_276 V_18 )
{
F_96 ( V_33 , V_277 ) ;
int V_6 ;
F_92 ( V_278 != V_279 ) ;
F_92 ( V_280 != V_281 ) ;
F_92 ( V_282 != V_283 ) ;
F_92 ( V_284 != 0 ) ;
F_101 ( V_33 , V_285 , V_18 ) ;
V_6 = F_65 ( V_2 , V_286 , V_33 , sizeof( V_33 ) ,
NULL , 0 , NULL ) ;
}
static int F_116 ( struct V_1 * V_2 )
{
F_96 ( V_33 , V_287 ) ;
int V_6 ;
F_92 ( V_288 != 0 ) ;
F_117 ( V_33 , V_289 ,
V_290 , 1 ) ;
V_6 = F_65 ( V_2 , V_291 , V_33 , sizeof( V_33 ) ,
NULL , 0 , NULL ) ;
return V_6 ;
}
static int F_118 ( struct V_1 * V_2 )
{
F_96 ( V_33 , V_272 ) ;
int V_6 ;
F_92 ( V_273 != 0 ) ;
F_101 ( V_33 , V_274 , 0 ) ;
V_6 = F_65 ( V_2 , V_120 , V_33 , sizeof( V_33 ) ,
NULL , 0 , NULL ) ;
if ( V_6 == - V_88 )
return 0 ;
if ( V_6 == 0 )
V_6 = - V_88 ;
return V_6 ;
}
enum V_292 F_119 ( enum V_292 V_259 )
{
return V_293 ;
}
int F_120 ( struct V_1 * V_2 , enum V_292 V_294 )
{
int V_6 ;
if ( V_294 == V_138 ) {
V_6 = F_121 ( V_2 -> V_295 ) ;
if ( V_6 )
return V_6 ;
if ( V_2 -> V_4 ) {
struct V_3 * V_4 = F_3 ( V_2 ) ;
V_4 -> V_18 = V_19 ;
}
return 0 ;
}
V_6 = F_11 ( V_2 ) ;
if ( V_6 )
return V_6 ;
if ( V_294 == V_296 )
return 0 ;
else if ( V_294 == V_297 )
return F_118 ( V_2 ) ;
else
return F_116 ( V_2 ) ;
}
static int F_122 ( struct V_1 * V_2 , T_3 type ,
const T_8 * V_298 , int * V_299 )
{
F_96 ( V_33 , V_300 ) ;
F_96 ( V_106 , V_301 ) ;
T_2 V_109 ;
int V_6 ;
F_101 ( V_33 , V_302 , type ) ;
F_101 ( V_33 , V_303 ,
V_304 ) ;
F_104 ( F_97 ( V_33 , V_305 ) , V_298 ) ;
V_6 = F_65 ( V_2 , V_306 , V_33 , sizeof( V_33 ) ,
V_106 , sizeof( V_106 ) , & V_109 ) ;
if ( V_6 )
goto V_9;
if ( V_109 < V_301 ) {
V_6 = - V_88 ;
goto V_9;
}
* V_299 = ( int ) F_76 ( V_106 , V_307 ) ;
return 0 ;
V_9:
* V_299 = - 1 ;
F_13 ( V_2 , V_58 , V_2 -> V_27 , L_27 , V_188 , V_6 ) ;
return V_6 ;
}
int
F_123 ( struct V_1 * V_2 , const T_8 * V_298 , int * V_299 )
{
return F_122 ( V_2 , V_308 , V_298 , V_299 ) ;
}
int F_124 ( struct V_1 * V_2 , int * V_299 )
{
F_96 ( V_106 , V_309 ) ;
T_2 V_109 ;
int V_6 ;
V_6 = F_65 ( V_2 , V_310 , NULL , 0 ,
V_106 , sizeof( V_106 ) , & V_109 ) ;
if ( V_6 )
goto V_9;
if ( V_109 < V_309 ) {
V_6 = - V_88 ;
goto V_9;
}
* V_299 = ( int ) F_76 ( V_106 , V_311 ) ;
return 0 ;
V_9:
* V_299 = - 1 ;
F_13 ( V_2 , V_58 , V_2 -> V_27 , L_27 , V_188 , V_6 ) ;
return V_6 ;
}
int F_125 ( struct V_1 * V_2 , int V_312 )
{
F_96 ( V_33 , V_313 ) ;
int V_6 ;
F_101 ( V_33 , V_314 , ( T_3 ) V_312 ) ;
V_6 = F_65 ( V_2 , V_315 , V_33 , sizeof( V_33 ) ,
NULL , 0 , NULL ) ;
return V_6 ;
}
int F_126 ( struct V_1 * V_2 )
{
struct V_139 * V_140 ;
struct V_316 * V_317 ;
F_96 ( V_33 ,
F_127 ( V_318 ) ) ;
int V_6 , V_134 ;
F_92 ( V_318 >
V_319 ) ;
V_134 = 0 ;
F_128 (channel, efx) {
F_129 (rx_queue, channel) {
if ( V_317 -> V_320 ) {
V_317 -> V_320 = false ;
F_130 ( & V_2 -> V_321 ) ;
F_131 (
V_33 , V_322 ,
V_134 , F_132 ( V_317 ) ) ;
V_134 ++ ;
}
}
}
V_6 = F_65 ( V_2 , V_323 , V_33 ,
F_127 ( V_134 ) , NULL , 0 , NULL ) ;
F_100 ( V_6 < 0 ) ;
return V_6 ;
}
int F_133 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_65 ( V_2 , V_324 , NULL , 0 , NULL , 0 , NULL ) ;
return V_6 ;
}
int F_134 ( struct V_1 * V_2 , T_3 type , bool V_325 ,
unsigned int * V_257 )
{
F_96 ( V_33 , V_326 ) ;
F_96 ( V_106 , V_327 ) ;
T_2 V_109 ;
int V_6 ;
F_92 ( V_328 != 0 ) ;
F_101 ( V_33 , V_329 , type ) ;
F_101 ( V_33 , V_330 , V_325 ) ;
V_6 = F_65 ( V_2 , V_331 , V_33 , sizeof( V_33 ) ,
V_106 , sizeof( V_106 ) , & V_109 ) ;
if ( V_6 )
return V_6 ;
if ( ! V_257 )
return 0 ;
if ( V_109 >= V_327 )
* V_257 = F_76 ( V_106 , V_332 ) ;
else
* V_257 = 0 ;
return 0 ;
}
int F_135 ( struct V_1 * V_2 , unsigned int * V_333 ,
unsigned int * V_334 )
{
F_96 ( V_106 , V_335 ) ;
T_2 V_109 ;
int V_6 ;
V_6 = F_65 ( V_2 , V_336 , NULL , 0 ,
V_106 , sizeof( V_106 ) , & V_109 ) ;
if ( V_6 )
goto V_9;
if ( V_109 < V_335 ) {
V_6 = - V_88 ;
goto V_9;
}
if ( V_333 )
* V_333 = F_76 ( V_106 , V_337 ) ;
if ( V_334 )
* V_334 = F_76 ( V_106 , V_338 ) ;
return 0 ;
V_9:
F_136 ( V_2 , V_58 , V_6 == - V_69 ? V_339 : V_340 ,
V_2 -> V_27 , L_27 , V_188 , V_6 ) ;
return V_6 ;
}
static int F_137 ( struct V_1 * V_2 , unsigned int type )
{
F_96 ( V_33 , V_341 ) ;
int V_6 ;
F_101 ( V_33 , V_342 , type ) ;
F_92 ( V_343 != 0 ) ;
V_6 = F_65 ( V_2 , V_344 , V_33 , sizeof( V_33 ) ,
NULL , 0 , NULL ) ;
return V_6 ;
}
static int F_138 ( struct V_1 * V_2 , unsigned int type ,
T_10 V_179 , T_8 * V_345 , T_2 V_346 )
{
F_96 ( V_33 , V_347 ) ;
F_96 ( V_106 ,
F_139 ( V_348 ) ) ;
T_2 V_109 ;
int V_6 ;
F_101 ( V_33 , V_349 , type ) ;
F_101 ( V_33 , V_350 , V_179 ) ;
F_101 ( V_33 , V_351 , V_346 ) ;
V_6 = F_65 ( V_2 , V_352 , V_33 , sizeof( V_33 ) ,
V_106 , sizeof( V_106 ) , & V_109 ) ;
if ( V_6 )
return V_6 ;
memcpy ( V_345 , F_97 ( V_106 , V_353 ) , V_346 ) ;
return 0 ;
}
static int F_140 ( struct V_1 * V_2 , unsigned int type ,
T_10 V_179 , const T_8 * V_345 , T_2 V_346 )
{
F_96 ( V_33 ,
F_141 ( V_348 ) ) ;
int V_6 ;
F_101 ( V_33 , V_354 , type ) ;
F_101 ( V_33 , V_355 , V_179 ) ;
F_101 ( V_33 , V_356 , V_346 ) ;
memcpy ( F_97 ( V_33 , V_357 ) , V_345 , V_346 ) ;
F_92 ( V_358 != 0 ) ;
V_6 = F_65 ( V_2 , V_359 , V_33 ,
F_69 ( F_141 ( V_346 ) , 4 ) ,
NULL , 0 , NULL ) ;
return V_6 ;
}
static int F_142 ( struct V_1 * V_2 , unsigned int type ,
T_10 V_179 , T_2 V_346 )
{
F_96 ( V_33 , V_360 ) ;
int V_6 ;
F_101 ( V_33 , V_361 , type ) ;
F_101 ( V_33 , V_362 , V_179 ) ;
F_101 ( V_33 , V_363 , V_346 ) ;
F_92 ( V_364 != 0 ) ;
V_6 = F_65 ( V_2 , V_365 , V_33 , sizeof( V_33 ) ,
NULL , 0 , NULL ) ;
return V_6 ;
}
static int F_143 ( struct V_1 * V_2 , unsigned int type )
{
F_96 ( V_33 , V_366 ) ;
int V_6 ;
F_101 ( V_33 , V_367 , type ) ;
F_92 ( V_368 != 0 ) ;
V_6 = F_65 ( V_2 , V_369 , V_33 , sizeof( V_33 ) ,
NULL , 0 , NULL ) ;
return V_6 ;
}
int F_144 ( struct V_370 * V_371 , T_10 V_372 ,
T_2 V_175 , T_2 * V_373 , T_8 * V_345 )
{
struct V_374 * V_375 = F_145 ( V_371 ) ;
struct V_1 * V_2 = V_371 -> V_376 ;
T_10 V_179 = V_372 ;
T_10 V_377 = F_146 ( T_10 , V_372 + V_175 , V_371 -> V_378 ) ;
T_2 V_379 ;
int V_6 = 0 ;
while ( V_179 < V_377 ) {
V_379 = F_146 ( T_2 , V_377 - V_179 , V_348 ) ;
V_6 = F_138 ( V_2 , V_375 -> V_380 , V_179 ,
V_345 , V_379 ) ;
if ( V_6 )
goto V_381;
V_179 += V_379 ;
V_345 += V_379 ;
}
V_381:
* V_373 = V_179 - V_372 ;
return V_6 ;
}
int F_147 ( struct V_370 * V_371 , T_10 V_372 , T_2 V_175 )
{
struct V_374 * V_375 = F_145 ( V_371 ) ;
struct V_1 * V_2 = V_371 -> V_376 ;
T_10 V_179 = V_372 & ~ ( ( T_10 ) ( V_371 -> V_382 - 1 ) ) ;
T_10 V_377 = F_146 ( T_10 , V_372 + V_175 , V_371 -> V_378 ) ;
T_2 V_379 = V_375 -> V_383 . V_371 . V_382 ;
int V_6 = 0 ;
if ( ! V_375 -> V_384 ) {
V_6 = F_137 ( V_2 , V_375 -> V_380 ) ;
if ( V_6 )
goto V_381;
V_375 -> V_384 = true ;
}
while ( V_179 < V_377 ) {
V_6 = F_142 ( V_2 , V_375 -> V_380 , V_179 ,
V_379 ) ;
if ( V_6 )
goto V_381;
V_179 += V_379 ;
}
V_381:
return V_6 ;
}
int F_148 ( struct V_370 * V_371 , T_10 V_372 ,
T_2 V_175 , T_2 * V_373 , const T_8 * V_345 )
{
struct V_374 * V_375 = F_145 ( V_371 ) ;
struct V_1 * V_2 = V_371 -> V_376 ;
T_10 V_179 = V_372 ;
T_10 V_377 = F_146 ( T_10 , V_372 + V_175 , V_371 -> V_378 ) ;
T_2 V_379 ;
int V_6 = 0 ;
if ( ! V_375 -> V_384 ) {
V_6 = F_137 ( V_2 , V_375 -> V_380 ) ;
if ( V_6 )
goto V_381;
V_375 -> V_384 = true ;
}
while ( V_179 < V_377 ) {
V_379 = F_146 ( T_2 , V_377 - V_179 , V_348 ) ;
V_6 = F_140 ( V_2 , V_375 -> V_380 , V_179 ,
V_345 , V_379 ) ;
if ( V_6 )
goto V_381;
V_179 += V_379 ;
V_345 += V_379 ;
}
V_381:
* V_373 = V_179 - V_372 ;
return V_6 ;
}
int F_149 ( struct V_370 * V_371 )
{
struct V_374 * V_375 = F_145 ( V_371 ) ;
struct V_1 * V_2 = V_371 -> V_376 ;
int V_6 = 0 ;
if ( V_375 -> V_384 ) {
V_375 -> V_384 = false ;
V_6 = F_143 ( V_2 , V_375 -> V_380 ) ;
}
return V_6 ;
}
void F_150 ( struct V_385 * V_375 )
{
struct V_374 * V_386 =
F_151 ( V_375 , struct V_374 , V_383 ) ;
struct V_1 * V_2 = V_375 -> V_371 . V_376 ;
snprintf ( V_375 -> T_4 , sizeof( V_375 -> T_4 ) , L_37 ,
V_2 -> T_4 , V_375 -> V_387 , V_386 -> V_388 ) ;
}
