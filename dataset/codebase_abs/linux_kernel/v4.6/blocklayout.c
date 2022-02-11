static T_1
F_1 ( struct V_1 * V_1 , const struct V_2 * V_3 ,
struct V_4 * args )
{
struct V_5 * V_6 = & args -> V_7 ;
struct V_8 * V_9 = V_1 -> V_10 ;
T_2 V_11 = ( 1 << V_1 -> V_12 ) ;
struct V_13 * V_14 ;
struct V_15 V_15 ;
T_2 V_16 = 0 ;
int error ;
if ( V_6 -> V_17 & ( V_11 - 1 ) ) {
F_2 ( L_1 ) ;
goto V_18;
}
error = - V_19 ;
V_14 = F_3 ( sizeof( * V_14 ) , V_20 ) ;
if ( ! V_14 )
goto V_21;
args -> V_22 = V_14 ;
error = V_9 -> V_23 -> V_24 ( V_1 , V_6 -> V_17 , V_6 -> V_25 ,
& V_15 , V_6 -> V_26 != V_27 ,
& V_16 ) ;
if ( error ) {
if ( error == - V_28 )
goto V_18;
goto V_21;
}
if ( V_15 . V_25 < args -> V_29 ) {
F_2 ( L_2 ) ;
goto V_18;
}
switch ( V_15 . type ) {
case V_30 :
if ( V_6 -> V_26 == V_27 )
V_14 -> V_31 = V_32 ;
else
V_14 -> V_31 = V_33 ;
V_14 -> V_34 = ( V_15 . V_35 << 9 ) ;
break;
case V_36 :
if ( V_6 -> V_26 & V_37 ) {
if ( args -> V_29 == 0 ) {
F_2 ( L_3 ) ;
goto V_18;
}
V_14 -> V_31 = V_38 ;
V_14 -> V_34 = ( V_15 . V_35 << 9 ) ;
break;
}
case V_39 :
if ( V_6 -> V_26 == V_27 ) {
V_14 -> V_31 = V_40 ;
break;
}
case V_41 :
default:
F_4 ( 1 , L_4 , V_15 . type ) ;
goto V_18;
}
error = F_5 ( & V_14 -> V_42 , V_3 , V_16 ) ;
if ( error )
goto V_21;
V_14 -> V_43 = V_15 . V_17 ;
V_14 -> V_44 = V_15 . V_25 ;
V_6 -> V_17 = V_15 . V_17 ;
V_6 -> V_25 = V_15 . V_25 ;
F_2 ( L_5 , V_14 -> V_43 , V_14 -> V_44 , V_14 -> V_31 ) ;
return 0 ;
V_21:
V_6 -> V_25 = 0 ;
return F_6 ( error ) ;
V_18:
V_6 -> V_25 = 0 ;
return V_45 ;
}
static T_1
F_7 ( struct V_1 * V_1 , struct V_46 * V_47 ,
struct V_15 * V_48 , int V_49 )
{
T_3 V_50 = V_47 -> V_51 + 1 ;
struct V_52 V_52 = { . V_53 = 0 } ;
int error ;
if ( V_47 -> V_54 . V_55 == V_56 ||
F_8 ( & V_47 -> V_54 , & V_1 -> V_57 ) < 0 )
V_47 -> V_54 = F_9 ( V_1 -> V_10 ) ;
V_52 . V_53 |= V_58 | V_59 | V_60 ;
V_52 . V_61 = V_52 . V_62 = V_52 . V_63 = V_47 -> V_54 ;
if ( V_50 > F_10 ( V_1 ) ) {
V_52 . V_53 |= V_64 ;
V_52 . V_65 = V_50 ;
}
error = V_1 -> V_10 -> V_23 -> V_66 ( V_1 , V_48 ,
V_49 , & V_52 ) ;
F_11 ( V_48 ) ;
return F_6 ( error ) ;
}
static int
F_12 ( struct V_8 * V_9 ,
struct V_67 * V_68 )
{
struct V_69 * V_70 ;
struct V_71 * V_72 ;
V_70 = F_3 ( sizeof( struct V_69 ) +
sizeof( struct V_71 ) , V_20 ) ;
if ( ! V_70 )
return - V_19 ;
V_68 -> V_73 = V_70 ;
V_70 -> V_74 = 1 ;
V_72 = & V_70 -> V_75 [ 0 ] ;
V_72 -> type = V_76 ;
V_72 -> V_77 . V_78 = V_79 ;
return V_9 -> V_23 -> V_80 ( V_9 , V_72 -> V_77 . V_81 , & V_72 -> V_77 . V_78 ,
& V_72 -> V_77 . V_17 ) ;
}
static T_1
F_13 ( struct V_8 * V_9 ,
struct V_82 * V_83 ,
struct V_67 * V_68 )
{
if ( V_9 -> V_84 != V_9 -> V_84 -> V_85 )
return V_86 ;
return F_6 ( F_12 ( V_9 , V_68 ) ) ;
}
static T_1
F_14 ( struct V_1 * V_1 ,
struct V_46 * V_47 )
{
struct V_15 * V_48 ;
int V_49 ;
V_49 = F_15 ( V_47 -> V_87 ,
V_47 -> V_88 , & V_48 , 1 << V_1 -> V_12 ) ;
if ( V_49 < 0 )
return F_6 ( V_49 ) ;
return F_7 ( V_1 , V_47 , V_48 , V_49 ) ;
}
static int F_16 ( struct V_89 * V_90 ,
struct V_71 * V_72 )
{
struct V_91 * V_92 = V_90 -> V_93 -> V_94 ;
struct V_95 * V_96 ;
T_4 V_97 = 252 , V_44 , V_98 ;
T_5 * V_99 , * V_100 , type , V_101 ;
int error ;
V_99 = F_3 ( V_97 , V_20 ) ;
if ( ! V_99 )
return - V_19 ;
V_96 = F_17 ( V_92 , V_102 , V_20 ) ;
if ( F_18 ( V_96 ) ) {
error = - V_19 ;
goto V_103;
}
F_19 ( V_96 ) ;
error = F_20 ( V_92 , V_96 , V_99 , V_97 , V_20 ) ;
if ( error )
goto V_104;
V_96 -> V_105 [ 0 ] = V_106 ;
V_96 -> V_105 [ 1 ] = 1 ;
V_96 -> V_105 [ 2 ] = 0x83 ;
V_96 -> V_105 [ 3 ] = V_97 >> 8 ;
V_96 -> V_105 [ 4 ] = V_97 & 0xff ;
V_96 -> V_107 = F_21 ( V_106 ) ;
error = F_22 ( V_96 -> V_92 , NULL , V_96 , 1 ) ;
if ( error ) {
F_23 ( L_6 ,
V_96 -> V_108 ) ;
goto V_104;
}
V_44 = ( V_99 [ 2 ] << 8 ) + V_99 [ 3 ] + 4 ;
if ( V_44 > V_97 ) {
F_23 ( L_7 ,
V_44 ) ;
goto V_104;
}
V_100 = V_99 + 4 ;
for ( V_100 = V_99 + 4 ; V_100 < V_99 + V_44 ; V_100 += V_98 + 4 ) {
V_98 = V_100 [ 3 ] ;
type = V_100 [ 1 ] & 0xf ;
V_101 = ( V_100 [ 1 ] >> 4 ) & 0x3 ;
if ( V_101 != 0x00 )
continue;
if ( type != 0x02 && type != 0x03 )
continue;
if ( V_98 != 8 && V_98 != 12 && V_98 != 16 )
continue;
V_72 -> V_109 . V_110 = V_111 ;
V_72 -> V_109 . V_112 = type == 0x02 ?
V_113 : V_114 ;
V_72 -> V_109 . V_115 = V_98 ;
memcpy ( V_72 -> V_109 . V_116 , V_100 + 4 , V_98 ) ;
if ( V_98 == 16 )
break;
}
V_104:
F_24 ( V_96 ) ;
V_103:
F_11 ( V_99 ) ;
return error ;
}
static T_6 F_25 ( struct V_82 * V_83 )
{
return ( ( T_6 ) V_83 -> V_117 . V_118 << 32 ) | V_83 -> V_117 . V_119 ;
}
static int
F_26 ( struct V_8 * V_9 ,
struct V_82 * V_83 ,
struct V_67 * V_68 )
{
struct V_69 * V_70 ;
struct V_71 * V_72 ;
const struct V_120 * V_121 ;
int error ;
V_70 = F_3 ( sizeof( struct V_69 ) +
sizeof( struct V_71 ) , V_20 ) ;
if ( ! V_70 )
return - V_19 ;
V_68 -> V_73 = V_70 ;
V_70 -> V_74 = 1 ;
V_72 = & V_70 -> V_75 [ 0 ] ;
V_72 -> type = V_122 ;
V_72 -> V_109 . V_123 = F_25 ( V_83 ) ;
error = F_16 ( V_9 -> V_84 , V_72 ) ;
if ( error )
return error ;
V_121 = V_9 -> V_84 -> V_93 -> V_124 -> V_120 ;
if ( ! V_121 ) {
F_23 ( L_8 ,
V_9 -> V_125 ) ;
return - V_126 ;
}
error = V_121 -> V_127 ( V_9 -> V_84 , 0 , V_128 , true ) ;
if ( error ) {
F_23 ( L_9 ,
V_9 -> V_125 ) ;
return - V_126 ;
}
error = V_121 -> V_129 ( V_9 -> V_84 , V_128 ,
V_130 , 0 ) ;
if ( error ) {
F_23 ( L_10 ,
V_9 -> V_125 ) ;
return - V_126 ;
}
return 0 ;
}
static T_1
F_27 ( struct V_8 * V_9 ,
struct V_82 * V_83 ,
struct V_67 * V_68 )
{
if ( V_9 -> V_84 != V_9 -> V_84 -> V_85 )
return V_86 ;
return F_6 ( F_26 ( V_9 , V_83 , V_68 ) ) ;
}
static T_1
F_28 ( struct V_1 * V_1 ,
struct V_46 * V_47 )
{
struct V_15 * V_48 ;
int V_49 ;
V_49 = F_29 ( V_47 -> V_87 ,
V_47 -> V_88 , & V_48 , 1 << V_1 -> V_12 ) ;
if ( V_49 < 0 )
return F_6 ( V_49 ) ;
return F_7 ( V_1 , V_47 , V_48 , V_49 ) ;
}
static void
F_30 ( struct V_131 * V_132 )
{
struct V_82 * V_83 = V_132 -> V_133 . V_134 ;
struct V_89 * V_90 = V_132 -> V_135 -> V_136 . V_137 -> V_138 -> V_84 ;
V_90 -> V_93 -> V_124 -> V_120 -> V_139 ( V_90 , V_128 ,
F_25 ( V_83 ) , 0 , true ) ;
}
