void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = V_2 -> V_3 ;
V_3 -> V_4 = 1 ;
V_3 -> V_5 = 1 ;
V_3 -> V_6 = 1 ;
if( V_3 -> V_6 )
V_3 -> V_7 = 1 ;
else
V_3 -> V_7 = true ;
V_3 -> V_8 = 7935UL ;
V_3 -> V_9 = 0 ;
V_3 -> V_10 = 1 ;
V_3 -> V_11 = 2 ;
V_3 -> V_12 = 0 ;
V_3 -> V_13 = 3 ;
if( V_3 -> V_13 == 2 )
V_3 -> V_13 = 3 ;
V_2 -> V_14 = 0 ;
V_2 -> V_15 = 0 ;
#ifdef F_2
V_16 -> V_17 = ( BOOLEAN ) V_18 -> V_19 ;
#endif
V_3 -> V_20 = 1 ;
V_3 -> V_21 = 1 ;
V_3 -> V_22 = 64 ;
V_3 -> V_23 = 30 ;
#ifdef F_3
V_3 -> V_24 = 4 ;
#endif
#ifdef F_4
V_3 -> V_25 = 1 ;
V_3 -> V_26 = 24 ;
V_3 -> V_27 = 8 ;
V_3 -> V_28 = 16 ;
#endif
}
void F_5 ( T_2 * V_29 , T_2 * V_30 )
{
static T_2 V_31 [] = { 0x00 , 0x90 , 0x4c , 0x33 } ;
T_3 V_32 ;
if( ! memcmp ( V_29 , V_31 , sizeof( V_31 ) ) )
{
F_6 ( V_33 , L_1 , V_34 ) ;
V_32 = ( T_3 ) ( & V_29 [ 4 ] ) ;
} else
V_32 = ( T_3 ) ( & V_29 [ 0 ] ) ;
F_6 ( V_33 , L_2 , V_30 ) ;
F_6 ( V_33 , L_3 , ( V_32 -> V_35 ) ? L_4 : L_5 ) ;
F_6 ( V_33 , L_6 , ( V_32 -> V_36 ) ? L_7 : L_8 ) ;
F_6 ( V_33 , L_9 , ( V_32 -> V_37 ) ? L_7 : L_8 ) ;
F_6 ( V_33 , L_10 , ( V_32 -> V_38 ) ? L_7 : L_8 ) ;
F_6 ( V_33 , L_11 , ( V_32 -> V_39 ) ? L_12 : L_13 ) ;
F_6 ( V_33 , L_14 , ( V_32 -> V_40 ) ? L_7 : L_8 ) ;
F_6 ( V_33 , L_15 , V_32 -> V_41 ) ;
F_6 ( V_33 , L_16 , V_32 -> V_42 ) ;
F_6 ( V_33 , L_17 , V_32 -> V_43 [ 0 ] ,\
V_32 -> V_43 [ 1 ] , V_32 -> V_43 [ 2 ] , V_32 -> V_43 [ 3 ] , V_32 -> V_43 [ 4 ] ) ;
}
void F_7 ( T_2 * V_44 , T_2 * V_30 )
{
static T_2 V_45 [] = { 0x00 , 0x90 , 0x4c , 0x34 } ;
T_4 V_46 ;
if( ! memcmp ( V_44 , V_45 , sizeof( V_45 ) ) )
{
F_6 ( V_33 , L_1 , V_34 ) ;
V_46 = ( T_4 ) ( & V_44 [ 4 ] ) ;
} else
V_46 = ( T_4 ) ( & V_44 [ 0 ] ) ;
F_6 ( V_33 , L_18 , V_30 ) ;
F_6 ( V_33 , L_19 , V_46 -> V_47 ) ;
F_6 ( V_33 , L_20 ) ;
switch( V_46 -> V_48 )
{
case 0 :
F_6 ( V_33 , L_21 ) ;
break;
case 1 :
F_6 ( V_33 , L_22 ) ;
break;
case 2 :
F_6 ( V_33 , L_23 ) ;
break;
case 3 :
F_6 ( V_33 , L_24 ) ;
break;
}
F_6 ( V_33 , L_25 , ( V_46 -> V_49 ) ? L_26 : L_27 ) ;
F_6 ( V_33 , L_28 ) ;
switch( V_46 -> V_50 )
{
case 0 :
F_6 ( V_33 , L_29 ) ;
break;
case 1 :
F_6 ( V_33 , L_30 ) ;
break;
case 2 :
F_6 ( V_33 , L_31 ) ;
break;
case 3 :
F_6 ( V_33 , L_32 ) ;
break;
}
F_6 ( V_33 , L_33 , V_46 -> V_51 [ 0 ] ,\
V_46 -> V_51 [ 1 ] , V_46 -> V_51 [ 2 ] , V_46 -> V_51 [ 3 ] , V_46 -> V_51 [ 4 ] ) ;
}
bool F_8 ( struct V_1 * V_2 )
{
bool V_52 = false ;
T_1 V_3 = V_2 -> V_3 ;
if( V_3 -> V_53 == false )
V_52 = false ;
else if( V_3 -> V_6 == false )
V_52 = false ;
else if ( ! V_2 -> V_54 ( V_2 ) )
V_52 = false ;
else if( ( ( T_3 ) ( V_3 -> V_55 ) ) -> V_35 )
V_52 = true ;
else
V_52 = false ;
return V_52 ;
}
bool F_9 ( struct V_1 * V_2 , bool V_56 )
{
bool V_52 = false ;
T_1 V_3 = V_2 -> V_3 ;
if( V_3 -> V_53 == false )
V_52 = false ;
else if ( ! V_2 -> V_54 ( V_2 ) )
V_52 = false ;
else if( V_56 )
{
if( ( ( T_3 ) ( V_3 -> V_55 ) ) -> V_37 )
V_52 = true ;
else
V_52 = false ;
}
else
{
if( ( ( T_3 ) ( V_3 -> V_55 ) ) -> V_36 )
V_52 = true ;
else
V_52 = false ;
}
return V_52 ;
}
T_5 F_10 ( struct V_1 * V_2 , T_2 V_57 )
{
T_2 V_56 ;
T_2 V_58 ;
V_56 = ( F_8 ( V_2 ) ) ? 1 : 0 ;
V_58 = ( F_9 ( V_2 , V_56 ) ) ? 1 : 0 ;
return V_59 [ V_56 ] [ V_58 ] [ ( V_57 & 0x7f ) ] ;
}
T_5 F_11 ( struct V_1 * V_2 , T_2 V_57 )
{
T_1 V_3 = V_2 -> V_3 ;
T_2 V_56 = ( V_3 -> V_60 ) ? 1 : 0 ;
T_2 V_58 = ( V_3 -> V_60 ) ?
( ( V_3 -> V_61 ) ? 1 : 0 ) :
( ( V_3 -> V_62 ) ? 1 : 0 ) ;
return V_59 [ V_56 ] [ V_58 ] [ ( V_57 & 0x7f ) ] ;
}
T_5 F_12 ( struct V_1 * V_2 , T_2 V_63 )
{
T_5 V_64 [ 12 ] = { 0x02 , 0x04 , 0x0b , 0x16 , 0x0c , 0x12 , 0x18 , 0x24 , 0x30 , 0x48 , 0x60 , 0x6c } ;
T_2 V_56 = 0 ;
T_2 V_58 = 0 ;
if( V_63 < 12 )
{
return V_64 [ V_63 ] ;
}
else
{
if ( V_63 >= 0x10 && V_63 <= 0x1f )
{
V_56 = 0 ;
V_58 = 0 ;
}
else if( V_63 >= 0x20 && V_63 <= 0x2f )
{
V_56 = 1 ;
V_58 = 0 ;
}
else if( V_63 >= 0x30 && V_63 <= 0x3f )
{
V_56 = 0 ;
V_58 = 1 ;
}
else if( V_63 >= 0x40 && V_63 <= 0x4f )
{
V_56 = 1 ;
V_58 = 1 ;
}
return V_59 [ V_56 ] [ V_58 ] [ V_63 & 0xf ] ;
}
}
bool F_13 ( struct V_1 * V_2 )
{
bool V_52 = false ;
struct V_65 * V_66 = & V_2 -> V_67 ;
#if 0
if(ieee->bHalfNMode == false)
retValue = false;
else
#endif
if( ( memcmp ( V_66 -> V_68 , V_69 , 3 ) == 0 ) ||
( memcmp ( V_66 -> V_68 , V_70 , 3 ) == 0 ) ||
( memcmp ( V_66 -> V_68 , V_71 , 3 ) == 0 ) ||
( memcmp ( V_66 -> V_68 , V_72 , 3 ) == 0 ) ||
( memcmp ( V_66 -> V_68 , V_73 , 3 ) == 0 ) ||
( V_66 -> V_74 ) )
V_52 = true ;
else if( ( memcmp ( V_66 -> V_68 , V_75 , 3 ) == 0 ) ||
( memcmp ( V_66 -> V_68 , V_76 , 3 ) == 0 ) ||
( memcmp ( V_66 -> V_68 , V_77 , 3 ) == 0 ) ||
( V_66 -> V_78 ) )
V_52 = true ;
else if( V_66 -> V_79 . V_80 )
V_52 = true ;
else
V_52 = false ;
return V_52 ;
}
void F_14 ( struct V_1 * V_2 )
{
T_1 V_3 = V_2 -> V_3 ;
struct V_65 * V_66 = & V_2 -> V_67 ;
if( V_66 -> V_79 . V_80 )
V_3 -> V_81 = V_82 ;
else if( V_66 -> V_78 ) {
V_3 -> V_81 = V_83 ;
}
else if( ( memcmp ( V_66 -> V_68 , V_75 , 3 ) == 0 ) ||
( memcmp ( V_66 -> V_68 , V_76 , 3 ) == 0 ) ||
( memcmp ( V_66 -> V_68 , V_77 , 3 ) == 0 ) ) {
V_3 -> V_81 = V_83 ;
}
else if( ( memcmp ( V_66 -> V_68 , V_69 , 3 ) == 0 ) ||
( memcmp ( V_66 -> V_68 , V_70 , 3 ) == 0 ) ||
( memcmp ( V_66 -> V_68 , V_71 , 3 ) == 0 ) ||
( memcmp ( V_66 -> V_68 , V_72 , 3 ) == 0 ) ||
( memcmp ( V_66 -> V_68 , V_73 , 3 ) == 0 ) ||
V_66 -> V_74 )
V_3 -> V_81 = V_84 ;
else if( ( V_66 -> V_85 ) || ( memcmp ( V_66 -> V_68 , V_86 , 3 ) == 0 ) )
V_3 -> V_81 = V_87 ;
else if( memcmp ( V_66 -> V_68 , V_88 , 3 ) == 0 )
V_3 -> V_81 = V_89 ;
else if ( ( memcmp ( V_66 -> V_68 , V_90 , 3 ) == 0 ) ||
V_66 -> V_91 ) {
V_3 -> V_81 = V_92 ;
}
else
V_3 -> V_81 = V_93 ;
F_6 ( V_94 , L_34 , V_3 -> V_81 ) ;
}
T_2 F_15 ( struct V_1 * V_2 , T_2 * V_95 )
{
T_2 V_96 = 0 ;
#if 0
#if ( V_97 == V_98 && V_99 == V_100 )
if((memcmp(PeerMacAddr, UNKNOWN_BORADCOM, 3)==0) ||
(memcmp(PeerMacAddr, LINKSYSWRT330_LINKSYSWRT300_BROADCOM, 3)==0)
)
{
ret = 1;
}
if(pHTInfo->bCurrentRT2RTAggregation)
{
ret = 1;
}
#endif
#endif
return V_96 ;
}
T_2 F_16 ( struct V_1 * V_2 , struct V_65 * V_101 )
{
T_2 V_52 = 0 ;
if( V_2 -> V_3 -> V_81 == V_92 )
{
V_52 = 1 ;
}
return V_52 ;
}
bool F_17 ( struct V_1 * V_2 )
{
bool V_52 = false ;
#ifdef F_18
#if ( V_97 == V_98 )
#if ( V_99 == V_100 )
V_52 = true ;
#elif ( V_99 == V_102 )
V_52 = false ;
#endif
#endif
#endif
return V_52 ;
}
bool F_19 ( struct V_1 * V_2 , T_2 * V_95 )
{
bool V_52 = false ;
#ifdef F_18
if( F_20 ( V_103 ) )
{
if( ( F_21 ( V_95 , V_69 , 3 ) == 0 ) ||
( F_21 ( V_95 , V_71 , 3 ) == 0 ) ||
( F_21 ( V_95 , V_72 , 3 ) == 0 ) )
{
V_52 = false ;
}
}
#endif
return V_52 ;
}
T_2 F_22 ( struct V_1 * V_2 , T_2 * V_95 )
{
T_2 V_52 = false ;
return V_52 ;
#if 0
if((memcmp(PeerMacAddr, UNKNOWN_BORADCOM, 3)==0)||
(memcmp(PeerMacAddr, LINKSYSWRT330_LINKSYSWRT300_BROADCOM, 3)==0)||
(memcmp(PeerMacAddr, LINKSYSWRT350_LINKSYSWRT150_BROADCOM, 3)==0)||
(memcmp(PeerMacAddr, NETGEAR834Bv2_BROADCOM, 3)==0))
{
retValue = 1;
}
return retValue;
#endif
}
T_2 F_23 ( struct V_65 * V_101 )
{
T_2 V_52 = 0 ;
if( V_101 -> V_78 )
{
V_52 = 1 ;
}
return V_52 ;
}
T_2 F_24 ( T_2 * V_95 )
{
T_2 V_52 = 0 ;
if( ( memcmp ( V_95 , V_75 , 3 ) == 0 ) ||
( memcmp ( V_95 , V_76 , 3 ) == 0 ) ||
( memcmp ( V_95 , V_77 , 3 ) == 0 ) )
{
V_52 = 1 ;
}
return V_52 ;
}
bool
F_25 ( struct V_1 * V_2 , struct V_65 * V_101 )
{
bool V_52 = false ;
T_1 V_3 = V_2 -> V_3 ;
{
if( V_3 -> V_81 == V_83 )
return true ;
}
return V_52 ;
}
void F_26 (
T_1 V_3
)
{
V_3 -> V_104 = 0 ;
V_3 -> V_81 = V_93 ;
}
void F_27 ( struct V_1 * V_2 , T_2 * V_105 , T_2 * V_106 , T_2 V_107 )
{
T_1 V_108 = V_2 -> V_3 ;
T_3 V_32 = NULL ;
if ( ( V_105 == NULL ) || ( V_108 == NULL ) )
{
F_6 ( V_109 , L_35 ) ;
return;
}
memset ( V_105 , 0 , * V_106 ) ;
if( V_108 -> V_110 == V_111 )
{
T_2 V_31 [] = { 0x00 , 0x90 , 0x4c , 0x33 } ;
memcpy ( V_105 , V_31 , sizeof( V_31 ) ) ;
V_32 = ( T_3 ) & ( V_105 [ 4 ] ) ;
} else
{
V_32 = ( T_3 ) V_105 ;
}
V_32 -> V_112 = 0 ;
if ( V_2 -> V_54 ( V_2 ) )
{
V_32 -> V_35 = 0 ;
}
else
{
V_32 -> V_35 = ( V_108 -> V_6 ? 1 : 0 ) ;
}
V_32 -> V_113 = V_108 -> V_13 ;
V_32 -> V_114 = 0 ;
V_32 -> V_36 = 1 ;
V_32 -> V_37 = 1 ;
V_32 -> V_38 = 1 ;
V_32 -> V_115 = 0 ;
V_32 -> V_116 = 0 ;
V_32 -> V_39 = ( V_117 >= 7935 ) ? 1 : 0 ;
V_32 -> V_40 = ( ( V_108 -> V_6 ) ? ( V_108 -> V_7 ? 1 : 0 ) : 0 ) ;
V_32 -> V_118 = 0 ;
V_32 -> V_119 = 0 ;
F_6 ( V_33 , L_36 , V_32 -> V_35 , V_32 -> V_39 , V_32 -> V_40 ) ;
if( V_107 )
{
V_32 -> V_42 = 7 ;
V_32 -> V_41 = 2 ;
}
else
{
V_32 -> V_41 = 3 ;
V_32 -> V_42 = 0 ;
}
memcpy ( V_32 -> V_43 , V_2 -> V_120 , 16 ) ;
if( V_108 -> V_104 & V_121 )
V_32 -> V_43 [ 1 ] &= 0x7f ;
if( V_108 -> V_104 & V_122 )
V_32 -> V_43 [ 1 ] &= 0xbf ;
if( V_108 -> V_104 & V_123 )
V_32 -> V_43 [ 1 ] &= 0x00 ;
if ( V_2 -> V_54 ( V_2 ) )
{
int V_124 ;
for( V_124 = 1 ; V_124 < 16 ; V_124 ++ )
V_32 -> V_43 [ V_124 ] = 0 ;
}
memset ( & V_32 -> V_125 , 0 , 2 ) ;
memset ( V_32 -> V_126 , 0 , 4 ) ;
V_32 -> V_127 = 0 ;
if( V_108 -> V_110 == V_111 )
* V_106 = 30 + 2 ;
else
* V_106 = 26 + 2 ;
}
void F_28 ( struct V_1 * V_2 , T_2 * V_128 , T_2 * V_106 , T_2 V_107 )
{
T_1 V_108 = V_2 -> V_3 ;
T_4 V_46 = ( T_4 ) V_128 ;
if ( ( V_128 == NULL ) || ( V_46 == NULL ) )
{
F_6 ( V_109 , L_37 ) ;
return;
}
memset ( V_128 , 0 , * V_106 ) ;
if ( ( V_2 -> V_129 == V_130 ) || ( V_2 -> V_129 == V_131 ) )
{
V_46 -> V_47 = V_2 -> V_67 . V_132 ;
V_46 -> V_48 = ( ( V_108 -> V_6 == false ) ? V_133 :
( V_2 -> V_67 . V_132 <= 6 ) ?
V_134 : V_135 ) ;
V_46 -> V_49 = V_108 -> V_6 ;
V_46 -> V_136 = 0 ;
V_46 -> V_137 = 0 ;
V_46 -> V_138 = 0 ;
V_46 -> V_50 = V_108 -> V_139 ;
V_46 -> V_140 = 0 ;
V_46 -> V_141 = 0 ;
V_46 -> V_142 = 0 ;
V_46 -> V_143 = 0 ;
V_46 -> V_144 = 0 ;
V_46 -> V_145 = 0 ;
memset ( V_46 -> V_51 , 0 , 16 ) ;
* V_106 = 22 + 2 ;
}
else
{
* V_106 = 0 ;
}
}
void F_29 ( struct V_1 * V_2 , T_2 * V_146 , T_2 * V_106 )
{
if ( V_146 == NULL ) {
F_6 ( V_109 , L_38 ) ;
return;
}
memset ( V_146 , 0 , * V_106 ) ;
* V_146 ++ = 0x00 ;
* V_146 ++ = 0xe0 ;
* V_146 ++ = 0x4c ;
* V_146 ++ = 0x02 ;
* V_146 ++ = 0x01 ;
* V_146 = 0x10 ;
if( V_2 -> V_147 ) {
* V_146 |= 0x08 ;
}
* V_106 = 6 + 2 ;
return;
#ifdef F_18
#if ( V_97 == V_98 && V_99 == V_100 )
#else
#endif
V_146 -> V_148 = 6 ;
#endif
}
T_2 F_30 ( struct V_1 * V_2 , T_2 * V_149 )
{
T_2 V_124 ;
if ( V_149 == NULL )
{
F_6 ( V_109 , L_39 ) ;
return false ;
}
switch( V_2 -> V_150 )
{
case V_151 :
case V_152 :
case V_153 :
for( V_124 = 0 ; V_124 <= 15 ; V_124 ++ ) {
V_149 [ V_124 ] = 0 ;
}
break;
case V_154 :
case V_155 :
V_149 [ 0 ] &= V_156 ;
V_149 [ 1 ] &= V_157 ;
V_149 [ 3 ] &= V_158 ;
break;
default:
break;
}
return true ;
}
T_2 F_31 ( struct V_1 * V_2 , T_2 * V_159 , T_2 * V_160 )
{
T_2 V_124 , V_161 ;
T_2 V_162 ;
T_2 V_163 = 0 ;
T_2 V_164 [ 16 ] ;
if ( V_159 == NULL || V_160 == NULL )
{
F_6 ( V_109 , L_40 ) ;
return false ;
}
for( V_124 = 0 ; V_124 < 16 ; V_124 ++ )
V_164 [ V_124 ] = V_159 [ V_124 ] & V_160 [ V_124 ] ;
for( V_124 = 0 ; V_124 < 16 ; V_124 ++ )
{
if( V_164 [ V_124 ] != 0 )
break;
}
if( V_124 == 16 )
return false ;
for( V_124 = 0 ; V_124 < 16 ; V_124 ++ )
{
if( V_164 [ V_124 ] != 0 )
{
V_162 = V_164 [ V_124 ] ;
for( V_161 = 0 ; V_161 < 8 ; V_161 ++ )
{
if( ( V_162 % 2 ) != 0 )
{
if( F_11 ( V_2 , ( 8 * V_124 + V_161 ) ) > F_11 ( V_2 , V_163 ) )
V_163 = ( 8 * V_124 + V_161 ) ;
}
V_162 = V_162 >> 1 ;
}
}
}
return ( V_163 | 0x80 ) ;
}
T_2 F_32 ( struct V_1 * V_2 , T_2 * V_165 , T_2 * V_149 )
{
T_2 V_124 = 0 ;
for( V_124 = 0 ; V_124 <= 15 ; V_124 ++ ) {
V_149 [ V_124 ] = V_2 -> V_120 [ V_124 ] & V_165 [ V_124 ] ;
}
F_30 ( V_2 , V_149 ) ;
if ( V_2 -> V_54 ( V_2 ) )
V_149 [ 1 ] = 0 ;
for( V_124 = 2 ; V_124 <= 15 ; V_124 ++ )
V_149 [ V_124 ] = 0 ;
return true ;
}
void F_33 ( struct V_1 * V_2 )
{
T_1 V_3 = V_2 -> V_3 ;
T_3 V_166 = NULL ;
T_4 V_167 = NULL ;
T_5 V_168 = 0 ;
T_2 * V_169 = NULL ;
static T_2 V_31 [] = { 0x00 , 0x90 , 0x4c , 0x33 } ;
static T_2 V_45 [] = { 0x00 , 0x90 , 0x4c , 0x34 } ;
if( V_3 -> V_53 == false )
{
F_6 ( V_109 , L_41 ) ;
return;
}
F_6 ( V_33 , L_42 ) ;
if( ! memcmp ( V_3 -> V_55 , V_31 , sizeof( V_31 ) ) )
V_166 = ( T_3 ) ( & V_3 -> V_55 [ 4 ] ) ;
else
V_166 = ( T_3 ) ( V_3 -> V_55 ) ;
if( ! memcmp ( V_3 -> V_170 , V_45 , sizeof( V_45 ) ) )
V_167 = ( T_4 ) ( & V_3 -> V_170 [ 4 ] ) ;
else
V_167 = ( T_4 ) ( V_3 -> V_170 ) ;
F_34 ( V_171 | V_33 , V_166 , sizeof( V_172 ) ) ;
F_35 ( V_2 , ( V_173 ) ( V_166 -> V_35 ) , ( V_174 ) ( V_167 -> V_48 ) ) ;
V_3 -> V_175 = ( ( V_167 -> V_49 == 1 ) ? true : false ) ;
V_3 -> V_62 =
( ( V_3 -> V_4 ) ? ( ( V_166 -> V_36 == 1 ) ? true : false ) : false ) ;
V_3 -> V_61 =
( ( V_3 -> V_5 ) ? ( ( V_166 -> V_37 == 1 ) ? true : false ) : false ) ;
V_3 -> V_176 =
( ( V_3 -> V_7 ) ? ( ( V_166 -> V_40 == 1 ) ? true : false ) : false ) ;
V_3 -> V_177 = V_3 -> V_9 ;
if ( V_2 -> V_178 &&
( V_2 -> V_178 ( V_2 ) & ( V_179 | V_180 ) ) ) {
if( ( V_3 -> V_81 == V_87 ) ||
( V_3 -> V_81 == V_93 ) )
V_3 -> V_181 = false ;
}
V_168 = ( V_166 -> V_39 == 0 ) ? 3839 : 7935 ;
if( V_3 -> V_8 > V_168 )
V_3 -> V_182 = V_168 ;
else
V_3 -> V_182 = V_3 -> V_8 ;
V_3 -> V_181 = V_3 -> V_10 ;
if( ! V_3 -> V_20 )
{
if( V_3 -> V_11 > V_166 -> V_41 )
V_3 -> V_183 = V_166 -> V_41 ;
else
V_3 -> V_183 = V_3 -> V_11 ;
} else
{
#if 0
osTmp= PacketGetElement( asocpdu, EID_Vendor, OUI_SUB_REALTEK_AGG, OUI_SUBTYPE_DONT_CARE);
if(osTmp.Length >= 5)
#endif
if ( V_2 -> V_67 . V_79 . V_80 )
{
if( V_2 -> V_184 != V_185 )
V_3 -> V_183 = V_166 -> V_41 ;
else
V_3 -> V_183 = V_186 ;
} else
{
if( V_166 -> V_41 < V_187 )
V_3 -> V_183 = V_166 -> V_41 ;
else
V_3 -> V_183 = V_187 ;
}
}
#if 1
if( V_3 -> V_12 > V_166 -> V_42 )
V_3 -> V_188 = V_3 -> V_12 ;
else
V_3 -> V_188 = V_166 -> V_42 ;
if( V_2 -> V_184 != V_185 )
V_3 -> V_188 = 7 ;
#else
if( V_3 -> V_12 > V_166 -> V_42 )
V_3 -> V_188 = V_3 -> V_12 ;
else
V_3 -> V_188 = V_166 -> V_42 ;
#endif
if( 0 )
{
V_3 -> V_181 = false ;
V_3 -> V_189 = V_190 ;
V_3 -> V_191 = 7935 ;
V_3 -> V_104 |= V_192 ;
}
V_3 -> V_193 = V_3 -> V_21 ;
if( V_166 -> V_43 [ 0 ] == 0 )
V_166 -> V_43 [ 0 ] = 0xff ;
F_32 ( V_2 , V_166 -> V_43 , V_2 -> V_194 ) ;
V_3 -> V_195 = V_166 -> V_113 ;
if( V_3 -> V_195 == V_196 )
V_169 = V_197 ;
else
V_169 = V_198 ;
V_2 -> V_199 = F_31 ( V_2 , V_2 -> V_194 , V_169 ) ;
V_2 -> V_200 = V_2 -> V_199 ;
V_3 -> V_139 = V_167 -> V_50 ;
}
void F_36 ( struct V_1 * V_2 )
{
T_1 V_3 = V_2 -> V_3 ;
F_6 ( V_33 , L_43 , V_34 ) ;
V_3 -> V_53 = false ;
V_3 -> V_60 = false ;
V_3 -> V_175 = false ;
V_3 -> V_62 = false ;
V_3 -> V_61 = false ;
V_3 -> V_201 = false ;
V_3 -> V_176 = true ;
V_3 -> V_177 = false ;
V_3 -> V_182 = V_3 -> V_8 ;
V_3 -> V_188 = V_3 -> V_12 ;
V_3 -> V_183 = V_3 -> V_11 ;
memset ( ( void * ) ( & ( V_3 -> V_202 ) ) , 0 , sizeof( V_3 -> V_202 ) ) ;
memset ( ( void * ) ( & ( V_3 -> V_203 ) ) , 0 , sizeof( V_3 -> V_203 ) ) ;
memset ( ( void * ) ( & ( V_3 -> V_55 ) ) , 0 , sizeof( V_3 -> V_55 ) ) ;
memset ( ( void * ) ( & ( V_3 -> V_170 ) ) , 0 , sizeof( V_3 -> V_170 ) ) ;
V_3 -> V_204 = false ;
V_3 -> V_205 = V_206 ;
V_3 -> V_110 = V_207 ;
V_3 -> V_208 = false ;
V_3 -> V_209 = false ;
V_3 -> V_81 = 0 ;
V_3 -> V_104 = 0 ;
{
T_2 * V_210 = & ( V_2 -> V_211 [ 0 ] ) ;
V_210 [ 0 ] = 0xFF ;
V_210 [ 1 ] = 0xFF ;
V_210 [ 4 ] = 0x01 ;
}
}
void F_37 ( T_6 V_212 )
{
V_212 -> V_213 = false ;
memset ( V_212 -> V_214 , 0 , sizeof( V_212 -> V_214 ) ) ;
V_212 -> V_215 = 0 ;
memset ( V_212 -> V_216 , 0 , sizeof( V_212 -> V_216 ) ) ;
V_212 -> V_217 = 0 ;
V_212 -> V_218 = V_207 ;
V_212 -> V_80 = false ;
V_212 -> V_219 = false ;
}
void F_38 ( struct V_1 * V_2 , struct V_65 * V_220 )
{
T_1 V_3 = V_2 -> V_3 ;
T_2 V_221 = 0 ;
F_6 ( V_33 , L_44 , V_34 ) ;
if ( V_220 -> V_79 . V_213 )
{
V_3 -> V_53 = true ;
V_3 -> V_110 = V_220 -> V_79 . V_218 ;
if( V_220 -> V_79 . V_215 > 0 && V_220 -> V_79 . V_215 <= sizeof( V_3 -> V_55 ) )
memcpy ( V_3 -> V_55 , V_220 -> V_79 . V_214 , V_220 -> V_79 . V_215 ) ;
if( V_220 -> V_79 . V_217 > 0 && V_220 -> V_79 . V_217 <= sizeof( V_3 -> V_170 ) )
memcpy ( V_3 -> V_170 , V_220 -> V_79 . V_216 , V_220 -> V_79 . V_217 ) ;
if( V_3 -> V_20 )
{
V_3 -> V_208 = V_220 -> V_79 . V_80 ;
V_3 -> V_209 = V_220 -> V_79 . V_219 ;
}
else
{
V_3 -> V_208 = false ;
V_3 -> V_209 = false ;
}
F_14 ( V_2 ) ;
V_3 -> V_104 = 0 ;
V_221 = F_15 ( V_2 , V_220 -> V_68 ) ;
if( V_221 )
V_3 -> V_104 |= V_122 ;
V_221 = F_16 ( V_2 , V_220 ) ;
if( V_221 )
V_3 -> V_104 |= V_222 ;
V_221 = F_17 ( V_2 ) ;
if( V_221 )
V_3 -> V_104 |= V_121 ;
V_221 = F_19 ( V_2 , V_220 -> V_68 ) ;
if( V_221 )
V_3 -> V_104 |= V_123 ;
V_221 = F_22 ( V_2 , V_220 -> V_68 ) ;
if( V_221 )
V_3 -> V_104 |= V_223 ;
V_221 = F_23 ( V_220 ) ;
if( V_221 )
V_3 -> V_104 |= V_224 ;
V_221 = F_24 ( V_220 -> V_68 ) ;
if( V_221 )
V_3 -> V_104 |= V_225 ;
V_221 = F_25 ( V_2 , V_220 ) ;
if( V_221 )
V_3 -> V_104 |= V_226 ;
}
else
{
V_3 -> V_53 = false ;
V_3 -> V_208 = false ;
V_3 -> V_209 = false ;
V_3 -> V_104 = 0 ;
}
}
void F_39 ( struct V_1 * V_2 , struct V_65 * V_220 )
{
T_1 V_3 = V_2 -> V_3 ;
T_4 V_167 = ( T_4 ) V_220 -> V_79 . V_216 ;
if( V_3 -> V_53 )
{
if( V_220 -> V_79 . V_217 != 0 )
V_3 -> V_139 = V_167 -> V_50 ;
}
}
void F_40 ( struct V_1 * V_2 )
{
T_1 V_3 = V_2 -> V_3 ;
if( V_3 -> V_227 )
{
V_3 -> V_53 = true ;
V_3 -> V_176 = V_3 -> V_7 ;
V_3 -> V_60 = V_3 -> V_6 ;
V_3 -> V_62 = V_3 -> V_4 ;
V_3 -> V_61 = V_3 -> V_5 ;
V_3 -> V_177 = V_3 -> V_9 ;
V_3 -> V_182 = V_3 -> V_8 ;
V_3 -> V_181 = V_3 -> V_10 ;
V_3 -> V_183 = V_3 -> V_11 ;
V_3 -> V_188 = V_3 -> V_188 ;
F_32 ( V_2 , V_2 -> V_120 , V_2 -> V_194 ) ;
#ifdef F_18
V_103 -> V_228 . V_229 ( V_103 , & V_16 -> V_230 , V_16 -> V_194 ) ;
#endif
V_2 -> V_199 = F_31 ( V_2 , V_2 -> V_194 , V_198 ) ;
V_2 -> V_200 = V_2 -> V_199 ;
}
else
{
V_3 -> V_53 = false ;
}
}
T_2 F_41 ( struct V_1 * V_2 , T_2 * V_231 )
{
if( V_2 -> V_3 -> V_53 )
{
if( ( F_42 ( V_231 ) && F_43 ( V_231 ) ) == 1 )
{
F_6 ( V_33 , L_45 ) ;
return true ;
}
}
return false ;
}
void F_35 ( struct V_1 * V_2 , V_173 V_232 , V_174 V_233 )
{
T_1 V_3 = V_2 -> V_3 ;
if( V_3 -> V_6 == false )
return;
if( V_3 -> V_204 ) {
return;
}
if ( V_232 == V_234 && ( ! V_2 -> V_54 ( V_2 ) ) )
{
if( V_2 -> V_67 . V_132 < 2 && V_233 == V_135 )
V_233 = V_133 ;
if( V_233 == V_134 || V_233 == V_135 ) {
V_3 -> V_60 = true ;
V_3 -> V_235 = V_233 ;
} else {
V_3 -> V_60 = false ;
V_3 -> V_235 = V_133 ;
}
} else {
V_3 -> V_60 = false ;
V_3 -> V_235 = V_133 ;
}
V_3 -> V_204 = true ;
F_44 ( V_2 ) ;
}
void F_44 ( struct V_1 * V_2 )
{
T_1 V_3 = V_2 -> V_3 ;
F_6 ( V_33 , L_46 , V_34 ) ;
if( V_3 -> V_60 )
{
if( V_3 -> V_235 == V_134 )
V_2 -> V_236 ( V_2 , V_2 -> V_67 . V_132 + 2 ) ;
else if( V_3 -> V_235 == V_135 )
V_2 -> V_236 ( V_2 , V_2 -> V_67 . V_132 - 2 ) ;
else
V_2 -> V_236 ( V_2 , V_2 -> V_67 . V_132 ) ;
V_2 -> V_237 ( V_2 , V_234 , V_3 -> V_235 ) ;
} else {
V_2 -> V_236 ( V_2 , V_2 -> V_67 . V_132 ) ;
V_2 -> V_237 ( V_2 , V_238 , V_133 ) ;
}
V_3 -> V_204 = false ;
}
