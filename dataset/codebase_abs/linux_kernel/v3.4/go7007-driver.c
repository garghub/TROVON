int F_1 ( struct V_1 * V_2 , T_1 * V_3 , T_1 * V_4 )
{
V_2 -> V_5 = 0 ;
V_2 -> V_6 -> V_7 ( V_2 ) ;
if ( F_2 ( V_2 -> V_8 ,
V_2 -> V_5 , 5 * V_9 ) < 0 ) {
F_3 ( & V_2 -> V_10 , L_1 ) ;
return - 1 ;
}
if ( ! V_2 -> V_5 )
return - 1 ;
V_2 -> V_5 = 0 ;
* V_3 = V_2 -> V_11 & 0xfffe ;
* V_4 = V_2 -> V_12 ;
return 0 ;
}
int F_4 ( struct V_1 * V_2 , T_1 V_13 , T_1 * V_4 )
{
int V_14 = 100 ;
T_1 V_3 ;
if ( F_5 ( V_2 , 0x0010 , V_13 ) < 0 )
return - V_15 ;
while ( V_14 -- > 0 ) {
if ( F_1 ( V_2 , & V_3 , V_4 ) == 0 &&
V_3 == 0xa000 )
return 0 ;
}
return - V_15 ;
}
static int F_6 ( struct V_1 * V_2 )
{
const struct V_16 * V_17 ;
char V_18 [] = L_2 ;
void * V_19 ;
int V_20 , V_21 = 0 ;
T_1 V_22 , V_23 ;
if ( F_7 ( & V_17 , V_18 , V_2 -> V_24 ) ) {
F_3 ( V_2 , L_3
L_4 , V_18 ) ;
return - 1 ;
}
if ( V_17 -> V_25 < 16 || memcmp ( V_17 -> V_4 , L_5 , 11 ) ) {
F_3 ( V_2 , L_6
L_7 , V_18 ) ;
F_8 ( V_17 ) ;
return - 1 ;
}
V_20 = V_17 -> V_25 - 16 ;
V_19 = F_9 ( V_20 , V_26 ) ;
if ( V_19 == NULL ) {
F_3 ( V_2 , L_8
L_9 , V_20 ) ;
F_8 ( V_17 ) ;
return - 1 ;
}
memcpy ( V_19 , V_17 -> V_4 + 16 , V_20 ) ;
F_8 ( V_17 ) ;
if ( F_10 ( V_2 ) < 0 ||
F_11 ( V_2 , V_19 , V_20 ) < 0 ||
F_1 ( V_2 , & V_22 , & V_23 ) < 0 ||
( V_22 & ~ 0x1 ) != 0x5a5a ) {
F_3 ( V_2 , L_10 ) ;
V_21 = - 1 ;
}
F_12 ( V_19 ) ;
return V_21 ;
}
int F_13 ( struct V_1 * V_2 , int V_27 )
{
int V_28 ;
F_14 ( & V_2 -> V_29 ) ;
V_28 = F_6 ( V_2 ) ;
F_15 ( & V_2 -> V_29 ) ;
if ( V_28 < 0 )
return - 1 ;
if ( ! V_27 )
return 0 ;
if ( F_16 ( V_2 ) < 0 )
return - 1 ;
V_2 -> V_30 = 1 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
if ( V_2 -> V_31 -> V_32 & V_33 ) {
F_18 ( V_2 , 0x1000 , 0x0811 ) ;
F_18 ( V_2 , 0x1000 , 0x0c11 ) ;
}
if ( V_2 -> V_34 == V_35 ) {
F_18 ( V_2 , 0x3c82 , 0x0001 ) ;
F_18 ( V_2 , 0x3c80 , 0x00fe ) ;
}
return 0 ;
}
int F_19 ( struct V_1 * V_2 )
{
if ( F_6 ( V_2 ) < 0 )
return - 1 ;
return F_17 ( V_2 ) ;
}
static int F_20 ( struct V_36 * V_37 , const char * type ,
int V_13 )
{
struct V_1 * V_2 = F_21 ( V_37 ) ;
struct V_38 * V_10 = & V_2 -> V_10 ;
if ( F_22 ( V_10 , V_37 , type , V_13 , NULL ) )
return 0 ;
F_23 ( V_39 L_11 , type ) ;
return - 1 ;
}
int F_24 ( struct V_1 * V_2 )
{
int V_40 , V_28 ;
F_23 ( V_39 L_12 , V_2 -> V_41 ) ;
F_14 ( & V_2 -> V_29 ) ;
V_28 = F_17 ( V_2 ) ;
F_15 ( & V_2 -> V_29 ) ;
if ( V_28 < 0 )
return - 1 ;
V_28 = F_25 ( V_2 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( ! V_2 -> V_30 &&
V_2 -> V_31 -> V_42 & V_43 ) {
if ( F_16 ( V_2 ) < 0 )
return - 1 ;
V_2 -> V_30 = 1 ;
}
if ( V_2 -> V_30 ) {
for ( V_40 = 0 ; V_40 < V_2 -> V_31 -> V_44 ; ++ V_40 )
F_20 ( & V_2 -> V_36 ,
V_2 -> V_31 -> V_45 [ V_40 ] . type ,
V_2 -> V_31 -> V_45 [ V_40 ] . V_13 ) ;
if ( V_2 -> V_34 == V_46 )
F_26 ( & V_2 -> V_36 ,
V_47 , & V_2 -> V_48 ) ;
}
if ( V_2 -> V_31 -> V_42 & V_49 ) {
V_2 -> V_50 = 1 ;
F_27 ( V_2 ) ;
}
return 0 ;
}
int F_28 ( struct V_1 * V_2 )
{
T_2 * V_51 ;
int V_20 , V_21 = 0 , V_40 ;
T_1 V_22 , V_23 ;
V_2 -> V_52 = 0 ;
if ( ! V_2 -> V_53 )
for ( V_40 = 0 ; V_40 < 4 ; ++ V_40 ) {
if ( V_2 -> V_54 [ V_40 ] . V_55 ) {
V_2 -> V_52 = 1 ;
continue;
}
V_2 -> V_54 [ V_40 ] . V_56 = 32767 ;
V_2 -> V_54 [ V_40 ] . V_57 = 32767 ;
V_2 -> V_54 [ V_40 ] . V_58 = 32767 ;
}
if ( F_29 ( V_2 , & V_51 , & V_20 ) < 0 )
return - 1 ;
if ( F_11 ( V_2 , V_51 , V_20 ) < 0 ||
F_1 ( V_2 , & V_22 , & V_23 ) < 0 ) {
F_3 ( & V_2 -> V_10 , L_10 ) ;
V_21 = - 1 ;
goto V_59;
}
V_2 -> V_60 = V_61 ;
V_2 -> V_62 = 0 ;
V_2 -> V_63 = 0 ;
if ( F_30 ( V_2 ) < 0 ) {
F_3 ( & V_2 -> V_10 , L_13 ) ;
V_21 = - 1 ;
goto V_59;
}
V_59:
F_12 ( V_51 ) ;
return V_21 ;
}
static inline void F_31 ( struct V_64 * V_65 , T_2 V_66 )
{
if ( V_65 != NULL && V_65 -> V_67 < V_68 ) {
unsigned int V_69 = V_65 -> V_70 >> V_71 ;
unsigned int V_72 = V_65 -> V_70 & ~ V_73 ;
* ( ( T_2 * ) F_32 ( V_65 -> V_74 [ V_69 ] ) + V_72 ) = V_66 ;
++ V_65 -> V_70 ;
++ V_65 -> V_67 ;
}
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_64 * V_65 ;
int V_40 ;
if ( V_2 -> V_75 ) {
if ( V_2 -> V_75 -> V_76 ) {
if ( V_2 -> V_75 -> V_67 + 216 < V_68 ) {
for ( V_40 = 0 ; V_40 < 216 ; ++ V_40 )
F_31 ( V_2 -> V_75 ,
V_2 -> V_77 [ V_40 ] ) ;
V_2 -> V_75 -> V_67 -= 216 ;
} else
V_2 -> V_75 -> V_76 = 0 ;
}
V_2 -> V_75 -> V_60 = V_78 ;
F_34 ( & V_2 -> V_79 ) ;
V_2 -> V_75 = NULL ;
}
F_35 (gobuf, &go->stream, stream)
if ( V_65 -> V_60 == V_80 ) {
V_65 -> V_81 = V_2 -> V_82 ;
F_36 ( & V_65 -> V_83 ) ;
V_2 -> V_75 = V_65 ;
break;
}
++ V_2 -> V_82 ;
}
static void F_37 ( struct V_1 * V_2 )
{
int V_84 , V_85 , V_40 , V_86 = ( ( V_2 -> V_87 >> 4 ) + 7 ) >> 3 ;
for ( V_40 = 0 ; V_40 < 16 ; ++ V_40 ) {
V_85 = ( ( ( V_2 -> V_62 - 1 ) << 3 ) + V_40 ) / ( V_2 -> V_87 >> 4 ) ;
V_84 = ( ( ( V_2 -> V_62 - 1 ) << 3 ) + V_40 ) % ( V_2 -> V_87 >> 4 ) ;
if ( V_86 * V_85 + ( V_84 >> 3 ) < sizeof( V_2 -> V_77 ) )
V_2 -> V_77 [ V_86 * V_85 + ( V_84 >> 3 ) ] |=
( V_2 -> V_88 & 1 ) << ( V_84 & 0x7 ) ;
V_2 -> V_88 >>= 1 ;
}
}
void F_38 ( struct V_1 * V_2 , T_2 * V_89 , int V_90 )
{
int V_40 , V_91 = - 1 , V_92 = - 1 ;
F_39 ( & V_2 -> V_93 ) ;
switch ( V_2 -> V_94 ) {
case V_95 :
V_91 = 0xB0 ;
V_92 = 0xB6 ;
break;
case V_96 :
case V_97 :
V_91 = 0xB3 ;
V_92 = 0x00 ;
break;
}
for ( V_40 = 0 ; V_40 < V_90 ; ++ V_40 ) {
if ( V_2 -> V_75 != NULL &&
V_2 -> V_75 -> V_67 >= V_68 - 3 ) {
F_40 ( & V_2 -> V_10 , L_14 ) ;
V_2 -> V_75 -> V_70 -= V_2 -> V_75 -> V_67 ;
V_2 -> V_75 -> V_67 = 0 ;
V_2 -> V_75 -> V_76 = 0 ;
V_2 -> V_75 = NULL ;
}
switch ( V_2 -> V_60 ) {
case V_61 :
switch ( V_89 [ V_40 ] ) {
case 0x00 :
V_2 -> V_60 = V_98 ;
break;
case 0xFF :
V_2 -> V_60 = V_99 ;
break;
default:
F_31 ( V_2 -> V_75 , V_89 [ V_40 ] ) ;
break;
}
break;
case V_98 :
switch ( V_89 [ V_40 ] ) {
case 0x00 :
V_2 -> V_60 = V_100 ;
break;
case 0xFF :
F_31 ( V_2 -> V_75 , 0x00 ) ;
V_2 -> V_60 = V_99 ;
break;
default:
F_31 ( V_2 -> V_75 , 0x00 ) ;
F_31 ( V_2 -> V_75 , V_89 [ V_40 ] ) ;
V_2 -> V_60 = V_61 ;
break;
}
break;
case V_100 :
switch ( V_89 [ V_40 ] ) {
case 0x00 :
F_31 ( V_2 -> V_75 , 0x00 ) ;
break;
case 0x01 :
V_2 -> V_60 = V_101 ;
break;
case 0xFF :
F_31 ( V_2 -> V_75 , 0x00 ) ;
F_31 ( V_2 -> V_75 , 0x00 ) ;
V_2 -> V_60 = V_99 ;
break;
default:
F_31 ( V_2 -> V_75 , 0x00 ) ;
F_31 ( V_2 -> V_75 , 0x00 ) ;
F_31 ( V_2 -> V_75 , V_89 [ V_40 ] ) ;
V_2 -> V_60 = V_61 ;
break;
}
break;
case V_101 :
if ( V_89 [ V_40 ] == 0xF8 && V_2 -> V_52 == 0 ) {
F_31 ( V_2 -> V_75 , 0x00 ) ;
F_31 ( V_2 -> V_75 , 0x00 ) ;
F_31 ( V_2 -> V_75 , 0x01 ) ;
F_31 ( V_2 -> V_75 , 0xF8 ) ;
V_2 -> V_60 = V_61 ;
break;
}
if ( ( V_2 -> V_94 == V_96 ||
V_2 -> V_94 == V_97 ||
V_2 -> V_94 == V_95 ) &&
( V_89 [ V_40 ] == V_91 ||
V_89 [ V_40 ] == 0xB8 ||
V_89 [ V_40 ] == V_92 ) ) {
if ( V_2 -> V_75 == NULL || V_2 -> V_63 )
F_33 ( V_2 ) ;
if ( V_89 [ V_40 ] == V_92 ) {
if ( V_2 -> V_75 != NULL )
V_2 -> V_75 -> V_102 =
V_2 -> V_75 -> V_70 ;
V_2 -> V_63 = 1 ;
} else {
V_2 -> V_63 = 0 ;
}
}
switch ( V_89 [ V_40 ] ) {
case 0xF5 :
V_2 -> V_62 = 12 ;
V_2 -> V_60 = V_103 ;
break;
case 0xF6 :
V_2 -> V_60 = V_104 ;
break;
case 0xF8 :
V_2 -> V_62 = 0 ;
memset ( V_2 -> V_77 , 0 ,
sizeof( V_2 -> V_77 ) ) ;
V_2 -> V_60 = V_105 ;
break;
case 0xFF :
F_31 ( V_2 -> V_75 , 0x00 ) ;
F_31 ( V_2 -> V_75 , 0x00 ) ;
F_31 ( V_2 -> V_75 , 0x01 ) ;
V_2 -> V_60 = V_99 ;
break;
default:
F_31 ( V_2 -> V_75 , 0x00 ) ;
F_31 ( V_2 -> V_75 , 0x00 ) ;
F_31 ( V_2 -> V_75 , 0x01 ) ;
F_31 ( V_2 -> V_75 , V_89 [ V_40 ] ) ;
V_2 -> V_60 = V_61 ;
break;
}
break;
case V_99 :
switch ( V_89 [ V_40 ] ) {
case 0x00 :
F_31 ( V_2 -> V_75 , 0xFF ) ;
V_2 -> V_60 = V_98 ;
break;
case 0xFF :
F_31 ( V_2 -> V_75 , 0xFF ) ;
break;
case 0xD8 :
if ( V_2 -> V_94 == V_106 )
F_33 ( V_2 ) ;
default:
F_31 ( V_2 -> V_75 , 0xFF ) ;
F_31 ( V_2 -> V_75 , V_89 [ V_40 ] ) ;
V_2 -> V_60 = V_61 ;
break;
}
break;
case V_104 :
V_2 -> V_62 = V_89 [ V_40 ] << 8 ;
V_2 -> V_60 = V_107 ;
break;
case V_107 :
V_2 -> V_62 |= V_89 [ V_40 ] ;
if ( V_2 -> V_62 > 0 )
V_2 -> V_60 = V_103 ;
else
V_2 -> V_60 = V_61 ;
break;
case V_105 :
if ( V_2 -> V_62 < 204 ) {
if ( V_2 -> V_62 & 1 ) {
V_2 -> V_88 |= V_89 [ V_40 ] ;
F_37 ( V_2 ) ;
} else
V_2 -> V_88 = V_89 [ V_40 ] << 8 ;
} else if ( V_2 -> V_62 == 207 && V_2 -> V_75 ) {
V_2 -> V_75 -> V_76 = V_89 [ V_40 ] ;
}
if ( ++ V_2 -> V_62 == 208 )
V_2 -> V_60 = V_61 ;
break;
case V_103 :
if ( -- V_2 -> V_62 == 0 )
V_2 -> V_60 = V_61 ;
break;
}
}
F_41 ( & V_2 -> V_93 ) ;
}
struct V_1 * F_42 ( struct V_108 * V_109 , struct V_110 * V_24 )
{
struct V_1 * V_2 ;
int V_40 ;
V_2 = F_9 ( sizeof( struct V_1 ) , V_26 ) ;
if ( V_2 == NULL )
return NULL ;
V_2 -> V_24 = V_24 ;
V_2 -> V_31 = V_109 ;
V_2 -> V_34 = 0 ;
V_2 -> V_111 = - 1 ;
V_2 -> V_48 = 0 ;
V_2 -> V_41 [ 0 ] = 0 ;
F_43 ( & V_2 -> V_29 ) ;
F_44 ( & V_2 -> V_79 ) ;
F_45 ( & V_2 -> V_93 ) ;
V_2 -> V_112 = NULL ;
V_2 -> V_113 = 0 ;
V_2 -> V_114 = V_115 ;
memset ( & V_2 -> V_36 , 0 , sizeof( V_2 -> V_36 ) ) ;
V_2 -> V_30 = 0 ;
V_2 -> V_5 = 0 ;
F_44 ( & V_2 -> V_8 ) ;
V_2 -> V_116 = 0 ;
V_2 -> V_117 = 0 ;
if ( V_109 -> V_118 & V_119 ) {
V_2 -> V_120 = V_121 ;
V_2 -> V_87 = 720 ;
V_2 -> V_122 = 480 ;
V_2 -> V_123 = 30000 ;
} else {
V_2 -> V_120 = V_124 ;
V_2 -> V_87 = V_109 -> V_125 ;
V_2 -> V_122 = V_109 -> V_126 ;
V_2 -> V_123 = V_109 -> V_123 ;
}
V_2 -> V_127 = V_109 -> V_128 ;
V_2 -> V_129 = V_109 -> V_130 ;
V_2 -> V_131 = 0 ;
V_2 -> V_132 = 0 ;
V_2 -> V_133 = 0 ;
V_2 -> V_134 = 0 ;
V_2 -> V_94 = V_106 ;
V_2 -> V_135 = 1500000 ;
V_2 -> V_136 = 1 ;
V_2 -> V_137 = 0 ;
V_2 -> V_138 = V_139 ;
V_2 -> V_140 = 0 ;
V_2 -> V_141 = 0 ;
V_2 -> V_142 = 0 ;
V_2 -> V_143 = 0 ;
V_2 -> V_144 = 0 ;
V_2 -> V_145 = 0 ;
V_2 -> V_53 = 0 ;
V_2 -> V_146 = 0 ;
for ( V_40 = 0 ; V_40 < 4 ; ++ V_40 )
V_2 -> V_54 [ V_40 ] . V_55 = 0 ;
for ( V_40 = 0 ; V_40 < 1624 ; ++ V_40 )
V_2 -> V_147 [ V_40 ] = 0 ;
V_2 -> V_148 = NULL ;
V_2 -> V_50 = 0 ;
F_46 ( & V_2 -> V_149 ) ;
return V_2 ;
}
void F_47 ( struct V_1 * V_2 )
{
if ( V_2 -> V_30 ) {
if ( F_48 ( & V_2 -> V_36 ) == 0 )
V_2 -> V_30 = 0 ;
else
F_3 ( & V_2 -> V_10 ,
L_15 ) ;
}
if ( V_2 -> V_50 )
F_49 ( V_2 ) ;
F_50 ( V_2 ) ;
}
