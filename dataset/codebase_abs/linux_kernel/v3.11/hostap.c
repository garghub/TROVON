static int F_1 ( T_1 V_1 , int V_2 )
{
T_1 V_3 ;
struct V_4 * V_5 = V_1 -> V_5 ;
int V_6 ;
const struct V_7 V_8 = {
. V_9 = V_1 -> V_10 ,
} ;
F_2 ( V_11 , V_12 L_1 , V_5 -> V_13 ) ;
V_1 -> V_14 = F_3 ( sizeof( * V_3 ) ) ;
if ( V_1 -> V_14 == NULL )
return - V_15 ;
V_3 = F_4 ( V_1 -> V_14 ) ;
* V_3 = * V_1 ;
memcpy ( V_1 -> V_14 -> V_16 , V_5 -> V_16 , V_17 ) ;
V_1 -> V_14 -> V_18 = & V_8 ;
V_1 -> V_14 -> type = V_19 ;
V_1 -> V_14 -> V_20 = V_5 -> V_20 ;
V_1 -> V_14 -> V_21 = V_5 -> V_21 ;
V_1 -> V_14 -> V_22 = V_5 -> V_22 ;
V_1 -> V_14 -> V_23 = V_5 -> V_23 ;
sprintf ( V_1 -> V_14 -> V_13 , L_2 , V_5 -> V_13 ) ;
if ( V_2 )
V_6 = F_5 ( V_1 -> V_14 ) ;
else
V_6 = F_6 ( V_1 -> V_14 ) ;
if ( V_6 ) {
F_2 ( V_11 , V_12 L_3 ,
V_5 -> V_13 ) ;
F_7 ( V_1 -> V_14 ) ;
V_1 -> V_14 = NULL ;
return - 1 ;
}
F_2 ( V_11 , V_12 L_4 ,
V_5 -> V_13 , V_1 -> V_14 -> V_13 ) ;
F_8 ( & V_1 -> V_24 , V_1 -> V_25 ) ;
return 0 ;
}
static int F_9 ( T_1 V_1 , int V_2 )
{
F_2 ( V_11 , V_12 L_5 , V_1 -> V_5 -> V_13 ) ;
if ( V_1 -> V_14 && V_1 -> V_14 -> V_13 && V_1 -> V_14 -> V_13 [ 0 ] ) {
if ( V_2 )
F_10 ( V_1 -> V_14 ) ;
else
F_11 ( V_1 -> V_14 ) ;
F_2 ( V_11 , V_12 L_6 ,
V_1 -> V_5 -> V_13 , V_1 -> V_14 -> V_13 ) ;
}
F_7 ( V_1 -> V_14 ) ;
V_1 -> V_14 = NULL ;
V_1 -> V_26 = false ;
V_1 -> V_27 = false ;
V_1 -> V_28 = false ;
V_1 -> V_29 -> V_30 = V_31 ;
V_1 -> V_29 -> V_32 = V_31 ;
F_8 ( & V_1 -> V_24 , V_1 -> V_25 ) ;
return 0 ;
}
int F_12 ( T_1 V_1 , int V_33 , int V_2 )
{
if ( V_33 < 0 || V_33 > 1 )
return - V_34 ;
if ( V_1 -> V_35 == V_33 )
return 0 ;
V_1 -> V_35 = V_33 ;
if ( V_33 )
return F_1 ( V_1 , V_2 ) ;
else
return F_9 ( V_1 , V_2 ) ;
}
static int F_13 ( T_1 V_1 ,
struct V_36 * V_37 )
{
unsigned int V_38 ;
if ( F_14 ( V_1 -> V_29 , V_37 -> V_39 , & V_38 ) ) {
F_15 ( V_1 , V_38 ) ;
} else {
return - V_40 ;
}
return 0 ;
}
static int F_16 ( T_1 V_1 ,
struct V_36 * V_37 )
{
T_2 V_29 = V_1 -> V_29 ;
unsigned int V_38 ;
if ( ! F_14 ( V_29 , V_37 -> V_39 , & V_38 ) ) {
F_17 ( ( T_1 ) V_1 , & V_38 ) ;
}
memcpy ( V_29 -> V_41 [ V_38 ] . V_42 , V_37 -> V_39 , V_43 ) ;
V_29 -> V_41 [ V_38 ] . V_44 = V_45 ;
V_29 -> V_41 [ V_38 ] . V_46 = V_37 -> V_47 . V_48 . V_49 ;
V_29 -> V_41 [ V_38 ] . V_50 = false ;
V_29 -> V_41 [ V_38 ] . V_51 = V_37 -> V_47 . V_48 . V_52 ;
V_29 -> V_41 [ V_38 ] . V_53 =
V_29 -> V_41 [ V_38 ] . V_54 ;
V_29 -> V_41 [ V_38 ] . V_55 = V_56 ;
V_29 -> V_41 [ V_38 ] . V_57 =
F_18 ( V_29 -> V_41 [ V_38 ] . V_46 ) ;
V_29 -> V_41 [ V_38 ] . V_58 = ( unsigned short ) V_37 -> V_47 . V_48 . V_59 ;
V_29 -> V_41 [ V_38 ] . V_60 = V_61 ;
F_2 ( V_11 , V_12 L_7 , V_29 -> V_41 [ V_38 ] . V_58 ) ;
F_2 ( V_11 , V_12 L_8 ,
V_37 -> V_39 [ 0 ] ,
V_37 -> V_39 [ 1 ] ,
V_37 -> V_39 [ 2 ] ,
V_37 -> V_39 [ 3 ] ,
V_37 -> V_39 [ 4 ] ,
V_37 -> V_39 [ 5 ]
) ;
F_2 ( V_11 , V_12 L_9 ,
V_29 -> V_41 [ V_38 ] . V_54 ) ;
return 0 ;
}
static int F_19 ( T_1 V_1 ,
struct V_36 * V_37 )
{
T_2 V_29 = V_1 -> V_29 ;
unsigned int V_38 ;
if ( F_14 ( V_29 , V_37 -> V_39 , & V_38 ) ) {
V_37 -> V_47 . V_62 . V_63 =
( V_61 - V_29 -> V_41 [ V_38 ] . V_60 ) / V_64 ;
} else {
return - V_40 ;
}
return 0 ;
}
static int F_20 ( T_1 V_1 ,
struct V_36 * V_37 )
{
T_2 V_29 = V_1 -> V_29 ;
unsigned int V_38 ;
if ( F_14 ( V_29 , V_37 -> V_39 , & V_38 ) ) {
V_29 -> V_41 [ V_38 ] . V_65 |= V_37 -> V_47 . V_66 . V_67 ;
V_29 -> V_41 [ V_38 ] . V_65 &= V_37 -> V_47 . V_66 . V_68 ;
F_2 ( V_11 , V_12 L_10 ,
( unsigned int ) V_29 -> V_41 [ V_38 ] . V_65 ) ;
} else {
return - V_40 ;
}
return 0 ;
}
static int F_21 ( T_1 V_1 ,
struct V_36 * V_37 )
{
T_2 V_29 = V_1 -> V_29 ;
memcpy ( V_29 -> V_69 ,
V_37 -> V_47 . V_70 . V_71 ,
V_37 -> V_47 . V_70 . V_72
) ;
V_29 -> V_73 = V_37 -> V_47 . V_70 . V_72 ;
F_2 ( V_11 , V_12 L_11 , V_29 -> V_73 ) ;
if ( V_29 -> V_73 == 0 ) {
V_29 -> V_74 = V_75 ;
F_2 ( V_11 , V_12 L_12 ) ;
} else {
if ( ( V_29 -> V_69 [ 0 ] == V_76 ) ||
( V_29 -> V_69 [ 0 ] == V_77 ) ) {
V_29 -> V_74 = V_78 ;
F_2 ( V_11 , V_12 L_13 ) ;
} else
return - V_34 ;
}
return 0 ;
}
static void F_22 ( T_1 V_1 )
{
F_23 ( V_1 , 1 ) ;
V_1 -> V_79 = 0 ;
return;
}
static int F_24 ( T_1 V_1 ,
struct V_36 * V_37 ,
int V_80 )
{
T_2 V_29 = V_1 -> V_29 ;
unsigned long V_81 = 0 ;
unsigned char V_82 [ V_83 ] ;
unsigned char V_84 [ V_83 ] ;
T_3 V_85 ;
unsigned char V_86 = V_87 ;
int V_6 = 0 ;
int V_88 = - 1 ;
int V_89 ;
bool V_90 = false ;
unsigned short V_91 = 0 ;
V_37 -> V_47 . V_92 . V_93 = 0 ;
if ( V_37 -> V_47 . V_92 . V_94 > V_95 )
return - V_34 ;
if ( ( V_37 -> V_47 . V_92 . V_96 > 3 ) || ( V_37 -> V_47 . V_92 . V_97 > V_83 ) ) {
V_37 -> V_47 . V_92 . V_93 = V_98 ;
F_2 ( V_11 , V_12 L_14 ) ;
return - V_34 ;
}
if ( F_25 ( V_37 -> V_39 ) ) {
if ( V_37 -> V_47 . V_92 . V_96 >= V_99 )
return - V_34 ;
V_88 = 0 ;
} else {
if ( F_14 ( V_29 , V_37 -> V_39 , & V_88 ) == false ) {
V_37 -> V_47 . V_92 . V_93 = V_100 ;
F_2 ( V_11 , V_12 L_15 ) ;
return - V_34 ;
}
}
F_2 ( V_11 , V_12 L_16 , V_88 ) ;
F_2 ( V_11 , V_12 L_17 , V_37 -> V_47 . V_92 . V_94 ) ;
if ( V_37 -> V_47 . V_92 . V_94 == V_101 ) {
if ( V_29 -> V_41 [ V_88 ] . V_102 == true ) {
if ( F_26 ( & ( V_1 -> V_24 ) ,
V_37 -> V_39 ,
V_29 -> V_41 [ V_88 ] . V_81 ,
V_1 -> V_25 ) == false ) {
F_2 ( V_11 , V_12 L_18 ) ;
}
V_29 -> V_41 [ V_88 ] . V_102 = false ;
}
V_29 -> V_41 [ V_88 ] . V_103 = 0 ;
V_29 -> V_41 [ V_88 ] . V_81 = 0 ;
V_29 -> V_41 [ V_88 ] . V_104 = 0 ;
V_29 -> V_41 [ V_88 ] . V_85 = 0 ;
V_29 -> V_41 [ V_88 ] . V_105 = 0 ;
V_29 -> V_41 [ V_88 ] . V_106 = 0 ;
V_29 -> V_41 [ V_88 ] . V_107 = 0 ;
memset ( & V_29 -> V_41 [ V_88 ] . V_108 [ 0 ] ,
0 ,
V_83
) ;
return V_6 ;
}
memcpy ( V_82 , V_37 -> V_47 . V_92 . V_109 , V_37 -> V_47 . V_92 . V_97 ) ;
V_29 -> V_41 [ V_88 ] . V_103 = V_37 -> V_47 . V_92 . V_96 ;
V_29 -> V_41 [ V_88 ] . V_104 = V_37 -> V_47 . V_92 . V_97 ;
memcpy ( & V_29 -> V_41 [ V_88 ] . V_108 [ 0 ] ,
V_37 -> V_47 . V_92 . V_109 ,
V_37 -> V_47 . V_92 . V_97
) ;
V_81 = ( unsigned long ) ( V_37 -> V_47 . V_92 . V_96 ) ;
if ( V_37 -> V_47 . V_92 . V_110 & V_111 ) {
V_1 -> V_103 = ( unsigned char ) V_81 ;
V_1 -> V_112 = true ;
V_81 |= ( 1 << 31 ) ;
}
if ( V_37 -> V_47 . V_92 . V_94 == V_113 ) {
if ( ( V_1 -> V_26 == false ) || ( V_88 == 0 ) ) {
F_27 ( & ( V_1 -> V_24 ) ,
V_81 & ~ ( V_114 | V_115 ) ,
V_37 -> V_47 . V_92 . V_97 ,
NULL ,
V_82 ,
V_87 ,
V_1 -> V_25 ,
V_1 -> V_116 ) ;
} else {
V_81 |= ( 1 << 30 ) ;
if ( F_28 ( & ( V_1 -> V_24 ) ,
& V_37 -> V_39 [ 0 ] ,
V_81 & ~ ( V_115 ) ,
V_37 -> V_47 . V_92 . V_97 ,
( V_117 ) & ( V_85 ) ,
( unsigned char * ) V_82 ,
V_87 ,
V_1 -> V_25 ,
V_1 -> V_116 ) == true ) {
V_29 -> V_41 [ V_88 ] . V_102 = true ;
} else {
V_29 -> V_41 [ V_88 ] . V_102 = false ;
V_90 = true ;
}
}
V_1 -> V_118 = V_119 ;
V_1 -> V_28 = true ;
V_29 -> V_30 = V_87 ;
V_29 -> V_32 = V_87 ;
V_29 -> V_41 [ V_88 ] . V_107 = V_87 ;
V_29 -> V_41 [ V_88 ] . V_81 = V_81 ;
return V_6 ;
}
if ( V_37 -> V_47 . V_92 . V_120 ) {
memcpy ( & V_84 , V_37 -> V_47 . V_92 . V_120 , 8 ) ;
for ( V_89 = 0 ; V_89 < 8 ; V_89 ++ )
V_85 |= ( unsigned long ) V_84 [ V_89 ] << ( V_89 * 8 ) ;
V_81 |= 1 << 29 ;
V_29 -> V_41 [ V_88 ] . V_85 = V_85 ;
}
if ( V_37 -> V_47 . V_92 . V_94 == V_121 ) {
if ( V_37 -> V_47 . V_92 . V_97 != V_83 )
return - V_34 ;
V_1 -> V_118 = V_122 ;
V_86 = V_123 ;
V_29 -> V_30 = V_123 ;
V_29 -> V_32 = V_123 ;
}
if ( V_37 -> V_47 . V_92 . V_94 == V_95 ) {
if ( ( V_37 -> V_47 . V_92 . V_97 != V_124 ) ||
( V_1 -> V_116 <= V_125 ) )
return - V_34 ;
V_1 -> V_118 = V_126 ;
V_86 = V_127 ;
V_29 -> V_30 = V_127 ;
V_29 -> V_32 = V_127 ;
}
if ( V_88 == 0 ) {
F_27 ( & ( V_1 -> V_24 ) ,
V_81 ,
V_37 -> V_47 . V_92 . V_97 ,
( V_117 ) & ( V_85 ) ,
V_82 ,
V_86 ,
V_1 -> V_25 ,
V_1 -> V_116 ) ;
V_29 -> V_41 [ V_88 ] . V_102 = true ;
} else {
V_81 |= ( 1 << 30 ) ;
if ( F_28 ( & ( V_1 -> V_24 ) ,
& V_37 -> V_39 [ 0 ] ,
V_81 ,
V_37 -> V_47 . V_92 . V_97 ,
( V_117 ) & ( V_85 ) ,
( unsigned char * ) V_82 ,
V_86 ,
V_1 -> V_25 ,
V_1 -> V_116 ) == true ) {
V_29 -> V_41 [ V_88 ] . V_102 = true ;
} else {
V_29 -> V_41 [ V_88 ] . V_102 = false ;
V_90 = true ;
F_2 ( V_11 , V_12 L_19 ) ;
}
}
if ( V_90 == true ) {
V_91 &= 0x7F00 ;
V_91 |= ( V_86 << 4 ) ;
V_91 |= ( V_86 ) ;
V_91 |= 0x0044 ;
V_91 |= 0x4000 ;
F_29 ( V_1 -> V_25 , V_91 , V_128 - 1 , V_1 -> V_116 ) ;
}
F_2 ( V_11 , V_12 L_20 , V_88 ) ;
F_2 ( V_11 , V_12 L_21 , V_37 -> V_47 . V_92 . V_96 ,
V_37 -> V_47 . V_92 . V_97 ) ;
F_2 ( V_11 , V_12 L_22 ,
V_29 -> V_41 [ V_88 ] . V_108 [ 0 ] ,
V_29 -> V_41 [ V_88 ] . V_108 [ 1 ] ,
V_29 -> V_41 [ V_88 ] . V_108 [ 2 ] ,
V_29 -> V_41 [ V_88 ] . V_108 [ 3 ] ,
V_29 -> V_41 [ V_88 ] . V_108 [ 4 ]
) ;
V_1 -> V_28 = true ;
V_29 -> V_41 [ V_88 ] . V_107 = V_86 ;
V_29 -> V_41 [ V_88 ] . V_81 = V_81 ;
V_29 -> V_41 [ V_88 ] . V_105 = 0 ;
V_29 -> V_41 [ V_88 ] . V_106 = 0 ;
return V_6 ;
}
static int F_30 ( T_1 V_1 ,
struct V_36 * V_37 ,
int V_80 )
{
T_2 V_29 = V_1 -> V_29 ;
int V_6 = 0 ;
int V_89 ;
int V_88 = 0 ;
V_37 -> V_47 . V_92 . V_93 = 0 ;
if ( F_25 ( V_37 -> V_39 ) ) {
V_88 = 0 ;
} else {
if ( F_14 ( V_29 , V_37 -> V_39 , & V_88 ) == false ) {
V_37 -> V_47 . V_92 . V_93 = V_100 ;
F_2 ( V_11 , V_12 L_23 ) ;
return - V_34 ;
}
}
F_2 ( V_11 , V_12 L_24 , V_88 ) ;
memset ( V_37 -> V_47 . V_92 . V_120 , 0 , 8 ) ;
for ( V_89 = 0 ; V_89 < 8 ; V_89 ++ ) {
V_37 -> V_47 . V_92 . V_120 [ V_89 ] = ( unsigned char ) V_29 -> V_41 [ V_88 ] . V_85 >> ( V_89 * 8 ) ;
}
return V_6 ;
}
int F_31 ( T_1 V_1 , struct V_129 * V_130 )
{
struct V_36 * V_37 ;
int V_6 = 0 ;
int V_131 = 0 ;
if ( V_130 -> V_132 < sizeof( struct V_36 ) ||
V_130 -> V_132 > V_133 || ! V_130 -> V_134 )
return - V_34 ;
V_37 = F_32 ( ( int ) V_130 -> V_132 , ( int ) V_135 ) ;
if ( V_37 == NULL )
return - V_15 ;
if ( F_33 ( V_37 , V_130 -> V_134 , V_130 -> V_132 ) ) {
V_6 = - V_136 ;
goto V_137;
}
switch ( V_37 -> V_138 ) {
case V_139 :
F_2 ( V_11 , V_12 L_25 ) ;
F_34 ( & V_1 -> V_140 ) ;
V_6 = F_24 ( V_1 , V_37 , V_130 -> V_132 ) ;
F_35 ( & V_1 -> V_140 ) ;
break;
case V_141 :
F_2 ( V_11 , V_12 L_26 ) ;
F_34 ( & V_1 -> V_140 ) ;
V_6 = F_30 ( V_1 , V_37 , V_130 -> V_132 ) ;
F_35 ( & V_1 -> V_140 ) ;
break;
case V_142 :
F_2 ( V_11 , V_12 L_27 ) ;
return - V_143 ;
break;
case V_144 :
F_2 ( V_11 , V_12 L_28 ) ;
F_34 ( & V_1 -> V_140 ) ;
F_22 ( V_1 ) ;
F_35 ( & V_1 -> V_140 ) ;
break;
case V_145 :
F_2 ( V_11 , V_12 L_29 ) ;
F_34 ( & V_1 -> V_140 ) ;
V_6 = F_16 ( V_1 , V_37 ) ;
F_35 ( & V_1 -> V_140 ) ;
break;
case V_146 :
F_2 ( V_11 , V_12 L_30 ) ;
F_34 ( & V_1 -> V_140 ) ;
V_6 = F_13 ( V_1 , V_37 ) ;
F_35 ( & V_1 -> V_140 ) ;
break;
case V_147 :
F_2 ( V_11 , V_12 L_31 ) ;
V_6 = F_19 ( V_1 , V_37 ) ;
V_131 = 1 ;
break;
case V_148 :
F_2 ( V_11 , V_12 L_32 ) ;
V_6 = F_20 ( V_1 , V_37 ) ;
break;
case V_149 :
F_2 ( V_11 , V_12 L_33 ) ;
return - V_143 ;
case V_150 :
F_2 ( V_11 , V_12 L_34 ) ;
V_6 = F_21 ( V_1 , V_37 ) ;
break;
case V_151 :
F_2 ( V_11 , V_12 L_35 ) ;
return - V_143 ;
case V_152 :
F_2 ( V_11 , V_12 L_36 ) ;
return - V_143 ;
default:
F_2 ( V_11 , V_12 L_37 ,
( int ) V_37 -> V_138 ) ;
return - V_143 ;
break;
}
if ( ( V_6 == 0 ) && V_131 ) {
if ( F_36 ( V_130 -> V_134 , V_37 , V_130 -> V_132 ) ) {
V_6 = - V_136 ;
goto V_137;
}
}
V_137:
F_37 ( V_37 ) ;
return V_6 ;
}
