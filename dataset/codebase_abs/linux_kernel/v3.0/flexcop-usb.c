static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 , T_3 V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
T_3 V_9 = V_5 ? V_10 : V_11 ;
T_3 V_12 = ( V_5 ? V_13 : V_14 ) | V_15 ;
T_3 V_16 = F_2 ( V_3 ) |
( V_5 ? 0x80 : 0 ) ;
int V_17 = F_3 ( V_7 -> V_18 ,
V_5 ? V_19 : V_20 ,
V_9 ,
V_12 ,
V_16 ,
0 ,
V_4 ,
sizeof( T_2 ) ,
V_21 * V_22 ) ;
if ( V_17 != sizeof( T_2 ) ) {
F_4 ( L_1 , V_5 ? L_2 :
L_3 , V_16 , V_3 ) ;
return - V_23 ;
}
return 0 ;
}
static int F_5 ( struct V_6 * V_7 ,
T_4 V_24 , T_3 V_25 , T_1 V_16 ,
T_3 * V_26 , T_2 V_27 )
{
T_3 V_12 = V_15 ;
T_1 V_28 ;
int V_29 , V_30 , V_17 ;
V_28 = V_25 << 8 ;
switch ( V_24 ) {
case V_31 :
V_29 = V_32 ;
V_12 |= V_13 ;
V_30 = V_19 ;
break;
case V_33 :
V_28 |= V_26 [ 0 ] ;
V_12 |= V_14 ;
V_29 = V_34 ;
V_30 = V_20 ;
break;
case V_35 :
V_12 |= V_14 ;
V_29 = V_36 ;
V_30 = V_20 ;
break;
default:
F_6 ( L_4 , V_24 ) ;
return - V_37 ;
}
F_7 ( L_5 , V_12 , V_24 ,
V_16 , V_28 , V_27 ) ;
V_17 = F_3 ( V_7 -> V_18 , V_30 ,
V_24 ,
V_12 ,
V_16 ,
V_28 ,
V_26 ,
V_27 ,
V_29 * V_22 ) ;
F_8 ( V_26 , V_17 , F_7 ) ;
return V_17 == V_27 ? 0 : - V_23 ;
}
static int F_9 ( struct V_6 * V_7 ,
T_4 V_24 , T_5 V_38 ,
T_2 V_39 , int V_40 , T_3 * V_41 , T_2 V_17 )
{
int V_42 , V_43 = 0 ;
T_1 V_44 ;
T_2 V_45 = 0 ;
switch( V_24 ) {
case V_31 :
V_44 = V_46 ;
break;
case V_33 :
V_44 = V_47 ;
break;
case V_35 :
V_44 = V_48 ;
break;
default:
return - V_37 ;
break;
}
for ( V_42 = 0 ; V_42 < V_17 ; ) {
V_45 =
V_44 < F_10 ( V_39 , V_17 ) ?
V_44 :
F_10 ( V_39 , V_17 ) ;
F_6 ( L_6 ,
( V_39 & V_49 ) |
( V_50 * V_40 ) ) ;
V_43 = F_5 ( V_7 , V_24 ,
V_38 + ( V_39 / V_51 ) ,
( V_39 & V_49 ) |
( V_50 * V_40 ) ,
& V_41 [ V_42 ] , V_45 ) ;
if ( V_43 < 0 )
return V_43 ;
V_39 += V_45 ;
V_17 -= V_45 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , int V_40 )
{
return F_9 ( V_2 -> V_8 , V_31 ,
V_52 , 0x1f010 , 1 ,
V_2 -> V_53 . V_54 , 6 ) ;
}
static int F_12 ( struct V_55 * V_56 ,
T_4 V_24 , T_6 V_57 ,
T_3 V_58 , T_3 V_39 , T_3 * V_41 , T_3 V_27 )
{
struct V_6 * V_7 = V_56 -> V_2 -> V_8 ;
T_1 V_59 , V_28 ;
int V_29 , V_30 , V_17 ;
T_3 V_12 = V_15 ;
switch ( V_57 ) {
case V_60 :
case V_61 :
case V_62 :
case V_63 :
V_30 = V_20 ;
V_29 = 2 ;
V_12 |= V_14 ;
break;
case V_64 :
case V_65 :
V_30 = V_19 ;
V_29 = 2 ;
V_12 |= V_13 ;
break;
default:
F_6 ( L_7 , V_57 ) ;
return - V_37 ;
}
V_59 = ( V_57 << 8 ) | ( V_56 -> V_66 << 4 ) ;
V_28 = ( V_58 << 8 ) | V_39 ;
F_13 ( L_8 ,
V_57 , V_12 , V_24 ,
V_59 & 0xff , V_59 >> 8 ,
V_28 & 0xff , V_28 >> 8 ) ;
V_17 = F_3 ( V_7 -> V_18 , V_30 ,
V_24 ,
V_12 ,
V_59 ,
V_28 ,
V_41 ,
V_27 ,
V_29 * V_22 ) ;
return V_17 == V_27 ? 0 : - V_67 ;
}
static T_7 F_14 ( struct V_1 * V_2 ,
T_8 V_68 )
{
T_7 V_4 ;
V_4 . V_69 = 0 ;
F_1 ( V_2 , V_68 , & V_4 . V_69 , 1 ) ;
return V_4 ;
}
static int F_15 ( struct V_1 * V_2 ,
T_8 V_68 , T_7 V_4 )
{
return F_1 ( V_2 , V_68 , & V_4 . V_69 , 0 ) ;
}
static int F_16 ( struct V_55 * V_56 ,
T_9 V_70 , T_3 V_58 , T_3 V_39 , T_3 * V_41 , T_1 V_17 )
{
if ( V_70 == V_71 )
return F_12 ( V_56 , V_72 ,
V_64 , V_58 , V_39 , V_41 , V_17 ) ;
else
return F_12 ( V_56 , V_72 ,
V_60 , V_58 , V_39 , V_41 , V_17 ) ;
}
static void F_17 ( struct V_6 * V_7 ,
T_3 * V_73 , int V_74 )
{
T_3 * V_75 ;
int V_76 ;
F_18 ( L_9 ,
V_7 -> V_77 , V_74 ) ;
if ( V_7 -> V_77 > 0 ) {
memcpy ( V_7 -> V_78 + V_7 -> V_77 , V_73 ,
V_74 ) ;
V_7 -> V_77 += V_74 ;
V_75 = V_7 -> V_78 ;
V_76 = V_7 -> V_77 ;
} else {
V_75 = V_73 ;
V_76 = V_74 ;
}
while ( V_76 >= 190 ) {
if ( * V_75 == 0xff ) {
switch ( * ( V_75 + 1 ) & 0x03 ) {
case 0x01 :
if ( * ( V_75 + 2 ) == 0x47 )
F_19 (
V_7 -> V_79 , V_75 + 2 , 1 ) ;
else
F_18 (
L_10 ,
* ( V_75 + 2 ) , * ( V_75 + 3 ) ,
* ( V_75 + 4 ) , * ( V_75 + 5 ) ) ;
V_75 += 190 ;
V_76 -= 190 ;
break;
default:
F_18 ( L_11 ) ;
V_76 = 0 ;
break;
}
} else {
F_18 ( L_12 ) ;
V_76 = 0 ;
}
}
if ( V_76 > 0 )
memcpy ( V_7 -> V_78 , V_75 , V_76 ) ;
V_7 -> V_77 = V_76 ;
}
static void F_20 ( struct V_80 * V_80 )
{
struct V_6 * V_7 = V_80 -> V_81 ;
int V_42 ;
if ( V_80 -> V_82 > 0 )
F_18 ( L_13 ,
V_80 -> V_83 , V_80 -> V_82 ) ;
for ( V_42 = 0 ; V_42 < V_80 -> V_84 ; V_42 ++ ) {
if ( V_80 -> V_85 [ V_42 ] . V_86 < 0 ) {
F_4 ( L_14 , V_42 ,
V_80 -> V_85 [ V_42 ] . V_86 ) ;
} else
if ( V_80 -> V_85 [ V_42 ] . V_82 > 0 ) {
F_18 ( L_15 ,
V_80 -> V_85 [ V_42 ] . V_82 ) ;
F_17 ( V_7 ,
V_80 -> V_87 +
V_80 -> V_85 [ V_42 ] . V_88 ,
V_80 -> V_85 [ V_42 ] . V_82 ) ;
}
V_80 -> V_85 [ V_42 ] . V_86 = 0 ;
V_80 -> V_85 [ V_42 ] . V_82 = 0 ;
}
F_21 ( V_80 , V_89 ) ;
}
static int F_22 ( struct V_1 * V_2 , int V_90 )
{
return 0 ;
}
static void F_23 ( struct V_6 * V_7 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_91 ; V_42 ++ )
if ( V_7 -> V_92 [ V_42 ] != NULL ) {
F_18 ( L_16 , V_42 ) ;
F_24 ( V_7 -> V_92 [ V_42 ] ) ;
F_25 ( V_7 -> V_92 [ V_42 ] ) ;
}
if ( V_7 -> V_93 != NULL )
F_26 ( NULL ,
V_7 -> V_94 , V_7 -> V_93 ,
V_7 -> V_95 ) ;
}
static int F_27 ( struct V_6 * V_7 )
{
T_1 V_96 = F_28 (
V_7 -> V_97 -> V_98 -> V_99 [ 0 ] . V_100 . V_101 ) ;
int V_102 = V_91 * V_103 *
V_96 , V_42 , V_104 , V_43 ;
int V_105 = 0 ;
F_18 ( L_17
L_18 , V_91 ,
V_103 , V_96 , V_102 ) ;
V_7 -> V_93 = F_29 ( NULL ,
V_102 , & V_7 -> V_95 ) ;
if ( V_7 -> V_93 == NULL )
return - V_106 ;
memset ( V_7 -> V_93 , 0 , V_102 ) ;
V_7 -> V_94 = V_102 ;
for ( V_42 = 0 ; V_42 < V_91 ; V_42 ++ ) {
V_7 -> V_92 [ V_42 ] = F_30 ( V_103 ,
V_89 ) ;
if ( V_7 -> V_92 [ V_42 ] == NULL ) {
V_43 = - V_106 ;
goto V_107;
}
}
for ( V_42 = 0 ; V_42 < V_91 ; V_42 ++ ) {
int V_108 = 0 ;
struct V_80 * V_80 = V_7 -> V_92 [ V_42 ] ;
F_18 ( L_19
L_20 , V_42 , V_105 ) ;
V_80 -> V_109 = V_7 -> V_18 ;
V_80 -> V_81 = V_7 ;
V_80 -> V_110 = F_20 ;
V_80 -> V_30 = V_111 ;
V_80 -> V_112 = V_113 ;
V_80 -> V_114 = 1 ;
V_80 -> V_84 = V_103 ;
V_80 -> V_83 = V_96 * V_103 ;
V_80 -> V_87 = V_7 -> V_93 + V_105 ;
V_105 += V_96 * V_103 ;
for ( V_104 = 0 ; V_104 < V_103 ; V_104 ++ ) {
F_18 ( L_21 ,
V_42 , V_104 , V_108 ) ;
V_80 -> V_85 [ V_104 ] . V_88 = V_108 ;
V_80 -> V_85 [ V_104 ] . V_115 = V_96 ;
V_108 += V_96 ;
}
if ( ( V_43 = F_21 ( V_7 -> V_92 [ V_42 ] , V_89 ) ) ) {
F_4 ( L_22 , V_42 , V_43 ) ;
goto V_107;
}
F_18 ( L_23 , V_42 ) ;
}
F_31 ( V_7 -> V_79 , V_116 |
V_117 | V_118 | V_119 ,
V_120 ) ;
F_32 ( V_7 -> V_79 , V_121 ) ;
F_33 ( V_7 -> V_79 , 1 , 1 , 1 ) ;
return 0 ;
V_107:
F_23 ( V_7 ) ;
return V_43 ;
}
static int F_34 ( struct V_6 * V_7 )
{
F_35 ( V_7 -> V_18 , 0 , 1 ) ;
switch ( V_7 -> V_18 -> V_122 ) {
case V_123 :
F_4 ( L_24 ) ;
return - V_124 ;
break;
case V_125 :
F_36 ( L_25 ) ;
break;
case V_126 :
F_36 ( L_26 ) ;
break;
case V_127 :
default:
F_4 ( L_27 ) ;
return - V_124 ;
}
F_37 ( V_7 -> V_97 , V_7 ) ;
return 0 ;
}
static void F_38 ( struct V_6 * V_7 )
{
F_37 ( V_7 -> V_97 , NULL ) ;
}
static int F_39 ( struct V_128 * V_129 ,
const struct V_130 * V_131 )
{
struct V_132 * V_18 = F_40 ( V_129 ) ;
struct V_6 * V_7 = NULL ;
struct V_1 * V_2 = NULL ;
int V_43 ;
if ( ( V_2 = F_41 ( sizeof( struct V_6 ) ) ) == NULL ) {
F_4 ( L_28 ) ;
return - V_106 ;
}
V_7 = V_2 -> V_8 ;
V_7 -> V_79 = V_2 ;
V_2 -> V_133 = F_14 ;
V_2 -> V_134 = F_15 ;
V_2 -> V_135 = F_16 ;
V_2 -> V_136 = F_11 ;
V_2 -> V_137 = F_22 ;
V_2 -> V_138 = 1 ;
V_2 -> V_139 = V_140 ;
V_2 -> V_109 = & V_18 -> V_109 ;
V_2 -> V_141 = V_142 ;
V_7 -> V_18 = V_18 ;
V_7 -> V_97 = V_129 ;
if ( ( V_43 = F_34 ( V_7 ) ) != 0 )
goto V_143;
if ( ( V_43 = F_42 ( V_2 ) ) != 0 )
goto V_144;
if ( ( V_43 = F_27 ( V_7 ) ) != 0 )
goto V_145;
F_36 ( L_29 , V_146 ) ;
return 0 ;
V_145:
F_43 ( V_2 ) ;
V_144:
F_38 ( V_7 ) ;
V_143:
F_44 ( V_2 ) ;
return V_43 ;
}
static void F_45 ( struct V_128 * V_129 )
{
struct V_6 * V_7 = F_46 ( V_129 ) ;
F_23 ( V_7 ) ;
F_43 ( V_7 -> V_79 ) ;
F_38 ( V_7 ) ;
F_44 ( V_7 -> V_79 ) ;
F_36 ( L_30 , V_146 ) ;
}
static int T_10 F_47 ( void )
{
int V_147 ;
if ( ( V_147 = F_48 ( & V_148 ) ) ) {
F_4 ( L_31 , V_147 ) ;
return V_147 ;
}
return 0 ;
}
static void T_11 F_49 ( void )
{
F_50 ( & V_148 ) ;
}
