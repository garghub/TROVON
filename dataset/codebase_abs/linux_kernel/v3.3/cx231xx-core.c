void F_1 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return;
if ( V_2 -> V_3 == NULL )
return;
if ( F_2 ( & V_2 -> V_4 ) > 0 ) {
F_3 ( & V_5 ) ;
F_4 ( & V_2 -> V_6 ) ;
F_5 ( & V_2 -> V_4 ) ;
F_6 ( & V_5 ) ;
}
}
void F_7 ( struct V_1 * V_2 )
{
F_3 ( & V_5 ) ;
F_8 ( & V_2 -> V_6 , & V_7 ) ;
F_9 ( & V_2 -> V_4 ) ;
F_6 ( & V_5 ) ;
}
int F_10 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = NULL ;
F_3 ( & V_5 ) ;
F_8 ( & V_9 -> V_10 , & V_11 ) ;
F_11 (dev, &cx231xx_devlist, devlist)
V_9 -> V_12 ( V_2 ) ;
F_12 (KERN_INFO DRIVER_NAME L_1 , ops->name) ;
F_6 ( & V_5 ) ;
return 0 ;
}
void F_13 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = NULL ;
F_3 ( & V_5 ) ;
F_11 (dev, &cx231xx_devlist, devlist)
V_9 -> V_13 ( V_2 ) ;
F_12 (KERN_INFO DRIVER_NAME L_2 , ops->name) ;
F_4 ( & V_9 -> V_10 ) ;
F_6 ( & V_5 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = NULL ;
F_3 ( & V_5 ) ;
if ( ! F_15 ( & V_11 ) ) {
F_11 (ops, &cx231xx_extension_devlist, next) {
if ( V_9 -> V_12 )
V_9 -> V_12 ( V_2 ) ;
}
}
F_6 ( & V_5 ) ;
}
void F_16 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = NULL ;
F_3 ( & V_5 ) ;
if ( ! F_15 ( & V_11 ) ) {
F_11 (ops, &cx231xx_extension_devlist, next) {
if ( V_9 -> V_13 )
V_9 -> V_13 ( V_2 ) ;
}
}
F_6 ( & V_5 ) ;
}
int F_17 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
int V_18 = 0 ;
struct V_1 * V_2 = V_15 -> V_2 ;
struct V_19 V_20 ;
T_1 V_21 = 0 ;
T_1 V_22 = 0 ;
T_1 V_23 = 0 ;
T_1 V_24 = 0 ;
if ( V_2 -> V_25 & V_26 )
return - V_27 ;
V_22 = V_15 -> V_28 ;
V_23 = V_15 -> V_29 ;
V_24 = V_15 -> V_30 ;
V_21 = V_17 -> V_21 ;
if ( V_21 == 1 )
V_20 . V_31 =
V_17 ->
V_32 << 9 | V_22 << 4 | V_21 << 2 |
V_23 << 1 | V_33 | V_24 << 6 ;
else
V_20 . V_31 =
V_17 ->
V_32 << 9 | V_22 << 4 | V_21 << 2 |
V_23 << 1 | V_33 | V_24 << 6 ;
if ( V_17 -> V_34 & V_35 ) {
V_20 . V_36 = V_15 -> V_37 + 4 ;
} else
V_20 . V_36 = V_15 -> V_37 ;
switch ( V_21 ) {
case 0 :
V_20 . V_38 = 0 ;
break;
case 1 :
V_20 . V_38 = ( V_17 -> V_39 & 0xff ) ;
break;
case 2 :
V_20 . V_38 = V_17 -> V_39 ;
break;
}
V_20 . V_40 = V_17 -> V_41 ;
V_20 . V_42 = 0 ;
if ( V_17 -> V_34 ) {
V_20 . V_34 = V_43 ;
memset ( V_17 -> V_44 , 0x00 , V_20 . V_40 ) ;
} else
V_20 . V_34 = V_45 ;
V_20 . V_46 = V_17 -> V_44 ;
V_18 = F_18 ( V_2 , & V_20 ) ;
if ( V_18 < 0 ) {
F_19
( L_3 ,
V_18 ) ;
}
return V_18 ;
}
static int F_20 ( struct V_1 * V_2 , unsigned int V_47 ,
T_2 V_48 , T_2 V_49 , T_3 V_50 , T_3 V_51 ,
void * V_52 , T_3 V_53 , int V_54 )
{
int V_55 , V_56 ;
if ( V_57 ) {
F_12 ( V_58 L_4
L_5 ,
V_2 -> V_59 ,
V_47 ,
( V_49 & V_43 ) ? L_6 : L_7 ,
V_49 ,
V_48 ,
V_50 & 0xff , V_50 >> 8 ,
V_51 & 0xff , V_51 >> 8 ,
V_53 & 0xff , V_53 >> 8 ) ;
if ( ! ( V_49 & V_43 ) ) {
F_12 ( V_60 L_8 ) ;
for ( V_56 = 0 ; V_56 < V_53 ; V_56 ++ )
F_12 ( V_60 L_9 ,
( ( unsigned char * ) V_52 ) [ V_56 ] ) ;
}
}
F_3 ( & V_2 -> V_61 ) ;
if ( ! ( V_49 & V_43 ) && V_53 )
memcpy ( V_2 -> V_62 , V_52 , V_53 ) ;
V_55 = F_21 ( V_2 -> V_3 , V_47 , V_48 , V_49 , V_50 ,
V_51 , V_2 -> V_62 , V_53 , V_54 ) ;
if ( ( V_49 & V_43 ) && V_53 )
memcpy ( V_52 , V_2 -> V_62 , V_53 ) ;
F_6 ( & V_2 -> V_61 ) ;
if ( V_57 ) {
if ( F_22 ( V_55 < 0 ) ) {
F_12 ( V_60 L_10 ) ;
return V_55 ;
}
if ( ( V_49 & V_43 ) ) {
F_12 ( V_60 L_11 ) ;
for ( V_56 = 0 ; V_56 < V_53 ; V_56 ++ )
F_12 ( V_60 L_9 ,
( ( unsigned char * ) V_52 ) [ V_56 ] ) ;
}
F_12 ( V_60 L_12 ) ;
}
return V_55 ;
}
int F_23 ( struct V_1 * V_2 , T_1 V_63 , T_4 V_64 ,
char * V_65 , int V_66 )
{
T_1 V_67 = 0 ;
int V_68 ;
int V_47 = F_24 ( V_2 -> V_3 , 0 ) ;
if ( V_2 -> V_25 & V_26 )
return - V_27 ;
if ( V_66 > V_69 )
return - V_70 ;
switch ( V_66 ) {
case 1 :
V_67 = V_71 ;
break;
case 2 :
V_67 = V_72 ;
break;
case 3 :
V_67 = V_73 ;
break;
case 4 :
V_67 = V_74 ;
break;
default:
V_67 = 0xFF ;
}
if ( V_67 == 0xFF )
return - V_70 ;
V_68 = F_20 ( V_2 , V_47 , V_63 ,
V_43 | V_75 | V_76 ,
V_67 , V_64 , V_65 , V_66 , V_77 ) ;
return V_68 ;
}
int F_18 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
int V_68 ;
int V_47 = 0 ;
int V_78 = 0 ;
T_1 * V_79 ;
if ( V_2 -> V_25 & V_26 )
return - V_27 ;
if ( ( V_20 -> V_40 > V_69 ) )
return - V_70 ;
if ( V_20 -> V_34 )
V_47 = F_24 ( V_2 -> V_3 , 0 ) ;
else
V_47 = F_25 ( V_2 -> V_3 , 0 ) ;
if ( ( V_20 -> V_40 > 4 ) && ( ( V_20 -> V_36 == 0x4 ) ||
( V_20 -> V_36 == 0x5 ) ||
( V_20 -> V_36 == 0x6 ) ) ) {
V_78 = 0 ;
V_79 = V_20 -> V_46 ;
V_78 = V_20 -> V_40 ;
V_20 -> V_31 = V_20 -> V_31 & 0xFFFB ;
V_20 -> V_31 = ( V_20 -> V_31 & 0xFFBD ) | 0x2 ;
V_68 = F_20 ( V_2 , V_47 , V_20 -> V_36 ,
V_20 -> V_34 | V_75 | V_76 ,
V_20 -> V_31 , V_20 -> V_38 , V_79 ,
0x0004 , V_77 ) ;
V_78 = V_78 - 4 ;
V_20 -> V_31 = ( V_20 -> V_31 & 0xFFBD ) | 0x42 ;
while ( V_78 - 4 > 0 ) {
V_79 = V_79 + 4 ;
V_68 = F_20 ( V_2 , V_47 ,
V_20 -> V_36 ,
V_20 -> V_34 | V_75 | V_76 ,
V_20 -> V_31 , V_20 -> V_38 , V_79 ,
0x0004 , V_77 ) ;
V_78 = V_78 - 4 ;
}
V_20 -> V_31 = ( V_20 -> V_31 & 0xFFBD ) | 0x40 ;
V_79 = V_79 + 4 ;
V_68 = F_20 ( V_2 , V_47 , V_20 -> V_36 ,
V_20 -> V_34 | V_75 | V_76 ,
V_20 -> V_31 , V_20 -> V_38 , V_79 ,
V_78 , V_77 ) ;
} else {
V_68 = F_20 ( V_2 , V_47 , V_20 -> V_36 ,
V_20 -> V_34 | V_75 | V_76 ,
V_20 -> V_31 , V_20 -> V_38 ,
V_20 -> V_46 , V_20 -> V_40 , V_77 ) ;
}
return V_68 ;
}
int F_26 ( struct V_1 * V_2 , T_1 V_63 , T_4 V_64 , char * V_65 ,
int V_66 )
{
T_1 V_67 = 0 ;
int V_68 ;
int V_47 = F_25 ( V_2 -> V_3 , 0 ) ;
if ( V_2 -> V_25 & V_26 )
return - V_27 ;
if ( ( V_66 < 1 ) || ( V_66 > V_69 ) )
return - V_70 ;
switch ( V_66 ) {
case 1 :
V_67 = V_71 ;
break;
case 2 :
V_67 = V_72 ;
break;
case 3 :
V_67 = V_73 ;
break;
case 4 :
V_67 = V_74 ;
break;
default:
V_67 = 0xFF ;
}
if ( V_67 == 0xFF )
return - V_70 ;
if ( V_57 ) {
int V_80 ;
F_27 ( L_13
L_14 ,
V_47 ,
V_45 | V_75 | V_76 ,
V_63 , 0 , V_67 , V_64 & 0xff ,
V_64 >> 8 , V_66 & 0xff , V_66 >> 8 ) ;
for ( V_80 = 0 ; V_80 < V_66 ; V_80 ++ )
F_27 ( L_9 , ( unsigned char ) V_65 [ V_80 ] ) ;
F_27 ( L_12 ) ;
}
V_68 = F_20 ( V_2 , V_47 , V_63 ,
V_45 | V_75 | V_76 ,
V_67 , V_64 , V_65 , V_66 , V_77 ) ;
return V_68 ;
}
int F_28 ( struct V_1 * V_2 )
{
int V_81 , V_82 = V_2 -> V_83 . V_84 ;
unsigned int V_85 = V_2 -> V_86 * 2 + 4 ;
T_5 V_87 = 0 ;
if ( V_2 -> V_86 * 2 * V_2 -> V_88 > 720 * 240 * 2 )
V_85 *= 2 ;
if ( V_2 -> V_86 > 360 ) {
V_2 -> V_83 . V_84 = 3 ;
} else if ( V_2 -> V_86 > 180 ) {
V_2 -> V_83 . V_84 = 2 ;
} else if ( V_2 -> V_86 > 0 ) {
V_2 -> V_83 . V_84 = 1 ;
} else {
V_2 -> V_83 . V_84 = 0 ;
}
if ( V_2 -> V_89 == 0 )
V_2 -> V_83 . V_84 = 0 ;
F_29 ( L_15 , V_2 -> V_83 . V_84 ) ;
V_87 =
V_2 -> V_90 . V_91 [ 0 ] . V_92 .
V_93 + 1 ;
if ( V_2 -> V_83 . V_84 != V_82 ) {
F_29 ( L_16 ,
V_85 , V_2 -> V_83 . V_84 ) ;
if ( V_2 -> V_83 . V_94 != NULL )
V_2 -> V_83 . V_95 =
V_2 -> V_83 . V_94 [ V_2 -> V_83 . V_84 ] ;
F_29 ( L_17 ,
V_2 -> V_83 . V_84 ,
V_2 -> V_83 . V_95 ) ;
V_81 =
F_30 ( V_2 -> V_3 , V_87 ,
V_2 -> V_83 . V_84 ) ;
if ( V_81 < 0 ) {
F_31
( L_18 ,
V_2 -> V_83 . V_84 , V_81 ) ;
return V_81 ;
}
}
return 0 ;
}
int F_32 ( struct V_1 * V_2 , T_1 V_51 , T_1 V_84 )
{
int V_18 = 0 ;
T_5 V_87 = 0 ;
T_5 V_95 = 0 ;
switch ( V_51 ) {
case V_96 :
V_87 =
V_2 -> V_90 . V_91 [ 0 ] . V_92 .
V_97 + 1 ;
V_2 -> V_98 . V_84 = V_84 ;
if ( V_2 -> V_98 . V_94 != NULL )
V_95 = V_2 -> V_98 . V_95 =
V_2 -> V_98 . V_94 [ V_2 -> V_98 . V_84 ] ;
break;
case V_99 :
V_87 =
V_2 -> V_90 . V_91 [ 0 ] . V_92 .
V_100 + 1 ;
break;
case V_101 :
V_87 =
V_2 -> V_90 . V_91 [ 0 ] . V_92 .
V_102 + 1 ;
V_2 -> V_103 . V_84 = V_84 ;
if ( V_2 -> V_103 . V_94 != NULL )
V_95 = V_2 -> V_103 . V_95 =
V_2 -> V_103 . V_94 [ V_2 -> V_103 . V_84 ] ;
break;
case V_104 :
V_87 =
V_2 -> V_90 . V_91 [ 0 ] . V_92 .
V_93 + 1 ;
V_2 -> V_83 . V_84 = V_84 ;
if ( V_2 -> V_83 . V_94 != NULL )
V_95 = V_2 -> V_83 . V_95 =
V_2 -> V_83 . V_94 [ V_2 -> V_83 .
V_84 ] ;
break;
case V_105 :
if ( V_2 -> V_106 . V_107 )
return 0 ;
V_87 =
V_2 -> V_90 . V_91 [ 0 ] . V_92 .
V_108 + 1 ;
V_2 -> V_109 . V_84 = V_84 ;
if ( V_2 -> V_109 . V_94 != NULL )
V_95 = V_2 -> V_109 . V_95 =
V_2 -> V_109 . V_94 [ V_2 -> V_109 . V_84 ] ;
break;
case V_110 :
V_87 =
V_2 -> V_90 . V_91 [ 0 ] . V_92 .
V_111 + 1 ;
V_2 -> V_112 . V_84 = V_84 ;
if ( V_2 -> V_112 . V_94 != NULL )
V_95 = V_2 -> V_112 . V_95 =
V_2 -> V_112 . V_94 [ V_2 ->
V_112 .
V_84 ] ;
break;
default:
break;
}
if ( V_84 > 0 && V_95 == 0 ) {
F_31
( L_19 ,
V_87 , V_84 ) ;
if ( V_2 -> V_106 . V_107 )
return - 1 ;
}
F_29 ( L_20
L_21 , V_84 , V_95 ,
V_87 ) ;
if ( V_87 > 0 ) {
V_18 = F_30 ( V_2 -> V_3 , V_87 , V_84 ) ;
if ( V_18 < 0 ) {
F_31
( L_22 ,
V_87 , V_84 , V_18 ) ;
return V_18 ;
}
}
return V_18 ;
}
int F_33 ( struct V_1 * V_2 , struct V_113 * V_114 )
{
int V_55 = 0 ;
if ( ! V_114 )
return V_55 ;
while ( V_114 -> V_115 >= 0 ) {
V_55 = F_34 ( V_2 , V_114 -> V_116 , V_114 -> V_67 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( V_114 -> V_115 > 0 )
F_35 ( V_114 -> V_115 ) ;
V_114 ++ ;
}
return V_55 ;
}
int F_36 ( struct V_1 * V_2 )
{
T_1 V_18 = 0 ;
T_1 V_50 [ 4 ] = { 0 , 0 , 0 , 0 } ;
V_18 = F_23 ( V_2 , V_117 , V_118 ,
V_50 , 4 ) ;
F_29 ( L_23 , V_118 ,
V_50 [ 0 ] , V_50 [ 1 ] , V_50 [ 2 ] , V_50 [ 3 ] ) ;
F_29 ( L_24 ) ;
V_50 [ 1 ] = ( T_1 ) 0x3 ;
V_18 = F_26 ( V_2 , V_119 ,
V_118 , V_50 , 4 ) ;
F_35 ( 10 ) ;
V_50 [ 1 ] = ( T_1 ) 0x0 ;
V_18 = F_26 ( V_2 , V_119 ,
V_118 , V_50 , 4 ) ;
F_35 ( 10 ) ;
V_50 [ 1 ] = ( T_1 ) 0x3 ;
V_18 = F_26 ( V_2 , V_119 ,
V_118 , V_50 , 4 ) ;
F_35 ( 10 ) ;
V_18 = F_23 ( V_2 , V_117 , V_118 ,
V_50 , 4 ) ;
F_29 ( L_23 , V_118 ,
V_50 [ 0 ] , V_50 [ 1 ] , V_50 [ 2 ] , V_50 [ 3 ] ) ;
return V_18 ;
}
int F_37 ( struct V_1 * V_2 )
{
return F_38 ( V_2 ) ;
}
int F_39 ( struct V_1 * V_2 , enum V_120 V_121 )
{
int V_81 = 0 ;
if ( V_2 -> V_122 == V_121 )
return 0 ;
if ( V_121 == V_123 ) {
V_2 -> V_122 = V_121 ;
}
if ( V_2 -> V_122 != V_123 )
return - V_70 ;
V_2 -> V_122 = V_121 ;
if ( V_2 -> V_122 == V_124 ) {
switch ( V_2 -> V_125 ) {
case V_126 :
case V_127 :
case V_128 :
case V_129 :
V_81 = F_40 ( V_2 , 0 ) ;
break;
case V_130 :
case V_131 :
V_81 = F_40 ( V_2 , 1 ) ;
break;
case V_132 :
V_81 = F_41 ( V_2 ,
V_133 ) ;
break;
default:
break;
}
} else {
switch ( V_2 -> V_125 ) {
case V_126 :
case V_127 :
case V_128 :
case V_129 :
V_81 = F_40 ( V_2 , 1 ) ;
break;
case V_130 :
case V_131 :
case V_132 :
case V_134 :
case V_135 :
case V_136 :
V_81 = F_40 ( V_2 , 0 ) ;
break;
default:
break;
}
}
return 0 ;
}
int F_42 ( struct V_1 * V_2 , T_1 * V_137 , T_4 V_53 )
{
int V_81 = 0 ;
int V_138 , V_68 = - V_139 ;
T_5 * V_140 ;
V_140 = F_43 ( 4096 , V_141 ) ;
if ( V_140 == NULL ) {
F_19 ( L_25 ) ;
return - V_139 ;
}
memcpy ( & V_140 [ 0 ] , V_137 , 4096 ) ;
V_68 = F_44 ( V_2 -> V_3 , F_45 ( V_2 -> V_3 , 5 ) ,
V_140 , 4096 , & V_138 , 2000 ) ;
if ( V_68 )
F_19 ( L_26 , V_68 ,
V_53 , V_138 ) ;
else {
V_81 = V_138 != V_53 ? - 1 : 0 ;
}
F_46 ( V_140 ) ;
return 0 ;
}
static void F_47 ( struct V_142 * V_142 )
{
struct V_143 * V_144 = V_142 -> V_145 ;
struct V_146 * V_147 =
F_48 ( V_144 , struct V_146 , V_148 ) ;
struct V_1 * V_2 = F_48 ( V_147 , struct V_1 , V_83 ) ;
int V_55 , V_56 ;
switch ( V_142 -> V_18 ) {
case 0 :
case - V_149 :
break;
case - V_150 :
case - V_151 :
case - V_152 :
return;
default:
F_27 ( L_27 , V_142 -> V_18 ) ;
break;
}
F_49 ( & V_2 -> V_83 . V_153 ) ;
V_55 = V_2 -> V_83 . V_154 . V_155 ( V_2 , V_142 ) ;
F_50 ( & V_2 -> V_83 . V_153 ) ;
for ( V_56 = 0 ; V_56 < V_142 -> V_156 ; V_56 ++ ) {
V_142 -> V_157 [ V_56 ] . V_18 = 0 ;
V_142 -> V_157 [ V_56 ] . V_158 = 0 ;
}
V_142 -> V_18 = 0 ;
V_142 -> V_18 = F_51 ( V_142 , V_159 ) ;
if ( V_142 -> V_18 ) {
F_27 ( L_28 ,
V_142 -> V_18 ) ;
}
}
static void F_52 ( struct V_142 * V_142 )
{
struct V_143 * V_144 = V_142 -> V_145 ;
struct V_146 * V_147 =
F_48 ( V_144 , struct V_146 , V_148 ) ;
struct V_1 * V_2 = F_48 ( V_147 , struct V_1 , V_83 ) ;
int V_55 ;
switch ( V_142 -> V_18 ) {
case 0 :
case - V_149 :
break;
case - V_150 :
case - V_151 :
case - V_152 :
return;
default:
F_27 ( L_27 , V_142 -> V_18 ) ;
break;
}
F_49 ( & V_2 -> V_83 . V_153 ) ;
V_55 = V_2 -> V_83 . V_160 . V_161 ( V_2 , V_142 ) ;
F_50 ( & V_2 -> V_83 . V_153 ) ;
V_142 -> V_18 = 0 ;
V_142 -> V_18 = F_51 ( V_142 , V_159 ) ;
if ( V_142 -> V_18 ) {
F_27 ( L_28 ,
V_142 -> V_18 ) ;
}
}
void F_53 ( struct V_1 * V_2 )
{
struct V_143 * V_144 = & V_2 -> V_83 . V_148 ;
struct V_142 * V_142 ;
int V_56 ;
F_27 ( L_29 ) ;
V_2 -> V_83 . V_154 . V_162 = - 1 ;
for ( V_56 = 0 ; V_56 < V_2 -> V_83 . V_154 . V_163 ; V_56 ++ ) {
V_142 = V_2 -> V_83 . V_154 . V_142 [ V_56 ] ;
if ( V_142 ) {
if ( ! F_54 () )
F_55 ( V_142 ) ;
else
F_56 ( V_142 ) ;
if ( V_2 -> V_83 . V_154 . V_164 [ V_56 ] ) {
F_57 ( V_2 -> V_3 ,
V_142 -> V_165 ,
V_2 -> V_83 . V_154 .
V_164 [ V_56 ] ,
V_142 -> V_166 ) ;
}
F_58 ( V_142 ) ;
V_2 -> V_83 . V_154 . V_142 [ V_56 ] = NULL ;
}
V_2 -> V_83 . V_154 . V_164 [ V_56 ] = NULL ;
}
F_46 ( V_2 -> V_83 . V_154 . V_142 ) ;
F_46 ( V_2 -> V_83 . V_154 . V_164 ) ;
F_46 ( V_144 -> V_167 ) ;
V_2 -> V_83 . V_154 . V_142 = NULL ;
V_2 -> V_83 . V_154 . V_164 = NULL ;
V_2 -> V_83 . V_154 . V_163 = 0 ;
V_144 -> V_167 = NULL ;
if ( V_2 -> V_168 == 0 )
F_59 ( V_2 , 0 , V_169 ) ;
else
F_59 ( V_2 , 0 , V_170 ) ;
}
void F_60 ( struct V_1 * V_2 )
{
struct V_142 * V_142 ;
int V_56 ;
F_27 ( L_30 ) ;
V_2 -> V_83 . V_160 . V_162 = - 1 ;
for ( V_56 = 0 ; V_56 < V_2 -> V_83 . V_160 . V_163 ; V_56 ++ ) {
V_142 = V_2 -> V_83 . V_160 . V_142 [ V_56 ] ;
if ( V_142 ) {
if ( ! F_54 () )
F_55 ( V_142 ) ;
else
F_56 ( V_142 ) ;
if ( V_2 -> V_83 . V_160 . V_164 [ V_56 ] ) {
F_57 ( V_2 -> V_3 ,
V_142 -> V_165 ,
V_2 -> V_83 . V_154 .
V_164 [ V_56 ] ,
V_142 -> V_166 ) ;
}
F_58 ( V_142 ) ;
V_2 -> V_83 . V_160 . V_142 [ V_56 ] = NULL ;
}
V_2 -> V_83 . V_160 . V_164 [ V_56 ] = NULL ;
}
F_46 ( V_2 -> V_83 . V_160 . V_142 ) ;
F_46 ( V_2 -> V_83 . V_160 . V_164 ) ;
V_2 -> V_83 . V_160 . V_142 = NULL ;
V_2 -> V_83 . V_160 . V_164 = NULL ;
V_2 -> V_83 . V_160 . V_163 = 0 ;
if ( V_2 -> V_168 == 0 )
F_59 ( V_2 , 0 , V_169 ) ;
else
F_59 ( V_2 , 0 , V_170 ) ;
}
int F_61 ( struct V_1 * V_2 , int V_171 ,
int V_163 , int V_95 ,
int (* V_155) ( struct V_1 * V_2 , struct V_142 * V_142 ) )
{
struct V_143 * V_144 = & V_2 -> V_83 . V_148 ;
int V_56 ;
int V_172 , V_47 ;
struct V_142 * V_142 ;
int V_173 , V_174 ;
int V_55 ;
F_53 ( V_2 ) ;
V_144 -> V_167 = F_43 ( 4096 , V_141 ) ;
if ( V_144 -> V_167 == NULL ) {
F_19 ( L_25 ) ;
return - V_139 ;
}
V_2 -> V_83 . V_154 . V_155 = V_155 ;
V_2 -> V_83 . V_154 . V_163 = V_163 ;
V_144 -> V_175 = 0 ;
V_144 -> V_176 = 0 ;
V_144 -> V_177 = 0 ;
V_144 -> V_178 = - 1 ;
V_144 -> V_179 = 0 ;
V_144 -> V_180 = V_2 -> V_88 / 2 ;
V_144 -> V_181 = V_2 -> V_86 << 1 ;
V_144 -> V_182 = 0 ;
V_144 -> V_183 = 0 ;
V_144 -> V_184 = 0 ;
V_144 -> V_185 = 0 ;
V_144 -> V_186 = V_187 ;
V_144 -> V_188 [ 0 ] = 0x00 ;
V_144 -> V_188 [ 1 ] = 0x00 ;
V_144 -> V_188 [ 2 ] = 0x01 ;
V_144 -> V_188 [ 3 ] = 0xBA ;
for ( V_56 = 0 ; V_56 < 8 ; V_56 ++ )
V_144 -> V_189 [ V_56 ] = 0 ;
V_2 -> V_83 . V_154 . V_142 =
F_43 ( sizeof( void * ) * V_163 , V_141 ) ;
if ( ! V_2 -> V_83 . V_154 . V_142 ) {
F_31 ( L_31 ) ;
return - V_139 ;
}
V_2 -> V_83 . V_154 . V_164 =
F_43 ( sizeof( void * ) * V_163 , V_141 ) ;
if ( ! V_2 -> V_83 . V_154 . V_164 ) {
F_31 ( L_32 ) ;
F_46 ( V_2 -> V_83 . V_154 . V_142 ) ;
return - V_139 ;
}
V_2 -> V_83 . V_154 . V_95 = V_95 ;
V_2 -> V_83 . V_154 . V_65 = NULL ;
V_172 = V_171 * V_2 -> V_83 . V_154 . V_95 ;
if ( V_2 -> V_168 == 1 )
V_2 -> V_83 . V_190 = 0x81 ;
else
V_2 -> V_83 . V_190 = 0x84 ;
for ( V_56 = 0 ; V_56 < V_2 -> V_83 . V_154 . V_163 ; V_56 ++ ) {
V_142 = F_62 ( V_171 , V_141 ) ;
if ( ! V_142 ) {
F_63 ( L_33 , V_56 ) ;
F_53 ( V_2 ) ;
return - V_139 ;
}
V_2 -> V_83 . V_154 . V_142 [ V_56 ] = V_142 ;
V_2 -> V_83 . V_154 . V_164 [ V_56 ] =
F_64 ( V_2 -> V_3 , V_172 , V_141 ,
& V_142 -> V_166 ) ;
if ( ! V_2 -> V_83 . V_154 . V_164 [ V_56 ] ) {
F_63 ( L_34
L_35 ,
V_172 , V_56 ,
F_65 () ? L_36 : L_37 ) ;
F_53 ( V_2 ) ;
return - V_139 ;
}
memset ( V_2 -> V_83 . V_154 . V_164 [ V_56 ] , 0 , V_172 ) ;
V_47 =
F_66 ( V_2 -> V_3 , V_2 -> V_83 . V_190 ) ;
F_67 ( V_142 , V_2 -> V_3 , V_47 ,
V_2 -> V_83 . V_154 . V_164 [ V_56 ] ,
V_172 , F_47 , V_144 , 1 ) ;
V_142 -> V_156 = V_171 ;
V_142 -> V_191 = V_192 | V_193 ;
V_174 = 0 ;
for ( V_173 = 0 ; V_173 < V_171 ; V_173 ++ ) {
V_142 -> V_157 [ V_173 ] . V_194 = V_174 ;
V_142 -> V_157 [ V_173 ] . V_195 =
V_2 -> V_83 . V_154 . V_95 ;
V_174 += V_2 -> V_83 . V_154 . V_95 ;
}
}
F_68 ( & V_144 -> V_196 ) ;
for ( V_56 = 0 ; V_56 < V_2 -> V_83 . V_154 . V_163 ; V_56 ++ ) {
V_55 = F_51 ( V_2 -> V_83 . V_154 . V_142 [ V_56 ] ,
V_159 ) ;
if ( V_55 ) {
F_63 ( L_38 , V_56 ,
V_55 ) ;
F_53 ( V_2 ) ;
return V_55 ;
}
}
if ( V_2 -> V_168 == 0 )
F_59 ( V_2 , 1 , V_169 ) ;
else
F_59 ( V_2 , 1 , V_170 ) ;
return 0 ;
}
int F_69 ( struct V_1 * V_2 , int V_171 ,
int V_163 , int V_95 ,
int (* V_161) ( struct V_1 * V_2 , struct V_142 * V_142 ) )
{
struct V_143 * V_144 = & V_2 -> V_83 . V_148 ;
int V_56 ;
int V_172 , V_47 ;
struct V_142 * V_142 ;
int V_55 ;
V_2 -> V_197 = V_2 -> V_197 > 2 ? 2 : V_2 -> V_197 ;
F_29 ( L_39 , V_2 -> V_197 ) ;
F_70 ( V_2 , V_2 -> V_197 ) ;
F_60 ( V_2 ) ;
V_2 -> V_83 . V_160 . V_161 = V_161 ;
V_2 -> V_83 . V_160 . V_163 = V_163 ;
V_144 -> V_175 = 0 ;
V_144 -> V_176 = 0 ;
V_144 -> V_177 = 0 ;
V_144 -> V_178 = - 1 ;
V_144 -> V_179 = 0 ;
V_144 -> V_180 = V_2 -> V_88 / 2 ;
V_144 -> V_181 = V_2 -> V_86 << 1 ;
V_144 -> V_182 = 0 ;
V_144 -> V_183 = 0 ;
V_144 -> V_184 = 0 ;
V_144 -> V_185 = 0 ;
V_144 -> V_188 [ 0 ] = 0x00 ;
V_144 -> V_188 [ 1 ] = 0x00 ;
V_144 -> V_188 [ 2 ] = 0x01 ;
V_144 -> V_188 [ 3 ] = 0xBA ;
for ( V_56 = 0 ; V_56 < 8 ; V_56 ++ )
V_144 -> V_189 [ V_56 ] = 0 ;
V_2 -> V_83 . V_160 . V_142 =
F_43 ( sizeof( void * ) * V_163 , V_141 ) ;
if ( ! V_2 -> V_83 . V_160 . V_142 ) {
F_31 ( L_31 ) ;
return - V_139 ;
}
V_2 -> V_83 . V_160 . V_164 =
F_43 ( sizeof( void * ) * V_163 , V_141 ) ;
if ( ! V_2 -> V_83 . V_160 . V_164 ) {
F_31 ( L_32 ) ;
F_46 ( V_2 -> V_83 . V_160 . V_142 ) ;
return - V_139 ;
}
V_2 -> V_83 . V_160 . V_95 = V_95 ;
V_2 -> V_83 . V_160 . V_65 = NULL ;
V_172 = V_171 * V_2 -> V_83 . V_160 . V_95 ;
if ( V_2 -> V_168 == 1 )
V_2 -> V_83 . V_190 = 0x81 ;
else
V_2 -> V_83 . V_190 = 0x84 ;
for ( V_56 = 0 ; V_56 < V_2 -> V_83 . V_160 . V_163 ; V_56 ++ ) {
V_142 = F_62 ( 0 , V_141 ) ;
if ( ! V_142 ) {
F_63 ( L_40 , V_56 ) ;
F_60 ( V_2 ) ;
return - V_139 ;
}
V_2 -> V_83 . V_160 . V_142 [ V_56 ] = V_142 ;
V_142 -> V_191 = V_193 ;
V_2 -> V_83 . V_160 . V_164 [ V_56 ] =
F_64 ( V_2 -> V_3 , V_172 , V_141 ,
& V_142 -> V_166 ) ;
if ( ! V_2 -> V_83 . V_160 . V_164 [ V_56 ] ) {
F_63 ( L_34
L_35 ,
V_172 , V_56 ,
F_65 () ? L_36 : L_37 ) ;
F_60 ( V_2 ) ;
return - V_139 ;
}
memset ( V_2 -> V_83 . V_160 . V_164 [ V_56 ] , 0 , V_172 ) ;
V_47 = F_71 ( V_2 -> V_3 ,
V_2 -> V_83 . V_190 ) ;
F_72 ( V_142 , V_2 -> V_3 , V_47 ,
V_2 -> V_83 . V_160 . V_164 [ V_56 ] ,
V_172 , F_52 , V_144 ) ;
}
F_68 ( & V_144 -> V_196 ) ;
for ( V_56 = 0 ; V_56 < V_2 -> V_83 . V_160 . V_163 ; V_56 ++ ) {
V_55 = F_51 ( V_2 -> V_83 . V_160 . V_142 [ V_56 ] ,
V_159 ) ;
if ( V_55 ) {
F_63 ( L_38 , V_56 ,
V_55 ) ;
F_60 ( V_2 ) ;
return V_55 ;
}
}
if ( V_2 -> V_168 == 0 )
F_59 ( V_2 , 1 , V_169 ) ;
else
F_59 ( V_2 , 1 , V_170 ) ;
return 0 ;
}
void F_73 ( struct V_1 * V_2 )
{
int V_18 = 0 ;
T_1 V_67 [ 4 ] = { 0 , 0 , 0 , 0 } ;
V_67 [ 0 ] = 0x00 ;
V_67 [ 1 ] = 0x03 ;
V_67 [ 2 ] = 0x00 ;
V_67 [ 3 ] = 0x00 ;
V_18 = F_26 ( V_2 , V_119 ,
V_198 , V_67 , 4 ) ;
V_67 [ 0 ] = 0x00 ;
V_67 [ 1 ] = 0x70 ;
V_67 [ 2 ] = 0x04 ;
V_67 [ 3 ] = 0x00 ;
V_18 = F_26 ( V_2 , V_119 ,
V_199 , V_67 , 4 ) ;
}
void F_74 ( struct V_1 * V_2 )
{
int V_18 = 0 ;
T_1 V_67 [ 4 ] = { 0 , 0 , 0 , 0 } ;
V_67 [ 0 ] = 0x03 ;
V_67 [ 1 ] = 0x03 ;
V_67 [ 2 ] = 0x00 ;
V_67 [ 3 ] = 0x00 ;
V_18 = F_26 ( V_2 , V_119 ,
V_198 , V_67 , 4 ) ;
V_67 [ 0 ] = 0x04 ;
V_67 [ 1 ] = 0xA3 ;
V_67 [ 2 ] = 0x3B ;
V_67 [ 3 ] = 0x00 ;
V_18 = F_26 ( V_2 , V_119 ,
V_199 , V_67 , 4 ) ;
}
int F_75 ( struct V_1 * V_2 )
{
int V_81 = 0 ;
V_2 -> V_15 [ 0 ] . V_37 = 0 ;
V_2 -> V_15 [ 0 ] . V_2 = V_2 ;
V_2 -> V_15 [ 0 ] . V_28 = V_200 ;
V_2 -> V_15 [ 0 ] . V_29 = 0 ;
V_2 -> V_15 [ 0 ] . V_30 = 0 ;
V_2 -> V_15 [ 1 ] . V_37 = 1 ;
V_2 -> V_15 [ 1 ] . V_2 = V_2 ;
V_2 -> V_15 [ 1 ] . V_28 = V_200 ;
V_2 -> V_15 [ 1 ] . V_29 = 0 ;
V_2 -> V_15 [ 1 ] . V_30 = 0 ;
V_2 -> V_15 [ 2 ] . V_37 = 2 ;
V_2 -> V_15 [ 2 ] . V_2 = V_2 ;
V_2 -> V_15 [ 2 ] . V_28 = V_200 ;
V_2 -> V_15 [ 2 ] . V_29 = 0 ;
V_2 -> V_15 [ 2 ] . V_30 = 0 ;
F_76 ( & V_2 -> V_15 [ 0 ] ) ;
F_76 ( & V_2 -> V_15 [ 1 ] ) ;
F_76 ( & V_2 -> V_15 [ 2 ] ) ;
if ( V_2 -> V_106 . V_201 ) {
V_81 = F_41 ( V_2 ,
V_202 ) ;
if ( V_81 < 0 ) {
F_31
( L_41 ,
V_203 , V_81 ) ;
return V_81 ;
}
} else {
V_81 = F_41 ( V_2 ,
V_204 ) ;
if ( V_81 < 0 ) {
F_31
( L_41 ,
V_203 , V_81 ) ;
return V_81 ;
}
}
if ( ( V_2 -> V_106 . V_205 == V_206 ) ||
( V_2 -> V_106 . V_205 == V_207 ) )
F_33 ( V_2 , V_2 -> V_106 . V_208 ) ;
V_81 = F_77 ( V_2 , 0x23c ) ;
if ( V_81 < 0 ) {
F_31
( L_42 ,
V_203 , V_81 ) ;
return V_81 ;
}
V_81 = F_78 ( V_2 ) ;
if ( V_81 < 0 ) {
F_31
( L_43 ,
V_203 , V_81 ) ;
return V_81 ;
}
V_81 = F_79 ( V_2 , V_209 ) ;
if ( V_81 < 0 ) {
F_31
( L_44 ,
V_203 , V_81 ) ;
return V_81 ;
}
V_81 = F_80 ( V_2 ) ;
if ( V_81 < 0 ) {
F_31
( L_45 ,
V_203 , V_81 ) ;
return V_81 ;
}
V_81 = F_81 ( V_2 ) ;
if ( V_81 < 0 ) {
F_31 ( L_46 ,
V_203 , V_81 ) ;
return V_81 ;
}
switch ( V_2 -> V_125 ) {
case V_126 :
case V_127 :
case V_128 :
case V_129 :
V_81 = F_40 ( V_2 , 1 ) ;
break;
case V_130 :
case V_131 :
case V_132 :
case V_134 :
case V_135 :
case V_136 :
V_81 = F_40 ( V_2 , 0 ) ;
break;
default:
break;
}
if ( V_81 < 0 ) {
F_31
( L_47 ,
V_203 , V_81 ) ;
return V_81 ;
}
F_32 ( V_2 , V_104 , 0 ) ;
F_32 ( V_2 , V_105 , 0 ) ;
F_32 ( V_2 , V_110 , 0 ) ;
if ( V_2 -> V_106 . V_210 )
F_32 ( V_2 , V_96 , 0 ) ;
V_81 = F_82 ( V_2 , true ) ;
return V_81 ;
}
void F_83 ( struct V_1 * V_2 )
{
F_84 ( & V_2 -> V_15 [ 2 ] ) ;
F_84 ( & V_2 -> V_15 [ 1 ] ) ;
F_84 ( & V_2 -> V_15 [ 0 ] ) ;
}
int F_85 ( struct V_1 * V_2 , T_5 V_211 , T_1 * V_212 ,
T_1 V_66 , T_1 V_48 , T_1 V_34 )
{
int V_18 = 0 ;
struct V_19 V_20 ;
V_20 . V_31 = ( T_4 ) ( V_211 >> 16 & 0xffff ) ;
if ( ! V_48 ) {
if ( V_34 )
V_20 . V_36 = V_213 ;
else
V_20 . V_36 = V_214 ;
} else {
if ( V_34 )
V_20 . V_36 = V_215 ;
else
V_20 . V_36 = V_216 ;
}
V_20 . V_38 = ( T_4 ) ( V_211 & 0xffff ) ;
V_20 . V_40 = V_66 ;
V_20 . V_42 = 0 ;
V_20 . V_46 = V_212 ;
if ( V_34 ) {
V_20 . V_34 = V_43 ;
memset ( V_20 . V_46 , 0x00 , V_20 . V_40 ) ;
} else
V_20 . V_34 = V_45 ;
V_18 = F_18 ( V_2 , & V_20 ) ;
if ( V_18 < 0 ) {
F_19
( L_3 ,
V_18 ) ;
}
return V_18 ;
}
int F_86 ( struct V_1 * V_2 , T_4 V_217 , T_5 V_122 )
{
T_1 V_50 [ 4 ] = { 0x0 , 0x0 , 0x0 , 0x0 } ;
T_5 V_218 = 0 ;
int V_18 = 0 ;
V_18 =
F_23 ( V_2 , V_117 , V_217 , V_50 , 4 ) ;
if ( V_18 < 0 )
return V_18 ;
V_218 = * ( ( T_5 * ) V_50 ) ;
V_218 |= V_122 ;
V_50 [ 0 ] = ( T_1 ) V_218 ;
V_50 [ 1 ] = ( T_1 ) ( V_218 >> 8 ) ;
V_50 [ 2 ] = ( T_1 ) ( V_218 >> 16 ) ;
V_50 [ 3 ] = ( T_1 ) ( V_218 >> 24 ) ;
V_18 =
F_26 ( V_2 , V_119 , V_217 , V_50 , 4 ) ;
return V_18 ;
}
int F_87 ( struct V_1 * V_2 , T_1 V_32 , T_4 V_219 ,
T_1 V_21 , T_5 * V_52 , T_1 V_220 , int V_221 )
{
int V_18 = 0 ;
struct V_16 V_17 ;
T_1 V_50 [ 64 ] = L_48 ;
if ( V_21 == 0 )
V_219 = 0 ;
else if ( V_21 == 1 )
V_219 &= 0xff ;
V_17 . V_32 = V_32 >> 1 ;
V_17 . V_34 = V_35 ;
V_17 . V_21 = V_21 ;
V_17 . V_39 = V_219 ;
V_17 . V_41 = V_220 ;
V_17 . V_44 = ( T_1 * ) V_50 ;
if ( V_221 == 0 )
V_18 = V_2 -> F_17 ( & V_2 -> V_15 [ 0 ] ,
& V_17 ) ;
else if ( V_221 == 1 )
V_18 = V_2 -> F_17 ( & V_2 -> V_15 [ 1 ] ,
& V_17 ) ;
else if ( V_221 == 2 )
V_18 = V_2 -> F_17 ( & V_2 -> V_15 [ 2 ] ,
& V_17 ) ;
if ( V_18 >= 0 ) {
if ( V_220 == 1 )
* V_52 = V_50 [ 0 ] ;
else if ( V_220 == 4 )
* V_52 =
V_50 [ 0 ] | V_50 [ 1 ] << 8 | V_50 [ 2 ] << 16 | V_50 [ 3 ]
<< 24 ;
else if ( V_220 > 4 )
* V_52 = V_50 [ V_219 ] ;
}
return V_18 ;
}
int F_88 ( struct V_1 * V_2 , T_1 V_32 , T_4 V_219 ,
T_1 V_21 , T_5 V_52 , T_1 V_220 , int V_221 )
{
int V_18 = 0 ;
T_1 V_50 [ 4 ] = { 0 , 0 , 0 , 0 } ;
struct V_16 V_17 ;
V_50 [ 0 ] = ( T_1 ) V_52 ;
V_50 [ 1 ] = ( T_1 ) ( V_52 >> 8 ) ;
V_50 [ 2 ] = ( T_1 ) ( V_52 >> 16 ) ;
V_50 [ 3 ] = ( T_1 ) ( V_52 >> 24 ) ;
if ( V_21 == 0 )
V_219 = 0 ;
else if ( V_21 == 1 )
V_219 &= 0xff ;
V_17 . V_32 = V_32 >> 1 ;
V_17 . V_34 = 0 ;
V_17 . V_21 = V_21 ;
V_17 . V_39 = V_219 ;
V_17 . V_41 = V_220 ;
V_17 . V_44 = V_50 ;
if ( V_221 == 0 )
V_18 = V_2 -> F_17 ( & V_2 -> V_15 [ 0 ] ,
& V_17 ) ;
else if ( V_221 == 1 )
V_18 = V_2 -> F_17 ( & V_2 -> V_15 [ 1 ] ,
& V_17 ) ;
else if ( V_221 == 2 )
V_18 = V_2 -> F_17 ( & V_2 -> V_15 [ 2 ] ,
& V_17 ) ;
return V_18 ;
}
int F_89 ( struct V_1 * V_2 , T_1 V_32 , T_4 V_219 ,
T_1 V_21 , T_5 * V_52 , T_1 V_220 )
{
int V_18 = 0 ;
struct V_16 V_17 ;
T_1 V_50 [ 4 ] = { 0 , 0 , 0 , 0 } ;
if ( V_21 == 0 )
V_219 = 0 ;
else if ( V_21 == 1 )
V_219 &= 0xff ;
V_17 . V_32 = V_32 >> 1 ;
V_17 . V_34 = V_35 ;
V_17 . V_21 = V_21 ;
V_17 . V_39 = V_219 ;
V_17 . V_41 = V_220 ;
V_17 . V_44 = ( T_1 * ) V_50 ;
V_18 = V_2 -> F_17 ( & V_2 -> V_15 [ 0 ] , & V_17 ) ;
if ( V_18 >= 0 ) {
if ( V_220 == 1 )
* V_52 = V_50 [ 0 ] ;
else
* V_52 =
V_50 [ 0 ] | V_50 [ 1 ] << 8 | V_50 [ 2 ] << 16 | V_50 [ 3 ]
<< 24 ;
}
return V_18 ;
}
int F_90 ( struct V_1 * V_2 , T_1 V_32 , T_4 V_219 ,
T_1 V_21 , T_5 V_52 , T_1 V_220 )
{
int V_18 = 0 ;
T_1 V_50 [ 4 ] = { 0 , 0 , 0 , 0 } ;
struct V_16 V_17 ;
V_50 [ 0 ] = ( T_1 ) V_52 ;
V_50 [ 1 ] = ( T_1 ) ( V_52 >> 8 ) ;
V_50 [ 2 ] = ( T_1 ) ( V_52 >> 16 ) ;
V_50 [ 3 ] = ( T_1 ) ( V_52 >> 24 ) ;
if ( V_21 == 0 )
V_219 = 0 ;
else if ( V_21 == 1 )
V_219 &= 0xff ;
V_17 . V_32 = V_32 >> 1 ;
V_17 . V_34 = 0 ;
V_17 . V_21 = V_21 ;
V_17 . V_39 = V_219 ;
V_17 . V_41 = V_220 ;
V_17 . V_44 = V_50 ;
V_18 = V_2 -> F_17 ( & V_2 -> V_15 [ 0 ] , & V_17 ) ;
return V_18 ;
}
int F_91 ( struct V_1 * V_2 , T_1 V_32 , T_1 V_53 ,
T_4 V_222 , T_1 V_223 , T_1 V_224 ,
T_5 V_50 )
{
int V_18 = 0 ;
T_5 V_218 ;
T_5 V_225 = 0 ;
int V_56 ;
if ( V_223 > ( V_53 - 1 ) || V_224 > ( V_53 - 1 ) )
return - 1 ;
if ( V_53 == 8 ) {
V_18 =
F_89 ( V_2 , V_32 , V_222 , 2 ,
& V_218 , 1 ) ;
} else {
V_18 =
F_89 ( V_2 , V_32 , V_222 , 2 ,
& V_218 , 4 ) ;
}
if ( V_18 < 0 )
return V_18 ;
V_225 = 1 << V_224 ;
for ( V_56 = V_224 ; V_56 > V_223 && V_56 > 0 ; V_56 -- )
V_225 = V_225 + ( 1 << ( V_56 - 1 ) ) ;
V_50 <<= V_223 ;
if ( V_53 == 8 ) {
V_218 &= ~ V_225 ;
V_218 |= V_50 ;
V_218 &= 0xff ;
V_18 =
F_90 ( V_2 , V_32 , V_222 , 2 ,
V_218 , 1 ) ;
} else {
V_218 &= ~ V_225 ;
V_218 |= V_50 ;
V_18 =
F_90 ( V_2 , V_32 , V_222 , 2 ,
V_218 , 4 ) ;
}
return V_18 ;
}
int F_92 ( struct V_1 * V_2 , T_1 V_32 ,
T_4 V_219 , T_5 V_225 , T_5 V_50 )
{
T_5 V_226 ;
int V_18 = 0 ;
V_18 = F_89 ( V_2 , V_32 , V_219 , 2 , & V_226 , 4 ) ;
if ( V_18 < 0 )
return V_18 ;
V_226 &= ~ V_225 ;
V_226 |= V_50 ;
V_18 = F_90 ( V_2 , V_32 , V_219 , 2 , V_226 , 4 ) ;
return V_18 ;
}
T_5 F_93 ( T_5 V_227 , T_5 V_52 )
{
T_5 V_226 ;
for ( V_226 = V_227 ; ( V_226 & 1 ) == 0 ; V_226 >>= 1 )
V_52 <<= 1 ;
return V_52 ;
}
