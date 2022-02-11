static const struct V_1 * F_1 ( const struct V_2 * V_3 , int V_4 )
{
const struct V_5 * V_6 = & V_3 -> V_7 ;
T_1 * V_8 = V_3 -> V_9 + V_6 -> V_10 + V_6 -> V_11 ;
return ( const struct V_1 * ) ( V_8 + V_4 * V_6 -> V_12 ) ;
}
static const struct V_5 * F_2 ( struct V_13 * V_14 )
{
T_2 V_15 = F_3 ( V_14 -> V_16 . V_17 ) ;
const struct V_5 * V_7 ;
for ( V_7 = V_18 ; V_7 -> V_19 ; ++ V_7 )
if ( V_7 -> V_19 == V_15 || V_7 -> V_20 == V_15 || V_7 -> V_21 == V_15 )
return V_7 ;
return V_18 ;
}
static inline int F_4 ( T_3 V_22 )
{
return ( signed short ) F_3 ( V_22 ) ;
}
static void F_5 ( struct V_23 * V_24 , unsigned int V_25 ,
const struct V_26 * V_27 )
{
int V_28 = V_27 -> V_29 ? ( V_27 -> V_30 - V_27 -> V_31 ) / V_27 -> V_29 : 0 ;
F_6 ( V_24 , V_25 , V_27 -> V_31 , V_27 -> V_30 , V_28 , 0 ) ;
}
static void F_7 ( struct V_23 * V_23 ,
const struct V_5 * V_7 )
{
F_8 ( V_32 , V_23 -> V_33 ) ;
F_6 ( V_23 , V_34 , 0 , 256 , 5 , 0 ) ;
F_6 ( V_23 , V_35 , 0 , 16 , 0 , 0 ) ;
F_5 ( V_23 , V_36 , & V_7 -> V_37 ) ;
F_5 ( V_23 , V_38 , & V_7 -> V_37 ) ;
F_5 ( V_23 , V_39 , & V_7 -> V_37 ) ;
F_5 ( V_23 , V_40 , & V_7 -> V_37 ) ;
F_5 ( V_23 , V_41 , & V_7 -> V_42 ) ;
F_5 ( V_23 , V_43 , & V_7 -> V_22 ) ;
F_5 ( V_23 , V_44 , & V_7 -> V_45 ) ;
F_8 ( V_46 , V_23 -> V_33 ) ;
F_8 ( V_47 , V_23 -> V_48 ) ;
if ( V_7 -> V_49 & V_50 )
F_8 ( V_51 , V_23 -> V_52 ) ;
F_9 ( V_23 , V_53 ,
V_54 | V_55 | V_56 ) ;
}
static int F_10 ( struct V_2 * V_3 , int V_57 )
{
if ( V_57 != sizeof( struct V_58 ) )
return - V_59 ;
F_11 ( 7 ,
L_1 ,
V_3 -> V_58 -> V_60 , V_3 -> V_58 -> V_61 ,
V_3 -> V_58 -> V_62 , V_3 -> V_58 -> V_63 ) ;
F_12 ( V_3 -> V_24 , V_47 , V_3 -> V_58 -> V_61 ) ;
F_13 ( V_3 -> V_24 ) ;
return 0 ;
}
static void F_14 ( struct V_23 * V_24 , int V_64 ,
const struct V_65 * V_66 ,
const struct V_1 * V_67 )
{
F_15 ( V_24 , V_64 ) ;
F_16 ( V_24 , V_68 , true ) ;
F_17 ( V_24 , V_36 ,
F_4 ( V_67 -> V_69 ) << 1 ) ;
F_17 ( V_24 , V_38 ,
F_4 ( V_67 -> V_70 ) << 1 ) ;
F_17 ( V_24 , V_39 ,
F_4 ( V_67 -> V_71 ) << 1 ) ;
F_17 ( V_24 , V_40 ,
F_4 ( V_67 -> V_72 ) << 1 ) ;
F_17 ( V_24 , V_41 ,
V_73 - F_4 ( V_67 -> V_74 ) ) ;
F_17 ( V_24 , V_43 , V_66 -> V_22 ) ;
F_17 ( V_24 , V_44 , V_66 -> V_45 ) ;
}
static void F_18 ( struct V_23 * V_24 ,
const struct V_5 * V_7 ,
const struct V_1 * V_67 , int V_75 )
{
int V_76 = 0 , V_77 = 0 ;
if ( V_75 ) {
int V_27 = F_4 ( V_67 -> V_69 ) ;
int V_37 = F_4 ( V_67 -> V_71 ) ;
if ( V_27 > 0 && F_4 ( V_67 -> V_78 ) ) {
V_76 = F_19 ( 256 * V_27 / V_7 -> V_27 . V_30 , 0 , 255 ) ;
V_77 = F_19 ( 16 * V_37 / V_7 -> V_37 . V_30 , 0 , 15 ) ;
}
}
F_17 ( V_24 , V_34 , V_76 ) ;
F_17 ( V_24 , V_35 , V_77 ) ;
}
static int F_20 ( struct V_2 * V_3 , int V_57 )
{
const struct V_5 * V_6 = & V_3 -> V_7 ;
const struct V_1 * V_67 ;
struct V_23 * V_24 = V_3 -> V_24 ;
int V_75 , V_4 , V_79 = 0 ;
if ( V_57 < V_6 -> V_10 || ( V_57 - V_6 -> V_10 ) % V_6 -> V_12 != 0 )
return - V_59 ;
V_75 = ( V_57 - V_6 -> V_10 ) / V_6 -> V_12 ;
for ( V_4 = 0 ; V_4 < V_75 ; V_4 ++ ) {
V_67 = F_1 ( V_3 , V_4 ) ;
if ( F_4 ( V_67 -> V_69 ) == 0 )
continue;
V_3 -> V_66 [ V_79 ] . V_22 = F_4 ( V_67 -> V_80 ) ;
V_3 -> V_66 [ V_79 ] . V_45 = V_6 -> V_45 . V_31 + V_6 -> V_45 . V_30 - F_4 ( V_67 -> V_81 ) ;
V_3 -> V_82 [ V_79 ++ ] = V_67 ;
}
F_21 ( V_24 , V_3 -> V_83 , V_3 -> V_66 , V_79 , 0 ) ;
for ( V_4 = 0 ; V_4 < V_79 ; V_4 ++ )
F_14 ( V_24 , V_3 -> V_83 [ V_4 ] ,
& V_3 -> V_66 [ V_4 ] , V_3 -> V_82 [ V_4 ] ) ;
F_22 ( V_24 ) ;
F_18 ( V_24 , V_6 , F_1 ( V_3 , 0 ) , V_75 ) ;
if ( V_6 -> V_49 & V_50 ) {
int V_84 = F_4 ( V_3 -> V_9 [ V_6 -> V_85 ] ) ;
F_12 ( V_24 , V_47 , V_84 ) ;
}
F_13 ( V_24 ) ;
return 0 ;
}
static int F_23 ( struct V_2 * V_3 , bool V_86 )
{
const struct V_5 * V_6 = & V_3 -> V_7 ;
int V_87 = 0 , V_57 ;
char * V_88 ;
if ( V_6 -> V_89 == V_90 )
return 0 ;
V_88 = F_24 ( V_6 -> V_91 , V_92 ) ;
if ( ! V_88 ) {
F_25 ( & V_3 -> V_93 -> V_3 , L_2 ) ;
V_87 = - V_94 ;
goto V_95;
}
V_57 = F_26 ( V_3 -> V_14 , F_27 ( V_3 -> V_14 , 0 ) ,
V_96 ,
V_97 | V_98 | V_99 ,
V_6 -> V_100 , V_6 -> V_101 , V_88 , V_6 -> V_91 , 5000 ) ;
if ( V_57 != V_6 -> V_91 ) {
F_25 ( & V_3 -> V_93 -> V_3 , L_3 ) ;
V_87 = - V_59 ;
goto V_95;
}
V_88 [ V_6 -> V_102 ] = V_86 ? V_6 -> V_103 : V_6 -> V_104 ;
V_57 = F_26 ( V_3 -> V_14 , F_28 ( V_3 -> V_14 , 0 ) ,
V_105 ,
V_106 | V_98 | V_99 ,
V_6 -> V_100 , V_6 -> V_101 , V_88 , V_6 -> V_91 , 5000 ) ;
if ( V_57 != V_6 -> V_91 ) {
F_25 ( & V_3 -> V_93 -> V_3 , L_4 ) ;
V_87 = - V_59 ;
goto V_95;
}
F_11 ( 2 , L_5 ,
V_86 ? L_6 : L_7 ) ;
V_95:
F_29 ( V_88 ) ;
return V_87 ;
}
static void F_30 ( struct V_107 * V_107 )
{
struct V_2 * V_3 = V_107 -> V_108 ;
struct V_109 * V_93 = V_3 -> V_93 ;
int error ;
switch ( V_107 -> V_110 ) {
case 0 :
break;
case - V_111 :
case - V_112 :
case - V_113 :
case - V_114 :
F_31 ( & V_93 -> V_3 , L_8 ,
V_107 -> V_110 ) ;
return;
default:
F_31 ( & V_93 -> V_3 , L_9 , V_107 -> V_110 ) ;
goto exit;
}
if ( F_10 ( V_3 , V_3 -> V_115 -> V_116 ) )
F_11 ( 1 , L_10 ,
V_3 -> V_115 -> V_116 ) ;
exit:
error = F_32 ( V_3 -> V_115 , V_117 ) ;
if ( error )
F_25 ( & V_93 -> V_3 , L_11 , error ) ;
}
static void F_33 ( struct V_107 * V_107 )
{
struct V_2 * V_3 = V_107 -> V_108 ;
struct V_109 * V_93 = V_3 -> V_93 ;
int error ;
switch ( V_107 -> V_110 ) {
case 0 :
break;
case - V_111 :
case - V_112 :
case - V_113 :
case - V_114 :
F_31 ( & V_93 -> V_3 , L_12 ,
V_107 -> V_110 ) ;
return;
default:
F_31 ( & V_93 -> V_3 , L_13 , V_107 -> V_110 ) ;
goto exit;
}
if ( V_3 -> V_118 -> V_116 == 2 )
goto exit;
if ( F_20 ( V_3 , V_3 -> V_118 -> V_116 ) )
F_11 ( 1 , L_14 ,
V_3 -> V_118 -> V_116 ) ;
exit:
error = F_32 ( V_3 -> V_118 , V_117 ) ;
if ( error )
F_25 ( & V_93 -> V_3 , L_15 , error ) ;
}
static int F_34 ( struct V_2 * V_3 )
{
int error ;
error = F_23 ( V_3 , true ) ;
if ( error ) {
F_11 ( 1 , L_16 ) ;
goto V_119;
}
if ( V_3 -> V_115 ) {
error = F_32 ( V_3 -> V_115 , V_92 ) ;
if ( error )
goto V_120;
}
error = F_32 ( V_3 -> V_118 , V_92 ) ;
if ( error )
goto V_121;
return 0 ;
V_121:
F_35 ( V_3 -> V_115 ) ;
V_120:
F_23 ( V_3 , false ) ;
V_119:
return error ;
}
static void F_36 ( struct V_2 * V_3 )
{
F_35 ( V_3 -> V_118 ) ;
F_35 ( V_3 -> V_115 ) ;
F_23 ( V_3 , false ) ;
}
static int F_37 ( struct V_23 * V_24 )
{
struct V_2 * V_3 = F_38 ( V_24 ) ;
int error ;
error = F_39 ( V_3 -> V_93 ) ;
if ( error )
return error ;
F_40 ( & V_3 -> V_122 ) ;
error = F_34 ( V_3 ) ;
if ( ! error )
V_3 -> V_123 = 1 ;
F_41 ( & V_3 -> V_122 ) ;
if ( error )
F_42 ( V_3 -> V_93 ) ;
return error ;
}
static void F_43 ( struct V_23 * V_24 )
{
struct V_2 * V_3 = F_38 ( V_24 ) ;
F_40 ( & V_3 -> V_122 ) ;
F_36 ( V_3 ) ;
V_3 -> V_123 = 0 ;
F_41 ( & V_3 -> V_122 ) ;
F_42 ( V_3 -> V_93 ) ;
}
static int F_44 ( struct V_109 * V_124 , T_4 V_125 )
{
struct V_2 * V_3 = F_45 ( V_124 ) ;
F_40 ( & V_3 -> V_122 ) ;
if ( V_3 -> V_123 )
F_36 ( V_3 ) ;
F_41 ( & V_3 -> V_122 ) ;
return 0 ;
}
static int F_46 ( struct V_109 * V_124 )
{
struct V_2 * V_3 = F_45 ( V_124 ) ;
int error = 0 ;
F_40 ( & V_3 -> V_122 ) ;
if ( V_3 -> V_123 )
error = F_34 ( V_3 ) ;
F_41 ( & V_3 -> V_122 ) ;
return error ;
}
static int F_47 ( struct V_109 * V_124 ,
const struct V_126 * V_15 )
{
struct V_13 * V_14 = F_48 ( V_124 ) ;
const struct V_5 * V_7 ;
struct V_2 * V_3 ;
struct V_23 * V_23 ;
int error = - V_94 ;
V_7 = F_2 ( V_14 ) ;
V_3 = F_49 ( sizeof( struct V_2 ) , V_92 ) ;
V_23 = F_50 () ;
if ( ! V_3 || ! V_23 ) {
F_25 ( & V_124 -> V_3 , L_2 ) ;
goto V_127;
}
V_3 -> V_14 = V_14 ;
V_3 -> V_93 = V_124 ;
V_3 -> V_24 = V_23 ;
V_3 -> V_7 = * V_7 ;
F_51 ( & V_3 -> V_122 ) ;
if ( V_7 -> V_89 == V_128 ) {
V_3 -> V_115 = F_52 ( 0 , V_92 ) ;
if ( ! V_3 -> V_115 )
goto V_127;
}
V_3 -> V_118 = F_52 ( 0 , V_92 ) ;
if ( ! V_3 -> V_118 )
goto V_129;
if ( V_3 -> V_115 ) {
V_3 -> V_58 = F_53 ( V_3 -> V_14 ,
V_3 -> V_7 . V_130 , V_92 ,
& V_3 -> V_115 -> V_131 ) ;
if ( ! V_3 -> V_58 )
goto V_132;
}
V_3 -> V_9 = F_53 ( V_3 -> V_14 ,
V_3 -> V_7 . V_133 , V_92 ,
& V_3 -> V_118 -> V_131 ) ;
if ( ! V_3 -> V_9 )
goto V_134;
if ( V_3 -> V_115 )
F_54 ( V_3 -> V_115 , V_14 ,
F_55 ( V_14 , V_7 -> V_135 ) ,
V_3 -> V_58 , V_3 -> V_7 . V_130 ,
F_30 , V_3 , 1 ) ;
F_54 ( V_3 -> V_118 , V_14 ,
F_55 ( V_14 , V_7 -> V_136 ) ,
V_3 -> V_9 , V_3 -> V_7 . V_133 ,
F_33 , V_3 , 1 ) ;
F_56 ( V_14 , V_3 -> V_137 , sizeof( V_3 -> V_137 ) ) ;
F_57 ( V_3 -> V_137 , L_17 , sizeof( V_3 -> V_137 ) ) ;
V_23 -> V_138 = L_18 ;
V_23 -> V_137 = V_3 -> V_137 ;
F_58 ( V_3 -> V_14 , & V_23 -> V_15 ) ;
V_23 -> V_15 . V_139 = V_7 -> V_49 ;
V_23 -> V_3 . V_140 = & V_124 -> V_3 ;
F_59 ( V_23 , V_3 ) ;
V_23 -> V_141 = F_37 ;
V_23 -> V_142 = F_43 ;
F_7 ( V_23 , V_7 ) ;
error = F_60 ( V_3 -> V_24 ) ;
if ( error )
goto V_143;
F_61 ( V_124 , V_3 ) ;
return 0 ;
V_143:
F_62 ( V_3 -> V_14 , V_3 -> V_7 . V_133 ,
V_3 -> V_9 , V_3 -> V_118 -> V_131 ) ;
V_134:
if ( V_3 -> V_115 )
F_62 ( V_3 -> V_14 , V_3 -> V_7 . V_130 ,
V_3 -> V_58 , V_3 -> V_115 -> V_131 ) ;
V_132:
F_63 ( V_3 -> V_118 ) ;
V_129:
F_63 ( V_3 -> V_115 ) ;
V_127:
F_61 ( V_124 , NULL ) ;
F_64 ( V_23 ) ;
F_29 ( V_3 ) ;
return error ;
}
static void F_65 ( struct V_109 * V_124 )
{
struct V_2 * V_3 = F_45 ( V_124 ) ;
F_61 ( V_124 , NULL ) ;
F_66 ( V_3 -> V_24 ) ;
F_62 ( V_3 -> V_14 , V_3 -> V_7 . V_133 ,
V_3 -> V_9 , V_3 -> V_118 -> V_131 ) ;
if ( V_3 -> V_115 )
F_62 ( V_3 -> V_14 , V_3 -> V_7 . V_130 ,
V_3 -> V_58 , V_3 -> V_115 -> V_131 ) ;
F_63 ( V_3 -> V_118 ) ;
F_63 ( V_3 -> V_115 ) ;
F_29 ( V_3 ) ;
}
