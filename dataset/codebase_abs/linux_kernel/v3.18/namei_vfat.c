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
static int F_8 ( const struct V_1 * V_1 , struct V_15 * V_15 )
{
V_15 -> V_16 = F_9 ( V_15 -> V_14 , F_7 ( V_15 ) ) ;
return 0 ;
}
static int F_10 ( const struct V_1 * V_1 , struct V_15 * V_15 )
{
struct V_17 * V_18 = F_11 ( V_1 -> V_19 ) -> V_20 ;
const unsigned char * V_14 ;
unsigned int V_13 ;
unsigned long V_16 ;
V_14 = V_15 -> V_14 ;
V_13 = F_7 ( V_15 ) ;
V_16 = F_12 () ;
while ( V_13 -- )
V_16 = F_13 ( F_14 ( V_18 , * V_14 ++ ) , V_16 ) ;
V_15 -> V_16 = F_15 ( V_16 ) ;
return 0 ;
}
static int F_16 ( const struct V_1 * V_21 , const struct V_1 * V_1 ,
unsigned int V_13 , const char * V_22 , const struct V_15 * V_14 )
{
struct V_17 * V_18 = F_11 ( V_21 -> V_19 ) -> V_20 ;
unsigned int V_23 , V_24 ;
V_23 = F_7 ( V_14 ) ;
V_24 = F_6 ( V_13 , V_22 ) ;
if ( V_23 == V_24 ) {
if ( F_17 ( V_18 , V_14 -> V_14 , V_22 , V_23 ) == 0 )
return 0 ;
}
return 1 ;
}
static int F_18 ( const struct V_1 * V_21 , const struct V_1 * V_1 ,
unsigned int V_13 , const char * V_22 , const struct V_15 * V_14 )
{
unsigned int V_23 , V_24 ;
V_23 = F_7 ( V_14 ) ;
V_24 = F_6 ( V_13 , V_22 ) ;
if ( V_23 == V_24 ) {
if ( strncmp ( V_14 -> V_14 , V_22 , V_23 ) == 0 )
return 0 ;
}
return 1 ;
}
static inline T_1 F_19 ( T_1 V_25 )
{
return ( V_25 < 0x0020 )
|| ( V_25 == '*' ) || ( V_25 == '?' ) || ( V_25 == '<' ) || ( V_25 == '>' )
|| ( V_25 == '|' ) || ( V_25 == '"' ) || ( V_25 == ':' ) || ( V_25 == '/' )
|| ( V_25 == '\\' ) ;
}
static inline T_1 F_20 ( T_1 V_25 )
{
return ( V_25 == '[' ) || ( V_25 == ']' ) || ( V_25 == ';' ) || ( V_25 == ',' )
|| ( V_25 == '+' ) || ( V_25 == '=' ) ;
}
static T_1 F_21 ( T_1 V_25 )
{
return ( V_25 == '.' ) || ( V_25 == ' ' ) ;
}
static inline int F_22 ( const T_1 * V_26 , int V_13 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_13 ; V_27 ++ )
if ( F_19 ( V_26 [ V_27 ] ) )
return - V_28 ;
if ( V_26 [ V_27 - 1 ] == ' ' )
return - V_28 ;
return 0 ;
}
static int F_23 ( struct V_29 * V_30 , unsigned char * V_14 )
{
struct V_31 V_32 ;
int V_33 = F_24 ( V_30 , V_14 , & V_32 ) ;
if ( V_33 )
return - V_34 ;
F_25 ( V_32 . V_35 ) ;
return 0 ;
}
static inline int F_26 ( struct V_17 * V_36 ,
unsigned char * V_37 , int V_38 ,
T_1 * V_39 , struct V_40 * V_41 )
{
int V_13 ;
if ( F_21 ( * V_39 ) ) {
V_41 -> V_42 = 0 ;
return 0 ;
}
if ( F_20 ( * V_39 ) ) {
V_41 -> V_42 = 0 ;
V_37 [ 0 ] = '_' ;
return 1 ;
}
V_13 = V_36 -> V_43 ( * V_39 , V_37 , V_38 ) ;
if ( V_13 <= 0 ) {
V_41 -> V_42 = 0 ;
V_37 [ 0 ] = '_' ;
V_13 = 1 ;
} else if ( V_13 == 1 ) {
unsigned char V_44 = V_37 [ 0 ] ;
if ( V_37 [ 0 ] >= 0x7F ) {
V_41 -> V_45 = 0 ;
V_41 -> V_46 = 0 ;
}
V_37 [ 0 ] = F_27 ( V_36 , V_37 [ 0 ] ) ;
if ( isalpha ( V_37 [ 0 ] ) ) {
if ( V_37 [ 0 ] == V_44 )
V_41 -> V_45 = 0 ;
else
V_41 -> V_46 = 0 ;
}
} else {
V_41 -> V_45 = 0 ;
V_41 -> V_46 = 0 ;
}
return V_13 ;
}
static int F_28 ( struct V_29 * V_30 , struct V_17 * V_36 ,
T_1 * V_47 , int V_48 ,
unsigned char * V_49 , unsigned char * V_50 )
{
struct V_51 * V_52 = & F_11 ( V_30 -> V_53 ) -> V_54 ;
T_1 * V_55 , * V_56 , * V_57 , * V_58 ;
unsigned char V_59 [ 9 ] , V_60 [ 4 ] , V_37 [ 5 ] , * V_61 ;
unsigned char V_62 [ V_63 ] ;
int V_64 , V_65 ;
int V_66 = 0 , V_67 , V_68 , V_27 , V_69 , V_70 ;
int V_71 ;
struct V_40 V_72 , V_73 ;
V_71 = 1 ;
F_29 ( & V_72 ) ;
F_29 ( & V_73 ) ;
V_56 = V_57 = & V_47 [ V_48 ] ;
while ( -- V_56 >= V_47 ) {
if ( * V_56 == 0x002E ) {
if ( V_56 == V_57 - 1 ) {
V_66 = V_48 ;
V_56 = NULL ;
}
break;
}
}
if ( V_56 == V_47 - 1 ) {
V_66 = V_48 ;
V_56 = NULL ;
} else if ( V_56 ) {
V_58 = & V_47 [ 0 ] ;
while ( V_58 < V_56 ) {
if ( ! F_21 ( * V_58 ) )
break;
V_58 ++ ;
}
if ( V_58 != V_56 ) {
V_66 = V_56 - V_47 ;
V_56 ++ ;
} else {
V_66 = V_48 ;
V_56 = NULL ;
}
}
V_69 = 6 ;
V_70 = 2 ;
for ( V_68 = V_27 = 0 , V_61 = V_59 , V_55 = V_47 ; V_27 < V_66 ; V_27 ++ , V_55 ++ ) {
V_64 = F_26 ( V_36 , V_62 , sizeof( V_62 ) ,
V_55 , & V_72 ) ;
if ( V_64 == 0 )
continue;
if ( V_68 < 2 && ( V_68 + V_64 ) > 2 )
V_70 = V_68 ;
if ( V_68 < 6 && ( V_68 + V_64 ) > 6 )
V_69 = V_68 ;
for ( V_65 = 0 ; V_65 < V_64 ; V_65 ++ ) {
* V_61 ++ = V_62 [ V_65 ] ;
V_68 ++ ;
if ( V_68 >= 8 )
break;
}
if ( V_68 >= 8 ) {
if ( ( V_65 < V_64 - 1 ) || ( V_55 + 1 ) - V_47 < V_66 )
V_71 = 0 ;
break;
}
}
if ( V_68 == 0 ) {
return - V_28 ;
}
V_67 = 0 ;
if ( V_56 ) {
for ( V_61 = V_60 , V_55 = V_56 ; V_67 < 3 && V_55 < V_57 ; V_55 ++ ) {
V_64 = F_26 ( V_36 , V_62 , sizeof( V_62 ) ,
V_55 , & V_73 ) ;
if ( V_64 == 0 )
continue;
if ( ( V_67 + V_64 ) > 3 ) {
V_71 = 0 ;
break;
}
for ( V_65 = 0 ; V_65 < V_64 ; V_65 ++ ) {
* V_61 ++ = V_62 [ V_65 ] ;
V_67 ++ ;
}
if ( V_67 >= 3 ) {
if ( V_55 + 1 != V_57 )
V_71 = 0 ;
break;
}
}
}
V_60 [ V_67 ] = '\0' ;
V_59 [ V_68 ] = '\0' ;
if ( V_59 [ 0 ] == V_74 )
V_59 [ 0 ] = 0x05 ;
memset ( V_49 , ' ' , V_75 ) ;
memcpy ( V_49 , V_59 , V_68 ) ;
memcpy ( V_49 + 8 , V_60 , V_67 ) ;
* V_50 = 0 ;
if ( V_71 && V_72 . V_42 && V_73 . V_42 ) {
if ( F_23 ( V_30 , V_49 ) == 0 )
return - V_76 ;
if ( V_52 -> V_77 & V_78 ) {
return ( V_72 . V_46 && V_73 . V_46 ) ;
} else if ( V_52 -> V_77 & V_79 ) {
if ( ( V_72 . V_46 || V_72 . V_45 ) &&
( V_73 . V_46 || V_73 . V_45 ) ) {
if ( ! V_72 . V_46 && V_72 . V_45 )
* V_50 |= V_80 ;
if ( ! V_73 . V_46 && V_73 . V_45 )
* V_50 |= V_81 ;
return 1 ;
}
return 0 ;
} else {
F_30 () ;
}
}
if ( V_52 -> V_82 == 0 )
if ( F_23 ( V_30 , V_49 ) < 0 )
return 0 ;
if ( V_68 > 6 ) {
V_68 = V_69 ;
V_49 [ 7 ] = ' ' ;
}
V_49 [ V_68 ] = '~' ;
for ( V_27 = 1 ; V_27 < 10 ; V_27 ++ ) {
V_49 [ V_68 + 1 ] = V_27 + '0' ;
if ( F_23 ( V_30 , V_49 ) < 0 )
return 0 ;
}
V_27 = V_83 ;
V_66 = ( V_83 >> 16 ) & 0x7 ;
if ( V_68 > 2 ) {
V_68 = V_70 ;
V_49 [ 7 ] = ' ' ;
}
V_49 [ V_68 + 4 ] = '~' ;
V_49 [ V_68 + 5 ] = '1' + V_66 ;
while ( 1 ) {
snprintf ( V_37 , sizeof( V_37 ) , L_1 , V_27 & 0xffff ) ;
memcpy ( & V_49 [ V_68 ] , V_37 , 4 ) ;
if ( F_23 ( V_30 , V_49 ) < 0 )
break;
V_27 -= 11 ;
}
return 0 ;
}
static int
F_31 ( const unsigned char * V_14 , int V_13 , unsigned char * V_84 ,
int * V_85 , int * V_86 , int V_87 , int V_88 ,
struct V_17 * V_36 )
{
const unsigned char * V_55 ;
unsigned char V_89 ;
unsigned char * V_90 ;
unsigned int V_91 ;
int V_27 , V_92 , V_93 ;
int V_94 ;
if ( V_88 ) {
* V_86 = F_32 ( V_14 , V_13 , V_95 ,
( T_1 * ) V_84 , V_96 + 2 ) ;
if ( * V_86 < 0 )
return * V_86 ;
else if ( * V_86 > V_96 )
return - V_97 ;
V_90 = & V_84 [ * V_86 * sizeof( T_1 ) ] ;
} else {
for ( V_27 = 0 , V_55 = V_14 , V_90 = V_84 , * V_86 = 0 ;
V_27 < V_13 && * V_86 < V_96 ;
* V_86 += 1 ) {
if ( V_87 && ( * V_55 == ':' ) ) {
if ( V_27 > V_13 - 5 )
return - V_28 ;
V_91 = 0 ;
for ( V_92 = 1 ; V_92 < 5 ; V_92 ++ ) {
V_89 = V_55 [ V_92 ] ;
V_91 <<= 4 ;
if ( V_89 >= '0' && V_89 <= '9' ) {
V_91 |= V_89 - '0' ;
continue;
}
if ( V_89 >= 'a' && V_89 <= 'f' ) {
V_91 |= V_89 - ( 'a' - 10 ) ;
continue;
}
if ( V_89 >= 'A' && V_89 <= 'F' ) {
V_91 |= V_89 - ( 'A' - 10 ) ;
continue;
}
return - V_28 ;
}
* V_90 ++ = V_91 & 0xFF ;
* V_90 ++ = V_91 >> 8 ;
V_55 += 5 ;
V_27 += 5 ;
} else {
V_94 = V_36 -> V_98 ( V_55 , V_13 - V_27 ,
( T_1 * ) V_90 ) ;
if ( V_94 < 0 )
return - V_28 ;
V_55 += V_94 ;
V_27 += V_94 ;
V_90 += 2 ;
}
}
if ( V_27 < V_13 )
return - V_97 ;
}
* V_85 = * V_86 ;
if ( * V_86 % 13 ) {
* V_90 ++ = 0 ;
* V_90 ++ = 0 ;
* V_86 += 1 ;
if ( * V_86 % 13 ) {
V_93 = 13 - ( * V_86 % 13 ) ;
for ( V_27 = 0 ; V_27 < V_93 ; V_27 ++ ) {
* V_90 ++ = 0xff ;
* V_90 ++ = 0xff ;
}
* V_86 += V_93 ;
}
}
return 0 ;
}
static int F_33 ( struct V_29 * V_30 , const unsigned char * V_14 ,
int V_13 , int V_99 , int V_100 ,
struct V_101 * V_102 ,
struct V_103 * V_104 , int * V_105 )
{
struct V_106 * V_107 = F_11 ( V_30 -> V_53 ) ;
struct V_51 * V_52 = & V_107 -> V_54 ;
struct V_103 * V_108 ;
struct V_109 * V_110 ;
unsigned char V_111 , V_50 ;
unsigned char V_112 [ V_75 ] ;
T_1 * V_47 ;
T_2 time , V_113 ;
T_3 V_114 ;
int V_33 , V_48 , V_115 , V_27 ;
T_4 V_116 ;
* V_105 = 0 ;
V_47 = F_34 () ;
if ( ! V_47 )
return - V_117 ;
V_33 = F_31 ( V_14 , V_13 , ( unsigned char * ) V_47 , & V_48 , & V_115 ,
V_52 -> V_118 , V_52 -> V_88 , V_107 -> V_20 ) ;
if ( V_33 )
goto V_119;
V_33 = F_22 ( V_47 , V_48 ) ;
if ( V_33 )
goto V_119;
V_33 = F_28 ( V_30 , V_107 -> V_120 , V_47 , V_48 ,
V_112 , & V_50 ) ;
if ( V_33 < 0 )
goto V_119;
else if ( V_33 == 1 ) {
V_110 = (struct V_109 * ) V_104 ;
V_33 = 0 ;
goto V_77;
}
V_111 = F_35 ( V_112 ) ;
* V_105 = V_115 / 13 ;
for ( V_108 = V_104 , V_27 = * V_105 ; V_27 > 0 ; V_27 -- , V_108 ++ ) {
V_108 -> V_121 = V_27 ;
V_108 -> V_122 = V_123 ;
V_108 -> V_124 = 0 ;
V_108 -> V_125 = V_111 ;
V_108 -> V_126 = 0 ;
V_116 = ( V_27 - 1 ) * 13 ;
F_36 ( V_108 -> V_127 , V_47 + V_116 , 5 ) ;
F_36 ( V_108 -> V_128 , V_47 + V_116 + 5 , 6 ) ;
F_36 ( V_108 -> V_129 , V_47 + V_116 + 11 , 2 ) ;
}
V_104 [ 0 ] . V_121 |= 0x40 ;
V_110 = (struct V_109 * ) V_108 ;
V_77:
( * V_105 ) ++ ;
memcpy ( V_110 -> V_14 , V_112 , V_75 ) ;
V_110 -> V_122 = V_99 ? V_130 : V_131 ;
V_110 -> V_50 = V_50 ;
F_37 ( V_107 , V_102 , & time , & V_113 , & V_114 ) ;
V_110 -> time = V_110 -> ctime = time ;
V_110 -> V_113 = V_110 -> V_132 = V_110 -> V_133 = V_113 ;
V_110 -> V_134 = V_114 ;
F_38 ( V_110 , V_100 ) ;
V_110 -> V_135 = 0 ;
V_119:
F_39 ( V_47 ) ;
return V_33 ;
}
static int F_40 ( struct V_29 * V_30 , struct V_15 * V_136 , int V_99 ,
int V_100 , struct V_101 * V_102 ,
struct V_31 * V_32 )
{
struct V_103 * V_104 ;
unsigned int V_13 ;
int V_33 , V_105 ;
V_13 = F_7 ( V_136 ) ;
if ( V_13 == 0 )
return - V_34 ;
V_104 = F_41 ( sizeof( * V_104 ) * V_137 , V_138 ) ;
if ( V_104 == NULL )
return - V_117 ;
V_33 = F_33 ( V_30 , V_136 -> V_14 , V_13 , V_99 , V_100 , V_102 ,
V_104 , & V_105 ) ;
if ( V_33 )
goto V_139;
V_33 = F_42 ( V_30 , V_104 , V_105 , V_32 ) ;
if ( V_33 )
goto V_139;
V_30 -> V_140 = V_30 -> V_141 = V_30 -> V_142 = * V_102 ;
if ( F_43 ( V_30 ) )
( void ) F_44 ( V_30 ) ;
else
F_45 ( V_30 ) ;
V_139:
F_46 ( V_104 ) ;
return V_33 ;
}
static int F_47 ( struct V_29 * V_30 , struct V_15 * V_136 ,
struct V_31 * V_32 )
{
unsigned int V_13 = F_7 ( V_136 ) ;
if ( V_13 == 0 )
return - V_34 ;
return F_48 ( V_30 , V_136 -> V_14 , V_13 , V_32 ) ;
}
static int F_49 ( struct V_1 * V_1 )
{
return F_50 ( V_1 ) && ( V_1 -> V_143 & V_144 ) ;
}
static struct V_1 * F_51 ( struct V_29 * V_30 , struct V_1 * V_1 ,
unsigned int V_8 )
{
struct V_145 * V_146 = V_30 -> V_53 ;
struct V_31 V_32 ;
struct V_29 * V_29 ;
struct V_1 * V_147 ;
int V_33 ;
F_52 ( & F_11 ( V_146 ) -> V_148 ) ;
V_33 = F_47 ( V_30 , & V_1 -> V_149 , & V_32 ) ;
if ( V_33 ) {
if ( V_33 == - V_34 ) {
V_29 = NULL ;
goto V_150;
}
goto error;
}
V_29 = F_53 ( V_146 , V_32 . V_110 , V_32 . V_151 ) ;
F_25 ( V_32 . V_35 ) ;
if ( F_54 ( V_29 ) ) {
V_33 = F_55 ( V_29 ) ;
goto error;
}
V_147 = F_56 ( V_29 ) ;
if ( V_147 && V_147 -> V_5 == V_1 -> V_5 &&
! F_49 ( V_147 ) ) {
F_57 ( F_58 ( V_147 ) ) ;
if ( ! F_59 ( V_29 -> V_152 ) )
F_60 ( V_147 , V_1 ) ;
F_61 ( V_29 ) ;
F_62 ( & F_11 ( V_146 ) -> V_148 ) ;
return V_147 ;
} else
F_63 ( V_147 ) ;
V_150:
F_62 ( & F_11 ( V_146 ) -> V_148 ) ;
if ( ! V_29 )
V_1 -> V_4 = V_30 -> V_7 ;
return F_64 ( V_29 , V_1 ) ;
error:
F_62 ( & F_11 ( V_146 ) -> V_148 ) ;
return F_65 ( V_33 ) ;
}
static int F_66 ( struct V_29 * V_30 , struct V_1 * V_1 , T_5 V_153 ,
bool V_154 )
{
struct V_145 * V_146 = V_30 -> V_53 ;
struct V_29 * V_29 ;
struct V_31 V_32 ;
struct V_101 V_102 ;
int V_33 ;
F_52 ( & F_11 ( V_146 ) -> V_148 ) ;
V_102 = V_155 ;
V_33 = F_40 ( V_30 , & V_1 -> V_149 , 0 , 0 , & V_102 , & V_32 ) ;
if ( V_33 )
goto V_150;
V_30 -> V_7 ++ ;
V_29 = F_53 ( V_146 , V_32 . V_110 , V_32 . V_151 ) ;
F_25 ( V_32 . V_35 ) ;
if ( F_54 ( V_29 ) ) {
V_33 = F_55 ( V_29 ) ;
goto V_150;
}
V_29 -> V_7 ++ ;
V_29 -> V_141 = V_29 -> V_142 = V_29 -> V_140 = V_102 ;
F_67 ( V_1 , V_29 ) ;
V_150:
F_62 ( & F_11 ( V_146 ) -> V_148 ) ;
return V_33 ;
}
static int F_68 ( struct V_29 * V_30 , struct V_1 * V_1 )
{
struct V_29 * V_29 = V_1 -> V_6 ;
struct V_145 * V_146 = V_30 -> V_53 ;
struct V_31 V_32 ;
int V_33 ;
F_52 ( & F_11 ( V_146 ) -> V_148 ) ;
V_33 = F_69 ( V_29 ) ;
if ( V_33 )
goto V_150;
V_33 = F_47 ( V_30 , & V_1 -> V_149 , & V_32 ) ;
if ( V_33 )
goto V_150;
V_33 = F_70 ( V_30 , & V_32 ) ;
if ( V_33 )
goto V_150;
F_71 ( V_30 ) ;
F_72 ( V_29 ) ;
V_29 -> V_141 = V_29 -> V_142 = V_155 ;
F_73 ( V_29 ) ;
V_1 -> V_4 = V_30 -> V_7 ;
V_150:
F_62 ( & F_11 ( V_146 ) -> V_148 ) ;
return V_33 ;
}
static int F_74 ( struct V_29 * V_30 , struct V_1 * V_1 )
{
struct V_29 * V_29 = V_1 -> V_6 ;
struct V_145 * V_146 = V_30 -> V_53 ;
struct V_31 V_32 ;
int V_33 ;
F_52 ( & F_11 ( V_146 ) -> V_148 ) ;
V_33 = F_47 ( V_30 , & V_1 -> V_149 , & V_32 ) ;
if ( V_33 )
goto V_150;
V_33 = F_70 ( V_30 , & V_32 ) ;
if ( V_33 )
goto V_150;
F_72 ( V_29 ) ;
V_29 -> V_141 = V_29 -> V_142 = V_155 ;
F_73 ( V_29 ) ;
V_1 -> V_4 = V_30 -> V_7 ;
V_150:
F_62 ( & F_11 ( V_146 ) -> V_148 ) ;
return V_33 ;
}
static int F_75 ( struct V_29 * V_30 , struct V_1 * V_1 , T_5 V_153 )
{
struct V_145 * V_146 = V_30 -> V_53 ;
struct V_29 * V_29 ;
struct V_31 V_32 ;
struct V_101 V_102 ;
int V_33 , V_100 ;
F_52 ( & F_11 ( V_146 ) -> V_148 ) ;
V_102 = V_155 ;
V_100 = F_76 ( V_30 , & V_102 ) ;
if ( V_100 < 0 ) {
V_33 = V_100 ;
goto V_150;
}
V_33 = F_40 ( V_30 , & V_1 -> V_149 , 1 , V_100 , & V_102 , & V_32 ) ;
if ( V_33 )
goto V_119;
V_30 -> V_7 ++ ;
F_77 ( V_30 ) ;
V_29 = F_53 ( V_146 , V_32 . V_110 , V_32 . V_151 ) ;
F_25 ( V_32 . V_35 ) ;
if ( F_54 ( V_29 ) ) {
V_33 = F_55 ( V_29 ) ;
goto V_150;
}
V_29 -> V_7 ++ ;
F_78 ( V_29 , 2 ) ;
V_29 -> V_141 = V_29 -> V_142 = V_29 -> V_140 = V_102 ;
F_67 ( V_1 , V_29 ) ;
F_62 ( & F_11 ( V_146 ) -> V_148 ) ;
return 0 ;
V_119:
F_79 ( V_30 , V_100 ) ;
V_150:
F_62 ( & F_11 ( V_146 ) -> V_148 ) ;
return V_33 ;
}
static int F_80 ( struct V_29 * V_156 , struct V_1 * V_157 ,
struct V_29 * V_158 , struct V_1 * V_159 )
{
struct V_160 * V_161 ;
struct V_109 * V_162 ;
struct V_29 * V_163 , * V_164 ;
struct V_31 V_165 , V_32 ;
struct V_101 V_102 ;
T_4 V_166 ;
int V_33 , V_99 , V_167 , V_168 = 0 ;
struct V_145 * V_146 = V_156 -> V_53 ;
V_165 . V_35 = V_32 . V_35 = V_161 = NULL ;
V_163 = V_157 -> V_6 ;
V_164 = V_159 -> V_6 ;
F_52 ( & F_11 ( V_146 ) -> V_148 ) ;
V_33 = F_47 ( V_156 , & V_157 -> V_149 , & V_165 ) ;
if ( V_33 )
goto V_150;
V_99 = F_59 ( V_163 -> V_152 ) ;
V_167 = ( V_99 && V_156 != V_158 ) ;
if ( V_167 ) {
if ( F_81 ( V_163 , & V_161 , & V_162 ) ) {
V_33 = - V_169 ;
goto V_150;
}
}
V_102 = V_155 ;
if ( V_164 ) {
if ( V_99 ) {
V_33 = F_69 ( V_164 ) ;
if ( V_33 )
goto V_150;
}
V_166 = F_82 ( V_164 ) -> V_151 ;
F_73 ( V_164 ) ;
} else {
V_33 = F_40 ( V_158 , & V_159 -> V_149 , V_99 , 0 ,
& V_102 , & V_32 ) ;
if ( V_33 )
goto V_150;
V_166 = V_32 . V_151 ;
}
V_158 -> V_7 ++ ;
F_73 ( V_163 ) ;
F_83 ( V_163 , V_166 ) ;
if ( F_43 ( V_158 ) ) {
V_33 = F_44 ( V_163 ) ;
if ( V_33 )
goto V_170;
} else
F_45 ( V_163 ) ;
if ( V_167 ) {
F_38 ( V_162 , F_82 ( V_158 ) -> V_171 ) ;
F_84 ( V_161 , V_163 ) ;
if ( F_43 ( V_158 ) ) {
V_33 = F_85 ( V_161 ) ;
if ( V_33 )
goto V_172;
}
F_71 ( V_156 ) ;
if ( ! V_164 )
F_77 ( V_158 ) ;
}
V_33 = F_70 ( V_156 , & V_165 ) ;
V_165 . V_35 = NULL ;
if ( V_33 )
goto V_172;
V_156 -> V_7 ++ ;
V_156 -> V_140 = V_156 -> V_141 = V_102 ;
if ( F_43 ( V_156 ) )
( void ) F_44 ( V_156 ) ;
else
F_45 ( V_156 ) ;
if ( V_164 ) {
F_71 ( V_164 ) ;
if ( V_99 )
F_71 ( V_164 ) ;
V_164 -> V_140 = V_102 ;
}
V_150:
F_25 ( V_32 . V_35 ) ;
F_25 ( V_161 ) ;
F_25 ( V_165 . V_35 ) ;
F_62 ( & F_11 ( V_146 ) -> V_148 ) ;
return V_33 ;
V_172:
V_168 = 1 ;
if ( V_167 ) {
F_38 ( V_162 , F_82 ( V_156 ) -> V_171 ) ;
F_84 ( V_161 , V_163 ) ;
V_168 |= F_85 ( V_161 ) ;
}
V_170:
F_73 ( V_163 ) ;
F_83 ( V_163 , V_165 . V_151 ) ;
if ( V_164 ) {
F_83 ( V_164 , V_166 ) ;
if ( V_168 )
V_168 |= F_44 ( V_164 ) ;
} else {
int V_173 = F_70 ( V_158 , & V_32 ) ;
if ( V_168 )
V_168 |= V_173 ;
V_32 . V_35 = NULL ;
}
if ( V_168 < 0 ) {
F_86 ( V_158 -> V_53 ,
L_2 ,
V_174 , V_32 . V_151 ) ;
}
goto V_150;
}
static void F_87 ( struct V_145 * V_146 )
{
F_11 ( V_146 ) -> V_175 = & V_176 ;
if ( F_11 ( V_146 ) -> V_54 . V_177 != 's' )
V_146 -> V_178 = & V_179 ;
else
V_146 -> V_178 = & V_180 ;
}
static int F_88 ( struct V_145 * V_146 , void * V_181 , int V_182 )
{
return F_89 ( V_146 , V_181 , V_182 , 1 , F_87 ) ;
}
static struct V_1 * F_90 ( struct V_183 * V_184 ,
int V_8 , const char * V_185 ,
void * V_181 )
{
return F_91 ( V_184 , V_8 , V_185 , V_181 , F_88 ) ;
}
static int T_6 F_92 ( void )
{
return F_93 ( & V_186 ) ;
}
static void T_7 F_94 ( void )
{
F_95 ( & V_186 ) ;
}
