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
} else if ( ( V_37 [ 0 ] . V_25 < 23 ) && ( ! V_6 -> V_52 ) ) {
V_4 . V_20 = ( V_37 [ 0 ] . V_13 [ 0 ] << 8 ) | ( V_37 [ 0 ] . V_45 << 1 ) ;
V_4 . V_11 = V_53 ;
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
} else if ( V_38 == 1 && ( V_37 [ 0 ] . V_41 & V_42 ) ) {
V_4 . V_20 = ( V_37 [ 0 ] . V_45 << 1 ) ;
V_4 . V_11 = V_50 ;
V_4 . V_15 = V_37 [ 0 ] . V_25 ;
V_4 . V_14 = V_37 [ 0 ] . V_13 ;
V_8 = F_1 ( V_2 , & V_4 ) ;
} else {
V_8 = - V_43 ;
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
struct V_3 V_82 = { 0x00c0 , V_48 , 1 , V_13 } ;
struct V_3 V_83 = { 0x00c8 , V_48 , 1 , V_13 } ;
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
V_6 -> V_62 = V_84 ;
V_6 -> V_61 = L_11 ;
goto V_85;
}
V_8 = F_1 ( V_2 , & V_69 ) ;
if ( V_8 == 0 && V_13 [ 0 ] == 0xa3 ) {
V_6 -> V_62 = V_86 ;
V_6 -> V_61 = L_12 ;
goto V_85;
}
V_8 = F_1 ( V_2 , & V_70 ) ;
if ( V_8 == 0 && V_13 [ 0 ] == 0x85 ) {
V_6 -> V_62 = V_87 ;
V_6 -> V_61 = L_13 ;
goto V_85;
}
V_8 = F_1 ( V_2 , & V_71 ) ;
if ( V_8 == 0 && V_13 [ 0 ] == 0x56 ) {
V_6 -> V_62 = V_88 ;
V_6 -> V_61 = L_14 ;
goto V_85;
}
V_8 = F_1 ( V_2 , & V_72 ) ;
if ( V_8 == 0 && ( V_13 [ 0 ] == 0x9e || V_13 [ 0 ] == 0x9c ) ) {
V_6 -> V_62 = V_89 ;
V_6 -> V_61 = L_15 ;
goto V_85;
}
V_8 = F_1 ( V_2 , & V_73 ) ;
if ( V_8 == 0 && V_13 [ 0 ] == 0x38 ) {
V_6 -> V_62 = V_90 ;
V_6 -> V_61 = L_16 ;
goto V_85;
}
V_8 = F_1 ( V_2 , & V_74 ) ;
if ( V_8 == 0 && V_13 [ 0 ] == 0x23 && V_13 [ 1 ] == 0x28 ) {
V_6 -> V_62 = V_91 ;
V_6 -> V_61 = L_17 ;
goto V_85;
}
V_8 = F_1 ( V_2 , & V_75 ) ;
if ( V_8 == 0 && V_13 [ 0 ] == 0x14 ) {
V_6 -> V_62 = V_92 ;
V_6 -> V_61 = L_18 ;
goto V_85;
}
V_8 = F_1 ( V_2 , & V_76 ) ;
if ( V_8 == 0 && V_13 [ 0 ] == 0x40 ) {
V_6 -> V_62 = V_93 ;
V_6 -> V_61 = L_19 ;
goto V_85;
}
V_8 = F_1 ( V_2 , & V_77 ) ;
if ( V_8 == 0 && ( V_13 [ 0 ] == 0xc7 || V_13 [ 1 ] == 0x60 ) ) {
V_6 -> V_62 = V_94 ;
V_6 -> V_61 = L_20 ;
goto V_85;
}
V_8 = F_1 ( V_2 , & V_78 ) ;
if ( V_8 == 0 && V_13 [ 0 ] == 0x69 ) {
V_6 -> V_62 = V_95 ;
V_6 -> V_61 = L_21 ;
goto V_85;
}
V_8 = F_1 ( V_2 , & V_79 ) ;
if ( V_8 == 0 && V_13 [ 0 ] == 0x69 ) {
V_6 -> V_62 = V_96 ;
V_6 -> V_61 = L_22 ;
goto V_85;
}
V_8 = F_11 ( V_2 , V_97 , 0x00 , 0x21 ) ;
if ( V_8 )
goto V_21;
V_8 = F_11 ( V_2 , V_60 , 0x00 , 0x21 ) ;
if ( V_8 )
goto V_21;
F_19 ( 50 ) ;
V_8 = F_11 ( V_2 , V_97 , 0x21 , 0x21 ) ;
if ( V_8 )
goto V_21;
V_8 = F_11 ( V_2 , V_60 , 0x21 , 0x21 ) ;
if ( V_8 )
goto V_21;
F_19 ( 50 ) ;
V_8 = F_1 ( V_2 , & V_82 ) ;
if ( V_8 == 0 && ( ( V_13 [ 0 ] & 0x80 ) == 0x80 ) ) {
V_6 -> V_62 = V_98 ;
V_6 -> V_61 = L_23 ;
goto V_85;
}
V_85:
F_6 ( & V_2 -> V_22 -> V_6 , L_8 , V_6 -> V_61 ) ;
if ( V_6 -> V_62 == V_96 ) {
V_8 = F_11 ( V_2 , V_97 , 0x01 , 0x01 ) ;
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
F_6 ( & V_2 -> V_22 -> V_6 , L_24 ) ;
V_6 -> V_99 = V_100 ;
goto V_101;
}
V_8 = F_1 ( V_2 , & V_81 ) ;
if ( V_8 == 0 && V_13 [ 0 ] == 0x03 ) {
F_6 ( & V_2 -> V_22 -> V_6 , L_25 ) ;
V_6 -> V_99 = V_102 ;
goto V_101;
}
}
if ( V_6 -> V_62 == V_98 ) {
V_8 = F_1 ( V_2 , & V_83 ) ;
if ( V_8 == 0 && ( ( V_13 [ 0 ] & 0x80 ) == 0x80 ) ) {
F_6 ( & V_2 -> V_22 -> V_6 , L_26 ) ;
V_6 -> V_99 = V_103 ;
goto V_101;
}
}
V_101:
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
if ( V_6 -> V_104 == V_105 )
return F_17 ( V_2 ) ;
else
return F_20 ( V_2 ) ;
}
static int F_22 ( struct V_1 * V_2 , const char * * V_106 )
{
struct V_5 * V_6 = F_18 ( V_2 ) ;
int V_8 ;
struct V_3 V_107 = { 0x0020 , V_50 , 0 , NULL } ;
F_6 ( & V_2 -> V_22 -> V_6 , L_3 ) ;
V_8 = F_1 ( V_2 , & V_107 ) ;
if ( V_8 == - V_108 ) {
V_6 -> V_104 = V_105 ;
} else if ( V_8 == 0 ) {
V_6 -> V_104 = V_109 ;
} else {
F_23 ( & V_2 -> V_22 -> V_6 , L_27 , V_8 ) ;
goto V_21;
}
F_6 ( & V_2 -> V_22 -> V_6 , L_28 , V_6 -> V_104 ) ;
return V_110 ;
V_21:
F_6 ( & V_2 -> V_22 -> V_6 , L_1 , V_8 ) ;
return V_8 ;
}
static int F_24 ( struct V_111 * V_35 )
{
struct V_1 * V_2 = F_25 ( V_35 ) ;
struct V_5 * V_6 = F_18 ( V_2 ) ;
struct V_112 * V_113 = & V_6 -> V_112 ;
struct V_114 V_115 ;
struct V_116 * V_117 ;
int V_8 ;
F_6 ( & V_2 -> V_22 -> V_6 , L_3 ) ;
switch ( V_6 -> V_62 ) {
case V_63 :
* V_113 = V_118 ;
break;
case V_65 :
* V_113 = V_119 ;
break;
case V_66 :
* V_113 = V_120 ;
break;
default:
F_23 ( & V_2 -> V_22 -> V_6 , L_29 , V_6 -> V_61 ) ;
V_8 = - V_121 ;
goto V_21;
}
memset ( & V_115 , 0 , sizeof( V_115 ) ) ;
F_26 ( V_115 . type , L_30 , V_122 ) ;
V_115 . V_45 = 0x10 ;
V_115 . V_123 = V_113 ;
F_27 ( L_31 , V_115 . type ) ;
V_117 = F_28 ( & V_2 -> V_124 , & V_115 ) ;
if ( V_117 == NULL || V_117 -> V_6 . V_125 == NULL ) {
V_8 = - V_121 ;
goto V_21;
}
if ( ! F_29 ( V_117 -> V_6 . V_125 -> V_126 ) ) {
F_30 ( V_117 ) ;
V_8 = - V_121 ;
goto V_21;
}
V_35 -> V_127 [ 0 ] = V_113 -> V_128 ( V_117 ) ;
V_6 -> V_129 = V_113 -> V_130 ( V_117 ) ;
V_6 -> V_131 = V_117 ;
return 0 ;
V_21:
F_6 ( & V_2 -> V_22 -> V_6 , L_1 , V_8 ) ;
return V_8 ;
}
static int F_31 ( struct V_1 * V_2 ,
int V_132 , int V_133 )
{
int V_8 ;
T_1 V_24 ;
F_6 ( & V_2 -> V_22 -> V_6 , L_32 , V_132 , V_133 ) ;
switch ( V_132 ) {
case V_134 :
V_8 = F_10 ( V_2 , V_97 , & V_24 ) ;
if ( V_8 )
goto V_21;
if ( V_133 )
V_24 &= 0xbf ;
else
V_24 |= 0x40 ;
V_8 = F_9 ( V_2 , V_97 , V_24 ) ;
if ( V_8 )
goto V_21;
break;
default:
V_8 = - V_135 ;
goto V_21;
}
return 0 ;
V_21:
F_6 ( & V_2 -> V_22 -> V_6 , L_1 , V_8 ) ;
return V_8 ;
}
static int F_32 ( struct V_1 * V_2 ,
int V_132 , int V_133 )
{
int V_8 ;
T_1 V_24 ;
F_6 ( & V_2 -> V_22 -> V_6 , L_32 , V_132 , V_133 ) ;
switch ( V_132 ) {
case V_136 :
if ( V_133 )
V_24 = ( 1 << 4 ) ;
else
V_24 = ( 0 << 4 ) ;
V_8 = F_11 ( V_2 , V_97 , V_24 , 0x10 ) ;
if ( V_8 )
goto V_21;
break;
case V_137 :
if ( V_133 )
V_24 = ( 1 << 1 ) ;
else
V_24 = ( 0 << 1 ) ;
V_8 = F_11 ( V_2 , V_97 , V_24 , 0x02 ) ;
if ( V_8 )
goto V_21;
break;
}
return 0 ;
V_21:
F_6 ( & V_2 -> V_22 -> V_6 , L_1 , V_8 ) ;
return V_8 ;
}
static int F_33 ( void * V_138 , int V_139 ,
int V_132 , int V_133 )
{
struct V_34 * V_54 = V_138 ;
struct V_140 * V_141 = V_54 -> V_6 . V_141 ;
struct V_34 * V_142 ;
struct V_1 * V_2 ;
struct V_5 * V_6 ;
if ( V_141 != NULL && V_141 -> type == & V_143 )
V_142 = F_34 ( V_141 ) ;
else
return - V_135 ;
V_2 = F_13 ( V_142 ) ;
V_6 = V_2 -> V_7 ;
F_6 ( & V_2 -> V_22 -> V_6 , L_33 ,
V_139 , V_132 , V_133 ) ;
switch ( V_139 ) {
case V_144 :
switch ( V_6 -> V_62 ) {
case V_84 :
return F_31 ( V_2 , V_132 , V_133 ) ;
case V_91 :
return F_32 ( V_2 , V_132 , V_133 ) ;
}
}
return 0 ;
}
static int F_35 ( struct V_111 * V_35 )
{
struct V_1 * V_2 = F_25 ( V_35 ) ;
struct V_5 * V_6 = F_18 ( V_2 ) ;
struct V_145 * V_113 = & V_6 -> V_145 ;
struct V_114 V_115 ;
struct V_116 * V_117 ;
int V_8 ;
F_6 ( & V_2 -> V_22 -> V_6 , L_3 ) ;
switch ( V_6 -> V_62 ) {
case V_84 :
* V_113 = V_146 ;
break;
case V_86 :
* V_113 = V_147 ;
break;
case V_88 :
* V_113 = V_148 ;
break;
case V_91 :
* V_113 = V_149 ;
break;
case V_93 :
* V_113 = V_150 ;
break;
case V_95 :
case V_96 :
* V_113 = V_151 ;
break;
case V_98 :
* V_113 = V_152 ;
break;
default:
F_23 ( & V_2 -> V_22 -> V_6 , L_29 , V_6 -> V_61 ) ;
V_8 = - V_121 ;
goto V_21;
}
memset ( & V_115 , 0 , sizeof( V_115 ) ) ;
F_26 ( V_115 . type , L_34 , V_122 ) ;
V_115 . V_45 = 0x10 ;
V_115 . V_123 = V_113 ;
F_27 ( L_31 , V_115 . type ) ;
V_117 = F_28 ( & V_2 -> V_124 , & V_115 ) ;
if ( V_117 == NULL || V_117 -> V_6 . V_125 == NULL ) {
V_8 = - V_121 ;
goto V_21;
}
if ( ! F_29 ( V_117 -> V_6 . V_125 -> V_126 ) ) {
F_30 ( V_117 ) ;
V_8 = - V_121 ;
goto V_21;
}
V_35 -> V_127 [ 0 ] = V_113 -> V_128 ( V_117 ) ;
V_6 -> V_129 = V_113 -> V_130 ( V_117 ) ;
V_6 -> V_131 = V_117 ;
V_35 -> V_127 [ 0 ] -> V_153 = F_33 ;
if ( V_6 -> V_99 ) {
struct V_114 V_154 = {} ;
V_8 = 0 ;
if ( V_6 -> V_99 == V_100 ) {
struct V_155 V_155 = {} ;
V_155 . V_127 = & V_35 -> V_127 [ 1 ] ;
V_155 . V_156 = 22 ,
F_26 ( V_154 . type , L_35 , V_122 ) ;
V_155 . V_157 = 20500000 ;
V_155 . V_158 = V_159 ;
V_155 . V_160 = V_161 ;
V_154 . V_45 = 0x18 ;
V_154 . V_123 = & V_155 ;
F_27 ( V_154 . type ) ;
V_117 = F_28 ( & V_2 -> V_124 , & V_154 ) ;
if ( V_117 == NULL || V_117 -> V_6 . V_125 == NULL ) {
V_6 -> V_99 = V_162 ;
goto V_163;
}
if ( ! F_29 ( V_117 -> V_6 . V_125 -> V_126 ) ) {
F_30 ( V_117 ) ;
V_6 -> V_99 = V_162 ;
goto V_163;
}
V_6 -> V_164 = V_117 ;
} else if ( V_6 -> V_99 == V_102 ) {
struct V_165 V_165 = {} ;
V_165 . V_127 = & V_35 -> V_127 [ 1 ] ;
V_165 . V_156 = 22 ,
F_26 ( V_154 . type , L_36 , V_122 ) ;
V_154 . V_45 = 0x18 ;
V_154 . V_123 = & V_165 ;
F_27 ( V_154 . type ) ;
V_117 = F_28 ( & V_2 -> V_124 , & V_154 ) ;
if ( V_117 == NULL || V_117 -> V_6 . V_125 == NULL ) {
V_6 -> V_99 = V_162 ;
goto V_163;
}
if ( ! F_29 ( V_117 -> V_6 . V_125 -> V_126 ) ) {
F_30 ( V_117 ) ;
V_6 -> V_99 = V_162 ;
goto V_163;
}
V_6 -> V_164 = V_117 ;
} else {
struct V_166 V_166 = {} ;
struct V_34 * V_54 ;
V_166 . V_34 = & V_54 ;
V_166 . V_127 = & V_35 -> V_127 [ 1 ] ;
V_166 . V_158 = V_167 ;
V_166 . V_168 = false ;
V_166 . V_169 = true ;
F_26 ( V_154 . type , L_37 , V_122 ) ;
V_154 . V_45 = 0x64 ;
V_154 . V_123 = & V_166 ;
F_27 ( V_154 . type ) ;
V_117 = F_28 ( & V_2 -> V_124 , & V_154 ) ;
if ( V_117 == NULL || V_117 -> V_6 . V_125 == NULL ) {
V_6 -> V_99 = V_162 ;
goto V_163;
}
if ( ! F_29 ( V_117 -> V_6 . V_125 -> V_126 ) ) {
F_30 ( V_117 ) ;
V_6 -> V_99 = V_162 ;
goto V_163;
}
V_6 -> V_164 = V_117 ;
V_6 -> V_52 = true ;
}
}
return 0 ;
V_163:
V_21:
F_6 ( & V_2 -> V_22 -> V_6 , L_1 , V_8 ) ;
return V_8 ;
}
static int F_36 ( struct V_111 * V_35 )
{
struct V_5 * V_6 = F_37 ( V_35 ) ;
if ( V_6 -> V_104 == V_105 )
return F_24 ( V_35 ) ;
else
return F_35 ( V_35 ) ;
}
static int F_38 ( struct V_111 * V_35 )
{
struct V_1 * V_2 = F_25 ( V_35 ) ;
struct V_5 * V_6 = F_18 ( V_2 ) ;
struct V_116 * V_117 ;
F_6 ( & V_2 -> V_22 -> V_6 , L_3 ) ;
V_117 = V_6 -> V_164 ;
if ( V_117 ) {
F_39 ( V_117 -> V_6 . V_125 -> V_126 ) ;
F_30 ( V_117 ) ;
}
V_117 = V_6 -> V_131 ;
if ( V_117 ) {
F_39 ( V_117 -> V_6 . V_125 -> V_126 ) ;
F_30 ( V_117 ) ;
}
return 0 ;
}
static int F_40 ( struct V_111 * V_35 )
{
int V_8 ;
struct V_1 * V_2 = F_25 ( V_35 ) ;
struct V_5 * V_6 = F_18 ( V_2 ) ;
struct V_170 * V_127 ;
F_6 ( & V_2 -> V_22 -> V_6 , L_3 ) ;
switch ( V_6 -> V_62 ) {
case V_63 :
V_127 = F_41 ( V_171 , V_35 -> V_127 [ 0 ] ,
V_6 -> V_129 ,
& V_172 ) ;
break;
case V_65 :
V_127 = F_41 ( V_173 , V_35 -> V_127 [ 0 ] ,
V_6 -> V_129 ,
& V_174 , 1220 ) ;
break;
case V_66 :
V_127 = F_41 ( V_175 , V_35 -> V_127 [ 0 ] ,
V_6 -> V_129 ,
& V_176 ) ;
break;
default:
V_127 = NULL ;
F_23 ( & V_2 -> V_22 -> V_6 , L_38 , V_6 -> V_62 ) ;
}
if ( V_127 == NULL ) {
V_8 = - V_121 ;
goto V_21;
}
return 0 ;
V_21:
F_6 ( & V_2 -> V_22 -> V_6 , L_1 , V_8 ) ;
return V_8 ;
}
static int F_42 ( struct V_111 * V_35 )
{
int V_8 ;
struct V_1 * V_2 = F_25 ( V_35 ) ;
struct V_5 * V_6 = F_18 ( V_2 ) ;
struct V_170 * V_127 = NULL ;
struct V_114 V_154 ;
struct V_116 * V_117 ;
struct V_177 * V_178 = NULL ;
struct V_179 * V_180 ;
struct V_181 V_113 ;
F_6 ( & V_2 -> V_22 -> V_6 , L_3 ) ;
memset ( & V_154 , 0 , sizeof( struct V_114 ) ) ;
memset ( & V_113 , 0 , sizeof( V_113 ) ) ;
switch ( V_6 -> V_62 ) {
case V_84 :
V_127 = F_41 ( V_182 , V_35 -> V_127 [ 0 ] ,
V_6 -> V_129 , & V_183 ) ;
V_35 -> V_127 [ 0 ] -> V_184 . V_185 =
V_35 -> V_127 [ 0 ] -> V_184 . V_186 . V_187 ;
break;
case V_86 :
V_127 = F_41 ( V_188 , V_35 -> V_127 [ 0 ] ,
V_6 -> V_129 , 0xc6 >> 1 , 0 , V_189 ) ;
V_35 -> V_127 [ 0 ] -> V_184 . V_185 =
V_35 -> V_127 [ 0 ] -> V_184 . V_186 . V_187 ;
break;
case V_93 : {
struct V_190 V_190 = {
. V_127 = V_35 -> V_127 [ 0 ] ,
. clock = 28800000 ,
} ;
F_26 ( V_154 . type , L_39 , V_122 ) ;
V_154 . V_45 = 0x64 ;
V_154 . V_123 = & V_190 ;
F_27 ( V_154 . type ) ;
V_117 = F_28 ( V_6 -> V_129 , & V_154 ) ;
if ( V_117 == NULL || V_117 -> V_6 . V_125 == NULL )
break;
if ( ! F_29 ( V_117 -> V_6 . V_125 -> V_126 ) ) {
F_30 ( V_117 ) ;
break;
}
V_6 -> V_191 = V_117 ;
V_178 = F_43 ( V_117 ) ;
}
break;
case V_88 : {
struct V_192 V_193 = {
. V_170 = V_35 -> V_127 [ 0 ] ,
} ;
struct V_114 V_115 = {} ;
F_26 ( V_115 . type , L_40 , V_122 ) ;
V_115 . V_45 = 0x56 ;
V_115 . V_123 = & V_193 ;
F_27 ( L_40 ) ;
V_117 = F_28 ( V_6 -> V_129 ,
& V_115 ) ;
if ( V_117 == NULL || V_117 -> V_6 . V_125 == NULL )
break;
if ( ! F_29 ( V_117 -> V_6 . V_125 -> V_126 ) ) {
F_30 ( V_117 ) ;
break;
}
V_6 -> V_191 = V_117 ;
V_178 = V_193 . V_194 ( V_117 ) ;
}
break;
case V_91 : {
struct V_195 V_196 = {
. V_170 = V_35 -> V_127 [ 0 ] ,
} ;
struct V_114 V_115 = {} ;
V_8 = F_11 ( V_2 , V_59 , 0x00 , 0x12 ) ;
if ( V_8 )
goto V_21;
V_8 = F_11 ( V_2 , V_60 , 0x12 , 0x12 ) ;
if ( V_8 )
goto V_21;
F_26 ( V_115 . type , L_41 , V_122 ) ;
V_115 . V_45 = 0x60 ;
V_115 . V_123 = & V_196 ;
F_27 ( L_41 ) ;
V_117 = F_28 ( V_6 -> V_129 , & V_115 ) ;
if ( V_117 == NULL || V_117 -> V_6 . V_125 == NULL )
break;
if ( ! F_29 ( V_117 -> V_6 . V_125 -> V_126 ) ) {
F_30 ( V_117 ) ;
break;
}
V_6 -> V_191 = V_117 ;
break;
}
case V_95 :
V_127 = F_41 ( V_197 , V_35 -> V_127 [ 0 ] ,
V_6 -> V_129 ,
& V_198 ) ;
V_35 -> V_127 [ 0 ] -> V_184 . V_185 =
V_35 -> V_127 [ 0 ] -> V_184 . V_186 . V_187 ;
break;
case V_96 :
V_127 = F_41 ( V_197 , V_35 -> V_127 [ 0 ] ,
V_6 -> V_129 ,
& V_199 ) ;
V_35 -> V_127 [ 0 ] -> V_184 . V_185 =
V_35 -> V_127 [ 0 ] -> V_184 . V_186 . V_187 ;
if ( V_35 -> V_127 [ 1 ] ) {
V_127 = F_41 ( V_197 , V_35 -> V_127 [ 1 ] ,
V_6 -> V_129 ,
& V_199 ) ;
V_35 -> V_127 [ 1 ] -> V_184 . V_185 =
V_35 -> V_127 [ 1 ] -> V_184 . V_186 . V_187 ;
}
break;
case V_98 : {
struct V_200 V_200 = {
. V_127 = V_35 -> V_127 [ 0 ] ,
. V_201 = 0 ,
. V_202 = false ,
} ;
F_26 ( V_154 . type , L_42 , V_122 ) ;
V_154 . V_45 = 0x60 ;
V_154 . V_123 = & V_200 ;
F_27 ( V_154 . type ) ;
V_117 = F_28 ( & V_2 -> V_124 , & V_154 ) ;
if ( V_117 == NULL || V_117 -> V_6 . V_125 == NULL )
break;
if ( ! F_29 ( V_117 -> V_6 . V_125 -> V_126 ) ) {
F_30 ( V_117 ) ;
break;
}
V_6 -> V_191 = V_117 ;
V_178 = F_43 ( V_117 ) ;
if ( V_35 -> V_127 [ 1 ] ) {
V_35 -> V_127 [ 1 ] -> V_203 =
V_35 -> V_127 [ 0 ] -> V_203 ;
memcpy ( & V_35 -> V_127 [ 1 ] -> V_184 . V_186 ,
& V_35 -> V_127 [ 0 ] -> V_184 . V_186 ,
sizeof( struct V_204 ) ) ;
}
}
break;
default:
F_23 ( & V_2 -> V_22 -> V_6 , L_38 , V_6 -> V_62 ) ;
}
if ( V_127 == NULL && V_6 -> V_191 == NULL ) {
V_8 = - V_121 ;
goto V_21;
}
switch ( V_6 -> V_62 ) {
case V_88 :
case V_84 :
case V_86 :
case V_93 :
case V_95 :
case V_96 :
V_113 . V_205 = V_6 -> V_145 . V_205 ;
V_113 . V_62 = V_6 -> V_62 ;
V_113 . V_116 = V_6 -> V_131 ;
V_113 . V_206 = V_6 -> V_145 . V_206 ;
V_113 . V_207 = V_6 -> V_145 . V_207 ;
V_113 . V_208 = V_6 -> V_145 . V_208 ;
V_113 . V_170 = V_35 -> V_127 [ 0 ] ;
V_113 . V_1 = V_2 ;
V_113 . V_177 = V_178 ;
F_27 ( L_31 , L_43 ) ;
V_180 = F_44 ( & V_2 -> V_22 -> V_6 ,
L_43 ,
V_209 ,
& V_113 , sizeof( V_113 ) ) ;
if ( F_45 ( V_180 ) || V_180 -> V_6 . V_125 == NULL )
break;
V_6 -> V_210 = V_180 ;
break;
default:
F_6 ( & V_2 -> V_22 -> V_6 , L_44 , V_6 -> V_62 ) ;
}
return 0 ;
V_21:
F_6 ( & V_2 -> V_22 -> V_6 , L_1 , V_8 ) ;
return V_8 ;
}
static int F_46 ( struct V_111 * V_35 )
{
struct V_5 * V_6 = F_37 ( V_35 ) ;
if ( V_6 -> V_104 == V_105 )
return F_40 ( V_35 ) ;
else
return F_42 ( V_35 ) ;
}
static int F_47 ( struct V_111 * V_35 )
{
struct V_1 * V_2 = F_25 ( V_35 ) ;
struct V_5 * V_6 = F_18 ( V_2 ) ;
struct V_116 * V_117 ;
struct V_179 * V_180 ;
F_6 ( & V_2 -> V_22 -> V_6 , L_3 ) ;
V_180 = V_6 -> V_210 ;
if ( V_180 )
F_48 ( V_180 ) ;
V_117 = V_6 -> V_191 ;
if ( V_117 ) {
F_39 ( V_117 -> V_6 . V_125 -> V_126 ) ;
F_30 ( V_117 ) ;
}
return 0 ;
}
static int F_49 ( struct V_1 * V_2 )
{
int V_8 ;
T_1 V_24 ;
F_6 ( & V_2 -> V_22 -> V_6 , L_3 ) ;
V_8 = F_10 ( V_2 , V_211 , & V_24 ) ;
if ( V_8 )
goto V_21;
V_24 |= 0x09 ;
V_8 = F_9 ( V_2 , V_211 , V_24 ) ;
if ( V_8 )
goto V_21;
V_8 = F_7 ( V_2 , V_212 , L_45 , 4 ) ;
if ( V_8 )
goto V_21;
V_8 = F_7 ( V_2 , V_213 , L_46 , 4 ) ;
if ( V_8 )
goto V_21;
return V_8 ;
V_21:
F_6 ( & V_2 -> V_22 -> V_6 , L_1 , V_8 ) ;
return V_8 ;
}
static int F_50 ( struct V_1 * V_2 , int V_214 )
{
int V_8 ;
T_1 V_215 , V_216 , V_217 [ 2 ] ;
F_6 ( & V_2 -> V_22 -> V_6 , L_47 , V_214 ) ;
V_8 = F_10 ( V_2 , V_218 , & V_216 ) ;
if ( V_8 )
goto V_21;
V_8 = F_10 ( V_2 , V_97 , & V_215 ) ;
if ( V_8 )
goto V_21;
F_6 ( & V_2 -> V_22 -> V_6 , L_48 , V_216 , V_215 ) ;
if ( V_214 ) {
V_215 |= 0x01 ;
V_215 &= ( ~ 0x10 ) ;
V_215 |= 0x04 ;
V_216 = V_216 & 0x0f ;
V_216 |= 0xe0 ;
V_217 [ 0 ] = 0x00 ;
V_217 [ 1 ] = 0x00 ;
} else {
V_215 &= ( ~ 0x01 ) ;
V_215 |= 0x10 ;
V_215 &= ( ~ 0x04 ) ;
V_216 = V_216 & ( ~ 0xc0 ) ;
V_217 [ 0 ] = 0x10 ;
V_217 [ 1 ] = 0x02 ;
}
F_6 ( & V_2 -> V_22 -> V_6 , L_49 , V_216 , V_215 ) ;
V_8 = F_9 ( V_2 , V_218 , V_216 ) ;
if ( V_8 )
goto V_21;
V_8 = F_9 ( V_2 , V_97 , V_215 ) ;
if ( V_8 )
goto V_21;
V_8 = F_7 ( V_2 , V_219 , V_217 , 2 ) ;
if ( V_8 )
goto V_21;
if ( V_214 )
F_51 ( V_2 -> V_18 , F_52 ( V_2 -> V_18 , 0x81 ) ) ;
return V_8 ;
V_21:
F_6 ( & V_2 -> V_22 -> V_6 , L_1 , V_8 ) ;
return V_8 ;
}
static int F_53 ( struct V_1 * V_2 , int V_214 )
{
int V_8 ;
F_6 ( & V_2 -> V_22 -> V_6 , L_47 , V_214 ) ;
if ( V_214 ) {
V_8 = F_11 ( V_2 , V_97 , 0x08 , 0x18 ) ;
if ( V_8 )
goto V_21;
V_8 = F_11 ( V_2 , V_220 , 0x00 , 0x10 ) ;
if ( V_8 )
goto V_21;
V_8 = F_11 ( V_2 , V_221 , 0x80 , 0x80 ) ;
if ( V_8 )
goto V_21;
V_8 = F_11 ( V_2 , V_221 , 0x20 , 0x20 ) ;
if ( V_8 )
goto V_21;
V_8 = F_7 ( V_2 , V_219 , L_50 , 2 ) ;
if ( V_8 )
goto V_21;
V_8 = F_51 ( V_2 -> V_18 , F_52 ( V_2 -> V_18 , 0x81 ) ) ;
if ( V_8 )
goto V_21;
} else {
V_8 = F_11 ( V_2 , V_97 , 0x10 , 0x10 ) ;
if ( V_8 )
goto V_21;
V_8 = F_11 ( V_2 , V_221 , 0x00 , 0x80 ) ;
if ( V_8 )
goto V_21;
V_8 = F_7 ( V_2 , V_219 , L_51 , 2 ) ;
if ( V_8 )
goto V_21;
}
return V_8 ;
V_21:
F_6 ( & V_2 -> V_22 -> V_6 , L_1 , V_8 ) ;
return V_8 ;
}
static int F_54 ( struct V_1 * V_2 , int V_214 )
{
struct V_5 * V_6 = F_18 ( V_2 ) ;
if ( V_6 -> V_104 == V_105 )
return F_50 ( V_2 , V_214 ) ;
else
return F_53 ( V_2 , V_214 ) ;
}
static int F_55 ( struct V_170 * V_127 , int V_214 )
{
struct V_1 * V_2 = F_56 ( V_127 ) ;
struct V_5 * V_6 = F_57 ( V_127 ) ;
struct V_145 * V_113 = & V_6 -> V_145 ;
int V_8 ;
T_1 V_24 ;
F_6 ( & V_2 -> V_22 -> V_6 , L_52 , V_127 -> V_222 , V_214 ) ;
if ( V_6 -> V_104 == V_105 )
return 0 ;
if ( V_127 -> V_222 == 0 && V_214 )
V_24 = 0x48 ;
else
V_24 = 0x00 ;
V_8 = F_11 ( V_2 , V_221 , V_24 , 0x48 ) ;
if ( V_8 )
goto V_21;
if ( V_127 -> V_222 == 1 && V_214 ) {
V_8 = V_113 -> V_223 ( V_6 -> V_131 ) ;
if ( V_8 )
goto V_21;
}
return 0 ;
V_21:
F_6 ( & V_2 -> V_22 -> V_6 , L_1 , V_8 ) ;
return V_8 ;
}
static int F_58 ( struct V_1 * V_2 )
{
int V_8 , V_224 ;
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_13 [ 5 ] ;
T_3 V_225 ;
struct V_226 V_227 [] = {
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
if ( ! V_6 -> V_228 ) {
for ( V_224 = 0 ; V_224 < F_59 ( V_227 ) ; V_224 ++ ) {
V_8 = F_9 ( V_2 , V_227 [ V_224 ] . V_23 ,
V_227 [ V_224 ] . V_24 ) ;
if ( V_8 )
goto V_21;
}
V_6 -> V_228 = true ;
}
V_8 = F_8 ( V_2 , V_229 , V_13 , 5 ) ;
if ( V_8 )
goto V_21;
if ( V_13 [ 4 ] & 0x01 ) {
if ( V_13 [ 2 ] == ( T_1 ) ~ V_13 [ 3 ] ) {
if ( V_13 [ 0 ] == ( T_1 ) ~ V_13 [ 1 ] ) {
V_225 = F_60 ( V_13 [ 0 ] , V_13 [ 2 ] ) ;
} else {
V_225 = F_61 ( V_13 [ 0 ] << 8 | V_13 [ 1 ] ,
V_13 [ 2 ] ) ;
}
} else {
V_225 = F_62 ( V_13 [ 0 ] << 24 | V_13 [ 1 ] << 16 |
V_13 [ 2 ] << 8 | V_13 [ 3 ] ) ;
}
F_63 ( V_2 -> V_230 , V_231 , V_225 , 0 ) ;
V_8 = F_9 ( V_2 , V_232 , 1 ) ;
if ( V_8 )
goto V_21;
V_8 = F_9 ( V_2 , V_232 , 1 ) ;
if ( V_8 )
goto V_21;
}
return V_8 ;
V_21:
F_6 ( & V_2 -> V_22 -> V_6 , L_1 , V_8 ) ;
return V_8 ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_233 * V_234 )
{
V_234 -> V_235 = V_236 ;
V_234 -> V_237 = V_238 ;
V_234 -> V_239 = F_58 ;
V_234 -> V_240 = 400 ;
return 0 ;
}
static int F_65 ( struct V_1 * V_2 )
{
int V_8 , V_224 , V_25 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_241 V_242 ;
T_1 V_13 [ 128 ] ;
static const struct V_243 V_244 [] = {
{ V_245 , 0x03 , 0xff } ,
{ V_246 , 0x80 , 0xff } ,
{ V_247 , 0x80 , 0xff } ,
} ;
if ( ! V_6 -> V_228 ) {
static const struct V_243 V_248 [] = {
{ V_220 , 0x00 , 0x04 } ,
{ V_220 , 0x00 , 0x08 } ,
{ V_249 , 0x20 , 0x20 } ,
{ V_59 , 0x00 , 0x08 } ,
{ V_60 , 0x08 , 0x08 } ,
{ V_97 , 0x08 , 0x08 } ,
{ V_250 , 0xd0 , 0xff } ,
{ V_251 , 0x07 , 0xff } ,
{ V_252 , 0xc0 , 0xff } ,
{ V_253 , 0x00 , 0xff } ,
{ V_254 , 0x03 , 0xff } ,
{ V_255 , 0x09 , 0xff } ,
{ V_256 , 0x1c , 0xff } ,
{ V_257 , 0x1e , 0xff } ,
{ V_258 , 0x1e , 0xff } ,
{ V_247 , 0x80 , 0xff } ,
} ;
for ( V_224 = 0 ; V_224 < F_59 ( V_248 ) ; V_224 ++ ) {
V_8 = F_11 ( V_2 , V_248 [ V_224 ] . V_23 ,
V_248 [ V_224 ] . V_24 , V_248 [ V_224 ] . V_32 ) ;
if ( V_8 )
goto V_21;
}
V_6 -> V_228 = true ;
}
V_8 = F_10 ( V_2 , V_245 , & V_13 [ 0 ] ) ;
if ( V_8 )
goto V_21;
if ( V_13 [ 0 ] != 0x83 )
goto exit;
V_8 = F_10 ( V_2 , V_259 , & V_13 [ 0 ] ) ;
if ( V_8 )
goto V_21;
V_25 = V_13 [ 0 ] ;
V_8 = F_8 ( V_2 , V_260 , V_13 , V_25 ) ;
if ( V_8 )
goto V_21;
for ( V_224 = 0 ; V_224 < F_59 ( V_244 ) ; V_224 ++ ) {
V_8 = F_11 ( V_2 , V_244 [ V_224 ] . V_23 ,
V_244 [ V_224 ] . V_24 , V_244 [ V_224 ] . V_32 ) ;
if ( V_8 )
goto V_21;
}
F_66 ( & V_242 ) ;
for ( V_224 = 0 ; V_224 < V_25 ; V_224 ++ ) {
V_242 . V_261 = V_13 [ V_224 ] >> 7 ;
V_242 . V_262 = 50800 * ( V_13 [ V_224 ] & 0x7f ) ;
F_67 ( V_2 -> V_230 , & V_242 ) ;
}
F_68 ( V_2 -> V_230 , true ) ;
F_69 ( V_2 -> V_230 ) ;
exit:
return V_8 ;
V_21:
F_6 ( & V_2 -> V_22 -> V_6 , L_1 , V_8 ) ;
return V_8 ;
}
static int F_70 ( struct V_1 * V_2 ,
struct V_233 * V_234 )
{
if ( V_263 )
return F_9 ( V_2 , V_264 , 0x00 ) ;
if ( ! V_234 -> V_235 )
V_234 -> V_235 = V_236 ;
V_234 -> V_237 = V_265 ;
V_234 -> V_266 = V_267 ;
V_234 -> V_239 = F_65 ;
V_234 -> V_240 = 200 ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 ,
struct V_233 * V_234 )
{
struct V_5 * V_6 = F_18 ( V_2 ) ;
if ( V_6 -> V_104 == V_105 )
return F_64 ( V_2 , V_234 ) ;
else
return F_70 ( V_2 , V_234 ) ;
}
static int F_72 ( struct V_111 * V_35 , int V_214 )
{
struct V_5 * V_6 = F_37 ( V_35 ) ;
if ( V_6 -> V_104 == V_105 ) {
struct V_112 * V_113 = & V_6 -> V_112 ;
return V_113 -> V_268 ( V_35 -> V_127 [ 0 ] , V_214 ) ;
} else {
struct V_145 * V_113 = & V_6 -> V_145 ;
return V_113 -> V_268 ( V_35 -> V_127 [ 0 ] , V_214 ) ;
}
}
static int F_73 ( struct V_111 * V_35 , int V_11 ,
T_2 V_269 , int V_214 )
{
struct V_5 * V_6 = F_37 ( V_35 ) ;
if ( V_6 -> V_104 == V_105 ) {
struct V_112 * V_113 = & V_6 -> V_112 ;
return V_113 -> V_270 ( V_35 -> V_127 [ 0 ] , V_11 , V_269 , V_214 ) ;
} else {
struct V_145 * V_113 = & V_6 -> V_145 ;
return V_113 -> V_270 ( V_35 -> V_127 [ 0 ] , V_11 , V_269 , V_214 ) ;
}
}
