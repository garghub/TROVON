int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
bool V_5 ;
int V_6 ;
V_2 -> V_4 = F_2 ( sizeof( * V_2 -> V_4 ) , V_7 ) ;
if ( ! V_2 -> V_4 )
return - V_8 ;
V_4 = F_3 ( V_2 ) ;
V_4 -> V_2 = V_2 ;
F_4 ( & V_4 -> V_9 ) ;
F_5 ( & V_4 -> V_10 ) ;
V_4 -> V_11 = V_12 ;
V_4 -> V_13 = V_14 ;
F_5 ( & V_4 -> V_15 ) ;
F_6 ( & V_4 -> V_16 ) ;
F_7 ( & V_4 -> V_17 , V_18 ,
( unsigned long ) V_4 ) ;
( void ) F_8 ( V_2 ) ;
V_4 -> V_19 = true ;
V_6 = F_9 ( V_2 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_10 ( V_2 , true , & V_5 ) ;
if ( V_6 ) {
F_11 ( V_2 , V_20 , V_2 -> V_21 ,
L_1 ) ;
return V_6 ;
}
if ( V_5 )
F_11 ( V_2 , V_20 , V_2 -> V_21 ,
L_2 ) ;
if ( V_2 -> V_4 -> V_22 &
( 1 << V_23 ) )
V_2 -> V_24 = V_2 ;
return 0 ;
}
void F_12 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_4 )
return;
F_13 ( V_2 -> V_4 -> V_25 . V_11 != V_12 ) ;
F_10 ( V_2 , false , NULL ) ;
F_14 ( V_2 -> V_4 ) ;
}
static void F_15 ( struct V_1 * V_2 , unsigned V_26 ,
const T_1 * V_27 , T_2 V_28 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
T_1 V_29 [ 2 ] ;
T_2 V_30 ;
T_3 V_31 , V_32 ;
F_13 ( V_4 -> V_11 == V_12 ) ;
F_16 ( & V_4 -> V_10 ) ;
++ V_4 -> V_32 ;
F_17 ( & V_4 -> V_10 ) ;
V_32 = V_4 -> V_32 & V_33 ;
V_31 = 0 ;
if ( V_4 -> V_13 == V_34 )
V_31 |= V_35 ;
if ( V_2 -> type -> V_36 == 1 ) {
F_18 ( V_29 [ 0 ] ,
V_37 , 0 ,
V_38 , 1 ,
V_39 , V_26 ,
V_40 , V_28 ,
V_41 , V_32 ,
V_42 , V_31 ,
V_43 , ! V_4 -> V_19 ) ;
V_30 = 4 ;
} else {
F_13 ( V_28 > V_44 ) ;
F_18 ( V_29 [ 0 ] ,
V_37 , 0 ,
V_38 , 1 ,
V_39 , V_45 ,
V_40 , 0 ,
V_41 , V_32 ,
V_42 , V_31 ,
V_43 , ! V_4 -> V_19 ) ;
F_19 ( V_29 [ 1 ] ,
V_46 , V_26 ,
V_47 , V_28 ) ;
V_30 = 8 ;
}
V_2 -> type -> V_48 ( V_2 , V_29 , V_30 , V_27 , V_28 ) ;
V_4 -> V_19 = false ;
}
static int F_20 ( unsigned int V_49 )
{
switch ( V_49 ) {
case 0 :
return 0 ;
#define F_21 ( T_4 ) \
case MC_CMD_ERR_ ## name: \
return -name;
F_21 ( V_50 ) ;
F_21 ( V_51 ) ;
F_21 ( V_52 ) ;
F_21 ( V_53 ) ;
F_21 ( V_54 ) ;
F_21 ( V_55 ) ;
F_21 ( V_56 ) ;
F_21 ( V_57 ) ;
F_21 ( V_58 ) ;
F_21 ( V_59 ) ;
F_21 ( V_60 ) ;
F_21 ( V_61 ) ;
#undef F_21
case V_62 :
return - V_63 ;
case V_64 :
return - V_65 ;
case V_66 :
return - V_67 ;
default:
return - V_68 ;
}
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
unsigned int V_69 , V_70 , error ;
T_1 V_29 ;
V_2 -> type -> V_71 ( V_2 , & V_29 , 0 , 4 ) ;
V_69 = F_23 ( V_29 , V_41 ) ;
V_70 = F_23 ( V_29 , V_39 ) ;
error = F_23 ( V_29 , V_72 ) ;
if ( V_70 != V_45 ) {
V_4 -> V_73 = 4 ;
V_4 -> V_74 = F_23 ( V_29 , V_40 ) ;
} else {
V_2 -> type -> V_71 ( V_2 , & V_29 , 4 , 4 ) ;
V_4 -> V_73 = 8 ;
V_4 -> V_74 =
F_23 ( V_29 , V_47 ) ;
}
if ( error && V_4 -> V_74 == 0 ) {
F_11 ( V_2 , V_75 , V_2 -> V_21 , L_3 ) ;
V_4 -> V_76 = - V_77 ;
} else if ( ( V_69 ^ V_4 -> V_32 ) & V_33 ) {
F_11 ( V_2 , V_75 , V_2 -> V_21 ,
L_4 ,
V_69 , V_4 -> V_32 ) ;
V_4 -> V_76 = - V_77 ;
} else if ( error ) {
V_2 -> type -> V_71 ( V_2 , & V_29 , V_4 -> V_73 , 4 ) ;
V_4 -> V_76 =
F_20 ( F_23 ( V_29 , V_78 ) ) ;
} else {
V_4 -> V_76 = 0 ;
}
}
static bool F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
F_25 () ;
if ( ! V_2 -> type -> V_79 ( V_2 ) )
return false ;
F_16 ( & V_4 -> V_10 ) ;
F_22 ( V_2 ) ;
F_17 ( & V_4 -> V_10 ) ;
return true ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
unsigned long time , V_80 ;
unsigned int V_81 ;
int V_6 ;
V_6 = F_8 ( V_2 ) ;
if ( V_6 ) {
F_16 ( & V_4 -> V_10 ) ;
V_4 -> V_76 = V_6 ;
V_4 -> V_73 = 0 ;
V_4 -> V_74 = 0 ;
F_17 ( & V_4 -> V_10 ) ;
return 0 ;
}
V_81 = V_82 ;
V_80 = V_83 + V_84 ;
while ( 1 ) {
if ( V_81 != 0 ) {
-- V_81 ;
F_27 ( 1 ) ;
} else {
F_28 ( 1 ) ;
}
time = V_83 ;
if ( F_24 ( V_2 ) )
break;
if ( F_29 ( time , V_80 ) )
return - V_85 ;
}
return 0 ;
}
int F_8 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_4 )
return 0 ;
return V_2 -> type -> V_86 ( V_2 ) ;
}
static bool F_30 ( struct V_3 * V_4 )
{
return F_31 ( & V_4 -> V_11 ,
V_12 , V_87 ) ==
V_12 ;
}
static void F_32 ( struct V_3 * V_4 )
{
F_33 ( V_4 -> V_9 ,
F_31 ( & V_4 -> V_11 ,
V_12 , V_88 ) ==
V_12 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
if ( F_35 ( V_4 -> V_9 , V_4 -> V_11 == V_89 ,
V_84 ) == 0 )
return - V_85 ;
if ( V_4 -> V_13 == V_14 )
return F_26 ( V_2 ) ;
return 0 ;
}
static bool F_36 ( struct V_3 * V_4 )
{
if ( F_31 ( & V_4 -> V_11 ,
V_88 , V_89 ) ==
V_88 ) {
F_37 ( & V_4 -> V_9 ) ;
return true ;
}
return false ;
}
static void F_38 ( struct V_3 * V_4 )
{
if ( V_4 -> V_13 == V_34 ) {
struct V_90 * V_91 ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_16 ( & V_4 -> V_15 ) ;
V_91 = F_39 (
& V_4 -> V_16 , struct V_90 , V_92 ) ;
if ( V_91 ) {
V_4 -> V_11 = V_87 ;
F_15 ( V_2 , V_91 -> V_26 ,
( const T_1 * ) ( V_91 + 1 ) ,
V_91 -> V_28 ) ;
F_40 ( & V_4 -> V_17 ,
V_83 + V_84 ) ;
}
F_17 ( & V_4 -> V_15 ) ;
if ( V_91 )
return;
}
V_4 -> V_11 = V_12 ;
F_37 ( & V_4 -> V_9 ) ;
}
static bool F_41 ( struct V_3 * V_4 , bool V_93 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_90 * V_91 ;
T_2 V_30 , V_94 , V_95 ;
T_1 * V_96 ;
F_42 ( V_97 , 0 ) ;
int V_6 ;
if ( F_31 ( & V_4 -> V_11 ,
V_87 , V_89 ) !=
V_87 )
return false ;
F_43 ( & V_4 -> V_10 ) ;
if ( V_93 ) {
++ V_4 -> V_32 ;
++ V_4 -> V_98 ;
V_6 = - V_85 ;
V_30 = 0 ;
V_94 = 0 ;
} else {
V_6 = V_4 -> V_76 ;
V_30 = V_4 -> V_73 ;
V_94 = V_4 -> V_74 ;
}
F_44 ( & V_4 -> V_10 ) ;
if ( ! V_93 )
F_45 ( & V_4 -> V_17 ) ;
F_43 ( & V_4 -> V_15 ) ;
V_91 = F_46 ( & V_4 -> V_16 ,
struct V_90 , V_92 ) ;
F_47 ( & V_91 -> V_92 ) ;
F_44 ( & V_4 -> V_15 ) ;
V_96 = ( T_1 * ) ( V_91 + 1 ) ;
V_2 -> type -> V_71 ( V_2 , V_96 , V_30 ,
F_48 ( V_91 -> V_99 , V_94 ) ) ;
if ( ! V_93 && V_6 && ! V_91 -> V_100 ) {
V_95 = F_48 ( sizeof( V_97 ) , V_94 ) ;
V_2 -> type -> V_71 ( V_2 , V_97 , V_30 ,
sizeof( V_97 ) ) ;
F_49 ( V_2 , V_91 -> V_26 , V_91 -> V_28 , V_97 ,
V_95 , V_6 ) ;
}
V_91 -> V_101 ( V_2 , V_91 -> V_102 , V_6 , V_96 , V_94 ) ;
F_14 ( V_91 ) ;
F_38 ( V_4 ) ;
return true ;
}
static void F_50 ( struct V_1 * V_2 , unsigned int V_32 ,
unsigned int V_103 , unsigned int V_49 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
bool V_104 = false ;
F_43 ( & V_4 -> V_10 ) ;
if ( ( V_32 ^ V_4 -> V_32 ) & V_33 ) {
if ( V_4 -> V_98 )
-- V_4 -> V_98 ;
else
F_11 ( V_2 , V_75 , V_2 -> V_21 ,
L_5
L_6 , V_32 , V_4 -> V_32 ) ;
} else {
if ( V_2 -> type -> V_36 >= 2 ) {
F_22 ( V_2 ) ;
} else {
V_4 -> V_76 = F_20 ( V_49 ) ;
V_4 -> V_73 = 4 ;
V_4 -> V_74 = V_103 ;
}
V_104 = true ;
}
F_44 ( & V_4 -> V_10 ) ;
if ( V_104 ) {
if ( ! F_41 ( V_4 , false ) )
( void ) F_36 ( V_4 ) ;
}
}
static void V_18 ( unsigned long V_105 )
{
struct V_3 * V_4 = (struct V_3 * ) V_105 ;
F_41 ( V_4 , true ) ;
}
static int
F_51 ( struct V_1 * V_2 , unsigned int V_26 , T_2 V_28 )
{
if ( V_2 -> type -> V_36 < 0 ||
( V_2 -> type -> V_36 < 2 &&
V_26 > V_106 ) )
return - V_56 ;
if ( V_28 > V_44 ||
( V_2 -> type -> V_36 < 2 &&
V_28 > V_107 ) )
return - V_108 ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 , unsigned V_26 , T_2 V_28 ,
T_1 * V_96 , T_2 V_99 ,
T_2 * V_109 , bool V_100 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
F_42 ( V_97 , 0 ) ;
int V_6 ;
if ( V_4 -> V_13 == V_14 )
V_6 = F_26 ( V_2 ) ;
else
V_6 = F_34 ( V_2 ) ;
if ( V_6 != 0 ) {
F_11 ( V_2 , V_75 , V_2 -> V_21 ,
L_7 ,
V_26 , ( int ) V_28 , V_4 -> V_13 ) ;
if ( V_4 -> V_13 == V_34 && F_24 ( V_2 ) ) {
F_11 ( V_2 , V_75 , V_2 -> V_21 ,
L_8 ) ;
V_6 = 0 ;
}
F_53 ( V_2 ) ;
F_16 ( & V_4 -> V_10 ) ;
++ V_4 -> V_32 ;
++ V_4 -> V_98 ;
F_17 ( & V_4 -> V_10 ) ;
}
if ( V_6 != 0 ) {
if ( V_109 )
* V_109 = 0 ;
} else {
T_2 V_30 , V_94 , V_95 ;
F_16 ( & V_4 -> V_10 ) ;
V_6 = V_4 -> V_76 ;
V_30 = V_4 -> V_73 ;
V_94 = V_4 -> V_74 ;
V_95 = F_48 ( sizeof( V_97 ) , V_94 ) ;
F_17 ( & V_4 -> V_10 ) ;
F_13 ( V_6 > 0 ) ;
V_2 -> type -> V_71 ( V_2 , V_96 , V_30 ,
F_48 ( V_99 , V_94 ) ) ;
if ( V_109 )
* V_109 = V_94 ;
V_2 -> type -> V_71 ( V_2 , V_97 , V_30 , V_95 ) ;
if ( V_26 == V_110 && V_6 == - V_77 ) {
} else if ( V_6 == - V_77 || V_6 == - V_52 ) {
F_11 ( V_2 , V_75 , V_2 -> V_21 , L_9 ,
- V_6 ) ;
F_54 ( V_2 , V_111 ) ;
} else if ( V_6 && ! V_100 ) {
F_49 ( V_2 , V_26 , V_28 , V_97 , V_95 ,
V_6 ) ;
}
if ( V_6 == - V_77 || V_6 == - V_52 ) {
F_55 ( V_112 ) ;
F_8 ( V_2 ) ;
V_4 -> V_19 = true ;
}
}
F_38 ( V_4 ) ;
return V_6 ;
}
static int F_56 ( struct V_1 * V_2 , unsigned V_26 ,
const T_1 * V_27 , T_2 V_28 ,
T_1 * V_96 , T_2 V_99 ,
T_2 * V_109 , bool V_100 )
{
int V_6 ;
V_6 = F_57 ( V_2 , V_26 , V_27 , V_28 ) ;
if ( V_6 ) {
if ( V_109 )
* V_109 = 0 ;
return V_6 ;
}
return F_52 ( V_2 , V_26 , V_28 , V_96 , V_99 ,
V_109 , V_100 ) ;
}
int F_58 ( struct V_1 * V_2 , unsigned V_26 ,
const T_1 * V_27 , T_2 V_28 ,
T_1 * V_96 , T_2 V_99 ,
T_2 * V_109 )
{
return F_56 ( V_2 , V_26 , V_27 , V_28 , V_96 , V_99 ,
V_109 , false ) ;
}
int F_59 ( struct V_1 * V_2 , unsigned V_26 ,
const T_1 * V_27 , T_2 V_28 ,
T_1 * V_96 , T_2 V_99 ,
T_2 * V_109 )
{
return F_56 ( V_2 , V_26 , V_27 , V_28 , V_96 , V_99 ,
V_109 , true ) ;
}
int F_57 ( struct V_1 * V_2 , unsigned V_26 ,
const T_1 * V_27 , T_2 V_28 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
int V_6 ;
V_6 = F_51 ( V_2 , V_26 , V_28 ) ;
if ( V_6 )
return V_6 ;
if ( V_2 -> V_113 )
return - V_114 ;
if ( V_4 -> V_13 == V_115 )
return - V_114 ;
F_32 ( V_4 ) ;
F_15 ( V_2 , V_26 , V_27 , V_28 ) ;
return 0 ;
}
static int F_60 ( struct V_1 * V_2 , unsigned int V_26 ,
const T_1 * V_27 , T_2 V_28 ,
T_2 V_99 ,
T_5 * V_101 ,
unsigned long V_102 , bool V_100 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
struct V_90 * V_91 ;
int V_6 ;
V_6 = F_51 ( V_2 , V_26 , V_28 ) ;
if ( V_6 )
return V_6 ;
if ( V_2 -> V_113 )
return - V_114 ;
V_91 = F_61 ( sizeof( * V_91 ) + F_62 ( F_63 ( V_28 , V_99 ) , 4 ) ,
V_116 ) ;
if ( ! V_91 )
return - V_8 ;
V_91 -> V_26 = V_26 ;
V_91 -> V_28 = V_28 ;
V_91 -> V_99 = V_99 ;
V_91 -> V_100 = V_100 ;
V_91 -> V_101 = V_101 ;
V_91 -> V_102 = V_102 ;
memcpy ( V_91 + 1 , V_27 , V_28 ) ;
F_16 ( & V_4 -> V_15 ) ;
if ( V_4 -> V_13 == V_34 ) {
F_64 ( & V_91 -> V_92 , & V_4 -> V_16 ) ;
if ( V_4 -> V_16 . V_117 == & V_91 -> V_92 &&
F_30 ( V_4 ) ) {
F_15 ( V_2 , V_26 , V_27 , V_28 ) ;
F_40 ( & V_4 -> V_17 ,
V_83 + V_84 ) ;
}
} else {
F_14 ( V_91 ) ;
V_6 = - V_114 ;
}
F_17 ( & V_4 -> V_15 ) ;
return V_6 ;
}
int
F_65 ( struct V_1 * V_2 , unsigned int V_26 ,
const T_1 * V_27 , T_2 V_28 , T_2 V_99 ,
T_5 * V_101 , unsigned long V_102 )
{
return F_60 ( V_2 , V_26 , V_27 , V_28 , V_99 , V_101 ,
V_102 , false ) ;
}
int F_66 ( struct V_1 * V_2 , unsigned int V_26 ,
const T_1 * V_27 , T_2 V_28 ,
T_2 V_99 , T_5 * V_101 ,
unsigned long V_102 )
{
return F_60 ( V_2 , V_26 , V_27 , V_28 , V_99 , V_101 ,
V_102 , true ) ;
}
int F_67 ( struct V_1 * V_2 , unsigned V_26 , T_2 V_28 ,
T_1 * V_96 , T_2 V_99 ,
T_2 * V_109 )
{
return F_52 ( V_2 , V_26 , V_28 , V_96 , V_99 ,
V_109 , false ) ;
}
int F_68 ( struct V_1 * V_2 , unsigned V_26 , T_2 V_28 ,
T_1 * V_96 , T_2 V_99 ,
T_2 * V_109 )
{
return F_52 ( V_2 , V_26 , V_28 , V_96 , V_99 ,
V_109 , true ) ;
}
void F_49 ( struct V_1 * V_2 , unsigned V_26 ,
T_2 V_28 , T_1 * V_96 ,
T_2 V_99 , int V_6 )
{
int V_118 = 0 , V_119 = 0 ;
if ( V_99 >= V_120 + 4 )
V_118 = F_69 ( V_96 , V_121 ) ;
if ( V_99 >= V_122 + 4 )
V_119 = F_69 ( V_96 , V_123 ) ;
F_11 ( V_2 , V_75 , V_2 -> V_21 ,
L_10 ,
V_26 , ( int ) V_28 , V_6 , V_118 , V_119 ) ;
}
void F_70 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( ! V_2 -> V_4 )
return;
V_4 = F_3 ( V_2 ) ;
if ( V_4 -> V_13 == V_14 || V_4 -> V_13 == V_115 )
return;
V_4 -> V_13 = V_14 ;
F_36 ( V_4 ) ;
}
void F_71 ( struct V_1 * V_2 )
{
struct V_90 * V_91 , * V_117 ;
struct V_3 * V_4 ;
if ( ! V_2 -> V_4 )
return;
V_4 = F_3 ( V_2 ) ;
F_13 ( V_4 -> V_13 == V_34 ) ;
F_45 ( & V_4 -> V_17 ) ;
if ( V_4 -> V_11 == V_87 ) {
F_26 ( V_2 ) ;
V_4 -> V_11 = V_12 ;
}
F_72 (async, next, &mcdi->async_list, list) {
V_91 -> V_101 ( V_2 , V_91 -> V_102 , - V_114 , NULL , 0 ) ;
F_47 ( & V_91 -> V_92 ) ;
F_14 ( V_91 ) ;
}
}
void F_73 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( ! V_2 -> V_4 )
return;
V_4 = F_3 ( V_2 ) ;
if ( V_4 -> V_13 == V_34 || V_4 -> V_13 == V_115 )
return;
F_32 ( V_4 ) ;
V_4 -> V_13 = V_34 ;
F_38 ( V_4 ) ;
}
static void F_74 ( struct V_1 * V_2 , int V_6 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
F_43 ( & V_4 -> V_10 ) ;
if ( F_36 ( V_4 ) ) {
if ( V_4 -> V_13 == V_34 ) {
V_4 -> V_76 = V_6 ;
V_4 -> V_73 = 0 ;
V_4 -> V_74 = 0 ;
++ V_4 -> V_98 ;
}
} else {
int V_124 ;
for ( V_124 = 0 ; V_124 < V_125 ; ++ V_124 ) {
if ( F_8 ( V_2 ) )
break;
F_27 ( V_126 ) ;
}
V_4 -> V_19 = true ;
F_54 ( V_2 , V_111 ) ;
}
F_44 ( & V_4 -> V_10 ) ;
}
static void F_75 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
F_43 ( & V_4 -> V_10 ) ;
V_2 -> V_113 = true ;
if ( F_36 ( V_4 ) ) {
if ( V_4 -> V_13 == V_34 ) {
V_4 -> V_76 = - V_77 ;
V_4 -> V_73 = 0 ;
V_4 -> V_74 = 0 ;
++ V_4 -> V_98 ;
}
}
V_4 -> V_19 = true ;
F_54 ( V_2 , V_127 ) ;
F_44 ( & V_4 -> V_10 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
if ( F_76 ( & V_4 -> V_13 , V_115 ) == V_115 )
return;
F_77 ( V_2 , V_75 , V_2 -> V_21 , L_11 ) ;
F_54 ( V_2 , V_128 ) ;
}
void F_78 ( struct V_129 * V_130 ,
T_6 * V_131 )
{
struct V_1 * V_2 = V_130 -> V_2 ;
int V_118 = F_79 ( * V_131 , V_132 ) ;
T_3 V_133 = F_79 ( * V_131 , V_134 ) ;
switch ( V_118 ) {
case V_135 :
F_11 ( V_2 , V_75 , V_2 -> V_21 ,
L_12 , V_133 ) ;
F_74 ( V_2 , - V_52 ) ;
break;
case V_136 :
F_80 ( V_2 , V_137 , V_2 -> V_21 , L_13 ) ;
break;
case V_138 :
F_50 ( V_2 ,
F_81 ( * V_131 , V_139 ) ,
F_81 ( * V_131 , V_140 ) ,
F_81 ( * V_131 , V_141 ) ) ;
break;
case V_142 :
F_82 ( V_2 , V_131 ) ;
break;
case V_143 :
F_83 ( V_2 , V_131 ) ;
break;
case V_144 :
F_77 ( V_2 , V_75 , V_2 -> V_21 ,
L_14 , V_133 ) ;
break;
case V_145 :
case V_146 :
F_80 ( V_2 , V_75 , V_2 -> V_21 , L_15 ) ;
F_74 ( V_2 , - V_77 ) ;
break;
case V_147 :
F_80 ( V_2 , V_75 , V_2 -> V_21 , L_16 ) ;
F_75 ( V_2 ) ;
break;
case V_148 :
break;
case V_149 :
F_84 ( V_2 , F_81 ( * V_131 , V_150 ) ) ;
break;
case V_151 :
case V_152 :
case V_153 :
F_85 ( V_2 , V_131 ) ;
break;
case V_154 :
F_86 ( V_130 , V_131 ) ;
break;
case V_155 :
case V_156 :
F_87 ( V_157 !=
V_158 ) ;
if ( ! F_81 ( * V_131 , V_159 ) )
F_88 ( V_2 ) ;
break;
case V_160 :
case V_161 :
F_11 ( V_2 , V_75 , V_2 -> V_21 ,
L_17 V_162 L_18 ,
V_118 == V_160 ? L_19 : L_20 ,
F_89 ( * V_131 ) ) ;
F_54 ( V_2 , V_163 ) ;
break;
default:
F_11 ( V_2 , V_75 , V_2 -> V_21 , L_21 ,
V_118 ) ;
}
}
void F_90 ( struct V_1 * V_2 , char * V_164 , T_2 V_165 )
{
F_91 ( V_96 ,
F_63 ( V_166 ,
V_167 ) ) ;
T_2 V_168 ;
const T_7 * V_169 ;
T_2 V_170 ;
int V_6 ;
F_87 ( V_171 != 0 ) ;
V_6 = F_58 ( V_2 , V_172 , NULL , 0 ,
V_96 , sizeof( V_96 ) , & V_168 ) ;
if ( V_6 )
goto V_173;
if ( V_168 < V_166 ) {
V_6 = - V_77 ;
goto V_173;
}
V_169 = ( T_7 * ) F_92 ( V_96 , V_174 ) ;
V_170 = snprintf ( V_164 , V_165 , L_22 ,
F_93 ( V_169 [ 0 ] ) , F_93 ( V_169 [ 1 ] ) ,
F_93 ( V_169 [ 2 ] ) , F_93 ( V_169 [ 3 ] ) ) ;
if ( F_94 ( V_2 ) >= V_175 ) {
F_87 ( V_176 != 0 ) ;
V_6 = F_58 ( V_2 , V_177 , NULL , 0 ,
V_96 , sizeof( V_96 ) , & V_168 ) ;
if ( V_6 || V_168 < V_167 )
V_170 += snprintf (
V_164 + V_170 , V_165 - V_170 , L_23 ) ;
else
V_170 += snprintf (
V_164 + V_170 , V_165 - V_170 , L_24 ,
F_95 ( V_96 ,
V_178 ) ,
F_95 ( V_96 ,
V_179 ) ) ;
if ( F_96 ( V_170 >= V_165 ) )
V_164 [ 0 ] = 0 ;
}
return;
V_173:
F_11 ( V_2 , V_20 , V_2 -> V_21 , L_25 , V_180 , V_6 ) ;
V_164 [ 0 ] = 0 ;
}
static int F_10 ( struct V_1 * V_2 , bool V_181 ,
bool * V_182 )
{
F_91 ( V_27 , V_183 ) ;
F_91 ( V_96 , V_184 ) ;
T_2 V_99 ;
int V_6 ;
F_97 ( V_27 , V_185 ,
V_181 ? 1 : 0 ) ;
F_97 ( V_27 , V_186 , 1 ) ;
F_97 ( V_27 , V_187 , V_188 ) ;
V_6 = F_58 ( V_2 , V_189 , V_27 , sizeof( V_27 ) ,
V_96 , sizeof( V_96 ) , & V_99 ) ;
if ( V_6 )
goto V_173;
if ( V_99 < V_190 ) {
V_6 = - V_77 ;
goto V_173;
}
if ( V_181 ) {
if ( V_99 >= V_184 ) {
V_2 -> V_4 -> V_22 =
F_69 ( V_96 ,
V_191 ) ;
} else {
V_2 -> V_4 -> V_22 =
1 << V_192 |
1 << V_193 |
( F_98 ( V_2 ) == 0 ) <<
V_23 ;
}
}
if ( V_181 &&
( V_2 -> V_4 -> V_22 &
( 1 << V_192 |
1 << V_193 ) ) !=
( 1 << V_192 |
1 << V_193 ) ) {
F_11 ( V_2 , V_20 , V_2 -> V_21 ,
L_26 ) ;
return - V_194 ;
}
if ( V_182 != NULL )
* V_182 = F_69 ( V_96 , V_195 ) ;
return 0 ;
V_173:
F_11 ( V_2 , V_20 , V_2 -> V_21 , L_25 , V_180 , V_6 ) ;
return V_6 ;
}
int F_99 ( struct V_1 * V_2 , T_8 * V_196 ,
T_9 * V_197 , T_3 * V_198 )
{
F_91 ( V_96 , V_199 ) ;
T_2 V_99 , V_200 ;
int V_201 = F_98 ( V_2 ) ;
int V_6 ;
F_87 ( V_202 != 0 ) ;
F_87 ( V_203 & 1 ) ;
F_87 ( V_204 & 1 ) ;
V_6 = F_58 ( V_2 , V_205 , NULL , 0 ,
V_96 , sizeof( V_96 ) , & V_99 ) ;
if ( V_6 )
goto V_173;
if ( V_99 < V_206 ) {
V_6 = - V_77 ;
goto V_173;
}
if ( V_196 )
F_100 ( V_196 ,
V_201 ?
F_92 ( V_96 , V_207 ) :
F_92 ( V_96 , V_208 ) ) ;
if ( V_197 ) {
for ( V_200 = 0 ;
V_200 < F_101 ( V_99 ,
V_209 ) ;
V_200 ++ )
V_197 [ V_200 ] = F_102 (
V_96 , V_209 , V_200 ) ;
for (; V_200 < V_210 ; V_200 ++ )
V_197 [ V_200 ] = 0 ;
}
if ( V_198 ) {
if ( V_201 )
* V_198 = F_69 ( V_96 ,
V_211 ) ;
else
* V_198 = F_69 ( V_96 ,
V_212 ) ;
}
return 0 ;
V_173:
F_11 ( V_2 , V_75 , V_2 -> V_21 , L_27 ,
V_180 , V_6 , ( int ) V_99 ) ;
return V_6 ;
}
int F_103 ( struct V_1 * V_2 , bool V_213 , bool V_214 , T_3 V_215 )
{
F_91 ( V_27 , V_216 ) ;
T_3 V_217 = 0 ;
int V_6 ;
if ( V_214 )
V_217 |= V_218 ;
if ( V_213 )
V_217 |= V_219 ;
F_97 ( V_27 , V_220 , V_217 ) ;
F_97 ( V_27 , V_221 , V_215 ) ;
F_87 ( V_222 != 0 ) ;
V_6 = F_58 ( V_2 , V_223 , V_27 , sizeof( V_27 ) ,
NULL , 0 , NULL ) ;
return V_6 ;
}
int F_104 ( struct V_1 * V_2 , T_3 * V_224 )
{
F_91 ( V_96 , V_225 ) ;
T_2 V_99 ;
int V_6 ;
F_87 ( V_226 != 0 ) ;
V_6 = F_58 ( V_2 , V_227 , NULL , 0 ,
V_96 , sizeof( V_96 ) , & V_99 ) ;
if ( V_6 )
goto V_173;
if ( V_99 < V_225 ) {
V_6 = - V_77 ;
goto V_173;
}
* V_224 = F_69 ( V_96 , V_228 ) ;
return 0 ;
V_173:
F_11 ( V_2 , V_75 , V_2 -> V_21 , L_25 ,
V_180 , V_6 ) ;
return V_6 ;
}
int F_105 ( struct V_1 * V_2 , unsigned int type ,
T_2 * V_229 , T_2 * V_230 ,
bool * V_231 )
{
F_91 ( V_27 , V_232 ) ;
F_91 ( V_96 , V_233 ) ;
T_2 V_99 ;
int V_6 ;
F_97 ( V_27 , V_234 , type ) ;
V_6 = F_58 ( V_2 , V_235 , V_27 , sizeof( V_27 ) ,
V_96 , sizeof( V_96 ) , & V_99 ) ;
if ( V_6 )
goto V_173;
if ( V_99 < V_233 ) {
V_6 = - V_77 ;
goto V_173;
}
* V_229 = F_69 ( V_96 , V_236 ) ;
* V_230 = F_69 ( V_96 , V_237 ) ;
* V_231 = ! ! ( F_69 ( V_96 , V_238 ) &
( 1 << V_239 ) ) ;
return 0 ;
V_173:
F_11 ( V_2 , V_75 , V_2 -> V_21 , L_25 , V_180 , V_6 ) ;
return V_6 ;
}
static int F_106 ( struct V_1 * V_2 , unsigned int type )
{
F_91 ( V_27 , V_240 ) ;
F_91 ( V_96 , V_241 ) ;
int V_6 ;
F_97 ( V_27 , V_242 , type ) ;
V_6 = F_58 ( V_2 , V_243 , V_27 , sizeof( V_27 ) ,
V_96 , sizeof( V_96 ) , NULL ) ;
if ( V_6 )
return V_6 ;
switch ( F_69 ( V_96 , V_244 ) ) {
case V_245 :
case V_246 :
return 0 ;
default:
return - V_77 ;
}
}
int F_107 ( struct V_1 * V_2 )
{
T_3 V_247 ;
unsigned int type ;
int V_6 ;
V_6 = F_104 ( V_2 , & V_247 ) ;
if ( V_6 )
goto V_248;
type = 0 ;
while ( V_247 != 0 ) {
if ( V_247 & 1 ) {
V_6 = F_106 ( V_2 , type ) ;
if ( V_6 )
goto V_249;
}
type ++ ;
V_247 >>= 1 ;
}
return 0 ;
V_249:
F_11 ( V_2 , V_75 , V_2 -> V_21 , L_28 ,
V_180 , type ) ;
V_248:
F_11 ( V_2 , V_75 , V_2 -> V_21 , L_25 , V_180 , V_6 ) ;
return V_6 ;
}
static int F_108 ( struct V_1 * V_2 )
{
F_91 ( V_27 , V_250 ) ;
F_42 ( V_96 , V_251 ) ;
unsigned int V_252 , V_253 ;
const char * V_254 ;
T_2 V_99 ;
int V_255 ;
int V_6 ;
V_255 = 2 ;
do {
F_97 ( V_27 , V_256 , 1 ) ;
V_6 = F_59 ( V_2 , V_257 ,
V_27 , V_250 ,
V_96 , sizeof( V_96 ) , & V_99 ) ;
} while ( ( V_6 == - V_52 || V_6 == - V_77 ) && V_255 -- > 0 );
if ( V_6 ) {
F_49 ( V_2 , V_257 ,
V_250 , V_96 ,
V_99 , V_6 ) ;
return V_6 ;
}
if ( V_99 < V_251 )
return - V_77 ;
V_252 = F_69 ( V_96 , V_258 ) ;
if ( V_252 == V_259 )
return 0 ;
V_254 = ( V_252 == V_260 )
? L_29
: ( V_252 == V_261 )
? L_30
: ( V_252 == V_262 )
? L_31
: L_32 ;
F_11 ( V_2 , V_75 , V_2 -> V_21 ,
L_33 , V_254 ,
F_69 ( V_96 , V_263 ) ,
F_69 ( V_96 , V_264 ) ) ;
for ( V_253 = 0 ;
V_253 < V_265 ;
V_253 ++ )
F_11 ( V_2 , V_75 , V_2 -> V_21 , L_34 ,
1 + V_253 ,
F_109 ( V_96 , V_266 ,
V_253 ) ) ;
return 0 ;
}
static void F_110 ( struct V_1 * V_2 )
{
F_91 ( V_27 , V_267 ) ;
F_87 ( V_268 != 0 ) ;
F_97 ( V_27 , V_269 ,
V_270 ) ;
( void ) F_58 ( V_2 , V_110 , V_27 , V_267 ,
NULL , 0 , NULL ) ;
}
int F_9 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_108 ( V_2 ) ;
if ( V_6 )
return V_6 ;
F_110 ( V_2 ) ;
return 0 ;
}
void F_111 ( struct V_1 * V_2 , enum V_271 V_13 )
{
F_91 ( V_27 , V_272 ) ;
int V_6 ;
F_87 ( V_273 != V_274 ) ;
F_87 ( V_275 != V_276 ) ;
F_87 ( V_277 != V_278 ) ;
F_87 ( V_279 != 0 ) ;
F_97 ( V_27 , V_280 , V_13 ) ;
V_6 = F_58 ( V_2 , V_281 , V_27 , sizeof( V_27 ) ,
NULL , 0 , NULL ) ;
}
static int F_112 ( struct V_1 * V_2 )
{
F_91 ( V_27 , V_282 ) ;
int V_6 ;
F_87 ( V_283 != 0 ) ;
F_113 ( V_27 , V_284 ,
V_285 , 1 ) ;
V_6 = F_58 ( V_2 , V_286 , V_27 , sizeof( V_27 ) ,
NULL , 0 , NULL ) ;
return V_6 ;
}
static int F_114 ( struct V_1 * V_2 )
{
F_91 ( V_27 , V_267 ) ;
int V_6 ;
F_87 ( V_268 != 0 ) ;
F_97 ( V_27 , V_269 , 0 ) ;
V_6 = F_58 ( V_2 , V_110 , V_27 , sizeof( V_27 ) ,
NULL , 0 , NULL ) ;
if ( V_6 == - V_77 )
return 0 ;
if ( V_6 == 0 )
V_6 = - V_77 ;
return V_6 ;
}
enum V_287 F_115 ( enum V_287 V_254 )
{
return V_288 ;
}
int F_116 ( struct V_1 * V_2 , enum V_287 V_289 )
{
int V_6 ;
if ( V_289 == V_128 ) {
V_6 = F_117 ( V_2 -> V_290 ) ;
if ( V_6 )
return V_6 ;
if ( V_2 -> V_4 ) {
struct V_3 * V_4 = F_3 ( V_2 ) ;
V_4 -> V_13 = V_14 ;
}
return 0 ;
}
V_6 = F_9 ( V_2 ) ;
if ( V_6 )
return V_6 ;
if ( V_289 == V_291 )
return F_114 ( V_2 ) ;
else
return F_112 ( V_2 ) ;
}
static int F_118 ( struct V_1 * V_2 , T_3 type ,
const T_8 * V_292 , int * V_293 )
{
F_91 ( V_27 , V_294 ) ;
F_91 ( V_96 , V_295 ) ;
T_2 V_99 ;
int V_6 ;
F_97 ( V_27 , V_296 , type ) ;
F_97 ( V_27 , V_297 ,
V_298 ) ;
F_100 ( F_92 ( V_27 , V_299 ) , V_292 ) ;
V_6 = F_58 ( V_2 , V_300 , V_27 , sizeof( V_27 ) ,
V_96 , sizeof( V_96 ) , & V_99 ) ;
if ( V_6 )
goto V_173;
if ( V_99 < V_295 ) {
V_6 = - V_77 ;
goto V_173;
}
* V_293 = ( int ) F_69 ( V_96 , V_301 ) ;
return 0 ;
V_173:
* V_293 = - 1 ;
F_11 ( V_2 , V_75 , V_2 -> V_21 , L_25 , V_180 , V_6 ) ;
return V_6 ;
}
int
F_119 ( struct V_1 * V_2 , const T_8 * V_292 , int * V_293 )
{
return F_118 ( V_2 , V_302 , V_292 , V_293 ) ;
}
int F_120 ( struct V_1 * V_2 , int * V_293 )
{
F_91 ( V_96 , V_303 ) ;
T_2 V_99 ;
int V_6 ;
V_6 = F_58 ( V_2 , V_304 , NULL , 0 ,
V_96 , sizeof( V_96 ) , & V_99 ) ;
if ( V_6 )
goto V_173;
if ( V_99 < V_303 ) {
V_6 = - V_77 ;
goto V_173;
}
* V_293 = ( int ) F_69 ( V_96 , V_305 ) ;
return 0 ;
V_173:
* V_293 = - 1 ;
F_11 ( V_2 , V_75 , V_2 -> V_21 , L_25 , V_180 , V_6 ) ;
return V_6 ;
}
int F_121 ( struct V_1 * V_2 , int V_306 )
{
F_91 ( V_27 , V_307 ) ;
int V_6 ;
F_97 ( V_27 , V_308 , ( T_3 ) V_306 ) ;
V_6 = F_58 ( V_2 , V_309 , V_27 , sizeof( V_27 ) ,
NULL , 0 , NULL ) ;
return V_6 ;
}
int F_122 ( struct V_1 * V_2 )
{
struct V_129 * V_130 ;
struct V_310 * V_311 ;
F_91 ( V_27 ,
F_123 ( V_312 ) ) ;
int V_6 , V_124 ;
F_87 ( V_312 >
V_313 ) ;
V_124 = 0 ;
F_124 (channel, efx) {
F_125 (rx_queue, channel) {
if ( V_311 -> V_314 ) {
V_311 -> V_314 = false ;
F_126 ( & V_2 -> V_315 ) ;
F_127 (
V_27 , V_316 ,
V_124 , F_128 ( V_311 ) ) ;
V_124 ++ ;
}
}
}
V_6 = F_58 ( V_2 , V_317 , V_27 ,
F_123 ( V_124 ) , NULL , 0 , NULL ) ;
F_96 ( V_6 < 0 ) ;
return V_6 ;
}
int F_129 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_58 ( V_2 , V_318 , NULL , 0 , NULL , 0 , NULL ) ;
return V_6 ;
}
int F_130 ( struct V_1 * V_2 , T_3 type , bool V_319 )
{
F_91 ( V_27 , V_320 ) ;
F_87 ( V_321 != 0 ) ;
F_97 ( V_27 , V_322 , type ) ;
F_97 ( V_27 , V_323 , V_319 ) ;
return F_58 ( V_2 , V_324 , V_27 , sizeof( V_27 ) ,
NULL , 0 , NULL ) ;
}
static int F_131 ( struct V_1 * V_2 , unsigned int type )
{
F_91 ( V_27 , V_325 ) ;
int V_6 ;
F_97 ( V_27 , V_326 , type ) ;
F_87 ( V_327 != 0 ) ;
V_6 = F_58 ( V_2 , V_328 , V_27 , sizeof( V_27 ) ,
NULL , 0 , NULL ) ;
return V_6 ;
}
static int F_132 ( struct V_1 * V_2 , unsigned int type ,
T_10 V_170 , T_8 * V_329 , T_2 V_330 )
{
F_91 ( V_27 , V_331 ) ;
F_91 ( V_96 ,
F_133 ( V_332 ) ) ;
T_2 V_99 ;
int V_6 ;
F_97 ( V_27 , V_333 , type ) ;
F_97 ( V_27 , V_334 , V_170 ) ;
F_97 ( V_27 , V_335 , V_330 ) ;
V_6 = F_58 ( V_2 , V_336 , V_27 , sizeof( V_27 ) ,
V_96 , sizeof( V_96 ) , & V_99 ) ;
if ( V_6 )
return V_6 ;
memcpy ( V_329 , F_92 ( V_96 , V_337 ) , V_330 ) ;
return 0 ;
}
static int F_134 ( struct V_1 * V_2 , unsigned int type ,
T_10 V_170 , const T_8 * V_329 , T_2 V_330 )
{
F_91 ( V_27 ,
F_135 ( V_332 ) ) ;
int V_6 ;
F_97 ( V_27 , V_338 , type ) ;
F_97 ( V_27 , V_339 , V_170 ) ;
F_97 ( V_27 , V_340 , V_330 ) ;
memcpy ( F_92 ( V_27 , V_341 ) , V_329 , V_330 ) ;
F_87 ( V_342 != 0 ) ;
V_6 = F_58 ( V_2 , V_343 , V_27 ,
F_62 ( F_135 ( V_330 ) , 4 ) ,
NULL , 0 , NULL ) ;
return V_6 ;
}
static int F_136 ( struct V_1 * V_2 , unsigned int type ,
T_10 V_170 , T_2 V_330 )
{
F_91 ( V_27 , V_344 ) ;
int V_6 ;
F_97 ( V_27 , V_345 , type ) ;
F_97 ( V_27 , V_346 , V_170 ) ;
F_97 ( V_27 , V_347 , V_330 ) ;
F_87 ( V_348 != 0 ) ;
V_6 = F_58 ( V_2 , V_349 , V_27 , sizeof( V_27 ) ,
NULL , 0 , NULL ) ;
return V_6 ;
}
static int F_137 ( struct V_1 * V_2 , unsigned int type )
{
F_91 ( V_27 , V_350 ) ;
int V_6 ;
F_97 ( V_27 , V_351 , type ) ;
F_87 ( V_352 != 0 ) ;
V_6 = F_58 ( V_2 , V_353 , V_27 , sizeof( V_27 ) ,
NULL , 0 , NULL ) ;
return V_6 ;
}
int F_138 ( struct V_354 * V_355 , T_10 V_356 ,
T_2 V_165 , T_2 * V_357 , T_8 * V_329 )
{
struct V_358 * V_359 = F_139 ( V_355 ) ;
struct V_1 * V_2 = V_355 -> V_360 ;
T_10 V_170 = V_356 ;
T_10 V_361 = F_140 ( T_10 , V_356 + V_165 , V_355 -> V_362 ) ;
T_2 V_363 ;
int V_6 = 0 ;
while ( V_170 < V_361 ) {
V_363 = F_140 ( T_2 , V_361 - V_170 , V_332 ) ;
V_6 = F_132 ( V_2 , V_359 -> V_364 , V_170 ,
V_329 , V_363 ) ;
if ( V_6 )
goto V_365;
V_170 += V_363 ;
V_329 += V_363 ;
}
V_365:
* V_357 = V_170 - V_356 ;
return V_6 ;
}
int F_141 ( struct V_354 * V_355 , T_10 V_356 , T_2 V_165 )
{
struct V_358 * V_359 = F_139 ( V_355 ) ;
struct V_1 * V_2 = V_355 -> V_360 ;
T_10 V_170 = V_356 & ~ ( ( T_10 ) ( V_355 -> V_366 - 1 ) ) ;
T_10 V_361 = F_140 ( T_10 , V_356 + V_165 , V_355 -> V_362 ) ;
T_2 V_363 = V_359 -> V_367 . V_355 . V_366 ;
int V_6 = 0 ;
if ( ! V_359 -> V_368 ) {
V_6 = F_131 ( V_2 , V_359 -> V_364 ) ;
if ( V_6 )
goto V_365;
V_359 -> V_368 = true ;
}
while ( V_170 < V_361 ) {
V_6 = F_136 ( V_2 , V_359 -> V_364 , V_170 ,
V_363 ) ;
if ( V_6 )
goto V_365;
V_170 += V_363 ;
}
V_365:
return V_6 ;
}
int F_142 ( struct V_354 * V_355 , T_10 V_356 ,
T_2 V_165 , T_2 * V_357 , const T_8 * V_329 )
{
struct V_358 * V_359 = F_139 ( V_355 ) ;
struct V_1 * V_2 = V_355 -> V_360 ;
T_10 V_170 = V_356 ;
T_10 V_361 = F_140 ( T_10 , V_356 + V_165 , V_355 -> V_362 ) ;
T_2 V_363 ;
int V_6 = 0 ;
if ( ! V_359 -> V_368 ) {
V_6 = F_131 ( V_2 , V_359 -> V_364 ) ;
if ( V_6 )
goto V_365;
V_359 -> V_368 = true ;
}
while ( V_170 < V_361 ) {
V_363 = F_140 ( T_2 , V_361 - V_170 , V_332 ) ;
V_6 = F_134 ( V_2 , V_359 -> V_364 , V_170 ,
V_329 , V_363 ) ;
if ( V_6 )
goto V_365;
V_170 += V_363 ;
V_329 += V_363 ;
}
V_365:
* V_357 = V_170 - V_356 ;
return V_6 ;
}
int F_143 ( struct V_354 * V_355 )
{
struct V_358 * V_359 = F_139 ( V_355 ) ;
struct V_1 * V_2 = V_355 -> V_360 ;
int V_6 = 0 ;
if ( V_359 -> V_368 ) {
V_359 -> V_368 = false ;
V_6 = F_137 ( V_2 , V_359 -> V_364 ) ;
}
return V_6 ;
}
void F_144 ( struct V_369 * V_359 )
{
struct V_358 * V_370 =
F_145 ( V_359 , struct V_358 , V_367 ) ;
struct V_1 * V_2 = V_359 -> V_355 . V_360 ;
snprintf ( V_359 -> T_4 , sizeof( V_359 -> T_4 ) , L_35 ,
V_2 -> T_4 , V_359 -> V_371 , V_370 -> V_372 ) ;
}
