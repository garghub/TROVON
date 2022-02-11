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
F_2 ( V_2 , L_31 ) ;
if ( V_22 -> V_37 & V_38 )
F_2 ( V_2 , L_32 ) ;
if ( V_22 -> V_37 & V_74 )
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
if ( V_22 -> V_32 ) {
if ( V_22 -> V_37 & V_84 )
F_2 ( V_2 , L_43 ) ;
else
F_2 ( V_2 , L_44 ) ;
}
#ifdef F_17
if ( V_22 -> V_37 & V_85 ) {
F_2 ( V_2 , L_45 ) ;
if ( V_22 -> V_86 )
F_14 ( V_2 , L_46 , V_22 -> V_86 ) ;
}
#endif
if ( V_22 -> V_37 & V_87 )
F_2 ( V_2 , L_47 ) ;
if ( V_22 -> V_37 & V_88 )
F_2 ( V_2 , L_48 ) ;
if ( V_22 -> V_37 & V_89 )
F_2 ( V_2 , L_49 ) ;
if ( V_22 -> V_37 & V_90 )
F_2 ( V_2 , L_50 ) ;
if ( V_22 -> V_37 & V_91 )
F_2 ( V_2 , L_51 ) ;
F_2 ( V_2 , L_22 ) ;
V_24 = V_22 -> V_92 ? F_18 () : V_22 -> V_93 ;
V_25 = V_22 -> V_94 ;
F_19 ( V_25 , V_95 ) ;
F_14 ( V_2 ,
L_52 ,
( unsigned long long ) V_22 -> V_96 ,
( unsigned long long ) V_22 -> V_97 ) ;
F_14 ( V_2 ,
L_53 ,
( unsigned long long ) F_20 ( V_22 -> V_98 ) ,
( unsigned long long ) F_20 ( V_24 ) ,
( unsigned long long ) V_25 ) ;
F_14 ( V_2 ,
L_54 ,
V_22 -> V_99 , V_22 -> V_100 ,
V_22 -> V_101 ) ;
if ( V_22 -> V_37 & V_38 ) {
F_14 ( V_2 , L_55 ,
& V_22 -> V_102 ,
& V_22 -> V_103 ) ;
} else
F_14 ( V_2 , L_56 ,
& V_22 -> V_104 , & V_22 -> V_105 ) ;
F_14 ( V_2 , L_57 ,
V_22 -> V_106 , V_22 -> V_107 ) ;
F_14 ( V_2 , L_58 , V_22 -> V_108 ) ;
F_14 ( V_2 , L_59 , V_22 -> V_109 ) ;
if ( V_22 -> V_110 [ 0 ] )
F_14 ( V_2 , L_60 , V_22 -> V_110 ) ;
else
F_2 ( V_2 , L_61 ) ;
return 0 ;
}
static int F_21 ( const char T_2 * V_111 , unsigned long V_112 ,
T_7 * V_113 )
{
int V_60 = 0 ;
* V_113 = 0 ;
for (; V_60 < V_112 ; V_60 ++ ) {
int V_114 ;
char V_115 ;
* V_113 <<= 4 ;
if ( F_22 ( V_115 , & V_111 [ V_60 ] ) )
return - V_19 ;
V_114 = F_23 ( V_115 ) ;
if ( V_114 >= 0 )
* V_113 |= V_114 ;
else
break;
}
return V_60 ;
}
static int F_24 ( const char T_2 * V_111 ,
unsigned int V_112 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_112 ; V_60 ++ ) {
char V_115 ;
if ( F_22 ( V_115 , & V_111 [ V_60 ] ) )
return - V_19 ;
switch ( V_115 ) {
case '\"' :
case '\n' :
case '\r' :
case '\t' :
case ' ' :
case '=' :
break;
default:
goto V_116;
}
}
V_116:
return V_60 ;
}
static long F_25 ( const char T_2 * V_111 , unsigned long V_112 ,
unsigned long * V_113 )
{
int V_60 ;
* V_113 = 0 ;
for ( V_60 = 0 ; V_60 < V_112 ; V_60 ++ ) {
char V_115 ;
if ( F_22 ( V_115 , & V_111 [ V_60 ] ) )
return - V_19 ;
if ( ( V_115 >= '0' ) && ( V_115 <= '9' ) ) {
* V_113 *= 10 ;
* V_113 += V_115 - '0' ;
} else
break;
}
return V_60 ;
}
static int F_26 ( const char T_2 * V_111 , unsigned int V_112 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_112 ; V_60 ++ ) {
char V_115 ;
if ( F_22 ( V_115 , & V_111 [ V_60 ] ) )
return - V_19 ;
switch ( V_115 ) {
case '\"' :
case '\n' :
case '\r' :
case '\t' :
case ' ' :
goto V_117;
default:
break;
}
}
V_117:
return V_60 ;
}
static T_1 F_27 ( const char T_2 * V_118 , struct V_21 * V_22 )
{
unsigned int V_119 = 0 ;
char V_115 ;
T_1 V_60 = 0 ;
int V_120 ;
V_22 -> V_59 = 0 ;
do {
T_7 V_121 ;
V_120 = F_21 ( & V_118 [ V_60 ] , 8 , & V_121 ) ;
if ( V_120 <= 0 )
return V_120 ;
V_22 -> V_61 [ V_119 ] = F_28 ( V_121 ) ;
if ( V_22 -> V_61 [ V_119 ] & V_122 )
V_22 -> V_37 |= V_81 ;
V_60 += V_120 ;
if ( F_22 ( V_115 , & V_118 [ V_60 ] ) )
return - V_19 ;
V_60 ++ ;
V_119 ++ ;
if ( V_119 >= V_123 )
return - V_124 ;
} while ( V_115 == ',' );
V_22 -> V_59 = V_119 ;
return V_60 ;
}
static T_1 F_29 ( struct V_5 * V_5 ,
const char T_2 * V_111 , T_3 V_7 ,
T_4 * V_125 )
{
struct V_1 * V_2 = V_5 -> V_126 ;
struct V_21 * V_22 = V_2 -> V_23 ;
int V_60 , V_127 , V_120 ;
char V_128 [ 16 ] , V_129 [ 32 ] ;
unsigned long V_114 = 0 ;
char * V_130 = NULL ;
int V_121 = 0 ;
char V_6 [ 128 ] ;
V_130 = & ( V_22 -> V_110 [ 0 ] ) ;
if ( V_7 < 1 ) {
F_30 ( L_62 ) ;
return - V_18 ;
}
V_127 = V_7 ;
V_121 = F_24 ( V_111 , V_127 ) ;
if ( V_121 < 0 ) {
F_30 ( L_63 ) ;
return V_121 ;
}
V_60 = V_121 ;
V_120 = F_26 ( & V_111 [ V_60 ] , sizeof( V_128 ) - 1 ) ;
if ( V_120 < 0 )
return V_120 ;
memset ( V_128 , 0 , sizeof( V_128 ) ) ;
if ( F_6 ( V_128 , & V_111 [ V_60 ] , V_120 ) )
return - V_19 ;
V_60 += V_120 ;
V_127 = V_7 - V_60 ;
V_120 = F_24 ( & V_111 [ V_60 ] , V_127 ) ;
if ( V_120 < 0 )
return V_120 ;
V_60 += V_120 ;
if ( V_131 ) {
T_3 V_132 = F_31 ( T_3 , V_7 , 1023 ) ;
char V_133 [ V_132 + 1 ] ;
if ( F_6 ( V_133 , V_111 , V_132 ) )
return - V_19 ;
V_133 [ V_132 ] = 0 ;
F_32 ( L_64 ,
V_128 , ( unsigned long ) V_7 , V_133 ) ;
}
if ( ! strcmp ( V_128 , L_65 ) ) {
V_120 = F_25 ( & V_111 [ V_60 ] , 10 , & V_114 ) ;
if ( V_120 < 0 )
return V_120 ;
V_60 += V_120 ;
if ( V_114 < 14 + 20 + 8 )
V_114 = 14 + 20 + 8 ;
if ( V_114 != V_22 -> V_26 ) {
V_22 -> V_26 = V_114 ;
V_22 -> V_134 = V_114 ;
}
sprintf ( V_130 , L_66 ,
V_22 -> V_26 ) ;
return V_7 ;
}
if ( ! strcmp ( V_128 , L_67 ) ) {
V_120 = F_25 ( & V_111 [ V_60 ] , 10 , & V_114 ) ;
if ( V_120 < 0 )
return V_120 ;
V_60 += V_120 ;
if ( V_114 < 14 + 20 + 8 )
V_114 = 14 + 20 + 8 ;
if ( V_114 != V_22 -> V_27 ) {
V_22 -> V_27 = V_114 ;
V_22 -> V_134 = V_114 ;
}
sprintf ( V_130 , L_68 ,
V_22 -> V_27 ) ;
return V_7 ;
}
if ( ! strcmp ( V_128 , L_69 ) ) {
V_120 = F_25 ( & V_111 [ V_60 ] , 10 , & V_114 ) ;
if ( V_120 < 0 )
return V_120 ;
V_60 += V_120 ;
if ( V_114 < 14 + 20 + 8 )
V_114 = 14 + 20 + 8 ;
if ( V_114 != V_22 -> V_26 ) {
V_22 -> V_26 = V_114 ;
V_22 -> V_27 = V_114 ;
V_22 -> V_134 = V_114 ;
}
sprintf ( V_130 , L_70 , V_22 -> V_26 ) ;
return V_7 ;
}
if ( ! strcmp ( V_128 , L_71 ) ) {
V_120 = F_25 ( & V_111 [ V_60 ] , 10 , & V_114 ) ;
if ( V_120 < 0 )
return V_120 ;
V_60 += V_120 ;
V_131 = V_114 ;
sprintf ( V_130 , L_72 , V_131 ) ;
return V_7 ;
}
if ( ! strcmp ( V_128 , L_73 ) ) {
V_120 = F_25 ( & V_111 [ V_60 ] , 10 , & V_114 ) ;
if ( V_120 < 0 )
return V_120 ;
V_60 += V_120 ;
V_22 -> V_28 = V_114 ;
sprintf ( V_130 , L_74 , V_22 -> V_28 ) ;
return V_7 ;
}
if ( ! strcmp ( V_128 , L_75 ) ) {
V_120 = F_25 ( & V_111 [ V_60 ] , 10 , & V_114 ) ;
if ( V_120 < 0 )
return V_120 ;
V_60 += V_120 ;
if ( V_114 == 0x7FFFFFFF )
V_22 -> V_29 = V_135 ;
else
V_22 -> V_29 = ( T_6 ) V_114 ;
sprintf ( V_130 , L_76 ,
( unsigned long long ) V_22 -> V_29 ) ;
return V_7 ;
}
if ( ! strcmp ( V_128 , L_77 ) ) {
V_120 = F_25 ( & V_111 [ V_60 ] , 10 , & V_114 ) ;
if ( V_120 < 0 )
return V_120 ;
V_60 += V_120 ;
if ( ! V_114 )
return V_120 ;
V_22 -> V_29 = V_22 -> V_26 * 8 * V_95 / V_114 ;
if ( V_131 )
F_33 ( L_78 , V_22 -> V_29 ) ;
sprintf ( V_130 , L_79 , V_114 ) ;
return V_7 ;
}
if ( ! strcmp ( V_128 , L_80 ) ) {
V_120 = F_25 ( & V_111 [ V_60 ] , 10 , & V_114 ) ;
if ( V_120 < 0 )
return V_120 ;
V_60 += V_120 ;
if ( ! V_114 )
return V_120 ;
V_22 -> V_29 = V_136 / V_114 ;
if ( V_131 )
F_33 ( L_78 , V_22 -> V_29 ) ;
sprintf ( V_130 , L_79 , V_114 ) ;
return V_7 ;
}
if ( ! strcmp ( V_128 , L_81 ) ) {
V_120 = F_25 ( & V_111 [ V_60 ] , 10 , & V_114 ) ;
if ( V_120 < 0 )
return V_120 ;
V_60 += V_120 ;
if ( V_114 != V_22 -> V_53 ) {
V_22 -> V_53 = V_114 ;
V_22 -> V_107 = V_114 ;
}
sprintf ( V_130 , L_82 , V_22 -> V_53 ) ;
return V_7 ;
}
if ( ! strcmp ( V_128 , L_83 ) ) {
V_120 = F_25 ( & V_111 [ V_60 ] , 10 , & V_114 ) ;
if ( V_120 < 0 )
return V_120 ;
V_60 += V_120 ;
if ( V_114 != V_22 -> V_55 ) {
V_22 -> V_55 = V_114 ;
V_22 -> V_106 = V_114 ;
}
sprintf ( V_130 , L_84 , V_22 -> V_55 ) ;
return V_7 ;
}
if ( ! strcmp ( V_128 , L_85 ) ) {
V_120 = F_25 ( & V_111 [ V_60 ] , 10 , & V_114 ) ;
if ( V_120 < 0 )
return V_120 ;
V_60 += V_120 ;
if ( V_114 != V_22 -> V_54 ) {
V_22 -> V_54 = V_114 ;
V_22 -> V_107 = V_114 ;
}
sprintf ( V_130 , L_86 , V_22 -> V_54 ) ;
return V_7 ;
}
if ( ! strcmp ( V_128 , L_87 ) ) {
V_120 = F_25 ( & V_111 [ V_60 ] , 10 , & V_114 ) ;
if ( V_120 < 0 )
return V_120 ;
V_60 += V_120 ;
if ( V_114 != V_22 -> V_56 ) {
V_22 -> V_56 = V_114 ;
V_22 -> V_106 = V_114 ;
}
sprintf ( V_130 , L_88 , V_22 -> V_56 ) ;
return V_7 ;
}
if ( ! strcmp ( V_128 , L_89 ) ) {
V_120 = F_25 ( & V_111 [ V_60 ] , 10 , & V_114 ) ;
if ( V_120 < 0 )
return V_120 ;
if ( ( V_114 > 0 ) &&
( ( V_22 -> V_72 == V_73 ) ||
! ( V_22 -> V_50 -> V_137 & V_138 ) ) )
return - V_139 ;
V_60 += V_120 ;
V_22 -> V_30 = V_114 ;
sprintf ( V_130 , L_90 , V_22 -> V_30 ) ;
return V_7 ;
}
if ( ! strcmp ( V_128 , L_91 ) ) {
V_120 = F_25 ( & V_111 [ V_60 ] , 10 , & V_114 ) ;
if ( V_120 < 0 )
return V_120 ;
V_60 += V_120 ;
V_22 -> V_7 = V_114 ;
sprintf ( V_130 , L_92 ,
( unsigned long long ) V_22 -> V_7 ) ;
return V_7 ;
}
if ( ! strcmp ( V_128 , L_93 ) ) {
V_120 = F_25 ( & V_111 [ V_60 ] , 10 , & V_114 ) ;
if ( V_120 < 0 )
return V_120 ;
V_60 += V_120 ;
if ( V_22 -> V_57 != V_114 ) {
V_22 -> V_57 = V_114 ;
V_22 -> V_101 = 0 ;
}
sprintf ( V_130 , L_94 ,
V_22 -> V_57 ) ;
return V_7 ;
}
if ( ! strcmp ( V_128 , L_95 ) ) {
V_120 = F_25 ( & V_111 [ V_60 ] , 10 , & V_114 ) ;
if ( V_120 < 0 )
return V_120 ;
V_60 += V_120 ;
if ( V_22 -> V_58 != V_114 ) {
V_22 -> V_58 = V_114 ;
V_22 -> V_100 = 0 ;
}
sprintf ( V_130 , L_96 ,
V_22 -> V_58 ) ;
return V_7 ;
}
if ( ! strcmp ( V_128 , L_97 ) ) {
V_120 = F_25 ( & V_111 [ V_60 ] , 10 , & V_114 ) ;
if ( V_120 < 0 )
return V_120 ;
V_60 += V_120 ;
if ( ( V_114 > 1 ) && ( V_22 -> V_72 == V_140 ) &&
( ! ( V_22 -> V_50 -> V_137 & V_138 ) ) )
return - V_139 ;
V_22 -> V_70 = V_114 < 1 ? 1 : V_114 ;
sprintf ( V_130 , L_98 , V_22 -> V_70 ) ;
return V_7 ;
}
if ( ! strcmp ( V_128 , L_99 ) ) {
V_120 = F_25 ( & V_111 [ V_60 ] , 10 , & V_114 ) ;
if ( V_120 < 0 )
return V_120 ;
V_60 += V_120 ;
if ( F_34 ( V_114 ) ) {
V_22 -> V_71 = V_114 ;
sprintf ( V_130 , L_100 , V_22 -> V_71 ) ;
if ( V_22 -> V_141 ) {
F_35 ( V_22 -> V_141 ) ;
V_22 -> V_141 = NULL ;
}
}
else
sprintf ( V_130 , L_101 ) ;
return V_7 ;
}
if ( ! strcmp ( V_128 , L_102 ) ) {
char V_142 [ 32 ] ;
memset ( V_142 , 0 , 32 ) ;
V_120 = F_26 ( & V_111 [ V_60 ] , sizeof( V_142 ) - 1 ) ;
if ( V_120 < 0 )
return V_120 ;
if ( F_6 ( V_142 , & V_111 [ V_60 ] , V_120 ) )
return - V_19 ;
V_60 += V_120 ;
if ( strcmp ( V_142 , L_103 ) == 0 ) {
V_22 -> V_72 = V_140 ;
} else if ( strcmp ( V_142 , L_104 ) == 0 ) {
if ( V_22 -> V_30 > 0 )
return - V_139 ;
V_22 -> V_72 = V_73 ;
V_22 -> V_143 = 1 ;
V_22 -> V_30 = 0 ;
} else {
sprintf ( V_130 ,
L_105 ,
V_142 , L_106 ) ;
return V_7 ;
}
sprintf ( V_130 , L_107 , V_142 ) ;
return V_7 ;
}
if ( ! strcmp ( V_128 , L_108 ) ) {
char V_142 [ 32 ] ;
memset ( V_142 , 0 , 32 ) ;
V_120 = F_26 ( & V_111 [ V_60 ] , sizeof( V_142 ) - 1 ) ;
if ( V_120 < 0 )
return V_120 ;
if ( F_6 ( V_142 , & V_111 [ V_60 ] , V_120 ) )
return - V_19 ;
V_60 += V_120 ;
if ( strcmp ( V_142 , L_109 ) == 0 )
V_22 -> V_37 |= V_74 ;
else if ( strcmp ( V_142 , L_110 ) == 0 )
V_22 -> V_37 &= ~ V_74 ;
else if ( strcmp ( V_142 , L_111 ) == 0 )
V_22 -> V_37 |= V_76 ;
else if ( strcmp ( V_142 , L_112 ) == 0 )
V_22 -> V_37 &= ~ V_76 ;
else if ( strcmp ( V_142 , L_113 ) == 0 )
V_22 -> V_37 |= V_75 ;
else if ( strcmp ( V_142 , L_114 ) == 0 )
V_22 -> V_37 &= ~ V_75 ;
else if ( strcmp ( V_142 , L_115 ) == 0 )
V_22 -> V_37 |= V_77 ;
else if ( strcmp ( V_142 , L_116 ) == 0 )
V_22 -> V_37 &= ~ V_77 ;
else if ( strcmp ( V_142 , L_117 ) == 0 )
V_22 -> V_37 |= V_78 ;
else if ( strcmp ( V_142 , L_118 ) == 0 )
V_22 -> V_37 &= ~ V_78 ;
else if ( strcmp ( V_142 , L_119 ) == 0 )
V_22 -> V_37 |= V_87 ;
else if ( strcmp ( V_142 , L_120 ) == 0 )
V_22 -> V_37 &= ~ V_87 ;
else if ( strcmp ( V_142 , L_121 ) == 0 )
V_22 -> V_37 |= V_88 ;
else if ( strcmp ( V_142 , L_122 ) == 0 )
V_22 -> V_37 &= ~ V_88 ;
else if ( strcmp ( V_142 , L_123 ) == 0 )
V_22 -> V_37 |= V_81 ;
else if ( strcmp ( V_142 , L_124 ) == 0 )
V_22 -> V_37 &= ~ V_81 ;
else if ( strcmp ( V_142 , L_125 ) == 0 )
V_22 -> V_37 |= V_89 ;
else if ( strcmp ( V_142 , L_126 ) == 0 )
V_22 -> V_37 &= ~ V_89 ;
else if ( strcmp ( V_142 , L_127 ) == 0 )
V_22 -> V_37 |= V_90 ;
else if ( strcmp ( V_142 , L_128 ) == 0 )
V_22 -> V_37 &= ~ V_90 ;
else if ( strcmp ( V_142 , L_129 ) == 0 )
V_22 -> V_37 |= V_84 ;
else if ( strcmp ( V_142 , L_130 ) == 0 )
V_22 -> V_37 |= V_82 ;
else if ( strcmp ( V_142 , L_131 ) == 0 )
V_22 -> V_37 &= ~ V_82 ;
else if ( strcmp ( V_142 , L_132 ) == 0 )
V_22 -> V_37 |= V_83 ;
else if ( strcmp ( V_142 , L_133 ) == 0 )
V_22 -> V_37 &= ~ V_83 ;
#ifdef F_17
else if ( strcmp ( V_142 , L_134 ) == 0 )
V_22 -> V_37 |= V_85 ;
#endif
else if ( strcmp ( V_142 , L_135 ) == 0 )
V_22 -> V_37 &= ~ V_38 ;
else if ( strcmp ( V_142 , L_136 ) == 0 )
V_22 -> V_37 |= V_91 ;
else if ( strcmp ( V_142 , L_137 ) == 0 )
V_22 -> V_37 &= ~ V_91 ;
else if ( strcmp ( V_142 , L_138 ) == 0 )
V_22 -> V_37 |= V_79 ;
else if ( strcmp ( V_142 , L_139 ) == 0 )
V_22 -> V_37 &= ~ V_79 ;
else if ( strcmp ( V_142 , L_140 ) == 0 )
V_22 -> V_37 |= V_80 ;
else if ( strcmp ( V_142 , L_141 ) == 0 )
V_22 -> V_37 &= ~ V_80 ;
else {
sprintf ( V_130 ,
L_142 ,
V_142 ,
L_143
L_144
L_145
L_146
L_147
#ifdef F_17
L_148
#endif
L_149 ) ;
return V_7 ;
}
sprintf ( V_130 , L_150 , V_22 -> V_37 ) ;
return V_7 ;
}
if ( ! strcmp ( V_128 , L_151 ) || ! strcmp ( V_128 , L_152 ) ) {
V_120 = F_26 ( & V_111 [ V_60 ] , sizeof( V_22 -> V_45 ) - 1 ) ;
if ( V_120 < 0 )
return V_120 ;
if ( F_6 ( V_6 , & V_111 [ V_60 ] , V_120 ) )
return - V_19 ;
V_6 [ V_120 ] = 0 ;
if ( strcmp ( V_6 , V_22 -> V_45 ) != 0 ) {
memset ( V_22 -> V_45 , 0 , sizeof( V_22 -> V_45 ) ) ;
strncpy ( V_22 -> V_45 , V_6 , V_120 ) ;
V_22 -> V_144 = F_36 ( V_22 -> V_45 ) ;
V_22 -> V_105 = V_22 -> V_144 ;
}
if ( V_131 )
F_32 ( L_153 , V_22 -> V_45 ) ;
V_60 += V_120 ;
sprintf ( V_130 , L_154 , V_22 -> V_45 ) ;
return V_7 ;
}
if ( ! strcmp ( V_128 , L_155 ) ) {
V_120 = F_26 ( & V_111 [ V_60 ] , sizeof( V_22 -> V_46 ) - 1 ) ;
if ( V_120 < 0 )
return V_120 ;
if ( F_6 ( V_6 , & V_111 [ V_60 ] , V_120 ) )
return - V_19 ;
V_6 [ V_120 ] = 0 ;
if ( strcmp ( V_6 , V_22 -> V_46 ) != 0 ) {
memset ( V_22 -> V_46 , 0 , sizeof( V_22 -> V_46 ) ) ;
strncpy ( V_22 -> V_46 , V_6 , V_120 ) ;
V_22 -> V_145 = F_36 ( V_22 -> V_46 ) ;
V_22 -> V_105 = V_22 -> V_145 ;
}
if ( V_131 )
F_32 ( L_156 , V_22 -> V_46 ) ;
V_60 += V_120 ;
sprintf ( V_130 , L_157 , V_22 -> V_46 ) ;
return V_7 ;
}
if ( ! strcmp ( V_128 , L_158 ) ) {
V_120 = F_26 ( & V_111 [ V_60 ] , sizeof( V_6 ) - 1 ) ;
if ( V_120 < 0 )
return V_120 ;
V_22 -> V_37 |= V_38 ;
if ( F_6 ( V_6 , & V_111 [ V_60 ] , V_120 ) )
return - V_19 ;
V_6 [ V_120 ] = 0 ;
F_37 ( V_6 , - 1 , V_22 -> V_42 . V_146 , - 1 , NULL ) ;
snprintf ( V_6 , sizeof( V_6 ) , L_159 , & V_22 -> V_42 ) ;
V_22 -> V_103 = V_22 -> V_42 ;
if ( V_131 )
F_32 ( L_160 , V_6 ) ;
V_60 += V_120 ;
sprintf ( V_130 , L_161 , V_6 ) ;
return V_7 ;
}
if ( ! strcmp ( V_128 , L_162 ) ) {
V_120 = F_26 ( & V_111 [ V_60 ] , sizeof( V_6 ) - 1 ) ;
if ( V_120 < 0 )
return V_120 ;
V_22 -> V_37 |= V_38 ;
if ( F_6 ( V_6 , & V_111 [ V_60 ] , V_120 ) )
return - V_19 ;
V_6 [ V_120 ] = 0 ;
F_37 ( V_6 , - 1 , V_22 -> V_43 . V_146 , - 1 , NULL ) ;
snprintf ( V_6 , sizeof( V_6 ) , L_159 , & V_22 -> V_43 ) ;
V_22 -> V_103 = V_22 -> V_43 ;
if ( V_131 )
F_32 ( L_163 , V_6 ) ;
V_60 += V_120 ;
sprintf ( V_130 , L_164 , V_6 ) ;
return V_7 ;
}
if ( ! strcmp ( V_128 , L_165 ) ) {
V_120 = F_26 ( & V_111 [ V_60 ] , sizeof( V_6 ) - 1 ) ;
if ( V_120 < 0 )
return V_120 ;
V_22 -> V_37 |= V_38 ;
if ( F_6 ( V_6 , & V_111 [ V_60 ] , V_120 ) )
return - V_19 ;
V_6 [ V_120 ] = 0 ;
F_37 ( V_6 , - 1 , V_22 -> V_44 . V_146 , - 1 , NULL ) ;
snprintf ( V_6 , sizeof( V_6 ) , L_159 , & V_22 -> V_44 ) ;
if ( V_131 )
F_32 ( L_166 , V_6 ) ;
V_60 += V_120 ;
sprintf ( V_130 , L_167 , V_6 ) ;
return V_7 ;
}
if ( ! strcmp ( V_128 , L_168 ) ) {
V_120 = F_26 ( & V_111 [ V_60 ] , sizeof( V_6 ) - 1 ) ;
if ( V_120 < 0 )
return V_120 ;
V_22 -> V_37 |= V_38 ;
if ( F_6 ( V_6 , & V_111 [ V_60 ] , V_120 ) )
return - V_19 ;
V_6 [ V_120 ] = 0 ;
F_37 ( V_6 , - 1 , V_22 -> V_39 . V_146 , - 1 , NULL ) ;
snprintf ( V_6 , sizeof( V_6 ) , L_159 , & V_22 -> V_39 ) ;
V_22 -> V_102 = V_22 -> V_39 ;
if ( V_131 )
F_32 ( L_169 , V_6 ) ;
V_60 += V_120 ;
sprintf ( V_130 , L_170 , V_6 ) ;
return V_7 ;
}
if ( ! strcmp ( V_128 , L_171 ) ) {
V_120 = F_26 ( & V_111 [ V_60 ] , sizeof( V_22 -> V_47 ) - 1 ) ;
if ( V_120 < 0 )
return V_120 ;
if ( F_6 ( V_6 , & V_111 [ V_60 ] , V_120 ) )
return - V_19 ;
V_6 [ V_120 ] = 0 ;
if ( strcmp ( V_6 , V_22 -> V_47 ) != 0 ) {
memset ( V_22 -> V_47 , 0 , sizeof( V_22 -> V_47 ) ) ;
strncpy ( V_22 -> V_47 , V_6 , V_120 ) ;
V_22 -> V_147 = F_36 ( V_22 -> V_47 ) ;
V_22 -> V_104 = V_22 -> V_147 ;
}
if ( V_131 )
F_32 ( L_172 , V_22 -> V_47 ) ;
V_60 += V_120 ;
sprintf ( V_130 , L_173 , V_22 -> V_47 ) ;
return V_7 ;
}
if ( ! strcmp ( V_128 , L_174 ) ) {
V_120 = F_26 ( & V_111 [ V_60 ] , sizeof( V_22 -> V_48 ) - 1 ) ;
if ( V_120 < 0 )
return V_120 ;
if ( F_6 ( V_6 , & V_111 [ V_60 ] , V_120 ) )
return - V_19 ;
V_6 [ V_120 ] = 0 ;
if ( strcmp ( V_6 , V_22 -> V_48 ) != 0 ) {
memset ( V_22 -> V_48 , 0 , sizeof( V_22 -> V_48 ) ) ;
strncpy ( V_22 -> V_48 , V_6 , V_120 ) ;
V_22 -> V_148 = F_36 ( V_22 -> V_48 ) ;
V_22 -> V_104 = V_22 -> V_148 ;
}
if ( V_131 )
F_32 ( L_175 , V_22 -> V_48 ) ;
V_60 += V_120 ;
sprintf ( V_130 , L_176 , V_22 -> V_48 ) ;
return V_7 ;
}
if ( ! strcmp ( V_128 , L_177 ) ) {
V_120 = F_26 ( & V_111 [ V_60 ] , sizeof( V_129 ) - 1 ) ;
if ( V_120 < 0 )
return V_120 ;
memset ( V_129 , 0 , sizeof( V_129 ) ) ;
if ( F_6 ( V_129 , & V_111 [ V_60 ] , V_120 ) )
return - V_19 ;
if ( ! F_38 ( V_129 , V_22 -> V_52 ) )
return - V_18 ;
F_39 ( & V_22 -> V_149 [ 0 ] , V_22 -> V_52 ) ;
sprintf ( V_130 , L_178 , V_22 -> V_52 ) ;
return V_7 ;
}
if ( ! strcmp ( V_128 , L_179 ) ) {
V_120 = F_26 ( & V_111 [ V_60 ] , sizeof( V_129 ) - 1 ) ;
if ( V_120 < 0 )
return V_120 ;
memset ( V_129 , 0 , sizeof( V_129 ) ) ;
if ( F_6 ( V_129 , & V_111 [ V_60 ] , V_120 ) )
return - V_19 ;
if ( ! F_38 ( V_129 , V_22 -> V_49 ) )
return - V_18 ;
F_39 ( & V_22 -> V_149 [ 6 ] , V_22 -> V_49 ) ;
sprintf ( V_130 , L_180 , V_22 -> V_49 ) ;
return V_7 ;
}
if ( ! strcmp ( V_128 , L_181 ) ) {
F_40 ( V_22 ) ;
sprintf ( V_130 , L_182 ) ;
return V_7 ;
}
if ( ! strcmp ( V_128 , L_183 ) ) {
V_120 = F_25 ( & V_111 [ V_60 ] , 10 , & V_114 ) ;
if ( V_120 < 0 )
return V_120 ;
V_60 += V_120 ;
if ( V_114 > V_150 )
V_114 = V_150 ;
V_22 -> V_32 = V_114 ;
sprintf ( V_130 , L_184 , V_22 -> V_32 ) ;
return V_7 ;
}
#ifdef F_17
if ( ! strcmp ( V_128 , L_185 ) ) {
V_120 = F_25 ( & V_111 [ V_60 ] , 10 , & V_114 ) ;
if ( V_120 < 0 )
return V_120 ;
V_60 += V_120 ;
V_22 -> V_86 = V_114 ;
sprintf ( V_130 , L_186 , V_22 -> V_86 ) ;
return V_7 ;
}
#endif
if ( ! strcmp ( V_128 , L_187 ) ) {
V_120 = F_25 ( & V_111 [ V_60 ] , 10 , & V_114 ) ;
if ( V_120 < 0 )
return V_120 ;
V_60 += V_120 ;
V_22 -> V_33 = V_114 ;
sprintf ( V_130 , L_188 , V_22 -> V_33 ) ;
return V_7 ;
}
if ( ! strcmp ( V_128 , L_189 ) ) {
V_120 = F_25 ( & V_111 [ V_60 ] , 5 , & V_114 ) ;
if ( V_120 < 0 )
return V_120 ;
V_60 += V_120 ;
V_22 -> V_34 = V_114 ;
sprintf ( V_130 , L_190 , V_22 -> V_34 ) ;
return V_7 ;
}
if ( ! strcmp ( V_128 , L_191 ) ) {
V_120 = F_25 ( & V_111 [ V_60 ] , 5 , & V_114 ) ;
if ( V_120 < 0 )
return V_120 ;
V_60 += V_120 ;
V_22 -> V_35 = V_114 ;
sprintf ( V_130 , L_192 , V_22 -> V_35 ) ;
return V_7 ;
}
if ( ! strcmp ( V_128 , L_193 ) ) {
unsigned int V_119 , V_151 ;
V_120 = F_27 ( & V_111 [ V_60 ] , V_22 ) ;
if ( V_120 < 0 )
return V_120 ;
V_60 += V_120 ;
V_151 = sprintf ( V_130 , L_194 ) ;
for ( V_119 = 0 ; V_119 < V_22 -> V_59 ; V_119 ++ )
V_151 += sprintf ( V_130 + V_151 ,
L_21 , F_16 ( V_22 -> V_61 [ V_119 ] ) ,
V_119 == V_22 -> V_59 - 1 ? L_195 : L_196 ) ;
if ( V_22 -> V_59 && V_22 -> V_62 != 0xffff ) {
V_22 -> V_62 = 0xffff ;
V_22 -> V_65 = 0xffff ;
if ( V_131 )
F_32 ( L_197 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_128 , L_198 ) ) {
V_120 = F_25 ( & V_111 [ V_60 ] , 4 , & V_114 ) ;
if ( V_120 < 0 )
return V_120 ;
V_60 += V_120 ;
if ( V_114 <= 4095 ) {
V_22 -> V_62 = V_114 ;
if ( V_131 )
F_32 ( L_199 ) ;
if ( V_131 && V_22 -> V_59 )
F_32 ( L_200 ) ;
V_22 -> V_59 = 0 ;
sprintf ( V_130 , L_201 , V_22 -> V_62 ) ;
} else {
V_22 -> V_62 = 0xffff ;
V_22 -> V_65 = 0xffff ;
if ( V_131 )
F_32 ( L_202 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_128 , L_203 ) ) {
V_120 = F_25 ( & V_111 [ V_60 ] , 1 , & V_114 ) ;
if ( V_120 < 0 )
return V_120 ;
V_60 += V_120 ;
if ( ( V_114 <= 7 ) && ( V_22 -> V_62 != 0xffff ) ) {
V_22 -> V_63 = V_114 ;
sprintf ( V_130 , L_204 , V_22 -> V_63 ) ;
} else {
sprintf ( V_130 , L_205 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_128 , L_206 ) ) {
V_120 = F_25 ( & V_111 [ V_60 ] , 1 , & V_114 ) ;
if ( V_120 < 0 )
return V_120 ;
V_60 += V_120 ;
if ( ( V_114 <= 1 ) && ( V_22 -> V_62 != 0xffff ) ) {
V_22 -> V_64 = V_114 ;
sprintf ( V_130 , L_207 , V_22 -> V_64 ) ;
} else {
sprintf ( V_130 , L_208 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_128 , L_209 ) ) {
V_120 = F_25 ( & V_111 [ V_60 ] , 4 , & V_114 ) ;
if ( V_120 < 0 )
return V_120 ;
V_60 += V_120 ;
if ( ( V_114 <= 4095 ) && ( ( V_22 -> V_62 != 0xffff ) ) ) {
V_22 -> V_65 = V_114 ;
if ( V_131 )
F_32 ( L_210 ) ;
if ( V_131 && V_22 -> V_59 )
F_32 ( L_200 ) ;
V_22 -> V_59 = 0 ;
sprintf ( V_130 , L_211 , V_22 -> V_65 ) ;
} else {
V_22 -> V_62 = 0xffff ;
V_22 -> V_65 = 0xffff ;
if ( V_131 )
F_32 ( L_202 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_128 , L_212 ) ) {
V_120 = F_25 ( & V_111 [ V_60 ] , 1 , & V_114 ) ;
if ( V_120 < 0 )
return V_120 ;
V_60 += V_120 ;
if ( ( V_114 <= 7 ) && ( V_22 -> V_65 != 0xffff ) ) {
V_22 -> V_66 = V_114 ;
sprintf ( V_130 , L_213 , V_22 -> V_66 ) ;
} else {
sprintf ( V_130 , L_214 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_128 , L_215 ) ) {
V_120 = F_25 ( & V_111 [ V_60 ] , 1 , & V_114 ) ;
if ( V_120 < 0 )
return V_120 ;
V_60 += V_120 ;
if ( ( V_114 <= 1 ) && ( V_22 -> V_65 != 0xffff ) ) {
V_22 -> V_67 = V_114 ;
sprintf ( V_130 , L_216 , V_22 -> V_67 ) ;
} else {
sprintf ( V_130 , L_217 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_128 , L_218 ) ) {
T_7 V_152 = 0 ;
V_120 = F_21 ( & V_111 [ V_60 ] , 2 , & V_152 ) ;
if ( V_120 < 0 )
return V_120 ;
V_60 += V_120 ;
if ( V_120 == 2 ) {
V_22 -> V_68 = V_152 ;
sprintf ( V_130 , L_219 , V_22 -> V_68 ) ;
} else {
sprintf ( V_130 , L_220 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_128 , L_221 ) ) {
T_7 V_152 = 0 ;
V_120 = F_21 ( & V_111 [ V_60 ] , 2 , & V_152 ) ;
if ( V_120 < 0 )
return V_120 ;
V_60 += V_120 ;
if ( V_120 == 2 ) {
V_22 -> V_69 = V_152 ;
sprintf ( V_130 , L_222 , V_22 -> V_69 ) ;
} else {
sprintf ( V_130 , L_223 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_128 , L_224 ) ) {
V_120 = F_25 ( & V_111 [ V_60 ] , 9 , & V_114 ) ;
if ( V_120 < 0 )
return V_120 ;
V_60 += V_120 ;
V_22 -> V_36 = V_114 ;
sprintf ( V_130 , L_225 ,
V_22 -> V_36 ) ;
return V_7 ;
}
sprintf ( V_22 -> V_110 , L_226 , V_128 ) ;
return - V_18 ;
}
static int F_41 ( struct V_20 * V_20 , struct V_5 * V_5 )
{
return F_11 ( V_5 , F_13 , F_12 ( V_20 ) ) ;
}
static int F_42 ( struct V_1 * V_2 , void * V_3 )
{
struct V_153 * V_154 = V_2 -> V_23 ;
const struct V_21 * V_22 ;
F_43 ( ! V_154 ) ;
F_2 ( V_2 , L_227 ) ;
F_44 () ;
F_45 (pkt_dev, &t->if_list, list)
if ( V_22 -> V_92 )
F_14 ( V_2 , L_228 , V_22 -> V_31 ) ;
F_2 ( V_2 , L_229 ) ;
F_45 (pkt_dev, &t->if_list, list)
if ( ! V_22 -> V_92 )
F_14 ( V_2 , L_228 , V_22 -> V_31 ) ;
if ( V_154 -> V_110 [ 0 ] )
F_14 ( V_2 , L_230 , V_154 -> V_110 ) ;
else
F_2 ( V_2 , L_231 ) ;
F_46 () ;
return 0 ;
}
static T_1 F_47 ( struct V_5 * V_5 ,
const char T_2 * V_111 ,
T_3 V_7 , T_4 * V_125 )
{
struct V_1 * V_2 = V_5 -> V_126 ;
struct V_153 * V_154 = V_2 -> V_23 ;
int V_60 , V_127 , V_120 , V_155 ;
char V_128 [ 40 ] ;
char * V_130 ;
if ( V_7 < 1 ) {
return - V_18 ;
}
V_127 = V_7 ;
V_120 = F_24 ( V_111 , V_127 ) ;
if ( V_120 < 0 )
return V_120 ;
V_60 = V_120 ;
V_120 = F_26 ( & V_111 [ V_60 ] , sizeof( V_128 ) - 1 ) ;
if ( V_120 < 0 )
return V_120 ;
memset ( V_128 , 0 , sizeof( V_128 ) ) ;
if ( F_6 ( V_128 , & V_111 [ V_60 ] , V_120 ) )
return - V_19 ;
V_60 += V_120 ;
V_127 = V_7 - V_60 ;
V_120 = F_24 ( & V_111 [ V_60 ] , V_127 ) ;
if ( V_120 < 0 )
return V_120 ;
V_60 += V_120 ;
if ( V_131 )
F_32 ( L_232 , V_128 , ( unsigned long ) V_7 ) ;
if ( ! V_154 ) {
F_48 ( L_233 ) ;
V_155 = - V_18 ;
goto V_156;
}
V_130 = & ( V_154 -> V_110 [ 0 ] ) ;
if ( ! strcmp ( V_128 , L_234 ) ) {
char V_142 [ 32 ] ;
memset ( V_142 , 0 , 32 ) ;
V_120 = F_26 ( & V_111 [ V_60 ] , sizeof( V_142 ) - 1 ) ;
if ( V_120 < 0 ) {
V_155 = V_120 ;
goto V_156;
}
if ( F_6 ( V_142 , & V_111 [ V_60 ] , V_120 ) )
return - V_19 ;
V_60 += V_120 ;
F_49 ( & V_157 ) ;
V_155 = F_50 ( V_154 , V_142 ) ;
F_51 ( & V_157 ) ;
if ( ! V_155 ) {
V_155 = V_7 ;
sprintf ( V_130 , L_235 , V_142 ) ;
} else
sprintf ( V_130 , L_236 , V_142 ) ;
goto V_156;
}
if ( ! strcmp ( V_128 , L_237 ) ) {
F_49 ( & V_157 ) ;
V_154 -> V_158 |= V_159 ;
F_51 ( & V_157 ) ;
F_52 ( F_53 ( 125 ) ) ;
V_155 = V_7 ;
sprintf ( V_130 , L_238 ) ;
goto V_156;
}
if ( ! strcmp ( V_128 , L_239 ) ) {
sprintf ( V_130 , L_240 ) ;
V_155 = V_7 ;
goto V_156;
}
V_155 = - V_18 ;
V_156:
return V_155 ;
}
static int F_54 ( struct V_20 * V_20 , struct V_5 * V_5 )
{
return F_11 ( V_5 , F_42 , F_12 ( V_20 ) ) ;
}
static struct V_21 * F_55 ( const struct V_10 * V_11 ,
const char * V_160 , int remove )
{
struct V_153 * V_154 ;
struct V_21 * V_22 = NULL ;
bool V_161 = ( remove == V_162 ) ;
F_56 (t, &pn->pktgen_threads, th_list) {
V_22 = F_57 ( V_154 , V_160 , V_161 ) ;
if ( V_22 ) {
if ( remove ) {
V_22 -> V_163 = 1 ;
V_154 -> V_158 |= V_164 ;
}
break;
}
}
return V_22 ;
}
static void F_58 ( const struct V_10 * V_11 , const char * V_160 )
{
struct V_21 * V_22 = NULL ;
const int V_165 = 10 , V_166 = 125 ;
int V_60 = 0 ;
F_49 ( & V_157 ) ;
F_32 ( L_241 , V_167 , V_160 ) ;
while ( 1 ) {
V_22 = F_55 ( V_11 , V_160 , REMOVE ) ;
if ( V_22 == NULL )
break;
F_51 ( & V_157 ) ;
F_32 ( L_242 ,
V_167 , V_160 ) ;
F_52 ( F_53 ( V_166 ) ) ;
F_49 ( & V_157 ) ;
if ( ++ V_60 >= V_165 ) {
F_48 ( L_243 ,
V_167 , V_166 * V_60 , V_160 ) ;
break;
}
}
F_51 ( & V_157 ) ;
}
static void F_59 ( const struct V_10 * V_11 , struct V_168 * V_169 )
{
struct V_153 * V_154 ;
F_56 (t, &pn->pktgen_threads, th_list) {
struct V_21 * V_22 ;
F_44 () ;
F_45 (pkt_dev, &t->if_list, list) {
if ( V_22 -> V_50 != V_169 )
continue;
F_60 ( V_22 -> V_170 ) ;
V_22 -> V_170 = F_61 ( V_169 -> V_128 , 0600 ,
V_11 -> V_171 ,
& V_172 ,
V_22 ) ;
if ( ! V_22 -> V_170 )
F_48 ( L_244 ,
V_169 -> V_128 ) ;
break;
}
F_46 () ;
}
}
static int F_62 ( struct V_173 * V_174 ,
unsigned long V_175 , void * V_176 )
{
struct V_168 * V_169 = F_63 ( V_176 ) ;
struct V_10 * V_11 = F_4 ( F_64 ( V_169 ) , V_15 ) ;
if ( V_11 -> V_177 )
return V_178 ;
switch ( V_175 ) {
case V_179 :
F_59 ( V_11 , V_169 ) ;
break;
case V_180 :
F_58 ( V_11 , V_169 -> V_128 ) ;
break;
}
return V_178 ;
}
static struct V_168 * F_65 ( const struct V_10 * V_11 ,
struct V_21 * V_22 ,
const char * V_160 )
{
char V_181 [ V_182 + 5 ] ;
int V_60 ;
for ( V_60 = 0 ; V_160 [ V_60 ] != '@' ; V_60 ++ ) {
if ( V_60 == V_182 )
break;
V_181 [ V_60 ] = V_160 [ V_60 ] ;
}
V_181 [ V_60 ] = 0 ;
return F_66 ( V_11 -> V_183 , V_181 ) ;
}
static int F_67 ( const struct V_10 * V_11 ,
struct V_21 * V_22 , const char * V_160 )
{
struct V_168 * V_50 ;
int V_184 ;
if ( V_22 -> V_50 ) {
F_68 ( V_22 -> V_50 ) ;
V_22 -> V_50 = NULL ;
}
V_50 = F_65 ( V_11 , V_22 , V_160 ) ;
if ( ! V_50 ) {
F_48 ( L_245 , V_160 ) ;
return - V_185 ;
}
if ( V_50 -> type != V_186 ) {
F_48 ( L_246 , V_160 ) ;
V_184 = - V_18 ;
} else if ( ! F_69 ( V_50 ) ) {
F_48 ( L_247 , V_160 ) ;
V_184 = - V_187 ;
} else {
V_22 -> V_50 = V_50 ;
return 0 ;
}
F_68 ( V_50 ) ;
return V_184 ;
}
static void F_70 ( struct V_21 * V_22 )
{
int V_188 ;
if ( ! V_22 -> V_50 ) {
F_48 ( L_248 ) ;
sprintf ( V_22 -> V_110 ,
L_249 ) ;
return;
}
V_188 = V_22 -> V_50 -> V_189 ;
if ( V_188 <= V_22 -> V_34 ) {
F_30 ( L_250 ,
V_22 -> V_34 , ( V_188 ? : 1 ) - 1 , V_188 ,
V_22 -> V_31 ) ;
V_22 -> V_34 = ( V_188 ? : 1 ) - 1 ;
}
if ( V_22 -> V_35 >= V_188 ) {
F_30 ( L_251 ,
V_22 -> V_35 , ( V_188 ? : 1 ) - 1 , V_188 ,
V_22 -> V_31 ) ;
V_22 -> V_35 = ( V_188 ? : 1 ) - 1 ;
}
if ( F_15 ( V_22 -> V_49 ) )
F_39 ( & ( V_22 -> V_149 [ 6 ] ) , V_22 -> V_50 -> V_51 ) ;
F_39 ( & ( V_22 -> V_149 [ 0 ] ) , V_22 -> V_52 ) ;
if ( V_22 -> V_37 & V_38 ) {
int V_60 , V_190 = 0 , V_184 = 1 ;
struct V_191 * V_192 ;
if ( V_22 -> V_26 == 0 ) {
V_22 -> V_26 = 14 + sizeof( struct V_193 )
+ sizeof( struct V_194 )
+ sizeof( struct V_195 )
+ V_22 -> V_196 ;
}
for ( V_60 = 0 ; V_60 < V_197 ; V_60 ++ )
if ( V_22 -> V_102 . V_146 [ V_60 ] ) {
V_190 = 1 ;
break;
}
if ( ! V_190 ) {
F_44 () ;
V_192 = F_71 ( V_22 -> V_50 ) ;
if ( V_192 ) {
struct V_198 * V_199 ;
F_72 ( & V_192 -> V_200 ) ;
F_56 (ifp, &idev->addr_list, if_list) {
if ( ( V_199 -> V_201 & V_202 ) &&
! ( V_199 -> V_37 & V_203 ) ) {
V_22 -> V_102 = V_199 -> V_204 ;
V_184 = 0 ;
break;
}
}
F_73 ( & V_192 -> V_200 ) ;
}
F_46 () ;
if ( V_184 )
F_48 ( L_252 ) ;
}
} else {
if ( V_22 -> V_26 == 0 ) {
V_22 -> V_26 = 14 + sizeof( struct V_205 )
+ sizeof( struct V_194 )
+ sizeof( struct V_195 )
+ V_22 -> V_196 ;
}
V_22 -> V_147 = 0 ;
V_22 -> V_148 = 0 ;
if ( strlen ( V_22 -> V_47 ) == 0 ) {
struct V_206 * V_207 ;
F_44 () ;
V_207 = F_74 ( V_22 -> V_50 ) ;
if ( V_207 ) {
if ( V_207 -> V_208 ) {
V_22 -> V_147 =
V_207 -> V_208 -> V_209 ;
V_22 -> V_148 = V_22 -> V_147 ;
}
}
F_46 () ;
} else {
V_22 -> V_147 = F_36 ( V_22 -> V_47 ) ;
V_22 -> V_148 = F_36 ( V_22 -> V_48 ) ;
}
V_22 -> V_144 = F_36 ( V_22 -> V_45 ) ;
V_22 -> V_145 = F_36 ( V_22 -> V_46 ) ;
}
V_22 -> V_134 = V_22 -> V_26 ;
if ( V_22 -> V_26 > V_22 -> V_27 )
V_22 -> V_27 = V_22 -> V_26 ;
V_22 -> V_100 = 0 ;
V_22 -> V_101 = 0 ;
V_22 -> V_104 = V_22 -> V_147 ;
V_22 -> V_105 = V_22 -> V_144 ;
V_22 -> V_106 = V_22 -> V_55 ;
V_22 -> V_107 = V_22 -> V_53 ;
V_22 -> V_109 = 0 ;
}
static void F_75 ( struct V_21 * V_22 , T_5 V_210 )
{
T_5 V_211 , V_212 ;
T_8 V_213 ;
struct V_214 V_154 ;
F_76 ( & V_154 . V_215 , V_216 , V_217 ) ;
F_77 ( & V_154 . V_215 , V_210 ) ;
V_213 = F_78 ( F_79 ( & V_154 . V_215 ) ) ;
if ( V_213 <= 0 ) {
V_22 -> V_218 = F_80 ( V_210 , V_22 -> V_29 ) ;
return;
}
V_211 = F_18 () ;
if ( V_213 < 100000 ) {
do {
V_212 = F_18 () ;
} while ( F_81 ( V_212 , V_210 ) < 0 );
} else {
F_82 ( & V_154 , V_12 ) ;
do {
F_83 ( V_219 ) ;
F_84 ( & V_154 . V_215 , V_217 ) ;
if ( F_85 ( V_154 . V_220 ) )
F_86 () ;
F_87 ( & V_154 . V_215 ) ;
} while ( V_154 . V_220 && V_22 -> V_92 && ! F_88 ( V_12 ) );
F_89 ( V_221 ) ;
V_212 = F_18 () ;
}
V_22 -> V_94 += F_78 ( F_90 ( V_212 , V_211 ) ) ;
V_22 -> V_218 = F_80 ( V_210 , V_22 -> V_29 ) ;
}
static inline void F_91 ( struct V_21 * V_22 )
{
V_22 -> V_196 = F_92 ( V_22 -> V_50 ) ;
V_22 -> V_196 += V_22 -> V_59 * sizeof( V_222 ) ;
V_22 -> V_196 += F_93 ( V_22 ) ;
V_22 -> V_196 += F_94 ( V_22 ) ;
}
static inline int F_95 ( const struct V_21 * V_22 , int V_223 )
{
return ! ! ( V_22 -> V_224 [ V_223 ] . V_37 & V_225 ) ;
}
static inline int F_96 ( struct V_21 * V_22 )
{
int V_223 = V_22 -> V_226 ;
if ( V_22 -> V_37 & V_84 ) {
if ( V_22 -> V_224 [ V_223 ] . V_7 >= V_22 -> V_33 ) {
V_22 -> V_224 [ V_223 ] . V_7 = 0 ;
V_22 -> V_224 [ V_223 ] . V_37 = 0 ;
V_22 -> V_226 += 1 ;
if ( V_22 -> V_226 >= V_22 -> V_32 )
V_22 -> V_226 = 0 ;
}
} else {
V_223 = F_97 () % V_22 -> V_32 ;
V_22 -> V_226 = V_223 ;
if ( V_22 -> V_224 [ V_223 ] . V_7 > V_22 -> V_33 ) {
V_22 -> V_224 [ V_223 ] . V_7 = 0 ;
V_22 -> V_224 [ V_223 ] . V_37 = 0 ;
}
}
return V_22 -> V_226 ;
}
static void F_98 ( struct V_21 * V_22 , int V_223 )
{
struct V_227 * V_228 = V_22 -> V_224 [ V_223 ] . V_228 ;
struct V_10 * V_11 = F_4 ( F_64 ( V_22 -> V_50 ) , V_15 ) ;
if ( ! V_228 ) {
if ( V_22 -> V_86 ) {
V_228 = F_99 ( V_11 -> V_183 , F_28 ( V_22 -> V_86 ) , V_229 ) ;
} else {
V_228 = F_100 ( V_11 -> V_183 , V_230 ,
( V_231 * ) & V_22 -> V_105 ,
( V_231 * ) & V_22 -> V_104 ,
V_229 ,
V_22 -> V_232 ,
V_22 -> V_233 , 0 ) ;
}
if ( V_228 ) {
V_22 -> V_224 [ V_223 ] . V_228 = V_228 ;
F_91 ( V_22 ) ;
V_22 -> V_196 += V_228 -> V_234 . V_235 ;
}
}
}
static void F_101 ( struct V_21 * V_22 )
{
if ( V_22 -> V_37 & V_83 )
V_22 -> V_108 = F_102 () ;
else if ( V_22 -> V_34 <= V_22 -> V_35 ) {
T_9 V_154 ;
if ( V_22 -> V_37 & V_82 ) {
V_154 = F_97 () %
( V_22 -> V_35 -
V_22 -> V_34 + 1 )
+ V_22 -> V_34 ;
} else {
V_154 = V_22 -> V_108 + 1 ;
if ( V_154 > V_22 -> V_35 )
V_154 = V_22 -> V_34 ;
}
V_22 -> V_108 = V_154 ;
}
V_22 -> V_108 = V_22 -> V_108 % V_22 -> V_50 -> V_189 ;
}
static void F_103 ( struct V_21 * V_22 )
{
T_7 V_236 ;
T_7 V_237 ;
int V_223 = 0 ;
if ( V_22 -> V_32 )
V_223 = F_96 ( V_22 ) ;
if ( V_22 -> V_57 > 1 ) {
T_7 V_238 ;
T_7 V_121 ;
if ( V_22 -> V_37 & V_87 )
V_238 = F_97 () % V_22 -> V_57 ;
else {
V_238 = V_22 -> V_101 ++ ;
if ( V_22 -> V_101 >=
V_22 -> V_57 )
V_22 -> V_101 = 0 ;
}
V_121 = V_22 -> V_49 [ 5 ] + ( V_238 & 0xFF ) ;
V_22 -> V_149 [ 11 ] = V_121 ;
V_121 = ( V_22 -> V_49 [ 4 ] + ( ( V_238 >> 8 ) & 0xFF ) + ( V_121 >> 8 ) ) ;
V_22 -> V_149 [ 10 ] = V_121 ;
V_121 = ( V_22 -> V_49 [ 3 ] + ( ( V_238 >> 16 ) & 0xFF ) + ( V_121 >> 8 ) ) ;
V_22 -> V_149 [ 9 ] = V_121 ;
V_121 = ( V_22 -> V_49 [ 2 ] + ( ( V_238 >> 24 ) & 0xFF ) + ( V_121 >> 8 ) ) ;
V_22 -> V_149 [ 8 ] = V_121 ;
V_121 = ( V_22 -> V_49 [ 1 ] + ( V_121 >> 8 ) ) ;
V_22 -> V_149 [ 7 ] = V_121 ;
}
if ( V_22 -> V_58 > 1 ) {
T_7 V_238 ;
T_7 V_121 ;
if ( V_22 -> V_37 & V_88 )
V_238 = F_97 () % V_22 -> V_58 ;
else {
V_238 = V_22 -> V_100 ++ ;
if ( V_22 -> V_100 >=
V_22 -> V_58 ) {
V_22 -> V_100 = 0 ;
}
}
V_121 = V_22 -> V_52 [ 5 ] + ( V_238 & 0xFF ) ;
V_22 -> V_149 [ 5 ] = V_121 ;
V_121 = ( V_22 -> V_52 [ 4 ] + ( ( V_238 >> 8 ) & 0xFF ) + ( V_121 >> 8 ) ) ;
V_22 -> V_149 [ 4 ] = V_121 ;
V_121 = ( V_22 -> V_52 [ 3 ] + ( ( V_238 >> 16 ) & 0xFF ) + ( V_121 >> 8 ) ) ;
V_22 -> V_149 [ 3 ] = V_121 ;
V_121 = ( V_22 -> V_52 [ 2 ] + ( ( V_238 >> 24 ) & 0xFF ) + ( V_121 >> 8 ) ) ;
V_22 -> V_149 [ 2 ] = V_121 ;
V_121 = ( V_22 -> V_52 [ 1 ] + ( V_121 >> 8 ) ) ;
V_22 -> V_149 [ 1 ] = V_121 ;
}
if ( V_22 -> V_37 & V_81 ) {
unsigned int V_60 ;
for ( V_60 = 0 ; V_60 < V_22 -> V_59 ; V_60 ++ )
if ( V_22 -> V_61 [ V_60 ] & V_122 )
V_22 -> V_61 [ V_60 ] = V_122 |
( ( V_239 V_240 ) F_97 () &
F_28 ( 0x000fffff ) ) ;
}
if ( ( V_22 -> V_37 & V_89 ) && ( V_22 -> V_62 != 0xffff ) ) {
V_22 -> V_62 = F_97 () & ( 4096 - 1 ) ;
}
if ( ( V_22 -> V_37 & V_90 ) && ( V_22 -> V_65 != 0xffff ) ) {
V_22 -> V_65 = F_97 () & ( 4096 - 1 ) ;
}
if ( V_22 -> V_53 < V_22 -> V_54 ) {
if ( V_22 -> V_37 & V_77 )
V_22 -> V_107 = F_97 () %
( V_22 -> V_54 - V_22 -> V_53 )
+ V_22 -> V_53 ;
else {
V_22 -> V_107 ++ ;
if ( V_22 -> V_107 >= V_22 -> V_54 )
V_22 -> V_107 = V_22 -> V_53 ;
}
}
if ( V_22 -> V_55 < V_22 -> V_56 ) {
if ( V_22 -> V_37 & V_78 ) {
V_22 -> V_106 = F_97 () %
( V_22 -> V_56 - V_22 -> V_55 )
+ V_22 -> V_55 ;
} else {
V_22 -> V_106 ++ ;
if ( V_22 -> V_106 >= V_22 -> V_56 )
V_22 -> V_106 = V_22 -> V_55 ;
}
}
if ( ! ( V_22 -> V_37 & V_38 ) ) {
V_236 = F_16 ( V_22 -> V_147 ) ;
V_237 = F_16 ( V_22 -> V_148 ) ;
if ( V_236 < V_237 ) {
T_7 V_154 ;
if ( V_22 -> V_37 & V_74 )
V_154 = F_97 () % ( V_237 - V_236 ) + V_236 ;
else {
V_154 = F_16 ( V_22 -> V_104 ) ;
V_154 ++ ;
if ( V_154 > V_237 )
V_154 = V_236 ;
}
V_22 -> V_104 = F_28 ( V_154 ) ;
}
if ( V_22 -> V_32 && F_95 ( V_22 , V_223 ) ) {
V_22 -> V_105 = V_22 -> V_224 [ V_223 ] . V_105 ;
} else {
V_236 = F_16 ( V_22 -> V_144 ) ;
V_237 = F_16 ( V_22 -> V_145 ) ;
if ( V_236 < V_237 ) {
T_7 V_154 ;
V_240 V_241 ;
if ( V_22 -> V_37 & V_75 ) {
do {
V_154 = F_97 () %
( V_237 - V_236 ) + V_236 ;
V_241 = F_28 ( V_154 ) ;
} while ( F_104 ( V_241 ) ||
F_105 ( V_241 ) ||
F_106 ( V_241 ) ||
F_107 ( V_241 ) ||
F_108 ( V_241 ) );
V_22 -> V_105 = V_241 ;
} else {
V_154 = F_16 ( V_22 -> V_105 ) ;
V_154 ++ ;
if ( V_154 > V_237 ) {
V_154 = V_236 ;
}
V_22 -> V_105 = F_28 ( V_154 ) ;
}
}
if ( V_22 -> V_32 ) {
V_22 -> V_224 [ V_223 ] . V_37 |= V_225 ;
V_22 -> V_224 [ V_223 ] . V_105 =
V_22 -> V_105 ;
#ifdef F_17
if ( V_22 -> V_37 & V_85 )
F_98 ( V_22 , V_223 ) ;
#endif
V_22 -> V_109 ++ ;
}
}
} else {
if ( ! F_109 ( & V_22 -> V_43 ) ) {
int V_60 ;
for ( V_60 = 0 ; V_60 < 4 ; V_60 ++ ) {
V_22 -> V_103 . V_242 [ V_60 ] =
( ( ( V_239 V_240 ) F_97 () |
V_22 -> V_43 . V_242 [ V_60 ] ) &
V_22 -> V_44 . V_242 [ V_60 ] ) ;
}
}
}
if ( V_22 -> V_26 < V_22 -> V_27 ) {
T_7 V_154 ;
if ( V_22 -> V_37 & V_76 ) {
V_154 = F_97 () %
( V_22 -> V_27 - V_22 -> V_26 )
+ V_22 -> V_26 ;
} else {
V_154 = V_22 -> V_134 + 1 ;
if ( V_154 > V_22 -> V_27 )
V_154 = V_22 -> V_26 ;
}
V_22 -> V_134 = V_154 ;
}
F_101 ( V_22 ) ;
V_22 -> V_224 [ V_223 ] . V_7 ++ ;
}
static int F_110 ( struct V_243 * V_244 , struct V_21 * V_22 )
{
struct V_227 * V_228 = V_22 -> V_224 [ V_22 -> V_226 ] . V_228 ;
int V_184 = 0 ;
struct V_183 * V_183 = F_64 ( V_22 -> V_50 ) ;
if ( ! V_228 )
return 0 ;
if ( ( V_228 -> V_234 . V_245 != V_246 ) && ( V_22 -> V_86 == 0 ) )
return 0 ;
if ( ( V_228 -> V_234 . V_245 == V_247 ) && ( V_22 -> V_86 != 0 ) )
V_244 -> V_248 = ( unsigned long ) & V_22 -> V_249 | V_250 ;
F_111 () ;
V_184 = V_228 -> V_251 -> V_252 ( V_228 , V_244 ) ;
F_112 () ;
if ( V_184 ) {
F_113 ( V_183 , V_253 ) ;
goto error;
}
V_184 = V_228 -> type -> V_252 ( V_228 , V_244 ) ;
if ( V_184 ) {
F_113 ( V_183 , V_254 ) ;
goto error;
}
F_114 ( & V_228 -> V_200 ) ;
V_228 -> V_255 . V_256 += V_244 -> V_120 ;
V_228 -> V_255 . V_257 ++ ;
F_115 ( & V_228 -> V_200 ) ;
error:
return V_184 ;
}
static void F_116 ( struct V_21 * V_22 )
{
if ( V_22 -> V_32 ) {
int V_60 ;
for ( V_60 = 0 ; V_60 < V_22 -> V_32 ; V_60 ++ ) {
struct V_227 * V_228 = V_22 -> V_224 [ V_60 ] . V_228 ;
if ( V_228 ) {
F_117 ( V_228 ) ;
V_22 -> V_224 [ V_60 ] . V_228 = NULL ;
}
}
}
}
static int F_118 ( struct V_21 * V_22 ,
struct V_243 * V_244 , T_10 V_258 )
{
if ( V_22 -> V_37 & V_85 ) {
struct V_227 * V_228 = V_22 -> V_224 [ V_22 -> V_226 ] . V_228 ;
int V_259 = 0 ;
if ( V_228 ) {
struct V_260 * V_261 ;
struct V_205 * V_262 ;
int V_155 ;
V_259 = V_228 -> V_234 . V_235 - F_119 ( V_244 ) ;
if ( V_259 > 0 ) {
V_155 = F_120 ( V_244 , V_259 , 0 , V_263 ) ;
if ( V_155 < 0 ) {
F_48 ( L_253 ,
V_155 ) ;
goto V_184;
}
}
F_121 ( V_244 , V_264 ) ;
V_155 = F_110 ( V_244 , V_22 ) ;
if ( V_155 ) {
F_48 ( L_254 , V_155 ) ;
goto V_184;
}
V_261 = (struct V_260 * ) F_122 ( V_244 , V_264 ) ;
memcpy ( V_261 , V_22 -> V_149 , 2 * V_265 ) ;
V_261 -> V_266 = V_258 ;
V_262 = F_123 ( V_244 ) ;
V_262 -> V_267 = F_124 ( V_244 -> V_120 - V_264 ) ;
F_125 ( V_262 ) ;
}
}
return 1 ;
V_184:
F_126 ( V_244 ) ;
return 0 ;
}
static void F_127 ( V_240 * V_268 , struct V_21 * V_22 )
{
unsigned int V_60 ;
for ( V_60 = 0 ; V_60 < V_22 -> V_59 ; V_60 ++ )
* V_268 ++ = V_22 -> V_61 [ V_60 ] & ~ V_122 ;
V_268 -- ;
* V_268 |= V_122 ;
}
static inline T_10 F_128 ( unsigned int V_269 , unsigned int V_270 ,
unsigned int V_271 )
{
return F_124 ( V_269 | ( V_270 << 12 ) | ( V_271 << 13 ) ) ;
}
static void F_129 ( struct V_21 * V_22 , struct V_243 * V_244 ,
int V_272 )
{
struct V_273 V_274 ;
struct V_195 * V_275 ;
V_275 = (struct V_195 * ) F_130 ( V_244 , sizeof( * V_275 ) ) ;
V_272 -= sizeof( * V_275 ) ;
if ( V_22 -> V_28 <= 0 ) {
memset ( F_130 ( V_244 , V_272 ) , 0 , V_272 ) ;
} else {
int V_276 = V_22 -> V_28 ;
int V_60 , V_120 ;
int V_277 ;
if ( V_276 > V_278 )
V_276 = V_278 ;
V_120 = V_272 - V_276 * V_279 ;
if ( V_120 > 0 ) {
memset ( F_130 ( V_244 , V_120 ) , 0 , V_120 ) ;
V_272 = V_276 * V_279 ;
}
V_60 = 0 ;
V_277 = ( V_272 / V_276 ) < V_279 ?
( V_272 / V_276 ) : V_279 ;
while ( V_272 > 0 ) {
if ( F_131 ( ! V_22 -> V_141 ) ) {
int V_71 = F_132 () ;
if ( V_22 -> V_71 >= 0 && ( V_22 -> V_37 & V_91 ) )
V_71 = V_22 -> V_71 ;
V_22 -> V_141 = F_133 ( V_71 , V_280 | V_281 , 0 ) ;
if ( ! V_22 -> V_141 )
break;
}
F_134 ( V_22 -> V_141 ) ;
F_135 ( V_244 , V_60 , V_22 -> V_141 ) ;
F_136 ( V_244 ) -> V_276 [ V_60 ] . V_282 = 0 ;
if ( V_60 == ( V_276 - 1 ) )
F_137 ( & F_136 ( V_244 ) -> V_276 [ V_60 ] ,
( V_272 < V_279 ? V_272 : V_279 ) ) ;
else
F_137 ( & F_136 ( V_244 ) -> V_276 [ V_60 ] , V_277 ) ;
V_272 -= F_138 ( & F_136 ( V_244 ) -> V_276 [ V_60 ] ) ;
V_244 -> V_120 += F_138 ( & F_136 ( V_244 ) -> V_276 [ V_60 ] ) ;
V_244 -> V_283 += F_138 ( & F_136 ( V_244 ) -> V_276 [ V_60 ] ) ;
V_60 ++ ;
F_136 ( V_244 ) -> V_284 = V_60 ;
}
}
V_275 -> V_285 = F_28 ( V_286 ) ;
V_275 -> V_99 = F_28 ( V_22 -> V_99 ) ;
if ( V_22 -> V_37 & V_80 ) {
V_275 -> V_287 = 0 ;
V_275 -> V_288 = 0 ;
} else {
F_139 ( & V_274 ) ;
V_275 -> V_287 = F_28 ( V_274 . V_287 ) ;
V_275 -> V_288 = F_28 ( V_274 . V_288 ) ;
}
}
static struct V_243 * F_140 ( struct V_168 * V_169 ,
struct V_21 * V_22 ,
unsigned int V_289 )
{
struct V_243 * V_244 = NULL ;
unsigned int V_290 = V_22 -> V_134 + 64 + V_289 +
V_22 -> V_196 ;
if ( V_22 -> V_37 & V_91 ) {
int V_71 = V_22 -> V_71 >= 0 ? V_22 -> V_71 : F_132 () ;
V_244 = F_141 ( V_291 + V_290 , V_292 , 0 , V_71 ) ;
if ( F_85 ( V_244 ) ) {
F_142 ( V_244 , V_291 ) ;
V_244 -> V_169 = V_169 ;
}
} else {
V_244 = F_143 ( V_169 , V_290 , V_292 ) ;
}
if ( F_85 ( V_244 ) )
F_142 ( V_244 , F_92 ( V_169 ) ) ;
return V_244 ;
}
static struct V_243 * F_144 ( struct V_168 * V_50 ,
struct V_21 * V_22 )
{
struct V_243 * V_244 = NULL ;
T_11 * V_261 ;
struct V_194 * V_293 ;
int V_272 , V_294 ;
struct V_205 * V_262 ;
T_10 V_258 = F_124 ( V_295 ) ;
V_240 * V_268 ;
T_10 * V_296 = NULL ;
T_10 * V_297 = NULL ;
T_10 * V_298 = NULL ;
T_10 * V_299 = NULL ;
T_12 V_300 ;
if ( V_22 -> V_59 )
V_258 = F_124 ( V_301 ) ;
if ( V_22 -> V_62 != 0xffff )
V_258 = F_124 ( V_302 ) ;
F_103 ( V_22 ) ;
V_300 = V_22 -> V_108 ;
V_272 = ( V_50 -> V_303 + 16 ) & ~ 0xf ;
V_244 = F_140 ( V_50 , V_22 , V_272 ) ;
if ( ! V_244 ) {
sprintf ( V_22 -> V_110 , L_255 ) ;
return NULL ;
}
F_145 ( V_244 -> V_9 ) ;
F_142 ( V_244 , V_272 ) ;
V_261 = ( T_11 * ) F_122 ( V_244 , 14 ) ;
V_268 = ( V_240 * ) F_130 ( V_244 , V_22 -> V_59 * sizeof( T_7 ) ) ;
if ( V_22 -> V_59 )
F_127 ( V_268 , V_22 ) ;
if ( V_22 -> V_62 != 0xffff ) {
if ( V_22 -> V_65 != 0xffff ) {
V_298 = ( T_10 * ) F_130 ( V_244 , sizeof( T_10 ) ) ;
* V_298 = F_128 ( V_22 -> V_65 ,
V_22 -> V_67 ,
V_22 -> V_66 ) ;
V_299 = ( T_10 * ) F_130 ( V_244 , sizeof( T_10 ) ) ;
* V_299 = F_124 ( V_302 ) ;
}
V_296 = ( T_10 * ) F_130 ( V_244 , sizeof( T_10 ) ) ;
* V_296 = F_128 ( V_22 -> V_62 ,
V_22 -> V_64 ,
V_22 -> V_63 ) ;
V_297 = ( T_10 * ) F_130 ( V_244 , sizeof( T_10 ) ) ;
* V_297 = F_124 ( V_295 ) ;
}
F_146 ( V_244 , 0 ) ;
F_147 ( V_244 , V_244 -> V_120 ) ;
V_262 = (struct V_205 * ) F_130 ( V_244 , sizeof( struct V_205 ) ) ;
F_148 ( V_244 , V_244 -> V_120 ) ;
V_293 = (struct V_194 * ) F_130 ( V_244 , sizeof( struct V_194 ) ) ;
F_149 ( V_244 , V_300 ) ;
V_244 -> V_304 = V_22 -> V_36 ;
memcpy ( V_261 , V_22 -> V_149 , 12 ) ;
* ( T_10 * ) & V_261 [ 12 ] = V_258 ;
V_272 = V_22 -> V_134 - 14 - 20 - 8 -
V_22 -> V_196 ;
if ( V_272 < 0 || V_272 < sizeof( struct V_195 ) )
V_272 = sizeof( struct V_195 ) ;
V_293 -> V_305 = F_124 ( V_22 -> V_107 ) ;
V_293 -> V_306 = F_124 ( V_22 -> V_106 ) ;
V_293 -> V_120 = F_124 ( V_272 + 8 ) ;
V_293 -> V_307 = 0 ;
V_262 -> V_308 = 5 ;
V_262 -> V_4 = 4 ;
V_262 -> V_309 = 32 ;
V_262 -> V_68 = V_22 -> V_68 ;
V_262 -> V_258 = V_310 ;
V_262 -> V_311 = V_22 -> V_104 ;
V_262 -> V_312 = V_22 -> V_105 ;
V_262 -> V_269 = F_124 ( V_22 -> V_313 ) ;
V_22 -> V_313 ++ ;
V_262 -> V_314 = 0 ;
V_294 = 20 + 8 + V_272 ;
V_262 -> V_267 = F_124 ( V_294 ) ;
F_125 ( V_262 ) ;
V_244 -> V_258 = V_258 ;
V_244 -> V_169 = V_50 ;
V_244 -> V_315 = V_316 ;
F_129 ( V_22 , V_244 , V_272 ) ;
if ( ! ( V_22 -> V_37 & V_79 ) ) {
V_244 -> V_317 = V_318 ;
} else if ( V_50 -> V_319 & ( V_320 | V_321 ) ) {
V_244 -> V_317 = V_322 ;
V_244 -> V_323 = 0 ;
F_150 ( V_244 , V_262 -> V_311 , V_262 -> V_312 ) ;
} else {
T_13 V_323 = F_151 ( V_244 , F_152 ( V_244 ) , V_272 + 8 , 0 ) ;
V_293 -> V_307 = F_153 ( V_262 -> V_311 , V_262 -> V_312 ,
V_272 + 8 , V_310 , V_323 ) ;
if ( V_293 -> V_307 == 0 )
V_293 -> V_307 = V_324 ;
}
#ifdef F_17
if ( ! F_118 ( V_22 , V_244 , V_258 ) )
return NULL ;
#endif
return V_244 ;
}
static struct V_243 * F_154 ( struct V_168 * V_50 ,
struct V_21 * V_22 )
{
struct V_243 * V_244 = NULL ;
T_11 * V_261 ;
struct V_194 * V_293 ;
int V_272 , V_325 ;
struct V_193 * V_262 ;
T_10 V_258 = F_124 ( V_326 ) ;
V_240 * V_268 ;
T_10 * V_296 = NULL ;
T_10 * V_297 = NULL ;
T_10 * V_298 = NULL ;
T_10 * V_299 = NULL ;
T_12 V_300 ;
if ( V_22 -> V_59 )
V_258 = F_124 ( V_301 ) ;
if ( V_22 -> V_62 != 0xffff )
V_258 = F_124 ( V_302 ) ;
F_103 ( V_22 ) ;
V_300 = V_22 -> V_108 ;
V_244 = F_140 ( V_50 , V_22 , 16 ) ;
if ( ! V_244 ) {
sprintf ( V_22 -> V_110 , L_255 ) ;
return NULL ;
}
F_145 ( V_244 -> V_9 ) ;
F_142 ( V_244 , 16 ) ;
V_261 = ( T_11 * ) F_122 ( V_244 , 14 ) ;
V_268 = ( V_240 * ) F_130 ( V_244 , V_22 -> V_59 * sizeof( T_7 ) ) ;
if ( V_22 -> V_59 )
F_127 ( V_268 , V_22 ) ;
if ( V_22 -> V_62 != 0xffff ) {
if ( V_22 -> V_65 != 0xffff ) {
V_298 = ( T_10 * ) F_130 ( V_244 , sizeof( T_10 ) ) ;
* V_298 = F_128 ( V_22 -> V_65 ,
V_22 -> V_67 ,
V_22 -> V_66 ) ;
V_299 = ( T_10 * ) F_130 ( V_244 , sizeof( T_10 ) ) ;
* V_299 = F_124 ( V_302 ) ;
}
V_296 = ( T_10 * ) F_130 ( V_244 , sizeof( T_10 ) ) ;
* V_296 = F_128 ( V_22 -> V_62 ,
V_22 -> V_64 ,
V_22 -> V_63 ) ;
V_297 = ( T_10 * ) F_130 ( V_244 , sizeof( T_10 ) ) ;
* V_297 = F_124 ( V_326 ) ;
}
F_146 ( V_244 , 0 ) ;
F_147 ( V_244 , V_244 -> V_120 ) ;
V_262 = (struct V_193 * ) F_130 ( V_244 , sizeof( struct V_193 ) ) ;
F_148 ( V_244 , V_244 -> V_120 ) ;
V_293 = (struct V_194 * ) F_130 ( V_244 , sizeof( struct V_194 ) ) ;
F_149 ( V_244 , V_300 ) ;
V_244 -> V_304 = V_22 -> V_36 ;
memcpy ( V_261 , V_22 -> V_149 , 12 ) ;
* ( T_10 * ) & V_261 [ 12 ] = V_258 ;
V_272 = V_22 -> V_134 - 14 -
sizeof( struct V_193 ) - sizeof( struct V_194 ) -
V_22 -> V_196 ;
if ( V_272 < 0 || V_272 < sizeof( struct V_195 ) ) {
V_272 = sizeof( struct V_195 ) ;
F_155 ( L_256 , V_272 ) ;
}
V_325 = V_272 + sizeof( struct V_194 ) ;
V_293 -> V_305 = F_124 ( V_22 -> V_107 ) ;
V_293 -> V_306 = F_124 ( V_22 -> V_106 ) ;
V_293 -> V_120 = F_124 ( V_325 ) ;
V_293 -> V_307 = 0 ;
* ( V_240 * ) V_262 = F_28 ( 0x60000000 ) ;
if ( V_22 -> V_69 ) {
* ( V_240 * ) V_262 |= F_28 ( 0x60000000 | ( V_22 -> V_69 << 20 ) ) ;
}
V_262 -> V_327 = 32 ;
V_262 -> V_328 = F_124 ( V_325 ) ;
V_262 -> V_329 = V_310 ;
V_262 -> V_312 = V_22 -> V_103 ;
V_262 -> V_311 = V_22 -> V_102 ;
V_244 -> V_258 = V_258 ;
V_244 -> V_169 = V_50 ;
V_244 -> V_315 = V_316 ;
F_129 ( V_22 , V_244 , V_272 ) ;
if ( ! ( V_22 -> V_37 & V_79 ) ) {
V_244 -> V_317 = V_318 ;
} else if ( V_50 -> V_319 & ( V_320 | V_330 ) ) {
V_244 -> V_317 = V_322 ;
V_244 -> V_331 = F_156 ( V_244 ) - V_244 -> V_332 ;
V_244 -> V_333 = F_157 ( struct V_194 , V_307 ) ;
V_293 -> V_307 = ~ F_158 ( & V_262 -> V_311 , & V_262 -> V_312 , V_325 , V_310 , 0 ) ;
} else {
T_13 V_323 = F_151 ( V_244 , F_152 ( V_244 ) , V_325 , 0 ) ;
V_293 -> V_307 = F_158 ( & V_262 -> V_311 , & V_262 -> V_312 , V_325 , V_310 , V_323 ) ;
if ( V_293 -> V_307 == 0 )
V_293 -> V_307 = V_324 ;
}
return V_244 ;
}
static struct V_243 * F_159 ( struct V_168 * V_50 ,
struct V_21 * V_22 )
{
if ( V_22 -> V_37 & V_38 )
return F_154 ( V_50 , V_22 ) ;
else
return F_144 ( V_50 , V_22 ) ;
}
static void F_40 ( struct V_21 * V_22 )
{
V_22 -> V_99 = 1 ;
V_22 -> V_94 = 0 ;
V_22 -> V_96 = 0 ;
V_22 -> V_334 = 0 ;
V_22 -> V_97 = 0 ;
}
static void F_160 ( struct V_153 * V_154 )
{
struct V_21 * V_22 ;
int V_335 = 0 ;
F_161 () ;
F_44 () ;
F_45 (pkt_dev, &t->if_list, list) {
F_70 ( V_22 ) ;
if ( V_22 -> V_50 ) {
F_40 ( V_22 ) ;
V_22 -> V_244 = NULL ;
V_22 -> V_98 = V_22 -> V_218 = F_18 () ;
F_91 ( V_22 ) ;
strcpy ( V_22 -> V_110 , L_257 ) ;
V_22 -> V_92 = 1 ;
V_335 ++ ;
} else
strcpy ( V_22 -> V_110 , L_258 ) ;
}
F_46 () ;
if ( V_335 )
V_154 -> V_158 &= ~ ( V_336 ) ;
}
static void F_7 ( struct V_10 * V_11 )
{
struct V_153 * V_154 ;
F_161 () ;
F_49 ( & V_157 ) ;
F_56 (t, &pn->pktgen_threads, th_list)
V_154 -> V_158 |= V_336 ;
F_51 ( & V_157 ) ;
}
static int F_162 ( const struct V_153 * V_154 )
{
const struct V_21 * V_22 ;
F_44 () ;
F_45 (pkt_dev, &t->if_list, list)
if ( V_22 -> V_92 ) {
F_46 () ;
return 1 ;
}
F_46 () ;
return 0 ;
}
static int F_163 ( struct V_153 * V_154 )
{
while ( F_162 ( V_154 ) ) {
F_164 ( 100 ) ;
if ( F_88 ( V_12 ) )
goto signal;
}
return 1 ;
signal:
return 0 ;
}
static int F_165 ( struct V_10 * V_11 )
{
struct V_153 * V_154 ;
int V_337 = 1 ;
F_49 ( & V_157 ) ;
F_56 (t, &pn->pktgen_threads, th_list) {
V_337 = F_163 ( V_154 ) ;
if ( V_337 == 0 )
break;
}
if ( V_337 == 0 )
F_56 (t, &pn->pktgen_threads, th_list)
V_154 -> V_158 |= ( V_336 ) ;
F_51 ( & V_157 ) ;
return V_337 ;
}
static void F_8 ( struct V_10 * V_11 )
{
struct V_153 * V_154 ;
F_161 () ;
F_49 ( & V_157 ) ;
F_56 (t, &pn->pktgen_threads, th_list)
V_154 -> V_158 |= ( V_338 ) ;
F_51 ( & V_157 ) ;
F_52 ( F_53 ( 125 ) ) ;
F_165 ( V_11 ) ;
}
static void F_9 ( struct V_10 * V_11 )
{
struct V_153 * V_154 ;
F_161 () ;
F_49 ( & V_157 ) ;
F_56 (t, &pn->pktgen_threads, th_list)
V_154 -> V_158 |= ( V_159 ) ;
F_51 ( & V_157 ) ;
F_52 ( F_53 ( 125 ) ) ;
F_165 ( V_11 ) ;
}
static void F_166 ( struct V_21 * V_22 , int V_284 )
{
T_14 V_339 , V_340 , V_341 ;
char * V_342 = V_22 -> V_110 ;
T_5 V_343 = F_90 ( V_22 -> V_93 ,
V_22 -> V_98 ) ;
T_5 V_25 = F_167 ( V_22 -> V_94 ) ;
V_342 += sprintf ( V_342 , L_259 ,
( unsigned long long ) F_20 ( V_343 ) ,
( unsigned long long ) F_20 ( F_90 ( V_343 , V_25 ) ) ,
( unsigned long long ) F_20 ( V_25 ) ,
( unsigned long long ) V_22 -> V_96 ,
V_22 -> V_134 , V_284 ) ;
V_341 = F_168 ( V_22 -> V_96 * V_136 ,
F_78 ( V_343 ) ) ;
V_339 = V_341 * 8 * V_22 -> V_134 ;
V_340 = V_339 ;
F_19 ( V_340 , 1000000 ) ;
V_342 += sprintf ( V_342 , L_260 ,
( unsigned long long ) V_341 ,
( unsigned long long ) V_340 ,
( unsigned long long ) V_339 ,
( unsigned long long ) V_22 -> V_97 ) ;
}
static int F_169 ( struct V_21 * V_22 )
{
int V_284 = V_22 -> V_244 ? F_136 ( V_22 -> V_244 ) -> V_284 : - 1 ;
if ( ! V_22 -> V_92 ) {
F_30 ( L_261 ,
V_22 -> V_31 ) ;
return - V_18 ;
}
V_22 -> V_92 = 0 ;
F_126 ( V_22 -> V_244 ) ;
V_22 -> V_244 = NULL ;
V_22 -> V_93 = F_18 () ;
F_166 ( V_22 , V_284 ) ;
return 0 ;
}
static struct V_21 * F_170 ( struct V_153 * V_154 )
{
struct V_21 * V_22 , * V_344 = NULL ;
F_44 () ;
F_45 (pkt_dev, &t->if_list, list) {
if ( ! V_22 -> V_92 )
continue;
if ( V_344 == NULL )
V_344 = V_22 ;
else if ( F_81 ( V_22 -> V_218 , V_344 -> V_218 ) < 0 )
V_344 = V_22 ;
}
F_46 () ;
return V_344 ;
}
static void F_171 ( struct V_153 * V_154 )
{
struct V_21 * V_22 ;
F_161 () ;
F_44 () ;
F_45 (pkt_dev, &t->if_list, list) {
F_169 ( V_22 ) ;
}
F_46 () ;
}
static void F_172 ( struct V_153 * V_154 )
{
struct V_345 * V_346 , * V_119 ;
struct V_21 * V_347 ;
F_161 () ;
F_173 (q, n, &t->if_list) {
V_347 = F_174 ( V_346 , struct V_21 , V_348 ) ;
if ( ! V_347 -> V_163 )
continue;
F_126 ( V_347 -> V_244 ) ;
V_347 -> V_244 = NULL ;
F_175 ( V_154 , V_347 ) ;
break;
}
}
static void F_176 ( struct V_153 * V_154 )
{
struct V_345 * V_346 , * V_119 ;
struct V_21 * V_347 ;
F_161 () ;
F_173 (q, n, &t->if_list) {
V_347 = F_174 ( V_346 , struct V_21 , V_348 ) ;
F_126 ( V_347 -> V_244 ) ;
V_347 -> V_244 = NULL ;
F_175 ( V_154 , V_347 ) ;
}
}
static void F_177 ( struct V_153 * V_154 )
{
F_178 ( V_154 -> V_349 -> V_350 , V_154 -> V_183 -> V_171 ) ;
}
static void F_179 ( struct V_21 * V_22 )
{
T_5 V_351 = F_18 () ;
F_86 () ;
V_22 -> V_94 += F_78 ( F_90 ( F_18 () , V_351 ) ) ;
}
static void F_180 ( struct V_21 * V_22 )
{
T_5 V_351 = F_18 () ;
while ( F_181 ( & ( V_22 -> V_244 -> V_352 ) ) != 1 ) {
if ( F_88 ( V_12 ) )
break;
if ( F_182 () )
F_179 ( V_22 ) ;
else
F_183 () ;
}
V_22 -> V_94 += F_78 ( F_90 ( F_18 () , V_351 ) ) ;
}
static void F_184 ( struct V_21 * V_22 )
{
unsigned int V_70 = F_185 ( V_22 -> V_70 ) ;
struct V_168 * V_50 = V_22 -> V_50 ;
struct V_353 * V_354 ;
struct V_243 * V_244 ;
int V_155 ;
if ( F_131 ( ! F_69 ( V_50 ) || ! F_186 ( V_50 ) ) ) {
F_169 ( V_22 ) ;
return;
}
if ( F_131 ( V_22 -> V_29 == V_135 ) ) {
V_22 -> V_218 = F_80 ( F_18 () , V_355 ) ;
return;
}
if ( ! V_22 -> V_244 || ( V_22 -> V_143 &&
++ V_22 -> V_356 >= V_22 -> V_30 ) ) {
F_126 ( V_22 -> V_244 ) ;
V_22 -> V_244 = F_159 ( V_50 , V_22 ) ;
if ( V_22 -> V_244 == NULL ) {
F_48 ( L_262 ) ;
F_86 () ;
V_22 -> V_356 -- ;
return;
}
V_22 -> V_357 = V_22 -> V_244 -> V_120 ;
V_22 -> V_356 = 0 ;
}
if ( V_22 -> V_29 && V_22 -> V_143 )
F_75 ( V_22 , V_22 -> V_218 ) ;
if ( V_22 -> V_72 == V_73 ) {
V_244 = V_22 -> V_244 ;
V_244 -> V_258 = F_187 ( V_244 , V_244 -> V_169 ) ;
F_188 ( V_70 , & V_244 -> V_352 ) ;
F_189 () ;
do {
V_155 = F_190 ( V_244 ) ;
if ( V_155 == V_358 )
V_22 -> V_97 ++ ;
V_22 -> V_96 ++ ;
V_22 -> V_99 ++ ;
if ( F_181 ( & V_244 -> V_352 ) != V_70 ) {
F_191 ( V_70 - 1 , & V_244 -> V_352 ) ;
break;
}
#ifdef F_192
V_244 -> V_359 = 0 ;
#endif
} while ( -- V_70 > 0 );
goto V_156;
}
V_354 = F_193 ( V_50 , V_22 -> V_244 ) ;
F_189 () ;
F_194 ( V_50 , V_354 , F_102 () ) ;
if ( F_131 ( F_195 ( V_354 ) ) ) {
V_155 = V_360 ;
V_22 -> V_143 = 0 ;
goto V_361;
}
F_188 ( V_70 , & V_22 -> V_244 -> V_352 ) ;
V_362:
V_155 = F_196 ( V_22 -> V_244 , V_50 , V_354 , -- V_70 > 0 ) ;
switch ( V_155 ) {
case V_363 :
V_22 -> V_143 = 1 ;
V_22 -> V_96 ++ ;
V_22 -> V_99 ++ ;
V_22 -> V_334 += V_22 -> V_357 ;
if ( V_70 > 0 && ! F_195 ( V_354 ) )
goto V_362;
break;
case V_364 :
case V_365 :
case V_366 :
V_22 -> V_97 ++ ;
break;
default:
F_155 ( L_263 ,
V_22 -> V_31 , V_155 ) ;
V_22 -> V_97 ++ ;
case V_367 :
case V_360 :
F_197 ( & ( V_22 -> V_244 -> V_352 ) ) ;
V_22 -> V_143 = 0 ;
}
if ( F_131 ( V_70 ) )
F_191 ( V_70 , & V_22 -> V_244 -> V_352 ) ;
V_361:
F_198 ( V_50 , V_354 ) ;
V_156:
F_199 () ;
if ( ( V_22 -> V_7 != 0 ) && ( V_22 -> V_96 >= V_22 -> V_7 ) ) {
F_180 ( V_22 ) ;
F_169 ( V_22 ) ;
}
}
static int F_200 ( void * V_368 )
{
F_201 ( V_369 ) ;
struct V_153 * V_154 = V_368 ;
struct V_21 * V_22 = NULL ;
int V_370 = V_154 -> V_370 ;
F_43 ( F_102 () != V_370 ) ;
F_202 ( & V_154 -> V_371 ) ;
F_203 ( & V_154 -> V_372 ) ;
F_32 ( L_264 , V_370 , F_204 ( V_12 ) ) ;
F_205 () ;
while ( ! F_206 () ) {
V_22 = F_170 ( V_154 ) ;
if ( F_131 ( ! V_22 && V_154 -> V_158 == 0 ) ) {
if ( V_154 -> V_183 -> V_177 )
break;
F_207 ( V_154 -> V_371 ,
V_154 -> V_158 != 0 ,
V_373 / 10 ) ;
F_208 () ;
continue;
}
if ( F_85 ( V_22 ) ) {
F_184 ( V_22 ) ;
if ( F_182 () )
F_179 ( V_22 ) ;
else
F_183 () ;
}
if ( V_154 -> V_158 & V_336 ) {
F_171 ( V_154 ) ;
V_154 -> V_158 &= ~ ( V_336 ) ;
}
if ( V_154 -> V_158 & V_338 ) {
F_160 ( V_154 ) ;
V_154 -> V_158 &= ~ ( V_338 ) ;
}
if ( V_154 -> V_158 & V_159 ) {
F_176 ( V_154 ) ;
V_154 -> V_158 &= ~ ( V_159 ) ;
}
if ( V_154 -> V_158 & V_164 ) {
F_172 ( V_154 ) ;
V_154 -> V_158 &= ~ ( V_164 ) ;
}
F_208 () ;
}
F_32 ( L_265 , V_154 -> V_349 -> V_350 ) ;
F_171 ( V_154 ) ;
F_32 ( L_266 , V_154 -> V_349 -> V_350 ) ;
F_176 ( V_154 ) ;
F_32 ( L_267 , V_154 -> V_349 -> V_350 ) ;
F_177 ( V_154 ) ;
return 0 ;
}
static struct V_21 * F_57 ( struct V_153 * V_154 ,
const char * V_160 , bool V_161 )
{
struct V_21 * V_342 , * V_22 = NULL ;
T_3 V_120 = strlen ( V_160 ) ;
F_44 () ;
F_45 (p, &t->if_list, list)
if ( strncmp ( V_342 -> V_31 , V_160 , V_120 ) == 0 ) {
if ( V_342 -> V_31 [ V_120 ] ) {
if ( V_161 || V_342 -> V_31 [ V_120 ] != '@' )
continue;
}
V_22 = V_342 ;
break;
}
F_46 () ;
F_32 ( L_268 , V_160 , V_22 ) ;
return V_22 ;
}
static int F_209 ( struct V_153 * V_154 ,
struct V_21 * V_22 )
{
int V_374 = 0 ;
F_210 ( V_154 ) ;
if ( V_22 -> V_375 ) {
F_48 ( L_269 ) ;
V_374 = - V_376 ;
goto V_156;
}
V_22 -> V_92 = 0 ;
V_22 -> V_375 = V_154 ;
F_211 ( & V_22 -> V_348 , & V_154 -> V_377 ) ;
V_156:
F_212 ( V_154 ) ;
return V_374 ;
}
static int F_50 ( struct V_153 * V_154 , const char * V_160 )
{
struct V_21 * V_22 ;
int V_184 ;
int V_71 = F_213 ( V_154 -> V_370 ) ;
V_22 = F_55 ( V_154 -> V_183 , V_160 , V_162 ) ;
if ( V_22 ) {
F_48 ( L_270 ) ;
return - V_376 ;
}
V_22 = F_214 ( sizeof( struct V_21 ) , V_280 , V_71 ) ;
if ( ! V_22 )
return - V_378 ;
strcpy ( V_22 -> V_31 , V_160 ) ;
V_22 -> V_224 = F_215 ( V_150 * sizeof( struct V_379 ) ,
V_71 ) ;
if ( V_22 -> V_224 == NULL ) {
F_216 ( V_22 ) ;
return - V_378 ;
}
V_22 -> V_163 = 0 ;
V_22 -> V_28 = 0 ;
V_22 -> V_29 = V_380 ;
V_22 -> V_7 = V_381 ;
V_22 -> V_96 = 0 ;
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
V_184 = F_67 ( V_154 -> V_183 , V_22 , V_160 ) ;
if ( V_184 )
goto V_382;
if ( V_22 -> V_50 -> V_137 & V_138 )
V_22 -> V_30 = V_383 ;
V_22 -> V_170 = F_61 ( V_160 , 0600 , V_154 -> V_183 -> V_171 ,
& V_172 , V_22 ) ;
if ( ! V_22 -> V_170 ) {
F_48 ( L_271 ,
V_384 , V_160 ) ;
V_184 = - V_18 ;
goto V_385;
}
#ifdef F_17
V_22 -> V_232 = V_246 ;
V_22 -> V_233 = V_386 ;
V_22 -> V_387 . V_388 = V_229 ;
V_22 -> V_249 . V_169 = V_22 -> V_50 ;
F_217 ( & V_22 -> V_249 , V_389 , false ) ;
V_22 -> V_249 . V_390 = & V_22 -> V_249 ;
V_22 -> V_249 . V_391 = & V_22 -> V_387 ;
#endif
return F_209 ( V_154 , V_22 ) ;
V_385:
F_68 ( V_22 -> V_50 ) ;
V_382:
#ifdef F_17
F_116 ( V_22 ) ;
#endif
F_218 ( V_22 -> V_224 ) ;
F_216 ( V_22 ) ;
return V_184 ;
}
static int T_15 F_219 ( int V_370 , struct V_10 * V_11 )
{
struct V_153 * V_154 ;
struct V_392 * V_393 ;
struct V_394 * V_342 ;
V_154 = F_214 ( sizeof( struct V_153 ) , V_280 ,
F_213 ( V_370 ) ) ;
if ( ! V_154 ) {
F_48 ( L_272 ) ;
return - V_378 ;
}
F_220 ( & V_154 -> F_210 ) ;
V_154 -> V_370 = V_370 ;
F_221 ( & V_154 -> V_377 ) ;
F_222 ( & V_154 -> V_395 , & V_11 -> V_396 ) ;
F_223 ( & V_154 -> V_372 ) ;
V_342 = F_224 ( F_200 ,
V_154 ,
F_213 ( V_370 ) ,
L_273 , V_370 ) ;
if ( F_225 ( V_342 ) ) {
F_48 ( L_274 , V_154 -> V_370 ) ;
F_226 ( & V_154 -> V_395 ) ;
F_216 ( V_154 ) ;
return F_227 ( V_342 ) ;
}
F_228 ( V_342 , V_370 ) ;
V_154 -> V_349 = V_342 ;
V_393 = F_61 ( V_154 -> V_349 -> V_350 , 0600 , V_11 -> V_171 ,
& V_397 , V_154 ) ;
if ( ! V_393 ) {
F_48 ( L_271 ,
V_384 , V_154 -> V_349 -> V_350 ) ;
F_229 ( V_342 ) ;
F_226 ( & V_154 -> V_395 ) ;
F_216 ( V_154 ) ;
return - V_18 ;
}
V_154 -> V_183 = V_11 ;
F_230 ( V_342 ) ;
F_231 ( V_342 ) ;
F_232 ( & V_154 -> V_372 ) ;
return 0 ;
}
static void F_233 ( struct V_153 * V_154 ,
struct V_21 * V_22 )
{
struct V_345 * V_346 , * V_119 ;
struct V_21 * V_342 ;
F_210 ( V_154 ) ;
F_173 (q, n, &t->if_list) {
V_342 = F_174 ( V_346 , struct V_21 , V_348 ) ;
if ( V_342 == V_22 )
F_234 ( & V_342 -> V_348 ) ;
}
F_212 ( V_154 ) ;
}
static int F_175 ( struct V_153 * V_154 ,
struct V_21 * V_22 )
{
F_32 ( L_275 , V_22 ) ;
if ( V_22 -> V_92 ) {
F_30 ( L_276 ) ;
F_169 ( V_22 ) ;
}
if ( V_22 -> V_50 ) {
F_68 ( V_22 -> V_50 ) ;
V_22 -> V_50 = NULL ;
}
F_60 ( V_22 -> V_170 ) ;
F_233 ( V_154 , V_22 ) ;
#ifdef F_17
F_116 ( V_22 ) ;
#endif
F_218 ( V_22 -> V_224 ) ;
if ( V_22 -> V_141 )
F_35 ( V_22 -> V_141 ) ;
F_235 ( V_22 , V_398 ) ;
return 0 ;
}
static int T_15 F_236 ( struct V_183 * V_183 )
{
struct V_10 * V_11 = F_4 ( V_183 , V_15 ) ;
struct V_392 * V_393 ;
int V_370 , V_155 = 0 ;
V_11 -> V_183 = V_183 ;
F_221 ( & V_11 -> V_396 ) ;
V_11 -> V_177 = false ;
V_11 -> V_171 = F_237 ( V_384 , V_11 -> V_183 -> V_399 ) ;
if ( ! V_11 -> V_171 ) {
F_30 ( L_277 , V_384 ) ;
return - V_185 ;
}
V_393 = F_238 ( V_400 , 0600 , V_11 -> V_171 , & V_401 ) ;
if ( V_393 == NULL ) {
F_48 ( L_278 , V_400 ) ;
V_155 = - V_18 ;
goto remove;
}
F_239 (cpu) {
int V_184 ;
V_184 = F_219 ( V_370 , V_11 ) ;
if ( V_184 )
F_30 ( L_279 ,
V_370 , V_184 ) ;
}
if ( F_240 ( & V_11 -> V_396 ) ) {
F_48 ( L_280 ) ;
V_155 = - V_185 ;
goto V_402;
}
return 0 ;
V_402:
F_178 ( V_400 , V_11 -> V_171 ) ;
remove:
F_178 ( V_384 , V_11 -> V_183 -> V_399 ) ;
return V_155 ;
}
static void T_16 F_241 ( struct V_183 * V_183 )
{
struct V_10 * V_11 = F_4 ( V_183 , V_15 ) ;
struct V_153 * V_154 ;
struct V_345 * V_346 , * V_119 ;
F_242 ( V_348 ) ;
V_11 -> V_177 = true ;
F_49 ( & V_157 ) ;
F_243 ( & V_11 -> V_396 , & V_348 ) ;
F_51 ( & V_157 ) ;
F_173 (q, n, &list) {
V_154 = F_174 ( V_346 , struct V_153 , V_395 ) ;
F_226 ( & V_154 -> V_395 ) ;
F_229 ( V_154 -> V_349 ) ;
F_244 ( V_154 -> V_349 ) ;
F_216 ( V_154 ) ;
}
F_178 ( V_400 , V_11 -> V_171 ) ;
F_178 ( V_384 , V_11 -> V_183 -> V_399 ) ;
}
static int T_17 F_245 ( void )
{
int V_155 = 0 ;
F_33 ( L_281 , V_4 ) ;
V_155 = F_246 ( & V_403 ) ;
if ( V_155 )
return V_155 ;
V_155 = F_247 ( & V_404 ) ;
if ( V_155 )
F_248 ( & V_403 ) ;
return V_155 ;
}
static void T_18 F_249 ( void )
{
F_250 ( & V_404 ) ;
F_248 ( & V_403 ) ;
}
