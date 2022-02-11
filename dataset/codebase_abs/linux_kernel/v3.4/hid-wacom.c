static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
union V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ,
struct V_7 , V_9 ) ;
int V_10 = V_11 [ V_8 -> V_12 ] ;
int V_13 = 0 ;
switch ( V_4 ) {
case V_14 :
V_6 -> V_15 = 1 ;
break;
case V_16 :
V_6 -> V_15 = V_17 ;
break;
case V_18 :
if ( V_10 == 0 )
V_6 -> V_15 = 100 ;
else
V_6 -> V_15 = V_10 ;
break;
default:
V_13 = - V_19 ;
break;
}
return V_13 ;
}
static int F_3 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
union V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 , struct V_7 , V_20 ) ;
int V_10 = V_11 [ V_8 -> V_12 ] ;
int V_13 = 0 ;
switch ( V_4 ) {
case V_14 :
case V_21 :
if ( V_10 == 0 )
V_6 -> V_15 = 1 ;
else
V_6 -> V_15 = 0 ;
break;
case V_16 :
V_6 -> V_15 = V_17 ;
break;
default:
V_13 = - V_19 ;
break;
}
return V_13 ;
}
static void F_4 ( struct V_22 * V_23 )
{
int V_13 ;
T_1 V_24 [ 2 ] ;
V_24 [ 0 ] = 0x03 ;
V_24 [ 1 ] = 0x20 ;
V_13 = V_23 -> V_25 ( V_23 , V_24 , 2 ,
V_26 ) ;
return;
}
static void F_5 ( struct V_22 * V_23 , T_2 V_27 )
{
struct V_7 * V_8 = F_6 ( V_23 ) ;
int V_28 , V_13 ;
char V_24 [ 2 ] ;
V_24 [ 0 ] = 0x03 ; V_24 [ 1 ] = 0x00 ;
V_28 = 3 ;
do {
V_13 = V_23 -> V_25 ( V_23 , V_24 , 2 ,
V_26 ) ;
} while ( V_13 < 0 && V_28 -- > 0 );
if ( V_13 >= 0 ) {
if ( V_27 == 0 )
V_24 [ 0 ] = 0x05 ;
else
V_24 [ 0 ] = 0x06 ;
V_24 [ 1 ] = 0x00 ;
V_28 = 3 ;
do {
V_13 = V_23 -> V_25 ( V_23 , V_24 , 2 ,
V_26 ) ;
} while ( V_13 < 0 && V_28 -- > 0 );
if ( V_13 >= 0 ) {
V_8 -> V_29 = V_27 ;
return;
}
}
F_7 ( V_23 , L_1 ,
V_24 [ 0 ] , V_13 ) ;
return;
}
static T_3 F_8 ( struct V_30 * V_31 ,
struct V_32
* V_33 , char * V_34 )
{
struct V_7 * V_8 = F_9 ( V_31 ) ;
return snprintf ( V_34 , V_35 , L_2 , V_8 -> V_29 ) ;
}
static T_3 F_10 ( struct V_30 * V_31 ,
struct V_32 * V_33 ,
const char * V_34 , T_4 V_36 )
{
struct V_22 * V_23 = F_2 ( V_31 , struct V_22 , V_31 ) ;
int V_37 ;
if ( sscanf ( V_34 , L_3 , & V_37 ) != 1 )
return - V_19 ;
if ( V_37 == 0 || V_37 == 1 ) {
F_5 ( V_23 , V_37 ) ;
return F_11 ( V_34 , V_35 ) ;
} else
return - V_19 ;
}
static int F_12 ( struct V_22 * V_23 ,
struct V_7 * V_8 ,
struct V_38 * V_39 , unsigned char * V_40 )
{
int V_41 , V_42 , V_43 , V_44 ;
V_41 = 0 ;
V_42 = F_13 ( * ( V_45 * ) & V_40 [ 2 ] ) ;
V_43 = F_13 ( * ( V_45 * ) & V_40 [ 4 ] ) ;
if ( V_40 [ 1 ] & 0x90 ) {
switch ( ( V_40 [ 1 ] >> 5 ) & 3 ) {
case 0 :
V_41 = V_46 ;
break;
case 1 :
V_41 = V_47 ;
break;
case 2 :
case 3 :
V_41 = V_48 ;
break;
}
if ( ! ( V_40 [ 1 ] & 0x10 ) )
V_41 = 0 ;
}
if ( V_8 -> V_41 != V_41 ) {
if ( V_8 -> V_41 ) {
if ( V_8 -> V_41 == V_48 ) {
F_14 ( V_39 , V_49 , 0 ) ;
F_14 ( V_39 , V_50 , 0 ) ;
F_14 ( V_39 , V_51 , 0 ) ;
F_15 ( V_39 , V_52 ,
F_16 ( V_39 , V_52 ) ) ;
} else {
F_14 ( V_39 , V_53 , 0 ) ;
F_14 ( V_39 , V_54 , 0 ) ;
F_14 ( V_39 , V_55 , 0 ) ;
F_15 ( V_39 , V_56 , 0 ) ;
}
F_14 ( V_39 , V_8 -> V_41 , 0 ) ;
F_17 ( V_39 ) ;
}
V_8 -> V_41 = V_41 ;
if ( V_41 )
F_14 ( V_39 , V_41 , 1 ) ;
}
if ( V_41 ) {
F_15 ( V_39 , V_57 , V_42 ) ;
F_15 ( V_39 , V_58 , V_43 ) ;
switch ( ( V_40 [ 1 ] >> 5 ) & 3 ) {
case 2 :
F_14 ( V_39 , V_51 , V_40 [ 1 ] & 0x04 ) ;
V_44 = ( V_40 [ 6 ] & 0x01 ) ? - 1 :
( V_40 [ 6 ] & 0x02 ) ? 1 : 0 ;
F_18 ( V_39 , V_59 , V_44 ) ;
case 3 :
F_14 ( V_39 , V_49 , V_40 [ 1 ] & 0x01 ) ;
F_14 ( V_39 , V_50 , V_40 [ 1 ] & 0x02 ) ;
V_44 = 44 - ( V_40 [ 6 ] >> 2 ) ;
if ( V_44 < 0 )
V_44 = 0 ;
else if ( V_44 > 31 )
V_44 = 31 ;
F_15 ( V_39 , V_52 , V_44 ) ;
break;
default:
F_15 ( V_39 , V_56 ,
V_40 [ 6 ] | ( ( ( V_60 ) ( V_40 [ 1 ] & 0x08 ) ) << 5 ) ) ;
F_14 ( V_39 , V_53 , V_40 [ 1 ] & 0x01 ) ;
F_14 ( V_39 , V_54 , V_40 [ 1 ] & 0x02 ) ;
F_14 ( V_39 , V_55 , ( V_41 == V_46 ) && V_40 [ 1 ] & 0x04 ) ;
break;
}
F_17 ( V_39 ) ;
}
V_44 = V_40 [ 7 ] & 0x03 ;
if ( V_44 != V_8 -> V_61 ) {
V_8 -> V_61 = V_44 ;
F_14 ( V_39 , V_62 , V_44 & 0x02 ) ;
F_14 ( V_39 , V_63 , V_44 & 0x01 ) ;
F_14 ( V_39 , V_64 , 0xf0 ) ;
F_19 ( V_39 , V_65 , V_66 , 0xf0 ) ;
F_17 ( V_39 ) ;
}
#ifdef F_20
V_44 = ( V_40 [ 7 ] >> 2 & 0x07 ) ;
if ( V_44 != V_8 -> V_12 )
V_8 -> V_12 = V_44 ;
#endif
return 1 ;
}
static void F_21 ( struct V_7 * V_8 ,
struct V_38 * V_39 , unsigned char * V_40 )
{
V_60 V_67 ;
T_1 V_68 ;
T_1 V_69 = 0 ;
V_68 = V_40 [ 1 ] ;
if ( V_68 != V_8 -> V_70 ) {
V_8 -> V_70 = V_68 ;
if ( V_68 & 0x80 ) {
F_14 ( V_39 , V_53 , 1 ) ;
F_15 ( V_39 , V_71 , ( V_68 & 0x7f ) ) ;
F_14 ( V_39 , V_64 , 1 ) ;
} else {
F_14 ( V_39 , V_53 , 0 ) ;
F_15 ( V_39 , V_71 , 0 ) ;
F_14 ( V_39 , V_64 , 0 ) ;
}
V_69 = 1 ;
}
V_67 = ( V_40 [ 3 ] << 1 ) | ( V_40 [ 2 ] & 0x01 ) ;
if ( V_67 != V_8 -> V_61 ) {
V_8 -> V_61 = V_67 ;
F_14 ( V_39 , V_62 , V_67 & 0x001 ) ;
F_14 ( V_39 , V_63 , V_67 & 0x002 ) ;
F_14 ( V_39 , V_72 , V_67 & 0x004 ) ;
F_14 ( V_39 , V_73 , V_67 & 0x008 ) ;
F_14 ( V_39 , V_74 , V_67 & 0x010 ) ;
F_14 ( V_39 , V_75 , V_67 & 0x020 ) ;
F_14 ( V_39 , V_76 , V_67 & 0x040 ) ;
F_14 ( V_39 , V_77 , V_67 & 0x080 ) ;
F_14 ( V_39 , V_78 , V_67 & 0x100 ) ;
F_14 ( V_39 , V_64 , 1 ) ;
V_69 = 1 ;
}
if ( V_69 ) {
F_15 ( V_39 , V_79 , V_80 ) ;
F_19 ( V_39 , V_65 , V_66 , 0xffffffff ) ;
F_17 ( V_39 ) ;
}
}
static void F_22 ( struct V_7 * V_8 ,
struct V_38 * V_39 , unsigned char * V_40 )
{
V_60 V_42 , V_43 , V_81 ;
T_1 V_82 ;
switch ( V_40 [ 1 ] ) {
case 0x80 :
F_14 ( V_39 , V_53 , 0 ) ;
F_15 ( V_39 , V_56 , 0 ) ;
F_14 ( V_39 , V_54 , 0 ) ;
F_14 ( V_39 , V_55 , 0 ) ;
F_14 ( V_39 , V_8 -> V_41 , 0 ) ;
F_15 ( V_39 , V_79 , 0 ) ;
F_19 ( V_39 , V_65 , V_66 , V_8 -> V_83 ) ;
V_8 -> V_41 = 0 ;
F_17 ( V_39 ) ;
break;
case 0xC2 :
V_8 -> V_84 = ( ( V_40 [ 2 ] << 4 ) | ( V_40 [ 3 ] >> 4 ) |
( ( V_40 [ 7 ] & 0x0f ) << 20 ) |
( ( V_40 [ 8 ] & 0xf0 ) << 12 ) ) ;
V_8 -> V_83 = ( ( V_40 [ 3 ] & 0x0f ) << 28 ) +
( V_40 [ 4 ] << 20 ) + ( V_40 [ 5 ] << 12 ) +
( V_40 [ 6 ] << 4 ) + ( V_40 [ 7 ] >> 4 ) ;
switch ( V_8 -> V_84 ) {
case 0x100802 :
V_8 -> V_41 = V_46 ;
break;
case 0x10080A :
V_8 -> V_41 = V_47 ;
break;
}
break;
default:
V_42 = V_40 [ 2 ] << 9 | V_40 [ 3 ] << 1 | ( ( V_40 [ 9 ] & 0x02 ) >> 1 ) ;
V_43 = V_40 [ 4 ] << 9 | V_40 [ 5 ] << 1 | ( V_40 [ 9 ] & 0x01 ) ;
V_81 = ( V_40 [ 6 ] << 3 ) | ( ( V_40 [ 7 ] & 0xC0 ) >> 5 )
| ( V_40 [ 1 ] & 0x01 ) ;
V_82 = ( V_40 [ 9 ] >> 2 ) & 0x3f ;
F_14 ( V_39 , V_53 , V_81 > 1 ) ;
F_14 ( V_39 , V_54 , V_40 [ 1 ] & 0x02 ) ;
F_14 ( V_39 , V_55 , V_40 [ 1 ] & 0x04 ) ;
F_14 ( V_39 , V_8 -> V_41 , 1 ) ;
F_15 ( V_39 , V_57 , V_42 ) ;
F_15 ( V_39 , V_58 , V_43 ) ;
F_15 ( V_39 , V_56 , V_81 ) ;
F_15 ( V_39 , V_52 , V_82 ) ;
F_15 ( V_39 , V_79 , V_8 -> V_84 ) ;
F_19 ( V_39 , V_65 , V_66 , V_8 -> V_83 ) ;
F_14 ( V_39 , V_8 -> V_41 , 1 ) ;
F_17 ( V_39 ) ;
break;
}
return;
}
static void F_23 ( struct V_22 * V_23 ,
struct V_7 * V_8 ,
struct V_38 * V_39 , unsigned char * V_40 )
{
switch ( V_40 [ 0 ] ) {
case 0x00 :
break;
case 0x02 :
F_22 ( V_8 , V_39 , V_40 ) ;
break;
case 0x03 :
V_8 -> V_85 = V_40 [ 2 ] ;
break;
case 0x0C :
F_21 ( V_8 , V_39 , V_40 ) ;
break;
default:
F_24 ( V_23 , L_4 , V_40 [ 0 ] , V_40 [ 1 ] ) ;
break;
}
}
static int F_25 ( struct V_22 * V_23 , struct V_86 * V_87 ,
T_2 * V_88 , int V_89 )
{
struct V_7 * V_8 = F_6 ( V_23 ) ;
struct V_90 * V_91 ;
struct V_38 * V_39 ;
unsigned char * V_40 = ( unsigned char * ) V_88 ;
int V_92 ;
if ( ! ( V_23 -> V_93 & V_94 ) )
return 0 ;
V_91 = F_26 ( V_23 -> V_95 . V_96 , struct V_90 , V_97 ) ;
V_39 = V_91 -> V_39 ;
if ( V_40 [ 0 ] != 0x03 )
return 0 ;
switch ( V_23 -> V_98 ) {
case V_99 :
return F_12 ( V_23 , V_8 , V_39 , V_40 ) ;
break;
case V_100 :
V_92 = 1 ;
switch ( V_40 [ 0 ] ) {
case 0x04 :
F_23 ( V_23 , V_8 , V_39 , V_40 + V_92 ) ;
V_92 += 10 ;
case 0x03 :
F_23 ( V_23 , V_8 , V_39 , V_40 + V_92 ) ;
V_92 += 10 ;
F_23 ( V_23 , V_8 , V_39 , V_40 + V_92 ) ;
break;
default:
F_24 ( V_23 , L_5 ,
V_40 [ 0 ] , V_40 [ 1 ] , V_89 ) ;
return 0 ;
}
}
return 1 ;
}
static int F_27 ( struct V_22 * V_23 , struct V_90 * V_101 ,
struct V_102 * V_103 , struct V_104 * V_105 , unsigned long * * V_106 ,
int * V_107 )
{
struct V_38 * V_39 = V_101 -> V_39 ;
F_28 ( V_108 , V_39 -> V_109 ) ;
V_39 -> V_110 [ 0 ] |= F_29 ( V_111 ) | F_29 ( V_112 ) | F_29 ( V_113 ) ;
F_28 ( V_59 , V_39 -> V_114 ) ;
F_28 ( V_46 , V_39 -> V_115 ) ;
F_28 ( V_53 , V_39 -> V_115 ) ;
F_28 ( V_54 , V_39 -> V_115 ) ;
F_28 ( V_55 , V_39 -> V_115 ) ;
F_28 ( V_49 , V_39 -> V_115 ) ;
F_28 ( V_50 , V_39 -> V_115 ) ;
F_28 ( V_51 , V_39 -> V_115 ) ;
F_30 ( V_39 , V_65 , V_66 ) ;
F_28 ( V_62 , V_39 -> V_115 ) ;
F_28 ( V_63 , V_39 -> V_115 ) ;
F_28 ( V_64 , V_39 -> V_115 ) ;
F_28 ( V_47 , V_39 -> V_115 ) ;
F_28 ( V_48 , V_39 -> V_115 ) ;
switch ( V_23 -> V_98 ) {
case V_99 :
F_31 ( V_39 , V_57 , 0 , 16704 , 4 , 0 ) ;
F_31 ( V_39 , V_58 , 0 , 12064 , 4 , 0 ) ;
F_31 ( V_39 , V_56 , 0 , 511 , 0 , 0 ) ;
F_31 ( V_39 , V_52 , 0 , 32 , 0 , 0 ) ;
break;
case V_100 :
F_28 ( V_71 , V_39 -> V_116 ) ;
F_28 ( V_79 , V_39 -> V_116 ) ;
F_28 ( V_72 , V_39 -> V_115 ) ;
F_28 ( V_73 , V_39 -> V_115 ) ;
F_28 ( V_74 , V_39 -> V_115 ) ;
F_28 ( V_75 , V_39 -> V_115 ) ;
F_28 ( V_76 , V_39 -> V_115 ) ;
F_28 ( V_77 , V_39 -> V_115 ) ;
F_28 ( V_78 , V_39 -> V_115 ) ;
F_31 ( V_39 , V_71 , 0 , 71 , 0 , 0 ) ;
F_31 ( V_39 , V_57 , 0 , 40640 , 4 , 0 ) ;
F_31 ( V_39 , V_58 , 0 , 25400 , 4 , 0 ) ;
F_31 ( V_39 , V_56 , 0 , 2047 , 0 , 0 ) ;
F_31 ( V_39 , V_52 , 0 , 63 , 0 , 0 ) ;
break;
}
return 0 ;
}
static int F_32 ( struct V_22 * V_23 ,
const struct V_117 * V_84 )
{
struct V_7 * V_8 ;
int V_13 ;
V_8 = F_33 ( sizeof( * V_8 ) , V_118 ) ;
if ( V_8 == NULL ) {
F_24 ( V_23 , L_6 ) ;
return - V_119 ;
}
F_34 ( V_23 , V_8 ) ;
V_13 = F_35 ( V_23 ) ;
if ( V_13 ) {
F_24 ( V_23 , L_7 ) ;
goto V_120;
}
V_13 = F_36 ( V_23 , V_121 ) ;
if ( V_13 ) {
F_24 ( V_23 , L_8 ) ;
goto V_120;
}
V_13 = F_37 ( & V_23 -> V_31 , & V_122 ) ;
if ( V_13 )
F_7 ( V_23 ,
L_9 , V_13 ) ;
switch ( V_23 -> V_98 ) {
case V_99 :
F_5 ( V_23 , 1 ) ;
break;
case V_100 :
sprintf ( V_23 -> V_123 , L_10 , L_11 ) ;
V_8 -> V_85 = 0 ;
F_4 ( V_23 ) ;
break;
}
#ifdef F_20
V_8 -> V_9 . V_124 = V_125 ;
V_8 -> V_9 . V_126 = F_38 ( V_125 ) ;
V_8 -> V_9 . V_127 = F_1 ;
V_8 -> V_9 . V_123 = L_12 ;
V_8 -> V_9 . type = V_128 ;
V_8 -> V_9 . V_129 = 0 ;
V_13 = F_39 ( & V_23 -> V_31 , & V_8 -> V_9 ) ;
if ( V_13 ) {
F_7 ( V_23 , L_13 ,
V_13 ) ;
goto V_130;
}
F_40 ( & V_8 -> V_9 , & V_23 -> V_31 ) ;
V_8 -> V_20 . V_124 = V_131 ;
V_8 -> V_20 . V_126 = F_38 ( V_131 ) ;
V_8 -> V_20 . V_127 = F_3 ;
V_8 -> V_20 . V_123 = L_14 ;
V_8 -> V_20 . type = V_132 ;
V_8 -> V_20 . V_129 = 0 ;
V_13 = F_39 ( & V_23 -> V_31 , & V_8 -> V_20 ) ;
if ( V_13 ) {
F_7 ( V_23 ,
L_15 , V_13 ) ;
goto V_133;
}
F_40 ( & V_8 -> V_20 , & V_23 -> V_31 ) ;
#endif
return 0 ;
#ifdef F_20
V_133:
F_41 ( & V_8 -> V_9 ) ;
V_130:
F_42 ( & V_23 -> V_31 , & V_122 ) ;
F_43 ( V_23 ) ;
#endif
V_120:
F_44 ( V_8 ) ;
return V_13 ;
}
static void F_45 ( struct V_22 * V_23 )
{
#ifdef F_20
struct V_7 * V_8 = F_6 ( V_23 ) ;
#endif
F_42 ( & V_23 -> V_31 , & V_122 ) ;
F_43 ( V_23 ) ;
#ifdef F_20
F_41 ( & V_8 -> V_9 ) ;
F_41 ( & V_8 -> V_20 ) ;
#endif
F_44 ( F_6 ( V_23 ) ) ;
}
static int T_5 F_46 ( void )
{
int V_13 ;
V_13 = F_47 ( & V_134 ) ;
if ( V_13 )
F_48 ( L_16 ) ;
return V_13 ;
}
static void T_6 F_49 ( void )
{
F_50 ( & V_134 ) ;
}
