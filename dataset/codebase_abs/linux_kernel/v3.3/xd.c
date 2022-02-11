static int T_1 F_1 ( void )
{
T_2 V_1 , V_2 ;
unsigned int V_3 ;
int V_4 ;
#ifdef F_2
{
T_2 V_5 = 0 ;
for ( V_1 = 4 ; V_1 > 0 ; V_1 -- )
if ( ( ( V_6 [ V_1 ] = V_6 [ V_1 - 1 ] ) >= 0 ) && ! V_5 )
V_5 = V_1 ;
if ( ( V_6 [ 0 ] = V_5 ) )
F_3 ( V_6 ) ;
}
#endif
F_4 ( & V_7 ) ; V_7 . V_8 = V_9 ;
V_4 = - V_10 ;
if ( F_5 ( V_11 , L_1 ) )
goto V_12;
V_4 = - V_13 ;
V_14 = F_6 ( V_15 , & V_16 ) ;
if ( ! V_14 )
goto V_17;
if ( F_7 ( & V_2 , & V_3 ) ) {
F_8 ( L_2 ,
V_18 [ V_2 ] . V_19 , V_2 , V_3 ) ;
if ( ! F_9 ( V_20 , 4 , L_1 ) ) {
F_8 ( L_3 ,
V_20 ) ;
goto V_21;
}
if ( V_2 )
V_18 [ V_2 ] . F_10 ( V_3 ) ;
V_22 = F_11 ( V_18 [ V_2 ] . V_23 ) ;
F_8 ( L_4 ,
V_22 , V_22 == 1 ? L_5 : L_6 , V_24 , V_25 ) ;
}
if ( ! V_26 && V_27 ) {
V_26 = ( char * ) F_12 ( V_27 * 0x200 ) ;
if ( ! V_26 ) {
F_8 ( V_28 L_7 ) ;
goto V_29;
}
}
V_4 = - V_30 ;
if ( ! V_22 )
goto V_29;
for ( V_1 = 0 ; V_1 < V_22 ; V_1 ++ ) {
T_3 * V_31 = & V_32 [ V_1 ] ;
struct V_33 * V_34 = F_13 ( 64 ) ;
if ( ! V_34 )
goto V_35;
V_31 -> V_36 = V_1 ;
V_34 -> V_37 = V_11 ;
V_34 -> V_38 = V_1 << 6 ;
sprintf ( V_34 -> V_39 , L_8 , V_1 + 'a' ) ;
V_34 -> V_40 = & V_41 ;
V_34 -> V_42 = V_31 ;
V_34 -> V_43 = V_14 ;
F_14 ( V_34 , V_31 -> V_44 * V_31 -> V_45 * V_31 -> V_46 ) ;
F_8 ( L_9 , V_34 -> V_39 ,
V_31 -> V_45 , V_31 -> V_44 , V_31 -> V_46 ) ;
V_47 [ V_1 ] = V_34 ;
}
V_4 = - V_10 ;
if ( F_15 ( V_24 , V_48 , 0 , L_10 , NULL ) ) {
F_8 ( L_11 , V_24 ) ;
goto V_49;
}
if ( F_16 ( V_25 , L_1 ) ) {
F_8 ( L_12 , V_25 ) ;
goto V_50;
}
F_17 ( V_14 , V_27 ) ;
for ( V_1 = 0 ; V_1 < V_22 ; V_1 ++ )
F_18 ( V_47 [ V_1 ] ) ;
return 0 ;
V_50:
F_19 ( V_24 , NULL ) ;
V_49:
for ( V_1 = 0 ; V_1 < V_22 ; V_1 ++ )
F_20 ( V_47 [ V_1 ] ) ;
V_29:
if ( V_27 )
F_21 ( V_20 , 4 ) ;
if ( V_26 )
F_22 ( ( unsigned long ) V_26 ,
V_27 * 0x200 ) ;
V_21:
F_23 ( V_14 ) ;
V_17:
F_24 ( V_11 , L_1 ) ;
V_12:
return V_4 ;
V_35:
V_4 = - V_13 ;
while ( V_1 -- )
F_20 ( V_47 [ V_1 ] ) ;
goto V_29;
}
static T_2 T_1 F_7 ( T_2 * V_2 , unsigned int * V_3 )
{
int V_1 , V_51 ;
if ( V_52 )
{
* V_2 = V_53 ;
* V_3 = 0 ;
return ( 1 ) ;
}
for ( V_1 = 0 ; V_1 < F_25 ( V_54 ) ; V_1 ++ ) {
void T_4 * V_31 = F_26 ( V_54 [ V_1 ] , 0x2000 ) ;
if ( ! V_31 )
continue;
for ( V_51 = 1 ; V_51 < F_25 ( V_18 ) ; V_51 ++ ) {
const char * V_55 = V_18 [ V_51 ] . string ;
if ( F_27 ( V_31 + V_18 [ V_51 ] . V_56 , V_55 , strlen ( V_55 ) ) ) {
* V_2 = V_51 ;
V_53 = V_51 ;
* V_3 = V_54 [ V_1 ] ;
F_28 ( V_31 ) ;
return 1 ;
}
}
F_28 ( V_31 ) ;
}
return 0 ;
}
static void V_15 ( struct V_57 * V_58 )
{
struct V_59 * V_60 ;
if ( V_61 )
return;
V_60 = F_29 ( V_58 ) ;
while ( V_60 ) {
unsigned V_62 = F_30 ( V_60 ) ;
unsigned V_5 = F_31 ( V_60 ) ;
T_3 * V_34 = V_60 -> V_63 -> V_42 ;
int V_64 = - V_65 ;
int V_66 ;
if ( V_60 -> V_67 != V_68 )
goto V_69;
if ( V_62 + V_5 > F_32 ( V_60 -> V_63 ) )
goto V_69;
for ( V_66 = 0 ; ( V_66 < V_70 ) && ! V_64 ; V_66 ++ )
V_64 = F_33 ( F_34 ( V_60 ) , V_34 , V_60 -> V_71 ,
V_62 , V_5 ) ;
V_69:
if ( ! F_35 ( V_60 , V_64 ) )
V_60 = F_29 ( V_58 ) ;
}
}
static int F_36 ( struct V_72 * V_73 , struct V_74 * V_75 )
{
T_3 * V_31 = V_73 -> V_76 -> V_42 ;
V_75 -> V_44 = V_31 -> V_44 ;
V_75 -> V_46 = V_31 -> V_46 ;
V_75 -> V_45 = V_31 -> V_45 ;
return 0 ;
}
static int F_37 ( struct V_72 * V_73 , T_5 V_77 , T_6 V_78 , T_7 V_79 )
{
switch ( V_78 ) {
case V_80 :
if ( ! F_38 ( V_81 ) ) return - V_82 ;
if ( V_61 ) return - V_10 ;
V_83 = ! V_79 ;
if ( V_83 && V_26 ) {
F_22 ( ( unsigned long ) V_26 ,
V_27 * 0x200 ) ;
V_26 = NULL ;
} else if ( ! V_83 && ! V_26 ) {
V_26 = ( char * ) F_12 ( V_27 * 0x200 ) ;
if ( ! V_26 ) {
V_83 = V_84 ;
return - V_13 ;
}
}
return 0 ;
case V_85 :
return F_39 ( ! V_83 , ( long V_86 * ) V_79 ) ;
case V_87 :
return F_39 ( V_27 , ( long V_86 * ) V_79 ) ;
default:
return - V_88 ;
}
}
static int F_40 ( struct V_72 * V_73 , T_5 V_77 ,
unsigned int V_78 , unsigned long V_89 )
{
int V_90 ;
F_41 ( & V_91 ) ;
V_90 = F_37 ( V_73 , V_77 , V_78 , V_89 ) ;
F_42 ( & V_91 ) ;
return V_90 ;
}
static int F_33 ( T_2 V_92 , T_3 * V_31 , char * V_71 , T_6 V_62 , T_6 V_5 )
{
int V_93 = V_31 -> V_36 ;
T_2 V_94 [ 6 ] , V_95 [ 4 ] ;
T_8 V_96 , V_97 ;
T_2 V_98 , V_99 , V_100 , V_77 = V_101 , V_102 ;
char * * V_103 ;
register int V_1 ;
#ifdef F_43
F_8 ( L_13 , V_92 == V_104 ? L_14 : L_15 , V_93 , V_71 , V_62 , V_5 ) ;
#endif
F_44 ( & V_16 ) ;
V_100 = V_31 -> V_100 ;
if ( ! V_26 )
V_26 = ( char * ) F_12 ( V_27 * 0x200 ) ;
while ( V_5 ) {
V_102 = V_5 < V_27 ? V_5 : V_27 ;
V_96 = V_62 / V_31 -> V_46 ;
V_98 = V_96 % V_31 -> V_44 ;
V_97 = V_96 / V_31 -> V_44 ;
V_99 = V_62 % V_31 -> V_46 ;
#ifdef F_43
F_8 ( L_16 , V_93 , V_98 , V_97 , V_99 , V_102 ) ;
#endif
if ( V_26 ) {
V_77 = F_45 ( V_92 == V_104 ? V_105 : V_106 , ( T_2 * ) ( V_26 ) , V_102 * 0x200 ) ;
V_103 = & V_26 ;
for ( V_1 = 0 ; V_1 < ( V_102 * 0x200 ) ; V_1 ++ )
V_26 [ V_1 ] = V_71 [ V_1 ] ;
}
else
V_103 = & V_71 ;
F_46 ( V_94 , V_92 == V_104 ? V_107 : V_108 , V_93 , V_98 , V_97 , V_99 , V_102 & 0xFF , V_100 ) ;
switch ( F_47 ( V_94 , V_77 , ( T_2 * ) ( * V_103 ) , ( T_2 * ) ( * V_103 ) , V_95 , V_109 ) ) {
case 1 :
F_8 ( L_17 , 'a' + V_93 , ( V_92 == V_104 ? L_14 : L_15 ) ) ;
F_48 ( V_93 ) ;
F_49 ( & V_16 ) ;
return - V_65 ;
case 2 :
if ( V_95 [ 0 ] & 0x30 ) {
F_8 ( L_18 , 'a' + V_93 , ( V_92 == V_104 ? L_19 : L_20 ) ) ;
switch ( ( V_95 [ 0 ] & 0x30 ) >> 4 ) {
case 0 : F_8 ( L_21 , V_95 [ 0 ] & 0x0F ) ;
break;
case 1 : F_8 ( L_22 , V_95 [ 0 ] & 0x0F ) ;
break;
case 2 : F_8 ( L_23 , V_95 [ 0 ] & 0x0F ) ;
break;
case 3 : F_8 ( L_24 , V_95 [ 0 ] & 0x0F ) ;
break;
}
}
if ( V_95 [ 0 ] & 0x80 )
F_8 ( L_25 , ( ( V_95 [ 2 ] & 0xC0 ) << 2 ) | V_95 [ 3 ] , V_95 [ 1 ] & 0x1F , V_95 [ 2 ] & 0x3F ) ;
else
F_8 ( L_26 ) ;
F_49 ( & V_16 ) ;
return - V_65 ;
}
if ( V_26 )
for ( V_1 = 0 ; V_1 < ( V_102 * 0x200 ) ; V_1 ++ )
V_71 [ V_1 ] = V_26 [ V_1 ] ;
V_5 -= V_102 , V_71 += V_102 * 0x200 , V_62 += V_102 ;
}
F_49 ( & V_16 ) ;
return 0 ;
}
static void F_48 ( T_2 V_93 )
{
T_2 V_94 [ 6 ] ;
F_46 ( V_94 , V_110 , V_93 , 0 , 0 , 0 , 0 , 0 ) ;
if ( F_47 ( V_94 , V_101 , NULL , NULL , NULL , V_109 * 8 ) )
F_8 ( L_27 , 'a' + V_93 ) ;
}
static T_9 V_48 ( int V_111 , void * V_112 )
{
if ( F_50 ( V_113 ) & V_114 ) {
#ifdef F_51
F_8 ( L_28 ) ;
#endif
F_52 ( 0 , V_115 ) ;
F_53 ( & V_116 ) ;
return V_117 ;
}
else
F_8 ( L_29 ) ;
return V_118 ;
}
static T_2 F_45 ( T_2 V_77 , T_2 * V_71 , T_6 V_5 )
{
unsigned long V_119 ;
if ( V_83 )
return ( V_101 ) ;
if ( ( ( unsigned long ) V_71 & 0xFFFF0000 ) != ( ( ( unsigned long ) V_71 + V_5 ) & 0xFFFF0000 ) ) {
#ifdef F_51
F_8 ( L_30 ) ;
#endif
return ( V_101 ) ;
}
V_119 = F_54 () ;
F_55 ( V_25 ) ;
F_56 ( V_25 ) ;
F_57 ( V_25 , V_77 ) ;
F_58 ( V_25 , ( unsigned long ) V_71 ) ;
F_59 ( V_25 , V_5 ) ;
F_60 ( V_119 ) ;
return ( V_120 ) ;
}
static T_2 * F_46 ( T_2 * V_94 , T_2 V_121 , T_2 V_93 , T_2 V_98 , T_8 V_97 , T_2 V_99 , T_2 V_5 , T_2 V_100 )
{
V_94 [ 0 ] = V_121 ;
V_94 [ 1 ] = ( ( V_93 & 0x07 ) << 5 ) | ( V_98 & 0x1F ) ;
V_94 [ 2 ] = ( ( V_97 & 0x300 ) >> 2 ) | ( V_99 & 0x3F ) ;
V_94 [ 3 ] = V_97 & 0xFF ;
V_94 [ 4 ] = V_5 ;
V_94 [ 5 ] = V_100 ;
return ( V_94 ) ;
}
static void V_9 ( unsigned long V_122 )
{
V_123 = 1 ;
F_53 ( & V_116 ) ;
}
static inline T_2 F_61 ( T_8 V_124 , T_2 V_125 , T_2 V_126 , T_7 V_127 )
{
T_7 V_128 = V_129 + V_127 ;
int V_130 ;
V_61 = 1 ;
while ( ( V_130 = ( ( F_50 ( V_124 ) & V_126 ) != V_125 ) ) && F_62 ( V_129 , V_128 ) )
F_63 ( 1 ) ;
V_61 = 0 ;
return ( V_130 ) ;
}
static inline T_6 F_64 ( void )
{
unsigned long V_125 ;
V_7 . V_131 = V_129 + 8 * V_132 ;
F_65 ( & V_7 ) ;
V_125 = F_54 () ;
F_66 ( V_25 ) ;
F_60 ( V_125 ) ;
F_67 ( & V_116 ) ;
F_68 ( & V_7 ) ;
V_61 = 0 ;
V_125 = F_54 () ;
F_55 ( V_25 ) ;
F_60 ( V_125 ) ;
if ( V_123 ) {
F_8 ( L_31 ) ;
V_123 = 0 ;
return ( 1 ) ;
}
return ( 0 ) ;
}
static T_6 F_47 ( T_2 * V_121 , T_2 V_77 , T_2 * V_133 , T_2 * V_134 , T_2 * V_95 , T_7 V_127 )
{
T_2 V_94 [ 6 ] , V_135 , V_136 = 0 ;
#ifdef F_69
F_8 ( L_32 , V_121 , V_77 , V_133 , V_134 , V_95 ) ;
#endif
F_52 ( 0 , V_137 ) ;
F_52 ( V_77 , V_115 ) ;
if ( F_61 ( V_113 , V_138 , V_138 , V_127 ) )
return ( 1 ) ;
while ( ! V_136 ) {
if ( F_61 ( V_113 , V_139 , V_139 , V_127 ) )
return ( 1 ) ;
switch ( F_50 ( V_113 ) & ( V_140 | V_141 ) ) {
case 0 :
if ( V_77 == V_120 ) {
if ( F_64 () )
return ( 1 ) ;
} else
F_52 ( V_134 ? * V_134 ++ : 0 , V_142 ) ;
break;
case V_141 :
if ( V_77 == V_120 ) {
if ( F_64 () )
return ( 1 ) ;
} else
if ( V_133 )
* V_133 ++ = F_50 ( V_142 ) ;
else
F_50 ( V_142 ) ;
break;
case V_140 :
F_52 ( V_121 ? * V_121 ++ : 0 , V_142 ) ;
break;
case V_140 | V_141 :
V_136 = 1 ;
break;
}
}
V_135 = F_50 ( V_142 ) ;
if ( F_61 ( V_113 , 0 , V_138 , V_127 ) )
return ( 1 ) ;
if ( V_135 & V_143 ) {
F_46 ( V_94 , V_144 , ( V_135 & V_145 ) >> 5 , 0 , 0 , 0 , 0 , 0 ) ;
if ( F_47 ( V_94 , 0 , V_95 , NULL , NULL , V_109 ) )
F_8 ( L_33 ) ;
}
#ifdef F_69
F_8 ( L_34 , V_135 ) ;
#endif
return ( V_135 & V_143 ) ;
}
static T_2 T_1 F_11 ( void (* V_23)( T_2 V_93 ) )
{
T_2 V_94 [ 6 ] , V_1 , V_5 = 0 ;
for ( V_1 = 0 ; V_1 < V_146 ; V_1 ++ ) {
F_46 ( V_94 , V_147 , V_1 , 0 , 0 , 0 , 0 , 0 ) ;
if ( ! F_47 ( V_94 , V_101 , NULL , NULL , NULL , V_109 * 8 ) ) {
F_70 ( V_148 ) ;
V_23 ( V_5 ) ;
V_5 ++ ;
F_70 ( V_148 ) ;
}
}
return ( V_5 ) ;
}
static void T_1 F_71 ( T_2 V_93 )
{
V_32 [ V_93 ] . V_44 = ( T_2 ) ( V_149 [ 3 * V_93 + 1 ] ) ;
V_32 [ V_93 ] . V_45 = ( T_8 ) ( V_149 [ 3 * V_93 ] ) ;
V_32 [ V_93 ] . V_46 = ( T_2 ) ( V_149 [ 3 * V_93 + 2 ] ) ;
}
static void T_1 F_72 ( unsigned int V_3 )
{
switch ( V_3 ) {
case 0x00000 :
case 0xC8000 : break;
case 0xCA000 : V_20 = 0x324 ;
case 0xD0000 :
case 0xD8000 : break;
default: F_8 ( L_35 , V_3 ) ;
break;
}
V_27 = 0x01 ;
F_52 ( 0 , V_150 ) ;
}
static void T_1 F_73 ( T_2 V_93 )
{
static T_8 V_151 [] [ 4 ] = {
{ 0x200 , 8 , 0x200 , 0x100 } ,
{ 0x267 , 2 , 0x267 , 0x267 } ,
{ 0x264 , 4 , 0x264 , 0x80 } ,
{ 0x132 , 4 , 0x132 , 0x0 } ,
{ 0x132 , 2 , 0x80 , 0x132 } ,
{ 0x177 , 8 , 0x177 , 0x0 } ,
{ 0x132 , 8 , 0x84 , 0x0 } ,
{} ,
{ 0x132 , 6 , 0x80 , 0x100 } ,
{ 0x200 , 6 , 0x100 , 0x100 } ,
{ 0x264 , 2 , 0x264 , 0x80 } ,
{ 0x280 , 4 , 0x280 , 0x100 } ,
{ 0x2B9 , 3 , 0x2B9 , 0x2B9 } ,
{ 0x2B9 , 5 , 0x2B9 , 0x2B9 } ,
{ 0x280 , 6 , 0x280 , 0x100 } ,
{ 0x132 , 4 , 0x132 , 0x0 } } ;
T_2 V_152 ;
V_152 = F_50 ( V_153 ) ;
V_152 = ( V_93 ? V_152 : ( V_152 >> 2 ) ) & 0x33 ;
V_152 = ( V_152 | ( V_152 >> 2 ) ) & 0x0F ;
if ( V_149 [ 3 * V_93 ] )
F_71 ( V_93 ) ;
else
if ( V_152 != 7 ) {
V_32 [ V_93 ] . V_44 = ( T_2 ) ( V_151 [ V_152 ] [ 1 ] ) ;
V_32 [ V_93 ] . V_45 = V_151 [ V_152 ] [ 0 ] ;
V_32 [ V_93 ] . V_46 = 17 ;
#if 0
xd_info[drive].rwrite = geometry_table[n][2];
xd_info[drive].precomp = geometry_table[n][3]
xd_info[drive].ecc = 0x0B;
#endif
}
else {
F_8 ( L_36 , 'a' + V_93 ) ;
return;
}
V_32 [ V_93 ] . V_100 = 5 ;
F_74 ( V_154 , V_93 , V_32 [ V_93 ] . V_44 , V_32 [ V_93 ] . V_45 , V_151 [ V_152 ] [ 2 ] , V_151 [ V_152 ] [ 3 ] , 0x0B ) ;
F_48 ( V_93 ) ;
}
static void T_1 F_75 ( T_2 V_93 )
{
T_2 V_94 [ 6 ] , V_155 [ 64 ] ;
F_46 ( V_94 , V_156 , V_93 , 0 , 0 , 0 , 0 , 0 ) ;
if ( ! F_47 ( V_94 , V_101 , V_155 , NULL , NULL , V_109 * 2 ) ) {
V_32 [ V_93 ] . V_44 = V_155 [ 0x0A ] ;
V_32 [ V_93 ] . V_45 = ( ( T_8 * ) ( V_155 ) ) [ 0x04 ] ;
V_32 [ V_93 ] . V_46 = 17 ;
if ( V_149 [ 3 * V_93 ] )
F_71 ( V_93 ) ;
#if 0
xd_info[drive].rwrite = ((u_short *) (buf + 1))[0x05];
xd_info[drive].precomp = ((u_short *) (buf + 1))[0x06];
xd_info[drive].ecc = buf[0x0F];
#endif
V_32 [ V_93 ] . V_100 = 0 ;
F_74 ( V_154 , V_93 , V_32 [ V_93 ] . V_44 , V_32 [ V_93 ] . V_45 , ( ( T_8 * ) ( V_155 + 1 ) ) [ 0x05 ] , ( ( T_8 * ) ( V_155 + 1 ) ) [ 0x06 ] , V_155 [ 0x0F ] ) ;
F_46 ( V_94 , V_157 , V_93 , 0 , 0 , 0 , 0 , 7 ) ;
if ( F_47 ( V_94 , V_101 , NULL , NULL , NULL , V_109 * 2 ) )
F_8 ( L_37 , 'a' + V_93 ) ;
}
else
F_8 ( L_38 , 'a' + V_93 ) ;
}
static void T_1 F_76 ( unsigned int V_3 )
{
switch ( V_3 ) {
case 0x00000 :
case 0xC8000 : break;
case 0xCA000 : V_20 = 0x324 ; break;
case 0xCC000 : V_20 = 0x328 ; break;
case 0xCE000 : V_20 = 0x32C ; break;
case 0xD0000 : V_20 = 0x328 ; break;
case 0xD8000 : V_20 = 0x32C ; break;
default: F_8 ( L_39 , V_3 ) ;
break;
}
V_27 = 0x01 ;
F_52 ( 0 , V_150 ) ;
F_77 ( V_148 ) ;
}
static void T_1 F_78 ( T_2 V_93 )
{
static T_8 V_151 [] [ 4 ] = {
{ 0x264 , 4 , 0x1C2 , 0x1C2 } ,
{ 0x132 , 4 , 0x099 , 0x0 } ,
{ 0x267 , 2 , 0x1C2 , 0x1C2 } ,
{ 0x267 , 4 , 0x1C2 , 0x1C2 } ,
{ 0x334 , 6 , 0x335 , 0x335 } ,
{ 0x30E , 4 , 0x30F , 0x3DC } ,
{ 0x30E , 2 , 0x30F , 0x30F } ,
{ 0x267 , 4 , 0x268 , 0x268 } ,
{ 0x3D5 , 5 , 0x3D6 , 0x3D6 } ,
{ 0x3DB , 7 , 0x3DC , 0x3DC } ,
{ 0x264 , 4 , 0x265 , 0x265 } ,
{ 0x267 , 4 , 0x268 , 0x268 } } ;
T_2 V_94 [ 6 ] , V_155 [ 0x200 ] ;
T_2 V_152 = 0 , V_158 , V_159 , V_160 ;
T_2 V_161 = ( V_18 [ V_53 ] . string [ 7 ] == '6' ) ;
V_159 = ~ ( F_50 ( 0x322 ) ) ;
if ( V_159 & 0x40 )
V_24 = 9 ;
V_158 = ( V_159 & 0x30 ) ? ( 0x04 << V_161 ) : 0 ;
F_46 ( V_94 , V_107 , V_93 , 0 , 0 , 0 , 1 , 0 ) ;
if ( ! F_47 ( V_94 , V_101 , V_155 , NULL , NULL , V_109 * 2 ) ) {
V_32 [ V_93 ] . V_44 = V_155 [ 0x1AF ] ;
V_32 [ V_93 ] . V_45 = ( ( T_8 * ) ( V_155 + 1 ) ) [ 0xD6 ] ;
V_32 [ V_93 ] . V_46 = 17 ;
if ( V_149 [ 3 * V_93 ] )
F_71 ( V_93 ) ;
#if 0
xd_info[drive].rwrite = ((u_short *) (buf))[0xD8];
xd_info[drive].wprecomp = ((u_short *) (buf))[0xDA];
xd_info[drive].ecc = buf[0x1B4];
#endif
V_32 [ V_93 ] . V_100 = V_155 [ 0x1B5 ] ;
V_160 = ! ( V_32 [ V_93 ] . V_44 ) || ! ( V_32 [ V_93 ] . V_45 ) ;
if ( V_149 [ 3 * V_93 ] ) {
F_71 ( V_93 ) ;
V_32 [ V_93 ] . V_100 = V_158 ? 7 : 5 ;
}
else if ( V_160 ) {
V_152 = ( ( ( V_159 & 0x0F ) >> ( V_93 << 1 ) ) & 0x03 ) | V_158 ;
V_32 [ V_93 ] . V_45 = V_151 [ V_152 ] [ 0 ] ;
V_32 [ V_93 ] . V_44 = ( T_2 ) ( V_151 [ V_152 ] [ 1 ] ) ;
V_32 [ V_93 ] . V_100 = V_158 ? 7 : 5 ;
#if 0
xd_info[drive].rwrite = geometry_table[n][2];
xd_info[drive].wprecomp = geometry_table[n][3];
xd_info[drive].ecc = 0x0B;
#endif
}
if ( ! V_161 ) {
if ( V_160 )
F_74 ( V_162 , V_93 , V_32 [ V_93 ] . V_44 , V_32 [ V_93 ] . V_45 ,
V_151 [ V_152 ] [ 2 ] , V_151 [ V_152 ] [ 3 ] , 0x0B ) ;
else
F_74 ( V_162 , V_93 , V_32 [ V_93 ] . V_44 , V_32 [ V_93 ] . V_45 ,
( ( T_8 * ) ( V_155 ) ) [ 0xD8 ] , ( ( T_8 * ) ( V_155 ) ) [ 0xDA ] , V_155 [ 0x1B4 ] ) ;
}
if ( V_158 & V_161 ) {
if ( ( V_32 [ V_93 ] . V_45 *= 26 ,
V_32 [ V_93 ] . V_45 /= 17 ) > 1023 )
V_32 [ V_93 ] . V_45 = 1023 ;
#if 0
xd_info[drive].rwrite *= 26;
xd_info[drive].rwrite /= 17;
xd_info[drive].wprecomp *= 26
xd_info[drive].wprecomp /= 17;
#endif
}
}
else
F_8 ( L_40 , 'a' + V_93 ) ;
}
static void T_1 F_79 ( unsigned int V_3 )
{
switch ( V_3 ) {
case 0x00000 :
case 0xC8000 : break;
case 0xD0000 : V_20 = 0x324 ; break;
case 0xD8000 : V_20 = 0x328 ; break;
case 0xE0000 : V_20 = 0x32C ; break;
default: F_8 ( L_41 , V_3 ) ;
break;
}
V_27 = 0x40 ;
F_52 ( 0 , V_150 ) ;
}
static void T_1 F_80 ( T_2 V_93 )
{
T_2 V_94 [ 6 ] , V_155 [ 0x200 ] ;
F_46 ( V_94 , V_163 , V_93 , 0 , 0 , 0 , 1 , 0 ) ;
if ( ! F_47 ( V_94 , V_101 , V_155 , NULL , NULL , V_109 * 2 ) ) {
V_32 [ V_93 ] . V_44 = V_155 [ 0x04 ] ;
V_32 [ V_93 ] . V_45 = ( V_155 [ 0x02 ] << 8 ) | V_155 [ 0x03 ] ;
V_32 [ V_93 ] . V_46 = V_155 [ 0x05 ] ;
V_32 [ V_93 ] . V_100 = 0 ;
}
else
F_8 ( L_42 , 'a' + V_93 ) ;
}
static void T_1 F_81 ( unsigned int V_3 )
{
switch ( V_3 ) {
case 0x00000 :
case 0xC8000 : break;
case 0xD0000 : V_20 = 0x324 ; break;
case 0xD8000 : V_20 = 0x328 ; break;
case 0xE0000 : V_20 = 0x32C ; break;
default: F_8 ( L_43 , V_3 ) ;
break;
}
V_27 = 0x40 ;
F_52 ( 0 , V_150 ) ;
}
static void T_1 F_82 ( T_2 V_93 )
{
F_83 ( V_93 ) ;
V_32 [ V_93 ] . V_100 = 2 ;
}
static void T_1 F_84 ( unsigned int V_3 )
{
switch ( V_3 ) {
case 0x00000 :
case 0xC8000 :
case 0xD0000 :
case 0xD2000 :
case 0xD4000 :
case 0xD6000 :
case 0xD8000 :
case 0xDA000 :
case 0xDC000 :
case 0xDE000 :
case 0xE0000 : break;
default: F_8 ( L_44 , V_3 ) ;
break;
}
V_27 = 0x01 ;
F_52 ( 0 , V_150 ) ;
F_77 ( V_148 ) ;
}
static void T_1 F_85 ( T_2 V_93 )
{
static T_8 V_151 [] [ 5 ] = {
{ 0x132 , 4 , 0x080 , 0x080 , 0x7 } ,
{ 0x132 , 4 , 0x080 , 0x080 , 0x17 } ,
{ 0x264 , 2 , 0x100 , 0x100 , 0x7 } ,
{ 0x264 , 2 , 0x100 , 0x100 , 0x17 } ,
{ 0x132 , 8 , 0x080 , 0x080 , 0x7 } ,
{ 0x132 , 8 , 0x080 , 0x080 , 0x17 } ,
{ 0x264 , 4 , 0x100 , 0x100 , 0x6 } ,
{ 0x264 , 4 , 0x100 , 0x100 , 0x17 } ,
{ 0x2BC , 5 , 0x2BC , 0x12C , 0x6 } ,
{ 0x3A5 , 4 , 0x3A5 , 0x3A5 , 0x7 } ,
{ 0x26C , 6 , 0x26C , 0x26C , 0x7 } ,
{ 0x200 , 8 , 0x200 , 0x100 , 0x17 } ,
{ 0x400 , 5 , 0x400 , 0x400 , 0x7 } ,
{ 0x400 , 6 , 0x400 , 0x400 , 0x7 } ,
{ 0x264 , 8 , 0x264 , 0x200 , 0x17 } ,
{ 0x33E , 7 , 0x33E , 0x200 , 0x7 } } ;
T_2 V_152 ;
V_152 = F_50 ( V_153 ) & 0x0F ;
if ( V_149 [ 3 * V_93 ] )
F_71 ( V_93 ) ;
else {
V_32 [ V_93 ] . V_44 = ( T_2 ) ( V_151 [ V_152 ] [ 1 ] ) ;
V_32 [ V_93 ] . V_45 = V_151 [ V_152 ] [ 0 ] ;
V_32 [ V_93 ] . V_46 = 17 ;
#if 0
xd_info[drive].rwrite = geometry_table[n][2];
xd_info[drive].precomp = geometry_table[n][3]
xd_info[drive].ecc = 0x0B;
#endif
}
V_32 [ V_93 ] . V_100 = V_151 [ V_152 ] [ 4 ] ;
F_74 ( V_164 , V_93 , V_32 [ V_93 ] . V_44 , V_32 [ V_93 ] . V_45 , V_151 [ V_152 ] [ 2 ] , V_151 [ V_152 ] [ 3 ] , 0x0B ) ;
F_48 ( V_93 ) ;
}
static void T_1 F_83 ( T_2 V_93 )
{
T_8 V_165 [] = { 0 , 0 , 0 } , V_166 [] = { 16 , 1024 , 64 } , V_167 [] = { 0 , 0 , 0 } ;
T_2 V_94 [ 6 ] , V_1 ;
if ( V_149 [ 3 * V_93 ] )
F_71 ( V_93 ) ;
else {
for ( V_1 = 0 ; V_1 < 3 ; V_1 ++ ) {
while ( V_165 [ V_1 ] != V_166 [ V_1 ] - 1 ) {
V_167 [ V_1 ] = ( V_165 [ V_1 ] + V_166 [ V_1 ] ) / 2 ;
F_46 ( V_94 , V_168 , V_93 , ( T_2 ) V_167 [ 0 ] , ( T_8 ) V_167 [ 1 ] , ( T_2 ) V_167 [ 2 ] , 0 , 0 ) ;
if ( ! F_47 ( V_94 , V_101 , NULL , NULL , NULL , V_109 * 2 ) )
V_165 [ V_1 ] = V_167 [ V_1 ] ;
else
V_166 [ V_1 ] = V_167 [ V_1 ] ;
}
V_167 [ V_1 ] = V_165 [ V_1 ] ;
}
V_32 [ V_93 ] . V_44 = ( T_2 ) V_165 [ 0 ] + 1 ;
V_32 [ V_93 ] . V_45 = ( T_8 ) V_165 [ 1 ] + 1 ;
V_32 [ V_93 ] . V_46 = ( T_2 ) V_165 [ 2 ] + 1 ;
}
V_32 [ V_93 ] . V_100 = 0 ;
}
static void T_1 F_3 ( int * V_169 )
{
switch ( V_169 [ 0 ] ) {
case 4 : if ( V_169 [ 4 ] < 0 )
V_83 = 1 ;
else if ( V_169 [ 4 ] < 8 )
V_25 = V_169 [ 4 ] ;
case 3 : if ( ( V_169 [ 3 ] > 0 ) && ( V_169 [ 3 ] <= 0x3FC ) )
V_20 = V_169 [ 3 ] ;
case 2 : if ( ( V_169 [ 2 ] > 0 ) && ( V_169 [ 2 ] < 16 ) )
V_24 = V_169 [ 2 ] ;
case 1 : V_52 = 1 ;
if ( ( V_169 [ 1 ] >= 0 ) && ( V_169 [ 1 ] < F_25 ( V_18 ) ) )
V_53 = V_169 [ 1 ] ;
case 0 : break;
default: F_8 ( L_45 ) ;
}
V_27 = 0x01 ;
}
static void T_1 F_74 ( T_2 V_121 , T_2 V_93 , T_2 V_44 , T_8 V_45 , T_8 V_170 , T_8 V_171 , T_2 V_172 )
{
T_2 V_94 [ 14 ] ;
F_46 ( V_94 , V_121 , V_93 , 0 , 0 , 0 , 0 , 0 ) ;
V_94 [ 6 ] = ( T_2 ) ( V_45 >> 8 ) & 0x03 ;
V_94 [ 7 ] = ( T_2 ) ( V_45 & 0xFF ) ;
V_94 [ 8 ] = V_44 & 0x1F ;
V_94 [ 9 ] = ( T_2 ) ( V_170 >> 8 ) & 0x03 ;
V_94 [ 10 ] = ( T_2 ) ( V_170 & 0xFF ) ;
V_94 [ 11 ] = ( T_2 ) ( V_171 >> 8 ) & 0x03 ;
V_94 [ 12 ] = ( T_2 ) ( V_171 & 0xFF ) ;
V_94 [ 13 ] = V_172 ;
if ( F_47 ( V_94 , V_101 , NULL , & V_94 [ 6 ] , NULL , V_109 * 2 ) )
F_8 ( L_46 , 'a' + V_93 ) ;
}
void F_86 ( void )
{
int V_1 ;
F_24 ( V_11 , L_1 ) ;
for ( V_1 = 0 ; V_1 < V_22 ; V_1 ++ ) {
F_87 ( V_47 [ V_1 ] ) ;
F_20 ( V_47 [ V_1 ] ) ;
}
F_23 ( V_14 ) ;
F_21 ( V_20 , 4 ) ;
if ( V_22 ) {
F_19 ( V_24 , NULL ) ;
F_88 ( V_25 ) ;
if ( V_26 )
F_22 ( ( unsigned long ) V_26 , V_27 * 0x200 ) ;
}
}
static int T_1 F_89 ( char * V_173 )
{
int V_174 [ 5 ] ;
F_90 ( V_173 , F_25 ( V_174 ) , V_174 ) ;
F_3 ( V_174 ) ;
return 1 ;
}
static int T_1 F_91 ( char * V_173 )
{
int V_1 , V_169 [ 1 + 3 * V_146 ] ;
F_90 ( V_173 , F_25 ( V_169 ) , V_169 ) ;
if ( V_169 [ 0 ] % 3 != 0 ) {
F_8 ( L_47 ) ;
return 1 ;
}
for ( V_1 = 0 ; ( V_1 < V_169 [ 0 ] ) && ( V_1 < 3 * V_146 ) ; V_1 ++ )
V_149 [ V_1 ] = V_169 [ V_1 + 1 ] ;
return 1 ;
}
