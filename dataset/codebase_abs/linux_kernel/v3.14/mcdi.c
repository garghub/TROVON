static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
F_2 ( ! V_3 -> V_4 ) ;
return & V_3 -> V_4 -> V_5 ;
}
int F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
bool V_6 ;
int V_7 ;
V_3 -> V_4 = F_4 ( sizeof( * V_3 -> V_4 ) , V_8 ) ;
if ( ! V_3 -> V_4 )
return - V_9 ;
V_4 = F_1 ( V_3 ) ;
V_4 -> V_3 = V_3 ;
F_5 ( & V_4 -> V_10 ) ;
F_6 ( & V_4 -> V_11 ) ;
V_4 -> V_12 = V_13 ;
V_4 -> V_14 = V_15 ;
F_6 ( & V_4 -> V_16 ) ;
F_7 ( & V_4 -> V_17 ) ;
F_8 ( & V_4 -> V_18 , V_19 ,
( unsigned long ) V_4 ) ;
( void ) F_9 ( V_3 ) ;
V_4 -> V_20 = true ;
V_7 = F_10 ( V_3 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_11 ( V_3 , true , & V_6 ) ;
if ( V_7 ) {
F_12 ( V_3 , V_21 , V_3 -> V_22 ,
L_1 ) ;
return V_7 ;
}
if ( V_6 )
F_12 ( V_3 , V_21 , V_3 -> V_22 ,
L_2 ) ;
if ( V_3 -> V_4 -> V_23 &
( 1 << V_24 ) )
V_3 -> V_25 = V_3 ;
return 0 ;
}
void F_13 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_4 )
return;
F_14 ( V_3 -> V_4 -> V_5 . V_12 != V_13 ) ;
F_11 ( V_3 , false , NULL ) ;
F_15 ( V_3 -> V_4 ) ;
}
static void F_16 ( struct V_2 * V_3 , unsigned V_26 ,
const T_1 * V_27 , T_2 V_28 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_29 [ 2 ] ;
T_2 V_30 ;
T_3 V_31 , V_32 ;
F_14 ( V_4 -> V_12 == V_13 ) ;
F_17 ( & V_4 -> V_11 ) ;
++ V_4 -> V_32 ;
F_18 ( & V_4 -> V_11 ) ;
V_32 = V_4 -> V_32 & V_33 ;
V_31 = 0 ;
if ( V_4 -> V_14 == V_34 )
V_31 |= V_35 ;
if ( V_3 -> type -> V_36 == 1 ) {
F_19 ( V_29 [ 0 ] ,
V_37 , 0 ,
V_38 , 1 ,
V_39 , V_26 ,
V_40 , V_28 ,
V_41 , V_32 ,
V_42 , V_31 ,
V_43 , ! V_4 -> V_20 ) ;
V_30 = 4 ;
} else {
F_14 ( V_28 > V_44 ) ;
F_19 ( V_29 [ 0 ] ,
V_37 , 0 ,
V_38 , 1 ,
V_39 , V_45 ,
V_40 , 0 ,
V_41 , V_32 ,
V_42 , V_31 ,
V_43 , ! V_4 -> V_20 ) ;
F_20 ( V_29 [ 1 ] ,
V_46 , V_26 ,
V_47 , V_28 ) ;
V_30 = 8 ;
}
V_3 -> type -> V_48 ( V_3 , V_29 , V_30 , V_27 , V_28 ) ;
V_4 -> V_20 = false ;
}
static int F_21 ( unsigned int V_49 )
{
switch ( V_49 ) {
case 0 :
return 0 ;
#define F_22 ( T_4 ) \
case MC_CMD_ERR_ ## name: \
return -name;
F_22 ( V_50 ) ;
F_22 ( V_51 ) ;
F_22 ( V_52 ) ;
F_22 ( V_53 ) ;
F_22 ( V_54 ) ;
F_22 ( V_55 ) ;
F_22 ( V_56 ) ;
F_22 ( V_57 ) ;
F_22 ( V_58 ) ;
F_22 ( V_59 ) ;
F_22 ( V_60 ) ;
F_22 ( V_61 ) ;
#undef F_22
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
static void F_23 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned int V_69 , V_70 , error ;
T_1 V_29 ;
V_3 -> type -> V_71 ( V_3 , & V_29 , 0 , 4 ) ;
V_69 = F_24 ( V_29 , V_41 ) ;
V_70 = F_24 ( V_29 , V_39 ) ;
error = F_24 ( V_29 , V_72 ) ;
if ( V_70 != V_45 ) {
V_4 -> V_73 = 4 ;
V_4 -> V_74 = F_24 ( V_29 , V_40 ) ;
} else {
V_3 -> type -> V_71 ( V_3 , & V_29 , 4 , 4 ) ;
V_4 -> V_73 = 8 ;
V_4 -> V_74 =
F_24 ( V_29 , V_47 ) ;
}
if ( error && V_4 -> V_74 == 0 ) {
F_12 ( V_3 , V_75 , V_3 -> V_22 , L_3 ) ;
V_4 -> V_76 = - V_77 ;
} else if ( ( V_69 ^ V_4 -> V_32 ) & V_33 ) {
F_12 ( V_3 , V_75 , V_3 -> V_22 ,
L_4 ,
V_69 , V_4 -> V_32 ) ;
V_4 -> V_76 = - V_77 ;
} else if ( error ) {
V_3 -> type -> V_71 ( V_3 , & V_29 , V_4 -> V_73 , 4 ) ;
V_4 -> V_76 =
F_21 ( F_24 ( V_29 , V_78 ) ) ;
} else {
V_4 -> V_76 = 0 ;
}
}
static bool F_25 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_26 () ;
if ( ! V_3 -> type -> V_79 ( V_3 ) )
return false ;
F_17 ( & V_4 -> V_11 ) ;
F_23 ( V_3 ) ;
F_18 ( & V_4 -> V_11 ) ;
return true ;
}
static int F_27 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long time , V_80 ;
unsigned int V_81 ;
int V_7 ;
V_7 = F_9 ( V_3 ) ;
if ( V_7 ) {
F_17 ( & V_4 -> V_11 ) ;
V_4 -> V_76 = V_7 ;
V_4 -> V_73 = 0 ;
V_4 -> V_74 = 0 ;
F_18 ( & V_4 -> V_11 ) ;
return 0 ;
}
V_81 = V_82 ;
V_80 = V_83 + V_84 ;
while ( 1 ) {
if ( V_81 != 0 ) {
-- V_81 ;
F_28 ( 1 ) ;
} else {
F_29 ( 1 ) ;
}
time = V_83 ;
if ( F_25 ( V_3 ) )
break;
if ( F_30 ( time , V_80 ) )
return - V_85 ;
}
return 0 ;
}
int F_9 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_4 )
return 0 ;
return V_3 -> type -> V_86 ( V_3 ) ;
}
static bool F_31 ( struct V_1 * V_4 )
{
return F_32 ( & V_4 -> V_12 ,
V_13 , V_87 ) ==
V_13 ;
}
static void F_33 ( struct V_1 * V_4 )
{
F_34 ( V_4 -> V_10 ,
F_32 ( & V_4 -> V_12 ,
V_13 , V_88 ) ==
V_13 ) ;
}
static int F_35 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( F_36 ( V_4 -> V_10 , V_4 -> V_12 == V_89 ,
V_84 ) == 0 )
return - V_85 ;
if ( V_4 -> V_14 == V_15 )
return F_27 ( V_3 ) ;
return 0 ;
}
static bool F_37 ( struct V_1 * V_4 )
{
if ( F_32 ( & V_4 -> V_12 ,
V_88 , V_89 ) ==
V_88 ) {
F_38 ( & V_4 -> V_10 ) ;
return true ;
}
return false ;
}
static void F_39 ( struct V_1 * V_4 )
{
if ( V_4 -> V_14 == V_34 ) {
struct V_90 * V_91 ;
struct V_2 * V_3 = V_4 -> V_3 ;
F_17 ( & V_4 -> V_16 ) ;
V_91 = F_40 (
& V_4 -> V_17 , struct V_90 , V_92 ) ;
if ( V_91 ) {
V_4 -> V_12 = V_87 ;
F_16 ( V_3 , V_91 -> V_26 ,
( const T_1 * ) ( V_91 + 1 ) ,
V_91 -> V_28 ) ;
F_41 ( & V_4 -> V_18 ,
V_83 + V_84 ) ;
}
F_18 ( & V_4 -> V_16 ) ;
if ( V_91 )
return;
}
V_4 -> V_12 = V_13 ;
F_38 ( & V_4 -> V_10 ) ;
}
static bool F_42 ( struct V_1 * V_4 , bool V_93 )
{
struct V_2 * V_3 = V_4 -> V_3 ;
struct V_90 * V_91 ;
T_2 V_30 , V_94 , V_95 ;
T_1 * V_96 ;
F_43 ( V_97 , 0 ) ;
int V_7 ;
if ( F_32 ( & V_4 -> V_12 ,
V_87 , V_89 ) !=
V_87 )
return false ;
F_44 ( & V_4 -> V_11 ) ;
if ( V_93 ) {
++ V_4 -> V_32 ;
++ V_4 -> V_98 ;
V_7 = - V_85 ;
V_30 = 0 ;
V_94 = 0 ;
} else {
V_7 = V_4 -> V_76 ;
V_30 = V_4 -> V_73 ;
V_94 = V_4 -> V_74 ;
}
F_45 ( & V_4 -> V_11 ) ;
if ( ! V_93 )
F_46 ( & V_4 -> V_18 ) ;
F_44 ( & V_4 -> V_16 ) ;
V_91 = F_47 ( & V_4 -> V_17 ,
struct V_90 , V_92 ) ;
F_48 ( & V_91 -> V_92 ) ;
F_45 ( & V_4 -> V_16 ) ;
V_96 = ( T_1 * ) ( V_91 + 1 ) ;
V_3 -> type -> V_71 ( V_3 , V_96 , V_30 ,
F_49 ( V_91 -> V_99 , V_94 ) ) ;
if ( ! V_93 && V_7 && ! V_91 -> V_100 ) {
V_95 = F_49 ( sizeof( V_97 ) , V_94 ) ;
V_3 -> type -> V_71 ( V_3 , V_97 , V_30 ,
sizeof( V_97 ) ) ;
F_50 ( V_3 , V_91 -> V_26 , V_91 -> V_28 , V_97 ,
V_95 , V_7 ) ;
}
V_91 -> V_101 ( V_3 , V_91 -> V_102 , V_7 , V_96 , V_94 ) ;
F_15 ( V_91 ) ;
F_39 ( V_4 ) ;
return true ;
}
static void F_51 ( struct V_2 * V_3 , unsigned int V_32 ,
unsigned int V_103 , unsigned int V_49 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
bool V_104 = false ;
F_44 ( & V_4 -> V_11 ) ;
if ( ( V_32 ^ V_4 -> V_32 ) & V_33 ) {
if ( V_4 -> V_98 )
-- V_4 -> V_98 ;
else
F_12 ( V_3 , V_75 , V_3 -> V_22 ,
L_5
L_6 , V_32 , V_4 -> V_32 ) ;
} else {
if ( V_3 -> type -> V_36 >= 2 ) {
F_23 ( V_3 ) ;
} else {
V_4 -> V_76 = F_21 ( V_49 ) ;
V_4 -> V_73 = 4 ;
V_4 -> V_74 = V_103 ;
}
V_104 = true ;
}
F_45 ( & V_4 -> V_11 ) ;
if ( V_104 ) {
if ( ! F_42 ( V_4 , false ) )
( void ) F_37 ( V_4 ) ;
}
}
static void V_19 ( unsigned long V_105 )
{
struct V_1 * V_4 = (struct V_1 * ) V_105 ;
F_42 ( V_4 , true ) ;
}
static int
F_52 ( struct V_2 * V_3 , unsigned int V_26 , T_2 V_28 )
{
if ( V_3 -> type -> V_36 < 0 ||
( V_3 -> type -> V_36 < 2 &&
V_26 > V_106 ) )
return - V_56 ;
if ( V_28 > V_44 ||
( V_3 -> type -> V_36 < 2 &&
V_28 > V_107 ) )
return - V_108 ;
return 0 ;
}
static int F_53 ( struct V_2 * V_3 , unsigned V_26 , T_2 V_28 ,
T_1 * V_96 , T_2 V_99 ,
T_2 * V_109 , bool V_100 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_43 ( V_97 , 0 ) ;
int V_7 ;
if ( V_4 -> V_14 == V_15 )
V_7 = F_27 ( V_3 ) ;
else
V_7 = F_35 ( V_3 ) ;
if ( V_7 != 0 ) {
F_12 ( V_3 , V_75 , V_3 -> V_22 ,
L_7 ,
V_26 , ( int ) V_28 , V_4 -> V_14 ) ;
if ( V_4 -> V_14 == V_34 && F_25 ( V_3 ) ) {
F_12 ( V_3 , V_75 , V_3 -> V_22 ,
L_8 ) ;
V_7 = 0 ;
}
F_17 ( & V_4 -> V_11 ) ;
++ V_4 -> V_32 ;
++ V_4 -> V_98 ;
F_18 ( & V_4 -> V_11 ) ;
}
if ( V_7 != 0 ) {
if ( V_109 )
* V_109 = 0 ;
} else {
T_2 V_30 , V_94 , V_95 ;
F_17 ( & V_4 -> V_11 ) ;
V_7 = V_4 -> V_76 ;
V_30 = V_4 -> V_73 ;
V_94 = V_4 -> V_74 ;
V_95 = F_49 ( sizeof( V_97 ) , V_94 ) ;
F_18 ( & V_4 -> V_11 ) ;
F_14 ( V_7 > 0 ) ;
V_3 -> type -> V_71 ( V_3 , V_96 , V_30 ,
F_49 ( V_99 , V_94 ) ) ;
if ( V_109 )
* V_109 = V_94 ;
V_3 -> type -> V_71 ( V_3 , V_97 , V_30 , V_95 ) ;
if ( V_26 == V_110 && V_7 == - V_77 ) {
} else if ( V_7 == - V_77 || V_7 == - V_52 ) {
F_12 ( V_3 , V_75 , V_3 -> V_22 , L_9 ,
- V_7 ) ;
F_54 ( V_3 , V_111 ) ;
} else if ( V_7 && ! V_100 ) {
F_50 ( V_3 , V_26 , V_28 , V_97 , V_95 ,
V_7 ) ;
}
if ( V_7 == - V_77 || V_7 == - V_52 ) {
F_55 ( V_112 ) ;
F_9 ( V_3 ) ;
V_4 -> V_20 = true ;
}
}
F_39 ( V_4 ) ;
return V_7 ;
}
static int F_56 ( struct V_2 * V_3 , unsigned V_26 ,
const T_1 * V_27 , T_2 V_28 ,
T_1 * V_96 , T_2 V_99 ,
T_2 * V_109 , bool V_100 )
{
int V_7 ;
V_7 = F_57 ( V_3 , V_26 , V_27 , V_28 ) ;
if ( V_7 ) {
if ( V_109 )
* V_109 = 0 ;
return V_7 ;
}
return F_53 ( V_3 , V_26 , V_28 , V_96 , V_99 ,
V_109 , V_100 ) ;
}
int F_58 ( struct V_2 * V_3 , unsigned V_26 ,
const T_1 * V_27 , T_2 V_28 ,
T_1 * V_96 , T_2 V_99 ,
T_2 * V_109 )
{
return F_56 ( V_3 , V_26 , V_27 , V_28 , V_96 , V_99 ,
V_109 , false ) ;
}
int F_59 ( struct V_2 * V_3 , unsigned V_26 ,
const T_1 * V_27 , T_2 V_28 ,
T_1 * V_96 , T_2 V_99 ,
T_2 * V_109 )
{
return F_56 ( V_3 , V_26 , V_27 , V_28 , V_96 , V_99 ,
V_109 , true ) ;
}
int F_57 ( struct V_2 * V_3 , unsigned V_26 ,
const T_1 * V_27 , T_2 V_28 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_7 ;
V_7 = F_52 ( V_3 , V_26 , V_28 ) ;
if ( V_7 )
return V_7 ;
if ( V_3 -> V_113 )
return - V_114 ;
F_33 ( V_4 ) ;
F_16 ( V_3 , V_26 , V_27 , V_28 ) ;
return 0 ;
}
static int F_60 ( struct V_2 * V_3 , unsigned int V_26 ,
const T_1 * V_27 , T_2 V_28 ,
T_2 V_99 ,
T_5 * V_101 ,
unsigned long V_102 , bool V_100 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_90 * V_91 ;
int V_7 ;
V_7 = F_52 ( V_3 , V_26 , V_28 ) ;
if ( V_7 )
return V_7 ;
if ( V_3 -> V_113 )
return - V_114 ;
V_91 = F_61 ( sizeof( * V_91 ) + F_62 ( F_63 ( V_28 , V_99 ) , 4 ) ,
V_115 ) ;
if ( ! V_91 )
return - V_9 ;
V_91 -> V_26 = V_26 ;
V_91 -> V_28 = V_28 ;
V_91 -> V_99 = V_99 ;
V_91 -> V_100 = V_100 ;
V_91 -> V_101 = V_101 ;
V_91 -> V_102 = V_102 ;
memcpy ( V_91 + 1 , V_27 , V_28 ) ;
F_17 ( & V_4 -> V_16 ) ;
if ( V_4 -> V_14 == V_34 ) {
F_64 ( & V_91 -> V_92 , & V_4 -> V_17 ) ;
if ( V_4 -> V_17 . V_116 == & V_91 -> V_92 &&
F_31 ( V_4 ) ) {
F_16 ( V_3 , V_26 , V_27 , V_28 ) ;
F_41 ( & V_4 -> V_18 ,
V_83 + V_84 ) ;
}
} else {
F_15 ( V_91 ) ;
V_7 = - V_114 ;
}
F_18 ( & V_4 -> V_16 ) ;
return V_7 ;
}
int
F_65 ( struct V_2 * V_3 , unsigned int V_26 ,
const T_1 * V_27 , T_2 V_28 , T_2 V_99 ,
T_5 * V_101 , unsigned long V_102 )
{
return F_60 ( V_3 , V_26 , V_27 , V_28 , V_99 , V_101 ,
V_102 , false ) ;
}
int F_66 ( struct V_2 * V_3 , unsigned int V_26 ,
const T_1 * V_27 , T_2 V_28 ,
T_2 V_99 , T_5 * V_101 ,
unsigned long V_102 )
{
return F_60 ( V_3 , V_26 , V_27 , V_28 , V_99 , V_101 ,
V_102 , true ) ;
}
int F_67 ( struct V_2 * V_3 , unsigned V_26 , T_2 V_28 ,
T_1 * V_96 , T_2 V_99 ,
T_2 * V_109 )
{
return F_53 ( V_3 , V_26 , V_28 , V_96 , V_99 ,
V_109 , false ) ;
}
int F_68 ( struct V_2 * V_3 , unsigned V_26 , T_2 V_28 ,
T_1 * V_96 , T_2 V_99 ,
T_2 * V_109 )
{
return F_53 ( V_3 , V_26 , V_28 , V_96 , V_99 ,
V_109 , true ) ;
}
void F_50 ( struct V_2 * V_3 , unsigned V_26 ,
T_2 V_28 , T_1 * V_96 ,
T_2 V_99 , int V_7 )
{
int V_117 = 0 , V_118 = 0 ;
if ( V_99 >= V_119 + 4 )
V_117 = F_69 ( V_96 , V_120 ) ;
if ( V_99 >= V_121 + 4 )
V_118 = F_69 ( V_96 , V_122 ) ;
F_12 ( V_3 , V_75 , V_3 -> V_22 ,
L_10 ,
V_26 , ( int ) V_28 , V_7 , V_117 , V_118 ) ;
}
void F_70 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
if ( ! V_3 -> V_4 )
return;
V_4 = F_1 ( V_3 ) ;
if ( V_4 -> V_14 == V_15 )
return;
V_4 -> V_14 = V_15 ;
F_37 ( V_4 ) ;
}
void F_71 ( struct V_2 * V_3 )
{
struct V_90 * V_91 , * V_116 ;
struct V_1 * V_4 ;
if ( ! V_3 -> V_4 )
return;
V_4 = F_1 ( V_3 ) ;
F_14 ( V_4 -> V_14 != V_15 ) ;
F_46 ( & V_4 -> V_18 ) ;
if ( V_4 -> V_12 == V_87 ) {
F_27 ( V_3 ) ;
V_4 -> V_12 = V_13 ;
}
F_72 (async, next, &mcdi->async_list, list) {
V_91 -> V_101 ( V_3 , V_91 -> V_102 , - V_114 , NULL , 0 ) ;
F_48 ( & V_91 -> V_92 ) ;
F_15 ( V_91 ) ;
}
}
void F_73 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
if ( ! V_3 -> V_4 )
return;
V_4 = F_1 ( V_3 ) ;
if ( V_4 -> V_14 == V_34 )
return;
F_33 ( V_4 ) ;
V_4 -> V_14 = V_34 ;
F_39 ( V_4 ) ;
}
static void F_74 ( struct V_2 * V_3 , int V_7 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_44 ( & V_4 -> V_11 ) ;
if ( F_37 ( V_4 ) ) {
if ( V_4 -> V_14 == V_34 ) {
V_4 -> V_76 = V_7 ;
V_4 -> V_73 = 0 ;
V_4 -> V_74 = 0 ;
++ V_4 -> V_98 ;
}
} else {
int V_123 ;
for ( V_123 = 0 ; V_123 < V_124 ; ++ V_123 ) {
if ( F_9 ( V_3 ) )
break;
F_28 ( V_125 ) ;
}
V_4 -> V_20 = true ;
F_54 ( V_3 , V_111 ) ;
}
F_45 ( & V_4 -> V_11 ) ;
}
static void F_75 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_44 ( & V_4 -> V_11 ) ;
V_3 -> V_113 = true ;
if ( F_37 ( V_4 ) ) {
if ( V_4 -> V_14 == V_34 ) {
V_4 -> V_76 = - V_77 ;
V_4 -> V_73 = 0 ;
V_4 -> V_74 = 0 ;
++ V_4 -> V_98 ;
}
}
V_4 -> V_20 = true ;
F_54 ( V_3 , V_126 ) ;
F_45 ( & V_4 -> V_11 ) ;
}
void F_76 ( struct V_127 * V_128 ,
T_6 * V_129 )
{
struct V_2 * V_3 = V_128 -> V_3 ;
int V_117 = F_77 ( * V_129 , V_130 ) ;
T_3 V_131 = F_77 ( * V_129 , V_132 ) ;
switch ( V_117 ) {
case V_133 :
F_12 ( V_3 , V_75 , V_3 -> V_22 ,
L_11 , V_131 ) ;
F_74 ( V_3 , - V_52 ) ;
break;
case V_134 :
F_78 ( V_3 , V_135 , V_3 -> V_22 , L_12 ) ;
break;
case V_136 :
F_51 ( V_3 ,
F_79 ( * V_129 , V_137 ) ,
F_79 ( * V_129 , V_138 ) ,
F_79 ( * V_129 , V_139 ) ) ;
break;
case V_140 :
F_80 ( V_3 , V_129 ) ;
break;
case V_141 :
F_81 ( V_3 , V_129 ) ;
break;
case V_142 :
F_82 ( V_3 , V_75 , V_3 -> V_22 ,
L_13 , V_131 ) ;
break;
case V_143 :
case V_144 :
F_78 ( V_3 , V_75 , V_3 -> V_22 , L_14 ) ;
F_74 ( V_3 , - V_77 ) ;
break;
case V_145 :
F_78 ( V_3 , V_75 , V_3 -> V_22 , L_15 ) ;
F_75 ( V_3 ) ;
break;
case V_146 :
break;
case V_147 :
F_83 ( V_3 , F_79 ( * V_129 , V_148 ) ) ;
break;
case V_149 :
case V_150 :
case V_151 :
F_84 ( V_3 , V_129 ) ;
break;
case V_152 :
F_85 ( V_128 , V_129 ) ;
break;
case V_153 :
case V_154 :
F_86 ( V_155 !=
V_156 ) ;
if ( ! F_79 ( * V_129 , V_157 ) )
F_87 ( V_3 ) ;
break;
case V_158 :
case V_159 :
F_12 ( V_3 , V_75 , V_3 -> V_22 ,
L_16 V_160 L_17 ,
V_117 == V_158 ? L_18 : L_19 ,
F_88 ( * V_129 ) ) ;
F_54 ( V_3 , V_161 ) ;
break;
default:
F_12 ( V_3 , V_75 , V_3 -> V_22 , L_20 ,
V_117 ) ;
}
}
void F_89 ( struct V_2 * V_3 , char * V_162 , T_2 V_163 )
{
F_90 ( V_96 ,
F_63 ( V_164 ,
V_165 ) ) ;
T_2 V_166 ;
const T_7 * V_167 ;
T_2 V_168 ;
int V_7 ;
F_86 ( V_169 != 0 ) ;
V_7 = F_58 ( V_3 , V_170 , NULL , 0 ,
V_96 , sizeof( V_96 ) , & V_166 ) ;
if ( V_7 )
goto V_171;
if ( V_166 < V_164 ) {
V_7 = - V_77 ;
goto V_171;
}
V_167 = ( T_7 * ) F_91 ( V_96 , V_172 ) ;
V_168 = snprintf ( V_162 , V_163 , L_21 ,
F_92 ( V_167 [ 0 ] ) , F_92 ( V_167 [ 1 ] ) ,
F_92 ( V_167 [ 2 ] ) , F_92 ( V_167 [ 3 ] ) ) ;
if ( F_93 ( V_3 ) >= V_173 ) {
F_86 ( V_174 != 0 ) ;
V_7 = F_58 ( V_3 , V_175 , NULL , 0 ,
V_96 , sizeof( V_96 ) , & V_166 ) ;
if ( V_7 || V_166 < V_165 )
V_168 += snprintf (
V_162 + V_168 , V_163 - V_168 , L_22 ) ;
else
V_168 += snprintf (
V_162 + V_168 , V_163 - V_168 , L_23 ,
F_94 ( V_96 ,
V_176 ) ,
F_94 ( V_96 ,
V_177 ) ) ;
if ( F_95 ( V_168 >= V_163 ) )
V_162 [ 0 ] = 0 ;
}
return;
V_171:
F_12 ( V_3 , V_21 , V_3 -> V_22 , L_24 , V_178 , V_7 ) ;
V_162 [ 0 ] = 0 ;
}
static int F_11 ( struct V_2 * V_3 , bool V_179 ,
bool * V_180 )
{
F_90 ( V_27 , V_181 ) ;
F_90 ( V_96 , V_182 ) ;
T_2 V_99 ;
int V_7 ;
F_96 ( V_27 , V_183 ,
V_179 ? 1 : 0 ) ;
F_96 ( V_27 , V_184 , 1 ) ;
F_96 ( V_27 , V_185 , V_186 ) ;
V_7 = F_58 ( V_3 , V_187 , V_27 , sizeof( V_27 ) ,
V_96 , sizeof( V_96 ) , & V_99 ) ;
if ( V_7 )
goto V_171;
if ( V_99 < V_188 ) {
V_7 = - V_77 ;
goto V_171;
}
if ( V_179 ) {
if ( V_99 >= V_182 ) {
V_3 -> V_4 -> V_23 =
F_69 ( V_96 ,
V_189 ) ;
} else {
V_3 -> V_4 -> V_23 =
1 << V_190 |
1 << V_191 |
( F_97 ( V_3 ) == 0 ) <<
V_24 ;
}
}
if ( V_179 &&
( V_3 -> V_4 -> V_23 &
( 1 << V_190 |
1 << V_191 ) ) !=
( 1 << V_190 |
1 << V_191 ) ) {
F_12 ( V_3 , V_21 , V_3 -> V_22 ,
L_25 ) ;
return - V_192 ;
}
if ( V_180 != NULL )
* V_180 = F_69 ( V_96 , V_193 ) ;
return 0 ;
V_171:
F_12 ( V_3 , V_21 , V_3 -> V_22 , L_24 , V_178 , V_7 ) ;
return V_7 ;
}
int F_98 ( struct V_2 * V_3 , T_8 * V_194 ,
T_9 * V_195 , T_3 * V_196 )
{
F_90 ( V_96 , V_197 ) ;
T_2 V_99 , V_198 ;
int V_199 = F_97 ( V_3 ) ;
int V_7 ;
F_86 ( V_200 != 0 ) ;
V_7 = F_58 ( V_3 , V_201 , NULL , 0 ,
V_96 , sizeof( V_96 ) , & V_99 ) ;
if ( V_7 )
goto V_171;
if ( V_99 < V_202 ) {
V_7 = - V_77 ;
goto V_171;
}
if ( V_194 )
memcpy ( V_194 ,
V_199 ?
F_91 ( V_96 , V_203 ) :
F_91 ( V_96 , V_204 ) ,
V_205 ) ;
if ( V_195 ) {
for ( V_198 = 0 ;
V_198 < F_99 ( V_99 ,
V_206 ) ;
V_198 ++ )
V_195 [ V_198 ] = F_100 (
V_96 , V_206 , V_198 ) ;
for (; V_198 < V_207 ; V_198 ++ )
V_195 [ V_198 ] = 0 ;
}
if ( V_196 ) {
if ( V_199 )
* V_196 = F_69 ( V_96 ,
V_208 ) ;
else
* V_196 = F_69 ( V_96 ,
V_209 ) ;
}
return 0 ;
V_171:
F_12 ( V_3 , V_75 , V_3 -> V_22 , L_26 ,
V_178 , V_7 , ( int ) V_99 ) ;
return V_7 ;
}
int F_101 ( struct V_2 * V_3 , bool V_210 , bool V_211 , T_3 V_212 )
{
F_90 ( V_27 , V_213 ) ;
T_3 V_214 = 0 ;
int V_7 ;
if ( V_211 )
V_214 |= V_215 ;
if ( V_210 )
V_214 |= V_216 ;
F_96 ( V_27 , V_217 , V_214 ) ;
F_96 ( V_27 , V_218 , V_212 ) ;
F_86 ( V_219 != 0 ) ;
V_7 = F_58 ( V_3 , V_220 , V_27 , sizeof( V_27 ) ,
NULL , 0 , NULL ) ;
return V_7 ;
}
int F_102 ( struct V_2 * V_3 , T_3 * V_221 )
{
F_90 ( V_96 , V_222 ) ;
T_2 V_99 ;
int V_7 ;
F_86 ( V_223 != 0 ) ;
V_7 = F_58 ( V_3 , V_224 , NULL , 0 ,
V_96 , sizeof( V_96 ) , & V_99 ) ;
if ( V_7 )
goto V_171;
if ( V_99 < V_222 ) {
V_7 = - V_77 ;
goto V_171;
}
* V_221 = F_69 ( V_96 , V_225 ) ;
return 0 ;
V_171:
F_12 ( V_3 , V_75 , V_3 -> V_22 , L_24 ,
V_178 , V_7 ) ;
return V_7 ;
}
int F_103 ( struct V_2 * V_3 , unsigned int type ,
T_2 * V_226 , T_2 * V_227 ,
bool * V_228 )
{
F_90 ( V_27 , V_229 ) ;
F_90 ( V_96 , V_230 ) ;
T_2 V_99 ;
int V_7 ;
F_96 ( V_27 , V_231 , type ) ;
V_7 = F_58 ( V_3 , V_232 , V_27 , sizeof( V_27 ) ,
V_96 , sizeof( V_96 ) , & V_99 ) ;
if ( V_7 )
goto V_171;
if ( V_99 < V_230 ) {
V_7 = - V_77 ;
goto V_171;
}
* V_226 = F_69 ( V_96 , V_233 ) ;
* V_227 = F_69 ( V_96 , V_234 ) ;
* V_228 = ! ! ( F_69 ( V_96 , V_235 ) &
( 1 << V_236 ) ) ;
return 0 ;
V_171:
F_12 ( V_3 , V_75 , V_3 -> V_22 , L_24 , V_178 , V_7 ) ;
return V_7 ;
}
static int F_104 ( struct V_2 * V_3 , unsigned int type )
{
F_90 ( V_27 , V_237 ) ;
F_90 ( V_96 , V_238 ) ;
int V_7 ;
F_96 ( V_27 , V_239 , type ) ;
V_7 = F_58 ( V_3 , V_240 , V_27 , sizeof( V_27 ) ,
V_96 , sizeof( V_96 ) , NULL ) ;
if ( V_7 )
return V_7 ;
switch ( F_69 ( V_96 , V_241 ) ) {
case V_242 :
case V_243 :
return 0 ;
default:
return - V_77 ;
}
}
int F_105 ( struct V_2 * V_3 )
{
T_3 V_244 ;
unsigned int type ;
int V_7 ;
V_7 = F_102 ( V_3 , & V_244 ) ;
if ( V_7 )
goto V_245;
type = 0 ;
while ( V_244 != 0 ) {
if ( V_244 & 1 ) {
V_7 = F_104 ( V_3 , type ) ;
if ( V_7 )
goto V_246;
}
type ++ ;
V_244 >>= 1 ;
}
return 0 ;
V_246:
F_12 ( V_3 , V_75 , V_3 -> V_22 , L_27 ,
V_178 , type ) ;
V_245:
F_12 ( V_3 , V_75 , V_3 -> V_22 , L_24 , V_178 , V_7 ) ;
return V_7 ;
}
static int F_106 ( struct V_2 * V_3 )
{
F_90 ( V_27 , V_247 ) ;
F_43 ( V_96 , V_248 ) ;
unsigned int V_249 , V_250 ;
const char * V_251 ;
T_2 V_99 ;
int V_252 ;
int V_7 ;
V_252 = 2 ;
do {
F_96 ( V_27 , V_253 , 1 ) ;
V_7 = F_59 ( V_3 , V_254 ,
V_27 , V_247 ,
V_96 , sizeof( V_96 ) , & V_99 ) ;
} while ( ( V_7 == - V_52 || V_7 == - V_77 ) && V_252 -- > 0 );
if ( V_7 ) {
F_50 ( V_3 , V_254 ,
V_247 , V_96 ,
V_99 , V_7 ) ;
return V_7 ;
}
if ( V_99 < V_248 )
return - V_77 ;
V_249 = F_69 ( V_96 , V_255 ) ;
if ( V_249 == V_256 )
return 0 ;
V_251 = ( V_249 == V_257 )
? L_28
: ( V_249 == V_258 )
? L_29
: ( V_249 == V_259 )
? L_30
: L_31 ;
F_12 ( V_3 , V_75 , V_3 -> V_22 ,
L_32 , V_251 ,
F_69 ( V_96 , V_260 ) ,
F_69 ( V_96 , V_261 ) ) ;
for ( V_250 = 0 ;
V_250 < V_262 ;
V_250 ++ )
F_12 ( V_3 , V_75 , V_3 -> V_22 , L_33 ,
1 + V_250 ,
F_107 ( V_96 , V_263 ,
V_250 ) ) ;
return 0 ;
}
static void F_108 ( struct V_2 * V_3 )
{
F_90 ( V_27 , V_264 ) ;
F_86 ( V_265 != 0 ) ;
F_96 ( V_27 , V_266 ,
V_267 ) ;
( void ) F_58 ( V_3 , V_110 , V_27 , V_264 ,
NULL , 0 , NULL ) ;
}
int F_10 ( struct V_2 * V_3 )
{
int V_7 ;
V_7 = F_106 ( V_3 ) ;
if ( V_7 )
return V_7 ;
F_108 ( V_3 ) ;
return 0 ;
}
void F_109 ( struct V_2 * V_3 , enum V_268 V_14 )
{
F_90 ( V_27 , V_269 ) ;
int V_7 ;
F_86 ( V_270 != V_271 ) ;
F_86 ( V_272 != V_273 ) ;
F_86 ( V_274 != V_275 ) ;
F_86 ( V_276 != 0 ) ;
F_96 ( V_27 , V_277 , V_14 ) ;
V_7 = F_58 ( V_3 , V_278 , V_27 , sizeof( V_27 ) ,
NULL , 0 , NULL ) ;
}
static int F_110 ( struct V_2 * V_3 )
{
F_90 ( V_27 , V_279 ) ;
int V_7 ;
F_86 ( V_280 != 0 ) ;
F_111 ( V_27 , V_281 ,
V_282 , 1 ) ;
V_7 = F_58 ( V_3 , V_283 , V_27 , sizeof( V_27 ) ,
NULL , 0 , NULL ) ;
return V_7 ;
}
static int F_112 ( struct V_2 * V_3 )
{
F_90 ( V_27 , V_264 ) ;
int V_7 ;
F_86 ( V_265 != 0 ) ;
F_96 ( V_27 , V_266 , 0 ) ;
V_7 = F_58 ( V_3 , V_110 , V_27 , sizeof( V_27 ) ,
NULL , 0 , NULL ) ;
if ( V_7 == - V_77 )
return 0 ;
if ( V_7 == 0 )
V_7 = - V_77 ;
return V_7 ;
}
enum V_284 F_113 ( enum V_284 V_251 )
{
return V_285 ;
}
int F_114 ( struct V_2 * V_3 , enum V_284 V_286 )
{
int V_7 ;
V_7 = F_10 ( V_3 ) ;
if ( V_7 )
return V_7 ;
if ( V_286 == V_287 )
return F_112 ( V_3 ) ;
else
return F_110 ( V_3 ) ;
}
static int F_115 ( struct V_2 * V_3 , T_3 type ,
const T_8 * V_288 , int * V_289 )
{
F_90 ( V_27 , V_290 ) ;
F_90 ( V_96 , V_291 ) ;
T_2 V_99 ;
int V_7 ;
F_96 ( V_27 , V_292 , type ) ;
F_96 ( V_27 , V_293 ,
V_294 ) ;
memcpy ( F_91 ( V_27 , V_295 ) , V_288 , V_205 ) ;
V_7 = F_58 ( V_3 , V_296 , V_27 , sizeof( V_27 ) ,
V_96 , sizeof( V_96 ) , & V_99 ) ;
if ( V_7 )
goto V_171;
if ( V_99 < V_291 ) {
V_7 = - V_77 ;
goto V_171;
}
* V_289 = ( int ) F_69 ( V_96 , V_297 ) ;
return 0 ;
V_171:
* V_289 = - 1 ;
F_12 ( V_3 , V_75 , V_3 -> V_22 , L_24 , V_178 , V_7 ) ;
return V_7 ;
}
int
F_116 ( struct V_2 * V_3 , const T_8 * V_288 , int * V_289 )
{
return F_115 ( V_3 , V_298 , V_288 , V_289 ) ;
}
int F_117 ( struct V_2 * V_3 , int * V_289 )
{
F_90 ( V_96 , V_299 ) ;
T_2 V_99 ;
int V_7 ;
V_7 = F_58 ( V_3 , V_300 , NULL , 0 ,
V_96 , sizeof( V_96 ) , & V_99 ) ;
if ( V_7 )
goto V_171;
if ( V_99 < V_299 ) {
V_7 = - V_77 ;
goto V_171;
}
* V_289 = ( int ) F_69 ( V_96 , V_301 ) ;
return 0 ;
V_171:
* V_289 = - 1 ;
F_12 ( V_3 , V_75 , V_3 -> V_22 , L_24 , V_178 , V_7 ) ;
return V_7 ;
}
int F_118 ( struct V_2 * V_3 , int V_302 )
{
F_90 ( V_27 , V_303 ) ;
int V_7 ;
F_96 ( V_27 , V_304 , ( T_3 ) V_302 ) ;
V_7 = F_58 ( V_3 , V_305 , V_27 , sizeof( V_27 ) ,
NULL , 0 , NULL ) ;
return V_7 ;
}
int F_119 ( struct V_2 * V_3 )
{
struct V_127 * V_128 ;
struct V_306 * V_307 ;
F_90 ( V_27 ,
F_120 ( V_308 ) ) ;
int V_7 , V_123 ;
F_86 ( V_308 >
V_309 ) ;
V_123 = 0 ;
F_121 (channel, efx) {
F_122 (rx_queue, channel) {
if ( V_307 -> V_310 ) {
V_307 -> V_310 = false ;
F_123 ( & V_3 -> V_311 ) ;
F_124 (
V_27 , V_312 ,
V_123 , F_125 ( V_307 ) ) ;
V_123 ++ ;
}
}
}
V_7 = F_58 ( V_3 , V_313 , V_27 ,
F_120 ( V_123 ) , NULL , 0 , NULL ) ;
F_95 ( V_7 < 0 ) ;
return V_7 ;
}
int F_126 ( struct V_2 * V_3 )
{
int V_7 ;
V_7 = F_58 ( V_3 , V_314 , NULL , 0 , NULL , 0 , NULL ) ;
return V_7 ;
}
int F_127 ( struct V_2 * V_3 , T_3 type , bool V_315 )
{
F_90 ( V_27 , V_316 ) ;
F_86 ( V_317 != 0 ) ;
F_96 ( V_27 , V_318 , type ) ;
F_96 ( V_27 , V_319 , V_315 ) ;
return F_58 ( V_3 , V_320 , V_27 , sizeof( V_27 ) ,
NULL , 0 , NULL ) ;
}
static int F_128 ( struct V_2 * V_3 , unsigned int type )
{
F_90 ( V_27 , V_321 ) ;
int V_7 ;
F_96 ( V_27 , V_322 , type ) ;
F_86 ( V_323 != 0 ) ;
V_7 = F_58 ( V_3 , V_324 , V_27 , sizeof( V_27 ) ,
NULL , 0 , NULL ) ;
return V_7 ;
}
static int F_129 ( struct V_2 * V_3 , unsigned int type ,
T_10 V_168 , T_8 * V_325 , T_2 V_326 )
{
F_90 ( V_27 , V_327 ) ;
F_90 ( V_96 ,
F_130 ( V_328 ) ) ;
T_2 V_99 ;
int V_7 ;
F_96 ( V_27 , V_329 , type ) ;
F_96 ( V_27 , V_330 , V_168 ) ;
F_96 ( V_27 , V_331 , V_326 ) ;
V_7 = F_58 ( V_3 , V_332 , V_27 , sizeof( V_27 ) ,
V_96 , sizeof( V_96 ) , & V_99 ) ;
if ( V_7 )
return V_7 ;
memcpy ( V_325 , F_91 ( V_96 , V_333 ) , V_326 ) ;
return 0 ;
}
static int F_131 ( struct V_2 * V_3 , unsigned int type ,
T_10 V_168 , const T_8 * V_325 , T_2 V_326 )
{
F_90 ( V_27 ,
F_132 ( V_328 ) ) ;
int V_7 ;
F_96 ( V_27 , V_334 , type ) ;
F_96 ( V_27 , V_335 , V_168 ) ;
F_96 ( V_27 , V_336 , V_326 ) ;
memcpy ( F_91 ( V_27 , V_337 ) , V_325 , V_326 ) ;
F_86 ( V_338 != 0 ) ;
V_7 = F_58 ( V_3 , V_339 , V_27 ,
F_62 ( F_132 ( V_326 ) , 4 ) ,
NULL , 0 , NULL ) ;
return V_7 ;
}
static int F_133 ( struct V_2 * V_3 , unsigned int type ,
T_10 V_168 , T_2 V_326 )
{
F_90 ( V_27 , V_340 ) ;
int V_7 ;
F_96 ( V_27 , V_341 , type ) ;
F_96 ( V_27 , V_342 , V_168 ) ;
F_96 ( V_27 , V_343 , V_326 ) ;
F_86 ( V_344 != 0 ) ;
V_7 = F_58 ( V_3 , V_345 , V_27 , sizeof( V_27 ) ,
NULL , 0 , NULL ) ;
return V_7 ;
}
static int F_134 ( struct V_2 * V_3 , unsigned int type )
{
F_90 ( V_27 , V_346 ) ;
int V_7 ;
F_96 ( V_27 , V_347 , type ) ;
F_86 ( V_348 != 0 ) ;
V_7 = F_58 ( V_3 , V_349 , V_27 , sizeof( V_27 ) ,
NULL , 0 , NULL ) ;
return V_7 ;
}
int F_135 ( struct V_350 * V_351 , T_10 V_352 ,
T_2 V_163 , T_2 * V_353 , T_8 * V_325 )
{
struct V_354 * V_355 = F_136 ( V_351 ) ;
struct V_2 * V_3 = V_351 -> V_356 ;
T_10 V_168 = V_352 ;
T_10 V_357 = F_137 ( T_10 , V_352 + V_163 , V_351 -> V_358 ) ;
T_2 V_359 ;
int V_7 = 0 ;
while ( V_168 < V_357 ) {
V_359 = F_137 ( T_2 , V_357 - V_168 , V_328 ) ;
V_7 = F_129 ( V_3 , V_355 -> V_360 , V_168 ,
V_325 , V_359 ) ;
if ( V_7 )
goto V_361;
V_168 += V_359 ;
V_325 += V_359 ;
}
V_361:
* V_353 = V_168 - V_352 ;
return V_7 ;
}
int F_138 ( struct V_350 * V_351 , T_10 V_352 , T_2 V_163 )
{
struct V_354 * V_355 = F_136 ( V_351 ) ;
struct V_2 * V_3 = V_351 -> V_356 ;
T_10 V_168 = V_352 & ~ ( ( T_10 ) ( V_351 -> V_362 - 1 ) ) ;
T_10 V_357 = F_137 ( T_10 , V_352 + V_163 , V_351 -> V_358 ) ;
T_2 V_359 = V_355 -> V_363 . V_351 . V_362 ;
int V_7 = 0 ;
if ( ! V_355 -> V_364 ) {
V_7 = F_128 ( V_3 , V_355 -> V_360 ) ;
if ( V_7 )
goto V_361;
V_355 -> V_364 = true ;
}
while ( V_168 < V_357 ) {
V_7 = F_133 ( V_3 , V_355 -> V_360 , V_168 ,
V_359 ) ;
if ( V_7 )
goto V_361;
V_168 += V_359 ;
}
V_361:
return V_7 ;
}
int F_139 ( struct V_350 * V_351 , T_10 V_352 ,
T_2 V_163 , T_2 * V_353 , const T_8 * V_325 )
{
struct V_354 * V_355 = F_136 ( V_351 ) ;
struct V_2 * V_3 = V_351 -> V_356 ;
T_10 V_168 = V_352 ;
T_10 V_357 = F_137 ( T_10 , V_352 + V_163 , V_351 -> V_358 ) ;
T_2 V_359 ;
int V_7 = 0 ;
if ( ! V_355 -> V_364 ) {
V_7 = F_128 ( V_3 , V_355 -> V_360 ) ;
if ( V_7 )
goto V_361;
V_355 -> V_364 = true ;
}
while ( V_168 < V_357 ) {
V_359 = F_137 ( T_2 , V_357 - V_168 , V_328 ) ;
V_7 = F_131 ( V_3 , V_355 -> V_360 , V_168 ,
V_325 , V_359 ) ;
if ( V_7 )
goto V_361;
V_168 += V_359 ;
V_325 += V_359 ;
}
V_361:
* V_353 = V_168 - V_352 ;
return V_7 ;
}
int F_140 ( struct V_350 * V_351 )
{
struct V_354 * V_355 = F_136 ( V_351 ) ;
struct V_2 * V_3 = V_351 -> V_356 ;
int V_7 = 0 ;
if ( V_355 -> V_364 ) {
V_355 -> V_364 = false ;
V_7 = F_134 ( V_3 , V_355 -> V_360 ) ;
}
return V_7 ;
}
void F_141 ( struct V_365 * V_355 )
{
struct V_354 * V_366 =
F_142 ( V_355 , struct V_354 , V_363 ) ;
struct V_2 * V_3 = V_355 -> V_351 . V_356 ;
snprintf ( V_355 -> T_4 , sizeof( V_355 -> T_4 ) , L_34 ,
V_3 -> T_4 , V_355 -> V_367 , V_366 -> V_368 ) ;
}
