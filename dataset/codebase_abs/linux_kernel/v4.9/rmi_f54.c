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
return error ;
F_9 ( & V_2 -> V_29 ) ;
V_2 -> V_30 = 1 ;
V_2 -> V_31 = V_32 + F_10 ( 100 ) ;
F_11 ( V_2 -> V_33 , & V_2 -> V_34 , 0 ) ;
F_12 ( & V_2 -> V_26 ) ;
return 0 ;
}
static T_2 F_13 ( struct V_1 * V_2 )
{
T_1 V_35 = V_2 -> V_36 ? : V_2 -> V_36 ;
T_1 V_37 = V_2 -> V_38 ? : V_2 -> V_38 ;
T_2 V_39 ;
switch ( F_2 ( V_2 , V_2 -> V_40 ) ) {
case V_5 :
V_39 = V_35 * V_37 ;
break;
case V_8 :
case V_9 :
case V_11 :
case V_12 :
case V_13 :
V_39 = sizeof( V_41 ) * V_35 * V_37 ;
break;
default:
V_39 = 0 ;
}
return V_39 ;
}
static int F_14 ( enum V_3 V_4 , T_3 * V_42 )
{
int V_43 = 0 ;
switch ( V_4 ) {
case V_5 :
* V_42 = V_44 ;
break;
case V_8 :
* V_42 = V_45 ;
break;
case V_9 :
case V_11 :
case V_12 :
case V_13 :
* V_42 = V_46 ;
break;
case V_16 :
case V_15 :
V_43 = - V_47 ;
break;
}
return V_43 ;
}
static int F_15 ( struct V_48 * V_49 , unsigned int * V_50 ,
unsigned int * V_51 , unsigned int V_52 [] ,
struct V_53 * V_54 [] )
{
struct V_1 * V_2 = V_49 -> V_55 ;
if ( * V_51 )
return V_52 [ 0 ] < F_13 ( V_2 ) ? - V_47 : 0 ;
* V_51 = 1 ;
V_52 [ 0 ] = F_13 ( V_2 ) ;
return 0 ;
}
static void F_16 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = F_17 ( V_57 -> V_48 ) ;
V_41 * V_58 ;
enum V_59 V_60 ;
enum V_3 V_4 ;
int V_43 ;
F_8 ( & V_2 -> V_61 ) ;
V_4 = F_2 ( V_2 , V_2 -> V_40 ) ;
if ( V_4 == V_16 ) {
V_60 = V_62 ;
goto V_63;
}
if ( V_2 -> V_30 ) {
V_60 = V_62 ;
goto V_63;
}
V_43 = F_4 ( V_2 -> V_19 , V_4 ) ;
if ( V_43 ) {
F_18 ( & V_2 -> V_19 -> V_21 , L_1 ) ;
V_60 = V_62 ;
goto V_63;
}
F_8 ( & V_2 -> V_26 ) ;
while ( V_2 -> V_30 ) {
F_12 ( & V_2 -> V_26 ) ;
if ( ! F_19 ( & V_2 -> V_29 ,
F_10 ( 1000 ) ) ) {
F_18 ( & V_2 -> V_19 -> V_21 , L_2 ) ;
V_60 = V_62 ;
goto V_63;
}
F_8 ( & V_2 -> V_26 ) ;
}
V_58 = F_20 ( V_57 , 0 ) ;
if ( ! V_58 ) {
F_18 ( & V_2 -> V_19 -> V_21 , L_3 ) ;
V_60 = V_62 ;
goto V_64;
}
memcpy ( V_58 , V_2 -> V_65 , V_2 -> V_66 ) ;
F_21 ( V_57 , 0 , F_13 ( V_2 ) ) ;
V_60 = V_67 ;
V_64:
F_12 ( & V_2 -> V_26 ) ;
V_63:
F_22 ( V_57 , V_60 ) ;
F_12 ( & V_2 -> V_61 ) ;
}
static int F_23 ( struct V_68 * V_68 , void * V_69 ,
struct V_70 * V_71 )
{
struct V_1 * V_2 = F_24 ( V_68 ) ;
F_25 ( V_71 -> V_72 , V_73 , sizeof( V_71 -> V_72 ) ) ;
F_25 ( V_71 -> V_74 , V_75 , sizeof( V_71 -> V_74 ) ) ;
snprintf ( V_71 -> V_76 , sizeof( V_71 -> V_76 ) ,
L_4 , F_26 ( & V_2 -> V_19 -> V_21 ) ) ;
return 0 ;
}
static int F_27 ( struct V_68 * V_68 , void * V_69 ,
struct V_77 * V_14 )
{
struct V_1 * V_2 = F_24 ( V_68 ) ;
enum V_3 V_4 ;
V_4 = F_2 ( V_2 , V_14 -> V_78 ) ;
if ( V_4 == V_16 )
return - V_47 ;
V_14 -> type = V_79 ;
F_25 ( V_14 -> V_80 , V_81 [ V_4 ] , sizeof( V_14 -> V_80 ) ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , unsigned int V_14 )
{
struct V_82 * V_83 = & V_2 -> V_84 ;
enum V_3 V_4 ;
int V_43 ;
V_4 = F_2 ( V_2 , V_14 ) ;
if ( V_4 == V_16 )
return - V_47 ;
V_43 = F_14 ( V_4 , & V_83 -> V_85 ) ;
if ( V_43 )
return V_43 ;
V_2 -> V_40 = V_14 ;
V_83 -> V_86 = V_2 -> V_36 ;
V_83 -> V_87 = V_2 -> V_38 ;
V_83 -> V_88 = V_89 ;
V_83 -> V_90 = V_91 ;
V_83 -> V_92 = V_83 -> V_86 * sizeof( V_41 ) ;
V_83 -> V_93 = V_83 -> V_86 * V_83 -> V_87 * sizeof( V_41 ) ;
return 0 ;
}
static int F_29 ( struct V_68 * V_68 , void * V_69 , unsigned int V_14 )
{
return F_28 ( F_24 ( V_68 ) , V_14 ) ;
}
static int F_30 ( struct V_68 * V_68 , void * V_69 ,
unsigned int * V_14 )
{
struct V_1 * V_2 = F_24 ( V_68 ) ;
* V_14 = V_2 -> V_40 ;
return 0 ;
}
static int F_31 ( struct V_68 * V_68 , void * V_69 ,
struct V_94 * V_83 )
{
struct V_1 * V_2 = F_24 ( V_68 ) ;
V_83 -> V_95 . V_96 = V_2 -> V_84 ;
return 0 ;
}
static int F_32 ( struct V_68 * V_68 , void * V_69 ,
struct V_97 * V_95 )
{
if ( V_95 -> type != V_98 )
return - V_47 ;
switch ( V_95 -> V_78 ) {
case 0 :
V_95 -> V_85 = V_45 ;
break;
case 1 :
V_95 -> V_85 = V_44 ;
break;
case 2 :
V_95 -> V_85 = V_46 ;
break;
default:
return - V_47 ;
}
return 0 ;
}
static int F_33 ( struct V_68 * V_68 , void * V_99 ,
struct V_100 * V_101 )
{
if ( V_101 -> type != V_98 )
return - V_47 ;
V_101 -> V_102 . V_103 . V_104 = 1 ;
V_101 -> V_102 . V_103 . V_105 . V_106 = 1 ;
V_101 -> V_102 . V_103 . V_105 . V_107 = 10 ;
return 0 ;
}
static void F_34 ( struct V_108 * V_34 )
{
struct V_1 * V_2 = F_35 ( V_34 , struct V_1 , V_34 . V_34 ) ;
struct V_18 * V_19 = V_2 -> V_19 ;
T_1 V_109 [ 2 ] ;
struct V_110 * V_111 ;
int V_66 ;
T_1 V_112 ;
T_1 * V_113 ;
int error ;
V_113 = V_2 -> V_65 ;
V_66 = F_13 ( V_2 ) ;
if ( V_66 == 0 ) {
F_18 ( & V_19 -> V_21 , L_5 ,
V_2 -> V_20 ) ;
error = - V_47 ;
goto error;
}
V_2 -> V_114 [ 0 ] . V_39 = V_66 ;
V_111 = V_2 -> V_114 ;
F_8 ( & V_2 -> V_26 ) ;
error = F_36 ( V_19 -> V_23 , V_2 -> V_19 -> V_24 . V_27 ,
& V_112 ) ;
if ( error ) {
F_18 ( & V_19 -> V_21 , L_6 ) ;
goto error;
}
if ( V_112 & V_28 ) {
if ( F_37 ( V_32 , V_2 -> V_31 ) ) {
F_18 ( & V_19 -> V_21 , L_7 ) ;
error = - V_115 ;
}
V_66 = 0 ;
goto error;
}
F_38 ( V_116 , & V_19 -> V_21 , L_8 ) ;
V_66 = 0 ;
for (; V_111 -> V_39 ; V_111 ++ ) {
V_109 [ 0 ] = V_111 -> V_117 & 0xff ;
V_109 [ 1 ] = ( V_111 -> V_117 >> 8 ) & 0xff ;
error = F_39 ( V_19 -> V_23 ,
V_19 -> V_24 . V_25 + V_118 ,
V_109 , sizeof( V_109 ) ) ;
if ( error ) {
F_18 ( & V_19 -> V_21 , L_9 ) ;
goto abort;
}
error = F_40 ( V_19 -> V_23 , V_19 -> V_24 . V_25 +
V_119 , V_113 ,
V_111 -> V_39 ) ;
if ( error ) {
F_18 ( & V_19 -> V_21 , L_10 ,
V_120 , V_111 -> V_39 , error ) ;
goto abort;
}
V_113 += V_111 -> V_39 ;
V_66 += V_111 -> V_39 ;
}
abort:
V_2 -> V_66 = error ? 0 : V_66 ;
error:
if ( error )
V_66 = 0 ;
if ( V_66 == 0 && ! error ) {
F_11 ( V_2 -> V_33 , & V_2 -> V_34 ,
F_10 ( 1 ) ) ;
} else {
V_2 -> V_30 = false ;
F_41 ( & V_2 -> V_29 ) ;
}
F_12 ( & V_2 -> V_26 ) ;
}
static int F_42 ( struct V_18 * V_19 , unsigned long * V_121 )
{
return 0 ;
}
static int F_43 ( struct V_18 * V_19 )
{
struct V_122 * V_123 = V_19 -> V_23 -> V_72 ;
V_123 -> V_124 ( V_19 -> V_23 , V_19 -> V_125 ) ;
return 0 ;
}
static int F_44 ( struct V_18 * V_19 )
{
int error ;
struct V_1 * V_2 ;
V_2 = F_5 ( & V_19 -> V_21 ) ;
error = F_40 ( V_19 -> V_23 , V_19 -> V_24 . V_126 ,
& V_2 -> V_127 , sizeof( V_2 -> V_127 ) ) ;
if ( error ) {
F_18 ( & V_19 -> V_21 , L_11 ,
V_120 ) ;
return error ;
}
V_2 -> V_36 = V_2 -> V_127 [ 0 ] ;
V_2 -> V_38 = V_2 -> V_127 [ 1 ] ;
V_2 -> V_6 = V_2 -> V_127 [ 2 ] ;
V_2 -> V_128 = V_2 -> V_127 [ 3 ] | ( V_2 -> V_127 [ 4 ] << 8 ) ;
V_2 -> V_129 = V_2 -> V_127 [ 5 ] ;
F_38 ( V_116 , & V_19 -> V_21 , L_12 ,
V_2 -> V_36 ) ;
F_38 ( V_116 , & V_19 -> V_21 , L_13 ,
V_2 -> V_38 ) ;
F_38 ( V_116 , & V_19 -> V_21 , L_14 ,
V_2 -> V_6 ) ;
F_38 ( V_116 , & V_19 -> V_21 , L_15 ,
V_2 -> V_128 ) ;
F_38 ( V_116 , & V_19 -> V_21 , L_16 ,
V_2 -> V_129 ) ;
V_2 -> V_30 = false ;
return 0 ;
}
static int F_45 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
int V_43 ;
T_1 V_35 , V_37 ;
V_2 = F_46 ( & V_19 -> V_21 , sizeof( struct V_1 ) , V_130 ) ;
if ( ! V_2 )
return - V_131 ;
V_2 -> V_19 = V_19 ;
F_47 ( & V_19 -> V_21 , V_2 ) ;
V_43 = F_44 ( V_19 ) ;
if ( V_43 )
return V_43 ;
F_48 ( & V_2 -> V_26 ) ;
F_48 ( & V_2 -> V_61 ) ;
V_35 = V_2 -> V_36 ;
V_37 = V_2 -> V_38 ;
V_2 -> V_65 = F_46 ( & V_19 -> V_21 ,
sizeof( V_41 ) * V_37 * V_35 ,
V_130 ) ;
if ( V_2 -> V_65 == NULL )
return - V_131 ;
F_49 ( & V_2 -> V_34 , F_34 ) ;
V_2 -> V_33 = F_50 ( L_17 ) ;
if ( ! V_2 -> V_33 )
return - V_131 ;
F_3 ( V_2 ) ;
F_25 ( V_2 -> V_132 . V_80 , V_73 , sizeof( V_2 -> V_132 . V_80 ) ) ;
V_43 = F_51 ( & V_19 -> V_21 , & V_2 -> V_132 ) ;
if ( V_43 ) {
F_18 ( & V_19 -> V_21 , L_18 ) ;
goto V_133;
}
F_48 ( & V_2 -> V_134 ) ;
V_2 -> V_135 = V_136 ;
V_2 -> V_135 . V_55 = V_2 ;
V_2 -> V_135 . V_134 = & V_2 -> V_134 ;
V_2 -> V_135 . V_21 = & V_19 -> V_21 ;
V_43 = F_52 ( & V_2 -> V_135 ) ;
if ( V_43 )
goto V_137;
V_2 -> V_138 = V_139 ;
V_2 -> V_138 . V_140 = & V_2 -> V_132 ;
V_2 -> V_138 . V_134 = & V_2 -> V_134 ;
V_2 -> V_138 . V_141 = V_142 ;
V_2 -> V_138 . V_135 = & V_2 -> V_135 ;
F_53 ( & V_2 -> V_138 , V_2 ) ;
V_43 = F_54 ( & V_2 -> V_138 , V_143 , - 1 ) ;
if ( V_43 ) {
F_18 ( & V_19 -> V_21 , L_19 ) ;
goto V_137;
}
return 0 ;
V_137:
F_55 ( & V_2 -> V_132 ) ;
V_133:
F_56 ( & V_2 -> V_34 ) ;
F_57 ( V_2 -> V_33 ) ;
F_58 ( V_2 -> V_33 ) ;
return V_43 ;
}
static void F_59 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_5 ( & V_19 -> V_21 ) ;
F_60 ( & V_2 -> V_138 ) ;
F_55 ( & V_2 -> V_132 ) ;
}
