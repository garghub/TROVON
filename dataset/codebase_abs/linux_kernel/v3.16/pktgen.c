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
if ( V_22 -> V_70 >= 0 )
F_15 ( V_2 , L_29 , V_22 -> V_70 ) ;
F_2 ( V_2 , L_30 ) ;
if ( V_22 -> V_37 & V_38 )
F_2 ( V_2 , L_31 ) ;
if ( V_22 -> V_37 & V_71 )
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
if ( V_22 -> V_32 ) {
if ( V_22 -> V_37 & V_80 )
F_2 ( V_2 , L_41 ) ;
else
F_2 ( V_2 , L_42 ) ;
}
#ifdef F_18
if ( V_22 -> V_37 & V_81 ) {
F_2 ( V_2 , L_43 ) ;
if ( V_22 -> V_82 )
F_15 ( V_2 , L_44 , V_22 -> V_82 ) ;
}
#endif
if ( V_22 -> V_37 & V_83 )
F_2 ( V_2 , L_45 ) ;
if ( V_22 -> V_37 & V_84 )
F_2 ( V_2 , L_46 ) ;
if ( V_22 -> V_37 & V_85 )
F_2 ( V_2 , L_47 ) ;
if ( V_22 -> V_37 & V_86 )
F_2 ( V_2 , L_48 ) ;
if ( V_22 -> V_37 & V_87 )
F_2 ( V_2 , L_49 ) ;
F_2 ( V_2 , L_23 ) ;
V_24 = V_22 -> V_88 ? F_19 () : V_22 -> V_89 ;
V_25 = V_22 -> V_90 ;
F_20 ( V_25 , V_91 ) ;
F_15 ( V_2 ,
L_50 ,
( unsigned long long ) V_22 -> V_92 ,
( unsigned long long ) V_22 -> V_93 ) ;
F_15 ( V_2 ,
L_51 ,
( unsigned long long ) F_21 ( V_22 -> V_94 ) ,
( unsigned long long ) F_21 ( V_24 ) ,
( unsigned long long ) V_25 ) ;
F_15 ( V_2 ,
L_52 ,
V_22 -> V_95 , V_22 -> V_96 ,
V_22 -> V_97 ) ;
if ( V_22 -> V_37 & V_38 ) {
F_15 ( V_2 , L_53 ,
& V_22 -> V_98 ,
& V_22 -> V_99 ) ;
} else
F_15 ( V_2 , L_54 ,
& V_22 -> V_100 , & V_22 -> V_101 ) ;
F_15 ( V_2 , L_55 ,
V_22 -> V_102 , V_22 -> V_103 ) ;
F_15 ( V_2 , L_56 , V_22 -> V_104 ) ;
F_15 ( V_2 , L_57 , V_22 -> V_105 ) ;
if ( V_22 -> V_106 [ 0 ] )
F_15 ( V_2 , L_58 , V_22 -> V_106 ) ;
else
F_2 ( V_2 , L_59 ) ;
return 0 ;
}
static int F_22 ( const char T_2 * V_107 , unsigned long V_108 ,
T_7 * V_109 )
{
int V_60 = 0 ;
* V_109 = 0 ;
for (; V_60 < V_108 ; V_60 ++ ) {
int V_110 ;
char V_111 ;
* V_109 <<= 4 ;
if ( F_23 ( V_111 , & V_107 [ V_60 ] ) )
return - V_19 ;
V_110 = F_24 ( V_111 ) ;
if ( V_110 >= 0 )
* V_109 |= V_110 ;
else
break;
}
return V_60 ;
}
static int F_25 ( const char T_2 * V_107 ,
unsigned int V_108 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_108 ; V_60 ++ ) {
char V_111 ;
if ( F_23 ( V_111 , & V_107 [ V_60 ] ) )
return - V_19 ;
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
return V_60 ;
}
static long F_26 ( const char T_2 * V_107 , unsigned long V_108 ,
unsigned long * V_109 )
{
int V_60 ;
* V_109 = 0 ;
for ( V_60 = 0 ; V_60 < V_108 ; V_60 ++ ) {
char V_111 ;
if ( F_23 ( V_111 , & V_107 [ V_60 ] ) )
return - V_19 ;
if ( ( V_111 >= '0' ) && ( V_111 <= '9' ) ) {
* V_109 *= 10 ;
* V_109 += V_111 - '0' ;
} else
break;
}
return V_60 ;
}
static int F_27 ( const char T_2 * V_107 , unsigned int V_108 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_108 ; V_60 ++ ) {
char V_111 ;
if ( F_23 ( V_111 , & V_107 [ V_60 ] ) )
return - V_19 ;
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
return V_60 ;
}
static T_1 F_28 ( const char T_2 * V_114 , struct V_21 * V_22 )
{
unsigned int V_115 = 0 ;
char V_111 ;
T_1 V_60 = 0 ;
int V_116 ;
V_22 -> V_59 = 0 ;
do {
T_7 V_117 ;
V_116 = F_22 ( & V_114 [ V_60 ] , 8 , & V_117 ) ;
if ( V_116 <= 0 )
return V_116 ;
V_22 -> V_61 [ V_115 ] = F_29 ( V_117 ) ;
if ( V_22 -> V_61 [ V_115 ] & V_118 )
V_22 -> V_37 |= V_77 ;
V_60 += V_116 ;
if ( F_23 ( V_111 , & V_114 [ V_60 ] ) )
return - V_19 ;
V_60 ++ ;
V_115 ++ ;
if ( V_115 >= V_119 )
return - V_120 ;
} while ( V_111 == ',' );
V_22 -> V_59 = V_115 ;
return V_60 ;
}
static T_1 F_30 ( struct V_5 * V_5 ,
const char T_2 * V_107 , T_3 V_7 ,
T_4 * V_121 )
{
struct V_1 * V_2 = V_5 -> V_122 ;
struct V_21 * V_22 = V_2 -> V_23 ;
int V_60 , V_123 , V_116 ;
char V_124 [ 16 ] , V_125 [ 32 ] ;
unsigned long V_110 = 0 ;
char * V_126 = NULL ;
int V_117 = 0 ;
char V_6 [ 128 ] ;
V_126 = & ( V_22 -> V_106 [ 0 ] ) ;
if ( V_7 < 1 ) {
F_10 ( L_60 ) ;
return - V_18 ;
}
V_123 = V_7 ;
V_117 = F_25 ( V_107 , V_123 ) ;
if ( V_117 < 0 ) {
F_10 ( L_61 ) ;
return V_117 ;
}
V_60 = V_117 ;
V_116 = F_27 ( & V_107 [ V_60 ] , sizeof( V_124 ) - 1 ) ;
if ( V_116 < 0 )
return V_116 ;
memset ( V_124 , 0 , sizeof( V_124 ) ) ;
if ( F_6 ( V_124 , & V_107 [ V_60 ] , V_116 ) )
return - V_19 ;
V_60 += V_116 ;
V_123 = V_7 - V_60 ;
V_116 = F_25 ( & V_107 [ V_60 ] , V_123 ) ;
if ( V_116 < 0 )
return V_116 ;
V_60 += V_116 ;
if ( V_127 ) {
T_3 V_128 = F_31 ( T_3 , V_7 , 1023 ) ;
char V_129 [ V_128 + 1 ] ;
if ( F_6 ( V_129 , V_107 , V_128 ) )
return - V_19 ;
V_129 [ V_128 ] = 0 ;
F_32 ( L_62 ,
V_124 , ( unsigned long ) V_7 , V_129 ) ;
}
if ( ! strcmp ( V_124 , L_63 ) ) {
V_116 = F_26 ( & V_107 [ V_60 ] , 10 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_60 += V_116 ;
if ( V_110 < 14 + 20 + 8 )
V_110 = 14 + 20 + 8 ;
if ( V_110 != V_22 -> V_26 ) {
V_22 -> V_26 = V_110 ;
V_22 -> V_130 = V_110 ;
}
sprintf ( V_126 , L_64 ,
V_22 -> V_26 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_65 ) ) {
V_116 = F_26 ( & V_107 [ V_60 ] , 10 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_60 += V_116 ;
if ( V_110 < 14 + 20 + 8 )
V_110 = 14 + 20 + 8 ;
if ( V_110 != V_22 -> V_27 ) {
V_22 -> V_27 = V_110 ;
V_22 -> V_130 = V_110 ;
}
sprintf ( V_126 , L_66 ,
V_22 -> V_27 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_67 ) ) {
V_116 = F_26 ( & V_107 [ V_60 ] , 10 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_60 += V_116 ;
if ( V_110 < 14 + 20 + 8 )
V_110 = 14 + 20 + 8 ;
if ( V_110 != V_22 -> V_26 ) {
V_22 -> V_26 = V_110 ;
V_22 -> V_27 = V_110 ;
V_22 -> V_130 = V_110 ;
}
sprintf ( V_126 , L_68 , V_22 -> V_26 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_69 ) ) {
V_116 = F_26 ( & V_107 [ V_60 ] , 10 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_60 += V_116 ;
V_127 = V_110 ;
sprintf ( V_126 , L_70 , V_127 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_71 ) ) {
V_116 = F_26 ( & V_107 [ V_60 ] , 10 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_60 += V_116 ;
V_22 -> V_28 = V_110 ;
sprintf ( V_126 , L_72 , V_22 -> V_28 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_73 ) ) {
V_116 = F_26 ( & V_107 [ V_60 ] , 10 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_60 += V_116 ;
if ( V_110 == 0x7FFFFFFF )
V_22 -> V_29 = V_131 ;
else
V_22 -> V_29 = ( T_6 ) V_110 ;
sprintf ( V_126 , L_74 ,
( unsigned long long ) V_22 -> V_29 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_75 ) ) {
V_116 = F_26 ( & V_107 [ V_60 ] , 10 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_60 += V_116 ;
if ( ! V_110 )
return V_116 ;
V_22 -> V_29 = V_22 -> V_26 * 8 * V_91 / V_110 ;
if ( V_127 )
F_33 ( L_76 , V_22 -> V_29 ) ;
sprintf ( V_126 , L_77 , V_110 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_78 ) ) {
V_116 = F_26 ( & V_107 [ V_60 ] , 10 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_60 += V_116 ;
if ( ! V_110 )
return V_116 ;
V_22 -> V_29 = V_132 / V_110 ;
if ( V_127 )
F_33 ( L_76 , V_22 -> V_29 ) ;
sprintf ( V_126 , L_77 , V_110 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_79 ) ) {
V_116 = F_26 ( & V_107 [ V_60 ] , 10 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_60 += V_116 ;
if ( V_110 != V_22 -> V_53 ) {
V_22 -> V_53 = V_110 ;
V_22 -> V_103 = V_110 ;
}
sprintf ( V_126 , L_80 , V_22 -> V_53 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_81 ) ) {
V_116 = F_26 ( & V_107 [ V_60 ] , 10 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_60 += V_116 ;
if ( V_110 != V_22 -> V_55 ) {
V_22 -> V_55 = V_110 ;
V_22 -> V_102 = V_110 ;
}
sprintf ( V_126 , L_82 , V_22 -> V_55 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_83 ) ) {
V_116 = F_26 ( & V_107 [ V_60 ] , 10 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_60 += V_116 ;
if ( V_110 != V_22 -> V_54 ) {
V_22 -> V_54 = V_110 ;
V_22 -> V_103 = V_110 ;
}
sprintf ( V_126 , L_84 , V_22 -> V_54 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_85 ) ) {
V_116 = F_26 ( & V_107 [ V_60 ] , 10 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_60 += V_116 ;
if ( V_110 != V_22 -> V_56 ) {
V_22 -> V_56 = V_110 ;
V_22 -> V_102 = V_110 ;
}
sprintf ( V_126 , L_86 , V_22 -> V_56 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_87 ) ) {
V_116 = F_26 ( & V_107 [ V_60 ] , 10 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
if ( ( V_110 > 0 ) &&
( ! ( V_22 -> V_50 -> V_133 & V_134 ) ) )
return - V_135 ;
V_60 += V_116 ;
V_22 -> V_30 = V_110 ;
sprintf ( V_126 , L_88 , V_22 -> V_30 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_89 ) ) {
V_116 = F_26 ( & V_107 [ V_60 ] , 10 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_60 += V_116 ;
V_22 -> V_7 = V_110 ;
sprintf ( V_126 , L_90 ,
( unsigned long long ) V_22 -> V_7 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_91 ) ) {
V_116 = F_26 ( & V_107 [ V_60 ] , 10 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_60 += V_116 ;
if ( V_22 -> V_57 != V_110 ) {
V_22 -> V_57 = V_110 ;
V_22 -> V_97 = 0 ;
}
sprintf ( V_126 , L_92 ,
V_22 -> V_57 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_93 ) ) {
V_116 = F_26 ( & V_107 [ V_60 ] , 10 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_60 += V_116 ;
if ( V_22 -> V_58 != V_110 ) {
V_22 -> V_58 = V_110 ;
V_22 -> V_96 = 0 ;
}
sprintf ( V_126 , L_94 ,
V_22 -> V_58 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_95 ) ) {
V_116 = F_26 ( & V_107 [ V_60 ] , 10 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_60 += V_116 ;
if ( F_34 ( V_110 ) ) {
V_22 -> V_70 = V_110 ;
sprintf ( V_126 , L_96 , V_22 -> V_70 ) ;
if ( V_22 -> V_136 ) {
F_35 ( V_22 -> V_136 ) ;
V_22 -> V_136 = NULL ;
}
}
else
sprintf ( V_126 , L_97 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_98 ) ) {
char V_137 [ 32 ] ;
memset ( V_137 , 0 , 32 ) ;
V_116 = F_27 ( & V_107 [ V_60 ] , sizeof( V_137 ) - 1 ) ;
if ( V_116 < 0 )
return V_116 ;
if ( F_6 ( V_137 , & V_107 [ V_60 ] , V_116 ) )
return - V_19 ;
V_60 += V_116 ;
if ( strcmp ( V_137 , L_99 ) == 0 )
V_22 -> V_37 |= V_71 ;
else if ( strcmp ( V_137 , L_100 ) == 0 )
V_22 -> V_37 &= ~ V_71 ;
else if ( strcmp ( V_137 , L_101 ) == 0 )
V_22 -> V_37 |= V_73 ;
else if ( strcmp ( V_137 , L_102 ) == 0 )
V_22 -> V_37 &= ~ V_73 ;
else if ( strcmp ( V_137 , L_103 ) == 0 )
V_22 -> V_37 |= V_72 ;
else if ( strcmp ( V_137 , L_104 ) == 0 )
V_22 -> V_37 &= ~ V_72 ;
else if ( strcmp ( V_137 , L_105 ) == 0 )
V_22 -> V_37 |= V_74 ;
else if ( strcmp ( V_137 , L_106 ) == 0 )
V_22 -> V_37 &= ~ V_74 ;
else if ( strcmp ( V_137 , L_107 ) == 0 )
V_22 -> V_37 |= V_75 ;
else if ( strcmp ( V_137 , L_108 ) == 0 )
V_22 -> V_37 &= ~ V_75 ;
else if ( strcmp ( V_137 , L_109 ) == 0 )
V_22 -> V_37 |= V_83 ;
else if ( strcmp ( V_137 , L_110 ) == 0 )
V_22 -> V_37 &= ~ V_83 ;
else if ( strcmp ( V_137 , L_111 ) == 0 )
V_22 -> V_37 |= V_84 ;
else if ( strcmp ( V_137 , L_112 ) == 0 )
V_22 -> V_37 &= ~ V_84 ;
else if ( strcmp ( V_137 , L_113 ) == 0 )
V_22 -> V_37 |= V_77 ;
else if ( strcmp ( V_137 , L_114 ) == 0 )
V_22 -> V_37 &= ~ V_77 ;
else if ( strcmp ( V_137 , L_115 ) == 0 )
V_22 -> V_37 |= V_85 ;
else if ( strcmp ( V_137 , L_116 ) == 0 )
V_22 -> V_37 &= ~ V_85 ;
else if ( strcmp ( V_137 , L_117 ) == 0 )
V_22 -> V_37 |= V_86 ;
else if ( strcmp ( V_137 , L_118 ) == 0 )
V_22 -> V_37 &= ~ V_86 ;
else if ( strcmp ( V_137 , L_119 ) == 0 )
V_22 -> V_37 |= V_80 ;
else if ( strcmp ( V_137 , L_120 ) == 0 )
V_22 -> V_37 |= V_78 ;
else if ( strcmp ( V_137 , L_121 ) == 0 )
V_22 -> V_37 &= ~ V_78 ;
else if ( strcmp ( V_137 , L_122 ) == 0 )
V_22 -> V_37 |= V_79 ;
else if ( strcmp ( V_137 , L_123 ) == 0 )
V_22 -> V_37 &= ~ V_79 ;
#ifdef F_18
else if ( strcmp ( V_137 , L_124 ) == 0 )
V_22 -> V_37 |= V_81 ;
#endif
else if ( strcmp ( V_137 , L_125 ) == 0 )
V_22 -> V_37 &= ~ V_38 ;
else if ( strcmp ( V_137 , L_126 ) == 0 )
V_22 -> V_37 |= V_87 ;
else if ( strcmp ( V_137 , L_127 ) == 0 )
V_22 -> V_37 &= ~ V_87 ;
else if ( strcmp ( V_137 , L_128 ) == 0 )
V_22 -> V_37 |= V_76 ;
else if ( strcmp ( V_137 , L_129 ) == 0 )
V_22 -> V_37 &= ~ V_76 ;
else {
sprintf ( V_126 ,
L_130 ,
V_137 ,
L_131
L_132
L_133
L_134
#ifdef F_18
L_135
#endif
L_136 ) ;
return V_7 ;
}
sprintf ( V_126 , L_137 , V_22 -> V_37 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_138 ) || ! strcmp ( V_124 , L_139 ) ) {
V_116 = F_27 ( & V_107 [ V_60 ] , sizeof( V_22 -> V_45 ) - 1 ) ;
if ( V_116 < 0 )
return V_116 ;
if ( F_6 ( V_6 , & V_107 [ V_60 ] , V_116 ) )
return - V_19 ;
V_6 [ V_116 ] = 0 ;
if ( strcmp ( V_6 , V_22 -> V_45 ) != 0 ) {
memset ( V_22 -> V_45 , 0 , sizeof( V_22 -> V_45 ) ) ;
strncpy ( V_22 -> V_45 , V_6 , V_116 ) ;
V_22 -> V_138 = F_36 ( V_22 -> V_45 ) ;
V_22 -> V_101 = V_22 -> V_138 ;
}
if ( V_127 )
F_32 ( L_140 , V_22 -> V_45 ) ;
V_60 += V_116 ;
sprintf ( V_126 , L_141 , V_22 -> V_45 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_142 ) ) {
V_116 = F_27 ( & V_107 [ V_60 ] , sizeof( V_22 -> V_46 ) - 1 ) ;
if ( V_116 < 0 )
return V_116 ;
if ( F_6 ( V_6 , & V_107 [ V_60 ] , V_116 ) )
return - V_19 ;
V_6 [ V_116 ] = 0 ;
if ( strcmp ( V_6 , V_22 -> V_46 ) != 0 ) {
memset ( V_22 -> V_46 , 0 , sizeof( V_22 -> V_46 ) ) ;
strncpy ( V_22 -> V_46 , V_6 , V_116 ) ;
V_22 -> V_139 = F_36 ( V_22 -> V_46 ) ;
V_22 -> V_101 = V_22 -> V_139 ;
}
if ( V_127 )
F_32 ( L_143 , V_22 -> V_46 ) ;
V_60 += V_116 ;
sprintf ( V_126 , L_144 , V_22 -> V_46 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_145 ) ) {
V_116 = F_27 ( & V_107 [ V_60 ] , sizeof( V_6 ) - 1 ) ;
if ( V_116 < 0 )
return V_116 ;
V_22 -> V_37 |= V_38 ;
if ( F_6 ( V_6 , & V_107 [ V_60 ] , V_116 ) )
return - V_19 ;
V_6 [ V_116 ] = 0 ;
F_37 ( V_6 , - 1 , V_22 -> V_42 . V_140 , - 1 , NULL ) ;
snprintf ( V_6 , sizeof( V_6 ) , L_146 , & V_22 -> V_42 ) ;
V_22 -> V_99 = V_22 -> V_42 ;
if ( V_127 )
F_32 ( L_147 , V_6 ) ;
V_60 += V_116 ;
sprintf ( V_126 , L_148 , V_6 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_149 ) ) {
V_116 = F_27 ( & V_107 [ V_60 ] , sizeof( V_6 ) - 1 ) ;
if ( V_116 < 0 )
return V_116 ;
V_22 -> V_37 |= V_38 ;
if ( F_6 ( V_6 , & V_107 [ V_60 ] , V_116 ) )
return - V_19 ;
V_6 [ V_116 ] = 0 ;
F_37 ( V_6 , - 1 , V_22 -> V_43 . V_140 , - 1 , NULL ) ;
snprintf ( V_6 , sizeof( V_6 ) , L_146 , & V_22 -> V_43 ) ;
V_22 -> V_99 = V_22 -> V_43 ;
if ( V_127 )
F_32 ( L_150 , V_6 ) ;
V_60 += V_116 ;
sprintf ( V_126 , L_151 , V_6 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_152 ) ) {
V_116 = F_27 ( & V_107 [ V_60 ] , sizeof( V_6 ) - 1 ) ;
if ( V_116 < 0 )
return V_116 ;
V_22 -> V_37 |= V_38 ;
if ( F_6 ( V_6 , & V_107 [ V_60 ] , V_116 ) )
return - V_19 ;
V_6 [ V_116 ] = 0 ;
F_37 ( V_6 , - 1 , V_22 -> V_44 . V_140 , - 1 , NULL ) ;
snprintf ( V_6 , sizeof( V_6 ) , L_146 , & V_22 -> V_44 ) ;
if ( V_127 )
F_32 ( L_153 , V_6 ) ;
V_60 += V_116 ;
sprintf ( V_126 , L_154 , V_6 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_155 ) ) {
V_116 = F_27 ( & V_107 [ V_60 ] , sizeof( V_6 ) - 1 ) ;
if ( V_116 < 0 )
return V_116 ;
V_22 -> V_37 |= V_38 ;
if ( F_6 ( V_6 , & V_107 [ V_60 ] , V_116 ) )
return - V_19 ;
V_6 [ V_116 ] = 0 ;
F_37 ( V_6 , - 1 , V_22 -> V_39 . V_140 , - 1 , NULL ) ;
snprintf ( V_6 , sizeof( V_6 ) , L_146 , & V_22 -> V_39 ) ;
V_22 -> V_98 = V_22 -> V_39 ;
if ( V_127 )
F_32 ( L_156 , V_6 ) ;
V_60 += V_116 ;
sprintf ( V_126 , L_157 , V_6 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_158 ) ) {
V_116 = F_27 ( & V_107 [ V_60 ] , sizeof( V_22 -> V_47 ) - 1 ) ;
if ( V_116 < 0 )
return V_116 ;
if ( F_6 ( V_6 , & V_107 [ V_60 ] , V_116 ) )
return - V_19 ;
V_6 [ V_116 ] = 0 ;
if ( strcmp ( V_6 , V_22 -> V_47 ) != 0 ) {
memset ( V_22 -> V_47 , 0 , sizeof( V_22 -> V_47 ) ) ;
strncpy ( V_22 -> V_47 , V_6 , V_116 ) ;
V_22 -> V_141 = F_36 ( V_22 -> V_47 ) ;
V_22 -> V_100 = V_22 -> V_141 ;
}
if ( V_127 )
F_32 ( L_159 , V_22 -> V_47 ) ;
V_60 += V_116 ;
sprintf ( V_126 , L_160 , V_22 -> V_47 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_161 ) ) {
V_116 = F_27 ( & V_107 [ V_60 ] , sizeof( V_22 -> V_48 ) - 1 ) ;
if ( V_116 < 0 )
return V_116 ;
if ( F_6 ( V_6 , & V_107 [ V_60 ] , V_116 ) )
return - V_19 ;
V_6 [ V_116 ] = 0 ;
if ( strcmp ( V_6 , V_22 -> V_48 ) != 0 ) {
memset ( V_22 -> V_48 , 0 , sizeof( V_22 -> V_48 ) ) ;
strncpy ( V_22 -> V_48 , V_6 , V_116 ) ;
V_22 -> V_142 = F_36 ( V_22 -> V_48 ) ;
V_22 -> V_100 = V_22 -> V_142 ;
}
if ( V_127 )
F_32 ( L_162 , V_22 -> V_48 ) ;
V_60 += V_116 ;
sprintf ( V_126 , L_163 , V_22 -> V_48 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_164 ) ) {
V_116 = F_27 ( & V_107 [ V_60 ] , sizeof( V_125 ) - 1 ) ;
if ( V_116 < 0 )
return V_116 ;
memset ( V_125 , 0 , sizeof( V_125 ) ) ;
if ( F_6 ( V_125 , & V_107 [ V_60 ] , V_116 ) )
return - V_19 ;
if ( ! F_38 ( V_125 , V_22 -> V_52 ) )
return - V_18 ;
F_39 ( & V_22 -> V_143 [ 0 ] , V_22 -> V_52 ) ;
sprintf ( V_126 , L_165 , V_22 -> V_52 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_166 ) ) {
V_116 = F_27 ( & V_107 [ V_60 ] , sizeof( V_125 ) - 1 ) ;
if ( V_116 < 0 )
return V_116 ;
memset ( V_125 , 0 , sizeof( V_125 ) ) ;
if ( F_6 ( V_125 , & V_107 [ V_60 ] , V_116 ) )
return - V_19 ;
if ( ! F_38 ( V_125 , V_22 -> V_49 ) )
return - V_18 ;
F_39 ( & V_22 -> V_143 [ 6 ] , V_22 -> V_49 ) ;
sprintf ( V_126 , L_167 , V_22 -> V_49 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_168 ) ) {
F_40 ( V_22 ) ;
sprintf ( V_126 , L_169 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_170 ) ) {
V_116 = F_26 ( & V_107 [ V_60 ] , 10 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_60 += V_116 ;
if ( V_110 > V_144 )
V_110 = V_144 ;
V_22 -> V_32 = V_110 ;
sprintf ( V_126 , L_171 , V_22 -> V_32 ) ;
return V_7 ;
}
#ifdef F_18
if ( ! strcmp ( V_124 , L_172 ) ) {
V_116 = F_26 ( & V_107 [ V_60 ] , 10 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_60 += V_116 ;
V_22 -> V_82 = V_110 ;
sprintf ( V_126 , L_173 , V_22 -> V_82 ) ;
return V_7 ;
}
#endif
if ( ! strcmp ( V_124 , L_174 ) ) {
V_116 = F_26 ( & V_107 [ V_60 ] , 10 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_60 += V_116 ;
V_22 -> V_33 = V_110 ;
sprintf ( V_126 , L_175 , V_22 -> V_33 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_176 ) ) {
V_116 = F_26 ( & V_107 [ V_60 ] , 5 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_60 += V_116 ;
V_22 -> V_34 = V_110 ;
sprintf ( V_126 , L_177 , V_22 -> V_34 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_178 ) ) {
V_116 = F_26 ( & V_107 [ V_60 ] , 5 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_60 += V_116 ;
V_22 -> V_35 = V_110 ;
sprintf ( V_126 , L_179 , V_22 -> V_35 ) ;
return V_7 ;
}
if ( ! strcmp ( V_124 , L_180 ) ) {
unsigned int V_115 , V_145 ;
V_116 = F_28 ( & V_107 [ V_60 ] , V_22 ) ;
if ( V_116 < 0 )
return V_116 ;
V_60 += V_116 ;
V_145 = sprintf ( V_126 , L_181 ) ;
for ( V_115 = 0 ; V_115 < V_22 -> V_59 ; V_115 ++ )
V_145 += sprintf ( V_126 + V_145 ,
L_22 , F_17 ( V_22 -> V_61 [ V_115 ] ) ,
V_115 == V_22 -> V_59 - 1 ? L_182 : L_183 ) ;
if ( V_22 -> V_59 && V_22 -> V_62 != 0xffff ) {
V_22 -> V_62 = 0xffff ;
V_22 -> V_65 = 0xffff ;
if ( V_127 )
F_32 ( L_184 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_124 , L_185 ) ) {
V_116 = F_26 ( & V_107 [ V_60 ] , 4 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_60 += V_116 ;
if ( V_110 <= 4095 ) {
V_22 -> V_62 = V_110 ;
if ( V_127 )
F_32 ( L_186 ) ;
if ( V_127 && V_22 -> V_59 )
F_32 ( L_187 ) ;
V_22 -> V_59 = 0 ;
sprintf ( V_126 , L_188 , V_22 -> V_62 ) ;
} else {
V_22 -> V_62 = 0xffff ;
V_22 -> V_65 = 0xffff ;
if ( V_127 )
F_32 ( L_189 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_124 , L_190 ) ) {
V_116 = F_26 ( & V_107 [ V_60 ] , 1 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_60 += V_116 ;
if ( ( V_110 <= 7 ) && ( V_22 -> V_62 != 0xffff ) ) {
V_22 -> V_63 = V_110 ;
sprintf ( V_126 , L_191 , V_22 -> V_63 ) ;
} else {
sprintf ( V_126 , L_192 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_124 , L_193 ) ) {
V_116 = F_26 ( & V_107 [ V_60 ] , 1 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_60 += V_116 ;
if ( ( V_110 <= 1 ) && ( V_22 -> V_62 != 0xffff ) ) {
V_22 -> V_64 = V_110 ;
sprintf ( V_126 , L_194 , V_22 -> V_64 ) ;
} else {
sprintf ( V_126 , L_195 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_124 , L_196 ) ) {
V_116 = F_26 ( & V_107 [ V_60 ] , 4 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_60 += V_116 ;
if ( ( V_110 <= 4095 ) && ( ( V_22 -> V_62 != 0xffff ) ) ) {
V_22 -> V_65 = V_110 ;
if ( V_127 )
F_32 ( L_197 ) ;
if ( V_127 && V_22 -> V_59 )
F_32 ( L_187 ) ;
V_22 -> V_59 = 0 ;
sprintf ( V_126 , L_198 , V_22 -> V_65 ) ;
} else {
V_22 -> V_62 = 0xffff ;
V_22 -> V_65 = 0xffff ;
if ( V_127 )
F_32 ( L_189 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_124 , L_199 ) ) {
V_116 = F_26 ( & V_107 [ V_60 ] , 1 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_60 += V_116 ;
if ( ( V_110 <= 7 ) && ( V_22 -> V_65 != 0xffff ) ) {
V_22 -> V_66 = V_110 ;
sprintf ( V_126 , L_200 , V_22 -> V_66 ) ;
} else {
sprintf ( V_126 , L_201 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_124 , L_202 ) ) {
V_116 = F_26 ( & V_107 [ V_60 ] , 1 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_60 += V_116 ;
if ( ( V_110 <= 1 ) && ( V_22 -> V_65 != 0xffff ) ) {
V_22 -> V_67 = V_110 ;
sprintf ( V_126 , L_203 , V_22 -> V_67 ) ;
} else {
sprintf ( V_126 , L_204 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_124 , L_205 ) ) {
T_7 V_146 = 0 ;
V_116 = F_22 ( & V_107 [ V_60 ] , 2 , & V_146 ) ;
if ( V_116 < 0 )
return V_116 ;
V_60 += V_116 ;
if ( V_116 == 2 ) {
V_22 -> V_68 = V_146 ;
sprintf ( V_126 , L_206 , V_22 -> V_68 ) ;
} else {
sprintf ( V_126 , L_207 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_124 , L_208 ) ) {
T_7 V_146 = 0 ;
V_116 = F_22 ( & V_107 [ V_60 ] , 2 , & V_146 ) ;
if ( V_116 < 0 )
return V_116 ;
V_60 += V_116 ;
if ( V_116 == 2 ) {
V_22 -> V_69 = V_146 ;
sprintf ( V_126 , L_209 , V_22 -> V_69 ) ;
} else {
sprintf ( V_126 , L_210 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_124 , L_211 ) ) {
V_116 = F_26 ( & V_107 [ V_60 ] , 9 , & V_110 ) ;
if ( V_116 < 0 )
return V_116 ;
V_60 += V_116 ;
V_22 -> V_36 = V_110 ;
sprintf ( V_126 , L_212 ,
V_22 -> V_36 ) ;
return V_7 ;
}
sprintf ( V_22 -> V_106 , L_213 , V_124 ) ;
return - V_18 ;
}
static int F_41 ( struct V_20 * V_20 , struct V_5 * V_5 )
{
return F_12 ( V_5 , F_14 , F_13 ( V_20 ) ) ;
}
static int F_42 ( struct V_1 * V_2 , void * V_3 )
{
struct V_147 * V_148 = V_2 -> V_23 ;
const struct V_21 * V_22 ;
F_43 ( ! V_148 ) ;
F_2 ( V_2 , L_214 ) ;
F_44 ( V_148 ) ;
F_45 (pkt_dev, &t->if_list, list)
if ( V_22 -> V_88 )
F_15 ( V_2 , L_215 , V_22 -> V_31 ) ;
F_2 ( V_2 , L_216 ) ;
F_45 (pkt_dev, &t->if_list, list)
if ( ! V_22 -> V_88 )
F_15 ( V_2 , L_215 , V_22 -> V_31 ) ;
if ( V_148 -> V_106 [ 0 ] )
F_15 ( V_2 , L_217 , V_148 -> V_106 ) ;
else
F_2 ( V_2 , L_218 ) ;
F_46 ( V_148 ) ;
return 0 ;
}
static T_1 F_47 ( struct V_5 * V_5 ,
const char T_2 * V_107 ,
T_3 V_7 , T_4 * V_121 )
{
struct V_1 * V_2 = V_5 -> V_122 ;
struct V_147 * V_148 = V_2 -> V_23 ;
int V_60 , V_123 , V_116 , V_149 ;
char V_124 [ 40 ] ;
char * V_126 ;
if ( V_7 < 1 ) {
return - V_18 ;
}
V_123 = V_7 ;
V_116 = F_25 ( V_107 , V_123 ) ;
if ( V_116 < 0 )
return V_116 ;
V_60 = V_116 ;
V_116 = F_27 ( & V_107 [ V_60 ] , sizeof( V_124 ) - 1 ) ;
if ( V_116 < 0 )
return V_116 ;
memset ( V_124 , 0 , sizeof( V_124 ) ) ;
if ( F_6 ( V_124 , & V_107 [ V_60 ] , V_116 ) )
return - V_19 ;
V_60 += V_116 ;
V_123 = V_7 - V_60 ;
V_116 = F_25 ( & V_107 [ V_60 ] , V_123 ) ;
if ( V_116 < 0 )
return V_116 ;
V_60 += V_116 ;
if ( V_127 )
F_32 ( L_219 , V_124 , ( unsigned long ) V_7 ) ;
if ( ! V_148 ) {
F_48 ( L_220 ) ;
V_149 = - V_18 ;
goto V_150;
}
V_126 = & ( V_148 -> V_106 [ 0 ] ) ;
if ( ! strcmp ( V_124 , L_221 ) ) {
char V_137 [ 32 ] ;
memset ( V_137 , 0 , 32 ) ;
V_116 = F_27 ( & V_107 [ V_60 ] , sizeof( V_137 ) - 1 ) ;
if ( V_116 < 0 ) {
V_149 = V_116 ;
goto V_150;
}
if ( F_6 ( V_137 , & V_107 [ V_60 ] , V_116 ) )
return - V_19 ;
V_60 += V_116 ;
F_49 ( & V_151 ) ;
V_149 = F_50 ( V_148 , V_137 ) ;
F_51 ( & V_151 ) ;
if ( ! V_149 ) {
V_149 = V_7 ;
sprintf ( V_126 , L_222 , V_137 ) ;
} else
sprintf ( V_126 , L_223 , V_137 ) ;
goto V_150;
}
if ( ! strcmp ( V_124 , L_224 ) ) {
F_49 ( & V_151 ) ;
V_148 -> V_152 |= V_153 ;
F_51 ( & V_151 ) ;
F_52 ( F_53 ( 125 ) ) ;
V_149 = V_7 ;
sprintf ( V_126 , L_225 ) ;
goto V_150;
}
if ( ! strcmp ( V_124 , L_226 ) ) {
sprintf ( V_126 , L_227 ) ;
V_149 = V_7 ;
goto V_150;
}
V_149 = - V_18 ;
V_150:
return V_149 ;
}
static int F_54 ( struct V_20 * V_20 , struct V_5 * V_5 )
{
return F_12 ( V_5 , F_42 , F_13 ( V_20 ) ) ;
}
static struct V_21 * F_55 ( const struct V_10 * V_11 ,
const char * V_154 , int remove )
{
struct V_147 * V_148 ;
struct V_21 * V_22 = NULL ;
bool V_155 = ( remove == V_156 ) ;
F_45 (t, &pn->pktgen_threads, th_list) {
V_22 = F_56 ( V_148 , V_154 , V_155 ) ;
if ( V_22 ) {
if ( remove ) {
F_44 ( V_148 ) ;
V_22 -> V_157 = 1 ;
V_148 -> V_152 |= V_158 ;
F_46 ( V_148 ) ;
}
break;
}
}
return V_22 ;
}
static void F_57 ( const struct V_10 * V_11 , const char * V_154 )
{
struct V_21 * V_22 = NULL ;
const int V_159 = 10 , V_160 = 125 ;
int V_60 = 0 ;
F_49 ( & V_151 ) ;
F_32 ( L_228 , V_161 , V_154 ) ;
while ( 1 ) {
V_22 = F_55 ( V_11 , V_154 , REMOVE ) ;
if ( V_22 == NULL )
break;
F_51 ( & V_151 ) ;
F_32 ( L_229 ,
V_161 , V_154 ) ;
F_52 ( F_53 ( V_160 ) ) ;
F_49 ( & V_151 ) ;
if ( ++ V_60 >= V_159 ) {
F_48 ( L_230 ,
V_161 , V_160 * V_60 , V_154 ) ;
break;
}
}
F_51 ( & V_151 ) ;
}
static void F_58 ( const struct V_10 * V_11 , struct V_162 * V_163 )
{
struct V_147 * V_148 ;
F_45 (t, &pn->pktgen_threads, th_list) {
struct V_21 * V_22 ;
F_45 (pkt_dev, &t->if_list, list) {
if ( V_22 -> V_50 != V_163 )
continue;
F_59 ( V_22 -> V_164 ) ;
V_22 -> V_164 = F_60 ( V_163 -> V_124 , 0600 ,
V_11 -> V_165 ,
& V_166 ,
V_22 ) ;
if ( ! V_22 -> V_164 )
F_48 ( L_231 ,
V_163 -> V_124 ) ;
break;
}
}
}
static int F_61 ( struct V_167 * V_168 ,
unsigned long V_169 , void * V_170 )
{
struct V_162 * V_163 = F_62 ( V_170 ) ;
struct V_10 * V_11 = F_4 ( F_63 ( V_163 ) , V_15 ) ;
if ( V_11 -> V_171 )
return V_172 ;
switch ( V_169 ) {
case V_173 :
F_58 ( V_11 , V_163 ) ;
break;
case V_174 :
F_57 ( V_11 , V_163 -> V_124 ) ;
break;
}
return V_172 ;
}
static struct V_162 * F_64 ( const struct V_10 * V_11 ,
struct V_21 * V_22 ,
const char * V_154 )
{
char V_175 [ V_176 + 5 ] ;
int V_60 ;
for ( V_60 = 0 ; V_154 [ V_60 ] != '@' ; V_60 ++ ) {
if ( V_60 == V_176 )
break;
V_175 [ V_60 ] = V_154 [ V_60 ] ;
}
V_175 [ V_60 ] = 0 ;
return F_65 ( V_11 -> V_177 , V_175 ) ;
}
static int F_66 ( const struct V_10 * V_11 ,
struct V_21 * V_22 , const char * V_154 )
{
struct V_162 * V_50 ;
int V_178 ;
if ( V_22 -> V_50 ) {
F_67 ( V_22 -> V_50 ) ;
V_22 -> V_50 = NULL ;
}
V_50 = F_64 ( V_11 , V_22 , V_154 ) ;
if ( ! V_50 ) {
F_48 ( L_232 , V_154 ) ;
return - V_179 ;
}
if ( V_50 -> type != V_180 ) {
F_48 ( L_233 , V_154 ) ;
V_178 = - V_18 ;
} else if ( ! F_68 ( V_50 ) ) {
F_48 ( L_234 , V_154 ) ;
V_178 = - V_181 ;
} else {
V_22 -> V_50 = V_50 ;
return 0 ;
}
F_67 ( V_50 ) ;
return V_178 ;
}
static void F_69 ( struct V_21 * V_22 )
{
int V_182 ;
if ( ! V_22 -> V_50 ) {
F_48 ( L_235 ) ;
sprintf ( V_22 -> V_106 ,
L_236 ) ;
return;
}
V_182 = V_22 -> V_50 -> V_183 ;
if ( V_182 <= V_22 -> V_34 ) {
F_10 ( L_237 ,
V_22 -> V_34 , ( V_182 ? : 1 ) - 1 , V_182 ,
V_22 -> V_31 ) ;
V_22 -> V_34 = ( V_182 ? : 1 ) - 1 ;
}
if ( V_22 -> V_35 >= V_182 ) {
F_10 ( L_238 ,
V_22 -> V_35 , ( V_182 ? : 1 ) - 1 , V_182 ,
V_22 -> V_31 ) ;
V_22 -> V_35 = ( V_182 ? : 1 ) - 1 ;
}
if ( F_16 ( V_22 -> V_49 ) )
F_39 ( & ( V_22 -> V_143 [ 6 ] ) , V_22 -> V_50 -> V_51 ) ;
F_39 ( & ( V_22 -> V_143 [ 0 ] ) , V_22 -> V_52 ) ;
if ( V_22 -> V_37 & V_38 ) {
int V_60 , V_184 = 0 , V_178 = 1 ;
struct V_185 * V_186 ;
if ( V_22 -> V_26 == 0 ) {
V_22 -> V_26 = 14 + sizeof( struct V_187 )
+ sizeof( struct V_188 )
+ sizeof( struct V_189 )
+ V_22 -> V_190 ;
}
for ( V_60 = 0 ; V_60 < V_191 ; V_60 ++ )
if ( V_22 -> V_98 . V_140 [ V_60 ] ) {
V_184 = 1 ;
break;
}
if ( ! V_184 ) {
F_70 () ;
V_186 = F_71 ( V_22 -> V_50 ) ;
if ( V_186 ) {
struct V_192 * V_193 ;
F_72 ( & V_186 -> V_194 ) ;
F_45 (ifp, &idev->addr_list, if_list) {
if ( ( V_193 -> V_195 & V_196 ) &&
! ( V_193 -> V_37 & V_197 ) ) {
V_22 -> V_98 = V_193 -> V_198 ;
V_178 = 0 ;
break;
}
}
F_73 ( & V_186 -> V_194 ) ;
}
F_74 () ;
if ( V_178 )
F_48 ( L_239 ) ;
}
} else {
if ( V_22 -> V_26 == 0 ) {
V_22 -> V_26 = 14 + sizeof( struct V_199 )
+ sizeof( struct V_188 )
+ sizeof( struct V_189 )
+ V_22 -> V_190 ;
}
V_22 -> V_141 = 0 ;
V_22 -> V_142 = 0 ;
if ( strlen ( V_22 -> V_47 ) == 0 ) {
struct V_200 * V_201 ;
F_70 () ;
V_201 = F_75 ( V_22 -> V_50 ) ;
if ( V_201 ) {
if ( V_201 -> V_202 ) {
V_22 -> V_141 =
V_201 -> V_202 -> V_203 ;
V_22 -> V_142 = V_22 -> V_141 ;
}
}
F_74 () ;
} else {
V_22 -> V_141 = F_36 ( V_22 -> V_47 ) ;
V_22 -> V_142 = F_36 ( V_22 -> V_48 ) ;
}
V_22 -> V_138 = F_36 ( V_22 -> V_45 ) ;
V_22 -> V_139 = F_36 ( V_22 -> V_46 ) ;
}
V_22 -> V_130 = V_22 -> V_26 ;
if ( V_22 -> V_26 > V_22 -> V_27 )
V_22 -> V_27 = V_22 -> V_26 ;
V_22 -> V_96 = 0 ;
V_22 -> V_97 = 0 ;
V_22 -> V_100 = V_22 -> V_141 ;
V_22 -> V_101 = V_22 -> V_138 ;
V_22 -> V_102 = V_22 -> V_55 ;
V_22 -> V_103 = V_22 -> V_53 ;
V_22 -> V_105 = 0 ;
}
static void F_76 ( struct V_21 * V_22 , T_5 V_204 )
{
T_5 V_205 , V_206 ;
T_8 V_207 ;
struct V_208 V_148 ;
F_77 ( & V_148 . V_209 , V_210 , V_211 ) ;
F_78 ( & V_148 . V_209 , V_204 ) ;
V_207 = F_79 ( F_80 ( & V_148 . V_209 ) ) ;
if ( V_207 <= 0 ) {
V_22 -> V_212 = F_81 ( V_204 , V_22 -> V_29 ) ;
return;
}
V_205 = F_19 () ;
if ( V_207 < 100000 ) {
do {
V_206 = F_19 () ;
} while ( F_82 ( V_206 , V_204 ) < 0 );
} else {
F_83 ( & V_148 , V_12 ) ;
do {
F_84 ( V_213 ) ;
F_85 ( & V_148 . V_209 , V_211 ) ;
if ( ! F_86 ( & V_148 . V_209 ) )
V_148 . V_214 = NULL ;
if ( F_87 ( V_148 . V_214 ) )
F_88 () ;
F_89 ( & V_148 . V_209 ) ;
} while ( V_148 . V_214 && V_22 -> V_88 && ! F_90 ( V_12 ) );
F_91 ( V_215 ) ;
V_206 = F_19 () ;
}
V_22 -> V_90 += F_79 ( F_92 ( V_206 , V_205 ) ) ;
V_22 -> V_212 = F_81 ( V_204 , V_22 -> V_29 ) ;
}
static inline void F_93 ( struct V_21 * V_22 )
{
V_22 -> V_190 = 0 ;
V_22 -> V_190 += V_22 -> V_59 * sizeof( V_216 ) ;
V_22 -> V_190 += F_94 ( V_22 ) ;
V_22 -> V_190 += F_95 ( V_22 ) ;
}
static inline int F_96 ( const struct V_21 * V_22 , int V_217 )
{
return ! ! ( V_22 -> V_218 [ V_217 ] . V_37 & V_219 ) ;
}
static inline int F_97 ( struct V_21 * V_22 )
{
int V_217 = V_22 -> V_220 ;
if ( V_22 -> V_37 & V_80 ) {
if ( V_22 -> V_218 [ V_217 ] . V_7 >= V_22 -> V_33 ) {
V_22 -> V_218 [ V_217 ] . V_7 = 0 ;
V_22 -> V_218 [ V_217 ] . V_37 = 0 ;
V_22 -> V_220 += 1 ;
if ( V_22 -> V_220 >= V_22 -> V_32 )
V_22 -> V_220 = 0 ;
}
} else {
V_217 = F_98 () % V_22 -> V_32 ;
V_22 -> V_220 = V_217 ;
if ( V_22 -> V_218 [ V_217 ] . V_7 > V_22 -> V_33 ) {
V_22 -> V_218 [ V_217 ] . V_7 = 0 ;
V_22 -> V_218 [ V_217 ] . V_37 = 0 ;
}
}
return V_22 -> V_220 ;
}
static void F_99 ( struct V_21 * V_22 , int V_217 )
{
struct V_221 * V_222 = V_22 -> V_218 [ V_217 ] . V_222 ;
struct V_10 * V_11 = F_4 ( F_63 ( V_22 -> V_50 ) , V_15 ) ;
if ( ! V_222 ) {
if ( V_22 -> V_82 ) {
V_222 = F_100 ( V_11 -> V_177 , F_29 ( V_22 -> V_82 ) , V_223 ) ;
} else {
V_222 = F_101 ( V_11 -> V_177 , V_224 ,
( V_225 * ) & V_22 -> V_101 ,
( V_225 * ) & V_22 -> V_100 ,
V_223 ,
V_22 -> V_226 ,
V_22 -> V_227 , 0 ) ;
}
if ( V_222 ) {
V_22 -> V_218 [ V_217 ] . V_222 = V_222 ;
F_93 ( V_22 ) ;
V_22 -> V_190 += V_222 -> V_228 . V_229 ;
}
}
}
static void F_102 ( struct V_21 * V_22 )
{
if ( V_22 -> V_37 & V_79 )
V_22 -> V_104 = F_103 () ;
else if ( V_22 -> V_34 <= V_22 -> V_35 ) {
T_9 V_148 ;
if ( V_22 -> V_37 & V_78 ) {
V_148 = F_98 () %
( V_22 -> V_35 -
V_22 -> V_34 + 1 )
+ V_22 -> V_34 ;
} else {
V_148 = V_22 -> V_104 + 1 ;
if ( V_148 > V_22 -> V_35 )
V_148 = V_22 -> V_34 ;
}
V_22 -> V_104 = V_148 ;
}
V_22 -> V_104 = V_22 -> V_104 % V_22 -> V_50 -> V_183 ;
}
static void F_104 ( struct V_21 * V_22 )
{
T_7 V_230 ;
T_7 V_231 ;
int V_217 = 0 ;
if ( V_22 -> V_32 )
V_217 = F_97 ( V_22 ) ;
if ( V_22 -> V_57 > 1 ) {
T_7 V_232 ;
T_7 V_117 ;
if ( V_22 -> V_37 & V_83 )
V_232 = F_98 () % V_22 -> V_57 ;
else {
V_232 = V_22 -> V_97 ++ ;
if ( V_22 -> V_97 >=
V_22 -> V_57 )
V_22 -> V_97 = 0 ;
}
V_117 = V_22 -> V_49 [ 5 ] + ( V_232 & 0xFF ) ;
V_22 -> V_143 [ 11 ] = V_117 ;
V_117 = ( V_22 -> V_49 [ 4 ] + ( ( V_232 >> 8 ) & 0xFF ) + ( V_117 >> 8 ) ) ;
V_22 -> V_143 [ 10 ] = V_117 ;
V_117 = ( V_22 -> V_49 [ 3 ] + ( ( V_232 >> 16 ) & 0xFF ) + ( V_117 >> 8 ) ) ;
V_22 -> V_143 [ 9 ] = V_117 ;
V_117 = ( V_22 -> V_49 [ 2 ] + ( ( V_232 >> 24 ) & 0xFF ) + ( V_117 >> 8 ) ) ;
V_22 -> V_143 [ 8 ] = V_117 ;
V_117 = ( V_22 -> V_49 [ 1 ] + ( V_117 >> 8 ) ) ;
V_22 -> V_143 [ 7 ] = V_117 ;
}
if ( V_22 -> V_58 > 1 ) {
T_7 V_232 ;
T_7 V_117 ;
if ( V_22 -> V_37 & V_84 )
V_232 = F_98 () % V_22 -> V_58 ;
else {
V_232 = V_22 -> V_96 ++ ;
if ( V_22 -> V_96 >=
V_22 -> V_58 ) {
V_22 -> V_96 = 0 ;
}
}
V_117 = V_22 -> V_52 [ 5 ] + ( V_232 & 0xFF ) ;
V_22 -> V_143 [ 5 ] = V_117 ;
V_117 = ( V_22 -> V_52 [ 4 ] + ( ( V_232 >> 8 ) & 0xFF ) + ( V_117 >> 8 ) ) ;
V_22 -> V_143 [ 4 ] = V_117 ;
V_117 = ( V_22 -> V_52 [ 3 ] + ( ( V_232 >> 16 ) & 0xFF ) + ( V_117 >> 8 ) ) ;
V_22 -> V_143 [ 3 ] = V_117 ;
V_117 = ( V_22 -> V_52 [ 2 ] + ( ( V_232 >> 24 ) & 0xFF ) + ( V_117 >> 8 ) ) ;
V_22 -> V_143 [ 2 ] = V_117 ;
V_117 = ( V_22 -> V_52 [ 1 ] + ( V_117 >> 8 ) ) ;
V_22 -> V_143 [ 1 ] = V_117 ;
}
if ( V_22 -> V_37 & V_77 ) {
unsigned int V_60 ;
for ( V_60 = 0 ; V_60 < V_22 -> V_59 ; V_60 ++ )
if ( V_22 -> V_61 [ V_60 ] & V_118 )
V_22 -> V_61 [ V_60 ] = V_118 |
( ( V_233 V_234 ) F_98 () &
F_29 ( 0x000fffff ) ) ;
}
if ( ( V_22 -> V_37 & V_85 ) && ( V_22 -> V_62 != 0xffff ) ) {
V_22 -> V_62 = F_98 () & ( 4096 - 1 ) ;
}
if ( ( V_22 -> V_37 & V_86 ) && ( V_22 -> V_65 != 0xffff ) ) {
V_22 -> V_65 = F_98 () & ( 4096 - 1 ) ;
}
if ( V_22 -> V_53 < V_22 -> V_54 ) {
if ( V_22 -> V_37 & V_74 )
V_22 -> V_103 = F_98 () %
( V_22 -> V_54 - V_22 -> V_53 )
+ V_22 -> V_53 ;
else {
V_22 -> V_103 ++ ;
if ( V_22 -> V_103 >= V_22 -> V_54 )
V_22 -> V_103 = V_22 -> V_53 ;
}
}
if ( V_22 -> V_55 < V_22 -> V_56 ) {
if ( V_22 -> V_37 & V_75 ) {
V_22 -> V_102 = F_98 () %
( V_22 -> V_56 - V_22 -> V_55 )
+ V_22 -> V_55 ;
} else {
V_22 -> V_102 ++ ;
if ( V_22 -> V_102 >= V_22 -> V_56 )
V_22 -> V_102 = V_22 -> V_55 ;
}
}
if ( ! ( V_22 -> V_37 & V_38 ) ) {
V_230 = F_17 ( V_22 -> V_141 ) ;
V_231 = F_17 ( V_22 -> V_142 ) ;
if ( V_230 < V_231 ) {
T_7 V_148 ;
if ( V_22 -> V_37 & V_71 )
V_148 = F_98 () % ( V_231 - V_230 ) + V_230 ;
else {
V_148 = F_17 ( V_22 -> V_100 ) ;
V_148 ++ ;
if ( V_148 > V_231 )
V_148 = V_230 ;
}
V_22 -> V_100 = F_29 ( V_148 ) ;
}
if ( V_22 -> V_32 && F_96 ( V_22 , V_217 ) ) {
V_22 -> V_101 = V_22 -> V_218 [ V_217 ] . V_101 ;
} else {
V_230 = F_17 ( V_22 -> V_138 ) ;
V_231 = F_17 ( V_22 -> V_139 ) ;
if ( V_230 < V_231 ) {
T_7 V_148 ;
V_234 V_235 ;
if ( V_22 -> V_37 & V_72 ) {
do {
V_148 = F_98 () %
( V_231 - V_230 ) + V_230 ;
V_235 = F_29 ( V_148 ) ;
} while ( F_105 ( V_235 ) ||
F_106 ( V_235 ) ||
F_107 ( V_235 ) ||
F_108 ( V_235 ) ||
F_109 ( V_235 ) );
V_22 -> V_101 = V_235 ;
} else {
V_148 = F_17 ( V_22 -> V_101 ) ;
V_148 ++ ;
if ( V_148 > V_231 ) {
V_148 = V_230 ;
}
V_22 -> V_101 = F_29 ( V_148 ) ;
}
}
if ( V_22 -> V_32 ) {
V_22 -> V_218 [ V_217 ] . V_37 |= V_219 ;
V_22 -> V_218 [ V_217 ] . V_101 =
V_22 -> V_101 ;
#ifdef F_18
if ( V_22 -> V_37 & V_81 )
F_99 ( V_22 , V_217 ) ;
#endif
V_22 -> V_105 ++ ;
}
}
} else {
if ( ! F_110 ( & V_22 -> V_43 ) ) {
int V_60 ;
for ( V_60 = 0 ; V_60 < 4 ; V_60 ++ ) {
V_22 -> V_99 . V_236 [ V_60 ] =
( ( ( V_233 V_234 ) F_98 () |
V_22 -> V_43 . V_236 [ V_60 ] ) &
V_22 -> V_44 . V_236 [ V_60 ] ) ;
}
}
}
if ( V_22 -> V_26 < V_22 -> V_27 ) {
T_7 V_148 ;
if ( V_22 -> V_37 & V_73 ) {
V_148 = F_98 () %
( V_22 -> V_27 - V_22 -> V_26 )
+ V_22 -> V_26 ;
} else {
V_148 = V_22 -> V_130 + 1 ;
if ( V_148 > V_22 -> V_27 )
V_148 = V_22 -> V_26 ;
}
V_22 -> V_130 = V_148 ;
}
F_102 ( V_22 ) ;
V_22 -> V_218 [ V_217 ] . V_7 ++ ;
}
static int F_111 ( struct V_237 * V_238 , struct V_21 * V_22 )
{
struct V_221 * V_222 = V_22 -> V_218 [ V_22 -> V_220 ] . V_222 ;
int V_178 = 0 ;
struct V_177 * V_177 = F_63 ( V_22 -> V_50 ) ;
if ( ! V_222 )
return 0 ;
if ( ( V_222 -> V_228 . V_239 != V_240 ) && ( V_22 -> V_82 == 0 ) )
return 0 ;
if ( ( V_222 -> V_228 . V_239 == V_241 ) && ( V_22 -> V_82 != 0 ) )
V_238 -> V_242 = ( unsigned long ) & V_22 -> V_243 | V_244 ;
F_112 () ;
V_178 = V_222 -> V_245 -> V_246 ( V_222 , V_238 ) ;
F_113 () ;
if ( V_178 ) {
F_114 ( V_177 , V_247 ) ;
goto error;
}
V_178 = V_222 -> type -> V_246 ( V_222 , V_238 ) ;
if ( V_178 ) {
F_114 ( V_177 , V_248 ) ;
goto error;
}
F_115 ( & V_222 -> V_194 ) ;
V_222 -> V_249 . V_250 += V_238 -> V_116 ;
V_222 -> V_249 . V_251 ++ ;
F_116 ( & V_222 -> V_194 ) ;
error:
return V_178 ;
}
static void F_117 ( struct V_21 * V_22 )
{
if ( V_22 -> V_32 ) {
int V_60 ;
for ( V_60 = 0 ; V_60 < V_22 -> V_32 ; V_60 ++ ) {
struct V_221 * V_222 = V_22 -> V_218 [ V_60 ] . V_222 ;
if ( V_222 ) {
F_118 ( V_222 ) ;
V_22 -> V_218 [ V_60 ] . V_222 = NULL ;
}
}
}
}
static int F_119 ( struct V_21 * V_22 ,
struct V_237 * V_238 , T_10 V_252 )
{
if ( V_22 -> V_37 & V_81 ) {
struct V_221 * V_222 = V_22 -> V_218 [ V_22 -> V_220 ] . V_222 ;
int V_253 = 0 ;
if ( V_222 ) {
int V_149 ;
T_11 * V_254 ;
struct V_199 * V_255 ;
V_253 = V_222 -> V_228 . V_229 - F_120 ( V_238 ) ;
if ( V_253 > 0 ) {
V_149 = F_121 ( V_238 , V_253 , 0 , V_256 ) ;
if ( V_149 < 0 ) {
F_48 ( L_240 ,
V_149 ) ;
goto V_178;
}
}
F_122 ( V_238 , V_257 ) ;
V_149 = F_111 ( V_238 , V_22 ) ;
if ( V_149 ) {
F_48 ( L_241 , V_149 ) ;
goto V_178;
}
V_254 = ( T_11 * ) F_123 ( V_238 , V_257 ) ;
memcpy ( V_254 , V_22 -> V_143 , 12 ) ;
* ( V_258 * ) & V_254 [ 12 ] = V_252 ;
V_255 = F_124 ( V_238 ) ;
V_255 -> V_259 = F_125 ( V_238 -> V_116 - V_257 ) ;
F_126 ( V_255 ) ;
}
}
return 1 ;
V_178:
F_127 ( V_238 ) ;
return 0 ;
}
static void F_128 ( V_234 * V_260 , struct V_21 * V_22 )
{
unsigned int V_60 ;
for ( V_60 = 0 ; V_60 < V_22 -> V_59 ; V_60 ++ )
* V_260 ++ = V_22 -> V_61 [ V_60 ] & ~ V_118 ;
V_260 -- ;
* V_260 |= V_118 ;
}
static inline T_10 F_129 ( unsigned int V_261 , unsigned int V_262 ,
unsigned int V_263 )
{
return F_125 ( V_261 | ( V_262 << 12 ) | ( V_263 << 13 ) ) ;
}
static void F_130 ( struct V_21 * V_22 , struct V_237 * V_238 ,
int V_264 )
{
struct V_265 V_266 ;
struct V_189 * V_267 ;
V_267 = (struct V_189 * ) F_131 ( V_238 , sizeof( * V_267 ) ) ;
V_264 -= sizeof( * V_267 ) ;
if ( V_22 -> V_28 <= 0 ) {
memset ( F_131 ( V_238 , V_264 ) , 0 , V_264 ) ;
} else {
int V_268 = V_22 -> V_28 ;
int V_60 , V_116 ;
int V_269 ;
if ( V_268 > V_270 )
V_268 = V_270 ;
V_116 = V_264 - V_268 * V_271 ;
if ( V_116 > 0 ) {
memset ( F_131 ( V_238 , V_116 ) , 0 , V_116 ) ;
V_264 = V_268 * V_271 ;
}
V_60 = 0 ;
V_269 = ( V_264 / V_268 ) < V_271 ?
( V_264 / V_268 ) : V_271 ;
while ( V_264 > 0 ) {
if ( F_132 ( ! V_22 -> V_136 ) ) {
int V_70 = F_133 () ;
if ( V_22 -> V_70 >= 0 && ( V_22 -> V_37 & V_87 ) )
V_70 = V_22 -> V_70 ;
V_22 -> V_136 = F_134 ( V_70 , V_272 | V_273 , 0 ) ;
if ( ! V_22 -> V_136 )
break;
}
F_135 ( V_22 -> V_136 ) ;
F_136 ( V_238 , V_60 , V_22 -> V_136 ) ;
F_137 ( V_238 ) -> V_268 [ V_60 ] . V_274 = 0 ;
if ( V_60 == ( V_268 - 1 ) )
F_138 ( & F_137 ( V_238 ) -> V_268 [ V_60 ] ,
( V_264 < V_271 ? V_264 : V_271 ) ) ;
else
F_138 ( & F_137 ( V_238 ) -> V_268 [ V_60 ] , V_269 ) ;
V_264 -= F_139 ( & F_137 ( V_238 ) -> V_268 [ V_60 ] ) ;
V_238 -> V_116 += F_139 ( & F_137 ( V_238 ) -> V_268 [ V_60 ] ) ;
V_238 -> V_275 += F_139 ( & F_137 ( V_238 ) -> V_268 [ V_60 ] ) ;
V_60 ++ ;
F_137 ( V_238 ) -> V_276 = V_60 ;
}
}
V_267 -> V_277 = F_29 ( V_278 ) ;
V_267 -> V_95 = F_29 ( V_22 -> V_95 ) ;
F_140 ( & V_266 ) ;
V_267 -> V_279 = F_29 ( V_266 . V_279 ) ;
V_267 -> V_280 = F_29 ( V_266 . V_280 ) ;
}
static struct V_237 * F_141 ( struct V_162 * V_163 ,
struct V_21 * V_22 ,
unsigned int V_281 )
{
struct V_237 * V_238 = NULL ;
unsigned int V_282 = V_22 -> V_130 + 64 + V_281 +
V_22 -> V_190 ;
if ( V_22 -> V_37 & V_87 ) {
int V_70 = V_22 -> V_70 >= 0 ? V_22 -> V_70 : F_133 () ;
V_238 = F_142 ( V_283 + V_282 , V_284 , 0 , V_70 ) ;
if ( F_87 ( V_238 ) ) {
F_143 ( V_238 , V_283 ) ;
V_238 -> V_163 = V_163 ;
}
} else {
V_238 = F_144 ( V_163 , V_282 , V_284 ) ;
}
return V_238 ;
}
static struct V_237 * F_145 ( struct V_162 * V_50 ,
struct V_21 * V_22 )
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
if ( V_22 -> V_59 )
V_252 = F_125 ( V_293 ) ;
if ( V_22 -> V_62 != 0xffff )
V_252 = F_125 ( V_294 ) ;
F_104 ( V_22 ) ;
V_292 = V_22 -> V_104 ;
V_264 = ( V_50 -> V_295 + 16 ) & ~ 0xf ;
V_238 = F_141 ( V_50 , V_22 , V_264 ) ;
if ( ! V_238 ) {
sprintf ( V_22 -> V_106 , L_242 ) ;
return NULL ;
}
F_146 ( V_238 -> V_9 ) ;
F_143 ( V_238 , V_264 ) ;
V_254 = ( T_11 * ) F_123 ( V_238 , 14 ) ;
V_260 = ( V_234 * ) F_131 ( V_238 , V_22 -> V_59 * sizeof( T_7 ) ) ;
if ( V_22 -> V_59 )
F_128 ( V_260 , V_22 ) ;
if ( V_22 -> V_62 != 0xffff ) {
if ( V_22 -> V_65 != 0xffff ) {
V_290 = ( T_10 * ) F_131 ( V_238 , sizeof( T_10 ) ) ;
* V_290 = F_129 ( V_22 -> V_65 ,
V_22 -> V_67 ,
V_22 -> V_66 ) ;
V_291 = ( T_10 * ) F_131 ( V_238 , sizeof( T_10 ) ) ;
* V_291 = F_125 ( V_294 ) ;
}
V_288 = ( T_10 * ) F_131 ( V_238 , sizeof( T_10 ) ) ;
* V_288 = F_129 ( V_22 -> V_62 ,
V_22 -> V_64 ,
V_22 -> V_63 ) ;
V_289 = ( T_10 * ) F_131 ( V_238 , sizeof( T_10 ) ) ;
* V_289 = F_125 ( V_287 ) ;
}
F_147 ( V_238 , 0 ) ;
F_148 ( V_238 , V_238 -> V_116 ) ;
V_255 = (struct V_199 * ) F_131 ( V_238 , sizeof( struct V_199 ) ) ;
F_149 ( V_238 , V_238 -> V_116 ) ;
V_285 = (struct V_188 * ) F_131 ( V_238 , sizeof( struct V_188 ) ) ;
F_150 ( V_238 , V_292 ) ;
V_238 -> V_296 = V_22 -> V_36 ;
memcpy ( V_254 , V_22 -> V_143 , 12 ) ;
* ( T_10 * ) & V_254 [ 12 ] = V_252 ;
V_264 = V_22 -> V_130 - 14 - 20 - 8 -
V_22 -> V_190 ;
if ( V_264 < 0 || V_264 < sizeof( struct V_189 ) )
V_264 = sizeof( struct V_189 ) ;
V_285 -> V_297 = F_125 ( V_22 -> V_103 ) ;
V_285 -> V_298 = F_125 ( V_22 -> V_102 ) ;
V_285 -> V_116 = F_125 ( V_264 + 8 ) ;
V_285 -> V_299 = 0 ;
V_255 -> V_300 = 5 ;
V_255 -> V_4 = 4 ;
V_255 -> V_301 = 32 ;
V_255 -> V_68 = V_22 -> V_68 ;
V_255 -> V_252 = V_302 ;
V_255 -> V_303 = V_22 -> V_100 ;
V_255 -> V_304 = V_22 -> V_101 ;
V_255 -> V_261 = F_125 ( V_22 -> V_305 ) ;
V_22 -> V_305 ++ ;
V_255 -> V_306 = 0 ;
V_286 = 20 + 8 + V_264 ;
V_255 -> V_259 = F_125 ( V_286 ) ;
F_126 ( V_255 ) ;
V_238 -> V_252 = V_252 ;
V_238 -> V_163 = V_50 ;
V_238 -> V_307 = V_308 ;
if ( ! ( V_22 -> V_37 & V_76 ) ) {
V_238 -> V_309 = V_310 ;
} else if ( V_50 -> V_311 & V_312 ) {
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
F_130 ( V_22 , V_238 , V_264 ) ;
#ifdef F_18
if ( ! F_119 ( V_22 , V_238 , V_252 ) )
return NULL ;
#endif
return V_238 ;
}
static struct V_237 * F_154 ( struct V_162 * V_50 ,
struct V_21 * V_22 )
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
if ( V_22 -> V_59 )
V_252 = F_125 ( V_293 ) ;
if ( V_22 -> V_62 != 0xffff )
V_252 = F_125 ( V_294 ) ;
F_104 ( V_22 ) ;
V_292 = V_22 -> V_104 ;
V_238 = F_141 ( V_50 , V_22 , 16 ) ;
if ( ! V_238 ) {
sprintf ( V_22 -> V_106 , L_242 ) ;
return NULL ;
}
F_146 ( V_238 -> V_9 ) ;
F_143 ( V_238 , 16 ) ;
V_254 = ( T_11 * ) F_123 ( V_238 , 14 ) ;
V_260 = ( V_234 * ) F_131 ( V_238 , V_22 -> V_59 * sizeof( T_7 ) ) ;
if ( V_22 -> V_59 )
F_128 ( V_260 , V_22 ) ;
if ( V_22 -> V_62 != 0xffff ) {
if ( V_22 -> V_65 != 0xffff ) {
V_290 = ( T_10 * ) F_131 ( V_238 , sizeof( T_10 ) ) ;
* V_290 = F_129 ( V_22 -> V_65 ,
V_22 -> V_67 ,
V_22 -> V_66 ) ;
V_291 = ( T_10 * ) F_131 ( V_238 , sizeof( T_10 ) ) ;
* V_291 = F_125 ( V_294 ) ;
}
V_288 = ( T_10 * ) F_131 ( V_238 , sizeof( T_10 ) ) ;
* V_288 = F_129 ( V_22 -> V_62 ,
V_22 -> V_64 ,
V_22 -> V_63 ) ;
V_289 = ( T_10 * ) F_131 ( V_238 , sizeof( T_10 ) ) ;
* V_289 = F_125 ( V_317 ) ;
}
F_147 ( V_238 , 0 ) ;
F_148 ( V_238 , V_238 -> V_116 ) ;
V_255 = (struct V_187 * ) F_131 ( V_238 , sizeof( struct V_187 ) ) ;
F_149 ( V_238 , V_238 -> V_116 ) ;
V_285 = (struct V_188 * ) F_131 ( V_238 , sizeof( struct V_188 ) ) ;
F_150 ( V_238 , V_292 ) ;
V_238 -> V_296 = V_22 -> V_36 ;
memcpy ( V_254 , V_22 -> V_143 , 12 ) ;
* ( T_10 * ) & V_254 [ 12 ] = V_252 ;
V_264 = V_22 -> V_130 - 14 -
sizeof( struct V_187 ) - sizeof( struct V_188 ) -
V_22 -> V_190 ;
if ( V_264 < 0 || V_264 < sizeof( struct V_189 ) ) {
V_264 = sizeof( struct V_189 ) ;
F_155 ( L_243 , V_264 ) ;
}
V_316 = V_264 + sizeof( struct V_188 ) ;
V_285 -> V_297 = F_125 ( V_22 -> V_103 ) ;
V_285 -> V_298 = F_125 ( V_22 -> V_102 ) ;
V_285 -> V_116 = F_125 ( V_316 ) ;
V_285 -> V_299 = 0 ;
* ( V_234 * ) V_255 = F_29 ( 0x60000000 ) ;
if ( V_22 -> V_69 ) {
* ( V_234 * ) V_255 |= F_29 ( 0x60000000 | ( V_22 -> V_69 << 20 ) ) ;
}
V_255 -> V_318 = 32 ;
V_255 -> V_319 = F_125 ( V_316 ) ;
V_255 -> V_320 = V_302 ;
V_255 -> V_304 = V_22 -> V_99 ;
V_255 -> V_303 = V_22 -> V_98 ;
V_238 -> V_252 = V_252 ;
V_238 -> V_163 = V_50 ;
V_238 -> V_307 = V_308 ;
if ( ! ( V_22 -> V_37 & V_76 ) ) {
V_238 -> V_309 = V_310 ;
} else if ( V_50 -> V_311 & V_321 ) {
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
F_130 ( V_22 , V_238 , V_264 ) ;
return V_238 ;
}
static struct V_237 * F_159 ( struct V_162 * V_50 ,
struct V_21 * V_22 )
{
if ( V_22 -> V_37 & V_38 )
return F_154 ( V_50 , V_22 ) ;
else
return F_145 ( V_50 , V_22 ) ;
}
static void F_40 ( struct V_21 * V_22 )
{
V_22 -> V_95 = 1 ;
V_22 -> V_90 = 0 ;
V_22 -> V_92 = 0 ;
V_22 -> V_325 = 0 ;
V_22 -> V_93 = 0 ;
}
static void F_160 ( struct V_147 * V_148 )
{
struct V_21 * V_22 ;
int V_326 = 0 ;
F_161 () ;
F_44 ( V_148 ) ;
F_45 (pkt_dev, &t->if_list, list) {
F_69 ( V_22 ) ;
if ( V_22 -> V_50 ) {
F_40 ( V_22 ) ;
V_22 -> V_88 = 1 ;
V_22 -> V_238 = NULL ;
V_22 -> V_94 = V_22 -> V_212 = F_19 () ;
F_93 ( V_22 ) ;
strcpy ( V_22 -> V_106 , L_244 ) ;
V_326 ++ ;
} else
strcpy ( V_22 -> V_106 , L_245 ) ;
}
F_46 ( V_148 ) ;
if ( V_326 )
V_148 -> V_152 &= ~ ( V_327 ) ;
}
static void F_7 ( struct V_10 * V_11 )
{
struct V_147 * V_148 ;
F_161 () ;
F_49 ( & V_151 ) ;
F_45 (t, &pn->pktgen_threads, th_list)
V_148 -> V_152 |= V_327 ;
F_51 ( & V_151 ) ;
}
static int F_162 ( const struct V_147 * V_148 )
{
const struct V_21 * V_22 ;
F_45 (pkt_dev, &t->if_list, list)
if ( V_22 -> V_88 )
return 1 ;
return 0 ;
}
static int F_163 ( struct V_147 * V_148 )
{
F_44 ( V_148 ) ;
while ( F_162 ( V_148 ) ) {
F_46 ( V_148 ) ;
F_164 ( 100 ) ;
if ( F_90 ( V_12 ) )
goto signal;
F_44 ( V_148 ) ;
}
F_46 ( V_148 ) ;
return 1 ;
signal:
return 0 ;
}
static int F_165 ( struct V_10 * V_11 )
{
struct V_147 * V_148 ;
int V_328 = 1 ;
F_49 ( & V_151 ) ;
F_45 (t, &pn->pktgen_threads, th_list) {
V_328 = F_163 ( V_148 ) ;
if ( V_328 == 0 )
break;
}
if ( V_328 == 0 )
F_45 (t, &pn->pktgen_threads, th_list)
V_148 -> V_152 |= ( V_327 ) ;
F_51 ( & V_151 ) ;
return V_328 ;
}
static void F_8 ( struct V_10 * V_11 )
{
struct V_147 * V_148 ;
F_161 () ;
F_49 ( & V_151 ) ;
F_45 (t, &pn->pktgen_threads, th_list)
V_148 -> V_152 |= ( V_329 ) ;
F_51 ( & V_151 ) ;
F_52 ( F_53 ( 125 ) ) ;
F_165 ( V_11 ) ;
}
static void F_9 ( struct V_10 * V_11 )
{
struct V_147 * V_148 ;
F_161 () ;
F_49 ( & V_151 ) ;
F_45 (t, &pn->pktgen_threads, th_list)
V_148 -> V_152 |= ( V_153 ) ;
F_51 ( & V_151 ) ;
F_52 ( F_53 ( 125 ) ) ;
F_165 ( V_11 ) ;
}
static void F_166 ( struct V_21 * V_22 , int V_276 )
{
T_13 V_330 , V_331 , V_332 ;
char * V_333 = V_22 -> V_106 ;
T_5 V_334 = F_92 ( V_22 -> V_89 ,
V_22 -> V_94 ) ;
T_5 V_25 = F_167 ( V_22 -> V_90 ) ;
V_333 += sprintf ( V_333 , L_246 ,
( unsigned long long ) F_21 ( V_334 ) ,
( unsigned long long ) F_21 ( F_92 ( V_334 , V_25 ) ) ,
( unsigned long long ) F_21 ( V_25 ) ,
( unsigned long long ) V_22 -> V_92 ,
V_22 -> V_130 , V_276 ) ;
V_332 = F_168 ( V_22 -> V_92 * V_132 ,
F_79 ( V_334 ) ) ;
V_330 = V_332 * 8 * V_22 -> V_130 ;
V_331 = V_330 ;
F_20 ( V_331 , 1000000 ) ;
V_333 += sprintf ( V_333 , L_247 ,
( unsigned long long ) V_332 ,
( unsigned long long ) V_331 ,
( unsigned long long ) V_330 ,
( unsigned long long ) V_22 -> V_93 ) ;
}
static int F_169 ( struct V_21 * V_22 )
{
int V_276 = V_22 -> V_238 ? F_137 ( V_22 -> V_238 ) -> V_276 : - 1 ;
if ( ! V_22 -> V_88 ) {
F_10 ( L_248 ,
V_22 -> V_31 ) ;
return - V_18 ;
}
F_127 ( V_22 -> V_238 ) ;
V_22 -> V_238 = NULL ;
V_22 -> V_89 = F_19 () ;
V_22 -> V_88 = 0 ;
F_166 ( V_22 , V_276 ) ;
return 0 ;
}
static struct V_21 * F_170 ( struct V_147 * V_148 )
{
struct V_21 * V_22 , * V_335 = NULL ;
F_44 ( V_148 ) ;
F_45 (pkt_dev, &t->if_list, list) {
if ( ! V_22 -> V_88 )
continue;
if ( V_335 == NULL )
V_335 = V_22 ;
else if ( F_82 ( V_22 -> V_212 , V_335 -> V_212 ) < 0 )
V_335 = V_22 ;
}
F_46 ( V_148 ) ;
return V_335 ;
}
static void F_171 ( struct V_147 * V_148 )
{
struct V_21 * V_22 ;
F_161 () ;
F_44 ( V_148 ) ;
F_45 (pkt_dev, &t->if_list, list) {
F_169 ( V_22 ) ;
}
F_46 ( V_148 ) ;
}
static void F_172 ( struct V_147 * V_148 )
{
struct V_336 * V_337 , * V_115 ;
struct V_21 * V_338 ;
F_161 () ;
F_44 ( V_148 ) ;
F_173 (q, n, &t->if_list) {
V_338 = F_174 ( V_337 , struct V_21 , V_339 ) ;
if ( ! V_338 -> V_157 )
continue;
F_127 ( V_338 -> V_238 ) ;
V_338 -> V_238 = NULL ;
F_175 ( V_148 , V_338 ) ;
break;
}
F_46 ( V_148 ) ;
}
static void F_176 ( struct V_147 * V_148 )
{
struct V_336 * V_337 , * V_115 ;
struct V_21 * V_338 ;
F_161 () ;
F_44 ( V_148 ) ;
F_173 (q, n, &t->if_list) {
V_338 = F_174 ( V_337 , struct V_21 , V_339 ) ;
F_127 ( V_338 -> V_238 ) ;
V_338 -> V_238 = NULL ;
F_175 ( V_148 , V_338 ) ;
}
F_46 ( V_148 ) ;
}
static void F_177 ( struct V_147 * V_148 )
{
F_178 ( V_148 -> V_340 -> V_341 , V_148 -> V_177 -> V_165 ) ;
}
static void F_179 ( struct V_21 * V_22 )
{
T_5 V_342 = F_19 () ;
F_88 () ;
V_22 -> V_90 += F_79 ( F_92 ( F_19 () , V_342 ) ) ;
}
static void F_180 ( struct V_21 * V_22 )
{
T_5 V_342 = F_19 () ;
while ( F_181 ( & ( V_22 -> V_238 -> V_343 ) ) != 1 ) {
if ( F_90 ( V_12 ) )
break;
if ( F_182 () )
F_179 ( V_22 ) ;
else
F_183 () ;
}
V_22 -> V_90 += F_79 ( F_92 ( F_19 () , V_342 ) ) ;
}
static void F_184 ( struct V_21 * V_22 )
{
struct V_162 * V_50 = V_22 -> V_50 ;
T_14 (* F_185)( struct V_237 * , struct V_162 * )
= V_50 -> V_344 -> V_345 ;
struct V_346 * V_347 ;
V_258 V_292 ;
int V_149 ;
if ( F_132 ( ! F_68 ( V_50 ) || ! F_186 ( V_50 ) ) ) {
F_169 ( V_22 ) ;
return;
}
if ( F_132 ( V_22 -> V_29 == V_131 ) ) {
V_22 -> V_212 = F_81 ( F_19 () , V_348 ) ;
return;
}
if ( ! V_22 -> V_238 || ( V_22 -> V_349 &&
++ V_22 -> V_350 >= V_22 -> V_30 ) ) {
F_127 ( V_22 -> V_238 ) ;
V_22 -> V_238 = F_159 ( V_50 , V_22 ) ;
if ( V_22 -> V_238 == NULL ) {
F_48 ( L_249 ) ;
F_88 () ;
V_22 -> V_350 -- ;
return;
}
V_22 -> V_351 = V_22 -> V_238 -> V_116 ;
V_22 -> V_352 ++ ;
V_22 -> V_350 = 0 ;
}
if ( V_22 -> V_29 && V_22 -> V_349 )
F_76 ( V_22 , V_22 -> V_212 ) ;
V_292 = F_187 ( V_22 -> V_238 ) ;
V_347 = F_188 ( V_50 , V_292 ) ;
F_189 () ;
F_190 ( V_50 , V_347 , F_103 () ) ;
if ( F_132 ( F_191 ( V_347 ) ) ) {
V_149 = V_353 ;
V_22 -> V_349 = 0 ;
goto V_354;
}
F_192 ( & ( V_22 -> V_238 -> V_343 ) ) ;
V_149 = (* F_185)( V_22 -> V_238 , V_50 ) ;
switch ( V_149 ) {
case V_355 :
F_193 ( V_347 ) ;
V_22 -> V_349 = 1 ;
V_22 -> V_92 ++ ;
V_22 -> V_95 ++ ;
V_22 -> V_325 += V_22 -> V_351 ;
break;
case V_356 :
case V_357 :
case V_358 :
V_22 -> V_93 ++ ;
break;
default:
F_155 ( L_250 ,
V_22 -> V_31 , V_149 ) ;
V_22 -> V_93 ++ ;
case V_359 :
case V_353 :
F_194 ( & ( V_22 -> V_238 -> V_343 ) ) ;
V_22 -> V_349 = 0 ;
}
V_354:
F_195 ( V_50 , V_347 ) ;
F_196 () ;
if ( ( V_22 -> V_7 != 0 ) && ( V_22 -> V_92 >= V_22 -> V_7 ) ) {
F_180 ( V_22 ) ;
F_169 ( V_22 ) ;
}
}
static int F_197 ( void * V_360 )
{
F_198 ( V_361 ) ;
struct V_147 * V_148 = V_360 ;
struct V_21 * V_22 = NULL ;
int V_362 = V_148 -> V_362 ;
F_43 ( F_103 () != V_362 ) ;
F_199 ( & V_148 -> V_363 ) ;
F_200 ( & V_148 -> V_364 ) ;
F_32 ( L_251 , V_362 , F_201 ( V_12 ) ) ;
F_84 ( V_213 ) ;
F_202 () ;
while ( ! F_203 () ) {
V_22 = F_170 ( V_148 ) ;
if ( F_132 ( ! V_22 && V_148 -> V_152 == 0 ) ) {
if ( V_148 -> V_177 -> V_171 )
break;
F_204 ( V_148 -> V_363 ,
V_148 -> V_152 != 0 ,
V_365 / 10 ) ;
F_205 () ;
continue;
}
F_91 ( V_215 ) ;
if ( F_87 ( V_22 ) ) {
F_184 ( V_22 ) ;
if ( F_182 () )
F_179 ( V_22 ) ;
else
F_183 () ;
}
if ( V_148 -> V_152 & V_327 ) {
F_171 ( V_148 ) ;
V_148 -> V_152 &= ~ ( V_327 ) ;
}
if ( V_148 -> V_152 & V_329 ) {
F_160 ( V_148 ) ;
V_148 -> V_152 &= ~ ( V_329 ) ;
}
if ( V_148 -> V_152 & V_153 ) {
F_176 ( V_148 ) ;
V_148 -> V_152 &= ~ ( V_153 ) ;
}
if ( V_148 -> V_152 & V_158 ) {
F_172 ( V_148 ) ;
V_148 -> V_152 &= ~ ( V_158 ) ;
}
F_205 () ;
F_84 ( V_213 ) ;
}
F_32 ( L_252 , V_148 -> V_340 -> V_341 ) ;
F_171 ( V_148 ) ;
F_32 ( L_253 , V_148 -> V_340 -> V_341 ) ;
F_176 ( V_148 ) ;
F_32 ( L_254 , V_148 -> V_340 -> V_341 ) ;
F_177 ( V_148 ) ;
while ( ! F_203 () ) {
F_84 ( V_213 ) ;
F_88 () ;
}
F_91 ( V_215 ) ;
return 0 ;
}
static struct V_21 * F_56 ( struct V_147 * V_148 ,
const char * V_154 , bool V_155 )
{
struct V_21 * V_333 , * V_22 = NULL ;
T_3 V_116 = strlen ( V_154 ) ;
F_44 ( V_148 ) ;
F_45 (p, &t->if_list, list)
if ( strncmp ( V_333 -> V_31 , V_154 , V_116 ) == 0 ) {
if ( V_333 -> V_31 [ V_116 ] ) {
if ( V_155 || V_333 -> V_31 [ V_116 ] != '@' )
continue;
}
V_22 = V_333 ;
break;
}
F_46 ( V_148 ) ;
F_32 ( L_255 , V_154 , V_22 ) ;
return V_22 ;
}
static int F_206 ( struct V_147 * V_148 ,
struct V_21 * V_22 )
{
int V_366 = 0 ;
F_44 ( V_148 ) ;
if ( V_22 -> V_367 ) {
F_48 ( L_256 ) ;
V_366 = - V_368 ;
goto V_150;
}
F_207 ( & V_22 -> V_339 , & V_148 -> V_369 ) ;
V_22 -> V_367 = V_148 ;
V_22 -> V_88 = 0 ;
V_150:
F_46 ( V_148 ) ;
return V_366 ;
}
static int F_50 ( struct V_147 * V_148 , const char * V_154 )
{
struct V_21 * V_22 ;
int V_178 ;
int V_70 = F_208 ( V_148 -> V_362 ) ;
V_22 = F_55 ( V_148 -> V_177 , V_154 , V_156 ) ;
if ( V_22 ) {
F_48 ( L_257 ) ;
return - V_368 ;
}
V_22 = F_209 ( sizeof( struct V_21 ) , V_272 , V_70 ) ;
if ( ! V_22 )
return - V_370 ;
strcpy ( V_22 -> V_31 , V_154 ) ;
V_22 -> V_218 = F_210 ( V_144 * sizeof( struct V_371 ) ,
V_70 ) ;
if ( V_22 -> V_218 == NULL ) {
F_211 ( V_22 ) ;
return - V_370 ;
}
V_22 -> V_157 = 0 ;
V_22 -> V_28 = 0 ;
V_22 -> V_29 = V_372 ;
V_22 -> V_7 = V_373 ;
V_22 -> V_92 = 0 ;
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
V_22 -> V_70 = - 1 ;
V_178 = F_66 ( V_148 -> V_177 , V_22 , V_154 ) ;
if ( V_178 )
goto V_374;
if ( V_22 -> V_50 -> V_133 & V_134 )
V_22 -> V_30 = V_375 ;
V_22 -> V_164 = F_60 ( V_154 , 0600 , V_148 -> V_177 -> V_165 ,
& V_166 , V_22 ) ;
if ( ! V_22 -> V_164 ) {
F_48 ( L_258 ,
V_376 , V_154 ) ;
V_178 = - V_18 ;
goto V_377;
}
#ifdef F_18
V_22 -> V_226 = V_240 ;
V_22 -> V_227 = V_378 ;
V_22 -> V_379 . V_380 = V_223 ;
V_22 -> V_243 . V_163 = V_22 -> V_50 ;
F_212 ( & V_22 -> V_243 , V_381 , false ) ;
V_22 -> V_243 . V_382 = & V_22 -> V_243 ;
V_22 -> V_243 . V_383 = & V_22 -> V_379 ;
#endif
return F_206 ( V_148 , V_22 ) ;
V_377:
F_67 ( V_22 -> V_50 ) ;
V_374:
#ifdef F_18
F_117 ( V_22 ) ;
#endif
F_213 ( V_22 -> V_218 ) ;
F_211 ( V_22 ) ;
return V_178 ;
}
static int T_15 F_214 ( int V_362 , struct V_10 * V_11 )
{
struct V_147 * V_148 ;
struct V_384 * V_385 ;
struct V_386 * V_333 ;
V_148 = F_209 ( sizeof( struct V_147 ) , V_272 ,
F_208 ( V_362 ) ) ;
if ( ! V_148 ) {
F_48 ( L_259 ) ;
return - V_370 ;
}
F_215 ( & V_148 -> F_44 ) ;
V_148 -> V_362 = V_362 ;
F_216 ( & V_148 -> V_369 ) ;
F_217 ( & V_148 -> V_387 , & V_11 -> V_388 ) ;
F_218 ( & V_148 -> V_364 ) ;
V_333 = F_219 ( F_197 ,
V_148 ,
F_208 ( V_362 ) ,
L_260 , V_362 ) ;
if ( F_220 ( V_333 ) ) {
F_48 ( L_261 , V_148 -> V_362 ) ;
F_221 ( & V_148 -> V_387 ) ;
F_211 ( V_148 ) ;
return F_222 ( V_333 ) ;
}
F_223 ( V_333 , V_362 ) ;
V_148 -> V_340 = V_333 ;
V_385 = F_60 ( V_148 -> V_340 -> V_341 , 0600 , V_11 -> V_165 ,
& V_389 , V_148 ) ;
if ( ! V_385 ) {
F_48 ( L_258 ,
V_376 , V_148 -> V_340 -> V_341 ) ;
F_224 ( V_333 ) ;
F_221 ( & V_148 -> V_387 ) ;
F_211 ( V_148 ) ;
return - V_18 ;
}
V_148 -> V_177 = V_11 ;
F_225 ( V_333 ) ;
F_226 ( & V_148 -> V_364 ) ;
return 0 ;
}
static void F_227 ( struct V_147 * V_148 ,
struct V_21 * V_22 )
{
struct V_336 * V_337 , * V_115 ;
struct V_21 * V_333 ;
F_173 (q, n, &t->if_list) {
V_333 = F_174 ( V_337 , struct V_21 , V_339 ) ;
if ( V_333 == V_22 )
F_221 ( & V_333 -> V_339 ) ;
}
}
static int F_175 ( struct V_147 * V_148 ,
struct V_21 * V_22 )
{
F_32 ( L_262 , V_22 ) ;
if ( V_22 -> V_88 ) {
F_10 ( L_263 ) ;
F_169 ( V_22 ) ;
}
if ( V_22 -> V_50 ) {
F_67 ( V_22 -> V_50 ) ;
V_22 -> V_50 = NULL ;
}
F_227 ( V_148 , V_22 ) ;
if ( V_22 -> V_164 )
F_59 ( V_22 -> V_164 ) ;
#ifdef F_18
F_117 ( V_22 ) ;
#endif
F_213 ( V_22 -> V_218 ) ;
if ( V_22 -> V_136 )
F_35 ( V_22 -> V_136 ) ;
F_211 ( V_22 ) ;
return 0 ;
}
static int T_15 F_228 ( struct V_177 * V_177 )
{
struct V_10 * V_11 = F_4 ( V_177 , V_15 ) ;
struct V_384 * V_385 ;
int V_362 , V_149 = 0 ;
V_11 -> V_177 = V_177 ;
F_216 ( & V_11 -> V_388 ) ;
V_11 -> V_171 = false ;
V_11 -> V_165 = F_229 ( V_376 , V_11 -> V_177 -> V_390 ) ;
if ( ! V_11 -> V_165 ) {
F_230 ( L_264 , V_376 ) ;
return - V_179 ;
}
V_385 = F_231 ( V_391 , 0600 , V_11 -> V_165 , & V_392 ) ;
if ( V_385 == NULL ) {
F_48 ( L_265 , V_391 ) ;
V_149 = - V_18 ;
goto remove;
}
F_232 (cpu) {
int V_178 ;
V_178 = F_214 ( V_362 , V_11 ) ;
if ( V_178 )
F_230 ( L_266 ,
V_362 , V_178 ) ;
}
if ( F_233 ( & V_11 -> V_388 ) ) {
F_48 ( L_267 ) ;
V_149 = - V_179 ;
goto V_393;
}
return 0 ;
V_393:
F_178 ( V_391 , V_11 -> V_165 ) ;
remove:
F_178 ( V_376 , V_11 -> V_177 -> V_390 ) ;
return V_149 ;
}
static void T_16 F_234 ( struct V_177 * V_177 )
{
struct V_10 * V_11 = F_4 ( V_177 , V_15 ) ;
struct V_147 * V_148 ;
struct V_336 * V_337 , * V_115 ;
F_235 ( V_339 ) ;
V_11 -> V_171 = true ;
F_49 ( & V_151 ) ;
F_236 ( & V_11 -> V_388 , & V_339 ) ;
F_51 ( & V_151 ) ;
F_173 (q, n, &list) {
V_148 = F_174 ( V_337 , struct V_147 , V_387 ) ;
F_221 ( & V_148 -> V_387 ) ;
F_224 ( V_148 -> V_340 ) ;
F_211 ( V_148 ) ;
}
F_178 ( V_391 , V_11 -> V_165 ) ;
F_178 ( V_376 , V_11 -> V_177 -> V_390 ) ;
}
static int T_17 F_237 ( void )
{
int V_149 = 0 ;
F_33 ( L_268 , V_4 ) ;
V_149 = F_238 ( & V_394 ) ;
if ( V_149 )
return V_149 ;
V_149 = F_239 ( & V_395 ) ;
if ( V_149 )
F_240 ( & V_394 ) ;
return V_149 ;
}
static void T_18 F_241 ( void )
{
F_242 ( & V_395 ) ;
F_240 ( & V_394 ) ;
}
