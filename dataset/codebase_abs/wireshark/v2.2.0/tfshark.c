static void
F_1 ( T_1 * V_1 )
{
fprintf ( V_1 , L_1 ) ;
fprintf ( V_1 , L_2 ) ;
fprintf ( V_1 , L_1 ) ;
fprintf ( V_1 , L_3 ) ;
fprintf ( V_1 , L_4 ) ;
fprintf ( V_1 , L_1 ) ;
fprintf ( V_1 , L_5 ) ;
fprintf ( V_1 , L_6 ) ;
fprintf ( V_1 , L_7 ) ;
fprintf ( V_1 , L_8 ) ;
fprintf ( V_1 , L_9 ) ;
fprintf ( V_1 , L_10 , V_2 ) ;
fprintf ( V_1 , L_11 ) ;
fprintf ( V_1 , L_12 ) ;
fprintf ( V_1 , L_13 ) ;
fprintf ( V_1 , L_14 ) ;
fprintf ( V_1 , L_15 ) ;
fprintf ( V_1 , L_16 ) ;
fprintf ( V_1 , L_17 ) ;
fprintf ( V_1 , L_18 ) ;
fprintf ( V_1 , L_19 ) ;
fprintf ( V_1 , L_20 ) ;
fprintf ( V_1 , L_21 ) ;
fprintf ( V_1 , L_22 ) ;
fprintf ( V_1 , L_23 ) ;
fprintf ( V_1 , L_24 ) ;
fprintf ( V_1 , L_25 ) ;
fprintf ( V_1 , L_26 ) ;
fprintf ( V_1 , L_27 ) ;
fprintf ( V_1 , L_28 ) ;
fprintf ( V_1 , L_29 ) ;
fprintf ( V_1 , L_30 ) ;
fprintf ( V_1 , L_31 ) ;
fprintf ( V_1 , L_32 ) ;
fprintf ( V_1 , L_33 ) ;
fprintf ( V_1 , L_34 ) ;
fprintf ( V_1 , L_35 ) ;
fprintf ( V_1 , L_36 ) ;
fprintf ( V_1 , L_37 ) ;
fprintf ( V_1 , L_38 ) ;
fprintf ( V_1 , L_1 ) ;
fprintf ( V_1 , L_39 ) ;
fprintf ( V_1 , L_40 ) ;
fprintf ( V_1 , L_41 ) ;
fprintf ( V_1 , L_42 ) ;
fprintf ( V_1 , L_43 ) ;
fprintf ( V_1 , L_44 ) ;
fprintf ( V_1 , L_45 ) ;
fprintf ( V_1 , L_46 ) ;
}
static void
F_2 ( void )
{
T_1 * V_1 ;
V_1 = stdout ;
fprintf ( V_1 , L_47 , F_3 () ) ;
fprintf ( V_1 , L_1 ) ;
fprintf ( V_1 , L_48 ) ;
fprintf ( V_1 , L_1 ) ;
fprintf ( V_1 , L_49 ) ;
fprintf ( V_1 , L_50 ) ;
fprintf ( V_1 , L_51 ) ;
fprintf ( V_1 , L_52 ) ;
fprintf ( V_1 , L_53 ) ;
fprintf ( V_1 , L_54 ) ;
fprintf ( V_1 , L_55 ) ;
fprintf ( V_1 , L_56 ) ;
fprintf ( V_1 , L_57 ) ;
fprintf ( V_1 , L_58 ) ;
fprintf ( V_1 , L_1 ) ;
fprintf ( V_1 , L_59 ) ;
fprintf ( V_1 , L_60 ) ;
fprintf ( V_1 , L_61 ) ;
fprintf ( V_1 , L_1 ) ;
}
static void
F_4 ( const T_2 * V_3 , T_3 V_4 ,
const T_2 * V_5 , T_4 V_6 )
{
if ( ( V_4 & V_7 & V_8 . V_9 ) == 0 &&
V_8 . V_9 != 0 ) {
return;
}
F_5 ( V_3 , V_4 , V_5 , V_6 ) ;
}
static void
F_6 ( void ) {
T_2 * V_10 , * V_11 ;
if ( F_7 () ) {
V_10 = F_8 () ;
V_11 = F_9 () ;
fprintf ( V_12 , L_62 ,
V_10 , V_11 ) ;
F_10 ( V_10 ) ;
F_10 ( V_11 ) ;
if ( F_11 () ) {
fprintf ( V_12 , L_63 ) ;
}
fprintf ( V_12 , L_1 ) ;
}
}
static void
F_12 ( T_5 * V_13 )
{
F_13 ( V_13 ) ;
}
int
main ( int V_14 , char * V_15 [] )
{
T_5 * V_16 ;
T_5 * V_17 ;
char * V_18 ;
int V_19 ;
static const struct V_20 V_21 [] = {
{ L_64 , V_22 , NULL , 'h' } ,
{ L_65 , V_22 , NULL , 'v' } ,
{ 0 , 0 , 0 , 0 }
} ;
T_6 V_23 = FALSE ;
char * V_24 , * V_25 ;
char * V_26 , * V_27 ;
int V_28 , V_29 ;
int V_30 , V_31 ;
int V_32 , V_33 ;
int V_34 , V_35 ;
int V_36 ;
volatile int V_37 = 0 ;
T_6 V_38 = FALSE ;
T_2 * volatile V_39 = NULL ;
T_2 * V_40 = NULL ;
T_2 * V_41 = NULL ;
T_7 * V_42 = NULL ;
T_7 * V_43 = NULL ;
T_2 * V_44 ;
T_8 * V_45 ;
int V_46 ;
T_2 * V_47 = NULL ;
#define F_14 "+2C:d:e:E:hK:lo:O:qQr:R:S:t:T:u:vVxX:Y:z:"
static const char V_48 [] = F_14 ;
setlocale ( V_49 , L_66 ) ;
F_15 ( V_50 , V_51 ) ;
#ifdef F_16
F_17 ( V_14 , V_15 ) ;
F_18 () ;
#if ! F_19 ( 2 , 31 , 0 )
F_20 ( NULL ) ;
#endif
#endif
F_21 () ;
F_22 () ;
F_6 () ;
V_18 = F_23 ( V_15 [ 0 ] , main ) ;
if ( V_18 != NULL ) {
fprintf ( V_12 , L_67 ,
V_18 ) ;
}
F_24 () ;
V_16 = F_25 ( NULL , V_52 ) ;
V_17 = F_26 ( F_12 ) ;
F_27 ( L_47
L_1
L_68
L_1
L_68 ,
F_3 () , V_16 -> V_13 , V_17 -> V_13 ) ;
V_53 = 0 ;
while ( ( V_19 = F_28 ( V_14 , V_15 , V_48 , V_21 , NULL ) ) != - 1 ) {
switch ( V_19 ) {
case 'C' :
if ( F_29 ( V_54 , FALSE ) ) {
F_30 ( V_54 ) ;
} else {
F_31 ( L_69 , V_54 ) ;
return 1 ;
}
break;
case 'O' :
V_47 = F_32 ( V_54 ) ;
case 'V' :
V_55 = TRUE ;
V_56 = TRUE ;
break;
case 'x' :
V_57 = TRUE ;
V_56 = TRUE ;
break;
case 'X' :
F_33 ( V_54 ) ;
break;
default:
break;
}
}
if ( V_58 == - 1 )
V_58 = ( V_55 || V_57 ) ? FALSE : TRUE ;
V_46 =
V_59 |
V_60 |
V_61 |
V_62 |
V_63 |
V_64 |
V_65 | V_66 ;
F_34 ( NULL ,
( T_3 ) V_46 ,
F_4 , NULL ) ;
F_34 ( V_67 ,
( T_3 ) V_46 ,
F_4 , NULL ) ;
F_35 ( V_50 , V_68 , V_69 ,
V_70 ) ;
F_36 ( V_71 ) ;
F_37 ( V_72 ) ;
F_38 ( V_73 ) ;
F_39 () ;
#ifdef F_40
F_41 () ;
F_42 () ;
#endif
if ( ! F_43 ( V_74 , V_75 , NULL ,
NULL ) )
return 2 ;
if ( V_14 >= 2 && strcmp ( V_15 [ 1 ] , L_70 ) == 0 ) {
F_44 () ;
if ( V_14 == 2 )
F_45 () ;
else {
if ( strcmp ( V_15 [ 2 ] , L_71 ) == 0 )
F_46 () ;
else if ( strcmp ( V_15 [ 2 ] , L_72 ) == 0 ) {
F_47 ( & V_28 , & V_29 , & V_24 ,
& V_30 , & V_31 , & V_25 ) ;
F_48 ( NULL ) ;
}
else if ( strcmp ( V_15 [ 2 ] , L_73 ) == 0 )
F_49 () ;
else if ( strcmp ( V_15 [ 2 ] , L_74 ) == 0 )
F_48 ( NULL ) ;
else if ( strcmp ( V_15 [ 2 ] , L_75 ) == 0 )
F_50 () ;
else if ( strcmp ( V_15 [ 2 ] , L_76 ) == 0 )
F_45 () ;
else if ( strcmp ( V_15 [ 2 ] , L_77 ) == 0 )
F_51 () ;
else if ( strcmp ( V_15 [ 2 ] , L_78 ) == 0 )
F_52 () ;
else if ( strcmp ( V_15 [ 2 ] , L_79 ) == 0 ) {
#ifdef F_40
F_53 () ;
#endif
#ifdef F_54
F_55 () ;
#endif
}
else if ( strcmp ( V_15 [ 2 ] , L_80 ) == 0 )
F_56 () ;
else if ( strcmp ( V_15 [ 2 ] , L_81 ) == 0 )
F_57 () ;
else if ( strcmp ( V_15 [ 2 ] , L_82 ) == 0 )
F_2 () ;
else if ( strcmp ( V_15 [ 2 ] , L_83 ) == 0 )
F_2 () ;
else {
F_31 ( L_84 , V_15 [ 2 ] ) ;
return 1 ;
}
}
return 0 ;
}
V_45 = F_47 ( & V_28 , & V_29 , & V_24 ,
& V_30 , & V_31 , & V_25 ) ;
if ( V_24 != NULL ) {
if ( V_28 != 0 ) {
F_31 ( L_85 ,
V_25 , F_58 ( V_28 ) ) ;
}
if ( V_29 != 0 ) {
F_31 ( L_86 ,
V_25 , F_58 ( V_29 ) ) ;
}
}
if ( V_25 != NULL ) {
if ( V_30 != 0 ) {
F_31 ( L_87 , V_25 ,
F_58 ( V_30 ) ) ;
}
if ( V_31 != 0 ) {
F_31 ( L_88 ,
V_25 , F_58 ( V_31 ) ) ;
}
F_10 ( V_25 ) ;
V_25 = NULL ;
}
F_59 ( & V_26 , & V_32 , & V_33 ,
& V_27 , & V_34 , & V_35 ) ;
F_60 ( & V_26 , & V_32 , & V_33 ,
& V_27 , & V_34 , & V_35 ) ;
if ( V_26 != NULL ) {
if ( V_32 != 0 ) {
F_31 ( L_89 ,
V_26 , F_58 ( V_32 ) ) ;
}
if ( V_33 != 0 ) {
F_31 ( L_90 ,
V_26 , F_58 ( V_33 ) ) ;
}
F_10 ( V_26 ) ;
}
if ( V_27 != NULL ) {
if ( V_34 != 0 ) {
F_31 (
L_91 , V_27 ,
F_58 ( V_34 ) ) ;
}
if ( V_35 != 0 ) {
F_31 (
L_92 , V_27 ,
F_58 ( V_35 ) ) ;
}
F_10 ( V_27 ) ;
}
F_61 ( & V_76 ) ;
V_77 = V_78 ;
V_79 = F_62 () ;
#ifdef F_63
V_80 = 1 ;
V_81 = 1 ;
#else
V_81 = 0 ;
#endif
V_53 = 1 ;
while ( ( V_19 = F_28 ( V_14 , V_15 , V_48 , V_21 , NULL ) ) != - 1 ) {
switch ( V_19 ) {
case '2' :
V_82 = TRUE ;
break;
case 'C' :
break;
case 'd' :
if ( ! F_64 ( V_54 ) )
return 1 ;
break;
#if F_65 ( V_83 ) || F_65 ( V_84 )
case 'K' :
F_66 ( V_54 ) ;
break;
#endif
case 'e' :
F_67 ( V_79 , V_54 ) ;
break;
case 'E' :
if ( ! F_68 ( V_79 , V_54 ) ) {
F_31 ( L_93 , V_54 ) ;
F_69 ( V_12 ) ;
return 1 ;
}
break;
case 'h' :
printf ( L_47
L_94
L_95 ,
F_3 () ) ;
F_1 ( stdout ) ;
return 0 ;
break;
case 'l' :
V_85 = TRUE ;
break;
case 'o' :
switch ( F_70 ( V_54 ) ) {
case V_86 :
break;
case V_87 :
F_31 ( L_96 , V_54 ) ;
return 1 ;
break;
case V_88 :
case V_89 :
F_31 ( L_97 , V_54 ) ;
return 1 ;
break;
}
break;
case 'q' :
V_38 = TRUE ;
break;
case 'Q' :
V_38 = TRUE ;
V_90 = TRUE ;
break;
case 'r' :
V_39 = F_32 ( V_54 ) ;
break;
case 'R' :
V_40 = V_54 ;
break;
case 'S' :
V_91 = F_32 ( V_54 ) ;
break;
case 't' :
if ( strcmp ( V_54 , L_98 ) == 0 )
F_36 ( V_71 ) ;
else if ( strcmp ( V_54 , L_99 ) == 0 )
F_36 ( V_92 ) ;
else if ( strcmp ( V_54 , L_100 ) == 0 )
F_36 ( V_93 ) ;
else if ( strcmp ( V_54 , L_101 ) == 0 )
F_36 ( V_94 ) ;
else if ( strcmp ( V_54 , L_102 ) == 0 )
F_36 ( V_95 ) ;
else if ( strcmp ( V_54 , L_103 ) == 0 )
F_36 ( V_96 ) ;
else if ( strcmp ( V_54 , L_104 ) == 0 )
F_36 ( V_97 ) ;
else if ( strcmp ( V_54 , L_105 ) == 0 )
F_36 ( V_98 ) ;
else if ( strcmp ( V_54 , L_106 ) == 0 )
F_36 ( V_99 ) ;
else if ( strcmp ( V_54 , L_107 ) == 0 )
F_36 ( V_100 ) ;
else {
F_31 ( L_108 , V_54 ) ;
F_71 ( L_109
L_110
L_111
L_112
L_113
L_114
L_115
L_116
L_117
L_118 ) ;
return 1 ;
}
break;
case 'T' :
if ( strcmp ( V_54 , L_119 ) == 0 ) {
V_101 = V_102 ;
V_77 = V_78 ;
} else if ( strcmp ( V_54 , L_120 ) == 0 ) {
V_101 = V_102 ;
V_77 = V_103 ;
} else if ( strcmp ( V_54 , L_121 ) == 0 ) {
V_101 = V_104 ;
V_55 = TRUE ;
V_58 = FALSE ;
} else if ( strcmp ( V_54 , L_122 ) == 0 ) {
V_101 = V_104 ;
V_55 = FALSE ;
V_58 = TRUE ;
} else if ( strcmp ( V_54 , L_76 ) == 0 ) {
V_101 = V_105 ;
V_55 = TRUE ;
V_58 = FALSE ;
} else {
F_31 ( L_123 , V_54 ) ;
F_71 ( L_124
L_125
L_126
L_127
L_128
L_129
L_130
L_131
L_132
L_133
L_134
L_135
L_136
L_137
L_138
L_139 ) ;
return 1 ;
}
break;
case 'u' :
if ( strcmp ( V_54 , L_140 ) == 0 )
F_38 ( V_73 ) ;
else if ( strcmp ( V_54 , L_141 ) == 0 )
F_38 ( V_106 ) ;
else {
F_31 ( L_142 , V_54 ) ;
F_71 ( L_143
L_144 ) ;
return 1 ;
}
break;
case 'v' :
{
F_72 ( L_145 , V_16 , V_17 ) ;
F_73 ( V_16 , TRUE ) ;
F_73 ( V_17 , TRUE ) ;
#ifdef F_74
F_75 () ;
#endif
F_76 () ;
return 0 ;
}
case 'O' :
break;
case 'V' :
break;
case 'x' :
break;
case 'X' :
break;
case 'Y' :
V_41 = V_54 ;
break;
case 'z' :
if ( strcmp ( L_64 , V_54 ) == 0 ) {
fprintf ( V_12 , L_146 ) ;
F_77 () ;
return 0 ;
}
if ( ! F_78 ( V_54 ) ) {
F_31 ( L_147 , V_54 ) ;
F_77 () ;
return 1 ;
}
break;
default:
case '?' :
F_1 ( V_12 ) ;
return 1 ;
break;
}
}
if ( V_105 != V_101 && 0 != F_79 ( V_79 ) ) {
F_31 ( L_148
L_149 ) ;
return 1 ;
} else if ( V_105 == V_101 && 0 == F_79 ( V_79 ) ) {
F_31 ( L_150
L_151 ) ;
return 1 ;
}
if ( V_81 < V_14 ) {
if ( V_39 != NULL ) {
if ( V_41 != NULL ) {
F_31 ( L_152
L_153 ) ;
return 1 ;
}
V_41 = F_80 ( V_14 , V_15 , V_81 ) ;
}
}
if ( ! V_38 )
V_56 = TRUE ;
if ( V_23 ) {
F_1 ( V_12 ) ;
return 1 ;
}
if ( V_57 ) {
if ( V_101 != V_102 ) {
F_31 ( L_154 ) ;
return 1 ;
}
}
if ( V_47 != NULL ) {
char * V_107 ;
if ( ! V_55 ) {
F_31 ( L_155 ) ;
return 1 ;
}
V_108 = F_81 ( V_109 , V_110 ) ;
for ( V_107 = strtok ( V_47 , L_156 ) ; V_107 ; V_107 = strtok ( NULL , L_156 ) ) {
F_82 ( V_108 , ( T_4 ) V_107 , ( T_4 ) V_107 ) ;
}
}
if ( V_40 != NULL && ! V_82 ) {
F_31 ( L_157 ) ;
return 1 ;
}
F_83 () ;
F_84 () ;
if ( V_26 == NULL && V_27 == NULL ) {
F_85 () ;
F_86 () ;
}
F_87 ( & V_76 . V_111 , V_45 -> V_112 , TRUE ) ;
if ( V_40 != NULL ) {
if ( ! F_88 ( V_40 , & V_42 , & V_44 ) ) {
F_31 ( L_68 , V_44 ) ;
F_10 ( V_44 ) ;
#ifdef F_74
F_75 () ;
#endif
F_76 () ;
return 2 ;
}
}
V_76 . V_42 = V_42 ;
if ( V_41 != NULL ) {
if ( ! F_88 ( V_41 , & V_43 , & V_44 ) ) {
F_31 ( L_68 , V_44 ) ;
F_10 ( V_44 ) ;
#ifdef F_74
F_75 () ;
#endif
F_76 () ;
return 2 ;
}
}
V_76 . V_43 = V_43 ;
if ( V_56 ) {
if ( V_101 == V_102 ) {
switch ( V_77 ) {
case V_78 :
V_113 = F_89 ( stdout ) ;
break;
case V_103 :
V_113 = F_90 ( stdout ) ;
break;
default:
F_91 () ;
}
}
}
V_114 = V_56 || V_42 || V_43 || F_92 () ;
if ( V_39 ) {
if ( F_93 ( & V_76 , V_39 , V_115 , FALSE , & V_36 ) != V_116 ) {
#ifdef F_74
F_75 () ;
#endif
F_76 () ;
return 2 ;
}
F_94 {
V_36 = F_95 ( & V_76 , 1 , 0 ) ;
}
F_96 (OutOfMemoryError) {
fprintf ( V_12 ,
L_158
L_1
L_159
L_1
L_160
L_161 ) ;
V_36 = V_117 ;
}
V_118 ;
if ( V_36 != 0 ) {
V_37 = 2 ;
}
}
F_10 ( V_39 ) ;
if ( V_76 . V_119 != NULL ) {
F_97 ( V_76 . V_119 ) ;
V_76 . V_119 = NULL ;
}
F_98 ( TRUE ) ;
F_99 () ;
F_100 ( V_76 . V_120 ) ;
#ifdef F_74
F_75 () ;
#endif
F_76 () ;
F_101 ( V_79 ) ;
V_79 = NULL ;
return V_37 ;
}
static const T_9 *
F_102 ( void * V_121 , T_10 V_122 )
{
T_11 * V_123 = ( T_11 * ) V_121 ;
if ( V_124 && V_124 -> V_125 == V_122 )
return & V_124 -> V_126 ;
if ( V_127 && V_127 -> V_125 == V_122 )
return & V_127 -> V_126 ;
if ( V_128 && V_128 -> V_125 == V_122 )
return & V_128 -> V_126 ;
if ( V_123 -> V_119 ) {
T_12 * V_129 = F_103 ( V_123 -> V_119 , V_122 ) ;
return ( V_129 ) ? & V_129 -> V_126 : NULL ;
}
return NULL ;
}
static const char *
F_104 ( void * V_121 V_130 , T_10 T_13 V_130 )
{
return L_66 ;
}
static T_14 *
F_105 ( T_11 * V_123 )
{
T_14 * V_120 = F_106 () ;
V_120 -> V_121 = V_123 ;
V_120 -> V_131 = F_102 ;
V_120 -> V_132 = F_104 ;
V_120 -> V_133 = NULL ;
return V_120 ;
}
static T_6
F_107 ( T_11 * V_123 , T_15 * V_134 ,
T_16 V_135 , struct V_136 * V_137 ,
const T_17 * V_138 )
{
T_12 V_139 ;
T_10 V_140 ;
T_6 V_141 ;
V_140 = V_123 -> V_142 + 1 ;
V_141 = TRUE ;
F_108 ( & V_139 , V_140 , V_137 , V_135 , V_143 ) ;
if ( V_134 ) {
if ( V_123 -> V_42 )
F_109 ( V_134 , V_123 -> V_42 ) ;
F_110 ( & V_139 , & V_123 -> V_144 ,
& V_124 , V_127 ) ;
if ( V_124 == & V_139 ) {
V_145 = V_139 ;
V_124 = & V_145 ;
}
F_111 ( V_134 , V_137 , F_112 ( & V_139 , V_138 ) , & V_139 , NULL ) ;
if ( V_123 -> V_42 )
V_141 = F_113 ( V_123 -> V_42 , V_134 ) ;
}
if ( V_141 ) {
F_114 ( & V_139 , & V_143 ) ;
V_128 = V_127 = F_115 ( V_123 -> V_119 , & V_139 ) ;
if ( V_134 ) {
F_116 ( V_134 -> V_146 . V_147 , V_148 , V_123 -> V_119 ) ;
}
V_123 -> V_142 ++ ;
} else {
F_117 ( & V_139 ) ;
}
if ( V_134 )
F_118 ( V_134 ) ;
return V_141 ;
}
static T_6
F_119 ( T_11 * V_123 , T_15 * V_134 , T_12 * V_149 ,
struct V_136 * V_150 , T_18 * V_151 ,
T_19 V_152 )
{
T_20 * V_111 ;
T_6 V_141 ;
V_141 = TRUE ;
if ( V_134 ) {
if ( V_123 -> V_43 )
F_109 ( V_134 , V_123 -> V_43 ) ;
F_120 ( V_134 , & V_123 -> V_111 ) ;
if ( ( V_152 & V_153 ) || ( V_56 && V_58 ) )
V_111 = & V_123 -> V_111 ;
else
V_111 = NULL ;
F_110 ( V_149 , & V_123 -> V_144 ,
& V_124 , V_127 ) ;
if ( V_124 == V_149 ) {
V_145 = * V_149 ;
V_124 = & V_145 ;
}
F_121 ( V_134 , V_150 , F_122 ( V_149 , V_151 ) , V_149 , V_111 ) ;
if ( V_123 -> V_43 )
V_141 = F_113 ( V_123 -> V_43 , V_134 ) ;
}
if ( V_141 ) {
F_114 ( V_149 , & V_143 ) ;
if ( V_56 ) {
F_123 ( V_123 , V_134 ) ;
if ( V_85 )
fflush ( stdout ) ;
if ( ferror ( stdout ) ) {
F_124 ( V_154 ) ;
exit ( 2 ) ;
}
}
V_127 = V_149 ;
}
V_128 = V_149 ;
if ( V_134 ) {
F_118 ( V_134 ) ;
}
return V_141 || V_149 -> V_155 . V_156 ;
}
static T_6
F_125 ( T_11 * V_123 , struct V_136 * T_21 V_130 , int * V_36 , T_2 * * T_22 V_130 , T_16 * T_23 V_130 , T_24 * * V_157 )
{
T_16 V_158 = F_126 ( V_123 -> V_159 , V_36 ) ;
* V_157 = ( T_24 * ) F_127 ( ( V_160 ) V_158 ) ;
F_128 ( * V_157 , ( unsigned int ) V_158 , V_123 -> V_159 -> V_161 ) ;
#if 0
if (bytes_read < 0) {
*err = file_error(cf->wth->fh, err_info);
if (*err == 0)
*err = FTAP_ERR_SHORT_READ;
return FALSE;
} else if (bytes_read == 0) {
return FALSE;
}
file_phdr->caplen = (guint32)packet_size;
file_phdr->len = (guint32)packet_size;
wth->phdr.pkt_encap = wth->file_encap;
if (!wth->subtype_read(wth, err, err_info, data_offset)) {
if (*err == 0)
*err = file_error(wth->fh, err_info);
return FALSE;
}
if (wth->phdr.caplen > wth->phdr.len)
wth->phdr.caplen = wth->phdr.len;
g_assert(wth->phdr.pkt_encap != WTAP_ENCAP_PER_PACKET);
#endif
return TRUE ;
}
static int
F_95 ( T_11 * V_123 , int V_162 , T_16 V_163 )
{
T_10 V_140 ;
int V_36 ;
T_2 * T_22 = NULL ;
T_16 T_23 = 0 ;
T_6 V_164 ;
T_19 V_152 ;
T_18 V_151 ;
T_15 * V_134 = NULL ;
struct V_136 T_21 ;
T_24 * V_165 ;
if ( V_56 ) {
if ( ! F_129 ( V_123 ) ) {
V_36 = V_154 ;
F_124 ( V_36 ) ;
goto V_166;
}
}
V_164 = F_130 () ;
V_152 = F_131 () ;
F_132 ( & T_21 ) ;
T_21 . V_167 = 1234 ;
if ( V_82 ) {
T_12 * V_149 ;
V_123 -> V_119 = F_133 () ;
if ( V_114 ) {
T_6 V_168 = FALSE ;
if ( V_123 -> V_42 )
V_168 = TRUE ;
V_134 = F_134 ( V_123 -> V_120 , V_168 , FALSE ) ;
}
while ( F_125 ( V_123 , & T_21 , & V_36 , & T_22 , & T_23 , & V_165 ) ) {
if ( F_107 ( V_123 , V_134 , T_23 , & T_21 ,
F_135 ( V_123 -> V_159 ) ) ) {
if ( ( -- V_162 == 0 ) || ( V_163 != 0 && T_23 >= V_163 ) ) {
V_36 = 0 ;
break;
}
}
}
if ( V_134 ) {
F_136 ( V_134 ) ;
V_134 = NULL ;
}
#if 0
wtap_sequential_close(cf->wth);
#endif
F_137 () ;
V_127 = NULL ;
V_128 = NULL ;
F_138 ( & V_151 , 1500 ) ;
if ( V_114 ) {
T_6 V_168 ;
if ( V_123 -> V_43 || V_55 || V_164 ||
( V_152 & V_169 ) || F_139 ( & V_123 -> V_111 ) )
V_168 = TRUE ;
else
V_168 = FALSE ;
V_134 = F_134 ( V_123 -> V_120 , V_168 , V_56 && V_55 ) ;
}
for ( V_140 = 1 ; V_36 == 0 && V_140 <= V_123 -> V_142 ; V_140 ++ ) {
V_149 = F_103 ( V_123 -> V_119 , V_140 ) ;
#if 0
if (wtap_seek_read(cf->wth, fdata->file_off,
&buf, fdata->cap_len, &err, &err_info)) {
process_packet_second_pass(cf, edt, fdata, &cf->phdr, &buf, tap_flags);
}
#else
F_119 ( V_123 , V_134 , V_149 , & V_123 -> V_150 , & V_151 , V_152 ) ;
#endif
}
if ( V_134 ) {
F_136 ( V_134 ) ;
V_134 = NULL ;
}
F_140 ( & V_151 ) ;
}
else {
V_140 = 0 ;
if ( V_114 ) {
T_6 V_168 ;
if ( V_123 -> V_42 || V_123 -> V_43 || V_55 || V_164 ||
( V_152 & V_169 ) || F_139 ( & V_123 -> V_111 ) )
V_168 = TRUE ;
else
V_168 = FALSE ;
V_134 = F_134 ( V_123 -> V_120 , V_168 , V_56 && V_55 ) ;
}
while ( F_125 ( V_123 , & T_21 , & V_36 , & T_22 , & T_23 , & V_165 ) ) {
V_140 ++ ;
F_141 ( V_123 , V_134 , T_23 , & T_21 ,
V_165 , V_152 ) ;
if ( ( -- V_162 == 0 ) || ( V_163 != 0 && T_23 >= V_163 ) ) {
V_36 = 0 ;
break;
}
}
if ( V_134 ) {
F_136 ( V_134 ) ;
V_134 = NULL ;
}
}
F_142 ( & T_21 ) ;
if ( V_36 != 0 ) {
#ifndef F_16
if ( V_56 ) {
T_25 V_170 , V_171 ;
if ( F_143 ( 1 , & V_170 ) == 0 && F_143 ( 2 , & V_171 ) == 0 ) {
if ( V_170 . V_172 == V_171 . V_172 &&
V_170 . V_173 == V_171 . V_173 ) {
fflush ( stdout ) ;
fprintf ( V_12 , L_1 ) ;
}
}
}
#endif
#if 0
switch (err) {
case FTAP_ERR_UNSUPPORTED:
cmdarg_err("The file \"%s\" contains record data that TFShark doesn't support.\n(%s)",
cf->filename, err_info);
g_free(err_info);
break;
case FTAP_ERR_UNSUPPORTED_ENCAP:
cmdarg_err("The file \"%s\" has a packet with a network type that TFShark doesn't support.\n(%s)",
cf->filename, err_info);
g_free(err_info);
break;
case FTAP_ERR_CANT_READ:
cmdarg_err("An attempt to read from the file \"%s\" failed for some unknown reason.",
cf->filename);
break;
case FTAP_ERR_SHORT_READ:
cmdarg_err("The file \"%s\" appears to have been cut short in the middle of a packet.",
cf->filename);
break;
case FTAP_ERR_BAD_FILE:
cmdarg_err("The file \"%s\" appears to be damaged or corrupt.\n(%s)",
cf->filename, err_info);
g_free(err_info);
break;
case FTAP_ERR_DECOMPRESS:
cmdarg_err("The compressed file \"%s\" appears to be damaged or corrupt.\n"
"(%s)", cf->filename, err_info);
break;
default:
cmdarg_err("An error occurred while reading the file \"%s\": %s.",
cf->filename, ftap_strerror(err));
break;
}
#endif
} else {
if ( V_56 ) {
if ( ! F_144 () ) {
V_36 = V_154 ;
F_124 ( V_36 ) ;
}
}
}
V_166:
F_145 ( V_123 -> V_159 ) ;
V_123 -> V_159 = NULL ;
return V_36 ;
}
static T_6
F_141 ( T_11 * V_123 , T_15 * V_134 , T_16 V_135 ,
struct V_136 * V_137 , const T_17 * V_138 , T_19 V_152 )
{
T_12 V_149 ;
T_20 * V_111 ;
T_6 V_141 ;
V_123 -> V_142 ++ ;
V_141 = TRUE ;
F_108 ( & V_149 , V_123 -> V_142 , V_137 , V_135 , V_143 ) ;
if ( V_134 ) {
if ( V_123 -> V_43 )
F_109 ( V_134 , V_123 -> V_43 ) ;
F_120 ( V_134 , & V_123 -> V_111 ) ;
if ( ( V_152 & V_153 ) || ( V_56 && V_58 ) || F_146 ( V_79 ) )
V_111 = & V_123 -> V_111 ;
else
V_111 = NULL ;
F_110 ( & V_149 , & V_123 -> V_144 ,
& V_124 , V_127 ) ;
if ( V_124 == & V_149 ) {
V_145 = V_149 ;
V_124 = & V_145 ;
}
F_121 ( V_134 , V_137 , F_147 ( & V_149 , V_138 ) , & V_149 , V_111 ) ;
if ( V_123 -> V_43 )
V_141 = F_113 ( V_123 -> V_43 , V_134 ) ;
}
if ( V_141 ) {
F_114 ( & V_149 , & V_143 ) ;
if ( V_56 ) {
F_123 ( V_123 , V_134 ) ;
if ( V_85 )
fflush ( stdout ) ;
if ( ferror ( stdout ) ) {
F_124 ( V_154 ) ;
exit ( 2 ) ;
}
}
V_174 = V_149 ;
V_127 = & V_174 ;
}
V_175 = V_149 ;
V_128 = & V_175 ;
if ( V_134 ) {
F_118 ( V_134 ) ;
F_117 ( & V_149 ) ;
}
return V_141 ;
}
static T_6
F_129 ( T_11 * V_123 )
{
switch ( V_101 ) {
case V_102 :
return F_148 ( V_113 , V_123 -> V_176 , F_3 () ) ;
case V_104 :
if ( V_55 )
F_149 ( stdout , V_123 -> V_176 ) ;
else
F_150 ( & V_123 -> V_111 , stdout ) ;
return ! ferror ( stdout ) ;
case V_105 :
F_151 ( V_79 , stdout ) ;
return ! ferror ( stdout ) ;
default:
F_91 () ;
return FALSE ;
}
}
static char *
F_152 ( T_26 V_177 )
{
static char * V_178 = NULL ;
static T_26 V_179 = 256 ;
T_26 V_180 ;
for ( V_180 = V_179 ; V_177 > V_180 ;
V_180 *= 2 )
;
if ( V_178 == NULL ) {
V_179 = V_180 ;
V_178 = ( char * ) F_127 ( V_179 + 1 ) ;
} else {
if ( V_180 > V_179 ) {
V_179 = V_180 ;
V_178 = ( char * ) F_153 ( V_178 , V_179 + 1 ) ;
}
}
return V_178 ;
}
static inline void
F_154 ( char * V_181 , const char * V_13 , T_26 V_182 )
{
memcpy ( V_181 , V_13 , V_182 ) ;
V_181 [ V_182 ] = '\0' ;
}
static inline void
F_155 ( char * V_181 , const char * V_13 , T_26 V_182 , T_26 V_183 )
{
T_26 V_184 ;
for ( V_184 = V_182 ; V_184 < V_183 ; V_184 ++ )
* V_181 ++ = ' ' ;
F_154 ( V_181 , V_13 , V_182 ) ;
}
static inline void
F_156 ( char * V_181 , const char * V_13 , T_26 V_182 , T_26 V_183 )
{
T_26 V_184 ;
memcpy ( V_181 , V_13 , V_182 ) ;
for ( V_184 = V_182 ; V_184 < V_183 ; V_184 ++ )
V_181 [ V_184 ] = ' ' ;
V_181 [ V_183 ] = '\0' ;
}
static T_6
F_157 ( T_11 * V_123 )
{
char * V_178 ;
int V_184 ;
T_26 V_185 ;
T_26 V_186 ;
T_26 V_187 ;
T_27 * V_188 ;
V_178 = F_152 ( 256 ) ;
V_185 = 0 ;
* V_178 = '\0' ;
for ( V_184 = 0 ; V_184 < V_123 -> V_111 . V_112 ; V_184 ++ ) {
V_188 = & V_123 -> V_111 . V_189 [ V_184 ] ;
if ( ! F_158 ( V_184 ) )
continue;
switch ( V_188 -> V_190 ) {
case V_191 :
V_186 = V_187 = strlen ( V_188 -> V_192 ) ;
if ( V_186 < 3 )
V_186 = 3 ;
V_178 = F_152 ( V_185 + V_186 ) ;
F_155 ( V_178 + V_185 , V_188 -> V_192 , V_187 , V_186 ) ;
break;
case V_193 :
case V_194 :
case V_195 :
case V_196 :
case V_197 :
case V_198 :
case V_199 :
case V_200 :
V_186 = V_187 = strlen ( V_188 -> V_192 ) ;
if ( V_186 < 10 )
V_186 = 10 ;
V_178 = F_152 ( V_185 + V_186 ) ;
F_155 ( V_178 + V_185 , V_188 -> V_192 , V_187 , V_186 ) ;
break;
case V_201 :
case V_202 :
case V_203 :
case V_204 :
case V_205 :
case V_206 :
case V_207 :
case V_208 :
case V_209 :
V_186 = V_187 = strlen ( V_188 -> V_192 ) ;
if ( V_186 < 12 )
V_186 = 12 ;
V_178 = F_152 ( V_185 + V_186 ) ;
F_155 ( V_178 + V_185 , V_188 -> V_192 , V_187 , V_186 ) ;
break;
case V_210 :
case V_211 :
case V_212 :
case V_213 :
case V_214 :
case V_215 :
case V_216 :
case V_217 :
case V_218 :
V_186 = V_187 = strlen ( V_188 -> V_192 ) ;
if ( V_186 < 12 )
V_186 = 12 ;
V_178 = F_152 ( V_185 + V_186 ) ;
F_156 ( V_178 + V_185 , V_188 -> V_192 , V_187 , V_186 ) ;
break;
default:
V_186 = strlen ( V_188 -> V_192 ) ;
V_178 = F_152 ( V_185 + V_186 ) ;
F_154 ( V_178 + V_185 , V_188 -> V_192 , V_186 ) ;
break;
}
V_185 += V_186 ;
if ( V_184 != V_123 -> V_111 . V_112 - 1 ) {
V_178 = F_152 ( V_185 + 4 ) ;
switch ( V_188 -> V_190 ) {
case V_201 :
case V_202 :
case V_203 :
switch ( V_123 -> V_111 . V_189 [ V_184 + 1 ] . V_190 ) {
case V_210 :
case V_211 :
case V_212 :
F_154 ( V_178 + V_185 , L_162 , 4 ) ;
V_185 += 4 ;
break;
default:
F_154 ( V_178 + V_185 , L_163 , 1 ) ;
V_185 += 1 ;
break;
}
break;
case V_204 :
case V_205 :
case V_206 :
switch ( V_123 -> V_111 . V_189 [ V_184 + 1 ] . V_190 ) {
case V_213 :
case V_214 :
case V_215 :
F_154 ( V_178 + V_185 , L_162 , 4 ) ;
V_185 += 4 ;
break;
default:
F_154 ( V_178 + V_185 , L_163 , 1 ) ;
V_185 += 1 ;
break;
}
break;
case V_207 :
case V_208 :
case V_209 :
switch ( V_123 -> V_111 . V_189 [ V_184 + 1 ] . V_190 ) {
case V_216 :
case V_217 :
case V_218 :
F_154 ( V_178 + V_185 , L_162 , 4 ) ;
V_185 += 4 ;
break;
default:
F_154 ( V_178 + V_185 , L_163 , 1 ) ;
V_185 += 1 ;
break;
}
break;
case V_210 :
case V_211 :
case V_212 :
switch ( V_123 -> V_111 . V_189 [ V_184 + 1 ] . V_190 ) {
case V_201 :
case V_202 :
case V_203 :
F_154 ( V_178 + V_185 , L_164 , 4 ) ;
V_185 += 4 ;
break;
default:
F_154 ( V_178 + V_185 , L_163 , 1 ) ;
V_185 += 1 ;
break;
}
break;
case V_213 :
case V_214 :
case V_215 :
switch ( V_123 -> V_111 . V_189 [ V_184 + 1 ] . V_190 ) {
case V_204 :
case V_205 :
case V_206 :
F_154 ( V_178 + V_185 , L_164 , 4 ) ;
V_185 += 4 ;
break;
default:
F_154 ( V_178 + V_185 , L_163 , 1 ) ;
V_185 += 1 ;
break;
}
break;
case V_216 :
case V_217 :
case V_218 :
switch ( V_123 -> V_111 . V_189 [ V_184 + 1 ] . V_190 ) {
case V_207 :
case V_208 :
case V_209 :
F_154 ( V_178 + V_185 , L_164 , 4 ) ;
V_185 += 4 ;
break;
default:
F_154 ( V_178 + V_185 , L_163 , 1 ) ;
V_185 += 1 ;
break;
}
break;
default:
F_154 ( V_178 + V_185 , L_163 , 1 ) ;
V_185 += 1 ;
break;
}
}
}
return F_159 ( V_113 , 0 , V_178 ) ;
}
static T_6
F_123 ( T_11 * V_123 , T_15 * V_134 )
{
T_28 V_219 ;
if ( V_58 || F_146 ( V_79 ) ) {
F_160 ( V_134 , FALSE , TRUE ) ;
if ( V_58 ) {
switch ( V_101 ) {
case V_102 :
if ( ! F_157 ( V_123 ) )
return FALSE ;
break;
case V_104 :
F_161 ( V_134 , stdout ) ;
return ! ferror ( stdout ) ;
case V_105 :
F_91 () ;
break;
}
}
}
if ( V_55 ) {
switch ( V_101 ) {
case V_102 :
V_219 . V_57 = V_57 ;
V_219 . V_220 = V_55 ? V_221 : V_222 ;
if ( ! F_162 ( & V_219 , V_134 , V_108 , V_113 ) )
return FALSE ;
if ( ! V_57 ) {
if ( ! F_159 ( V_113 , 0 , V_91 ) )
return FALSE ;
}
break;
case V_104 :
F_163 ( NULL , NULL , V_134 , stdout ) ;
printf ( L_1 ) ;
return ! ferror ( stdout ) ;
case V_105 :
F_164 ( V_79 , V_134 , & V_123 -> V_111 , stdout ) ;
printf ( L_1 ) ;
return ! ferror ( stdout ) ;
}
}
if ( V_57 ) {
if ( V_58 || V_55 ) {
if ( ! F_159 ( V_113 , 0 , L_66 ) )
return FALSE ;
}
if ( ! F_165 ( V_113 , V_134 ) )
return FALSE ;
if ( ! F_159 ( V_113 , 0 , V_91 ) )
return FALSE ;
}
return TRUE ;
}
static T_6
F_144 ( void )
{
switch ( V_101 ) {
case V_102 :
return F_166 ( V_113 ) ;
case V_104 :
if ( V_55 )
F_167 ( stdout ) ;
else
F_168 ( stdout ) ;
return ! ferror ( stdout ) ;
case V_105 :
F_169 ( V_79 , stdout ) ;
return ! ferror ( stdout ) ;
default:
F_91 () ;
return FALSE ;
}
}
T_29
F_93 ( T_11 * V_123 , const char * V_223 , unsigned int type , T_6 V_224 , int * V_36 )
{
T_2 * T_22 ;
char V_44 [ 2048 + 1 ] ;
F_100 ( V_123 -> V_120 ) ;
V_123 -> V_120 = F_105 ( V_123 ) ;
V_123 -> V_159 = NULL ;
V_123 -> V_225 = 0 ;
V_123 -> V_176 = F_32 ( V_223 ) ;
V_123 -> V_224 = V_224 ;
V_123 -> V_226 = FALSE ;
V_123 -> V_227 = 0 ;
V_123 -> V_228 = type ;
V_123 -> V_142 = 0 ;
V_123 -> V_229 = FALSE ;
V_123 -> V_230 = 0 ;
V_123 -> V_231 = 0 ;
if ( V_123 -> V_231 == 0 ) {
V_123 -> V_232 = FALSE ;
V_123 -> V_231 = 0 ;
} else
V_123 -> V_232 = TRUE ;
F_170 ( & V_123 -> V_144 ) ;
V_124 = NULL ;
V_127 = NULL ;
V_128 = NULL ;
V_123 -> V_233 = V_234 ;
return V_116 ;
F_171 ( V_44 , sizeof V_44 ,
F_172 ( * V_36 , T_22 , FALSE , V_123 -> V_227 ) , V_223 ) ;
F_31 ( L_68 , V_44 ) ;
return V_235 ;
}
static void
F_124 ( int V_36 )
{
switch ( V_36 ) {
case V_236 :
F_31 ( L_165
L_166 ) ;
break;
#ifdef F_173
case F_173 :
F_31 ( L_167
L_168 ) ;
break;
#endif
default:
F_31 ( L_169 ,
F_58 ( V_36 ) ) ;
break;
}
}
static const char *
F_172 ( int V_36 , T_2 * T_22 V_130 , T_6 V_237 ,
int T_30 V_130 )
{
const char * V_238 ;
#if 0
if (err < 0) {
switch (err) {
case FTAP_ERR_NOT_REGULAR_FILE:
errmsg = "The file \"%s\" is a \"special file\" or socket or other non-regular file.";
break;
case FTAP_ERR_RANDOM_OPEN_PIPE:
errmsg = "The file \"%s\" is a pipe or FIFO; TFShark can't read pipe or FIFO files in two-pass mode.";
break;
case FTAP_ERR_FILE_UNKNOWN_FORMAT:
errmsg = "The file \"%s\" isn't a capture file in a format TFShark understands.";
break;
case FTAP_ERR_UNSUPPORTED:
g_snprintf(errmsg_errno, sizeof(errmsg_errno),
"The file \"%%s\" isn't a capture file in a format TFShark understands.\n"
"(%s)", err_info);
g_free(err_info);
errmsg = errmsg_errno;
break;
case FTAP_ERR_CANT_WRITE_TO_PIPE:
g_snprintf(errmsg_errno, sizeof(errmsg_errno),
"The file \"%%s\" is a pipe, and \"%s\" capture files can't be "
"written to a pipe.", ftap_file_type_subtype_short_string(file_type));
errmsg = errmsg_errno;
break;
case FTAP_ERR_UNSUPPORTED_FILE_TYPE:
errmsg = "TFShark doesn't support writing capture files in that format.";
break;
case FTAP_ERR_UNSUPPORTED_ENCAP:
if (for_writing) {
g_snprintf(errmsg_errno, sizeof(errmsg_errno),
"TFShark can't save this capture as a \"%s\" file.",
ftap_file_type_subtype_short_string(file_type));
} else {
g_snprintf(errmsg_errno, sizeof(errmsg_errno),
"The file \"%%s\" is a capture for a network type that TFShark doesn't support.\n"
"(%s)", err_info);
g_free(err_info);
}
errmsg = errmsg_errno;
break;
case FTAP_ERR_ENCAP_PER_RECORD_UNSUPPORTED:
if (for_writing) {
g_snprintf(errmsg_errno, sizeof(errmsg_errno),
"TFShark can't save this capture as a \"%s\" file.",
ftap_file_type_subtype_short_string(file_type));
errmsg = errmsg_errno;
} else
errmsg = "The file \"%s\" is a capture for a network type that TFShark doesn't support.";
break;
case FTAP_ERR_BAD_FILE:
g_snprintf(errmsg_errno, sizeof(errmsg_errno),
"The file \"%%s\" appears to be damaged or corrupt.\n"
"(%s)", err_info);
g_free(err_info);
errmsg = errmsg_errno;
break;
case FTAP_ERR_CANT_OPEN:
if (for_writing)
errmsg = "The file \"%s\" could not be created for some unknown reason.";
else
errmsg = "The file \"%s\" could not be opened for some unknown reason.";
break;
case FTAP_ERR_SHORT_READ:
errmsg = "The file \"%s\" appears to have been cut short"
" in the middle of a packet or other data.";
break;
case FTAP_ERR_SHORT_WRITE:
errmsg = "A full header couldn't be written to the file \"%s\".";
break;
case FTAP_ERR_COMPRESSION_NOT_SUPPORTED:
errmsg = "This file type cannot be written as a compressed file.";
break;
case FTAP_ERR_DECOMPRESS:
g_snprintf(errmsg_errno, sizeof(errmsg_errno),
"The compressed file \"%%s\" appears to be damaged or corrupt.\n"
"(%s)", err_info);
g_free(err_info);
errmsg = errmsg_errno;
break;
default:
g_snprintf(errmsg_errno, sizeof(errmsg_errno),
"The file \"%%s\" could not be %s: %s.",
for_writing ? "created" : "opened",
ftap_strerror(err));
errmsg = errmsg_errno;
break;
}
} else
#endif
V_238 = F_174 ( V_36 , V_237 ) ;
return V_238 ;
}
static void
V_68 ( const char * V_176 , int V_36 , T_6 V_237 )
{
fprintf ( V_12 , L_170 ) ;
fprintf ( V_12 , F_174 ( V_36 , V_237 ) , V_176 ) ;
fprintf ( V_12 , L_1 ) ;
}
static void
V_50 ( const char * V_239 , T_31 V_240 )
{
fprintf ( V_12 , L_170 ) ;
vfprintf ( V_12 , V_239 , V_240 ) ;
fprintf ( V_12 , L_1 ) ;
}
static void
V_69 ( const char * V_176 , int V_36 )
{
F_31 ( L_171 ,
V_176 , F_58 ( V_36 ) ) ;
}
static void
V_70 ( const char * V_176 , int V_36 )
{
F_31 ( L_172 ,
V_176 , F_58 ( V_36 ) ) ;
}
static void
V_51 ( const char * V_239 , T_31 V_240 )
{
vfprintf ( V_12 , V_239 , V_240 ) ;
fprintf ( V_12 , L_1 ) ;
}
