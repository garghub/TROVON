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
fprintf ( V_1 , L_10 ) ;
fprintf ( V_1 , L_11 , V_2 ) ;
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
fprintf ( V_1 , L_39 ) ;
fprintf ( V_1 , L_1 ) ;
fprintf ( V_1 , L_40 ) ;
fprintf ( V_1 , L_41 ) ;
fprintf ( V_1 , L_42 ) ;
fprintf ( V_1 , L_43 ) ;
fprintf ( V_1 , L_44 ) ;
fprintf ( V_1 , L_45 ) ;
fprintf ( V_1 , L_46 ) ;
fprintf ( V_1 , L_47 ) ;
}
static void
F_2 ( void )
{
T_1 * V_1 ;
V_1 = stdout ;
fprintf ( V_1 , L_48 , F_3 () ) ;
fprintf ( V_1 , L_1 ) ;
fprintf ( V_1 , L_49 ) ;
fprintf ( V_1 , L_1 ) ;
fprintf ( V_1 , L_50 ) ;
fprintf ( V_1 , L_51 ) ;
fprintf ( V_1 , L_52 ) ;
fprintf ( V_1 , L_53 ) ;
fprintf ( V_1 , L_54 ) ;
fprintf ( V_1 , L_55 ) ;
fprintf ( V_1 , L_56 ) ;
fprintf ( V_1 , L_57 ) ;
fprintf ( V_1 , L_58 ) ;
fprintf ( V_1 , L_59 ) ;
fprintf ( V_1 , L_1 ) ;
fprintf ( V_1 , L_60 ) ;
fprintf ( V_1 , L_61 ) ;
fprintf ( V_1 , L_62 ) ;
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
fprintf ( V_12 , L_63 ,
V_10 , V_11 ) ;
F_10 ( V_10 ) ;
F_10 ( V_11 ) ;
if ( F_11 () ) {
fprintf ( V_12 , L_64 ) ;
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
{ L_65 , V_22 , NULL , 'h' } ,
{ L_66 , V_22 , NULL , 'v' } ,
{ 0 , 0 , 0 , 0 }
} ;
T_6 V_23 = FALSE ;
int V_24 ;
volatile T_6 V_25 ;
volatile int V_26 = 0 ;
T_6 V_27 = FALSE ;
T_2 * volatile V_28 = NULL ;
T_2 * V_29 = NULL ;
T_2 * V_30 = NULL ;
T_7 * V_31 = NULL ;
T_7 * V_32 = NULL ;
T_2 * V_33 ;
T_8 * V_34 ;
int V_35 ;
T_2 * V_36 = NULL ;
#define F_14 "+2C:d:e:E:hK:lo:O:qQr:R:S:t:T:u:vVxX:Y:z:"
static const char V_37 [] = F_14 ;
setlocale ( V_38 , L_67 ) ;
F_15 ( V_39 , V_40 ) ;
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
fprintf ( V_12 ,
L_68 ,
V_18 ) ;
F_10 ( V_18 ) ;
}
F_24 () ;
V_16 = F_25 ( NULL , V_41 ) ;
V_17 = F_26 ( F_12 ) ;
F_27 ( L_48
L_1
L_69
L_1
L_69 ,
F_3 () , V_16 -> V_13 , V_17 -> V_13 ) ;
F_28 ( V_16 , TRUE ) ;
F_28 ( V_17 , TRUE ) ;
V_42 = 0 ;
while ( ( V_19 = F_29 ( V_14 , V_15 , V_37 , V_21 , NULL ) ) != - 1 ) {
switch ( V_19 ) {
case 'C' :
if ( F_30 ( V_43 , FALSE ) ) {
F_31 ( V_43 ) ;
} else {
F_32 ( L_70 , V_43 ) ;
return 1 ;
}
break;
case 'O' :
V_36 = F_33 ( V_43 ) ;
case 'V' :
V_44 = TRUE ;
V_45 = TRUE ;
break;
case 'x' :
V_46 = TRUE ;
V_45 = TRUE ;
break;
case 'X' :
F_34 ( V_43 ) ;
break;
default:
break;
}
}
if ( V_47 == - 1 )
V_47 = ( V_44 || V_46 ) ? FALSE : TRUE ;
V_35 =
V_48 |
V_49 |
V_50 |
V_51 |
V_52 |
V_53 |
V_54 | V_55 ;
F_35 ( NULL ,
( T_3 ) V_35 ,
F_4 , NULL ) ;
F_35 ( V_56 ,
( T_3 ) V_35 ,
F_4 , NULL ) ;
F_36 ( V_39 , V_39 ,
V_57 , V_58 ,
V_59 ) ;
F_37 ( V_60 ) ;
F_38 ( V_61 ) ;
F_39 ( V_62 ) ;
F_40 () ;
#ifdef F_41
F_42 () ;
F_43 ( V_63 ) ;
#endif
if ( ! F_44 ( V_64 , V_65 , NULL ,
NULL ) ) {
V_26 = V_66 ;
goto V_67;
}
if ( V_14 >= 2 && strcmp ( V_15 [ 1 ] , L_71 ) == 0 ) {
F_45 () ;
if ( V_14 == 2 )
F_46 () ;
else {
if ( strcmp ( V_15 [ 2 ] , L_72 ) == 0 )
F_47 () ;
else if ( strcmp ( V_15 [ 2 ] , L_73 ) == 0 ) {
F_48 () ;
F_49 ( NULL ) ;
}
else if ( strcmp ( V_15 [ 2 ] , L_74 ) == 0 )
F_50 () ;
else if ( strcmp ( V_15 [ 2 ] , L_75 ) == 0 )
F_49 ( NULL ) ;
else if ( strcmp ( V_15 [ 2 ] , L_76 ) == 0 )
F_51 () ;
else if ( strcmp ( V_15 [ 2 ] , L_77 ) == 0 )
F_46 () ;
else if ( strcmp ( V_15 [ 2 ] , L_78 ) == 0 )
F_52 () ;
else if ( strcmp ( V_15 [ 2 ] , L_79 ) == 0 )
F_53 () ;
else if ( strcmp ( V_15 [ 2 ] , L_80 ) == 0 ) {
#ifdef F_41
F_54 () ;
#endif
#ifdef F_55
F_56 () ;
#endif
}
else if ( strcmp ( V_15 [ 2 ] , L_81 ) == 0 )
F_57 () ;
else if ( strcmp ( V_15 [ 2 ] , L_82 ) == 0 )
F_58 () ;
else if ( strcmp ( V_15 [ 2 ] , L_83 ) == 0 )
F_2 () ;
else if ( strcmp ( V_15 [ 2 ] , L_84 ) == 0 )
F_2 () ;
else {
F_32 ( L_85 , V_15 [ 2 ] ) ;
V_26 = V_68 ;
goto V_67;
}
}
goto V_67;
}
V_34 = F_48 () ;
F_59 ( & V_69 ) ;
V_70 = V_71 ;
V_72 = F_60 () ;
#ifdef F_61
V_73 = 1 ;
V_74 = 1 ;
#else
V_74 = 0 ;
#endif
V_42 = 1 ;
while ( ( V_19 = F_29 ( V_14 , V_15 , V_37 , V_21 , NULL ) ) != - 1 ) {
switch ( V_19 ) {
case '2' :
V_75 = TRUE ;
break;
case 'C' :
break;
case 'e' :
F_62 ( V_72 , V_43 ) ;
break;
case 'E' :
if ( ! F_63 ( V_72 , V_43 ) ) {
F_32 ( L_86 , V_43 ) ;
F_64 ( V_12 ) ;
V_26 = V_68 ;
goto V_67;
}
break;
case 'h' :
printf ( L_48
L_87
L_88 ,
F_3 () ) ;
F_1 ( stdout ) ;
goto V_67;
break;
case 'l' :
V_76 = TRUE ;
break;
case 'o' :
{
char * V_77 = NULL ;
switch ( F_65 ( V_43 , & V_77 ) ) {
case V_78 :
break;
case V_79 :
F_32 ( L_89 , V_43 ,
V_77 ? L_90 : L_67 , V_77 ? V_77 : L_67 ) ;
F_10 ( V_77 ) ;
return 1 ;
break;
case V_80 :
case V_81 :
F_32 ( L_91 , V_43 ) ;
V_26 = V_68 ;
goto V_67;
break;
}
break;
}
case 'q' :
V_27 = TRUE ;
break;
case 'Q' :
V_27 = TRUE ;
V_82 = TRUE ;
break;
case 'r' :
V_28 = F_33 ( V_43 ) ;
break;
case 'R' :
V_29 = V_43 ;
break;
case 'S' :
V_83 = F_33 ( V_43 ) ;
break;
case 'T' :
if ( strcmp ( V_43 , L_92 ) == 0 ) {
V_84 = V_85 ;
V_70 = V_71 ;
} else if ( strcmp ( V_43 , L_93 ) == 0 ) {
V_84 = V_85 ;
V_70 = V_86 ;
} else if ( strcmp ( V_43 , L_94 ) == 0 ) {
V_84 = V_87 ;
V_44 = TRUE ;
V_47 = FALSE ;
} else if ( strcmp ( V_43 , L_95 ) == 0 ) {
V_84 = V_87 ;
V_44 = FALSE ;
V_47 = TRUE ;
} else if ( strcmp ( V_43 , L_77 ) == 0 ) {
V_84 = V_88 ;
V_44 = TRUE ;
V_47 = FALSE ;
} else {
F_32 ( L_96 , V_43 ) ;
F_66 ( L_97
L_98
L_99
L_100
L_101
L_102
L_103
L_104
L_105
L_106
L_107
L_108
L_109
L_110
L_111
L_112 ) ;
V_26 = V_68 ;
goto V_67;
}
break;
case 'v' :
V_16 = F_25 ( NULL , V_41 ) ;
V_17 = F_26 ( F_12 ) ;
F_67 ( L_113 , V_16 , V_17 ) ;
F_28 ( V_16 , TRUE ) ;
F_28 ( V_17 , TRUE ) ;
goto V_67;
case 'O' :
break;
case 'V' :
break;
case 'x' :
break;
case 'X' :
break;
case 'Y' :
V_30 = V_43 ;
break;
case 'z' :
if ( strcmp ( L_65 , V_43 ) == 0 ) {
fprintf ( V_12 , L_114 ) ;
F_68 () ;
goto V_67;
}
if ( ! F_69 ( V_43 ) ) {
F_32 ( L_115 , V_43 ) ;
F_68 () ;
V_26 = V_68 ;
goto V_67;
}
break;
case 'd' :
case 'K' :
case 't' :
case 'u' :
case V_89 :
case V_90 :
case V_91 :
case V_92 :
if ( ! F_70 ( V_19 , V_43 ) ) {
V_26 = V_68 ;
goto V_67;
}
break;
default:
case '?' :
F_1 ( V_12 ) ;
V_26 = V_68 ;
goto V_67;
break;
}
}
if ( V_88 != V_84 && 0 != F_71 ( V_72 ) ) {
F_32 ( L_116
L_117 ) ;
return 1 ;
} else if ( V_88 == V_84 && 0 == F_71 ( V_72 ) ) {
F_32 ( L_118
L_119 ) ;
V_26 = V_68 ;
goto V_67;
}
if ( V_74 < V_14 ) {
if ( V_28 != NULL ) {
if ( V_30 != NULL ) {
F_32 ( L_120
L_121 ) ;
V_26 = V_68 ;
goto V_67;
}
V_30 = F_72 ( V_14 , V_15 , V_74 ) ;
}
}
if ( ! V_27 )
V_45 = TRUE ;
if ( V_23 ) {
F_1 ( V_12 ) ;
V_26 = V_68 ;
goto V_67;
}
if ( V_46 ) {
if ( V_84 != V_85 ) {
F_32 ( L_122 ) ;
V_26 = V_68 ;
goto V_67;
}
}
if ( V_36 != NULL ) {
char * V_93 ;
if ( ! V_44 ) {
F_32 ( L_123 ) ;
V_26 = V_68 ;
goto V_67;
}
V_94 = F_73 ( V_95 , V_96 ) ;
for ( V_93 = strtok ( V_36 , L_124 ) ; V_93 ; V_93 = strtok ( NULL , L_124 ) ) {
F_74 ( V_94 , ( T_4 ) V_93 , ( T_4 ) V_93 ) ;
}
}
if ( V_29 != NULL && ! V_75 ) {
F_32 ( L_125 ) ;
V_26 = V_68 ;
goto V_67;
}
F_75 () ;
F_76 () ;
if ( ! F_77 () ) {
V_26 = V_68 ;
goto V_67;
}
F_78 ( & V_69 . V_97 , V_34 -> V_98 , TRUE ) ;
if ( V_29 != NULL ) {
if ( ! F_79 ( V_29 , & V_31 , & V_33 ) ) {
F_32 ( L_69 , V_33 ) ;
F_10 ( V_33 ) ;
V_26 = V_99 ;
goto V_67;
}
}
V_69 . V_31 = V_31 ;
if ( V_30 != NULL ) {
if ( ! F_79 ( V_30 , & V_32 , & V_33 ) ) {
F_32 ( L_69 , V_33 ) ;
F_10 ( V_33 ) ;
V_26 = V_99 ;
goto V_67;
}
}
V_69 . V_32 = V_32 ;
if ( V_45 ) {
if ( V_84 == V_85 ) {
switch ( V_70 ) {
case V_71 :
V_100 = F_80 ( stdout ) ;
break;
case V_86 :
V_100 = F_81 ( stdout ) ;
break;
default:
F_82 () ;
}
}
}
V_101 = V_45 || V_31 || V_32 || F_83 () ;
if ( V_28 ) {
if ( F_84 ( & V_69 , V_28 , V_102 , FALSE , & V_24 ) != V_103 ) {
V_26 = V_104 ;
goto V_67;
}
F_85 {
V_25 = F_86 ( & V_69 , 1 , 0 ) ;
}
F_87 (OutOfMemoryError) {
fprintf ( V_12 ,
L_126
L_1
L_127
L_1
L_128
L_129 ) ;
V_25 = FALSE ;
}
V_105 ;
if ( ! V_25 ) {
V_26 = 2 ;
}
}
F_10 ( V_28 ) ;
if ( V_69 . V_106 != NULL ) {
F_88 ( V_69 . V_106 ) ;
V_69 . V_106 = NULL ;
}
F_89 ( TRUE ) ;
F_90 () ;
V_67:
F_91 ( V_100 ) ;
F_92 ( V_69 . V_107 ) ;
F_93 () ;
#ifdef F_94
F_95 () ;
#endif
F_96 ( V_72 ) ;
V_72 = NULL ;
F_97 ( & V_69 . V_97 ) ;
F_98 () ;
return V_26 ;
}
static const T_9 *
F_99 ( void * V_108 , T_10 V_109 )
{
T_11 * V_110 = ( T_11 * ) V_108 ;
if ( V_111 && V_111 -> V_112 == V_109 )
return & V_111 -> V_113 ;
if ( V_114 && V_114 -> V_112 == V_109 )
return & V_114 -> V_113 ;
if ( V_115 && V_115 -> V_112 == V_109 )
return & V_115 -> V_113 ;
if ( V_110 -> V_106 ) {
T_12 * V_116 = F_100 ( V_110 -> V_106 , V_109 ) ;
return ( V_116 ) ? & V_116 -> V_113 : NULL ;
}
return NULL ;
}
static const char *
F_101 ( void * V_108 V_117 , T_10 T_13 V_117 )
{
return L_67 ;
}
static T_14 *
F_102 ( T_11 * V_110 )
{
T_14 * V_107 = F_103 () ;
V_107 -> V_108 = V_110 ;
V_107 -> V_118 = F_99 ;
V_107 -> V_119 = F_101 ;
V_107 -> V_120 = NULL ;
return V_107 ;
}
static T_6
F_104 ( T_11 * V_110 , T_15 * V_121 ,
T_16 V_122 , struct V_123 * V_124 ,
const T_17 * V_125 )
{
T_12 V_126 ;
T_10 V_127 ;
T_6 V_128 ;
V_127 = V_110 -> V_129 + 1 ;
V_128 = TRUE ;
F_105 ( & V_126 , V_127 , V_124 , V_122 , V_130 ) ;
if ( V_121 ) {
if ( V_110 -> V_31 )
F_106 ( V_121 , V_110 -> V_31 ) ;
F_107 ( V_121 ) ;
F_108 ( & V_126 , & V_110 -> V_131 ,
& V_111 , V_114 ) ;
if ( V_111 == & V_126 ) {
V_132 = V_126 ;
V_111 = & V_132 ;
}
F_109 ( V_121 , V_124 , F_110 ( & V_126 , V_125 ) , & V_126 , NULL ) ;
if ( V_110 -> V_31 )
V_128 = F_111 ( V_110 -> V_31 , V_121 ) ;
}
if ( V_128 ) {
F_112 ( & V_126 , & V_130 ) ;
V_115 = V_114 = F_113 ( V_110 -> V_106 , & V_126 ) ;
if ( V_121 ) {
F_114 ( V_121 -> V_133 . V_134 , V_135 , V_110 -> V_106 ) ;
}
V_110 -> V_129 ++ ;
} else {
F_115 ( & V_126 ) ;
}
if ( V_121 )
F_116 ( V_121 ) ;
return V_128 ;
}
static T_6
F_117 ( T_11 * V_110 , T_15 * V_121 ,
T_12 * V_136 , struct V_123 * V_137 ,
T_18 * V_138 , T_19 V_139 )
{
T_20 * V_97 ;
T_6 V_128 ;
V_128 = TRUE ;
if ( V_121 ) {
if ( V_110 -> V_32 )
F_106 ( V_121 , V_110 -> V_32 ) ;
F_107 ( V_121 ) ;
F_118 ( V_121 , & V_110 -> V_97 ) ;
if ( ( V_139 & V_140 ) || ( V_45 && V_47 ) )
V_97 = & V_110 -> V_97 ;
else
V_97 = NULL ;
F_108 ( V_136 , & V_110 -> V_131 ,
& V_111 , V_114 ) ;
if ( V_111 == V_136 ) {
V_132 = * V_136 ;
V_111 = & V_132 ;
}
F_119 ( V_121 , V_137 , F_120 ( V_136 , V_138 ) , V_136 , V_97 ) ;
if ( V_110 -> V_32 )
V_128 = F_111 ( V_110 -> V_32 , V_121 ) ;
}
if ( V_128 ) {
F_112 ( V_136 , & V_130 ) ;
if ( V_45 ) {
F_121 ( V_110 , V_121 ) ;
if ( V_76 )
fflush ( stdout ) ;
if ( ferror ( stdout ) ) {
F_122 ( V_141 ) ;
return FALSE ;
}
}
V_114 = V_136 ;
}
V_115 = V_136 ;
if ( V_121 ) {
F_116 ( V_121 ) ;
}
return V_128 || V_136 -> V_142 . V_143 ;
}
static T_6
F_123 ( T_11 * V_110 , struct V_123 * T_21 V_117 , int * V_24 , T_2 * * T_22 V_117 , T_16 * T_23 V_117 , T_24 * * V_144 )
{
T_16 V_145 = F_124 ( V_110 -> V_146 , V_24 ) ;
* V_144 = ( T_24 * ) F_125 ( ( V_147 ) V_145 ) ;
F_126 ( * V_144 , ( unsigned int ) V_145 , V_110 -> V_146 -> V_148 ) ;
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
static T_6
F_86 ( T_11 * V_110 , int V_149 , T_16 V_150 )
{
T_10 V_127 ;
int V_24 ;
T_2 * T_22 = NULL ;
T_16 T_23 = 0 ;
T_6 V_151 ;
T_19 V_139 ;
T_18 V_138 ;
T_15 * V_121 = NULL ;
struct V_123 T_21 ;
T_24 * V_152 ;
if ( V_45 ) {
if ( ! F_127 ( V_110 ) ) {
V_24 = V_141 ;
F_122 ( V_24 ) ;
goto V_153;
}
}
V_151 = F_128 () ;
V_139 = F_129 () ;
F_130 ( & T_21 ) ;
T_21 . V_154 = 1234 ;
if ( V_75 ) {
T_12 * V_136 ;
V_110 -> V_106 = F_131 () ;
if ( V_101 ) {
T_6 V_155 ;
V_155 =
( V_110 -> V_31 != NULL || F_132 () ) ;
V_121 = F_133 ( V_110 -> V_107 , V_155 , FALSE ) ;
}
while ( F_123 ( V_110 , & T_21 , & V_24 , & T_22 , & T_23 , & V_152 ) ) {
if ( F_104 ( V_110 , V_121 , T_23 , & T_21 ,
F_134 ( V_110 -> V_146 ) ) ) {
if ( ( -- V_149 == 0 ) || ( V_150 != 0 && T_23 >= V_150 ) ) {
V_24 = 0 ;
break;
}
}
}
if ( V_121 ) {
F_135 ( V_121 ) ;
V_121 = NULL ;
}
#if 0
wtap_sequential_close(cf->wth);
#endif
F_136 () ;
V_114 = NULL ;
V_115 = NULL ;
F_137 ( & V_138 , 1500 ) ;
if ( V_101 ) {
T_6 V_155 ;
V_155 =
( V_110 -> V_32 || V_44 || V_151 ||
( V_139 & V_156 ) || F_138 ( & V_110 -> V_97 ) ) ;
V_121 = F_133 ( V_110 -> V_107 , V_155 , V_45 && V_44 ) ;
}
for ( V_127 = 1 ; V_24 == 0 && V_127 <= V_110 -> V_129 ; V_127 ++ ) {
V_136 = F_100 ( V_110 -> V_106 , V_127 ) ;
#if 0
if (wtap_seek_read(cf->wth, fdata->file_off,
&buf, fdata->cap_len, &err, &err_info)) {
process_packet_second_pass(cf, edt, fdata, &cf->phdr, &buf, tap_flags);
}
#else
if ( ! F_117 ( V_110 , V_121 , V_136 , & V_110 -> V_137 , & V_138 ,
V_139 ) )
return FALSE ;
#endif
}
if ( V_121 ) {
F_135 ( V_121 ) ;
V_121 = NULL ;
}
F_139 ( & V_138 ) ;
}
else {
V_127 = 0 ;
if ( V_101 ) {
T_6 V_155 ;
V_155 =
( V_110 -> V_31 || V_110 -> V_32 || V_44 || V_151 ||
( V_139 & V_156 ) || F_132 () ||
F_138 ( & V_110 -> V_97 ) ) ;
V_121 = F_133 ( V_110 -> V_107 , V_155 , V_45 && V_44 ) ;
}
while ( F_123 ( V_110 , & T_21 , & V_24 , & T_22 , & T_23 , & V_152 ) ) {
V_127 ++ ;
if ( ! F_140 ( V_110 , V_121 , T_23 ,
& T_21 ,
V_152 , V_139 ) )
return FALSE ;
if ( ( -- V_149 == 0 ) || ( V_150 != 0 && T_23 >= V_150 ) ) {
V_24 = 0 ;
break;
}
}
if ( V_121 ) {
F_135 ( V_121 ) ;
V_121 = NULL ;
}
}
F_141 ( & T_21 ) ;
if ( V_24 != 0 ) {
#ifndef F_16
if ( V_45 ) {
T_25 V_157 , V_158 ;
if ( F_142 ( 1 , & V_157 ) == 0 && F_142 ( 2 , & V_158 ) == 0 ) {
if ( V_157 . V_159 == V_158 . V_159 &&
V_157 . V_160 == V_158 . V_160 ) {
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
if ( V_45 ) {
if ( ! F_143 () ) {
V_24 = V_141 ;
F_122 ( V_24 ) ;
}
}
}
V_153:
F_144 ( V_110 -> V_146 ) ;
V_110 -> V_146 = NULL ;
return ( V_24 != 0 ) ;
}
static T_6
F_140 ( T_11 * V_110 , T_15 * V_121 , T_16 V_122 ,
struct V_123 * V_124 , const T_17 * V_125 ,
T_19 V_139 )
{
T_12 V_136 ;
T_20 * V_97 ;
T_6 V_128 ;
V_110 -> V_129 ++ ;
V_128 = TRUE ;
F_105 ( & V_136 , V_110 -> V_129 , V_124 , V_122 , V_130 ) ;
if ( V_121 ) {
if ( V_110 -> V_32 )
F_106 ( V_121 , V_110 -> V_32 ) ;
F_118 ( V_121 , & V_110 -> V_97 ) ;
if ( ( V_139 & V_140 ) || ( V_45 && V_47 ) || F_145 ( V_72 ) )
V_97 = & V_110 -> V_97 ;
else
V_97 = NULL ;
F_108 ( & V_136 , & V_110 -> V_131 ,
& V_111 , V_114 ) ;
if ( V_111 == & V_136 ) {
V_132 = V_136 ;
V_111 = & V_132 ;
}
F_119 ( V_121 , V_124 , F_146 ( & V_136 , V_125 ) , & V_136 , V_97 ) ;
if ( V_110 -> V_32 )
V_128 = F_111 ( V_110 -> V_32 , V_121 ) ;
}
if ( V_128 ) {
F_112 ( & V_136 , & V_130 ) ;
if ( V_45 ) {
F_121 ( V_110 , V_121 ) ;
if ( V_76 )
fflush ( stdout ) ;
if ( ferror ( stdout ) ) {
F_122 ( V_141 ) ;
return FALSE ;
}
}
V_161 = V_136 ;
V_114 = & V_161 ;
}
V_162 = V_136 ;
V_115 = & V_162 ;
if ( V_121 ) {
F_116 ( V_121 ) ;
F_115 ( & V_136 ) ;
}
return V_128 ;
}
static T_6
F_127 ( T_11 * V_110 )
{
switch ( V_84 ) {
case V_85 :
return F_147 ( V_100 , V_110 -> V_163 , F_3 () ) ;
case V_87 :
if ( V_44 )
F_148 ( stdout , V_110 -> V_163 ) ;
else
F_149 ( & V_110 -> V_97 , stdout ) ;
return ! ferror ( stdout ) ;
case V_88 :
F_150 ( V_72 , stdout ) ;
return ! ferror ( stdout ) ;
default:
F_82 () ;
return FALSE ;
}
}
static char *
F_151 ( T_26 V_164 )
{
static char * V_165 = NULL ;
static T_26 V_166 = 256 ;
T_26 V_167 ;
for ( V_167 = V_166 ; V_164 > V_167 ;
V_167 *= 2 )
;
if ( V_165 == NULL ) {
V_166 = V_167 ;
V_165 = ( char * ) F_125 ( V_166 + 1 ) ;
} else {
if ( V_167 > V_166 ) {
V_166 = V_167 ;
V_165 = ( char * ) F_152 ( V_165 , V_166 + 1 ) ;
}
}
return V_165 ;
}
static inline void
F_153 ( char * V_168 , const char * V_13 , T_26 V_169 )
{
memcpy ( V_168 , V_13 , V_169 ) ;
V_168 [ V_169 ] = '\0' ;
}
static inline void
F_154 ( char * V_168 , const char * V_13 , T_26 V_169 , T_26 V_170 )
{
T_26 V_171 ;
for ( V_171 = V_169 ; V_171 < V_170 ; V_171 ++ )
* V_168 ++ = ' ' ;
F_153 ( V_168 , V_13 , V_169 ) ;
}
static inline void
F_155 ( char * V_168 , const char * V_13 , T_26 V_169 , T_26 V_170 )
{
T_26 V_171 ;
memcpy ( V_168 , V_13 , V_169 ) ;
for ( V_171 = V_169 ; V_171 < V_170 ; V_171 ++ )
V_168 [ V_171 ] = ' ' ;
V_168 [ V_170 ] = '\0' ;
}
static T_6
F_156 ( T_11 * V_110 )
{
char * V_165 ;
int V_171 ;
T_26 V_172 ;
T_26 V_173 ;
T_26 V_174 ;
T_27 * V_175 ;
V_165 = F_151 ( 256 ) ;
V_172 = 0 ;
* V_165 = '\0' ;
for ( V_171 = 0 ; V_171 < V_110 -> V_97 . V_98 ; V_171 ++ ) {
V_175 = & V_110 -> V_97 . V_176 [ V_171 ] ;
if ( ! F_157 ( V_171 ) )
continue;
switch ( V_175 -> V_177 ) {
case V_178 :
V_173 = V_174 = strlen ( V_175 -> V_179 ) ;
if ( V_173 < 3 )
V_173 = 3 ;
V_165 = F_151 ( V_172 + V_173 ) ;
F_154 ( V_165 + V_172 , V_175 -> V_179 , V_174 , V_173 ) ;
break;
case V_180 :
case V_181 :
case V_182 :
case V_183 :
case V_184 :
case V_185 :
case V_186 :
case V_187 :
V_173 = V_174 = strlen ( V_175 -> V_179 ) ;
if ( V_173 < 10 )
V_173 = 10 ;
V_165 = F_151 ( V_172 + V_173 ) ;
F_154 ( V_165 + V_172 , V_175 -> V_179 , V_174 , V_173 ) ;
break;
case V_188 :
case V_189 :
case V_190 :
case V_191 :
case V_192 :
case V_193 :
case V_194 :
case V_195 :
case V_196 :
V_173 = V_174 = strlen ( V_175 -> V_179 ) ;
if ( V_173 < 12 )
V_173 = 12 ;
V_165 = F_151 ( V_172 + V_173 ) ;
F_154 ( V_165 + V_172 , V_175 -> V_179 , V_174 , V_173 ) ;
break;
case V_197 :
case V_198 :
case V_199 :
case V_200 :
case V_201 :
case V_202 :
case V_203 :
case V_204 :
case V_205 :
V_173 = V_174 = strlen ( V_175 -> V_179 ) ;
if ( V_173 < 12 )
V_173 = 12 ;
V_165 = F_151 ( V_172 + V_173 ) ;
F_155 ( V_165 + V_172 , V_175 -> V_179 , V_174 , V_173 ) ;
break;
default:
V_173 = strlen ( V_175 -> V_179 ) ;
V_165 = F_151 ( V_172 + V_173 ) ;
F_153 ( V_165 + V_172 , V_175 -> V_179 , V_173 ) ;
break;
}
V_172 += V_173 ;
if ( V_171 != V_110 -> V_97 . V_98 - 1 ) {
V_165 = F_151 ( V_172 + 4 ) ;
switch ( V_175 -> V_177 ) {
case V_188 :
case V_189 :
case V_190 :
switch ( V_110 -> V_97 . V_176 [ V_171 + 1 ] . V_177 ) {
case V_197 :
case V_198 :
case V_199 :
F_153 ( V_165 + V_172 , L_130 , 4 ) ;
V_172 += 4 ;
break;
default:
F_153 ( V_165 + V_172 , L_131 , 1 ) ;
V_172 += 1 ;
break;
}
break;
case V_191 :
case V_192 :
case V_193 :
switch ( V_110 -> V_97 . V_176 [ V_171 + 1 ] . V_177 ) {
case V_200 :
case V_201 :
case V_202 :
F_153 ( V_165 + V_172 , L_130 , 4 ) ;
V_172 += 4 ;
break;
default:
F_153 ( V_165 + V_172 , L_131 , 1 ) ;
V_172 += 1 ;
break;
}
break;
case V_194 :
case V_195 :
case V_196 :
switch ( V_110 -> V_97 . V_176 [ V_171 + 1 ] . V_177 ) {
case V_203 :
case V_204 :
case V_205 :
F_153 ( V_165 + V_172 , L_130 , 4 ) ;
V_172 += 4 ;
break;
default:
F_153 ( V_165 + V_172 , L_131 , 1 ) ;
V_172 += 1 ;
break;
}
break;
case V_197 :
case V_198 :
case V_199 :
switch ( V_110 -> V_97 . V_176 [ V_171 + 1 ] . V_177 ) {
case V_188 :
case V_189 :
case V_190 :
F_153 ( V_165 + V_172 , L_132 , 4 ) ;
V_172 += 4 ;
break;
default:
F_153 ( V_165 + V_172 , L_131 , 1 ) ;
V_172 += 1 ;
break;
}
break;
case V_200 :
case V_201 :
case V_202 :
switch ( V_110 -> V_97 . V_176 [ V_171 + 1 ] . V_177 ) {
case V_191 :
case V_192 :
case V_193 :
F_153 ( V_165 + V_172 , L_132 , 4 ) ;
V_172 += 4 ;
break;
default:
F_153 ( V_165 + V_172 , L_131 , 1 ) ;
V_172 += 1 ;
break;
}
break;
case V_203 :
case V_204 :
case V_205 :
switch ( V_110 -> V_97 . V_176 [ V_171 + 1 ] . V_177 ) {
case V_194 :
case V_195 :
case V_196 :
F_153 ( V_165 + V_172 , L_132 , 4 ) ;
V_172 += 4 ;
break;
default:
F_153 ( V_165 + V_172 , L_131 , 1 ) ;
V_172 += 1 ;
break;
}
break;
default:
F_153 ( V_165 + V_172 , L_131 , 1 ) ;
V_172 += 1 ;
break;
}
}
}
return F_158 ( V_100 , 0 , V_165 ) ;
}
static T_6
F_121 ( T_11 * V_110 , T_15 * V_121 )
{
if ( V_47 || F_145 ( V_72 ) ) {
F_159 ( V_121 , FALSE , TRUE ) ;
if ( V_47 ) {
switch ( V_84 ) {
case V_85 :
if ( ! F_156 ( V_110 ) )
return FALSE ;
break;
case V_87 :
F_160 ( V_121 , stdout ) ;
return ! ferror ( stdout ) ;
case V_88 :
F_82 () ;
break;
}
}
}
if ( V_44 ) {
switch ( V_84 ) {
case V_85 :
if ( ! F_161 ( V_44 ? V_206 : V_207 ,
V_46 , V_121 , V_94 , V_100 ) )
return FALSE ;
if ( ! V_46 ) {
if ( ! F_158 ( V_100 , 0 , V_83 ) )
return FALSE ;
}
break;
case V_87 :
F_162 ( NULL , NULL , V_208 , V_121 , stdout ) ;
printf ( L_1 ) ;
return ! ferror ( stdout ) ;
case V_88 :
F_163 ( V_72 , V_121 , & V_110 -> V_97 , stdout ) ;
printf ( L_1 ) ;
return ! ferror ( stdout ) ;
}
}
if ( V_46 ) {
if ( V_47 || V_44 ) {
if ( ! F_158 ( V_100 , 0 , L_67 ) )
return FALSE ;
}
if ( ! F_164 ( V_100 , V_121 ) )
return FALSE ;
if ( ! F_158 ( V_100 , 0 , V_83 ) )
return FALSE ;
}
return TRUE ;
}
static T_6
F_143 ( void )
{
switch ( V_84 ) {
case V_85 :
return F_165 ( V_100 ) ;
case V_87 :
if ( V_44 )
F_166 ( stdout ) ;
else
F_167 ( stdout ) ;
return ! ferror ( stdout ) ;
case V_88 :
F_168 ( V_72 , stdout ) ;
return ! ferror ( stdout ) ;
default:
F_82 () ;
return FALSE ;
}
}
T_28
F_84 ( T_11 * V_110 , const char * V_209 , unsigned int type , T_6 V_210 , int * V_24 )
{
T_2 * T_22 ;
char V_33 [ 2048 + 1 ] ;
F_92 ( V_110 -> V_107 ) ;
V_110 -> V_107 = F_102 ( V_110 ) ;
V_110 -> V_146 = NULL ;
V_110 -> V_211 = 0 ;
V_110 -> V_163 = F_33 ( V_209 ) ;
V_110 -> V_210 = V_210 ;
V_110 -> V_212 = FALSE ;
V_110 -> V_213 = 0 ;
V_110 -> V_214 = type ;
V_110 -> V_129 = 0 ;
V_110 -> V_215 = FALSE ;
V_110 -> V_216 = 0 ;
V_110 -> V_217 = 0 ;
F_169 ( & V_110 -> V_131 ) ;
V_111 = NULL ;
V_114 = NULL ;
V_115 = NULL ;
V_110 -> V_218 = V_219 ;
return V_103 ;
F_170 ( V_33 , sizeof V_33 ,
F_171 ( * V_24 , T_22 , FALSE , V_110 -> V_213 ) , V_209 ) ;
F_32 ( L_69 , V_33 ) ;
return V_220 ;
}
static void
F_122 ( int V_24 )
{
switch ( V_24 ) {
case V_221 :
F_32 ( L_133
L_134 ) ;
break;
#ifdef F_172
case F_172 :
F_32 ( L_135
L_136 ) ;
break;
#endif
default:
F_32 ( L_137 ,
F_173 ( V_24 ) ) ;
break;
}
}
static const char *
F_171 ( int V_24 , T_2 * T_22 V_117 , T_6 V_222 ,
int T_29 V_117 )
{
const char * V_77 ;
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
V_77 = F_174 ( V_24 , V_222 ) ;
return V_77 ;
}
static void
V_39 ( const char * V_223 , T_30 V_224 )
{
fprintf ( V_12 , L_138 ) ;
vfprintf ( V_12 , V_223 , V_224 ) ;
fprintf ( V_12 , L_1 ) ;
}
static void
V_57 ( const char * V_163 , int V_24 , T_6 V_222 )
{
fprintf ( V_12 , L_138 ) ;
fprintf ( V_12 , F_174 ( V_24 , V_222 ) , V_163 ) ;
fprintf ( V_12 , L_1 ) ;
}
static void
V_58 ( const char * V_163 , int V_24 )
{
F_32 ( L_139 ,
V_163 , F_173 ( V_24 ) ) ;
}
static void
V_59 ( const char * V_163 , int V_24 )
{
F_32 ( L_140 ,
V_163 , F_173 ( V_24 ) ) ;
}
static void
V_40 ( const char * V_223 , T_30 V_224 )
{
vfprintf ( V_12 , V_223 , V_224 ) ;
fprintf ( V_12 , L_1 ) ;
}
