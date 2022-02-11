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
if ( V_23 -> V_33 ) {
if ( V_23 -> V_38 & V_80 )
F_15 ( V_2 , L_40 ) ;
else
F_15 ( V_2 , L_41 ) ;
}
#ifdef F_18
if ( V_23 -> V_38 & V_81 )
F_15 ( V_2 , L_42 ) ;
#endif
if ( V_23 -> V_38 & V_82 )
F_15 ( V_2 , L_43 ) ;
if ( V_23 -> V_38 & V_83 )
F_15 ( V_2 , L_44 ) ;
if ( V_23 -> V_38 & V_84 )
F_15 ( V_2 , L_45 ) ;
if ( V_23 -> V_38 & V_85 )
F_15 ( V_2 , L_46 ) ;
if ( V_23 -> V_38 & V_86 )
F_15 ( V_2 , L_47 ) ;
F_2 ( V_2 , L_23 ) ;
V_25 = V_23 -> V_87 ? F_19 () : V_23 -> V_88 ;
V_26 = V_23 -> V_89 ;
F_20 ( V_26 , V_90 ) ;
F_15 ( V_2 ,
L_48 ,
( unsigned long long ) V_23 -> V_91 ,
( unsigned long long ) V_23 -> V_92 ) ;
F_15 ( V_2 ,
L_49 ,
( unsigned long long ) F_21 ( V_23 -> V_93 ) ,
( unsigned long long ) F_21 ( V_25 ) ,
( unsigned long long ) V_26 ) ;
F_15 ( V_2 ,
L_50 ,
V_23 -> V_94 , V_23 -> V_95 ,
V_23 -> V_96 ) ;
if ( V_23 -> V_38 & V_39 ) {
F_15 ( V_2 , L_51 ,
& V_23 -> V_97 ,
& V_23 -> V_98 ) ;
} else
F_15 ( V_2 , L_52 ,
& V_23 -> V_99 , & V_23 -> V_100 ) ;
F_15 ( V_2 , L_53 ,
V_23 -> V_101 , V_23 -> V_102 ) ;
F_15 ( V_2 , L_54 , V_23 -> V_103 ) ;
F_15 ( V_2 , L_55 , V_23 -> V_104 ) ;
if ( V_23 -> V_105 [ 0 ] )
F_15 ( V_2 , L_56 , V_23 -> V_105 ) ;
else
F_15 ( V_2 , L_57 ) ;
return 0 ;
}
static int F_22 ( const char T_2 * V_106 , unsigned long V_107 ,
T_7 * V_108 )
{
int V_61 = 0 ;
* V_108 = 0 ;
for (; V_61 < V_107 ; V_61 ++ ) {
int V_109 ;
char V_110 ;
* V_108 <<= 4 ;
if ( F_23 ( V_110 , & V_106 [ V_61 ] ) )
return - V_20 ;
V_109 = F_24 ( V_110 ) ;
if ( V_109 >= 0 )
* V_108 |= V_109 ;
else
break;
}
return V_61 ;
}
static int F_25 ( const char T_2 * V_106 ,
unsigned int V_107 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_107 ; V_61 ++ ) {
char V_110 ;
if ( F_23 ( V_110 , & V_106 [ V_61 ] ) )
return - V_20 ;
switch ( V_110 ) {
case '\"' :
case '\n' :
case '\r' :
case '\t' :
case ' ' :
case '=' :
break;
default:
goto V_111;
}
}
V_111:
return V_61 ;
}
static long F_26 ( const char T_2 * V_106 , unsigned long V_107 ,
unsigned long * V_108 )
{
int V_61 ;
* V_108 = 0 ;
for ( V_61 = 0 ; V_61 < V_107 ; V_61 ++ ) {
char V_110 ;
if ( F_23 ( V_110 , & V_106 [ V_61 ] ) )
return - V_20 ;
if ( ( V_110 >= '0' ) && ( V_110 <= '9' ) ) {
* V_108 *= 10 ;
* V_108 += V_110 - '0' ;
} else
break;
}
return V_61 ;
}
static int F_27 ( const char T_2 * V_106 , unsigned int V_107 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_107 ; V_61 ++ ) {
char V_110 ;
if ( F_23 ( V_110 , & V_106 [ V_61 ] ) )
return - V_20 ;
switch ( V_110 ) {
case '\"' :
case '\n' :
case '\r' :
case '\t' :
case ' ' :
goto V_112;
break;
default:
break;
}
}
V_112:
return V_61 ;
}
static T_1 F_28 ( const char T_2 * V_113 , struct V_22 * V_23 )
{
unsigned int V_114 = 0 ;
char V_110 ;
T_1 V_61 = 0 ;
int V_115 ;
V_23 -> V_60 = 0 ;
do {
T_7 V_116 ;
V_115 = F_22 ( & V_113 [ V_61 ] , 8 , & V_116 ) ;
if ( V_115 <= 0 )
return V_115 ;
V_23 -> V_62 [ V_114 ] = F_29 ( V_116 ) ;
if ( V_23 -> V_62 [ V_114 ] & V_117 )
V_23 -> V_38 |= V_77 ;
V_61 += V_115 ;
if ( F_23 ( V_110 , & V_113 [ V_61 ] ) )
return - V_20 ;
V_61 ++ ;
V_114 ++ ;
if ( V_114 >= V_118 )
return - V_119 ;
} while ( V_110 == ',' );
V_23 -> V_60 = V_114 ;
return V_61 ;
}
static T_1 F_30 ( struct V_5 * V_5 ,
const char T_2 * V_106 , T_3 V_7 ,
T_4 * V_120 )
{
struct V_1 * V_2 = V_5 -> V_121 ;
struct V_22 * V_23 = V_2 -> V_24 ;
int V_61 , V_122 , V_115 ;
char V_123 [ 16 ] , V_124 [ 32 ] ;
unsigned long V_109 = 0 ;
char * V_125 = NULL ;
int V_116 = 0 ;
char V_6 [ 128 ] ;
V_125 = & ( V_23 -> V_105 [ 0 ] ) ;
if ( V_7 < 1 ) {
F_10 ( L_58 ) ;
return - V_126 ;
}
V_122 = V_7 ;
V_116 = F_25 ( V_106 , V_122 ) ;
if ( V_116 < 0 ) {
F_10 ( L_59 ) ;
return V_116 ;
}
V_61 = V_116 ;
V_115 = F_27 ( & V_106 [ V_61 ] , sizeof( V_123 ) - 1 ) ;
if ( V_115 < 0 )
return V_115 ;
memset ( V_123 , 0 , sizeof( V_123 ) ) ;
if ( F_6 ( V_123 , & V_106 [ V_61 ] , V_115 ) )
return - V_20 ;
V_61 += V_115 ;
V_122 = V_7 - V_61 ;
V_115 = F_25 ( & V_106 [ V_61 ] , V_122 ) ;
if ( V_115 < 0 )
return V_115 ;
V_61 += V_115 ;
if ( V_127 ) {
T_3 V_128 = F_31 ( T_3 , V_7 , 1023 ) ;
char V_129 [ V_128 + 1 ] ;
if ( F_6 ( V_129 , V_106 , V_128 ) )
return - V_20 ;
V_129 [ V_128 ] = 0 ;
F_32 ( L_60 ,
V_123 , ( unsigned long ) V_7 , V_129 ) ;
}
if ( ! strcmp ( V_123 , L_61 ) ) {
V_115 = F_26 ( & V_106 [ V_61 ] , 10 , & V_109 ) ;
if ( V_115 < 0 )
return V_115 ;
V_61 += V_115 ;
if ( V_109 < 14 + 20 + 8 )
V_109 = 14 + 20 + 8 ;
if ( V_109 != V_23 -> V_27 ) {
V_23 -> V_27 = V_109 ;
V_23 -> V_130 = V_109 ;
}
sprintf ( V_125 , L_62 ,
V_23 -> V_27 ) ;
return V_7 ;
}
if ( ! strcmp ( V_123 , L_63 ) ) {
V_115 = F_26 ( & V_106 [ V_61 ] , 10 , & V_109 ) ;
if ( V_115 < 0 )
return V_115 ;
V_61 += V_115 ;
if ( V_109 < 14 + 20 + 8 )
V_109 = 14 + 20 + 8 ;
if ( V_109 != V_23 -> V_28 ) {
V_23 -> V_28 = V_109 ;
V_23 -> V_130 = V_109 ;
}
sprintf ( V_125 , L_64 ,
V_23 -> V_28 ) ;
return V_7 ;
}
if ( ! strcmp ( V_123 , L_65 ) ) {
V_115 = F_26 ( & V_106 [ V_61 ] , 10 , & V_109 ) ;
if ( V_115 < 0 )
return V_115 ;
V_61 += V_115 ;
if ( V_109 < 14 + 20 + 8 )
V_109 = 14 + 20 + 8 ;
if ( V_109 != V_23 -> V_27 ) {
V_23 -> V_27 = V_109 ;
V_23 -> V_28 = V_109 ;
V_23 -> V_130 = V_109 ;
}
sprintf ( V_125 , L_66 , V_23 -> V_27 ) ;
return V_7 ;
}
if ( ! strcmp ( V_123 , L_67 ) ) {
V_115 = F_26 ( & V_106 [ V_61 ] , 10 , & V_109 ) ;
if ( V_115 < 0 )
return V_115 ;
V_61 += V_115 ;
V_127 = V_109 ;
sprintf ( V_125 , L_68 , V_127 ) ;
return V_7 ;
}
if ( ! strcmp ( V_123 , L_69 ) ) {
V_115 = F_26 ( & V_106 [ V_61 ] , 10 , & V_109 ) ;
if ( V_115 < 0 )
return V_115 ;
V_61 += V_115 ;
V_23 -> V_29 = V_109 ;
sprintf ( V_125 , L_70 , V_23 -> V_29 ) ;
return V_7 ;
}
if ( ! strcmp ( V_123 , L_71 ) ) {
V_115 = F_26 ( & V_106 [ V_61 ] , 10 , & V_109 ) ;
if ( V_115 < 0 )
return V_115 ;
V_61 += V_115 ;
if ( V_109 == 0x7FFFFFFF )
V_23 -> V_30 = V_131 ;
else
V_23 -> V_30 = ( T_6 ) V_109 ;
sprintf ( V_125 , L_72 ,
( unsigned long long ) V_23 -> V_30 ) ;
return V_7 ;
}
if ( ! strcmp ( V_123 , L_73 ) ) {
V_115 = F_26 ( & V_106 [ V_61 ] , 10 , & V_109 ) ;
if ( V_115 < 0 )
return V_115 ;
V_61 += V_115 ;
if ( ! V_109 )
return V_115 ;
V_23 -> V_30 = V_23 -> V_27 * 8 * V_90 / V_109 ;
if ( V_127 )
F_33 ( L_74 , V_23 -> V_30 ) ;
sprintf ( V_125 , L_75 , V_109 ) ;
return V_7 ;
}
if ( ! strcmp ( V_123 , L_76 ) ) {
V_115 = F_26 ( & V_106 [ V_61 ] , 10 , & V_109 ) ;
if ( V_115 < 0 )
return V_115 ;
V_61 += V_115 ;
if ( ! V_109 )
return V_115 ;
V_23 -> V_30 = V_132 / V_109 ;
if ( V_127 )
F_33 ( L_74 , V_23 -> V_30 ) ;
sprintf ( V_125 , L_75 , V_109 ) ;
return V_7 ;
}
if ( ! strcmp ( V_123 , L_77 ) ) {
V_115 = F_26 ( & V_106 [ V_61 ] , 10 , & V_109 ) ;
if ( V_115 < 0 )
return V_115 ;
V_61 += V_115 ;
if ( V_109 != V_23 -> V_54 ) {
V_23 -> V_54 = V_109 ;
V_23 -> V_102 = V_109 ;
}
sprintf ( V_125 , L_78 , V_23 -> V_54 ) ;
return V_7 ;
}
if ( ! strcmp ( V_123 , L_79 ) ) {
V_115 = F_26 ( & V_106 [ V_61 ] , 10 , & V_109 ) ;
if ( V_115 < 0 )
return V_115 ;
V_61 += V_115 ;
if ( V_109 != V_23 -> V_56 ) {
V_23 -> V_56 = V_109 ;
V_23 -> V_101 = V_109 ;
}
sprintf ( V_125 , L_80 , V_23 -> V_56 ) ;
return V_7 ;
}
if ( ! strcmp ( V_123 , L_81 ) ) {
V_115 = F_26 ( & V_106 [ V_61 ] , 10 , & V_109 ) ;
if ( V_115 < 0 )
return V_115 ;
V_61 += V_115 ;
if ( V_109 != V_23 -> V_55 ) {
V_23 -> V_55 = V_109 ;
V_23 -> V_102 = V_109 ;
}
sprintf ( V_125 , L_82 , V_23 -> V_55 ) ;
return V_7 ;
}
if ( ! strcmp ( V_123 , L_83 ) ) {
V_115 = F_26 ( & V_106 [ V_61 ] , 10 , & V_109 ) ;
if ( V_115 < 0 )
return V_115 ;
V_61 += V_115 ;
if ( V_109 != V_23 -> V_57 ) {
V_23 -> V_57 = V_109 ;
V_23 -> V_101 = V_109 ;
}
sprintf ( V_125 , L_84 , V_23 -> V_57 ) ;
return V_7 ;
}
if ( ! strcmp ( V_123 , L_85 ) ) {
V_115 = F_26 ( & V_106 [ V_61 ] , 10 , & V_109 ) ;
if ( V_115 < 0 )
return V_115 ;
if ( ( V_109 > 0 ) &&
( ! ( V_23 -> V_51 -> V_133 & V_134 ) ) )
return - V_135 ;
V_61 += V_115 ;
V_23 -> V_31 = V_109 ;
sprintf ( V_125 , L_86 , V_23 -> V_31 ) ;
return V_7 ;
}
if ( ! strcmp ( V_123 , L_87 ) ) {
V_115 = F_26 ( & V_106 [ V_61 ] , 10 , & V_109 ) ;
if ( V_115 < 0 )
return V_115 ;
V_61 += V_115 ;
V_23 -> V_7 = V_109 ;
sprintf ( V_125 , L_88 ,
( unsigned long long ) V_23 -> V_7 ) ;
return V_7 ;
}
if ( ! strcmp ( V_123 , L_89 ) ) {
V_115 = F_26 ( & V_106 [ V_61 ] , 10 , & V_109 ) ;
if ( V_115 < 0 )
return V_115 ;
V_61 += V_115 ;
if ( V_23 -> V_58 != V_109 ) {
V_23 -> V_58 = V_109 ;
V_23 -> V_96 = 0 ;
}
sprintf ( V_125 , L_90 ,
V_23 -> V_58 ) ;
return V_7 ;
}
if ( ! strcmp ( V_123 , L_91 ) ) {
V_115 = F_26 ( & V_106 [ V_61 ] , 10 , & V_109 ) ;
if ( V_115 < 0 )
return V_115 ;
V_61 += V_115 ;
if ( V_23 -> V_59 != V_109 ) {
V_23 -> V_59 = V_109 ;
V_23 -> V_95 = 0 ;
}
sprintf ( V_125 , L_92 ,
V_23 -> V_59 ) ;
return V_7 ;
}
if ( ! strcmp ( V_123 , L_93 ) ) {
V_115 = F_26 ( & V_106 [ V_61 ] , 10 , & V_109 ) ;
if ( V_115 < 0 )
return V_115 ;
V_61 += V_115 ;
if ( F_34 ( V_109 ) ) {
V_23 -> V_71 = V_109 ;
sprintf ( V_125 , L_94 , V_23 -> V_71 ) ;
if ( V_23 -> V_136 ) {
F_35 ( V_23 -> V_136 ) ;
V_23 -> V_136 = NULL ;
}
}
else
sprintf ( V_125 , L_95 ) ;
return V_7 ;
}
if ( ! strcmp ( V_123 , L_96 ) ) {
char V_137 [ 32 ] ;
memset ( V_137 , 0 , 32 ) ;
V_115 = F_27 ( & V_106 [ V_61 ] , sizeof( V_137 ) - 1 ) ;
if ( V_115 < 0 )
return V_115 ;
if ( F_6 ( V_137 , & V_106 [ V_61 ] , V_115 ) )
return - V_20 ;
V_61 += V_115 ;
if ( strcmp ( V_137 , L_97 ) == 0 )
V_23 -> V_38 |= V_72 ;
else if ( strcmp ( V_137 , L_98 ) == 0 )
V_23 -> V_38 &= ~ V_72 ;
else if ( strcmp ( V_137 , L_99 ) == 0 )
V_23 -> V_38 |= V_74 ;
else if ( strcmp ( V_137 , L_100 ) == 0 )
V_23 -> V_38 &= ~ V_74 ;
else if ( strcmp ( V_137 , L_101 ) == 0 )
V_23 -> V_38 |= V_73 ;
else if ( strcmp ( V_137 , L_102 ) == 0 )
V_23 -> V_38 &= ~ V_73 ;
else if ( strcmp ( V_137 , L_103 ) == 0 )
V_23 -> V_38 |= V_75 ;
else if ( strcmp ( V_137 , L_104 ) == 0 )
V_23 -> V_38 &= ~ V_75 ;
else if ( strcmp ( V_137 , L_105 ) == 0 )
V_23 -> V_38 |= V_76 ;
else if ( strcmp ( V_137 , L_106 ) == 0 )
V_23 -> V_38 &= ~ V_76 ;
else if ( strcmp ( V_137 , L_107 ) == 0 )
V_23 -> V_38 |= V_82 ;
else if ( strcmp ( V_137 , L_108 ) == 0 )
V_23 -> V_38 &= ~ V_82 ;
else if ( strcmp ( V_137 , L_109 ) == 0 )
V_23 -> V_38 |= V_83 ;
else if ( strcmp ( V_137 , L_110 ) == 0 )
V_23 -> V_38 &= ~ V_83 ;
else if ( strcmp ( V_137 , L_111 ) == 0 )
V_23 -> V_38 |= V_77 ;
else if ( strcmp ( V_137 , L_112 ) == 0 )
V_23 -> V_38 &= ~ V_77 ;
else if ( strcmp ( V_137 , L_113 ) == 0 )
V_23 -> V_38 |= V_84 ;
else if ( strcmp ( V_137 , L_114 ) == 0 )
V_23 -> V_38 &= ~ V_84 ;
else if ( strcmp ( V_137 , L_115 ) == 0 )
V_23 -> V_38 |= V_85 ;
else if ( strcmp ( V_137 , L_116 ) == 0 )
V_23 -> V_38 &= ~ V_85 ;
else if ( strcmp ( V_137 , L_117 ) == 0 )
V_23 -> V_38 |= V_80 ;
else if ( strcmp ( V_137 , L_118 ) == 0 )
V_23 -> V_38 |= V_78 ;
else if ( strcmp ( V_137 , L_119 ) == 0 )
V_23 -> V_38 &= ~ V_78 ;
else if ( strcmp ( V_137 , L_120 ) == 0 )
V_23 -> V_38 |= V_79 ;
else if ( strcmp ( V_137 , L_121 ) == 0 )
V_23 -> V_38 &= ~ V_79 ;
#ifdef F_18
else if ( strcmp ( V_137 , L_122 ) == 0 )
V_23 -> V_38 |= V_81 ;
#endif
else if ( strcmp ( V_137 , L_123 ) == 0 )
V_23 -> V_38 &= ~ V_39 ;
else if ( strcmp ( V_137 , L_124 ) == 0 )
V_23 -> V_38 |= V_86 ;
else if ( strcmp ( V_137 , L_125 ) == 0 )
V_23 -> V_38 &= ~ V_86 ;
else {
sprintf ( V_125 ,
L_126 ,
V_137 ,
L_127
L_128 ) ;
return V_7 ;
}
sprintf ( V_125 , L_129 , V_23 -> V_38 ) ;
return V_7 ;
}
if ( ! strcmp ( V_123 , L_130 ) || ! strcmp ( V_123 , L_131 ) ) {
V_115 = F_27 ( & V_106 [ V_61 ] , sizeof( V_23 -> V_46 ) - 1 ) ;
if ( V_115 < 0 )
return V_115 ;
if ( F_6 ( V_6 , & V_106 [ V_61 ] , V_115 ) )
return - V_20 ;
V_6 [ V_115 ] = 0 ;
if ( strcmp ( V_6 , V_23 -> V_46 ) != 0 ) {
memset ( V_23 -> V_46 , 0 , sizeof( V_23 -> V_46 ) ) ;
strncpy ( V_23 -> V_46 , V_6 , V_115 ) ;
V_23 -> V_138 = F_36 ( V_23 -> V_46 ) ;
V_23 -> V_100 = V_23 -> V_138 ;
}
if ( V_127 )
F_32 ( L_132 , V_23 -> V_46 ) ;
V_61 += V_115 ;
sprintf ( V_125 , L_133 , V_23 -> V_46 ) ;
return V_7 ;
}
if ( ! strcmp ( V_123 , L_134 ) ) {
V_115 = F_27 ( & V_106 [ V_61 ] , sizeof( V_23 -> V_47 ) - 1 ) ;
if ( V_115 < 0 )
return V_115 ;
if ( F_6 ( V_6 , & V_106 [ V_61 ] , V_115 ) )
return - V_20 ;
V_6 [ V_115 ] = 0 ;
if ( strcmp ( V_6 , V_23 -> V_47 ) != 0 ) {
memset ( V_23 -> V_47 , 0 , sizeof( V_23 -> V_47 ) ) ;
strncpy ( V_23 -> V_47 , V_6 , V_115 ) ;
V_23 -> V_139 = F_36 ( V_23 -> V_47 ) ;
V_23 -> V_100 = V_23 -> V_139 ;
}
if ( V_127 )
F_32 ( L_135 , V_23 -> V_47 ) ;
V_61 += V_115 ;
sprintf ( V_125 , L_136 , V_23 -> V_47 ) ;
return V_7 ;
}
if ( ! strcmp ( V_123 , L_137 ) ) {
V_115 = F_27 ( & V_106 [ V_61 ] , sizeof( V_6 ) - 1 ) ;
if ( V_115 < 0 )
return V_115 ;
V_23 -> V_38 |= V_39 ;
if ( F_6 ( V_6 , & V_106 [ V_61 ] , V_115 ) )
return - V_20 ;
V_6 [ V_115 ] = 0 ;
F_37 ( V_6 , - 1 , V_23 -> V_43 . V_140 , - 1 , NULL ) ;
snprintf ( V_6 , sizeof( V_6 ) , L_138 , & V_23 -> V_43 ) ;
V_23 -> V_98 = V_23 -> V_43 ;
if ( V_127 )
F_32 ( L_139 , V_6 ) ;
V_61 += V_115 ;
sprintf ( V_125 , L_140 , V_6 ) ;
return V_7 ;
}
if ( ! strcmp ( V_123 , L_141 ) ) {
V_115 = F_27 ( & V_106 [ V_61 ] , sizeof( V_6 ) - 1 ) ;
if ( V_115 < 0 )
return V_115 ;
V_23 -> V_38 |= V_39 ;
if ( F_6 ( V_6 , & V_106 [ V_61 ] , V_115 ) )
return - V_20 ;
V_6 [ V_115 ] = 0 ;
F_37 ( V_6 , - 1 , V_23 -> V_44 . V_140 , - 1 , NULL ) ;
snprintf ( V_6 , sizeof( V_6 ) , L_138 , & V_23 -> V_44 ) ;
V_23 -> V_98 = V_23 -> V_44 ;
if ( V_127 )
F_32 ( L_142 , V_6 ) ;
V_61 += V_115 ;
sprintf ( V_125 , L_143 , V_6 ) ;
return V_7 ;
}
if ( ! strcmp ( V_123 , L_144 ) ) {
V_115 = F_27 ( & V_106 [ V_61 ] , sizeof( V_6 ) - 1 ) ;
if ( V_115 < 0 )
return V_115 ;
V_23 -> V_38 |= V_39 ;
if ( F_6 ( V_6 , & V_106 [ V_61 ] , V_115 ) )
return - V_20 ;
V_6 [ V_115 ] = 0 ;
F_37 ( V_6 , - 1 , V_23 -> V_45 . V_140 , - 1 , NULL ) ;
snprintf ( V_6 , sizeof( V_6 ) , L_138 , & V_23 -> V_45 ) ;
if ( V_127 )
F_32 ( L_145 , V_6 ) ;
V_61 += V_115 ;
sprintf ( V_125 , L_146 , V_6 ) ;
return V_7 ;
}
if ( ! strcmp ( V_123 , L_147 ) ) {
V_115 = F_27 ( & V_106 [ V_61 ] , sizeof( V_6 ) - 1 ) ;
if ( V_115 < 0 )
return V_115 ;
V_23 -> V_38 |= V_39 ;
if ( F_6 ( V_6 , & V_106 [ V_61 ] , V_115 ) )
return - V_20 ;
V_6 [ V_115 ] = 0 ;
F_37 ( V_6 , - 1 , V_23 -> V_40 . V_140 , - 1 , NULL ) ;
snprintf ( V_6 , sizeof( V_6 ) , L_138 , & V_23 -> V_40 ) ;
V_23 -> V_97 = V_23 -> V_40 ;
if ( V_127 )
F_32 ( L_148 , V_6 ) ;
V_61 += V_115 ;
sprintf ( V_125 , L_149 , V_6 ) ;
return V_7 ;
}
if ( ! strcmp ( V_123 , L_150 ) ) {
V_115 = F_27 ( & V_106 [ V_61 ] , sizeof( V_23 -> V_48 ) - 1 ) ;
if ( V_115 < 0 )
return V_115 ;
if ( F_6 ( V_6 , & V_106 [ V_61 ] , V_115 ) )
return - V_20 ;
V_6 [ V_115 ] = 0 ;
if ( strcmp ( V_6 , V_23 -> V_48 ) != 0 ) {
memset ( V_23 -> V_48 , 0 , sizeof( V_23 -> V_48 ) ) ;
strncpy ( V_23 -> V_48 , V_6 , V_115 ) ;
V_23 -> V_141 = F_36 ( V_23 -> V_48 ) ;
V_23 -> V_99 = V_23 -> V_141 ;
}
if ( V_127 )
F_32 ( L_151 , V_23 -> V_48 ) ;
V_61 += V_115 ;
sprintf ( V_125 , L_152 , V_23 -> V_48 ) ;
return V_7 ;
}
if ( ! strcmp ( V_123 , L_153 ) ) {
V_115 = F_27 ( & V_106 [ V_61 ] , sizeof( V_23 -> V_49 ) - 1 ) ;
if ( V_115 < 0 )
return V_115 ;
if ( F_6 ( V_6 , & V_106 [ V_61 ] , V_115 ) )
return - V_20 ;
V_6 [ V_115 ] = 0 ;
if ( strcmp ( V_6 , V_23 -> V_49 ) != 0 ) {
memset ( V_23 -> V_49 , 0 , sizeof( V_23 -> V_49 ) ) ;
strncpy ( V_23 -> V_49 , V_6 , V_115 ) ;
V_23 -> V_142 = F_36 ( V_23 -> V_49 ) ;
V_23 -> V_99 = V_23 -> V_142 ;
}
if ( V_127 )
F_32 ( L_154 , V_23 -> V_49 ) ;
V_61 += V_115 ;
sprintf ( V_125 , L_155 , V_23 -> V_49 ) ;
return V_7 ;
}
if ( ! strcmp ( V_123 , L_156 ) ) {
V_115 = F_27 ( & V_106 [ V_61 ] , sizeof( V_124 ) - 1 ) ;
if ( V_115 < 0 )
return V_115 ;
memset ( V_124 , 0 , sizeof( V_124 ) ) ;
if ( F_6 ( V_124 , & V_106 [ V_61 ] , V_115 ) )
return - V_20 ;
if ( ! F_38 ( V_124 , V_23 -> V_53 ) )
return - V_126 ;
memcpy ( & V_23 -> V_143 [ 0 ] , V_23 -> V_53 , V_144 ) ;
sprintf ( V_125 , L_157 , V_23 -> V_53 ) ;
return V_7 ;
}
if ( ! strcmp ( V_123 , L_158 ) ) {
V_115 = F_27 ( & V_106 [ V_61 ] , sizeof( V_124 ) - 1 ) ;
if ( V_115 < 0 )
return V_115 ;
memset ( V_124 , 0 , sizeof( V_124 ) ) ;
if ( F_6 ( V_124 , & V_106 [ V_61 ] , V_115 ) )
return - V_20 ;
if ( ! F_38 ( V_124 , V_23 -> V_50 ) )
return - V_126 ;
memcpy ( & V_23 -> V_143 [ 6 ] , V_23 -> V_50 , V_144 ) ;
sprintf ( V_125 , L_159 , V_23 -> V_50 ) ;
return V_7 ;
}
if ( ! strcmp ( V_123 , L_160 ) ) {
F_39 ( V_23 ) ;
sprintf ( V_125 , L_161 ) ;
return V_7 ;
}
if ( ! strcmp ( V_123 , L_162 ) ) {
V_115 = F_26 ( & V_106 [ V_61 ] , 10 , & V_109 ) ;
if ( V_115 < 0 )
return V_115 ;
V_61 += V_115 ;
if ( V_109 > V_145 )
V_109 = V_145 ;
V_23 -> V_33 = V_109 ;
sprintf ( V_125 , L_163 , V_23 -> V_33 ) ;
return V_7 ;
}
if ( ! strcmp ( V_123 , L_164 ) ) {
V_115 = F_26 ( & V_106 [ V_61 ] , 10 , & V_109 ) ;
if ( V_115 < 0 )
return V_115 ;
V_61 += V_115 ;
V_23 -> V_34 = V_109 ;
sprintf ( V_125 , L_165 , V_23 -> V_34 ) ;
return V_7 ;
}
if ( ! strcmp ( V_123 , L_166 ) ) {
V_115 = F_26 ( & V_106 [ V_61 ] , 5 , & V_109 ) ;
if ( V_115 < 0 )
return V_115 ;
V_61 += V_115 ;
V_23 -> V_35 = V_109 ;
sprintf ( V_125 , L_167 , V_23 -> V_35 ) ;
return V_7 ;
}
if ( ! strcmp ( V_123 , L_168 ) ) {
V_115 = F_26 ( & V_106 [ V_61 ] , 5 , & V_109 ) ;
if ( V_115 < 0 )
return V_115 ;
V_61 += V_115 ;
V_23 -> V_36 = V_109 ;
sprintf ( V_125 , L_169 , V_23 -> V_36 ) ;
return V_7 ;
}
if ( ! strcmp ( V_123 , L_170 ) ) {
unsigned int V_114 , V_146 ;
V_115 = F_28 ( & V_106 [ V_61 ] , V_23 ) ;
if ( V_115 < 0 )
return V_115 ;
V_61 += V_115 ;
V_146 = sprintf ( V_125 , L_171 ) ;
for ( V_114 = 0 ; V_114 < V_23 -> V_60 ; V_114 ++ )
V_146 += sprintf ( V_125 + V_146 ,
L_22 , F_17 ( V_23 -> V_62 [ V_114 ] ) ,
V_114 == V_23 -> V_60 - 1 ? L_172 : L_173 ) ;
if ( V_23 -> V_60 && V_23 -> V_63 != 0xffff ) {
V_23 -> V_63 = 0xffff ;
V_23 -> V_66 = 0xffff ;
if ( V_127 )
F_32 ( L_174 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_123 , L_175 ) ) {
V_115 = F_26 ( & V_106 [ V_61 ] , 4 , & V_109 ) ;
if ( V_115 < 0 )
return V_115 ;
V_61 += V_115 ;
if ( V_109 <= 4095 ) {
V_23 -> V_63 = V_109 ;
if ( V_127 )
F_32 ( L_176 ) ;
if ( V_127 && V_23 -> V_60 )
F_32 ( L_177 ) ;
V_23 -> V_60 = 0 ;
sprintf ( V_125 , L_178 , V_23 -> V_63 ) ;
} else {
V_23 -> V_63 = 0xffff ;
V_23 -> V_66 = 0xffff ;
if ( V_127 )
F_32 ( L_179 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_123 , L_180 ) ) {
V_115 = F_26 ( & V_106 [ V_61 ] , 1 , & V_109 ) ;
if ( V_115 < 0 )
return V_115 ;
V_61 += V_115 ;
if ( ( V_109 <= 7 ) && ( V_23 -> V_63 != 0xffff ) ) {
V_23 -> V_64 = V_109 ;
sprintf ( V_125 , L_181 , V_23 -> V_64 ) ;
} else {
sprintf ( V_125 , L_182 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_123 , L_183 ) ) {
V_115 = F_26 ( & V_106 [ V_61 ] , 1 , & V_109 ) ;
if ( V_115 < 0 )
return V_115 ;
V_61 += V_115 ;
if ( ( V_109 <= 1 ) && ( V_23 -> V_63 != 0xffff ) ) {
V_23 -> V_65 = V_109 ;
sprintf ( V_125 , L_184 , V_23 -> V_65 ) ;
} else {
sprintf ( V_125 , L_185 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_123 , L_186 ) ) {
V_115 = F_26 ( & V_106 [ V_61 ] , 4 , & V_109 ) ;
if ( V_115 < 0 )
return V_115 ;
V_61 += V_115 ;
if ( ( V_109 <= 4095 ) && ( ( V_23 -> V_63 != 0xffff ) ) ) {
V_23 -> V_66 = V_109 ;
if ( V_127 )
F_32 ( L_187 ) ;
if ( V_127 && V_23 -> V_60 )
F_32 ( L_177 ) ;
V_23 -> V_60 = 0 ;
sprintf ( V_125 , L_188 , V_23 -> V_66 ) ;
} else {
V_23 -> V_63 = 0xffff ;
V_23 -> V_66 = 0xffff ;
if ( V_127 )
F_32 ( L_179 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_123 , L_189 ) ) {
V_115 = F_26 ( & V_106 [ V_61 ] , 1 , & V_109 ) ;
if ( V_115 < 0 )
return V_115 ;
V_61 += V_115 ;
if ( ( V_109 <= 7 ) && ( V_23 -> V_66 != 0xffff ) ) {
V_23 -> V_67 = V_109 ;
sprintf ( V_125 , L_190 , V_23 -> V_67 ) ;
} else {
sprintf ( V_125 , L_191 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_123 , L_192 ) ) {
V_115 = F_26 ( & V_106 [ V_61 ] , 1 , & V_109 ) ;
if ( V_115 < 0 )
return V_115 ;
V_61 += V_115 ;
if ( ( V_109 <= 1 ) && ( V_23 -> V_66 != 0xffff ) ) {
V_23 -> V_68 = V_109 ;
sprintf ( V_125 , L_193 , V_23 -> V_68 ) ;
} else {
sprintf ( V_125 , L_194 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_123 , L_195 ) ) {
T_7 V_147 = 0 ;
V_115 = F_22 ( & V_106 [ V_61 ] , 2 , & V_147 ) ;
if ( V_115 < 0 )
return V_115 ;
V_61 += V_115 ;
if ( V_115 == 2 ) {
V_23 -> V_69 = V_147 ;
sprintf ( V_125 , L_196 , V_23 -> V_69 ) ;
} else {
sprintf ( V_125 , L_197 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_123 , L_198 ) ) {
T_7 V_147 = 0 ;
V_115 = F_22 ( & V_106 [ V_61 ] , 2 , & V_147 ) ;
if ( V_115 < 0 )
return V_115 ;
V_61 += V_115 ;
if ( V_115 == 2 ) {
V_23 -> V_70 = V_147 ;
sprintf ( V_125 , L_199 , V_23 -> V_70 ) ;
} else {
sprintf ( V_125 , L_200 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_123 , L_201 ) ) {
V_115 = F_26 ( & V_106 [ V_61 ] , 9 , & V_109 ) ;
if ( V_115 < 0 )
return V_115 ;
V_61 += V_115 ;
V_23 -> V_37 = V_109 ;
sprintf ( V_125 , L_202 ,
V_23 -> V_37 ) ;
return V_7 ;
}
sprintf ( V_23 -> V_105 , L_203 , V_123 ) ;
return - V_126 ;
}
static int F_40 ( struct V_21 * V_21 , struct V_5 * V_5 )
{
return F_12 ( V_5 , F_14 , F_13 ( V_21 ) ) ;
}
static int F_41 ( struct V_1 * V_2 , void * V_3 )
{
struct V_148 * V_149 = V_2 -> V_24 ;
const struct V_22 * V_23 ;
F_42 ( ! V_149 ) ;
F_15 ( V_2 , L_204 ) ;
F_43 ( V_149 ) ;
F_44 (pkt_dev, &t->if_list, list)
if ( V_23 -> V_87 )
F_15 ( V_2 , L_205 , V_23 -> V_32 ) ;
F_15 ( V_2 , L_206 ) ;
F_44 (pkt_dev, &t->if_list, list)
if ( ! V_23 -> V_87 )
F_15 ( V_2 , L_205 , V_23 -> V_32 ) ;
if ( V_149 -> V_105 [ 0 ] )
F_15 ( V_2 , L_207 , V_149 -> V_105 ) ;
else
F_15 ( V_2 , L_208 ) ;
F_45 ( V_149 ) ;
return 0 ;
}
static T_1 F_46 ( struct V_5 * V_5 ,
const char T_2 * V_106 ,
T_3 V_7 , T_4 * V_120 )
{
struct V_1 * V_2 = V_5 -> V_121 ;
struct V_148 * V_149 = V_2 -> V_24 ;
int V_61 , V_122 , V_115 , V_150 ;
char V_123 [ 40 ] ;
char * V_125 ;
if ( V_7 < 1 ) {
return - V_126 ;
}
V_122 = V_7 ;
V_115 = F_25 ( V_106 , V_122 ) ;
if ( V_115 < 0 )
return V_115 ;
V_61 = V_115 ;
V_115 = F_27 ( & V_106 [ V_61 ] , sizeof( V_123 ) - 1 ) ;
if ( V_115 < 0 )
return V_115 ;
memset ( V_123 , 0 , sizeof( V_123 ) ) ;
if ( F_6 ( V_123 , & V_106 [ V_61 ] , V_115 ) )
return - V_20 ;
V_61 += V_115 ;
V_122 = V_7 - V_61 ;
V_115 = F_25 ( & V_106 [ V_61 ] , V_122 ) ;
if ( V_115 < 0 )
return V_115 ;
V_61 += V_115 ;
if ( V_127 )
F_32 ( L_209 , V_123 , ( unsigned long ) V_7 ) ;
if ( ! V_149 ) {
F_47 ( L_210 ) ;
V_150 = - V_126 ;
goto V_19;
}
V_125 = & ( V_149 -> V_105 [ 0 ] ) ;
if ( ! strcmp ( V_123 , L_211 ) ) {
char V_137 [ 32 ] ;
memset ( V_137 , 0 , 32 ) ;
V_115 = F_27 ( & V_106 [ V_61 ] , sizeof( V_137 ) - 1 ) ;
if ( V_115 < 0 ) {
V_150 = V_115 ;
goto V_19;
}
if ( F_6 ( V_137 , & V_106 [ V_61 ] , V_115 ) )
return - V_20 ;
V_61 += V_115 ;
F_48 ( & V_151 ) ;
V_150 = F_49 ( V_149 , V_137 ) ;
F_50 ( & V_151 ) ;
if ( ! V_150 ) {
V_150 = V_7 ;
sprintf ( V_125 , L_212 , V_137 ) ;
} else
sprintf ( V_125 , L_213 , V_137 ) ;
goto V_19;
}
if ( ! strcmp ( V_123 , L_214 ) ) {
F_48 ( & V_151 ) ;
V_149 -> V_152 |= V_153 ;
F_50 ( & V_151 ) ;
F_51 ( F_52 ( 125 ) ) ;
V_150 = V_7 ;
sprintf ( V_125 , L_215 ) ;
goto V_19;
}
if ( ! strcmp ( V_123 , L_216 ) ) {
sprintf ( V_125 , L_217 ) ;
V_150 = V_7 ;
goto V_19;
}
V_150 = - V_126 ;
V_19:
return V_150 ;
}
static int F_53 ( struct V_21 * V_21 , struct V_5 * V_5 )
{
return F_12 ( V_5 , F_41 , F_13 ( V_21 ) ) ;
}
static struct V_22 * F_54 ( const struct V_11 * V_12 ,
const char * V_154 , int remove )
{
struct V_148 * V_149 ;
struct V_22 * V_23 = NULL ;
bool V_155 = ( remove == V_156 ) ;
F_44 (t, &pn->pktgen_threads, th_list) {
V_23 = F_55 ( V_149 , V_154 , V_155 ) ;
if ( V_23 ) {
if ( remove ) {
F_43 ( V_149 ) ;
V_23 -> V_157 = 1 ;
V_149 -> V_152 |= V_158 ;
F_45 ( V_149 ) ;
}
break;
}
}
return V_23 ;
}
static void F_56 ( const struct V_11 * V_12 , const char * V_154 )
{
struct V_22 * V_23 = NULL ;
const int V_159 = 10 , V_160 = 125 ;
int V_61 = 0 ;
F_48 ( & V_151 ) ;
F_32 ( L_218 , V_161 , V_154 ) ;
while ( 1 ) {
V_23 = F_54 ( V_12 , V_154 , REMOVE ) ;
if ( V_23 == NULL )
break;
F_50 ( & V_151 ) ;
F_32 ( L_219 ,
V_161 , V_154 ) ;
F_51 ( F_52 ( V_160 ) ) ;
F_48 ( & V_151 ) ;
if ( ++ V_61 >= V_159 ) {
F_47 ( L_220 ,
V_161 , V_160 * V_61 , V_154 ) ;
break;
}
}
F_50 ( & V_151 ) ;
}
static void F_57 ( const struct V_11 * V_12 , struct V_162 * V_163 )
{
struct V_148 * V_149 ;
F_44 (t, &pn->pktgen_threads, th_list) {
struct V_22 * V_23 ;
F_44 (pkt_dev, &t->if_list, list) {
if ( V_23 -> V_51 != V_163 )
continue;
F_58 ( V_23 -> V_164 ) ;
V_23 -> V_164 = F_59 ( V_163 -> V_123 , 0600 ,
V_12 -> V_165 ,
& V_166 ,
V_23 ) ;
if ( ! V_23 -> V_164 )
F_47 ( L_221 ,
V_163 -> V_123 ) ;
break;
}
}
}
static int F_60 ( struct V_167 * V_168 ,
unsigned long V_169 , void * V_170 )
{
struct V_162 * V_163 = F_61 ( V_170 ) ;
struct V_11 * V_12 = F_4 ( F_62 ( V_163 ) , V_16 ) ;
if ( V_12 -> V_171 )
return V_172 ;
switch ( V_169 ) {
case V_173 :
F_57 ( V_12 , V_163 ) ;
break;
case V_174 :
F_56 ( V_12 , V_163 -> V_123 ) ;
break;
}
return V_172 ;
}
static struct V_162 * F_63 ( const struct V_11 * V_12 ,
struct V_22 * V_23 ,
const char * V_154 )
{
char V_175 [ V_176 + 5 ] ;
int V_61 ;
for ( V_61 = 0 ; V_154 [ V_61 ] != '@' ; V_61 ++ ) {
if ( V_61 == V_176 )
break;
V_175 [ V_61 ] = V_154 [ V_61 ] ;
}
V_175 [ V_61 ] = 0 ;
return F_64 ( V_12 -> V_177 , V_175 ) ;
}
static int F_65 ( const struct V_11 * V_12 ,
struct V_22 * V_23 , const char * V_154 )
{
struct V_162 * V_51 ;
int V_9 ;
if ( V_23 -> V_51 ) {
F_66 ( V_23 -> V_51 ) ;
V_23 -> V_51 = NULL ;
}
V_51 = F_63 ( V_12 , V_23 , V_154 ) ;
if ( ! V_51 ) {
F_47 ( L_222 , V_154 ) ;
return - V_178 ;
}
if ( V_51 -> type != V_179 ) {
F_47 ( L_223 , V_154 ) ;
V_9 = - V_126 ;
} else if ( ! F_67 ( V_51 ) ) {
F_47 ( L_224 , V_154 ) ;
V_9 = - V_180 ;
} else {
V_23 -> V_51 = V_51 ;
return 0 ;
}
F_66 ( V_51 ) ;
return V_9 ;
}
static void F_68 ( struct V_22 * V_23 )
{
int V_181 ;
if ( ! V_23 -> V_51 ) {
F_47 ( L_225 ) ;
sprintf ( V_23 -> V_105 ,
L_226 ) ;
return;
}
V_181 = V_23 -> V_51 -> V_182 ;
if ( V_181 <= V_23 -> V_35 ) {
F_10 ( L_227 ,
V_23 -> V_35 , ( V_181 ? : 1 ) - 1 , V_181 ,
V_23 -> V_32 ) ;
V_23 -> V_35 = ( V_181 ? : 1 ) - 1 ;
}
if ( V_23 -> V_36 >= V_181 ) {
F_10 ( L_228 ,
V_23 -> V_36 , ( V_181 ? : 1 ) - 1 , V_181 ,
V_23 -> V_32 ) ;
V_23 -> V_36 = ( V_181 ? : 1 ) - 1 ;
}
if ( F_16 ( V_23 -> V_50 ) )
memcpy ( & ( V_23 -> V_143 [ 6 ] ) , V_23 -> V_51 -> V_52 , V_144 ) ;
memcpy ( & ( V_23 -> V_143 [ 0 ] ) , V_23 -> V_53 , V_144 ) ;
if ( V_23 -> V_38 & V_39 ) {
int V_61 , V_183 = 0 , V_9 = 1 ;
struct V_184 * V_185 ;
if ( V_23 -> V_27 == 0 ) {
V_23 -> V_27 = 14 + sizeof( struct V_186 )
+ sizeof( struct V_187 )
+ sizeof( struct V_188 )
+ V_23 -> V_189 ;
}
for ( V_61 = 0 ; V_61 < V_190 ; V_61 ++ )
if ( V_23 -> V_97 . V_140 [ V_61 ] ) {
V_183 = 1 ;
break;
}
if ( ! V_183 ) {
F_69 () ;
V_185 = F_70 ( V_23 -> V_51 ) ;
if ( V_185 ) {
struct V_191 * V_192 ;
F_71 ( & V_185 -> V_193 ) ;
F_44 (ifp, &idev->addr_list, if_list) {
if ( ( V_192 -> V_194 & V_195 ) &&
! ( V_192 -> V_38 & V_196 ) ) {
V_23 -> V_97 = V_192 -> V_197 ;
V_9 = 0 ;
break;
}
}
F_72 ( & V_185 -> V_193 ) ;
}
F_73 () ;
if ( V_9 )
F_47 ( L_229 ) ;
}
} else {
if ( V_23 -> V_27 == 0 ) {
V_23 -> V_27 = 14 + sizeof( struct V_198 )
+ sizeof( struct V_187 )
+ sizeof( struct V_188 )
+ V_23 -> V_189 ;
}
V_23 -> V_141 = 0 ;
V_23 -> V_142 = 0 ;
if ( strlen ( V_23 -> V_48 ) == 0 ) {
struct V_199 * V_200 ;
F_69 () ;
V_200 = F_74 ( V_23 -> V_51 ) ;
if ( V_200 ) {
if ( V_200 -> V_201 ) {
V_23 -> V_141 =
V_200 -> V_201 -> V_202 ;
V_23 -> V_142 = V_23 -> V_141 ;
}
}
F_73 () ;
} else {
V_23 -> V_141 = F_36 ( V_23 -> V_48 ) ;
V_23 -> V_142 = F_36 ( V_23 -> V_49 ) ;
}
V_23 -> V_138 = F_36 ( V_23 -> V_46 ) ;
V_23 -> V_139 = F_36 ( V_23 -> V_47 ) ;
}
V_23 -> V_130 = V_23 -> V_27 ;
if ( V_23 -> V_27 > V_23 -> V_28 )
V_23 -> V_28 = V_23 -> V_27 ;
V_23 -> V_95 = 0 ;
V_23 -> V_96 = 0 ;
V_23 -> V_99 = V_23 -> V_141 ;
V_23 -> V_100 = V_23 -> V_138 ;
V_23 -> V_101 = V_23 -> V_56 ;
V_23 -> V_102 = V_23 -> V_54 ;
V_23 -> V_104 = 0 ;
}
static void F_75 ( struct V_22 * V_23 , T_5 V_203 )
{
T_5 V_204 , V_205 ;
T_8 V_206 ;
struct V_207 V_149 ;
F_76 ( & V_149 . V_208 , V_209 , V_210 ) ;
F_77 ( & V_149 . V_208 , V_203 ) ;
V_206 = F_78 ( F_79 ( & V_149 . V_208 ) ) ;
if ( V_206 <= 0 ) {
V_23 -> V_211 = F_80 ( V_203 , V_23 -> V_30 ) ;
return;
}
V_204 = F_19 () ;
if ( V_206 < 100000 ) {
do {
V_205 = F_19 () ;
} while ( F_81 ( V_205 , V_203 ) < 0 );
} else {
F_82 ( & V_149 , V_13 ) ;
do {
F_83 ( V_212 ) ;
F_84 ( & V_149 . V_208 , V_210 ) ;
if ( ! F_85 ( & V_149 . V_208 ) )
V_149 . V_213 = NULL ;
if ( F_86 ( V_149 . V_213 ) )
F_87 () ;
F_88 ( & V_149 . V_208 ) ;
} while ( V_149 . V_213 && V_23 -> V_87 && ! F_89 ( V_13 ) );
F_90 ( V_214 ) ;
V_205 = F_19 () ;
}
V_23 -> V_89 += F_78 ( F_91 ( V_205 , V_204 ) ) ;
V_23 -> V_211 = F_80 ( V_203 , V_23 -> V_30 ) ;
}
static inline void F_92 ( struct V_22 * V_23 )
{
V_23 -> V_189 = 0 ;
V_23 -> V_189 += V_23 -> V_60 * sizeof( V_215 ) ;
V_23 -> V_189 += F_93 ( V_23 ) ;
V_23 -> V_189 += F_94 ( V_23 ) ;
}
static inline int F_95 ( const struct V_22 * V_23 , int V_216 )
{
return ! ! ( V_23 -> V_217 [ V_216 ] . V_38 & V_218 ) ;
}
static inline int F_96 ( struct V_22 * V_23 )
{
int V_216 = V_23 -> V_219 ;
if ( V_23 -> V_38 & V_80 ) {
if ( V_23 -> V_217 [ V_216 ] . V_7 >= V_23 -> V_34 ) {
V_23 -> V_217 [ V_216 ] . V_7 = 0 ;
V_23 -> V_217 [ V_216 ] . V_38 = 0 ;
V_23 -> V_219 += 1 ;
if ( V_23 -> V_219 >= V_23 -> V_33 )
V_23 -> V_219 = 0 ;
}
} else {
V_216 = F_97 () % V_23 -> V_33 ;
V_23 -> V_219 = V_216 ;
if ( V_23 -> V_217 [ V_216 ] . V_7 > V_23 -> V_34 ) {
V_23 -> V_217 [ V_216 ] . V_7 = 0 ;
V_23 -> V_217 [ V_216 ] . V_38 = 0 ;
}
}
return V_23 -> V_219 ;
}
static void F_98 ( struct V_22 * V_23 , int V_216 )
{
struct V_220 * V_221 = V_23 -> V_217 [ V_216 ] . V_221 ;
struct V_11 * V_12 = F_4 ( F_62 ( V_23 -> V_51 ) , V_16 ) ;
if ( ! V_221 ) {
V_221 = F_99 ( V_12 -> V_177 , V_222 ,
( V_223 * ) & V_23 -> V_100 ,
( V_223 * ) & V_23 -> V_99 ,
V_224 ,
V_23 -> V_225 ,
V_23 -> V_226 , 0 ) ;
if ( V_221 ) {
V_23 -> V_217 [ V_216 ] . V_221 = V_221 ;
F_92 ( V_23 ) ;
V_23 -> V_189 += V_221 -> V_227 . V_228 ;
}
}
}
static void F_100 ( struct V_22 * V_23 )
{
if ( V_23 -> V_38 & V_79 )
V_23 -> V_103 = F_101 () ;
else if ( V_23 -> V_35 <= V_23 -> V_36 ) {
T_9 V_149 ;
if ( V_23 -> V_38 & V_78 ) {
V_149 = F_97 () %
( V_23 -> V_36 -
V_23 -> V_35 + 1 )
+ V_23 -> V_35 ;
} else {
V_149 = V_23 -> V_103 + 1 ;
if ( V_149 > V_23 -> V_36 )
V_149 = V_23 -> V_35 ;
}
V_23 -> V_103 = V_149 ;
}
V_23 -> V_103 = V_23 -> V_103 % V_23 -> V_51 -> V_182 ;
}
static void F_102 ( struct V_22 * V_23 )
{
T_7 V_229 ;
T_7 V_230 ;
int V_216 = 0 ;
if ( V_23 -> V_33 )
V_216 = F_96 ( V_23 ) ;
if ( V_23 -> V_58 > 1 ) {
T_7 V_231 ;
T_7 V_116 ;
if ( V_23 -> V_38 & V_82 )
V_231 = F_97 () % V_23 -> V_58 ;
else {
V_231 = V_23 -> V_96 ++ ;
if ( V_23 -> V_96 >=
V_23 -> V_58 )
V_23 -> V_96 = 0 ;
}
V_116 = V_23 -> V_50 [ 5 ] + ( V_231 & 0xFF ) ;
V_23 -> V_143 [ 11 ] = V_116 ;
V_116 = ( V_23 -> V_50 [ 4 ] + ( ( V_231 >> 8 ) & 0xFF ) + ( V_116 >> 8 ) ) ;
V_23 -> V_143 [ 10 ] = V_116 ;
V_116 = ( V_23 -> V_50 [ 3 ] + ( ( V_231 >> 16 ) & 0xFF ) + ( V_116 >> 8 ) ) ;
V_23 -> V_143 [ 9 ] = V_116 ;
V_116 = ( V_23 -> V_50 [ 2 ] + ( ( V_231 >> 24 ) & 0xFF ) + ( V_116 >> 8 ) ) ;
V_23 -> V_143 [ 8 ] = V_116 ;
V_116 = ( V_23 -> V_50 [ 1 ] + ( V_116 >> 8 ) ) ;
V_23 -> V_143 [ 7 ] = V_116 ;
}
if ( V_23 -> V_59 > 1 ) {
T_7 V_231 ;
T_7 V_116 ;
if ( V_23 -> V_38 & V_83 )
V_231 = F_97 () % V_23 -> V_59 ;
else {
V_231 = V_23 -> V_95 ++ ;
if ( V_23 -> V_95 >=
V_23 -> V_59 ) {
V_23 -> V_95 = 0 ;
}
}
V_116 = V_23 -> V_53 [ 5 ] + ( V_231 & 0xFF ) ;
V_23 -> V_143 [ 5 ] = V_116 ;
V_116 = ( V_23 -> V_53 [ 4 ] + ( ( V_231 >> 8 ) & 0xFF ) + ( V_116 >> 8 ) ) ;
V_23 -> V_143 [ 4 ] = V_116 ;
V_116 = ( V_23 -> V_53 [ 3 ] + ( ( V_231 >> 16 ) & 0xFF ) + ( V_116 >> 8 ) ) ;
V_23 -> V_143 [ 3 ] = V_116 ;
V_116 = ( V_23 -> V_53 [ 2 ] + ( ( V_231 >> 24 ) & 0xFF ) + ( V_116 >> 8 ) ) ;
V_23 -> V_143 [ 2 ] = V_116 ;
V_116 = ( V_23 -> V_53 [ 1 ] + ( V_116 >> 8 ) ) ;
V_23 -> V_143 [ 1 ] = V_116 ;
}
if ( V_23 -> V_38 & V_77 ) {
unsigned int V_61 ;
for ( V_61 = 0 ; V_61 < V_23 -> V_60 ; V_61 ++ )
if ( V_23 -> V_62 [ V_61 ] & V_117 )
V_23 -> V_62 [ V_61 ] = V_117 |
( ( V_232 V_233 ) F_97 () &
F_29 ( 0x000fffff ) ) ;
}
if ( ( V_23 -> V_38 & V_84 ) && ( V_23 -> V_63 != 0xffff ) ) {
V_23 -> V_63 = F_97 () & ( 4096 - 1 ) ;
}
if ( ( V_23 -> V_38 & V_85 ) && ( V_23 -> V_66 != 0xffff ) ) {
V_23 -> V_66 = F_97 () & ( 4096 - 1 ) ;
}
if ( V_23 -> V_54 < V_23 -> V_55 ) {
if ( V_23 -> V_38 & V_75 )
V_23 -> V_102 = F_97 () %
( V_23 -> V_55 - V_23 -> V_54 )
+ V_23 -> V_54 ;
else {
V_23 -> V_102 ++ ;
if ( V_23 -> V_102 >= V_23 -> V_55 )
V_23 -> V_102 = V_23 -> V_54 ;
}
}
if ( V_23 -> V_56 < V_23 -> V_57 ) {
if ( V_23 -> V_38 & V_76 ) {
V_23 -> V_101 = F_97 () %
( V_23 -> V_57 - V_23 -> V_56 )
+ V_23 -> V_56 ;
} else {
V_23 -> V_101 ++ ;
if ( V_23 -> V_101 >= V_23 -> V_57 )
V_23 -> V_101 = V_23 -> V_56 ;
}
}
if ( ! ( V_23 -> V_38 & V_39 ) ) {
V_229 = F_17 ( V_23 -> V_141 ) ;
V_230 = F_17 ( V_23 -> V_142 ) ;
if ( V_229 < V_230 ) {
T_7 V_149 ;
if ( V_23 -> V_38 & V_72 )
V_149 = F_97 () % ( V_230 - V_229 ) + V_229 ;
else {
V_149 = F_17 ( V_23 -> V_99 ) ;
V_149 ++ ;
if ( V_149 > V_230 )
V_149 = V_229 ;
}
V_23 -> V_99 = F_29 ( V_149 ) ;
}
if ( V_23 -> V_33 && F_95 ( V_23 , V_216 ) ) {
V_23 -> V_100 = V_23 -> V_217 [ V_216 ] . V_100 ;
} else {
V_229 = F_17 ( V_23 -> V_138 ) ;
V_230 = F_17 ( V_23 -> V_139 ) ;
if ( V_229 < V_230 ) {
T_7 V_149 ;
V_233 V_234 ;
if ( V_23 -> V_38 & V_73 ) {
do {
V_149 = F_97 () %
( V_230 - V_229 ) + V_229 ;
V_234 = F_29 ( V_149 ) ;
} while ( F_103 ( V_234 ) ||
F_104 ( V_234 ) ||
F_105 ( V_234 ) ||
F_106 ( V_234 ) ||
F_107 ( V_234 ) );
V_23 -> V_100 = V_234 ;
} else {
V_149 = F_17 ( V_23 -> V_100 ) ;
V_149 ++ ;
if ( V_149 > V_230 ) {
V_149 = V_229 ;
}
V_23 -> V_100 = F_29 ( V_149 ) ;
}
}
if ( V_23 -> V_33 ) {
V_23 -> V_217 [ V_216 ] . V_38 |= V_218 ;
V_23 -> V_217 [ V_216 ] . V_100 =
V_23 -> V_100 ;
#ifdef F_18
if ( V_23 -> V_38 & V_81 )
F_98 ( V_23 , V_216 ) ;
#endif
V_23 -> V_104 ++ ;
}
}
} else {
if ( ! F_108 ( & V_23 -> V_44 ) ) {
int V_61 ;
for ( V_61 = 0 ; V_61 < 4 ; V_61 ++ ) {
V_23 -> V_98 . V_235 [ V_61 ] =
( ( ( V_232 V_233 ) F_97 () |
V_23 -> V_44 . V_235 [ V_61 ] ) &
V_23 -> V_45 . V_235 [ V_61 ] ) ;
}
}
}
if ( V_23 -> V_27 < V_23 -> V_28 ) {
T_7 V_149 ;
if ( V_23 -> V_38 & V_74 ) {
V_149 = F_97 () %
( V_23 -> V_28 - V_23 -> V_27 )
+ V_23 -> V_27 ;
} else {
V_149 = V_23 -> V_130 + 1 ;
if ( V_149 > V_23 -> V_28 )
V_149 = V_23 -> V_27 ;
}
V_23 -> V_130 = V_149 ;
}
F_100 ( V_23 ) ;
V_23 -> V_217 [ V_216 ] . V_7 ++ ;
}
static int F_109 ( struct V_236 * V_237 , struct V_22 * V_23 )
{
struct V_220 * V_221 = V_23 -> V_217 [ V_23 -> V_219 ] . V_221 ;
int V_9 = 0 ;
if ( ! V_221 )
return 0 ;
if ( V_221 -> V_227 . V_238 != V_239 )
return 0 ;
F_110 ( & V_221 -> V_193 ) ;
V_9 = V_221 -> V_240 -> V_241 ( V_221 , V_237 ) ;
if ( V_9 )
goto error;
V_9 = V_221 -> type -> V_241 ( V_221 , V_237 ) ;
if ( V_9 )
goto error;
V_221 -> V_242 . V_243 += V_237 -> V_115 ;
V_221 -> V_242 . V_244 ++ ;
error:
F_111 ( & V_221 -> V_193 ) ;
return V_9 ;
}
static void F_112 ( struct V_22 * V_23 )
{
if ( V_23 -> V_33 ) {
int V_61 ;
for ( V_61 = 0 ; V_61 < V_23 -> V_33 ; V_61 ++ ) {
struct V_220 * V_221 = V_23 -> V_217 [ V_61 ] . V_221 ;
if ( V_221 ) {
F_113 ( V_221 ) ;
V_23 -> V_217 [ V_61 ] . V_221 = NULL ;
}
}
}
}
static int F_114 ( struct V_22 * V_23 ,
struct V_236 * V_237 , T_10 V_245 )
{
if ( V_23 -> V_38 & V_81 ) {
struct V_220 * V_221 = V_23 -> V_217 [ V_23 -> V_219 ] . V_221 ;
int V_246 = 0 ;
if ( V_221 ) {
int V_150 ;
T_11 * V_247 ;
V_246 = V_221 -> V_227 . V_228 - F_115 ( V_237 ) ;
if ( V_246 > 0 ) {
V_150 = F_116 ( V_237 , V_246 , 0 , V_248 ) ;
if ( V_150 < 0 ) {
F_47 ( L_230 ,
V_150 ) ;
goto V_9;
}
}
F_117 ( V_237 , V_249 ) ;
V_150 = F_109 ( V_237 , V_23 ) ;
if ( V_150 ) {
F_47 ( L_231 , V_150 ) ;
goto V_9;
}
V_247 = ( T_11 * ) F_118 ( V_237 , V_249 ) ;
memcpy ( V_247 , V_23 -> V_143 , 12 ) ;
* ( V_250 * ) & V_247 [ 12 ] = V_245 ;
}
}
return 1 ;
V_9:
F_119 ( V_237 ) ;
return 0 ;
}
static void F_120 ( V_233 * V_251 , struct V_22 * V_23 )
{
unsigned int V_61 ;
for ( V_61 = 0 ; V_61 < V_23 -> V_60 ; V_61 ++ )
* V_251 ++ = V_23 -> V_62 [ V_61 ] & ~ V_117 ;
V_251 -- ;
* V_251 |= V_117 ;
}
static inline T_10 F_121 ( unsigned int V_252 , unsigned int V_253 ,
unsigned int V_254 )
{
return F_122 ( V_252 | ( V_253 << 12 ) | ( V_254 << 13 ) ) ;
}
static void F_123 ( struct V_22 * V_23 , struct V_236 * V_237 ,
int V_255 )
{
struct V_256 V_257 ;
struct V_188 * V_258 ;
V_258 = (struct V_188 * ) F_124 ( V_237 , sizeof( * V_258 ) ) ;
V_255 -= sizeof( * V_258 ) ;
if ( V_23 -> V_29 <= 0 ) {
memset ( F_124 ( V_237 , V_255 ) , 0 , V_255 ) ;
} else {
int V_259 = V_23 -> V_29 ;
int V_61 , V_115 ;
int V_260 ;
if ( V_259 > V_261 )
V_259 = V_261 ;
V_115 = V_255 - V_259 * V_262 ;
if ( V_115 > 0 ) {
memset ( F_124 ( V_237 , V_115 ) , 0 , V_115 ) ;
V_255 = V_259 * V_262 ;
}
V_61 = 0 ;
V_260 = ( V_255 / V_259 ) < V_262 ?
( V_255 / V_259 ) : V_262 ;
while ( V_255 > 0 ) {
if ( F_125 ( ! V_23 -> V_136 ) ) {
int V_71 = F_126 () ;
if ( V_23 -> V_71 >= 0 && ( V_23 -> V_38 & V_86 ) )
V_71 = V_23 -> V_71 ;
V_23 -> V_136 = F_127 ( V_71 , V_263 | V_264 , 0 ) ;
if ( ! V_23 -> V_136 )
break;
}
F_128 ( V_23 -> V_136 ) ;
F_129 ( V_237 , V_61 , V_23 -> V_136 ) ;
F_130 ( V_237 ) -> V_259 [ V_61 ] . V_265 = 0 ;
if ( V_61 == ( V_259 - 1 ) )
F_131 ( & F_130 ( V_237 ) -> V_259 [ V_61 ] ,
( V_255 < V_262 ? V_255 : V_262 ) ) ;
else
F_131 ( & F_130 ( V_237 ) -> V_259 [ V_61 ] , V_260 ) ;
V_255 -= F_132 ( & F_130 ( V_237 ) -> V_259 [ V_61 ] ) ;
V_237 -> V_115 += F_132 ( & F_130 ( V_237 ) -> V_259 [ V_61 ] ) ;
V_237 -> V_266 += F_132 ( & F_130 ( V_237 ) -> V_259 [ V_61 ] ) ;
V_61 ++ ;
F_130 ( V_237 ) -> V_267 = V_61 ;
}
}
V_258 -> V_268 = F_29 ( V_269 ) ;
V_258 -> V_94 = F_29 ( V_23 -> V_94 ) ;
F_133 ( & V_257 ) ;
V_258 -> V_270 = F_29 ( V_257 . V_270 ) ;
V_258 -> V_271 = F_29 ( V_257 . V_271 ) ;
}
static struct V_236 * F_134 ( struct V_162 * V_163 ,
struct V_22 * V_23 ,
unsigned int V_272 )
{
struct V_236 * V_237 = NULL ;
unsigned int V_273 = V_23 -> V_130 + 64 + V_272 +
V_23 -> V_189 ;
if ( V_23 -> V_38 & V_86 ) {
int V_71 = V_23 -> V_71 >= 0 ? V_23 -> V_71 : F_126 () ;
V_237 = F_135 ( V_274 + V_273 , V_275 , 0 , V_71 ) ;
if ( F_86 ( V_237 ) ) {
F_136 ( V_237 , V_274 ) ;
V_237 -> V_163 = V_163 ;
}
} else {
V_237 = F_137 ( V_163 , V_273 , V_275 ) ;
}
return V_237 ;
}
static struct V_236 * F_138 ( struct V_162 * V_51 ,
struct V_22 * V_23 )
{
struct V_236 * V_237 = NULL ;
T_11 * V_247 ;
struct V_187 * V_276 ;
int V_255 , V_277 ;
struct V_198 * V_278 ;
T_10 V_245 = F_122 ( V_279 ) ;
V_233 * V_251 ;
T_10 * V_280 = NULL ;
T_10 * V_281 = NULL ;
T_10 * V_282 = NULL ;
T_10 * V_283 = NULL ;
V_250 V_284 ;
if ( V_23 -> V_60 )
V_245 = F_122 ( V_285 ) ;
if ( V_23 -> V_63 != 0xffff )
V_245 = F_122 ( V_286 ) ;
F_102 ( V_23 ) ;
V_284 = V_23 -> V_103 ;
V_255 = ( V_51 -> V_287 + 16 ) & ~ 0xf ;
V_237 = F_134 ( V_51 , V_23 , V_255 ) ;
if ( ! V_237 ) {
sprintf ( V_23 -> V_105 , L_232 ) ;
return NULL ;
}
F_139 ( V_237 -> V_10 ) ;
F_136 ( V_237 , V_255 ) ;
V_247 = ( T_11 * ) F_118 ( V_237 , 14 ) ;
V_251 = ( V_233 * ) F_124 ( V_237 , V_23 -> V_60 * sizeof( T_7 ) ) ;
if ( V_23 -> V_60 )
F_120 ( V_251 , V_23 ) ;
if ( V_23 -> V_63 != 0xffff ) {
if ( V_23 -> V_66 != 0xffff ) {
V_282 = ( T_10 * ) F_124 ( V_237 , sizeof( T_10 ) ) ;
* V_282 = F_121 ( V_23 -> V_66 ,
V_23 -> V_68 ,
V_23 -> V_67 ) ;
V_283 = ( T_10 * ) F_124 ( V_237 , sizeof( T_10 ) ) ;
* V_283 = F_122 ( V_286 ) ;
}
V_280 = ( T_10 * ) F_124 ( V_237 , sizeof( T_10 ) ) ;
* V_280 = F_121 ( V_23 -> V_63 ,
V_23 -> V_65 ,
V_23 -> V_64 ) ;
V_281 = ( T_10 * ) F_124 ( V_237 , sizeof( T_10 ) ) ;
* V_281 = F_122 ( V_279 ) ;
}
F_140 ( V_237 , 0 ) ;
F_141 ( V_237 , V_237 -> V_115 ) ;
V_278 = (struct V_198 * ) F_124 ( V_237 , sizeof( struct V_198 ) ) ;
F_142 ( V_237 , V_237 -> V_115 ) ;
V_276 = (struct V_187 * ) F_124 ( V_237 , sizeof( struct V_187 ) ) ;
F_143 ( V_237 , V_284 ) ;
V_237 -> V_288 = V_23 -> V_37 ;
memcpy ( V_247 , V_23 -> V_143 , 12 ) ;
* ( T_10 * ) & V_247 [ 12 ] = V_245 ;
V_255 = V_23 -> V_130 - 14 - 20 - 8 -
V_23 -> V_189 ;
if ( V_255 < 0 || V_255 < sizeof( struct V_188 ) )
V_255 = sizeof( struct V_188 ) ;
V_276 -> V_289 = F_122 ( V_23 -> V_102 ) ;
V_276 -> V_290 = F_122 ( V_23 -> V_101 ) ;
V_276 -> V_115 = F_122 ( V_255 + 8 ) ;
V_276 -> V_291 = 0 ;
V_278 -> V_292 = 5 ;
V_278 -> V_4 = 4 ;
V_278 -> V_293 = 32 ;
V_278 -> V_69 = V_23 -> V_69 ;
V_278 -> V_245 = V_294 ;
V_278 -> V_295 = V_23 -> V_99 ;
V_278 -> V_296 = V_23 -> V_100 ;
V_278 -> V_252 = F_122 ( V_23 -> V_297 ) ;
V_23 -> V_297 ++ ;
V_278 -> V_298 = 0 ;
V_277 = 20 + 8 + V_255 ;
V_278 -> V_299 = F_122 ( V_277 ) ;
V_278 -> V_291 = 0 ;
V_278 -> V_291 = F_144 ( ( void * ) V_278 , V_278 -> V_292 ) ;
V_237 -> V_245 = V_245 ;
V_237 -> V_163 = V_51 ;
V_237 -> V_300 = V_301 ;
F_123 ( V_23 , V_237 , V_255 ) ;
#ifdef F_18
if ( ! F_114 ( V_23 , V_237 , V_245 ) )
return NULL ;
#endif
return V_237 ;
}
static struct V_236 * F_145 ( struct V_162 * V_51 ,
struct V_22 * V_23 )
{
struct V_236 * V_237 = NULL ;
T_11 * V_247 ;
struct V_187 * V_276 ;
int V_255 ;
struct V_186 * V_278 ;
T_10 V_245 = F_122 ( V_302 ) ;
V_233 * V_251 ;
T_10 * V_280 = NULL ;
T_10 * V_281 = NULL ;
T_10 * V_282 = NULL ;
T_10 * V_283 = NULL ;
V_250 V_284 ;
if ( V_23 -> V_60 )
V_245 = F_122 ( V_285 ) ;
if ( V_23 -> V_63 != 0xffff )
V_245 = F_122 ( V_286 ) ;
F_102 ( V_23 ) ;
V_284 = V_23 -> V_103 ;
V_237 = F_134 ( V_51 , V_23 , 16 ) ;
if ( ! V_237 ) {
sprintf ( V_23 -> V_105 , L_232 ) ;
return NULL ;
}
F_139 ( V_237 -> V_10 ) ;
F_136 ( V_237 , 16 ) ;
V_247 = ( T_11 * ) F_118 ( V_237 , 14 ) ;
V_251 = ( V_233 * ) F_124 ( V_237 , V_23 -> V_60 * sizeof( T_7 ) ) ;
if ( V_23 -> V_60 )
F_120 ( V_251 , V_23 ) ;
if ( V_23 -> V_63 != 0xffff ) {
if ( V_23 -> V_66 != 0xffff ) {
V_282 = ( T_10 * ) F_124 ( V_237 , sizeof( T_10 ) ) ;
* V_282 = F_121 ( V_23 -> V_66 ,
V_23 -> V_68 ,
V_23 -> V_67 ) ;
V_283 = ( T_10 * ) F_124 ( V_237 , sizeof( T_10 ) ) ;
* V_283 = F_122 ( V_286 ) ;
}
V_280 = ( T_10 * ) F_124 ( V_237 , sizeof( T_10 ) ) ;
* V_280 = F_121 ( V_23 -> V_63 ,
V_23 -> V_65 ,
V_23 -> V_64 ) ;
V_281 = ( T_10 * ) F_124 ( V_237 , sizeof( T_10 ) ) ;
* V_281 = F_122 ( V_302 ) ;
}
F_140 ( V_237 , 0 ) ;
F_141 ( V_237 , V_237 -> V_115 ) ;
V_278 = (struct V_186 * ) F_124 ( V_237 , sizeof( struct V_186 ) ) ;
F_142 ( V_237 , V_237 -> V_115 ) ;
V_276 = (struct V_187 * ) F_124 ( V_237 , sizeof( struct V_187 ) ) ;
F_143 ( V_237 , V_284 ) ;
V_237 -> V_288 = V_23 -> V_37 ;
memcpy ( V_247 , V_23 -> V_143 , 12 ) ;
* ( T_10 * ) & V_247 [ 12 ] = V_245 ;
V_255 = V_23 -> V_130 - 14 -
sizeof( struct V_186 ) - sizeof( struct V_187 ) -
V_23 -> V_189 ;
if ( V_255 < 0 || V_255 < sizeof( struct V_188 ) ) {
V_255 = sizeof( struct V_188 ) ;
F_146 ( L_233 , V_255 ) ;
}
V_276 -> V_289 = F_122 ( V_23 -> V_102 ) ;
V_276 -> V_290 = F_122 ( V_23 -> V_101 ) ;
V_276 -> V_115 = F_122 ( V_255 + sizeof( struct V_187 ) ) ;
V_276 -> V_291 = 0 ;
* ( V_233 * ) V_278 = F_29 ( 0x60000000 ) ;
if ( V_23 -> V_70 ) {
* ( V_233 * ) V_278 |= F_29 ( 0x60000000 | ( V_23 -> V_70 << 20 ) ) ;
}
V_278 -> V_303 = 32 ;
V_278 -> V_304 = F_122 ( sizeof( struct V_187 ) + V_255 ) ;
V_278 -> V_305 = V_294 ;
V_278 -> V_296 = V_23 -> V_98 ;
V_278 -> V_295 = V_23 -> V_97 ;
V_237 -> V_245 = V_245 ;
V_237 -> V_163 = V_51 ;
V_237 -> V_300 = V_301 ;
F_123 ( V_23 , V_237 , V_255 ) ;
return V_237 ;
}
static struct V_236 * F_147 ( struct V_162 * V_51 ,
struct V_22 * V_23 )
{
if ( V_23 -> V_38 & V_39 )
return F_145 ( V_51 , V_23 ) ;
else
return F_138 ( V_51 , V_23 ) ;
}
static void F_39 ( struct V_22 * V_23 )
{
V_23 -> V_94 = 1 ;
V_23 -> V_89 = 0 ;
V_23 -> V_91 = 0 ;
V_23 -> V_306 = 0 ;
V_23 -> V_92 = 0 ;
}
static void F_148 ( struct V_148 * V_149 )
{
struct V_22 * V_23 ;
int V_307 = 0 ;
F_149 () ;
F_43 ( V_149 ) ;
F_44 (pkt_dev, &t->if_list, list) {
F_68 ( V_23 ) ;
if ( V_23 -> V_51 ) {
F_39 ( V_23 ) ;
V_23 -> V_87 = 1 ;
V_23 -> V_237 = NULL ;
V_23 -> V_93 = V_23 -> V_211 = F_19 () ;
F_92 ( V_23 ) ;
strcpy ( V_23 -> V_105 , L_234 ) ;
V_307 ++ ;
} else
strcpy ( V_23 -> V_105 , L_235 ) ;
}
F_45 ( V_149 ) ;
if ( V_307 )
V_149 -> V_152 &= ~ ( V_308 ) ;
}
static void F_7 ( struct V_11 * V_12 )
{
struct V_148 * V_149 ;
F_149 () ;
F_48 ( & V_151 ) ;
F_44 (t, &pn->pktgen_threads, th_list)
V_149 -> V_152 |= V_308 ;
F_50 ( & V_151 ) ;
}
static int F_150 ( const struct V_148 * V_149 )
{
const struct V_22 * V_23 ;
F_44 (pkt_dev, &t->if_list, list)
if ( V_23 -> V_87 )
return 1 ;
return 0 ;
}
static int F_151 ( struct V_148 * V_149 )
{
F_43 ( V_149 ) ;
while ( F_150 ( V_149 ) ) {
F_45 ( V_149 ) ;
F_152 ( 100 ) ;
if ( F_89 ( V_13 ) )
goto signal;
F_43 ( V_149 ) ;
}
F_45 ( V_149 ) ;
return 1 ;
signal:
return 0 ;
}
static int F_153 ( struct V_11 * V_12 )
{
struct V_148 * V_149 ;
int V_309 = 1 ;
F_48 ( & V_151 ) ;
F_44 (t, &pn->pktgen_threads, th_list) {
V_309 = F_151 ( V_149 ) ;
if ( V_309 == 0 )
break;
}
if ( V_309 == 0 )
F_44 (t, &pn->pktgen_threads, th_list)
V_149 -> V_152 |= ( V_308 ) ;
F_50 ( & V_151 ) ;
return V_309 ;
}
static void F_8 ( struct V_11 * V_12 )
{
struct V_148 * V_149 ;
F_149 () ;
F_48 ( & V_151 ) ;
F_44 (t, &pn->pktgen_threads, th_list)
V_149 -> V_152 |= ( V_310 ) ;
F_50 ( & V_151 ) ;
F_51 ( F_52 ( 125 ) ) ;
F_153 ( V_12 ) ;
}
static void F_9 ( struct V_11 * V_12 )
{
struct V_148 * V_149 ;
F_149 () ;
F_48 ( & V_151 ) ;
F_44 (t, &pn->pktgen_threads, th_list)
V_149 -> V_152 |= ( V_153 ) ;
F_50 ( & V_151 ) ;
F_51 ( F_52 ( 125 ) ) ;
F_153 ( V_12 ) ;
}
static void F_154 ( struct V_22 * V_23 , int V_267 )
{
T_12 V_311 , V_312 , V_313 ;
char * V_314 = V_23 -> V_105 ;
T_5 V_315 = F_91 ( V_23 -> V_88 ,
V_23 -> V_93 ) ;
T_5 V_26 = F_155 ( V_23 -> V_89 ) ;
V_314 += sprintf ( V_314 , L_236 ,
( unsigned long long ) F_21 ( V_315 ) ,
( unsigned long long ) F_21 ( F_91 ( V_315 , V_26 ) ) ,
( unsigned long long ) F_21 ( V_26 ) ,
( unsigned long long ) V_23 -> V_91 ,
V_23 -> V_130 , V_267 ) ;
V_313 = F_156 ( V_23 -> V_91 * V_132 ,
F_78 ( V_315 ) ) ;
V_311 = V_313 * 8 * V_23 -> V_130 ;
V_312 = V_311 ;
F_20 ( V_312 , 1000000 ) ;
V_314 += sprintf ( V_314 , L_237 ,
( unsigned long long ) V_313 ,
( unsigned long long ) V_312 ,
( unsigned long long ) V_311 ,
( unsigned long long ) V_23 -> V_92 ) ;
}
static int F_157 ( struct V_22 * V_23 )
{
int V_267 = V_23 -> V_237 ? F_130 ( V_23 -> V_237 ) -> V_267 : - 1 ;
if ( ! V_23 -> V_87 ) {
F_10 ( L_238 ,
V_23 -> V_32 ) ;
return - V_126 ;
}
F_119 ( V_23 -> V_237 ) ;
V_23 -> V_237 = NULL ;
V_23 -> V_88 = F_19 () ;
V_23 -> V_87 = 0 ;
F_154 ( V_23 , V_267 ) ;
return 0 ;
}
static struct V_22 * F_158 ( struct V_148 * V_149 )
{
struct V_22 * V_23 , * V_316 = NULL ;
F_43 ( V_149 ) ;
F_44 (pkt_dev, &t->if_list, list) {
if ( ! V_23 -> V_87 )
continue;
if ( V_316 == NULL )
V_316 = V_23 ;
else if ( F_81 ( V_23 -> V_211 , V_316 -> V_211 ) < 0 )
V_316 = V_23 ;
}
F_45 ( V_149 ) ;
return V_316 ;
}
static void F_159 ( struct V_148 * V_149 )
{
struct V_22 * V_23 ;
F_149 () ;
F_43 ( V_149 ) ;
F_44 (pkt_dev, &t->if_list, list) {
F_157 ( V_23 ) ;
}
F_45 ( V_149 ) ;
}
static void F_160 ( struct V_148 * V_149 )
{
struct V_317 * V_318 , * V_114 ;
struct V_22 * V_319 ;
F_149 () ;
F_43 ( V_149 ) ;
F_161 (q, n, &t->if_list) {
V_319 = F_162 ( V_318 , struct V_22 , V_320 ) ;
if ( ! V_319 -> V_157 )
continue;
F_119 ( V_319 -> V_237 ) ;
V_319 -> V_237 = NULL ;
F_163 ( V_149 , V_319 ) ;
break;
}
F_45 ( V_149 ) ;
}
static void F_164 ( struct V_148 * V_149 )
{
struct V_317 * V_318 , * V_114 ;
struct V_22 * V_319 ;
F_149 () ;
F_43 ( V_149 ) ;
F_161 (q, n, &t->if_list) {
V_319 = F_162 ( V_318 , struct V_22 , V_320 ) ;
F_119 ( V_319 -> V_237 ) ;
V_319 -> V_237 = NULL ;
F_163 ( V_149 , V_319 ) ;
}
F_45 ( V_149 ) ;
}
static void F_165 ( struct V_148 * V_149 )
{
F_166 ( V_149 -> V_321 -> V_322 , V_149 -> V_177 -> V_165 ) ;
}
static void F_167 ( struct V_22 * V_23 )
{
T_5 V_323 = F_19 () ;
F_87 () ;
V_23 -> V_89 += F_78 ( F_91 ( F_19 () , V_323 ) ) ;
}
static void F_168 ( struct V_22 * V_23 )
{
T_5 V_323 = F_19 () ;
while ( F_169 ( & ( V_23 -> V_237 -> V_324 ) ) != 1 ) {
if ( F_89 ( V_13 ) )
break;
if ( F_170 () )
F_167 ( V_23 ) ;
else
F_171 () ;
}
V_23 -> V_89 += F_78 ( F_91 ( F_19 () , V_323 ) ) ;
}
static void F_172 ( struct V_22 * V_23 )
{
struct V_162 * V_51 = V_23 -> V_51 ;
T_13 (* F_173)( struct V_236 * , struct V_162 * )
= V_51 -> V_325 -> V_326 ;
struct V_327 * V_328 ;
V_250 V_284 ;
int V_150 ;
if ( F_125 ( ! F_67 ( V_51 ) || ! F_174 ( V_51 ) ) ) {
F_157 ( V_23 ) ;
return;
}
if ( F_125 ( V_23 -> V_30 == V_131 ) ) {
V_23 -> V_211 = F_80 ( F_19 () , V_329 ) ;
return;
}
if ( ! V_23 -> V_237 || ( V_23 -> V_330 &&
++ V_23 -> V_331 >= V_23 -> V_31 ) ) {
F_119 ( V_23 -> V_237 ) ;
V_23 -> V_237 = F_147 ( V_51 , V_23 ) ;
if ( V_23 -> V_237 == NULL ) {
F_47 ( L_239 ) ;
F_87 () ;
V_23 -> V_331 -- ;
return;
}
V_23 -> V_332 = V_23 -> V_237 -> V_115 ;
V_23 -> V_333 ++ ;
V_23 -> V_331 = 0 ;
}
if ( V_23 -> V_30 && V_23 -> V_330 )
F_75 ( V_23 , V_23 -> V_211 ) ;
V_284 = F_175 ( V_23 -> V_237 ) ;
V_328 = F_176 ( V_51 , V_284 ) ;
F_177 ( V_328 ) ;
if ( F_125 ( F_178 ( V_328 ) ) ) {
V_150 = V_334 ;
V_23 -> V_330 = 0 ;
goto V_335;
}
F_179 ( & ( V_23 -> V_237 -> V_324 ) ) ;
V_150 = (* F_173)( V_23 -> V_237 , V_51 ) ;
switch ( V_150 ) {
case V_336 :
F_180 ( V_328 ) ;
V_23 -> V_330 = 1 ;
V_23 -> V_91 ++ ;
V_23 -> V_94 ++ ;
V_23 -> V_306 += V_23 -> V_332 ;
break;
case V_337 :
case V_338 :
case V_339 :
V_23 -> V_92 ++ ;
break;
default:
F_146 ( L_240 ,
V_23 -> V_32 , V_150 ) ;
V_23 -> V_92 ++ ;
case V_340 :
case V_334 :
F_181 ( & ( V_23 -> V_237 -> V_324 ) ) ;
V_23 -> V_330 = 0 ;
}
V_335:
F_182 ( V_328 ) ;
if ( ( V_23 -> V_7 != 0 ) && ( V_23 -> V_91 >= V_23 -> V_7 ) ) {
F_168 ( V_23 ) ;
F_157 ( V_23 ) ;
}
}
static int F_183 ( void * V_341 )
{
F_184 ( V_342 ) ;
struct V_148 * V_149 = V_341 ;
struct V_22 * V_23 = NULL ;
int V_343 = V_149 -> V_343 ;
F_42 ( F_101 () != V_343 ) ;
F_185 ( & V_149 -> V_344 ) ;
F_186 ( & V_149 -> V_345 ) ;
F_32 ( L_241 , V_343 , F_187 ( V_13 ) ) ;
F_83 ( V_212 ) ;
F_188 () ;
while ( ! F_189 () ) {
V_23 = F_158 ( V_149 ) ;
if ( F_125 ( ! V_23 && V_149 -> V_152 == 0 ) ) {
if ( V_149 -> V_177 -> V_171 )
break;
F_190 ( V_149 -> V_344 ,
V_149 -> V_152 != 0 ,
V_346 / 10 ) ;
F_191 () ;
continue;
}
F_90 ( V_214 ) ;
if ( F_86 ( V_23 ) ) {
F_172 ( V_23 ) ;
if ( F_170 () )
F_167 ( V_23 ) ;
else
F_171 () ;
}
if ( V_149 -> V_152 & V_308 ) {
F_159 ( V_149 ) ;
V_149 -> V_152 &= ~ ( V_308 ) ;
}
if ( V_149 -> V_152 & V_310 ) {
F_148 ( V_149 ) ;
V_149 -> V_152 &= ~ ( V_310 ) ;
}
if ( V_149 -> V_152 & V_153 ) {
F_164 ( V_149 ) ;
V_149 -> V_152 &= ~ ( V_153 ) ;
}
if ( V_149 -> V_152 & V_158 ) {
F_160 ( V_149 ) ;
V_149 -> V_152 &= ~ ( V_158 ) ;
}
F_191 () ;
F_83 ( V_212 ) ;
}
F_32 ( L_242 , V_149 -> V_321 -> V_322 ) ;
F_159 ( V_149 ) ;
F_32 ( L_243 , V_149 -> V_321 -> V_322 ) ;
F_164 ( V_149 ) ;
F_32 ( L_244 , V_149 -> V_321 -> V_322 ) ;
F_165 ( V_149 ) ;
while ( ! F_189 () ) {
F_83 ( V_212 ) ;
F_87 () ;
}
F_90 ( V_214 ) ;
return 0 ;
}
static struct V_22 * F_55 ( struct V_148 * V_149 ,
const char * V_154 , bool V_155 )
{
struct V_22 * V_314 , * V_23 = NULL ;
T_3 V_115 = strlen ( V_154 ) ;
F_43 ( V_149 ) ;
F_44 (p, &t->if_list, list)
if ( strncmp ( V_314 -> V_32 , V_154 , V_115 ) == 0 ) {
if ( V_314 -> V_32 [ V_115 ] ) {
if ( V_155 || V_314 -> V_32 [ V_115 ] != '@' )
continue;
}
V_23 = V_314 ;
break;
}
F_45 ( V_149 ) ;
F_32 ( L_245 , V_154 , V_23 ) ;
return V_23 ;
}
static int F_192 ( struct V_148 * V_149 ,
struct V_22 * V_23 )
{
int V_347 = 0 ;
F_43 ( V_149 ) ;
if ( V_23 -> V_348 ) {
F_47 ( L_246 ) ;
V_347 = - V_349 ;
goto V_19;
}
F_193 ( & V_23 -> V_320 , & V_149 -> V_350 ) ;
V_23 -> V_348 = V_149 ;
V_23 -> V_87 = 0 ;
V_19:
F_45 ( V_149 ) ;
return V_347 ;
}
static int F_49 ( struct V_148 * V_149 , const char * V_154 )
{
struct V_22 * V_23 ;
int V_9 ;
int V_71 = F_194 ( V_149 -> V_343 ) ;
V_23 = F_54 ( V_149 -> V_177 , V_154 , V_156 ) ;
if ( V_23 ) {
F_47 ( L_247 ) ;
return - V_349 ;
}
V_23 = F_195 ( sizeof( struct V_22 ) , V_263 , V_71 ) ;
if ( ! V_23 )
return - V_351 ;
strcpy ( V_23 -> V_32 , V_154 ) ;
V_23 -> V_217 = F_196 ( V_145 * sizeof( struct V_352 ) ,
V_71 ) ;
if ( V_23 -> V_217 == NULL ) {
F_197 ( V_23 ) ;
return - V_351 ;
}
V_23 -> V_157 = 0 ;
V_23 -> V_29 = 0 ;
V_23 -> V_30 = V_353 ;
V_23 -> V_7 = V_354 ;
V_23 -> V_91 = 0 ;
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
V_9 = F_65 ( V_149 -> V_177 , V_23 , V_154 ) ;
if ( V_9 )
goto V_355;
if ( V_23 -> V_51 -> V_133 & V_134 )
V_23 -> V_31 = V_356 ;
V_23 -> V_164 = F_59 ( V_154 , 0600 , V_149 -> V_177 -> V_165 ,
& V_166 , V_23 ) ;
if ( ! V_23 -> V_164 ) {
F_47 ( L_248 ,
V_357 , V_154 ) ;
V_9 = - V_126 ;
goto V_358;
}
#ifdef F_18
V_23 -> V_225 = V_239 ;
V_23 -> V_226 = V_359 ;
#endif
return F_192 ( V_149 , V_23 ) ;
V_358:
F_66 ( V_23 -> V_51 ) ;
V_355:
#ifdef F_18
F_112 ( V_23 ) ;
#endif
F_198 ( V_23 -> V_217 ) ;
F_197 ( V_23 ) ;
return V_9 ;
}
static int T_14 F_199 ( int V_343 , struct V_11 * V_12 )
{
struct V_148 * V_149 ;
struct V_360 * V_361 ;
struct V_362 * V_314 ;
V_149 = F_195 ( sizeof( struct V_148 ) , V_263 ,
F_194 ( V_343 ) ) ;
if ( ! V_149 ) {
F_47 ( L_249 ) ;
return - V_351 ;
}
F_200 ( & V_149 -> F_43 ) ;
V_149 -> V_343 = V_343 ;
F_201 ( & V_149 -> V_350 ) ;
F_202 ( & V_149 -> V_363 , & V_12 -> V_364 ) ;
F_203 ( & V_149 -> V_345 ) ;
V_314 = F_204 ( F_183 ,
V_149 ,
F_194 ( V_343 ) ,
L_250 , V_343 ) ;
if ( F_205 ( V_314 ) ) {
F_47 ( L_251 , V_149 -> V_343 ) ;
F_206 ( & V_149 -> V_363 ) ;
F_197 ( V_149 ) ;
return F_207 ( V_314 ) ;
}
F_208 ( V_314 , V_343 ) ;
V_149 -> V_321 = V_314 ;
V_361 = F_59 ( V_149 -> V_321 -> V_322 , 0600 , V_12 -> V_165 ,
& V_365 , V_149 ) ;
if ( ! V_361 ) {
F_47 ( L_248 ,
V_357 , V_149 -> V_321 -> V_322 ) ;
F_209 ( V_314 ) ;
F_206 ( & V_149 -> V_363 ) ;
F_197 ( V_149 ) ;
return - V_126 ;
}
V_149 -> V_177 = V_12 ;
F_210 ( V_314 ) ;
F_211 ( & V_149 -> V_345 ) ;
return 0 ;
}
static void F_212 ( struct V_148 * V_149 ,
struct V_22 * V_23 )
{
struct V_317 * V_318 , * V_114 ;
struct V_22 * V_314 ;
F_161 (q, n, &t->if_list) {
V_314 = F_162 ( V_318 , struct V_22 , V_320 ) ;
if ( V_314 == V_23 )
F_206 ( & V_314 -> V_320 ) ;
}
}
static int F_163 ( struct V_148 * V_149 ,
struct V_22 * V_23 )
{
F_32 ( L_252 , V_23 ) ;
if ( V_23 -> V_87 ) {
F_10 ( L_253 ) ;
F_157 ( V_23 ) ;
}
if ( V_23 -> V_51 ) {
F_66 ( V_23 -> V_51 ) ;
V_23 -> V_51 = NULL ;
}
F_212 ( V_149 , V_23 ) ;
if ( V_23 -> V_164 )
F_58 ( V_23 -> V_164 ) ;
#ifdef F_18
F_112 ( V_23 ) ;
#endif
F_198 ( V_23 -> V_217 ) ;
if ( V_23 -> V_136 )
F_35 ( V_23 -> V_136 ) ;
F_197 ( V_23 ) ;
return 0 ;
}
static int T_14 F_213 ( struct V_177 * V_177 )
{
struct V_11 * V_12 = F_4 ( V_177 , V_16 ) ;
struct V_360 * V_361 ;
int V_343 , V_150 = 0 ;
V_12 -> V_177 = V_177 ;
F_201 ( & V_12 -> V_364 ) ;
V_12 -> V_171 = false ;
V_12 -> V_165 = F_214 ( V_357 , V_12 -> V_177 -> V_366 ) ;
if ( ! V_12 -> V_165 ) {
F_215 ( L_254 , V_357 ) ;
return - V_178 ;
}
V_361 = F_216 ( V_367 , 0600 , V_12 -> V_165 , & V_368 ) ;
if ( V_361 == NULL ) {
F_47 ( L_255 , V_367 ) ;
V_150 = - V_126 ;
goto remove;
}
F_217 (cpu) {
int V_9 ;
V_9 = F_199 ( V_343 , V_12 ) ;
if ( V_9 )
F_215 ( L_256 ,
V_343 , V_9 ) ;
}
if ( F_218 ( & V_12 -> V_364 ) ) {
F_47 ( L_257 ) ;
V_150 = - V_178 ;
goto V_369;
}
return 0 ;
V_369:
F_166 ( V_367 , V_12 -> V_165 ) ;
remove:
F_166 ( V_357 , V_12 -> V_177 -> V_366 ) ;
return V_150 ;
}
static void T_15 F_219 ( struct V_177 * V_177 )
{
struct V_11 * V_12 = F_4 ( V_177 , V_16 ) ;
struct V_148 * V_149 ;
struct V_317 * V_318 , * V_114 ;
F_220 ( V_320 ) ;
V_12 -> V_171 = true ;
F_48 ( & V_151 ) ;
F_221 ( & V_12 -> V_364 , & V_320 ) ;
F_50 ( & V_151 ) ;
F_161 (q, n, &list) {
V_149 = F_162 ( V_318 , struct V_148 , V_363 ) ;
F_206 ( & V_149 -> V_363 ) ;
F_209 ( V_149 -> V_321 ) ;
F_197 ( V_149 ) ;
}
F_166 ( V_367 , V_12 -> V_165 ) ;
F_166 ( V_357 , V_12 -> V_177 -> V_366 ) ;
}
static int T_16 F_222 ( void )
{
int V_150 = 0 ;
F_33 ( L_258 , V_4 ) ;
V_150 = F_223 ( & V_370 ) ;
if ( V_150 )
return V_150 ;
V_150 = F_224 ( & V_371 ) ;
if ( V_150 )
F_225 ( & V_370 ) ;
return V_150 ;
}
static void T_17 F_226 ( void )
{
F_227 ( & V_371 ) ;
F_225 ( & V_370 ) ;
}
