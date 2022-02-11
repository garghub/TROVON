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
V_71 . V_73 . V_74 = ( T_1 ) V_75 ;
V_71 . V_73 . V_76 = V_77 * 1000 ;
if ( V_78 == NULL ) { V_77 ++ ; }
V_71 . V_79 = V_71 . V_41 = V_14 + V_8 + V_17 ;
V_71 . V_80 = V_81 ;
V_71 . V_82 = 0 ;
V_71 . V_83 = 0 ;
V_71 . V_84 = NULL ;
V_71 . V_85 = 0 ;
V_71 . V_86 = 0 ;
V_71 . V_86 |= V_87 ;
V_71 . V_83 = V_88 | V_89 | V_90 | V_91 ;
F_12 ( V_92 , & V_71 , V_7 , & V_72 ) ;
}
}
V_93 += V_8 ;
V_8 = 0 ;
}
static void
F_13 ( char * V_1 )
{
T_3 V_94 ;
if ( V_95 != 0 ) {
if ( V_95 == V_96 )
return;
V_97 [ V_95 ++ ] = ' ' ;
}
V_94 = strlen ( V_1 ) ;
if ( V_94 != 0 ) {
if ( V_95 + V_94 > V_96 )
return;
F_14 ( & V_97 [ V_95 ] , V_1 , V_96 ) ;
V_95 += ( int ) V_94 ;
if ( V_98 >= 2 ) {
char * V_4 ;
char V_99 [ V_96 ] ;
F_14 ( V_99 , V_97 , V_96 ) ;
while ( ( V_4 = strchr ( V_99 , '\r' ) ) != NULL ) * V_4 = ' ' ;
fprintf ( V_6 , L_2 , V_99 ) ;
}
}
}
static void
F_15 ( void )
{
struct V_100 V_101 ;
char * V_102 ;
char * V_103 ;
int V_104 ;
int V_19 ;
V_97 [ V_95 ] = '\0' ;
if ( V_105 ) {
switch ( V_97 [ 0 ] ) {
case 'i' :
case 'I' :
V_87 = 0x00000001 ;
V_97 [ 0 ] = ' ' ;
break;
case 'o' :
case 'O' :
V_87 = 0x00000002 ;
V_97 [ 0 ] = ' ' ;
break;
default:
V_87 = 0x00000000 ;
break;
}
V_19 = 0 ;
while ( V_97 [ V_19 ] == ' ' ||
V_97 [ V_19 ] == '\r' ||
V_97 [ V_19 ] == '\t' ) {
V_19 ++ ;
}
V_95 -= V_19 ;
memmove ( V_97 , V_97 + V_19 , V_95 + 1 ) ;
}
if ( V_78 == NULL )
return;
V_101 = V_106 ;
V_77 = 0 ;
if ( strlen ( V_97 ) > 2 ) {
V_102 = strptime ( V_97 , V_78 , & V_101 ) ;
if ( V_102 != NULL ) {
V_75 = mktime ( & V_101 ) ;
} else
V_75 = - 1 ;
if ( - 1 == V_75 )
{
char * V_4 ;
while ( ( V_4 = strchr ( V_97 , '\r' ) ) != NULL ) * V_4 = ' ' ;
fprintf ( V_6 , L_3 ,
V_97 , V_78 ) ;
if ( V_98 >= 2 ) {
fprintf ( V_6 , L_4 ,
V_101 . V_107 , V_101 . V_108 , V_101 . V_109 ,
V_101 . V_110 , V_101 . V_111 , V_101 . V_112 , V_101 . V_113 ) ;
}
V_75 = 0 ;
V_77 = 0 ;
}
else
{
V_77 = ( T_1 ) strtol ( V_102 , & V_103 , 10 ) ;
if ( V_102 == V_103 ) {
V_77 = 0 ;
} else {
V_104 = ( int ) ( V_103 - V_102 ) ;
if ( V_104 > 6 ) {
for ( V_19 = V_104 - 6 ; V_19 != 0 ; V_19 -- )
V_77 /= 10 ;
} else if ( V_104 < 6 ) {
for ( V_19 = 6 - V_104 ; V_19 != 0 ; V_19 -- )
V_77 *= 10 ;
}
}
}
}
if ( V_98 >= 2 ) {
char * V_4 ;
while ( ( V_4 = strchr ( V_97 , '\r' ) ) != NULL ) * V_4 = ' ' ;
fprintf ( V_6 , L_5 , V_97 ) ;
fprintf ( V_6 , L_6 , V_78 , ( T_1 ) V_75 , V_77 ) ;
}
V_95 = 0 ;
}
static void
F_3 ( void )
{
if ( V_98 >= 1 )
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
F_17 ( T_4 V_114 , char * V_1 )
{
T_1 V_3 ;
if ( V_98 >= 2 ) {
char * V_4 ;
if ( V_1 != NULL ) { while ( ( V_4 = strchr ( V_1 , '\r' ) ) != NULL ) * V_4 = ' ' ; }
fprintf ( V_6 , L_9 ,
V_115 [ V_116 ] , V_117 [ V_114 ] , V_1 ? V_1 : L_10 ) ;
}
switch( V_116 ) {
case V_118 :
switch( V_114 ) {
case V_119 :
F_13 ( V_1 ) ;
break;
case V_120 :
F_16 ( V_1 ) ;
break;
case V_121 :
V_3 = F_1 ( V_1 , TRUE ) ;
if ( V_3 == 0 ) {
F_3 () ;
V_116 = V_122 ;
}
break;
default:
break;
}
break;
case V_123 :
switch( V_114 ) {
case V_119 :
F_13 ( V_1 ) ;
break;
case V_120 :
F_16 ( V_1 ) ;
break;
case V_121 :
V_3 = F_1 ( V_1 , TRUE ) ;
if ( V_3 == 0 ) {
F_3 () ;
V_93 = 0 ;
V_116 = V_122 ;
} else if ( ( V_3 - V_93 ) != V_8 ) {
if ( V_3 < V_8 ) {
F_4 ( V_8 - V_3 ) ;
V_116 = V_122 ;
} else {
if ( V_98 >= 1 )
fprintf ( V_6 , L_11 ,
V_8 , V_3 ) ;
F_6 () ;
V_116 = V_118 ;
}
} else
V_116 = V_122 ;
break;
default:
break;
}
break;
case V_122 :
switch( V_114 ) {
case V_124 :
V_116 = V_125 ;
F_2 ( V_1 ) ;
break;
case V_119 :
case V_120 :
case V_121 :
V_116 = V_126 ;
break;
case V_127 :
V_116 = V_123 ;
break;
default:
break;
}
break;
case V_125 :
switch( V_114 ) {
case V_124 :
F_2 ( V_1 ) ;
break;
case V_119 :
case V_120 :
case V_121 :
V_116 = V_126 ;
break;
case V_127 :
V_116 = V_123 ;
break;
default:
break;
}
break;
case V_126 :
switch( V_114 ) {
case V_127 :
V_116 = V_123 ;
break;
default:
break;
}
break;
default:
fprintf ( V_6 , L_12 , V_116 ) ;
exit ( - 1 ) ;
}
if ( V_98 >= 2 )
fprintf ( V_6 , L_13 , V_115 [ V_116 ] ) ;
}
void
F_18 ( T_5 * V_128 )
{
V_7 = ( V_9 * ) F_19 ( sizeof( V_32 ) + sizeof( V_30 ) +
sizeof( V_24 ) + sizeof( V_22 ) +
V_129 ) ;
if ( ! V_7 )
{
fprintf ( V_6 , L_14 ) ;
exit ( - 1 ) ;
}
V_116 = V_118 ;
V_8 = 0 ;
V_93 = 0 ;
V_95 = 0 ;
V_75 = time ( 0 ) ;
V_106 = * localtime ( & V_75 ) ;
V_106 . V_113 = - 1 ;
V_77 = 0 ;
V_31 = FALSE ;
V_29 = FALSE ;
V_25 = FALSE ;
V_27 = FALSE ;
V_23 = FALSE ;
V_21 = FALSE ;
V_5 = ( V_128 -> V_130 == V_131 ) ? 16 :
( V_128 -> V_130 == V_132 ) ? 8 :
( V_128 -> V_130 == V_133 ) ? 10 :
16 ;
V_105 = V_128 -> V_105 ;
if ( V_128 -> V_134 )
{
V_78 = V_128 -> V_135 ;
}
V_81 = V_128 -> V_136 ;
V_92 = V_128 -> V_92 ;
switch ( V_128 -> V_137 )
{
case V_138 :
V_31 = TRUE ;
V_34 = V_128 -> V_139 ;
break;
case V_140 :
V_29 = TRUE ;
V_38 = V_128 -> V_37 ;
V_31 = TRUE ;
V_34 = 0x800 ;
break;
case V_141 :
V_25 = TRUE ;
V_27 = FALSE ;
V_47 = V_128 -> V_63 ;
V_49 = V_128 -> V_142 ;
V_29 = TRUE ;
V_38 = 17 ;
V_31 = TRUE ;
V_34 = 0x800 ;
break;
case V_143 :
V_27 = TRUE ;
V_25 = FALSE ;
V_47 = V_128 -> V_63 ;
V_49 = V_128 -> V_142 ;
V_29 = TRUE ;
V_38 = 6 ;
V_31 = TRUE ;
V_34 = 0x800 ;
break;
case V_144 :
V_23 = TRUE ;
V_64 = V_128 -> V_63 ;
V_65 = V_128 -> V_142 ;
V_67 = V_128 -> V_66 ;
V_29 = TRUE ;
V_38 = 132 ;
V_31 = TRUE ;
V_34 = 0x800 ;
break;
case V_145 :
V_23 = TRUE ;
V_21 = TRUE ;
V_64 = V_128 -> V_63 ;
V_65 = V_128 -> V_142 ;
V_62 = V_128 -> V_146 ;
V_29 = TRUE ;
V_38 = 132 ;
V_31 = TRUE ;
V_34 = 0x800 ;
break;
default:
break;
}
V_10 = V_128 -> V_147 ;
}
void
F_20 ( void )
{
F_21 ( V_7 ) ;
}
