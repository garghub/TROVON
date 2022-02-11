static unsigned long
F_1 ( const char * V_1 , int V_2 )
{
unsigned long V_3 ;
char * V_4 ;
V_3 = strtoul ( V_1 , & V_4 , V_2 ? V_5 : 16 ) ;
if ( V_4 == V_1 ) {
fprintf ( V_6 , L_1 , V_1 ) ;
}
return V_3 ;
}
static void
F_2 ( const char * V_1 )
{
unsigned long V_3 ;
V_3 = F_1 ( V_1 , FALSE ) ;
V_7 [ V_8 ] = ( unsigned char ) V_3 ;
V_8 ++ ;
if ( V_8 >= V_9 )
F_3 () ;
}
static void
F_4 ( unsigned long V_10 )
{
V_8 -= V_10 ;
}
static unsigned long
F_5 ( unsigned long V_11 )
{
unsigned long V_12 ;
V_12 = V_11 % 4 ;
if ( V_12 == 0 )
return 0 ;
else
return 4 - V_12 ;
}
void
F_6 ( void )
{
int V_13 = 0 ;
int V_14 = 0 ;
int V_15 = 0 ;
int V_16 = 0 ;
int V_17 = 0 ;
int V_18 , V_19 ;
if ( V_8 > 0 ) {
V_13 = 0 ;
if ( V_20 ) { V_13 += sizeof( V_21 ) ; }
if ( V_22 ) { V_13 += sizeof( V_23 ) ; }
if ( V_24 ) { V_13 += sizeof( V_25 ) ; V_14 = V_13 + V_8 ; }
if ( V_26 ) { V_13 += sizeof( V_27 ) ; V_14 = V_13 + V_8 ; }
if ( V_28 ) {
V_13 += sizeof( V_29 ) ;
V_15 = V_13 + V_8 + ( ( V_20 ) ? F_5 ( V_8 ) : 0 ) ;
}
if ( V_30 ) { V_13 += sizeof( V_31 ) ; }
memmove ( & V_7 [ V_13 ] , V_7 , V_8 ) ;
if ( V_30 ) {
if ( V_13 + V_8 < 60 ) {
V_16 = 60 - ( V_13 + V_8 ) ;
}
}
if ( V_30 ) {
V_31 . V_32 = F_7 ( V_33 ) ;
memcpy ( & V_7 [ V_17 ] , & V_31 , sizeof( V_31 ) ) ;
V_17 += sizeof( V_31 ) ;
}
if ( V_28 ) {
T_1 V_34 [ 1 ] ;
V_29 . V_35 = F_7 ( V_15 ) ;
V_29 . V_36 = ( V_37 ) V_38 ;
V_29 . V_39 = 0 ;
V_34 [ 0 ] . V_40 = ( V_37 * ) & V_29 ; V_34 [ 0 ] . V_41 = sizeof( V_29 ) ;
V_29 . V_39 = F_8 ( V_34 , 1 ) ;
memcpy ( & V_7 [ V_17 ] , & V_29 , sizeof( V_29 ) ) ;
V_17 += sizeof( V_29 ) ;
}
V_42 . V_43 = V_29 . V_43 ;
V_42 . V_44 = V_29 . V_44 ;
V_42 . V_45 = 0 ;
V_42 . V_36 = ( V_37 ) V_38 ;
V_42 . V_11 = F_7 ( V_14 ) ;
if ( V_24 ) {
T_1 V_34 [ 3 ] ;
V_25 . V_46 = F_7 ( V_47 ) ;
V_25 . V_48 = F_7 ( V_49 ) ;
V_25 . V_11 = F_7 ( V_14 ) ;
V_25 . V_50 = 0 ;
V_34 [ 0 ] . V_40 = ( V_37 * ) & V_42 ; V_34 [ 0 ] . V_41 = sizeof( V_42 ) ;
V_34 [ 1 ] . V_40 = ( V_37 * ) & V_25 ; V_34 [ 1 ] . V_41 = sizeof( V_25 ) ;
V_34 [ 2 ] . V_40 = & V_7 [ V_13 ] ; V_34 [ 2 ] . V_41 = V_8 ;
V_25 . V_50 = F_8 ( V_34 , 3 ) ;
memcpy ( & V_7 [ V_17 ] , & V_25 , sizeof( V_25 ) ) ;
V_17 += sizeof( V_25 ) ;
}
if ( V_26 ) {
T_1 V_34 [ 3 ] ;
V_27 . V_46 = F_7 ( V_47 ) ;
V_27 . V_48 = F_7 ( V_49 ) ;
V_27 . V_51 = F_7 ( 0x2000 ) ;
V_27 . V_50 = 0 ;
V_34 [ 0 ] . V_40 = ( V_37 * ) & V_42 ; V_34 [ 0 ] . V_41 = sizeof( V_42 ) ;
V_34 [ 1 ] . V_40 = ( V_37 * ) & V_27 ; V_34 [ 1 ] . V_41 = sizeof( V_27 ) ;
V_34 [ 2 ] . V_40 = & V_7 [ V_13 ] ; V_34 [ 2 ] . V_41 = V_8 ;
V_27 . V_50 = F_8 ( V_34 , 3 ) ;
memcpy ( & V_7 [ V_17 ] , & V_27 , sizeof( V_27 ) ) ;
V_17 += sizeof( V_27 ) ;
}
if ( V_20 ) {
V_21 . type = V_52 ;
V_21 . V_53 = V_54 ;
V_21 . V_11 = F_7 ( V_8 + sizeof( V_21 ) ) ;
V_21 . V_55 = F_9 ( V_56 ) ;
V_21 . V_57 = F_7 ( V_58 ) ;
V_21 . V_59 = F_7 ( V_60 ) ;
V_21 . V_61 = F_9 ( V_62 ) ;
V_19 = F_5 ( V_8 ) ;
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ )
V_7 [ V_13 + V_8 + V_18 ] = 0 ;
V_8 += V_19 ;
}
if ( V_22 ) {
V_23 . V_63 = F_7 ( V_64 ) ;
V_23 . V_48 = F_7 ( V_65 ) ;
V_23 . V_66 = F_9 ( V_67 ) ;
V_23 . V_50 = F_9 ( 0 ) ;
V_23 . V_50 = F_10 ( & V_23 , sizeof( V_23 ) , V_68 ) ;
if ( V_20 )
V_23 . V_50 = F_10 ( & V_21 , sizeof( V_21 ) , V_23 . V_50 ) ;
V_23 . V_50 = F_9 ( ~ F_10 ( & V_7 [ V_13 ] , V_8 , V_23 . V_50 ) ) ;
memcpy ( & V_7 [ V_17 ] , & V_23 , sizeof( V_23 ) ) ;
V_17 += sizeof( V_23 ) ;
}
if ( V_20 ) {
memcpy ( & V_7 [ V_17 ] , & V_21 , sizeof( V_21 ) ) ;
V_17 += sizeof( V_21 ) ;
}
if ( V_30 && V_16 > 0 ) {
memset ( & V_7 [ V_13 + V_8 ] , 0 , V_16 ) ;
}
V_27 . V_69 = F_9 ( F_11 ( V_27 . V_69 ) + V_8 ) ;
{
struct V_70 V_71 ;
int V_72 ;
V_71 . V_73 . V_74 = ( V_75 ) V_76 ;
V_71 . V_73 . V_77 = V_78 * 1000 ;
if ( V_79 == NULL ) { V_78 ++ ; }
V_71 . V_80 = V_71 . V_41 = V_13 + V_8 + V_16 ;
V_71 . V_81 = V_82 ;
F_12 ( V_83 , & V_71 , NULL , V_7 , & V_72 ) ;
}
}
V_84 += V_8 ;
V_8 = 0 ;
}
static void
F_13 ( char * V_1 )
{
T_2 V_85 ;
if ( V_86 != 0 ) {
if ( V_86 == V_87 )
return;
V_88 [ V_86 ++ ] = ' ' ;
}
V_85 = strlen ( V_1 ) ;
if ( V_85 != 0 ) {
if ( V_86 + V_85 > V_87 )
return;
F_14 ( & V_88 [ V_86 ] , V_1 , V_87 ) ;
V_86 += ( int ) V_85 ;
if ( V_89 >= 2 ) {
char * V_4 ;
char V_90 [ V_87 ] ;
F_14 ( V_90 , V_88 , V_87 ) ;
while ( ( V_4 = strchr ( V_90 , '\r' ) ) != NULL ) * V_4 = ' ' ;
fprintf ( V_6 , L_2 , V_90 ) ;
}
}
}
static void
F_15 ( void )
{
struct V_91 V_92 ;
char * V_93 ;
char * V_94 ;
int V_95 ;
int V_18 ;
if ( V_79 == NULL )
return;
V_92 = V_96 ;
V_78 = 0 ;
V_88 [ V_86 ] = '\0' ;
if ( strlen ( V_88 ) > 2 ) {
V_93 = strptime ( V_88 , V_79 , & V_92 ) ;
if ( V_93 != NULL ) {
V_76 = mktime ( & V_92 ) ;
} else
V_76 = - 1 ;
if ( - 1 == V_76 )
{
char * V_4 ;
while ( ( V_4 = strchr ( V_88 , '\r' ) ) != NULL ) * V_4 = ' ' ;
fprintf ( V_6 , L_3 ,
V_88 , V_79 ) ;
if ( V_89 >= 2 ) {
fprintf ( V_6 , L_4 ,
V_92 . V_97 , V_92 . V_98 , V_92 . V_99 ,
V_92 . V_100 , V_92 . V_101 , V_92 . V_102 , V_92 . V_103 ) ;
}
V_76 = 0 ;
V_78 = 0 ;
}
else
{
V_78 = strtol ( V_93 , & V_94 , 10 ) ;
if ( V_93 == V_94 ) {
V_78 = 0 ;
} else {
V_95 = ( int ) ( V_94 - V_93 ) ;
if ( V_95 > 6 ) {
for ( V_18 = V_95 - 6 ; V_18 != 0 ; V_18 -- )
V_78 /= 10 ;
} else if ( V_95 < 6 ) {
for ( V_18 = 6 - V_95 ; V_18 != 0 ; V_18 -- )
V_78 *= 10 ;
}
}
}
}
if ( V_89 >= 2 ) {
char * V_4 ;
while ( ( V_4 = strchr ( V_88 , '\r' ) ) != NULL ) * V_4 = ' ' ;
fprintf ( V_6 , L_5 , V_88 ) ;
fprintf ( V_6 , L_6 , V_79 , ( V_75 ) V_76 , V_78 ) ;
}
V_86 = 0 ;
}
static void
F_3 ( void )
{
if ( V_89 >= 1 )
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
F_17 ( T_3 V_104 , char * V_1 )
{
unsigned long V_3 ;
if ( V_89 >= 2 ) {
char * V_4 ;
if ( V_1 != NULL ) { while ( ( V_4 = strchr ( V_1 , '\r' ) ) != NULL ) * V_4 = ' ' ; }
fprintf ( V_6 , L_9 ,
V_105 [ V_106 ] , V_107 [ V_104 ] , V_1 ? V_1 : L_10 ) ;
}
switch( V_106 ) {
case V_108 :
switch( V_104 ) {
case V_109 :
F_13 ( V_1 ) ;
break;
case V_110 :
F_16 ( V_1 ) ;
break;
case V_111 :
V_3 = F_1 ( V_1 , TRUE ) ;
if ( V_3 == 0 ) {
F_3 () ;
V_106 = V_112 ;
}
break;
default:
break;
}
break;
case V_113 :
switch( V_104 ) {
case V_109 :
F_13 ( V_1 ) ;
break;
case V_110 :
F_16 ( V_1 ) ;
break;
case V_111 :
V_3 = F_1 ( V_1 , TRUE ) ;
if ( V_3 == 0 ) {
F_3 () ;
V_84 = 0 ;
V_106 = V_112 ;
} else if ( ( V_3 - V_84 ) != V_8 ) {
if ( V_3 < V_8 ) {
F_4 ( V_8 - V_3 ) ;
V_106 = V_112 ;
} else {
if ( V_89 >= 1 )
fprintf ( V_6 , L_11 ,
V_8 , V_3 ) ;
F_6 () ;
V_106 = V_108 ;
}
} else
V_106 = V_112 ;
break;
default:
break;
}
break;
case V_112 :
switch( V_104 ) {
case V_114 :
V_106 = V_115 ;
F_2 ( V_1 ) ;
break;
case V_109 :
case V_110 :
case V_111 :
V_106 = V_116 ;
break;
case V_117 :
V_106 = V_113 ;
break;
default:
break;
}
break;
case V_115 :
switch( V_104 ) {
case V_114 :
F_2 ( V_1 ) ;
break;
case V_109 :
case V_110 :
case V_111 :
V_106 = V_116 ;
break;
case V_117 :
V_106 = V_113 ;
break;
default:
break;
}
break;
case V_116 :
switch( V_104 ) {
case V_117 :
V_106 = V_113 ;
break;
default:
break;
}
break;
default:
fprintf ( V_6 , L_12 , V_106 ) ;
exit ( - 1 ) ;
}
if ( V_89 >= 2 )
fprintf ( V_6 , L_13 , V_105 [ V_106 ] ) ;
}
void
F_18 ( T_4 * V_118 )
{
V_7 = ( unsigned char * ) F_19 ( sizeof( V_31 ) + sizeof( V_29 ) +
sizeof( V_23 ) + sizeof( V_21 ) +
V_119 ) ;
if ( ! V_7 )
{
fprintf ( V_6 , L_14 ) ;
exit ( - 1 ) ;
}
V_106 = V_108 ;
V_8 = 0 ;
V_84 = 0 ;
V_86 = 0 ;
V_76 = time ( 0 ) ;
V_96 = * localtime ( & V_76 ) ;
V_96 . V_103 = - 1 ;
V_78 = 0 ;
V_30 = FALSE ;
V_28 = FALSE ;
V_24 = FALSE ;
V_26 = FALSE ;
V_22 = FALSE ;
V_20 = FALSE ;
V_5 = ( V_118 -> V_120 == V_121 ) ? 16 :
( V_118 -> V_120 == V_122 ) ? 8 :
( V_118 -> V_120 == V_123 ) ? 10 :
16 ;
if ( V_118 -> V_124 )
{
V_79 = V_118 -> V_125 ;
}
V_82 = V_118 -> V_126 ;
V_83 = V_118 -> V_83 ;
switch ( V_118 -> V_127 )
{
case V_128 :
V_30 = TRUE ;
V_33 = V_118 -> V_129 ;
break;
case V_130 :
V_28 = TRUE ;
V_38 = V_118 -> V_36 ;
V_30 = TRUE ;
V_33 = 0x800 ;
break;
case V_131 :
V_24 = TRUE ;
V_26 = FALSE ;
V_47 = V_118 -> V_63 ;
V_49 = V_118 -> V_132 ;
V_28 = TRUE ;
V_38 = 17 ;
V_30 = TRUE ;
V_33 = 0x800 ;
break;
case V_133 :
V_26 = TRUE ;
V_24 = FALSE ;
V_47 = V_118 -> V_63 ;
V_49 = V_118 -> V_132 ;
V_28 = TRUE ;
V_38 = 6 ;
V_30 = TRUE ;
V_33 = 0x800 ;
break;
case V_134 :
V_22 = TRUE ;
V_64 = V_118 -> V_63 ;
V_65 = V_118 -> V_132 ;
V_67 = V_118 -> V_66 ;
V_28 = TRUE ;
V_38 = 132 ;
V_30 = TRUE ;
V_33 = 0x800 ;
break;
case V_135 :
V_22 = TRUE ;
V_20 = TRUE ;
V_64 = V_118 -> V_63 ;
V_65 = V_118 -> V_132 ;
V_62 = V_118 -> V_136 ;
V_28 = TRUE ;
V_38 = 132 ;
V_30 = TRUE ;
V_33 = 0x800 ;
break;
default:
break;
}
V_9 = V_118 -> V_137 ;
}
void
F_20 ( void )
{
F_21 ( V_7 ) ;
}
