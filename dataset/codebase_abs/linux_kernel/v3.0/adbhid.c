static void
F_1 ( unsigned char * V_1 , int V_2 , int V_3 )
{
int V_4 = ( V_1 [ 0 ] >> 4 ) & 0x0f ;
if ( ! V_5 [ V_4 ] ) {
F_2 ( V_6 L_1 ,
V_4 , V_1 [ 0 ] , V_1 [ 1 ] , V_1 [ 2 ] , V_1 [ 3 ] ) ;
return;
}
if ( V_2 != 3 || ( V_1 [ 0 ] & 3 ) != V_7 )
return;
F_3 ( V_4 , V_1 [ 1 ] , 0 ) ;
if ( ! ( V_1 [ 2 ] == 0xff || ( V_1 [ 2 ] == 0x7f && V_1 [ 1 ] == 0x7f ) ) )
F_3 ( V_4 , V_1 [ 2 ] , 0 ) ;
}
static void
F_3 ( int V_4 , int V_8 , int V_9 )
{
struct V_5 * V_10 = V_5 [ V_4 ] ;
int V_11 , V_12 , V_13 ;
V_11 = V_8 & 0x7f ;
V_12 = V_8 & 0x80 ;
if ( V_14 ) {
if ( V_11 == V_15 && ! V_12 ) {
if ( V_10 -> V_16 & V_17 ) {
V_10 -> V_16 &= ~ V_17 ;
return;
} else {
V_10 -> V_16 |= V_18
| V_19 ;
}
} else if ( V_8 == 0xff &&
! ( V_10 -> V_16 & V_20 ) ) {
if ( V_10 -> V_16 & V_18 ) {
V_11 = V_15 ;
if ( V_10 -> V_16 & V_19 ) {
V_12 = 1 ;
V_10 -> V_16 &= ~ V_19 ;
} else {
V_12 = 0 ;
V_10 -> V_16 &= ~ V_18 ;
}
} else {
F_2 ( V_21 L_2
L_3 ) ;
}
}
}
switch ( V_11 ) {
case V_15 :
if ( ! V_14 ) {
F_4 ( V_10 -> V_22 , V_23 , 1 ) ;
F_5 ( V_10 -> V_22 ) ;
F_4 ( V_10 -> V_22 , V_23 , 0 ) ;
F_5 ( V_10 -> V_22 ) ;
return;
}
break;
#ifdef F_6
case V_24 :
switch( F_7 ( V_25 ,
NULL , V_26 , 0 ) ) {
case V_27 :
case V_28 :
case V_29 :
V_11 = V_30 ;
}
break;
case V_30 :
if ( V_12 )
V_10 -> V_16 &= ~ V_20 ;
else
V_10 -> V_16 |= V_20 ;
if ( V_10 -> V_16 & V_31 ) {
V_11 = V_32 ;
if ( V_12 )
V_10 -> V_16 &= ~ V_33 ;
else
V_10 -> V_16 |= V_33 ;
} else if ( V_10 -> V_16 & V_33 ) {
V_11 = V_32 ;
V_10 -> V_16 &= ~ V_33 ;
}
break;
case V_34 :
if ( V_12 ) {
V_10 -> V_16 &= ~ V_31 ;
if ( V_10 -> V_16 & V_35 ) {
V_10 -> V_16 &= ~ V_35 ;
V_11 = V_36 ;
break;
}
} else
V_10 -> V_16 |= V_31 ;
break;
case V_37 :
if ( V_10 -> V_16 & V_31 ) {
V_11 = V_36 ;
if ( V_12 )
V_10 -> V_16 &= ~ V_35 ;
else
V_10 -> V_16 |= V_35 ;
}
break;
#endif
}
V_13 = V_5 [ V_4 ] -> V_11 [ V_11 ] ;
if ( V_13 ) {
F_4 ( V_5 [ V_4 ] -> V_22 , V_13 , ! V_12 ) ;
F_5 ( V_5 [ V_4 ] -> V_22 ) ;
} else
F_2 ( V_21 L_4 , V_11 ,
V_12 ? L_5 : L_6 ) ;
}
static void
F_8 ( unsigned char * V_1 , int V_2 , int V_38 )
{
int V_4 = ( V_1 [ 0 ] >> 4 ) & 0x0f ;
if ( ! V_5 [ V_4 ] ) {
F_2 ( V_6 L_7 , V_4 ) ;
return;
}
switch ( V_5 [ V_4 ] -> V_39 )
{
case V_40 :
V_1 [ 1 ] = ( V_1 [ 1 ] & 0x7f ) | ( ( V_1 [ 1 ] & V_1 [ 2 ] ) & 0x80 ) ;
V_1 [ 2 ] = V_1 [ 2 ] | 0x80 ;
break;
case V_41 :
V_1 [ 1 ] = ( V_1 [ 1 ] & 0x7f ) | ( ( V_1 [ 3 ] & 0x01 ) << 7 ) ;
V_1 [ 2 ] = ( V_1 [ 2 ] & 0x7f ) | ( ( V_1 [ 3 ] & 0x02 ) << 6 ) ;
V_1 [ 3 ] = ( V_1 [ 3 ] & 0x77 ) | ( ( V_1 [ 3 ] & 0x04 ) << 5 )
| ( V_1 [ 3 ] & 0x08 ) ;
break;
case V_42 :
V_1 [ 1 ] = ( V_1 [ 1 ] & 0x7f ) | ( ( ( V_1 [ 3 ] & 0x04 ) << 5 )
& ( ( V_1 [ 3 ] & 0x08 ) << 4 ) ) ;
V_1 [ 2 ] = ( V_1 [ 2 ] & 0x7f ) | ( ( V_1 [ 3 ] & 0x01 ) << 7 ) ;
V_1 [ 3 ] = ( V_1 [ 3 ] & 0x77 ) | ( ( V_1 [ 3 ] & 0x02 ) << 6 ) ;
break;
case V_43 :
V_1 [ 1 ] = ( V_1 [ 1 ] & 0x7f ) | ( ( V_1 [ 3 ] & 0x01 ) << 7 ) ;
V_1 [ 2 ] = ( V_1 [ 2 ] & 0x7f ) | ( ( V_1 [ 3 ] & 0x02 ) << 6 ) ;
V_1 [ 3 ] = ( ( V_1 [ 3 ] & 0x04 ) << 5 ) ;
break;
case V_44 :
V_1 [ 3 ] = ( V_1 [ 2 ] & 0x80 ) ? 0x80 : 0x00 ;
V_1 [ 2 ] |= 0x80 ;
V_2 = 4 ;
break;
}
F_4 ( V_5 [ V_4 ] -> V_22 , V_45 , ! ( ( V_1 [ 1 ] >> 7 ) & 1 ) ) ;
F_4 ( V_5 [ V_4 ] -> V_22 , V_46 , ! ( ( V_1 [ 2 ] >> 7 ) & 1 ) ) ;
if ( V_2 >= 4 && V_5 [ V_4 ] -> V_39 != V_40 )
F_4 ( V_5 [ V_4 ] -> V_22 , V_47 , ! ( ( V_1 [ 3 ] >> 7 ) & 1 ) ) ;
F_9 ( V_5 [ V_4 ] -> V_22 , V_48 ,
( ( V_1 [ 2 ] & 0x7f ) < 64 ? ( V_1 [ 2 ] & 0x7f ) : ( V_1 [ 2 ] & 0x7f ) - 128 ) ) ;
F_9 ( V_5 [ V_4 ] -> V_22 , V_49 ,
( ( V_1 [ 1 ] & 0x7f ) < 64 ? ( V_1 [ 1 ] & 0x7f ) : ( V_1 [ 1 ] & 0x7f ) - 128 ) ) ;
F_5 ( V_5 [ V_4 ] -> V_22 ) ;
}
static void
F_10 ( unsigned char * V_1 , int V_2 , int V_38 )
{
int V_4 = ( V_1 [ 0 ] >> 4 ) & 0x0f ;
if ( ! V_5 [ V_4 ] ) {
F_2 ( V_6 L_7 , V_4 ) ;
return;
}
switch ( V_5 [ V_4 ] -> V_50 ) {
default:
case 0x02 :
{
int V_51 = ( V_1 [ 1 ] == ( V_1 [ 1 ] & 0xf ) ) ;
switch ( V_1 [ 1 ] & 0x0f ) {
case 0x0 :
F_4 ( V_5 [ V_4 ] -> V_22 , V_52 , V_51 ) ;
break;
case 0x1 :
F_4 ( V_5 [ V_4 ] -> V_22 , V_53 , V_51 ) ;
break;
case 0x2 :
F_4 ( V_5 [ V_4 ] -> V_22 , V_54 , V_51 ) ;
break;
case 0x3 :
F_4 ( V_5 [ V_4 ] -> V_22 , V_55 , V_51 ) ;
break;
default:
F_2 ( V_21 L_8 ,
V_1 [ 0 ] , V_1 [ 1 ] , V_1 [ 2 ] , V_1 [ 3 ] ) ;
break;
}
}
break;
case 0x1f :
{
int V_51 = ( V_1 [ 1 ] == ( V_1 [ 1 ] & 0xf ) ) ;
switch ( V_1 [ 1 ] & 0x0f ) {
case 0x8 :
F_4 ( V_5 [ V_4 ] -> V_22 , V_53 , V_51 ) ;
break;
case 0x7 :
F_4 ( V_5 [ V_4 ] -> V_22 , V_54 , V_51 ) ;
break;
case 0x6 :
F_4 ( V_5 [ V_4 ] -> V_22 , V_55 , V_51 ) ;
break;
case 0xb :
F_4 ( V_5 [ V_4 ] -> V_22 , V_56 , V_51 ) ;
break;
case 0xa :
#ifdef F_11
if ( V_51 )
F_12 () ;
#endif
F_4 ( V_5 [ V_4 ] -> V_22 , V_57 , V_51 ) ;
break;
case 0x9 :
#ifdef F_11
if ( V_51 )
F_13 () ;
#endif
F_4 ( V_5 [ V_4 ] -> V_22 , V_58 , V_51 ) ;
break;
case 0xc :
F_4 ( V_5 [ V_4 ] -> V_22 , V_59 , V_51 ) ;
break;
case 0xd :
F_4 ( V_5 [ V_4 ] -> V_22 , V_60 , V_51 ) ;
break;
case 0xe :
F_4 ( V_5 [ V_4 ] -> V_22 , V_61 , V_51 ) ;
break;
case 0xf :
switch ( V_1 [ 1 ] ) {
case 0x8f :
case 0x0f :
F_4 ( V_5 [ V_4 ] -> V_22 , V_62 , V_51 ) ;
break;
case 0x7f :
case 0xff :
break;
default:
F_2 ( V_21 L_8 ,
V_1 [ 0 ] , V_1 [ 1 ] , V_1 [ 2 ] , V_1 [ 3 ] ) ;
break;
}
break;
default:
F_2 ( V_21 L_8 ,
V_1 [ 0 ] , V_1 [ 1 ] , V_1 [ 2 ] , V_1 [ 3 ] ) ;
break;
}
}
break;
}
F_5 ( V_5 [ V_4 ] -> V_22 ) ;
}
static void F_14 ( struct V_63 * V_64 )
{
int V_65 = 0 , V_66 = 0 , V_67 = 0 ;
unsigned long V_16 ;
F_15 ( & V_68 , V_16 ) ;
if ( V_69 != V_70 ) {
V_66 = V_71 [ V_69 ] ;
V_65 = V_72 [ V_66 ] & 0xff ;
V_72 [ V_66 ] = 0 ;
V_69 ++ ;
V_69 = ( V_69 < 16 ) ? V_69 : 0 ;
V_67 = V_73 ;
} else
V_73 = 0 ;
F_16 ( & V_68 , V_16 ) ;
if ( V_67 )
V_63 ( & V_74 , F_14 , 0 , 3 ,
F_17 ( V_66 , V_75 ) , 0xff , ~ V_65 ) ;
}
static void F_18 ( unsigned char V_65 , int V_66 )
{
unsigned long V_16 ;
F_15 ( & V_68 , V_16 ) ;
if ( ! V_73 ) {
V_73 = 1 ;
F_16 ( & V_68 , V_16 ) ;
V_63 ( & V_74 , F_14 , 0 , 3 ,
F_17 ( V_66 , V_75 ) , 0xff , ~ V_65 ) ;
return;
} else {
if ( ! ( V_72 [ V_66 ] & 0x100 ) ) {
V_71 [ V_70 ] = V_66 ;
V_70 ++ ;
V_70 = ( V_70 < 16 ) ? V_70 : 0 ;
}
V_72 [ V_66 ] = V_65 | 0x100 ;
}
F_16 ( & V_68 , V_16 ) ;
}
static int F_19 ( struct V_76 * V_77 , unsigned int type , unsigned int V_78 , int V_79 )
{
struct V_5 * V_5 = F_20 ( V_77 ) ;
unsigned char V_65 ;
switch ( type ) {
case V_80 :
V_65 = ( F_21 ( V_81 , V_77 -> V_82 ) ? 4 : 0 ) |
( F_21 ( V_83 , V_77 -> V_82 ) ? 1 : 0 ) |
( F_21 ( V_84 , V_77 -> V_82 ) ? 2 : 0 ) ;
F_18 ( V_65 , V_5 -> V_4 ) ;
return 0 ;
}
return - 1 ;
}
static void
F_22 ( void )
{
struct V_5 * V_10 ;
int V_85 ;
for ( V_85 = 1 ; V_85 < 16 ; V_85 ++ ) {
V_10 = V_5 [ V_85 ] ;
if ( V_10 && V_10 -> V_4 == V_86 )
if ( V_10 -> V_16 & V_18 )
V_10 -> V_16 |= V_17 ;
}
}
static int
F_23 ( struct V_87 * V_88 , unsigned long V_78 , void * V_89 )
{
switch ( V_78 ) {
case V_90 :
case V_91 :
{
int V_85 ;
for ( V_85 = 1 ; V_85 < 16 ; V_85 ++ ) {
if ( V_5 [ V_85 ] )
F_24 ( & V_5 [ V_85 ] -> V_22 -> V_92 ) ;
}
}
while ( V_73 )
F_25 () ;
if ( V_14 )
F_22 () ;
break;
case V_93 :
F_26 () ;
break;
}
return V_94 ;
}
static int
F_27 ( int V_4 , int V_95 , int V_50 ,
int V_96 , int V_39 )
{
struct V_5 * V_97 ;
struct V_76 * V_76 ;
int V_98 ;
int V_85 ;
if ( V_5 [ V_4 ] ) {
F_2 ( V_6 L_9 , V_4 ) ;
return - V_99 ;
}
V_5 [ V_4 ] = V_97 = F_28 ( sizeof( struct V_5 ) , V_100 ) ;
V_76 = F_29 () ;
if ( ! V_97 || ! V_76 ) {
V_98 = - V_101 ;
goto V_102;
}
sprintf ( V_97 -> V_103 , L_10 , V_4 , V_95 , V_50 ) ;
V_97 -> V_22 = V_76 ;
V_97 -> V_4 = V_95 ;
V_97 -> V_50 = V_50 ;
V_97 -> V_96 = V_96 ;
V_97 -> V_39 = V_39 ;
V_97 -> V_16 = 0 ;
F_30 ( V_76 , V_97 ) ;
V_76 -> V_104 = V_97 -> V_104 ;
V_76 -> V_103 = V_97 -> V_103 ;
V_76 -> V_4 . V_105 = V_106 ;
V_76 -> V_4 . V_107 = 0x0001 ;
V_76 -> V_4 . V_108 = ( V_4 << 12 ) | ( V_95 << 8 ) | V_50 ;
V_76 -> V_4 . V_109 = 0x0100 ;
switch ( V_95 ) {
case V_86 :
V_97 -> V_11 = F_31 ( sizeof( V_110 ) , V_100 ) ;
if ( ! V_97 -> V_11 ) {
V_98 = - V_101 ;
goto V_102;
}
sprintf ( V_97 -> V_104 , L_11 ) ;
memcpy ( V_97 -> V_11 , V_110 , sizeof( V_110 ) ) ;
F_2 ( V_21 L_12 ) ;
switch ( V_50 ) {
default:
F_2 ( L_13 ) ;
V_76 -> V_4 . V_109 = V_111 ;
break;
case 0x01 : case 0x02 : case 0x03 : case 0x06 : case 0x08 :
case 0x0C : case 0x10 : case 0x18 : case 0x1B : case 0x1C :
case 0xC0 : case 0xC3 : case 0xC6 :
F_2 ( L_14 ) ;
V_76 -> V_4 . V_109 = V_112 ;
break;
case 0x04 : case 0x05 : case 0x07 : case 0x09 : case 0x0D :
case 0x11 : case 0x14 : case 0x19 : case 0x1D : case 0xC1 :
case 0xC4 : case 0xC7 :
F_2 ( L_15 ) ;
V_76 -> V_4 . V_109 = V_113 ;
V_85 = V_97 -> V_11 [ 10 ] ;
V_97 -> V_11 [ 10 ] = V_97 -> V_11 [ 50 ] ;
V_97 -> V_11 [ 50 ] = V_85 ;
break;
case 0x12 : case 0x15 : case 0x16 : case 0x17 : case 0x1A :
case 0x1E : case 0xC2 : case 0xC5 : case 0xC8 : case 0xC9 :
F_2 ( L_16 ) ;
V_76 -> V_4 . V_109 = V_114 ;
break;
}
for ( V_85 = 0 ; V_85 < 128 ; V_85 ++ )
if ( V_97 -> V_11 [ V_85 ] )
F_32 ( V_97 -> V_11 [ V_85 ] , V_76 -> V_115 ) ;
V_76 -> V_116 [ 0 ] = F_33 ( V_117 ) | F_33 ( V_80 ) |
F_33 ( V_118 ) ;
V_76 -> V_119 [ 0 ] = F_33 ( V_81 ) |
F_33 ( V_84 ) | F_33 ( V_83 ) ;
V_76 -> V_120 = F_19 ;
V_76 -> V_121 = V_122 ;
V_76 -> V_123 = sizeof( V_97 -> V_11 [ 0 ] ) ;
break;
case V_124 :
sprintf ( V_97 -> V_104 , L_17 ) ;
V_76 -> V_116 [ 0 ] = F_33 ( V_117 ) | F_33 ( V_125 ) ;
V_76 -> V_115 [ F_34 ( V_126 ) ] = F_33 ( V_45 ) |
F_33 ( V_46 ) | F_33 ( V_47 ) ;
V_76 -> V_127 [ 0 ] = F_33 ( V_48 ) | F_33 ( V_49 ) ;
break;
case V_128 :
switch ( V_50 ) {
case 0x02 :
sprintf ( V_97 -> V_104 , L_18 ) ;
V_76 -> V_116 [ 0 ] = F_33 ( V_117 ) |
F_33 ( V_118 ) ;
F_32 ( V_52 , V_76 -> V_115 ) ;
F_32 ( V_53 , V_76 -> V_115 ) ;
F_32 ( V_55 , V_76 -> V_115 ) ;
F_32 ( V_54 , V_76 -> V_115 ) ;
break;
case 0x1f :
sprintf ( V_97 -> V_104 , L_19 ) ;
V_76 -> V_116 [ 0 ] = F_33 ( V_117 ) |
F_33 ( V_118 ) ;
F_32 ( V_53 , V_76 -> V_115 ) ;
F_32 ( V_55 , V_76 -> V_115 ) ;
F_32 ( V_54 , V_76 -> V_115 ) ;
F_32 ( V_58 , V_76 -> V_115 ) ;
F_32 ( V_57 , V_76 -> V_115 ) ;
F_32 ( V_56 , V_76 -> V_115 ) ;
F_32 ( V_59 , V_76 -> V_115 ) ;
F_32 ( V_60 , V_76 -> V_115 ) ;
F_32 ( V_61 , V_76 -> V_115 ) ;
F_32 ( V_62 , V_76 -> V_115 ) ;
break;
}
if ( V_97 -> V_104 [ 0 ] )
break;
default:
F_2 ( V_21 L_20 ) ;
V_98 = - V_129 ;
goto V_102;
}
V_76 -> V_11 = V_97 -> V_11 ;
V_98 = F_35 ( V_76 ) ;
if ( V_98 )
goto V_102;
if ( V_95 == V_86 ) {
V_76 -> V_130 [ V_131 ] = 500 ;
V_76 -> V_130 [ V_132 ] = 66 ;
}
return 0 ;
V_102: F_36 ( V_76 ) ;
if ( V_97 ) {
F_37 ( V_97 -> V_11 ) ;
F_37 ( V_97 ) ;
}
V_5 [ V_4 ] = NULL ;
return V_98 ;
}
static void F_38 ( int V_4 )
{
F_39 ( V_5 [ V_4 ] -> V_22 ) ;
F_37 ( V_5 [ V_4 ] -> V_11 ) ;
F_37 ( V_5 [ V_4 ] ) ;
V_5 [ V_4 ] = NULL ;
}
static T_1
F_40 ( int V_4 , int V_95 , int V_133 ,
int V_134 , int V_135 )
{
if ( V_5 [ V_4 ] ) {
if ( V_5 [ V_4 ] -> V_22 -> V_4 . V_108 !=
( ( V_4 << 12 ) | ( V_95 << 8 ) | V_133 ) ) {
F_38 ( V_4 ) ;
F_27 ( V_4 , V_95 , V_133 ,
V_134 , V_135 ) ;
}
} else
F_27 ( V_4 , V_95 , V_133 ,
V_134 , V_135 ) ;
return 1 << V_4 ;
}
static void
F_41 ( T_1 V_136 )
{
int V_85 ;
for( V_85 = 1 ; V_85 < 16 ; V_85 ++ )
if ( V_5 [ V_85 ] && ! ( V_136 & ( 1 << V_85 ) ) )
F_38 ( V_85 ) ;
}
static void
F_26 ( void )
{
struct V_63 V_64 ;
int V_85 , V_95 , V_133 , V_134 ;
T_1 V_137 = 0 ;
F_42 ( V_124 , 0 , & V_138 , F_8 ) ;
F_42 ( V_86 , 0 , & V_139 , F_1 ) ;
F_42 ( V_128 , 0 , & V_140 , F_10 ) ;
for ( V_85 = 0 ; V_85 < V_139 . V_141 ; V_85 ++ ) {
int V_4 = V_139 . V_4 [ V_85 ] ;
F_43 ( V_4 , & V_95 , & V_133 ) ;
V_63 ( & V_64 , NULL , V_142 , 3 ,
F_17 ( V_4 , V_75 ) , 0xff , 0xff ) ;
#if 0
if (adb_try_handler_change(id, 5))
printk("ADB keyboard at %d, handler set to 5\n", id);
else
#endif
if ( F_44 ( V_4 , 3 ) )
F_2 ( L_21 , V_4 ) ;
else
F_2 ( L_22 , V_4 ) ;
F_43 ( V_4 , & V_95 , & V_134 ) ;
V_137 |= F_40 ( V_4 , V_95 , V_133 ,
V_134 , 0 ) ;
}
for ( V_85 = 0 ; V_85 < V_140 . V_141 ; V_85 ++ ) {
int V_4 = V_140 . V_4 [ V_85 ] ;
F_43 ( V_4 , & V_95 , & V_133 ) ;
V_137 |= F_40 ( V_4 , V_95 , V_133 ,
V_133 , 0 ) ;
}
for ( V_85 = 0 ; V_85 < V_138 . V_141 ; V_85 ++ ) {
int V_4 = V_138 . V_4 [ V_85 ] ;
int V_39 ;
F_43 ( V_4 , & V_95 , & V_133 ) ;
if ( F_44 ( V_4 , 4 ) ) {
F_2 ( L_23 , V_4 ) ;
V_39 = V_143 ;
}
else if ( F_44 ( V_4 , 0x2F ) ) {
F_2 ( L_24 , V_4 ) ;
V_39 = V_41 ;
}
else if ( F_44 ( V_4 , 0x42 ) ) {
F_2 ( L_25 , V_4 ) ;
V_39 = V_42 ;
}
else if ( F_44 ( V_4 , 0x66 ) ) {
F_2 ( L_26 , V_4 ) ;
V_39 = V_41 ;
}
else if ( F_44 ( V_4 , 0x5F ) ) {
F_2 ( L_27 , V_4 ) ;
V_39 = V_41 ;
}
else if ( F_44 ( V_4 , 3 ) ) {
F_2 ( L_28 , V_4 ) ;
V_39 = V_43 ;
}
else if ( F_44 ( V_4 , 2 ) ) {
F_2 ( L_29 , V_4 ) ;
V_39 = V_144 ;
}
else {
F_2 ( L_30 , V_4 ) ;
V_39 = V_145 ;
}
if ( ( V_39 == V_42 )
|| ( V_39 == V_41 ) ) {
F_45 ( V_4 ) ;
} else if ( V_39 == V_43 ) {
F_46 ( V_4 ) ;
} else if ( V_39 == V_143 ) {
V_63 ( & V_64 , NULL , V_142 | V_146 , 1 ,
F_47 ( V_4 , 1 ) ) ;
if ( ( V_64 . V_147 ) &&
( V_64 . V_148 [ 1 ] == 0x9a ) && ( ( V_64 . V_148 [ 2 ] == 0x21 )
|| ( V_64 . V_148 [ 2 ] == 0x20 ) ) ) {
V_39 = V_149 ;
F_48 ( V_4 ) ;
}
else if ( ( V_64 . V_147 >= 4 ) &&
( V_64 . V_148 [ 1 ] == 0x74 ) && ( V_64 . V_148 [ 2 ] == 0x70 ) &&
( V_64 . V_148 [ 3 ] == 0x61 ) && ( V_64 . V_148 [ 4 ] == 0x64 ) ) {
V_39 = V_40 ;
F_49 ( V_4 ) ;
}
else if ( ( V_64 . V_147 >= 4 ) &&
( V_64 . V_148 [ 1 ] == 0x4b ) && ( V_64 . V_148 [ 2 ] == 0x4d ) &&
( V_64 . V_148 [ 3 ] == 0x4c ) && ( V_64 . V_148 [ 4 ] == 0x31 ) ) {
V_39 = V_150 ;
F_50 ( V_4 ) ;
}
else if ( ( V_64 . V_147 == 9 ) &&
( V_64 . V_148 [ 1 ] == 0x4b ) && ( V_64 . V_148 [ 2 ] == 0x4f ) &&
( V_64 . V_148 [ 3 ] == 0x49 ) && ( V_64 . V_148 [ 4 ] == 0x54 ) ) {
if ( F_44 ( V_4 , 0x42 ) ) {
F_2 ( L_31 , V_4 ) ;
V_39 = V_44 ;
}
}
}
F_2 ( L_32 ) ;
F_43 ( V_4 , & V_95 , & V_134 ) ;
V_137 |= F_40 ( V_4 , V_95 , V_133 ,
V_134 , V_39 ) ;
}
F_41 ( V_137 ) ;
}
static void
F_49 ( int V_4 )
{
struct V_63 V_64 ;
unsigned char V_151 [ 8 ] ;
F_2 ( L_33 ) ;
V_63 ( & V_64 , NULL , V_142 | V_146 , 1 ,
F_47 ( V_4 , 1 ) ) ;
if ( V_64 . V_147 < 8 )
F_2 ( L_34 ) ;
else
{
memcpy ( V_151 , & V_64 . V_148 [ 1 ] , 8 ) ;
V_63 ( & V_64 , NULL , V_142 , 9 ,
F_17 ( V_4 , 1 ) ,
V_151 [ 0 ] ,
V_151 [ 1 ] ,
V_151 [ 2 ] ,
V_151 [ 3 ] ,
V_151 [ 4 ] ,
V_151 [ 5 ] ,
0x0d ,
V_151 [ 7 ] ) ;
V_63 ( & V_64 , NULL , V_142 , 9 ,
F_17 ( V_4 , 2 ) ,
0x99 ,
0x94 ,
0x19 ,
0xff ,
0xb2 ,
0x8a ,
0x1b ,
0x50 ) ;
V_63 ( & V_64 , NULL , V_142 , 9 ,
F_17 ( V_4 , 1 ) ,
V_151 [ 0 ] ,
V_151 [ 1 ] ,
V_151 [ 2 ] ,
V_151 [ 3 ] ,
V_151 [ 4 ] ,
V_151 [ 5 ] ,
0x03 ,
V_151 [ 7 ] ) ;
V_63 ( & V_64 , NULL , V_142 , 1 , F_51 ( V_4 ) ) ;
}
}
static void
F_48 ( int V_4 )
{
struct V_63 V_64 ;
F_2 ( L_35 ) ;
V_63 ( & V_64 , NULL , V_142 , 3 ,
F_17 ( V_4 , 1 ) , 00 , 0x81 ) ;
V_63 ( & V_64 , NULL , V_142 , 3 ,
F_17 ( V_4 , 1 ) , 01 , 0x81 ) ;
V_63 ( & V_64 , NULL , V_142 , 3 ,
F_17 ( V_4 , 1 ) , 02 , 0x81 ) ;
V_63 ( & V_64 , NULL , V_142 , 3 ,
F_17 ( V_4 , 1 ) , 03 , 0x38 ) ;
V_63 ( & V_64 , NULL , V_142 , 3 ,
F_17 ( V_4 , 1 ) , 00 , 0x81 ) ;
V_63 ( & V_64 , NULL , V_142 , 3 ,
F_17 ( V_4 , 1 ) , 01 , 0x81 ) ;
V_63 ( & V_64 , NULL , V_142 , 3 ,
F_17 ( V_4 , 1 ) , 02 , 0x81 ) ;
V_63 ( & V_64 , NULL , V_142 , 3 ,
F_17 ( V_4 , 1 ) , 03 , 0x38 ) ;
}
static void
F_50 ( int V_4 )
{
struct V_63 V_64 ;
F_2 ( L_36 ) ;
V_63 ( & V_64 , NULL , V_142 , 1 , F_51 ( V_4 ) ) ;
V_63 ( & V_64 , NULL , V_142 , 1 , F_51 ( 3 ) ) ;
V_63 ( & V_64 , NULL , V_142 , 9 ,
F_17 ( 3 , 2 ) ,
0xe7 ,
0x8c ,
0 ,
0 ,
0 ,
0xff ,
0xff ,
0x94 ) ;
V_63 ( & V_64 , NULL , V_142 , 1 , F_51 ( 3 ) ) ;
V_63 ( & V_64 , NULL , V_142 , 9 ,
F_17 ( 3 , 2 ) ,
0xa5 ,
0x14 ,
0 ,
0 ,
0x69 ,
0xff ,
0xff ,
0x27 ) ;
}
static void
F_45 ( int V_4 )
{
struct V_63 V_64 ;
F_2 ( L_37 ) ;
V_63 ( & V_64 , NULL , V_142 , 1 , F_51 ( V_4 ) ) ;
V_63 ( & V_64 , NULL , V_142 , 5 ,
F_17 ( V_4 , 1 ) ,
0x20 ,
0x00 ,
0x10 ,
0x07 ) ;
V_63 ( & V_64 , NULL , V_142 , 1 , F_51 ( V_4 ) ) ;
}
static void
F_46 ( int V_4 )
{
struct V_63 V_64 ;
F_2 ( L_38 ) ;
V_63 ( & V_64 , NULL , V_142 , 3 ,
F_17 ( V_4 , 0x2 ) ,
0x00 ,
0x07 ) ;
V_63 ( & V_64 , NULL , V_142 , 1 , F_51 ( V_4 ) ) ;
}
static int T_2 F_52 ( void )
{
#ifndef F_53
if ( ! F_54 ( V_152 ) && ! F_54 ( V_153 ) )
return 0 ;
#endif
V_74 . V_154 = 1 ;
F_26 () ;
F_55 ( & V_155 ,
& V_156 ) ;
return 0 ;
}
static void T_3 F_56 ( void )
{
}
