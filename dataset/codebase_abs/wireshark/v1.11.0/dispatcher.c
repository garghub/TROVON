int F_1 ( int V_1 , const char * V_2 , ... ) {
T_1 V_3 ;
char * V_4 ;
if ( V_5 < V_1 ) return 1 ;
va_start ( V_3 , V_2 ) ;
V_4 = F_2 ( V_2 , V_3 ) ;
va_end ( V_3 ) ;
if ( V_6 ) {
fprintf ( V_7 , L_1 , V_6 -> V_8 , V_6 -> V_9 , V_1 , V_4 ) ;
} else {
fprintf ( V_7 , L_2 , V_1 , V_4 ) ;
}
fflush ( V_7 ) ;
F_3 ( V_4 ) ;
return 1 ;
}
static char * F_4 ( char * * T_2 V_10 ) {
return F_5 ( L_3 , V_5 ) ;
}
static T_3 F_6 ( char * V_11 , char * * T_2 ) {
char * V_12 ;
int V_13 = ( int ) strtol ( V_11 , & V_12 , 10 ) ;
if ( V_12 <= V_11 ) {
* T_2 = F_7 ( L_4 ) ;
return FALSE ;
} else if ( V_13 < 0 || V_13 > 5 ) {
* T_2 = F_5 ( L_5 , V_13 ) ;
return FALSE ;
}
V_5 = V_13 ;
F_8 () ;
return TRUE ;
}
static void F_9 ( void ) {
#ifdef F_10
F_11 ( & V_14 . V_15 ) ;
F_12 ( & V_14 . V_16 , ( void * ) & V_14 . V_17 ) ;
#endif
}
static void F_13 ( void ) {
int V_18 ;
struct V_19 * V_20 = V_6 -> V_21 ;
int V_22 = V_6 -> V_22 ;
for( V_18 = 0 ; V_18 < V_22 ; V_18 ++ ) {
struct V_19 * V_23 = & ( V_20 [ V_18 ] ) ;
if ( V_23 -> V_8 > 0 ) {
F_14 ( ( 0 , L_6 , V_23 -> V_24 , V_23 -> V_8 ) ) ;
F_15 ( V_23 -> V_8 , V_25 ) ;
}
}
}
static void F_16 ( int V_26 , const char * V_2 , ... ) {
T_4 V_27 = 1024 ;
T_5 V_28 [ V_27 ] ;
T_1 V_3 ;
va_start ( V_3 , V_2 ) ;
F_17 ( V_28 , V_27 , V_2 , V_3 ) ;
va_end ( V_3 ) ;
F_14 ( ( 0 , L_7 , V_26 , V_28 ) ) ;
F_13 () ;
exit ( V_26 ) ;
}
static void F_18 ( int V_29 , const char * V_2 , ... ) {
T_4 V_27 = 1024 ;
T_5 V_28 [ V_27 ] ;
T_1 V_3 ;
static T_6 * V_30 ;
va_start ( V_3 , V_2 ) ;
F_17 ( V_28 , V_27 , V_2 , V_3 ) ;
va_end ( V_3 ) ;
F_14 ( ( 0 , L_8 , V_28 ) ) ;
V_30 = V_6 -> V_31 . V_32 -> error ( V_29 , V_28 ) ;
F_19 ( V_30 , V_33 ) ;
F_20 ( V_30 , TRUE ) ;
}
static char * F_21 ( T_7 * V_34 , char * * V_35 ) {
#define F_22 46
int V_18 ;
T_7 * V_36 ;
T_8 * V_37 ;
T_9 * V_38 ;
T_10 * V_39 ;
T_11 * V_40 ;
char V_41 [ F_22 ] ;
T_12 * V_4 = F_23 ( L_9 ) ;
char * V_42 ;
V_18 = 1 ;
for ( V_36 = F_24 ( V_34 ) ; V_36 != NULL ;
V_36 = F_25 ( V_36 ) ) {
V_37 = ( T_8 * ) V_36 -> V_43 ;
F_26 ( V_4 , L_10 , V_37 -> V_44 , V_37 -> V_44 ) ;
if ( V_37 -> V_45 != NULL )
F_26 ( V_4 , L_11 , V_37 -> V_45 ) ;
if ( V_37 -> V_46 != NULL )
F_26 ( V_4 , L_12 , V_37 -> V_46 ) ;
for ( V_38 = F_27 ( V_37 -> V_47 , 0 ) ; V_38 != NULL ;
V_38 = F_28 ( V_38 ) ) {
V_39 = ( T_10 * ) V_38 -> V_43 ;
switch( V_39 -> V_48 ) {
case V_49 :
if ( F_29 ( V_50 , & V_39 -> V_38 . V_51 , V_41 ,
F_22 ) ) {
F_26 ( V_4 , L_13 , V_41 ) ;
} else {
F_30 ( V_4 , L_14 ) ;
}
break;
case V_52 :
if ( F_29 ( V_53 , & V_39 -> V_38 . V_54 ,
V_41 , F_22 ) ) {
F_26 ( V_4 , L_13 , V_41 ) ;
} else {
F_30 ( V_4 , L_15 ) ;
}
break;
default:
F_26 ( V_4 , L_16 , V_39 -> V_48 ) ;
}
}
F_31 ( V_4 , V_4 -> V_27 - 1 ) ;
F_30 ( V_4 , L_17 ) ;
if ( V_37 -> V_55 )
F_30 ( V_4 , L_18 ) ;
else
F_30 ( V_4 , L_19 ) ;
V_40 = F_32 ( V_37 -> V_44 , 0 , V_35 , NULL ) ;
if ( V_40 != NULL ) {
if ( V_40 -> V_56 != NULL ) {
T_7 * V_57 = V_40 -> V_56 ;
T_13 * V_58 ;
F_30 ( V_4 , L_20 ) ;
for (; V_57 != NULL ; V_57 = F_25 ( V_57 ) ) {
V_58 = ( T_13 * ) V_57 -> V_43 ;
F_26 ( V_4 , L_21 , V_58 -> V_44 , ( V_58 -> V_59 ) ? V_58 -> V_59 : L_22 ) ;
}
F_31 ( V_4 , V_4 -> V_27 - 2 ) ;
F_30 ( V_4 , L_23 ) ;
}
F_26 ( V_4 , L_24 , V_40 -> V_60 ? L_25 : L_26 ) ;
if ( V_40 -> V_60 ) {
F_33 ( V_40 ) ;
V_40 = F_32 ( V_37 -> V_44 , 1 , V_35 , NULL ) ;
if ( V_40 -> V_56 != NULL ) {
T_7 * V_57 = V_40 -> V_56 ;
T_13 * V_58 ;
F_30 ( V_4 , L_27 ) ;
for (; V_57 != NULL ; V_57 = F_25 ( V_57 ) ) {
V_58 = ( T_13 * ) V_57 -> V_43 ;
F_26 ( V_4 , L_21 , V_58 -> V_44 , ( V_58 -> V_59 ) ? V_58 -> V_59 : L_22 ) ;
}
F_31 ( V_4 , V_4 -> V_27 - 2 ) ;
F_30 ( V_4 , L_23 ) ;
}
}
F_33 ( V_40 ) ;
}
F_30 ( V_4 , L_28 ) ;
}
F_31 ( V_4 , V_4 -> V_27 - 2 ) ;
F_30 ( V_4 , L_29 ) ;
V_42 = V_4 -> V_4 ;
F_34 ( V_4 , FALSE ) ;
return V_42 ;
}
static void F_35 ( char * * T_2 ) {
int V_61 = 0 ;
T_7 * V_34 ;
T_2 = NULL ;
V_34 = F_36 ( & V_61 , T_2 , NULL ) ;
if ( T_2 ) {
F_14 ( ( 1 , L_30 , T_2 ) ) ;
} else {
V_62 = F_21 ( V_34 , T_2 ) ;
if ( T_2 ) {
F_14 ( ( 1 , L_31 , T_2 ) ) ;
}
}
F_37 ( V_34 ) ;
}
static char * F_38 ( char * * T_2 V_10 ) {
return F_7 ( V_62 ? V_62 : L_22 ) ;
}
static char * F_39 ( char * * T_2 V_10 ) {
return F_5 ( L_32 , ( ( ( float ) V_63 ) / 1000000.0 ) ) ;
}
static T_3 F_40 ( char * V_11 , char * * T_2 ) {
char * V_12 ;
int V_64 = ( int ) strtol ( V_11 , & V_12 , 10 ) ;
if ( V_12 <= V_11 ) {
* T_2 = F_7 ( L_4 ) ;
return FALSE ;
}
V_63 = V_64 ;
return TRUE ;
}
static char * F_41 ( char * * T_2 V_10 ) {
return F_7 ( V_65 ) ;
}
static char * F_42 ( char * * T_2 V_10 ) {
return F_7 ( V_66 ) ;
}
static char * F_43 ( char * * T_2 V_10 ) {
T_12 * V_4 = F_23 ( L_22 ) ;
char * V_42 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_67 ; V_18 ++ ) {
if ( F_44 ( V_18 ) ) {
F_26 ( V_4 , L_33 ,
F_45 ( V_18 ) , F_46 ( V_18 ) ) ;
}
}
V_42 = V_4 -> V_4 ;
F_34 ( V_4 , FALSE ) ;
return V_42 ;
}
static T_3 F_47 ( char * V_11 , char * * T_2 ) {
if ( F_48 ( V_11 ) ) {
return TRUE ;
} else {
* T_2 = F_5 ( L_34 , V_11 ) ;
return FALSE ;
}
}
static T_3 F_49 ( char * V_11 , char * * T_2 ) {
if ( F_50 ( V_11 ) ) {
return TRUE ;
} else {
* T_2 = F_5 ( L_35 , V_11 ) ;
return FALSE ;
}
}
static char * F_51 ( char * * T_2 V_10 ) {
return F_52 ( V_68 , V_69 ) ;
}
static struct V_19 * F_53 ( struct V_6 * V_70 , int V_24 ) {
int V_18 ;
struct V_19 * V_20 = V_70 -> V_21 ;
int V_22 = V_70 -> V_22 ;
for( V_18 = 0 ; V_18 < V_22 ; V_18 ++ ) {
struct V_19 * V_23 = & ( V_20 [ V_18 ] ) ;
if ( V_23 -> V_24 == V_24 ) return V_23 ;
}
return NULL ;
}
static void F_54 ( struct V_19 * V_23 ) {
F_55 ( & ( V_23 -> V_71 ) , - 1 , 4096 ) ;
V_23 -> V_24 = - 1 ;
V_23 -> V_72 = FREE ;
V_23 -> V_71 . V_73 = - 1 ;
V_23 -> V_74 = - 1 ;
V_23 -> V_8 = - 1 ;
V_23 -> V_9 = - 1 ;
V_23 -> V_75 = FALSE ;
}
static void F_56 ( int V_8 ) {
V_6 -> V_76 = V_8 ;
}
static void F_57 ( void ) {
F_14 ( ( 2 , L_36 ) ) ;
}
void F_58 ( int V_77 ) {
F_59 ( ( V_78 , L_37 , V_77 ) ) ;
exit ( 1 ) ;
}
void F_60 ( int V_77 ) {
int V_79 ;
int V_18 ;
struct V_19 * V_20 = V_6 -> V_21 ;
int V_22 = V_6 -> V_22 ;
int V_8 = F_61 ( - 1 , & V_79 , V_80 ) ;
int V_81 = V_6 -> V_9 ;
V_6 -> V_9 = 0 ;
if ( V_77 != V_82 ) {
F_14 ( ( 1 , L_38 , V_77 ) ) ;
V_6 -> V_9 = V_81 ;
return;
}
F_14 ( ( 2 , L_39 , V_8 ) ) ;
for( V_18 = 0 ; V_18 < V_22 ; V_18 ++ ) {
struct V_19 * V_23 = & ( V_20 [ V_18 ] ) ;
if ( V_23 -> V_8 == V_8 ) {
if ( V_23 -> V_75 || V_6 -> V_75 ) {
F_62 ( V_6 -> V_83 , NULL , V_23 -> V_24 , V_84 , V_23 -> V_9 ) ;
} else {
char * V_42 = NULL ;
T_6 * V_85 ;
if ( F_63 ( V_79 ) ) {
V_42 = F_5 (
L_40 ,
V_8 , F_64 ( V_79 ) ) ;
} else if ( F_65 ( V_79 ) ) {
V_42 = F_5 (
L_41 ,
V_8 , F_66 ( V_79 ) , F_67 ( V_79 ) ? L_42 : L_43 ) ;
} else if ( F_68 ( V_79 ) ) {
V_42 = F_5 (
L_44 ,
V_8 , F_69 ( V_79 ) ) ;
}
V_85 = V_6 -> V_31 . V_32 -> V_86 ( V_42 ) ;
F_18 ( V_87 , V_42 ) ;
if ( V_42 ) F_3 ( V_42 ) ;
F_62 ( V_6 -> V_83 , V_85 , V_23 -> V_24 , V_88 , 0 ) ;
if ( V_85 ) F_20 ( V_85 , TRUE ) ;
}
F_70 ( V_23 , V_89 ) ;
F_54 ( V_23 ) ;
V_6 -> V_9 = V_81 ;
return;
}
}
if ( V_8 == V_6 -> V_76 ) {
V_6 -> V_76 = 0 ;
V_6 -> V_9 = V_81 ;
F_14 ( ( 2 , L_45 , V_8 ) ) ;
return;
}
F_18 ( V_90 , L_46 , V_8 ) ;
V_6 -> V_9 = V_81 ;
}
static void F_71 ( void ) {
V_6 -> V_75 = TRUE ;
F_13 () ;
exit ( 0 ) ;
}
static long F_72 ( T_14 * V_91 , T_4 V_27 , T_15 V_24 , T_16 type , T_17 V_9 , void * V_43 ) {
T_6 V_92 ;
struct V_19 * V_23 = (struct V_19 * ) V_43 ;
V_6 -> V_9 = V_23 -> V_9 = V_9 ;
V_92 . V_43 = V_91 ;
V_92 . V_27 = ( V_93 ) V_27 ;
if ( V_24 != V_23 -> V_24 ) {
goto V_94;
}
switch( type ) {
case V_33 : break;
case V_95 : break;
case V_96 : F_70 ( V_23 , V_97 ) ; break;
case V_84 :
V_23 -> V_75 = TRUE ;
F_70 ( V_23 , V_98 ) ;
break;
case V_99 : break;
case V_100 : break;
case V_101 : F_70 ( V_23 , V_102 ) ; break;
case V_103 : F_70 ( V_23 , V_104 ) ; break;
case V_105 : F_70 ( V_23 , V_106 ) ; break;
case V_107 : break;
case V_108 : break;
case V_109 : break;
case V_110 : break;
case V_111 :
case V_112 : F_70 ( V_23 , V_113 ) ; break;
case V_114 : break;
case V_115 : break;
case V_116 : break;
default:
goto V_94;
}
F_14 ( ( 4 , L_47 , V_9 , V_23 -> V_24 , type ) ) ;
return F_62 ( V_6 -> V_83 , & V_92 , V_24 , type , V_9 ) ;
V_94:
F_70 ( V_23 , V_117 ) ;
V_23 -> V_75 = TRUE ;
F_15 ( V_23 -> V_8 , V_25 ) ;
F_18 ( V_87 , L_48 , V_24 ) ;
return 0 ;
}
static void F_73 ( T_18 * V_85 , T_15 V_24 ) {
struct V_19 * V_23 ;
int V_9 = V_6 -> V_9 ;
int V_8 ;
if ( ( V_23 = F_53 ( V_6 , V_24 ) ) ) {
F_18 ( V_118 , L_49 , V_24 ) ;
return;
} else if ( ( V_23 = F_53 ( V_6 , - 1 ) ) ) {
int V_119 [ 2 ] ;
int V_120 [ 2 ] ;
int V_121 ;
int V_122 ;
int V_123 ;
int V_124 ;
F_14 ( ( 5 , L_50 ) ) ;
if( F_74 ( V_119 ) < 0 ) {
F_18 ( V_125 , L_51 , strerror ( V_126 ) ) ;
return;
}
V_122 = V_119 [ 0 ] ;
V_123 = V_119 [ 1 ] ;
F_14 ( ( 5 , L_52 ) ) ;
if( F_74 ( V_120 ) < 0 ) {
F_75 ( V_122 ) ;
F_75 ( V_123 ) ;
F_18 ( V_125 , L_53 , strerror ( V_126 ) ) ;
return;
}
V_124 = V_120 [ 0 ] ;
V_121 = V_120 [ 1 ] ;
F_14 ( ( 4 , L_54 ) ) ;
switch ( ( V_8 = F_76 () ) ) {
case - 1 : {
F_75 ( V_123 ) ;
F_75 ( V_121 ) ;
F_75 ( V_124 ) ;
F_75 ( V_122 ) ;
F_18 ( V_125 , L_55 , strerror ( V_126 ) ) ;
return;
}
case 0 : {
F_57 () ;
F_75 ( V_123 ) ;
F_75 ( V_124 ) ;
F_77 ( V_24 , V_122 , V_121 , V_9 , & V_14 ) ;
exit ( F_78 () ) ;
return;
}
default: {
F_75 ( V_121 ) ;
F_75 ( V_122 ) ;
F_55 ( & ( V_23 -> V_71 ) , V_124 , 4096 ) ;
V_23 -> V_74 = V_123 ;
V_23 -> V_8 = V_8 ;
V_23 -> V_24 = V_24 ;
V_23 -> V_75 = FALSE ;
F_70 ( V_23 , V_127 ) ;
F_14 ( ( 4 , L_56 ,
V_8 , V_23 -> V_24 , V_124 , V_123 ) ) ;
V_128 . V_129 = ( int ) ( V_130 / 1000000 ) ;
V_128 . V_131 = ( int ) ( V_130 % 1000000 ) ;
F_79 ( 0 , NULL , NULL , NULL , & V_128 ) ;
F_62 ( V_123 , V_85 , V_23 -> V_24 , V_132 , V_6 -> V_9 ) ;
return;
}
}
} else {
F_18 ( V_125 , L_57 , V_6 -> V_22 ) ;
return;
}
}
static long F_80 ( T_14 * V_91 , T_4 V_27 , T_15 V_24 , T_16 type , T_17 V_9 , void * V_43 V_10 ) {
T_6 V_92 ;
V_92 . V_43 = V_91 ;
V_92 . V_27 = ( V_93 ) V_27 ;
V_6 -> V_9 = V_9 ;
F_14 ( ( 1 , L_58 , F_81 ( type ) , V_24 , V_9 ) ) ;
if ( V_24 == 0 ) {
F_14 ( ( 2 , L_59 ) ) ;
switch( type ) {
case V_133 :
F_71 () ;
return 0 ;
case V_134 :
F_14 ( ( 2 , L_60 , V_9 ) ) ;
F_62 ( V_6 -> V_83 , NULL , V_24 , V_100 , V_9 ) ;
return 0 ;
case V_135 : {
char * V_136 ;
char * V_137 ;
if ( V_6 -> V_138 . V_139 -> V_140 ( V_91 , V_27 , & V_136 , & V_137 ) ) {
T_6 * V_30 ;
char * T_2 ;
if ( ! F_82 ( V_68 , V_136 , V_137 , & T_2 ) ) {
F_18 ( V_141 , L_61 , T_2 ) ;
F_3 ( T_2 ) ;
return 0 ;
}
V_30 = V_6 -> V_31 . V_32 -> V_136 ( V_136 , V_137 ) ;
F_19 ( V_30 , V_99 ) ;
F_20 ( V_30 , TRUE ) ;
F_14 ( ( 1 , L_62 , V_136 , V_137 ) ) ;
return 0 ;
} else {
F_18 ( V_141 , L_63 ) ;
return 0 ;
}
}
case V_142 : {
T_6 * V_30 ;
char * V_136 ;
if ( V_6 -> V_138 . V_139 -> V_143 ( V_91 , V_27 , & V_136 ) ) {
char * T_2 ;
char * V_11 ;
if ( ! ( V_11 = F_83 ( V_68 , V_136 , & T_2 ) ) ) {
F_18 ( V_144 , L_61 , T_2 ) ;
F_3 ( T_2 ) ;
return 0 ;
}
V_30 = V_6 -> V_31 . V_32 -> V_136 ( V_136 , V_11 ) ;
F_19 ( V_30 , V_99 ) ;
F_20 ( V_30 , TRUE ) ;
F_14 ( ( 1 , L_64 , V_136 , V_11 ) ) ;
return 0 ;
} else {
F_18 ( V_144 , L_63 ) ;
return 0 ;
}
}
default:
F_18 ( V_145 , L_65 , type ) ;
return 0 ;
}
} else {
struct V_19 * V_23 ;
F_14 ( ( 2 , L_66 ) ) ;
if ( ! ( V_23 = F_53 ( V_6 , V_24 ) ) ) {
if ( type == V_132 ) {
F_73 ( & V_92 , V_24 ) ;
return 0 ;
} else {
F_18 ( V_146 , L_67 , V_24 ) ;
return 0 ;
}
} else {
switch( type ) {
case V_133 :
F_70 ( V_23 , V_89 ) ;
goto V_147;
case V_148 :
F_70 ( V_23 , V_102 ) ;
goto V_147;
case V_149 :
F_70 ( V_23 , V_104 ) ;
goto V_147;
case V_150 :
F_70 ( V_23 , V_106 ) ;
goto V_147;
case V_151 :
F_70 ( V_23 , V_113 ) ;
goto V_147;
case V_152 :
case V_153 :
case V_135 :
case V_142 :
case V_134 :
case V_154 :
case V_155 :
case V_156 :
case V_157 :
V_147: {
F_14 ( ( 3 , L_68 , V_24 , type , V_9 ) ) ;
return F_62 ( V_23 -> V_74 , & V_92 , V_24 , type , V_9 ) ;
}
default:
F_18 ( V_145 , L_69 , V_9 , type ) ;
return 0 ;
}
}
}
}
int F_84 ( void ) {
int V_83 = V_6 -> V_83 ;
int V_158 = V_6 -> V_158 . V_73 ;
struct V_19 * V_21 = V_6 -> V_21 ;
F_14 ( ( 5 , L_70 , V_158 , V_83 ) ) ;
do {
T_19 V_159 ;
T_19 V_160 ;
struct V_19 * V_23 ;
int V_161 ;
int V_162 = 0 ;
struct V_163 V_164 ;
F_85 ( & V_159 ) ;
F_85 ( & V_160 ) ;
F_86 ( V_158 , & V_159 ) ;
F_86 ( V_158 , & V_160 ) ;
F_86 ( V_83 , & V_160 ) ;
for ( V_23 = V_21 ; V_23 -> V_8 ; V_23 ++ ) {
if ( V_23 -> V_24 > 0 ) {
V_162 ++ ;
F_86 ( V_23 -> V_71 . V_73 , & V_159 ) ;
F_86 ( V_23 -> V_71 . V_73 , & V_160 ) ;
}
}
F_14 ( ( 4 , L_71 , V_162 , V_164 . V_131 ) ) ;
V_164 . V_129 = ( int ) ( V_63 / 1000000 ) ;
V_164 . V_131 = ( int ) ( V_63 % 1000000 ) ;
V_161 = F_79 ( V_165 , & V_159 , NULL , & V_160 , & V_164 ) ;
F_14 ( ( 5 , L_72 , V_162 , V_161 ) ) ;
if ( V_161 < 0 ) {
F_14 ( ( 1 , L_73 , strerror ( V_126 ) ) ) ;
continue;
}
if ( F_87 ( V_158 , & V_159 ) ) {
long V_166 = F_88 ( & ( V_6 -> V_158 ) , F_80 , V_6 ) ;
if ( V_166 < 0 ) {
F_14 ( ( 1 , L_74 ) ) ;
continue;
}
}
if ( F_87 ( V_158 , & V_160 ) ) {
F_14 ( ( 1 , L_75 ) ) ;
continue;
}
if ( F_87 ( V_83 , & V_160 ) ) {
F_14 ( ( 1 , L_76 ) ) ;
continue;
}
for ( V_23 = V_21 ; V_23 -> V_8 ; V_23 ++ ) {
if ( V_23 -> V_71 . V_73 > 0 ) {
if ( F_87 ( V_23 -> V_71 . V_73 , & V_160 ) ) {
struct V_163 V_167 ;
V_167 . V_129 = 0 ;
V_167 . V_131 = V_168 ;
F_14 ( ( 1 , L_77 , V_23 -> V_24 ) ) ;
F_15 ( V_23 -> V_8 , V_25 ) ;
F_79 ( 0 , NULL , NULL , NULL , & V_167 ) ;
F_54 ( V_23 ) ;
continue;
}
if ( F_87 ( V_23 -> V_71 . V_73 , & V_159 ) ) {
long V_166 = F_88 ( & ( V_23 -> V_71 ) , F_72 , V_23 ) ;
if ( V_166 < 0 ) {
F_14 ( ( 1 , L_78 , V_23 -> V_24 ) ) ;
continue;
}
continue;
}
}
}
} while( 1 );
return 1 ;
}
void F_89 ( int V_77 V_10 ) {
F_14 ( ( 1 , L_79 ) ) ;
}
