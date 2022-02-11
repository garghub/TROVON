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
V_40 = F_11 ( ( V_62 ) V_23 -> V_66 , V_55 ) ;
printf ( L_40 , V_40 ) ;
F_12 ( V_40 ) ;
}
}
}
#ifdef F_2
if ( V_17 ) {
printf ( L_41 , V_67 ) ;
printf ( L_42 , V_68 ) ;
printf ( L_43 , V_69 ) ;
}
#endif
if ( V_12 ) printf ( L_44 , F_4 ( V_23 -> V_18 ) ) ;
if ( V_7 && V_23 -> V_70 )
printf ( L_45 , V_23 -> V_70 ) ;
}
static void
F_13 ( void )
{
if ( V_71 ) putchar ( V_71 ) ;
}
static void
F_14 ( void )
{
if ( V_72 ) putchar ( V_72 ) ;
}
static void
F_15 ( const T_1 * V_73 )
{
F_13 () ;
F_14 () ;
printf ( L_46 , V_73 ) ;
F_14 () ;
}
static void
F_16 ( void )
{
F_14 () ;
printf ( L_47 ) ;
F_14 () ;
if ( V_2 ) F_15 ( L_48 ) ;
if ( V_3 ) F_15 ( L_49 ) ;
if ( V_4 ) F_15 ( L_50 ) ;
if ( V_4 ) F_15 ( L_51 ) ;
if ( V_4 ) F_15 ( L_52 ) ;
if ( V_5 ) F_15 ( L_53 ) ;
if ( V_6 ) F_15 ( L_54 ) ;
if ( V_8 ) F_15 ( L_55 ) ;
if ( V_9 ) F_15 ( L_56 ) ;
if ( V_10 ) F_15 ( L_57 ) ;
if ( V_11 ) F_15 ( L_58 ) ;
if ( V_13 ) F_15 ( L_59 ) ;
if ( V_14 ) F_15 ( L_60 ) ;
if ( V_15 ) F_15 ( L_61 ) ;
if ( V_16 ) F_15 ( L_62 ) ;
#ifdef F_2
if ( V_17 ) {
F_15 ( L_63 ) ;
F_15 ( L_64 ) ;
F_15 ( L_65 ) ;
}
#endif
if ( V_12 ) F_15 ( L_66 ) ;
if ( V_7 ) F_15 ( L_67 ) ;
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
printf ( L_46 , V_35 ) ;
F_14 () ;
}
if ( V_2 ) {
F_13 () ;
F_14 () ;
printf ( L_46 , V_36 ) ;
F_14 () ;
}
if ( V_3 ) {
F_13 () ;
F_14 () ;
printf ( L_46 , V_37 ) ;
F_14 () ;
}
if ( V_4 ) {
F_13 () ;
F_14 () ;
if ( V_23 -> V_50 )
printf ( L_68 , V_23 -> V_51 ) ;
else
printf ( L_69 ) ;
F_14 () ;
if ( V_23 -> V_52 > 0 ) {
F_13 () ;
F_14 () ;
printf ( L_68 , V_23 -> V_53 ) ;
F_14 () ;
F_13 () ;
F_14 () ;
printf ( L_68 , V_23 -> V_52 ) ;
F_14 () ;
}
else {
F_13 () ;
F_14 () ;
printf ( L_70 ) ;
F_14 () ;
F_13 () ;
F_14 () ;
printf ( L_70 ) ;
F_14 () ;
}
}
if ( V_5 ) {
F_13 () ;
F_14 () ;
printf ( L_68 , V_23 -> V_29 ) ;
F_14 () ;
}
if ( V_6 ) {
F_13 () ;
F_14 () ;
printf ( L_25 V_56 L_71 , V_23 -> V_57 ) ;
F_14 () ;
}
if ( V_8 ) {
F_13 () ;
F_14 () ;
printf ( L_25 V_56 L_72 , V_23 -> V_59 ) ;
F_14 () ;
}
if ( V_9 ) {
F_13 () ;
F_14 () ;
if ( V_23 -> V_28 )
printf ( L_73 , V_23 -> V_60 ) ;
else
printf ( L_70 ) ;
F_14 () ;
}
if ( V_10 ) {
F_13 () ;
F_14 () ;
printf ( L_46 , F_5 ( V_38 , V_23 , FALSE ) ) ;
F_14 () ;
}
if ( V_11 ) {
F_13 () ;
F_14 () ;
printf ( L_46 , F_5 ( V_39 , V_23 , FALSE ) ) ;
F_14 () ;
}
if ( V_13 ) {
F_13 () ;
F_14 () ;
if ( V_23 -> V_28 )
printf ( L_74 , V_23 -> V_61 ) ;
else
printf ( L_70 ) ;
F_14 () ;
}
if ( V_14 ) {
F_13 () ;
F_14 () ;
if ( V_23 -> V_28 )
printf ( L_74 , V_23 -> V_61 * 8 ) ;
else
printf ( L_70 ) ;
F_14 () ;
}
if ( V_15 ) {
F_13 () ;
F_14 () ;
printf ( L_74 , V_23 -> V_65 ) ;
F_14 () ;
}
if ( V_16 ) {
F_13 () ;
F_14 () ;
if ( V_23 -> V_28 )
printf ( L_74 , V_23 -> V_66 ) ;
else
printf ( L_70 ) ;
F_14 () ;
}
#ifdef F_2
if ( V_17 ) {
F_13 () ;
F_14 () ;
printf ( L_46 , V_67 ) ;
F_14 () ;
F_13 () ;
F_14 () ;
printf ( L_46 , V_68 ) ;
F_14 () ;
F_13 () ;
F_14 () ;
printf ( L_46 , V_69 ) ;
F_14 () ;
}
#endif
if ( V_12 ) {
F_13 () ;
F_14 () ;
printf ( L_46 , F_4 ( V_23 -> V_18 ) ) ;
F_14 () ;
}
if ( V_7 ) {
F_13 () ;
F_14 () ;
printf ( L_46 , V_23 -> V_70 ) ;
F_14 () ;
}
printf ( L_5 ) ;
}
static int
F_18 ( T_7 * V_74 , const char * V_35 )
{
int V_75 = 0 ;
int V_76 ;
T_1 * V_77 ;
V_62 V_78 ;
V_62 V_79 ;
T_8 V_80 = 0 ;
V_62 V_81 = 0 ;
T_8 V_53 = 0xffffffff ;
T_8 V_52 = 0 ;
const struct V_82 * V_83 ;
T_4 V_23 ;
T_5 V_84 = TRUE ;
double V_43 = 0 ;
double V_44 = 0 ;
double V_85 = 0 ;
double V_86 = 0 ;
T_5 V_87 = FALSE ;
T_2 V_18 = V_19 ;
T_9 * V_88 ;
T_1 * V_89 ;
V_23 . V_49 = F_19 ( int , V_48 ) ;
while ( F_20 ( V_74 , & V_76 , & V_77 , & V_79 ) ) {
V_83 = F_21 ( V_74 ) ;
if ( V_83 -> V_90 & V_91 ) {
V_86 = V_85 ;
V_85 = F_22 ( & V_83 -> V_92 ) ;
if ( V_80 == 0 ) {
V_43 = V_85 ;
V_44 = V_85 ;
V_86 = V_85 ;
}
if ( V_85 < V_86 ) {
V_18 = V_20 ;
}
if ( V_85 < V_43 ) {
V_43 = V_85 ;
}
if ( V_85 > V_44 ) {
V_44 = V_85 ;
}
} else {
V_84 = FALSE ;
if ( V_18 != V_20 )
V_18 = V_21 ;
}
if ( V_83 -> V_93 == V_94 ) {
V_81 += V_83 -> V_95 ;
V_80 ++ ;
if ( V_83 -> V_96 < V_83 -> V_95 ) {
if ( V_83 -> V_96 < V_53 )
V_53 = V_83 -> V_96 ;
if ( V_83 -> V_96 > V_52 )
V_52 = V_83 -> V_96 ;
}
if ( F_23 ( V_74 ) == V_46 ) {
if ( ( V_83 -> V_97 > 0 ) && ( V_83 -> V_97 < V_48 ) ) {
V_23 . V_49 [ V_83 -> V_97 ] += 1 ;
} else {
fprintf ( V_98 , L_75 , V_83 -> V_97 , V_80 ) ;
}
}
}
}
if ( V_76 != 0 ) {
fprintf ( V_98 ,
L_76 ,
V_80 , V_35 , F_24 ( V_76 ) ) ;
switch ( V_76 ) {
case V_99 :
V_75 = 1 ;
fprintf ( V_98 ,
L_77 ) ;
break;
case V_100 :
case V_101 :
case V_102 :
case V_103 :
fprintf ( V_98 , L_78 , V_77 ) ;
F_12 ( V_77 ) ;
default:
F_12 ( V_23 . V_49 ) ;
return 1 ;
}
}
V_78 = F_25 ( V_74 , & V_76 ) ;
if ( V_78 == - 1 ) {
fprintf ( V_98 ,
L_79 ,
V_35 , F_26 ( V_76 ) ) ;
F_12 ( V_23 . V_49 ) ;
return 1 ;
}
V_23 . V_57 = V_78 ;
V_23 . V_41 = F_27 ( V_74 ) ;
V_23 . V_45 = F_28 ( V_74 ) ;
V_23 . V_42 = F_23 ( V_74 ) ;
V_23 . V_51 = F_29 ( V_74 ) ;
if ( V_23 . V_51 > 0 )
V_23 . V_50 = TRUE ;
else
V_23 . V_50 = FALSE ;
V_23 . V_53 = V_53 ;
V_23 . V_52 = V_52 ;
V_23 . V_29 = V_80 ;
V_23 . V_28 = V_84 ;
V_23 . V_43 = V_43 ;
V_23 . V_44 = V_44 ;
V_23 . V_60 = V_44 - V_43 ;
V_23 . V_87 = V_87 ;
V_23 . V_18 = V_18 ;
V_23 . V_59 = V_81 ;
V_23 . V_61 = 0.0 ;
V_23 . V_66 = 0.0 ;
V_23 . V_65 = 0.0 ;
if ( V_80 > 0 ) {
if ( V_23 . V_60 > 0.0 ) {
V_23 . V_61 = ( double ) V_81 / ( V_44 - V_43 ) ;
V_23 . V_66 = ( double ) V_80 / ( V_44 - V_43 ) ;
}
V_23 . V_65 = ( double ) V_81 / V_80 ;
}
V_23 . V_70 = NULL ;
V_88 = F_30 ( V_74 ) ;
if ( V_88 ) {
V_23 . V_70 = F_31 ( V_88 -> V_104 ) ;
}
F_12 ( V_88 ) ;
if ( V_23 . V_70 ) {
V_89 = V_23 . V_70 ;
while ( * V_89 != '\0' ) {
if ( * V_89 == '\n' )
* V_89 = ' ' ;
V_89 ++ ;
}
}
if ( V_105 ) {
F_8 ( V_35 , & V_23 ) ;
} else {
F_17 ( V_35 , & V_23 ) ;
}
F_12 ( V_23 . V_49 ) ;
F_12 ( V_23 . V_70 ) ;
return V_75 ;
}
static void
F_32 ( T_5 V_106 )
{
T_10 * V_107 ;
if ( ! V_106 ) {
V_107 = stdout ;
}
else {
V_107 = V_98 ;
}
fprintf ( V_107 , L_80
#ifdef F_33
L_81 F_33 L_82 V_108 L_83
#endif
L_5 , V_109 ) ;
fprintf ( V_107 , L_84 ) ;
fprintf ( V_107 , L_85 ) ;
fprintf ( V_107 , L_5 ) ;
fprintf ( V_107 , L_86 ) ;
fprintf ( V_107 , L_5 ) ;
fprintf ( V_107 , L_87 ) ;
fprintf ( V_107 , L_88 ) ;
fprintf ( V_107 , L_89 ) ;
#ifdef F_2
fprintf ( V_107 , L_90 ) ;
#endif
fprintf ( V_107 , L_91 ) ;
fprintf ( V_107 , L_5 ) ;
fprintf ( V_107 , L_92 ) ;
fprintf ( V_107 , L_93 ) ;
fprintf ( V_107 , L_94 ) ;
fprintf ( V_107 , L_95 ) ;
fprintf ( V_107 , L_96 ) ;
fprintf ( V_107 , L_5 ) ;
fprintf ( V_107 , L_97 ) ;
fprintf ( V_107 , L_98 ) ;
fprintf ( V_107 , L_99 ) ;
fprintf ( V_107 , L_100 ) ;
fprintf ( V_107 , L_101 ) ;
fprintf ( V_107 , L_102 ) ;
fprintf ( V_107 , L_5 ) ;
fprintf ( V_107 , L_103 ) ;
fprintf ( V_107 , L_104 ) ;
fprintf ( V_107 , L_105 ) ;
fprintf ( V_107 , L_106 ) ;
fprintf ( V_107 , L_107 ) ;
fprintf ( V_107 , L_5 ) ;
fprintf ( V_107 , L_108 ) ;
fprintf ( V_107 , L_109 ) ;
fprintf ( V_107 , L_110 ) ;
fprintf ( V_107 , L_111 ) ;
fprintf ( V_107 , L_5 ) ;
fprintf ( V_107 , L_112 ) ;
fprintf ( V_107 , L_113 ) ;
fprintf ( V_107 , L_114 ) ;
fprintf ( V_107 , L_5 ) ;
fprintf ( V_107 , L_115 ) ;
fprintf ( V_107 , L_116 ) ;
fprintf ( V_107 , L_117 ) ;
fprintf ( V_107 , L_5 ) ;
fprintf ( V_107 , L_118 ) ;
fprintf ( V_107 , L_119 ) ;
fprintf ( V_107 , L_120 ) ;
fprintf ( V_107 , L_5 ) ;
fprintf ( V_107 , L_121 ) ;
fprintf ( V_107 , L_122 ) ;
fprintf ( V_107 , L_123 ) ;
fprintf ( V_107 , L_124 ) ;
fprintf ( V_107 , L_5 ) ;
fprintf ( V_107 , L_125 ) ;
fprintf ( V_107 , L_126 ) ;
fprintf ( V_107 , L_5 ) ;
fprintf ( V_107 , L_127 ) ;
fprintf ( V_107 , L_128 ) ;
#ifndef F_2
fprintf ( V_107 , L_129 ) ;
#endif
}
static void
F_34 ( const char * T_11 V_110 , T_12 T_13 V_110 )
{
return;
}
static void
F_35 ( const unsigned char * V_111 , T_14 V_112 , char * V_113 ) {
int V_47 ;
for ( V_47 = 0 ; V_47 < ( int ) V_112 ; V_47 ++ ) {
F_6 ( V_113 + ( V_47 * 2 ) , 3 , L_130 , V_111 [ V_47 ] ) ;
}
}
int
main ( int V_114 , char * V_115 [] )
{
T_7 * V_74 ;
int V_76 ;
T_1 * V_77 ;
int V_116 ;
int V_117 ;
int V_75 = 0 ;
#ifdef F_36
char * V_118 ;
#endif
#ifdef F_2
T_10 * V_119 ;
char * V_120 = NULL ;
T_15 V_121 = NULL ;
T_14 V_122 ;
#endif
#ifdef F_37
F_38 ( V_114 , V_115 ) ;
F_39 () ;
#endif
F_40 () ;
F_41 () ;
#ifdef F_36
if ( ( V_118 = F_42 ( V_115 [ 0 ] , main ) ) ) {
F_43 ( L_131 , V_118 ) ;
F_12 ( V_118 ) ;
} else {
F_44 () ;
F_45 ( F_34 , NULL , NULL , NULL ) ;
F_46 () ;
F_47 () ;
}
#endif
#ifdef F_48
V_123 = F_49 ( L_132 ) ;
V_124 = F_50 ( L_133 , L_134 ,
L_135 , NULL , NULL ) ;
V_125 = F_50 ( L_136 , L_137 ,
L_138 , NULL , NULL ) ;
V_126 = F_50 ( L_139 , L_140 ,
L_141 , NULL , NULL ) ;
V_127 = F_50 ( L_142 , L_143 ,
L_144 , NULL , NULL ) ;
V_128 = F_50 ( L_145 , L_146 ,
L_147 , NULL , NULL ) ;
V_129 = F_50 ( L_148 , L_149 ,
L_150 , NULL , NULL ) ;
F_51 ( V_124 , V_130 ) ;
F_51 ( V_125 , V_131 ) ;
F_51 ( V_126 , V_132 ) ;
F_51 ( V_127 , V_133 ) ;
F_51 ( V_128 , V_134 ) ;
F_51 ( V_129 , V_135 ) ;
F_52 ( V_123 , V_136 , NULL ) ;
F_53 ( V_123 , V_124 ) ;
F_53 ( V_123 , V_125 ) ;
F_53 ( V_123 , V_126 ) ;
F_53 ( V_123 , V_127 ) ;
F_53 ( V_123 , V_128 ) ;
F_53 ( V_123 , V_129 ) ;
V_115 [ 0 ] = ( char * ) L_151 ;
if ( V_114 > 2 && V_1 )
F_3 () ;
if ( ! F_54 ( V_123 , & V_114 , & V_115 , & V_137 ) ) {
if ( V_137 )
F_55 ( L_152 , V_137 -> V_138 ) ;
F_55 ( L_46 , F_56 ( V_123 , TRUE , NULL ) ) ;
exit ( 1 ) ;
}
if ( V_139 ) {
F_57 ( L_46 , F_56 ( V_123 , FALSE , NULL ) ) ;
exit ( 0 ) ;
}
if ( V_114 < 2 ) {
F_55 ( L_46 , F_56 ( V_123 , FALSE , NULL ) ) ;
exit ( 1 ) ;
}
F_58 ( V_123 ) ;
#endif
while ( ( V_116 = F_59 ( V_114 , V_115 , L_153 V_140 L_154 ) ) != - 1 ) {
switch ( V_116 ) {
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
V_141 = FALSE ;
break;
case 'A' :
F_1 () ;
break;
case 'L' :
V_105 = TRUE ;
break;
case 'T' :
V_105 = FALSE ;
break;
case 'M' :
V_54 = TRUE ;
break;
case 'R' :
V_142 = TRUE ;
break;
case 'r' :
V_142 = FALSE ;
break;
case 'N' :
V_72 = '\0' ;
break;
case 'q' :
V_72 = '\'' ;
break;
case 'Q' :
V_72 = '"' ;
break;
case 'B' :
V_71 = '\t' ;
break;
case 'm' :
V_71 = ',' ;
break;
case 'b' :
V_71 = ' ' ;
break;
case 'h' :
F_32 ( FALSE ) ;
exit ( 0 ) ;
break;
case '?' :
F_32 ( TRUE ) ;
exit ( 1 ) ;
break;
}
}
setlocale ( V_143 , L_6 ) ;
if ( ( V_114 - V_144 ) < 1 ) {
F_32 ( TRUE ) ;
exit ( 1 ) ;
}
if ( ! V_105 && V_142 ) {
F_16 () ;
}
#ifdef F_2
if ( V_17 ) {
F_60 ( NULL ) ;
F_61 ( & V_121 , V_145 , 0 ) ;
if ( V_121 ) {
F_62 ( V_121 , V_146 ) ;
F_62 ( V_121 , V_147 ) ;
}
V_120 = ( char * ) F_63 ( V_148 ) ;
}
#endif
V_117 = 0 ;
for ( V_116 = V_144 ; V_116 < V_114 ; V_116 ++ ) {
#ifdef F_2
F_64 ( V_67 , L_155 , V_149 ) ;
F_64 ( V_68 , L_155 , V_149 ) ;
F_64 ( V_69 , L_155 , V_149 ) ;
if ( V_17 ) {
V_119 = F_65 ( V_115 [ V_116 ] , L_156 ) ;
if ( V_119 && V_121 ) {
while( ( V_122 = fread ( V_120 , 1 , V_148 , V_119 ) ) > 0 ) {
F_66 ( V_121 , V_120 , V_122 ) ;
}
F_67 ( V_121 ) ;
F_35 ( F_68 ( V_121 , V_145 ) , V_150 , V_67 ) ;
F_35 ( F_68 ( V_121 , V_146 ) , V_151 , V_68 ) ;
F_35 ( F_68 ( V_121 , V_147 ) , V_152 , V_69 ) ;
}
if ( V_119 ) fclose ( V_119 ) ;
if ( V_121 ) F_69 ( V_121 ) ;
}
#endif
V_74 = F_70 ( V_115 [ V_116 ] , V_153 , & V_76 , & V_77 , FALSE ) ;
if ( ! V_74 ) {
fprintf ( V_98 , L_157 , V_115 [ V_116 ] ,
F_24 ( V_76 ) ) ;
switch ( V_76 ) {
case V_100 :
case V_101 :
case V_102 :
fprintf ( V_98 , L_78 , V_77 ) ;
F_12 ( V_77 ) ;
break;
}
V_117 = 1 ;
if ( ! V_141 )
exit ( 1 ) ;
}
if ( V_74 ) {
if ( ( V_116 > V_144 ) && ( V_105 ) )
printf ( L_5 ) ;
V_75 = F_18 ( V_74 , V_115 [ V_116 ] ) ;
F_71 ( V_74 ) ;
if ( V_75 )
exit ( V_75 ) ;
}
}
return V_117 ;
}
