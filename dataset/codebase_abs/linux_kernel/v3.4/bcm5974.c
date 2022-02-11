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
static inline int F_4 ( const struct V_13 * V_14 , int V_12 )
{
return V_12 * V_14 -> V_15 / ( V_14 -> V_16 - V_14 -> V_17 ) ;
}
static inline int F_5 ( const struct V_13 * V_14 , int V_12 )
{
int V_18 = F_4 ( V_14 , V_12 ) ;
return F_6 ( V_18 , 0 , V_14 -> V_15 - 1 ) ;
}
static void F_7 ( struct V_19 * V_19 ,
const struct V_1 * V_7 )
{
F_8 ( V_20 , V_19 -> V_21 ) ;
F_9 ( V_19 , V_22 ,
0 , V_7 -> V_14 . V_15 , V_7 -> V_14 . V_23 , 0 ) ;
F_9 ( V_19 , V_24 ,
0 , V_7 -> V_25 . V_15 , V_7 -> V_25 . V_23 , 0 ) ;
F_9 ( V_19 , V_26 ,
0 , V_7 -> V_12 . V_15 , V_7 -> V_12 . V_23 , 0 ) ;
F_9 ( V_19 , V_27 ,
0 , V_7 -> V_28 . V_15 , V_7 -> V_28 . V_23 , 0 ) ;
F_9 ( V_19 , V_29 ,
V_7 -> V_25 . V_17 , V_7 -> V_25 . V_16 , 0 , 0 ) ;
F_9 ( V_19 , V_30 ,
V_7 -> V_25 . V_17 , V_7 -> V_25 . V_16 , 0 , 0 ) ;
F_9 ( V_19 , V_31 ,
V_7 -> V_25 . V_17 , V_7 -> V_25 . V_16 , 0 , 0 ) ;
F_9 ( V_19 , V_32 ,
V_7 -> V_25 . V_17 , V_7 -> V_25 . V_16 , 0 , 0 ) ;
F_9 ( V_19 , V_33 ,
- V_34 ,
V_34 , 0 , 0 ) ;
F_9 ( V_19 , V_35 ,
V_7 -> V_12 . V_17 , V_7 -> V_12 . V_16 , 0 , 0 ) ;
F_9 ( V_19 , V_36 ,
V_7 -> V_28 . V_17 , V_7 -> V_28 . V_16 , 0 , 0 ) ;
F_8 ( V_37 , V_19 -> V_21 ) ;
F_8 ( V_38 , V_19 -> V_39 ) ;
F_8 ( V_40 , V_19 -> V_39 ) ;
F_8 ( V_41 , V_19 -> V_39 ) ;
F_8 ( V_42 , V_19 -> V_39 ) ;
F_8 ( V_43 , V_19 -> V_39 ) ;
F_8 ( V_44 , V_19 -> V_39 ) ;
F_8 ( V_45 , V_19 -> V_46 ) ;
if ( V_7 -> V_47 & V_48 )
F_8 ( V_49 , V_19 -> V_46 ) ;
F_10 ( V_19 , 60 ) ;
}
static int F_11 ( struct V_50 * V_51 , int V_52 )
{
if ( V_52 != sizeof( struct V_53 ) )
return - V_54 ;
F_12 ( 7 ,
L_1 ,
V_51 -> V_53 -> V_55 , V_51 -> V_53 -> V_56 ,
V_51 -> V_53 -> V_57 , V_51 -> V_53 -> V_58 ) ;
F_13 ( V_51 -> V_59 , V_44 , V_51 -> V_53 -> V_56 ) ;
F_14 ( V_51 -> V_59 ) ;
return 0 ;
}
static void F_15 ( struct V_19 * V_59 ,
const struct V_1 * V_7 ,
const struct V_60 * V_61 )
{
F_16 ( V_59 , V_29 ,
F_3 ( V_61 -> V_62 ) << 1 ) ;
F_16 ( V_59 , V_30 ,
F_3 ( V_61 -> V_63 ) << 1 ) ;
F_16 ( V_59 , V_31 ,
F_3 ( V_61 -> V_64 ) << 1 ) ;
F_16 ( V_59 , V_32 ,
F_3 ( V_61 -> V_65 ) << 1 ) ;
F_16 ( V_59 , V_33 ,
V_34 - F_3 ( V_61 -> V_66 ) ) ;
F_16 ( V_59 , V_35 , F_3 ( V_61 -> V_67 ) ) ;
F_16 ( V_59 , V_36 ,
V_7 -> V_28 . V_17 + V_7 -> V_28 . V_16 - F_3 ( V_61 -> V_68 ) ) ;
F_17 ( V_59 ) ;
}
static int F_18 ( struct V_50 * V_51 , int V_52 )
{
const struct V_1 * V_69 = & V_51 -> V_7 ;
const struct V_60 * V_61 ;
struct V_19 * V_59 = V_51 -> V_59 ;
int V_70 , V_71 , V_72 , V_73 , V_74 , V_75 ;
int V_76 , V_77 , V_78 = 0 , V_79 = 0 , V_80 = 0 ;
int V_81 = 0 , V_82 = 0 , V_67 = 0 , V_68 = 0 ;
if ( V_52 < V_69 -> V_83 || ( V_52 - V_69 -> V_83 ) % V_84 != 0 )
return - V_54 ;
V_61 = ( const struct V_60 * ) ( V_51 -> V_85 + V_69 -> V_83 ) ;
V_74 = ( V_52 - V_69 -> V_83 ) / V_84 ;
if ( V_74 ) {
for ( V_75 = 0 ; V_75 < V_74 ; V_75 ++ )
F_15 ( V_59 , V_69 , & V_61 [ V_75 ] ) ;
V_70 = F_3 ( V_61 -> V_62 ) ;
V_71 = F_3 ( V_61 -> V_64 ) ;
V_72 = F_3 ( V_61 -> V_67 ) ;
V_73 = F_3 ( V_61 -> V_68 ) ;
F_12 ( 9 ,
L_2
L_3 ,
V_70 , V_71 , V_72 , V_73 , V_74 ) ;
V_76 = F_5 ( & V_69 -> V_14 , V_70 ) ;
V_77 = F_3 ( V_61 -> V_77 ) ;
if ( V_76 > V_86 && V_77 ) {
V_81 = V_76 ;
V_82 = F_5 ( & V_69 -> V_25 , V_71 ) ;
V_67 = F_5 ( & V_69 -> V_12 , V_72 - V_69 -> V_12 . V_17 ) ;
V_68 = F_5 ( & V_69 -> V_28 , V_69 -> V_28 . V_16 - V_73 ) ;
while ( V_74 -- ) {
V_76 = F_5 ( & V_69 -> V_14 ,
F_3 ( V_61 -> V_62 ) ) ;
if ( V_76 > V_86 )
V_80 ++ ;
if ( V_76 > V_87 )
V_79 ++ ;
V_61 ++ ;
}
}
}
if ( V_69 -> V_88 == V_89 )
V_78 = F_3 ( V_51 -> V_85 [ V_90 ] ) ;
if ( V_51 -> V_91 < V_79 )
V_51 -> V_91 = V_79 ;
if ( V_51 -> V_91 > V_80 )
V_51 -> V_91 = V_80 ;
F_13 ( V_59 , V_38 , V_51 -> V_91 > 0 ) ;
F_13 ( V_59 , V_40 , V_51 -> V_91 == 1 ) ;
F_13 ( V_59 , V_41 , V_51 -> V_91 == 2 ) ;
F_13 ( V_59 , V_42 , V_51 -> V_91 == 3 ) ;
F_13 ( V_59 , V_43 , V_51 -> V_91 > 3 ) ;
F_16 ( V_59 , V_22 , V_81 ) ;
F_16 ( V_59 , V_24 , V_82 ) ;
if ( V_81 ) {
F_16 ( V_59 , V_26 , V_67 ) ;
F_16 ( V_59 , V_27 , V_68 ) ;
F_12 ( 8 ,
L_4
L_5 , V_81 , V_82 ,
V_67 , V_68 , V_79 , V_80 , V_51 -> V_91 , V_78 ) ;
}
if ( V_69 -> V_88 == V_89 )
F_13 ( V_59 , V_44 , V_78 ) ;
F_14 ( V_59 ) ;
return 0 ;
}
static int F_19 ( struct V_50 * V_51 , bool V_92 )
{
char * V_93 = F_20 ( 8 , V_94 ) ;
int V_95 = 0 , V_52 ;
if ( ! V_93 ) {
F_21 ( L_6 ) ;
V_95 = - V_96 ;
goto V_97;
}
V_52 = F_22 ( V_51 -> V_3 , F_23 ( V_51 -> V_3 , 0 ) ,
V_98 ,
V_99 | V_100 | V_101 ,
V_102 ,
V_103 , V_93 , 8 , 5000 ) ;
if ( V_52 != 8 ) {
F_21 ( L_7 ) ;
V_95 = - V_54 ;
goto V_97;
}
V_93 [ 0 ] = V_92 ?
V_104 :
V_105 ;
V_52 = F_22 ( V_51 -> V_3 , F_24 ( V_51 -> V_3 , 0 ) ,
V_106 ,
V_107 | V_100 | V_101 ,
V_102 ,
V_103 , V_93 , 8 , 5000 ) ;
if ( V_52 != 8 ) {
F_21 ( L_8 ) ;
V_95 = - V_54 ;
goto V_97;
}
F_12 ( 2 , L_9 ,
V_92 ? L_10 : L_11 ) ;
V_97:
F_25 ( V_93 ) ;
return V_95 ;
}
static void F_26 ( struct V_108 * V_108 )
{
struct V_50 * V_51 = V_108 -> V_109 ;
int error ;
switch ( V_108 -> V_110 ) {
case 0 :
break;
case - V_111 :
case - V_112 :
case - V_113 :
case - V_114 :
F_27 ( L_12 , V_108 -> V_110 ) ;
return;
default:
F_27 ( L_13 , V_108 -> V_110 ) ;
goto exit;
}
if ( F_11 ( V_51 , V_51 -> V_115 -> V_116 ) )
F_12 ( 1 , L_14 ,
V_51 -> V_115 -> V_116 ) ;
exit:
error = F_28 ( V_51 -> V_115 , V_117 ) ;
if ( error )
F_21 ( L_15 , error ) ;
}
static void F_29 ( struct V_108 * V_108 )
{
struct V_50 * V_51 = V_108 -> V_109 ;
int error ;
switch ( V_108 -> V_110 ) {
case 0 :
break;
case - V_111 :
case - V_112 :
case - V_113 :
case - V_114 :
F_27 ( L_16 , V_108 -> V_110 ) ;
return;
default:
F_27 ( L_17 , V_108 -> V_110 ) ;
goto exit;
}
if ( V_51 -> V_118 -> V_116 == 2 )
goto exit;
if ( F_18 ( V_51 , V_51 -> V_118 -> V_116 ) )
F_12 ( 1 , L_18 ,
V_51 -> V_118 -> V_116 ) ;
exit:
error = F_28 ( V_51 -> V_118 , V_117 ) ;
if ( error )
F_21 ( L_19 , error ) ;
}
static int F_30 ( struct V_50 * V_51 )
{
int error ;
error = F_19 ( V_51 , true ) ;
if ( error ) {
F_12 ( 1 , L_20 ) ;
goto V_119;
}
error = F_28 ( V_51 -> V_115 , V_94 ) ;
if ( error )
goto V_120;
error = F_28 ( V_51 -> V_118 , V_94 ) ;
if ( error )
goto V_121;
return 0 ;
V_121:
F_31 ( V_51 -> V_115 ) ;
V_120:
F_19 ( V_51 , false ) ;
V_119:
return error ;
}
static void F_32 ( struct V_50 * V_51 )
{
F_31 ( V_51 -> V_118 ) ;
F_31 ( V_51 -> V_115 ) ;
F_19 ( V_51 , false ) ;
}
static int F_33 ( struct V_19 * V_59 )
{
struct V_50 * V_51 = F_34 ( V_59 ) ;
int error ;
error = F_35 ( V_51 -> V_122 ) ;
if ( error )
return error ;
F_36 ( & V_51 -> V_123 ) ;
error = F_30 ( V_51 ) ;
if ( ! error )
V_51 -> V_124 = 1 ;
F_37 ( & V_51 -> V_123 ) ;
if ( error )
F_38 ( V_51 -> V_122 ) ;
return error ;
}
static void F_39 ( struct V_19 * V_59 )
{
struct V_50 * V_51 = F_34 ( V_59 ) ;
F_36 ( & V_51 -> V_123 ) ;
F_32 ( V_51 ) ;
V_51 -> V_124 = 0 ;
F_37 ( & V_51 -> V_123 ) ;
F_38 ( V_51 -> V_122 ) ;
}
static int F_40 ( struct V_125 * V_126 , T_3 V_127 )
{
struct V_50 * V_51 = F_41 ( V_126 ) ;
F_36 ( & V_51 -> V_123 ) ;
if ( V_51 -> V_124 )
F_32 ( V_51 ) ;
F_37 ( & V_51 -> V_123 ) ;
return 0 ;
}
static int F_42 ( struct V_125 * V_126 )
{
struct V_50 * V_51 = F_41 ( V_126 ) ;
int error = 0 ;
F_36 ( & V_51 -> V_123 ) ;
if ( V_51 -> V_124 )
error = F_30 ( V_51 ) ;
F_37 ( & V_51 -> V_123 ) ;
return error ;
}
static int F_43 ( struct V_125 * V_126 ,
const struct V_128 * V_4 )
{
struct V_2 * V_3 = F_44 ( V_126 ) ;
const struct V_1 * V_7 ;
struct V_50 * V_51 ;
struct V_19 * V_19 ;
int error = - V_96 ;
V_7 = F_1 ( V_3 ) ;
V_51 = F_45 ( sizeof( struct V_50 ) , V_94 ) ;
V_19 = F_46 () ;
if ( ! V_51 || ! V_19 ) {
F_21 ( L_6 ) ;
goto V_129;
}
V_51 -> V_3 = V_3 ;
V_51 -> V_122 = V_126 ;
V_51 -> V_59 = V_19 ;
V_51 -> V_7 = * V_7 ;
F_47 ( & V_51 -> V_123 ) ;
V_51 -> V_115 = F_48 ( 0 , V_94 ) ;
if ( ! V_51 -> V_115 )
goto V_129;
V_51 -> V_118 = F_48 ( 0 , V_94 ) ;
if ( ! V_51 -> V_118 )
goto V_130;
V_51 -> V_53 = F_49 ( V_51 -> V_3 ,
V_51 -> V_7 . V_131 , V_94 ,
& V_51 -> V_115 -> V_132 ) ;
if ( ! V_51 -> V_53 )
goto V_133;
V_51 -> V_85 = F_49 ( V_51 -> V_3 ,
V_51 -> V_7 . V_134 , V_94 ,
& V_51 -> V_118 -> V_132 ) ;
if ( ! V_51 -> V_85 )
goto V_135;
F_50 ( V_51 -> V_115 , V_3 ,
F_51 ( V_3 , V_7 -> V_136 ) ,
V_51 -> V_53 , V_51 -> V_7 . V_131 ,
F_26 , V_51 , 1 ) ;
F_50 ( V_51 -> V_118 , V_3 ,
F_51 ( V_3 , V_7 -> V_137 ) ,
V_51 -> V_85 , V_51 -> V_7 . V_134 ,
F_29 , V_51 , 1 ) ;
F_52 ( V_3 , V_51 -> V_138 , sizeof( V_51 -> V_138 ) ) ;
F_53 ( V_51 -> V_138 , L_21 , sizeof( V_51 -> V_138 ) ) ;
V_19 -> V_139 = L_22 ;
V_19 -> V_138 = V_51 -> V_138 ;
F_54 ( V_51 -> V_3 , & V_19 -> V_4 ) ;
V_19 -> V_4 . V_140 = V_7 -> V_47 ;
V_19 -> V_51 . V_141 = & V_126 -> V_51 ;
F_55 ( V_19 , V_51 ) ;
V_19 -> V_142 = F_33 ;
V_19 -> V_143 = F_39 ;
F_7 ( V_19 , V_7 ) ;
error = F_56 ( V_51 -> V_59 ) ;
if ( error )
goto V_144;
F_57 ( V_126 , V_51 ) ;
return 0 ;
V_144:
F_58 ( V_51 -> V_3 , V_51 -> V_7 . V_134 ,
V_51 -> V_85 , V_51 -> V_118 -> V_132 ) ;
V_135:
F_58 ( V_51 -> V_3 , V_51 -> V_7 . V_131 ,
V_51 -> V_53 , V_51 -> V_115 -> V_132 ) ;
V_133:
F_59 ( V_51 -> V_118 ) ;
V_130:
F_59 ( V_51 -> V_115 ) ;
V_129:
F_57 ( V_126 , NULL ) ;
F_60 ( V_19 ) ;
F_25 ( V_51 ) ;
return error ;
}
static void F_61 ( struct V_125 * V_126 )
{
struct V_50 * V_51 = F_41 ( V_126 ) ;
F_57 ( V_126 , NULL ) ;
F_62 ( V_51 -> V_59 ) ;
F_58 ( V_51 -> V_3 , V_51 -> V_7 . V_134 ,
V_51 -> V_85 , V_51 -> V_118 -> V_132 ) ;
F_58 ( V_51 -> V_3 , V_51 -> V_7 . V_131 ,
V_51 -> V_53 , V_51 -> V_115 -> V_132 ) ;
F_59 ( V_51 -> V_118 ) ;
F_59 ( V_51 -> V_115 ) ;
F_25 ( V_51 ) ;
}
