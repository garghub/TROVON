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
F_6 ( V_2 -> V_18 , 0 , V_7 , V_4 -> V_20 ,
V_4 -> V_13 , V_8 , V_4 -> V_9 ) ;
if ( V_5 > 0 )
V_5 = 0 ;
if ( ! V_5 && V_7 == ( V_16 | V_19 ) )
memcpy ( V_4 -> V_15 , V_8 , V_4 -> V_9 ) ;
F_7 ( V_8 ) ;
if ( V_5 )
goto V_12;
return V_5 ;
V_12:
F_8 ( & V_2 -> V_18 -> V_21 , L_1 , V_22 , V_5 ) ;
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
static int F_13 ( struct V_1 * V_2 , T_2 V_23 , T_1 V_24 ,
T_1 V_32 )
{
int V_5 ;
T_1 V_33 ;
if ( V_32 != 0xff ) {
V_5 = F_12 ( V_2 , V_23 , & V_33 ) ;
if ( V_5 )
return V_5 ;
V_24 &= V_32 ;
V_33 &= ~ V_32 ;
V_24 |= V_33 ;
}
return F_11 ( V_2 , V_23 , V_24 ) ;
}
static int F_14 ( struct V_34 * V_35 , struct V_36 V_37 [] ,
int V_38 )
{
int V_5 ;
struct V_1 * V_2 = F_15 ( V_35 ) ;
struct V_39 * V_40 = V_2 -> V_40 ;
struct V_3 V_4 ;
if ( F_16 ( & V_2 -> V_41 ) < 0 )
return - V_42 ;
if ( V_38 == 2 && ! ( V_37 [ 0 ] . V_43 & V_44 ) &&
( V_37 [ 1 ] . V_43 & V_44 ) ) {
if ( V_37 [ 0 ] . V_25 > 24 || V_37 [ 1 ] . V_25 > 24 ) {
V_5 = - V_45 ;
goto V_46;
} else if ( V_37 [ 0 ] . V_47 == 0x10 ) {
V_4 . V_20 = ( V_37 [ 0 ] . V_8 [ 0 ] << 8 ) | ( V_37 [ 0 ] . V_47 << 1 ) ;
V_4 . V_13 = V_48 | V_40 -> V_49 ;
V_4 . V_9 = V_37 [ 1 ] . V_25 ;
V_4 . V_15 = & V_37 [ 1 ] . V_8 [ 0 ] ;
V_5 = F_1 ( V_2 , & V_4 ) ;
} else if ( V_37 [ 0 ] . V_25 < 2 ) {
V_4 . V_20 = ( V_37 [ 0 ] . V_8 [ 0 ] << 8 ) | ( V_37 [ 0 ] . V_47 << 1 ) ;
V_4 . V_13 = V_50 ;
V_4 . V_9 = V_37 [ 1 ] . V_25 ;
V_4 . V_15 = & V_37 [ 1 ] . V_8 [ 0 ] ;
V_5 = F_1 ( V_2 , & V_4 ) ;
} else {
V_4 . V_20 = ( V_37 [ 0 ] . V_47 << 1 ) ;
V_4 . V_13 = V_51 ;
V_4 . V_9 = V_37 [ 0 ] . V_25 ;
V_4 . V_15 = V_37 [ 0 ] . V_8 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 )
goto V_46;
V_4 . V_20 = ( V_37 [ 0 ] . V_47 << 1 ) ;
V_4 . V_13 = V_52 ;
V_4 . V_9 = V_37 [ 1 ] . V_25 ;
V_4 . V_15 = V_37 [ 1 ] . V_8 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
}
} else if ( V_38 == 1 && ! ( V_37 [ 0 ] . V_43 & V_44 ) ) {
if ( V_37 [ 0 ] . V_25 > 22 ) {
V_5 = - V_45 ;
goto V_46;
} else if ( V_37 [ 0 ] . V_47 == 0x10 ) {
if ( V_37 [ 0 ] . V_8 [ 0 ] == 0x00 ) {
V_40 -> V_49 = V_37 [ 0 ] . V_8 [ 1 ] ;
V_5 = 0 ;
} else {
V_4 . V_20 = ( V_37 [ 0 ] . V_8 [ 0 ] << 8 ) |
( V_37 [ 0 ] . V_47 << 1 ) ;
V_4 . V_13 = V_53 | V_40 -> V_49 ;
V_4 . V_9 = V_37 [ 0 ] . V_25 - 1 ;
V_4 . V_15 = & V_37 [ 0 ] . V_8 [ 1 ] ;
V_5 = F_1 ( V_2 , & V_4 ) ;
}
} else if ( V_37 [ 0 ] . V_25 < 23 ) {
V_4 . V_20 = ( V_37 [ 0 ] . V_8 [ 0 ] << 8 ) | ( V_37 [ 0 ] . V_47 << 1 ) ;
V_4 . V_13 = V_54 ;
V_4 . V_9 = V_37 [ 0 ] . V_25 - 1 ;
V_4 . V_15 = & V_37 [ 0 ] . V_8 [ 1 ] ;
V_5 = F_1 ( V_2 , & V_4 ) ;
} else {
V_4 . V_20 = ( V_37 [ 0 ] . V_47 << 1 ) ;
V_4 . V_13 = V_51 ;
V_4 . V_9 = V_37 [ 0 ] . V_25 ;
V_4 . V_15 = V_37 [ 0 ] . V_8 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
}
} else {
V_5 = - V_55 ;
}
V_46:
F_17 ( & V_2 -> V_41 ) ;
return V_5 ? V_5 : V_38 ;
}
static T_3 F_18 ( struct V_34 * V_56 )
{
return V_57 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_20 ( V_2 ) ;
int V_5 ;
T_1 V_8 [ 1 ] ;
struct V_3 V_58 = { 0x0120 , 0x0011 , 0x0001 , L_2 } ;
struct V_3 V_59 = { 0x00c0 , V_50 , 1 , V_8 } ;
struct V_3 V_60 = { 0x0fc4 , V_50 , 1 , V_8 } ;
F_8 ( & V_2 -> V_18 -> V_21 , L_3 , V_22 ) ;
V_5 = F_11 ( V_2 , V_61 , 0x0a ) ;
if ( V_5 )
goto V_12;
V_5 = F_11 ( V_2 , V_62 , 0x15 ) ;
if ( V_5 )
goto V_12;
F_21 ( 20 ) ;
V_40 -> V_63 = L_4 ;
V_5 = F_1 ( V_2 , & V_58 ) ;
if ( V_5 )
goto V_12;
V_5 = F_1 ( V_2 , & V_60 ) ;
if ( V_5 == 0 && V_8 [ 0 ] == 0x2c ) {
V_40 -> V_64 = V_65 ;
V_40 -> V_63 = L_5 ;
goto V_66;
}
V_5 = F_1 ( V_2 , & V_58 ) ;
if ( V_5 )
goto V_12;
V_5 = F_1 ( V_2 , & V_59 ) ;
if ( V_5 == 0 && V_8 [ 0 ] == 0x63 ) {
V_40 -> V_64 = V_67 ;
V_40 -> V_63 = L_6 ;
goto V_66;
}
V_40 -> V_64 = V_68 ;
V_40 -> V_63 = L_7 ;
goto V_66;
V_66:
F_8 ( & V_2 -> V_18 -> V_21 , L_8 , V_22 , V_40 -> V_63 ) ;
return 0 ;
V_12:
F_8 ( & V_2 -> V_18 -> V_21 , L_1 , V_22 , V_5 ) ;
return V_5 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_20 ( V_2 ) ;
int V_5 ;
T_1 V_8 [ 2 ] ;
struct V_3 V_58 = { 0x0120 , 0x0011 , 0x0001 , L_9 } ;
struct V_3 V_69 = { 0x0120 , 0x0011 , 0x0001 , L_10 } ;
struct V_3 V_70 = { 0x00c6 , V_50 , 1 , V_8 } ;
struct V_3 V_71 = { 0x00c6 , V_50 , 1 , V_8 } ;
struct V_3 V_72 = { 0x00c0 , V_50 , 1 , V_8 } ;
struct V_3 V_73 = { 0x01ac , V_50 , 1 , V_8 } ;
struct V_3 V_74 = { 0x00c0 , V_50 , 1 , V_8 } ;
struct V_3 V_75 = { 0x00c0 , V_50 , 1 , V_8 } ;
struct V_3 V_76 = { 0x7ec0 , V_50 , 2 , V_8 } ;
struct V_3 V_77 = { 0xd9c0 , V_50 , 1 , V_8 } ;
struct V_3 V_78 = { 0x02c8 , V_50 , 1 , V_8 } ;
struct V_3 V_79 = { 0x00c0 , V_50 , 2 , V_8 } ;
struct V_3 V_80 = { 0x0034 , V_50 , 1 , V_8 } ;
F_8 ( & V_2 -> V_18 -> V_21 , L_3 , V_22 ) ;
V_5 = F_13 ( V_2 , V_61 , 0x00 , 0x40 ) ;
if ( V_5 )
goto V_12;
V_5 = F_13 ( V_2 , V_62 , 0x48 , 0x48 ) ;
if ( V_5 )
goto V_12;
V_5 = F_1 ( V_2 , & V_58 ) ;
if ( V_5 )
goto V_12;
V_40 -> V_63 = L_4 ;
V_5 = F_1 ( V_2 , & V_70 ) ;
if ( V_5 == 0 && V_8 [ 0 ] == 0xa1 ) {
V_40 -> V_64 = V_81 ;
V_40 -> V_63 = L_11 ;
goto V_66;
}
V_5 = F_1 ( V_2 , & V_71 ) ;
if ( V_5 == 0 && V_8 [ 0 ] == 0xa3 ) {
V_40 -> V_64 = V_82 ;
V_40 -> V_63 = L_12 ;
goto V_66;
}
V_5 = F_1 ( V_2 , & V_72 ) ;
if ( V_5 == 0 && V_8 [ 0 ] == 0x85 ) {
V_40 -> V_64 = V_83 ;
V_40 -> V_63 = L_13 ;
goto V_66;
}
V_5 = F_1 ( V_2 , & V_73 ) ;
if ( V_5 == 0 && V_8 [ 0 ] == 0x56 ) {
V_40 -> V_64 = V_84 ;
V_40 -> V_63 = L_14 ;
goto V_66;
}
V_5 = F_1 ( V_2 , & V_74 ) ;
if ( V_5 == 0 && ( V_8 [ 0 ] == 0x9e || V_8 [ 0 ] == 0x9c ) ) {
V_40 -> V_64 = V_85 ;
V_40 -> V_63 = L_15 ;
goto V_66;
}
V_5 = F_1 ( V_2 , & V_75 ) ;
if ( V_5 == 0 && V_8 [ 0 ] == 0x38 ) {
V_40 -> V_64 = V_86 ;
V_40 -> V_63 = L_16 ;
goto V_66;
}
V_5 = F_1 ( V_2 , & V_76 ) ;
if ( V_5 == 0 && V_8 [ 0 ] == 0x23 && V_8 [ 1 ] == 0x28 ) {
V_40 -> V_64 = V_87 ;
V_40 -> V_63 = L_17 ;
goto V_66;
}
V_5 = F_1 ( V_2 , & V_77 ) ;
if ( V_5 == 0 && V_8 [ 0 ] == 0x14 ) {
V_40 -> V_64 = V_88 ;
V_40 -> V_63 = L_18 ;
goto V_66;
}
V_5 = F_1 ( V_2 , & V_78 ) ;
if ( V_5 == 0 && V_8 [ 0 ] == 0x40 ) {
V_40 -> V_64 = V_89 ;
V_40 -> V_63 = L_19 ;
goto V_66;
}
V_5 = F_1 ( V_2 , & V_79 ) ;
if ( V_5 == 0 && ( V_8 [ 0 ] == 0xc7 || V_8 [ 1 ] == 0x60 ) ) {
V_40 -> V_64 = V_90 ;
V_40 -> V_63 = L_20 ;
goto V_66;
}
V_5 = F_1 ( V_2 , & V_80 ) ;
if ( V_5 == 0 && V_8 [ 0 ] == 0x69 ) {
V_40 -> V_64 = V_91 ;
V_40 -> V_63 = L_21 ;
goto V_66;
}
V_66:
F_8 ( & V_2 -> V_18 -> V_21 , L_8 , V_22 , V_40 -> V_63 ) ;
V_5 = F_1 ( V_2 , & V_69 ) ;
if ( V_5 < 0 )
goto V_12;
return 0 ;
V_12:
F_8 ( & V_2 -> V_18 -> V_21 , L_1 , V_22 , V_5 ) ;
return V_5 ;
}
static int F_23 ( struct V_92 * V_35 )
{
struct V_1 * V_2 = F_24 ( V_35 ) ;
struct V_39 * V_40 = F_20 ( V_2 ) ;
struct V_93 * V_93 ;
int V_5 ;
F_8 ( & V_2 -> V_18 -> V_21 , L_3 , V_22 ) ;
switch ( V_40 -> V_64 ) {
case V_65 :
V_93 = & V_94 ;
break;
case V_67 :
V_93 = & V_95 ;
break;
case V_68 :
V_93 = & V_96 ;
break;
default:
F_25 ( & V_2 -> V_18 -> V_21 , L_22 ,
V_97 , V_40 -> V_63 ) ;
V_5 = - V_98 ;
goto V_12;
}
V_35 -> V_99 [ 0 ] = F_26 ( V_100 , V_93 , & V_2 -> V_101 ) ;
if ( ! V_35 -> V_99 [ 0 ] ) {
V_5 = - V_98 ;
goto V_12;
}
return 0 ;
V_12:
F_8 ( & V_2 -> V_18 -> V_21 , L_1 , V_22 , V_5 ) ;
return V_5 ;
}
static int F_27 ( struct V_1 * V_2 ,
int V_102 , int V_103 )
{
int V_5 ;
T_1 V_24 ;
F_8 ( & V_2 -> V_18 -> V_21 , L_23 , V_22 , V_102 , V_103 ) ;
switch ( V_102 ) {
case V_104 :
V_5 = F_12 ( V_2 , V_105 , & V_24 ) ;
if ( V_5 )
goto V_12;
if ( V_103 )
V_24 &= 0xbf ;
else
V_24 |= 0x40 ;
V_5 = F_11 ( V_2 , V_105 , V_24 ) ;
if ( V_5 )
goto V_12;
break;
default:
V_5 = - V_55 ;
goto V_12;
}
return 0 ;
V_12:
F_8 ( & V_2 -> V_18 -> V_21 , L_1 , V_22 , V_5 ) ;
return V_5 ;
}
static int F_28 ( struct V_1 * V_2 ,
int V_102 , int V_103 )
{
int V_5 ;
T_1 V_24 ;
F_8 ( & V_2 -> V_18 -> V_21 , L_23 , V_22 , V_102 , V_103 ) ;
switch ( V_102 ) {
case V_106 :
if ( V_103 )
V_24 = ( 1 << 4 ) ;
else
V_24 = ( 0 << 4 ) ;
V_5 = F_13 ( V_2 , V_105 , V_24 , 0x10 ) ;
if ( V_5 )
goto V_12;
break;
case V_107 :
if ( V_103 )
V_24 = ( 1 << 1 ) ;
else
V_24 = ( 0 << 1 ) ;
V_5 = F_13 ( V_2 , V_105 , V_24 , 0x02 ) ;
if ( V_5 )
goto V_12;
break;
}
return 0 ;
V_12:
F_8 ( & V_2 -> V_18 -> V_21 , L_1 , V_22 , V_5 ) ;
return V_5 ;
}
static int F_29 ( struct V_1 * V_2 , int V_102 , int V_103 )
{
struct V_39 * V_40 = V_2 -> V_40 ;
switch ( V_40 -> V_64 ) {
case V_81 :
return F_27 ( V_2 , V_102 , V_103 ) ;
case V_87 :
return F_28 ( V_2 , V_102 , V_103 ) ;
default:
break;
}
return 0 ;
}
static int F_30 ( void * V_108 , int V_109 ,
int V_102 , int V_103 )
{
struct V_34 * V_35 = V_108 ;
struct V_1 * V_2 = F_15 ( V_35 ) ;
F_8 ( & V_2 -> V_18 -> V_21 , L_24 ,
V_22 , V_109 , V_102 , V_103 ) ;
switch ( V_109 ) {
case V_110 :
return F_29 ( V_2 , V_102 , V_103 ) ;
default:
break;
}
return 0 ;
}
static int F_31 ( struct V_92 * V_35 )
{
int V_5 ;
struct V_1 * V_2 = F_24 ( V_35 ) ;
struct V_39 * V_40 = F_20 ( V_2 ) ;
struct V_111 * V_111 ;
F_8 ( & V_2 -> V_18 -> V_21 , L_3 , V_22 ) ;
switch ( V_40 -> V_64 ) {
case V_81 :
V_111 = & V_112 ;
break;
case V_82 :
V_111 = & V_113 ;
break;
case V_84 :
V_111 = & V_112 ;
break;
case V_87 :
V_111 = & V_114 ;
break;
case V_89 :
V_111 = & V_115 ;
break;
case V_91 :
V_111 = & V_116 ;
break;
default:
F_25 ( & V_2 -> V_18 -> V_21 , L_22 ,
V_97 , V_40 -> V_63 ) ;
V_5 = - V_98 ;
goto V_12;
}
V_35 -> V_99 [ 0 ] = F_26 ( V_117 , V_111 , & V_2 -> V_101 ) ;
if ( ! V_35 -> V_99 [ 0 ] ) {
V_5 = - V_98 ;
goto V_12;
}
V_35 -> V_99 [ 0 ] -> V_118 = F_30 ;
return 0 ;
V_12:
F_8 ( & V_2 -> V_18 -> V_21 , L_1 , V_22 , V_5 ) ;
return V_5 ;
}
static int F_32 ( struct V_92 * V_35 )
{
int V_5 ;
struct V_1 * V_2 = F_24 ( V_35 ) ;
struct V_39 * V_40 = F_20 ( V_2 ) ;
struct V_34 * V_119 ;
struct V_120 * V_99 ;
F_8 ( & V_2 -> V_18 -> V_21 , L_3 , V_22 ) ;
V_119 = F_33 ( V_35 -> V_99 [ 0 ] ) ;
switch ( V_40 -> V_64 ) {
case V_65 :
V_99 = F_26 ( V_121 , V_35 -> V_99 [ 0 ] ,
V_119 , & V_122 ) ;
break;
case V_67 :
V_99 = F_26 ( V_123 , V_35 -> V_99 [ 0 ] ,
V_119 , & V_124 ,
1220 ) ;
break;
case V_68 :
V_99 = F_26 ( V_125 , V_35 -> V_99 [ 0 ] ,
V_119 , & V_126 ) ;
break;
default:
V_99 = NULL ;
F_25 ( & V_2 -> V_18 -> V_21 , L_25 , V_97 ,
V_40 -> V_64 ) ;
}
if ( V_99 == NULL ) {
V_5 = - V_98 ;
goto V_12;
}
return 0 ;
V_12:
F_8 ( & V_2 -> V_18 -> V_21 , L_1 , V_22 , V_5 ) ;
return V_5 ;
}
static int F_34 ( struct V_92 * V_35 )
{
int V_5 ;
struct V_1 * V_2 = F_24 ( V_35 ) ;
struct V_39 * V_40 = F_20 ( V_2 ) ;
struct V_120 * V_99 ;
F_8 ( & V_2 -> V_18 -> V_21 , L_3 , V_22 ) ;
switch ( V_40 -> V_64 ) {
case V_81 :
V_99 = F_26 ( V_127 , V_35 -> V_99 [ 0 ] ,
& V_2 -> V_101 , & V_128 ) ;
V_35 -> V_99 [ 0 ] -> V_129 . V_130 =
V_35 -> V_99 [ 0 ] -> V_129 . V_131 . V_132 ;
return 0 ;
break;
case V_82 :
V_99 = F_26 ( V_133 , V_35 -> V_99 [ 0 ] ,
& V_2 -> V_101 , 0xc6 >> 1 , 0 , V_134 ) ;
V_35 -> V_99 [ 0 ] -> V_129 . V_130 =
V_35 -> V_99 [ 0 ] -> V_129 . V_131 . V_132 ;
return 0 ;
case V_89 :
V_99 = F_26 ( V_135 , V_35 -> V_99 [ 0 ] , & V_2 -> V_101 ,
& V_136 ) ;
break;
case V_84 :
V_99 = F_26 ( V_137 , V_35 -> V_99 [ 0 ] , & V_2 -> V_101 ,
& V_138 ) ;
break;
case V_87 :
V_5 = F_13 ( V_2 , V_61 , 0x00 , 0x12 ) ;
if ( V_5 )
goto V_12;
V_5 = F_13 ( V_2 , V_62 , 0x12 , 0x12 ) ;
if ( V_5 )
goto V_12;
V_99 = F_26 ( V_139 , V_35 -> V_99 [ 0 ] , & V_2 -> V_101 ,
& V_140 ) ;
break;
case V_91 :
V_99 = F_26 ( V_141 , V_35 -> V_99 [ 0 ] , & V_2 -> V_101 ,
& V_142 ) ;
V_35 -> V_99 [ 0 ] -> V_129 . V_130 =
V_35 -> V_99 [ 0 ] -> V_129 . V_131 . V_132 ;
break;
default:
V_99 = NULL ;
F_25 ( & V_2 -> V_18 -> V_21 , L_25 , V_97 ,
V_40 -> V_64 ) ;
}
if ( V_99 == NULL ) {
V_5 = - V_98 ;
goto V_12;
}
return 0 ;
V_12:
F_8 ( & V_2 -> V_18 -> V_21 , L_1 , V_22 , V_5 ) ;
return V_5 ;
}
static int F_35 ( struct V_1 * V_2 )
{
int V_5 ;
T_1 V_24 ;
F_8 ( & V_2 -> V_18 -> V_21 , L_3 , V_22 ) ;
V_5 = F_12 ( V_2 , V_143 , & V_24 ) ;
if ( V_5 )
goto V_12;
V_24 |= 0x09 ;
V_5 = F_11 ( V_2 , V_143 , V_24 ) ;
if ( V_5 )
goto V_12;
V_5 = F_9 ( V_2 , V_144 , L_26 , 4 ) ;
if ( V_5 )
goto V_12;
V_5 = F_9 ( V_2 , V_145 , L_27 , 4 ) ;
if ( V_5 )
goto V_12;
return V_5 ;
V_12:
F_8 ( & V_2 -> V_18 -> V_21 , L_1 , V_22 , V_5 ) ;
return V_5 ;
}
static int F_36 ( struct V_1 * V_2 , int V_146 )
{
int V_5 ;
T_1 V_147 , V_148 , V_149 [ 2 ] ;
F_8 ( & V_2 -> V_18 -> V_21 , L_28 , V_22 , V_146 ) ;
V_5 = F_12 ( V_2 , V_150 , & V_148 ) ;
if ( V_5 )
goto V_12;
V_5 = F_12 ( V_2 , V_105 , & V_147 ) ;
if ( V_5 )
goto V_12;
F_8 ( & V_2 -> V_18 -> V_21 , L_29 , V_22 ,
V_148 , V_147 ) ;
if ( V_146 ) {
V_147 |= 0x01 ;
V_147 &= ( ~ 0x10 ) ;
V_147 |= 0x04 ;
V_148 = V_148 & 0x0f ;
V_148 |= 0xe0 ;
V_149 [ 0 ] = 0x00 ;
V_149 [ 1 ] = 0x00 ;
} else {
V_147 &= ( ~ 0x01 ) ;
V_147 |= 0x10 ;
V_147 &= ( ~ 0x04 ) ;
V_148 = V_148 & ( ~ 0xc0 ) ;
V_149 [ 0 ] = 0x10 ;
V_149 [ 1 ] = 0x02 ;
}
F_8 ( & V_2 -> V_18 -> V_21 , L_30 , V_22 ,
V_148 , V_147 ) ;
V_5 = F_11 ( V_2 , V_150 , V_148 ) ;
if ( V_5 )
goto V_12;
V_5 = F_11 ( V_2 , V_105 , V_147 ) ;
if ( V_5 )
goto V_12;
V_5 = F_9 ( V_2 , V_151 , V_149 , 2 ) ;
if ( V_5 )
goto V_12;
if ( V_146 )
F_37 ( V_2 -> V_18 , F_38 ( V_2 -> V_18 , 0x81 ) ) ;
return V_5 ;
V_12:
F_8 ( & V_2 -> V_18 -> V_21 , L_1 , V_22 , V_5 ) ;
return V_5 ;
}
static int F_39 ( struct V_1 * V_2 , int V_146 )
{
int V_5 ;
F_8 ( & V_2 -> V_18 -> V_21 , L_28 , V_22 , V_146 ) ;
if ( V_146 ) {
V_5 = F_13 ( V_2 , V_105 , 0x08 , 0x18 ) ;
if ( V_5 )
goto V_12;
V_5 = F_13 ( V_2 , V_152 , 0x00 , 0x10 ) ;
if ( V_5 )
goto V_12;
V_5 = F_13 ( V_2 , V_153 , 0x80 , 0x80 ) ;
if ( V_5 )
goto V_12;
V_5 = F_13 ( V_2 , V_153 , 0x20 , 0x20 ) ;
if ( V_5 )
goto V_12;
F_40 ( 5 ) ;
V_5 = F_13 ( V_2 , V_153 , 0x48 , 0x48 ) ;
if ( V_5 )
goto V_12;
V_5 = F_9 ( V_2 , V_151 , L_31 , 2 ) ;
if ( V_5 )
goto V_12;
V_5 = F_37 ( V_2 -> V_18 , F_38 ( V_2 -> V_18 , 0x81 ) ) ;
if ( V_5 )
goto V_12;
} else {
V_5 = F_13 ( V_2 , V_105 , 0x10 , 0x10 ) ;
if ( V_5 )
goto V_12;
V_5 = F_13 ( V_2 , V_153 , 0x00 , 0x48 ) ;
if ( V_5 )
goto V_12;
V_5 = F_13 ( V_2 , V_153 , 0x00 , 0x80 ) ;
if ( V_5 )
goto V_12;
V_5 = F_9 ( V_2 , V_151 , L_32 , 2 ) ;
if ( V_5 )
goto V_12;
}
return V_5 ;
V_12:
F_8 ( & V_2 -> V_18 -> V_21 , L_1 , V_22 , V_5 ) ;
return V_5 ;
}
static int F_41 ( struct V_1 * V_2 )
{
int V_5 , V_154 ;
struct V_39 * V_40 = V_2 -> V_40 ;
T_1 V_8 [ 5 ] ;
T_3 V_155 ;
struct V_156 V_157 [] = {
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
if ( ! V_40 -> V_158 ) {
for ( V_154 = 0 ; V_154 < F_42 ( V_157 ) ; V_154 ++ ) {
V_5 = F_11 ( V_2 , V_157 [ V_154 ] . V_23 ,
V_157 [ V_154 ] . V_24 ) ;
if ( V_5 )
goto V_12;
}
V_40 -> V_158 = true ;
}
V_5 = F_10 ( V_2 , V_159 , V_8 , 5 ) ;
if ( V_5 )
goto V_12;
if ( V_8 [ 4 ] & 0x01 ) {
if ( V_8 [ 2 ] == ( T_1 ) ~ V_8 [ 3 ] ) {
if ( V_8 [ 0 ] == ( T_1 ) ~ V_8 [ 1 ] ) {
V_155 = V_8 [ 0 ] << 8 | V_8 [ 2 ] ;
} else {
V_155 = V_8 [ 0 ] << 16 |
V_8 [ 1 ] << 8 | V_8 [ 2 ] ;
}
} else {
V_155 = V_8 [ 0 ] << 24 | V_8 [ 1 ] << 16 |
V_8 [ 2 ] << 8 | V_8 [ 3 ] ;
}
F_43 ( V_2 -> V_160 , V_155 , 0 ) ;
V_5 = F_11 ( V_2 , V_161 , 1 ) ;
if ( V_5 )
goto V_12;
V_5 = F_11 ( V_2 , V_161 , 1 ) ;
if ( V_5 )
goto V_12;
}
return V_5 ;
V_12:
F_8 ( & V_2 -> V_18 -> V_21 , L_1 , V_22 , V_5 ) ;
return V_5 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_162 * V_163 )
{
V_163 -> V_164 = V_165 ;
V_163 -> V_166 = V_167 ;
V_163 -> V_168 = F_41 ;
V_163 -> V_169 = 400 ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
int V_5 , V_154 , V_25 ;
struct V_39 * V_40 = V_2 -> V_40 ;
struct V_170 V_171 ;
T_1 V_8 [ 128 ] ;
static const struct V_172 V_173 [] = {
{ V_174 , 0x03 , 0xff } ,
{ V_175 , 0x80 , 0xff } ,
{ V_176 , 0x80 , 0xff } ,
} ;
if ( ! V_40 -> V_158 ) {
static const struct V_172 V_177 [] = {
{ V_152 , 0x00 , 0x04 } ,
{ V_152 , 0x00 , 0x08 } ,
{ V_178 , 0x20 , 0x20 } ,
{ V_61 , 0x00 , 0x08 } ,
{ V_62 , 0x08 , 0x08 } ,
{ V_105 , 0x08 , 0x08 } ,
{ V_179 , 0xd0 , 0xff } ,
{ V_180 , 0x07 , 0xff } ,
{ V_181 , 0xc0 , 0xff } ,
{ V_182 , 0x00 , 0xff } ,
{ V_183 , 0x03 , 0xff } ,
{ V_184 , 0x09 , 0xff } ,
{ V_185 , 0x1c , 0xff } ,
{ V_186 , 0x1e , 0xff } ,
{ V_187 , 0x1e , 0xff } ,
{ V_176 , 0x80 , 0xff } ,
} ;
for ( V_154 = 0 ; V_154 < F_42 ( V_177 ) ; V_154 ++ ) {
V_5 = F_13 ( V_2 , V_177 [ V_154 ] . V_23 ,
V_177 [ V_154 ] . V_24 , V_177 [ V_154 ] . V_32 ) ;
if ( V_5 )
goto V_12;
}
V_40 -> V_158 = true ;
}
V_5 = F_12 ( V_2 , V_174 , & V_8 [ 0 ] ) ;
if ( V_5 )
goto V_12;
if ( V_8 [ 0 ] != 0x83 )
goto exit;
V_5 = F_12 ( V_2 , V_188 , & V_8 [ 0 ] ) ;
if ( V_5 )
goto V_12;
V_25 = V_8 [ 0 ] ;
V_5 = F_10 ( V_2 , V_189 , V_8 , V_25 ) ;
if ( V_5 )
goto V_12;
for ( V_154 = 0 ; V_154 < F_42 ( V_173 ) ; V_154 ++ ) {
V_5 = F_13 ( V_2 , V_173 [ V_154 ] . V_23 ,
V_173 [ V_154 ] . V_24 , V_173 [ V_154 ] . V_32 ) ;
if ( V_5 )
goto V_12;
}
F_46 ( & V_171 ) ;
for ( V_154 = 0 ; V_154 < V_25 ; V_154 ++ ) {
V_171 . V_190 = V_8 [ V_154 ] >> 7 ;
V_171 . V_191 = 50800 * ( V_8 [ V_154 ] & 0x7f ) ;
F_47 ( V_2 -> V_160 , & V_171 ) ;
}
F_48 ( V_2 -> V_160 , true ) ;
F_49 ( V_2 -> V_160 ) ;
exit:
return V_5 ;
V_12:
F_8 ( & V_2 -> V_18 -> V_21 , L_1 , V_22 , V_5 ) ;
return V_5 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_162 * V_163 )
{
if ( ! V_163 -> V_164 )
V_163 -> V_164 = V_165 ;
V_163 -> V_166 = V_192 ;
V_163 -> V_193 = V_194 ;
V_163 -> V_168 = F_45 ;
V_163 -> V_169 = 400 ;
return 0 ;
}
