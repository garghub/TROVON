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
F_10 ( V_19 , 60 ) ;
}
static int F_11 ( struct V_45 * V_46 , int V_47 )
{
if ( V_47 != sizeof( struct V_48 ) )
return - V_49 ;
F_12 ( 7 ,
L_1 ,
V_46 -> V_48 -> V_50 , V_46 -> V_48 -> V_51 ,
V_46 -> V_48 -> V_52 , V_46 -> V_48 -> V_53 ) ;
F_13 ( V_46 -> V_54 , V_44 , V_46 -> V_48 -> V_51 ) ;
F_14 ( V_46 -> V_54 ) ;
return 0 ;
}
static void F_15 ( struct V_19 * V_54 ,
const struct V_1 * V_7 ,
const struct V_55 * V_56 )
{
F_16 ( V_54 , V_29 ,
F_3 ( V_56 -> V_57 ) << 1 ) ;
F_16 ( V_54 , V_30 ,
F_3 ( V_56 -> V_58 ) << 1 ) ;
F_16 ( V_54 , V_31 ,
F_3 ( V_56 -> V_59 ) << 1 ) ;
F_16 ( V_54 , V_32 ,
F_3 ( V_56 -> V_60 ) << 1 ) ;
F_16 ( V_54 , V_33 ,
V_34 - F_3 ( V_56 -> V_61 ) ) ;
F_16 ( V_54 , V_35 , F_3 ( V_56 -> V_62 ) ) ;
F_16 ( V_54 , V_36 ,
V_7 -> V_28 . V_17 + V_7 -> V_28 . V_16 - F_3 ( V_56 -> V_63 ) ) ;
F_17 ( V_54 ) ;
}
static int F_18 ( struct V_45 * V_46 , int V_47 )
{
const struct V_1 * V_64 = & V_46 -> V_7 ;
const struct V_55 * V_56 ;
struct V_19 * V_54 = V_46 -> V_54 ;
int V_65 , V_66 , V_67 , V_68 , V_69 , V_70 ;
int V_71 , V_72 , V_73 = 0 , V_74 = 0 , V_75 = 0 ;
int V_76 = 0 , V_77 = 0 , V_62 = 0 , V_63 = 0 ;
if ( V_47 < V_64 -> V_78 || ( V_47 - V_64 -> V_78 ) % V_79 != 0 )
return - V_49 ;
V_56 = ( const struct V_55 * ) ( V_46 -> V_80 + V_64 -> V_78 ) ;
V_69 = ( V_47 - V_64 -> V_78 ) / V_79 ;
if ( V_69 ) {
for ( V_70 = 0 ; V_70 < V_69 ; V_70 ++ )
F_15 ( V_54 , V_64 , & V_56 [ V_70 ] ) ;
V_65 = F_3 ( V_56 -> V_57 ) ;
V_66 = F_3 ( V_56 -> V_59 ) ;
V_67 = F_3 ( V_56 -> V_62 ) ;
V_68 = F_3 ( V_56 -> V_63 ) ;
F_12 ( 9 ,
L_2
L_3 ,
V_65 , V_66 , V_67 , V_68 , V_69 ) ;
V_71 = F_5 ( & V_64 -> V_14 , V_65 ) ;
V_72 = F_3 ( V_56 -> V_72 ) ;
if ( V_71 > V_81 && V_72 ) {
V_76 = V_71 ;
V_77 = F_5 ( & V_64 -> V_25 , V_66 ) ;
V_62 = F_5 ( & V_64 -> V_12 , V_67 - V_64 -> V_12 . V_17 ) ;
V_63 = F_5 ( & V_64 -> V_28 , V_64 -> V_28 . V_16 - V_68 ) ;
while ( V_69 -- ) {
V_71 = F_5 ( & V_64 -> V_14 ,
F_3 ( V_56 -> V_57 ) ) ;
if ( V_71 > V_81 )
V_75 ++ ;
if ( V_71 > V_82 )
V_74 ++ ;
V_56 ++ ;
}
}
}
if ( V_64 -> V_83 == V_84 )
V_73 = F_3 ( V_46 -> V_80 [ V_85 ] ) ;
if ( V_46 -> V_86 < V_74 )
V_46 -> V_86 = V_74 ;
if ( V_46 -> V_86 > V_75 )
V_46 -> V_86 = V_75 ;
F_13 ( V_54 , V_38 , V_46 -> V_86 > 0 ) ;
F_13 ( V_54 , V_40 , V_46 -> V_86 == 1 ) ;
F_13 ( V_54 , V_41 , V_46 -> V_86 == 2 ) ;
F_13 ( V_54 , V_42 , V_46 -> V_86 == 3 ) ;
F_13 ( V_54 , V_43 , V_46 -> V_86 > 3 ) ;
F_16 ( V_54 , V_22 , V_76 ) ;
F_16 ( V_54 , V_24 , V_77 ) ;
if ( V_76 ) {
F_16 ( V_54 , V_26 , V_62 ) ;
F_16 ( V_54 , V_27 , V_63 ) ;
F_12 ( 8 ,
L_4
L_5 , V_76 , V_77 ,
V_62 , V_63 , V_74 , V_75 , V_46 -> V_86 , V_73 ) ;
}
if ( V_64 -> V_83 == V_84 )
F_13 ( V_54 , V_44 , V_73 ) ;
F_14 ( V_54 ) ;
return 0 ;
}
static int F_19 ( struct V_45 * V_46 , bool V_87 )
{
char * V_88 = F_20 ( 8 , V_89 ) ;
int V_90 = 0 , V_47 ;
if ( ! V_88 ) {
F_21 ( L_6 ) ;
V_90 = - V_91 ;
goto V_92;
}
V_47 = F_22 ( V_46 -> V_3 , F_23 ( V_46 -> V_3 , 0 ) ,
V_93 ,
V_94 | V_95 | V_96 ,
V_97 ,
V_98 , V_88 , 8 , 5000 ) ;
if ( V_47 != 8 ) {
F_21 ( L_7 ) ;
V_90 = - V_49 ;
goto V_92;
}
V_88 [ 0 ] = V_87 ?
V_99 :
V_100 ;
V_47 = F_22 ( V_46 -> V_3 , F_24 ( V_46 -> V_3 , 0 ) ,
V_101 ,
V_102 | V_95 | V_96 ,
V_97 ,
V_98 , V_88 , 8 , 5000 ) ;
if ( V_47 != 8 ) {
F_21 ( L_8 ) ;
V_90 = - V_49 ;
goto V_92;
}
F_12 ( 2 , L_9 ,
V_87 ? L_10 : L_11 ) ;
V_92:
F_25 ( V_88 ) ;
return V_90 ;
}
static void F_26 ( struct V_103 * V_103 )
{
struct V_45 * V_46 = V_103 -> V_104 ;
int error ;
switch ( V_103 -> V_105 ) {
case 0 :
break;
case - V_106 :
case - V_107 :
case - V_108 :
case - V_109 :
F_27 ( L_12 , V_103 -> V_105 ) ;
return;
default:
F_27 ( L_13 , V_103 -> V_105 ) ;
goto exit;
}
if ( F_11 ( V_46 , V_46 -> V_110 -> V_111 ) )
F_12 ( 1 , L_14 ,
V_46 -> V_110 -> V_111 ) ;
exit:
error = F_28 ( V_46 -> V_110 , V_112 ) ;
if ( error )
F_21 ( L_15 , error ) ;
}
static void F_29 ( struct V_103 * V_103 )
{
struct V_45 * V_46 = V_103 -> V_104 ;
int error ;
switch ( V_103 -> V_105 ) {
case 0 :
break;
case - V_106 :
case - V_107 :
case - V_108 :
case - V_109 :
F_27 ( L_16 , V_103 -> V_105 ) ;
return;
default:
F_27 ( L_17 , V_103 -> V_105 ) ;
goto exit;
}
if ( V_46 -> V_113 -> V_111 == 2 )
goto exit;
if ( F_18 ( V_46 , V_46 -> V_113 -> V_111 ) )
F_12 ( 1 , L_18 ,
V_46 -> V_113 -> V_111 ) ;
exit:
error = F_28 ( V_46 -> V_113 , V_112 ) ;
if ( error )
F_21 ( L_19 , error ) ;
}
static int F_30 ( struct V_45 * V_46 )
{
int error ;
error = F_19 ( V_46 , true ) ;
if ( error ) {
F_12 ( 1 , L_20 ) ;
goto V_114;
}
error = F_28 ( V_46 -> V_110 , V_89 ) ;
if ( error )
goto V_115;
error = F_28 ( V_46 -> V_113 , V_89 ) ;
if ( error )
goto V_116;
return 0 ;
V_116:
F_31 ( V_46 -> V_110 ) ;
V_115:
F_19 ( V_46 , false ) ;
V_114:
return error ;
}
static void F_32 ( struct V_45 * V_46 )
{
F_31 ( V_46 -> V_113 ) ;
F_31 ( V_46 -> V_110 ) ;
F_19 ( V_46 , false ) ;
}
static int F_33 ( struct V_19 * V_54 )
{
struct V_45 * V_46 = F_34 ( V_54 ) ;
int error ;
error = F_35 ( V_46 -> V_117 ) ;
if ( error )
return error ;
F_36 ( & V_46 -> V_118 ) ;
error = F_30 ( V_46 ) ;
if ( ! error )
V_46 -> V_119 = 1 ;
F_37 ( & V_46 -> V_118 ) ;
if ( error )
F_38 ( V_46 -> V_117 ) ;
return error ;
}
static void F_39 ( struct V_19 * V_54 )
{
struct V_45 * V_46 = F_34 ( V_54 ) ;
F_36 ( & V_46 -> V_118 ) ;
F_32 ( V_46 ) ;
V_46 -> V_119 = 0 ;
F_37 ( & V_46 -> V_118 ) ;
F_38 ( V_46 -> V_117 ) ;
}
static int F_40 ( struct V_120 * V_121 , T_3 V_122 )
{
struct V_45 * V_46 = F_41 ( V_121 ) ;
F_36 ( & V_46 -> V_118 ) ;
if ( V_46 -> V_119 )
F_32 ( V_46 ) ;
F_37 ( & V_46 -> V_118 ) ;
return 0 ;
}
static int F_42 ( struct V_120 * V_121 )
{
struct V_45 * V_46 = F_41 ( V_121 ) ;
int error = 0 ;
F_36 ( & V_46 -> V_118 ) ;
if ( V_46 -> V_119 )
error = F_30 ( V_46 ) ;
F_37 ( & V_46 -> V_118 ) ;
return error ;
}
static int F_43 ( struct V_120 * V_121 ,
const struct V_123 * V_4 )
{
struct V_2 * V_3 = F_44 ( V_121 ) ;
const struct V_1 * V_7 ;
struct V_45 * V_46 ;
struct V_19 * V_19 ;
int error = - V_91 ;
V_7 = F_1 ( V_3 ) ;
V_46 = F_45 ( sizeof( struct V_45 ) , V_89 ) ;
V_19 = F_46 () ;
if ( ! V_46 || ! V_19 ) {
F_21 ( L_6 ) ;
goto V_124;
}
V_46 -> V_3 = V_3 ;
V_46 -> V_117 = V_121 ;
V_46 -> V_54 = V_19 ;
V_46 -> V_7 = * V_7 ;
F_47 ( & V_46 -> V_118 ) ;
V_46 -> V_110 = F_48 ( 0 , V_89 ) ;
if ( ! V_46 -> V_110 )
goto V_124;
V_46 -> V_113 = F_48 ( 0 , V_89 ) ;
if ( ! V_46 -> V_113 )
goto V_125;
V_46 -> V_48 = F_49 ( V_46 -> V_3 ,
V_46 -> V_7 . V_126 , V_89 ,
& V_46 -> V_110 -> V_127 ) ;
if ( ! V_46 -> V_48 )
goto V_128;
V_46 -> V_80 = F_49 ( V_46 -> V_3 ,
V_46 -> V_7 . V_129 , V_89 ,
& V_46 -> V_113 -> V_127 ) ;
if ( ! V_46 -> V_80 )
goto V_130;
F_50 ( V_46 -> V_110 , V_3 ,
F_51 ( V_3 , V_7 -> V_131 ) ,
V_46 -> V_48 , V_46 -> V_7 . V_126 ,
F_26 , V_46 , 1 ) ;
F_50 ( V_46 -> V_113 , V_3 ,
F_51 ( V_3 , V_7 -> V_132 ) ,
V_46 -> V_80 , V_46 -> V_7 . V_129 ,
F_29 , V_46 , 1 ) ;
F_52 ( V_3 , V_46 -> V_133 , sizeof( V_46 -> V_133 ) ) ;
F_53 ( V_46 -> V_133 , L_21 , sizeof( V_46 -> V_133 ) ) ;
V_19 -> V_134 = L_22 ;
V_19 -> V_133 = V_46 -> V_133 ;
F_54 ( V_46 -> V_3 , & V_19 -> V_4 ) ;
V_19 -> V_4 . V_135 = V_7 -> V_136 ;
V_19 -> V_46 . V_137 = & V_121 -> V_46 ;
F_55 ( V_19 , V_46 ) ;
V_19 -> V_138 = F_33 ;
V_19 -> V_139 = F_39 ;
F_7 ( V_19 , V_7 ) ;
error = F_56 ( V_46 -> V_54 ) ;
if ( error )
goto V_140;
F_57 ( V_121 , V_46 ) ;
return 0 ;
V_140:
F_58 ( V_46 -> V_3 , V_46 -> V_7 . V_129 ,
V_46 -> V_80 , V_46 -> V_113 -> V_127 ) ;
V_130:
F_58 ( V_46 -> V_3 , V_46 -> V_7 . V_126 ,
V_46 -> V_48 , V_46 -> V_110 -> V_127 ) ;
V_128:
F_59 ( V_46 -> V_113 ) ;
V_125:
F_59 ( V_46 -> V_110 ) ;
V_124:
F_57 ( V_121 , NULL ) ;
F_60 ( V_19 ) ;
F_25 ( V_46 ) ;
return error ;
}
static void F_61 ( struct V_120 * V_121 )
{
struct V_45 * V_46 = F_41 ( V_121 ) ;
F_57 ( V_121 , NULL ) ;
F_62 ( V_46 -> V_54 ) ;
F_58 ( V_46 -> V_3 , V_46 -> V_7 . V_129 ,
V_46 -> V_80 , V_46 -> V_113 -> V_127 ) ;
F_58 ( V_46 -> V_3 , V_46 -> V_7 . V_126 ,
V_46 -> V_48 , V_46 -> V_110 -> V_127 ) ;
F_59 ( V_46 -> V_113 ) ;
F_59 ( V_46 -> V_110 ) ;
F_25 ( V_46 ) ;
}
static int T_4 F_63 ( void )
{
return F_64 ( & V_141 ) ;
}
static void T_5 F_65 ( void )
{
F_66 ( & V_141 ) ;
}
