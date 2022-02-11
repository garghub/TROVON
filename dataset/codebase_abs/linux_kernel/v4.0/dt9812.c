static int F_1 ( struct V_1 * V_2 ,
int V_3 , void * V_4 , T_1 V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 V_12 ;
int V_13 , V_14 ;
V_12 . V_12 = F_3 ( V_15 ) ;
V_12 . V_16 . V_17 . V_18 =
F_4 ( V_19 + V_3 ) ;
V_12 . V_16 . V_17 . V_20 = F_4 ( V_5 ) ;
V_14 = F_5 ( V_7 , F_6 ( V_7 , V_9 -> V_21 . V_22 ) ,
& V_12 , 32 , & V_13 , V_23 ) ;
if ( V_14 )
return V_14 ;
return F_5 ( V_7 , F_7 ( V_7 , V_9 -> V_24 . V_22 ) ,
V_4 , V_5 , & V_13 , V_23 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
int V_25 , T_2 * V_18 ,
T_2 * V_26 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 V_12 ;
int V_27 , V_13 , V_14 ;
V_12 . V_12 = F_3 ( V_28 ) ;
V_12 . V_16 . V_29 . V_13 = V_25 ;
for ( V_27 = 0 ; V_27 < V_25 ; V_27 ++ )
V_12 . V_16 . V_29 . V_18 [ V_27 ] = V_18 [ V_27 ] ;
V_14 = F_5 ( V_7 , F_6 ( V_7 , V_9 -> V_21 . V_22 ) ,
& V_12 , 32 , & V_13 , V_23 ) ;
if ( V_14 )
return V_14 ;
return F_5 ( V_7 , F_7 ( V_7 , V_9 -> V_24 . V_22 ) ,
V_26 , V_25 , & V_13 , V_23 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
int V_25 , T_2 * V_18 ,
T_2 * V_26 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 V_12 ;
int V_27 , V_13 ;
V_12 . V_12 = F_3 ( V_30 ) ;
V_12 . V_16 . V_29 . V_13 = V_25 ;
for ( V_27 = 0 ; V_27 < V_25 ; V_27 ++ ) {
V_12 . V_16 . V_31 . V_32 [ V_27 ] . V_18 = V_18 [ V_27 ] ;
V_12 . V_16 . V_31 . V_32 [ V_27 ] . V_26 = V_26 [ V_27 ] ;
}
return F_5 ( V_7 , F_6 ( V_7 , V_9 -> V_21 . V_22 ) ,
& V_12 , 32 , & V_13 , V_23 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
int V_25 ,
struct V_33 * V_34 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 V_12 ;
int V_27 , V_13 ;
V_12 . V_12 = F_3 ( V_35 ) ;
V_12 . V_16 . V_36 . V_13 = V_25 ;
for ( V_27 = 0 ; V_27 < V_25 ; V_27 ++ )
V_12 . V_16 . V_36 . V_34 [ V_27 ] = V_34 [ V_27 ] ;
return F_5 ( V_7 , F_6 ( V_7 , V_9 -> V_21 . V_22 ) ,
& V_12 , 32 , & V_13 , V_23 ) ;
}
static int F_11 ( struct V_1 * V_2 , T_2 * V_37 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
T_2 V_38 [ 2 ] = { V_39 , V_40 } ;
T_2 V_26 [ 2 ] ;
int V_14 ;
F_12 ( & V_9 -> V_41 ) ;
V_14 = F_8 ( V_2 , 2 , V_38 , V_26 ) ;
if ( V_14 == 0 ) {
* V_37 = ( V_26 [ 0 ] & 0x7f ) | ( ( V_26 [ 1 ] & 0x08 ) << 4 ) ;
}
F_13 ( & V_9 -> V_41 ) ;
return V_14 ;
}
static int F_14 ( struct V_1 * V_2 , T_2 V_37 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
T_2 V_38 [ 1 ] = { V_42 } ;
T_2 V_26 [ 1 ] = { V_37 } ;
int V_14 ;
F_12 ( & V_9 -> V_41 ) ;
V_14 = F_9 ( V_2 , 1 , V_38 , V_26 ) ;
F_13 ( & V_9 -> V_41 ) ;
return V_14 ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_33 * V_34 , int V_43 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
if ( V_9 -> V_44 == V_45 ) {
V_34 -> V_18 = V_40 ;
V_34 -> V_46 = 0xe0 ;
V_34 -> V_47 = V_43 << 5 ;
} else {
V_34 -> V_18 = V_48 ;
V_34 -> V_46 = 0xff ;
V_34 -> V_47 = V_43 & 0x07 ;
}
}
static void F_16 ( struct V_1 * V_2 ,
struct V_33 * V_34 ,
enum V_49 V_50 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
if ( V_9 -> V_44 == V_45 )
V_50 <<= 1 ;
V_34 -> V_18 = V_51 ;
V_34 -> V_46 = V_52 |
V_53 |
V_54 ;
switch ( V_50 ) {
case V_55 :
V_34 -> V_47 = V_52 |
V_53 ;
break;
default:
case V_56 :
V_34 -> V_47 = 0x00 ;
break;
case V_57 :
V_34 -> V_47 = V_54 ;
break;
case V_58 :
V_34 -> V_47 = V_53 ;
break;
case V_59 :
V_34 -> V_47 = V_53 |
V_54 ;
break;
case V_60 :
V_34 -> V_47 = V_52 ;
break;
}
}
static int F_17 ( struct V_1 * V_2 ,
int V_43 , T_3 * V_26 , enum V_49 V_50 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_33 V_34 [ 3 ] ;
T_2 V_38 [ 3 ] = {
V_61 ,
V_62 ,
V_63
} ;
T_2 V_64 [ 3 ] ;
int V_14 ;
F_12 ( & V_9 -> V_41 ) ;
F_16 ( V_2 , & V_34 [ 0 ] , V_50 ) ;
F_15 ( V_2 , & V_34 [ 1 ] , V_43 ) ;
V_34 [ 2 ] . V_18 = V_61 ;
V_34 [ 2 ] . V_46 = 0xff ;
V_34 [ 2 ] . V_47 = V_65 | V_66 ;
V_14 = F_10 ( V_2 , 3 , V_34 ) ;
if ( V_14 )
goto exit;
V_14 = F_8 ( V_2 , 3 , V_38 , V_64 ) ;
if ( V_14 )
goto exit;
if ( ( V_64 [ 0 ] & ( V_67 | V_66 ) ) ==
V_67 ) {
switch ( V_9 -> V_44 ) {
case V_45 :
* V_26 = ( ( V_64 [ 1 ] << 8 ) | V_64 [ 2 ] ) + 0x800 ;
break;
case V_68 :
* V_26 = ( V_64 [ 1 ] << 8 ) | V_64 [ 2 ] ;
break;
}
}
exit:
F_13 ( & V_9 -> V_41 ) ;
return V_14 ;
}
static int F_18 ( struct V_1 * V_2 , int V_43 , T_3 V_26 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_33 V_34 [ 3 ] ;
int V_14 ;
F_12 ( & V_9 -> V_41 ) ;
switch ( V_43 ) {
case 0 :
V_34 [ 0 ] . V_18 = V_69 ;
V_34 [ 0 ] . V_46 = 0xff ;
V_34 [ 0 ] . V_47 = V_70 ;
V_34 [ 1 ] . V_18 = V_71 ;
V_34 [ 1 ] . V_46 = 0xff ;
V_34 [ 1 ] . V_47 = V_26 & 0xff ;
V_34 [ 2 ] . V_18 = V_72 ;
V_34 [ 2 ] . V_46 = 0xff ;
V_34 [ 2 ] . V_47 = ( V_26 >> 8 ) & 0xf ;
break;
case 1 :
V_34 [ 0 ] . V_18 = V_73 ;
V_34 [ 0 ] . V_46 = 0xff ;
V_34 [ 0 ] . V_47 = V_70 ;
V_34 [ 1 ] . V_18 = V_74 ;
V_34 [ 1 ] . V_46 = 0xff ;
V_34 [ 1 ] . V_47 = V_26 & 0xff ;
V_34 [ 2 ] . V_18 = V_75 ;
V_34 [ 2 ] . V_46 = 0xff ;
V_34 [ 2 ] . V_47 = ( V_26 >> 8 ) & 0xf ;
break;
}
V_14 = F_10 ( V_2 , 3 , V_34 ) ;
F_13 ( & V_9 -> V_41 ) ;
return V_14 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_76 * V_77 ,
struct V_78 * V_79 ,
unsigned int * V_80 )
{
T_2 V_37 = 0 ;
int V_14 ;
V_14 = F_11 ( V_2 , & V_37 ) ;
if ( V_14 )
return V_14 ;
V_80 [ 1 ] = V_37 ;
return V_79 -> V_81 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_76 * V_77 ,
struct V_78 * V_79 ,
unsigned int * V_80 )
{
if ( F_21 ( V_77 , V_80 ) )
F_14 ( V_2 , V_77 -> V_82 ) ;
V_80 [ 1 ] = V_77 -> V_82 ;
return V_79 -> V_81 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_76 * V_77 ,
struct V_78 * V_79 ,
unsigned int * V_80 )
{
unsigned int V_83 = F_23 ( V_79 -> V_84 ) ;
T_3 V_64 = 0 ;
int V_14 ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_79 -> V_81 ; V_27 ++ ) {
V_14 = F_17 ( V_2 , V_83 , & V_64 , V_56 ) ;
if ( V_14 )
return V_14 ;
V_80 [ V_27 ] = V_64 ;
}
return V_79 -> V_81 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_76 * V_77 ,
struct V_78 * V_79 ,
unsigned int * V_80 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_14 ;
F_12 ( & V_9 -> V_41 ) ;
V_14 = F_25 ( V_2 , V_77 , V_79 , V_80 ) ;
F_13 ( & V_9 -> V_41 ) ;
return V_14 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_76 * V_77 ,
struct V_78 * V_79 ,
unsigned int * V_80 )
{
unsigned int V_83 = F_23 ( V_79 -> V_84 ) ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_79 -> V_81 ; V_27 ++ ) {
unsigned int V_64 = V_80 [ V_27 ] ;
int V_14 ;
V_14 = F_18 ( V_2 , V_83 , V_64 ) ;
if ( V_14 )
return V_14 ;
V_77 -> V_85 [ V_83 ] = V_64 ;
}
return V_79 -> V_81 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_86 * V_87 = F_28 ( V_2 ) ;
struct V_88 * V_89 = V_87 -> V_90 ;
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_91 * V_92 ;
int V_27 ;
if ( V_89 -> V_93 . V_94 != 5 ) {
F_29 ( V_2 -> V_95 , L_1 ) ;
return - V_96 ;
}
for ( V_27 = 0 ; V_27 < V_89 -> V_93 . V_94 ; ++ V_27 ) {
int V_97 = - 1 ;
V_92 = & V_89 -> V_98 [ V_27 ] . V_93 ;
switch ( V_27 ) {
case 0 :
V_97 = V_99 ;
break;
case 1 :
V_97 = V_100 ;
V_9 -> V_21 . V_22 = V_92 -> V_101 ;
V_9 -> V_21 . V_102 = F_30 ( V_92 -> V_103 ) ;
break;
case 2 :
V_97 = V_99 ;
V_9 -> V_24 . V_22 = V_92 -> V_101 ;
V_9 -> V_24 . V_102 = F_30 ( V_92 -> V_103 ) ;
break;
case 3 :
V_97 = V_100 ;
break;
case 4 :
V_97 = V_99 ;
break;
}
if ( ( V_92 -> V_101 & V_99 ) != V_97 ) {
F_29 ( V_2 -> V_95 ,
L_2 ) ;
return - V_96 ;
}
}
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_2 -> V_10 ;
T_4 V_104 ;
T_3 V_105 ;
T_3 V_106 ;
T_2 V_107 ;
T_5 V_108 ;
T_6 V_109 ;
int V_14 ;
int V_27 ;
V_14 = F_1 ( V_2 , 0 , & V_107 , sizeof( V_107 ) ) ;
if ( V_14 ) {
F_32 ( V_7 ) ;
for ( V_27 = 0 ; V_27 < 10 ; V_27 ++ ) {
V_14 = F_1 ( V_2 , 1 , & V_107 , sizeof( V_107 ) ) ;
if ( V_14 == 0 )
break;
}
if ( V_14 ) {
F_29 ( V_2 -> V_95 ,
L_3 ) ;
return V_14 ;
}
}
V_14 = F_1 ( V_2 , 1 , & V_108 , sizeof( V_108 ) ) ;
if ( V_14 ) {
F_29 ( V_2 -> V_95 , L_4 ) ;
return V_14 ;
}
V_105 = F_30 ( V_108 ) ;
V_14 = F_1 ( V_2 , 3 , & V_108 , sizeof( V_108 ) ) ;
if ( V_14 ) {
F_29 ( V_2 -> V_95 , L_5 ) ;
return V_14 ;
}
V_106 = F_30 ( V_108 ) ;
V_14 = F_1 ( V_2 , 5 , & V_108 , sizeof( V_108 ) ) ;
if ( V_14 ) {
F_29 ( V_2 -> V_95 , L_6 ) ;
return V_14 ;
}
V_9 -> V_44 = F_30 ( V_108 ) ;
V_14 = F_1 ( V_2 , 7 , & V_109 , sizeof( V_109 ) ) ;
if ( V_14 ) {
F_29 ( V_2 -> V_95 , L_7 ) ;
return V_14 ;
}
V_104 = F_33 ( V_109 ) ;
F_34 ( V_2 -> V_95 , L_8 ,
V_105 , V_106 , V_9 -> V_44 , V_104 ) ;
if ( V_9 -> V_44 != V_45 &&
V_9 -> V_44 != V_68 ) {
F_29 ( V_2 -> V_95 , L_9 ) ;
return - V_110 ;
}
return 0 ;
}
static int F_35 ( struct V_1 * V_2 ,
unsigned long V_111 )
{
struct V_86 * V_87 = F_28 ( V_2 ) ;
struct V_8 * V_9 ;
struct V_76 * V_77 ;
bool V_112 ;
int V_14 ;
int V_27 ;
V_9 = F_36 ( V_2 , sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - V_113 ;
F_37 ( & V_9 -> V_41 , 1 ) ;
F_38 ( V_87 , V_9 ) ;
V_14 = F_27 ( V_2 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_31 ( V_2 ) ;
if ( V_14 )
return V_14 ;
V_112 = ( V_9 -> V_44 == V_68 ) ;
V_14 = F_39 ( V_2 , 4 ) ;
if ( V_14 )
return V_14 ;
V_77 = & V_2 -> V_114 [ 0 ] ;
V_77 -> type = V_115 ;
V_77 -> V_116 = V_117 ;
V_77 -> V_118 = 8 ;
V_77 -> V_119 = 1 ;
V_77 -> V_120 = & V_121 ;
V_77 -> V_122 = F_19 ;
V_77 = & V_2 -> V_114 [ 1 ] ;
V_77 -> type = V_123 ;
V_77 -> V_116 = V_124 ;
V_77 -> V_118 = 8 ;
V_77 -> V_119 = 1 ;
V_77 -> V_120 = & V_121 ;
V_77 -> V_122 = F_20 ;
V_77 = & V_2 -> V_114 [ 2 ] ;
V_77 -> type = V_125 ;
V_77 -> V_116 = V_117 | V_126 ;
V_77 -> V_118 = 8 ;
V_77 -> V_119 = 0x0fff ;
V_77 -> V_120 = V_112 ? & V_127 : & V_128 ;
V_77 -> V_129 = F_22 ;
V_77 = & V_2 -> V_114 [ 3 ] ;
V_77 -> type = V_130 ;
V_77 -> V_116 = V_124 ;
V_77 -> V_118 = 2 ;
V_77 -> V_119 = 0x0fff ;
V_77 -> V_120 = V_112 ? & V_127 : & V_128 ;
V_77 -> V_131 = F_26 ;
V_77 -> V_129 = F_24 ;
V_14 = F_40 ( V_77 ) ;
if ( V_14 )
return V_14 ;
for ( V_27 = 0 ; V_27 < V_77 -> V_118 ; V_27 ++ )
V_77 -> V_85 [ V_27 ] = V_112 ? 0x0000 : 0x0800 ;
return 0 ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_86 * V_87 = F_28 ( V_2 ) ;
struct V_8 * V_9 = V_2 -> V_10 ;
if ( ! V_9 )
return;
F_12 ( & V_9 -> V_41 ) ;
F_38 ( V_87 , NULL ) ;
F_13 ( & V_9 -> V_41 ) ;
}
static int F_42 ( struct V_86 * V_87 ,
const struct V_132 * V_133 )
{
return F_43 ( V_87 , & V_134 , V_133 -> V_135 ) ;
}
