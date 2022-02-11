static int F_1 ( struct V_1 * V_1 )
{
int V_2 = 1 ;
F_2 ( & V_1 -> V_3 ) ;
if ( V_1 -> V_4 != F_3 ( V_1 -> V_5 ) -> V_6 )
V_2 = 0 ;
F_4 ( & V_1 -> V_3 ) ;
return V_2 ;
}
static int F_5 ( struct V_1 * V_1 , unsigned int V_7 )
{
if ( V_7 & V_8 )
return - V_9 ;
if ( F_6 ( V_1 ) )
return 1 ;
return F_1 ( V_1 ) ;
}
static int F_7 ( struct V_1 * V_1 , unsigned int V_7 )
{
if ( V_7 & V_8 )
return - V_9 ;
if ( F_6 ( V_1 ) )
return 1 ;
if ( ! V_7 )
return 0 ;
if ( V_7 & ( V_10 | V_11 ) )
return 0 ;
return F_1 ( V_1 ) ;
}
static unsigned int F_8 ( unsigned int V_12 , const char * V_13 )
{
while ( V_12 && V_13 [ V_12 - 1 ] == '.' )
V_12 -- ;
return V_12 ;
}
static unsigned int F_9 ( const struct V_14 * V_14 )
{
return F_8 ( V_14 -> V_12 , V_14 -> V_13 ) ;
}
static int F_10 ( const struct V_1 * V_1 , struct V_14 * V_14 )
{
V_14 -> V_15 = F_11 ( V_1 , V_14 -> V_13 , F_9 ( V_14 ) ) ;
return 0 ;
}
static int F_12 ( const struct V_1 * V_1 , struct V_14 * V_14 )
{
struct V_16 * V_17 = F_13 ( V_1 -> V_18 ) -> V_19 ;
const unsigned char * V_13 ;
unsigned int V_12 ;
unsigned long V_15 ;
V_13 = V_14 -> V_13 ;
V_12 = F_9 ( V_14 ) ;
V_15 = F_14 ( V_1 ) ;
while ( V_12 -- )
V_15 = F_15 ( F_16 ( V_17 , * V_13 ++ ) , V_15 ) ;
V_14 -> V_15 = F_17 ( V_15 ) ;
return 0 ;
}
static int F_18 ( const struct V_1 * V_1 ,
unsigned int V_12 , const char * V_20 , const struct V_14 * V_13 )
{
struct V_16 * V_17 = F_13 ( V_1 -> V_18 ) -> V_19 ;
unsigned int V_21 , V_22 ;
V_21 = F_9 ( V_13 ) ;
V_22 = F_8 ( V_12 , V_20 ) ;
if ( V_21 == V_22 ) {
if ( F_19 ( V_17 , V_13 -> V_13 , V_20 , V_21 ) == 0 )
return 0 ;
}
return 1 ;
}
static int F_20 ( const struct V_1 * V_1 ,
unsigned int V_12 , const char * V_20 , const struct V_14 * V_13 )
{
unsigned int V_21 , V_22 ;
V_21 = F_9 ( V_13 ) ;
V_22 = F_8 ( V_12 , V_20 ) ;
if ( V_21 == V_22 ) {
if ( strncmp ( V_13 -> V_13 , V_20 , V_21 ) == 0 )
return 0 ;
}
return 1 ;
}
static inline T_1 F_21 ( T_1 V_23 )
{
return ( V_23 < 0x0020 )
|| ( V_23 == '*' ) || ( V_23 == '?' ) || ( V_23 == '<' ) || ( V_23 == '>' )
|| ( V_23 == '|' ) || ( V_23 == '"' ) || ( V_23 == ':' ) || ( V_23 == '/' )
|| ( V_23 == '\\' ) ;
}
static inline T_1 F_22 ( T_1 V_23 )
{
return ( V_23 == '[' ) || ( V_23 == ']' ) || ( V_23 == ';' ) || ( V_23 == ',' )
|| ( V_23 == '+' ) || ( V_23 == '=' ) ;
}
static T_1 F_23 ( T_1 V_23 )
{
return ( V_23 == '.' ) || ( V_23 == ' ' ) ;
}
static inline int F_24 ( const T_1 * V_24 , int V_12 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_12 ; V_25 ++ )
if ( F_21 ( V_24 [ V_25 ] ) )
return - V_26 ;
if ( V_24 [ V_25 - 1 ] == ' ' )
return - V_26 ;
return 0 ;
}
static int F_25 ( struct V_27 * V_28 , unsigned char * V_13 )
{
struct V_29 V_30 ;
int V_31 = F_26 ( V_28 , V_13 , & V_30 ) ;
if ( V_31 )
return - V_32 ;
F_27 ( V_30 . V_33 ) ;
return 0 ;
}
static inline int F_28 ( struct V_16 * V_34 ,
unsigned char * V_35 , int V_36 ,
T_1 * V_37 , struct V_38 * V_39 )
{
int V_12 ;
if ( F_23 ( * V_37 ) ) {
V_39 -> V_40 = 0 ;
return 0 ;
}
if ( F_22 ( * V_37 ) ) {
V_39 -> V_40 = 0 ;
V_35 [ 0 ] = '_' ;
return 1 ;
}
V_12 = V_34 -> V_41 ( * V_37 , V_35 , V_36 ) ;
if ( V_12 <= 0 ) {
V_39 -> V_40 = 0 ;
V_35 [ 0 ] = '_' ;
V_12 = 1 ;
} else if ( V_12 == 1 ) {
unsigned char V_42 = V_35 [ 0 ] ;
if ( V_35 [ 0 ] >= 0x7F ) {
V_39 -> V_43 = 0 ;
V_39 -> V_44 = 0 ;
}
V_35 [ 0 ] = F_29 ( V_34 , V_35 [ 0 ] ) ;
if ( isalpha ( V_35 [ 0 ] ) ) {
if ( V_35 [ 0 ] == V_42 )
V_39 -> V_43 = 0 ;
else
V_39 -> V_44 = 0 ;
}
} else {
V_39 -> V_43 = 0 ;
V_39 -> V_44 = 0 ;
}
return V_12 ;
}
static int F_30 ( struct V_27 * V_28 , struct V_16 * V_34 ,
T_1 * V_45 , int V_46 ,
unsigned char * V_47 , unsigned char * V_48 )
{
struct V_49 * V_50 = & F_13 ( V_28 -> V_51 ) -> V_52 ;
T_1 * V_53 , * V_54 , * V_55 , * V_56 ;
unsigned char V_57 [ 9 ] , V_58 [ 4 ] , V_35 [ 5 ] , * V_59 ;
unsigned char V_60 [ V_61 ] ;
int V_62 , V_63 ;
int V_64 = 0 , V_65 , V_66 , V_25 , V_67 , V_68 ;
int V_69 ;
struct V_38 V_70 , V_71 ;
V_69 = 1 ;
F_31 ( & V_70 ) ;
F_31 ( & V_71 ) ;
V_54 = V_55 = & V_45 [ V_46 ] ;
while ( -- V_54 >= V_45 ) {
if ( * V_54 == 0x002E ) {
if ( V_54 == V_55 - 1 ) {
V_64 = V_46 ;
V_54 = NULL ;
}
break;
}
}
if ( V_54 == V_45 - 1 ) {
V_64 = V_46 ;
V_54 = NULL ;
} else if ( V_54 ) {
V_56 = & V_45 [ 0 ] ;
while ( V_56 < V_54 ) {
if ( ! F_23 ( * V_56 ) )
break;
V_56 ++ ;
}
if ( V_56 != V_54 ) {
V_64 = V_54 - V_45 ;
V_54 ++ ;
} else {
V_64 = V_46 ;
V_54 = NULL ;
}
}
V_67 = 6 ;
V_68 = 2 ;
for ( V_66 = V_25 = 0 , V_59 = V_57 , V_53 = V_45 ; V_25 < V_64 ; V_25 ++ , V_53 ++ ) {
V_62 = F_28 ( V_34 , V_60 , sizeof( V_60 ) ,
V_53 , & V_70 ) ;
if ( V_62 == 0 )
continue;
if ( V_66 < 2 && ( V_66 + V_62 ) > 2 )
V_68 = V_66 ;
if ( V_66 < 6 && ( V_66 + V_62 ) > 6 )
V_67 = V_66 ;
for ( V_63 = 0 ; V_63 < V_62 ; V_63 ++ ) {
* V_59 ++ = V_60 [ V_63 ] ;
V_66 ++ ;
if ( V_66 >= 8 )
break;
}
if ( V_66 >= 8 ) {
if ( ( V_63 < V_62 - 1 ) || ( V_53 + 1 ) - V_45 < V_64 )
V_69 = 0 ;
break;
}
}
if ( V_66 == 0 ) {
return - V_26 ;
}
V_65 = 0 ;
if ( V_54 ) {
for ( V_59 = V_58 , V_53 = V_54 ; V_65 < 3 && V_53 < V_55 ; V_53 ++ ) {
V_62 = F_28 ( V_34 , V_60 , sizeof( V_60 ) ,
V_53 , & V_71 ) ;
if ( V_62 == 0 )
continue;
if ( ( V_65 + V_62 ) > 3 ) {
V_69 = 0 ;
break;
}
for ( V_63 = 0 ; V_63 < V_62 ; V_63 ++ ) {
* V_59 ++ = V_60 [ V_63 ] ;
V_65 ++ ;
}
if ( V_65 >= 3 ) {
if ( V_53 + 1 != V_55 )
V_69 = 0 ;
break;
}
}
}
V_58 [ V_65 ] = '\0' ;
V_57 [ V_66 ] = '\0' ;
if ( V_57 [ 0 ] == V_72 )
V_57 [ 0 ] = 0x05 ;
memset ( V_47 , ' ' , V_73 ) ;
memcpy ( V_47 , V_57 , V_66 ) ;
memcpy ( V_47 + 8 , V_58 , V_65 ) ;
* V_48 = 0 ;
if ( V_69 && V_70 . V_40 && V_71 . V_40 ) {
if ( F_25 ( V_28 , V_47 ) == 0 )
return - V_74 ;
if ( V_50 -> V_75 & V_76 ) {
return ( V_70 . V_44 && V_71 . V_44 ) ;
} else if ( V_50 -> V_75 & V_77 ) {
if ( ( V_70 . V_44 || V_70 . V_43 ) &&
( V_71 . V_44 || V_71 . V_43 ) ) {
if ( ! V_70 . V_44 && V_70 . V_43 )
* V_48 |= V_78 ;
if ( ! V_71 . V_44 && V_71 . V_43 )
* V_48 |= V_79 ;
return 1 ;
}
return 0 ;
} else {
F_32 () ;
}
}
if ( V_50 -> V_80 == 0 )
if ( F_25 ( V_28 , V_47 ) < 0 )
return 0 ;
if ( V_66 > 6 ) {
V_66 = V_67 ;
V_47 [ 7 ] = ' ' ;
}
V_47 [ V_66 ] = '~' ;
for ( V_25 = 1 ; V_25 < 10 ; V_25 ++ ) {
V_47 [ V_66 + 1 ] = V_25 + '0' ;
if ( F_25 ( V_28 , V_47 ) < 0 )
return 0 ;
}
V_25 = V_81 ;
V_64 = ( V_81 >> 16 ) & 0x7 ;
if ( V_66 > 2 ) {
V_66 = V_68 ;
V_47 [ 7 ] = ' ' ;
}
V_47 [ V_66 + 4 ] = '~' ;
V_47 [ V_66 + 5 ] = '1' + V_64 ;
while ( 1 ) {
snprintf ( V_35 , sizeof( V_35 ) , L_1 , V_25 & 0xffff ) ;
memcpy ( & V_47 [ V_66 ] , V_35 , 4 ) ;
if ( F_25 ( V_28 , V_47 ) < 0 )
break;
V_25 -= 11 ;
}
return 0 ;
}
static int
F_33 ( const unsigned char * V_13 , int V_12 , unsigned char * V_82 ,
int * V_83 , int * V_84 , int V_85 , int V_86 ,
struct V_16 * V_34 )
{
const unsigned char * V_53 ;
unsigned char V_87 ;
unsigned char * V_88 ;
unsigned int V_89 ;
int V_25 , V_90 , V_91 ;
int V_92 ;
if ( V_86 ) {
* V_84 = F_34 ( V_13 , V_12 , V_93 ,
( T_1 * ) V_82 , V_94 + 2 ) ;
if ( * V_84 < 0 )
return * V_84 ;
else if ( * V_84 > V_94 )
return - V_95 ;
V_88 = & V_82 [ * V_84 * sizeof( T_1 ) ] ;
} else {
for ( V_25 = 0 , V_53 = V_13 , V_88 = V_82 , * V_84 = 0 ;
V_25 < V_12 && * V_84 < V_94 ;
* V_84 += 1 ) {
if ( V_85 && ( * V_53 == ':' ) ) {
if ( V_25 > V_12 - 5 )
return - V_26 ;
V_89 = 0 ;
for ( V_90 = 1 ; V_90 < 5 ; V_90 ++ ) {
V_87 = V_53 [ V_90 ] ;
V_89 <<= 4 ;
if ( V_87 >= '0' && V_87 <= '9' ) {
V_89 |= V_87 - '0' ;
continue;
}
if ( V_87 >= 'a' && V_87 <= 'f' ) {
V_89 |= V_87 - ( 'a' - 10 ) ;
continue;
}
if ( V_87 >= 'A' && V_87 <= 'F' ) {
V_89 |= V_87 - ( 'A' - 10 ) ;
continue;
}
return - V_26 ;
}
* V_88 ++ = V_89 & 0xFF ;
* V_88 ++ = V_89 >> 8 ;
V_53 += 5 ;
V_25 += 5 ;
} else {
V_92 = V_34 -> V_96 ( V_53 , V_12 - V_25 ,
( T_1 * ) V_88 ) ;
if ( V_92 < 0 )
return - V_26 ;
V_53 += V_92 ;
V_25 += V_92 ;
V_88 += 2 ;
}
}
if ( V_25 < V_12 )
return - V_95 ;
}
* V_83 = * V_84 ;
if ( * V_84 % 13 ) {
* V_88 ++ = 0 ;
* V_88 ++ = 0 ;
* V_84 += 1 ;
if ( * V_84 % 13 ) {
V_91 = 13 - ( * V_84 % 13 ) ;
for ( V_25 = 0 ; V_25 < V_91 ; V_25 ++ ) {
* V_88 ++ = 0xff ;
* V_88 ++ = 0xff ;
}
* V_84 += V_91 ;
}
}
return 0 ;
}
static int F_35 ( struct V_27 * V_28 , const unsigned char * V_13 ,
int V_12 , int V_97 , int V_98 ,
struct V_99 * V_100 ,
struct V_101 * V_102 , int * V_103 )
{
struct V_104 * V_105 = F_13 ( V_28 -> V_51 ) ;
struct V_49 * V_50 = & V_105 -> V_52 ;
struct V_101 * V_106 ;
struct V_107 * V_108 ;
unsigned char V_109 , V_48 ;
unsigned char V_110 [ V_73 ] ;
T_1 * V_45 ;
T_2 time , V_111 ;
T_3 V_112 ;
int V_31 , V_46 , V_113 , V_25 ;
T_4 V_114 ;
* V_103 = 0 ;
V_45 = F_36 () ;
if ( ! V_45 )
return - V_115 ;
V_31 = F_33 ( V_13 , V_12 , ( unsigned char * ) V_45 , & V_46 , & V_113 ,
V_50 -> V_116 , V_50 -> V_86 , V_105 -> V_19 ) ;
if ( V_31 )
goto V_117;
V_31 = F_24 ( V_45 , V_46 ) ;
if ( V_31 )
goto V_117;
V_31 = F_30 ( V_28 , V_105 -> V_118 , V_45 , V_46 ,
V_110 , & V_48 ) ;
if ( V_31 < 0 )
goto V_117;
else if ( V_31 == 1 ) {
V_108 = (struct V_107 * ) V_102 ;
V_31 = 0 ;
goto V_75;
}
V_109 = F_37 ( V_110 ) ;
* V_103 = V_113 / 13 ;
for ( V_106 = V_102 , V_25 = * V_103 ; V_25 > 0 ; V_25 -- , V_106 ++ ) {
V_106 -> V_119 = V_25 ;
V_106 -> V_120 = V_121 ;
V_106 -> V_122 = 0 ;
V_106 -> V_123 = V_109 ;
V_106 -> V_124 = 0 ;
V_114 = ( V_25 - 1 ) * 13 ;
F_38 ( V_106 -> V_125 , V_45 + V_114 , 5 ) ;
F_38 ( V_106 -> V_126 , V_45 + V_114 + 5 , 6 ) ;
F_38 ( V_106 -> V_127 , V_45 + V_114 + 11 , 2 ) ;
}
V_102 [ 0 ] . V_119 |= 0x40 ;
V_108 = (struct V_107 * ) V_106 ;
V_75:
( * V_103 ) ++ ;
memcpy ( V_108 -> V_13 , V_110 , V_73 ) ;
V_108 -> V_120 = V_97 ? V_128 : V_129 ;
V_108 -> V_48 = V_48 ;
F_39 ( V_105 , V_100 , & time , & V_111 , & V_112 ) ;
V_108 -> time = V_108 -> ctime = time ;
V_108 -> V_111 = V_108 -> V_130 = V_108 -> V_131 = V_111 ;
V_108 -> V_132 = V_112 ;
F_40 ( V_108 , V_98 ) ;
V_108 -> V_133 = 0 ;
V_117:
F_41 ( V_45 ) ;
return V_31 ;
}
static int F_42 ( struct V_27 * V_28 , const struct V_14 * V_134 ,
int V_97 , int V_98 , struct V_99 * V_100 ,
struct V_29 * V_30 )
{
struct V_101 * V_102 ;
unsigned int V_12 ;
int V_31 , V_103 ;
V_12 = F_9 ( V_134 ) ;
if ( V_12 == 0 )
return - V_32 ;
V_102 = F_43 ( sizeof( * V_102 ) * V_135 , V_136 ) ;
if ( V_102 == NULL )
return - V_115 ;
V_31 = F_35 ( V_28 , V_134 -> V_13 , V_12 , V_97 , V_98 , V_100 ,
V_102 , & V_103 ) ;
if ( V_31 )
goto V_137;
V_31 = F_44 ( V_28 , V_102 , V_103 , V_30 ) ;
if ( V_31 )
goto V_137;
V_28 -> V_138 = V_28 -> V_139 = V_28 -> V_140 = * V_100 ;
if ( F_45 ( V_28 ) )
( void ) F_46 ( V_28 ) ;
else
F_47 ( V_28 ) ;
V_137:
F_48 ( V_102 ) ;
return V_31 ;
}
static int F_49 ( struct V_27 * V_28 , const struct V_14 * V_134 ,
struct V_29 * V_30 )
{
unsigned int V_12 = F_9 ( V_134 ) ;
if ( V_12 == 0 )
return - V_32 ;
return F_50 ( V_28 , V_134 -> V_13 , V_12 , V_30 ) ;
}
static int F_51 ( struct V_1 * V_1 )
{
return F_52 ( V_1 ) && ( V_1 -> V_141 & V_142 ) ;
}
static struct V_1 * F_53 ( struct V_27 * V_28 , struct V_1 * V_1 ,
unsigned int V_7 )
{
struct V_143 * V_144 = V_28 -> V_51 ;
struct V_29 V_30 ;
struct V_27 * V_27 ;
struct V_1 * V_145 ;
int V_31 ;
F_54 ( & F_13 ( V_144 ) -> V_146 ) ;
V_31 = F_49 ( V_28 , & V_1 -> V_147 , & V_30 ) ;
if ( V_31 ) {
if ( V_31 == - V_32 ) {
V_27 = NULL ;
goto V_148;
}
goto error;
}
V_27 = F_55 ( V_144 , V_30 . V_108 , V_30 . V_149 ) ;
F_27 ( V_30 . V_33 ) ;
if ( F_56 ( V_27 ) ) {
V_31 = F_57 ( V_27 ) ;
goto error;
}
V_145 = F_58 ( V_27 ) ;
if ( V_145 && V_145 -> V_5 == V_1 -> V_5 &&
! F_51 ( V_145 ) ) {
F_59 ( F_60 ( V_145 ) ) ;
if ( ! F_61 ( V_27 -> V_150 ) )
F_62 ( V_145 , V_1 ) ;
F_63 ( V_27 ) ;
F_64 ( & F_13 ( V_144 ) -> V_146 ) ;
return V_145 ;
} else
F_65 ( V_145 ) ;
V_148:
F_64 ( & F_13 ( V_144 ) -> V_146 ) ;
if ( ! V_27 )
V_1 -> V_4 = V_28 -> V_6 ;
return F_66 ( V_27 , V_1 ) ;
error:
F_64 ( & F_13 ( V_144 ) -> V_146 ) ;
return F_67 ( V_31 ) ;
}
static int F_68 ( struct V_27 * V_28 , struct V_1 * V_1 , T_5 V_151 ,
bool V_152 )
{
struct V_143 * V_144 = V_28 -> V_51 ;
struct V_27 * V_27 ;
struct V_29 V_30 ;
struct V_99 V_100 ;
int V_31 ;
F_54 ( & F_13 ( V_144 ) -> V_146 ) ;
V_100 = V_153 ;
V_31 = F_42 ( V_28 , & V_1 -> V_147 , 0 , 0 , & V_100 , & V_30 ) ;
if ( V_31 )
goto V_148;
V_28 -> V_6 ++ ;
V_27 = F_55 ( V_144 , V_30 . V_108 , V_30 . V_149 ) ;
F_27 ( V_30 . V_33 ) ;
if ( F_56 ( V_27 ) ) {
V_31 = F_57 ( V_27 ) ;
goto V_148;
}
V_27 -> V_6 ++ ;
V_27 -> V_139 = V_27 -> V_140 = V_27 -> V_138 = V_100 ;
F_69 ( V_1 , V_27 ) ;
V_148:
F_64 ( & F_13 ( V_144 ) -> V_146 ) ;
return V_31 ;
}
static int F_70 ( struct V_27 * V_28 , struct V_1 * V_1 )
{
struct V_27 * V_27 = F_3 ( V_1 ) ;
struct V_143 * V_144 = V_28 -> V_51 ;
struct V_29 V_30 ;
int V_31 ;
F_54 ( & F_13 ( V_144 ) -> V_146 ) ;
V_31 = F_71 ( V_27 ) ;
if ( V_31 )
goto V_148;
V_31 = F_49 ( V_28 , & V_1 -> V_147 , & V_30 ) ;
if ( V_31 )
goto V_148;
V_31 = F_72 ( V_28 , & V_30 ) ;
if ( V_31 )
goto V_148;
F_73 ( V_28 ) ;
F_74 ( V_27 ) ;
V_27 -> V_139 = V_27 -> V_140 = V_153 ;
F_75 ( V_27 ) ;
V_1 -> V_4 = V_28 -> V_6 ;
V_148:
F_64 ( & F_13 ( V_144 ) -> V_146 ) ;
return V_31 ;
}
static int F_76 ( struct V_27 * V_28 , struct V_1 * V_1 )
{
struct V_27 * V_27 = F_3 ( V_1 ) ;
struct V_143 * V_144 = V_28 -> V_51 ;
struct V_29 V_30 ;
int V_31 ;
F_54 ( & F_13 ( V_144 ) -> V_146 ) ;
V_31 = F_49 ( V_28 , & V_1 -> V_147 , & V_30 ) ;
if ( V_31 )
goto V_148;
V_31 = F_72 ( V_28 , & V_30 ) ;
if ( V_31 )
goto V_148;
F_74 ( V_27 ) ;
V_27 -> V_139 = V_27 -> V_140 = V_153 ;
F_75 ( V_27 ) ;
V_1 -> V_4 = V_28 -> V_6 ;
V_148:
F_64 ( & F_13 ( V_144 ) -> V_146 ) ;
return V_31 ;
}
static int F_77 ( struct V_27 * V_28 , struct V_1 * V_1 , T_5 V_151 )
{
struct V_143 * V_144 = V_28 -> V_51 ;
struct V_27 * V_27 ;
struct V_29 V_30 ;
struct V_99 V_100 ;
int V_31 , V_98 ;
F_54 ( & F_13 ( V_144 ) -> V_146 ) ;
V_100 = V_153 ;
V_98 = F_78 ( V_28 , & V_100 ) ;
if ( V_98 < 0 ) {
V_31 = V_98 ;
goto V_148;
}
V_31 = F_42 ( V_28 , & V_1 -> V_147 , 1 , V_98 , & V_100 , & V_30 ) ;
if ( V_31 )
goto V_117;
V_28 -> V_6 ++ ;
F_79 ( V_28 ) ;
V_27 = F_55 ( V_144 , V_30 . V_108 , V_30 . V_149 ) ;
F_27 ( V_30 . V_33 ) ;
if ( F_56 ( V_27 ) ) {
V_31 = F_57 ( V_27 ) ;
goto V_148;
}
V_27 -> V_6 ++ ;
F_80 ( V_27 , 2 ) ;
V_27 -> V_139 = V_27 -> V_140 = V_27 -> V_138 = V_100 ;
F_69 ( V_1 , V_27 ) ;
F_64 ( & F_13 ( V_144 ) -> V_146 ) ;
return 0 ;
V_117:
F_81 ( V_28 , V_98 ) ;
V_148:
F_64 ( & F_13 ( V_144 ) -> V_146 ) ;
return V_31 ;
}
static int F_82 ( struct V_27 * V_154 , struct V_1 * V_155 ,
struct V_27 * V_156 , struct V_1 * V_157 )
{
struct V_158 * V_159 ;
struct V_107 * V_160 ;
struct V_27 * V_161 , * V_162 ;
struct V_29 V_163 , V_30 ;
struct V_99 V_100 ;
T_4 V_164 ;
int V_31 , V_97 , V_165 , V_166 = 0 ;
struct V_143 * V_144 = V_154 -> V_51 ;
V_163 . V_33 = V_30 . V_33 = V_159 = NULL ;
V_161 = F_3 ( V_155 ) ;
V_162 = F_3 ( V_157 ) ;
F_54 ( & F_13 ( V_144 ) -> V_146 ) ;
V_31 = F_49 ( V_154 , & V_155 -> V_147 , & V_163 ) ;
if ( V_31 )
goto V_148;
V_97 = F_61 ( V_161 -> V_150 ) ;
V_165 = ( V_97 && V_154 != V_156 ) ;
if ( V_165 ) {
if ( F_83 ( V_161 , & V_159 , & V_160 ) ) {
V_31 = - V_167 ;
goto V_148;
}
}
V_100 = V_153 ;
if ( V_162 ) {
if ( V_97 ) {
V_31 = F_71 ( V_162 ) ;
if ( V_31 )
goto V_148;
}
V_164 = F_84 ( V_162 ) -> V_149 ;
F_75 ( V_162 ) ;
} else {
V_31 = F_42 ( V_156 , & V_157 -> V_147 , V_97 , 0 ,
& V_100 , & V_30 ) ;
if ( V_31 )
goto V_148;
V_164 = V_30 . V_149 ;
}
V_156 -> V_6 ++ ;
F_75 ( V_161 ) ;
F_85 ( V_161 , V_164 ) ;
if ( F_45 ( V_156 ) ) {
V_31 = F_46 ( V_161 ) ;
if ( V_31 )
goto V_168;
} else
F_47 ( V_161 ) ;
if ( V_165 ) {
F_40 ( V_160 , F_84 ( V_156 ) -> V_169 ) ;
F_86 ( V_159 , V_161 ) ;
if ( F_45 ( V_156 ) ) {
V_31 = F_87 ( V_159 ) ;
if ( V_31 )
goto V_170;
}
F_73 ( V_154 ) ;
if ( ! V_162 )
F_79 ( V_156 ) ;
}
V_31 = F_72 ( V_154 , & V_163 ) ;
V_163 . V_33 = NULL ;
if ( V_31 )
goto V_170;
V_154 -> V_6 ++ ;
V_154 -> V_138 = V_154 -> V_139 = V_100 ;
if ( F_45 ( V_154 ) )
( void ) F_46 ( V_154 ) ;
else
F_47 ( V_154 ) ;
if ( V_162 ) {
F_73 ( V_162 ) ;
if ( V_97 )
F_73 ( V_162 ) ;
V_162 -> V_138 = V_100 ;
}
V_148:
F_27 ( V_30 . V_33 ) ;
F_27 ( V_159 ) ;
F_27 ( V_163 . V_33 ) ;
F_64 ( & F_13 ( V_144 ) -> V_146 ) ;
return V_31 ;
V_170:
V_166 = 1 ;
if ( V_165 ) {
F_40 ( V_160 , F_84 ( V_154 ) -> V_169 ) ;
F_86 ( V_159 , V_161 ) ;
V_166 |= F_87 ( V_159 ) ;
}
V_168:
F_75 ( V_161 ) ;
F_85 ( V_161 , V_163 . V_149 ) ;
if ( V_162 ) {
F_85 ( V_162 , V_164 ) ;
if ( V_166 )
V_166 |= F_46 ( V_162 ) ;
} else {
int V_171 = F_72 ( V_156 , & V_30 ) ;
if ( V_166 )
V_166 |= V_171 ;
V_30 . V_33 = NULL ;
}
if ( V_166 < 0 ) {
F_88 ( V_156 -> V_51 ,
L_2 ,
V_172 , V_30 . V_149 ) ;
}
goto V_148;
}
static void F_89 ( struct V_143 * V_144 )
{
F_13 ( V_144 ) -> V_173 = & V_174 ;
if ( F_13 ( V_144 ) -> V_52 . V_175 != 's' )
V_144 -> V_176 = & V_177 ;
else
V_144 -> V_176 = & V_178 ;
}
static int F_90 ( struct V_143 * V_144 , void * V_179 , int V_180 )
{
return F_91 ( V_144 , V_179 , V_180 , 1 , F_89 ) ;
}
static struct V_1 * F_92 ( struct V_181 * V_182 ,
int V_7 , const char * V_183 ,
void * V_179 )
{
return F_93 ( V_182 , V_7 , V_183 , V_179 , F_90 ) ;
}
static int T_6 F_94 ( void )
{
return F_95 ( & V_184 ) ;
}
static void T_7 F_96 ( void )
{
F_97 ( & V_184 ) ;
}
