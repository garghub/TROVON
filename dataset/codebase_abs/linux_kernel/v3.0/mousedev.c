static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_3 ,
unsigned int V_4 , int V_5 )
{
int V_6 , V_7 ;
enum { V_8 = 128 };
switch ( V_4 ) {
case V_9 :
F_2 ( 0 ) = V_5 ;
if ( V_3 -> V_10 && V_3 -> V_11 >= 2 ) {
V_6 = F_3 ( V_2 , V_9 ) -
F_4 ( V_2 , V_9 ) ;
if ( V_6 == 0 )
V_6 = 256 * 2 ;
V_7 = ( ( V_5 - F_2 ( 2 ) ) * 256 * V_8 ) / V_6 ;
V_7 += V_3 -> V_12 ;
V_3 -> V_13 . V_14 = V_7 / V_8 ;
V_3 -> V_12 =
V_7 - V_3 -> V_13 . V_14 * V_8 ;
}
break;
case V_15 :
F_5 ( 0 ) = V_5 ;
if ( V_3 -> V_10 && V_3 -> V_11 >= 2 ) {
V_6 = F_3 ( V_2 , V_9 ) -
F_4 ( V_2 , V_9 ) ;
if ( V_6 == 0 )
V_6 = 256 * 2 ;
V_7 = - ( ( V_5 - F_5 ( 2 ) ) * 256 * V_8 ) / V_6 ;
V_7 += V_3 -> V_16 ;
V_3 -> V_13 . V_17 = V_7 / V_8 ;
V_3 -> V_16 = V_7 -
V_3 -> V_13 . V_17 * V_8 ;
}
break;
}
}
static void F_6 ( struct V_1 * V_2 , struct V_3 * V_3 ,
unsigned int V_4 , int V_5 )
{
int V_18 , V_19 , V_6 ;
switch ( V_4 ) {
case V_9 :
V_18 = F_4 ( V_2 , V_9 ) ;
V_19 = F_3 ( V_2 , V_9 ) ;
V_6 = V_19 - V_18 ;
if ( V_6 == 0 )
V_6 = V_20 ? : 1 ;
V_5 = F_7 ( V_5 , V_18 , V_19 ) ;
V_3 -> V_13 . V_21 = ( ( V_5 - V_18 ) * V_20 ) / V_6 ;
V_3 -> V_13 . V_22 = 1 ;
break;
case V_15 :
V_18 = F_4 ( V_2 , V_15 ) ;
V_19 = F_3 ( V_2 , V_15 ) ;
V_6 = V_19 - V_18 ;
if ( V_6 == 0 )
V_6 = V_23 ? : 1 ;
V_5 = F_7 ( V_5 , V_18 , V_19 ) ;
V_3 -> V_13 . V_24 = V_23 - ( ( V_5 - V_18 ) * V_23 ) / V_6 ;
V_3 -> V_13 . V_22 = 1 ;
break;
}
}
static void F_8 ( struct V_3 * V_3 ,
unsigned int V_4 , int V_5 )
{
switch ( V_4 ) {
case V_25 :
V_3 -> V_13 . V_14 += V_5 ;
break;
case V_26 :
V_3 -> V_13 . V_17 -= V_5 ;
break;
case V_27 :
V_3 -> V_13 . V_28 -= V_5 ;
break;
}
}
static void F_9 ( struct V_3 * V_3 ,
unsigned int V_4 , int V_5 )
{
int V_29 ;
switch ( V_4 ) {
case V_30 :
case V_31 :
case V_32 : V_29 = 0 ; break;
case V_33 :
case V_34 :
case V_35 : V_29 = 1 ; break;
case V_36 :
case V_37 :
case V_38 :
case V_39 : V_29 = 2 ; break;
case V_40 :
case V_41 :
case V_42 : V_29 = 3 ; break;
case V_43 :
case V_44 : V_29 = 4 ; break;
default: return;
}
if ( V_5 ) {
F_10 ( V_29 , & V_3 -> V_13 . V_45 ) ;
F_10 ( V_29 , & V_46 -> V_13 . V_45 ) ;
} else {
F_11 ( V_29 , & V_3 -> V_13 . V_45 ) ;
F_11 ( V_29 , & V_46 -> V_13 . V_45 ) ;
}
}
static void F_12 ( struct V_3 * V_3 ,
struct V_47 * V_13 )
{
struct V_48 * V_49 ;
struct V_50 * V_51 ;
unsigned int V_52 ;
int V_53 = 0 ;
F_13 () ;
F_14 (client, &mousedev->client_list, node) {
F_15 ( & V_49 -> V_54 ) ;
V_51 = & V_49 -> V_55 [ V_49 -> V_56 ] ;
if ( V_49 -> V_57 && V_51 -> V_45 != V_3 -> V_13 . V_45 ) {
V_52 = ( V_49 -> V_56 + 1 ) % V_58 ;
if ( V_52 != V_49 -> V_59 ) {
V_51 = & V_49 -> V_55 [ V_49 -> V_56 = V_52 ] ;
memset ( V_51 , 0 , sizeof( struct V_50 ) ) ;
}
}
if ( V_13 -> V_22 ) {
V_51 -> V_14 += V_13 -> V_21 - V_49 -> V_60 ;
V_51 -> V_17 += V_13 -> V_24 - V_49 -> V_61 ;
V_49 -> V_60 = V_13 -> V_21 ;
V_49 -> V_61 = V_13 -> V_24 ;
}
V_49 -> V_60 += V_13 -> V_14 ;
V_49 -> V_60 = V_49 -> V_60 < 0 ?
0 : ( V_49 -> V_60 >= V_20 ? V_20 : V_49 -> V_60 ) ;
V_49 -> V_61 += V_13 -> V_17 ;
V_49 -> V_61 = V_49 -> V_61 < 0 ?
0 : ( V_49 -> V_61 >= V_23 ? V_23 : V_49 -> V_61 ) ;
V_51 -> V_14 += V_13 -> V_14 ;
V_51 -> V_17 += V_13 -> V_17 ;
V_51 -> V_28 += V_13 -> V_28 ;
V_51 -> V_45 = V_3 -> V_13 . V_45 ;
if ( V_51 -> V_14 || V_51 -> V_17 || V_51 -> V_28 ||
V_51 -> V_45 != V_49 -> V_62 )
V_49 -> V_57 = 1 ;
F_16 ( & V_49 -> V_54 ) ;
if ( V_49 -> V_57 ) {
F_17 ( & V_49 -> V_63 , V_64 , V_65 ) ;
V_53 = 1 ;
}
}
F_18 () ;
if ( V_53 )
F_19 ( & V_3 -> V_66 ) ;
}
static void F_20 ( struct V_3 * V_3 , int V_5 )
{
if ( ! V_5 ) {
if ( V_3 -> V_10 &&
F_21 ( V_67 ,
V_3 -> V_10 + F_22 ( V_68 ) ) ) {
F_10 ( 0 , & V_3 -> V_13 . V_45 ) ;
F_10 ( 0 , & V_46 -> V_13 . V_45 ) ;
F_12 ( V_3 , & V_46 -> V_13 ) ;
F_12 ( V_46 ,
& V_46 -> V_13 ) ;
F_11 ( 0 , & V_3 -> V_13 . V_45 ) ;
F_11 ( 0 , & V_46 -> V_13 . V_45 ) ;
}
V_3 -> V_10 = V_3 -> V_11 = 0 ;
V_3 -> V_12 = 0 ;
V_3 -> V_16 = 0 ;
} else if ( ! V_3 -> V_10 )
V_3 -> V_10 = V_67 ;
}
static void F_23 ( struct V_69 * V_70 ,
unsigned int type , unsigned int V_4 , int V_5 )
{
struct V_3 * V_3 = V_70 -> V_71 ;
switch ( type ) {
case V_72 :
if ( F_24 ( V_73 , V_70 -> V_2 -> V_74 ) )
return;
if ( F_24 ( V_75 , V_70 -> V_2 -> V_74 ) )
F_1 ( V_70 -> V_2 ,
V_3 , V_4 , V_5 ) ;
else
F_6 ( V_70 -> V_2 , V_3 , V_4 , V_5 ) ;
break;
case V_76 :
F_8 ( V_3 , V_4 , V_5 ) ;
break;
case V_77 :
if ( V_5 != 2 ) {
if ( V_4 == V_30 &&
F_24 ( V_75 , V_70 -> V_2 -> V_74 ) )
F_20 ( V_3 , V_5 ) ;
else
F_9 ( V_3 , V_4 , V_5 ) ;
}
break;
case V_78 :
if ( V_4 == V_79 ) {
if ( V_3 -> V_10 ) {
V_3 -> V_11 ++ ;
F_2 ( 0 ) = F_2 ( 1 ) ;
F_5 ( 0 ) = F_5 ( 1 ) ;
}
F_12 ( V_3 , & V_3 -> V_13 ) ;
F_12 ( V_46 , & V_3 -> V_13 ) ;
V_3 -> V_13 . V_14 = V_3 -> V_13 . V_17 =
V_3 -> V_13 . V_28 = 0 ;
V_3 -> V_13 . V_22 = 0 ;
}
break;
}
}
static int F_25 ( int V_80 , struct V_81 * V_81 , int V_82 )
{
struct V_48 * V_49 = V_81 -> V_83 ;
return F_26 ( V_80 , V_81 , V_82 , & V_49 -> V_63 ) ;
}
static void F_27 ( struct V_84 * V_2 )
{
struct V_3 * V_3 = F_28 ( V_2 , struct V_3 , V_2 ) ;
F_29 ( V_3 -> V_70 . V_2 ) ;
F_30 ( V_3 ) ;
}
static int F_31 ( struct V_3 * V_3 )
{
int V_85 ;
V_85 = F_32 ( & V_3 -> V_86 ) ;
if ( V_85 )
return V_85 ;
if ( V_3 -> V_87 == V_88 )
F_33 () ;
else if ( ! V_3 -> V_89 )
V_85 = - V_90 ;
else if ( ! V_3 -> V_91 ++ ) {
V_85 = F_34 ( & V_3 -> V_70 ) ;
if ( V_85 )
V_3 -> V_91 -- ;
}
F_35 ( & V_3 -> V_86 ) ;
return V_85 ;
}
static void F_36 ( struct V_3 * V_3 )
{
F_37 ( & V_3 -> V_86 ) ;
if ( V_3 -> V_87 == V_88 )
F_38 () ;
else if ( V_3 -> V_89 && ! -- V_3 -> V_91 )
F_39 ( & V_3 -> V_70 ) ;
F_35 ( & V_3 -> V_86 ) ;
}
static void F_33 ( void )
{
struct V_3 * V_3 ;
if ( V_46 -> V_91 ++ )
return;
F_40 (mousedev, &mousedev_mix_list, mixdev_node) {
if ( ! V_3 -> V_92 ) {
if ( F_31 ( V_3 ) )
continue;
V_3 -> V_92 = 1 ;
}
}
}
static void F_38 ( void )
{
struct V_3 * V_3 ;
if ( -- V_46 -> V_91 )
return;
F_40 (mousedev, &mousedev_mix_list, mixdev_node) {
if ( V_3 -> V_92 ) {
V_3 -> V_92 = 0 ;
F_36 ( V_3 ) ;
}
}
}
static void F_41 ( struct V_3 * V_3 ,
struct V_48 * V_49 )
{
F_15 ( & V_3 -> V_93 ) ;
F_42 ( & V_49 -> V_94 , & V_3 -> V_95 ) ;
F_16 ( & V_3 -> V_93 ) ;
}
static void F_43 ( struct V_3 * V_3 ,
struct V_48 * V_49 )
{
F_15 ( & V_3 -> V_93 ) ;
F_44 ( & V_49 -> V_94 ) ;
F_16 ( & V_3 -> V_93 ) ;
F_45 () ;
}
static int F_46 ( struct V_96 * V_96 , struct V_81 * V_81 )
{
struct V_48 * V_49 = V_81 -> V_83 ;
struct V_3 * V_3 = V_49 -> V_3 ;
F_43 ( V_3 , V_49 ) ;
F_30 ( V_49 ) ;
F_36 ( V_3 ) ;
F_47 ( & V_3 -> V_2 ) ;
return 0 ;
}
static int F_48 ( struct V_96 * V_96 , struct V_81 * V_81 )
{
struct V_48 * V_49 ;
struct V_3 * V_3 ;
int error ;
int V_97 ;
#ifdef F_49
if ( F_50 ( V_96 ) == V_98 )
V_97 = V_88 ;
else
#endif
V_97 = F_51 ( V_96 ) - V_99 ;
if ( V_97 >= V_100 )
return - V_90 ;
error = F_32 ( & V_101 ) ;
if ( error ) {
return error ;
}
V_3 = V_102 [ V_97 ] ;
if ( V_3 )
F_52 ( & V_3 -> V_2 ) ;
F_35 ( & V_101 ) ;
if ( ! V_3 ) {
return - V_90 ;
}
V_49 = F_53 ( sizeof( struct V_48 ) , V_103 ) ;
if ( ! V_49 ) {
error = - V_104 ;
goto V_105;
}
F_54 ( & V_49 -> V_54 ) ;
V_49 -> V_60 = V_20 / 2 ;
V_49 -> V_61 = V_23 / 2 ;
V_49 -> V_3 = V_3 ;
F_41 ( V_3 , V_49 ) ;
error = F_31 ( V_3 ) ;
if ( error )
goto V_106;
V_81 -> V_83 = V_49 ;
return 0 ;
V_106:
F_43 ( V_3 , V_49 ) ;
F_30 ( V_49 ) ;
V_105:
F_47 ( & V_3 -> V_2 ) ;
return error ;
}
static inline int F_55 ( int V_107 , int V_108 )
{
return V_107 > V_108 ? V_108 : ( V_107 < - V_108 ? - V_108 : V_107 ) ;
}
static void F_56 ( struct V_48 * V_49 ,
signed char * V_109 )
{
struct V_50 * V_51 = & V_49 -> V_55 [ V_49 -> V_59 ] ;
V_109 [ 0 ] = 0x08 |
( ( V_51 -> V_14 < 0 ) << 4 ) | ( ( V_51 -> V_17 < 0 ) << 5 ) | ( V_51 -> V_45 & 0x07 ) ;
V_109 [ 1 ] = F_55 ( V_51 -> V_14 , 127 ) ;
V_109 [ 2 ] = F_55 ( V_51 -> V_17 , 127 ) ;
V_51 -> V_14 -= V_109 [ 1 ] ;
V_51 -> V_17 -= V_109 [ 2 ] ;
switch ( V_49 -> V_110 ) {
case V_111 :
V_109 [ 3 ] = F_55 ( V_51 -> V_28 , 7 ) ;
V_51 -> V_28 -= V_109 [ 3 ] ;
V_109 [ 3 ] = ( V_109 [ 3 ] & 0x0f ) | ( ( V_51 -> V_45 & 0x18 ) << 1 ) ;
V_49 -> V_112 = 4 ;
break;
case V_113 :
V_109 [ 0 ] |=
( ( V_51 -> V_45 & 0x10 ) >> 3 ) | ( ( V_51 -> V_45 & 0x08 ) >> 1 ) ;
V_109 [ 3 ] = F_55 ( V_51 -> V_28 , 127 ) ;
V_51 -> V_28 -= V_109 [ 3 ] ;
V_49 -> V_112 = 4 ;
break;
case V_114 :
default:
V_109 [ 0 ] |=
( ( V_51 -> V_45 & 0x10 ) >> 3 ) | ( ( V_51 -> V_45 & 0x08 ) >> 1 ) ;
V_51 -> V_28 = 0 ;
V_49 -> V_112 = 3 ;
break;
}
if ( ! V_51 -> V_14 && ! V_51 -> V_17 && ! V_51 -> V_28 ) {
if ( V_49 -> V_59 == V_49 -> V_56 ) {
V_49 -> V_57 = 0 ;
V_49 -> V_62 = V_51 -> V_45 ;
} else
V_49 -> V_59 = ( V_49 -> V_59 + 1 ) % V_58 ;
}
}
static void F_57 ( struct V_48 * V_49 ,
int V_115 )
{
V_49 -> V_116 [ 0 ] = 0xfa ;
switch ( V_115 ) {
case 0xeb :
F_56 ( V_49 , & V_49 -> V_116 [ 1 ] ) ;
V_49 -> V_112 ++ ;
break;
case 0xf2 :
switch ( V_49 -> V_110 ) {
case V_114 :
V_49 -> V_116 [ 1 ] = 0 ;
break;
case V_113 :
V_49 -> V_116 [ 1 ] = 3 ;
break;
case V_111 :
V_49 -> V_116 [ 1 ] = 4 ;
break;
}
V_49 -> V_112 = 2 ;
break;
case 0xe9 :
V_49 -> V_116 [ 1 ] = 0x60 ; V_49 -> V_116 [ 2 ] = 3 ; V_49 -> V_116 [ 3 ] = 200 ;
V_49 -> V_112 = 4 ;
break;
case 0xff :
V_49 -> V_117 = V_49 -> V_118 = 0 ;
V_49 -> V_110 = V_114 ;
V_49 -> V_116 [ 1 ] = 0xaa ; V_49 -> V_116 [ 2 ] = 0x00 ;
V_49 -> V_112 = 3 ;
break;
default:
V_49 -> V_112 = 1 ;
break;
}
V_49 -> V_119 = V_49 -> V_112 ;
}
static T_1 F_58 ( struct V_81 * V_81 , const char T_2 * V_119 ,
T_3 V_120 , T_4 * V_121 )
{
struct V_48 * V_49 = V_81 -> V_83 ;
unsigned char V_122 ;
unsigned int V_97 ;
for ( V_97 = 0 ; V_97 < V_120 ; V_97 ++ ) {
if ( F_59 ( V_122 , V_119 + V_97 ) )
return - V_123 ;
F_60 ( & V_49 -> V_54 ) ;
if ( V_122 == V_124 [ V_49 -> V_118 ] ) {
if ( ++ V_49 -> V_118 == V_125 ) {
V_49 -> V_118 = 0 ;
V_49 -> V_110 = V_111 ;
}
} else
V_49 -> V_118 = 0 ;
if ( V_122 == V_126 [ V_49 -> V_117 ] ) {
if ( ++ V_49 -> V_117 == V_125 ) {
V_49 -> V_117 = 0 ;
V_49 -> V_110 = V_113 ;
}
} else
V_49 -> V_117 = 0 ;
F_57 ( V_49 , V_122 ) ;
F_61 ( & V_49 -> V_54 ) ;
}
F_17 ( & V_49 -> V_63 , V_64 , V_65 ) ;
F_19 ( & V_49 -> V_3 -> V_66 ) ;
return V_120 ;
}
static T_1 F_62 ( struct V_81 * V_81 , char T_2 * V_119 ,
T_3 V_120 , T_4 * V_121 )
{
struct V_48 * V_49 = V_81 -> V_83 ;
struct V_3 * V_3 = V_49 -> V_3 ;
signed char V_127 [ sizeof( V_49 -> V_116 ) ] ;
int V_85 = 0 ;
if ( ! V_49 -> V_57 && ! V_49 -> V_119 && V_3 -> V_89 &&
( V_81 -> V_128 & V_129 ) )
return - V_130 ;
V_85 = F_63 ( V_3 -> V_66 ,
! V_3 -> V_89 || V_49 -> V_57 || V_49 -> V_119 ) ;
if ( V_85 )
return V_85 ;
if ( ! V_3 -> V_89 )
return - V_90 ;
F_60 ( & V_49 -> V_54 ) ;
if ( ! V_49 -> V_119 && V_49 -> V_57 ) {
F_56 ( V_49 , V_49 -> V_116 ) ;
V_49 -> V_119 = V_49 -> V_112 ;
}
if ( V_120 > V_49 -> V_119 )
V_120 = V_49 -> V_119 ;
memcpy ( V_127 , V_49 -> V_116 + V_49 -> V_112 - V_49 -> V_119 , V_120 ) ;
V_49 -> V_119 -= V_120 ;
F_61 ( & V_49 -> V_54 ) ;
if ( F_64 ( V_119 , V_127 , V_120 ) )
return - V_123 ;
return V_120 ;
}
static unsigned int F_65 ( struct V_81 * V_81 , T_5 * V_66 )
{
struct V_48 * V_49 = V_81 -> V_83 ;
struct V_3 * V_3 = V_49 -> V_3 ;
unsigned int V_131 ;
F_66 ( V_81 , & V_3 -> V_66 , V_66 ) ;
V_131 = V_3 -> V_89 ? V_132 | V_133 : V_134 | V_135 ;
if ( V_49 -> V_57 || V_49 -> V_119 )
V_131 |= V_136 | V_137 ;
return V_131 ;
}
static int F_67 ( struct V_3 * V_3 )
{
V_102 [ V_3 -> V_87 ] = V_3 ;
return 0 ;
}
static void F_68 ( struct V_3 * V_3 )
{
F_37 ( & V_101 ) ;
V_102 [ V_3 -> V_87 ] = NULL ;
F_35 ( & V_101 ) ;
}
static void F_69 ( struct V_3 * V_3 )
{
F_37 ( & V_3 -> V_86 ) ;
V_3 -> V_89 = false ;
F_35 ( & V_3 -> V_86 ) ;
}
static void F_70 ( struct V_3 * V_3 )
{
struct V_48 * V_49 ;
F_15 ( & V_3 -> V_93 ) ;
F_40 (client, &mousedev->client_list, node)
F_17 ( & V_49 -> V_63 , V_64 , V_138 ) ;
F_16 ( & V_3 -> V_93 ) ;
F_19 ( & V_3 -> V_66 ) ;
}
static void F_71 ( struct V_3 * V_3 )
{
struct V_69 * V_70 = & V_3 -> V_70 ;
F_69 ( V_3 ) ;
F_70 ( V_3 ) ;
F_68 ( V_3 ) ;
if ( V_3 -> V_91 )
F_39 ( V_70 ) ;
}
static struct V_3 * F_72 ( struct V_1 * V_2 ,
struct V_139 * V_140 ,
int V_87 )
{
struct V_3 * V_3 ;
int error ;
V_3 = F_53 ( sizeof( struct V_3 ) , V_103 ) ;
if ( ! V_3 ) {
error = - V_104 ;
goto V_141;
}
F_73 ( & V_3 -> V_95 ) ;
F_73 ( & V_3 -> V_142 ) ;
F_54 ( & V_3 -> V_93 ) ;
F_74 ( & V_3 -> V_86 ) ;
F_75 ( & V_3 -> V_86 ,
V_87 == V_88 ? V_143 : 0 ) ;
F_76 ( & V_3 -> V_66 ) ;
if ( V_87 == V_88 )
F_77 ( & V_3 -> V_2 , L_1 ) ;
else
F_77 ( & V_3 -> V_2 , L_2 , V_87 ) ;
V_3 -> V_87 = V_87 ;
V_3 -> V_89 = true ;
V_3 -> V_70 . V_2 = F_78 ( V_2 ) ;
V_3 -> V_70 . V_144 = F_79 ( & V_3 -> V_2 ) ;
V_3 -> V_70 . V_140 = V_140 ;
V_3 -> V_70 . V_71 = V_3 ;
V_3 -> V_2 . V_145 = & V_146 ;
if ( V_2 )
V_3 -> V_2 . V_147 = & V_2 -> V_2 ;
V_3 -> V_2 . V_148 = F_80 ( V_149 , V_99 + V_87 ) ;
V_3 -> V_2 . V_150 = F_27 ;
F_81 ( & V_3 -> V_2 ) ;
if ( V_87 != V_88 ) {
error = F_82 ( & V_3 -> V_70 ) ;
if ( error )
goto V_151;
}
error = F_67 ( V_3 ) ;
if ( error )
goto V_152;
error = F_83 ( & V_3 -> V_2 ) ;
if ( error )
goto V_153;
return V_3 ;
V_153:
F_71 ( V_3 ) ;
V_152:
if ( V_87 != V_88 )
F_84 ( & V_3 -> V_70 ) ;
V_151:
F_47 ( & V_3 -> V_2 ) ;
V_141:
return F_85 ( error ) ;
}
static void F_86 ( struct V_3 * V_3 )
{
F_87 ( & V_3 -> V_2 ) ;
F_71 ( V_3 ) ;
if ( V_3 -> V_87 != V_88 )
F_84 ( & V_3 -> V_70 ) ;
F_47 ( & V_3 -> V_2 ) ;
}
static int F_88 ( struct V_3 * V_3 )
{
int V_85 ;
V_85 = F_32 ( & V_46 -> V_86 ) ;
if ( V_85 )
return V_85 ;
if ( V_46 -> V_91 ) {
V_85 = F_31 ( V_3 ) ;
if ( V_85 )
goto V_154;
V_3 -> V_92 = 1 ;
}
F_52 ( & V_3 -> V_2 ) ;
F_89 ( & V_3 -> V_142 , & V_155 ) ;
V_154:
F_35 ( & V_46 -> V_86 ) ;
return V_85 ;
}
static void F_90 ( struct V_3 * V_3 )
{
F_37 ( & V_46 -> V_86 ) ;
if ( V_3 -> V_92 ) {
V_3 -> V_92 = 0 ;
F_36 ( V_3 ) ;
}
F_91 ( & V_3 -> V_142 ) ;
F_35 ( & V_46 -> V_86 ) ;
F_47 ( & V_3 -> V_2 ) ;
}
static int F_92 ( struct V_139 * V_140 ,
struct V_1 * V_2 ,
const struct V_156 * V_157 )
{
struct V_3 * V_3 ;
int V_87 ;
int error ;
for ( V_87 = 0 ; V_87 < V_100 ; V_87 ++ )
if ( ! V_102 [ V_87 ] )
break;
if ( V_87 == V_100 ) {
F_93 ( L_3 ) ;
return - V_158 ;
}
V_3 = F_72 ( V_2 , V_140 , V_87 ) ;
if ( F_94 ( V_3 ) )
return F_95 ( V_3 ) ;
error = F_88 ( V_3 ) ;
if ( error ) {
F_86 ( V_3 ) ;
return error ;
}
return 0 ;
}
static void F_96 ( struct V_69 * V_70 )
{
struct V_3 * V_3 = V_70 -> V_71 ;
F_90 ( V_3 ) ;
F_86 ( V_3 ) ;
}
static int T_6 F_97 ( void )
{
int error ;
V_46 = F_72 ( NULL , & V_159 , V_88 ) ;
if ( F_94 ( V_46 ) )
return F_95 ( V_46 ) ;
error = F_98 ( & V_159 ) ;
if ( error ) {
F_86 ( V_46 ) ;
return error ;
}
#ifdef F_49
error = F_99 ( & V_160 ) ;
if ( error )
F_100 ( L_4 ,
error ) ;
else
V_161 = 1 ;
#endif
F_101 ( L_5 ) ;
return 0 ;
}
static void T_7 F_102 ( void )
{
#ifdef F_49
if ( V_161 )
F_103 ( & V_160 ) ;
#endif
F_104 ( & V_159 ) ;
F_86 ( V_46 ) ;
}
