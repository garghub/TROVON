static inline void F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( V_2 , F_3 ( V_2 ) + V_3 ) ;
}
static void F_4 ( const char * V_4 , int line , char * type , char * V_5 , ... )
{
T_1 args ;
char V_6 [ V_7 ] ;
va_start ( args , V_5 ) ;
vsnprintf ( V_6 , sizeof( V_6 ) , V_5 , args ) ;
va_end ( args ) ;
#ifndef F_5
F_6 ( L_1 , type , V_6 ) ;
#else
F_6 ( L_2 , type , V_4 , line , V_6 ) ;
#endif
}
static void F_7 ( const char * V_4 , int line , int V_8 , char * V_5 , ... )
{
T_1 args ;
char V_6 [ V_7 ] ;
va_start ( args , V_5 ) ;
vsnprintf ( V_6 , sizeof( V_6 ) , V_5 , args ) ;
va_end ( args ) ;
if ( V_8 & V_9 ) {
F_6 ( L_3 , V_8 , V_4 , line , V_6 ) ;
}
}
static void F_8 ( struct V_1 * V_2 )
{
T_2 * V_10 = ( T_2 * ) V_2 -> V_11 -> V_12 -> V_13 ;
V_10 -> V_14 = NULL ;
V_2 -> V_15 ( V_2 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
void (* F_10)( struct V_1 * ) )
{
#ifdef F_5
unsigned char V_16 = F_11 ( V_2 ) ;
#endif
T_2 * V_10 = ( T_2 * ) V_2 -> V_11 -> V_12 -> V_13 ;
F_12 ( V_17 ,
L_4 ,
V_2 , V_16 , V_2 -> V_11 -> V_18 , F_13 ( V_2 ) ,
F_14 ( V_2 ) , F_15 ( V_2 ) ) ;
V_2 -> V_15 = F_10 ;
if ( V_10 -> V_14 != NULL ) {
F_16 ( V_19 , L_5 ) ;
V_2 -> V_20 = V_21 << 16 ;
F_8 ( V_2 ) ;
return 0 ;
}
#if 0
if (data->ScsiInfo->stop != 0) {
nsp_msg(KERN_INFO, "suspending device. reject command.");
SCpnt->result = DID_BAD_TARGET << 16;
nsp_scsi_done(SCpnt);
return SCSI_MLQUEUE_HOST_BUSY;
}
#endif
F_17 ( V_2 ) ;
V_10 -> V_14 = V_2 ;
V_2 -> V_22 . V_23 = V_24 ;
V_2 -> V_22 . V_25 = 0 ;
V_2 -> V_22 . V_26 = V_27 ;
V_2 -> V_22 . V_28 = 0 ;
V_2 -> V_22 . V_29 = V_30 ;
F_2 ( V_2 , F_14 ( V_2 ) ) ;
if ( F_14 ( V_2 ) ) {
V_2 -> V_22 . V_31 = F_13 ( V_2 ) ;
V_2 -> V_22 . V_32 = V_33 ;
V_2 -> V_22 . V_34 = V_2 -> V_22 . V_31 -> V_35 ;
V_2 -> V_22 . V_36 = F_15 ( V_2 ) - 1 ;
} else {
V_2 -> V_22 . V_32 = NULL ;
V_2 -> V_22 . V_34 = 0 ;
V_2 -> V_22 . V_31 = NULL ;
V_2 -> V_22 . V_36 = 0 ;
}
if ( F_18 ( V_2 ) == FALSE ) {
F_12 ( V_17 , L_6 ) ;
V_2 -> V_20 = V_37 << 16 ;
F_8 ( V_2 ) ;
return 0 ;
}
#ifdef F_5
V_10 -> V_38 ++ ;
#endif
return 0 ;
}
void F_19 ( T_2 * V_10 )
{
T_3 V_39 = { . V_40 = V_41 ,
. V_42 = 0 ,
. V_43 = 0
} ;
int V_44 ;
for ( V_44 = 0 ; V_44 < F_20 ( V_10 -> V_45 ) ; V_44 ++ ) {
V_10 -> V_45 [ V_44 ] = V_39 ;
}
}
static int F_21 ( T_2 * V_10 )
{
unsigned int V_46 = V_10 -> V_47 ;
F_12 ( V_48 , L_7 , V_46 ) ;
V_10 -> V_49 = V_50 | V_51 ;
V_10 -> V_14 = NULL ;
V_10 -> V_52 = 0 ;
V_10 -> V_53 = V_54 ;
F_19 ( V_10 ) ;
F_22 ( V_46 , V_55 , V_56 ) ;
F_22 ( V_46 , V_57 , V_58 ) ;
F_23 ( V_46 , V_59 , 0 ) ;
F_23 ( V_46 , V_60 , V_54 ) ;
F_23 ( V_46 , V_61 , V_10 -> V_49 ) ;
F_23 ( V_46 , V_62 , 0 ) ;
F_23 ( V_46 , V_63 , V_64 |
V_65 |
V_66 |
V_67 ) ;
F_22 ( V_46 , V_57 , V_68 ) ;
F_23 ( V_46 , V_69 , 0 ) ;
if ( ( F_24 ( V_46 , V_70 ) & V_71 ) == 0 ) {
F_16 ( V_72 , L_8 ) ;
F_23 ( V_46 , V_69 , V_73 ) ;
}
F_23 ( V_46 , V_74 , 0 ) ;
F_23 ( V_46 , V_74 , 0 ) ;
F_23 ( V_46 , V_75 , 0 ) ;
F_23 ( V_46 , V_76 , 0 ) ;
F_23 ( V_46 , V_59 , V_77 |
V_78 |
V_79 ) ;
F_22 ( V_46 , V_55 , V_80 ) ;
F_25 ( V_10 , FALSE ) ;
return TRUE ;
}
static int F_18 ( struct V_1 * V_2 )
{
unsigned int V_81 = V_2 -> V_11 -> V_12 -> V_82 ;
unsigned int V_46 = V_2 -> V_11 -> V_12 -> V_83 ;
unsigned char V_16 = F_11 ( V_2 ) ;
T_2 * V_10 = ( T_2 * ) V_2 -> V_11 -> V_12 -> V_13 ;
int V_84 ;
unsigned char V_29 , V_85 ;
V_29 = F_24 ( V_46 , V_86 ) ;
if( V_29 != V_87 ) {
return FALSE ;
}
V_2 -> V_22 . V_29 = V_88 ;
F_23 ( V_46 , V_89 , V_90 ) ;
V_84 = 1000 ;
do {
V_85 = F_24 ( V_46 , V_91 ) ;
F_26 ( 1 ) ;
} while( ( V_85 & ( V_92 | V_93 ) ) == 0 &&
( V_84 -- != 0 ) );
if ( ! ( V_85 & V_92 ) ) {
F_23 ( V_46 , V_89 , V_94 ) ;
return FALSE ;
}
V_2 -> V_22 . V_29 = V_95 ;
F_26 ( 3 ) ;
F_23 ( V_46 , V_96 , F_27 ( V_81 ) | F_27 ( V_16 ) ) ;
F_23 ( V_46 , V_97 , V_98 | V_99 | V_100 ) ;
F_26 ( 2 ) ;
F_23 ( V_46 , V_97 , V_98 | V_99 | V_101 | V_100 ) ;
F_23 ( V_46 , V_89 , V_94 ) ;
F_23 ( V_46 , V_97 , V_98 | V_101 | V_100 ) ;
F_28 ( V_2 , 1000 / 51 ) ;
V_10 -> V_102 = 1 ;
return TRUE ;
}
static int F_29 ( struct V_1 * V_2 )
{
unsigned char V_16 = F_11 ( V_2 ) ;
T_2 * V_10 = ( T_2 * ) V_2 -> V_11 -> V_12 -> V_13 ;
T_3 * V_103 = & ( V_10 -> V_45 [ V_16 ] ) ;
struct V_104 * V_105 ;
unsigned int V_106 , V_107 ;
int V_44 ;
F_12 ( V_108 , L_9 ) ;
V_106 = V_103 -> V_42 ;
V_107 = V_103 -> V_43 ;
F_12 ( V_108 , L_10 , V_106 , V_107 ) ;
if ( ( V_10 -> V_49 & ( F_27 ( 0 ) | F_27 ( 1 ) ) ) == V_109 ) {
V_105 = V_110 ;
} else {
V_105 = V_111 ;
}
for ( V_44 = 0 ; V_105 -> V_112 != 0 ; V_44 ++ , V_105 ++ ) {
if ( V_106 >= V_105 -> V_113 &&
V_106 <= V_105 -> V_112 ) {
break;
}
}
if ( V_106 != 0 && V_105 -> V_112 == 0 ) {
F_12 ( V_108 , L_11 ) ;
V_103 -> V_42 = 0 ;
V_103 -> V_43 = 0 ;
V_103 -> V_114 = 0 ;
V_103 -> V_115 = 0 ;
return FALSE ;
}
V_103 -> V_114 = ( V_105 -> V_116 << V_117 ) |
( V_107 & V_118 ) ;
V_103 -> V_115 = V_105 -> V_119 ;
F_12 ( V_108 , L_12 , V_103 -> V_114 , V_103 -> V_115 ) ;
return TRUE ;
}
static void F_28 ( struct V_1 * V_2 , int time )
{
unsigned int V_46 = V_2 -> V_11 -> V_12 -> V_83 ;
T_2 * V_10 = ( T_2 * ) V_2 -> V_11 -> V_12 -> V_13 ;
V_10 -> V_120 = time ;
F_23 ( V_46 , V_74 , time ) ;
}
static int F_30 ( struct V_1 * V_2 , unsigned char V_8 ,
char * V_121 )
{
unsigned int V_46 = V_2 -> V_11 -> V_12 -> V_83 ;
unsigned char V_122 ;
int V_84 ;
V_84 = 100 ;
do {
V_122 = F_24 ( V_46 , V_86 ) ;
if ( V_122 == 0xff ) {
break;
}
} while ( ( -- V_84 != 0 ) && ( V_122 & V_8 ) != 0 );
if ( V_84 == 0 ) {
F_16 ( V_19 , L_13 , V_121 ) ;
}
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
unsigned char V_123 ,
unsigned char V_8 )
{
unsigned int V_46 = V_2 -> V_11 -> V_12 -> V_83 ;
int V_84 ;
unsigned char V_29 , V_124 ;
V_84 = 100 ;
do {
V_29 = F_24 ( V_46 , V_86 ) ;
if ( V_29 == 0xff ) {
return - 1 ;
}
V_124 = F_32 ( V_46 , V_125 ) ;
if ( V_124 & V_126 ) {
return 0 ;
}
if ( ( V_29 & V_8 ) != 0 && ( V_29 & V_127 ) == V_123 ) {
return 1 ;
}
} while( V_84 -- != 0 );
return - 1 ;
}
static int F_33 ( struct V_1 * V_2 , int V_29 )
{
unsigned int V_46 = V_2 -> V_11 -> V_12 -> V_83 ;
T_2 * V_10 = ( T_2 * ) V_2 -> V_11 -> V_12 -> V_13 ;
char * V_6 = V_10 -> V_128 ;
int V_129 = F_34 ( V_130 , V_10 -> V_131 ) ;
int V_32 ;
int V_132 ;
for ( V_32 = 0 ; V_129 > 0 ; V_129 -- , V_32 ++ ) {
V_132 = F_31 ( V_2 , V_29 , V_133 ) ;
if ( V_132 <= 0 ) {
F_12 ( V_134 , L_14 ) ;
return 0 ;
}
if ( V_129 == 1 && V_2 -> V_22 . V_29 == V_135 ) {
F_23 ( V_46 , V_97 , V_136 | V_137 ) ;
}
if ( V_29 & V_138 ) {
F_12 ( V_134 , L_15 ) ;
V_6 [ V_32 ] = F_24 ( V_46 , V_139 ) ;
} else {
F_12 ( V_134 , L_16 ) ;
F_23 ( V_46 , V_139 , V_6 [ V_32 ] ) ;
}
F_30 ( V_2 , V_140 , L_17 ) ;
}
return V_129 ;
}
static int F_35 ( struct V_1 * V_2 )
{
T_2 * V_10 = ( T_2 * ) V_2 -> V_11 -> V_12 -> V_13 ;
unsigned int V_141 ;
if ( V_2 -> V_22 . V_26 != V_142 ) {
return 0 ;
}
V_141 = F_36 ( V_2 ) ;
if ( V_10 -> V_52 == V_141 ) {
return 0 ;
}
F_12 ( V_134 , L_18 ) ;
V_2 -> V_22 . V_29 = V_143 ;
F_37 ( V_2 ) ;
F_25 ( V_10 , FALSE ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
unsigned int V_46 = V_2 -> V_11 -> V_12 -> V_83 ;
unsigned int V_81 = V_2 -> V_11 -> V_12 -> V_82 ;
unsigned char V_144 ;
unsigned char V_145 , V_146 ;
int V_16 ;
F_12 ( V_147 , L_9 ) ;
V_145 = F_24 ( V_46 , V_148 ) ;
V_146 = V_145 & ( ~ F_27 ( V_81 ) ) ;
V_16 = 0 ;
while( V_146 != 0 ) {
if ( V_146 & F_27 ( 0 ) ) {
break;
}
V_146 >>= 1 ;
V_16 ++ ;
}
if ( F_11 ( V_2 ) != V_16 ) {
F_16 ( V_149 , L_19 , V_16 ) ;
}
F_30 ( V_2 , V_150 , L_20 ) ;
F_39 ( V_2 ) ;
V_144 = F_24 ( V_46 , V_97 ) & ~ ( V_99 | V_100 ) ;
F_23 ( V_46 , V_97 , V_144 ) ;
F_23 ( V_46 , V_97 , V_144 | V_136 | V_137 ) ;
return TRUE ;
}
static int F_36 ( struct V_1 * V_2 )
{
unsigned int V_46 = V_2 -> V_11 -> V_12 -> V_83 ;
unsigned int V_141 ;
unsigned int V_151 , V_152 , V_153 , V_154 ;
F_23 ( V_46 , V_63 , V_64 | V_155 ) ;
V_151 = F_24 ( V_46 , V_156 ) ;
V_152 = F_24 ( V_46 , V_156 ) ;
V_153 = F_24 ( V_46 , V_156 ) ;
V_154 = F_24 ( V_46 , V_156 ) ;
V_141 = ( V_153 << 16 ) | ( V_152 << 8 ) | ( V_151 << 0 ) ;
return V_141 ;
}
static void F_37 ( struct V_1 * V_2 )
{
unsigned int V_46 = V_2 -> V_11 -> V_12 -> V_83 ;
unsigned long V_157 = V_2 -> V_11 -> V_12 -> V_46 ;
T_2 * V_10 = ( T_2 * ) V_2 -> V_11 -> V_12 -> V_13 ;
long V_84 ;
int V_158 , V_159 ;
unsigned char V_160 , V_161 ;
V_158 = V_10 -> V_52 ;
F_12 ( V_134 , L_21 ,
V_2 , F_3 ( V_2 ) , V_158 , V_2 -> V_22 . V_32 ,
V_2 -> V_22 . V_34 , V_2 -> V_22 . V_31 ,
V_2 -> V_22 . V_36 ) ;
V_84 = 1000 ;
while ( ( V_84 -- != 0 ) &&
( V_2 -> V_22 . V_34 > 0 || V_2 -> V_22 . V_36 > 0 ) ) {
V_160 = F_24 ( V_46 , V_86 ) ;
V_160 &= V_127 ;
V_159 = F_36 ( V_2 ) - V_158 ;
if ( V_159 == 0 ) {
if ( V_160 == V_162 ) {
continue;
} else {
F_12 ( V_134 , L_22 , V_160 ) ;
break;
}
}
V_161 = F_32 ( V_46 , V_163 ) ;
if ( ( V_161 & V_164 ) == 0 &&
V_160 == V_162 ) {
continue;
}
V_159 = F_34 ( V_159 , V_2 -> V_22 . V_34 ) ;
switch ( V_10 -> V_53 ) {
case V_165 :
V_159 &= ~ ( F_27 ( 1 ) | F_27 ( 0 ) ) ;
F_40 ( V_46 , V_2 -> V_22 . V_32 , V_159 >> 2 ) ;
break;
case V_54 :
F_41 ( V_46 , V_2 -> V_22 . V_32 , V_159 ) ;
break;
case V_166 :
V_159 &= ~ ( F_27 ( 1 ) | F_27 ( 0 ) ) ;
F_42 ( V_157 , V_2 -> V_22 . V_32 , V_159 >> 2 ) ;
break;
default:
F_12 ( V_134 , L_23 ) ;
return;
}
F_1 ( V_2 , - V_159 ) ;
V_2 -> V_22 . V_32 += V_159 ;
V_2 -> V_22 . V_34 -= V_159 ;
V_158 += V_159 ;
if ( V_2 -> V_22 . V_34 == 0 &&
V_2 -> V_22 . V_36 != 0 ) {
V_2 -> V_22 . V_36 -- ;
V_2 -> V_22 . V_31 ++ ;
V_2 -> V_22 . V_32 = V_33 ;
V_2 -> V_22 . V_34 = V_2 -> V_22 . V_31 -> V_35 ;
V_84 = 1000 ;
}
}
V_10 -> V_52 = V_158 ;
if ( V_84 < 0 ) {
F_16 ( V_19 , L_24 ,
F_3 ( V_2 ) , V_2 -> V_22 . V_34 ,
V_2 -> V_22 . V_36 ) ;
}
F_12 ( V_134 , L_25 , V_158 ) ;
F_12 ( V_134 , L_26 , V_10 -> V_38 ,
F_3 ( V_2 ) ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
unsigned int V_46 = V_2 -> V_11 -> V_12 -> V_83 ;
unsigned long V_157 = V_2 -> V_11 -> V_12 -> V_46 ;
T_2 * V_10 = ( T_2 * ) V_2 -> V_11 -> V_12 -> V_13 ;
int V_84 ;
int V_158 , V_159 ;
unsigned char V_160 ;
V_158 = V_10 -> V_52 ;
F_12 ( V_134 , L_27 ,
V_10 -> V_52 , V_2 -> V_22 . V_32 , V_2 -> V_22 . V_34 ,
V_2 -> V_22 . V_31 , V_2 -> V_22 . V_36 ,
F_3 ( V_2 ) ) ;
V_84 = 1000 ;
while ( ( V_84 -- != 0 ) &&
( V_2 -> V_22 . V_34 > 0 || V_2 -> V_22 . V_36 > 0 ) ) {
V_160 = F_24 ( V_46 , V_86 ) ;
V_160 &= V_127 ;
if ( V_160 != V_167 ) {
V_159 = V_158 - F_36 ( V_2 ) ;
F_12 ( V_134 , L_28 , V_160 , V_159 ) ;
F_1 ( V_2 , V_159 ) ;
V_2 -> V_22 . V_32 -= V_159 ;
V_2 -> V_22 . V_34 += V_159 ;
V_158 -= V_159 ;
break;
}
V_159 = V_158 - F_36 ( V_2 ) ;
if ( V_159 > 0 ) {
F_12 ( V_134 , L_29 , V_158 , V_159 ) ;
continue;
}
V_159 = F_34 ( V_2 -> V_22 . V_34 , V_168 ) ;
switch ( V_10 -> V_53 ) {
case V_165 :
V_159 &= ~ ( F_27 ( 1 ) | F_27 ( 0 ) ) ;
F_44 ( V_46 , V_2 -> V_22 . V_32 , V_159 >> 2 ) ;
break;
case V_54 :
F_45 ( V_46 , V_2 -> V_22 . V_32 , V_159 ) ;
break;
case V_166 :
V_159 &= ~ ( F_27 ( 1 ) | F_27 ( 0 ) ) ;
F_46 ( V_157 , V_2 -> V_22 . V_32 , V_159 >> 2 ) ;
break;
default:
F_12 ( V_134 , L_30 ) ;
break;
}
F_1 ( V_2 , - V_159 ) ;
V_2 -> V_22 . V_32 += V_159 ;
V_2 -> V_22 . V_34 -= V_159 ;
V_158 += V_159 ;
if ( V_2 -> V_22 . V_34 == 0 &&
V_2 -> V_22 . V_36 != 0 ) {
V_2 -> V_22 . V_36 -- ;
V_2 -> V_22 . V_31 ++ ;
V_2 -> V_22 . V_32 = V_33 ;
V_2 -> V_22 . V_34 = V_2 -> V_22 . V_31 -> V_35 ;
V_84 = 1000 ;
}
}
V_10 -> V_52 = V_158 ;
if ( V_84 < 0 ) {
F_16 ( V_19 , L_31 ,
F_3 ( V_2 ) ) ;
}
F_12 ( V_134 , L_32 , V_158 ) ;
F_12 ( V_134 , L_33 , V_10 -> V_38 ,
F_3 ( V_2 ) ) ;
}
static int F_39 ( struct V_1 * V_2 )
{
unsigned int V_46 = V_2 -> V_11 -> V_12 -> V_83 ;
unsigned char V_16 = F_11 ( V_2 ) ;
T_2 * V_10 = ( T_2 * ) V_2 -> V_11 -> V_12 -> V_13 ;
T_3 * V_103 = & ( V_10 -> V_45 [ V_16 ] ) ;
F_23 ( V_46 , V_75 , V_103 -> V_114 ) ;
F_23 ( V_46 , V_76 , V_103 -> V_115 ) ;
if ( F_3 ( V_2 ) % 4 != 0 ||
F_3 ( V_2 ) <= V_169 ) {
V_10 -> V_53 = V_54 ;
} else if ( V_170 == V_171 ) {
V_10 -> V_53 = V_166 ;
} else if ( V_170 == V_172 ) {
V_10 -> V_53 = V_165 ;
} else {
V_10 -> V_53 = V_54 ;
}
F_25 ( V_10 , TRUE ) ;
V_10 -> V_52 = 0 ;
F_23 ( V_46 , V_63 , V_64 |
V_65 |
V_66 |
V_67 ) ;
return 0 ;
}
static T_4 F_47 ( int V_173 , void * V_174 )
{
unsigned int V_46 ;
unsigned char V_175 , V_176 , V_29 ;
struct V_1 * V_177 ;
unsigned char V_16 , V_18 ;
unsigned int * V_178 ;
int V_44 , V_146 ;
T_2 * V_10 ;
if ( V_174 != NULL &&
( ( V_179 * ) V_174 ) -> V_12 != NULL ) {
V_179 * V_180 = ( V_179 * ) V_174 ;
V_10 = ( T_2 * ) V_180 -> V_12 -> V_13 ;
} else {
F_12 ( V_181 , L_34 ) ;
return V_182 ;
}
V_46 = V_10 -> V_47 ;
F_22 ( V_46 , V_55 , V_183 ) ;
V_175 = F_32 ( V_46 , V_125 ) ;
if ( ( V_175 == 0xff ) || ( ( V_175 & V_184 ) == 0 ) ) {
F_22 ( V_46 , V_55 , 0 ) ;
return V_182 ;
}
V_29 = F_24 ( V_46 , V_86 ) ;
if( ( V_175 & V_126 ) != 0 ) {
V_176 = F_24 ( V_46 , V_185 ) ;
} else {
V_176 = 0 ;
}
if ( V_10 -> V_120 != 0 ) {
F_23 ( V_46 , V_74 , 0 ) ;
F_23 ( V_46 , V_74 , 0 ) ;
V_10 -> V_120 = 0 ;
}
if ( ( V_175 & V_184 ) == V_186 &&
V_10 -> V_102 == 0 ) {
F_22 ( V_46 , V_55 , V_187 ) ;
return V_188 ;
}
F_22 ( V_46 , V_55 , V_187 | V_189 ) ;
if ( ( V_175 & V_126 ) &&
( V_176 & V_190 ) ) {
F_16 ( V_149 , L_35 ) ;
F_21 ( V_10 ) ;
F_48 ( V_10 ) ;
if( V_10 -> V_14 != NULL ) {
V_177 = V_10 -> V_14 ;
V_177 -> V_20 = ( V_191 << 16 ) |
( ( V_177 -> V_22 . V_25 & 0xff ) << 8 ) |
( ( V_177 -> V_22 . V_23 & 0xff ) << 0 ) ;
F_8 ( V_177 ) ;
}
return V_188 ;
}
if ( V_10 -> V_14 == NULL ) {
F_16 ( V_149 , L_36 , V_175 , V_29 , V_176 ) ;
F_21 ( V_10 ) ;
F_48 ( V_10 ) ;
return V_188 ;
}
V_177 = V_10 -> V_14 ;
V_16 = V_177 -> V_11 -> V_192 ;
V_18 = V_177 -> V_11 -> V_18 ;
V_178 = & ( V_10 -> V_45 [ V_16 ] . V_40 ) ;
if ( V_175 & V_126 ) {
if ( V_176 & V_193 ) {
F_12 ( V_181 , L_37 ) ;
F_22 ( V_46 , V_55 , V_194 ) ;
if ( F_38 ( V_177 ) != FALSE ) {
return V_188 ;
}
}
if ( ( V_176 & ( V_195 | V_196 ) ) == 0 ) {
return V_188 ;
}
}
switch( V_177 -> V_22 . V_29 ) {
case V_95 :
if ( ( V_29 & V_197 ) == 0 ) {
if ( V_10 -> V_102 >= V_198 ) {
F_12 ( V_181 , L_38 ) ;
V_10 -> V_102 = 0 ;
F_23 ( V_46 , V_97 , 0 ) ;
V_177 -> V_20 = V_199 << 16 ;
F_8 ( V_177 ) ;
return V_188 ;
}
V_10 -> V_102 += 1 ;
F_28 ( V_177 , 1000 / 51 ) ;
return V_188 ;
}
V_10 -> V_102 = 0 ;
V_177 -> V_22 . V_29 = V_200 ;
F_23 ( V_46 , V_97 , V_100 ) ;
F_26 ( 1 ) ;
F_23 ( V_46 , V_97 , V_100 | V_136 | V_137 ) ;
return V_188 ;
break;
case V_201 :
if ( ( V_29 & V_127 ) != V_202 ) {
V_177 -> V_20 = V_203 << 16 ;
F_8 ( V_177 ) ;
return V_188 ;
}
default:
if ( ( V_175 & ( V_126 | V_204 ) ) == 0 ) {
return V_188 ;
}
break;
}
if ( ( ( V_177 -> V_22 . V_29 == V_205 ) || ( V_177 -> V_22 . V_29 == V_135 ) ) &&
( V_176 & V_196 ) != 0 ) {
F_12 ( V_181 , L_39 , V_175 , V_29 , V_176 ) ;
if ( ( V_177 -> V_22 . V_25 == V_206 ) ) {
V_177 -> V_20 = ( V_207 << 16 ) |
( ( V_177 -> V_22 . V_25 & 0xff ) << 8 ) |
( ( V_177 -> V_22 . V_23 & 0xff ) << 0 ) ;
F_12 ( V_181 , L_40 , V_177 -> V_20 ) ;
F_8 ( V_177 ) ;
return V_188 ;
}
return V_188 ;
}
if ( V_29 == 0 ) {
F_16 ( V_19 , L_41 , V_175 , V_29 , V_176 ) ;
* V_178 = V_208 ;
V_177 -> V_20 = V_209 << 16 ;
F_8 ( V_177 ) ;
return V_188 ;
}
switch ( V_29 & V_127 ) {
case V_210 :
F_12 ( V_181 , L_42 ) ;
if ( ( V_29 & V_133 ) == 0 ) {
F_12 ( V_181 , L_43 ) ;
return V_188 ;
}
V_177 -> V_22 . V_29 = V_211 ;
F_39 ( V_177 ) ;
F_12 ( V_181 , L_44 , V_177 -> V_212 ) ;
F_23 ( V_46 , V_213 , V_214 ) ;
for ( V_44 = 0 ; V_44 < V_177 -> V_212 ; V_44 ++ ) {
F_23 ( V_46 , V_215 , V_177 -> V_216 [ V_44 ] ) ;
}
F_23 ( V_46 , V_213 , V_214 | V_217 ) ;
break;
case V_167 :
F_12 ( V_181 , L_45 ) ;
V_177 -> V_22 . V_29 = V_143 ;
V_177 -> V_22 . V_26 = V_218 ;
F_43 ( V_177 ) ;
break;
case V_162 :
F_12 ( V_181 , L_46 ) ;
V_177 -> V_22 . V_29 = V_143 ;
V_177 -> V_22 . V_26 = V_142 ;
F_37 ( V_177 ) ;
break;
case V_219 :
F_35 ( V_177 ) ;
F_12 ( V_181 , L_47 ) ;
V_177 -> V_22 . V_29 = V_220 ;
V_177 -> V_22 . V_23 = F_24 ( V_46 , V_139 ) ;
F_12 ( V_181 , L_48 , V_177 -> V_22 . V_25 , V_177 -> V_22 . V_23 ) ;
break;
case V_221 :
F_12 ( V_181 , L_49 ) ;
if ( ( V_29 & V_133 ) == 0 ) {
goto V_222;
}
V_177 -> V_22 . V_29 = V_135 ;
V_10 -> V_131 = V_44 = 0 ;
V_10 -> V_128 [ V_44 ] = F_49 ( TRUE , V_18 ) ; V_44 ++ ;
if ( * V_178 == V_41 ) {
V_10 -> V_45 [ V_16 ] . V_42 = 0 ;
V_10 -> V_45 [ V_16 ] . V_43 = 0 ;
V_10 -> V_128 [ V_44 ] = V_223 ; V_44 ++ ;
V_10 -> V_128 [ V_44 ] = 3 ; V_44 ++ ;
V_10 -> V_128 [ V_44 ] = V_224 ; V_44 ++ ;
V_10 -> V_128 [ V_44 ] = 0x0c ; V_44 ++ ;
V_10 -> V_128 [ V_44 ] = 15 ; V_44 ++ ;
}
V_10 -> V_131 = V_44 ;
F_29 ( V_177 ) ;
F_50 ( V_10 ) ;
F_51 ( V_177 ) ;
break;
case V_202 :
F_35 ( V_177 ) ;
F_12 ( V_181 , L_50 ) ;
if ( ( V_29 & V_133 ) == 0 ) {
goto V_222;
}
V_177 -> V_22 . V_29 = V_205 ;
F_52 ( V_177 ) ;
if ( * V_178 == V_41 ) {
if ( V_10 -> V_131 >= 5 &&
V_10 -> V_128 [ 0 ] == V_223 &&
V_10 -> V_128 [ 1 ] == 3 &&
V_10 -> V_128 [ 2 ] == V_224 ) {
V_10 -> V_45 [ V_16 ] . V_42 = V_10 -> V_128 [ 3 ] ;
V_10 -> V_45 [ V_16 ] . V_43 = V_10 -> V_128 [ 4 ] ;
* V_178 = V_225 ;
} else {
V_10 -> V_45 [ V_16 ] . V_42 = 0 ;
V_10 -> V_45 [ V_16 ] . V_43 = 0 ;
* V_178 = V_208 ;
}
F_29 ( V_177 ) ;
}
V_146 = - 1 ;
for ( V_44 = 0 ; V_44 < V_10 -> V_131 ; V_44 ++ ) {
V_146 = V_10 -> V_128 [ V_44 ] ;
if ( V_10 -> V_128 [ V_44 ] == V_223 ) {
V_44 += ( 1 + V_10 -> V_128 [ V_44 + 1 ] ) ;
}
}
V_177 -> V_22 . V_25 = V_146 ;
F_12 ( V_181 , L_51 , V_177 -> V_22 . V_25 , V_10 -> V_131 ) ;
F_50 ( V_10 ) ;
break;
case V_226 :
default:
F_12 ( V_181 , L_52 ) ;
break;
}
return V_188 ;
V_222:
F_28 ( V_177 , 1000 / 102 ) ;
return V_188 ;
}
static struct V_227 * F_53 ( struct V_228 * V_229 )
{
struct V_227 * V_12 ;
T_2 * V_230 = & V_231 , * V_10 ;
F_12 ( V_48 , L_53 , V_229 -> V_82 ) ;
V_12 = F_54 ( & V_232 , sizeof( T_2 ) ) ;
if ( V_12 == NULL ) {
F_12 ( V_48 , L_54 ) ;
return NULL ;
}
memcpy ( V_12 -> V_13 , V_230 , sizeof( T_2 ) ) ;
V_10 = ( T_2 * ) V_12 -> V_13 ;
V_10 -> V_233 -> V_12 = V_12 ;
#ifdef F_5
V_10 -> V_38 = 0 ;
#endif
F_12 ( V_48 , L_55 , V_230 -> V_234 , ( ( T_2 * ) V_12 -> V_13 ) -> V_234 ) ;
V_12 -> V_235 = V_10 -> V_47 ;
V_12 -> V_83 = V_10 -> V_47 ;
V_12 -> V_236 = V_10 -> V_237 ;
V_12 -> V_173 = V_10 -> V_234 ;
V_12 -> V_46 = V_10 -> V_238 ;
F_55 ( & ( V_10 -> V_239 ) ) ;
snprintf ( V_10 -> V_240 ,
sizeof( V_10 -> V_240 ) ,
L_56 ,
V_12 -> V_83 , V_12 -> V_83 + V_12 -> V_236 - 1 ,
V_12 -> V_46 ,
V_12 -> V_173 ) ;
V_229 -> V_241 = V_10 -> V_240 ;
F_12 ( V_48 , L_57 ) ;
return V_12 ;
}
static const char * F_56 ( struct V_227 * V_242 )
{
T_2 * V_10 = ( T_2 * ) V_242 -> V_13 ;
return V_10 -> V_240 ;
}
static int F_57 ( struct V_243 * V_152 , struct V_227 * V_12 )
{
int V_192 ;
int V_244 ;
unsigned long V_245 ;
T_2 * V_10 ;
int V_246 ;
V_246 = V_12 -> V_247 ;
V_10 = ( T_2 * ) V_12 -> V_13 ;
F_58 ( V_152 , L_58
L_59 ) ;
F_59 ( V_152 , L_60 , V_246 ) ;
F_59 ( V_152 , L_61 , V_12 -> V_173 ) ;
F_59 ( V_152 , L_62 , V_12 -> V_83 , V_12 -> V_83 + V_12 -> V_236 - 1 ) ;
F_59 ( V_152 , L_63 , V_12 -> V_46 , V_12 -> V_46 + V_10 -> V_248 - 1 ) ;
F_59 ( V_152 , L_64 , V_12 -> V_249 ) ;
F_58 ( V_152 , L_65 ) ;
switch ( V_170 ) {
case V_250 :
F_58 ( V_152 , L_66 ) ;
break;
case V_172 :
F_58 ( V_152 , L_67 ) ;
break;
case V_171 :
F_58 ( V_152 , L_68 ) ;
break;
default:
F_58 ( V_152 , L_69 ) ;
break;
}
F_60 ( V_152 , '\n' ) ;
F_61 ( & ( V_10 -> V_239 ) , V_245 ) ;
F_59 ( V_152 , L_70 , V_10 -> V_14 ) ;
F_62 ( & ( V_10 -> V_239 ) , V_245 ) ;
F_58 ( V_152 , L_71 ) ;
for( V_192 = 0 ; V_192 < F_20 ( V_10 -> V_45 ) ; V_192 ++ ) {
F_59 ( V_152 , L_72 , V_192 ) ;
if ( V_192 == V_12 -> V_82 ) {
F_58 ( V_152 , L_73 ) ;
continue;
}
switch( V_10 -> V_45 [ V_192 ] . V_40 ) {
case V_225 :
F_58 ( V_152 , L_74 ) ;
break;
case V_208 :
F_58 ( V_152 , L_75 ) ;
break;
case V_41 :
F_58 ( V_152 , L_76 ) ;
break;
default:
F_58 ( V_152 , L_77 ) ;
break;
}
if ( V_10 -> V_45 [ V_192 ] . V_42 != 0 ) {
V_244 = 1000000 / ( V_10 -> V_45 [ V_192 ] . V_42 * 4 ) ;
F_59 ( V_152 , L_78 ,
V_244 / 1000 ,
V_244 % 1000 ,
V_10 -> V_45 [ V_192 ] . V_43
) ;
}
F_60 ( V_152 , '\n' ) ;
}
return 0 ;
}
static int F_48 ( T_2 * V_10 )
{
unsigned int V_46 = V_10 -> V_47 ;
int V_44 ;
F_22 ( V_46 , V_55 , V_56 ) ;
F_23 ( V_46 , V_97 , V_251 ) ;
F_63 ( 100 ) ;
F_23 ( V_46 , V_97 , 0 ) ;
for( V_44 = 0 ; V_44 < 5 ; V_44 ++ ) {
F_24 ( V_46 , V_185 ) ;
}
F_19 ( V_10 ) ;
F_22 ( V_46 , V_55 , V_80 ) ;
return V_252 ;
}
static int F_64 ( struct V_1 * V_2 )
{
T_2 * V_10 = ( T_2 * ) V_2 -> V_11 -> V_12 -> V_13 ;
F_12 ( V_253 , L_79 , V_2 ) ;
return F_48 ( V_10 ) ;
}
static int F_65 ( struct V_1 * V_2 )
{
T_2 * V_10 = ( T_2 * ) V_2 -> V_11 -> V_12 -> V_13 ;
F_12 ( V_253 , L_9 ) ;
F_21 ( V_10 ) ;
return V_252 ;
}
static int F_66 ( struct V_254 * V_255 )
{
V_179 * V_180 ;
T_2 * V_10 = & V_231 ;
int V_132 ;
F_12 ( V_48 , L_9 ) ;
V_180 = F_67 ( sizeof( * V_180 ) , V_256 ) ;
if ( V_180 == NULL ) { return - V_257 ; }
V_180 -> V_258 = V_255 ;
V_255 -> V_259 = V_180 ;
V_10 -> V_233 = V_180 ;
F_12 ( V_48 , L_80 , V_180 ) ;
V_132 = F_68 ( V_255 ) ;
F_12 ( V_48 , L_81 , V_255 ) ;
return V_132 ;
}
static void F_69 ( struct V_254 * V_255 )
{
F_12 ( V_48 , L_82 , V_255 ) ;
( ( V_179 * ) V_255 -> V_259 ) -> V_260 = 1 ;
F_70 ( V_255 ) ;
F_71 ( V_255 -> V_259 ) ;
V_255 -> V_259 = NULL ;
}
static int F_72 ( struct V_254 * V_258 , void * V_261 )
{
T_2 * V_10 = V_261 ;
if ( V_258 -> V_262 == 0 )
return - V_263 ;
if ( F_73 ( V_258 ) != 0 )
goto V_264;
if ( F_74 ( V_258 -> V_265 [ 2 ] ) ) {
V_258 -> V_265 [ 2 ] -> V_245 |= ( V_266 |
V_267 |
V_268 ) ;
if ( V_258 -> V_265 [ 2 ] -> V_269 < 0x1000 )
V_258 -> V_265 [ 2 ] -> V_269 = 0x1000 ;
if ( F_75 ( V_258 , V_258 -> V_265 [ 2 ] , 0 ) != 0 )
goto V_264;
if ( F_76 ( V_258 , V_258 -> V_265 [ 2 ] ,
V_258 -> V_270 ) != 0 )
goto V_264;
V_10 -> V_238 = ( unsigned long )
F_77 ( V_258 -> V_265 [ 2 ] -> V_271 ,
F_74 ( V_258 -> V_265 [ 2 ] ) ) ;
V_10 -> V_248 = F_74 ( V_258 -> V_265 [ 2 ] ) ;
}
return 0 ;
V_264:
F_12 ( V_48 , L_83 ) ;
F_78 ( V_258 ) ;
return - V_263 ;
}
static int F_68 ( struct V_254 * V_255 )
{
int V_132 ;
V_179 * V_180 = V_255 -> V_259 ;
struct V_227 * V_12 ;
T_2 * V_10 = & V_231 ;
F_12 ( V_48 , L_9 ) ;
V_255 -> V_272 |= V_273 | V_274 |
V_275 | V_276 | V_277 |
V_278 ;
V_132 = F_79 ( V_255 , F_72 , V_10 ) ;
if ( V_132 )
goto V_279;
if ( F_80 ( V_255 , F_47 ) )
goto V_279;
V_132 = F_81 ( V_255 ) ;
if ( V_132 )
goto V_279;
if ( V_280 ) {
if ( V_255 -> V_265 [ 0 ] ) {
F_82 ( V_255 -> V_265 [ 0 ] -> V_271 ,
F_74 ( V_255 -> V_265 [ 0 ] ) ) ;
}
if ( V_255 -> V_265 [ 1 ] ) {
F_82 ( V_255 -> V_265 [ 1 ] -> V_271 ,
F_74 ( V_255 -> V_265 [ 1 ] ) ) ;
}
}
V_10 -> V_47 = V_255 -> V_265 [ 0 ] -> V_271 ;
V_10 -> V_237 = F_74 ( V_255 -> V_265 [ 0 ] ) ;
V_10 -> V_234 = V_255 -> V_173 ;
F_12 ( V_48 , L_84 ,
V_10 -> V_47 , V_10 -> V_237 , V_10 -> V_234 ) ;
if( F_21 ( V_10 ) == FALSE ) {
goto V_279;
}
V_12 = F_53 ( & V_232 ) ;
if ( V_12 == NULL ) {
F_12 ( V_48 , L_85 ) ;
goto V_279;
}
V_132 = F_83 ( V_12 , NULL ) ;
if ( V_132 )
goto V_279;
F_84 ( V_12 ) ;
V_180 -> V_12 = V_12 ;
return 0 ;
V_279:
F_12 ( V_48 , L_86 ) ;
F_70 ( V_255 ) ;
return - V_263 ;
}
static void F_70 ( struct V_254 * V_255 )
{
V_179 * V_180 = V_255 -> V_259 ;
T_2 * V_10 = NULL ;
if ( V_180 -> V_12 == NULL ) {
F_16 ( V_19 , L_87 ) ;
} else {
V_10 = ( T_2 * ) V_180 -> V_12 -> V_13 ;
}
F_12 ( V_48 , L_81 , V_255 ) ;
if ( V_180 -> V_12 != NULL ) {
F_85 ( V_180 -> V_12 ) ;
}
if ( F_74 ( V_255 -> V_265 [ 2 ] ) ) {
if ( V_10 != NULL ) {
F_86 ( ( void * ) ( V_10 -> V_238 ) ) ;
}
}
F_78 ( V_255 ) ;
if ( V_180 -> V_12 != NULL ) {
F_87 ( V_180 -> V_12 ) ;
}
}
static int F_88 ( struct V_254 * V_255 )
{
V_179 * V_180 = V_255 -> V_259 ;
T_2 * V_10 ;
F_12 ( V_48 , L_88 ) ;
if ( V_180 -> V_12 != NULL ) {
F_16 ( V_72 , L_89 ) ;
V_10 = ( T_2 * ) V_180 -> V_12 -> V_13 ;
F_19 ( V_10 ) ;
}
V_180 -> V_260 = 1 ;
return 0 ;
}
static int F_89 ( struct V_254 * V_255 )
{
V_179 * V_180 = V_255 -> V_259 ;
T_2 * V_10 ;
F_12 ( V_48 , L_90 ) ;
V_180 -> V_260 = 0 ;
if ( V_180 -> V_12 != NULL ) {
F_16 ( V_72 , L_91 ) ;
V_10 = ( T_2 * ) V_180 -> V_12 -> V_13 ;
F_21 ( V_10 ) ;
F_48 ( V_10 ) ;
}
return 0 ;
}
static int T_5 F_90 ( void )
{
return F_91 ( & V_281 ) ;
}
static void T_6 F_92 ( void )
{
F_93 ( & V_281 ) ;
}
