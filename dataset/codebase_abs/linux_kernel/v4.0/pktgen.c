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
F_10 ( L_4 , V_9 ) ;
return V_7 ;
}
static int F_11 ( struct V_20 * V_20 , struct V_5 * V_5 )
{
return F_12 ( V_5 , F_1 , F_13 ( V_20 ) ) ;
}
static int F_14 ( struct V_1 * V_2 , void * V_3 )
{
const struct V_21 * V_22 = V_2 -> V_23 ;
T_5 V_24 ;
T_6 V_25 ;
F_15 ( V_2 ,
L_5 ,
( unsigned long long ) V_22 -> V_7 , V_22 -> V_26 ,
V_22 -> V_27 ) ;
F_15 ( V_2 ,
L_6 ,
V_22 -> V_28 , ( unsigned long long ) V_22 -> V_29 ,
V_22 -> V_30 , V_22 -> V_31 ) ;
F_15 ( V_2 , L_7 , V_22 -> V_32 ,
V_22 -> V_33 ) ;
F_15 ( V_2 ,
L_8 ,
V_22 -> V_34 ,
V_22 -> V_35 ) ;
if ( V_22 -> V_36 )
F_15 ( V_2 , L_9 ,
V_22 -> V_36 ) ;
if ( V_22 -> V_37 & V_38 ) {
F_15 ( V_2 ,
L_10
L_11 ,
& V_22 -> V_39 ,
& V_22 -> V_40 , & V_22 -> V_41 ,
& V_22 -> V_42 ,
& V_22 -> V_43 , & V_22 -> V_44 ) ;
} else {
F_15 ( V_2 ,
L_12 ,
V_22 -> V_45 , V_22 -> V_46 ) ;
F_15 ( V_2 ,
L_13 ,
V_22 -> V_47 , V_22 -> V_48 ) ;
}
F_2 ( V_2 , L_14 ) ;
F_15 ( V_2 , L_15 ,
F_16 ( V_22 -> V_49 ) ?
V_22 -> V_50 -> V_51 : V_22 -> V_49 ) ;
F_2 ( V_2 , L_16 ) ;
F_15 ( V_2 , L_17 , V_22 -> V_52 ) ;
F_15 ( V_2 ,
L_18
L_19 ,
V_22 -> V_53 , V_22 -> V_54 ,
V_22 -> V_55 , V_22 -> V_56 ) ;
F_15 ( V_2 ,
L_20 ,
V_22 -> V_57 , V_22 -> V_58 ) ;
if ( V_22 -> V_59 ) {
unsigned int V_60 ;
F_2 ( V_2 , L_21 ) ;
for ( V_60 = 0 ; V_60 < V_22 -> V_59 ; V_60 ++ )
F_15 ( V_2 , L_22 , F_17 ( V_22 -> V_61 [ V_60 ] ) ,
V_60 == V_22 -> V_59 - 1 ? L_23 : L_24 ) ;
}
if ( V_22 -> V_62 != 0xffff )
F_15 ( V_2 , L_25 ,
V_22 -> V_62 , V_22 -> V_63 ,
V_22 -> V_64 ) ;
if ( V_22 -> V_65 != 0xffff )
F_15 ( V_2 , L_26 ,
V_22 -> V_65 , V_22 -> V_66 ,
V_22 -> V_67 ) ;
if ( V_22 -> V_68 )
F_15 ( V_2 , L_27 , V_22 -> V_68 ) ;
if ( V_22 -> V_69 )
F_15 ( V_2 , L_28 , V_22 -> V_69 ) ;
if ( V_22 -> V_70 > 1 )
F_15 ( V_2 , L_29 , V_22 -> V_70 ) ;
if ( V_22 -> V_71 >= 0 )
F_15 ( V_2 , L_30 , V_22 -> V_71 ) ;
F_2 ( V_2 , L_31 ) ;
if ( V_22 -> V_37 & V_38 )
F_2 ( V_2 , L_32 ) ;
if ( V_22 -> V_37 & V_72 )
F_2 ( V_2 , L_33 ) ;
if ( V_22 -> V_37 & V_73 )
F_2 ( V_2 , L_34 ) ;
if ( V_22 -> V_37 & V_74 )
F_2 ( V_2 , L_35 ) ;
if ( V_22 -> V_37 & V_75 )
F_2 ( V_2 , L_36 ) ;
if ( V_22 -> V_37 & V_76 )
F_2 ( V_2 , L_37 ) ;
if ( V_22 -> V_37 & V_77 )
F_2 ( V_2 , L_38 ) ;
if ( V_22 -> V_37 & V_78 )
F_2 ( V_2 , L_39 ) ;
if ( V_22 -> V_37 & V_79 )
F_2 ( V_2 , L_40 ) ;
if ( V_22 -> V_37 & V_80 )
F_2 ( V_2 , L_41 ) ;
if ( V_22 -> V_37 & V_81 )
F_2 ( V_2 , L_42 ) ;
if ( V_22 -> V_32 ) {
if ( V_22 -> V_37 & V_82 )
F_2 ( V_2 , L_43 ) ;
else
F_2 ( V_2 , L_44 ) ;
}
#ifdef F_18
if ( V_22 -> V_37 & V_83 ) {
F_2 ( V_2 , L_45 ) ;
if ( V_22 -> V_84 )
F_15 ( V_2 , L_46 , V_22 -> V_84 ) ;
}
#endif
if ( V_22 -> V_37 & V_85 )
F_2 ( V_2 , L_47 ) ;
if ( V_22 -> V_37 & V_86 )
F_2 ( V_2 , L_48 ) ;
if ( V_22 -> V_37 & V_87 )
F_2 ( V_2 , L_49 ) ;
if ( V_22 -> V_37 & V_88 )
F_2 ( V_2 , L_50 ) ;
if ( V_22 -> V_37 & V_89 )
F_2 ( V_2 , L_51 ) ;
F_2 ( V_2 , L_23 ) ;
V_24 = V_22 -> V_90 ? F_19 () : V_22 -> V_91 ;
V_25 = V_22 -> V_92 ;
F_20 ( V_25 , V_93 ) ;
F_15 ( V_2 ,
L_52 ,
( unsigned long long ) V_22 -> V_94 ,
( unsigned long long ) V_22 -> V_95 ) ;
F_15 ( V_2 ,
L_53 ,
( unsigned long long ) F_21 ( V_22 -> V_96 ) ,
( unsigned long long ) F_21 ( V_24 ) ,
( unsigned long long ) V_25 ) ;
F_15 ( V_2 ,
L_54 ,
V_22 -> V_97 , V_22 -> V_98 ,
V_22 -> V_99 ) ;
if ( V_22 -> V_37 & V_38 ) {
F_15 ( V_2 , L_55 ,
& V_22 -> V_100 ,
& V_22 -> V_101 ) ;
} else
F_15 ( V_2 , L_56 ,
& V_22 -> V_102 , & V_22 -> V_103 ) ;
F_15 ( V_2 , L_57 ,
V_22 -> V_104 , V_22 -> V_105 ) ;
F_15 ( V_2 , L_58 , V_22 -> V_106 ) ;
F_15 ( V_2 , L_59 , V_22 -> V_107 ) ;
if ( V_22 -> V_108 [ 0 ] )
F_15 ( V_2 , L_60 , V_22 -> V_108 ) ;
else
F_2 ( V_2 , L_61 ) ;
return 0 ;
}
static int F_22 ( const char T_2 * V_109 , unsigned long V_110 ,
T_7 * V_111 )
{
int V_60 = 0 ;
* V_111 = 0 ;
for (; V_60 < V_110 ; V_60 ++ ) {
int V_112 ;
char V_113 ;
* V_111 <<= 4 ;
if ( F_23 ( V_113 , & V_109 [ V_60 ] ) )
return - V_19 ;
V_112 = F_24 ( V_113 ) ;
if ( V_112 >= 0 )
* V_111 |= V_112 ;
else
break;
}
return V_60 ;
}
static int F_25 ( const char T_2 * V_109 ,
unsigned int V_110 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_110 ; V_60 ++ ) {
char V_113 ;
if ( F_23 ( V_113 , & V_109 [ V_60 ] ) )
return - V_19 ;
switch ( V_113 ) {
case '\"' :
case '\n' :
case '\r' :
case '\t' :
case ' ' :
case '=' :
break;
default:
goto V_114;
}
}
V_114:
return V_60 ;
}
static long F_26 ( const char T_2 * V_109 , unsigned long V_110 ,
unsigned long * V_111 )
{
int V_60 ;
* V_111 = 0 ;
for ( V_60 = 0 ; V_60 < V_110 ; V_60 ++ ) {
char V_113 ;
if ( F_23 ( V_113 , & V_109 [ V_60 ] ) )
return - V_19 ;
if ( ( V_113 >= '0' ) && ( V_113 <= '9' ) ) {
* V_111 *= 10 ;
* V_111 += V_113 - '0' ;
} else
break;
}
return V_60 ;
}
static int F_27 ( const char T_2 * V_109 , unsigned int V_110 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_110 ; V_60 ++ ) {
char V_113 ;
if ( F_23 ( V_113 , & V_109 [ V_60 ] ) )
return - V_19 ;
switch ( V_113 ) {
case '\"' :
case '\n' :
case '\r' :
case '\t' :
case ' ' :
goto V_115;
default:
break;
}
}
V_115:
return V_60 ;
}
static T_1 F_28 ( const char T_2 * V_116 , struct V_21 * V_22 )
{
unsigned int V_117 = 0 ;
char V_113 ;
T_1 V_60 = 0 ;
int V_118 ;
V_22 -> V_59 = 0 ;
do {
T_7 V_119 ;
V_118 = F_22 ( & V_116 [ V_60 ] , 8 , & V_119 ) ;
if ( V_118 <= 0 )
return V_118 ;
V_22 -> V_61 [ V_117 ] = F_29 ( V_119 ) ;
if ( V_22 -> V_61 [ V_117 ] & V_120 )
V_22 -> V_37 |= V_79 ;
V_60 += V_118 ;
if ( F_23 ( V_113 , & V_116 [ V_60 ] ) )
return - V_19 ;
V_60 ++ ;
V_117 ++ ;
if ( V_117 >= V_121 )
return - V_122 ;
} while ( V_113 == ',' );
V_22 -> V_59 = V_117 ;
return V_60 ;
}
static T_1 F_30 ( struct V_5 * V_5 ,
const char T_2 * V_109 , T_3 V_7 ,
T_4 * V_123 )
{
struct V_1 * V_2 = V_5 -> V_124 ;
struct V_21 * V_22 = V_2 -> V_23 ;
int V_60 , V_125 , V_118 ;
char V_126 [ 16 ] , V_127 [ 32 ] ;
unsigned long V_112 = 0 ;
char * V_128 = NULL ;
int V_119 = 0 ;
char V_6 [ 128 ] ;
V_128 = & ( V_22 -> V_108 [ 0 ] ) ;
if ( V_7 < 1 ) {
F_10 ( L_62 ) ;
return - V_18 ;
}
V_125 = V_7 ;
V_119 = F_25 ( V_109 , V_125 ) ;
if ( V_119 < 0 ) {
F_10 ( L_63 ) ;
return V_119 ;
}
V_60 = V_119 ;
V_118 = F_27 ( & V_109 [ V_60 ] , sizeof( V_126 ) - 1 ) ;
if ( V_118 < 0 )
return V_118 ;
memset ( V_126 , 0 , sizeof( V_126 ) ) ;
if ( F_6 ( V_126 , & V_109 [ V_60 ] , V_118 ) )
return - V_19 ;
V_60 += V_118 ;
V_125 = V_7 - V_60 ;
V_118 = F_25 ( & V_109 [ V_60 ] , V_125 ) ;
if ( V_118 < 0 )
return V_118 ;
V_60 += V_118 ;
if ( V_129 ) {
T_3 V_130 = F_31 ( T_3 , V_7 , 1023 ) ;
char V_131 [ V_130 + 1 ] ;
if ( F_6 ( V_131 , V_109 , V_130 ) )
return - V_19 ;
V_131 [ V_130 ] = 0 ;
F_32 ( L_64 ,
V_126 , ( unsigned long ) V_7 , V_131 ) ;
}
if ( ! strcmp ( V_126 , L_65 ) ) {
V_118 = F_26 ( & V_109 [ V_60 ] , 10 , & V_112 ) ;
if ( V_118 < 0 )
return V_118 ;
V_60 += V_118 ;
if ( V_112 < 14 + 20 + 8 )
V_112 = 14 + 20 + 8 ;
if ( V_112 != V_22 -> V_26 ) {
V_22 -> V_26 = V_112 ;
V_22 -> V_132 = V_112 ;
}
sprintf ( V_128 , L_66 ,
V_22 -> V_26 ) ;
return V_7 ;
}
if ( ! strcmp ( V_126 , L_67 ) ) {
V_118 = F_26 ( & V_109 [ V_60 ] , 10 , & V_112 ) ;
if ( V_118 < 0 )
return V_118 ;
V_60 += V_118 ;
if ( V_112 < 14 + 20 + 8 )
V_112 = 14 + 20 + 8 ;
if ( V_112 != V_22 -> V_27 ) {
V_22 -> V_27 = V_112 ;
V_22 -> V_132 = V_112 ;
}
sprintf ( V_128 , L_68 ,
V_22 -> V_27 ) ;
return V_7 ;
}
if ( ! strcmp ( V_126 , L_69 ) ) {
V_118 = F_26 ( & V_109 [ V_60 ] , 10 , & V_112 ) ;
if ( V_118 < 0 )
return V_118 ;
V_60 += V_118 ;
if ( V_112 < 14 + 20 + 8 )
V_112 = 14 + 20 + 8 ;
if ( V_112 != V_22 -> V_26 ) {
V_22 -> V_26 = V_112 ;
V_22 -> V_27 = V_112 ;
V_22 -> V_132 = V_112 ;
}
sprintf ( V_128 , L_70 , V_22 -> V_26 ) ;
return V_7 ;
}
if ( ! strcmp ( V_126 , L_71 ) ) {
V_118 = F_26 ( & V_109 [ V_60 ] , 10 , & V_112 ) ;
if ( V_118 < 0 )
return V_118 ;
V_60 += V_118 ;
V_129 = V_112 ;
sprintf ( V_128 , L_72 , V_129 ) ;
return V_7 ;
}
if ( ! strcmp ( V_126 , L_73 ) ) {
V_118 = F_26 ( & V_109 [ V_60 ] , 10 , & V_112 ) ;
if ( V_118 < 0 )
return V_118 ;
V_60 += V_118 ;
V_22 -> V_28 = V_112 ;
sprintf ( V_128 , L_74 , V_22 -> V_28 ) ;
return V_7 ;
}
if ( ! strcmp ( V_126 , L_75 ) ) {
V_118 = F_26 ( & V_109 [ V_60 ] , 10 , & V_112 ) ;
if ( V_118 < 0 )
return V_118 ;
V_60 += V_118 ;
if ( V_112 == 0x7FFFFFFF )
V_22 -> V_29 = V_133 ;
else
V_22 -> V_29 = ( T_6 ) V_112 ;
sprintf ( V_128 , L_76 ,
( unsigned long long ) V_22 -> V_29 ) ;
return V_7 ;
}
if ( ! strcmp ( V_126 , L_77 ) ) {
V_118 = F_26 ( & V_109 [ V_60 ] , 10 , & V_112 ) ;
if ( V_118 < 0 )
return V_118 ;
V_60 += V_118 ;
if ( ! V_112 )
return V_118 ;
V_22 -> V_29 = V_22 -> V_26 * 8 * V_93 / V_112 ;
if ( V_129 )
F_33 ( L_78 , V_22 -> V_29 ) ;
sprintf ( V_128 , L_79 , V_112 ) ;
return V_7 ;
}
if ( ! strcmp ( V_126 , L_80 ) ) {
V_118 = F_26 ( & V_109 [ V_60 ] , 10 , & V_112 ) ;
if ( V_118 < 0 )
return V_118 ;
V_60 += V_118 ;
if ( ! V_112 )
return V_118 ;
V_22 -> V_29 = V_134 / V_112 ;
if ( V_129 )
F_33 ( L_78 , V_22 -> V_29 ) ;
sprintf ( V_128 , L_79 , V_112 ) ;
return V_7 ;
}
if ( ! strcmp ( V_126 , L_81 ) ) {
V_118 = F_26 ( & V_109 [ V_60 ] , 10 , & V_112 ) ;
if ( V_118 < 0 )
return V_118 ;
V_60 += V_118 ;
if ( V_112 != V_22 -> V_53 ) {
V_22 -> V_53 = V_112 ;
V_22 -> V_105 = V_112 ;
}
sprintf ( V_128 , L_82 , V_22 -> V_53 ) ;
return V_7 ;
}
if ( ! strcmp ( V_126 , L_83 ) ) {
V_118 = F_26 ( & V_109 [ V_60 ] , 10 , & V_112 ) ;
if ( V_118 < 0 )
return V_118 ;
V_60 += V_118 ;
if ( V_112 != V_22 -> V_55 ) {
V_22 -> V_55 = V_112 ;
V_22 -> V_104 = V_112 ;
}
sprintf ( V_128 , L_84 , V_22 -> V_55 ) ;
return V_7 ;
}
if ( ! strcmp ( V_126 , L_85 ) ) {
V_118 = F_26 ( & V_109 [ V_60 ] , 10 , & V_112 ) ;
if ( V_118 < 0 )
return V_118 ;
V_60 += V_118 ;
if ( V_112 != V_22 -> V_54 ) {
V_22 -> V_54 = V_112 ;
V_22 -> V_105 = V_112 ;
}
sprintf ( V_128 , L_86 , V_22 -> V_54 ) ;
return V_7 ;
}
if ( ! strcmp ( V_126 , L_87 ) ) {
V_118 = F_26 ( & V_109 [ V_60 ] , 10 , & V_112 ) ;
if ( V_118 < 0 )
return V_118 ;
V_60 += V_118 ;
if ( V_112 != V_22 -> V_56 ) {
V_22 -> V_56 = V_112 ;
V_22 -> V_104 = V_112 ;
}
sprintf ( V_128 , L_88 , V_22 -> V_56 ) ;
return V_7 ;
}
if ( ! strcmp ( V_126 , L_89 ) ) {
V_118 = F_26 ( & V_109 [ V_60 ] , 10 , & V_112 ) ;
if ( V_118 < 0 )
return V_118 ;
if ( ( V_112 > 0 ) &&
( ! ( V_22 -> V_50 -> V_135 & V_136 ) ) )
return - V_137 ;
V_60 += V_118 ;
V_22 -> V_30 = V_112 ;
sprintf ( V_128 , L_90 , V_22 -> V_30 ) ;
return V_7 ;
}
if ( ! strcmp ( V_126 , L_91 ) ) {
V_118 = F_26 ( & V_109 [ V_60 ] , 10 , & V_112 ) ;
if ( V_118 < 0 )
return V_118 ;
V_60 += V_118 ;
V_22 -> V_7 = V_112 ;
sprintf ( V_128 , L_92 ,
( unsigned long long ) V_22 -> V_7 ) ;
return V_7 ;
}
if ( ! strcmp ( V_126 , L_93 ) ) {
V_118 = F_26 ( & V_109 [ V_60 ] , 10 , & V_112 ) ;
if ( V_118 < 0 )
return V_118 ;
V_60 += V_118 ;
if ( V_22 -> V_57 != V_112 ) {
V_22 -> V_57 = V_112 ;
V_22 -> V_99 = 0 ;
}
sprintf ( V_128 , L_94 ,
V_22 -> V_57 ) ;
return V_7 ;
}
if ( ! strcmp ( V_126 , L_95 ) ) {
V_118 = F_26 ( & V_109 [ V_60 ] , 10 , & V_112 ) ;
if ( V_118 < 0 )
return V_118 ;
V_60 += V_118 ;
if ( V_22 -> V_58 != V_112 ) {
V_22 -> V_58 = V_112 ;
V_22 -> V_98 = 0 ;
}
sprintf ( V_128 , L_96 ,
V_22 -> V_58 ) ;
return V_7 ;
}
if ( ! strcmp ( V_126 , L_97 ) ) {
V_118 = F_26 ( & V_109 [ V_60 ] , 10 , & V_112 ) ;
if ( V_118 < 0 )
return V_118 ;
V_60 += V_118 ;
if ( ( V_112 > 1 ) &&
( ! ( V_22 -> V_50 -> V_135 & V_136 ) ) )
return - V_137 ;
V_22 -> V_70 = V_112 < 1 ? 1 : V_112 ;
sprintf ( V_128 , L_98 , V_22 -> V_70 ) ;
return V_7 ;
}
if ( ! strcmp ( V_126 , L_99 ) ) {
V_118 = F_26 ( & V_109 [ V_60 ] , 10 , & V_112 ) ;
if ( V_118 < 0 )
return V_118 ;
V_60 += V_118 ;
if ( F_34 ( V_112 ) ) {
V_22 -> V_71 = V_112 ;
sprintf ( V_128 , L_100 , V_22 -> V_71 ) ;
if ( V_22 -> V_138 ) {
F_35 ( V_22 -> V_138 ) ;
V_22 -> V_138 = NULL ;
}
}
else
sprintf ( V_128 , L_101 ) ;
return V_7 ;
}
if ( ! strcmp ( V_126 , L_102 ) ) {
char V_139 [ 32 ] ;
memset ( V_139 , 0 , 32 ) ;
V_118 = F_27 ( & V_109 [ V_60 ] , sizeof( V_139 ) - 1 ) ;
if ( V_118 < 0 )
return V_118 ;
if ( F_6 ( V_139 , & V_109 [ V_60 ] , V_118 ) )
return - V_19 ;
V_60 += V_118 ;
if ( strcmp ( V_139 , L_103 ) == 0 )
V_22 -> V_37 |= V_72 ;
else if ( strcmp ( V_139 , L_104 ) == 0 )
V_22 -> V_37 &= ~ V_72 ;
else if ( strcmp ( V_139 , L_105 ) == 0 )
V_22 -> V_37 |= V_74 ;
else if ( strcmp ( V_139 , L_106 ) == 0 )
V_22 -> V_37 &= ~ V_74 ;
else if ( strcmp ( V_139 , L_107 ) == 0 )
V_22 -> V_37 |= V_73 ;
else if ( strcmp ( V_139 , L_108 ) == 0 )
V_22 -> V_37 &= ~ V_73 ;
else if ( strcmp ( V_139 , L_109 ) == 0 )
V_22 -> V_37 |= V_75 ;
else if ( strcmp ( V_139 , L_110 ) == 0 )
V_22 -> V_37 &= ~ V_75 ;
else if ( strcmp ( V_139 , L_111 ) == 0 )
V_22 -> V_37 |= V_76 ;
else if ( strcmp ( V_139 , L_112 ) == 0 )
V_22 -> V_37 &= ~ V_76 ;
else if ( strcmp ( V_139 , L_113 ) == 0 )
V_22 -> V_37 |= V_85 ;
else if ( strcmp ( V_139 , L_114 ) == 0 )
V_22 -> V_37 &= ~ V_85 ;
else if ( strcmp ( V_139 , L_115 ) == 0 )
V_22 -> V_37 |= V_86 ;
else if ( strcmp ( V_139 , L_116 ) == 0 )
V_22 -> V_37 &= ~ V_86 ;
else if ( strcmp ( V_139 , L_117 ) == 0 )
V_22 -> V_37 |= V_79 ;
else if ( strcmp ( V_139 , L_118 ) == 0 )
V_22 -> V_37 &= ~ V_79 ;
else if ( strcmp ( V_139 , L_119 ) == 0 )
V_22 -> V_37 |= V_87 ;
else if ( strcmp ( V_139 , L_120 ) == 0 )
V_22 -> V_37 &= ~ V_87 ;
else if ( strcmp ( V_139 , L_121 ) == 0 )
V_22 -> V_37 |= V_88 ;
else if ( strcmp ( V_139 , L_122 ) == 0 )
V_22 -> V_37 &= ~ V_88 ;
else if ( strcmp ( V_139 , L_123 ) == 0 )
V_22 -> V_37 |= V_82 ;
else if ( strcmp ( V_139 , L_124 ) == 0 )
V_22 -> V_37 |= V_80 ;
else if ( strcmp ( V_139 , L_125 ) == 0 )
V_22 -> V_37 &= ~ V_80 ;
else if ( strcmp ( V_139 , L_126 ) == 0 )
V_22 -> V_37 |= V_81 ;
else if ( strcmp ( V_139 , L_127 ) == 0 )
V_22 -> V_37 &= ~ V_81 ;
#ifdef F_18
else if ( strcmp ( V_139 , L_128 ) == 0 )
V_22 -> V_37 |= V_83 ;
#endif
else if ( strcmp ( V_139 , L_129 ) == 0 )
V_22 -> V_37 &= ~ V_38 ;
else if ( strcmp ( V_139 , L_130 ) == 0 )
V_22 -> V_37 |= V_89 ;
else if ( strcmp ( V_139 , L_131 ) == 0 )
V_22 -> V_37 &= ~ V_89 ;
else if ( strcmp ( V_139 , L_132 ) == 0 )
V_22 -> V_37 |= V_77 ;
else if ( strcmp ( V_139 , L_133 ) == 0 )
V_22 -> V_37 &= ~ V_77 ;
else if ( strcmp ( V_139 , L_134 ) == 0 )
V_22 -> V_37 |= V_78 ;
else {
sprintf ( V_128 ,
L_135 ,
V_139 ,
L_136
L_137
L_138
L_139
L_140
#ifdef F_18
L_141
#endif
L_142 ) ;
return V_7 ;
}
sprintf ( V_128 , L_143 , V_22 -> V_37 ) ;
return V_7 ;
}
if ( ! strcmp ( V_126 , L_144 ) || ! strcmp ( V_126 , L_145 ) ) {
V_118 = F_27 ( & V_109 [ V_60 ] , sizeof( V_22 -> V_45 ) - 1 ) ;
if ( V_118 < 0 )
return V_118 ;
if ( F_6 ( V_6 , & V_109 [ V_60 ] , V_118 ) )
return - V_19 ;
V_6 [ V_118 ] = 0 ;
if ( strcmp ( V_6 , V_22 -> V_45 ) != 0 ) {
memset ( V_22 -> V_45 , 0 , sizeof( V_22 -> V_45 ) ) ;
strncpy ( V_22 -> V_45 , V_6 , V_118 ) ;
V_22 -> V_140 = F_36 ( V_22 -> V_45 ) ;
V_22 -> V_103 = V_22 -> V_140 ;
}
if ( V_129 )
F_32 ( L_146 , V_22 -> V_45 ) ;
V_60 += V_118 ;
sprintf ( V_128 , L_147 , V_22 -> V_45 ) ;
return V_7 ;
}
if ( ! strcmp ( V_126 , L_148 ) ) {
V_118 = F_27 ( & V_109 [ V_60 ] , sizeof( V_22 -> V_46 ) - 1 ) ;
if ( V_118 < 0 )
return V_118 ;
if ( F_6 ( V_6 , & V_109 [ V_60 ] , V_118 ) )
return - V_19 ;
V_6 [ V_118 ] = 0 ;
if ( strcmp ( V_6 , V_22 -> V_46 ) != 0 ) {
memset ( V_22 -> V_46 , 0 , sizeof( V_22 -> V_46 ) ) ;
strncpy ( V_22 -> V_46 , V_6 , V_118 ) ;
V_22 -> V_141 = F_36 ( V_22 -> V_46 ) ;
V_22 -> V_103 = V_22 -> V_141 ;
}
if ( V_129 )
F_32 ( L_149 , V_22 -> V_46 ) ;
V_60 += V_118 ;
sprintf ( V_128 , L_150 , V_22 -> V_46 ) ;
return V_7 ;
}
if ( ! strcmp ( V_126 , L_151 ) ) {
V_118 = F_27 ( & V_109 [ V_60 ] , sizeof( V_6 ) - 1 ) ;
if ( V_118 < 0 )
return V_118 ;
V_22 -> V_37 |= V_38 ;
if ( F_6 ( V_6 , & V_109 [ V_60 ] , V_118 ) )
return - V_19 ;
V_6 [ V_118 ] = 0 ;
F_37 ( V_6 , - 1 , V_22 -> V_42 . V_142 , - 1 , NULL ) ;
snprintf ( V_6 , sizeof( V_6 ) , L_152 , & V_22 -> V_42 ) ;
V_22 -> V_101 = V_22 -> V_42 ;
if ( V_129 )
F_32 ( L_153 , V_6 ) ;
V_60 += V_118 ;
sprintf ( V_128 , L_154 , V_6 ) ;
return V_7 ;
}
if ( ! strcmp ( V_126 , L_155 ) ) {
V_118 = F_27 ( & V_109 [ V_60 ] , sizeof( V_6 ) - 1 ) ;
if ( V_118 < 0 )
return V_118 ;
V_22 -> V_37 |= V_38 ;
if ( F_6 ( V_6 , & V_109 [ V_60 ] , V_118 ) )
return - V_19 ;
V_6 [ V_118 ] = 0 ;
F_37 ( V_6 , - 1 , V_22 -> V_43 . V_142 , - 1 , NULL ) ;
snprintf ( V_6 , sizeof( V_6 ) , L_152 , & V_22 -> V_43 ) ;
V_22 -> V_101 = V_22 -> V_43 ;
if ( V_129 )
F_32 ( L_156 , V_6 ) ;
V_60 += V_118 ;
sprintf ( V_128 , L_157 , V_6 ) ;
return V_7 ;
}
if ( ! strcmp ( V_126 , L_158 ) ) {
V_118 = F_27 ( & V_109 [ V_60 ] , sizeof( V_6 ) - 1 ) ;
if ( V_118 < 0 )
return V_118 ;
V_22 -> V_37 |= V_38 ;
if ( F_6 ( V_6 , & V_109 [ V_60 ] , V_118 ) )
return - V_19 ;
V_6 [ V_118 ] = 0 ;
F_37 ( V_6 , - 1 , V_22 -> V_44 . V_142 , - 1 , NULL ) ;
snprintf ( V_6 , sizeof( V_6 ) , L_152 , & V_22 -> V_44 ) ;
if ( V_129 )
F_32 ( L_159 , V_6 ) ;
V_60 += V_118 ;
sprintf ( V_128 , L_160 , V_6 ) ;
return V_7 ;
}
if ( ! strcmp ( V_126 , L_161 ) ) {
V_118 = F_27 ( & V_109 [ V_60 ] , sizeof( V_6 ) - 1 ) ;
if ( V_118 < 0 )
return V_118 ;
V_22 -> V_37 |= V_38 ;
if ( F_6 ( V_6 , & V_109 [ V_60 ] , V_118 ) )
return - V_19 ;
V_6 [ V_118 ] = 0 ;
F_37 ( V_6 , - 1 , V_22 -> V_39 . V_142 , - 1 , NULL ) ;
snprintf ( V_6 , sizeof( V_6 ) , L_152 , & V_22 -> V_39 ) ;
V_22 -> V_100 = V_22 -> V_39 ;
if ( V_129 )
F_32 ( L_162 , V_6 ) ;
V_60 += V_118 ;
sprintf ( V_128 , L_163 , V_6 ) ;
return V_7 ;
}
if ( ! strcmp ( V_126 , L_164 ) ) {
V_118 = F_27 ( & V_109 [ V_60 ] , sizeof( V_22 -> V_47 ) - 1 ) ;
if ( V_118 < 0 )
return V_118 ;
if ( F_6 ( V_6 , & V_109 [ V_60 ] , V_118 ) )
return - V_19 ;
V_6 [ V_118 ] = 0 ;
if ( strcmp ( V_6 , V_22 -> V_47 ) != 0 ) {
memset ( V_22 -> V_47 , 0 , sizeof( V_22 -> V_47 ) ) ;
strncpy ( V_22 -> V_47 , V_6 , V_118 ) ;
V_22 -> V_143 = F_36 ( V_22 -> V_47 ) ;
V_22 -> V_102 = V_22 -> V_143 ;
}
if ( V_129 )
F_32 ( L_165 , V_22 -> V_47 ) ;
V_60 += V_118 ;
sprintf ( V_128 , L_166 , V_22 -> V_47 ) ;
return V_7 ;
}
if ( ! strcmp ( V_126 , L_167 ) ) {
V_118 = F_27 ( & V_109 [ V_60 ] , sizeof( V_22 -> V_48 ) - 1 ) ;
if ( V_118 < 0 )
return V_118 ;
if ( F_6 ( V_6 , & V_109 [ V_60 ] , V_118 ) )
return - V_19 ;
V_6 [ V_118 ] = 0 ;
if ( strcmp ( V_6 , V_22 -> V_48 ) != 0 ) {
memset ( V_22 -> V_48 , 0 , sizeof( V_22 -> V_48 ) ) ;
strncpy ( V_22 -> V_48 , V_6 , V_118 ) ;
V_22 -> V_144 = F_36 ( V_22 -> V_48 ) ;
V_22 -> V_102 = V_22 -> V_144 ;
}
if ( V_129 )
F_32 ( L_168 , V_22 -> V_48 ) ;
V_60 += V_118 ;
sprintf ( V_128 , L_169 , V_22 -> V_48 ) ;
return V_7 ;
}
if ( ! strcmp ( V_126 , L_170 ) ) {
V_118 = F_27 ( & V_109 [ V_60 ] , sizeof( V_127 ) - 1 ) ;
if ( V_118 < 0 )
return V_118 ;
memset ( V_127 , 0 , sizeof( V_127 ) ) ;
if ( F_6 ( V_127 , & V_109 [ V_60 ] , V_118 ) )
return - V_19 ;
if ( ! F_38 ( V_127 , V_22 -> V_52 ) )
return - V_18 ;
F_39 ( & V_22 -> V_145 [ 0 ] , V_22 -> V_52 ) ;
sprintf ( V_128 , L_171 , V_22 -> V_52 ) ;
return V_7 ;
}
if ( ! strcmp ( V_126 , L_172 ) ) {
V_118 = F_27 ( & V_109 [ V_60 ] , sizeof( V_127 ) - 1 ) ;
if ( V_118 < 0 )
return V_118 ;
memset ( V_127 , 0 , sizeof( V_127 ) ) ;
if ( F_6 ( V_127 , & V_109 [ V_60 ] , V_118 ) )
return - V_19 ;
if ( ! F_38 ( V_127 , V_22 -> V_49 ) )
return - V_18 ;
F_39 ( & V_22 -> V_145 [ 6 ] , V_22 -> V_49 ) ;
sprintf ( V_128 , L_173 , V_22 -> V_49 ) ;
return V_7 ;
}
if ( ! strcmp ( V_126 , L_174 ) ) {
F_40 ( V_22 ) ;
sprintf ( V_128 , L_175 ) ;
return V_7 ;
}
if ( ! strcmp ( V_126 , L_176 ) ) {
V_118 = F_26 ( & V_109 [ V_60 ] , 10 , & V_112 ) ;
if ( V_118 < 0 )
return V_118 ;
V_60 += V_118 ;
if ( V_112 > V_146 )
V_112 = V_146 ;
V_22 -> V_32 = V_112 ;
sprintf ( V_128 , L_177 , V_22 -> V_32 ) ;
return V_7 ;
}
#ifdef F_18
if ( ! strcmp ( V_126 , L_178 ) ) {
V_118 = F_26 ( & V_109 [ V_60 ] , 10 , & V_112 ) ;
if ( V_118 < 0 )
return V_118 ;
V_60 += V_118 ;
V_22 -> V_84 = V_112 ;
sprintf ( V_128 , L_179 , V_22 -> V_84 ) ;
return V_7 ;
}
#endif
if ( ! strcmp ( V_126 , L_180 ) ) {
V_118 = F_26 ( & V_109 [ V_60 ] , 10 , & V_112 ) ;
if ( V_118 < 0 )
return V_118 ;
V_60 += V_118 ;
V_22 -> V_33 = V_112 ;
sprintf ( V_128 , L_181 , V_22 -> V_33 ) ;
return V_7 ;
}
if ( ! strcmp ( V_126 , L_182 ) ) {
V_118 = F_26 ( & V_109 [ V_60 ] , 5 , & V_112 ) ;
if ( V_118 < 0 )
return V_118 ;
V_60 += V_118 ;
V_22 -> V_34 = V_112 ;
sprintf ( V_128 , L_183 , V_22 -> V_34 ) ;
return V_7 ;
}
if ( ! strcmp ( V_126 , L_184 ) ) {
V_118 = F_26 ( & V_109 [ V_60 ] , 5 , & V_112 ) ;
if ( V_118 < 0 )
return V_118 ;
V_60 += V_118 ;
V_22 -> V_35 = V_112 ;
sprintf ( V_128 , L_185 , V_22 -> V_35 ) ;
return V_7 ;
}
if ( ! strcmp ( V_126 , L_186 ) ) {
unsigned int V_117 , V_147 ;
V_118 = F_28 ( & V_109 [ V_60 ] , V_22 ) ;
if ( V_118 < 0 )
return V_118 ;
V_60 += V_118 ;
V_147 = sprintf ( V_128 , L_187 ) ;
for ( V_117 = 0 ; V_117 < V_22 -> V_59 ; V_117 ++ )
V_147 += sprintf ( V_128 + V_147 ,
L_22 , F_17 ( V_22 -> V_61 [ V_117 ] ) ,
V_117 == V_22 -> V_59 - 1 ? L_188 : L_189 ) ;
if ( V_22 -> V_59 && V_22 -> V_62 != 0xffff ) {
V_22 -> V_62 = 0xffff ;
V_22 -> V_65 = 0xffff ;
if ( V_129 )
F_32 ( L_190 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_126 , L_191 ) ) {
V_118 = F_26 ( & V_109 [ V_60 ] , 4 , & V_112 ) ;
if ( V_118 < 0 )
return V_118 ;
V_60 += V_118 ;
if ( V_112 <= 4095 ) {
V_22 -> V_62 = V_112 ;
if ( V_129 )
F_32 ( L_192 ) ;
if ( V_129 && V_22 -> V_59 )
F_32 ( L_193 ) ;
V_22 -> V_59 = 0 ;
sprintf ( V_128 , L_194 , V_22 -> V_62 ) ;
} else {
V_22 -> V_62 = 0xffff ;
V_22 -> V_65 = 0xffff ;
if ( V_129 )
F_32 ( L_195 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_126 , L_196 ) ) {
V_118 = F_26 ( & V_109 [ V_60 ] , 1 , & V_112 ) ;
if ( V_118 < 0 )
return V_118 ;
V_60 += V_118 ;
if ( ( V_112 <= 7 ) && ( V_22 -> V_62 != 0xffff ) ) {
V_22 -> V_63 = V_112 ;
sprintf ( V_128 , L_197 , V_22 -> V_63 ) ;
} else {
sprintf ( V_128 , L_198 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_126 , L_199 ) ) {
V_118 = F_26 ( & V_109 [ V_60 ] , 1 , & V_112 ) ;
if ( V_118 < 0 )
return V_118 ;
V_60 += V_118 ;
if ( ( V_112 <= 1 ) && ( V_22 -> V_62 != 0xffff ) ) {
V_22 -> V_64 = V_112 ;
sprintf ( V_128 , L_200 , V_22 -> V_64 ) ;
} else {
sprintf ( V_128 , L_201 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_126 , L_202 ) ) {
V_118 = F_26 ( & V_109 [ V_60 ] , 4 , & V_112 ) ;
if ( V_118 < 0 )
return V_118 ;
V_60 += V_118 ;
if ( ( V_112 <= 4095 ) && ( ( V_22 -> V_62 != 0xffff ) ) ) {
V_22 -> V_65 = V_112 ;
if ( V_129 )
F_32 ( L_203 ) ;
if ( V_129 && V_22 -> V_59 )
F_32 ( L_193 ) ;
V_22 -> V_59 = 0 ;
sprintf ( V_128 , L_204 , V_22 -> V_65 ) ;
} else {
V_22 -> V_62 = 0xffff ;
V_22 -> V_65 = 0xffff ;
if ( V_129 )
F_32 ( L_195 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_126 , L_205 ) ) {
V_118 = F_26 ( & V_109 [ V_60 ] , 1 , & V_112 ) ;
if ( V_118 < 0 )
return V_118 ;
V_60 += V_118 ;
if ( ( V_112 <= 7 ) && ( V_22 -> V_65 != 0xffff ) ) {
V_22 -> V_66 = V_112 ;
sprintf ( V_128 , L_206 , V_22 -> V_66 ) ;
} else {
sprintf ( V_128 , L_207 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_126 , L_208 ) ) {
V_118 = F_26 ( & V_109 [ V_60 ] , 1 , & V_112 ) ;
if ( V_118 < 0 )
return V_118 ;
V_60 += V_118 ;
if ( ( V_112 <= 1 ) && ( V_22 -> V_65 != 0xffff ) ) {
V_22 -> V_67 = V_112 ;
sprintf ( V_128 , L_209 , V_22 -> V_67 ) ;
} else {
sprintf ( V_128 , L_210 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_126 , L_211 ) ) {
T_7 V_148 = 0 ;
V_118 = F_22 ( & V_109 [ V_60 ] , 2 , & V_148 ) ;
if ( V_118 < 0 )
return V_118 ;
V_60 += V_118 ;
if ( V_118 == 2 ) {
V_22 -> V_68 = V_148 ;
sprintf ( V_128 , L_212 , V_22 -> V_68 ) ;
} else {
sprintf ( V_128 , L_213 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_126 , L_214 ) ) {
T_7 V_148 = 0 ;
V_118 = F_22 ( & V_109 [ V_60 ] , 2 , & V_148 ) ;
if ( V_118 < 0 )
return V_118 ;
V_60 += V_118 ;
if ( V_118 == 2 ) {
V_22 -> V_69 = V_148 ;
sprintf ( V_128 , L_215 , V_22 -> V_69 ) ;
} else {
sprintf ( V_128 , L_216 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_126 , L_217 ) ) {
V_118 = F_26 ( & V_109 [ V_60 ] , 9 , & V_112 ) ;
if ( V_118 < 0 )
return V_118 ;
V_60 += V_118 ;
V_22 -> V_36 = V_112 ;
sprintf ( V_128 , L_218 ,
V_22 -> V_36 ) ;
return V_7 ;
}
sprintf ( V_22 -> V_108 , L_219 , V_126 ) ;
return - V_18 ;
}
static int F_41 ( struct V_20 * V_20 , struct V_5 * V_5 )
{
return F_12 ( V_5 , F_14 , F_13 ( V_20 ) ) ;
}
static int F_42 ( struct V_1 * V_2 , void * V_3 )
{
struct V_149 * V_150 = V_2 -> V_23 ;
const struct V_21 * V_22 ;
F_43 ( ! V_150 ) ;
F_2 ( V_2 , L_220 ) ;
F_44 () ;
F_45 (pkt_dev, &t->if_list, list)
if ( V_22 -> V_90 )
F_15 ( V_2 , L_221 , V_22 -> V_31 ) ;
F_2 ( V_2 , L_222 ) ;
F_45 (pkt_dev, &t->if_list, list)
if ( ! V_22 -> V_90 )
F_15 ( V_2 , L_221 , V_22 -> V_31 ) ;
if ( V_150 -> V_108 [ 0 ] )
F_15 ( V_2 , L_223 , V_150 -> V_108 ) ;
else
F_2 ( V_2 , L_224 ) ;
F_46 () ;
return 0 ;
}
static T_1 F_47 ( struct V_5 * V_5 ,
const char T_2 * V_109 ,
T_3 V_7 , T_4 * V_123 )
{
struct V_1 * V_2 = V_5 -> V_124 ;
struct V_149 * V_150 = V_2 -> V_23 ;
int V_60 , V_125 , V_118 , V_151 ;
char V_126 [ 40 ] ;
char * V_128 ;
if ( V_7 < 1 ) {
return - V_18 ;
}
V_125 = V_7 ;
V_118 = F_25 ( V_109 , V_125 ) ;
if ( V_118 < 0 )
return V_118 ;
V_60 = V_118 ;
V_118 = F_27 ( & V_109 [ V_60 ] , sizeof( V_126 ) - 1 ) ;
if ( V_118 < 0 )
return V_118 ;
memset ( V_126 , 0 , sizeof( V_126 ) ) ;
if ( F_6 ( V_126 , & V_109 [ V_60 ] , V_118 ) )
return - V_19 ;
V_60 += V_118 ;
V_125 = V_7 - V_60 ;
V_118 = F_25 ( & V_109 [ V_60 ] , V_125 ) ;
if ( V_118 < 0 )
return V_118 ;
V_60 += V_118 ;
if ( V_129 )
F_32 ( L_225 , V_126 , ( unsigned long ) V_7 ) ;
if ( ! V_150 ) {
F_48 ( L_226 ) ;
V_151 = - V_18 ;
goto V_152;
}
V_128 = & ( V_150 -> V_108 [ 0 ] ) ;
if ( ! strcmp ( V_126 , L_227 ) ) {
char V_139 [ 32 ] ;
memset ( V_139 , 0 , 32 ) ;
V_118 = F_27 ( & V_109 [ V_60 ] , sizeof( V_139 ) - 1 ) ;
if ( V_118 < 0 ) {
V_151 = V_118 ;
goto V_152;
}
if ( F_6 ( V_139 , & V_109 [ V_60 ] , V_118 ) )
return - V_19 ;
V_60 += V_118 ;
F_49 ( & V_153 ) ;
V_151 = F_50 ( V_150 , V_139 ) ;
F_51 ( & V_153 ) ;
if ( ! V_151 ) {
V_151 = V_7 ;
sprintf ( V_128 , L_228 , V_139 ) ;
} else
sprintf ( V_128 , L_229 , V_139 ) ;
goto V_152;
}
if ( ! strcmp ( V_126 , L_230 ) ) {
F_49 ( & V_153 ) ;
V_150 -> V_154 |= V_155 ;
F_51 ( & V_153 ) ;
F_52 ( F_53 ( 125 ) ) ;
V_151 = V_7 ;
sprintf ( V_128 , L_231 ) ;
goto V_152;
}
if ( ! strcmp ( V_126 , L_232 ) ) {
sprintf ( V_128 , L_233 ) ;
V_151 = V_7 ;
goto V_152;
}
V_151 = - V_18 ;
V_152:
return V_151 ;
}
static int F_54 ( struct V_20 * V_20 , struct V_5 * V_5 )
{
return F_12 ( V_5 , F_42 , F_13 ( V_20 ) ) ;
}
static struct V_21 * F_55 ( const struct V_10 * V_11 ,
const char * V_156 , int remove )
{
struct V_149 * V_150 ;
struct V_21 * V_22 = NULL ;
bool V_157 = ( remove == V_158 ) ;
F_56 (t, &pn->pktgen_threads, th_list) {
V_22 = F_57 ( V_150 , V_156 , V_157 ) ;
if ( V_22 ) {
if ( remove ) {
V_22 -> V_159 = 1 ;
V_150 -> V_154 |= V_160 ;
}
break;
}
}
return V_22 ;
}
static void F_58 ( const struct V_10 * V_11 , const char * V_156 )
{
struct V_21 * V_22 = NULL ;
const int V_161 = 10 , V_162 = 125 ;
int V_60 = 0 ;
F_49 ( & V_153 ) ;
F_32 ( L_234 , V_163 , V_156 ) ;
while ( 1 ) {
V_22 = F_55 ( V_11 , V_156 , REMOVE ) ;
if ( V_22 == NULL )
break;
F_51 ( & V_153 ) ;
F_32 ( L_235 ,
V_163 , V_156 ) ;
F_52 ( F_53 ( V_162 ) ) ;
F_49 ( & V_153 ) ;
if ( ++ V_60 >= V_161 ) {
F_48 ( L_236 ,
V_163 , V_162 * V_60 , V_156 ) ;
break;
}
}
F_51 ( & V_153 ) ;
}
static void F_59 ( const struct V_10 * V_11 , struct V_164 * V_165 )
{
struct V_149 * V_150 ;
F_56 (t, &pn->pktgen_threads, th_list) {
struct V_21 * V_22 ;
F_44 () ;
F_45 (pkt_dev, &t->if_list, list) {
if ( V_22 -> V_50 != V_165 )
continue;
F_60 ( V_22 -> V_166 ) ;
V_22 -> V_166 = F_61 ( V_165 -> V_126 , 0600 ,
V_11 -> V_167 ,
& V_168 ,
V_22 ) ;
if ( ! V_22 -> V_166 )
F_48 ( L_237 ,
V_165 -> V_126 ) ;
break;
}
F_46 () ;
}
}
static int F_62 ( struct V_169 * V_170 ,
unsigned long V_171 , void * V_172 )
{
struct V_164 * V_165 = F_63 ( V_172 ) ;
struct V_10 * V_11 = F_4 ( F_64 ( V_165 ) , V_15 ) ;
if ( V_11 -> V_173 )
return V_174 ;
switch ( V_171 ) {
case V_175 :
F_59 ( V_11 , V_165 ) ;
break;
case V_176 :
F_58 ( V_11 , V_165 -> V_126 ) ;
break;
}
return V_174 ;
}
static struct V_164 * F_65 ( const struct V_10 * V_11 ,
struct V_21 * V_22 ,
const char * V_156 )
{
char V_177 [ V_178 + 5 ] ;
int V_60 ;
for ( V_60 = 0 ; V_156 [ V_60 ] != '@' ; V_60 ++ ) {
if ( V_60 == V_178 )
break;
V_177 [ V_60 ] = V_156 [ V_60 ] ;
}
V_177 [ V_60 ] = 0 ;
return F_66 ( V_11 -> V_179 , V_177 ) ;
}
static int F_67 ( const struct V_10 * V_11 ,
struct V_21 * V_22 , const char * V_156 )
{
struct V_164 * V_50 ;
int V_180 ;
if ( V_22 -> V_50 ) {
F_68 ( V_22 -> V_50 ) ;
V_22 -> V_50 = NULL ;
}
V_50 = F_65 ( V_11 , V_22 , V_156 ) ;
if ( ! V_50 ) {
F_48 ( L_238 , V_156 ) ;
return - V_181 ;
}
if ( V_50 -> type != V_182 ) {
F_48 ( L_239 , V_156 ) ;
V_180 = - V_18 ;
} else if ( ! F_69 ( V_50 ) ) {
F_48 ( L_240 , V_156 ) ;
V_180 = - V_183 ;
} else {
V_22 -> V_50 = V_50 ;
return 0 ;
}
F_68 ( V_50 ) ;
return V_180 ;
}
static void F_70 ( struct V_21 * V_22 )
{
int V_184 ;
if ( ! V_22 -> V_50 ) {
F_48 ( L_241 ) ;
sprintf ( V_22 -> V_108 ,
L_242 ) ;
return;
}
V_184 = V_22 -> V_50 -> V_185 ;
if ( V_184 <= V_22 -> V_34 ) {
F_10 ( L_243 ,
V_22 -> V_34 , ( V_184 ? : 1 ) - 1 , V_184 ,
V_22 -> V_31 ) ;
V_22 -> V_34 = ( V_184 ? : 1 ) - 1 ;
}
if ( V_22 -> V_35 >= V_184 ) {
F_10 ( L_244 ,
V_22 -> V_35 , ( V_184 ? : 1 ) - 1 , V_184 ,
V_22 -> V_31 ) ;
V_22 -> V_35 = ( V_184 ? : 1 ) - 1 ;
}
if ( F_16 ( V_22 -> V_49 ) )
F_39 ( & ( V_22 -> V_145 [ 6 ] ) , V_22 -> V_50 -> V_51 ) ;
F_39 ( & ( V_22 -> V_145 [ 0 ] ) , V_22 -> V_52 ) ;
if ( V_22 -> V_37 & V_38 ) {
int V_60 , V_186 = 0 , V_180 = 1 ;
struct V_187 * V_188 ;
if ( V_22 -> V_26 == 0 ) {
V_22 -> V_26 = 14 + sizeof( struct V_189 )
+ sizeof( struct V_190 )
+ sizeof( struct V_191 )
+ V_22 -> V_192 ;
}
for ( V_60 = 0 ; V_60 < V_193 ; V_60 ++ )
if ( V_22 -> V_100 . V_142 [ V_60 ] ) {
V_186 = 1 ;
break;
}
if ( ! V_186 ) {
F_44 () ;
V_188 = F_71 ( V_22 -> V_50 ) ;
if ( V_188 ) {
struct V_194 * V_195 ;
F_72 ( & V_188 -> V_196 ) ;
F_56 (ifp, &idev->addr_list, if_list) {
if ( ( V_195 -> V_197 & V_198 ) &&
! ( V_195 -> V_37 & V_199 ) ) {
V_22 -> V_100 = V_195 -> V_200 ;
V_180 = 0 ;
break;
}
}
F_73 ( & V_188 -> V_196 ) ;
}
F_46 () ;
if ( V_180 )
F_48 ( L_245 ) ;
}
} else {
if ( V_22 -> V_26 == 0 ) {
V_22 -> V_26 = 14 + sizeof( struct V_201 )
+ sizeof( struct V_190 )
+ sizeof( struct V_191 )
+ V_22 -> V_192 ;
}
V_22 -> V_143 = 0 ;
V_22 -> V_144 = 0 ;
if ( strlen ( V_22 -> V_47 ) == 0 ) {
struct V_202 * V_203 ;
F_44 () ;
V_203 = F_74 ( V_22 -> V_50 ) ;
if ( V_203 ) {
if ( V_203 -> V_204 ) {
V_22 -> V_143 =
V_203 -> V_204 -> V_205 ;
V_22 -> V_144 = V_22 -> V_143 ;
}
}
F_46 () ;
} else {
V_22 -> V_143 = F_36 ( V_22 -> V_47 ) ;
V_22 -> V_144 = F_36 ( V_22 -> V_48 ) ;
}
V_22 -> V_140 = F_36 ( V_22 -> V_45 ) ;
V_22 -> V_141 = F_36 ( V_22 -> V_46 ) ;
}
V_22 -> V_132 = V_22 -> V_26 ;
if ( V_22 -> V_26 > V_22 -> V_27 )
V_22 -> V_27 = V_22 -> V_26 ;
V_22 -> V_98 = 0 ;
V_22 -> V_99 = 0 ;
V_22 -> V_102 = V_22 -> V_143 ;
V_22 -> V_103 = V_22 -> V_140 ;
V_22 -> V_104 = V_22 -> V_55 ;
V_22 -> V_105 = V_22 -> V_53 ;
V_22 -> V_107 = 0 ;
}
static void F_75 ( struct V_21 * V_22 , T_5 V_206 )
{
T_5 V_207 , V_208 ;
T_8 V_209 ;
struct V_210 V_150 ;
F_76 ( & V_150 . V_211 , V_212 , V_213 ) ;
F_77 ( & V_150 . V_211 , V_206 ) ;
V_209 = F_78 ( F_79 ( & V_150 . V_211 ) ) ;
if ( V_209 <= 0 ) {
V_22 -> V_214 = F_80 ( V_206 , V_22 -> V_29 ) ;
return;
}
V_207 = F_19 () ;
if ( V_209 < 100000 ) {
do {
V_208 = F_19 () ;
} while ( F_81 ( V_208 , V_206 ) < 0 );
} else {
F_82 ( & V_150 , V_12 ) ;
do {
F_83 ( V_215 ) ;
F_84 ( & V_150 . V_211 , V_213 ) ;
if ( ! F_85 ( & V_150 . V_211 ) )
V_150 . V_216 = NULL ;
if ( F_86 ( V_150 . V_216 ) )
F_87 () ;
F_88 ( & V_150 . V_211 ) ;
} while ( V_150 . V_216 && V_22 -> V_90 && ! F_89 ( V_12 ) );
F_90 ( V_217 ) ;
V_208 = F_19 () ;
}
V_22 -> V_92 += F_78 ( F_91 ( V_208 , V_207 ) ) ;
V_22 -> V_214 = F_80 ( V_206 , V_22 -> V_29 ) ;
}
static inline void F_92 ( struct V_21 * V_22 )
{
V_22 -> V_192 = 0 ;
V_22 -> V_192 += V_22 -> V_59 * sizeof( V_218 ) ;
V_22 -> V_192 += F_93 ( V_22 ) ;
V_22 -> V_192 += F_94 ( V_22 ) ;
}
static inline int F_95 ( const struct V_21 * V_22 , int V_219 )
{
return ! ! ( V_22 -> V_220 [ V_219 ] . V_37 & V_221 ) ;
}
static inline int F_96 ( struct V_21 * V_22 )
{
int V_219 = V_22 -> V_222 ;
if ( V_22 -> V_37 & V_82 ) {
if ( V_22 -> V_220 [ V_219 ] . V_7 >= V_22 -> V_33 ) {
V_22 -> V_220 [ V_219 ] . V_7 = 0 ;
V_22 -> V_220 [ V_219 ] . V_37 = 0 ;
V_22 -> V_222 += 1 ;
if ( V_22 -> V_222 >= V_22 -> V_32 )
V_22 -> V_222 = 0 ;
}
} else {
V_219 = F_97 () % V_22 -> V_32 ;
V_22 -> V_222 = V_219 ;
if ( V_22 -> V_220 [ V_219 ] . V_7 > V_22 -> V_33 ) {
V_22 -> V_220 [ V_219 ] . V_7 = 0 ;
V_22 -> V_220 [ V_219 ] . V_37 = 0 ;
}
}
return V_22 -> V_222 ;
}
static void F_98 ( struct V_21 * V_22 , int V_219 )
{
struct V_223 * V_224 = V_22 -> V_220 [ V_219 ] . V_224 ;
struct V_10 * V_11 = F_4 ( F_64 ( V_22 -> V_50 ) , V_15 ) ;
if ( ! V_224 ) {
if ( V_22 -> V_84 ) {
V_224 = F_99 ( V_11 -> V_179 , F_29 ( V_22 -> V_84 ) , V_225 ) ;
} else {
V_224 = F_100 ( V_11 -> V_179 , V_226 ,
( V_227 * ) & V_22 -> V_103 ,
( V_227 * ) & V_22 -> V_102 ,
V_225 ,
V_22 -> V_228 ,
V_22 -> V_229 , 0 ) ;
}
if ( V_224 ) {
V_22 -> V_220 [ V_219 ] . V_224 = V_224 ;
F_92 ( V_22 ) ;
V_22 -> V_192 += V_224 -> V_230 . V_231 ;
}
}
}
static void F_101 ( struct V_21 * V_22 )
{
if ( V_22 -> V_37 & V_81 )
V_22 -> V_106 = F_102 () ;
else if ( V_22 -> V_34 <= V_22 -> V_35 ) {
T_9 V_150 ;
if ( V_22 -> V_37 & V_80 ) {
V_150 = F_97 () %
( V_22 -> V_35 -
V_22 -> V_34 + 1 )
+ V_22 -> V_34 ;
} else {
V_150 = V_22 -> V_106 + 1 ;
if ( V_150 > V_22 -> V_35 )
V_150 = V_22 -> V_34 ;
}
V_22 -> V_106 = V_150 ;
}
V_22 -> V_106 = V_22 -> V_106 % V_22 -> V_50 -> V_185 ;
}
static void F_103 ( struct V_21 * V_22 )
{
T_7 V_232 ;
T_7 V_233 ;
int V_219 = 0 ;
if ( V_22 -> V_32 )
V_219 = F_96 ( V_22 ) ;
if ( V_22 -> V_57 > 1 ) {
T_7 V_234 ;
T_7 V_119 ;
if ( V_22 -> V_37 & V_85 )
V_234 = F_97 () % V_22 -> V_57 ;
else {
V_234 = V_22 -> V_99 ++ ;
if ( V_22 -> V_99 >=
V_22 -> V_57 )
V_22 -> V_99 = 0 ;
}
V_119 = V_22 -> V_49 [ 5 ] + ( V_234 & 0xFF ) ;
V_22 -> V_145 [ 11 ] = V_119 ;
V_119 = ( V_22 -> V_49 [ 4 ] + ( ( V_234 >> 8 ) & 0xFF ) + ( V_119 >> 8 ) ) ;
V_22 -> V_145 [ 10 ] = V_119 ;
V_119 = ( V_22 -> V_49 [ 3 ] + ( ( V_234 >> 16 ) & 0xFF ) + ( V_119 >> 8 ) ) ;
V_22 -> V_145 [ 9 ] = V_119 ;
V_119 = ( V_22 -> V_49 [ 2 ] + ( ( V_234 >> 24 ) & 0xFF ) + ( V_119 >> 8 ) ) ;
V_22 -> V_145 [ 8 ] = V_119 ;
V_119 = ( V_22 -> V_49 [ 1 ] + ( V_119 >> 8 ) ) ;
V_22 -> V_145 [ 7 ] = V_119 ;
}
if ( V_22 -> V_58 > 1 ) {
T_7 V_234 ;
T_7 V_119 ;
if ( V_22 -> V_37 & V_86 )
V_234 = F_97 () % V_22 -> V_58 ;
else {
V_234 = V_22 -> V_98 ++ ;
if ( V_22 -> V_98 >=
V_22 -> V_58 ) {
V_22 -> V_98 = 0 ;
}
}
V_119 = V_22 -> V_52 [ 5 ] + ( V_234 & 0xFF ) ;
V_22 -> V_145 [ 5 ] = V_119 ;
V_119 = ( V_22 -> V_52 [ 4 ] + ( ( V_234 >> 8 ) & 0xFF ) + ( V_119 >> 8 ) ) ;
V_22 -> V_145 [ 4 ] = V_119 ;
V_119 = ( V_22 -> V_52 [ 3 ] + ( ( V_234 >> 16 ) & 0xFF ) + ( V_119 >> 8 ) ) ;
V_22 -> V_145 [ 3 ] = V_119 ;
V_119 = ( V_22 -> V_52 [ 2 ] + ( ( V_234 >> 24 ) & 0xFF ) + ( V_119 >> 8 ) ) ;
V_22 -> V_145 [ 2 ] = V_119 ;
V_119 = ( V_22 -> V_52 [ 1 ] + ( V_119 >> 8 ) ) ;
V_22 -> V_145 [ 1 ] = V_119 ;
}
if ( V_22 -> V_37 & V_79 ) {
unsigned int V_60 ;
for ( V_60 = 0 ; V_60 < V_22 -> V_59 ; V_60 ++ )
if ( V_22 -> V_61 [ V_60 ] & V_120 )
V_22 -> V_61 [ V_60 ] = V_120 |
( ( V_235 V_236 ) F_97 () &
F_29 ( 0x000fffff ) ) ;
}
if ( ( V_22 -> V_37 & V_87 ) && ( V_22 -> V_62 != 0xffff ) ) {
V_22 -> V_62 = F_97 () & ( 4096 - 1 ) ;
}
if ( ( V_22 -> V_37 & V_88 ) && ( V_22 -> V_65 != 0xffff ) ) {
V_22 -> V_65 = F_97 () & ( 4096 - 1 ) ;
}
if ( V_22 -> V_53 < V_22 -> V_54 ) {
if ( V_22 -> V_37 & V_75 )
V_22 -> V_105 = F_97 () %
( V_22 -> V_54 - V_22 -> V_53 )
+ V_22 -> V_53 ;
else {
V_22 -> V_105 ++ ;
if ( V_22 -> V_105 >= V_22 -> V_54 )
V_22 -> V_105 = V_22 -> V_53 ;
}
}
if ( V_22 -> V_55 < V_22 -> V_56 ) {
if ( V_22 -> V_37 & V_76 ) {
V_22 -> V_104 = F_97 () %
( V_22 -> V_56 - V_22 -> V_55 )
+ V_22 -> V_55 ;
} else {
V_22 -> V_104 ++ ;
if ( V_22 -> V_104 >= V_22 -> V_56 )
V_22 -> V_104 = V_22 -> V_55 ;
}
}
if ( ! ( V_22 -> V_37 & V_38 ) ) {
V_232 = F_17 ( V_22 -> V_143 ) ;
V_233 = F_17 ( V_22 -> V_144 ) ;
if ( V_232 < V_233 ) {
T_7 V_150 ;
if ( V_22 -> V_37 & V_72 )
V_150 = F_97 () % ( V_233 - V_232 ) + V_232 ;
else {
V_150 = F_17 ( V_22 -> V_102 ) ;
V_150 ++ ;
if ( V_150 > V_233 )
V_150 = V_232 ;
}
V_22 -> V_102 = F_29 ( V_150 ) ;
}
if ( V_22 -> V_32 && F_95 ( V_22 , V_219 ) ) {
V_22 -> V_103 = V_22 -> V_220 [ V_219 ] . V_103 ;
} else {
V_232 = F_17 ( V_22 -> V_140 ) ;
V_233 = F_17 ( V_22 -> V_141 ) ;
if ( V_232 < V_233 ) {
T_7 V_150 ;
V_236 V_237 ;
if ( V_22 -> V_37 & V_73 ) {
do {
V_150 = F_97 () %
( V_233 - V_232 ) + V_232 ;
V_237 = F_29 ( V_150 ) ;
} while ( F_104 ( V_237 ) ||
F_105 ( V_237 ) ||
F_106 ( V_237 ) ||
F_107 ( V_237 ) ||
F_108 ( V_237 ) );
V_22 -> V_103 = V_237 ;
} else {
V_150 = F_17 ( V_22 -> V_103 ) ;
V_150 ++ ;
if ( V_150 > V_233 ) {
V_150 = V_232 ;
}
V_22 -> V_103 = F_29 ( V_150 ) ;
}
}
if ( V_22 -> V_32 ) {
V_22 -> V_220 [ V_219 ] . V_37 |= V_221 ;
V_22 -> V_220 [ V_219 ] . V_103 =
V_22 -> V_103 ;
#ifdef F_18
if ( V_22 -> V_37 & V_83 )
F_98 ( V_22 , V_219 ) ;
#endif
V_22 -> V_107 ++ ;
}
}
} else {
if ( ! F_109 ( & V_22 -> V_43 ) ) {
int V_60 ;
for ( V_60 = 0 ; V_60 < 4 ; V_60 ++ ) {
V_22 -> V_101 . V_238 [ V_60 ] =
( ( ( V_235 V_236 ) F_97 () |
V_22 -> V_43 . V_238 [ V_60 ] ) &
V_22 -> V_44 . V_238 [ V_60 ] ) ;
}
}
}
if ( V_22 -> V_26 < V_22 -> V_27 ) {
T_7 V_150 ;
if ( V_22 -> V_37 & V_74 ) {
V_150 = F_97 () %
( V_22 -> V_27 - V_22 -> V_26 )
+ V_22 -> V_26 ;
} else {
V_150 = V_22 -> V_132 + 1 ;
if ( V_150 > V_22 -> V_27 )
V_150 = V_22 -> V_26 ;
}
V_22 -> V_132 = V_150 ;
}
F_101 ( V_22 ) ;
V_22 -> V_220 [ V_219 ] . V_7 ++ ;
}
static int F_110 ( struct V_239 * V_240 , struct V_21 * V_22 )
{
struct V_223 * V_224 = V_22 -> V_220 [ V_22 -> V_222 ] . V_224 ;
int V_180 = 0 ;
struct V_179 * V_179 = F_64 ( V_22 -> V_50 ) ;
if ( ! V_224 )
return 0 ;
if ( ( V_224 -> V_230 . V_241 != V_242 ) && ( V_22 -> V_84 == 0 ) )
return 0 ;
if ( ( V_224 -> V_230 . V_241 == V_243 ) && ( V_22 -> V_84 != 0 ) )
V_240 -> V_244 = ( unsigned long ) & V_22 -> V_245 | V_246 ;
F_111 () ;
V_180 = V_224 -> V_247 -> V_248 ( V_224 , V_240 ) ;
F_112 () ;
if ( V_180 ) {
F_113 ( V_179 , V_249 ) ;
goto error;
}
V_180 = V_224 -> type -> V_248 ( V_224 , V_240 ) ;
if ( V_180 ) {
F_113 ( V_179 , V_250 ) ;
goto error;
}
F_114 ( & V_224 -> V_196 ) ;
V_224 -> V_251 . V_252 += V_240 -> V_118 ;
V_224 -> V_251 . V_253 ++ ;
F_115 ( & V_224 -> V_196 ) ;
error:
return V_180 ;
}
static void F_116 ( struct V_21 * V_22 )
{
if ( V_22 -> V_32 ) {
int V_60 ;
for ( V_60 = 0 ; V_60 < V_22 -> V_32 ; V_60 ++ ) {
struct V_223 * V_224 = V_22 -> V_220 [ V_60 ] . V_224 ;
if ( V_224 ) {
F_117 ( V_224 ) ;
V_22 -> V_220 [ V_60 ] . V_224 = NULL ;
}
}
}
}
static int F_118 ( struct V_21 * V_22 ,
struct V_239 * V_240 , T_10 V_254 )
{
if ( V_22 -> V_37 & V_83 ) {
struct V_223 * V_224 = V_22 -> V_220 [ V_22 -> V_222 ] . V_224 ;
int V_255 = 0 ;
if ( V_224 ) {
int V_151 ;
T_11 * V_256 ;
struct V_201 * V_257 ;
V_255 = V_224 -> V_230 . V_231 - F_119 ( V_240 ) ;
if ( V_255 > 0 ) {
V_151 = F_120 ( V_240 , V_255 , 0 , V_258 ) ;
if ( V_151 < 0 ) {
F_48 ( L_246 ,
V_151 ) ;
goto V_180;
}
}
F_121 ( V_240 , V_259 ) ;
V_151 = F_110 ( V_240 , V_22 ) ;
if ( V_151 ) {
F_48 ( L_247 , V_151 ) ;
goto V_180;
}
V_256 = ( T_11 * ) F_122 ( V_240 , V_259 ) ;
memcpy ( V_256 , V_22 -> V_145 , 12 ) ;
* ( V_260 * ) & V_256 [ 12 ] = V_254 ;
V_257 = F_123 ( V_240 ) ;
V_257 -> V_261 = F_124 ( V_240 -> V_118 - V_259 ) ;
F_125 ( V_257 ) ;
}
}
return 1 ;
V_180:
F_126 ( V_240 ) ;
return 0 ;
}
static void F_127 ( V_236 * V_262 , struct V_21 * V_22 )
{
unsigned int V_60 ;
for ( V_60 = 0 ; V_60 < V_22 -> V_59 ; V_60 ++ )
* V_262 ++ = V_22 -> V_61 [ V_60 ] & ~ V_120 ;
V_262 -- ;
* V_262 |= V_120 ;
}
static inline T_10 F_128 ( unsigned int V_263 , unsigned int V_264 ,
unsigned int V_265 )
{
return F_124 ( V_263 | ( V_264 << 12 ) | ( V_265 << 13 ) ) ;
}
static void F_129 ( struct V_21 * V_22 , struct V_239 * V_240 ,
int V_266 )
{
struct V_267 V_268 ;
struct V_191 * V_269 ;
V_269 = (struct V_191 * ) F_130 ( V_240 , sizeof( * V_269 ) ) ;
V_266 -= sizeof( * V_269 ) ;
if ( V_22 -> V_28 <= 0 ) {
memset ( F_130 ( V_240 , V_266 ) , 0 , V_266 ) ;
} else {
int V_270 = V_22 -> V_28 ;
int V_60 , V_118 ;
int V_271 ;
if ( V_270 > V_272 )
V_270 = V_272 ;
V_118 = V_266 - V_270 * V_273 ;
if ( V_118 > 0 ) {
memset ( F_130 ( V_240 , V_118 ) , 0 , V_118 ) ;
V_266 = V_270 * V_273 ;
}
V_60 = 0 ;
V_271 = ( V_266 / V_270 ) < V_273 ?
( V_266 / V_270 ) : V_273 ;
while ( V_266 > 0 ) {
if ( F_131 ( ! V_22 -> V_138 ) ) {
int V_71 = F_132 () ;
if ( V_22 -> V_71 >= 0 && ( V_22 -> V_37 & V_89 ) )
V_71 = V_22 -> V_71 ;
V_22 -> V_138 = F_133 ( V_71 , V_274 | V_275 , 0 ) ;
if ( ! V_22 -> V_138 )
break;
}
F_134 ( V_22 -> V_138 ) ;
F_135 ( V_240 , V_60 , V_22 -> V_138 ) ;
F_136 ( V_240 ) -> V_270 [ V_60 ] . V_276 = 0 ;
if ( V_60 == ( V_270 - 1 ) )
F_137 ( & F_136 ( V_240 ) -> V_270 [ V_60 ] ,
( V_266 < V_273 ? V_266 : V_273 ) ) ;
else
F_137 ( & F_136 ( V_240 ) -> V_270 [ V_60 ] , V_271 ) ;
V_266 -= F_138 ( & F_136 ( V_240 ) -> V_270 [ V_60 ] ) ;
V_240 -> V_118 += F_138 ( & F_136 ( V_240 ) -> V_270 [ V_60 ] ) ;
V_240 -> V_277 += F_138 ( & F_136 ( V_240 ) -> V_270 [ V_60 ] ) ;
V_60 ++ ;
F_136 ( V_240 ) -> V_278 = V_60 ;
}
}
V_269 -> V_279 = F_29 ( V_280 ) ;
V_269 -> V_97 = F_29 ( V_22 -> V_97 ) ;
if ( V_22 -> V_37 & V_78 ) {
V_269 -> V_281 = 0 ;
V_269 -> V_282 = 0 ;
} else {
F_139 ( & V_268 ) ;
V_269 -> V_281 = F_29 ( V_268 . V_281 ) ;
V_269 -> V_282 = F_29 ( V_268 . V_282 ) ;
}
}
static struct V_239 * F_140 ( struct V_164 * V_165 ,
struct V_21 * V_22 ,
unsigned int V_283 )
{
struct V_239 * V_240 = NULL ;
unsigned int V_284 = V_22 -> V_132 + 64 + V_283 +
V_22 -> V_192 ;
if ( V_22 -> V_37 & V_89 ) {
int V_71 = V_22 -> V_71 >= 0 ? V_22 -> V_71 : F_132 () ;
V_240 = F_141 ( V_285 + V_284 , V_286 , 0 , V_71 ) ;
if ( F_86 ( V_240 ) ) {
F_142 ( V_240 , V_285 ) ;
V_240 -> V_165 = V_165 ;
}
} else {
V_240 = F_143 ( V_165 , V_284 , V_286 ) ;
}
return V_240 ;
}
static struct V_239 * F_144 ( struct V_164 * V_50 ,
struct V_21 * V_22 )
{
struct V_239 * V_240 = NULL ;
T_11 * V_256 ;
struct V_190 * V_287 ;
int V_266 , V_288 ;
struct V_201 * V_257 ;
T_10 V_254 = F_124 ( V_289 ) ;
V_236 * V_262 ;
T_10 * V_290 = NULL ;
T_10 * V_291 = NULL ;
T_10 * V_292 = NULL ;
T_10 * V_293 = NULL ;
V_260 V_294 ;
if ( V_22 -> V_59 )
V_254 = F_124 ( V_295 ) ;
if ( V_22 -> V_62 != 0xffff )
V_254 = F_124 ( V_296 ) ;
F_103 ( V_22 ) ;
V_294 = V_22 -> V_106 ;
V_266 = ( V_50 -> V_297 + 16 ) & ~ 0xf ;
V_240 = F_140 ( V_50 , V_22 , V_266 ) ;
if ( ! V_240 ) {
sprintf ( V_22 -> V_108 , L_248 ) ;
return NULL ;
}
F_145 ( V_240 -> V_9 ) ;
F_142 ( V_240 , V_266 ) ;
V_256 = ( T_11 * ) F_122 ( V_240 , 14 ) ;
V_262 = ( V_236 * ) F_130 ( V_240 , V_22 -> V_59 * sizeof( T_7 ) ) ;
if ( V_22 -> V_59 )
F_127 ( V_262 , V_22 ) ;
if ( V_22 -> V_62 != 0xffff ) {
if ( V_22 -> V_65 != 0xffff ) {
V_292 = ( T_10 * ) F_130 ( V_240 , sizeof( T_10 ) ) ;
* V_292 = F_128 ( V_22 -> V_65 ,
V_22 -> V_67 ,
V_22 -> V_66 ) ;
V_293 = ( T_10 * ) F_130 ( V_240 , sizeof( T_10 ) ) ;
* V_293 = F_124 ( V_296 ) ;
}
V_290 = ( T_10 * ) F_130 ( V_240 , sizeof( T_10 ) ) ;
* V_290 = F_128 ( V_22 -> V_62 ,
V_22 -> V_64 ,
V_22 -> V_63 ) ;
V_291 = ( T_10 * ) F_130 ( V_240 , sizeof( T_10 ) ) ;
* V_291 = F_124 ( V_289 ) ;
}
F_146 ( V_240 , 0 ) ;
F_147 ( V_240 , V_240 -> V_118 ) ;
V_257 = (struct V_201 * ) F_130 ( V_240 , sizeof( struct V_201 ) ) ;
F_148 ( V_240 , V_240 -> V_118 ) ;
V_287 = (struct V_190 * ) F_130 ( V_240 , sizeof( struct V_190 ) ) ;
F_149 ( V_240 , V_294 ) ;
V_240 -> V_298 = V_22 -> V_36 ;
memcpy ( V_256 , V_22 -> V_145 , 12 ) ;
* ( T_10 * ) & V_256 [ 12 ] = V_254 ;
V_266 = V_22 -> V_132 - 14 - 20 - 8 -
V_22 -> V_192 ;
if ( V_266 < 0 || V_266 < sizeof( struct V_191 ) )
V_266 = sizeof( struct V_191 ) ;
V_287 -> V_299 = F_124 ( V_22 -> V_105 ) ;
V_287 -> V_300 = F_124 ( V_22 -> V_104 ) ;
V_287 -> V_118 = F_124 ( V_266 + 8 ) ;
V_287 -> V_301 = 0 ;
V_257 -> V_302 = 5 ;
V_257 -> V_4 = 4 ;
V_257 -> V_303 = 32 ;
V_257 -> V_68 = V_22 -> V_68 ;
V_257 -> V_254 = V_304 ;
V_257 -> V_305 = V_22 -> V_102 ;
V_257 -> V_306 = V_22 -> V_103 ;
V_257 -> V_263 = F_124 ( V_22 -> V_307 ) ;
V_22 -> V_307 ++ ;
V_257 -> V_308 = 0 ;
V_288 = 20 + 8 + V_266 ;
V_257 -> V_261 = F_124 ( V_288 ) ;
F_125 ( V_257 ) ;
V_240 -> V_254 = V_254 ;
V_240 -> V_165 = V_50 ;
V_240 -> V_309 = V_310 ;
F_129 ( V_22 , V_240 , V_266 ) ;
if ( ! ( V_22 -> V_37 & V_77 ) ) {
V_240 -> V_311 = V_312 ;
} else if ( V_50 -> V_313 & V_314 ) {
V_240 -> V_311 = V_315 ;
V_240 -> V_316 = 0 ;
F_150 ( V_240 , V_257 -> V_305 , V_257 -> V_306 ) ;
} else {
T_12 V_316 = F_151 ( V_240 , F_152 ( V_240 ) , V_266 + 8 , 0 ) ;
V_287 -> V_301 = F_153 ( V_257 -> V_305 , V_257 -> V_306 ,
V_266 + 8 , V_304 , V_316 ) ;
if ( V_287 -> V_301 == 0 )
V_287 -> V_301 = V_317 ;
}
#ifdef F_18
if ( ! F_118 ( V_22 , V_240 , V_254 ) )
return NULL ;
#endif
return V_240 ;
}
static struct V_239 * F_154 ( struct V_164 * V_50 ,
struct V_21 * V_22 )
{
struct V_239 * V_240 = NULL ;
T_11 * V_256 ;
struct V_190 * V_287 ;
int V_266 , V_318 ;
struct V_189 * V_257 ;
T_10 V_254 = F_124 ( V_319 ) ;
V_236 * V_262 ;
T_10 * V_290 = NULL ;
T_10 * V_291 = NULL ;
T_10 * V_292 = NULL ;
T_10 * V_293 = NULL ;
V_260 V_294 ;
if ( V_22 -> V_59 )
V_254 = F_124 ( V_295 ) ;
if ( V_22 -> V_62 != 0xffff )
V_254 = F_124 ( V_296 ) ;
F_103 ( V_22 ) ;
V_294 = V_22 -> V_106 ;
V_240 = F_140 ( V_50 , V_22 , 16 ) ;
if ( ! V_240 ) {
sprintf ( V_22 -> V_108 , L_248 ) ;
return NULL ;
}
F_145 ( V_240 -> V_9 ) ;
F_142 ( V_240 , 16 ) ;
V_256 = ( T_11 * ) F_122 ( V_240 , 14 ) ;
V_262 = ( V_236 * ) F_130 ( V_240 , V_22 -> V_59 * sizeof( T_7 ) ) ;
if ( V_22 -> V_59 )
F_127 ( V_262 , V_22 ) ;
if ( V_22 -> V_62 != 0xffff ) {
if ( V_22 -> V_65 != 0xffff ) {
V_292 = ( T_10 * ) F_130 ( V_240 , sizeof( T_10 ) ) ;
* V_292 = F_128 ( V_22 -> V_65 ,
V_22 -> V_67 ,
V_22 -> V_66 ) ;
V_293 = ( T_10 * ) F_130 ( V_240 , sizeof( T_10 ) ) ;
* V_293 = F_124 ( V_296 ) ;
}
V_290 = ( T_10 * ) F_130 ( V_240 , sizeof( T_10 ) ) ;
* V_290 = F_128 ( V_22 -> V_62 ,
V_22 -> V_64 ,
V_22 -> V_63 ) ;
V_291 = ( T_10 * ) F_130 ( V_240 , sizeof( T_10 ) ) ;
* V_291 = F_124 ( V_319 ) ;
}
F_146 ( V_240 , 0 ) ;
F_147 ( V_240 , V_240 -> V_118 ) ;
V_257 = (struct V_189 * ) F_130 ( V_240 , sizeof( struct V_189 ) ) ;
F_148 ( V_240 , V_240 -> V_118 ) ;
V_287 = (struct V_190 * ) F_130 ( V_240 , sizeof( struct V_190 ) ) ;
F_149 ( V_240 , V_294 ) ;
V_240 -> V_298 = V_22 -> V_36 ;
memcpy ( V_256 , V_22 -> V_145 , 12 ) ;
* ( T_10 * ) & V_256 [ 12 ] = V_254 ;
V_266 = V_22 -> V_132 - 14 -
sizeof( struct V_189 ) - sizeof( struct V_190 ) -
V_22 -> V_192 ;
if ( V_266 < 0 || V_266 < sizeof( struct V_191 ) ) {
V_266 = sizeof( struct V_191 ) ;
F_155 ( L_249 , V_266 ) ;
}
V_318 = V_266 + sizeof( struct V_190 ) ;
V_287 -> V_299 = F_124 ( V_22 -> V_105 ) ;
V_287 -> V_300 = F_124 ( V_22 -> V_104 ) ;
V_287 -> V_118 = F_124 ( V_318 ) ;
V_287 -> V_301 = 0 ;
* ( V_236 * ) V_257 = F_29 ( 0x60000000 ) ;
if ( V_22 -> V_69 ) {
* ( V_236 * ) V_257 |= F_29 ( 0x60000000 | ( V_22 -> V_69 << 20 ) ) ;
}
V_257 -> V_320 = 32 ;
V_257 -> V_321 = F_124 ( V_318 ) ;
V_257 -> V_322 = V_304 ;
V_257 -> V_306 = V_22 -> V_101 ;
V_257 -> V_305 = V_22 -> V_100 ;
V_240 -> V_254 = V_254 ;
V_240 -> V_165 = V_50 ;
V_240 -> V_309 = V_310 ;
F_129 ( V_22 , V_240 , V_266 ) ;
if ( ! ( V_22 -> V_37 & V_77 ) ) {
V_240 -> V_311 = V_312 ;
} else if ( V_50 -> V_313 & V_323 ) {
V_240 -> V_311 = V_315 ;
V_240 -> V_324 = F_156 ( V_240 ) - V_240 -> V_325 ;
V_240 -> V_326 = F_157 ( struct V_190 , V_301 ) ;
V_287 -> V_301 = ~ F_158 ( & V_257 -> V_305 , & V_257 -> V_306 , V_318 , V_304 , 0 ) ;
} else {
T_12 V_316 = F_151 ( V_240 , F_152 ( V_240 ) , V_318 , 0 ) ;
V_287 -> V_301 = F_158 ( & V_257 -> V_305 , & V_257 -> V_306 , V_318 , V_304 , V_316 ) ;
if ( V_287 -> V_301 == 0 )
V_287 -> V_301 = V_317 ;
}
return V_240 ;
}
static struct V_239 * F_159 ( struct V_164 * V_50 ,
struct V_21 * V_22 )
{
if ( V_22 -> V_37 & V_38 )
return F_154 ( V_50 , V_22 ) ;
else
return F_144 ( V_50 , V_22 ) ;
}
static void F_40 ( struct V_21 * V_22 )
{
V_22 -> V_97 = 1 ;
V_22 -> V_92 = 0 ;
V_22 -> V_94 = 0 ;
V_22 -> V_327 = 0 ;
V_22 -> V_95 = 0 ;
}
static void F_160 ( struct V_149 * V_150 )
{
struct V_21 * V_22 ;
int V_328 = 0 ;
F_161 () ;
F_44 () ;
F_45 (pkt_dev, &t->if_list, list) {
F_70 ( V_22 ) ;
if ( V_22 -> V_50 ) {
F_40 ( V_22 ) ;
V_22 -> V_240 = NULL ;
V_22 -> V_96 = V_22 -> V_214 = F_19 () ;
F_92 ( V_22 ) ;
strcpy ( V_22 -> V_108 , L_250 ) ;
V_22 -> V_90 = 1 ;
V_328 ++ ;
} else
strcpy ( V_22 -> V_108 , L_251 ) ;
}
F_46 () ;
if ( V_328 )
V_150 -> V_154 &= ~ ( V_329 ) ;
}
static void F_7 ( struct V_10 * V_11 )
{
struct V_149 * V_150 ;
F_161 () ;
F_49 ( & V_153 ) ;
F_56 (t, &pn->pktgen_threads, th_list)
V_150 -> V_154 |= V_329 ;
F_51 ( & V_153 ) ;
}
static int F_162 ( const struct V_149 * V_150 )
{
const struct V_21 * V_22 ;
F_44 () ;
F_45 (pkt_dev, &t->if_list, list)
if ( V_22 -> V_90 ) {
F_46 () ;
return 1 ;
}
F_46 () ;
return 0 ;
}
static int F_163 ( struct V_149 * V_150 )
{
while ( F_162 ( V_150 ) ) {
F_164 ( 100 ) ;
if ( F_89 ( V_12 ) )
goto signal;
}
return 1 ;
signal:
return 0 ;
}
static int F_165 ( struct V_10 * V_11 )
{
struct V_149 * V_150 ;
int V_330 = 1 ;
F_49 ( & V_153 ) ;
F_56 (t, &pn->pktgen_threads, th_list) {
V_330 = F_163 ( V_150 ) ;
if ( V_330 == 0 )
break;
}
if ( V_330 == 0 )
F_56 (t, &pn->pktgen_threads, th_list)
V_150 -> V_154 |= ( V_329 ) ;
F_51 ( & V_153 ) ;
return V_330 ;
}
static void F_8 ( struct V_10 * V_11 )
{
struct V_149 * V_150 ;
F_161 () ;
F_49 ( & V_153 ) ;
F_56 (t, &pn->pktgen_threads, th_list)
V_150 -> V_154 |= ( V_331 ) ;
F_51 ( & V_153 ) ;
F_52 ( F_53 ( 125 ) ) ;
F_165 ( V_11 ) ;
}
static void F_9 ( struct V_10 * V_11 )
{
struct V_149 * V_150 ;
F_161 () ;
F_49 ( & V_153 ) ;
F_56 (t, &pn->pktgen_threads, th_list)
V_150 -> V_154 |= ( V_155 ) ;
F_51 ( & V_153 ) ;
F_52 ( F_53 ( 125 ) ) ;
F_165 ( V_11 ) ;
}
static void F_166 ( struct V_21 * V_22 , int V_278 )
{
T_13 V_332 , V_333 , V_334 ;
char * V_335 = V_22 -> V_108 ;
T_5 V_336 = F_91 ( V_22 -> V_91 ,
V_22 -> V_96 ) ;
T_5 V_25 = F_167 ( V_22 -> V_92 ) ;
V_335 += sprintf ( V_335 , L_252 ,
( unsigned long long ) F_21 ( V_336 ) ,
( unsigned long long ) F_21 ( F_91 ( V_336 , V_25 ) ) ,
( unsigned long long ) F_21 ( V_25 ) ,
( unsigned long long ) V_22 -> V_94 ,
V_22 -> V_132 , V_278 ) ;
V_334 = F_168 ( V_22 -> V_94 * V_134 ,
F_78 ( V_336 ) ) ;
V_332 = V_334 * 8 * V_22 -> V_132 ;
V_333 = V_332 ;
F_20 ( V_333 , 1000000 ) ;
V_335 += sprintf ( V_335 , L_253 ,
( unsigned long long ) V_334 ,
( unsigned long long ) V_333 ,
( unsigned long long ) V_332 ,
( unsigned long long ) V_22 -> V_95 ) ;
}
static int F_169 ( struct V_21 * V_22 )
{
int V_278 = V_22 -> V_240 ? F_136 ( V_22 -> V_240 ) -> V_278 : - 1 ;
if ( ! V_22 -> V_90 ) {
F_10 ( L_254 ,
V_22 -> V_31 ) ;
return - V_18 ;
}
V_22 -> V_90 = 0 ;
F_126 ( V_22 -> V_240 ) ;
V_22 -> V_240 = NULL ;
V_22 -> V_91 = F_19 () ;
F_166 ( V_22 , V_278 ) ;
return 0 ;
}
static struct V_21 * F_170 ( struct V_149 * V_150 )
{
struct V_21 * V_22 , * V_337 = NULL ;
F_44 () ;
F_45 (pkt_dev, &t->if_list, list) {
if ( ! V_22 -> V_90 )
continue;
if ( V_337 == NULL )
V_337 = V_22 ;
else if ( F_81 ( V_22 -> V_214 , V_337 -> V_214 ) < 0 )
V_337 = V_22 ;
}
F_46 () ;
return V_337 ;
}
static void F_171 ( struct V_149 * V_150 )
{
struct V_21 * V_22 ;
F_161 () ;
F_44 () ;
F_45 (pkt_dev, &t->if_list, list) {
F_169 ( V_22 ) ;
}
F_46 () ;
}
static void F_172 ( struct V_149 * V_150 )
{
struct V_338 * V_339 , * V_117 ;
struct V_21 * V_340 ;
F_161 () ;
F_173 (q, n, &t->if_list) {
V_340 = F_174 ( V_339 , struct V_21 , V_341 ) ;
if ( ! V_340 -> V_159 )
continue;
F_126 ( V_340 -> V_240 ) ;
V_340 -> V_240 = NULL ;
F_175 ( V_150 , V_340 ) ;
break;
}
}
static void F_176 ( struct V_149 * V_150 )
{
struct V_338 * V_339 , * V_117 ;
struct V_21 * V_340 ;
F_161 () ;
F_173 (q, n, &t->if_list) {
V_340 = F_174 ( V_339 , struct V_21 , V_341 ) ;
F_126 ( V_340 -> V_240 ) ;
V_340 -> V_240 = NULL ;
F_175 ( V_150 , V_340 ) ;
}
}
static void F_177 ( struct V_149 * V_150 )
{
F_178 ( V_150 -> V_342 -> V_343 , V_150 -> V_179 -> V_167 ) ;
}
static void F_179 ( struct V_21 * V_22 )
{
T_5 V_344 = F_19 () ;
F_87 () ;
V_22 -> V_92 += F_78 ( F_91 ( F_19 () , V_344 ) ) ;
}
static void F_180 ( struct V_21 * V_22 )
{
T_5 V_344 = F_19 () ;
while ( F_181 ( & ( V_22 -> V_240 -> V_345 ) ) != 1 ) {
if ( F_89 ( V_12 ) )
break;
if ( F_182 () )
F_179 ( V_22 ) ;
else
F_183 () ;
}
V_22 -> V_92 += F_78 ( F_91 ( F_19 () , V_344 ) ) ;
}
static void F_184 ( struct V_21 * V_22 )
{
unsigned int V_70 = F_185 ( V_22 -> V_70 ) ;
struct V_164 * V_50 = V_22 -> V_50 ;
struct V_346 * V_347 ;
int V_151 ;
if ( F_131 ( ! F_69 ( V_50 ) || ! F_186 ( V_50 ) ) ) {
F_169 ( V_22 ) ;
return;
}
if ( F_131 ( V_22 -> V_29 == V_133 ) ) {
V_22 -> V_214 = F_80 ( F_19 () , V_348 ) ;
return;
}
if ( ! V_22 -> V_240 || ( V_22 -> V_349 &&
++ V_22 -> V_350 >= V_22 -> V_30 ) ) {
F_126 ( V_22 -> V_240 ) ;
V_22 -> V_240 = F_159 ( V_50 , V_22 ) ;
if ( V_22 -> V_240 == NULL ) {
F_48 ( L_255 ) ;
F_87 () ;
V_22 -> V_350 -- ;
return;
}
V_22 -> V_351 = V_22 -> V_240 -> V_118 ;
V_22 -> V_352 ++ ;
V_22 -> V_350 = 0 ;
}
if ( V_22 -> V_29 && V_22 -> V_349 )
F_75 ( V_22 , V_22 -> V_214 ) ;
V_347 = F_187 ( V_50 , V_22 -> V_240 ) ;
F_188 () ;
F_189 ( V_50 , V_347 , F_102 () ) ;
if ( F_131 ( F_190 ( V_347 ) ) ) {
V_151 = V_353 ;
V_22 -> V_349 = 0 ;
goto V_354;
}
F_191 ( V_70 , & V_22 -> V_240 -> V_345 ) ;
V_355:
V_151 = F_192 ( V_22 -> V_240 , V_50 , V_347 , -- V_70 > 0 ) ;
switch ( V_151 ) {
case V_356 :
V_22 -> V_349 = 1 ;
V_22 -> V_94 ++ ;
V_22 -> V_97 ++ ;
V_22 -> V_327 += V_22 -> V_351 ;
if ( V_70 > 0 && ! F_190 ( V_347 ) )
goto V_355;
break;
case V_357 :
case V_358 :
case V_359 :
V_22 -> V_95 ++ ;
break;
default:
F_155 ( L_256 ,
V_22 -> V_31 , V_151 ) ;
V_22 -> V_95 ++ ;
case V_360 :
case V_353 :
F_193 ( & ( V_22 -> V_240 -> V_345 ) ) ;
V_22 -> V_349 = 0 ;
}
if ( F_131 ( V_70 ) )
F_194 ( V_70 , & V_22 -> V_240 -> V_345 ) ;
V_354:
F_195 ( V_50 , V_347 ) ;
F_196 () ;
if ( ( V_22 -> V_7 != 0 ) && ( V_22 -> V_94 >= V_22 -> V_7 ) ) {
F_180 ( V_22 ) ;
F_169 ( V_22 ) ;
}
}
static int F_197 ( void * V_361 )
{
F_198 ( V_362 ) ;
struct V_149 * V_150 = V_361 ;
struct V_21 * V_22 = NULL ;
int V_363 = V_150 -> V_363 ;
F_43 ( F_102 () != V_363 ) ;
F_199 ( & V_150 -> V_364 ) ;
F_200 ( & V_150 -> V_365 ) ;
F_32 ( L_257 , V_363 , F_201 ( V_12 ) ) ;
F_202 () ;
F_90 ( V_217 ) ;
while ( ! F_203 () ) {
V_22 = F_170 ( V_150 ) ;
if ( F_131 ( ! V_22 && V_150 -> V_154 == 0 ) ) {
if ( V_150 -> V_179 -> V_173 )
break;
F_204 ( V_150 -> V_364 ,
V_150 -> V_154 != 0 ,
V_366 / 10 ) ;
F_205 () ;
continue;
}
if ( F_86 ( V_22 ) ) {
F_184 ( V_22 ) ;
if ( F_182 () )
F_179 ( V_22 ) ;
else
F_183 () ;
}
if ( V_150 -> V_154 & V_329 ) {
F_171 ( V_150 ) ;
V_150 -> V_154 &= ~ ( V_329 ) ;
}
if ( V_150 -> V_154 & V_331 ) {
F_160 ( V_150 ) ;
V_150 -> V_154 &= ~ ( V_331 ) ;
}
if ( V_150 -> V_154 & V_155 ) {
F_176 ( V_150 ) ;
V_150 -> V_154 &= ~ ( V_155 ) ;
}
if ( V_150 -> V_154 & V_160 ) {
F_172 ( V_150 ) ;
V_150 -> V_154 &= ~ ( V_160 ) ;
}
F_205 () ;
}
F_83 ( V_215 ) ;
F_32 ( L_258 , V_150 -> V_342 -> V_343 ) ;
F_171 ( V_150 ) ;
F_32 ( L_259 , V_150 -> V_342 -> V_343 ) ;
F_176 ( V_150 ) ;
F_32 ( L_260 , V_150 -> V_342 -> V_343 ) ;
F_177 ( V_150 ) ;
while ( ! F_203 () ) {
F_83 ( V_215 ) ;
F_87 () ;
}
F_90 ( V_217 ) ;
return 0 ;
}
static struct V_21 * F_57 ( struct V_149 * V_150 ,
const char * V_156 , bool V_157 )
{
struct V_21 * V_335 , * V_22 = NULL ;
T_3 V_118 = strlen ( V_156 ) ;
F_44 () ;
F_45 (p, &t->if_list, list)
if ( strncmp ( V_335 -> V_31 , V_156 , V_118 ) == 0 ) {
if ( V_335 -> V_31 [ V_118 ] ) {
if ( V_157 || V_335 -> V_31 [ V_118 ] != '@' )
continue;
}
V_22 = V_335 ;
break;
}
F_46 () ;
F_32 ( L_261 , V_156 , V_22 ) ;
return V_22 ;
}
static int F_206 ( struct V_149 * V_150 ,
struct V_21 * V_22 )
{
int V_367 = 0 ;
F_207 ( V_150 ) ;
if ( V_22 -> V_368 ) {
F_48 ( L_262 ) ;
V_367 = - V_369 ;
goto V_152;
}
V_22 -> V_90 = 0 ;
V_22 -> V_368 = V_150 ;
F_208 ( & V_22 -> V_341 , & V_150 -> V_370 ) ;
V_152:
F_209 ( V_150 ) ;
return V_367 ;
}
static int F_50 ( struct V_149 * V_150 , const char * V_156 )
{
struct V_21 * V_22 ;
int V_180 ;
int V_71 = F_210 ( V_150 -> V_363 ) ;
V_22 = F_55 ( V_150 -> V_179 , V_156 , V_158 ) ;
if ( V_22 ) {
F_48 ( L_263 ) ;
return - V_369 ;
}
V_22 = F_211 ( sizeof( struct V_21 ) , V_274 , V_71 ) ;
if ( ! V_22 )
return - V_371 ;
strcpy ( V_22 -> V_31 , V_156 ) ;
V_22 -> V_220 = F_212 ( V_146 * sizeof( struct V_372 ) ,
V_71 ) ;
if ( V_22 -> V_220 == NULL ) {
F_213 ( V_22 ) ;
return - V_371 ;
}
V_22 -> V_159 = 0 ;
V_22 -> V_28 = 0 ;
V_22 -> V_29 = V_373 ;
V_22 -> V_7 = V_374 ;
V_22 -> V_94 = 0 ;
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
V_180 = F_67 ( V_150 -> V_179 , V_22 , V_156 ) ;
if ( V_180 )
goto V_375;
if ( V_22 -> V_50 -> V_135 & V_136 )
V_22 -> V_30 = V_376 ;
V_22 -> V_166 = F_61 ( V_156 , 0600 , V_150 -> V_179 -> V_167 ,
& V_168 , V_22 ) ;
if ( ! V_22 -> V_166 ) {
F_48 ( L_264 ,
V_377 , V_156 ) ;
V_180 = - V_18 ;
goto V_378;
}
#ifdef F_18
V_22 -> V_228 = V_242 ;
V_22 -> V_229 = V_379 ;
V_22 -> V_380 . V_381 = V_225 ;
V_22 -> V_245 . V_165 = V_22 -> V_50 ;
F_214 ( & V_22 -> V_245 , V_382 , false ) ;
V_22 -> V_245 . V_383 = & V_22 -> V_245 ;
V_22 -> V_245 . V_384 = & V_22 -> V_380 ;
#endif
return F_206 ( V_150 , V_22 ) ;
V_378:
F_68 ( V_22 -> V_50 ) ;
V_375:
#ifdef F_18
F_116 ( V_22 ) ;
#endif
F_215 ( V_22 -> V_220 ) ;
F_213 ( V_22 ) ;
return V_180 ;
}
static int T_14 F_216 ( int V_363 , struct V_10 * V_11 )
{
struct V_149 * V_150 ;
struct V_385 * V_386 ;
struct V_387 * V_335 ;
V_150 = F_211 ( sizeof( struct V_149 ) , V_274 ,
F_210 ( V_363 ) ) ;
if ( ! V_150 ) {
F_48 ( L_265 ) ;
return - V_371 ;
}
F_217 ( & V_150 -> F_207 ) ;
V_150 -> V_363 = V_363 ;
F_218 ( & V_150 -> V_370 ) ;
F_219 ( & V_150 -> V_388 , & V_11 -> V_389 ) ;
F_220 ( & V_150 -> V_365 ) ;
V_335 = F_221 ( F_197 ,
V_150 ,
F_210 ( V_363 ) ,
L_266 , V_363 ) ;
if ( F_222 ( V_335 ) ) {
F_48 ( L_267 , V_150 -> V_363 ) ;
F_223 ( & V_150 -> V_388 ) ;
F_213 ( V_150 ) ;
return F_224 ( V_335 ) ;
}
F_225 ( V_335 , V_363 ) ;
V_150 -> V_342 = V_335 ;
V_386 = F_61 ( V_150 -> V_342 -> V_343 , 0600 , V_11 -> V_167 ,
& V_390 , V_150 ) ;
if ( ! V_386 ) {
F_48 ( L_264 ,
V_377 , V_150 -> V_342 -> V_343 ) ;
F_226 ( V_335 ) ;
F_223 ( & V_150 -> V_388 ) ;
F_213 ( V_150 ) ;
return - V_18 ;
}
V_150 -> V_179 = V_11 ;
F_227 ( V_335 ) ;
F_228 ( & V_150 -> V_365 ) ;
return 0 ;
}
static void F_229 ( struct V_149 * V_150 ,
struct V_21 * V_22 )
{
struct V_338 * V_339 , * V_117 ;
struct V_21 * V_335 ;
F_207 ( V_150 ) ;
F_173 (q, n, &t->if_list) {
V_335 = F_174 ( V_339 , struct V_21 , V_341 ) ;
if ( V_335 == V_22 )
F_230 ( & V_335 -> V_341 ) ;
}
F_209 ( V_150 ) ;
}
static int F_175 ( struct V_149 * V_150 ,
struct V_21 * V_22 )
{
F_32 ( L_268 , V_22 ) ;
if ( V_22 -> V_90 ) {
F_10 ( L_269 ) ;
F_169 ( V_22 ) ;
}
if ( V_22 -> V_50 ) {
F_68 ( V_22 -> V_50 ) ;
V_22 -> V_50 = NULL ;
}
F_60 ( V_22 -> V_166 ) ;
F_229 ( V_150 , V_22 ) ;
#ifdef F_18
F_116 ( V_22 ) ;
#endif
F_215 ( V_22 -> V_220 ) ;
if ( V_22 -> V_138 )
F_35 ( V_22 -> V_138 ) ;
F_231 ( V_22 , V_391 ) ;
return 0 ;
}
static int T_14 F_232 ( struct V_179 * V_179 )
{
struct V_10 * V_11 = F_4 ( V_179 , V_15 ) ;
struct V_385 * V_386 ;
int V_363 , V_151 = 0 ;
V_11 -> V_179 = V_179 ;
F_218 ( & V_11 -> V_389 ) ;
V_11 -> V_173 = false ;
V_11 -> V_167 = F_233 ( V_377 , V_11 -> V_179 -> V_392 ) ;
if ( ! V_11 -> V_167 ) {
F_10 ( L_270 , V_377 ) ;
return - V_181 ;
}
V_386 = F_234 ( V_393 , 0600 , V_11 -> V_167 , & V_394 ) ;
if ( V_386 == NULL ) {
F_48 ( L_271 , V_393 ) ;
V_151 = - V_18 ;
goto remove;
}
F_235 (cpu) {
int V_180 ;
V_180 = F_216 ( V_363 , V_11 ) ;
if ( V_180 )
F_10 ( L_272 ,
V_363 , V_180 ) ;
}
if ( F_236 ( & V_11 -> V_389 ) ) {
F_48 ( L_273 ) ;
V_151 = - V_181 ;
goto V_395;
}
return 0 ;
V_395:
F_178 ( V_393 , V_11 -> V_167 ) ;
remove:
F_178 ( V_377 , V_11 -> V_179 -> V_392 ) ;
return V_151 ;
}
static void T_15 F_237 ( struct V_179 * V_179 )
{
struct V_10 * V_11 = F_4 ( V_179 , V_15 ) ;
struct V_149 * V_150 ;
struct V_338 * V_339 , * V_117 ;
F_238 ( V_341 ) ;
V_11 -> V_173 = true ;
F_49 ( & V_153 ) ;
F_239 ( & V_11 -> V_389 , & V_341 ) ;
F_51 ( & V_153 ) ;
F_173 (q, n, &list) {
V_150 = F_174 ( V_339 , struct V_149 , V_388 ) ;
F_223 ( & V_150 -> V_388 ) ;
F_226 ( V_150 -> V_342 ) ;
F_213 ( V_150 ) ;
}
F_178 ( V_393 , V_11 -> V_167 ) ;
F_178 ( V_377 , V_11 -> V_179 -> V_392 ) ;
}
static int T_16 F_240 ( void )
{
int V_151 = 0 ;
F_33 ( L_274 , V_4 ) ;
V_151 = F_241 ( & V_396 ) ;
if ( V_151 )
return V_151 ;
V_151 = F_242 ( & V_397 ) ;
if ( V_151 )
F_243 ( & V_396 ) ;
return V_151 ;
}
static void T_17 F_244 ( void )
{
F_245 ( & V_397 ) ;
F_243 ( & V_396 ) ;
}
