static int T_1 F_1 ( const struct V_1 * V_2 )
{
V_3 = V_2 -> V_4 ;
return 1 ;
}
static void F_2 ( void )
{
memset ( V_5 , 0 , sizeof( struct V_6 ) ) ;
}
static void F_3 ( void )
{
F_4 ( & V_7 ) ;
F_2 () ;
}
static void F_5 ( void )
{
F_6 ( & V_7 ) ;
}
static void T_1 F_7 ( const struct V_8 * V_9 )
{
int V_10 = ( V_9 -> V_11 - 11 ) / sizeof( struct V_12 ) - 1 ;
struct V_12 * V_13 ;
struct V_14 * V_15 =
F_8 ( V_9 , struct V_14 , V_16 ) ;
if ( V_9 -> V_11 < 17 )
return;
V_17 = V_15 -> V_18 ;
V_19 = V_15 -> V_20 ;
V_13 = F_9 ( V_21 , ( V_22 + V_10 ) *
sizeof( struct V_12 ) ,
V_23 ) ;
if ( ! V_13 )
return;
V_21 = V_13 ;
memcpy ( V_21 + V_22 , V_15 -> V_10 ,
sizeof( struct V_12 ) * V_10 ) ;
V_22 += V_10 ;
}
static void T_1 F_10 ( const struct V_8 * V_9 , void * V_24 )
{
switch ( V_9 -> type ) {
case 0xd4 :
case 0xd5 :
case 0xd6 :
break;
case 0xda :
F_7 ( V_9 ) ;
break;
}
}
static int F_11 ( int V_25 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_22 ; V_26 ++ ) {
if ( V_21 [ V_26 ] . V_27 == V_25 )
return V_26 ;
}
return - 1 ;
}
static int F_12 ( int V_25 )
{
int V_28 ;
V_28 = F_11 ( V_25 ) ;
if ( V_28 == - 1 )
return - 1 ;
return V_21 [ V_28 ] . V_29 ;
}
static struct V_6 *
F_13 ( struct V_6 * V_5 , int V_30 ,
int V_31 )
{
struct V_32 V_33 ;
V_33 . V_34 = V_35 ;
V_33 . V_36 = V_17 ;
V_33 . V_37 = V_19 ;
V_33 . V_38 = F_14 ( V_5 ) ;
V_33 . V_39 = 0x42534931 ;
V_5 -> V_30 = V_30 ;
V_5 -> V_31 = V_31 ;
F_15 ( & V_33 ) ;
return V_5 ;
}
static inline int F_16 ( int V_40 )
{
switch ( V_40 ) {
case 0 :
return 0 ;
case - 1 :
return - V_41 ;
case - 2 :
return - V_42 ;
default:
return - V_43 ;
}
}
static int F_17 ( void * V_44 , bool V_45 )
{
int V_46 = V_45 ? 1 : 0 ;
unsigned long V_47 = ( unsigned long ) V_44 ;
int V_48 = ( unsigned long ) V_44 - 1 ;
int V_49 ;
int V_50 ;
int V_51 ;
F_3 () ;
F_13 ( V_5 , 17 , 11 ) ;
V_51 = V_5 -> V_52 [ 0 ] ;
V_50 = V_5 -> V_52 [ 1 ] ;
if ( V_51 != 0 )
goto V_53;
F_2 () ;
V_5 -> V_54 [ 0 ] = 0x2 ;
F_13 ( V_5 , 17 , 11 ) ;
V_51 = V_5 -> V_52 [ 0 ] ;
V_49 = V_5 -> V_52 [ 1 ] ;
if ( V_51 == 0 && ( V_49 & F_18 ( V_48 ) ) &&
( V_50 & F_18 ( 0 ) ) && ! ( V_50 & F_18 ( 16 ) ) )
V_46 = 1 ;
F_2 () ;
V_5 -> V_54 [ 0 ] = ( 1 | ( V_47 << 8 ) | ( V_46 << 16 ) ) ;
F_13 ( V_5 , 17 , 11 ) ;
V_51 = V_5 -> V_52 [ 0 ] ;
V_53:
F_5 () ;
return F_16 ( V_51 ) ;
}
static void F_19 ( struct V_55 * V_55 , int V_47 ,
int V_50 )
{
if ( V_50 & F_18 ( 0 ) ) {
int V_56 = F_20 ( V_55 ) ;
F_2 () ;
V_5 -> V_54 [ 0 ] = ( 1 | ( V_47 << 8 ) | ( V_56 << 16 ) ) ;
F_13 ( V_5 , 17 , 11 ) ;
} else {
F_21 ( V_55 , ! ! ( V_50 & F_18 ( V_47 + 16 ) ) ) ;
}
}
static void F_22 ( struct V_55 * V_55 , int V_47 ,
int V_50 , int V_49 )
{
if ( V_49 & ( F_18 ( V_47 - 1 ) ) )
F_23 ( V_55 , ! ( V_50 & F_18 ( 16 ) ) ) ;
}
static void F_24 ( struct V_55 * V_55 , void * V_44 )
{
int V_47 = ( ( unsigned long ) V_44 & 0xF ) ;
int V_49 ;
int V_50 ;
int V_51 ;
F_3 () ;
F_13 ( V_5 , 17 , 11 ) ;
V_51 = V_5 -> V_52 [ 0 ] ;
V_50 = V_5 -> V_52 [ 1 ] ;
if ( V_51 != 0 || ! ( V_50 & F_18 ( 0 ) ) ) {
F_5 () ;
return;
}
F_2 () ;
V_5 -> V_54 [ 0 ] = 0x2 ;
F_13 ( V_5 , 17 , 11 ) ;
V_51 = V_5 -> V_52 [ 0 ] ;
V_49 = V_5 -> V_52 [ 1 ] ;
F_5 () ;
if ( V_51 != 0 )
return;
F_22 ( V_55 , V_47 , V_50 , V_49 ) ;
}
static int F_25 ( struct V_57 * V_58 , void * V_44 )
{
int V_59 ;
int V_60 ;
int V_50 ;
int V_51 ;
F_3 () ;
F_13 ( V_5 , 17 , 11 ) ;
V_51 = V_5 -> V_52 [ 0 ] ;
V_50 = V_5 -> V_52 [ 1 ] ;
F_2 () ;
V_5 -> V_54 [ 0 ] = 0x2 ;
F_13 ( V_5 , 17 , 11 ) ;
V_60 = V_5 -> V_52 [ 0 ] ;
V_59 = V_5 -> V_52 [ 1 ] ;
F_5 () ;
F_26 ( V_58 , L_1 , V_51 ) ;
F_26 ( V_58 , L_2 , V_50 ) ;
F_26 ( V_58 , L_3 ,
V_50 & F_18 ( 0 ) ) ;
F_26 ( V_58 , L_4 ,
( V_50 & F_18 ( 1 ) ) >> 1 ) ;
F_26 ( V_58 , L_5 ,
( V_50 & F_18 ( 2 ) ) >> 2 ) ;
F_26 ( V_58 , L_6 ,
( V_50 & F_18 ( 3 ) ) >> 3 ) ;
F_26 ( V_58 , L_7 ,
( V_50 & F_18 ( 4 ) ) >> 4 ) ;
F_26 ( V_58 , L_8 ,
( V_50 & F_18 ( 5 ) ) >> 5 ) ;
F_26 ( V_58 , L_9 ,
( V_50 & F_18 ( 6 ) ) >> 6 ) ;
F_26 ( V_58 , L_10 ,
( V_50 & F_18 ( 7 ) ) >> 7 ) ;
F_26 ( V_58 , L_11 ,
( V_50 & F_18 ( 8 ) ) >> 8 ) ;
F_26 ( V_58 , L_12 ,
( V_50 & F_18 ( 9 ) ) >> 9 ) ;
F_26 ( V_58 , L_13 ,
( V_50 & F_18 ( 10 ) ) >> 10 ) ;
F_26 ( V_58 , L_14 ,
( V_50 & F_18 ( 11 ) ) >> 11 ) ;
F_26 ( V_58 , L_15 ,
( V_50 & F_18 ( 12 ) ) >> 12 ) ;
F_26 ( V_58 , L_16 ,
( V_50 & F_18 ( 16 ) ) >> 16 ) ;
F_26 ( V_58 , L_17 ,
( V_50 & F_18 ( 17 ) ) >> 17 ) ;
F_26 ( V_58 , L_18 ,
( V_50 & F_18 ( 18 ) ) >> 18 ) ;
F_26 ( V_58 , L_19 ,
( V_50 & F_18 ( 19 ) ) >> 19 ) ;
F_26 ( V_58 , L_20 ,
( V_50 & F_18 ( 20 ) ) >> 20 ) ;
F_26 ( V_58 , L_21 ,
( V_50 & F_18 ( 21 ) ) >> 21 ) ;
F_26 ( V_58 , L_22 , V_60 ) ;
F_26 ( V_58 , L_23 , V_59 ) ;
F_26 ( V_58 , L_24 ,
V_59 & F_18 ( 0 ) ) ;
F_26 ( V_58 , L_25 ,
( V_59 & F_18 ( 1 ) ) >> 1 ) ;
F_26 ( V_58 , L_26 ,
( V_59 & F_18 ( 2 ) ) >> 2 ) ;
F_26 ( V_58 , L_27 ,
( V_59 & F_18 ( 3 ) ) >> 3 ) ;
F_26 ( V_58 , L_28 ,
( V_59 & F_18 ( 4 ) ) >> 4 ) ;
F_26 ( V_58 , L_29 ,
( V_59 & F_18 ( 7 ) ) >> 7 ) ;
F_26 ( V_58 , L_30 ,
( V_59 & F_18 ( 8 ) ) >> 8 ) ;
F_26 ( V_58 , L_31 ,
( V_59 & F_18 ( 15 ) ) >> 15 ) ;
return 0 ;
}
static int F_27 ( struct V_61 * V_61 , struct V_62 * V_62 )
{
return F_28 ( V_62 , F_25 , V_61 -> V_63 ) ;
}
static void F_29 ( struct V_64 * V_65 )
{
int V_49 = 0 ;
int V_50 ;
int V_51 ;
F_3 () ;
F_13 ( V_5 , 17 , 11 ) ;
V_51 = V_5 -> V_52 [ 0 ] ;
V_50 = V_5 -> V_52 [ 1 ] ;
if ( V_51 != 0 )
goto V_53;
F_2 () ;
V_5 -> V_54 [ 0 ] = 0x2 ;
F_13 ( V_5 , 17 , 11 ) ;
V_51 = V_5 -> V_52 [ 0 ] ;
if ( V_51 == 0 && ( V_50 & F_18 ( 0 ) ) )
V_49 = V_5 -> V_52 [ 1 ] ;
if ( V_66 ) {
F_22 ( V_66 , 1 , V_50 , V_49 ) ;
F_19 ( V_66 , 1 , V_50 ) ;
}
if ( V_67 ) {
F_22 ( V_67 , 2 , V_50 ,
V_49 ) ;
F_19 ( V_67 , 2 , V_50 ) ;
}
if ( V_68 ) {
F_22 ( V_68 , 3 , V_50 , V_49 ) ;
F_19 ( V_68 , 3 , V_50 ) ;
}
V_53:
F_5 () ;
}
static bool F_30 ( unsigned char V_44 , unsigned char V_69 ,
struct V_70 * V_71 )
{
static bool V_72 ;
if ( V_69 & V_73 )
return false ;
if ( F_31 ( V_44 == 0xe0 ) ) {
V_72 = true ;
return false ;
} else if ( F_31 ( V_72 ) ) {
switch ( V_44 ) {
case 0x8 :
F_32 ( & V_74 ,
F_33 ( V_75 / 4 ) ) ;
break;
}
V_72 = false ;
}
return false ;
}
static int F_34 ( struct V_76 * V_77 ,
unsigned long V_78 , void * V_44 )
{
F_32 ( & V_74 , 0 ) ;
return V_79 ;
}
static int T_1 F_35 ( void )
{
int V_50 , V_51 , V_80 ;
const char * V_81 ;
V_80 = 0 ;
V_81 = F_36 ( V_82 ) ;
if ( V_81 && ( strncmp ( V_81 , L_32 , 8 ) == 0 ||
strncmp ( V_81 , L_33 , 9 ) == 0 ) )
V_80 = 1 ;
if ( ! V_83 && ! V_80 )
return 0 ;
F_3 () ;
F_13 ( V_5 , 17 , 11 ) ;
V_51 = V_5 -> V_52 [ 0 ] ;
V_50 = V_5 -> V_52 [ 1 ] ;
F_5 () ;
if ( V_51 != 0 )
return 0 ;
if ( ! ( V_50 & F_18 ( 0 ) ) && ! V_83 )
return 0 ;
if ( ( V_50 & ( 1 << 2 | 1 << 8 ) ) == ( 1 << 2 | 1 << 8 ) ) {
V_66 = F_37 ( L_34 , & V_84 -> V_85 ,
V_86 ,
& V_87 , ( void * ) 1 ) ;
if ( ! V_66 ) {
V_51 = - V_88 ;
goto V_89;
}
V_51 = F_38 ( V_66 ) ;
if ( V_51 )
goto V_89;
}
if ( ( V_50 & ( 1 << 3 | 1 << 9 ) ) == ( 1 << 3 | 1 << 9 ) ) {
V_67 = F_37 ( L_35 ,
& V_84 -> V_85 ,
V_90 ,
& V_87 , ( void * ) 2 ) ;
if ( ! V_67 ) {
V_51 = - V_88 ;
goto V_91;
}
V_51 = F_38 ( V_67 ) ;
if ( V_51 )
goto V_91;
}
if ( ( V_50 & ( 1 << 4 | 1 << 10 ) ) == ( 1 << 4 | 1 << 10 ) ) {
V_68 = F_37 ( L_36 ,
& V_84 -> V_85 ,
V_92 ,
& V_87 , ( void * ) 3 ) ;
if ( ! V_68 ) {
V_51 = - V_88 ;
goto V_93;
}
V_51 = F_38 ( V_68 ) ;
if ( V_51 )
goto V_93;
}
V_94 =
F_39 ( V_95 ) ;
if ( V_94 ) {
V_96 =
F_39 ( V_97 ) ;
if ( ! V_96 ) {
F_40 ( V_95 ) ;
V_94 = NULL ;
}
}
if ( V_94 ) {
V_51 = V_94 (
& V_98 ) ;
F_40 ( V_95 ) ;
V_94 = NULL ;
if ( V_51 != 0 ) {
F_40 ( V_97 ) ;
V_96 = NULL ;
}
} else {
F_41 ( L_37 ) ;
V_51 = - V_99 ;
}
if ( V_51 == 0 ) {
F_41 ( L_38 ) ;
} else if ( V_51 != - V_99 ) {
F_42 ( L_39 ) ;
goto V_100;
} else {
V_51 = F_43 ( F_30 ) ;
if ( V_51 ) {
F_42 ( L_40 ) ;
goto V_100;
}
F_41 ( L_41 ) ;
}
return 0 ;
V_100:
if ( V_68 )
F_44 ( V_68 ) ;
V_93:
F_45 ( V_68 ) ;
if ( V_67 )
F_44 ( V_67 ) ;
V_91:
F_45 ( V_67 ) ;
if ( V_66 )
F_44 ( V_66 ) ;
V_89:
F_45 ( V_66 ) ;
return V_51 ;
}
static void F_46 ( void )
{
if ( V_96 ) {
V_96 ( & V_98 ) ;
F_40 ( V_97 ) ;
V_96 = NULL ;
} else {
F_47 ( F_30 ) ;
}
F_48 ( & V_74 ) ;
if ( V_66 ) {
F_44 ( V_66 ) ;
F_45 ( V_66 ) ;
}
if ( V_67 ) {
F_44 ( V_67 ) ;
F_45 ( V_67 ) ;
}
if ( V_68 ) {
F_44 ( V_68 ) ;
F_45 ( V_68 ) ;
}
}
static int F_49 ( struct V_101 * V_102 )
{
int V_103 ;
int V_51 ;
V_103 = F_12 ( V_104 ) ;
if ( V_103 == - 1 )
return - V_99 ;
F_3 () ;
V_5 -> V_54 [ 0 ] = V_103 ;
V_5 -> V_54 [ 1 ] = V_102 -> V_105 . V_106 ;
if ( F_50 () > 0 )
F_13 ( V_5 , 1 , 2 ) ;
else
F_13 ( V_5 , 1 , 1 ) ;
V_51 = F_16 ( V_5 -> V_52 [ 0 ] ) ;
F_5 () ;
return V_51 ;
}
static int F_51 ( struct V_101 * V_102 )
{
int V_103 ;
int V_51 ;
V_103 = F_12 ( V_104 ) ;
if ( V_103 == - 1 )
return - V_99 ;
F_3 () ;
V_5 -> V_54 [ 0 ] = V_103 ;
if ( F_50 () > 0 )
F_13 ( V_5 , 0 , 2 ) ;
else
F_13 ( V_5 , 0 , 1 ) ;
if ( V_5 -> V_52 [ 0 ] )
V_51 = F_16 ( V_5 -> V_52 [ 0 ] ) ;
else
V_51 = V_5 -> V_52 [ 1 ] ;
F_5 () ;
return V_51 ;
}
static void F_52 ( void )
{
int V_33 = 0x97 ;
char V_44 = 1 ;
F_53 ( & V_44 , V_33 | 1 << 12 ) ;
}
static void F_54 ( void )
{
int V_33 = 0x97 ;
char V_44 = 2 ;
F_53 ( & V_44 , V_33 | 1 << 12 ) ;
}
static void F_55 ( struct V_107 * V_108 ,
enum V_109 V_40 )
{
if ( V_40 > 0 )
F_52 () ;
else
F_54 () ;
}
static int T_1 F_56 ( struct V_110 * V_85 )
{
return F_57 ( V_85 , & V_111 ) ;
}
static void F_58 ( void )
{
F_59 ( & V_111 ) ;
}
static int F_60 ( struct V_112 * V_113 )
{
T_2 V_114 ;
int V_51 ;
F_3 () ;
V_5 -> V_54 [ 0 ] = 0x0 ;
F_13 ( V_5 , 4 , 11 ) ;
V_51 = V_5 -> V_52 [ 0 ] ;
if ( V_51 ) {
V_51 = F_16 ( V_51 ) ;
goto V_53;
}
V_113 -> V_115 = V_5 -> V_52 [ 1 ] & 0xFFFF ;
V_113 -> type = ( V_5 -> V_52 [ 1 ] >> 24 ) & 0xFF ;
V_113 -> V_116 = V_5 -> V_52 [ 2 ] & 0xFF ;
V_114 = ( V_5 -> V_52 [ 2 ] >> 8 ) & 0xFF ;
V_113 -> V_117 = ( V_5 -> V_52 [ 2 ] >> 16 ) & 0xFF ;
if ( V_114 & F_18 ( 0 ) )
V_113 -> V_118 = ( V_5 -> V_52 [ 3 ] >> 0 ) & 0xFF ;
if ( V_114 & F_18 ( 1 ) )
V_113 -> V_119 = ( V_5 -> V_52 [ 3 ] >> 8 ) & 0xFF ;
if ( V_114 & F_18 ( 2 ) )
V_113 -> V_120 = ( V_5 -> V_52 [ 3 ] >> 16 ) & 0xFF ;
if ( V_114 & F_18 ( 3 ) )
V_113 -> V_121 = ( V_5 -> V_52 [ 3 ] >> 24 ) & 0xFF ;
V_53:
F_5 () ;
return V_51 ;
}
static unsigned int F_61 ( void )
{
if ( V_112 . V_117 != 0 )
return V_112 . V_117 ;
if ( V_122 > 0 )
return V_122 - 1 ;
return 0 ;
}
static int F_62 ( struct V_123 * V_124 )
{
int V_26 ;
if ( V_112 . V_117 != 0 )
return V_124 -> V_125 ;
if ( V_122 > 0 ) {
for ( V_26 = 0 ; V_26 < V_122 ; ++ V_26 )
if ( V_126 [ V_26 ] == V_124 -> V_127 )
return V_26 ;
return 0 ;
}
return - V_43 ;
}
static int F_63 ( struct V_123 * V_124 , T_2 V_125 )
{
if ( V_112 . V_117 != 0 ) {
if ( V_125 != 0 )
V_128 = V_125 ;
if ( V_124 -> V_125 == V_125 )
return 0 ;
V_124 -> V_125 = V_125 ;
if ( V_125 != 0 && V_124 -> V_127 == V_129 )
V_124 -> V_127 = V_130 ;
else if ( V_125 == 0 && V_124 -> V_127 != V_129 ) {
V_130 = V_124 -> V_127 ;
V_124 -> V_127 = V_129 ;
}
return 0 ;
}
if ( V_122 > 0 && V_125 < V_122 ) {
if ( V_125 != 0 )
V_128 = V_125 ;
V_124 -> V_127 = V_126 [ V_125 ] ;
return 0 ;
}
return - V_43 ;
}
static int F_64 ( struct V_123 * V_124 )
{
int V_51 ;
F_3 () ;
V_5 -> V_54 [ 0 ] = 0x1 ;
F_13 ( V_5 , 4 , 11 ) ;
V_51 = V_5 -> V_52 [ 0 ] ;
if ( V_51 ) {
V_51 = F_16 ( V_51 ) ;
goto V_53;
}
V_124 -> V_127 = F_65 ( V_5 -> V_52 [ 1 ] & 0xFFFF ) ;
if ( V_124 -> V_127 != 0 )
V_124 -> V_127 -- ;
V_124 -> V_116 = ( V_5 -> V_52 [ 1 ] >> 16 ) & 0xFF ;
V_124 -> V_131 = ( V_5 -> V_52 [ 1 ] >> 24 ) & 0x3F ;
V_124 -> V_132 = ( V_5 -> V_52 [ 1 ] >> 30 ) & 0x3 ;
V_124 -> V_133 = V_5 -> V_52 [ 2 ] & 0xFF ;
V_124 -> V_134 = ( V_5 -> V_52 [ 2 ] >> 8 ) & 0xFF ;
V_124 -> V_125 = ( V_5 -> V_52 [ 2 ] >> 16 ) & 0xFF ;
V_53:
F_5 () ;
return V_51 ;
}
static int F_66 ( struct V_123 * V_124 )
{
int V_51 ;
F_3 () ;
V_5 -> V_54 [ 0 ] = 0x2 ;
V_5 -> V_54 [ 1 ] = F_18 ( V_124 -> V_127 ) & 0xFFFF ;
V_5 -> V_54 [ 1 ] |= ( V_124 -> V_116 & 0xFF ) << 16 ;
V_5 -> V_54 [ 1 ] |= ( V_124 -> V_131 & 0x3F ) << 24 ;
V_5 -> V_54 [ 1 ] |= ( V_124 -> V_132 & 0x3 ) << 30 ;
V_5 -> V_54 [ 2 ] = V_124 -> V_133 & 0xFF ;
V_5 -> V_54 [ 2 ] |= ( V_124 -> V_125 & 0xFF ) << 16 ;
F_13 ( V_5 , 4 , 11 ) ;
V_51 = V_5 -> V_52 [ 0 ] ;
F_5 () ;
return F_16 ( V_51 ) ;
}
static int F_67 ( struct V_123 * V_124 , struct V_123 * V_135 )
{
int V_51 ;
V_51 = F_66 ( V_124 ) ;
if ( V_51 == 0 )
return 0 ;
if ( F_66 ( V_135 ) )
F_68 ( L_42 ) ;
return V_51 ;
}
static int F_69 ( T_2 V_136 )
{
int V_28 ;
int V_51 ;
if ( V_136 >= F_70 ( V_137 ) )
return - V_43 ;
V_28 = F_11 ( V_137 [ V_136 ] ) ;
if ( V_28 == - 1 )
return - V_43 ;
F_3 () ;
V_5 -> V_54 [ 0 ] = V_21 [ V_28 ] . V_29 ;
V_5 -> V_54 [ 1 ] = V_21 [ V_28 ] . V_40 ;
F_13 ( V_5 , 1 , 0 ) ;
V_51 = V_5 -> V_52 [ 0 ] ;
F_5 () ;
return F_16 ( V_51 ) ;
}
static int F_71 ( T_2 V_136 )
{
int V_28 ;
int V_51 ;
int V_138 ;
if ( V_136 >= F_70 ( V_137 ) )
return - V_43 ;
V_28 = F_11 ( V_137 [ V_136 ] ) ;
if ( V_28 == - 1 )
return - V_43 ;
F_3 () ;
V_5 -> V_54 [ 0 ] = V_21 [ V_28 ] . V_29 ;
F_13 ( V_5 , 0 , 0 ) ;
V_51 = V_5 -> V_52 [ 0 ] ;
V_138 = V_5 -> V_52 [ 1 ] ;
F_5 () ;
if ( V_51 )
return F_16 ( V_51 ) ;
return ( V_138 == V_21 [ V_28 ] . V_40 ) ;
}
static int F_72 ( void )
{
int V_26 ;
int V_51 ;
for ( V_26 = 0 ; V_26 < F_70 ( V_137 ) ; ++ V_26 ) {
V_51 = F_71 ( V_26 ) ;
if ( V_51 == 1 )
return V_26 ;
}
return V_51 ;
}
static int F_73 ( void )
{
return F_74 ( V_139 ) ;
}
static inline int F_75 ( void )
{
struct V_123 V_124 ;
int V_51 ;
int V_26 ;
V_51 = F_60 ( & V_112 ) ;
if ( V_51 )
return V_51 ;
F_64 ( & V_124 ) ;
if ( V_112 . V_118 > 63 )
V_112 . V_118 = 63 ;
if ( V_112 . V_119 > 63 )
V_112 . V_119 = 63 ;
if ( V_112 . V_120 > 63 )
V_112 . V_120 = 63 ;
if ( V_112 . V_121 > 63 )
V_112 . V_121 = 63 ;
V_112 . V_115 &= ~ F_18 ( V_140 ) ;
V_128 = F_62 ( & V_124 ) ;
V_130 = V_124 . V_127 ;
if ( V_128 == 0 && F_61 () != 0 )
V_128 = 1 ;
if ( V_130 == V_129 ) {
V_130 =
F_65 ( V_112 . V_115 & ~ F_18 ( V_129 ) ) ;
if ( V_130 != 0 )
V_130 -- ;
}
if ( V_112 . V_115 & ( F_18 ( V_141 ) |
F_18 ( V_142 ) ) )
V_143 = true ;
if ( V_112 . V_115 & (
F_18 ( V_142 ) | F_18 ( V_144 ) |
F_18 ( V_145 ) | F_18 ( V_146 ) |
F_18 ( V_147 ) | F_18 ( V_148 )
) )
V_149 = true ;
for ( V_26 = 0 ; V_26 < 16 ; ++ V_26 )
if ( F_76 ( V_26 ) && ( F_18 ( V_26 ) & V_112 . V_115 ) )
V_126 [ 1 + V_122 ++ ] = V_26 ;
if ( V_122 > 0 ) {
for ( V_26 = 0 ; V_26 < 16 ; ++ V_26 ) {
if ( F_18 ( V_26 ) & V_112 . V_115 ) {
V_126 [ 0 ] = V_26 ;
break;
}
}
V_122 ++ ;
}
return 0 ;
}
static inline void F_77 ( void )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < F_70 ( V_137 ) ; ++ V_26 )
if ( F_11 ( V_137 [ V_26 ] ) != - 1 )
V_139 |= F_18 ( V_26 ) ;
}
static void F_78 ( void )
{
int V_51 ;
V_51 = F_75 () ;
F_77 () ;
if ( V_139 != 0 || V_51 == 0 )
V_150 = true ;
}
static T_3 F_79 ( struct V_110 * V_85 ,
struct V_151 * V_152 ,
const char * V_153 , T_4 V_154 )
{
struct V_123 V_155 ;
struct V_123 V_124 ;
bool V_156 ;
int V_40 ;
int V_51 ;
char V_157 ;
T_2 V_158 ;
int V_26 ;
V_51 = sscanf ( V_153 , L_43 , & V_40 , & V_157 ) ;
if ( V_51 < 1 )
return - V_43 ;
else if ( V_51 == 1 )
V_157 = 's' ;
if ( V_40 < 0 )
return - V_43 ;
V_156 = false ;
switch ( V_157 ) {
case 's' :
if ( V_40 > V_112 . V_118 )
V_156 = true ;
V_158 = V_159 ;
break;
case 'm' :
if ( V_40 > V_112 . V_119 )
V_156 = true ;
V_158 = V_160 ;
break;
case 'h' :
if ( V_40 > V_112 . V_120 )
V_156 = true ;
V_158 = V_161 ;
break;
case 'd' :
if ( V_40 > V_112 . V_121 )
V_156 = true ;
V_158 = V_162 ;
break;
default:
return - V_43 ;
}
if ( V_3 && V_3 -> V_163 )
V_156 = true ;
if ( V_156 ) {
switch ( V_158 ) {
case V_162 :
V_40 *= 24 ;
case V_161 :
V_40 *= 60 ;
case V_160 :
V_40 *= 60 ;
V_158 = V_159 ;
}
if ( V_3 && V_3 -> V_163 ) {
for ( V_26 = 0 ; V_3 -> V_164 [ V_26 ] != - 1 ; V_26 ++ ) {
if ( V_40 <= V_3 -> V_164 [ V_26 ] ) {
V_40 = V_3 -> V_164 [ V_26 ] ;
break;
}
}
}
if ( V_40 <= V_112 . V_118 && V_112 . V_118 ) {
V_158 = V_159 ;
} else if ( V_40 / 60 <= V_112 . V_119 && V_112 . V_119 ) {
V_40 /= 60 ;
V_158 = V_160 ;
} else if ( V_40 / ( 60 * 60 ) <= V_112 . V_120 && V_112 . V_120 ) {
V_40 /= ( 60 * 60 ) ;
V_158 = V_161 ;
} else if ( V_40 / ( 60 * 60 * 24 ) <= V_112 . V_121 && V_112 . V_121 ) {
V_40 /= ( 60 * 60 * 24 ) ;
V_158 = V_162 ;
} else {
return - V_43 ;
}
}
V_51 = F_64 ( & V_124 ) ;
if ( V_51 )
return V_51 ;
V_155 = V_124 ;
V_155 . V_131 = V_40 ;
V_155 . V_132 = V_158 ;
V_51 = F_67 ( & V_155 , & V_124 ) ;
if ( V_51 )
return V_51 ;
return V_154 ;
}
static T_3 F_80 ( struct V_110 * V_85 ,
struct V_151 * V_152 , char * V_153 )
{
struct V_123 V_124 ;
int V_51 ;
int V_165 ;
V_51 = F_64 ( & V_124 ) ;
if ( V_51 )
return V_51 ;
V_165 = sprintf ( V_153 , L_44 , V_124 . V_131 ) ;
switch ( V_124 . V_132 ) {
case V_159 :
return V_165 + sprintf ( V_153 + V_165 , L_45 ) ;
case V_160 :
return V_165 + sprintf ( V_153 + V_165 , L_46 ) ;
case V_161 :
return V_165 + sprintf ( V_153 + V_165 , L_47 ) ;
case V_162 :
return V_165 + sprintf ( V_153 + V_165 , L_48 ) ;
default:
return - V_43 ;
}
return V_165 ;
}
static T_3 F_81 ( struct V_110 * V_85 ,
struct V_151 * V_152 ,
const char * V_153 , T_4 V_154 )
{
struct V_123 V_155 ;
struct V_123 V_124 ;
bool V_166 = false ;
int V_167 = - 1 ;
char V_168 [ 21 ] ;
int V_26 , V_51 ;
V_51 = sscanf ( V_153 , L_49 , V_168 ) ;
if ( V_51 != 1 )
return - V_43 ;
if ( V_168 [ 0 ] != '+' && V_168 [ 0 ] != '-' )
return - V_43 ;
V_51 = F_64 ( & V_124 ) ;
if ( V_51 )
return V_51 ;
if ( V_149 )
V_166 = F_82 ( V_124 . V_127 ) ;
if ( V_149 ) {
for ( V_26 = 0 ; V_26 < F_70 ( V_169 ) ; ++ V_26 ) {
if ( ! ( V_112 . V_116 & F_18 ( V_26 ) ) )
continue;
if ( ! V_169 [ V_26 ] )
continue;
if ( strcmp ( V_168 + 1 , V_169 [ V_26 ] ) != 0 )
continue;
if ( V_168 [ 0 ] == '+' &&
V_166 && ( V_124 . V_116 & F_18 ( V_26 ) ) )
return V_154 ;
if ( V_168 [ 0 ] == '-' &&
( ! V_166 || ! ( V_124 . V_116 & F_18 ( V_26 ) ) ) )
return V_154 ;
V_167 = V_26 ;
break;
}
}
if ( V_167 != - 1 ) {
V_155 = V_124 ;
if ( V_168 [ 0 ] == '+' )
V_155 . V_116 |= F_18 ( V_167 ) ;
else {
V_155 . V_116 &= ~ F_18 ( V_167 ) ;
if ( V_167 == 1 )
V_155 . V_116 &= ~ F_18 ( 2 ) ;
}
if ( ( V_112 . V_116 & V_155 . V_116 ) !=
V_155 . V_116 )
return - V_43 ;
if ( V_155 . V_116 && ! V_166 ) {
V_155 . V_127 = V_144 ;
F_63 ( & V_155 , V_128 ) ;
} else if ( V_155 . V_116 == 0 ) {
F_63 ( & V_155 , 0 ) ;
}
if ( ! ( V_112 . V_115 & F_18 ( V_155 . V_127 ) ) )
return - V_43 ;
V_51 = F_67 ( & V_155 , & V_124 ) ;
if ( V_51 )
return V_51 ;
if ( V_155 . V_127 != V_129 )
V_130 = V_155 . V_127 ;
return V_154 ;
}
return - V_43 ;
}
static T_3 F_83 ( struct V_110 * V_85 ,
struct V_151 * V_152 , char * V_153 )
{
struct V_123 V_124 ;
bool V_166 ;
int V_125 , V_26 , V_51 ;
int V_165 = 0 ;
V_51 = F_64 ( & V_124 ) ;
if ( V_51 )
return V_51 ;
V_165 = 0 ;
if ( V_149 ) {
V_166 = F_82 ( V_124 . V_127 ) ;
V_125 = F_62 ( & V_124 ) ;
for ( V_26 = 0 ; V_26 < F_70 ( V_169 ) ; ++ V_26 ) {
if ( ! ( V_112 . V_116 & F_18 ( V_26 ) ) )
continue;
if ( ! V_169 [ V_26 ] )
continue;
if ( ( V_166 || V_125 <= 0 ) &&
( V_124 . V_116 & F_18 ( V_26 ) ) )
V_153 [ V_165 ++ ] = '+' ;
else
V_153 [ V_165 ++ ] = '-' ;
V_165 += sprintf ( V_153 + V_165 , L_50 , V_169 [ V_26 ] ) ;
}
}
if ( V_165 )
V_153 [ V_165 - 1 ] = '\n' ;
return V_165 ;
}
static T_3 F_84 ( struct V_110 * V_85 ,
struct V_151 * V_152 ,
const char * V_153 , T_4 V_154 )
{
struct V_123 V_155 ;
struct V_123 V_124 ;
bool V_166 = false ;
int V_170 ;
int V_51 ;
V_51 = F_85 ( V_153 , 0 , & V_170 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_64 ( & V_124 ) ;
if ( V_51 )
return V_51 ;
if ( V_170 == F_86 ( V_124 . V_127 ) )
return V_154 ;
V_155 = V_124 ;
if ( V_149 )
V_166 = F_82 ( V_124 . V_127 ) ;
if ( V_170 ) {
if ( V_166 )
V_155 . V_127 = V_142 ;
else
V_155 . V_127 = V_141 ;
} else {
if ( V_166 ) {
V_155 . V_127 = V_144 ;
F_63 ( & V_155 , V_128 ) ;
} else {
V_155 . V_127 = V_140 ;
}
}
if ( ! ( V_112 . V_115 & F_18 ( V_155 . V_127 ) ) )
return - V_43 ;
V_51 = F_67 ( & V_155 , & V_124 ) ;
if ( V_51 )
return V_51 ;
V_130 = V_155 . V_127 ;
return V_154 ;
}
static T_3 F_87 ( struct V_110 * V_85 ,
struct V_151 * V_152 ,
char * V_153 )
{
struct V_123 V_124 ;
bool V_171 = false ;
int V_51 ;
V_51 = F_64 ( & V_124 ) ;
if ( V_51 )
return V_51 ;
V_171 = F_86 ( V_124 . V_127 ) ;
return sprintf ( V_153 , L_51 , V_171 ? 1 : 0 ) ;
}
static T_3 F_88 ( struct V_110 * V_85 ,
struct V_151 * V_152 ,
const char * V_153 , T_4 V_154 )
{
struct V_123 V_124 ;
struct V_123 V_155 ;
T_2 V_172 ;
int V_51 ;
V_51 = F_89 ( V_153 , 10 , & V_172 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_64 ( & V_124 ) ;
if ( V_51 )
return V_51 ;
V_155 = V_124 ;
V_155 . V_133 = V_172 ;
V_51 = F_67 ( & V_155 , & V_124 ) ;
if ( V_51 )
return V_51 ;
return V_154 ;
}
static T_3 F_90 ( struct V_110 * V_85 ,
struct V_151 * V_152 ,
char * V_153 )
{
struct V_123 V_124 ;
int V_51 ;
V_51 = F_64 ( & V_124 ) ;
if ( V_51 )
return V_51 ;
return sprintf ( V_153 , L_51 , V_124 . V_133 ) ;
}
static enum V_109 F_91 ( struct V_107 * V_108 )
{
int V_51 ;
T_5 V_173 ;
struct V_123 V_124 ;
if ( F_61 () ) {
V_51 = F_64 ( & V_124 ) ;
if ( V_51 )
return 0 ;
V_51 = F_62 ( & V_124 ) ;
if ( V_51 < 0 )
return 0 ;
return V_51 ;
}
if ( F_73 () ) {
V_51 = F_72 () ;
if ( V_51 < 0 )
return 0 ;
for ( V_173 = V_139 ; V_173 != 0 && V_51 > 0 ; -- V_51 )
V_173 &= V_173 - 1 ;
if ( V_173 == 0 )
return 0 ;
return F_65 ( V_173 ) - 1 ;
}
F_42 ( L_52 ) ;
return 0 ;
}
static void F_92 ( struct V_107 * V_108 ,
enum V_109 V_40 )
{
struct V_123 V_124 ;
struct V_123 V_155 ;
T_5 V_173 ;
if ( F_61 () ) {
if ( F_64 ( & V_124 ) )
return;
V_155 = V_124 ;
if ( F_63 ( & V_155 , V_40 ) )
return;
F_67 ( & V_155 , & V_124 ) ;
return;
}
if ( F_73 () ) {
for ( V_173 = V_139 ; V_173 != 0 && V_40 > 0 ; -- V_40 )
V_173 &= V_173 - 1 ;
if ( V_173 == 0 )
return;
F_69 ( F_65 ( V_173 ) - 1 ) ;
return;
}
F_42 ( L_52 ) ;
}
static int T_1 F_93 ( struct V_110 * V_85 )
{
F_78 () ;
if ( ! V_150 )
return - V_99 ;
if ( ! V_143 )
V_174 [ 1 ] = NULL ;
V_175 . V_176 = F_61 () ;
if ( ! V_175 . V_176 ) {
V_175 . V_176 = F_73 () ;
if ( V_175 . V_176 )
V_175 . V_176 -- ;
}
return F_57 ( V_85 , & V_175 ) ;
}
static void F_94 ( struct V_107 * V_108 ,
enum V_109 V_40 )
{
}
static void F_95 ( void )
{
if ( ! V_150 )
return;
V_175 . V_177 = F_94 ;
F_59 ( & V_175 ) ;
}
static int T_1 F_96 ( void )
{
int V_178 = 0 ;
int V_103 ;
int V_51 ;
if ( ! F_97 ( V_179 ) )
return - V_99 ;
V_3 = NULL ;
F_97 ( V_180 ) ;
F_98 ( F_10 , NULL ) ;
if ( ! V_21 ) {
F_41 ( L_53 ) ;
return - V_99 ;
}
V_51 = F_99 ( & V_181 ) ;
if ( V_51 )
goto V_182;
V_84 = F_100 ( L_54 , - 1 ) ;
if ( ! V_84 ) {
V_51 = - V_88 ;
goto V_183;
}
V_51 = F_101 ( V_84 ) ;
if ( V_51 )
goto V_184;
V_5 = ( void * ) F_102 ( V_23 | V_185 ) ;
if ( ! V_5 ) {
V_51 = - V_88 ;
goto V_186;
}
V_51 = F_35 () ;
if ( V_51 ) {
F_42 ( L_55 ) ;
goto V_187;
}
if ( V_3 && V_3 -> V_111 )
F_56 ( & V_84 -> V_85 ) ;
F_93 ( & V_84 -> V_85 ) ;
V_188 = F_103 ( L_56 , NULL ) ;
if ( V_188 != NULL )
F_104 ( L_57 , 0444 , V_188 , NULL ,
& V_189 ) ;
if ( F_105 () != V_190 )
return 0 ;
V_103 = F_12 ( V_104 ) ;
if ( V_103 != - 1 ) {
F_3 () ;
V_5 -> V_54 [ 0 ] = V_103 ;
F_13 ( V_5 , 0 , 2 ) ;
if ( V_5 -> V_52 [ 0 ] == 0 )
V_178 = V_5 -> V_52 [ 3 ] ;
F_5 () ;
}
if ( V_178 ) {
struct V_191 V_105 ;
memset ( & V_105 , 0 , sizeof( struct V_191 ) ) ;
V_105 . type = V_192 ;
V_105 . V_176 = V_178 ;
V_193 = F_106 ( L_58 ,
& V_84 -> V_85 ,
NULL ,
& V_194 ,
& V_105 ) ;
if ( F_107 ( V_193 ) ) {
V_51 = F_108 ( V_193 ) ;
V_193 = NULL ;
goto V_195;
}
V_193 -> V_105 . V_106 =
F_51 ( V_193 ) ;
F_109 ( V_193 ) ;
}
return 0 ;
V_195:
F_46 () ;
V_187:
F_110 ( ( unsigned long ) V_5 ) ;
V_186:
F_111 ( V_84 ) ;
V_184:
F_112 ( V_84 ) ;
V_183:
F_113 ( & V_181 ) ;
V_182:
F_114 ( V_21 ) ;
return V_51 ;
}
static void T_6 F_115 ( void )
{
F_116 ( V_188 ) ;
if ( V_3 && V_3 -> V_111 )
F_58 () ;
F_95 () ;
F_117 ( V_193 ) ;
F_46 () ;
if ( V_84 ) {
F_118 ( V_84 ) ;
F_113 ( & V_181 ) ;
}
F_114 ( V_21 ) ;
F_110 ( ( unsigned long ) V_5 ) ;
}
