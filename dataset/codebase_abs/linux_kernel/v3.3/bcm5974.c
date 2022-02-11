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
if ( V_7 -> V_45 & V_46 )
F_8 ( V_47 , V_19 -> V_48 ) ;
F_10 ( V_19 , 60 ) ;
}
static int F_11 ( struct V_49 * V_50 , int V_51 )
{
if ( V_51 != sizeof( struct V_52 ) )
return - V_53 ;
F_12 ( 7 ,
L_1 ,
V_50 -> V_52 -> V_54 , V_50 -> V_52 -> V_55 ,
V_50 -> V_52 -> V_56 , V_50 -> V_52 -> V_57 ) ;
F_13 ( V_50 -> V_58 , V_44 , V_50 -> V_52 -> V_55 ) ;
F_14 ( V_50 -> V_58 ) ;
return 0 ;
}
static void F_15 ( struct V_19 * V_58 ,
const struct V_1 * V_7 ,
const struct V_59 * V_60 )
{
F_16 ( V_58 , V_29 ,
F_3 ( V_60 -> V_61 ) << 1 ) ;
F_16 ( V_58 , V_30 ,
F_3 ( V_60 -> V_62 ) << 1 ) ;
F_16 ( V_58 , V_31 ,
F_3 ( V_60 -> V_63 ) << 1 ) ;
F_16 ( V_58 , V_32 ,
F_3 ( V_60 -> V_64 ) << 1 ) ;
F_16 ( V_58 , V_33 ,
V_34 - F_3 ( V_60 -> V_65 ) ) ;
F_16 ( V_58 , V_35 , F_3 ( V_60 -> V_66 ) ) ;
F_16 ( V_58 , V_36 ,
V_7 -> V_28 . V_17 + V_7 -> V_28 . V_16 - F_3 ( V_60 -> V_67 ) ) ;
F_17 ( V_58 ) ;
}
static int F_18 ( struct V_49 * V_50 , int V_51 )
{
const struct V_1 * V_68 = & V_50 -> V_7 ;
const struct V_59 * V_60 ;
struct V_19 * V_58 = V_50 -> V_58 ;
int V_69 , V_70 , V_71 , V_72 , V_73 , V_74 ;
int V_75 , V_76 , V_77 = 0 , V_78 = 0 , V_79 = 0 ;
int V_80 = 0 , V_81 = 0 , V_66 = 0 , V_67 = 0 ;
if ( V_51 < V_68 -> V_82 || ( V_51 - V_68 -> V_82 ) % V_83 != 0 )
return - V_53 ;
V_60 = ( const struct V_59 * ) ( V_50 -> V_84 + V_68 -> V_82 ) ;
V_73 = ( V_51 - V_68 -> V_82 ) / V_83 ;
if ( V_73 ) {
for ( V_74 = 0 ; V_74 < V_73 ; V_74 ++ )
F_15 ( V_58 , V_68 , & V_60 [ V_74 ] ) ;
V_69 = F_3 ( V_60 -> V_61 ) ;
V_70 = F_3 ( V_60 -> V_63 ) ;
V_71 = F_3 ( V_60 -> V_66 ) ;
V_72 = F_3 ( V_60 -> V_67 ) ;
F_12 ( 9 ,
L_2
L_3 ,
V_69 , V_70 , V_71 , V_72 , V_73 ) ;
V_75 = F_5 ( & V_68 -> V_14 , V_69 ) ;
V_76 = F_3 ( V_60 -> V_76 ) ;
if ( V_75 > V_85 && V_76 ) {
V_80 = V_75 ;
V_81 = F_5 ( & V_68 -> V_25 , V_70 ) ;
V_66 = F_5 ( & V_68 -> V_12 , V_71 - V_68 -> V_12 . V_17 ) ;
V_67 = F_5 ( & V_68 -> V_28 , V_68 -> V_28 . V_16 - V_72 ) ;
while ( V_73 -- ) {
V_75 = F_5 ( & V_68 -> V_14 ,
F_3 ( V_60 -> V_61 ) ) ;
if ( V_75 > V_85 )
V_79 ++ ;
if ( V_75 > V_86 )
V_78 ++ ;
V_60 ++ ;
}
}
}
if ( V_68 -> V_87 == V_88 )
V_77 = F_3 ( V_50 -> V_84 [ V_89 ] ) ;
if ( V_50 -> V_90 < V_78 )
V_50 -> V_90 = V_78 ;
if ( V_50 -> V_90 > V_79 )
V_50 -> V_90 = V_79 ;
F_13 ( V_58 , V_38 , V_50 -> V_90 > 0 ) ;
F_13 ( V_58 , V_40 , V_50 -> V_90 == 1 ) ;
F_13 ( V_58 , V_41 , V_50 -> V_90 == 2 ) ;
F_13 ( V_58 , V_42 , V_50 -> V_90 == 3 ) ;
F_13 ( V_58 , V_43 , V_50 -> V_90 > 3 ) ;
F_16 ( V_58 , V_22 , V_80 ) ;
F_16 ( V_58 , V_24 , V_81 ) ;
if ( V_80 ) {
F_16 ( V_58 , V_26 , V_66 ) ;
F_16 ( V_58 , V_27 , V_67 ) ;
F_12 ( 8 ,
L_4
L_5 , V_80 , V_81 ,
V_66 , V_67 , V_78 , V_79 , V_50 -> V_90 , V_77 ) ;
}
if ( V_68 -> V_87 == V_88 )
F_13 ( V_58 , V_44 , V_77 ) ;
F_14 ( V_58 ) ;
return 0 ;
}
static int F_19 ( struct V_49 * V_50 , bool V_91 )
{
char * V_92 = F_20 ( 8 , V_93 ) ;
int V_94 = 0 , V_51 ;
if ( ! V_92 ) {
F_21 ( L_6 ) ;
V_94 = - V_95 ;
goto V_96;
}
V_51 = F_22 ( V_50 -> V_3 , F_23 ( V_50 -> V_3 , 0 ) ,
V_97 ,
V_98 | V_99 | V_100 ,
V_101 ,
V_102 , V_92 , 8 , 5000 ) ;
if ( V_51 != 8 ) {
F_21 ( L_7 ) ;
V_94 = - V_53 ;
goto V_96;
}
V_92 [ 0 ] = V_91 ?
V_103 :
V_104 ;
V_51 = F_22 ( V_50 -> V_3 , F_24 ( V_50 -> V_3 , 0 ) ,
V_105 ,
V_106 | V_99 | V_100 ,
V_101 ,
V_102 , V_92 , 8 , 5000 ) ;
if ( V_51 != 8 ) {
F_21 ( L_8 ) ;
V_94 = - V_53 ;
goto V_96;
}
F_12 ( 2 , L_9 ,
V_91 ? L_10 : L_11 ) ;
V_96:
F_25 ( V_92 ) ;
return V_94 ;
}
static void F_26 ( struct V_107 * V_107 )
{
struct V_49 * V_50 = V_107 -> V_108 ;
int error ;
switch ( V_107 -> V_109 ) {
case 0 :
break;
case - V_110 :
case - V_111 :
case - V_112 :
case - V_113 :
F_27 ( L_12 , V_107 -> V_109 ) ;
return;
default:
F_27 ( L_13 , V_107 -> V_109 ) ;
goto exit;
}
if ( F_11 ( V_50 , V_50 -> V_114 -> V_115 ) )
F_12 ( 1 , L_14 ,
V_50 -> V_114 -> V_115 ) ;
exit:
error = F_28 ( V_50 -> V_114 , V_116 ) ;
if ( error )
F_21 ( L_15 , error ) ;
}
static void F_29 ( struct V_107 * V_107 )
{
struct V_49 * V_50 = V_107 -> V_108 ;
int error ;
switch ( V_107 -> V_109 ) {
case 0 :
break;
case - V_110 :
case - V_111 :
case - V_112 :
case - V_113 :
F_27 ( L_16 , V_107 -> V_109 ) ;
return;
default:
F_27 ( L_17 , V_107 -> V_109 ) ;
goto exit;
}
if ( V_50 -> V_117 -> V_115 == 2 )
goto exit;
if ( F_18 ( V_50 , V_50 -> V_117 -> V_115 ) )
F_12 ( 1 , L_18 ,
V_50 -> V_117 -> V_115 ) ;
exit:
error = F_28 ( V_50 -> V_117 , V_116 ) ;
if ( error )
F_21 ( L_19 , error ) ;
}
static int F_30 ( struct V_49 * V_50 )
{
int error ;
error = F_19 ( V_50 , true ) ;
if ( error ) {
F_12 ( 1 , L_20 ) ;
goto V_118;
}
error = F_28 ( V_50 -> V_114 , V_93 ) ;
if ( error )
goto V_119;
error = F_28 ( V_50 -> V_117 , V_93 ) ;
if ( error )
goto V_120;
return 0 ;
V_120:
F_31 ( V_50 -> V_114 ) ;
V_119:
F_19 ( V_50 , false ) ;
V_118:
return error ;
}
static void F_32 ( struct V_49 * V_50 )
{
F_31 ( V_50 -> V_117 ) ;
F_31 ( V_50 -> V_114 ) ;
F_19 ( V_50 , false ) ;
}
static int F_33 ( struct V_19 * V_58 )
{
struct V_49 * V_50 = F_34 ( V_58 ) ;
int error ;
error = F_35 ( V_50 -> V_121 ) ;
if ( error )
return error ;
F_36 ( & V_50 -> V_122 ) ;
error = F_30 ( V_50 ) ;
if ( ! error )
V_50 -> V_123 = 1 ;
F_37 ( & V_50 -> V_122 ) ;
if ( error )
F_38 ( V_50 -> V_121 ) ;
return error ;
}
static void F_39 ( struct V_19 * V_58 )
{
struct V_49 * V_50 = F_34 ( V_58 ) ;
F_36 ( & V_50 -> V_122 ) ;
F_32 ( V_50 ) ;
V_50 -> V_123 = 0 ;
F_37 ( & V_50 -> V_122 ) ;
F_38 ( V_50 -> V_121 ) ;
}
static int F_40 ( struct V_124 * V_125 , T_3 V_126 )
{
struct V_49 * V_50 = F_41 ( V_125 ) ;
F_36 ( & V_50 -> V_122 ) ;
if ( V_50 -> V_123 )
F_32 ( V_50 ) ;
F_37 ( & V_50 -> V_122 ) ;
return 0 ;
}
static int F_42 ( struct V_124 * V_125 )
{
struct V_49 * V_50 = F_41 ( V_125 ) ;
int error = 0 ;
F_36 ( & V_50 -> V_122 ) ;
if ( V_50 -> V_123 )
error = F_30 ( V_50 ) ;
F_37 ( & V_50 -> V_122 ) ;
return error ;
}
static int F_43 ( struct V_124 * V_125 ,
const struct V_127 * V_4 )
{
struct V_2 * V_3 = F_44 ( V_125 ) ;
const struct V_1 * V_7 ;
struct V_49 * V_50 ;
struct V_19 * V_19 ;
int error = - V_95 ;
V_7 = F_1 ( V_3 ) ;
V_50 = F_45 ( sizeof( struct V_49 ) , V_93 ) ;
V_19 = F_46 () ;
if ( ! V_50 || ! V_19 ) {
F_21 ( L_6 ) ;
goto V_128;
}
V_50 -> V_3 = V_3 ;
V_50 -> V_121 = V_125 ;
V_50 -> V_58 = V_19 ;
V_50 -> V_7 = * V_7 ;
F_47 ( & V_50 -> V_122 ) ;
V_50 -> V_114 = F_48 ( 0 , V_93 ) ;
if ( ! V_50 -> V_114 )
goto V_128;
V_50 -> V_117 = F_48 ( 0 , V_93 ) ;
if ( ! V_50 -> V_117 )
goto V_129;
V_50 -> V_52 = F_49 ( V_50 -> V_3 ,
V_50 -> V_7 . V_130 , V_93 ,
& V_50 -> V_114 -> V_131 ) ;
if ( ! V_50 -> V_52 )
goto V_132;
V_50 -> V_84 = F_49 ( V_50 -> V_3 ,
V_50 -> V_7 . V_133 , V_93 ,
& V_50 -> V_117 -> V_131 ) ;
if ( ! V_50 -> V_84 )
goto V_134;
F_50 ( V_50 -> V_114 , V_3 ,
F_51 ( V_3 , V_7 -> V_135 ) ,
V_50 -> V_52 , V_50 -> V_7 . V_130 ,
F_26 , V_50 , 1 ) ;
F_50 ( V_50 -> V_117 , V_3 ,
F_51 ( V_3 , V_7 -> V_136 ) ,
V_50 -> V_84 , V_50 -> V_7 . V_133 ,
F_29 , V_50 , 1 ) ;
F_52 ( V_3 , V_50 -> V_137 , sizeof( V_50 -> V_137 ) ) ;
F_53 ( V_50 -> V_137 , L_21 , sizeof( V_50 -> V_137 ) ) ;
V_19 -> V_138 = L_22 ;
V_19 -> V_137 = V_50 -> V_137 ;
F_54 ( V_50 -> V_3 , & V_19 -> V_4 ) ;
V_19 -> V_4 . V_139 = V_7 -> V_45 ;
V_19 -> V_50 . V_140 = & V_125 -> V_50 ;
F_55 ( V_19 , V_50 ) ;
V_19 -> V_141 = F_33 ;
V_19 -> V_142 = F_39 ;
F_7 ( V_19 , V_7 ) ;
error = F_56 ( V_50 -> V_58 ) ;
if ( error )
goto V_143;
F_57 ( V_125 , V_50 ) ;
return 0 ;
V_143:
F_58 ( V_50 -> V_3 , V_50 -> V_7 . V_133 ,
V_50 -> V_84 , V_50 -> V_117 -> V_131 ) ;
V_134:
F_58 ( V_50 -> V_3 , V_50 -> V_7 . V_130 ,
V_50 -> V_52 , V_50 -> V_114 -> V_131 ) ;
V_132:
F_59 ( V_50 -> V_117 ) ;
V_129:
F_59 ( V_50 -> V_114 ) ;
V_128:
F_57 ( V_125 , NULL ) ;
F_60 ( V_19 ) ;
F_25 ( V_50 ) ;
return error ;
}
static void F_61 ( struct V_124 * V_125 )
{
struct V_49 * V_50 = F_41 ( V_125 ) ;
F_57 ( V_125 , NULL ) ;
F_62 ( V_50 -> V_58 ) ;
F_58 ( V_50 -> V_3 , V_50 -> V_7 . V_133 ,
V_50 -> V_84 , V_50 -> V_117 -> V_131 ) ;
F_58 ( V_50 -> V_3 , V_50 -> V_7 . V_130 ,
V_50 -> V_52 , V_50 -> V_114 -> V_131 ) ;
F_59 ( V_50 -> V_117 ) ;
F_59 ( V_50 -> V_114 ) ;
F_25 ( V_50 ) ;
}
