static int F_1 ( struct V_1 * V_1 )
{
int V_2 = 1 ;
F_2 ( & V_1 -> V_3 ) ;
if ( V_1 -> V_4 != V_1 -> V_5 -> V_6 -> V_7 )
V_2 = 0 ;
F_3 ( & V_1 -> V_3 ) ;
return V_2 ;
}
static int F_4 ( struct V_1 * V_1 , struct V_8 * V_9 )
{
if ( V_9 && V_9 -> V_10 & V_11 )
return - V_12 ;
if ( V_1 -> V_6 )
return 1 ;
return F_1 ( V_1 ) ;
}
static int F_5 ( struct V_1 * V_1 , struct V_8 * V_9 )
{
if ( V_9 && V_9 -> V_10 & V_11 )
return - V_12 ;
if ( V_1 -> V_6 )
return 1 ;
if ( ! V_9 )
return 0 ;
if ( V_9 -> V_10 & ( V_13 | V_14 ) )
return 0 ;
return F_1 ( V_1 ) ;
}
static unsigned int F_6 ( unsigned int V_15 , const char * V_16 )
{
while ( V_15 && V_16 [ V_15 - 1 ] == '.' )
V_15 -- ;
return V_15 ;
}
static unsigned int F_7 ( const struct V_17 * V_17 )
{
return F_6 ( V_17 -> V_15 , V_17 -> V_16 ) ;
}
static int F_8 ( const struct V_1 * V_1 , const struct V_18 * V_18 ,
struct V_17 * V_17 )
{
V_17 -> V_19 = F_9 ( V_17 -> V_16 , F_7 ( V_17 ) ) ;
return 0 ;
}
static int F_10 ( const struct V_1 * V_1 , const struct V_18 * V_18 ,
struct V_17 * V_17 )
{
struct V_20 * V_21 = F_11 ( V_1 -> V_22 ) -> V_23 ;
const unsigned char * V_16 ;
unsigned int V_15 ;
unsigned long V_19 ;
V_16 = V_17 -> V_16 ;
V_15 = F_7 ( V_17 ) ;
V_19 = F_12 () ;
while ( V_15 -- )
V_19 = F_13 ( F_14 ( V_21 , * V_16 ++ ) , V_19 ) ;
V_17 -> V_19 = F_15 ( V_19 ) ;
return 0 ;
}
static int F_16 ( const struct V_1 * V_24 , const struct V_18 * V_25 ,
const struct V_1 * V_1 , const struct V_18 * V_18 ,
unsigned int V_15 , const char * V_26 , const struct V_17 * V_16 )
{
struct V_20 * V_21 = F_11 ( V_24 -> V_22 ) -> V_23 ;
unsigned int V_27 , V_28 ;
V_27 = F_7 ( V_16 ) ;
V_28 = F_6 ( V_15 , V_26 ) ;
if ( V_27 == V_28 ) {
if ( F_17 ( V_21 , V_16 -> V_16 , V_26 , V_27 ) == 0 )
return 0 ;
}
return 1 ;
}
static int F_18 ( const struct V_1 * V_24 , const struct V_18 * V_25 ,
const struct V_1 * V_1 , const struct V_18 * V_18 ,
unsigned int V_15 , const char * V_26 , const struct V_17 * V_16 )
{
unsigned int V_27 , V_28 ;
V_27 = F_7 ( V_16 ) ;
V_28 = F_6 ( V_15 , V_26 ) ;
if ( V_27 == V_28 ) {
if ( strncmp ( V_16 -> V_16 , V_26 , V_27 ) == 0 )
return 0 ;
}
return 1 ;
}
static inline T_1 F_19 ( T_1 V_29 )
{
return ( V_29 < 0x0020 )
|| ( V_29 == '*' ) || ( V_29 == '?' ) || ( V_29 == '<' ) || ( V_29 == '>' )
|| ( V_29 == '|' ) || ( V_29 == '"' ) || ( V_29 == ':' ) || ( V_29 == '/' )
|| ( V_29 == '\\' ) ;
}
static inline T_1 F_20 ( T_1 V_29 )
{
return ( V_29 == '[' ) || ( V_29 == ']' ) || ( V_29 == ';' ) || ( V_29 == ',' )
|| ( V_29 == '+' ) || ( V_29 == '=' ) ;
}
static T_1 F_21 ( T_1 V_29 )
{
return ( V_29 == '.' ) || ( V_29 == ' ' ) ;
}
static inline int F_22 ( const T_1 * V_30 , int V_15 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < V_15 ; V_31 ++ )
if ( F_19 ( V_30 [ V_31 ] ) )
return - V_32 ;
if ( V_30 [ V_31 - 1 ] == ' ' )
return - V_32 ;
return 0 ;
}
static int F_23 ( struct V_18 * V_33 , unsigned char * V_16 )
{
struct V_34 V_35 ;
int V_36 = F_24 ( V_33 , V_16 , & V_35 ) ;
if ( V_36 )
return - V_37 ;
F_25 ( V_35 . V_38 ) ;
return 0 ;
}
static inline int F_26 ( struct V_20 * V_39 ,
unsigned char * V_40 , int V_41 ,
T_1 * V_42 , struct V_43 * V_44 )
{
int V_15 ;
if ( F_21 ( * V_42 ) ) {
V_44 -> V_45 = 0 ;
return 0 ;
}
if ( F_20 ( * V_42 ) ) {
V_44 -> V_45 = 0 ;
V_40 [ 0 ] = '_' ;
return 1 ;
}
V_15 = V_39 -> V_46 ( * V_42 , V_40 , V_41 ) ;
if ( V_15 <= 0 ) {
V_44 -> V_45 = 0 ;
V_40 [ 0 ] = '_' ;
V_15 = 1 ;
} else if ( V_15 == 1 ) {
unsigned char V_47 = V_40 [ 0 ] ;
if ( V_40 [ 0 ] >= 0x7F ) {
V_44 -> V_48 = 0 ;
V_44 -> V_49 = 0 ;
}
V_40 [ 0 ] = F_27 ( V_39 , V_40 [ 0 ] ) ;
if ( isalpha ( V_40 [ 0 ] ) ) {
if ( V_40 [ 0 ] == V_47 )
V_44 -> V_48 = 0 ;
else
V_44 -> V_49 = 0 ;
}
} else {
V_44 -> V_48 = 0 ;
V_44 -> V_49 = 0 ;
}
return V_15 ;
}
static int F_28 ( struct V_18 * V_33 , struct V_20 * V_39 ,
T_1 * V_50 , int V_51 ,
unsigned char * V_52 , unsigned char * V_53 )
{
struct V_54 * V_55 = & F_11 ( V_33 -> V_56 ) -> V_57 ;
T_1 * V_58 , * V_59 , * V_60 , * V_61 ;
unsigned char V_62 [ 9 ] , V_63 [ 4 ] , V_40 [ 5 ] , * V_64 ;
unsigned char V_65 [ V_66 ] ;
int V_67 , V_68 ;
int V_69 = 0 , V_70 , V_71 , V_31 , V_72 , V_73 ;
int V_74 ;
struct V_43 V_75 , V_76 ;
V_74 = 1 ;
F_29 ( & V_75 ) ;
F_29 ( & V_76 ) ;
V_59 = V_60 = & V_50 [ V_51 ] ;
while ( -- V_59 >= V_50 ) {
if ( * V_59 == 0x002E ) {
if ( V_59 == V_60 - 1 ) {
V_69 = V_51 ;
V_59 = NULL ;
}
break;
}
}
if ( V_59 == V_50 - 1 ) {
V_69 = V_51 ;
V_59 = NULL ;
} else if ( V_59 ) {
V_61 = & V_50 [ 0 ] ;
while ( V_61 < V_59 ) {
if ( ! F_21 ( * V_61 ) )
break;
V_61 ++ ;
}
if ( V_61 != V_59 ) {
V_69 = V_59 - V_50 ;
V_59 ++ ;
} else {
V_69 = V_51 ;
V_59 = NULL ;
}
}
V_72 = 6 ;
V_73 = 2 ;
for ( V_71 = V_31 = 0 , V_64 = V_62 , V_58 = V_50 ; V_31 < V_69 ; V_31 ++ , V_58 ++ ) {
V_67 = F_26 ( V_39 , V_65 , sizeof( V_65 ) ,
V_58 , & V_75 ) ;
if ( V_67 == 0 )
continue;
if ( V_71 < 2 && ( V_71 + V_67 ) > 2 )
V_73 = V_71 ;
if ( V_71 < 6 && ( V_71 + V_67 ) > 6 )
V_72 = V_71 ;
for ( V_68 = 0 ; V_68 < V_67 ; V_68 ++ ) {
* V_64 ++ = V_65 [ V_68 ] ;
V_71 ++ ;
if ( V_71 >= 8 )
break;
}
if ( V_71 >= 8 ) {
if ( ( V_68 < V_67 - 1 ) || ( V_58 + 1 ) - V_50 < V_69 )
V_74 = 0 ;
break;
}
}
if ( V_71 == 0 ) {
return - V_32 ;
}
V_70 = 0 ;
if ( V_59 ) {
for ( V_64 = V_63 , V_58 = V_59 ; V_70 < 3 && V_58 < V_60 ; V_58 ++ ) {
V_67 = F_26 ( V_39 , V_65 , sizeof( V_65 ) ,
V_58 , & V_76 ) ;
if ( V_67 == 0 )
continue;
if ( ( V_70 + V_67 ) > 3 ) {
V_74 = 0 ;
break;
}
for ( V_68 = 0 ; V_68 < V_67 ; V_68 ++ ) {
* V_64 ++ = V_65 [ V_68 ] ;
V_70 ++ ;
}
if ( V_70 >= 3 ) {
if ( V_58 + 1 != V_60 )
V_74 = 0 ;
break;
}
}
}
V_63 [ V_70 ] = '\0' ;
V_62 [ V_71 ] = '\0' ;
if ( V_62 [ 0 ] == V_77 )
V_62 [ 0 ] = 0x05 ;
memset ( V_52 , ' ' , V_78 ) ;
memcpy ( V_52 , V_62 , V_71 ) ;
memcpy ( V_52 + 8 , V_63 , V_70 ) ;
* V_53 = 0 ;
if ( V_74 && V_75 . V_45 && V_76 . V_45 ) {
if ( F_23 ( V_33 , V_52 ) == 0 )
return - V_79 ;
if ( V_55 -> V_80 & V_81 ) {
return ( V_75 . V_49 && V_76 . V_49 ) ;
} else if ( V_55 -> V_80 & V_82 ) {
if ( ( V_75 . V_49 || V_75 . V_48 ) &&
( V_76 . V_49 || V_76 . V_48 ) ) {
if ( ! V_75 . V_49 && V_75 . V_48 )
* V_53 |= V_83 ;
if ( ! V_76 . V_49 && V_76 . V_48 )
* V_53 |= V_84 ;
return 1 ;
}
return 0 ;
} else {
F_30 () ;
}
}
if ( V_55 -> V_85 == 0 )
if ( F_23 ( V_33 , V_52 ) < 0 )
return 0 ;
if ( V_71 > 6 ) {
V_71 = V_72 ;
V_52 [ 7 ] = ' ' ;
}
V_52 [ V_71 ] = '~' ;
for ( V_31 = 1 ; V_31 < 10 ; V_31 ++ ) {
V_52 [ V_71 + 1 ] = V_31 + '0' ;
if ( F_23 ( V_33 , V_52 ) < 0 )
return 0 ;
}
V_31 = V_86 ;
V_69 = ( V_86 >> 16 ) & 0x7 ;
if ( V_71 > 2 ) {
V_71 = V_73 ;
V_52 [ 7 ] = ' ' ;
}
V_52 [ V_71 + 4 ] = '~' ;
V_52 [ V_71 + 5 ] = '1' + V_69 ;
while ( 1 ) {
snprintf ( V_40 , sizeof( V_40 ) , L_1 , V_31 & 0xffff ) ;
memcpy ( & V_52 [ V_71 ] , V_40 , 4 ) ;
if ( F_23 ( V_33 , V_52 ) < 0 )
break;
V_31 -= 11 ;
}
return 0 ;
}
static int
F_31 ( const unsigned char * V_16 , int V_15 , unsigned char * V_87 ,
int * V_88 , int * V_89 , int V_90 , int V_91 ,
struct V_20 * V_39 )
{
const unsigned char * V_58 ;
unsigned char V_92 ;
unsigned char * V_93 ;
unsigned int V_94 ;
int V_31 , V_95 , V_96 ;
int V_97 ;
if ( V_91 ) {
* V_89 = F_32 ( V_16 , V_15 , V_98 ,
( T_1 * ) V_87 , V_99 + 2 ) ;
if ( * V_89 < 0 )
return * V_89 ;
else if ( * V_89 > V_99 )
return - V_100 ;
V_93 = & V_87 [ * V_89 * sizeof( T_1 ) ] ;
} else {
if ( V_39 ) {
for ( V_31 = 0 , V_58 = V_16 , V_93 = V_87 , * V_89 = 0 ;
V_31 < V_15 && * V_89 <= V_99 ;
* V_89 += 1 )
{
if ( V_90 && ( * V_58 == ':' ) ) {
if ( V_31 > V_15 - 5 )
return - V_32 ;
V_94 = 0 ;
for ( V_95 = 1 ; V_95 < 5 ; V_95 ++ ) {
V_92 = V_58 [ V_95 ] ;
V_94 <<= 4 ;
if ( V_92 >= '0' && V_92 <= '9' ) {
V_94 |= V_92 - '0' ;
continue;
}
if ( V_92 >= 'a' && V_92 <= 'f' ) {
V_94 |= V_92 - ( 'a' - 10 ) ;
continue;
}
if ( V_92 >= 'A' && V_92 <= 'F' ) {
V_94 |= V_92 - ( 'A' - 10 ) ;
continue;
}
return - V_32 ;
}
* V_93 ++ = V_94 & 0xFF ;
* V_93 ++ = V_94 >> 8 ;
V_58 += 5 ;
V_31 += 5 ;
} else {
if ( ( V_97 = V_39 -> V_101 ( V_58 , V_15 - V_31 , ( T_1 * ) V_93 ) ) < 0 )
return - V_32 ;
V_58 += V_97 ;
V_31 += V_97 ;
V_93 += 2 ;
}
}
if ( V_31 < V_15 )
return - V_100 ;
} else {
for ( V_31 = 0 , V_58 = V_16 , V_93 = V_87 , * V_89 = 0 ;
V_31 < V_15 && * V_89 <= V_99 ;
V_31 ++ , * V_89 += 1 )
{
* V_93 ++ = * V_58 ++ ;
* V_93 ++ = 0 ;
}
if ( V_31 < V_15 )
return - V_100 ;
}
}
* V_88 = * V_89 ;
if ( * V_89 % 13 ) {
* V_93 ++ = 0 ;
* V_93 ++ = 0 ;
* V_89 += 1 ;
if ( * V_89 % 13 ) {
V_96 = 13 - ( * V_89 % 13 ) ;
for ( V_31 = 0 ; V_31 < V_96 ; V_31 ++ ) {
* V_93 ++ = 0xff ;
* V_93 ++ = 0xff ;
}
* V_89 += V_96 ;
}
}
return 0 ;
}
static int F_33 ( struct V_18 * V_33 , const unsigned char * V_16 ,
int V_15 , int V_102 , int V_103 ,
struct V_104 * V_105 ,
struct V_106 * V_107 , int * V_108 )
{
struct V_109 * V_110 = F_11 ( V_33 -> V_56 ) ;
struct V_54 * V_55 = & V_110 -> V_57 ;
struct V_106 * V_111 ;
struct V_112 * V_113 ;
unsigned char V_114 , V_53 ;
unsigned char V_115 [ V_78 ] ;
T_1 * V_50 ;
T_2 time , V_116 ;
T_3 V_117 ;
int V_36 , V_51 , V_118 , V_31 ;
T_4 V_119 ;
* V_108 = 0 ;
V_50 = F_34 () ;
if ( ! V_50 )
return - V_120 ;
V_36 = F_31 ( V_16 , V_15 , ( unsigned char * ) V_50 , & V_51 , & V_118 ,
V_55 -> V_121 , V_55 -> V_91 , V_110 -> V_23 ) ;
if ( V_36 )
goto V_122;
V_36 = F_22 ( V_50 , V_51 ) ;
if ( V_36 )
goto V_122;
V_36 = F_28 ( V_33 , V_110 -> V_123 , V_50 , V_51 ,
V_115 , & V_53 ) ;
if ( V_36 < 0 )
goto V_122;
else if ( V_36 == 1 ) {
V_113 = (struct V_112 * ) V_107 ;
V_36 = 0 ;
goto V_80;
}
V_114 = F_35 ( V_115 ) ;
* V_108 = V_118 / 13 ;
for ( V_111 = V_107 , V_31 = * V_108 ; V_31 > 0 ; V_31 -- , V_111 ++ ) {
V_111 -> V_124 = V_31 ;
V_111 -> V_125 = V_126 ;
V_111 -> V_127 = 0 ;
V_111 -> V_128 = V_114 ;
V_111 -> V_129 = 0 ;
V_119 = ( V_31 - 1 ) * 13 ;
F_36 ( V_111 -> V_130 , V_50 + V_119 , 5 ) ;
F_36 ( V_111 -> V_131 , V_50 + V_119 + 5 , 6 ) ;
F_36 ( V_111 -> V_132 , V_50 + V_119 + 11 , 2 ) ;
}
V_107 [ 0 ] . V_124 |= 0x40 ;
V_113 = (struct V_112 * ) V_111 ;
V_80:
( * V_108 ) ++ ;
memcpy ( V_113 -> V_16 , V_115 , V_78 ) ;
V_113 -> V_125 = V_102 ? V_133 : V_134 ;
V_113 -> V_53 = V_53 ;
F_37 ( V_110 , V_105 , & time , & V_116 , & V_117 ) ;
V_113 -> time = V_113 -> ctime = time ;
V_113 -> V_116 = V_113 -> V_135 = V_113 -> V_136 = V_116 ;
V_113 -> V_137 = V_117 ;
V_113 -> V_129 = F_38 ( V_103 ) ;
V_113 -> V_138 = F_38 ( V_103 >> 16 ) ;
V_113 -> V_139 = 0 ;
V_122:
F_39 ( V_50 ) ;
return V_36 ;
}
static int F_40 ( struct V_18 * V_33 , struct V_17 * V_140 , int V_102 ,
int V_103 , struct V_104 * V_105 ,
struct V_34 * V_35 )
{
struct V_106 * V_107 ;
unsigned int V_15 ;
int V_36 , V_108 ;
V_15 = F_7 ( V_140 ) ;
if ( V_15 == 0 )
return - V_37 ;
V_107 = F_41 ( sizeof( * V_107 ) * V_141 , V_142 ) ;
if ( V_107 == NULL )
return - V_120 ;
V_36 = F_33 ( V_33 , V_140 -> V_16 , V_15 , V_102 , V_103 , V_105 ,
V_107 , & V_108 ) ;
if ( V_36 )
goto V_143;
V_36 = F_42 ( V_33 , V_107 , V_108 , V_35 ) ;
if ( V_36 )
goto V_143;
V_33 -> V_144 = V_33 -> V_145 = V_33 -> V_146 = * V_105 ;
if ( F_43 ( V_33 ) )
( void ) F_44 ( V_33 ) ;
else
F_45 ( V_33 ) ;
V_143:
F_46 ( V_107 ) ;
return V_36 ;
}
static int F_47 ( struct V_18 * V_33 , struct V_17 * V_140 ,
struct V_34 * V_35 )
{
unsigned int V_15 = F_7 ( V_140 ) ;
if ( V_15 == 0 )
return - V_37 ;
return F_48 ( V_33 , V_140 -> V_16 , V_15 , V_35 ) ;
}
static int F_49 ( struct V_1 * V_1 )
{
return F_50 ( V_1 ) && ( V_1 -> V_147 & V_148 ) ;
}
static struct V_1 * F_51 ( struct V_18 * V_33 , struct V_1 * V_1 ,
struct V_8 * V_9 )
{
struct V_149 * V_150 = V_33 -> V_56 ;
struct V_34 V_35 ;
struct V_18 * V_18 ;
struct V_1 * V_151 ;
int V_36 ;
F_52 ( V_150 ) ;
V_36 = F_47 ( V_33 , & V_1 -> V_152 , & V_35 ) ;
if ( V_36 ) {
if ( V_36 == - V_37 ) {
V_18 = NULL ;
goto V_153;
}
goto error;
}
V_18 = F_53 ( V_150 , V_35 . V_113 , V_35 . V_154 ) ;
F_25 ( V_35 . V_38 ) ;
if ( F_54 ( V_18 ) ) {
V_36 = F_55 ( V_18 ) ;
goto error;
}
V_151 = F_56 ( V_18 ) ;
if ( V_151 && ! F_49 ( V_151 ) ) {
F_57 ( F_58 ( V_151 ) ) ;
if ( ! F_59 ( V_18 -> V_155 ) )
F_60 ( V_151 , V_1 ) ;
F_61 ( V_18 ) ;
F_62 ( V_150 ) ;
return V_151 ;
} else
F_63 ( V_151 ) ;
V_153:
F_62 ( V_150 ) ;
V_1 -> V_4 = V_1 -> V_5 -> V_6 -> V_7 ;
V_1 = F_64 ( V_18 , V_1 ) ;
if ( V_1 )
V_1 -> V_4 = V_1 -> V_5 -> V_6 -> V_7 ;
return V_1 ;
error:
F_62 ( V_150 ) ;
return F_65 ( V_36 ) ;
}
static int F_66 ( struct V_18 * V_33 , struct V_1 * V_1 , T_5 V_156 ,
struct V_8 * V_9 )
{
struct V_149 * V_150 = V_33 -> V_56 ;
struct V_18 * V_18 ;
struct V_34 V_35 ;
struct V_104 V_105 ;
int V_36 ;
F_52 ( V_150 ) ;
V_105 = V_157 ;
V_36 = F_40 ( V_33 , & V_1 -> V_152 , 0 , 0 , & V_105 , & V_35 ) ;
if ( V_36 )
goto V_153;
V_33 -> V_7 ++ ;
V_18 = F_53 ( V_150 , V_35 . V_113 , V_35 . V_154 ) ;
F_25 ( V_35 . V_38 ) ;
if ( F_54 ( V_18 ) ) {
V_36 = F_55 ( V_18 ) ;
goto V_153;
}
V_18 -> V_7 ++ ;
V_18 -> V_145 = V_18 -> V_146 = V_18 -> V_144 = V_105 ;
V_1 -> V_4 = V_1 -> V_5 -> V_6 -> V_7 ;
F_67 ( V_1 , V_18 ) ;
V_153:
F_62 ( V_150 ) ;
return V_36 ;
}
static int F_68 ( struct V_18 * V_33 , struct V_1 * V_1 )
{
struct V_18 * V_18 = V_1 -> V_6 ;
struct V_149 * V_150 = V_33 -> V_56 ;
struct V_34 V_35 ;
int V_36 ;
F_52 ( V_150 ) ;
V_36 = F_69 ( V_18 ) ;
if ( V_36 )
goto V_153;
V_36 = F_47 ( V_33 , & V_1 -> V_152 , & V_35 ) ;
if ( V_36 )
goto V_153;
V_36 = F_70 ( V_33 , & V_35 ) ;
if ( V_36 )
goto V_153;
F_71 ( V_33 ) ;
F_72 ( V_18 ) ;
V_18 -> V_145 = V_18 -> V_146 = V_157 ;
F_73 ( V_18 ) ;
V_153:
F_62 ( V_150 ) ;
return V_36 ;
}
static int F_74 ( struct V_18 * V_33 , struct V_1 * V_1 )
{
struct V_18 * V_18 = V_1 -> V_6 ;
struct V_149 * V_150 = V_33 -> V_56 ;
struct V_34 V_35 ;
int V_36 ;
F_52 ( V_150 ) ;
V_36 = F_47 ( V_33 , & V_1 -> V_152 , & V_35 ) ;
if ( V_36 )
goto V_153;
V_36 = F_70 ( V_33 , & V_35 ) ;
if ( V_36 )
goto V_153;
F_72 ( V_18 ) ;
V_18 -> V_145 = V_18 -> V_146 = V_157 ;
F_73 ( V_18 ) ;
V_153:
F_62 ( V_150 ) ;
return V_36 ;
}
static int F_75 ( struct V_18 * V_33 , struct V_1 * V_1 , T_5 V_156 )
{
struct V_149 * V_150 = V_33 -> V_56 ;
struct V_18 * V_18 ;
struct V_34 V_35 ;
struct V_104 V_105 ;
int V_36 , V_103 ;
F_52 ( V_150 ) ;
V_105 = V_157 ;
V_103 = F_76 ( V_33 , & V_105 ) ;
if ( V_103 < 0 ) {
V_36 = V_103 ;
goto V_153;
}
V_36 = F_40 ( V_33 , & V_1 -> V_152 , 1 , V_103 , & V_105 , & V_35 ) ;
if ( V_36 )
goto V_122;
V_33 -> V_7 ++ ;
F_77 ( V_33 ) ;
V_18 = F_53 ( V_150 , V_35 . V_113 , V_35 . V_154 ) ;
F_25 ( V_35 . V_38 ) ;
if ( F_54 ( V_18 ) ) {
V_36 = F_55 ( V_18 ) ;
goto V_153;
}
V_18 -> V_7 ++ ;
F_78 ( V_18 , 2 ) ;
V_18 -> V_145 = V_18 -> V_146 = V_18 -> V_144 = V_105 ;
V_1 -> V_4 = V_1 -> V_5 -> V_6 -> V_7 ;
F_67 ( V_1 , V_18 ) ;
F_62 ( V_150 ) ;
return 0 ;
V_122:
F_79 ( V_33 , V_103 ) ;
V_153:
F_62 ( V_150 ) ;
return V_36 ;
}
static int F_80 ( struct V_18 * V_158 , struct V_1 * V_159 ,
struct V_18 * V_160 , struct V_1 * V_161 )
{
struct V_162 * V_163 ;
struct V_112 * V_164 ;
struct V_18 * V_165 , * V_166 ;
struct V_34 V_167 , V_35 ;
struct V_104 V_105 ;
T_4 V_168 , V_169 ;
int V_36 , V_102 , V_170 , V_171 = 0 ;
struct V_149 * V_150 = V_158 -> V_56 ;
V_167 . V_38 = V_35 . V_38 = V_163 = NULL ;
V_165 = V_159 -> V_6 ;
V_166 = V_161 -> V_6 ;
F_52 ( V_150 ) ;
V_36 = F_47 ( V_158 , & V_159 -> V_152 , & V_167 ) ;
if ( V_36 )
goto V_153;
V_102 = F_59 ( V_165 -> V_155 ) ;
V_170 = ( V_102 && V_158 != V_160 ) ;
if ( V_170 ) {
if ( F_81 ( V_165 , & V_163 , & V_164 ,
& V_168 ) < 0 ) {
V_36 = - V_172 ;
goto V_153;
}
}
V_105 = V_157 ;
if ( V_166 ) {
if ( V_102 ) {
V_36 = F_69 ( V_166 ) ;
if ( V_36 )
goto V_153;
}
V_169 = F_82 ( V_166 ) -> V_154 ;
F_73 ( V_166 ) ;
} else {
V_36 = F_40 ( V_160 , & V_161 -> V_152 , V_102 , 0 ,
& V_105 , & V_35 ) ;
if ( V_36 )
goto V_153;
V_169 = V_35 . V_154 ;
}
V_160 -> V_7 ++ ;
F_73 ( V_165 ) ;
F_83 ( V_165 , V_169 ) ;
if ( F_43 ( V_160 ) ) {
V_36 = F_44 ( V_165 ) ;
if ( V_36 )
goto V_173;
} else
F_45 ( V_165 ) ;
if ( V_170 ) {
int V_129 = F_82 ( V_160 ) -> V_174 ;
V_164 -> V_129 = F_38 ( V_129 ) ;
V_164 -> V_138 = F_38 ( V_129 >> 16 ) ;
F_84 ( V_163 , V_165 ) ;
if ( F_43 ( V_160 ) ) {
V_36 = F_85 ( V_163 ) ;
if ( V_36 )
goto V_175;
}
F_71 ( V_158 ) ;
if ( ! V_166 )
F_77 ( V_160 ) ;
}
V_36 = F_70 ( V_158 , & V_167 ) ;
V_167 . V_38 = NULL ;
if ( V_36 )
goto V_175;
V_158 -> V_7 ++ ;
V_158 -> V_144 = V_158 -> V_145 = V_105 ;
if ( F_43 ( V_158 ) )
( void ) F_44 ( V_158 ) ;
else
F_45 ( V_158 ) ;
if ( V_166 ) {
F_71 ( V_166 ) ;
if ( V_102 )
F_71 ( V_166 ) ;
V_166 -> V_144 = V_105 ;
}
V_153:
F_25 ( V_35 . V_38 ) ;
F_25 ( V_163 ) ;
F_25 ( V_167 . V_38 ) ;
F_62 ( V_150 ) ;
return V_36 ;
V_175:
V_171 = 1 ;
if ( V_170 ) {
int V_129 = F_82 ( V_158 ) -> V_174 ;
V_164 -> V_129 = F_38 ( V_129 ) ;
V_164 -> V_138 = F_38 ( V_129 >> 16 ) ;
F_84 ( V_163 , V_165 ) ;
V_171 |= F_85 ( V_163 ) ;
}
V_173:
F_73 ( V_165 ) ;
F_83 ( V_165 , V_167 . V_154 ) ;
if ( V_166 ) {
F_83 ( V_166 , V_169 ) ;
if ( V_171 )
V_171 |= F_44 ( V_166 ) ;
} else {
int V_176 = F_70 ( V_160 , & V_35 ) ;
if ( V_171 )
V_171 |= V_176 ;
V_35 . V_38 = NULL ;
}
if ( V_171 < 0 ) {
F_86 ( V_160 -> V_56 ,
L_2 ,
V_177 , V_35 . V_154 ) ;
}
goto V_153;
}
static void F_87 ( struct V_149 * V_150 )
{
F_11 ( V_150 ) -> V_178 = & V_179 ;
if ( F_11 ( V_150 ) -> V_57 . V_180 != 's' )
V_150 -> V_181 = & V_182 ;
else
V_150 -> V_181 = & V_183 ;
}
static int F_88 ( struct V_149 * V_150 , void * V_184 , int V_185 )
{
return F_89 ( V_150 , V_184 , V_185 , 1 , F_87 ) ;
}
static struct V_1 * F_90 ( struct V_186 * V_187 ,
int V_10 , const char * V_188 ,
void * V_184 )
{
return F_91 ( V_187 , V_10 , V_188 , V_184 , F_88 ) ;
}
static int T_6 F_92 ( void )
{
return F_93 ( & V_189 ) ;
}
static void T_7 F_94 ( void )
{
F_95 ( & V_189 ) ;
}
