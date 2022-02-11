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
if ( ! F_4 ( V_11 ) ) {
V_9 = - V_12 ;
goto V_13;
}
if ( V_7 > sizeof( V_10 ) )
V_7 = sizeof( V_10 ) ;
if ( F_5 ( V_10 , V_6 , V_7 ) ) {
V_9 = - V_14 ;
goto V_13;
}
V_10 [ V_7 - 1 ] = 0 ;
if ( ! strcmp ( V_10 , L_1 ) )
F_6 () ;
else if ( ! strcmp ( V_10 , L_2 ) )
F_7 () ;
else if ( ! strcmp ( V_10 , L_3 ) )
F_8 () ;
else
F_9 ( L_4 , V_10 ) ;
V_9 = V_7 ;
V_13:
return V_9 ;
}
static int F_10 ( struct V_15 * V_15 , struct V_5 * V_5 )
{
return F_11 ( V_5 , F_1 , F_12 ( V_15 ) -> V_10 ) ;
}
static int F_13 ( struct V_1 * V_2 , void * V_3 )
{
const struct V_16 * V_17 = V_2 -> V_18 ;
T_5 V_19 ;
T_6 V_20 ;
F_14 ( V_2 ,
L_5 ,
( unsigned long long ) V_17 -> V_7 , V_17 -> V_21 ,
V_17 -> V_22 ) ;
F_14 ( V_2 ,
L_6 ,
V_17 -> V_23 , ( unsigned long long ) V_17 -> V_24 ,
V_17 -> V_25 , V_17 -> V_26 ) ;
F_14 ( V_2 , L_7 , V_17 -> V_27 ,
V_17 -> V_28 ) ;
F_14 ( V_2 ,
L_8 ,
V_17 -> V_29 ,
V_17 -> V_30 ) ;
if ( V_17 -> V_31 )
F_14 ( V_2 , L_9 ,
V_17 -> V_31 ) ;
if ( V_17 -> V_32 & V_33 ) {
F_14 ( V_2 ,
L_10
L_11 ,
& V_17 -> V_34 ,
& V_17 -> V_35 , & V_17 -> V_36 ,
& V_17 -> V_37 ,
& V_17 -> V_38 , & V_17 -> V_39 ) ;
} else {
F_14 ( V_2 ,
L_12 ,
V_17 -> V_40 , V_17 -> V_41 ) ;
F_14 ( V_2 ,
L_13 ,
V_17 -> V_42 , V_17 -> V_43 ) ;
}
F_2 ( V_2 , L_14 ) ;
F_14 ( V_2 , L_15 ,
F_15 ( V_17 -> V_44 ) ?
V_17 -> V_45 -> V_46 : V_17 -> V_44 ) ;
F_14 ( V_2 , L_16 ) ;
F_14 ( V_2 , L_17 , V_17 -> V_47 ) ;
F_14 ( V_2 ,
L_18
L_19 ,
V_17 -> V_48 , V_17 -> V_49 ,
V_17 -> V_50 , V_17 -> V_51 ) ;
F_14 ( V_2 ,
L_20 ,
V_17 -> V_52 , V_17 -> V_53 ) ;
if ( V_17 -> V_54 ) {
unsigned int V_55 ;
F_14 ( V_2 , L_21 ) ;
for ( V_55 = 0 ; V_55 < V_17 -> V_54 ; V_55 ++ )
F_14 ( V_2 , L_22 , F_16 ( V_17 -> V_56 [ V_55 ] ) ,
V_55 == V_17 -> V_54 - 1 ? L_23 : L_24 ) ;
}
if ( V_17 -> V_57 != 0xffff )
F_14 ( V_2 , L_25 ,
V_17 -> V_57 , V_17 -> V_58 ,
V_17 -> V_59 ) ;
if ( V_17 -> V_60 != 0xffff )
F_14 ( V_2 , L_26 ,
V_17 -> V_60 , V_17 -> V_61 ,
V_17 -> V_62 ) ;
if ( V_17 -> V_63 )
F_14 ( V_2 , L_27 , V_17 -> V_63 ) ;
if ( V_17 -> V_64 )
F_14 ( V_2 , L_28 , V_17 -> V_64 ) ;
if ( V_17 -> V_65 >= 0 )
F_14 ( V_2 , L_29 , V_17 -> V_65 ) ;
F_14 ( V_2 , L_30 ) ;
if ( V_17 -> V_32 & V_33 )
F_14 ( V_2 , L_31 ) ;
if ( V_17 -> V_32 & V_66 )
F_14 ( V_2 , L_32 ) ;
if ( V_17 -> V_32 & V_67 )
F_14 ( V_2 , L_33 ) ;
if ( V_17 -> V_32 & V_68 )
F_14 ( V_2 , L_34 ) ;
if ( V_17 -> V_32 & V_69 )
F_14 ( V_2 , L_35 ) ;
if ( V_17 -> V_32 & V_70 )
F_14 ( V_2 , L_36 ) ;
if ( V_17 -> V_32 & V_71 )
F_14 ( V_2 , L_37 ) ;
if ( V_17 -> V_32 & V_72 )
F_14 ( V_2 , L_38 ) ;
if ( V_17 -> V_32 & V_73 )
F_14 ( V_2 , L_39 ) ;
if ( V_17 -> V_27 ) {
if ( V_17 -> V_32 & V_74 )
F_14 ( V_2 , L_40 ) ;
else
F_14 ( V_2 , L_41 ) ;
}
#ifdef F_17
if ( V_17 -> V_32 & V_75 )
F_14 ( V_2 , L_42 ) ;
#endif
if ( V_17 -> V_32 & V_76 )
F_14 ( V_2 , L_43 ) ;
if ( V_17 -> V_32 & V_77 )
F_14 ( V_2 , L_44 ) ;
if ( V_17 -> V_32 & V_78 )
F_14 ( V_2 , L_45 ) ;
if ( V_17 -> V_32 & V_79 )
F_14 ( V_2 , L_46 ) ;
if ( V_17 -> V_32 & V_80 )
F_14 ( V_2 , L_47 ) ;
F_2 ( V_2 , L_23 ) ;
V_19 = V_17 -> V_81 ? F_18 () : V_17 -> V_82 ;
V_20 = V_17 -> V_83 ;
F_19 ( V_20 , V_84 ) ;
F_14 ( V_2 ,
L_48 ,
( unsigned long long ) V_17 -> V_85 ,
( unsigned long long ) V_17 -> V_86 ) ;
F_14 ( V_2 ,
L_49 ,
( unsigned long long ) F_20 ( V_17 -> V_87 ) ,
( unsigned long long ) F_20 ( V_19 ) ,
( unsigned long long ) V_20 ) ;
F_14 ( V_2 ,
L_50 ,
V_17 -> V_88 , V_17 -> V_89 ,
V_17 -> V_90 ) ;
if ( V_17 -> V_32 & V_33 ) {
F_14 ( V_2 , L_51 ,
& V_17 -> V_91 ,
& V_17 -> V_92 ) ;
} else
F_14 ( V_2 , L_52 ,
& V_17 -> V_93 , & V_17 -> V_94 ) ;
F_14 ( V_2 , L_53 ,
V_17 -> V_95 , V_17 -> V_96 ) ;
F_14 ( V_2 , L_54 , V_17 -> V_97 ) ;
F_14 ( V_2 , L_55 , V_17 -> V_98 ) ;
if ( V_17 -> V_99 [ 0 ] )
F_14 ( V_2 , L_56 , V_17 -> V_99 ) ;
else
F_14 ( V_2 , L_57 ) ;
return 0 ;
}
static int F_21 ( const char T_2 * V_100 , unsigned long V_101 ,
T_7 * V_102 )
{
int V_55 = 0 ;
* V_102 = 0 ;
for (; V_55 < V_101 ; V_55 ++ ) {
int V_103 ;
char V_104 ;
* V_102 <<= 4 ;
if ( F_22 ( V_104 , & V_100 [ V_55 ] ) )
return - V_14 ;
V_103 = F_23 ( V_104 ) ;
if ( V_103 >= 0 )
* V_102 |= V_103 ;
else
break;
}
return V_55 ;
}
static int F_24 ( const char T_2 * V_100 ,
unsigned int V_101 )
{
int V_55 ;
for ( V_55 = 0 ; V_55 < V_101 ; V_55 ++ ) {
char V_104 ;
if ( F_22 ( V_104 , & V_100 [ V_55 ] ) )
return - V_14 ;
switch ( V_104 ) {
case '\"' :
case '\n' :
case '\r' :
case '\t' :
case ' ' :
case '=' :
break;
default:
goto V_105;
}
}
V_105:
return V_55 ;
}
static long F_25 ( const char T_2 * V_100 , unsigned long V_101 ,
unsigned long * V_102 )
{
int V_55 ;
* V_102 = 0 ;
for ( V_55 = 0 ; V_55 < V_101 ; V_55 ++ ) {
char V_104 ;
if ( F_22 ( V_104 , & V_100 [ V_55 ] ) )
return - V_14 ;
if ( ( V_104 >= '0' ) && ( V_104 <= '9' ) ) {
* V_102 *= 10 ;
* V_102 += V_104 - '0' ;
} else
break;
}
return V_55 ;
}
static int F_26 ( const char T_2 * V_100 , unsigned int V_101 )
{
int V_55 ;
for ( V_55 = 0 ; V_55 < V_101 ; V_55 ++ ) {
char V_104 ;
if ( F_22 ( V_104 , & V_100 [ V_55 ] ) )
return - V_14 ;
switch ( V_104 ) {
case '\"' :
case '\n' :
case '\r' :
case '\t' :
case ' ' :
goto V_106;
break;
default:
break;
}
}
V_106:
return V_55 ;
}
static T_1 F_27 ( const char T_2 * V_107 , struct V_16 * V_17 )
{
unsigned int V_108 = 0 ;
char V_104 ;
T_1 V_55 = 0 ;
int V_109 ;
V_17 -> V_54 = 0 ;
do {
T_7 V_110 ;
V_109 = F_21 ( & V_107 [ V_55 ] , 8 , & V_110 ) ;
if ( V_109 <= 0 )
return V_109 ;
V_17 -> V_56 [ V_108 ] = F_28 ( V_110 ) ;
if ( V_17 -> V_56 [ V_108 ] & V_111 )
V_17 -> V_32 |= V_71 ;
V_55 += V_109 ;
if ( F_22 ( V_104 , & V_107 [ V_55 ] ) )
return - V_14 ;
V_55 ++ ;
V_108 ++ ;
if ( V_108 >= V_112 )
return - V_113 ;
} while ( V_104 == ',' );
V_17 -> V_54 = V_108 ;
return V_55 ;
}
static T_1 F_29 ( struct V_5 * V_5 ,
const char T_2 * V_100 , T_3 V_7 ,
T_4 * V_114 )
{
struct V_1 * V_2 = V_5 -> V_115 ;
struct V_16 * V_17 = V_2 -> V_18 ;
int V_55 , V_116 , V_109 ;
char V_117 [ 16 ] , V_118 [ 32 ] ;
unsigned long V_103 = 0 ;
char * V_119 = NULL ;
int V_110 = 0 ;
char V_6 [ 128 ] ;
V_119 = & ( V_17 -> V_99 [ 0 ] ) ;
if ( V_7 < 1 ) {
F_9 ( L_58 ) ;
return - V_120 ;
}
V_116 = V_7 ;
V_110 = F_24 ( V_100 , V_116 ) ;
if ( V_110 < 0 ) {
F_9 ( L_59 ) ;
return V_110 ;
}
V_55 = V_110 ;
V_109 = F_26 ( & V_100 [ V_55 ] , sizeof( V_117 ) - 1 ) ;
if ( V_109 < 0 )
return V_109 ;
memset ( V_117 , 0 , sizeof( V_117 ) ) ;
if ( F_5 ( V_117 , & V_100 [ V_55 ] , V_109 ) )
return - V_14 ;
V_55 += V_109 ;
V_116 = V_7 - V_55 ;
V_109 = F_24 ( & V_100 [ V_55 ] , V_116 ) ;
if ( V_109 < 0 )
return V_109 ;
V_55 += V_109 ;
if ( V_121 ) {
T_3 V_122 = F_30 ( T_3 , V_7 , 1023 ) ;
char V_123 [ V_122 + 1 ] ;
if ( F_5 ( V_123 , V_100 , V_122 ) )
return - V_14 ;
V_123 [ V_122 ] = 0 ;
F_31 ( L_60 ,
V_117 , ( unsigned long ) V_7 , V_123 ) ;
}
if ( ! strcmp ( V_117 , L_61 ) ) {
V_109 = F_25 ( & V_100 [ V_55 ] , 10 , & V_103 ) ;
if ( V_109 < 0 )
return V_109 ;
V_55 += V_109 ;
if ( V_103 < 14 + 20 + 8 )
V_103 = 14 + 20 + 8 ;
if ( V_103 != V_17 -> V_21 ) {
V_17 -> V_21 = V_103 ;
V_17 -> V_124 = V_103 ;
}
sprintf ( V_119 , L_62 ,
V_17 -> V_21 ) ;
return V_7 ;
}
if ( ! strcmp ( V_117 , L_63 ) ) {
V_109 = F_25 ( & V_100 [ V_55 ] , 10 , & V_103 ) ;
if ( V_109 < 0 )
return V_109 ;
V_55 += V_109 ;
if ( V_103 < 14 + 20 + 8 )
V_103 = 14 + 20 + 8 ;
if ( V_103 != V_17 -> V_22 ) {
V_17 -> V_22 = V_103 ;
V_17 -> V_124 = V_103 ;
}
sprintf ( V_119 , L_64 ,
V_17 -> V_22 ) ;
return V_7 ;
}
if ( ! strcmp ( V_117 , L_65 ) ) {
V_109 = F_25 ( & V_100 [ V_55 ] , 10 , & V_103 ) ;
if ( V_109 < 0 )
return V_109 ;
V_55 += V_109 ;
if ( V_103 < 14 + 20 + 8 )
V_103 = 14 + 20 + 8 ;
if ( V_103 != V_17 -> V_21 ) {
V_17 -> V_21 = V_103 ;
V_17 -> V_22 = V_103 ;
V_17 -> V_124 = V_103 ;
}
sprintf ( V_119 , L_66 , V_17 -> V_21 ) ;
return V_7 ;
}
if ( ! strcmp ( V_117 , L_67 ) ) {
V_109 = F_25 ( & V_100 [ V_55 ] , 10 , & V_103 ) ;
if ( V_109 < 0 )
return V_109 ;
V_55 += V_109 ;
V_121 = V_103 ;
sprintf ( V_119 , L_68 , V_121 ) ;
return V_7 ;
}
if ( ! strcmp ( V_117 , L_69 ) ) {
V_109 = F_25 ( & V_100 [ V_55 ] , 10 , & V_103 ) ;
if ( V_109 < 0 )
return V_109 ;
V_55 += V_109 ;
V_17 -> V_23 = V_103 ;
sprintf ( V_119 , L_70 , V_17 -> V_23 ) ;
return V_7 ;
}
if ( ! strcmp ( V_117 , L_71 ) ) {
V_109 = F_25 ( & V_100 [ V_55 ] , 10 , & V_103 ) ;
if ( V_109 < 0 )
return V_109 ;
V_55 += V_109 ;
if ( V_103 == 0x7FFFFFFF )
V_17 -> V_24 = V_125 ;
else
V_17 -> V_24 = ( T_6 ) V_103 ;
sprintf ( V_119 , L_72 ,
( unsigned long long ) V_17 -> V_24 ) ;
return V_7 ;
}
if ( ! strcmp ( V_117 , L_73 ) ) {
V_109 = F_25 ( & V_100 [ V_55 ] , 10 , & V_103 ) ;
if ( V_109 < 0 )
return V_109 ;
V_55 += V_109 ;
if ( ! V_103 )
return V_109 ;
V_17 -> V_24 = V_17 -> V_21 * 8 * V_84 / V_103 ;
if ( V_121 )
F_32 ( L_74 , V_17 -> V_24 ) ;
sprintf ( V_119 , L_75 , V_103 ) ;
return V_7 ;
}
if ( ! strcmp ( V_117 , L_76 ) ) {
V_109 = F_25 ( & V_100 [ V_55 ] , 10 , & V_103 ) ;
if ( V_109 < 0 )
return V_109 ;
V_55 += V_109 ;
if ( ! V_103 )
return V_109 ;
V_17 -> V_24 = V_126 / V_103 ;
if ( V_121 )
F_32 ( L_74 , V_17 -> V_24 ) ;
sprintf ( V_119 , L_75 , V_103 ) ;
return V_7 ;
}
if ( ! strcmp ( V_117 , L_77 ) ) {
V_109 = F_25 ( & V_100 [ V_55 ] , 10 , & V_103 ) ;
if ( V_109 < 0 )
return V_109 ;
V_55 += V_109 ;
if ( V_103 != V_17 -> V_48 ) {
V_17 -> V_48 = V_103 ;
V_17 -> V_96 = V_103 ;
}
sprintf ( V_119 , L_78 , V_17 -> V_48 ) ;
return V_7 ;
}
if ( ! strcmp ( V_117 , L_79 ) ) {
V_109 = F_25 ( & V_100 [ V_55 ] , 10 , & V_103 ) ;
if ( V_109 < 0 )
return V_109 ;
V_55 += V_109 ;
if ( V_103 != V_17 -> V_50 ) {
V_17 -> V_50 = V_103 ;
V_17 -> V_95 = V_103 ;
}
sprintf ( V_119 , L_80 , V_17 -> V_50 ) ;
return V_7 ;
}
if ( ! strcmp ( V_117 , L_81 ) ) {
V_109 = F_25 ( & V_100 [ V_55 ] , 10 , & V_103 ) ;
if ( V_109 < 0 )
return V_109 ;
V_55 += V_109 ;
if ( V_103 != V_17 -> V_49 ) {
V_17 -> V_49 = V_103 ;
V_17 -> V_96 = V_103 ;
}
sprintf ( V_119 , L_82 , V_17 -> V_49 ) ;
return V_7 ;
}
if ( ! strcmp ( V_117 , L_83 ) ) {
V_109 = F_25 ( & V_100 [ V_55 ] , 10 , & V_103 ) ;
if ( V_109 < 0 )
return V_109 ;
V_55 += V_109 ;
if ( V_103 != V_17 -> V_51 ) {
V_17 -> V_51 = V_103 ;
V_17 -> V_95 = V_103 ;
}
sprintf ( V_119 , L_84 , V_17 -> V_51 ) ;
return V_7 ;
}
if ( ! strcmp ( V_117 , L_85 ) ) {
V_109 = F_25 ( & V_100 [ V_55 ] , 10 , & V_103 ) ;
if ( V_109 < 0 )
return V_109 ;
if ( ( V_103 > 0 ) &&
( ! ( V_17 -> V_45 -> V_127 & V_128 ) ) )
return - V_129 ;
V_55 += V_109 ;
V_17 -> V_25 = V_103 ;
sprintf ( V_119 , L_86 , V_17 -> V_25 ) ;
return V_7 ;
}
if ( ! strcmp ( V_117 , L_87 ) ) {
V_109 = F_25 ( & V_100 [ V_55 ] , 10 , & V_103 ) ;
if ( V_109 < 0 )
return V_109 ;
V_55 += V_109 ;
V_17 -> V_7 = V_103 ;
sprintf ( V_119 , L_88 ,
( unsigned long long ) V_17 -> V_7 ) ;
return V_7 ;
}
if ( ! strcmp ( V_117 , L_89 ) ) {
V_109 = F_25 ( & V_100 [ V_55 ] , 10 , & V_103 ) ;
if ( V_109 < 0 )
return V_109 ;
V_55 += V_109 ;
if ( V_17 -> V_52 != V_103 ) {
V_17 -> V_52 = V_103 ;
V_17 -> V_90 = 0 ;
}
sprintf ( V_119 , L_90 ,
V_17 -> V_52 ) ;
return V_7 ;
}
if ( ! strcmp ( V_117 , L_91 ) ) {
V_109 = F_25 ( & V_100 [ V_55 ] , 10 , & V_103 ) ;
if ( V_109 < 0 )
return V_109 ;
V_55 += V_109 ;
if ( V_17 -> V_53 != V_103 ) {
V_17 -> V_53 = V_103 ;
V_17 -> V_89 = 0 ;
}
sprintf ( V_119 , L_92 ,
V_17 -> V_53 ) ;
return V_7 ;
}
if ( ! strcmp ( V_117 , L_93 ) ) {
V_109 = F_25 ( & V_100 [ V_55 ] , 10 , & V_103 ) ;
if ( V_109 < 0 )
return V_109 ;
V_55 += V_109 ;
if ( F_33 ( V_103 ) ) {
V_17 -> V_65 = V_103 ;
sprintf ( V_119 , L_94 , V_17 -> V_65 ) ;
if ( V_17 -> V_130 ) {
F_34 ( V_17 -> V_130 ) ;
V_17 -> V_130 = NULL ;
}
}
else
sprintf ( V_119 , L_95 ) ;
return V_7 ;
}
if ( ! strcmp ( V_117 , L_96 ) ) {
char V_131 [ 32 ] ;
memset ( V_131 , 0 , 32 ) ;
V_109 = F_26 ( & V_100 [ V_55 ] , sizeof( V_131 ) - 1 ) ;
if ( V_109 < 0 )
return V_109 ;
if ( F_5 ( V_131 , & V_100 [ V_55 ] , V_109 ) )
return - V_14 ;
V_55 += V_109 ;
if ( strcmp ( V_131 , L_97 ) == 0 )
V_17 -> V_32 |= V_66 ;
else if ( strcmp ( V_131 , L_98 ) == 0 )
V_17 -> V_32 &= ~ V_66 ;
else if ( strcmp ( V_131 , L_99 ) == 0 )
V_17 -> V_32 |= V_68 ;
else if ( strcmp ( V_131 , L_100 ) == 0 )
V_17 -> V_32 &= ~ V_68 ;
else if ( strcmp ( V_131 , L_101 ) == 0 )
V_17 -> V_32 |= V_67 ;
else if ( strcmp ( V_131 , L_102 ) == 0 )
V_17 -> V_32 &= ~ V_67 ;
else if ( strcmp ( V_131 , L_103 ) == 0 )
V_17 -> V_32 |= V_69 ;
else if ( strcmp ( V_131 , L_104 ) == 0 )
V_17 -> V_32 &= ~ V_69 ;
else if ( strcmp ( V_131 , L_105 ) == 0 )
V_17 -> V_32 |= V_70 ;
else if ( strcmp ( V_131 , L_106 ) == 0 )
V_17 -> V_32 &= ~ V_70 ;
else if ( strcmp ( V_131 , L_107 ) == 0 )
V_17 -> V_32 |= V_76 ;
else if ( strcmp ( V_131 , L_108 ) == 0 )
V_17 -> V_32 &= ~ V_76 ;
else if ( strcmp ( V_131 , L_109 ) == 0 )
V_17 -> V_32 |= V_77 ;
else if ( strcmp ( V_131 , L_110 ) == 0 )
V_17 -> V_32 &= ~ V_77 ;
else if ( strcmp ( V_131 , L_111 ) == 0 )
V_17 -> V_32 |= V_71 ;
else if ( strcmp ( V_131 , L_112 ) == 0 )
V_17 -> V_32 &= ~ V_71 ;
else if ( strcmp ( V_131 , L_113 ) == 0 )
V_17 -> V_32 |= V_78 ;
else if ( strcmp ( V_131 , L_114 ) == 0 )
V_17 -> V_32 &= ~ V_78 ;
else if ( strcmp ( V_131 , L_115 ) == 0 )
V_17 -> V_32 |= V_79 ;
else if ( strcmp ( V_131 , L_116 ) == 0 )
V_17 -> V_32 &= ~ V_79 ;
else if ( strcmp ( V_131 , L_117 ) == 0 )
V_17 -> V_32 |= V_74 ;
else if ( strcmp ( V_131 , L_118 ) == 0 )
V_17 -> V_32 |= V_72 ;
else if ( strcmp ( V_131 , L_119 ) == 0 )
V_17 -> V_32 &= ~ V_72 ;
else if ( strcmp ( V_131 , L_120 ) == 0 )
V_17 -> V_32 |= V_73 ;
else if ( strcmp ( V_131 , L_121 ) == 0 )
V_17 -> V_32 &= ~ V_73 ;
#ifdef F_17
else if ( strcmp ( V_131 , L_122 ) == 0 )
V_17 -> V_32 |= V_75 ;
#endif
else if ( strcmp ( V_131 , L_123 ) == 0 )
V_17 -> V_32 &= ~ V_33 ;
else if ( strcmp ( V_131 , L_124 ) == 0 )
V_17 -> V_32 |= V_80 ;
else if ( strcmp ( V_131 , L_125 ) == 0 )
V_17 -> V_32 &= ~ V_80 ;
else {
sprintf ( V_119 ,
L_126 ,
V_131 ,
L_127
L_128 ) ;
return V_7 ;
}
sprintf ( V_119 , L_129 , V_17 -> V_32 ) ;
return V_7 ;
}
if ( ! strcmp ( V_117 , L_130 ) || ! strcmp ( V_117 , L_131 ) ) {
V_109 = F_26 ( & V_100 [ V_55 ] , sizeof( V_17 -> V_40 ) - 1 ) ;
if ( V_109 < 0 )
return V_109 ;
if ( F_5 ( V_6 , & V_100 [ V_55 ] , V_109 ) )
return - V_14 ;
V_6 [ V_109 ] = 0 ;
if ( strcmp ( V_6 , V_17 -> V_40 ) != 0 ) {
memset ( V_17 -> V_40 , 0 , sizeof( V_17 -> V_40 ) ) ;
strncpy ( V_17 -> V_40 , V_6 , V_109 ) ;
V_17 -> V_132 = F_35 ( V_17 -> V_40 ) ;
V_17 -> V_94 = V_17 -> V_132 ;
}
if ( V_121 )
F_31 ( L_132 , V_17 -> V_40 ) ;
V_55 += V_109 ;
sprintf ( V_119 , L_133 , V_17 -> V_40 ) ;
return V_7 ;
}
if ( ! strcmp ( V_117 , L_134 ) ) {
V_109 = F_26 ( & V_100 [ V_55 ] , sizeof( V_17 -> V_41 ) - 1 ) ;
if ( V_109 < 0 )
return V_109 ;
if ( F_5 ( V_6 , & V_100 [ V_55 ] , V_109 ) )
return - V_14 ;
V_6 [ V_109 ] = 0 ;
if ( strcmp ( V_6 , V_17 -> V_41 ) != 0 ) {
memset ( V_17 -> V_41 , 0 , sizeof( V_17 -> V_41 ) ) ;
strncpy ( V_17 -> V_41 , V_6 , V_109 ) ;
V_17 -> V_133 = F_35 ( V_17 -> V_41 ) ;
V_17 -> V_94 = V_17 -> V_133 ;
}
if ( V_121 )
F_31 ( L_135 , V_17 -> V_41 ) ;
V_55 += V_109 ;
sprintf ( V_119 , L_136 , V_17 -> V_41 ) ;
return V_7 ;
}
if ( ! strcmp ( V_117 , L_137 ) ) {
V_109 = F_26 ( & V_100 [ V_55 ] , sizeof( V_6 ) - 1 ) ;
if ( V_109 < 0 )
return V_109 ;
V_17 -> V_32 |= V_33 ;
if ( F_5 ( V_6 , & V_100 [ V_55 ] , V_109 ) )
return - V_14 ;
V_6 [ V_109 ] = 0 ;
F_36 ( V_6 , - 1 , V_17 -> V_37 . V_134 , - 1 , NULL ) ;
snprintf ( V_6 , sizeof( V_6 ) , L_138 , & V_17 -> V_37 ) ;
V_17 -> V_92 = V_17 -> V_37 ;
if ( V_121 )
F_31 ( L_139 , V_6 ) ;
V_55 += V_109 ;
sprintf ( V_119 , L_140 , V_6 ) ;
return V_7 ;
}
if ( ! strcmp ( V_117 , L_141 ) ) {
V_109 = F_26 ( & V_100 [ V_55 ] , sizeof( V_6 ) - 1 ) ;
if ( V_109 < 0 )
return V_109 ;
V_17 -> V_32 |= V_33 ;
if ( F_5 ( V_6 , & V_100 [ V_55 ] , V_109 ) )
return - V_14 ;
V_6 [ V_109 ] = 0 ;
F_36 ( V_6 , - 1 , V_17 -> V_38 . V_134 , - 1 , NULL ) ;
snprintf ( V_6 , sizeof( V_6 ) , L_138 , & V_17 -> V_38 ) ;
V_17 -> V_92 = V_17 -> V_38 ;
if ( V_121 )
F_31 ( L_142 , V_6 ) ;
V_55 += V_109 ;
sprintf ( V_119 , L_143 , V_6 ) ;
return V_7 ;
}
if ( ! strcmp ( V_117 , L_144 ) ) {
V_109 = F_26 ( & V_100 [ V_55 ] , sizeof( V_6 ) - 1 ) ;
if ( V_109 < 0 )
return V_109 ;
V_17 -> V_32 |= V_33 ;
if ( F_5 ( V_6 , & V_100 [ V_55 ] , V_109 ) )
return - V_14 ;
V_6 [ V_109 ] = 0 ;
F_36 ( V_6 , - 1 , V_17 -> V_39 . V_134 , - 1 , NULL ) ;
snprintf ( V_6 , sizeof( V_6 ) , L_138 , & V_17 -> V_39 ) ;
if ( V_121 )
F_31 ( L_145 , V_6 ) ;
V_55 += V_109 ;
sprintf ( V_119 , L_146 , V_6 ) ;
return V_7 ;
}
if ( ! strcmp ( V_117 , L_147 ) ) {
V_109 = F_26 ( & V_100 [ V_55 ] , sizeof( V_6 ) - 1 ) ;
if ( V_109 < 0 )
return V_109 ;
V_17 -> V_32 |= V_33 ;
if ( F_5 ( V_6 , & V_100 [ V_55 ] , V_109 ) )
return - V_14 ;
V_6 [ V_109 ] = 0 ;
F_36 ( V_6 , - 1 , V_17 -> V_34 . V_134 , - 1 , NULL ) ;
snprintf ( V_6 , sizeof( V_6 ) , L_138 , & V_17 -> V_34 ) ;
V_17 -> V_91 = V_17 -> V_34 ;
if ( V_121 )
F_31 ( L_148 , V_6 ) ;
V_55 += V_109 ;
sprintf ( V_119 , L_149 , V_6 ) ;
return V_7 ;
}
if ( ! strcmp ( V_117 , L_150 ) ) {
V_109 = F_26 ( & V_100 [ V_55 ] , sizeof( V_17 -> V_42 ) - 1 ) ;
if ( V_109 < 0 )
return V_109 ;
if ( F_5 ( V_6 , & V_100 [ V_55 ] , V_109 ) )
return - V_14 ;
V_6 [ V_109 ] = 0 ;
if ( strcmp ( V_6 , V_17 -> V_42 ) != 0 ) {
memset ( V_17 -> V_42 , 0 , sizeof( V_17 -> V_42 ) ) ;
strncpy ( V_17 -> V_42 , V_6 , V_109 ) ;
V_17 -> V_135 = F_35 ( V_17 -> V_42 ) ;
V_17 -> V_93 = V_17 -> V_135 ;
}
if ( V_121 )
F_31 ( L_151 , V_17 -> V_42 ) ;
V_55 += V_109 ;
sprintf ( V_119 , L_152 , V_17 -> V_42 ) ;
return V_7 ;
}
if ( ! strcmp ( V_117 , L_153 ) ) {
V_109 = F_26 ( & V_100 [ V_55 ] , sizeof( V_17 -> V_43 ) - 1 ) ;
if ( V_109 < 0 )
return V_109 ;
if ( F_5 ( V_6 , & V_100 [ V_55 ] , V_109 ) )
return - V_14 ;
V_6 [ V_109 ] = 0 ;
if ( strcmp ( V_6 , V_17 -> V_43 ) != 0 ) {
memset ( V_17 -> V_43 , 0 , sizeof( V_17 -> V_43 ) ) ;
strncpy ( V_17 -> V_43 , V_6 , V_109 ) ;
V_17 -> V_136 = F_35 ( V_17 -> V_43 ) ;
V_17 -> V_93 = V_17 -> V_136 ;
}
if ( V_121 )
F_31 ( L_154 , V_17 -> V_43 ) ;
V_55 += V_109 ;
sprintf ( V_119 , L_155 , V_17 -> V_43 ) ;
return V_7 ;
}
if ( ! strcmp ( V_117 , L_156 ) ) {
V_109 = F_26 ( & V_100 [ V_55 ] , sizeof( V_118 ) - 1 ) ;
if ( V_109 < 0 )
return V_109 ;
memset ( V_118 , 0 , sizeof( V_118 ) ) ;
if ( F_5 ( V_118 , & V_100 [ V_55 ] , V_109 ) )
return - V_14 ;
if ( ! F_37 ( V_118 , V_17 -> V_47 ) )
return - V_120 ;
memcpy ( & V_17 -> V_137 [ 0 ] , V_17 -> V_47 , V_138 ) ;
sprintf ( V_119 , L_157 , V_17 -> V_47 ) ;
return V_7 ;
}
if ( ! strcmp ( V_117 , L_158 ) ) {
V_109 = F_26 ( & V_100 [ V_55 ] , sizeof( V_118 ) - 1 ) ;
if ( V_109 < 0 )
return V_109 ;
memset ( V_118 , 0 , sizeof( V_118 ) ) ;
if ( F_5 ( V_118 , & V_100 [ V_55 ] , V_109 ) )
return - V_14 ;
if ( ! F_37 ( V_118 , V_17 -> V_44 ) )
return - V_120 ;
memcpy ( & V_17 -> V_137 [ 6 ] , V_17 -> V_44 , V_138 ) ;
sprintf ( V_119 , L_159 , V_17 -> V_44 ) ;
return V_7 ;
}
if ( ! strcmp ( V_117 , L_160 ) ) {
F_38 ( V_17 ) ;
sprintf ( V_119 , L_161 ) ;
return V_7 ;
}
if ( ! strcmp ( V_117 , L_162 ) ) {
V_109 = F_25 ( & V_100 [ V_55 ] , 10 , & V_103 ) ;
if ( V_109 < 0 )
return V_109 ;
V_55 += V_109 ;
if ( V_103 > V_139 )
V_103 = V_139 ;
V_17 -> V_27 = V_103 ;
sprintf ( V_119 , L_163 , V_17 -> V_27 ) ;
return V_7 ;
}
if ( ! strcmp ( V_117 , L_164 ) ) {
V_109 = F_25 ( & V_100 [ V_55 ] , 10 , & V_103 ) ;
if ( V_109 < 0 )
return V_109 ;
V_55 += V_109 ;
V_17 -> V_28 = V_103 ;
sprintf ( V_119 , L_165 , V_17 -> V_28 ) ;
return V_7 ;
}
if ( ! strcmp ( V_117 , L_166 ) ) {
V_109 = F_25 ( & V_100 [ V_55 ] , 5 , & V_103 ) ;
if ( V_109 < 0 )
return V_109 ;
V_55 += V_109 ;
V_17 -> V_29 = V_103 ;
sprintf ( V_119 , L_167 , V_17 -> V_29 ) ;
return V_7 ;
}
if ( ! strcmp ( V_117 , L_168 ) ) {
V_109 = F_25 ( & V_100 [ V_55 ] , 5 , & V_103 ) ;
if ( V_109 < 0 )
return V_109 ;
V_55 += V_109 ;
V_17 -> V_30 = V_103 ;
sprintf ( V_119 , L_169 , V_17 -> V_30 ) ;
return V_7 ;
}
if ( ! strcmp ( V_117 , L_170 ) ) {
unsigned int V_108 , V_140 ;
V_109 = F_27 ( & V_100 [ V_55 ] , V_17 ) ;
if ( V_109 < 0 )
return V_109 ;
V_55 += V_109 ;
V_140 = sprintf ( V_119 , L_171 ) ;
for ( V_108 = 0 ; V_108 < V_17 -> V_54 ; V_108 ++ )
V_140 += sprintf ( V_119 + V_140 ,
L_22 , F_16 ( V_17 -> V_56 [ V_108 ] ) ,
V_108 == V_17 -> V_54 - 1 ? L_172 : L_173 ) ;
if ( V_17 -> V_54 && V_17 -> V_57 != 0xffff ) {
V_17 -> V_57 = 0xffff ;
V_17 -> V_60 = 0xffff ;
if ( V_121 )
F_31 ( L_174 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_117 , L_175 ) ) {
V_109 = F_25 ( & V_100 [ V_55 ] , 4 , & V_103 ) ;
if ( V_109 < 0 )
return V_109 ;
V_55 += V_109 ;
if ( V_103 <= 4095 ) {
V_17 -> V_57 = V_103 ;
if ( V_121 )
F_31 ( L_176 ) ;
if ( V_121 && V_17 -> V_54 )
F_31 ( L_177 ) ;
V_17 -> V_54 = 0 ;
sprintf ( V_119 , L_178 , V_17 -> V_57 ) ;
} else {
V_17 -> V_57 = 0xffff ;
V_17 -> V_60 = 0xffff ;
if ( V_121 )
F_31 ( L_179 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_117 , L_180 ) ) {
V_109 = F_25 ( & V_100 [ V_55 ] , 1 , & V_103 ) ;
if ( V_109 < 0 )
return V_109 ;
V_55 += V_109 ;
if ( ( V_103 <= 7 ) && ( V_17 -> V_57 != 0xffff ) ) {
V_17 -> V_58 = V_103 ;
sprintf ( V_119 , L_181 , V_17 -> V_58 ) ;
} else {
sprintf ( V_119 , L_182 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_117 , L_183 ) ) {
V_109 = F_25 ( & V_100 [ V_55 ] , 1 , & V_103 ) ;
if ( V_109 < 0 )
return V_109 ;
V_55 += V_109 ;
if ( ( V_103 <= 1 ) && ( V_17 -> V_57 != 0xffff ) ) {
V_17 -> V_59 = V_103 ;
sprintf ( V_119 , L_184 , V_17 -> V_59 ) ;
} else {
sprintf ( V_119 , L_185 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_117 , L_186 ) ) {
V_109 = F_25 ( & V_100 [ V_55 ] , 4 , & V_103 ) ;
if ( V_109 < 0 )
return V_109 ;
V_55 += V_109 ;
if ( ( V_103 <= 4095 ) && ( ( V_17 -> V_57 != 0xffff ) ) ) {
V_17 -> V_60 = V_103 ;
if ( V_121 )
F_31 ( L_187 ) ;
if ( V_121 && V_17 -> V_54 )
F_31 ( L_177 ) ;
V_17 -> V_54 = 0 ;
sprintf ( V_119 , L_188 , V_17 -> V_60 ) ;
} else {
V_17 -> V_57 = 0xffff ;
V_17 -> V_60 = 0xffff ;
if ( V_121 )
F_31 ( L_179 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_117 , L_189 ) ) {
V_109 = F_25 ( & V_100 [ V_55 ] , 1 , & V_103 ) ;
if ( V_109 < 0 )
return V_109 ;
V_55 += V_109 ;
if ( ( V_103 <= 7 ) && ( V_17 -> V_60 != 0xffff ) ) {
V_17 -> V_61 = V_103 ;
sprintf ( V_119 , L_190 , V_17 -> V_61 ) ;
} else {
sprintf ( V_119 , L_191 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_117 , L_192 ) ) {
V_109 = F_25 ( & V_100 [ V_55 ] , 1 , & V_103 ) ;
if ( V_109 < 0 )
return V_109 ;
V_55 += V_109 ;
if ( ( V_103 <= 1 ) && ( V_17 -> V_60 != 0xffff ) ) {
V_17 -> V_62 = V_103 ;
sprintf ( V_119 , L_193 , V_17 -> V_62 ) ;
} else {
sprintf ( V_119 , L_194 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_117 , L_195 ) ) {
T_7 V_141 = 0 ;
V_109 = F_21 ( & V_100 [ V_55 ] , 2 , & V_141 ) ;
if ( V_109 < 0 )
return V_109 ;
V_55 += V_109 ;
if ( V_109 == 2 ) {
V_17 -> V_63 = V_141 ;
sprintf ( V_119 , L_196 , V_17 -> V_63 ) ;
} else {
sprintf ( V_119 , L_197 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_117 , L_198 ) ) {
T_7 V_141 = 0 ;
V_109 = F_21 ( & V_100 [ V_55 ] , 2 , & V_141 ) ;
if ( V_109 < 0 )
return V_109 ;
V_55 += V_109 ;
if ( V_109 == 2 ) {
V_17 -> V_64 = V_141 ;
sprintf ( V_119 , L_199 , V_17 -> V_64 ) ;
} else {
sprintf ( V_119 , L_200 ) ;
}
return V_7 ;
}
if ( ! strcmp ( V_117 , L_201 ) ) {
V_109 = F_25 ( & V_100 [ V_55 ] , 9 , & V_103 ) ;
if ( V_109 < 0 )
return V_109 ;
V_55 += V_109 ;
V_17 -> V_31 = V_103 ;
sprintf ( V_119 , L_202 ,
V_17 -> V_31 ) ;
return V_7 ;
}
sprintf ( V_17 -> V_99 , L_203 , V_117 ) ;
return - V_120 ;
}
static int F_39 ( struct V_15 * V_15 , struct V_5 * V_5 )
{
return F_11 ( V_5 , F_13 , F_12 ( V_15 ) -> V_10 ) ;
}
static int F_40 ( struct V_1 * V_2 , void * V_3 )
{
struct V_142 * V_143 = V_2 -> V_18 ;
const struct V_16 * V_17 ;
F_41 ( ! V_143 ) ;
F_14 ( V_2 , L_204 ) ;
F_42 ( V_143 ) ;
F_43 (pkt_dev, &t->if_list, list)
if ( V_17 -> V_81 )
F_14 ( V_2 , L_205 , V_17 -> V_26 ) ;
F_14 ( V_2 , L_206 ) ;
F_43 (pkt_dev, &t->if_list, list)
if ( ! V_17 -> V_81 )
F_14 ( V_2 , L_205 , V_17 -> V_26 ) ;
if ( V_143 -> V_99 [ 0 ] )
F_14 ( V_2 , L_207 , V_143 -> V_99 ) ;
else
F_14 ( V_2 , L_208 ) ;
F_44 ( V_143 ) ;
return 0 ;
}
static T_1 F_45 ( struct V_5 * V_5 ,
const char T_2 * V_100 ,
T_3 V_7 , T_4 * V_114 )
{
struct V_1 * V_2 = V_5 -> V_115 ;
struct V_142 * V_143 = V_2 -> V_18 ;
int V_55 , V_116 , V_109 , V_144 ;
char V_117 [ 40 ] ;
char * V_119 ;
if ( V_7 < 1 ) {
return - V_120 ;
}
V_116 = V_7 ;
V_109 = F_24 ( V_100 , V_116 ) ;
if ( V_109 < 0 )
return V_109 ;
V_55 = V_109 ;
V_109 = F_26 ( & V_100 [ V_55 ] , sizeof( V_117 ) - 1 ) ;
if ( V_109 < 0 )
return V_109 ;
memset ( V_117 , 0 , sizeof( V_117 ) ) ;
if ( F_5 ( V_117 , & V_100 [ V_55 ] , V_109 ) )
return - V_14 ;
V_55 += V_109 ;
V_116 = V_7 - V_55 ;
V_109 = F_24 ( & V_100 [ V_55 ] , V_116 ) ;
if ( V_109 < 0 )
return V_109 ;
V_55 += V_109 ;
if ( V_121 )
F_31 ( L_209 , V_117 , ( unsigned long ) V_7 ) ;
if ( ! V_143 ) {
F_46 ( L_210 ) ;
V_144 = - V_120 ;
goto V_13;
}
V_119 = & ( V_143 -> V_99 [ 0 ] ) ;
if ( ! strcmp ( V_117 , L_211 ) ) {
char V_131 [ 32 ] ;
memset ( V_131 , 0 , 32 ) ;
V_109 = F_26 ( & V_100 [ V_55 ] , sizeof( V_131 ) - 1 ) ;
if ( V_109 < 0 ) {
V_144 = V_109 ;
goto V_13;
}
if ( F_5 ( V_131 , & V_100 [ V_55 ] , V_109 ) )
return - V_14 ;
V_55 += V_109 ;
F_47 ( & V_145 ) ;
V_144 = F_48 ( V_143 , V_131 ) ;
F_49 ( & V_145 ) ;
if ( ! V_144 ) {
V_144 = V_7 ;
sprintf ( V_119 , L_212 , V_131 ) ;
} else
sprintf ( V_119 , L_213 , V_131 ) ;
goto V_13;
}
if ( ! strcmp ( V_117 , L_214 ) ) {
F_47 ( & V_145 ) ;
V_143 -> V_146 |= V_147 ;
F_49 ( & V_145 ) ;
F_50 ( F_51 ( 125 ) ) ;
V_144 = V_7 ;
sprintf ( V_119 , L_215 ) ;
goto V_13;
}
if ( ! strcmp ( V_117 , L_216 ) ) {
sprintf ( V_119 , L_217 ) ;
V_144 = V_7 ;
goto V_13;
}
V_144 = - V_120 ;
V_13:
return V_144 ;
}
static int F_52 ( struct V_15 * V_15 , struct V_5 * V_5 )
{
return F_11 ( V_5 , F_40 , F_12 ( V_15 ) -> V_10 ) ;
}
static struct V_16 * F_53 ( const char * V_148 , int remove )
{
struct V_142 * V_143 ;
struct V_16 * V_17 = NULL ;
bool V_149 = ( remove == V_150 ) ;
F_43 (t, &pktgen_threads, th_list) {
V_17 = F_54 ( V_143 , V_148 , V_149 ) ;
if ( V_17 ) {
if ( remove ) {
F_42 ( V_143 ) ;
V_17 -> V_151 = 1 ;
V_143 -> V_146 |= V_152 ;
F_44 ( V_143 ) ;
}
break;
}
}
return V_17 ;
}
static void F_55 ( const char * V_148 )
{
struct V_16 * V_17 = NULL ;
const int V_153 = 10 , V_154 = 125 ;
int V_55 = 0 ;
F_47 ( & V_145 ) ;
F_31 ( L_218 , V_155 , V_148 ) ;
while ( 1 ) {
V_17 = F_53 ( V_148 , REMOVE ) ;
if ( V_17 == NULL )
break;
F_49 ( & V_145 ) ;
F_31 ( L_219 ,
V_155 , V_148 ) ;
F_50 ( F_51 ( V_154 ) ) ;
F_47 ( & V_145 ) ;
if ( ++ V_55 >= V_153 ) {
F_46 ( L_220 ,
V_155 , V_154 * V_55 , V_148 ) ;
break;
}
}
F_49 ( & V_145 ) ;
}
static void F_56 ( struct V_156 * V_157 )
{
struct V_142 * V_143 ;
F_43 (t, &pktgen_threads, th_list) {
struct V_16 * V_17 ;
F_43 (pkt_dev, &t->if_list, list) {
if ( V_17 -> V_45 != V_157 )
continue;
F_57 ( V_17 -> V_158 -> V_117 , V_159 ) ;
V_17 -> V_158 = F_58 ( V_157 -> V_117 , 0600 ,
V_159 ,
& V_160 ,
V_17 ) ;
if ( ! V_17 -> V_158 )
F_46 ( L_221 ,
V_157 -> V_117 ) ;
break;
}
}
}
static int F_59 ( struct V_161 * V_162 ,
unsigned long V_163 , void * V_164 )
{
struct V_156 * V_157 = V_164 ;
if ( ! F_60 ( F_61 ( V_157 ) , & V_165 ) || V_166 )
return V_167 ;
switch ( V_163 ) {
case V_168 :
F_56 ( V_157 ) ;
break;
case V_169 :
F_55 ( V_157 -> V_117 ) ;
break;
}
return V_167 ;
}
static struct V_156 * F_62 ( struct V_16 * V_17 ,
const char * V_148 )
{
char V_170 [ V_171 + 5 ] ;
int V_55 ;
for ( V_55 = 0 ; V_148 [ V_55 ] != '@' ; V_55 ++ ) {
if ( V_55 == V_171 )
break;
V_170 [ V_55 ] = V_148 [ V_55 ] ;
}
V_170 [ V_55 ] = 0 ;
return F_63 ( & V_165 , V_170 ) ;
}
static int F_64 ( struct V_16 * V_17 , const char * V_148 )
{
struct V_156 * V_45 ;
int V_9 ;
if ( V_17 -> V_45 ) {
F_65 ( V_17 -> V_45 ) ;
V_17 -> V_45 = NULL ;
}
V_45 = F_62 ( V_17 , V_148 ) ;
if ( ! V_45 ) {
F_46 ( L_222 , V_148 ) ;
return - V_172 ;
}
if ( V_45 -> type != V_173 ) {
F_46 ( L_223 , V_148 ) ;
V_9 = - V_120 ;
} else if ( ! F_66 ( V_45 ) ) {
F_46 ( L_224 , V_148 ) ;
V_9 = - V_174 ;
} else {
V_17 -> V_45 = V_45 ;
return 0 ;
}
F_65 ( V_45 ) ;
return V_9 ;
}
static void F_67 ( struct V_16 * V_17 )
{
int V_175 ;
if ( ! V_17 -> V_45 ) {
F_46 ( L_225 ) ;
sprintf ( V_17 -> V_99 ,
L_226 ) ;
return;
}
V_175 = V_17 -> V_45 -> V_176 ;
if ( V_175 <= V_17 -> V_29 ) {
F_9 ( L_227 ,
V_17 -> V_29 , ( V_175 ? : 1 ) - 1 , V_175 ,
V_17 -> V_26 ) ;
V_17 -> V_29 = ( V_175 ? : 1 ) - 1 ;
}
if ( V_17 -> V_30 >= V_175 ) {
F_9 ( L_228 ,
V_17 -> V_30 , ( V_175 ? : 1 ) - 1 , V_175 ,
V_17 -> V_26 ) ;
V_17 -> V_30 = ( V_175 ? : 1 ) - 1 ;
}
if ( F_15 ( V_17 -> V_44 ) )
memcpy ( & ( V_17 -> V_137 [ 6 ] ) , V_17 -> V_45 -> V_46 , V_138 ) ;
memcpy ( & ( V_17 -> V_137 [ 0 ] ) , V_17 -> V_47 , V_138 ) ;
if ( V_17 -> V_32 & V_33 ) {
int V_55 , V_177 = 0 , V_9 = 1 ;
struct V_178 * V_179 ;
if ( V_17 -> V_21 == 0 ) {
V_17 -> V_21 = 14 + sizeof( struct V_180 )
+ sizeof( struct V_181 )
+ sizeof( struct V_182 )
+ V_17 -> V_183 ;
}
for ( V_55 = 0 ; V_55 < V_184 ; V_55 ++ )
if ( V_17 -> V_91 . V_134 [ V_55 ] ) {
V_177 = 1 ;
break;
}
if ( ! V_177 ) {
F_68 () ;
V_179 = F_69 ( V_17 -> V_45 ) ;
if ( V_179 ) {
struct V_185 * V_186 ;
F_70 ( & V_179 -> V_187 ) ;
F_43 (ifp, &idev->addr_list, if_list) {
if ( ( V_186 -> V_188 & V_189 ) &&
! ( V_186 -> V_32 & V_190 ) ) {
V_17 -> V_91 = V_186 -> V_191 ;
V_9 = 0 ;
break;
}
}
F_71 ( & V_179 -> V_187 ) ;
}
F_72 () ;
if ( V_9 )
F_46 ( L_229 ) ;
}
} else {
if ( V_17 -> V_21 == 0 ) {
V_17 -> V_21 = 14 + sizeof( struct V_192 )
+ sizeof( struct V_181 )
+ sizeof( struct V_182 )
+ V_17 -> V_183 ;
}
V_17 -> V_135 = 0 ;
V_17 -> V_136 = 0 ;
if ( strlen ( V_17 -> V_42 ) == 0 ) {
struct V_193 * V_194 ;
F_68 () ;
V_194 = F_73 ( V_17 -> V_45 ) ;
if ( V_194 ) {
if ( V_194 -> V_195 ) {
V_17 -> V_135 =
V_194 -> V_195 -> V_196 ;
V_17 -> V_136 = V_17 -> V_135 ;
}
}
F_72 () ;
} else {
V_17 -> V_135 = F_35 ( V_17 -> V_42 ) ;
V_17 -> V_136 = F_35 ( V_17 -> V_43 ) ;
}
V_17 -> V_132 = F_35 ( V_17 -> V_40 ) ;
V_17 -> V_133 = F_35 ( V_17 -> V_41 ) ;
}
V_17 -> V_124 = V_17 -> V_21 ;
if ( V_17 -> V_21 > V_17 -> V_22 )
V_17 -> V_22 = V_17 -> V_21 ;
V_17 -> V_89 = 0 ;
V_17 -> V_90 = 0 ;
V_17 -> V_93 = V_17 -> V_135 ;
V_17 -> V_94 = V_17 -> V_132 ;
V_17 -> V_95 = V_17 -> V_50 ;
V_17 -> V_96 = V_17 -> V_48 ;
V_17 -> V_98 = 0 ;
}
static void F_74 ( struct V_16 * V_17 , T_5 V_197 )
{
T_5 V_198 , V_199 ;
T_8 V_200 ;
struct V_201 V_143 ;
F_75 ( & V_143 . V_202 , V_203 , V_204 ) ;
F_76 ( & V_143 . V_202 , V_197 ) ;
V_200 = F_77 ( F_78 ( & V_143 . V_202 ) ) ;
if ( V_200 <= 0 ) {
V_17 -> V_205 = F_79 ( V_197 , V_17 -> V_24 ) ;
return;
}
V_198 = F_18 () ;
if ( V_200 < 100000 ) {
do {
V_199 = F_18 () ;
} while ( F_80 ( V_199 , V_197 ) < 0 );
} else {
F_81 ( & V_143 , V_206 ) ;
do {
F_82 ( V_207 ) ;
F_83 ( & V_143 . V_202 , V_204 ) ;
if ( ! F_84 ( & V_143 . V_202 ) )
V_143 . V_208 = NULL ;
if ( F_85 ( V_143 . V_208 ) )
F_86 () ;
F_87 ( & V_143 . V_202 ) ;
} while ( V_143 . V_208 && V_17 -> V_81 && ! F_88 ( V_206 ) );
F_89 ( V_209 ) ;
V_199 = F_18 () ;
}
V_17 -> V_83 += F_77 ( F_90 ( V_199 , V_198 ) ) ;
V_17 -> V_205 = F_79 ( V_197 , V_17 -> V_24 ) ;
}
static inline void F_91 ( struct V_16 * V_17 )
{
V_17 -> V_183 = 0 ;
V_17 -> V_183 += V_17 -> V_54 * sizeof( V_210 ) ;
V_17 -> V_183 += F_92 ( V_17 ) ;
V_17 -> V_183 += F_93 ( V_17 ) ;
}
static inline int F_94 ( const struct V_16 * V_17 , int V_211 )
{
return ! ! ( V_17 -> V_212 [ V_211 ] . V_32 & V_213 ) ;
}
static inline int F_95 ( struct V_16 * V_17 )
{
int V_211 = V_17 -> V_214 ;
if ( V_17 -> V_32 & V_74 ) {
if ( V_17 -> V_212 [ V_211 ] . V_7 >= V_17 -> V_28 ) {
V_17 -> V_212 [ V_211 ] . V_7 = 0 ;
V_17 -> V_212 [ V_211 ] . V_32 = 0 ;
V_17 -> V_214 += 1 ;
if ( V_17 -> V_214 >= V_17 -> V_27 )
V_17 -> V_214 = 0 ;
}
} else {
V_211 = F_96 () % V_17 -> V_27 ;
V_17 -> V_214 = V_211 ;
if ( V_17 -> V_212 [ V_211 ] . V_7 > V_17 -> V_28 ) {
V_17 -> V_212 [ V_211 ] . V_7 = 0 ;
V_17 -> V_212 [ V_211 ] . V_32 = 0 ;
}
}
return V_17 -> V_214 ;
}
static void F_97 ( struct V_16 * V_17 , int V_211 )
{
struct V_215 * V_216 = V_17 -> V_212 [ V_211 ] . V_216 ;
if ( ! V_216 ) {
V_216 = F_98 ( & V_165 , V_217 ,
( V_218 * ) & V_17 -> V_94 ,
( V_218 * ) & V_17 -> V_93 ,
V_219 ,
V_17 -> V_220 ,
V_17 -> V_221 , 0 ) ;
if ( V_216 ) {
V_17 -> V_212 [ V_211 ] . V_216 = V_216 ;
F_91 ( V_17 ) ;
V_17 -> V_183 += V_216 -> V_222 . V_223 ;
}
}
}
static void F_99 ( struct V_16 * V_17 )
{
if ( V_17 -> V_32 & V_73 )
V_17 -> V_97 = F_100 () ;
else if ( V_17 -> V_29 <= V_17 -> V_30 ) {
T_9 V_143 ;
if ( V_17 -> V_32 & V_72 ) {
V_143 = F_96 () %
( V_17 -> V_30 -
V_17 -> V_29 + 1 )
+ V_17 -> V_29 ;
} else {
V_143 = V_17 -> V_97 + 1 ;
if ( V_143 > V_17 -> V_30 )
V_143 = V_17 -> V_29 ;
}
V_17 -> V_97 = V_143 ;
}
V_17 -> V_97 = V_17 -> V_97 % V_17 -> V_45 -> V_176 ;
}
static void F_101 ( struct V_16 * V_17 )
{
T_7 V_224 ;
T_7 V_225 ;
int V_211 = 0 ;
if ( V_17 -> V_27 )
V_211 = F_95 ( V_17 ) ;
if ( V_17 -> V_52 > 1 ) {
T_7 V_226 ;
T_7 V_110 ;
if ( V_17 -> V_32 & V_76 )
V_226 = F_96 () % V_17 -> V_52 ;
else {
V_226 = V_17 -> V_90 ++ ;
if ( V_17 -> V_90 >=
V_17 -> V_52 )
V_17 -> V_90 = 0 ;
}
V_110 = V_17 -> V_44 [ 5 ] + ( V_226 & 0xFF ) ;
V_17 -> V_137 [ 11 ] = V_110 ;
V_110 = ( V_17 -> V_44 [ 4 ] + ( ( V_226 >> 8 ) & 0xFF ) + ( V_110 >> 8 ) ) ;
V_17 -> V_137 [ 10 ] = V_110 ;
V_110 = ( V_17 -> V_44 [ 3 ] + ( ( V_226 >> 16 ) & 0xFF ) + ( V_110 >> 8 ) ) ;
V_17 -> V_137 [ 9 ] = V_110 ;
V_110 = ( V_17 -> V_44 [ 2 ] + ( ( V_226 >> 24 ) & 0xFF ) + ( V_110 >> 8 ) ) ;
V_17 -> V_137 [ 8 ] = V_110 ;
V_110 = ( V_17 -> V_44 [ 1 ] + ( V_110 >> 8 ) ) ;
V_17 -> V_137 [ 7 ] = V_110 ;
}
if ( V_17 -> V_53 > 1 ) {
T_7 V_226 ;
T_7 V_110 ;
if ( V_17 -> V_32 & V_77 )
V_226 = F_96 () % V_17 -> V_53 ;
else {
V_226 = V_17 -> V_89 ++ ;
if ( V_17 -> V_89 >=
V_17 -> V_53 ) {
V_17 -> V_89 = 0 ;
}
}
V_110 = V_17 -> V_47 [ 5 ] + ( V_226 & 0xFF ) ;
V_17 -> V_137 [ 5 ] = V_110 ;
V_110 = ( V_17 -> V_47 [ 4 ] + ( ( V_226 >> 8 ) & 0xFF ) + ( V_110 >> 8 ) ) ;
V_17 -> V_137 [ 4 ] = V_110 ;
V_110 = ( V_17 -> V_47 [ 3 ] + ( ( V_226 >> 16 ) & 0xFF ) + ( V_110 >> 8 ) ) ;
V_17 -> V_137 [ 3 ] = V_110 ;
V_110 = ( V_17 -> V_47 [ 2 ] + ( ( V_226 >> 24 ) & 0xFF ) + ( V_110 >> 8 ) ) ;
V_17 -> V_137 [ 2 ] = V_110 ;
V_110 = ( V_17 -> V_47 [ 1 ] + ( V_110 >> 8 ) ) ;
V_17 -> V_137 [ 1 ] = V_110 ;
}
if ( V_17 -> V_32 & V_71 ) {
unsigned int V_55 ;
for ( V_55 = 0 ; V_55 < V_17 -> V_54 ; V_55 ++ )
if ( V_17 -> V_56 [ V_55 ] & V_111 )
V_17 -> V_56 [ V_55 ] = V_111 |
( ( V_227 V_228 ) F_96 () &
F_28 ( 0x000fffff ) ) ;
}
if ( ( V_17 -> V_32 & V_78 ) && ( V_17 -> V_57 != 0xffff ) ) {
V_17 -> V_57 = F_96 () & ( 4096 - 1 ) ;
}
if ( ( V_17 -> V_32 & V_79 ) && ( V_17 -> V_60 != 0xffff ) ) {
V_17 -> V_60 = F_96 () & ( 4096 - 1 ) ;
}
if ( V_17 -> V_48 < V_17 -> V_49 ) {
if ( V_17 -> V_32 & V_69 )
V_17 -> V_96 = F_96 () %
( V_17 -> V_49 - V_17 -> V_48 )
+ V_17 -> V_48 ;
else {
V_17 -> V_96 ++ ;
if ( V_17 -> V_96 >= V_17 -> V_49 )
V_17 -> V_96 = V_17 -> V_48 ;
}
}
if ( V_17 -> V_50 < V_17 -> V_51 ) {
if ( V_17 -> V_32 & V_70 ) {
V_17 -> V_95 = F_96 () %
( V_17 -> V_51 - V_17 -> V_50 )
+ V_17 -> V_50 ;
} else {
V_17 -> V_95 ++ ;
if ( V_17 -> V_95 >= V_17 -> V_51 )
V_17 -> V_95 = V_17 -> V_50 ;
}
}
if ( ! ( V_17 -> V_32 & V_33 ) ) {
V_224 = F_16 ( V_17 -> V_135 ) ;
V_225 = F_16 ( V_17 -> V_136 ) ;
if ( V_224 < V_225 ) {
T_7 V_143 ;
if ( V_17 -> V_32 & V_66 )
V_143 = F_96 () % ( V_225 - V_224 ) + V_224 ;
else {
V_143 = F_16 ( V_17 -> V_93 ) ;
V_143 ++ ;
if ( V_143 > V_225 )
V_143 = V_224 ;
}
V_17 -> V_93 = F_28 ( V_143 ) ;
}
if ( V_17 -> V_27 && F_94 ( V_17 , V_211 ) ) {
V_17 -> V_94 = V_17 -> V_212 [ V_211 ] . V_94 ;
} else {
V_224 = F_16 ( V_17 -> V_132 ) ;
V_225 = F_16 ( V_17 -> V_133 ) ;
if ( V_224 < V_225 ) {
T_7 V_143 ;
V_228 V_229 ;
if ( V_17 -> V_32 & V_67 ) {
V_143 = F_96 () % ( V_225 - V_224 ) + V_224 ;
V_229 = F_28 ( V_143 ) ;
while ( F_102 ( V_229 ) ||
F_103 ( V_229 ) ||
F_104 ( V_229 ) ||
F_105 ( V_229 ) ||
F_106 ( V_229 ) ) {
V_143 = F_96 () % ( V_225 - V_224 ) + V_224 ;
V_229 = F_28 ( V_143 ) ;
}
V_17 -> V_94 = V_229 ;
} else {
V_143 = F_16 ( V_17 -> V_94 ) ;
V_143 ++ ;
if ( V_143 > V_225 ) {
V_143 = V_224 ;
}
V_17 -> V_94 = F_28 ( V_143 ) ;
}
}
if ( V_17 -> V_27 ) {
V_17 -> V_212 [ V_211 ] . V_32 |= V_213 ;
V_17 -> V_212 [ V_211 ] . V_94 =
V_17 -> V_94 ;
#ifdef F_17
if ( V_17 -> V_32 & V_75 )
F_97 ( V_17 , V_211 ) ;
#endif
V_17 -> V_98 ++ ;
}
}
} else {
if ( ! F_107 ( & V_17 -> V_38 ) ) {
int V_55 ;
for ( V_55 = 0 ; V_55 < 4 ; V_55 ++ ) {
V_17 -> V_92 . V_230 [ V_55 ] =
( ( ( V_227 V_228 ) F_96 () |
V_17 -> V_38 . V_230 [ V_55 ] ) &
V_17 -> V_39 . V_230 [ V_55 ] ) ;
}
}
}
if ( V_17 -> V_21 < V_17 -> V_22 ) {
T_7 V_143 ;
if ( V_17 -> V_32 & V_68 ) {
V_143 = F_96 () %
( V_17 -> V_22 - V_17 -> V_21 )
+ V_17 -> V_21 ;
} else {
V_143 = V_17 -> V_124 + 1 ;
if ( V_143 > V_17 -> V_22 )
V_143 = V_17 -> V_21 ;
}
V_17 -> V_124 = V_143 ;
}
F_99 ( V_17 ) ;
V_17 -> V_212 [ V_211 ] . V_7 ++ ;
}
static int F_108 ( struct V_231 * V_232 , struct V_16 * V_17 )
{
struct V_215 * V_216 = V_17 -> V_212 [ V_17 -> V_214 ] . V_216 ;
int V_9 = 0 ;
if ( ! V_216 )
return 0 ;
if ( V_216 -> V_222 . V_233 != V_234 )
return 0 ;
F_109 ( & V_216 -> V_187 ) ;
V_9 = V_216 -> V_235 -> V_236 ( V_216 , V_232 ) ;
if ( V_9 )
goto error;
V_9 = V_216 -> type -> V_236 ( V_216 , V_232 ) ;
if ( V_9 )
goto error;
V_216 -> V_237 . V_238 += V_232 -> V_109 ;
V_216 -> V_237 . V_239 ++ ;
error:
F_110 ( & V_216 -> V_187 ) ;
return V_9 ;
}
static void F_111 ( struct V_16 * V_17 )
{
if ( V_17 -> V_27 ) {
int V_55 ;
for ( V_55 = 0 ; V_55 < V_17 -> V_27 ; V_55 ++ ) {
struct V_215 * V_216 = V_17 -> V_212 [ V_55 ] . V_216 ;
if ( V_216 ) {
F_112 ( V_216 ) ;
V_17 -> V_212 [ V_55 ] . V_216 = NULL ;
}
}
}
}
static int F_113 ( struct V_16 * V_17 ,
struct V_231 * V_232 , T_10 V_240 )
{
if ( V_17 -> V_32 & V_75 ) {
struct V_215 * V_216 = V_17 -> V_212 [ V_17 -> V_214 ] . V_216 ;
int V_241 = 0 ;
if ( V_216 ) {
int V_144 ;
T_11 * V_242 ;
V_241 = V_216 -> V_222 . V_223 - F_114 ( V_232 ) ;
if ( V_241 > 0 ) {
V_144 = F_115 ( V_232 , V_241 , 0 , V_243 ) ;
if ( V_144 < 0 ) {
F_46 ( L_230 ,
V_144 ) ;
goto V_9;
}
}
F_116 ( V_232 , V_244 ) ;
V_144 = F_108 ( V_232 , V_17 ) ;
if ( V_144 ) {
F_46 ( L_231 , V_144 ) ;
goto V_9;
}
V_242 = ( T_11 * ) F_117 ( V_232 , V_244 ) ;
memcpy ( V_242 , V_17 -> V_137 , 12 ) ;
* ( V_245 * ) & V_242 [ 12 ] = V_240 ;
}
}
return 1 ;
V_9:
F_118 ( V_232 ) ;
return 0 ;
}
static void F_119 ( V_228 * V_246 , struct V_16 * V_17 )
{
unsigned int V_55 ;
for ( V_55 = 0 ; V_55 < V_17 -> V_54 ; V_55 ++ )
* V_246 ++ = V_17 -> V_56 [ V_55 ] & ~ V_111 ;
V_246 -- ;
* V_246 |= V_111 ;
}
static inline T_10 F_120 ( unsigned int V_247 , unsigned int V_248 ,
unsigned int V_249 )
{
return F_121 ( V_247 | ( V_248 << 12 ) | ( V_249 << 13 ) ) ;
}
static void F_122 ( struct V_16 * V_17 , struct V_231 * V_232 ,
int V_250 )
{
struct V_251 V_252 ;
struct V_182 * V_253 ;
V_253 = (struct V_182 * ) F_123 ( V_232 , sizeof( * V_253 ) ) ;
V_250 -= sizeof( * V_253 ) ;
if ( V_17 -> V_23 <= 0 ) {
memset ( F_123 ( V_232 , V_250 ) , 0 , V_250 ) ;
} else {
int V_254 = V_17 -> V_23 ;
int V_55 , V_109 ;
int V_255 ;
if ( V_254 > V_256 )
V_254 = V_256 ;
V_109 = V_250 - V_254 * V_257 ;
if ( V_109 > 0 ) {
memset ( F_123 ( V_232 , V_109 ) , 0 , V_109 ) ;
V_250 = V_254 * V_257 ;
}
V_55 = 0 ;
V_255 = ( V_250 / V_254 ) < V_257 ?
( V_250 / V_254 ) : V_257 ;
while ( V_250 > 0 ) {
if ( F_124 ( ! V_17 -> V_130 ) ) {
int V_65 = F_125 () ;
if ( V_17 -> V_65 >= 0 && ( V_17 -> V_32 & V_80 ) )
V_65 = V_17 -> V_65 ;
V_17 -> V_130 = F_126 ( V_65 , V_258 | V_259 , 0 ) ;
if ( ! V_17 -> V_130 )
break;
}
F_127 ( V_17 -> V_130 ) ;
F_128 ( V_232 , V_55 , V_17 -> V_130 ) ;
F_129 ( V_232 ) -> V_254 [ V_55 ] . V_260 = 0 ;
if ( V_55 == ( V_254 - 1 ) )
F_130 ( & F_129 ( V_232 ) -> V_254 [ V_55 ] ,
( V_250 < V_257 ? V_250 : V_257 ) ) ;
else
F_130 ( & F_129 ( V_232 ) -> V_254 [ V_55 ] , V_255 ) ;
V_250 -= F_131 ( & F_129 ( V_232 ) -> V_254 [ V_55 ] ) ;
V_232 -> V_109 += F_131 ( & F_129 ( V_232 ) -> V_254 [ V_55 ] ) ;
V_232 -> V_261 += F_131 ( & F_129 ( V_232 ) -> V_254 [ V_55 ] ) ;
V_55 ++ ;
F_129 ( V_232 ) -> V_262 = V_55 ;
}
}
V_253 -> V_263 = F_28 ( V_264 ) ;
V_253 -> V_88 = F_28 ( V_17 -> V_88 ) ;
F_132 ( & V_252 ) ;
V_253 -> V_265 = F_28 ( V_252 . V_265 ) ;
V_253 -> V_266 = F_28 ( V_252 . V_266 ) ;
}
static struct V_231 * F_133 ( struct V_156 * V_45 ,
struct V_16 * V_17 )
{
struct V_231 * V_232 = NULL ;
T_11 * V_242 ;
struct V_181 * V_267 ;
int V_250 , V_268 ;
struct V_192 * V_269 ;
T_10 V_240 = F_121 ( V_270 ) ;
V_228 * V_246 ;
T_10 * V_271 = NULL ;
T_10 * V_272 = NULL ;
T_10 * V_273 = NULL ;
T_10 * V_274 = NULL ;
V_245 V_275 ;
if ( V_17 -> V_54 )
V_240 = F_121 ( V_276 ) ;
if ( V_17 -> V_57 != 0xffff )
V_240 = F_121 ( V_277 ) ;
F_101 ( V_17 ) ;
V_275 = V_17 -> V_97 ;
V_250 = ( V_45 -> V_278 + 16 ) & ~ 0xf ;
if ( V_17 -> V_32 & V_80 ) {
int V_65 ;
if ( V_17 -> V_65 >= 0 )
V_65 = V_17 -> V_65 ;
else
V_65 = F_125 () ;
V_232 = F_134 ( V_279 + V_17 -> V_124 + 64
+ V_250 + V_17 -> V_183 , V_280 , 0 , V_65 ) ;
if ( F_85 ( V_232 ) ) {
F_135 ( V_232 , V_279 ) ;
V_232 -> V_157 = V_45 ;
}
}
else
V_232 = F_136 ( V_45 ,
V_17 -> V_124 + 64
+ V_250 + V_17 -> V_183 , V_280 ) ;
if ( ! V_232 ) {
sprintf ( V_17 -> V_99 , L_232 ) ;
return NULL ;
}
F_137 ( V_232 -> V_10 ) ;
F_135 ( V_232 , V_250 ) ;
V_242 = ( T_11 * ) F_117 ( V_232 , 14 ) ;
V_246 = ( V_228 * ) F_123 ( V_232 , V_17 -> V_54 * sizeof( T_7 ) ) ;
if ( V_17 -> V_54 )
F_119 ( V_246 , V_17 ) ;
if ( V_17 -> V_57 != 0xffff ) {
if ( V_17 -> V_60 != 0xffff ) {
V_273 = ( T_10 * ) F_123 ( V_232 , sizeof( T_10 ) ) ;
* V_273 = F_120 ( V_17 -> V_60 ,
V_17 -> V_62 ,
V_17 -> V_61 ) ;
V_274 = ( T_10 * ) F_123 ( V_232 , sizeof( T_10 ) ) ;
* V_274 = F_121 ( V_277 ) ;
}
V_271 = ( T_10 * ) F_123 ( V_232 , sizeof( T_10 ) ) ;
* V_271 = F_120 ( V_17 -> V_57 ,
V_17 -> V_59 ,
V_17 -> V_58 ) ;
V_272 = ( T_10 * ) F_123 ( V_232 , sizeof( T_10 ) ) ;
* V_272 = F_121 ( V_270 ) ;
}
V_232 -> V_281 = V_232 -> V_282 ;
V_232 -> V_283 = V_232 -> V_281 + sizeof( struct V_192 ) ;
F_123 ( V_232 , sizeof( struct V_192 ) + sizeof( struct V_181 ) ) ;
F_138 ( V_232 , V_275 ) ;
V_232 -> V_284 = V_17 -> V_31 ;
V_269 = F_139 ( V_232 ) ;
V_267 = F_140 ( V_232 ) ;
memcpy ( V_242 , V_17 -> V_137 , 12 ) ;
* ( T_10 * ) & V_242 [ 12 ] = V_240 ;
V_250 = V_17 -> V_124 - 14 - 20 - 8 -
V_17 -> V_183 ;
if ( V_250 < 0 || V_250 < sizeof( struct V_182 ) )
V_250 = sizeof( struct V_182 ) ;
V_267 -> V_285 = F_121 ( V_17 -> V_96 ) ;
V_267 -> V_286 = F_121 ( V_17 -> V_95 ) ;
V_267 -> V_109 = F_121 ( V_250 + 8 ) ;
V_267 -> V_287 = 0 ;
V_269 -> V_288 = 5 ;
V_269 -> V_4 = 4 ;
V_269 -> V_289 = 32 ;
V_269 -> V_63 = V_17 -> V_63 ;
V_269 -> V_240 = V_290 ;
V_269 -> V_291 = V_17 -> V_93 ;
V_269 -> V_292 = V_17 -> V_94 ;
V_269 -> V_247 = F_121 ( V_17 -> V_293 ) ;
V_17 -> V_293 ++ ;
V_269 -> V_294 = 0 ;
V_268 = 20 + 8 + V_250 ;
V_269 -> V_295 = F_121 ( V_268 ) ;
V_269 -> V_287 = 0 ;
V_269 -> V_287 = F_141 ( ( void * ) V_269 , V_269 -> V_288 ) ;
V_232 -> V_240 = V_240 ;
V_232 -> V_296 = ( V_232 -> V_281 - V_244 -
V_17 -> V_183 ) ;
V_232 -> V_157 = V_45 ;
V_232 -> V_297 = V_298 ;
F_122 ( V_17 , V_232 , V_250 ) ;
#ifdef F_17
if ( ! F_113 ( V_17 , V_232 , V_240 ) )
return NULL ;
#endif
return V_232 ;
}
static struct V_231 * F_142 ( struct V_156 * V_45 ,
struct V_16 * V_17 )
{
struct V_231 * V_232 = NULL ;
T_11 * V_242 ;
struct V_181 * V_267 ;
int V_250 ;
struct V_180 * V_269 ;
T_10 V_240 = F_121 ( V_299 ) ;
V_228 * V_246 ;
T_10 * V_271 = NULL ;
T_10 * V_272 = NULL ;
T_10 * V_273 = NULL ;
T_10 * V_274 = NULL ;
V_245 V_275 ;
if ( V_17 -> V_54 )
V_240 = F_121 ( V_276 ) ;
if ( V_17 -> V_57 != 0xffff )
V_240 = F_121 ( V_277 ) ;
F_101 ( V_17 ) ;
V_275 = V_17 -> V_97 ;
V_232 = F_136 ( V_45 ,
V_17 -> V_124 + 64
+ 16 + V_17 -> V_183 , V_280 ) ;
if ( ! V_232 ) {
sprintf ( V_17 -> V_99 , L_232 ) ;
return NULL ;
}
F_137 ( V_232 -> V_10 ) ;
F_135 ( V_232 , 16 ) ;
V_242 = ( T_11 * ) F_117 ( V_232 , 14 ) ;
V_246 = ( V_228 * ) F_123 ( V_232 , V_17 -> V_54 * sizeof( T_7 ) ) ;
if ( V_17 -> V_54 )
F_119 ( V_246 , V_17 ) ;
if ( V_17 -> V_57 != 0xffff ) {
if ( V_17 -> V_60 != 0xffff ) {
V_273 = ( T_10 * ) F_123 ( V_232 , sizeof( T_10 ) ) ;
* V_273 = F_120 ( V_17 -> V_60 ,
V_17 -> V_62 ,
V_17 -> V_61 ) ;
V_274 = ( T_10 * ) F_123 ( V_232 , sizeof( T_10 ) ) ;
* V_274 = F_121 ( V_277 ) ;
}
V_271 = ( T_10 * ) F_123 ( V_232 , sizeof( T_10 ) ) ;
* V_271 = F_120 ( V_17 -> V_57 ,
V_17 -> V_59 ,
V_17 -> V_58 ) ;
V_272 = ( T_10 * ) F_123 ( V_232 , sizeof( T_10 ) ) ;
* V_272 = F_121 ( V_299 ) ;
}
V_232 -> V_281 = V_232 -> V_282 ;
V_232 -> V_283 = V_232 -> V_281 + sizeof( struct V_180 ) ;
F_123 ( V_232 , sizeof( struct V_180 ) + sizeof( struct V_181 ) ) ;
F_138 ( V_232 , V_275 ) ;
V_232 -> V_284 = V_17 -> V_31 ;
V_269 = F_143 ( V_232 ) ;
V_267 = F_140 ( V_232 ) ;
memcpy ( V_242 , V_17 -> V_137 , 12 ) ;
* ( T_10 * ) & V_242 [ 12 ] = V_240 ;
V_250 = V_17 -> V_124 - 14 -
sizeof( struct V_180 ) - sizeof( struct V_181 ) -
V_17 -> V_183 ;
if ( V_250 < 0 || V_250 < sizeof( struct V_182 ) ) {
V_250 = sizeof( struct V_182 ) ;
F_144 ( L_233 , V_250 ) ;
}
V_267 -> V_285 = F_121 ( V_17 -> V_96 ) ;
V_267 -> V_286 = F_121 ( V_17 -> V_95 ) ;
V_267 -> V_109 = F_121 ( V_250 + sizeof( struct V_181 ) ) ;
V_267 -> V_287 = 0 ;
* ( V_228 * ) V_269 = F_28 ( 0x60000000 ) ;
if ( V_17 -> V_64 ) {
* ( V_228 * ) V_269 |= F_28 ( 0x60000000 | ( V_17 -> V_64 << 20 ) ) ;
}
V_269 -> V_300 = 32 ;
V_269 -> V_301 = F_121 ( sizeof( struct V_181 ) + V_250 ) ;
V_269 -> V_302 = V_290 ;
V_269 -> V_292 = V_17 -> V_92 ;
V_269 -> V_291 = V_17 -> V_91 ;
V_232 -> V_296 = ( V_232 -> V_281 - V_244 -
V_17 -> V_183 ) ;
V_232 -> V_240 = V_240 ;
V_232 -> V_157 = V_45 ;
V_232 -> V_297 = V_298 ;
F_122 ( V_17 , V_232 , V_250 ) ;
return V_232 ;
}
static struct V_231 * F_145 ( struct V_156 * V_45 ,
struct V_16 * V_17 )
{
if ( V_17 -> V_32 & V_33 )
return F_142 ( V_45 , V_17 ) ;
else
return F_133 ( V_45 , V_17 ) ;
}
static void F_38 ( struct V_16 * V_17 )
{
V_17 -> V_88 = 1 ;
V_17 -> V_83 = 0 ;
V_17 -> V_85 = 0 ;
V_17 -> V_303 = 0 ;
V_17 -> V_86 = 0 ;
}
static void F_146 ( struct V_142 * V_143 )
{
struct V_16 * V_17 ;
int V_304 = 0 ;
F_147 () ;
F_42 ( V_143 ) ;
F_43 (pkt_dev, &t->if_list, list) {
F_67 ( V_17 ) ;
if ( V_17 -> V_45 ) {
F_38 ( V_17 ) ;
V_17 -> V_81 = 1 ;
V_17 -> V_232 = NULL ;
V_17 -> V_87 = V_17 -> V_205 = F_18 () ;
F_91 ( V_17 ) ;
strcpy ( V_17 -> V_99 , L_234 ) ;
V_304 ++ ;
} else
strcpy ( V_17 -> V_99 , L_235 ) ;
}
F_44 ( V_143 ) ;
if ( V_304 )
V_143 -> V_146 &= ~ ( V_305 ) ;
}
static void F_6 ( void )
{
struct V_142 * V_143 ;
F_147 () ;
F_47 ( & V_145 ) ;
F_43 (t, &pktgen_threads, th_list)
V_143 -> V_146 |= V_305 ;
F_49 ( & V_145 ) ;
}
static int F_148 ( const struct V_142 * V_143 )
{
const struct V_16 * V_17 ;
F_43 (pkt_dev, &t->if_list, list)
if ( V_17 -> V_81 )
return 1 ;
return 0 ;
}
static int F_149 ( struct V_142 * V_143 )
{
F_42 ( V_143 ) ;
while ( F_148 ( V_143 ) ) {
F_44 ( V_143 ) ;
F_150 ( 100 ) ;
if ( F_88 ( V_206 ) )
goto signal;
F_42 ( V_143 ) ;
}
F_44 ( V_143 ) ;
return 1 ;
signal:
return 0 ;
}
static int F_151 ( void )
{
struct V_142 * V_143 ;
int V_306 = 1 ;
F_47 ( & V_145 ) ;
F_43 (t, &pktgen_threads, th_list) {
V_306 = F_149 ( V_143 ) ;
if ( V_306 == 0 )
break;
}
if ( V_306 == 0 )
F_43 (t, &pktgen_threads, th_list)
V_143 -> V_146 |= ( V_305 ) ;
F_49 ( & V_145 ) ;
return V_306 ;
}
static void F_7 ( void )
{
struct V_142 * V_143 ;
F_147 () ;
F_47 ( & V_145 ) ;
F_43 (t, &pktgen_threads, th_list)
V_143 -> V_146 |= ( V_307 ) ;
F_49 ( & V_145 ) ;
F_50 ( F_51 ( 125 ) ) ;
F_151 () ;
}
static void F_8 ( void )
{
struct V_142 * V_143 ;
F_147 () ;
F_47 ( & V_145 ) ;
F_43 (t, &pktgen_threads, th_list)
V_143 -> V_146 |= ( V_147 ) ;
F_49 ( & V_145 ) ;
F_50 ( F_51 ( 125 ) ) ;
F_151 () ;
}
static void F_152 ( struct V_16 * V_17 , int V_262 )
{
T_12 V_308 , V_309 , V_310 ;
char * V_311 = V_17 -> V_99 ;
T_5 V_312 = F_90 ( V_17 -> V_82 ,
V_17 -> V_87 ) ;
T_5 V_20 = F_153 ( V_17 -> V_83 ) ;
V_311 += sprintf ( V_311 , L_236 ,
( unsigned long long ) F_20 ( V_312 ) ,
( unsigned long long ) F_20 ( F_90 ( V_312 , V_20 ) ) ,
( unsigned long long ) F_20 ( V_20 ) ,
( unsigned long long ) V_17 -> V_85 ,
V_17 -> V_124 , V_262 ) ;
V_310 = F_154 ( V_17 -> V_85 * V_126 ,
F_77 ( V_312 ) ) ;
V_308 = V_310 * 8 * V_17 -> V_124 ;
V_309 = V_308 ;
F_19 ( V_309 , 1000000 ) ;
V_311 += sprintf ( V_311 , L_237 ,
( unsigned long long ) V_310 ,
( unsigned long long ) V_309 ,
( unsigned long long ) V_308 ,
( unsigned long long ) V_17 -> V_86 ) ;
}
static int F_155 ( struct V_16 * V_17 )
{
int V_262 = V_17 -> V_232 ? F_129 ( V_17 -> V_232 ) -> V_262 : - 1 ;
if ( ! V_17 -> V_81 ) {
F_9 ( L_238 ,
V_17 -> V_26 ) ;
return - V_120 ;
}
F_118 ( V_17 -> V_232 ) ;
V_17 -> V_232 = NULL ;
V_17 -> V_82 = F_18 () ;
V_17 -> V_81 = 0 ;
F_152 ( V_17 , V_262 ) ;
return 0 ;
}
static struct V_16 * F_156 ( struct V_142 * V_143 )
{
struct V_16 * V_17 , * V_313 = NULL ;
F_42 ( V_143 ) ;
F_43 (pkt_dev, &t->if_list, list) {
if ( ! V_17 -> V_81 )
continue;
if ( V_313 == NULL )
V_313 = V_17 ;
else if ( F_80 ( V_17 -> V_205 , V_313 -> V_205 ) < 0 )
V_313 = V_17 ;
}
F_44 ( V_143 ) ;
return V_313 ;
}
static void F_157 ( struct V_142 * V_143 )
{
struct V_16 * V_17 ;
F_147 () ;
F_42 ( V_143 ) ;
F_43 (pkt_dev, &t->if_list, list) {
F_155 ( V_17 ) ;
}
F_44 ( V_143 ) ;
}
static void F_158 ( struct V_142 * V_143 )
{
struct V_314 * V_315 , * V_108 ;
struct V_16 * V_316 ;
F_147 () ;
F_42 ( V_143 ) ;
F_159 (q, n, &t->if_list) {
V_316 = F_160 ( V_315 , struct V_16 , V_317 ) ;
if ( ! V_316 -> V_151 )
continue;
F_118 ( V_316 -> V_232 ) ;
V_316 -> V_232 = NULL ;
F_161 ( V_143 , V_316 ) ;
break;
}
F_44 ( V_143 ) ;
}
static void F_162 ( struct V_142 * V_143 )
{
struct V_314 * V_315 , * V_108 ;
struct V_16 * V_316 ;
F_147 () ;
F_42 ( V_143 ) ;
F_159 (q, n, &t->if_list) {
V_316 = F_160 ( V_315 , struct V_16 , V_317 ) ;
F_118 ( V_316 -> V_232 ) ;
V_316 -> V_232 = NULL ;
F_161 ( V_143 , V_316 ) ;
}
F_44 ( V_143 ) ;
}
static void F_163 ( struct V_142 * V_143 )
{
F_57 ( V_143 -> V_318 -> V_319 , V_159 ) ;
}
static void F_164 ( struct V_16 * V_17 )
{
T_5 V_320 = F_18 () ;
F_86 () ;
V_17 -> V_83 += F_77 ( F_90 ( F_18 () , V_320 ) ) ;
}
static void F_165 ( struct V_16 * V_17 )
{
T_5 V_320 = F_18 () ;
while ( F_166 ( & ( V_17 -> V_232 -> V_321 ) ) != 1 ) {
if ( F_88 ( V_206 ) )
break;
if ( F_167 () )
F_164 ( V_17 ) ;
else
F_168 () ;
}
V_17 -> V_83 += F_77 ( F_90 ( F_18 () , V_320 ) ) ;
}
static void F_169 ( struct V_16 * V_17 )
{
struct V_156 * V_45 = V_17 -> V_45 ;
T_13 (* F_170)( struct V_231 * , struct V_156 * )
= V_45 -> V_322 -> V_323 ;
struct V_324 * V_325 ;
V_245 V_275 ;
int V_144 ;
if ( F_124 ( ! F_66 ( V_45 ) || ! F_171 ( V_45 ) ) ) {
F_155 ( V_17 ) ;
return;
}
if ( F_124 ( V_17 -> V_24 == V_125 ) ) {
V_17 -> V_205 = F_79 ( F_18 () , V_326 ) ;
return;
}
if ( ! V_17 -> V_232 || ( V_17 -> V_327 &&
++ V_17 -> V_328 >= V_17 -> V_25 ) ) {
F_118 ( V_17 -> V_232 ) ;
V_17 -> V_232 = F_145 ( V_45 , V_17 ) ;
if ( V_17 -> V_232 == NULL ) {
F_46 ( L_239 ) ;
F_86 () ;
V_17 -> V_328 -- ;
return;
}
V_17 -> V_329 = V_17 -> V_232 -> V_109 ;
V_17 -> V_330 ++ ;
V_17 -> V_328 = 0 ;
}
if ( V_17 -> V_24 && V_17 -> V_327 )
F_74 ( V_17 , V_17 -> V_205 ) ;
V_275 = F_172 ( V_17 -> V_232 ) ;
V_325 = F_173 ( V_45 , V_275 ) ;
F_174 ( V_325 ) ;
if ( F_124 ( F_175 ( V_325 ) ) ) {
V_144 = V_331 ;
V_17 -> V_327 = 0 ;
goto V_332;
}
F_176 ( & ( V_17 -> V_232 -> V_321 ) ) ;
V_144 = (* F_170)( V_17 -> V_232 , V_45 ) ;
switch ( V_144 ) {
case V_333 :
F_177 ( V_325 ) ;
V_17 -> V_327 = 1 ;
V_17 -> V_85 ++ ;
V_17 -> V_88 ++ ;
V_17 -> V_303 += V_17 -> V_329 ;
break;
case V_334 :
case V_335 :
case V_336 :
V_17 -> V_86 ++ ;
break;
default:
F_144 ( L_240 ,
V_17 -> V_26 , V_144 ) ;
V_17 -> V_86 ++ ;
case V_337 :
case V_331 :
F_178 ( & ( V_17 -> V_232 -> V_321 ) ) ;
V_17 -> V_327 = 0 ;
}
V_332:
F_179 ( V_325 ) ;
if ( ( V_17 -> V_7 != 0 ) && ( V_17 -> V_85 >= V_17 -> V_7 ) ) {
F_165 ( V_17 ) ;
F_155 ( V_17 ) ;
}
}
static int F_180 ( void * V_338 )
{
F_181 ( V_339 ) ;
struct V_142 * V_143 = V_338 ;
struct V_16 * V_17 = NULL ;
int V_340 = V_143 -> V_340 ;
F_41 ( F_100 () != V_340 ) ;
F_182 ( & V_143 -> V_341 ) ;
F_183 ( & V_143 -> V_342 ) ;
F_31 ( L_241 , V_340 , F_184 ( V_206 ) ) ;
F_82 ( V_207 ) ;
F_185 () ;
while ( ! F_186 () ) {
V_17 = F_156 ( V_143 ) ;
if ( F_124 ( ! V_17 && V_143 -> V_146 == 0 ) ) {
if ( V_166 )
break;
F_187 ( V_143 -> V_341 ,
V_143 -> V_146 != 0 ,
V_343 / 10 ) ;
F_188 () ;
continue;
}
F_89 ( V_209 ) ;
if ( F_85 ( V_17 ) ) {
F_169 ( V_17 ) ;
if ( F_167 () )
F_164 ( V_17 ) ;
else
F_168 () ;
}
if ( V_143 -> V_146 & V_305 ) {
F_157 ( V_143 ) ;
V_143 -> V_146 &= ~ ( V_305 ) ;
}
if ( V_143 -> V_146 & V_307 ) {
F_146 ( V_143 ) ;
V_143 -> V_146 &= ~ ( V_307 ) ;
}
if ( V_143 -> V_146 & V_147 ) {
F_162 ( V_143 ) ;
V_143 -> V_146 &= ~ ( V_147 ) ;
}
if ( V_143 -> V_146 & V_152 ) {
F_158 ( V_143 ) ;
V_143 -> V_146 &= ~ ( V_152 ) ;
}
F_188 () ;
F_82 ( V_207 ) ;
}
F_31 ( L_242 , V_143 -> V_318 -> V_319 ) ;
F_157 ( V_143 ) ;
F_31 ( L_243 , V_143 -> V_318 -> V_319 ) ;
F_162 ( V_143 ) ;
F_31 ( L_244 , V_143 -> V_318 -> V_319 ) ;
F_163 ( V_143 ) ;
while ( ! F_186 () ) {
F_82 ( V_207 ) ;
F_86 () ;
}
F_89 ( V_209 ) ;
return 0 ;
}
static struct V_16 * F_54 ( struct V_142 * V_143 ,
const char * V_148 , bool V_149 )
{
struct V_16 * V_311 , * V_17 = NULL ;
T_3 V_109 = strlen ( V_148 ) ;
F_42 ( V_143 ) ;
F_43 (p, &t->if_list, list)
if ( strncmp ( V_311 -> V_26 , V_148 , V_109 ) == 0 ) {
if ( V_311 -> V_26 [ V_109 ] ) {
if ( V_149 || V_311 -> V_26 [ V_109 ] != '@' )
continue;
}
V_17 = V_311 ;
break;
}
F_44 ( V_143 ) ;
F_31 ( L_245 , V_148 , V_17 ) ;
return V_17 ;
}
static int F_189 ( struct V_142 * V_143 ,
struct V_16 * V_17 )
{
int V_344 = 0 ;
F_42 ( V_143 ) ;
if ( V_17 -> V_345 ) {
F_46 ( L_246 ) ;
V_344 = - V_346 ;
goto V_13;
}
F_190 ( & V_17 -> V_317 , & V_143 -> V_347 ) ;
V_17 -> V_345 = V_143 ;
V_17 -> V_81 = 0 ;
V_13:
F_44 ( V_143 ) ;
return V_344 ;
}
static int F_48 ( struct V_142 * V_143 , const char * V_148 )
{
struct V_16 * V_17 ;
int V_9 ;
int V_65 = F_191 ( V_143 -> V_340 ) ;
V_17 = F_53 ( V_148 , V_150 ) ;
if ( V_17 ) {
F_46 ( L_247 ) ;
return - V_346 ;
}
V_17 = F_192 ( sizeof( struct V_16 ) , V_258 , V_65 ) ;
if ( ! V_17 )
return - V_348 ;
strcpy ( V_17 -> V_26 , V_148 ) ;
V_17 -> V_212 = F_193 ( V_139 * sizeof( struct V_349 ) ,
V_65 ) ;
if ( V_17 -> V_212 == NULL ) {
F_194 ( V_17 ) ;
return - V_348 ;
}
V_17 -> V_151 = 0 ;
V_17 -> V_23 = 0 ;
V_17 -> V_24 = V_350 ;
V_17 -> V_7 = V_351 ;
V_17 -> V_85 = 0 ;
V_17 -> V_48 = 9 ;
V_17 -> V_49 = 9 ;
V_17 -> V_50 = 9 ;
V_17 -> V_51 = 9 ;
V_17 -> V_58 = 0 ;
V_17 -> V_59 = 0 ;
V_17 -> V_57 = 0xffff ;
V_17 -> V_61 = 0 ;
V_17 -> V_62 = 0 ;
V_17 -> V_60 = 0xffff ;
V_17 -> V_65 = - 1 ;
V_9 = F_64 ( V_17 , V_148 ) ;
if ( V_9 )
goto V_352;
if ( V_17 -> V_45 -> V_127 & V_128 )
V_17 -> V_25 = V_353 ;
V_17 -> V_158 = F_58 ( V_148 , 0600 , V_159 ,
& V_160 , V_17 ) ;
if ( ! V_17 -> V_158 ) {
F_46 ( L_248 ,
V_354 , V_148 ) ;
V_9 = - V_120 ;
goto V_355;
}
#ifdef F_17
V_17 -> V_220 = V_234 ;
V_17 -> V_221 = V_356 ;
#endif
return F_189 ( V_143 , V_17 ) ;
V_355:
F_65 ( V_17 -> V_45 ) ;
V_352:
#ifdef F_17
F_111 ( V_17 ) ;
#endif
F_195 ( V_17 -> V_212 ) ;
F_194 ( V_17 ) ;
return V_9 ;
}
static int T_14 F_196 ( int V_340 )
{
struct V_142 * V_143 ;
struct V_357 * V_358 ;
struct V_359 * V_311 ;
V_143 = F_192 ( sizeof( struct V_142 ) , V_258 ,
F_191 ( V_340 ) ) ;
if ( ! V_143 ) {
F_46 ( L_249 ) ;
return - V_348 ;
}
F_197 ( & V_143 -> F_42 ) ;
V_143 -> V_340 = V_340 ;
F_198 ( & V_143 -> V_347 ) ;
F_199 ( & V_143 -> V_360 , & V_361 ) ;
F_200 ( & V_143 -> V_342 ) ;
V_311 = F_201 ( F_180 ,
V_143 ,
F_191 ( V_340 ) ,
L_250 , V_340 ) ;
if ( F_202 ( V_311 ) ) {
F_46 ( L_251 , V_143 -> V_340 ) ;
F_203 ( & V_143 -> V_360 ) ;
F_194 ( V_143 ) ;
return F_204 ( V_311 ) ;
}
F_205 ( V_311 , V_340 ) ;
V_143 -> V_318 = V_311 ;
V_358 = F_58 ( V_143 -> V_318 -> V_319 , 0600 , V_159 ,
& V_362 , V_143 ) ;
if ( ! V_358 ) {
F_46 ( L_248 ,
V_354 , V_143 -> V_318 -> V_319 ) ;
F_206 ( V_311 ) ;
F_203 ( & V_143 -> V_360 ) ;
F_194 ( V_143 ) ;
return - V_120 ;
}
F_207 ( V_311 ) ;
F_208 ( & V_143 -> V_342 ) ;
return 0 ;
}
static void F_209 ( struct V_142 * V_143 ,
struct V_16 * V_17 )
{
struct V_314 * V_315 , * V_108 ;
struct V_16 * V_311 ;
F_159 (q, n, &t->if_list) {
V_311 = F_160 ( V_315 , struct V_16 , V_317 ) ;
if ( V_311 == V_17 )
F_203 ( & V_311 -> V_317 ) ;
}
}
static int F_161 ( struct V_142 * V_143 ,
struct V_16 * V_17 )
{
F_31 ( L_252 , V_17 ) ;
if ( V_17 -> V_81 ) {
F_9 ( L_253 ) ;
F_155 ( V_17 ) ;
}
if ( V_17 -> V_45 ) {
F_65 ( V_17 -> V_45 ) ;
V_17 -> V_45 = NULL ;
}
F_209 ( V_143 , V_17 ) ;
if ( V_17 -> V_158 )
F_57 ( V_17 -> V_158 -> V_117 , V_159 ) ;
#ifdef F_17
F_111 ( V_17 ) ;
#endif
F_195 ( V_17 -> V_212 ) ;
if ( V_17 -> V_130 )
F_34 ( V_17 -> V_130 ) ;
F_194 ( V_17 ) ;
return 0 ;
}
static int T_14 F_210 ( void )
{
int V_340 ;
struct V_357 * V_358 ;
int V_144 = 0 ;
F_32 ( L_254 , V_4 ) ;
V_159 = F_211 ( V_354 , V_165 . V_363 ) ;
if ( ! V_159 )
return - V_172 ;
V_358 = F_212 ( V_364 , 0600 , V_159 , & V_365 ) ;
if ( V_358 == NULL ) {
F_46 ( L_255 , V_364 ) ;
V_144 = - V_120 ;
goto V_366;
}
F_213 ( & V_367 ) ;
F_214 (cpu) {
int V_9 ;
V_9 = F_196 ( V_340 ) ;
if ( V_9 )
F_9 ( L_256 ,
V_340 , V_9 ) ;
}
if ( F_215 ( & V_361 ) ) {
F_46 ( L_257 ) ;
V_144 = - V_172 ;
goto V_368;
}
return 0 ;
V_368:
F_216 ( & V_367 ) ;
F_57 ( V_364 , V_159 ) ;
V_366:
F_217 ( & V_165 , V_354 ) ;
return V_144 ;
}
static void T_15 F_218 ( void )
{
struct V_142 * V_143 ;
struct V_314 * V_315 , * V_108 ;
F_219 ( V_317 ) ;
V_166 = true ;
F_47 ( & V_145 ) ;
F_220 ( & V_361 , & V_317 ) ;
F_49 ( & V_145 ) ;
F_159 (q, n, &list) {
V_143 = F_160 ( V_315 , struct V_142 , V_360 ) ;
F_203 ( & V_143 -> V_360 ) ;
F_206 ( V_143 -> V_318 ) ;
F_194 ( V_143 ) ;
}
F_216 ( & V_367 ) ;
F_57 ( V_364 , V_159 ) ;
F_217 ( & V_165 , V_354 ) ;
}
