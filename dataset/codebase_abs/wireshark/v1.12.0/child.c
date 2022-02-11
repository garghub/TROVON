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
V_8 . V_19 . V_20 , V_8 . V_9 , F_9 ( V_17 ) , V_8 . V_11 , ( V_18 > 0 ? L_6 : strerror ( V_21 ) ) ) ;
return V_18 ;
}
static void F_10 ( int T_6 V_12 ) {
F_11 ( ( 3 , L_7 ) ) ;
exit ( 0 ) ;
}
extern void F_12 ( T_7 V_9 , int V_22 , int V_20 , int V_11 , T_8 * V_23 ) {
V_24 = V_23 ;
V_25 . V_26 = V_27 / 1000000 ;
V_25 . V_28 = V_27 % 1000000 ;
V_8 . V_9 = V_9 ;
V_8 . V_29 = V_30 ;
V_8 . V_10 = F_13 () ;
V_8 . V_31 = F_14 () ;
V_8 . V_11 = V_11 ;
F_15 ( & ( V_8 . V_32 ) , V_22 , 4096 ) ;
V_8 . V_19 . V_20 = V_20 ;
V_8 . V_19 . V_33 = - 1 ;
V_8 . V_19 . V_34 = - 1 ;
V_8 . V_19 . V_35 = - 1 ;
F_16 ( & V_8 . V_36 , NULL ) ;
V_8 . V_37 . V_26 = V_8 . V_36 . V_26 ;
V_8 . V_37 . V_28 = V_8 . V_36 . V_28 ;
F_17 ( & ( V_8 . V_38 ) , & ( V_8 . V_39 ) , NULL , NULL ) ;
F_18 () ;
F_11 ( ( 5 , L_8 , V_9 , V_22 , V_20 , V_11 ) ) ;
signal ( V_40 , V_41 ) ;
signal ( V_42 , F_10 ) ;
signal ( V_43 , V_41 ) ;
signal ( V_44 , V_41 ) ;
signal ( V_45 , V_41 ) ;
signal ( V_46 , V_41 ) ;
}
void F_19 ( int V_47 , unsigned V_11 , const char * V_2 , ... ) {
T_9 V_48 = 1024 ;
T_10 V_49 [ V_48 ] ;
T_1 V_3 ;
static T_4 * V_50 ;
va_start ( V_3 , V_2 ) ;
F_20 ( V_49 , V_48 , V_2 , V_3 ) ;
va_end ( V_3 ) ;
F_11 ( ( 0 , L_9 , V_49 ) ) ;
V_50 = V_8 . V_38 -> error ( V_47 , V_49 ) ;
F_8 ( V_8 . V_19 . V_20 , V_50 , V_8 . V_9 , V_51 , V_11 , NULL ) ;
F_21 ( V_50 , TRUE ) ;
}
static char * F_22 ( char * * T_2 ) {
char * V_52 = F_23 ( NULL , 128 ) ;
if ( ! V_52 ) {
* T_2 = F_5 ( strerror ( V_21 ) ) ;
}
return V_52 ;
}
static T_3 F_24 ( char * V_13 , char * * T_2 ) {
if ( F_25 ( V_13 ) != 0 ) {
* T_2 = F_3 ( L_10 , strerror ( V_21 ) ) ;
return FALSE ;
}
return TRUE ;
}
static char * F_26 ( char * * T_2 ) {
if ( V_8 . V_29 != V_53 && V_8 . V_29 != V_54 ) {
* T_2 = F_5 ( L_11 ) ;
return NULL ;
}
return F_3 ( L_2 , V_55 ) ;
}
static T_3 F_27 ( char * V_13 , char * * T_2 V_12 ) {
T_11 * V_56 = NULL ;
if ( V_8 . V_29 != V_30 && V_8 . V_29 != V_57 ) {
* T_2 = F_5 ( L_12 ) ;
return FALSE ;
} else if ( F_28 ( V_13 , & V_56 ) ) {
if ( V_8 . V_58 ) F_29 ( V_8 . V_58 ) ;
if ( V_8 . V_59 ) F_30 ( V_8 . V_59 ) ;
V_8 . V_59 = V_56 ;
V_8 . V_58 = F_5 ( V_13 ) ;
return TRUE ;
} else {
* T_2 = F_5 ( V_60 ) ;
return FALSE ;
}
}
static char * F_31 ( char * * T_2 V_12 ) { return F_5 ( V_8 . V_58 ? V_8 . V_58 : L_13 ) ; }
static T_3 F_32 ( char * V_13 , char * * T_2 ) {
if ( V_8 . V_29 != V_30 ) {
* T_2 = F_3 ( L_14 , V_13 ) ;
return FALSE ;
}
if ( F_33 ( V_13 , FALSE ) ) {
F_34 ( V_13 ) ;
if ( V_61 ) F_29 ( V_61 ) ;
V_61 = F_5 ( V_13 ) ;
return TRUE ;
} else {
* T_2 = F_3 ( L_15 , V_13 ) ;
return FALSE ;
}
}
static char * F_35 ( char * * T_2 V_12 ) { return F_5 ( V_61 ? V_61 : L_13 ) ; }
static char * F_36 ( char * * T_2 ) {
T_12 * V_62 = NULL ;
T_13 * V_63 = F_37 ( L_16 , 0 , & V_62 ) ;
T_14 * V_4 = F_38 ( L_17 ) ;
char * V_64 ;
const char * V_65 ;
if ( V_62 ) {
* T_2 = F_3 ( L_18 , V_62 -> V_66 ) ;
return NULL ;
}
while( ( V_65 = F_39 ( V_63 ) ) ) {
F_40 ( V_4 , L_19 , V_65 ) ;
}
F_41 ( V_63 ) ;
F_42 ( V_4 , V_4 -> V_48 - 2 ) ;
F_43 ( V_4 , L_20 ) ;
V_64 = V_4 -> V_4 ;
F_44 ( V_4 , FALSE ) ;
return V_64 ;
}
static T_3 F_45 ( char * V_13 , char * * T_2 ) {
int V_67 = F_46 ( V_13 ) ;
if ( V_67 < 0 ) {
* T_2 = F_3 ( L_21 , V_13 ) ;
return FALSE ;
} else {
V_68 = V_67 ;
return TRUE ;
}
}
static char * F_47 ( char * * T_2 V_12 ) {
return F_3 ( L_22 ,
F_48 ( V_68 ) ,
V_68 , F_49 ( V_68 ) ) ;
}
static T_3 F_50 ( char * V_13 , char * * T_2 ) {
if ( F_51 ( V_13 ) ) {
return TRUE ;
} else {
* T_2 = F_3 ( L_23 , V_13 ) ;
return FALSE ;
}
}
static char * F_52 ( char * * T_2 V_12 ) {
return F_53 ( V_69 , V_70 ) ;
}
static void F_54 ( char * V_71 ) {
F_11 ( ( 2 , L_24 , V_71 ) ) ;
F_19 ( V_72 , V_8 . V_11 , L_25 ) ;
V_8 . V_29 = V_54 ;
}
static void F_55 ( char * V_73 , char * V_74 ) {
F_11 ( ( 2 , L_26 , V_73 , V_74 ) ) ;
F_19 ( V_72 , V_8 . V_11 , L_27 ) ;
V_8 . V_29 = V_75 ;
}
static void F_56 ( void ) {
F_11 ( ( 2 , L_28 ) ) ;
F_19 ( V_72 , V_8 . V_11 , L_29 ) ;
V_8 . V_29 = V_53 ;
}
static void F_57 ( void ) {
F_11 ( ( 2 , L_30 ) ) ;
F_19 ( V_72 , V_8 . V_11 , L_31 ) ;
V_8 . V_29 = V_57 ;
}
static void F_58 ( char * V_76 ) {
F_11 ( ( 2 , L_32 , V_76 ) ) ;
F_19 ( V_72 , V_8 . V_11 , L_33 ) ;
}
static void F_59 ( char * V_76 ) {
F_11 ( ( 2 , L_34 , V_76 ) ) ;
F_19 ( V_72 , V_8 . V_11 , L_35 ) ;
}
static void F_60 ( char * V_77 ) {
F_11 ( ( 2 , L_36 , V_77 ) ) ;
F_19 ( V_72 , V_8 . V_11 , L_37 ) ;
}
static void F_61 ( int V_78 , char * V_79 ) {
F_11 ( ( 2 , L_38 , V_78 , V_79 ) ) ;
F_19 ( V_72 , V_8 . V_11 , L_39 ) ;
}
static void F_62 ( char * V_80 ) {
F_11 ( ( 2 , L_40 , V_80 ) ) ;
F_19 ( V_72 , V_8 . V_11 , L_41 ) ;
}
static void F_63 ( char * V_71 , char * V_74 ) {
F_11 ( ( 2 , L_42 , V_71 , V_74 ) ) ;
F_19 ( V_72 , V_8 . V_11 , L_43 ) ;
}
static long F_64 ( T_15 * V_81 , T_9 V_48 , T_7 V_9 , T_5 type , T_16 V_11 , void * T_17 V_12 ) {
T_4 V_50 ;
T_4 * V_82 ;
char * T_2 = NULL ;
V_8 . V_11 = V_11 ;
F_11 ( ( 2 , L_44 , F_9 ( type ) , V_48 ) ) ;
if ( V_8 . V_9 != V_9 ) {
F_19 ( V_83 , V_11 ,
L_45 , V_8 . V_9 , V_9 , F_9 ( type ) ) ;
return 0 ;
}
V_50 . T_17 = V_81 ;
V_50 . V_48 = ( V_84 ) V_48 ;
switch( type ) {
case V_85 : {
V_8 . V_29 = V_86 ;
if ( ! F_65 ( V_69 , ( V_87 * ) & V_50 , & T_2 ) ) {
F_19 ( V_88 , V_11 ,
L_46 , T_2 ) ;
} else {
V_8 . V_29 = V_30 ;
F_66 ( NULL , V_89 ) ;
}
break;
}
case V_90 :
F_11 ( ( 1 , L_47 ) ) ;
F_66 ( & V_50 , V_91 ) ;
break;
case V_92 : {
char * V_93 ;
char * V_94 ;
if ( V_8 . V_39 -> V_95 && V_8 . V_39 -> V_95 ( V_81 , V_48 , & V_93 , & V_94 ) ) {
if ( ! F_67 ( V_69 , V_93 , V_94 , & T_2 ) ) {
F_19 ( V_96 , V_11 , L_48 , T_2 ) ;
F_29 ( T_2 ) ;
return 0 ;
}
V_82 = V_8 . V_38 -> V_93 ( V_93 , V_94 ) ;
F_66 ( V_82 , V_97 ) ;
F_21 ( V_82 , TRUE ) ;
F_11 ( ( 1 , L_49 , V_93 , V_94 ) ) ;
break;
} else {
goto V_98;
}
}
case V_99 : {
char * V_93 ;
if ( V_8 . V_39 -> V_100 && V_8 . V_39 -> V_100 ( V_81 , V_48 , & V_93 ) ) {
char * V_13 ;
if ( ! ( V_13 = F_68 ( V_69 , V_93 , & T_2 ) ) ) {
F_19 ( V_101 , V_11 , L_48 , T_2 ) ;
F_29 ( T_2 ) ;
return 0 ;
}
V_82 = V_8 . V_38 -> V_93 ( V_93 , V_13 ) ;
F_66 ( V_82 , V_97 ) ;
F_21 ( V_82 , TRUE ) ;
F_11 ( ( 2 , L_50 , V_93 , V_13 ) ) ;
break;
} else {
goto V_98;
}
}
case V_102 :
F_66 ( NULL , V_103 ) ;
F_11 ( ( 3 , L_51 ) ) ;
F_69 ( 0 , NULL , NULL , NULL , & V_25 ) ;
F_11 ( ( 1 , L_52 ) ) ;
exit ( 0 ) ;
break;
case V_104 : {
char * V_71 ;
if ( V_8 . V_29 != V_30 ) goto V_105;
if ( V_8 . V_39 -> V_106 ( V_81 , V_48 , & V_71 ) ) {
F_54 ( V_71 ) ;
} else {
F_19 ( V_107 , V_11 , L_53 ) ;
}
break;
}
case V_108 : {
char * V_73 ;
char * V_74 ;
if ( V_8 . V_29 != V_30 ) goto V_105;
if ( V_8 . V_39 -> V_109 ( V_81 , V_48 , & V_73 , & V_74 ) ) {
F_55 ( V_73 , V_74 ) ;
} else {
F_19 ( V_107 , V_11 , L_54 ) ;
}
break;
}
case V_110 : {
if ( V_8 . V_29 != V_75 ) goto V_105;
F_56 () ;
break;
}
case V_111 : {
if ( V_8 . V_29 != V_53 ) goto V_105;
F_57 () ;
break;
}
case V_112 : {
char * V_76 ;
if ( V_8 . V_29 != V_53 && V_8 . V_29 != V_54 && V_8 . V_29 != V_57 ) goto V_105;
if ( V_8 . V_39 -> V_113 ( V_81 , V_48 , & V_76 ) ) {
F_58 ( V_76 ) ;
} else {
F_19 ( V_107 , V_11 , L_55 ) ;
}
break;
}
case V_114 : {
char * V_76 ;
if ( V_8 . V_29 != V_53 && V_8 . V_29 != V_54 && V_8 . V_29 != V_57 ) goto V_105;
if ( V_8 . V_39 -> V_115 ( V_81 , V_48 , & V_76 ) ) {
F_59 ( V_76 ) ;
} else {
F_19 ( V_107 , V_11 , L_56 ) ;
}
break;
}
case V_116 : {
char * V_77 ;
if ( V_8 . V_29 != V_53 && V_8 . V_29 != V_54 && V_8 . V_29 != V_57 ) goto V_105;
if ( V_8 . V_39 -> V_117 ( V_81 , V_48 , & V_77 ) ) {
F_60 ( V_77 ) ;
} else {
F_19 ( V_107 , V_11 , L_57 ) ;
}
break;
}
case V_118 : {
int V_78 ;
char * V_79 ;
if ( V_8 . V_29 != V_53 && V_8 . V_29 != V_54 && V_8 . V_29 != V_57 ) goto V_105;
if ( V_8 . V_39 -> V_119 ( V_81 , V_48 , & V_78 , & V_79 ) ) {
F_61 ( V_78 , V_79 ) ;
} else {
F_19 ( V_107 , V_11 , L_57 ) ;
}
break;
}
case V_120 : {
char * V_80 ;
if ( V_8 . V_29 != V_57 ) goto V_105;
if ( V_8 . V_39 -> V_121 ( V_81 , V_48 , & V_80 ) ) {
F_62 ( V_80 ) ;
} else {
F_19 ( V_107 , V_11 , L_58 ) ;
}
break;
}
case V_122 : {
char * V_71 ;
char * V_74 ;
if ( V_8 . V_29 != V_57 ) goto V_105;
if ( V_8 . V_39 -> V_123 ( V_81 , V_48 , & V_71 , & V_74 ) ) {
F_63 ( V_71 , V_74 ) ;
} else {
F_19 ( V_107 , V_11 , L_59 ) ;
}
break;
}
default:
F_19 ( V_83 , V_11 , L_60 , V_9 , F_9 ( type ) ) ;
break;
}
return 0 ;
V_98:
F_19 ( V_83 , V_11 , L_61 , F_9 ( type ) ) ;
return 0 ;
V_105:
F_19 ( V_83 , V_11 , L_62 , F_70 ( V_8 . V_29 ) , F_9 ( type ) ) ;
return 0 ;
}
static int F_71 ( void ) {
F_11 ( ( 2 , L_63 ) ) ;
return FALSE ;
}
static void F_72 ( void ) {
}
int F_73 ( void ) {
int V_124 = V_8 . V_32 . V_125 ;
int V_126 = V_8 . V_19 . V_20 ;
#ifdef F_74
int V_127 = 0 ;
#endif
F_11 ( ( 0 , L_64 ) ) ;
do {
T_18 V_128 ;
T_18 V_129 ;
T_18 V_130 ;
struct V_131 V_132 ;
int V_133 ;
T_19 V_134 = FALSE ;
F_75 ( & V_128 ) ;
F_75 ( & V_129 ) ;
F_75 ( & V_130 ) ;
F_76 ( V_124 , & V_128 ) ;
F_76 ( V_124 , & V_130 ) ;
F_76 ( V_126 , & V_130 ) ;
if ( V_8 . V_19 . V_33 > 0 ) {
F_76 ( V_8 . V_19 . V_33 , & V_128 ) ;
}
#ifdef F_74
if ( V_127 <= 20 ) F_11 ( ( 4 , L_65 , V_127 ++ ) ) ;
#endif
V_132 . V_26 = 0 ;
V_132 . V_28 = 999999 ;
V_133 = F_69 ( V_135 , & V_128 , & V_129 , & V_130 , & V_132 ) ;
#ifdef F_74
if ( V_127 <= 20 ) F_11 ( ( 4 , L_66 , V_133 ) ) ;
#endif
if ( F_77 ( V_124 , & V_130 ) ) {
F_11 ( ( 0 , L_67 , V_127 ) ) ;
break;
}
if ( F_77 ( V_126 , & V_130 ) ) {
F_11 ( ( 0 , L_68 , V_127 ) ) ;
break;
}
if ( V_8 . V_19 . V_33 > 0 && F_77 ( V_8 . V_19 . V_33 , & V_130 ) ) {
F_11 ( ( 0 , L_69 , V_127 ) ) ;
break;
}
if ( F_77 ( V_124 , & V_128 ) ) {
long V_18 = F_78 ( & ( V_8 . V_32 ) , F_64 , & V_8 ) ;
#ifdef F_74
V_127 = 0 ;
#endif
if ( V_18 < 0 ) {
F_11 ( ( 0 , L_70 , V_127 ) ) ;
return ( int ) V_18 ;
}
}
if ( V_8 . V_19 . V_33 > 0 && F_77 ( V_8 . V_19 . V_33 , & V_128 ) ) {
#ifdef F_74
V_127 = 0 ;
#endif
V_134 = F_71 () ;
}
if ( V_8 . V_29 == V_54 || V_134 ) {
F_72 () ;
}
} while( 1 );
F_66 ( NULL , V_103 ) ;
F_11 ( ( 3 , L_51 ) ) ;
return 222 ;
}
