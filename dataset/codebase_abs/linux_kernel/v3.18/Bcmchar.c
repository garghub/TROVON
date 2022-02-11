static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 ,
struct V_4 * V_5 )
{
INT V_6 = V_7 ;
F_2 ( & V_2 -> V_8 ) ;
if ( ( V_2 -> V_9 == TRUE ) || ( V_2 -> V_10 == TRUE ) ||
( V_2 -> V_11 == TRUE ) ) {
F_3 ( V_2 ,
V_12 , V_13 , V_14 ,
L_1 ) ;
F_4 ( & V_2 -> V_8 ) ;
F_5 ( V_3 ) ;
return - V_15 ;
}
V_6 = F_6 ( V_2 , ( V_16 ) V_3 ,
V_5 -> V_17 ,
V_5 -> V_18 ) ;
F_4 ( & V_2 -> V_8 ) ;
if ( V_6 != V_19 ) {
F_5 ( V_3 ) ;
return V_6 ;
}
if ( F_7 ( V_5 -> V_20 , V_3 , V_5 -> V_18 ) ) {
F_5 ( V_3 ) ;
return - V_21 ;
}
return V_19 ;
}
static int F_8 ( struct V_1 * V_2 ,
T_1 V_3 ,
struct V_4 * V_5 )
{
INT V_6 ;
T_2 V_22 = 0 ;
V_6 = F_9 ( V_2 , V_2 -> V_23 ) ;
if ( V_6 == V_19 )
return V_19 ;
if ( ( ( V_5 -> V_17 + V_5 -> V_18 ) !=
V_2 -> V_24 ) ||
( V_5 -> V_18 < V_25 ) ) {
F_3 ( V_2 , V_12 , V_13 , V_14 ,
L_2 ) ;
F_4 ( & V_2 -> V_8 ) ;
F_5 ( V_3 ) ;
return V_6 ;
}
V_22 =
F_10 ( * ( V_16 ) ( V_3 + V_5 -> V_18 -
V_25 ) ) ;
if ( V_22 != V_26 ) {
F_3 ( V_2 , V_12 , V_13 , V_14 ,
L_2 ) ;
F_4 ( & V_2 -> V_8 ) ;
F_5 ( V_3 ) ;
return V_6 ;
}
return V_19 ;
}
static int F_11 ( struct V_27 * V_27 , struct V_28 * V_29 )
{
struct V_1 * V_2 = NULL ;
struct V_30 * V_31 = NULL ;
V_2 = F_12 ( V_32 ) ;
V_31 = F_13 ( sizeof( struct V_30 ) , V_33 ) ;
if ( ! V_31 )
return - V_34 ;
V_31 -> V_35 = V_2 ;
V_31 -> V_36 = 0xFFFFFFFF & ~ ( 1 << 0xB ) ;
F_2 ( & V_2 -> V_37 ) ;
V_31 -> V_38 = V_2 -> V_39 ;
V_2 -> V_39 = V_31 ;
F_4 ( & V_2 -> V_37 ) ;
V_29 -> V_40 = V_31 ;
F_14 ( & V_2 -> V_41 ) ;
F_15 ( V_27 , V_29 ) ;
return 0 ;
}
static int F_16 ( struct V_27 * V_27 , struct V_28 * V_29 )
{
struct V_30 * V_31 , * V_42 , * V_43 ;
struct V_1 * V_2 = NULL ;
struct V_44 * V_45 , * V_46 ;
V_31 = (struct V_30 * ) V_29 -> V_40 ;
if ( V_31 == NULL )
return 0 ;
V_2 = V_31 -> V_35 ;
F_2 ( & V_2 -> V_37 ) ;
V_42 = V_2 -> V_39 ;
for ( V_43 = NULL ; V_42 ; V_43 = V_42 , V_42 = V_42 -> V_38 ) {
if ( V_42 == V_31 )
break;
}
if ( V_42 ) {
if ( ! V_43 )
V_2 -> V_39 = V_42 -> V_38 ;
else
V_43 -> V_38 = V_42 -> V_38 ;
} else {
F_4 ( & V_2 -> V_37 ) ;
return 0 ;
}
V_45 = V_31 -> V_47 ;
while ( V_45 ) {
V_46 = V_45 -> V_38 ;
F_17 ( V_45 ) ;
V_45 = V_46 ;
}
F_4 ( & V_2 -> V_37 ) ;
F_18 ( & V_2 -> V_41 ) ;
F_5 ( V_31 ) ;
V_29 -> V_40 = NULL ;
return 0 ;
}
static T_3 F_19 ( struct V_28 * V_29 ,
char T_4 * V_48 ,
T_5 V_49 ,
T_6 * V_50 )
{
struct V_30 * V_31 = V_29 -> V_40 ;
struct V_1 * V_2 = V_31 -> V_35 ;
struct V_44 * V_51 = NULL ;
T_3 V_52 = 0 ;
int V_53 = 0 ;
unsigned long V_54 = 0 ;
V_53 = F_20 (
V_2 -> V_55 ,
( V_31 -> V_47 ||
V_2 -> V_56 ) ) ;
if ( ( V_53 == - V_57 ) ) {
F_3 ( V_2 , V_12 , V_13 , V_14 ,
L_3 ) ;
return V_53 ;
}
if ( V_2 -> V_56 ) {
F_3 ( V_2 , V_12 , V_13 , V_14 ,
L_4 ) ;
return - V_58 ;
}
if ( false == V_2 -> V_59 )
return - V_15 ;
F_2 ( & V_2 -> V_37 ) ;
if ( V_31 -> V_47 ) {
V_51 = V_31 -> V_47 ;
F_21 ( V_31 -> V_47 ,
V_31 -> V_60 ) ;
V_31 -> V_61 -- ;
}
F_4 ( & V_2 -> V_37 ) ;
if ( V_51 ) {
V_52 = V_51 -> V_62 ;
V_54 = F_7 ( V_48 , V_51 -> V_63 ,
F_22 ( T_5 , V_52 , V_49 ) ) ;
if ( V_54 ) {
F_23 ( V_51 ) ;
F_3 ( V_2 , V_64 , 0 , 0 ,
L_5 ) ;
return - V_21 ;
}
F_3 ( V_2 , V_12 , V_13 , V_14 ,
L_6 ,
V_52 , V_51 , V_65 -> V_66 ) ;
F_23 ( V_51 ) ;
}
F_3 ( V_2 , V_12 , V_13 , V_14 , L_7 ) ;
return V_52 ;
}
static int F_24 ( void T_4 * V_67 ,
struct V_1 * V_2 )
{
struct V_68 V_69 = { 0 } ;
struct V_70 V_71 ;
T_7 V_72 ;
INT V_6 = V_7 ;
T_8 V_73 ;
T_9 V_74 ;
int V_75 ;
if ( F_25 ( & V_71 , V_67 , sizeof( struct V_70 ) ) )
return - V_21 ;
if ( V_71 . V_76 > sizeof( V_69 ) )
return - V_77 ;
if ( F_25 ( & V_69 , V_71 . V_78 ,
V_71 . V_76 ) )
return - V_21 ;
if ( V_71 . V_79 > V_80 ||
V_71 . V_79 == 0 ) {
return - V_77 ;
}
V_73 = V_71 . V_79 ;
V_74 = 4 - ( V_73 % 4 ) ;
V_73 += V_74 % 4 ;
V_72 = F_26 ( V_73 , V_33 ) ;
if ( ! V_72 )
return - V_34 ;
V_75 = F_27 ( V_2 , ( T_8 ) V_69 . Register ,
( V_16 ) V_72 , V_73 ) ;
if ( V_75 > 0 ) {
V_6 = V_19 ;
if ( F_7 ( V_71 . V_81 , V_72 , V_75 ) ) {
F_5 ( V_72 ) ;
return - V_21 ;
}
} else {
V_6 = V_75 ;
}
F_5 ( V_72 ) ;
return V_6 ;
}
static int F_28 ( void T_4 * V_67 ,
struct V_1 * V_2 )
{
struct V_82 V_83 = { 0 } ;
struct V_70 V_71 ;
T_8 V_42 = 0 ;
INT V_6 ;
if ( F_25 ( & V_71 , V_67 , sizeof( struct V_70 ) ) )
return - V_21 ;
if ( V_71 . V_76 > sizeof( V_83 ) )
return - V_77 ;
if ( F_25 ( & V_83 , V_71 . V_78 ,
V_71 . V_76 ) )
return - V_21 ;
V_42 = V_83 . Register & V_84 ;
if ( ! ( ( V_2 -> V_85 -> V_86 ) & V_87 ) &&
( ( V_42 == V_88 ) ||
( V_42 == V_89 ) ||
( V_42 == V_90 ) ||
( V_42 == V_91 ) ) ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_8 ) ;
return - V_21 ;
}
V_6 = F_29 ( V_2 , ( T_8 ) V_83 . Register ,
( V_16 ) V_83 . V_92 , sizeof( T_2 ) ) ;
if ( V_6 == V_19 ) {
F_3 ( V_2 , V_12 , V_13 ,
V_14 , L_9 ) ;
} else {
F_3 ( V_2 , V_12 , V_13 ,
V_14 , L_10 ) ;
V_6 = - V_21 ;
}
return V_6 ;
}
static int F_30 ( void T_4 * V_67 ,
struct V_1 * V_2 )
{
struct V_68 V_69 = { 0 } ;
struct V_70 V_71 ;
T_7 V_72 = NULL ;
T_8 V_42 = 0 ;
INT V_6 ;
int V_75 ;
if ( ( V_2 -> V_9 == TRUE ) ||
( V_2 -> V_10 == TRUE ) ||
( V_2 -> V_11 == TRUE ) ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_11 ) ;
return - V_15 ;
}
if ( F_25 ( & V_71 , V_67 , sizeof( struct V_70 ) ) )
return - V_21 ;
if ( V_71 . V_76 > sizeof( V_69 ) )
return - V_77 ;
if ( F_25 ( & V_69 , V_71 . V_78 ,
V_71 . V_76 ) )
return - V_21 ;
if ( V_71 . V_79 > V_80 ||
V_71 . V_79 == 0 ) {
return - V_77 ;
}
V_72 = F_26 ( V_71 . V_79 , V_33 ) ;
if ( ! V_72 )
return V_7 ;
if ( ( ( ( T_2 ) V_69 . Register & 0x0F000000 ) != 0x0F000000 ) ||
( ( T_2 ) V_69 . Register & 0x3 ) ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_12 ,
( int ) V_69 . Register ) ;
F_5 ( V_72 ) ;
return - V_77 ;
}
V_42 = V_69 . Register & V_84 ;
V_75 = F_31 ( V_2 , ( T_8 ) V_69 . Register ,
( V_16 ) V_72 , V_71 . V_79 ) ;
if ( V_75 > 0 ) {
V_6 = V_19 ;
if ( F_7 ( V_71 . V_81 , V_72 , V_75 ) ) {
F_5 ( V_72 ) ;
return - V_21 ;
}
} else {
V_6 = V_75 ;
}
F_5 ( V_72 ) ;
return V_6 ;
}
static int F_32 ( void T_4 * V_67 ,
struct V_1 * V_2 ,
T_8 V_93 )
{
struct V_82 V_83 = { 0 } ;
struct V_70 V_71 ;
T_8 V_42 = 0 ;
INT V_6 ;
if ( ( V_2 -> V_9 == TRUE ) ||
( V_2 -> V_10 == TRUE ) ||
( V_2 -> V_11 == TRUE ) ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_13 ) ;
return - V_15 ;
}
if ( F_25 ( & V_71 , V_67 , sizeof( struct V_70 ) ) )
return - V_21 ;
if ( V_71 . V_76 > sizeof( V_83 ) )
return - V_77 ;
if ( F_25 ( & V_83 , V_71 . V_78 ,
V_71 . V_76 ) )
return - V_21 ;
if ( ( ( ( T_2 ) V_83 . Register & 0x0F000000 ) != 0x0F000000 ) ||
( ( T_2 ) V_83 . Register & 0x3 ) ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_14 ,
( int ) V_83 . Register ) ;
return - V_77 ;
}
V_42 = V_83 . Register & V_84 ;
if ( ! ( ( V_2 -> V_85 -> V_86 ) & V_87 ) &&
( ( V_42 == V_88 ) ||
( V_42 == V_89 ) ||
( V_42 == V_90 ) ||
( V_42 == V_91 ) ) &&
( V_93 == V_94 ) ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_8 ) ;
return - V_21 ;
}
V_6 = F_33 ( V_2 , ( T_8 ) V_83 . Register ,
( V_16 ) V_83 . V_92 ,
V_83 . V_95 ) ;
if ( V_6 == V_19 ) {
F_3 ( V_2 , V_64 , V_13 ,
V_14 , L_9 ) ;
} else {
F_3 ( V_2 , V_12 , V_13 ,
V_14 , L_10 ) ;
V_6 = - V_21 ;
}
return V_6 ;
}
static int F_34 ( void T_4 * V_67 ,
struct V_1 * V_2 )
{
struct V_96 V_97 = { 0 } ;
struct V_70 V_71 ;
T_10 V_98 [ 4 ] ;
T_8 V_99 = 0 ;
T_8 V_100 = 0 ;
T_8 V_101 = 0 ;
INT V_6 ;
int V_75 ;
if ( ( V_2 -> V_9 == TRUE ) ||
( V_2 -> V_10 == TRUE ) ||
( V_2 -> V_11 == TRUE ) ) {
F_3 ( V_2 , V_12 , V_13 ,
V_14 ,
L_15 ) ;
return - V_15 ;
}
if ( F_25 ( & V_71 , V_67 , sizeof( struct V_70 ) ) )
return - V_21 ;
if ( V_71 . V_76 > sizeof( V_97 ) )
return - V_77 ;
if ( F_25 ( & V_97 , V_71 . V_78 ,
V_71 . V_76 ) )
return - V_21 ;
V_100 = V_97 . V_102 ;
V_101 = V_97 . V_103 ;
V_99 = ( 1 << V_100 ) ;
if ( F_35 ( V_2 , V_99 ) == false ) {
F_3 ( V_2 , V_12 , V_13 ,
V_14 ,
L_16 ,
V_99 ) ;
return - V_77 ;
}
if ( V_101 ) {
V_6 = F_33 ( V_2 ,
V_104 ,
( V_16 ) ( & V_99 ) , sizeof( T_8 ) ) ;
if ( V_6 == V_19 ) {
F_3 ( V_2 , V_12 ,
V_13 , V_14 ,
L_17 ) ;
} else {
F_3 ( V_2 , V_12 ,
V_13 , V_14 ,
L_18 ,
V_100 ) ;
return V_6 ;
}
} else {
V_6 = F_33 ( V_2 ,
V_105 ,
( V_16 ) ( & V_99 ) , sizeof( T_8 ) ) ;
if ( V_6 == V_19 ) {
F_3 ( V_2 , V_12 ,
V_13 , V_14 ,
L_17 ) ;
} else {
F_3 ( V_2 , V_12 ,
V_13 , V_14 ,
L_19 ,
V_100 ) ;
return V_6 ;
}
}
V_75 = F_31 ( V_2 , ( T_8 ) V_106 ,
( V_16 ) V_98 , sizeof( T_8 ) ) ;
if ( V_75 < 0 ) {
V_6 = V_75 ;
F_3 ( V_2 , V_12 , V_13 , V_14 ,
L_20 ) ;
return V_6 ;
}
V_6 = V_19 ;
* ( T_8 * ) V_98 |= ( 1 << V_100 ) ;
V_6 = F_33 ( V_2 , V_106 ,
( V_16 ) V_98 , sizeof( T_8 ) ) ;
if ( V_6 == V_19 ) {
F_3 ( V_2 , V_12 , V_13 ,
V_14 ,
L_21 ) ;
} else {
F_3 ( V_2 , V_12 , V_13 ,
V_14 ,
L_22 ) ;
}
return V_6 ;
}
static int F_36 ( void T_4 * V_67 ,
struct V_1 * V_2 )
{
struct V_107 V_108 = { 0 } ;
struct V_70 V_71 ;
F_3 ( V_2 , V_12 , V_13 , V_14 ,
L_23 ) ;
if ( ( V_2 -> V_9 == TRUE ) ||
( V_2 -> V_10 == TRUE ) ||
( V_2 -> V_11 == TRUE ) ) {
F_3 ( V_2 , V_12 , V_13 ,
V_14 ,
L_15 ) ;
return - V_15 ;
}
if ( F_25 ( & V_71 , V_67 , sizeof( struct V_70 ) ) )
return - V_21 ;
if ( V_71 . V_76 > sizeof( V_108 ) )
return - V_77 ;
if ( F_25 ( & V_108 , V_71 . V_78 ,
V_71 . V_76 ) )
return - V_21 ;
if ( V_2 -> V_109 . V_110 ) {
if ( V_108 . V_111 == V_112 ) {
F_3 ( V_2 , V_12 ,
V_13 , V_14 ,
L_24 ) ;
V_2 -> V_113 = V_114 ;
} else {
F_3 ( V_2 , V_12 ,
V_13 , V_14 ,
L_25 ) ;
V_2 -> V_113 = V_115 ;
}
F_37 ( & V_2 -> V_109 . V_116 ) ;
}
return V_19 ;
}
static int F_38 ( void T_4 * V_67 ,
struct V_1 * V_2 )
{
struct V_96 V_97 = { 0 } ;
struct V_70 V_71 ;
T_2 V_100 = 0 ;
T_10 V_117 [ 4 ] ;
INT V_6 ;
int V_75 ;
if ( ( V_2 -> V_9 == TRUE ) ||
( V_2 -> V_10 == TRUE ) ||
( V_2 -> V_11 == TRUE ) )
return - V_15 ;
if ( F_25 ( & V_71 , V_67 , sizeof( struct V_70 ) ) )
return - V_21 ;
if ( V_71 . V_76 > sizeof( V_97 ) )
return - V_77 ;
if ( F_25 ( & V_97 , V_71 . V_78 ,
V_71 . V_76 ) )
return - V_21 ;
V_100 = V_97 . V_102 ;
V_75 = F_31 ( V_2 , ( T_8 ) V_118 ,
( V_16 ) V_117 , sizeof( T_8 ) ) ;
if ( V_75 < 0 ) {
V_6 = V_75 ;
F_3 ( V_2 , V_64 , 0 , 0 ,
L_26 ) ;
return V_6 ;
}
V_6 = V_19 ;
return V_6 ;
}
static int F_39 ( void T_4 * V_67 ,
struct V_1 * V_2 )
{
struct V_119 V_120 [ V_121 ] ;
struct V_119 * V_122 =
(struct V_119 * ) V_120 ;
struct V_70 V_71 ;
T_10 V_98 [ 4 ] ;
INT V_6 = V_7 ;
int V_75 ;
memset ( V_122 , 0 ,
V_121 * sizeof( struct V_119 ) ) ;
if ( ( V_2 -> V_9 == TRUE ) ||
( V_2 -> V_10 == TRUE ) ||
( V_2 -> V_11 == TRUE ) )
return - V_77 ;
if ( F_25 ( & V_71 , V_67 , sizeof( struct V_70 ) ) )
return - V_21 ;
if ( V_71 . V_76 > sizeof( V_120 ) )
return - V_77 ;
if ( V_71 . V_79 > sizeof( V_120 ) )
V_71 . V_79 = sizeof( V_120 ) ;
if ( F_25 ( & V_120 , V_71 . V_78 ,
V_71 . V_76 ) )
return - V_21 ;
if ( F_35 ( V_2 , V_122 [ V_123 ] . V_124 )
== false ) {
F_3 ( V_2 , V_12 , V_13 ,
V_14 ,
L_27 ,
V_122 [ V_123 ] . V_124 ,
V_2 -> V_125 ) ;
return - V_77 ;
}
if ( ( V_122 [ V_123 ] . V_124 ) &
( V_122 [ V_123 ] . V_126 ) ) {
* ( T_8 * ) V_98 = V_122 [ V_123 ] . V_124 &
V_122 [ V_123 ] . V_126 &
V_122 [ V_123 ] . V_127 ;
if ( * ( T_8 * ) V_98 )
V_6 = F_33 ( V_2 ,
V_104 ,
( V_16 ) V_98 , sizeof( T_2 ) ) ;
if ( V_6 != V_19 ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_28 ) ;
return V_6 ;
}
* ( T_8 * ) V_98 =
( V_122 [ V_123 ] . V_124 &
V_122 [ V_123 ] . V_126 &
( ~ ( V_122 [ V_123 ] . V_127 ) ) ) ;
if ( * ( T_8 * ) V_98 )
V_6 = F_33 ( V_2 ,
V_105 , ( V_16 ) V_98 ,
sizeof( T_2 ) ) ;
if ( V_6 != V_19 ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_29 ) ;
return V_6 ;
}
}
if ( V_122 [ V_123 ] . V_124 ) {
V_75 = F_31 ( V_2 , ( T_8 ) V_118 ,
( V_16 ) V_98 , sizeof( T_8 ) ) ;
if ( V_75 < 0 ) {
V_6 = V_75 ;
F_3 ( V_2 , V_64 , 0 , 0 ,
L_30 ) ;
return V_6 ;
}
V_6 = V_19 ;
V_122 [ V_123 ] . V_127 =
( * ( T_8 * ) V_98 &
V_122 [ V_123 ] . V_124 ) ;
}
V_6 = F_7 ( V_71 . V_81 , & V_120 ,
V_71 . V_79 ) ;
if ( V_6 ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_31 ,
V_6 ) ;
return - V_21 ;
}
return V_6 ;
}
static int F_40 ( void T_4 * V_67 ,
struct V_1 * V_2 )
{
struct V_128 V_129 [ V_121 ] ;
struct V_128 * V_130 =
(struct V_128 * ) V_129 ;
struct V_70 V_71 ;
T_10 V_98 [ 4 ] ;
INT V_6 ;
int V_75 ;
if ( ( V_2 -> V_9 == TRUE ) ||
( V_2 -> V_10 == TRUE ) ||
( V_2 -> V_11 == TRUE ) )
return - V_77 ;
if ( F_25 ( & V_71 , V_67 , sizeof( struct V_70 ) ) )
return - V_21 ;
if ( V_71 . V_76 > sizeof( V_129 ) )
return - V_77 ;
if ( V_71 . V_79 > sizeof( V_129 ) )
V_71 . V_79 = sizeof( V_129 ) ;
if ( F_25 ( & V_129 , V_71 . V_78 ,
V_71 . V_76 ) )
return - V_21 ;
V_75 = F_31 ( V_2 , ( T_8 ) V_106 ,
( V_16 ) V_98 , sizeof( T_8 ) ) ;
if ( V_75 < 0 ) {
V_6 = V_75 ;
F_3 ( V_2 , V_64 , 0 , 0 ,
L_32 ) ;
return V_6 ;
}
V_6 = V_19 ;
if ( F_35 ( V_2 , V_130 [ V_123 ] . V_124 )
== false ) {
F_3 ( V_2 , V_12 , V_13 , V_14 ,
L_27 ,
V_130 [ V_123 ] . V_124 ,
V_2 -> V_125 ) ;
return - V_77 ;
}
if ( V_130 [ V_123 ] . V_124 ) {
* ( T_8 * ) V_98 |=
( V_130 [ V_123 ] . V_131 &
V_130 [ V_123 ] . V_124 ) ;
* ( T_8 * ) V_98 &=
~ ( ( ~ V_130 [ V_123 ] . V_131 ) &
V_130 [ V_123 ] . V_124 ) ;
V_130 [ V_123 ] . V_131 = * ( T_8 * ) V_98 ;
V_6 = F_33 ( V_2 , V_106 ,
( V_16 ) V_98 , sizeof( T_2 ) ) ;
if ( V_6 == V_19 ) {
F_3 ( V_2 ,
V_12 , V_13 , V_14 ,
L_33 ) ;
} else {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_34 ) ;
return - V_21 ;
}
} else {
V_130 [ V_123 ] . V_131 = * ( T_8 * ) V_98 ;
}
V_6 = F_7 ( V_71 . V_81 , & V_129 ,
V_71 . V_79 ) ;
if ( V_6 ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_31 ,
V_6 ) ;
return - V_21 ;
}
return V_6 ;
}
static int F_41 ( void T_4 * V_67 ,
struct V_1 * V_2 )
{
struct V_70 V_71 ;
T_11 V_132 = NULL ;
INT V_6 ;
if ( F_25 ( & V_71 , V_67 , sizeof( struct V_70 ) ) )
return - V_21 ;
if ( V_71 . V_76 < sizeof( struct V_133 ) )
return - V_77 ;
if ( V_71 . V_76 > V_134 )
return - V_77 ;
V_132 = F_42 ( V_71 . V_78 ,
V_71 . V_76 ) ;
if ( F_43 ( V_132 ) )
return F_44 ( V_132 ) ;
F_2 ( & V_2 -> V_135 ) ;
V_6 = F_45 (
V_2 -> V_136 ,
! V_2 -> V_11 ,
( 1 * V_137 ) ) ;
if ( V_6 == - V_57 )
goto V_138;
if ( V_2 -> V_11 ) {
F_3 ( V_2 , V_12 , V_13 , V_14 ,
L_35 ) ;
V_6 = V_7 ;
goto V_138;
}
V_6 = F_46 ( V_2 , ( T_11 ) V_132 ) ;
V_138:
F_4 ( & V_2 -> V_135 ) ;
F_5 ( V_132 ) ;
return V_6 ;
}
static int F_47 (
struct V_1 * V_2 )
{
INT V_6 ;
if ( F_48 ( & V_2 -> V_8 ) ) {
F_3 ( V_2 , V_12 , V_13 , V_14 ,
L_36 ) ;
return - V_15 ;
}
F_3 ( V_2 , V_64 , 0 , 0 ,
L_37 ,
V_65 -> V_66 ) ;
if ( F_48 ( & V_2 -> V_139 ) )
return - V_140 ;
V_2 -> V_141 = false ;
V_2 -> V_142 = V_65 -> V_66 ;
V_2 -> V_143 = false ;
V_2 -> V_59 = false ;
F_49 ( V_2 -> V_144 ) ;
F_50 ( V_2 -> V_144 ) ;
V_6 = F_51 ( V_2 ) ;
if ( V_6 ) {
F_52 ( V_145 L_38 , V_2 -> V_144 -> V_146 ) ;
F_4 ( & V_2 -> V_139 ) ;
F_4 ( & V_2 -> V_8 ) ;
return V_6 ;
}
F_53 ( 10 ) ;
F_4 ( & V_2 -> V_8 ) ;
return V_6 ;
}
static int F_54 ( void T_4 * V_67 ,
struct V_1 * V_2 )
{
struct V_147 * V_148 = NULL ;
struct V_70 V_71 ;
INT V_6 ;
F_3 ( V_2 , V_64 , 0 , 0 ,
L_37 , V_65 -> V_66 ) ;
if ( ! F_48 ( & V_2 -> V_139 ) ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_39 ) ;
F_4 ( & V_2 -> V_139 ) ;
return - V_77 ;
}
if ( F_25 ( & V_71 , V_67 , sizeof( struct V_70 ) ) ) {
F_4 ( & V_2 -> V_139 ) ;
return - V_21 ;
}
F_3 ( V_2 , V_64 , 0 , 0 ,
L_40 , V_71 . V_76 ) ;
if ( V_71 . V_76 > sizeof( struct V_147 ) ) {
F_4 ( & V_2 -> V_139 ) ;
return - V_77 ;
}
V_148 = F_26 ( sizeof( * V_148 ) , V_33 ) ;
if ( ! V_148 ) {
F_4 ( & V_2 -> V_139 ) ;
return - V_34 ;
}
if ( F_25 ( V_148 , V_71 . V_78 ,
V_71 . V_76 ) ) {
F_4 ( & V_2 -> V_139 ) ;
F_5 ( V_148 ) ;
return - V_21 ;
}
if ( ! V_148 -> V_149 ||
( V_148 -> V_150 == 0 ) ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_41 ,
V_148 -> V_150 ) ;
F_4 ( & V_2 -> V_139 ) ;
F_5 ( V_148 ) ;
V_6 = - V_77 ;
return V_6 ;
}
V_6 = F_55 ( V_2 , V_148 ) ;
if ( V_6 != V_19 ) {
if ( V_148 -> V_151 == V_152 )
F_3 ( V_2 , V_64 , 0 , 0 ,
L_42 ) ;
else
F_3 ( V_2 , V_64 , 0 , 0 ,
L_43 ) ;
if ( V_2 -> V_109 . V_110 &
V_153 ) {
V_2 -> V_113 = V_154 ;
V_2 -> V_109 . V_155 = false ;
F_37 ( & V_2 -> V_109 . V_116 ) ;
}
}
if ( V_6 != V_19 )
F_4 ( & V_2 -> V_139 ) ;
F_3 ( V_2 , V_64 , V_13 , V_14 ,
L_44 ) ;
F_5 ( V_148 ) ;
return V_6 ;
}
static int F_56 ( void T_4 * V_67 ,
struct V_1 * V_2 )
{
INT V_6 ;
int V_156 = 0 ;
if ( ! F_48 ( & V_2 -> V_139 ) ) {
F_4 ( & V_2 -> V_139 ) ;
return - V_77 ;
}
if ( F_48 ( & V_2 -> V_8 ) ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_45 ) ;
F_4 ( & V_2 -> V_139 ) ;
return - V_15 ;
}
V_2 -> V_141 = TRUE ;
V_2 -> V_143 = TRUE ;
F_57 ( & V_2 -> V_157 , 0 ) ;
V_2 -> V_158 = 0 ;
V_2 -> V_159 = 0 ;
V_6 = F_58 ( V_2 ) ;
if ( V_6 ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_46 ) ;
F_4 ( & V_2 -> V_139 ) ;
F_4 ( & V_2 -> V_8 ) ;
return V_6 ;
}
F_3 ( V_2 , V_12 , V_13 ,
V_14 , L_47 ) ;
F_53 ( 10 ) ;
if ( F_59 ( (struct V_160 * ) V_2 -> V_161 ) )
F_3 ( V_2 , V_64 , 0 , 0 ,
L_48 ) ;
V_156 = 5 * V_137 ;
V_2 -> V_162 = false ;
F_60 ( V_2 -> V_163 ,
V_2 -> V_162 , V_156 ) ;
V_2 -> V_142 = V_164 ;
V_2 -> V_59 = TRUE ;
F_57 ( & V_2 -> V_157 , 0 ) ;
V_2 -> V_158 = 0 ;
V_2 -> V_165 = 0 ;
F_57 ( & V_2 -> V_166 , 0 ) ;
V_2 -> V_167 = 0 ;
V_2 -> V_168 = 0 ;
if ( V_2 -> V_109 . V_110 &
V_153 ) {
V_2 -> V_113 = V_169 ;
F_37 ( & V_2 -> V_109 . V_116 ) ;
}
if ( ! V_156 )
V_6 = - V_58 ;
F_4 ( & V_2 -> V_139 ) ;
F_4 ( & V_2 -> V_8 ) ;
return V_6 ;
}
static int F_61 ( struct V_1 * V_2 )
{
INT V_6 ;
INT V_170 ;
V_170 = F_48 ( & V_2 -> V_8 ) ;
if ( V_170 ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_49 ) ;
return - V_15 ;
}
F_2 ( & V_2 -> V_37 ) ;
V_6 = F_51 ( V_2 ) ;
F_62 () ;
F_4 ( & V_2 -> V_37 ) ;
F_4 ( & V_2 -> V_8 ) ;
F_63 ( V_2 ) ;
return V_6 ;
}
static int F_64 ( T_2 V_171 ,
struct V_1 * V_2 )
{
T_12 V_172 ;
for ( V_172 = 0 ; V_172 < V_173 ; V_172 ++ ) {
if ( F_65 ( V_2 -> V_174 [ V_172 ] . V_175 ,
( unsigned long T_4 * ) V_171 ) ) {
return - V_21 ;
}
}
return 0 ;
}
static int F_66 ( void T_4 * V_67 ,
struct V_1 * V_2 )
{
T_8 V_63 = 0 ;
if ( F_25 ( & V_63 , V_67 , sizeof( T_8 ) ) )
return - V_21 ;
if ( V_63 ) {
F_3 ( V_2 , V_12 , V_13 , V_14 ,
L_50 ) ;
V_2 -> V_176 = V_177 ;
} else {
F_3 ( V_2 , V_12 , V_13 , V_14 ,
L_51 ) ;
V_2 -> V_176 = V_178 ;
}
return V_19 ;
}
static int F_67 ( void T_4 * V_67 )
{
struct V_70 V_71 ;
T_13 V_62 ;
if ( F_25 ( & V_71 , V_67 , sizeof( struct V_70 ) ) )
return - V_21 ;
V_62 = F_22 ( T_13 , V_71 . V_79 , strlen ( V_179 ) + 1 ) ;
if ( F_7 ( V_71 . V_81 , V_179 , V_62 ) )
return - V_21 ;
return V_19 ;
}
static int F_68 ( void T_4 * V_67 ,
struct V_1 * V_2 )
{
struct V_180 V_181 ;
struct V_70 V_71 ;
if ( F_25 ( & V_71 , V_67 , sizeof( struct V_70 ) ) ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_52 ) ;
return - V_21 ;
}
if ( V_71 . V_79 != sizeof( V_181 ) )
return - V_77 ;
memset ( & V_181 , 0 , sizeof( V_181 ) ) ;
V_181 . V_182 = V_2 -> V_9 ;
V_181 . V_183 = V_2 -> V_10 ;
V_181 . V_184 = V_2 -> V_168 ;
if ( F_7 ( V_71 . V_81 , & V_181 , F_22 ( T_5 ,
sizeof( V_181 ) , V_71 . V_79 ) ) ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_53 ) ;
return - V_21 ;
}
return V_19 ;
}
static int F_69 ( void T_4 * V_67 ,
struct V_1 * V_2 )
{
struct V_70 V_71 ;
T_8 V_185 ;
if ( F_25 ( & V_71 , V_67 , sizeof( struct V_70 ) ) )
return - V_21 ;
if ( F_25 ( & V_185 , V_71 . V_78 , sizeof( T_8 ) ) )
return - V_21 ;
if ( V_185 )
V_2 -> V_39 -> V_186 = TRUE ;
else
V_2 -> V_39 -> V_186 = false ;
return V_19 ;
}
static int F_70 ( void T_4 * V_67 ,
struct V_1 * V_2 )
{
struct V_70 V_71 ;
T_2 V_187 = 0 ;
if ( F_25 ( & V_71 , V_67 , sizeof( struct V_70 ) ) )
return - V_21 ;
if ( V_71 . V_79 < sizeof( struct V_188 ) ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_54 ,
V_71 . V_79 ,
sizeof( struct V_188 ) ) ;
return - V_77 ;
}
if ( F_25 ( & V_187 , V_71 . V_78 , sizeof( V_187 ) ) )
return - V_21 ;
F_3 ( V_2 , V_12 , V_13 , V_14 ,
L_55 , V_187 ) ;
F_71 ( V_2 , V_187 , V_71 . V_81 ) ;
return V_19 ;
}
static int F_72 ( void T_4 * V_67 ,
struct V_1 * V_2 ,
struct V_30 * V_31 )
{
struct V_70 V_71 ;
INT V_6 = V_7 ;
T_11 V_72 ;
if ( F_25 ( & V_71 , V_67 , sizeof( struct V_70 ) ) )
return - V_21 ;
if ( V_71 . V_79 != sizeof( struct V_189 ) ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_56 , V_71 . V_79 ,
sizeof( struct V_189 ) ) ;
return - V_77 ;
}
V_72 = F_13 ( sizeof( struct V_189 ) , V_33 ) ;
if ( ! V_72 )
return V_7 ;
V_6 = F_73 ( V_2 , V_72 ) ;
F_74 ( V_72 , V_31 ) ;
if ( V_6 != V_7 ) {
if ( F_7 ( V_71 . V_81 , V_72 ,
sizeof( struct V_189 ) ) ) {
F_5 ( V_72 ) ;
return - V_21 ;
}
}
F_5 ( V_72 ) ;
return V_6 ;
}
static int F_75 ( void T_4 * V_67 ,
struct V_1 * V_2 , T_8 V_93 )
{
struct V_190 * V_191 ;
struct V_70 V_71 ;
T_8 V_42 = 0 ;
INT V_6 = V_7 ;
T_7 V_132 = NULL ;
if ( ( V_2 -> V_9 == TRUE ) ||
( V_2 -> V_10 == TRUE ) ||
( V_2 -> V_11 == TRUE ) ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_57 ) ;
return - V_15 ;
}
if ( F_25 ( & V_71 , V_67 , sizeof( struct V_70 ) ) )
return - V_21 ;
if ( V_71 . V_76 < sizeof( T_2 ) * 2 )
return - V_77 ;
V_132 = F_42 ( V_71 . V_78 ,
V_71 . V_76 ) ;
if ( F_43 ( V_132 ) )
return F_44 ( V_132 ) ;
V_191 = (struct V_190 * ) V_132 ;
if ( ( ( T_2 ) V_191 -> Register & 0x0F000000 ) != 0x0F000000 ||
( ( T_2 ) V_191 -> Register & 0x3 ) ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_14 ,
( int ) V_191 -> Register ) ;
F_5 ( V_132 ) ;
return - V_77 ;
}
V_42 = V_191 -> Register & V_84 ;
if ( ! ( ( V_2 -> V_85 -> V_86 ) & V_87 ) &&
( ( V_42 == V_88 ) ||
( V_42 == V_89 ) ||
( V_42 == V_90 ) ||
( V_42 == V_91 ) ) &&
( V_93 == V_94 ) ) {
F_5 ( V_132 ) ;
F_3 ( V_2 , V_64 , 0 , 0 ,
L_8 ) ;
return - V_21 ;
}
if ( V_191 -> V_192 == false )
V_6 = F_76 ( V_2 , ( T_8 ) V_191 -> Register ,
( T_7 ) V_191 -> V_193 ,
V_71 . V_76 - 2 * sizeof( T_2 ) ) ;
else
V_6 = F_33 ( V_2 , ( T_8 ) V_191 -> Register ,
( V_16 ) V_191 -> V_193 ,
V_71 . V_76 - 2 * sizeof( T_2 ) ) ;
if ( V_6 != V_19 )
F_3 ( V_2 , V_64 , 0 , 0 , L_10 ) ;
F_5 ( V_132 ) ;
return V_6 ;
}
static int F_77 ( void T_4 * V_67 ,
struct V_1 * V_2 )
{
struct V_70 V_71 ;
if ( F_25 ( & V_71 , V_67 , sizeof( struct V_70 ) ) )
return - V_21 ;
if ( V_2 -> V_194 == V_195 || V_2 -> V_194 == V_196 ) {
if ( F_7 ( V_71 . V_81 , & V_2 -> V_24 ,
sizeof( T_8 ) ) )
return - V_21 ;
}
return V_19 ;
}
static int F_78 ( void T_4 * V_67 ,
struct V_1 * V_2 )
{
struct V_70 V_71 ;
T_8 V_197 = 0 ;
INT V_6 = V_7 ;
if ( V_2 -> V_194 == V_196 ) {
if ( F_25 ( & V_71 , V_67 ,
sizeof( struct V_70 ) ) )
return - V_21 ;
if ( F_25 ( & V_197 , V_71 . V_78 ,
sizeof( T_8 ) ) )
return - V_21 ;
if ( ( V_197 < V_198 ) ||
( V_197 > V_199 ) ) {
if ( F_7 ( V_71 . V_81 ,
& V_2 -> V_200 , sizeof( T_8 ) ) )
return - V_21 ;
} else {
if ( F_79 ( V_2 ) ) {
if ( F_7 ( V_71 . V_81 ,
& V_2 -> V_200 , sizeof( T_8 ) ) )
return - V_21 ;
} else {
if ( ( TRUE == V_2 -> V_10 ) ||
( TRUE == V_2 -> V_9 ) ) {
F_3 ( V_2 ,
V_64 , 0 , 0 ,
L_1 ) ;
return - V_15 ;
}
V_2 -> V_200 = V_197 ;
F_80 ( V_2 ,
V_2 -> V_200 ) ;
}
}
V_6 = V_19 ;
} else {
V_6 = V_7 ;
}
return V_6 ;
}
static int F_81 ( void T_4 * V_67 ,
struct V_1 * V_2 )
{
#ifdef F_82
struct V_70 V_71 ;
struct V_201 V_202 ;
F_3 ( V_2 , V_12 , V_13 , V_14 ,
L_58 ) ;
if ( F_25 ( & V_71 , V_67 , sizeof( struct V_70 ) ) )
return - V_21 ;
if ( F_25 ( & V_202 , V_71 . V_78 ,
sizeof( struct V_201 ) ) )
return - V_21 ;
F_3 ( V_2 , V_64 , 0 , 0 ,
L_59 ,
V_202 . V_203 , V_202 . Type ) ;
V_202 . V_204 = 1 << V_202 . V_204 ;
F_3 ( V_2 , V_64 , 0 , 0 ,
L_60 , V_202 . V_204 ) ;
V_2 -> V_205 . type |= V_202 . Type ;
if ( V_202 . V_203 )
V_2 -> V_205 . V_206 [ V_202 . Type ] |=
V_202 . V_204 ;
else
V_2 -> V_205 . V_206 [ V_202 . Type ] &=
~ V_202 . V_204 ;
F_83 ( V_2 ) ;
#endif
return V_19 ;
}
static int F_84 ( void T_4 * V_67 ,
struct V_1 * V_2 , T_8 V_93 )
{
struct V_4 V_5 ;
struct V_207 V_208 , V_209 ;
struct V_70 V_71 ;
T_1 V_3 = NULL ;
INT V_6 = V_7 ;
memset ( & V_208 , 0 , sizeof( struct V_207 ) ) ;
memset ( & V_209 , 0 , sizeof( struct V_207 ) ) ;
if ( ( V_2 -> V_194 == V_196 ) &&
( V_2 -> V_210 == 0 ) ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_61 ) ;
return - V_21 ;
}
if ( F_79 ( V_2 ) ) {
if ( ( V_2 -> V_23 != V_211 ) &&
( V_2 -> V_23 != V_212 ) &&
( V_2 -> V_23 != V_213 ) ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_62 ) ;
return V_7 ;
}
}
if ( F_25 ( & V_71 , V_67 , sizeof( struct V_70 ) ) )
return - V_21 ;
if ( F_25 ( & V_5 ,
( V_214 == V_93 ) ?
V_71 . V_81 : V_71 . V_78 ,
sizeof( struct V_4 ) ) )
return - V_21 ;
if ( V_5 . V_18 > V_2 -> V_24 )
return V_7 ;
if ( V_5 . V_17 >
V_2 -> V_24 - V_5 . V_18 )
return V_7 ;
V_3 = F_42 ( V_5 . V_20 ,
V_5 . V_18 ) ;
if ( F_43 ( V_3 ) )
return F_44 ( V_3 ) ;
F_85 ( & V_208 ) ;
if ( V_214 == V_93 ) {
int V_54 = F_1 ( V_2 , V_3 ,
& V_5 ) ;
if ( V_54 != V_19 )
return V_54 ;
} else {
F_2 ( & V_2 -> V_8 ) ;
if ( ( V_2 -> V_9 == TRUE ) ||
( V_2 -> V_10 == TRUE ) ||
( V_2 -> V_11 == TRUE ) ) {
F_3 ( V_2 ,
V_12 , V_13 , V_14 ,
L_1 ) ;
F_4 ( & V_2 -> V_8 ) ;
F_5 ( V_3 ) ;
return - V_15 ;
}
V_2 -> V_215 = TRUE ;
if ( F_79 ( V_2 ) ) {
int V_54 = F_8 ( V_2 ,
V_3 ,
& V_5 ) ;
if ( V_54 != V_19 )
return V_54 ;
}
V_6 = F_86 ( V_2 , ( V_16 ) V_3 ,
V_5 . V_17 , V_5 . V_18 ,
V_5 . V_216 ) ;
if ( F_79 ( V_2 ) )
F_87 ( V_2 , V_2 -> V_23 ) ;
V_2 -> V_215 = false ;
F_4 ( & V_2 -> V_8 ) ;
if ( V_6 != V_19 ) {
F_5 ( V_3 ) ;
return V_6 ;
}
}
F_85 ( & V_209 ) ;
F_3 ( V_2 , V_12 , V_13 , V_14 ,
L_63 ,
( V_209 . V_217 - V_208 . V_217 ) * 1000 +
( V_209 . V_218 - V_208 . V_218 ) / 1000 ) ;
F_5 ( V_3 ) ;
return V_19 ;
}
static int F_88 ( void T_4 * V_67 ,
struct V_1 * V_2 )
{
struct V_219 V_220 = { 0 } ;
struct V_70 V_71 ;
T_1 V_221 = NULL ;
T_8 V_222 = 0 ;
T_8 V_223 = 0 ;
T_8 V_224 = 0 ;
T_8 V_225 = 0 ;
INT V_6 = V_7 ;
void T_4 * V_226 ;
if ( F_79 ( V_2 ) != TRUE ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_64 ) ;
return - V_77 ;
}
F_3 ( V_2 , V_12 , V_13 ,
V_14 , L_65 ) ;
if ( F_25 ( & V_71 , V_67 , sizeof( struct V_70 ) ) )
return - V_21 ;
if ( F_25 ( & V_220 , V_71 . V_78 ,
sizeof( struct V_219 ) ) )
return - V_21 ;
F_3 ( V_2 , V_12 , V_13 , V_14 ,
L_66 ,
V_220 . V_227 ) ;
F_3 ( V_2 , V_12 , V_13 , V_14 ,
L_67 ,
V_220 . V_228 ) ;
F_3 ( V_2 , V_12 , V_13 , V_14 ,
L_68 ,
V_220 . V_229 ) ;
F_3 ( V_2 , V_12 , V_13 , V_14 ,
L_69 ,
V_220 . V_216 ) ;
if ( F_89 ( V_2 , & V_220 ) == false )
return V_7 ;
V_222 = V_220 . V_229 ;
if ( V_222 > V_2 -> V_200 )
V_223 = V_2 -> V_200 ;
else
V_223 = V_222 ;
V_225 = V_220 . V_228 ;
V_226 = V_71 . V_81 ;
V_221 = F_13 ( V_223 , V_33 ) ;
if ( V_221 == NULL ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_70 ) ;
return - V_34 ;
}
F_2 ( & V_2 -> V_8 ) ;
if ( ( V_2 -> V_9 == TRUE ) ||
( V_2 -> V_10 == TRUE ) ||
( V_2 -> V_11 == TRUE ) ) {
F_3 ( V_2 , V_12 , V_13 ,
V_14 ,
L_1 ) ;
F_4 ( & V_2 -> V_8 ) ;
F_5 ( V_221 ) ;
return - V_15 ;
}
while ( V_222 ) {
if ( V_222 > V_2 -> V_200 )
V_224 = V_2 -> V_200 ;
else
V_224 = V_222 ;
V_6 = F_90 ( V_2 , ( V_16 ) V_221 ,
V_220 . V_227 , V_225 , V_224 ) ;
if ( V_6 ) {
F_3 ( V_2 ,
V_12 , V_13 , V_14 ,
L_71 ,
V_6 ) ;
break;
}
F_91 ( V_2 , V_12 , V_13 ,
V_14 , V_221 , V_224 ) ;
V_6 = F_7 ( V_226 , V_221 , V_224 ) ;
if ( V_6 ) {
F_3 ( V_2 ,
V_12 , V_13 , V_14 ,
L_72 , V_6 ) ;
F_4 ( & V_2 -> V_8 ) ;
F_5 ( V_221 ) ;
return - V_21 ;
}
V_222 = V_222 - V_224 ;
if ( V_222 ) {
V_225 = V_225 + V_224 ;
V_226 = V_226 + V_224 ;
}
}
F_4 ( & V_2 -> V_8 ) ;
F_5 ( V_221 ) ;
return V_6 ;
}
static int F_92 ( void T_4 * V_67 ,
struct V_1 * V_2 )
{
struct V_219 V_230 = { 0 } ;
struct V_70 V_71 ;
T_1 V_231 ;
void T_4 * V_232 ;
T_8 V_222 = 0 ;
T_8 V_223 = 0 ;
T_8 V_233 = 0 ;
T_8 V_234 = 0 ;
INT V_6 = V_7 ;
if ( F_79 ( V_2 ) != TRUE ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_64 ) ;
return - V_77 ;
}
V_2 -> V_235 = false ;
F_3 ( V_2 , V_12 , V_13 , V_14 ,
L_73 ) ;
if ( F_25 ( & V_71 , V_67 , sizeof( struct V_70 ) ) )
return - V_21 ;
if ( F_25 ( & V_230 , V_71 . V_78 ,
sizeof( struct V_219 ) ) )
return - V_21 ;
F_3 ( V_2 , V_12 , V_13 , V_14 ,
L_74 , V_230 . V_227 ) ;
F_3 ( V_2 , V_12 , V_13 , V_14 ,
L_75 , V_230 . V_228 ) ;
F_3 ( V_2 , V_12 , V_13 , V_14 ,
L_76 , V_230 . V_229 ) ;
F_3 ( V_2 , V_12 , V_13 , V_14 ,
L_77 , V_230 . V_216 ) ;
if ( ( V_230 . V_227 != V_236 ) && ( V_230 . V_227 != V_237 )
&& ( V_230 . V_227 != V_238 ) ) {
F_3 ( V_2 , V_12 , V_13 , V_14 ,
L_78 ) ;
return - V_77 ;
}
if ( F_89 ( V_2 , & V_230 ) == false )
return V_7 ;
V_232 = V_230 . V_239 ;
V_233 = V_230 . V_228 ;
V_222 = V_230 . V_229 ;
if ( V_222 > V_2 -> V_200 )
V_223 = V_2 -> V_200 ;
else
V_223 = V_222 ;
V_231 = F_26 ( V_223 , V_33 ) ;
if ( V_231 == NULL )
return - V_34 ;
V_234 = V_2 -> V_200 ;
if ( V_233 % V_2 -> V_200 ) {
V_234 = V_2 -> V_200 -
( V_233 % V_2 -> V_200 ) ;
}
if ( V_222 < V_234 )
V_234 = V_222 ;
F_2 ( & V_2 -> V_8 ) ;
if ( ( V_2 -> V_9 == TRUE ) ||
( V_2 -> V_10 == TRUE ) ||
( V_2 -> V_11 == TRUE ) ) {
F_3 ( V_2 , V_12 , V_13 , V_14 ,
L_1 ) ;
F_4 ( & V_2 -> V_8 ) ;
F_5 ( V_231 ) ;
return - V_15 ;
}
F_9 ( V_2 , V_230 . V_227 ) ;
do {
V_6 = F_25 ( V_231 , V_232 , V_234 ) ;
if ( V_6 ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_79 , V_6 ) ;
F_4 ( & V_2 -> V_8 ) ;
F_5 ( V_231 ) ;
return - V_21 ;
}
F_91 ( V_2 , V_12 ,
V_13 , V_14 , V_231 , V_234 ) ;
V_6 = F_93 ( V_2 , ( V_16 ) V_231 ,
V_230 . V_227 ,
V_233 ,
V_234 ,
V_230 . V_216 ) ;
if ( V_6 ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_71 , V_6 ) ;
break;
}
V_222 = V_222 - V_234 ;
if ( V_222 ) {
V_233 = V_233 + V_234 ;
V_232 = V_232 + V_234 ;
if ( V_222 > V_2 -> V_200 )
V_234 = V_2 -> V_200 ;
else
V_234 = V_222 ;
}
} while ( V_222 > 0 );
F_87 ( V_2 , V_230 . V_227 ) ;
F_4 ( & V_2 -> V_8 ) ;
F_5 ( V_231 ) ;
return V_6 ;
}
static int F_94 ( void T_4 * V_67 ,
struct V_1 * V_2 )
{
struct V_240 * V_241 ;
struct V_70 V_71 ;
F_3 ( V_2 , V_12 , V_13 , V_14 ,
L_80 ) ;
if ( F_25 ( & V_71 , V_67 , sizeof( struct V_70 ) ) )
return - V_21 ;
if ( V_71 . V_79 != sizeof( struct V_240 ) )
return - V_77 ;
V_241 = F_13 ( sizeof( struct V_240 ) ,
V_33 ) ;
if ( V_241 == NULL ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_81 ) ;
return - V_34 ;
}
F_2 ( & V_2 -> V_8 ) ;
if ( ( V_2 -> V_9 == TRUE ) ||
( V_2 -> V_10 == TRUE ) ||
( V_2 -> V_11 == TRUE ) ) {
F_3 ( V_2 , V_12 , V_13 , V_14 ,
L_1 ) ;
F_4 ( & V_2 -> V_8 ) ;
F_5 ( V_241 ) ;
return - V_15 ;
}
F_95 ( V_2 , V_241 ) ;
F_4 ( & V_2 -> V_8 ) ;
if ( F_7 ( V_71 . V_81 , V_241 ,
sizeof( struct V_240 ) ) ) {
F_5 ( V_241 ) ;
return - V_21 ;
}
F_5 ( V_241 ) ;
return V_7 ;
}
static int F_96 ( void T_4 * V_67 ,
struct V_1 * V_2 )
{
enum V_242 V_243 = 0 ;
INT V_6 = V_7 ;
struct V_70 V_71 ;
F_3 ( V_2 , V_12 , V_13 , V_14 ,
L_82 ) ;
if ( F_79 ( V_2 ) != TRUE ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_64 ) ;
return - V_77 ;
}
V_6 = F_25 ( & V_71 , V_67 ,
sizeof( struct V_70 ) ) ;
if ( V_6 ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_83 ) ;
return - V_21 ;
}
V_6 = F_25 ( & V_243 ,
V_71 . V_78 , sizeof( INT ) ) ;
if ( V_6 ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_84 ) ;
return - V_21 ;
}
F_2 ( & V_2 -> V_8 ) ;
if ( ( V_2 -> V_9 == TRUE ) ||
( V_2 -> V_10 == TRUE ) ||
( V_2 -> V_11 == TRUE ) ) {
F_3 ( V_2 , V_12 , V_13 , V_14 ,
L_1 ) ;
F_4 ( & V_2 -> V_8 ) ;
return - V_15 ;
}
V_6 = F_97 ( V_2 , V_243 ) ;
if ( V_6 )
F_3 ( V_2 , V_64 , 0 , 0 ,
L_85 ,
V_6 ) ;
F_4 ( & V_2 -> V_8 ) ;
return V_6 ;
}
static int F_98 ( void T_4 * V_67 ,
struct V_1 * V_2 )
{
struct V_244 V_245 = { 0 } ;
struct V_70 V_71 ;
INT V_6 = V_19 ;
F_3 ( V_2 , V_12 , V_13 , V_14 ,
L_86 ) ;
V_2 -> V_235 = false ;
if ( F_79 ( V_2 ) != TRUE ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_64 ) ;
return - V_77 ;
}
V_6 = F_25 ( & V_71 , V_67 ,
sizeof( struct V_70 ) ) ;
if ( V_6 ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_87 ,
V_6 ) ;
return - V_21 ;
}
V_6 = F_25 ( & V_245 , V_71 . V_78 ,
sizeof( struct V_244 ) ) ;
if ( V_6 ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_88 ,
V_6 ) ;
return - V_21 ;
}
F_3 ( V_2 , V_12 , V_13 , V_14 ,
L_89 , V_245 . V_246 ) ;
F_3 ( V_2 , V_12 , V_13 , V_14 ,
L_90 , V_245 . V_247 ) ;
F_3 ( V_2 , V_12 , V_13 , V_14 ,
L_91 , V_245 . V_228 ) ;
F_3 ( V_2 , V_12 , V_13 , V_14 ,
L_92 , V_245 . V_229 ) ;
if ( F_99 ( V_2 , V_245 . V_246 ) == false ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_93 ,
V_245 . V_246 ) ;
return - V_77 ;
}
if ( F_99 ( V_2 , V_245 . V_247 ) == false ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_94 ,
V_245 . V_247 ) ;
return - V_77 ;
}
if ( V_245 . V_246 == V_245 . V_247 ) {
F_3 ( V_2 , V_12 , V_13 , V_14 ,
L_95 ) ;
return - V_77 ;
}
F_2 ( & V_2 -> V_8 ) ;
if ( ( V_2 -> V_9 == TRUE ) ||
( V_2 -> V_10 == TRUE ) ||
( V_2 -> V_11 == TRUE ) ) {
F_3 ( V_2 , V_12 , V_13 , V_14 ,
L_1 ) ;
F_4 ( & V_2 -> V_8 ) ;
return - V_15 ;
}
if ( V_245 . V_246 == V_248 ||
V_245 . V_246 == V_249 ) {
if ( F_100 ( V_2 ) ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_96 ) ;
V_6 = - V_77 ;
} else if ( V_245 . V_229 == 0 ) {
V_6 = F_101 ( V_2 , V_245 ) ;
} else {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_97 ) ;
V_6 = V_7 ;
}
F_4 ( & V_2 -> V_8 ) ;
return V_6 ;
}
V_6 = F_102 ( V_2 , V_245 . V_246 ,
V_245 . V_247 ,
V_245 . V_228 ,
V_245 . V_229 ) ;
F_4 ( & V_2 -> V_8 ) ;
return V_6 ;
}
static int F_103 ( void T_4 * V_67 ,
struct V_1 * V_2 )
{
struct V_70 V_71 ;
INT V_6 = V_19 ;
F_3 ( V_2 , V_12 , V_13 , V_14 ,
L_98 ) ;
V_6 = F_25 ( & V_71 , V_67 ,
sizeof( struct V_70 ) ) ;
if ( V_6 ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_83 ) ;
return - V_21 ;
}
if ( V_2 -> V_194 != V_196 ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_99 ) ;
return - V_77 ;
}
if ( F_79 ( V_2 ) == TRUE ) {
if ( V_71 . V_79 < sizeof( struct V_250 ) )
return - V_77 ;
if ( F_7 ( V_71 . V_81 ,
V_2 -> V_251 ,
sizeof( struct V_250 ) ) )
return - V_21 ;
} else {
if ( V_71 . V_79 < sizeof( struct V_252 ) )
return - V_77 ;
if ( F_7 ( V_71 . V_81 , V_2 -> V_253 ,
sizeof( struct V_252 ) ) )
return - V_21 ;
}
return V_6 ;
}
static int F_104 ( void T_4 * V_67 ,
struct V_1 * V_2 )
{
struct V_70 V_71 ;
INT V_6 = V_7 ;
T_8 V_254 = 0 ;
enum V_242 V_243 ;
V_243 = V_255 ;
F_3 ( V_2 , V_12 , V_13 , V_14 ,
L_100 ) ;
if ( F_79 ( V_2 ) != TRUE ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_64 ) ;
return - V_77 ;
}
V_6 = F_25 ( & V_71 , V_67 ,
sizeof( struct V_70 ) ) ;
if ( V_6 ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_83 ) ;
return - V_21 ;
}
V_6 = F_25 ( & V_243 , V_71 . V_78 ,
sizeof( INT ) ) ;
if ( V_6 ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_84 ) ;
return - V_21 ;
}
F_3 ( V_2 , V_12 , V_13 , V_14 ,
L_101 , V_243 ) ;
if ( ( V_243 != V_211 ) &&
( V_243 != V_212 ) &&
( V_243 != V_213 ) ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_102 ,
V_243 ) ;
return V_7 ;
}
V_254 = F_105 ( V_2 , V_243 ) ;
if ( V_254 == V_256 ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_103 ,
V_243 ) ;
return - V_77 ;
}
V_2 -> V_235 = TRUE ;
V_2 -> V_257 = V_254 ;
V_2 -> V_23 = V_243 ;
return V_19 ;
}
static int F_106 ( void T_4 * V_67 ,
struct V_1 * V_2 )
{
struct V_4 V_258 ;
struct V_70 V_71 ;
unsigned int V_222 ;
INT V_223 ;
INT V_225 = 0 ;
T_8 V_224 = 0 ;
T_1 V_221 ;
void T_4 * V_226 ;
INT V_6 = V_7 ;
if ( V_2 -> V_194 != V_196 ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_104 ) ;
return - V_77 ;
}
if ( F_25 ( & V_71 , V_67 , sizeof( struct V_70 ) ) ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_105 ) ;
return - V_21 ;
}
if ( F_25 ( & V_258 , V_71 . V_81 ,
sizeof( struct V_4 ) ) )
return - V_21 ;
V_222 = V_258 . V_18 ;
if ( V_222 > V_259 )
V_223 = V_259 ;
else
V_223 = V_222 ;
V_225 = V_258 . V_17 ;
V_226 = V_258 . V_20 ;
V_221 = F_13 ( V_223 , V_33 ) ;
if ( V_221 == NULL ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_70 ) ;
return - V_34 ;
}
F_2 ( & V_2 -> V_8 ) ;
if ( ( V_2 -> V_9 == TRUE ) ||
( V_2 -> V_10 == TRUE ) ||
( V_2 -> V_11 == TRUE ) ) {
F_3 ( V_2 , V_12 , V_13 , V_14 ,
L_1 ) ;
F_5 ( V_221 ) ;
F_4 ( & V_2 -> V_8 ) ;
return - V_15 ;
}
V_2 -> V_260 = TRUE ;
while ( V_222 ) {
if ( V_222 > V_259 )
V_224 = V_259 ;
else
V_224 = V_222 ;
V_6 = F_6 ( V_2 , ( V_16 ) V_221 ,
V_225 , V_224 ) ;
if ( V_6 ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_71 ,
V_6 ) ;
break;
}
F_91 ( V_2 , V_12 , V_13 ,
V_14 , V_221 , V_224 ) ;
V_6 = F_7 ( V_226 , V_221 , V_224 ) ;
if ( V_6 ) {
F_3 ( V_2 , V_64 , 0 , 0 ,
L_72 ,
V_6 ) ;
F_4 ( & V_2 -> V_8 ) ;
F_5 ( V_221 ) ;
return - V_21 ;
}
V_222 = V_222 - V_224 ;
if ( V_222 ) {
V_225 = V_225 + V_224 ;
V_226 = V_226 + V_224 ;
}
}
V_2 -> V_260 = false ;
F_4 ( & V_2 -> V_8 ) ;
F_5 ( V_221 ) ;
return V_6 ;
}
static int F_107 ( void T_4 * V_67 ,
struct V_1 * V_2 ,
struct V_30 * V_31 )
{
struct V_70 V_71 ;
INT V_6 = V_7 ;
T_2 V_261 = 0 ;
V_6 = F_25 ( & V_71 , V_67 ,
sizeof( struct V_70 ) ) ;
if ( V_6 ) {
F_3 ( V_2 , V_12 , V_13 , V_14 ,
L_106 ) ;
return - V_21 ;
}
if ( V_71 . V_76 != sizeof( unsigned long ) )
return - V_77 ;
V_6 = F_25 ( & V_261 , V_71 . V_78 ,
V_71 . V_76 ) ;
if ( V_6 ) {
F_3 ( V_2 , V_12 , V_13 , V_14 ,
L_107 ) ;
return - V_21 ;
}
F_3 ( V_2 , V_12 , V_13 , V_14 ,
L_108 ,
V_261 ) ;
V_31 -> V_36 = V_261 ;
return V_6 ;
}
static int F_108 ( void T_4 * V_67 ,
struct V_1 * V_2 )
{
struct V_262 V_263 ;
struct V_70 V_71 ;
F_3 ( V_2 , V_12 , V_13 , V_14 ,
L_109 ) ;
memset ( & V_263 , 0 , sizeof( V_263 ) ) ;
V_263 . V_264 = V_265 ;
V_263 . V_266 = V_267 ;
V_263 . V_268 = 0 ;
V_263 . V_269 = V_2 -> V_194 ;
V_263 . V_270 = V_271 ;
if ( F_25 ( & V_71 , V_67 , sizeof( struct V_70 ) ) )
return - V_21 ;
if ( V_71 . V_79 < sizeof( V_263 ) )
return - V_77 ;
if ( F_7 ( V_71 . V_81 , & V_263 , sizeof( V_263 ) ) )
return - V_21 ;
return V_19 ;
}
static int F_109 ( void T_4 * V_67 ,
struct V_1 * V_2 )
{
struct V_272 V_273 = { 0 } ;
struct V_70 V_71 ;
F_3 ( V_2 , V_12 , V_13 , V_14 ,
L_110 ) ;
if ( F_25 ( & V_71 , V_67 , sizeof( struct V_70 ) ) )
return - V_21 ;
if ( V_71 . V_79 < sizeof( struct V_272 ) )
return - V_77 ;
V_273 . V_274 =
F_110 () - V_2 -> V_275 ;
if ( F_7 ( V_71 . V_81 , & V_273 ,
sizeof( struct V_272 ) ) )
return - V_21 ;
return V_19 ;
}
static long F_111 ( struct V_28 * V_29 , T_8 V_93 , T_2 V_171 )
{
struct V_30 * V_31 = V_29 -> V_40 ;
void T_4 * V_67 = ( void T_4 * ) V_171 ;
struct V_1 * V_2 = V_31 -> V_35 ;
INT V_6 = V_7 ;
F_3 ( V_2 , V_12 , V_13 , V_14 ,
L_111 ,
V_93 , V_171 ) ;
if ( F_112 ( V_93 ) != V_276 )
return - V_21 ;
if ( F_113 ( V_93 ) & V_277 )
V_6 = ! F_114 ( V_278 , V_67 , F_115 ( V_93 ) ) ;
else if ( F_113 ( V_93 ) & V_279 )
V_6 = ! F_114 ( V_280 , V_67 , F_115 ( V_93 ) ) ;
else if ( V_281 == ( F_113 ( V_93 ) & V_281 ) )
V_6 = V_19 ;
if ( V_6 )
return - V_21 ;
if ( V_2 -> V_56 )
return - V_21 ;
if ( false == V_2 -> V_59 ) {
switch ( V_93 ) {
case V_282 :
case V_283 :
case V_284 :
case V_285 :
case V_286 :
case V_287 :
case V_288 :
case V_289 :
return - V_15 ;
default:
break;
}
}
V_6 = F_116 ( V_2 , V_93 , V_171 ) ;
if ( V_6 != V_290 )
return V_6 ;
switch ( V_93 ) {
case V_291 :
V_6 = F_24 ( V_67 , V_2 ) ;
return V_6 ;
case V_292 :
V_6 = F_28 ( V_67 , V_2 ) ;
return V_6 ;
case V_293 :
case V_294 :
V_6 = F_30 ( V_67 , V_2 ) ;
return V_6 ;
case V_94 :
case V_295 :
V_6 = F_32 ( V_67 , V_2 , V_93 ) ;
return V_6 ;
case V_288 :
V_6 = F_34 ( V_67 , V_2 ) ;
return V_6 ;
case V_296 :
V_6 = F_36 ( V_67 ,
V_2 ) ;
return V_6 ;
case V_289 :
V_6 = F_38 ( V_67 , V_2 ) ;
return V_6 ;
case V_297 :
V_6 = F_39 ( V_67 , V_2 ) ;
return V_6 ;
case V_298 :
V_6 = F_40 ( V_67 , V_2 ) ;
return V_6 ;
case V_282 :
case V_283 :
case V_284 :
case V_285 :
case V_286 :
case V_287 :
V_6 = F_41 ( V_67 , V_2 ) ;
return V_6 ;
case V_299 :
V_6 = F_47 ( V_2 ) ;
return V_6 ;
case V_300 :
V_6 = F_54 ( V_67 , V_2 ) ;
return V_6 ;
case V_301 :
V_6 = F_56 ( V_67 , V_2 ) ;
return V_6 ;
case V_302 :
V_6 = 0 ;
if ( F_65 ( V_2 -> V_303 ,
( unsigned long T_4 * ) V_171 ) )
V_6 = - V_21 ;
break;
case V_304 :
V_6 = 0 ;
if ( F_65 ( V_2 -> V_305 ,
( unsigned long T_4 * ) V_171 ) )
V_6 = - V_21 ;
break;
case V_306 :
V_6 = F_61 ( V_2 ) ;
return V_6 ;
case V_307 :
V_6 = F_64 ( V_171 , V_2 ) ;
return V_6 ;
case V_308 :
F_117 ( V_2 ) ;
F_118 ( & V_2 -> V_309 ) ;
V_6 = V_19 ;
break;
case V_310 :
if ( F_7 ( V_67 , & V_2 -> V_174 ,
sizeof( struct V_311 ) * V_173 ) )
return - V_21 ;
V_6 = V_19 ;
break;
case V_312 :
V_6 = F_66 ( V_67 , V_2 ) ;
return V_6 ;
case V_313 :
V_6 = F_67 ( V_67 ) ;
return V_6 ;
case V_314 :
V_6 = F_68 ( V_67 , V_2 ) ;
return V_6 ;
case V_315 :
V_6 = F_69 ( V_67 , V_2 ) ;
return V_6 ;
case V_316 :
V_6 = F_70 ( V_67 , V_2 ) ;
return V_6 ;
case V_317 :
V_6 = F_72 ( V_67 , V_2 , V_31 ) ;
return V_6 ;
case V_318 :
if ( ( false == V_2 -> V_319 ) &&
( TRUE == V_2 -> V_9 ) ) {
V_2 -> V_320 = V_321 ;
V_2 -> V_322 = TRUE ;
F_37 ( & V_2 -> V_323 ) ;
}
V_6 = V_19 ;
break;
case V_324 :
V_6 = F_75 ( V_67 , V_2 , V_93 ) ;
return V_6 ;
case V_325 :
V_6 = F_77 ( V_67 , V_2 ) ;
return V_6 ;
case V_326 :
V_6 = F_78 ( V_67 , V_2 ) ;
return V_6 ;
case V_327 :
V_6 = F_81 ( V_67 , V_2 ) ;
return V_6 ;
case V_214 :
case V_328 :
V_6 = F_84 ( V_67 , V_2 , V_93 ) ;
return V_6 ;
case V_329 :
V_6 = F_88 ( V_67 , V_2 ) ;
return V_6 ;
case V_330 :
V_6 = F_92 ( V_67 , V_2 ) ;
return V_6 ;
case V_331 :
V_6 = F_94 ( V_67 , V_2 ) ;
return V_6 ;
case V_332 :
V_6 = F_96 ( V_67 , V_2 ) ;
return V_6 ;
case V_333 :
V_2 -> V_235 = false ;
F_3 ( V_2 , V_12 , V_13 , V_14 ,
L_112 ) ;
V_6 = V_19 ;
break;
case V_334 :
V_6 = F_98 ( V_67 , V_2 ) ;
return V_6 ;
case V_335 :
V_6 = F_103 ( V_67 , V_2 ) ;
return V_6 ;
case V_336 :
V_6 = F_104 ( V_67 , V_2 ) ;
return V_6 ;
case V_337 :
V_6 = F_106 ( V_67 , V_2 ) ;
return V_6 ;
case V_338 :
V_6 = F_107 ( V_67 , V_2 , V_31 ) ;
return V_6 ;
case V_339 :
V_6 = F_108 ( V_67 , V_2 ) ;
return V_6 ;
case V_340 :
V_6 = F_109 ( V_67 , V_2 ) ;
return V_6 ;
case V_341 :
F_3 ( V_2 , V_12 , V_13 , V_14 ,
L_113 ) ;
break;
default:
F_119 ( V_342 L_114 , V_93 ) ;
V_6 = V_7 ;
break;
}
return V_6 ;
}
int F_120 ( struct V_1 * V_2 )
{
if ( V_2 -> V_343 > 0 )
return V_2 -> V_343 ;
V_2 -> V_343 = F_121 ( 0 , V_344 , & V_345 ) ;
if ( V_2 -> V_343 < 0 ) {
F_52 ( V_342 L_115 ) ;
return V_2 -> V_343 ;
}
V_2 -> V_346 = F_122 ( V_347 , NULL ,
F_123 ( V_2 -> V_343 , 0 ) ,
V_2 , V_344 ) ;
if ( F_43 ( V_2 -> V_346 ) ) {
F_52 ( V_342 L_116 ) ;
F_124 ( V_2 -> V_343 , V_344 ) ;
return F_44 ( V_2 -> V_346 ) ;
}
return 0 ;
}
void F_125 ( struct V_1 * V_2 )
{
if ( V_2 -> V_343 > 0 ) {
F_126 ( V_347 , F_123 ( V_2 -> V_343 , 0 ) ) ;
F_124 ( V_2 -> V_343 , V_344 ) ;
}
}
