static bool F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
switch ( V_4 ) {
case V_5 :
return V_2 -> V_6 & V_7 ;
case V_8 :
case V_9 :
return V_2 -> V_6 & V_10 ;
case V_11 :
return V_2 -> V_6 & V_10 ;
case V_12 :
case V_13 :
return true ;
default:
return false ;
}
}
static enum V_3 F_2 ( struct V_1 * V_2 ,
unsigned int V_14 )
{
if ( V_14 >= V_15 )
return V_16 ;
return V_2 -> V_17 [ V_14 ] ;
}
static void F_3 ( struct V_1 * V_2 )
{
int V_14 = 0 ;
enum V_3 V_4 ;
for ( V_4 = 1 ; V_4 < V_15 ; V_4 ++ ) {
if ( ! F_1 ( V_2 , V_4 ) )
continue;
V_2 -> V_17 [ V_14 ++ ] = V_4 ;
}
}
static int F_4 ( struct V_18 * V_19 , T_1 V_20 )
{
struct V_1 * V_2 = F_5 ( & V_19 -> V_21 ) ;
struct V_22 * V_23 = V_19 -> V_23 ;
int error ;
if ( V_2 -> V_20 != V_20 ) {
error = F_6 ( V_23 , V_2 -> V_19 -> V_24 . V_25 ,
V_20 ) ;
if ( error )
return error ;
V_2 -> V_20 = V_20 ;
}
F_7 ( 2000 , 3000 ) ;
F_8 ( & V_2 -> V_26 ) ;
error = F_6 ( V_23 , V_19 -> V_24 . V_27 , V_28 ) ;
if ( error < 0 )
goto V_29;
F_9 ( & V_2 -> V_30 ) ;
V_2 -> V_31 = 1 ;
V_2 -> V_32 = V_33 + F_10 ( 100 ) ;
F_11 ( V_2 -> V_34 , & V_2 -> V_35 , 0 ) ;
V_29:
F_12 ( & V_2 -> V_26 ) ;
return error ;
}
static T_2 F_13 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_19 -> V_23 ;
struct V_36 * V_37 = F_5 ( & V_23 -> V_21 ) ;
T_1 V_38 = V_37 -> V_39 ? : V_2 -> V_39 ;
T_1 V_40 = V_37 -> V_41 ? : V_2 -> V_41 ;
T_2 V_42 ;
switch ( F_2 ( V_2 , V_2 -> V_43 ) ) {
case V_5 :
V_42 = V_38 * V_40 ;
break;
case V_8 :
case V_9 :
case V_11 :
case V_12 :
case V_13 :
V_42 = sizeof( V_44 ) * V_38 * V_40 ;
break;
default:
V_42 = 0 ;
}
return V_42 ;
}
static int F_14 ( enum V_3 V_4 , T_3 * V_45 )
{
int V_46 = 0 ;
switch ( V_4 ) {
case V_5 :
* V_45 = V_47 ;
break;
case V_8 :
* V_45 = V_48 ;
break;
case V_9 :
case V_11 :
case V_12 :
case V_13 :
* V_45 = V_49 ;
break;
case V_16 :
case V_15 :
V_46 = - V_50 ;
break;
}
return V_46 ;
}
static int F_15 ( struct V_51 * V_52 , unsigned int * V_53 ,
unsigned int * V_54 , unsigned int V_55 [] ,
struct V_56 * V_57 [] )
{
struct V_1 * V_2 = V_52 -> V_58 ;
if ( * V_54 )
return V_55 [ 0 ] < F_13 ( V_2 ) ? - V_50 : 0 ;
* V_54 = 1 ;
V_55 [ 0 ] = F_13 ( V_2 ) ;
return 0 ;
}
static void F_16 ( struct V_59 * V_60 )
{
struct V_1 * V_2 = F_17 ( V_60 -> V_51 ) ;
V_44 * V_61 ;
enum V_62 V_63 ;
enum V_3 V_4 ;
int V_46 ;
F_8 ( & V_2 -> V_64 ) ;
V_4 = F_2 ( V_2 , V_2 -> V_43 ) ;
if ( V_4 == V_16 ) {
V_63 = V_65 ;
goto V_66;
}
if ( V_2 -> V_31 ) {
V_63 = V_65 ;
goto V_66;
}
V_46 = F_4 ( V_2 -> V_19 , V_4 ) ;
if ( V_46 ) {
F_18 ( & V_2 -> V_19 -> V_21 , L_1 ) ;
V_63 = V_65 ;
goto V_66;
}
F_8 ( & V_2 -> V_26 ) ;
while ( V_2 -> V_31 ) {
F_12 ( & V_2 -> V_26 ) ;
if ( ! F_19 ( & V_2 -> V_30 ,
F_10 ( 1000 ) ) ) {
F_18 ( & V_2 -> V_19 -> V_21 , L_2 ) ;
V_63 = V_65 ;
goto V_66;
}
F_8 ( & V_2 -> V_26 ) ;
}
V_61 = F_20 ( V_60 , 0 ) ;
if ( ! V_61 ) {
F_18 ( & V_2 -> V_19 -> V_21 , L_3 ) ;
V_63 = V_65 ;
goto V_67;
}
memcpy ( V_61 , V_2 -> V_68 , V_2 -> V_69 ) ;
F_21 ( V_60 , 0 , F_13 ( V_2 ) ) ;
V_63 = V_70 ;
V_67:
F_12 ( & V_2 -> V_26 ) ;
V_66:
F_22 ( V_60 , V_63 ) ;
F_12 ( & V_2 -> V_64 ) ;
}
static int F_23 ( struct V_71 * V_71 , void * V_72 ,
struct V_73 * V_74 )
{
struct V_1 * V_2 = F_24 ( V_71 ) ;
F_25 ( V_74 -> V_75 , V_76 , sizeof( V_74 -> V_75 ) ) ;
F_25 ( V_74 -> V_77 , V_78 , sizeof( V_74 -> V_77 ) ) ;
snprintf ( V_74 -> V_79 , sizeof( V_74 -> V_79 ) ,
L_4 , F_26 ( & V_2 -> V_19 -> V_21 ) ) ;
return 0 ;
}
static int F_27 ( struct V_71 * V_71 , void * V_72 ,
struct V_80 * V_14 )
{
struct V_1 * V_2 = F_24 ( V_71 ) ;
enum V_3 V_4 ;
V_4 = F_2 ( V_2 , V_14 -> V_81 ) ;
if ( V_4 == V_16 )
return - V_50 ;
V_14 -> type = V_82 ;
F_25 ( V_14 -> V_83 , V_84 [ V_4 ] , sizeof( V_14 -> V_83 ) ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , unsigned int V_14 )
{
struct V_22 * V_23 = V_2 -> V_19 -> V_23 ;
struct V_36 * V_37 = F_5 ( & V_23 -> V_21 ) ;
T_1 V_38 = V_37 -> V_39 ? : V_2 -> V_39 ;
T_1 V_40 = V_37 -> V_41 ? : V_2 -> V_41 ;
struct V_85 * V_86 = & V_2 -> V_87 ;
enum V_3 V_4 ;
int V_46 ;
V_4 = F_2 ( V_2 , V_14 ) ;
if ( V_4 == V_16 )
return - V_50 ;
V_46 = F_14 ( V_4 , & V_86 -> V_88 ) ;
if ( V_46 )
return V_46 ;
V_2 -> V_43 = V_14 ;
V_86 -> V_89 = V_38 ;
V_86 -> V_90 = V_40 ;
V_86 -> V_91 = V_92 ;
V_86 -> V_93 = V_94 ;
V_86 -> V_95 = V_86 -> V_89 * sizeof( V_44 ) ;
V_86 -> V_96 = V_86 -> V_89 * V_86 -> V_90 * sizeof( V_44 ) ;
return 0 ;
}
static int F_29 ( struct V_71 * V_71 , void * V_72 , unsigned int V_14 )
{
return F_28 ( F_24 ( V_71 ) , V_14 ) ;
}
static int F_30 ( struct V_71 * V_71 , void * V_72 ,
unsigned int * V_14 )
{
struct V_1 * V_2 = F_24 ( V_71 ) ;
* V_14 = V_2 -> V_43 ;
return 0 ;
}
static int F_31 ( struct V_71 * V_71 , void * V_72 ,
struct V_97 * V_86 )
{
struct V_1 * V_2 = F_24 ( V_71 ) ;
V_86 -> V_98 . V_99 = V_2 -> V_87 ;
return 0 ;
}
static int F_32 ( struct V_71 * V_71 , void * V_72 ,
struct V_100 * V_98 )
{
if ( V_98 -> type != V_101 )
return - V_50 ;
switch ( V_98 -> V_81 ) {
case 0 :
V_98 -> V_88 = V_48 ;
break;
case 1 :
V_98 -> V_88 = V_47 ;
break;
case 2 :
V_98 -> V_88 = V_49 ;
break;
default:
return - V_50 ;
}
return 0 ;
}
static int F_33 ( struct V_71 * V_71 , void * V_102 ,
struct V_103 * V_104 )
{
if ( V_104 -> type != V_101 )
return - V_50 ;
V_104 -> V_105 . V_106 . V_107 = 1 ;
V_104 -> V_105 . V_106 . V_108 . V_109 = 1 ;
V_104 -> V_105 . V_106 . V_108 . V_110 = 10 ;
return 0 ;
}
static void F_34 ( struct V_111 * V_35 )
{
struct V_1 * V_2 = F_35 ( V_35 , struct V_1 , V_35 . V_35 ) ;
struct V_18 * V_19 = V_2 -> V_19 ;
T_1 V_112 [ 2 ] ;
struct V_113 * V_114 ;
int V_69 ;
T_1 V_115 ;
T_1 * V_116 ;
int error ;
V_116 = V_2 -> V_68 ;
V_69 = F_13 ( V_2 ) ;
if ( V_69 == 0 ) {
F_18 ( & V_19 -> V_21 , L_5 ,
V_2 -> V_20 ) ;
error = - V_50 ;
goto error;
}
V_2 -> V_117 [ 0 ] . V_42 = V_69 ;
V_114 = V_2 -> V_117 ;
F_8 ( & V_2 -> V_26 ) ;
error = F_36 ( V_19 -> V_23 , V_2 -> V_19 -> V_24 . V_27 ,
& V_115 ) ;
if ( error ) {
F_18 ( & V_19 -> V_21 , L_6 ) ;
goto error;
}
if ( V_115 & V_28 ) {
if ( F_37 ( V_33 , V_2 -> V_32 ) ) {
F_18 ( & V_19 -> V_21 , L_7 ) ;
error = - V_118 ;
}
V_69 = 0 ;
goto error;
}
F_38 ( V_119 , & V_19 -> V_21 , L_8 ) ;
V_69 = 0 ;
for (; V_114 -> V_42 ; V_114 ++ ) {
V_112 [ 0 ] = V_114 -> V_120 & 0xff ;
V_112 [ 1 ] = ( V_114 -> V_120 >> 8 ) & 0xff ;
error = F_39 ( V_19 -> V_23 ,
V_19 -> V_24 . V_25 + V_121 ,
V_112 , sizeof( V_112 ) ) ;
if ( error ) {
F_18 ( & V_19 -> V_21 , L_9 ) ;
goto abort;
}
error = F_40 ( V_19 -> V_23 , V_19 -> V_24 . V_25 +
V_122 , V_116 ,
V_114 -> V_42 ) ;
if ( error ) {
F_18 ( & V_19 -> V_21 , L_10 ,
V_123 , V_114 -> V_42 , error ) ;
goto abort;
}
V_116 += V_114 -> V_42 ;
V_69 += V_114 -> V_42 ;
}
abort:
V_2 -> V_69 = error ? 0 : V_69 ;
error:
if ( error )
V_69 = 0 ;
if ( V_69 == 0 && ! error ) {
F_11 ( V_2 -> V_34 , & V_2 -> V_35 ,
F_10 ( 1 ) ) ;
} else {
V_2 -> V_31 = false ;
F_41 ( & V_2 -> V_30 ) ;
}
F_12 ( & V_2 -> V_26 ) ;
}
static int F_42 ( struct V_18 * V_19 , unsigned long * V_124 )
{
return 0 ;
}
static int F_43 ( struct V_18 * V_19 )
{
struct V_125 * V_126 = V_19 -> V_23 -> V_75 ;
V_126 -> V_127 ( V_19 -> V_23 , V_19 -> V_128 ) ;
return 0 ;
}
static int F_44 ( struct V_18 * V_19 )
{
int error ;
struct V_1 * V_2 ;
T_1 V_129 [ 6 ] ;
V_2 = F_5 ( & V_19 -> V_21 ) ;
error = F_40 ( V_19 -> V_23 , V_19 -> V_24 . V_130 ,
V_129 , sizeof( V_129 ) ) ;
if ( error ) {
F_18 ( & V_19 -> V_21 , L_11 ,
V_123 ) ;
return error ;
}
V_2 -> V_39 = V_129 [ 0 ] ;
V_2 -> V_41 = V_129 [ 1 ] ;
V_2 -> V_6 = V_129 [ 2 ] ;
V_2 -> V_131 = V_129 [ 3 ] | ( V_129 [ 4 ] << 8 ) ;
V_2 -> V_132 = V_129 [ 5 ] ;
F_38 ( V_119 , & V_19 -> V_21 , L_12 ,
V_2 -> V_39 ) ;
F_38 ( V_119 , & V_19 -> V_21 , L_13 ,
V_2 -> V_41 ) ;
F_38 ( V_119 , & V_19 -> V_21 , L_14 ,
V_2 -> V_6 ) ;
F_38 ( V_119 , & V_19 -> V_21 , L_15 ,
V_2 -> V_131 ) ;
F_38 ( V_119 , & V_19 -> V_21 , L_16 ,
V_2 -> V_132 ) ;
V_2 -> V_31 = false ;
return 0 ;
}
static int F_45 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
int V_46 ;
T_1 V_38 , V_40 ;
V_2 = F_46 ( & V_19 -> V_21 , sizeof( struct V_1 ) , V_133 ) ;
if ( ! V_2 )
return - V_134 ;
V_2 -> V_19 = V_19 ;
F_47 ( & V_19 -> V_21 , V_2 ) ;
V_46 = F_44 ( V_19 ) ;
if ( V_46 )
return V_46 ;
F_48 ( & V_2 -> V_26 ) ;
F_48 ( & V_2 -> V_64 ) ;
V_38 = V_2 -> V_39 ;
V_40 = V_2 -> V_41 ;
V_2 -> V_68 = F_46 ( & V_19 -> V_21 ,
sizeof( V_44 ) * V_40 * V_38 ,
V_133 ) ;
if ( V_2 -> V_68 == NULL )
return - V_134 ;
F_49 ( & V_2 -> V_35 , F_34 ) ;
V_2 -> V_34 = F_50 ( L_17 ) ;
if ( ! V_2 -> V_34 )
return - V_134 ;
F_3 ( V_2 ) ;
F_25 ( V_2 -> V_135 . V_83 , V_76 , sizeof( V_2 -> V_135 . V_83 ) ) ;
V_46 = F_51 ( & V_19 -> V_21 , & V_2 -> V_135 ) ;
if ( V_46 ) {
F_18 ( & V_19 -> V_21 , L_18 ) ;
goto V_136;
}
F_48 ( & V_2 -> V_137 ) ;
V_2 -> V_138 = V_139 ;
V_2 -> V_138 . V_58 = V_2 ;
V_2 -> V_138 . V_137 = & V_2 -> V_137 ;
V_2 -> V_138 . V_21 = & V_19 -> V_21 ;
V_46 = F_52 ( & V_2 -> V_138 ) ;
if ( V_46 )
goto V_140;
V_2 -> V_141 = V_142 ;
V_2 -> V_141 . V_143 = & V_2 -> V_135 ;
V_2 -> V_141 . V_137 = & V_2 -> V_137 ;
V_2 -> V_141 . V_144 = V_145 ;
V_2 -> V_141 . V_138 = & V_2 -> V_138 ;
F_53 ( & V_2 -> V_141 , V_2 ) ;
V_46 = F_54 ( & V_2 -> V_141 , V_146 , - 1 ) ;
if ( V_46 ) {
F_18 ( & V_19 -> V_21 , L_19 ) ;
goto V_140;
}
return 0 ;
V_140:
F_55 ( & V_2 -> V_135 ) ;
V_136:
F_56 ( & V_2 -> V_35 ) ;
F_57 ( V_2 -> V_34 ) ;
F_58 ( V_2 -> V_34 ) ;
return V_46 ;
}
static void F_59 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_5 ( & V_19 -> V_21 ) ;
F_60 ( & V_2 -> V_141 ) ;
F_55 ( & V_2 -> V_135 ) ;
}
