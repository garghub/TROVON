short F_1 ( const struct V_1 * V_2 )
{
return ( V_2 -> V_3 > 0 ) || ( V_2 -> V_4 > 4 ) ;
}
short F_2 ( const struct V_1 * V_2 )
{
return V_2 -> V_5 & V_6 ;
}
unsigned int F_3 ( struct V_7 * V_8 )
{
unsigned int V_9 = 0 ;
if ( V_8 -> V_10 & V_11 )
V_9 = V_12 + 2 ;
if ( V_8 -> V_10 & V_13 )
V_9 += V_14 + 2 ;
return V_9 ;
}
void F_4 ( struct V_7 * V_8 , T_1 * * V_15 )
{
T_1 * V_16 = * V_15 ;
if ( V_8 -> V_10 & V_11 ) {
* V_16 ++ = V_17 ;
* V_16 ++ = 4 ;
* V_16 ++ = V_18 | V_19 ;
* V_16 ++ = V_18 | V_20 ;
* V_16 ++ = V_18 | V_21 ;
* V_16 ++ = V_18 | V_22 ;
}
* V_15 = V_16 ;
}
void F_5 ( struct V_7 * V_8 , T_1 * * V_15 )
{
T_1 * V_16 = * V_15 ;
if ( V_8 -> V_10 & V_13 ) {
* V_16 ++ = V_23 ;
* V_16 ++ = 8 ;
* V_16 ++ = V_18 | V_24 ;
* V_16 ++ = V_18 | V_25 ;
* V_16 ++ = V_18 | V_26 ;
* V_16 ++ = V_18 | V_27 ;
* V_16 ++ = V_18 | V_28 ;
* V_16 ++ = V_18 | V_29 ;
* V_16 ++ = V_18 | V_30 ;
* V_16 ++ = V_18 | V_31 ;
}
* V_15 = V_16 ;
}
void F_6 ( struct V_7 * V_8 , T_1 * * V_15 ) {
T_1 * V_16 = * V_15 ;
* V_16 ++ = V_32 ;
* V_16 ++ = 7 ;
* V_16 ++ = 0x00 ;
* V_16 ++ = 0x50 ;
* V_16 ++ = 0xf2 ;
* V_16 ++ = 0x02 ;
* V_16 ++ = 0x00 ;
* V_16 ++ = 0x01 ;
#ifdef F_7
if( V_8 -> V_33 . V_34 & 0x80 ) {
* V_16 ++ = 0x0f | V_35 ;
} else {
* V_16 ++ = V_35 ;
}
#else
* V_16 ++ = V_35 ;
#endif
* V_15 = V_16 ;
}
void F_8 ( struct V_7 * V_8 , T_1 * * V_15 ) {
T_1 * V_16 = * V_15 ;
* V_16 ++ = V_32 ;
* V_16 ++ = 7 ;
* V_16 ++ = 0x00 ;
* V_16 ++ = 0xe0 ;
* V_16 ++ = 0x4c ;
* V_16 ++ = 0x01 ;
* V_16 ++ = 0x02 ;
* V_16 ++ = 0x11 ;
* V_16 ++ = 0x00 ;
* V_15 = V_16 ;
F_9 ( V_36 L_1 ) ;
}
void F_10 ( struct V_7 * V_8 , struct V_37 * V_38 )
{
int V_39 ;
V_39 = ( V_8 -> V_40 + 1 ) % V_41 ;
V_8 -> V_40 = V_39 ;
V_8 -> V_42 [ V_39 ] = V_38 ;
}
struct V_37 * F_11 ( struct V_7 * V_8 )
{
struct V_37 * V_43 ;
if( V_8 -> V_44 == V_8 -> V_40 )
return NULL ;
V_43 = V_8 -> V_42 [ V_8 -> V_44 ] ;
V_8 -> V_44 =
( V_8 -> V_44 + 1 ) % V_41 ;
return V_43 ;
}
void F_12 ( struct V_7 * V_8 )
{
V_8 -> V_44 = V_8 -> V_40 = 0 ;
}
inline void F_13 ( struct V_37 * V_38 , struct V_7 * V_8 )
{
unsigned long V_45 ;
short V_46 = V_8 -> V_47 & V_48 ;
struct V_49 * V_50 =
(struct V_49 * ) V_38 -> V_51 ;
F_14 ( & V_8 -> V_52 , V_45 ) ;
F_15 ( V_8 , 0 ) ;
if( V_46 ) {
if( V_8 -> V_53 ) {
F_10 ( V_8 , V_38 ) ;
} else{
V_50 -> V_54 = F_16 ( V_8 -> V_54 [ 0 ] << 4 ) ;
if ( V_8 -> V_54 [ 0 ] == 0xFFF )
V_8 -> V_54 [ 0 ] = 0 ;
else
V_8 -> V_54 [ 0 ] ++ ;
V_8 -> V_55 -> V_56 = V_57 ;
V_8 -> V_58 ( V_38 , V_8 -> V_55 , V_8 -> V_59 ) ;
}
F_17 ( & V_8 -> V_52 , V_45 ) ;
} else{
F_17 ( & V_8 -> V_52 , V_45 ) ;
F_14 ( & V_8 -> V_60 , V_45 ) ;
V_50 -> V_54 = F_16 ( V_8 -> V_54 [ 0 ] << 4 ) ;
if ( V_8 -> V_54 [ 0 ] == 0xFFF )
V_8 -> V_54 [ 0 ] = 0 ;
else
V_8 -> V_54 [ 0 ] ++ ;
V_8 -> V_55 -> V_56 = V_57 ;
V_8 -> V_61 ( V_38 , V_8 -> V_55 ) ;
F_17 ( & V_8 -> V_60 , V_45 ) ;
}
}
inline void F_18 ( struct V_37 * V_38 , struct V_7 * V_8 )
{
short V_46 = V_8 -> V_47 & V_48 ;
struct V_49 * V_50 =
(struct V_49 * ) V_38 -> V_51 ;
if( V_46 ) {
V_50 -> V_54 = F_16 ( V_8 -> V_54 [ 0 ] << 4 ) ;
if ( V_8 -> V_54 [ 0 ] == 0xFFF )
V_8 -> V_54 [ 0 ] = 0 ;
else
V_8 -> V_54 [ 0 ] ++ ;
V_8 -> V_55 -> V_56 = V_57 ;
V_8 -> V_58 ( V_38 , V_8 -> V_55 , V_8 -> V_59 ) ;
} else{
V_50 -> V_54 = F_16 ( V_8 -> V_54 [ 0 ] << 4 ) ;
if ( V_8 -> V_54 [ 0 ] == 0xFFF )
V_8 -> V_54 [ 0 ] = 0 ;
else
V_8 -> V_54 [ 0 ] ++ ;
V_8 -> V_55 -> V_56 = V_57 ;
V_8 -> V_61 ( V_38 , V_8 -> V_55 ) ;
}
}
inline struct V_37 * F_19 (
struct V_1 * V_62 ,
struct V_7 * V_8 ,
T_1 V_63 )
{
struct V_37 * V_38 ;
struct V_64 * V_65 ;
V_38 = F_20 ( sizeof( struct V_64 ) ) ;
if ( ! V_38 )
return NULL ;
V_65 = (struct V_64 * ) F_21 ( V_38 , sizeof( struct V_64 ) ) ;
V_65 -> V_50 . V_66 = F_16 ( V_67 ) ;
V_65 -> V_50 . V_68 = 0 ;
memcpy ( V_65 -> V_50 . V_69 , V_62 -> V_70 , V_71 ) ;
memcpy ( V_65 -> V_50 . V_72 , V_8 -> V_55 -> V_73 , V_71 ) ;
memcpy ( V_65 -> V_50 . V_74 , V_62 -> V_70 , V_71 ) ;
V_65 -> V_75 = V_63 ;
return V_38 ;
}
void
F_22 (
struct V_7 * V_8 ,
T_1 * V_76 ,
T_1 V_63
)
{
struct V_1 * V_62 = & V_8 -> V_33 ;
struct V_37 * V_38 ;
V_38 = F_19 ( V_62 , V_8 , V_63 ) ;
if ( V_38 ) {
F_13 ( V_38 , V_8 ) ;
}
}
inline struct V_37 * F_23 ( struct V_7 * V_8 )
{
unsigned int V_77 , V_9 ;
T_1 * V_16 ;
struct V_37 * V_38 ;
struct V_78 * V_79 ;
V_77 = V_8 -> V_33 . V_80 ;
V_9 = F_3 ( V_8 ) ;
V_38 = F_20 ( sizeof( struct V_78 ) +
2 + V_77 + V_9 ) ;
if ( ! V_38 )
return NULL ;
V_79 = (struct V_78 * ) F_21 ( V_38 , sizeof( struct V_78 ) ) ;
V_79 -> V_50 . V_81 = F_16 ( V_82 ) ;
V_79 -> V_50 . V_68 = 0 ;
memset ( V_79 -> V_50 . V_69 , 0xff , V_71 ) ;
memcpy ( V_79 -> V_50 . V_72 , V_8 -> V_55 -> V_73 , V_71 ) ;
memset ( V_79 -> V_50 . V_74 , 0xff , V_71 ) ;
V_16 = ( T_1 * ) F_21 ( V_38 , V_77 + 2 + V_9 ) ;
* V_16 ++ = V_83 ;
* V_16 ++ = V_77 ;
memcpy ( V_16 , V_8 -> V_33 . V_84 , V_77 ) ;
V_16 += V_77 ;
F_4 ( V_8 , & V_16 ) ;
F_5 ( V_8 , & V_16 ) ;
return V_38 ;
}
void F_24 ( struct V_7 * V_8 )
{
struct V_37 * V_38 ;
V_38 = F_25 ( V_8 ) ;
if ( V_38 ) {
F_13 ( V_38 , V_8 ) ;
V_8 -> V_85 . V_86 ++ ;
F_26 ( V_38 ) ;
}
V_8 -> V_87 . V_88 = V_57 +
( F_27 ( V_8 -> V_33 . V_89 - 5 ) ) ;
if( V_8 -> V_90 )
F_28 ( & V_8 -> V_87 ) ;
}
void F_29 ( struct V_7 * V_8 )
{
struct V_37 * V_38 ;
V_38 = F_25 ( V_8 ) ;
if ( V_38 ) {
F_13 ( V_38 , V_8 ) ;
V_8 -> V_85 . V_86 ++ ;
F_26 ( V_38 ) ;
}
V_8 -> V_87 . V_88 = V_57 +
( F_27 ( V_8 -> V_33 . V_89 - 5 ) ) ;
if( V_8 -> V_90 )
F_28 ( & V_8 -> V_87 ) ;
}
void F_30 ( unsigned long V_91 )
{
struct V_7 * V_8 =
(struct V_7 * ) V_91 ;
unsigned long V_45 ;
F_14 ( & V_8 -> V_92 , V_45 ) ;
F_29 ( V_8 ) ;
F_17 ( & V_8 -> V_92 , V_45 ) ;
}
void F_31 ( struct V_7 * V_8 )
{
struct V_37 * V_38 ;
V_38 = F_23 ( V_8 ) ;
if ( V_38 ) {
F_13 ( V_38 , V_8 ) ;
V_8 -> V_85 . V_93 ++ ;
}
}
void F_32 ( struct V_7 * V_8 )
{
if ( V_8 -> V_94 && ( V_8 -> V_47 & V_95 ) ) {
F_31 ( V_8 ) ;
F_31 ( V_8 ) ;
}
}
void F_33 ( struct V_7 * V_8 )
{
short V_96 = 0 ;
T_1 V_97 [ V_98 + 1 ] ;
memcpy ( V_97 , F_34 ( V_8 ) -> V_97 , V_98 + 1 ) ;
F_35 ( & V_8 -> V_99 ) ;
while( 1 )
{
do{
V_96 ++ ;
if ( V_96 > V_98 )
goto V_100;
}while( ! V_97 [ V_96 ] );
if ( V_8 -> V_101 == V_102 )
goto V_100;
V_8 -> V_103 ( V_8 -> V_55 , V_96 ) ;
if( V_97 [ V_96 ] == 1 )
{
F_32 ( V_8 ) ;
}
if ( V_8 -> V_104 )
goto V_100;
F_36 ( V_105 ) ;
}
V_100:
V_8 -> V_104 = 0 ;
F_37 ( & V_8 -> V_99 ) ;
if( F_38 ( V_8 ) )
F_39 ( V_8 ) ;
}
void F_40 ( struct V_7 * V_8 )
{
int V_96 ;
unsigned int V_106 = 0 ;
T_1 V_97 [ V_98 + 1 ] ;
memcpy ( V_97 , F_34 ( V_8 ) -> V_97 , V_98 + 1 ) ;
F_35 ( & V_8 -> V_99 ) ;
V_96 = V_8 -> V_33 . V_107 ;
while( 1 )
{
if ( V_8 -> V_101 == V_102 )
{
goto V_100;
}
if( V_97 [ V_8 -> V_33 . V_107 ] > 0 )
{
V_8 -> V_103 ( V_8 -> V_55 , V_8 -> V_33 . V_107 ) ;
}
if( V_97 [ V_8 -> V_33 . V_107 ] == 1 )
{
F_32 ( V_8 ) ;
}
F_36 ( V_105 ) ;
do{
if ( V_106 ++ >= V_98 )
goto V_100;
V_8 -> V_33 . V_107 = ( V_8 -> V_33 . V_107 + 1 ) % V_98 ;
}while( ! V_97 [ V_8 -> V_33 . V_107 ] );
}
V_100:
V_8 -> V_108 = false ;
F_37 ( & V_8 -> V_99 ) ;
if( F_38 ( V_8 ) )
F_39 ( V_8 ) ;
}
void F_41 ( struct V_109 * V_110 )
{
struct V_111 * V_112 = F_42 ( V_110 ) ;
struct V_7 * V_8 = F_43 ( V_112 , struct V_7 , V_113 ) ;
static short V_114 = 0 ;
T_1 V_97 [ V_98 + 1 ] ;
memcpy ( V_97 , F_34 ( V_8 ) -> V_97 , V_98 + 1 ) ;
F_35 ( & V_8 -> V_99 ) ;
do{
V_8 -> V_33 . V_107 =
( V_8 -> V_33 . V_107 + 1 ) % V_98 ;
if ( V_114 ++ > V_98 )
goto V_100;
}while( ! V_97 [ V_8 -> V_33 . V_107 ] );
if ( V_8 -> V_115 == 0 )
{
F_9 ( L_2 ) ;
goto V_100;
}
V_8 -> V_103 ( V_8 -> V_55 , V_8 -> V_33 . V_107 ) ;
if( V_97 [ V_8 -> V_33 . V_107 ] == 1 )
F_32 ( V_8 ) ;
F_44 ( V_8 -> V_116 , & V_8 -> V_113 , V_105 ) ;
F_37 ( & V_8 -> V_99 ) ;
return;
V_100:
V_8 -> V_108 = false ;
V_114 = 0 ;
V_8 -> V_115 = 0 ;
F_37 ( & V_8 -> V_99 ) ;
if( F_38 ( V_8 ) )
F_39 ( V_8 ) ;
return;
}
void F_45 ( struct V_7 * V_8 )
{
unsigned long V_45 ;
F_14 ( & V_8 -> V_92 , V_45 ) ;
V_8 -> V_90 = 1 ;
F_29 ( V_8 ) ;
F_17 ( & V_8 -> V_92 , V_45 ) ;
}
void F_46 ( struct V_7 * V_8 )
{
unsigned long V_45 ;
F_14 ( & V_8 -> V_92 , V_45 ) ;
V_8 -> V_90 = 0 ;
F_47 ( & V_8 -> V_87 ) ;
F_17 ( & V_8 -> V_92 , V_45 ) ;
}
void F_48 ( struct V_7 * V_8 )
{
if( V_8 -> V_117 )
V_8 -> V_117 ( V_8 -> V_55 ) ;
if ( V_8 -> V_47 & V_118 )
F_46 ( V_8 ) ;
}
void F_49 ( struct V_7 * V_8 )
{
if( V_8 -> V_119 )
V_8 -> V_119 ( V_8 -> V_55 ) ;
if( V_8 -> V_47 & V_118 )
F_45 ( V_8 ) ;
}
void F_50 ( struct V_7 * V_8 )
{
F_35 ( & V_8 -> V_99 ) ;
if ( V_8 -> V_115 == 1 ) {
V_8 -> V_115 = 0 ;
F_51 ( & V_8 -> V_113 ) ;
}
F_37 ( & V_8 -> V_99 ) ;
}
void F_52 ( struct V_7 * V_8 )
{
if ( V_8 -> V_47 & V_120 )
F_50 ( V_8 ) ;
else
V_8 -> V_121 ( V_8 -> V_55 ) ;
}
void F_53 ( struct V_7 * V_8 )
{
if( F_38 ( V_8 ) )
{
if( F_54 ( V_8 ) )
{
F_55 ( V_8 ) ;
}
}
if ( V_8 -> V_47 & V_120 ) {
if ( V_8 -> V_115 == 0 )
{
V_8 -> V_115 = 1 ;
#if 1
F_44 ( V_8 -> V_116 , & V_8 -> V_113 , 0 ) ;
#endif
}
} else
V_8 -> V_122 ( V_8 -> V_55 ) ;
}
void F_56 ( struct V_7 * V_8 )
{
if( F_38 ( V_8 ) )
{
if( F_54 ( V_8 ) )
{
F_55 ( V_8 ) ;
}
}
V_8 -> V_104 = 0 ;
if ( V_8 -> V_47 & V_120 )
F_33 ( V_8 ) ;
else
V_8 -> V_123 ( V_8 -> V_55 ) ;
}
inline struct V_37 * F_57 ( struct V_1 * V_62 ,
struct V_7 * V_8 , int V_124 )
{
struct V_37 * V_38 ;
struct V_125 * V_126 ;
V_38 = F_20 ( sizeof( struct V_125 ) + V_124 ) ;
if ( ! V_38 ) return NULL ;
V_126 = (struct V_125 * )
F_21 ( V_38 , sizeof( struct V_125 ) ) ;
V_126 -> V_50 . V_81 = V_127 ;
if ( V_124 ) V_126 -> V_50 . V_81 |= V_128 ;
V_126 -> V_50 . V_68 = 0x013a ;
memcpy ( V_126 -> V_50 . V_69 , V_62 -> V_70 , V_71 ) ;
memcpy ( V_126 -> V_50 . V_72 , V_8 -> V_55 -> V_73 , V_71 ) ;
memcpy ( V_126 -> V_50 . V_74 , V_62 -> V_70 , V_71 ) ;
V_126 -> V_129 = V_8 -> V_130 ? V_131 : V_132 ;
V_126 -> V_133 = F_16 ( V_8 -> V_134 ) ;
V_8 -> V_134 ++ ;
V_126 -> V_135 = F_16 ( V_136 ) ;
return V_38 ;
}
static struct V_37 * F_58 ( struct V_7 * V_8 , T_1 * V_137 )
{
T_1 * V_16 ;
int V_138 ;
struct V_139 * V_140 ;
struct V_37 * V_38 ;
int V_141 ;
int V_142 , V_143 ;
struct V_144 * V_145 ;
char * V_84 = V_8 -> V_33 . V_84 ;
int V_80 = V_8 -> V_33 . V_80 ;
int V_9 = V_8 -> V_33 . V_4 + 2 ;
int V_146 = V_8 -> V_33 . V_3 ;
int V_147 = V_8 -> V_147 ;
if( V_146 > 0 ) V_146 += 2 ;
if( V_8 -> V_33 . V_5 & V_148 )
V_142 = 4 ;
else
V_142 = 0 ;
if( F_1 ( & V_8 -> V_33 ) )
V_143 = 3 ;
else
V_143 = 0 ;
V_138 = sizeof( struct V_139 ) +
V_80
+ 3
+ V_9
+ V_146
+ V_142
+ V_147
+ V_143 ;
V_38 = F_20 ( V_138 ) ;
if ( ! V_38 )
return NULL ;
V_140 = (struct V_139 * ) F_21 ( V_38 , V_138 ) ;
memcpy ( V_140 -> V_50 . V_69 , V_137 , V_71 ) ;
memcpy ( V_140 -> V_50 . V_72 , V_8 -> V_55 -> V_73 , V_71 ) ;
memcpy ( V_140 -> V_50 . V_74 , V_8 -> V_33 . V_70 , V_71 ) ;
V_140 -> V_50 . V_68 = 0 ;
V_140 -> V_89 =
F_16 ( V_8 -> V_33 . V_89 ) ;
V_140 -> V_5 =
F_16 ( V_8 -> V_33 . V_5 & V_148 ) ;
if( V_8 -> V_149 && ( V_8 -> V_33 . V_5 & V_6 ) )
V_140 -> V_5 |= F_16 ( V_6 ) ;
V_145 = V_8 -> V_145 [ V_8 -> V_150 ] ;
V_141 = V_8 -> V_151 && V_145 && V_145 -> V_152 &&
( ( 0 == strcmp ( V_145 -> V_152 -> V_153 , L_3 ) ) || V_147 ) ;
if ( V_141 )
V_140 -> V_5 |= F_16 ( V_154 ) ;
V_140 -> V_50 . V_81 = F_16 ( V_155 ) ;
V_140 -> V_156 . V_157 = V_83 ;
V_140 -> V_156 . V_77 = V_80 ;
V_16 = ( T_1 * ) V_140 -> V_156 . V_51 ;
memcpy ( V_16 , V_84 , V_80 ) ;
V_16 += V_80 ;
* ( V_16 ++ ) = V_17 ;
* ( V_16 ++ ) = V_9 - 2 ;
memcpy ( V_16 , V_8 -> V_33 . V_158 , V_9 - 2 ) ;
V_16 += V_9 - 2 ;
* ( V_16 ++ ) = V_159 ;
* ( V_16 ++ ) = 1 ;
* ( V_16 ++ ) = V_8 -> V_33 . V_107 ;
if( V_142 ) {
* ( V_16 ++ ) = V_160 ;
* ( V_16 ++ ) = 2 ;
* ( ( V_161 * ) ( V_16 ) ) = F_16 ( V_8 -> V_33 . V_162 ) ;
V_16 += 2 ;
}
if( V_143 ) {
* ( V_16 ++ ) = V_163 ;
* ( V_16 ++ ) = 1 ;
* ( V_16 ++ ) = 0 ;
}
if( V_146 ) {
* ( V_16 ++ ) = V_23 ;
* ( V_16 ++ ) = V_146 - 2 ;
memcpy ( V_16 , V_8 -> V_33 . V_164 , V_146 - 2 ) ;
V_16 += V_146 - 2 ;
}
if ( V_147 )
{
if ( V_8 -> V_165 == V_166 )
{
memcpy ( & V_8 -> V_167 [ 14 ] , & V_8 -> V_167 [ 8 ] , 4 ) ;
}
memcpy ( V_16 , V_8 -> V_167 , V_8 -> V_147 ) ;
}
V_38 -> V_55 = V_8 -> V_55 ;
return V_38 ;
}
struct V_37 * F_59 ( struct V_7 * V_8 , T_1 * V_137 )
{
struct V_37 * V_38 ;
T_1 * V_16 ;
struct V_144 * V_145 ;
struct V_168 * V_169 ;
short V_141 ;
unsigned int V_9 = F_3 ( V_8 ) ;
int V_77 = sizeof( struct V_168 ) + V_9 ;
V_38 = F_20 ( V_77 ) ;
if ( ! V_38 )
return NULL ;
V_169 = (struct V_168 * )
F_21 ( V_38 , sizeof( struct V_168 ) ) ;
V_169 -> V_50 . V_66 = F_16 ( V_170 ) ;
memcpy ( V_169 -> V_50 . V_69 , V_137 , V_71 ) ;
memcpy ( V_169 -> V_50 . V_74 , V_8 -> V_55 -> V_73 , V_71 ) ;
memcpy ( V_169 -> V_50 . V_72 , V_8 -> V_55 -> V_73 , V_71 ) ;
V_169 -> V_5 = F_16 ( V_8 -> V_165 == V_171 ?
V_172 : V_148 ) ;
if( V_8 -> V_149 )
V_169 -> V_5 |= F_16 ( V_6 ) ;
if ( V_8 -> V_151 )
V_145 = V_8 -> V_145 [ V_8 -> V_150 ] ;
else V_145 = NULL ;
V_141 = ( V_145 && V_145 -> V_152 ) ;
if ( V_141 )
V_169 -> V_5 |= F_16 ( V_154 ) ;
V_169 -> V_135 = 0 ;
V_169 -> V_173 = F_16 ( V_8 -> V_174 ) ;
if ( V_8 -> V_174 == 0x2007 ) V_8 -> V_174 = 0 ;
else V_8 -> V_174 ++ ;
V_16 = ( T_1 * ) F_21 ( V_38 , V_9 ) ;
F_4 ( V_8 , & V_16 ) ;
F_5 ( V_8 , & V_16 ) ;
return V_38 ;
}
struct V_37 * F_60 ( struct V_7 * V_8 , int V_135 , T_1 * V_137 )
{
struct V_37 * V_38 ;
struct V_125 * V_126 ;
V_38 = F_20 ( sizeof( struct V_125 ) + 1 ) ;
if ( ! V_38 )
return NULL ;
V_38 -> V_77 = sizeof( struct V_125 ) ;
V_126 = (struct V_125 * ) V_38 -> V_51 ;
V_126 -> V_135 = F_16 ( V_135 ) ;
V_126 -> V_133 = F_16 ( 2 ) ;
V_126 -> V_129 = F_16 ( V_131 ) ;
memcpy ( V_126 -> V_50 . V_74 , V_8 -> V_55 -> V_73 , V_71 ) ;
memcpy ( V_126 -> V_50 . V_72 , V_8 -> V_55 -> V_73 , V_71 ) ;
memcpy ( V_126 -> V_50 . V_69 , V_137 , V_71 ) ;
V_126 -> V_50 . V_81 = F_16 ( V_127 ) ;
return V_38 ;
}
struct V_37 * F_61 ( struct V_7 * V_8 , short V_175 )
{
struct V_37 * V_38 ;
struct V_49 * V_176 ;
V_38 = F_20 ( sizeof( struct V_49 ) ) ;
if ( ! V_38 )
return NULL ;
V_176 = (struct V_49 * ) F_21 ( V_38 , sizeof( struct V_49 ) ) ;
memcpy ( V_176 -> V_69 , V_8 -> V_33 . V_70 , V_71 ) ;
memcpy ( V_176 -> V_72 , V_8 -> V_55 -> V_73 , V_71 ) ;
memcpy ( V_176 -> V_74 , V_8 -> V_33 . V_70 , V_71 ) ;
V_176 -> V_66 = F_16 ( V_177 |
V_178 | V_179 |
( V_175 ? V_180 : 0 ) ) ;
return V_38 ;
}
void F_62 ( struct V_7 * V_8 , T_1 * V_137 )
{
struct V_37 * V_181 = F_59 ( V_8 , V_137 ) ;
if ( V_181 ) {
F_13 ( V_181 , V_8 ) ;
F_26 ( V_181 ) ;
}
}
void F_63 ( struct V_7 * V_8 , int V_182 , T_1 * V_137 )
{
struct V_37 * V_181 = F_60 ( V_8 , V_182 , V_137 ) ;
if ( V_181 ) {
F_13 ( V_181 , V_8 ) ;
F_26 ( V_181 ) ;
}
}
void F_64 ( struct V_7 * V_8 , T_1 * V_137 )
{
struct V_37 * V_181 = F_58 ( V_8 , V_137 ) ;
if ( V_181 ) {
F_13 ( V_181 , V_8 ) ;
F_26 ( V_181 ) ;
}
}
inline struct V_37 * F_65 ( struct V_1 * V_62 , struct V_7 * V_8 )
{
struct V_37 * V_38 ;
struct V_183 * V_176 ;
T_1 * V_16 ;
unsigned int V_184 = V_62 -> V_147 ;
#if 1
unsigned int V_185 = V_62 -> V_186 ;
#else
unsigned int V_185 = V_62 -> V_186 - 4 ;
#endif
unsigned int V_9 = F_3 ( V_8 ) ;
unsigned int V_187 = V_62 -> V_188 ? 9 : 0 ;
unsigned int V_189 = V_62 -> V_190 ? 9 : 0 ;
T_1 V_191 = V_8 -> V_192 & 0xff ;
int V_77 = 0 ;
if( V_8 -> V_193 ) {
if ( V_194 == V_191 ) {
V_185 = 0 ;
} else if ( V_195 == V_191 ) {
V_184 = 0 ;
}
}
V_77 = sizeof( struct V_183 ) +
+ V_62 -> V_80
+ V_9
+ V_184
+ V_185
+ V_187
+ V_189 ;
V_38 = F_20 ( V_77 ) ;
if ( ! V_38 )
return NULL ;
V_176 = (struct V_183 * )
F_21 ( V_38 , sizeof( struct V_183 ) ) ;
V_176 -> V_50 . V_66 = V_196 ;
V_176 -> V_50 . V_68 = 37 ;
memcpy ( V_176 -> V_50 . V_69 , V_62 -> V_70 , V_71 ) ;
memcpy ( V_176 -> V_50 . V_72 , V_8 -> V_55 -> V_73 , V_71 ) ;
memcpy ( V_176 -> V_50 . V_74 , V_62 -> V_70 , V_71 ) ;
memcpy ( V_8 -> V_197 , V_62 -> V_70 , V_71 ) ;
V_176 -> V_5 = F_16 ( V_172 ) ;
if ( V_62 -> V_5 & V_154 )
V_176 -> V_5 |= F_16 ( V_154 ) ;
if ( V_62 -> V_5 & V_198 )
V_176 -> V_5 |= F_16 ( V_198 ) ;
if( V_8 -> V_149 )
V_176 -> V_5 |= F_16 ( V_6 ) ;
V_176 -> V_199 = 0xa ;
V_176 -> V_156 . V_157 = V_83 ;
V_176 -> V_156 . V_77 = V_62 -> V_80 ;
V_16 = F_21 ( V_38 , V_62 -> V_80 ) ;
memcpy ( V_16 , V_62 -> V_84 , V_62 -> V_80 ) ;
V_16 = F_21 ( V_38 , V_9 ) ;
F_4 ( V_8 , & V_16 ) ;
F_5 ( V_8 , & V_16 ) ;
V_16 = F_21 ( V_38 , V_8 -> V_147 ) ;
memcpy ( V_16 , V_8 -> V_167 , V_8 -> V_147 ) ;
V_16 = F_21 ( V_38 , V_187 ) ;
if( V_187 ) {
F_6 ( V_8 , & V_16 ) ;
}
V_16 = F_21 ( V_38 , V_189 ) ;
if( V_189 ) {
F_8 ( V_8 , & V_16 ) ;
}
return V_38 ;
}
void F_66 ( struct V_7 * V_8 )
{
unsigned long V_45 ;
F_14 ( & V_8 -> V_52 , V_45 ) ;
V_8 -> V_134 ++ ;
if ( V_8 -> V_101 == V_200 ) {
F_67 ( L_4 ) ;
V_8 -> V_85 . V_201 ++ ;
} else{
F_67 ( L_5 ) ;
V_8 -> V_85 . V_202 ++ ;
}
V_8 -> V_101 = V_203 ;
F_44 ( V_8 -> V_116 , & V_8 -> V_204 , V_205 ) ;
F_17 ( & V_8 -> V_52 , V_45 ) ;
}
void F_68 ( unsigned long V_55 )
{
F_66 ( (struct V_7 * ) V_55 ) ;
}
void F_69 ( struct V_7 * V_8 )
{
struct V_1 * V_62 = & V_8 -> V_33 ;
struct V_37 * V_38 ;
F_67 ( L_6 ) ;
V_8 -> V_85 . V_206 ++ ;
V_38 = F_57 ( V_62 , V_8 , 0 ) ;
if ( ! V_38 ) {
F_66 ( V_8 ) ;
}
else{
V_8 -> V_101 = V_200 ;
F_67 ( L_7 ) ;
F_13 ( V_38 , V_8 ) ;
if( ! F_70 ( & V_8 -> V_207 ) ) {
V_8 -> V_207 . V_88 = V_57 + ( V_208 / 2 ) ;
F_28 ( & V_8 -> V_207 ) ;
}
}
}
void F_71 ( struct V_7 * V_8 , T_1 * V_209 , int V_210 )
{
T_1 * V_211 ;
struct V_37 * V_38 ;
struct V_1 * V_62 = & V_8 -> V_33 ;
F_47 ( & V_8 -> V_207 ) ;
V_8 -> V_134 ++ ;
V_8 -> V_85 . V_206 ++ ;
V_38 = F_57 ( V_62 , V_8 , V_210 + 2 ) ;
if ( ! V_38 )
F_66 ( V_8 ) ;
else{
V_211 = F_21 ( V_38 , V_210 + 2 ) ;
* ( V_211 ++ ) = V_212 ;
* ( V_211 ++ ) = V_210 ;
memcpy ( V_211 , V_209 , V_210 ) ;
F_67 ( L_8 ) ;
F_72 ( V_8 , V_38 , sizeof( struct V_49 ) ) ;
F_13 ( V_38 , V_8 ) ;
if ( ! F_70 ( & V_8 -> V_207 ) ) {
V_8 -> V_207 . V_88 = V_57 + ( V_208 / 2 ) ;
F_28 ( & V_8 -> V_207 ) ;
}
F_26 ( V_38 ) ;
}
F_73 ( V_209 ) ;
}
void F_74 ( struct V_7 * V_8 )
{
struct V_37 * V_38 ;
struct V_1 * V_62 = & V_8 -> V_33 ;
F_47 ( & V_8 -> V_207 ) ;
F_67 ( L_9 ) ;
V_8 -> V_85 . V_213 ++ ;
V_38 = F_65 ( V_62 , V_8 ) ;
if ( ! V_38 )
F_66 ( V_8 ) ;
else{
F_13 ( V_38 , V_8 ) ;
if ( ! F_70 ( & V_8 -> V_207 ) ) {
V_8 -> V_207 . V_88 = V_57 + ( V_208 / 2 ) ;
F_28 ( & V_8 -> V_207 ) ;
}
}
}
void F_75 ( struct V_109 * V_110 )
{
struct V_7 * V_8 = F_43 ( V_110 , struct V_7 , V_214 ) ;
F_9 ( V_215 L_10 ) ;
if( F_1 ( & V_8 -> V_33 ) &&
( V_8 -> V_10 & V_13 ) ) {
V_8 -> V_216 = 540 ;
F_9 ( V_215 L_11 ) ;
} else{
V_8 -> V_216 = 110 ;
F_9 ( V_215 L_12 ) ;
}
V_8 -> V_217 ( V_8 -> V_55 ) ;
F_76 ( V_8 ) ;
if ( V_8 -> V_218 )
V_8 -> V_218 ( V_8 -> V_55 ) ;
F_77 ( V_8 -> V_55 ) ;
}
void F_78 ( struct V_7 * V_8 )
{
int V_219 ;
F_47 ( & V_8 -> V_207 ) ;
for( V_219 = 0 ; V_219 < 6 ; V_219 ++ ) {
}
V_8 -> V_101 = V_102 ;
F_67 ( L_13 ) ;
F_79 ( V_8 -> V_116 , & V_8 -> V_214 ) ;
}
void F_80 ( struct V_109 * V_110 )
{
struct V_7 * V_8 = F_43 ( V_110 , struct V_7 , V_220 ) ;
V_8 -> V_104 = 1 ;
F_35 ( & V_8 -> V_221 ) ;
if ( V_8 -> V_222 )
V_8 -> V_222 ( V_8 -> V_55 ) ;
F_52 ( V_8 ) ;
V_8 -> V_103 ( V_8 -> V_55 , V_8 -> V_33 . V_107 ) ;
V_8 -> V_134 = 1 ;
F_69 ( V_8 ) ;
F_37 ( & V_8 -> V_221 ) ;
}
inline void F_81 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
T_1 V_223 [ V_224 + 1 ] ;
int V_225 = 0 ;
short V_226 , V_227 , V_228 , V_229 , V_230 ;
if ( V_8 -> V_101 != V_231 )
return;
if ( ( V_8 -> V_165 == V_232 ) && ! ( V_2 -> V_5 & V_172 ) )
return;
if ( ( V_8 -> V_165 == V_166 ) && ! ( V_2 -> V_5 & V_148 ) )
return;
if ( V_8 -> V_165 == V_232 || V_8 -> V_165 == V_166 ) {
V_226 = V_8 -> V_233 ;
V_227 = V_8 -> V_234 ;
V_228 = ! ( V_2 -> V_80 == 0 || V_2 -> V_84 [ 0 ] == '\0' ) ;
V_229 = ( memcmp ( V_8 -> V_33 . V_70 , V_2 -> V_70 , V_71 ) == 0 ) ;
if( V_8 -> V_33 . V_80 != V_2 -> V_80 )
V_230 = 0 ;
else
V_230 = ( 0 == strncmp ( V_8 -> V_33 . V_84 , V_2 -> V_84 , V_2 -> V_80 ) ) ;
if (
( V_226 && V_229 &&
( ( V_227 && V_228 && V_230 ) || ( V_228 && ! V_227 ) || ( ! V_228 && V_227 ) ) ) ||
( ! V_226 && V_227 && V_228 && V_230 )
) {
if ( ! V_228 ) {
strncpy ( V_223 , V_8 -> V_33 . V_84 , V_224 ) ;
V_225 = V_8 -> V_33 . V_80 ;
}
memcpy ( & V_8 -> V_33 , V_2 , sizeof( struct V_1 ) ) ;
if ( ! V_228 ) {
strncpy ( V_8 -> V_33 . V_84 , V_223 , V_224 ) ;
V_8 -> V_33 . V_80 = V_225 ;
}
F_9 ( V_215 L_14 , V_8 -> V_33 . V_84 , V_8 -> V_33 . V_107 ) ;
if ( V_8 -> V_165 == V_232 ) {
V_8 -> V_101 = V_235 ;
V_8 -> V_236 = false ;
F_79 ( V_8 -> V_116 , & V_8 -> V_220 ) ;
} else{
if( F_1 ( & V_8 -> V_33 ) &&
( V_8 -> V_10 & V_13 ) ) {
V_8 -> V_216 = 540 ;
F_9 ( V_215 L_11 ) ;
} else{
V_8 -> V_216 = 110 ;
F_9 ( V_215 L_12 ) ;
}
V_8 -> V_101 = V_102 ;
V_8 -> V_236 = false ;
}
}
}
}
void F_82 ( struct V_7 * V_8 )
{
unsigned long V_45 ;
struct V_1 * V_237 ;
F_14 ( & V_8 -> V_52 , V_45 ) ;
F_83 (target, &ieee->network_list, list) {
if ( V_8 -> V_101 != V_231 )
break;
if ( V_8 -> V_238 == 0 || F_84 ( V_237 -> V_239 + V_8 -> V_238 , V_57 ) )
F_81 ( V_8 , V_237 ) ;
}
F_17 ( & V_8 -> V_52 , V_45 ) ;
}
static inline V_161 F_85 ( struct V_37 * V_38 , T_1 * * V_209 , int * V_210 )
{
struct V_125 * V_240 ;
T_1 * V_241 ;
if ( V_38 -> V_77 < ( sizeof( struct V_125 ) - sizeof( struct V_242 ) ) ) {
F_67 ( L_15 , V_38 -> V_77 ) ;
return 0xcafe ;
}
* V_209 = NULL ;
V_240 = (struct V_125 * ) V_38 -> V_51 ;
if( V_38 -> V_77 > ( sizeof( struct V_125 ) + 3 ) ) {
V_241 = V_38 -> V_51 + sizeof( struct V_125 ) ;
if( * ( V_241 ++ ) == V_212 ) {
* V_210 = * ( V_241 ++ ) ;
* V_209 = F_86 ( V_241 , * V_210 , V_243 ) ;
if ( ! * V_209 )
return - V_244 ;
}
}
return F_16 ( V_240 -> V_135 ) ;
}
int F_87 ( struct V_37 * V_38 , T_1 * V_137 )
{
struct V_125 * V_240 ;
if ( V_38 -> V_77 < ( sizeof( struct V_125 ) - sizeof( struct V_242 ) ) ) {
F_67 ( L_16 , V_38 -> V_77 ) ;
return - 1 ;
}
V_240 = (struct V_125 * ) V_38 -> V_51 ;
memcpy ( V_137 , V_240 -> V_50 . V_72 , V_71 ) ;
if ( F_88 ( V_240 -> V_129 ) != V_131 )
return V_245 ;
return V_136 ;
}
static short F_89 ( struct V_7 * V_8 , struct V_37 * V_38 , T_1 * V_246 )
{
T_1 * V_16 ;
T_1 * V_247 ;
T_1 * V_84 = NULL ;
T_1 V_248 = 0 ;
struct V_49 * V_50 =
(struct V_49 * ) V_38 -> V_51 ;
if ( V_38 -> V_77 < sizeof ( struct V_49 ) )
return - 1 ;
memcpy ( V_246 , V_50 -> V_72 , V_71 ) ;
V_247 = ( T_1 * ) V_38 -> V_51 + V_38 -> V_77 ;
V_16 = V_38 -> V_51 + sizeof ( struct V_49 ) ;
while ( V_16 + 1 < V_247 ) {
if ( * V_16 == 0 ) {
V_84 = V_16 + 2 ;
V_248 = * ( V_16 + 1 ) ;
break;
}
V_16 ++ ;
V_16 = V_16 + * ( V_16 ) ;
V_16 ++ ;
}
if ( V_248 == 0 ) return 1 ;
if ( ! V_84 ) return 1 ;
return ( ! strncmp ( V_84 , V_8 -> V_33 . V_84 , V_248 ) ) ;
}
int F_90 ( struct V_37 * V_38 , T_1 * V_137 )
{
struct V_183 * V_240 ;
if ( V_38 -> V_77 < ( sizeof( struct V_183 ) -
sizeof( struct V_242 ) ) ) {
F_67 ( L_17 , V_38 -> V_77 ) ;
return - 1 ;
}
V_240 = (struct V_183 * ) V_38 -> V_51 ;
memcpy ( V_137 , V_240 -> V_50 . V_72 , V_71 ) ;
return 0 ;
}
static inline V_161 F_91 ( struct V_37 * V_38 , int * V_173 )
{
struct V_168 * V_240 ;
if ( V_38 -> V_77 < sizeof( struct V_168 ) ) {
F_67 ( L_15 , V_38 -> V_77 ) ;
return 0xcafe ;
}
V_240 = (struct V_168 * ) V_38 -> V_51 ;
* V_173 = F_88 ( V_240 -> V_173 ) & 0x3fff ;
return F_88 ( V_240 -> V_135 ) ;
}
static inline void
F_92 ( struct V_7 * V_8 , struct V_37 * V_38 )
{
T_1 V_137 [ V_71 ] ;
V_8 -> V_85 . V_249 ++ ;
if ( F_89 ( V_8 , V_38 , V_137 ) ) {
V_8 -> V_85 . V_250 ++ ;
F_64 ( V_8 , V_137 ) ;
}
}
inline void
F_93 ( struct V_7 * V_8 , struct V_37 * V_38 )
{
T_1 V_137 [ V_71 ] ;
int V_135 ;
V_8 -> V_85 . V_251 ++ ;
V_135 = F_87 ( V_38 , V_137 ) ;
if ( V_135 != - 1 ) {
F_63 ( V_8 , V_135 , V_137 ) ;
}
}
inline void
F_94 ( struct V_7 * V_8 , struct V_37 * V_38 )
{
T_1 V_137 [ V_71 ] ;
V_8 -> V_85 . V_252 ++ ;
if ( F_90 ( V_38 , V_137 ) != - 1 ) {
F_62 ( V_8 , V_137 ) ;
}
F_9 ( V_215 L_18 , V_137 ) ;
}
void F_95 ( struct V_7 * V_8 , short V_175 )
{
struct V_37 * V_181 = F_61 ( V_8 , V_175 ) ;
if ( V_181 )
F_18 ( V_181 , V_8 ) ;
}
short F_96 ( struct V_7 * V_8 , T_2 * V_253 , T_2 * V_254 )
{
int V_255 = 0 ;
T_1 V_256 ;
V_256 = V_8 -> V_33 . V_257 ;
if( ! ( V_256 & V_258 ) )
return 0 ;
else
V_255 = V_8 -> V_33 . V_89 ;
V_8 -> V_33 . V_257 = V_259 ;
if( V_256 & ( ( V_260 | V_261 ) & V_8 -> V_262 ) )
return 2 ;
if( ! F_84 ( V_57 , V_8 -> V_55 -> V_56 + F_27 ( V_255 ) ) )
return 0 ;
if( ! F_84 ( V_57 , V_8 -> V_263 + F_27 ( V_255 ) ) )
return 0 ;
if( ( V_8 -> V_47 & V_48 ) &&
( V_8 -> V_44 != V_8 -> V_40 ) )
return 0 ;
if( V_254 ) {
* V_254 = V_8 -> V_33 . V_264 [ 0 ]
+ F_27 ( ( V_8 -> V_33 . V_89 ) ) ;
}
if( V_253 ) {
* V_253 = V_8 -> V_33 . V_264 [ 1 ] ;
if( V_254 && * V_254 < V_8 -> V_33 . V_264 [ 0 ] )
* V_253 += 1 ;
}
return 1 ;
}
inline void F_97 ( struct V_7 * V_8 )
{
T_2 V_265 , V_266 ;
short V_267 ;
unsigned long V_45 , V_268 ;
F_14 ( & V_8 -> V_52 , V_45 ) ;
if( ( V_8 -> V_262 == V_269 ||
V_8 -> V_165 != V_232 ||
V_8 -> V_101 != V_102 ) ) {
F_14 ( & V_8 -> V_60 , V_268 ) ;
F_15 ( V_8 , 1 ) ;
F_17 ( & V_8 -> V_60 , V_268 ) ;
}
V_267 = F_96 ( V_8 , & V_265 , & V_266 ) ;
if( V_267 == 0 )
goto V_100;
if( V_267 == 1 ) {
if( V_8 -> V_270 == 1 )
V_8 -> V_271 ( V_8 -> V_55 , V_265 , V_266 ) ;
else if( V_8 -> V_270 == 0 ) {
F_14 ( & V_8 -> V_60 , V_268 ) ;
if( V_8 -> V_272 ( V_8 -> V_55 ) ) {
V_8 -> V_270 = 2 ;
V_8 -> V_273 ( V_8 -> V_55 ) ;
F_95 ( V_8 , 1 ) ;
V_8 -> V_274 = V_265 ;
V_8 -> V_275 = V_266 ;
}
F_17 ( & V_8 -> V_60 , V_268 ) ;
}
} else if( V_267 == 2 ) {
F_14 ( & V_8 -> V_60 , V_268 ) ;
F_15 ( V_8 , 1 ) ;
F_17 ( & V_8 -> V_60 , V_268 ) ;
}
V_100:
F_17 ( & V_8 -> V_52 , V_45 ) ;
}
void F_15 ( struct V_7 * V_8 , short V_276 )
{
if( V_8 -> V_270 == 0 ) {
if( V_276 ) {
V_8 -> V_273 ( V_8 -> V_55 ) ;
F_95 ( V_8 , 0 ) ;
}
return;
}
if( V_8 -> V_270 == 1 )
V_8 -> V_277 ( V_8 -> V_55 ) ;
V_8 -> V_270 = 0 ;
if( V_276 ) {
V_8 -> V_273 ( V_8 -> V_55 ) ;
F_95 ( V_8 , 0 ) ;
}
}
void F_98 ( struct V_7 * V_8 , short V_278 )
{
unsigned long V_45 , V_268 ;
F_14 ( & V_8 -> V_52 , V_45 ) ;
if( V_8 -> V_270 == 2 ) {
if( V_278 ) {
V_8 -> V_270 = 1 ;
V_8 -> V_271 ( V_8 -> V_55 , V_8 -> V_274 , V_8 -> V_275 ) ;
}
}
else {
if( ( V_8 -> V_270 == 0 ) && ! V_278 ) {
F_14 ( & V_8 -> V_60 , V_268 ) ;
F_95 ( V_8 , 0 ) ;
F_17 ( & V_8 -> V_60 , V_268 ) ;
}
}
F_17 ( & V_8 -> V_52 , V_45 ) ;
}
inline int
F_99 ( struct V_7 * V_8 , struct V_37 * V_38 ,
struct V_279 * V_280 , V_161 type ,
V_161 V_281 )
{
struct V_49 * V_50 = (struct V_49 * ) V_38 -> V_51 ;
V_161 V_282 ;
T_1 * V_209 = NULL ;
int V_210 = 0 ;
int V_173 = 0 ;
struct V_168 * V_283 ;
struct V_242 * V_156 ;
if( ! V_8 -> V_284 )
return 0 ;
if( V_8 -> V_270 || ( V_8 -> V_262 != V_269 &&
V_8 -> V_165 == V_232 &&
V_8 -> V_101 == V_102 ) )
F_100 ( & V_8 -> V_285 ) ;
if ( F_101 ( V_50 -> V_66 ) != V_155 &&
F_101 ( V_50 -> V_66 ) != V_286 )
V_8 -> V_263 = V_57 ;
switch ( F_101 ( V_50 -> V_66 ) ) {
case V_170 :
case V_287 :
F_67 ( L_19 ,
F_101 ( V_50 -> V_81 ) ) ;
if ( ( V_8 -> V_47 & V_288 ) &&
V_8 -> V_101 == V_289 &&
V_8 -> V_165 == V_232 ) {
if ( 0 == ( V_282 = F_91 ( V_38 , & V_173 ) ) ) {
V_161 V_290 ;
V_8 -> V_101 = V_102 ;
V_8 -> V_174 = V_173 ;
V_8 -> V_85 . V_291 ++ ;
if( 1 == V_280 -> V_292 )
{
goto V_293;
}
V_283 = (struct V_168 * ) V_38 -> V_51 ;
V_156 = & V_283 -> V_156 ;
V_290 = V_38 -> V_77 - ( ( void * ) V_156 - ( void * ) V_283 ) ;
while ( V_290 >= sizeof( struct V_294 ) ) {
if ( sizeof( struct V_294 ) + V_156 -> V_77 > V_290 ) {
F_9 ( V_295 L_20 ) ;
return 1 ;
}
switch ( V_156 -> V_157 ) {
case V_32 :
F_102 ( L_21 , V_156 -> V_77 ) ;
if ( V_156 -> V_77 >= 8 &&
V_156 -> V_51 [ 0 ] == 0x00 &&
V_156 -> V_51 [ 1 ] == 0x50 &&
V_156 -> V_51 [ 2 ] == 0xf2 &&
V_156 -> V_51 [ 3 ] == 0x02 &&
V_156 -> V_51 [ 4 ] == 0x01 ) {
memcpy ( V_8 -> V_33 . V_296 , ( T_1 * ) ( V_156 -> V_51 \
+ 8 ) , ( V_156 -> V_77 - 8 ) ) ;
if ( ( ( V_8 -> V_33 . V_34 ^ V_156 -> V_51 [ 6 ] ) & \
0x0f ) || ( ! V_8 -> V_297 ) ) {
V_8 -> V_297 = 1 ;
F_79 ( V_8 -> V_116 , & V_8 -> V_298 ) ;
}
V_8 -> V_33 . V_34 = V_156 -> V_51 [ 6 ] ;
}
break;
default:
break;
}
V_290 -= sizeof( struct V_294 ) +
V_156 -> V_77 ;
V_156 = (struct V_242 * )
& V_156 -> V_51 [ V_156 -> V_77 ] ;
}
if( ! V_8 -> V_297 )
{
F_79 ( V_8 -> V_116 , & V_8 -> V_298 ) ;
V_8 -> V_297 = 1 ;
}
V_293:
F_78 ( V_8 ) ;
} else{
V_8 -> V_85 . V_299 ++ ;
F_67 (
L_22 ,
V_282 ) ;
F_66 ( V_8 ) ;
}
}
break;
case V_196 :
case V_300 :
if ( ( V_8 -> V_47 & V_288 ) &&
V_8 -> V_165 == V_171 )
F_94 ( V_8 , V_38 ) ;
break;
case V_127 :
if ( V_8 -> V_47 & V_288 ) {
if ( V_8 -> V_101 == V_200 &&
V_8 -> V_165 == V_232 ) {
F_67 ( L_23 ) ;
if ( 0 == ( V_282 = F_85 ( V_38 , & V_209 , & V_210 ) ) ) {
if( V_8 -> V_130 || ! V_209 ) {
V_8 -> V_101 = V_289 ;
V_8 -> V_85 . V_301 ++ ;
F_74 ( V_8 ) ;
} else{
F_71 ( V_8 , V_209 , V_210 ) ;
}
} else{
V_8 -> V_85 . V_302 ++ ;
F_67 ( L_24 , V_282 ) ;
F_66 ( V_8 ) ;
}
} else if ( V_8 -> V_165 == V_171 ) {
F_93 ( V_8 , V_38 ) ;
}
}
break;
case V_82 :
if ( ( V_8 -> V_47 & V_303 ) &&
( ( V_8 -> V_165 == V_166 ||
V_8 -> V_165 == V_171 ) &&
V_8 -> V_101 == V_102 ) )
F_92 ( V_8 , V_38 ) ;
break;
case V_67 :
case V_304 :
if ( ( V_8 -> V_47 & V_288 ) &&
( V_8 -> V_101 == V_102 ) &&
( V_8 -> V_165 == V_232 ) &&
( ! memcmp ( V_50 -> V_72 , V_8 -> V_33 . V_70 , V_71 ) ) ) {
V_8 -> V_101 = V_235 ;
V_8 -> V_85 . V_305 ++ ;
F_79 ( V_8 -> V_116 , & V_8 -> V_220 ) ;
}
break;
default:
return - 1 ;
break;
}
return 0 ;
}
void F_103 ( struct V_306 * V_307 , struct V_7 * V_8 )
{
unsigned long V_45 ;
int V_219 ;
F_14 ( & V_8 -> V_52 , V_45 ) ;
F_15 ( V_8 , 0 ) ;
for( V_219 = 0 ; V_219 < V_307 -> V_308 ; V_219 ++ ) {
if ( V_8 -> V_53 ) {
V_8 -> V_309 . V_307 = V_307 ;
V_8 -> V_309 . V_310 = V_219 ;
goto exit;
} else{
V_8 -> V_58 (
V_307 -> V_311 [ V_219 ] ,
V_8 -> V_55 , V_8 -> V_216 ) ;
V_8 -> V_312 . V_313 ++ ;
V_8 -> V_312 . V_314 += V_307 -> V_311 [ V_219 ] -> V_77 ;
V_8 -> V_55 -> V_56 = V_57 ;
}
}
F_104 ( V_307 ) ;
exit:
F_17 ( & V_8 -> V_52 , V_45 ) ;
}
void F_105 ( struct V_7 * V_8 )
{
int V_219 ;
for( V_219 = V_8 -> V_309 . V_310 ; V_219 < V_8 -> V_309 . V_307 -> V_308 ; V_219 ++ ) {
if ( V_8 -> V_53 ) {
V_8 -> V_309 . V_310 = V_219 ;
return;
} else{
V_8 -> V_58 (
V_8 -> V_309 . V_307 -> V_311 [ V_219 ] ,
V_8 -> V_55 , V_8 -> V_216 ) ;
V_8 -> V_312 . V_313 ++ ;
V_8 -> V_55 -> V_56 = V_57 ;
}
}
F_104 ( V_8 -> V_309 . V_307 ) ;
V_8 -> V_309 . V_307 = NULL ;
}
void F_106 ( struct V_7 * V_8 )
{
unsigned long V_45 ;
F_14 ( & V_8 -> V_52 , V_45 ) ;
F_12 ( V_8 ) ;
if ( V_8 -> V_309 . V_307 ) {
F_104 ( V_8 -> V_309 . V_307 ) ;
V_8 -> V_309 . V_307 = NULL ;
}
V_8 -> V_53 = 0 ;
F_17 ( & V_8 -> V_52 , V_45 ) ;
}
void F_107 ( struct V_7 * V_8 )
{
unsigned long V_45 ;
struct V_37 * V_38 ;
struct V_49 * V_50 ;
F_14 ( & V_8 -> V_52 , V_45 ) ;
if ( ! V_8 -> V_53 ) goto exit;
V_8 -> V_53 = 0 ;
if( V_8 -> V_47 & V_48 ) {
while ( ! V_8 -> V_53 && ( V_38 = F_11 ( V_8 ) ) ) {
V_50 = (struct V_49 * ) V_38 -> V_51 ;
V_50 -> V_54 = F_16 ( V_8 -> V_54 [ 0 ] << 4 ) ;
if ( V_8 -> V_54 [ 0 ] == 0xFFF )
V_8 -> V_54 [ 0 ] = 0 ;
else
V_8 -> V_54 [ 0 ] ++ ;
V_8 -> V_58 ( V_38 , V_8 -> V_55 , V_8 -> V_59 ) ;
F_26 ( V_38 ) ;
}
}
if ( ! V_8 -> V_53 && V_8 -> V_309 . V_307 )
F_105 ( V_8 ) ;
if ( ! V_8 -> V_53 && F_108 ( V_8 -> V_55 ) ) {
V_8 -> V_85 . V_315 ++ ;
F_109 ( V_8 -> V_55 ) ;
}
exit :
F_17 ( & V_8 -> V_52 , V_45 ) ;
}
void F_110 ( struct V_7 * V_8 )
{
if ( ! F_108 ( V_8 -> V_55 ) ) {
F_111 ( V_8 -> V_55 ) ;
V_8 -> V_85 . V_316 ++ ;
}
V_8 -> V_53 = 1 ;
}
inline void F_112 ( struct V_7 * V_8 )
{
F_113 ( V_8 -> V_33 . V_70 ) ;
}
void F_114 ( struct V_7 * V_8 )
{
V_8 -> V_174 = 1 ;
if ( V_8 -> V_33 . V_80 == 0 ) {
strncpy ( V_8 -> V_33 . V_84 ,
V_317 ,
V_224 ) ;
V_8 -> V_33 . V_80 = strlen ( V_317 ) ;
V_8 -> V_234 = 1 ;
}
memcpy ( V_8 -> V_33 . V_70 , V_8 -> V_55 -> V_73 , V_71 ) ;
V_8 -> V_103 ( V_8 -> V_55 , V_8 -> V_33 . V_107 ) ;
V_8 -> V_101 = V_102 ;
V_8 -> V_217 ( V_8 -> V_55 ) ;
F_76 ( V_8 ) ;
if ( V_8 -> V_218 )
V_8 -> V_218 ( V_8 -> V_55 ) ;
F_77 ( V_8 -> V_55 ) ;
}
void F_115 ( struct V_7 * V_8 )
{
if( V_8 -> V_318 ) {
if ( V_8 -> V_218 )
V_8 -> V_218 ( V_8 -> V_55 ) ;
F_77 ( V_8 -> V_55 ) ;
}
}
void F_116 ( struct V_109 * V_110 )
{
struct V_111 * V_112 = F_42 ( V_110 ) ;
struct V_7 * V_8 = F_43 ( V_112 , struct V_7 , V_319 ) ;
F_35 ( & V_8 -> V_221 ) ;
if ( V_8 -> V_33 . V_80 == 0 ) {
strcpy ( V_8 -> V_33 . V_84 , V_317 ) ;
V_8 -> V_33 . V_80 = strlen ( V_317 ) ;
V_8 -> V_234 = 1 ;
}
F_82 ( V_8 ) ;
if( V_8 -> V_101 == V_231 )
V_8 -> V_33 . V_107 = 10 ;
if ( V_8 -> V_101 == V_231 )
F_56 ( V_8 ) ;
if ( V_8 -> V_101 == V_231 ) {
F_9 ( L_25 ) ;
if( ! V_8 -> V_233 )
F_112 ( V_8 ) ;
if( V_8 -> V_10 & V_11 ) {
V_8 -> V_33 . V_4 = 4 ;
V_8 -> V_33 . V_158 [ 0 ] = V_18 | V_19 ;
V_8 -> V_33 . V_158 [ 1 ] = V_18 | V_20 ;
V_8 -> V_33 . V_158 [ 2 ] = V_18 | V_21 ;
V_8 -> V_33 . V_158 [ 3 ] = V_18 | V_22 ;
} else
V_8 -> V_33 . V_4 = 0 ;
if( V_8 -> V_10 & V_13 ) {
V_8 -> V_33 . V_3 = 8 ;
V_8 -> V_33 . V_164 [ 0 ] = V_18 | V_24 ;
V_8 -> V_33 . V_164 [ 1 ] = V_18 | V_25 ;
V_8 -> V_33 . V_164 [ 2 ] = V_18 | V_26 ;
V_8 -> V_33 . V_164 [ 3 ] = V_18 | V_27 ;
V_8 -> V_33 . V_164 [ 4 ] = V_18 | V_28 ;
V_8 -> V_33 . V_164 [ 5 ] = V_18 | V_29 ;
V_8 -> V_33 . V_164 [ 6 ] = V_18 | V_30 ;
V_8 -> V_33 . V_164 [ 7 ] = V_18 | V_31 ;
V_8 -> V_216 = 540 ;
} else{
V_8 -> V_33 . V_3 = 0 ;
V_8 -> V_216 = 110 ;
}
V_8 -> V_33 . V_188 = 0 ;
V_8 -> V_33 . V_162 = 0 ;
V_8 -> V_33 . V_5 = V_148 ;
if( V_8 -> V_149 )
V_8 -> V_33 . V_5 |= V_6 ;
}
V_8 -> V_101 = V_102 ;
V_8 -> V_103 ( V_8 -> V_55 , V_8 -> V_33 . V_107 ) ;
V_8 -> V_217 ( V_8 -> V_55 ) ;
F_76 ( V_8 ) ;
F_49 ( V_8 ) ;
F_9 ( V_295 L_26 ) ;
if ( V_8 -> V_218 )
V_8 -> V_218 ( V_8 -> V_55 ) ;
F_77 ( V_8 -> V_55 ) ;
F_37 ( & V_8 -> V_221 ) ;
}
inline void F_117 ( struct V_7 * V_8 )
{
F_44 ( V_8 -> V_116 , & V_8 -> V_319 , 100 ) ;
}
void F_118 ( struct V_7 * V_8 )
{
unsigned long V_45 ;
if( F_38 ( V_8 ) && ! F_54 ( V_8 ) )
{
if( ! V_8 -> V_320 )
{
return;
}
}
F_82 ( V_8 ) ;
F_14 ( & V_8 -> V_52 , V_45 ) ;
if ( V_8 -> V_101 == V_231 ) {
V_8 -> V_108 = true ;
F_53 ( V_8 ) ;
}
F_17 ( & V_8 -> V_52 , V_45 ) ;
}
void F_119 ( struct V_7 * V_8 )
{
F_120 ( V_8 -> V_55 ) ;
if ( V_8 -> V_47 & V_321 )
F_106 ( V_8 ) ;
if ( V_8 -> V_222 )
V_8 -> V_222 ( V_8 -> V_55 ) ;
if( F_38 ( V_8 ) )
F_121 ( V_8 ) ;
V_8 -> V_217 ( V_8 -> V_55 ) ;
if ( V_8 -> V_101 == V_102 )
F_76 ( V_8 ) ;
V_8 -> V_101 = V_231 ;
}
void F_122 ( struct V_109 * V_110 )
{
struct V_111 * V_112 = F_42 ( V_110 ) ;
struct V_7 * V_8 = F_43 ( V_112 , struct V_7 , V_204 ) ;
unsigned long V_45 ;
F_35 ( & V_8 -> V_221 ) ;
if( ! V_8 -> V_284 )
goto exit;
if( V_8 -> V_101 != V_203 )
goto exit;
V_8 -> V_101 = V_231 ;
V_8 -> V_236 = true ;
F_82 ( V_8 ) ;
F_14 ( & V_8 -> V_52 , V_45 ) ;
if( V_8 -> V_101 == V_231 ) {
V_8 -> V_236 = false ;
V_8 -> V_108 = true ;
F_53 ( V_8 ) ;
}
if( V_8 -> V_101 == V_231 )
{
F_76 ( V_8 ) ;
}
F_17 ( & V_8 -> V_52 , V_45 ) ;
exit:
F_37 ( & V_8 -> V_221 ) ;
}
struct V_37 * F_25 ( struct V_7 * V_8 )
{
T_1 V_322 [] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
struct V_37 * V_38 = NULL ;
struct V_139 * V_323 ;
V_38 = F_58 ( V_8 , V_322 ) ;
if ( ! V_38 )
return NULL ;
V_323 = (struct V_139 * ) V_38 -> V_51 ;
V_323 -> V_50 . V_81 = F_16 ( V_286 ) ;
return V_38 ;
}
struct V_37 * F_123 ( struct V_7 * V_8 )
{
struct V_37 * V_38 ;
struct V_139 * V_323 ;
V_38 = F_25 ( V_8 ) ;
if( ! V_38 )
return NULL ;
V_323 = (struct V_139 * ) V_38 -> V_51 ;
V_323 -> V_50 . V_54 = F_16 ( V_8 -> V_54 [ 0 ] << 4 ) ;
if ( V_8 -> V_54 [ 0 ] == 0xFFF )
V_8 -> V_54 [ 0 ] = 0 ;
else
V_8 -> V_54 [ 0 ] ++ ;
return V_38 ;
}
void F_124 ( struct V_7 * V_8 )
{
V_8 -> V_104 = 1 ;
F_35 ( & V_8 -> V_221 ) ;
F_125 ( V_8 ) ;
F_37 ( & V_8 -> V_221 ) ;
}
void F_125 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_284 )
return;
V_8 -> V_284 = 0 ;
F_48 ( V_8 ) ;
if( ( V_8 -> V_165 == V_232 ) && ( V_8 -> V_101 == V_102 ) ) {
F_22 ( V_8 , NULL , V_324 ) ;
}
F_47 ( & V_8 -> V_207 ) ;
F_51 ( & V_8 -> V_204 ) ;
F_51 ( & V_8 -> V_319 ) ;
F_52 ( V_8 ) ;
F_119 ( V_8 ) ;
}
void F_126 ( struct V_7 * V_8 )
{
V_8 -> V_104 = 0 ;
F_35 ( & V_8 -> V_221 ) ;
F_127 ( V_8 ) ;
F_37 ( & V_8 -> V_221 ) ;
}
void F_127 ( struct V_7 * V_8 )
{
short V_96 = 0 ;
int V_219 = 0 ;
if ( V_8 -> V_284 )
return;
V_8 -> V_284 = 1 ;
if ( V_8 -> V_33 . V_107 == 0 ) {
do{
V_96 ++ ;
if ( V_96 > V_98 )
return;
}while( ! F_34 ( V_8 ) -> V_97 [ V_96 ] );
V_8 -> V_33 . V_107 = V_96 ;
}
if ( V_8 -> V_33 . V_89 == 0 )
V_8 -> V_33 . V_89 = 100 ;
V_8 -> V_103 ( V_8 -> V_55 , V_8 -> V_33 . V_107 ) ;
for( V_219 = 0 ; V_219 < 17 ; V_219 ++ ) {
V_8 -> V_325 [ V_219 ] = - 1 ;
V_8 -> V_326 [ V_219 ] = - 1 ;
V_8 -> V_327 [ V_219 ] = 0 ;
}
V_8 -> V_297 = 0 ;
switch ( V_8 -> V_165 ) {
case V_328 :
V_8 -> V_165 = V_232 ;
case V_232 :
F_118 ( V_8 ) ;
break;
case V_166 :
F_117 ( V_8 ) ;
break;
case V_171 :
F_114 ( V_8 ) ;
break;
case V_329 :
F_115 ( V_8 ) ;
break;
default:
V_8 -> V_165 = V_232 ;
F_118 ( V_8 ) ;
break;
}
}
void F_128 ( struct V_7 * V_8 )
{
int V_219 ;
memset ( & V_8 -> V_33 , 0 , sizeof( struct V_1 ) ) ;
V_8 -> V_101 = V_231 ;
V_8 -> V_104 = 0 ;
for( V_219 = 0 ; V_219 < 5 ; V_219 ++ ) {
V_8 -> V_54 [ V_219 ] = 0 ;
}
V_8 -> V_174 = 0 ;
V_8 -> V_53 = 0 ;
V_8 -> V_115 = 0 ;
V_8 -> V_47 = 0 ;
V_8 -> V_233 = 0 ;
V_8 -> V_234 = 0 ;
V_8 -> V_284 = 0 ;
V_8 -> V_59 = V_330 ;
V_8 -> V_216 = 3 ;
V_8 -> V_262 = V_331 | V_332 ;
V_8 -> V_270 = 0 ;
V_8 -> V_333 = false ;
V_8 -> V_108 = false ;
V_8 -> V_334 = 2 ;
V_8 -> V_335 = 0 ;
V_8 -> V_336 = 0 ;
V_8 -> V_337 = 0 ;
V_8 -> V_338 = 0 ;
V_8 -> V_236 = false ;
V_8 -> V_339 = false ;
F_12 ( V_8 ) ;
V_8 -> V_309 . V_307 = NULL ;
F_129 ( & V_8 -> V_207 ) ;
V_8 -> V_207 . V_51 = ( unsigned long ) V_8 ;
V_8 -> V_207 . V_340 = F_68 ;
F_129 ( & V_8 -> V_87 ) ;
V_8 -> V_87 . V_51 = ( unsigned long ) V_8 ;
V_8 -> V_87 . V_340 = F_30 ;
V_8 -> V_116 = F_130 ( V_341 ) ;
F_131 ( & V_8 -> V_319 , ( void * ) F_116 ) ;
F_132 ( & V_8 -> V_214 , ( void * ) F_75 ) ;
F_132 ( & V_8 -> V_220 , ( void * ) F_80 ) ;
F_131 ( & V_8 -> V_113 , ( void * ) F_41 ) ;
F_131 ( & V_8 -> V_204 , ( void * ) F_122 ) ;
F_132 ( & V_8 -> V_342 , ( void * ) V_343 ) ;
F_133 ( & V_8 -> V_221 , 1 ) ;
F_133 ( & V_8 -> V_99 , 1 ) ;
F_134 ( & V_8 -> V_60 ) ;
F_134 ( & V_8 -> V_92 ) ;
F_135 ( & V_8 -> V_285 ,
( void (*) ( unsigned long ) ) F_97 ,
( unsigned long ) V_8 ) ;
V_8 -> V_344 = F_136 ( sizeof( V_345 ) , V_243 ) ;
}
void F_137 ( struct V_7 * V_8 )
{
F_35 ( & V_8 -> V_221 ) ;
F_47 ( & V_8 -> V_207 ) ;
F_51 ( & V_8 -> V_204 ) ;
F_51 ( & V_8 -> V_346 ) ;
F_138 ( V_8 -> V_116 ) ;
F_73 ( V_8 -> V_344 ) ;
F_37 ( & V_8 -> V_221 ) ;
}
static int F_139 ( struct V_7 * V_8 , int V_347 )
{
F_9 ( L_27 , V_347 ? L_28 : L_29 ) ;
V_8 -> V_348 = V_347 ;
return 0 ;
}
void F_140 ( struct V_7 * V_8 , char * V_167 , int V_147 )
{
F_139 ( V_8 , 1 ) ;
F_119 ( V_8 ) ;
}
static int F_141 ( struct V_7 * V_8 , int V_349 , int V_350 )
{
int V_43 = 0 ;
switch ( V_349 ) {
case V_351 :
break;
case V_352 :
F_119 ( V_8 ) ;
break;
default:
F_9 ( L_30 , V_349 ) ;
V_43 = - V_353 ;
}
return V_43 ;
}
static int F_142 ( struct V_7 * V_8 ,
struct V_354 * V_355 , int V_356 )
{
T_1 * V_181 ;
if ( V_355 -> V_357 . V_167 . V_77 > V_358 ||
( V_355 -> V_357 . V_167 . V_77 && V_355 -> V_357 . V_167 . V_51 == NULL ) )
return - V_359 ;
if ( V_355 -> V_357 . V_167 . V_77 ) {
V_181 = F_86 ( V_355 -> V_357 . V_167 . V_51 , V_355 -> V_357 . V_167 . V_77 ,
V_360 ) ;
if ( V_181 == NULL )
return - V_244 ;
F_73 ( V_8 -> V_167 ) ;
V_8 -> V_167 = V_181 ;
V_8 -> V_147 = V_355 -> V_357 . V_167 . V_77 ;
} else {
F_73 ( V_8 -> V_167 ) ;
V_8 -> V_167 = NULL ;
V_8 -> V_147 = 0 ;
}
F_140 ( V_8 , V_8 -> V_167 , V_8 -> V_147 ) ;
return 0 ;
}
static int F_143 ( struct V_7 * V_8 , int V_347 )
{
struct V_361 V_362 = {
. V_45 = V_363 ,
} ;
int V_43 = 0 ;
if ( V_347 & V_364 ) {
V_362 . V_365 = V_132 ;
V_8 -> V_130 = 0 ;
} else {
V_362 . V_365 = V_131 ;
V_8 -> V_130 = 1 ;
}
if ( V_8 -> V_366 )
V_8 -> V_366 ( V_8 -> V_55 , & V_362 ) ;
else
V_43 = - V_353 ;
return V_43 ;
}
static int F_144 ( struct V_7 * V_8 , T_1 V_153 , T_2 V_347 )
{
int V_43 = 0 ;
unsigned long V_45 ;
switch ( V_153 ) {
case V_367 :
V_43 = F_139 ( V_8 , V_347 ) ;
break;
case V_368 :
V_8 -> V_369 = V_347 ;
break;
case V_370 : {
struct V_361 V_362 = {
. V_45 = V_371 ,
. V_372 = V_347 ,
} ;
V_8 -> V_373 = V_347 ;
if ( ! V_347 ) {
V_362 . V_45 |= V_374 ;
V_362 . V_375 = V_376 ;
}
else {
V_362 . V_45 |= V_374 ;
V_362 . V_375 = V_377 ;
}
if ( V_8 -> V_366 )
V_8 -> V_366 ( V_8 -> V_55 , & V_362 ) ;
break;
}
case V_378 :
V_8 -> V_379 = V_347 ;
break;
case V_380 :
V_43 = F_143 ( V_8 , V_347 ) ;
break;
case V_381 :
V_8 -> V_382 = V_347 ;
break;
case V_383 :
F_14 ( & V_8 -> V_384 , V_45 ) ;
V_8 -> V_193 = 1 ;
V_8 -> V_192 = V_347 ;
F_17 ( & V_8 -> V_384 , V_45 ) ;
break;
default:
F_9 ( L_31 , V_153 ) ;
V_43 = - V_353 ;
}
return V_43 ;
}
static int F_145 ( struct V_7 * V_8 ,
struct V_354 * V_355 , int V_385 )
{
int V_43 = 0 ;
struct V_386 * V_152 ;
struct V_144 * * V_145 ;
struct V_361 V_362 = {
. V_45 = 0 ,
} ;
V_355 -> V_357 . V_145 . V_387 = 0 ;
V_355 -> V_357 . V_145 . V_388 [ V_389 - 1 ] = '\0' ;
if ( V_385 !=
( int ) ( ( char * ) V_355 -> V_357 . V_145 . V_390 - ( char * ) V_355 ) +
V_355 -> V_357 . V_145 . V_391 ) {
F_9 ( L_32 , V_385 ,
V_355 -> V_357 . V_145 . V_391 ) ;
return - V_359 ;
}
if ( F_146 ( V_355 -> V_392 ) ) {
if ( V_355 -> V_357 . V_145 . V_393 >= V_394 )
return - V_359 ;
V_145 = & V_8 -> V_145 [ V_355 -> V_357 . V_145 . V_393 ] ;
} else {
return - V_359 ;
}
if ( strcmp ( V_355 -> V_357 . V_145 . V_388 , L_33 ) == 0 ) {
if ( V_145 ) {
V_362 . V_372 = 0 ;
V_362 . V_375 = V_376 ;
V_362 . V_45 |= V_371 | V_374 ;
F_147 ( V_8 , V_145 ) ;
}
goto V_395;
}
V_362 . V_372 = 1 ;
V_362 . V_45 |= V_371 ;
if ( ! ( V_8 -> V_151 || V_8 -> V_396 ) &&
strcmp ( V_355 -> V_357 . V_145 . V_388 , L_34 ) )
goto V_397;
V_152 = F_148 ( V_355 -> V_357 . V_145 . V_388 ) ;
if ( V_152 == NULL && strcmp ( V_355 -> V_357 . V_145 . V_388 , L_3 ) == 0 )
V_152 = F_148 ( V_355 -> V_357 . V_145 . V_388 ) ;
else if ( V_152 == NULL && strcmp ( V_355 -> V_357 . V_145 . V_388 , L_34 ) == 0 )
V_152 = F_148 ( V_355 -> V_357 . V_145 . V_388 ) ;
else if ( V_152 == NULL && strcmp ( V_355 -> V_357 . V_145 . V_388 , L_35 ) == 0 )
V_152 = F_148 ( V_355 -> V_357 . V_145 . V_388 ) ;
if ( V_152 == NULL ) {
F_9 ( L_36 , V_355 -> V_357 . V_145 . V_388 ) ;
V_355 -> V_357 . V_145 . V_387 = V_398 ;
V_43 = - V_359 ;
goto V_395;
}
if ( * V_145 == NULL || ( * V_145 ) -> V_152 != V_152 ) {
struct V_144 * V_399 ;
F_147 ( V_8 , V_145 ) ;
V_399 = F_136 ( sizeof( * V_399 ) , V_360 ) ;
if ( V_399 == NULL ) {
V_43 = - V_244 ;
goto V_395;
}
memset ( V_399 , 0 , sizeof( struct V_144 ) ) ;
V_399 -> V_152 = V_152 ;
if ( V_399 -> V_152 )
V_399 -> V_400 =
V_399 -> V_152 -> V_401 ( V_355 -> V_357 . V_145 . V_393 ) ;
if ( V_399 -> V_400 == NULL ) {
F_73 ( V_399 ) ;
V_355 -> V_357 . V_145 . V_387 = V_402 ;
V_43 = - V_359 ;
goto V_395;
}
* V_145 = V_399 ;
}
if ( V_355 -> V_357 . V_145 . V_391 > 0 && ( * V_145 ) -> V_152 -> V_403 &&
( * V_145 ) -> V_152 -> V_403 ( V_355 -> V_357 . V_145 . V_390 ,
V_355 -> V_357 . V_145 . V_391 , V_355 -> V_357 . V_145 . V_404 ,
( * V_145 ) -> V_400 ) < 0 ) {
F_9 ( L_37 ) ;
V_355 -> V_357 . V_145 . V_387 = V_405 ;
V_43 = - V_359 ;
goto V_395;
}
V_397:
if ( V_355 -> V_357 . V_145 . V_406 ) {
V_8 -> V_150 = V_355 -> V_357 . V_145 . V_393 ;
V_362 . V_407 = V_355 -> V_357 . V_145 . V_393 ;
V_362 . V_45 |= V_408 ;
} else
V_362 . V_45 &= ~ V_408 ;
if ( V_355 -> V_357 . V_145 . V_388 != NULL ) {
memcpy ( V_362 . V_409 [ V_355 -> V_357 . V_145 . V_393 ] ,
V_355 -> V_357 . V_145 . V_390 ,
V_355 -> V_357 . V_145 . V_391 ) ;
V_362 . V_410 [ V_355 -> V_357 . V_145 . V_393 ] = V_355 -> V_357 . V_145 . V_391 ;
V_362 . V_45 |= ( 1 << V_355 -> V_357 . V_145 . V_393 ) ;
if ( strcmp ( V_355 -> V_357 . V_145 . V_388 , L_3 ) == 0 ) {
V_362 . V_45 |= V_374 ;
V_362 . V_375 = V_377 ;
} else if ( strcmp ( V_355 -> V_357 . V_145 . V_388 , L_34 ) == 0 ) {
V_362 . V_45 |= V_374 ;
V_362 . V_375 = V_411 ;
} else if ( strcmp ( V_355 -> V_357 . V_145 . V_388 , L_35 ) == 0 ) {
V_362 . V_45 |= V_374 ;
V_362 . V_375 = V_412 ;
}
}
V_395:
if ( V_8 -> V_366 )
V_8 -> V_366 ( V_8 -> V_55 , & V_362 ) ;
if ( V_8 -> V_413 &&
V_8 -> V_165 != V_232 &&
V_8 -> V_414 &&
V_8 -> V_414 ( V_8 -> V_55 ) ) {
F_9 ( L_38 ) ;
V_355 -> V_357 . V_145 . V_387 = V_415 ;
return - V_359 ;
}
return V_43 ;
}
int F_149 ( struct V_7 * V_8 , struct V_416 * V_417 )
{
struct V_354 * V_355 ;
int V_43 = 0 ;
F_35 ( & V_8 -> V_221 ) ;
if ( V_417 -> V_418 < sizeof( struct V_354 ) || ! V_417 -> V_419 ) {
V_43 = - V_359 ;
goto V_100;
}
V_355 = F_136 ( V_417 -> V_418 , V_360 ) ;
if ( V_355 == NULL ) {
V_43 = - V_244 ;
goto V_100;
}
if ( F_150 ( V_355 , V_417 -> V_419 , V_417 -> V_418 ) ) {
F_73 ( V_355 ) ;
V_43 = - V_420 ;
goto V_100;
}
switch ( V_355 -> V_421 ) {
case V_422 :
V_43 = F_144 ( V_8 , V_355 -> V_357 . V_423 . V_153 ,
V_355 -> V_357 . V_423 . V_347 ) ;
break;
case V_424 :
V_43 = F_142 ( V_8 , V_355 , V_417 -> V_418 ) ;
break;
case V_425 :
V_43 = F_145 ( V_8 , V_355 , V_417 -> V_418 ) ;
break;
case V_426 :
V_43 = F_141 ( V_8 , V_355 -> V_357 . V_427 . V_349 ,
V_355 -> V_357 . V_427 . V_428 ) ;
break;
default:
F_9 ( L_39 , V_355 -> V_421 ) ;
V_43 = - V_353 ;
break;
}
if ( V_43 == 0 && F_151 ( V_417 -> V_419 , V_355 , V_417 -> V_418 ) )
V_43 = - V_420 ;
F_73 ( V_355 ) ;
V_100:
F_37 ( & V_8 -> V_221 ) ;
return V_43 ;
}
void F_76 ( struct V_7 * V_8 )
{
union V_429 V_430 ;
V_430 . V_431 . V_432 = V_433 ;
if ( V_8 -> V_101 == V_102 )
memcpy ( V_430 . V_431 . V_434 , V_8 -> V_33 . V_70 , V_71 ) ;
else
memset ( V_430 . V_431 . V_434 , 0 , V_71 ) ;
F_152 ( V_8 -> V_55 , V_435 , & V_430 , NULL ) ;
}
