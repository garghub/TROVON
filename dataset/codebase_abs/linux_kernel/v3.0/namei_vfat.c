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
if ( ! ( V_9 -> V_10 & ( V_13 | V_14 ) ) ) {
if ( V_9 -> V_10 & ( V_15 | V_16 ) )
return 0 ;
}
return F_1 ( V_1 ) ;
}
static unsigned int F_6 ( unsigned int V_17 , const char * V_18 )
{
while ( V_17 && V_18 [ V_17 - 1 ] == '.' )
V_17 -- ;
return V_17 ;
}
static unsigned int F_7 ( const struct V_19 * V_19 )
{
return F_6 ( V_19 -> V_17 , V_19 -> V_18 ) ;
}
static int F_8 ( const struct V_1 * V_1 , const struct V_20 * V_20 ,
struct V_19 * V_19 )
{
V_19 -> V_21 = F_9 ( V_19 -> V_18 , F_7 ( V_19 ) ) ;
return 0 ;
}
static int F_10 ( const struct V_1 * V_1 , const struct V_20 * V_20 ,
struct V_19 * V_19 )
{
struct V_22 * V_23 = F_11 ( V_1 -> V_24 ) -> V_25 ;
const unsigned char * V_18 ;
unsigned int V_17 ;
unsigned long V_21 ;
V_18 = V_19 -> V_18 ;
V_17 = F_7 ( V_19 ) ;
V_21 = F_12 () ;
while ( V_17 -- )
V_21 = F_13 ( F_14 ( V_23 , * V_18 ++ ) , V_21 ) ;
V_19 -> V_21 = F_15 ( V_21 ) ;
return 0 ;
}
static int F_16 ( const struct V_1 * V_26 , const struct V_20 * V_27 ,
const struct V_1 * V_1 , const struct V_20 * V_20 ,
unsigned int V_17 , const char * V_28 , const struct V_19 * V_18 )
{
struct V_22 * V_23 = F_11 ( V_26 -> V_24 ) -> V_25 ;
unsigned int V_29 , V_30 ;
V_29 = F_7 ( V_18 ) ;
V_30 = F_6 ( V_17 , V_28 ) ;
if ( V_29 == V_30 ) {
if ( F_17 ( V_23 , V_18 -> V_18 , V_28 , V_29 ) == 0 )
return 0 ;
}
return 1 ;
}
static int F_18 ( const struct V_1 * V_26 , const struct V_20 * V_27 ,
const struct V_1 * V_1 , const struct V_20 * V_20 ,
unsigned int V_17 , const char * V_28 , const struct V_19 * V_18 )
{
unsigned int V_29 , V_30 ;
V_29 = F_7 ( V_18 ) ;
V_30 = F_6 ( V_17 , V_28 ) ;
if ( V_29 == V_30 ) {
if ( strncmp ( V_18 -> V_18 , V_28 , V_29 ) == 0 )
return 0 ;
}
return 1 ;
}
static inline T_1 F_19 ( T_1 V_31 )
{
return ( V_31 < 0x0020 )
|| ( V_31 == '*' ) || ( V_31 == '?' ) || ( V_31 == '<' ) || ( V_31 == '>' )
|| ( V_31 == '|' ) || ( V_31 == '"' ) || ( V_31 == ':' ) || ( V_31 == '/' )
|| ( V_31 == '\\' ) ;
}
static inline T_1 F_20 ( T_1 V_31 )
{
return ( V_31 == '[' ) || ( V_31 == ']' ) || ( V_31 == ';' ) || ( V_31 == ',' )
|| ( V_31 == '+' ) || ( V_31 == '=' ) ;
}
static T_1 F_21 ( T_1 V_31 )
{
return ( V_31 == '.' ) || ( V_31 == ' ' ) ;
}
static inline int F_22 ( const T_1 * V_32 , int V_17 )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < V_17 ; V_33 ++ )
if ( F_19 ( V_32 [ V_33 ] ) )
return - V_34 ;
if ( V_32 [ V_33 - 1 ] == ' ' )
return - V_34 ;
return 0 ;
}
static int F_23 ( struct V_20 * V_35 , unsigned char * V_18 )
{
struct V_36 V_37 ;
int V_38 = F_24 ( V_35 , V_18 , & V_37 ) ;
if ( V_38 )
return - V_39 ;
F_25 ( V_37 . V_40 ) ;
return 0 ;
}
static inline int F_26 ( struct V_22 * V_41 ,
unsigned char * V_42 , int V_43 ,
T_1 * V_44 , struct V_45 * V_46 )
{
int V_17 ;
if ( F_21 ( * V_44 ) ) {
V_46 -> V_47 = 0 ;
return 0 ;
}
if ( F_20 ( * V_44 ) ) {
V_46 -> V_47 = 0 ;
V_42 [ 0 ] = '_' ;
return 1 ;
}
V_17 = V_41 -> V_48 ( * V_44 , V_42 , V_43 ) ;
if ( V_17 <= 0 ) {
V_46 -> V_47 = 0 ;
V_42 [ 0 ] = '_' ;
V_17 = 1 ;
} else if ( V_17 == 1 ) {
unsigned char V_49 = V_42 [ 0 ] ;
if ( V_42 [ 0 ] >= 0x7F ) {
V_46 -> V_50 = 0 ;
V_46 -> V_51 = 0 ;
}
V_42 [ 0 ] = F_27 ( V_41 , V_42 [ 0 ] ) ;
if ( isalpha ( V_42 [ 0 ] ) ) {
if ( V_42 [ 0 ] == V_49 )
V_46 -> V_50 = 0 ;
else
V_46 -> V_51 = 0 ;
}
} else {
V_46 -> V_50 = 0 ;
V_46 -> V_51 = 0 ;
}
return V_17 ;
}
static int F_28 ( struct V_20 * V_35 , struct V_22 * V_41 ,
T_1 * V_52 , int V_53 ,
unsigned char * V_54 , unsigned char * V_55 )
{
struct V_56 * V_57 = & F_11 ( V_35 -> V_58 ) -> V_59 ;
T_1 * V_60 , * V_61 , * V_62 , * V_63 ;
unsigned char V_64 [ 9 ] , V_65 [ 4 ] , V_42 [ 5 ] , * V_66 ;
unsigned char V_67 [ V_68 ] ;
int V_69 , V_70 ;
int V_71 = 0 , V_72 , V_73 , V_33 , V_74 , V_75 ;
int V_76 ;
struct V_45 V_77 , V_78 ;
V_76 = 1 ;
F_29 ( & V_77 ) ;
F_29 ( & V_78 ) ;
V_61 = V_62 = & V_52 [ V_53 ] ;
while ( -- V_61 >= V_52 ) {
if ( * V_61 == 0x002E ) {
if ( V_61 == V_62 - 1 ) {
V_71 = V_53 ;
V_61 = NULL ;
}
break;
}
}
if ( V_61 == V_52 - 1 ) {
V_71 = V_53 ;
V_61 = NULL ;
} else if ( V_61 ) {
V_63 = & V_52 [ 0 ] ;
while ( V_63 < V_61 ) {
if ( ! F_21 ( * V_63 ) )
break;
V_63 ++ ;
}
if ( V_63 != V_61 ) {
V_71 = V_61 - V_52 ;
V_61 ++ ;
} else {
V_71 = V_53 ;
V_61 = NULL ;
}
}
V_74 = 6 ;
V_75 = 2 ;
for ( V_73 = V_33 = 0 , V_66 = V_64 , V_60 = V_52 ; V_33 < V_71 ; V_33 ++ , V_60 ++ ) {
V_69 = F_26 ( V_41 , V_67 , sizeof( V_67 ) ,
V_60 , & V_77 ) ;
if ( V_69 == 0 )
continue;
if ( V_73 < 2 && ( V_73 + V_69 ) > 2 )
V_75 = V_73 ;
if ( V_73 < 6 && ( V_73 + V_69 ) > 6 )
V_74 = V_73 ;
for ( V_70 = 0 ; V_70 < V_69 ; V_70 ++ ) {
* V_66 ++ = V_67 [ V_70 ] ;
V_73 ++ ;
if ( V_73 >= 8 )
break;
}
if ( V_73 >= 8 ) {
if ( ( V_70 < V_69 - 1 ) || ( V_60 + 1 ) - V_52 < V_71 )
V_76 = 0 ;
break;
}
}
if ( V_73 == 0 ) {
return - V_34 ;
}
V_72 = 0 ;
if ( V_61 ) {
for ( V_66 = V_65 , V_60 = V_61 ; V_72 < 3 && V_60 < V_62 ; V_60 ++ ) {
V_69 = F_26 ( V_41 , V_67 , sizeof( V_67 ) ,
V_60 , & V_78 ) ;
if ( V_69 == 0 )
continue;
if ( ( V_72 + V_69 ) > 3 ) {
V_76 = 0 ;
break;
}
for ( V_70 = 0 ; V_70 < V_69 ; V_70 ++ ) {
* V_66 ++ = V_67 [ V_70 ] ;
V_72 ++ ;
}
if ( V_72 >= 3 ) {
if ( V_60 + 1 != V_62 )
V_76 = 0 ;
break;
}
}
}
V_65 [ V_72 ] = '\0' ;
V_64 [ V_73 ] = '\0' ;
if ( V_64 [ 0 ] == V_79 )
V_64 [ 0 ] = 0x05 ;
memset ( V_54 , ' ' , V_80 ) ;
memcpy ( V_54 , V_64 , V_73 ) ;
memcpy ( V_54 + 8 , V_65 , V_72 ) ;
* V_55 = 0 ;
if ( V_76 && V_77 . V_47 && V_78 . V_47 ) {
if ( F_23 ( V_35 , V_54 ) == 0 )
return - V_81 ;
if ( V_57 -> V_82 & V_83 ) {
return ( V_77 . V_51 && V_78 . V_51 ) ;
} else if ( V_57 -> V_82 & V_84 ) {
if ( ( V_77 . V_51 || V_77 . V_50 ) &&
( V_78 . V_51 || V_78 . V_50 ) ) {
if ( ! V_77 . V_51 && V_77 . V_50 )
* V_55 |= V_85 ;
if ( ! V_78 . V_51 && V_78 . V_50 )
* V_55 |= V_86 ;
return 1 ;
}
return 0 ;
} else {
F_30 () ;
}
}
if ( V_57 -> V_87 == 0 )
if ( F_23 ( V_35 , V_54 ) < 0 )
return 0 ;
if ( V_73 > 6 ) {
V_73 = V_74 ;
V_54 [ 7 ] = ' ' ;
}
V_54 [ V_73 ] = '~' ;
for ( V_33 = 1 ; V_33 < 10 ; V_33 ++ ) {
V_54 [ V_73 + 1 ] = V_33 + '0' ;
if ( F_23 ( V_35 , V_54 ) < 0 )
return 0 ;
}
V_33 = V_88 ;
V_71 = ( V_88 >> 16 ) & 0x7 ;
if ( V_73 > 2 ) {
V_73 = V_75 ;
V_54 [ 7 ] = ' ' ;
}
V_54 [ V_73 + 4 ] = '~' ;
V_54 [ V_73 + 5 ] = '1' + V_71 ;
while ( 1 ) {
snprintf ( V_42 , sizeof( V_42 ) , L_1 , V_33 & 0xffff ) ;
memcpy ( & V_54 [ V_73 ] , V_42 , 4 ) ;
if ( F_23 ( V_35 , V_54 ) < 0 )
break;
V_33 -= 11 ;
}
return 0 ;
}
static int
F_31 ( const unsigned char * V_18 , int V_17 , unsigned char * V_89 ,
int * V_90 , int * V_91 , int V_92 , int V_93 ,
struct V_22 * V_41 )
{
const unsigned char * V_60 ;
unsigned char V_94 ;
unsigned char * V_95 ;
unsigned int V_96 ;
int V_33 , V_97 , V_98 ;
int V_99 ;
if ( V_93 ) {
* V_91 = F_32 ( V_18 , V_17 , ( T_1 * ) V_89 ) ;
if ( * V_91 < 0 )
return * V_91 ;
else if ( * V_91 > V_100 )
return - V_101 ;
V_95 = & V_89 [ * V_91 * sizeof( T_1 ) ] ;
} else {
if ( V_41 ) {
for ( V_33 = 0 , V_60 = V_18 , V_95 = V_89 , * V_91 = 0 ;
V_33 < V_17 && * V_91 <= V_100 ;
* V_91 += 1 )
{
if ( V_92 && ( * V_60 == ':' ) ) {
if ( V_33 > V_17 - 5 )
return - V_34 ;
V_96 = 0 ;
for ( V_97 = 1 ; V_97 < 5 ; V_97 ++ ) {
V_94 = V_60 [ V_97 ] ;
V_96 <<= 4 ;
if ( V_94 >= '0' && V_94 <= '9' ) {
V_96 |= V_94 - '0' ;
continue;
}
if ( V_94 >= 'a' && V_94 <= 'f' ) {
V_96 |= V_94 - ( 'a' - 10 ) ;
continue;
}
if ( V_94 >= 'A' && V_94 <= 'F' ) {
V_96 |= V_94 - ( 'A' - 10 ) ;
continue;
}
return - V_34 ;
}
* V_95 ++ = V_96 & 0xFF ;
* V_95 ++ = V_96 >> 8 ;
V_60 += 5 ;
V_33 += 5 ;
} else {
if ( ( V_99 = V_41 -> V_102 ( V_60 , V_17 - V_33 , ( T_1 * ) V_95 ) ) < 0 )
return - V_34 ;
V_60 += V_99 ;
V_33 += V_99 ;
V_95 += 2 ;
}
}
if ( V_33 < V_17 )
return - V_101 ;
} else {
for ( V_33 = 0 , V_60 = V_18 , V_95 = V_89 , * V_91 = 0 ;
V_33 < V_17 && * V_91 <= V_100 ;
V_33 ++ , * V_91 += 1 )
{
* V_95 ++ = * V_60 ++ ;
* V_95 ++ = 0 ;
}
if ( V_33 < V_17 )
return - V_101 ;
}
}
* V_90 = * V_91 ;
if ( * V_91 % 13 ) {
* V_95 ++ = 0 ;
* V_95 ++ = 0 ;
* V_91 += 1 ;
if ( * V_91 % 13 ) {
V_98 = 13 - ( * V_91 % 13 ) ;
for ( V_33 = 0 ; V_33 < V_98 ; V_33 ++ ) {
* V_95 ++ = 0xff ;
* V_95 ++ = 0xff ;
}
* V_91 += V_98 ;
}
}
return 0 ;
}
static int F_33 ( struct V_20 * V_35 , const unsigned char * V_18 ,
int V_17 , int V_103 , int V_104 ,
struct V_105 * V_106 ,
struct V_107 * V_108 , int * V_109 )
{
struct V_110 * V_111 = F_11 ( V_35 -> V_58 ) ;
struct V_56 * V_57 = & V_111 -> V_59 ;
struct V_107 * V_112 ;
struct V_113 * V_114 ;
unsigned char V_115 , V_55 ;
unsigned char V_116 [ V_80 ] ;
T_1 * V_52 ;
T_2 time , V_117 ;
T_3 V_118 ;
int V_38 , V_53 , V_119 , V_33 ;
T_4 V_120 ;
* V_109 = 0 ;
V_52 = F_34 () ;
if ( ! V_52 )
return - V_121 ;
V_38 = F_31 ( V_18 , V_17 , ( unsigned char * ) V_52 , & V_53 , & V_119 ,
V_57 -> V_122 , V_57 -> V_93 , V_111 -> V_25 ) ;
if ( V_38 )
goto V_123;
V_38 = F_22 ( V_52 , V_53 ) ;
if ( V_38 )
goto V_123;
V_38 = F_28 ( V_35 , V_111 -> V_124 , V_52 , V_53 ,
V_116 , & V_55 ) ;
if ( V_38 < 0 )
goto V_123;
else if ( V_38 == 1 ) {
V_114 = (struct V_113 * ) V_108 ;
V_38 = 0 ;
goto V_82;
}
V_115 = F_35 ( V_116 ) ;
* V_109 = V_119 / 13 ;
for ( V_112 = V_108 , V_33 = * V_109 ; V_33 > 0 ; V_33 -- , V_112 ++ ) {
V_112 -> V_125 = V_33 ;
V_112 -> V_126 = V_127 ;
V_112 -> V_128 = 0 ;
V_112 -> V_129 = V_115 ;
V_112 -> V_130 = 0 ;
V_120 = ( V_33 - 1 ) * 13 ;
F_36 ( V_112 -> V_131 , V_52 + V_120 , 5 ) ;
F_36 ( V_112 -> V_132 , V_52 + V_120 + 5 , 6 ) ;
F_36 ( V_112 -> V_133 , V_52 + V_120 + 11 , 2 ) ;
}
V_108 [ 0 ] . V_125 |= 0x40 ;
V_114 = (struct V_113 * ) V_112 ;
V_82:
( * V_109 ) ++ ;
memcpy ( V_114 -> V_18 , V_116 , V_80 ) ;
V_114 -> V_126 = V_103 ? V_134 : V_135 ;
V_114 -> V_55 = V_55 ;
F_37 ( V_111 , V_106 , & time , & V_117 , & V_118 ) ;
V_114 -> time = V_114 -> ctime = time ;
V_114 -> V_117 = V_114 -> V_136 = V_114 -> V_137 = V_117 ;
V_114 -> V_138 = V_118 ;
V_114 -> V_130 = F_38 ( V_104 ) ;
V_114 -> V_139 = F_38 ( V_104 >> 16 ) ;
V_114 -> V_140 = 0 ;
V_123:
F_39 ( V_52 ) ;
return V_38 ;
}
static int F_40 ( struct V_20 * V_35 , struct V_19 * V_141 , int V_103 ,
int V_104 , struct V_105 * V_106 ,
struct V_36 * V_37 )
{
struct V_107 * V_108 ;
unsigned int V_17 ;
int V_38 , V_109 ;
V_17 = F_7 ( V_141 ) ;
if ( V_17 == 0 )
return - V_39 ;
V_108 = F_41 ( sizeof( * V_108 ) * V_142 , V_143 ) ;
if ( V_108 == NULL )
return - V_121 ;
V_38 = F_33 ( V_35 , V_141 -> V_18 , V_17 , V_103 , V_104 , V_106 ,
V_108 , & V_109 ) ;
if ( V_38 )
goto V_144;
V_38 = F_42 ( V_35 , V_108 , V_109 , V_37 ) ;
if ( V_38 )
goto V_144;
V_35 -> V_145 = V_35 -> V_146 = V_35 -> V_147 = * V_106 ;
if ( F_43 ( V_35 ) )
( void ) F_44 ( V_35 ) ;
else
F_45 ( V_35 ) ;
V_144:
F_46 ( V_108 ) ;
return V_38 ;
}
static int F_47 ( struct V_20 * V_35 , struct V_19 * V_141 ,
struct V_36 * V_37 )
{
unsigned int V_17 = F_7 ( V_141 ) ;
if ( V_17 == 0 )
return - V_39 ;
return F_48 ( V_35 , V_141 -> V_18 , V_17 , V_37 ) ;
}
static int F_49 ( struct V_1 * V_1 )
{
return F_50 ( V_1 ) && ( V_1 -> V_148 & V_149 ) ;
}
static struct V_1 * F_51 ( struct V_20 * V_35 , struct V_1 * V_1 ,
struct V_8 * V_9 )
{
struct V_150 * V_151 = V_35 -> V_58 ;
struct V_36 V_37 ;
struct V_20 * V_20 ;
struct V_1 * V_152 ;
int V_38 ;
F_52 ( V_151 ) ;
V_38 = F_47 ( V_35 , & V_1 -> V_153 , & V_37 ) ;
if ( V_38 ) {
if ( V_38 == - V_39 ) {
V_20 = NULL ;
goto V_154;
}
goto error;
}
V_20 = F_53 ( V_151 , V_37 . V_114 , V_37 . V_155 ) ;
F_25 ( V_37 . V_40 ) ;
if ( F_54 ( V_20 ) ) {
V_38 = F_55 ( V_20 ) ;
goto error;
}
V_152 = F_56 ( V_20 ) ;
if ( V_152 && ! F_49 ( V_152 ) ) {
F_57 ( F_58 ( V_152 ) ) ;
if ( ! F_59 ( V_20 -> V_156 ) )
F_60 ( V_152 , V_1 ) ;
F_61 ( V_20 ) ;
F_62 ( V_151 ) ;
return V_152 ;
} else
F_63 ( V_152 ) ;
V_154:
F_62 ( V_151 ) ;
V_1 -> V_4 = V_1 -> V_5 -> V_6 -> V_7 ;
V_1 = F_64 ( V_20 , V_1 ) ;
if ( V_1 )
V_1 -> V_4 = V_1 -> V_5 -> V_6 -> V_7 ;
return V_1 ;
error:
F_62 ( V_151 ) ;
return F_65 ( V_38 ) ;
}
static int F_66 ( struct V_20 * V_35 , struct V_1 * V_1 , int V_157 ,
struct V_8 * V_9 )
{
struct V_150 * V_151 = V_35 -> V_58 ;
struct V_20 * V_20 ;
struct V_36 V_37 ;
struct V_105 V_106 ;
int V_38 ;
F_52 ( V_151 ) ;
V_106 = V_158 ;
V_38 = F_40 ( V_35 , & V_1 -> V_153 , 0 , 0 , & V_106 , & V_37 ) ;
if ( V_38 )
goto V_154;
V_35 -> V_7 ++ ;
V_20 = F_53 ( V_151 , V_37 . V_114 , V_37 . V_155 ) ;
F_25 ( V_37 . V_40 ) ;
if ( F_54 ( V_20 ) ) {
V_38 = F_55 ( V_20 ) ;
goto V_154;
}
V_20 -> V_7 ++ ;
V_20 -> V_146 = V_20 -> V_147 = V_20 -> V_145 = V_106 ;
V_1 -> V_4 = V_1 -> V_5 -> V_6 -> V_7 ;
F_67 ( V_1 , V_20 ) ;
V_154:
F_62 ( V_151 ) ;
return V_38 ;
}
static int F_68 ( struct V_20 * V_35 , struct V_1 * V_1 )
{
struct V_20 * V_20 = V_1 -> V_6 ;
struct V_150 * V_151 = V_35 -> V_58 ;
struct V_36 V_37 ;
int V_38 ;
F_52 ( V_151 ) ;
V_38 = F_69 ( V_20 ) ;
if ( V_38 )
goto V_154;
V_38 = F_47 ( V_35 , & V_1 -> V_153 , & V_37 ) ;
if ( V_38 )
goto V_154;
V_38 = F_70 ( V_35 , & V_37 ) ;
if ( V_38 )
goto V_154;
F_71 ( V_35 ) ;
F_72 ( V_20 ) ;
V_20 -> V_146 = V_20 -> V_147 = V_158 ;
F_73 ( V_20 ) ;
V_154:
F_62 ( V_151 ) ;
return V_38 ;
}
static int F_74 ( struct V_20 * V_35 , struct V_1 * V_1 )
{
struct V_20 * V_20 = V_1 -> V_6 ;
struct V_150 * V_151 = V_35 -> V_58 ;
struct V_36 V_37 ;
int V_38 ;
F_52 ( V_151 ) ;
V_38 = F_47 ( V_35 , & V_1 -> V_153 , & V_37 ) ;
if ( V_38 )
goto V_154;
V_38 = F_70 ( V_35 , & V_37 ) ;
if ( V_38 )
goto V_154;
F_72 ( V_20 ) ;
V_20 -> V_146 = V_20 -> V_147 = V_158 ;
F_73 ( V_20 ) ;
V_154:
F_62 ( V_151 ) ;
return V_38 ;
}
static int F_75 ( struct V_20 * V_35 , struct V_1 * V_1 , int V_157 )
{
struct V_150 * V_151 = V_35 -> V_58 ;
struct V_20 * V_20 ;
struct V_36 V_37 ;
struct V_105 V_106 ;
int V_38 , V_104 ;
F_52 ( V_151 ) ;
V_106 = V_158 ;
V_104 = F_76 ( V_35 , & V_106 ) ;
if ( V_104 < 0 ) {
V_38 = V_104 ;
goto V_154;
}
V_38 = F_40 ( V_35 , & V_1 -> V_153 , 1 , V_104 , & V_106 , & V_37 ) ;
if ( V_38 )
goto V_123;
V_35 -> V_7 ++ ;
F_77 ( V_35 ) ;
V_20 = F_53 ( V_151 , V_37 . V_114 , V_37 . V_155 ) ;
F_25 ( V_37 . V_40 ) ;
if ( F_54 ( V_20 ) ) {
V_38 = F_55 ( V_20 ) ;
goto V_154;
}
V_20 -> V_7 ++ ;
V_20 -> V_159 = 2 ;
V_20 -> V_146 = V_20 -> V_147 = V_20 -> V_145 = V_106 ;
V_1 -> V_4 = V_1 -> V_5 -> V_6 -> V_7 ;
F_67 ( V_1 , V_20 ) ;
F_62 ( V_151 ) ;
return 0 ;
V_123:
F_78 ( V_35 , V_104 ) ;
V_154:
F_62 ( V_151 ) ;
return V_38 ;
}
static int F_79 ( struct V_20 * V_160 , struct V_1 * V_161 ,
struct V_20 * V_162 , struct V_1 * V_163 )
{
struct V_164 * V_165 ;
struct V_113 * V_166 ;
struct V_20 * V_167 , * V_168 ;
struct V_36 V_169 , V_37 ;
struct V_105 V_106 ;
T_4 V_170 , V_171 ;
int V_38 , V_103 , V_172 , V_173 = 0 ;
struct V_150 * V_151 = V_160 -> V_58 ;
V_169 . V_40 = V_37 . V_40 = V_165 = NULL ;
V_167 = V_161 -> V_6 ;
V_168 = V_163 -> V_6 ;
F_52 ( V_151 ) ;
V_38 = F_47 ( V_160 , & V_161 -> V_153 , & V_169 ) ;
if ( V_38 )
goto V_154;
V_103 = F_59 ( V_167 -> V_156 ) ;
V_172 = ( V_103 && V_160 != V_162 ) ;
if ( V_172 ) {
if ( F_80 ( V_167 , & V_165 , & V_166 ,
& V_170 ) < 0 ) {
V_38 = - V_174 ;
goto V_154;
}
}
V_106 = V_158 ;
if ( V_168 ) {
if ( V_103 ) {
V_38 = F_69 ( V_168 ) ;
if ( V_38 )
goto V_154;
}
V_171 = F_81 ( V_168 ) -> V_155 ;
F_73 ( V_168 ) ;
} else {
V_38 = F_40 ( V_162 , & V_163 -> V_153 , V_103 , 0 ,
& V_106 , & V_37 ) ;
if ( V_38 )
goto V_154;
V_171 = V_37 . V_155 ;
}
V_162 -> V_7 ++ ;
F_73 ( V_167 ) ;
F_82 ( V_167 , V_171 ) ;
if ( F_43 ( V_162 ) ) {
V_38 = F_44 ( V_167 ) ;
if ( V_38 )
goto V_175;
} else
F_45 ( V_167 ) ;
if ( V_172 ) {
int V_130 = F_81 ( V_162 ) -> V_176 ;
V_166 -> V_130 = F_38 ( V_130 ) ;
V_166 -> V_139 = F_38 ( V_130 >> 16 ) ;
F_83 ( V_165 , V_167 ) ;
if ( F_43 ( V_162 ) ) {
V_38 = F_84 ( V_165 ) ;
if ( V_38 )
goto V_177;
}
F_71 ( V_160 ) ;
if ( ! V_168 )
F_77 ( V_162 ) ;
}
V_38 = F_70 ( V_160 , & V_169 ) ;
V_169 . V_40 = NULL ;
if ( V_38 )
goto V_177;
V_160 -> V_7 ++ ;
V_160 -> V_145 = V_160 -> V_146 = V_106 ;
if ( F_43 ( V_160 ) )
( void ) F_44 ( V_160 ) ;
else
F_45 ( V_160 ) ;
if ( V_168 ) {
F_71 ( V_168 ) ;
if ( V_103 )
F_71 ( V_168 ) ;
V_168 -> V_145 = V_106 ;
}
V_154:
F_25 ( V_37 . V_40 ) ;
F_25 ( V_165 ) ;
F_25 ( V_169 . V_40 ) ;
F_62 ( V_151 ) ;
return V_38 ;
V_177:
V_173 = 1 ;
if ( V_172 ) {
int V_130 = F_81 ( V_160 ) -> V_176 ;
V_166 -> V_130 = F_38 ( V_130 ) ;
V_166 -> V_139 = F_38 ( V_130 >> 16 ) ;
F_83 ( V_165 , V_167 ) ;
V_173 |= F_84 ( V_165 ) ;
}
V_175:
F_73 ( V_167 ) ;
F_82 ( V_167 , V_169 . V_155 ) ;
if ( V_168 ) {
F_82 ( V_168 , V_171 ) ;
if ( V_173 )
V_173 |= F_44 ( V_168 ) ;
} else {
int V_178 = F_70 ( V_162 , & V_37 ) ;
if ( V_173 )
V_173 |= V_178 ;
V_37 . V_40 = NULL ;
}
if ( V_173 < 0 ) {
F_85 ( V_162 -> V_58 ,
L_2 ,
V_179 , V_37 . V_155 ) ;
}
goto V_154;
}
static void F_86 ( struct V_150 * V_151 )
{
F_11 ( V_151 ) -> V_180 = & V_181 ;
if ( F_11 ( V_151 ) -> V_59 . V_182 != 's' )
V_151 -> V_183 = & V_184 ;
else
V_151 -> V_183 = & V_185 ;
}
static int F_87 ( struct V_150 * V_151 , void * V_186 , int V_187 )
{
return F_88 ( V_151 , V_186 , V_187 , 1 , F_86 ) ;
}
static struct V_1 * F_89 ( struct V_188 * V_189 ,
int V_10 , const char * V_190 ,
void * V_186 )
{
return F_90 ( V_189 , V_10 , V_190 , V_186 , F_87 ) ;
}
static int T_5 F_91 ( void )
{
return F_92 ( & V_191 ) ;
}
static void T_6 F_93 ( void )
{
F_94 ( & V_191 ) ;
}
