static T_1
F_1 ( T_2 * * V_1 , const T_2 * V_2 )
{
T_3 V_3 = 0 , V_4 ;
T_1 V_5 ;
T_4 V_6 ;
T_3 V_7 , V_8 ;
if( V_2 != NULL )
{
V_4 = ( T_3 ) strlen ( V_2 ) ;
if( ( V_4 > 2 ) && ( V_2 [ 0 ] == '0' ) && ( ( V_2 [ 1 ] == 'x' ) || ( V_2 [ 1 ] == 'X' ) ) )
{
V_7 = 2 ;
V_8 = 0 ;
if( V_4 % 2 == 1 )
{
V_3 = ( V_4 - 2 ) / 2 + 1 ;
* V_1 = ( T_2 * ) F_2 ( ( V_3 + 1 ) * sizeof( T_2 ) ) ;
V_5 = F_3 ( V_2 [ V_7 ] ) ;
V_7 ++ ;
if ( V_5 == - 1 )
{
F_4 ( * V_1 ) ;
* V_1 = NULL ;
return - 1 ;
}
( * V_1 ) [ V_8 ] = ( T_4 ) V_5 ;
V_8 ++ ;
}
else
{
V_3 = ( V_4 - 2 ) / 2 ;
* V_1 = ( T_2 * ) F_2 ( ( V_3 + 1 ) * sizeof( T_2 ) ) ;
}
while( V_7 < ( V_4 - 1 ) )
{
V_5 = F_3 ( V_2 [ V_7 ] ) ;
V_7 ++ ;
if ( V_5 == - 1 )
{
F_4 ( * V_1 ) ;
* V_1 = NULL ;
return - 1 ;
}
V_6 = ( ( T_4 ) V_5 ) << 4 ;
V_5 = F_3 ( V_2 [ V_7 ] ) ;
V_7 ++ ;
if ( V_5 == - 1 )
{
F_4 ( * V_1 ) ;
* V_1 = NULL ;
return - 1 ;
}
V_6 |= ( T_4 ) V_5 ;
( * V_1 ) [ V_8 ] = V_6 ;
V_8 ++ ;
}
( * V_1 ) [ V_8 ] = '\0' ;
}
else if( ( V_4 == 2 ) && ( V_2 [ 0 ] == '0' ) && ( ( V_2 [ 1 ] == 'x' ) || ( V_2 [ 1 ] == 'X' ) ) )
{
return 0 ;
}
else
{
V_3 = V_4 ;
* V_1 = F_5 ( V_2 ) ;
}
}
return V_3 ;
}
static T_5 F_6 ( void * V_9 , char * * T_6 V_10 ) {
T_7 * V_11 = ( T_7 * ) V_9 ;
if ( V_11 -> V_12 ) {
V_11 -> V_13 = F_1 ( & V_11 -> V_14 , V_11 -> V_12 ) ;
V_11 -> V_15 = FALSE ;
}
else {
V_11 -> V_13 = 0 ;
V_11 -> V_14 = NULL ;
}
if ( V_11 -> V_16 ) {
V_11 -> V_17 = F_1 ( & V_11 -> V_18 , V_11 -> V_16 ) ;
}
else {
V_11 -> V_17 = 0 ;
V_11 -> V_18 = NULL ;
}
return TRUE ;
}
static void * F_7 ( void * V_19 , const void * V_20 , T_8 T_9 V_10 ) {
T_7 * V_21 = ( T_7 * ) V_19 ;
const T_7 * V_22 = ( const T_7 * ) V_20 ;
V_21 -> V_23 = V_22 -> V_23 ;
V_21 -> V_24 = ( V_22 -> V_24 ) ? F_5 ( V_22 -> V_24 ) : NULL ;
V_21 -> V_25 = ( V_22 -> V_25 ) ? F_5 ( V_22 -> V_25 ) : NULL ;
V_21 -> V_26 = ( V_22 -> V_26 ) ? F_5 ( V_22 -> V_26 ) : NULL ;
V_21 -> V_27 = V_22 -> V_27 ;
V_21 -> V_12 = ( V_22 -> V_12 ) ? F_5 ( V_22 -> V_12 ) : NULL ;
V_21 -> V_28 = V_22 -> V_28 ;
V_21 -> V_16 = ( V_22 -> V_16 ) ? F_5 ( V_22 -> V_16 ) : NULL ;
F_6 ( V_21 , NULL ) ;
return V_21 ;
}
static void F_8 ( void * V_9 ) {
T_7 * V_11 = ( T_7 * ) V_9 ;
F_4 ( V_11 -> V_24 ) ;
F_4 ( V_11 -> V_25 ) ;
F_4 ( V_11 -> V_26 ) ;
F_4 ( V_11 -> V_12 ) ;
F_4 ( V_11 -> V_14 ) ;
F_4 ( V_11 -> V_16 ) ;
F_4 ( V_11 -> V_18 ) ;
if ( V_11 -> V_15 ) {
F_9 ( V_11 -> V_29 ) ;
V_11 -> V_15 = FALSE ;
}
}
void F_10 ( T_10 V_23 , const T_2 * V_24 , const char * V_25 ,
T_2 * V_26 ,
T_10 V_27 , const T_2 * V_14 ,
T_10 V_28 , const T_2 * V_18 )
{
T_7 * V_30 = NULL ;
if ( V_31 . V_32 == 0 ) {
V_31 . V_33 = ( T_7 * ) F_2 ( sizeof( T_7 ) * V_34 ) ;
}
if ( V_31 . V_32 < V_34 ) {
V_30 = & V_31 . V_33 [ V_31 . V_32 ++ ] ;
}
else {
fprintf ( V_35 , L_1 ,
V_34 ) ;
return;
}
V_30 -> V_23 = V_23 ;
V_30 -> V_24 = F_5 ( V_24 ) ;
V_30 -> V_25 = F_5 ( V_25 ) ;
V_30 -> V_26 = F_5 ( V_26 ) ;
V_30 -> V_27 = V_27 ;
V_30 -> V_12 = F_5 ( V_14 ) ;
V_30 -> V_28 = V_28 ;
if ( V_18 ) {
V_30 -> V_16 = F_5 ( V_18 ) ;
}
else {
V_30 -> V_16 = NULL ;
}
F_6 ( V_30 , NULL ) ;
}
static void F_11 ( T_11 V_26 , T_11 V_36 , T_12 * V_37 )
{
T_13 * V_38 = ( T_13 * ) F_12 ( V_39 ,
F_13 ( ( T_3 ) V_26 ) ) ;
if ( V_38 == NULL ) {
V_38 = F_14 ( F_15 () , T_13 ) ;
V_38 -> V_40 = V_36 ;
V_38 -> V_41 = V_37 -> V_42 ;
F_16 ( V_39 , F_13 ( ( T_3 ) V_26 ) , V_38 ) ;
}
else {
T_13 * V_43 ;
if ( V_36 != V_38 -> V_40 + 1 ) {
V_43 = F_14 ( F_15 () , T_13 ) ;
* V_43 = * V_38 ;
F_16 ( V_44 , F_13 ( V_37 -> V_42 ) , V_43 ) ;
}
V_38 -> V_40 = V_36 ;
V_38 -> V_41 = V_37 -> V_42 ;
}
}
static void F_17 ( T_11 V_26 , T_11 V_36 ,
T_14 * V_45 , T_15 * V_46 , T_12 * V_37 )
{
T_13 * V_38 = ( T_13 * ) F_12 ( V_44 ,
F_13 ( V_37 -> V_42 ) ) ;
if ( V_38 != NULL ) {
T_16 * V_47 , * V_48 ;
V_47 = F_18 ( V_46 , V_49 ,
V_45 , 0 , 0 , V_38 -> V_40 + 1 ) ;
if ( V_36 > ( V_38 -> V_40 + 1 ) ) {
F_19 ( V_47 , L_2 ,
V_36 - ( V_38 -> V_40 + 1 ) ) ;
}
F_20 ( V_47 ) ;
V_48 = F_18 ( V_46 , V_50 ,
V_45 , 0 , 0 , V_38 -> V_41 ) ;
F_20 ( V_48 ) ;
if ( V_36 == V_38 -> V_40 ) {
F_21 ( V_37 , V_47 , & V_51 ,
L_3 ,
V_26 , V_36 ) ;
}
else if ( V_36 > V_38 -> V_40 + 1 ) {
F_21 ( V_37 , V_47 , & V_51 ,
L_4 ,
V_26 ,
V_36 - ( V_38 -> V_40 + 1 ) ) ;
}
else {
F_21 ( V_37 , V_47 , & V_51 ,
L_5 ,
V_26 ,
( V_38 -> V_40 + 1 ) - V_36 ) ;
}
}
}
static T_5
F_22 ( T_2 * V_52 , T_2 * V_53 , T_1 V_54 )
{
T_3 V_7 ;
T_3 V_55 = 0 ;
T_3 V_56 = 0 ;
char V_57 [ 3 ] ;
char V_58 [ 3 ] ;
T_3 V_59 ;
T_3 V_60 = ( T_3 ) strlen ( V_53 ) ;
if( ( V_60 == 1 ) && ( V_53 [ 0 ] == V_61 ) )
return TRUE ;
V_59 = ( T_3 ) strlen ( V_52 ) ;
if( V_59 != V_60 )
return FALSE ;
if( ( ( V_54 == V_62 ) && ( V_60 > V_63 ) ) ||
( ( V_54 == V_64 ) && ( V_60 > V_65 ) ) )
{
for( V_7 = 0 ; V_7 < V_59 ; V_7 ++ )
{
if( ( V_53 [ V_7 ] != V_61 ) && ( V_53 [ V_7 ] != V_52 [ V_7 ] ) )
return FALSE ;
}
return TRUE ;
}
else
{
for( V_7 = 0 ; V_7 < ( V_60 / 4 ) ; V_7 ++ )
{
if( ( V_53 [ V_7 ] != V_61 ) && ( V_53 [ V_7 ] != V_52 [ V_7 ] ) )
return FALSE ;
}
if( V_53 [ V_7 ] == V_61 )
return TRUE ;
else if ( V_60 % 4 != 0 )
{
V_57 [ 0 ] = V_53 [ V_7 ] ;
V_57 [ 1 ] = '\0' ;
V_58 [ 0 ] = V_52 [ V_7 ] ;
V_58 [ 1 ] = '\0' ;
if ( sscanf ( V_57 , L_6 , & V_55 ) == V_66 )
return FALSE ;
if ( sscanf ( V_58 , L_6 , & V_56 ) == V_66 )
return FALSE ;
for( V_7 = 0 ; V_7 < ( V_60 % 4 ) ; V_7 ++ )
{
if( ( ( V_55 >> ( 4 - V_7 - 1 ) ) & 1 ) != ( ( V_56 >> ( 4 - V_7 - 1 ) ) & 1 ) )
return FALSE ;
}
}
}
return TRUE ;
}
static T_5
F_23 ( T_3 V_26 , T_2 * V_53 )
{
T_3 V_7 ;
T_3 V_60 = ( T_3 ) strlen ( V_53 ) ;
if( ( V_60 == 1 ) && ( V_53 [ 0 ] == V_61 ) )
return TRUE ;
if ( strchr ( V_53 , V_61 ) != NULL ) {
T_2 V_67 [ V_68 ] ;
F_24 ( V_67 , V_68 , L_7 , V_26 ) ;
if( strlen ( V_67 ) != V_60 )
return FALSE ;
for( V_7 = 2 ; V_53 [ V_7 ] ; V_7 ++ )
if( ( V_53 [ V_7 ] != V_61 ) && ( V_53 [ V_7 ] != V_67 [ V_7 ] ) )
return FALSE ;
} else if ( strtoul ( V_53 , NULL , 0 ) != V_26 ) {
return FALSE ;
}
return TRUE ;
}
static T_5
F_25 ( T_1 V_69 , T_2 * V_70 , T_2 * V_71 , T_3 V_26 ,
T_1 * V_27 ,
T_1 * V_28 ,
T_2 * * V_14 ,
T_3 * V_72 ,
T_2 * * V_18 ,
T_3 * V_73 ,
T_17 * * V_29 ,
T_5 * * V_15
)
{
T_5 V_74 = FALSE ;
T_3 V_7 , V_8 ;
* V_29 = NULL ;
* V_15 = NULL ;
for ( V_7 = 0 , V_8 = 0 ; ( V_74 == FALSE ) && ( ( V_7 < V_75 ) || ( V_8 < V_31 . V_32 ) ) ; )
{
T_7 * V_30 ;
if ( V_8 < V_31 . V_32 ) {
V_30 = & V_31 . V_33 [ V_8 ++ ] ;
}
else {
V_30 = & V_76 [ V_7 ++ ] ;
}
if( ( V_69 == V_30 -> V_23 )
&& F_22 ( V_70 , V_30 -> V_24 , V_69 )
&& F_22 ( V_71 , V_30 -> V_25 , V_69 )
&& F_23 ( V_26 , V_30 -> V_26 ) )
{
V_74 = TRUE ;
* V_27 = V_30 -> V_27 ;
* V_28 = V_30 -> V_28 ;
* V_18 = V_30 -> V_18 ;
if ( V_30 -> V_17 == - 1 )
{
* V_73 = 0 ;
V_74 = FALSE ;
}
else {
* V_73 = V_30 -> V_17 ;
}
* V_14 = V_30 -> V_14 ;
if ( V_30 -> V_13 == - 1 )
{
* V_72 = 0 ;
V_74 = FALSE ;
}
else {
* V_72 = V_30 -> V_13 ;
}
* V_29 = & V_30 -> V_29 ;
* V_15 = & V_30 -> V_15 ;
}
}
return V_74 ;
}
static void
F_26 ( T_18 V_77 , T_12 * V_37 , T_14 * V_45 )
{
if ( F_27 ( V_78 ) ) {
T_19 * V_79 = F_28 ( V_37 , F_29 ( V_77 ) , V_80 ) ;
V_79 -> V_81 = V_81 ( V_45 ) ;
V_79 -> V_82 = V_82 ( V_45 ) ;
V_79 -> V_83 = V_45 ;
F_30 ( V_78 , V_37 , V_79 ) ;
}
}
static int
F_31 ( T_14 * V_45 , T_12 * V_37 , T_15 * V_46 , void * T_20 V_10 )
{
T_15 * V_84 ;
T_16 * V_85 , * V_86 ;
T_10 V_87 ;
T_3 V_88 ;
T_3 V_89 ;
T_11 V_90 ;
F_32 ( V_37 -> V_91 , V_92 , L_8 ) ;
F_33 ( V_37 -> V_91 , V_93 ) ;
V_85 = F_34 ( V_46 , V_94 , V_45 , 0 , - 1 , V_95 ) ;
V_84 = F_35 ( V_85 , V_96 ) ;
V_87 = F_36 ( V_45 , 1 ) ;
V_88 = ( V_87 + 2 ) * 4 ;
V_89 = V_87 ? ( V_87 - 1 ) * 4 : 0 ;
F_34 ( V_84 , V_97 , V_45 , 0 , 1 , V_98 ) ;
V_86 = F_34 ( V_84 , V_99 , V_45 , 1 , 1 , V_98 ) ;
F_19 ( V_86 , L_9 , V_88 ) ;
F_34 ( V_84 , V_100 , V_45 , 2 , 2 , V_95 ) ;
F_37 ( V_84 , V_101 , V_45 , 4 , 4 , V_98 , & V_90 ) ;
F_38 ( V_37 -> V_91 , V_93 , L_10 , V_90 ) ;
F_34 ( V_84 , V_102 , V_45 , 8 , 4 , V_98 ) ;
F_34 ( V_84 , V_103 , V_45 , 12 , V_89 , V_95 ) ;
F_39 ( V_85 , V_88 ) ;
return V_88 ;
}
static int
F_40 ( T_14 * V_45 , T_12 * V_37 , T_15 * V_46 , void * T_20 V_10 )
{
T_10 V_104 ;
T_14 * V_105 ;
int V_106 ;
T_18 V_77 ;
T_11 V_107 ;
V_106 = F_31 ( V_45 , V_37 , V_46 , NULL ) ;
V_104 = F_36 ( V_45 , 0 ) ;
V_105 = F_41 ( V_45 , V_106 ) ;
V_107 = V_37 -> V_108 ;
V_77 = F_42 ( V_109 , V_104 ) ;
if ( V_77 ) {
V_37 -> V_108 = V_104 ;
} else {
V_77 = V_110 ;
}
F_26 ( V_77 , V_37 , V_105 ) ;
F_43 ( V_77 , V_105 , V_37 , V_46 ) ;
V_37 -> V_108 = V_107 ;
return V_81 ( V_45 ) ;
}
static void
F_44 ( T_15 * V_46 , T_14 * V_45 , T_1 V_111 , T_1 V_112 , T_10 * V_113 ,
T_5 V_114 , T_5 V_115 )
{
T_16 * V_116 ;
T_15 * V_117 ;
T_5 V_118 = FALSE , V_119 = FALSE ;
if( V_112 == 0 )
{
V_117 = F_45 ( V_46 , V_45 , V_111 , 0 ,
V_120 , NULL , L_11 ) ;
V_118 = TRUE ;
}
else if( F_46 ( V_45 , V_111 - V_112 , V_112 ) )
{
if( ( V_114 ) && ( V_115 ) )
{
V_117 = F_45 ( V_46 , V_45 , V_111 - V_112 , V_112 ,
V_120 , NULL , L_12 ) ;
V_118 = TRUE ;
}
else if( ( V_114 ) && ( ! V_115 ) )
{
V_117 = F_47 ( V_46 , V_45 , V_111 - V_112 , V_112 ,
V_120 , NULL , L_13 , V_113 ) ;
V_119 = TRUE ;
}
else
V_117 = F_45 ( V_46 , V_45 , V_111 - V_112 , V_112 ,
V_120 , NULL , L_14 ) ;
}
else
{
V_117 = F_45 ( V_46 , V_45 , V_111 - V_112 , V_112 - ( V_111 - V_81 ( V_45 ) ) ,
V_120 , NULL , L_15 ) ;
V_119 = TRUE ;
}
V_116 = F_48 ( V_117 , V_121 ,
V_45 , V_111 - V_112 , V_112 , V_118 ) ;
F_20 ( V_116 ) ;
V_116 = F_48 ( V_117 , V_122 ,
V_45 , V_111 - V_112 , V_112 , V_119 ) ;
F_20 ( V_116 ) ;
}
static int
F_49 ( T_14 * V_45 , T_12 * V_37 , T_15 * V_46 , void * T_20 V_10 )
{
T_15 * V_123 = NULL ;
T_16 * V_86 ;
T_1 V_111 = 0 ;
#ifdef F_50
T_1 V_7 ;
T_2 * V_124 = NULL ;
T_2 * V_125 = NULL ;
#endif
T_11 V_26 = 0 ;
T_3 V_126 = 0 ;
T_5 V_127 = FALSE ;
T_14 * V_105 ;
T_18 V_77 ;
T_11 V_107 ;
#ifdef F_50
T_5 V_128 = FALSE ;
T_10 * V_129 = NULL ;
T_10 * V_130 = NULL ;
T_10 * V_131 = NULL ;
T_14 * V_132 ;
T_1 V_69 = V_133 ;
T_1 V_134 = V_135 ;
T_1 V_136 = V_137 ;
T_2 * V_138 = NULL ;
T_2 * V_139 = NULL ;
T_3 V_140 = 0 ;
T_3 V_141 = 0 ;
T_17 * V_29 ;
T_5 * V_15 ;
T_1 V_142 = 0 ;
T_1 V_112 = 0 ;
T_1 V_143 = 0 ;
T_5 V_144 = FALSE ;
T_5 V_145 = FALSE ;
T_5 V_146 = FALSE ;
T_5 V_114 = FALSE ;
T_5 V_115 = FALSE ;
T_5 V_147 = FALSE ;
#endif
T_1 V_148 = 0 ;
#ifdef F_50
int V_149 = 0 ;
T_21 V_150 ;
int V_151 = 0 ;
T_22 T_6 = 0 ;
int V_152 = 0 ;
int V_153 = 0 ;
int V_154 = 0 ;
unsigned char * V_113 = NULL ;
unsigned char * V_155 ;
unsigned char V_156 [ 16 ] ;
#endif
T_11 V_36 ;
F_32 ( V_37 -> V_91 , V_92 , L_16 ) ;
F_33 ( V_37 -> V_91 , V_93 ) ;
V_111 = 0 , V_126 = 0 ;
V_127 = FALSE ;
V_86 = F_34 ( V_46 , V_157 , V_45 , 0 , - 1 , V_95 ) ;
V_123 = F_35 ( V_86 , V_158 ) ;
F_37 ( V_123 , V_159 , V_45 ,
0 , 4 , V_98 , & V_26 ) ;
F_37 ( V_123 , V_160 , V_45 ,
4 , 4 , V_98 , & V_36 ) ;
F_38 ( V_37 -> V_91 , V_93 , L_17 , V_26 ) ;
if ( V_161 ) {
if ( ! V_37 -> V_162 -> V_163 . V_164 ) {
F_11 ( V_26 , V_36 , V_37 ) ;
}
F_17 ( V_26 , V_36 ,
V_45 , V_123 , V_37 ) ;
}
#ifdef F_50
if( V_165 &&
! V_166 )
V_128 = TRUE ;
if( V_166 || V_167 )
{
if ( V_37 -> V_70 . type == V_168 ) {
V_69 = V_64 ;
} else if ( V_37 -> V_70 . type == V_169 ) {
V_69 = V_62 ;
}
V_124 = F_51 ( F_52 () , & V_37 -> V_70 ) ;
V_125 = F_51 ( F_52 () , & V_37 -> V_71 ) ;
if ( V_81 ( V_45 ) >= 4 )
{
V_26 = F_53 ( V_45 , 0 ) ;
}
if( ( V_147 = F_25 ( V_69 , V_124 , V_125 , V_26 ,
& V_134 , & V_136 ,
& V_138 , & V_140 , & V_139 , & V_141 ,
& V_29 , & V_15 ) ) )
{
V_111 = V_82 ( V_45 ) ;
switch( V_136 )
{
case V_137 :
V_112 = 0 ;
break;
case V_170 :
V_112 = 8 ;
break;
case V_171 :
case V_172 :
V_112 = 16 ;
break;
case V_173 :
case V_174 :
V_112 = 32 ;
break;
case V_175 :
case V_176 :
V_112 = 24 ;
break;
case V_177 :
case V_178 :
case V_179 :
case V_180 :
case V_181 :
default:
V_112 = 12 ;
break;
}
if( V_167 )
{
switch( V_136 )
{
case V_177 :
V_154 = V_182 ;
V_146 = TRUE ;
break;
case V_137 :
V_146 = FALSE ;
V_115 = TRUE ;
V_114 = TRUE ;
break;
case V_178 :
case V_171 :
V_154 = V_183 ;
V_146 = TRUE ;
break;
case V_175 :
V_154 = V_184 ;
V_146 = TRUE ;
break;
case V_173 :
V_154 = V_185 ;
V_146 = TRUE ;
break;
case V_179 :
V_154 = V_186 ;
V_146 = TRUE ;
break;
case V_180 :
V_154 = V_187 ;
V_146 = TRUE ;
break;
case V_170 :
case V_181 :
case V_172 :
case V_176 :
case V_174 :
default:
V_114 = FALSE ;
V_146 = FALSE ;
break;
}
if( ( V_146 ) && ( ! V_114 ) )
{
F_54 ( V_188 , 0 ) ;
F_54 ( V_189 , 0 ) ;
V_130 = ( T_10 * ) F_55 ( F_52 () , V_112 + 1 ) ;
F_56 ( V_45 , V_130 , V_111 - V_112 , V_112 ) ;
V_131 = ( T_10 * ) F_55 ( F_52 () , V_111 - V_112 + 1 ) ;
F_56 ( V_45 , V_131 , 0 , V_111 - V_112 ) ;
T_6 = F_57 ( & V_150 , V_154 , V_190 ) ;
if ( T_6 )
{
fprintf ( V_35 , L_18 ,
F_58 ( V_154 ) , F_59 ( T_6 ) ) ;
V_114 = FALSE ;
}
else
{
V_151 = F_60 ( V_154 ) ;
if ( V_151 < 1 || V_151 < V_112 )
{
fprintf ( V_35 , L_19 ,
F_58 ( V_154 ) , V_151 ) ;
V_114 = FALSE ;
}
else
{
F_61 ( V_150 , V_139 , V_141 ) ;
F_62 ( V_150 , V_131 , V_111 - V_112 ) ;
V_155 = F_63 ( V_150 , V_154 ) ;
if ( V_155 == 0 )
{
fprintf ( V_35 , L_20 ,
F_58 ( V_154 ) ) ;
V_114 = FALSE ;
}
else
{
if( memcmp ( V_155 , V_130 , V_112 ) )
{
unsigned char V_191 [ 3 ] ;
V_113 = ( T_10 * ) F_64 ( F_52 () , V_112 * 2 + 1 ) ;
for ( V_7 = 0 ; V_7 < V_112 ; V_7 ++ )
{
F_24 ( ( char * ) V_191 , 3 ,
L_21 , V_155 [ V_7 ] & 0xFF ) ;
V_113 [ V_7 * 2 ] = V_191 [ 0 ] ;
V_113 [ V_7 * 2 + 1 ] = V_191 [ 1 ] ;
}
V_113 [ V_112 * 2 ] = '\0' ;
V_114 = TRUE ;
V_115 = FALSE ;
}
else
{
V_114 = TRUE ;
V_115 = TRUE ;
}
}
}
F_65 ( V_150 ) ;
}
}
}
if( V_166 )
{
V_128 = FALSE ;
switch( V_134 )
{
case V_192 :
V_142 = 8 ;
V_152 = V_193 ;
V_153 = V_194 ;
V_143 = V_111 - 8 ;
if ( V_143 <= 0 )
V_144 = FALSE ;
else
{
if( V_143 % V_142 == 0 )
V_149 = V_143 ;
else
V_149 = ( V_143 / V_142 ) * V_142 + V_142 ;
if ( V_140 != F_66 ( V_152 ) )
{
fprintf ( V_35 , L_22 ,
V_140 * 8 ,
( unsigned long ) F_66 ( V_152 ) * 8 ) ;
V_144 = FALSE ;
}
else
V_145 = TRUE ;
}
break;
case V_195 :
V_142 = 16 ;
V_153 = V_194 ;
V_143 = V_111 - 8 ;
if ( V_143 <= 0 )
V_144 = FALSE ;
else
{
if( V_143 % V_142 == 0 )
V_149 = V_143 ;
else
V_149 = ( V_143 / V_142 ) * V_142 + V_142 ;
switch( V_140 * 8 )
{
case 128 :
V_152 = V_196 ;
V_145 = TRUE ;
break;
case 192 :
V_152 = V_197 ;
V_145 = TRUE ;
break;
case 256 :
V_152 = V_198 ;
V_145 = TRUE ;
break;
default:
fprintf ( V_35 , L_23 ,
V_140 * 8 ) ;
V_144 = FALSE ;
}
}
break;
case V_199 :
V_142 = 8 ;
V_153 = V_194 ;
V_143 = V_111 - 8 ;
if ( V_143 <= 0 )
V_144 = FALSE ;
else
{
if( V_143 % V_142 == 0 )
V_149 = V_143 ;
else
V_149 = ( V_143 / V_142 ) * V_142 + V_142 ;
switch( V_140 * 8 )
{
case 128 :
V_152 = V_200 ;
V_145 = TRUE ;
break;
default:
fprintf ( V_35 , L_24 ,
V_140 * 8 ) ;
V_144 = FALSE ;
}
}
break;
case V_201 :
V_142 = 8 ;
V_152 = V_202 ;
V_153 = V_194 ;
V_143 = V_111 - 8 ;
if ( V_143 <= 0 )
V_144 = FALSE ;
else
{
if( V_143 % V_142 == 0 )
V_149 = V_143 ;
else
V_149 = ( V_143 / V_142 ) * V_142 + V_142 ;
if ( V_140 != F_66 ( V_152 ) )
{
fprintf ( V_35 , L_25 ,
V_140 * 8 , ( unsigned long ) F_66 ( V_152 ) * 8 ) ;
V_144 = FALSE ;
}
else
V_145 = TRUE ;
}
break;
case V_203 :
case V_204 :
V_142 = 8 ;
V_153 = V_205 ;
V_143 = V_111 - 8 ;
if ( V_143 <= 0 )
V_144 = FALSE ;
else
{
if( V_143 % V_142 == 0 )
V_149 = V_143 ;
else
V_149 = ( V_143 / V_142 ) * V_142 + V_142 ;
switch( V_140 * 8 )
{
case 160 :
V_152 = V_196 ;
V_145 = TRUE ;
break;
case 224 :
V_152 = V_197 ;
V_145 = TRUE ;
break;
case 288 :
V_152 = V_198 ;
V_145 = TRUE ;
break;
default:
fprintf ( V_35 , L_26 ,
V_140 * 8 ) ;
V_144 = FALSE ;
}
}
break;
case V_206 :
V_142 = 16 ;
V_153 = V_194 ;
V_143 = V_111 - 8 ;
if ( V_143 <= 0 )
V_144 = FALSE ;
else
{
if( V_143 % V_142 == 0 )
V_149 = V_143 ;
else
V_149 = ( V_143 / V_142 ) * V_142 + V_142 ;
switch( V_140 * 8 )
{
case 128 :
V_152 = V_207 ;
V_145 = TRUE ;
break;
case 256 :
V_152 = V_208 ;
V_145 = TRUE ;
break;
default:
fprintf ( V_35 , L_27 ,
V_140 * 8 ) ;
V_144 = FALSE ;
}
}
break;
case V_209 :
V_142 = 8 ;
V_152 = V_210 ;
V_153 = V_194 ;
V_143 = V_111 - 8 ;
if ( V_143 <= 0 )
V_144 = FALSE ;
else
{
if( V_143 % V_142 == 0 )
V_149 = V_143 ;
else
V_149 = ( V_143 / V_142 ) * V_142 + V_142 ;
if ( V_140 != F_66 ( V_152 ) )
{
fprintf ( V_35 , L_28 ,
V_140 * 8 , ( unsigned long ) F_66 ( V_152 ) * 8 ) ;
V_144 = FALSE ;
}
else
V_145 = TRUE ;
}
break;
case V_135 :
default :
V_142 = 0 ;
V_143 = V_111 - 8 ;
if ( V_143 <= 0 )
V_144 = FALSE ;
else
{
V_129 = ( T_10 * ) F_64 ( F_52 () , V_143 + 1 ) ;
F_56 ( V_45 , V_129 , V_211 , V_143 ) ;
V_144 = TRUE ;
}
break;
}
if ( V_145 )
{
V_129 = ( T_10 * ) F_64 ( F_52 () , V_149 + V_142 ) ;
F_56 ( V_45 , V_129 , V_211 , V_143 ) ;
if ( ! ( * V_15 ) ) {
T_6 = F_67 ( V_29 , V_152 , V_153 , 0 ) ;
if ( T_6 )
{
fprintf ( V_35 , L_29 ,
F_68 ( V_152 ) , V_153 , F_59 ( T_6 ) ) ;
}
else
{
if ( * V_15 == FALSE )
{
if ( V_153 == V_205 )
{
T_6 = F_69 ( * V_29 , V_138 , V_140 - 4 ) ;
}
else
{
T_6 = F_69 ( * V_29 , V_138 , V_140 ) ;
}
if ( T_6 )
{
fprintf ( V_35 , L_30 ,
F_68 ( V_152 ) , V_153 , V_140 , F_59 ( T_6 ) ) ;
F_9 ( * V_29 ) ;
}
}
* V_15 = TRUE ;
}
}
if ( V_153 == V_205 )
{
memset ( V_156 , 0 , 16 ) ;
memcpy ( V_156 , V_138 + V_140 - 4 , 4 ) ;
memcpy ( V_156 + 4 , V_129 , 8 ) ;
V_156 [ 15 ] = 1 ;
if ( V_134 == V_204 ) {
V_156 [ 15 ] ++ ;
}
T_6 = F_70 ( * V_29 , V_156 , 16 ) ;
if ( ! T_6 )
{
T_6 = F_71 ( * V_29 , V_129 + V_142 , V_149 , NULL , 0 ) ;
}
}
else
{
T_6 = F_71 ( * V_29 , V_129 , V_149 + V_142 , NULL , 0 ) ;
}
if ( T_6 )
{
fprintf ( V_35 , L_31 ,
F_68 ( V_152 ) , V_153 , F_59 ( T_6 ) ) ;
F_9 ( * V_29 ) ;
V_144 = FALSE ;
}
else
{
if( V_143 >= V_112 )
{
F_56 ( V_45 , V_129 + V_143 - V_112 , ( T_1 ) ( V_211 + V_143 - V_112 ) , V_112 ) ;
}
V_144 = TRUE ;
}
}
}
}
else if( V_165 )
{
V_128 = TRUE ;
}
if( V_144 && ( V_143 > V_142 ) )
{
V_132 = F_72 ( V_45 , ( T_10 * ) F_73 ( V_129 + sizeof( T_10 ) * V_142 ,
V_143 - V_142 ) ,
V_143 - V_142 , V_143 - V_142 ) ;
F_74 ( V_37 , V_132 , L_32 ) ;
F_75 ( V_132 , F_4 ) ;
if( F_46 ( V_45 , 8 , V_142 ) )
{
if( V_142 > 0 )
F_34 ( V_123 , V_212 , V_45 , 8 , V_142 , V_95 ) ;
}
else
{
F_76 ( V_123 , V_212 , V_45 , 8 , - 1 , NULL , L_33 ) ;
}
if( F_46 ( V_132 , V_143 - V_142 - V_112 - 2 , 2 ) )
{
V_148 = F_36 ( V_132 , V_143 - V_142 - V_112 - 2 ) ;
if( V_143 - V_142 - V_112 - V_148 - 2 >= 0 )
{
V_126 = F_36 ( V_132 , V_143 - V_142 - V_112 - 1 ) ;
V_77 = F_42 ( V_109 , V_126 ) ;
if ( V_77 ) {
V_107 = V_37 -> V_108 ;
V_37 -> V_108 = V_126 ;
V_105 = F_77 ( V_132 , 0 ,
V_143 - V_112 - V_148 - V_142 - 2 ) ;
F_26 ( V_77 , V_37 , V_105 ) ;
F_43 ( V_77 , V_105 , V_37 , V_46 ) ;
V_37 -> V_108 = V_107 ;
V_127 = TRUE ;
}
}
}
if( V_127 )
{
if( V_123 )
{
if( V_148 != 0 )
F_34 ( V_123 , V_213 ,
V_132 ,
V_143 - V_142 - V_112 - 2 - V_148 ,
V_148 , V_95 ) ;
F_18 ( V_123 , V_214 , V_132 ,
V_143 - V_142 - V_112 - 2 , 1 ,
V_148 ) ;
F_78 ( V_123 , V_215 , V_132 ,
V_143 - V_142 - V_112 - 1 , 1 ,
V_126 ,
L_34 ,
F_79 ( V_126 ) , V_126 ) ;
F_44 ( V_123 ,
V_132 ,
V_143 - V_142 ,
V_112 ,
V_113 ,
V_114 ,
V_115 ) ;
}
}
else
{
V_105 = F_77 ( V_132 , 0 ,
V_143 - V_142 - V_112 ) ;
F_26 ( V_110 , V_37 , V_105 ) ;
F_43 ( V_110 , V_105 , V_37 , V_123 ) ;
F_44 ( V_123 ,
V_132 ,
V_143 - V_142 , V_112 ,
V_113 , V_114 ,
V_115 ) ;
}
}
}
if( ! V_166 && V_167 && V_147 )
{
V_105 = F_80 ( V_45 , 8 , V_111 - 8 - V_112 , - 1 ) ;
F_26 ( V_110 , V_37 , V_105 ) ;
F_43 ( V_110 , V_105 , V_37 , V_123 ) ;
F_44 ( V_123 , V_45 , V_111 ,
V_112 , V_113 ,
V_114 , V_115 ) ;
}
else if( V_128 )
{
#endif
if( V_165 )
{
V_111 = V_82 ( V_45 ) ;
if( F_46 ( V_45 , V_111 - 14 , 2 ) )
{
V_148 = F_36 ( V_45 , V_111 - 14 ) ;
V_126 = F_36 ( V_45 , V_111 - 13 ) ;
V_77 = F_42 ( V_109 , V_126 ) ;
if ( V_77 ) {
V_107 = V_37 -> V_108 ;
V_37 -> V_108 = V_126 ;
V_105 = F_77 ( V_45 , 8 , V_111 - 8 - 14 - V_148 ) ;
F_26 ( V_77 , V_37 , V_105 ) ;
F_43 ( V_77 , V_105 , V_37 , V_46 ) ;
V_37 -> V_108 = V_107 ;
V_127 = TRUE ;
}
}
}
if( V_127 )
{
if( V_123 )
{
F_18 ( V_123 , V_214 , V_45 ,
V_111 - 14 , 1 ,
V_148 ) ;
F_78 ( V_123 , V_215 , V_45 ,
V_111 - 13 , 1 ,
V_126 ,
L_34 ,
F_79 ( V_126 ) , V_126 ) ;
if( F_46 ( V_45 , V_111 - 12 , 12 ) )
{
F_34 ( V_123 , V_216 , V_45 , V_111 - 12 , 12 , V_95 ) ;
}
else
{
F_76 ( V_123 , V_216 , V_45 , V_111 - 12 , 12 - ( V_111 - V_81 ( V_45 ) ) ,
NULL , L_15 ) ;
}
}
}
#ifdef F_50
}
#endif
return V_81 ( V_45 ) ;
}
static int
F_81 ( T_14 * V_45 , T_12 * V_37 , T_15 * V_46 , void * T_23 V_10 )
{
T_15 * V_217 ;
T_16 * V_86 ;
T_10 V_218 ;
T_11 V_219 ;
T_18 V_77 ;
T_11 V_107 ;
T_14 * T_20 , * V_220 ;
F_32 ( V_37 -> V_91 , V_92 , L_35 ) ;
F_33 ( V_37 -> V_91 , V_93 ) ;
V_218 = F_36 ( V_45 , 0 ) ;
V_86 = F_34 ( V_46 , V_221 , V_45 , 0 , - 1 , V_95 ) ;
V_217 = F_35 ( V_86 , V_222 ) ;
F_82 ( V_217 , V_223 , V_45 ,
0 , 1 , V_218 , L_36 , F_79 ( V_218 ) , V_218 ) ;
F_34 ( V_217 , V_224 , V_45 , 1 , 1 , V_95 ) ;
F_37 ( V_217 , V_225 , V_45 , 2 , 2 , V_98 , & V_219 ) ;
F_38 ( V_37 -> V_91 , V_93 , L_37 , F_83 ( V_219 , V_226 , L_38 ) ) ;
T_20 = F_41 ( V_45 , 4 ) ;
F_26 ( V_110 , V_37 , T_20 ) ;
F_43 ( V_110 , T_20 , V_37 , V_217 ) ;
V_220 = F_84 ( T_20 , T_20 , 0 , V_81 ( T_20 ) ) ;
if ( V_220 ) {
F_74 ( V_37 , V_220 , L_39 ) ;
V_107 = V_37 -> V_108 ;
V_77 = F_42 ( V_109 , V_218 ) ;
if ( V_77 ) {
V_37 -> V_108 = V_218 ;
} else {
V_77 = V_110 ;
}
F_26 ( V_77 , V_37 , V_220 ) ;
F_43 ( V_77 , V_220 , V_37 , V_46 ) ;
V_37 -> V_108 = V_107 ;
}
return V_81 ( V_45 ) ;
}
static void F_85 ( void )
{
V_39 = F_86 ( V_227 , V_228 ) ;
V_44 = F_86 ( V_227 , V_228 ) ;
}
static void F_87 ( void )
{
#ifdef F_50
T_3 V_19 ;
for ( V_19 = 0 ; V_19 < V_31 . V_32 ; V_19 ++ ) {
F_8 ( & ( V_31 . V_33 [ V_19 ] ) ) ;
}
F_4 ( V_31 . V_33 ) ;
V_31 . V_33 = NULL ;
V_31 . V_32 = 0 ;
#endif
F_88 ( V_39 ) ;
F_88 ( V_44 ) ;
}
void
F_89 ( void )
{
static T_24 V_229 [] = {
{ & V_97 ,
{ L_40 , L_41 , V_230 , V_231 | V_232 , & V_233 , 0x0 ,
NULL , V_234 } } ,
{ & V_99 ,
{ L_42 , L_43 , V_230 , V_231 , NULL , 0x0 ,
NULL , V_234 } } ,
{ & V_100 ,
{ L_44 , L_45 , V_235 , V_236 , NULL , 0x0 ,
NULL , V_234 } } ,
{ & V_101 ,
{ L_46 , L_47 , V_237 , V_238 , NULL , 0x0 ,
L_48 , V_234 } } ,
{ & V_103 ,
{ L_49 , L_50 , V_235 , V_236 , NULL , 0x0 ,
L_51 , V_234 } } ,
{ & V_102 ,
{ L_52 , L_53 , V_237 , V_231 , NULL , 0x0 ,
L_54 , V_234 } }
} ;
static T_24 V_239 [] = {
{ & V_159 ,
{ L_55 , L_56 , V_237 , V_240 , NULL , 0x0 ,
L_57 , V_234 } } ,
{ & V_160 ,
{ L_58 , L_59 , V_237 , V_231 , NULL , 0x0 ,
L_60 , V_234 } } ,
{ & V_213 ,
{ L_61 , L_62 , V_235 , V_236 , NULL , 0x0 ,
NULL , V_234 } } ,
{ & V_214 ,
{ L_63 , L_64 , V_230 , V_231 , NULL , 0x0 ,
L_65 , V_234 } } ,
{ & V_215 ,
{ L_66 , L_67 , V_230 , V_238 , NULL , 0x0 ,
L_68 , V_234 } } ,
{ & V_216 ,
{ L_14 , L_69 , V_235 , V_236 , NULL , 0x0 ,
NULL , V_234 } } ,
{ & V_212 ,
{ L_70 , L_71 , V_235 , V_236 , NULL , 0x0 ,
L_72 , V_234 } } ,
{ & V_121 ,
{ L_73 , L_74 , V_241 , V_236 , NULL , 0x0 ,
L_75 , V_234 } } ,
{ & V_122 ,
{ L_76 , L_77 , V_241 , V_236 , NULL , 0x0 ,
L_78 , V_234 } } ,
{ & V_49 ,
{ L_79 , L_80 , V_237 , V_231 , NULL , 0x0 ,
NULL , V_234 } } ,
{ & V_50 ,
{ L_81 , L_82 , V_242 , V_236 , NULL , 0x0 ,
NULL , V_234 } } ,
} ;
static T_24 V_243 [] = {
{ & V_223 ,
{ L_83 , L_84 , V_230 , V_238 , NULL , 0x0 ,
NULL , V_234 } } ,
{ & V_224 ,
{ L_85 , L_86 , V_230 , V_238 , NULL , 0x0 ,
L_87 , V_234 } } ,
{ & V_225 ,
{ L_88 , L_89 , V_244 , V_238 , F_90 ( V_226 ) , 0x0 ,
L_90 , V_234 } } ,
} ;
static T_1 * V_245 [] = {
& V_96 ,
& V_158 ,
& V_120 ,
& V_222 ,
} ;
static T_25 V_246 [] = {
{ & V_51 , { L_91 , V_247 , V_248 , L_92 , V_249 } }
} ;
#ifdef F_50
static const T_26 V_250 [] = {
{ V_64 , L_93 } ,
{ V_62 , L_94 } ,
{ 0x00 , NULL }
} ;
static const T_26 V_251 [] = {
{ V_135 , L_95 } ,
{ V_192 , L_96 } ,
{ V_195 , L_97 } ,
{ V_203 , L_98 } ,
{ V_201 , L_99 } ,
{ V_199 , L_100 } ,
{ V_209 , L_101 } ,
{ V_206 , L_102 } ,
{ V_204 , L_103 } ,
{ 0x00 , NULL }
} ;
static const T_26 V_252 [] = {
{ V_137 , L_95 } ,
{ V_177 , L_104 } ,
{ V_178 , L_105 } ,
{ V_171 , L_106 } ,
{ V_175 , L_107 } ,
{ V_173 , L_108 } ,
{ V_179 , L_109 } ,
{ V_180 , L_110 } ,
{ V_170 , L_111 } ,
{ V_181 , L_112 } ,
{ V_172 , L_113 } ,
{ V_176 , L_114 } ,
{ V_174 , L_115 } ,
{ 0x00 , NULL }
} ;
static T_27 V_253 [] = {
F_91 ( V_76 , V_23 , L_116 , V_250 , L_117 ) ,
F_92 ( V_76 , V_24 , L_118 , L_119 ) ,
F_92 ( V_76 , V_25 , L_120 , L_121 ) ,
F_92 ( V_76 , V_26 , L_122 , L_122 ) ,
F_91 ( V_76 , V_27 , L_123 , V_251 , L_124 ) ,
F_92 ( V_76 , V_12 , L_125 , L_125 ) ,
F_91 ( V_76 , V_28 , L_126 , V_252 , L_127 ) ,
F_92 ( V_76 , V_16 , L_128 , L_128 ) ,
V_254
} ;
#endif
T_28 * V_255 ;
T_28 * V_256 ;
T_29 * V_257 ;
V_94 = F_93 ( L_129 , L_8 , L_130 ) ;
F_94 ( V_94 , V_229 , F_95 ( V_229 ) ) ;
V_157 = F_93 ( L_131 ,
L_16 , L_132 ) ;
F_94 ( V_157 , V_239 , F_95 ( V_239 ) ) ;
V_221 = F_93 ( L_133 ,
L_35 , L_134 ) ;
F_94 ( V_221 , V_243 , F_95 ( V_243 ) ) ;
F_96 ( V_245 , F_95 ( V_245 ) ) ;
V_257 = F_97 ( V_157 ) ;
F_98 ( V_257 , V_246 , F_95 ( V_246 ) ) ;
V_255 = F_99 ( V_94 , NULL ) ;
F_100 ( V_255 , L_135 ) ;
V_256 = F_99 ( V_157 , NULL ) ;
F_101 ( V_256 , L_136 ,
L_137 ,
L_138
L_139
L_140 ,
& V_165 ) ;
F_101 ( V_256 , L_141 ,
L_142 ,
L_143 ,
& V_161 ) ;
#ifdef F_50
F_101 ( V_256 , L_144 ,
L_145 ,
L_146 ,
& V_166 ) ;
F_101 ( V_256 , L_147 ,
L_148 ,
L_149 ,
& V_167 ) ;
V_258 = F_102 ( L_150 ,
sizeof( T_7 ) ,
L_151 ,
TRUE ,
& V_76 ,
& V_75 ,
V_259 ,
NULL ,
F_7 ,
F_6 ,
F_8 ,
NULL ,
V_253 ) ;
F_103 ( V_256 ,
L_152 ,
L_150 ,
L_153 ,
V_258 ) ;
#endif
F_104 ( & F_85 ) ;
F_105 ( & F_87 ) ;
F_106 ( L_132 , F_49 , V_157 ) ;
F_106 ( L_130 , F_40 , V_94 ) ;
}
void
F_107 ( void )
{
T_18 V_260 , V_261 , V_262 , V_263 ;
V_110 = F_108 ( L_154 ) ;
V_261 = F_108 ( L_130 ) ;
F_109 ( L_155 , V_264 , V_261 ) ;
V_260 = F_108 ( L_132 ) ;
F_109 ( L_155 , V_265 , V_260 ) ;
V_263 = F_110 ( F_81 , V_221 ) ;
F_109 ( L_155 , V_266 , V_263 ) ;
V_262 = F_110 ( F_31 , V_94 ) ;
F_109 ( L_156 , V_264 , V_262 ) ;
V_109 = F_111 ( L_155 ) ;
V_78 = F_112 ( V_267 ) ;
}
