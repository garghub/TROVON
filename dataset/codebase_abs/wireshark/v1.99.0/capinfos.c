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
static void F_7 ( const T_1 * V_31 , T_6 V_32 , const T_1 * V_33 , double V_34 ) {
if ( V_34 > 0.0 )
printf ( L_10 , V_31 , V_32 , V_34 , V_33 ) ;
else
printf ( L_11 , V_31 ) ;
}
static void
F_8 ( const T_1 * V_35 , T_4 * V_23 )
{
const T_1 * V_36 , * V_37 ;
T_3 V_38 ;
T_3 V_39 ;
T_1 * V_40 ;
V_36 = F_9 ( V_23 -> V_41 ) ;
V_37 = F_10 ( V_23 -> V_42 ) ;
V_38 = ( T_3 ) V_23 -> V_43 ;
V_39 = ( T_3 ) V_23 -> V_44 ;
if ( V_35 ) printf ( L_12 , V_35 ) ;
if ( V_2 ) printf ( L_13 ,
V_36 ,
V_23 -> V_45 ? L_14 : L_6 ) ;
if ( V_3 ) printf ( L_15 , V_37 ) ;
if ( V_3 && ( V_23 -> V_42 == V_46 ) ) {
int V_47 ;
for ( V_47 = 0 ; V_47 < V_48 ; V_47 ++ ) {
if ( V_23 -> V_49 [ V_47 ] > 0 )
printf ( L_16 , F_10 ( V_47 ) ) ;
}
}
if ( V_4 && V_23 -> V_50 )
printf ( L_17 , V_23 -> V_51 ) ;
else if ( V_4 && ! V_23 -> V_50 )
printf ( L_18 ) ;
if ( V_23 -> V_52 > 0 ) {
if ( V_23 -> V_53 == V_23 -> V_52 )
printf ( L_19 , V_23 -> V_53 ) ;
else
printf ( L_20 ,
V_23 -> V_53 , V_23 -> V_52 ) ;
}
if ( V_5 ) {
printf ( L_21 ) ;
if ( V_54 ) {
printf ( L_22 , V_23 -> V_29 ) ;
} else {
V_40 = F_11 ( V_23 -> V_29 , V_55 ) ;
printf ( L_23 , V_40 ) ;
F_12 ( V_40 ) ;
}
}
if ( V_6 ) {
printf ( L_24 ) ;
if ( V_54 ) {
printf ( L_25 V_56 L_26 , V_23 -> V_57 ) ;
} else {
V_40 = F_11 ( V_23 -> V_57 , V_58 ) ;
printf ( L_23 , V_40 ) ;
F_12 ( V_40 ) ;
}
}
if ( V_8 ) {
printf ( L_27 ) ;
if ( V_54 ) {
printf ( L_25 V_56 L_28 , V_23 -> V_59 ) ;
} else {
V_40 = F_11 ( V_23 -> V_59 , V_58 ) ;
printf ( L_23 , V_40 ) ;
F_12 ( V_40 ) ;
}
}
if ( V_23 -> V_28 ) {
if ( V_9 )
F_7 ( L_29 , 0 , L_30 , V_23 -> V_60 ) ;
if ( V_10 )
printf ( L_31 , F_5 ( V_38 , V_23 , TRUE ) ) ;
if ( V_11 )
printf ( L_32 , F_5 ( V_39 , V_23 , TRUE ) ) ;
if ( V_13 ) {
printf ( L_33 ) ;
if ( V_54 ) {
F_7 ( L_6 , 2 , L_34 , V_23 -> V_61 ) ;
} else {
V_40 = F_11 ( ( V_62 ) V_23 -> V_61 , V_63 ) ;
printf ( L_23 , V_40 ) ;
F_12 ( V_40 ) ;
}
}
if ( V_14 ) {
printf ( L_35 ) ;
if ( V_54 ) {
F_7 ( L_6 , 2 , L_36 , V_23 -> V_61 * 8 ) ;
} else {
V_40 = F_11 ( ( V_62 ) ( V_23 -> V_61 * 8 ) , V_64 ) ;
printf ( L_23 , V_40 ) ;
F_12 ( V_40 ) ;
}
}
}
if ( V_15 ) printf ( L_37 , V_23 -> V_65 ) ;
if ( V_23 -> V_28 ) {
if ( V_16 ) {
printf ( L_38 ) ;
if ( V_54 ) {
F_7 ( L_6 , 2 , L_39 , V_23 -> V_66 ) ;
} else {
V_40 = F_11 ( ( V_62 ) V_23 -> V_66 , V_67 ) ;
printf ( L_23 , V_40 ) ;
F_12 ( V_40 ) ;
}
}
}
#ifdef F_2
if ( V_17 ) {
printf ( L_40 , V_68 ) ;
printf ( L_41 , V_69 ) ;
printf ( L_42 , V_70 ) ;
}
#endif
if ( V_12 ) printf ( L_43 , F_4 ( V_23 -> V_18 ) ) ;
if ( V_7 && V_23 -> V_71 )
printf ( L_44 , V_23 -> V_71 ) ;
}
static void
F_13 ( void )
{
if ( V_72 ) putchar ( V_72 ) ;
}
static void
F_14 ( void )
{
if ( V_73 ) putchar ( V_73 ) ;
}
static void
F_15 ( const T_1 * V_74 )
{
F_13 () ;
F_14 () ;
printf ( L_45 , V_74 ) ;
F_14 () ;
}
static void
F_16 ( void )
{
F_14 () ;
printf ( L_46 ) ;
F_14 () ;
if ( V_2 ) F_15 ( L_47 ) ;
if ( V_3 ) F_15 ( L_48 ) ;
if ( V_4 ) F_15 ( L_49 ) ;
if ( V_4 ) F_15 ( L_50 ) ;
if ( V_4 ) F_15 ( L_51 ) ;
if ( V_5 ) F_15 ( L_52 ) ;
if ( V_6 ) F_15 ( L_53 ) ;
if ( V_8 ) F_15 ( L_54 ) ;
if ( V_9 ) F_15 ( L_55 ) ;
if ( V_10 ) F_15 ( L_56 ) ;
if ( V_11 ) F_15 ( L_57 ) ;
if ( V_13 ) F_15 ( L_58 ) ;
if ( V_14 ) F_15 ( L_59 ) ;
if ( V_15 ) F_15 ( L_60 ) ;
if ( V_16 ) F_15 ( L_61 ) ;
#ifdef F_2
if ( V_17 ) {
F_15 ( L_62 ) ;
F_15 ( L_63 ) ;
F_15 ( L_64 ) ;
}
#endif
if ( V_12 ) F_15 ( L_65 ) ;
if ( V_7 ) F_15 ( L_66 ) ;
printf ( L_5 ) ;
}
static void
F_17 ( const T_1 * V_35 , T_4 * V_23 )
{
const T_1 * V_36 , * V_37 ;
T_3 V_38 ;
T_3 V_39 ;
V_36 = F_9 ( V_23 -> V_41 ) ;
V_37 = F_10 ( V_23 -> V_42 ) ;
V_38 = ( T_3 ) V_23 -> V_43 ;
V_39 = ( T_3 ) V_23 -> V_44 ;
if ( V_35 ) {
F_14 () ;
printf ( L_45 , V_35 ) ;
F_14 () ;
}
if ( V_2 ) {
F_13 () ;
F_14 () ;
printf ( L_45 , V_36 ) ;
F_14 () ;
}
if ( V_3 ) {
F_13 () ;
F_14 () ;
printf ( L_45 , V_37 ) ;
F_14 () ;
}
if ( V_4 ) {
F_13 () ;
F_14 () ;
if ( V_23 -> V_50 )
printf ( L_67 , V_23 -> V_51 ) ;
else
printf ( L_68 ) ;
F_14 () ;
if ( V_23 -> V_52 > 0 ) {
F_13 () ;
F_14 () ;
printf ( L_67 , V_23 -> V_53 ) ;
F_14 () ;
F_13 () ;
F_14 () ;
printf ( L_67 , V_23 -> V_52 ) ;
F_14 () ;
}
else {
F_13 () ;
F_14 () ;
printf ( L_69 ) ;
F_14 () ;
F_13 () ;
F_14 () ;
printf ( L_69 ) ;
F_14 () ;
}
}
if ( V_5 ) {
F_13 () ;
F_14 () ;
printf ( L_67 , V_23 -> V_29 ) ;
F_14 () ;
}
if ( V_6 ) {
F_13 () ;
F_14 () ;
printf ( L_25 V_56 L_70 , V_23 -> V_57 ) ;
F_14 () ;
}
if ( V_8 ) {
F_13 () ;
F_14 () ;
printf ( L_25 V_56 L_71 , V_23 -> V_59 ) ;
F_14 () ;
}
if ( V_9 ) {
F_13 () ;
F_14 () ;
if ( V_23 -> V_28 )
printf ( L_72 , V_23 -> V_60 ) ;
else
printf ( L_69 ) ;
F_14 () ;
}
if ( V_10 ) {
F_13 () ;
F_14 () ;
printf ( L_45 , F_5 ( V_38 , V_23 , FALSE ) ) ;
F_14 () ;
}
if ( V_11 ) {
F_13 () ;
F_14 () ;
printf ( L_45 , F_5 ( V_39 , V_23 , FALSE ) ) ;
F_14 () ;
}
if ( V_13 ) {
F_13 () ;
F_14 () ;
if ( V_23 -> V_28 )
printf ( L_73 , V_23 -> V_61 ) ;
else
printf ( L_69 ) ;
F_14 () ;
}
if ( V_14 ) {
F_13 () ;
F_14 () ;
if ( V_23 -> V_28 )
printf ( L_73 , V_23 -> V_61 * 8 ) ;
else
printf ( L_69 ) ;
F_14 () ;
}
if ( V_15 ) {
F_13 () ;
F_14 () ;
printf ( L_73 , V_23 -> V_65 ) ;
F_14 () ;
}
if ( V_16 ) {
F_13 () ;
F_14 () ;
if ( V_23 -> V_28 )
printf ( L_73 , V_23 -> V_66 ) ;
else
printf ( L_69 ) ;
F_14 () ;
}
#ifdef F_2
if ( V_17 ) {
F_13 () ;
F_14 () ;
printf ( L_45 , V_68 ) ;
F_14 () ;
F_13 () ;
F_14 () ;
printf ( L_45 , V_69 ) ;
F_14 () ;
F_13 () ;
F_14 () ;
printf ( L_45 , V_70 ) ;
F_14 () ;
}
#endif
if ( V_12 ) {
F_13 () ;
F_14 () ;
printf ( L_45 , F_4 ( V_23 -> V_18 ) ) ;
F_14 () ;
}
if ( V_7 ) {
F_13 () ;
F_14 () ;
printf ( L_45 , V_23 -> V_71 ) ;
F_14 () ;
}
printf ( L_5 ) ;
}
static int
F_18 ( T_7 * V_75 , const char * V_35 )
{
int V_76 = 0 ;
int V_77 ;
T_1 * V_78 ;
V_62 V_79 ;
V_62 V_80 ;
T_8 V_81 = 0 ;
V_62 V_82 = 0 ;
T_8 V_53 = 0xffffffff ;
T_8 V_52 = 0 ;
const struct V_83 * V_84 ;
T_4 V_23 ;
T_5 V_85 = TRUE ;
double V_43 = 0 ;
double V_44 = 0 ;
double V_86 = 0 ;
double V_87 = 0 ;
T_5 V_88 = FALSE ;
T_2 V_18 = V_19 ;
T_9 * V_89 ;
T_1 * V_90 ;
V_23 . V_49 = F_19 ( int , V_48 ) ;
while ( F_20 ( V_75 , & V_77 , & V_78 , & V_80 ) ) {
V_84 = F_21 ( V_75 ) ;
if ( V_84 -> V_91 & V_92 ) {
V_87 = V_86 ;
V_86 = F_22 ( & V_84 -> V_93 ) ;
if ( V_81 == 0 ) {
V_43 = V_86 ;
V_44 = V_86 ;
V_87 = V_86 ;
}
if ( V_86 < V_87 ) {
V_18 = V_20 ;
}
if ( V_86 < V_43 ) {
V_43 = V_86 ;
}
if ( V_86 > V_44 ) {
V_44 = V_86 ;
}
} else {
V_85 = FALSE ;
if ( V_18 != V_20 )
V_18 = V_21 ;
}
if ( V_84 -> V_94 == V_95 ) {
V_82 += V_84 -> V_96 ;
V_81 ++ ;
if ( V_84 -> V_97 < V_84 -> V_96 ) {
if ( V_84 -> V_97 < V_53 )
V_53 = V_84 -> V_97 ;
if ( V_84 -> V_97 > V_52 )
V_52 = V_84 -> V_97 ;
}
if ( F_23 ( V_75 ) == V_46 ) {
if ( ( V_84 -> V_98 > 0 ) && ( V_84 -> V_98 < V_48 ) ) {
V_23 . V_49 [ V_84 -> V_98 ] += 1 ;
} else {
fprintf ( V_99 , L_74 , V_84 -> V_98 , V_81 ) ;
}
}
}
}
if ( V_77 != 0 ) {
fprintf ( V_99 ,
L_75 ,
V_81 , V_35 , F_24 ( V_77 ) ) ;
switch ( V_77 ) {
case V_100 :
V_76 = 1 ;
fprintf ( V_99 ,
L_76 ) ;
break;
case V_101 :
case V_102 :
case V_103 :
case V_104 :
fprintf ( V_99 , L_77 , V_78 ) ;
F_12 ( V_78 ) ;
default:
F_12 ( V_23 . V_49 ) ;
return 1 ;
}
}
V_79 = F_25 ( V_75 , & V_77 ) ;
if ( V_79 == - 1 ) {
fprintf ( V_99 ,
L_78 ,
V_35 , F_26 ( V_77 ) ) ;
F_12 ( V_23 . V_49 ) ;
return 1 ;
}
V_23 . V_57 = V_79 ;
V_23 . V_41 = F_27 ( V_75 ) ;
V_23 . V_45 = F_28 ( V_75 ) ;
V_23 . V_42 = F_23 ( V_75 ) ;
V_23 . V_51 = F_29 ( V_75 ) ;
if ( V_23 . V_51 > 0 )
V_23 . V_50 = TRUE ;
else
V_23 . V_50 = FALSE ;
V_23 . V_53 = V_53 ;
V_23 . V_52 = V_52 ;
V_23 . V_29 = V_81 ;
V_23 . V_28 = V_85 ;
V_23 . V_43 = V_43 ;
V_23 . V_44 = V_44 ;
V_23 . V_60 = V_44 - V_43 ;
V_23 . V_88 = V_88 ;
V_23 . V_18 = V_18 ;
V_23 . V_59 = V_82 ;
V_23 . V_61 = 0.0 ;
V_23 . V_66 = 0.0 ;
V_23 . V_65 = 0.0 ;
if ( V_81 > 0 ) {
if ( V_23 . V_60 > 0.0 ) {
V_23 . V_61 = ( double ) V_82 / ( V_44 - V_43 ) ;
V_23 . V_66 = ( double ) V_81 / ( V_44 - V_43 ) ;
}
V_23 . V_65 = ( double ) V_82 / V_81 ;
}
V_23 . V_71 = NULL ;
V_89 = F_30 ( V_75 ) ;
if ( V_89 ) {
V_23 . V_71 = F_31 ( V_89 -> V_105 ) ;
}
F_12 ( V_89 ) ;
if ( V_23 . V_71 ) {
V_90 = V_23 . V_71 ;
while ( * V_90 != '\0' ) {
if ( * V_90 == '\n' )
* V_90 = ' ' ;
V_90 ++ ;
}
}
if ( V_106 ) {
F_8 ( V_35 , & V_23 ) ;
} else {
F_17 ( V_35 , & V_23 ) ;
}
F_12 ( V_23 . V_49 ) ;
F_12 ( V_23 . V_71 ) ;
return V_76 ;
}
static void
F_32 ( T_10 * V_107 , T_10 * V_108 )
{
printf ( L_79
L_5
L_45
L_5
L_45
L_5
L_45 ,
F_33 () , F_34 () ,
V_107 -> V_109 , V_108 -> V_109 ) ;
}
static void
F_35 ( T_11 * V_110 )
{
fprintf ( V_110 , L_5 ) ;
fprintf ( V_110 , L_80 ) ;
fprintf ( V_110 , L_5 ) ;
fprintf ( V_110 , L_81 ) ;
fprintf ( V_110 , L_82 ) ;
fprintf ( V_110 , L_83 ) ;
#ifdef F_2
fprintf ( V_110 , L_84 ) ;
#endif
fprintf ( V_110 , L_85 ) ;
fprintf ( V_110 , L_5 ) ;
fprintf ( V_110 , L_86 ) ;
fprintf ( V_110 , L_87 ) ;
fprintf ( V_110 , L_88 ) ;
fprintf ( V_110 , L_89 ) ;
fprintf ( V_110 , L_90 ) ;
fprintf ( V_110 , L_5 ) ;
fprintf ( V_110 , L_91 ) ;
fprintf ( V_110 , L_92 ) ;
fprintf ( V_110 , L_93 ) ;
fprintf ( V_110 , L_94 ) ;
fprintf ( V_110 , L_95 ) ;
fprintf ( V_110 , L_96 ) ;
fprintf ( V_110 , L_5 ) ;
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
fprintf ( V_110 , L_5 ) ;
fprintf ( V_110 , L_106 ) ;
fprintf ( V_110 , L_107 ) ;
fprintf ( V_110 , L_108 ) ;
fprintf ( V_110 , L_5 ) ;
fprintf ( V_110 , L_109 ) ;
fprintf ( V_110 , L_110 ) ;
fprintf ( V_110 , L_111 ) ;
fprintf ( V_110 , L_5 ) ;
fprintf ( V_110 , L_112 ) ;
fprintf ( V_110 , L_113 ) ;
fprintf ( V_110 , L_114 ) ;
fprintf ( V_110 , L_5 ) ;
fprintf ( V_110 , L_115 ) ;
fprintf ( V_110 , L_116 ) ;
fprintf ( V_110 , L_117 ) ;
fprintf ( V_110 , L_118 ) ;
fprintf ( V_110 , L_5 ) ;
fprintf ( V_110 , L_119 ) ;
fprintf ( V_110 , L_120 ) ;
fprintf ( V_110 , L_5 ) ;
fprintf ( V_110 , L_121 ) ;
fprintf ( V_110 , L_122 ) ;
#ifndef F_2
fprintf ( V_110 , L_123 ) ;
#endif
}
static void
F_36 ( const char * T_12 V_111 , T_13 T_14 V_111 )
{
return;
}
static void
F_37 ( const unsigned char * V_112 , T_15 V_113 , char * V_109 ) {
int V_47 ;
for ( V_47 = 0 ; V_47 < ( int ) V_113 ; V_47 ++ ) {
F_6 ( V_109 + ( V_47 * 2 ) , 3 , L_124 , V_112 [ V_47 ] ) ;
}
}
static void
F_38 ( T_10 * V_109 )
{
F_39 ( V_109 , L_125 ) ;
#ifdef F_40
F_39 ( V_109 , L_126 ) ;
#ifdef F_41
F_39 ( V_109 , F_41 ) ;
#else
F_39 ( V_109 , L_127 ) ;
#endif
#else
F_39 ( V_109 , L_128 ) ;
#endif
}
static void
F_42 ( T_10 * V_109 )
{
#if F_43 ( F_40 ) && ! F_43 ( V_114 )
F_44 ( V_109 , L_129 , F_45 () ) ;
#endif
}
int
main ( int V_115 , char * V_116 [] )
{
T_10 * V_107 ;
T_10 * V_108 ;
T_7 * V_75 ;
int V_77 ;
T_1 * V_78 ;
int V_117 ;
int V_118 ;
static const struct V_119 V_120 [] = {
{ ( char * ) L_130 , V_121 , NULL , 'h' } ,
{ ( char * ) L_131 , V_121 , NULL , 'v' } ,
{ 0 , 0 , 0 , 0 }
} ;
int V_76 = 0 ;
#ifdef F_46
char * V_122 ;
#endif
#ifdef F_2
T_11 * V_123 ;
char * V_124 = NULL ;
T_16 V_125 = NULL ;
T_15 V_126 ;
#endif
V_107 = F_47 ( L_132 ) ;
F_48 ( V_107 , NULL , F_38 ) ;
V_108 = F_47 ( L_133 ) ;
F_49 ( V_108 , F_42 ) ;
F_50 ( L_79
L_5
L_45
L_5
L_45 ,
F_33 () , V_107 -> V_109 , V_108 -> V_109 ) ;
#ifdef V_114
F_51 ( V_115 , V_116 ) ;
F_52 () ;
#endif
F_53 () ;
F_54 () ;
#ifdef F_46
if ( ( V_122 = F_55 ( V_116 [ 0 ] , main ) ) ) {
F_56 ( L_134 , V_122 ) ;
F_12 ( V_122 ) ;
} else {
F_57 () ;
F_58 ( F_36 , NULL , NULL , NULL ) ;
F_59 () ;
F_60 () ;
}
#endif
#ifdef F_61
V_127 = F_62 ( L_135 ) ;
V_128 = F_63 ( L_136 , L_137 ,
L_138 , NULL , NULL ) ;
V_129 = F_63 ( L_139 , L_140 ,
L_141 , NULL , NULL ) ;
V_130 = F_63 ( L_142 , L_143 ,
L_144 , NULL , NULL ) ;
V_131 = F_63 ( L_145 , L_146 ,
L_147 , NULL , NULL ) ;
V_132 = F_63 ( L_148 , L_149 ,
L_150 , NULL , NULL ) ;
V_133 = F_63 ( L_151 , L_152 ,
L_153 , NULL , NULL ) ;
F_64 ( V_128 , V_134 ) ;
F_64 ( V_129 , V_135 ) ;
F_64 ( V_130 , V_136 ) ;
F_64 ( V_131 , V_137 ) ;
F_64 ( V_132 , V_138 ) ;
F_64 ( V_133 , V_139 ) ;
F_65 ( V_127 , V_140 , NULL ) ;
F_66 ( V_127 , V_128 ) ;
F_66 ( V_127 , V_129 ) ;
F_66 ( V_127 , V_130 ) ;
F_66 ( V_127 , V_131 ) ;
F_66 ( V_127 , V_132 ) ;
F_66 ( V_127 , V_133 ) ;
V_116 [ 0 ] = ( char * ) L_154 ;
if ( V_115 > 2 && V_1 )
F_3 () ;
if ( ! F_67 ( V_127 , & V_115 , & V_116 , & V_141 ) ) {
if ( V_141 )
F_68 ( L_155 , V_141 -> V_142 ) ;
F_68 ( L_45 , F_69 ( V_127 , TRUE , NULL ) ) ;
exit ( 1 ) ;
}
if ( V_143 ) {
F_70 ( L_45 , F_69 ( V_127 , FALSE , NULL ) ) ;
exit ( 0 ) ;
}
if ( V_115 < 2 ) {
F_68 ( L_45 , F_69 ( V_127 , FALSE , NULL ) ) ;
exit ( 1 ) ;
}
F_71 ( V_127 ) ;
#endif
while ( ( V_117 = F_72 ( V_115 , V_116 , L_156 V_144 L_157 , V_120 , NULL ) ) != - 1 ) {
switch ( V_117 ) {
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
V_106 = TRUE ;
break;
case 'T' :
V_106 = FALSE ;
break;
case 'M' :
V_54 = TRUE ;
break;
case 'R' :
V_146 = TRUE ;
break;
case 'r' :
V_146 = FALSE ;
break;
case 'N' :
V_73 = '\0' ;
break;
case 'q' :
V_73 = '\'' ;
break;
case 'Q' :
V_73 = '"' ;
break;
case 'B' :
V_72 = '\t' ;
break;
case 'm' :
V_72 = ',' ;
break;
case 'b' :
V_72 = ' ' ;
break;
case 'h' :
printf ( L_79
L_158
L_159 ,
F_33 () ) ;
F_35 ( stdout ) ;
exit ( 0 ) ;
break;
case 'v' :
F_32 ( V_107 , V_108 ) ;
F_73 ( V_107 , TRUE ) ;
F_73 ( V_108 , TRUE ) ;
exit ( 0 ) ;
break;
case '?' :
F_35 ( V_99 ) ;
exit ( 1 ) ;
break;
}
}
setlocale ( V_147 , L_6 ) ;
if ( ( V_115 - V_148 ) < 1 ) {
F_35 ( V_99 ) ;
exit ( 1 ) ;
}
if ( ! V_106 && V_146 ) {
F_16 () ;
}
#ifdef F_2
if ( V_17 ) {
F_74 ( NULL ) ;
F_75 ( & V_125 , V_149 , 0 ) ;
if ( V_125 ) {
F_76 ( V_125 , V_150 ) ;
F_76 ( V_125 , V_151 ) ;
}
V_124 = ( char * ) F_77 ( V_152 ) ;
}
#endif
V_118 = 0 ;
for ( V_117 = V_148 ; V_117 < V_115 ; V_117 ++ ) {
#ifdef F_2
F_78 ( V_68 , L_160 , V_153 ) ;
F_78 ( V_69 , L_160 , V_153 ) ;
F_78 ( V_70 , L_160 , V_153 ) ;
if ( V_17 ) {
V_123 = F_79 ( V_116 [ V_117 ] , L_161 ) ;
if ( V_123 && V_125 ) {
while( ( V_126 = fread ( V_124 , 1 , V_152 , V_123 ) ) > 0 ) {
F_80 ( V_125 , V_124 , V_126 ) ;
}
F_81 ( V_125 ) ;
F_37 ( F_82 ( V_125 , V_149 ) , V_154 , V_68 ) ;
F_37 ( F_82 ( V_125 , V_150 ) , V_155 , V_69 ) ;
F_37 ( F_82 ( V_125 , V_151 ) , V_156 , V_70 ) ;
}
if ( V_123 ) fclose ( V_123 ) ;
if ( V_125 ) F_83 ( V_125 ) ;
}
#endif
V_75 = F_84 ( V_116 [ V_117 ] , V_157 , & V_77 , & V_78 , FALSE ) ;
if ( ! V_75 ) {
fprintf ( V_99 , L_162 , V_116 [ V_117 ] ,
F_24 ( V_77 ) ) ;
switch ( V_77 ) {
case V_101 :
case V_102 :
case V_103 :
case V_104 :
fprintf ( V_99 , L_77 , V_78 ) ;
F_12 ( V_78 ) ;
break;
}
V_118 = 1 ;
if ( ! V_145 )
exit ( 1 ) ;
}
if ( V_75 ) {
if ( ( V_117 > V_148 ) && ( V_106 ) )
printf ( L_5 ) ;
V_76 = F_18 ( V_75 , V_116 [ V_117 ] ) ;
F_85 ( V_75 ) ;
if ( V_76 )
exit ( V_76 ) ;
}
}
return V_118 ;
}
