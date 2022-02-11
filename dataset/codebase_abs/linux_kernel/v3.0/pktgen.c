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
unsigned V_60 ;
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
static unsigned long F_28 ( const char T_3 * V_105 ,
unsigned long V_106 , unsigned long * V_107 )
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
unsigned V_113 = 0 ;
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
F_34 ( V_129 L_60 , V_122 ,
( unsigned long ) V_12 , V_128 ) ;
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
V_22 -> V_130 = V_108 ;
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
V_22 -> V_130 = V_108 ;
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
V_22 -> V_130 = V_108 ;
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
V_22 -> V_29 = V_131 ;
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
V_22 -> V_29 = V_132 / V_108 ;
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
if ( V_22 -> V_133 ) {
F_37 ( V_22 -> V_133 ) ;
V_22 -> V_133 = NULL ;
}
}
else
sprintf ( V_124 , L_95 ) ;
return V_12 ;
}
if ( ! strcmp ( V_122 , L_96 ) ) {
char V_134 [ 32 ] ;
memset ( V_134 , 0 , 32 ) ;
V_114 = F_29 ( & V_105 [ V_60 ] , sizeof( V_134 ) - 1 ) ;
if ( V_114 < 0 )
return V_114 ;
if ( F_9 ( V_134 , & V_105 [ V_60 ] , V_114 ) )
return - V_19 ;
V_60 += V_114 ;
if ( strcmp ( V_134 , L_97 ) == 0 )
V_22 -> V_37 |= V_71 ;
else if ( strcmp ( V_134 , L_98 ) == 0 )
V_22 -> V_37 &= ~ V_71 ;
else if ( strcmp ( V_134 , L_99 ) == 0 )
V_22 -> V_37 |= V_73 ;
else if ( strcmp ( V_134 , L_100 ) == 0 )
V_22 -> V_37 &= ~ V_73 ;
else if ( strcmp ( V_134 , L_101 ) == 0 )
V_22 -> V_37 |= V_72 ;
else if ( strcmp ( V_134 , L_102 ) == 0 )
V_22 -> V_37 &= ~ V_72 ;
else if ( strcmp ( V_134 , L_103 ) == 0 )
V_22 -> V_37 |= V_74 ;
else if ( strcmp ( V_134 , L_104 ) == 0 )
V_22 -> V_37 &= ~ V_74 ;
else if ( strcmp ( V_134 , L_105 ) == 0 )
V_22 -> V_37 |= V_75 ;
else if ( strcmp ( V_134 , L_106 ) == 0 )
V_22 -> V_37 &= ~ V_75 ;
else if ( strcmp ( V_134 , L_107 ) == 0 )
V_22 -> V_37 |= V_81 ;
else if ( strcmp ( V_134 , L_108 ) == 0 )
V_22 -> V_37 &= ~ V_81 ;
else if ( strcmp ( V_134 , L_109 ) == 0 )
V_22 -> V_37 |= V_82 ;
else if ( strcmp ( V_134 , L_110 ) == 0 )
V_22 -> V_37 &= ~ V_82 ;
else if ( strcmp ( V_134 , L_111 ) == 0 )
V_22 -> V_37 |= V_76 ;
else if ( strcmp ( V_134 , L_112 ) == 0 )
V_22 -> V_37 &= ~ V_76 ;
else if ( strcmp ( V_134 , L_113 ) == 0 )
V_22 -> V_37 |= V_83 ;
else if ( strcmp ( V_134 , L_114 ) == 0 )
V_22 -> V_37 &= ~ V_83 ;
else if ( strcmp ( V_134 , L_115 ) == 0 )
V_22 -> V_37 |= V_84 ;
else if ( strcmp ( V_134 , L_116 ) == 0 )
V_22 -> V_37 &= ~ V_84 ;
else if ( strcmp ( V_134 , L_117 ) == 0 )
V_22 -> V_37 |= V_79 ;
else if ( strcmp ( V_134 , L_118 ) == 0 )
V_22 -> V_37 |= V_77 ;
else if ( strcmp ( V_134 , L_119 ) == 0 )
V_22 -> V_37 &= ~ V_77 ;
else if ( strcmp ( V_134 , L_120 ) == 0 )
V_22 -> V_37 |= V_78 ;
else if ( strcmp ( V_134 , L_121 ) == 0 )
V_22 -> V_37 &= ~ V_78 ;
#ifdef F_21
else if ( strcmp ( V_134 , L_122 ) == 0 )
V_22 -> V_37 |= V_80 ;
#endif
else if ( strcmp ( V_134 , L_123 ) == 0 )
V_22 -> V_37 &= ~ V_38 ;
else if ( strcmp ( V_134 , L_124 ) == 0 )
V_22 -> V_37 |= V_85 ;
else if ( strcmp ( V_134 , L_125 ) == 0 )
V_22 -> V_37 &= ~ V_85 ;
else {
sprintf ( V_124 ,
L_126 ,
V_134 ,
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
V_22 -> V_135 = F_38 ( V_22 -> V_45 ) ;
V_22 -> V_99 = V_22 -> V_135 ;
}
if ( V_126 )
F_34 ( V_129 L_132 ,
V_22 -> V_45 ) ;
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
V_22 -> V_136 = F_38 ( V_22 -> V_46 ) ;
V_22 -> V_99 = V_22 -> V_136 ;
}
if ( V_126 )
F_34 ( V_129 L_135 ,
V_22 -> V_46 ) ;
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
F_39 ( V_11 , V_22 -> V_42 . V_137 ) ;
snprintf ( V_11 , sizeof( V_11 ) , L_138 , & V_22 -> V_42 ) ;
F_40 ( & V_22 -> V_97 , & V_22 -> V_42 ) ;
if ( V_126 )
F_34 ( V_129 L_139 , V_11 ) ;
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
F_39 ( V_11 , V_22 -> V_43 . V_137 ) ;
snprintf ( V_11 , sizeof( V_11 ) , L_138 , & V_22 -> V_43 ) ;
F_40 ( & V_22 -> V_97 ,
& V_22 -> V_43 ) ;
if ( V_126 )
F_34 ( V_129 L_142 , V_11 ) ;
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
F_39 ( V_11 , V_22 -> V_44 . V_137 ) ;
snprintf ( V_11 , sizeof( V_11 ) , L_138 , & V_22 -> V_44 ) ;
if ( V_126 )
F_34 ( V_129 L_145 , V_11 ) ;
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
F_39 ( V_11 , V_22 -> V_39 . V_137 ) ;
snprintf ( V_11 , sizeof( V_11 ) , L_138 , & V_22 -> V_39 ) ;
F_40 ( & V_22 -> V_96 , & V_22 -> V_39 ) ;
if ( V_126 )
F_34 ( V_129 L_148 , V_11 ) ;
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
V_22 -> V_138 = F_38 ( V_22 -> V_47 ) ;
V_22 -> V_98 = V_22 -> V_138 ;
}
if ( V_126 )
F_34 ( V_129 L_151 ,
V_22 -> V_47 ) ;
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
V_22 -> V_139 = F_38 ( V_22 -> V_48 ) ;
V_22 -> V_98 = V_22 -> V_139 ;
}
if ( V_126 )
F_34 ( V_129 L_154 ,
V_22 -> V_48 ) ;
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
if ( ! F_41 ( V_123 , V_22 -> V_52 ) )
return - V_125 ;
memcpy ( & V_22 -> V_140 [ 0 ] , V_22 -> V_52 , V_141 ) ;
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
if ( ! F_41 ( V_123 , V_22 -> V_49 ) )
return - V_125 ;
memcpy ( & V_22 -> V_140 [ 6 ] , V_22 -> V_49 , V_141 ) ;
sprintf ( V_124 , L_159 , V_22 -> V_49 ) ;
return V_12 ;
}
if ( ! strcmp ( V_122 , L_160 ) ) {
F_42 ( V_22 ) ;
sprintf ( V_124 , L_161 ) ;
return V_12 ;
}
if ( ! strcmp ( V_122 , L_162 ) ) {
V_114 = F_28 ( & V_105 [ V_60 ] , 10 , & V_108 ) ;
if ( V_114 < 0 )
return V_114 ;
V_60 += V_114 ;
if ( V_108 > V_142 )
V_108 = V_142 ;
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
unsigned V_113 , V_143 ;
V_114 = F_30 ( & V_105 [ V_60 ] , V_22 ) ;
if ( V_114 < 0 )
return V_114 ;
V_60 += V_114 ;
V_143 = sprintf ( V_124 , L_171 ) ;
for ( V_113 = 0 ; V_113 < V_22 -> V_59 ; V_113 ++ )
V_143 += sprintf ( V_124 + V_143 ,
L_22 , F_20 ( V_22 -> V_61 [ V_113 ] ) ,
V_113 == V_22 -> V_59 - 1 ? L_172 : L_173 ) ;
if ( V_22 -> V_59 && V_22 -> V_62 != 0xffff ) {
V_22 -> V_62 = 0xffff ;
V_22 -> V_65 = 0xffff ;
if ( V_126 )
F_34 ( V_129 L_174 ) ;
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
F_34 ( V_129 L_176 ) ;
if ( V_126 && V_22 -> V_59 )
F_34 ( V_129 L_177 ) ;
V_22 -> V_59 = 0 ;
sprintf ( V_124 , L_178 , V_22 -> V_62 ) ;
} else {
V_22 -> V_62 = 0xffff ;
V_22 -> V_65 = 0xffff ;
if ( V_126 )
F_34 ( V_129 L_179 ) ;
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
F_34 ( V_129 L_187 ) ;
if ( V_126 && V_22 -> V_59 )
F_34 ( V_129 L_177 ) ;
V_22 -> V_59 = 0 ;
sprintf ( V_124 , L_188 , V_22 -> V_65 ) ;
} else {
V_22 -> V_62 = 0xffff ;
V_22 -> V_65 = 0xffff ;
if ( V_126 )
F_34 ( V_129 L_179 ) ;
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
T_7 V_144 = 0 ;
V_114 = F_24 ( & V_105 [ V_60 ] , 2 , & V_144 ) ;
if ( V_114 < 0 )
return V_114 ;
V_60 += V_114 ;
if ( V_114 == 2 ) {
V_22 -> V_68 = V_144 ;
sprintf ( V_124 , L_196 , V_22 -> V_68 ) ;
} else {
sprintf ( V_124 , L_197 ) ;
}
return V_12 ;
}
if ( ! strcmp ( V_122 , L_198 ) ) {
T_7 V_144 = 0 ;
V_114 = F_24 ( & V_105 [ V_60 ] , 2 , & V_144 ) ;
if ( V_114 < 0 )
return V_114 ;
V_60 += V_114 ;
if ( V_114 == 2 ) {
V_22 -> V_69 = V_144 ;
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
static int F_43 ( struct V_20 * V_20 , struct V_10 * V_10 )
{
return F_15 ( V_10 , F_17 , F_16 ( V_20 ) -> V_15 ) ;
}
static int F_44 ( struct V_6 * V_7 , void * V_8 )
{
struct V_145 * V_146 = V_7 -> V_23 ;
const struct V_21 * V_22 ;
F_45 ( ! V_146 ) ;
F_18 ( V_7 , L_204 ) ;
F_46 ( V_146 ) ;
F_47 (pkt_dev, &t->if_list, list)
if ( V_22 -> V_86 )
F_18 ( V_7 , L_205 , V_22 -> V_31 ) ;
F_18 ( V_7 , L_206 ) ;
F_47 (pkt_dev, &t->if_list, list)
if ( ! V_22 -> V_86 )
F_18 ( V_7 , L_205 , V_22 -> V_31 ) ;
if ( V_146 -> V_104 [ 0 ] )
F_18 ( V_7 , L_207 , V_146 -> V_104 ) ;
else
F_18 ( V_7 , L_208 ) ;
F_48 ( V_146 ) ;
return 0 ;
}
static T_2 F_49 ( struct V_10 * V_10 ,
const char T_3 * V_105 ,
T_4 V_12 , T_5 * V_119 )
{
struct V_6 * V_7 = V_10 -> V_120 ;
struct V_145 * V_146 = V_7 -> V_23 ;
int V_60 , V_121 , V_114 , V_147 ;
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
F_34 ( V_129 L_209 ,
V_122 , ( unsigned long ) V_12 ) ;
if ( ! V_146 ) {
F_50 ( L_210 ) ;
V_147 = - V_125 ;
goto V_18;
}
V_124 = & ( V_146 -> V_104 [ 0 ] ) ;
if ( ! strcmp ( V_122 , L_211 ) ) {
char V_134 [ 32 ] ;
memset ( V_134 , 0 , 32 ) ;
V_114 = F_29 ( & V_105 [ V_60 ] , sizeof( V_134 ) - 1 ) ;
if ( V_114 < 0 ) {
V_147 = V_114 ;
goto V_18;
}
if ( F_9 ( V_134 , & V_105 [ V_60 ] , V_114 ) )
return - V_19 ;
V_60 += V_114 ;
F_51 ( & V_148 ) ;
F_52 ( V_146 , V_134 ) ;
F_53 ( & V_148 ) ;
V_147 = V_12 ;
sprintf ( V_124 , L_212 , V_134 ) ;
goto V_18;
}
if ( ! strcmp ( V_122 , L_213 ) ) {
F_51 ( & V_148 ) ;
V_146 -> V_149 |= V_150 ;
F_53 ( & V_148 ) ;
F_54 ( F_55 ( 125 ) ) ;
V_147 = V_12 ;
sprintf ( V_124 , L_214 ) ;
goto V_18;
}
if ( ! strcmp ( V_122 , L_215 ) ) {
sprintf ( V_124 , L_216 ) ;
V_147 = V_12 ;
goto V_18;
}
V_147 = - V_125 ;
V_18:
return V_147 ;
}
static int F_56 ( struct V_20 * V_20 , struct V_10 * V_10 )
{
return F_15 ( V_10 , F_44 , F_16 ( V_20 ) -> V_15 ) ;
}
static struct V_21 * F_57 ( const char * V_151 , int remove )
{
struct V_145 * V_146 ;
struct V_21 * V_22 = NULL ;
bool V_152 = ( remove == V_153 ) ;
F_47 (t, &pktgen_threads, th_list) {
V_22 = F_58 ( V_146 , V_151 , V_152 ) ;
if ( V_22 ) {
if ( remove ) {
F_46 ( V_146 ) ;
V_22 -> V_154 = 1 ;
V_146 -> V_149 |= V_155 ;
F_48 ( V_146 ) ;
}
break;
}
}
return V_22 ;
}
static void F_59 ( const char * V_151 )
{
struct V_21 * V_22 = NULL ;
const int V_156 = 10 , V_157 = 125 ;
int V_60 = 0 ;
F_51 ( & V_148 ) ;
F_60 ( L_217 , V_158 , V_151 ) ;
while ( 1 ) {
V_22 = F_57 ( V_151 , REMOVE ) ;
if ( V_22 == NULL )
break;
F_53 ( & V_148 ) ;
F_60 ( L_218 ,
V_158 , V_151 ) ;
F_54 ( F_55 ( V_157 ) ) ;
F_51 ( & V_148 ) ;
if ( ++ V_60 >= V_156 ) {
F_50 ( L_219 ,
V_158 , V_157 * V_60 , V_151 ) ;
break;
}
}
F_53 ( & V_148 ) ;
}
static void F_61 ( struct V_159 * V_160 )
{
struct V_145 * V_146 ;
F_47 (t, &pktgen_threads, th_list) {
struct V_21 * V_22 ;
F_47 (pkt_dev, &t->if_list, list) {
if ( V_22 -> V_50 != V_160 )
continue;
F_62 ( V_22 -> V_161 -> V_122 , V_162 ) ;
V_22 -> V_161 = F_63 ( V_160 -> V_122 , 0600 ,
V_162 ,
& V_163 ,
V_22 ) ;
if ( ! V_22 -> V_161 )
F_50 ( L_220 ,
V_160 -> V_122 ) ;
break;
}
}
}
static int F_64 ( struct V_164 * V_165 ,
unsigned long V_166 , void * V_167 )
{
struct V_159 * V_160 = V_167 ;
if ( ! F_65 ( F_66 ( V_160 ) , & V_168 ) )
return V_169 ;
switch ( V_166 ) {
case V_170 :
F_61 ( V_160 ) ;
break;
case V_171 :
F_59 ( V_160 -> V_122 ) ;
break;
}
return V_169 ;
}
static struct V_159 * F_67 ( struct V_21 * V_22 ,
const char * V_151 )
{
char V_172 [ V_173 + 5 ] ;
int V_60 ;
for ( V_60 = 0 ; V_151 [ V_60 ] != '@' ; V_60 ++ ) {
if ( V_60 == V_173 )
break;
V_172 [ V_60 ] = V_151 [ V_60 ] ;
}
V_172 [ V_60 ] = 0 ;
return F_68 ( & V_168 , V_172 ) ;
}
static int F_69 ( struct V_21 * V_22 , const char * V_151 )
{
struct V_159 * V_50 ;
int V_14 ;
if ( V_22 -> V_50 ) {
F_70 ( V_22 -> V_50 ) ;
V_22 -> V_50 = NULL ;
}
V_50 = F_67 ( V_22 , V_151 ) ;
if ( ! V_50 ) {
F_50 ( L_221 , V_151 ) ;
return - V_174 ;
}
if ( V_50 -> type != V_175 ) {
F_50 ( L_222 , V_151 ) ;
V_14 = - V_125 ;
} else if ( ! F_71 ( V_50 ) ) {
F_50 ( L_223 , V_151 ) ;
V_14 = - V_176 ;
} else {
V_22 -> V_50 = V_50 ;
return 0 ;
}
F_70 ( V_50 ) ;
return V_14 ;
}
static void F_72 ( struct V_21 * V_22 )
{
int V_177 ;
if ( ! V_22 -> V_50 ) {
F_50 ( L_224 ) ;
sprintf ( V_22 -> V_104 ,
L_225 ) ;
return;
}
V_177 = V_22 -> V_50 -> V_178 ;
if ( V_177 <= V_22 -> V_34 ) {
F_13 ( L_226 ,
V_22 -> V_34 , ( V_177 ? : 1 ) - 1 , V_177 ,
V_22 -> V_31 ) ;
V_22 -> V_34 = V_177 - 1 ;
}
if ( V_22 -> V_35 >= V_177 ) {
F_13 ( L_227 ,
V_22 -> V_35 , ( V_177 ? : 1 ) - 1 , V_177 ,
V_22 -> V_31 ) ;
V_22 -> V_35 = V_177 - 1 ;
}
if ( F_19 ( V_22 -> V_49 ) )
memcpy ( & ( V_22 -> V_140 [ 6 ] ) , V_22 -> V_50 -> V_51 , V_141 ) ;
memcpy ( & ( V_22 -> V_140 [ 0 ] ) , V_22 -> V_52 , V_141 ) ;
V_22 -> V_130 = V_22 -> V_26 ;
if ( V_22 -> V_37 & V_38 ) {
#ifdef F_73
int V_60 , V_179 = 0 , V_14 = 1 ;
struct V_180 * V_181 ;
for ( V_60 = 0 ; V_60 < V_182 ; V_60 ++ )
if ( V_22 -> V_96 . V_137 [ V_60 ] ) {
V_179 = 1 ;
break;
}
if ( ! V_179 ) {
F_74 () ;
V_181 = F_75 ( V_22 -> V_50 ) ;
if ( V_181 ) {
struct V_183 * V_184 ;
F_76 ( & V_181 -> V_185 ) ;
for ( V_184 = V_181 -> V_186 ; V_184 ;
V_184 = V_184 -> V_187 ) {
if ( V_184 -> V_188 == V_189 &&
! ( V_184 -> V_37 & V_190 ) ) {
F_40 ( & V_22 ->
V_96 ,
& V_184 -> V_191 ) ;
V_14 = 0 ;
break;
}
}
F_77 ( & V_181 -> V_185 ) ;
}
F_78 () ;
if ( V_14 )
F_50 ( L_228 ) ;
}
#endif
} else {
V_22 -> V_138 = 0 ;
V_22 -> V_139 = 0 ;
if ( strlen ( V_22 -> V_47 ) == 0 ) {
struct V_192 * V_193 ;
F_74 () ;
V_193 = F_79 ( V_22 -> V_50 ) ;
if ( V_193 ) {
if ( V_193 -> V_194 ) {
V_22 -> V_138 =
V_193 -> V_194 -> V_195 ;
V_22 -> V_139 = V_22 -> V_138 ;
}
}
F_78 () ;
} else {
V_22 -> V_138 = F_38 ( V_22 -> V_47 ) ;
V_22 -> V_139 = F_38 ( V_22 -> V_48 ) ;
}
V_22 -> V_135 = F_38 ( V_22 -> V_45 ) ;
V_22 -> V_136 = F_38 ( V_22 -> V_46 ) ;
}
V_22 -> V_94 = 0 ;
V_22 -> V_95 = 0 ;
V_22 -> V_98 = V_22 -> V_138 ;
V_22 -> V_99 = V_22 -> V_135 ;
V_22 -> V_100 = V_22 -> V_55 ;
V_22 -> V_101 = V_22 -> V_53 ;
V_22 -> V_103 = 0 ;
}
static void F_80 ( struct V_21 * V_22 , T_1 V_196 )
{
T_1 V_197 , V_198 ;
T_8 V_199 ;
struct V_200 V_146 ;
F_81 ( & V_146 . V_201 , V_202 , V_203 ) ;
F_82 ( & V_146 . V_201 , V_196 ) ;
V_199 = F_83 ( F_84 ( & V_146 . V_201 ) ) ;
if ( V_199 <= 0 ) {
V_22 -> V_204 = F_85 ( V_196 , V_22 -> V_29 ) ;
return;
}
V_197 = F_1 () ;
if ( V_199 < 100000 )
F_86 ( V_199 ) ;
else {
F_87 ( & V_146 , V_205 ) ;
do {
F_88 ( V_206 ) ;
F_89 ( & V_146 . V_201 , V_203 ) ;
if ( ! F_90 ( & V_146 . V_201 ) )
V_146 . V_207 = NULL ;
if ( F_91 ( V_146 . V_207 ) )
F_92 () ;
F_93 ( & V_146 . V_201 ) ;
} while ( V_146 . V_207 && V_22 -> V_86 && ! F_94 ( V_205 ) );
F_95 ( V_208 ) ;
}
V_198 = F_1 () ;
V_22 -> V_88 += F_83 ( F_96 ( V_198 , V_197 ) ) ;
V_22 -> V_204 = F_85 ( V_196 , V_22 -> V_29 ) ;
}
static inline void F_97 ( struct V_21 * V_22 )
{
V_22 -> V_209 = 0 ;
V_22 -> V_209 += V_22 -> V_59 * sizeof( V_210 ) ;
V_22 -> V_209 += F_98 ( V_22 ) ;
V_22 -> V_209 += F_99 ( V_22 ) ;
}
static inline int F_100 ( const struct V_21 * V_22 , int V_211 )
{
return ! ! ( V_22 -> V_212 [ V_211 ] . V_37 & V_213 ) ;
}
static inline int F_101 ( struct V_21 * V_22 )
{
int V_211 = V_22 -> V_214 ;
if ( V_22 -> V_37 & V_79 ) {
if ( V_22 -> V_212 [ V_211 ] . V_12 >= V_22 -> V_33 ) {
V_22 -> V_212 [ V_211 ] . V_12 = 0 ;
V_22 -> V_212 [ V_211 ] . V_37 = 0 ;
V_22 -> V_214 += 1 ;
if ( V_22 -> V_214 >= V_22 -> V_32 )
V_22 -> V_214 = 0 ;
}
} else {
V_211 = F_102 () % V_22 -> V_32 ;
V_22 -> V_214 = V_211 ;
if ( V_22 -> V_212 [ V_211 ] . V_12 > V_22 -> V_33 ) {
V_22 -> V_212 [ V_211 ] . V_12 = 0 ;
V_22 -> V_212 [ V_211 ] . V_37 = 0 ;
}
}
return V_22 -> V_214 ;
}
static void F_103 ( struct V_21 * V_22 , int V_211 )
{
struct V_215 * V_216 = V_22 -> V_212 [ V_211 ] . V_216 ;
if ( ! V_216 ) {
V_216 = F_104 ( & V_168 , V_217 ,
( V_218 * ) & V_22 -> V_99 ,
( V_218 * ) & V_22 -> V_98 ,
V_219 ,
V_22 -> V_220 ,
V_22 -> V_221 , 0 ) ;
if ( V_216 ) {
V_22 -> V_212 [ V_211 ] . V_216 = V_216 ;
F_97 ( V_22 ) ;
V_22 -> V_209 += V_216 -> V_222 . V_223 ;
}
}
}
static void F_105 ( struct V_21 * V_22 )
{
if ( V_22 -> V_37 & V_78 )
V_22 -> V_102 = F_106 () ;
else if ( V_22 -> V_34 <= V_22 -> V_35 ) {
T_9 V_146 ;
if ( V_22 -> V_37 & V_77 ) {
V_146 = F_102 () %
( V_22 -> V_35 -
V_22 -> V_34 + 1 )
+ V_22 -> V_34 ;
} else {
V_146 = V_22 -> V_102 + 1 ;
if ( V_146 > V_22 -> V_35 )
V_146 = V_22 -> V_34 ;
}
V_22 -> V_102 = V_146 ;
}
V_22 -> V_102 = V_22 -> V_102 % V_22 -> V_50 -> V_178 ;
}
static void F_107 ( struct V_21 * V_22 )
{
T_7 V_224 ;
T_7 V_225 ;
int V_211 = 0 ;
if ( V_22 -> V_32 )
V_211 = F_101 ( V_22 ) ;
if ( V_22 -> V_57 > 1 ) {
T_7 V_226 ;
T_7 V_115 ;
if ( V_22 -> V_37 & V_81 )
V_226 = F_102 () % V_22 -> V_57 ;
else {
V_226 = V_22 -> V_95 ++ ;
if ( V_22 -> V_95 >=
V_22 -> V_57 )
V_22 -> V_95 = 0 ;
}
V_115 = V_22 -> V_49 [ 5 ] + ( V_226 & 0xFF ) ;
V_22 -> V_140 [ 11 ] = V_115 ;
V_115 = ( V_22 -> V_49 [ 4 ] + ( ( V_226 >> 8 ) & 0xFF ) + ( V_115 >> 8 ) ) ;
V_22 -> V_140 [ 10 ] = V_115 ;
V_115 = ( V_22 -> V_49 [ 3 ] + ( ( V_226 >> 16 ) & 0xFF ) + ( V_115 >> 8 ) ) ;
V_22 -> V_140 [ 9 ] = V_115 ;
V_115 = ( V_22 -> V_49 [ 2 ] + ( ( V_226 >> 24 ) & 0xFF ) + ( V_115 >> 8 ) ) ;
V_22 -> V_140 [ 8 ] = V_115 ;
V_115 = ( V_22 -> V_49 [ 1 ] + ( V_115 >> 8 ) ) ;
V_22 -> V_140 [ 7 ] = V_115 ;
}
if ( V_22 -> V_58 > 1 ) {
T_7 V_226 ;
T_7 V_115 ;
if ( V_22 -> V_37 & V_82 )
V_226 = F_102 () % V_22 -> V_58 ;
else {
V_226 = V_22 -> V_94 ++ ;
if ( V_22 -> V_94 >=
V_22 -> V_58 ) {
V_22 -> V_94 = 0 ;
}
}
V_115 = V_22 -> V_52 [ 5 ] + ( V_226 & 0xFF ) ;
V_22 -> V_140 [ 5 ] = V_115 ;
V_115 = ( V_22 -> V_52 [ 4 ] + ( ( V_226 >> 8 ) & 0xFF ) + ( V_115 >> 8 ) ) ;
V_22 -> V_140 [ 4 ] = V_115 ;
V_115 = ( V_22 -> V_52 [ 3 ] + ( ( V_226 >> 16 ) & 0xFF ) + ( V_115 >> 8 ) ) ;
V_22 -> V_140 [ 3 ] = V_115 ;
V_115 = ( V_22 -> V_52 [ 2 ] + ( ( V_226 >> 24 ) & 0xFF ) + ( V_115 >> 8 ) ) ;
V_22 -> V_140 [ 2 ] = V_115 ;
V_115 = ( V_22 -> V_52 [ 1 ] + ( V_115 >> 8 ) ) ;
V_22 -> V_140 [ 1 ] = V_115 ;
}
if ( V_22 -> V_37 & V_76 ) {
unsigned V_60 ;
for ( V_60 = 0 ; V_60 < V_22 -> V_59 ; V_60 ++ )
if ( V_22 -> V_61 [ V_60 ] & V_116 )
V_22 -> V_61 [ V_60 ] = V_116 |
( ( V_227 V_228 ) F_102 () &
F_31 ( 0x000fffff ) ) ;
}
if ( ( V_22 -> V_37 & V_83 ) && ( V_22 -> V_62 != 0xffff ) ) {
V_22 -> V_62 = F_102 () & ( 4096 - 1 ) ;
}
if ( ( V_22 -> V_37 & V_84 ) && ( V_22 -> V_65 != 0xffff ) ) {
V_22 -> V_65 = F_102 () & ( 4096 - 1 ) ;
}
if ( V_22 -> V_53 < V_22 -> V_54 ) {
if ( V_22 -> V_37 & V_74 )
V_22 -> V_101 = F_102 () %
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
V_22 -> V_100 = F_102 () %
( V_22 -> V_56 - V_22 -> V_55 )
+ V_22 -> V_55 ;
} else {
V_22 -> V_100 ++ ;
if ( V_22 -> V_100 >= V_22 -> V_56 )
V_22 -> V_100 = V_22 -> V_55 ;
}
}
if ( ! ( V_22 -> V_37 & V_38 ) ) {
V_224 = F_20 ( V_22 -> V_138 ) ;
V_225 = F_20 ( V_22 -> V_139 ) ;
if ( V_224 < V_225 ) {
T_7 V_146 ;
if ( V_22 -> V_37 & V_71 )
V_146 = F_102 () % ( V_225 - V_224 ) + V_224 ;
else {
V_146 = F_20 ( V_22 -> V_98 ) ;
V_146 ++ ;
if ( V_146 > V_225 )
V_146 = V_224 ;
}
V_22 -> V_98 = F_31 ( V_146 ) ;
}
if ( V_22 -> V_32 && F_100 ( V_22 , V_211 ) ) {
V_22 -> V_99 = V_22 -> V_212 [ V_211 ] . V_99 ;
} else {
V_224 = F_20 ( V_22 -> V_135 ) ;
V_225 = F_20 ( V_22 -> V_136 ) ;
if ( V_224 < V_225 ) {
T_7 V_146 ;
V_228 V_229 ;
if ( V_22 -> V_37 & V_72 ) {
V_146 = F_102 () % ( V_225 - V_224 ) + V_224 ;
V_229 = F_31 ( V_146 ) ;
while ( F_108 ( V_229 ) ||
F_109 ( V_229 ) ||
F_110 ( V_229 ) ||
F_111 ( V_229 ) ||
F_112 ( V_229 ) ) {
V_146 = F_102 () % ( V_225 - V_224 ) + V_224 ;
V_229 = F_31 ( V_146 ) ;
}
V_22 -> V_99 = V_229 ;
} else {
V_146 = F_20 ( V_22 -> V_99 ) ;
V_146 ++ ;
if ( V_146 > V_225 ) {
V_146 = V_224 ;
}
V_22 -> V_99 = F_31 ( V_146 ) ;
}
}
if ( V_22 -> V_32 ) {
V_22 -> V_212 [ V_211 ] . V_37 |= V_213 ;
V_22 -> V_212 [ V_211 ] . V_99 =
V_22 -> V_99 ;
#ifdef F_21
if ( V_22 -> V_37 & V_80 )
F_103 ( V_22 , V_211 ) ;
#endif
V_22 -> V_103 ++ ;
}
}
} else {
if ( V_22 -> V_43 . V_230 [ 0 ] == 0 &&
V_22 -> V_43 . V_230 [ 1 ] == 0 &&
V_22 -> V_43 . V_230 [ 2 ] == 0 &&
V_22 -> V_43 . V_230 [ 3 ] == 0 ) ;
else {
int V_60 ;
for ( V_60 = 0 ; V_60 < 4 ; V_60 ++ ) {
V_22 -> V_97 . V_230 [ V_60 ] =
( ( ( V_227 V_228 ) F_102 () |
V_22 -> V_43 . V_230 [ V_60 ] ) &
V_22 -> V_44 . V_230 [ V_60 ] ) ;
}
}
}
if ( V_22 -> V_26 < V_22 -> V_27 ) {
T_7 V_146 ;
if ( V_22 -> V_37 & V_73 ) {
V_146 = F_102 () %
( V_22 -> V_27 - V_22 -> V_26 )
+ V_22 -> V_26 ;
} else {
V_146 = V_22 -> V_130 + 1 ;
if ( V_146 > V_22 -> V_27 )
V_146 = V_22 -> V_26 ;
}
V_22 -> V_130 = V_146 ;
}
F_105 ( V_22 ) ;
V_22 -> V_212 [ V_211 ] . V_12 ++ ;
}
static int F_113 ( struct V_231 * V_232 , struct V_21 * V_22 )
{
struct V_215 * V_216 = V_22 -> V_212 [ V_22 -> V_214 ] . V_216 ;
int V_14 = 0 ;
if ( ! V_216 )
return 0 ;
if ( V_216 -> V_222 . V_233 != V_234 )
return 0 ;
F_114 ( & V_216 -> V_185 ) ;
V_14 = V_216 -> V_235 -> V_236 ( V_216 , V_232 ) ;
if ( V_14 )
goto error;
V_14 = V_216 -> type -> V_236 ( V_216 , V_232 ) ;
if ( V_14 )
goto error;
V_216 -> V_237 . V_238 += V_232 -> V_114 ;
V_216 -> V_237 . V_239 ++ ;
error:
F_115 ( & V_216 -> V_185 ) ;
return V_14 ;
}
static void F_116 ( struct V_21 * V_22 )
{
if ( V_22 -> V_32 ) {
int V_60 ;
for ( V_60 = 0 ; V_60 < V_22 -> V_32 ; V_60 ++ ) {
struct V_215 * V_216 = V_22 -> V_212 [ V_60 ] . V_216 ;
if ( V_216 ) {
F_117 ( V_216 ) ;
V_22 -> V_212 [ V_60 ] . V_216 = NULL ;
}
}
}
}
static int F_118 ( struct V_21 * V_22 ,
struct V_231 * V_232 , T_10 V_240 )
{
if ( V_22 -> V_37 & V_80 ) {
struct V_215 * V_216 = V_22 -> V_212 [ V_22 -> V_214 ] . V_216 ;
int V_241 = 0 ;
if ( V_216 ) {
int V_147 ;
T_11 * V_242 ;
V_241 = V_216 -> V_222 . V_223 - F_119 ( V_232 ) ;
if ( V_241 > 0 ) {
V_147 = F_120 ( V_232 , V_241 , 0 , V_243 ) ;
if ( V_147 < 0 ) {
F_50 ( L_229 ,
V_147 ) ;
goto V_14;
}
}
F_121 ( V_232 , V_244 ) ;
V_147 = F_113 ( V_232 , V_22 ) ;
if ( V_147 ) {
F_50 ( L_230 , V_147 ) ;
goto V_14;
}
V_242 = ( T_11 * ) F_122 ( V_232 , V_244 ) ;
memcpy ( V_242 , V_22 -> V_140 , 12 ) ;
* ( V_245 * ) & V_242 [ 12 ] = V_240 ;
}
}
return 1 ;
V_14:
F_123 ( V_232 ) ;
return 0 ;
}
static void F_124 ( V_228 * V_246 , struct V_21 * V_22 )
{
unsigned V_60 ;
for ( V_60 = 0 ; V_60 < V_22 -> V_59 ; V_60 ++ )
* V_246 ++ = V_22 -> V_61 [ V_60 ] & ~ V_116 ;
V_246 -- ;
* V_246 |= V_116 ;
}
static inline T_10 F_125 ( unsigned int V_247 , unsigned int V_248 ,
unsigned int V_249 )
{
return F_126 ( V_247 | ( V_248 << 12 ) | ( V_249 << 13 ) ) ;
}
static void F_127 ( struct V_21 * V_22 , struct V_231 * V_232 ,
int V_250 )
{
struct V_251 V_252 ;
struct V_253 * V_254 ;
V_254 = (struct V_253 * ) F_128 ( V_232 , sizeof( * V_254 ) ) ;
V_250 -= sizeof( * V_254 ) ;
if ( V_22 -> V_28 <= 0 ) {
memset ( F_128 ( V_232 , V_250 ) , 0 , V_250 ) ;
} else {
int V_255 = V_22 -> V_28 ;
int V_60 , V_114 ;
int V_256 ;
if ( V_255 > V_257 )
V_255 = V_257 ;
V_114 = V_250 - V_255 * V_258 ;
if ( V_114 > 0 ) {
memset ( F_128 ( V_232 , V_114 ) , 0 , V_114 ) ;
V_250 = V_255 * V_258 ;
}
V_60 = 0 ;
V_256 = ( V_250 / V_255 ) < V_258 ?
( V_250 / V_255 ) : V_258 ;
while ( V_250 > 0 ) {
if ( F_129 ( ! V_22 -> V_133 ) ) {
int V_70 = F_130 () ;
if ( V_22 -> V_70 >= 0 && ( V_22 -> V_37 & V_85 ) )
V_70 = V_22 -> V_70 ;
V_22 -> V_133 = F_131 ( V_70 , V_259 | V_260 , 0 ) ;
if ( ! V_22 -> V_133 )
break;
}
F_132 ( V_232 ) -> V_255 [ V_60 ] . V_133 = V_22 -> V_133 ;
F_133 ( V_22 -> V_133 ) ;
F_132 ( V_232 ) -> V_255 [ V_60 ] . V_261 = 0 ;
if ( V_60 == ( V_255 - 1 ) )
F_132 ( V_232 ) -> V_255 [ V_60 ] . V_262 =
( V_250 < V_258 ? V_250 : V_258 ) ;
else
F_132 ( V_232 ) -> V_255 [ V_60 ] . V_262 = V_256 ;
V_250 -= F_132 ( V_232 ) -> V_255 [ V_60 ] . V_262 ;
V_232 -> V_114 += F_132 ( V_232 ) -> V_255 [ V_60 ] . V_262 ;
V_232 -> V_263 += F_132 ( V_232 ) -> V_255 [ V_60 ] . V_262 ;
V_60 ++ ;
F_132 ( V_232 ) -> V_264 = V_60 ;
}
}
V_254 -> V_265 = F_31 ( V_266 ) ;
V_254 -> V_93 = F_31 ( V_22 -> V_93 ) ;
F_134 ( & V_252 ) ;
V_254 -> V_267 = F_31 ( V_252 . V_267 ) ;
V_254 -> V_268 = F_31 ( V_252 . V_268 ) ;
}
static struct V_231 * F_135 ( struct V_159 * V_50 ,
struct V_21 * V_22 )
{
struct V_231 * V_232 = NULL ;
T_11 * V_242 ;
struct V_269 * V_270 ;
int V_250 , V_271 ;
struct V_272 * V_273 ;
T_10 V_240 = F_126 ( V_274 ) ;
V_228 * V_246 ;
T_10 * V_275 = NULL ;
T_10 * V_276 = NULL ;
T_10 * V_277 = NULL ;
T_10 * V_278 = NULL ;
V_245 V_279 ;
if ( V_22 -> V_59 )
V_240 = F_126 ( V_280 ) ;
if ( V_22 -> V_62 != 0xffff )
V_240 = F_126 ( V_281 ) ;
F_107 ( V_22 ) ;
V_279 = V_22 -> V_102 ;
V_250 = ( V_50 -> V_282 + 16 ) & ~ 0xf ;
if ( V_22 -> V_37 & V_85 ) {
int V_70 ;
if ( V_22 -> V_70 >= 0 )
V_70 = V_22 -> V_70 ;
else
V_70 = F_130 () ;
V_232 = F_136 ( V_283 + V_22 -> V_130 + 64
+ V_250 + V_22 -> V_209 , V_284 , 0 , V_70 ) ;
if ( F_91 ( V_232 ) ) {
F_137 ( V_232 , V_283 ) ;
V_232 -> V_160 = V_50 ;
}
}
else
V_232 = F_138 ( V_50 ,
V_22 -> V_130 + 64
+ V_250 + V_22 -> V_209 , V_284 ) ;
if ( ! V_232 ) {
sprintf ( V_22 -> V_104 , L_231 ) ;
return NULL ;
}
F_139 ( V_232 -> V_15 ) ;
F_137 ( V_232 , V_250 ) ;
V_242 = ( T_11 * ) F_122 ( V_232 , 14 ) ;
V_246 = ( V_228 * ) F_128 ( V_232 , V_22 -> V_59 * sizeof( T_7 ) ) ;
if ( V_22 -> V_59 )
F_124 ( V_246 , V_22 ) ;
if ( V_22 -> V_62 != 0xffff ) {
if ( V_22 -> V_65 != 0xffff ) {
V_277 = ( T_10 * ) F_128 ( V_232 , sizeof( T_10 ) ) ;
* V_277 = F_125 ( V_22 -> V_65 ,
V_22 -> V_67 ,
V_22 -> V_66 ) ;
V_278 = ( T_10 * ) F_128 ( V_232 , sizeof( T_10 ) ) ;
* V_278 = F_126 ( V_281 ) ;
}
V_275 = ( T_10 * ) F_128 ( V_232 , sizeof( T_10 ) ) ;
* V_275 = F_125 ( V_22 -> V_62 ,
V_22 -> V_64 ,
V_22 -> V_63 ) ;
V_276 = ( T_10 * ) F_128 ( V_232 , sizeof( T_10 ) ) ;
* V_276 = F_126 ( V_274 ) ;
}
V_232 -> V_285 = V_232 -> V_286 ;
V_232 -> V_287 = V_232 -> V_285 + sizeof( struct V_272 ) ;
F_128 ( V_232 , sizeof( struct V_272 ) + sizeof( struct V_269 ) ) ;
F_140 ( V_232 , V_279 ) ;
V_232 -> V_288 = V_22 -> V_36 ;
V_273 = F_141 ( V_232 ) ;
V_270 = F_142 ( V_232 ) ;
memcpy ( V_242 , V_22 -> V_140 , 12 ) ;
* ( T_10 * ) & V_242 [ 12 ] = V_240 ;
V_250 = V_22 -> V_130 - 14 - 20 - 8 -
V_22 -> V_209 ;
if ( V_250 < sizeof( struct V_253 ) )
V_250 = sizeof( struct V_253 ) ;
V_270 -> V_289 = F_126 ( V_22 -> V_101 ) ;
V_270 -> V_290 = F_126 ( V_22 -> V_100 ) ;
V_270 -> V_114 = F_126 ( V_250 + 8 ) ;
V_270 -> V_291 = 0 ;
V_273 -> V_292 = 5 ;
V_273 -> V_9 = 4 ;
V_273 -> V_293 = 32 ;
V_273 -> V_68 = V_22 -> V_68 ;
V_273 -> V_240 = V_294 ;
V_273 -> V_295 = V_22 -> V_98 ;
V_273 -> V_296 = V_22 -> V_99 ;
V_273 -> V_247 = F_126 ( V_22 -> V_297 ) ;
V_22 -> V_297 ++ ;
V_273 -> V_298 = 0 ;
V_271 = 20 + 8 + V_250 ;
V_273 -> V_299 = F_126 ( V_271 ) ;
V_273 -> V_291 = 0 ;
V_273 -> V_291 = F_143 ( ( void * ) V_273 , V_273 -> V_292 ) ;
V_232 -> V_240 = V_240 ;
V_232 -> V_300 = ( V_232 -> V_285 - V_244 -
V_22 -> V_209 ) ;
V_232 -> V_160 = V_50 ;
V_232 -> V_301 = V_302 ;
F_127 ( V_22 , V_232 , V_250 ) ;
#ifdef F_21
if ( ! F_118 ( V_22 , V_232 , V_240 ) )
return NULL ;
#endif
return V_232 ;
}
static unsigned int F_39 ( const char * V_229 , char V_303 [ 16 ] )
{
unsigned int V_60 ;
unsigned int V_114 = 0 ;
unsigned long V_304 ;
char V_305 [ 16 ] ;
unsigned int V_306 = 0 ;
unsigned int V_307 = 0 ;
V_228 V_115 ;
char * V_308 ;
for ( V_60 = 0 ; V_60 < 16 ; V_60 ++ )
V_303 [ V_60 ] = 0 ;
for (; ; ) {
if ( * V_229 == ':' ) {
V_114 ++ ;
if ( V_229 [ 1 ] == ':' ) {
V_229 += 2 ;
V_114 ++ ;
break;
}
V_229 ++ ;
}
V_304 = F_144 ( V_229 , & V_308 , 16 ) ;
V_60 = V_308 - V_229 ;
if ( ! V_60 )
return 0 ;
if ( V_306 == 12 && V_229 [ V_60 ] == '.' ) {
V_115 = F_38 ( V_229 ) ;
memcpy ( (struct V_309 * ) ( V_303 + 12 ) , & V_115 , sizeof( V_115 ) ) ;
return V_60 + V_114 ;
}
V_303 [ V_306 ++ ] = ( V_304 >> 8 ) ;
V_303 [ V_306 ++ ] = ( V_304 & 255 ) ;
V_229 += V_60 ;
V_114 += V_60 ;
if ( V_306 == 16 )
return V_114 ;
}
for (; ; ) {
if ( * V_229 == ':' ) {
if ( V_307 == 0 )
break;
V_229 ++ ;
V_114 ++ ;
} else if ( V_307 != 0 )
break;
V_304 = F_145 ( V_229 , & V_308 , 16 ) ;
V_60 = V_308 - V_229 ;
if ( ! V_60 ) {
if ( * V_229 )
V_114 -- ;
break;
}
if ( V_307 + V_306 <= 12 && V_229 [ V_60 ] == '.' ) {
V_115 = F_38 ( V_229 ) ;
memcpy ( (struct V_309 * ) ( V_305 + V_307 ) , & V_115 ,
sizeof( V_115 ) ) ;
V_307 += 4 ;
V_114 += strlen ( V_229 ) ;
break;
}
V_305 [ V_307 ++ ] = ( V_304 >> 8 ) ;
V_305 [ V_307 ++ ] = ( V_304 & 255 ) ;
V_229 += V_60 ;
V_114 += V_60 ;
if ( V_306 + V_307 == 16 )
break;
}
for ( V_60 = 0 ; V_60 < V_307 ; V_60 ++ )
V_303 [ 16 - V_307 + V_60 ] = V_305 [ V_60 ] ;
return V_114 ;
}
static struct V_231 * F_146 ( struct V_159 * V_50 ,
struct V_21 * V_22 )
{
struct V_231 * V_232 = NULL ;
T_11 * V_242 ;
struct V_269 * V_270 ;
int V_250 ;
struct V_310 * V_273 ;
T_10 V_240 = F_126 ( V_311 ) ;
V_228 * V_246 ;
T_10 * V_275 = NULL ;
T_10 * V_276 = NULL ;
T_10 * V_277 = NULL ;
T_10 * V_278 = NULL ;
V_245 V_279 ;
if ( V_22 -> V_59 )
V_240 = F_126 ( V_280 ) ;
if ( V_22 -> V_62 != 0xffff )
V_240 = F_126 ( V_281 ) ;
F_107 ( V_22 ) ;
V_279 = V_22 -> V_102 ;
V_232 = F_138 ( V_50 ,
V_22 -> V_130 + 64
+ 16 + V_22 -> V_209 , V_284 ) ;
if ( ! V_232 ) {
sprintf ( V_22 -> V_104 , L_231 ) ;
return NULL ;
}
F_139 ( V_232 -> V_15 ) ;
F_137 ( V_232 , 16 ) ;
V_242 = ( T_11 * ) F_122 ( V_232 , 14 ) ;
V_246 = ( V_228 * ) F_128 ( V_232 , V_22 -> V_59 * sizeof( T_7 ) ) ;
if ( V_22 -> V_59 )
F_124 ( V_246 , V_22 ) ;
if ( V_22 -> V_62 != 0xffff ) {
if ( V_22 -> V_65 != 0xffff ) {
V_277 = ( T_10 * ) F_128 ( V_232 , sizeof( T_10 ) ) ;
* V_277 = F_125 ( V_22 -> V_65 ,
V_22 -> V_67 ,
V_22 -> V_66 ) ;
V_278 = ( T_10 * ) F_128 ( V_232 , sizeof( T_10 ) ) ;
* V_278 = F_126 ( V_281 ) ;
}
V_275 = ( T_10 * ) F_128 ( V_232 , sizeof( T_10 ) ) ;
* V_275 = F_125 ( V_22 -> V_62 ,
V_22 -> V_64 ,
V_22 -> V_63 ) ;
V_276 = ( T_10 * ) F_128 ( V_232 , sizeof( T_10 ) ) ;
* V_276 = F_126 ( V_311 ) ;
}
V_232 -> V_285 = V_232 -> V_286 ;
V_232 -> V_287 = V_232 -> V_285 + sizeof( struct V_310 ) ;
F_128 ( V_232 , sizeof( struct V_310 ) + sizeof( struct V_269 ) ) ;
F_140 ( V_232 , V_279 ) ;
V_232 -> V_288 = V_22 -> V_36 ;
V_273 = F_147 ( V_232 ) ;
V_270 = F_142 ( V_232 ) ;
memcpy ( V_242 , V_22 -> V_140 , 12 ) ;
* ( T_10 * ) & V_242 [ 12 ] = V_240 ;
V_250 = V_22 -> V_130 - 14 -
sizeof( struct V_310 ) - sizeof( struct V_269 ) -
V_22 -> V_209 ;
if ( V_250 < sizeof( struct V_253 ) ) {
V_250 = sizeof( struct V_253 ) ;
if ( F_148 () )
F_35 ( L_232 , V_250 ) ;
}
V_270 -> V_289 = F_126 ( V_22 -> V_101 ) ;
V_270 -> V_290 = F_126 ( V_22 -> V_100 ) ;
V_270 -> V_114 = F_126 ( V_250 + sizeof( struct V_269 ) ) ;
V_270 -> V_291 = 0 ;
* ( V_228 * ) V_273 = F_31 ( 0x60000000 ) ;
if ( V_22 -> V_69 ) {
* ( V_228 * ) V_273 |= F_31 ( 0x60000000 | ( V_22 -> V_69 << 20 ) ) ;
}
V_273 -> V_312 = 32 ;
V_273 -> V_313 = F_126 ( sizeof( struct V_269 ) + V_250 ) ;
V_273 -> V_314 = V_294 ;
F_40 ( & V_273 -> V_296 , & V_22 -> V_97 ) ;
F_40 ( & V_273 -> V_295 , & V_22 -> V_96 ) ;
V_232 -> V_300 = ( V_232 -> V_285 - V_244 -
V_22 -> V_209 ) ;
V_232 -> V_240 = V_240 ;
V_232 -> V_160 = V_50 ;
V_232 -> V_301 = V_302 ;
F_127 ( V_22 , V_232 , V_250 ) ;
return V_232 ;
}
static struct V_231 * F_149 ( struct V_159 * V_50 ,
struct V_21 * V_22 )
{
if ( V_22 -> V_37 & V_38 )
return F_146 ( V_50 , V_22 ) ;
else
return F_135 ( V_50 , V_22 ) ;
}
static void F_42 ( struct V_21 * V_22 )
{
V_22 -> V_93 = 1 ;
V_22 -> V_88 = 0 ;
V_22 -> V_90 = 0 ;
V_22 -> V_315 = 0 ;
V_22 -> V_91 = 0 ;
}
static void F_150 ( struct V_145 * V_146 )
{
struct V_21 * V_22 ;
int V_316 = 0 ;
F_151 () ;
F_46 ( V_146 ) ;
F_47 (pkt_dev, &t->if_list, list) {
F_72 ( V_22 ) ;
if ( V_22 -> V_50 ) {
F_42 ( V_22 ) ;
V_22 -> V_86 = 1 ;
V_22 -> V_232 = NULL ;
V_22 -> V_92 =
V_22 -> V_204 = F_1 () ;
F_97 ( V_22 ) ;
strcpy ( V_22 -> V_104 , L_233 ) ;
V_316 ++ ;
} else
strcpy ( V_22 -> V_104 , L_234 ) ;
}
F_48 ( V_146 ) ;
if ( V_316 )
V_146 -> V_149 &= ~ ( V_317 ) ;
}
static void F_10 ( void )
{
struct V_145 * V_146 ;
F_151 () ;
F_51 ( & V_148 ) ;
F_47 (t, &pktgen_threads, th_list)
V_146 -> V_149 |= V_317 ;
F_53 ( & V_148 ) ;
}
static int F_152 ( const struct V_145 * V_146 )
{
const struct V_21 * V_22 ;
F_47 (pkt_dev, &t->if_list, list)
if ( V_22 -> V_86 )
return 1 ;
return 0 ;
}
static int F_153 ( struct V_145 * V_146 )
{
F_46 ( V_146 ) ;
while ( F_152 ( V_146 ) ) {
F_48 ( V_146 ) ;
F_154 ( 100 ) ;
if ( F_94 ( V_205 ) )
goto signal;
F_46 ( V_146 ) ;
}
F_48 ( V_146 ) ;
return 1 ;
signal:
return 0 ;
}
static int F_155 ( void )
{
struct V_145 * V_146 ;
int V_318 = 1 ;
F_51 ( & V_148 ) ;
F_47 (t, &pktgen_threads, th_list) {
V_318 = F_153 ( V_146 ) ;
if ( V_318 == 0 )
break;
}
if ( V_318 == 0 )
F_47 (t, &pktgen_threads, th_list)
V_146 -> V_149 |= ( V_317 ) ;
F_53 ( & V_148 ) ;
return V_318 ;
}
static void F_11 ( void )
{
struct V_145 * V_146 ;
F_151 () ;
F_51 ( & V_148 ) ;
F_47 (t, &pktgen_threads, th_list)
V_146 -> V_149 |= ( V_319 ) ;
F_53 ( & V_148 ) ;
F_54 ( F_55 ( 125 ) ) ;
F_155 () ;
}
static void F_12 ( void )
{
struct V_145 * V_146 ;
F_151 () ;
F_51 ( & V_148 ) ;
F_47 (t, &pktgen_threads, th_list)
V_146 -> V_149 |= ( V_150 ) ;
F_53 ( & V_148 ) ;
F_54 ( F_55 ( 125 ) ) ;
F_155 () ;
}
static void F_156 ( struct V_21 * V_22 , int V_264 )
{
T_12 V_320 , V_321 , V_322 ;
char * V_323 = V_22 -> V_104 ;
T_1 V_324 = F_96 ( V_22 -> V_87 ,
V_22 -> V_92 ) ;
T_1 V_25 = F_157 ( V_22 -> V_88 ) ;
V_323 += sprintf ( V_323 , L_235 ,
( unsigned long long ) F_23 ( V_324 ) ,
( unsigned long long ) F_23 ( F_96 ( V_324 , V_25 ) ) ,
( unsigned long long ) F_23 ( V_25 ) ,
( unsigned long long ) V_22 -> V_90 ,
V_22 -> V_130 , V_264 ) ;
V_322 = F_158 ( V_22 -> V_90 * V_132 ,
F_83 ( V_324 ) ) ;
V_320 = V_322 * 8 * V_22 -> V_130 ;
V_321 = V_320 ;
F_22 ( V_321 , 1000000 ) ;
V_323 += sprintf ( V_323 , L_236 ,
( unsigned long long ) V_322 ,
( unsigned long long ) V_321 ,
( unsigned long long ) V_320 ,
( unsigned long long ) V_22 -> V_91 ) ;
}
static int F_159 ( struct V_21 * V_22 )
{
int V_264 = V_22 -> V_232 ? F_132 ( V_22 -> V_232 ) -> V_264 : - 1 ;
if ( ! V_22 -> V_86 ) {
F_13 ( L_237 ,
V_22 -> V_31 ) ;
return - V_125 ;
}
F_123 ( V_22 -> V_232 ) ;
V_22 -> V_232 = NULL ;
V_22 -> V_87 = F_1 () ;
V_22 -> V_86 = 0 ;
F_156 ( V_22 , V_264 ) ;
return 0 ;
}
static struct V_21 * F_160 ( struct V_145 * V_146 )
{
struct V_21 * V_22 , * V_325 = NULL ;
F_46 ( V_146 ) ;
F_47 (pkt_dev, &t->if_list, list) {
if ( ! V_22 -> V_86 )
continue;
if ( V_325 == NULL )
V_325 = V_22 ;
else if ( F_4 ( V_22 -> V_204 , V_325 -> V_204 ) )
V_325 = V_22 ;
}
F_48 ( V_146 ) ;
return V_325 ;
}
static void F_161 ( struct V_145 * V_146 )
{
struct V_21 * V_22 ;
F_151 () ;
F_46 ( V_146 ) ;
F_47 (pkt_dev, &t->if_list, list) {
F_159 ( V_22 ) ;
}
F_48 ( V_146 ) ;
}
static void F_162 ( struct V_145 * V_146 )
{
struct V_326 * V_327 , * V_113 ;
struct V_21 * V_328 ;
F_151 () ;
F_46 ( V_146 ) ;
F_163 (q, n, &t->if_list) {
V_328 = F_164 ( V_327 , struct V_21 , V_329 ) ;
if ( ! V_328 -> V_154 )
continue;
F_123 ( V_328 -> V_232 ) ;
V_328 -> V_232 = NULL ;
F_165 ( V_146 , V_328 ) ;
break;
}
F_48 ( V_146 ) ;
}
static void F_166 ( struct V_145 * V_146 )
{
struct V_326 * V_327 , * V_113 ;
struct V_21 * V_328 ;
F_151 () ;
F_46 ( V_146 ) ;
F_163 (q, n, &t->if_list) {
V_328 = F_164 ( V_327 , struct V_21 , V_329 ) ;
F_123 ( V_328 -> V_232 ) ;
V_328 -> V_232 = NULL ;
F_165 ( V_146 , V_328 ) ;
}
F_48 ( V_146 ) ;
}
static void F_167 ( struct V_145 * V_146 )
{
F_62 ( V_146 -> V_330 -> V_331 , V_162 ) ;
}
static void F_168 ( struct V_21 * V_22 )
{
T_1 V_332 = F_1 () ;
F_92 () ;
V_22 -> V_88 += F_83 ( F_96 ( F_1 () , V_332 ) ) ;
}
static void F_169 ( struct V_21 * V_22 )
{
T_1 V_332 = F_1 () ;
while ( F_170 ( & ( V_22 -> V_232 -> V_333 ) ) != 1 ) {
if ( F_94 ( V_205 ) )
break;
if ( F_171 () )
F_168 ( V_22 ) ;
else
F_172 () ;
}
V_22 -> V_88 += F_83 ( F_96 ( F_1 () , V_332 ) ) ;
}
static void F_173 ( struct V_21 * V_22 )
{
struct V_159 * V_50 = V_22 -> V_50 ;
T_13 (* F_174)( struct V_231 * , struct V_159 * )
= V_50 -> V_334 -> V_335 ;
struct V_336 * V_337 ;
V_245 V_279 ;
int V_147 ;
if ( F_129 ( ! F_71 ( V_50 ) || ! F_175 ( V_50 ) ) ) {
F_159 ( V_22 ) ;
return;
}
if ( F_129 ( V_22 -> V_29 == V_131 ) ) {
V_22 -> V_204 = F_85 ( F_1 () , V_338 ) ;
return;
}
if ( ! V_22 -> V_232 || ( V_22 -> V_339 &&
++ V_22 -> V_340 >= V_22 -> V_30 ) ) {
F_123 ( V_22 -> V_232 ) ;
V_22 -> V_232 = F_149 ( V_50 , V_22 ) ;
if ( V_22 -> V_232 == NULL ) {
F_50 ( L_238 ) ;
F_92 () ;
V_22 -> V_340 -- ;
return;
}
V_22 -> V_341 = V_22 -> V_232 -> V_114 ;
V_22 -> V_342 ++ ;
V_22 -> V_340 = 0 ;
}
if ( V_22 -> V_29 && V_22 -> V_339 )
F_80 ( V_22 , V_22 -> V_204 ) ;
V_279 = F_176 ( V_22 -> V_232 ) ;
V_337 = F_177 ( V_50 , V_279 ) ;
F_178 ( V_337 ) ;
if ( F_129 ( F_179 ( V_337 ) ) ) {
V_147 = V_343 ;
V_22 -> V_339 = 0 ;
goto V_344;
}
F_180 ( & ( V_22 -> V_232 -> V_333 ) ) ;
V_147 = (* F_174)( V_22 -> V_232 , V_50 ) ;
switch ( V_147 ) {
case V_345 :
F_181 ( V_337 ) ;
V_22 -> V_339 = 1 ;
V_22 -> V_90 ++ ;
V_22 -> V_93 ++ ;
V_22 -> V_315 += V_22 -> V_341 ;
break;
case V_346 :
case V_347 :
case V_348 :
V_22 -> V_91 ++ ;
break;
default:
if ( F_148 () )
F_35 ( L_239 , V_22 -> V_31 , V_147 ) ;
V_22 -> V_91 ++ ;
case V_349 :
case V_343 :
F_182 ( & ( V_22 -> V_232 -> V_333 ) ) ;
V_22 -> V_339 = 0 ;
}
V_344:
F_183 ( V_337 ) ;
if ( ( V_22 -> V_12 != 0 ) && ( V_22 -> V_90 >= V_22 -> V_12 ) ) {
F_169 ( V_22 ) ;
F_159 ( V_22 ) ;
}
}
static int F_184 ( void * V_350 )
{
F_185 ( V_351 ) ;
struct V_145 * V_146 = V_350 ;
struct V_21 * V_22 = NULL ;
int V_352 = V_146 -> V_352 ;
F_45 ( F_106 () != V_352 ) ;
F_186 ( & V_146 -> V_353 ) ;
F_187 ( & V_146 -> V_354 ) ;
F_60 ( L_240 , V_352 , F_188 ( V_205 ) ) ;
F_88 ( V_206 ) ;
F_189 () ;
while ( ! F_190 () ) {
V_22 = F_160 ( V_146 ) ;
if ( F_129 ( ! V_22 && V_146 -> V_149 == 0 ) ) {
if ( V_355 )
break;
F_191 ( V_146 -> V_353 ,
V_146 -> V_149 != 0 ,
V_356 / 10 ) ;
F_192 () ;
continue;
}
F_95 ( V_208 ) ;
if ( F_91 ( V_22 ) ) {
F_173 ( V_22 ) ;
if ( F_171 () )
F_168 ( V_22 ) ;
else
F_172 () ;
}
if ( V_146 -> V_149 & V_317 ) {
F_161 ( V_146 ) ;
V_146 -> V_149 &= ~ ( V_317 ) ;
}
if ( V_146 -> V_149 & V_319 ) {
F_150 ( V_146 ) ;
V_146 -> V_149 &= ~ ( V_319 ) ;
}
if ( V_146 -> V_149 & V_150 ) {
F_166 ( V_146 ) ;
V_146 -> V_149 &= ~ ( V_150 ) ;
}
if ( V_146 -> V_149 & V_155 ) {
F_162 ( V_146 ) ;
V_146 -> V_149 &= ~ ( V_155 ) ;
}
F_192 () ;
F_88 ( V_206 ) ;
}
F_60 ( L_241 , V_146 -> V_330 -> V_331 ) ;
F_161 ( V_146 ) ;
F_60 ( L_242 , V_146 -> V_330 -> V_331 ) ;
F_166 ( V_146 ) ;
F_60 ( L_243 , V_146 -> V_330 -> V_331 ) ;
F_167 ( V_146 ) ;
while ( ! F_190 () ) {
F_88 ( V_206 ) ;
F_92 () ;
}
F_95 ( V_208 ) ;
return 0 ;
}
static struct V_21 * F_58 ( struct V_145 * V_146 ,
const char * V_151 , bool V_152 )
{
struct V_21 * V_323 , * V_22 = NULL ;
T_4 V_114 = strlen ( V_151 ) ;
F_46 ( V_146 ) ;
F_47 (p, &t->if_list, list)
if ( strncmp ( V_323 -> V_31 , V_151 , V_114 ) == 0 ) {
if ( V_323 -> V_31 [ V_114 ] ) {
if ( V_152 || V_323 -> V_31 [ V_114 ] != '@' )
continue;
}
V_22 = V_323 ;
break;
}
F_48 ( V_146 ) ;
F_60 ( L_244 , V_151 , V_22 ) ;
return V_22 ;
}
static int F_193 ( struct V_145 * V_146 ,
struct V_21 * V_22 )
{
int V_357 = 0 ;
F_46 ( V_146 ) ;
if ( V_22 -> V_358 ) {
F_50 ( L_245 ) ;
V_357 = - V_359 ;
goto V_18;
}
F_194 ( & V_22 -> V_329 , & V_146 -> V_360 ) ;
V_22 -> V_358 = V_146 ;
V_22 -> V_86 = 0 ;
V_18:
F_48 ( V_146 ) ;
return V_357 ;
}
static int F_52 ( struct V_145 * V_146 , const char * V_151 )
{
struct V_21 * V_22 ;
int V_14 ;
int V_70 = F_195 ( V_146 -> V_352 ) ;
V_22 = F_57 ( V_151 , V_153 ) ;
if ( V_22 ) {
F_50 ( L_246 ) ;
return - V_359 ;
}
V_22 = F_196 ( sizeof( struct V_21 ) , V_259 , V_70 ) ;
if ( ! V_22 )
return - V_361 ;
strcpy ( V_22 -> V_31 , V_151 ) ;
V_22 -> V_212 = F_197 ( V_142 * sizeof( struct V_362 ) ,
V_70 ) ;
if ( V_22 -> V_212 == NULL ) {
F_198 ( V_22 ) ;
return - V_361 ;
}
V_22 -> V_154 = 0 ;
V_22 -> V_26 = V_363 ;
V_22 -> V_27 = V_363 ;
V_22 -> V_28 = 0 ;
V_22 -> V_30 = V_364 ;
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
V_14 = F_69 ( V_22 , V_151 ) ;
if ( V_14 )
goto V_367;
V_22 -> V_161 = F_63 ( V_151 , 0600 , V_162 ,
& V_163 , V_22 ) ;
if ( ! V_22 -> V_161 ) {
F_50 ( L_247 ,
V_368 , V_151 ) ;
V_14 = - V_125 ;
goto V_369;
}
#ifdef F_21
V_22 -> V_220 = V_234 ;
V_22 -> V_221 = V_370 ;
#endif
return F_193 ( V_146 , V_22 ) ;
V_369:
F_70 ( V_22 -> V_50 ) ;
V_367:
#ifdef F_21
F_116 ( V_22 ) ;
#endif
F_199 ( V_22 -> V_212 ) ;
F_198 ( V_22 ) ;
return V_14 ;
}
static int T_14 F_200 ( int V_352 )
{
struct V_145 * V_146 ;
struct V_371 * V_372 ;
struct V_373 * V_323 ;
V_146 = F_196 ( sizeof( struct V_145 ) , V_259 ,
F_195 ( V_352 ) ) ;
if ( ! V_146 ) {
F_50 ( L_248 ) ;
return - V_361 ;
}
F_201 ( & V_146 -> F_46 ) ;
V_146 -> V_352 = V_352 ;
F_202 ( & V_146 -> V_360 ) ;
F_203 ( & V_146 -> V_374 , & V_375 ) ;
F_204 ( & V_146 -> V_354 ) ;
V_323 = F_205 ( F_184 ,
V_146 ,
F_195 ( V_352 ) ,
L_249 , V_352 ) ;
if ( F_206 ( V_323 ) ) {
F_50 ( L_250 , V_146 -> V_352 ) ;
F_207 ( & V_146 -> V_374 ) ;
F_198 ( V_146 ) ;
return F_208 ( V_323 ) ;
}
F_209 ( V_323 , V_352 ) ;
V_146 -> V_330 = V_323 ;
V_372 = F_63 ( V_146 -> V_330 -> V_331 , 0600 , V_162 ,
& V_376 , V_146 ) ;
if ( ! V_372 ) {
F_50 ( L_247 ,
V_368 , V_146 -> V_330 -> V_331 ) ;
F_210 ( V_323 ) ;
F_207 ( & V_146 -> V_374 ) ;
F_198 ( V_146 ) ;
return - V_125 ;
}
F_211 ( V_323 ) ;
F_212 ( & V_146 -> V_354 ) ;
return 0 ;
}
static void F_213 ( struct V_145 * V_146 ,
struct V_21 * V_22 )
{
struct V_326 * V_327 , * V_113 ;
struct V_21 * V_323 ;
F_163 (q, n, &t->if_list) {
V_323 = F_164 ( V_327 , struct V_21 , V_329 ) ;
if ( V_323 == V_22 )
F_207 ( & V_323 -> V_329 ) ;
}
}
static int F_165 ( struct V_145 * V_146 ,
struct V_21 * V_22 )
{
F_60 ( L_251 , V_22 ) ;
if ( V_22 -> V_86 ) {
F_13 ( L_252 ) ;
F_159 ( V_22 ) ;
}
if ( V_22 -> V_50 ) {
F_70 ( V_22 -> V_50 ) ;
V_22 -> V_50 = NULL ;
}
F_213 ( V_146 , V_22 ) ;
if ( V_22 -> V_161 )
F_62 ( V_22 -> V_161 -> V_122 , V_162 ) ;
#ifdef F_21
F_116 ( V_22 ) ;
#endif
F_199 ( V_22 -> V_212 ) ;
if ( V_22 -> V_133 )
F_37 ( V_22 -> V_133 ) ;
F_198 ( V_22 ) ;
return 0 ;
}
static int T_14 F_214 ( void )
{
int V_352 ;
struct V_371 * V_372 ;
int V_147 = 0 ;
F_35 ( L_253 , V_9 ) ;
V_162 = F_215 ( V_368 , V_168 . V_377 ) ;
if ( ! V_162 )
return - V_174 ;
V_372 = F_216 ( V_378 , 0600 , V_162 , & V_379 ) ;
if ( V_372 == NULL ) {
F_50 ( L_254 , V_378 ) ;
V_147 = - V_125 ;
goto V_380;
}
F_217 ( & V_381 ) ;
F_218 (cpu) {
int V_14 ;
V_14 = F_200 ( V_352 ) ;
if ( V_14 )
F_13 ( L_255 ,
V_352 , V_14 ) ;
}
if ( F_219 ( & V_375 ) ) {
F_50 ( L_256 ) ;
V_147 = - V_174 ;
goto V_382;
}
return 0 ;
V_382:
F_220 ( & V_381 ) ;
F_62 ( V_378 , V_162 ) ;
V_380:
F_221 ( & V_168 , V_368 ) ;
return V_147 ;
}
static void T_15 F_222 ( void )
{
struct V_145 * V_146 ;
struct V_326 * V_327 , * V_113 ;
V_355 = true ;
F_163 (q, n, &pktgen_threads) {
V_146 = F_164 ( V_327 , struct V_145 , V_374 ) ;
F_210 ( V_146 -> V_330 ) ;
F_198 ( V_146 ) ;
}
F_220 ( & V_381 ) ;
F_62 ( V_378 , V_162 ) ;
F_221 ( & V_168 , V_368 ) ;
}
