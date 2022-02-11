static void F_1 ( int V_1 , unsigned int V_2 )
{
F_2 ( V_2 & 0x0000FF , V_1 + V_3 ) ;
F_2 ( ( V_2 & 0x00FF00 ) >> 8 , V_1 + V_4 ) ;
F_2 ( ( V_2 & 0xFF0000 ) >> 16 , V_1 + V_5 ) ;
}
static T_1 unsigned int F_3 ( int V_1 , unsigned char * V_6 , unsigned int V_2 )
{
unsigned int V_7 = V_2 ;
unsigned long V_8 = 0 ;
unsigned int V_9 ;
unsigned long V_10 ;
int V_11 = V_12 ;
F_4 ( & V_13 , V_8 ) ;
while( V_2 && V_11 )
{
V_9 = F_5 ( V_1 + V_14 ) ;
if( V_15 && V_9 > 3 )
{
F_6 ( V_1 + V_16 , V_6 , V_9 >> 2 ) ;
V_6 += V_9 & 0xFC ;
V_2 -= V_9 & 0xFC ;
}
else if( V_9 > 0 )
{
V_2 -= V_9 ;
for(; V_9 > 0 ; V_9 -- )
* ( V_6 ++ ) = F_5 ( V_1 + V_16 ) ;
}
else
{
V_10 = V_17 + V_11 ;
F_7 ( & V_13 , V_8 ) ;
while( F_8 ( V_17 , V_10 ) && ( F_5 ( V_1 + V_18 ) & V_19 ) && V_11 )
if( F_5 ( V_1 + V_18 ) & V_20 )
V_11 = 0 ;
F_4 ( & V_13 , V_8 ) ;
if( F_5 ( V_1 + V_18 ) & V_19 )
V_11 = 0 ;
}
}
F_7 ( & V_13 , V_8 ) ;
return V_7 - V_2 ;
}
static T_1 unsigned int F_9 ( int V_1 , unsigned char * V_6 , unsigned int V_2 )
{
unsigned int V_7 = V_2 ;
unsigned long V_8 = 0 ;
unsigned int V_21 ;
unsigned long V_10 ;
unsigned int V_11 = V_22 ;
F_4 ( & V_13 , V_8 ) ;
while( V_2 && V_11 )
{
V_21 = V_23 - F_5 ( V_1 + V_14 ) ;
if( V_21 > V_2 )
V_21 = V_2 ;
if( V_15 && V_21 > 3 )
{
F_10 ( V_1 + V_16 , V_6 , V_21 >> 2 ) ;
V_6 += V_21 & 0xFC ;
V_2 -= V_21 & 0xFC ;
}
else if( V_21 > 0 )
{
V_2 -= V_21 ;
for(; V_21 > 0 ; V_21 -- )
F_2 ( * ( V_6 ++ ) , V_1 + V_16 ) ;
}
else
{
V_10 = V_17 + V_11 ;
F_7 ( & V_13 , V_8 ) ;
while( F_8 ( V_17 , V_10 ) && ( F_5 ( V_1 + V_18 ) & V_24 ) && V_11 )
;
F_4 ( & V_13 , V_8 ) ;
if( F_5 ( V_1 + V_18 ) & V_24 )
V_11 = 0 ;
}
}
F_7 ( & V_13 , V_8 ) ;
return V_7 - V_2 ;
}
static T_2 F_11 ( int V_25 , void * V_26 )
{
struct V_27 * V_28 = V_26 ;
int V_1 = V_28 -> V_29 ;
int V_10 ;
unsigned long V_8 = 0 ;
unsigned char V_30 , V_31 , V_32 ;
struct V_33 * V_34 ;
unsigned int V_35 = 0 ;
F_4 ( V_28 -> V_36 , V_8 ) ;
V_30 = F_5 ( V_1 + V_37 ) ;
V_31 = F_5 ( V_1 + V_18 ) ;
V_32 = F_5 ( V_1 + V_38 ) ;
F_7 ( V_28 -> V_36 , V_8 ) ;
if( V_32 & V_20 )
{
F_12 ( V_39 L_1 ) ;
V_40 -> V_41 . V_42 = V_43 ;
V_40 -> V_44 = V_45 << 16 ;
F_4 ( V_28 -> V_36 , V_8 ) ;
V_40 -> V_46 ( V_40 ) ;
F_7 ( V_28 -> V_36 , V_8 ) ;
goto V_47;
}
if( V_32 & V_48 )
{
F_12 ( V_49 L_2 , F_5 ( V_1 + V_50 ) ) ;
V_40 -> V_41 . V_42 = V_43 ;
V_40 -> V_44 = V_51 << 16 ;
F_4 ( V_28 -> V_36 , V_8 ) ;
V_40 -> V_46 ( V_40 ) ;
F_7 ( V_28 -> V_36 , V_8 ) ;
goto V_47;
}
if( V_30 & V_52 )
{
F_12 ( V_49 L_3 ) ;
V_40 -> V_41 . V_42 = V_43 ;
V_40 -> V_44 = V_51 << 16 ;
F_4 ( V_28 -> V_36 , V_8 ) ;
V_40 -> V_46 ( V_40 ) ;
F_7 ( V_28 -> V_36 , V_8 ) ;
goto V_47;
}
if( V_30 & V_53 )
{
F_12 ( V_49 L_4 ) ;
V_40 -> V_41 . V_42 = V_43 ;
V_40 -> V_44 = V_54 << 16 ;
F_4 ( V_28 -> V_36 , V_8 ) ;
V_40 -> V_46 ( V_40 ) ;
F_7 ( V_28 -> V_36 , V_8 ) ;
goto V_47;
}
if( V_31 & ( V_55 | V_56 ) )
{
F_12 ( V_49 L_5 ) ;
V_40 -> V_41 . V_42 = V_43 ;
V_40 -> V_44 = V_51 << 16 ;
F_4 ( V_28 -> V_36 , V_8 ) ;
V_40 -> V_46 ( V_40 ) ;
F_7 ( V_28 -> V_36 , V_8 ) ;
goto V_47;
}
if( V_32 & V_57 )
{
if( V_40 -> V_41 . V_42 != V_58 )
V_40 -> V_44 = V_59 << 16 ;
else
V_40 -> V_44 = ( V_40 -> V_41 . V_60 & 0xFF ) | ( ( V_40 -> V_41 . V_61 & 0xFF ) << 8 ) | ( V_62 << 16 ) ;
V_40 -> V_41 . V_42 = V_43 ;
F_4 ( V_28 -> V_36 , V_8 ) ;
V_40 -> V_46 ( V_40 ) ;
F_7 ( V_28 -> V_36 , V_8 ) ;
goto V_47;
}
switch( V_30 & V_63 )
{
case V_64 :
{
if( V_32 & V_65 )
{
V_40 -> V_41 . V_42 = V_66 ;
F_2 ( V_67 , V_1 + V_50 ) ;
F_1 ( V_1 ,
F_13 ( V_40 ) ) ;
F_2 ( V_68 | V_69 , V_1 + V_50 ) ;
F_14 (current_command,
sg, scsi_sg_count(current_command), i) {
V_35 += F_9 ( V_1 ,
F_15 ( V_34 ) ,
V_34 -> V_70 ) ;
}
if( V_35 < V_40 -> V_71 )
F_12 ( V_49 L_6 , V_35 , V_40 -> V_71 ) ;
}
break;
}
case V_72 :
{
if( V_32 & V_65 )
{
V_40 -> V_41 . V_42 = V_73 ;
F_2 ( V_67 , V_1 + V_50 ) ;
F_1 ( V_1 ,
F_13 ( V_40 ) ) ;
F_2 ( V_68 | V_69 , V_1 + V_50 ) ;
F_14 (current_command,
sg, scsi_sg_count(current_command), i) {
V_35 += F_3 ( V_1 ,
F_15 ( V_34 ) ,
V_34 -> V_70 ) ;
}
if( V_35 < V_40 -> V_71 )
F_12 ( V_49 L_7 , V_35 , V_40 -> V_71 ) ;
}
break;
}
case V_74 :
{
V_40 -> V_41 . V_42 = V_75 ;
F_12 ( V_76 L_8 ) ;
break;
}
case V_77 :
{
V_40 -> V_41 . V_42 = V_78 ;
F_2 ( V_67 , V_1 + V_50 ) ;
F_2 ( V_79 , V_1 + V_50 ) ;
break;
}
case V_80 :
case V_81 :
{
F_12 ( V_76 L_9 ) ;
break;
}
case V_82 :
{
V_40 -> V_41 . V_42 = V_83 ;
F_2 ( V_84 , V_1 + V_50 ) ;
F_2 ( V_85 , V_1 + V_50 ) ;
break;
}
case V_86 :
{
V_40 -> V_41 . V_42 = V_58 ;
V_40 -> V_41 . V_60 = F_5 ( V_1 + V_87 ) ;
V_40 -> V_41 . V_61 = F_5 ( V_1 + V_87 ) ;
if( V_40 -> V_41 . V_61 == V_88 || V_40 -> V_41 . V_61 == V_89 )
F_2 ( V_84 , V_1 + V_50 ) ;
F_2 ( V_85 , V_1 + V_50 ) ;
break;
}
}
V_47:
return V_90 ;
}
static void F_16 ( int V_1 , int V_91 )
{
F_2 ( V_92 , V_1 + V_50 ) ;
F_2 ( V_93 , V_1 + V_50 ) ;
F_2 ( 0x99 , V_1 + V_94 ) ;
F_2 ( 0x05 , V_1 + V_95 ) ;
F_2 ( 0x00 , V_1 + V_96 ) ;
F_2 ( V_97 | V_91 , V_1 + V_98 ) ;
F_2 ( V_99 | V_100 | V_101 , V_1 + V_102 ) ;
F_2 ( V_103 | V_104 | V_105 | V_106 | V_107 , V_1 + V_108 ) ;
F_2 ( 0x83 | V_109 , V_1 + V_110 ) ;
F_2 ( V_111 | V_112 , V_1 + V_113 ) ;
F_2 ( 0 , V_1 + V_114 ) ;
}
static int F_17 ( int V_1 , int V_91 )
{
int V_25 , V_115 ;
unsigned long V_10 ;
F_5 ( V_1 + V_38 ) ;
V_115 = F_18 () ;
F_16 ( V_1 , V_91 ) ;
F_2 ( V_93 , V_1 + V_50 ) ;
F_2 ( V_116 , V_1 + V_50 ) ;
F_2 ( 0x07 , V_1 + V_117 ) ;
F_2 ( 0x00 , V_1 + V_117 ) ;
V_10 = V_17 + 20 ;
while( F_8 ( V_17 , V_10 ) && ! ( F_5 ( V_1 + V_37 ) & V_20 ) )
F_19 () ;
if( F_20 ( V_10 , V_17 ) )
return 0 ;
V_25 = F_21 ( V_115 ) ;
F_16 ( V_1 , V_91 ) ;
return V_25 ;
}
void F_22 ( char * V_118 , int * V_119 )
{
int V_10 ;
if( V_120 >= V_121 )
{
F_12 ( V_49 L_10 ) ;
return;
}
if( V_119 [ 0 ] < 1 || V_119 [ 0 ] > 2 )
{
F_12 ( V_76 L_11 ) ;
F_12 ( V_76 L_12 ) ;
return;
}
for( V_10 = 0 ; V_10 < V_120 && V_10 >= 0 ; V_10 ++ )
if( V_122 [ V_10 ] . V_1 == V_119 [ 1 ] )
V_10 = - 2 ;
if( V_10 >= 0 )
{
V_122 [ V_120 ] . V_1 = V_119 [ 1 ] ;
V_122 [ V_120 ] . V_25 = ( V_119 [ 0 ] == 2 ) ? V_119 [ 2 ] : 0 ;
V_120 ++ ;
}
}
static int F_23 ( int V_1 )
{
F_2 ( V_92 , V_1 + V_50 ) ;
F_2 ( V_93 , V_1 + V_50 ) ;
if( F_5 ( V_1 + V_50 ) != V_93 )
return 0 ;
if( ! F_5 ( V_1 + V_5 ) || F_5 ( V_1 + V_5 ) == 0xFF )
return 0 ;
if( ( F_5 ( V_1 + V_18 ) & ( V_24 | V_19 | V_55 | V_56 | V_123 | V_124 ) ) != V_19 )
return 0 ;
return 1 ;
}
static void F_24 ( void )
{
int * V_1 = V_125 ;
int V_119 [ 2 ] ;
V_119 [ 0 ] = 1 ;
for(; * V_1 ; V_1 ++ ) {
if ( F_25 ( * V_1 , V_126 , V_127 ) ) {
if ( F_23 ( * V_1 ) ) {
V_119 [ 1 ] = * V_1 ;
F_22 ( NULL , V_119 ) ;
}
F_26 ( * V_1 , V_126 ) ;
}
}
}
int T_3 F_27 ( struct V_128 * V_129 )
{
unsigned long V_8 ;
struct V_27 * V_130 = NULL ;
int V_10 ;
int V_131 ;
struct V_132 * V_133 = NULL ;
#ifdef F_28
int V_119 [ 3 ] ;
V_119 [ 0 ] = 2 ;
if( V_134 [ 0 ] )
{
V_119 [ 1 ] = V_134 [ 0 ] ;
V_119 [ 2 ] = V_134 [ 1 ] ;
F_22 ( NULL , V_119 ) ;
}
if( V_135 [ 0 ] )
{
V_119 [ 1 ] = V_135 [ 0 ] ;
V_119 [ 2 ] = V_135 [ 1 ] ;
F_22 ( NULL , V_119 ) ;
}
if( V_136 [ 0 ] )
{
V_119 [ 1 ] = V_136 [ 0 ] ;
V_119 [ 2 ] = V_136 [ 1 ] ;
F_22 ( NULL , V_119 ) ;
}
if( V_137 [ 0 ] )
{
V_119 [ 1 ] = V_137 [ 0 ] ;
V_119 [ 2 ] = V_137 [ 1 ] ;
F_22 ( NULL , V_119 ) ;
}
#endif
F_12 ( V_138 L_13 , V_139 ) ;
for ( V_10 = 0 ; V_140 [ V_10 ] . V_141 != 0 ; V_10 ++ ) {
while( ( V_133 = F_29 ( NULL , V_140 [ V_10 ] . V_141 ,
V_140 [ V_10 ] . V_142 , V_133 ) ) != NULL )
{
int V_10 [ 3 ] ;
if( F_30 ( V_133 ) < 0 )
{
F_12 ( V_49 L_14 ) ;
continue;
}
if( F_31 ( V_133 ) < 0 )
{
F_12 ( V_49 L_15 ) ;
F_32 ( V_133 ) ;
continue;
}
V_10 [ 0 ] = 2 ;
V_10 [ 1 ] = F_33 ( V_133 , 0 ) ;
V_10 [ 2 ] = F_34 ( V_133 , 0 ) ;
F_12 ( V_138 L_16 ,
V_10 [ 1 ] , V_10 [ 2 ] ) ;
F_22 ( NULL , V_10 ) ;
}
}
F_24 () ;
for( V_131 = 0 , V_10 = 0 ; V_10 < V_120 ; V_10 ++ ) {
if ( ! F_25 ( V_122 [ V_10 ] . V_1 , V_126 , V_127 ) )
continue;
if ( ! F_23 ( V_122 [ V_10 ] . V_1 ) ) {
F_12 ( V_49 L_17 , V_122 [ V_10 ] . V_1 ) ;
goto V_143;
}
if ( ! V_122 [ V_10 ] . V_25 )
V_122 [ V_10 ] . V_25 = F_17 ( V_122 [ V_10 ] . V_1 , V_122 [ V_10 ] . V_91 ) ;
if ( ! V_122 [ V_10 ] . V_25 )
goto V_143;
V_130 = F_35 ( V_129 , 0 ) ;
if ( ! V_130 )
goto V_143;
if ( F_36 ( V_122 [ V_10 ] . V_25 , F_11 , 0 , V_127 , V_130 ) )
goto V_144;
F_4 ( & V_13 , V_8 ) ;
V_130 -> V_145 = V_122 [ V_10 ] . V_1 ;
V_130 -> V_29 = V_122 [ V_10 ] . V_1 ;
V_130 -> V_146 = V_126 ;
V_130 -> V_25 = V_122 [ V_10 ] . V_25 ;
V_130 -> V_147 = V_122 [ V_10 ] . V_91 ;
F_16 ( V_122 [ V_10 ] . V_1 , V_122 [ V_10 ] . V_91 ) ;
V_131 ++ ;
F_7 ( & V_13 , V_8 ) ;
continue;
V_144:
F_37 ( V_130 ) ;
V_143:
F_26 ( V_122 [ V_10 ] . V_1 , V_126 ) ;
}
return V_131 ;
}
const char * F_38 ( struct V_27 * V_148 )
{
int V_10 ;
int V_1 = V_148 -> V_29 ;
int V_25 = V_148 -> V_25 ;
int V_91 = 0 ;
int V_149 = F_5 ( V_1 + V_5 ) ;
for( V_10 = 0 ; V_10 < V_120 ; V_10 ++ )
if( V_122 [ V_10 ] . V_1 == V_1 )
V_91 = V_122 [ V_10 ] . V_91 ;
sprintf ( V_150 , L_18 , V_149 , V_1 , V_25 , V_91 , ( V_15 ) ? L_19 : L_20 ) ;
return V_150 ;
}
static int F_39 ( T_4 * V_151 , void (* F_40)( T_4 * ) )
{
int V_1 ;
unsigned long V_8 = 0 ;
int V_10 ;
V_1 = V_151 -> V_152 -> V_153 -> V_29 ;
V_40 = V_151 ;
V_40 -> V_46 = F_40 ;
V_40 -> V_41 . V_42 = V_75 ;
V_40 -> V_41 . V_60 = 0 ;
V_40 -> V_41 . V_61 = 0 ;
F_4 ( & V_13 , V_8 ) ;
F_2 ( F_41 ( V_151 ) , V_1 + V_117 ) ;
F_2 ( V_67 , V_1 + V_50 ) ;
for( V_10 = 0 ; V_10 < V_151 -> V_154 ; V_10 ++ )
F_2 ( V_151 -> V_155 [ V_10 ] , V_1 + V_87 ) ;
F_2 ( V_156 , V_1 + V_50 ) ;
F_7 ( & V_13 , V_8 ) ;
return 0 ;
}
static int F_42 ( T_4 * V_151 )
{
int V_1 ;
int V_91 = - 1 ;
int V_10 ;
unsigned long V_8 ;
F_4 ( & V_13 , V_8 ) ;
V_1 = V_151 -> V_152 -> V_153 -> V_29 ;
for( V_10 = 0 ; V_10 < V_120 && V_91 == - 1 ; V_10 ++ )
if( V_122 [ V_10 ] . V_1 == V_1 )
V_91 = V_122 [ V_10 ] . V_91 ;
F_2 ( V_92 , V_1 + V_50 ) ;
F_2 ( V_93 | V_69 , V_1 + V_50 ) ;
F_2 ( V_157 , V_1 + V_50 ) ;
F_16 ( V_1 , V_91 ) ;
F_7 ( & V_13 , V_8 ) ;
return V_158 ;
}
static int F_43 ( struct V_27 * V_159 )
{
if ( V_159 -> V_25 )
F_44 ( V_159 -> V_25 , V_159 ) ;
if ( V_159 -> V_29 && V_159 -> V_146 )
F_26 ( V_159 -> V_29 , V_159 -> V_146 ) ;
return 0 ;
}
static int F_45 ( struct V_160 * V_161 ,
struct V_162 * V_28 ,
T_5 V_163 , int * V_164 )
{
int V_165 ;
V_165 = V_163 ;
V_164 [ 0 ] = 64 ;
V_164 [ 1 ] = 32 ;
if( ( V_164 [ 2 ] = V_165 >> 11 ) > 1024 )
{
V_164 [ 0 ] = 255 ;
V_164 [ 1 ] = 63 ;
V_164 [ 2 ] = V_165 / ( 255 * 63 ) ;
}
return 0 ;
}
