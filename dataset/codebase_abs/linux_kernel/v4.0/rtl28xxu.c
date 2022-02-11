static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 ;
unsigned int V_9 ;
T_1 V_10 ;
if ( V_4 -> V_11 & V_12 ) {
memcpy ( V_6 -> V_13 , V_4 -> V_14 , V_4 -> V_15 ) ;
V_10 = ( V_16 | V_17 ) ;
V_9 = F_2 ( V_2 -> V_18 , 0 ) ;
} else {
V_10 = ( V_16 | V_19 ) ;
V_9 = F_3 ( V_2 -> V_18 , 0 ) ;
}
V_8 = F_4 ( V_2 -> V_18 , V_9 , 0 , V_10 , V_4 -> V_20 ,
V_4 -> V_11 , V_6 -> V_13 , V_4 -> V_15 , 1000 ) ;
F_5 ( V_2 -> V_18 , 0 , V_10 , V_4 -> V_20 ,
V_4 -> V_11 , V_6 -> V_13 , V_4 -> V_15 ) ;
if ( V_8 < 0 )
goto V_21;
if ( V_10 == ( V_16 | V_19 ) )
memcpy ( V_4 -> V_14 , V_6 -> V_13 , V_4 -> V_15 ) ;
return 0 ;
V_21:
F_6 ( & V_2 -> V_22 -> V_6 , L_1 , V_8 ) ;
return V_8 ;
}
static int F_7 ( struct V_1 * V_2 , T_2 V_23 , T_1 * V_24 , int V_25 )
{
struct V_3 V_4 ;
if ( V_23 < 0x3000 )
V_4 . V_11 = V_26 ;
else if ( V_23 < 0x4000 )
V_4 . V_11 = V_27 ;
else
V_4 . V_11 = V_28 ;
V_4 . V_20 = V_23 ;
V_4 . V_15 = V_25 ;
V_4 . V_14 = V_24 ;
return F_1 ( V_2 , & V_4 ) ;
}
static int F_8 ( struct V_1 * V_2 , T_2 V_23 , T_1 * V_24 , int V_25 )
{
struct V_3 V_4 ;
if ( V_23 < 0x3000 )
V_4 . V_11 = V_29 ;
else if ( V_23 < 0x4000 )
V_4 . V_11 = V_30 ;
else
V_4 . V_11 = V_31 ;
V_4 . V_20 = V_23 ;
V_4 . V_15 = V_25 ;
V_4 . V_14 = V_24 ;
return F_1 ( V_2 , & V_4 ) ;
}
static int F_9 ( struct V_1 * V_2 , T_2 V_23 , T_1 V_24 )
{
return F_7 ( V_2 , V_23 , & V_24 , 1 ) ;
}
static int F_10 ( struct V_1 * V_2 , T_2 V_23 , T_1 * V_24 )
{
return F_8 ( V_2 , V_23 , V_24 , 1 ) ;
}
static int F_11 ( struct V_1 * V_2 , T_2 V_23 , T_1 V_24 ,
T_1 V_32 )
{
int V_8 ;
T_1 V_33 ;
if ( V_32 != 0xff ) {
V_8 = F_10 ( V_2 , V_23 , & V_33 ) ;
if ( V_8 )
return V_8 ;
V_24 &= V_32 ;
V_33 &= ~ V_32 ;
V_24 |= V_33 ;
}
return F_9 ( V_2 , V_23 , V_24 ) ;
}
static int F_12 ( struct V_34 * V_35 , struct V_36 V_37 [] ,
int V_38 )
{
int V_8 ;
struct V_1 * V_2 = F_13 ( V_35 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_3 V_4 ;
if ( F_14 ( & V_2 -> V_39 ) < 0 )
return - V_40 ;
if ( V_38 == 2 && ! ( V_37 [ 0 ] . V_41 & V_42 ) &&
( V_37 [ 1 ] . V_41 & V_42 ) ) {
if ( V_37 [ 0 ] . V_25 > 24 || V_37 [ 1 ] . V_25 > 24 ) {
V_8 = - V_43 ;
goto V_44;
} else if ( V_37 [ 0 ] . V_45 == 0x10 ) {
V_4 . V_20 = ( V_37 [ 0 ] . V_13 [ 0 ] << 8 ) | ( V_37 [ 0 ] . V_45 << 1 ) ;
V_4 . V_11 = V_46 | V_6 -> V_47 ;
V_4 . V_15 = V_37 [ 1 ] . V_25 ;
V_4 . V_14 = & V_37 [ 1 ] . V_13 [ 0 ] ;
V_8 = F_1 ( V_2 , & V_4 ) ;
} else if ( V_37 [ 0 ] . V_25 < 2 ) {
V_4 . V_20 = ( V_37 [ 0 ] . V_13 [ 0 ] << 8 ) | ( V_37 [ 0 ] . V_45 << 1 ) ;
V_4 . V_11 = V_48 ;
V_4 . V_15 = V_37 [ 1 ] . V_25 ;
V_4 . V_14 = & V_37 [ 1 ] . V_13 [ 0 ] ;
V_8 = F_1 ( V_2 , & V_4 ) ;
} else {
V_4 . V_20 = ( V_37 [ 0 ] . V_45 << 1 ) ;
V_4 . V_11 = V_49 ;
V_4 . V_15 = V_37 [ 0 ] . V_25 ;
V_4 . V_14 = V_37 [ 0 ] . V_13 ;
V_8 = F_1 ( V_2 , & V_4 ) ;
if ( V_8 )
goto V_44;
V_4 . V_20 = ( V_37 [ 0 ] . V_45 << 1 ) ;
V_4 . V_11 = V_50 ;
V_4 . V_15 = V_37 [ 1 ] . V_25 ;
V_4 . V_14 = V_37 [ 1 ] . V_13 ;
V_8 = F_1 ( V_2 , & V_4 ) ;
}
} else if ( V_38 == 1 && ! ( V_37 [ 0 ] . V_41 & V_42 ) ) {
if ( V_37 [ 0 ] . V_25 > 22 ) {
V_8 = - V_43 ;
goto V_44;
} else if ( V_37 [ 0 ] . V_45 == 0x10 ) {
if ( V_37 [ 0 ] . V_13 [ 0 ] == 0x00 ) {
V_6 -> V_47 = V_37 [ 0 ] . V_13 [ 1 ] ;
V_8 = 0 ;
} else {
V_4 . V_20 = ( V_37 [ 0 ] . V_13 [ 0 ] << 8 ) |
( V_37 [ 0 ] . V_45 << 1 ) ;
V_4 . V_11 = V_51 | V_6 -> V_47 ;
V_4 . V_15 = V_37 [ 0 ] . V_25 - 1 ;
V_4 . V_14 = & V_37 [ 0 ] . V_13 [ 1 ] ;
V_8 = F_1 ( V_2 , & V_4 ) ;
}
} else if ( V_37 [ 0 ] . V_25 < 23 ) {
V_4 . V_20 = ( V_37 [ 0 ] . V_13 [ 0 ] << 8 ) | ( V_37 [ 0 ] . V_45 << 1 ) ;
V_4 . V_11 = V_52 ;
V_4 . V_15 = V_37 [ 0 ] . V_25 - 1 ;
V_4 . V_14 = & V_37 [ 0 ] . V_13 [ 1 ] ;
V_8 = F_1 ( V_2 , & V_4 ) ;
} else {
V_4 . V_20 = ( V_37 [ 0 ] . V_45 << 1 ) ;
V_4 . V_11 = V_49 ;
V_4 . V_15 = V_37 [ 0 ] . V_25 ;
V_4 . V_14 = V_37 [ 0 ] . V_13 ;
V_8 = F_1 ( V_2 , & V_4 ) ;
}
} else {
V_8 = - V_53 ;
}
V_44:
F_15 ( & V_2 -> V_39 ) ;
return V_8 ? V_8 : V_38 ;
}
static T_3 F_16 ( struct V_34 * V_54 )
{
return V_55 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_18 ( V_2 ) ;
int V_8 ;
T_1 V_13 [ 1 ] ;
struct V_3 V_56 = { 0x0120 , 0x0011 , 0x0001 , L_2 } ;
struct V_3 V_57 = { 0x00c0 , V_48 , 1 , V_13 } ;
struct V_3 V_58 = { 0x0fc4 , V_48 , 1 , V_13 } ;
F_6 ( & V_2 -> V_22 -> V_6 , L_3 ) ;
V_8 = F_9 ( V_2 , V_59 , 0x0a ) ;
if ( V_8 )
goto V_21;
V_8 = F_9 ( V_2 , V_60 , 0x15 ) ;
if ( V_8 )
goto V_21;
F_19 ( 20 ) ;
V_6 -> V_61 = L_4 ;
V_8 = F_1 ( V_2 , & V_56 ) ;
if ( V_8 )
goto V_21;
V_8 = F_1 ( V_2 , & V_58 ) ;
if ( V_8 == 0 && V_13 [ 0 ] == 0x2c ) {
V_6 -> V_62 = V_63 ;
V_6 -> V_61 = L_5 ;
goto V_64;
}
V_8 = F_1 ( V_2 , & V_56 ) ;
if ( V_8 )
goto V_21;
V_8 = F_1 ( V_2 , & V_57 ) ;
if ( V_8 == 0 && V_13 [ 0 ] == 0x63 ) {
V_6 -> V_62 = V_65 ;
V_6 -> V_61 = L_6 ;
goto V_64;
}
V_6 -> V_62 = V_66 ;
V_6 -> V_61 = L_7 ;
goto V_64;
V_64:
F_6 ( & V_2 -> V_22 -> V_6 , L_8 , V_6 -> V_61 ) ;
return 0 ;
V_21:
F_6 ( & V_2 -> V_22 -> V_6 , L_1 , V_8 ) ;
return V_8 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_18 ( V_2 ) ;
int V_8 ;
T_1 V_13 [ 2 ] ;
struct V_3 V_56 = { 0x0120 , 0x0011 , 0x0001 , L_9 } ;
struct V_3 V_67 = { 0x0120 , 0x0011 , 0x0001 , L_10 } ;
struct V_3 V_68 = { 0x00c6 , V_48 , 1 , V_13 } ;
struct V_3 V_69 = { 0x00c6 , V_48 , 1 , V_13 } ;
struct V_3 V_70 = { 0x00c0 , V_48 , 1 , V_13 } ;
struct V_3 V_71 = { 0x01ac , V_48 , 1 , V_13 } ;
struct V_3 V_72 = { 0x00c0 , V_48 , 1 , V_13 } ;
struct V_3 V_73 = { 0x00c0 , V_48 , 1 , V_13 } ;
struct V_3 V_74 = { 0x7ec0 , V_48 , 2 , V_13 } ;
struct V_3 V_75 = { 0xd9c0 , V_48 , 1 , V_13 } ;
struct V_3 V_76 = { 0x02c8 , V_48 , 1 , V_13 } ;
struct V_3 V_77 = { 0x00c0 , V_48 , 2 , V_13 } ;
struct V_3 V_78 = { 0x0034 , V_48 , 1 , V_13 } ;
struct V_3 V_79 = { 0x0074 , V_48 , 1 , V_13 } ;
struct V_3 V_80 = { 0xff38 , V_48 , 1 , V_13 } ;
struct V_3 V_81 = { 0xff38 , V_48 , 1 , V_13 } ;
F_6 ( & V_2 -> V_22 -> V_6 , L_3 ) ;
V_8 = F_11 ( V_2 , V_59 , 0x00 , 0x40 ) ;
if ( V_8 )
goto V_21;
V_8 = F_11 ( V_2 , V_60 , 0x48 , 0x48 ) ;
if ( V_8 )
goto V_21;
V_8 = F_1 ( V_2 , & V_56 ) ;
if ( V_8 )
goto V_21;
V_6 -> V_61 = L_4 ;
V_8 = F_1 ( V_2 , & V_68 ) ;
if ( V_8 == 0 && V_13 [ 0 ] == 0xa1 ) {
V_6 -> V_62 = V_82 ;
V_6 -> V_61 = L_11 ;
goto V_83;
}
V_8 = F_1 ( V_2 , & V_69 ) ;
if ( V_8 == 0 && V_13 [ 0 ] == 0xa3 ) {
V_6 -> V_62 = V_84 ;
V_6 -> V_61 = L_12 ;
goto V_83;
}
V_8 = F_1 ( V_2 , & V_70 ) ;
if ( V_8 == 0 && V_13 [ 0 ] == 0x85 ) {
V_6 -> V_62 = V_85 ;
V_6 -> V_61 = L_13 ;
goto V_83;
}
V_8 = F_1 ( V_2 , & V_71 ) ;
if ( V_8 == 0 && V_13 [ 0 ] == 0x56 ) {
V_6 -> V_62 = V_86 ;
V_6 -> V_61 = L_14 ;
goto V_83;
}
V_8 = F_1 ( V_2 , & V_72 ) ;
if ( V_8 == 0 && ( V_13 [ 0 ] == 0x9e || V_13 [ 0 ] == 0x9c ) ) {
V_6 -> V_62 = V_87 ;
V_6 -> V_61 = L_15 ;
goto V_83;
}
V_8 = F_1 ( V_2 , & V_73 ) ;
if ( V_8 == 0 && V_13 [ 0 ] == 0x38 ) {
V_6 -> V_62 = V_88 ;
V_6 -> V_61 = L_16 ;
goto V_83;
}
V_8 = F_1 ( V_2 , & V_74 ) ;
if ( V_8 == 0 && V_13 [ 0 ] == 0x23 && V_13 [ 1 ] == 0x28 ) {
V_6 -> V_62 = V_89 ;
V_6 -> V_61 = L_17 ;
goto V_83;
}
V_8 = F_1 ( V_2 , & V_75 ) ;
if ( V_8 == 0 && V_13 [ 0 ] == 0x14 ) {
V_6 -> V_62 = V_90 ;
V_6 -> V_61 = L_18 ;
goto V_83;
}
V_8 = F_1 ( V_2 , & V_76 ) ;
if ( V_8 == 0 && V_13 [ 0 ] == 0x40 ) {
V_6 -> V_62 = V_91 ;
V_6 -> V_61 = L_19 ;
goto V_83;
}
V_8 = F_1 ( V_2 , & V_77 ) ;
if ( V_8 == 0 && ( V_13 [ 0 ] == 0xc7 || V_13 [ 1 ] == 0x60 ) ) {
V_6 -> V_62 = V_92 ;
V_6 -> V_61 = L_20 ;
goto V_83;
}
V_8 = F_1 ( V_2 , & V_78 ) ;
if ( V_8 == 0 && V_13 [ 0 ] == 0x69 ) {
V_6 -> V_62 = V_93 ;
V_6 -> V_61 = L_21 ;
goto V_83;
}
V_8 = F_1 ( V_2 , & V_79 ) ;
if ( V_8 == 0 && V_13 [ 0 ] == 0x69 ) {
V_6 -> V_62 = V_94 ;
V_6 -> V_61 = L_22 ;
goto V_83;
}
V_83:
F_6 ( & V_2 -> V_22 -> V_6 , L_8 , V_6 -> V_61 ) ;
if ( V_6 -> V_62 == V_94 ) {
V_8 = F_11 ( V_2 , V_95 , 0x01 , 0x01 ) ;
if ( V_8 )
goto V_21;
V_8 = F_11 ( V_2 , V_59 , 0x00 , 0x01 ) ;
if ( V_8 )
goto V_21;
V_8 = F_11 ( V_2 , V_60 , 0x01 , 0x01 ) ;
if ( V_8 )
goto V_21;
V_8 = F_1 ( V_2 , & V_80 ) ;
if ( V_8 == 0 && V_13 [ 0 ] == 0x02 ) {
F_6 ( & V_2 -> V_22 -> V_6 , L_23 ) ;
V_6 -> V_96 = V_97 ;
goto V_98;
}
V_8 = F_1 ( V_2 , & V_81 ) ;
if ( V_8 == 0 && V_13 [ 0 ] == 0x03 ) {
F_6 ( & V_2 -> V_22 -> V_6 , L_24 ) ;
V_6 -> V_96 = V_99 ;
goto V_98;
}
}
V_98:
V_8 = F_1 ( V_2 , & V_67 ) ;
if ( V_8 < 0 )
goto V_21;
return 0 ;
V_21:
F_6 ( & V_2 -> V_22 -> V_6 , L_1 , V_8 ) ;
return V_8 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_18 ( V_2 ) ;
if ( V_6 -> V_100 == V_101 )
return F_17 ( V_2 ) ;
else
return F_20 ( V_2 ) ;
}
static int F_22 ( struct V_1 * V_2 , const char * * V_102 )
{
struct V_5 * V_6 = F_18 ( V_2 ) ;
int V_8 ;
struct V_3 V_103 = { 0x0020 , V_50 , 0 , NULL } ;
F_6 ( & V_2 -> V_22 -> V_6 , L_3 ) ;
V_8 = F_1 ( V_2 , & V_103 ) ;
if ( V_8 == - V_104 ) {
V_6 -> V_100 = V_101 ;
} else if ( V_8 == 0 ) {
V_6 -> V_100 = V_105 ;
} else {
F_23 ( & V_2 -> V_22 -> V_6 , L_25 , V_8 ) ;
goto V_21;
}
F_6 ( & V_2 -> V_22 -> V_6 , L_26 , V_6 -> V_100 ) ;
return V_106 ;
V_21:
F_6 ( & V_2 -> V_22 -> V_6 , L_1 , V_8 ) ;
return V_8 ;
}
static int F_24 ( struct V_107 * V_35 )
{
struct V_1 * V_2 = F_25 ( V_35 ) ;
struct V_5 * V_6 = F_18 ( V_2 ) ;
struct V_108 * V_109 = & V_6 -> V_108 ;
struct V_110 V_111 ;
struct V_112 * V_113 ;
int V_8 ;
F_6 ( & V_2 -> V_22 -> V_6 , L_3 ) ;
switch ( V_6 -> V_62 ) {
case V_63 :
* V_109 = V_114 ;
break;
case V_65 :
* V_109 = V_115 ;
break;
case V_66 :
* V_109 = V_116 ;
break;
default:
F_23 ( & V_2 -> V_22 -> V_6 , L_27 , V_6 -> V_61 ) ;
V_8 = - V_117 ;
goto V_21;
}
memset ( & V_111 , 0 , sizeof( V_111 ) ) ;
F_26 ( V_111 . type , L_28 , V_118 ) ;
V_111 . V_45 = 0x10 ;
V_111 . V_119 = V_109 ;
F_27 ( L_29 , V_111 . type ) ;
V_113 = F_28 ( & V_2 -> V_120 , & V_111 ) ;
if ( V_113 == NULL || V_113 -> V_6 . V_121 == NULL ) {
V_8 = - V_117 ;
goto V_21;
}
if ( ! F_29 ( V_113 -> V_6 . V_121 -> V_122 ) ) {
F_30 ( V_113 ) ;
V_8 = - V_117 ;
goto V_21;
}
V_35 -> V_123 [ 0 ] = V_109 -> V_124 ( V_113 ) ;
V_6 -> V_125 = V_109 -> V_126 ( V_113 ) ;
V_6 -> V_127 = V_113 ;
return 0 ;
V_21:
F_6 ( & V_2 -> V_22 -> V_6 , L_1 , V_8 ) ;
return V_8 ;
}
static int F_31 ( struct V_1 * V_2 ,
int V_128 , int V_129 )
{
int V_8 ;
T_1 V_24 ;
F_6 ( & V_2 -> V_22 -> V_6 , L_30 , V_128 , V_129 ) ;
switch ( V_128 ) {
case V_130 :
V_8 = F_10 ( V_2 , V_95 , & V_24 ) ;
if ( V_8 )
goto V_21;
if ( V_129 )
V_24 &= 0xbf ;
else
V_24 |= 0x40 ;
V_8 = F_9 ( V_2 , V_95 , V_24 ) ;
if ( V_8 )
goto V_21;
break;
default:
V_8 = - V_53 ;
goto V_21;
}
return 0 ;
V_21:
F_6 ( & V_2 -> V_22 -> V_6 , L_1 , V_8 ) ;
return V_8 ;
}
static int F_32 ( struct V_1 * V_2 ,
int V_128 , int V_129 )
{
int V_8 ;
T_1 V_24 ;
F_6 ( & V_2 -> V_22 -> V_6 , L_30 , V_128 , V_129 ) ;
switch ( V_128 ) {
case V_131 :
if ( V_129 )
V_24 = ( 1 << 4 ) ;
else
V_24 = ( 0 << 4 ) ;
V_8 = F_11 ( V_2 , V_95 , V_24 , 0x10 ) ;
if ( V_8 )
goto V_21;
break;
case V_132 :
if ( V_129 )
V_24 = ( 1 << 1 ) ;
else
V_24 = ( 0 << 1 ) ;
V_8 = F_11 ( V_2 , V_95 , V_24 , 0x02 ) ;
if ( V_8 )
goto V_21;
break;
}
return 0 ;
V_21:
F_6 ( & V_2 -> V_22 -> V_6 , L_1 , V_8 ) ;
return V_8 ;
}
static int F_33 ( void * V_133 , int V_134 ,
int V_128 , int V_129 )
{
struct V_34 * V_54 = V_133 ;
struct V_135 * V_136 = V_54 -> V_6 . V_136 ;
struct V_34 * V_137 ;
struct V_1 * V_2 ;
struct V_5 * V_6 ;
if ( V_136 != NULL && V_136 -> type == & V_138 )
V_137 = F_34 ( V_136 ) ;
else
return - V_53 ;
V_2 = F_13 ( V_137 ) ;
V_6 = V_2 -> V_7 ;
F_6 ( & V_2 -> V_22 -> V_6 , L_31 ,
V_134 , V_128 , V_129 ) ;
switch ( V_134 ) {
case V_139 :
switch ( V_6 -> V_62 ) {
case V_82 :
return F_31 ( V_2 , V_128 , V_129 ) ;
case V_89 :
return F_32 ( V_2 , V_128 , V_129 ) ;
}
}
return 0 ;
}
static int F_35 ( struct V_107 * V_35 )
{
struct V_1 * V_2 = F_25 ( V_35 ) ;
struct V_5 * V_6 = F_18 ( V_2 ) ;
struct V_140 * V_109 = & V_6 -> V_140 ;
struct V_110 V_111 ;
struct V_112 * V_113 ;
int V_8 ;
F_6 ( & V_2 -> V_22 -> V_6 , L_3 ) ;
switch ( V_6 -> V_62 ) {
case V_82 :
* V_109 = V_141 ;
break;
case V_84 :
* V_109 = V_142 ;
break;
case V_86 :
* V_109 = V_141 ;
break;
case V_89 :
* V_109 = V_143 ;
break;
case V_91 :
* V_109 = V_144 ;
break;
case V_93 :
case V_94 :
* V_109 = V_145 ;
break;
default:
F_23 ( & V_2 -> V_22 -> V_6 , L_27 , V_6 -> V_61 ) ;
V_8 = - V_117 ;
goto V_21;
}
memset ( & V_111 , 0 , sizeof( V_111 ) ) ;
F_26 ( V_111 . type , L_32 , V_118 ) ;
V_111 . V_45 = 0x10 ;
V_111 . V_119 = V_109 ;
F_27 ( L_29 , V_111 . type ) ;
V_113 = F_28 ( & V_2 -> V_120 , & V_111 ) ;
if ( V_113 == NULL || V_113 -> V_6 . V_121 == NULL ) {
V_8 = - V_117 ;
goto V_21;
}
if ( ! F_29 ( V_113 -> V_6 . V_121 -> V_122 ) ) {
F_30 ( V_113 ) ;
V_8 = - V_117 ;
goto V_21;
}
V_35 -> V_123 [ 0 ] = V_109 -> V_124 ( V_113 ) ;
V_6 -> V_125 = V_109 -> V_126 ( V_113 ) ;
V_6 -> V_127 = V_113 ;
V_35 -> V_123 [ 0 ] -> V_146 = F_33 ;
if ( V_6 -> V_96 ) {
struct V_110 V_147 = {} ;
V_8 = 0 ;
if ( V_6 -> V_96 == V_97 ) {
struct V_148 V_148 = {} ;
V_148 . V_123 = & V_35 -> V_123 [ 1 ] ;
V_148 . V_149 = 22 ,
F_26 ( V_147 . type , L_33 , V_118 ) ;
V_148 . V_150 = 20500000 ;
V_147 . V_45 = 0x18 ;
V_147 . V_119 = & V_148 ;
F_27 ( V_147 . type ) ;
V_113 = F_28 ( & V_2 -> V_120 , & V_147 ) ;
if ( V_113 == NULL || V_113 -> V_6 . V_121 == NULL ) {
V_6 -> V_96 = V_151 ;
goto V_152;
}
if ( ! F_29 ( V_113 -> V_6 . V_121 -> V_122 ) ) {
F_30 ( V_113 ) ;
V_6 -> V_96 = V_151 ;
goto V_152;
}
V_6 -> V_153 = V_113 ;
} else {
struct V_154 V_154 = {} ;
V_154 . V_123 = & V_35 -> V_123 [ 1 ] ;
V_154 . V_149 = 22 ,
F_26 ( V_147 . type , L_34 , V_118 ) ;
V_147 . V_45 = 0x18 ;
V_147 . V_119 = & V_154 ;
F_27 ( V_147 . type ) ;
V_113 = F_28 ( & V_2 -> V_120 , & V_147 ) ;
if ( V_113 == NULL || V_113 -> V_6 . V_121 == NULL ) {
V_6 -> V_96 = V_151 ;
goto V_152;
}
if ( ! F_29 ( V_113 -> V_6 . V_121 -> V_122 ) ) {
F_30 ( V_113 ) ;
V_6 -> V_96 = V_151 ;
goto V_152;
}
V_6 -> V_153 = V_113 ;
}
}
return 0 ;
V_152:
V_21:
F_6 ( & V_2 -> V_22 -> V_6 , L_1 , V_8 ) ;
return V_8 ;
}
static int F_36 ( struct V_107 * V_35 )
{
struct V_5 * V_6 = F_37 ( V_35 ) ;
if ( V_6 -> V_100 == V_101 )
return F_24 ( V_35 ) ;
else
return F_35 ( V_35 ) ;
}
static int F_38 ( struct V_107 * V_35 )
{
struct V_1 * V_2 = F_25 ( V_35 ) ;
struct V_5 * V_6 = F_18 ( V_2 ) ;
struct V_112 * V_113 ;
F_6 ( & V_2 -> V_22 -> V_6 , L_3 ) ;
V_113 = V_6 -> V_153 ;
if ( V_113 ) {
F_39 ( V_113 -> V_6 . V_121 -> V_122 ) ;
F_30 ( V_113 ) ;
}
V_113 = V_6 -> V_127 ;
if ( V_113 ) {
F_39 ( V_113 -> V_6 . V_121 -> V_122 ) ;
F_30 ( V_113 ) ;
}
return 0 ;
}
static int F_40 ( struct V_107 * V_35 )
{
int V_8 ;
struct V_1 * V_2 = F_25 ( V_35 ) ;
struct V_5 * V_6 = F_18 ( V_2 ) ;
struct V_155 * V_123 ;
F_6 ( & V_2 -> V_22 -> V_6 , L_3 ) ;
switch ( V_6 -> V_62 ) {
case V_63 :
V_123 = F_41 ( V_156 , V_35 -> V_123 [ 0 ] ,
V_6 -> V_125 ,
& V_157 ) ;
break;
case V_65 :
V_123 = F_41 ( V_158 , V_35 -> V_123 [ 0 ] ,
V_6 -> V_125 ,
& V_159 , 1220 ) ;
break;
case V_66 :
V_123 = F_41 ( V_160 , V_35 -> V_123 [ 0 ] ,
V_6 -> V_125 ,
& V_161 ) ;
break;
default:
V_123 = NULL ;
F_23 ( & V_2 -> V_22 -> V_6 , L_35 , V_6 -> V_62 ) ;
}
if ( V_123 == NULL ) {
V_8 = - V_117 ;
goto V_21;
}
return 0 ;
V_21:
F_6 ( & V_2 -> V_22 -> V_6 , L_1 , V_8 ) ;
return V_8 ;
}
static int F_42 ( struct V_107 * V_35 )
{
int V_8 ;
struct V_1 * V_2 = F_25 ( V_35 ) ;
struct V_5 * V_6 = F_18 ( V_2 ) ;
struct V_155 * V_123 = NULL ;
struct V_110 V_147 ;
struct V_112 * V_113 ;
struct V_162 * V_163 = NULL ;
struct V_164 * V_165 ;
struct V_166 V_109 ;
F_6 ( & V_2 -> V_22 -> V_6 , L_3 ) ;
memset ( & V_147 , 0 , sizeof( struct V_110 ) ) ;
memset ( & V_109 , 0 , sizeof( V_109 ) ) ;
switch ( V_6 -> V_62 ) {
case V_82 :
V_123 = F_41 ( V_167 , V_35 -> V_123 [ 0 ] ,
V_6 -> V_125 , & V_168 ) ;
V_35 -> V_123 [ 0 ] -> V_169 . V_170 =
V_35 -> V_123 [ 0 ] -> V_169 . V_171 . V_172 ;
break;
case V_84 :
V_123 = F_41 ( V_173 , V_35 -> V_123 [ 0 ] ,
V_6 -> V_125 , 0xc6 >> 1 , 0 , V_174 ) ;
V_35 -> V_123 [ 0 ] -> V_169 . V_170 =
V_35 -> V_123 [ 0 ] -> V_169 . V_171 . V_172 ;
break;
case V_91 : {
struct V_175 V_175 = {
. V_123 = V_35 -> V_123 [ 0 ] ,
. clock = 28800000 ,
} ;
F_26 ( V_147 . type , L_36 , V_118 ) ;
V_147 . V_45 = 0x64 ;
V_147 . V_119 = & V_175 ;
F_27 ( V_147 . type ) ;
V_113 = F_28 ( V_6 -> V_125 , & V_147 ) ;
if ( V_113 == NULL || V_113 -> V_6 . V_121 == NULL )
break;
if ( ! F_29 ( V_113 -> V_6 . V_121 -> V_122 ) ) {
F_30 ( V_113 ) ;
break;
}
V_6 -> V_176 = V_113 ;
V_163 = F_43 ( V_113 ) ;
}
break;
case V_86 :
V_123 = F_41 ( V_177 , V_35 -> V_123 [ 0 ] ,
V_6 -> V_125 ,
& V_178 ) ;
break;
case V_89 :
V_8 = F_11 ( V_2 , V_59 , 0x00 , 0x12 ) ;
if ( V_8 )
goto V_21;
V_8 = F_11 ( V_2 , V_60 , 0x12 , 0x12 ) ;
if ( V_8 )
goto V_21;
V_123 = F_41 ( V_179 , V_35 -> V_123 [ 0 ] ,
V_6 -> V_125 ,
& V_180 ) ;
break;
case V_93 :
V_123 = F_41 ( V_181 , V_35 -> V_123 [ 0 ] ,
V_6 -> V_125 ,
& V_182 ) ;
V_35 -> V_123 [ 0 ] -> V_169 . V_170 =
V_35 -> V_123 [ 0 ] -> V_169 . V_171 . V_172 ;
break;
case V_94 :
V_123 = F_41 ( V_181 , V_35 -> V_123 [ 0 ] ,
V_6 -> V_125 ,
& V_183 ) ;
V_35 -> V_123 [ 0 ] -> V_169 . V_170 =
V_35 -> V_123 [ 0 ] -> V_169 . V_171 . V_172 ;
if ( V_35 -> V_123 [ 1 ] ) {
V_123 = F_41 ( V_181 , V_35 -> V_123 [ 1 ] ,
V_6 -> V_125 ,
& V_183 ) ;
V_35 -> V_123 [ 1 ] -> V_169 . V_170 =
V_35 -> V_123 [ 1 ] -> V_169 . V_171 . V_172 ;
}
break;
default:
F_23 ( & V_2 -> V_22 -> V_6 , L_35 , V_6 -> V_62 ) ;
}
if ( V_123 == NULL && V_6 -> V_176 == NULL ) {
V_8 = - V_117 ;
goto V_21;
}
switch ( V_6 -> V_62 ) {
case V_82 :
case V_84 :
case V_91 :
case V_93 :
case V_94 :
V_109 . V_184 = V_6 -> V_140 . V_184 ;
V_109 . V_62 = V_6 -> V_62 ;
V_109 . V_112 = V_6 -> V_127 ;
V_109 . V_185 = V_6 -> V_140 . V_185 ;
V_109 . V_186 = V_6 -> V_140 . V_186 ;
V_109 . V_187 = V_6 -> V_140 . V_187 ;
V_109 . V_155 = V_35 -> V_123 [ 0 ] ;
V_109 . V_1 = V_2 ;
V_109 . V_162 = V_163 ;
F_27 ( L_29 , L_37 ) ;
V_165 = F_44 ( & V_2 -> V_22 -> V_6 ,
L_37 ,
V_188 ,
& V_109 , sizeof( V_109 ) ) ;
if ( V_165 == NULL || V_165 -> V_6 . V_121 == NULL )
break;
V_6 -> V_189 = V_165 ;
break;
default:
F_6 ( & V_2 -> V_22 -> V_6 , L_38 , V_6 -> V_62 ) ;
}
return 0 ;
V_21:
F_6 ( & V_2 -> V_22 -> V_6 , L_1 , V_8 ) ;
return V_8 ;
}
static int F_45 ( struct V_107 * V_35 )
{
struct V_5 * V_6 = F_37 ( V_35 ) ;
if ( V_6 -> V_100 == V_101 )
return F_40 ( V_35 ) ;
else
return F_42 ( V_35 ) ;
}
static int F_46 ( struct V_107 * V_35 )
{
struct V_1 * V_2 = F_25 ( V_35 ) ;
struct V_5 * V_6 = F_18 ( V_2 ) ;
struct V_112 * V_113 ;
struct V_164 * V_165 ;
F_6 ( & V_2 -> V_22 -> V_6 , L_3 ) ;
V_165 = V_6 -> V_189 ;
if ( V_165 )
F_47 ( V_165 ) ;
V_113 = V_6 -> V_176 ;
if ( V_113 ) {
F_39 ( V_113 -> V_6 . V_121 -> V_122 ) ;
F_30 ( V_113 ) ;
}
return 0 ;
}
static int F_48 ( struct V_1 * V_2 )
{
int V_8 ;
T_1 V_24 ;
F_6 ( & V_2 -> V_22 -> V_6 , L_3 ) ;
V_8 = F_10 ( V_2 , V_190 , & V_24 ) ;
if ( V_8 )
goto V_21;
V_24 |= 0x09 ;
V_8 = F_9 ( V_2 , V_190 , V_24 ) ;
if ( V_8 )
goto V_21;
V_8 = F_7 ( V_2 , V_191 , L_39 , 4 ) ;
if ( V_8 )
goto V_21;
V_8 = F_7 ( V_2 , V_192 , L_40 , 4 ) ;
if ( V_8 )
goto V_21;
return V_8 ;
V_21:
F_6 ( & V_2 -> V_22 -> V_6 , L_1 , V_8 ) ;
return V_8 ;
}
static int F_49 ( struct V_1 * V_2 , int V_193 )
{
int V_8 ;
T_1 V_194 , V_195 , V_196 [ 2 ] ;
F_6 ( & V_2 -> V_22 -> V_6 , L_41 , V_193 ) ;
V_8 = F_10 ( V_2 , V_197 , & V_195 ) ;
if ( V_8 )
goto V_21;
V_8 = F_10 ( V_2 , V_95 , & V_194 ) ;
if ( V_8 )
goto V_21;
F_6 ( & V_2 -> V_22 -> V_6 , L_42 , V_195 , V_194 ) ;
if ( V_193 ) {
V_194 |= 0x01 ;
V_194 &= ( ~ 0x10 ) ;
V_194 |= 0x04 ;
V_195 = V_195 & 0x0f ;
V_195 |= 0xe0 ;
V_196 [ 0 ] = 0x00 ;
V_196 [ 1 ] = 0x00 ;
} else {
V_194 &= ( ~ 0x01 ) ;
V_194 |= 0x10 ;
V_194 &= ( ~ 0x04 ) ;
V_195 = V_195 & ( ~ 0xc0 ) ;
V_196 [ 0 ] = 0x10 ;
V_196 [ 1 ] = 0x02 ;
}
F_6 ( & V_2 -> V_22 -> V_6 , L_43 , V_195 , V_194 ) ;
V_8 = F_9 ( V_2 , V_197 , V_195 ) ;
if ( V_8 )
goto V_21;
V_8 = F_9 ( V_2 , V_95 , V_194 ) ;
if ( V_8 )
goto V_21;
V_8 = F_7 ( V_2 , V_198 , V_196 , 2 ) ;
if ( V_8 )
goto V_21;
if ( V_193 )
F_50 ( V_2 -> V_18 , F_51 ( V_2 -> V_18 , 0x81 ) ) ;
return V_8 ;
V_21:
F_6 ( & V_2 -> V_22 -> V_6 , L_1 , V_8 ) ;
return V_8 ;
}
static int F_52 ( struct V_1 * V_2 , int V_193 )
{
int V_8 ;
F_6 ( & V_2 -> V_22 -> V_6 , L_41 , V_193 ) ;
if ( V_193 ) {
V_8 = F_11 ( V_2 , V_95 , 0x08 , 0x18 ) ;
if ( V_8 )
goto V_21;
V_8 = F_11 ( V_2 , V_199 , 0x00 , 0x10 ) ;
if ( V_8 )
goto V_21;
V_8 = F_11 ( V_2 , V_200 , 0x80 , 0x80 ) ;
if ( V_8 )
goto V_21;
V_8 = F_11 ( V_2 , V_200 , 0x20 , 0x20 ) ;
if ( V_8 )
goto V_21;
V_8 = F_7 ( V_2 , V_198 , L_44 , 2 ) ;
if ( V_8 )
goto V_21;
V_8 = F_50 ( V_2 -> V_18 , F_51 ( V_2 -> V_18 , 0x81 ) ) ;
if ( V_8 )
goto V_21;
} else {
V_8 = F_11 ( V_2 , V_95 , 0x10 , 0x10 ) ;
if ( V_8 )
goto V_21;
V_8 = F_11 ( V_2 , V_200 , 0x00 , 0x80 ) ;
if ( V_8 )
goto V_21;
V_8 = F_7 ( V_2 , V_198 , L_45 , 2 ) ;
if ( V_8 )
goto V_21;
}
return V_8 ;
V_21:
F_6 ( & V_2 -> V_22 -> V_6 , L_1 , V_8 ) ;
return V_8 ;
}
static int F_53 ( struct V_1 * V_2 , int V_193 )
{
struct V_5 * V_6 = F_18 ( V_2 ) ;
if ( V_6 -> V_100 == V_101 )
return F_49 ( V_2 , V_193 ) ;
else
return F_52 ( V_2 , V_193 ) ;
}
static int F_54 ( struct V_155 * V_123 , int V_193 )
{
struct V_1 * V_2 = F_55 ( V_123 ) ;
struct V_5 * V_6 = F_56 ( V_123 ) ;
struct V_140 * V_109 = & V_6 -> V_140 ;
int V_8 ;
T_1 V_24 ;
F_6 ( & V_2 -> V_22 -> V_6 , L_46 , V_123 -> V_201 , V_193 ) ;
if ( V_6 -> V_100 == V_101 )
return 0 ;
if ( V_123 -> V_201 == 0 && V_193 )
V_24 = 0x48 ;
else
V_24 = 0x00 ;
V_8 = F_11 ( V_2 , V_200 , V_24 , 0x48 ) ;
if ( V_8 )
goto V_21;
if ( V_123 -> V_201 == 1 && V_193 ) {
V_8 = V_109 -> V_202 ( V_6 -> V_127 ) ;
if ( V_8 )
goto V_21;
}
return 0 ;
V_21:
F_6 ( & V_2 -> V_22 -> V_6 , L_1 , V_8 ) ;
return V_8 ;
}
static int F_57 ( struct V_1 * V_2 )
{
int V_8 , V_203 ;
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_13 [ 5 ] ;
T_3 V_204 ;
struct V_205 V_206 [] = {
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
if ( ! V_6 -> V_207 ) {
for ( V_203 = 0 ; V_203 < F_58 ( V_206 ) ; V_203 ++ ) {
V_8 = F_9 ( V_2 , V_206 [ V_203 ] . V_23 ,
V_206 [ V_203 ] . V_24 ) ;
if ( V_8 )
goto V_21;
}
V_6 -> V_207 = true ;
}
V_8 = F_8 ( V_2 , V_208 , V_13 , 5 ) ;
if ( V_8 )
goto V_21;
if ( V_13 [ 4 ] & 0x01 ) {
if ( V_13 [ 2 ] == ( T_1 ) ~ V_13 [ 3 ] ) {
if ( V_13 [ 0 ] == ( T_1 ) ~ V_13 [ 1 ] ) {
V_204 = F_59 ( V_13 [ 0 ] , V_13 [ 2 ] ) ;
} else {
V_204 = F_60 ( V_13 [ 0 ] << 8 | V_13 [ 1 ] ,
V_13 [ 2 ] ) ;
}
} else {
V_204 = F_61 ( V_13 [ 0 ] << 24 | V_13 [ 1 ] << 16 |
V_13 [ 2 ] << 8 | V_13 [ 3 ] ) ;
}
F_62 ( V_2 -> V_209 , V_210 , V_204 , 0 ) ;
V_8 = F_9 ( V_2 , V_211 , 1 ) ;
if ( V_8 )
goto V_21;
V_8 = F_9 ( V_2 , V_211 , 1 ) ;
if ( V_8 )
goto V_21;
}
return V_8 ;
V_21:
F_6 ( & V_2 -> V_22 -> V_6 , L_1 , V_8 ) ;
return V_8 ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_212 * V_213 )
{
V_213 -> V_214 = V_215 ;
V_213 -> V_216 = V_217 ;
V_213 -> V_218 = F_57 ;
V_213 -> V_219 = 400 ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 )
{
int V_8 , V_203 , V_25 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_220 V_221 ;
T_1 V_13 [ 128 ] ;
static const struct V_222 V_223 [] = {
{ V_224 , 0x03 , 0xff } ,
{ V_225 , 0x80 , 0xff } ,
{ V_226 , 0x80 , 0xff } ,
} ;
if ( ! V_6 -> V_207 ) {
static const struct V_222 V_227 [] = {
{ V_199 , 0x00 , 0x04 } ,
{ V_199 , 0x00 , 0x08 } ,
{ V_228 , 0x20 , 0x20 } ,
{ V_59 , 0x00 , 0x08 } ,
{ V_60 , 0x08 , 0x08 } ,
{ V_95 , 0x08 , 0x08 } ,
{ V_229 , 0xd0 , 0xff } ,
{ V_230 , 0x07 , 0xff } ,
{ V_231 , 0xc0 , 0xff } ,
{ V_232 , 0x00 , 0xff } ,
{ V_233 , 0x03 , 0xff } ,
{ V_234 , 0x09 , 0xff } ,
{ V_235 , 0x1c , 0xff } ,
{ V_236 , 0x1e , 0xff } ,
{ V_237 , 0x1e , 0xff } ,
{ V_226 , 0x80 , 0xff } ,
} ;
for ( V_203 = 0 ; V_203 < F_58 ( V_227 ) ; V_203 ++ ) {
V_8 = F_11 ( V_2 , V_227 [ V_203 ] . V_23 ,
V_227 [ V_203 ] . V_24 , V_227 [ V_203 ] . V_32 ) ;
if ( V_8 )
goto V_21;
}
V_6 -> V_207 = true ;
}
V_8 = F_10 ( V_2 , V_224 , & V_13 [ 0 ] ) ;
if ( V_8 )
goto V_21;
if ( V_13 [ 0 ] != 0x83 )
goto exit;
V_8 = F_10 ( V_2 , V_238 , & V_13 [ 0 ] ) ;
if ( V_8 )
goto V_21;
V_25 = V_13 [ 0 ] ;
V_8 = F_8 ( V_2 , V_239 , V_13 , V_25 ) ;
if ( V_8 )
goto V_21;
for ( V_203 = 0 ; V_203 < F_58 ( V_223 ) ; V_203 ++ ) {
V_8 = F_11 ( V_2 , V_223 [ V_203 ] . V_23 ,
V_223 [ V_203 ] . V_24 , V_223 [ V_203 ] . V_32 ) ;
if ( V_8 )
goto V_21;
}
F_65 ( & V_221 ) ;
for ( V_203 = 0 ; V_203 < V_25 ; V_203 ++ ) {
V_221 . V_240 = V_13 [ V_203 ] >> 7 ;
V_221 . V_241 = 50800 * ( V_13 [ V_203 ] & 0x7f ) ;
F_66 ( V_2 -> V_209 , & V_221 ) ;
}
F_67 ( V_2 -> V_209 , true ) ;
F_68 ( V_2 -> V_209 ) ;
exit:
return V_8 ;
V_21:
F_6 ( & V_2 -> V_22 -> V_6 , L_1 , V_8 ) ;
return V_8 ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_212 * V_213 )
{
if ( V_242 )
return F_9 ( V_2 , V_243 , 0x00 ) ;
if ( ! V_213 -> V_214 )
V_213 -> V_214 = V_215 ;
V_213 -> V_216 = V_244 ;
V_213 -> V_245 = V_246 ;
V_213 -> V_218 = F_64 ;
V_213 -> V_219 = 400 ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 ,
struct V_212 * V_213 )
{
struct V_5 * V_6 = F_18 ( V_2 ) ;
if ( V_6 -> V_100 == V_101 )
return F_63 ( V_2 , V_213 ) ;
else
return F_69 ( V_2 , V_213 ) ;
}
static int F_71 ( struct V_107 * V_35 , int V_193 )
{
struct V_5 * V_6 = F_37 ( V_35 ) ;
if ( V_6 -> V_100 == V_101 ) {
struct V_108 * V_109 = & V_6 -> V_108 ;
return V_109 -> V_247 ( V_35 -> V_123 [ 0 ] , V_193 ) ;
} else {
struct V_140 * V_109 = & V_6 -> V_140 ;
return V_109 -> V_247 ( V_35 -> V_123 [ 0 ] , V_193 ) ;
}
}
static int F_72 ( struct V_107 * V_35 , int V_11 ,
T_2 V_248 , int V_193 )
{
struct V_5 * V_6 = F_37 ( V_35 ) ;
if ( V_6 -> V_100 == V_101 ) {
struct V_108 * V_109 = & V_6 -> V_108 ;
return V_109 -> V_249 ( V_35 -> V_123 [ 0 ] , V_11 , V_248 , V_193 ) ;
} else {
struct V_140 * V_109 = & V_6 -> V_140 ;
return V_109 -> V_249 ( V_35 -> V_123 [ 0 ] , V_11 , V_248 , V_193 ) ;
}
}
