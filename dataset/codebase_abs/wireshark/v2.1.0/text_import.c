static T_1
F_1 ( const char * V_1 , int V_2 )
{
unsigned long V_3 ;
char * V_4 ;
if ( V_1 == NULL ) {
fprintf ( V_5 , L_1 ) ;
exit ( 1 ) ;
}
V_3 = strtoul ( V_1 , & V_4 , V_2 ? V_6 : 16 ) ;
if ( V_4 == V_1 ) {
fprintf ( V_5 , L_2 , V_1 ) ;
}
return ( T_1 ) V_3 ;
}
static void
F_2 ( const char * V_1 )
{
T_1 V_3 ;
V_3 = F_1 ( V_1 , FALSE ) ;
V_7 [ V_8 ] = ( V_9 ) V_3 ;
V_8 ++ ;
if ( V_8 >= V_10 )
F_3 () ;
}
static void
F_4 ( T_1 V_11 )
{
V_8 -= V_11 ;
}
static T_1
F_5 ( T_1 V_12 )
{
T_1 V_13 ;
V_13 = V_12 % 4 ;
if ( V_13 == 0 )
return 0 ;
else
return 4 - V_13 ;
}
void
F_6 ( void )
{
int V_14 = 0 ;
int V_15 = 0 ;
int V_16 = 0 ;
int V_17 = 0 ;
int V_18 = 0 ;
int V_19 , V_20 ;
if ( V_8 > 0 ) {
V_14 = 0 ;
if ( V_21 ) { V_14 += ( int ) sizeof( V_22 ) ; }
if ( V_23 ) { V_14 += ( int ) sizeof( V_24 ) ; }
if ( V_25 ) { V_14 += ( int ) sizeof( V_26 ) ; V_15 = V_14 + V_8 ; }
if ( V_27 ) { V_14 += ( int ) sizeof( V_28 ) ; V_15 = V_14 + V_8 ; }
if ( V_29 ) {
V_14 += ( int ) sizeof( V_30 ) ;
V_16 = V_14 + V_8 + ( ( V_21 ) ? F_5 ( V_8 ) : 0 ) ;
}
if ( V_31 ) { V_14 += ( int ) sizeof( V_32 ) ; }
memmove ( & V_7 [ V_14 ] , V_7 , V_8 ) ;
if ( V_31 ) {
if ( V_14 + V_8 < 60 ) {
V_17 = 60 - ( V_14 + V_8 ) ;
}
}
if ( V_31 ) {
V_32 . V_33 = F_7 ( V_34 ) ;
memcpy ( & V_7 [ V_18 ] , & V_32 , sizeof( V_32 ) ) ;
V_18 += ( int ) sizeof( V_32 ) ;
}
if ( V_29 ) {
T_2 V_35 [ 1 ] ;
V_30 . V_36 = F_7 ( V_16 ) ;
V_30 . V_37 = ( V_9 ) V_38 ;
V_30 . V_39 = 0 ;
V_35 [ 0 ] . V_40 = ( V_9 * ) & V_30 ; V_35 [ 0 ] . V_41 = sizeof( V_30 ) ;
V_30 . V_39 = F_8 ( V_35 , 1 ) ;
memcpy ( & V_7 [ V_18 ] , & V_30 , sizeof( V_30 ) ) ;
V_18 += ( int ) sizeof( V_30 ) ;
}
V_42 . V_43 = V_30 . V_43 ;
V_42 . V_44 = V_30 . V_44 ;
V_42 . V_45 = 0 ;
V_42 . V_37 = ( V_9 ) V_38 ;
V_42 . V_12 = F_7 ( V_15 ) ;
if ( V_25 ) {
T_2 V_35 [ 3 ] ;
V_26 . V_46 = F_7 ( V_47 ) ;
V_26 . V_48 = F_7 ( V_49 ) ;
V_26 . V_12 = F_7 ( V_15 ) ;
V_26 . V_50 = 0 ;
V_35 [ 0 ] . V_40 = ( V_9 * ) & V_42 ; V_35 [ 0 ] . V_41 = sizeof( V_42 ) ;
V_35 [ 1 ] . V_40 = ( V_9 * ) & V_26 ; V_35 [ 1 ] . V_41 = sizeof( V_26 ) ;
V_35 [ 2 ] . V_40 = & V_7 [ V_14 ] ; V_35 [ 2 ] . V_41 = V_8 ;
V_26 . V_50 = F_8 ( V_35 , 3 ) ;
memcpy ( & V_7 [ V_18 ] , & V_26 , sizeof( V_26 ) ) ;
V_18 += ( int ) sizeof( V_26 ) ;
}
if ( V_27 ) {
T_2 V_35 [ 3 ] ;
V_28 . V_46 = F_7 ( V_47 ) ;
V_28 . V_48 = F_7 ( V_49 ) ;
V_28 . V_51 = F_7 ( 0x2000 ) ;
V_28 . V_50 = 0 ;
V_35 [ 0 ] . V_40 = ( V_9 * ) & V_42 ; V_35 [ 0 ] . V_41 = sizeof( V_42 ) ;
V_35 [ 1 ] . V_40 = ( V_9 * ) & V_28 ; V_35 [ 1 ] . V_41 = sizeof( V_28 ) ;
V_35 [ 2 ] . V_40 = & V_7 [ V_14 ] ; V_35 [ 2 ] . V_41 = V_8 ;
V_28 . V_50 = F_8 ( V_35 , 3 ) ;
memcpy ( & V_7 [ V_18 ] , & V_28 , sizeof( V_28 ) ) ;
V_18 += ( int ) sizeof( V_28 ) ;
}
if ( V_21 ) {
V_22 . type = V_52 ;
V_22 . V_53 = V_54 ;
V_22 . V_12 = F_7 ( V_8 + sizeof( V_22 ) ) ;
V_22 . V_55 = F_9 ( V_56 ) ;
V_22 . V_57 = F_7 ( V_58 ) ;
V_22 . V_59 = F_7 ( V_60 ) ;
V_22 . V_61 = F_9 ( V_62 ) ;
V_20 = F_5 ( V_8 ) ;
for ( V_19 = 0 ; V_19 < V_20 ; V_19 ++ )
V_7 [ V_14 + V_8 + V_19 ] = 0 ;
V_8 += V_20 ;
}
if ( V_23 ) {
V_24 . V_63 = F_7 ( V_64 ) ;
V_24 . V_48 = F_7 ( V_65 ) ;
V_24 . V_66 = F_9 ( V_67 ) ;
V_24 . V_50 = F_9 ( 0 ) ;
V_24 . V_50 = F_10 ( & V_24 , sizeof( V_24 ) , V_68 ) ;
if ( V_21 )
V_24 . V_50 = F_10 ( & V_22 , sizeof( V_22 ) , V_24 . V_50 ) ;
V_24 . V_50 = F_9 ( ~ F_10 ( & V_7 [ V_14 ] , V_8 , V_24 . V_50 ) ) ;
memcpy ( & V_7 [ V_18 ] , & V_24 , sizeof( V_24 ) ) ;
V_18 += ( int ) sizeof( V_24 ) ;
}
if ( V_21 ) {
memcpy ( & V_7 [ V_18 ] , & V_22 , sizeof( V_22 ) ) ;
}
if ( V_31 && V_17 > 0 ) {
memset ( & V_7 [ V_14 + V_8 ] , 0 , V_17 ) ;
}
V_28 . V_69 = F_11 ( V_28 . V_69 ) + V_8 ;
V_28 . V_69 = F_9 ( V_28 . V_69 ) ;
{
struct V_70 V_71 ;
int V_72 ;
T_3 * V_73 ;
memset ( & V_71 , 0 , sizeof( struct V_70 ) ) ;
V_71 . V_74 = V_75 ;
V_71 . V_76 . V_77 = ( T_1 ) V_78 ;
V_71 . V_76 . V_79 = V_80 * 1000 ;
if ( V_81 == NULL ) { V_80 ++ ; }
V_71 . V_82 = V_71 . V_41 = V_14 + V_8 + V_17 ;
V_71 . V_83 = V_84 ;
V_71 . V_85 |= V_86 ;
V_71 . V_87 = V_88 | V_89 | V_90 | V_91 ;
if ( ! F_12 ( V_92 , & V_71 , V_7 , & V_72 , & V_73 ) ) {
switch ( V_72 ) {
case V_93 :
F_13 ( V_73 ) ;
break;
default:
break;
}
}
}
}
V_94 += V_8 ;
V_8 = 0 ;
}
static void
F_14 ( char * V_1 )
{
T_4 V_95 ;
if ( V_96 != 0 ) {
if ( V_96 == V_97 )
return;
V_98 [ V_96 ++ ] = ' ' ;
}
if( V_1 == NULL ) {
fprintf ( V_5 , L_1 ) ;
exit ( 1 ) ;
}
V_95 = strlen ( V_1 ) ;
if ( V_95 != 0 ) {
if ( V_96 + V_95 > V_97 )
return;
F_15 ( & V_98 [ V_96 ] , V_1 , V_97 ) ;
V_96 += ( int ) V_95 ;
if ( V_99 >= 2 ) {
char * V_4 ;
char V_100 [ V_97 ] ;
F_15 ( V_100 , V_98 , V_97 ) ;
while ( ( V_4 = strchr ( V_100 , '\r' ) ) != NULL ) * V_4 = ' ' ;
fprintf ( V_5 , L_3 , V_100 ) ;
}
}
}
static void
F_16 ( void )
{
struct V_101 V_102 ;
char * V_103 ;
char * V_104 ;
int V_105 ;
int V_19 ;
V_98 [ V_96 ] = '\0' ;
if ( V_106 ) {
switch ( V_98 [ 0 ] ) {
case 'i' :
case 'I' :
V_86 = 0x00000001 ;
V_98 [ 0 ] = ' ' ;
break;
case 'o' :
case 'O' :
V_86 = 0x00000002 ;
V_98 [ 0 ] = ' ' ;
break;
default:
V_86 = 0x00000000 ;
break;
}
V_19 = 0 ;
while ( V_98 [ V_19 ] == ' ' ||
V_98 [ V_19 ] == '\r' ||
V_98 [ V_19 ] == '\t' ) {
V_19 ++ ;
}
V_96 -= V_19 ;
memmove ( V_98 , V_98 + V_19 , V_96 + 1 ) ;
}
if ( V_81 == NULL )
return;
V_102 = V_107 ;
V_80 = 0 ;
if ( strlen ( V_98 ) > 2 ) {
V_103 = strptime ( V_98 , V_81 , & V_102 ) ;
if ( V_103 != NULL ) {
V_78 = mktime ( & V_102 ) ;
} else
V_78 = - 1 ;
if ( - 1 == V_78 )
{
char * V_4 ;
while ( ( V_4 = strchr ( V_98 , '\r' ) ) != NULL ) * V_4 = ' ' ;
fprintf ( V_5 , L_4 ,
V_98 , V_81 ) ;
if ( V_99 >= 2 ) {
fprintf ( V_5 , L_5 ,
V_102 . V_108 , V_102 . V_109 , V_102 . V_110 ,
V_102 . V_111 , V_102 . V_112 , V_102 . V_113 , V_102 . V_114 ) ;
}
V_78 = 0 ;
V_80 = 0 ;
}
else
{
V_80 = ( T_1 ) strtol ( V_103 , & V_104 , 10 ) ;
if ( V_103 == V_104 ) {
V_80 = 0 ;
} else {
V_105 = ( int ) ( V_104 - V_103 ) ;
if ( V_105 > 6 ) {
for ( V_19 = V_105 - 6 ; V_19 != 0 ; V_19 -- )
V_80 /= 10 ;
} else if ( V_105 < 6 ) {
for ( V_19 = 6 - V_105 ; V_19 != 0 ; V_19 -- )
V_80 *= 10 ;
}
}
}
}
if ( V_99 >= 2 ) {
char * V_4 ;
while ( ( V_4 = strchr ( V_98 , '\r' ) ) != NULL ) * V_4 = ' ' ;
fprintf ( V_5 , L_6 , V_98 ) ;
fprintf ( V_5 , L_7 , V_81 , ( T_1 ) V_78 , V_80 ) ;
}
V_96 = 0 ;
}
static void
F_3 ( void )
{
if ( V_99 >= 1 )
fprintf ( V_5 , L_8 ) ;
F_6 () ;
F_16 () ;
}
static void
F_17 ( char * V_1 )
{
fprintf ( V_5 , L_9 , V_1 + 10 ) ;
}
void
F_18 ( T_5 V_115 , char * V_1 )
{
T_1 V_3 ;
if ( V_99 >= 2 ) {
char * V_4 ;
if ( V_1 != NULL ) { while ( ( V_4 = strchr ( V_1 , '\r' ) ) != NULL ) * V_4 = ' ' ; }
fprintf ( V_5 , L_10 ,
V_116 [ V_117 ] , V_118 [ V_115 ] , V_1 ? V_1 : L_11 ) ;
}
switch( V_117 ) {
case V_119 :
switch( V_115 ) {
case V_120 :
F_14 ( V_1 ) ;
break;
case V_121 :
F_17 ( V_1 ) ;
break;
case V_122 :
V_3 = F_1 ( V_1 , TRUE ) ;
if ( V_3 == 0 ) {
F_3 () ;
V_117 = V_123 ;
}
break;
default:
break;
}
break;
case V_124 :
switch( V_115 ) {
case V_120 :
F_14 ( V_1 ) ;
break;
case V_121 :
F_17 ( V_1 ) ;
break;
case V_122 :
V_3 = F_1 ( V_1 , TRUE ) ;
if ( V_3 == 0 ) {
F_3 () ;
V_94 = 0 ;
V_117 = V_123 ;
} else if ( ( V_3 - V_94 ) != V_8 ) {
if ( V_3 < V_8 ) {
F_4 ( V_8 - V_3 ) ;
V_117 = V_123 ;
} else {
if ( V_99 >= 1 )
fprintf ( V_5 , L_12 ,
V_8 , V_3 ) ;
F_6 () ;
V_117 = V_119 ;
}
} else
V_117 = V_123 ;
break;
default:
break;
}
break;
case V_123 :
switch( V_115 ) {
case V_125 :
V_117 = V_126 ;
F_2 ( V_1 ) ;
break;
case V_120 :
case V_121 :
case V_122 :
V_117 = V_127 ;
break;
case V_128 :
V_117 = V_124 ;
break;
default:
break;
}
break;
case V_126 :
switch( V_115 ) {
case V_125 :
F_2 ( V_1 ) ;
break;
case V_120 :
case V_121 :
case V_122 :
V_117 = V_127 ;
break;
case V_128 :
V_117 = V_124 ;
break;
default:
break;
}
break;
case V_127 :
switch( V_115 ) {
case V_128 :
V_117 = V_124 ;
break;
default:
break;
}
break;
default:
fprintf ( V_5 , L_13 , V_117 ) ;
exit ( - 1 ) ;
}
if ( V_99 >= 2 )
fprintf ( V_5 , L_14 , V_116 [ V_117 ] ) ;
}
int
F_19 ( T_6 * V_129 )
{
T_7 V_130 ;
int V_131 ;
V_7 = ( V_9 * ) F_20 ( sizeof( V_32 ) + sizeof( V_30 ) +
sizeof( V_24 ) + sizeof( V_22 ) +
V_132 ) ;
if ( ! V_7 )
{
fprintf ( V_5 , L_15 ) ;
exit ( - 1 ) ;
}
V_117 = V_119 ;
V_8 = 0 ;
V_94 = 0 ;
V_96 = 0 ;
V_78 = time ( 0 ) ;
V_107 = * localtime ( & V_78 ) ;
V_107 . V_114 = - 1 ;
V_80 = 0 ;
V_31 = FALSE ;
V_29 = FALSE ;
V_25 = FALSE ;
V_27 = FALSE ;
V_23 = FALSE ;
V_21 = FALSE ;
V_6 = ( V_129 -> V_133 == V_134 ) ? 16 :
( V_129 -> V_133 == V_135 ) ? 8 :
( V_129 -> V_133 == V_136 ) ? 10 :
16 ;
V_106 = V_129 -> V_106 ;
if ( V_129 -> V_137 )
{
V_81 = V_129 -> V_138 ;
}
V_84 = V_129 -> V_139 ;
V_92 = V_129 -> V_92 ;
switch ( V_129 -> V_140 )
{
case V_141 :
V_31 = TRUE ;
V_34 = V_129 -> V_142 ;
break;
case V_143 :
V_29 = TRUE ;
V_38 = V_129 -> V_37 ;
V_31 = TRUE ;
V_34 = 0x800 ;
break;
case V_144 :
V_25 = TRUE ;
V_27 = FALSE ;
V_47 = V_129 -> V_63 ;
V_49 = V_129 -> V_145 ;
V_29 = TRUE ;
V_38 = 17 ;
V_31 = TRUE ;
V_34 = 0x800 ;
break;
case V_146 :
V_27 = TRUE ;
V_25 = FALSE ;
V_47 = V_129 -> V_63 ;
V_49 = V_129 -> V_145 ;
V_29 = TRUE ;
V_38 = 6 ;
V_31 = TRUE ;
V_34 = 0x800 ;
break;
case V_147 :
V_23 = TRUE ;
V_64 = V_129 -> V_63 ;
V_65 = V_129 -> V_145 ;
V_67 = V_129 -> V_66 ;
V_29 = TRUE ;
V_38 = 132 ;
V_31 = TRUE ;
V_34 = 0x800 ;
break;
case V_148 :
V_23 = TRUE ;
V_21 = TRUE ;
V_64 = V_129 -> V_63 ;
V_65 = V_129 -> V_145 ;
V_62 = V_129 -> V_149 ;
V_29 = TRUE ;
V_38 = 132 ;
V_31 = TRUE ;
V_34 = 0x800 ;
break;
default:
break;
}
V_10 = V_129 -> V_150 ;
if ( F_21 ( & V_130 ) != 0 ) {
V_131 = V_151 ;
F_13 ( V_7 ) ;
return V_131 ;
}
F_22 ( V_129 -> V_152 , V_130 ) ;
F_23 ( V_130 ) ;
F_24 ( V_130 ) ;
F_13 ( V_7 ) ;
return 0 ;
}
