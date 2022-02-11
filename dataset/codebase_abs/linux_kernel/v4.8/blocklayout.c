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
struct V_84 * V_85 ,
struct V_67 * V_68 )
{
if ( V_9 -> V_86 != V_9 -> V_86 -> V_87 )
return V_88 ;
return F_6 ( F_12 ( V_9 , V_68 ) ) ;
}
static T_1
F_14 ( struct V_1 * V_1 ,
struct V_46 * V_47 )
{
struct V_15 * V_48 ;
int V_49 ;
V_49 = F_15 ( V_47 -> V_89 ,
V_47 -> V_90 , & V_48 , 1 << V_1 -> V_12 ) ;
if ( V_49 < 0 )
return F_6 ( V_49 ) ;
return F_7 ( V_1 , V_47 , V_48 , V_49 ) ;
}
static int F_16 ( struct V_91 * V_92 ,
struct V_71 * V_72 )
{
struct V_93 * V_94 = V_92 -> V_95 -> V_96 ;
struct V_97 * V_98 ;
T_4 V_99 = 252 , V_44 , V_100 ;
T_5 * V_101 , * V_102 , type , V_103 ;
int error ;
V_101 = F_3 ( V_99 , V_20 ) ;
if ( ! V_101 )
return - V_19 ;
V_98 = F_17 ( V_94 , V_104 , V_20 ) ;
if ( F_18 ( V_98 ) ) {
error = - V_19 ;
goto V_105;
}
F_19 ( V_98 ) ;
error = F_20 ( V_94 , V_98 , V_101 , V_99 , V_20 ) ;
if ( error )
goto V_106;
V_98 -> V_107 [ 0 ] = V_108 ;
V_98 -> V_107 [ 1 ] = 1 ;
V_98 -> V_107 [ 2 ] = 0x83 ;
V_98 -> V_107 [ 3 ] = V_99 >> 8 ;
V_98 -> V_107 [ 4 ] = V_99 & 0xff ;
V_98 -> V_109 = F_21 ( V_108 ) ;
error = F_22 ( V_98 -> V_94 , NULL , V_98 , 1 ) ;
if ( error ) {
F_23 ( L_6 ,
V_98 -> V_110 ) ;
goto V_106;
}
V_44 = ( V_101 [ 2 ] << 8 ) + V_101 [ 3 ] + 4 ;
if ( V_44 > V_99 ) {
F_23 ( L_7 ,
V_44 ) ;
goto V_106;
}
V_102 = V_101 + 4 ;
for ( V_102 = V_101 + 4 ; V_102 < V_101 + V_44 ; V_102 += V_100 + 4 ) {
V_100 = V_102 [ 3 ] ;
type = V_102 [ 1 ] & 0xf ;
V_103 = ( V_102 [ 1 ] >> 4 ) & 0x3 ;
if ( V_103 != 0x00 )
continue;
if ( type != 0x02 && type != 0x03 )
continue;
if ( V_100 != 8 && V_100 != 12 && V_100 != 16 )
continue;
V_72 -> V_111 . V_112 = V_113 ;
V_72 -> V_111 . V_114 = type == 0x02 ?
V_115 : V_116 ;
V_72 -> V_111 . V_117 = V_100 ;
memcpy ( V_72 -> V_111 . V_118 , V_102 + 4 , V_100 ) ;
if ( V_100 == 16 )
break;
}
V_106:
F_24 ( V_98 ) ;
V_105:
F_11 ( V_101 ) ;
return error ;
}
static T_6 F_25 ( struct V_84 * V_85 )
{
return ( ( T_6 ) V_85 -> V_119 . V_120 << 32 ) | V_85 -> V_119 . V_121 ;
}
static int
F_26 ( struct V_8 * V_9 ,
struct V_84 * V_85 ,
struct V_67 * V_68 )
{
struct V_69 * V_70 ;
struct V_71 * V_72 ;
const struct V_122 * V_123 ;
int error ;
V_70 = F_3 ( sizeof( struct V_69 ) +
sizeof( struct V_71 ) , V_20 ) ;
if ( ! V_70 )
return - V_19 ;
V_68 -> V_73 = V_70 ;
V_70 -> V_74 = 1 ;
V_72 = & V_70 -> V_75 [ 0 ] ;
V_72 -> type = V_124 ;
V_72 -> V_111 . V_125 = F_25 ( V_85 ) ;
error = F_16 ( V_9 -> V_86 , V_72 ) ;
if ( error )
return error ;
V_123 = V_9 -> V_86 -> V_95 -> V_126 -> V_122 ;
if ( ! V_123 ) {
F_23 ( L_8 ,
V_9 -> V_127 ) ;
return - V_128 ;
}
error = V_123 -> V_129 ( V_9 -> V_86 , 0 , V_130 , true ) ;
if ( error ) {
F_23 ( L_9 ,
V_9 -> V_127 ) ;
return - V_128 ;
}
error = V_123 -> V_131 ( V_9 -> V_86 , V_130 ,
V_132 , 0 ) ;
if ( error ) {
F_23 ( L_10 ,
V_9 -> V_127 ) ;
return - V_128 ;
}
return 0 ;
}
static T_1
F_27 ( struct V_8 * V_9 ,
struct V_82 * V_83 ,
struct V_84 * V_85 ,
struct V_67 * V_68 )
{
if ( V_9 -> V_86 != V_9 -> V_86 -> V_87 )
return V_88 ;
return F_6 ( F_26 ( V_9 , V_85 , V_68 ) ) ;
}
static T_1
F_28 ( struct V_1 * V_1 ,
struct V_46 * V_47 )
{
struct V_15 * V_48 ;
int V_49 ;
V_49 = F_29 ( V_47 -> V_89 ,
V_47 -> V_90 , & V_48 , 1 << V_1 -> V_12 ) ;
if ( V_49 < 0 )
return F_6 ( V_49 ) ;
return F_7 ( V_1 , V_47 , V_48 , V_49 ) ;
}
static void
F_30 ( struct V_133 * V_134 )
{
struct V_84 * V_85 = V_134 -> V_135 . V_136 ;
struct V_91 * V_92 = V_134 -> V_137 -> V_138 . V_139 -> V_140 -> V_86 ;
V_92 -> V_95 -> V_126 -> V_122 -> V_141 ( V_92 , V_130 ,
F_25 ( V_85 ) , 0 , true ) ;
}
