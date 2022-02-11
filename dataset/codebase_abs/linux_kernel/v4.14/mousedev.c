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
V_49 -> V_60 = F_16 ( V_49 -> V_60 , 0 , V_20 ) ;
V_49 -> V_61 += V_13 -> V_17 ;
V_49 -> V_61 = F_16 ( V_49 -> V_61 , 0 , V_23 ) ;
V_51 -> V_14 += V_13 -> V_14 ;
V_51 -> V_17 += V_13 -> V_17 ;
V_51 -> V_28 += V_13 -> V_28 ;
V_51 -> V_45 = V_3 -> V_13 . V_45 ;
if ( V_51 -> V_14 || V_51 -> V_17 || V_51 -> V_28 ||
V_51 -> V_45 != V_49 -> V_62 )
V_49 -> V_57 = 1 ;
F_17 ( & V_49 -> V_54 ) ;
if ( V_49 -> V_57 ) {
F_18 ( & V_49 -> V_63 , V_64 , V_65 ) ;
V_53 = 1 ;
}
}
F_19 () ;
if ( V_53 )
F_20 ( & V_3 -> V_66 ) ;
}
static void F_21 ( struct V_3 * V_3 , int V_5 )
{
if ( ! V_5 ) {
if ( V_3 -> V_10 &&
F_22 ( V_67 ,
V_3 -> V_10 + F_23 ( V_68 ) ) ) {
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
static void F_24 ( struct V_69 * V_70 ,
unsigned int type , unsigned int V_4 , int V_5 )
{
struct V_3 * V_3 = V_70 -> V_71 ;
switch ( type ) {
case V_72 :
if ( F_25 ( V_73 , V_70 -> V_2 -> V_74 ) )
return;
if ( F_25 ( V_75 , V_70 -> V_2 -> V_74 ) )
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
F_25 ( V_75 , V_70 -> V_2 -> V_74 ) )
F_21 ( V_3 , V_5 ) ;
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
static int F_26 ( int V_80 , struct V_81 * V_81 , int V_82 )
{
struct V_48 * V_49 = V_81 -> V_83 ;
return F_27 ( V_80 , V_81 , V_82 , & V_49 -> V_63 ) ;
}
static void F_28 ( struct V_84 * V_2 )
{
struct V_3 * V_3 = F_29 ( V_2 , struct V_3 , V_2 ) ;
F_30 ( V_3 -> V_70 . V_2 ) ;
F_31 ( V_3 ) ;
}
static int F_32 ( struct V_3 * V_3 )
{
int V_85 ;
V_85 = F_33 ( & V_3 -> V_86 ) ;
if ( V_85 )
return V_85 ;
if ( ! V_3 -> V_87 )
V_85 = - V_88 ;
else if ( ! V_3 -> V_89 ++ ) {
V_85 = F_34 ( & V_3 -> V_70 ) ;
if ( V_85 )
V_3 -> V_89 -- ;
}
F_35 ( & V_3 -> V_86 ) ;
return V_85 ;
}
static void F_36 ( struct V_3 * V_3 )
{
F_37 ( & V_3 -> V_86 ) ;
if ( V_3 -> V_87 && ! -- V_3 -> V_89 )
F_38 ( & V_3 -> V_70 ) ;
F_35 ( & V_3 -> V_86 ) ;
}
static int F_39 ( struct V_3 * V_90 )
{
int error ;
error = F_33 ( & V_90 -> V_86 ) ;
if ( error )
return error ;
if ( ! V_90 -> V_89 ++ ) {
struct V_3 * V_3 ;
F_40 (mousedev, &mousedev_mix_list, mixdev_node) {
if ( ! V_3 -> V_91 ) {
if ( F_32 ( V_3 ) )
continue;
V_3 -> V_91 = true ;
}
}
}
F_35 ( & V_90 -> V_86 ) ;
return 0 ;
}
static void F_41 ( struct V_3 * V_90 )
{
F_37 ( & V_90 -> V_86 ) ;
if ( ! -- V_90 -> V_89 ) {
struct V_3 * V_3 ;
F_40 (mousedev, &mousedev_mix_list, mixdev_node) {
if ( V_3 -> V_91 ) {
V_3 -> V_91 = false ;
F_36 ( V_3 ) ;
}
}
}
F_35 ( & V_90 -> V_86 ) ;
}
static void F_42 ( struct V_3 * V_3 ,
struct V_48 * V_49 )
{
F_15 ( & V_3 -> V_92 ) ;
F_43 ( & V_49 -> V_93 , & V_3 -> V_94 ) ;
F_17 ( & V_3 -> V_92 ) ;
}
static void F_44 ( struct V_3 * V_3 ,
struct V_48 * V_49 )
{
F_15 ( & V_3 -> V_92 ) ;
F_45 ( & V_49 -> V_93 ) ;
F_17 ( & V_3 -> V_92 ) ;
F_46 () ;
}
static int F_47 ( struct V_95 * V_95 , struct V_81 * V_81 )
{
struct V_48 * V_49 = V_81 -> V_83 ;
struct V_3 * V_3 = V_49 -> V_3 ;
F_44 ( V_3 , V_49 ) ;
F_31 ( V_49 ) ;
V_3 -> V_96 ( V_3 ) ;
return 0 ;
}
static int F_48 ( struct V_95 * V_95 , struct V_81 * V_81 )
{
struct V_48 * V_49 ;
struct V_3 * V_3 ;
int error ;
#ifdef F_49
if ( F_50 ( V_95 ) == V_97 )
V_3 = V_46 ;
else
#endif
V_3 = F_29 ( V_95 -> V_98 , struct V_3 , V_99 ) ;
V_49 = F_51 ( sizeof( struct V_48 ) , V_100 ) ;
if ( ! V_49 )
return - V_101 ;
F_52 ( & V_49 -> V_54 ) ;
V_49 -> V_60 = V_20 / 2 ;
V_49 -> V_61 = V_23 / 2 ;
V_49 -> V_3 = V_3 ;
F_42 ( V_3 , V_49 ) ;
error = V_3 -> V_102 ( V_3 ) ;
if ( error )
goto V_103;
V_81 -> V_83 = V_49 ;
F_53 ( V_95 , V_81 ) ;
return 0 ;
V_103:
F_44 ( V_3 , V_49 ) ;
F_31 ( V_49 ) ;
return error ;
}
static void F_54 ( struct V_48 * V_49 , T_1 * V_104 )
{
struct V_50 * V_51 = & V_49 -> V_55 [ V_49 -> V_59 ] ;
T_2 V_14 , V_17 , V_28 ;
V_14 = F_16 ( V_51 -> V_14 , - 127 , 127 ) ;
V_51 -> V_14 -= V_14 ;
V_17 = F_16 ( V_51 -> V_17 , - 127 , 127 ) ;
V_51 -> V_17 -= V_17 ;
V_104 [ 0 ] = F_55 ( 3 ) ;
V_104 [ 0 ] |= ( ( V_14 & F_55 ( 7 ) ) >> 3 ) | ( ( V_17 & F_55 ( 7 ) ) >> 2 ) ;
V_104 [ 0 ] |= V_51 -> V_45 & 0x07 ;
V_104 [ 1 ] = V_14 ;
V_104 [ 2 ] = V_17 ;
switch ( V_49 -> V_105 ) {
case V_106 :
V_28 = F_16 ( V_51 -> V_28 , - 7 , 7 ) ;
V_51 -> V_28 -= V_28 ;
V_104 [ 3 ] = ( V_28 & 0x0f ) | ( ( V_51 -> V_45 & 0x18 ) << 1 ) ;
V_49 -> V_107 = 4 ;
break;
case V_108 :
V_28 = F_16 ( V_51 -> V_28 , - 127 , 127 ) ;
V_51 -> V_28 -= V_28 ;
V_104 [ 0 ] |= ( ( V_51 -> V_45 & 0x10 ) >> 3 ) |
( ( V_51 -> V_45 & 0x08 ) >> 1 ) ;
V_104 [ 3 ] = V_28 ;
V_49 -> V_107 = 4 ;
break;
case V_109 :
default:
V_51 -> V_28 = 0 ;
V_104 [ 0 ] |= ( ( V_51 -> V_45 & 0x10 ) >> 3 ) |
( ( V_51 -> V_45 & 0x08 ) >> 1 ) ;
V_49 -> V_107 = 3 ;
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
static void F_56 ( struct V_48 * V_49 ,
int V_110 )
{
V_49 -> V_111 [ 0 ] = 0xfa ;
switch ( V_110 ) {
case 0xeb :
F_54 ( V_49 , & V_49 -> V_111 [ 1 ] ) ;
V_49 -> V_107 ++ ;
break;
case 0xf2 :
switch ( V_49 -> V_105 ) {
case V_109 :
V_49 -> V_111 [ 1 ] = 0 ;
break;
case V_108 :
V_49 -> V_111 [ 1 ] = 3 ;
break;
case V_106 :
V_49 -> V_111 [ 1 ] = 4 ;
break;
}
V_49 -> V_107 = 2 ;
break;
case 0xe9 :
V_49 -> V_111 [ 1 ] = 0x60 ; V_49 -> V_111 [ 2 ] = 3 ; V_49 -> V_111 [ 3 ] = 200 ;
V_49 -> V_107 = 4 ;
break;
case 0xff :
V_49 -> V_112 = V_49 -> V_113 = 0 ;
V_49 -> V_105 = V_109 ;
V_49 -> V_111 [ 1 ] = 0xaa ; V_49 -> V_111 [ 2 ] = 0x00 ;
V_49 -> V_107 = 3 ;
break;
default:
V_49 -> V_107 = 1 ;
break;
}
V_49 -> V_114 = V_49 -> V_107 ;
}
static T_3 F_57 ( struct V_81 * V_81 , const char T_4 * V_114 ,
T_5 V_115 , T_6 * V_116 )
{
struct V_48 * V_49 = V_81 -> V_83 ;
unsigned char V_117 ;
unsigned int V_118 ;
for ( V_118 = 0 ; V_118 < V_115 ; V_118 ++ ) {
if ( F_58 ( V_117 , V_114 + V_118 ) )
return - V_119 ;
F_59 ( & V_49 -> V_54 ) ;
if ( V_117 == V_120 [ V_49 -> V_113 ] ) {
if ( ++ V_49 -> V_113 == V_121 ) {
V_49 -> V_113 = 0 ;
V_49 -> V_105 = V_106 ;
}
} else
V_49 -> V_113 = 0 ;
if ( V_117 == V_122 [ V_49 -> V_112 ] ) {
if ( ++ V_49 -> V_112 == V_121 ) {
V_49 -> V_112 = 0 ;
V_49 -> V_105 = V_108 ;
}
} else
V_49 -> V_112 = 0 ;
F_56 ( V_49 , V_117 ) ;
F_60 ( & V_49 -> V_54 ) ;
}
F_18 ( & V_49 -> V_63 , V_64 , V_65 ) ;
F_20 ( & V_49 -> V_3 -> V_66 ) ;
return V_115 ;
}
static T_3 F_61 ( struct V_81 * V_81 , char T_4 * V_114 ,
T_5 V_115 , T_6 * V_116 )
{
struct V_48 * V_49 = V_81 -> V_83 ;
struct V_3 * V_3 = V_49 -> V_3 ;
T_1 V_123 [ sizeof( V_49 -> V_111 ) ] ;
int V_85 = 0 ;
if ( ! V_49 -> V_57 && ! V_49 -> V_114 && V_3 -> V_87 &&
( V_81 -> V_124 & V_125 ) )
return - V_126 ;
V_85 = F_62 ( V_3 -> V_66 ,
! V_3 -> V_87 || V_49 -> V_57 || V_49 -> V_114 ) ;
if ( V_85 )
return V_85 ;
if ( ! V_3 -> V_87 )
return - V_88 ;
F_59 ( & V_49 -> V_54 ) ;
if ( ! V_49 -> V_114 && V_49 -> V_57 ) {
F_54 ( V_49 , V_49 -> V_111 ) ;
V_49 -> V_114 = V_49 -> V_107 ;
}
if ( V_115 > V_49 -> V_114 )
V_115 = V_49 -> V_114 ;
memcpy ( V_123 , V_49 -> V_111 + V_49 -> V_107 - V_49 -> V_114 , V_115 ) ;
V_49 -> V_114 -= V_115 ;
F_60 ( & V_49 -> V_54 ) ;
if ( F_63 ( V_114 , V_123 , V_115 ) )
return - V_119 ;
return V_115 ;
}
static unsigned int F_64 ( struct V_81 * V_81 , T_7 * V_66 )
{
struct V_48 * V_49 = V_81 -> V_83 ;
struct V_3 * V_3 = V_49 -> V_3 ;
unsigned int V_127 ;
F_65 ( V_81 , & V_3 -> V_66 , V_66 ) ;
V_127 = V_3 -> V_87 ? V_128 | V_129 : V_130 | V_131 ;
if ( V_49 -> V_57 || V_49 -> V_114 )
V_127 |= V_132 | V_133 ;
return V_127 ;
}
static void F_66 ( struct V_3 * V_3 )
{
F_37 ( & V_3 -> V_86 ) ;
V_3 -> V_87 = false ;
F_35 ( & V_3 -> V_86 ) ;
}
static void F_67 ( struct V_3 * V_3 )
{
struct V_48 * V_49 ;
F_15 ( & V_3 -> V_92 ) ;
F_40 (client, &mousedev->client_list, node)
F_18 ( & V_49 -> V_63 , V_64 , V_134 ) ;
F_17 ( & V_3 -> V_92 ) ;
F_20 ( & V_3 -> V_66 ) ;
}
static void F_68 ( struct V_3 * V_3 )
{
struct V_69 * V_70 = & V_3 -> V_70 ;
F_66 ( V_3 ) ;
F_67 ( V_3 ) ;
if ( V_3 -> V_89 )
F_38 ( V_70 ) ;
}
static int F_69 ( bool V_90 )
{
int V_135 ;
if ( V_90 ) {
V_135 = F_70 ( V_136 , 1 , false ) ;
if ( V_135 < 0 )
F_71 ( L_1 , V_135 ) ;
} else {
V_135 = F_70 ( V_137 ,
V_138 , true ) ;
if ( V_135 < 0 )
F_71 ( L_2 , V_135 ) ;
}
return V_135 ;
}
static struct V_3 * F_72 ( struct V_1 * V_2 ,
struct V_139 * V_140 ,
bool V_90 )
{
struct V_3 * V_3 ;
int V_135 ;
int error ;
V_135 = F_69 ( V_90 ) ;
if ( V_135 < 0 ) {
error = V_135 ;
goto V_141;
}
V_3 = F_51 ( sizeof( struct V_3 ) , V_100 ) ;
if ( ! V_3 ) {
error = - V_101 ;
goto V_142;
}
F_73 ( & V_3 -> V_94 ) ;
F_73 ( & V_3 -> V_143 ) ;
F_52 ( & V_3 -> V_92 ) ;
F_74 ( & V_3 -> V_86 ) ;
F_75 ( & V_3 -> V_86 ,
V_90 ? V_144 : 0 ) ;
F_76 ( & V_3 -> V_66 ) ;
if ( V_90 ) {
F_77 ( & V_3 -> V_2 , L_3 ) ;
V_3 -> V_102 = F_39 ;
V_3 -> V_96 = F_41 ;
} else {
int V_145 = V_135 ;
if ( V_145 < V_137 + V_138 )
V_145 -= V_137 ;
F_77 ( & V_3 -> V_2 , L_4 , V_145 ) ;
V_3 -> V_102 = F_32 ;
V_3 -> V_96 = F_36 ;
}
V_3 -> V_87 = true ;
V_3 -> V_70 . V_2 = F_78 ( V_2 ) ;
V_3 -> V_70 . V_146 = F_79 ( & V_3 -> V_2 ) ;
V_3 -> V_70 . V_140 = V_140 ;
V_3 -> V_70 . V_71 = V_3 ;
V_3 -> V_2 . V_147 = & V_148 ;
if ( V_2 )
V_3 -> V_2 . V_149 = & V_2 -> V_2 ;
V_3 -> V_2 . V_150 = F_80 ( V_151 , V_135 ) ;
V_3 -> V_2 . V_152 = F_28 ;
F_81 ( & V_3 -> V_2 ) ;
if ( ! V_90 ) {
error = F_82 ( & V_3 -> V_70 ) ;
if ( error )
goto V_153;
}
F_83 ( & V_3 -> V_99 , & V_154 ) ;
error = F_84 ( & V_3 -> V_99 , & V_3 -> V_2 ) ;
if ( error )
goto V_155;
return V_3 ;
V_155:
F_68 ( V_3 ) ;
if ( ! V_90 )
F_85 ( & V_3 -> V_70 ) ;
V_153:
F_86 ( & V_3 -> V_2 ) ;
V_142:
F_87 ( V_135 ) ;
V_141:
return F_88 ( error ) ;
}
static void F_89 ( struct V_3 * V_3 )
{
F_90 ( & V_3 -> V_99 , & V_3 -> V_2 ) ;
F_68 ( V_3 ) ;
F_87 ( F_91 ( V_3 -> V_2 . V_150 ) ) ;
if ( V_3 != V_46 )
F_85 ( & V_3 -> V_70 ) ;
F_86 ( & V_3 -> V_2 ) ;
}
static int F_92 ( struct V_3 * V_3 )
{
int V_85 ;
V_85 = F_33 ( & V_46 -> V_86 ) ;
if ( V_85 )
return V_85 ;
if ( V_46 -> V_89 ) {
V_85 = F_32 ( V_3 ) ;
if ( V_85 )
goto V_156;
V_3 -> V_91 = true ;
}
F_93 ( & V_3 -> V_2 ) ;
F_94 ( & V_3 -> V_143 , & V_157 ) ;
V_156:
F_35 ( & V_46 -> V_86 ) ;
return V_85 ;
}
static void F_95 ( struct V_3 * V_3 )
{
F_37 ( & V_46 -> V_86 ) ;
if ( V_3 -> V_91 ) {
V_3 -> V_91 = false ;
F_36 ( V_3 ) ;
}
F_96 ( & V_3 -> V_143 ) ;
F_35 ( & V_46 -> V_86 ) ;
F_86 ( & V_3 -> V_2 ) ;
}
static int F_97 ( struct V_139 * V_140 ,
struct V_1 * V_2 ,
const struct V_158 * V_159 )
{
struct V_3 * V_3 ;
int error ;
V_3 = F_72 ( V_2 , V_140 , false ) ;
if ( F_98 ( V_3 ) )
return F_99 ( V_3 ) ;
error = F_92 ( V_3 ) ;
if ( error ) {
F_89 ( V_3 ) ;
return error ;
}
return 0 ;
}
static void F_100 ( struct V_69 * V_70 )
{
struct V_3 * V_3 = V_70 -> V_71 ;
F_95 ( V_3 ) ;
F_89 ( V_3 ) ;
}
static void T_8 F_101 ( void )
{
int error ;
error = F_102 ( & V_160 ) ;
if ( error )
F_103 ( L_5 ,
error ) ;
else
V_161 = true ;
}
static void T_9 F_104 ( void )
{
if ( V_161 )
F_105 ( & V_160 ) ;
}
static inline void F_101 ( void ) { }
static inline void F_104 ( void ) { }
static int T_8 F_106 ( void )
{
int error ;
V_46 = F_72 ( NULL , & V_162 , true ) ;
if ( F_98 ( V_46 ) )
return F_99 ( V_46 ) ;
error = F_107 ( & V_162 ) ;
if ( error ) {
F_89 ( V_46 ) ;
return error ;
}
F_101 () ;
F_108 ( L_6 ) ;
return 0 ;
}
static void T_9 F_109 ( void )
{
F_104 () ;
F_110 ( & V_162 ) ;
F_89 ( V_46 ) ;
}
