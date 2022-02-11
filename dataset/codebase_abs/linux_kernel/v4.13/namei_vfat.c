static inline unsigned long F_1 ( struct V_1 * V_1 )
{
return ( unsigned long ) V_1 -> V_2 ;
}
static inline void F_2 ( struct V_1 * V_1 ,
unsigned long V_3 )
{
V_1 -> V_2 = ( void * ) V_3 ;
}
static int F_3 ( struct V_1 * V_1 )
{
int V_4 = 1 ;
F_4 ( & V_1 -> V_5 ) ;
if ( F_1 ( V_1 ) != F_5 ( V_1 -> V_6 ) -> V_7 )
V_4 = 0 ;
F_6 ( & V_1 -> V_5 ) ;
return V_4 ;
}
static int F_7 ( struct V_1 * V_1 , unsigned int V_8 )
{
if ( V_8 & V_9 )
return - V_10 ;
if ( F_8 ( V_1 ) )
return 1 ;
return F_3 ( V_1 ) ;
}
static int F_9 ( struct V_1 * V_1 , unsigned int V_8 )
{
if ( V_8 & V_9 )
return - V_10 ;
if ( F_8 ( V_1 ) )
return 1 ;
if ( ! V_8 )
return 0 ;
if ( V_8 & ( V_11 | V_12 ) )
return 0 ;
return F_3 ( V_1 ) ;
}
static unsigned int F_10 ( unsigned int V_13 , const char * V_14 )
{
while ( V_13 && V_14 [ V_13 - 1 ] == '.' )
V_13 -- ;
return V_13 ;
}
static unsigned int F_11 ( const struct V_15 * V_15 )
{
return F_10 ( V_15 -> V_13 , V_15 -> V_14 ) ;
}
static int F_12 ( const struct V_1 * V_1 , struct V_15 * V_15 )
{
V_15 -> V_16 = F_13 ( V_1 , V_15 -> V_14 , F_11 ( V_15 ) ) ;
return 0 ;
}
static int F_14 ( const struct V_1 * V_1 , struct V_15 * V_15 )
{
struct V_17 * V_18 = F_15 ( V_1 -> V_19 ) -> V_20 ;
const unsigned char * V_14 ;
unsigned int V_13 ;
unsigned long V_16 ;
V_14 = V_15 -> V_14 ;
V_13 = F_11 ( V_15 ) ;
V_16 = F_16 ( V_1 ) ;
while ( V_13 -- )
V_16 = F_17 ( F_18 ( V_18 , * V_14 ++ ) , V_16 ) ;
V_15 -> V_16 = F_19 ( V_16 ) ;
return 0 ;
}
static int F_20 ( const struct V_1 * V_1 ,
unsigned int V_13 , const char * V_21 , const struct V_15 * V_14 )
{
struct V_17 * V_18 = F_15 ( V_1 -> V_19 ) -> V_20 ;
unsigned int V_22 , V_23 ;
V_22 = F_11 ( V_14 ) ;
V_23 = F_10 ( V_13 , V_21 ) ;
if ( V_22 == V_23 ) {
if ( F_21 ( V_18 , V_14 -> V_14 , V_21 , V_22 ) == 0 )
return 0 ;
}
return 1 ;
}
static int F_22 ( const struct V_1 * V_1 ,
unsigned int V_13 , const char * V_21 , const struct V_15 * V_14 )
{
unsigned int V_22 , V_23 ;
V_22 = F_11 ( V_14 ) ;
V_23 = F_10 ( V_13 , V_21 ) ;
if ( V_22 == V_23 ) {
if ( strncmp ( V_14 -> V_14 , V_21 , V_22 ) == 0 )
return 0 ;
}
return 1 ;
}
static inline T_1 F_23 ( T_1 V_24 )
{
return ( V_24 < 0x0020 )
|| ( V_24 == '*' ) || ( V_24 == '?' ) || ( V_24 == '<' ) || ( V_24 == '>' )
|| ( V_24 == '|' ) || ( V_24 == '"' ) || ( V_24 == ':' ) || ( V_24 == '/' )
|| ( V_24 == '\\' ) ;
}
static inline T_1 F_24 ( T_1 V_24 )
{
return ( V_24 == '[' ) || ( V_24 == ']' ) || ( V_24 == ';' ) || ( V_24 == ',' )
|| ( V_24 == '+' ) || ( V_24 == '=' ) ;
}
static T_1 F_25 ( T_1 V_24 )
{
return ( V_24 == '.' ) || ( V_24 == ' ' ) ;
}
static inline int F_26 ( const T_1 * V_25 , int V_13 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_13 ; V_26 ++ )
if ( F_23 ( V_25 [ V_26 ] ) )
return - V_27 ;
if ( V_25 [ V_26 - 1 ] == ' ' )
return - V_27 ;
return 0 ;
}
static int F_27 ( struct V_28 * V_29 , unsigned char * V_14 )
{
struct V_30 V_31 ;
int V_32 = F_28 ( V_29 , V_14 , & V_31 ) ;
if ( V_32 )
return - V_33 ;
F_29 ( V_31 . V_34 ) ;
return 0 ;
}
static inline int F_30 ( struct V_17 * V_35 ,
unsigned char * V_36 , int V_37 ,
T_1 * V_38 , struct V_39 * V_40 )
{
int V_13 ;
if ( F_25 ( * V_38 ) ) {
V_40 -> V_41 = 0 ;
return 0 ;
}
if ( F_24 ( * V_38 ) ) {
V_40 -> V_41 = 0 ;
V_36 [ 0 ] = '_' ;
return 1 ;
}
V_13 = V_35 -> V_42 ( * V_38 , V_36 , V_37 ) ;
if ( V_13 <= 0 ) {
V_40 -> V_41 = 0 ;
V_36 [ 0 ] = '_' ;
V_13 = 1 ;
} else if ( V_13 == 1 ) {
unsigned char V_43 = V_36 [ 0 ] ;
if ( V_36 [ 0 ] >= 0x7F ) {
V_40 -> V_44 = 0 ;
V_40 -> V_45 = 0 ;
}
V_36 [ 0 ] = F_31 ( V_35 , V_36 [ 0 ] ) ;
if ( isalpha ( V_36 [ 0 ] ) ) {
if ( V_36 [ 0 ] == V_43 )
V_40 -> V_44 = 0 ;
else
V_40 -> V_45 = 0 ;
}
} else {
V_40 -> V_44 = 0 ;
V_40 -> V_45 = 0 ;
}
return V_13 ;
}
static int F_32 ( struct V_28 * V_29 , struct V_17 * V_35 ,
T_1 * V_46 , int V_47 ,
unsigned char * V_48 , unsigned char * V_49 )
{
struct V_50 * V_51 = & F_15 ( V_29 -> V_52 ) -> V_53 ;
T_1 * V_54 , * V_55 , * V_56 , * V_57 ;
unsigned char V_58 [ 9 ] , V_59 [ 4 ] , V_36 [ 5 ] , * V_60 ;
unsigned char V_61 [ V_62 ] ;
int V_63 , V_64 ;
int V_65 = 0 , V_66 , V_67 , V_26 , V_68 , V_69 ;
int V_70 ;
struct V_39 V_71 , V_72 ;
V_70 = 1 ;
F_33 ( & V_71 ) ;
F_33 ( & V_72 ) ;
V_55 = V_56 = & V_46 [ V_47 ] ;
while ( -- V_55 >= V_46 ) {
if ( * V_55 == 0x002E ) {
if ( V_55 == V_56 - 1 ) {
V_65 = V_47 ;
V_55 = NULL ;
}
break;
}
}
if ( V_55 == V_46 - 1 ) {
V_65 = V_47 ;
V_55 = NULL ;
} else if ( V_55 ) {
V_57 = & V_46 [ 0 ] ;
while ( V_57 < V_55 ) {
if ( ! F_25 ( * V_57 ) )
break;
V_57 ++ ;
}
if ( V_57 != V_55 ) {
V_65 = V_55 - V_46 ;
V_55 ++ ;
} else {
V_65 = V_47 ;
V_55 = NULL ;
}
}
V_68 = 6 ;
V_69 = 2 ;
for ( V_67 = V_26 = 0 , V_60 = V_58 , V_54 = V_46 ; V_26 < V_65 ; V_26 ++ , V_54 ++ ) {
V_63 = F_30 ( V_35 , V_61 , sizeof( V_61 ) ,
V_54 , & V_71 ) ;
if ( V_63 == 0 )
continue;
if ( V_67 < 2 && ( V_67 + V_63 ) > 2 )
V_69 = V_67 ;
if ( V_67 < 6 && ( V_67 + V_63 ) > 6 )
V_68 = V_67 ;
for ( V_64 = 0 ; V_64 < V_63 ; V_64 ++ ) {
* V_60 ++ = V_61 [ V_64 ] ;
V_67 ++ ;
if ( V_67 >= 8 )
break;
}
if ( V_67 >= 8 ) {
if ( ( V_64 < V_63 - 1 ) || ( V_54 + 1 ) - V_46 < V_65 )
V_70 = 0 ;
break;
}
}
if ( V_67 == 0 ) {
return - V_27 ;
}
V_66 = 0 ;
if ( V_55 ) {
for ( V_60 = V_59 , V_54 = V_55 ; V_66 < 3 && V_54 < V_56 ; V_54 ++ ) {
V_63 = F_30 ( V_35 , V_61 , sizeof( V_61 ) ,
V_54 , & V_72 ) ;
if ( V_63 == 0 )
continue;
if ( ( V_66 + V_63 ) > 3 ) {
V_70 = 0 ;
break;
}
for ( V_64 = 0 ; V_64 < V_63 ; V_64 ++ ) {
* V_60 ++ = V_61 [ V_64 ] ;
V_66 ++ ;
}
if ( V_66 >= 3 ) {
if ( V_54 + 1 != V_56 )
V_70 = 0 ;
break;
}
}
}
V_59 [ V_66 ] = '\0' ;
V_58 [ V_67 ] = '\0' ;
if ( V_58 [ 0 ] == V_73 )
V_58 [ 0 ] = 0x05 ;
memset ( V_48 , ' ' , V_74 ) ;
memcpy ( V_48 , V_58 , V_67 ) ;
memcpy ( V_48 + 8 , V_59 , V_66 ) ;
* V_49 = 0 ;
if ( V_70 && V_71 . V_41 && V_72 . V_41 ) {
if ( F_27 ( V_29 , V_48 ) == 0 )
return - V_75 ;
if ( V_51 -> V_76 & V_77 ) {
return ( V_71 . V_45 && V_72 . V_45 ) ;
} else if ( V_51 -> V_76 & V_78 ) {
if ( ( V_71 . V_45 || V_71 . V_44 ) &&
( V_72 . V_45 || V_72 . V_44 ) ) {
if ( ! V_71 . V_45 && V_71 . V_44 )
* V_49 |= V_79 ;
if ( ! V_72 . V_45 && V_72 . V_44 )
* V_49 |= V_80 ;
return 1 ;
}
return 0 ;
} else {
F_34 () ;
}
}
if ( V_51 -> V_81 == 0 )
if ( F_27 ( V_29 , V_48 ) < 0 )
return 0 ;
if ( V_67 > 6 ) {
V_67 = V_68 ;
V_48 [ 7 ] = ' ' ;
}
V_48 [ V_67 ] = '~' ;
for ( V_26 = 1 ; V_26 < 10 ; V_26 ++ ) {
V_48 [ V_67 + 1 ] = V_26 + '0' ;
if ( F_27 ( V_29 , V_48 ) < 0 )
return 0 ;
}
V_26 = V_82 ;
V_65 = ( V_82 >> 16 ) & 0x7 ;
if ( V_67 > 2 ) {
V_67 = V_69 ;
V_48 [ 7 ] = ' ' ;
}
V_48 [ V_67 + 4 ] = '~' ;
V_48 [ V_67 + 5 ] = '1' + V_65 ;
while ( 1 ) {
snprintf ( V_36 , sizeof( V_36 ) , L_1 , V_26 & 0xffff ) ;
memcpy ( & V_48 [ V_67 ] , V_36 , 4 ) ;
if ( F_27 ( V_29 , V_48 ) < 0 )
break;
V_26 -= 11 ;
}
return 0 ;
}
static int
F_35 ( const unsigned char * V_14 , int V_13 , unsigned char * V_83 ,
int * V_84 , int * V_85 , int V_86 , int V_87 ,
struct V_17 * V_35 )
{
const unsigned char * V_54 ;
unsigned char V_88 ;
unsigned char * V_89 ;
unsigned int V_90 ;
int V_26 , V_91 , V_92 ;
int V_93 ;
if ( V_87 ) {
* V_85 = F_36 ( V_14 , V_13 , V_94 ,
( T_1 * ) V_83 , V_95 + 2 ) ;
if ( * V_85 < 0 )
return * V_85 ;
else if ( * V_85 > V_95 )
return - V_96 ;
V_89 = & V_83 [ * V_85 * sizeof( T_1 ) ] ;
} else {
for ( V_26 = 0 , V_54 = V_14 , V_89 = V_83 , * V_85 = 0 ;
V_26 < V_13 && * V_85 < V_95 ;
* V_85 += 1 ) {
if ( V_86 && ( * V_54 == ':' ) ) {
if ( V_26 > V_13 - 5 )
return - V_27 ;
V_90 = 0 ;
for ( V_91 = 1 ; V_91 < 5 ; V_91 ++ ) {
V_88 = V_54 [ V_91 ] ;
V_90 <<= 4 ;
if ( V_88 >= '0' && V_88 <= '9' ) {
V_90 |= V_88 - '0' ;
continue;
}
if ( V_88 >= 'a' && V_88 <= 'f' ) {
V_90 |= V_88 - ( 'a' - 10 ) ;
continue;
}
if ( V_88 >= 'A' && V_88 <= 'F' ) {
V_90 |= V_88 - ( 'A' - 10 ) ;
continue;
}
return - V_27 ;
}
* V_89 ++ = V_90 & 0xFF ;
* V_89 ++ = V_90 >> 8 ;
V_54 += 5 ;
V_26 += 5 ;
} else {
V_93 = V_35 -> V_97 ( V_54 , V_13 - V_26 ,
( T_1 * ) V_89 ) ;
if ( V_93 < 0 )
return - V_27 ;
V_54 += V_93 ;
V_26 += V_93 ;
V_89 += 2 ;
}
}
if ( V_26 < V_13 )
return - V_96 ;
}
* V_84 = * V_85 ;
if ( * V_85 % 13 ) {
* V_89 ++ = 0 ;
* V_89 ++ = 0 ;
* V_85 += 1 ;
if ( * V_85 % 13 ) {
V_92 = 13 - ( * V_85 % 13 ) ;
for ( V_26 = 0 ; V_26 < V_92 ; V_26 ++ ) {
* V_89 ++ = 0xff ;
* V_89 ++ = 0xff ;
}
* V_85 += V_92 ;
}
}
return 0 ;
}
static int F_37 ( struct V_28 * V_29 , const unsigned char * V_14 ,
int V_13 , int V_98 , int V_99 ,
struct V_100 * V_101 ,
struct V_102 * V_103 , int * V_104 )
{
struct V_105 * V_106 = F_15 ( V_29 -> V_52 ) ;
struct V_50 * V_51 = & V_106 -> V_53 ;
struct V_102 * V_107 ;
struct V_108 * V_109 ;
unsigned char V_110 , V_49 ;
unsigned char V_111 [ V_74 ] ;
T_1 * V_46 ;
T_2 time , V_112 ;
T_3 V_113 ;
int V_32 , V_47 , V_114 , V_26 ;
T_4 V_115 ;
* V_104 = 0 ;
V_46 = F_38 () ;
if ( ! V_46 )
return - V_116 ;
V_32 = F_35 ( V_14 , V_13 , ( unsigned char * ) V_46 , & V_47 , & V_114 ,
V_51 -> V_117 , V_51 -> V_87 , V_106 -> V_20 ) ;
if ( V_32 )
goto V_118;
V_32 = F_26 ( V_46 , V_47 ) ;
if ( V_32 )
goto V_118;
V_32 = F_32 ( V_29 , V_106 -> V_119 , V_46 , V_47 ,
V_111 , & V_49 ) ;
if ( V_32 < 0 )
goto V_118;
else if ( V_32 == 1 ) {
V_109 = (struct V_108 * ) V_103 ;
V_32 = 0 ;
goto V_76;
}
V_110 = F_39 ( V_111 ) ;
* V_104 = V_114 / 13 ;
for ( V_107 = V_103 , V_26 = * V_104 ; V_26 > 0 ; V_26 -- , V_107 ++ ) {
V_107 -> V_120 = V_26 ;
V_107 -> V_121 = V_122 ;
V_107 -> V_123 = 0 ;
V_107 -> V_124 = V_110 ;
V_107 -> V_125 = 0 ;
V_115 = ( V_26 - 1 ) * 13 ;
F_40 ( V_107 -> V_126 , V_46 + V_115 , 5 ) ;
F_40 ( V_107 -> V_127 , V_46 + V_115 + 5 , 6 ) ;
F_40 ( V_107 -> V_128 , V_46 + V_115 + 11 , 2 ) ;
}
V_103 [ 0 ] . V_120 |= 0x40 ;
V_109 = (struct V_108 * ) V_107 ;
V_76:
( * V_104 ) ++ ;
memcpy ( V_109 -> V_14 , V_111 , V_74 ) ;
V_109 -> V_121 = V_98 ? V_129 : V_130 ;
V_109 -> V_49 = V_49 ;
F_41 ( V_106 , V_101 , & time , & V_112 , & V_113 ) ;
V_109 -> time = V_109 -> ctime = time ;
V_109 -> V_112 = V_109 -> V_131 = V_109 -> V_132 = V_112 ;
V_109 -> V_133 = V_113 ;
F_42 ( V_109 , V_99 ) ;
V_109 -> V_134 = 0 ;
V_118:
F_43 ( V_46 ) ;
return V_32 ;
}
static int F_44 ( struct V_28 * V_29 , const struct V_15 * V_135 ,
int V_98 , int V_99 , struct V_100 * V_101 ,
struct V_30 * V_31 )
{
struct V_102 * V_103 ;
unsigned int V_13 ;
int V_32 , V_104 ;
V_13 = F_11 ( V_135 ) ;
if ( V_13 == 0 )
return - V_33 ;
V_103 = F_45 ( sizeof( * V_103 ) * V_136 , V_137 ) ;
if ( V_103 == NULL )
return - V_116 ;
V_32 = F_37 ( V_29 , V_135 -> V_14 , V_13 , V_98 , V_99 , V_101 ,
V_103 , & V_104 ) ;
if ( V_32 )
goto V_138;
V_32 = F_46 ( V_29 , V_103 , V_104 , V_31 ) ;
if ( V_32 )
goto V_138;
V_29 -> V_139 = V_29 -> V_140 = V_29 -> V_141 = * V_101 ;
if ( F_47 ( V_29 ) )
( void ) F_48 ( V_29 ) ;
else
F_49 ( V_29 ) ;
V_138:
F_50 ( V_103 ) ;
return V_32 ;
}
static int F_51 ( struct V_28 * V_29 , const struct V_15 * V_135 ,
struct V_30 * V_31 )
{
unsigned int V_13 = F_11 ( V_135 ) ;
if ( V_13 == 0 )
return - V_33 ;
return F_52 ( V_29 , V_135 -> V_14 , V_13 , V_31 ) ;
}
static int F_53 ( struct V_1 * V_1 )
{
return F_54 ( V_1 ) && ( V_1 -> V_142 & V_143 ) ;
}
static struct V_1 * F_55 ( struct V_28 * V_29 , struct V_1 * V_1 ,
unsigned int V_8 )
{
struct V_144 * V_145 = V_29 -> V_52 ;
struct V_30 V_31 ;
struct V_28 * V_28 ;
struct V_1 * V_146 ;
int V_32 ;
F_56 ( & F_15 ( V_145 ) -> V_147 ) ;
V_32 = F_51 ( V_29 , & V_1 -> V_148 , & V_31 ) ;
if ( V_32 ) {
if ( V_32 == - V_33 ) {
V_28 = NULL ;
goto V_149;
}
goto error;
}
V_28 = F_57 ( V_145 , V_31 . V_109 , V_31 . V_150 ) ;
F_29 ( V_31 . V_34 ) ;
if ( F_58 ( V_28 ) ) {
V_32 = F_59 ( V_28 ) ;
goto error;
}
V_146 = F_60 ( V_28 ) ;
if ( V_146 && V_146 -> V_6 == V_1 -> V_6 &&
! F_53 ( V_146 ) ) {
F_61 ( F_62 ( V_146 ) ) ;
if ( ! F_63 ( V_28 -> V_151 ) )
F_64 ( V_146 , V_1 ) ;
F_65 ( V_28 ) ;
F_66 ( & F_15 ( V_145 ) -> V_147 ) ;
return V_146 ;
} else
F_67 ( V_146 ) ;
V_149:
F_66 ( & F_15 ( V_145 ) -> V_147 ) ;
if ( ! V_28 )
F_2 ( V_1 , V_29 -> V_7 ) ;
return F_68 ( V_28 , V_1 ) ;
error:
F_66 ( & F_15 ( V_145 ) -> V_147 ) ;
return F_69 ( V_32 ) ;
}
static int F_70 ( struct V_28 * V_29 , struct V_1 * V_1 , T_5 V_152 ,
bool V_153 )
{
struct V_144 * V_145 = V_29 -> V_52 ;
struct V_28 * V_28 ;
struct V_30 V_31 ;
struct V_100 V_101 ;
int V_32 ;
F_56 ( & F_15 ( V_145 ) -> V_147 ) ;
V_101 = F_71 ( V_29 ) ;
V_32 = F_44 ( V_29 , & V_1 -> V_148 , 0 , 0 , & V_101 , & V_31 ) ;
if ( V_32 )
goto V_149;
V_29 -> V_7 ++ ;
V_28 = F_57 ( V_145 , V_31 . V_109 , V_31 . V_150 ) ;
F_29 ( V_31 . V_34 ) ;
if ( F_58 ( V_28 ) ) {
V_32 = F_59 ( V_28 ) ;
goto V_149;
}
V_28 -> V_7 ++ ;
V_28 -> V_140 = V_28 -> V_141 = V_28 -> V_139 = V_101 ;
F_72 ( V_1 , V_28 ) ;
V_149:
F_66 ( & F_15 ( V_145 ) -> V_147 ) ;
return V_32 ;
}
static int F_73 ( struct V_28 * V_29 , struct V_1 * V_1 )
{
struct V_28 * V_28 = F_5 ( V_1 ) ;
struct V_144 * V_145 = V_29 -> V_52 ;
struct V_30 V_31 ;
int V_32 ;
F_56 ( & F_15 ( V_145 ) -> V_147 ) ;
V_32 = F_74 ( V_28 ) ;
if ( V_32 )
goto V_149;
V_32 = F_51 ( V_29 , & V_1 -> V_148 , & V_31 ) ;
if ( V_32 )
goto V_149;
V_32 = F_75 ( V_29 , & V_31 ) ;
if ( V_32 )
goto V_149;
F_76 ( V_29 ) ;
F_77 ( V_28 ) ;
V_28 -> V_140 = V_28 -> V_141 = F_71 ( V_28 ) ;
F_78 ( V_28 ) ;
F_2 ( V_1 , V_29 -> V_7 ) ;
V_149:
F_66 ( & F_15 ( V_145 ) -> V_147 ) ;
return V_32 ;
}
static int F_79 ( struct V_28 * V_29 , struct V_1 * V_1 )
{
struct V_28 * V_28 = F_5 ( V_1 ) ;
struct V_144 * V_145 = V_29 -> V_52 ;
struct V_30 V_31 ;
int V_32 ;
F_56 ( & F_15 ( V_145 ) -> V_147 ) ;
V_32 = F_51 ( V_29 , & V_1 -> V_148 , & V_31 ) ;
if ( V_32 )
goto V_149;
V_32 = F_75 ( V_29 , & V_31 ) ;
if ( V_32 )
goto V_149;
F_77 ( V_28 ) ;
V_28 -> V_140 = V_28 -> V_141 = F_71 ( V_28 ) ;
F_78 ( V_28 ) ;
F_2 ( V_1 , V_29 -> V_7 ) ;
V_149:
F_66 ( & F_15 ( V_145 ) -> V_147 ) ;
return V_32 ;
}
static int F_80 ( struct V_28 * V_29 , struct V_1 * V_1 , T_5 V_152 )
{
struct V_144 * V_145 = V_29 -> V_52 ;
struct V_28 * V_28 ;
struct V_30 V_31 ;
struct V_100 V_101 ;
int V_32 , V_99 ;
F_56 ( & F_15 ( V_145 ) -> V_147 ) ;
V_101 = F_71 ( V_29 ) ;
V_99 = F_81 ( V_29 , & V_101 ) ;
if ( V_99 < 0 ) {
V_32 = V_99 ;
goto V_149;
}
V_32 = F_44 ( V_29 , & V_1 -> V_148 , 1 , V_99 , & V_101 , & V_31 ) ;
if ( V_32 )
goto V_118;
V_29 -> V_7 ++ ;
F_82 ( V_29 ) ;
V_28 = F_57 ( V_145 , V_31 . V_109 , V_31 . V_150 ) ;
F_29 ( V_31 . V_34 ) ;
if ( F_58 ( V_28 ) ) {
V_32 = F_59 ( V_28 ) ;
goto V_149;
}
V_28 -> V_7 ++ ;
F_83 ( V_28 , 2 ) ;
V_28 -> V_140 = V_28 -> V_141 = V_28 -> V_139 = V_101 ;
F_72 ( V_1 , V_28 ) ;
F_66 ( & F_15 ( V_145 ) -> V_147 ) ;
return 0 ;
V_118:
F_84 ( V_29 , V_99 ) ;
V_149:
F_66 ( & F_15 ( V_145 ) -> V_147 ) ;
return V_32 ;
}
static int F_85 ( struct V_28 * V_154 , struct V_1 * V_155 ,
struct V_28 * V_156 , struct V_1 * V_157 ,
unsigned int V_8 )
{
struct V_158 * V_159 ;
struct V_108 * V_160 ;
struct V_28 * V_161 , * V_162 ;
struct V_30 V_163 , V_31 ;
struct V_100 V_101 ;
T_4 V_164 ;
int V_32 , V_98 , V_165 , V_166 = 0 ;
struct V_144 * V_145 = V_154 -> V_52 ;
if ( V_8 & ~ V_167 )
return - V_27 ;
V_163 . V_34 = V_31 . V_34 = V_159 = NULL ;
V_161 = F_5 ( V_155 ) ;
V_162 = F_5 ( V_157 ) ;
F_56 ( & F_15 ( V_145 ) -> V_147 ) ;
V_32 = F_51 ( V_154 , & V_155 -> V_148 , & V_163 ) ;
if ( V_32 )
goto V_149;
V_98 = F_63 ( V_161 -> V_151 ) ;
V_165 = ( V_98 && V_154 != V_156 ) ;
if ( V_165 ) {
if ( F_86 ( V_161 , & V_159 , & V_160 ) ) {
V_32 = - V_168 ;
goto V_149;
}
}
V_101 = F_71 ( V_154 ) ;
if ( V_162 ) {
if ( V_98 ) {
V_32 = F_74 ( V_162 ) ;
if ( V_32 )
goto V_149;
}
V_164 = F_87 ( V_162 ) -> V_150 ;
F_78 ( V_162 ) ;
} else {
V_32 = F_44 ( V_156 , & V_157 -> V_148 , V_98 , 0 ,
& V_101 , & V_31 ) ;
if ( V_32 )
goto V_149;
V_164 = V_31 . V_150 ;
}
V_156 -> V_7 ++ ;
F_78 ( V_161 ) ;
F_88 ( V_161 , V_164 ) ;
if ( F_47 ( V_156 ) ) {
V_32 = F_48 ( V_161 ) ;
if ( V_32 )
goto V_169;
} else
F_49 ( V_161 ) ;
if ( V_165 ) {
F_42 ( V_160 , F_87 ( V_156 ) -> V_170 ) ;
F_89 ( V_159 , V_161 ) ;
if ( F_47 ( V_156 ) ) {
V_32 = F_90 ( V_159 ) ;
if ( V_32 )
goto V_171;
}
F_76 ( V_154 ) ;
if ( ! V_162 )
F_82 ( V_156 ) ;
}
V_32 = F_75 ( V_154 , & V_163 ) ;
V_163 . V_34 = NULL ;
if ( V_32 )
goto V_171;
V_154 -> V_7 ++ ;
V_154 -> V_139 = V_154 -> V_140 = V_101 ;
if ( F_47 ( V_154 ) )
( void ) F_48 ( V_154 ) ;
else
F_49 ( V_154 ) ;
if ( V_162 ) {
F_76 ( V_162 ) ;
if ( V_98 )
F_76 ( V_162 ) ;
V_162 -> V_139 = V_101 ;
}
V_149:
F_29 ( V_31 . V_34 ) ;
F_29 ( V_159 ) ;
F_29 ( V_163 . V_34 ) ;
F_66 ( & F_15 ( V_145 ) -> V_147 ) ;
return V_32 ;
V_171:
V_166 = 1 ;
if ( V_165 ) {
F_42 ( V_160 , F_87 ( V_154 ) -> V_170 ) ;
F_89 ( V_159 , V_161 ) ;
V_166 |= F_90 ( V_159 ) ;
}
V_169:
F_78 ( V_161 ) ;
F_88 ( V_161 , V_163 . V_150 ) ;
if ( V_162 ) {
F_88 ( V_162 , V_164 ) ;
if ( V_166 )
V_166 |= F_48 ( V_162 ) ;
} else {
int V_172 = F_75 ( V_156 , & V_31 ) ;
if ( V_166 )
V_166 |= V_172 ;
V_31 . V_34 = NULL ;
}
if ( V_166 < 0 ) {
F_91 ( V_156 -> V_52 ,
L_2 ,
V_173 , V_31 . V_150 ) ;
}
goto V_149;
}
static void F_92 ( struct V_144 * V_145 )
{
F_15 ( V_145 ) -> V_174 = & V_175 ;
if ( F_15 ( V_145 ) -> V_53 . V_176 != 's' )
V_145 -> V_177 = & V_178 ;
else
V_145 -> V_177 = & V_179 ;
}
static int F_93 ( struct V_144 * V_145 , void * V_180 , int V_181 )
{
return F_94 ( V_145 , V_180 , V_181 , 1 , F_92 ) ;
}
static struct V_1 * F_95 ( struct V_182 * V_183 ,
int V_8 , const char * V_184 ,
void * V_180 )
{
return F_96 ( V_183 , V_8 , V_184 , V_180 , F_93 ) ;
}
static int T_6 F_97 ( void )
{
return F_98 ( & V_185 ) ;
}
static void T_7 F_99 ( void )
{
F_100 ( & V_185 ) ;
}
