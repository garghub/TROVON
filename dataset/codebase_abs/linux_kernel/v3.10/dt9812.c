static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_2 ) ;
}
static void F_3 ( struct V_2 * V_2 )
{
struct V_1 * V_4 = F_1 ( V_2 ) ;
F_4 ( V_4 -> V_5 ) ;
F_5 ( V_4 ) ;
}
static int F_6 ( struct V_1 * V_4 , int V_6 , void * V_7 ,
T_1 V_8 )
{
struct V_9 V_10 ;
int V_11 , V_12 ;
V_10 . V_10 = F_7 ( V_13 ) ;
V_10 . V_14 . V_15 . V_16 =
F_8 ( V_17 + V_6 ) ;
V_10 . V_14 . V_15 . V_18 = F_8 ( V_8 ) ;
V_11 = 32 ;
V_12 = F_9 ( V_4 -> V_5 ,
F_10 ( V_4 -> V_5 ,
V_4 -> V_19 . V_20 ) ,
& V_10 , 32 , & V_11 , V_21 * 1 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_9 ( V_4 -> V_5 ,
F_11 ( V_4 -> V_5 ,
V_4 -> V_22 . V_20 ) ,
V_7 , V_8 , & V_11 , V_21 * 1 ) ;
return V_12 ;
}
static int F_12 ( struct V_1 * V_4 , int V_23 ,
T_2 * V_16 , T_2 * V_24 )
{
struct V_9 V_10 ;
int V_25 , V_11 , V_12 ;
V_10 . V_10 = F_7 ( V_26 ) ;
V_10 . V_14 . V_27 . V_11 = V_23 ;
for ( V_25 = 0 ; V_25 < V_23 ; V_25 ++ )
V_10 . V_14 . V_27 . V_16 [ V_25 ] = V_16 [ V_25 ] ;
V_11 = 32 ;
V_12 = F_9 ( V_4 -> V_5 ,
F_10 ( V_4 -> V_5 ,
V_4 -> V_19 . V_20 ) ,
& V_10 , 32 , & V_11 , V_21 * 1 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_9 ( V_4 -> V_5 ,
F_11 ( V_4 -> V_5 ,
V_4 -> V_22 . V_20 ) ,
V_24 , V_23 , & V_11 , V_21 * 1 ) ;
return V_12 ;
}
static int F_13 ( struct V_1 * V_4 ,
int V_23 , T_2 * V_16 ,
T_2 * V_24 )
{
struct V_9 V_10 ;
int V_25 , V_11 , V_12 ;
V_10 . V_10 = F_7 ( V_28 ) ;
V_10 . V_14 . V_27 . V_11 = V_23 ;
for ( V_25 = 0 ; V_25 < V_23 ; V_25 ++ ) {
V_10 . V_14 . V_29 . V_30 [ V_25 ] . V_16 = V_16 [ V_25 ] ;
V_10 . V_14 . V_29 . V_30 [ V_25 ] . V_24 = V_24 [ V_25 ] ;
}
V_12 = F_9 ( V_4 -> V_5 ,
F_10 ( V_4 -> V_5 ,
V_4 -> V_19 . V_20 ) ,
& V_10 , 32 , & V_11 , V_21 * 1 ) ;
return V_12 ;
}
static int F_14 ( struct V_1 * V_4 , int V_23 ,
struct V_31 * V_32 )
{
struct V_9 V_10 ;
int V_25 , V_11 , V_12 ;
V_10 . V_10 = F_7 ( V_33 ) ;
V_10 . V_14 . V_34 . V_11 = V_23 ;
for ( V_25 = 0 ; V_25 < V_23 ; V_25 ++ )
V_10 . V_14 . V_34 . V_32 [ V_25 ] = V_32 [ V_25 ] ;
V_12 = F_9 ( V_4 -> V_5 ,
F_10 ( V_4 -> V_5 ,
V_4 -> V_19 . V_20 ) ,
& V_10 , 32 , & V_11 , V_21 * 1 ) ;
return V_12 ;
}
static int F_15 ( struct V_35 * V_36 , T_2 * V_37 )
{
int V_38 = - V_39 ;
F_16 ( & V_36 -> V_40 ) ;
if ( V_36 -> V_41 ) {
T_2 V_42 [ 2 ] = { V_43 , V_44 } ;
T_2 V_24 [ 2 ] ;
V_38 = F_12 ( V_36 -> V_41 , 2 , V_42 ,
V_24 ) ;
if ( V_38 == 0 ) {
* V_37 = ( V_24 [ 0 ] & 0x7f ) | ( ( V_24 [ 1 ] & 0x08 ) << 4 ) ;
}
}
F_17 ( & V_36 -> V_40 ) ;
return V_38 ;
}
static int F_18 ( struct V_35 * V_36 , T_2 V_37 )
{
int V_38 = - V_39 ;
F_16 ( & V_36 -> V_40 ) ;
if ( V_36 -> V_41 ) {
T_2 V_42 [ 1 ] ;
T_2 V_24 [ 1 ] ;
V_42 [ 0 ] = V_45 ;
V_24 [ 0 ] = V_37 ;
V_38 = F_13 ( V_36 -> V_41 , 1 , V_42 ,
V_24 ) ;
V_36 -> V_41 -> V_46 = V_37 ;
}
F_17 ( & V_36 -> V_40 ) ;
return V_38 ;
}
static int F_19 ( struct V_35 * V_36 , T_2 * V_37 )
{
int V_38 = - V_39 ;
F_16 ( & V_36 -> V_40 ) ;
if ( V_36 -> V_41 ) {
* V_37 = V_36 -> V_41 -> V_46 ;
V_38 = 0 ;
}
F_17 ( & V_36 -> V_40 ) ;
return V_38 ;
}
static void F_20 ( struct V_1 * V_4 ,
struct V_31 * V_32 , int V_47 )
{
if ( V_4 -> V_48 == V_49 ) {
V_32 -> V_16 = V_44 ;
V_32 -> V_50 = 0xe0 ;
V_32 -> V_51 = V_47 << 5 ;
} else {
V_32 -> V_16 = V_52 ;
V_32 -> V_50 = 0xff ;
V_32 -> V_51 = V_47 & 0x07 ;
}
}
static void F_21 ( struct V_1 * V_4 ,
struct V_31 * V_32 ,
enum V_53 V_54 )
{
if ( V_4 -> V_48 == V_49 ) {
V_54 <<= 1 ;
}
V_32 -> V_16 = V_55 ;
V_32 -> V_50 = V_56 |
V_57 | V_58 ;
switch ( V_54 ) {
case V_59 :
V_32 -> V_51 = V_56 |
V_57 ;
break;
case V_60 :
V_32 -> V_51 = 0x00 ;
break;
case V_61 :
V_32 -> V_51 = V_58 ;
break;
case V_62 :
V_32 -> V_51 = V_57 ;
break;
case V_63 :
V_32 -> V_51 = V_57 |
V_58 ;
break;
case V_64 :
V_32 -> V_51 = V_56 ;
break;
default:
F_22 ( & V_4 -> V_65 -> V_4 , L_1 , V_54 ) ;
}
}
static int F_23 ( struct V_35 * V_36 , int V_47 , T_3 * V_24 ,
enum V_53 V_54 )
{
struct V_31 V_32 [ 3 ] ;
T_2 V_42 [ 3 ] = {
V_66 ,
V_67 ,
V_68
} ;
T_2 V_69 [ 3 ] ;
int V_38 = - V_39 ;
F_16 ( & V_36 -> V_40 ) ;
if ( ! V_36 -> V_41 )
goto exit;
F_21 ( V_36 -> V_41 , & V_32 [ 0 ] , V_54 ) ;
F_20 ( V_36 -> V_41 , & V_32 [ 1 ] , V_47 ) ;
V_32 [ 2 ] . V_16 = V_66 ;
V_32 [ 2 ] . V_50 = 0xff ;
V_32 [ 2 ] . V_51 = V_70 | V_71 ;
V_38 = F_14 ( V_36 -> V_41 , 3 , V_32 ) ;
if ( V_38 )
goto exit;
V_38 = F_12 ( V_36 -> V_41 , 3 , V_42 , V_69 ) ;
if ( V_38 )
goto exit;
if ( ( V_69 [ 0 ] & ( V_72 | V_71 ) ) ==
V_72 ) {
switch ( V_36 -> V_41 -> V_48 ) {
case V_49 :
* V_24 = ( ( V_69 [ 1 ] << 8 ) | V_69 [ 2 ] ) + 0x800 ;
break;
case V_73 :
* V_24 = ( V_69 [ 1 ] << 8 ) | V_69 [ 2 ] ;
break;
}
}
exit:
F_17 ( & V_36 -> V_40 ) ;
return V_38 ;
}
static int F_24 ( struct V_35 * V_36 , int V_47 ,
T_3 * V_24 )
{
int V_38 = - V_39 ;
F_16 ( & V_36 -> V_40 ) ;
if ( V_36 -> V_41 ) {
* V_24 = V_36 -> V_41 -> V_74 [ V_47 ] ;
V_38 = 0 ;
}
F_17 ( & V_36 -> V_40 ) ;
return V_38 ;
}
static int F_25 ( struct V_35 * V_36 , int V_47 , T_3 V_24 )
{
int V_38 = - V_39 ;
F_16 ( & V_36 -> V_40 ) ;
if ( V_36 -> V_41 ) {
struct V_31 V_32 [ 3 ] ;
switch ( V_47 ) {
case 0 :
V_32 [ 0 ] . V_16 = V_75 ;
V_32 [ 0 ] . V_50 = 0xff ;
V_32 [ 0 ] . V_51 = V_76 ;
V_32 [ 1 ] . V_16 = V_77 ;
V_32 [ 1 ] . V_50 = 0xff ;
V_32 [ 1 ] . V_51 = V_24 & 0xff ;
V_32 [ 2 ] . V_16 = V_78 ;
V_32 [ 2 ] . V_50 = 0xff ;
V_32 [ 2 ] . V_51 = ( V_24 >> 8 ) & 0xf ;
break;
case 1 :
V_32 [ 0 ] . V_16 = V_79 ;
V_32 [ 0 ] . V_50 = 0xff ;
V_32 [ 0 ] . V_51 = V_76 ;
V_32 [ 1 ] . V_16 = V_80 ;
V_32 [ 1 ] . V_50 = 0xff ;
V_32 [ 1 ] . V_51 = V_24 & 0xff ;
V_32 [ 2 ] . V_16 = V_81 ;
V_32 [ 2 ] . V_50 = 0xff ;
V_32 [ 2 ] . V_51 = ( V_24 >> 8 ) & 0xf ;
break;
}
V_38 = F_14 ( V_36 -> V_41 , 3 , V_32 ) ;
V_36 -> V_41 -> V_74 [ V_47 ] = V_24 ;
}
F_17 ( & V_36 -> V_40 ) ;
return V_38 ;
}
static int F_26 ( struct V_82 * V_65 ,
const struct V_83 * V_84 )
{
int V_12 = - V_85 ;
struct V_1 * V_4 = NULL ;
struct V_86 * V_87 ;
struct V_88 * V_89 ;
int V_25 ;
T_2 V_90 ;
V_4 = F_27 ( sizeof( * V_4 ) , V_91 ) ;
if ( V_4 == NULL )
goto error;
F_28 ( & V_4 -> V_2 ) ;
V_4 -> V_5 = F_29 ( F_30 ( V_65 ) ) ;
V_4 -> V_65 = V_65 ;
V_87 = V_65 -> V_92 ;
if ( V_87 -> V_93 . V_94 != 5 ) {
F_22 ( & V_65 -> V_4 , L_2 ) ;
V_12 = - V_39 ;
goto error;
}
for ( V_25 = 0 ; V_25 < V_87 -> V_93 . V_94 ; ++ V_25 ) {
int V_95 = - 1 ;
V_89 = & V_87 -> V_89 [ V_25 ] . V_93 ;
switch ( V_25 ) {
case 0 :
V_95 = V_96 ;
V_4 -> V_97 . V_20 = V_89 -> V_98 ;
V_4 -> V_97 . V_99 =
F_31 ( V_89 -> V_100 ) ;
break;
case 1 :
V_95 = V_101 ;
V_4 -> V_19 . V_20 = V_89 -> V_98 ;
V_4 -> V_19 . V_99 =
F_31 ( V_89 -> V_100 ) ;
break;
case 2 :
V_95 = V_96 ;
V_4 -> V_22 . V_20 = V_89 -> V_98 ;
V_4 -> V_22 . V_99 =
F_31 ( V_89 -> V_100 ) ;
break;
case 3 :
V_95 = V_101 ;
V_4 -> V_102 . V_20 = V_89 -> V_98 ;
V_4 -> V_102 . V_99 =
F_31 ( V_89 -> V_100 ) ;
break;
case 4 :
V_95 = V_96 ;
V_4 -> V_103 . V_20 = V_89 -> V_98 ;
V_4 -> V_103 . V_99 =
F_31 ( V_89 -> V_100 ) ;
break;
}
if ( ( V_89 -> V_98 & V_96 ) != V_95 ) {
F_22 ( & V_65 -> V_4 ,
L_3 ) ;
V_12 = - V_39 ;
goto error;
}
}
if ( F_6 ( V_4 , 0 , & V_90 , sizeof( V_90 ) ) != 0 ) {
F_32 ( V_4 -> V_5 ) ;
for ( V_25 = 0 ; V_25 < 10 ; V_25 ++ ) {
V_12 = F_6 ( V_4 , 1 , & V_90 , sizeof( V_90 ) ) ;
if ( V_12 == 0 ) {
F_33 ( & V_65 -> V_4 ,
L_4
L_5 , V_25 ) ;
break;
}
}
}
if ( F_6 ( V_4 , 1 , & V_4 -> V_104 , sizeof( V_4 -> V_104 ) ) != 0 ) {
F_22 ( & V_65 -> V_4 , L_6 ) ;
V_12 = - V_39 ;
goto error;
}
if ( F_6 ( V_4 , 3 , & V_4 -> V_105 , sizeof( V_4 -> V_105 ) ) != 0 ) {
F_22 ( & V_65 -> V_4 , L_7 ) ;
V_12 = - V_39 ;
goto error;
}
if ( F_6 ( V_4 , 5 , & V_4 -> V_48 , sizeof( V_4 -> V_48 ) ) != 0 ) {
F_22 ( & V_65 -> V_4 , L_8 ) ;
V_12 = - V_39 ;
goto error;
}
if ( F_6 ( V_4 , 7 , & V_4 -> V_106 , sizeof( V_4 -> V_106 ) ) != 0 ) {
F_22 ( & V_65 -> V_4 , L_9 ) ;
V_12 = - V_39 ;
goto error;
}
V_4 -> V_104 = F_31 ( V_4 -> V_104 ) ;
V_4 -> V_105 = F_31 ( V_4 -> V_105 ) ;
V_4 -> V_48 = F_31 ( V_4 -> V_48 ) ;
V_4 -> V_106 = F_34 ( V_4 -> V_106 ) ;
switch ( V_4 -> V_48 ) {
case V_49 :
V_4 -> V_74 [ 0 ] = 0x0800 ;
V_4 -> V_74 [ 1 ] = 0x800 ;
break;
case V_73 :
V_4 -> V_74 [ 0 ] = 0x0000 ;
V_4 -> V_74 [ 1 ] = 0x0000 ;
break;
}
V_4 -> V_46 = 0 ;
F_35 ( V_65 , V_4 ) ;
F_33 ( & V_65 -> V_4 , L_10 ,
V_4 -> V_104 , V_4 -> V_105 , V_4 -> V_48 , V_4 -> V_106 ) ;
F_16 ( & V_107 ) ;
{
struct V_35 * V_108 = NULL ;
struct V_35 * V_109 = NULL ;
for ( V_25 = 0 ; V_25 < V_110 ; V_25 ++ ) {
if ( ! V_108 && ! V_111 [ V_25 ] . V_41 && V_111 [ V_25 ] . V_106 == 0 )
V_108 = & V_111 [ V_25 ] ;
if ( ! V_109 && V_111 [ V_25 ] . V_106 == V_4 -> V_106 )
V_109 = & V_111 [ V_25 ] ;
}
if ( ! V_109 )
V_109 = V_108 ;
if ( V_109 ) {
F_16 ( & V_109 -> V_40 ) ;
V_109 -> V_41 = V_4 ;
V_4 -> V_36 = V_109 ;
F_17 ( & V_109 -> V_40 ) ;
}
}
F_17 ( & V_107 ) ;
return 0 ;
error:
if ( V_4 )
F_36 ( & V_4 -> V_2 , F_3 ) ;
return V_12 ;
}
static void F_37 ( struct V_82 * V_65 )
{
struct V_1 * V_4 ;
int V_112 = V_65 -> V_112 ;
F_16 ( & V_107 ) ;
V_4 = F_38 ( V_65 ) ;
if ( V_4 -> V_36 ) {
F_16 ( & V_4 -> V_36 -> V_40 ) ;
V_4 -> V_36 -> V_41 = NULL ;
F_17 ( & V_4 -> V_36 -> V_40 ) ;
V_4 -> V_36 = NULL ;
}
F_35 ( V_65 , NULL ) ;
F_17 ( & V_107 ) ;
F_36 ( & V_4 -> V_2 , F_3 ) ;
F_33 ( & V_65 -> V_4 , L_11 , V_112 ) ;
}
static int F_39 ( struct V_113 * V_4 )
{
struct V_114 * V_115 = V_4 -> V_116 ;
int V_38 = - V_39 ;
F_16 ( & V_115 -> V_36 -> V_40 ) ;
if ( V_115 -> V_36 -> V_41 ) {
struct V_117 * V_118 ;
V_118 = & V_4 -> V_119 [ 0 ] ;
V_118 -> V_120 = 8 ;
V_118 -> V_121 = 1 ;
V_118 = & V_4 -> V_119 [ 1 ] ;
V_118 -> V_120 = 8 ;
V_118 -> V_121 = 1 ;
V_118 = & V_4 -> V_119 [ 2 ] ;
V_118 -> V_120 = 8 ;
switch ( V_115 -> V_36 -> V_41 -> V_48 ) {
case 0 : {
V_118 -> V_121 = 4095 ;
V_118 -> V_122 = & V_123 ;
}
break;
case 1 : {
V_118 -> V_121 = 4095 ;
V_118 -> V_122 = & V_124 ;
}
break;
}
V_118 = & V_4 -> V_119 [ 3 ] ;
V_118 -> V_120 = 2 ;
switch ( V_115 -> V_36 -> V_41 -> V_48 ) {
case 0 : {
V_118 -> V_121 = 4095 ;
V_118 -> V_122 = & V_123 ;
}
break;
case 1 : {
V_118 -> V_121 = 4095 ;
V_118 -> V_122 = & V_124 ;
}
break;
}
V_38 = 0 ;
}
F_17 ( & V_115 -> V_36 -> V_40 ) ;
return V_38 ;
}
static int F_40 ( struct V_113 * V_4 ,
struct V_117 * V_118 , struct V_125 * V_126 ,
unsigned int * V_127 )
{
struct V_114 * V_115 = V_4 -> V_116 ;
unsigned int V_47 = F_41 ( V_126 -> V_128 ) ;
int V_129 ;
T_2 V_37 = 0 ;
F_15 ( V_115 -> V_36 , & V_37 ) ;
for ( V_129 = 0 ; V_129 < V_126 -> V_129 ; V_129 ++ )
V_127 [ V_129 ] = ( ( 1 << V_47 ) & V_37 ) != 0 ;
return V_129 ;
}
static int F_42 ( struct V_113 * V_4 ,
struct V_117 * V_118 , struct V_125 * V_126 ,
unsigned int * V_127 )
{
struct V_114 * V_115 = V_4 -> V_116 ;
unsigned int V_47 = F_41 ( V_126 -> V_128 ) ;
int V_129 ;
T_2 V_37 = 0 ;
F_19 ( V_115 -> V_36 , & V_37 ) ;
for ( V_129 = 0 ; V_129 < V_126 -> V_129 ; V_129 ++ ) {
T_2 V_130 = 1 << V_47 ;
V_37 &= ~ V_130 ;
if ( V_127 [ V_129 ] )
V_37 |= V_130 ;
}
F_18 ( V_115 -> V_36 , V_37 ) ;
return V_129 ;
}
static int F_43 ( struct V_113 * V_4 ,
struct V_117 * V_118 , struct V_125 * V_126 ,
unsigned int * V_127 )
{
struct V_114 * V_115 = V_4 -> V_116 ;
unsigned int V_47 = F_41 ( V_126 -> V_128 ) ;
int V_129 ;
for ( V_129 = 0 ; V_129 < V_126 -> V_129 ; V_129 ++ ) {
T_3 V_24 = 0 ;
F_23 ( V_115 -> V_36 , V_47 , & V_24 , V_60 ) ;
V_127 [ V_129 ] = V_24 ;
}
return V_129 ;
}
static int F_44 ( struct V_113 * V_4 ,
struct V_117 * V_118 , struct V_125 * V_126 ,
unsigned int * V_127 )
{
struct V_114 * V_115 = V_4 -> V_116 ;
unsigned int V_47 = F_41 ( V_126 -> V_128 ) ;
int V_129 ;
T_3 V_24 ;
for ( V_129 = 0 ; V_129 < V_126 -> V_129 ; V_129 ++ ) {
V_24 = 0 ;
F_24 ( V_115 -> V_36 , V_47 , & V_24 ) ;
V_127 [ V_129 ] = V_24 ;
}
return V_129 ;
}
static int F_45 ( struct V_113 * V_4 ,
struct V_117 * V_118 , struct V_125 * V_126 ,
unsigned int * V_127 )
{
struct V_114 * V_115 = V_4 -> V_116 ;
unsigned int V_47 = F_41 ( V_126 -> V_128 ) ;
int V_129 ;
for ( V_129 = 0 ; V_129 < V_126 -> V_129 ; V_129 ++ )
F_25 ( V_115 -> V_36 , V_47 , V_127 [ V_129 ] ) ;
return V_129 ;
}
static int F_46 ( struct V_113 * V_4 , struct V_131 * V_132 )
{
struct V_114 * V_115 ;
int V_25 ;
struct V_117 * V_118 ;
int V_133 ;
V_115 = F_27 ( sizeof( * V_115 ) , V_91 ) ;
if ( ! V_115 )
return - V_85 ;
V_4 -> V_116 = V_115 ;
V_4 -> V_134 = F_39 ;
V_115 -> V_106 = V_132 -> V_135 [ 0 ] ;
V_133 = F_47 ( V_4 , 4 ) ;
if ( V_133 )
return V_133 ;
V_118 = & V_4 -> V_119 [ 0 ] ;
V_118 -> type = V_136 ;
V_118 -> V_137 = V_138 ;
V_118 -> V_120 = 0 ;
V_118 -> V_121 = 1 ;
V_118 -> V_122 = & V_139 ;
V_118 -> V_140 = & F_40 ;
V_118 = & V_4 -> V_119 [ 1 ] ;
V_118 -> type = V_141 ;
V_118 -> V_137 = V_142 ;
V_118 -> V_120 = 0 ;
V_118 -> V_121 = 1 ;
V_118 -> V_122 = & V_139 ;
V_118 -> V_143 = & F_42 ;
V_118 = & V_4 -> V_119 [ 2 ] ;
V_118 -> type = V_144 ;
V_118 -> V_137 = V_138 | V_145 ;
V_118 -> V_120 = 0 ;
V_118 -> V_121 = 1 ;
V_118 -> V_122 = NULL ;
V_118 -> V_140 = & F_43 ;
V_118 = & V_4 -> V_119 [ 3 ] ;
V_118 -> type = V_146 ;
V_118 -> V_137 = V_142 ;
V_118 -> V_120 = 0 ;
V_118 -> V_121 = 1 ;
V_118 -> V_122 = NULL ;
V_118 -> V_143 = & F_45 ;
V_118 -> V_140 = & F_44 ;
F_33 ( V_4 -> V_147 , L_12 ) ;
F_16 ( & V_107 ) ;
{
struct V_35 * V_108 = NULL ;
struct V_35 * V_109 = NULL ;
for ( V_25 = 0 ; V_25 < V_110 ; V_25 ++ ) {
if ( ! V_108 && ! V_111 [ V_25 ] . V_148 ) {
V_108 = & V_111 [ V_25 ] ;
}
if ( ! V_109 &&
V_111 [ V_25 ] . V_41 &&
V_111 [ V_25 ] . V_41 -> V_106 == V_115 -> V_106 ) {
V_109 = & V_111 [ V_25 ] ;
}
}
if ( ! V_109 )
V_109 = V_108 ;
if ( V_109 ) {
F_16 ( & V_109 -> V_40 ) ;
V_109 -> V_148 = V_115 ;
V_109 -> V_106 = V_115 -> V_106 ;
V_115 -> V_36 = V_109 ;
F_17 ( & V_109 -> V_40 ) ;
}
}
F_17 ( & V_107 ) ;
return 0 ;
}
static void F_48 ( struct V_113 * V_4 )
{
}
static int T_4 F_49 ( void )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_110 ; V_25 ++ ) {
F_50 ( & V_111 [ V_25 ] . V_40 , 1 ) ;
V_111 [ V_25 ] . V_106 = 0 ;
V_111 [ V_25 ] . V_41 = NULL ;
V_111 [ V_25 ] . V_148 = NULL ;
}
V_111 [ 12 ] . V_106 = 0x0 ;
return F_51 ( & V_149 ,
& V_150 ) ;
}
static void T_5 F_52 ( void )
{
F_53 ( & V_149 , & V_150 ) ;
}
