static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = NULL ;
struct V_6 * V_7 = NULL ;
V_5 = F_2 ( V_8 ) ;
V_7 = F_3 ( sizeof( struct V_6 ) , V_9 ) ;
if ( ! V_7 )
return - V_10 ;
V_7 -> V_5 = V_5 ;
V_7 -> V_11 = 0xFFFFFFFF & ~ ( 1 << 0xB ) ;
F_4 ( & V_5 -> V_12 ) ;
V_7 -> V_13 = V_5 -> V_14 ;
V_5 -> V_14 = V_7 ;
F_5 ( & V_5 -> V_12 ) ;
V_3 -> V_15 = V_7 ;
F_6 ( & V_5 -> V_16 ) ;
F_7 ( V_1 , V_3 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_6 * V_7 , * V_17 , * V_18 ;
struct V_4 * V_5 = NULL ;
struct V_19 * V_20 , * V_21 ;
V_7 = (struct V_6 * ) V_3 -> V_15 ;
if ( V_7 == NULL )
return 0 ;
V_5 = V_7 -> V_5 ;
F_4 ( & V_5 -> V_12 ) ;
V_17 = V_5 -> V_14 ;
for ( V_18 = NULL ; V_17 ; V_18 = V_17 , V_17 = V_17 -> V_13 ) {
if ( V_17 == V_7 )
break;
}
if ( V_17 ) {
if ( ! V_18 )
V_5 -> V_14 = V_17 -> V_13 ;
else
V_18 -> V_13 = V_17 -> V_13 ;
} else {
F_5 ( & V_5 -> V_12 ) ;
return 0 ;
}
V_20 = V_7 -> V_22 ;
while ( V_20 ) {
V_21 = V_20 -> V_13 ;
F_9 ( V_20 ) ;
V_20 = V_21 ;
}
F_5 ( & V_5 -> V_12 ) ;
F_10 ( & V_5 -> V_16 ) ;
F_11 ( V_7 ) ;
V_3 -> V_15 = NULL ;
return 0 ;
}
static T_1 F_12 ( struct V_2 * V_3 , char T_2 * V_23 , T_3 V_24 ,
T_4 * V_25 )
{
struct V_6 * V_7 = V_3 -> V_15 ;
struct V_4 * V_5 = V_7 -> V_5 ;
struct V_19 * V_26 = NULL ;
T_1 V_27 = 0 ;
int V_28 = 0 ;
unsigned long V_29 = 0 ;
V_28 = F_13 ( V_5 -> V_30 ,
( V_7 -> V_22 ||
V_5 -> V_31 ) ) ;
if ( ( V_28 == - V_32 ) ) {
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_1 ) ;
return V_28 ;
}
if ( V_5 -> V_31 ) {
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_2 ) ;
return - V_36 ;
}
if ( false == V_5 -> V_37 )
return - V_38 ;
F_4 ( & V_5 -> V_12 ) ;
if ( V_7 -> V_22 ) {
V_26 = V_7 -> V_22 ;
F_15 ( V_7 -> V_22 ,
V_7 -> V_39 ) ;
V_7 -> V_40 -- ;
}
F_5 ( & V_5 -> V_12 ) ;
if ( V_26 ) {
V_27 = V_26 -> V_41 ;
V_29 = F_16 ( V_23 , V_26 -> V_42 ,
F_17 ( T_3 , V_27 , V_24 ) ) ;
if ( V_29 ) {
F_18 ( V_26 ) ;
F_14 ( V_5 , V_43 , 0 , 0 ,
L_3 ) ;
return - V_44 ;
}
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_4 ,
V_27 , V_26 , V_45 -> V_46 ) ;
F_18 ( V_26 ) ;
}
F_14 ( V_5 , V_33 , V_34 , V_35 , L_5 ) ;
return V_27 ;
}
static int F_19 ( void T_2 * V_47 ,
struct V_4 * V_5 )
{
struct V_48 V_49 = { 0 } ;
struct V_50 V_51 ;
T_5 V_52 ;
INT V_53 = V_54 ;
T_6 V_55 ;
T_7 V_56 ;
int V_57 ;
if ( F_20 ( & V_51 , V_47 , sizeof( struct V_50 ) ) )
return - V_44 ;
if ( V_51 . V_58 > sizeof( V_49 ) )
return - V_59 ;
if ( F_20 ( & V_49 , V_51 . V_60 ,
V_51 . V_58 ) )
return - V_44 ;
if ( V_51 . V_61 > V_62 ||
V_51 . V_61 == 0 ) {
return - V_59 ;
}
V_55 = V_51 . V_61 ;
V_56 = 4 - ( V_55 % 4 ) ;
V_55 += V_56 % 4 ;
V_52 = F_21 ( V_55 , V_9 ) ;
if ( ! V_52 )
return - V_10 ;
V_57 = F_22 ( V_5 , ( T_6 ) V_49 . Register ,
( V_63 ) V_52 , V_55 ) ;
if ( V_57 > 0 ) {
V_53 = V_64 ;
if ( F_16 ( V_51 . V_65 , V_52 , V_57 ) ) {
F_11 ( V_52 ) ;
return - V_44 ;
}
} else {
V_53 = V_57 ;
}
F_11 ( V_52 ) ;
return V_53 ;
}
static int F_23 ( void T_2 * V_47 ,
struct V_4 * V_5 )
{
struct V_66 V_67 = { 0 } ;
struct V_50 V_51 ;
T_6 V_68 = 0 ;
INT V_53 ;
if ( F_20 ( & V_51 , V_47 , sizeof( struct V_50 ) ) )
return - V_44 ;
if ( V_51 . V_58 > sizeof( V_67 ) )
return - V_59 ;
if ( F_20 ( & V_67 , V_51 . V_60 ,
V_51 . V_58 ) )
return - V_44 ;
V_68 = V_67 . Register & V_69 ;
if ( ! ( ( V_5 -> V_70 -> V_71 ) & V_72 ) &&
( ( V_68 == V_73 ) ||
( V_68 == V_74 ) ||
( V_68 == V_75 ) ||
( V_68 == V_76 ) ) ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_6 ) ;
return - V_44 ;
}
V_53 = F_24 ( V_5 , ( T_6 ) V_67 . Register ,
( V_63 ) V_67 . V_77 , sizeof( V_78 ) ) ;
if ( V_53 == V_64 ) {
F_14 ( V_5 , V_33 , V_34 ,
V_35 , L_7 ) ;
} else {
F_14 ( V_5 , V_33 , V_34 ,
V_35 , L_8 ) ;
V_53 = - V_44 ;
}
return V_53 ;
}
static int F_25 ( void T_2 * V_47 ,
struct V_4 * V_5 )
{
struct V_48 V_49 = { 0 } ;
struct V_50 V_51 ;
T_5 V_52 = NULL ;
T_6 V_68 = 0 ;
INT V_53 ;
int V_57 ;
if ( ( V_5 -> V_79 == TRUE ) ||
( V_5 -> V_80 == TRUE ) ||
( V_5 -> V_81 == TRUE ) ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_9 ) ;
return - V_38 ;
}
if ( F_20 ( & V_51 , V_47 , sizeof( struct V_50 ) ) )
return - V_44 ;
if ( V_51 . V_58 > sizeof( V_49 ) )
return - V_59 ;
if ( F_20 ( & V_49 , V_51 . V_60 ,
V_51 . V_58 ) )
return - V_44 ;
if ( V_51 . V_61 > V_62 ||
V_51 . V_61 == 0 ) {
return - V_59 ;
}
V_52 = F_21 ( V_51 . V_61 , V_9 ) ;
if ( ! V_52 )
return V_54 ;
if ( ( ( ( V_78 ) V_49 . Register & 0x0F000000 ) != 0x0F000000 ) ||
( ( V_78 ) V_49 . Register & 0x3 ) ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_10 ,
( int ) V_49 . Register ) ;
F_11 ( V_52 ) ;
return - V_59 ;
}
V_68 = V_49 . Register & V_69 ;
V_57 = F_26 ( V_5 , ( T_6 ) V_49 . Register ,
( V_63 ) V_52 , V_51 . V_61 ) ;
if ( V_57 > 0 ) {
V_53 = V_64 ;
if ( F_16 ( V_51 . V_65 , V_52 , V_57 ) ) {
F_11 ( V_52 ) ;
return - V_44 ;
}
} else {
V_53 = V_57 ;
}
F_11 ( V_52 ) ;
return V_53 ;
}
static int F_27 ( void T_2 * V_47 ,
struct V_4 * V_5 , T_6 V_82 )
{
struct V_66 V_67 = { 0 } ;
struct V_50 V_51 ;
T_6 V_68 = 0 ;
INT V_53 ;
if ( ( V_5 -> V_79 == TRUE ) ||
( V_5 -> V_80 == TRUE ) ||
( V_5 -> V_81 == TRUE ) ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_11 ) ;
return - V_38 ;
}
if ( F_20 ( & V_51 , V_47 , sizeof( struct V_50 ) ) )
return - V_44 ;
if ( V_51 . V_58 > sizeof( V_67 ) )
return - V_59 ;
if ( F_20 ( & V_67 , V_51 . V_60 ,
V_51 . V_58 ) )
return - V_44 ;
if ( ( ( ( V_78 ) V_67 . Register & 0x0F000000 ) != 0x0F000000 ) ||
( ( V_78 ) V_67 . Register & 0x3 ) ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_12 ,
( int ) V_67 . Register ) ;
return - V_59 ;
}
V_68 = V_67 . Register & V_69 ;
if ( ! ( ( V_5 -> V_70 -> V_71 ) & V_72 ) &&
( ( V_68 == V_73 ) ||
( V_68 == V_74 ) ||
( V_68 == V_75 ) ||
( V_68 == V_76 ) ) &&
( V_82 == V_83 ) ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_6 ) ;
return - V_44 ;
}
V_53 = F_28 ( V_5 , ( T_6 ) V_67 . Register ,
( V_63 ) V_67 . V_77 ,
V_67 . V_84 ) ;
if ( V_53 == V_64 ) {
F_14 ( V_5 , V_43 , V_34 ,
V_35 , L_7 ) ;
} else {
F_14 ( V_5 , V_33 , V_34 ,
V_35 , L_8 ) ;
V_53 = - V_44 ;
}
return V_53 ;
}
static int F_29 ( void T_2 * V_47 ,
struct V_4 * V_5 )
{
struct V_85 V_86 = { 0 } ;
struct V_50 V_51 ;
T_8 V_87 [ 4 ] ;
T_6 V_88 = 0 ;
T_6 V_89 = 0 ;
T_6 V_90 = 0 ;
INT V_53 ;
int V_57 ;
if ( ( V_5 -> V_79 == TRUE ) ||
( V_5 -> V_80 == TRUE ) ||
( V_5 -> V_81 == TRUE ) ) {
F_14 ( V_5 , V_33 , V_34 ,
V_35 ,
L_13 ) ;
return - V_38 ;
}
if ( F_20 ( & V_51 , V_47 , sizeof( struct V_50 ) ) )
return - V_44 ;
if ( V_51 . V_58 > sizeof( V_86 ) )
return - V_59 ;
if ( F_20 ( & V_86 , V_51 . V_60 , V_51 . V_58 ) )
return - V_44 ;
V_89 = V_86 . V_91 ;
V_90 = V_86 . V_92 ;
V_88 = ( 1 << V_89 ) ;
if ( F_30 ( V_5 , V_88 ) == false ) {
F_14 ( V_5 , V_33 , V_34 ,
V_35 ,
L_14 ,
V_88 ) ;
return - V_59 ;
}
if ( V_90 ) {
V_53 = F_28 ( V_5 ,
V_93 ,
( V_63 ) ( & V_88 ) , sizeof( T_6 ) ) ;
if ( V_53 == V_64 ) {
F_14 ( V_5 , V_33 ,
V_34 , V_35 ,
L_15 ) ;
} else {
F_14 ( V_5 , V_33 ,
V_34 , V_35 ,
L_16 ,
V_89 ) ;
return V_53 ;
}
} else {
V_53 = F_28 ( V_5 ,
V_94 ,
( V_63 ) ( & V_88 ) , sizeof( T_6 ) ) ;
if ( V_53 == V_64 ) {
F_14 ( V_5 , V_33 ,
V_34 , V_35 ,
L_15 ) ;
} else {
F_14 ( V_5 , V_33 ,
V_34 , V_35 ,
L_17 ,
V_89 ) ;
return V_53 ;
}
}
V_57 = F_26 ( V_5 , ( T_6 ) V_95 ,
( V_63 ) V_87 , sizeof( T_6 ) ) ;
if ( V_57 < 0 ) {
V_53 = V_57 ;
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_18 ) ;
return V_53 ;
} else {
V_53 = V_64 ;
}
* ( T_6 * ) V_87 |= ( 1 << V_89 ) ;
V_53 = F_28 ( V_5 , V_95 ,
( V_63 ) V_87 , sizeof( T_6 ) ) ;
if ( V_53 == V_64 ) {
F_14 ( V_5 , V_33 , V_34 ,
V_35 ,
L_19 ) ;
} else {
F_14 ( V_5 , V_33 , V_34 ,
V_35 ,
L_20 ) ;
}
return V_53 ;
}
static int F_31 ( void T_2 * V_47 ,
struct V_4 * V_5 )
{
struct V_96 V_97 = { 0 } ;
struct V_50 V_51 ;
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_21 ) ;
if ( ( V_5 -> V_79 == TRUE ) ||
( V_5 -> V_80 == TRUE ) ||
( V_5 -> V_81 == TRUE ) ) {
F_14 ( V_5 , V_33 , V_34 ,
V_35 ,
L_13 ) ;
return - V_38 ;
}
if ( F_20 ( & V_51 , V_47 , sizeof( struct V_50 ) ) )
return - V_44 ;
if ( V_51 . V_58 > sizeof( V_97 ) )
return - V_59 ;
if ( F_20 ( & V_97 , V_51 . V_60 , V_51 . V_58 ) )
return - V_44 ;
if ( V_5 -> V_98 . V_99 ) {
if ( V_97 . V_100 == V_101 ) {
F_14 ( V_5 , V_33 ,
V_34 , V_35 ,
L_22 ) ;
V_5 -> V_102 = V_103 ;
} else {
F_14 ( V_5 , V_33 ,
V_34 , V_35 ,
L_23 ) ;
V_5 -> V_102 = V_104 ;
}
F_32 ( & V_5 -> V_98 . V_105 ) ;
}
return V_64 ;
}
static int F_33 ( void T_2 * V_47 ,
struct V_4 * V_5 )
{
struct V_85 V_86 = { 0 } ;
struct V_50 V_51 ;
V_78 V_89 = 0 ;
T_8 V_106 [ 4 ] ;
INT V_53 ;
int V_57 ;
if ( ( V_5 -> V_79 == TRUE ) ||
( V_5 -> V_80 == TRUE ) ||
( V_5 -> V_81 == TRUE ) )
return - V_38 ;
if ( F_20 ( & V_51 , V_47 , sizeof( struct V_50 ) ) )
return - V_44 ;
if ( V_51 . V_58 > sizeof( V_86 ) )
return - V_59 ;
if ( F_20 ( & V_86 , V_51 . V_60 ,
V_51 . V_58 ) )
return - V_44 ;
V_89 = V_86 . V_91 ;
V_57 = F_26 ( V_5 , ( T_6 ) V_107 ,
( V_63 ) V_106 , sizeof( T_6 ) ) ;
if ( V_57 < 0 ) {
V_53 = V_57 ;
F_14 ( V_5 , V_43 , 0 , 0 ,
L_24 ) ;
return V_53 ;
} else {
V_53 = V_64 ;
}
return V_53 ;
}
static int F_34 ( void T_2 * V_47 ,
struct V_4 * V_5 )
{
struct V_108 V_109 [ V_110 ] ;
struct V_108 * V_111 =
(struct V_108 * ) V_109 ;
struct V_50 V_51 ;
T_8 V_87 [ 4 ] ;
INT V_53 = V_54 ;
int V_57 ;
memset ( V_111 , 0 , V_110 * sizeof( struct V_108 ) ) ;
if ( ( V_5 -> V_79 == TRUE ) ||
( V_5 -> V_80 == TRUE ) ||
( V_5 -> V_81 == TRUE ) )
return - V_59 ;
if ( F_20 ( & V_51 , V_47 , sizeof( struct V_50 ) ) )
return - V_44 ;
if ( V_51 . V_58 > sizeof( V_109 ) )
return - V_59 ;
if ( V_51 . V_61 > sizeof( V_109 ) )
V_51 . V_61 = sizeof( V_109 ) ;
if ( F_20 ( & V_109 , V_51 . V_60 ,
V_51 . V_58 ) )
return - V_44 ;
if ( F_30 ( V_5 ,
V_111 [ V_112 ] . V_113 ) == false ) {
F_14 ( V_5 , V_33 , V_34 ,
V_35 ,
L_25 ,
V_111 [ V_112 ] . V_113 ,
V_5 -> V_114 ) ;
return - V_59 ;
}
if ( ( V_111 [ V_112 ] . V_113 ) &
( V_111 [ V_112 ] . V_115 ) ) {
* ( T_6 * ) V_87 = V_111 [ V_112 ] . V_113 &
V_111 [ V_112 ] . V_115 &
V_111 [ V_112 ] . V_116 ;
if ( * ( T_6 * ) V_87 )
V_53 = F_28 ( V_5 ,
V_93 ,
( V_63 ) V_87 , sizeof( V_78 ) ) ;
if ( V_53 != V_64 ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_26 ) ;
return V_53 ;
}
* ( T_6 * ) V_87 = ( V_111 [ V_112 ] . V_113 &
V_111 [ V_112 ] . V_115 &
( ~ ( V_111 [ V_112 ] . V_116 ) ) ) ;
if ( * ( T_6 * ) V_87 )
V_53 = F_28 ( V_5 ,
V_94 , ( V_63 ) V_87 ,
sizeof( V_78 ) ) ;
if ( V_53 != V_64 ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_27 ) ;
return V_53 ;
}
}
if ( V_111 [ V_112 ] . V_113 ) {
V_57 = F_26 ( V_5 , ( T_6 ) V_107 ,
( V_63 ) V_87 , sizeof( T_6 ) ) ;
if ( V_57 < 0 ) {
V_53 = V_57 ;
F_14 ( V_5 , V_43 , 0 , 0 ,
L_28 ) ;
return V_53 ;
} else {
V_53 = V_64 ;
}
V_111 [ V_112 ] . V_116 = ( * ( T_6 * ) V_87 &
V_111 [ V_112 ] . V_113 ) ;
}
V_53 = F_16 ( V_51 . V_65 , & V_109 ,
V_51 . V_61 ) ;
if ( V_53 ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_29 ,
V_53 ) ;
return - V_44 ;
}
return V_53 ;
}
static int F_35 ( void T_2 * V_47 ,
struct V_4 * V_5 )
{
struct V_117 V_118 [ V_110 ] ;
struct V_117 * V_119 =
(struct V_117 * ) V_118 ;
struct V_50 V_51 ;
T_8 V_87 [ 4 ] ;
INT V_53 ;
int V_57 ;
if ( ( V_5 -> V_79 == TRUE ) ||
( V_5 -> V_80 == TRUE ) ||
( V_5 -> V_81 == TRUE ) )
return - V_59 ;
if ( F_20 ( & V_51 , V_47 , sizeof( struct V_50 ) ) )
return - V_44 ;
if ( V_51 . V_58 > sizeof( V_118 ) )
return - V_59 ;
if ( V_51 . V_61 > sizeof( V_118 ) )
V_51 . V_61 = sizeof( V_118 ) ;
if ( F_20 ( & V_118 , V_51 . V_60 ,
V_51 . V_58 ) )
return - V_44 ;
V_57 = F_26 ( V_5 , ( T_6 ) V_95 ,
( V_63 ) V_87 , sizeof( T_6 ) ) ;
if ( V_57 < 0 ) {
V_53 = V_57 ;
F_14 ( V_5 , V_43 , 0 , 0 ,
L_30 ) ;
return V_53 ;
} else {
V_53 = V_64 ;
}
if ( F_30 ( V_5 ,
V_119 [ V_112 ] . V_113 ) == false ) {
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_25 ,
V_119 [ V_112 ] . V_113 ,
V_5 -> V_114 ) ;
return - V_59 ;
}
if ( V_119 [ V_112 ] . V_113 ) {
* ( T_6 * ) V_87 |= ( V_119 [ V_112 ] . V_120 &
V_119 [ V_112 ] . V_113 ) ;
* ( T_6 * ) V_87 &= ~ ( ( ~ V_119 [ V_112 ] . V_120 ) &
V_119 [ V_112 ] . V_113 ) ;
V_119 [ V_112 ] . V_120 = * ( T_6 * ) V_87 ;
V_53 = F_28 ( V_5 , V_95 ,
( V_63 ) V_87 , sizeof( V_78 ) ) ;
if ( V_53 == V_64 ) {
F_14 ( V_5 ,
V_33 , V_34 , V_35 ,
L_31 ) ;
} else {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_32 ) ;
return - V_44 ;
}
} else {
V_119 [ V_112 ] . V_120 = * ( T_6 * ) V_87 ;
}
V_53 = F_16 ( V_51 . V_65 , & V_118 ,
V_51 . V_61 ) ;
if ( V_53 ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_29 ,
V_53 ) ;
return - V_44 ;
}
return V_53 ;
}
static int F_36 ( void T_2 * V_47 ,
struct V_4 * V_5 )
{
struct V_50 V_51 ;
T_9 V_121 = NULL ;
INT V_53 ;
if ( F_20 ( & V_51 , V_47 , sizeof( struct V_50 ) ) )
return - V_44 ;
if ( V_51 . V_58 < sizeof( struct V_122 ) )
return - V_59 ;
if ( V_51 . V_58 > V_123 )
return - V_59 ;
V_121 = F_37 ( V_51 . V_60 ,
V_51 . V_58 ) ;
if ( F_38 ( V_121 ) )
return F_39 ( V_121 ) ;
F_4 ( & V_5 -> V_124 ) ;
V_53 = F_40 ( V_5 -> V_125 ,
! V_5 -> V_81 ,
( 1 * V_126 ) ) ;
if ( V_53 == - V_32 )
goto V_127;
if ( V_5 -> V_81 ) {
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_33 ) ;
V_53 = V_54 ;
goto V_127;
}
V_53 = F_41 ( V_5 , ( T_9 ) V_121 ) ;
V_127:
F_5 ( & V_5 -> V_124 ) ;
F_11 ( V_121 ) ;
return V_53 ;
}
static int F_42 (
struct V_4 * V_5 )
{
INT V_53 ;
if ( F_43 ( & V_5 -> V_128 ) ) {
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_34 ) ;
return - V_38 ;
}
F_14 ( V_5 , V_43 , 0 , 0 ,
L_35 , V_45 -> V_46 ) ;
if ( F_43 ( & V_5 -> V_129 ) )
return - V_130 ;
V_5 -> V_131 = false ;
V_5 -> V_132 = V_45 -> V_46 ;
V_5 -> V_133 = false ;
V_5 -> V_37 = false ;
F_44 ( V_5 -> V_134 ) ;
F_45 ( V_5 -> V_134 ) ;
V_53 = F_46 ( V_5 ) ;
if ( V_53 ) {
F_47 ( V_135 L_36 , V_5 -> V_134 -> V_136 ) ;
F_5 ( & V_5 -> V_129 ) ;
F_5 ( & V_5 -> V_128 ) ;
return V_53 ;
}
F_48 ( 10 ) ;
F_5 ( & V_5 -> V_128 ) ;
return V_53 ;
}
static int F_49 ( void T_2 * V_47 ,
struct V_4 * V_5 )
{
struct V_137 * V_138 = NULL ;
struct V_50 V_51 ;
INT V_53 ;
F_14 ( V_5 , V_43 , 0 , 0 ,
L_35 , V_45 -> V_46 ) ;
if ( ! F_43 ( & V_5 -> V_129 ) ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_37 ) ;
F_5 ( & V_5 -> V_129 ) ;
return - V_59 ;
}
if ( F_20 ( & V_51 , V_47 , sizeof( struct V_50 ) ) ) {
F_5 ( & V_5 -> V_129 ) ;
return - V_44 ;
}
F_14 ( V_5 , V_43 , 0 , 0 ,
L_38 , V_51 . V_58 ) ;
if ( V_51 . V_58 > sizeof( struct V_137 ) ) {
F_5 ( & V_5 -> V_129 ) ;
return - V_59 ;
}
V_138 = F_21 ( sizeof( * V_138 ) , V_9 ) ;
if ( ! V_138 ) {
F_5 ( & V_5 -> V_129 ) ;
return - V_10 ;
}
if ( F_20 ( V_138 , V_51 . V_60 ,
V_51 . V_58 ) ) {
F_5 ( & V_5 -> V_129 ) ;
F_11 ( V_138 ) ;
return - V_44 ;
}
if ( ! V_138 -> V_139 ||
( V_138 -> V_140 == 0 ) ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_39 ,
V_138 -> V_140 ) ;
F_5 ( & V_5 -> V_129 ) ;
F_11 ( V_138 ) ;
V_53 = - V_59 ;
return V_53 ;
}
V_53 = F_50 ( V_5 , V_138 ) ;
if ( V_53 != V_64 ) {
if ( V_138 -> V_141 == V_142 )
F_14 ( V_5 , V_43 , 0 , 0 ,
L_40 ) ;
else
F_14 ( V_5 , V_43 , 0 , 0 ,
L_41 ) ;
if ( V_5 -> V_98 . V_99 &
V_143 ) {
V_5 -> V_102 = V_144 ;
V_5 -> V_98 . V_145 = false ;
F_32 ( & V_5 -> V_98 . V_105 ) ;
}
}
if ( V_53 != V_64 )
F_5 ( & V_5 -> V_129 ) ;
F_14 ( V_5 , V_43 , V_34 , V_35 ,
L_42 ) ;
F_11 ( V_138 ) ;
return V_53 ;
}
static int F_51 ( void T_2 * V_47 ,
struct V_4 * V_5 )
{
INT V_53 ;
int V_146 = 0 ;
if ( ! F_43 ( & V_5 -> V_129 ) ) {
F_5 ( & V_5 -> V_129 ) ;
return - V_59 ;
}
if ( F_43 ( & V_5 -> V_128 ) ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_43 ) ;
F_5 ( & V_5 -> V_129 ) ;
return - V_38 ;
}
V_5 -> V_131 = TRUE ;
V_5 -> V_133 = TRUE ;
F_52 ( & V_5 -> V_147 , 0 ) ;
V_5 -> V_148 = 0 ;
V_5 -> V_149 = 0 ;
V_53 = F_53 ( V_5 ) ;
if ( V_53 ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_44 ) ;
F_5 ( & V_5 -> V_129 ) ;
F_5 ( & V_5 -> V_128 ) ;
return V_53 ;
} else {
F_14 ( V_5 , V_33 , V_34 ,
V_35 , L_45 ) ;
}
F_48 ( 10 ) ;
if ( F_54 ( (struct V_150 * ) V_5 -> V_151 ) )
F_14 ( V_5 , V_43 , 0 , 0 ,
L_46 ) ;
V_146 = 5 * V_126 ;
V_5 -> V_152 = false ;
F_55 ( V_5 -> V_153 ,
V_5 -> V_152 , V_146 ) ;
V_5 -> V_132 = V_154 ;
V_5 -> V_37 = TRUE ;
F_52 ( & V_5 -> V_147 , 0 ) ;
V_5 -> V_148 = 0 ;
V_5 -> V_155 = 0 ;
F_52 ( & V_5 -> V_156 , 0 ) ;
V_5 -> V_157 = 0 ;
V_5 -> V_158 = 0 ;
if ( V_5 -> V_98 . V_99 &
V_143 ) {
V_5 -> V_102 = V_159 ;
F_32 ( & V_5 -> V_98 . V_105 ) ;
}
if ( ! V_146 )
V_53 = - V_36 ;
F_5 ( & V_5 -> V_129 ) ;
F_5 ( & V_5 -> V_128 ) ;
return V_53 ;
}
static int F_56 ( struct V_4 * V_5 )
{
INT V_53 ;
INT V_160 ;
V_160 = F_43 ( & V_5 -> V_128 ) ;
if ( V_160 ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_47 ) ;
return - V_38 ;
}
F_4 ( & V_5 -> V_12 ) ;
V_53 = F_46 ( V_5 ) ;
F_57 () ;
F_5 ( & V_5 -> V_12 ) ;
F_5 ( & V_5 -> V_128 ) ;
F_58 ( V_5 ) ;
return V_53 ;
}
static int F_59 ( V_78 V_161 ,
struct V_4 * V_5 )
{
T_10 V_162 ;
for ( V_162 = 0 ; V_162 < V_163 ; V_162 ++ ) {
if ( F_60 ( V_5 -> V_164 [ V_162 ] . V_165 ,
( unsigned long T_2 * ) V_161 ) ) {
return - V_44 ;
}
}
return 0 ;
}
static int F_61 ( void T_2 * V_47 ,
struct V_4 * V_5 )
{
T_6 V_166 = 0 ;
if ( F_20 ( & V_166 , V_47 , sizeof( T_6 ) ) )
return - V_44 ;
if ( V_166 ) {
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_48 ) ;
V_5 -> V_167 = V_168 ;
} else {
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_49 ) ;
V_5 -> V_167 = V_169 ;
}
return V_64 ;
}
static int F_62 ( void T_2 * V_47 )
{
struct V_50 V_51 ;
T_11 V_41 ;
if ( F_20 ( & V_51 , V_47 , sizeof( struct V_50 ) ) )
return - V_44 ;
V_41 = F_17 ( T_11 , V_51 . V_61 , strlen ( V_170 ) + 1 ) ;
if ( F_16 ( V_51 . V_65 , V_170 , V_41 ) )
return - V_44 ;
return V_64 ;
}
static int F_63 ( void T_2 * V_47 ,
struct V_4 * V_5 )
{
struct V_171 V_172 ;
struct V_50 V_51 ;
if ( F_20 ( & V_51 , V_47 , sizeof( struct V_50 ) ) ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_50 ) ;
return - V_44 ;
}
if ( V_51 . V_61 != sizeof( V_172 ) )
return - V_59 ;
memset ( & V_172 , 0 , sizeof( V_172 ) ) ;
V_172 . V_173 = V_5 -> V_79 ;
V_172 . V_174 = V_5 -> V_80 ;
V_172 . V_175 = V_5 -> V_158 ;
if ( F_16 ( V_51 . V_65 , & V_172 , F_17 ( T_3 ,
sizeof( V_172 ) , V_51 . V_61 ) ) ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_51 ) ;
return - V_44 ;
}
return V_64 ;
}
static int F_64 ( void T_2 * V_47 ,
struct V_4 * V_5 )
{
struct V_50 V_51 ;
T_6 V_176 ;
if ( F_20 ( & V_51 , V_47 , sizeof( struct V_50 ) ) )
return - V_44 ;
if ( F_20 ( & V_176 , V_51 . V_60 , sizeof( T_6 ) ) )
return - V_44 ;
if ( V_176 )
V_5 -> V_14 -> V_177 = TRUE ;
else
V_5 -> V_14 -> V_177 = false ;
return V_64 ;
}
static int F_65 ( void T_2 * V_47 ,
struct V_4 * V_5 )
{
struct V_50 V_51 ;
V_78 V_178 = 0 ;
if ( F_20 ( & V_51 , V_47 , sizeof( struct V_50 ) ) )
return - V_44 ;
if ( V_51 . V_61 < sizeof( struct V_179 ) ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_52 ,
V_51 . V_61 ,
sizeof( struct V_179 ) ) ;
return - V_59 ;
}
if ( F_20 ( & V_178 , V_51 . V_60 , sizeof( V_178 ) ) )
return - V_44 ;
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_53 , V_178 ) ;
F_66 ( V_5 , V_178 , V_51 . V_65 ) ;
return V_64 ;
}
static int F_67 ( void T_2 * V_47 ,
struct V_4 * V_5 , struct V_6 * V_7 )
{
struct V_50 V_51 ;
INT V_53 = V_54 ;
T_9 V_52 ;
if ( F_20 ( & V_51 , V_47 , sizeof( struct V_50 ) ) )
return - V_44 ;
if ( V_51 . V_61 != sizeof( struct V_180 ) ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_54 , V_51 . V_61 ,
sizeof( struct V_180 ) ) ;
return - V_59 ;
}
V_52 = F_3 ( sizeof( struct V_180 ) , V_9 ) ;
if ( ! V_52 )
return V_54 ;
V_53 = F_68 ( V_5 , V_52 ) ;
F_69 ( V_52 , V_7 ) ;
if ( V_53 != V_54 ) {
if ( F_16 ( V_51 . V_65 , V_52 ,
sizeof( struct V_180 ) ) ) {
F_11 ( V_52 ) ;
return - V_44 ;
}
}
F_11 ( V_52 ) ;
return V_53 ;
}
static int F_70 ( void T_2 * V_47 ,
struct V_4 * V_5 , T_6 V_82 )
{
struct V_181 * V_182 ;
struct V_50 V_51 ;
T_6 V_68 = 0 ;
INT V_53 = V_54 ;
T_5 V_121 = NULL ;
if ( ( V_5 -> V_79 == TRUE ) ||
( V_5 -> V_80 == TRUE ) ||
( V_5 -> V_81 == TRUE ) ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_55 ) ;
return - V_38 ;
}
if ( F_20 ( & V_51 , V_47 , sizeof( struct V_50 ) ) )
return - V_44 ;
if ( V_51 . V_58 < sizeof( V_78 ) * 2 )
return - V_59 ;
V_121 = F_37 ( V_51 . V_60 ,
V_51 . V_58 ) ;
if ( F_38 ( V_121 ) )
return F_39 ( V_121 ) ;
V_182 = (struct V_181 * ) V_121 ;
if ( ( ( V_78 ) V_182 -> Register & 0x0F000000 ) != 0x0F000000 ||
( ( V_78 ) V_182 -> Register & 0x3 ) ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_12 ,
( int ) V_182 -> Register ) ;
F_11 ( V_121 ) ;
return - V_59 ;
}
V_68 = V_182 -> Register & V_69 ;
if ( ! ( ( V_5 -> V_70 -> V_71 ) & V_72 ) &&
( ( V_68 == V_73 ) ||
( V_68 == V_74 ) ||
( V_68 == V_75 ) ||
( V_68 == V_76 ) ) &&
( V_82 == V_83 ) ) {
F_11 ( V_121 ) ;
F_14 ( V_5 , V_43 , 0 , 0 ,
L_6 ) ;
return - V_44 ;
}
if ( V_182 -> V_183 == false )
V_53 = F_71 ( V_5 , ( T_6 ) V_182 -> Register ,
( T_5 ) V_182 -> V_184 ,
V_51 . V_58 - 2 * sizeof( V_78 ) ) ;
else
V_53 = F_28 ( V_5 , ( T_6 ) V_182 -> Register ,
( V_63 ) V_182 -> V_184 ,
V_51 . V_58 - 2 * sizeof( V_78 ) ) ;
if ( V_53 != V_64 )
F_14 ( V_5 , V_43 , 0 , 0 , L_8 ) ;
F_11 ( V_121 ) ;
return V_53 ;
}
static int F_72 ( void T_2 * V_47 ,
struct V_4 * V_5 )
{
struct V_50 V_51 ;
if ( F_20 ( & V_51 , V_47 , sizeof( struct V_50 ) ) )
return - V_44 ;
if ( V_5 -> V_185 == V_186 || V_5 -> V_185 == V_187 ) {
if ( F_16 ( V_51 . V_65 , & V_5 -> V_188 ,
sizeof( T_6 ) ) )
return - V_44 ;
}
return V_64 ;
}
static int F_73 ( void T_2 * V_47 ,
struct V_4 * V_5 )
{
struct V_50 V_51 ;
T_6 V_189 = 0 ;
INT V_53 = V_54 ;
if ( V_5 -> V_185 == V_187 ) {
if ( F_20 ( & V_51 , V_47 ,
sizeof( struct V_50 ) ) )
return - V_44 ;
if ( F_20 ( & V_189 , V_51 . V_60 ,
sizeof( T_6 ) ) )
return - V_44 ;
if ( ( V_189 < V_190 ) ||
( V_189 > V_191 ) ) {
if ( F_16 ( V_51 . V_65 ,
& V_5 -> V_189 , sizeof( T_6 ) ) )
return - V_44 ;
} else {
if ( F_74 ( V_5 ) ) {
if ( F_16 ( V_51 . V_65 ,
& V_5 -> V_189 , sizeof( T_6 ) ) )
return - V_44 ;
} else {
if ( ( TRUE == V_5 -> V_80 ) ||
( TRUE == V_5 -> V_79 ) ) {
F_14 ( V_5 ,
V_43 , 0 , 0 ,
L_56 ) ;
return - V_38 ;
}
V_5 -> V_189 = V_189 ;
F_75 ( V_5 ,
V_5 -> V_189 ) ;
}
}
V_53 = V_64 ;
} else {
V_53 = V_54 ;
}
return V_53 ;
}
static int F_76 ( void T_2 * V_47 ,
struct V_4 * V_5 )
{
#ifdef F_77
struct V_50 V_51 ;
struct V_192 V_193 ;
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_57 ) ;
if ( F_20 ( & V_51 , V_47 , sizeof( struct V_50 ) ) )
return - V_44 ;
if ( F_20 ( & V_193 , V_51 . V_60 ,
sizeof( struct V_192 ) ) )
return - V_44 ;
F_14 ( V_5 , V_43 , 0 , 0 ,
L_58 ,
V_193 . V_194 , V_193 . Type ) ;
V_193 . V_195 = 1 << V_193 . V_195 ;
F_14 ( V_5 , V_43 , 0 , 0 ,
L_59 , V_193 . V_195 ) ;
V_5 -> V_196 . type |= V_193 . Type ;
if ( V_193 . V_194 )
V_5 -> V_196 . V_197 [ V_193 . Type ] |=
V_193 . V_195 ;
else
V_5 -> V_196 . V_197 [ V_193 . Type ] &=
~ V_193 . V_195 ;
F_78 ( V_5 ) ;
#endif
return V_64 ;
}
static int F_79 ( void T_2 * V_47 ,
struct V_4 * V_5 , T_6 V_82 )
{
struct V_198 V_199 ;
struct V_200 V_201 , V_202 ;
struct V_50 V_51 ;
T_12 V_203 = NULL ;
V_78 V_204 = 0 ;
INT V_53 = V_54 ;
memset ( & V_201 , 0 , sizeof( struct V_200 ) ) ;
memset ( & V_202 , 0 , sizeof( struct V_200 ) ) ;
if ( ( V_5 -> V_185 == V_187 ) &&
( V_5 -> V_205 == 0 ) ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_60 ) ;
return - V_44 ;
}
if ( F_74 ( V_5 ) ) {
if ( ( V_5 -> V_206 != V_207 ) &&
( V_5 -> V_206 != V_208 ) &&
( V_5 -> V_206 != V_209 ) ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_61 ) ;
return V_54 ;
}
}
if ( F_20 ( & V_51 , V_47 , sizeof( struct V_50 ) ) )
return - V_44 ;
if ( F_20 ( & V_199 ,
( V_210 == V_82 ) ?
V_51 . V_65 : V_51 . V_60 ,
sizeof( struct V_198 ) ) )
return - V_44 ;
if ( V_199 . V_211 > V_5 -> V_188 )
return V_54 ;
if ( V_199 . V_212 >
V_5 -> V_188 - V_199 . V_211 )
return V_54 ;
V_203 = F_37 ( V_199 . V_213 ,
V_199 . V_211 ) ;
if ( F_38 ( V_203 ) )
return F_39 ( V_203 ) ;
F_80 ( & V_201 ) ;
if ( V_210 == V_82 ) {
F_4 ( & V_5 -> V_128 ) ;
if ( ( V_5 -> V_79 == TRUE ) ||
( V_5 -> V_80 == TRUE ) ||
( V_5 -> V_81 == TRUE ) ) {
F_14 ( V_5 ,
V_33 , V_34 , V_35 ,
L_56 ) ;
F_5 ( & V_5 -> V_128 ) ;
F_11 ( V_203 ) ;
return - V_38 ;
}
V_53 = F_81 ( V_5 , ( V_63 ) V_203 ,
V_199 . V_212 , V_199 . V_211 ) ;
F_5 ( & V_5 -> V_128 ) ;
if ( V_53 != V_64 ) {
F_11 ( V_203 ) ;
return V_53 ;
}
if ( F_16 ( V_199 . V_213 , V_203 ,
V_199 . V_211 ) ) {
F_11 ( V_203 ) ;
return - V_44 ;
}
} else {
F_4 ( & V_5 -> V_128 ) ;
if ( ( V_5 -> V_79 == TRUE ) ||
( V_5 -> V_80 == TRUE ) ||
( V_5 -> V_81 == TRUE ) ) {
F_14 ( V_5 ,
V_33 , V_34 , V_35 ,
L_56 ) ;
F_5 ( & V_5 -> V_128 ) ;
F_11 ( V_203 ) ;
return - V_38 ;
}
V_5 -> V_214 = TRUE ;
if ( F_74 ( V_5 ) ) {
V_53 = F_82 ( V_5 ,
V_5 -> V_206 ) ;
if ( V_53 != V_64 ) {
if ( ( ( V_199 . V_212 + V_199 . V_211 ) !=
V_5 -> V_188 ) ||
( V_199 . V_211 < V_215 ) ) {
F_14 ( V_5 , V_33 ,
V_34 , V_35 ,
L_62 ) ;
F_5 ( & V_5 -> V_128 ) ;
F_11 ( V_203 ) ;
return V_53 ;
}
V_204 = F_83 ( * ( V_63 ) ( V_203 + V_199 . V_211 - V_215 ) ) ;
if ( V_204 !=
V_216 ) {
F_14 ( V_5 ,
V_33 , V_34 , V_35 ,
L_62 ) ;
F_5 ( & V_5 -> V_128 ) ;
F_11 ( V_203 ) ;
return V_53 ;
}
}
}
V_53 = F_84 ( V_5 , ( V_63 ) V_203 ,
V_199 . V_212 , V_199 . V_211 ,
V_199 . V_217 ) ;
if ( F_74 ( V_5 ) )
F_85 ( V_5 , V_5 -> V_206 ) ;
V_5 -> V_214 = false ;
F_5 ( & V_5 -> V_128 ) ;
if ( V_53 != V_64 ) {
F_11 ( V_203 ) ;
return V_53 ;
}
}
F_80 ( & V_202 ) ;
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_63 ,
( V_202 . V_218 - V_201 . V_218 ) * 1000 + ( V_202 . V_219 - V_201 . V_219 ) / 1000 ) ;
F_11 ( V_203 ) ;
return V_64 ;
}
static int F_86 ( void T_2 * V_47 ,
struct V_4 * V_5 )
{
struct V_220 V_221 = { 0 } ;
struct V_50 V_51 ;
T_12 V_222 = NULL ;
T_6 V_223 = 0 ;
T_6 V_224 = 0 ;
T_6 V_225 = 0 ;
T_6 V_226 = 0 ;
INT V_53 = V_54 ;
void T_2 * V_227 ;
if ( F_74 ( V_5 ) != TRUE ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_64 ) ;
return - V_59 ;
}
F_14 ( V_5 , V_33 , V_34 ,
V_35 , L_65 ) ;
if ( F_20 ( & V_51 , V_47 , sizeof( struct V_50 ) ) )
return - V_44 ;
if ( F_20 ( & V_221 , V_51 . V_60 ,
sizeof( struct V_220 ) ) )
return - V_44 ;
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_66 , V_221 . V_228 ) ;
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_67 , V_221 . V_229 ) ;
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_68 , V_221 . V_230 ) ;
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_69 , V_221 . V_217 ) ;
if ( F_87 ( V_5 , & V_221 ) == false )
return V_54 ;
V_223 = V_221 . V_230 ;
if ( V_223 > V_5 -> V_189 )
V_224 = V_5 -> V_189 ;
else
V_224 = V_223 ;
V_226 = V_221 . V_229 ;
V_227 = V_51 . V_65 ;
V_222 = ( T_5 ) F_3 ( V_224 , V_9 ) ;
if ( V_222 == NULL ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_70 ) ;
return - V_10 ;
}
F_4 ( & V_5 -> V_128 ) ;
if ( ( V_5 -> V_79 == TRUE ) ||
( V_5 -> V_80 == TRUE ) ||
( V_5 -> V_81 == TRUE ) ) {
F_14 ( V_5 , V_33 , V_34 ,
V_35 , L_56 ) ;
F_5 ( & V_5 -> V_128 ) ;
F_11 ( V_222 ) ;
return - V_38 ;
}
while ( V_223 ) {
if ( V_223 > V_5 -> V_189 )
V_225 = V_5 -> V_189 ;
else
V_225 = V_223 ;
V_53 = F_88 ( V_5 , ( V_63 ) V_222 ,
V_221 . V_228 , V_226 , V_225 ) ;
if ( V_53 ) {
F_14 ( V_5 ,
V_33 , V_34 , V_35 ,
L_71 ,
V_53 ) ;
break;
}
F_89 ( V_5 , V_33 , V_34 ,
V_35 , V_222 , V_225 ) ;
V_53 = F_16 ( V_227 , V_222 , V_225 ) ;
if ( V_53 ) {
F_14 ( V_5 ,
V_33 , V_34 , V_35 ,
L_72 , V_53 ) ;
F_5 ( & V_5 -> V_128 ) ;
F_11 ( V_222 ) ;
return - V_44 ;
}
V_223 = V_223 - V_225 ;
if ( V_223 ) {
V_226 = V_226 + V_225 ;
V_227 = V_227 + V_225 ;
}
}
F_5 ( & V_5 -> V_128 ) ;
F_11 ( V_222 ) ;
return V_53 ;
}
static int F_90 ( void T_2 * V_47 ,
struct V_4 * V_5 )
{
struct V_220 V_231 = { 0 } ;
struct V_50 V_51 ;
T_12 V_232 ;
void T_2 * V_233 ;
T_6 V_223 = 0 ;
T_6 V_224 = 0 ;
T_6 V_234 = 0 ;
T_6 V_235 = 0 ;
INT V_53 = V_54 ;
if ( F_74 ( V_5 ) != TRUE ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_64 ) ;
return - V_59 ;
}
V_5 -> V_236 = false ;
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_73 ) ;
if ( F_20 ( & V_51 , V_47 , sizeof( struct V_50 ) ) )
return - V_44 ;
if ( F_20 ( & V_231 , V_51 . V_60 ,
sizeof( struct V_220 ) ) )
return - V_44 ;
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_66 , V_231 . V_228 ) ;
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_74 , V_231 . V_229 ) ;
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_68 , V_231 . V_230 ) ;
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_69 , V_231 . V_217 ) ;
if ( ( V_231 . V_228 != V_237 ) && ( V_231 . V_228 != V_238 )
&& ( V_231 . V_228 != V_239 ) ) {
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_75 ) ;
return - V_59 ;
}
if ( F_87 ( V_5 , & V_231 ) == false )
return V_54 ;
V_233 = V_231 . V_240 ;
V_234 = V_231 . V_229 ;
V_223 = V_231 . V_230 ;
if ( V_223 > V_5 -> V_189 )
V_224 = V_5 -> V_189 ;
else
V_224 = V_223 ;
V_232 = F_21 ( V_224 , V_9 ) ;
if ( V_232 == NULL )
return - V_10 ;
V_235 = V_5 -> V_189 ;
if ( V_234 % V_5 -> V_189 )
V_235 = V_5 -> V_189 - ( V_234 % V_5 -> V_189 ) ;
if ( V_223 < V_235 )
V_235 = V_223 ;
F_4 ( & V_5 -> V_128 ) ;
if ( ( V_5 -> V_79 == TRUE ) ||
( V_5 -> V_80 == TRUE ) ||
( V_5 -> V_81 == TRUE ) ) {
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_56 ) ;
F_5 ( & V_5 -> V_128 ) ;
F_11 ( V_232 ) ;
return - V_38 ;
}
F_82 ( V_5 , V_231 . V_228 ) ;
do {
V_53 = F_20 ( V_232 , V_233 , V_235 ) ;
if ( V_53 ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_76 , V_53 ) ;
F_5 ( & V_5 -> V_128 ) ;
F_11 ( V_232 ) ;
return - V_44 ;
}
F_89 ( V_5 , V_33 ,
V_34 , V_35 , V_232 , V_235 ) ;
V_53 = F_91 ( V_5 , ( V_63 ) V_232 ,
V_231 . V_228 , V_234 , V_235 ,
V_231 . V_217 ) ;
if ( V_53 ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_71 , V_53 ) ;
break;
}
V_223 = V_223 - V_235 ;
if ( V_223 ) {
V_234 = V_234 + V_235 ;
V_233 = V_233 + V_235 ;
if ( V_223 > V_5 -> V_189 )
V_235 = V_5 -> V_189 ;
else
V_235 = V_223 ;
}
} while ( V_223 > 0 );
F_85 ( V_5 , V_231 . V_228 ) ;
F_5 ( & V_5 -> V_128 ) ;
F_11 ( V_232 ) ;
return V_53 ;
}
static int F_92 ( void T_2 * V_47 ,
struct V_4 * V_5 )
{
struct V_241 * V_242 ;
struct V_50 V_51 ;
INT V_53 = V_54 ;
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_77 ) ;
if ( F_20 ( & V_51 , V_47 , sizeof( struct V_50 ) ) )
return - V_44 ;
if ( V_51 . V_61 != sizeof( struct V_241 ) )
return - V_59 ;
V_242 = F_3 ( sizeof( struct V_241 ) , V_9 ) ;
if ( V_242 == NULL ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_78 ) ;
return - V_10 ;
}
F_4 ( & V_5 -> V_128 ) ;
if ( ( V_5 -> V_79 == TRUE ) ||
( V_5 -> V_80 == TRUE ) ||
( V_5 -> V_81 == TRUE ) ) {
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_56 ) ;
F_5 ( & V_5 -> V_128 ) ;
F_11 ( V_242 ) ;
return - V_38 ;
}
F_93 ( V_5 , V_242 ) ;
F_5 ( & V_5 -> V_128 ) ;
if ( F_16 ( V_51 . V_65 , V_242 ,
sizeof( struct V_241 ) ) ) {
F_11 ( V_242 ) ;
return - V_44 ;
}
F_11 ( V_242 ) ;
return V_53 ;
}
static int F_94 ( void T_2 * V_47 ,
struct V_4 * V_5 )
{
enum V_243 V_244 = 0 ;
INT V_53 = V_54 ;
struct V_50 V_51 ;
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_79 ) ;
if ( F_74 ( V_5 ) != TRUE ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_64 ) ;
return - V_59 ;
}
V_53 = F_20 ( & V_51 , V_47 , sizeof( struct V_50 ) ) ;
if ( V_53 ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_80 ) ;
return - V_44 ;
}
V_53 = F_20 ( & V_244 ,
V_51 . V_60 , sizeof( INT ) ) ;
if ( V_53 ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_81 ) ;
return - V_44 ;
}
F_4 ( & V_5 -> V_128 ) ;
if ( ( V_5 -> V_79 == TRUE ) ||
( V_5 -> V_80 == TRUE ) ||
( V_5 -> V_81 == TRUE ) ) {
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_56 ) ;
F_5 ( & V_5 -> V_128 ) ;
return - V_38 ;
}
V_53 = F_95 ( V_5 , V_244 ) ;
if ( V_53 )
F_14 ( V_5 , V_43 , 0 , 0 ,
L_82 ,
V_53 ) ;
F_5 ( & V_5 -> V_128 ) ;
return V_53 ;
}
static int F_96 ( void T_2 * V_47 ,
struct V_4 * V_5 )
{
struct V_245 V_246 = { 0 } ;
struct V_50 V_51 ;
INT V_53 = V_64 ;
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_83 ) ;
V_5 -> V_236 = false ;
if ( F_74 ( V_5 ) != TRUE ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_64 ) ;
return - V_59 ;
}
V_53 = F_20 ( & V_51 , V_47 , sizeof( struct V_50 ) ) ;
if ( V_53 ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_84 , V_53 ) ;
return - V_44 ;
}
V_53 = F_20 ( & V_246 , V_51 . V_60 ,
sizeof( struct V_245 ) ) ;
if ( V_53 ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_85 ,
V_53 ) ;
return - V_44 ;
}
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_86 , V_246 . V_247 ) ;
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_87 , V_246 . V_248 ) ;
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_88 , V_246 . V_229 ) ;
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_89 , V_246 . V_230 ) ;
if ( F_97 ( V_5 , V_246 . V_247 ) == false ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_90 ,
V_246 . V_247 ) ;
return - V_59 ;
}
if ( F_97 ( V_5 , V_246 . V_248 ) == false ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_91 ,
V_246 . V_248 ) ;
return - V_59 ;
}
if ( V_246 . V_247 == V_246 . V_248 ) {
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_92 ) ;
return - V_59 ;
}
F_4 ( & V_5 -> V_128 ) ;
if ( ( V_5 -> V_79 == TRUE ) ||
( V_5 -> V_80 == TRUE ) ||
( V_5 -> V_81 == TRUE ) ) {
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_56 ) ;
F_5 ( & V_5 -> V_128 ) ;
return - V_38 ;
}
if ( V_246 . V_247 == V_249 ||
V_246 . V_247 == V_250 ) {
if ( F_98 ( V_5 ) ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_93 ) ;
V_53 = - V_59 ;
} else if ( V_246 . V_230 == 0 ) {
V_53 = F_99 ( V_5 , V_246 ) ;
} else {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_94 ) ;
V_53 = V_54 ;
}
F_5 ( & V_5 -> V_128 ) ;
return V_53 ;
}
V_53 = F_100 ( V_5 , V_246 . V_247 ,
V_246 . V_248 ,
V_246 . V_229 ,
V_246 . V_230 ) ;
F_5 ( & V_5 -> V_128 ) ;
return V_53 ;
}
static int F_101 ( void T_2 * V_47 ,
struct V_4 * V_5 )
{
struct V_50 V_51 ;
INT V_53 = V_64 ;
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_95 ) ;
V_53 = F_20 ( & V_51 , V_47 , sizeof( struct V_50 ) ) ;
if ( V_53 ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_80 ) ;
return - V_44 ;
}
if ( V_5 -> V_185 != V_187 ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_96 ) ;
return - V_59 ;
}
if ( F_74 ( V_5 ) == TRUE ) {
if ( V_51 . V_61 < sizeof( struct V_251 ) )
return - V_59 ;
if ( F_16 ( V_51 . V_65 ,
V_5 -> V_252 ,
sizeof( struct V_251 ) ) )
return - V_44 ;
} else {
if ( V_51 . V_61 < sizeof( struct V_253 ) )
return - V_59 ;
if ( F_16 ( V_51 . V_65 , V_5 -> V_254 ,
sizeof( struct V_253 ) ) )
return - V_44 ;
}
return V_53 ;
}
static int F_102 ( void T_2 * V_47 ,
struct V_4 * V_5 )
{
struct V_50 V_51 ;
INT V_53 = V_54 ;
T_6 V_255 = 0 ;
enum V_243 V_244 ;
V_244 = V_256 ;
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_97 ) ;
if ( F_74 ( V_5 ) != TRUE ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_64 ) ;
return - V_59 ;
}
V_53 = F_20 ( & V_51 , V_47 , sizeof( struct V_50 ) ) ;
if ( V_53 ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_80 ) ;
return - V_44 ;
}
V_53 = F_20 ( & V_244 , V_51 . V_60 ,
sizeof( INT ) ) ;
if ( V_53 ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_81 ) ;
return - V_44 ;
}
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_98 , V_244 ) ;
if ( ( V_244 != V_207 ) &&
( V_244 != V_208 ) &&
( V_244 != V_209 ) ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_99 ,
V_244 ) ;
return V_54 ;
}
V_255 = F_103 ( V_5 , V_244 ) ;
if ( V_255 == V_257 ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_100 ,
V_244 ) ;
return - V_59 ;
}
V_5 -> V_236 = TRUE ;
V_5 -> V_258 = V_255 ;
V_5 -> V_206 = V_244 ;
return V_64 ;
}
static int F_104 ( void T_2 * V_47 ,
struct V_4 * V_5 )
{
struct V_198 V_259 ;
struct V_50 V_51 ;
unsigned int V_223 ;
INT V_224 ;
INT V_226 = 0 ;
T_6 V_225 = 0 ;
T_12 V_222 ;
void T_2 * V_227 ;
INT V_53 = V_54 ;
if ( V_5 -> V_185 != V_187 ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_101 ) ;
return - V_59 ;
}
if ( F_20 ( & V_51 , V_47 , sizeof( struct V_50 ) ) ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_102 ) ;
return - V_44 ;
}
if ( F_20 ( & V_259 , V_51 . V_65 ,
sizeof( struct V_198 ) ) )
return - V_44 ;
V_223 = V_259 . V_211 ;
if ( V_223 > V_260 )
V_224 = V_260 ;
else
V_224 = V_223 ;
V_226 = V_259 . V_212 ;
V_227 = V_259 . V_213 ;
V_222 = F_3 ( V_224 , V_9 ) ;
if ( V_222 == NULL ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_70 ) ;
return - V_10 ;
}
F_4 ( & V_5 -> V_128 ) ;
if ( ( V_5 -> V_79 == TRUE ) ||
( V_5 -> V_80 == TRUE ) ||
( V_5 -> V_81 == TRUE ) ) {
F_14 ( V_5 , V_33 , V_34 ,
V_35 , L_56 ) ;
F_11 ( V_222 ) ;
F_5 ( & V_5 -> V_128 ) ;
return - V_38 ;
}
V_5 -> V_261 = TRUE ;
while ( V_223 ) {
if ( V_223 > V_260 )
V_225 = V_260 ;
else
V_225 = V_223 ;
V_53 = F_81 ( V_5 , ( V_63 ) V_222 ,
V_226 , V_225 ) ;
if ( V_53 ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_71 , V_53 ) ;
break;
}
F_89 ( V_5 , V_33 , V_34 ,
V_35 , V_222 , V_225 ) ;
V_53 = F_16 ( V_227 , V_222 , V_225 ) ;
if ( V_53 ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_72 , V_53 ) ;
F_5 ( & V_5 -> V_128 ) ;
F_11 ( V_222 ) ;
return - V_44 ;
}
V_223 = V_223 - V_225 ;
if ( V_223 ) {
V_226 = V_226 + V_225 ;
V_227 = V_227 + V_225 ;
}
}
V_5 -> V_261 = false ;
F_5 ( & V_5 -> V_128 ) ;
F_11 ( V_222 ) ;
return V_53 ;
}
static int F_105 ( void T_2 * V_47 ,
struct V_4 * V_5 , struct V_6 * V_7 )
{
struct V_50 V_51 ;
INT V_53 = V_54 ;
V_78 V_11 = 0 ;
V_53 = F_20 ( & V_51 , V_47 , sizeof( struct V_50 ) ) ;
if ( V_53 ) {
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_103 ) ;
return - V_44 ;
}
if ( V_51 . V_58 != sizeof( unsigned long ) )
return - V_59 ;
V_53 = F_20 ( & V_11 ,
V_51 . V_60 , V_51 . V_58 ) ;
if ( V_53 ) {
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_104 ) ;
return - V_44 ;
}
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_105 ,
V_11 ) ;
V_7 -> V_11 = V_11 ;
return V_53 ;
}
static int F_106 ( void T_2 * V_47 ,
struct V_4 * V_5 )
{
struct V_262 V_263 ;
struct V_50 V_51 ;
F_14 ( V_5 , V_33 , V_34 ,
V_35 , L_106 ) ;
memset ( & V_263 , 0 , sizeof( V_263 ) ) ;
V_263 . V_264 = V_265 ;
V_263 . V_266 = V_267 ;
V_263 . V_268 = 0 ;
V_263 . V_269 = V_5 -> V_185 ;
V_263 . V_270 = V_271 ;
if ( F_20 ( & V_51 , V_47 , sizeof( struct V_50 ) ) )
return - V_44 ;
if ( V_51 . V_61 < sizeof( V_263 ) )
return - V_59 ;
if ( F_16 ( V_51 . V_65 , & V_263 , sizeof( V_263 ) ) )
return - V_44 ;
return V_64 ;
}
static int F_107 ( void T_2 * V_47 ,
struct V_4 * V_5 )
{
struct V_272 V_273 = { 0 } ;
struct V_50 V_51 ;
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_107 ) ;
if ( F_20 ( & V_51 , V_47 , sizeof( struct V_50 ) ) )
return - V_44 ;
if ( V_51 . V_61 < sizeof( struct V_272 ) )
return - V_59 ;
V_273 . V_274 =
F_108 () - V_5 -> V_275 ;
if ( F_16 ( V_51 . V_65 , & V_273 ,
sizeof( struct V_272 ) ) )
return - V_44 ;
return V_64 ;
}
static long F_109 ( struct V_2 * V_3 , T_6 V_82 , V_78 V_161 )
{
struct V_6 * V_7 = V_3 -> V_15 ;
void T_2 * V_47 = ( void T_2 * ) V_161 ;
struct V_4 * V_5 = V_7 -> V_5 ;
INT V_53 = V_54 ;
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_108 ,
V_82 , V_161 ) ;
if ( F_110 ( V_82 ) != V_276 )
return - V_44 ;
if ( F_111 ( V_82 ) & V_277 )
V_53 = ! F_112 ( V_278 , V_47 , F_113 ( V_82 ) ) ;
else if ( F_111 ( V_82 ) & V_279 )
V_53 = ! F_112 ( V_280 , V_47 , F_113 ( V_82 ) ) ;
else if ( V_281 == ( F_111 ( V_82 ) & V_281 ) )
V_53 = V_64 ;
if ( V_53 )
return - V_44 ;
if ( V_5 -> V_31 )
return - V_44 ;
if ( false == V_5 -> V_37 ) {
switch ( V_82 ) {
case V_282 :
case V_283 :
case V_284 :
case V_285 :
case V_286 :
case V_287 :
case V_288 :
case V_289 :
return - V_38 ;
default:
break;
}
}
V_53 = F_114 ( V_5 , V_82 , V_161 ) ;
if ( V_53 != V_290 )
return V_53 ;
switch ( V_82 ) {
case V_291 :
V_53 = F_19 ( V_47 , V_5 ) ;
return V_53 ;
case V_292 :
V_53 = F_23 ( V_47 , V_5 ) ;
return V_53 ;
case V_293 :
case V_294 :
V_53 = F_25 ( V_47 , V_5 ) ;
return V_53 ;
case V_83 :
case V_295 :
V_53 = F_27 ( V_47 , V_5 , V_82 ) ;
return V_53 ;
case V_288 :
V_53 = F_29 ( V_47 , V_5 ) ;
return V_53 ;
case V_296 :
V_53 = F_31 ( V_47 , V_5 ) ;
return V_53 ;
case V_289 :
V_53 = F_33 ( V_47 , V_5 ) ;
return V_53 ;
case V_297 :
V_53 = F_34 ( V_47 , V_5 ) ;
return V_53 ;
case V_298 :
V_53 = F_35 ( V_47 , V_5 ) ;
return V_53 ;
case V_282 :
case V_283 :
case V_284 :
case V_285 :
case V_286 :
case V_287 :
V_53 = F_36 ( V_47 , V_5 ) ;
return V_53 ;
case V_299 :
V_53 = F_42 ( V_5 ) ;
return V_53 ;
case V_300 :
V_53 = F_49 ( V_47 , V_5 ) ;
return V_53 ;
case V_301 :
V_53 = F_51 ( V_47 , V_5 ) ;
return V_53 ;
case V_302 :
V_53 = 0 ;
if ( F_60 ( V_5 -> V_303 , ( unsigned long T_2 * ) V_161 ) )
V_53 = - V_44 ;
break;
case V_304 :
V_53 = 0 ;
if ( F_60 ( V_5 -> V_305 , ( unsigned long T_2 * ) V_161 ) )
V_53 = - V_44 ;
break;
case V_306 :
V_53 = F_56 ( V_5 ) ;
return V_53 ;
case V_307 :
V_53 = F_59 ( V_161 , V_5 ) ;
return V_53 ;
case V_308 :
F_115 ( V_5 ) ;
F_116 ( & V_5 -> V_309 ) ;
V_53 = V_64 ;
break;
case V_310 :
if ( F_16 ( V_47 , & V_5 -> V_164 ,
sizeof( struct V_311 ) * V_163 ) )
return - V_44 ;
V_53 = V_64 ;
break;
case V_312 :
V_53 = F_61 ( V_47 , V_5 ) ;
return V_53 ;
case V_313 :
V_53 = F_62 ( V_47 ) ;
return V_53 ;
case V_314 :
V_53 = F_63 ( V_47 , V_5 ) ;
return V_53 ;
case V_315 :
V_53 = F_64 ( V_47 , V_5 ) ;
return V_53 ;
case V_316 :
V_53 = F_65 ( V_47 , V_5 ) ;
return V_53 ;
case V_317 :
V_53 = F_67 ( V_47 , V_5 , V_7 ) ;
return V_53 ;
case V_318 :
if ( ( false == V_5 -> V_319 ) &&
( TRUE == V_5 -> V_79 ) ) {
V_5 -> V_320 = V_321 ;
V_5 -> V_322 = TRUE ;
F_32 ( & V_5 -> V_323 ) ;
}
V_53 = V_64 ;
break;
case V_324 :
V_53 = F_70 ( V_47 , V_5 , V_82 ) ;
return V_53 ;
case V_325 :
V_53 = F_72 ( V_47 , V_5 ) ;
return V_53 ;
case V_326 :
V_53 = F_73 ( V_47 , V_5 ) ;
return V_53 ;
case V_327 :
V_53 = F_76 ( V_47 , V_5 ) ;
return V_53 ;
case V_210 :
case V_328 :
V_53 = F_79 ( V_47 , V_5 , V_82 ) ;
return V_53 ;
case V_329 :
V_53 = F_86 ( V_47 , V_5 ) ;
return V_53 ;
case V_330 :
V_53 = F_90 ( V_47 , V_5 ) ;
return V_53 ;
case V_331 :
V_53 = F_92 ( V_47 , V_5 ) ;
return V_53 ;
case V_332 :
V_53 = F_94 ( V_47 , V_5 ) ;
return V_53 ;
case V_333 :
V_5 -> V_236 = false ;
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_109 ) ;
V_53 = V_64 ;
break;
case V_334 :
V_53 = F_96 ( V_47 , V_5 ) ;
return V_53 ;
case V_335 :
V_53 = F_101 ( V_47 , V_5 ) ;
return V_53 ;
case V_336 :
V_53 = F_102 ( V_47 , V_5 ) ;
return V_53 ;
case V_337 :
V_53 = F_104 ( V_47 , V_5 ) ;
return V_53 ;
case V_338 :
V_53 = F_105 ( V_47 , V_5 , V_7 ) ;
return V_53 ;
case V_339 :
V_53 = F_106 ( V_47 , V_5 ) ;
return V_53 ;
case V_340 :
V_53 = F_107 ( V_47 , V_5 ) ;
return V_53 ;
case V_341 :
F_14 ( V_5 , V_33 , V_34 ,
V_35 , L_110 ) ;
break;
default:
F_117 ( V_342 L_111 , V_82 ) ;
V_53 = V_54 ;
break;
}
return V_53 ;
}
int F_118 ( struct V_4 * V_5 )
{
if ( V_5 -> V_343 > 0 )
return V_5 -> V_343 ;
V_5 -> V_343 = F_119 ( 0 , V_344 , & V_345 ) ;
if ( V_5 -> V_343 < 0 ) {
F_47 ( V_342 L_112 ) ;
return V_5 -> V_343 ;
}
V_5 -> V_346 = F_120 ( V_347 , NULL ,
F_121 ( V_5 -> V_343 , 0 ) ,
V_5 , V_344 ) ;
if ( F_38 ( V_5 -> V_346 ) ) {
F_47 ( V_342 L_113 ) ;
F_122 ( V_5 -> V_343 , V_344 ) ;
return F_39 ( V_5 -> V_346 ) ;
}
return 0 ;
}
void F_123 ( struct V_4 * V_5 )
{
if ( V_5 -> V_343 > 0 ) {
F_124 ( V_347 , F_121 ( V_5 -> V_343 , 0 ) ) ;
F_122 ( V_5 -> V_343 , V_344 ) ;
}
}
