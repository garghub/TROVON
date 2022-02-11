static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
F_2 ( V_2 , V_4 ) ;
return 0 ;
}
static T_1 F_3 ( struct V_5 * V_5 , const char T_2 * V_6 ,
T_3 V_7 , T_4 * V_8 )
{
char V_9 [ 128 ] ;
struct V_10 * V_11 = F_4 ( V_12 -> V_13 -> V_14 , V_15 ) ;
if ( ! F_5 ( V_16 ) )
return - V_17 ;
if ( V_7 == 0 )
return - V_18 ;
if ( V_7 > sizeof( V_9 ) )
V_7 = sizeof( V_9 ) ;
if ( F_6 ( V_9 , V_6 , V_7 ) )
return - V_19 ;
V_9 [ V_7 - 1 ] = 0 ;
if ( ! strcmp ( V_9 , L_1 ) )
F_7 ( V_11 ) ;
else if ( ! strcmp ( V_9 , L_2 ) )
F_8 ( V_11 ) ;
else if ( ! strcmp ( V_9 , L_3 ) )
F_9 ( V_11 ) ;
else
return - V_18 ;
return V_7 ;
}
static int F_10 ( struct V_20 * V_20 , struct V_5 * V_5 )
{
return F_11 ( V_5 , F_1 , F_12 ( V_20 ) ) ;
}
static int F_13 ( struct V_1 * V_2 , void * V_3 )
{
const struct V_21 * V_22 = V_2 -> V_23 ;
T_5 V_24 ;
T_6 V_25 ;
F_14 ( V_2 ,
L_4 ,
( unsigned long long ) V_22 -> V_7 , V_22 -> V_26 ,
V_22 -> V_27 ) ;
F_14 ( V_2 ,
L_5 ,
V_22 -> V_28 , ( unsigned long long ) V_22 -> V_29 ,
V_22 -> V_30 , V_22 -> V_31 ) ;
F_14 ( V_2 , L_6 , V_22 -> V_32 ,
V_22 -> V_33 ) ;
F_14 ( V_2 ,
L_7 ,
V_22 -> V_34 ,
V_22 -> V_35 ) ;
if ( V_22 -> V_36 )
F_14 ( V_2 , L_8 ,
V_22 -> V_36 ) ;
if ( V_22 -> V_37 & V_38 ) {
F_14 ( V_2 ,
L_9
L_10 ,
& V_22 -> V_39 ,
& V_22 -> V_40 , & V_22 -> V_41 ,
& V_22 -> V_42 ,
& V_22 -> V_43 , & V_22 -> V_44 ) ;
} else {
F_14 ( V_2 ,
L_11 ,
V_22 -> V_45 , V_22 -> V_46 ) ;
F_14 ( V_2 ,
L_12 ,
V_22 -> V_47 , V_22 -> V_48 ) ;
}
F_2 ( V_2 , L_13 ) ;
F_14 ( V_2 , L_14 ,
F_15 ( V_22 -> V_49 ) ?
V_22 -> V_50 -> V_51 : V_22 -> V_49 ) ;
F_2 ( V_2 , L_15 ) ;
F_14 ( V_2 , L_16 , V_22 -> V_52 ) ;
F_14 ( V_2 ,
L_17
L_18 ,
V_22 -> V_53 , V_22 -> V_54 ,
V_22 -> V_55 , V_22 -> V_56 ) ;
F_14 ( V_2 ,
L_19 ,
V_22 -> V_57 , V_22 -> V_58 ) ;
if ( V_22 -> V_59 ) {
unsigned int V_60 ;
F_2 ( V_2 , L_20 ) ;
for ( V_60 = 0 ; V_60 < V_22 -> V_59 ; V_60 ++ )
F_14 ( V_2 , L_21 , F_16 ( V_22 -> V_61 [ V_60 ] ) ,
V_60 == V_22 -> V_59 - 1 ? L_22 : L_23 ) ;
}
if ( V_22 -> V_62 != 0xffff )
F_14 ( V_2 , L_24 ,
V_22 -> V_62 , V_22 -> V_63 ,
V_22 -> V_64 ) ;
if ( V_22 -> V_65 != 0xffff )
F_14 ( V_2 , L_25 ,
V_22 -> V_65 , V_22 -> V_66 ,
V_22 -> V_67 ) ;
if ( V_22 -> V_68 )
F_14 ( V_2 , L_26 , V_22 -> V_68 ) ;
if ( V_22 -> V_69 )
F_14 ( V_2 , L_27 , V_22 -> V_69 ) ;
if ( V_22 -> V_70 > 1 )
F_14 ( V_2 , L_28 , V_22 -> V_70 ) ;
if ( V_22 -> V_71 >= 0 )
F_14 ( V_2 , L_29 , V_22 -> V_71 ) ;
if ( V_22 -> V_72 == V_73 )
F_2 ( V_2 , L_30 ) ;
else if ( V_22 -> V_72 == V_74 )
F_2 ( V_2 , L_31 ) ;
F_2 ( V_2 , L_32 ) ;
if ( V_22 -> V_37 & V_38 )
F_2 ( V_2 , L_33 ) ;
if ( V_22 -> V_37 & V_75 )
F_2 ( V_2 , L_34 ) ;
if ( V_22 -> V_37 & V_76 )
F_2 ( V_2 , L_35 ) ;
if ( V_22 -> V_37 & V_77 )
F_2 ( V_2 , L_36 ) ;
if ( V_22 -> V_37 & V_78 )
F_2 ( V_2 , L_37 ) ;
if ( V_22 -> V_37 & V_79 )
F_2 ( V_2 , L_38 ) ;
if ( V_22 -> V_37 & V_80 )
F_2 ( V_2 , L_39 ) ;
if ( V_22 -> V_37 & V_81 )
F_2 ( V_2 , L_40 ) ;
if ( V_22 -> V_37 & V_82 )
F_2 ( V_2 , L_41 ) ;
if ( V_22 -> V_37 & V_83 )
F_2 ( V_2 , L_42 ) ;
if ( V_22 -> V_37 & V_84 )
F_2 ( V_2 , L_43 ) ;
if ( V_22 -> V_32 ) {
if ( V_22 -> V_37 & V_85 )
F_2 ( V_2 , L_44 ) ;
else
F_2 ( V_2 , L_45 ) ;
}
#ifdef F_17
if ( V_22 -> V_37 & V_86 ) {
F_2 ( V_2 , L_46 ) ;
if ( V_22 -> V_87 )
F_14 ( V_2 , L_47 , V_22 -> V_87 ) ;
}
#endif
if ( V_22 -> V_37 & V_88 )
F_2 ( V_2 , L_48 ) ;
if ( V_22 -> V_37 & V_89 )
F_2 ( V_2 , L_49 ) ;
if ( V_22 -> V_37 & V_90 )
F_2 ( V_2 , L_50 ) ;
if ( V_22 -> V_37 & V_91 )
F_2 ( V_2 , L_51 ) ;
if ( V_22 -> V_37 & V_92 )
F_2 ( V_2 , L_52 ) ;
F_2 ( V_2 , L_22 ) ;
V_24 = V_22 -> V_93 ? F_18 () : V_22 -> V_94 ;
V_25 = V_22 -> V_95 ;
F_19 ( V_25 , V_96 ) ;
F_14 ( V_2 ,
L_53 ,
( unsigned long long ) V_22 -> V_97 ,
( unsigned long long ) V_22 -> V_98 ) ;
F_14 ( V_2 ,
L_54 ,
( unsigned long long ) F_20 ( V_22 -> V_99 ) ,
( unsigned long long ) F_20 ( V_24 ) ,
( unsigned long long ) V_25 ) ;
F_14 ( V_2 ,
L_55 ,
V_22 -> V_100 , V_22 -> V_101 ,
V_22 -> V_102 ) ;
if ( V_22 -> V_37 & V_38 ) {
F_14 ( V_2 , L_56 ,
& V_22 -> V_103 ,
& V_22 -> V_104 ) ;
} else
F_14 ( V_2 , L_57 ,
& V_22 -> V_105 , & V_22 -> V_106 ) ;
F_14 ( V_2 , L_58 ,
V_22 -> V_107 , V_22 -> V_108 ) ;
F_14 ( V_2 , L_59 , V_22 -> V_109 ) ;
F_14 ( V_2 , L_60 , V_22 -> V_110 ) ;
if ( V_22 -> V_111 [ 0 ] )
F_14 ( V_2 , L_61 , V_22 -> V_111 ) ;
else
F_2 ( V_2 , L_62 ) ;
return 0 ;
}
static int F_21 ( const char T_2 * V_112 , unsigned long V_113 ,
T_7 * V_114 )
{
int V_60 = 0 ;
* V_114 = 0 ;
for (; V_60 < V_113 ; V_60 ++ ) {
int V_115 ;
char V_116 ;
* V_114 <<= 4 ;
if ( F_22 ( V_116 , & V_112 [ V_60 ] ) )
return - V_19 ;
V_115 = F_23 ( V_116 ) ;
if ( V_115 >= 0 )
* V_114 |= V_115 ;
else
break;
}
return V_60 ;
}
static int F_24 ( const char T_2 * V_112 ,
unsigned int V_113 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_113 ; V_60 ++ ) {
char V_116 ;
if ( F_22 ( V_116 , & V_112 [ V_60 ] ) )
return - V_19 ;
switch ( V_116 ) {
case '\"' :
case '\n' :
case '\r' :
case '\t' :
case ' ' :
case '=' :
break;
default:
goto V_117;
}
}
V_117:
return V_60 ;
}
static long F_25 ( const char T_2 * V_112 , unsigned long V_113 ,
unsigned long * V_114 )
{
int V_60 ;
* V_114 = 0 ;
for ( V_60 = 0 ; V_60 < V_113 ; V_60 ++ ) {
char V_116 ;
if ( F_22 ( V_116 , & V_112 [ V_60 ] ) )
return - V_19 ;
if ( ( V_116 >= '0' ) && ( V_116 <= '9' ) ) {
* V_114 *= 10 ;
* V_114 += V_116 - '0' ;
} else
break;
}
return V_60 ;
}
static int F_26 ( const char T_2 * V_112 , unsigned int V_113 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_113 ; V_60 ++ ) {
char V_116 ;
if ( F_22 ( V_116 , & V_112 [ V_60 ] ) )
return - V_19 ;
switch ( V_116 ) {
case '\"' :
case '\n' :
case '\r' :
case '\t' :
case ' ' :
goto V_118;
default:
break;
}
}
V_118:
return V_60 ;
}
static T_1 F_27 ( const char T_2 * V_119 , struct V_21 * V_22 )
{
unsigned int V_120 = 0 ;
char V_116 ;
T_1 V_60 = 0 ;
int V_121 ;
V_22 -> V_59 = 0 ;
do {
T_7 V_122 ;
V_121 = F_21 ( & V_119 [ V_60 ] , 8 , & V_122 ) ;
if ( V_121 <= 0 )
return V_121 ;
V_22 -> V_61 [ V_120 ] = F_28 ( V_122 ) ;
if ( V_22 -> V_61 [ V_120 ] & V_123 )
V_22 -> V_37 |= V_82 ;
V_60 += V_121 ;
if ( F_22 ( V_116 , & V_119 [ V_60 ] ) )
return - V_19 ;
V_60 ++ ;
V_120 ++ ;
if ( V_120 >= V_124 )
return - V_125 ;
} while ( V_116 == ',' );
V_22 -> V_59 = V_120 ;
return V_60 ;
}
static T_1 F_29 ( struct V_5 * V_5 ,
const char T_2 * V_112 , T_3 V_7 ,
T_4 * V_126 )
{
struct V_1 * V_2 = V_5 -> V_127 ;
struct V_21 * V_22 = V_2 -> V_23 ;
int V_60 , V_128 , V_121 ;
char V_129 [ 16 ] , V_130 [ 32 ] ;
unsigned long V_115 = 0 ;
char * V_131 = NULL ;
int V_122 = 0 ;
char V_6 [ 128 ] ;
V_131 = & ( V_22 -> V_111 [ 0 ] ) ;
if ( V_7 < 1 ) {
F_30 ( L_63 ) ;
return - V_18 ;
}
V_128 = V_7 ;
V_122 = F_24 ( V_112 , V_128 ) ;
if ( V_122 < 0 ) {
F_30 ( L_64 ) ;
return V_122 ;
}
V_60 = V_122 ;
V_121 = F_26 ( & V_112 [ V_60 ] , sizeof( V_129 ) - 1 ) ;
if ( V_121 < 0 )
return V_121 ;
memset ( V_129 , 0 , sizeof( V_129 ) ) ;
if ( F_6 ( V_129 , & V_112 [ V_60 ] , V_121 ) )
return - V_19 ;
V_60 += V_121 ;
V_128 = V_7 - V_60 ;
V_121 = F_24 ( & V_112 [ V_60 ] , V_128 ) ;
if ( V_121 < 0 )
return V_121 ;
V_60 += V_121 ;
if ( V_132 ) {
T_3 V_133 = F_31 ( T_3 , V_7 , 1023 ) ;
char V_134 [ V_133 + 1 ] ;
if ( F_6 ( V_134 , V_112 , V_133 ) )
return - V_19 ;
V_134 [ V_133 ] = 0 ;
F_32 ( L_65 ,
V_129 , ( unsigned long ) V_7 , V_134 ) ;
}
if ( ! strcmp ( V_129 , L_66 ) ) {
V_121 = F_25 ( & V_112 [ V_60 ] , 10 , & V_115 ) ;
if ( V_121 < 0 )
return V_121 ;
V_60 += V_121 ;
if ( V_115 < 14 + 20 + 8 )
V_115 = 14 + 20 + 8 ;
if ( V_115 != V_22 -> V_26 ) {
V_22 -> V_26 = V_115 ;
V_22 -> V_135 = V_115 ;
}
sprintf ( V_131 , L_67 ,
V_22 -> V_26 ) ;
return V_7 ;
}
if ( ! strcmp ( V_129 , L_68 ) ) {
V_121 = F_25 ( & V_112 [ V_60 ] , 10 , & V_115 ) ;
if ( V_121 < 0 )
return V_121 ;
V_60 += V_121 ;
if ( V_115 < 14 + 20 + 8 )
V_115 = 14 + 20 + 8 ;
if ( V_115 != V_22 -> V_27 ) {
V_22 -> V_27 = V_115 ;
V_22 -> V_135 = V_115 ;
}
sprintf ( V_131 , L_69 ,
V_22 -> V_27 ) ;
return V_7 ;
}
if ( ! strcmp ( V_129 , L_70 ) ) {
V_121 = F_25 ( & V_112 [ V_60 ] , 10 , & V_115 ) ;
if ( V_121 < 0 )
return V_121 ;
V_60 += V_121 ;
if ( V_115 < 14 + 20 + 8 )
V_115 = 14 + 20 + 8 ;
if ( V_115 != V_22 -> V_26 ) {
V_22 -> V_26 = V_115 ;
V_22 -> V_27 = V_115 ;
V_22 -> V_135 = V_115 ;
}
sprintf ( V_131 , L_71 , V_22 -> V_26 ) ;
return V_7 ;
}
if ( ! strcmp ( V_129 , L_72 ) ) {
V_121 = F_25 ( & V_112 [ V_60 ] , 10 , & V_115 ) ;
if ( V_121 < 0 )
return V_121 ;
V_60 += V_121 ;
V_132 = V_115 ;
sprintf ( V_131 , L_73 , V_132 ) ;
return V_7 ;
}
if ( ! strcmp ( V_129 , L_74 ) ) {
V_121 = F_25 ( & V_112 [ V_60 ] , 10 , & V_115 ) ;
if ( V_121 < 0 )
return V_121 ;
V_60 += V_121 ;
V_22 -> V_28 = V_115 ;
sprintf ( V_131 , L_75 , V_22 -> V_28 ) ;
return V_7 ;
}
if ( ! strcmp ( V_129 , L_76 ) ) {
V_121 = F_25 ( & V_112 [ V_60 ] , 10 , & V_115 ) ;
if ( V_121 < 0 )
return V_121 ;
V_60 += V_121 ;
if ( V_115 == 0x7FFFFFFF )
V_22 -> V_29 = V_136 ;
else
V_22 -> V_29 = ( T_6 ) V_115 ;
sprintf ( V_131 , L_77 ,
( unsigned long long ) V_22 -> V_29 ) ;
return V_7 ;
}
if ( ! strcmp ( V_129 , L_78 ) ) {
V_121 = F_25 ( & V_112 [ V_60 ] , 10 , & V_115 ) ;
if ( V_121 < 0 )
return V_121 ;
V_60 += V_121 ;
if ( ! V_115 )
return V_121 ;
V_22 -> V_29 = V_22 -> V_26 * 8 * V_96 / V_115 ;
if ( V_132 )
F_33 ( L_79 , V_22 -> V_29 ) ;
sprintf ( V_131 , L_80 , V_115 ) ;
return V_7 ;
}
if ( ! strcmp ( V_129 , L_81 ) ) {
V_121 = F_25 ( & V_112 [ V_60 ] , 10 , & V_115 ) ;
if ( V_121 < 0 )
return V_121 ;
V_60 += V_121 ;
if ( ! V_115 )
return V_121 ;
V_22 -> V_29 = V_137 / V_115 ;
if ( V_132 )
F_33 ( L_79 , V_22 -> V_29 ) ;
sprintf ( V_131 , L_80 , V_115 ) ;
return V_7 ;
}
if ( ! strcmp ( V_129 , L_82 ) ) {
V_121 = F_25 ( & V_112 [ V_60 ] , 10 , & V_115 ) ;
if ( V_121 < 0 )
return V_121 ;
V_60 += V_121 ;
if ( V_115 != V_22 -> V_53 ) {
V_22 -> V_53 = V_115 ;
V_22 -> V_108 = V_115 ;
}
sprintf ( V_131 , L_83 , V_22 -> V_53 ) ;
return V_7 ;
}
if ( ! strcmp ( V_129 , L_84 ) ) {
V_121 = F_25 ( & V_112 [ V_60 ] , 10 , & V_115 ) ;
if ( V_121 < 0 )
return V_121 ;
V_60 += V_121 ;
if ( V_115 != V_22 -> V_55 ) {
V_22 -> V_55 = V_115 ;
V_22 -> V_107 = V_115 ;
}
sprintf ( V_131 , L_85 , V_22 -> V_55 ) ;
return V_7 ;
}
if ( ! strcmp ( V_129 , L_86 ) ) {
V_121 = F_25 ( & V_112 [ V_60 ] , 10 , & V_115 ) ;
if ( V_121 < 0 )
return V_121 ;
V_60 += V_121 ;
if ( V_115 != V_22 -> V_54 ) {
V_22 -> V_54 = V_115 ;
V_22 -> V_108 = V_115 ;
}
sprintf ( V_131 , L_87 , V_22 -> V_54 ) ;
return V_7 ;
}
if ( ! strcmp ( V_129 , L_88 ) ) {
V_121 = F_25 ( & V_112 [ V_60 ] , 10 , & V_115 ) ;
if ( V_121 < 0 )
return V_121 ;
V_60 += V_121 ;
if ( V_115 != V_22 -> V_56 ) {
V_22 -> V_56 = V_115 ;
V_22 -> V_107 = V_115 ;
}
sprintf ( V_131 , L_89 , V_22 -> V_56 ) ;
return V_7 ;
}
if ( ! strcmp ( V_129 , L_90 ) ) {
V_121 = F_25 ( & V_112 [ V_60 ] , 10 , & V_115 ) ;
if ( V_121 < 0 )
return V_121 ;
if ( ( V_115 > 0 ) &&
( ( V_22 -> V_72 == V_73 ) ||
! ( V_22 -> V_50 -> V_138 & V_139 ) ) )
return - V_140 ;
V_60 += V_121 ;
V_22 -> V_30 = V_115 ;
sprintf ( V_131 , L_91 , V_22 -> V_30 ) ;
return V_7 ;
}
if ( ! strcmp ( V_129 , L_92 ) ) {
V_121 = F_25 ( & V_112 [ V_60 ] , 10 , & V_115 ) ;
if ( V_121 < 0 )
return V_121 ;
V_60 += V_121 ;
V_22 -> V_7 = V_115 ;
sprintf ( V_131 , L_93 ,
( unsigned long long ) V_22 -> V_7 ) ;
return V_7 ;
}
if ( ! strcmp ( V_129 , L_94 ) ) {
V_121 = F_25 ( & V_112 [ V_60 ] , 10 , & V_115 ) ;
if ( V_121 < 0 )
return V_121 ;
V_60 += V_121 ;
if ( V_22 -> V_57 != V_115 ) {
V_22 -> V_57 = V_115 ;
V_22 -> V_102 = 0 ;
}
sprintf ( V_131 , L_95 ,
V_22 -> V_57 ) ;
return V_7 ;
}
if ( ! strcmp ( V_129 , L_96 ) ) {
V_121 = F_25 ( & V_112 [ V_60 ] , 10 , & V_115 ) ;
if ( V_121 < 0 )
return V_121 ;
V_60 += V_121 ;
if ( V_22 -> V_58 != V_115 ) {
V_22 -> V_58 = V_115 ;
V_22 -> V_101 = 0 ;
}
sprintf ( V_131 , L_97 ,
V_22 -> V_58 ) ;
return V_7 ;
}
if ( ! strcmp ( V_129 , L_98 ) ) {
V_121 = F_25 ( & V_112 [ V_60 ] , 10 , & V_115 ) ;
if ( V_121 < 0 )
return V_121 ;
V_60 += V_121 ;
if ( ( V_115 > 1 ) &&
( ( V_22 -> V_72 == V_74 ) ||
( ( V_22 -> V_72 == V_141 ) &&
( ! ( V_22 -> V_50 -> V_138 & V_139 ) ) ) ) )
return - V_140 ;
V_22 -> V_70 = V_115 < 1 ? 1 : V_115 ;
sprintf ( V_131 , L_99 , V_22 -> V_70 ) ;
return V_7 ;
}
if ( ! strcmp ( V_129 , L_100 ) ) {
V_121 = F_25 ( & V_112 [ V_60 ] , 10 , & V_115 ) ;
if ( V_121 < 0 )
return V_121 ;
V_60 += V_121 ;
if ( F_34 ( V_115 ) ) {
V_22 -> V_71 = V_115 ;
sprintf ( V_131 , L_101 , V_22 -> V_71 ) ;
if ( V_22 -> V_142 ) {
F_35 ( V_22 -> V_142 ) ;
V_22 -> V_142 = NULL ;
}
}
else
sprintf ( V_131 , L_102 ) ;
return V_7 ;
}
if ( ! strcmp ( V_129 , L_103 ) ) {
char V_143 [ 32 ] ;
memset ( V_143 , 0 , 32 ) ;
V_121 = F_26 ( & V_112 [ V_60 ] , sizeof( V_143 ) - 1 ) ;
if ( V_121 < 0 )
return V_121 ;
if ( F_6 ( V_143 , & V_112 [ V_60 ] , V_121 ) )
return - V_19 ;
V_60 += V_121 ;
if ( strcmp ( V_143 , L_104 ) == 0 ) {
V_22 -> V_72 = V_141 ;
} else if ( strcmp ( V_143 , L_105 ) == 0 ) {
if ( V_22 -> V_30 > 0 )
return - V_140 ;
V_22 -> V_72 = V_73 ;
V_22 -> V_144 = 1 ;
V_22 -> V_30 = 0 ;
} else if ( strcmp ( V_143 , L_106 ) == 0 ) {
V_22 -> V_72 = V_74 ;
V_22 -> V_144 = 1 ;
} else {
sprintf ( V_131 ,
L_107 ,
V_143 , L_108 ) ;
return V_7 ;
}
sprintf ( V_131 , L_109 , V_143 ) ;
return V_7 ;
}
if ( ! strcmp ( V_129 , L_110 ) ) {
char V_143 [ 32 ] ;
memset ( V_143 , 0 , 32 ) ;
V_121 = F_26 ( & V_112 [ V_60 ] , sizeof( V_143 ) - 1 ) ;
if ( V_121 < 0 )
return V_121 ;
if ( F_6 ( V_143 , & V_112 [ V_60 ] , V_121 ) )
return - V_19 ;
V_60 += V_121 ;
if ( strcmp ( V_143 , L_111 ) == 0 )
V_22 -> V_37 |= V_75 ;
else if ( strcmp ( V_143 , L_112 ) == 0 )
V_22 -> V_37 &= ~ V_75 ;
else if ( strcmp ( V_143 , L_113 ) == 0 )
V_22 -> V_37 |= V_77 ;
else if ( strcmp ( V_143 , L_114 ) == 0 )
V_22 -> V_37 &= ~ V_77 ;
else if ( strcmp ( V_143 , L_115 ) == 0 )
V_22 -> V_37 |= V_76 ;
else if ( strcmp ( V_143 , L_116 ) == 0 )
V_22 -> V_37 &= ~ V_76 ;
else if ( strcmp ( V_143 , L_117 ) == 0 )
V_22 -> V_37 |= V_78 ;
else if ( strcmp ( V_143 , L_118 ) == 0 )
V_22 -> V_37 &= ~ V_78 ;
else if ( strcmp ( V_143 , L_119 ) == 0 )
V_22 -> V_37 |= V_79 ;
else if ( strcmp ( V_143 , L_120 ) == 0 )
V_22 -> V_37 &= ~ V_79 ;
else if ( strcmp ( V_143 , L_121 ) == 0 )
V_22 -> V_37 |= V_88 ;
else if ( strcmp ( V_143 , L_122 ) == 0 )
V_22 -> V_37 &= ~ V_88 ;
else if ( strcmp ( V_143 , L_123 ) == 0 )
V_22 -> V_37 |= V_89 ;
else if ( strcmp ( V_143 , L_124 ) == 0 )
V_22 -> V_37 &= ~ V_89 ;
else if ( strcmp ( V_143 , L_125 ) == 0 )
V_22 -> V_37 |= V_82 ;
else if ( strcmp ( V_143 , L_126 ) == 0 )
V_22 -> V_37 &= ~ V_82 ;
else if ( strcmp ( V_143 , L_127 ) == 0 )
V_22 -> V_37 |= V_90 ;
else if ( strcmp ( V_143 , L_128 ) == 0 )
V_22 -> V_37 &= ~ V_90 ;
else if ( strcmp ( V_143 , L_129 ) == 0 )
V_22 -> V_37 |= V_91 ;
else if ( strcmp ( V_143 , L_130 ) == 0 )
V_22 -> V_37 &= ~ V_91 ;
else if ( strcmp ( V_143 , L_131 ) == 0 )
V_22 -> V_37 |= V_85 ;
else if ( strcmp ( V_143 , L_132 ) == 0 )
V_22 -> V_37 |= V_83 ;
else if ( strcmp ( V_143 , L_133 ) == 0 )
V_22 -> V_37 &= ~ V_83 ;
else if ( strcmp ( V_143 , L_134 ) == 0 )
V_22 -> V_37 |= V_84 ;
else if ( strcmp ( V_143 , L_135 ) == 0 )
V_22 -> V_37 &= ~ V_84 ;
#ifdef F_17
else if ( strcmp ( V_143 , L_136 ) == 0 )
V_22 -> V_37 |= V_86 ;
#endif
else if ( strcmp ( V_143 , L_137 ) == 0 )
V_22 -> V_37 &= ~ V_38 ;
else if ( strcmp ( V_143 , L_138 ) == 0 )
V_22 -> V_37 |= V_92 ;
else if ( strcmp ( V_143 , L_139 ) == 0 )
V_22 -> V_37 &= ~ V_92 ;
else if ( strcmp ( V_143 , L_140 ) == 0 )
V_22 -> V_37 |= V_80 ;
else if ( strcmp ( V_143 , L_141 ) == 0 )
V_22 -> V_37 &= ~ V_80 ;
else if ( strcmp ( V_143 , L_142 ) == 0 )
V_22 -> V_37 |= V_81 ;
else if ( strcmp ( V_143 , L_143 ) == 0 )
V_22 -> V_37 &= ~ V_81 ;
else {
sprintf ( V_131 ,
L_144 ,
V_143 ,
L_145
L_146
L_147
L_148
L_149
#ifdef F_17
L_150
#endif
L_151 ) ;
return V_7 ;
}
sprintf ( V_131 , L_152 , V_22 -> V_37 ) ;
return V_7 ;
}
if ( ! strcmp ( V_129 , L_153 ) || ! strcmp ( V_129 , L_154 ) ) {
V_121 = F_26 ( & V_112 [ V_60 ] , sizeof( V_22 -> V_45 ) - 1 ) ;
if ( V_121 < 0 )
return V_121 ;
if ( F_6 ( V_6 , & V_112 [ V_60 ] , V_121 ) )
return - V_19 ;
V_6 [ V_121 ] = 0 ;
if ( strcmp ( V_6 , V_22 -> V_45 ) != 0 ) {
memset ( V_22 -> V_45 , 0 , sizeof( V_22 -> V_45 ) ) ;
strncpy ( V_22 -> V_45 , V_6 , V_121 ) ;
V_22 -> V_145 = F_36 ( V_22 -> V_45 ) ;
V_22 -> V_106 = V_22 -> V_145 ;
}
if ( V_132 )
F_32 ( L_155 , V_22 -> V_45 ) ;
V_60 += V_121 ;
sprintf ( V_131 , L_156 , V_22 -> V_45 ) ;
return V_7 ;
}
if ( ! strcmp ( V_129 , L_157 ) ) {
V_121 = F_26 ( & V_112 [ V_60 ] , sizeof( V_22 -> V_46 ) - 1 ) ;
if ( V_121 < 0 )
return V_121 ;
if ( F_6 ( V_6 , & V_112 [ V_60 ] , V_121 ) )
return - V_19 ;
V_6 [ V_121 ] = 0 ;
if ( strcmp ( V_6 , V_22 -> V_46 ) != 0 ) {
memset ( V_22 -> V_46 , 0 , sizeof( V_22 -> V_46 ) ) ;
strncpy ( V_22 -> V_46 , V_6 , V_121 ) ;
V_22 -> V_146 = F_36 ( V_22 -> V_46 ) ;
V_22 -> V_106 = V_22 -> V_146 ;
}
if ( V_132 )
F_32 ( L_158 , V_22 -> V_46 ) ;
V_60 += V_121 ;
sprintf ( V_131 , L_159 , V_22 -> V_46 ) ;
return V_7 ;
}
if ( ! strcmp ( V_129 , L_160 ) ) {
V_121 = F_26 ( & V_112 [ V_60 ] , sizeof( V_6 ) - 1 ) ;
if ( V_121 < 0 )
return V_121 ;
V_22 -> V_37 |= V_38 ;
if ( F_6 ( V_6 , & V_112 [ V_60 ] , V_121 ) )
return - V_19 ;
V_6 [ V_121 ] = 0 ;
F_37 ( V_6 , - 1 , V_22 -> V_42 . V_147 , - 1 , NULL ) ;
snprintf ( V_6 , sizeof( V_6 ) , L_161 , & V_22 -> V_42 ) ;
V_22 -> V_104 = V_22 -> V_42 ;
if ( V_132 )
F_32 ( L_162 , V_6 ) ;
V_60 += V_121 ;
sprintf ( V_131 , L_163 , V_6 ) ;
return V_7 ;
}
if ( ! strcmp ( V_129 , L_164 ) ) {
V_121 = F_26 ( & V_112 [ V_60 ] , sizeof( V_6 ) - 1 ) ;
if ( V_121 < 0 )
return V_121 ;
V_22 -> V_37 |= V_38 ;
if ( F_6 ( V_6 , & V_112 [ V_60 ] , V_121 ) )
return - V_19 ;
V_6 [ V_121 ] = 0 ;
F_37 ( V_6 , - 1 , V_22 -> V_43 . V_147 , - 1 , NULL ) ;
snprintf ( V_6 , sizeof( V_6 ) , L_161 , & V_22 -> V_43 ) ;
V_22 -> V_104 = V_22 -> V_43 ;
if ( V_132 )
F_32 ( L_165 , V_6 ) ;
V_60 += V_121 ;
sprintf ( V_131 , L_166 , V_6 ) ;
return V_7 ;
}
if ( ! strcmp ( V_129 , L_167 ) ) {
V_121 = F_26 ( & V_112 [ V_60 ] , sizeof( V_6 ) - 1 ) ;
if ( V_121 < 0 )
return V_121 ;
V_22 -> V_37 |= V_38 ;
if ( F_6 ( V_6 , & V_112 [ V_60 ] , V_121 ) )
return - V_19 ;
V_6 [ V_121 ] = 0 ;
F_37 ( V_6 , - 1 , V_22 -> V_44 . V_147 , - 1 , NULL ) ;
snprintf ( V_6 , sizeof( V_6 ) , L_161 , & V_22 -> V_44 ) ;
if ( V_132 )
F_32 ( L_168 , V_6 ) ;
V_60 += V_121 ;
sprintf ( V_131 , L_169 , V_6 ) ;
return V_7 ;
}
if ( ! strcmp ( V_129 , L_170 ) ) {
V_121 = F_26 ( & V_112 [ V_60 ] , sizeof( V_6 ) - 1 ) ;
if ( V_121 < 0 )
return V_121 ;
V_22 -> V_37 |= V_38 ;
if ( F_6 ( V_6 , & V_112 [ V_60 ] , V_121 ) )
return - V_19 ;
V_6 [ V_121 ] = 0 ;
F_37 ( V_6 , - 1 , V_22 -> V_39 . V_147 , - 1 , NULL ) ;
snprintf ( V_6 , sizeof( V_6 ) , L_161 , & V_22 -> V_39 ) ;
V_22 -> V_103 = V_22 -> V_39 ;
if ( V_132 )
F_32 ( L_171 , V_6 ) ;
V_60 += V_121 ;
sprintf ( V_131 , L_172 , V_6 ) ;
return V_7 ;
}
if ( ! strcmp ( V_129 , L_173 ) ) {
V_121 = F_26 ( & V_112 [ V_60 ] , sizeof( V_22 -> V_47 ) - 1 ) ;
if ( V_121 < 0 )
return V_121 ;
if ( F_6 ( V_6 , & V_112 [ V_60 ] , V_121 ) )
return - V_19 ;
V_6 [ V_121 ] = 0 ;
if ( strcmp ( V_6 , V_22 -> V_47 ) != 0 ) {
memset ( V_22 -> V_47 , 0 , sizeof( V_22 -> V_47 ) ) ;
strncpy ( V_22 -> V_47 , V_6 , V_121 ) ;
V_22 -> V_148 = F_36 ( V_22 -> V_47 ) ;
V_22 -> V_105 = V_22 -> V_148 ;
}
if ( V_132 )
F_32 ( L_174 , V_22 -> V_47 ) ;
V_60 += V_121 ;
sprintf ( V_131 , L_175 , V_22 -> V_47 ) ;
return V_7 ;
}
if ( ! strcmp ( V_129 , L_176 ) ) {
V_121 = F_26 ( & V_112 [ V_60 ] , sizeof( V_22 -> V_48 ) - 1 ) ;
if ( V_121 < 0 )
return V_121 ;
if ( F_6 ( V_6 , & V_112 [ V_60 ] , V_121 ) )
return - V_19 ;
V_6 [ V_121 ] = 0 ;
if ( strcmp ( V_6 , V_22 -> V_48 ) != 0 ) {
memset ( V_22 -> V_48 , 0 , sizeof( V_22 -> V_48 ) ) ;
strncpy ( V_22 -> V_48 , V_6 , V_121 ) ;
V_22 -> V_149 = F_36 ( V_22 -> V_48 ) ;
V_22 -> V_105 = V_22 -> V_149 ;
}
if ( V_132 )
F_32 ( L_177 , V_22 -> V_48 ) ;
V_60 += V_121 ;
sprintf ( V_131 , L_178 , V_22 -> V_48 ) ;
return V_7 ;
}
if ( ! strcmp ( V_129 , L_179 ) ) {
V_121 = F_26 ( & V_112 [ V_60 ] , sizeof( V_130 ) - 1 ) ;
if ( V_121 < 0 )
return V_121 ;
memset ( V_130 , 0 , sizeof( V_130 ) ) ;
if ( F_6 ( V_130 , & V_112 [ V_60 ] , V_121 ) )
return - V_19 ;
if ( ! F_38 ( V_130 , V_22 -> V_52 ) )
return - V_18 ;
F_39 ( & V_22 -> V_150 [ 0 ] , V_22 -> V_52 ) ;
sprintf ( V_131 , L_180 , V_22 -> V_52 ) ;
return V_7 ;
}
if ( ! strcmp ( V_129 , L_181 ) ) {
V_121 = F_26 ( & V_112 [ V_60 ] , sizeof( V_130 ) - 1 ) ;
if ( V_121 < 0 )
return V_121 ;
memset ( V_130 , 0 , sizeof( V_130 ) ) ;
if ( F_6 ( V_130 , & V_112 [ V_60 ] , V_121 ) )
return - V_19 ;
if ( ! F_38 ( V_130 , V_22 -> V_49 ) )
return - V_18 ;
F_39 ( & V_22 -> V_150 [ 6 ] , V_22 -> V_49 ) ;
sprintf ( V_131 , L_182 , V_22 -> V_49 ) ;
return V_7 ;
}
if ( ! strcmp ( V_129 , L_183 ) ) {
F_40 ( V_22 ) ;
sprintf ( V_131 , L_184 ) ;
return V_7 ;
}
if ( ! strcmp ( V_129 , L_185 ) ) {
V_121 = F_25 ( & V_112 [ V_60 ] , 10 , & V_115 ) ;
if ( V_121 < 0 )
return V_121 ;
V_60 += V_121 ;
if ( V_115 > V_151 )
V_115 = V_151 ;
V_22 -> V_32 = V_115 ;
sprintf ( V_131 , L_186 , V_22 -> V_32 ) ;
return V_7 ;
}
#ifdef F_17
if ( ! strcmp ( V_129 , L_187 ) ) {
V_121 = F_25 ( & V_112 [ V_60 ] , 10 , & V_115 ) ;
if ( V_121 < 0 )
return V_121 ;
V_60 += V_121 ;
V_22 -> V_87 = V_115 ;
sprintf ( V_131 , L_188 , V_22 -> V_87 ) ;
return V_7 ;
}
#endif
if ( ! strcmp ( V_129 , L_189 ) ) {
V_121 = F_25 ( & V_112 [ V_60 ] , 10 , & V_115 ) ;
if ( V_121 < 0 )
return V_121 ;
V_60 += V_121 ;
V_22 -> V_33 = V_115 ;
sprintf ( V_131 , L_190 , V_22 -> V_33 ) ;
return V_7 ;
}
if ( ! strcmp ( V_129 , L_191 ) ) {
V_121 = F_25 ( & V_112 [ V_60 ] , 5 , & V_115 ) ;
if ( V_121 < 0 )
return V_121 ;
V_60 += V_121 ;
V_22 -> V_34 = V_115 ;
sprintf ( V_131 , L_192 , V_22 -> V_34 ) ;
return V_7 ;
}
if ( ! strcmp ( V_129 , L_193 ) ) {
V_121 = F_25 ( & V_112 [ V_60 ] , 5 , & V_115 ) ;
if ( V_121 < 0 )
return V_121 ;
V_60 += V_121 ;
V_22 -> V_35 = V_115 ;
sprintf ( V_131 , L_194 , V_22 -> V_35 ) ;
return V_7 ;
}
if ( ! strcmp ( V_129 , L_195 ) ) {
unsigned int V_120 , V_152 ;
V_121 = F_27 ( & V_112 [ V_60 ] , V_22 ) ;
if ( V_121 < 0 )
return V_121 ;
V_60 += V_121 ;
V_152 = sprintf ( V_131 , L_196 ) ;
for ( V_120 = 0 ; V_120 < V_22 -> V_59 ; V_120 ++ )
V_152 += sprintf ( V_131 + V_152 ,
L_21 , F_16 ( V_22 -> V_61 [ V_120 ] ) ,
V_120 == V_22 -> V_59 - 1 ? L_197 : L_198 ) ;
if ( V_22 -> V_59 && V_22 -> V_62 != 0xffff ) {
V_22 -> V_62 = 0xffff ;
V_22 -> V_65 = 0xffff ;
if ( V_132 )
F_32 ( L_199 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_129 , L_200 ) ) {
V_121 = F_25 ( & V_112 [ V_60 ] , 4 , & V_115 ) ;
if ( V_121 < 0 )
return V_121 ;
V_60 += V_121 ;
if ( V_115 <= 4095 ) {
V_22 -> V_62 = V_115 ;
if ( V_132 )
F_32 ( L_201 ) ;
if ( V_132 && V_22 -> V_59 )
F_32 ( L_202 ) ;
V_22 -> V_59 = 0 ;
sprintf ( V_131 , L_203 , V_22 -> V_62 ) ;
} else {
V_22 -> V_62 = 0xffff ;
V_22 -> V_65 = 0xffff ;
if ( V_132 )
F_32 ( L_204 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_129 , L_205 ) ) {
V_121 = F_25 ( & V_112 [ V_60 ] , 1 , & V_115 ) ;
if ( V_121 < 0 )
return V_121 ;
V_60 += V_121 ;
if ( ( V_115 <= 7 ) && ( V_22 -> V_62 != 0xffff ) ) {
V_22 -> V_63 = V_115 ;
sprintf ( V_131 , L_206 , V_22 -> V_63 ) ;
} else {
sprintf ( V_131 , L_207 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_129 , L_208 ) ) {
V_121 = F_25 ( & V_112 [ V_60 ] , 1 , & V_115 ) ;
if ( V_121 < 0 )
return V_121 ;
V_60 += V_121 ;
if ( ( V_115 <= 1 ) && ( V_22 -> V_62 != 0xffff ) ) {
V_22 -> V_64 = V_115 ;
sprintf ( V_131 , L_209 , V_22 -> V_64 ) ;
} else {
sprintf ( V_131 , L_210 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_129 , L_211 ) ) {
V_121 = F_25 ( & V_112 [ V_60 ] , 4 , & V_115 ) ;
if ( V_121 < 0 )
return V_121 ;
V_60 += V_121 ;
if ( ( V_115 <= 4095 ) && ( ( V_22 -> V_62 != 0xffff ) ) ) {
V_22 -> V_65 = V_115 ;
if ( V_132 )
F_32 ( L_212 ) ;
if ( V_132 && V_22 -> V_59 )
F_32 ( L_202 ) ;
V_22 -> V_59 = 0 ;
sprintf ( V_131 , L_213 , V_22 -> V_65 ) ;
} else {
V_22 -> V_62 = 0xffff ;
V_22 -> V_65 = 0xffff ;
if ( V_132 )
F_32 ( L_204 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_129 , L_214 ) ) {
V_121 = F_25 ( & V_112 [ V_60 ] , 1 , & V_115 ) ;
if ( V_121 < 0 )
return V_121 ;
V_60 += V_121 ;
if ( ( V_115 <= 7 ) && ( V_22 -> V_65 != 0xffff ) ) {
V_22 -> V_66 = V_115 ;
sprintf ( V_131 , L_215 , V_22 -> V_66 ) ;
} else {
sprintf ( V_131 , L_216 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_129 , L_217 ) ) {
V_121 = F_25 ( & V_112 [ V_60 ] , 1 , & V_115 ) ;
if ( V_121 < 0 )
return V_121 ;
V_60 += V_121 ;
if ( ( V_115 <= 1 ) && ( V_22 -> V_65 != 0xffff ) ) {
V_22 -> V_67 = V_115 ;
sprintf ( V_131 , L_218 , V_22 -> V_67 ) ;
} else {
sprintf ( V_131 , L_219 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_129 , L_220 ) ) {
T_7 V_153 = 0 ;
V_121 = F_21 ( & V_112 [ V_60 ] , 2 , & V_153 ) ;
if ( V_121 < 0 )
return V_121 ;
V_60 += V_121 ;
if ( V_121 == 2 ) {
V_22 -> V_68 = V_153 ;
sprintf ( V_131 , L_221 , V_22 -> V_68 ) ;
} else {
sprintf ( V_131 , L_222 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_129 , L_223 ) ) {
T_7 V_153 = 0 ;
V_121 = F_21 ( & V_112 [ V_60 ] , 2 , & V_153 ) ;
if ( V_121 < 0 )
return V_121 ;
V_60 += V_121 ;
if ( V_121 == 2 ) {
V_22 -> V_69 = V_153 ;
sprintf ( V_131 , L_224 , V_22 -> V_69 ) ;
} else {
sprintf ( V_131 , L_225 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_129 , L_226 ) ) {
V_121 = F_25 ( & V_112 [ V_60 ] , 9 , & V_115 ) ;
if ( V_121 < 0 )
return V_121 ;
V_60 += V_121 ;
V_22 -> V_36 = V_115 ;
sprintf ( V_131 , L_227 ,
V_22 -> V_36 ) ;
return V_7 ;
}
sprintf ( V_22 -> V_111 , L_228 , V_129 ) ;
return - V_18 ;
}
static int F_41 ( struct V_20 * V_20 , struct V_5 * V_5 )
{
return F_11 ( V_5 , F_13 , F_12 ( V_20 ) ) ;
}
static int F_42 ( struct V_1 * V_2 , void * V_3 )
{
struct V_154 * V_155 = V_2 -> V_23 ;
const struct V_21 * V_22 ;
F_43 ( ! V_155 ) ;
F_2 ( V_2 , L_229 ) ;
F_44 () ;
F_45 (pkt_dev, &t->if_list, list)
if ( V_22 -> V_93 )
F_14 ( V_2 , L_230 , V_22 -> V_31 ) ;
F_2 ( V_2 , L_231 ) ;
F_45 (pkt_dev, &t->if_list, list)
if ( ! V_22 -> V_93 )
F_14 ( V_2 , L_230 , V_22 -> V_31 ) ;
if ( V_155 -> V_111 [ 0 ] )
F_14 ( V_2 , L_232 , V_155 -> V_111 ) ;
else
F_2 ( V_2 , L_233 ) ;
F_46 () ;
return 0 ;
}
static T_1 F_47 ( struct V_5 * V_5 ,
const char T_2 * V_112 ,
T_3 V_7 , T_4 * V_126 )
{
struct V_1 * V_2 = V_5 -> V_127 ;
struct V_154 * V_155 = V_2 -> V_23 ;
int V_60 , V_128 , V_121 , V_156 ;
char V_129 [ 40 ] ;
char * V_131 ;
if ( V_7 < 1 ) {
return - V_18 ;
}
V_128 = V_7 ;
V_121 = F_24 ( V_112 , V_128 ) ;
if ( V_121 < 0 )
return V_121 ;
V_60 = V_121 ;
V_121 = F_26 ( & V_112 [ V_60 ] , sizeof( V_129 ) - 1 ) ;
if ( V_121 < 0 )
return V_121 ;
memset ( V_129 , 0 , sizeof( V_129 ) ) ;
if ( F_6 ( V_129 , & V_112 [ V_60 ] , V_121 ) )
return - V_19 ;
V_60 += V_121 ;
V_128 = V_7 - V_60 ;
V_121 = F_24 ( & V_112 [ V_60 ] , V_128 ) ;
if ( V_121 < 0 )
return V_121 ;
V_60 += V_121 ;
if ( V_132 )
F_32 ( L_234 , V_129 , ( unsigned long ) V_7 ) ;
if ( ! V_155 ) {
F_48 ( L_235 ) ;
V_156 = - V_18 ;
goto V_157;
}
V_131 = & ( V_155 -> V_111 [ 0 ] ) ;
if ( ! strcmp ( V_129 , L_236 ) ) {
char V_143 [ 32 ] ;
memset ( V_143 , 0 , 32 ) ;
V_121 = F_26 ( & V_112 [ V_60 ] , sizeof( V_143 ) - 1 ) ;
if ( V_121 < 0 ) {
V_156 = V_121 ;
goto V_157;
}
if ( F_6 ( V_143 , & V_112 [ V_60 ] , V_121 ) )
return - V_19 ;
V_60 += V_121 ;
F_49 ( & V_158 ) ;
V_156 = F_50 ( V_155 , V_143 ) ;
F_51 ( & V_158 ) ;
if ( ! V_156 ) {
V_156 = V_7 ;
sprintf ( V_131 , L_237 , V_143 ) ;
} else
sprintf ( V_131 , L_238 , V_143 ) ;
goto V_157;
}
if ( ! strcmp ( V_129 , L_239 ) ) {
F_49 ( & V_158 ) ;
V_155 -> V_159 |= V_160 ;
F_51 ( & V_158 ) ;
F_52 ( F_53 ( 125 ) ) ;
V_156 = V_7 ;
sprintf ( V_131 , L_240 ) ;
goto V_157;
}
if ( ! strcmp ( V_129 , L_241 ) ) {
sprintf ( V_131 , L_242 ) ;
V_156 = V_7 ;
goto V_157;
}
V_156 = - V_18 ;
V_157:
return V_156 ;
}
static int F_54 ( struct V_20 * V_20 , struct V_5 * V_5 )
{
return F_11 ( V_5 , F_42 , F_12 ( V_20 ) ) ;
}
static struct V_21 * F_55 ( const struct V_10 * V_11 ,
const char * V_161 , int remove )
{
struct V_154 * V_155 ;
struct V_21 * V_22 = NULL ;
bool V_162 = ( remove == V_163 ) ;
F_56 (t, &pn->pktgen_threads, th_list) {
V_22 = F_57 ( V_155 , V_161 , V_162 ) ;
if ( V_22 ) {
if ( remove ) {
V_22 -> V_164 = 1 ;
V_155 -> V_159 |= V_165 ;
}
break;
}
}
return V_22 ;
}
static void F_58 ( const struct V_10 * V_11 , const char * V_161 )
{
struct V_21 * V_22 = NULL ;
const int V_166 = 10 , V_167 = 125 ;
int V_60 = 0 ;
F_49 ( & V_158 ) ;
F_32 ( L_243 , V_168 , V_161 ) ;
while ( 1 ) {
V_22 = F_55 ( V_11 , V_161 , REMOVE ) ;
if ( V_22 == NULL )
break;
F_51 ( & V_158 ) ;
F_32 ( L_244 ,
V_168 , V_161 ) ;
F_52 ( F_53 ( V_167 ) ) ;
F_49 ( & V_158 ) ;
if ( ++ V_60 >= V_166 ) {
F_48 ( L_245 ,
V_168 , V_167 * V_60 , V_161 ) ;
break;
}
}
F_51 ( & V_158 ) ;
}
static void F_59 ( const struct V_10 * V_11 , struct V_169 * V_170 )
{
struct V_154 * V_155 ;
F_56 (t, &pn->pktgen_threads, th_list) {
struct V_21 * V_22 ;
F_44 () ;
F_45 (pkt_dev, &t->if_list, list) {
if ( V_22 -> V_50 != V_170 )
continue;
F_60 ( V_22 -> V_171 ) ;
V_22 -> V_171 = F_61 ( V_170 -> V_129 , 0600 ,
V_11 -> V_172 ,
& V_173 ,
V_22 ) ;
if ( ! V_22 -> V_171 )
F_48 ( L_246 ,
V_170 -> V_129 ) ;
break;
}
F_46 () ;
}
}
static int F_62 ( struct V_174 * V_175 ,
unsigned long V_176 , void * V_177 )
{
struct V_169 * V_170 = F_63 ( V_177 ) ;
struct V_10 * V_11 = F_4 ( F_64 ( V_170 ) , V_15 ) ;
if ( V_11 -> V_178 )
return V_179 ;
switch ( V_176 ) {
case V_180 :
F_59 ( V_11 , V_170 ) ;
break;
case V_181 :
F_58 ( V_11 , V_170 -> V_129 ) ;
break;
}
return V_179 ;
}
static struct V_169 * F_65 ( const struct V_10 * V_11 ,
struct V_21 * V_22 ,
const char * V_161 )
{
char V_182 [ V_183 + 5 ] ;
int V_60 ;
for ( V_60 = 0 ; V_161 [ V_60 ] != '@' ; V_60 ++ ) {
if ( V_60 == V_183 )
break;
V_182 [ V_60 ] = V_161 [ V_60 ] ;
}
V_182 [ V_60 ] = 0 ;
return F_66 ( V_11 -> V_184 , V_182 ) ;
}
static int F_67 ( const struct V_10 * V_11 ,
struct V_21 * V_22 , const char * V_161 )
{
struct V_169 * V_50 ;
int V_185 ;
if ( V_22 -> V_50 ) {
F_68 ( V_22 -> V_50 ) ;
V_22 -> V_50 = NULL ;
}
V_50 = F_65 ( V_11 , V_22 , V_161 ) ;
if ( ! V_50 ) {
F_48 ( L_247 , V_161 ) ;
return - V_186 ;
}
if ( V_50 -> type != V_187 ) {
F_48 ( L_248 , V_161 ) ;
V_185 = - V_18 ;
} else if ( ! F_69 ( V_50 ) ) {
F_48 ( L_249 , V_161 ) ;
V_185 = - V_188 ;
} else {
V_22 -> V_50 = V_50 ;
return 0 ;
}
F_68 ( V_50 ) ;
return V_185 ;
}
static void F_70 ( struct V_21 * V_22 )
{
int V_189 ;
if ( ! V_22 -> V_50 ) {
F_48 ( L_250 ) ;
sprintf ( V_22 -> V_111 ,
L_251 ) ;
return;
}
V_189 = V_22 -> V_50 -> V_190 ;
if ( V_189 <= V_22 -> V_34 ) {
F_30 ( L_252 ,
V_22 -> V_34 , ( V_189 ? : 1 ) - 1 , V_189 ,
V_22 -> V_31 ) ;
V_22 -> V_34 = ( V_189 ? : 1 ) - 1 ;
}
if ( V_22 -> V_35 >= V_189 ) {
F_30 ( L_253 ,
V_22 -> V_35 , ( V_189 ? : 1 ) - 1 , V_189 ,
V_22 -> V_31 ) ;
V_22 -> V_35 = ( V_189 ? : 1 ) - 1 ;
}
if ( F_15 ( V_22 -> V_49 ) )
F_39 ( & ( V_22 -> V_150 [ 6 ] ) , V_22 -> V_50 -> V_51 ) ;
F_39 ( & ( V_22 -> V_150 [ 0 ] ) , V_22 -> V_52 ) ;
if ( V_22 -> V_37 & V_38 ) {
int V_60 , V_191 = 0 , V_185 = 1 ;
struct V_192 * V_193 ;
if ( V_22 -> V_26 == 0 ) {
V_22 -> V_26 = 14 + sizeof( struct V_194 )
+ sizeof( struct V_195 )
+ sizeof( struct V_196 )
+ V_22 -> V_197 ;
}
for ( V_60 = 0 ; V_60 < V_198 ; V_60 ++ )
if ( V_22 -> V_103 . V_147 [ V_60 ] ) {
V_191 = 1 ;
break;
}
if ( ! V_191 ) {
F_44 () ;
V_193 = F_71 ( V_22 -> V_50 ) ;
if ( V_193 ) {
struct V_199 * V_200 ;
F_72 ( & V_193 -> V_201 ) ;
F_56 (ifp, &idev->addr_list, if_list) {
if ( ( V_200 -> V_202 & V_203 ) &&
! ( V_200 -> V_37 & V_204 ) ) {
V_22 -> V_103 = V_200 -> V_205 ;
V_185 = 0 ;
break;
}
}
F_73 ( & V_193 -> V_201 ) ;
}
F_46 () ;
if ( V_185 )
F_48 ( L_254 ) ;
}
} else {
if ( V_22 -> V_26 == 0 ) {
V_22 -> V_26 = 14 + sizeof( struct V_206 )
+ sizeof( struct V_195 )
+ sizeof( struct V_196 )
+ V_22 -> V_197 ;
}
V_22 -> V_148 = 0 ;
V_22 -> V_149 = 0 ;
if ( strlen ( V_22 -> V_47 ) == 0 ) {
struct V_207 * V_208 ;
F_44 () ;
V_208 = F_74 ( V_22 -> V_50 ) ;
if ( V_208 ) {
if ( V_208 -> V_209 ) {
V_22 -> V_148 =
V_208 -> V_209 -> V_210 ;
V_22 -> V_149 = V_22 -> V_148 ;
}
}
F_46 () ;
} else {
V_22 -> V_148 = F_36 ( V_22 -> V_47 ) ;
V_22 -> V_149 = F_36 ( V_22 -> V_48 ) ;
}
V_22 -> V_145 = F_36 ( V_22 -> V_45 ) ;
V_22 -> V_146 = F_36 ( V_22 -> V_46 ) ;
}
V_22 -> V_135 = V_22 -> V_26 ;
if ( V_22 -> V_26 > V_22 -> V_27 )
V_22 -> V_27 = V_22 -> V_26 ;
V_22 -> V_101 = 0 ;
V_22 -> V_102 = 0 ;
V_22 -> V_105 = V_22 -> V_148 ;
V_22 -> V_106 = V_22 -> V_145 ;
V_22 -> V_107 = V_22 -> V_55 ;
V_22 -> V_108 = V_22 -> V_53 ;
V_22 -> V_110 = 0 ;
}
static void F_75 ( struct V_21 * V_22 , T_5 V_211 )
{
T_5 V_212 , V_213 ;
T_8 V_214 ;
struct V_215 V_155 ;
F_76 ( & V_155 . V_216 , V_217 , V_218 ) ;
F_77 ( & V_155 . V_216 , V_211 ) ;
V_214 = F_78 ( F_79 ( & V_155 . V_216 ) ) ;
if ( V_214 <= 0 )
goto V_157;
V_212 = F_18 () ;
if ( V_214 < 100000 ) {
do {
V_213 = F_18 () ;
} while ( F_80 ( V_213 , V_211 ) < 0 );
} else {
F_81 ( & V_155 , V_12 ) ;
do {
F_82 ( V_219 ) ;
F_83 ( & V_155 . V_216 , V_218 ) ;
if ( F_84 ( V_155 . V_220 ) )
F_85 () ;
F_86 ( & V_155 . V_216 ) ;
} while ( V_155 . V_220 && V_22 -> V_93 && ! F_87 ( V_12 ) );
F_88 ( V_221 ) ;
V_213 = F_18 () ;
}
V_22 -> V_95 += F_78 ( F_89 ( V_213 , V_212 ) ) ;
V_157:
V_22 -> V_222 = F_90 ( V_211 , V_22 -> V_29 ) ;
F_91 ( & V_155 . V_216 ) ;
}
static inline void F_92 ( struct V_21 * V_22 )
{
V_22 -> V_197 = F_93 ( V_22 -> V_50 ) ;
V_22 -> V_197 += V_22 -> V_59 * sizeof( V_223 ) ;
V_22 -> V_197 += F_94 ( V_22 ) ;
V_22 -> V_197 += F_95 ( V_22 ) ;
}
static inline int F_96 ( const struct V_21 * V_22 , int V_224 )
{
return ! ! ( V_22 -> V_225 [ V_224 ] . V_37 & V_226 ) ;
}
static inline int F_97 ( struct V_21 * V_22 )
{
int V_224 = V_22 -> V_227 ;
if ( V_22 -> V_37 & V_85 ) {
if ( V_22 -> V_225 [ V_224 ] . V_7 >= V_22 -> V_33 ) {
V_22 -> V_225 [ V_224 ] . V_7 = 0 ;
V_22 -> V_225 [ V_224 ] . V_37 = 0 ;
V_22 -> V_227 += 1 ;
if ( V_22 -> V_227 >= V_22 -> V_32 )
V_22 -> V_227 = 0 ;
}
} else {
V_224 = F_98 () % V_22 -> V_32 ;
V_22 -> V_227 = V_224 ;
if ( V_22 -> V_225 [ V_224 ] . V_7 > V_22 -> V_33 ) {
V_22 -> V_225 [ V_224 ] . V_7 = 0 ;
V_22 -> V_225 [ V_224 ] . V_37 = 0 ;
}
}
return V_22 -> V_227 ;
}
static void F_99 ( struct V_21 * V_22 , int V_224 )
{
struct V_228 * V_229 = V_22 -> V_225 [ V_224 ] . V_229 ;
struct V_10 * V_11 = F_4 ( F_64 ( V_22 -> V_50 ) , V_15 ) ;
if ( ! V_229 ) {
if ( V_22 -> V_87 ) {
V_229 = F_100 ( V_11 -> V_184 , F_28 ( V_22 -> V_87 ) , V_230 ) ;
} else {
V_229 = F_101 ( V_11 -> V_184 , V_231 ,
( V_232 * ) & V_22 -> V_106 ,
( V_232 * ) & V_22 -> V_105 ,
V_230 ,
V_22 -> V_233 ,
V_22 -> V_234 , 0 ) ;
}
if ( V_229 ) {
V_22 -> V_225 [ V_224 ] . V_229 = V_229 ;
F_92 ( V_22 ) ;
V_22 -> V_197 += V_229 -> V_235 . V_236 ;
}
}
}
static void F_102 ( struct V_21 * V_22 )
{
if ( V_22 -> V_37 & V_84 )
V_22 -> V_109 = F_103 () ;
else if ( V_22 -> V_34 <= V_22 -> V_35 ) {
T_9 V_155 ;
if ( V_22 -> V_37 & V_83 ) {
V_155 = F_98 () %
( V_22 -> V_35 -
V_22 -> V_34 + 1 )
+ V_22 -> V_34 ;
} else {
V_155 = V_22 -> V_109 + 1 ;
if ( V_155 > V_22 -> V_35 )
V_155 = V_22 -> V_34 ;
}
V_22 -> V_109 = V_155 ;
}
V_22 -> V_109 = V_22 -> V_109 % V_22 -> V_50 -> V_190 ;
}
static void F_104 ( struct V_21 * V_22 )
{
T_7 V_237 ;
T_7 V_238 ;
int V_224 = 0 ;
if ( V_22 -> V_32 )
V_224 = F_97 ( V_22 ) ;
if ( V_22 -> V_57 > 1 ) {
T_7 V_239 ;
T_7 V_122 ;
if ( V_22 -> V_37 & V_88 )
V_239 = F_98 () % V_22 -> V_57 ;
else {
V_239 = V_22 -> V_102 ++ ;
if ( V_22 -> V_102 >=
V_22 -> V_57 )
V_22 -> V_102 = 0 ;
}
V_122 = V_22 -> V_49 [ 5 ] + ( V_239 & 0xFF ) ;
V_22 -> V_150 [ 11 ] = V_122 ;
V_122 = ( V_22 -> V_49 [ 4 ] + ( ( V_239 >> 8 ) & 0xFF ) + ( V_122 >> 8 ) ) ;
V_22 -> V_150 [ 10 ] = V_122 ;
V_122 = ( V_22 -> V_49 [ 3 ] + ( ( V_239 >> 16 ) & 0xFF ) + ( V_122 >> 8 ) ) ;
V_22 -> V_150 [ 9 ] = V_122 ;
V_122 = ( V_22 -> V_49 [ 2 ] + ( ( V_239 >> 24 ) & 0xFF ) + ( V_122 >> 8 ) ) ;
V_22 -> V_150 [ 8 ] = V_122 ;
V_122 = ( V_22 -> V_49 [ 1 ] + ( V_122 >> 8 ) ) ;
V_22 -> V_150 [ 7 ] = V_122 ;
}
if ( V_22 -> V_58 > 1 ) {
T_7 V_239 ;
T_7 V_122 ;
if ( V_22 -> V_37 & V_89 )
V_239 = F_98 () % V_22 -> V_58 ;
else {
V_239 = V_22 -> V_101 ++ ;
if ( V_22 -> V_101 >=
V_22 -> V_58 ) {
V_22 -> V_101 = 0 ;
}
}
V_122 = V_22 -> V_52 [ 5 ] + ( V_239 & 0xFF ) ;
V_22 -> V_150 [ 5 ] = V_122 ;
V_122 = ( V_22 -> V_52 [ 4 ] + ( ( V_239 >> 8 ) & 0xFF ) + ( V_122 >> 8 ) ) ;
V_22 -> V_150 [ 4 ] = V_122 ;
V_122 = ( V_22 -> V_52 [ 3 ] + ( ( V_239 >> 16 ) & 0xFF ) + ( V_122 >> 8 ) ) ;
V_22 -> V_150 [ 3 ] = V_122 ;
V_122 = ( V_22 -> V_52 [ 2 ] + ( ( V_239 >> 24 ) & 0xFF ) + ( V_122 >> 8 ) ) ;
V_22 -> V_150 [ 2 ] = V_122 ;
V_122 = ( V_22 -> V_52 [ 1 ] + ( V_122 >> 8 ) ) ;
V_22 -> V_150 [ 1 ] = V_122 ;
}
if ( V_22 -> V_37 & V_82 ) {
unsigned int V_60 ;
for ( V_60 = 0 ; V_60 < V_22 -> V_59 ; V_60 ++ )
if ( V_22 -> V_61 [ V_60 ] & V_123 )
V_22 -> V_61 [ V_60 ] = V_123 |
( ( V_240 V_241 ) F_98 () &
F_28 ( 0x000fffff ) ) ;
}
if ( ( V_22 -> V_37 & V_90 ) && ( V_22 -> V_62 != 0xffff ) ) {
V_22 -> V_62 = F_98 () & ( 4096 - 1 ) ;
}
if ( ( V_22 -> V_37 & V_91 ) && ( V_22 -> V_65 != 0xffff ) ) {
V_22 -> V_65 = F_98 () & ( 4096 - 1 ) ;
}
if ( V_22 -> V_53 < V_22 -> V_54 ) {
if ( V_22 -> V_37 & V_78 )
V_22 -> V_108 = F_98 () %
( V_22 -> V_54 - V_22 -> V_53 )
+ V_22 -> V_53 ;
else {
V_22 -> V_108 ++ ;
if ( V_22 -> V_108 >= V_22 -> V_54 )
V_22 -> V_108 = V_22 -> V_53 ;
}
}
if ( V_22 -> V_55 < V_22 -> V_56 ) {
if ( V_22 -> V_37 & V_79 ) {
V_22 -> V_107 = F_98 () %
( V_22 -> V_56 - V_22 -> V_55 )
+ V_22 -> V_55 ;
} else {
V_22 -> V_107 ++ ;
if ( V_22 -> V_107 >= V_22 -> V_56 )
V_22 -> V_107 = V_22 -> V_55 ;
}
}
if ( ! ( V_22 -> V_37 & V_38 ) ) {
V_237 = F_16 ( V_22 -> V_148 ) ;
V_238 = F_16 ( V_22 -> V_149 ) ;
if ( V_237 < V_238 ) {
T_7 V_155 ;
if ( V_22 -> V_37 & V_75 )
V_155 = F_98 () % ( V_238 - V_237 ) + V_237 ;
else {
V_155 = F_16 ( V_22 -> V_105 ) ;
V_155 ++ ;
if ( V_155 > V_238 )
V_155 = V_237 ;
}
V_22 -> V_105 = F_28 ( V_155 ) ;
}
if ( V_22 -> V_32 && F_96 ( V_22 , V_224 ) ) {
V_22 -> V_106 = V_22 -> V_225 [ V_224 ] . V_106 ;
} else {
V_237 = F_16 ( V_22 -> V_145 ) ;
V_238 = F_16 ( V_22 -> V_146 ) ;
if ( V_237 < V_238 ) {
T_7 V_155 ;
V_241 V_242 ;
if ( V_22 -> V_37 & V_76 ) {
do {
V_155 = F_98 () %
( V_238 - V_237 ) + V_237 ;
V_242 = F_28 ( V_155 ) ;
} while ( F_105 ( V_242 ) ||
F_106 ( V_242 ) ||
F_107 ( V_242 ) ||
F_108 ( V_242 ) ||
F_109 ( V_242 ) );
V_22 -> V_106 = V_242 ;
} else {
V_155 = F_16 ( V_22 -> V_106 ) ;
V_155 ++ ;
if ( V_155 > V_238 ) {
V_155 = V_237 ;
}
V_22 -> V_106 = F_28 ( V_155 ) ;
}
}
if ( V_22 -> V_32 ) {
V_22 -> V_225 [ V_224 ] . V_37 |= V_226 ;
V_22 -> V_225 [ V_224 ] . V_106 =
V_22 -> V_106 ;
#ifdef F_17
if ( V_22 -> V_37 & V_86 )
F_99 ( V_22 , V_224 ) ;
#endif
V_22 -> V_110 ++ ;
}
}
} else {
if ( ! F_110 ( & V_22 -> V_43 ) ) {
int V_60 ;
for ( V_60 = 0 ; V_60 < 4 ; V_60 ++ ) {
V_22 -> V_104 . V_243 [ V_60 ] =
( ( ( V_240 V_241 ) F_98 () |
V_22 -> V_43 . V_243 [ V_60 ] ) &
V_22 -> V_44 . V_243 [ V_60 ] ) ;
}
}
}
if ( V_22 -> V_26 < V_22 -> V_27 ) {
T_7 V_155 ;
if ( V_22 -> V_37 & V_77 ) {
V_155 = F_98 () %
( V_22 -> V_27 - V_22 -> V_26 )
+ V_22 -> V_26 ;
} else {
V_155 = V_22 -> V_135 + 1 ;
if ( V_155 > V_22 -> V_27 )
V_155 = V_22 -> V_26 ;
}
V_22 -> V_135 = V_155 ;
}
F_102 ( V_22 ) ;
V_22 -> V_225 [ V_224 ] . V_7 ++ ;
}
static int F_111 ( struct V_244 * V_245 , struct V_21 * V_22 )
{
struct V_228 * V_229 = V_22 -> V_225 [ V_22 -> V_227 ] . V_229 ;
int V_185 = 0 ;
struct V_184 * V_184 = F_64 ( V_22 -> V_50 ) ;
if ( ! V_229 )
return 0 ;
if ( ( V_229 -> V_235 . V_246 != V_247 ) && ( V_22 -> V_87 == 0 ) )
return 0 ;
if ( ( V_229 -> V_235 . V_246 == V_248 ) && ( V_22 -> V_87 != 0 ) )
V_245 -> V_249 = ( unsigned long ) & V_22 -> V_250 | V_251 ;
F_112 () ;
V_185 = V_229 -> V_252 -> V_253 ( V_229 , V_245 ) ;
F_113 () ;
if ( V_185 ) {
F_114 ( V_184 , V_254 ) ;
goto error;
}
V_185 = V_229 -> type -> V_253 ( V_229 , V_245 ) ;
if ( V_185 ) {
F_114 ( V_184 , V_255 ) ;
goto error;
}
F_115 ( & V_229 -> V_201 ) ;
V_229 -> V_256 . V_257 += V_245 -> V_121 ;
V_229 -> V_256 . V_258 ++ ;
F_116 ( & V_229 -> V_201 ) ;
error:
return V_185 ;
}
static void F_117 ( struct V_21 * V_22 )
{
if ( V_22 -> V_32 ) {
int V_60 ;
for ( V_60 = 0 ; V_60 < V_22 -> V_32 ; V_60 ++ ) {
struct V_228 * V_229 = V_22 -> V_225 [ V_60 ] . V_229 ;
if ( V_229 ) {
F_118 ( V_229 ) ;
V_22 -> V_225 [ V_60 ] . V_229 = NULL ;
}
}
}
}
static int F_119 ( struct V_21 * V_22 ,
struct V_244 * V_245 , T_10 V_259 )
{
if ( V_22 -> V_37 & V_86 ) {
struct V_228 * V_229 = V_22 -> V_225 [ V_22 -> V_227 ] . V_229 ;
int V_260 = 0 ;
if ( V_229 ) {
struct V_261 * V_262 ;
struct V_206 * V_263 ;
int V_156 ;
V_260 = V_229 -> V_235 . V_236 - F_120 ( V_245 ) ;
if ( V_260 > 0 ) {
V_156 = F_121 ( V_245 , V_260 , 0 , V_264 ) ;
if ( V_156 < 0 ) {
F_48 ( L_255 ,
V_156 ) ;
goto V_185;
}
}
F_122 ( V_245 , V_265 ) ;
V_156 = F_111 ( V_245 , V_22 ) ;
if ( V_156 ) {
F_48 ( L_256 , V_156 ) ;
goto V_185;
}
V_262 = (struct V_261 * ) F_123 ( V_245 , V_265 ) ;
memcpy ( V_262 , V_22 -> V_150 , 2 * V_266 ) ;
V_262 -> V_267 = V_259 ;
V_263 = F_124 ( V_245 ) ;
V_263 -> V_268 = F_125 ( V_245 -> V_121 - V_265 ) ;
F_126 ( V_263 ) ;
}
}
return 1 ;
V_185:
F_127 ( V_245 ) ;
return 0 ;
}
static void F_128 ( V_241 * V_269 , struct V_21 * V_22 )
{
unsigned int V_60 ;
for ( V_60 = 0 ; V_60 < V_22 -> V_59 ; V_60 ++ )
* V_269 ++ = V_22 -> V_61 [ V_60 ] & ~ V_123 ;
V_269 -- ;
* V_269 |= V_123 ;
}
static inline T_10 F_129 ( unsigned int V_270 , unsigned int V_271 ,
unsigned int V_272 )
{
return F_125 ( V_270 | ( V_271 << 12 ) | ( V_272 << 13 ) ) ;
}
static void F_130 ( struct V_21 * V_22 , struct V_244 * V_245 ,
int V_273 )
{
struct V_274 V_275 ;
struct V_196 * V_276 ;
V_276 = (struct V_196 * ) F_131 ( V_245 , sizeof( * V_276 ) ) ;
V_273 -= sizeof( * V_276 ) ;
if ( V_22 -> V_28 <= 0 ) {
memset ( F_131 ( V_245 , V_273 ) , 0 , V_273 ) ;
} else {
int V_277 = V_22 -> V_28 ;
int V_60 , V_121 ;
int V_278 ;
if ( V_277 > V_279 )
V_277 = V_279 ;
V_121 = V_273 - V_277 * V_280 ;
if ( V_121 > 0 ) {
memset ( F_131 ( V_245 , V_121 ) , 0 , V_121 ) ;
V_273 = V_277 * V_280 ;
}
V_60 = 0 ;
V_278 = ( V_273 / V_277 ) < V_280 ?
( V_273 / V_277 ) : V_280 ;
while ( V_273 > 0 ) {
if ( F_132 ( ! V_22 -> V_142 ) ) {
int V_71 = F_133 () ;
if ( V_22 -> V_71 >= 0 && ( V_22 -> V_37 & V_92 ) )
V_71 = V_22 -> V_71 ;
V_22 -> V_142 = F_134 ( V_71 , V_281 | V_282 , 0 ) ;
if ( ! V_22 -> V_142 )
break;
}
F_135 ( V_22 -> V_142 ) ;
F_136 ( V_245 , V_60 , V_22 -> V_142 ) ;
F_137 ( V_245 ) -> V_277 [ V_60 ] . V_283 = 0 ;
if ( V_60 == ( V_277 - 1 ) )
F_138 ( & F_137 ( V_245 ) -> V_277 [ V_60 ] ,
( V_273 < V_280 ? V_273 : V_280 ) ) ;
else
F_138 ( & F_137 ( V_245 ) -> V_277 [ V_60 ] , V_278 ) ;
V_273 -= F_139 ( & F_137 ( V_245 ) -> V_277 [ V_60 ] ) ;
V_245 -> V_121 += F_139 ( & F_137 ( V_245 ) -> V_277 [ V_60 ] ) ;
V_245 -> V_284 += F_139 ( & F_137 ( V_245 ) -> V_277 [ V_60 ] ) ;
V_60 ++ ;
F_137 ( V_245 ) -> V_285 = V_60 ;
}
}
V_276 -> V_286 = F_28 ( V_287 ) ;
V_276 -> V_100 = F_28 ( V_22 -> V_100 ) ;
if ( V_22 -> V_37 & V_81 ) {
V_276 -> V_288 = 0 ;
V_276 -> V_289 = 0 ;
} else {
F_140 ( & V_275 ) ;
V_276 -> V_288 = F_28 ( V_275 . V_288 ) ;
V_276 -> V_289 = F_28 ( V_275 . V_289 ) ;
}
}
static struct V_244 * F_141 ( struct V_169 * V_170 ,
struct V_21 * V_22 ,
unsigned int V_290 )
{
struct V_244 * V_245 = NULL ;
unsigned int V_291 = V_22 -> V_135 + 64 + V_290 +
V_22 -> V_197 ;
if ( V_22 -> V_37 & V_92 ) {
int V_71 = V_22 -> V_71 >= 0 ? V_22 -> V_71 : F_133 () ;
V_245 = F_142 ( V_292 + V_291 , V_293 , 0 , V_71 ) ;
if ( F_84 ( V_245 ) ) {
F_143 ( V_245 , V_292 ) ;
V_245 -> V_170 = V_170 ;
}
} else {
V_245 = F_144 ( V_170 , V_291 , V_293 ) ;
}
if ( F_84 ( V_245 ) )
F_143 ( V_245 , F_93 ( V_170 ) ) ;
return V_245 ;
}
static struct V_244 * F_145 ( struct V_169 * V_50 ,
struct V_21 * V_22 )
{
struct V_244 * V_245 = NULL ;
T_11 * V_262 ;
struct V_195 * V_294 ;
int V_273 , V_295 ;
struct V_206 * V_263 ;
T_10 V_259 = F_125 ( V_296 ) ;
V_241 * V_269 ;
T_10 * V_297 = NULL ;
T_10 * V_298 = NULL ;
T_10 * V_299 = NULL ;
T_10 * V_300 = NULL ;
T_12 V_301 ;
if ( V_22 -> V_59 )
V_259 = F_125 ( V_302 ) ;
if ( V_22 -> V_62 != 0xffff )
V_259 = F_125 ( V_303 ) ;
F_104 ( V_22 ) ;
V_301 = V_22 -> V_109 ;
V_273 = ( V_50 -> V_304 + 16 ) & ~ 0xf ;
V_245 = F_141 ( V_50 , V_22 , V_273 ) ;
if ( ! V_245 ) {
sprintf ( V_22 -> V_111 , L_257 ) ;
return NULL ;
}
F_146 ( V_245 -> V_9 ) ;
F_143 ( V_245 , V_273 ) ;
V_262 = ( T_11 * ) F_123 ( V_245 , 14 ) ;
V_269 = ( V_241 * ) F_131 ( V_245 , V_22 -> V_59 * sizeof( T_7 ) ) ;
if ( V_22 -> V_59 )
F_128 ( V_269 , V_22 ) ;
if ( V_22 -> V_62 != 0xffff ) {
if ( V_22 -> V_65 != 0xffff ) {
V_299 = ( T_10 * ) F_131 ( V_245 , sizeof( T_10 ) ) ;
* V_299 = F_129 ( V_22 -> V_65 ,
V_22 -> V_67 ,
V_22 -> V_66 ) ;
V_300 = ( T_10 * ) F_131 ( V_245 , sizeof( T_10 ) ) ;
* V_300 = F_125 ( V_303 ) ;
}
V_297 = ( T_10 * ) F_131 ( V_245 , sizeof( T_10 ) ) ;
* V_297 = F_129 ( V_22 -> V_62 ,
V_22 -> V_64 ,
V_22 -> V_63 ) ;
V_298 = ( T_10 * ) F_131 ( V_245 , sizeof( T_10 ) ) ;
* V_298 = F_125 ( V_296 ) ;
}
F_147 ( V_245 ) ;
F_148 ( V_245 , V_245 -> V_121 ) ;
V_263 = (struct V_206 * ) F_131 ( V_245 , sizeof( struct V_206 ) ) ;
F_149 ( V_245 , V_245 -> V_121 ) ;
V_294 = (struct V_195 * ) F_131 ( V_245 , sizeof( struct V_195 ) ) ;
F_150 ( V_245 , V_301 ) ;
V_245 -> V_305 = V_22 -> V_36 ;
memcpy ( V_262 , V_22 -> V_150 , 12 ) ;
* ( T_10 * ) & V_262 [ 12 ] = V_259 ;
V_273 = V_22 -> V_135 - 14 - 20 - 8 -
V_22 -> V_197 ;
if ( V_273 < 0 || V_273 < sizeof( struct V_196 ) )
V_273 = sizeof( struct V_196 ) ;
V_294 -> V_306 = F_125 ( V_22 -> V_108 ) ;
V_294 -> V_307 = F_125 ( V_22 -> V_107 ) ;
V_294 -> V_121 = F_125 ( V_273 + 8 ) ;
V_294 -> V_308 = 0 ;
V_263 -> V_309 = 5 ;
V_263 -> V_4 = 4 ;
V_263 -> V_310 = 32 ;
V_263 -> V_68 = V_22 -> V_68 ;
V_263 -> V_259 = V_311 ;
V_263 -> V_312 = V_22 -> V_105 ;
V_263 -> V_313 = V_22 -> V_106 ;
V_263 -> V_270 = F_125 ( V_22 -> V_314 ) ;
V_22 -> V_314 ++ ;
V_263 -> V_315 = 0 ;
V_295 = 20 + 8 + V_273 ;
V_263 -> V_268 = F_125 ( V_295 ) ;
F_126 ( V_263 ) ;
V_245 -> V_259 = V_259 ;
V_245 -> V_170 = V_50 ;
V_245 -> V_316 = V_317 ;
F_130 ( V_22 , V_245 , V_273 ) ;
if ( ! ( V_22 -> V_37 & V_80 ) ) {
V_245 -> V_318 = V_319 ;
} else if ( V_50 -> V_320 & ( V_321 | V_322 ) ) {
V_245 -> V_318 = V_323 ;
V_245 -> V_324 = 0 ;
F_151 ( V_245 , V_263 -> V_312 , V_263 -> V_313 ) ;
} else {
T_13 V_324 = F_152 ( V_245 , F_153 ( V_245 ) , V_273 + 8 , 0 ) ;
V_294 -> V_308 = F_154 ( V_263 -> V_312 , V_263 -> V_313 ,
V_273 + 8 , V_311 , V_324 ) ;
if ( V_294 -> V_308 == 0 )
V_294 -> V_308 = V_325 ;
}
#ifdef F_17
if ( ! F_119 ( V_22 , V_245 , V_259 ) )
return NULL ;
#endif
return V_245 ;
}
static struct V_244 * F_155 ( struct V_169 * V_50 ,
struct V_21 * V_22 )
{
struct V_244 * V_245 = NULL ;
T_11 * V_262 ;
struct V_195 * V_294 ;
int V_273 , V_326 ;
struct V_194 * V_263 ;
T_10 V_259 = F_125 ( V_327 ) ;
V_241 * V_269 ;
T_10 * V_297 = NULL ;
T_10 * V_298 = NULL ;
T_10 * V_299 = NULL ;
T_10 * V_300 = NULL ;
T_12 V_301 ;
if ( V_22 -> V_59 )
V_259 = F_125 ( V_302 ) ;
if ( V_22 -> V_62 != 0xffff )
V_259 = F_125 ( V_303 ) ;
F_104 ( V_22 ) ;
V_301 = V_22 -> V_109 ;
V_245 = F_141 ( V_50 , V_22 , 16 ) ;
if ( ! V_245 ) {
sprintf ( V_22 -> V_111 , L_257 ) ;
return NULL ;
}
F_146 ( V_245 -> V_9 ) ;
F_143 ( V_245 , 16 ) ;
V_262 = ( T_11 * ) F_123 ( V_245 , 14 ) ;
V_269 = ( V_241 * ) F_131 ( V_245 , V_22 -> V_59 * sizeof( T_7 ) ) ;
if ( V_22 -> V_59 )
F_128 ( V_269 , V_22 ) ;
if ( V_22 -> V_62 != 0xffff ) {
if ( V_22 -> V_65 != 0xffff ) {
V_299 = ( T_10 * ) F_131 ( V_245 , sizeof( T_10 ) ) ;
* V_299 = F_129 ( V_22 -> V_65 ,
V_22 -> V_67 ,
V_22 -> V_66 ) ;
V_300 = ( T_10 * ) F_131 ( V_245 , sizeof( T_10 ) ) ;
* V_300 = F_125 ( V_303 ) ;
}
V_297 = ( T_10 * ) F_131 ( V_245 , sizeof( T_10 ) ) ;
* V_297 = F_129 ( V_22 -> V_62 ,
V_22 -> V_64 ,
V_22 -> V_63 ) ;
V_298 = ( T_10 * ) F_131 ( V_245 , sizeof( T_10 ) ) ;
* V_298 = F_125 ( V_327 ) ;
}
F_147 ( V_245 ) ;
F_148 ( V_245 , V_245 -> V_121 ) ;
V_263 = (struct V_194 * ) F_131 ( V_245 , sizeof( struct V_194 ) ) ;
F_149 ( V_245 , V_245 -> V_121 ) ;
V_294 = (struct V_195 * ) F_131 ( V_245 , sizeof( struct V_195 ) ) ;
F_150 ( V_245 , V_301 ) ;
V_245 -> V_305 = V_22 -> V_36 ;
memcpy ( V_262 , V_22 -> V_150 , 12 ) ;
* ( T_10 * ) & V_262 [ 12 ] = V_259 ;
V_273 = V_22 -> V_135 - 14 -
sizeof( struct V_194 ) - sizeof( struct V_195 ) -
V_22 -> V_197 ;
if ( V_273 < 0 || V_273 < sizeof( struct V_196 ) ) {
V_273 = sizeof( struct V_196 ) ;
F_156 ( L_258 , V_273 ) ;
}
V_326 = V_273 + sizeof( struct V_195 ) ;
V_294 -> V_306 = F_125 ( V_22 -> V_108 ) ;
V_294 -> V_307 = F_125 ( V_22 -> V_107 ) ;
V_294 -> V_121 = F_125 ( V_326 ) ;
V_294 -> V_308 = 0 ;
* ( V_241 * ) V_263 = F_28 ( 0x60000000 ) ;
if ( V_22 -> V_69 ) {
* ( V_241 * ) V_263 |= F_28 ( 0x60000000 | ( V_22 -> V_69 << 20 ) ) ;
}
V_263 -> V_328 = 32 ;
V_263 -> V_329 = F_125 ( V_326 ) ;
V_263 -> V_330 = V_311 ;
V_263 -> V_313 = V_22 -> V_104 ;
V_263 -> V_312 = V_22 -> V_103 ;
V_245 -> V_259 = V_259 ;
V_245 -> V_170 = V_50 ;
V_245 -> V_316 = V_317 ;
F_130 ( V_22 , V_245 , V_273 ) ;
if ( ! ( V_22 -> V_37 & V_80 ) ) {
V_245 -> V_318 = V_319 ;
} else if ( V_50 -> V_320 & ( V_321 | V_331 ) ) {
V_245 -> V_318 = V_323 ;
V_245 -> V_332 = F_157 ( V_245 ) - V_245 -> V_333 ;
V_245 -> V_334 = F_158 ( struct V_195 , V_308 ) ;
V_294 -> V_308 = ~ F_159 ( & V_263 -> V_312 , & V_263 -> V_313 , V_326 , V_311 , 0 ) ;
} else {
T_13 V_324 = F_152 ( V_245 , F_153 ( V_245 ) , V_326 , 0 ) ;
V_294 -> V_308 = F_159 ( & V_263 -> V_312 , & V_263 -> V_313 , V_326 , V_311 , V_324 ) ;
if ( V_294 -> V_308 == 0 )
V_294 -> V_308 = V_325 ;
}
return V_245 ;
}
static struct V_244 * F_160 ( struct V_169 * V_50 ,
struct V_21 * V_22 )
{
if ( V_22 -> V_37 & V_38 )
return F_155 ( V_50 , V_22 ) ;
else
return F_145 ( V_50 , V_22 ) ;
}
static void F_40 ( struct V_21 * V_22 )
{
V_22 -> V_100 = 1 ;
V_22 -> V_95 = 0 ;
V_22 -> V_97 = 0 ;
V_22 -> V_335 = 0 ;
V_22 -> V_98 = 0 ;
}
static void F_161 ( struct V_154 * V_155 )
{
struct V_21 * V_22 ;
int V_336 = 0 ;
F_162 () ;
F_44 () ;
F_45 (pkt_dev, &t->if_list, list) {
F_70 ( V_22 ) ;
if ( V_22 -> V_50 ) {
F_40 ( V_22 ) ;
V_22 -> V_245 = NULL ;
V_22 -> V_99 = V_22 -> V_222 = F_18 () ;
F_92 ( V_22 ) ;
strcpy ( V_22 -> V_111 , L_259 ) ;
V_22 -> V_93 = 1 ;
V_336 ++ ;
} else
strcpy ( V_22 -> V_111 , L_260 ) ;
}
F_46 () ;
if ( V_336 )
V_155 -> V_159 &= ~ ( V_337 ) ;
}
static void F_7 ( struct V_10 * V_11 )
{
struct V_154 * V_155 ;
F_162 () ;
F_49 ( & V_158 ) ;
F_56 (t, &pn->pktgen_threads, th_list)
V_155 -> V_159 |= V_337 ;
F_51 ( & V_158 ) ;
}
static int F_163 ( const struct V_154 * V_155 )
{
const struct V_21 * V_22 ;
F_44 () ;
F_45 (pkt_dev, &t->if_list, list)
if ( V_22 -> V_93 ) {
F_46 () ;
return 1 ;
}
F_46 () ;
return 0 ;
}
static int F_164 ( struct V_154 * V_155 )
{
while ( F_163 ( V_155 ) ) {
F_165 ( 100 ) ;
if ( F_87 ( V_12 ) )
goto signal;
}
return 1 ;
signal:
return 0 ;
}
static int F_166 ( struct V_10 * V_11 )
{
struct V_154 * V_155 ;
int V_338 = 1 ;
F_49 ( & V_158 ) ;
F_56 (t, &pn->pktgen_threads, th_list) {
V_338 = F_164 ( V_155 ) ;
if ( V_338 == 0 )
break;
}
if ( V_338 == 0 )
F_56 (t, &pn->pktgen_threads, th_list)
V_155 -> V_159 |= ( V_337 ) ;
F_51 ( & V_158 ) ;
return V_338 ;
}
static void F_8 ( struct V_10 * V_11 )
{
struct V_154 * V_155 ;
F_162 () ;
F_49 ( & V_158 ) ;
F_56 (t, &pn->pktgen_threads, th_list)
V_155 -> V_159 |= ( V_339 ) ;
F_51 ( & V_158 ) ;
F_52 ( F_53 ( 125 ) ) ;
F_166 ( V_11 ) ;
}
static void F_9 ( struct V_10 * V_11 )
{
struct V_154 * V_155 ;
F_162 () ;
F_49 ( & V_158 ) ;
F_56 (t, &pn->pktgen_threads, th_list)
V_155 -> V_159 |= ( V_160 ) ;
F_51 ( & V_158 ) ;
F_52 ( F_53 ( 125 ) ) ;
F_166 ( V_11 ) ;
}
static void F_167 ( struct V_21 * V_22 , int V_285 )
{
T_14 V_340 , V_341 , V_342 ;
char * V_343 = V_22 -> V_111 ;
T_5 V_344 = F_89 ( V_22 -> V_94 ,
V_22 -> V_99 ) ;
T_5 V_25 = F_168 ( V_22 -> V_95 ) ;
V_343 += sprintf ( V_343 , L_261 ,
( unsigned long long ) F_20 ( V_344 ) ,
( unsigned long long ) F_20 ( F_89 ( V_344 , V_25 ) ) ,
( unsigned long long ) F_20 ( V_25 ) ,
( unsigned long long ) V_22 -> V_97 ,
V_22 -> V_135 , V_285 ) ;
V_342 = F_169 ( V_22 -> V_97 * V_137 ,
F_78 ( V_344 ) ) ;
V_340 = V_342 * 8 * V_22 -> V_135 ;
V_341 = V_340 ;
F_19 ( V_341 , 1000000 ) ;
V_343 += sprintf ( V_343 , L_262 ,
( unsigned long long ) V_342 ,
( unsigned long long ) V_341 ,
( unsigned long long ) V_340 ,
( unsigned long long ) V_22 -> V_98 ) ;
}
static int F_170 ( struct V_21 * V_22 )
{
int V_285 = V_22 -> V_245 ? F_137 ( V_22 -> V_245 ) -> V_285 : - 1 ;
if ( ! V_22 -> V_93 ) {
F_30 ( L_263 ,
V_22 -> V_31 ) ;
return - V_18 ;
}
V_22 -> V_93 = 0 ;
F_127 ( V_22 -> V_245 ) ;
V_22 -> V_245 = NULL ;
V_22 -> V_94 = F_18 () ;
F_167 ( V_22 , V_285 ) ;
return 0 ;
}
static struct V_21 * F_171 ( struct V_154 * V_155 )
{
struct V_21 * V_22 , * V_345 = NULL ;
F_44 () ;
F_45 (pkt_dev, &t->if_list, list) {
if ( ! V_22 -> V_93 )
continue;
if ( V_345 == NULL )
V_345 = V_22 ;
else if ( F_80 ( V_22 -> V_222 , V_345 -> V_222 ) < 0 )
V_345 = V_22 ;
}
F_46 () ;
return V_345 ;
}
static void F_172 ( struct V_154 * V_155 )
{
struct V_21 * V_22 ;
F_162 () ;
F_44 () ;
F_45 (pkt_dev, &t->if_list, list) {
F_170 ( V_22 ) ;
}
F_46 () ;
}
static void F_173 ( struct V_154 * V_155 )
{
struct V_346 * V_347 , * V_120 ;
struct V_21 * V_348 ;
F_162 () ;
F_174 (q, n, &t->if_list) {
V_348 = F_175 ( V_347 , struct V_21 , V_349 ) ;
if ( ! V_348 -> V_164 )
continue;
F_127 ( V_348 -> V_245 ) ;
V_348 -> V_245 = NULL ;
F_176 ( V_155 , V_348 ) ;
break;
}
}
static void F_177 ( struct V_154 * V_155 )
{
struct V_346 * V_347 , * V_120 ;
struct V_21 * V_348 ;
F_162 () ;
F_174 (q, n, &t->if_list) {
V_348 = F_175 ( V_347 , struct V_21 , V_349 ) ;
F_127 ( V_348 -> V_245 ) ;
V_348 -> V_245 = NULL ;
F_176 ( V_155 , V_348 ) ;
}
}
static void F_178 ( struct V_154 * V_155 )
{
F_179 ( V_155 -> V_350 -> V_351 , V_155 -> V_184 -> V_172 ) ;
}
static void F_180 ( struct V_21 * V_22 )
{
T_5 V_352 = F_18 () ;
F_85 () ;
V_22 -> V_95 += F_78 ( F_89 ( F_18 () , V_352 ) ) ;
}
static void F_181 ( struct V_21 * V_22 )
{
T_5 V_352 = F_18 () ;
while ( F_182 ( & ( V_22 -> V_245 -> V_353 ) ) != 1 ) {
if ( F_87 ( V_12 ) )
break;
if ( F_183 () )
F_180 ( V_22 ) ;
else
F_184 () ;
}
V_22 -> V_95 += F_78 ( F_89 ( F_18 () , V_352 ) ) ;
}
static void F_185 ( struct V_21 * V_22 )
{
unsigned int V_70 = F_186 ( V_22 -> V_70 ) ;
struct V_169 * V_50 = V_22 -> V_50 ;
struct V_354 * V_355 ;
struct V_244 * V_245 ;
int V_156 ;
if ( F_132 ( ! F_69 ( V_50 ) || ! F_187 ( V_50 ) ) ) {
F_170 ( V_22 ) ;
return;
}
if ( F_132 ( V_22 -> V_29 == V_136 ) ) {
V_22 -> V_222 = F_90 ( F_18 () , V_356 ) ;
return;
}
if ( ! V_22 -> V_245 || ( V_22 -> V_144 &&
++ V_22 -> V_357 >= V_22 -> V_30 ) ) {
F_127 ( V_22 -> V_245 ) ;
V_22 -> V_245 = F_160 ( V_50 , V_22 ) ;
if ( V_22 -> V_245 == NULL ) {
F_48 ( L_264 ) ;
F_85 () ;
V_22 -> V_357 -- ;
return;
}
V_22 -> V_358 = V_22 -> V_245 -> V_121 ;
V_22 -> V_357 = 0 ;
}
if ( V_22 -> V_29 && V_22 -> V_144 )
F_75 ( V_22 , V_22 -> V_222 ) ;
if ( V_22 -> V_72 == V_73 ) {
V_245 = V_22 -> V_245 ;
V_245 -> V_259 = F_188 ( V_245 , V_245 -> V_170 ) ;
F_189 ( V_70 , & V_245 -> V_353 ) ;
F_190 () ;
do {
V_156 = F_191 ( V_245 ) ;
if ( V_156 == V_359 )
V_22 -> V_98 ++ ;
V_22 -> V_97 ++ ;
V_22 -> V_100 ++ ;
if ( F_182 ( & V_245 -> V_353 ) != V_70 ) {
F_192 ( V_70 - 1 , & V_245 -> V_353 ) ;
break;
}
#ifdef F_193
V_245 -> V_360 = 0 ;
#endif
} while ( -- V_70 > 0 );
goto V_157;
} else if ( V_22 -> V_72 == V_74 ) {
F_190 () ;
F_194 ( & V_22 -> V_245 -> V_353 ) ;
V_156 = F_195 ( V_22 -> V_245 ) ;
switch ( V_156 ) {
case V_361 :
V_22 -> V_97 ++ ;
V_22 -> V_100 ++ ;
V_22 -> V_335 += V_22 -> V_358 ;
break;
case V_362 :
case V_363 :
case V_364 :
default:
V_22 -> V_98 ++ ;
F_156 ( L_265 ,
V_22 -> V_31 , V_156 ) ;
break;
}
goto V_157;
}
V_355 = F_196 ( V_50 , V_22 -> V_245 ) ;
F_190 () ;
F_197 ( V_50 , V_355 , F_103 () ) ;
if ( F_132 ( F_198 ( V_355 ) ) ) {
V_156 = V_364 ;
V_22 -> V_144 = 0 ;
goto V_365;
}
F_189 ( V_70 , & V_22 -> V_245 -> V_353 ) ;
V_366:
V_156 = F_199 ( V_22 -> V_245 , V_50 , V_355 , -- V_70 > 0 ) ;
switch ( V_156 ) {
case V_367 :
V_22 -> V_144 = 1 ;
V_22 -> V_97 ++ ;
V_22 -> V_100 ++ ;
V_22 -> V_335 += V_22 -> V_358 ;
if ( V_70 > 0 && ! F_198 ( V_355 ) )
goto V_366;
break;
case V_362 :
case V_363 :
V_22 -> V_98 ++ ;
break;
default:
F_156 ( L_265 ,
V_22 -> V_31 , V_156 ) ;
V_22 -> V_98 ++ ;
case V_364 :
F_200 ( & ( V_22 -> V_245 -> V_353 ) ) ;
V_22 -> V_144 = 0 ;
}
if ( F_132 ( V_70 ) )
F_192 ( V_70 , & V_22 -> V_245 -> V_353 ) ;
V_365:
F_201 ( V_50 , V_355 ) ;
V_157:
F_202 () ;
if ( ( V_22 -> V_7 != 0 ) && ( V_22 -> V_97 >= V_22 -> V_7 ) ) {
F_181 ( V_22 ) ;
F_170 ( V_22 ) ;
}
}
static int F_203 ( void * V_368 )
{
F_204 ( V_369 ) ;
struct V_154 * V_155 = V_368 ;
struct V_21 * V_22 = NULL ;
int V_370 = V_155 -> V_370 ;
F_43 ( F_103 () != V_370 ) ;
F_205 ( & V_155 -> V_371 ) ;
F_206 ( & V_155 -> V_372 ) ;
F_32 ( L_266 , V_370 , F_207 ( V_12 ) ) ;
F_208 () ;
while ( ! F_209 () ) {
V_22 = F_171 ( V_155 ) ;
if ( F_132 ( ! V_22 && V_155 -> V_159 == 0 ) ) {
if ( V_155 -> V_184 -> V_178 )
break;
F_210 ( V_155 -> V_371 ,
V_155 -> V_159 != 0 ,
V_373 / 10 ) ;
F_211 () ;
continue;
}
if ( F_84 ( V_22 ) ) {
F_185 ( V_22 ) ;
if ( F_183 () )
F_180 ( V_22 ) ;
else
F_184 () ;
}
if ( V_155 -> V_159 & V_337 ) {
F_172 ( V_155 ) ;
V_155 -> V_159 &= ~ ( V_337 ) ;
}
if ( V_155 -> V_159 & V_339 ) {
F_161 ( V_155 ) ;
V_155 -> V_159 &= ~ ( V_339 ) ;
}
if ( V_155 -> V_159 & V_160 ) {
F_177 ( V_155 ) ;
V_155 -> V_159 &= ~ ( V_160 ) ;
}
if ( V_155 -> V_159 & V_165 ) {
F_173 ( V_155 ) ;
V_155 -> V_159 &= ~ ( V_165 ) ;
}
F_211 () ;
}
F_32 ( L_267 , V_155 -> V_350 -> V_351 ) ;
F_172 ( V_155 ) ;
F_32 ( L_268 , V_155 -> V_350 -> V_351 ) ;
F_177 ( V_155 ) ;
F_32 ( L_269 , V_155 -> V_350 -> V_351 ) ;
F_178 ( V_155 ) ;
return 0 ;
}
static struct V_21 * F_57 ( struct V_154 * V_155 ,
const char * V_161 , bool V_162 )
{
struct V_21 * V_343 , * V_22 = NULL ;
T_3 V_121 = strlen ( V_161 ) ;
F_44 () ;
F_45 (p, &t->if_list, list)
if ( strncmp ( V_343 -> V_31 , V_161 , V_121 ) == 0 ) {
if ( V_343 -> V_31 [ V_121 ] ) {
if ( V_162 || V_343 -> V_31 [ V_121 ] != '@' )
continue;
}
V_22 = V_343 ;
break;
}
F_46 () ;
F_32 ( L_270 , V_161 , V_22 ) ;
return V_22 ;
}
static int F_212 ( struct V_154 * V_155 ,
struct V_21 * V_22 )
{
int V_374 = 0 ;
F_213 ( V_155 ) ;
if ( V_22 -> V_375 ) {
F_48 ( L_271 ) ;
V_374 = - V_376 ;
goto V_157;
}
V_22 -> V_93 = 0 ;
V_22 -> V_375 = V_155 ;
F_214 ( & V_22 -> V_349 , & V_155 -> V_377 ) ;
V_157:
F_215 ( V_155 ) ;
return V_374 ;
}
static int F_50 ( struct V_154 * V_155 , const char * V_161 )
{
struct V_21 * V_22 ;
int V_185 ;
int V_71 = F_216 ( V_155 -> V_370 ) ;
V_22 = F_55 ( V_155 -> V_184 , V_161 , V_163 ) ;
if ( V_22 ) {
F_48 ( L_272 ) ;
return - V_376 ;
}
V_22 = F_217 ( sizeof( struct V_21 ) , V_281 , V_71 ) ;
if ( ! V_22 )
return - V_378 ;
strcpy ( V_22 -> V_31 , V_161 ) ;
V_22 -> V_225 = F_218 ( V_151 * sizeof( struct V_379 ) ,
V_71 ) ;
if ( V_22 -> V_225 == NULL ) {
F_219 ( V_22 ) ;
return - V_378 ;
}
V_22 -> V_164 = 0 ;
V_22 -> V_28 = 0 ;
V_22 -> V_29 = V_380 ;
V_22 -> V_7 = V_381 ;
V_22 -> V_97 = 0 ;
V_22 -> V_53 = 9 ;
V_22 -> V_54 = 9 ;
V_22 -> V_55 = 9 ;
V_22 -> V_56 = 9 ;
V_22 -> V_63 = 0 ;
V_22 -> V_64 = 0 ;
V_22 -> V_62 = 0xffff ;
V_22 -> V_66 = 0 ;
V_22 -> V_67 = 0 ;
V_22 -> V_65 = 0xffff ;
V_22 -> V_70 = 1 ;
V_22 -> V_71 = - 1 ;
V_185 = F_67 ( V_155 -> V_184 , V_22 , V_161 ) ;
if ( V_185 )
goto V_382;
if ( V_22 -> V_50 -> V_138 & V_139 )
V_22 -> V_30 = V_383 ;
V_22 -> V_171 = F_61 ( V_161 , 0600 , V_155 -> V_184 -> V_172 ,
& V_173 , V_22 ) ;
if ( ! V_22 -> V_171 ) {
F_48 ( L_273 ,
V_384 , V_161 ) ;
V_185 = - V_18 ;
goto V_385;
}
#ifdef F_17
V_22 -> V_233 = V_247 ;
V_22 -> V_234 = V_386 ;
V_22 -> V_387 . V_388 = V_230 ;
V_22 -> V_250 . V_170 = V_22 -> V_50 ;
F_220 ( & V_22 -> V_250 , V_389 , false ) ;
V_22 -> V_250 . V_390 = & V_22 -> V_250 ;
V_22 -> V_250 . V_391 = & V_22 -> V_387 ;
#endif
return F_212 ( V_155 , V_22 ) ;
V_385:
F_68 ( V_22 -> V_50 ) ;
V_382:
#ifdef F_17
F_117 ( V_22 ) ;
#endif
F_221 ( V_22 -> V_225 ) ;
F_219 ( V_22 ) ;
return V_185 ;
}
static int T_15 F_222 ( int V_370 , struct V_10 * V_11 )
{
struct V_154 * V_155 ;
struct V_392 * V_393 ;
struct V_394 * V_343 ;
V_155 = F_217 ( sizeof( struct V_154 ) , V_281 ,
F_216 ( V_370 ) ) ;
if ( ! V_155 ) {
F_48 ( L_274 ) ;
return - V_378 ;
}
F_223 ( & V_155 -> F_213 ) ;
V_155 -> V_370 = V_370 ;
F_224 ( & V_155 -> V_377 ) ;
F_225 ( & V_155 -> V_395 , & V_11 -> V_396 ) ;
F_226 ( & V_155 -> V_372 ) ;
V_343 = F_227 ( F_203 ,
V_155 ,
F_216 ( V_370 ) ,
L_275 , V_370 ) ;
if ( F_228 ( V_343 ) ) {
F_48 ( L_276 , V_155 -> V_370 ) ;
F_229 ( & V_155 -> V_395 ) ;
F_219 ( V_155 ) ;
return F_230 ( V_343 ) ;
}
F_231 ( V_343 , V_370 ) ;
V_155 -> V_350 = V_343 ;
V_393 = F_61 ( V_155 -> V_350 -> V_351 , 0600 , V_11 -> V_172 ,
& V_397 , V_155 ) ;
if ( ! V_393 ) {
F_48 ( L_273 ,
V_384 , V_155 -> V_350 -> V_351 ) ;
F_232 ( V_343 ) ;
F_229 ( & V_155 -> V_395 ) ;
F_219 ( V_155 ) ;
return - V_18 ;
}
V_155 -> V_184 = V_11 ;
F_233 ( V_343 ) ;
F_234 ( V_343 ) ;
F_235 ( & V_155 -> V_372 ) ;
return 0 ;
}
static void F_236 ( struct V_154 * V_155 ,
struct V_21 * V_22 )
{
struct V_346 * V_347 , * V_120 ;
struct V_21 * V_343 ;
F_213 ( V_155 ) ;
F_174 (q, n, &t->if_list) {
V_343 = F_175 ( V_347 , struct V_21 , V_349 ) ;
if ( V_343 == V_22 )
F_237 ( & V_343 -> V_349 ) ;
}
F_215 ( V_155 ) ;
}
static int F_176 ( struct V_154 * V_155 ,
struct V_21 * V_22 )
{
F_32 ( L_277 , V_22 ) ;
if ( V_22 -> V_93 ) {
F_30 ( L_278 ) ;
F_170 ( V_22 ) ;
}
if ( V_22 -> V_50 ) {
F_68 ( V_22 -> V_50 ) ;
V_22 -> V_50 = NULL ;
}
F_60 ( V_22 -> V_171 ) ;
F_236 ( V_155 , V_22 ) ;
#ifdef F_17
F_117 ( V_22 ) ;
#endif
F_221 ( V_22 -> V_225 ) ;
if ( V_22 -> V_142 )
F_35 ( V_22 -> V_142 ) ;
F_238 ( V_22 , V_398 ) ;
return 0 ;
}
static int T_15 F_239 ( struct V_184 * V_184 )
{
struct V_10 * V_11 = F_4 ( V_184 , V_15 ) ;
struct V_392 * V_393 ;
int V_370 , V_156 = 0 ;
V_11 -> V_184 = V_184 ;
F_224 ( & V_11 -> V_396 ) ;
V_11 -> V_178 = false ;
V_11 -> V_172 = F_240 ( V_384 , V_11 -> V_184 -> V_399 ) ;
if ( ! V_11 -> V_172 ) {
F_30 ( L_279 , V_384 ) ;
return - V_186 ;
}
V_393 = F_241 ( V_400 , 0600 , V_11 -> V_172 , & V_401 ) ;
if ( V_393 == NULL ) {
F_48 ( L_280 , V_400 ) ;
V_156 = - V_18 ;
goto remove;
}
F_242 (cpu) {
int V_185 ;
V_185 = F_222 ( V_370 , V_11 ) ;
if ( V_185 )
F_30 ( L_281 ,
V_370 , V_185 ) ;
}
if ( F_243 ( & V_11 -> V_396 ) ) {
F_48 ( L_282 ) ;
V_156 = - V_186 ;
goto V_402;
}
return 0 ;
V_402:
F_179 ( V_400 , V_11 -> V_172 ) ;
remove:
F_179 ( V_384 , V_11 -> V_184 -> V_399 ) ;
return V_156 ;
}
static void T_16 F_244 ( struct V_184 * V_184 )
{
struct V_10 * V_11 = F_4 ( V_184 , V_15 ) ;
struct V_154 * V_155 ;
struct V_346 * V_347 , * V_120 ;
F_245 ( V_349 ) ;
V_11 -> V_178 = true ;
F_49 ( & V_158 ) ;
F_246 ( & V_11 -> V_396 , & V_349 ) ;
F_51 ( & V_158 ) ;
F_174 (q, n, &list) {
V_155 = F_175 ( V_347 , struct V_154 , V_395 ) ;
F_229 ( & V_155 -> V_395 ) ;
F_232 ( V_155 -> V_350 ) ;
F_247 ( V_155 -> V_350 ) ;
F_219 ( V_155 ) ;
}
F_179 ( V_400 , V_11 -> V_172 ) ;
F_179 ( V_384 , V_11 -> V_184 -> V_399 ) ;
}
static int T_17 F_248 ( void )
{
int V_156 = 0 ;
F_33 ( L_283 , V_4 ) ;
V_156 = F_249 ( & V_403 ) ;
if ( V_156 )
return V_156 ;
V_156 = F_250 ( & V_404 ) ;
if ( V_156 )
F_251 ( & V_403 ) ;
return V_156 ;
}
static void T_18 F_252 ( void )
{
F_253 ( & V_404 ) ;
F_251 ( & V_403 ) ;
}
