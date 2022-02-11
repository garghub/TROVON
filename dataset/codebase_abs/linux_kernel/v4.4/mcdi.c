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
V_6 = F_10 ( V_2 ) ;
if ( V_6 )
break;
F_34 ( V_136 ) ;
}
if ( ! V_6 && V_2 -> type -> V_137 )
V_2 -> type -> V_137 ( V_2 ) ;
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
F_61 ( V_2 , V_138 ) ;
F_51 ( & V_4 -> V_15 ) ;
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
if ( F_83 ( & V_4 -> V_18 , V_125 ) == V_125 )
return;
F_84 ( V_2 , V_58 , V_2 -> V_27 , L_14 ) ;
F_61 ( V_2 , V_139 ) ;
}
void F_85 ( struct V_140 * V_141 ,
T_6 * V_142 )
{
struct V_1 * V_2 = V_141 -> V_2 ;
int V_128 = F_86 ( * V_142 , V_143 ) ;
T_3 V_144 = F_86 ( * V_142 , V_145 ) ;
switch ( V_128 ) {
case V_146 :
F_13 ( V_2 , V_58 , V_2 -> V_27 ,
L_15 , V_144 ) ;
F_81 ( V_2 , - V_63 ) ;
break;
case V_147 :
F_25 ( V_2 , V_148 , V_2 -> V_27 , L_16 ) ;
break;
case V_149 :
F_57 ( V_2 ,
F_87 ( * V_142 , V_150 ) ,
F_87 ( * V_142 , V_151 ) ,
F_87 ( * V_142 , V_152 ) ) ;
break;
case V_153 :
F_88 ( V_2 , V_142 ) ;
break;
case V_154 :
F_89 ( V_2 , V_142 ) ;
break;
case V_155 :
F_84 ( V_2 , V_58 , V_2 -> V_27 ,
L_17 , V_144 ) ;
break;
case V_156 :
case V_157 :
F_25 ( V_2 , V_58 , V_2 -> V_27 , L_18 ) ;
F_81 ( V_2 , - V_88 ) ;
break;
case V_158 :
F_25 ( V_2 , V_58 , V_2 -> V_27 , L_19 ) ;
F_82 ( V_2 ) ;
break;
case V_159 :
break;
case V_160 :
if ( V_2 -> type -> V_161 )
V_2 -> type -> V_161 ( V_2 ,
F_87 ( * V_142 , V_162 ) ) ;
break;
case V_163 :
case V_164 :
case V_165 :
F_90 ( V_2 , V_142 ) ;
break;
case V_166 :
F_91 ( V_141 , V_142 ) ;
break;
case V_167 :
case V_168 :
F_92 ( V_169 !=
V_170 ) ;
if ( ! F_87 ( * V_142 , V_171 ) )
F_93 ( V_2 ) ;
break;
case V_172 :
case V_173 :
F_13 ( V_2 , V_58 , V_2 -> V_27 ,
L_20 V_174 L_21 ,
V_128 == V_172 ? L_22 : L_23 ,
F_94 ( * V_142 ) ) ;
F_61 ( V_2 , V_175 ) ;
break;
default:
F_13 ( V_2 , V_58 , V_2 -> V_27 , L_24 ,
V_128 ) ;
}
}
void F_95 ( struct V_1 * V_2 , char * V_35 , T_2 V_176 )
{
F_96 ( V_106 , V_177 ) ;
T_2 V_178 ;
const T_7 * V_179 ;
T_2 V_180 ;
int V_6 ;
F_92 ( V_181 != 0 ) ;
V_6 = F_65 ( V_2 , V_182 , NULL , 0 ,
V_106 , sizeof( V_106 ) , & V_178 ) ;
if ( V_6 )
goto V_9;
if ( V_178 < V_177 ) {
V_6 = - V_88 ;
goto V_9;
}
V_179 = ( T_7 * ) F_97 ( V_106 , V_183 ) ;
V_180 = snprintf ( V_35 , V_176 , L_25 ,
F_98 ( V_179 [ 0 ] ) , F_98 ( V_179 [ 1 ] ) ,
F_98 ( V_179 [ 2 ] ) , F_98 ( V_179 [ 3 ] ) ) ;
if ( F_99 ( V_2 ) >= V_184 ) {
struct V_185 * V_186 = V_2 -> V_186 ;
V_180 += snprintf ( V_35 + V_180 , V_176 - V_180 , L_26 ,
V_186 -> V_187 ,
V_186 -> V_188 ) ;
if ( F_100 ( V_180 >= V_176 ) )
V_35 [ 0 ] = 0 ;
}
return;
V_9:
F_13 ( V_2 , V_26 , V_2 -> V_27 , L_27 , V_189 , V_6 ) ;
V_35 [ 0 ] = 0 ;
}
static int F_12 ( struct V_1 * V_2 , bool V_190 ,
bool * V_191 )
{
F_96 ( V_33 , V_192 ) ;
F_96 ( V_106 , V_193 ) ;
T_2 V_109 ;
int V_6 ;
F_101 ( V_33 , V_194 ,
V_190 ? 1 : 0 ) ;
F_101 ( V_33 , V_195 , 1 ) ;
F_101 ( V_33 , V_196 , V_197 ) ;
V_6 = F_66 ( V_2 , V_198 , V_33 , sizeof( V_33 ) ,
V_106 , sizeof( V_106 ) , & V_109 ) ;
if ( V_6 == - V_61 ) {
F_84 ( V_2 , V_26 , V_2 -> V_27 ,
L_28 ) ;
F_101 ( V_33 , V_196 ,
V_199 ) ;
V_6 = F_66 ( V_2 , V_198 , V_33 ,
sizeof( V_33 ) , V_106 , sizeof( V_106 ) ,
& V_109 ) ;
}
if ( V_6 ) {
F_56 ( V_2 , V_198 , sizeof( V_33 ) ,
V_106 , V_109 , V_6 ) ;
goto V_9;
}
if ( V_109 < V_200 ) {
V_6 = - V_88 ;
goto V_9;
}
if ( V_190 ) {
if ( V_109 >= V_193 ) {
V_2 -> V_4 -> V_28 =
F_76 ( V_106 ,
V_201 ) ;
} else {
V_2 -> V_4 -> V_28 =
1 << V_202 |
1 << V_203 |
( F_102 ( V_2 ) == 0 ) <<
V_29 ;
}
}
if ( V_191 != NULL )
* V_191 = F_76 ( V_106 , V_204 ) ;
return 0 ;
V_9:
F_13 ( V_2 , V_26 , V_2 -> V_27 , L_27 , V_189 , V_6 ) ;
return V_6 ;
}
int F_103 ( struct V_1 * V_2 , T_8 * V_205 ,
T_9 * V_206 , T_3 * V_207 )
{
F_96 ( V_106 , V_208 ) ;
T_2 V_109 , V_56 ;
int V_209 = F_102 ( V_2 ) ;
int V_6 ;
F_92 ( V_210 != 0 ) ;
F_92 ( V_211 & 1 ) ;
F_92 ( V_212 & 1 ) ;
V_6 = F_65 ( V_2 , V_213 , NULL , 0 ,
V_106 , sizeof( V_106 ) , & V_109 ) ;
if ( V_6 )
goto V_9;
if ( V_109 < V_214 ) {
V_6 = - V_88 ;
goto V_9;
}
if ( V_205 )
F_104 ( V_205 ,
V_209 ?
F_97 ( V_106 , V_215 ) :
F_97 ( V_106 , V_216 ) ) ;
if ( V_206 ) {
for ( V_56 = 0 ;
V_56 < F_105 ( V_109 ,
V_217 ) ;
V_56 ++ )
V_206 [ V_56 ] = F_106 (
V_106 , V_217 , V_56 ) ;
for (; V_56 < V_218 ; V_56 ++ )
V_206 [ V_56 ] = 0 ;
}
if ( V_207 ) {
if ( V_209 )
* V_207 = F_76 ( V_106 ,
V_219 ) ;
else
* V_207 = F_76 ( V_106 ,
V_220 ) ;
}
return 0 ;
V_9:
F_13 ( V_2 , V_58 , V_2 -> V_27 , L_29 ,
V_189 , V_6 , ( int ) V_109 ) ;
return V_6 ;
}
int F_107 ( struct V_1 * V_2 , bool V_221 , bool V_222 , T_3 V_223 )
{
F_96 ( V_33 , V_224 ) ;
T_3 V_225 = 0 ;
int V_6 ;
if ( V_222 )
V_225 |= V_226 ;
if ( V_221 )
V_225 |= V_227 ;
F_101 ( V_33 , V_228 , V_225 ) ;
F_101 ( V_33 , V_229 , V_223 ) ;
F_92 ( V_230 != 0 ) ;
V_6 = F_65 ( V_2 , V_231 , V_33 , sizeof( V_33 ) ,
NULL , 0 , NULL ) ;
return V_6 ;
}
int F_108 ( struct V_1 * V_2 , T_3 * V_232 )
{
F_96 ( V_106 , V_233 ) ;
T_2 V_109 ;
int V_6 ;
F_92 ( V_234 != 0 ) ;
V_6 = F_65 ( V_2 , V_235 , NULL , 0 ,
V_106 , sizeof( V_106 ) , & V_109 ) ;
if ( V_6 )
goto V_9;
if ( V_109 < V_233 ) {
V_6 = - V_88 ;
goto V_9;
}
* V_232 = F_76 ( V_106 , V_236 ) ;
return 0 ;
V_9:
F_13 ( V_2 , V_58 , V_2 -> V_27 , L_27 ,
V_189 , V_6 ) ;
return V_6 ;
}
int F_109 ( struct V_1 * V_2 , unsigned int type ,
T_2 * V_237 , T_2 * V_238 ,
bool * V_239 )
{
F_96 ( V_33 , V_240 ) ;
F_96 ( V_106 , V_241 ) ;
T_2 V_109 ;
int V_6 ;
F_101 ( V_33 , V_242 , type ) ;
V_6 = F_65 ( V_2 , V_243 , V_33 , sizeof( V_33 ) ,
V_106 , sizeof( V_106 ) , & V_109 ) ;
if ( V_6 )
goto V_9;
if ( V_109 < V_241 ) {
V_6 = - V_88 ;
goto V_9;
}
* V_237 = F_76 ( V_106 , V_244 ) ;
* V_238 = F_76 ( V_106 , V_245 ) ;
* V_239 = ! ! ( F_76 ( V_106 , V_246 ) &
( 1 << V_247 ) ) ;
return 0 ;
V_9:
F_13 ( V_2 , V_58 , V_2 -> V_27 , L_27 , V_189 , V_6 ) ;
return V_6 ;
}
static int F_110 ( struct V_1 * V_2 , unsigned int type )
{
F_96 ( V_33 , V_248 ) ;
F_96 ( V_106 , V_249 ) ;
int V_6 ;
F_101 ( V_33 , V_250 , type ) ;
V_6 = F_65 ( V_2 , V_251 , V_33 , sizeof( V_33 ) ,
V_106 , sizeof( V_106 ) , NULL ) ;
if ( V_6 )
return V_6 ;
switch ( F_76 ( V_106 , V_252 ) ) {
case V_253 :
case V_254 :
return 0 ;
default:
return - V_88 ;
}
}
int F_111 ( struct V_1 * V_2 )
{
T_3 V_255 ;
unsigned int type ;
int V_6 ;
V_6 = F_108 ( V_2 , & V_255 ) ;
if ( V_6 )
goto V_11;
type = 0 ;
while ( V_255 != 0 ) {
if ( V_255 & 1 ) {
V_6 = F_110 ( V_2 , type ) ;
if ( V_6 )
goto V_25;
}
type ++ ;
V_255 >>= 1 ;
}
return 0 ;
V_25:
F_13 ( V_2 , V_58 , V_2 -> V_27 , L_30 ,
V_189 , type ) ;
V_11:
F_13 ( V_2 , V_58 , V_2 -> V_27 , L_27 , V_189 , V_6 ) ;
return V_6 ;
}
static int F_112 ( struct V_1 * V_2 )
{
F_96 ( V_33 , V_256 ) ;
F_96 ( V_106 , V_257 ) ;
unsigned int V_258 , V_259 ;
const char * V_260 ;
T_2 V_109 ;
int V_261 ;
int V_6 ;
V_261 = 2 ;
do {
F_101 ( V_33 , V_262 , 1 ) ;
V_6 = F_66 ( V_2 , V_263 ,
V_33 , V_256 ,
V_106 , sizeof( V_106 ) , & V_109 ) ;
if ( V_6 == - V_61 )
return 0 ;
} while ( ( V_6 == - V_63 || V_6 == - V_88 ) && V_261 -- > 0 );
if ( V_6 ) {
F_56 ( V_2 , V_263 ,
V_256 , V_106 ,
V_109 , V_6 ) ;
return V_6 ;
}
if ( V_109 < V_257 )
return - V_88 ;
V_258 = F_76 ( V_106 , V_264 ) ;
if ( V_258 == V_265 )
return 0 ;
V_260 = ( V_258 == V_266 )
? L_31
: ( V_258 == V_267 )
? L_32
: ( V_258 == V_268 )
? L_33
: L_34 ;
F_13 ( V_2 , V_58 , V_2 -> V_27 ,
L_35 , V_260 ,
F_76 ( V_106 , V_269 ) ,
F_76 ( V_106 , V_270 ) ) ;
for ( V_259 = 0 ;
V_259 < V_271 ;
V_259 ++ )
F_13 ( V_2 , V_58 , V_2 -> V_27 , L_36 ,
1 + V_259 ,
F_113 ( V_106 , V_272 ,
V_259 ) ) ;
return 1 ;
}
static int F_114 ( struct V_1 * V_2 )
{
F_96 ( V_33 , V_273 ) ;
int V_6 ;
F_92 ( V_274 != 0 ) ;
F_101 ( V_33 , V_275 ,
V_276 ) ;
V_6 = F_66 ( V_2 , V_120 , V_33 , V_273 ,
NULL , 0 , NULL ) ;
if ( V_6 == - V_88 )
V_6 = 0 ;
if ( V_6 )
F_56 ( V_2 , V_120 , V_273 ,
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
void F_115 ( struct V_1 * V_2 , enum V_277 V_18 )
{
F_96 ( V_33 , V_278 ) ;
int V_6 ;
F_92 ( V_279 != V_280 ) ;
F_92 ( V_281 != V_282 ) ;
F_92 ( V_283 != V_284 ) ;
F_92 ( V_285 != 0 ) ;
F_101 ( V_33 , V_286 , V_18 ) ;
V_6 = F_65 ( V_2 , V_287 , V_33 , sizeof( V_33 ) ,
NULL , 0 , NULL ) ;
}
static int F_116 ( struct V_1 * V_2 )
{
F_96 ( V_33 , V_288 ) ;
int V_6 ;
F_92 ( V_289 != 0 ) ;
F_117 ( V_33 , V_290 ,
V_291 , 1 ) ;
V_6 = F_65 ( V_2 , V_292 , V_33 , sizeof( V_33 ) ,
NULL , 0 , NULL ) ;
return V_6 ;
}
static int F_118 ( struct V_1 * V_2 )
{
F_96 ( V_33 , V_273 ) ;
int V_6 ;
F_92 ( V_274 != 0 ) ;
F_101 ( V_33 , V_275 , 0 ) ;
V_6 = F_65 ( V_2 , V_120 , V_33 , sizeof( V_33 ) ,
NULL , 0 , NULL ) ;
if ( V_6 == - V_88 )
return 0 ;
if ( V_6 == 0 )
V_6 = - V_88 ;
return V_6 ;
}
enum V_293 F_119 ( enum V_293 V_260 )
{
return V_294 ;
}
int F_120 ( struct V_1 * V_2 , enum V_293 V_295 )
{
int V_6 ;
if ( V_295 == V_139 ) {
V_6 = F_121 ( V_2 -> V_296 ) ;
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
if ( V_295 == V_297 )
return 0 ;
else if ( V_295 == V_298 )
return F_118 ( V_2 ) ;
else
return F_116 ( V_2 ) ;
}
static int F_122 ( struct V_1 * V_2 , T_3 type ,
const T_8 * V_299 , int * V_300 )
{
F_96 ( V_33 , V_301 ) ;
F_96 ( V_106 , V_302 ) ;
T_2 V_109 ;
int V_6 ;
F_101 ( V_33 , V_303 , type ) ;
F_101 ( V_33 , V_304 ,
V_305 ) ;
F_104 ( F_97 ( V_33 , V_306 ) , V_299 ) ;
V_6 = F_65 ( V_2 , V_307 , V_33 , sizeof( V_33 ) ,
V_106 , sizeof( V_106 ) , & V_109 ) ;
if ( V_6 )
goto V_9;
if ( V_109 < V_302 ) {
V_6 = - V_88 ;
goto V_9;
}
* V_300 = ( int ) F_76 ( V_106 , V_308 ) ;
return 0 ;
V_9:
* V_300 = - 1 ;
F_13 ( V_2 , V_58 , V_2 -> V_27 , L_27 , V_189 , V_6 ) ;
return V_6 ;
}
int
F_123 ( struct V_1 * V_2 , const T_8 * V_299 , int * V_300 )
{
return F_122 ( V_2 , V_309 , V_299 , V_300 ) ;
}
int F_124 ( struct V_1 * V_2 , int * V_300 )
{
F_96 ( V_106 , V_310 ) ;
T_2 V_109 ;
int V_6 ;
V_6 = F_65 ( V_2 , V_311 , NULL , 0 ,
V_106 , sizeof( V_106 ) , & V_109 ) ;
if ( V_6 )
goto V_9;
if ( V_109 < V_310 ) {
V_6 = - V_88 ;
goto V_9;
}
* V_300 = ( int ) F_76 ( V_106 , V_312 ) ;
return 0 ;
V_9:
* V_300 = - 1 ;
F_13 ( V_2 , V_58 , V_2 -> V_27 , L_27 , V_189 , V_6 ) ;
return V_6 ;
}
int F_125 ( struct V_1 * V_2 , int V_313 )
{
F_96 ( V_33 , V_314 ) ;
int V_6 ;
F_101 ( V_33 , V_315 , ( T_3 ) V_313 ) ;
V_6 = F_65 ( V_2 , V_316 , V_33 , sizeof( V_33 ) ,
NULL , 0 , NULL ) ;
return V_6 ;
}
int F_126 ( struct V_1 * V_2 )
{
struct V_140 * V_141 ;
struct V_317 * V_318 ;
F_96 ( V_33 ,
F_127 ( V_319 ) ) ;
int V_6 , V_134 ;
F_92 ( V_319 >
V_320 ) ;
V_134 = 0 ;
F_128 (channel, efx) {
F_129 (rx_queue, channel) {
if ( V_318 -> V_321 ) {
V_318 -> V_321 = false ;
F_130 ( & V_2 -> V_322 ) ;
F_131 (
V_33 , V_323 ,
V_134 , F_132 ( V_318 ) ) ;
V_134 ++ ;
}
}
}
V_6 = F_65 ( V_2 , V_324 , V_33 ,
F_127 ( V_134 ) , NULL , 0 , NULL ) ;
F_100 ( V_6 < 0 ) ;
return V_6 ;
}
int F_133 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_65 ( V_2 , V_325 , NULL , 0 , NULL , 0 , NULL ) ;
return V_6 ;
}
int F_134 ( struct V_1 * V_2 , T_3 type , bool V_326 ,
unsigned int * V_258 )
{
F_96 ( V_33 , V_327 ) ;
F_96 ( V_106 , V_328 ) ;
T_2 V_109 ;
int V_6 ;
F_92 ( V_329 != 0 ) ;
F_101 ( V_33 , V_330 , type ) ;
F_101 ( V_33 , V_331 , V_326 ) ;
V_6 = F_65 ( V_2 , V_332 , V_33 , sizeof( V_33 ) ,
V_106 , sizeof( V_106 ) , & V_109 ) ;
if ( V_6 )
return V_6 ;
if ( ! V_258 )
return 0 ;
if ( V_109 >= V_328 )
* V_258 = F_76 ( V_106 , V_333 ) ;
else
* V_258 = 0 ;
return 0 ;
}
int F_135 ( struct V_1 * V_2 , unsigned int * V_334 ,
unsigned int * V_335 )
{
F_96 ( V_106 , V_336 ) ;
T_2 V_109 ;
int V_6 ;
V_6 = F_65 ( V_2 , V_337 , NULL , 0 ,
V_106 , sizeof( V_106 ) , & V_109 ) ;
if ( V_6 )
goto V_9;
if ( V_109 < V_336 ) {
V_6 = - V_88 ;
goto V_9;
}
if ( V_334 )
* V_334 = F_76 ( V_106 , V_338 ) ;
if ( V_335 )
* V_335 = F_76 ( V_106 , V_339 ) ;
return 0 ;
V_9:
F_136 ( V_2 , V_58 , V_6 == - V_69 ? V_340 : V_341 ,
V_2 -> V_27 , L_27 , V_189 , V_6 ) ;
return V_6 ;
}
static int F_137 ( struct V_1 * V_2 , unsigned int type )
{
F_96 ( V_33 , V_342 ) ;
int V_6 ;
F_101 ( V_33 , V_343 , type ) ;
F_92 ( V_344 != 0 ) ;
V_6 = F_65 ( V_2 , V_345 , V_33 , sizeof( V_33 ) ,
NULL , 0 , NULL ) ;
return V_6 ;
}
static int F_138 ( struct V_1 * V_2 , unsigned int type ,
T_10 V_180 , T_8 * V_346 , T_2 V_347 )
{
F_96 ( V_33 , V_348 ) ;
F_96 ( V_106 ,
F_139 ( V_349 ) ) ;
T_2 V_109 ;
int V_6 ;
F_101 ( V_33 , V_350 , type ) ;
F_101 ( V_33 , V_351 , V_180 ) ;
F_101 ( V_33 , V_352 , V_347 ) ;
V_6 = F_65 ( V_2 , V_353 , V_33 , sizeof( V_33 ) ,
V_106 , sizeof( V_106 ) , & V_109 ) ;
if ( V_6 )
return V_6 ;
memcpy ( V_346 , F_97 ( V_106 , V_354 ) , V_347 ) ;
return 0 ;
}
static int F_140 ( struct V_1 * V_2 , unsigned int type ,
T_10 V_180 , const T_8 * V_346 , T_2 V_347 )
{
F_96 ( V_33 ,
F_141 ( V_349 ) ) ;
int V_6 ;
F_101 ( V_33 , V_355 , type ) ;
F_101 ( V_33 , V_356 , V_180 ) ;
F_101 ( V_33 , V_357 , V_347 ) ;
memcpy ( F_97 ( V_33 , V_358 ) , V_346 , V_347 ) ;
F_92 ( V_359 != 0 ) ;
V_6 = F_65 ( V_2 , V_360 , V_33 ,
F_69 ( F_141 ( V_347 ) , 4 ) ,
NULL , 0 , NULL ) ;
return V_6 ;
}
static int F_142 ( struct V_1 * V_2 , unsigned int type ,
T_10 V_180 , T_2 V_347 )
{
F_96 ( V_33 , V_361 ) ;
int V_6 ;
F_101 ( V_33 , V_362 , type ) ;
F_101 ( V_33 , V_363 , V_180 ) ;
F_101 ( V_33 , V_364 , V_347 ) ;
F_92 ( V_365 != 0 ) ;
V_6 = F_65 ( V_2 , V_366 , V_33 , sizeof( V_33 ) ,
NULL , 0 , NULL ) ;
return V_6 ;
}
static int F_143 ( struct V_1 * V_2 , unsigned int type )
{
F_96 ( V_33 , V_367 ) ;
int V_6 ;
F_101 ( V_33 , V_368 , type ) ;
F_92 ( V_369 != 0 ) ;
V_6 = F_65 ( V_2 , V_370 , V_33 , sizeof( V_33 ) ,
NULL , 0 , NULL ) ;
return V_6 ;
}
int F_144 ( struct V_371 * V_372 , T_10 V_373 ,
T_2 V_176 , T_2 * V_374 , T_8 * V_346 )
{
struct V_375 * V_376 = F_145 ( V_372 ) ;
struct V_1 * V_2 = V_372 -> V_377 ;
T_10 V_180 = V_373 ;
T_10 V_378 = F_146 ( T_10 , V_373 + V_176 , V_372 -> V_379 ) ;
T_2 V_380 ;
int V_6 = 0 ;
while ( V_180 < V_378 ) {
V_380 = F_146 ( T_2 , V_378 - V_180 , V_349 ) ;
V_6 = F_138 ( V_2 , V_376 -> V_381 , V_180 ,
V_346 , V_380 ) ;
if ( V_6 )
goto V_382;
V_180 += V_380 ;
V_346 += V_380 ;
}
V_382:
* V_374 = V_180 - V_373 ;
return V_6 ;
}
int F_147 ( struct V_371 * V_372 , T_10 V_373 , T_2 V_176 )
{
struct V_375 * V_376 = F_145 ( V_372 ) ;
struct V_1 * V_2 = V_372 -> V_377 ;
T_10 V_180 = V_373 & ~ ( ( T_10 ) ( V_372 -> V_383 - 1 ) ) ;
T_10 V_378 = F_146 ( T_10 , V_373 + V_176 , V_372 -> V_379 ) ;
T_2 V_380 = V_376 -> V_384 . V_372 . V_383 ;
int V_6 = 0 ;
if ( ! V_376 -> V_385 ) {
V_6 = F_137 ( V_2 , V_376 -> V_381 ) ;
if ( V_6 )
goto V_382;
V_376 -> V_385 = true ;
}
while ( V_180 < V_378 ) {
V_6 = F_142 ( V_2 , V_376 -> V_381 , V_180 ,
V_380 ) ;
if ( V_6 )
goto V_382;
V_180 += V_380 ;
}
V_382:
return V_6 ;
}
int F_148 ( struct V_371 * V_372 , T_10 V_373 ,
T_2 V_176 , T_2 * V_374 , const T_8 * V_346 )
{
struct V_375 * V_376 = F_145 ( V_372 ) ;
struct V_1 * V_2 = V_372 -> V_377 ;
T_10 V_180 = V_373 ;
T_10 V_378 = F_146 ( T_10 , V_373 + V_176 , V_372 -> V_379 ) ;
T_2 V_380 ;
int V_6 = 0 ;
if ( ! V_376 -> V_385 ) {
V_6 = F_137 ( V_2 , V_376 -> V_381 ) ;
if ( V_6 )
goto V_382;
V_376 -> V_385 = true ;
}
while ( V_180 < V_378 ) {
V_380 = F_146 ( T_2 , V_378 - V_180 , V_349 ) ;
V_6 = F_140 ( V_2 , V_376 -> V_381 , V_180 ,
V_346 , V_380 ) ;
if ( V_6 )
goto V_382;
V_180 += V_380 ;
V_346 += V_380 ;
}
V_382:
* V_374 = V_180 - V_373 ;
return V_6 ;
}
int F_149 ( struct V_371 * V_372 )
{
struct V_375 * V_376 = F_145 ( V_372 ) ;
struct V_1 * V_2 = V_372 -> V_377 ;
int V_6 = 0 ;
if ( V_376 -> V_385 ) {
V_376 -> V_385 = false ;
V_6 = F_143 ( V_2 , V_376 -> V_381 ) ;
}
return V_6 ;
}
void F_150 ( struct V_386 * V_376 )
{
struct V_375 * V_387 =
F_151 ( V_376 , struct V_375 , V_384 ) ;
struct V_1 * V_2 = V_376 -> V_372 . V_377 ;
snprintf ( V_376 -> T_4 , sizeof( V_376 -> T_4 ) , L_37 ,
V_2 -> T_4 , V_376 -> V_388 , V_387 -> V_389 ) ;
}
