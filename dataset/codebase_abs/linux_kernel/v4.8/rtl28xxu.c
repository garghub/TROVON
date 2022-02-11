static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 ;
unsigned int V_9 ;
T_1 V_10 ;
F_2 ( & V_2 -> V_11 ) ;
if ( V_4 -> V_12 > sizeof( V_6 -> V_13 ) ) {
F_3 ( & V_2 -> V_14 -> V_6 , L_1 , V_4 -> V_12 ) ;
V_8 = - V_15 ;
goto V_16;
}
if ( V_4 -> V_17 & V_18 ) {
memcpy ( V_6 -> V_13 , V_4 -> V_19 , V_4 -> V_12 ) ;
V_10 = ( V_20 | V_21 ) ;
V_9 = F_4 ( V_2 -> V_22 , 0 ) ;
} else {
V_10 = ( V_20 | V_23 ) ;
V_9 = F_5 ( V_2 -> V_22 , 0 ) ;
}
V_8 = F_6 ( V_2 -> V_22 , V_9 , 0 , V_10 , V_4 -> V_24 ,
V_4 -> V_17 , V_6 -> V_13 , V_4 -> V_12 , 1000 ) ;
F_7 ( V_2 -> V_22 , 0 , V_10 , V_4 -> V_24 ,
V_4 -> V_17 , V_6 -> V_13 , V_4 -> V_12 ) ;
if ( V_8 < 0 )
goto V_16;
if ( V_10 == ( V_20 | V_23 ) )
memcpy ( V_4 -> V_19 , V_6 -> V_13 , V_4 -> V_12 ) ;
F_8 ( & V_2 -> V_11 ) ;
return 0 ;
V_16:
F_8 ( & V_2 -> V_11 ) ;
F_9 ( & V_2 -> V_14 -> V_6 , L_2 , V_8 ) ;
return V_8 ;
}
static int F_10 ( struct V_1 * V_2 , T_2 V_25 , T_1 * V_26 , int V_27 )
{
struct V_3 V_4 ;
if ( V_25 < 0x3000 )
V_4 . V_17 = V_28 ;
else if ( V_25 < 0x4000 )
V_4 . V_17 = V_29 ;
else
V_4 . V_17 = V_30 ;
V_4 . V_24 = V_25 ;
V_4 . V_12 = V_27 ;
V_4 . V_19 = V_26 ;
return F_1 ( V_2 , & V_4 ) ;
}
static int F_11 ( struct V_1 * V_2 , T_2 V_25 , T_1 * V_26 , int V_27 )
{
struct V_3 V_4 ;
if ( V_25 < 0x3000 )
V_4 . V_17 = V_31 ;
else if ( V_25 < 0x4000 )
V_4 . V_17 = V_32 ;
else
V_4 . V_17 = V_33 ;
V_4 . V_24 = V_25 ;
V_4 . V_12 = V_27 ;
V_4 . V_19 = V_26 ;
return F_1 ( V_2 , & V_4 ) ;
}
static int F_12 ( struct V_1 * V_2 , T_2 V_25 , T_1 V_26 )
{
return F_10 ( V_2 , V_25 , & V_26 , 1 ) ;
}
static int F_13 ( struct V_1 * V_2 , T_2 V_25 , T_1 * V_26 )
{
return F_11 ( V_2 , V_25 , V_26 , 1 ) ;
}
static int F_14 ( struct V_1 * V_2 , T_2 V_25 , T_1 V_26 ,
T_1 V_34 )
{
int V_8 ;
T_1 V_35 ;
if ( V_34 != 0xff ) {
V_8 = F_13 ( V_2 , V_25 , & V_35 ) ;
if ( V_8 )
return V_8 ;
V_26 &= V_34 ;
V_35 &= ~ V_34 ;
V_26 |= V_35 ;
}
return F_12 ( V_2 , V_25 , V_26 ) ;
}
static int F_15 ( struct V_36 * V_37 , struct V_38 V_39 [] ,
int V_40 )
{
int V_8 ;
struct V_1 * V_2 = F_16 ( V_37 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_3 V_4 ;
if ( F_17 ( & V_2 -> V_41 ) < 0 )
return - V_42 ;
if ( V_40 == 2 && ! ( V_39 [ 0 ] . V_43 & V_44 ) &&
( V_39 [ 1 ] . V_43 & V_44 ) ) {
if ( V_39 [ 0 ] . V_27 > 24 || V_39 [ 1 ] . V_27 > 24 ) {
V_8 = - V_45 ;
goto V_16;
} else if ( V_39 [ 0 ] . V_46 == 0x10 ) {
if ( V_39 [ 0 ] . V_13 [ 0 ] == 0x00 ) {
V_39 [ 1 ] . V_13 [ 0 ] = V_6 -> V_47 ;
V_8 = 0 ;
} else {
V_4 . V_24 = ( V_39 [ 0 ] . V_13 [ 0 ] << 8 ) | ( V_39 [ 0 ] . V_46 << 1 ) ;
V_4 . V_17 = V_48 | V_6 -> V_47 ;
V_4 . V_12 = V_39 [ 1 ] . V_27 ;
V_4 . V_19 = & V_39 [ 1 ] . V_13 [ 0 ] ;
V_8 = F_1 ( V_2 , & V_4 ) ;
}
} else if ( V_39 [ 0 ] . V_27 < 2 ) {
V_4 . V_24 = ( V_39 [ 0 ] . V_13 [ 0 ] << 8 ) | ( V_39 [ 0 ] . V_46 << 1 ) ;
V_4 . V_17 = V_49 ;
V_4 . V_12 = V_39 [ 1 ] . V_27 ;
V_4 . V_19 = & V_39 [ 1 ] . V_13 [ 0 ] ;
V_8 = F_1 ( V_2 , & V_4 ) ;
} else {
V_4 . V_24 = ( V_39 [ 0 ] . V_46 << 1 ) ;
V_4 . V_17 = V_50 ;
V_4 . V_12 = V_39 [ 0 ] . V_27 ;
V_4 . V_19 = V_39 [ 0 ] . V_13 ;
V_8 = F_1 ( V_2 , & V_4 ) ;
if ( V_8 )
goto V_16;
V_4 . V_24 = ( V_39 [ 0 ] . V_46 << 1 ) ;
V_4 . V_17 = V_51 ;
V_4 . V_12 = V_39 [ 1 ] . V_27 ;
V_4 . V_19 = V_39 [ 1 ] . V_13 ;
V_8 = F_1 ( V_2 , & V_4 ) ;
}
} else if ( V_40 == 1 && ! ( V_39 [ 0 ] . V_43 & V_44 ) ) {
if ( V_39 [ 0 ] . V_27 > 22 ) {
V_8 = - V_45 ;
goto V_16;
} else if ( V_39 [ 0 ] . V_46 == 0x10 ) {
if ( V_39 [ 0 ] . V_13 [ 0 ] == 0x00 ) {
V_6 -> V_47 = V_39 [ 0 ] . V_13 [ 1 ] ;
V_8 = 0 ;
} else {
V_4 . V_24 = ( V_39 [ 0 ] . V_13 [ 0 ] << 8 ) |
( V_39 [ 0 ] . V_46 << 1 ) ;
V_4 . V_17 = V_52 | V_6 -> V_47 ;
V_4 . V_12 = V_39 [ 0 ] . V_27 - 1 ;
V_4 . V_19 = & V_39 [ 0 ] . V_13 [ 1 ] ;
V_8 = F_1 ( V_2 , & V_4 ) ;
}
} else if ( ( V_39 [ 0 ] . V_27 < 23 ) && ( ! V_6 -> V_53 ) ) {
V_4 . V_24 = ( V_39 [ 0 ] . V_13 [ 0 ] << 8 ) | ( V_39 [ 0 ] . V_46 << 1 ) ;
V_4 . V_17 = V_54 ;
V_4 . V_12 = V_39 [ 0 ] . V_27 - 1 ;
V_4 . V_19 = & V_39 [ 0 ] . V_13 [ 1 ] ;
V_8 = F_1 ( V_2 , & V_4 ) ;
} else {
V_4 . V_24 = ( V_39 [ 0 ] . V_46 << 1 ) ;
V_4 . V_17 = V_50 ;
V_4 . V_12 = V_39 [ 0 ] . V_27 ;
V_4 . V_19 = V_39 [ 0 ] . V_13 ;
V_8 = F_1 ( V_2 , & V_4 ) ;
}
} else if ( V_40 == 1 && ( V_39 [ 0 ] . V_43 & V_44 ) ) {
V_4 . V_24 = ( V_39 [ 0 ] . V_46 << 1 ) ;
V_4 . V_17 = V_51 ;
V_4 . V_12 = V_39 [ 0 ] . V_27 ;
V_4 . V_19 = V_39 [ 0 ] . V_13 ;
V_8 = F_1 ( V_2 , & V_4 ) ;
} else {
V_8 = - V_45 ;
}
if ( V_8 == - V_55 )
V_8 = - V_42 ;
V_16:
F_8 ( & V_2 -> V_41 ) ;
return V_8 ? V_8 : V_40 ;
}
static T_3 F_18 ( struct V_36 * V_56 )
{
return V_57 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_20 ( V_2 ) ;
int V_8 ;
T_1 V_13 [ 1 ] ;
struct V_3 V_58 = { 0x0120 , 0x0011 , 0x0001 , L_3 } ;
struct V_3 V_59 = { 0x00c0 , V_49 , 1 , V_13 } ;
struct V_3 V_60 = { 0x0fc4 , V_49 , 1 , V_13 } ;
F_9 ( & V_2 -> V_14 -> V_6 , L_4 ) ;
V_8 = F_12 ( V_2 , V_61 , 0x0a ) ;
if ( V_8 )
goto V_62;
V_8 = F_12 ( V_2 , V_63 , 0x15 ) ;
if ( V_8 )
goto V_62;
F_21 ( 20 ) ;
V_6 -> V_64 = L_5 ;
V_8 = F_1 ( V_2 , & V_58 ) ;
if ( V_8 )
goto V_62;
V_8 = F_1 ( V_2 , & V_60 ) ;
if ( V_8 == 0 && V_13 [ 0 ] == 0x2c ) {
V_6 -> V_65 = V_66 ;
V_6 -> V_64 = L_6 ;
goto V_67;
}
V_8 = F_1 ( V_2 , & V_58 ) ;
if ( V_8 )
goto V_62;
V_8 = F_1 ( V_2 , & V_59 ) ;
if ( V_8 == 0 && V_13 [ 0 ] == 0x63 ) {
V_6 -> V_65 = V_68 ;
V_6 -> V_64 = L_7 ;
goto V_67;
}
V_6 -> V_65 = V_69 ;
V_6 -> V_64 = L_8 ;
goto V_67;
V_67:
F_9 ( & V_2 -> V_14 -> V_6 , L_9 , V_6 -> V_64 ) ;
return 0 ;
V_62:
F_9 ( & V_2 -> V_14 -> V_6 , L_2 , V_8 ) ;
return V_8 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_20 ( V_2 ) ;
int V_8 ;
T_1 V_13 [ 2 ] ;
struct V_3 V_58 = { 0x0120 , 0x0011 , 0x0001 , L_10 } ;
struct V_3 V_70 = { 0x0120 , 0x0011 , 0x0001 , L_11 } ;
struct V_3 V_71 = { 0x00c6 , V_49 , 1 , V_13 } ;
struct V_3 V_72 = { 0x00c6 , V_49 , 1 , V_13 } ;
struct V_3 V_73 = { 0x00c0 , V_49 , 1 , V_13 } ;
struct V_3 V_74 = { 0x01ac , V_49 , 1 , V_13 } ;
struct V_3 V_75 = { 0x00c0 , V_49 , 1 , V_13 } ;
struct V_3 V_76 = { 0x00c0 , V_49 , 1 , V_13 } ;
struct V_3 V_77 = { 0x7ec0 , V_49 , 2 , V_13 } ;
struct V_3 V_78 = { 0xd9c0 , V_49 , 1 , V_13 } ;
struct V_3 V_79 = { 0x02c8 , V_49 , 1 , V_13 } ;
struct V_3 V_80 = { 0x00c0 , V_49 , 2 , V_13 } ;
struct V_3 V_81 = { 0x0034 , V_49 , 1 , V_13 } ;
struct V_3 V_82 = { 0x0074 , V_49 , 1 , V_13 } ;
struct V_3 V_83 = { 0xff38 , V_49 , 1 , V_13 } ;
struct V_3 V_84 = { 0xff38 , V_49 , 1 , V_13 } ;
struct V_3 V_85 = { 0x00c0 , V_49 , 1 , V_13 } ;
struct V_3 V_86 = { 0x00c8 , V_49 , 1 , V_13 } ;
F_9 ( & V_2 -> V_14 -> V_6 , L_4 ) ;
V_8 = F_14 ( V_2 , V_61 , 0x00 , 0x40 ) ;
if ( V_8 )
goto V_62;
V_8 = F_14 ( V_2 , V_63 , 0x48 , 0x48 ) ;
if ( V_8 )
goto V_62;
V_8 = F_1 ( V_2 , & V_58 ) ;
if ( V_8 )
goto V_62;
V_6 -> V_64 = L_5 ;
V_8 = F_1 ( V_2 , & V_71 ) ;
if ( V_8 == 0 && V_13 [ 0 ] == 0xa1 ) {
V_6 -> V_65 = V_87 ;
V_6 -> V_64 = L_12 ;
goto V_88;
}
V_8 = F_1 ( V_2 , & V_72 ) ;
if ( V_8 == 0 && V_13 [ 0 ] == 0xa3 ) {
V_6 -> V_65 = V_89 ;
V_6 -> V_64 = L_13 ;
goto V_88;
}
V_8 = F_1 ( V_2 , & V_73 ) ;
if ( V_8 == 0 && V_13 [ 0 ] == 0x85 ) {
V_6 -> V_65 = V_90 ;
V_6 -> V_64 = L_14 ;
goto V_88;
}
V_8 = F_1 ( V_2 , & V_74 ) ;
if ( V_8 == 0 && V_13 [ 0 ] == 0x56 ) {
V_6 -> V_65 = V_91 ;
V_6 -> V_64 = L_15 ;
goto V_88;
}
V_8 = F_1 ( V_2 , & V_75 ) ;
if ( V_8 == 0 && ( V_13 [ 0 ] == 0x9e || V_13 [ 0 ] == 0x9c ) ) {
V_6 -> V_65 = V_92 ;
V_6 -> V_64 = L_16 ;
goto V_88;
}
V_8 = F_1 ( V_2 , & V_76 ) ;
if ( V_8 == 0 && V_13 [ 0 ] == 0x38 ) {
V_6 -> V_65 = V_93 ;
V_6 -> V_64 = L_17 ;
goto V_88;
}
V_8 = F_1 ( V_2 , & V_77 ) ;
if ( V_8 == 0 && V_13 [ 0 ] == 0x23 && V_13 [ 1 ] == 0x28 ) {
V_6 -> V_65 = V_94 ;
V_6 -> V_64 = L_18 ;
goto V_88;
}
V_8 = F_1 ( V_2 , & V_78 ) ;
if ( V_8 == 0 && V_13 [ 0 ] == 0x14 ) {
V_6 -> V_65 = V_95 ;
V_6 -> V_64 = L_19 ;
goto V_88;
}
V_8 = F_1 ( V_2 , & V_79 ) ;
if ( V_8 == 0 && V_13 [ 0 ] == 0x40 ) {
V_6 -> V_65 = V_96 ;
V_6 -> V_64 = L_20 ;
goto V_88;
}
V_8 = F_1 ( V_2 , & V_80 ) ;
if ( V_8 == 0 && ( V_13 [ 0 ] == 0xc7 || V_13 [ 1 ] == 0x60 ) ) {
V_6 -> V_65 = V_97 ;
V_6 -> V_64 = L_21 ;
goto V_88;
}
V_8 = F_1 ( V_2 , & V_81 ) ;
if ( V_8 == 0 && V_13 [ 0 ] == 0x69 ) {
V_6 -> V_65 = V_98 ;
V_6 -> V_64 = L_22 ;
goto V_88;
}
V_8 = F_1 ( V_2 , & V_82 ) ;
if ( V_8 == 0 && V_13 [ 0 ] == 0x69 ) {
V_6 -> V_65 = V_99 ;
V_6 -> V_64 = L_23 ;
goto V_88;
}
V_8 = F_14 ( V_2 , V_100 , 0x00 , 0x21 ) ;
if ( V_8 )
goto V_62;
V_8 = F_14 ( V_2 , V_63 , 0x00 , 0x21 ) ;
if ( V_8 )
goto V_62;
F_21 ( 50 ) ;
V_8 = F_14 ( V_2 , V_100 , 0x21 , 0x21 ) ;
if ( V_8 )
goto V_62;
V_8 = F_14 ( V_2 , V_63 , 0x21 , 0x21 ) ;
if ( V_8 )
goto V_62;
F_21 ( 50 ) ;
V_8 = F_1 ( V_2 , & V_85 ) ;
if ( V_8 == 0 && ( ( V_13 [ 0 ] & 0x80 ) == 0x80 ) ) {
V_6 -> V_65 = V_101 ;
V_6 -> V_64 = L_24 ;
goto V_88;
}
V_88:
F_9 ( & V_2 -> V_14 -> V_6 , L_9 , V_6 -> V_64 ) ;
if ( V_6 -> V_65 == V_99 ) {
V_8 = F_14 ( V_2 , V_100 , 0x01 , 0x01 ) ;
if ( V_8 )
goto V_62;
V_8 = F_14 ( V_2 , V_61 , 0x00 , 0x01 ) ;
if ( V_8 )
goto V_62;
V_8 = F_14 ( V_2 , V_63 , 0x01 , 0x01 ) ;
if ( V_8 )
goto V_62;
V_8 = F_1 ( V_2 , & V_83 ) ;
if ( V_8 == 0 && V_13 [ 0 ] == 0x02 ) {
F_9 ( & V_2 -> V_14 -> V_6 , L_25 ) ;
V_6 -> V_102 = V_103 ;
goto V_104;
}
V_8 = F_1 ( V_2 , & V_84 ) ;
if ( V_8 == 0 && V_13 [ 0 ] == 0x03 ) {
F_9 ( & V_2 -> V_14 -> V_6 , L_26 ) ;
V_6 -> V_102 = V_105 ;
goto V_104;
}
}
if ( V_6 -> V_65 == V_101 ) {
V_8 = F_1 ( V_2 , & V_86 ) ;
if ( V_8 == 0 && ( ( V_13 [ 0 ] & 0x80 ) == 0x80 ) ) {
F_9 ( & V_2 -> V_14 -> V_6 , L_27 ) ;
V_6 -> V_102 = V_106 ;
goto V_104;
}
}
V_104:
V_8 = F_1 ( V_2 , & V_70 ) ;
if ( V_8 < 0 )
goto V_62;
return 0 ;
V_62:
F_9 ( & V_2 -> V_14 -> V_6 , L_2 , V_8 ) ;
return V_8 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_20 ( V_2 ) ;
if ( V_6 -> V_107 == V_108 )
return F_19 ( V_2 ) ;
else
return F_22 ( V_2 ) ;
}
static int F_24 ( struct V_1 * V_2 , const char * * V_109 )
{
struct V_5 * V_6 = F_20 ( V_2 ) ;
int V_8 ;
struct V_3 V_110 = { 0x0020 , V_51 , 0 , NULL } ;
F_9 ( & V_2 -> V_14 -> V_6 , L_4 ) ;
V_8 = F_1 ( V_2 , & V_110 ) ;
if ( V_8 == - V_55 ) {
V_6 -> V_107 = V_108 ;
} else if ( V_8 == 0 ) {
V_6 -> V_107 = V_111 ;
} else {
F_3 ( & V_2 -> V_14 -> V_6 , L_28 , V_8 ) ;
goto V_62;
}
F_9 ( & V_2 -> V_14 -> V_6 , L_29 , V_6 -> V_107 ) ;
V_2 -> V_112 . V_113 = 3 ;
V_2 -> V_112 . V_114 = F_25 ( 10 ) ;
return V_115 ;
V_62:
F_9 ( & V_2 -> V_14 -> V_6 , L_2 , V_8 ) ;
return V_8 ;
}
static int F_26 ( struct V_116 * V_37 )
{
struct V_1 * V_2 = F_27 ( V_37 ) ;
struct V_5 * V_6 = F_20 ( V_2 ) ;
struct V_117 * V_118 = & V_6 -> V_117 ;
struct V_119 V_120 ;
struct V_121 * V_122 ;
int V_8 ;
F_9 ( & V_2 -> V_14 -> V_6 , L_4 ) ;
switch ( V_6 -> V_65 ) {
case V_66 :
* V_118 = V_123 ;
break;
case V_68 :
* V_118 = V_124 ;
break;
case V_69 :
* V_118 = V_125 ;
break;
default:
F_3 ( & V_2 -> V_14 -> V_6 , L_30 , V_6 -> V_64 ) ;
V_8 = - V_126 ;
goto V_62;
}
memset ( & V_120 , 0 , sizeof( V_120 ) ) ;
F_28 ( V_120 . type , L_31 , V_127 ) ;
V_120 . V_46 = 0x10 ;
V_120 . V_128 = V_118 ;
F_29 ( L_32 , V_120 . type ) ;
V_122 = F_30 ( & V_2 -> V_112 , & V_120 ) ;
if ( V_122 == NULL || V_122 -> V_6 . V_129 == NULL ) {
V_8 = - V_126 ;
goto V_62;
}
if ( ! F_31 ( V_122 -> V_6 . V_129 -> V_130 ) ) {
F_32 ( V_122 ) ;
V_8 = - V_126 ;
goto V_62;
}
V_37 -> V_131 [ 0 ] = V_118 -> V_132 ( V_122 ) ;
V_6 -> V_133 = V_118 -> V_134 ( V_122 ) ;
V_6 -> V_135 = V_122 ;
return 0 ;
V_62:
F_9 ( & V_2 -> V_14 -> V_6 , L_2 , V_8 ) ;
return V_8 ;
}
static int F_33 ( struct V_1 * V_2 ,
int V_136 , int V_137 )
{
int V_8 ;
T_1 V_26 ;
F_9 ( & V_2 -> V_14 -> V_6 , L_33 , V_136 , V_137 ) ;
switch ( V_136 ) {
case V_138 :
V_8 = F_13 ( V_2 , V_100 , & V_26 ) ;
if ( V_8 )
goto V_62;
if ( V_137 )
V_26 &= 0xbf ;
else
V_26 |= 0x40 ;
V_8 = F_12 ( V_2 , V_100 , V_26 ) ;
if ( V_8 )
goto V_62;
break;
default:
V_8 = - V_15 ;
goto V_62;
}
return 0 ;
V_62:
F_9 ( & V_2 -> V_14 -> V_6 , L_2 , V_8 ) ;
return V_8 ;
}
static int F_34 ( struct V_1 * V_2 ,
int V_136 , int V_137 )
{
int V_8 ;
T_1 V_26 ;
F_9 ( & V_2 -> V_14 -> V_6 , L_33 , V_136 , V_137 ) ;
switch ( V_136 ) {
case V_139 :
if ( V_137 )
V_26 = ( 1 << 4 ) ;
else
V_26 = ( 0 << 4 ) ;
V_8 = F_14 ( V_2 , V_100 , V_26 , 0x10 ) ;
if ( V_8 )
goto V_62;
break;
case V_140 :
if ( V_137 )
V_26 = ( 1 << 1 ) ;
else
V_26 = ( 0 << 1 ) ;
V_8 = F_14 ( V_2 , V_100 , V_26 , 0x02 ) ;
if ( V_8 )
goto V_62;
break;
}
return 0 ;
V_62:
F_9 ( & V_2 -> V_14 -> V_6 , L_2 , V_8 ) ;
return V_8 ;
}
static int F_35 ( void * V_141 , int V_142 ,
int V_136 , int V_137 )
{
struct V_36 * V_56 = V_141 ;
struct V_143 * V_144 = V_56 -> V_6 . V_144 ;
struct V_36 * V_145 ;
struct V_1 * V_2 ;
struct V_5 * V_6 ;
if ( V_144 != NULL && V_144 -> type == & V_146 )
V_145 = F_36 ( V_144 ) ;
else
return - V_15 ;
V_2 = F_16 ( V_145 ) ;
V_6 = V_2 -> V_7 ;
F_9 ( & V_2 -> V_14 -> V_6 , L_34 ,
V_142 , V_136 , V_137 ) ;
switch ( V_142 ) {
case V_147 :
switch ( V_6 -> V_65 ) {
case V_87 :
return F_33 ( V_2 , V_136 , V_137 ) ;
case V_94 :
return F_34 ( V_2 , V_136 , V_137 ) ;
}
}
return 0 ;
}
static int F_37 ( struct V_116 * V_37 )
{
struct V_1 * V_2 = F_27 ( V_37 ) ;
struct V_5 * V_6 = F_20 ( V_2 ) ;
struct V_148 * V_118 = & V_6 -> V_148 ;
struct V_119 V_120 ;
struct V_121 * V_122 ;
int V_8 ;
F_9 ( & V_2 -> V_14 -> V_6 , L_4 ) ;
switch ( V_6 -> V_65 ) {
case V_87 :
* V_118 = V_149 ;
break;
case V_89 :
* V_118 = V_150 ;
break;
case V_91 :
* V_118 = V_151 ;
break;
case V_94 :
* V_118 = V_152 ;
break;
case V_96 :
* V_118 = V_153 ;
break;
case V_98 :
case V_99 :
* V_118 = V_154 ;
break;
case V_101 :
* V_118 = V_155 ;
break;
default:
F_3 ( & V_2 -> V_14 -> V_6 , L_30 , V_6 -> V_64 ) ;
V_8 = - V_126 ;
goto V_62;
}
memset ( & V_120 , 0 , sizeof( V_120 ) ) ;
F_28 ( V_120 . type , L_35 , V_127 ) ;
V_120 . V_46 = 0x10 ;
V_120 . V_128 = V_118 ;
F_29 ( L_32 , V_120 . type ) ;
V_122 = F_30 ( & V_2 -> V_112 , & V_120 ) ;
if ( V_122 == NULL || V_122 -> V_6 . V_129 == NULL ) {
V_8 = - V_126 ;
goto V_62;
}
if ( ! F_31 ( V_122 -> V_6 . V_129 -> V_130 ) ) {
F_32 ( V_122 ) ;
V_8 = - V_126 ;
goto V_62;
}
V_37 -> V_131 [ 0 ] = V_118 -> V_132 ( V_122 ) ;
V_6 -> V_133 = V_118 -> V_134 ( V_122 ) ;
V_6 -> V_135 = V_122 ;
V_37 -> V_131 [ 0 ] -> V_156 = F_35 ;
if ( V_6 -> V_102 ) {
struct V_119 V_157 = {} ;
V_8 = 0 ;
if ( V_6 -> V_102 == V_103 ) {
struct V_158 V_158 = {} ;
V_158 . V_131 = & V_37 -> V_131 [ 1 ] ;
V_158 . V_159 = 22 ,
F_28 ( V_157 . type , L_36 , V_127 ) ;
V_158 . V_160 = 20500000 ;
V_158 . V_161 = V_162 ;
V_158 . V_163 = V_164 ;
V_157 . V_46 = 0x18 ;
V_157 . V_128 = & V_158 ;
F_29 ( V_157 . type ) ;
V_122 = F_30 ( & V_2 -> V_112 , & V_157 ) ;
if ( V_122 == NULL || V_122 -> V_6 . V_129 == NULL ) {
V_6 -> V_102 = V_165 ;
goto V_166;
}
if ( ! F_31 ( V_122 -> V_6 . V_129 -> V_130 ) ) {
F_32 ( V_122 ) ;
V_6 -> V_102 = V_165 ;
goto V_166;
}
V_6 -> V_167 = V_122 ;
} else if ( V_6 -> V_102 == V_105 ) {
struct V_168 V_168 = {} ;
V_168 . V_131 = & V_37 -> V_131 [ 1 ] ;
V_168 . V_159 = 22 ,
F_28 ( V_157 . type , L_37 , V_127 ) ;
V_157 . V_46 = 0x18 ;
V_157 . V_128 = & V_168 ;
F_29 ( V_157 . type ) ;
V_122 = F_30 ( & V_2 -> V_112 , & V_157 ) ;
if ( V_122 == NULL || V_122 -> V_6 . V_129 == NULL ) {
V_6 -> V_102 = V_165 ;
goto V_166;
}
if ( ! F_31 ( V_122 -> V_6 . V_129 -> V_130 ) ) {
F_32 ( V_122 ) ;
V_6 -> V_102 = V_165 ;
goto V_166;
}
V_6 -> V_167 = V_122 ;
} else {
struct V_169 V_169 = {} ;
struct V_36 * V_56 ;
V_169 . V_36 = & V_56 ;
V_169 . V_131 = & V_37 -> V_131 [ 1 ] ;
V_169 . V_161 = V_170 ;
V_169 . V_171 = false ;
V_169 . V_172 = true ;
F_28 ( V_157 . type , L_38 , V_127 ) ;
V_157 . V_46 = 0x64 ;
V_157 . V_128 = & V_169 ;
F_29 ( V_157 . type ) ;
V_122 = F_30 ( & V_2 -> V_112 , & V_157 ) ;
if ( V_122 == NULL || V_122 -> V_6 . V_129 == NULL ) {
V_6 -> V_102 = V_165 ;
goto V_166;
}
if ( ! F_31 ( V_122 -> V_6 . V_129 -> V_130 ) ) {
F_32 ( V_122 ) ;
V_6 -> V_102 = V_165 ;
goto V_166;
}
V_6 -> V_167 = V_122 ;
V_6 -> V_53 = true ;
}
}
return 0 ;
V_166:
V_62:
F_9 ( & V_2 -> V_14 -> V_6 , L_2 , V_8 ) ;
return V_8 ;
}
static int F_38 ( struct V_116 * V_37 )
{
struct V_5 * V_6 = F_39 ( V_37 ) ;
if ( V_6 -> V_107 == V_108 )
return F_26 ( V_37 ) ;
else
return F_37 ( V_37 ) ;
}
static int F_40 ( struct V_116 * V_37 )
{
struct V_1 * V_2 = F_27 ( V_37 ) ;
struct V_5 * V_6 = F_20 ( V_2 ) ;
struct V_121 * V_122 ;
F_9 ( & V_2 -> V_14 -> V_6 , L_4 ) ;
V_122 = V_6 -> V_167 ;
if ( V_122 ) {
F_41 ( V_122 -> V_6 . V_129 -> V_130 ) ;
F_32 ( V_122 ) ;
}
V_122 = V_6 -> V_135 ;
if ( V_122 ) {
F_41 ( V_122 -> V_6 . V_129 -> V_130 ) ;
F_32 ( V_122 ) ;
}
return 0 ;
}
static int F_42 ( struct V_116 * V_37 )
{
int V_8 ;
struct V_1 * V_2 = F_27 ( V_37 ) ;
struct V_5 * V_6 = F_20 ( V_2 ) ;
struct V_173 * V_131 ;
F_9 ( & V_2 -> V_14 -> V_6 , L_4 ) ;
switch ( V_6 -> V_65 ) {
case V_66 :
V_131 = F_43 ( V_174 , V_37 -> V_131 [ 0 ] ,
V_6 -> V_133 ,
& V_175 ) ;
break;
case V_68 :
V_131 = F_43 ( V_176 , V_37 -> V_131 [ 0 ] ,
V_6 -> V_133 ,
& V_177 , 1220 ) ;
break;
case V_69 :
V_131 = F_43 ( V_178 , V_37 -> V_131 [ 0 ] ,
V_6 -> V_133 ,
& V_179 ) ;
break;
default:
V_131 = NULL ;
F_3 ( & V_2 -> V_14 -> V_6 , L_39 , V_6 -> V_65 ) ;
}
if ( V_131 == NULL ) {
V_8 = - V_126 ;
goto V_62;
}
return 0 ;
V_62:
F_9 ( & V_2 -> V_14 -> V_6 , L_2 , V_8 ) ;
return V_8 ;
}
static int F_44 ( struct V_116 * V_37 )
{
int V_8 ;
struct V_1 * V_2 = F_27 ( V_37 ) ;
struct V_5 * V_6 = F_20 ( V_2 ) ;
struct V_173 * V_131 = NULL ;
struct V_119 V_157 ;
struct V_121 * V_122 ;
struct V_180 * V_181 = NULL ;
struct V_182 * V_183 ;
struct V_184 V_118 ;
F_9 ( & V_2 -> V_14 -> V_6 , L_4 ) ;
memset ( & V_157 , 0 , sizeof( struct V_119 ) ) ;
memset ( & V_118 , 0 , sizeof( V_118 ) ) ;
switch ( V_6 -> V_65 ) {
case V_87 :
V_131 = F_43 ( V_185 , V_37 -> V_131 [ 0 ] ,
V_6 -> V_133 , & V_186 ) ;
V_37 -> V_131 [ 0 ] -> V_187 . V_188 =
V_37 -> V_131 [ 0 ] -> V_187 . V_189 . V_190 ;
break;
case V_89 :
V_131 = F_43 ( V_191 , V_37 -> V_131 [ 0 ] ,
V_6 -> V_133 , 0xc6 >> 1 , 0 , V_192 ) ;
V_37 -> V_131 [ 0 ] -> V_187 . V_188 =
V_37 -> V_131 [ 0 ] -> V_187 . V_189 . V_190 ;
break;
case V_96 : {
struct V_193 V_193 = {
. V_131 = V_37 -> V_131 [ 0 ] ,
. clock = 28800000 ,
} ;
F_28 ( V_157 . type , L_40 , V_127 ) ;
V_157 . V_46 = 0x64 ;
V_157 . V_128 = & V_193 ;
F_29 ( V_157 . type ) ;
V_122 = F_30 ( V_6 -> V_133 , & V_157 ) ;
if ( V_122 == NULL || V_122 -> V_6 . V_129 == NULL )
break;
if ( ! F_31 ( V_122 -> V_6 . V_129 -> V_130 ) ) {
F_32 ( V_122 ) ;
break;
}
V_6 -> V_194 = V_122 ;
V_181 = F_45 ( V_122 ) ;
}
break;
case V_91 : {
struct V_195 V_196 = {
. V_173 = V_37 -> V_131 [ 0 ] ,
} ;
struct V_119 V_120 = {} ;
F_28 ( V_120 . type , L_41 , V_127 ) ;
V_120 . V_46 = 0x56 ;
V_120 . V_128 = & V_196 ;
F_29 ( L_41 ) ;
V_122 = F_30 ( V_6 -> V_133 ,
& V_120 ) ;
if ( V_122 == NULL || V_122 -> V_6 . V_129 == NULL )
break;
if ( ! F_31 ( V_122 -> V_6 . V_129 -> V_130 ) ) {
F_32 ( V_122 ) ;
break;
}
V_6 -> V_194 = V_122 ;
V_181 = V_196 . V_197 ( V_122 ) ;
}
break;
case V_94 : {
struct V_198 V_199 = {
. V_173 = V_37 -> V_131 [ 0 ] ,
} ;
struct V_119 V_120 = {} ;
V_8 = F_14 ( V_2 , V_61 , 0x00 , 0x12 ) ;
if ( V_8 )
goto V_62;
V_8 = F_14 ( V_2 , V_63 , 0x12 , 0x12 ) ;
if ( V_8 )
goto V_62;
F_28 ( V_120 . type , L_42 , V_127 ) ;
V_120 . V_46 = 0x60 ;
V_120 . V_128 = & V_199 ;
F_29 ( L_42 ) ;
V_122 = F_30 ( V_6 -> V_133 , & V_120 ) ;
if ( V_122 == NULL || V_122 -> V_6 . V_129 == NULL )
break;
if ( ! F_31 ( V_122 -> V_6 . V_129 -> V_130 ) ) {
F_32 ( V_122 ) ;
break;
}
V_6 -> V_194 = V_122 ;
break;
}
case V_98 :
V_131 = F_43 ( V_200 , V_37 -> V_131 [ 0 ] ,
V_6 -> V_133 ,
& V_201 ) ;
V_37 -> V_131 [ 0 ] -> V_187 . V_188 =
V_37 -> V_131 [ 0 ] -> V_187 . V_189 . V_190 ;
break;
case V_99 :
V_131 = F_43 ( V_200 , V_37 -> V_131 [ 0 ] ,
V_6 -> V_133 ,
& V_202 ) ;
V_37 -> V_131 [ 0 ] -> V_187 . V_188 =
V_37 -> V_131 [ 0 ] -> V_187 . V_189 . V_190 ;
if ( V_37 -> V_131 [ 1 ] ) {
V_131 = F_43 ( V_200 , V_37 -> V_131 [ 1 ] ,
V_6 -> V_133 ,
& V_202 ) ;
V_37 -> V_131 [ 1 ] -> V_187 . V_188 =
V_37 -> V_131 [ 1 ] -> V_187 . V_189 . V_190 ;
}
break;
case V_101 : {
struct V_203 V_203 = {
. V_131 = V_37 -> V_131 [ 0 ] ,
. V_204 = 0 ,
. V_205 = false ,
} ;
F_28 ( V_157 . type , L_43 , V_127 ) ;
V_157 . V_46 = 0x60 ;
V_157 . V_128 = & V_203 ;
F_29 ( V_157 . type ) ;
V_122 = F_30 ( & V_2 -> V_112 , & V_157 ) ;
if ( V_122 == NULL || V_122 -> V_6 . V_129 == NULL )
break;
if ( ! F_31 ( V_122 -> V_6 . V_129 -> V_130 ) ) {
F_32 ( V_122 ) ;
break;
}
V_6 -> V_194 = V_122 ;
V_181 = F_45 ( V_122 ) ;
if ( V_37 -> V_131 [ 1 ] ) {
V_37 -> V_131 [ 1 ] -> V_206 =
V_37 -> V_131 [ 0 ] -> V_206 ;
memcpy ( & V_37 -> V_131 [ 1 ] -> V_187 . V_189 ,
& V_37 -> V_131 [ 0 ] -> V_187 . V_189 ,
sizeof( struct V_207 ) ) ;
}
}
break;
default:
F_3 ( & V_2 -> V_14 -> V_6 , L_39 , V_6 -> V_65 ) ;
}
if ( V_131 == NULL && V_6 -> V_194 == NULL ) {
V_8 = - V_126 ;
goto V_62;
}
switch ( V_6 -> V_65 ) {
case V_91 :
case V_87 :
case V_89 :
case V_96 :
case V_98 :
case V_99 :
V_118 . V_208 = V_6 -> V_148 . V_208 ;
V_118 . V_65 = V_6 -> V_65 ;
V_118 . V_209 = V_6 -> V_148 . V_209 ;
V_118 . V_173 = V_37 -> V_131 [ 0 ] ;
V_118 . V_1 = V_2 ;
V_118 . V_180 = V_181 ;
F_29 ( L_32 , L_44 ) ;
V_183 = F_46 ( & V_2 -> V_14 -> V_6 ,
L_44 ,
V_210 ,
& V_118 , sizeof( V_118 ) ) ;
if ( F_47 ( V_183 ) || V_183 -> V_6 . V_129 == NULL )
break;
V_6 -> V_211 = V_183 ;
break;
default:
F_9 ( & V_2 -> V_14 -> V_6 , L_45 , V_6 -> V_65 ) ;
}
return 0 ;
V_62:
F_9 ( & V_2 -> V_14 -> V_6 , L_2 , V_8 ) ;
return V_8 ;
}
static int F_48 ( struct V_116 * V_37 )
{
struct V_5 * V_6 = F_39 ( V_37 ) ;
if ( V_6 -> V_107 == V_108 )
return F_42 ( V_37 ) ;
else
return F_44 ( V_37 ) ;
}
static int F_49 ( struct V_116 * V_37 )
{
struct V_1 * V_2 = F_27 ( V_37 ) ;
struct V_5 * V_6 = F_20 ( V_2 ) ;
struct V_121 * V_122 ;
struct V_182 * V_183 ;
F_9 ( & V_2 -> V_14 -> V_6 , L_4 ) ;
V_183 = V_6 -> V_211 ;
if ( V_183 )
F_50 ( V_183 ) ;
V_122 = V_6 -> V_194 ;
if ( V_122 ) {
F_41 ( V_122 -> V_6 . V_129 -> V_130 ) ;
F_32 ( V_122 ) ;
}
return 0 ;
}
static int F_51 ( struct V_1 * V_2 )
{
int V_8 ;
T_1 V_26 ;
F_9 ( & V_2 -> V_14 -> V_6 , L_4 ) ;
V_8 = F_13 ( V_2 , V_212 , & V_26 ) ;
if ( V_8 )
goto V_62;
V_26 |= 0x09 ;
V_8 = F_12 ( V_2 , V_212 , V_26 ) ;
if ( V_8 )
goto V_62;
V_8 = F_10 ( V_2 , V_213 , L_46 , 4 ) ;
if ( V_8 )
goto V_62;
V_8 = F_10 ( V_2 , V_214 , L_47 , 4 ) ;
if ( V_8 )
goto V_62;
return V_8 ;
V_62:
F_9 ( & V_2 -> V_14 -> V_6 , L_2 , V_8 ) ;
return V_8 ;
}
static int F_52 ( struct V_1 * V_2 , int V_215 )
{
int V_8 ;
T_1 V_216 , V_217 , V_218 [ 2 ] ;
F_9 ( & V_2 -> V_14 -> V_6 , L_48 , V_215 ) ;
V_8 = F_13 ( V_2 , V_219 , & V_217 ) ;
if ( V_8 )
goto V_62;
V_8 = F_13 ( V_2 , V_100 , & V_216 ) ;
if ( V_8 )
goto V_62;
F_9 ( & V_2 -> V_14 -> V_6 , L_49 , V_217 , V_216 ) ;
if ( V_215 ) {
V_216 |= 0x01 ;
V_216 &= ( ~ 0x10 ) ;
V_216 |= 0x04 ;
V_217 = V_217 & 0x0f ;
V_217 |= 0xe0 ;
V_218 [ 0 ] = 0x00 ;
V_218 [ 1 ] = 0x00 ;
} else {
V_216 &= ( ~ 0x01 ) ;
V_216 |= 0x10 ;
V_216 &= ( ~ 0x04 ) ;
V_217 = V_217 & ( ~ 0xc0 ) ;
V_218 [ 0 ] = 0x10 ;
V_218 [ 1 ] = 0x02 ;
}
F_9 ( & V_2 -> V_14 -> V_6 , L_50 , V_217 , V_216 ) ;
V_8 = F_12 ( V_2 , V_219 , V_217 ) ;
if ( V_8 )
goto V_62;
V_8 = F_12 ( V_2 , V_100 , V_216 ) ;
if ( V_8 )
goto V_62;
V_8 = F_10 ( V_2 , V_220 , V_218 , 2 ) ;
if ( V_8 )
goto V_62;
if ( V_215 )
F_53 ( V_2 -> V_22 , F_54 ( V_2 -> V_22 , 0x81 ) ) ;
return V_8 ;
V_62:
F_9 ( & V_2 -> V_14 -> V_6 , L_2 , V_8 ) ;
return V_8 ;
}
static int F_55 ( struct V_1 * V_2 , int V_215 )
{
int V_8 ;
F_9 ( & V_2 -> V_14 -> V_6 , L_48 , V_215 ) ;
if ( V_215 ) {
V_8 = F_14 ( V_2 , V_100 , 0x08 , 0x18 ) ;
if ( V_8 )
goto V_62;
V_8 = F_14 ( V_2 , V_221 , 0x00 , 0x10 ) ;
if ( V_8 )
goto V_62;
V_8 = F_14 ( V_2 , V_222 , 0x80 , 0x80 ) ;
if ( V_8 )
goto V_62;
V_8 = F_14 ( V_2 , V_222 , 0x20 , 0x20 ) ;
if ( V_8 )
goto V_62;
V_8 = F_10 ( V_2 , V_220 , L_51 , 2 ) ;
if ( V_8 )
goto V_62;
V_8 = F_53 ( V_2 -> V_22 , F_54 ( V_2 -> V_22 , 0x81 ) ) ;
if ( V_8 )
goto V_62;
} else {
V_8 = F_14 ( V_2 , V_100 , 0x10 , 0x10 ) ;
if ( V_8 )
goto V_62;
V_8 = F_14 ( V_2 , V_222 , 0x00 , 0x80 ) ;
if ( V_8 )
goto V_62;
V_8 = F_10 ( V_2 , V_220 , L_52 , 2 ) ;
if ( V_8 )
goto V_62;
}
return V_8 ;
V_62:
F_9 ( & V_2 -> V_14 -> V_6 , L_2 , V_8 ) ;
return V_8 ;
}
static int F_56 ( struct V_1 * V_2 , int V_215 )
{
struct V_5 * V_6 = F_20 ( V_2 ) ;
if ( V_6 -> V_107 == V_108 )
return F_52 ( V_2 , V_215 ) ;
else
return F_55 ( V_2 , V_215 ) ;
}
static int F_57 ( struct V_173 * V_131 , int V_215 )
{
struct V_1 * V_2 = F_58 ( V_131 ) ;
struct V_5 * V_6 = F_59 ( V_131 ) ;
struct V_148 * V_118 = & V_6 -> V_148 ;
int V_8 ;
T_1 V_26 ;
F_9 ( & V_2 -> V_14 -> V_6 , L_53 , V_131 -> V_223 , V_215 ) ;
if ( V_6 -> V_107 == V_108 )
return 0 ;
if ( V_131 -> V_223 == 0 ) {
if ( V_215 )
V_26 = 0x48 ;
else
V_26 = 0x00 ;
V_8 = F_14 ( V_2 , V_222 , V_26 , 0x48 ) ;
if ( V_8 )
goto V_62;
} else if ( V_131 -> V_223 == 1 ) {
V_8 = V_118 -> V_224 ( V_6 -> V_135 , V_215 ) ;
if ( V_8 )
goto V_62;
}
return 0 ;
V_62:
F_9 ( & V_2 -> V_14 -> V_6 , L_2 , V_8 ) ;
return V_8 ;
}
static int F_60 ( struct V_1 * V_2 )
{
int V_8 , V_225 ;
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_13 [ 5 ] ;
T_3 V_226 ;
struct V_227 V_228 [] = {
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
if ( ! V_6 -> V_229 ) {
for ( V_225 = 0 ; V_225 < F_61 ( V_228 ) ; V_225 ++ ) {
V_8 = F_12 ( V_2 , V_228 [ V_225 ] . V_25 ,
V_228 [ V_225 ] . V_26 ) ;
if ( V_8 )
goto V_62;
}
V_6 -> V_229 = true ;
}
V_8 = F_11 ( V_2 , V_230 , V_13 , 5 ) ;
if ( V_8 )
goto V_62;
if ( V_13 [ 4 ] & 0x01 ) {
if ( V_13 [ 2 ] == ( T_1 ) ~ V_13 [ 3 ] ) {
if ( V_13 [ 0 ] == ( T_1 ) ~ V_13 [ 1 ] ) {
V_226 = F_62 ( V_13 [ 0 ] , V_13 [ 2 ] ) ;
} else {
V_226 = F_63 ( V_13 [ 0 ] << 8 | V_13 [ 1 ] ,
V_13 [ 2 ] ) ;
}
} else {
V_226 = F_64 ( V_13 [ 0 ] << 24 | V_13 [ 1 ] << 16 |
V_13 [ 2 ] << 8 | V_13 [ 3 ] ) ;
}
F_65 ( V_2 -> V_231 , V_232 , V_226 , 0 ) ;
V_8 = F_12 ( V_2 , V_233 , 1 ) ;
if ( V_8 )
goto V_62;
V_8 = F_12 ( V_2 , V_233 , 1 ) ;
if ( V_8 )
goto V_62;
}
return V_8 ;
V_62:
F_9 ( & V_2 -> V_14 -> V_6 , L_2 , V_8 ) ;
return V_8 ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_234 * V_235 )
{
V_235 -> V_236 = V_237 ;
V_235 -> V_238 = V_239 ;
V_235 -> V_240 = F_60 ;
V_235 -> V_241 = 400 ;
return 0 ;
}
static int F_67 ( struct V_1 * V_2 )
{
int V_8 , V_225 , V_27 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_242 V_243 ;
T_1 V_13 [ 128 ] ;
static const struct V_244 V_245 [] = {
{ V_246 , 0x03 , 0xff } ,
{ V_247 , 0x80 , 0xff } ,
{ V_248 , 0x80 , 0xff } ,
} ;
if ( ! V_6 -> V_229 ) {
static const struct V_244 V_249 [] = {
{ V_221 , 0x00 , 0x04 } ,
{ V_221 , 0x00 , 0x08 } ,
{ V_250 , 0x20 , 0x20 } ,
{ V_61 , 0x00 , 0x08 } ,
{ V_63 , 0x08 , 0x08 } ,
{ V_100 , 0x08 , 0x08 } ,
{ V_251 , 0xd0 , 0xff } ,
{ V_252 , 0x07 , 0xff } ,
{ V_253 , 0xc0 , 0xff } ,
{ V_254 , 0x00 , 0xff } ,
{ V_255 , 0x03 , 0xff } ,
{ V_256 , 0x09 , 0xff } ,
{ V_257 , 0x1c , 0xff } ,
{ V_258 , 0x1e , 0xff } ,
{ V_259 , 0x1e , 0xff } ,
{ V_248 , 0x80 , 0xff } ,
} ;
for ( V_225 = 0 ; V_225 < F_61 ( V_249 ) ; V_225 ++ ) {
V_8 = F_14 ( V_2 , V_249 [ V_225 ] . V_25 ,
V_249 [ V_225 ] . V_26 , V_249 [ V_225 ] . V_34 ) ;
if ( V_8 )
goto V_62;
}
V_6 -> V_229 = true ;
}
V_8 = F_13 ( V_2 , V_246 , & V_13 [ 0 ] ) ;
if ( V_8 )
goto V_62;
if ( V_13 [ 0 ] != 0x83 )
goto exit;
V_8 = F_13 ( V_2 , V_260 , & V_13 [ 0 ] ) ;
if ( V_8 )
goto V_62;
V_27 = V_13 [ 0 ] ;
V_8 = F_11 ( V_2 , V_261 , V_13 , V_27 ) ;
if ( V_8 )
goto V_62;
for ( V_225 = 0 ; V_225 < F_61 ( V_245 ) ; V_225 ++ ) {
V_8 = F_14 ( V_2 , V_245 [ V_225 ] . V_25 ,
V_245 [ V_225 ] . V_26 , V_245 [ V_225 ] . V_34 ) ;
if ( V_8 )
goto V_62;
}
F_68 ( & V_243 ) ;
for ( V_225 = 0 ; V_225 < V_27 ; V_225 ++ ) {
V_243 . V_262 = V_13 [ V_225 ] >> 7 ;
V_243 . V_263 = 50800 * ( V_13 [ V_225 ] & 0x7f ) ;
F_69 ( V_2 -> V_231 , & V_243 ) ;
}
F_70 ( V_2 -> V_231 , true ) ;
F_71 ( V_2 -> V_231 ) ;
exit:
return V_8 ;
V_62:
F_9 ( & V_2 -> V_14 -> V_6 , L_2 , V_8 ) ;
return V_8 ;
}
static int F_72 ( struct V_1 * V_2 ,
struct V_234 * V_235 )
{
if ( V_264 )
return F_12 ( V_2 , V_265 , 0x00 ) ;
if ( ! V_235 -> V_236 )
V_235 -> V_236 = V_237 ;
V_235 -> V_238 = V_266 ;
V_235 -> V_267 = V_268 ;
V_235 -> V_240 = F_67 ;
V_235 -> V_241 = 200 ;
return 0 ;
}
static int F_73 ( struct V_1 * V_2 ,
struct V_234 * V_235 )
{
struct V_5 * V_6 = F_20 ( V_2 ) ;
if ( V_6 -> V_107 == V_108 )
return F_66 ( V_2 , V_235 ) ;
else
return F_72 ( V_2 , V_235 ) ;
}
static int F_74 ( struct V_116 * V_37 , int V_215 )
{
struct V_5 * V_6 = F_39 ( V_37 ) ;
if ( V_6 -> V_107 == V_108 ) {
struct V_117 * V_118 = & V_6 -> V_117 ;
return V_118 -> V_269 ( V_37 -> V_131 [ 0 ] , V_215 ) ;
} else {
struct V_148 * V_118 = & V_6 -> V_148 ;
return V_118 -> V_269 ( V_37 -> V_131 [ 0 ] , V_215 ) ;
}
}
static int F_75 ( struct V_116 * V_37 , int V_17 ,
T_2 V_270 , int V_215 )
{
struct V_5 * V_6 = F_39 ( V_37 ) ;
if ( V_6 -> V_107 == V_108 ) {
struct V_117 * V_118 = & V_6 -> V_117 ;
return V_118 -> V_271 ( V_37 -> V_131 [ 0 ] , V_17 , V_270 , V_215 ) ;
} else {
struct V_148 * V_118 = & V_6 -> V_148 ;
return V_118 -> V_271 ( V_37 -> V_131 [ 0 ] , V_17 , V_270 , V_215 ) ;
}
}
