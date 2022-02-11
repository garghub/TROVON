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
unsigned char * V_88 ;
int V_26 , V_89 ;
int V_90 ;
if ( V_87 ) {
* V_85 = F_36 ( V_14 , V_13 , V_91 ,
( T_1 * ) V_83 , V_92 + 2 ) ;
if ( * V_85 < 0 )
return * V_85 ;
else if ( * V_85 > V_92 )
return - V_93 ;
V_88 = & V_83 [ * V_85 * sizeof( T_1 ) ] ;
} else {
for ( V_26 = 0 , V_54 = V_14 , V_88 = V_83 , * V_85 = 0 ;
V_26 < V_13 && * V_85 < V_92 ;
* V_85 += 1 ) {
if ( V_86 && ( * V_54 == ':' ) ) {
T_2 V_94 [ 2 ] ;
if ( V_26 > V_13 - 5 )
return - V_27 ;
if ( F_37 ( V_94 , V_54 + 1 , 2 ) < 0 )
return - V_27 ;
* ( T_1 * ) V_88 = V_94 [ 0 ] << 8 | V_94 [ 1 ] ;
V_88 += 2 ;
V_54 += 5 ;
V_26 += 5 ;
} else {
V_90 = V_35 -> V_95 ( V_54 , V_13 - V_26 ,
( T_1 * ) V_88 ) ;
if ( V_90 < 0 )
return - V_27 ;
V_54 += V_90 ;
V_26 += V_90 ;
V_88 += 2 ;
}
}
if ( V_26 < V_13 )
return - V_93 ;
}
* V_84 = * V_85 ;
if ( * V_85 % 13 ) {
* V_88 ++ = 0 ;
* V_88 ++ = 0 ;
* V_85 += 1 ;
if ( * V_85 % 13 ) {
V_89 = 13 - ( * V_85 % 13 ) ;
for ( V_26 = 0 ; V_26 < V_89 ; V_26 ++ ) {
* V_88 ++ = 0xff ;
* V_88 ++ = 0xff ;
}
* V_85 += V_89 ;
}
}
return 0 ;
}
static int F_38 ( struct V_28 * V_29 , const unsigned char * V_14 ,
int V_13 , int V_96 , int V_97 ,
struct V_98 * V_99 ,
struct V_100 * V_101 , int * V_102 )
{
struct V_103 * V_104 = F_15 ( V_29 -> V_52 ) ;
struct V_50 * V_51 = & V_104 -> V_53 ;
struct V_100 * V_105 ;
struct V_106 * V_107 ;
unsigned char V_108 , V_49 ;
unsigned char V_109 [ V_74 ] ;
T_1 * V_46 ;
T_3 time , V_110 ;
T_2 V_111 ;
int V_32 , V_47 , V_112 , V_26 ;
T_4 V_113 ;
* V_102 = 0 ;
V_46 = F_39 () ;
if ( ! V_46 )
return - V_114 ;
V_32 = F_35 ( V_14 , V_13 , ( unsigned char * ) V_46 , & V_47 , & V_112 ,
V_51 -> V_115 , V_51 -> V_87 , V_104 -> V_20 ) ;
if ( V_32 )
goto V_116;
V_32 = F_26 ( V_46 , V_47 ) ;
if ( V_32 )
goto V_116;
V_32 = F_32 ( V_29 , V_104 -> V_117 , V_46 , V_47 ,
V_109 , & V_49 ) ;
if ( V_32 < 0 )
goto V_116;
else if ( V_32 == 1 ) {
V_107 = (struct V_106 * ) V_101 ;
V_32 = 0 ;
goto V_76;
}
V_108 = F_40 ( V_109 ) ;
* V_102 = V_112 / 13 ;
for ( V_105 = V_101 , V_26 = * V_102 ; V_26 > 0 ; V_26 -- , V_105 ++ ) {
V_105 -> V_118 = V_26 ;
V_105 -> V_119 = V_120 ;
V_105 -> V_121 = 0 ;
V_105 -> V_122 = V_108 ;
V_105 -> V_123 = 0 ;
V_113 = ( V_26 - 1 ) * 13 ;
F_41 ( V_105 -> V_124 , V_46 + V_113 , 5 ) ;
F_41 ( V_105 -> V_125 , V_46 + V_113 + 5 , 6 ) ;
F_41 ( V_105 -> V_126 , V_46 + V_113 + 11 , 2 ) ;
}
V_101 [ 0 ] . V_118 |= 0x40 ;
V_107 = (struct V_106 * ) V_105 ;
V_76:
( * V_102 ) ++ ;
memcpy ( V_107 -> V_14 , V_109 , V_74 ) ;
V_107 -> V_119 = V_96 ? V_127 : V_128 ;
V_107 -> V_49 = V_49 ;
F_42 ( V_104 , V_99 , & time , & V_110 , & V_111 ) ;
V_107 -> time = V_107 -> ctime = time ;
V_107 -> V_110 = V_107 -> V_129 = V_107 -> V_130 = V_110 ;
V_107 -> V_131 = V_111 ;
F_43 ( V_107 , V_97 ) ;
V_107 -> V_132 = 0 ;
V_116:
F_44 ( V_46 ) ;
return V_32 ;
}
static int F_45 ( struct V_28 * V_29 , const struct V_15 * V_133 ,
int V_96 , int V_97 , struct V_98 * V_99 ,
struct V_30 * V_31 )
{
struct V_100 * V_101 ;
unsigned int V_13 ;
int V_32 , V_102 ;
V_13 = F_11 ( V_133 ) ;
if ( V_13 == 0 )
return - V_33 ;
V_101 = F_46 ( sizeof( * V_101 ) * V_134 , V_135 ) ;
if ( V_101 == NULL )
return - V_114 ;
V_32 = F_38 ( V_29 , V_133 -> V_14 , V_13 , V_96 , V_97 , V_99 ,
V_101 , & V_102 ) ;
if ( V_32 )
goto V_136;
V_32 = F_47 ( V_29 , V_101 , V_102 , V_31 ) ;
if ( V_32 )
goto V_136;
V_29 -> V_137 = V_29 -> V_138 = V_29 -> V_139 = * V_99 ;
if ( F_48 ( V_29 ) )
( void ) F_49 ( V_29 ) ;
else
F_50 ( V_29 ) ;
V_136:
F_51 ( V_101 ) ;
return V_32 ;
}
static int F_52 ( struct V_28 * V_29 , const struct V_15 * V_133 ,
struct V_30 * V_31 )
{
unsigned int V_13 = F_11 ( V_133 ) ;
if ( V_13 == 0 )
return - V_33 ;
return F_53 ( V_29 , V_133 -> V_14 , V_13 , V_31 ) ;
}
static int F_54 ( struct V_1 * V_1 )
{
return F_55 ( V_1 ) && ( V_1 -> V_140 & V_141 ) ;
}
static struct V_1 * F_56 ( struct V_28 * V_29 , struct V_1 * V_1 ,
unsigned int V_8 )
{
struct V_142 * V_143 = V_29 -> V_52 ;
struct V_30 V_31 ;
struct V_28 * V_28 ;
struct V_1 * V_144 ;
int V_32 ;
F_57 ( & F_15 ( V_143 ) -> V_145 ) ;
V_32 = F_52 ( V_29 , & V_1 -> V_146 , & V_31 ) ;
if ( V_32 ) {
if ( V_32 == - V_33 ) {
V_28 = NULL ;
goto V_147;
}
goto error;
}
V_28 = F_58 ( V_143 , V_31 . V_107 , V_31 . V_148 ) ;
F_29 ( V_31 . V_34 ) ;
if ( F_59 ( V_28 ) ) {
V_32 = F_60 ( V_28 ) ;
goto error;
}
V_144 = F_61 ( V_28 ) ;
if ( V_144 && V_144 -> V_6 == V_1 -> V_6 &&
! F_54 ( V_144 ) ) {
F_62 ( F_63 ( V_144 ) ) ;
if ( ! F_64 ( V_28 -> V_149 ) )
F_65 ( V_144 , V_1 ) ;
F_66 ( V_28 ) ;
F_67 ( & F_15 ( V_143 ) -> V_145 ) ;
return V_144 ;
} else
F_68 ( V_144 ) ;
V_147:
F_67 ( & F_15 ( V_143 ) -> V_145 ) ;
if ( ! V_28 )
F_2 ( V_1 , V_29 -> V_7 ) ;
return F_69 ( V_28 , V_1 ) ;
error:
F_67 ( & F_15 ( V_143 ) -> V_145 ) ;
return F_70 ( V_32 ) ;
}
static int F_71 ( struct V_28 * V_29 , struct V_1 * V_1 , T_5 V_150 ,
bool V_151 )
{
struct V_142 * V_143 = V_29 -> V_52 ;
struct V_28 * V_28 ;
struct V_30 V_31 ;
struct V_98 V_99 ;
int V_32 ;
F_57 ( & F_15 ( V_143 ) -> V_145 ) ;
V_99 = F_72 ( V_29 ) ;
V_32 = F_45 ( V_29 , & V_1 -> V_146 , 0 , 0 , & V_99 , & V_31 ) ;
if ( V_32 )
goto V_147;
V_29 -> V_7 ++ ;
V_28 = F_58 ( V_143 , V_31 . V_107 , V_31 . V_148 ) ;
F_29 ( V_31 . V_34 ) ;
if ( F_59 ( V_28 ) ) {
V_32 = F_60 ( V_28 ) ;
goto V_147;
}
V_28 -> V_7 ++ ;
V_28 -> V_138 = V_28 -> V_139 = V_28 -> V_137 = V_99 ;
F_73 ( V_1 , V_28 ) ;
V_147:
F_67 ( & F_15 ( V_143 ) -> V_145 ) ;
return V_32 ;
}
static int F_74 ( struct V_28 * V_29 , struct V_1 * V_1 )
{
struct V_28 * V_28 = F_5 ( V_1 ) ;
struct V_142 * V_143 = V_29 -> V_52 ;
struct V_30 V_31 ;
int V_32 ;
F_57 ( & F_15 ( V_143 ) -> V_145 ) ;
V_32 = F_75 ( V_28 ) ;
if ( V_32 )
goto V_147;
V_32 = F_52 ( V_29 , & V_1 -> V_146 , & V_31 ) ;
if ( V_32 )
goto V_147;
V_32 = F_76 ( V_29 , & V_31 ) ;
if ( V_32 )
goto V_147;
F_77 ( V_29 ) ;
F_78 ( V_28 ) ;
V_28 -> V_138 = V_28 -> V_139 = F_72 ( V_28 ) ;
F_79 ( V_28 ) ;
F_2 ( V_1 , V_29 -> V_7 ) ;
V_147:
F_67 ( & F_15 ( V_143 ) -> V_145 ) ;
return V_32 ;
}
static int F_80 ( struct V_28 * V_29 , struct V_1 * V_1 )
{
struct V_28 * V_28 = F_5 ( V_1 ) ;
struct V_142 * V_143 = V_29 -> V_52 ;
struct V_30 V_31 ;
int V_32 ;
F_57 ( & F_15 ( V_143 ) -> V_145 ) ;
V_32 = F_52 ( V_29 , & V_1 -> V_146 , & V_31 ) ;
if ( V_32 )
goto V_147;
V_32 = F_76 ( V_29 , & V_31 ) ;
if ( V_32 )
goto V_147;
F_78 ( V_28 ) ;
V_28 -> V_138 = V_28 -> V_139 = F_72 ( V_28 ) ;
F_79 ( V_28 ) ;
F_2 ( V_1 , V_29 -> V_7 ) ;
V_147:
F_67 ( & F_15 ( V_143 ) -> V_145 ) ;
return V_32 ;
}
static int F_81 ( struct V_28 * V_29 , struct V_1 * V_1 , T_5 V_150 )
{
struct V_142 * V_143 = V_29 -> V_52 ;
struct V_28 * V_28 ;
struct V_30 V_31 ;
struct V_98 V_99 ;
int V_32 , V_97 ;
F_57 ( & F_15 ( V_143 ) -> V_145 ) ;
V_99 = F_72 ( V_29 ) ;
V_97 = F_82 ( V_29 , & V_99 ) ;
if ( V_97 < 0 ) {
V_32 = V_97 ;
goto V_147;
}
V_32 = F_45 ( V_29 , & V_1 -> V_146 , 1 , V_97 , & V_99 , & V_31 ) ;
if ( V_32 )
goto V_116;
V_29 -> V_7 ++ ;
F_83 ( V_29 ) ;
V_28 = F_58 ( V_143 , V_31 . V_107 , V_31 . V_148 ) ;
F_29 ( V_31 . V_34 ) ;
if ( F_59 ( V_28 ) ) {
V_32 = F_60 ( V_28 ) ;
goto V_147;
}
V_28 -> V_7 ++ ;
F_84 ( V_28 , 2 ) ;
V_28 -> V_138 = V_28 -> V_139 = V_28 -> V_137 = V_99 ;
F_73 ( V_1 , V_28 ) ;
F_67 ( & F_15 ( V_143 ) -> V_145 ) ;
return 0 ;
V_116:
F_85 ( V_29 , V_97 ) ;
V_147:
F_67 ( & F_15 ( V_143 ) -> V_145 ) ;
return V_32 ;
}
static int F_86 ( struct V_28 * V_152 , struct V_1 * V_153 ,
struct V_28 * V_154 , struct V_1 * V_155 ,
unsigned int V_8 )
{
struct V_156 * V_157 ;
struct V_106 * V_158 ;
struct V_28 * V_159 , * V_160 ;
struct V_30 V_161 , V_31 ;
struct V_98 V_99 ;
T_4 V_162 ;
int V_32 , V_96 , V_163 , V_164 = 0 ;
struct V_142 * V_143 = V_152 -> V_52 ;
if ( V_8 & ~ V_165 )
return - V_27 ;
V_161 . V_34 = V_31 . V_34 = V_157 = NULL ;
V_159 = F_5 ( V_153 ) ;
V_160 = F_5 ( V_155 ) ;
F_57 ( & F_15 ( V_143 ) -> V_145 ) ;
V_32 = F_52 ( V_152 , & V_153 -> V_146 , & V_161 ) ;
if ( V_32 )
goto V_147;
V_96 = F_64 ( V_159 -> V_149 ) ;
V_163 = ( V_96 && V_152 != V_154 ) ;
if ( V_163 ) {
if ( F_87 ( V_159 , & V_157 , & V_158 ) ) {
V_32 = - V_166 ;
goto V_147;
}
}
V_99 = F_72 ( V_152 ) ;
if ( V_160 ) {
if ( V_96 ) {
V_32 = F_75 ( V_160 ) ;
if ( V_32 )
goto V_147;
}
V_162 = F_88 ( V_160 ) -> V_148 ;
F_79 ( V_160 ) ;
} else {
V_32 = F_45 ( V_154 , & V_155 -> V_146 , V_96 , 0 ,
& V_99 , & V_31 ) ;
if ( V_32 )
goto V_147;
V_162 = V_31 . V_148 ;
}
V_154 -> V_7 ++ ;
F_79 ( V_159 ) ;
F_89 ( V_159 , V_162 ) ;
if ( F_48 ( V_154 ) ) {
V_32 = F_49 ( V_159 ) ;
if ( V_32 )
goto V_167;
} else
F_50 ( V_159 ) ;
if ( V_163 ) {
F_43 ( V_158 , F_88 ( V_154 ) -> V_168 ) ;
F_90 ( V_157 , V_159 ) ;
if ( F_48 ( V_154 ) ) {
V_32 = F_91 ( V_157 ) ;
if ( V_32 )
goto V_169;
}
F_77 ( V_152 ) ;
if ( ! V_160 )
F_83 ( V_154 ) ;
}
V_32 = F_76 ( V_152 , & V_161 ) ;
V_161 . V_34 = NULL ;
if ( V_32 )
goto V_169;
V_152 -> V_7 ++ ;
V_152 -> V_137 = V_152 -> V_138 = V_99 ;
if ( F_48 ( V_152 ) )
( void ) F_49 ( V_152 ) ;
else
F_50 ( V_152 ) ;
if ( V_160 ) {
F_77 ( V_160 ) ;
if ( V_96 )
F_77 ( V_160 ) ;
V_160 -> V_137 = V_99 ;
}
V_147:
F_29 ( V_31 . V_34 ) ;
F_29 ( V_157 ) ;
F_29 ( V_161 . V_34 ) ;
F_67 ( & F_15 ( V_143 ) -> V_145 ) ;
return V_32 ;
V_169:
V_164 = 1 ;
if ( V_163 ) {
F_43 ( V_158 , F_88 ( V_152 ) -> V_168 ) ;
F_90 ( V_157 , V_159 ) ;
V_164 |= F_91 ( V_157 ) ;
}
V_167:
F_79 ( V_159 ) ;
F_89 ( V_159 , V_161 . V_148 ) ;
if ( V_160 ) {
F_89 ( V_160 , V_162 ) ;
if ( V_164 )
V_164 |= F_49 ( V_160 ) ;
} else {
int V_170 = F_76 ( V_154 , & V_31 ) ;
if ( V_164 )
V_164 |= V_170 ;
V_31 . V_34 = NULL ;
}
if ( V_164 < 0 ) {
F_92 ( V_154 -> V_52 ,
L_2 ,
V_171 , V_31 . V_148 ) ;
}
goto V_147;
}
static void F_93 ( struct V_142 * V_143 )
{
F_15 ( V_143 ) -> V_172 = & V_173 ;
if ( F_15 ( V_143 ) -> V_53 . V_174 != 's' )
V_143 -> V_175 = & V_176 ;
else
V_143 -> V_175 = & V_177 ;
}
static int F_94 ( struct V_142 * V_143 , void * V_178 , int V_179 )
{
return F_95 ( V_143 , V_178 , V_179 , 1 , F_93 ) ;
}
static struct V_1 * F_96 ( struct V_180 * V_181 ,
int V_8 , const char * V_182 ,
void * V_178 )
{
return F_97 ( V_181 , V_8 , V_182 , V_178 , F_94 ) ;
}
static int T_6 F_98 ( void )
{
return F_99 ( & V_183 ) ;
}
static void T_7 F_100 ( void )
{
F_101 ( & V_183 ) ;
}
