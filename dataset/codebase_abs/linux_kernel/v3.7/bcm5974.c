static const struct V_1 * F_1 ( struct V_2 * V_3 )
{
T_1 V_4 = F_2 ( V_3 -> V_5 . V_6 ) ;
const struct V_1 * V_7 ;
for ( V_7 = V_8 ; V_7 -> V_9 ; ++ V_7 )
if ( V_7 -> V_9 == V_4 || V_7 -> V_10 == V_4 || V_7 -> V_11 == V_4 )
return V_7 ;
return V_8 ;
}
static inline int F_3 ( T_2 V_12 )
{
return ( signed short ) F_2 ( V_12 ) ;
}
static void F_4 ( struct V_13 * V_14 , unsigned int V_15 ,
const struct V_16 * V_17 )
{
int V_18 = V_17 -> V_19 ? ( V_17 -> V_20 - V_17 -> V_21 ) / V_17 -> V_19 : 0 ;
F_5 ( V_14 , V_15 , V_17 -> V_21 , V_17 -> V_20 , V_18 , 0 ) ;
}
static void F_6 ( struct V_13 * V_13 ,
const struct V_1 * V_7 )
{
F_7 ( V_22 , V_13 -> V_23 ) ;
F_5 ( V_13 , V_24 , 0 , 256 , 5 , 0 ) ;
F_5 ( V_13 , V_25 , 0 , 16 , 0 , 0 ) ;
F_4 ( V_13 , V_26 , & V_7 -> V_27 ) ;
F_4 ( V_13 , V_28 , & V_7 -> V_27 ) ;
F_4 ( V_13 , V_29 , & V_7 -> V_27 ) ;
F_4 ( V_13 , V_30 , & V_7 -> V_27 ) ;
F_4 ( V_13 , V_31 , & V_7 -> V_32 ) ;
F_4 ( V_13 , V_33 , & V_7 -> V_12 ) ;
F_4 ( V_13 , V_34 , & V_7 -> V_35 ) ;
F_7 ( V_36 , V_13 -> V_23 ) ;
F_7 ( V_37 , V_13 -> V_38 ) ;
if ( V_7 -> V_39 & V_40 )
F_7 ( V_41 , V_13 -> V_42 ) ;
F_8 ( V_13 , V_43 ,
V_44 | V_45 | V_46 ) ;
}
static int F_9 ( struct V_47 * V_48 , int V_49 )
{
if ( V_49 != sizeof( struct V_50 ) )
return - V_51 ;
F_10 ( 7 ,
L_1 ,
V_48 -> V_50 -> V_52 , V_48 -> V_50 -> V_53 ,
V_48 -> V_50 -> V_54 , V_48 -> V_50 -> V_55 ) ;
F_11 ( V_48 -> V_14 , V_37 , V_48 -> V_50 -> V_53 ) ;
F_12 ( V_48 -> V_14 ) ;
return 0 ;
}
static void F_13 ( struct V_13 * V_14 , int V_56 ,
const struct V_57 * V_58 ,
const struct V_59 * V_60 )
{
F_14 ( V_14 , V_56 ) ;
F_15 ( V_14 , V_61 , true ) ;
F_16 ( V_14 , V_26 ,
F_3 ( V_60 -> V_62 ) << 1 ) ;
F_16 ( V_14 , V_28 ,
F_3 ( V_60 -> V_63 ) << 1 ) ;
F_16 ( V_14 , V_29 ,
F_3 ( V_60 -> V_64 ) << 1 ) ;
F_16 ( V_14 , V_30 ,
F_3 ( V_60 -> V_65 ) << 1 ) ;
F_16 ( V_14 , V_31 ,
V_66 - F_3 ( V_60 -> V_67 ) ) ;
F_16 ( V_14 , V_33 , V_58 -> V_12 ) ;
F_16 ( V_14 , V_34 , V_58 -> V_35 ) ;
}
static void F_17 ( struct V_13 * V_14 ,
const struct V_1 * V_7 ,
const struct V_59 * V_60 , int V_68 )
{
int V_69 = 0 , V_70 = 0 ;
if ( V_68 ) {
int V_17 = F_3 ( V_60 -> V_62 ) ;
int V_27 = F_3 ( V_60 -> V_64 ) ;
if ( V_17 > 0 && F_3 ( V_60 -> V_71 ) ) {
V_69 = F_18 ( 256 * V_17 / V_7 -> V_17 . V_20 , 0 , 255 ) ;
V_70 = F_18 ( 16 * V_27 / V_7 -> V_27 . V_20 , 0 , 15 ) ;
}
}
F_16 ( V_14 , V_24 , V_69 ) ;
F_16 ( V_14 , V_25 , V_70 ) ;
}
static int F_19 ( struct V_47 * V_48 , int V_49 )
{
const struct V_1 * V_72 = & V_48 -> V_7 ;
const struct V_59 * V_60 ;
struct V_13 * V_14 = V_48 -> V_14 ;
int V_68 , V_73 , V_74 = 0 ;
if ( V_49 < V_72 -> V_75 || ( V_49 - V_72 -> V_75 ) % V_76 != 0 )
return - V_51 ;
V_60 = ( const struct V_59 * ) ( V_48 -> V_77 + V_72 -> V_75 ) ;
V_68 = ( V_49 - V_72 -> V_75 ) / V_76 ;
for ( V_73 = 0 ; V_73 < V_68 ; V_73 ++ ) {
if ( F_3 ( V_60 [ V_73 ] . V_62 ) == 0 )
continue;
V_48 -> V_58 [ V_74 ] . V_12 = F_3 ( V_60 [ V_73 ] . V_78 ) ;
V_48 -> V_58 [ V_74 ] . V_35 = V_72 -> V_35 . V_21 + V_72 -> V_35 . V_20 - F_3 ( V_60 [ V_73 ] . V_79 ) ;
V_48 -> V_80 [ V_74 ++ ] = & V_60 [ V_73 ] ;
}
F_20 ( V_14 , V_48 -> V_81 , V_48 -> V_58 , V_74 ) ;
for ( V_73 = 0 ; V_73 < V_74 ; V_73 ++ )
F_13 ( V_14 , V_48 -> V_81 [ V_73 ] ,
& V_48 -> V_58 [ V_73 ] , V_48 -> V_80 [ V_73 ] ) ;
F_21 ( V_14 ) ;
F_17 ( V_14 , V_72 , V_60 , V_68 ) ;
if ( V_72 -> V_82 == V_83 ) {
int V_84 = F_3 ( V_48 -> V_77 [ V_85 ] ) ;
F_11 ( V_14 , V_37 , V_84 ) ;
}
F_12 ( V_14 ) ;
return 0 ;
}
static int F_22 ( struct V_47 * V_48 , bool V_86 )
{
char * V_87 = F_23 ( 8 , V_88 ) ;
int V_89 = 0 , V_49 ;
if ( ! V_87 ) {
F_24 ( & V_48 -> V_90 -> V_48 , L_2 ) ;
V_89 = - V_91 ;
goto V_92;
}
V_49 = F_25 ( V_48 -> V_3 , F_26 ( V_48 -> V_3 , 0 ) ,
V_93 ,
V_94 | V_95 | V_96 ,
V_97 ,
V_98 , V_87 , 8 , 5000 ) ;
if ( V_49 != 8 ) {
F_24 ( & V_48 -> V_90 -> V_48 , L_3 ) ;
V_89 = - V_51 ;
goto V_92;
}
V_87 [ 0 ] = V_86 ?
V_99 :
V_100 ;
V_49 = F_25 ( V_48 -> V_3 , F_27 ( V_48 -> V_3 , 0 ) ,
V_101 ,
V_102 | V_95 | V_96 ,
V_97 ,
V_98 , V_87 , 8 , 5000 ) ;
if ( V_49 != 8 ) {
F_24 ( & V_48 -> V_90 -> V_48 , L_4 ) ;
V_89 = - V_51 ;
goto V_92;
}
F_10 ( 2 , L_5 ,
V_86 ? L_6 : L_7 ) ;
V_92:
F_28 ( V_87 ) ;
return V_89 ;
}
static void F_29 ( struct V_103 * V_103 )
{
struct V_47 * V_48 = V_103 -> V_104 ;
struct V_105 * V_90 = V_48 -> V_90 ;
int error ;
switch ( V_103 -> V_106 ) {
case 0 :
break;
case - V_107 :
case - V_108 :
case - V_109 :
case - V_110 :
F_30 ( & V_90 -> V_48 , L_8 ,
V_103 -> V_106 ) ;
return;
default:
F_30 ( & V_90 -> V_48 , L_9 , V_103 -> V_106 ) ;
goto exit;
}
if ( F_9 ( V_48 , V_48 -> V_111 -> V_112 ) )
F_10 ( 1 , L_10 ,
V_48 -> V_111 -> V_112 ) ;
exit:
error = F_31 ( V_48 -> V_111 , V_113 ) ;
if ( error )
F_24 ( & V_90 -> V_48 , L_11 , error ) ;
}
static void F_32 ( struct V_103 * V_103 )
{
struct V_47 * V_48 = V_103 -> V_104 ;
struct V_105 * V_90 = V_48 -> V_90 ;
int error ;
switch ( V_103 -> V_106 ) {
case 0 :
break;
case - V_107 :
case - V_108 :
case - V_109 :
case - V_110 :
F_30 ( & V_90 -> V_48 , L_12 ,
V_103 -> V_106 ) ;
return;
default:
F_30 ( & V_90 -> V_48 , L_13 , V_103 -> V_106 ) ;
goto exit;
}
if ( V_48 -> V_114 -> V_112 == 2 )
goto exit;
if ( F_19 ( V_48 , V_48 -> V_114 -> V_112 ) )
F_10 ( 1 , L_14 ,
V_48 -> V_114 -> V_112 ) ;
exit:
error = F_31 ( V_48 -> V_114 , V_113 ) ;
if ( error )
F_24 ( & V_90 -> V_48 , L_15 , error ) ;
}
static int F_33 ( struct V_47 * V_48 )
{
int error ;
error = F_22 ( V_48 , true ) ;
if ( error ) {
F_10 ( 1 , L_16 ) ;
goto V_115;
}
if ( V_48 -> V_111 ) {
error = F_31 ( V_48 -> V_111 , V_88 ) ;
if ( error )
goto V_116;
}
error = F_31 ( V_48 -> V_114 , V_88 ) ;
if ( error )
goto V_117;
return 0 ;
V_117:
F_34 ( V_48 -> V_111 ) ;
V_116:
F_22 ( V_48 , false ) ;
V_115:
return error ;
}
static void F_35 ( struct V_47 * V_48 )
{
F_34 ( V_48 -> V_114 ) ;
F_34 ( V_48 -> V_111 ) ;
F_22 ( V_48 , false ) ;
}
static int F_36 ( struct V_13 * V_14 )
{
struct V_47 * V_48 = F_37 ( V_14 ) ;
int error ;
error = F_38 ( V_48 -> V_90 ) ;
if ( error )
return error ;
F_39 ( & V_48 -> V_118 ) ;
error = F_33 ( V_48 ) ;
if ( ! error )
V_48 -> V_119 = 1 ;
F_40 ( & V_48 -> V_118 ) ;
if ( error )
F_41 ( V_48 -> V_90 ) ;
return error ;
}
static void F_42 ( struct V_13 * V_14 )
{
struct V_47 * V_48 = F_37 ( V_14 ) ;
F_39 ( & V_48 -> V_118 ) ;
F_35 ( V_48 ) ;
V_48 -> V_119 = 0 ;
F_40 ( & V_48 -> V_118 ) ;
F_41 ( V_48 -> V_90 ) ;
}
static int F_43 ( struct V_105 * V_120 , T_3 V_121 )
{
struct V_47 * V_48 = F_44 ( V_120 ) ;
F_39 ( & V_48 -> V_118 ) ;
if ( V_48 -> V_119 )
F_35 ( V_48 ) ;
F_40 ( & V_48 -> V_118 ) ;
return 0 ;
}
static int F_45 ( struct V_105 * V_120 )
{
struct V_47 * V_48 = F_44 ( V_120 ) ;
int error = 0 ;
F_39 ( & V_48 -> V_118 ) ;
if ( V_48 -> V_119 )
error = F_33 ( V_48 ) ;
F_40 ( & V_48 -> V_118 ) ;
return error ;
}
static int F_46 ( struct V_105 * V_120 ,
const struct V_122 * V_4 )
{
struct V_2 * V_3 = F_47 ( V_120 ) ;
const struct V_1 * V_7 ;
struct V_47 * V_48 ;
struct V_13 * V_13 ;
int error = - V_91 ;
V_7 = F_1 ( V_3 ) ;
V_48 = F_48 ( sizeof( struct V_47 ) , V_88 ) ;
V_13 = F_49 () ;
if ( ! V_48 || ! V_13 ) {
F_24 ( & V_120 -> V_48 , L_2 ) ;
goto V_123;
}
V_48 -> V_3 = V_3 ;
V_48 -> V_90 = V_120 ;
V_48 -> V_14 = V_13 ;
V_48 -> V_7 = * V_7 ;
F_50 ( & V_48 -> V_118 ) ;
if ( V_7 -> V_82 == V_124 ) {
V_48 -> V_111 = F_51 ( 0 , V_88 ) ;
if ( ! V_48 -> V_111 )
goto V_123;
}
V_48 -> V_114 = F_51 ( 0 , V_88 ) ;
if ( ! V_48 -> V_114 )
goto V_125;
if ( V_48 -> V_111 ) {
V_48 -> V_50 = F_52 ( V_48 -> V_3 ,
V_48 -> V_7 . V_126 , V_88 ,
& V_48 -> V_111 -> V_127 ) ;
if ( ! V_48 -> V_50 )
goto V_128;
}
V_48 -> V_77 = F_52 ( V_48 -> V_3 ,
V_48 -> V_7 . V_129 , V_88 ,
& V_48 -> V_114 -> V_127 ) ;
if ( ! V_48 -> V_77 )
goto V_130;
if ( V_48 -> V_111 )
F_53 ( V_48 -> V_111 , V_3 ,
F_54 ( V_3 , V_7 -> V_131 ) ,
V_48 -> V_50 , V_48 -> V_7 . V_126 ,
F_29 , V_48 , 1 ) ;
F_53 ( V_48 -> V_114 , V_3 ,
F_54 ( V_3 , V_7 -> V_132 ) ,
V_48 -> V_77 , V_48 -> V_7 . V_129 ,
F_32 , V_48 , 1 ) ;
F_55 ( V_3 , V_48 -> V_133 , sizeof( V_48 -> V_133 ) ) ;
F_56 ( V_48 -> V_133 , L_17 , sizeof( V_48 -> V_133 ) ) ;
V_13 -> V_134 = L_18 ;
V_13 -> V_133 = V_48 -> V_133 ;
F_57 ( V_48 -> V_3 , & V_13 -> V_4 ) ;
V_13 -> V_4 . V_135 = V_7 -> V_39 ;
V_13 -> V_48 . V_136 = & V_120 -> V_48 ;
F_58 ( V_13 , V_48 ) ;
V_13 -> V_137 = F_36 ;
V_13 -> V_138 = F_42 ;
F_6 ( V_13 , V_7 ) ;
error = F_59 ( V_48 -> V_14 ) ;
if ( error )
goto V_139;
F_60 ( V_120 , V_48 ) ;
return 0 ;
V_139:
F_61 ( V_48 -> V_3 , V_48 -> V_7 . V_129 ,
V_48 -> V_77 , V_48 -> V_114 -> V_127 ) ;
V_130:
if ( V_48 -> V_111 )
F_61 ( V_48 -> V_3 , V_48 -> V_7 . V_126 ,
V_48 -> V_50 , V_48 -> V_111 -> V_127 ) ;
V_128:
F_62 ( V_48 -> V_114 ) ;
V_125:
F_62 ( V_48 -> V_111 ) ;
V_123:
F_60 ( V_120 , NULL ) ;
F_63 ( V_13 ) ;
F_28 ( V_48 ) ;
return error ;
}
static void F_64 ( struct V_105 * V_120 )
{
struct V_47 * V_48 = F_44 ( V_120 ) ;
F_60 ( V_120 , NULL ) ;
F_65 ( V_48 -> V_14 ) ;
F_61 ( V_48 -> V_3 , V_48 -> V_7 . V_129 ,
V_48 -> V_77 , V_48 -> V_114 -> V_127 ) ;
if ( V_48 -> V_111 )
F_61 ( V_48 -> V_3 , V_48 -> V_7 . V_126 ,
V_48 -> V_50 , V_48 -> V_111 -> V_127 ) ;
F_62 ( V_48 -> V_114 ) ;
F_62 ( V_48 -> V_111 ) ;
F_28 ( V_48 ) ;
}
