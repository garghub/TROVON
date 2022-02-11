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
F_5 ( V_2 , V_3 , V_16 ) ;
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
V_36 . V_36 = V_37 ;
V_36 . V_38 = F_22 ( V_34 ) ;
F_18 ( & V_5 -> V_39 , 0 ) ;
V_10 = F_11 ( V_8 , & V_36 . V_36 , sizeof( V_36 ) ,
V_25 ) ;
if ( V_10 < 0 ) {
F_20 ( V_8 , L_6 , V_10 ) ;
return V_10 ;
}
V_10 = F_14 ( V_5 , & V_5 -> V_39 ) ;
if ( V_10 )
return V_10 ;
F_23 ( V_8 , L_7 ,
V_5 -> V_40 , V_34 ) ;
if ( V_34 > V_5 -> V_40 )
V_34 = V_5 -> V_40 ;
memcpy ( V_20 , V_5 -> V_41 , V_34 ) ;
return V_5 -> V_40 ;
}
static int F_24 ( void * V_9 , T_1 V_42 , T_4 V_38 )
{
struct V_43 * V_36 = V_9 ;
if ( V_38 < 1 || V_38 > 512 )
return - V_44 ;
V_36 -> V_36 = V_45 ;
V_36 -> V_42 = V_42 << 1 ;
V_36 -> V_38 = F_22 ( V_38 ) ;
return sizeof( * V_36 ) ;
}
static int F_25 ( void * V_9 , T_1 V_42 , T_4 V_38 ,
T_1 V_46 , T_1 * V_20 , T_1 V_47 )
{
struct V_48 * V_36 = V_9 ;
if ( V_38 < 1 || V_38 > 512
|| V_47 > sizeof( V_36 -> V_49 ) - 1 )
return - V_44 ;
V_36 -> V_36 = V_50 ;
V_36 -> V_42 = V_42 << 1 ;
V_36 -> V_38 = F_22 ( V_38 ) ;
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
V_36 -> V_38 = V_47 + 1 ;
V_36 -> V_20 [ 0 ] = V_46 ;
memcpy ( & V_36 -> V_20 [ 1 ] , V_20 , V_47 ) ;
return V_47 + 4 ;
}
static int F_27 ( struct V_54 * V_55 , T_4 V_56 ,
unsigned short V_57 , char V_58 , T_1 V_46 ,
int V_34 , union V_59 * V_20 )
{
struct V_4 * V_5 = (struct V_4 * ) V_55 -> V_60 ;
struct V_7 * V_8 = V_5 -> V_8 ;
T_1 V_9 [ 64 ] ;
T_5 V_61 ;
T_6 V_21 ;
T_2 V_40 = 0 ;
unsigned int V_62 ;
int V_10 ;
F_23 ( V_8 , L_8 ,
V_58 == V_63 ? L_9 : L_10 ,
V_56 , V_57 , V_46 , V_34 ) ;
switch ( V_34 ) {
case V_64 :
V_40 = 1 ;
if ( V_65 == V_58 )
V_21 = F_24 ( V_9 , V_56 , V_40 ) ;
else
V_21 = F_26 ( V_9 , V_56 , V_20 -> V_66 , NULL ,
0 ) ;
break;
case V_67 :
V_40 = 1 ;
if ( V_65 == V_58 )
V_21 = F_25 ( V_9 , V_56 , V_40 ,
V_46 , NULL , 0 ) ;
else
V_21 = F_26 ( V_9 , V_56 , V_46 ,
& V_20 -> V_66 , 1 ) ;
break;
case V_68 :
V_40 = 2 ;
V_61 = F_22 ( V_20 -> V_61 ) ;
if ( V_65 == V_58 )
V_21 = F_25 ( V_9 , V_56 , V_40 ,
V_46 , NULL , 0 ) ;
else
V_21 = F_26 ( V_9 , V_56 , V_46 ,
( T_1 * ) & V_61 , 2 ) ;
break;
case V_69 :
V_34 = V_68 ;
V_58 = V_65 ;
V_40 = 2 ;
V_61 = F_22 ( V_20 -> V_61 ) ;
V_21 = F_25 ( V_9 , V_56 , V_40 , V_46 ,
( T_1 * ) & V_61 , 2 ) ;
break;
case V_70 :
V_34 = V_71 ;
case V_71 :
if ( V_65 == V_58 ) {
V_21 = F_25 ( V_9 , V_56 ,
V_72 ,
V_46 , NULL , 0 ) ;
} else {
V_21 = F_26 ( V_9 , V_56 , V_46 ,
V_20 -> V_73 ,
V_20 -> V_73 [ 0 ] + 1 ) ;
}
break;
case V_74 :
V_34 = V_71 ;
V_58 = V_65 ;
V_21 = F_25 ( V_9 , V_56 , V_72 ,
V_46 , V_20 -> V_73 ,
V_20 -> V_73 [ 0 ] + 1 ) ;
break;
default:
F_20 ( V_8 , L_11 , V_34 ) ;
return - V_75 ;
}
if ( V_21 < 0 )
return V_21 ;
V_10 = F_28 ( V_8 , V_76 ) ;
if ( V_10 < 0 ) {
F_4 ( V_8 , L_12 , V_10 ) ;
return V_10 ;
}
V_10 = F_11 ( V_8 , V_9 , V_21 , V_25 ) ;
if ( V_10 < 0 ) {
F_20 ( V_8 , L_13 , V_10 ) ;
goto V_77;
}
for ( V_62 = 0 ; V_62 < V_78 ; ++ V_62 ) {
V_10 = F_19 ( V_5 ) ;
if ( - V_79 == V_10 )
continue;
if ( V_10 < 0 )
goto V_77;
break;
}
if ( V_78 <= V_62 ) {
F_20 ( V_8 , L_14 ) ;
V_9 [ 0 ] = V_80 ;
V_9 [ 1 ] = 0x01 ;
V_10 = F_11 ( V_8 , V_9 , 2 , V_25 ) ;
if ( V_10 < 0 )
F_20 ( V_8 , L_15 ,
V_10 ) ;
V_10 = - V_30 ;
goto V_77;
}
if ( V_63 == V_58 ) {
V_10 = 0 ;
goto V_77;
}
if ( V_71 == V_34 )
V_40 = V_10 ;
V_10 = F_21 ( V_5 , V_9 , V_40 ) ;
if ( V_10 < 0 )
goto V_77;
if ( V_10 != V_40 ) {
F_20 ( V_8 , L_16 , V_10 , V_40 ) ;
V_10 = - V_81 ;
goto V_77;
}
switch ( V_34 ) {
case V_64 :
case V_67 :
V_20 -> V_66 = V_9 [ 0 ] ;
break;
case V_68 :
V_20 -> V_61 = F_29 ( ( T_5 * ) V_9 ) ;
break;
case V_71 :
if ( V_40 > V_72 ) {
V_10 = - V_82 ;
goto V_77;
}
memcpy ( V_20 -> V_73 , V_9 , V_40 ) ;
break;
}
V_10 = 0 ;
V_77:
F_28 ( V_8 , V_83 ) ;
F_23 ( V_8 , L_17 , V_10 ) ;
return V_10 ;
}
static T_7 F_30 ( struct V_54 * V_55 )
{
return V_84 |
V_85 |
V_86 |
V_87 |
V_88 |
V_89 |
V_90 ;
}
static int F_31 ( struct V_7 * V_8 ,
struct V_91 * V_92 )
{
int V_10 ;
V_10 = F_8 ( V_8 , V_93 , ( T_1 * ) V_92 , sizeof( * V_92 ) ,
V_12 ) ;
if ( V_10 != sizeof( * V_92 ) ) {
F_4 ( V_8 , L_18 , V_10 ) ;
if ( V_10 < 0 )
return V_10 ;
return - V_81 ;
}
return 0 ;
}
static int F_32 ( struct V_7 * V_8 ,
struct V_91 * V_92 )
{
int V_10 ;
F_33 ( V_92 -> V_36 != V_93 ) ;
V_10 = F_11 ( V_8 , ( T_1 * ) V_92 , sizeof( * V_92 ) ,
V_12 ) ;
if ( V_10 != sizeof( * V_92 ) ) {
F_4 ( V_8 , L_19 , V_10 ) ;
if ( V_10 < 0 )
return V_10 ;
return - V_81 ;
}
return 0 ;
}
static T_6 F_34 ( struct V_94 * V_95 ,
struct V_96 * V_97 , const char * V_9 ,
T_2 V_21 )
{
struct V_7 * V_8 = F_2 ( V_95 , struct V_7 , V_5 ) ;
struct V_98 * V_99 =
F_2 ( V_97 , struct V_98 , V_99 ) ;
struct V_100 V_36 ;
int V_10 ;
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
V_10 = F_35 ( V_9 , V_21 , V_101 ,
V_36 . string , F_36 ( V_36 . string ) ) ;
V_36 . V_36 = V_99 -> V_36 ;
V_36 . V_38 = V_10 * sizeof( V_36 . string [ 0 ] ) + 2 ;
V_36 . type = V_102 ;
V_10 = F_11 ( V_8 , & V_36 . V_36 , V_36 . V_38 + 1 ,
V_12 ) ;
if ( V_10 != V_36 . V_38 + 1 ) {
F_4 ( V_8 , L_20 , V_97 -> V_99 . V_103 ,
V_10 ) ;
if ( V_10 < 0 )
return V_10 ;
return - V_81 ;
}
F_37 ( V_8 ) ;
return V_21 ;
}
static T_6 F_38 ( struct V_94 * V_95 ,
struct V_96 * V_97 , char * V_9 )
{
struct V_7 * V_8 = F_2 ( V_95 , struct V_7 , V_5 ) ;
struct V_98 * V_99 =
F_2 ( V_97 , struct V_98 , V_99 ) ;
struct V_100 V_36 ;
T_1 V_38 ;
int V_10 ;
V_10 = F_8 ( V_8 , V_99 -> V_36 , & V_36 . V_36 ,
sizeof( V_36 ) - 1 , V_12 ) ;
if ( V_10 < 3 ) {
F_4 ( V_8 , L_21 , V_97 -> V_99 . V_103 ,
V_10 ) ;
if ( V_10 < 0 )
return V_10 ;
return - V_81 ;
}
if ( V_36 . V_38 < 2 ) {
F_4 ( V_8 , L_22 ,
V_97 -> V_99 . V_103 , V_36 . V_38 ) ;
return - V_81 ;
}
V_38 = V_36 . V_38 > V_10 - 1 ? V_10 - 1 : V_36 . V_38 ;
V_38 = ( V_38 - 2 ) / sizeof( V_36 . string [ 0 ] ) ;
V_10 = F_39 ( V_36 . string , V_38 , V_101 , V_9 ,
V_104 - 1 ) ;
V_9 [ V_10 ++ ] = '\n' ;
return V_10 ;
}
static void F_37 ( struct V_7 * V_8 )
{
struct V_105 * * V_99 ;
T_1 V_9 [ 2 ] ;
int V_10 ;
V_10 = F_8 ( V_8 , V_106 , V_9 , sizeof( V_9 ) ,
V_12 ) ;
if ( V_10 != sizeof( V_9 ) ) {
F_4 ( V_8 , L_23 , V_10 ) ;
return;
}
for ( V_99 = V_107 . V_108 ; * V_99 ; ++ V_99 ) {
T_8 V_109 = ( V_9 [ 1 ] & 1 ) ? V_110 | V_111 : V_111 ;
V_10 = F_40 ( & V_8 -> V_5 . V_112 , * V_99 , V_109 ) ;
if ( V_10 < 0 )
F_4 ( V_8 , L_24 ,
( * V_99 ) -> V_103 ) ;
V_9 [ 1 ] >>= 1 ;
}
}
static int F_41 ( struct V_7 * V_8 , const struct V_113 * V_114 )
{
struct V_4 * V_5 ;
T_1 V_9 [ 3 ] ;
struct V_115 V_116 ;
int V_10 ;
V_10 = F_42 ( V_8 ) ;
if ( V_10 ) {
F_4 ( V_8 , L_25 ) ;
return V_10 ;
}
V_10 = F_43 ( V_8 , V_117 ) ;
if ( V_10 ) {
F_4 ( V_8 , L_26 ) ;
return V_10 ;
}
V_10 = F_44 ( V_8 ) ;
if ( V_10 ) {
F_4 ( V_8 , L_27 ) ;
goto V_118;
}
V_10 = F_28 ( V_8 , V_76 ) ;
if ( V_10 < 0 ) {
F_4 ( V_8 , L_12 , V_10 ) ;
goto V_119;
}
V_10 = F_8 ( V_8 , V_120 , V_9 , sizeof( V_9 ) ,
V_12 ) ;
if ( V_10 != sizeof( V_9 ) ) {
F_4 ( V_8 , L_28 ) ;
if ( V_10 >= 0 )
V_10 = - V_81 ;
goto V_121;
}
F_45 ( V_8 , L_29 ,
V_9 [ 1 ] , V_9 [ 2 ] ) ;
V_10 = F_8 ( V_8 , V_122 , ( T_1 * ) & V_116 ,
sizeof( V_116 ) , V_12 ) ;
if ( V_10 != sizeof( V_116 ) ) {
F_4 ( V_8 , L_30 ) ;
if ( V_10 >= 0 )
V_10 = - V_81 ;
goto V_121;
}
V_116 . V_123 = F_22 ( 1 ) ;
V_10 = F_11 ( V_8 , ( T_1 * ) & V_116 , sizeof( V_116 ) ,
V_12 ) ;
if ( V_10 != sizeof( V_116 ) ) {
F_4 ( V_8 , L_31 ) ;
if ( V_10 >= 0 )
V_10 = - V_81 ;
goto V_121;
}
V_5 = F_46 ( sizeof( * V_5 ) , V_23 ) ;
if ( ! V_5 ) {
V_10 = - V_24 ;
goto V_121;
}
F_47 ( V_8 , ( void * ) V_5 ) ;
V_5 -> V_8 = V_8 ;
V_5 -> V_55 . V_124 = V_125 ;
V_5 -> V_55 . V_126 = V_127 ;
V_5 -> V_55 . V_128 = & V_129 ;
V_5 -> V_55 . V_60 = V_5 ;
V_5 -> V_55 . V_5 . V_130 = & V_8 -> V_5 ;
snprintf ( V_5 -> V_55 . V_103 , sizeof( V_5 -> V_55 . V_103 ) ,
L_32 , V_8 -> V_131 ) ;
F_48 ( & V_5 -> V_27 ) ;
F_49 ( V_8 ) ;
V_10 = F_50 ( & V_5 -> V_55 ) ;
F_51 ( V_8 ) ;
if ( V_10 ) {
F_4 ( V_8 , L_33 ) ;
goto V_132;
}
F_23 ( V_8 , L_34 ) ;
V_5 -> V_6 . V_133 = L_35 ;
V_5 -> V_6 . V_134 = F_1 ;
V_5 -> V_6 . V_135 = F_7 ;
V_5 -> V_6 . V_136 = F_5 ;
V_5 -> V_6 . V_137 = F_6 ;
V_5 -> V_6 . V_138 = - 1 ;
V_5 -> V_6 . V_139 = 8 ;
V_5 -> V_6 . V_140 = 1 ;
V_5 -> V_6 . V_5 = & V_8 -> V_5 ;
V_10 = F_52 ( & V_5 -> V_6 ) ;
if ( V_10 < 0 ) {
F_4 ( V_8 , L_36 ) ;
goto V_141;
}
V_10 = F_53 ( & V_8 -> V_5 . V_112 , & V_107 ) ;
if ( V_10 < 0 ) {
F_4 ( V_8 , L_37 ) ;
goto V_142;
}
F_37 ( V_8 ) ;
F_28 ( V_8 , V_83 ) ;
return V_10 ;
V_142:
if ( F_54 ( & V_5 -> V_6 ) < 0 )
F_4 ( V_8 , L_38 ) ;
V_141:
F_55 ( & V_5 -> V_55 ) ;
V_132:
F_10 ( V_5 ) ;
V_121:
F_28 ( V_8 , V_83 ) ;
V_119:
F_56 ( V_8 ) ;
V_118:
F_57 ( V_8 ) ;
return V_10 ;
}
static void F_58 ( struct V_7 * V_8 )
{
struct V_4 * V_5 = F_59 ( V_8 ) ;
F_60 ( & V_8 -> V_5 . V_112 , & V_107 ) ;
if ( F_54 ( & V_5 -> V_6 ) )
F_4 ( V_8 , L_39 ) ;
F_55 ( & V_5 -> V_55 ) ;
F_56 ( V_8 ) ;
F_57 ( V_8 ) ;
F_10 ( V_5 ) ;
}
static int F_61 ( struct V_7 * V_8 , struct V_143 * V_36 ,
T_1 * V_20 , int V_34 )
{
struct V_4 * V_5 = F_59 ( V_8 ) ;
struct V_144 * V_145 = ( void * ) V_20 ;
switch ( V_20 [ 0 ] ) {
case V_146 :
F_23 ( V_8 , L_40 ,
V_145 -> V_147 , V_145 -> V_148 ,
F_62 ( V_145 -> V_62 ) , F_62 ( V_145 -> V_38 ) ) ;
switch ( V_145 -> V_147 ) {
case V_149 :
V_5 -> V_33 = - V_150 ;
break;
case V_151 :
V_5 -> V_33 = - V_79 ;
break;
case V_152 :
V_5 -> V_33 = F_62 ( V_145 -> V_38 ) ;
break;
case V_153 :
switch ( V_145 -> V_148 ) {
case V_154 :
case V_155 :
V_5 -> V_33 = - V_30 ;
break;
default:
V_5 -> V_33 = - V_81 ;
break;
}
break;
default:
V_5 -> V_33 = - V_44 ;
break;
}
F_18 ( & V_5 -> V_32 , 1 ) ;
break;
case V_156 :
F_23 ( V_8 , L_41 , V_20 [ 1 ] , V_20 [ 2 ] ) ;
V_5 -> V_40 = V_20 [ 2 ] ;
if ( V_5 -> V_40 > sizeof( V_5 -> V_41 ) )
V_5 -> V_40 = sizeof( V_5 -> V_41 ) ;
memcpy ( V_5 -> V_41 , & V_20 [ 3 ] , V_5 -> V_40 ) ;
F_18 ( & V_5 -> V_39 , 1 ) ;
break;
default:
F_4 ( V_8 , L_42 ) ;
return 0 ;
}
F_63 ( & V_5 -> V_27 ) ;
return 1 ;
}
