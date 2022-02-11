static T_1
F_1 ( const char * V_1 , int V_2 )
{
unsigned long V_3 ;
char * V_4 ;
V_3 = strtoul ( V_1 , & V_4 , V_2 ? V_5 : 16 ) ;
if ( V_4 == V_1 ) {
fprintf ( V_6 , L_1 , V_1 ) ;
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
memset ( & V_71 , 0 , sizeof( struct V_70 ) ) ;
V_71 . V_73 = V_74 ;
V_71 . V_75 . V_76 = ( T_1 ) V_77 ;
V_71 . V_75 . V_78 = V_79 * 1000 ;
if ( V_80 == NULL ) { V_79 ++ ; }
V_71 . V_81 = V_71 . V_41 = V_14 + V_8 + V_17 ;
V_71 . V_82 = V_83 ;
V_71 . V_84 |= V_85 ;
V_71 . V_86 = V_87 | V_88 | V_89 | V_90 ;
F_12 ( V_91 , & V_71 , V_7 , & V_72 ) ;
}
}
V_92 += V_8 ;
V_8 = 0 ;
}
static void
F_13 ( char * V_1 )
{
T_3 V_93 ;
if ( V_94 != 0 ) {
if ( V_94 == V_95 )
return;
V_96 [ V_94 ++ ] = ' ' ;
}
V_93 = strlen ( V_1 ) ;
if ( V_93 != 0 ) {
if ( V_94 + V_93 > V_95 )
return;
F_14 ( & V_96 [ V_94 ] , V_1 , V_95 ) ;
V_94 += ( int ) V_93 ;
if ( V_97 >= 2 ) {
char * V_4 ;
char V_98 [ V_95 ] ;
F_14 ( V_98 , V_96 , V_95 ) ;
while ( ( V_4 = strchr ( V_98 , '\r' ) ) != NULL ) * V_4 = ' ' ;
fprintf ( V_6 , L_2 , V_98 ) ;
}
}
}
static void
F_15 ( void )
{
struct V_99 V_100 ;
char * V_101 ;
char * V_102 ;
int V_103 ;
int V_19 ;
V_96 [ V_94 ] = '\0' ;
if ( V_104 ) {
switch ( V_96 [ 0 ] ) {
case 'i' :
case 'I' :
V_85 = 0x00000001 ;
V_96 [ 0 ] = ' ' ;
break;
case 'o' :
case 'O' :
V_85 = 0x00000002 ;
V_96 [ 0 ] = ' ' ;
break;
default:
V_85 = 0x00000000 ;
break;
}
V_19 = 0 ;
while ( V_96 [ V_19 ] == ' ' ||
V_96 [ V_19 ] == '\r' ||
V_96 [ V_19 ] == '\t' ) {
V_19 ++ ;
}
V_94 -= V_19 ;
memmove ( V_96 , V_96 + V_19 , V_94 + 1 ) ;
}
if ( V_80 == NULL )
return;
V_100 = V_105 ;
V_79 = 0 ;
if ( strlen ( V_96 ) > 2 ) {
V_101 = strptime ( V_96 , V_80 , & V_100 ) ;
if ( V_101 != NULL ) {
V_77 = mktime ( & V_100 ) ;
} else
V_77 = - 1 ;
if ( - 1 == V_77 )
{
char * V_4 ;
while ( ( V_4 = strchr ( V_96 , '\r' ) ) != NULL ) * V_4 = ' ' ;
fprintf ( V_6 , L_3 ,
V_96 , V_80 ) ;
if ( V_97 >= 2 ) {
fprintf ( V_6 , L_4 ,
V_100 . V_106 , V_100 . V_107 , V_100 . V_108 ,
V_100 . V_109 , V_100 . V_110 , V_100 . V_111 , V_100 . V_112 ) ;
}
V_77 = 0 ;
V_79 = 0 ;
}
else
{
V_79 = ( T_1 ) strtol ( V_101 , & V_102 , 10 ) ;
if ( V_101 == V_102 ) {
V_79 = 0 ;
} else {
V_103 = ( int ) ( V_102 - V_101 ) ;
if ( V_103 > 6 ) {
for ( V_19 = V_103 - 6 ; V_19 != 0 ; V_19 -- )
V_79 /= 10 ;
} else if ( V_103 < 6 ) {
for ( V_19 = 6 - V_103 ; V_19 != 0 ; V_19 -- )
V_79 *= 10 ;
}
}
}
}
if ( V_97 >= 2 ) {
char * V_4 ;
while ( ( V_4 = strchr ( V_96 , '\r' ) ) != NULL ) * V_4 = ' ' ;
fprintf ( V_6 , L_5 , V_96 ) ;
fprintf ( V_6 , L_6 , V_80 , ( T_1 ) V_77 , V_79 ) ;
}
V_94 = 0 ;
}
static void
F_3 ( void )
{
if ( V_97 >= 1 )
fprintf ( V_6 , L_7 ) ;
F_6 () ;
F_15 () ;
}
static void
F_16 ( char * V_1 )
{
fprintf ( V_6 , L_8 , V_1 + 10 ) ;
}
void
F_17 ( T_4 V_113 , char * V_1 )
{
T_1 V_3 ;
if ( V_97 >= 2 ) {
char * V_4 ;
if ( V_1 != NULL ) { while ( ( V_4 = strchr ( V_1 , '\r' ) ) != NULL ) * V_4 = ' ' ; }
fprintf ( V_6 , L_9 ,
V_114 [ V_115 ] , V_116 [ V_113 ] , V_1 ? V_1 : L_10 ) ;
}
switch( V_115 ) {
case V_117 :
switch( V_113 ) {
case V_118 :
F_13 ( V_1 ) ;
break;
case V_119 :
F_16 ( V_1 ) ;
break;
case V_120 :
V_3 = F_1 ( V_1 , TRUE ) ;
if ( V_3 == 0 ) {
F_3 () ;
V_115 = V_121 ;
}
break;
default:
break;
}
break;
case V_122 :
switch( V_113 ) {
case V_118 :
F_13 ( V_1 ) ;
break;
case V_119 :
F_16 ( V_1 ) ;
break;
case V_120 :
V_3 = F_1 ( V_1 , TRUE ) ;
if ( V_3 == 0 ) {
F_3 () ;
V_92 = 0 ;
V_115 = V_121 ;
} else if ( ( V_3 - V_92 ) != V_8 ) {
if ( V_3 < V_8 ) {
F_4 ( V_8 - V_3 ) ;
V_115 = V_121 ;
} else {
if ( V_97 >= 1 )
fprintf ( V_6 , L_11 ,
V_8 , V_3 ) ;
F_6 () ;
V_115 = V_117 ;
}
} else
V_115 = V_121 ;
break;
default:
break;
}
break;
case V_121 :
switch( V_113 ) {
case V_123 :
V_115 = V_124 ;
F_2 ( V_1 ) ;
break;
case V_118 :
case V_119 :
case V_120 :
V_115 = V_125 ;
break;
case V_126 :
V_115 = V_122 ;
break;
default:
break;
}
break;
case V_124 :
switch( V_113 ) {
case V_123 :
F_2 ( V_1 ) ;
break;
case V_118 :
case V_119 :
case V_120 :
V_115 = V_125 ;
break;
case V_126 :
V_115 = V_122 ;
break;
default:
break;
}
break;
case V_125 :
switch( V_113 ) {
case V_126 :
V_115 = V_122 ;
break;
default:
break;
}
break;
default:
fprintf ( V_6 , L_12 , V_115 ) ;
exit ( - 1 ) ;
}
if ( V_97 >= 2 )
fprintf ( V_6 , L_13 , V_114 [ V_115 ] ) ;
}
void
F_18 ( T_5 * V_127 )
{
V_7 = ( V_9 * ) F_19 ( sizeof( V_32 ) + sizeof( V_30 ) +
sizeof( V_24 ) + sizeof( V_22 ) +
V_128 ) ;
if ( ! V_7 )
{
fprintf ( V_6 , L_14 ) ;
exit ( - 1 ) ;
}
V_115 = V_117 ;
V_8 = 0 ;
V_92 = 0 ;
V_94 = 0 ;
V_77 = time ( 0 ) ;
V_105 = * localtime ( & V_77 ) ;
V_105 . V_112 = - 1 ;
V_79 = 0 ;
V_31 = FALSE ;
V_29 = FALSE ;
V_25 = FALSE ;
V_27 = FALSE ;
V_23 = FALSE ;
V_21 = FALSE ;
V_5 = ( V_127 -> V_129 == V_130 ) ? 16 :
( V_127 -> V_129 == V_131 ) ? 8 :
( V_127 -> V_129 == V_132 ) ? 10 :
16 ;
V_104 = V_127 -> V_104 ;
if ( V_127 -> V_133 )
{
V_80 = V_127 -> V_134 ;
}
V_83 = V_127 -> V_135 ;
V_91 = V_127 -> V_91 ;
switch ( V_127 -> V_136 )
{
case V_137 :
V_31 = TRUE ;
V_34 = V_127 -> V_138 ;
break;
case V_139 :
V_29 = TRUE ;
V_38 = V_127 -> V_37 ;
V_31 = TRUE ;
V_34 = 0x800 ;
break;
case V_140 :
V_25 = TRUE ;
V_27 = FALSE ;
V_47 = V_127 -> V_63 ;
V_49 = V_127 -> V_141 ;
V_29 = TRUE ;
V_38 = 17 ;
V_31 = TRUE ;
V_34 = 0x800 ;
break;
case V_142 :
V_27 = TRUE ;
V_25 = FALSE ;
V_47 = V_127 -> V_63 ;
V_49 = V_127 -> V_141 ;
V_29 = TRUE ;
V_38 = 6 ;
V_31 = TRUE ;
V_34 = 0x800 ;
break;
case V_143 :
V_23 = TRUE ;
V_64 = V_127 -> V_63 ;
V_65 = V_127 -> V_141 ;
V_67 = V_127 -> V_66 ;
V_29 = TRUE ;
V_38 = 132 ;
V_31 = TRUE ;
V_34 = 0x800 ;
break;
case V_144 :
V_23 = TRUE ;
V_21 = TRUE ;
V_64 = V_127 -> V_63 ;
V_65 = V_127 -> V_141 ;
V_62 = V_127 -> V_145 ;
V_29 = TRUE ;
V_38 = 132 ;
V_31 = TRUE ;
V_34 = 0x800 ;
break;
default:
break;
}
V_10 = V_127 -> V_146 ;
}
void
F_20 ( void )
{
F_21 ( V_7 ) ;
}
