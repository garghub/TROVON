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
static int F_21 ( struct V_1 * V_2 ,
int V_77 , int V_78 )
{
int V_5 ;
T_1 V_24 ;
F_8 ( L_9 , V_22 , V_77 , V_78 ) ;
switch ( V_77 ) {
case V_79 :
V_5 = F_12 ( V_2 , V_80 , & V_24 ) ;
if ( V_5 )
goto V_12;
if ( V_78 )
V_24 &= 0xbf ;
else
V_24 |= 0x40 ;
V_5 = F_11 ( V_2 , V_80 , V_24 ) ;
if ( V_5 )
goto V_12;
break;
default:
V_5 = - V_53 ;
goto V_12;
}
return 0 ;
V_12:
V_12 ( L_1 , V_22 , V_5 ) ;
return V_5 ;
}
static int F_22 ( struct V_1 * V_2 ,
int V_77 , int V_78 )
{
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , int V_77 , int V_78 )
{
struct V_37 * V_38 = V_2 -> V_38 ;
switch ( V_38 -> V_64 ) {
case V_81 :
return F_21 ( V_2 , V_77 , V_78 ) ;
case V_82 :
return F_22 ( V_2 , V_77 , V_78 ) ;
default:
break;
}
return - V_76 ;
}
static int F_24 ( void * V_83 , int V_84 ,
int V_77 , int V_78 )
{
struct V_32 * V_33 = V_83 ;
struct V_1 * V_2 = F_14 ( V_33 ) ;
switch ( V_84 ) {
case V_85 :
return F_23 ( V_2 , V_77 , V_78 ) ;
default:
break;
}
return - V_53 ;
}
static int F_25 ( struct V_56 * V_33 )
{
int V_5 ;
struct V_37 * V_38 = V_33 -> V_57 -> V_38 ;
struct V_86 * V_86 ;
T_1 V_8 [ 2 ] , V_24 ;
struct V_3 V_87 = { 0x0120 , 0x0011 , 0x0001 , L_10 } ;
struct V_3 V_88 = { 0x0120 , 0x0011 , 0x0001 , L_11 } ;
struct V_3 V_89 = { 0x00c6 , V_48 , 1 , V_8 } ;
struct V_3 V_90 = { 0x00c6 , V_48 , 1 , V_8 } ;
struct V_3 V_91 = { 0x00c0 , V_48 , 1 , V_8 } ;
struct V_3 V_92 = { 0x01ac , V_48 , 1 , V_8 } ;
struct V_3 V_93 = { 0x00c0 , V_48 , 1 , V_8 } ;
struct V_3 V_94 = { 0x00c0 , V_48 , 1 , V_8 } ;
struct V_3 V_95 = { 0x7ec0 , V_48 , 2 , V_8 } ;
struct V_3 V_96 = { 0xd9c0 , V_48 , 1 , V_8 } ;
struct V_3 V_97 = { 0x02c8 , V_48 , 1 , V_8 } ;
struct V_3 V_98 = { 0x00c0 , V_48 , 2 , V_8 } ;
F_8 ( L_3 , V_22 ) ;
V_5 = F_12 ( V_33 -> V_57 , V_62 , & V_24 ) ;
if ( V_5 )
goto V_12;
V_24 &= 0xbf ;
V_5 = F_11 ( V_33 -> V_57 , V_62 , V_24 ) ;
if ( V_5 )
goto V_12;
V_5 = F_12 ( V_33 -> V_57 , V_63 , & V_24 ) ;
if ( V_5 )
goto V_12;
V_24 |= 0x48 ;
V_5 = F_11 ( V_33 -> V_57 , V_63 , V_24 ) ;
if ( V_5 )
goto V_12;
V_5 = F_1 ( V_33 -> V_57 , & V_87 ) ;
if ( V_5 )
goto V_12;
V_38 -> V_64 = V_99 ;
V_5 = F_1 ( V_33 -> V_57 , & V_89 ) ;
if ( V_5 == 0 && V_8 [ 0 ] == 0xa1 ) {
V_38 -> V_64 = V_81 ;
V_86 = & V_100 ;
F_26 ( L_12 , V_22 ) ;
goto V_67;
}
V_5 = F_1 ( V_33 -> V_57 , & V_90 ) ;
if ( V_5 == 0 && V_8 [ 0 ] == 0xa3 ) {
V_38 -> V_64 = V_82 ;
V_86 = & V_101 ;
F_26 ( L_13 , V_22 ) ;
goto V_67;
}
V_5 = F_1 ( V_33 -> V_57 , & V_91 ) ;
if ( V_5 == 0 && V_8 [ 0 ] == 0x85 ) {
V_38 -> V_64 = V_102 ;
F_26 ( L_14 , V_22 ) ;
goto V_103;
}
V_5 = F_1 ( V_33 -> V_57 , & V_92 ) ;
if ( V_5 == 0 && V_8 [ 0 ] == 0x56 ) {
V_38 -> V_64 = V_104 ;
F_26 ( L_15 , V_22 ) ;
goto V_103;
}
V_5 = F_1 ( V_33 -> V_57 , & V_93 ) ;
if ( V_5 == 0 && ( V_8 [ 0 ] == 0x9e || V_8 [ 0 ] == 0x9c ) ) {
V_38 -> V_64 = V_105 ;
F_26 ( L_16 , V_22 ) ;
goto V_103;
}
V_5 = F_1 ( V_33 -> V_57 , & V_94 ) ;
if ( V_5 == 0 && V_8 [ 0 ] == 0x38 ) {
V_38 -> V_64 = V_106 ;
F_26 ( L_17 , V_22 ) ;
goto V_103;
}
V_5 = F_1 ( V_33 -> V_57 , & V_95 ) ;
if ( V_5 == 0 && V_8 [ 0 ] == 0x23 && V_8 [ 1 ] == 0x28 ) {
V_38 -> V_64 = V_107 ;
F_26 ( L_18 , V_22 ) ;
goto V_103;
}
V_5 = F_1 ( V_33 -> V_57 , & V_96 ) ;
if ( V_5 == 0 && V_8 [ 0 ] == 0x14 ) {
V_38 -> V_64 = V_108 ;
F_26 ( L_19 , V_22 ) ;
goto V_103;
}
V_5 = F_1 ( V_33 -> V_57 , & V_97 ) ;
if ( V_5 == 0 && V_8 [ 0 ] == 0x40 ) {
V_38 -> V_64 = V_109 ;
F_26 ( L_20 , V_22 ) ;
goto V_103;
}
V_5 = F_1 ( V_33 -> V_57 , & V_98 ) ;
if ( V_5 == 0 && ( V_8 [ 0 ] == 0xc7 || V_8 [ 1 ] == 0x60 ) ) {
V_38 -> V_64 = V_110 ;
F_26 ( L_21 , V_22 ) ;
goto V_103;
}
V_103:
V_5 = F_1 ( V_33 -> V_57 , & V_88 ) ;
if ( V_5 )
goto V_12;
F_8 ( L_22 ) ;
V_5 = - V_76 ;
return V_5 ;
V_67:
V_5 = F_1 ( V_33 -> V_57 , & V_88 ) ;
if ( V_5 )
goto V_12;
V_33 -> V_72 [ 0 ] . V_73 = F_20 ( V_111 , V_86 ,
& V_33 -> V_57 -> V_75 ) ;
if ( V_33 -> V_72 [ 0 ] . V_73 == NULL ) {
V_5 = - V_76 ;
goto V_12;
}
V_33 -> V_72 [ 0 ] . V_73 -> V_112 = F_24 ;
return V_5 ;
V_12:
F_8 ( L_1 , V_22 , V_5 ) ;
return V_5 ;
}
static int F_27 ( struct V_56 * V_33 )
{
int V_5 ;
struct V_37 * V_38 = V_33 -> V_57 -> V_38 ;
struct V_32 * V_113 ;
struct V_114 * V_73 ;
F_8 ( L_3 , V_22 ) ;
V_113 = F_28 ( V_33 -> V_72 [ 0 ] . V_73 ) ;
switch ( V_38 -> V_64 ) {
case V_65 :
V_73 = F_20 ( V_115 , V_33 -> V_72 [ 0 ] . V_73 ,
V_113 , & V_116 ) ;
break;
case V_68 :
V_73 = F_20 ( V_117 , V_33 -> V_72 [ 0 ] . V_73 ,
V_113 , & V_118 ,
1220 ) ;
break;
case V_70 :
V_73 = F_20 ( V_119 , V_33 -> V_72 [ 0 ] . V_73 ,
V_113 , & V_120 ) ;
break;
default:
V_73 = NULL ;
V_12 ( L_23 , V_38 -> V_64 ) ;
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
static int F_29 ( struct V_56 * V_33 )
{
int V_5 ;
struct V_37 * V_38 = V_33 -> V_57 -> V_38 ;
struct V_114 * V_73 ;
F_8 ( L_3 , V_22 ) ;
switch ( V_38 -> V_64 ) {
case V_81 :
V_73 = F_20 ( V_121 , V_33 -> V_72 [ 0 ] . V_73 ,
& V_33 -> V_57 -> V_75 , 0xc6 >> 1 , 0 , V_122 ) ;
V_33 -> V_72 [ 0 ] . V_73 -> V_123 . V_124 = V_33 -> V_72 [ 0 ] .
V_73 -> V_123 . V_125 . V_126 ;
return 0 ;
break;
case V_82 :
V_73 = F_20 ( V_127 , V_33 -> V_72 [ 0 ] . V_73 ,
& V_33 -> V_57 -> V_75 , 0xc6 >> 1 , 0 , V_122 ) ;
V_33 -> V_72 [ 0 ] . V_73 -> V_123 . V_124 = V_33 -> V_72 [ 0 ]
. V_73 -> V_123 . V_125 . V_126 ;
return 0 ;
default:
V_73 = NULL ;
V_12 ( L_23 , V_38 -> V_64 ) ;
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
static int F_30 ( struct V_56 * V_33 , int V_128 )
{
int V_5 ;
T_1 V_8 [ 2 ] , V_129 ;
F_8 ( L_24 , V_22 , V_128 ) ;
V_5 = F_12 ( V_33 -> V_57 , V_80 , & V_129 ) ;
if ( V_5 )
goto V_12;
if ( V_128 ) {
V_8 [ 0 ] = 0x00 ;
V_8 [ 1 ] = 0x00 ;
V_129 |= 0x04 ;
} else {
V_8 [ 0 ] = 0x10 ;
V_8 [ 1 ] = 0x02 ;
V_129 &= ( ~ 0x04 ) ;
}
V_5 = F_11 ( V_33 -> V_57 , V_80 , V_129 ) ;
if ( V_5 )
goto V_12;
V_5 = F_9 ( V_33 -> V_57 , V_130 , V_8 , 2 ) ;
if ( V_5 )
goto V_12;
return V_5 ;
V_12:
F_8 ( L_1 , V_22 , V_5 ) ;
return V_5 ;
}
static int F_31 ( struct V_56 * V_33 , int V_128 )
{
int V_5 ;
T_1 V_8 [ 2 ] ;
F_8 ( L_24 , V_22 , V_128 ) ;
if ( V_128 ) {
V_8 [ 0 ] = 0x00 ;
V_8 [ 1 ] = 0x00 ;
} else {
V_8 [ 0 ] = 0x10 ;
V_8 [ 1 ] = 0x02 ;
}
V_5 = F_9 ( V_33 -> V_57 , V_130 , V_8 , 2 ) ;
if ( V_5 )
goto V_12;
return V_5 ;
V_12:
F_8 ( L_1 , V_22 , V_5 ) ;
return V_5 ;
}
static int F_32 ( struct V_1 * V_2 , int V_128 )
{
int V_5 ;
T_1 V_129 , V_131 ;
F_8 ( L_24 , V_22 , V_128 ) ;
V_5 = F_12 ( V_2 , V_132 , & V_131 ) ;
if ( V_5 )
goto V_12;
V_5 = F_12 ( V_2 , V_80 , & V_129 ) ;
if ( V_5 )
goto V_12;
F_8 ( L_25 , V_22 , V_131 , V_129 ) ;
if ( V_128 ) {
V_129 |= 0x01 ;
V_129 &= ( ~ 0x10 ) ;
V_131 = V_131 & 0x0f ;
V_131 |= 0xe0 ;
} else {
V_129 &= ( ~ 0x01 ) ;
V_129 |= 0x10 ;
V_131 = V_131 & ( ~ 0xc0 ) ;
}
F_8 ( L_26 , V_22 , V_131 , V_129 ) ;
V_5 = F_11 ( V_2 , V_132 , V_131 ) ;
if ( V_5 )
goto V_12;
V_5 = F_11 ( V_2 , V_80 , V_129 ) ;
if ( V_5 )
goto V_12;
return V_5 ;
V_12:
F_8 ( L_1 , V_22 , V_5 ) ;
return V_5 ;
}
static int F_33 ( struct V_1 * V_2 , int V_128 )
{
int V_5 ;
T_1 V_24 ;
F_8 ( L_24 , V_22 , V_128 ) ;
if ( V_128 ) {
V_5 = F_12 ( V_2 , V_80 , & V_24 ) ;
if ( V_5 )
goto V_12;
V_24 |= 0x08 ;
V_24 &= 0xef ;
V_5 = F_11 ( V_2 , V_80 , V_24 ) ;
if ( V_5 )
goto V_12;
V_5 = F_12 ( V_2 , V_133 , & V_24 ) ;
if ( V_5 )
goto V_12;
V_24 &= 0xef ;
V_5 = F_11 ( V_2 , V_133 , V_24 ) ;
if ( V_5 )
goto V_12;
V_5 = F_12 ( V_2 , V_134 , & V_24 ) ;
if ( V_5 )
goto V_12;
V_24 |= 0x80 ;
V_5 = F_11 ( V_2 , V_134 , V_24 ) ;
if ( V_5 )
goto V_12;
V_5 = F_12 ( V_2 , V_134 , & V_24 ) ;
if ( V_5 )
goto V_12;
V_24 &= 0xdf ;
V_5 = F_11 ( V_2 , V_134 , V_24 ) ;
if ( V_5 )
goto V_12;
V_5 = F_12 ( V_2 , V_134 , & V_24 ) ;
if ( V_5 )
goto V_12;
V_24 |= 0x20 ;
V_5 = F_11 ( V_2 , V_134 , V_24 ) ;
if ( V_5 )
goto V_12;
F_34 ( 5 ) ;
V_5 = F_12 ( V_2 , V_134 , & V_24 ) ;
if ( V_5 )
goto V_12;
V_24 |= 0x48 ;
V_5 = F_11 ( V_2 , V_134 , V_24 ) ;
if ( V_5 )
goto V_12;
} else {
V_5 = F_12 ( V_2 , V_133 , & V_24 ) ;
if ( V_5 )
goto V_12;
V_24 |= 0x0c ;
V_5 = F_11 ( V_2 , V_133 , V_24 ) ;
if ( V_5 )
goto V_12;
V_5 = F_12 ( V_2 , V_80 , & V_24 ) ;
if ( V_5 )
goto V_12;
V_24 |= 0x10 ;
V_5 = F_11 ( V_2 , V_80 , V_24 ) ;
if ( V_5 )
goto V_12;
V_5 = F_12 ( V_2 , V_134 , & V_24 ) ;
if ( V_5 )
goto V_12;
V_24 &= 0x37 ;
V_5 = F_11 ( V_2 , V_134 , V_24 ) ;
if ( V_5 )
goto V_12;
}
return V_5 ;
V_12:
F_8 ( L_1 , V_22 , V_5 ) ;
return V_5 ;
}
static int F_35 ( struct V_1 * V_2 )
{
int V_5 , V_135 ;
struct V_37 * V_38 = V_2 -> V_38 ;
T_1 V_8 [ 5 ] ;
T_3 V_136 ;
struct V_137 V_138 [] = {
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
if ( ! V_38 -> V_139 ) {
for ( V_135 = 0 ; V_135 < F_36 ( V_138 ) ; V_135 ++ ) {
V_5 = F_11 ( V_2 , V_138 [ V_135 ] . V_23 ,
V_138 [ V_135 ] . V_24 ) ;
if ( V_5 )
goto V_12;
}
V_38 -> V_139 = true ;
}
V_5 = F_10 ( V_2 , V_140 , V_8 , 5 ) ;
if ( V_5 )
goto V_12;
if ( V_8 [ 4 ] & 0x01 ) {
if ( V_8 [ 2 ] == ( T_1 ) ~ V_8 [ 3 ] ) {
if ( V_8 [ 0 ] == ( T_1 ) ~ V_8 [ 1 ] ) {
V_136 = V_8 [ 0 ] << 8 | V_8 [ 2 ] ;
} else {
V_136 = V_8 [ 0 ] << 16 |
V_8 [ 1 ] << 8 | V_8 [ 2 ] ;
}
} else {
V_136 = V_8 [ 0 ] << 24 | V_8 [ 1 ] << 16 |
V_8 [ 2 ] << 8 | V_8 [ 3 ] ;
}
F_37 ( V_2 -> V_141 , V_136 , 0 ) ;
V_5 = F_11 ( V_2 , V_142 , 1 ) ;
if ( V_5 )
goto V_12;
V_5 = F_11 ( V_2 , V_142 , 1 ) ;
if ( V_5 )
goto V_12;
}
return V_5 ;
V_12:
F_8 ( L_1 , V_22 , V_5 ) ;
return V_5 ;
}
static int F_38 ( struct V_1 * V_2 )
{
int V_5 , V_135 ;
struct V_37 * V_38 = V_2 -> V_38 ;
T_1 V_8 [ 128 ] ;
int V_25 ;
struct V_137 V_138 [] = {
{ V_143 , 0x20 } ,
{ V_144 , 0x80 } ,
{ V_145 , 0xff } ,
{ V_146 , 0xff } ,
{ V_147 , 0xd0 } ,
{ V_148 , 0x07 } ,
{ V_149 , 0xc0 } ,
{ V_150 , 0x00 } ,
{ V_151 , 0x03 } ,
{ V_152 , 0x09 } ,
{ V_153 , 0x1c } ,
{ V_154 , 0x1e } ,
{ V_155 , 0x1e } ,
{ V_143 , 0x80 } ,
} ;
if ( ! V_38 -> V_139 ) {
for ( V_135 = 0 ; V_135 < F_36 ( V_138 ) ; V_135 ++ ) {
V_5 = F_11 ( V_2 , V_138 [ V_135 ] . V_23 ,
V_138 [ V_135 ] . V_24 ) ;
if ( V_5 )
goto V_12;
}
V_38 -> V_139 = true ;
}
V_5 = F_12 ( V_2 , V_145 , & V_8 [ 0 ] ) ;
if ( V_5 )
goto V_12;
if ( V_8 [ 0 ] != 0x83 )
goto exit;
V_5 = F_12 ( V_2 , V_156 , & V_8 [ 0 ] ) ;
if ( V_5 )
goto V_12;
V_25 = V_8 [ 0 ] ;
V_5 = F_10 ( V_2 , V_157 , V_8 , V_25 ) ;
V_5 = F_11 ( V_2 , V_145 , 0x03 ) ;
V_5 = F_11 ( V_2 , V_144 , 0x80 ) ;
V_5 = F_11 ( V_2 , V_143 , 0x80 ) ;
exit:
return V_5 ;
V_12:
F_8 ( L_1 , V_22 , V_5 ) ;
return V_5 ;
}
static int F_39 ( struct V_158 * V_159 ,
const struct V_160 * V_161 )
{
int V_5 , V_135 ;
T_1 V_24 ;
int V_162 = F_36 ( V_163 ) ;
struct V_1 * V_2 ;
struct V_164 * V_18 ;
bool V_67 ;
F_8 ( L_27 , V_22 ,
V_159 -> V_165 -> V_166 . V_167 ) ;
if ( V_159 -> V_165 -> V_166 . V_167 != 0 )
return 0 ;
V_18 = F_40 ( V_159 ) ;
for ( V_135 = 0 , V_67 = false ; V_135 < F_36 ( V_168 ) - 1 ; V_135 ++ ) {
if ( V_168 [ V_135 ] . V_169 ==
F_41 ( V_18 -> V_170 . V_169 ) &&
V_168 [ V_135 ] . V_171 ==
F_41 ( V_18 -> V_170 . V_171 ) ) {
V_67 = true ;
break;
}
}
if ( ! V_67 ) {
F_8 ( L_28 , V_22 ,
F_41 ( V_18 -> V_170 . V_169 ) ,
F_41 ( V_18 -> V_170 . V_171 ) ) ;
V_163 [ 0 ] . V_172 [ 0 ] . V_173 [ 0 ] -> V_169 =
F_41 ( V_18 -> V_170 . V_169 ) ;
V_163 [ 0 ] . V_172 [ 0 ] . V_173 [ 0 ] -> V_171 =
F_41 ( V_18 -> V_170 . V_171 ) ;
}
for ( V_135 = 0 ; V_135 < V_162 ; V_135 ++ ) {
V_5 = F_42 ( V_159 , & V_163 [ V_135 ] ,
V_174 , & V_2 , V_175 ) ;
if ( V_5 == 0 || V_5 != - V_76 )
break;
}
if ( V_5 )
goto V_12;
V_5 = F_12 ( V_2 , V_176 , & V_24 ) ;
if ( V_5 )
goto V_12;
V_24 |= 0x09 ;
V_5 = F_11 ( V_2 , V_176 , V_24 ) ;
if ( V_5 )
goto V_12;
V_5 = F_9 ( V_2 , V_177 , L_29 , 4 ) ;
if ( V_5 )
goto V_12;
V_5 = F_9 ( V_2 , V_178 , L_30 , 4 ) ;
if ( V_5 )
goto V_12;
return V_5 ;
V_12:
F_8 ( L_1 , V_22 , V_5 ) ;
return V_5 ;
}
static int T_4 F_43 ( void )
{
int V_5 ;
F_8 ( L_3 , V_22 ) ;
V_5 = F_44 ( & V_179 ) ;
if ( V_5 )
V_12 ( L_31 , V_5 ) ;
return V_5 ;
}
static void T_5 F_45 ( void )
{
F_8 ( L_3 , V_22 ) ;
F_46 ( & V_179 ) ;
}
