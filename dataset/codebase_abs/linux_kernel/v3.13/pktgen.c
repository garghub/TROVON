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
if ( V_23 -> V_38 & V_82 )
F_15 ( V_2 , L_43 ) ;
#endif
if ( V_23 -> V_38 & V_83 )
F_15 ( V_2 , L_44 ) ;
if ( V_23 -> V_38 & V_84 )
F_15 ( V_2 , L_45 ) ;
if ( V_23 -> V_38 & V_85 )
F_15 ( V_2 , L_46 ) ;
if ( V_23 -> V_38 & V_86 )
F_15 ( V_2 , L_47 ) ;
if ( V_23 -> V_38 & V_87 )
F_15 ( V_2 , L_48 ) ;
F_2 ( V_2 , L_23 ) ;
V_25 = V_23 -> V_88 ? F_19 () : V_23 -> V_89 ;
V_26 = V_23 -> V_90 ;
F_20 ( V_26 , V_91 ) ;
F_15 ( V_2 ,
L_49 ,
( unsigned long long ) V_23 -> V_92 ,
( unsigned long long ) V_23 -> V_93 ) ;
F_15 ( V_2 ,
L_50 ,
( unsigned long long ) F_21 ( V_23 -> V_94 ) ,
( unsigned long long ) F_21 ( V_25 ) ,
( unsigned long long ) V_26 ) ;
F_15 ( V_2 ,
L_51 ,
V_23 -> V_95 , V_23 -> V_96 ,
V_23 -> V_97 ) ;
if ( V_23 -> V_38 & V_39 ) {
F_15 ( V_2 , L_52 ,
& V_23 -> V_98 ,
& V_23 -> V_99 ) ;
} else
F_15 ( V_2 , L_53 ,
& V_23 -> V_100 , & V_23 -> V_101 ) ;
F_15 ( V_2 , L_54 ,
V_23 -> V_102 , V_23 -> V_103 ) ;
F_15 ( V_2 , L_55 , V_23 -> V_104 ) ;
F_15 ( V_2 , L_56 , V_23 -> V_105 ) ;
if ( V_23 -> V_106 [ 0 ] )
F_15 ( V_2 , L_57 , V_23 -> V_106 ) ;
else
F_15 ( V_2 , L_58 ) ;
return 0 ;
}
static int F_22 ( const char T_2 * V_107 , unsigned long V_108 ,
T_7 * V_109 )
{
int V_61 = 0 ;
* V_109 = 0 ;
for (; V_61 < V_108 ; V_61 ++ ) {
int V_110 ;
char V_111 ;
* V_109 <<= 4 ;
if ( F_23 ( V_111 , & V_107 [ V_61 ] ) )
return - V_20 ;
V_110 = F_24 ( V_111 ) ;
if ( V_110 >= 0 )
* V_109 |= V_110 ;
else
break;
}
return V_61 ;
}
static int F_25 ( const char T_2 * V_107 ,
unsigned int V_108 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_108 ; V_61 ++ ) {
char V_111 ;
if ( F_23 ( V_111 , & V_107 [ V_61 ] ) )
return - V_20 ;
switch ( V_111 ) {
case '\"' :
case '\n' :
case '\r' :
case '\t' :
case ' ' :
case '=' :
break;
default:
goto V_112;
}
}
V_112:
return V_61 ;
}
static long F_26 ( const char T_2 * V_107 , unsigned long V_108 ,
unsigned long * V_109 )
{
int V_61 ;
* V_109 = 0 ;
for ( V_61 = 0 ; V_61 < V_108 ; V_61 ++ ) {
char V_111 ;
if ( F_23 ( V_111 , & V_107 [ V_61 ] ) )
return - V_20 ;
if ( ( V_111 >= '0' ) && ( V_111 <= '9' ) ) {
* V_109 *= 10 ;
* V_109 += V_111 - '0' ;
} else
break;
}
return V_61 ;
}
static int F_27 ( const char T_2 * V_107 , unsigned int V_108 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_108 ; V_61 ++ ) {
char V_111 ;
if ( F_23 ( V_111 , & V_107 [ V_61 ] ) )
return - V_20 ;
switch ( V_111 ) {
case '\"' :
case '\n' :
case '\r' :
case '\t' :
case ' ' :
goto V_113;
break;
default:
break;
}
}
V_113:
return V_61 ;
}
static T_1 F_28 ( const char T_2 * V_114 , struct V_22 * V_23 )
{
unsigned int V_115 = 0 ;
char V_111 ;
T_1 V_61 = 0 ;
int V_116 ;
V_23 -> V_60 = 0 ;
do {
T_7 V_117 ;
V_116 = F_22 ( & V_114 [ V_61 ] , 8 , & V_117 ) ;
if ( V_116 <= 0 )
return V_116 ;
V_23 -> V_62 [ V_115 ] = F_29 ( V_117 ) ;
if ( V_23 -> V_62 [ V_115 ] & V_118 )
V_23 -> V_38 |= V_78 ;
V_61 += V_116 ;
if ( F_23 ( V_111 , & V_114 [ V_61 ] ) )
return - V_20 ;
V_61 ++ ;
V_115 ++ ;
if ( V_115 >= V_119 )
return - V_120 ;
} while ( V_111 == ',' );
V_23 -> V_60 = V_115 ;
return V_61 ;
}
static T_1 F_30 ( struct V_5 * V_5 ,
const char T_2 * V_107 , T_3 V_7 ,
T_4 * V_121 )
{
struct V_1 * V_2 = V_5 -> V_122 ;
struct V_22 * V_23 = V_2 -> V_24 ;
int V_61 , V_123 , V_116 ;
char V_124 [ 16 ] , V_125 [ 32 ] ;
unsigned long V_110 = 0 ;
char * V_126 = NULL ;
int V_117 = 0 ;
char V_6 [ 128 ] ;
V_126 = & ( V_23 -> V_106 [ 0 ] ) ;
if ( V_7 < 1 ) {
F_10 ( L_59 ) ;
return - V_127 ;
}
V_123 = V_7 ;
V_117 = F_25 ( V_107 , V_123 ) ;
if ( V_117 < 0 ) {
F_10 ( L_60 ) ;
return V_117 ;
}
V_61 = V_117 ;
V_116 = F_27 ( & V_107 [ V_61 ] , sizeof( V_124 ) - 1 ) ;
if ( V_116 < 0 )
return V_116 ;
memset ( V_124 , 0 , sizeof( V_124 ) ) ;
if ( F_6 ( V_124 , & V_107 [ V_61 ] , V_116 ) )
return - V_20 ;
V_61 += V_116 ;
V_123 = V_7 - V_61 ;
V_116 = F_25 ( & V_107 [ V_61 ] , V_123 ) ;
if ( V_116 < 0 )
return V_116 ;
V_61 += V_116 ;
if ( V_128 ) {
T_3 V_129 = F_31 ( T_3 , V_7 , 1023 ) ;
char V_130 [ V_129 + 1 ] ;
if ( F_6 ( V_130 , V_107 , V_129 ) )
return - V_20 ;
V_130 [ V_129 ] = 0 ;
F_32 ( L_61 ,
V_124 , ( unsigned long ) V_7 , V_130 ) ;
}
if ( ! strcmp ( V_124 , L_62 ) ) {
V_116 = F_26 ( & V_107 [ V_61 ] , 10 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_61 += V_116 ;
if ( V_110 < 14 + 20 + 8 )
V_110 = 14 + 20 + 8 ;
if ( V_110 != V_23 -> V_27 ) {
V_23 -> V_27 = V_110 ;
V_23 -> V_131 = V_110 ;
}
sprintf ( V_126 , L_63 ,
V_23 -> V_27 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_64 ) ) {
V_116 = F_26 ( & V_107 [ V_61 ] , 10 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_61 += V_116 ;
if ( V_110 < 14 + 20 + 8 )
V_110 = 14 + 20 + 8 ;
if ( V_110 != V_23 -> V_28 ) {
V_23 -> V_28 = V_110 ;
V_23 -> V_131 = V_110 ;
}
sprintf ( V_126 , L_65 ,
V_23 -> V_28 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_66 ) ) {
V_116 = F_26 ( & V_107 [ V_61 ] , 10 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_61 += V_116 ;
if ( V_110 < 14 + 20 + 8 )
V_110 = 14 + 20 + 8 ;
if ( V_110 != V_23 -> V_27 ) {
V_23 -> V_27 = V_110 ;
V_23 -> V_28 = V_110 ;
V_23 -> V_131 = V_110 ;
}
sprintf ( V_126 , L_67 , V_23 -> V_27 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_68 ) ) {
V_116 = F_26 ( & V_107 [ V_61 ] , 10 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_61 += V_116 ;
V_128 = V_110 ;
sprintf ( V_126 , L_69 , V_128 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_70 ) ) {
V_116 = F_26 ( & V_107 [ V_61 ] , 10 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_61 += V_116 ;
V_23 -> V_29 = V_110 ;
sprintf ( V_126 , L_71 , V_23 -> V_29 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_72 ) ) {
V_116 = F_26 ( & V_107 [ V_61 ] , 10 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_61 += V_116 ;
if ( V_110 == 0x7FFFFFFF )
V_23 -> V_30 = V_132 ;
else
V_23 -> V_30 = ( T_6 ) V_110 ;
sprintf ( V_126 , L_73 ,
( unsigned long long ) V_23 -> V_30 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_74 ) ) {
V_116 = F_26 ( & V_107 [ V_61 ] , 10 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_61 += V_116 ;
if ( ! V_110 )
return V_116 ;
V_23 -> V_30 = V_23 -> V_27 * 8 * V_91 / V_110 ;
if ( V_128 )
F_33 ( L_75 , V_23 -> V_30 ) ;
sprintf ( V_126 , L_76 , V_110 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_77 ) ) {
V_116 = F_26 ( & V_107 [ V_61 ] , 10 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_61 += V_116 ;
if ( ! V_110 )
return V_116 ;
V_23 -> V_30 = V_133 / V_110 ;
if ( V_128 )
F_33 ( L_75 , V_23 -> V_30 ) ;
sprintf ( V_126 , L_76 , V_110 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_78 ) ) {
V_116 = F_26 ( & V_107 [ V_61 ] , 10 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_61 += V_116 ;
if ( V_110 != V_23 -> V_54 ) {
V_23 -> V_54 = V_110 ;
V_23 -> V_103 = V_110 ;
}
sprintf ( V_126 , L_79 , V_23 -> V_54 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_80 ) ) {
V_116 = F_26 ( & V_107 [ V_61 ] , 10 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_61 += V_116 ;
if ( V_110 != V_23 -> V_56 ) {
V_23 -> V_56 = V_110 ;
V_23 -> V_102 = V_110 ;
}
sprintf ( V_126 , L_81 , V_23 -> V_56 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_82 ) ) {
V_116 = F_26 ( & V_107 [ V_61 ] , 10 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_61 += V_116 ;
if ( V_110 != V_23 -> V_55 ) {
V_23 -> V_55 = V_110 ;
V_23 -> V_103 = V_110 ;
}
sprintf ( V_126 , L_83 , V_23 -> V_55 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_84 ) ) {
V_116 = F_26 ( & V_107 [ V_61 ] , 10 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_61 += V_116 ;
if ( V_110 != V_23 -> V_57 ) {
V_23 -> V_57 = V_110 ;
V_23 -> V_102 = V_110 ;
}
sprintf ( V_126 , L_85 , V_23 -> V_57 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_86 ) ) {
V_116 = F_26 ( & V_107 [ V_61 ] , 10 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
if ( ( V_110 > 0 ) &&
( ! ( V_23 -> V_51 -> V_134 & V_135 ) ) )
return - V_136 ;
V_61 += V_116 ;
V_23 -> V_31 = V_110 ;
sprintf ( V_126 , L_87 , V_23 -> V_31 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_88 ) ) {
V_116 = F_26 ( & V_107 [ V_61 ] , 10 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_61 += V_116 ;
V_23 -> V_7 = V_110 ;
sprintf ( V_126 , L_89 ,
( unsigned long long ) V_23 -> V_7 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_90 ) ) {
V_116 = F_26 ( & V_107 [ V_61 ] , 10 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_61 += V_116 ;
if ( V_23 -> V_58 != V_110 ) {
V_23 -> V_58 = V_110 ;
V_23 -> V_97 = 0 ;
}
sprintf ( V_126 , L_91 ,
V_23 -> V_58 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_92 ) ) {
V_116 = F_26 ( & V_107 [ V_61 ] , 10 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_61 += V_116 ;
if ( V_23 -> V_59 != V_110 ) {
V_23 -> V_59 = V_110 ;
V_23 -> V_96 = 0 ;
}
sprintf ( V_126 , L_93 ,
V_23 -> V_59 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_94 ) ) {
V_116 = F_26 ( & V_107 [ V_61 ] , 10 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_61 += V_116 ;
if ( F_34 ( V_110 ) ) {
V_23 -> V_71 = V_110 ;
sprintf ( V_126 , L_95 , V_23 -> V_71 ) ;
if ( V_23 -> V_137 ) {
F_35 ( V_23 -> V_137 ) ;
V_23 -> V_137 = NULL ;
}
}
else
sprintf ( V_126 , L_96 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_97 ) ) {
char V_138 [ 32 ] ;
memset ( V_138 , 0 , 32 ) ;
V_116 = F_27 ( & V_107 [ V_61 ] , sizeof( V_138 ) - 1 ) ;
if ( V_116 < 0 )
return V_116 ;
if ( F_6 ( V_138 , & V_107 [ V_61 ] , V_116 ) )
return - V_20 ;
V_61 += V_116 ;
if ( strcmp ( V_138 , L_98 ) == 0 )
V_23 -> V_38 |= V_72 ;
else if ( strcmp ( V_138 , L_99 ) == 0 )
V_23 -> V_38 &= ~ V_72 ;
else if ( strcmp ( V_138 , L_100 ) == 0 )
V_23 -> V_38 |= V_74 ;
else if ( strcmp ( V_138 , L_101 ) == 0 )
V_23 -> V_38 &= ~ V_74 ;
else if ( strcmp ( V_138 , L_102 ) == 0 )
V_23 -> V_38 |= V_73 ;
else if ( strcmp ( V_138 , L_103 ) == 0 )
V_23 -> V_38 &= ~ V_73 ;
else if ( strcmp ( V_138 , L_104 ) == 0 )
V_23 -> V_38 |= V_75 ;
else if ( strcmp ( V_138 , L_105 ) == 0 )
V_23 -> V_38 &= ~ V_75 ;
else if ( strcmp ( V_138 , L_106 ) == 0 )
V_23 -> V_38 |= V_76 ;
else if ( strcmp ( V_138 , L_107 ) == 0 )
V_23 -> V_38 &= ~ V_76 ;
else if ( strcmp ( V_138 , L_108 ) == 0 )
V_23 -> V_38 |= V_83 ;
else if ( strcmp ( V_138 , L_109 ) == 0 )
V_23 -> V_38 &= ~ V_83 ;
else if ( strcmp ( V_138 , L_110 ) == 0 )
V_23 -> V_38 |= V_84 ;
else if ( strcmp ( V_138 , L_111 ) == 0 )
V_23 -> V_38 &= ~ V_84 ;
else if ( strcmp ( V_138 , L_112 ) == 0 )
V_23 -> V_38 |= V_78 ;
else if ( strcmp ( V_138 , L_113 ) == 0 )
V_23 -> V_38 &= ~ V_78 ;
else if ( strcmp ( V_138 , L_114 ) == 0 )
V_23 -> V_38 |= V_85 ;
else if ( strcmp ( V_138 , L_115 ) == 0 )
V_23 -> V_38 &= ~ V_85 ;
else if ( strcmp ( V_138 , L_116 ) == 0 )
V_23 -> V_38 |= V_86 ;
else if ( strcmp ( V_138 , L_117 ) == 0 )
V_23 -> V_38 &= ~ V_86 ;
else if ( strcmp ( V_138 , L_118 ) == 0 )
V_23 -> V_38 |= V_81 ;
else if ( strcmp ( V_138 , L_119 ) == 0 )
V_23 -> V_38 |= V_79 ;
else if ( strcmp ( V_138 , L_120 ) == 0 )
V_23 -> V_38 &= ~ V_79 ;
else if ( strcmp ( V_138 , L_121 ) == 0 )
V_23 -> V_38 |= V_80 ;
else if ( strcmp ( V_138 , L_122 ) == 0 )
V_23 -> V_38 &= ~ V_80 ;
#ifdef F_18
else if ( strcmp ( V_138 , L_123 ) == 0 )
V_23 -> V_38 |= V_82 ;
#endif
else if ( strcmp ( V_138 , L_124 ) == 0 )
V_23 -> V_38 &= ~ V_39 ;
else if ( strcmp ( V_138 , L_125 ) == 0 )
V_23 -> V_38 |= V_87 ;
else if ( strcmp ( V_138 , L_126 ) == 0 )
V_23 -> V_38 &= ~ V_87 ;
else if ( strcmp ( V_138 , L_127 ) == 0 )
V_23 -> V_38 |= V_77 ;
else if ( strcmp ( V_138 , L_128 ) == 0 )
V_23 -> V_38 &= ~ V_77 ;
else {
sprintf ( V_126 ,
L_129 ,
V_138 ,
L_130
L_131 ) ;
return V_7 ;
}
sprintf ( V_126 , L_132 , V_23 -> V_38 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_133 ) || ! strcmp ( V_124 , L_134 ) ) {
V_116 = F_27 ( & V_107 [ V_61 ] , sizeof( V_23 -> V_46 ) - 1 ) ;
if ( V_116 < 0 )
return V_116 ;
if ( F_6 ( V_6 , & V_107 [ V_61 ] , V_116 ) )
return - V_20 ;
V_6 [ V_116 ] = 0 ;
if ( strcmp ( V_6 , V_23 -> V_46 ) != 0 ) {
memset ( V_23 -> V_46 , 0 , sizeof( V_23 -> V_46 ) ) ;
strncpy ( V_23 -> V_46 , V_6 , V_116 ) ;
V_23 -> V_139 = F_36 ( V_23 -> V_46 ) ;
V_23 -> V_101 = V_23 -> V_139 ;
}
if ( V_128 )
F_32 ( L_135 , V_23 -> V_46 ) ;
V_61 += V_116 ;
sprintf ( V_126 , L_136 , V_23 -> V_46 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_137 ) ) {
V_116 = F_27 ( & V_107 [ V_61 ] , sizeof( V_23 -> V_47 ) - 1 ) ;
if ( V_116 < 0 )
return V_116 ;
if ( F_6 ( V_6 , & V_107 [ V_61 ] , V_116 ) )
return - V_20 ;
V_6 [ V_116 ] = 0 ;
if ( strcmp ( V_6 , V_23 -> V_47 ) != 0 ) {
memset ( V_23 -> V_47 , 0 , sizeof( V_23 -> V_47 ) ) ;
strncpy ( V_23 -> V_47 , V_6 , V_116 ) ;
V_23 -> V_140 = F_36 ( V_23 -> V_47 ) ;
V_23 -> V_101 = V_23 -> V_140 ;
}
if ( V_128 )
F_32 ( L_138 , V_23 -> V_47 ) ;
V_61 += V_116 ;
sprintf ( V_126 , L_139 , V_23 -> V_47 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_140 ) ) {
V_116 = F_27 ( & V_107 [ V_61 ] , sizeof( V_6 ) - 1 ) ;
if ( V_116 < 0 )
return V_116 ;
V_23 -> V_38 |= V_39 ;
if ( F_6 ( V_6 , & V_107 [ V_61 ] , V_116 ) )
return - V_20 ;
V_6 [ V_116 ] = 0 ;
F_37 ( V_6 , - 1 , V_23 -> V_43 . V_141 , - 1 , NULL ) ;
snprintf ( V_6 , sizeof( V_6 ) , L_141 , & V_23 -> V_43 ) ;
V_23 -> V_99 = V_23 -> V_43 ;
if ( V_128 )
F_32 ( L_142 , V_6 ) ;
V_61 += V_116 ;
sprintf ( V_126 , L_143 , V_6 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_144 ) ) {
V_116 = F_27 ( & V_107 [ V_61 ] , sizeof( V_6 ) - 1 ) ;
if ( V_116 < 0 )
return V_116 ;
V_23 -> V_38 |= V_39 ;
if ( F_6 ( V_6 , & V_107 [ V_61 ] , V_116 ) )
return - V_20 ;
V_6 [ V_116 ] = 0 ;
F_37 ( V_6 , - 1 , V_23 -> V_44 . V_141 , - 1 , NULL ) ;
snprintf ( V_6 , sizeof( V_6 ) , L_141 , & V_23 -> V_44 ) ;
V_23 -> V_99 = V_23 -> V_44 ;
if ( V_128 )
F_32 ( L_145 , V_6 ) ;
V_61 += V_116 ;
sprintf ( V_126 , L_146 , V_6 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_147 ) ) {
V_116 = F_27 ( & V_107 [ V_61 ] , sizeof( V_6 ) - 1 ) ;
if ( V_116 < 0 )
return V_116 ;
V_23 -> V_38 |= V_39 ;
if ( F_6 ( V_6 , & V_107 [ V_61 ] , V_116 ) )
return - V_20 ;
V_6 [ V_116 ] = 0 ;
F_37 ( V_6 , - 1 , V_23 -> V_45 . V_141 , - 1 , NULL ) ;
snprintf ( V_6 , sizeof( V_6 ) , L_141 , & V_23 -> V_45 ) ;
if ( V_128 )
F_32 ( L_148 , V_6 ) ;
V_61 += V_116 ;
sprintf ( V_126 , L_149 , V_6 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_150 ) ) {
V_116 = F_27 ( & V_107 [ V_61 ] , sizeof( V_6 ) - 1 ) ;
if ( V_116 < 0 )
return V_116 ;
V_23 -> V_38 |= V_39 ;
if ( F_6 ( V_6 , & V_107 [ V_61 ] , V_116 ) )
return - V_20 ;
V_6 [ V_116 ] = 0 ;
F_37 ( V_6 , - 1 , V_23 -> V_40 . V_141 , - 1 , NULL ) ;
snprintf ( V_6 , sizeof( V_6 ) , L_141 , & V_23 -> V_40 ) ;
V_23 -> V_98 = V_23 -> V_40 ;
if ( V_128 )
F_32 ( L_151 , V_6 ) ;
V_61 += V_116 ;
sprintf ( V_126 , L_152 , V_6 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_153 ) ) {
V_116 = F_27 ( & V_107 [ V_61 ] , sizeof( V_23 -> V_48 ) - 1 ) ;
if ( V_116 < 0 )
return V_116 ;
if ( F_6 ( V_6 , & V_107 [ V_61 ] , V_116 ) )
return - V_20 ;
V_6 [ V_116 ] = 0 ;
if ( strcmp ( V_6 , V_23 -> V_48 ) != 0 ) {
memset ( V_23 -> V_48 , 0 , sizeof( V_23 -> V_48 ) ) ;
strncpy ( V_23 -> V_48 , V_6 , V_116 ) ;
V_23 -> V_142 = F_36 ( V_23 -> V_48 ) ;
V_23 -> V_100 = V_23 -> V_142 ;
}
if ( V_128 )
F_32 ( L_154 , V_23 -> V_48 ) ;
V_61 += V_116 ;
sprintf ( V_126 , L_155 , V_23 -> V_48 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_156 ) ) {
V_116 = F_27 ( & V_107 [ V_61 ] , sizeof( V_23 -> V_49 ) - 1 ) ;
if ( V_116 < 0 )
return V_116 ;
if ( F_6 ( V_6 , & V_107 [ V_61 ] , V_116 ) )
return - V_20 ;
V_6 [ V_116 ] = 0 ;
if ( strcmp ( V_6 , V_23 -> V_49 ) != 0 ) {
memset ( V_23 -> V_49 , 0 , sizeof( V_23 -> V_49 ) ) ;
strncpy ( V_23 -> V_49 , V_6 , V_116 ) ;
V_23 -> V_143 = F_36 ( V_23 -> V_49 ) ;
V_23 -> V_100 = V_23 -> V_143 ;
}
if ( V_128 )
F_32 ( L_157 , V_23 -> V_49 ) ;
V_61 += V_116 ;
sprintf ( V_126 , L_158 , V_23 -> V_49 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_159 ) ) {
V_116 = F_27 ( & V_107 [ V_61 ] , sizeof( V_125 ) - 1 ) ;
if ( V_116 < 0 )
return V_116 ;
memset ( V_125 , 0 , sizeof( V_125 ) ) ;
if ( F_6 ( V_125 , & V_107 [ V_61 ] , V_116 ) )
return - V_20 ;
if ( ! F_38 ( V_125 , V_23 -> V_53 ) )
return - V_127 ;
memcpy ( & V_23 -> V_144 [ 0 ] , V_23 -> V_53 , V_145 ) ;
sprintf ( V_126 , L_160 , V_23 -> V_53 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_161 ) ) {
V_116 = F_27 ( & V_107 [ V_61 ] , sizeof( V_125 ) - 1 ) ;
if ( V_116 < 0 )
return V_116 ;
memset ( V_125 , 0 , sizeof( V_125 ) ) ;
if ( F_6 ( V_125 , & V_107 [ V_61 ] , V_116 ) )
return - V_20 ;
if ( ! F_38 ( V_125 , V_23 -> V_50 ) )
return - V_127 ;
memcpy ( & V_23 -> V_144 [ 6 ] , V_23 -> V_50 , V_145 ) ;
sprintf ( V_126 , L_162 , V_23 -> V_50 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_163 ) ) {
F_39 ( V_23 ) ;
sprintf ( V_126 , L_164 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_165 ) ) {
V_116 = F_26 ( & V_107 [ V_61 ] , 10 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_61 += V_116 ;
if ( V_110 > V_146 )
V_110 = V_146 ;
V_23 -> V_33 = V_110 ;
sprintf ( V_126 , L_166 , V_23 -> V_33 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_167 ) ) {
V_116 = F_26 ( & V_107 [ V_61 ] , 10 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_61 += V_116 ;
V_23 -> V_34 = V_110 ;
sprintf ( V_126 , L_168 , V_23 -> V_34 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_169 ) ) {
V_116 = F_26 ( & V_107 [ V_61 ] , 5 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_61 += V_116 ;
V_23 -> V_35 = V_110 ;
sprintf ( V_126 , L_170 , V_23 -> V_35 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_171 ) ) {
V_116 = F_26 ( & V_107 [ V_61 ] , 5 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_61 += V_116 ;
V_23 -> V_36 = V_110 ;
sprintf ( V_126 , L_172 , V_23 -> V_36 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_173 ) ) {
unsigned int V_115 , V_147 ;
V_116 = F_28 ( & V_107 [ V_61 ] , V_23 ) ;
if ( V_116 < 0 )
return V_116 ;
V_61 += V_116 ;
V_147 = sprintf ( V_126 , L_174 ) ;
for ( V_115 = 0 ; V_115 < V_23 -> V_60 ; V_115 ++ )
V_147 += sprintf ( V_126 + V_147 ,
L_22 , F_17 ( V_23 -> V_62 [ V_115 ] ) ,
V_115 == V_23 -> V_60 - 1 ? L_175 : L_176 ) ;
if ( V_23 -> V_60 && V_23 -> V_63 != 0xffff ) {
V_23 -> V_63 = 0xffff ;
V_23 -> V_66 = 0xffff ;
if ( V_128 )
F_32 ( L_177 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_124 , L_178 ) ) {
V_116 = F_26 ( & V_107 [ V_61 ] , 4 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_61 += V_116 ;
if ( V_110 <= 4095 ) {
V_23 -> V_63 = V_110 ;
if ( V_128 )
F_32 ( L_179 ) ;
if ( V_128 && V_23 -> V_60 )
F_32 ( L_180 ) ;
V_23 -> V_60 = 0 ;
sprintf ( V_126 , L_181 , V_23 -> V_63 ) ;
} else {
V_23 -> V_63 = 0xffff ;
V_23 -> V_66 = 0xffff ;
if ( V_128 )
F_32 ( L_182 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_124 , L_183 ) ) {
V_116 = F_26 ( & V_107 [ V_61 ] , 1 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_61 += V_116 ;
if ( ( V_110 <= 7 ) && ( V_23 -> V_63 != 0xffff ) ) {
V_23 -> V_64 = V_110 ;
sprintf ( V_126 , L_184 , V_23 -> V_64 ) ;
} else {
sprintf ( V_126 , L_185 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_124 , L_186 ) ) {
V_116 = F_26 ( & V_107 [ V_61 ] , 1 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_61 += V_116 ;
if ( ( V_110 <= 1 ) && ( V_23 -> V_63 != 0xffff ) ) {
V_23 -> V_65 = V_110 ;
sprintf ( V_126 , L_187 , V_23 -> V_65 ) ;
} else {
sprintf ( V_126 , L_188 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_124 , L_189 ) ) {
V_116 = F_26 ( & V_107 [ V_61 ] , 4 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_61 += V_116 ;
if ( ( V_110 <= 4095 ) && ( ( V_23 -> V_63 != 0xffff ) ) ) {
V_23 -> V_66 = V_110 ;
if ( V_128 )
F_32 ( L_190 ) ;
if ( V_128 && V_23 -> V_60 )
F_32 ( L_180 ) ;
V_23 -> V_60 = 0 ;
sprintf ( V_126 , L_191 , V_23 -> V_66 ) ;
} else {
V_23 -> V_63 = 0xffff ;
V_23 -> V_66 = 0xffff ;
if ( V_128 )
F_32 ( L_182 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_124 , L_192 ) ) {
V_116 = F_26 ( & V_107 [ V_61 ] , 1 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_61 += V_116 ;
if ( ( V_110 <= 7 ) && ( V_23 -> V_66 != 0xffff ) ) {
V_23 -> V_67 = V_110 ;
sprintf ( V_126 , L_193 , V_23 -> V_67 ) ;
} else {
sprintf ( V_126 , L_194 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_124 , L_195 ) ) {
V_116 = F_26 ( & V_107 [ V_61 ] , 1 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_61 += V_116 ;
if ( ( V_110 <= 1 ) && ( V_23 -> V_66 != 0xffff ) ) {
V_23 -> V_68 = V_110 ;
sprintf ( V_126 , L_196 , V_23 -> V_68 ) ;
} else {
sprintf ( V_126 , L_197 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_124 , L_198 ) ) {
T_7 V_148 = 0 ;
V_116 = F_22 ( & V_107 [ V_61 ] , 2 , & V_148 ) ;
if ( V_116 < 0 )
return V_116 ;
V_61 += V_116 ;
if ( V_116 == 2 ) {
V_23 -> V_69 = V_148 ;
sprintf ( V_126 , L_199 , V_23 -> V_69 ) ;
} else {
sprintf ( V_126 , L_200 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_124 , L_201 ) ) {
T_7 V_148 = 0 ;
V_116 = F_22 ( & V_107 [ V_61 ] , 2 , & V_148 ) ;
if ( V_116 < 0 )
return V_116 ;
V_61 += V_116 ;
if ( V_116 == 2 ) {
V_23 -> V_70 = V_148 ;
sprintf ( V_126 , L_202 , V_23 -> V_70 ) ;
} else {
sprintf ( V_126 , L_203 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_124 , L_204 ) ) {
V_116 = F_26 ( & V_107 [ V_61 ] , 9 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_61 += V_116 ;
V_23 -> V_37 = V_110 ;
sprintf ( V_126 , L_205 ,
V_23 -> V_37 ) ;
return V_7 ;
}
sprintf ( V_23 -> V_106 , L_206 , V_124 ) ;
return - V_127 ;
}
static int F_40 ( struct V_21 * V_21 , struct V_5 * V_5 )
{
return F_12 ( V_5 , F_14 , F_13 ( V_21 ) ) ;
}
static int F_41 ( struct V_1 * V_2 , void * V_3 )
{
struct V_149 * V_150 = V_2 -> V_24 ;
const struct V_22 * V_23 ;
F_42 ( ! V_150 ) ;
F_15 ( V_2 , L_207 ) ;
F_43 ( V_150 ) ;
F_44 (pkt_dev, &t->if_list, list)
if ( V_23 -> V_88 )
F_15 ( V_2 , L_208 , V_23 -> V_32 ) ;
F_15 ( V_2 , L_209 ) ;
F_44 (pkt_dev, &t->if_list, list)
if ( ! V_23 -> V_88 )
F_15 ( V_2 , L_208 , V_23 -> V_32 ) ;
if ( V_150 -> V_106 [ 0 ] )
F_15 ( V_2 , L_210 , V_150 -> V_106 ) ;
else
F_15 ( V_2 , L_211 ) ;
F_45 ( V_150 ) ;
return 0 ;
}
static T_1 F_46 ( struct V_5 * V_5 ,
const char T_2 * V_107 ,
T_3 V_7 , T_4 * V_121 )
{
struct V_1 * V_2 = V_5 -> V_122 ;
struct V_149 * V_150 = V_2 -> V_24 ;
int V_61 , V_123 , V_116 , V_151 ;
char V_124 [ 40 ] ;
char * V_126 ;
if ( V_7 < 1 ) {
return - V_127 ;
}
V_123 = V_7 ;
V_116 = F_25 ( V_107 , V_123 ) ;
if ( V_116 < 0 )
return V_116 ;
V_61 = V_116 ;
V_116 = F_27 ( & V_107 [ V_61 ] , sizeof( V_124 ) - 1 ) ;
if ( V_116 < 0 )
return V_116 ;
memset ( V_124 , 0 , sizeof( V_124 ) ) ;
if ( F_6 ( V_124 , & V_107 [ V_61 ] , V_116 ) )
return - V_20 ;
V_61 += V_116 ;
V_123 = V_7 - V_61 ;
V_116 = F_25 ( & V_107 [ V_61 ] , V_123 ) ;
if ( V_116 < 0 )
return V_116 ;
V_61 += V_116 ;
if ( V_128 )
F_32 ( L_212 , V_124 , ( unsigned long ) V_7 ) ;
if ( ! V_150 ) {
F_47 ( L_213 ) ;
V_151 = - V_127 ;
goto V_19;
}
V_126 = & ( V_150 -> V_106 [ 0 ] ) ;
if ( ! strcmp ( V_124 , L_214 ) ) {
char V_138 [ 32 ] ;
memset ( V_138 , 0 , 32 ) ;
V_116 = F_27 ( & V_107 [ V_61 ] , sizeof( V_138 ) - 1 ) ;
if ( V_116 < 0 ) {
V_151 = V_116 ;
goto V_19;
}
if ( F_6 ( V_138 , & V_107 [ V_61 ] , V_116 ) )
return - V_20 ;
V_61 += V_116 ;
F_48 ( & V_152 ) ;
V_151 = F_49 ( V_150 , V_138 ) ;
F_50 ( & V_152 ) ;
if ( ! V_151 ) {
V_151 = V_7 ;
sprintf ( V_126 , L_215 , V_138 ) ;
} else
sprintf ( V_126 , L_216 , V_138 ) ;
goto V_19;
}
if ( ! strcmp ( V_124 , L_217 ) ) {
F_48 ( & V_152 ) ;
V_150 -> V_153 |= V_154 ;
F_50 ( & V_152 ) ;
F_51 ( F_52 ( 125 ) ) ;
V_151 = V_7 ;
sprintf ( V_126 , L_218 ) ;
goto V_19;
}
if ( ! strcmp ( V_124 , L_219 ) ) {
sprintf ( V_126 , L_220 ) ;
V_151 = V_7 ;
goto V_19;
}
V_151 = - V_127 ;
V_19:
return V_151 ;
}
static int F_53 ( struct V_21 * V_21 , struct V_5 * V_5 )
{
return F_12 ( V_5 , F_41 , F_13 ( V_21 ) ) ;
}
static struct V_22 * F_54 ( const struct V_11 * V_12 ,
const char * V_155 , int remove )
{
struct V_149 * V_150 ;
struct V_22 * V_23 = NULL ;
bool V_156 = ( remove == V_157 ) ;
F_44 (t, &pn->pktgen_threads, th_list) {
V_23 = F_55 ( V_150 , V_155 , V_156 ) ;
if ( V_23 ) {
if ( remove ) {
F_43 ( V_150 ) ;
V_23 -> V_158 = 1 ;
V_150 -> V_153 |= V_159 ;
F_45 ( V_150 ) ;
}
break;
}
}
return V_23 ;
}
static void F_56 ( const struct V_11 * V_12 , const char * V_155 )
{
struct V_22 * V_23 = NULL ;
const int V_160 = 10 , V_161 = 125 ;
int V_61 = 0 ;
F_48 ( & V_152 ) ;
F_32 ( L_221 , V_162 , V_155 ) ;
while ( 1 ) {
V_23 = F_54 ( V_12 , V_155 , REMOVE ) ;
if ( V_23 == NULL )
break;
F_50 ( & V_152 ) ;
F_32 ( L_222 ,
V_162 , V_155 ) ;
F_51 ( F_52 ( V_161 ) ) ;
F_48 ( & V_152 ) ;
if ( ++ V_61 >= V_160 ) {
F_47 ( L_223 ,
V_162 , V_161 * V_61 , V_155 ) ;
break;
}
}
F_50 ( & V_152 ) ;
}
static void F_57 ( const struct V_11 * V_12 , struct V_163 * V_164 )
{
struct V_149 * V_150 ;
F_44 (t, &pn->pktgen_threads, th_list) {
struct V_22 * V_23 ;
F_44 (pkt_dev, &t->if_list, list) {
if ( V_23 -> V_51 != V_164 )
continue;
F_58 ( V_23 -> V_165 ) ;
V_23 -> V_165 = F_59 ( V_164 -> V_124 , 0600 ,
V_12 -> V_166 ,
& V_167 ,
V_23 ) ;
if ( ! V_23 -> V_165 )
F_47 ( L_224 ,
V_164 -> V_124 ) ;
break;
}
}
}
static int F_60 ( struct V_168 * V_169 ,
unsigned long V_170 , void * V_171 )
{
struct V_163 * V_164 = F_61 ( V_171 ) ;
struct V_11 * V_12 = F_4 ( F_62 ( V_164 ) , V_16 ) ;
if ( V_12 -> V_172 )
return V_173 ;
switch ( V_170 ) {
case V_174 :
F_57 ( V_12 , V_164 ) ;
break;
case V_175 :
F_56 ( V_12 , V_164 -> V_124 ) ;
break;
}
return V_173 ;
}
static struct V_163 * F_63 ( const struct V_11 * V_12 ,
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
return F_64 ( V_12 -> V_178 , V_176 ) ;
}
static int F_65 ( const struct V_11 * V_12 ,
struct V_22 * V_23 , const char * V_155 )
{
struct V_163 * V_51 ;
int V_9 ;
if ( V_23 -> V_51 ) {
F_66 ( V_23 -> V_51 ) ;
V_23 -> V_51 = NULL ;
}
V_51 = F_63 ( V_12 , V_23 , V_155 ) ;
if ( ! V_51 ) {
F_47 ( L_225 , V_155 ) ;
return - V_179 ;
}
if ( V_51 -> type != V_180 ) {
F_47 ( L_226 , V_155 ) ;
V_9 = - V_127 ;
} else if ( ! F_67 ( V_51 ) ) {
F_47 ( L_227 , V_155 ) ;
V_9 = - V_181 ;
} else {
V_23 -> V_51 = V_51 ;
return 0 ;
}
F_66 ( V_51 ) ;
return V_9 ;
}
static void F_68 ( struct V_22 * V_23 )
{
int V_182 ;
if ( ! V_23 -> V_51 ) {
F_47 ( L_228 ) ;
sprintf ( V_23 -> V_106 ,
L_229 ) ;
return;
}
V_182 = V_23 -> V_51 -> V_183 ;
if ( V_182 <= V_23 -> V_35 ) {
F_10 ( L_230 ,
V_23 -> V_35 , ( V_182 ? : 1 ) - 1 , V_182 ,
V_23 -> V_32 ) ;
V_23 -> V_35 = ( V_182 ? : 1 ) - 1 ;
}
if ( V_23 -> V_36 >= V_182 ) {
F_10 ( L_231 ,
V_23 -> V_36 , ( V_182 ? : 1 ) - 1 , V_182 ,
V_23 -> V_32 ) ;
V_23 -> V_36 = ( V_182 ? : 1 ) - 1 ;
}
if ( F_16 ( V_23 -> V_50 ) )
memcpy ( & ( V_23 -> V_144 [ 6 ] ) , V_23 -> V_51 -> V_52 , V_145 ) ;
memcpy ( & ( V_23 -> V_144 [ 0 ] ) , V_23 -> V_53 , V_145 ) ;
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
if ( V_23 -> V_98 . V_141 [ V_61 ] ) {
V_184 = 1 ;
break;
}
if ( ! V_184 ) {
F_69 () ;
V_186 = F_70 ( V_23 -> V_51 ) ;
if ( V_186 ) {
struct V_192 * V_193 ;
F_71 ( & V_186 -> V_194 ) ;
F_44 (ifp, &idev->addr_list, if_list) {
if ( ( V_193 -> V_195 & V_196 ) &&
! ( V_193 -> V_38 & V_197 ) ) {
V_23 -> V_98 = V_193 -> V_198 ;
V_9 = 0 ;
break;
}
}
F_72 ( & V_186 -> V_194 ) ;
}
F_73 () ;
if ( V_9 )
F_47 ( L_232 ) ;
}
} else {
if ( V_23 -> V_27 == 0 ) {
V_23 -> V_27 = 14 + sizeof( struct V_199 )
+ sizeof( struct V_188 )
+ sizeof( struct V_189 )
+ V_23 -> V_190 ;
}
V_23 -> V_142 = 0 ;
V_23 -> V_143 = 0 ;
if ( strlen ( V_23 -> V_48 ) == 0 ) {
struct V_200 * V_201 ;
F_69 () ;
V_201 = F_74 ( V_23 -> V_51 ) ;
if ( V_201 ) {
if ( V_201 -> V_202 ) {
V_23 -> V_142 =
V_201 -> V_202 -> V_203 ;
V_23 -> V_143 = V_23 -> V_142 ;
}
}
F_73 () ;
} else {
V_23 -> V_142 = F_36 ( V_23 -> V_48 ) ;
V_23 -> V_143 = F_36 ( V_23 -> V_49 ) ;
}
V_23 -> V_139 = F_36 ( V_23 -> V_46 ) ;
V_23 -> V_140 = F_36 ( V_23 -> V_47 ) ;
}
V_23 -> V_131 = V_23 -> V_27 ;
if ( V_23 -> V_27 > V_23 -> V_28 )
V_23 -> V_28 = V_23 -> V_27 ;
V_23 -> V_96 = 0 ;
V_23 -> V_97 = 0 ;
V_23 -> V_100 = V_23 -> V_142 ;
V_23 -> V_101 = V_23 -> V_139 ;
V_23 -> V_102 = V_23 -> V_56 ;
V_23 -> V_103 = V_23 -> V_54 ;
V_23 -> V_105 = 0 ;
}
static void F_75 ( struct V_22 * V_23 , T_5 V_204 )
{
T_5 V_205 , V_206 ;
T_8 V_207 ;
struct V_208 V_150 ;
F_76 ( & V_150 . V_209 , V_210 , V_211 ) ;
F_77 ( & V_150 . V_209 , V_204 ) ;
V_207 = F_78 ( F_79 ( & V_150 . V_209 ) ) ;
if ( V_207 <= 0 ) {
V_23 -> V_212 = F_80 ( V_204 , V_23 -> V_30 ) ;
return;
}
V_205 = F_19 () ;
if ( V_207 < 100000 ) {
do {
V_206 = F_19 () ;
} while ( F_81 ( V_206 , V_204 ) < 0 );
} else {
F_82 ( & V_150 , V_13 ) ;
do {
F_83 ( V_213 ) ;
F_84 ( & V_150 . V_209 , V_211 ) ;
if ( ! F_85 ( & V_150 . V_209 ) )
V_150 . V_214 = NULL ;
if ( F_86 ( V_150 . V_214 ) )
F_87 () ;
F_88 ( & V_150 . V_209 ) ;
} while ( V_150 . V_214 && V_23 -> V_88 && ! F_89 ( V_13 ) );
F_90 ( V_215 ) ;
V_206 = F_19 () ;
}
V_23 -> V_90 += F_78 ( F_91 ( V_206 , V_205 ) ) ;
V_23 -> V_212 = F_80 ( V_204 , V_23 -> V_30 ) ;
}
static inline void F_92 ( struct V_22 * V_23 )
{
V_23 -> V_190 = 0 ;
V_23 -> V_190 += V_23 -> V_60 * sizeof( V_216 ) ;
V_23 -> V_190 += F_93 ( V_23 ) ;
V_23 -> V_190 += F_94 ( V_23 ) ;
}
static inline int F_95 ( const struct V_22 * V_23 , int V_217 )
{
return ! ! ( V_23 -> V_218 [ V_217 ] . V_38 & V_219 ) ;
}
static inline int F_96 ( struct V_22 * V_23 )
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
V_217 = F_97 () % V_23 -> V_33 ;
V_23 -> V_220 = V_217 ;
if ( V_23 -> V_218 [ V_217 ] . V_7 > V_23 -> V_34 ) {
V_23 -> V_218 [ V_217 ] . V_7 = 0 ;
V_23 -> V_218 [ V_217 ] . V_38 = 0 ;
}
}
return V_23 -> V_220 ;
}
static void F_98 ( struct V_22 * V_23 , int V_217 )
{
struct V_221 * V_222 = V_23 -> V_218 [ V_217 ] . V_222 ;
struct V_11 * V_12 = F_4 ( F_62 ( V_23 -> V_51 ) , V_16 ) ;
if ( ! V_222 ) {
V_222 = F_99 ( V_12 -> V_178 , V_223 ,
( V_224 * ) & V_23 -> V_101 ,
( V_224 * ) & V_23 -> V_100 ,
V_225 ,
V_23 -> V_226 ,
V_23 -> V_227 , 0 ) ;
if ( V_222 ) {
V_23 -> V_218 [ V_217 ] . V_222 = V_222 ;
F_92 ( V_23 ) ;
V_23 -> V_190 += V_222 -> V_228 . V_229 ;
}
}
}
static void F_100 ( struct V_22 * V_23 )
{
if ( V_23 -> V_38 & V_80 )
V_23 -> V_104 = F_101 () ;
else if ( V_23 -> V_35 <= V_23 -> V_36 ) {
T_9 V_150 ;
if ( V_23 -> V_38 & V_79 ) {
V_150 = F_97 () %
( V_23 -> V_36 -
V_23 -> V_35 + 1 )
+ V_23 -> V_35 ;
} else {
V_150 = V_23 -> V_104 + 1 ;
if ( V_150 > V_23 -> V_36 )
V_150 = V_23 -> V_35 ;
}
V_23 -> V_104 = V_150 ;
}
V_23 -> V_104 = V_23 -> V_104 % V_23 -> V_51 -> V_183 ;
}
static void F_102 ( struct V_22 * V_23 )
{
T_7 V_230 ;
T_7 V_231 ;
int V_217 = 0 ;
if ( V_23 -> V_33 )
V_217 = F_96 ( V_23 ) ;
if ( V_23 -> V_58 > 1 ) {
T_7 V_232 ;
T_7 V_117 ;
if ( V_23 -> V_38 & V_83 )
V_232 = F_97 () % V_23 -> V_58 ;
else {
V_232 = V_23 -> V_97 ++ ;
if ( V_23 -> V_97 >=
V_23 -> V_58 )
V_23 -> V_97 = 0 ;
}
V_117 = V_23 -> V_50 [ 5 ] + ( V_232 & 0xFF ) ;
V_23 -> V_144 [ 11 ] = V_117 ;
V_117 = ( V_23 -> V_50 [ 4 ] + ( ( V_232 >> 8 ) & 0xFF ) + ( V_117 >> 8 ) ) ;
V_23 -> V_144 [ 10 ] = V_117 ;
V_117 = ( V_23 -> V_50 [ 3 ] + ( ( V_232 >> 16 ) & 0xFF ) + ( V_117 >> 8 ) ) ;
V_23 -> V_144 [ 9 ] = V_117 ;
V_117 = ( V_23 -> V_50 [ 2 ] + ( ( V_232 >> 24 ) & 0xFF ) + ( V_117 >> 8 ) ) ;
V_23 -> V_144 [ 8 ] = V_117 ;
V_117 = ( V_23 -> V_50 [ 1 ] + ( V_117 >> 8 ) ) ;
V_23 -> V_144 [ 7 ] = V_117 ;
}
if ( V_23 -> V_59 > 1 ) {
T_7 V_232 ;
T_7 V_117 ;
if ( V_23 -> V_38 & V_84 )
V_232 = F_97 () % V_23 -> V_59 ;
else {
V_232 = V_23 -> V_96 ++ ;
if ( V_23 -> V_96 >=
V_23 -> V_59 ) {
V_23 -> V_96 = 0 ;
}
}
V_117 = V_23 -> V_53 [ 5 ] + ( V_232 & 0xFF ) ;
V_23 -> V_144 [ 5 ] = V_117 ;
V_117 = ( V_23 -> V_53 [ 4 ] + ( ( V_232 >> 8 ) & 0xFF ) + ( V_117 >> 8 ) ) ;
V_23 -> V_144 [ 4 ] = V_117 ;
V_117 = ( V_23 -> V_53 [ 3 ] + ( ( V_232 >> 16 ) & 0xFF ) + ( V_117 >> 8 ) ) ;
V_23 -> V_144 [ 3 ] = V_117 ;
V_117 = ( V_23 -> V_53 [ 2 ] + ( ( V_232 >> 24 ) & 0xFF ) + ( V_117 >> 8 ) ) ;
V_23 -> V_144 [ 2 ] = V_117 ;
V_117 = ( V_23 -> V_53 [ 1 ] + ( V_117 >> 8 ) ) ;
V_23 -> V_144 [ 1 ] = V_117 ;
}
if ( V_23 -> V_38 & V_78 ) {
unsigned int V_61 ;
for ( V_61 = 0 ; V_61 < V_23 -> V_60 ; V_61 ++ )
if ( V_23 -> V_62 [ V_61 ] & V_118 )
V_23 -> V_62 [ V_61 ] = V_118 |
( ( V_233 V_234 ) F_97 () &
F_29 ( 0x000fffff ) ) ;
}
if ( ( V_23 -> V_38 & V_85 ) && ( V_23 -> V_63 != 0xffff ) ) {
V_23 -> V_63 = F_97 () & ( 4096 - 1 ) ;
}
if ( ( V_23 -> V_38 & V_86 ) && ( V_23 -> V_66 != 0xffff ) ) {
V_23 -> V_66 = F_97 () & ( 4096 - 1 ) ;
}
if ( V_23 -> V_54 < V_23 -> V_55 ) {
if ( V_23 -> V_38 & V_75 )
V_23 -> V_103 = F_97 () %
( V_23 -> V_55 - V_23 -> V_54 )
+ V_23 -> V_54 ;
else {
V_23 -> V_103 ++ ;
if ( V_23 -> V_103 >= V_23 -> V_55 )
V_23 -> V_103 = V_23 -> V_54 ;
}
}
if ( V_23 -> V_56 < V_23 -> V_57 ) {
if ( V_23 -> V_38 & V_76 ) {
V_23 -> V_102 = F_97 () %
( V_23 -> V_57 - V_23 -> V_56 )
+ V_23 -> V_56 ;
} else {
V_23 -> V_102 ++ ;
if ( V_23 -> V_102 >= V_23 -> V_57 )
V_23 -> V_102 = V_23 -> V_56 ;
}
}
if ( ! ( V_23 -> V_38 & V_39 ) ) {
V_230 = F_17 ( V_23 -> V_142 ) ;
V_231 = F_17 ( V_23 -> V_143 ) ;
if ( V_230 < V_231 ) {
T_7 V_150 ;
if ( V_23 -> V_38 & V_72 )
V_150 = F_97 () % ( V_231 - V_230 ) + V_230 ;
else {
V_150 = F_17 ( V_23 -> V_100 ) ;
V_150 ++ ;
if ( V_150 > V_231 )
V_150 = V_230 ;
}
V_23 -> V_100 = F_29 ( V_150 ) ;
}
if ( V_23 -> V_33 && F_95 ( V_23 , V_217 ) ) {
V_23 -> V_101 = V_23 -> V_218 [ V_217 ] . V_101 ;
} else {
V_230 = F_17 ( V_23 -> V_139 ) ;
V_231 = F_17 ( V_23 -> V_140 ) ;
if ( V_230 < V_231 ) {
T_7 V_150 ;
V_234 V_235 ;
if ( V_23 -> V_38 & V_73 ) {
do {
V_150 = F_97 () %
( V_231 - V_230 ) + V_230 ;
V_235 = F_29 ( V_150 ) ;
} while ( F_103 ( V_235 ) ||
F_104 ( V_235 ) ||
F_105 ( V_235 ) ||
F_106 ( V_235 ) ||
F_107 ( V_235 ) );
V_23 -> V_101 = V_235 ;
} else {
V_150 = F_17 ( V_23 -> V_101 ) ;
V_150 ++ ;
if ( V_150 > V_231 ) {
V_150 = V_230 ;
}
V_23 -> V_101 = F_29 ( V_150 ) ;
}
}
if ( V_23 -> V_33 ) {
V_23 -> V_218 [ V_217 ] . V_38 |= V_219 ;
V_23 -> V_218 [ V_217 ] . V_101 =
V_23 -> V_101 ;
#ifdef F_18
if ( V_23 -> V_38 & V_82 )
F_98 ( V_23 , V_217 ) ;
#endif
V_23 -> V_105 ++ ;
}
}
} else {
if ( ! F_108 ( & V_23 -> V_44 ) ) {
int V_61 ;
for ( V_61 = 0 ; V_61 < 4 ; V_61 ++ ) {
V_23 -> V_99 . V_236 [ V_61 ] =
( ( ( V_233 V_234 ) F_97 () |
V_23 -> V_44 . V_236 [ V_61 ] ) &
V_23 -> V_45 . V_236 [ V_61 ] ) ;
}
}
}
if ( V_23 -> V_27 < V_23 -> V_28 ) {
T_7 V_150 ;
if ( V_23 -> V_38 & V_74 ) {
V_150 = F_97 () %
( V_23 -> V_28 - V_23 -> V_27 )
+ V_23 -> V_27 ;
} else {
V_150 = V_23 -> V_131 + 1 ;
if ( V_150 > V_23 -> V_28 )
V_150 = V_23 -> V_27 ;
}
V_23 -> V_131 = V_150 ;
}
F_100 ( V_23 ) ;
V_23 -> V_218 [ V_217 ] . V_7 ++ ;
}
static int F_109 ( struct V_237 * V_238 , struct V_22 * V_23 )
{
struct V_221 * V_222 = V_23 -> V_218 [ V_23 -> V_220 ] . V_222 ;
int V_9 = 0 ;
if ( ! V_222 )
return 0 ;
if ( V_222 -> V_228 . V_239 != V_240 )
return 0 ;
F_110 ( & V_222 -> V_194 ) ;
V_9 = V_222 -> V_241 -> V_242 ( V_222 , V_238 ) ;
if ( V_9 )
goto error;
V_9 = V_222 -> type -> V_242 ( V_222 , V_238 ) ;
if ( V_9 )
goto error;
V_222 -> V_243 . V_244 += V_238 -> V_116 ;
V_222 -> V_243 . V_245 ++ ;
error:
F_111 ( & V_222 -> V_194 ) ;
return V_9 ;
}
static void F_112 ( struct V_22 * V_23 )
{
if ( V_23 -> V_33 ) {
int V_61 ;
for ( V_61 = 0 ; V_61 < V_23 -> V_33 ; V_61 ++ ) {
struct V_221 * V_222 = V_23 -> V_218 [ V_61 ] . V_222 ;
if ( V_222 ) {
F_113 ( V_222 ) ;
V_23 -> V_218 [ V_61 ] . V_222 = NULL ;
}
}
}
}
static int F_114 ( struct V_22 * V_23 ,
struct V_237 * V_238 , T_10 V_246 )
{
if ( V_23 -> V_38 & V_82 ) {
struct V_221 * V_222 = V_23 -> V_218 [ V_23 -> V_220 ] . V_222 ;
int V_247 = 0 ;
if ( V_222 ) {
int V_151 ;
T_11 * V_248 ;
struct V_199 * V_249 ;
V_247 = V_222 -> V_228 . V_229 - F_115 ( V_238 ) ;
if ( V_247 > 0 ) {
V_151 = F_116 ( V_238 , V_247 , 0 , V_250 ) ;
if ( V_151 < 0 ) {
F_47 ( L_233 ,
V_151 ) ;
goto V_9;
}
}
F_117 ( V_238 , V_251 ) ;
V_151 = F_109 ( V_238 , V_23 ) ;
if ( V_151 ) {
F_47 ( L_234 , V_151 ) ;
goto V_9;
}
V_248 = ( T_11 * ) F_118 ( V_238 , V_251 ) ;
memcpy ( V_248 , V_23 -> V_144 , 12 ) ;
* ( V_252 * ) & V_248 [ 12 ] = V_246 ;
V_249 = F_119 ( V_238 ) ;
V_249 -> V_253 = F_120 ( V_238 -> V_116 - V_251 ) ;
F_121 ( V_249 ) ;
}
}
return 1 ;
V_9:
F_122 ( V_238 ) ;
return 0 ;
}
static void F_123 ( V_234 * V_254 , struct V_22 * V_23 )
{
unsigned int V_61 ;
for ( V_61 = 0 ; V_61 < V_23 -> V_60 ; V_61 ++ )
* V_254 ++ = V_23 -> V_62 [ V_61 ] & ~ V_118 ;
V_254 -- ;
* V_254 |= V_118 ;
}
static inline T_10 F_124 ( unsigned int V_255 , unsigned int V_256 ,
unsigned int V_257 )
{
return F_120 ( V_255 | ( V_256 << 12 ) | ( V_257 << 13 ) ) ;
}
static void F_125 ( struct V_22 * V_23 , struct V_237 * V_238 ,
int V_258 )
{
struct V_259 V_260 ;
struct V_189 * V_261 ;
V_261 = (struct V_189 * ) F_126 ( V_238 , sizeof( * V_261 ) ) ;
V_258 -= sizeof( * V_261 ) ;
if ( V_23 -> V_29 <= 0 ) {
memset ( F_126 ( V_238 , V_258 ) , 0 , V_258 ) ;
} else {
int V_262 = V_23 -> V_29 ;
int V_61 , V_116 ;
int V_263 ;
if ( V_262 > V_264 )
V_262 = V_264 ;
V_116 = V_258 - V_262 * V_265 ;
if ( V_116 > 0 ) {
memset ( F_126 ( V_238 , V_116 ) , 0 , V_116 ) ;
V_258 = V_262 * V_265 ;
}
V_61 = 0 ;
V_263 = ( V_258 / V_262 ) < V_265 ?
( V_258 / V_262 ) : V_265 ;
while ( V_258 > 0 ) {
if ( F_127 ( ! V_23 -> V_137 ) ) {
int V_71 = F_128 () ;
if ( V_23 -> V_71 >= 0 && ( V_23 -> V_38 & V_87 ) )
V_71 = V_23 -> V_71 ;
V_23 -> V_137 = F_129 ( V_71 , V_266 | V_267 , 0 ) ;
if ( ! V_23 -> V_137 )
break;
}
F_130 ( V_23 -> V_137 ) ;
F_131 ( V_238 , V_61 , V_23 -> V_137 ) ;
F_132 ( V_238 ) -> V_262 [ V_61 ] . V_268 = 0 ;
if ( V_61 == ( V_262 - 1 ) )
F_133 ( & F_132 ( V_238 ) -> V_262 [ V_61 ] ,
( V_258 < V_265 ? V_258 : V_265 ) ) ;
else
F_133 ( & F_132 ( V_238 ) -> V_262 [ V_61 ] , V_263 ) ;
V_258 -= F_134 ( & F_132 ( V_238 ) -> V_262 [ V_61 ] ) ;
V_238 -> V_116 += F_134 ( & F_132 ( V_238 ) -> V_262 [ V_61 ] ) ;
V_238 -> V_269 += F_134 ( & F_132 ( V_238 ) -> V_262 [ V_61 ] ) ;
V_61 ++ ;
F_132 ( V_238 ) -> V_270 = V_61 ;
}
}
V_261 -> V_271 = F_29 ( V_272 ) ;
V_261 -> V_95 = F_29 ( V_23 -> V_95 ) ;
F_135 ( & V_260 ) ;
V_261 -> V_273 = F_29 ( V_260 . V_273 ) ;
V_261 -> V_274 = F_29 ( V_260 . V_274 ) ;
}
static struct V_237 * F_136 ( struct V_163 * V_164 ,
struct V_22 * V_23 ,
unsigned int V_275 )
{
struct V_237 * V_238 = NULL ;
unsigned int V_276 = V_23 -> V_131 + 64 + V_275 +
V_23 -> V_190 ;
if ( V_23 -> V_38 & V_87 ) {
int V_71 = V_23 -> V_71 >= 0 ? V_23 -> V_71 : F_128 () ;
V_238 = F_137 ( V_277 + V_276 , V_278 , 0 , V_71 ) ;
if ( F_86 ( V_238 ) ) {
F_138 ( V_238 , V_277 ) ;
V_238 -> V_164 = V_164 ;
}
} else {
V_238 = F_139 ( V_164 , V_276 , V_278 ) ;
}
return V_238 ;
}
static struct V_237 * F_140 ( struct V_163 * V_51 ,
struct V_22 * V_23 )
{
struct V_237 * V_238 = NULL ;
T_11 * V_248 ;
struct V_188 * V_279 ;
int V_258 , V_280 ;
struct V_199 * V_249 ;
T_10 V_246 = F_120 ( V_281 ) ;
V_234 * V_254 ;
T_10 * V_282 = NULL ;
T_10 * V_283 = NULL ;
T_10 * V_284 = NULL ;
T_10 * V_285 = NULL ;
V_252 V_286 ;
if ( V_23 -> V_60 )
V_246 = F_120 ( V_287 ) ;
if ( V_23 -> V_63 != 0xffff )
V_246 = F_120 ( V_288 ) ;
F_102 ( V_23 ) ;
V_286 = V_23 -> V_104 ;
V_258 = ( V_51 -> V_289 + 16 ) & ~ 0xf ;
V_238 = F_136 ( V_51 , V_23 , V_258 ) ;
if ( ! V_238 ) {
sprintf ( V_23 -> V_106 , L_235 ) ;
return NULL ;
}
F_141 ( V_238 -> V_10 ) ;
F_138 ( V_238 , V_258 ) ;
V_248 = ( T_11 * ) F_118 ( V_238 , 14 ) ;
V_254 = ( V_234 * ) F_126 ( V_238 , V_23 -> V_60 * sizeof( T_7 ) ) ;
if ( V_23 -> V_60 )
F_123 ( V_254 , V_23 ) ;
if ( V_23 -> V_63 != 0xffff ) {
if ( V_23 -> V_66 != 0xffff ) {
V_284 = ( T_10 * ) F_126 ( V_238 , sizeof( T_10 ) ) ;
* V_284 = F_124 ( V_23 -> V_66 ,
V_23 -> V_68 ,
V_23 -> V_67 ) ;
V_285 = ( T_10 * ) F_126 ( V_238 , sizeof( T_10 ) ) ;
* V_285 = F_120 ( V_288 ) ;
}
V_282 = ( T_10 * ) F_126 ( V_238 , sizeof( T_10 ) ) ;
* V_282 = F_124 ( V_23 -> V_63 ,
V_23 -> V_65 ,
V_23 -> V_64 ) ;
V_283 = ( T_10 * ) F_126 ( V_238 , sizeof( T_10 ) ) ;
* V_283 = F_120 ( V_281 ) ;
}
F_142 ( V_238 , 0 ) ;
F_143 ( V_238 , V_238 -> V_116 ) ;
V_249 = (struct V_199 * ) F_126 ( V_238 , sizeof( struct V_199 ) ) ;
F_144 ( V_238 , V_238 -> V_116 ) ;
V_279 = (struct V_188 * ) F_126 ( V_238 , sizeof( struct V_188 ) ) ;
F_145 ( V_238 , V_286 ) ;
V_238 -> V_290 = V_23 -> V_37 ;
memcpy ( V_248 , V_23 -> V_144 , 12 ) ;
* ( T_10 * ) & V_248 [ 12 ] = V_246 ;
V_258 = V_23 -> V_131 - 14 - 20 - 8 -
V_23 -> V_190 ;
if ( V_258 < 0 || V_258 < sizeof( struct V_189 ) )
V_258 = sizeof( struct V_189 ) ;
V_279 -> V_291 = F_120 ( V_23 -> V_103 ) ;
V_279 -> V_292 = F_120 ( V_23 -> V_102 ) ;
V_279 -> V_116 = F_120 ( V_258 + 8 ) ;
V_279 -> V_293 = 0 ;
V_249 -> V_294 = 5 ;
V_249 -> V_4 = 4 ;
V_249 -> V_295 = 32 ;
V_249 -> V_69 = V_23 -> V_69 ;
V_249 -> V_246 = V_296 ;
V_249 -> V_297 = V_23 -> V_100 ;
V_249 -> V_298 = V_23 -> V_101 ;
V_249 -> V_255 = F_120 ( V_23 -> V_299 ) ;
V_23 -> V_299 ++ ;
V_249 -> V_300 = 0 ;
V_280 = 20 + 8 + V_258 ;
V_249 -> V_253 = F_120 ( V_280 ) ;
F_121 ( V_249 ) ;
V_238 -> V_246 = V_246 ;
V_238 -> V_164 = V_51 ;
V_238 -> V_301 = V_302 ;
if ( ! ( V_23 -> V_38 & V_77 ) ) {
V_238 -> V_303 = V_304 ;
} else if ( V_51 -> V_305 & V_306 ) {
V_238 -> V_303 = V_307 ;
V_238 -> V_308 = 0 ;
F_146 ( V_238 , V_279 -> V_291 , V_279 -> V_292 ) ;
} else {
T_12 V_308 = F_147 ( V_238 ) ;
V_279 -> V_293 = F_148 ( V_279 -> V_291 , V_279 -> V_292 ,
V_258 + 8 , V_296 , V_308 ) ;
if ( V_279 -> V_293 == 0 )
V_279 -> V_293 = V_309 ;
}
F_125 ( V_23 , V_238 , V_258 ) ;
#ifdef F_18
if ( ! F_114 ( V_23 , V_238 , V_246 ) )
return NULL ;
#endif
return V_238 ;
}
static struct V_237 * F_149 ( struct V_163 * V_51 ,
struct V_22 * V_23 )
{
struct V_237 * V_238 = NULL ;
T_11 * V_248 ;
struct V_188 * V_279 ;
int V_258 , V_310 ;
struct V_187 * V_249 ;
T_10 V_246 = F_120 ( V_311 ) ;
V_234 * V_254 ;
T_10 * V_282 = NULL ;
T_10 * V_283 = NULL ;
T_10 * V_284 = NULL ;
T_10 * V_285 = NULL ;
V_252 V_286 ;
if ( V_23 -> V_60 )
V_246 = F_120 ( V_287 ) ;
if ( V_23 -> V_63 != 0xffff )
V_246 = F_120 ( V_288 ) ;
F_102 ( V_23 ) ;
V_286 = V_23 -> V_104 ;
V_238 = F_136 ( V_51 , V_23 , 16 ) ;
if ( ! V_238 ) {
sprintf ( V_23 -> V_106 , L_235 ) ;
return NULL ;
}
F_141 ( V_238 -> V_10 ) ;
F_138 ( V_238 , 16 ) ;
V_248 = ( T_11 * ) F_118 ( V_238 , 14 ) ;
V_254 = ( V_234 * ) F_126 ( V_238 , V_23 -> V_60 * sizeof( T_7 ) ) ;
if ( V_23 -> V_60 )
F_123 ( V_254 , V_23 ) ;
if ( V_23 -> V_63 != 0xffff ) {
if ( V_23 -> V_66 != 0xffff ) {
V_284 = ( T_10 * ) F_126 ( V_238 , sizeof( T_10 ) ) ;
* V_284 = F_124 ( V_23 -> V_66 ,
V_23 -> V_68 ,
V_23 -> V_67 ) ;
V_285 = ( T_10 * ) F_126 ( V_238 , sizeof( T_10 ) ) ;
* V_285 = F_120 ( V_288 ) ;
}
V_282 = ( T_10 * ) F_126 ( V_238 , sizeof( T_10 ) ) ;
* V_282 = F_124 ( V_23 -> V_63 ,
V_23 -> V_65 ,
V_23 -> V_64 ) ;
V_283 = ( T_10 * ) F_126 ( V_238 , sizeof( T_10 ) ) ;
* V_283 = F_120 ( V_311 ) ;
}
F_142 ( V_238 , 0 ) ;
F_143 ( V_238 , V_238 -> V_116 ) ;
V_249 = (struct V_187 * ) F_126 ( V_238 , sizeof( struct V_187 ) ) ;
F_144 ( V_238 , V_238 -> V_116 ) ;
V_279 = (struct V_188 * ) F_126 ( V_238 , sizeof( struct V_188 ) ) ;
F_145 ( V_238 , V_286 ) ;
V_238 -> V_290 = V_23 -> V_37 ;
memcpy ( V_248 , V_23 -> V_144 , 12 ) ;
* ( T_10 * ) & V_248 [ 12 ] = V_246 ;
V_258 = V_23 -> V_131 - 14 -
sizeof( struct V_187 ) - sizeof( struct V_188 ) -
V_23 -> V_190 ;
if ( V_258 < 0 || V_258 < sizeof( struct V_189 ) ) {
V_258 = sizeof( struct V_189 ) ;
F_150 ( L_236 , V_258 ) ;
}
V_310 = V_258 + sizeof( struct V_188 ) ;
V_279 -> V_291 = F_120 ( V_23 -> V_103 ) ;
V_279 -> V_292 = F_120 ( V_23 -> V_102 ) ;
V_279 -> V_116 = F_120 ( V_310 ) ;
V_279 -> V_293 = 0 ;
* ( V_234 * ) V_249 = F_29 ( 0x60000000 ) ;
if ( V_23 -> V_70 ) {
* ( V_234 * ) V_249 |= F_29 ( 0x60000000 | ( V_23 -> V_70 << 20 ) ) ;
}
V_249 -> V_312 = 32 ;
V_249 -> V_313 = F_120 ( V_310 ) ;
V_249 -> V_314 = V_296 ;
V_249 -> V_298 = V_23 -> V_99 ;
V_249 -> V_297 = V_23 -> V_98 ;
V_238 -> V_246 = V_246 ;
V_238 -> V_164 = V_51 ;
V_238 -> V_301 = V_302 ;
if ( ! ( V_23 -> V_38 & V_77 ) ) {
V_238 -> V_303 = V_304 ;
} else if ( V_51 -> V_305 & V_315 ) {
V_238 -> V_303 = V_307 ;
V_238 -> V_316 = F_151 ( V_238 ) - V_238 -> V_317 ;
V_238 -> V_318 = F_152 ( struct V_188 , V_293 ) ;
V_279 -> V_293 = ~ F_153 ( & V_249 -> V_297 , & V_249 -> V_298 , V_310 , V_296 , 0 ) ;
} else {
T_12 V_308 = F_147 ( V_238 ) ;
V_279 -> V_293 = F_153 ( & V_249 -> V_297 , & V_249 -> V_298 , V_310 , V_296 , V_308 ) ;
if ( V_279 -> V_293 == 0 )
V_279 -> V_293 = V_309 ;
}
F_125 ( V_23 , V_238 , V_258 ) ;
return V_238 ;
}
static struct V_237 * F_154 ( struct V_163 * V_51 ,
struct V_22 * V_23 )
{
if ( V_23 -> V_38 & V_39 )
return F_149 ( V_51 , V_23 ) ;
else
return F_140 ( V_51 , V_23 ) ;
}
static void F_39 ( struct V_22 * V_23 )
{
V_23 -> V_95 = 1 ;
V_23 -> V_90 = 0 ;
V_23 -> V_92 = 0 ;
V_23 -> V_319 = 0 ;
V_23 -> V_93 = 0 ;
}
static void F_155 ( struct V_149 * V_150 )
{
struct V_22 * V_23 ;
int V_320 = 0 ;
F_156 () ;
F_43 ( V_150 ) ;
F_44 (pkt_dev, &t->if_list, list) {
F_68 ( V_23 ) ;
if ( V_23 -> V_51 ) {
F_39 ( V_23 ) ;
V_23 -> V_88 = 1 ;
V_23 -> V_238 = NULL ;
V_23 -> V_94 = V_23 -> V_212 = F_19 () ;
F_92 ( V_23 ) ;
strcpy ( V_23 -> V_106 , L_237 ) ;
V_320 ++ ;
} else
strcpy ( V_23 -> V_106 , L_238 ) ;
}
F_45 ( V_150 ) ;
if ( V_320 )
V_150 -> V_153 &= ~ ( V_321 ) ;
}
static void F_7 ( struct V_11 * V_12 )
{
struct V_149 * V_150 ;
F_156 () ;
F_48 ( & V_152 ) ;
F_44 (t, &pn->pktgen_threads, th_list)
V_150 -> V_153 |= V_321 ;
F_50 ( & V_152 ) ;
}
static int F_157 ( const struct V_149 * V_150 )
{
const struct V_22 * V_23 ;
F_44 (pkt_dev, &t->if_list, list)
if ( V_23 -> V_88 )
return 1 ;
return 0 ;
}
static int F_158 ( struct V_149 * V_150 )
{
F_43 ( V_150 ) ;
while ( F_157 ( V_150 ) ) {
F_45 ( V_150 ) ;
F_159 ( 100 ) ;
if ( F_89 ( V_13 ) )
goto signal;
F_43 ( V_150 ) ;
}
F_45 ( V_150 ) ;
return 1 ;
signal:
return 0 ;
}
static int F_160 ( struct V_11 * V_12 )
{
struct V_149 * V_150 ;
int V_322 = 1 ;
F_48 ( & V_152 ) ;
F_44 (t, &pn->pktgen_threads, th_list) {
V_322 = F_158 ( V_150 ) ;
if ( V_322 == 0 )
break;
}
if ( V_322 == 0 )
F_44 (t, &pn->pktgen_threads, th_list)
V_150 -> V_153 |= ( V_321 ) ;
F_50 ( & V_152 ) ;
return V_322 ;
}
static void F_8 ( struct V_11 * V_12 )
{
struct V_149 * V_150 ;
F_156 () ;
F_48 ( & V_152 ) ;
F_44 (t, &pn->pktgen_threads, th_list)
V_150 -> V_153 |= ( V_323 ) ;
F_50 ( & V_152 ) ;
F_51 ( F_52 ( 125 ) ) ;
F_160 ( V_12 ) ;
}
static void F_9 ( struct V_11 * V_12 )
{
struct V_149 * V_150 ;
F_156 () ;
F_48 ( & V_152 ) ;
F_44 (t, &pn->pktgen_threads, th_list)
V_150 -> V_153 |= ( V_154 ) ;
F_50 ( & V_152 ) ;
F_51 ( F_52 ( 125 ) ) ;
F_160 ( V_12 ) ;
}
static void F_161 ( struct V_22 * V_23 , int V_270 )
{
T_13 V_324 , V_325 , V_326 ;
char * V_327 = V_23 -> V_106 ;
T_5 V_328 = F_91 ( V_23 -> V_89 ,
V_23 -> V_94 ) ;
T_5 V_26 = F_162 ( V_23 -> V_90 ) ;
V_327 += sprintf ( V_327 , L_239 ,
( unsigned long long ) F_21 ( V_328 ) ,
( unsigned long long ) F_21 ( F_91 ( V_328 , V_26 ) ) ,
( unsigned long long ) F_21 ( V_26 ) ,
( unsigned long long ) V_23 -> V_92 ,
V_23 -> V_131 , V_270 ) ;
V_326 = F_163 ( V_23 -> V_92 * V_133 ,
F_78 ( V_328 ) ) ;
V_324 = V_326 * 8 * V_23 -> V_131 ;
V_325 = V_324 ;
F_20 ( V_325 , 1000000 ) ;
V_327 += sprintf ( V_327 , L_240 ,
( unsigned long long ) V_326 ,
( unsigned long long ) V_325 ,
( unsigned long long ) V_324 ,
( unsigned long long ) V_23 -> V_93 ) ;
}
static int F_164 ( struct V_22 * V_23 )
{
int V_270 = V_23 -> V_238 ? F_132 ( V_23 -> V_238 ) -> V_270 : - 1 ;
if ( ! V_23 -> V_88 ) {
F_10 ( L_241 ,
V_23 -> V_32 ) ;
return - V_127 ;
}
F_122 ( V_23 -> V_238 ) ;
V_23 -> V_238 = NULL ;
V_23 -> V_89 = F_19 () ;
V_23 -> V_88 = 0 ;
F_161 ( V_23 , V_270 ) ;
return 0 ;
}
static struct V_22 * F_165 ( struct V_149 * V_150 )
{
struct V_22 * V_23 , * V_329 = NULL ;
F_43 ( V_150 ) ;
F_44 (pkt_dev, &t->if_list, list) {
if ( ! V_23 -> V_88 )
continue;
if ( V_329 == NULL )
V_329 = V_23 ;
else if ( F_81 ( V_23 -> V_212 , V_329 -> V_212 ) < 0 )
V_329 = V_23 ;
}
F_45 ( V_150 ) ;
return V_329 ;
}
static void F_166 ( struct V_149 * V_150 )
{
struct V_22 * V_23 ;
F_156 () ;
F_43 ( V_150 ) ;
F_44 (pkt_dev, &t->if_list, list) {
F_164 ( V_23 ) ;
}
F_45 ( V_150 ) ;
}
static void F_167 ( struct V_149 * V_150 )
{
struct V_330 * V_331 , * V_115 ;
struct V_22 * V_332 ;
F_156 () ;
F_43 ( V_150 ) ;
F_168 (q, n, &t->if_list) {
V_332 = F_169 ( V_331 , struct V_22 , V_333 ) ;
if ( ! V_332 -> V_158 )
continue;
F_122 ( V_332 -> V_238 ) ;
V_332 -> V_238 = NULL ;
F_170 ( V_150 , V_332 ) ;
break;
}
F_45 ( V_150 ) ;
}
static void F_171 ( struct V_149 * V_150 )
{
struct V_330 * V_331 , * V_115 ;
struct V_22 * V_332 ;
F_156 () ;
F_43 ( V_150 ) ;
F_168 (q, n, &t->if_list) {
V_332 = F_169 ( V_331 , struct V_22 , V_333 ) ;
F_122 ( V_332 -> V_238 ) ;
V_332 -> V_238 = NULL ;
F_170 ( V_150 , V_332 ) ;
}
F_45 ( V_150 ) ;
}
static void F_172 ( struct V_149 * V_150 )
{
F_173 ( V_150 -> V_334 -> V_335 , V_150 -> V_178 -> V_166 ) ;
}
static void F_174 ( struct V_22 * V_23 )
{
T_5 V_336 = F_19 () ;
F_87 () ;
V_23 -> V_90 += F_78 ( F_91 ( F_19 () , V_336 ) ) ;
}
static void F_175 ( struct V_22 * V_23 )
{
T_5 V_336 = F_19 () ;
while ( F_176 ( & ( V_23 -> V_238 -> V_337 ) ) != 1 ) {
if ( F_89 ( V_13 ) )
break;
if ( F_177 () )
F_174 ( V_23 ) ;
else
F_178 () ;
}
V_23 -> V_90 += F_78 ( F_91 ( F_19 () , V_336 ) ) ;
}
static void F_179 ( struct V_22 * V_23 )
{
struct V_163 * V_51 = V_23 -> V_51 ;
T_14 (* F_180)( struct V_237 * , struct V_163 * )
= V_51 -> V_338 -> V_339 ;
struct V_340 * V_341 ;
V_252 V_286 ;
int V_151 ;
if ( F_127 ( ! F_67 ( V_51 ) || ! F_181 ( V_51 ) ) ) {
F_164 ( V_23 ) ;
return;
}
if ( F_127 ( V_23 -> V_30 == V_132 ) ) {
V_23 -> V_212 = F_80 ( F_19 () , V_342 ) ;
return;
}
if ( ! V_23 -> V_238 || ( V_23 -> V_343 &&
++ V_23 -> V_344 >= V_23 -> V_31 ) ) {
F_122 ( V_23 -> V_238 ) ;
V_23 -> V_238 = F_154 ( V_51 , V_23 ) ;
if ( V_23 -> V_238 == NULL ) {
F_47 ( L_242 ) ;
F_87 () ;
V_23 -> V_344 -- ;
return;
}
V_23 -> V_345 = V_23 -> V_238 -> V_116 ;
V_23 -> V_346 ++ ;
V_23 -> V_344 = 0 ;
}
if ( V_23 -> V_30 && V_23 -> V_343 )
F_75 ( V_23 , V_23 -> V_212 ) ;
V_286 = F_182 ( V_23 -> V_238 ) ;
V_341 = F_183 ( V_51 , V_286 ) ;
F_184 ( V_341 ) ;
if ( F_127 ( F_185 ( V_341 ) ) ) {
V_151 = V_347 ;
V_23 -> V_343 = 0 ;
goto V_348;
}
F_186 ( & ( V_23 -> V_238 -> V_337 ) ) ;
V_151 = (* F_180)( V_23 -> V_238 , V_51 ) ;
switch ( V_151 ) {
case V_349 :
F_187 ( V_341 ) ;
V_23 -> V_343 = 1 ;
V_23 -> V_92 ++ ;
V_23 -> V_95 ++ ;
V_23 -> V_319 += V_23 -> V_345 ;
break;
case V_350 :
case V_351 :
case V_352 :
V_23 -> V_93 ++ ;
break;
default:
F_150 ( L_243 ,
V_23 -> V_32 , V_151 ) ;
V_23 -> V_93 ++ ;
case V_353 :
case V_347 :
F_188 ( & ( V_23 -> V_238 -> V_337 ) ) ;
V_23 -> V_343 = 0 ;
}
V_348:
F_189 ( V_341 ) ;
if ( ( V_23 -> V_7 != 0 ) && ( V_23 -> V_92 >= V_23 -> V_7 ) ) {
F_175 ( V_23 ) ;
F_164 ( V_23 ) ;
}
}
static int F_190 ( void * V_354 )
{
F_191 ( V_355 ) ;
struct V_149 * V_150 = V_354 ;
struct V_22 * V_23 = NULL ;
int V_356 = V_150 -> V_356 ;
F_42 ( F_101 () != V_356 ) ;
F_192 ( & V_150 -> V_357 ) ;
F_193 ( & V_150 -> V_358 ) ;
F_32 ( L_244 , V_356 , F_194 ( V_13 ) ) ;
F_83 ( V_213 ) ;
F_195 () ;
while ( ! F_196 () ) {
V_23 = F_165 ( V_150 ) ;
if ( F_127 ( ! V_23 && V_150 -> V_153 == 0 ) ) {
if ( V_150 -> V_178 -> V_172 )
break;
F_197 ( V_150 -> V_357 ,
V_150 -> V_153 != 0 ,
V_359 / 10 ) ;
F_198 () ;
continue;
}
F_90 ( V_215 ) ;
if ( F_86 ( V_23 ) ) {
F_179 ( V_23 ) ;
if ( F_177 () )
F_174 ( V_23 ) ;
else
F_178 () ;
}
if ( V_150 -> V_153 & V_321 ) {
F_166 ( V_150 ) ;
V_150 -> V_153 &= ~ ( V_321 ) ;
}
if ( V_150 -> V_153 & V_323 ) {
F_155 ( V_150 ) ;
V_150 -> V_153 &= ~ ( V_323 ) ;
}
if ( V_150 -> V_153 & V_154 ) {
F_171 ( V_150 ) ;
V_150 -> V_153 &= ~ ( V_154 ) ;
}
if ( V_150 -> V_153 & V_159 ) {
F_167 ( V_150 ) ;
V_150 -> V_153 &= ~ ( V_159 ) ;
}
F_198 () ;
F_83 ( V_213 ) ;
}
F_32 ( L_245 , V_150 -> V_334 -> V_335 ) ;
F_166 ( V_150 ) ;
F_32 ( L_246 , V_150 -> V_334 -> V_335 ) ;
F_171 ( V_150 ) ;
F_32 ( L_247 , V_150 -> V_334 -> V_335 ) ;
F_172 ( V_150 ) ;
while ( ! F_196 () ) {
F_83 ( V_213 ) ;
F_87 () ;
}
F_90 ( V_215 ) ;
return 0 ;
}
static struct V_22 * F_55 ( struct V_149 * V_150 ,
const char * V_155 , bool V_156 )
{
struct V_22 * V_327 , * V_23 = NULL ;
T_3 V_116 = strlen ( V_155 ) ;
F_43 ( V_150 ) ;
F_44 (p, &t->if_list, list)
if ( strncmp ( V_327 -> V_32 , V_155 , V_116 ) == 0 ) {
if ( V_327 -> V_32 [ V_116 ] ) {
if ( V_156 || V_327 -> V_32 [ V_116 ] != '@' )
continue;
}
V_23 = V_327 ;
break;
}
F_45 ( V_150 ) ;
F_32 ( L_248 , V_155 , V_23 ) ;
return V_23 ;
}
static int F_199 ( struct V_149 * V_150 ,
struct V_22 * V_23 )
{
int V_360 = 0 ;
F_43 ( V_150 ) ;
if ( V_23 -> V_361 ) {
F_47 ( L_249 ) ;
V_360 = - V_362 ;
goto V_19;
}
F_200 ( & V_23 -> V_333 , & V_150 -> V_363 ) ;
V_23 -> V_361 = V_150 ;
V_23 -> V_88 = 0 ;
V_19:
F_45 ( V_150 ) ;
return V_360 ;
}
static int F_49 ( struct V_149 * V_150 , const char * V_155 )
{
struct V_22 * V_23 ;
int V_9 ;
int V_71 = F_201 ( V_150 -> V_356 ) ;
V_23 = F_54 ( V_150 -> V_178 , V_155 , V_157 ) ;
if ( V_23 ) {
F_47 ( L_250 ) ;
return - V_362 ;
}
V_23 = F_202 ( sizeof( struct V_22 ) , V_266 , V_71 ) ;
if ( ! V_23 )
return - V_364 ;
strcpy ( V_23 -> V_32 , V_155 ) ;
V_23 -> V_218 = F_203 ( V_146 * sizeof( struct V_365 ) ,
V_71 ) ;
if ( V_23 -> V_218 == NULL ) {
F_204 ( V_23 ) ;
return - V_364 ;
}
V_23 -> V_158 = 0 ;
V_23 -> V_29 = 0 ;
V_23 -> V_30 = V_366 ;
V_23 -> V_7 = V_367 ;
V_23 -> V_92 = 0 ;
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
V_9 = F_65 ( V_150 -> V_178 , V_23 , V_155 ) ;
if ( V_9 )
goto V_368;
if ( V_23 -> V_51 -> V_134 & V_135 )
V_23 -> V_31 = V_369 ;
V_23 -> V_165 = F_59 ( V_155 , 0600 , V_150 -> V_178 -> V_166 ,
& V_167 , V_23 ) ;
if ( ! V_23 -> V_165 ) {
F_47 ( L_251 ,
V_370 , V_155 ) ;
V_9 = - V_127 ;
goto V_371;
}
#ifdef F_18
V_23 -> V_226 = V_240 ;
V_23 -> V_227 = V_372 ;
#endif
return F_199 ( V_150 , V_23 ) ;
V_371:
F_66 ( V_23 -> V_51 ) ;
V_368:
#ifdef F_18
F_112 ( V_23 ) ;
#endif
F_205 ( V_23 -> V_218 ) ;
F_204 ( V_23 ) ;
return V_9 ;
}
static int T_15 F_206 ( int V_356 , struct V_11 * V_12 )
{
struct V_149 * V_150 ;
struct V_373 * V_374 ;
struct V_375 * V_327 ;
V_150 = F_202 ( sizeof( struct V_149 ) , V_266 ,
F_201 ( V_356 ) ) ;
if ( ! V_150 ) {
F_47 ( L_252 ) ;
return - V_364 ;
}
F_207 ( & V_150 -> F_43 ) ;
V_150 -> V_356 = V_356 ;
F_208 ( & V_150 -> V_363 ) ;
F_209 ( & V_150 -> V_376 , & V_12 -> V_377 ) ;
F_210 ( & V_150 -> V_358 ) ;
V_327 = F_211 ( F_190 ,
V_150 ,
F_201 ( V_356 ) ,
L_253 , V_356 ) ;
if ( F_212 ( V_327 ) ) {
F_47 ( L_254 , V_150 -> V_356 ) ;
F_213 ( & V_150 -> V_376 ) ;
F_204 ( V_150 ) ;
return F_214 ( V_327 ) ;
}
F_215 ( V_327 , V_356 ) ;
V_150 -> V_334 = V_327 ;
V_374 = F_59 ( V_150 -> V_334 -> V_335 , 0600 , V_12 -> V_166 ,
& V_378 , V_150 ) ;
if ( ! V_374 ) {
F_47 ( L_251 ,
V_370 , V_150 -> V_334 -> V_335 ) ;
F_216 ( V_327 ) ;
F_213 ( & V_150 -> V_376 ) ;
F_204 ( V_150 ) ;
return - V_127 ;
}
V_150 -> V_178 = V_12 ;
F_217 ( V_327 ) ;
F_218 ( & V_150 -> V_358 ) ;
return 0 ;
}
static void F_219 ( struct V_149 * V_150 ,
struct V_22 * V_23 )
{
struct V_330 * V_331 , * V_115 ;
struct V_22 * V_327 ;
F_168 (q, n, &t->if_list) {
V_327 = F_169 ( V_331 , struct V_22 , V_333 ) ;
if ( V_327 == V_23 )
F_213 ( & V_327 -> V_333 ) ;
}
}
static int F_170 ( struct V_149 * V_150 ,
struct V_22 * V_23 )
{
F_32 ( L_255 , V_23 ) ;
if ( V_23 -> V_88 ) {
F_10 ( L_256 ) ;
F_164 ( V_23 ) ;
}
if ( V_23 -> V_51 ) {
F_66 ( V_23 -> V_51 ) ;
V_23 -> V_51 = NULL ;
}
F_219 ( V_150 , V_23 ) ;
if ( V_23 -> V_165 )
F_58 ( V_23 -> V_165 ) ;
#ifdef F_18
F_112 ( V_23 ) ;
#endif
F_205 ( V_23 -> V_218 ) ;
if ( V_23 -> V_137 )
F_35 ( V_23 -> V_137 ) ;
F_204 ( V_23 ) ;
return 0 ;
}
static int T_15 F_220 ( struct V_178 * V_178 )
{
struct V_11 * V_12 = F_4 ( V_178 , V_16 ) ;
struct V_373 * V_374 ;
int V_356 , V_151 = 0 ;
V_12 -> V_178 = V_178 ;
F_208 ( & V_12 -> V_377 ) ;
V_12 -> V_172 = false ;
V_12 -> V_166 = F_221 ( V_370 , V_12 -> V_178 -> V_379 ) ;
if ( ! V_12 -> V_166 ) {
F_222 ( L_257 , V_370 ) ;
return - V_179 ;
}
V_374 = F_223 ( V_380 , 0600 , V_12 -> V_166 , & V_381 ) ;
if ( V_374 == NULL ) {
F_47 ( L_258 , V_380 ) ;
V_151 = - V_127 ;
goto remove;
}
F_224 (cpu) {
int V_9 ;
V_9 = F_206 ( V_356 , V_12 ) ;
if ( V_9 )
F_222 ( L_259 ,
V_356 , V_9 ) ;
}
if ( F_225 ( & V_12 -> V_377 ) ) {
F_47 ( L_260 ) ;
V_151 = - V_179 ;
goto V_382;
}
return 0 ;
V_382:
F_173 ( V_380 , V_12 -> V_166 ) ;
remove:
F_173 ( V_370 , V_12 -> V_178 -> V_379 ) ;
return V_151 ;
}
static void T_16 F_226 ( struct V_178 * V_178 )
{
struct V_11 * V_12 = F_4 ( V_178 , V_16 ) ;
struct V_149 * V_150 ;
struct V_330 * V_331 , * V_115 ;
F_227 ( V_333 ) ;
V_12 -> V_172 = true ;
F_48 ( & V_152 ) ;
F_228 ( & V_12 -> V_377 , & V_333 ) ;
F_50 ( & V_152 ) ;
F_168 (q, n, &list) {
V_150 = F_169 ( V_331 , struct V_149 , V_376 ) ;
F_213 ( & V_150 -> V_376 ) ;
F_216 ( V_150 -> V_334 ) ;
F_204 ( V_150 ) ;
}
F_173 ( V_380 , V_12 -> V_166 ) ;
F_173 ( V_370 , V_12 -> V_178 -> V_379 ) ;
}
static int T_17 F_229 ( void )
{
int V_151 = 0 ;
F_33 ( L_261 , V_4 ) ;
V_151 = F_230 ( & V_383 ) ;
if ( V_151 )
return V_151 ;
V_151 = F_231 ( & V_384 ) ;
if ( V_151 )
F_232 ( & V_383 ) ;
return V_151 ;
}
static void T_18 F_233 ( void )
{
F_234 ( & V_384 ) ;
F_232 ( & V_383 ) ;
}
