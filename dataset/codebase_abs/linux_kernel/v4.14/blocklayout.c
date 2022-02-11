static T_1
F_1 ( struct V_1 * V_1 , const struct V_2 * V_3 ,
struct V_4 * args )
{
struct V_5 * V_6 = & args -> V_7 ;
struct V_8 * V_9 = V_1 -> V_10 ;
T_2 V_11 = F_2 ( V_1 ) ;
struct V_12 * V_13 ;
struct V_14 V_14 ;
T_2 V_15 = 0 ;
int error ;
if ( V_6 -> V_16 & ( V_11 - 1 ) ) {
F_3 ( L_1 ) ;
goto V_17;
}
error = - V_18 ;
V_13 = F_4 ( sizeof( * V_13 ) , V_19 ) ;
if ( ! V_13 )
goto V_20;
args -> V_21 = V_13 ;
error = V_9 -> V_22 -> V_23 ( V_1 , V_6 -> V_16 , V_6 -> V_24 ,
& V_14 , V_6 -> V_25 != V_26 ,
& V_15 ) ;
if ( error ) {
if ( error == - V_27 )
goto V_17;
goto V_20;
}
if ( V_14 . V_24 < args -> V_28 ) {
F_3 ( L_2 ) ;
goto V_17;
}
switch ( V_14 . type ) {
case V_29 :
if ( V_6 -> V_25 == V_26 )
V_13 -> V_30 = V_31 ;
else
V_13 -> V_30 = V_32 ;
V_13 -> V_33 = ( V_14 . V_34 << 9 ) ;
break;
case V_35 :
if ( V_6 -> V_25 & V_36 ) {
if ( args -> V_28 == 0 ) {
F_3 ( L_3 ) ;
goto V_17;
}
V_13 -> V_30 = V_37 ;
V_13 -> V_33 = ( V_14 . V_34 << 9 ) ;
break;
}
case V_38 :
if ( V_6 -> V_25 == V_26 ) {
V_13 -> V_30 = V_39 ;
break;
}
case V_40 :
default:
F_5 ( 1 , L_4 , V_14 . type ) ;
goto V_17;
}
error = F_6 ( & V_13 -> V_41 , V_3 , V_15 ) ;
if ( error )
goto V_20;
V_13 -> V_42 = V_14 . V_16 ;
V_13 -> V_43 = V_14 . V_24 ;
V_6 -> V_16 = V_14 . V_16 ;
V_6 -> V_24 = V_14 . V_24 ;
F_3 ( L_5 , V_13 -> V_42 , V_13 -> V_43 , V_13 -> V_30 ) ;
return 0 ;
V_20:
V_6 -> V_24 = 0 ;
return F_7 ( error ) ;
V_17:
V_6 -> V_24 = 0 ;
return V_44 ;
}
static T_1
F_8 ( struct V_1 * V_1 , struct V_45 * V_46 ,
struct V_14 * V_47 , int V_48 )
{
T_3 V_49 = V_46 -> V_50 + 1 ;
struct V_51 V_51 = { . V_52 = 0 } ;
int error ;
if ( V_46 -> V_53 . V_54 == V_55 ||
F_9 ( & V_46 -> V_53 , & V_1 -> V_56 ) < 0 )
V_46 -> V_53 = F_10 ( V_1 ) ;
V_51 . V_52 |= V_57 | V_58 | V_59 ;
V_51 . V_60 = V_51 . V_61 = V_51 . V_62 = V_46 -> V_53 ;
if ( V_49 > F_11 ( V_1 ) ) {
V_51 . V_52 |= V_63 ;
V_51 . V_64 = V_49 ;
}
error = V_1 -> V_10 -> V_22 -> V_65 ( V_1 , V_47 ,
V_48 , & V_51 ) ;
F_12 ( V_47 ) ;
return F_7 ( error ) ;
}
static int
F_13 ( struct V_8 * V_9 ,
struct V_66 * V_67 )
{
struct V_68 * V_69 ;
struct V_70 * V_71 ;
V_69 = F_4 ( sizeof( struct V_68 ) +
sizeof( struct V_70 ) , V_19 ) ;
if ( ! V_69 )
return - V_18 ;
V_67 -> V_72 = V_69 ;
V_69 -> V_73 = 1 ;
V_71 = & V_69 -> V_74 [ 0 ] ;
V_71 -> type = V_75 ;
V_71 -> V_76 . V_77 = V_78 ;
return V_9 -> V_22 -> V_79 ( V_9 , V_71 -> V_76 . V_80 , & V_71 -> V_76 . V_77 ,
& V_71 -> V_76 . V_16 ) ;
}
static T_1
F_14 ( struct V_8 * V_9 ,
struct V_81 * V_82 ,
struct V_83 * V_84 ,
struct V_66 * V_67 )
{
if ( V_9 -> V_85 != V_9 -> V_85 -> V_86 )
return V_87 ;
return F_7 ( F_13 ( V_9 , V_67 ) ) ;
}
static T_1
F_15 ( struct V_1 * V_1 ,
struct V_45 * V_46 )
{
struct V_14 * V_47 ;
int V_48 ;
V_48 = F_16 ( V_46 -> V_88 ,
V_46 -> V_89 , & V_47 , F_2 ( V_1 ) ) ;
if ( V_48 < 0 )
return F_7 ( V_48 ) ;
return F_8 ( V_1 , V_46 , V_47 , V_48 ) ;
}
static int F_17 ( struct V_90 * V_91 ,
struct V_70 * V_71 )
{
struct V_92 * V_93 = V_91 -> V_94 -> V_95 ;
struct V_96 * V_97 ;
struct V_98 * V_99 ;
T_4 V_100 = 252 , V_43 , V_101 ;
T_5 * V_102 , * V_103 , type , V_104 ;
int error ;
if ( F_18 ( ! F_19 ( V_93 ) ) )
return - V_105 ;
V_102 = F_4 ( V_100 , V_19 ) ;
if ( ! V_102 )
return - V_18 ;
V_97 = F_20 ( V_93 , V_106 , V_19 ) ;
if ( F_21 ( V_97 ) ) {
error = - V_18 ;
goto V_107;
}
V_99 = F_22 ( V_97 ) ;
error = F_23 ( V_93 , V_97 , V_102 , V_100 , V_19 ) ;
if ( error )
goto V_108;
V_99 -> V_109 [ 0 ] = V_110 ;
V_99 -> V_109 [ 1 ] = 1 ;
V_99 -> V_109 [ 2 ] = 0x83 ;
V_99 -> V_109 [ 3 ] = V_100 >> 8 ;
V_99 -> V_109 [ 4 ] = V_100 & 0xff ;
V_99 -> V_111 = F_24 ( V_110 ) ;
F_25 ( V_97 -> V_93 , NULL , V_97 , 1 ) ;
if ( V_99 -> V_112 ) {
F_26 ( L_6 ,
V_99 -> V_112 ) ;
error = - V_113 ;
goto V_108;
}
V_43 = ( V_102 [ 2 ] << 8 ) + V_102 [ 3 ] + 4 ;
if ( V_43 > V_100 ) {
F_26 ( L_7 ,
V_43 ) ;
goto V_108;
}
V_103 = V_102 + 4 ;
for ( V_103 = V_102 + 4 ; V_103 < V_102 + V_43 ; V_103 += V_101 + 4 ) {
V_101 = V_103 [ 3 ] ;
type = V_103 [ 1 ] & 0xf ;
V_104 = ( V_103 [ 1 ] >> 4 ) & 0x3 ;
if ( V_104 != 0x00 )
continue;
if ( type != 0x02 && type != 0x03 )
continue;
if ( V_101 != 8 && V_101 != 12 && V_101 != 16 )
continue;
V_71 -> V_114 . V_115 = V_116 ;
V_71 -> V_114 . V_117 = type == 0x02 ?
V_118 : V_119 ;
V_71 -> V_114 . V_120 = V_101 ;
memcpy ( V_71 -> V_114 . V_121 , V_103 + 4 , V_101 ) ;
if ( V_101 == 16 )
break;
}
V_108:
F_27 ( V_97 ) ;
V_107:
F_12 ( V_102 ) ;
return error ;
}
static T_6 F_28 ( struct V_83 * V_84 )
{
return ( ( T_6 ) V_84 -> V_122 . V_123 << 32 ) | V_84 -> V_122 . V_124 ;
}
static int
F_29 ( struct V_8 * V_9 ,
struct V_83 * V_84 ,
struct V_66 * V_67 )
{
struct V_68 * V_69 ;
struct V_70 * V_71 ;
const struct V_125 * V_126 ;
int error ;
V_69 = F_4 ( sizeof( struct V_68 ) +
sizeof( struct V_70 ) , V_19 ) ;
if ( ! V_69 )
return - V_18 ;
V_67 -> V_72 = V_69 ;
V_69 -> V_73 = 1 ;
V_71 = & V_69 -> V_74 [ 0 ] ;
V_71 -> type = V_127 ;
V_71 -> V_114 . V_128 = F_28 ( V_84 ) ;
error = F_17 ( V_9 -> V_85 , V_71 ) ;
if ( error )
return error ;
V_126 = V_9 -> V_85 -> V_94 -> V_129 -> V_125 ;
if ( ! V_126 ) {
F_26 ( L_8 ,
V_9 -> V_130 ) ;
return - V_105 ;
}
error = V_126 -> V_131 ( V_9 -> V_85 , 0 , V_132 , true ) ;
if ( error ) {
F_26 ( L_9 ,
V_9 -> V_130 ) ;
return - V_105 ;
}
error = V_126 -> V_133 ( V_9 -> V_85 , V_132 ,
V_134 , 0 ) ;
if ( error ) {
F_26 ( L_10 ,
V_9 -> V_130 ) ;
return - V_105 ;
}
return 0 ;
}
static T_1
F_30 ( struct V_8 * V_9 ,
struct V_81 * V_82 ,
struct V_83 * V_84 ,
struct V_66 * V_67 )
{
if ( V_9 -> V_85 != V_9 -> V_85 -> V_86 )
return V_87 ;
return F_7 ( F_29 ( V_9 , V_84 , V_67 ) ) ;
}
static T_1
F_31 ( struct V_1 * V_1 ,
struct V_45 * V_46 )
{
struct V_14 * V_47 ;
int V_48 ;
V_48 = F_32 ( V_46 -> V_88 ,
V_46 -> V_89 , & V_47 , F_2 ( V_1 ) ) ;
if ( V_48 < 0 )
return F_7 ( V_48 ) ;
return F_8 ( V_1 , V_46 , V_47 , V_48 ) ;
}
static void
F_33 ( struct V_135 * V_136 )
{
struct V_83 * V_84 = V_136 -> V_137 . V_138 ;
struct V_90 * V_91 = V_136 -> V_139 -> V_140 . V_141 -> V_142 -> V_85 ;
V_91 -> V_94 -> V_129 -> V_125 -> V_143 ( V_91 , V_132 ,
F_28 ( V_84 ) , 0 , true ) ;
}
