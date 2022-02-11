static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 ,
V_6 ) ;
struct V_7 * V_8 = V_5 -> V_8 ;
T_1 V_9 [ 5 ] ;
int V_10 ;
V_10 = F_3 ( V_8 , V_11 , V_9 ,
sizeof( V_9 ) , V_12 ,
V_13 ) ;
if ( V_10 != sizeof( V_9 ) ) {
F_4 ( V_8 , L_1 , V_10 ) ;
return V_10 ;
}
V_9 [ 1 ] &= ~ ( 1 << V_3 ) ;
V_9 [ 2 ] = V_14 ;
V_10 = F_3 ( V_8 , V_11 , V_9 , sizeof( V_9 ) ,
V_12 , V_15 ) ;
if ( V_10 < 0 ) {
F_4 ( V_8 , L_2 , V_10 ) ;
return V_10 ;
}
return 0 ;
}
static void F_5 ( struct V_1 * V_2 , unsigned V_3 , int V_16 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 ,
V_6 ) ;
struct V_7 * V_8 = V_5 -> V_8 ;
T_1 V_9 [ 3 ] ;
int V_10 ;
V_9 [ 0 ] = V_17 ;
V_9 [ 1 ] = V_16 ? 0xff : 0 ;
V_9 [ 2 ] = 1 << V_3 ;
V_10 = F_3 ( V_8 , V_17 , V_9 , sizeof( V_9 ) ,
V_12 , V_15 ) ;
if ( V_10 < 0 )
F_4 ( V_8 , L_3 , V_10 ) ;
}
static int F_6 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 ,
V_6 ) ;
struct V_7 * V_8 = V_5 -> V_8 ;
T_1 V_9 [ 2 ] ;
int V_10 ;
V_10 = F_3 ( V_8 , V_18 , V_9 , sizeof( V_9 ) ,
V_12 , V_13 ) ;
if ( V_10 != sizeof( V_9 ) ) {
F_4 ( V_8 , L_4 , V_10 ) ;
return V_10 ;
}
return ( V_9 [ 1 ] >> V_3 ) & 1 ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned V_3 , int V_16 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 ,
V_6 ) ;
struct V_7 * V_8 = V_5 -> V_8 ;
T_1 V_9 [ 5 ] ;
int V_10 ;
V_10 = F_3 ( V_8 , V_11 , V_9 ,
sizeof( V_9 ) , V_12 ,
V_13 ) ;
if ( V_10 != sizeof( V_9 ) ) {
F_4 ( V_8 , L_1 , V_10 ) ;
return V_10 ;
}
V_9 [ 1 ] |= 1 << V_3 ;
V_9 [ 2 ] = V_14 ;
V_10 = F_3 ( V_8 , V_11 , V_9 , sizeof( V_9 ) ,
V_12 , V_15 ) ;
if ( V_10 < 0 ) {
F_4 ( V_8 , L_2 , V_10 ) ;
return V_10 ;
}
F_5 ( V_2 , V_3 , V_16 ) ;
return 0 ;
}
static int F_8 ( struct V_7 * V_8 , unsigned char V_19 ,
T_1 * V_20 , T_2 V_21 , unsigned char V_22 )
{
T_1 * V_9 ;
int V_10 ;
V_9 = F_9 ( V_21 , V_23 ) ;
if ( ! V_9 )
return - V_24 ;
V_10 = F_3 ( V_8 , V_19 , V_9 , V_21 ,
V_22 , V_13 ) ;
memcpy ( V_20 , V_9 , V_21 ) ;
F_10 ( V_9 ) ;
return V_10 ;
}
static int F_11 ( struct V_7 * V_8 , T_1 * V_20 , T_2 V_21 ,
unsigned char V_22 )
{
T_1 * V_9 ;
int V_10 ;
V_9 = F_12 ( V_20 , V_21 , V_23 ) ;
if ( ! V_9 )
return - V_24 ;
if ( V_22 == V_25 )
V_10 = F_13 ( V_8 , V_9 , V_21 ) ;
else
V_10 = F_3 ( V_8 , V_9 [ 0 ] , V_9 , V_21 , V_22 ,
V_15 ) ;
F_10 ( V_9 ) ;
return V_10 ;
}
static int F_14 ( struct V_4 * V_5 , T_3 * V_26 )
{
int V_10 = 0 ;
V_10 = F_15 ( V_5 -> V_27 ,
F_16 ( V_26 ) , F_17 ( V_28 ) ) ;
if ( - V_29 == V_10 )
return V_10 ;
if ( ! V_10 )
return - V_30 ;
F_18 ( V_26 , 0 ) ;
return 0 ;
}
static int F_19 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = V_5 -> V_8 ;
T_1 V_9 [ 2 ] ;
int V_10 ;
V_9 [ 0 ] = V_31 ;
V_9 [ 1 ] = 0x01 ;
F_18 ( & V_5 -> V_32 , 0 ) ;
V_10 = F_11 ( V_8 , V_9 , 2 , V_25 ) ;
if ( V_10 < 0 ) {
F_20 ( V_8 , L_5 , V_10 ) ;
return V_10 ;
}
V_10 = F_14 ( V_5 , & V_5 -> V_32 ) ;
if ( V_10 )
return V_10 ;
return V_5 -> V_33 ;
}
static int F_21 ( struct V_4 * V_5 , T_1 * V_20 , T_2 V_34 )
{
struct V_7 * V_8 = V_5 -> V_8 ;
struct V_35 V_36 ;
int V_10 ;
if ( V_34 > sizeof( V_5 -> V_37 ) )
V_34 = sizeof( V_5 -> V_37 ) ;
V_36 . V_36 = V_38 ;
V_36 . V_39 = F_22 ( V_34 ) ;
F_18 ( & V_5 -> V_40 , 0 ) ;
V_10 = F_11 ( V_8 , & V_36 . V_36 , sizeof( V_36 ) ,
V_25 ) ;
if ( V_10 < 0 ) {
F_20 ( V_8 , L_6 , V_10 ) ;
return V_10 ;
}
V_10 = F_14 ( V_5 , & V_5 -> V_40 ) ;
if ( V_10 )
return V_10 ;
F_23 ( V_8 , L_7 ,
V_5 -> V_41 , V_34 ) ;
if ( V_34 > V_5 -> V_41 )
V_34 = V_5 -> V_41 ;
memcpy ( V_20 , V_5 -> V_37 , V_34 ) ;
return V_5 -> V_41 ;
}
static int F_24 ( void * V_9 , T_1 V_42 , T_4 V_39 )
{
struct V_43 * V_36 = V_9 ;
if ( V_39 < 1 || V_39 > 512 )
return - V_44 ;
V_36 -> V_36 = V_45 ;
V_36 -> V_42 = V_42 << 1 ;
V_36 -> V_39 = F_22 ( V_39 ) ;
return sizeof( * V_36 ) ;
}
static int F_25 ( void * V_9 , T_1 V_42 , T_4 V_39 ,
T_1 V_46 , T_1 * V_20 , T_1 V_47 )
{
struct V_48 * V_36 = V_9 ;
if ( V_39 < 1 || V_39 > 512
|| V_47 > sizeof( V_36 -> V_49 ) - 1 )
return - V_44 ;
V_36 -> V_36 = V_50 ;
V_36 -> V_42 = V_42 << 1 ;
V_36 -> V_39 = F_22 ( V_39 ) ;
V_36 -> V_51 = V_47 + 1 ;
V_36 -> V_49 [ 0 ] = V_46 ;
memcpy ( & V_36 -> V_49 [ 1 ] , V_20 , V_47 ) ;
return V_47 + 6 ;
}
static int F_26 ( void * V_9 , T_1 V_42 , T_1 V_46 , T_1 * V_20 ,
T_1 V_47 )
{
struct V_52 * V_36 = V_9 ;
if ( V_47 > sizeof( V_36 -> V_20 ) - 1 )
return - V_44 ;
V_36 -> V_36 = V_53 ;
V_36 -> V_42 = V_42 << 1 ;
V_36 -> V_39 = V_47 + 1 ;
V_36 -> V_20 [ 0 ] = V_46 ;
memcpy ( & V_36 -> V_20 [ 1 ] , V_20 , V_47 ) ;
return V_47 + 4 ;
}
static int F_27 ( void * V_9 , T_1 V_42 , T_1 * V_20 ,
T_1 V_47 )
{
struct V_52 * V_36 = V_9 ;
if ( V_47 > sizeof( V_36 -> V_20 ) )
return - V_44 ;
V_36 -> V_36 = V_53 ;
V_36 -> V_42 = V_42 << 1 ;
V_36 -> V_39 = V_47 ;
memcpy ( V_36 -> V_20 , V_20 , V_47 ) ;
return V_47 + 3 ;
}
static int F_28 ( struct V_54 * V_55 , struct V_56 * V_57 ,
int V_58 )
{
struct V_4 * V_5 = (struct V_4 * ) V_55 -> V_59 ;
struct V_7 * V_8 = V_5 -> V_8 ;
T_1 V_9 [ 64 ] ;
T_5 V_21 ;
unsigned int V_60 ;
int V_10 ;
F_23 ( V_8 , L_8 , V_58 ) ;
if ( V_58 != 1 ) {
F_4 ( V_8 ,
L_9 ) ;
return - V_61 ;
}
if ( V_57 -> V_62 & V_63 )
V_21 = F_24 ( V_9 , V_57 -> V_64 , V_57 -> V_65 ) ;
else
V_21 = F_27 ( V_9 , V_57 -> V_64 , V_57 -> V_9 ,
V_57 -> V_65 ) ;
if ( V_21 < 0 )
return V_21 ;
V_10 = F_29 ( V_8 , V_66 ) ;
if ( V_10 < 0 ) {
F_4 ( V_8 , L_10 , V_10 ) ;
return V_10 ;
}
V_10 = F_11 ( V_8 , V_9 , V_21 , V_25 ) ;
if ( V_10 < 0 ) {
F_20 ( V_8 , L_11 , V_10 ) ;
goto V_67;
}
for ( V_60 = 0 ; V_60 < V_68 ; ++ V_60 ) {
V_10 = F_19 ( V_5 ) ;
if ( - V_69 == V_10 )
continue;
if ( V_10 < 0 )
goto V_67;
break;
}
if ( V_68 <= V_60 ) {
F_20 ( V_8 , L_12 ) ;
V_9 [ 0 ] = V_70 ;
V_9 [ 1 ] = 0x01 ;
V_10 = F_11 ( V_8 , V_9 , 2 , V_25 ) ;
if ( V_10 < 0 )
F_20 ( V_8 , L_13 ,
V_10 ) ;
V_10 = - V_30 ;
goto V_67;
}
if ( ! ( V_57 -> V_62 & V_63 ) )
goto V_71;
V_10 = F_21 ( V_5 , V_57 -> V_9 , V_57 -> V_65 ) ;
if ( V_10 < 0 )
goto V_67;
if ( V_10 != V_57 -> V_65 ) {
F_20 ( V_8 , L_14 , V_10 , V_57 -> V_65 ) ;
V_10 = - V_72 ;
goto V_67;
}
V_71:
V_10 = 1 ;
V_67:
F_29 ( V_8 , V_73 ) ;
F_23 ( V_8 , L_15 , V_10 ) ;
return V_10 ;
}
static int F_30 ( struct V_54 * V_55 , T_4 V_64 ,
unsigned short V_62 , char V_74 , T_1 V_46 ,
int V_34 , union V_75 * V_20 )
{
struct V_4 * V_5 = (struct V_4 * ) V_55 -> V_59 ;
struct V_7 * V_8 = V_5 -> V_8 ;
T_1 V_9 [ 64 ] ;
T_6 V_76 ;
T_5 V_21 ;
T_2 V_41 = 0 ;
unsigned int V_60 ;
int V_10 ;
F_23 ( V_8 , L_16 ,
V_74 == V_77 ? L_17 : L_18 ,
V_64 , V_62 , V_46 , V_34 ) ;
switch ( V_34 ) {
case V_78 :
V_41 = 1 ;
if ( V_79 == V_74 )
V_21 = F_24 ( V_9 , V_64 , V_41 ) ;
else
V_21 = F_26 ( V_9 , V_64 , V_20 -> V_80 , NULL ,
0 ) ;
break;
case V_81 :
V_41 = 1 ;
if ( V_79 == V_74 )
V_21 = F_25 ( V_9 , V_64 , V_41 ,
V_46 , NULL , 0 ) ;
else
V_21 = F_26 ( V_9 , V_64 , V_46 ,
& V_20 -> V_80 , 1 ) ;
break;
case V_82 :
V_41 = 2 ;
V_76 = F_22 ( V_20 -> V_76 ) ;
if ( V_79 == V_74 )
V_21 = F_25 ( V_9 , V_64 , V_41 ,
V_46 , NULL , 0 ) ;
else
V_21 = F_26 ( V_9 , V_64 , V_46 ,
( T_1 * ) & V_76 , 2 ) ;
break;
case V_83 :
V_34 = V_82 ;
V_74 = V_79 ;
V_41 = 2 ;
V_76 = F_22 ( V_20 -> V_76 ) ;
V_21 = F_25 ( V_9 , V_64 , V_41 , V_46 ,
( T_1 * ) & V_76 , 2 ) ;
break;
case V_84 :
V_34 = V_85 ;
case V_85 :
if ( V_79 == V_74 ) {
V_21 = F_25 ( V_9 , V_64 ,
V_86 ,
V_46 , NULL , 0 ) ;
} else {
V_21 = F_26 ( V_9 , V_64 , V_46 ,
V_20 -> V_87 ,
V_20 -> V_87 [ 0 ] + 1 ) ;
}
break;
case V_88 :
V_34 = V_85 ;
V_74 = V_79 ;
V_21 = F_25 ( V_9 , V_64 , V_86 ,
V_46 , V_20 -> V_87 ,
V_20 -> V_87 [ 0 ] + 1 ) ;
break;
default:
F_20 ( V_8 , L_19 , V_34 ) ;
return - V_61 ;
}
if ( V_21 < 0 )
return V_21 ;
V_10 = F_29 ( V_8 , V_66 ) ;
if ( V_10 < 0 ) {
F_4 ( V_8 , L_10 , V_10 ) ;
return V_10 ;
}
V_10 = F_11 ( V_8 , V_9 , V_21 , V_25 ) ;
if ( V_10 < 0 ) {
F_20 ( V_8 , L_11 , V_10 ) ;
goto V_67;
}
for ( V_60 = 0 ; V_60 < V_68 ; ++ V_60 ) {
V_10 = F_19 ( V_5 ) ;
if ( - V_69 == V_10 )
continue;
if ( V_10 < 0 )
goto V_67;
break;
}
if ( V_68 <= V_60 ) {
F_20 ( V_8 , L_12 ) ;
V_9 [ 0 ] = V_70 ;
V_9 [ 1 ] = 0x01 ;
V_10 = F_11 ( V_8 , V_9 , 2 , V_25 ) ;
if ( V_10 < 0 )
F_20 ( V_8 , L_13 ,
V_10 ) ;
V_10 = - V_30 ;
goto V_67;
}
if ( V_77 == V_74 ) {
V_10 = 0 ;
goto V_67;
}
if ( V_85 == V_34 )
V_41 = V_10 ;
V_10 = F_21 ( V_5 , V_9 , V_41 ) ;
if ( V_10 < 0 )
goto V_67;
if ( V_10 != V_41 ) {
F_20 ( V_8 , L_20 , V_10 , V_41 ) ;
V_10 = - V_72 ;
goto V_67;
}
switch ( V_34 ) {
case V_78 :
case V_81 :
V_20 -> V_80 = V_9 [ 0 ] ;
break;
case V_82 :
V_20 -> V_76 = F_31 ( ( T_6 * ) V_9 ) ;
break;
case V_85 :
if ( V_41 > V_86 ) {
V_10 = - V_89 ;
goto V_67;
}
memcpy ( V_20 -> V_87 , V_9 , V_41 ) ;
break;
}
V_10 = 0 ;
V_67:
F_29 ( V_8 , V_73 ) ;
F_23 ( V_8 , L_21 , V_10 ) ;
return V_10 ;
}
static T_7 F_32 ( struct V_54 * V_55 )
{
return V_90 |
V_91 |
V_92 |
V_93 |
V_94 |
V_95 |
V_96 |
V_97 ;
}
static int F_33 ( struct V_7 * V_8 ,
struct V_98 * V_99 )
{
int V_10 ;
V_10 = F_8 ( V_8 , V_100 , ( T_1 * ) V_99 , sizeof( * V_99 ) ,
V_12 ) ;
if ( V_10 != sizeof( * V_99 ) ) {
F_4 ( V_8 , L_22 , V_10 ) ;
if ( V_10 < 0 )
return V_10 ;
return - V_72 ;
}
return 0 ;
}
static int F_34 ( struct V_7 * V_8 ,
struct V_98 * V_99 )
{
int V_10 ;
F_35 ( V_99 -> V_36 != V_100 ) ;
V_10 = F_11 ( V_8 , ( T_1 * ) V_99 , sizeof( * V_99 ) ,
V_12 ) ;
if ( V_10 != sizeof( * V_99 ) ) {
F_4 ( V_8 , L_23 , V_10 ) ;
if ( V_10 < 0 )
return V_10 ;
return - V_72 ;
}
return 0 ;
}
static T_5 F_36 ( struct V_101 * V_102 ,
struct V_103 * V_104 , const char * V_9 ,
T_2 V_21 )
{
struct V_7 * V_8 = F_2 ( V_102 , struct V_7 , V_5 ) ;
struct V_105 * V_106 =
F_2 ( V_104 , struct V_105 , V_106 ) ;
struct V_107 V_36 ;
int V_10 ;
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
V_10 = F_37 ( V_9 , V_21 , V_108 ,
V_36 . string , F_38 ( V_36 . string ) ) ;
V_36 . V_36 = V_106 -> V_36 ;
V_36 . V_39 = V_10 * sizeof( V_36 . string [ 0 ] ) + 2 ;
V_36 . type = V_109 ;
V_10 = F_11 ( V_8 , & V_36 . V_36 , V_36 . V_39 + 1 ,
V_12 ) ;
if ( V_10 != V_36 . V_39 + 1 ) {
F_4 ( V_8 , L_24 , V_104 -> V_106 . V_110 ,
V_10 ) ;
if ( V_10 < 0 )
return V_10 ;
return - V_72 ;
}
F_39 ( V_8 ) ;
return V_21 ;
}
static T_5 F_40 ( struct V_101 * V_102 ,
struct V_103 * V_104 , char * V_9 )
{
struct V_7 * V_8 = F_2 ( V_102 , struct V_7 , V_5 ) ;
struct V_105 * V_106 =
F_2 ( V_104 , struct V_105 , V_106 ) ;
struct V_107 V_36 ;
T_1 V_39 ;
int V_10 ;
V_10 = F_8 ( V_8 , V_106 -> V_36 , & V_36 . V_36 ,
sizeof( V_36 ) - 1 , V_12 ) ;
if ( V_10 < 3 ) {
F_4 ( V_8 , L_25 , V_104 -> V_106 . V_110 ,
V_10 ) ;
if ( V_10 < 0 )
return V_10 ;
return - V_72 ;
}
if ( V_36 . V_39 < 2 ) {
F_4 ( V_8 , L_26 ,
V_104 -> V_106 . V_110 , V_36 . V_39 ) ;
return - V_72 ;
}
V_39 = V_36 . V_39 > V_10 - 1 ? V_10 - 1 : V_36 . V_39 ;
V_39 = ( V_39 - 2 ) / sizeof( V_36 . string [ 0 ] ) ;
V_10 = F_41 ( V_36 . string , V_39 , V_108 , V_9 ,
V_111 - 1 ) ;
V_9 [ V_10 ++ ] = '\n' ;
return V_10 ;
}
static void F_39 ( struct V_7 * V_8 )
{
struct V_112 * * V_106 ;
T_1 V_9 [ 2 ] ;
int V_10 ;
V_10 = F_8 ( V_8 , V_113 , V_9 , sizeof( V_9 ) ,
V_12 ) ;
if ( V_10 != sizeof( V_9 ) ) {
F_4 ( V_8 , L_27 , V_10 ) ;
return;
}
for ( V_106 = V_114 . V_115 ; * V_106 ; ++ V_106 ) {
T_8 V_116 = ( V_9 [ 1 ] & 1 ) ? V_117 | V_118 : V_118 ;
V_10 = F_42 ( & V_8 -> V_5 . V_119 , * V_106 , V_116 ) ;
if ( V_10 < 0 )
F_4 ( V_8 , L_28 ,
( * V_106 ) -> V_110 ) ;
V_9 [ 1 ] >>= 1 ;
}
}
static int F_43 ( struct V_7 * V_8 , const struct V_120 * V_121 )
{
struct V_4 * V_5 ;
T_1 V_9 [ 3 ] ;
struct V_122 V_123 ;
int V_10 ;
V_10 = F_44 ( V_8 ) ;
if ( V_10 ) {
F_4 ( V_8 , L_29 ) ;
return V_10 ;
}
V_10 = F_45 ( V_8 , V_124 ) ;
if ( V_10 ) {
F_4 ( V_8 , L_30 ) ;
return V_10 ;
}
V_10 = F_46 ( V_8 ) ;
if ( V_10 ) {
F_4 ( V_8 , L_31 ) ;
goto V_125;
}
V_10 = F_29 ( V_8 , V_66 ) ;
if ( V_10 < 0 ) {
F_4 ( V_8 , L_10 , V_10 ) ;
goto V_126;
}
V_10 = F_8 ( V_8 , V_127 , V_9 , sizeof( V_9 ) ,
V_12 ) ;
if ( V_10 != sizeof( V_9 ) ) {
F_4 ( V_8 , L_32 ) ;
if ( V_10 >= 0 )
V_10 = - V_72 ;
goto V_128;
}
F_47 ( V_8 , L_33 ,
V_9 [ 1 ] , V_9 [ 2 ] ) ;
V_10 = F_8 ( V_8 , V_129 , ( T_1 * ) & V_123 ,
sizeof( V_123 ) , V_12 ) ;
if ( V_10 != sizeof( V_123 ) ) {
F_4 ( V_8 , L_34 ) ;
if ( V_10 >= 0 )
V_10 = - V_72 ;
goto V_128;
}
V_123 . V_130 = F_22 ( 1 ) ;
V_10 = F_11 ( V_8 , ( T_1 * ) & V_123 , sizeof( V_123 ) ,
V_12 ) ;
if ( V_10 != sizeof( V_123 ) ) {
F_4 ( V_8 , L_35 ) ;
if ( V_10 >= 0 )
V_10 = - V_72 ;
goto V_128;
}
V_5 = F_48 ( sizeof( * V_5 ) , V_23 ) ;
if ( ! V_5 ) {
V_10 = - V_24 ;
goto V_128;
}
F_49 ( V_8 , ( void * ) V_5 ) ;
V_5 -> V_8 = V_8 ;
V_5 -> V_55 . V_131 = V_132 ;
V_5 -> V_55 . V_133 = V_134 ;
V_5 -> V_55 . V_135 = & V_136 ;
V_5 -> V_55 . V_59 = V_5 ;
V_5 -> V_55 . V_5 . V_137 = & V_8 -> V_5 ;
snprintf ( V_5 -> V_55 . V_110 , sizeof( V_5 -> V_55 . V_110 ) ,
L_36 , V_8 -> V_138 ) ;
F_50 ( & V_5 -> V_27 ) ;
F_51 ( V_8 ) ;
V_10 = F_52 ( & V_5 -> V_55 ) ;
F_53 ( V_8 ) ;
if ( V_10 ) {
F_4 ( V_8 , L_37 ) ;
goto V_139;
}
F_23 ( V_8 , L_38 ) ;
V_5 -> V_6 . V_140 = L_39 ;
V_5 -> V_6 . V_141 = F_1 ;
V_5 -> V_6 . V_142 = F_7 ;
V_5 -> V_6 . V_143 = F_5 ;
V_5 -> V_6 . V_144 = F_6 ;
V_5 -> V_6 . V_145 = - 1 ;
V_5 -> V_6 . V_146 = 8 ;
V_5 -> V_6 . V_147 = 1 ;
V_5 -> V_6 . V_5 = & V_8 -> V_5 ;
V_10 = F_54 ( & V_5 -> V_6 ) ;
if ( V_10 < 0 ) {
F_4 ( V_8 , L_40 ) ;
goto V_148;
}
V_10 = F_55 ( & V_8 -> V_5 . V_119 , & V_114 ) ;
if ( V_10 < 0 ) {
F_4 ( V_8 , L_41 ) ;
goto V_149;
}
F_39 ( V_8 ) ;
F_29 ( V_8 , V_73 ) ;
return V_10 ;
V_149:
F_56 ( & V_5 -> V_6 ) ;
V_148:
F_57 ( & V_5 -> V_55 ) ;
V_139:
F_10 ( V_5 ) ;
V_128:
F_29 ( V_8 , V_73 ) ;
V_126:
F_58 ( V_8 ) ;
V_125:
F_59 ( V_8 ) ;
return V_10 ;
}
static void F_60 ( struct V_7 * V_8 )
{
struct V_4 * V_5 = F_61 ( V_8 ) ;
F_62 ( & V_8 -> V_5 . V_119 , & V_114 ) ;
F_56 ( & V_5 -> V_6 ) ;
F_57 ( & V_5 -> V_55 ) ;
F_58 ( V_8 ) ;
F_59 ( V_8 ) ;
F_10 ( V_5 ) ;
}
static int F_63 ( struct V_7 * V_8 , struct V_150 * V_36 ,
T_1 * V_20 , int V_34 )
{
struct V_4 * V_5 = F_61 ( V_8 ) ;
struct V_151 * V_152 = ( void * ) V_20 ;
switch ( V_20 [ 0 ] ) {
case V_153 :
F_23 ( V_8 , L_42 ,
V_152 -> V_154 , V_152 -> V_155 ,
F_64 ( V_152 -> V_60 ) , F_64 ( V_152 -> V_39 ) ) ;
switch ( V_152 -> V_154 ) {
case V_156 :
V_5 -> V_33 = - V_157 ;
break;
case V_158 :
V_5 -> V_33 = - V_69 ;
break;
case V_159 :
V_5 -> V_33 = F_64 ( V_152 -> V_39 ) ;
break;
case V_160 :
switch ( V_152 -> V_155 ) {
case V_161 :
case V_162 :
V_5 -> V_33 = - V_30 ;
break;
default:
V_5 -> V_33 = - V_72 ;
break;
}
break;
default:
V_5 -> V_33 = - V_44 ;
break;
}
F_18 ( & V_5 -> V_32 , 1 ) ;
break;
case V_163 :
F_23 ( V_8 , L_43 , V_20 [ 1 ] , V_20 [ 2 ] ) ;
V_5 -> V_41 = V_20 [ 2 ] ;
if ( V_5 -> V_41 > sizeof( V_5 -> V_37 ) )
V_5 -> V_41 = sizeof( V_5 -> V_37 ) ;
memcpy ( V_5 -> V_37 , & V_20 [ 3 ] , V_5 -> V_41 ) ;
F_18 ( & V_5 -> V_40 , 1 ) ;
break;
default:
F_4 ( V_8 , L_44 ) ;
return 0 ;
}
F_65 ( & V_5 -> V_27 ) ;
return 1 ;
}
