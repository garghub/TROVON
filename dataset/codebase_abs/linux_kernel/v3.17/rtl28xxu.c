static inline struct V_1 * F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const struct V_5 * V_6 ,
struct V_7 * V_8 )
{
return NULL ;
}
static int F_2 ( struct V_9 * V_10 , struct V_11 * V_12 )
{
int V_13 ;
unsigned int V_14 ;
T_1 V_15 ;
T_1 * V_16 ;
V_16 = F_3 ( V_12 -> V_17 , V_18 ) ;
if ( ! V_16 ) {
V_13 = - V_19 ;
goto V_20;
}
if ( V_12 -> V_21 & V_22 ) {
memcpy ( V_16 , V_12 -> V_23 , V_12 -> V_17 ) ;
V_15 = ( V_24 | V_25 ) ;
V_14 = F_4 ( V_10 -> V_26 , 0 ) ;
} else {
V_15 = ( V_24 | V_27 ) ;
V_14 = F_5 ( V_10 -> V_26 , 0 ) ;
}
V_13 = F_6 ( V_10 -> V_26 , V_14 , 0 , V_15 , V_12 -> V_28 ,
V_12 -> V_21 , V_16 , V_12 -> V_17 , 1000 ) ;
F_7 ( V_10 -> V_26 , 0 , V_15 , V_12 -> V_28 ,
V_12 -> V_21 , V_16 , V_12 -> V_17 ) ;
if ( V_13 > 0 )
V_13 = 0 ;
if ( ! V_13 && V_15 == ( V_24 | V_27 ) )
memcpy ( V_12 -> V_23 , V_16 , V_12 -> V_17 ) ;
F_8 ( V_16 ) ;
if ( V_13 )
goto V_20;
return V_13 ;
V_20:
F_9 ( & V_10 -> V_26 -> V_29 , L_1 , V_30 , V_13 ) ;
return V_13 ;
}
static int F_10 ( struct V_9 * V_10 , T_2 V_31 , T_1 * V_32 , int V_33 )
{
struct V_11 V_12 ;
if ( V_31 < 0x3000 )
V_12 . V_21 = V_34 ;
else if ( V_31 < 0x4000 )
V_12 . V_21 = V_35 ;
else
V_12 . V_21 = V_36 ;
V_12 . V_28 = V_31 ;
V_12 . V_17 = V_33 ;
V_12 . V_23 = V_32 ;
return F_2 ( V_10 , & V_12 ) ;
}
static int F_11 ( struct V_9 * V_10 , T_2 V_31 , T_1 * V_32 , int V_33 )
{
struct V_11 V_12 ;
if ( V_31 < 0x3000 )
V_12 . V_21 = V_37 ;
else if ( V_31 < 0x4000 )
V_12 . V_21 = V_38 ;
else
V_12 . V_21 = V_39 ;
V_12 . V_28 = V_31 ;
V_12 . V_17 = V_33 ;
V_12 . V_23 = V_32 ;
return F_2 ( V_10 , & V_12 ) ;
}
static int F_12 ( struct V_9 * V_10 , T_2 V_31 , T_1 V_32 )
{
return F_10 ( V_10 , V_31 , & V_32 , 1 ) ;
}
static int F_13 ( struct V_9 * V_10 , T_2 V_31 , T_1 * V_32 )
{
return F_11 ( V_10 , V_31 , V_32 , 1 ) ;
}
static int F_14 ( struct V_9 * V_10 , T_2 V_31 , T_1 V_32 ,
T_1 V_40 )
{
int V_13 ;
T_1 V_41 ;
if ( V_40 != 0xff ) {
V_13 = F_13 ( V_10 , V_31 , & V_41 ) ;
if ( V_13 )
return V_13 ;
V_32 &= V_40 ;
V_41 &= ~ V_40 ;
V_32 |= V_41 ;
}
return F_12 ( V_10 , V_31 , V_32 ) ;
}
static int F_15 ( struct V_3 * V_42 , struct V_43 V_44 [] ,
int V_45 )
{
int V_13 ;
struct V_9 * V_10 = F_16 ( V_42 ) ;
struct V_46 * V_47 = V_10 -> V_47 ;
struct V_11 V_12 ;
if ( F_17 ( & V_10 -> V_48 ) < 0 )
return - V_49 ;
if ( V_45 == 2 && ! ( V_44 [ 0 ] . V_50 & V_51 ) &&
( V_44 [ 1 ] . V_50 & V_51 ) ) {
if ( V_44 [ 0 ] . V_33 > 24 || V_44 [ 1 ] . V_33 > 24 ) {
V_13 = - V_52 ;
goto V_53;
} else if ( V_44 [ 0 ] . V_54 == 0x10 ) {
V_12 . V_28 = ( V_44 [ 0 ] . V_16 [ 0 ] << 8 ) | ( V_44 [ 0 ] . V_54 << 1 ) ;
V_12 . V_21 = V_55 | V_47 -> V_56 ;
V_12 . V_17 = V_44 [ 1 ] . V_33 ;
V_12 . V_23 = & V_44 [ 1 ] . V_16 [ 0 ] ;
V_13 = F_2 ( V_10 , & V_12 ) ;
} else if ( V_44 [ 0 ] . V_33 < 2 ) {
V_12 . V_28 = ( V_44 [ 0 ] . V_16 [ 0 ] << 8 ) | ( V_44 [ 0 ] . V_54 << 1 ) ;
V_12 . V_21 = V_57 ;
V_12 . V_17 = V_44 [ 1 ] . V_33 ;
V_12 . V_23 = & V_44 [ 1 ] . V_16 [ 0 ] ;
V_13 = F_2 ( V_10 , & V_12 ) ;
} else {
V_12 . V_28 = ( V_44 [ 0 ] . V_54 << 1 ) ;
V_12 . V_21 = V_58 ;
V_12 . V_17 = V_44 [ 0 ] . V_33 ;
V_12 . V_23 = V_44 [ 0 ] . V_16 ;
V_13 = F_2 ( V_10 , & V_12 ) ;
if ( V_13 )
goto V_53;
V_12 . V_28 = ( V_44 [ 0 ] . V_54 << 1 ) ;
V_12 . V_21 = V_59 ;
V_12 . V_17 = V_44 [ 1 ] . V_33 ;
V_12 . V_23 = V_44 [ 1 ] . V_16 ;
V_13 = F_2 ( V_10 , & V_12 ) ;
}
} else if ( V_45 == 1 && ! ( V_44 [ 0 ] . V_50 & V_51 ) ) {
if ( V_44 [ 0 ] . V_33 > 22 ) {
V_13 = - V_52 ;
goto V_53;
} else if ( V_44 [ 0 ] . V_54 == 0x10 ) {
if ( V_44 [ 0 ] . V_16 [ 0 ] == 0x00 ) {
V_47 -> V_56 = V_44 [ 0 ] . V_16 [ 1 ] ;
V_13 = 0 ;
} else {
V_12 . V_28 = ( V_44 [ 0 ] . V_16 [ 0 ] << 8 ) |
( V_44 [ 0 ] . V_54 << 1 ) ;
V_12 . V_21 = V_60 | V_47 -> V_56 ;
V_12 . V_17 = V_44 [ 0 ] . V_33 - 1 ;
V_12 . V_23 = & V_44 [ 0 ] . V_16 [ 1 ] ;
V_13 = F_2 ( V_10 , & V_12 ) ;
}
} else if ( V_44 [ 0 ] . V_33 < 23 ) {
V_12 . V_28 = ( V_44 [ 0 ] . V_16 [ 0 ] << 8 ) | ( V_44 [ 0 ] . V_54 << 1 ) ;
V_12 . V_21 = V_61 ;
V_12 . V_17 = V_44 [ 0 ] . V_33 - 1 ;
V_12 . V_23 = & V_44 [ 0 ] . V_16 [ 1 ] ;
V_13 = F_2 ( V_10 , & V_12 ) ;
} else {
V_12 . V_28 = ( V_44 [ 0 ] . V_54 << 1 ) ;
V_12 . V_21 = V_58 ;
V_12 . V_17 = V_44 [ 0 ] . V_33 ;
V_12 . V_23 = V_44 [ 0 ] . V_16 ;
V_13 = F_2 ( V_10 , & V_12 ) ;
}
} else {
V_13 = - V_62 ;
}
V_53:
F_18 ( & V_10 -> V_48 ) ;
return V_13 ? V_13 : V_45 ;
}
static T_3 F_19 ( struct V_3 * V_63 )
{
return V_64 ;
}
static int F_20 ( struct V_9 * V_10 )
{
struct V_46 * V_47 = F_21 ( V_10 ) ;
int V_13 ;
T_1 V_16 [ 1 ] ;
struct V_11 V_65 = { 0x0120 , 0x0011 , 0x0001 , L_2 } ;
struct V_11 V_66 = { 0x00c0 , V_57 , 1 , V_16 } ;
struct V_11 V_67 = { 0x0fc4 , V_57 , 1 , V_16 } ;
F_9 ( & V_10 -> V_26 -> V_29 , L_3 , V_30 ) ;
V_13 = F_12 ( V_10 , V_68 , 0x0a ) ;
if ( V_13 )
goto V_20;
V_13 = F_12 ( V_10 , V_69 , 0x15 ) ;
if ( V_13 )
goto V_20;
F_22 ( 20 ) ;
V_47 -> V_70 = L_4 ;
V_13 = F_2 ( V_10 , & V_65 ) ;
if ( V_13 )
goto V_20;
V_13 = F_2 ( V_10 , & V_67 ) ;
if ( V_13 == 0 && V_16 [ 0 ] == 0x2c ) {
V_47 -> V_71 = V_72 ;
V_47 -> V_70 = L_5 ;
goto V_73;
}
V_13 = F_2 ( V_10 , & V_65 ) ;
if ( V_13 )
goto V_20;
V_13 = F_2 ( V_10 , & V_66 ) ;
if ( V_13 == 0 && V_16 [ 0 ] == 0x63 ) {
V_47 -> V_71 = V_74 ;
V_47 -> V_70 = L_6 ;
goto V_73;
}
V_47 -> V_71 = V_75 ;
V_47 -> V_70 = L_7 ;
goto V_73;
V_73:
F_9 ( & V_10 -> V_26 -> V_29 , L_8 , V_30 , V_47 -> V_70 ) ;
return 0 ;
V_20:
F_9 ( & V_10 -> V_26 -> V_29 , L_1 , V_30 , V_13 ) ;
return V_13 ;
}
static int F_23 ( struct V_9 * V_10 )
{
struct V_46 * V_47 = F_21 ( V_10 ) ;
int V_13 ;
T_1 V_16 [ 2 ] ;
struct V_11 V_65 = { 0x0120 , 0x0011 , 0x0001 , L_9 } ;
struct V_11 V_76 = { 0x0120 , 0x0011 , 0x0001 , L_10 } ;
struct V_11 V_77 = { 0x00c6 , V_57 , 1 , V_16 } ;
struct V_11 V_78 = { 0x00c6 , V_57 , 1 , V_16 } ;
struct V_11 V_79 = { 0x00c0 , V_57 , 1 , V_16 } ;
struct V_11 V_80 = { 0x01ac , V_57 , 1 , V_16 } ;
struct V_11 V_81 = { 0x00c0 , V_57 , 1 , V_16 } ;
struct V_11 V_82 = { 0x00c0 , V_57 , 1 , V_16 } ;
struct V_11 V_83 = { 0x7ec0 , V_57 , 2 , V_16 } ;
struct V_11 V_84 = { 0xd9c0 , V_57 , 1 , V_16 } ;
struct V_11 V_85 = { 0x02c8 , V_57 , 1 , V_16 } ;
struct V_11 V_86 = { 0x00c0 , V_57 , 2 , V_16 } ;
struct V_11 V_87 = { 0x0034 , V_57 , 1 , V_16 } ;
struct V_11 V_88 = { 0x0074 , V_57 , 1 , V_16 } ;
F_9 ( & V_10 -> V_26 -> V_29 , L_3 , V_30 ) ;
V_13 = F_14 ( V_10 , V_68 , 0x00 , 0x40 ) ;
if ( V_13 )
goto V_20;
V_13 = F_14 ( V_10 , V_69 , 0x48 , 0x48 ) ;
if ( V_13 )
goto V_20;
V_13 = F_2 ( V_10 , & V_65 ) ;
if ( V_13 )
goto V_20;
V_47 -> V_70 = L_4 ;
V_13 = F_2 ( V_10 , & V_77 ) ;
if ( V_13 == 0 && V_16 [ 0 ] == 0xa1 ) {
V_47 -> V_71 = V_89 ;
V_47 -> V_70 = L_11 ;
goto V_73;
}
V_13 = F_2 ( V_10 , & V_78 ) ;
if ( V_13 == 0 && V_16 [ 0 ] == 0xa3 ) {
V_47 -> V_71 = V_90 ;
V_47 -> V_70 = L_12 ;
goto V_73;
}
V_13 = F_2 ( V_10 , & V_79 ) ;
if ( V_13 == 0 && V_16 [ 0 ] == 0x85 ) {
V_47 -> V_71 = V_91 ;
V_47 -> V_70 = L_13 ;
goto V_73;
}
V_13 = F_2 ( V_10 , & V_80 ) ;
if ( V_13 == 0 && V_16 [ 0 ] == 0x56 ) {
V_47 -> V_71 = V_92 ;
V_47 -> V_70 = L_14 ;
goto V_73;
}
V_13 = F_2 ( V_10 , & V_81 ) ;
if ( V_13 == 0 && ( V_16 [ 0 ] == 0x9e || V_16 [ 0 ] == 0x9c ) ) {
V_47 -> V_71 = V_93 ;
V_47 -> V_70 = L_15 ;
goto V_73;
}
V_13 = F_2 ( V_10 , & V_82 ) ;
if ( V_13 == 0 && V_16 [ 0 ] == 0x38 ) {
V_47 -> V_71 = V_94 ;
V_47 -> V_70 = L_16 ;
goto V_73;
}
V_13 = F_2 ( V_10 , & V_83 ) ;
if ( V_13 == 0 && V_16 [ 0 ] == 0x23 && V_16 [ 1 ] == 0x28 ) {
V_47 -> V_71 = V_95 ;
V_47 -> V_70 = L_17 ;
goto V_73;
}
V_13 = F_2 ( V_10 , & V_84 ) ;
if ( V_13 == 0 && V_16 [ 0 ] == 0x14 ) {
V_47 -> V_71 = V_96 ;
V_47 -> V_70 = L_18 ;
goto V_73;
}
V_13 = F_2 ( V_10 , & V_85 ) ;
if ( V_13 == 0 && V_16 [ 0 ] == 0x40 ) {
V_47 -> V_71 = V_97 ;
V_47 -> V_70 = L_19 ;
goto V_73;
}
V_13 = F_2 ( V_10 , & V_86 ) ;
if ( V_13 == 0 && ( V_16 [ 0 ] == 0xc7 || V_16 [ 1 ] == 0x60 ) ) {
V_47 -> V_71 = V_98 ;
V_47 -> V_70 = L_20 ;
goto V_73;
}
V_13 = F_2 ( V_10 , & V_87 ) ;
if ( V_13 == 0 && V_16 [ 0 ] == 0x69 ) {
V_47 -> V_71 = V_99 ;
V_47 -> V_70 = L_21 ;
goto V_73;
}
V_13 = F_2 ( V_10 , & V_88 ) ;
if ( V_13 == 0 && V_16 [ 0 ] == 0x69 ) {
V_47 -> V_71 = V_100 ;
V_47 -> V_70 = L_22 ;
goto V_73;
}
V_73:
F_9 ( & V_10 -> V_26 -> V_29 , L_8 , V_30 , V_47 -> V_70 ) ;
V_13 = F_2 ( V_10 , & V_76 ) ;
if ( V_13 < 0 )
goto V_20;
return 0 ;
V_20:
F_9 ( & V_10 -> V_26 -> V_29 , L_1 , V_30 , V_13 ) ;
return V_13 ;
}
static int F_24 ( struct V_101 * V_42 )
{
struct V_9 * V_10 = F_25 ( V_42 ) ;
struct V_46 * V_47 = F_21 ( V_10 ) ;
const struct V_102 * V_102 ;
int V_13 ;
F_9 ( & V_10 -> V_26 -> V_29 , L_3 , V_30 ) ;
switch ( V_47 -> V_71 ) {
case V_72 :
V_102 = & V_103 ;
break;
case V_74 :
V_102 = & V_104 ;
break;
case V_75 :
V_102 = & V_105 ;
break;
default:
F_26 ( & V_10 -> V_26 -> V_29 , L_23 ,
V_106 , V_47 -> V_70 ) ;
V_13 = - V_107 ;
goto V_20;
}
V_42 -> V_2 [ 0 ] = F_27 ( V_108 , V_102 , & V_10 -> V_109 ) ;
if ( ! V_42 -> V_2 [ 0 ] ) {
V_13 = - V_107 ;
goto V_20;
}
return 0 ;
V_20:
F_9 ( & V_10 -> V_26 -> V_29 , L_1 , V_30 , V_13 ) ;
return V_13 ;
}
static int F_28 ( struct V_9 * V_10 ,
int V_110 , int V_111 )
{
int V_13 ;
T_1 V_32 ;
F_9 ( & V_10 -> V_26 -> V_29 , L_24 , V_30 , V_110 , V_111 ) ;
switch ( V_110 ) {
case V_112 :
V_13 = F_13 ( V_10 , V_113 , & V_32 ) ;
if ( V_13 )
goto V_20;
if ( V_111 )
V_32 &= 0xbf ;
else
V_32 |= 0x40 ;
V_13 = F_12 ( V_10 , V_113 , V_32 ) ;
if ( V_13 )
goto V_20;
break;
default:
V_13 = - V_62 ;
goto V_20;
}
return 0 ;
V_20:
F_9 ( & V_10 -> V_26 -> V_29 , L_1 , V_30 , V_13 ) ;
return V_13 ;
}
static int F_29 ( struct V_9 * V_10 ,
int V_110 , int V_111 )
{
int V_13 ;
T_1 V_32 ;
F_9 ( & V_10 -> V_26 -> V_29 , L_24 , V_30 , V_110 , V_111 ) ;
switch ( V_110 ) {
case V_114 :
if ( V_111 )
V_32 = ( 1 << 4 ) ;
else
V_32 = ( 0 << 4 ) ;
V_13 = F_14 ( V_10 , V_113 , V_32 , 0x10 ) ;
if ( V_13 )
goto V_20;
break;
case V_115 :
if ( V_111 )
V_32 = ( 1 << 1 ) ;
else
V_32 = ( 0 << 1 ) ;
V_13 = F_14 ( V_10 , V_113 , V_32 , 0x02 ) ;
if ( V_13 )
goto V_20;
break;
}
return 0 ;
V_20:
F_9 ( & V_10 -> V_26 -> V_29 , L_1 , V_30 , V_13 ) ;
return V_13 ;
}
static int F_30 ( struct V_9 * V_10 , int V_110 , int V_111 )
{
struct V_46 * V_47 = V_10 -> V_47 ;
switch ( V_47 -> V_71 ) {
case V_89 :
return F_28 ( V_10 , V_110 , V_111 ) ;
case V_95 :
return F_29 ( V_10 , V_110 , V_111 ) ;
default:
break;
}
return 0 ;
}
static int F_31 ( void * V_116 , int V_117 ,
int V_110 , int V_111 )
{
struct V_3 * V_42 = V_116 ;
struct V_9 * V_10 = F_16 ( V_42 ) ;
F_9 ( & V_10 -> V_26 -> V_29 , L_25 ,
V_30 , V_117 , V_110 , V_111 ) ;
switch ( V_117 ) {
case V_118 :
return F_30 ( V_10 , V_110 , V_111 ) ;
default:
break;
}
return 0 ;
}
static int F_32 ( struct V_101 * V_42 )
{
int V_13 ;
struct V_9 * V_10 = F_25 ( V_42 ) ;
struct V_46 * V_47 = F_21 ( V_10 ) ;
const struct V_5 * V_5 ;
F_9 ( & V_10 -> V_26 -> V_29 , L_3 , V_30 ) ;
switch ( V_47 -> V_71 ) {
case V_89 :
V_5 = & V_119 ;
break;
case V_90 :
V_5 = & V_120 ;
break;
case V_92 :
V_5 = & V_119 ;
break;
case V_95 :
V_5 = & V_121 ;
break;
case V_97 :
V_5 = & V_122 ;
break;
case V_99 :
case V_100 :
V_5 = & V_123 ;
break;
default:
F_26 ( & V_10 -> V_26 -> V_29 , L_23 ,
V_106 , V_47 -> V_70 ) ;
V_13 = - V_107 ;
goto V_20;
}
V_42 -> V_2 [ 0 ] = F_27 ( V_124 , V_5 , & V_10 -> V_109 ) ;
if ( ! V_42 -> V_2 [ 0 ] ) {
V_13 = - V_107 ;
goto V_20;
}
V_47 -> V_125 = F_33 ( V_42 -> V_2 [ 0 ] ) ;
V_42 -> V_2 [ 0 ] -> V_126 = F_31 ;
return 0 ;
V_20:
F_9 ( & V_10 -> V_26 -> V_29 , L_1 , V_30 , V_13 ) ;
return V_13 ;
}
static int F_34 ( struct V_101 * V_42 )
{
int V_13 ;
struct V_9 * V_10 = F_25 ( V_42 ) ;
struct V_46 * V_47 = F_21 ( V_10 ) ;
struct V_3 * V_127 ;
struct V_1 * V_2 ;
F_9 ( & V_10 -> V_26 -> V_29 , L_3 , V_30 ) ;
V_127 = F_35 ( V_42 -> V_2 [ 0 ] ) ;
switch ( V_47 -> V_71 ) {
case V_72 :
V_2 = F_27 ( V_128 , V_42 -> V_2 [ 0 ] ,
V_127 , & V_129 ) ;
break;
case V_74 :
V_2 = F_27 ( V_130 , V_42 -> V_2 [ 0 ] ,
V_127 , & V_131 ,
1220 ) ;
break;
case V_75 :
V_2 = F_27 ( V_132 , V_42 -> V_2 [ 0 ] ,
V_127 , & V_133 ) ;
break;
default:
V_2 = NULL ;
F_26 ( & V_10 -> V_26 -> V_29 , L_26 , V_106 ,
V_47 -> V_71 ) ;
}
if ( V_2 == NULL ) {
V_13 = - V_107 ;
goto V_20;
}
return 0 ;
V_20:
F_9 ( & V_10 -> V_26 -> V_29 , L_1 , V_30 , V_13 ) ;
return V_13 ;
}
static int F_36 ( struct V_101 * V_42 )
{
int V_13 ;
struct V_9 * V_10 = F_25 ( V_42 ) ;
struct V_46 * V_47 = F_21 ( V_10 ) ;
struct V_1 * V_2 = NULL ;
struct V_134 V_135 ;
struct V_136 * V_137 ;
F_9 ( & V_10 -> V_26 -> V_29 , L_3 , V_30 ) ;
memset ( & V_135 , 0 , sizeof( struct V_134 ) ) ;
switch ( V_47 -> V_71 ) {
case V_89 :
V_2 = F_27 ( V_138 , V_42 -> V_2 [ 0 ] ,
& V_10 -> V_109 , & V_139 ) ;
V_42 -> V_2 [ 0 ] -> V_140 . V_141 =
V_42 -> V_2 [ 0 ] -> V_140 . V_142 . V_143 ;
F_37 ( F_1 , V_42 -> V_2 [ 0 ] , & V_10 -> V_109 ,
& V_119 , NULL ) ;
break;
case V_90 :
V_2 = F_27 ( V_144 , V_42 -> V_2 [ 0 ] ,
& V_10 -> V_109 , 0xc6 >> 1 , 0 , V_145 ) ;
V_42 -> V_2 [ 0 ] -> V_140 . V_141 =
V_42 -> V_2 [ 0 ] -> V_140 . V_142 . V_143 ;
F_37 ( F_1 , V_42 -> V_2 [ 0 ] , & V_10 -> V_109 ,
& V_120 , NULL ) ;
break;
case V_97 : {
struct V_7 * V_8 ;
struct V_3 * V_146 =
F_38 ( V_42 -> V_2 [ 0 ] ) ;
struct V_147 V_147 = {
. V_2 = V_42 -> V_2 [ 0 ] ,
. clock = 28800000 ,
} ;
F_39 ( V_135 . type , L_27 , V_148 ) ;
V_135 . V_54 = 0x64 ;
V_135 . V_149 = & V_147 ;
F_40 ( V_135 . type ) ;
V_137 = F_41 ( V_47 -> V_125 , & V_135 ) ;
if ( V_137 == NULL || V_137 -> V_29 . V_150 == NULL )
break;
if ( ! F_42 ( V_137 -> V_29 . V_150 -> V_151 ) ) {
F_43 ( V_137 ) ;
break;
}
V_47 -> V_137 = V_137 ;
V_8 = F_44 ( V_137 ) ;
F_45 ( V_146 , V_10 ) ;
F_37 ( F_1 , V_42 -> V_2 [ 0 ] ,
V_146 ,
& V_122 , V_8 ) ;
}
break;
case V_92 :
V_2 = F_27 ( V_152 , V_42 -> V_2 [ 0 ] , & V_10 -> V_109 ,
& V_153 ) ;
break;
case V_95 :
V_13 = F_14 ( V_10 , V_68 , 0x00 , 0x12 ) ;
if ( V_13 )
goto V_20;
V_13 = F_14 ( V_10 , V_69 , 0x12 , 0x12 ) ;
if ( V_13 )
goto V_20;
V_2 = F_27 ( V_154 , V_42 -> V_2 [ 0 ] , & V_10 -> V_109 ,
& V_155 ) ;
break;
case V_99 :
V_2 = F_27 ( V_156 , V_42 -> V_2 [ 0 ] , & V_10 -> V_109 ,
& V_157 ) ;
V_42 -> V_2 [ 0 ] -> V_140 . V_141 =
V_42 -> V_2 [ 0 ] -> V_140 . V_142 . V_143 ;
F_37 ( F_1 , V_42 -> V_2 [ 0 ] , & V_10 -> V_109 ,
& V_123 , NULL ) ;
break;
case V_100 :
V_13 = F_14 ( V_10 , V_113 , 0x00 , 0x01 ) ;
if ( V_13 )
goto V_20;
V_13 = F_14 ( V_10 , V_68 , 0x00 , 0x01 ) ;
if ( V_13 )
goto V_20;
V_13 = F_14 ( V_10 , V_69 , 0x01 , 0x01 ) ;
if ( V_13 )
goto V_20;
V_2 = F_27 ( V_156 , V_42 -> V_2 [ 0 ] , & V_10 -> V_109 ,
& V_158 ) ;
V_42 -> V_2 [ 0 ] -> V_140 . V_141 =
V_42 -> V_2 [ 0 ] -> V_140 . V_142 . V_143 ;
break;
default:
F_26 ( & V_10 -> V_26 -> V_29 , L_26 , V_106 ,
V_47 -> V_71 ) ;
}
if ( V_2 == NULL && V_47 -> V_137 == NULL ) {
V_13 = - V_107 ;
goto V_20;
}
return 0 ;
V_20:
F_9 ( & V_10 -> V_26 -> V_29 , L_1 , V_30 , V_13 ) ;
return V_13 ;
}
static int F_46 ( struct V_9 * V_10 )
{
int V_13 ;
T_1 V_32 ;
F_9 ( & V_10 -> V_26 -> V_29 , L_3 , V_30 ) ;
V_13 = F_13 ( V_10 , V_159 , & V_32 ) ;
if ( V_13 )
goto V_20;
V_32 |= 0x09 ;
V_13 = F_12 ( V_10 , V_159 , V_32 ) ;
if ( V_13 )
goto V_20;
V_13 = F_10 ( V_10 , V_160 , L_28 , 4 ) ;
if ( V_13 )
goto V_20;
V_13 = F_10 ( V_10 , V_161 , L_29 , 4 ) ;
if ( V_13 )
goto V_20;
return V_13 ;
V_20:
F_9 ( & V_10 -> V_26 -> V_29 , L_1 , V_30 , V_13 ) ;
return V_13 ;
}
static void F_47 ( struct V_9 * V_10 )
{
struct V_46 * V_47 = V_10 -> V_47 ;
struct V_136 * V_137 = V_47 -> V_137 ;
F_9 ( & V_10 -> V_26 -> V_29 , L_3 , V_30 ) ;
if ( V_137 ) {
F_48 ( V_137 -> V_29 . V_150 -> V_151 ) ;
F_43 ( V_137 ) ;
}
return;
}
static int F_49 ( struct V_9 * V_10 , int V_162 )
{
int V_13 ;
T_1 V_163 , V_164 , V_165 [ 2 ] ;
F_9 ( & V_10 -> V_26 -> V_29 , L_30 , V_30 , V_162 ) ;
V_13 = F_13 ( V_10 , V_166 , & V_164 ) ;
if ( V_13 )
goto V_20;
V_13 = F_13 ( V_10 , V_113 , & V_163 ) ;
if ( V_13 )
goto V_20;
F_9 ( & V_10 -> V_26 -> V_29 , L_31 , V_30 ,
V_164 , V_163 ) ;
if ( V_162 ) {
V_163 |= 0x01 ;
V_163 &= ( ~ 0x10 ) ;
V_163 |= 0x04 ;
V_164 = V_164 & 0x0f ;
V_164 |= 0xe0 ;
V_165 [ 0 ] = 0x00 ;
V_165 [ 1 ] = 0x00 ;
} else {
V_163 &= ( ~ 0x01 ) ;
V_163 |= 0x10 ;
V_163 &= ( ~ 0x04 ) ;
V_164 = V_164 & ( ~ 0xc0 ) ;
V_165 [ 0 ] = 0x10 ;
V_165 [ 1 ] = 0x02 ;
}
F_9 ( & V_10 -> V_26 -> V_29 , L_32 , V_30 ,
V_164 , V_163 ) ;
V_13 = F_12 ( V_10 , V_166 , V_164 ) ;
if ( V_13 )
goto V_20;
V_13 = F_12 ( V_10 , V_113 , V_163 ) ;
if ( V_13 )
goto V_20;
V_13 = F_10 ( V_10 , V_167 , V_165 , 2 ) ;
if ( V_13 )
goto V_20;
if ( V_162 )
F_50 ( V_10 -> V_26 , F_51 ( V_10 -> V_26 , 0x81 ) ) ;
return V_13 ;
V_20:
F_9 ( & V_10 -> V_26 -> V_29 , L_1 , V_30 , V_13 ) ;
return V_13 ;
}
static int F_52 ( struct V_9 * V_10 , int V_162 )
{
int V_13 ;
F_9 ( & V_10 -> V_26 -> V_29 , L_30 , V_30 , V_162 ) ;
if ( V_162 ) {
V_13 = F_14 ( V_10 , V_113 , 0x08 , 0x18 ) ;
if ( V_13 )
goto V_20;
V_13 = F_14 ( V_10 , V_168 , 0x00 , 0x10 ) ;
if ( V_13 )
goto V_20;
V_13 = F_14 ( V_10 , V_169 , 0x80 , 0x80 ) ;
if ( V_13 )
goto V_20;
V_13 = F_14 ( V_10 , V_169 , 0x20 , 0x20 ) ;
if ( V_13 )
goto V_20;
F_53 ( 5 ) ;
V_13 = F_14 ( V_10 , V_169 , 0x48 , 0x48 ) ;
if ( V_13 )
goto V_20;
V_13 = F_10 ( V_10 , V_167 , L_33 , 2 ) ;
if ( V_13 )
goto V_20;
V_13 = F_50 ( V_10 -> V_26 , F_51 ( V_10 -> V_26 , 0x81 ) ) ;
if ( V_13 )
goto V_20;
} else {
V_13 = F_14 ( V_10 , V_113 , 0x10 , 0x10 ) ;
if ( V_13 )
goto V_20;
V_13 = F_14 ( V_10 , V_169 , 0x00 , 0x48 ) ;
if ( V_13 )
goto V_20;
V_13 = F_14 ( V_10 , V_169 , 0x00 , 0x80 ) ;
if ( V_13 )
goto V_20;
V_13 = F_10 ( V_10 , V_167 , L_34 , 2 ) ;
if ( V_13 )
goto V_20;
}
return V_13 ;
V_20:
F_9 ( & V_10 -> V_26 -> V_29 , L_1 , V_30 , V_13 ) ;
return V_13 ;
}
static int F_54 ( struct V_9 * V_10 )
{
int V_13 , V_170 ;
struct V_46 * V_47 = V_10 -> V_47 ;
T_1 V_16 [ 5 ] ;
T_3 V_171 ;
struct V_172 V_173 [] = {
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
if ( ! V_47 -> V_174 ) {
for ( V_170 = 0 ; V_170 < F_55 ( V_173 ) ; V_170 ++ ) {
V_13 = F_12 ( V_10 , V_173 [ V_170 ] . V_31 ,
V_173 [ V_170 ] . V_32 ) ;
if ( V_13 )
goto V_20;
}
V_47 -> V_174 = true ;
}
V_13 = F_11 ( V_10 , V_175 , V_16 , 5 ) ;
if ( V_13 )
goto V_20;
if ( V_16 [ 4 ] & 0x01 ) {
if ( V_16 [ 2 ] == ( T_1 ) ~ V_16 [ 3 ] ) {
if ( V_16 [ 0 ] == ( T_1 ) ~ V_16 [ 1 ] ) {
V_171 = F_56 ( V_16 [ 0 ] , V_16 [ 2 ] ) ;
} else {
V_171 = F_57 ( V_16 [ 0 ] << 8 | V_16 [ 1 ] ,
V_16 [ 2 ] ) ;
}
} else {
V_171 = F_58 ( V_16 [ 0 ] << 24 | V_16 [ 1 ] << 16 |
V_16 [ 2 ] << 8 | V_16 [ 3 ] ) ;
}
F_59 ( V_10 -> V_176 , V_177 , V_171 , 0 ) ;
V_13 = F_12 ( V_10 , V_178 , 1 ) ;
if ( V_13 )
goto V_20;
V_13 = F_12 ( V_10 , V_178 , 1 ) ;
if ( V_13 )
goto V_20;
}
return V_13 ;
V_20:
F_9 ( & V_10 -> V_26 -> V_29 , L_1 , V_30 , V_13 ) ;
return V_13 ;
}
static int F_60 ( struct V_9 * V_10 ,
struct V_179 * V_180 )
{
V_180 -> V_181 = V_182 ;
V_180 -> V_183 = V_184 ;
V_180 -> V_185 = F_54 ;
V_180 -> V_186 = 400 ;
return 0 ;
}
static int F_61 ( struct V_9 * V_10 )
{
int V_13 , V_170 , V_33 ;
struct V_46 * V_47 = V_10 -> V_47 ;
struct V_187 V_188 ;
T_1 V_16 [ 128 ] ;
static const struct V_189 V_190 [] = {
{ V_191 , 0x03 , 0xff } ,
{ V_192 , 0x80 , 0xff } ,
{ V_193 , 0x80 , 0xff } ,
} ;
if ( ! V_47 -> V_174 ) {
static const struct V_189 V_194 [] = {
{ V_168 , 0x00 , 0x04 } ,
{ V_168 , 0x00 , 0x08 } ,
{ V_195 , 0x20 , 0x20 } ,
{ V_68 , 0x00 , 0x08 } ,
{ V_69 , 0x08 , 0x08 } ,
{ V_113 , 0x08 , 0x08 } ,
{ V_196 , 0xd0 , 0xff } ,
{ V_197 , 0x07 , 0xff } ,
{ V_198 , 0xc0 , 0xff } ,
{ V_199 , 0x00 , 0xff } ,
{ V_200 , 0x03 , 0xff } ,
{ V_201 , 0x09 , 0xff } ,
{ V_202 , 0x1c , 0xff } ,
{ V_203 , 0x1e , 0xff } ,
{ V_204 , 0x1e , 0xff } ,
{ V_193 , 0x80 , 0xff } ,
} ;
for ( V_170 = 0 ; V_170 < F_55 ( V_194 ) ; V_170 ++ ) {
V_13 = F_14 ( V_10 , V_194 [ V_170 ] . V_31 ,
V_194 [ V_170 ] . V_32 , V_194 [ V_170 ] . V_40 ) ;
if ( V_13 )
goto V_20;
}
V_47 -> V_174 = true ;
}
V_13 = F_13 ( V_10 , V_191 , & V_16 [ 0 ] ) ;
if ( V_13 )
goto V_20;
if ( V_16 [ 0 ] != 0x83 )
goto exit;
V_13 = F_13 ( V_10 , V_205 , & V_16 [ 0 ] ) ;
if ( V_13 )
goto V_20;
V_33 = V_16 [ 0 ] ;
V_13 = F_11 ( V_10 , V_206 , V_16 , V_33 ) ;
if ( V_13 )
goto V_20;
for ( V_170 = 0 ; V_170 < F_55 ( V_190 ) ; V_170 ++ ) {
V_13 = F_14 ( V_10 , V_190 [ V_170 ] . V_31 ,
V_190 [ V_170 ] . V_32 , V_190 [ V_170 ] . V_40 ) ;
if ( V_13 )
goto V_20;
}
F_62 ( & V_188 ) ;
for ( V_170 = 0 ; V_170 < V_33 ; V_170 ++ ) {
V_188 . V_207 = V_16 [ V_170 ] >> 7 ;
V_188 . V_208 = 50800 * ( V_16 [ V_170 ] & 0x7f ) ;
F_63 ( V_10 -> V_176 , & V_188 ) ;
}
F_64 ( V_10 -> V_176 , true ) ;
F_65 ( V_10 -> V_176 ) ;
exit:
return V_13 ;
V_20:
F_9 ( & V_10 -> V_26 -> V_29 , L_1 , V_30 , V_13 ) ;
return V_13 ;
}
static int F_66 ( struct V_9 * V_10 ,
struct V_179 * V_180 )
{
if ( V_209 )
return F_12 ( V_10 , V_210 , 0x00 ) ;
if ( ! V_180 -> V_181 )
V_180 -> V_181 = V_182 ;
V_180 -> V_183 = V_211 ;
V_180 -> V_212 = V_213 ;
V_180 -> V_185 = F_61 ;
V_180 -> V_186 = 400 ;
return 0 ;
}
