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
V_19 = F_9 ( V_17 -> V_4 + 16 , V_20 , V_26 ) ;
if ( V_19 == NULL ) {
F_3 ( V_2 , L_8
L_9 , V_20 ) ;
F_8 ( V_17 ) ;
return - 1 ;
}
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
if ( V_2 -> V_34 == V_36 ) {
F_18 ( V_2 , 0x3c82 , 0x0000 ) ;
F_18 ( V_2 , 0x3c80 , 0x00df ) ;
}
return 0 ;
}
int F_19 ( struct V_1 * V_2 )
{
if ( F_6 ( V_2 ) < 0 )
return - 1 ;
return F_17 ( V_2 ) ;
}
static int F_20 ( struct V_37 * V_38 , const char * type ,
int V_13 )
{
struct V_1 * V_2 = F_21 ( V_38 ) ;
struct V_39 * V_10 = & V_2 -> V_10 ;
if ( F_22 ( V_10 , V_38 , type , V_13 , NULL ) )
return 0 ;
F_23 ( & V_38 -> V_24 ,
L_11 , type ) ;
return - 1 ;
}
int F_24 ( struct V_1 * V_2 )
{
int V_40 , V_28 ;
F_23 ( V_2 -> V_24 , L_12 , V_2 -> V_41 ) ;
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
F_20 ( & V_2 -> V_37 ,
V_2 -> V_31 -> V_45 [ V_40 ] . type ,
V_2 -> V_31 -> V_45 [ V_40 ] . V_13 ) ;
if ( V_2 -> V_34 == V_36 )
F_26 ( & V_2 -> V_37 ,
V_46 , & V_2 -> V_47 ) ;
}
if ( V_2 -> V_31 -> V_42 & V_48 ) {
V_2 -> V_49 = 1 ;
F_27 ( V_2 ) ;
}
return 0 ;
}
int F_28 ( struct V_1 * V_2 )
{
T_2 * V_50 ;
int V_20 , V_21 = 0 , V_40 ;
T_1 V_22 , V_23 ;
V_2 -> V_51 = 0 ;
if ( ! V_2 -> V_52 )
for ( V_40 = 0 ; V_40 < 4 ; ++ V_40 ) {
if ( V_2 -> V_53 [ V_40 ] . V_54 ) {
V_2 -> V_51 = 1 ;
continue;
}
V_2 -> V_53 [ V_40 ] . V_55 = 32767 ;
V_2 -> V_53 [ V_40 ] . V_56 = 32767 ;
V_2 -> V_53 [ V_40 ] . V_57 = 32767 ;
}
if ( F_29 ( V_2 , & V_50 , & V_20 ) < 0 )
return - 1 ;
if ( F_11 ( V_2 , V_50 , V_20 ) < 0 ||
F_1 ( V_2 , & V_22 , & V_23 ) < 0 ) {
F_3 ( & V_2 -> V_10 , L_10 ) ;
V_21 = - 1 ;
goto V_58;
}
V_2 -> V_59 = V_60 ;
V_2 -> V_61 = 0 ;
V_2 -> V_62 = 0 ;
if ( F_30 ( V_2 ) < 0 ) {
F_3 ( & V_2 -> V_10 , L_13 ) ;
V_21 = - 1 ;
goto V_58;
}
V_58:
F_12 ( V_50 ) ;
return V_21 ;
}
static inline void F_31 ( struct V_63 * V_64 , T_2 V_65 )
{
if ( V_64 != NULL && V_64 -> V_66 < V_67 ) {
unsigned int V_68 = V_64 -> V_69 >> V_70 ;
unsigned int V_71 = V_64 -> V_69 & ~ V_72 ;
* ( ( T_2 * ) F_32 ( V_64 -> V_73 [ V_68 ] ) + V_71 ) = V_65 ;
++ V_64 -> V_69 ;
++ V_64 -> V_66 ;
}
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_63 * V_64 ;
int V_40 ;
if ( V_2 -> V_74 ) {
if ( V_2 -> V_74 -> V_75 ) {
if ( V_2 -> V_74 -> V_66 + 216 < V_67 ) {
for ( V_40 = 0 ; V_40 < 216 ; ++ V_40 )
F_31 ( V_2 -> V_74 ,
V_2 -> V_76 [ V_40 ] ) ;
V_2 -> V_74 -> V_66 -= 216 ;
} else
V_2 -> V_74 -> V_75 = 0 ;
}
V_2 -> V_74 -> V_59 = V_77 ;
F_34 ( & V_2 -> V_78 ) ;
V_2 -> V_74 = NULL ;
}
F_35 (gobuf, &go->stream, stream)
if ( V_64 -> V_59 == V_79 ) {
V_64 -> V_80 = V_2 -> V_81 ;
F_36 ( & V_64 -> V_82 ) ;
V_2 -> V_74 = V_64 ;
break;
}
++ V_2 -> V_81 ;
}
static void F_37 ( struct V_1 * V_2 )
{
int V_83 , V_84 , V_40 , V_85 = ( ( V_2 -> V_86 >> 4 ) + 7 ) >> 3 ;
for ( V_40 = 0 ; V_40 < 16 ; ++ V_40 ) {
V_84 = ( ( ( V_2 -> V_61 - 1 ) << 3 ) + V_40 ) / ( V_2 -> V_86 >> 4 ) ;
V_83 = ( ( ( V_2 -> V_61 - 1 ) << 3 ) + V_40 ) % ( V_2 -> V_86 >> 4 ) ;
if ( V_85 * V_84 + ( V_83 >> 3 ) < sizeof( V_2 -> V_76 ) )
V_2 -> V_76 [ V_85 * V_84 + ( V_83 >> 3 ) ] |=
( V_2 -> V_87 & 1 ) << ( V_83 & 0x7 ) ;
V_2 -> V_87 >>= 1 ;
}
}
void F_38 ( struct V_1 * V_2 , T_2 * V_88 , int V_89 )
{
int V_40 , V_90 = - 1 , V_91 = - 1 ;
F_39 ( & V_2 -> V_92 ) ;
switch ( V_2 -> V_93 ) {
case V_94 :
V_90 = 0xB0 ;
V_91 = 0xB6 ;
break;
case V_95 :
case V_96 :
V_90 = 0xB3 ;
V_91 = 0x00 ;
break;
}
for ( V_40 = 0 ; V_40 < V_89 ; ++ V_40 ) {
if ( V_2 -> V_74 != NULL &&
V_2 -> V_74 -> V_66 >= V_67 - 3 ) {
F_40 ( & V_2 -> V_10 , L_14 ) ;
V_2 -> V_74 -> V_69 -= V_2 -> V_74 -> V_66 ;
V_2 -> V_74 -> V_66 = 0 ;
V_2 -> V_74 -> V_75 = 0 ;
V_2 -> V_74 = NULL ;
}
switch ( V_2 -> V_59 ) {
case V_60 :
switch ( V_88 [ V_40 ] ) {
case 0x00 :
V_2 -> V_59 = V_97 ;
break;
case 0xFF :
V_2 -> V_59 = V_98 ;
break;
default:
F_31 ( V_2 -> V_74 , V_88 [ V_40 ] ) ;
break;
}
break;
case V_97 :
switch ( V_88 [ V_40 ] ) {
case 0x00 :
V_2 -> V_59 = V_99 ;
break;
case 0xFF :
F_31 ( V_2 -> V_74 , 0x00 ) ;
V_2 -> V_59 = V_98 ;
break;
default:
F_31 ( V_2 -> V_74 , 0x00 ) ;
F_31 ( V_2 -> V_74 , V_88 [ V_40 ] ) ;
V_2 -> V_59 = V_60 ;
break;
}
break;
case V_99 :
switch ( V_88 [ V_40 ] ) {
case 0x00 :
F_31 ( V_2 -> V_74 , 0x00 ) ;
break;
case 0x01 :
V_2 -> V_59 = V_100 ;
break;
case 0xFF :
F_31 ( V_2 -> V_74 , 0x00 ) ;
F_31 ( V_2 -> V_74 , 0x00 ) ;
V_2 -> V_59 = V_98 ;
break;
default:
F_31 ( V_2 -> V_74 , 0x00 ) ;
F_31 ( V_2 -> V_74 , 0x00 ) ;
F_31 ( V_2 -> V_74 , V_88 [ V_40 ] ) ;
V_2 -> V_59 = V_60 ;
break;
}
break;
case V_100 :
if ( V_88 [ V_40 ] == 0xF8 && V_2 -> V_51 == 0 ) {
F_31 ( V_2 -> V_74 , 0x00 ) ;
F_31 ( V_2 -> V_74 , 0x00 ) ;
F_31 ( V_2 -> V_74 , 0x01 ) ;
F_31 ( V_2 -> V_74 , 0xF8 ) ;
V_2 -> V_59 = V_60 ;
break;
}
if ( ( V_2 -> V_93 == V_95 ||
V_2 -> V_93 == V_96 ||
V_2 -> V_93 == V_94 ) &&
( V_88 [ V_40 ] == V_90 ||
V_88 [ V_40 ] == 0xB8 ||
V_88 [ V_40 ] == V_91 ) ) {
if ( V_2 -> V_74 == NULL || V_2 -> V_62 )
F_33 ( V_2 ) ;
if ( V_88 [ V_40 ] == V_91 ) {
if ( V_2 -> V_74 != NULL )
V_2 -> V_74 -> V_101 =
V_2 -> V_74 -> V_69 ;
V_2 -> V_62 = 1 ;
} else {
V_2 -> V_62 = 0 ;
}
}
switch ( V_88 [ V_40 ] ) {
case 0xF5 :
V_2 -> V_61 = 12 ;
V_2 -> V_59 = V_102 ;
break;
case 0xF6 :
V_2 -> V_59 = V_103 ;
break;
case 0xF8 :
V_2 -> V_61 = 0 ;
memset ( V_2 -> V_76 , 0 ,
sizeof( V_2 -> V_76 ) ) ;
V_2 -> V_59 = V_104 ;
break;
case 0xFF :
F_31 ( V_2 -> V_74 , 0x00 ) ;
F_31 ( V_2 -> V_74 , 0x00 ) ;
F_31 ( V_2 -> V_74 , 0x01 ) ;
V_2 -> V_59 = V_98 ;
break;
default:
F_31 ( V_2 -> V_74 , 0x00 ) ;
F_31 ( V_2 -> V_74 , 0x00 ) ;
F_31 ( V_2 -> V_74 , 0x01 ) ;
F_31 ( V_2 -> V_74 , V_88 [ V_40 ] ) ;
V_2 -> V_59 = V_60 ;
break;
}
break;
case V_98 :
switch ( V_88 [ V_40 ] ) {
case 0x00 :
F_31 ( V_2 -> V_74 , 0xFF ) ;
V_2 -> V_59 = V_97 ;
break;
case 0xFF :
F_31 ( V_2 -> V_74 , 0xFF ) ;
break;
case 0xD8 :
if ( V_2 -> V_93 == V_105 )
F_33 ( V_2 ) ;
default:
F_31 ( V_2 -> V_74 , 0xFF ) ;
F_31 ( V_2 -> V_74 , V_88 [ V_40 ] ) ;
V_2 -> V_59 = V_60 ;
break;
}
break;
case V_103 :
V_2 -> V_61 = V_88 [ V_40 ] << 8 ;
V_2 -> V_59 = V_106 ;
break;
case V_106 :
V_2 -> V_61 |= V_88 [ V_40 ] ;
if ( V_2 -> V_61 > 0 )
V_2 -> V_59 = V_102 ;
else
V_2 -> V_59 = V_60 ;
break;
case V_104 :
if ( V_2 -> V_61 < 204 ) {
if ( V_2 -> V_61 & 1 ) {
V_2 -> V_87 |= V_88 [ V_40 ] ;
F_37 ( V_2 ) ;
} else
V_2 -> V_87 = V_88 [ V_40 ] << 8 ;
} else if ( V_2 -> V_61 == 207 && V_2 -> V_74 ) {
V_2 -> V_74 -> V_75 = V_88 [ V_40 ] ;
}
if ( ++ V_2 -> V_61 == 208 )
V_2 -> V_59 = V_60 ;
break;
case V_102 :
if ( -- V_2 -> V_61 == 0 )
V_2 -> V_59 = V_60 ;
break;
}
}
F_41 ( & V_2 -> V_92 ) ;
}
struct V_1 * F_42 ( struct V_107 * V_108 , struct V_109 * V_24 )
{
struct V_1 * V_2 ;
int V_40 ;
V_2 = F_43 ( sizeof( struct V_1 ) , V_26 ) ;
if ( V_2 == NULL )
return NULL ;
V_2 -> V_24 = V_24 ;
V_2 -> V_31 = V_108 ;
V_2 -> V_34 = 0 ;
V_2 -> V_110 = - 1 ;
V_2 -> V_47 = 0 ;
V_2 -> V_41 [ 0 ] = 0 ;
F_44 ( & V_2 -> V_29 ) ;
F_45 ( & V_2 -> V_78 ) ;
F_46 ( & V_2 -> V_92 ) ;
V_2 -> V_111 = NULL ;
V_2 -> V_112 = 0 ;
V_2 -> V_113 = V_114 ;
memset ( & V_2 -> V_37 , 0 , sizeof( V_2 -> V_37 ) ) ;
V_2 -> V_30 = 0 ;
V_2 -> V_5 = 0 ;
F_45 ( & V_2 -> V_8 ) ;
V_2 -> V_115 = 0 ;
V_2 -> V_116 = 0 ;
if ( V_108 -> V_117 & V_118 ) {
V_2 -> V_119 = V_120 ;
V_2 -> V_86 = 720 ;
V_2 -> V_121 = 480 ;
V_2 -> V_122 = 30000 ;
} else {
V_2 -> V_119 = V_123 ;
V_2 -> V_86 = V_108 -> V_124 ;
V_2 -> V_121 = V_108 -> V_125 ;
V_2 -> V_122 = V_108 -> V_122 ;
}
V_2 -> V_126 = V_108 -> V_127 ;
V_2 -> V_128 = V_108 -> V_129 ;
V_2 -> V_130 = 0 ;
V_2 -> V_131 = 0 ;
V_2 -> V_132 = 0 ;
V_2 -> V_133 = 0 ;
V_2 -> V_93 = V_105 ;
V_2 -> V_134 = 1500000 ;
V_2 -> V_135 = 1 ;
V_2 -> V_136 = 0 ;
V_2 -> V_137 = V_138 ;
V_2 -> V_139 = 0 ;
V_2 -> V_140 = 0 ;
V_2 -> V_141 = 0 ;
V_2 -> V_142 = 0 ;
V_2 -> V_143 = 0 ;
V_2 -> V_144 = 0 ;
V_2 -> V_52 = 0 ;
V_2 -> V_145 = 0 ;
for ( V_40 = 0 ; V_40 < 4 ; ++ V_40 )
V_2 -> V_53 [ V_40 ] . V_54 = 0 ;
for ( V_40 = 0 ; V_40 < 1624 ; ++ V_40 )
V_2 -> V_146 [ V_40 ] = 0 ;
V_2 -> V_147 = NULL ;
V_2 -> V_49 = 0 ;
F_47 ( & V_2 -> V_148 ) ;
return V_2 ;
}
void F_48 ( struct V_1 * V_2 )
{
if ( V_2 -> V_30 ) {
if ( F_49 ( & V_2 -> V_37 ) == 0 )
V_2 -> V_30 = 0 ;
else
F_3 ( & V_2 -> V_10 ,
L_15 ) ;
}
if ( V_2 -> V_49 )
F_50 ( V_2 ) ;
F_51 ( V_2 ) ;
}
