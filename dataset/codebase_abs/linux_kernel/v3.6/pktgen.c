static inline T_1 F_1 ( void )
{
struct V_1 V_2 ;
F_2 ( & V_2 ) ;
return F_3 ( V_2 ) ;
}
static inline int F_4 ( const T_1 V_3 , const T_1 V_4 )
{
return V_3 . V_5 < V_4 . V_5 ;
}
static int F_5 ( struct V_6 * V_7 , void * V_8 )
{
F_6 ( V_7 , V_9 ) ;
return 0 ;
}
static T_2 F_7 ( struct V_10 * V_10 , const char T_3 * V_11 ,
T_4 V_12 , T_5 * V_13 )
{
int V_14 = 0 ;
char V_15 [ 128 ] ;
if ( ! F_8 ( V_16 ) ) {
V_14 = - V_17 ;
goto V_18;
}
if ( V_12 > sizeof( V_15 ) )
V_12 = sizeof( V_15 ) ;
if ( F_9 ( V_15 , V_11 , V_12 ) ) {
V_14 = - V_19 ;
goto V_18;
}
V_15 [ V_12 - 1 ] = 0 ;
if ( ! strcmp ( V_15 , L_1 ) )
F_10 () ;
else if ( ! strcmp ( V_15 , L_2 ) )
F_11 () ;
else if ( ! strcmp ( V_15 , L_3 ) )
F_12 () ;
else
F_13 ( L_4 , V_15 ) ;
V_14 = V_12 ;
V_18:
return V_14 ;
}
static int F_14 ( struct V_20 * V_20 , struct V_10 * V_10 )
{
return F_15 ( V_10 , F_5 , F_16 ( V_20 ) -> V_15 ) ;
}
static int F_17 ( struct V_6 * V_7 , void * V_8 )
{
const struct V_21 * V_22 = V_7 -> V_23 ;
T_1 V_24 ;
T_6 V_25 ;
F_18 ( V_7 ,
L_5 ,
( unsigned long long ) V_22 -> V_12 , V_22 -> V_26 ,
V_22 -> V_27 ) ;
F_18 ( V_7 ,
L_6 ,
V_22 -> V_28 , ( unsigned long long ) V_22 -> V_29 ,
V_22 -> V_30 , V_22 -> V_31 ) ;
F_18 ( V_7 , L_7 , V_22 -> V_32 ,
V_22 -> V_33 ) ;
F_18 ( V_7 ,
L_8 ,
V_22 -> V_34 ,
V_22 -> V_35 ) ;
if ( V_22 -> V_36 )
F_18 ( V_7 , L_9 ,
V_22 -> V_36 ) ;
if ( V_22 -> V_37 & V_38 ) {
F_18 ( V_7 ,
L_10
L_11 ,
& V_22 -> V_39 ,
& V_22 -> V_40 , & V_22 -> V_41 ,
& V_22 -> V_42 ,
& V_22 -> V_43 , & V_22 -> V_44 ) ;
} else {
F_18 ( V_7 ,
L_12 ,
V_22 -> V_45 , V_22 -> V_46 ) ;
F_18 ( V_7 ,
L_13 ,
V_22 -> V_47 , V_22 -> V_48 ) ;
}
F_6 ( V_7 , L_14 ) ;
F_18 ( V_7 , L_15 ,
F_19 ( V_22 -> V_49 ) ?
V_22 -> V_50 -> V_51 : V_22 -> V_49 ) ;
F_18 ( V_7 , L_16 ) ;
F_18 ( V_7 , L_17 , V_22 -> V_52 ) ;
F_18 ( V_7 ,
L_18
L_19 ,
V_22 -> V_53 , V_22 -> V_54 ,
V_22 -> V_55 , V_22 -> V_56 ) ;
F_18 ( V_7 ,
L_20 ,
V_22 -> V_57 , V_22 -> V_58 ) ;
if ( V_22 -> V_59 ) {
unsigned int V_60 ;
F_18 ( V_7 , L_21 ) ;
for ( V_60 = 0 ; V_60 < V_22 -> V_59 ; V_60 ++ )
F_18 ( V_7 , L_22 , F_20 ( V_22 -> V_61 [ V_60 ] ) ,
V_60 == V_22 -> V_59 - 1 ? L_23 : L_24 ) ;
}
if ( V_22 -> V_62 != 0xffff )
F_18 ( V_7 , L_25 ,
V_22 -> V_62 , V_22 -> V_63 ,
V_22 -> V_64 ) ;
if ( V_22 -> V_65 != 0xffff )
F_18 ( V_7 , L_26 ,
V_22 -> V_65 , V_22 -> V_66 ,
V_22 -> V_67 ) ;
if ( V_22 -> V_68 )
F_18 ( V_7 , L_27 , V_22 -> V_68 ) ;
if ( V_22 -> V_69 )
F_18 ( V_7 , L_28 , V_22 -> V_69 ) ;
if ( V_22 -> V_70 >= 0 )
F_18 ( V_7 , L_29 , V_22 -> V_70 ) ;
F_18 ( V_7 , L_30 ) ;
if ( V_22 -> V_37 & V_38 )
F_18 ( V_7 , L_31 ) ;
if ( V_22 -> V_37 & V_71 )
F_18 ( V_7 , L_32 ) ;
if ( V_22 -> V_37 & V_72 )
F_18 ( V_7 , L_33 ) ;
if ( V_22 -> V_37 & V_73 )
F_18 ( V_7 , L_34 ) ;
if ( V_22 -> V_37 & V_74 )
F_18 ( V_7 , L_35 ) ;
if ( V_22 -> V_37 & V_75 )
F_18 ( V_7 , L_36 ) ;
if ( V_22 -> V_37 & V_76 )
F_18 ( V_7 , L_37 ) ;
if ( V_22 -> V_37 & V_77 )
F_18 ( V_7 , L_38 ) ;
if ( V_22 -> V_37 & V_78 )
F_18 ( V_7 , L_39 ) ;
if ( V_22 -> V_32 ) {
if ( V_22 -> V_37 & V_79 )
F_18 ( V_7 , L_40 ) ;
else
F_18 ( V_7 , L_41 ) ;
}
#ifdef F_21
if ( V_22 -> V_37 & V_80 )
F_18 ( V_7 , L_42 ) ;
#endif
if ( V_22 -> V_37 & V_81 )
F_18 ( V_7 , L_43 ) ;
if ( V_22 -> V_37 & V_82 )
F_18 ( V_7 , L_44 ) ;
if ( V_22 -> V_37 & V_83 )
F_18 ( V_7 , L_45 ) ;
if ( V_22 -> V_37 & V_84 )
F_18 ( V_7 , L_46 ) ;
if ( V_22 -> V_37 & V_85 )
F_18 ( V_7 , L_47 ) ;
F_6 ( V_7 , L_23 ) ;
V_24 = V_22 -> V_86 ? F_1 () : V_22 -> V_87 ;
V_25 = V_22 -> V_88 ;
F_22 ( V_25 , V_89 ) ;
F_18 ( V_7 ,
L_48 ,
( unsigned long long ) V_22 -> V_90 ,
( unsigned long long ) V_22 -> V_91 ) ;
F_18 ( V_7 ,
L_49 ,
( unsigned long long ) F_23 ( V_22 -> V_92 ) ,
( unsigned long long ) F_23 ( V_24 ) ,
( unsigned long long ) V_25 ) ;
F_18 ( V_7 ,
L_50 ,
V_22 -> V_93 , V_22 -> V_94 ,
V_22 -> V_95 ) ;
if ( V_22 -> V_37 & V_38 ) {
F_18 ( V_7 , L_51 ,
& V_22 -> V_96 ,
& V_22 -> V_97 ) ;
} else
F_18 ( V_7 , L_52 ,
V_22 -> V_98 , V_22 -> V_99 ) ;
F_18 ( V_7 , L_53 ,
V_22 -> V_100 , V_22 -> V_101 ) ;
F_18 ( V_7 , L_54 , V_22 -> V_102 ) ;
F_18 ( V_7 , L_55 , V_22 -> V_103 ) ;
if ( V_22 -> V_104 [ 0 ] )
F_18 ( V_7 , L_56 , V_22 -> V_104 ) ;
else
F_18 ( V_7 , L_57 ) ;
return 0 ;
}
static int F_24 ( const char T_3 * V_105 , unsigned long V_106 ,
T_7 * V_107 )
{
int V_60 = 0 ;
* V_107 = 0 ;
for (; V_60 < V_106 ; V_60 ++ ) {
int V_108 ;
char V_109 ;
* V_107 <<= 4 ;
if ( F_25 ( V_109 , & V_105 [ V_60 ] ) )
return - V_19 ;
V_108 = F_26 ( V_109 ) ;
if ( V_108 >= 0 )
* V_107 |= V_108 ;
else
break;
}
return V_60 ;
}
static int F_27 ( const char T_3 * V_105 ,
unsigned int V_106 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_106 ; V_60 ++ ) {
char V_109 ;
if ( F_25 ( V_109 , & V_105 [ V_60 ] ) )
return - V_19 ;
switch ( V_109 ) {
case '\"' :
case '\n' :
case '\r' :
case '\t' :
case ' ' :
case '=' :
break;
default:
goto V_110;
}
}
V_110:
return V_60 ;
}
static long F_28 ( const char T_3 * V_105 , unsigned long V_106 ,
unsigned long * V_107 )
{
int V_60 ;
* V_107 = 0 ;
for ( V_60 = 0 ; V_60 < V_106 ; V_60 ++ ) {
char V_109 ;
if ( F_25 ( V_109 , & V_105 [ V_60 ] ) )
return - V_19 ;
if ( ( V_109 >= '0' ) && ( V_109 <= '9' ) ) {
* V_107 *= 10 ;
* V_107 += V_109 - '0' ;
} else
break;
}
return V_60 ;
}
static int F_29 ( const char T_3 * V_105 , unsigned int V_106 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_106 ; V_60 ++ ) {
char V_109 ;
if ( F_25 ( V_109 , & V_105 [ V_60 ] ) )
return - V_19 ;
switch ( V_109 ) {
case '\"' :
case '\n' :
case '\r' :
case '\t' :
case ' ' :
goto V_111;
break;
default:
break;
}
}
V_111:
return V_60 ;
}
static T_2 F_30 ( const char T_3 * V_112 , struct V_21 * V_22 )
{
unsigned int V_113 = 0 ;
char V_109 ;
T_2 V_60 = 0 ;
int V_114 ;
V_22 -> V_59 = 0 ;
do {
T_7 V_115 ;
V_114 = F_24 ( & V_112 [ V_60 ] , 8 , & V_115 ) ;
if ( V_114 <= 0 )
return V_114 ;
V_22 -> V_61 [ V_113 ] = F_31 ( V_115 ) ;
if ( V_22 -> V_61 [ V_113 ] & V_116 )
V_22 -> V_37 |= V_76 ;
V_60 += V_114 ;
if ( F_25 ( V_109 , & V_112 [ V_60 ] ) )
return - V_19 ;
V_60 ++ ;
V_113 ++ ;
if ( V_113 >= V_117 )
return - V_118 ;
} while ( V_109 == ',' );
V_22 -> V_59 = V_113 ;
return V_60 ;
}
static T_2 F_32 ( struct V_10 * V_10 ,
const char T_3 * V_105 , T_4 V_12 ,
T_5 * V_119 )
{
struct V_6 * V_7 = V_10 -> V_120 ;
struct V_21 * V_22 = V_7 -> V_23 ;
int V_60 , V_121 , V_114 ;
char V_122 [ 16 ] , V_123 [ 32 ] ;
unsigned long V_108 = 0 ;
char * V_124 = NULL ;
int V_115 = 0 ;
char V_11 [ 128 ] ;
V_124 = & ( V_22 -> V_104 [ 0 ] ) ;
if ( V_12 < 1 ) {
F_13 ( L_58 ) ;
return - V_125 ;
}
V_121 = V_12 ;
V_115 = F_27 ( V_105 , V_121 ) ;
if ( V_115 < 0 ) {
F_13 ( L_59 ) ;
return V_115 ;
}
V_60 = V_115 ;
V_114 = F_29 ( & V_105 [ V_60 ] , sizeof( V_122 ) - 1 ) ;
if ( V_114 < 0 )
return V_114 ;
memset ( V_122 , 0 , sizeof( V_122 ) ) ;
if ( F_9 ( V_122 , & V_105 [ V_60 ] , V_114 ) )
return - V_19 ;
V_60 += V_114 ;
V_121 = V_12 - V_60 ;
V_114 = F_27 ( & V_105 [ V_60 ] , V_121 ) ;
if ( V_114 < 0 )
return V_114 ;
V_60 += V_114 ;
if ( V_126 ) {
T_4 V_127 = F_33 ( T_4 , V_12 , 1023 ) ;
char V_128 [ V_127 + 1 ] ;
if ( F_9 ( V_128 , V_105 , V_127 ) )
return - V_19 ;
V_128 [ V_127 ] = 0 ;
F_34 ( L_60 ,
V_122 , ( unsigned long ) V_12 , V_128 ) ;
}
if ( ! strcmp ( V_122 , L_61 ) ) {
V_114 = F_28 ( & V_105 [ V_60 ] , 10 , & V_108 ) ;
if ( V_114 < 0 )
return V_114 ;
V_60 += V_114 ;
if ( V_108 < 14 + 20 + 8 )
V_108 = 14 + 20 + 8 ;
if ( V_108 != V_22 -> V_26 ) {
V_22 -> V_26 = V_108 ;
V_22 -> V_129 = V_108 ;
}
sprintf ( V_124 , L_62 ,
V_22 -> V_26 ) ;
return V_12 ;
}
if ( ! strcmp ( V_122 , L_63 ) ) {
V_114 = F_28 ( & V_105 [ V_60 ] , 10 , & V_108 ) ;
if ( V_114 < 0 )
return V_114 ;
V_60 += V_114 ;
if ( V_108 < 14 + 20 + 8 )
V_108 = 14 + 20 + 8 ;
if ( V_108 != V_22 -> V_27 ) {
V_22 -> V_27 = V_108 ;
V_22 -> V_129 = V_108 ;
}
sprintf ( V_124 , L_64 ,
V_22 -> V_27 ) ;
return V_12 ;
}
if ( ! strcmp ( V_122 , L_65 ) ) {
V_114 = F_28 ( & V_105 [ V_60 ] , 10 , & V_108 ) ;
if ( V_114 < 0 )
return V_114 ;
V_60 += V_114 ;
if ( V_108 < 14 + 20 + 8 )
V_108 = 14 + 20 + 8 ;
if ( V_108 != V_22 -> V_26 ) {
V_22 -> V_26 = V_108 ;
V_22 -> V_27 = V_108 ;
V_22 -> V_129 = V_108 ;
}
sprintf ( V_124 , L_66 , V_22 -> V_26 ) ;
return V_12 ;
}
if ( ! strcmp ( V_122 , L_67 ) ) {
V_114 = F_28 ( & V_105 [ V_60 ] , 10 , & V_108 ) ;
if ( V_114 < 0 )
return V_114 ;
V_60 += V_114 ;
V_126 = V_108 ;
sprintf ( V_124 , L_68 , V_126 ) ;
return V_12 ;
}
if ( ! strcmp ( V_122 , L_69 ) ) {
V_114 = F_28 ( & V_105 [ V_60 ] , 10 , & V_108 ) ;
if ( V_114 < 0 )
return V_114 ;
V_60 += V_114 ;
V_22 -> V_28 = V_108 ;
sprintf ( V_124 , L_70 , V_22 -> V_28 ) ;
return V_12 ;
}
if ( ! strcmp ( V_122 , L_71 ) ) {
V_114 = F_28 ( & V_105 [ V_60 ] , 10 , & V_108 ) ;
if ( V_114 < 0 )
return V_114 ;
V_60 += V_114 ;
if ( V_108 == 0x7FFFFFFF )
V_22 -> V_29 = V_130 ;
else
V_22 -> V_29 = ( T_6 ) V_108 ;
sprintf ( V_124 , L_72 ,
( unsigned long long ) V_22 -> V_29 ) ;
return V_12 ;
}
if ( ! strcmp ( V_122 , L_73 ) ) {
V_114 = F_28 ( & V_105 [ V_60 ] , 10 , & V_108 ) ;
if ( V_114 < 0 )
return V_114 ;
V_60 += V_114 ;
if ( ! V_108 )
return V_114 ;
V_22 -> V_29 = V_22 -> V_26 * 8 * V_89 / V_108 ;
if ( V_126 )
F_35 ( L_74 , V_22 -> V_29 ) ;
sprintf ( V_124 , L_75 , V_108 ) ;
return V_12 ;
}
if ( ! strcmp ( V_122 , L_76 ) ) {
V_114 = F_28 ( & V_105 [ V_60 ] , 10 , & V_108 ) ;
if ( V_114 < 0 )
return V_114 ;
V_60 += V_114 ;
if ( ! V_108 )
return V_114 ;
V_22 -> V_29 = V_131 / V_108 ;
if ( V_126 )
F_35 ( L_74 , V_22 -> V_29 ) ;
sprintf ( V_124 , L_75 , V_108 ) ;
return V_12 ;
}
if ( ! strcmp ( V_122 , L_77 ) ) {
V_114 = F_28 ( & V_105 [ V_60 ] , 10 , & V_108 ) ;
if ( V_114 < 0 )
return V_114 ;
V_60 += V_114 ;
if ( V_108 != V_22 -> V_53 ) {
V_22 -> V_53 = V_108 ;
V_22 -> V_101 = V_108 ;
}
sprintf ( V_124 , L_78 , V_22 -> V_53 ) ;
return V_12 ;
}
if ( ! strcmp ( V_122 , L_79 ) ) {
V_114 = F_28 ( & V_105 [ V_60 ] , 10 , & V_108 ) ;
if ( V_114 < 0 )
return V_114 ;
V_60 += V_114 ;
if ( V_108 != V_22 -> V_55 ) {
V_22 -> V_55 = V_108 ;
V_22 -> V_100 = V_108 ;
}
sprintf ( V_124 , L_80 , V_22 -> V_55 ) ;
return V_12 ;
}
if ( ! strcmp ( V_122 , L_81 ) ) {
V_114 = F_28 ( & V_105 [ V_60 ] , 10 , & V_108 ) ;
if ( V_114 < 0 )
return V_114 ;
V_60 += V_114 ;
if ( V_108 != V_22 -> V_54 ) {
V_22 -> V_54 = V_108 ;
V_22 -> V_101 = V_108 ;
}
sprintf ( V_124 , L_82 , V_22 -> V_54 ) ;
return V_12 ;
}
if ( ! strcmp ( V_122 , L_83 ) ) {
V_114 = F_28 ( & V_105 [ V_60 ] , 10 , & V_108 ) ;
if ( V_114 < 0 )
return V_114 ;
V_60 += V_114 ;
if ( V_108 != V_22 -> V_56 ) {
V_22 -> V_56 = V_108 ;
V_22 -> V_100 = V_108 ;
}
sprintf ( V_124 , L_84 , V_22 -> V_56 ) ;
return V_12 ;
}
if ( ! strcmp ( V_122 , L_85 ) ) {
V_114 = F_28 ( & V_105 [ V_60 ] , 10 , & V_108 ) ;
if ( V_114 < 0 )
return V_114 ;
if ( ( V_108 > 0 ) &&
( ! ( V_22 -> V_50 -> V_132 & V_133 ) ) )
return - V_134 ;
V_60 += V_114 ;
V_22 -> V_30 = V_108 ;
sprintf ( V_124 , L_86 , V_22 -> V_30 ) ;
return V_12 ;
}
if ( ! strcmp ( V_122 , L_87 ) ) {
V_114 = F_28 ( & V_105 [ V_60 ] , 10 , & V_108 ) ;
if ( V_114 < 0 )
return V_114 ;
V_60 += V_114 ;
V_22 -> V_12 = V_108 ;
sprintf ( V_124 , L_88 ,
( unsigned long long ) V_22 -> V_12 ) ;
return V_12 ;
}
if ( ! strcmp ( V_122 , L_89 ) ) {
V_114 = F_28 ( & V_105 [ V_60 ] , 10 , & V_108 ) ;
if ( V_114 < 0 )
return V_114 ;
V_60 += V_114 ;
if ( V_22 -> V_57 != V_108 ) {
V_22 -> V_57 = V_108 ;
V_22 -> V_95 = 0 ;
}
sprintf ( V_124 , L_90 ,
V_22 -> V_57 ) ;
return V_12 ;
}
if ( ! strcmp ( V_122 , L_91 ) ) {
V_114 = F_28 ( & V_105 [ V_60 ] , 10 , & V_108 ) ;
if ( V_114 < 0 )
return V_114 ;
V_60 += V_114 ;
if ( V_22 -> V_58 != V_108 ) {
V_22 -> V_58 = V_108 ;
V_22 -> V_94 = 0 ;
}
sprintf ( V_124 , L_92 ,
V_22 -> V_58 ) ;
return V_12 ;
}
if ( ! strcmp ( V_122 , L_93 ) ) {
V_114 = F_28 ( & V_105 [ V_60 ] , 10 , & V_108 ) ;
if ( V_114 < 0 )
return V_114 ;
V_60 += V_114 ;
if ( F_36 ( V_108 ) ) {
V_22 -> V_70 = V_108 ;
sprintf ( V_124 , L_94 , V_22 -> V_70 ) ;
if ( V_22 -> V_135 ) {
F_37 ( V_22 -> V_135 ) ;
V_22 -> V_135 = NULL ;
}
}
else
sprintf ( V_124 , L_95 ) ;
return V_12 ;
}
if ( ! strcmp ( V_122 , L_96 ) ) {
char V_136 [ 32 ] ;
memset ( V_136 , 0 , 32 ) ;
V_114 = F_29 ( & V_105 [ V_60 ] , sizeof( V_136 ) - 1 ) ;
if ( V_114 < 0 )
return V_114 ;
if ( F_9 ( V_136 , & V_105 [ V_60 ] , V_114 ) )
return - V_19 ;
V_60 += V_114 ;
if ( strcmp ( V_136 , L_97 ) == 0 )
V_22 -> V_37 |= V_71 ;
else if ( strcmp ( V_136 , L_98 ) == 0 )
V_22 -> V_37 &= ~ V_71 ;
else if ( strcmp ( V_136 , L_99 ) == 0 )
V_22 -> V_37 |= V_73 ;
else if ( strcmp ( V_136 , L_100 ) == 0 )
V_22 -> V_37 &= ~ V_73 ;
else if ( strcmp ( V_136 , L_101 ) == 0 )
V_22 -> V_37 |= V_72 ;
else if ( strcmp ( V_136 , L_102 ) == 0 )
V_22 -> V_37 &= ~ V_72 ;
else if ( strcmp ( V_136 , L_103 ) == 0 )
V_22 -> V_37 |= V_74 ;
else if ( strcmp ( V_136 , L_104 ) == 0 )
V_22 -> V_37 &= ~ V_74 ;
else if ( strcmp ( V_136 , L_105 ) == 0 )
V_22 -> V_37 |= V_75 ;
else if ( strcmp ( V_136 , L_106 ) == 0 )
V_22 -> V_37 &= ~ V_75 ;
else if ( strcmp ( V_136 , L_107 ) == 0 )
V_22 -> V_37 |= V_81 ;
else if ( strcmp ( V_136 , L_108 ) == 0 )
V_22 -> V_37 &= ~ V_81 ;
else if ( strcmp ( V_136 , L_109 ) == 0 )
V_22 -> V_37 |= V_82 ;
else if ( strcmp ( V_136 , L_110 ) == 0 )
V_22 -> V_37 &= ~ V_82 ;
else if ( strcmp ( V_136 , L_111 ) == 0 )
V_22 -> V_37 |= V_76 ;
else if ( strcmp ( V_136 , L_112 ) == 0 )
V_22 -> V_37 &= ~ V_76 ;
else if ( strcmp ( V_136 , L_113 ) == 0 )
V_22 -> V_37 |= V_83 ;
else if ( strcmp ( V_136 , L_114 ) == 0 )
V_22 -> V_37 &= ~ V_83 ;
else if ( strcmp ( V_136 , L_115 ) == 0 )
V_22 -> V_37 |= V_84 ;
else if ( strcmp ( V_136 , L_116 ) == 0 )
V_22 -> V_37 &= ~ V_84 ;
else if ( strcmp ( V_136 , L_117 ) == 0 )
V_22 -> V_37 |= V_79 ;
else if ( strcmp ( V_136 , L_118 ) == 0 )
V_22 -> V_37 |= V_77 ;
else if ( strcmp ( V_136 , L_119 ) == 0 )
V_22 -> V_37 &= ~ V_77 ;
else if ( strcmp ( V_136 , L_120 ) == 0 )
V_22 -> V_37 |= V_78 ;
else if ( strcmp ( V_136 , L_121 ) == 0 )
V_22 -> V_37 &= ~ V_78 ;
#ifdef F_21
else if ( strcmp ( V_136 , L_122 ) == 0 )
V_22 -> V_37 |= V_80 ;
#endif
else if ( strcmp ( V_136 , L_123 ) == 0 )
V_22 -> V_37 &= ~ V_38 ;
else if ( strcmp ( V_136 , L_124 ) == 0 )
V_22 -> V_37 |= V_85 ;
else if ( strcmp ( V_136 , L_125 ) == 0 )
V_22 -> V_37 &= ~ V_85 ;
else {
sprintf ( V_124 ,
L_126 ,
V_136 ,
L_127
L_128 ) ;
return V_12 ;
}
sprintf ( V_124 , L_129 , V_22 -> V_37 ) ;
return V_12 ;
}
if ( ! strcmp ( V_122 , L_130 ) || ! strcmp ( V_122 , L_131 ) ) {
V_114 = F_29 ( & V_105 [ V_60 ] , sizeof( V_22 -> V_45 ) - 1 ) ;
if ( V_114 < 0 )
return V_114 ;
if ( F_9 ( V_11 , & V_105 [ V_60 ] , V_114 ) )
return - V_19 ;
V_11 [ V_114 ] = 0 ;
if ( strcmp ( V_11 , V_22 -> V_45 ) != 0 ) {
memset ( V_22 -> V_45 , 0 , sizeof( V_22 -> V_45 ) ) ;
strncpy ( V_22 -> V_45 , V_11 , V_114 ) ;
V_22 -> V_137 = F_38 ( V_22 -> V_45 ) ;
V_22 -> V_99 = V_22 -> V_137 ;
}
if ( V_126 )
F_34 ( L_132 , V_22 -> V_45 ) ;
V_60 += V_114 ;
sprintf ( V_124 , L_133 , V_22 -> V_45 ) ;
return V_12 ;
}
if ( ! strcmp ( V_122 , L_134 ) ) {
V_114 = F_29 ( & V_105 [ V_60 ] , sizeof( V_22 -> V_46 ) - 1 ) ;
if ( V_114 < 0 )
return V_114 ;
if ( F_9 ( V_11 , & V_105 [ V_60 ] , V_114 ) )
return - V_19 ;
V_11 [ V_114 ] = 0 ;
if ( strcmp ( V_11 , V_22 -> V_46 ) != 0 ) {
memset ( V_22 -> V_46 , 0 , sizeof( V_22 -> V_46 ) ) ;
strncpy ( V_22 -> V_46 , V_11 , V_114 ) ;
V_22 -> V_138 = F_38 ( V_22 -> V_46 ) ;
V_22 -> V_99 = V_22 -> V_138 ;
}
if ( V_126 )
F_34 ( L_135 , V_22 -> V_46 ) ;
V_60 += V_114 ;
sprintf ( V_124 , L_136 , V_22 -> V_46 ) ;
return V_12 ;
}
if ( ! strcmp ( V_122 , L_137 ) ) {
V_114 = F_29 ( & V_105 [ V_60 ] , sizeof( V_11 ) - 1 ) ;
if ( V_114 < 0 )
return V_114 ;
V_22 -> V_37 |= V_38 ;
if ( F_9 ( V_11 , & V_105 [ V_60 ] , V_114 ) )
return - V_19 ;
V_11 [ V_114 ] = 0 ;
F_39 ( V_11 , V_22 -> V_42 . V_139 ) ;
snprintf ( V_11 , sizeof( V_11 ) , L_138 , & V_22 -> V_42 ) ;
V_22 -> V_97 = V_22 -> V_42 ;
if ( V_126 )
F_34 ( L_139 , V_11 ) ;
V_60 += V_114 ;
sprintf ( V_124 , L_140 , V_11 ) ;
return V_12 ;
}
if ( ! strcmp ( V_122 , L_141 ) ) {
V_114 = F_29 ( & V_105 [ V_60 ] , sizeof( V_11 ) - 1 ) ;
if ( V_114 < 0 )
return V_114 ;
V_22 -> V_37 |= V_38 ;
if ( F_9 ( V_11 , & V_105 [ V_60 ] , V_114 ) )
return - V_19 ;
V_11 [ V_114 ] = 0 ;
F_39 ( V_11 , V_22 -> V_43 . V_139 ) ;
snprintf ( V_11 , sizeof( V_11 ) , L_138 , & V_22 -> V_43 ) ;
V_22 -> V_97 = V_22 -> V_43 ;
if ( V_126 )
F_34 ( L_142 , V_11 ) ;
V_60 += V_114 ;
sprintf ( V_124 , L_143 , V_11 ) ;
return V_12 ;
}
if ( ! strcmp ( V_122 , L_144 ) ) {
V_114 = F_29 ( & V_105 [ V_60 ] , sizeof( V_11 ) - 1 ) ;
if ( V_114 < 0 )
return V_114 ;
V_22 -> V_37 |= V_38 ;
if ( F_9 ( V_11 , & V_105 [ V_60 ] , V_114 ) )
return - V_19 ;
V_11 [ V_114 ] = 0 ;
F_39 ( V_11 , V_22 -> V_44 . V_139 ) ;
snprintf ( V_11 , sizeof( V_11 ) , L_138 , & V_22 -> V_44 ) ;
if ( V_126 )
F_34 ( L_145 , V_11 ) ;
V_60 += V_114 ;
sprintf ( V_124 , L_146 , V_11 ) ;
return V_12 ;
}
if ( ! strcmp ( V_122 , L_147 ) ) {
V_114 = F_29 ( & V_105 [ V_60 ] , sizeof( V_11 ) - 1 ) ;
if ( V_114 < 0 )
return V_114 ;
V_22 -> V_37 |= V_38 ;
if ( F_9 ( V_11 , & V_105 [ V_60 ] , V_114 ) )
return - V_19 ;
V_11 [ V_114 ] = 0 ;
F_39 ( V_11 , V_22 -> V_39 . V_139 ) ;
snprintf ( V_11 , sizeof( V_11 ) , L_138 , & V_22 -> V_39 ) ;
V_22 -> V_96 = V_22 -> V_39 ;
if ( V_126 )
F_34 ( L_148 , V_11 ) ;
V_60 += V_114 ;
sprintf ( V_124 , L_149 , V_11 ) ;
return V_12 ;
}
if ( ! strcmp ( V_122 , L_150 ) ) {
V_114 = F_29 ( & V_105 [ V_60 ] , sizeof( V_22 -> V_47 ) - 1 ) ;
if ( V_114 < 0 )
return V_114 ;
if ( F_9 ( V_11 , & V_105 [ V_60 ] , V_114 ) )
return - V_19 ;
V_11 [ V_114 ] = 0 ;
if ( strcmp ( V_11 , V_22 -> V_47 ) != 0 ) {
memset ( V_22 -> V_47 , 0 , sizeof( V_22 -> V_47 ) ) ;
strncpy ( V_22 -> V_47 , V_11 , V_114 ) ;
V_22 -> V_140 = F_38 ( V_22 -> V_47 ) ;
V_22 -> V_98 = V_22 -> V_140 ;
}
if ( V_126 )
F_34 ( L_151 , V_22 -> V_47 ) ;
V_60 += V_114 ;
sprintf ( V_124 , L_152 , V_22 -> V_47 ) ;
return V_12 ;
}
if ( ! strcmp ( V_122 , L_153 ) ) {
V_114 = F_29 ( & V_105 [ V_60 ] , sizeof( V_22 -> V_48 ) - 1 ) ;
if ( V_114 < 0 )
return V_114 ;
if ( F_9 ( V_11 , & V_105 [ V_60 ] , V_114 ) )
return - V_19 ;
V_11 [ V_114 ] = 0 ;
if ( strcmp ( V_11 , V_22 -> V_48 ) != 0 ) {
memset ( V_22 -> V_48 , 0 , sizeof( V_22 -> V_48 ) ) ;
strncpy ( V_22 -> V_48 , V_11 , V_114 ) ;
V_22 -> V_141 = F_38 ( V_22 -> V_48 ) ;
V_22 -> V_98 = V_22 -> V_141 ;
}
if ( V_126 )
F_34 ( L_154 , V_22 -> V_48 ) ;
V_60 += V_114 ;
sprintf ( V_124 , L_155 , V_22 -> V_48 ) ;
return V_12 ;
}
if ( ! strcmp ( V_122 , L_156 ) ) {
V_114 = F_29 ( & V_105 [ V_60 ] , sizeof( V_123 ) - 1 ) ;
if ( V_114 < 0 )
return V_114 ;
memset ( V_123 , 0 , sizeof( V_123 ) ) ;
if ( F_9 ( V_123 , & V_105 [ V_60 ] , V_114 ) )
return - V_19 ;
if ( ! F_40 ( V_123 , V_22 -> V_52 ) )
return - V_125 ;
memcpy ( & V_22 -> V_142 [ 0 ] , V_22 -> V_52 , V_143 ) ;
sprintf ( V_124 , L_157 , V_22 -> V_52 ) ;
return V_12 ;
}
if ( ! strcmp ( V_122 , L_158 ) ) {
V_114 = F_29 ( & V_105 [ V_60 ] , sizeof( V_123 ) - 1 ) ;
if ( V_114 < 0 )
return V_114 ;
memset ( V_123 , 0 , sizeof( V_123 ) ) ;
if ( F_9 ( V_123 , & V_105 [ V_60 ] , V_114 ) )
return - V_19 ;
if ( ! F_40 ( V_123 , V_22 -> V_49 ) )
return - V_125 ;
memcpy ( & V_22 -> V_142 [ 6 ] , V_22 -> V_49 , V_143 ) ;
sprintf ( V_124 , L_159 , V_22 -> V_49 ) ;
return V_12 ;
}
if ( ! strcmp ( V_122 , L_160 ) ) {
F_41 ( V_22 ) ;
sprintf ( V_124 , L_161 ) ;
return V_12 ;
}
if ( ! strcmp ( V_122 , L_162 ) ) {
V_114 = F_28 ( & V_105 [ V_60 ] , 10 , & V_108 ) ;
if ( V_114 < 0 )
return V_114 ;
V_60 += V_114 ;
if ( V_108 > V_144 )
V_108 = V_144 ;
V_22 -> V_32 = V_108 ;
sprintf ( V_124 , L_163 , V_22 -> V_32 ) ;
return V_12 ;
}
if ( ! strcmp ( V_122 , L_164 ) ) {
V_114 = F_28 ( & V_105 [ V_60 ] , 10 , & V_108 ) ;
if ( V_114 < 0 )
return V_114 ;
V_60 += V_114 ;
V_22 -> V_33 = V_108 ;
sprintf ( V_124 , L_165 , V_22 -> V_33 ) ;
return V_12 ;
}
if ( ! strcmp ( V_122 , L_166 ) ) {
V_114 = F_28 ( & V_105 [ V_60 ] , 5 , & V_108 ) ;
if ( V_114 < 0 )
return V_114 ;
V_60 += V_114 ;
V_22 -> V_34 = V_108 ;
sprintf ( V_124 , L_167 , V_22 -> V_34 ) ;
return V_12 ;
}
if ( ! strcmp ( V_122 , L_168 ) ) {
V_114 = F_28 ( & V_105 [ V_60 ] , 5 , & V_108 ) ;
if ( V_114 < 0 )
return V_114 ;
V_60 += V_114 ;
V_22 -> V_35 = V_108 ;
sprintf ( V_124 , L_169 , V_22 -> V_35 ) ;
return V_12 ;
}
if ( ! strcmp ( V_122 , L_170 ) ) {
unsigned int V_113 , V_145 ;
V_114 = F_30 ( & V_105 [ V_60 ] , V_22 ) ;
if ( V_114 < 0 )
return V_114 ;
V_60 += V_114 ;
V_145 = sprintf ( V_124 , L_171 ) ;
for ( V_113 = 0 ; V_113 < V_22 -> V_59 ; V_113 ++ )
V_145 += sprintf ( V_124 + V_145 ,
L_22 , F_20 ( V_22 -> V_61 [ V_113 ] ) ,
V_113 == V_22 -> V_59 - 1 ? L_172 : L_173 ) ;
if ( V_22 -> V_59 && V_22 -> V_62 != 0xffff ) {
V_22 -> V_62 = 0xffff ;
V_22 -> V_65 = 0xffff ;
if ( V_126 )
F_34 ( L_174 ) ;
}
return V_12 ;
}
if ( ! strcmp ( V_122 , L_175 ) ) {
V_114 = F_28 ( & V_105 [ V_60 ] , 4 , & V_108 ) ;
if ( V_114 < 0 )
return V_114 ;
V_60 += V_114 ;
if ( V_108 <= 4095 ) {
V_22 -> V_62 = V_108 ;
if ( V_126 )
F_34 ( L_176 ) ;
if ( V_126 && V_22 -> V_59 )
F_34 ( L_177 ) ;
V_22 -> V_59 = 0 ;
sprintf ( V_124 , L_178 , V_22 -> V_62 ) ;
} else {
V_22 -> V_62 = 0xffff ;
V_22 -> V_65 = 0xffff ;
if ( V_126 )
F_34 ( L_179 ) ;
}
return V_12 ;
}
if ( ! strcmp ( V_122 , L_180 ) ) {
V_114 = F_28 ( & V_105 [ V_60 ] , 1 , & V_108 ) ;
if ( V_114 < 0 )
return V_114 ;
V_60 += V_114 ;
if ( ( V_108 <= 7 ) && ( V_22 -> V_62 != 0xffff ) ) {
V_22 -> V_63 = V_108 ;
sprintf ( V_124 , L_181 , V_22 -> V_63 ) ;
} else {
sprintf ( V_124 , L_182 ) ;
}
return V_12 ;
}
if ( ! strcmp ( V_122 , L_183 ) ) {
V_114 = F_28 ( & V_105 [ V_60 ] , 1 , & V_108 ) ;
if ( V_114 < 0 )
return V_114 ;
V_60 += V_114 ;
if ( ( V_108 <= 1 ) && ( V_22 -> V_62 != 0xffff ) ) {
V_22 -> V_64 = V_108 ;
sprintf ( V_124 , L_184 , V_22 -> V_64 ) ;
} else {
sprintf ( V_124 , L_185 ) ;
}
return V_12 ;
}
if ( ! strcmp ( V_122 , L_186 ) ) {
V_114 = F_28 ( & V_105 [ V_60 ] , 4 , & V_108 ) ;
if ( V_114 < 0 )
return V_114 ;
V_60 += V_114 ;
if ( ( V_108 <= 4095 ) && ( ( V_22 -> V_62 != 0xffff ) ) ) {
V_22 -> V_65 = V_108 ;
if ( V_126 )
F_34 ( L_187 ) ;
if ( V_126 && V_22 -> V_59 )
F_34 ( L_177 ) ;
V_22 -> V_59 = 0 ;
sprintf ( V_124 , L_188 , V_22 -> V_65 ) ;
} else {
V_22 -> V_62 = 0xffff ;
V_22 -> V_65 = 0xffff ;
if ( V_126 )
F_34 ( L_179 ) ;
}
return V_12 ;
}
if ( ! strcmp ( V_122 , L_189 ) ) {
V_114 = F_28 ( & V_105 [ V_60 ] , 1 , & V_108 ) ;
if ( V_114 < 0 )
return V_114 ;
V_60 += V_114 ;
if ( ( V_108 <= 7 ) && ( V_22 -> V_65 != 0xffff ) ) {
V_22 -> V_66 = V_108 ;
sprintf ( V_124 , L_190 , V_22 -> V_66 ) ;
} else {
sprintf ( V_124 , L_191 ) ;
}
return V_12 ;
}
if ( ! strcmp ( V_122 , L_192 ) ) {
V_114 = F_28 ( & V_105 [ V_60 ] , 1 , & V_108 ) ;
if ( V_114 < 0 )
return V_114 ;
V_60 += V_114 ;
if ( ( V_108 <= 1 ) && ( V_22 -> V_65 != 0xffff ) ) {
V_22 -> V_67 = V_108 ;
sprintf ( V_124 , L_193 , V_22 -> V_67 ) ;
} else {
sprintf ( V_124 , L_194 ) ;
}
return V_12 ;
}
if ( ! strcmp ( V_122 , L_195 ) ) {
T_7 V_146 = 0 ;
V_114 = F_24 ( & V_105 [ V_60 ] , 2 , & V_146 ) ;
if ( V_114 < 0 )
return V_114 ;
V_60 += V_114 ;
if ( V_114 == 2 ) {
V_22 -> V_68 = V_146 ;
sprintf ( V_124 , L_196 , V_22 -> V_68 ) ;
} else {
sprintf ( V_124 , L_197 ) ;
}
return V_12 ;
}
if ( ! strcmp ( V_122 , L_198 ) ) {
T_7 V_146 = 0 ;
V_114 = F_24 ( & V_105 [ V_60 ] , 2 , & V_146 ) ;
if ( V_114 < 0 )
return V_114 ;
V_60 += V_114 ;
if ( V_114 == 2 ) {
V_22 -> V_69 = V_146 ;
sprintf ( V_124 , L_199 , V_22 -> V_69 ) ;
} else {
sprintf ( V_124 , L_200 ) ;
}
return V_12 ;
}
if ( ! strcmp ( V_122 , L_201 ) ) {
V_114 = F_28 ( & V_105 [ V_60 ] , 9 , & V_108 ) ;
if ( V_114 < 0 )
return V_114 ;
V_60 += V_114 ;
V_22 -> V_36 = V_108 ;
sprintf ( V_124 , L_202 ,
V_22 -> V_36 ) ;
return V_12 ;
}
sprintf ( V_22 -> V_104 , L_203 , V_122 ) ;
return - V_125 ;
}
static int F_42 ( struct V_20 * V_20 , struct V_10 * V_10 )
{
return F_15 ( V_10 , F_17 , F_16 ( V_20 ) -> V_15 ) ;
}
static int F_43 ( struct V_6 * V_7 , void * V_8 )
{
struct V_147 * V_148 = V_7 -> V_23 ;
const struct V_21 * V_22 ;
F_44 ( ! V_148 ) ;
F_18 ( V_7 , L_204 ) ;
F_45 ( V_148 ) ;
F_46 (pkt_dev, &t->if_list, list)
if ( V_22 -> V_86 )
F_18 ( V_7 , L_205 , V_22 -> V_31 ) ;
F_18 ( V_7 , L_206 ) ;
F_46 (pkt_dev, &t->if_list, list)
if ( ! V_22 -> V_86 )
F_18 ( V_7 , L_205 , V_22 -> V_31 ) ;
if ( V_148 -> V_104 [ 0 ] )
F_18 ( V_7 , L_207 , V_148 -> V_104 ) ;
else
F_18 ( V_7 , L_208 ) ;
F_47 ( V_148 ) ;
return 0 ;
}
static T_2 F_48 ( struct V_10 * V_10 ,
const char T_3 * V_105 ,
T_4 V_12 , T_5 * V_119 )
{
struct V_6 * V_7 = V_10 -> V_120 ;
struct V_147 * V_148 = V_7 -> V_23 ;
int V_60 , V_121 , V_114 , V_149 ;
char V_122 [ 40 ] ;
char * V_124 ;
if ( V_12 < 1 ) {
return - V_125 ;
}
V_121 = V_12 ;
V_114 = F_27 ( V_105 , V_121 ) ;
if ( V_114 < 0 )
return V_114 ;
V_60 = V_114 ;
V_114 = F_29 ( & V_105 [ V_60 ] , sizeof( V_122 ) - 1 ) ;
if ( V_114 < 0 )
return V_114 ;
memset ( V_122 , 0 , sizeof( V_122 ) ) ;
if ( F_9 ( V_122 , & V_105 [ V_60 ] , V_114 ) )
return - V_19 ;
V_60 += V_114 ;
V_121 = V_12 - V_60 ;
V_114 = F_27 ( & V_105 [ V_60 ] , V_121 ) ;
if ( V_114 < 0 )
return V_114 ;
V_60 += V_114 ;
if ( V_126 )
F_34 ( L_209 , V_122 , ( unsigned long ) V_12 ) ;
if ( ! V_148 ) {
F_49 ( L_210 ) ;
V_149 = - V_125 ;
goto V_18;
}
V_124 = & ( V_148 -> V_104 [ 0 ] ) ;
if ( ! strcmp ( V_122 , L_211 ) ) {
char V_136 [ 32 ] ;
memset ( V_136 , 0 , 32 ) ;
V_114 = F_29 ( & V_105 [ V_60 ] , sizeof( V_136 ) - 1 ) ;
if ( V_114 < 0 ) {
V_149 = V_114 ;
goto V_18;
}
if ( F_9 ( V_136 , & V_105 [ V_60 ] , V_114 ) )
return - V_19 ;
V_60 += V_114 ;
F_50 ( & V_150 ) ;
F_51 ( V_148 , V_136 ) ;
F_52 ( & V_150 ) ;
V_149 = V_12 ;
sprintf ( V_124 , L_212 , V_136 ) ;
goto V_18;
}
if ( ! strcmp ( V_122 , L_213 ) ) {
F_50 ( & V_150 ) ;
V_148 -> V_151 |= V_152 ;
F_52 ( & V_150 ) ;
F_53 ( F_54 ( 125 ) ) ;
V_149 = V_12 ;
sprintf ( V_124 , L_214 ) ;
goto V_18;
}
if ( ! strcmp ( V_122 , L_215 ) ) {
sprintf ( V_124 , L_216 ) ;
V_149 = V_12 ;
goto V_18;
}
V_149 = - V_125 ;
V_18:
return V_149 ;
}
static int F_55 ( struct V_20 * V_20 , struct V_10 * V_10 )
{
return F_15 ( V_10 , F_43 , F_16 ( V_20 ) -> V_15 ) ;
}
static struct V_21 * F_56 ( const char * V_153 , int remove )
{
struct V_147 * V_148 ;
struct V_21 * V_22 = NULL ;
bool V_154 = ( remove == V_155 ) ;
F_46 (t, &pktgen_threads, th_list) {
V_22 = F_57 ( V_148 , V_153 , V_154 ) ;
if ( V_22 ) {
if ( remove ) {
F_45 ( V_148 ) ;
V_22 -> V_156 = 1 ;
V_148 -> V_151 |= V_157 ;
F_47 ( V_148 ) ;
}
break;
}
}
return V_22 ;
}
static void F_58 ( const char * V_153 )
{
struct V_21 * V_22 = NULL ;
const int V_158 = 10 , V_159 = 125 ;
int V_60 = 0 ;
F_50 ( & V_150 ) ;
F_34 ( L_217 , V_160 , V_153 ) ;
while ( 1 ) {
V_22 = F_56 ( V_153 , REMOVE ) ;
if ( V_22 == NULL )
break;
F_52 ( & V_150 ) ;
F_34 ( L_218 ,
V_160 , V_153 ) ;
F_53 ( F_54 ( V_159 ) ) ;
F_50 ( & V_150 ) ;
if ( ++ V_60 >= V_158 ) {
F_49 ( L_219 ,
V_160 , V_159 * V_60 , V_153 ) ;
break;
}
}
F_52 ( & V_150 ) ;
}
static void F_59 ( struct V_161 * V_162 )
{
struct V_147 * V_148 ;
F_46 (t, &pktgen_threads, th_list) {
struct V_21 * V_22 ;
F_46 (pkt_dev, &t->if_list, list) {
if ( V_22 -> V_50 != V_162 )
continue;
F_60 ( V_22 -> V_163 -> V_122 , V_164 ) ;
V_22 -> V_163 = F_61 ( V_162 -> V_122 , 0600 ,
V_164 ,
& V_165 ,
V_22 ) ;
if ( ! V_22 -> V_163 )
F_49 ( L_220 ,
V_162 -> V_122 ) ;
break;
}
}
}
static int F_62 ( struct V_166 * V_167 ,
unsigned long V_168 , void * V_169 )
{
struct V_161 * V_162 = V_169 ;
if ( ! F_63 ( F_64 ( V_162 ) , & V_170 ) || V_171 )
return V_172 ;
switch ( V_168 ) {
case V_173 :
F_59 ( V_162 ) ;
break;
case V_174 :
F_58 ( V_162 -> V_122 ) ;
break;
}
return V_172 ;
}
static struct V_161 * F_65 ( struct V_21 * V_22 ,
const char * V_153 )
{
char V_175 [ V_176 + 5 ] ;
int V_60 ;
for ( V_60 = 0 ; V_153 [ V_60 ] != '@' ; V_60 ++ ) {
if ( V_60 == V_176 )
break;
V_175 [ V_60 ] = V_153 [ V_60 ] ;
}
V_175 [ V_60 ] = 0 ;
return F_66 ( & V_170 , V_175 ) ;
}
static int F_67 ( struct V_21 * V_22 , const char * V_153 )
{
struct V_161 * V_50 ;
int V_14 ;
if ( V_22 -> V_50 ) {
F_68 ( V_22 -> V_50 ) ;
V_22 -> V_50 = NULL ;
}
V_50 = F_65 ( V_22 , V_153 ) ;
if ( ! V_50 ) {
F_49 ( L_221 , V_153 ) ;
return - V_177 ;
}
if ( V_50 -> type != V_178 ) {
F_49 ( L_222 , V_153 ) ;
V_14 = - V_125 ;
} else if ( ! F_69 ( V_50 ) ) {
F_49 ( L_223 , V_153 ) ;
V_14 = - V_179 ;
} else {
V_22 -> V_50 = V_50 ;
return 0 ;
}
F_68 ( V_50 ) ;
return V_14 ;
}
static void F_70 ( struct V_21 * V_22 )
{
int V_180 ;
if ( ! V_22 -> V_50 ) {
F_49 ( L_224 ) ;
sprintf ( V_22 -> V_104 ,
L_225 ) ;
return;
}
V_180 = V_22 -> V_50 -> V_181 ;
if ( V_180 <= V_22 -> V_34 ) {
F_13 ( L_226 ,
V_22 -> V_34 , ( V_180 ? : 1 ) - 1 , V_180 ,
V_22 -> V_31 ) ;
V_22 -> V_34 = ( V_180 ? : 1 ) - 1 ;
}
if ( V_22 -> V_35 >= V_180 ) {
F_13 ( L_227 ,
V_22 -> V_35 , ( V_180 ? : 1 ) - 1 , V_180 ,
V_22 -> V_31 ) ;
V_22 -> V_35 = ( V_180 ? : 1 ) - 1 ;
}
if ( F_19 ( V_22 -> V_49 ) )
memcpy ( & ( V_22 -> V_142 [ 6 ] ) , V_22 -> V_50 -> V_51 , V_143 ) ;
memcpy ( & ( V_22 -> V_142 [ 0 ] ) , V_22 -> V_52 , V_143 ) ;
V_22 -> V_129 = V_22 -> V_26 ;
if ( V_22 -> V_37 & V_38 ) {
#ifdef F_71
int V_60 , V_182 = 0 , V_14 = 1 ;
struct V_183 * V_184 ;
for ( V_60 = 0 ; V_60 < V_185 ; V_60 ++ )
if ( V_22 -> V_96 . V_139 [ V_60 ] ) {
V_182 = 1 ;
break;
}
if ( ! V_182 ) {
F_72 () ;
V_184 = F_73 ( V_22 -> V_50 ) ;
if ( V_184 ) {
struct V_186 * V_187 ;
F_74 ( & V_184 -> V_188 ) ;
for ( V_187 = V_184 -> V_189 ; V_187 ;
V_187 = V_187 -> V_190 ) {
if ( V_187 -> V_191 == V_192 &&
! ( V_187 -> V_37 & V_193 ) ) {
V_22 -> V_96 = V_187 -> V_194 ;
V_14 = 0 ;
break;
}
}
F_75 ( & V_184 -> V_188 ) ;
}
F_76 () ;
if ( V_14 )
F_49 ( L_228 ) ;
}
#endif
} else {
V_22 -> V_140 = 0 ;
V_22 -> V_141 = 0 ;
if ( strlen ( V_22 -> V_47 ) == 0 ) {
struct V_195 * V_196 ;
F_72 () ;
V_196 = F_77 ( V_22 -> V_50 ) ;
if ( V_196 ) {
if ( V_196 -> V_197 ) {
V_22 -> V_140 =
V_196 -> V_197 -> V_198 ;
V_22 -> V_141 = V_22 -> V_140 ;
}
}
F_76 () ;
} else {
V_22 -> V_140 = F_38 ( V_22 -> V_47 ) ;
V_22 -> V_141 = F_38 ( V_22 -> V_48 ) ;
}
V_22 -> V_137 = F_38 ( V_22 -> V_45 ) ;
V_22 -> V_138 = F_38 ( V_22 -> V_46 ) ;
}
V_22 -> V_94 = 0 ;
V_22 -> V_95 = 0 ;
V_22 -> V_98 = V_22 -> V_140 ;
V_22 -> V_99 = V_22 -> V_137 ;
V_22 -> V_100 = V_22 -> V_55 ;
V_22 -> V_101 = V_22 -> V_53 ;
V_22 -> V_103 = 0 ;
}
static void F_78 ( struct V_21 * V_22 , T_1 V_199 )
{
T_1 V_200 , V_201 ;
T_8 V_202 ;
struct V_203 V_148 ;
F_79 ( & V_148 . V_204 , V_205 , V_206 ) ;
F_80 ( & V_148 . V_204 , V_199 ) ;
V_202 = F_81 ( F_82 ( & V_148 . V_204 ) ) ;
if ( V_202 <= 0 ) {
V_22 -> V_207 = F_83 ( V_199 , V_22 -> V_29 ) ;
return;
}
V_200 = F_1 () ;
if ( V_202 < 100000 ) {
do {
V_201 = F_1 () ;
} while ( F_4 ( V_201 , V_199 ) );
} else {
F_84 ( & V_148 , V_208 ) ;
do {
F_85 ( V_209 ) ;
F_86 ( & V_148 . V_204 , V_206 ) ;
if ( ! F_87 ( & V_148 . V_204 ) )
V_148 . V_210 = NULL ;
if ( F_88 ( V_148 . V_210 ) )
F_89 () ;
F_90 ( & V_148 . V_204 ) ;
} while ( V_148 . V_210 && V_22 -> V_86 && ! F_91 ( V_208 ) );
F_92 ( V_211 ) ;
V_201 = F_1 () ;
}
V_22 -> V_88 += F_81 ( F_93 ( V_201 , V_200 ) ) ;
V_22 -> V_207 = F_83 ( V_199 , V_22 -> V_29 ) ;
}
static inline void F_94 ( struct V_21 * V_22 )
{
V_22 -> V_212 = 0 ;
V_22 -> V_212 += V_22 -> V_59 * sizeof( V_213 ) ;
V_22 -> V_212 += F_95 ( V_22 ) ;
V_22 -> V_212 += F_96 ( V_22 ) ;
}
static inline int F_97 ( const struct V_21 * V_22 , int V_214 )
{
return ! ! ( V_22 -> V_215 [ V_214 ] . V_37 & V_216 ) ;
}
static inline int F_98 ( struct V_21 * V_22 )
{
int V_214 = V_22 -> V_217 ;
if ( V_22 -> V_37 & V_79 ) {
if ( V_22 -> V_215 [ V_214 ] . V_12 >= V_22 -> V_33 ) {
V_22 -> V_215 [ V_214 ] . V_12 = 0 ;
V_22 -> V_215 [ V_214 ] . V_37 = 0 ;
V_22 -> V_217 += 1 ;
if ( V_22 -> V_217 >= V_22 -> V_32 )
V_22 -> V_217 = 0 ;
}
} else {
V_214 = F_99 () % V_22 -> V_32 ;
V_22 -> V_217 = V_214 ;
if ( V_22 -> V_215 [ V_214 ] . V_12 > V_22 -> V_33 ) {
V_22 -> V_215 [ V_214 ] . V_12 = 0 ;
V_22 -> V_215 [ V_214 ] . V_37 = 0 ;
}
}
return V_22 -> V_217 ;
}
static void F_100 ( struct V_21 * V_22 , int V_214 )
{
struct V_218 * V_219 = V_22 -> V_215 [ V_214 ] . V_219 ;
if ( ! V_219 ) {
V_219 = F_101 ( & V_170 , V_220 ,
( V_221 * ) & V_22 -> V_99 ,
( V_221 * ) & V_22 -> V_98 ,
V_222 ,
V_22 -> V_223 ,
V_22 -> V_224 , 0 ) ;
if ( V_219 ) {
V_22 -> V_215 [ V_214 ] . V_219 = V_219 ;
F_94 ( V_22 ) ;
V_22 -> V_212 += V_219 -> V_225 . V_226 ;
}
}
}
static void F_102 ( struct V_21 * V_22 )
{
if ( V_22 -> V_37 & V_78 )
V_22 -> V_102 = F_103 () ;
else if ( V_22 -> V_34 <= V_22 -> V_35 ) {
T_9 V_148 ;
if ( V_22 -> V_37 & V_77 ) {
V_148 = F_99 () %
( V_22 -> V_35 -
V_22 -> V_34 + 1 )
+ V_22 -> V_34 ;
} else {
V_148 = V_22 -> V_102 + 1 ;
if ( V_148 > V_22 -> V_35 )
V_148 = V_22 -> V_34 ;
}
V_22 -> V_102 = V_148 ;
}
V_22 -> V_102 = V_22 -> V_102 % V_22 -> V_50 -> V_181 ;
}
static void F_104 ( struct V_21 * V_22 )
{
T_7 V_227 ;
T_7 V_228 ;
int V_214 = 0 ;
if ( V_22 -> V_32 )
V_214 = F_98 ( V_22 ) ;
if ( V_22 -> V_57 > 1 ) {
T_7 V_229 ;
T_7 V_115 ;
if ( V_22 -> V_37 & V_81 )
V_229 = F_99 () % V_22 -> V_57 ;
else {
V_229 = V_22 -> V_95 ++ ;
if ( V_22 -> V_95 >=
V_22 -> V_57 )
V_22 -> V_95 = 0 ;
}
V_115 = V_22 -> V_49 [ 5 ] + ( V_229 & 0xFF ) ;
V_22 -> V_142 [ 11 ] = V_115 ;
V_115 = ( V_22 -> V_49 [ 4 ] + ( ( V_229 >> 8 ) & 0xFF ) + ( V_115 >> 8 ) ) ;
V_22 -> V_142 [ 10 ] = V_115 ;
V_115 = ( V_22 -> V_49 [ 3 ] + ( ( V_229 >> 16 ) & 0xFF ) + ( V_115 >> 8 ) ) ;
V_22 -> V_142 [ 9 ] = V_115 ;
V_115 = ( V_22 -> V_49 [ 2 ] + ( ( V_229 >> 24 ) & 0xFF ) + ( V_115 >> 8 ) ) ;
V_22 -> V_142 [ 8 ] = V_115 ;
V_115 = ( V_22 -> V_49 [ 1 ] + ( V_115 >> 8 ) ) ;
V_22 -> V_142 [ 7 ] = V_115 ;
}
if ( V_22 -> V_58 > 1 ) {
T_7 V_229 ;
T_7 V_115 ;
if ( V_22 -> V_37 & V_82 )
V_229 = F_99 () % V_22 -> V_58 ;
else {
V_229 = V_22 -> V_94 ++ ;
if ( V_22 -> V_94 >=
V_22 -> V_58 ) {
V_22 -> V_94 = 0 ;
}
}
V_115 = V_22 -> V_52 [ 5 ] + ( V_229 & 0xFF ) ;
V_22 -> V_142 [ 5 ] = V_115 ;
V_115 = ( V_22 -> V_52 [ 4 ] + ( ( V_229 >> 8 ) & 0xFF ) + ( V_115 >> 8 ) ) ;
V_22 -> V_142 [ 4 ] = V_115 ;
V_115 = ( V_22 -> V_52 [ 3 ] + ( ( V_229 >> 16 ) & 0xFF ) + ( V_115 >> 8 ) ) ;
V_22 -> V_142 [ 3 ] = V_115 ;
V_115 = ( V_22 -> V_52 [ 2 ] + ( ( V_229 >> 24 ) & 0xFF ) + ( V_115 >> 8 ) ) ;
V_22 -> V_142 [ 2 ] = V_115 ;
V_115 = ( V_22 -> V_52 [ 1 ] + ( V_115 >> 8 ) ) ;
V_22 -> V_142 [ 1 ] = V_115 ;
}
if ( V_22 -> V_37 & V_76 ) {
unsigned int V_60 ;
for ( V_60 = 0 ; V_60 < V_22 -> V_59 ; V_60 ++ )
if ( V_22 -> V_61 [ V_60 ] & V_116 )
V_22 -> V_61 [ V_60 ] = V_116 |
( ( V_230 V_231 ) F_99 () &
F_31 ( 0x000fffff ) ) ;
}
if ( ( V_22 -> V_37 & V_83 ) && ( V_22 -> V_62 != 0xffff ) ) {
V_22 -> V_62 = F_99 () & ( 4096 - 1 ) ;
}
if ( ( V_22 -> V_37 & V_84 ) && ( V_22 -> V_65 != 0xffff ) ) {
V_22 -> V_65 = F_99 () & ( 4096 - 1 ) ;
}
if ( V_22 -> V_53 < V_22 -> V_54 ) {
if ( V_22 -> V_37 & V_74 )
V_22 -> V_101 = F_99 () %
( V_22 -> V_54 - V_22 -> V_53 )
+ V_22 -> V_53 ;
else {
V_22 -> V_101 ++ ;
if ( V_22 -> V_101 >= V_22 -> V_54 )
V_22 -> V_101 = V_22 -> V_53 ;
}
}
if ( V_22 -> V_55 < V_22 -> V_56 ) {
if ( V_22 -> V_37 & V_75 ) {
V_22 -> V_100 = F_99 () %
( V_22 -> V_56 - V_22 -> V_55 )
+ V_22 -> V_55 ;
} else {
V_22 -> V_100 ++ ;
if ( V_22 -> V_100 >= V_22 -> V_56 )
V_22 -> V_100 = V_22 -> V_55 ;
}
}
if ( ! ( V_22 -> V_37 & V_38 ) ) {
V_227 = F_20 ( V_22 -> V_140 ) ;
V_228 = F_20 ( V_22 -> V_141 ) ;
if ( V_227 < V_228 ) {
T_7 V_148 ;
if ( V_22 -> V_37 & V_71 )
V_148 = F_99 () % ( V_228 - V_227 ) + V_227 ;
else {
V_148 = F_20 ( V_22 -> V_98 ) ;
V_148 ++ ;
if ( V_148 > V_228 )
V_148 = V_227 ;
}
V_22 -> V_98 = F_31 ( V_148 ) ;
}
if ( V_22 -> V_32 && F_97 ( V_22 , V_214 ) ) {
V_22 -> V_99 = V_22 -> V_215 [ V_214 ] . V_99 ;
} else {
V_227 = F_20 ( V_22 -> V_137 ) ;
V_228 = F_20 ( V_22 -> V_138 ) ;
if ( V_227 < V_228 ) {
T_7 V_148 ;
V_231 V_232 ;
if ( V_22 -> V_37 & V_72 ) {
V_148 = F_99 () % ( V_228 - V_227 ) + V_227 ;
V_232 = F_31 ( V_148 ) ;
while ( F_105 ( V_232 ) ||
F_106 ( V_232 ) ||
F_107 ( V_232 ) ||
F_108 ( V_232 ) ||
F_109 ( V_232 ) ) {
V_148 = F_99 () % ( V_228 - V_227 ) + V_227 ;
V_232 = F_31 ( V_148 ) ;
}
V_22 -> V_99 = V_232 ;
} else {
V_148 = F_20 ( V_22 -> V_99 ) ;
V_148 ++ ;
if ( V_148 > V_228 ) {
V_148 = V_227 ;
}
V_22 -> V_99 = F_31 ( V_148 ) ;
}
}
if ( V_22 -> V_32 ) {
V_22 -> V_215 [ V_214 ] . V_37 |= V_216 ;
V_22 -> V_215 [ V_214 ] . V_99 =
V_22 -> V_99 ;
#ifdef F_21
if ( V_22 -> V_37 & V_80 )
F_100 ( V_22 , V_214 ) ;
#endif
V_22 -> V_103 ++ ;
}
}
} else {
if ( V_22 -> V_43 . V_233 [ 0 ] == 0 &&
V_22 -> V_43 . V_233 [ 1 ] == 0 &&
V_22 -> V_43 . V_233 [ 2 ] == 0 &&
V_22 -> V_43 . V_233 [ 3 ] == 0 ) ;
else {
int V_60 ;
for ( V_60 = 0 ; V_60 < 4 ; V_60 ++ ) {
V_22 -> V_97 . V_233 [ V_60 ] =
( ( ( V_230 V_231 ) F_99 () |
V_22 -> V_43 . V_233 [ V_60 ] ) &
V_22 -> V_44 . V_233 [ V_60 ] ) ;
}
}
}
if ( V_22 -> V_26 < V_22 -> V_27 ) {
T_7 V_148 ;
if ( V_22 -> V_37 & V_73 ) {
V_148 = F_99 () %
( V_22 -> V_27 - V_22 -> V_26 )
+ V_22 -> V_26 ;
} else {
V_148 = V_22 -> V_129 + 1 ;
if ( V_148 > V_22 -> V_27 )
V_148 = V_22 -> V_26 ;
}
V_22 -> V_129 = V_148 ;
}
F_102 ( V_22 ) ;
V_22 -> V_215 [ V_214 ] . V_12 ++ ;
}
static int F_110 ( struct V_234 * V_235 , struct V_21 * V_22 )
{
struct V_218 * V_219 = V_22 -> V_215 [ V_22 -> V_217 ] . V_219 ;
int V_14 = 0 ;
if ( ! V_219 )
return 0 ;
if ( V_219 -> V_225 . V_236 != V_237 )
return 0 ;
F_111 ( & V_219 -> V_188 ) ;
V_14 = V_219 -> V_238 -> V_239 ( V_219 , V_235 ) ;
if ( V_14 )
goto error;
V_14 = V_219 -> type -> V_239 ( V_219 , V_235 ) ;
if ( V_14 )
goto error;
V_219 -> V_240 . V_241 += V_235 -> V_114 ;
V_219 -> V_240 . V_242 ++ ;
error:
F_112 ( & V_219 -> V_188 ) ;
return V_14 ;
}
static void F_113 ( struct V_21 * V_22 )
{
if ( V_22 -> V_32 ) {
int V_60 ;
for ( V_60 = 0 ; V_60 < V_22 -> V_32 ; V_60 ++ ) {
struct V_218 * V_219 = V_22 -> V_215 [ V_60 ] . V_219 ;
if ( V_219 ) {
F_114 ( V_219 ) ;
V_22 -> V_215 [ V_60 ] . V_219 = NULL ;
}
}
}
}
static int F_115 ( struct V_21 * V_22 ,
struct V_234 * V_235 , T_10 V_243 )
{
if ( V_22 -> V_37 & V_80 ) {
struct V_218 * V_219 = V_22 -> V_215 [ V_22 -> V_217 ] . V_219 ;
int V_244 = 0 ;
if ( V_219 ) {
int V_149 ;
T_11 * V_245 ;
V_244 = V_219 -> V_225 . V_226 - F_116 ( V_235 ) ;
if ( V_244 > 0 ) {
V_149 = F_117 ( V_235 , V_244 , 0 , V_246 ) ;
if ( V_149 < 0 ) {
F_49 ( L_229 ,
V_149 ) ;
goto V_14;
}
}
F_118 ( V_235 , V_247 ) ;
V_149 = F_110 ( V_235 , V_22 ) ;
if ( V_149 ) {
F_49 ( L_230 , V_149 ) ;
goto V_14;
}
V_245 = ( T_11 * ) F_119 ( V_235 , V_247 ) ;
memcpy ( V_245 , V_22 -> V_142 , 12 ) ;
* ( V_248 * ) & V_245 [ 12 ] = V_243 ;
}
}
return 1 ;
V_14:
F_120 ( V_235 ) ;
return 0 ;
}
static void F_121 ( V_231 * V_249 , struct V_21 * V_22 )
{
unsigned int V_60 ;
for ( V_60 = 0 ; V_60 < V_22 -> V_59 ; V_60 ++ )
* V_249 ++ = V_22 -> V_61 [ V_60 ] & ~ V_116 ;
V_249 -- ;
* V_249 |= V_116 ;
}
static inline T_10 F_122 ( unsigned int V_250 , unsigned int V_251 ,
unsigned int V_252 )
{
return F_123 ( V_250 | ( V_251 << 12 ) | ( V_252 << 13 ) ) ;
}
static void F_124 ( struct V_21 * V_22 , struct V_234 * V_235 ,
int V_253 )
{
struct V_254 V_255 ;
struct V_256 * V_257 ;
V_257 = (struct V_256 * ) F_125 ( V_235 , sizeof( * V_257 ) ) ;
V_253 -= sizeof( * V_257 ) ;
if ( V_22 -> V_28 <= 0 ) {
memset ( F_125 ( V_235 , V_253 ) , 0 , V_253 ) ;
} else {
int V_258 = V_22 -> V_28 ;
int V_60 , V_114 ;
int V_259 ;
if ( V_258 > V_260 )
V_258 = V_260 ;
V_114 = V_253 - V_258 * V_261 ;
if ( V_114 > 0 ) {
memset ( F_125 ( V_235 , V_114 ) , 0 , V_114 ) ;
V_253 = V_258 * V_261 ;
}
V_60 = 0 ;
V_259 = ( V_253 / V_258 ) < V_261 ?
( V_253 / V_258 ) : V_261 ;
while ( V_253 > 0 ) {
if ( F_126 ( ! V_22 -> V_135 ) ) {
int V_70 = F_127 () ;
if ( V_22 -> V_70 >= 0 && ( V_22 -> V_37 & V_85 ) )
V_70 = V_22 -> V_70 ;
V_22 -> V_135 = F_128 ( V_70 , V_262 | V_263 , 0 ) ;
if ( ! V_22 -> V_135 )
break;
}
F_129 ( V_22 -> V_135 ) ;
F_130 ( V_235 , V_60 , V_22 -> V_135 ) ;
F_131 ( V_235 ) -> V_258 [ V_60 ] . V_264 = 0 ;
if ( V_60 == ( V_258 - 1 ) )
F_132 ( & F_131 ( V_235 ) -> V_258 [ V_60 ] ,
( V_253 < V_261 ? V_253 : V_261 ) ) ;
else
F_132 ( & F_131 ( V_235 ) -> V_258 [ V_60 ] , V_259 ) ;
V_253 -= F_133 ( & F_131 ( V_235 ) -> V_258 [ V_60 ] ) ;
V_235 -> V_114 += F_133 ( & F_131 ( V_235 ) -> V_258 [ V_60 ] ) ;
V_235 -> V_265 += F_133 ( & F_131 ( V_235 ) -> V_258 [ V_60 ] ) ;
V_60 ++ ;
F_131 ( V_235 ) -> V_266 = V_60 ;
}
}
V_257 -> V_267 = F_31 ( V_268 ) ;
V_257 -> V_93 = F_31 ( V_22 -> V_93 ) ;
F_134 ( & V_255 ) ;
V_257 -> V_269 = F_31 ( V_255 . V_269 ) ;
V_257 -> V_270 = F_31 ( V_255 . V_270 ) ;
}
static struct V_234 * F_135 ( struct V_161 * V_50 ,
struct V_21 * V_22 )
{
struct V_234 * V_235 = NULL ;
T_11 * V_245 ;
struct V_271 * V_272 ;
int V_253 , V_273 ;
struct V_274 * V_275 ;
T_10 V_243 = F_123 ( V_276 ) ;
V_231 * V_249 ;
T_10 * V_277 = NULL ;
T_10 * V_278 = NULL ;
T_10 * V_279 = NULL ;
T_10 * V_280 = NULL ;
V_248 V_281 ;
if ( V_22 -> V_59 )
V_243 = F_123 ( V_282 ) ;
if ( V_22 -> V_62 != 0xffff )
V_243 = F_123 ( V_283 ) ;
F_104 ( V_22 ) ;
V_281 = V_22 -> V_102 ;
V_253 = ( V_50 -> V_284 + 16 ) & ~ 0xf ;
if ( V_22 -> V_37 & V_85 ) {
int V_70 ;
if ( V_22 -> V_70 >= 0 )
V_70 = V_22 -> V_70 ;
else
V_70 = F_127 () ;
V_235 = F_136 ( V_285 + V_22 -> V_129 + 64
+ V_253 + V_22 -> V_212 , V_286 , 0 , V_70 ) ;
if ( F_88 ( V_235 ) ) {
F_137 ( V_235 , V_285 ) ;
V_235 -> V_162 = V_50 ;
}
}
else
V_235 = F_138 ( V_50 ,
V_22 -> V_129 + 64
+ V_253 + V_22 -> V_212 , V_286 ) ;
if ( ! V_235 ) {
sprintf ( V_22 -> V_104 , L_231 ) ;
return NULL ;
}
F_139 ( V_235 -> V_15 ) ;
F_137 ( V_235 , V_253 ) ;
V_245 = ( T_11 * ) F_119 ( V_235 , 14 ) ;
V_249 = ( V_231 * ) F_125 ( V_235 , V_22 -> V_59 * sizeof( T_7 ) ) ;
if ( V_22 -> V_59 )
F_121 ( V_249 , V_22 ) ;
if ( V_22 -> V_62 != 0xffff ) {
if ( V_22 -> V_65 != 0xffff ) {
V_279 = ( T_10 * ) F_125 ( V_235 , sizeof( T_10 ) ) ;
* V_279 = F_122 ( V_22 -> V_65 ,
V_22 -> V_67 ,
V_22 -> V_66 ) ;
V_280 = ( T_10 * ) F_125 ( V_235 , sizeof( T_10 ) ) ;
* V_280 = F_123 ( V_283 ) ;
}
V_277 = ( T_10 * ) F_125 ( V_235 , sizeof( T_10 ) ) ;
* V_277 = F_122 ( V_22 -> V_62 ,
V_22 -> V_64 ,
V_22 -> V_63 ) ;
V_278 = ( T_10 * ) F_125 ( V_235 , sizeof( T_10 ) ) ;
* V_278 = F_123 ( V_276 ) ;
}
V_235 -> V_287 = V_235 -> V_288 ;
V_235 -> V_289 = V_235 -> V_287 + sizeof( struct V_274 ) ;
F_125 ( V_235 , sizeof( struct V_274 ) + sizeof( struct V_271 ) ) ;
F_140 ( V_235 , V_281 ) ;
V_235 -> V_290 = V_22 -> V_36 ;
V_275 = F_141 ( V_235 ) ;
V_272 = F_142 ( V_235 ) ;
memcpy ( V_245 , V_22 -> V_142 , 12 ) ;
* ( T_10 * ) & V_245 [ 12 ] = V_243 ;
V_253 = V_22 -> V_129 - 14 - 20 - 8 -
V_22 -> V_212 ;
if ( V_253 < 0 || V_253 < sizeof( struct V_256 ) )
V_253 = sizeof( struct V_256 ) ;
V_272 -> V_291 = F_123 ( V_22 -> V_101 ) ;
V_272 -> V_292 = F_123 ( V_22 -> V_100 ) ;
V_272 -> V_114 = F_123 ( V_253 + 8 ) ;
V_272 -> V_293 = 0 ;
V_275 -> V_294 = 5 ;
V_275 -> V_9 = 4 ;
V_275 -> V_295 = 32 ;
V_275 -> V_68 = V_22 -> V_68 ;
V_275 -> V_243 = V_296 ;
V_275 -> V_297 = V_22 -> V_98 ;
V_275 -> V_298 = V_22 -> V_99 ;
V_275 -> V_250 = F_123 ( V_22 -> V_299 ) ;
V_22 -> V_299 ++ ;
V_275 -> V_300 = 0 ;
V_273 = 20 + 8 + V_253 ;
V_275 -> V_301 = F_123 ( V_273 ) ;
V_275 -> V_293 = 0 ;
V_275 -> V_293 = F_143 ( ( void * ) V_275 , V_275 -> V_294 ) ;
V_235 -> V_243 = V_243 ;
V_235 -> V_302 = ( V_235 -> V_287 - V_247 -
V_22 -> V_212 ) ;
V_235 -> V_162 = V_50 ;
V_235 -> V_303 = V_304 ;
F_124 ( V_22 , V_235 , V_253 ) ;
#ifdef F_21
if ( ! F_115 ( V_22 , V_235 , V_243 ) )
return NULL ;
#endif
return V_235 ;
}
static unsigned int F_39 ( const char * V_232 , char V_305 [ 16 ] )
{
unsigned int V_60 ;
unsigned int V_114 = 0 ;
unsigned long V_306 ;
char V_307 [ 16 ] ;
unsigned int V_308 = 0 ;
unsigned int V_309 = 0 ;
V_231 V_115 ;
char * V_310 ;
for ( V_60 = 0 ; V_60 < 16 ; V_60 ++ )
V_305 [ V_60 ] = 0 ;
for (; ; ) {
if ( * V_232 == ':' ) {
V_114 ++ ;
if ( V_232 [ 1 ] == ':' ) {
V_232 += 2 ;
V_114 ++ ;
break;
}
V_232 ++ ;
}
V_306 = F_144 ( V_232 , & V_310 , 16 ) ;
V_60 = V_310 - V_232 ;
if ( ! V_60 )
return 0 ;
if ( V_308 == 12 && V_232 [ V_60 ] == '.' ) {
V_115 = F_38 ( V_232 ) ;
memcpy ( (struct V_311 * ) ( V_305 + 12 ) , & V_115 , sizeof( V_115 ) ) ;
return V_60 + V_114 ;
}
V_305 [ V_308 ++ ] = ( V_306 >> 8 ) ;
V_305 [ V_308 ++ ] = ( V_306 & 255 ) ;
V_232 += V_60 ;
V_114 += V_60 ;
if ( V_308 == 16 )
return V_114 ;
}
for (; ; ) {
if ( * V_232 == ':' ) {
if ( V_309 == 0 )
break;
V_232 ++ ;
V_114 ++ ;
} else if ( V_309 != 0 )
break;
V_306 = F_145 ( V_232 , & V_310 , 16 ) ;
V_60 = V_310 - V_232 ;
if ( ! V_60 ) {
if ( * V_232 )
V_114 -- ;
break;
}
if ( V_309 + V_308 <= 12 && V_232 [ V_60 ] == '.' ) {
V_115 = F_38 ( V_232 ) ;
memcpy ( (struct V_311 * ) ( V_307 + V_309 ) , & V_115 ,
sizeof( V_115 ) ) ;
V_309 += 4 ;
V_114 += strlen ( V_232 ) ;
break;
}
V_307 [ V_309 ++ ] = ( V_306 >> 8 ) ;
V_307 [ V_309 ++ ] = ( V_306 & 255 ) ;
V_232 += V_60 ;
V_114 += V_60 ;
if ( V_308 + V_309 == 16 )
break;
}
for ( V_60 = 0 ; V_60 < V_309 ; V_60 ++ )
V_305 [ 16 - V_309 + V_60 ] = V_307 [ V_60 ] ;
return V_114 ;
}
static struct V_234 * F_146 ( struct V_161 * V_50 ,
struct V_21 * V_22 )
{
struct V_234 * V_235 = NULL ;
T_11 * V_245 ;
struct V_271 * V_272 ;
int V_253 ;
struct V_312 * V_275 ;
T_10 V_243 = F_123 ( V_313 ) ;
V_231 * V_249 ;
T_10 * V_277 = NULL ;
T_10 * V_278 = NULL ;
T_10 * V_279 = NULL ;
T_10 * V_280 = NULL ;
V_248 V_281 ;
if ( V_22 -> V_59 )
V_243 = F_123 ( V_282 ) ;
if ( V_22 -> V_62 != 0xffff )
V_243 = F_123 ( V_283 ) ;
F_104 ( V_22 ) ;
V_281 = V_22 -> V_102 ;
V_235 = F_138 ( V_50 ,
V_22 -> V_129 + 64
+ 16 + V_22 -> V_212 , V_286 ) ;
if ( ! V_235 ) {
sprintf ( V_22 -> V_104 , L_231 ) ;
return NULL ;
}
F_139 ( V_235 -> V_15 ) ;
F_137 ( V_235 , 16 ) ;
V_245 = ( T_11 * ) F_119 ( V_235 , 14 ) ;
V_249 = ( V_231 * ) F_125 ( V_235 , V_22 -> V_59 * sizeof( T_7 ) ) ;
if ( V_22 -> V_59 )
F_121 ( V_249 , V_22 ) ;
if ( V_22 -> V_62 != 0xffff ) {
if ( V_22 -> V_65 != 0xffff ) {
V_279 = ( T_10 * ) F_125 ( V_235 , sizeof( T_10 ) ) ;
* V_279 = F_122 ( V_22 -> V_65 ,
V_22 -> V_67 ,
V_22 -> V_66 ) ;
V_280 = ( T_10 * ) F_125 ( V_235 , sizeof( T_10 ) ) ;
* V_280 = F_123 ( V_283 ) ;
}
V_277 = ( T_10 * ) F_125 ( V_235 , sizeof( T_10 ) ) ;
* V_277 = F_122 ( V_22 -> V_62 ,
V_22 -> V_64 ,
V_22 -> V_63 ) ;
V_278 = ( T_10 * ) F_125 ( V_235 , sizeof( T_10 ) ) ;
* V_278 = F_123 ( V_313 ) ;
}
V_235 -> V_287 = V_235 -> V_288 ;
V_235 -> V_289 = V_235 -> V_287 + sizeof( struct V_312 ) ;
F_125 ( V_235 , sizeof( struct V_312 ) + sizeof( struct V_271 ) ) ;
F_140 ( V_235 , V_281 ) ;
V_235 -> V_290 = V_22 -> V_36 ;
V_275 = F_147 ( V_235 ) ;
V_272 = F_142 ( V_235 ) ;
memcpy ( V_245 , V_22 -> V_142 , 12 ) ;
* ( T_10 * ) & V_245 [ 12 ] = V_243 ;
V_253 = V_22 -> V_129 - 14 -
sizeof( struct V_312 ) - sizeof( struct V_271 ) -
V_22 -> V_212 ;
if ( V_253 < sizeof( struct V_256 ) ) {
V_253 = sizeof( struct V_256 ) ;
F_148 ( L_232 , V_253 ) ;
}
V_272 -> V_291 = F_123 ( V_22 -> V_101 ) ;
V_272 -> V_292 = F_123 ( V_22 -> V_100 ) ;
V_272 -> V_114 = F_123 ( V_253 + sizeof( struct V_271 ) ) ;
V_272 -> V_293 = 0 ;
* ( V_231 * ) V_275 = F_31 ( 0x60000000 ) ;
if ( V_22 -> V_69 ) {
* ( V_231 * ) V_275 |= F_31 ( 0x60000000 | ( V_22 -> V_69 << 20 ) ) ;
}
V_275 -> V_314 = 32 ;
V_275 -> V_315 = F_123 ( sizeof( struct V_271 ) + V_253 ) ;
V_275 -> V_316 = V_296 ;
V_275 -> V_298 = V_22 -> V_97 ;
V_275 -> V_297 = V_22 -> V_96 ;
V_235 -> V_302 = ( V_235 -> V_287 - V_247 -
V_22 -> V_212 ) ;
V_235 -> V_243 = V_243 ;
V_235 -> V_162 = V_50 ;
V_235 -> V_303 = V_304 ;
F_124 ( V_22 , V_235 , V_253 ) ;
return V_235 ;
}
static struct V_234 * F_149 ( struct V_161 * V_50 ,
struct V_21 * V_22 )
{
if ( V_22 -> V_37 & V_38 )
return F_146 ( V_50 , V_22 ) ;
else
return F_135 ( V_50 , V_22 ) ;
}
static void F_41 ( struct V_21 * V_22 )
{
V_22 -> V_93 = 1 ;
V_22 -> V_88 = 0 ;
V_22 -> V_90 = 0 ;
V_22 -> V_317 = 0 ;
V_22 -> V_91 = 0 ;
}
static void F_150 ( struct V_147 * V_148 )
{
struct V_21 * V_22 ;
int V_318 = 0 ;
F_151 () ;
F_45 ( V_148 ) ;
F_46 (pkt_dev, &t->if_list, list) {
F_70 ( V_22 ) ;
if ( V_22 -> V_50 ) {
F_41 ( V_22 ) ;
V_22 -> V_86 = 1 ;
V_22 -> V_235 = NULL ;
V_22 -> V_92 =
V_22 -> V_207 = F_1 () ;
F_94 ( V_22 ) ;
strcpy ( V_22 -> V_104 , L_233 ) ;
V_318 ++ ;
} else
strcpy ( V_22 -> V_104 , L_234 ) ;
}
F_47 ( V_148 ) ;
if ( V_318 )
V_148 -> V_151 &= ~ ( V_319 ) ;
}
static void F_10 ( void )
{
struct V_147 * V_148 ;
F_151 () ;
F_50 ( & V_150 ) ;
F_46 (t, &pktgen_threads, th_list)
V_148 -> V_151 |= V_319 ;
F_52 ( & V_150 ) ;
}
static int F_152 ( const struct V_147 * V_148 )
{
const struct V_21 * V_22 ;
F_46 (pkt_dev, &t->if_list, list)
if ( V_22 -> V_86 )
return 1 ;
return 0 ;
}
static int F_153 ( struct V_147 * V_148 )
{
F_45 ( V_148 ) ;
while ( F_152 ( V_148 ) ) {
F_47 ( V_148 ) ;
F_154 ( 100 ) ;
if ( F_91 ( V_208 ) )
goto signal;
F_45 ( V_148 ) ;
}
F_47 ( V_148 ) ;
return 1 ;
signal:
return 0 ;
}
static int F_155 ( void )
{
struct V_147 * V_148 ;
int V_320 = 1 ;
F_50 ( & V_150 ) ;
F_46 (t, &pktgen_threads, th_list) {
V_320 = F_153 ( V_148 ) ;
if ( V_320 == 0 )
break;
}
if ( V_320 == 0 )
F_46 (t, &pktgen_threads, th_list)
V_148 -> V_151 |= ( V_319 ) ;
F_52 ( & V_150 ) ;
return V_320 ;
}
static void F_11 ( void )
{
struct V_147 * V_148 ;
F_151 () ;
F_50 ( & V_150 ) ;
F_46 (t, &pktgen_threads, th_list)
V_148 -> V_151 |= ( V_321 ) ;
F_52 ( & V_150 ) ;
F_53 ( F_54 ( 125 ) ) ;
F_155 () ;
}
static void F_12 ( void )
{
struct V_147 * V_148 ;
F_151 () ;
F_50 ( & V_150 ) ;
F_46 (t, &pktgen_threads, th_list)
V_148 -> V_151 |= ( V_152 ) ;
F_52 ( & V_150 ) ;
F_53 ( F_54 ( 125 ) ) ;
F_155 () ;
}
static void F_156 ( struct V_21 * V_22 , int V_266 )
{
T_12 V_322 , V_323 , V_324 ;
char * V_325 = V_22 -> V_104 ;
T_1 V_326 = F_93 ( V_22 -> V_87 ,
V_22 -> V_92 ) ;
T_1 V_25 = F_157 ( V_22 -> V_88 ) ;
V_325 += sprintf ( V_325 , L_235 ,
( unsigned long long ) F_23 ( V_326 ) ,
( unsigned long long ) F_23 ( F_93 ( V_326 , V_25 ) ) ,
( unsigned long long ) F_23 ( V_25 ) ,
( unsigned long long ) V_22 -> V_90 ,
V_22 -> V_129 , V_266 ) ;
V_324 = F_158 ( V_22 -> V_90 * V_131 ,
F_81 ( V_326 ) ) ;
V_322 = V_324 * 8 * V_22 -> V_129 ;
V_323 = V_322 ;
F_22 ( V_323 , 1000000 ) ;
V_325 += sprintf ( V_325 , L_236 ,
( unsigned long long ) V_324 ,
( unsigned long long ) V_323 ,
( unsigned long long ) V_322 ,
( unsigned long long ) V_22 -> V_91 ) ;
}
static int F_159 ( struct V_21 * V_22 )
{
int V_266 = V_22 -> V_235 ? F_131 ( V_22 -> V_235 ) -> V_266 : - 1 ;
if ( ! V_22 -> V_86 ) {
F_13 ( L_237 ,
V_22 -> V_31 ) ;
return - V_125 ;
}
F_120 ( V_22 -> V_235 ) ;
V_22 -> V_235 = NULL ;
V_22 -> V_87 = F_1 () ;
V_22 -> V_86 = 0 ;
F_156 ( V_22 , V_266 ) ;
return 0 ;
}
static struct V_21 * F_160 ( struct V_147 * V_148 )
{
struct V_21 * V_22 , * V_327 = NULL ;
F_45 ( V_148 ) ;
F_46 (pkt_dev, &t->if_list, list) {
if ( ! V_22 -> V_86 )
continue;
if ( V_327 == NULL )
V_327 = V_22 ;
else if ( F_4 ( V_22 -> V_207 , V_327 -> V_207 ) )
V_327 = V_22 ;
}
F_47 ( V_148 ) ;
return V_327 ;
}
static void F_161 ( struct V_147 * V_148 )
{
struct V_21 * V_22 ;
F_151 () ;
F_45 ( V_148 ) ;
F_46 (pkt_dev, &t->if_list, list) {
F_159 ( V_22 ) ;
}
F_47 ( V_148 ) ;
}
static void F_162 ( struct V_147 * V_148 )
{
struct V_328 * V_329 , * V_113 ;
struct V_21 * V_330 ;
F_151 () ;
F_45 ( V_148 ) ;
F_163 (q, n, &t->if_list) {
V_330 = F_164 ( V_329 , struct V_21 , V_331 ) ;
if ( ! V_330 -> V_156 )
continue;
F_120 ( V_330 -> V_235 ) ;
V_330 -> V_235 = NULL ;
F_165 ( V_148 , V_330 ) ;
break;
}
F_47 ( V_148 ) ;
}
static void F_166 ( struct V_147 * V_148 )
{
struct V_328 * V_329 , * V_113 ;
struct V_21 * V_330 ;
F_151 () ;
F_45 ( V_148 ) ;
F_163 (q, n, &t->if_list) {
V_330 = F_164 ( V_329 , struct V_21 , V_331 ) ;
F_120 ( V_330 -> V_235 ) ;
V_330 -> V_235 = NULL ;
F_165 ( V_148 , V_330 ) ;
}
F_47 ( V_148 ) ;
}
static void F_167 ( struct V_147 * V_148 )
{
F_60 ( V_148 -> V_332 -> V_333 , V_164 ) ;
}
static void F_168 ( struct V_21 * V_22 )
{
T_1 V_334 = F_1 () ;
F_89 () ;
V_22 -> V_88 += F_81 ( F_93 ( F_1 () , V_334 ) ) ;
}
static void F_169 ( struct V_21 * V_22 )
{
T_1 V_334 = F_1 () ;
while ( F_170 ( & ( V_22 -> V_235 -> V_335 ) ) != 1 ) {
if ( F_91 ( V_208 ) )
break;
if ( F_171 () )
F_168 ( V_22 ) ;
else
F_172 () ;
}
V_22 -> V_88 += F_81 ( F_93 ( F_1 () , V_334 ) ) ;
}
static void F_173 ( struct V_21 * V_22 )
{
struct V_161 * V_50 = V_22 -> V_50 ;
T_13 (* F_174)( struct V_234 * , struct V_161 * )
= V_50 -> V_336 -> V_337 ;
struct V_338 * V_339 ;
V_248 V_281 ;
int V_149 ;
if ( F_126 ( ! F_69 ( V_50 ) || ! F_175 ( V_50 ) ) ) {
F_159 ( V_22 ) ;
return;
}
if ( F_126 ( V_22 -> V_29 == V_130 ) ) {
V_22 -> V_207 = F_83 ( F_1 () , V_340 ) ;
return;
}
if ( ! V_22 -> V_235 || ( V_22 -> V_341 &&
++ V_22 -> V_342 >= V_22 -> V_30 ) ) {
F_120 ( V_22 -> V_235 ) ;
V_22 -> V_235 = F_149 ( V_50 , V_22 ) ;
if ( V_22 -> V_235 == NULL ) {
F_49 ( L_238 ) ;
F_89 () ;
V_22 -> V_342 -- ;
return;
}
V_22 -> V_343 = V_22 -> V_235 -> V_114 ;
V_22 -> V_344 ++ ;
V_22 -> V_342 = 0 ;
}
if ( V_22 -> V_29 && V_22 -> V_341 )
F_78 ( V_22 , V_22 -> V_207 ) ;
V_281 = F_176 ( V_22 -> V_235 ) ;
V_339 = F_177 ( V_50 , V_281 ) ;
F_178 ( V_339 ) ;
if ( F_126 ( F_179 ( V_339 ) ) ) {
V_149 = V_345 ;
V_22 -> V_341 = 0 ;
goto V_346;
}
F_180 ( & ( V_22 -> V_235 -> V_335 ) ) ;
V_149 = (* F_174)( V_22 -> V_235 , V_50 ) ;
switch ( V_149 ) {
case V_347 :
F_181 ( V_339 ) ;
V_22 -> V_341 = 1 ;
V_22 -> V_90 ++ ;
V_22 -> V_93 ++ ;
V_22 -> V_317 += V_22 -> V_343 ;
break;
case V_348 :
case V_349 :
case V_350 :
V_22 -> V_91 ++ ;
break;
default:
F_148 ( L_239 ,
V_22 -> V_31 , V_149 ) ;
V_22 -> V_91 ++ ;
case V_351 :
case V_345 :
F_182 ( & ( V_22 -> V_235 -> V_335 ) ) ;
V_22 -> V_341 = 0 ;
}
V_346:
F_183 ( V_339 ) ;
if ( ( V_22 -> V_12 != 0 ) && ( V_22 -> V_90 >= V_22 -> V_12 ) ) {
F_169 ( V_22 ) ;
F_159 ( V_22 ) ;
}
}
static int F_184 ( void * V_352 )
{
F_185 ( V_353 ) ;
struct V_147 * V_148 = V_352 ;
struct V_21 * V_22 = NULL ;
int V_354 = V_148 -> V_354 ;
F_44 ( F_103 () != V_354 ) ;
F_186 ( & V_148 -> V_355 ) ;
F_187 ( & V_148 -> V_356 ) ;
F_34 ( L_240 , V_354 , F_188 ( V_208 ) ) ;
F_85 ( V_209 ) ;
F_189 () ;
while ( ! F_190 () ) {
V_22 = F_160 ( V_148 ) ;
if ( F_126 ( ! V_22 && V_148 -> V_151 == 0 ) ) {
if ( V_171 )
break;
F_191 ( V_148 -> V_355 ,
V_148 -> V_151 != 0 ,
V_357 / 10 ) ;
F_192 () ;
continue;
}
F_92 ( V_211 ) ;
if ( F_88 ( V_22 ) ) {
F_173 ( V_22 ) ;
if ( F_171 () )
F_168 ( V_22 ) ;
else
F_172 () ;
}
if ( V_148 -> V_151 & V_319 ) {
F_161 ( V_148 ) ;
V_148 -> V_151 &= ~ ( V_319 ) ;
}
if ( V_148 -> V_151 & V_321 ) {
F_150 ( V_148 ) ;
V_148 -> V_151 &= ~ ( V_321 ) ;
}
if ( V_148 -> V_151 & V_152 ) {
F_166 ( V_148 ) ;
V_148 -> V_151 &= ~ ( V_152 ) ;
}
if ( V_148 -> V_151 & V_157 ) {
F_162 ( V_148 ) ;
V_148 -> V_151 &= ~ ( V_157 ) ;
}
F_192 () ;
F_85 ( V_209 ) ;
}
F_34 ( L_241 , V_148 -> V_332 -> V_333 ) ;
F_161 ( V_148 ) ;
F_34 ( L_242 , V_148 -> V_332 -> V_333 ) ;
F_166 ( V_148 ) ;
F_34 ( L_243 , V_148 -> V_332 -> V_333 ) ;
F_167 ( V_148 ) ;
while ( ! F_190 () ) {
F_85 ( V_209 ) ;
F_89 () ;
}
F_92 ( V_211 ) ;
return 0 ;
}
static struct V_21 * F_57 ( struct V_147 * V_148 ,
const char * V_153 , bool V_154 )
{
struct V_21 * V_325 , * V_22 = NULL ;
T_4 V_114 = strlen ( V_153 ) ;
F_45 ( V_148 ) ;
F_46 (p, &t->if_list, list)
if ( strncmp ( V_325 -> V_31 , V_153 , V_114 ) == 0 ) {
if ( V_325 -> V_31 [ V_114 ] ) {
if ( V_154 || V_325 -> V_31 [ V_114 ] != '@' )
continue;
}
V_22 = V_325 ;
break;
}
F_47 ( V_148 ) ;
F_34 ( L_244 , V_153 , V_22 ) ;
return V_22 ;
}
static int F_193 ( struct V_147 * V_148 ,
struct V_21 * V_22 )
{
int V_358 = 0 ;
F_45 ( V_148 ) ;
if ( V_22 -> V_359 ) {
F_49 ( L_245 ) ;
V_358 = - V_360 ;
goto V_18;
}
F_194 ( & V_22 -> V_331 , & V_148 -> V_361 ) ;
V_22 -> V_359 = V_148 ;
V_22 -> V_86 = 0 ;
V_18:
F_47 ( V_148 ) ;
return V_358 ;
}
static int F_51 ( struct V_147 * V_148 , const char * V_153 )
{
struct V_21 * V_22 ;
int V_14 ;
int V_70 = F_195 ( V_148 -> V_354 ) ;
V_22 = F_56 ( V_153 , V_155 ) ;
if ( V_22 ) {
F_49 ( L_246 ) ;
return - V_360 ;
}
V_22 = F_196 ( sizeof( struct V_21 ) , V_262 , V_70 ) ;
if ( ! V_22 )
return - V_362 ;
strcpy ( V_22 -> V_31 , V_153 ) ;
V_22 -> V_215 = F_197 ( V_144 * sizeof( struct V_363 ) ,
V_70 ) ;
if ( V_22 -> V_215 == NULL ) {
F_198 ( V_22 ) ;
return - V_362 ;
}
V_22 -> V_156 = 0 ;
V_22 -> V_26 = V_364 ;
V_22 -> V_27 = V_364 ;
V_22 -> V_28 = 0 ;
V_22 -> V_29 = V_365 ;
V_22 -> V_12 = V_366 ;
V_22 -> V_90 = 0 ;
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
V_14 = F_67 ( V_22 , V_153 ) ;
if ( V_14 )
goto V_367;
if ( V_22 -> V_50 -> V_132 & V_133 )
V_22 -> V_30 = V_368 ;
V_22 -> V_163 = F_61 ( V_153 , 0600 , V_164 ,
& V_165 , V_22 ) ;
if ( ! V_22 -> V_163 ) {
F_49 ( L_247 ,
V_369 , V_153 ) ;
V_14 = - V_125 ;
goto V_370;
}
#ifdef F_21
V_22 -> V_223 = V_237 ;
V_22 -> V_224 = V_371 ;
#endif
return F_193 ( V_148 , V_22 ) ;
V_370:
F_68 ( V_22 -> V_50 ) ;
V_367:
#ifdef F_21
F_113 ( V_22 ) ;
#endif
F_199 ( V_22 -> V_215 ) ;
F_198 ( V_22 ) ;
return V_14 ;
}
static int T_14 F_200 ( int V_354 )
{
struct V_147 * V_148 ;
struct V_372 * V_373 ;
struct V_374 * V_325 ;
V_148 = F_196 ( sizeof( struct V_147 ) , V_262 ,
F_195 ( V_354 ) ) ;
if ( ! V_148 ) {
F_49 ( L_248 ) ;
return - V_362 ;
}
F_201 ( & V_148 -> F_45 ) ;
V_148 -> V_354 = V_354 ;
F_202 ( & V_148 -> V_361 ) ;
F_203 ( & V_148 -> V_375 , & V_376 ) ;
F_204 ( & V_148 -> V_356 ) ;
V_325 = F_205 ( F_184 ,
V_148 ,
F_195 ( V_354 ) ,
L_249 , V_354 ) ;
if ( F_206 ( V_325 ) ) {
F_49 ( L_250 , V_148 -> V_354 ) ;
F_207 ( & V_148 -> V_375 ) ;
F_198 ( V_148 ) ;
return F_208 ( V_325 ) ;
}
F_209 ( V_325 , V_354 ) ;
V_148 -> V_332 = V_325 ;
V_373 = F_61 ( V_148 -> V_332 -> V_333 , 0600 , V_164 ,
& V_377 , V_148 ) ;
if ( ! V_373 ) {
F_49 ( L_247 ,
V_369 , V_148 -> V_332 -> V_333 ) ;
F_210 ( V_325 ) ;
F_207 ( & V_148 -> V_375 ) ;
F_198 ( V_148 ) ;
return - V_125 ;
}
F_211 ( V_325 ) ;
F_212 ( & V_148 -> V_356 ) ;
return 0 ;
}
static void F_213 ( struct V_147 * V_148 ,
struct V_21 * V_22 )
{
struct V_328 * V_329 , * V_113 ;
struct V_21 * V_325 ;
F_163 (q, n, &t->if_list) {
V_325 = F_164 ( V_329 , struct V_21 , V_331 ) ;
if ( V_325 == V_22 )
F_207 ( & V_325 -> V_331 ) ;
}
}
static int F_165 ( struct V_147 * V_148 ,
struct V_21 * V_22 )
{
F_34 ( L_251 , V_22 ) ;
if ( V_22 -> V_86 ) {
F_13 ( L_252 ) ;
F_159 ( V_22 ) ;
}
if ( V_22 -> V_50 ) {
F_68 ( V_22 -> V_50 ) ;
V_22 -> V_50 = NULL ;
}
F_213 ( V_148 , V_22 ) ;
if ( V_22 -> V_163 )
F_60 ( V_22 -> V_163 -> V_122 , V_164 ) ;
#ifdef F_21
F_113 ( V_22 ) ;
#endif
F_199 ( V_22 -> V_215 ) ;
if ( V_22 -> V_135 )
F_37 ( V_22 -> V_135 ) ;
F_198 ( V_22 ) ;
return 0 ;
}
static int T_14 F_214 ( void )
{
int V_354 ;
struct V_372 * V_373 ;
int V_149 = 0 ;
F_35 ( L_253 , V_9 ) ;
V_164 = F_215 ( V_369 , V_170 . V_378 ) ;
if ( ! V_164 )
return - V_177 ;
V_373 = F_216 ( V_379 , 0600 , V_164 , & V_380 ) ;
if ( V_373 == NULL ) {
F_49 ( L_254 , V_379 ) ;
V_149 = - V_125 ;
goto V_381;
}
F_217 ( & V_382 ) ;
F_218 (cpu) {
int V_14 ;
V_14 = F_200 ( V_354 ) ;
if ( V_14 )
F_13 ( L_255 ,
V_354 , V_14 ) ;
}
if ( F_219 ( & V_376 ) ) {
F_49 ( L_256 ) ;
V_149 = - V_177 ;
goto V_383;
}
return 0 ;
V_383:
F_220 ( & V_382 ) ;
F_60 ( V_379 , V_164 ) ;
V_381:
F_221 ( & V_170 , V_369 ) ;
return V_149 ;
}
static void T_15 F_222 ( void )
{
struct V_147 * V_148 ;
struct V_328 * V_329 , * V_113 ;
F_223 ( V_331 ) ;
V_171 = true ;
F_50 ( & V_150 ) ;
F_224 ( & V_376 , & V_331 ) ;
F_52 ( & V_150 ) ;
F_163 (q, n, &list) {
V_148 = F_164 ( V_329 , struct V_147 , V_375 ) ;
F_207 ( & V_148 -> V_375 ) ;
F_210 ( V_148 -> V_332 ) ;
F_198 ( V_148 ) ;
}
F_220 ( & V_382 ) ;
F_60 ( V_379 , V_164 ) ;
F_221 ( & V_170 , V_369 ) ;
}
