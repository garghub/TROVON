int F_1 ( int V_1 , const char * V_2 , ... ) {
T_1 V_3 ;
char V_4 [ V_5 ] ;
if ( V_6 < V_1 ) return 1 ;
va_start ( V_3 , V_2 ) ;
vsnprintf ( V_4 , V_5 , V_2 , V_3 ) ;
va_end ( V_3 ) ;
fprintf ( V_7 , L_1 ,
V_8 . V_9 , V_8 . V_10 , V_8 . V_11 , V_1 , V_4 ) ;
return 1 ;
}
static char * F_2 ( char * * T_2 V_12 ) {
return F_3 ( L_2 , V_6 ) ;
}
static T_3 F_4 ( char * V_13 , char * * T_2 ) {
char * V_14 ;
int V_15 = ( int ) strtol ( V_13 , & V_14 , 10 ) ;
if ( V_14 <= V_13 ) {
* T_2 = F_5 ( L_3 ) ;
return FALSE ;
} else if ( V_15 < 0 || V_15 > 5 ) {
* T_2 = F_3 ( L_4 , V_15 ) ;
return FALSE ;
}
V_6 = V_15 ;
F_6 () ;
return TRUE ;
}
static long F_7 ( T_4 * V_16 , T_5 V_17 ) {
long V_18 = F_8 ( V_8 . V_19 . V_20 , V_16 , V_8 . V_9 , V_17 , V_8 . V_11 , NULL ) ;
F_1 ( 1 , L_5 ,
V_8 . V_19 . V_20 , V_8 . V_9 , F_9 ( V_17 ) , V_8 . V_11 , ( V_18 > 0 ? L_6 : F_10 ( V_21 ) ) ) ;
return V_18 ;
}
static void F_11 ( int T_6 V_12 ) {
F_12 ( ( 3 , L_7 ) ) ;
exit ( 0 ) ;
}
extern void F_13 ( T_7 V_9 , int V_22 , int V_20 , int V_11 , T_8 * V_23 ) {
V_24 = V_23 ;
V_25 . V_26 = V_27 / 1000000 ;
V_25 . V_28 = V_27 % 1000000 ;
V_8 . V_9 = V_9 ;
V_8 . V_29 = V_30 ;
V_8 . V_10 = F_14 () ;
V_8 . V_31 = F_15 () ;
V_8 . V_11 = V_11 ;
F_16 ( & ( V_8 . V_32 ) , V_22 , 4096 ) ;
V_8 . V_19 . V_20 = V_20 ;
V_8 . V_19 . V_33 = - 1 ;
V_8 . V_19 . V_34 = - 1 ;
V_8 . V_19 . V_35 = - 1 ;
F_17 ( & V_8 . V_36 , NULL ) ;
V_8 . V_37 . V_26 = V_8 . V_36 . V_26 ;
V_8 . V_37 . V_28 = V_8 . V_36 . V_28 ;
F_18 ( & ( V_8 . V_38 ) , & ( V_8 . V_39 ) , NULL , NULL ) ;
F_19 () ;
F_12 ( ( 5 , L_8 , V_9 , V_22 , V_20 , V_11 ) ) ;
signal ( V_40 , V_41 ) ;
signal ( V_42 , F_11 ) ;
signal ( V_43 , V_41 ) ;
signal ( V_44 , V_41 ) ;
signal ( V_45 , V_41 ) ;
signal ( V_46 , V_41 ) ;
}
void F_20 ( int V_47 , unsigned V_11 , const char * V_2 , ... ) {
T_9 V_48 = 1024 ;
T_10 V_49 [ V_48 ] ;
T_1 V_3 ;
static T_4 * V_50 ;
va_start ( V_3 , V_2 ) ;
F_21 ( V_49 , V_48 , V_2 , V_3 ) ;
va_end ( V_3 ) ;
F_12 ( ( 0 , L_9 , V_49 ) ) ;
V_50 = V_8 . V_38 -> error ( V_47 , V_49 ) ;
F_8 ( V_8 . V_19 . V_20 , V_50 , V_8 . V_9 , V_51 , V_11 , NULL ) ;
F_22 ( V_50 , TRUE ) ;
}
static char * F_23 ( char * * T_2 ) {
char * V_52 = F_24 ( NULL , 128 ) ;
if ( ! V_52 ) {
* T_2 = F_5 ( F_10 ( V_21 ) ) ;
}
return V_52 ;
}
static T_3 F_25 ( char * V_13 , char * * T_2 ) {
if ( F_26 ( V_13 ) != 0 ) {
* T_2 = F_3 ( L_10 , F_10 ( V_21 ) ) ;
return FALSE ;
}
return TRUE ;
}
static char * F_27 ( char * * T_2 ) {
if ( V_8 . V_29 != V_53 && V_8 . V_29 != V_54 ) {
* T_2 = F_5 ( L_11 ) ;
return NULL ;
}
return F_3 ( L_2 , V_55 ) ;
}
static T_3 F_28 ( char * V_13 , char * * T_2 ) {
T_11 * V_56 = NULL ;
if ( V_8 . V_29 != V_30 && V_8 . V_29 != V_57 ) {
* T_2 = F_5 ( L_12 ) ;
return FALSE ;
} else {
if ( F_29 ( V_13 , & V_56 , T_2 ) ) {
if ( V_8 . V_58 ) F_30 ( V_8 . V_58 ) ;
if ( V_8 . V_59 ) F_31 ( V_8 . V_59 ) ;
V_8 . V_59 = V_56 ;
V_8 . V_58 = F_5 ( V_13 ) ;
return TRUE ;
} else {
return FALSE ;
}
}
}
static char * F_32 ( char * * T_2 V_12 ) { return F_5 ( V_8 . V_58 ? V_8 . V_58 : L_13 ) ; }
static T_3 F_33 ( char * V_13 , char * * T_2 ) {
if ( V_8 . V_29 != V_30 ) {
* T_2 = F_3 ( L_14 , V_13 ) ;
return FALSE ;
}
if ( F_34 ( V_13 , FALSE ) ) {
F_35 ( V_13 ) ;
if ( V_60 ) F_30 ( V_60 ) ;
V_60 = F_5 ( V_13 ) ;
return TRUE ;
} else {
* T_2 = F_3 ( L_15 , V_13 ) ;
return FALSE ;
}
}
static char * F_36 ( char * * T_2 V_12 ) { return F_5 ( V_60 ? V_60 : L_13 ) ; }
static char * F_37 ( char * * T_2 ) {
T_12 * V_61 = NULL ;
T_13 * V_62 = F_38 ( L_16 , 0 , & V_61 ) ;
T_14 * V_4 = F_39 ( L_17 ) ;
const char * V_63 ;
if ( V_61 ) {
* T_2 = F_3 ( L_18 , V_61 -> V_64 ) ;
return NULL ;
}
while( ( V_63 = F_40 ( V_62 ) ) ) {
F_41 ( V_4 , L_19 , V_63 ) ;
}
F_42 ( V_62 ) ;
F_43 ( V_4 , V_4 -> V_48 - 2 ) ;
F_44 ( V_4 , L_20 ) ;
return F_45 ( V_4 , FALSE ) ;
}
static T_3 F_46 ( char * V_13 , char * * T_2 ) {
int V_65 = F_47 ( V_13 ) ;
if ( V_65 < 0 ) {
* T_2 = F_3 ( L_21 , V_13 ) ;
return FALSE ;
} else {
V_66 = V_65 ;
return TRUE ;
}
}
static char * F_48 ( char * * T_2 V_12 ) {
return F_3 ( L_22 ,
F_49 ( V_66 ) ,
V_66 , F_50 ( V_66 ) ) ;
}
static T_3 F_51 ( char * V_13 , char * * T_2 ) {
if ( F_52 ( V_13 ) ) {
return TRUE ;
} else {
* T_2 = F_3 ( L_23 , V_13 ) ;
return FALSE ;
}
}
static char * F_53 ( char * * T_2 V_12 ) {
return F_54 ( V_67 , V_68 ) ;
}
static void F_55 ( char * V_69 ) {
F_12 ( ( 2 , L_24 , V_69 ) ) ;
F_20 ( V_70 , V_8 . V_11 , L_25 ) ;
V_8 . V_29 = V_54 ;
}
static void F_56 ( char * V_71 , char * V_72 ) {
F_12 ( ( 2 , L_26 , V_71 , V_72 ) ) ;
F_20 ( V_70 , V_8 . V_11 , L_27 ) ;
V_8 . V_29 = V_73 ;
}
static void F_57 ( void ) {
F_12 ( ( 2 , L_28 ) ) ;
F_20 ( V_70 , V_8 . V_11 , L_29 ) ;
V_8 . V_29 = V_53 ;
}
static void F_58 ( void ) {
F_12 ( ( 2 , L_30 ) ) ;
F_20 ( V_70 , V_8 . V_11 , L_31 ) ;
V_8 . V_29 = V_57 ;
}
static void F_59 ( char * V_74 ) {
F_12 ( ( 2 , L_32 , V_74 ) ) ;
F_20 ( V_70 , V_8 . V_11 , L_33 ) ;
}
static void F_60 ( char * V_74 ) {
F_12 ( ( 2 , L_34 , V_74 ) ) ;
F_20 ( V_70 , V_8 . V_11 , L_35 ) ;
}
static void F_61 ( char * V_75 ) {
F_12 ( ( 2 , L_36 , V_75 ) ) ;
F_20 ( V_70 , V_8 . V_11 , L_37 ) ;
}
static void F_62 ( int V_76 , char * V_77 ) {
F_12 ( ( 2 , L_38 , V_76 , V_77 ) ) ;
F_20 ( V_70 , V_8 . V_11 , L_39 ) ;
}
static void F_63 ( char * V_78 ) {
F_12 ( ( 2 , L_40 , V_78 ) ) ;
F_20 ( V_70 , V_8 . V_11 , L_41 ) ;
}
static void F_64 ( char * V_69 , char * V_72 ) {
F_12 ( ( 2 , L_42 , V_69 , V_72 ) ) ;
F_20 ( V_70 , V_8 . V_11 , L_43 ) ;
}
static long F_65 ( T_15 * V_79 , T_9 V_48 , T_7 V_9 , T_5 type , T_16 V_11 , void * T_17 V_12 ) {
T_4 V_50 ;
T_4 * V_80 ;
char * T_2 = NULL ;
V_8 . V_11 = V_11 ;
F_12 ( ( 2 , L_44 , F_9 ( type ) , V_48 ) ) ;
#if 0
gettimeofday(&(child.now), NULL);
#endif
if ( V_8 . V_9 != V_9 ) {
F_20 ( V_81 , V_11 ,
L_45 , V_8 . V_9 , V_9 , F_9 ( type ) ) ;
return 0 ;
}
V_50 . T_17 = V_79 ;
V_50 . V_48 = ( V_82 ) V_48 ;
switch( type ) {
case V_83 : {
V_8 . V_29 = V_84 ;
if ( ! F_66 ( V_67 , ( V_85 * ) & V_50 , & T_2 ) ) {
F_20 ( V_86 , V_11 ,
L_46 , T_2 ) ;
} else {
V_8 . V_29 = V_30 ;
F_67 ( NULL , V_87 ) ;
}
break;
}
case V_88 :
F_12 ( ( 1 , L_47 ) ) ;
F_67 ( & V_50 , V_89 ) ;
break;
case V_90 : {
char * V_91 ;
char * V_92 ;
if ( V_8 . V_39 -> V_93 && V_8 . V_39 -> V_93 ( V_79 , V_48 , & V_91 , & V_92 ) ) {
if ( ! F_68 ( V_67 , V_91 , V_92 , & T_2 ) ) {
F_20 ( V_94 , V_11 , L_48 , T_2 ) ;
F_30 ( T_2 ) ;
return 0 ;
}
V_80 = V_8 . V_38 -> V_91 ( V_91 , V_92 ) ;
F_67 ( V_80 , V_95 ) ;
F_22 ( V_80 , TRUE ) ;
F_12 ( ( 1 , L_49 , V_91 , V_92 ) ) ;
break;
} else {
goto V_96;
}
}
case V_97 : {
char * V_91 ;
if ( V_8 . V_39 -> V_98 && V_8 . V_39 -> V_98 ( V_79 , V_48 , & V_91 ) ) {
char * V_13 ;
if ( ! ( V_13 = F_69 ( V_67 , V_91 , & T_2 ) ) ) {
F_20 ( V_99 , V_11 , L_48 , T_2 ) ;
F_30 ( T_2 ) ;
return 0 ;
}
V_80 = V_8 . V_38 -> V_91 ( V_91 , V_13 ) ;
F_67 ( V_80 , V_95 ) ;
F_22 ( V_80 , TRUE ) ;
F_12 ( ( 2 , L_50 , V_91 , V_13 ) ) ;
break;
} else {
goto V_96;
}
}
case V_100 :
F_67 ( NULL , V_101 ) ;
F_12 ( ( 3 , L_51 ) ) ;
F_70 ( 0 , NULL , NULL , NULL , & V_25 ) ;
F_12 ( ( 1 , L_52 ) ) ;
exit ( 0 ) ;
break;
case V_102 : {
char * V_69 ;
if ( V_8 . V_29 != V_30 ) goto V_103;
if ( V_8 . V_39 -> V_104 ( V_79 , V_48 , & V_69 ) ) {
F_55 ( V_69 ) ;
} else {
F_20 ( V_105 , V_11 , L_53 ) ;
}
break;
}
case V_106 : {
char * V_71 ;
char * V_72 ;
if ( V_8 . V_29 != V_30 ) goto V_103;
if ( V_8 . V_39 -> V_107 ( V_79 , V_48 , & V_71 , & V_72 ) ) {
F_56 ( V_71 , V_72 ) ;
} else {
F_20 ( V_105 , V_11 , L_54 ) ;
}
break;
}
case V_108 : {
if ( V_8 . V_29 != V_73 ) goto V_103;
F_57 () ;
break;
}
case V_109 : {
if ( V_8 . V_29 != V_53 ) goto V_103;
F_58 () ;
break;
}
case V_110 : {
char * V_74 ;
if ( V_8 . V_29 != V_53 && V_8 . V_29 != V_54 && V_8 . V_29 != V_57 ) goto V_103;
if ( V_8 . V_39 -> V_111 ( V_79 , V_48 , & V_74 ) ) {
F_59 ( V_74 ) ;
} else {
F_20 ( V_105 , V_11 , L_55 ) ;
}
break;
}
case V_112 : {
char * V_74 ;
if ( V_8 . V_29 != V_53 && V_8 . V_29 != V_54 && V_8 . V_29 != V_57 ) goto V_103;
if ( V_8 . V_39 -> V_113 ( V_79 , V_48 , & V_74 ) ) {
F_60 ( V_74 ) ;
} else {
F_20 ( V_105 , V_11 , L_56 ) ;
}
break;
}
case V_114 : {
char * V_75 ;
if ( V_8 . V_29 != V_53 && V_8 . V_29 != V_54 && V_8 . V_29 != V_57 ) goto V_103;
if ( V_8 . V_39 -> V_115 ( V_79 , V_48 , & V_75 ) ) {
F_61 ( V_75 ) ;
} else {
F_20 ( V_105 , V_11 , L_57 ) ;
}
break;
}
case V_116 : {
int V_76 ;
char * V_77 ;
if ( V_8 . V_29 != V_53 && V_8 . V_29 != V_54 && V_8 . V_29 != V_57 ) goto V_103;
if ( V_8 . V_39 -> V_117 ( V_79 , V_48 , & V_76 , & V_77 ) ) {
F_62 ( V_76 , V_77 ) ;
} else {
F_20 ( V_105 , V_11 , L_57 ) ;
}
break;
}
case V_118 : {
char * V_78 ;
if ( V_8 . V_29 != V_57 ) goto V_103;
if ( V_8 . V_39 -> V_119 ( V_79 , V_48 , & V_78 ) ) {
F_63 ( V_78 ) ;
} else {
F_20 ( V_105 , V_11 , L_58 ) ;
}
break;
}
case V_120 : {
char * V_69 ;
char * V_72 ;
if ( V_8 . V_29 != V_57 ) goto V_103;
if ( V_8 . V_39 -> V_121 ( V_79 , V_48 , & V_69 , & V_72 ) ) {
F_64 ( V_69 , V_72 ) ;
} else {
F_20 ( V_105 , V_11 , L_59 ) ;
}
break;
}
default:
F_20 ( V_81 , V_11 , L_60 , V_9 , F_9 ( type ) ) ;
break;
}
return 0 ;
V_96:
F_20 ( V_81 , V_11 , L_61 , F_9 ( type ) ) ;
return 0 ;
V_103:
F_20 ( V_81 , V_11 , L_62 , F_71 ( V_8 . V_29 ) , F_9 ( type ) ) ;
return 0 ;
}
static int F_72 ( void ) {
F_12 ( ( 2 , L_63 ) ) ;
return FALSE ;
}
static void F_73 ( void ) {
}
int F_74 ( void ) {
int V_122 = V_8 . V_32 . V_123 ;
int V_124 = V_8 . V_19 . V_20 ;
#ifdef F_75
int V_125 = 0 ;
#endif
F_12 ( ( 0 , L_64 ) ) ;
do {
T_18 V_126 ;
T_18 V_127 ;
T_18 V_128 ;
struct V_129 V_130 ;
int V_131 ;
T_19 V_132 = FALSE ;
F_76 ( & V_126 ) ;
F_76 ( & V_127 ) ;
F_76 ( & V_128 ) ;
F_77 ( V_122 , & V_126 ) ;
F_77 ( V_122 , & V_128 ) ;
F_77 ( V_124 , & V_128 ) ;
if ( V_8 . V_19 . V_33 > 0 ) {
F_77 ( V_8 . V_19 . V_33 , & V_126 ) ;
}
#ifdef F_75
if ( V_125 <= 20 ) F_12 ( ( 4 , L_65 , V_125 ++ ) ) ;
#endif
V_130 . V_26 = 0 ;
V_130 . V_28 = 999999 ;
V_131 = F_70 ( V_133 , & V_126 , & V_127 , & V_128 , & V_130 ) ;
#ifdef F_75
if ( V_125 <= 20 ) F_12 ( ( 4 , L_66 , V_131 ) ) ;
#endif
if ( F_78 ( V_122 , & V_128 ) ) {
F_12 ( ( 0 , L_67 , V_125 ) ) ;
break;
}
if ( F_78 ( V_124 , & V_128 ) ) {
F_12 ( ( 0 , L_68 , V_125 ) ) ;
break;
}
if ( V_8 . V_19 . V_33 > 0 && F_78 ( V_8 . V_19 . V_33 , & V_128 ) ) {
F_12 ( ( 0 , L_69 , V_125 ) ) ;
break;
}
if ( F_78 ( V_122 , & V_126 ) ) {
long V_18 = F_79 ( & ( V_8 . V_32 ) , F_65 , & V_8 ) ;
#ifdef F_75
V_125 = 0 ;
#endif
if ( V_18 < 0 ) {
F_12 ( ( 0 , L_70 , V_125 ) ) ;
return ( int ) V_18 ;
}
}
if ( V_8 . V_19 . V_33 > 0 && F_78 ( V_8 . V_19 . V_33 , & V_126 ) ) {
#ifdef F_75
V_125 = 0 ;
#endif
V_132 = F_72 () ;
}
if ( V_8 . V_29 == V_54 || V_132 ) {
F_73 () ;
}
} while( 1 );
F_67 ( NULL , V_101 ) ;
F_12 ( ( 3 , L_51 ) ) ;
return 222 ;
}
