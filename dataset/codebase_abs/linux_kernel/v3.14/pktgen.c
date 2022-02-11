static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
F_2 ( V_2 , V_4 ) ;
return 0 ;
}
static T_1 F_3 ( struct V_5 * V_5 , const char T_2 * V_6 ,
T_3 V_7 , T_4 * V_8 )
{
int V_9 = 0 ;
char V_10 [ 128 ] ;
struct V_11 * V_12 = F_4 ( V_13 -> V_14 -> V_15 , V_16 ) ;
if ( ! F_5 ( V_17 ) ) {
V_9 = - V_18 ;
goto V_19;
}
if ( V_7 > sizeof( V_10 ) )
V_7 = sizeof( V_10 ) ;
if ( F_6 ( V_10 , V_6 , V_7 ) ) {
V_9 = - V_20 ;
goto V_19;
}
V_10 [ V_7 - 1 ] = 0 ;
if ( ! strcmp ( V_10 , L_1 ) )
F_7 ( V_12 ) ;
else if ( ! strcmp ( V_10 , L_2 ) )
F_8 ( V_12 ) ;
else if ( ! strcmp ( V_10 , L_3 ) )
F_9 ( V_12 ) ;
else
F_10 ( L_4 , V_10 ) ;
V_9 = V_7 ;
V_19:
return V_9 ;
}
static int F_11 ( struct V_21 * V_21 , struct V_5 * V_5 )
{
return F_12 ( V_5 , F_1 , F_13 ( V_21 ) ) ;
}
static int F_14 ( struct V_1 * V_2 , void * V_3 )
{
const struct V_22 * V_23 = V_2 -> V_24 ;
T_5 V_25 ;
T_6 V_26 ;
F_15 ( V_2 ,
L_5 ,
( unsigned long long ) V_23 -> V_7 , V_23 -> V_27 ,
V_23 -> V_28 ) ;
F_15 ( V_2 ,
L_6 ,
V_23 -> V_29 , ( unsigned long long ) V_23 -> V_30 ,
V_23 -> V_31 , V_23 -> V_32 ) ;
F_15 ( V_2 , L_7 , V_23 -> V_33 ,
V_23 -> V_34 ) ;
F_15 ( V_2 ,
L_8 ,
V_23 -> V_35 ,
V_23 -> V_36 ) ;
if ( V_23 -> V_37 )
F_15 ( V_2 , L_9 ,
V_23 -> V_37 ) ;
if ( V_23 -> V_38 & V_39 ) {
F_15 ( V_2 ,
L_10
L_11 ,
& V_23 -> V_40 ,
& V_23 -> V_41 , & V_23 -> V_42 ,
& V_23 -> V_43 ,
& V_23 -> V_44 , & V_23 -> V_45 ) ;
} else {
F_15 ( V_2 ,
L_12 ,
V_23 -> V_46 , V_23 -> V_47 ) ;
F_15 ( V_2 ,
L_13 ,
V_23 -> V_48 , V_23 -> V_49 ) ;
}
F_2 ( V_2 , L_14 ) ;
F_15 ( V_2 , L_15 ,
F_16 ( V_23 -> V_50 ) ?
V_23 -> V_51 -> V_52 : V_23 -> V_50 ) ;
F_15 ( V_2 , L_16 ) ;
F_15 ( V_2 , L_17 , V_23 -> V_53 ) ;
F_15 ( V_2 ,
L_18
L_19 ,
V_23 -> V_54 , V_23 -> V_55 ,
V_23 -> V_56 , V_23 -> V_57 ) ;
F_15 ( V_2 ,
L_20 ,
V_23 -> V_58 , V_23 -> V_59 ) ;
if ( V_23 -> V_60 ) {
unsigned int V_61 ;
F_15 ( V_2 , L_21 ) ;
for ( V_61 = 0 ; V_61 < V_23 -> V_60 ; V_61 ++ )
F_15 ( V_2 , L_22 , F_17 ( V_23 -> V_62 [ V_61 ] ) ,
V_61 == V_23 -> V_60 - 1 ? L_23 : L_24 ) ;
}
if ( V_23 -> V_63 != 0xffff )
F_15 ( V_2 , L_25 ,
V_23 -> V_63 , V_23 -> V_64 ,
V_23 -> V_65 ) ;
if ( V_23 -> V_66 != 0xffff )
F_15 ( V_2 , L_26 ,
V_23 -> V_66 , V_23 -> V_67 ,
V_23 -> V_68 ) ;
if ( V_23 -> V_69 )
F_15 ( V_2 , L_27 , V_23 -> V_69 ) ;
if ( V_23 -> V_70 )
F_15 ( V_2 , L_28 , V_23 -> V_70 ) ;
if ( V_23 -> V_71 >= 0 )
F_15 ( V_2 , L_29 , V_23 -> V_71 ) ;
F_15 ( V_2 , L_30 ) ;
if ( V_23 -> V_38 & V_39 )
F_15 ( V_2 , L_31 ) ;
if ( V_23 -> V_38 & V_72 )
F_15 ( V_2 , L_32 ) ;
if ( V_23 -> V_38 & V_73 )
F_15 ( V_2 , L_33 ) ;
if ( V_23 -> V_38 & V_74 )
F_15 ( V_2 , L_34 ) ;
if ( V_23 -> V_38 & V_75 )
F_15 ( V_2 , L_35 ) ;
if ( V_23 -> V_38 & V_76 )
F_15 ( V_2 , L_36 ) ;
if ( V_23 -> V_38 & V_77 )
F_15 ( V_2 , L_37 ) ;
if ( V_23 -> V_38 & V_78 )
F_15 ( V_2 , L_38 ) ;
if ( V_23 -> V_38 & V_79 )
F_15 ( V_2 , L_39 ) ;
if ( V_23 -> V_38 & V_80 )
F_15 ( V_2 , L_40 ) ;
if ( V_23 -> V_33 ) {
if ( V_23 -> V_38 & V_81 )
F_15 ( V_2 , L_41 ) ;
else
F_15 ( V_2 , L_42 ) ;
}
#ifdef F_18
if ( V_23 -> V_38 & V_82 ) {
F_15 ( V_2 , L_43 ) ;
if ( V_23 -> V_83 )
F_15 ( V_2 , L_44 , V_23 -> V_83 ) ;
}
#endif
if ( V_23 -> V_38 & V_84 )
F_15 ( V_2 , L_45 ) ;
if ( V_23 -> V_38 & V_85 )
F_15 ( V_2 , L_46 ) ;
if ( V_23 -> V_38 & V_86 )
F_15 ( V_2 , L_47 ) ;
if ( V_23 -> V_38 & V_87 )
F_15 ( V_2 , L_48 ) ;
if ( V_23 -> V_38 & V_88 )
F_15 ( V_2 , L_49 ) ;
F_2 ( V_2 , L_23 ) ;
V_25 = V_23 -> V_89 ? F_19 () : V_23 -> V_90 ;
V_26 = V_23 -> V_91 ;
F_20 ( V_26 , V_92 ) ;
F_15 ( V_2 ,
L_50 ,
( unsigned long long ) V_23 -> V_93 ,
( unsigned long long ) V_23 -> V_94 ) ;
F_15 ( V_2 ,
L_51 ,
( unsigned long long ) F_21 ( V_23 -> V_95 ) ,
( unsigned long long ) F_21 ( V_25 ) ,
( unsigned long long ) V_26 ) ;
F_15 ( V_2 ,
L_52 ,
V_23 -> V_96 , V_23 -> V_97 ,
V_23 -> V_98 ) ;
if ( V_23 -> V_38 & V_39 ) {
F_15 ( V_2 , L_53 ,
& V_23 -> V_99 ,
& V_23 -> V_100 ) ;
} else
F_15 ( V_2 , L_54 ,
& V_23 -> V_101 , & V_23 -> V_102 ) ;
F_15 ( V_2 , L_55 ,
V_23 -> V_103 , V_23 -> V_104 ) ;
F_15 ( V_2 , L_56 , V_23 -> V_105 ) ;
F_15 ( V_2 , L_57 , V_23 -> V_106 ) ;
if ( V_23 -> V_107 [ 0 ] )
F_15 ( V_2 , L_58 , V_23 -> V_107 ) ;
else
F_15 ( V_2 , L_59 ) ;
return 0 ;
}
static int F_22 ( const char T_2 * V_108 , unsigned long V_109 ,
T_7 * V_110 )
{
int V_61 = 0 ;
* V_110 = 0 ;
for (; V_61 < V_109 ; V_61 ++ ) {
int V_111 ;
char V_112 ;
* V_110 <<= 4 ;
if ( F_23 ( V_112 , & V_108 [ V_61 ] ) )
return - V_20 ;
V_111 = F_24 ( V_112 ) ;
if ( V_111 >= 0 )
* V_110 |= V_111 ;
else
break;
}
return V_61 ;
}
static int F_25 ( const char T_2 * V_108 ,
unsigned int V_109 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_109 ; V_61 ++ ) {
char V_112 ;
if ( F_23 ( V_112 , & V_108 [ V_61 ] ) )
return - V_20 ;
switch ( V_112 ) {
case '\"' :
case '\n' :
case '\r' :
case '\t' :
case ' ' :
case '=' :
break;
default:
goto V_113;
}
}
V_113:
return V_61 ;
}
static long F_26 ( const char T_2 * V_108 , unsigned long V_109 ,
unsigned long * V_110 )
{
int V_61 ;
* V_110 = 0 ;
for ( V_61 = 0 ; V_61 < V_109 ; V_61 ++ ) {
char V_112 ;
if ( F_23 ( V_112 , & V_108 [ V_61 ] ) )
return - V_20 ;
if ( ( V_112 >= '0' ) && ( V_112 <= '9' ) ) {
* V_110 *= 10 ;
* V_110 += V_112 - '0' ;
} else
break;
}
return V_61 ;
}
static int F_27 ( const char T_2 * V_108 , unsigned int V_109 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_109 ; V_61 ++ ) {
char V_112 ;
if ( F_23 ( V_112 , & V_108 [ V_61 ] ) )
return - V_20 ;
switch ( V_112 ) {
case '\"' :
case '\n' :
case '\r' :
case '\t' :
case ' ' :
goto V_114;
break;
default:
break;
}
}
V_114:
return V_61 ;
}
static T_1 F_28 ( const char T_2 * V_115 , struct V_22 * V_23 )
{
unsigned int V_116 = 0 ;
char V_112 ;
T_1 V_61 = 0 ;
int V_117 ;
V_23 -> V_60 = 0 ;
do {
T_7 V_118 ;
V_117 = F_22 ( & V_115 [ V_61 ] , 8 , & V_118 ) ;
if ( V_117 <= 0 )
return V_117 ;
V_23 -> V_62 [ V_116 ] = F_29 ( V_118 ) ;
if ( V_23 -> V_62 [ V_116 ] & V_119 )
V_23 -> V_38 |= V_78 ;
V_61 += V_117 ;
if ( F_23 ( V_112 , & V_115 [ V_61 ] ) )
return - V_20 ;
V_61 ++ ;
V_116 ++ ;
if ( V_116 >= V_120 )
return - V_121 ;
} while ( V_112 == ',' );
V_23 -> V_60 = V_116 ;
return V_61 ;
}
static T_1 F_30 ( struct V_5 * V_5 ,
const char T_2 * V_108 , T_3 V_7 ,
T_4 * V_122 )
{
struct V_1 * V_2 = V_5 -> V_123 ;
struct V_22 * V_23 = V_2 -> V_24 ;
int V_61 , V_124 , V_117 ;
char V_125 [ 16 ] , V_126 [ 32 ] ;
unsigned long V_111 = 0 ;
char * V_127 = NULL ;
int V_118 = 0 ;
char V_6 [ 128 ] ;
V_127 = & ( V_23 -> V_107 [ 0 ] ) ;
if ( V_7 < 1 ) {
F_10 ( L_60 ) ;
return - V_128 ;
}
V_124 = V_7 ;
V_118 = F_25 ( V_108 , V_124 ) ;
if ( V_118 < 0 ) {
F_10 ( L_61 ) ;
return V_118 ;
}
V_61 = V_118 ;
V_117 = F_27 ( & V_108 [ V_61 ] , sizeof( V_125 ) - 1 ) ;
if ( V_117 < 0 )
return V_117 ;
memset ( V_125 , 0 , sizeof( V_125 ) ) ;
if ( F_6 ( V_125 , & V_108 [ V_61 ] , V_117 ) )
return - V_20 ;
V_61 += V_117 ;
V_124 = V_7 - V_61 ;
V_117 = F_25 ( & V_108 [ V_61 ] , V_124 ) ;
if ( V_117 < 0 )
return V_117 ;
V_61 += V_117 ;
if ( V_129 ) {
T_3 V_130 = F_31 ( T_3 , V_7 , 1023 ) ;
char V_131 [ V_130 + 1 ] ;
if ( F_6 ( V_131 , V_108 , V_130 ) )
return - V_20 ;
V_131 [ V_130 ] = 0 ;
F_32 ( L_62 ,
V_125 , ( unsigned long ) V_7 , V_131 ) ;
}
if ( ! strcmp ( V_125 , L_63 ) ) {
V_117 = F_26 ( & V_108 [ V_61 ] , 10 , & V_111 ) ;
if ( V_117 < 0 )
return V_117 ;
V_61 += V_117 ;
if ( V_111 < 14 + 20 + 8 )
V_111 = 14 + 20 + 8 ;
if ( V_111 != V_23 -> V_27 ) {
V_23 -> V_27 = V_111 ;
V_23 -> V_132 = V_111 ;
}
sprintf ( V_127 , L_64 ,
V_23 -> V_27 ) ;
return V_7 ;
}
if ( ! strcmp ( V_125 , L_65 ) ) {
V_117 = F_26 ( & V_108 [ V_61 ] , 10 , & V_111 ) ;
if ( V_117 < 0 )
return V_117 ;
V_61 += V_117 ;
if ( V_111 < 14 + 20 + 8 )
V_111 = 14 + 20 + 8 ;
if ( V_111 != V_23 -> V_28 ) {
V_23 -> V_28 = V_111 ;
V_23 -> V_132 = V_111 ;
}
sprintf ( V_127 , L_66 ,
V_23 -> V_28 ) ;
return V_7 ;
}
if ( ! strcmp ( V_125 , L_67 ) ) {
V_117 = F_26 ( & V_108 [ V_61 ] , 10 , & V_111 ) ;
if ( V_117 < 0 )
return V_117 ;
V_61 += V_117 ;
if ( V_111 < 14 + 20 + 8 )
V_111 = 14 + 20 + 8 ;
if ( V_111 != V_23 -> V_27 ) {
V_23 -> V_27 = V_111 ;
V_23 -> V_28 = V_111 ;
V_23 -> V_132 = V_111 ;
}
sprintf ( V_127 , L_68 , V_23 -> V_27 ) ;
return V_7 ;
}
if ( ! strcmp ( V_125 , L_69 ) ) {
V_117 = F_26 ( & V_108 [ V_61 ] , 10 , & V_111 ) ;
if ( V_117 < 0 )
return V_117 ;
V_61 += V_117 ;
V_129 = V_111 ;
sprintf ( V_127 , L_70 , V_129 ) ;
return V_7 ;
}
if ( ! strcmp ( V_125 , L_71 ) ) {
V_117 = F_26 ( & V_108 [ V_61 ] , 10 , & V_111 ) ;
if ( V_117 < 0 )
return V_117 ;
V_61 += V_117 ;
V_23 -> V_29 = V_111 ;
sprintf ( V_127 , L_72 , V_23 -> V_29 ) ;
return V_7 ;
}
if ( ! strcmp ( V_125 , L_73 ) ) {
V_117 = F_26 ( & V_108 [ V_61 ] , 10 , & V_111 ) ;
if ( V_117 < 0 )
return V_117 ;
V_61 += V_117 ;
if ( V_111 == 0x7FFFFFFF )
V_23 -> V_30 = V_133 ;
else
V_23 -> V_30 = ( T_6 ) V_111 ;
sprintf ( V_127 , L_74 ,
( unsigned long long ) V_23 -> V_30 ) ;
return V_7 ;
}
if ( ! strcmp ( V_125 , L_75 ) ) {
V_117 = F_26 ( & V_108 [ V_61 ] , 10 , & V_111 ) ;
if ( V_117 < 0 )
return V_117 ;
V_61 += V_117 ;
if ( ! V_111 )
return V_117 ;
V_23 -> V_30 = V_23 -> V_27 * 8 * V_92 / V_111 ;
if ( V_129 )
F_33 ( L_76 , V_23 -> V_30 ) ;
sprintf ( V_127 , L_77 , V_111 ) ;
return V_7 ;
}
if ( ! strcmp ( V_125 , L_78 ) ) {
V_117 = F_26 ( & V_108 [ V_61 ] , 10 , & V_111 ) ;
if ( V_117 < 0 )
return V_117 ;
V_61 += V_117 ;
if ( ! V_111 )
return V_117 ;
V_23 -> V_30 = V_134 / V_111 ;
if ( V_129 )
F_33 ( L_76 , V_23 -> V_30 ) ;
sprintf ( V_127 , L_77 , V_111 ) ;
return V_7 ;
}
if ( ! strcmp ( V_125 , L_79 ) ) {
V_117 = F_26 ( & V_108 [ V_61 ] , 10 , & V_111 ) ;
if ( V_117 < 0 )
return V_117 ;
V_61 += V_117 ;
if ( V_111 != V_23 -> V_54 ) {
V_23 -> V_54 = V_111 ;
V_23 -> V_104 = V_111 ;
}
sprintf ( V_127 , L_80 , V_23 -> V_54 ) ;
return V_7 ;
}
if ( ! strcmp ( V_125 , L_81 ) ) {
V_117 = F_26 ( & V_108 [ V_61 ] , 10 , & V_111 ) ;
if ( V_117 < 0 )
return V_117 ;
V_61 += V_117 ;
if ( V_111 != V_23 -> V_56 ) {
V_23 -> V_56 = V_111 ;
V_23 -> V_103 = V_111 ;
}
sprintf ( V_127 , L_82 , V_23 -> V_56 ) ;
return V_7 ;
}
if ( ! strcmp ( V_125 , L_83 ) ) {
V_117 = F_26 ( & V_108 [ V_61 ] , 10 , & V_111 ) ;
if ( V_117 < 0 )
return V_117 ;
V_61 += V_117 ;
if ( V_111 != V_23 -> V_55 ) {
V_23 -> V_55 = V_111 ;
V_23 -> V_104 = V_111 ;
}
sprintf ( V_127 , L_84 , V_23 -> V_55 ) ;
return V_7 ;
}
if ( ! strcmp ( V_125 , L_85 ) ) {
V_117 = F_26 ( & V_108 [ V_61 ] , 10 , & V_111 ) ;
if ( V_117 < 0 )
return V_117 ;
V_61 += V_117 ;
if ( V_111 != V_23 -> V_57 ) {
V_23 -> V_57 = V_111 ;
V_23 -> V_103 = V_111 ;
}
sprintf ( V_127 , L_86 , V_23 -> V_57 ) ;
return V_7 ;
}
if ( ! strcmp ( V_125 , L_87 ) ) {
V_117 = F_26 ( & V_108 [ V_61 ] , 10 , & V_111 ) ;
if ( V_117 < 0 )
return V_117 ;
if ( ( V_111 > 0 ) &&
( ! ( V_23 -> V_51 -> V_135 & V_136 ) ) )
return - V_137 ;
V_61 += V_117 ;
V_23 -> V_31 = V_111 ;
sprintf ( V_127 , L_88 , V_23 -> V_31 ) ;
return V_7 ;
}
if ( ! strcmp ( V_125 , L_89 ) ) {
V_117 = F_26 ( & V_108 [ V_61 ] , 10 , & V_111 ) ;
if ( V_117 < 0 )
return V_117 ;
V_61 += V_117 ;
V_23 -> V_7 = V_111 ;
sprintf ( V_127 , L_90 ,
( unsigned long long ) V_23 -> V_7 ) ;
return V_7 ;
}
if ( ! strcmp ( V_125 , L_91 ) ) {
V_117 = F_26 ( & V_108 [ V_61 ] , 10 , & V_111 ) ;
if ( V_117 < 0 )
return V_117 ;
V_61 += V_117 ;
if ( V_23 -> V_58 != V_111 ) {
V_23 -> V_58 = V_111 ;
V_23 -> V_98 = 0 ;
}
sprintf ( V_127 , L_92 ,
V_23 -> V_58 ) ;
return V_7 ;
}
if ( ! strcmp ( V_125 , L_93 ) ) {
V_117 = F_26 ( & V_108 [ V_61 ] , 10 , & V_111 ) ;
if ( V_117 < 0 )
return V_117 ;
V_61 += V_117 ;
if ( V_23 -> V_59 != V_111 ) {
V_23 -> V_59 = V_111 ;
V_23 -> V_97 = 0 ;
}
sprintf ( V_127 , L_94 ,
V_23 -> V_59 ) ;
return V_7 ;
}
if ( ! strcmp ( V_125 , L_95 ) ) {
V_117 = F_26 ( & V_108 [ V_61 ] , 10 , & V_111 ) ;
if ( V_117 < 0 )
return V_117 ;
V_61 += V_117 ;
if ( F_34 ( V_111 ) ) {
V_23 -> V_71 = V_111 ;
sprintf ( V_127 , L_96 , V_23 -> V_71 ) ;
if ( V_23 -> V_138 ) {
F_35 ( V_23 -> V_138 ) ;
V_23 -> V_138 = NULL ;
}
}
else
sprintf ( V_127 , L_97 ) ;
return V_7 ;
}
if ( ! strcmp ( V_125 , L_98 ) ) {
char V_139 [ 32 ] ;
memset ( V_139 , 0 , 32 ) ;
V_117 = F_27 ( & V_108 [ V_61 ] , sizeof( V_139 ) - 1 ) ;
if ( V_117 < 0 )
return V_117 ;
if ( F_6 ( V_139 , & V_108 [ V_61 ] , V_117 ) )
return - V_20 ;
V_61 += V_117 ;
if ( strcmp ( V_139 , L_99 ) == 0 )
V_23 -> V_38 |= V_72 ;
else if ( strcmp ( V_139 , L_100 ) == 0 )
V_23 -> V_38 &= ~ V_72 ;
else if ( strcmp ( V_139 , L_101 ) == 0 )
V_23 -> V_38 |= V_74 ;
else if ( strcmp ( V_139 , L_102 ) == 0 )
V_23 -> V_38 &= ~ V_74 ;
else if ( strcmp ( V_139 , L_103 ) == 0 )
V_23 -> V_38 |= V_73 ;
else if ( strcmp ( V_139 , L_104 ) == 0 )
V_23 -> V_38 &= ~ V_73 ;
else if ( strcmp ( V_139 , L_105 ) == 0 )
V_23 -> V_38 |= V_75 ;
else if ( strcmp ( V_139 , L_106 ) == 0 )
V_23 -> V_38 &= ~ V_75 ;
else if ( strcmp ( V_139 , L_107 ) == 0 )
V_23 -> V_38 |= V_76 ;
else if ( strcmp ( V_139 , L_108 ) == 0 )
V_23 -> V_38 &= ~ V_76 ;
else if ( strcmp ( V_139 , L_109 ) == 0 )
V_23 -> V_38 |= V_84 ;
else if ( strcmp ( V_139 , L_110 ) == 0 )
V_23 -> V_38 &= ~ V_84 ;
else if ( strcmp ( V_139 , L_111 ) == 0 )
V_23 -> V_38 |= V_85 ;
else if ( strcmp ( V_139 , L_112 ) == 0 )
V_23 -> V_38 &= ~ V_85 ;
else if ( strcmp ( V_139 , L_113 ) == 0 )
V_23 -> V_38 |= V_78 ;
else if ( strcmp ( V_139 , L_114 ) == 0 )
V_23 -> V_38 &= ~ V_78 ;
else if ( strcmp ( V_139 , L_115 ) == 0 )
V_23 -> V_38 |= V_86 ;
else if ( strcmp ( V_139 , L_116 ) == 0 )
V_23 -> V_38 &= ~ V_86 ;
else if ( strcmp ( V_139 , L_117 ) == 0 )
V_23 -> V_38 |= V_87 ;
else if ( strcmp ( V_139 , L_118 ) == 0 )
V_23 -> V_38 &= ~ V_87 ;
else if ( strcmp ( V_139 , L_119 ) == 0 )
V_23 -> V_38 |= V_81 ;
else if ( strcmp ( V_139 , L_120 ) == 0 )
V_23 -> V_38 |= V_79 ;
else if ( strcmp ( V_139 , L_121 ) == 0 )
V_23 -> V_38 &= ~ V_79 ;
else if ( strcmp ( V_139 , L_122 ) == 0 )
V_23 -> V_38 |= V_80 ;
else if ( strcmp ( V_139 , L_123 ) == 0 )
V_23 -> V_38 &= ~ V_80 ;
#ifdef F_18
else if ( strcmp ( V_139 , L_124 ) == 0 )
V_23 -> V_38 |= V_82 ;
#endif
else if ( strcmp ( V_139 , L_125 ) == 0 )
V_23 -> V_38 &= ~ V_39 ;
else if ( strcmp ( V_139 , L_126 ) == 0 )
V_23 -> V_38 |= V_88 ;
else if ( strcmp ( V_139 , L_127 ) == 0 )
V_23 -> V_38 &= ~ V_88 ;
else if ( strcmp ( V_139 , L_128 ) == 0 )
V_23 -> V_38 |= V_77 ;
else if ( strcmp ( V_139 , L_129 ) == 0 )
V_23 -> V_38 &= ~ V_77 ;
else {
sprintf ( V_127 ,
L_130 ,
V_139 ,
L_131
L_132 ) ;
return V_7 ;
}
sprintf ( V_127 , L_133 , V_23 -> V_38 ) ;
return V_7 ;
}
if ( ! strcmp ( V_125 , L_134 ) || ! strcmp ( V_125 , L_135 ) ) {
V_117 = F_27 ( & V_108 [ V_61 ] , sizeof( V_23 -> V_46 ) - 1 ) ;
if ( V_117 < 0 )
return V_117 ;
if ( F_6 ( V_6 , & V_108 [ V_61 ] , V_117 ) )
return - V_20 ;
V_6 [ V_117 ] = 0 ;
if ( strcmp ( V_6 , V_23 -> V_46 ) != 0 ) {
memset ( V_23 -> V_46 , 0 , sizeof( V_23 -> V_46 ) ) ;
strncpy ( V_23 -> V_46 , V_6 , V_117 ) ;
V_23 -> V_140 = F_36 ( V_23 -> V_46 ) ;
V_23 -> V_102 = V_23 -> V_140 ;
}
if ( V_129 )
F_32 ( L_136 , V_23 -> V_46 ) ;
V_61 += V_117 ;
sprintf ( V_127 , L_137 , V_23 -> V_46 ) ;
return V_7 ;
}
if ( ! strcmp ( V_125 , L_138 ) ) {
V_117 = F_27 ( & V_108 [ V_61 ] , sizeof( V_23 -> V_47 ) - 1 ) ;
if ( V_117 < 0 )
return V_117 ;
if ( F_6 ( V_6 , & V_108 [ V_61 ] , V_117 ) )
return - V_20 ;
V_6 [ V_117 ] = 0 ;
if ( strcmp ( V_6 , V_23 -> V_47 ) != 0 ) {
memset ( V_23 -> V_47 , 0 , sizeof( V_23 -> V_47 ) ) ;
strncpy ( V_23 -> V_47 , V_6 , V_117 ) ;
V_23 -> V_141 = F_36 ( V_23 -> V_47 ) ;
V_23 -> V_102 = V_23 -> V_141 ;
}
if ( V_129 )
F_32 ( L_139 , V_23 -> V_47 ) ;
V_61 += V_117 ;
sprintf ( V_127 , L_140 , V_23 -> V_47 ) ;
return V_7 ;
}
if ( ! strcmp ( V_125 , L_141 ) ) {
V_117 = F_27 ( & V_108 [ V_61 ] , sizeof( V_6 ) - 1 ) ;
if ( V_117 < 0 )
return V_117 ;
V_23 -> V_38 |= V_39 ;
if ( F_6 ( V_6 , & V_108 [ V_61 ] , V_117 ) )
return - V_20 ;
V_6 [ V_117 ] = 0 ;
F_37 ( V_6 , - 1 , V_23 -> V_43 . V_142 , - 1 , NULL ) ;
snprintf ( V_6 , sizeof( V_6 ) , L_142 , & V_23 -> V_43 ) ;
V_23 -> V_100 = V_23 -> V_43 ;
if ( V_129 )
F_32 ( L_143 , V_6 ) ;
V_61 += V_117 ;
sprintf ( V_127 , L_144 , V_6 ) ;
return V_7 ;
}
if ( ! strcmp ( V_125 , L_145 ) ) {
V_117 = F_27 ( & V_108 [ V_61 ] , sizeof( V_6 ) - 1 ) ;
if ( V_117 < 0 )
return V_117 ;
V_23 -> V_38 |= V_39 ;
if ( F_6 ( V_6 , & V_108 [ V_61 ] , V_117 ) )
return - V_20 ;
V_6 [ V_117 ] = 0 ;
F_37 ( V_6 , - 1 , V_23 -> V_44 . V_142 , - 1 , NULL ) ;
snprintf ( V_6 , sizeof( V_6 ) , L_142 , & V_23 -> V_44 ) ;
V_23 -> V_100 = V_23 -> V_44 ;
if ( V_129 )
F_32 ( L_146 , V_6 ) ;
V_61 += V_117 ;
sprintf ( V_127 , L_147 , V_6 ) ;
return V_7 ;
}
if ( ! strcmp ( V_125 , L_148 ) ) {
V_117 = F_27 ( & V_108 [ V_61 ] , sizeof( V_6 ) - 1 ) ;
if ( V_117 < 0 )
return V_117 ;
V_23 -> V_38 |= V_39 ;
if ( F_6 ( V_6 , & V_108 [ V_61 ] , V_117 ) )
return - V_20 ;
V_6 [ V_117 ] = 0 ;
F_37 ( V_6 , - 1 , V_23 -> V_45 . V_142 , - 1 , NULL ) ;
snprintf ( V_6 , sizeof( V_6 ) , L_142 , & V_23 -> V_45 ) ;
if ( V_129 )
F_32 ( L_149 , V_6 ) ;
V_61 += V_117 ;
sprintf ( V_127 , L_150 , V_6 ) ;
return V_7 ;
}
if ( ! strcmp ( V_125 , L_151 ) ) {
V_117 = F_27 ( & V_108 [ V_61 ] , sizeof( V_6 ) - 1 ) ;
if ( V_117 < 0 )
return V_117 ;
V_23 -> V_38 |= V_39 ;
if ( F_6 ( V_6 , & V_108 [ V_61 ] , V_117 ) )
return - V_20 ;
V_6 [ V_117 ] = 0 ;
F_37 ( V_6 , - 1 , V_23 -> V_40 . V_142 , - 1 , NULL ) ;
snprintf ( V_6 , sizeof( V_6 ) , L_142 , & V_23 -> V_40 ) ;
V_23 -> V_99 = V_23 -> V_40 ;
if ( V_129 )
F_32 ( L_152 , V_6 ) ;
V_61 += V_117 ;
sprintf ( V_127 , L_153 , V_6 ) ;
return V_7 ;
}
if ( ! strcmp ( V_125 , L_154 ) ) {
V_117 = F_27 ( & V_108 [ V_61 ] , sizeof( V_23 -> V_48 ) - 1 ) ;
if ( V_117 < 0 )
return V_117 ;
if ( F_6 ( V_6 , & V_108 [ V_61 ] , V_117 ) )
return - V_20 ;
V_6 [ V_117 ] = 0 ;
if ( strcmp ( V_6 , V_23 -> V_48 ) != 0 ) {
memset ( V_23 -> V_48 , 0 , sizeof( V_23 -> V_48 ) ) ;
strncpy ( V_23 -> V_48 , V_6 , V_117 ) ;
V_23 -> V_143 = F_36 ( V_23 -> V_48 ) ;
V_23 -> V_101 = V_23 -> V_143 ;
}
if ( V_129 )
F_32 ( L_155 , V_23 -> V_48 ) ;
V_61 += V_117 ;
sprintf ( V_127 , L_156 , V_23 -> V_48 ) ;
return V_7 ;
}
if ( ! strcmp ( V_125 , L_157 ) ) {
V_117 = F_27 ( & V_108 [ V_61 ] , sizeof( V_23 -> V_49 ) - 1 ) ;
if ( V_117 < 0 )
return V_117 ;
if ( F_6 ( V_6 , & V_108 [ V_61 ] , V_117 ) )
return - V_20 ;
V_6 [ V_117 ] = 0 ;
if ( strcmp ( V_6 , V_23 -> V_49 ) != 0 ) {
memset ( V_23 -> V_49 , 0 , sizeof( V_23 -> V_49 ) ) ;
strncpy ( V_23 -> V_49 , V_6 , V_117 ) ;
V_23 -> V_144 = F_36 ( V_23 -> V_49 ) ;
V_23 -> V_101 = V_23 -> V_144 ;
}
if ( V_129 )
F_32 ( L_158 , V_23 -> V_49 ) ;
V_61 += V_117 ;
sprintf ( V_127 , L_159 , V_23 -> V_49 ) ;
return V_7 ;
}
if ( ! strcmp ( V_125 , L_160 ) ) {
V_117 = F_27 ( & V_108 [ V_61 ] , sizeof( V_126 ) - 1 ) ;
if ( V_117 < 0 )
return V_117 ;
memset ( V_126 , 0 , sizeof( V_126 ) ) ;
if ( F_6 ( V_126 , & V_108 [ V_61 ] , V_117 ) )
return - V_20 ;
if ( ! F_38 ( V_126 , V_23 -> V_53 ) )
return - V_128 ;
F_39 ( & V_23 -> V_145 [ 0 ] , V_23 -> V_53 ) ;
sprintf ( V_127 , L_161 , V_23 -> V_53 ) ;
return V_7 ;
}
if ( ! strcmp ( V_125 , L_162 ) ) {
V_117 = F_27 ( & V_108 [ V_61 ] , sizeof( V_126 ) - 1 ) ;
if ( V_117 < 0 )
return V_117 ;
memset ( V_126 , 0 , sizeof( V_126 ) ) ;
if ( F_6 ( V_126 , & V_108 [ V_61 ] , V_117 ) )
return - V_20 ;
if ( ! F_38 ( V_126 , V_23 -> V_50 ) )
return - V_128 ;
F_39 ( & V_23 -> V_145 [ 6 ] , V_23 -> V_50 ) ;
sprintf ( V_127 , L_163 , V_23 -> V_50 ) ;
return V_7 ;
}
if ( ! strcmp ( V_125 , L_164 ) ) {
F_40 ( V_23 ) ;
sprintf ( V_127 , L_165 ) ;
return V_7 ;
}
if ( ! strcmp ( V_125 , L_166 ) ) {
V_117 = F_26 ( & V_108 [ V_61 ] , 10 , & V_111 ) ;
if ( V_117 < 0 )
return V_117 ;
V_61 += V_117 ;
if ( V_111 > V_146 )
V_111 = V_146 ;
V_23 -> V_33 = V_111 ;
sprintf ( V_127 , L_167 , V_23 -> V_33 ) ;
return V_7 ;
}
#ifdef F_18
if ( ! strcmp ( V_125 , L_168 ) ) {
V_117 = F_26 ( & V_108 [ V_61 ] , 10 , & V_111 ) ;
if ( V_117 < 0 )
return V_117 ;
V_61 += V_117 ;
V_23 -> V_83 = V_111 ;
sprintf ( V_127 , L_169 , V_23 -> V_83 ) ;
return V_7 ;
}
#endif
if ( ! strcmp ( V_125 , L_170 ) ) {
V_117 = F_26 ( & V_108 [ V_61 ] , 10 , & V_111 ) ;
if ( V_117 < 0 )
return V_117 ;
V_61 += V_117 ;
V_23 -> V_34 = V_111 ;
sprintf ( V_127 , L_171 , V_23 -> V_34 ) ;
return V_7 ;
}
if ( ! strcmp ( V_125 , L_172 ) ) {
V_117 = F_26 ( & V_108 [ V_61 ] , 5 , & V_111 ) ;
if ( V_117 < 0 )
return V_117 ;
V_61 += V_117 ;
V_23 -> V_35 = V_111 ;
sprintf ( V_127 , L_173 , V_23 -> V_35 ) ;
return V_7 ;
}
if ( ! strcmp ( V_125 , L_174 ) ) {
V_117 = F_26 ( & V_108 [ V_61 ] , 5 , & V_111 ) ;
if ( V_117 < 0 )
return V_117 ;
V_61 += V_117 ;
V_23 -> V_36 = V_111 ;
sprintf ( V_127 , L_175 , V_23 -> V_36 ) ;
return V_7 ;
}
if ( ! strcmp ( V_125 , L_176 ) ) {
unsigned int V_116 , V_147 ;
V_117 = F_28 ( & V_108 [ V_61 ] , V_23 ) ;
if ( V_117 < 0 )
return V_117 ;
V_61 += V_117 ;
V_147 = sprintf ( V_127 , L_177 ) ;
for ( V_116 = 0 ; V_116 < V_23 -> V_60 ; V_116 ++ )
V_147 += sprintf ( V_127 + V_147 ,
L_22 , F_17 ( V_23 -> V_62 [ V_116 ] ) ,
V_116 == V_23 -> V_60 - 1 ? L_178 : L_179 ) ;
if ( V_23 -> V_60 && V_23 -> V_63 != 0xffff ) {
V_23 -> V_63 = 0xffff ;
V_23 -> V_66 = 0xffff ;
if ( V_129 )
F_32 ( L_180 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_125 , L_181 ) ) {
V_117 = F_26 ( & V_108 [ V_61 ] , 4 , & V_111 ) ;
if ( V_117 < 0 )
return V_117 ;
V_61 += V_117 ;
if ( V_111 <= 4095 ) {
V_23 -> V_63 = V_111 ;
if ( V_129 )
F_32 ( L_182 ) ;
if ( V_129 && V_23 -> V_60 )
F_32 ( L_183 ) ;
V_23 -> V_60 = 0 ;
sprintf ( V_127 , L_184 , V_23 -> V_63 ) ;
} else {
V_23 -> V_63 = 0xffff ;
V_23 -> V_66 = 0xffff ;
if ( V_129 )
F_32 ( L_185 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_125 , L_186 ) ) {
V_117 = F_26 ( & V_108 [ V_61 ] , 1 , & V_111 ) ;
if ( V_117 < 0 )
return V_117 ;
V_61 += V_117 ;
if ( ( V_111 <= 7 ) && ( V_23 -> V_63 != 0xffff ) ) {
V_23 -> V_64 = V_111 ;
sprintf ( V_127 , L_187 , V_23 -> V_64 ) ;
} else {
sprintf ( V_127 , L_188 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_125 , L_189 ) ) {
V_117 = F_26 ( & V_108 [ V_61 ] , 1 , & V_111 ) ;
if ( V_117 < 0 )
return V_117 ;
V_61 += V_117 ;
if ( ( V_111 <= 1 ) && ( V_23 -> V_63 != 0xffff ) ) {
V_23 -> V_65 = V_111 ;
sprintf ( V_127 , L_190 , V_23 -> V_65 ) ;
} else {
sprintf ( V_127 , L_191 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_125 , L_192 ) ) {
V_117 = F_26 ( & V_108 [ V_61 ] , 4 , & V_111 ) ;
if ( V_117 < 0 )
return V_117 ;
V_61 += V_117 ;
if ( ( V_111 <= 4095 ) && ( ( V_23 -> V_63 != 0xffff ) ) ) {
V_23 -> V_66 = V_111 ;
if ( V_129 )
F_32 ( L_193 ) ;
if ( V_129 && V_23 -> V_60 )
F_32 ( L_183 ) ;
V_23 -> V_60 = 0 ;
sprintf ( V_127 , L_194 , V_23 -> V_66 ) ;
} else {
V_23 -> V_63 = 0xffff ;
V_23 -> V_66 = 0xffff ;
if ( V_129 )
F_32 ( L_185 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_125 , L_195 ) ) {
V_117 = F_26 ( & V_108 [ V_61 ] , 1 , & V_111 ) ;
if ( V_117 < 0 )
return V_117 ;
V_61 += V_117 ;
if ( ( V_111 <= 7 ) && ( V_23 -> V_66 != 0xffff ) ) {
V_23 -> V_67 = V_111 ;
sprintf ( V_127 , L_196 , V_23 -> V_67 ) ;
} else {
sprintf ( V_127 , L_197 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_125 , L_198 ) ) {
V_117 = F_26 ( & V_108 [ V_61 ] , 1 , & V_111 ) ;
if ( V_117 < 0 )
return V_117 ;
V_61 += V_117 ;
if ( ( V_111 <= 1 ) && ( V_23 -> V_66 != 0xffff ) ) {
V_23 -> V_68 = V_111 ;
sprintf ( V_127 , L_199 , V_23 -> V_68 ) ;
} else {
sprintf ( V_127 , L_200 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_125 , L_201 ) ) {
T_7 V_148 = 0 ;
V_117 = F_22 ( & V_108 [ V_61 ] , 2 , & V_148 ) ;
if ( V_117 < 0 )
return V_117 ;
V_61 += V_117 ;
if ( V_117 == 2 ) {
V_23 -> V_69 = V_148 ;
sprintf ( V_127 , L_202 , V_23 -> V_69 ) ;
} else {
sprintf ( V_127 , L_203 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_125 , L_204 ) ) {
T_7 V_148 = 0 ;
V_117 = F_22 ( & V_108 [ V_61 ] , 2 , & V_148 ) ;
if ( V_117 < 0 )
return V_117 ;
V_61 += V_117 ;
if ( V_117 == 2 ) {
V_23 -> V_70 = V_148 ;
sprintf ( V_127 , L_205 , V_23 -> V_70 ) ;
} else {
sprintf ( V_127 , L_206 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_125 , L_207 ) ) {
V_117 = F_26 ( & V_108 [ V_61 ] , 9 , & V_111 ) ;
if ( V_117 < 0 )
return V_117 ;
V_61 += V_117 ;
V_23 -> V_37 = V_111 ;
sprintf ( V_127 , L_208 ,
V_23 -> V_37 ) ;
return V_7 ;
}
sprintf ( V_23 -> V_107 , L_209 , V_125 ) ;
return - V_128 ;
}
static int F_41 ( struct V_21 * V_21 , struct V_5 * V_5 )
{
return F_12 ( V_5 , F_14 , F_13 ( V_21 ) ) ;
}
static int F_42 ( struct V_1 * V_2 , void * V_3 )
{
struct V_149 * V_150 = V_2 -> V_24 ;
const struct V_22 * V_23 ;
F_43 ( ! V_150 ) ;
F_15 ( V_2 , L_210 ) ;
F_44 ( V_150 ) ;
F_45 (pkt_dev, &t->if_list, list)
if ( V_23 -> V_89 )
F_15 ( V_2 , L_211 , V_23 -> V_32 ) ;
F_15 ( V_2 , L_212 ) ;
F_45 (pkt_dev, &t->if_list, list)
if ( ! V_23 -> V_89 )
F_15 ( V_2 , L_211 , V_23 -> V_32 ) ;
if ( V_150 -> V_107 [ 0 ] )
F_15 ( V_2 , L_213 , V_150 -> V_107 ) ;
else
F_15 ( V_2 , L_214 ) ;
F_46 ( V_150 ) ;
return 0 ;
}
static T_1 F_47 ( struct V_5 * V_5 ,
const char T_2 * V_108 ,
T_3 V_7 , T_4 * V_122 )
{
struct V_1 * V_2 = V_5 -> V_123 ;
struct V_149 * V_150 = V_2 -> V_24 ;
int V_61 , V_124 , V_117 , V_151 ;
char V_125 [ 40 ] ;
char * V_127 ;
if ( V_7 < 1 ) {
return - V_128 ;
}
V_124 = V_7 ;
V_117 = F_25 ( V_108 , V_124 ) ;
if ( V_117 < 0 )
return V_117 ;
V_61 = V_117 ;
V_117 = F_27 ( & V_108 [ V_61 ] , sizeof( V_125 ) - 1 ) ;
if ( V_117 < 0 )
return V_117 ;
memset ( V_125 , 0 , sizeof( V_125 ) ) ;
if ( F_6 ( V_125 , & V_108 [ V_61 ] , V_117 ) )
return - V_20 ;
V_61 += V_117 ;
V_124 = V_7 - V_61 ;
V_117 = F_25 ( & V_108 [ V_61 ] , V_124 ) ;
if ( V_117 < 0 )
return V_117 ;
V_61 += V_117 ;
if ( V_129 )
F_32 ( L_215 , V_125 , ( unsigned long ) V_7 ) ;
if ( ! V_150 ) {
F_48 ( L_216 ) ;
V_151 = - V_128 ;
goto V_19;
}
V_127 = & ( V_150 -> V_107 [ 0 ] ) ;
if ( ! strcmp ( V_125 , L_217 ) ) {
char V_139 [ 32 ] ;
memset ( V_139 , 0 , 32 ) ;
V_117 = F_27 ( & V_108 [ V_61 ] , sizeof( V_139 ) - 1 ) ;
if ( V_117 < 0 ) {
V_151 = V_117 ;
goto V_19;
}
if ( F_6 ( V_139 , & V_108 [ V_61 ] , V_117 ) )
return - V_20 ;
V_61 += V_117 ;
F_49 ( & V_152 ) ;
V_151 = F_50 ( V_150 , V_139 ) ;
F_51 ( & V_152 ) ;
if ( ! V_151 ) {
V_151 = V_7 ;
sprintf ( V_127 , L_218 , V_139 ) ;
} else
sprintf ( V_127 , L_219 , V_139 ) ;
goto V_19;
}
if ( ! strcmp ( V_125 , L_220 ) ) {
F_49 ( & V_152 ) ;
V_150 -> V_153 |= V_154 ;
F_51 ( & V_152 ) ;
F_52 ( F_53 ( 125 ) ) ;
V_151 = V_7 ;
sprintf ( V_127 , L_221 ) ;
goto V_19;
}
if ( ! strcmp ( V_125 , L_222 ) ) {
sprintf ( V_127 , L_223 ) ;
V_151 = V_7 ;
goto V_19;
}
V_151 = - V_128 ;
V_19:
return V_151 ;
}
static int F_54 ( struct V_21 * V_21 , struct V_5 * V_5 )
{
return F_12 ( V_5 , F_42 , F_13 ( V_21 ) ) ;
}
static struct V_22 * F_55 ( const struct V_11 * V_12 ,
const char * V_155 , int remove )
{
struct V_149 * V_150 ;
struct V_22 * V_23 = NULL ;
bool V_156 = ( remove == V_157 ) ;
F_45 (t, &pn->pktgen_threads, th_list) {
V_23 = F_56 ( V_150 , V_155 , V_156 ) ;
if ( V_23 ) {
if ( remove ) {
F_44 ( V_150 ) ;
V_23 -> V_158 = 1 ;
V_150 -> V_153 |= V_159 ;
F_46 ( V_150 ) ;
}
break;
}
}
return V_23 ;
}
static void F_57 ( const struct V_11 * V_12 , const char * V_155 )
{
struct V_22 * V_23 = NULL ;
const int V_160 = 10 , V_161 = 125 ;
int V_61 = 0 ;
F_49 ( & V_152 ) ;
F_32 ( L_224 , V_162 , V_155 ) ;
while ( 1 ) {
V_23 = F_55 ( V_12 , V_155 , REMOVE ) ;
if ( V_23 == NULL )
break;
F_51 ( & V_152 ) ;
F_32 ( L_225 ,
V_162 , V_155 ) ;
F_52 ( F_53 ( V_161 ) ) ;
F_49 ( & V_152 ) ;
if ( ++ V_61 >= V_160 ) {
F_48 ( L_226 ,
V_162 , V_161 * V_61 , V_155 ) ;
break;
}
}
F_51 ( & V_152 ) ;
}
static void F_58 ( const struct V_11 * V_12 , struct V_163 * V_164 )
{
struct V_149 * V_150 ;
F_45 (t, &pn->pktgen_threads, th_list) {
struct V_22 * V_23 ;
F_45 (pkt_dev, &t->if_list, list) {
if ( V_23 -> V_51 != V_164 )
continue;
F_59 ( V_23 -> V_165 ) ;
V_23 -> V_165 = F_60 ( V_164 -> V_125 , 0600 ,
V_12 -> V_166 ,
& V_167 ,
V_23 ) ;
if ( ! V_23 -> V_165 )
F_48 ( L_227 ,
V_164 -> V_125 ) ;
break;
}
}
}
static int F_61 ( struct V_168 * V_169 ,
unsigned long V_170 , void * V_171 )
{
struct V_163 * V_164 = F_62 ( V_171 ) ;
struct V_11 * V_12 = F_4 ( F_63 ( V_164 ) , V_16 ) ;
if ( V_12 -> V_172 )
return V_173 ;
switch ( V_170 ) {
case V_174 :
F_58 ( V_12 , V_164 ) ;
break;
case V_175 :
F_57 ( V_12 , V_164 -> V_125 ) ;
break;
}
return V_173 ;
}
static struct V_163 * F_64 ( const struct V_11 * V_12 ,
struct V_22 * V_23 ,
const char * V_155 )
{
char V_176 [ V_177 + 5 ] ;
int V_61 ;
for ( V_61 = 0 ; V_155 [ V_61 ] != '@' ; V_61 ++ ) {
if ( V_61 == V_177 )
break;
V_176 [ V_61 ] = V_155 [ V_61 ] ;
}
V_176 [ V_61 ] = 0 ;
return F_65 ( V_12 -> V_178 , V_176 ) ;
}
static int F_66 ( const struct V_11 * V_12 ,
struct V_22 * V_23 , const char * V_155 )
{
struct V_163 * V_51 ;
int V_9 ;
if ( V_23 -> V_51 ) {
F_67 ( V_23 -> V_51 ) ;
V_23 -> V_51 = NULL ;
}
V_51 = F_64 ( V_12 , V_23 , V_155 ) ;
if ( ! V_51 ) {
F_48 ( L_228 , V_155 ) ;
return - V_179 ;
}
if ( V_51 -> type != V_180 ) {
F_48 ( L_229 , V_155 ) ;
V_9 = - V_128 ;
} else if ( ! F_68 ( V_51 ) ) {
F_48 ( L_230 , V_155 ) ;
V_9 = - V_181 ;
} else {
V_23 -> V_51 = V_51 ;
return 0 ;
}
F_67 ( V_51 ) ;
return V_9 ;
}
static void F_69 ( struct V_22 * V_23 )
{
int V_182 ;
if ( ! V_23 -> V_51 ) {
F_48 ( L_231 ) ;
sprintf ( V_23 -> V_107 ,
L_232 ) ;
return;
}
V_182 = V_23 -> V_51 -> V_183 ;
if ( V_182 <= V_23 -> V_35 ) {
F_10 ( L_233 ,
V_23 -> V_35 , ( V_182 ? : 1 ) - 1 , V_182 ,
V_23 -> V_32 ) ;
V_23 -> V_35 = ( V_182 ? : 1 ) - 1 ;
}
if ( V_23 -> V_36 >= V_182 ) {
F_10 ( L_234 ,
V_23 -> V_36 , ( V_182 ? : 1 ) - 1 , V_182 ,
V_23 -> V_32 ) ;
V_23 -> V_36 = ( V_182 ? : 1 ) - 1 ;
}
if ( F_16 ( V_23 -> V_50 ) )
F_39 ( & ( V_23 -> V_145 [ 6 ] ) , V_23 -> V_51 -> V_52 ) ;
F_39 ( & ( V_23 -> V_145 [ 0 ] ) , V_23 -> V_53 ) ;
if ( V_23 -> V_38 & V_39 ) {
int V_61 , V_184 = 0 , V_9 = 1 ;
struct V_185 * V_186 ;
if ( V_23 -> V_27 == 0 ) {
V_23 -> V_27 = 14 + sizeof( struct V_187 )
+ sizeof( struct V_188 )
+ sizeof( struct V_189 )
+ V_23 -> V_190 ;
}
for ( V_61 = 0 ; V_61 < V_191 ; V_61 ++ )
if ( V_23 -> V_99 . V_142 [ V_61 ] ) {
V_184 = 1 ;
break;
}
if ( ! V_184 ) {
F_70 () ;
V_186 = F_71 ( V_23 -> V_51 ) ;
if ( V_186 ) {
struct V_192 * V_193 ;
F_72 ( & V_186 -> V_194 ) ;
F_45 (ifp, &idev->addr_list, if_list) {
if ( ( V_193 -> V_195 & V_196 ) &&
! ( V_193 -> V_38 & V_197 ) ) {
V_23 -> V_99 = V_193 -> V_198 ;
V_9 = 0 ;
break;
}
}
F_73 ( & V_186 -> V_194 ) ;
}
F_74 () ;
if ( V_9 )
F_48 ( L_235 ) ;
}
} else {
if ( V_23 -> V_27 == 0 ) {
V_23 -> V_27 = 14 + sizeof( struct V_199 )
+ sizeof( struct V_188 )
+ sizeof( struct V_189 )
+ V_23 -> V_190 ;
}
V_23 -> V_143 = 0 ;
V_23 -> V_144 = 0 ;
if ( strlen ( V_23 -> V_48 ) == 0 ) {
struct V_200 * V_201 ;
F_70 () ;
V_201 = F_75 ( V_23 -> V_51 ) ;
if ( V_201 ) {
if ( V_201 -> V_202 ) {
V_23 -> V_143 =
V_201 -> V_202 -> V_203 ;
V_23 -> V_144 = V_23 -> V_143 ;
}
}
F_74 () ;
} else {
V_23 -> V_143 = F_36 ( V_23 -> V_48 ) ;
V_23 -> V_144 = F_36 ( V_23 -> V_49 ) ;
}
V_23 -> V_140 = F_36 ( V_23 -> V_46 ) ;
V_23 -> V_141 = F_36 ( V_23 -> V_47 ) ;
}
V_23 -> V_132 = V_23 -> V_27 ;
if ( V_23 -> V_27 > V_23 -> V_28 )
V_23 -> V_28 = V_23 -> V_27 ;
V_23 -> V_97 = 0 ;
V_23 -> V_98 = 0 ;
V_23 -> V_101 = V_23 -> V_143 ;
V_23 -> V_102 = V_23 -> V_140 ;
V_23 -> V_103 = V_23 -> V_56 ;
V_23 -> V_104 = V_23 -> V_54 ;
V_23 -> V_106 = 0 ;
}
static void F_76 ( struct V_22 * V_23 , T_5 V_204 )
{
T_5 V_205 , V_206 ;
T_8 V_207 ;
struct V_208 V_150 ;
F_77 ( & V_150 . V_209 , V_210 , V_211 ) ;
F_78 ( & V_150 . V_209 , V_204 ) ;
V_207 = F_79 ( F_80 ( & V_150 . V_209 ) ) ;
if ( V_207 <= 0 ) {
V_23 -> V_212 = F_81 ( V_204 , V_23 -> V_30 ) ;
return;
}
V_205 = F_19 () ;
if ( V_207 < 100000 ) {
do {
V_206 = F_19 () ;
} while ( F_82 ( V_206 , V_204 ) < 0 );
} else {
F_83 ( & V_150 , V_13 ) ;
do {
F_84 ( V_213 ) ;
F_85 ( & V_150 . V_209 , V_211 ) ;
if ( ! F_86 ( & V_150 . V_209 ) )
V_150 . V_214 = NULL ;
if ( F_87 ( V_150 . V_214 ) )
F_88 () ;
F_89 ( & V_150 . V_209 ) ;
} while ( V_150 . V_214 && V_23 -> V_89 && ! F_90 ( V_13 ) );
F_91 ( V_215 ) ;
V_206 = F_19 () ;
}
V_23 -> V_91 += F_79 ( F_92 ( V_206 , V_205 ) ) ;
V_23 -> V_212 = F_81 ( V_204 , V_23 -> V_30 ) ;
}
static inline void F_93 ( struct V_22 * V_23 )
{
V_23 -> V_190 = 0 ;
V_23 -> V_190 += V_23 -> V_60 * sizeof( V_216 ) ;
V_23 -> V_190 += F_94 ( V_23 ) ;
V_23 -> V_190 += F_95 ( V_23 ) ;
}
static inline int F_96 ( const struct V_22 * V_23 , int V_217 )
{
return ! ! ( V_23 -> V_218 [ V_217 ] . V_38 & V_219 ) ;
}
static inline int F_97 ( struct V_22 * V_23 )
{
int V_217 = V_23 -> V_220 ;
if ( V_23 -> V_38 & V_81 ) {
if ( V_23 -> V_218 [ V_217 ] . V_7 >= V_23 -> V_34 ) {
V_23 -> V_218 [ V_217 ] . V_7 = 0 ;
V_23 -> V_218 [ V_217 ] . V_38 = 0 ;
V_23 -> V_220 += 1 ;
if ( V_23 -> V_220 >= V_23 -> V_33 )
V_23 -> V_220 = 0 ;
}
} else {
V_217 = F_98 () % V_23 -> V_33 ;
V_23 -> V_220 = V_217 ;
if ( V_23 -> V_218 [ V_217 ] . V_7 > V_23 -> V_34 ) {
V_23 -> V_218 [ V_217 ] . V_7 = 0 ;
V_23 -> V_218 [ V_217 ] . V_38 = 0 ;
}
}
return V_23 -> V_220 ;
}
static void F_99 ( struct V_22 * V_23 , int V_217 )
{
struct V_221 * V_222 = V_23 -> V_218 [ V_217 ] . V_222 ;
struct V_11 * V_12 = F_4 ( F_63 ( V_23 -> V_51 ) , V_16 ) ;
if ( ! V_222 ) {
if ( V_23 -> V_83 ) {
V_222 = F_100 ( V_12 -> V_178 , F_29 ( V_23 -> V_83 ) , V_223 ) ;
} else {
V_222 = F_101 ( V_12 -> V_178 , V_224 ,
( V_225 * ) & V_23 -> V_102 ,
( V_225 * ) & V_23 -> V_101 ,
V_223 ,
V_23 -> V_226 ,
V_23 -> V_227 , 0 ) ;
}
if ( V_222 ) {
V_23 -> V_218 [ V_217 ] . V_222 = V_222 ;
F_93 ( V_23 ) ;
V_23 -> V_190 += V_222 -> V_228 . V_229 ;
}
}
}
static void F_102 ( struct V_22 * V_23 )
{
if ( V_23 -> V_38 & V_80 )
V_23 -> V_105 = F_103 () ;
else if ( V_23 -> V_35 <= V_23 -> V_36 ) {
T_9 V_150 ;
if ( V_23 -> V_38 & V_79 ) {
V_150 = F_98 () %
( V_23 -> V_36 -
V_23 -> V_35 + 1 )
+ V_23 -> V_35 ;
} else {
V_150 = V_23 -> V_105 + 1 ;
if ( V_150 > V_23 -> V_36 )
V_150 = V_23 -> V_35 ;
}
V_23 -> V_105 = V_150 ;
}
V_23 -> V_105 = V_23 -> V_105 % V_23 -> V_51 -> V_183 ;
}
static void F_104 ( struct V_22 * V_23 )
{
T_7 V_230 ;
T_7 V_231 ;
int V_217 = 0 ;
if ( V_23 -> V_33 )
V_217 = F_97 ( V_23 ) ;
if ( V_23 -> V_58 > 1 ) {
T_7 V_232 ;
T_7 V_118 ;
if ( V_23 -> V_38 & V_84 )
V_232 = F_98 () % V_23 -> V_58 ;
else {
V_232 = V_23 -> V_98 ++ ;
if ( V_23 -> V_98 >=
V_23 -> V_58 )
V_23 -> V_98 = 0 ;
}
V_118 = V_23 -> V_50 [ 5 ] + ( V_232 & 0xFF ) ;
V_23 -> V_145 [ 11 ] = V_118 ;
V_118 = ( V_23 -> V_50 [ 4 ] + ( ( V_232 >> 8 ) & 0xFF ) + ( V_118 >> 8 ) ) ;
V_23 -> V_145 [ 10 ] = V_118 ;
V_118 = ( V_23 -> V_50 [ 3 ] + ( ( V_232 >> 16 ) & 0xFF ) + ( V_118 >> 8 ) ) ;
V_23 -> V_145 [ 9 ] = V_118 ;
V_118 = ( V_23 -> V_50 [ 2 ] + ( ( V_232 >> 24 ) & 0xFF ) + ( V_118 >> 8 ) ) ;
V_23 -> V_145 [ 8 ] = V_118 ;
V_118 = ( V_23 -> V_50 [ 1 ] + ( V_118 >> 8 ) ) ;
V_23 -> V_145 [ 7 ] = V_118 ;
}
if ( V_23 -> V_59 > 1 ) {
T_7 V_232 ;
T_7 V_118 ;
if ( V_23 -> V_38 & V_85 )
V_232 = F_98 () % V_23 -> V_59 ;
else {
V_232 = V_23 -> V_97 ++ ;
if ( V_23 -> V_97 >=
V_23 -> V_59 ) {
V_23 -> V_97 = 0 ;
}
}
V_118 = V_23 -> V_53 [ 5 ] + ( V_232 & 0xFF ) ;
V_23 -> V_145 [ 5 ] = V_118 ;
V_118 = ( V_23 -> V_53 [ 4 ] + ( ( V_232 >> 8 ) & 0xFF ) + ( V_118 >> 8 ) ) ;
V_23 -> V_145 [ 4 ] = V_118 ;
V_118 = ( V_23 -> V_53 [ 3 ] + ( ( V_232 >> 16 ) & 0xFF ) + ( V_118 >> 8 ) ) ;
V_23 -> V_145 [ 3 ] = V_118 ;
V_118 = ( V_23 -> V_53 [ 2 ] + ( ( V_232 >> 24 ) & 0xFF ) + ( V_118 >> 8 ) ) ;
V_23 -> V_145 [ 2 ] = V_118 ;
V_118 = ( V_23 -> V_53 [ 1 ] + ( V_118 >> 8 ) ) ;
V_23 -> V_145 [ 1 ] = V_118 ;
}
if ( V_23 -> V_38 & V_78 ) {
unsigned int V_61 ;
for ( V_61 = 0 ; V_61 < V_23 -> V_60 ; V_61 ++ )
if ( V_23 -> V_62 [ V_61 ] & V_119 )
V_23 -> V_62 [ V_61 ] = V_119 |
( ( V_233 V_234 ) F_98 () &
F_29 ( 0x000fffff ) ) ;
}
if ( ( V_23 -> V_38 & V_86 ) && ( V_23 -> V_63 != 0xffff ) ) {
V_23 -> V_63 = F_98 () & ( 4096 - 1 ) ;
}
if ( ( V_23 -> V_38 & V_87 ) && ( V_23 -> V_66 != 0xffff ) ) {
V_23 -> V_66 = F_98 () & ( 4096 - 1 ) ;
}
if ( V_23 -> V_54 < V_23 -> V_55 ) {
if ( V_23 -> V_38 & V_75 )
V_23 -> V_104 = F_98 () %
( V_23 -> V_55 - V_23 -> V_54 )
+ V_23 -> V_54 ;
else {
V_23 -> V_104 ++ ;
if ( V_23 -> V_104 >= V_23 -> V_55 )
V_23 -> V_104 = V_23 -> V_54 ;
}
}
if ( V_23 -> V_56 < V_23 -> V_57 ) {
if ( V_23 -> V_38 & V_76 ) {
V_23 -> V_103 = F_98 () %
( V_23 -> V_57 - V_23 -> V_56 )
+ V_23 -> V_56 ;
} else {
V_23 -> V_103 ++ ;
if ( V_23 -> V_103 >= V_23 -> V_57 )
V_23 -> V_103 = V_23 -> V_56 ;
}
}
if ( ! ( V_23 -> V_38 & V_39 ) ) {
V_230 = F_17 ( V_23 -> V_143 ) ;
V_231 = F_17 ( V_23 -> V_144 ) ;
if ( V_230 < V_231 ) {
T_7 V_150 ;
if ( V_23 -> V_38 & V_72 )
V_150 = F_98 () % ( V_231 - V_230 ) + V_230 ;
else {
V_150 = F_17 ( V_23 -> V_101 ) ;
V_150 ++ ;
if ( V_150 > V_231 )
V_150 = V_230 ;
}
V_23 -> V_101 = F_29 ( V_150 ) ;
}
if ( V_23 -> V_33 && F_96 ( V_23 , V_217 ) ) {
V_23 -> V_102 = V_23 -> V_218 [ V_217 ] . V_102 ;
} else {
V_230 = F_17 ( V_23 -> V_140 ) ;
V_231 = F_17 ( V_23 -> V_141 ) ;
if ( V_230 < V_231 ) {
T_7 V_150 ;
V_234 V_235 ;
if ( V_23 -> V_38 & V_73 ) {
do {
V_150 = F_98 () %
( V_231 - V_230 ) + V_230 ;
V_235 = F_29 ( V_150 ) ;
} while ( F_105 ( V_235 ) ||
F_106 ( V_235 ) ||
F_107 ( V_235 ) ||
F_108 ( V_235 ) ||
F_109 ( V_235 ) );
V_23 -> V_102 = V_235 ;
} else {
V_150 = F_17 ( V_23 -> V_102 ) ;
V_150 ++ ;
if ( V_150 > V_231 ) {
V_150 = V_230 ;
}
V_23 -> V_102 = F_29 ( V_150 ) ;
}
}
if ( V_23 -> V_33 ) {
V_23 -> V_218 [ V_217 ] . V_38 |= V_219 ;
V_23 -> V_218 [ V_217 ] . V_102 =
V_23 -> V_102 ;
#ifdef F_18
if ( V_23 -> V_38 & V_82 )
F_99 ( V_23 , V_217 ) ;
#endif
V_23 -> V_106 ++ ;
}
}
} else {
if ( ! F_110 ( & V_23 -> V_44 ) ) {
int V_61 ;
for ( V_61 = 0 ; V_61 < 4 ; V_61 ++ ) {
V_23 -> V_100 . V_236 [ V_61 ] =
( ( ( V_233 V_234 ) F_98 () |
V_23 -> V_44 . V_236 [ V_61 ] ) &
V_23 -> V_45 . V_236 [ V_61 ] ) ;
}
}
}
if ( V_23 -> V_27 < V_23 -> V_28 ) {
T_7 V_150 ;
if ( V_23 -> V_38 & V_74 ) {
V_150 = F_98 () %
( V_23 -> V_28 - V_23 -> V_27 )
+ V_23 -> V_27 ;
} else {
V_150 = V_23 -> V_132 + 1 ;
if ( V_150 > V_23 -> V_28 )
V_150 = V_23 -> V_27 ;
}
V_23 -> V_132 = V_150 ;
}
F_102 ( V_23 ) ;
V_23 -> V_218 [ V_217 ] . V_7 ++ ;
}
static int F_111 ( struct V_237 * V_238 , struct V_22 * V_23 )
{
struct V_221 * V_222 = V_23 -> V_218 [ V_23 -> V_220 ] . V_222 ;
int V_9 = 0 ;
struct V_178 * V_178 = F_63 ( V_23 -> V_51 ) ;
if ( ! V_222 )
return 0 ;
if ( ( V_222 -> V_228 . V_239 != V_240 ) && ( V_23 -> V_83 == 0 ) )
return 0 ;
if ( ( V_222 -> V_228 . V_239 == V_241 ) && ( V_23 -> V_83 != 0 ) )
V_238 -> V_242 = ( unsigned long ) & V_23 -> V_243 | V_244 ;
F_112 () ;
V_9 = V_222 -> V_245 -> V_246 ( V_222 , V_238 ) ;
F_113 () ;
if ( V_9 ) {
F_114 ( V_178 , V_247 ) ;
goto error;
}
V_9 = V_222 -> type -> V_246 ( V_222 , V_238 ) ;
if ( V_9 ) {
F_114 ( V_178 , V_248 ) ;
goto error;
}
F_115 ( & V_222 -> V_194 ) ;
V_222 -> V_249 . V_250 += V_238 -> V_117 ;
V_222 -> V_249 . V_251 ++ ;
F_116 ( & V_222 -> V_194 ) ;
error:
return V_9 ;
}
static void F_117 ( struct V_22 * V_23 )
{
if ( V_23 -> V_33 ) {
int V_61 ;
for ( V_61 = 0 ; V_61 < V_23 -> V_33 ; V_61 ++ ) {
struct V_221 * V_222 = V_23 -> V_218 [ V_61 ] . V_222 ;
if ( V_222 ) {
F_118 ( V_222 ) ;
V_23 -> V_218 [ V_61 ] . V_222 = NULL ;
}
}
}
}
static int F_119 ( struct V_22 * V_23 ,
struct V_237 * V_238 , T_10 V_252 )
{
if ( V_23 -> V_38 & V_82 ) {
struct V_221 * V_222 = V_23 -> V_218 [ V_23 -> V_220 ] . V_222 ;
int V_253 = 0 ;
if ( V_222 ) {
int V_151 ;
T_11 * V_254 ;
struct V_199 * V_255 ;
V_253 = V_222 -> V_228 . V_229 - F_120 ( V_238 ) ;
if ( V_253 > 0 ) {
V_151 = F_121 ( V_238 , V_253 , 0 , V_256 ) ;
if ( V_151 < 0 ) {
F_48 ( L_236 ,
V_151 ) ;
goto V_9;
}
}
F_122 ( V_238 , V_257 ) ;
V_151 = F_111 ( V_238 , V_23 ) ;
if ( V_151 ) {
F_48 ( L_237 , V_151 ) ;
goto V_9;
}
V_254 = ( T_11 * ) F_123 ( V_238 , V_257 ) ;
memcpy ( V_254 , V_23 -> V_145 , 12 ) ;
* ( V_258 * ) & V_254 [ 12 ] = V_252 ;
V_255 = F_124 ( V_238 ) ;
V_255 -> V_259 = F_125 ( V_238 -> V_117 - V_257 ) ;
F_126 ( V_255 ) ;
}
}
return 1 ;
V_9:
F_127 ( V_238 ) ;
return 0 ;
}
static void F_128 ( V_234 * V_260 , struct V_22 * V_23 )
{
unsigned int V_61 ;
for ( V_61 = 0 ; V_61 < V_23 -> V_60 ; V_61 ++ )
* V_260 ++ = V_23 -> V_62 [ V_61 ] & ~ V_119 ;
V_260 -- ;
* V_260 |= V_119 ;
}
static inline T_10 F_129 ( unsigned int V_261 , unsigned int V_262 ,
unsigned int V_263 )
{
return F_125 ( V_261 | ( V_262 << 12 ) | ( V_263 << 13 ) ) ;
}
static void F_130 ( struct V_22 * V_23 , struct V_237 * V_238 ,
int V_264 )
{
struct V_265 V_266 ;
struct V_189 * V_267 ;
V_267 = (struct V_189 * ) F_131 ( V_238 , sizeof( * V_267 ) ) ;
V_264 -= sizeof( * V_267 ) ;
if ( V_23 -> V_29 <= 0 ) {
memset ( F_131 ( V_238 , V_264 ) , 0 , V_264 ) ;
} else {
int V_268 = V_23 -> V_29 ;
int V_61 , V_117 ;
int V_269 ;
if ( V_268 > V_270 )
V_268 = V_270 ;
V_117 = V_264 - V_268 * V_271 ;
if ( V_117 > 0 ) {
memset ( F_131 ( V_238 , V_117 ) , 0 , V_117 ) ;
V_264 = V_268 * V_271 ;
}
V_61 = 0 ;
V_269 = ( V_264 / V_268 ) < V_271 ?
( V_264 / V_268 ) : V_271 ;
while ( V_264 > 0 ) {
if ( F_132 ( ! V_23 -> V_138 ) ) {
int V_71 = F_133 () ;
if ( V_23 -> V_71 >= 0 && ( V_23 -> V_38 & V_88 ) )
V_71 = V_23 -> V_71 ;
V_23 -> V_138 = F_134 ( V_71 , V_272 | V_273 , 0 ) ;
if ( ! V_23 -> V_138 )
break;
}
F_135 ( V_23 -> V_138 ) ;
F_136 ( V_238 , V_61 , V_23 -> V_138 ) ;
F_137 ( V_238 ) -> V_268 [ V_61 ] . V_274 = 0 ;
if ( V_61 == ( V_268 - 1 ) )
F_138 ( & F_137 ( V_238 ) -> V_268 [ V_61 ] ,
( V_264 < V_271 ? V_264 : V_271 ) ) ;
else
F_138 ( & F_137 ( V_238 ) -> V_268 [ V_61 ] , V_269 ) ;
V_264 -= F_139 ( & F_137 ( V_238 ) -> V_268 [ V_61 ] ) ;
V_238 -> V_117 += F_139 ( & F_137 ( V_238 ) -> V_268 [ V_61 ] ) ;
V_238 -> V_275 += F_139 ( & F_137 ( V_238 ) -> V_268 [ V_61 ] ) ;
V_61 ++ ;
F_137 ( V_238 ) -> V_276 = V_61 ;
}
}
V_267 -> V_277 = F_29 ( V_278 ) ;
V_267 -> V_96 = F_29 ( V_23 -> V_96 ) ;
F_140 ( & V_266 ) ;
V_267 -> V_279 = F_29 ( V_266 . V_279 ) ;
V_267 -> V_280 = F_29 ( V_266 . V_280 ) ;
}
static struct V_237 * F_141 ( struct V_163 * V_164 ,
struct V_22 * V_23 ,
unsigned int V_281 )
{
struct V_237 * V_238 = NULL ;
unsigned int V_282 = V_23 -> V_132 + 64 + V_281 +
V_23 -> V_190 ;
if ( V_23 -> V_38 & V_88 ) {
int V_71 = V_23 -> V_71 >= 0 ? V_23 -> V_71 : F_133 () ;
V_238 = F_142 ( V_283 + V_282 , V_284 , 0 , V_71 ) ;
if ( F_87 ( V_238 ) ) {
F_143 ( V_238 , V_283 ) ;
V_238 -> V_164 = V_164 ;
}
} else {
V_238 = F_144 ( V_164 , V_282 , V_284 ) ;
}
return V_238 ;
}
static struct V_237 * F_145 ( struct V_163 * V_51 ,
struct V_22 * V_23 )
{
struct V_237 * V_238 = NULL ;
T_11 * V_254 ;
struct V_188 * V_285 ;
int V_264 , V_286 ;
struct V_199 * V_255 ;
T_10 V_252 = F_125 ( V_287 ) ;
V_234 * V_260 ;
T_10 * V_288 = NULL ;
T_10 * V_289 = NULL ;
T_10 * V_290 = NULL ;
T_10 * V_291 = NULL ;
V_258 V_292 ;
if ( V_23 -> V_60 )
V_252 = F_125 ( V_293 ) ;
if ( V_23 -> V_63 != 0xffff )
V_252 = F_125 ( V_294 ) ;
F_104 ( V_23 ) ;
V_292 = V_23 -> V_105 ;
V_264 = ( V_51 -> V_295 + 16 ) & ~ 0xf ;
V_238 = F_141 ( V_51 , V_23 , V_264 ) ;
if ( ! V_238 ) {
sprintf ( V_23 -> V_107 , L_238 ) ;
return NULL ;
}
F_146 ( V_238 -> V_10 ) ;
F_143 ( V_238 , V_264 ) ;
V_254 = ( T_11 * ) F_123 ( V_238 , 14 ) ;
V_260 = ( V_234 * ) F_131 ( V_238 , V_23 -> V_60 * sizeof( T_7 ) ) ;
if ( V_23 -> V_60 )
F_128 ( V_260 , V_23 ) ;
if ( V_23 -> V_63 != 0xffff ) {
if ( V_23 -> V_66 != 0xffff ) {
V_290 = ( T_10 * ) F_131 ( V_238 , sizeof( T_10 ) ) ;
* V_290 = F_129 ( V_23 -> V_66 ,
V_23 -> V_68 ,
V_23 -> V_67 ) ;
V_291 = ( T_10 * ) F_131 ( V_238 , sizeof( T_10 ) ) ;
* V_291 = F_125 ( V_294 ) ;
}
V_288 = ( T_10 * ) F_131 ( V_238 , sizeof( T_10 ) ) ;
* V_288 = F_129 ( V_23 -> V_63 ,
V_23 -> V_65 ,
V_23 -> V_64 ) ;
V_289 = ( T_10 * ) F_131 ( V_238 , sizeof( T_10 ) ) ;
* V_289 = F_125 ( V_287 ) ;
}
F_147 ( V_238 , 0 ) ;
F_148 ( V_238 , V_238 -> V_117 ) ;
V_255 = (struct V_199 * ) F_131 ( V_238 , sizeof( struct V_199 ) ) ;
F_149 ( V_238 , V_238 -> V_117 ) ;
V_285 = (struct V_188 * ) F_131 ( V_238 , sizeof( struct V_188 ) ) ;
F_150 ( V_238 , V_292 ) ;
V_238 -> V_296 = V_23 -> V_37 ;
memcpy ( V_254 , V_23 -> V_145 , 12 ) ;
* ( T_10 * ) & V_254 [ 12 ] = V_252 ;
V_264 = V_23 -> V_132 - 14 - 20 - 8 -
V_23 -> V_190 ;
if ( V_264 < 0 || V_264 < sizeof( struct V_189 ) )
V_264 = sizeof( struct V_189 ) ;
V_285 -> V_297 = F_125 ( V_23 -> V_104 ) ;
V_285 -> V_298 = F_125 ( V_23 -> V_103 ) ;
V_285 -> V_117 = F_125 ( V_264 + 8 ) ;
V_285 -> V_299 = 0 ;
V_255 -> V_300 = 5 ;
V_255 -> V_4 = 4 ;
V_255 -> V_301 = 32 ;
V_255 -> V_69 = V_23 -> V_69 ;
V_255 -> V_252 = V_302 ;
V_255 -> V_303 = V_23 -> V_101 ;
V_255 -> V_304 = V_23 -> V_102 ;
V_255 -> V_261 = F_125 ( V_23 -> V_305 ) ;
V_23 -> V_305 ++ ;
V_255 -> V_306 = 0 ;
V_286 = 20 + 8 + V_264 ;
V_255 -> V_259 = F_125 ( V_286 ) ;
F_126 ( V_255 ) ;
V_238 -> V_252 = V_252 ;
V_238 -> V_164 = V_51 ;
V_238 -> V_307 = V_308 ;
if ( ! ( V_23 -> V_38 & V_77 ) ) {
V_238 -> V_309 = V_310 ;
} else if ( V_51 -> V_311 & V_312 ) {
V_238 -> V_309 = V_313 ;
V_238 -> V_314 = 0 ;
F_151 ( V_238 , V_285 -> V_297 , V_285 -> V_298 ) ;
} else {
T_12 V_314 = F_152 ( V_238 ) ;
V_285 -> V_299 = F_153 ( V_285 -> V_297 , V_285 -> V_298 ,
V_264 + 8 , V_302 , V_314 ) ;
if ( V_285 -> V_299 == 0 )
V_285 -> V_299 = V_315 ;
}
F_130 ( V_23 , V_238 , V_264 ) ;
#ifdef F_18
if ( ! F_119 ( V_23 , V_238 , V_252 ) )
return NULL ;
#endif
return V_238 ;
}
static struct V_237 * F_154 ( struct V_163 * V_51 ,
struct V_22 * V_23 )
{
struct V_237 * V_238 = NULL ;
T_11 * V_254 ;
struct V_188 * V_285 ;
int V_264 , V_316 ;
struct V_187 * V_255 ;
T_10 V_252 = F_125 ( V_317 ) ;
V_234 * V_260 ;
T_10 * V_288 = NULL ;
T_10 * V_289 = NULL ;
T_10 * V_290 = NULL ;
T_10 * V_291 = NULL ;
V_258 V_292 ;
if ( V_23 -> V_60 )
V_252 = F_125 ( V_293 ) ;
if ( V_23 -> V_63 != 0xffff )
V_252 = F_125 ( V_294 ) ;
F_104 ( V_23 ) ;
V_292 = V_23 -> V_105 ;
V_238 = F_141 ( V_51 , V_23 , 16 ) ;
if ( ! V_238 ) {
sprintf ( V_23 -> V_107 , L_238 ) ;
return NULL ;
}
F_146 ( V_238 -> V_10 ) ;
F_143 ( V_238 , 16 ) ;
V_254 = ( T_11 * ) F_123 ( V_238 , 14 ) ;
V_260 = ( V_234 * ) F_131 ( V_238 , V_23 -> V_60 * sizeof( T_7 ) ) ;
if ( V_23 -> V_60 )
F_128 ( V_260 , V_23 ) ;
if ( V_23 -> V_63 != 0xffff ) {
if ( V_23 -> V_66 != 0xffff ) {
V_290 = ( T_10 * ) F_131 ( V_238 , sizeof( T_10 ) ) ;
* V_290 = F_129 ( V_23 -> V_66 ,
V_23 -> V_68 ,
V_23 -> V_67 ) ;
V_291 = ( T_10 * ) F_131 ( V_238 , sizeof( T_10 ) ) ;
* V_291 = F_125 ( V_294 ) ;
}
V_288 = ( T_10 * ) F_131 ( V_238 , sizeof( T_10 ) ) ;
* V_288 = F_129 ( V_23 -> V_63 ,
V_23 -> V_65 ,
V_23 -> V_64 ) ;
V_289 = ( T_10 * ) F_131 ( V_238 , sizeof( T_10 ) ) ;
* V_289 = F_125 ( V_317 ) ;
}
F_147 ( V_238 , 0 ) ;
F_148 ( V_238 , V_238 -> V_117 ) ;
V_255 = (struct V_187 * ) F_131 ( V_238 , sizeof( struct V_187 ) ) ;
F_149 ( V_238 , V_238 -> V_117 ) ;
V_285 = (struct V_188 * ) F_131 ( V_238 , sizeof( struct V_188 ) ) ;
F_150 ( V_238 , V_292 ) ;
V_238 -> V_296 = V_23 -> V_37 ;
memcpy ( V_254 , V_23 -> V_145 , 12 ) ;
* ( T_10 * ) & V_254 [ 12 ] = V_252 ;
V_264 = V_23 -> V_132 - 14 -
sizeof( struct V_187 ) - sizeof( struct V_188 ) -
V_23 -> V_190 ;
if ( V_264 < 0 || V_264 < sizeof( struct V_189 ) ) {
V_264 = sizeof( struct V_189 ) ;
F_155 ( L_239 , V_264 ) ;
}
V_316 = V_264 + sizeof( struct V_188 ) ;
V_285 -> V_297 = F_125 ( V_23 -> V_104 ) ;
V_285 -> V_298 = F_125 ( V_23 -> V_103 ) ;
V_285 -> V_117 = F_125 ( V_316 ) ;
V_285 -> V_299 = 0 ;
* ( V_234 * ) V_255 = F_29 ( 0x60000000 ) ;
if ( V_23 -> V_70 ) {
* ( V_234 * ) V_255 |= F_29 ( 0x60000000 | ( V_23 -> V_70 << 20 ) ) ;
}
V_255 -> V_318 = 32 ;
V_255 -> V_319 = F_125 ( V_316 ) ;
V_255 -> V_320 = V_302 ;
V_255 -> V_304 = V_23 -> V_100 ;
V_255 -> V_303 = V_23 -> V_99 ;
V_238 -> V_252 = V_252 ;
V_238 -> V_164 = V_51 ;
V_238 -> V_307 = V_308 ;
if ( ! ( V_23 -> V_38 & V_77 ) ) {
V_238 -> V_309 = V_310 ;
} else if ( V_51 -> V_311 & V_321 ) {
V_238 -> V_309 = V_313 ;
V_238 -> V_322 = F_156 ( V_238 ) - V_238 -> V_323 ;
V_238 -> V_324 = F_157 ( struct V_188 , V_299 ) ;
V_285 -> V_299 = ~ F_158 ( & V_255 -> V_303 , & V_255 -> V_304 , V_316 , V_302 , 0 ) ;
} else {
T_12 V_314 = F_152 ( V_238 ) ;
V_285 -> V_299 = F_158 ( & V_255 -> V_303 , & V_255 -> V_304 , V_316 , V_302 , V_314 ) ;
if ( V_285 -> V_299 == 0 )
V_285 -> V_299 = V_315 ;
}
F_130 ( V_23 , V_238 , V_264 ) ;
return V_238 ;
}
static struct V_237 * F_159 ( struct V_163 * V_51 ,
struct V_22 * V_23 )
{
if ( V_23 -> V_38 & V_39 )
return F_154 ( V_51 , V_23 ) ;
else
return F_145 ( V_51 , V_23 ) ;
}
static void F_40 ( struct V_22 * V_23 )
{
V_23 -> V_96 = 1 ;
V_23 -> V_91 = 0 ;
V_23 -> V_93 = 0 ;
V_23 -> V_325 = 0 ;
V_23 -> V_94 = 0 ;
}
static void F_160 ( struct V_149 * V_150 )
{
struct V_22 * V_23 ;
int V_326 = 0 ;
F_161 () ;
F_44 ( V_150 ) ;
F_45 (pkt_dev, &t->if_list, list) {
F_69 ( V_23 ) ;
if ( V_23 -> V_51 ) {
F_40 ( V_23 ) ;
V_23 -> V_89 = 1 ;
V_23 -> V_238 = NULL ;
V_23 -> V_95 = V_23 -> V_212 = F_19 () ;
F_93 ( V_23 ) ;
strcpy ( V_23 -> V_107 , L_240 ) ;
V_326 ++ ;
} else
strcpy ( V_23 -> V_107 , L_241 ) ;
}
F_46 ( V_150 ) ;
if ( V_326 )
V_150 -> V_153 &= ~ ( V_327 ) ;
}
static void F_7 ( struct V_11 * V_12 )
{
struct V_149 * V_150 ;
F_161 () ;
F_49 ( & V_152 ) ;
F_45 (t, &pn->pktgen_threads, th_list)
V_150 -> V_153 |= V_327 ;
F_51 ( & V_152 ) ;
}
static int F_162 ( const struct V_149 * V_150 )
{
const struct V_22 * V_23 ;
F_45 (pkt_dev, &t->if_list, list)
if ( V_23 -> V_89 )
return 1 ;
return 0 ;
}
static int F_163 ( struct V_149 * V_150 )
{
F_44 ( V_150 ) ;
while ( F_162 ( V_150 ) ) {
F_46 ( V_150 ) ;
F_164 ( 100 ) ;
if ( F_90 ( V_13 ) )
goto signal;
F_44 ( V_150 ) ;
}
F_46 ( V_150 ) ;
return 1 ;
signal:
return 0 ;
}
static int F_165 ( struct V_11 * V_12 )
{
struct V_149 * V_150 ;
int V_328 = 1 ;
F_49 ( & V_152 ) ;
F_45 (t, &pn->pktgen_threads, th_list) {
V_328 = F_163 ( V_150 ) ;
if ( V_328 == 0 )
break;
}
if ( V_328 == 0 )
F_45 (t, &pn->pktgen_threads, th_list)
V_150 -> V_153 |= ( V_327 ) ;
F_51 ( & V_152 ) ;
return V_328 ;
}
static void F_8 ( struct V_11 * V_12 )
{
struct V_149 * V_150 ;
F_161 () ;
F_49 ( & V_152 ) ;
F_45 (t, &pn->pktgen_threads, th_list)
V_150 -> V_153 |= ( V_329 ) ;
F_51 ( & V_152 ) ;
F_52 ( F_53 ( 125 ) ) ;
F_165 ( V_12 ) ;
}
static void F_9 ( struct V_11 * V_12 )
{
struct V_149 * V_150 ;
F_161 () ;
F_49 ( & V_152 ) ;
F_45 (t, &pn->pktgen_threads, th_list)
V_150 -> V_153 |= ( V_154 ) ;
F_51 ( & V_152 ) ;
F_52 ( F_53 ( 125 ) ) ;
F_165 ( V_12 ) ;
}
static void F_166 ( struct V_22 * V_23 , int V_276 )
{
T_13 V_330 , V_331 , V_332 ;
char * V_333 = V_23 -> V_107 ;
T_5 V_334 = F_92 ( V_23 -> V_90 ,
V_23 -> V_95 ) ;
T_5 V_26 = F_167 ( V_23 -> V_91 ) ;
V_333 += sprintf ( V_333 , L_242 ,
( unsigned long long ) F_21 ( V_334 ) ,
( unsigned long long ) F_21 ( F_92 ( V_334 , V_26 ) ) ,
( unsigned long long ) F_21 ( V_26 ) ,
( unsigned long long ) V_23 -> V_93 ,
V_23 -> V_132 , V_276 ) ;
V_332 = F_168 ( V_23 -> V_93 * V_134 ,
F_79 ( V_334 ) ) ;
V_330 = V_332 * 8 * V_23 -> V_132 ;
V_331 = V_330 ;
F_20 ( V_331 , 1000000 ) ;
V_333 += sprintf ( V_333 , L_243 ,
( unsigned long long ) V_332 ,
( unsigned long long ) V_331 ,
( unsigned long long ) V_330 ,
( unsigned long long ) V_23 -> V_94 ) ;
}
static int F_169 ( struct V_22 * V_23 )
{
int V_276 = V_23 -> V_238 ? F_137 ( V_23 -> V_238 ) -> V_276 : - 1 ;
if ( ! V_23 -> V_89 ) {
F_10 ( L_244 ,
V_23 -> V_32 ) ;
return - V_128 ;
}
F_127 ( V_23 -> V_238 ) ;
V_23 -> V_238 = NULL ;
V_23 -> V_90 = F_19 () ;
V_23 -> V_89 = 0 ;
F_166 ( V_23 , V_276 ) ;
return 0 ;
}
static struct V_22 * F_170 ( struct V_149 * V_150 )
{
struct V_22 * V_23 , * V_335 = NULL ;
F_44 ( V_150 ) ;
F_45 (pkt_dev, &t->if_list, list) {
if ( ! V_23 -> V_89 )
continue;
if ( V_335 == NULL )
V_335 = V_23 ;
else if ( F_82 ( V_23 -> V_212 , V_335 -> V_212 ) < 0 )
V_335 = V_23 ;
}
F_46 ( V_150 ) ;
return V_335 ;
}
static void F_171 ( struct V_149 * V_150 )
{
struct V_22 * V_23 ;
F_161 () ;
F_44 ( V_150 ) ;
F_45 (pkt_dev, &t->if_list, list) {
F_169 ( V_23 ) ;
}
F_46 ( V_150 ) ;
}
static void F_172 ( struct V_149 * V_150 )
{
struct V_336 * V_337 , * V_116 ;
struct V_22 * V_338 ;
F_161 () ;
F_44 ( V_150 ) ;
F_173 (q, n, &t->if_list) {
V_338 = F_174 ( V_337 , struct V_22 , V_339 ) ;
if ( ! V_338 -> V_158 )
continue;
F_127 ( V_338 -> V_238 ) ;
V_338 -> V_238 = NULL ;
F_175 ( V_150 , V_338 ) ;
break;
}
F_46 ( V_150 ) ;
}
static void F_176 ( struct V_149 * V_150 )
{
struct V_336 * V_337 , * V_116 ;
struct V_22 * V_338 ;
F_161 () ;
F_44 ( V_150 ) ;
F_173 (q, n, &t->if_list) {
V_338 = F_174 ( V_337 , struct V_22 , V_339 ) ;
F_127 ( V_338 -> V_238 ) ;
V_338 -> V_238 = NULL ;
F_175 ( V_150 , V_338 ) ;
}
F_46 ( V_150 ) ;
}
static void F_177 ( struct V_149 * V_150 )
{
F_178 ( V_150 -> V_340 -> V_341 , V_150 -> V_178 -> V_166 ) ;
}
static void F_179 ( struct V_22 * V_23 )
{
T_5 V_342 = F_19 () ;
F_88 () ;
V_23 -> V_91 += F_79 ( F_92 ( F_19 () , V_342 ) ) ;
}
static void F_180 ( struct V_22 * V_23 )
{
T_5 V_342 = F_19 () ;
while ( F_181 ( & ( V_23 -> V_238 -> V_343 ) ) != 1 ) {
if ( F_90 ( V_13 ) )
break;
if ( F_182 () )
F_179 ( V_23 ) ;
else
F_183 () ;
}
V_23 -> V_91 += F_79 ( F_92 ( F_19 () , V_342 ) ) ;
}
static void F_184 ( struct V_22 * V_23 )
{
struct V_163 * V_51 = V_23 -> V_51 ;
T_14 (* F_185)( struct V_237 * , struct V_163 * )
= V_51 -> V_344 -> V_345 ;
struct V_346 * V_347 ;
V_258 V_292 ;
int V_151 ;
if ( F_132 ( ! F_68 ( V_51 ) || ! F_186 ( V_51 ) ) ) {
F_169 ( V_23 ) ;
return;
}
if ( F_132 ( V_23 -> V_30 == V_133 ) ) {
V_23 -> V_212 = F_81 ( F_19 () , V_348 ) ;
return;
}
if ( ! V_23 -> V_238 || ( V_23 -> V_349 &&
++ V_23 -> V_350 >= V_23 -> V_31 ) ) {
F_127 ( V_23 -> V_238 ) ;
V_23 -> V_238 = F_159 ( V_51 , V_23 ) ;
if ( V_23 -> V_238 == NULL ) {
F_48 ( L_245 ) ;
F_88 () ;
V_23 -> V_350 -- ;
return;
}
V_23 -> V_351 = V_23 -> V_238 -> V_117 ;
V_23 -> V_352 ++ ;
V_23 -> V_350 = 0 ;
}
if ( V_23 -> V_30 && V_23 -> V_349 )
F_76 ( V_23 , V_23 -> V_212 ) ;
V_292 = F_187 ( V_23 -> V_238 ) ;
V_347 = F_188 ( V_51 , V_292 ) ;
F_189 ( V_347 ) ;
if ( F_132 ( F_190 ( V_347 ) ) ) {
V_151 = V_353 ;
V_23 -> V_349 = 0 ;
goto V_354;
}
F_191 ( & ( V_23 -> V_238 -> V_343 ) ) ;
V_151 = (* F_185)( V_23 -> V_238 , V_51 ) ;
switch ( V_151 ) {
case V_355 :
F_192 ( V_347 ) ;
V_23 -> V_349 = 1 ;
V_23 -> V_93 ++ ;
V_23 -> V_96 ++ ;
V_23 -> V_325 += V_23 -> V_351 ;
break;
case V_356 :
case V_357 :
case V_358 :
V_23 -> V_94 ++ ;
break;
default:
F_155 ( L_246 ,
V_23 -> V_32 , V_151 ) ;
V_23 -> V_94 ++ ;
case V_359 :
case V_353 :
F_193 ( & ( V_23 -> V_238 -> V_343 ) ) ;
V_23 -> V_349 = 0 ;
}
V_354:
F_194 ( V_347 ) ;
if ( ( V_23 -> V_7 != 0 ) && ( V_23 -> V_93 >= V_23 -> V_7 ) ) {
F_180 ( V_23 ) ;
F_169 ( V_23 ) ;
}
}
static int F_195 ( void * V_360 )
{
F_196 ( V_361 ) ;
struct V_149 * V_150 = V_360 ;
struct V_22 * V_23 = NULL ;
int V_362 = V_150 -> V_362 ;
F_43 ( F_103 () != V_362 ) ;
F_197 ( & V_150 -> V_363 ) ;
F_198 ( & V_150 -> V_364 ) ;
F_32 ( L_247 , V_362 , F_199 ( V_13 ) ) ;
F_84 ( V_213 ) ;
F_200 () ;
while ( ! F_201 () ) {
V_23 = F_170 ( V_150 ) ;
if ( F_132 ( ! V_23 && V_150 -> V_153 == 0 ) ) {
if ( V_150 -> V_178 -> V_172 )
break;
F_202 ( V_150 -> V_363 ,
V_150 -> V_153 != 0 ,
V_365 / 10 ) ;
F_203 () ;
continue;
}
F_91 ( V_215 ) ;
if ( F_87 ( V_23 ) ) {
F_184 ( V_23 ) ;
if ( F_182 () )
F_179 ( V_23 ) ;
else
F_183 () ;
}
if ( V_150 -> V_153 & V_327 ) {
F_171 ( V_150 ) ;
V_150 -> V_153 &= ~ ( V_327 ) ;
}
if ( V_150 -> V_153 & V_329 ) {
F_160 ( V_150 ) ;
V_150 -> V_153 &= ~ ( V_329 ) ;
}
if ( V_150 -> V_153 & V_154 ) {
F_176 ( V_150 ) ;
V_150 -> V_153 &= ~ ( V_154 ) ;
}
if ( V_150 -> V_153 & V_159 ) {
F_172 ( V_150 ) ;
V_150 -> V_153 &= ~ ( V_159 ) ;
}
F_203 () ;
F_84 ( V_213 ) ;
}
F_32 ( L_248 , V_150 -> V_340 -> V_341 ) ;
F_171 ( V_150 ) ;
F_32 ( L_249 , V_150 -> V_340 -> V_341 ) ;
F_176 ( V_150 ) ;
F_32 ( L_250 , V_150 -> V_340 -> V_341 ) ;
F_177 ( V_150 ) ;
while ( ! F_201 () ) {
F_84 ( V_213 ) ;
F_88 () ;
}
F_91 ( V_215 ) ;
return 0 ;
}
static struct V_22 * F_56 ( struct V_149 * V_150 ,
const char * V_155 , bool V_156 )
{
struct V_22 * V_333 , * V_23 = NULL ;
T_3 V_117 = strlen ( V_155 ) ;
F_44 ( V_150 ) ;
F_45 (p, &t->if_list, list)
if ( strncmp ( V_333 -> V_32 , V_155 , V_117 ) == 0 ) {
if ( V_333 -> V_32 [ V_117 ] ) {
if ( V_156 || V_333 -> V_32 [ V_117 ] != '@' )
continue;
}
V_23 = V_333 ;
break;
}
F_46 ( V_150 ) ;
F_32 ( L_251 , V_155 , V_23 ) ;
return V_23 ;
}
static int F_204 ( struct V_149 * V_150 ,
struct V_22 * V_23 )
{
int V_366 = 0 ;
F_44 ( V_150 ) ;
if ( V_23 -> V_367 ) {
F_48 ( L_252 ) ;
V_366 = - V_368 ;
goto V_19;
}
F_205 ( & V_23 -> V_339 , & V_150 -> V_369 ) ;
V_23 -> V_367 = V_150 ;
V_23 -> V_89 = 0 ;
V_19:
F_46 ( V_150 ) ;
return V_366 ;
}
static int F_50 ( struct V_149 * V_150 , const char * V_155 )
{
struct V_22 * V_23 ;
int V_9 ;
int V_71 = F_206 ( V_150 -> V_362 ) ;
V_23 = F_55 ( V_150 -> V_178 , V_155 , V_157 ) ;
if ( V_23 ) {
F_48 ( L_253 ) ;
return - V_368 ;
}
V_23 = F_207 ( sizeof( struct V_22 ) , V_272 , V_71 ) ;
if ( ! V_23 )
return - V_370 ;
strcpy ( V_23 -> V_32 , V_155 ) ;
V_23 -> V_218 = F_208 ( V_146 * sizeof( struct V_371 ) ,
V_71 ) ;
if ( V_23 -> V_218 == NULL ) {
F_209 ( V_23 ) ;
return - V_370 ;
}
V_23 -> V_158 = 0 ;
V_23 -> V_29 = 0 ;
V_23 -> V_30 = V_372 ;
V_23 -> V_7 = V_373 ;
V_23 -> V_93 = 0 ;
V_23 -> V_54 = 9 ;
V_23 -> V_55 = 9 ;
V_23 -> V_56 = 9 ;
V_23 -> V_57 = 9 ;
V_23 -> V_64 = 0 ;
V_23 -> V_65 = 0 ;
V_23 -> V_63 = 0xffff ;
V_23 -> V_67 = 0 ;
V_23 -> V_68 = 0 ;
V_23 -> V_66 = 0xffff ;
V_23 -> V_71 = - 1 ;
V_9 = F_66 ( V_150 -> V_178 , V_23 , V_155 ) ;
if ( V_9 )
goto V_374;
if ( V_23 -> V_51 -> V_135 & V_136 )
V_23 -> V_31 = V_375 ;
V_23 -> V_165 = F_60 ( V_155 , 0600 , V_150 -> V_178 -> V_166 ,
& V_167 , V_23 ) ;
if ( ! V_23 -> V_165 ) {
F_48 ( L_254 ,
V_376 , V_155 ) ;
V_9 = - V_128 ;
goto V_377;
}
#ifdef F_18
V_23 -> V_226 = V_240 ;
V_23 -> V_227 = V_378 ;
V_23 -> V_379 . V_380 = V_223 ;
V_23 -> V_243 . V_164 = V_23 -> V_51 ;
F_210 ( & V_23 -> V_243 , V_381 , false ) ;
V_23 -> V_243 . V_382 = & V_23 -> V_243 ;
V_23 -> V_243 . V_383 = & V_23 -> V_379 ;
#endif
return F_204 ( V_150 , V_23 ) ;
V_377:
F_67 ( V_23 -> V_51 ) ;
V_374:
#ifdef F_18
F_117 ( V_23 ) ;
#endif
F_211 ( V_23 -> V_218 ) ;
F_209 ( V_23 ) ;
return V_9 ;
}
static int T_15 F_212 ( int V_362 , struct V_11 * V_12 )
{
struct V_149 * V_150 ;
struct V_384 * V_385 ;
struct V_386 * V_333 ;
V_150 = F_207 ( sizeof( struct V_149 ) , V_272 ,
F_206 ( V_362 ) ) ;
if ( ! V_150 ) {
F_48 ( L_255 ) ;
return - V_370 ;
}
F_213 ( & V_150 -> F_44 ) ;
V_150 -> V_362 = V_362 ;
F_214 ( & V_150 -> V_369 ) ;
F_215 ( & V_150 -> V_387 , & V_12 -> V_388 ) ;
F_216 ( & V_150 -> V_364 ) ;
V_333 = F_217 ( F_195 ,
V_150 ,
F_206 ( V_362 ) ,
L_256 , V_362 ) ;
if ( F_218 ( V_333 ) ) {
F_48 ( L_257 , V_150 -> V_362 ) ;
F_219 ( & V_150 -> V_387 ) ;
F_209 ( V_150 ) ;
return F_220 ( V_333 ) ;
}
F_221 ( V_333 , V_362 ) ;
V_150 -> V_340 = V_333 ;
V_385 = F_60 ( V_150 -> V_340 -> V_341 , 0600 , V_12 -> V_166 ,
& V_389 , V_150 ) ;
if ( ! V_385 ) {
F_48 ( L_254 ,
V_376 , V_150 -> V_340 -> V_341 ) ;
F_222 ( V_333 ) ;
F_219 ( & V_150 -> V_387 ) ;
F_209 ( V_150 ) ;
return - V_128 ;
}
V_150 -> V_178 = V_12 ;
F_223 ( V_333 ) ;
F_224 ( & V_150 -> V_364 ) ;
return 0 ;
}
static void F_225 ( struct V_149 * V_150 ,
struct V_22 * V_23 )
{
struct V_336 * V_337 , * V_116 ;
struct V_22 * V_333 ;
F_173 (q, n, &t->if_list) {
V_333 = F_174 ( V_337 , struct V_22 , V_339 ) ;
if ( V_333 == V_23 )
F_219 ( & V_333 -> V_339 ) ;
}
}
static int F_175 ( struct V_149 * V_150 ,
struct V_22 * V_23 )
{
F_32 ( L_258 , V_23 ) ;
if ( V_23 -> V_89 ) {
F_10 ( L_259 ) ;
F_169 ( V_23 ) ;
}
if ( V_23 -> V_51 ) {
F_67 ( V_23 -> V_51 ) ;
V_23 -> V_51 = NULL ;
}
F_225 ( V_150 , V_23 ) ;
if ( V_23 -> V_165 )
F_59 ( V_23 -> V_165 ) ;
#ifdef F_18
F_117 ( V_23 ) ;
#endif
F_211 ( V_23 -> V_218 ) ;
if ( V_23 -> V_138 )
F_35 ( V_23 -> V_138 ) ;
F_209 ( V_23 ) ;
return 0 ;
}
static int T_15 F_226 ( struct V_178 * V_178 )
{
struct V_11 * V_12 = F_4 ( V_178 , V_16 ) ;
struct V_384 * V_385 ;
int V_362 , V_151 = 0 ;
V_12 -> V_178 = V_178 ;
F_214 ( & V_12 -> V_388 ) ;
V_12 -> V_172 = false ;
V_12 -> V_166 = F_227 ( V_376 , V_12 -> V_178 -> V_390 ) ;
if ( ! V_12 -> V_166 ) {
F_228 ( L_260 , V_376 ) ;
return - V_179 ;
}
V_385 = F_229 ( V_391 , 0600 , V_12 -> V_166 , & V_392 ) ;
if ( V_385 == NULL ) {
F_48 ( L_261 , V_391 ) ;
V_151 = - V_128 ;
goto remove;
}
F_230 (cpu) {
int V_9 ;
V_9 = F_212 ( V_362 , V_12 ) ;
if ( V_9 )
F_228 ( L_262 ,
V_362 , V_9 ) ;
}
if ( F_231 ( & V_12 -> V_388 ) ) {
F_48 ( L_263 ) ;
V_151 = - V_179 ;
goto V_393;
}
return 0 ;
V_393:
F_178 ( V_391 , V_12 -> V_166 ) ;
remove:
F_178 ( V_376 , V_12 -> V_178 -> V_390 ) ;
return V_151 ;
}
static void T_16 F_232 ( struct V_178 * V_178 )
{
struct V_11 * V_12 = F_4 ( V_178 , V_16 ) ;
struct V_149 * V_150 ;
struct V_336 * V_337 , * V_116 ;
F_233 ( V_339 ) ;
V_12 -> V_172 = true ;
F_49 ( & V_152 ) ;
F_234 ( & V_12 -> V_388 , & V_339 ) ;
F_51 ( & V_152 ) ;
F_173 (q, n, &list) {
V_150 = F_174 ( V_337 , struct V_149 , V_387 ) ;
F_219 ( & V_150 -> V_387 ) ;
F_222 ( V_150 -> V_340 ) ;
F_209 ( V_150 ) ;
}
F_178 ( V_391 , V_12 -> V_166 ) ;
F_178 ( V_376 , V_12 -> V_178 -> V_390 ) ;
}
static int T_17 F_235 ( void )
{
int V_151 = 0 ;
F_33 ( L_264 , V_4 ) ;
V_151 = F_236 ( & V_394 ) ;
if ( V_151 )
return V_151 ;
V_151 = F_237 ( & V_395 ) ;
if ( V_151 )
F_238 ( & V_394 ) ;
return V_151 ;
}
static void T_18 F_239 ( void )
{
F_240 ( & V_395 ) ;
F_238 ( & V_394 ) ;
}
