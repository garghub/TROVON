INLINE T_1 F_1 ( T_1 V_1 )
{
if ( ( V_1 >= '0' ) && ( V_1 <= '9' ) )
return ( V_1 - '0' ) ;
else if ( ( V_1 >= 'A' ) && ( V_1 <= 'F' ) )
return ( 10 + ( V_1 - 'A' ) ) ;
else if ( ( V_1 >= 'a' ) && ( V_1 <= 'f' ) )
return ( 10 + ( V_1 - 'a' ) ) ;
return V_2 ;
}
INLINE T_1 F_2 ( T_1 V_3 )
{
T_1 * V_4 = L_1 ;
return V_4 [ V_3 & 0xF ] ;
}
INLINE T_2 F_3 ( char * V_5 , T_1 * V_6 )
{
* V_6 = 0 ;
while ( * V_5 != '\0' ) {
if ( ( * V_5 == ':' ) || ( * V_5 == '-' ) )
* ( ++ V_6 ) = 0 ;
else
* V_6 = ( * V_6 << 4 ) + F_1 ( * V_5 ) ;
V_5 ++ ;
}
return V_7 ;
}
INLINE void F_4 ( T_1 * V_5 , T_1 * V_6 )
{
T_3 V_8 = 0 ;
T_3 V_9 = 0 ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ ) {
V_5 [ V_9 ++ ] = F_2 ( ( T_1 ) ( ( V_6 [ V_8 ] >> 4 ) & 0x0F ) ) ;
V_5 [ V_9 ++ ] = F_2 ( ( T_1 ) ( V_6 [ V_8 ] & 0x0F ) ) ;
V_5 [ V_9 ++ ] = ':' ;
}
V_5 [ -- V_9 ] = '\0' ;
}
INLINE T_1 F_5 ( T_1 * V_10 , T_3 * V_11 )
{
T_1 V_8 = 0 ;
T_1 V_12 = 0 ;
* V_11 = 0 ;
while ( V_10 [ V_8 ] != '\0' ) {
if ( V_10 [ V_8 ] == '.' ) {
* V_11 = ( ( * V_11 ) << 8 ) | V_12 ;
V_12 = 0 ;
} else {
V_12 = V_12 * 10 + F_1 ( V_10 [ V_8 ] ) ;
}
V_8 ++ ;
}
* V_11 = ( ( * V_11 ) << 8 ) | V_12 ;
return 0 ;
}
INLINE T_1 F_6 ( T_1 * V_10 , T_3 V_11 )
{
T_1 V_8 = 0 ;
T_1 V_12 = 0 ;
T_1 V_13 = 0 ;
T_1 V_14 = 0 ;
for ( V_13 = 4 ; V_13 > 0 ; V_13 -- ) {
V_12 = ( V_11 >> ( 8 * ( V_13 - 1 ) ) ) & 0xFF ;
if ( V_12 >= 100 )
V_14 = 2 ;
else if ( V_12 >= 10 )
V_14 = 1 ;
else
V_14 = 0 ;
switch ( V_14 ) {
case 2 :
V_10 [ V_8 ++ ] = F_2 ( V_12 / 100 ) ;
V_12 %= 100 ;
case 1 :
V_10 [ V_8 ++ ] = F_2 ( V_12 / 10 ) ;
V_12 %= 10 ;
default:
V_10 [ V_8 ++ ] = F_2 ( V_12 ) ;
}
if ( V_13 > 1 )
V_10 [ V_8 ++ ] = '.' ;
}
V_10 [ V_8 ] = '\0' ;
return V_8 ;
}
INLINE T_4 F_7 ( T_3 V_15 )
{
if ( ( V_15 == V_16 ) ||
( V_15 == V_17 ) ||
( V_15 == V_18 ) ||
( V_15 == V_19 ) ) {
return V_20 ;
}
if ( ( V_21 == V_15 ) ||
( V_22 == V_15 ) ||
( V_23 == V_15 ) ) {
return V_24 ;
}
if ( V_15 < 0x1000 )
return V_25 ;
else if ( V_15 < 0x2000 )
return V_26 ;
else if ( V_15 < 0x3000 )
return V_27 ;
else if ( V_15 < 0x4000 )
return V_28 ;
else if ( V_15 < 0x5000 )
return V_29 ;
return V_30 ;
}
INLINE T_2 F_8 ( T_1 * V_31 )
{
T_2 V_32 = 0 ;
V_32 = V_31 [ 0 ] ;
V_32 |= ( V_31 [ 1 ] << 8 ) ;
return V_32 ;
}
INLINE T_3 F_9 ( T_1 * V_31 )
{
T_3 V_33 = 0 ;
T_3 V_34 = V_35 ;
V_33 |= V_31 [ V_34 ++ ] ;
V_33 |= ( V_31 [ V_34 ++ ] << 8 ) ;
V_33 |= ( V_31 [ V_34 ++ ] << 16 ) ;
V_33 |= ( V_31 [ V_34 ] << 24 ) ;
return V_33 ;
}
INLINE T_3 F_10 ( T_1 * V_31 )
{
T_3 V_33 = 0 ;
T_3 V_34 = ( V_35 + 4 ) ;
V_33 |= V_31 [ V_34 ++ ] ;
V_33 |= ( V_31 [ V_34 ++ ] << 8 ) ;
V_33 |= ( V_31 [ V_34 ++ ] << 16 ) ;
V_33 |= ( V_31 [ V_34 ] << 24 ) ;
return V_33 ;
}
INLINE T_5 F_11 ( T_1 * V_36 )
{
return ( ( T_5 ) ( V_36 [ 0 ] & 0x0C ) ) ;
}
INLINE T_6 F_12 ( T_1 * V_36 )
{
return ( ( T_6 ) ( V_36 [ 0 ] & 0xFC ) ) ;
}
INLINE T_1 F_13 ( T_1 * V_36 )
{
return ( V_36 [ 1 ] & 0x01 ) ;
}
INLINE T_1 F_14 ( T_1 * V_36 )
{
return ( ( V_36 [ 1 ] & 0x02 ) >> 1 ) ;
}
INLINE void F_15 ( T_1 * V_37 , T_1 * V_38 )
{
F_16 ( V_38 , V_37 + 4 , 6 ) ;
}
INLINE void F_17 ( T_1 * V_37 , T_1 * V_38 )
{
F_16 ( V_38 , V_37 + 10 , 6 ) ;
}
INLINE void F_18 ( T_1 * V_37 , T_1 * V_38 )
{
F_16 ( V_38 , V_37 + 16 , 6 ) ;
}
INLINE void F_19 ( T_1 * V_31 , T_1 * V_39 )
{
if ( F_14 ( V_31 ) == 1 )
F_17 ( V_31 , V_39 ) ;
else if ( F_13 ( V_31 ) == 1 )
F_15 ( V_31 , V_39 ) ;
else
F_18 ( V_31 , V_39 ) ;
}
INLINE void F_20 ( T_1 * V_31 , T_1 * V_40 , T_1 * V_41 )
{
T_1 V_42 = 0 ;
T_1 V_8 = 0 ;
T_1 V_9 = 0 ;
V_42 = V_31 [ V_35 + V_43 + V_44 +
V_45 + 1 ] ;
V_9 = V_35 + V_43 + V_44 +
V_45 + 2 ;
if ( V_42 >= V_46 )
V_42 = 0 ;
for ( V_8 = 0 ; V_8 < V_42 ; V_8 ++ , V_9 ++ )
V_40 [ V_8 ] = V_31 [ V_9 ] ;
V_40 [ V_42 ] = '\0' ;
* V_41 = V_42 ;
}
INLINE T_2 F_21 ( T_1 * V_31 )
{
T_2 V_47 = 0 ;
T_2 V_34 = V_35 ;
T_6 V_48 = V_49 ;
V_48 = F_12 ( V_31 ) ;
if ( ( V_48 == V_49 ) || ( V_48 == V_50 ) )
V_34 += V_43 + V_44 ;
V_47 = V_31 [ V_34 ] ;
V_47 |= ( V_31 [ V_34 + 1 ] << 8 ) ;
return V_47 ;
}
INLINE T_2 F_22 ( T_1 * V_31 )
{
T_2 V_47 = 0 ;
V_47 = V_31 [ 0 ] ;
V_47 |= ( V_31 [ 1 ] << 8 ) ;
return V_47 ;
}
INLINE T_2 F_23 ( T_1 * V_31 )
{
T_2 V_51 = 0 ;
V_51 = V_31 [ 3 ] ;
V_51 = ( V_51 << 8 ) | V_31 [ 2 ] ;
return V_51 ;
}
INLINE T_2 F_24 ( T_1 * V_31 )
{
T_2 V_52 = 0 ;
V_52 = V_31 [ 4 ] ;
V_52 |= ( V_31 [ 5 ] << 8 ) ;
return V_52 ;
}
T_7 F_25 ( void )
{
T_7 V_53 = V_54 ;
F_26 ( V_55 , L_2 ) ;
F_27 ( & V_56 , 1 ) ;
F_27 ( & V_57 , 0 ) ;
V_58 = ( V_59 * ) F_28 ( V_60 ) ;
if ( V_58 == NULL ) {
F_29 ( L_3 ) ;
V_53 = V_61 ;
goto V_62;
}
F_30 ( ( void * ) V_58 , 0 , V_60 ) ;
F_30 ( ( void * ) ( & V_63 ) , 0 , sizeof( V_64 ) ) ;
V_62:
return V_53 ;
}
T_1 * F_31 ( T_1 * V_37 , T_2 V_65 , T_2 V_66 )
{
T_2 V_67 = 0 ;
V_67 = V_66 ;
while ( V_67 < ( V_65 - V_68 ) ) {
if ( V_37 [ V_67 ] == V_69 ) {
return & V_37 [ V_67 ] ;
} else {
V_67 += ( V_70 + V_37 [ V_67 + 1 ] ) ;
}
}
return 0 ;
}
T_1 F_32 ( T_1 * V_37 , T_2 V_65 )
{
T_2 V_34 ;
V_34 = V_71 ;
while ( V_34 < ( V_65 - V_68 ) ) {
if ( V_37 [ V_34 ] == V_72 )
return V_37 [ V_34 + 2 ] ;
else
V_34 += V_37 [ V_34 + 1 ] + V_70 ;
}
return 0 ;
}
T_1 F_33 ( T_1 * V_37 , T_2 V_65 )
{
#ifdef F_34
#ifdef F_35
return ( F_36 () + 1 ) ;
#else
return F_32 ( V_37 , V_65 ) ;
#endif
#else
return 0 ;
#endif
}
T_7 F_37 ( T_1 * V_73 , T_8 * * V_74 )
{
T_7 V_53 = V_54 ;
T_8 * V_75 = NULL ;
T_1 V_76 = 0 ;
T_1 V_77 = 0 ;
T_2 V_78 = 0 ;
T_2 V_79 = ( T_2 ) V_80 ;
T_2 V_81 = 0 ;
T_1 * V_82 = 0 ;
V_76 = V_73 [ 0 ] ;
if ( 'N' != V_76 ) {
F_29 ( L_4 ) ;
F_38 ( V_53 , V_83 ) ;
}
V_77 = V_73 [ 1 ] ;
V_78 = F_39 ( V_73 [ 2 ] , V_73 [ 3 ] ) ;
V_79 = F_39 ( V_73 [ 4 ] , V_73 [ 5 ] ) ;
V_81 = F_39 ( V_73 [ 6 ] , V_73 [ 7 ] ) ;
V_82 = & V_73 [ 8 ] ;
{
T_1 * V_37 = 0 ;
T_2 V_65 = 0 ;
T_1 * V_84 = 0 ;
T_1 * V_85 = 0 ;
T_2 V_86 = 0 ;
T_1 V_87 = 0 ;
T_3 V_88 ;
T_3 V_89 ;
V_75 = ( T_8 * ) F_28 ( sizeof( T_8 ) ) ;
F_30 ( ( void * ) ( V_75 ) , 0 , sizeof( T_8 ) ) ;
V_75 -> V_90 = V_82 [ 0 ] ;
V_37 = & V_82 [ 1 ] ;
V_65 = V_81 - 1 ;
V_75 -> V_91 = F_21 ( V_37 ) ;
#ifdef F_40
V_75 -> V_92 = F_9 ( V_37 ) ;
F_26 ( V_55 , L_5 , V_75 -> V_92 ) ;
#endif
V_88 = F_9 ( V_37 ) ;
V_89 = F_10 ( V_37 ) ;
V_75 -> V_93 = V_88 | ( ( V_94 ) V_89 << 32 ) ;
F_20 ( V_37 , V_75 -> V_95 , & ( V_75 -> V_96 ) ) ;
F_19 ( V_37 , V_75 -> V_97 ) ;
V_75 -> V_98 = F_33 ( V_37 , ( V_65 + V_68 ) ) ;
V_87 = ( V_35 + V_43 ) ;
V_75 -> V_99 = F_8 ( V_37 + V_87 ) ;
V_87 += V_44 + V_45 ;
V_84 = F_31 ( V_37 , ( V_65 + V_68 ) , V_87 ) ;
if ( V_84 != 0 ) {
V_75 -> V_100 = V_84 [ 3 ] ;
}
V_85 = & V_37 [ V_35 + V_43 + V_44 + V_45 ] ;
V_86 = V_65 - ( V_35 + V_43 + V_44 + V_45 ) ;
if ( V_86 > 0 ) {
V_75 -> V_85 = ( T_1 * ) F_28 ( V_86 ) ;
F_30 ( ( void * ) ( V_75 -> V_85 ) , 0 , V_86 ) ;
F_16 ( V_75 -> V_85 , V_85 , V_86 ) ;
}
V_75 -> V_86 = V_86 ;
}
* V_74 = V_75 ;
V_101:
return V_53 ;
}
T_7 F_41 ( T_8 * V_75 )
{
T_7 V_53 = V_54 ;
if ( V_75 != NULL ) {
if ( V_75 -> V_85 != NULL ) {
F_42 ( V_75 -> V_85 ) ;
V_75 -> V_85 = NULL ;
} else {
V_53 = V_83 ;
}
F_42 ( V_75 ) ;
V_75 = NULL ;
} else {
V_53 = V_83 ;
}
return V_53 ;
}
T_7 F_43 ( T_1 * V_102 , T_3 V_103 ,
T_9 * * V_104 )
{
T_7 V_53 = V_54 ;
T_9 * V_105 = NULL ;
T_2 V_106 = 0 ;
T_1 * V_85 = 0 ;
T_2 V_86 = 0 ;
V_105 = ( T_9 * ) F_28 ( sizeof( T_9 ) ) ;
F_30 ( ( void * ) ( V_105 ) , 0 , sizeof( T_9 ) ) ;
V_106 = ( T_2 ) V_103 ;
V_105 -> V_107 = F_23 ( V_102 ) ;
if ( V_105 -> V_107 == V_108 ) {
V_105 -> V_109 = F_22 ( V_102 ) ;
V_105 -> V_110 = F_24 ( V_102 ) ;
V_85 = & V_102 [ V_45 + V_111 + V_112 ] ;
V_86 = V_106 - ( V_45 + V_111 + V_112 ) ;
V_105 -> V_113 = ( T_1 * ) F_28 ( V_86 ) ;
F_30 ( ( void * ) ( V_105 -> V_113 ) , 0 , V_86 ) ;
F_16 ( V_105 -> V_113 , V_85 , V_86 ) ;
V_105 -> V_114 = V_86 ;
}
* V_104 = V_105 ;
return V_53 ;
}
T_7 F_44 ( T_9 * V_105 )
{
T_7 V_53 = V_54 ;
if ( V_105 != NULL ) {
if ( V_105 -> V_113 != NULL ) {
F_42 ( V_105 -> V_113 ) ;
V_105 -> V_113 = NULL ;
} else {
V_53 = V_83 ;
}
F_42 ( V_105 ) ;
V_105 = NULL ;
} else {
V_53 = V_83 ;
}
return V_53 ;
}
T_7 F_45 ( T_1 V_115 [] [ V_116 ] ,
T_10 * * V_117 ,
T_3 * V_118 )
{
T_7 V_53 = V_54 ;
T_10 * V_119 = NULL ;
T_3 V_120 = 0 ;
T_3 V_121 = 0 ;
T_1 * V_122 ;
T_3 V_123 = 2 ;
T_1 V_124 ;
T_3 V_8 ;
T_3 V_9 ;
for ( V_8 = 0 ; V_8 < V_123 ; V_8 ++ ) {
V_121 = V_115 [ V_8 ] [ 0 ] ;
for ( V_9 = 0 ; V_9 < V_121 ; V_9 += V_125 ) {
V_120 ++ ;
}
}
V_119 = ( T_10 * ) F_28 ( V_120 * sizeof( T_10 ) ) ;
if ( V_119 == NULL ) {
V_120 = 0 ;
F_38 ( V_53 , V_61 ) ;
}
F_30 ( ( void * ) ( V_119 ) , 0 , V_120 * sizeof( T_10 ) ) ;
V_120 = 0 ;
for ( V_8 = 0 ; V_8 < V_123 ; V_8 ++ ) {
V_122 = V_115 [ V_8 ] ;
V_121 = V_122 [ 0 ] ;
V_124 = V_122 [ 1 ] ;
V_122 += 2 ;
for ( V_9 = 0 ; V_9 < V_121 ; V_9 += V_125 ) {
F_16 ( & V_119 [ V_120 ] , V_122 , V_125 ) ;
V_122 += V_125 ;
V_120 ++ ;
}
}
V_101:
* V_117 = V_119 ;
* V_118 = V_120 ;
return V_53 ;
}
T_7 F_46 ( T_10 * V_119 )
{
T_7 V_53 = V_54 ;
if ( V_119 != NULL ) {
F_42 ( V_119 ) ;
}
return V_53 ;
}
void F_47 ( char * V_126 , T_7 * V_127 ,
T_11 * V_128 , V_59 * V_129 )
{
T_1 * V_130 = ( T_1 * ) V_129 ;
T_1 V_131 = 0 ;
T_7 V_132 = * V_127 ;
if ( V_128 == NULL ) {
F_48 ( V_55 , L_6 , V_131 ) ;
return;
}
V_126 [ V_132 ++ ] = ( T_1 ) ( V_128 -> V_133 & 0xFF ) ;
V_126 [ V_132 ++ ] = ( T_1 ) ( V_128 -> V_133 >> 8 ) & 0xFF ;
if ( V_134 == V_135 ) {
V_131 = * V_130 ;
V_126 [ V_132 ++ ] = sizeof( T_1 ) ;
V_126 [ V_132 ++ ] = V_131 ;
}
* V_127 = V_132 ;
}
void F_49 ( char * V_126 , T_7 * V_127 ,
T_11 * V_128 , V_59 * V_129 )
{
T_2 * V_136 = ( T_2 * ) V_129 ;
T_2 V_137 = 0 ;
T_7 V_132 = * V_127 ;
if ( V_128 == NULL ) {
F_48 ( V_55 , L_7 , V_137 ) ;
return;
}
V_126 [ V_132 ++ ] = ( T_1 ) ( V_128 -> V_133 & 0xFF ) ;
V_126 [ V_132 ++ ] = ( T_1 ) ( ( V_128 -> V_133 >> 8 ) & 0xFF ) ;
if ( V_134 == V_135 ) {
V_137 = * V_136 ;
V_126 [ V_132 ++ ] = sizeof( T_2 ) ;
V_126 [ V_132 ++ ] = ( T_1 ) ( V_137 & 0xFF ) ;
V_126 [ V_132 ++ ] = ( T_1 ) ( ( V_137 >> 8 ) & 0xFF ) ;
}
* V_127 = V_132 ;
}
void F_50 ( char * V_126 , T_7 * V_127 ,
T_11 * V_128 , V_59 * V_129 )
{
T_3 * V_138 = ( T_3 * ) V_129 ;
T_3 V_139 = 0 ;
T_7 V_132 = * V_127 ;
if ( V_128 == NULL ) {
F_48 ( V_55 , L_8 , V_139 ) ;
return;
}
V_126 [ V_132 ++ ] = ( T_1 ) ( V_128 -> V_133 & 0xFF ) ;
V_126 [ V_132 ++ ] = ( T_1 ) ( ( V_128 -> V_133 >> 8 ) & 0xFF ) ;
if ( V_134 == V_135 ) {
V_139 = * V_138 ;
V_126 [ V_132 ++ ] = sizeof( T_3 ) ;
V_126 [ V_132 ++ ] = ( T_1 ) ( V_139 & 0xFF ) ;
V_126 [ V_132 ++ ] = ( T_1 ) ( ( V_139 >> 8 ) & 0xFF ) ;
V_126 [ V_132 ++ ] = ( T_1 ) ( ( V_139 >> 16 ) & 0xFF ) ;
V_126 [ V_132 ++ ] = ( T_1 ) ( ( V_139 >> 24 ) & 0xFF ) ;
}
* V_127 = V_132 ;
}
void F_51 ( char * V_126 , T_7 * V_127 ,
T_11 * V_128 , T_1 * V_140 )
{
T_3 V_139 = 0 ;
T_7 V_132 = * V_127 ;
if ( V_128 == NULL ) {
F_48 ( V_55 , L_9 ) ;
return;
}
V_126 [ V_132 ++ ] = ( T_1 ) ( V_128 -> V_133 & 0xFF ) ;
V_126 [ V_132 ++ ] = ( T_1 ) ( ( V_128 -> V_133 >> 8 ) & 0xFF ) ;
if ( V_134 == V_135 ) {
V_126 [ V_132 ++ ] = sizeof( T_3 ) ;
F_5 ( V_140 , & V_139 ) ;
V_126 [ V_132 ++ ] = ( T_1 ) ( V_139 & 0xFF ) ;
V_126 [ V_132 ++ ] = ( T_1 ) ( ( V_139 >> 8 ) & 0xFF ) ;
V_126 [ V_132 ++ ] = ( T_1 ) ( ( V_139 >> 16 ) & 0xFF ) ;
V_126 [ V_132 ++ ] = ( T_1 ) ( ( V_139 >> 24 ) & 0xFF ) ;
}
* V_127 = V_132 ;
}
void F_52 ( char * V_126 , T_7 * V_127 ,
T_11 * V_128 , T_1 * V_130 , T_7 V_141 )
{
T_2 V_78 = 0 ;
T_2 V_142 = 0 ;
T_7 V_132 = * V_127 ;
if ( V_128 == NULL ) {
F_48 ( V_55 , L_10 ) ;
return;
}
V_126 [ V_132 ++ ] = ( T_1 ) ( V_128 -> V_133 & 0xFF ) ;
V_126 [ V_132 ++ ] = ( T_1 ) ( ( V_128 -> V_133 >> 8 ) & 0xFF ) ;
if ( V_134 == V_135 ) {
V_78 = ( T_2 ) V_141 ;
V_126 [ V_132 ++ ] = ( T_1 ) V_78 ;
for ( V_142 = 0 ; V_142 < V_78 ; V_142 ++ )
V_126 [ V_132 ++ ] = V_130 [ V_142 ] ;
}
* V_127 = V_132 ;
}
void F_53 ( char * V_126 , T_7 * V_127 ,
T_11 * V_128 , T_1 * V_130 )
{
T_2 V_78 = 0 ;
T_7 V_132 = * V_127 ;
if ( V_128 == NULL ) {
F_48 ( V_55 , L_11 ) ;
return;
}
V_126 [ V_132 ++ ] = ( T_1 ) ( V_128 -> V_133 & 0xFF ) ;
V_126 [ V_132 ++ ] = ( T_1 ) ( ( V_128 -> V_133 >> 8 ) & 0xFF ) ;
if ( V_134 == V_135 ) {
V_78 = V_7 ;
V_126 [ V_132 ++ ] = ( T_1 ) V_78 ;
F_3 ( V_130 , V_126 + V_132 ) ;
V_132 += V_78 ;
}
* V_127 = V_132 ;
}
void F_54 ( char * V_126 , T_7 * V_127 ,
T_11 * V_128 , T_1 * V_130 , T_7 V_141 )
{
T_2 V_78 = 0 ;
T_2 V_142 = 0 ;
T_7 V_132 = * V_127 ;
T_1 V_143 = 0 ;
if ( V_128 == NULL ) {
F_48 ( V_55 , L_12 ) ;
return;
}
V_126 [ V_132 ++ ] = ( T_1 ) ( V_128 -> V_133 & 0xFF ) ;
V_126 [ V_132 ++ ] = ( T_1 ) ( ( V_128 -> V_133 >> 8 ) & 0xFF ) ;
if ( V_134 == V_135 ) {
V_78 = ( T_2 ) V_141 ;
V_126 [ V_132 ++ ] = ( T_1 ) ( V_78 & 0xFF ) ;
V_126 [ V_132 ++ ] = ( T_1 ) ( ( V_78 >> 8 ) & 0xFF ) ;
for ( V_142 = 0 ; V_142 < V_78 ; V_142 ++ )
V_126 [ V_132 ++ ] = V_130 [ V_142 ] ;
for ( V_142 = 0 ; V_142 < V_78 ; V_142 ++ )
V_143 += V_126 [ V_144 + V_142 + 4 ] ;
V_126 [ V_132 ++ ] = V_143 ;
}
* V_127 = V_132 ;
}
T_7 F_55 ( T_1 * V_145 ,
T_2 V_133 ,
T_2 V_146 ,
bool V_147 ,
T_3 V_13 ,
T_11 * V_148 )
{
T_3 V_149 = 0 ;
T_3 V_142 = 0 ;
T_1 V_150 = 0 ;
T_2 V_151 = 0 ;
T_3 V_152 = 0 ;
T_1 V_153 [ 256 ] = { 0 } ;
T_4 V_154 = V_30 ;
if ( V_147 ) {
V_154 = F_7 ( V_155 ) ;
} else {
V_154 = V_156 [ V_13 ] . V_154 ;
}
switch ( V_154 ) {
case V_25 :
V_150 = V_145 [ V_142 ] ;
* ( V_148 -> V_129 ) = V_150 ;
break;
case V_26 :
{
T_2 * V_136 = ( T_2 * ) ( V_148 -> V_129 ) ;
V_151 = F_39 ( V_145 [ V_142 ] , V_145 [ V_142 + 1 ] ) ;
* V_136 = V_151 ;
break;
}
case V_27 :
{
T_3 * V_138 = ( T_3 * ) ( V_148 -> V_129 ) ;
V_152 = F_56 (
F_39 ( V_145 [ V_142 ] , V_145 [ V_142 + 1 ] ) ,
F_39 ( V_145 [ V_142 + 2 ] , V_145 [ V_142 + 3 ] )
) ;
* V_138 = V_152 ;
break;
}
case V_28 :
F_16 ( V_153 , V_145 + V_142 , V_146 ) ;
if ( V_147 ) {
} else {
}
if ( V_148 -> V_141 >= V_146 ) {
F_16 ( V_148 -> V_129 , V_153 , V_146 ) ;
V_148 -> V_141 = V_146 ;
} else {
F_29 ( L_13 ) ;
V_149 = - 2 ;
}
break;
case V_20 :
F_4 ( V_153 , V_145 + V_142 ) ;
F_57 ( V_148 -> V_129 , V_153 , F_58 ( V_153 ) ) ;
V_148 -> V_129 [ F_58 ( V_153 ) ] = '\0' ;
if ( V_147 ) {
} else {
}
break;
case V_24 :
V_152 = F_56 (
F_39 ( V_145 [ V_142 ] , V_145 [ V_142 + 1 ] ) ,
F_39 ( V_145 [ V_142 + 2 ] , V_145 [ V_142 + 3 ] )
) ;
F_6 ( V_153 , V_152 ) ;
if ( V_147 ) {
} else {
}
break;
case V_29 :
if ( V_148 -> V_141 >= V_146 ) {
F_16 ( V_148 -> V_129 , V_145 + V_142 , V_146 ) ;
V_148 -> V_141 = V_146 ;
} else {
F_29 ( L_14 , V_149 ) ;
V_149 = - 2 ;
}
break;
default:
F_29 ( L_15 , V_149 ) ;
V_149 = - 2 ;
break;
}
return V_149 ;
}
T_7 F_59 ( T_1 * V_145 , T_11 * V_157 )
{
T_2 V_158 = 0 ;
T_2 V_133 = 0 ;
T_2 V_146 = 0 ;
T_4 V_154 = V_30 ;
bool V_159 = false ;
T_3 V_13 = 0 ;
T_3 V_142 = 0 ;
T_3 V_160 = 0 ;
if ( V_161 != V_145 [ 0 ] ) {
F_60 ( V_55 , L_4 ) ;
return - 1 ;
}
V_158 = F_39 ( V_145 [ 2 ] , V_145 [ 3 ] ) ;
V_162 = V_158 ;
for ( V_142 = V_144 ; V_142 < V_158 ; ) {
V_133 = F_39 ( V_145 [ V_142 ] , V_145 [ V_142 + 1 ] ) ;
V_146 = V_145 [ V_142 + 2 ] ;
V_154 = F_7 ( V_133 ) ;
if ( V_29 == V_154 ) {
V_146 |= ( ( T_2 ) V_145 [ V_142 + 3 ] << 8 ) & 0xFF00 ;
V_142 ++ ;
}
V_142 += 3 ;
if ( ( V_133 == V_155 ) && ( ! V_159 ) ) {
V_159 = true ;
if ( - 2 == F_55 ( & V_145 [ V_142 ] , V_133 , V_146 , true , 0 , & V_157 [ V_160 ] ) ) {
return - 2 ;
}
V_160 ++ ;
} else {
for ( V_13 = 0 ; V_13 < V_163 ; V_13 ++ ) {
if ( V_156 [ V_13 ] . V_133 == V_133 ) {
if ( - 2 == F_55 ( & V_145 [ V_142 ] , V_133 , V_146 , false , V_13 ,
& V_157 [ V_160 ] ) ) {
return - 2 ;
}
V_160 ++ ;
}
}
}
V_142 += V_146 ;
if ( V_29 == V_154 ) {
V_142 ++ ;
}
}
return 0 ;
}
T_7 F_61 ( T_1 * V_164 )
{
T_7 V_53 = V_83 ;
T_2 V_158 = 0 ;
T_2 V_165 = ( T_2 ) V_80 ;
if ( V_161 != V_164 [ 0 ] ) {
F_29 ( L_4 ) ;
return V_83 ;
}
V_158 = F_39 ( V_164 [ 2 ] , V_164 [ 3 ] ) ;
V_165 = F_39 ( V_164 [ 4 ] , V_164 [ 5 ] ) ;
if ( ( V_165 == V_166 ) &&
( V_164 [ 6 ] == 1 ) &&
( V_164 [ 7 ] == V_167 ) ) {
V_53 = V_167 ;
return V_53 ;
}
V_53 = V_83 ;
return V_53 ;
}
T_7 F_62 ( char * V_168 , T_7 * V_169 )
{
T_7 V_53 = V_54 ;
T_2 V_78 = ( T_2 ) ( * V_169 ) ;
T_2 V_170 = 0 ;
if ( V_134 == V_135 )
V_168 [ V_170 ++ ] = V_171 ;
else
V_168 [ V_170 ++ ] = V_172 ;
V_168 [ V_170 ++ ] = V_173 ++ ;
V_168 [ V_170 ++ ] = ( T_1 ) ( V_78 & 0xFF ) ;
V_168 [ V_170 ++ ] = ( T_1 ) ( ( V_78 >> 8 ) & 0xFF ) ;
* V_169 = V_78 ;
return V_53 ;
}
T_7 F_63 ( V_59 * V_174 , T_7 * V_169 ,
T_11 * V_175 , T_3 V_176 )
{
T_7 V_53 = V_54 ;
T_3 V_177 = 0 ;
* V_169 = V_144 ;
for ( V_177 = 0 ; V_177 < V_176 ; V_177 ++ ) {
switch ( V_175 [ V_177 ] . V_154 ) {
case V_25 :
F_47 ( V_174 , V_169 , & V_175 [ V_177 ] ,
V_175 [ V_177 ] . V_129 ) ;
break;
case V_26 :
F_49 ( V_174 , V_169 , & V_175 [ V_177 ] ,
V_175 [ V_177 ] . V_129 ) ;
break;
case V_27 :
F_50 ( V_174 , V_169 , & V_175 [ V_177 ] ,
V_175 [ V_177 ] . V_129 ) ;
break;
case V_28 :
F_52 ( V_174 , V_169 , & V_175 [ V_177 ] ,
V_175 [ V_177 ] . V_129 , V_175 [ V_177 ] . V_141 ) ;
break;
case V_24 :
F_51 ( V_174 , V_169 , & V_175 [ V_177 ] ,
V_175 [ V_177 ] . V_129 ) ;
break;
case V_29 :
F_54 ( V_174 , V_169 , & V_175 [ V_177 ] ,
V_175 [ V_177 ] . V_129 , V_175 [ V_177 ] . V_141 ) ;
break;
default:
F_29 ( L_16 ) ;
}
}
F_62 ( V_174 , V_169 ) ;
return V_53 ;
}
T_7 F_64 ( char * V_178 , T_7 V_179 , T_7 * V_180 ,
bool V_181 )
{
T_7 V_53 = V_54 ;
if ( V_63 . V_181 ) {
F_65 ( & V_57 ) ;
* V_180 = V_63 . V_182 ;
}
F_30 ( ( void * ) ( & V_63 ) , 0 , sizeof( V_64 ) ) ;
return V_53 ;
}
T_7 F_66 ( T_1 V_183 , T_11 * V_175 ,
T_3 V_176 , bool V_181 , T_3 V_184 )
{
T_7 V_53 = V_54 ;
T_7 V_185 = V_54 ;
T_7 V_186 = 0 ;
T_7 V_187 = 0 ;
F_65 ( & V_56 ) ;
V_134 = V_183 ;
F_30 ( ( void * ) V_58 , 0 , V_60 ) ;
if ( F_63 ( V_58 , & V_186 , V_175 , V_176 ) != V_54 ) {
V_53 = V_83 ;
goto V_188;
}
V_63 . V_178 = V_58 ;
V_63 . V_179 = V_60 ;
F_60 ( V_55 , L_17 , V_181 ) ;
V_63 . V_181 = V_181 ;
V_53 = F_67 ( V_58 , V_186 ) ;
if ( V_53 != V_54 ) {
goto V_188;
}
F_30 ( ( void * ) V_58 , 0 , V_60 ) ;
F_64 ( V_58 , V_60 , & V_187 , V_181 ) ;
if ( V_181 ) {
if ( V_134 == V_189 ) {
#if 1
V_185 = F_59 ( V_58 , V_175 ) ;
if ( V_185 != 0 ) {
V_53 = V_83 ;
goto V_188;
} else {
V_53 = V_54 ;
}
#endif
} else {
V_185 = F_61 ( V_58 ) ;
if ( V_185 != V_167 ) {
V_53 = V_83 ;
goto V_188;
} else {
V_53 = V_54 ;
}
}
}
V_188:
F_68 ( & V_56 ) ;
return V_53 ;
}
T_7 F_69 ( char * V_178 , T_7 V_190 )
{
T_7 V_53 = V_54 ;
if ( V_63 . V_181 ) {
if ( V_190 <= V_63 . V_179 ) {
F_16 ( V_63 . V_178 , V_178 , V_190 ) ;
V_63 . V_182 = V_190 ;
} else {
F_16 ( V_63 . V_178 , V_178 , V_63 . V_179 ) ;
V_63 . V_182 = V_63 . V_179 ;
F_29 ( L_18 ) ;
}
F_68 ( & V_57 ) ;
}
return V_53 ;
}
T_7 F_70 ( T_1 * V_191 , T_7 V_192 )
{
T_7 V_53 = V_54 ;
T_1 V_76 = 0 ;
V_76 = V_191 [ 0 ] ;
switch ( V_76 ) {
case 'R' :
F_69 ( V_191 , V_192 ) ;
break;
case 'N' :
F_60 ( V_55 , L_19 ) ;
F_71 ( V_191 , V_192 ) ;
break;
case 'I' :
F_72 ( V_191 , V_192 ) ;
break;
case 'S' :
F_73 ( V_191 , V_192 ) ;
break;
default:
F_29 ( L_20 ) ;
break;
}
return V_53 ;
}
T_7 F_74 ( void )
{
T_7 V_53 = V_54 ;
F_26 ( V_55 , L_21 ) ;
if ( V_58 != NULL ) {
F_42 ( V_58 ) ;
V_58 = NULL ;
}
return V_53 ;
}
T_7 F_66 ( T_1 V_183 , T_11 * V_175 ,
T_3 V_176 , bool V_181 , T_3 V_184 )
{
T_7 V_193 = 0 , V_194 = 0 ;
if ( V_195 == NULL ) {
F_26 ( V_55 , L_22 ) ;
return 1 ;
} else {
F_26 ( V_55 , L_23 ) ;
}
if ( V_195 -> V_196 == NULL ||
V_195 -> V_197 == NULL ) {
F_26 ( V_55 , L_24 ) ;
return 1 ;
} else {
F_26 ( V_55 , L_25 ) ;
}
if ( V_183 == V_189 ) {
for ( V_193 = 0 ; V_193 < V_176 ; V_193 ++ ) {
F_60 ( V_55 , L_26 , ! V_193 ,
( V_193 == V_176 - 1 ) ) ;
if ( ! V_195 -> V_197 ( ! V_193 ,
V_175 [ V_193 ] . V_133 ,
( V_193 == V_176 - 1 ) , V_184 ) ) {
V_194 = - 1 ;
F_75 ( L_27 ) ;
break;
}
}
V_193 = 0 ;
for ( V_193 = 0 ; V_193 < V_176 ; V_193 ++ ) {
V_175 [ V_193 ] . V_141 = V_195 -> V_198 (
V_175 [ V_193 ] . V_133 ,
V_175 [ V_193 ] . V_129 , V_175 [ V_193 ] . V_141 ) ;
}
} else if ( V_183 == V_135 ) {
for ( V_193 = 0 ; V_193 < V_176 ; V_193 ++ ) {
F_26 ( V_55 , L_28 , V_175 [ V_193 ] . V_133 ) ;
if ( ! V_195 -> V_196 ( ! V_193 ,
V_175 [ V_193 ] . V_133 , V_175 [ V_193 ] . V_129 ,
V_175 [ V_193 ] . V_141 ,
( V_193 == V_176 - 1 ) , V_184 ) ) {
V_194 = - 1 ;
F_75 ( L_29 ) ;
break;
}
}
}
return V_194 ;
}
