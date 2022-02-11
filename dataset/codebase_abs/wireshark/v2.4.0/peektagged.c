static int F_1 ( T_1 * V_1 , const char * V_2 , int * V_3 ,
T_2 * * V_4 )
{
int V_5 ;
const char * V_6 ;
V_6 = V_2 ;
while ( * V_6 )
{
V_5 = F_2 ( V_1 -> V_7 ) ;
if ( V_5 == V_8 )
{
* V_3 = F_3 ( V_1 -> V_7 , V_4 ) ;
if ( * V_3 != 0 && * V_3 != V_9 )
return - 1 ;
return 0 ;
}
if ( V_5 == * V_6 )
V_6 ++ ;
else
{
if ( V_5 == V_2 [ 0 ] )
V_6 = & V_2 [ 1 ] ;
else
V_6 = V_2 ;
}
}
return ( * V_6 == '\0' ? 1 : 0 ) ;
}
static int F_4 ( T_1 * V_1 , char * V_10 , int V_11 ,
const char * V_12 , int * V_3 ,
T_2 * * V_4 )
{
int V_5 ;
char * V_6 ;
int V_13 ;
for ( V_6 = V_10 , V_13 = 0 ; V_13 < V_11 ; V_13 ++ , V_6 ++ )
{
V_5 = F_2 ( V_1 -> V_7 ) ;
if ( V_5 == V_8 )
{
* V_3 = F_3 ( V_1 -> V_7 , V_4 ) ;
if ( * V_3 != 0 && * V_3 != V_9 )
return - 1 ;
return 0 ;
}
if ( strchr ( V_12 , V_5 ) != NULL )
{
* V_6 = '\0' ;
break;
}
else
* V_6 = V_5 ;
}
return V_13 ;
}
static int F_5 ( T_1 * V_1 , T_3 * V_14 , int * V_3 ,
T_2 * * V_4 )
{
int V_15 ;
char V_16 [ 12 ] ;
unsigned long V_17 ;
char * V_18 ;
V_15 = F_4 ( V_1 , V_16 , sizeof ( V_16 ) - 1 , L_1 ,
V_3 , V_4 ) ;
if ( V_15 == 0 || V_15 == - 1 ) {
return V_15 ;
}
V_17 = strtoul ( V_16 , & V_18 , 10 ) ;
if ( V_18 == V_16 || V_17 > V_19 )
return 0 ;
* V_14 = ( T_3 ) V_17 ;
return 1 ;
}
T_4 F_6 ( T_1 * V_1 , int * V_3 , T_2 * * V_4 )
{
T_5 V_20 ;
int V_15 ;
T_3 V_21 = 0 ;
T_3 V_22 ;
T_3 V_23 = 0 ;
int V_24 ;
static const int V_25 [] = {
V_26 ,
V_27 ,
V_27 ,
V_27
} ;
#define F_7 (sizeof peektagged_encap / sizeof peektagged_encap[0])
T_6 * V_28 ;
if ( ! F_8 ( V_1 -> V_7 , & V_20 , ( int ) sizeof( V_20 ) , V_3 , V_4 ) ) {
if ( * V_3 != V_9 )
return V_29 ;
return V_30 ;
}
if ( memcmp ( V_20 . V_31 , L_2 , sizeof( V_20 . V_31 ) ) != 0 )
return V_30 ;
V_15 = F_1 ( V_1 , L_3 , V_3 , V_4 ) ;
if ( V_15 == - 1 )
return V_29 ;
if ( V_15 == 0 ) {
return V_30 ;
}
V_15 = F_5 ( V_1 , & V_21 , V_3 , V_4 ) ;
if ( V_15 == - 1 )
return V_29 ;
if ( V_15 == 0 ) {
return V_30 ;
}
if ( V_21 != 9 ) {
* V_3 = V_32 ;
* V_4 = F_9 ( L_4 ,
V_21 ) ;
return V_29 ;
}
V_15 = F_1 ( V_1 , L_5 , V_3 , V_4 ) ;
if ( V_15 == - 1 )
return V_29 ;
if ( V_15 == 0 ) {
* V_3 = V_33 ;
* V_4 = F_10 ( L_6 ) ;
return V_29 ;
}
V_15 = F_5 ( V_1 , & V_22 , V_3 , V_4 ) ;
if ( V_15 == - 1 )
return V_29 ;
if ( V_15 == 0 ) {
* V_3 = V_33 ;
* V_4 = F_10 ( L_7 ) ;
return V_29 ;
}
V_15 = F_1 ( V_1 , L_8 , V_3 , V_4 ) ;
if ( V_15 == - 1 )
return V_29 ;
if ( V_15 == 0 ) {
* V_3 = V_33 ;
* V_4 = F_10 ( L_9 ) ;
return V_29 ;
}
V_15 = F_5 ( V_1 , & V_23 , V_3 , V_4 ) ;
if ( V_15 == - 1 )
return V_29 ;
if ( V_15 == 0 ) {
* V_3 = V_33 ;
* V_4 = F_10 ( L_10 ) ;
return V_29 ;
}
if ( V_23 >= F_7
|| V_25 [ V_23 ] == V_34 ) {
* V_3 = V_32 ;
* V_4 = F_9 ( L_11 ,
V_23 ) ;
return V_29 ;
}
V_15 = F_1 ( V_1 , L_12 , V_3 , V_4 ) ;
if ( V_15 == - 1 )
return V_29 ;
if ( V_15 == 0 ) {
* V_3 = V_9 ;
return V_29 ;
}
if ( ! F_8 ( V_1 -> V_7 , NULL , 8 , V_3 , V_4 ) ) {
return V_29 ;
}
V_24 = V_25 [ V_23 ] ;
V_1 -> V_35 = V_36 ;
V_1 -> V_24 = V_24 ;
V_1 -> V_37 = V_38 ;
V_1 -> V_39 = V_40 ;
V_1 -> V_41 = V_42 ;
V_28 = ( T_6 * ) F_11 ( sizeof( T_6 ) ) ;
V_1 -> V_43 = ( void * ) V_28 ;
switch ( V_23 ) {
case V_44 :
case V_45 :
case V_46 :
V_28 -> V_47 = FALSE ;
break;
case V_48 :
V_28 -> V_47 = TRUE ;
break;
}
V_1 -> V_49 = 0 ;
return V_50 ;
}
static int
F_12 ( T_1 * V_1 , T_7 V_7 , struct V_51 * V_52 ,
T_8 * V_53 , int * V_3 , T_2 * * V_4 )
{
T_6 * V_28 = ( T_6 * ) V_1 -> V_43 ;
T_9 V_54 = FALSE ;
T_10 V_55 [ 6 ] ;
T_11 V_56 ;
T_9 V_57 = FALSE ;
T_3 V_58 = 0 ;
T_3 V_59 = 0 ;
T_9 V_60 = FALSE ;
T_9 V_61 = FALSE ;
T_12 V_62 ;
T_3 V_63 = 0 ;
T_9 V_64 = FALSE ;
T_3 V_65 = 0 ;
T_13 V_66 ;
T_14 V_67 ;
struct V_68 V_69 ;
T_14 V_13 ;
int V_70 = 0 ;
T_15 V_71 ;
V_62 . V_72 = 0 ;
V_62 . V_73 = 0 ;
memset ( & V_69 , 0 , sizeof V_69 ) ;
V_69 . V_74 = - 1 ;
V_69 . V_75 = FALSE ;
V_69 . V_76 = FALSE ;
V_69 . V_77 = V_78 ;
do {
if ( ! F_13 ( V_7 , V_55 , sizeof V_55 , V_3 , V_4 ) ) {
if ( * V_3 == 0 ) {
if ( V_54 )
* V_3 = V_9 ;
}
return - 1 ;
}
V_54 = TRUE ;
V_56 = F_14 ( & V_55 [ 0 ] ) ;
switch ( V_56 ) {
case V_79 :
if ( V_57 ) {
* V_3 = V_33 ;
* V_4 = F_10 ( L_13 ) ;
return - 1 ;
}
V_58 = F_15 ( & V_55 [ 2 ] ) ;
V_57 = TRUE ;
break;
case V_80 :
if ( V_60 ) {
* V_3 = V_33 ;
* V_4 = F_10 ( L_14 ) ;
return - 1 ;
}
V_62 . V_73 = F_15 ( & V_55 [ 2 ] ) ;
V_60 = TRUE ;
break;
case V_81 :
if ( V_61 ) {
* V_3 = V_33 ;
* V_4 = F_10 ( L_15 ) ;
return - 1 ;
}
V_62 . V_72 = F_15 ( & V_55 [ 2 ] ) ;
V_61 = TRUE ;
break;
case V_82 :
break;
case V_83 :
V_69 . V_84 = TRUE ;
V_69 . V_66 = F_15 ( & V_55 [ 2 ] ) ;
break;
case V_85 :
V_65 = F_15 ( & V_55 [ 2 ] ) ;
V_64 = TRUE ;
break;
case V_86 :
V_69 . V_87 = TRUE ;
V_69 . V_88 = F_15 ( & V_55 [ 2 ] ) ;
break;
case V_89 :
V_69 . V_90 = TRUE ;
V_69 . V_91 = F_15 ( & V_55 [ 2 ] ) ;
break;
case V_92 :
V_69 . V_93 = TRUE ;
V_69 . V_94 = F_15 ( & V_55 [ 2 ] ) ;
break;
case V_95 :
V_69 . V_96 = TRUE ;
V_69 . V_97 = F_15 ( & V_55 [ 2 ] ) ;
break;
case V_98 :
break;
case V_99 :
V_69 . V_100 = TRUE ;
V_69 . V_67 = F_15 ( & V_55 [ 2 ] ) ;
break;
case V_101 :
break;
case V_102 :
break;
case V_103 :
break;
case V_104 :
break;
case V_105 :
break;
case V_106 :
break;
case V_107 :
break;
case V_108 :
V_63 = F_15 ( & V_55 [ 2 ] ) ;
if ( V_63 & V_109 ) {
V_69 . V_77 = V_110 ;
for ( V_13 = 0 ; V_13 < 4 ; V_13 ++ )
V_69 . V_111 . V_112 . V_113 [ V_13 ] = 0 ;
switch ( V_63 & V_114 ) {
case V_115 :
V_69 . V_111 . V_112 . V_116 = TRUE ;
V_69 . V_111 . V_112 . V_117 = 1 ;
break;
case V_118 :
V_69 . V_111 . V_112 . V_116 = TRUE ;
V_69 . V_111 . V_112 . V_117 = 0 ;
break;
default:
break;
}
} else {
V_69 . V_77 = V_119 ;
switch ( V_63 & V_120 ) {
case 0 :
V_69 . V_111 . V_121 . V_122 = TRUE ;
V_69 . V_111 . V_121 . V_123 = V_124 ;
break;
case V_125 :
V_69 . V_111 . V_121 . V_122 = TRUE ;
V_69 . V_111 . V_121 . V_123 = V_126 ;
break;
case V_127 :
V_69 . V_111 . V_121 . V_122 = TRUE ;
V_69 . V_111 . V_121 . V_123 = V_128 ;
break;
case V_129 :
V_69 . V_111 . V_121 . V_122 = TRUE ;
V_69 . V_111 . V_121 . V_123 = V_130 ;
break;
default:
break;
}
switch ( V_63 & V_114 ) {
case V_115 :
V_69 . V_111 . V_121 . V_116 = TRUE ;
V_69 . V_111 . V_121 . V_117 = 1 ;
break;
case V_118 :
V_69 . V_111 . V_121 . V_116 = TRUE ;
V_69 . V_111 . V_121 . V_117 = 0 ;
break;
default:
break;
}
}
break;
case V_131 :
V_59 = F_15 ( & V_55 [ 2 ] ) ;
break;
default:
break;
}
} while ( V_56 != V_131 );
if ( ! V_57 ) {
* V_3 = V_33 ;
* V_4 = F_10 ( L_16 ) ;
return - 1 ;
}
if ( ! V_60 ) {
* V_3 = V_33 ;
* V_4 = F_10 ( L_17 ) ;
return - 1 ;
}
if ( ! V_61 ) {
* V_3 = V_33 ;
* V_4 = F_10 ( L_18 ) ;
return - 1 ;
}
if ( V_59 == 0 )
V_59 = V_58 ;
if ( V_59 > V_132 ) {
* V_3 = V_33 ;
* V_4 = F_9 ( L_19 ,
V_59 , V_132 ) ;
return - 1 ;
}
V_52 -> V_133 = V_134 ;
V_52 -> V_135 = V_136 | V_137 ;
V_52 -> V_138 = V_58 ;
V_52 -> V_139 = V_59 ;
V_71 = ( ( ( T_15 ) V_62 . V_72 ) << 32 ) + V_62 . V_73 ;
if ( ! F_16 ( & V_52 -> V_140 , V_71 ) ) {
* V_3 = V_33 ;
* V_4 = F_10 ( L_20 ) ;
return - 1 ;
}
switch ( V_1 -> V_24 ) {
case V_27 :
if ( V_64 ) {
if ( V_63 & V_141 ) {
if ( ! ( V_63 & V_109 ) ) {
V_69 . V_111 . V_121 . V_142 = TRUE ;
V_69 . V_111 . V_121 . V_143 = V_65 ;
}
} else {
V_69 . V_144 = TRUE ;
V_69 . V_145 = V_65 ;
}
}
if ( V_69 . V_100 && ! V_69 . V_84 ) {
V_66 = F_17 ( V_69 . V_67 ) ;
if ( V_66 != - 1 ) {
V_69 . V_84 = TRUE ;
V_69 . V_66 = V_66 ;
}
} else if ( V_69 . V_84 && ! V_69 . V_100 ) {
switch ( V_69 . V_77 ) {
case V_146 :
case V_147 :
case V_148 :
V_67 = F_18 ( V_69 . V_66 , TRUE ) ;
break;
case V_149 :
V_67 = F_18 ( V_69 . V_66 , FALSE ) ;
break;
default:
V_67 = 0 ;
break;
}
if ( V_67 != 0 ) {
V_69 . V_100 = TRUE ;
V_69 . V_67 = V_67 ;
}
}
V_52 -> V_150 . V_69 = V_69 ;
if ( V_28 -> V_47 )
V_52 -> V_150 . V_69 . V_74 = 4 ;
else {
if ( V_52 -> V_138 < 4 || V_52 -> V_139 < 4 ) {
* V_3 = V_33 ;
* V_4 = F_9 ( L_21 ) ;
return FALSE ;
}
V_52 -> V_150 . V_69 . V_74 = 0 ;
V_52 -> V_138 -= 4 ;
V_52 -> V_139 -= 4 ;
V_70 = 4 ;
}
V_52 -> V_150 . V_69 . V_75 = FALSE ;
V_52 -> V_150 . V_69 . V_76 = FALSE ;
break;
case V_26 :
if ( V_52 -> V_138 < 4 || V_52 -> V_139 < 4 ) {
* V_3 = V_33 ;
* V_4 = F_9 ( L_22 ) ;
return FALSE ;
}
V_52 -> V_150 . V_151 . V_74 = 0 ;
V_52 -> V_138 -= 4 ;
V_52 -> V_139 -= 4 ;
V_70 = 4 ;
break;
}
if ( ! F_19 ( V_7 , V_53 , V_52 -> V_139 , V_3 , V_4 ) )
return - 1 ;
return V_70 ;
}
static T_9 V_38 ( T_1 * V_1 , int * V_3 , T_2 * * V_4 ,
T_16 * V_152 )
{
int V_70 ;
* V_152 = F_20 ( V_1 -> V_7 ) ;
V_70 = F_12 ( V_1 , V_1 -> V_7 , & V_1 -> V_52 ,
V_1 -> V_153 , V_3 , V_4 ) ;
if ( V_70 == - 1 )
return FALSE ;
if ( V_70 != 0 ) {
if ( ! F_8 ( V_1 -> V_7 , NULL , V_70 , V_3 , V_4 ) )
return FALSE ;
}
return TRUE ;
}
static T_9
V_40 ( T_1 * V_1 , T_16 V_154 ,
struct V_51 * V_52 , T_8 * V_53 , int * V_3 , T_2 * * V_4 )
{
if ( F_21 ( V_1 -> V_155 , V_154 , V_156 , V_3 ) == - 1 )
return FALSE ;
if ( F_12 ( V_1 , V_1 -> V_155 , V_52 , V_53 , V_3 , V_4 ) == - 1 ) {
if ( * V_3 == 0 )
* V_3 = V_9 ;
return FALSE ;
}
return TRUE ;
}
