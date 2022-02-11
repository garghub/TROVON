static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 , T_3 V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
T_3 V_9 = V_5 ? V_10 : V_11 ;
T_3 V_12 = ( V_5 ? V_13 : V_14 ) | V_15 ;
T_3 V_16 = F_2 ( V_3 ) |
( V_5 ? 0x80 : 0 ) ;
int V_17 ;
F_3 ( & V_7 -> V_18 ) ;
if ( ! V_5 )
memcpy ( V_7 -> V_19 , V_4 , sizeof( * V_4 ) ) ;
V_17 = F_4 ( V_7 -> V_20 ,
V_5 ? V_21 : V_22 ,
V_9 ,
V_12 ,
V_16 ,
0 ,
V_7 -> V_19 ,
sizeof( T_2 ) ,
V_23 * V_24 ) ;
if ( V_17 != sizeof( T_2 ) ) {
F_5 ( L_1 , V_5 ? L_2 :
L_3 , V_16 , V_3 ) ;
if ( V_17 >= 0 )
V_17 = - V_25 ;
}
if ( V_5 && V_17 >= 0 )
memcpy ( V_4 , V_7 -> V_19 , sizeof( * V_4 ) ) ;
F_6 ( & V_7 -> V_18 ) ;
return V_17 ;
}
static int F_7 ( struct V_6 * V_7 ,
T_4 V_26 , T_3 V_27 , T_1 V_16 ,
T_3 * V_28 , T_2 V_29 )
{
T_3 V_12 = V_15 ;
T_1 V_30 ;
int V_31 , V_32 , V_17 ;
V_30 = V_27 << 8 ;
if ( V_29 > sizeof( V_7 -> V_19 ) ) {
F_5 ( L_4 ) ;
return - V_25 ;
}
switch ( V_26 ) {
case V_33 :
V_31 = V_34 ;
V_12 |= V_13 ;
V_32 = V_21 ;
break;
case V_35 :
V_30 |= V_28 [ 0 ] ;
V_12 |= V_14 ;
V_31 = V_36 ;
V_32 = V_22 ;
break;
case V_37 :
V_12 |= V_14 ;
V_31 = V_38 ;
V_32 = V_22 ;
break;
default:
F_8 ( L_5 , V_26 ) ;
return - V_39 ;
}
F_9 ( L_6 , V_12 , V_26 ,
V_16 , V_30 , V_29 ) ;
F_3 ( & V_7 -> V_18 ) ;
if ( ( V_12 & V_40 ) == V_14 )
memcpy ( V_7 -> V_19 , V_28 , V_29 ) ;
V_17 = F_4 ( V_7 -> V_20 , V_32 ,
V_26 ,
V_12 ,
V_16 ,
V_30 ,
V_7 -> V_19 ,
V_29 ,
V_31 * V_24 ) ;
if ( V_17 != V_29 )
V_17 = - V_25 ;
if ( V_17 >= 0 ) {
V_17 = 0 ;
if ( ( V_12 & V_40 ) == V_13 )
memcpy ( V_28 , V_7 -> V_19 , V_29 ) ;
}
F_6 ( & V_7 -> V_18 ) ;
F_10 ( V_28 , V_17 , F_9 ) ;
return V_17 ;
}
static int F_11 ( struct V_6 * V_7 ,
T_4 V_26 , T_5 V_41 ,
T_2 V_42 , int V_43 , T_3 * V_44 , T_2 V_45 )
{
int V_46 , V_17 = 0 ;
T_1 V_47 ;
T_2 V_48 = 0 ;
switch( V_26 ) {
case V_33 :
V_47 = V_49 ;
break;
case V_35 :
V_47 = V_50 ;
break;
case V_37 :
V_47 = V_51 ;
break;
default:
return - V_39 ;
break;
}
for ( V_46 = 0 ; V_46 < V_45 ; ) {
V_48 =
V_47 < F_12 ( V_42 , V_45 ) ?
V_47 :
F_12 ( V_42 , V_45 ) ;
F_8 ( L_7 ,
( V_42 & V_52 ) |
( V_53 * V_43 ) ) ;
V_17 = F_7 ( V_7 , V_26 ,
V_41 + ( V_42 / V_54 ) ,
( V_42 & V_52 ) |
( V_53 * V_43 ) ,
& V_44 [ V_46 ] , V_48 ) ;
if ( V_17 < 0 )
return V_17 ;
V_42 += V_48 ;
V_45 -= V_48 ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , int V_43 )
{
return F_11 ( V_2 -> V_8 , V_33 ,
V_55 , 0x1f010 , 1 ,
V_2 -> V_56 . V_57 , 6 ) ;
}
static int F_14 ( struct V_58 * V_59 ,
T_4 V_26 , T_6 V_60 ,
T_3 V_61 , T_3 V_42 , T_3 * V_44 , T_3 V_29 )
{
struct V_6 * V_7 = V_59 -> V_2 -> V_8 ;
T_1 V_62 , V_30 ;
int V_31 , V_32 , V_17 ;
T_3 V_12 = V_15 ;
if ( V_29 > sizeof( V_7 -> V_19 ) ) {
F_5 ( L_4 ) ;
return - V_25 ;
}
switch ( V_60 ) {
case V_63 :
case V_64 :
case V_65 :
case V_66 :
V_32 = V_22 ;
V_31 = 2 ;
V_12 |= V_14 ;
break;
case V_67 :
case V_68 :
V_32 = V_21 ;
V_31 = 2 ;
V_12 |= V_13 ;
break;
default:
F_8 ( L_8 , V_60 ) ;
return - V_39 ;
}
V_62 = ( V_60 << 8 ) | ( V_59 -> V_69 << 4 ) ;
V_30 = ( V_61 << 8 ) | V_42 ;
F_15 ( L_9 ,
V_60 , V_12 , V_26 ,
V_62 & 0xff , V_62 >> 8 ,
V_30 & 0xff , V_30 >> 8 ) ;
F_3 ( & V_7 -> V_18 ) ;
if ( ( V_12 & V_40 ) == V_14 )
memcpy ( V_7 -> V_19 , V_44 , V_29 ) ;
V_17 = F_4 ( V_7 -> V_20 , V_32 ,
V_26 ,
V_12 ,
V_62 ,
V_30 ,
V_7 -> V_19 ,
V_29 ,
V_31 * V_24 ) ;
if ( V_17 != V_29 )
V_17 = - V_25 ;
if ( V_17 >= 0 ) {
V_17 = 0 ;
if ( ( V_12 & V_40 ) == V_13 )
memcpy ( V_44 , V_7 -> V_19 , V_29 ) ;
}
F_6 ( & V_7 -> V_18 ) ;
return 0 ;
}
static T_7 F_16 ( struct V_1 * V_2 ,
T_8 V_70 )
{
T_7 V_4 ;
V_4 . V_71 = 0 ;
F_1 ( V_2 , V_70 , & V_4 . V_71 , 1 ) ;
return V_4 ;
}
static int F_17 ( struct V_1 * V_2 ,
T_8 V_70 , T_7 V_4 )
{
return F_1 ( V_2 , V_70 , & V_4 . V_71 , 0 ) ;
}
static int F_18 ( struct V_58 * V_59 ,
T_9 V_72 , T_3 V_61 , T_3 V_42 , T_3 * V_44 , T_1 V_45 )
{
if ( V_72 == V_73 )
return F_14 ( V_59 , V_74 ,
V_67 , V_61 , V_42 , V_44 , V_45 ) ;
else
return F_14 ( V_59 , V_74 ,
V_63 , V_61 , V_42 , V_44 , V_45 ) ;
}
static void F_19 ( struct V_6 * V_7 ,
T_3 * V_75 , int V_76 )
{
T_3 * V_77 ;
int V_78 ;
F_20 ( L_10 ,
V_7 -> V_79 , V_76 ) ;
if ( V_7 -> V_79 > 0 ) {
memcpy ( V_7 -> V_80 + V_7 -> V_79 , V_75 ,
V_76 ) ;
V_7 -> V_79 += V_76 ;
V_77 = V_7 -> V_80 ;
V_78 = V_7 -> V_79 ;
} else {
V_77 = V_75 ;
V_78 = V_76 ;
}
while ( V_78 >= 190 ) {
if ( * V_77 == 0xff ) {
switch ( * ( V_77 + 1 ) & 0x03 ) {
case 0x01 :
if ( * ( V_77 + 2 ) == 0x47 )
F_21 (
V_7 -> V_81 , V_77 + 2 , 1 ) ;
else
F_20 ( L_11 , 4 , V_77 + 2 ) ;
V_77 += 190 ;
V_78 -= 190 ;
break;
default:
F_20 ( L_12 ) ;
V_78 = 0 ;
break;
}
} else {
F_20 ( L_13 ) ;
V_78 = 0 ;
}
}
if ( V_78 > 0 )
memcpy ( V_7 -> V_80 , V_77 , V_78 ) ;
V_7 -> V_79 = V_78 ;
}
static void F_22 ( struct V_82 * V_82 )
{
struct V_6 * V_7 = V_82 -> V_83 ;
int V_46 ;
if ( V_82 -> V_84 > 0 )
F_20 ( L_14 ,
V_82 -> V_85 , V_82 -> V_84 ) ;
for ( V_46 = 0 ; V_46 < V_82 -> V_86 ; V_46 ++ ) {
if ( V_82 -> V_87 [ V_46 ] . V_88 < 0 ) {
F_5 ( L_15 , V_46 ,
V_82 -> V_87 [ V_46 ] . V_88 ) ;
} else
if ( V_82 -> V_87 [ V_46 ] . V_84 > 0 ) {
F_20 ( L_16 ,
V_82 -> V_87 [ V_46 ] . V_84 ) ;
F_19 ( V_7 ,
V_82 -> V_89 +
V_82 -> V_87 [ V_46 ] . V_90 ,
V_82 -> V_87 [ V_46 ] . V_84 ) ;
}
V_82 -> V_87 [ V_46 ] . V_88 = 0 ;
V_82 -> V_87 [ V_46 ] . V_84 = 0 ;
}
F_23 ( V_82 , V_91 ) ;
}
static int F_24 ( struct V_1 * V_2 , int V_92 )
{
return 0 ;
}
static void F_25 ( struct V_6 * V_7 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_93 ; V_46 ++ )
if ( V_7 -> V_94 [ V_46 ] != NULL ) {
F_20 ( L_17 , V_46 ) ;
F_26 ( V_7 -> V_94 [ V_46 ] ) ;
F_27 ( V_7 -> V_94 [ V_46 ] ) ;
}
if ( V_7 -> V_95 != NULL )
F_28 ( V_7 -> V_20 ,
V_7 -> V_96 , V_7 -> V_95 ,
V_7 -> V_97 ) ;
}
static int F_29 ( struct V_6 * V_7 )
{
T_1 V_98 = F_30 (
V_7 -> V_99 -> V_100 -> V_101 [ 0 ] . V_102 . V_103 ) ;
int V_104 = V_93 * V_105 *
V_98 , V_46 , V_106 , V_17 ;
int V_107 = 0 ;
F_20 ( L_18 ,
V_93 ,
V_105 , V_98 , V_104 ) ;
V_7 -> V_95 = F_31 ( V_7 -> V_20 ,
V_104 , V_108 , & V_7 -> V_97 ) ;
if ( V_7 -> V_95 == NULL )
return - V_109 ;
memset ( V_7 -> V_95 , 0 , V_104 ) ;
V_7 -> V_96 = V_104 ;
for ( V_46 = 0 ; V_46 < V_93 ; V_46 ++ ) {
V_7 -> V_94 [ V_46 ] = F_32 ( V_105 ,
V_91 ) ;
if ( V_7 -> V_94 [ V_46 ] == NULL ) {
V_17 = - V_109 ;
goto V_110;
}
}
for ( V_46 = 0 ; V_46 < V_93 ; V_46 ++ ) {
int V_111 = 0 ;
struct V_82 * V_82 = V_7 -> V_94 [ V_46 ] ;
F_20 ( L_19 ,
V_46 , V_107 ) ;
V_82 -> V_112 = V_7 -> V_20 ;
V_82 -> V_83 = V_7 ;
V_82 -> V_113 = F_22 ;
V_82 -> V_32 = V_114 ;
V_82 -> V_115 = V_116 ;
V_82 -> V_117 = 1 ;
V_82 -> V_86 = V_105 ;
V_82 -> V_85 = V_98 * V_105 ;
V_82 -> V_89 = V_7 -> V_95 + V_107 ;
V_107 += V_98 * V_105 ;
for ( V_106 = 0 ; V_106 < V_105 ; V_106 ++ ) {
F_20 ( L_20 ,
V_46 , V_106 , V_111 ) ;
V_82 -> V_87 [ V_106 ] . V_90 = V_111 ;
V_82 -> V_87 [ V_106 ] . V_118 = V_98 ;
V_111 += V_98 ;
}
if ( ( V_17 = F_23 ( V_7 -> V_94 [ V_46 ] , V_91 ) ) ) {
F_5 ( L_21 , V_46 , V_17 ) ;
goto V_110;
}
F_20 ( L_22 , V_46 ) ;
}
F_33 ( V_7 -> V_81 , V_119 |
V_120 | V_121 | V_122 ,
V_123 ) ;
F_34 ( V_7 -> V_81 , V_124 ) ;
F_35 ( V_7 -> V_81 , 1 , 1 , 1 ) ;
return 0 ;
V_110:
F_25 ( V_7 ) ;
return V_17 ;
}
static int F_36 ( struct V_6 * V_7 )
{
F_37 ( V_7 -> V_20 , 0 , 1 ) ;
switch ( V_7 -> V_20 -> V_125 ) {
case V_126 :
F_5 ( L_23 ) ;
return - V_127 ;
break;
case V_128 :
F_38 ( L_24 ) ;
break;
case V_129 :
F_38 ( L_25 ) ;
break;
case V_130 :
default:
F_5 ( L_26 ) ;
return - V_127 ;
}
F_39 ( V_7 -> V_99 , V_7 ) ;
return 0 ;
}
static void F_40 ( struct V_6 * V_7 )
{
F_39 ( V_7 -> V_99 , NULL ) ;
}
static int F_41 ( struct V_131 * V_132 ,
const struct V_133 * V_134 )
{
struct V_135 * V_20 = F_42 ( V_132 ) ;
struct V_6 * V_7 = NULL ;
struct V_1 * V_2 = NULL ;
int V_17 ;
if ( ( V_2 = F_43 ( sizeof( struct V_6 ) ) ) == NULL ) {
F_5 ( L_27 ) ;
return - V_109 ;
}
V_7 = V_2 -> V_8 ;
V_7 -> V_81 = V_2 ;
F_44 ( & V_7 -> V_18 ) ;
V_2 -> V_136 = F_16 ;
V_2 -> V_137 = F_17 ;
V_2 -> V_138 = F_18 ;
V_2 -> V_139 = F_13 ;
V_2 -> V_140 = F_24 ;
V_2 -> V_141 = 1 ;
V_2 -> V_142 = V_143 ;
V_2 -> V_112 = & V_20 -> V_112 ;
V_2 -> V_144 = V_145 ;
V_7 -> V_20 = V_20 ;
V_7 -> V_99 = V_132 ;
if ( ( V_17 = F_36 ( V_7 ) ) != 0 )
goto V_146;
if ( ( V_17 = F_45 ( V_2 ) ) != 0 )
goto V_147;
if ( ( V_17 = F_29 ( V_7 ) ) != 0 )
goto V_148;
F_38 ( L_28 , V_149 ) ;
return 0 ;
V_148:
F_46 ( V_2 ) ;
V_147:
F_40 ( V_7 ) ;
V_146:
F_47 ( V_2 ) ;
return V_17 ;
}
static void F_48 ( struct V_131 * V_132 )
{
struct V_6 * V_7 = F_49 ( V_132 ) ;
F_25 ( V_7 ) ;
F_46 ( V_7 -> V_81 ) ;
F_40 ( V_7 ) ;
F_47 ( V_7 -> V_81 ) ;
F_38 ( L_29 , V_149 ) ;
}
