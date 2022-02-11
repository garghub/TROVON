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
if ( F_11 ( V_1 -> V_7 , 8L , V_35 , V_3 ) == - 1 )
return V_30 ;
V_24 = V_25 [ V_23 ] ;
V_1 -> V_36 = V_37 ;
V_1 -> V_24 = V_24 ;
V_1 -> V_38 = V_39 ;
V_1 -> V_40 = V_41 ;
V_1 -> V_42 = V_43 ;
V_28 = ( T_6 * ) F_12 ( sizeof( T_6 ) ) ;
V_1 -> V_44 = ( void * ) V_28 ;
switch ( V_23 ) {
case V_45 :
case V_46 :
case V_47 :
V_28 -> V_48 = FALSE ;
break;
case V_49 :
V_28 -> V_48 = TRUE ;
break;
}
V_1 -> V_50 = 0 ;
return V_51 ;
}
static int
F_13 ( T_1 * V_1 , T_7 V_7 , struct V_52 * V_53 ,
T_8 * V_54 , int * V_3 , T_2 * * V_4 )
{
T_6 * V_28 = ( T_6 * ) V_1 -> V_44 ;
T_9 V_55 = FALSE ;
T_10 V_56 [ 6 ] ;
T_11 V_57 ;
T_9 V_58 = FALSE ;
T_3 V_59 = 0 ;
T_3 V_60 = 0 ;
T_9 V_61 = FALSE ;
T_9 V_62 = FALSE ;
T_12 V_63 ;
T_3 V_64 = 0 ;
T_9 V_65 = FALSE ;
T_3 V_66 = 0 ;
T_13 V_67 ;
T_14 V_68 ;
struct V_69 V_70 ;
T_14 V_13 ;
int V_71 = 0 ;
T_15 V_72 ;
V_63 . V_73 = 0 ;
V_63 . V_74 = 0 ;
memset ( & V_70 , 0 , sizeof V_70 ) ;
V_70 . V_75 = - 1 ;
V_70 . V_76 = FALSE ;
V_70 . V_77 = FALSE ;
V_70 . V_78 = V_79 ;
V_70 . V_80 = 0 ;
do {
if ( ! F_14 ( V_7 , V_56 , sizeof V_56 , V_3 , V_4 ) ) {
if ( * V_3 == 0 ) {
if ( V_55 )
* V_3 = V_9 ;
}
return - 1 ;
}
V_55 = TRUE ;
V_57 = F_15 ( & V_56 [ 0 ] ) ;
switch ( V_57 ) {
case V_81 :
if ( V_58 ) {
* V_3 = V_33 ;
* V_4 = F_10 ( L_13 ) ;
return - 1 ;
}
V_59 = F_16 ( & V_56 [ 2 ] ) ;
V_58 = TRUE ;
break;
case V_82 :
if ( V_61 ) {
* V_3 = V_33 ;
* V_4 = F_10 ( L_14 ) ;
return - 1 ;
}
V_63 . V_74 = F_16 ( & V_56 [ 2 ] ) ;
V_61 = TRUE ;
break;
case V_83 :
if ( V_62 ) {
* V_3 = V_33 ;
* V_4 = F_10 ( L_15 ) ;
return - 1 ;
}
V_63 . V_73 = F_16 ( & V_56 [ 2 ] ) ;
V_62 = TRUE ;
break;
case V_84 :
break;
case V_85 :
V_70 . V_80 |= V_86 ;
V_70 . V_67 = F_16 ( & V_56 [ 2 ] ) ;
break;
case V_87 :
V_66 = F_16 ( & V_56 [ 2 ] ) ;
V_65 = TRUE ;
break;
case V_88 :
V_70 . V_80 |= V_89 ;
V_70 . V_90 = F_16 ( & V_56 [ 2 ] ) ;
break;
case V_91 :
V_70 . V_80 |= V_92 ;
V_70 . V_93 = F_16 ( & V_56 [ 2 ] ) ;
break;
case V_94 :
V_70 . V_80 |= V_95 ;
V_70 . V_96 = F_16 ( & V_56 [ 2 ] ) ;
break;
case V_97 :
V_70 . V_80 |= V_98 ;
V_70 . V_99 = F_16 ( & V_56 [ 2 ] ) ;
break;
case V_100 :
break;
case V_101 :
V_70 . V_80 |= V_102 ;
V_70 . V_68 = F_16 ( & V_56 [ 2 ] ) ;
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
break;
case V_109 :
break;
case V_110 :
V_64 = F_16 ( & V_56 [ 2 ] ) ;
if ( V_64 & V_111 ) {
V_70 . V_78 = V_112 ;
V_70 . V_113 . V_114 . V_80 = 0 ;
for ( V_13 = 0 ; V_13 < 4 ; V_13 ++ )
V_70 . V_113 . V_114 . V_115 [ V_13 ] = 0 ;
switch ( V_64 & V_116 ) {
case V_117 :
V_70 . V_113 . V_114 . V_80 |= V_118 ;
V_70 . V_113 . V_114 . V_119 = 1 ;
break;
case V_120 :
V_70 . V_113 . V_114 . V_80 |= V_118 ;
V_70 . V_113 . V_114 . V_119 = 0 ;
break;
default:
break;
}
} else {
V_70 . V_78 = V_121 ;
switch ( V_64 & V_122 ) {
case 0 :
V_70 . V_113 . V_123 . V_80 = V_124 ;
V_70 . V_113 . V_123 . V_125 = V_126 ;
break;
case V_127 :
V_70 . V_113 . V_123 . V_80 = V_124 ;
V_70 . V_113 . V_123 . V_125 = V_128 ;
break;
case V_129 :
V_70 . V_113 . V_123 . V_80 = V_124 ;
V_70 . V_113 . V_123 . V_125 = V_130 ;
break;
case V_131 :
V_70 . V_113 . V_123 . V_80 = V_124 ;
V_70 . V_113 . V_123 . V_125 = V_132 ;
break;
default:
V_70 . V_113 . V_123 . V_80 = 0 ;
break;
}
switch ( V_64 & V_116 ) {
case V_117 :
V_70 . V_113 . V_123 . V_80 |= V_133 ;
V_70 . V_113 . V_123 . V_119 = 1 ;
break;
case V_120 :
V_70 . V_113 . V_123 . V_80 |= V_133 ;
V_70 . V_113 . V_123 . V_119 = 0 ;
break;
default:
break;
}
}
break;
case V_134 :
V_60 = F_16 ( & V_56 [ 2 ] ) ;
break;
default:
break;
}
} while ( V_57 != V_134 );
if ( ! V_58 ) {
* V_3 = V_33 ;
* V_4 = F_10 ( L_16 ) ;
return - 1 ;
}
if ( ! V_61 ) {
* V_3 = V_33 ;
* V_4 = F_10 ( L_17 ) ;
return - 1 ;
}
if ( ! V_62 ) {
* V_3 = V_33 ;
* V_4 = F_10 ( L_18 ) ;
return - 1 ;
}
if ( V_60 == 0 )
V_60 = V_59 ;
if ( V_60 > V_135 ) {
* V_3 = V_33 ;
* V_4 = F_9 ( L_19 ,
V_60 , V_135 ) ;
return - 1 ;
}
V_53 -> V_136 = V_137 ;
V_53 -> V_80 = V_138 | V_139 ;
V_53 -> V_140 = V_59 ;
V_53 -> V_141 = V_60 ;
V_72 = ( ( ( T_15 ) V_63 . V_73 ) << 32 ) + V_63 . V_74 ;
if ( ! F_17 ( & V_53 -> V_142 , V_72 ) ) {
* V_3 = V_33 ;
* V_4 = F_9 ( L_20 ) ;
return - 1 ;
}
switch ( V_1 -> V_24 ) {
case V_27 :
if ( V_65 ) {
if ( V_64 & V_143 ) {
if ( ! ( V_64 & V_111 ) ) {
V_70 . V_113 . V_123 . V_80 |= V_144 ;
V_70 . V_113 . V_123 . V_145 = V_66 ;
}
} else {
V_70 . V_80 |= V_146 ;
V_70 . V_147 = V_66 ;
}
}
switch ( V_70 . V_80 & ( V_102 | V_86 ) ) {
case V_102 :
V_67 = F_18 ( V_70 . V_68 ) ;
if ( V_67 != - 1 ) {
V_70 . V_80 |= V_86 ;
V_70 . V_67 = V_67 ;
}
break;
case V_86 :
switch ( V_70 . V_78 ) {
case V_148 :
case V_149 :
case V_150 :
V_68 = F_19 ( V_70 . V_67 , TRUE ) ;
break;
case V_151 :
V_68 = F_19 ( V_70 . V_67 , FALSE ) ;
break;
default:
V_68 = 0 ;
break;
}
if ( V_68 != 0 ) {
V_70 . V_80 |= V_102 ;
V_70 . V_68 = V_68 ;
}
break;
}
V_53 -> V_152 . V_70 = V_70 ;
if ( V_28 -> V_48 )
V_53 -> V_152 . V_70 . V_75 = 4 ;
else {
if ( V_53 -> V_140 < 4 || V_53 -> V_141 < 4 ) {
* V_3 = V_33 ;
* V_4 = F_9 ( L_21 ) ;
return FALSE ;
}
V_53 -> V_152 . V_70 . V_75 = 0 ;
V_53 -> V_140 -= 4 ;
V_53 -> V_141 -= 4 ;
V_71 = 4 ;
}
V_53 -> V_152 . V_70 . V_76 = FALSE ;
V_53 -> V_152 . V_70 . V_77 = FALSE ;
break;
case V_26 :
if ( V_53 -> V_140 < 4 || V_53 -> V_141 < 4 ) {
* V_3 = V_33 ;
* V_4 = F_9 ( L_22 ) ;
return FALSE ;
}
V_53 -> V_152 . V_153 . V_75 = 0 ;
V_53 -> V_140 -= 4 ;
V_53 -> V_141 -= 4 ;
V_71 = 4 ;
break;
}
if ( ! F_20 ( V_7 , V_54 , V_53 -> V_141 , V_3 , V_4 ) )
return - 1 ;
return V_71 ;
}
static T_9 V_39 ( T_1 * V_1 , int * V_3 , T_2 * * V_4 ,
T_16 * V_154 )
{
int V_71 ;
* V_154 = F_21 ( V_1 -> V_7 ) ;
V_71 = F_13 ( V_1 , V_1 -> V_7 , & V_1 -> V_53 ,
V_1 -> V_155 , V_3 , V_4 ) ;
if ( V_71 == - 1 )
return FALSE ;
if ( V_71 != 0 ) {
if ( ! F_22 ( V_1 -> V_7 , V_71 , V_3 ) )
return FALSE ;
}
return TRUE ;
}
static T_9
V_41 ( T_1 * V_1 , T_16 V_156 ,
struct V_52 * V_53 , T_8 * V_54 , int * V_3 , T_2 * * V_4 )
{
if ( F_11 ( V_1 -> V_157 , V_156 , V_158 , V_3 ) == - 1 )
return FALSE ;
if ( F_13 ( V_1 , V_1 -> V_157 , V_53 , V_54 , V_3 , V_4 ) == - 1 ) {
if ( * V_3 == 0 )
* V_3 = V_9 ;
return FALSE ;
}
return TRUE ;
}
