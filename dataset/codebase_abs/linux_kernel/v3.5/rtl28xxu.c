static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
unsigned int V_6 ;
T_1 V_7 ;
T_1 * V_8 ;
V_8 = F_2 ( V_4 -> V_9 , V_10 ) ;
if ( ! V_8 ) {
V_5 = - V_11 ;
goto V_12;
}
if ( V_4 -> V_13 & V_14 ) {
memcpy ( V_8 , V_4 -> V_15 , V_4 -> V_9 ) ;
V_7 = ( V_16 | V_17 ) ;
V_6 = F_3 ( V_2 -> V_18 , 0 ) ;
} else {
V_7 = ( V_16 | V_19 ) ;
V_6 = F_4 ( V_2 -> V_18 , 0 ) ;
}
V_5 = F_5 ( V_2 -> V_18 , V_6 , 0 , V_7 , V_4 -> V_20 ,
V_4 -> V_13 , V_8 , V_4 -> V_9 , 1000 ) ;
if ( V_5 > 0 )
V_5 = 0 ;
F_6 ( 0 , V_7 , V_4 -> V_20 , V_4 -> V_13 , V_8 , V_4 -> V_9 ,
V_21 ) ;
if ( ! V_5 && V_7 == ( V_16 | V_19 ) )
memcpy ( V_4 -> V_15 , V_8 , V_4 -> V_9 ) ;
F_7 ( V_8 ) ;
if ( V_5 )
goto V_12;
return V_5 ;
V_12:
F_8 ( L_1 , V_22 , V_5 ) ;
return V_5 ;
}
static int F_9 ( struct V_1 * V_2 , T_2 V_23 , T_1 * V_24 , int V_25 )
{
struct V_3 V_4 ;
if ( V_23 < 0x3000 )
V_4 . V_13 = V_26 ;
else if ( V_23 < 0x4000 )
V_4 . V_13 = V_27 ;
else
V_4 . V_13 = V_28 ;
V_4 . V_20 = V_23 ;
V_4 . V_9 = V_25 ;
V_4 . V_15 = V_24 ;
return F_1 ( V_2 , & V_4 ) ;
}
static int F_10 ( struct V_1 * V_2 , T_2 V_23 , T_1 * V_24 , int V_25 )
{
struct V_3 V_4 ;
if ( V_23 < 0x3000 )
V_4 . V_13 = V_29 ;
else if ( V_23 < 0x4000 )
V_4 . V_13 = V_30 ;
else
V_4 . V_13 = V_31 ;
V_4 . V_20 = V_23 ;
V_4 . V_9 = V_25 ;
V_4 . V_15 = V_24 ;
return F_1 ( V_2 , & V_4 ) ;
}
static int F_11 ( struct V_1 * V_2 , T_2 V_23 , T_1 V_24 )
{
return F_9 ( V_2 , V_23 , & V_24 , 1 ) ;
}
static int F_12 ( struct V_1 * V_2 , T_2 V_23 , T_1 * V_24 )
{
return F_10 ( V_2 , V_23 , V_24 , 1 ) ;
}
static int F_13 ( struct V_32 * V_33 , struct V_34 V_35 [] ,
int V_36 )
{
int V_5 ;
struct V_1 * V_2 = F_14 ( V_33 ) ;
struct V_37 * V_38 = V_2 -> V_38 ;
struct V_3 V_4 ;
if ( F_15 ( & V_2 -> V_39 ) < 0 )
return - V_40 ;
if ( V_36 == 2 && ! ( V_35 [ 0 ] . V_41 & V_42 ) &&
( V_35 [ 1 ] . V_41 & V_42 ) ) {
if ( V_35 [ 0 ] . V_25 > 24 || V_35 [ 1 ] . V_25 > 24 ) {
V_5 = - V_43 ;
goto V_44;
} else if ( V_35 [ 0 ] . V_45 == 0x10 ) {
V_4 . V_20 = ( V_35 [ 0 ] . V_8 [ 0 ] << 8 ) | ( V_35 [ 0 ] . V_45 << 1 ) ;
V_4 . V_13 = V_46 | V_38 -> V_47 ;
V_4 . V_9 = V_35 [ 1 ] . V_25 ;
V_4 . V_15 = & V_35 [ 1 ] . V_8 [ 0 ] ;
V_5 = F_1 ( V_2 , & V_4 ) ;
} else if ( V_35 [ 0 ] . V_25 < 2 ) {
V_4 . V_20 = ( V_35 [ 0 ] . V_8 [ 0 ] << 8 ) | ( V_35 [ 0 ] . V_45 << 1 ) ;
V_4 . V_13 = V_48 ;
V_4 . V_9 = V_35 [ 1 ] . V_25 ;
V_4 . V_15 = & V_35 [ 1 ] . V_8 [ 0 ] ;
V_5 = F_1 ( V_2 , & V_4 ) ;
} else {
V_4 . V_20 = ( V_35 [ 0 ] . V_45 << 1 ) ;
V_4 . V_13 = V_49 ;
V_4 . V_9 = V_35 [ 0 ] . V_25 ;
V_4 . V_15 = V_35 [ 0 ] . V_8 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_44;
V_4 . V_20 = ( V_35 [ 0 ] . V_45 << 1 ) ;
V_4 . V_13 = V_50 ;
V_4 . V_9 = V_35 [ 1 ] . V_25 ;
V_4 . V_15 = V_35 [ 1 ] . V_8 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
}
} else if ( V_36 == 1 && ! ( V_35 [ 0 ] . V_41 & V_42 ) ) {
if ( V_35 [ 0 ] . V_25 > 22 ) {
V_5 = - V_43 ;
goto V_44;
} else if ( V_35 [ 0 ] . V_45 == 0x10 ) {
if ( V_35 [ 0 ] . V_8 [ 0 ] == 0x00 ) {
V_38 -> V_47 = V_35 [ 0 ] . V_8 [ 1 ] ;
V_5 = 0 ;
} else {
V_4 . V_20 = ( V_35 [ 0 ] . V_8 [ 0 ] << 8 ) |
( V_35 [ 0 ] . V_45 << 1 ) ;
V_4 . V_13 = V_51 | V_38 -> V_47 ;
V_4 . V_9 = V_35 [ 0 ] . V_25 - 1 ;
V_4 . V_15 = & V_35 [ 0 ] . V_8 [ 1 ] ;
V_5 = F_1 ( V_2 , & V_4 ) ;
}
} else if ( V_35 [ 0 ] . V_25 < 23 ) {
V_4 . V_20 = ( V_35 [ 0 ] . V_8 [ 0 ] << 8 ) | ( V_35 [ 0 ] . V_45 << 1 ) ;
V_4 . V_13 = V_52 ;
V_4 . V_9 = V_35 [ 0 ] . V_25 - 1 ;
V_4 . V_15 = & V_35 [ 0 ] . V_8 [ 1 ] ;
V_5 = F_1 ( V_2 , & V_4 ) ;
} else {
V_4 . V_20 = ( V_35 [ 0 ] . V_45 << 1 ) ;
V_4 . V_13 = V_49 ;
V_4 . V_9 = V_35 [ 0 ] . V_25 ;
V_4 . V_15 = V_35 [ 0 ] . V_8 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
}
} else {
V_5 = - V_53 ;
}
V_44:
F_16 ( & V_2 -> V_39 ) ;
return V_5 ? V_5 : V_36 ;
}
static T_3 F_17 ( struct V_32 * V_54 )
{
return V_55 ;
}
static int F_18 ( struct V_56 * V_33 )
{
int V_5 ;
struct V_37 * V_38 = V_33 -> V_57 -> V_38 ;
T_1 V_8 [ 1 ] ;
struct V_58 * V_58 ;
struct V_3 V_59 = { 0x0120 , 0x0011 , 0x0001 , L_2 } ;
struct V_3 V_60 = { 0x00c0 , V_48 , 1 , V_8 } ;
struct V_3 V_61 = { 0x0fc4 , V_48 , 1 , V_8 } ;
F_8 ( L_3 , V_22 ) ;
V_5 = F_11 ( V_33 -> V_57 , V_62 , 0x0a ) ;
if ( V_5 )
goto V_12;
V_5 = F_11 ( V_33 -> V_57 , V_63 , 0x15 ) ;
if ( V_5 )
goto V_12;
F_19 ( 20 ) ;
V_5 = F_1 ( V_33 -> V_57 , & V_59 ) ;
if ( V_5 )
goto V_12;
V_5 = F_1 ( V_33 -> V_57 , & V_61 ) ;
if ( V_5 == 0 && V_8 [ 0 ] == 0x2c ) {
V_38 -> V_64 = V_65 ;
V_58 = & V_66 ;
F_8 ( L_4 , V_22 ) ;
goto V_67;
} else {
F_8 ( L_5 ,
V_22 , V_5 , V_8 [ 0 ] ) ;
}
V_5 = F_1 ( V_33 -> V_57 , & V_59 ) ;
if ( V_5 )
goto V_12;
V_5 = F_1 ( V_33 -> V_57 , & V_60 ) ;
if ( V_5 == 0 && V_8 [ 0 ] == 0x63 ) {
V_38 -> V_64 = V_68 ;
V_58 = & V_69 ;
F_8 ( L_6 , V_22 ) ;
goto V_67;
} else {
F_8 ( L_7 ,
V_22 , V_5 , V_8 [ 0 ] ) ;
}
V_5 = 0 ;
V_38 -> V_64 = V_70 ;
V_58 = & V_71 ;
F_8 ( L_8 , V_22 ) ;
goto V_67;
V_67:
V_33 -> V_72 [ 0 ] . V_73 = F_20 ( V_74 , V_58 ,
& V_33 -> V_57 -> V_75 ) ;
if ( V_33 -> V_72 [ 0 ] . V_73 == NULL ) {
V_5 = - V_76 ;
goto V_12;
}
return V_5 ;
V_12:
F_8 ( L_1 , V_22 , V_5 ) ;
return V_5 ;
}
static int F_21 ( struct V_56 * V_33 )
{
int V_5 ;
struct V_37 * V_38 = V_33 -> V_57 -> V_38 ;
T_1 V_8 [ 1 ] ;
struct V_3 V_77 = { 0x0120 , 0x0011 , 0x0001 , L_9 } ;
struct V_3 V_78 = { 0x0120 , 0x0011 , 0x0001 , L_10 } ;
struct V_3 V_79 = { 0x01ac , V_48 , 1 , V_8 } ;
F_8 ( L_3 , V_22 ) ;
V_5 = F_11 ( V_33 -> V_57 , V_62 , 0x0a ) ;
if ( V_5 )
goto V_12;
V_5 = F_11 ( V_33 -> V_57 , V_63 , 0x15 ) ;
if ( V_5 )
goto V_12;
V_5 = F_11 ( V_33 -> V_57 , V_80 , 0xe8 ) ;
if ( V_5 )
goto V_12;
V_5 = F_1 ( V_33 -> V_57 , & V_77 ) ;
if ( V_5 )
goto V_12;
V_5 = F_1 ( V_33 -> V_57 , & V_79 ) ;
if ( V_5 == 0 && V_8 [ 0 ] == 0x56 ) {
V_38 -> V_64 = V_81 ;
F_8 ( L_11 , V_22 ) ;
goto V_67;
} else {
F_8 ( L_12 ,
V_22 , V_5 , V_8 [ 0 ] ) ;
}
V_5 = F_1 ( V_33 -> V_57 , & V_78 ) ;
if ( V_5 )
goto V_12;
V_5 = - V_76 ;
goto V_12;
V_67:
V_5 = F_1 ( V_33 -> V_57 , & V_78 ) ;
if ( V_5 )
goto V_12;
return V_5 ;
V_12:
F_8 ( L_1 , V_22 , V_5 ) ;
return V_5 ;
}
static int F_22 ( struct V_56 * V_33 )
{
int V_5 ;
struct V_37 * V_38 = V_33 -> V_57 -> V_38 ;
struct V_32 * V_82 ;
struct V_83 * V_73 ;
F_8 ( L_3 , V_22 ) ;
V_82 = F_23 ( V_33 -> V_72 [ 0 ] . V_73 ) ;
switch ( V_38 -> V_64 ) {
case V_65 :
V_73 = F_20 ( V_84 , V_33 -> V_72 [ 0 ] . V_73 ,
V_82 , & V_85 ) ;
break;
case V_68 :
V_73 = F_20 ( V_86 , V_33 -> V_72 [ 0 ] . V_73 ,
V_82 , & V_87 ,
1220 ) ;
break;
case V_70 :
V_73 = F_20 ( V_88 , V_33 -> V_72 [ 0 ] . V_73 ,
V_82 , & V_89 ) ;
break;
default:
V_73 = NULL ;
V_12 ( L_13 , V_38 -> V_64 ) ;
}
if ( V_73 == NULL ) {
V_5 = - V_76 ;
goto V_12;
}
return 0 ;
V_12:
F_8 ( L_1 , V_22 , V_5 ) ;
return V_5 ;
}
static int F_24 ( struct V_56 * V_33 )
{
int V_5 ;
struct V_37 * V_38 = V_33 -> V_57 -> V_38 ;
struct V_83 * V_73 ;
F_8 ( L_3 , V_22 ) ;
switch ( V_38 -> V_64 ) {
case V_81 :
V_73 = NULL ;
break;
default:
V_73 = NULL ;
V_12 ( L_13 , V_38 -> V_64 ) ;
}
if ( V_73 == NULL ) {
V_5 = - V_76 ;
goto V_12;
}
return 0 ;
V_12:
F_8 ( L_1 , V_22 , V_5 ) ;
return V_5 ;
}
static int F_25 ( struct V_56 * V_33 , int V_90 )
{
int V_5 ;
T_1 V_8 [ 2 ] , V_91 ;
F_8 ( L_14 , V_22 , V_90 ) ;
V_5 = F_12 ( V_33 -> V_57 , V_92 , & V_91 ) ;
if ( V_5 )
goto V_12;
if ( V_90 ) {
V_8 [ 0 ] = 0x00 ;
V_8 [ 1 ] = 0x00 ;
V_91 |= 0x04 ;
} else {
V_8 [ 0 ] = 0x10 ;
V_8 [ 1 ] = 0x02 ;
V_91 &= ( ~ 0x04 ) ;
}
V_5 = F_11 ( V_33 -> V_57 , V_92 , V_91 ) ;
if ( V_5 )
goto V_12;
V_5 = F_9 ( V_33 -> V_57 , V_93 , V_8 , 2 ) ;
if ( V_5 )
goto V_12;
return V_5 ;
V_12:
F_8 ( L_1 , V_22 , V_5 ) ;
return V_5 ;
}
static int F_26 ( struct V_1 * V_2 , int V_90 )
{
int V_5 ;
T_1 V_91 , V_94 ;
F_8 ( L_14 , V_22 , V_90 ) ;
V_5 = F_12 ( V_2 , V_95 , & V_94 ) ;
if ( V_5 )
goto V_12;
V_5 = F_12 ( V_2 , V_92 , & V_91 ) ;
if ( V_5 )
goto V_12;
F_8 ( L_15 , V_22 , V_94 , V_91 ) ;
if ( V_90 ) {
V_91 |= 0x01 ;
V_91 &= ( ~ 0x10 ) ;
V_94 = V_94 & 0x0f ;
V_94 |= 0xe0 ;
} else {
V_91 &= ( ~ 0x01 ) ;
V_91 |= 0x10 ;
V_94 = V_94 & ( ~ 0xc0 ) ;
}
F_8 ( L_16 , V_22 , V_94 , V_91 ) ;
V_5 = F_11 ( V_2 , V_95 , V_94 ) ;
if ( V_5 )
goto V_12;
V_5 = F_11 ( V_2 , V_92 , V_91 ) ;
if ( V_5 )
goto V_12;
return V_5 ;
V_12:
F_8 ( L_1 , V_22 , V_5 ) ;
return V_5 ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_5 , V_96 ;
struct V_37 * V_38 = V_2 -> V_38 ;
T_1 V_8 [ 5 ] ;
T_3 V_97 ;
struct V_98 V_99 [] = {
{ 0x3033 , 0x80 } ,
{ 0x3020 , 0x43 } ,
{ 0x3021 , 0x16 } ,
{ 0x3022 , 0x16 } ,
{ 0x3023 , 0x5a } ,
{ 0x3024 , 0x2d } ,
{ 0x3025 , 0x16 } ,
{ 0x3026 , 0x01 } ,
{ 0x3028 , 0xb0 } ,
{ 0x3029 , 0x04 } ,
{ 0x302c , 0x88 } ,
{ 0x302e , 0x13 } ,
{ 0x3030 , 0xdf } ,
{ 0x3031 , 0x05 } ,
} ;
if ( ! V_38 -> V_100 ) {
for ( V_96 = 0 ; V_96 < F_28 ( V_99 ) ; V_96 ++ ) {
V_5 = F_11 ( V_2 , V_99 [ V_96 ] . V_23 ,
V_99 [ V_96 ] . V_24 ) ;
if ( V_5 )
goto V_12;
}
V_38 -> V_100 = true ;
}
V_5 = F_10 ( V_2 , V_101 , V_8 , 5 ) ;
if ( V_5 )
goto V_12;
if ( V_8 [ 4 ] & 0x01 ) {
if ( V_8 [ 2 ] == ( T_1 ) ~ V_8 [ 3 ] ) {
if ( V_8 [ 0 ] == ( T_1 ) ~ V_8 [ 1 ] ) {
V_97 = V_8 [ 0 ] << 8 | V_8 [ 2 ] ;
} else {
V_97 = V_8 [ 0 ] << 16 |
V_8 [ 1 ] << 8 | V_8 [ 2 ] ;
}
} else {
V_97 = V_8 [ 0 ] << 24 | V_8 [ 1 ] << 16 |
V_8 [ 2 ] << 8 | V_8 [ 3 ] ;
}
F_29 ( V_2 -> V_102 , V_97 , 0 ) ;
V_5 = F_11 ( V_2 , V_103 , 1 ) ;
if ( V_5 )
goto V_12;
V_5 = F_11 ( V_2 , V_103 , 1 ) ;
if ( V_5 )
goto V_12;
}
return V_5 ;
V_12:
F_8 ( L_1 , V_22 , V_5 ) ;
return V_5 ;
}
static int F_30 ( struct V_1 * V_2 )
{
int V_5 , V_96 ;
struct V_37 * V_38 = V_2 -> V_38 ;
T_1 V_8 [ 128 ] ;
int V_25 ;
struct V_98 V_99 [] = {
{ V_104 , 0x20 } ,
{ V_105 , 0x80 } ,
{ V_106 , 0xff } ,
{ V_107 , 0xff } ,
{ V_108 , 0xd0 } ,
{ V_109 , 0x07 } ,
{ V_110 , 0xc0 } ,
{ V_111 , 0x00 } ,
{ V_112 , 0x03 } ,
{ V_113 , 0x09 } ,
{ V_114 , 0x1c } ,
{ V_115 , 0x1e } ,
{ V_116 , 0x1e } ,
{ V_104 , 0x80 } ,
} ;
if ( ! V_38 -> V_100 ) {
for ( V_96 = 0 ; V_96 < F_28 ( V_99 ) ; V_96 ++ ) {
V_5 = F_11 ( V_2 , V_99 [ V_96 ] . V_23 ,
V_99 [ V_96 ] . V_24 ) ;
if ( V_5 )
goto V_12;
}
V_38 -> V_100 = true ;
}
V_5 = F_12 ( V_2 , V_106 , & V_8 [ 0 ] ) ;
if ( V_5 )
goto V_12;
if ( V_8 [ 0 ] != 0x83 )
goto exit;
V_5 = F_12 ( V_2 , V_117 , & V_8 [ 0 ] ) ;
if ( V_5 )
goto V_12;
V_25 = V_8 [ 0 ] ;
V_5 = F_10 ( V_2 , V_118 , V_8 , V_25 ) ;
V_5 = F_11 ( V_2 , V_106 , 0x03 ) ;
V_5 = F_11 ( V_2 , V_105 , 0x80 ) ;
V_5 = F_11 ( V_2 , V_104 , 0x80 ) ;
exit:
return V_5 ;
V_12:
F_8 ( L_1 , V_22 , V_5 ) ;
return V_5 ;
}
static int F_31 ( struct V_119 * V_120 ,
const struct V_121 * V_122 )
{
int V_5 , V_96 ;
int V_123 = F_28 ( V_124 ) ;
struct V_1 * V_2 ;
struct V_125 * V_18 ;
bool V_67 ;
F_8 ( L_17 , V_22 ,
V_120 -> V_126 -> V_127 . V_128 ) ;
if ( V_120 -> V_126 -> V_127 . V_128 != 0 )
return 0 ;
V_18 = F_32 ( V_120 ) ;
for ( V_96 = 0 , V_67 = false ; V_96 < F_28 ( V_129 ) - 1 ; V_96 ++ ) {
if ( V_129 [ V_96 ] . V_130 ==
F_33 ( V_18 -> V_131 . V_130 ) &&
V_129 [ V_96 ] . V_132 ==
F_33 ( V_18 -> V_131 . V_132 ) ) {
V_67 = true ;
break;
}
}
if ( ! V_67 ) {
F_8 ( L_18 , V_22 ,
F_33 ( V_18 -> V_131 . V_130 ) ,
F_33 ( V_18 -> V_131 . V_132 ) ) ;
V_124 [ 0 ] . V_133 [ 0 ] . V_134 [ 0 ] -> V_130 =
F_33 ( V_18 -> V_131 . V_130 ) ;
V_124 [ 0 ] . V_133 [ 0 ] . V_134 [ 0 ] -> V_132 =
F_33 ( V_18 -> V_131 . V_132 ) ;
}
for ( V_96 = 0 ; V_96 < V_123 ; V_96 ++ ) {
V_5 = F_34 ( V_120 , & V_124 [ V_96 ] ,
V_135 , & V_2 , V_136 ) ;
if ( V_5 == 0 || V_5 != - V_76 )
break;
}
if ( V_5 )
goto V_12;
V_5 = F_11 ( V_2 , V_137 , 0x09 ) ;
if ( V_5 )
goto V_12;
V_5 = F_9 ( V_2 , V_138 , L_19 , 4 ) ;
if ( V_5 )
goto V_12;
V_5 = F_9 ( V_2 , V_139 , L_20 , 4 ) ;
if ( V_5 )
goto V_12;
return V_5 ;
V_12:
F_8 ( L_1 , V_22 , V_5 ) ;
return V_5 ;
}
static int T_4 F_35 ( void )
{
int V_5 ;
F_8 ( L_3 , V_22 ) ;
V_5 = F_36 ( & V_140 ) ;
if ( V_5 )
V_12 ( L_21 , V_5 ) ;
return V_5 ;
}
static void T_5 F_37 ( void )
{
F_8 ( L_3 , V_22 ) ;
F_38 ( & V_140 ) ;
}
