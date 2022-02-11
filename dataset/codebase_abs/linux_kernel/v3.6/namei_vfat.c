static int F_1 ( struct V_1 * V_1 )
{
int V_2 = 1 ;
F_2 ( & V_1 -> V_3 ) ;
if ( V_1 -> V_4 != V_1 -> V_5 -> V_6 -> V_7 )
V_2 = 0 ;
F_3 ( & V_1 -> V_3 ) ;
return V_2 ;
}
static int F_4 ( struct V_1 * V_1 , unsigned int V_8 )
{
if ( V_8 & V_9 )
return - V_10 ;
if ( V_1 -> V_6 )
return 1 ;
return F_1 ( V_1 ) ;
}
static int F_5 ( struct V_1 * V_1 , unsigned int V_8 )
{
if ( V_8 & V_9 )
return - V_10 ;
if ( V_1 -> V_6 )
return 1 ;
if ( ! V_8 )
return 0 ;
if ( V_8 & ( V_11 | V_12 ) )
return 0 ;
return F_1 ( V_1 ) ;
}
static unsigned int F_6 ( unsigned int V_13 , const char * V_14 )
{
while ( V_13 && V_14 [ V_13 - 1 ] == '.' )
V_13 -- ;
return V_13 ;
}
static unsigned int F_7 ( const struct V_15 * V_15 )
{
return F_6 ( V_15 -> V_13 , V_15 -> V_14 ) ;
}
static int F_8 ( const struct V_1 * V_1 , const struct V_16 * V_16 ,
struct V_15 * V_15 )
{
V_15 -> V_17 = F_9 ( V_15 -> V_14 , F_7 ( V_15 ) ) ;
return 0 ;
}
static int F_10 ( const struct V_1 * V_1 , const struct V_16 * V_16 ,
struct V_15 * V_15 )
{
struct V_18 * V_19 = F_11 ( V_1 -> V_20 ) -> V_21 ;
const unsigned char * V_14 ;
unsigned int V_13 ;
unsigned long V_17 ;
V_14 = V_15 -> V_14 ;
V_13 = F_7 ( V_15 ) ;
V_17 = F_12 () ;
while ( V_13 -- )
V_17 = F_13 ( F_14 ( V_19 , * V_14 ++ ) , V_17 ) ;
V_15 -> V_17 = F_15 ( V_17 ) ;
return 0 ;
}
static int F_16 ( const struct V_1 * V_22 , const struct V_16 * V_23 ,
const struct V_1 * V_1 , const struct V_16 * V_16 ,
unsigned int V_13 , const char * V_24 , const struct V_15 * V_14 )
{
struct V_18 * V_19 = F_11 ( V_22 -> V_20 ) -> V_21 ;
unsigned int V_25 , V_26 ;
V_25 = F_7 ( V_14 ) ;
V_26 = F_6 ( V_13 , V_24 ) ;
if ( V_25 == V_26 ) {
if ( F_17 ( V_19 , V_14 -> V_14 , V_24 , V_25 ) == 0 )
return 0 ;
}
return 1 ;
}
static int F_18 ( const struct V_1 * V_22 , const struct V_16 * V_23 ,
const struct V_1 * V_1 , const struct V_16 * V_16 ,
unsigned int V_13 , const char * V_24 , const struct V_15 * V_14 )
{
unsigned int V_25 , V_26 ;
V_25 = F_7 ( V_14 ) ;
V_26 = F_6 ( V_13 , V_24 ) ;
if ( V_25 == V_26 ) {
if ( strncmp ( V_14 -> V_14 , V_24 , V_25 ) == 0 )
return 0 ;
}
return 1 ;
}
static inline T_1 F_19 ( T_1 V_27 )
{
return ( V_27 < 0x0020 )
|| ( V_27 == '*' ) || ( V_27 == '?' ) || ( V_27 == '<' ) || ( V_27 == '>' )
|| ( V_27 == '|' ) || ( V_27 == '"' ) || ( V_27 == ':' ) || ( V_27 == '/' )
|| ( V_27 == '\\' ) ;
}
static inline T_1 F_20 ( T_1 V_27 )
{
return ( V_27 == '[' ) || ( V_27 == ']' ) || ( V_27 == ';' ) || ( V_27 == ',' )
|| ( V_27 == '+' ) || ( V_27 == '=' ) ;
}
static T_1 F_21 ( T_1 V_27 )
{
return ( V_27 == '.' ) || ( V_27 == ' ' ) ;
}
static inline int F_22 ( const T_1 * V_28 , int V_13 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < V_13 ; V_29 ++ )
if ( F_19 ( V_28 [ V_29 ] ) )
return - V_30 ;
if ( V_28 [ V_29 - 1 ] == ' ' )
return - V_30 ;
return 0 ;
}
static int F_23 ( struct V_16 * V_31 , unsigned char * V_14 )
{
struct V_32 V_33 ;
int V_34 = F_24 ( V_31 , V_14 , & V_33 ) ;
if ( V_34 )
return - V_35 ;
F_25 ( V_33 . V_36 ) ;
return 0 ;
}
static inline int F_26 ( struct V_18 * V_37 ,
unsigned char * V_38 , int V_39 ,
T_1 * V_40 , struct V_41 * V_42 )
{
int V_13 ;
if ( F_21 ( * V_40 ) ) {
V_42 -> V_43 = 0 ;
return 0 ;
}
if ( F_20 ( * V_40 ) ) {
V_42 -> V_43 = 0 ;
V_38 [ 0 ] = '_' ;
return 1 ;
}
V_13 = V_37 -> V_44 ( * V_40 , V_38 , V_39 ) ;
if ( V_13 <= 0 ) {
V_42 -> V_43 = 0 ;
V_38 [ 0 ] = '_' ;
V_13 = 1 ;
} else if ( V_13 == 1 ) {
unsigned char V_45 = V_38 [ 0 ] ;
if ( V_38 [ 0 ] >= 0x7F ) {
V_42 -> V_46 = 0 ;
V_42 -> V_47 = 0 ;
}
V_38 [ 0 ] = F_27 ( V_37 , V_38 [ 0 ] ) ;
if ( isalpha ( V_38 [ 0 ] ) ) {
if ( V_38 [ 0 ] == V_45 )
V_42 -> V_46 = 0 ;
else
V_42 -> V_47 = 0 ;
}
} else {
V_42 -> V_46 = 0 ;
V_42 -> V_47 = 0 ;
}
return V_13 ;
}
static int F_28 ( struct V_16 * V_31 , struct V_18 * V_37 ,
T_1 * V_48 , int V_49 ,
unsigned char * V_50 , unsigned char * V_51 )
{
struct V_52 * V_53 = & F_11 ( V_31 -> V_54 ) -> V_55 ;
T_1 * V_56 , * V_57 , * V_58 , * V_59 ;
unsigned char V_60 [ 9 ] , V_61 [ 4 ] , V_38 [ 5 ] , * V_62 ;
unsigned char V_63 [ V_64 ] ;
int V_65 , V_66 ;
int V_67 = 0 , V_68 , V_69 , V_29 , V_70 , V_71 ;
int V_72 ;
struct V_41 V_73 , V_74 ;
V_72 = 1 ;
F_29 ( & V_73 ) ;
F_29 ( & V_74 ) ;
V_57 = V_58 = & V_48 [ V_49 ] ;
while ( -- V_57 >= V_48 ) {
if ( * V_57 == 0x002E ) {
if ( V_57 == V_58 - 1 ) {
V_67 = V_49 ;
V_57 = NULL ;
}
break;
}
}
if ( V_57 == V_48 - 1 ) {
V_67 = V_49 ;
V_57 = NULL ;
} else if ( V_57 ) {
V_59 = & V_48 [ 0 ] ;
while ( V_59 < V_57 ) {
if ( ! F_21 ( * V_59 ) )
break;
V_59 ++ ;
}
if ( V_59 != V_57 ) {
V_67 = V_57 - V_48 ;
V_57 ++ ;
} else {
V_67 = V_49 ;
V_57 = NULL ;
}
}
V_70 = 6 ;
V_71 = 2 ;
for ( V_69 = V_29 = 0 , V_62 = V_60 , V_56 = V_48 ; V_29 < V_67 ; V_29 ++ , V_56 ++ ) {
V_65 = F_26 ( V_37 , V_63 , sizeof( V_63 ) ,
V_56 , & V_73 ) ;
if ( V_65 == 0 )
continue;
if ( V_69 < 2 && ( V_69 + V_65 ) > 2 )
V_71 = V_69 ;
if ( V_69 < 6 && ( V_69 + V_65 ) > 6 )
V_70 = V_69 ;
for ( V_66 = 0 ; V_66 < V_65 ; V_66 ++ ) {
* V_62 ++ = V_63 [ V_66 ] ;
V_69 ++ ;
if ( V_69 >= 8 )
break;
}
if ( V_69 >= 8 ) {
if ( ( V_66 < V_65 - 1 ) || ( V_56 + 1 ) - V_48 < V_67 )
V_72 = 0 ;
break;
}
}
if ( V_69 == 0 ) {
return - V_30 ;
}
V_68 = 0 ;
if ( V_57 ) {
for ( V_62 = V_61 , V_56 = V_57 ; V_68 < 3 && V_56 < V_58 ; V_56 ++ ) {
V_65 = F_26 ( V_37 , V_63 , sizeof( V_63 ) ,
V_56 , & V_74 ) ;
if ( V_65 == 0 )
continue;
if ( ( V_68 + V_65 ) > 3 ) {
V_72 = 0 ;
break;
}
for ( V_66 = 0 ; V_66 < V_65 ; V_66 ++ ) {
* V_62 ++ = V_63 [ V_66 ] ;
V_68 ++ ;
}
if ( V_68 >= 3 ) {
if ( V_56 + 1 != V_58 )
V_72 = 0 ;
break;
}
}
}
V_61 [ V_68 ] = '\0' ;
V_60 [ V_69 ] = '\0' ;
if ( V_60 [ 0 ] == V_75 )
V_60 [ 0 ] = 0x05 ;
memset ( V_50 , ' ' , V_76 ) ;
memcpy ( V_50 , V_60 , V_69 ) ;
memcpy ( V_50 + 8 , V_61 , V_68 ) ;
* V_51 = 0 ;
if ( V_72 && V_73 . V_43 && V_74 . V_43 ) {
if ( F_23 ( V_31 , V_50 ) == 0 )
return - V_77 ;
if ( V_53 -> V_78 & V_79 ) {
return ( V_73 . V_47 && V_74 . V_47 ) ;
} else if ( V_53 -> V_78 & V_80 ) {
if ( ( V_73 . V_47 || V_73 . V_46 ) &&
( V_74 . V_47 || V_74 . V_46 ) ) {
if ( ! V_73 . V_47 && V_73 . V_46 )
* V_51 |= V_81 ;
if ( ! V_74 . V_47 && V_74 . V_46 )
* V_51 |= V_82 ;
return 1 ;
}
return 0 ;
} else {
F_30 () ;
}
}
if ( V_53 -> V_83 == 0 )
if ( F_23 ( V_31 , V_50 ) < 0 )
return 0 ;
if ( V_69 > 6 ) {
V_69 = V_70 ;
V_50 [ 7 ] = ' ' ;
}
V_50 [ V_69 ] = '~' ;
for ( V_29 = 1 ; V_29 < 10 ; V_29 ++ ) {
V_50 [ V_69 + 1 ] = V_29 + '0' ;
if ( F_23 ( V_31 , V_50 ) < 0 )
return 0 ;
}
V_29 = V_84 ;
V_67 = ( V_84 >> 16 ) & 0x7 ;
if ( V_69 > 2 ) {
V_69 = V_71 ;
V_50 [ 7 ] = ' ' ;
}
V_50 [ V_69 + 4 ] = '~' ;
V_50 [ V_69 + 5 ] = '1' + V_67 ;
while ( 1 ) {
snprintf ( V_38 , sizeof( V_38 ) , L_1 , V_29 & 0xffff ) ;
memcpy ( & V_50 [ V_69 ] , V_38 , 4 ) ;
if ( F_23 ( V_31 , V_50 ) < 0 )
break;
V_29 -= 11 ;
}
return 0 ;
}
static int
F_31 ( const unsigned char * V_14 , int V_13 , unsigned char * V_85 ,
int * V_86 , int * V_87 , int V_88 , int V_89 ,
struct V_18 * V_37 )
{
const unsigned char * V_56 ;
unsigned char V_90 ;
unsigned char * V_91 ;
unsigned int V_92 ;
int V_29 , V_93 , V_94 ;
int V_95 ;
if ( V_89 ) {
* V_87 = F_32 ( V_14 , V_13 , V_96 ,
( T_1 * ) V_85 , V_97 + 2 ) ;
if ( * V_87 < 0 )
return * V_87 ;
else if ( * V_87 > V_97 )
return - V_98 ;
V_91 = & V_85 [ * V_87 * sizeof( T_1 ) ] ;
} else {
for ( V_29 = 0 , V_56 = V_14 , V_91 = V_85 , * V_87 = 0 ;
V_29 < V_13 && * V_87 < V_97 ;
* V_87 += 1 ) {
if ( V_88 && ( * V_56 == ':' ) ) {
if ( V_29 > V_13 - 5 )
return - V_30 ;
V_92 = 0 ;
for ( V_93 = 1 ; V_93 < 5 ; V_93 ++ ) {
V_90 = V_56 [ V_93 ] ;
V_92 <<= 4 ;
if ( V_90 >= '0' && V_90 <= '9' ) {
V_92 |= V_90 - '0' ;
continue;
}
if ( V_90 >= 'a' && V_90 <= 'f' ) {
V_92 |= V_90 - ( 'a' - 10 ) ;
continue;
}
if ( V_90 >= 'A' && V_90 <= 'F' ) {
V_92 |= V_90 - ( 'A' - 10 ) ;
continue;
}
return - V_30 ;
}
* V_91 ++ = V_92 & 0xFF ;
* V_91 ++ = V_92 >> 8 ;
V_56 += 5 ;
V_29 += 5 ;
} else {
V_95 = V_37 -> V_99 ( V_56 , V_13 - V_29 ,
( T_1 * ) V_91 ) ;
if ( V_95 < 0 )
return - V_30 ;
V_56 += V_95 ;
V_29 += V_95 ;
V_91 += 2 ;
}
}
if ( V_29 < V_13 )
return - V_98 ;
}
* V_86 = * V_87 ;
if ( * V_87 % 13 ) {
* V_91 ++ = 0 ;
* V_91 ++ = 0 ;
* V_87 += 1 ;
if ( * V_87 % 13 ) {
V_94 = 13 - ( * V_87 % 13 ) ;
for ( V_29 = 0 ; V_29 < V_94 ; V_29 ++ ) {
* V_91 ++ = 0xff ;
* V_91 ++ = 0xff ;
}
* V_87 += V_94 ;
}
}
return 0 ;
}
static int F_33 ( struct V_16 * V_31 , const unsigned char * V_14 ,
int V_13 , int V_100 , int V_101 ,
struct V_102 * V_103 ,
struct V_104 * V_105 , int * V_106 )
{
struct V_107 * V_108 = F_11 ( V_31 -> V_54 ) ;
struct V_52 * V_53 = & V_108 -> V_55 ;
struct V_104 * V_109 ;
struct V_110 * V_111 ;
unsigned char V_112 , V_51 ;
unsigned char V_113 [ V_76 ] ;
T_1 * V_48 ;
T_2 time , V_114 ;
T_3 V_115 ;
int V_34 , V_49 , V_116 , V_29 ;
T_4 V_117 ;
* V_106 = 0 ;
V_48 = F_34 () ;
if ( ! V_48 )
return - V_118 ;
V_34 = F_31 ( V_14 , V_13 , ( unsigned char * ) V_48 , & V_49 , & V_116 ,
V_53 -> V_119 , V_53 -> V_89 , V_108 -> V_21 ) ;
if ( V_34 )
goto V_120;
V_34 = F_22 ( V_48 , V_49 ) ;
if ( V_34 )
goto V_120;
V_34 = F_28 ( V_31 , V_108 -> V_121 , V_48 , V_49 ,
V_113 , & V_51 ) ;
if ( V_34 < 0 )
goto V_120;
else if ( V_34 == 1 ) {
V_111 = (struct V_110 * ) V_105 ;
V_34 = 0 ;
goto V_78;
}
V_112 = F_35 ( V_113 ) ;
* V_106 = V_116 / 13 ;
for ( V_109 = V_105 , V_29 = * V_106 ; V_29 > 0 ; V_29 -- , V_109 ++ ) {
V_109 -> V_122 = V_29 ;
V_109 -> V_123 = V_124 ;
V_109 -> V_125 = 0 ;
V_109 -> V_126 = V_112 ;
V_109 -> V_127 = 0 ;
V_117 = ( V_29 - 1 ) * 13 ;
F_36 ( V_109 -> V_128 , V_48 + V_117 , 5 ) ;
F_36 ( V_109 -> V_129 , V_48 + V_117 + 5 , 6 ) ;
F_36 ( V_109 -> V_130 , V_48 + V_117 + 11 , 2 ) ;
}
V_105 [ 0 ] . V_122 |= 0x40 ;
V_111 = (struct V_110 * ) V_109 ;
V_78:
( * V_106 ) ++ ;
memcpy ( V_111 -> V_14 , V_113 , V_76 ) ;
V_111 -> V_123 = V_100 ? V_131 : V_132 ;
V_111 -> V_51 = V_51 ;
F_37 ( V_108 , V_103 , & time , & V_114 , & V_115 ) ;
V_111 -> time = V_111 -> ctime = time ;
V_111 -> V_114 = V_111 -> V_133 = V_111 -> V_134 = V_114 ;
V_111 -> V_135 = V_115 ;
F_38 ( V_111 , V_101 ) ;
V_111 -> V_136 = 0 ;
V_120:
F_39 ( V_48 ) ;
return V_34 ;
}
static int F_40 ( struct V_16 * V_31 , struct V_15 * V_137 , int V_100 ,
int V_101 , struct V_102 * V_103 ,
struct V_32 * V_33 )
{
struct V_104 * V_105 ;
unsigned int V_13 ;
int V_34 , V_106 ;
V_13 = F_7 ( V_137 ) ;
if ( V_13 == 0 )
return - V_35 ;
V_105 = F_41 ( sizeof( * V_105 ) * V_138 , V_139 ) ;
if ( V_105 == NULL )
return - V_118 ;
V_34 = F_33 ( V_31 , V_137 -> V_14 , V_13 , V_100 , V_101 , V_103 ,
V_105 , & V_106 ) ;
if ( V_34 )
goto V_140;
V_34 = F_42 ( V_31 , V_105 , V_106 , V_33 ) ;
if ( V_34 )
goto V_140;
V_31 -> V_141 = V_31 -> V_142 = V_31 -> V_143 = * V_103 ;
if ( F_43 ( V_31 ) )
( void ) F_44 ( V_31 ) ;
else
F_45 ( V_31 ) ;
V_140:
F_46 ( V_105 ) ;
return V_34 ;
}
static int F_47 ( struct V_16 * V_31 , struct V_15 * V_137 ,
struct V_32 * V_33 )
{
unsigned int V_13 = F_7 ( V_137 ) ;
if ( V_13 == 0 )
return - V_35 ;
return F_48 ( V_31 , V_137 -> V_14 , V_13 , V_33 ) ;
}
static int F_49 ( struct V_1 * V_1 )
{
return F_50 ( V_1 ) && ( V_1 -> V_144 & V_145 ) ;
}
static struct V_1 * F_51 ( struct V_16 * V_31 , struct V_1 * V_1 ,
unsigned int V_8 )
{
struct V_146 * V_147 = V_31 -> V_54 ;
struct V_32 V_33 ;
struct V_16 * V_16 ;
struct V_1 * V_148 ;
int V_34 ;
F_52 ( V_147 ) ;
V_34 = F_47 ( V_31 , & V_1 -> V_149 , & V_33 ) ;
if ( V_34 ) {
if ( V_34 == - V_35 ) {
V_16 = NULL ;
goto V_150;
}
goto error;
}
V_16 = F_53 ( V_147 , V_33 . V_111 , V_33 . V_151 ) ;
F_25 ( V_33 . V_36 ) ;
if ( F_54 ( V_16 ) ) {
V_34 = F_55 ( V_16 ) ;
goto error;
}
V_148 = F_56 ( V_16 ) ;
if ( V_148 && ! F_49 ( V_148 ) ) {
F_57 ( F_58 ( V_148 ) ) ;
if ( ! F_59 ( V_16 -> V_152 ) )
F_60 ( V_148 , V_1 ) ;
F_61 ( V_16 ) ;
F_62 ( V_147 ) ;
return V_148 ;
} else
F_63 ( V_148 ) ;
V_150:
F_62 ( V_147 ) ;
V_1 -> V_4 = V_1 -> V_5 -> V_6 -> V_7 ;
V_1 = F_64 ( V_16 , V_1 ) ;
if ( V_1 )
V_1 -> V_4 = V_1 -> V_5 -> V_6 -> V_7 ;
return V_1 ;
error:
F_62 ( V_147 ) ;
return F_65 ( V_34 ) ;
}
static int F_66 ( struct V_16 * V_31 , struct V_1 * V_1 , T_5 V_153 ,
bool V_154 )
{
struct V_146 * V_147 = V_31 -> V_54 ;
struct V_16 * V_16 ;
struct V_32 V_33 ;
struct V_102 V_103 ;
int V_34 ;
F_52 ( V_147 ) ;
V_103 = V_155 ;
V_34 = F_40 ( V_31 , & V_1 -> V_149 , 0 , 0 , & V_103 , & V_33 ) ;
if ( V_34 )
goto V_150;
V_31 -> V_7 ++ ;
V_16 = F_53 ( V_147 , V_33 . V_111 , V_33 . V_151 ) ;
F_25 ( V_33 . V_36 ) ;
if ( F_54 ( V_16 ) ) {
V_34 = F_55 ( V_16 ) ;
goto V_150;
}
V_16 -> V_7 ++ ;
V_16 -> V_142 = V_16 -> V_143 = V_16 -> V_141 = V_103 ;
V_1 -> V_4 = V_1 -> V_5 -> V_6 -> V_7 ;
F_67 ( V_1 , V_16 ) ;
V_150:
F_62 ( V_147 ) ;
return V_34 ;
}
static int F_68 ( struct V_16 * V_31 , struct V_1 * V_1 )
{
struct V_16 * V_16 = V_1 -> V_6 ;
struct V_146 * V_147 = V_31 -> V_54 ;
struct V_32 V_33 ;
int V_34 ;
F_52 ( V_147 ) ;
V_34 = F_69 ( V_16 ) ;
if ( V_34 )
goto V_150;
V_34 = F_47 ( V_31 , & V_1 -> V_149 , & V_33 ) ;
if ( V_34 )
goto V_150;
V_34 = F_70 ( V_31 , & V_33 ) ;
if ( V_34 )
goto V_150;
F_71 ( V_31 ) ;
F_72 ( V_16 ) ;
V_16 -> V_142 = V_16 -> V_143 = V_155 ;
F_73 ( V_16 ) ;
V_150:
F_62 ( V_147 ) ;
return V_34 ;
}
static int F_74 ( struct V_16 * V_31 , struct V_1 * V_1 )
{
struct V_16 * V_16 = V_1 -> V_6 ;
struct V_146 * V_147 = V_31 -> V_54 ;
struct V_32 V_33 ;
int V_34 ;
F_52 ( V_147 ) ;
V_34 = F_47 ( V_31 , & V_1 -> V_149 , & V_33 ) ;
if ( V_34 )
goto V_150;
V_34 = F_70 ( V_31 , & V_33 ) ;
if ( V_34 )
goto V_150;
F_72 ( V_16 ) ;
V_16 -> V_142 = V_16 -> V_143 = V_155 ;
F_73 ( V_16 ) ;
V_150:
F_62 ( V_147 ) ;
return V_34 ;
}
static int F_75 ( struct V_16 * V_31 , struct V_1 * V_1 , T_5 V_153 )
{
struct V_146 * V_147 = V_31 -> V_54 ;
struct V_16 * V_16 ;
struct V_32 V_33 ;
struct V_102 V_103 ;
int V_34 , V_101 ;
F_52 ( V_147 ) ;
V_103 = V_155 ;
V_101 = F_76 ( V_31 , & V_103 ) ;
if ( V_101 < 0 ) {
V_34 = V_101 ;
goto V_150;
}
V_34 = F_40 ( V_31 , & V_1 -> V_149 , 1 , V_101 , & V_103 , & V_33 ) ;
if ( V_34 )
goto V_120;
V_31 -> V_7 ++ ;
F_77 ( V_31 ) ;
V_16 = F_53 ( V_147 , V_33 . V_111 , V_33 . V_151 ) ;
F_25 ( V_33 . V_36 ) ;
if ( F_54 ( V_16 ) ) {
V_34 = F_55 ( V_16 ) ;
goto V_150;
}
V_16 -> V_7 ++ ;
F_78 ( V_16 , 2 ) ;
V_16 -> V_142 = V_16 -> V_143 = V_16 -> V_141 = V_103 ;
V_1 -> V_4 = V_1 -> V_5 -> V_6 -> V_7 ;
F_67 ( V_1 , V_16 ) ;
F_62 ( V_147 ) ;
return 0 ;
V_120:
F_79 ( V_31 , V_101 ) ;
V_150:
F_62 ( V_147 ) ;
return V_34 ;
}
static int F_80 ( struct V_16 * V_156 , struct V_1 * V_157 ,
struct V_16 * V_158 , struct V_1 * V_159 )
{
struct V_160 * V_161 ;
struct V_110 * V_162 ;
struct V_16 * V_163 , * V_164 ;
struct V_32 V_165 , V_33 ;
struct V_102 V_103 ;
T_4 V_166 , V_167 ;
int V_34 , V_100 , V_168 , V_169 = 0 ;
struct V_146 * V_147 = V_156 -> V_54 ;
V_165 . V_36 = V_33 . V_36 = V_161 = NULL ;
V_163 = V_157 -> V_6 ;
V_164 = V_159 -> V_6 ;
F_52 ( V_147 ) ;
V_34 = F_47 ( V_156 , & V_157 -> V_149 , & V_165 ) ;
if ( V_34 )
goto V_150;
V_100 = F_59 ( V_163 -> V_152 ) ;
V_168 = ( V_100 && V_156 != V_158 ) ;
if ( V_168 ) {
if ( F_81 ( V_163 , & V_161 , & V_162 ,
& V_166 ) < 0 ) {
V_34 = - V_170 ;
goto V_150;
}
}
V_103 = V_155 ;
if ( V_164 ) {
if ( V_100 ) {
V_34 = F_69 ( V_164 ) ;
if ( V_34 )
goto V_150;
}
V_167 = F_82 ( V_164 ) -> V_151 ;
F_73 ( V_164 ) ;
} else {
V_34 = F_40 ( V_158 , & V_159 -> V_149 , V_100 , 0 ,
& V_103 , & V_33 ) ;
if ( V_34 )
goto V_150;
V_167 = V_33 . V_151 ;
}
V_158 -> V_7 ++ ;
F_73 ( V_163 ) ;
F_83 ( V_163 , V_167 ) ;
if ( F_43 ( V_158 ) ) {
V_34 = F_44 ( V_163 ) ;
if ( V_34 )
goto V_171;
} else
F_45 ( V_163 ) ;
if ( V_168 ) {
F_38 ( V_162 , F_82 ( V_158 ) -> V_172 ) ;
F_84 ( V_161 , V_163 ) ;
if ( F_43 ( V_158 ) ) {
V_34 = F_85 ( V_161 ) ;
if ( V_34 )
goto V_173;
}
F_71 ( V_156 ) ;
if ( ! V_164 )
F_77 ( V_158 ) ;
}
V_34 = F_70 ( V_156 , & V_165 ) ;
V_165 . V_36 = NULL ;
if ( V_34 )
goto V_173;
V_156 -> V_7 ++ ;
V_156 -> V_141 = V_156 -> V_142 = V_103 ;
if ( F_43 ( V_156 ) )
( void ) F_44 ( V_156 ) ;
else
F_45 ( V_156 ) ;
if ( V_164 ) {
F_71 ( V_164 ) ;
if ( V_100 )
F_71 ( V_164 ) ;
V_164 -> V_141 = V_103 ;
}
V_150:
F_25 ( V_33 . V_36 ) ;
F_25 ( V_161 ) ;
F_25 ( V_165 . V_36 ) ;
F_62 ( V_147 ) ;
return V_34 ;
V_173:
V_169 = 1 ;
if ( V_168 ) {
F_38 ( V_162 , F_82 ( V_156 ) -> V_172 ) ;
F_84 ( V_161 , V_163 ) ;
V_169 |= F_85 ( V_161 ) ;
}
V_171:
F_73 ( V_163 ) ;
F_83 ( V_163 , V_165 . V_151 ) ;
if ( V_164 ) {
F_83 ( V_164 , V_167 ) ;
if ( V_169 )
V_169 |= F_44 ( V_164 ) ;
} else {
int V_174 = F_70 ( V_158 , & V_33 ) ;
if ( V_169 )
V_169 |= V_174 ;
V_33 . V_36 = NULL ;
}
if ( V_169 < 0 ) {
F_86 ( V_158 -> V_54 ,
L_2 ,
V_175 , V_33 . V_151 ) ;
}
goto V_150;
}
static void F_87 ( struct V_146 * V_147 )
{
F_11 ( V_147 ) -> V_176 = & V_177 ;
if ( F_11 ( V_147 ) -> V_55 . V_178 != 's' )
V_147 -> V_179 = & V_180 ;
else
V_147 -> V_179 = & V_181 ;
}
static int F_88 ( struct V_146 * V_147 , void * V_182 , int V_183 )
{
return F_89 ( V_147 , V_182 , V_183 , 1 , F_87 ) ;
}
static struct V_1 * F_90 ( struct V_184 * V_185 ,
int V_8 , const char * V_186 ,
void * V_182 )
{
return F_91 ( V_185 , V_8 , V_186 , V_182 , F_88 ) ;
}
static int T_6 F_92 ( void )
{
return F_93 ( & V_187 ) ;
}
static void T_7 F_94 ( void )
{
F_95 ( & V_187 ) ;
}
