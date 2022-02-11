static void
F_1 ( void )
{
V_1 = TRUE ;
V_2 = TRUE ;
V_3 = TRUE ;
V_4 = TRUE ;
V_5 = TRUE ;
V_6 = TRUE ;
V_7 = TRUE ;
V_8 = TRUE ;
V_9 = TRUE ;
V_10 = TRUE ;
V_11 = TRUE ;
V_12 = TRUE ;
V_13 = TRUE ;
V_14 = TRUE ;
V_15 = TRUE ;
V_16 = TRUE ;
#ifdef F_2
V_17 = TRUE ;
#endif
}
static void
F_3 ( void )
{
V_1 = FALSE ;
V_2 = FALSE ;
V_3 = FALSE ;
V_4 = FALSE ;
V_5 = FALSE ;
V_6 = FALSE ;
V_7 = FALSE ;
V_8 = FALSE ;
V_9 = FALSE ;
V_10 = FALSE ;
V_11 = FALSE ;
V_12 = FALSE ;
V_13 = FALSE ;
V_14 = FALSE ;
V_15 = FALSE ;
V_16 = FALSE ;
#ifdef F_2
V_17 = FALSE ;
#endif
}
static const T_1 *
F_4 ( T_2 V_18 )
{
switch ( V_18 ) {
case V_19 :
return L_1 ;
case V_20 :
return L_2 ;
case V_21 :
return L_3 ;
default:
return L_4 ;
}
}
static T_1 *
F_5 ( T_3 V_22 , T_4 * V_23 , T_5 V_24 )
{
const T_1 * V_25 = V_24 ? L_5 : L_6 ;
static T_1 V_26 [ 20 ] ;
char * V_27 ;
if ( V_23 -> V_28 && V_23 -> V_29 > 0 ) {
if ( V_30 ) {
F_6 ( V_26 , 20 , L_7 , ( unsigned long ) V_22 , V_25 ) ;
return V_26 ;
} else {
#if ( V_31 V_32 ) && ( V_33 < 1500 )
if ( V_22 > 2000000000 ) {
V_27 = NULL ;
} else
#endif
V_27 = ctime ( & V_22 ) ;
if ( V_27 == NULL ) {
F_6 ( V_26 , 20 , L_8 , V_25 ) ;
return V_26 ;
}
if ( ! V_24 ) {
V_27 [ 24 ] = '\0' ;
}
return V_27 ;
}
}
F_6 ( V_26 , 15 , L_9 , V_25 ) ;
return V_26 ;
}
static double
F_7 ( const struct V_34 * V_35 )
{
return ( V_35 -> V_36 / 1000000000.0 ) + ( double ) V_35 -> V_37 ;
}
static void F_8 ( const T_1 * V_38 , T_6 V_39 , const T_1 * V_40 , double V_41 ) {
if ( V_41 > 0.0 )
printf ( L_10 , V_38 , V_39 , V_41 , V_40 ) ;
else
printf ( L_11 , V_38 ) ;
}
static void
F_9 ( const T_1 * V_42 , T_4 * V_23 )
{
const T_1 * V_43 , * V_44 ;
T_3 V_45 ;
T_3 V_46 ;
T_1 * V_47 ;
V_43 = F_10 ( V_23 -> V_48 ) ;
V_44 = F_11 ( V_23 -> V_49 ) ;
V_45 = ( T_3 ) V_23 -> V_50 ;
V_46 = ( T_3 ) V_23 -> V_51 ;
if ( V_42 ) printf ( L_12 , V_42 ) ;
if ( V_2 ) printf ( L_13 ,
V_43 ,
V_23 -> V_52 ? L_14 : L_6 ) ;
if ( V_3 ) printf ( L_15 , V_44 ) ;
if ( V_3 && ( V_23 -> V_49 == V_53 ) ) {
int V_54 ;
for ( V_54 = 0 ; V_54 < V_55 ; V_54 ++ ) {
if ( V_23 -> V_56 [ V_54 ] > 0 )
printf ( L_16 , F_11 ( V_54 ) ) ;
}
}
if ( V_4 && V_23 -> V_57 )
printf ( L_17 , V_23 -> V_58 ) ;
else if( V_4 && ! V_23 -> V_57 )
printf ( L_18 ) ;
if ( V_23 -> V_59 > 0 ) {
if ( V_23 -> V_60 == V_23 -> V_59 )
printf ( L_19 , V_23 -> V_60 ) ;
else
printf ( L_20 ,
V_23 -> V_60 , V_23 -> V_59 ) ;
}
if ( V_5 ) {
printf ( L_21 ) ;
if ( V_61 ) {
printf ( L_22 , V_23 -> V_29 ) ;
} else {
V_47 = F_12 ( V_23 -> V_29 , V_62 ) ;
printf ( L_23 , V_47 ) ;
F_13 ( V_47 ) ;
}
}
if ( V_6 ) {
printf ( L_24 ) ;
if ( V_61 ) {
printf ( L_25 V_63 L_26 , V_23 -> V_64 ) ;
} else {
V_47 = F_12 ( V_23 -> V_64 , V_65 ) ;
printf ( L_23 , V_47 ) ;
F_13 ( V_47 ) ;
}
}
if ( V_8 ) {
printf ( L_27 ) ;
if ( V_61 ) {
printf ( L_25 V_63 L_28 , V_23 -> V_66 ) ;
} else {
V_47 = F_12 ( V_23 -> V_66 , V_65 ) ;
printf ( L_23 , V_47 ) ;
F_13 ( V_47 ) ;
}
}
if ( V_23 -> V_28 ) {
if ( V_9 )
F_8 ( L_29 , 0 , L_30 , V_23 -> V_67 ) ;
if ( V_10 )
printf ( L_31 , F_5 ( V_45 , V_23 , TRUE ) ) ;
if ( V_11 )
printf ( L_32 , F_5 ( V_46 , V_23 , TRUE ) ) ;
if ( V_13 ) {
printf ( L_33 ) ;
if ( V_61 ) {
F_8 ( L_6 , 2 , L_34 , V_23 -> V_68 ) ;
} else {
V_47 = F_12 ( ( V_69 ) V_23 -> V_68 , V_70 ) ;
printf ( L_23 , V_47 ) ;
F_13 ( V_47 ) ;
}
}
if ( V_14 ) {
printf ( L_35 ) ;
if ( V_61 ) {
F_8 ( L_6 , 2 , L_36 , V_23 -> V_68 * 8 ) ;
} else {
V_47 = F_12 ( ( V_69 ) ( V_23 -> V_68 * 8 ) , V_71 ) ;
printf ( L_23 , V_47 ) ;
F_13 ( V_47 ) ;
}
}
}
if ( V_15 ) printf ( L_37 , V_23 -> V_72 ) ;
if ( V_23 -> V_28 ) {
if ( V_16 ) {
printf ( L_38 ) ;
if ( V_61 ) {
F_8 ( L_6 , 2 , L_39 , V_23 -> V_73 ) ;
} else {
V_47 = F_12 ( ( V_69 ) V_23 -> V_73 , V_62 ) ;
printf ( L_40 , V_47 ) ;
F_13 ( V_47 ) ;
}
}
}
#ifdef F_2
if ( V_17 ) {
printf ( L_41 , V_74 ) ;
printf ( L_42 , V_75 ) ;
printf ( L_43 , V_76 ) ;
}
#endif
if ( V_12 ) printf ( L_44 , F_4 ( V_23 -> V_18 ) ) ;
if ( V_7 && V_23 -> V_77 )
printf ( L_45 , V_23 -> V_77 ) ;
}
static void
F_14 ( void )
{
if ( V_78 ) putchar ( V_78 ) ;
}
static void
F_15 ( void )
{
if ( V_79 ) putchar ( V_79 ) ;
}
static void
F_16 ( const T_1 * V_80 )
{
F_14 () ;
F_15 () ;
printf ( L_46 , V_80 ) ;
F_15 () ;
}
static void
F_17 ( void )
{
F_15 () ;
printf ( L_47 ) ;
F_15 () ;
if ( V_2 ) F_16 ( L_48 ) ;
if ( V_3 ) F_16 ( L_49 ) ;
if ( V_4 ) F_16 ( L_50 ) ;
if ( V_4 ) F_16 ( L_51 ) ;
if ( V_4 ) F_16 ( L_52 ) ;
if ( V_5 ) F_16 ( L_53 ) ;
if ( V_6 ) F_16 ( L_54 ) ;
if ( V_8 ) F_16 ( L_55 ) ;
if ( V_9 ) F_16 ( L_56 ) ;
if ( V_10 ) F_16 ( L_57 ) ;
if ( V_11 ) F_16 ( L_58 ) ;
if ( V_13 ) F_16 ( L_59 ) ;
if ( V_14 ) F_16 ( L_60 ) ;
if ( V_15 ) F_16 ( L_61 ) ;
if ( V_16 ) F_16 ( L_62 ) ;
#ifdef F_2
if ( V_17 ) {
F_16 ( L_63 ) ;
F_16 ( L_64 ) ;
F_16 ( L_65 ) ;
}
#endif
if ( V_12 ) F_16 ( L_66 ) ;
if ( V_7 ) F_16 ( L_67 ) ;
printf ( L_5 ) ;
}
static void
F_18 ( const T_1 * V_42 , T_4 * V_23 )
{
const T_1 * V_43 , * V_44 ;
T_3 V_45 ;
T_3 V_46 ;
V_43 = F_10 ( V_23 -> V_48 ) ;
V_44 = F_11 ( V_23 -> V_49 ) ;
V_45 = ( T_3 ) V_23 -> V_50 ;
V_46 = ( T_3 ) V_23 -> V_51 ;
if ( V_42 ) {
F_15 () ;
printf ( L_46 , V_42 ) ;
F_15 () ;
}
if ( V_2 ) {
F_14 () ;
F_15 () ;
printf ( L_46 , V_43 ) ;
F_15 () ;
}
if ( V_3 ) {
F_14 () ;
F_15 () ;
printf ( L_46 , V_44 ) ;
F_15 () ;
}
if ( V_4 ) {
F_14 () ;
F_15 () ;
if( V_23 -> V_57 )
printf ( L_68 , V_23 -> V_58 ) ;
else
printf ( L_69 ) ;
F_15 () ;
if ( V_23 -> V_59 > 0 ) {
F_14 () ;
F_15 () ;
printf ( L_68 , V_23 -> V_60 ) ;
F_15 () ;
F_14 () ;
F_15 () ;
printf ( L_68 , V_23 -> V_59 ) ;
F_15 () ;
}
else {
F_14 () ;
F_15 () ;
printf ( L_70 ) ;
F_15 () ;
F_14 () ;
F_15 () ;
printf ( L_70 ) ;
F_15 () ;
}
}
if ( V_5 ) {
F_14 () ;
F_15 () ;
printf ( L_68 , V_23 -> V_29 ) ;
F_15 () ;
}
if ( V_6 ) {
F_14 () ;
F_15 () ;
printf ( L_25 V_63 L_71 , V_23 -> V_64 ) ;
F_15 () ;
}
if ( V_8 ) {
F_14 () ;
F_15 () ;
printf ( L_25 V_63 L_72 , V_23 -> V_66 ) ;
F_15 () ;
}
if ( V_9 ) {
F_14 () ;
F_15 () ;
if ( V_23 -> V_28 )
printf ( L_73 , V_23 -> V_67 ) ;
else
printf ( L_70 ) ;
F_15 () ;
}
if ( V_10 ) {
F_14 () ;
F_15 () ;
printf ( L_46 , F_5 ( V_45 , V_23 , FALSE ) ) ;
F_15 () ;
}
if ( V_11 ) {
F_14 () ;
F_15 () ;
printf ( L_46 , F_5 ( V_46 , V_23 , FALSE ) ) ;
F_15 () ;
}
if ( V_13 ) {
F_14 () ;
F_15 () ;
if ( V_23 -> V_28 )
printf ( L_74 , V_23 -> V_68 ) ;
else
printf ( L_70 ) ;
F_15 () ;
}
if ( V_14 ) {
F_14 () ;
F_15 () ;
if ( V_23 -> V_28 )
printf ( L_74 , V_23 -> V_68 * 8 ) ;
else
printf ( L_70 ) ;
F_15 () ;
}
if ( V_15 ) {
F_14 () ;
F_15 () ;
printf ( L_74 , V_23 -> V_72 ) ;
F_15 () ;
}
if ( V_16 ) {
F_14 () ;
F_15 () ;
if ( V_23 -> V_28 )
printf ( L_74 , V_23 -> V_73 ) ;
else
printf ( L_70 ) ;
F_15 () ;
}
#ifdef F_2
if ( V_17 ) {
F_14 () ;
F_15 () ;
printf ( L_46 , V_74 ) ;
F_15 () ;
F_14 () ;
F_15 () ;
printf ( L_46 , V_75 ) ;
F_15 () ;
F_14 () ;
F_15 () ;
printf ( L_46 , V_76 ) ;
F_15 () ;
}
#endif
if ( V_12 ) {
F_14 () ;
F_15 () ;
printf ( L_46 , F_4 ( V_23 -> V_18 ) ) ;
F_15 () ;
}
if ( V_7 ) {
F_14 () ;
F_15 () ;
printf ( L_46 , V_23 -> V_77 ) ;
F_15 () ;
}
printf ( L_5 ) ;
}
static int
F_19 ( T_7 * V_81 , const char * V_42 )
{
int V_82 ;
T_1 * V_83 ;
V_69 V_84 ;
V_69 V_85 ;
T_8 V_86 = 0 ;
V_69 V_87 = 0 ;
T_8 V_60 = 0xffffffff ;
T_8 V_59 = 0 ;
const struct V_88 * V_89 ;
T_4 V_23 ;
T_5 V_90 = TRUE ;
double V_50 = 0 ;
double V_51 = 0 ;
double V_91 = 0 ;
double V_92 = 0 ;
T_5 V_93 = FALSE ;
T_2 V_18 = V_19 ;
T_9 * V_94 ;
T_1 * V_95 ;
V_23 . V_56 = F_20 ( int , V_55 ) ;
while ( F_21 ( V_81 , & V_82 , & V_83 , & V_85 ) ) {
V_89 = F_22 ( V_81 ) ;
if ( V_89 -> V_96 & V_97 ) {
V_92 = V_91 ;
V_91 = F_7 ( & V_89 -> V_98 ) ;
if( V_86 == 0 ) {
V_50 = V_91 ;
V_51 = V_91 ;
V_92 = V_91 ;
}
if ( V_91 < V_92 ) {
V_18 = V_20 ;
}
if ( V_91 < V_50 ) {
V_50 = V_91 ;
}
if ( V_91 > V_51 ) {
V_51 = V_91 ;
}
} else {
V_90 = FALSE ;
if ( V_18 != V_20 )
V_18 = V_21 ;
}
V_87 += V_89 -> V_99 ;
V_86 ++ ;
if ( V_89 -> V_100 < V_89 -> V_99 ) {
if ( V_89 -> V_100 < V_60 )
V_60 = V_89 -> V_100 ;
if ( V_89 -> V_100 > V_59 )
V_59 = V_89 -> V_100 ;
}
if ( F_23 ( V_81 ) == V_53 ) {
if ( ( V_89 -> V_101 > 0 ) && ( V_89 -> V_101 < V_55 ) ) {
V_23 . V_56 [ V_89 -> V_101 ] += 1 ;
} else {
fprintf ( V_102 , L_75 , V_89 -> V_101 , V_86 ) ;
}
}
}
if ( V_82 != 0 ) {
fprintf ( V_102 ,
L_76 ,
V_86 , V_42 , F_24 ( V_82 ) ) ;
switch ( V_82 ) {
case V_103 :
case V_104 :
case V_105 :
case V_106 :
fprintf ( V_102 , L_77 , V_83 ) ;
F_13 ( V_83 ) ;
break;
}
F_13 ( V_23 . V_56 ) ;
return 1 ;
}
V_84 = F_25 ( V_81 , & V_82 ) ;
if ( V_84 == - 1 ) {
fprintf ( V_102 ,
L_78 ,
V_42 , F_26 ( V_82 ) ) ;
F_13 ( V_23 . V_56 ) ;
return 1 ;
}
V_23 . V_64 = V_84 ;
V_23 . V_48 = F_27 ( V_81 ) ;
V_23 . V_52 = F_28 ( V_81 ) ;
V_23 . V_49 = F_23 ( V_81 ) ;
V_23 . V_58 = F_29 ( V_81 ) ;
if( V_23 . V_58 > 0 )
V_23 . V_57 = TRUE ;
else
V_23 . V_57 = FALSE ;
V_23 . V_60 = V_60 ;
V_23 . V_59 = V_59 ;
V_23 . V_29 = V_86 ;
V_23 . V_28 = V_90 ;
V_23 . V_50 = V_50 ;
V_23 . V_51 = V_51 ;
V_23 . V_67 = V_51 - V_50 ;
V_23 . V_93 = V_93 ;
V_23 . V_18 = V_18 ;
V_23 . V_66 = V_87 ;
V_23 . V_68 = 0.0 ;
V_23 . V_73 = 0.0 ;
V_23 . V_72 = 0.0 ;
if ( V_86 > 0 ) {
if ( V_23 . V_67 > 0.0 ) {
V_23 . V_68 = ( double ) V_87 / ( V_51 - V_50 ) ;
V_23 . V_73 = ( double ) V_86 / ( V_51 - V_50 ) ;
}
V_23 . V_72 = ( double ) V_87 / V_86 ;
}
V_23 . V_77 = NULL ;
V_94 = F_30 ( V_81 ) ;
if ( V_94 ) {
V_23 . V_77 = F_31 ( V_94 -> V_107 ) ;
}
F_13 ( V_94 ) ;
if ( V_23 . V_77 ) {
V_95 = V_23 . V_77 ;
while ( * V_95 != '\0' ) {
if ( * V_95 == '\n' )
* V_95 = ' ' ;
V_95 ++ ;
}
}
if( V_108 ) {
F_9 ( V_42 , & V_23 ) ;
} else {
F_18 ( V_42 , & V_23 ) ;
}
F_13 ( V_23 . V_56 ) ;
F_13 ( V_23 . V_77 ) ;
return 0 ;
}
static void
F_32 ( T_5 V_109 )
{
T_10 * V_110 ;
if ( ! V_109 ) {
V_110 = stdout ;
}
else {
V_110 = V_102 ;
}
fprintf ( V_110 , L_79
#ifdef F_33
L_80 F_33 L_81 V_111 L_82
#endif
L_5 , V_112 ) ;
fprintf ( V_110 , L_83 ) ;
fprintf ( V_110 , L_84 ) ;
fprintf ( V_110 , L_5 ) ;
fprintf ( V_110 , L_85 ) ;
fprintf ( V_110 , L_5 ) ;
fprintf ( V_110 , L_86 ) ;
fprintf ( V_110 , L_87 ) ;
fprintf ( V_110 , L_88 ) ;
#ifdef F_2
fprintf ( V_110 , L_89 ) ;
#endif
fprintf ( V_110 , L_90 ) ;
fprintf ( V_110 , L_5 ) ;
fprintf ( V_110 , L_91 ) ;
fprintf ( V_110 , L_92 ) ;
fprintf ( V_110 , L_93 ) ;
fprintf ( V_110 , L_94 ) ;
fprintf ( V_110 , L_95 ) ;
fprintf ( V_110 , L_5 ) ;
fprintf ( V_110 , L_96 ) ;
fprintf ( V_110 , L_97 ) ;
fprintf ( V_110 , L_98 ) ;
fprintf ( V_110 , L_99 ) ;
fprintf ( V_110 , L_100 ) ;
fprintf ( V_110 , L_101 ) ;
fprintf ( V_110 , L_5 ) ;
fprintf ( V_110 , L_102 ) ;
fprintf ( V_110 , L_103 ) ;
fprintf ( V_110 , L_104 ) ;
fprintf ( V_110 , L_105 ) ;
fprintf ( V_110 , L_106 ) ;
fprintf ( V_110 , L_5 ) ;
fprintf ( V_110 , L_107 ) ;
fprintf ( V_110 , L_108 ) ;
fprintf ( V_110 , L_109 ) ;
fprintf ( V_110 , L_110 ) ;
fprintf ( V_110 , L_5 ) ;
fprintf ( V_110 , L_111 ) ;
fprintf ( V_110 , L_112 ) ;
fprintf ( V_110 , L_113 ) ;
fprintf ( V_110 , L_5 ) ;
fprintf ( V_110 , L_114 ) ;
fprintf ( V_110 , L_115 ) ;
fprintf ( V_110 , L_116 ) ;
fprintf ( V_110 , L_5 ) ;
fprintf ( V_110 , L_117 ) ;
fprintf ( V_110 , L_118 ) ;
fprintf ( V_110 , L_119 ) ;
fprintf ( V_110 , L_5 ) ;
fprintf ( V_110 , L_120 ) ;
fprintf ( V_110 , L_121 ) ;
fprintf ( V_110 , L_122 ) ;
fprintf ( V_110 , L_123 ) ;
fprintf ( V_110 , L_5 ) ;
fprintf ( V_110 , L_124 ) ;
fprintf ( V_110 , L_125 ) ;
fprintf ( V_110 , L_5 ) ;
fprintf ( V_110 , L_126 ) ;
fprintf ( V_110 , L_127 ) ;
#ifndef F_2
fprintf ( V_110 , L_128 ) ;
#endif
}
static void
F_34 ( const char * T_11 V_113 , T_12 T_13 V_113 )
{
return;
}
static void
F_35 ( const unsigned char * V_114 , T_14 V_115 , char * V_116 ) {
int V_54 ;
for ( V_54 = 0 ; V_54 < ( int ) V_115 ; V_54 ++ ) {
F_6 ( V_116 + ( V_54 * 2 ) , 3 , L_129 , V_114 [ V_54 ] ) ;
}
}
int
main ( int V_117 , char * V_118 [] )
{
T_7 * V_81 ;
int V_82 ;
T_1 * V_83 ;
int V_119 ;
int V_120 ;
int V_121 = 0 ;
#ifdef F_36
char * V_122 ;
#endif
#ifdef F_2
T_10 * V_123 ;
char * V_124 = NULL ;
T_15 V_125 = NULL ;
T_14 V_126 ;
#endif
#ifdef V_32
F_37 ( V_117 , V_118 ) ;
F_38 () ;
#endif
F_39 () ;
#ifdef F_36
if ( ( V_122 = F_40 ( V_118 [ 0 ] , main ) ) ) {
F_41 ( L_130 , V_122 ) ;
F_13 ( V_122 ) ;
} else {
F_42 ( F_34 , NULL , NULL , NULL ) ;
F_43 () ;
}
#endif
#ifdef F_44
V_127 = F_45 ( L_131 ) ;
V_128 = F_46 ( L_132 , L_133 ,
L_134 , NULL , NULL ) ;
V_129 = F_46 ( L_135 , L_136 ,
L_137 , NULL , NULL ) ;
V_130 = F_46 ( L_138 , L_139 ,
L_140 , NULL , NULL ) ;
V_131 = F_46 ( L_141 , L_142 ,
L_143 , NULL , NULL ) ;
V_132 = F_46 ( L_144 , L_145 ,
L_146 , NULL , NULL ) ;
V_133 = F_46 ( L_147 , L_148 ,
L_149 , NULL , NULL ) ;
F_47 ( V_128 , V_134 ) ;
F_47 ( V_129 , V_135 ) ;
F_47 ( V_130 , V_136 ) ;
F_47 ( V_131 , V_137 ) ;
F_47 ( V_132 , V_138 ) ;
F_47 ( V_133 , V_139 ) ;
F_48 ( V_127 , V_140 , NULL ) ;
F_49 ( V_127 , V_128 ) ;
F_49 ( V_127 , V_129 ) ;
F_49 ( V_127 , V_130 ) ;
F_49 ( V_127 , V_131 ) ;
F_49 ( V_127 , V_132 ) ;
F_49 ( V_127 , V_133 ) ;
V_118 [ 0 ] = ( char * ) L_150 ;
if ( V_117 >= 2 && V_1 )
F_3 () ;
if( ! F_50 ( V_127 , & V_117 , & V_118 , & V_141 ) ) {
if( V_141 ) F_51 ( L_151 , V_141 -> V_142 ) ;
F_51 ( L_46 , F_52 ( V_127 , TRUE , NULL ) ) ;
exit ( 1 ) ;
}
if( V_143 || ( V_117 < 2 ) ) {
F_51 ( L_46 , F_52 ( V_127 , FALSE , NULL ) ) ;
exit ( 0 ) ;
}
F_53 ( V_127 ) ;
#endif
while ( ( V_119 = F_54 ( V_117 , V_118 , L_152 V_144 L_153 ) ) != - 1 ) {
switch ( V_119 ) {
case 't' :
if ( V_1 ) F_3 () ;
V_2 = TRUE ;
break;
case 'E' :
if ( V_1 ) F_3 () ;
V_3 = TRUE ;
break;
case 'l' :
if ( V_1 ) F_3 () ;
V_4 = TRUE ;
break;
case 'c' :
if ( V_1 ) F_3 () ;
V_5 = TRUE ;
break;
case 's' :
if ( V_1 ) F_3 () ;
V_6 = TRUE ;
break;
case 'd' :
if ( V_1 ) F_3 () ;
V_8 = TRUE ;
break;
case 'u' :
if ( V_1 ) F_3 () ;
V_9 = TRUE ;
break;
case 'a' :
if ( V_1 ) F_3 () ;
V_10 = TRUE ;
break;
case 'e' :
if ( V_1 ) F_3 () ;
V_11 = TRUE ;
break;
case 'S' :
V_30 = TRUE ;
break;
case 'y' :
if ( V_1 ) F_3 () ;
V_13 = TRUE ;
break;
case 'i' :
if ( V_1 ) F_3 () ;
V_14 = TRUE ;
break;
case 'z' :
if ( V_1 ) F_3 () ;
V_15 = TRUE ;
break;
case 'x' :
if ( V_1 ) F_3 () ;
V_16 = TRUE ;
break;
#ifdef F_2
case 'H' :
if ( V_1 ) F_3 () ;
V_17 = TRUE ;
break;
#endif
case 'o' :
if ( V_1 ) F_3 () ;
V_12 = TRUE ;
break;
case 'k' :
if ( V_1 ) F_3 () ;
V_7 = TRUE ;
break;
case 'C' :
V_145 = FALSE ;
break;
case 'A' :
F_1 () ;
break;
case 'L' :
V_108 = TRUE ;
break;
case 'T' :
V_108 = FALSE ;
break;
case 'M' :
V_61 = TRUE ;
break;
case 'R' :
V_146 = TRUE ;
break;
case 'r' :
V_146 = FALSE ;
break;
case 'N' :
V_79 = '\0' ;
break;
case 'q' :
V_79 = '\'' ;
break;
case 'Q' :
V_79 = '"' ;
break;
case 'B' :
V_78 = '\t' ;
break;
case 'm' :
V_78 = ',' ;
break;
case 'b' :
V_78 = ' ' ;
break;
case 'h' :
F_32 ( FALSE ) ;
exit ( 1 ) ;
break;
case '?' :
F_32 ( TRUE ) ;
exit ( 1 ) ;
break;
}
}
setlocale ( V_147 , L_6 ) ;
if ( ( V_117 - V_148 ) < 1 ) {
F_32 ( TRUE ) ;
exit ( 1 ) ;
}
if( ! V_108 && V_146 ) {
F_17 () ;
}
#ifdef F_2
if ( V_17 ) {
F_55 ( NULL ) ;
F_56 ( & V_125 , V_149 , 0 ) ;
if ( V_125 ) {
F_57 ( V_125 , V_150 ) ;
F_57 ( V_125 , V_151 ) ;
}
V_124 = ( char * ) F_58 ( V_152 ) ;
}
#endif
V_120 = 0 ;
for ( V_119 = V_148 ; V_119 < V_117 ; V_119 ++ ) {
#ifdef F_2
F_59 ( V_74 , L_154 , V_153 ) ;
F_59 ( V_75 , L_154 , V_153 ) ;
F_59 ( V_76 , L_154 , V_153 ) ;
if ( V_17 ) {
V_123 = F_60 ( V_118 [ V_119 ] , L_155 ) ;
if ( V_123 && V_125 ) {
while( ( V_126 = fread ( V_124 , 1 , V_152 , V_123 ) ) > 0 ) {
F_61 ( V_125 , V_124 , V_126 ) ;
}
F_62 ( V_125 ) ;
F_35 ( F_63 ( V_125 , V_149 ) , V_154 , V_74 ) ;
F_35 ( F_63 ( V_125 , V_150 ) , V_155 , V_75 ) ;
F_35 ( F_63 ( V_125 , V_151 ) , V_156 , V_76 ) ;
}
if ( V_123 ) fclose ( V_123 ) ;
if ( V_125 ) F_64 ( V_125 ) ;
}
#endif
V_81 = F_65 ( V_118 [ V_119 ] , & V_82 , & V_83 , FALSE ) ;
if ( ! V_81 ) {
fprintf ( V_102 , L_156 , V_118 [ V_119 ] ,
F_24 ( V_82 ) ) ;
switch ( V_82 ) {
case V_103 :
case V_104 :
case V_105 :
fprintf ( V_102 , L_77 , V_83 ) ;
F_13 ( V_83 ) ;
break;
}
V_120 = 1 ;
if( ! V_145 )
exit ( 1 ) ;
}
if( V_81 ) {
if ( ( V_119 > V_148 ) && ( V_108 ) )
printf ( L_5 ) ;
V_121 = F_19 ( V_81 , V_118 [ V_119 ] ) ;
F_66 ( V_81 ) ;
if ( V_121 )
exit ( V_121 ) ;
}
}
return V_120 ;
}
