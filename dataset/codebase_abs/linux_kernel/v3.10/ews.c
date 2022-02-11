static void F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned char V_8 = 0 ;
if ( V_3 )
V_8 |= V_9 ;
if ( V_4 )
V_8 |= V_10 ;
F_2 ( V_6 , V_11 , V_8 ) ;
F_3 ( 5 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
return F_5 ( V_6 , V_11 ) & V_9 ? 1 : 0 ;
}
static int F_6 ( struct V_1 * V_2 , int V_12 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_13 ;
F_2 ( V_6 , V_14 , ~ V_15 ) ;
F_2 ( V_6 , V_11 , 0 ) ;
if ( V_12 )
F_3 ( 5 ) ;
V_13 = F_5 ( V_6 , V_11 ) & V_10 ? 1 : 0 ;
F_2 ( V_6 , V_11 , V_15 ) ;
F_2 ( V_6 , V_14 , ~ V_9 ) ;
return V_13 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned char V_16 ;
F_8 ( V_6 ) ;
V_16 = V_15 ;
switch ( V_6 -> V_17 . V_18 ) {
case V_19 :
V_16 |= V_20 ;
break;
case V_21 :
V_16 |= V_22 ;
break;
}
F_9 ( V_6 , V_16 , V_16 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_11 ( V_6 ) ;
}
static void F_12 ( struct V_1 * V_2 , int clock , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned char V_16 = 0 ;
if ( clock )
V_16 |= V_9 ;
if ( V_4 )
V_16 |= V_10 ;
V_6 -> V_23 . V_24 &= ~ ( V_9 | V_10 ) ;
V_6 -> V_23 . V_24 |= V_16 ;
F_2 ( V_6 , V_25 , V_6 -> V_23 . V_24 ) ;
F_2 ( V_6 , V_14 , ~ V_16 ) ;
}
static int F_13 ( struct V_5 * V_6 , int V_26 )
{
struct V_27 * V_28 = V_6 -> V_28 ;
unsigned char V_4 , V_29 ;
if ( F_14 ( V_26 < 0 || V_26 > 0x0f ) )
return - V_30 ;
F_15 ( V_6 -> V_31 ) ;
if ( F_16 ( V_28 -> V_32 [ V_33 ] , & V_4 , 1 ) != 1 )
goto V_34;
V_29 = ( V_4 & 0xf0 ) | V_26 ;
if ( V_29 != V_4 )
if ( F_17 ( V_28 -> V_32 [ V_33 ] , & V_29 , 1 )
!= 1 )
goto V_34;
F_18 ( V_6 -> V_31 ) ;
return 0 ;
V_34:
F_18 ( V_6 -> V_31 ) ;
F_19 ( V_35 L_1 ) ;
return - V_36 ;
}
static void F_20 ( struct V_37 * V_38 , int V_39 )
{
struct V_5 * V_6 = V_38 -> V_7 [ 0 ] ;
unsigned char V_8 ;
if ( F_13 ( V_6 , ~ ( 1 << V_39 ) & 0x0f ) < 0 )
F_19 ( V_35 L_2 ) ;
F_8 ( V_6 ) ;
V_8 = V_40 |
V_41 |
V_42 ;
F_2 ( V_6 , V_25 ,
V_6 -> V_23 . V_24 | V_8 ) ;
F_2 ( V_6 , V_14 , ~ V_8 ) ;
}
static void F_21 ( struct V_37 * V_38 , int V_39 )
{
struct V_5 * V_6 = V_38 -> V_7 [ 0 ] ;
F_11 ( V_6 ) ;
F_3 ( 1 ) ;
F_13 ( V_6 , 0x0f ) ;
}
static void F_22 ( struct V_37 * V_38 , int V_39 )
{
struct V_5 * V_6 = V_38 -> V_7 [ 0 ] ;
unsigned char V_8 ;
F_8 ( V_6 ) ;
V_8 = V_10 |
V_9 |
V_20 |
V_15 ;
F_2 ( V_6 , V_25 ,
V_6 -> V_23 . V_24 | V_8 ) ;
F_2 ( V_6 , V_14 , ~ V_8 ) ;
}
static void F_23 ( struct V_37 * V_38 , int V_39 )
{
struct V_43 * V_44 = ( void * ) V_38 -> V_45 [ 0 ] ;
struct V_5 * V_6 = V_38 -> V_7 [ 0 ] ;
unsigned char V_8 ;
F_8 ( V_6 ) ;
V_8 = V_44 -> V_46 = V_44 -> V_47 = ( 1 << V_39 ) & V_22 ;
V_8 |= V_48 |
V_49 |
V_50 ;
F_2 ( V_6 , V_25 ,
V_6 -> V_23 . V_24 | V_8 ) ;
F_2 ( V_6 , V_14 , ~ V_8 ) ;
}
static void F_24 ( struct V_5 * V_6 , unsigned char V_51 )
{
struct V_27 * V_28 = V_6 -> V_28 ;
unsigned char V_52 [ 2 ] ;
F_15 ( V_6 -> V_31 ) ;
switch ( V_6 -> V_17 . V_18 ) {
case V_53 :
case V_54 :
case V_55 :
case V_56 :
if ( F_17 ( V_28 -> V_32 [ V_57 ] , & V_51 , 1 )
!= 1 )
goto V_58;
break;
case V_59 :
if ( F_16 ( V_28 -> V_32 [ V_60 ] , V_52 , 2 )
!= 2 )
goto V_58;
if ( V_51 != V_52 [ 1 ] ) {
V_52 [ 1 ] = V_51 ;
if ( F_17 ( V_28 -> V_32 [ V_60 ] ,
V_52 , 2 ) != 2 )
goto V_58;
}
break;
}
V_58:
F_18 ( V_6 -> V_31 ) ;
}
static void F_25 ( struct V_5 * V_6 , struct V_61 * V_62 )
{
F_26 ( & V_62 -> V_63 . V_64 , V_6 -> V_65 . V_66 ) ;
}
static int F_27 ( struct V_5 * V_6 , struct V_61 * V_62 )
{
unsigned int V_67 ;
int V_68 ;
V_67 = F_28 ( & V_62 -> V_63 . V_64 ) ;
F_29 ( & V_6 -> V_69 ) ;
V_68 = V_6 -> V_65 . V_66 != V_67 ;
V_6 -> V_65 . V_66 = V_67 ;
if ( V_68 && V_6 -> V_70 == NULL ) {
F_30 ( & V_6 -> V_69 ) ;
F_24 ( V_6 , V_67 ) ;
} else {
F_30 ( & V_6 -> V_69 ) ;
}
return V_68 ;
}
static void F_31 ( struct V_5 * V_6 , struct V_61 * V_62 )
{
F_26 ( & V_62 -> V_63 . V_64 , V_6 -> V_65 . V_71 ) ;
}
static int F_32 ( struct V_5 * V_6 , struct V_61 * V_62 )
{
unsigned int V_67 ;
int V_68 ;
V_67 = F_28 ( & V_62 -> V_63 . V_64 ) ;
F_29 ( & V_6 -> V_69 ) ;
V_68 = V_6 -> V_65 . V_71 != V_67 ;
V_6 -> V_65 . V_71 = V_67 ;
if ( V_68 && V_6 -> V_70 != NULL ) {
F_30 ( & V_6 -> V_69 ) ;
F_24 ( V_6 , V_67 ) ;
} else {
F_30 ( & V_6 -> V_69 ) ;
}
return V_68 ;
}
static void F_33 ( struct V_5 * V_6 , struct V_72 * V_73 )
{
V_6 -> V_65 . V_71 = V_6 -> V_65 . V_66 ;
}
static void F_34 ( struct V_5 * V_6 , int V_74 )
{
unsigned long V_75 ;
unsigned char V_8 ;
int V_68 ;
F_35 ( & V_6 -> V_69 , V_75 ) ;
V_8 = V_6 -> V_65 . V_71 ;
if ( V_8 & 0x10 )
V_8 &= ( V_8 & 0x01 ) ? ~ 0x06 : ~ 0x60 ;
switch ( V_74 ) {
case 32000 : V_8 |= ( V_8 & 0x01 ) ? 0x02 : 0x00 ; break;
case 44100 : V_8 |= ( V_8 & 0x01 ) ? 0x06 : 0x40 ; break;
case 48000 : V_8 |= ( V_8 & 0x01 ) ? 0x04 : 0x20 ; break;
default: V_8 |= ( V_8 & 0x01 ) ? 0x06 : 0x40 ; break;
}
V_68 = V_6 -> V_65 . V_71 != V_8 ;
V_6 -> V_65 . V_71 = V_8 ;
F_36 ( & V_6 -> V_69 , V_75 ) ;
if ( V_68 )
F_37 ( V_6 -> V_76 , V_77 , & V_6 -> V_65 . V_78 -> V_79 ) ;
F_24 ( V_6 , V_8 ) ;
}
static int F_38 ( struct V_5 * V_6 )
{
int V_80 ;
struct V_37 * V_38 ;
struct V_27 * V_28 ;
switch ( V_6 -> V_17 . V_18 ) {
case V_19 :
V_6 -> V_81 = 2 ;
V_6 -> V_82 = 2 ;
break;
case V_53 :
case V_54 :
case V_55 :
case V_56 :
V_6 -> V_81 = 8 ;
V_6 -> V_82 = 8 ;
break;
case V_59 :
V_6 -> V_81 = 8 ;
V_6 -> V_82 = 8 ;
break;
case V_21 :
V_6 -> V_81 = 6 ;
V_6 -> V_82 = 6 ;
break;
}
V_28 = F_39 ( sizeof( * V_28 ) , V_83 ) ;
if ( ! V_28 )
return - V_84 ;
V_6 -> V_28 = V_28 ;
if ( ( V_80 = F_40 ( V_6 -> V_76 , L_3 , NULL , & V_6 -> V_31 ) ) < 0 ) {
F_19 ( V_35 L_4 ) ;
return V_80 ;
}
V_6 -> V_31 -> V_7 = V_6 ;
V_6 -> V_31 -> V_85 . V_13 = & V_86 ;
switch ( V_6 -> V_17 . V_18 ) {
case V_21 :
V_80 = F_41 ( V_6 -> V_31 , L_5 ,
V_87 ,
& V_28 -> V_32 [ V_88 ] ) ;
if ( V_80 < 0 ) {
F_19 ( V_35 L_6 ) ;
return V_80 ;
}
F_42 ( V_6 , V_89 , 0x80 ) ;
break;
case V_53 :
case V_54 :
case V_55 :
case V_56 :
V_80 = F_41 ( V_6 -> V_31 , L_7 ,
V_90 ,
& V_28 -> V_32 [ V_57 ] ) ;
if ( V_80 < 0 )
return V_80 ;
V_80 = F_41 ( V_6 -> V_31 , L_8 ,
V_91 ,
& V_28 -> V_32 [ V_92 ] ) ;
if ( V_80 < 0 )
return V_80 ;
V_80 = F_41 ( V_6 -> V_31 , L_9 ,
V_93 ,
& V_28 -> V_32 [ V_33 ] ) ;
if ( V_80 < 0 )
return V_80 ;
if ( ( V_80 = F_13 ( V_6 , 0x0f ) ) < 0 )
return V_80 ;
break;
case V_59 :
V_80 = F_41 ( V_6 -> V_31 , L_10 ,
V_94 ,
& V_28 -> V_32 [ V_60 ] ) ;
if ( V_80 < 0 )
return V_80 ;
break;
}
switch ( V_6 -> V_17 . V_18 ) {
case V_19 :
if ( ( V_80 = F_43 ( V_6 , V_95 ) ) < 0 )
return V_80 ;
F_44 ( V_6 -> V_96 , V_97 , V_98 | V_99 | V_100 | V_101 ) ;
break;
case V_21 :
if ( ( V_80 = F_43 ( V_6 , V_102 ) ) < 0 )
return V_80 ;
F_44 ( V_6 -> V_96 , V_97 , V_98 | V_99 | V_100 | V_101 ) ;
break;
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_59 :
V_6 -> V_65 . V_103 . V_104 = F_33 ;
V_6 -> V_65 . V_103 . V_105 = F_34 ;
V_6 -> V_65 . V_103 . V_106 = F_25 ;
V_6 -> V_65 . V_103 . V_107 = F_27 ;
V_6 -> V_65 . V_103 . V_108 = F_31 ;
V_6 -> V_65 . V_103 . V_109 = F_32 ;
F_24 ( V_6 , V_6 -> V_65 . V_66 ) ;
break;
}
switch ( V_6 -> V_17 . V_18 ) {
case V_59 :
return 0 ;
}
V_38 = V_6 -> V_110 = F_39 ( sizeof( struct V_37 ) , V_83 ) ;
if ( ! V_38 )
return - V_84 ;
V_6 -> V_111 = 1 ;
switch ( V_6 -> V_17 . V_18 ) {
case V_53 :
case V_54 :
case V_55 :
case V_56 :
V_80 = F_45 ( V_38 , & V_112 , & V_113 , V_6 ) ;
break;
case V_19 :
V_80 = F_45 ( V_38 , & V_114 , & V_115 , V_6 ) ;
break;
case V_21 :
V_80 = F_45 ( V_38 , & V_116 , & V_117 , V_6 ) ;
break;
default:
V_80 = 0 ;
}
return V_80 ;
}
static int F_46 ( struct V_118 * V_119 , struct V_120 * V_121 ) {
static const char * const V_122 [ 2 ] = {
L_11 , L_12 ,
} ;
V_121 -> type = V_123 ;
V_121 -> V_124 = 1 ;
V_121 -> V_63 . V_125 . V_126 = 2 ;
if ( V_121 -> V_63 . V_125 . V_127 >= 2 )
V_121 -> V_63 . V_125 . V_127 = 1 ;
strcpy ( V_121 -> V_63 . V_125 . V_128 , V_122 [ V_121 -> V_63 . V_125 . V_127 ] ) ;
return 0 ;
}
static int F_47 ( struct V_118 * V_119 , struct V_61 * V_62 )
{
struct V_5 * V_6 = F_48 ( V_119 ) ;
unsigned char V_16 = V_119 -> V_45 & 0xff ;
F_8 ( V_6 ) ;
V_62 -> V_63 . V_125 . V_127 [ 0 ] = F_5 ( V_6 , V_11 ) & V_16 ? 1 : 0 ;
F_11 ( V_6 ) ;
return 0 ;
}
static int F_49 ( struct V_118 * V_119 , struct V_61 * V_62 )
{
struct V_5 * V_6 = F_48 ( V_119 ) ;
unsigned char V_16 = V_119 -> V_45 & 0xff ;
int V_67 , V_129 ;
if ( V_119 -> V_45 & ( 1 << 31 ) )
return - V_130 ;
V_129 = V_62 -> V_63 . V_125 . V_127 [ 0 ] ? V_16 : 0 ;
F_8 ( V_6 ) ;
V_67 = F_5 ( V_6 , V_11 ) ;
V_129 |= V_67 & ~ V_16 ;
F_2 ( V_6 , V_11 , V_129 ) ;
F_11 ( V_6 ) ;
return V_67 != V_129 ;
}
static int F_50 ( struct V_118 * V_119 , struct V_61 * V_62 )
{
struct V_5 * V_6 = F_48 ( V_119 ) ;
struct V_27 * V_28 = V_6 -> V_28 ;
unsigned char V_4 ;
F_15 ( V_6 -> V_31 ) ;
if ( F_16 ( V_28 -> V_32 [ V_33 ] , & V_4 , 1 ) != 1 ) {
F_18 ( V_6 -> V_31 ) ;
return - V_36 ;
}
F_18 ( V_6 -> V_31 ) ;
V_62 -> V_63 . V_125 . V_127 [ 0 ] = V_4 & V_131 ? 1 : 0 ;
return 0 ;
}
static int F_51 ( struct V_118 * V_119 , struct V_61 * V_62 )
{
struct V_5 * V_6 = F_48 ( V_119 ) ;
struct V_27 * V_28 = V_6 -> V_28 ;
unsigned char V_4 , V_29 ;
F_15 ( V_6 -> V_31 ) ;
if ( F_16 ( V_28 -> V_32 [ V_33 ] , & V_4 , 1 ) != 1 ) {
F_18 ( V_6 -> V_31 ) ;
return - V_36 ;
}
V_29 = ( V_4 & ~ V_131 ) | ( V_62 -> V_63 . V_125 . V_127 [ 0 ] ? V_131 : 0 ) ;
if ( V_29 != V_4 && F_17 ( V_28 -> V_32 [ V_33 ] ,
& V_29 , 1 ) != 1 ) {
F_18 ( V_6 -> V_31 ) ;
return - V_36 ;
}
F_18 ( V_6 -> V_31 ) ;
return V_29 != V_4 ;
}
static int F_52 ( struct V_118 * V_119 , struct V_61 * V_62 )
{
struct V_5 * V_6 = F_48 ( V_119 ) ;
struct V_27 * V_28 = V_6 -> V_28 ;
int V_132 = F_53 ( V_119 , & V_62 -> V_79 ) ;
unsigned char V_4 ;
if ( F_14 ( V_132 < 0 || V_132 > 7 ) )
return 0 ;
F_15 ( V_6 -> V_31 ) ;
if ( F_16 ( V_28 -> V_32 [ V_92 ] , & V_4 , 1 ) != 1 ) {
F_18 ( V_6 -> V_31 ) ;
return - V_36 ;
}
V_62 -> V_63 . V_125 . V_127 [ 0 ] = V_4 & ( 1 << V_132 ) ? 0 : 1 ;
F_18 ( V_6 -> V_31 ) ;
return 0 ;
}
static int F_54 ( struct V_118 * V_119 , struct V_61 * V_62 )
{
struct V_5 * V_6 = F_48 ( V_119 ) ;
struct V_27 * V_28 = V_6 -> V_28 ;
int V_132 = F_53 ( V_119 , & V_62 -> V_79 ) ;
unsigned char V_4 , V_29 ;
if ( F_14 ( V_132 < 0 || V_132 > 7 ) )
return 0 ;
F_15 ( V_6 -> V_31 ) ;
if ( F_16 ( V_28 -> V_32 [ V_92 ] , & V_4 , 1 ) != 1 ) {
F_18 ( V_6 -> V_31 ) ;
return - V_36 ;
}
V_29 = ( V_4 & ~ ( 1 << V_132 ) ) | ( V_62 -> V_63 . V_125 . V_127 [ 0 ] ? 0 : ( 1 << V_132 ) ) ;
if ( V_29 != V_4 && F_17 ( V_28 -> V_32 [ V_92 ] ,
& V_29 , 1 ) != 1 ) {
F_18 ( V_6 -> V_31 ) ;
return - V_36 ;
}
F_18 ( V_6 -> V_31 ) ;
return V_29 != V_4 ;
}
static int F_55 ( struct V_118 * V_119 , struct V_61 * V_62 )
{
struct V_5 * V_6 = F_48 ( V_119 ) ;
struct V_27 * V_28 = V_6 -> V_28 ;
int V_133 = V_119 -> V_45 & 0xff ;
int V_134 = ( V_119 -> V_45 >> 8 ) & 1 ;
unsigned char V_4 [ 2 ] ;
F_15 ( V_6 -> V_31 ) ;
if ( F_16 ( V_28 -> V_32 [ V_60 ] , V_4 , 2 ) != 2 ) {
F_18 ( V_6 -> V_31 ) ;
return - V_36 ;
}
F_18 ( V_6 -> V_31 ) ;
V_4 [ 0 ] = ( V_4 [ V_133 >> 3 ] >> ( V_133 & 7 ) ) & 0x01 ;
if ( V_134 )
V_4 [ 0 ] ^= 0x01 ;
V_62 -> V_63 . integer . V_63 [ 0 ] = V_4 [ 0 ] ;
return 0 ;
}
static int F_56 ( struct V_118 * V_119 , struct V_61 * V_62 )
{
struct V_5 * V_6 = F_48 ( V_119 ) ;
struct V_27 * V_28 = V_6 -> V_28 ;
int V_133 = V_119 -> V_45 & 0xff ;
int V_134 = ( V_119 -> V_45 >> 8 ) & 1 ;
unsigned char V_4 [ 2 ] , V_29 [ 2 ] ;
int V_68 ;
F_15 ( V_6 -> V_31 ) ;
if ( F_16 ( V_28 -> V_32 [ V_60 ] , V_4 , 2 ) != 2 ) {
F_18 ( V_6 -> V_31 ) ;
return - V_36 ;
}
V_29 [ V_133 >> 3 ] = V_4 [ V_133 >> 3 ] & ~ ( 1 << ( V_133 & 7 ) ) ;
if ( V_134 ) {
if ( ! V_62 -> V_63 . integer . V_63 [ 0 ] )
V_29 [ V_133 >> 3 ] |= ( 1 << ( V_133 & 7 ) ) ;
} else {
if ( V_62 -> V_63 . integer . V_63 [ 0 ] )
V_29 [ V_133 >> 3 ] |= ( 1 << ( V_133 & 7 ) ) ;
}
V_68 = ( V_4 [ V_133 >> 3 ] != V_29 [ V_133 >> 3 ] ) ;
if ( V_68 &&
F_17 ( V_28 -> V_32 [ V_60 ] , V_4 , 2 ) != 2 ) {
F_18 ( V_6 -> V_31 ) ;
return - V_36 ;
}
F_18 ( V_6 -> V_31 ) ;
return V_68 ;
}
static int F_57 ( struct V_5 * V_6 , unsigned char V_135 )
{
unsigned char V_136 ;
struct V_27 * V_28 = V_6 -> V_28 ;
F_15 ( V_6 -> V_31 ) ;
V_136 = V_135 ;
F_17 ( V_28 -> V_32 [ V_88 ] , & V_136 , 1 ) ;
V_136 = 0 ;
if ( F_16 ( V_28 -> V_32 [ V_88 ] , & V_136 , 1 ) != 1 ) {
F_18 ( V_6 -> V_31 ) ;
F_58 ( V_35 L_13 ) ;
return - V_36 ;
}
F_18 ( V_6 -> V_31 ) ;
return V_136 ;
}
static int F_42 ( struct V_5 * V_6 , unsigned char V_135 , unsigned char V_4 )
{
unsigned char V_52 [ 2 ] ;
struct V_27 * V_28 = V_6 -> V_28 ;
F_15 ( V_6 -> V_31 ) ;
V_52 [ 0 ] = V_135 ;
V_52 [ 1 ] = V_4 ;
if ( F_17 ( V_28 -> V_32 [ V_88 ] , V_52 , 2 ) != 2 ) {
F_18 ( V_6 -> V_31 ) ;
return - V_36 ;
}
F_18 ( V_6 -> V_31 ) ;
return 0 ;
}
static int F_59 ( struct V_118 * V_119 , struct V_61 * V_62 )
{
struct V_5 * V_6 = F_48 ( V_119 ) ;
int V_133 = V_119 -> V_45 & 0xff ;
int V_134 = ( V_119 -> V_45 >> 8 ) & 1 ;
int V_4 ;
if ( ( V_4 = F_57 ( V_6 , V_137 ) ) < 0 )
return V_4 ;
V_4 = ( V_4 >> V_133 ) & 1 ;
if ( V_134 )
V_4 ^= 1 ;
V_62 -> V_63 . integer . V_63 [ 0 ] = V_4 ;
return 0 ;
}
static int F_60 ( struct V_118 * V_119 , struct V_61 * V_62 )
{
struct V_5 * V_6 = F_48 ( V_119 ) ;
int V_133 = V_119 -> V_45 & 0xff ;
int V_134 = ( V_119 -> V_45 >> 8 ) & 1 ;
int V_4 , V_29 ;
if ( ( V_4 = F_57 ( V_6 , V_137 ) ) < 0 )
return V_4 ;
V_29 = V_4 & ~ ( 1 << V_133 ) ;
if ( V_62 -> V_63 . integer . V_63 [ 0 ] )
V_29 |= ( 1 << V_133 ) ;
if ( V_134 )
V_29 ^= ( 1 << V_133 ) ;
if ( V_4 != V_29 ) {
F_42 ( V_6 , V_137 , ( unsigned char ) V_29 ) ;
return 1 ;
}
return 0 ;
}
static int F_61 ( struct V_118 * V_119 , struct V_120 * V_121 )
{
static const char * const V_122 [ 4 ] = {
L_14 , L_15 , L_16 , L_17
} ;
V_121 -> type = V_123 ;
V_121 -> V_124 = 1 ;
V_121 -> V_63 . V_125 . V_126 = 4 ;
if ( V_121 -> V_63 . V_125 . V_127 >= 4 )
V_121 -> V_63 . V_125 . V_127 = 1 ;
strcpy ( V_121 -> V_63 . V_125 . V_128 , V_122 [ V_121 -> V_63 . V_125 . V_127 ] ) ;
return 0 ;
}
static int F_62 ( struct V_118 * V_119 , struct V_61 * V_62 )
{
struct V_5 * V_6 = F_48 ( V_119 ) ;
int V_4 ;
if ( ( V_4 = F_57 ( V_6 , V_137 ) ) < 0 )
return V_4 ;
V_62 -> V_63 . integer . V_63 [ 0 ] = V_4 & 3 ;
return 0 ;
}
static int F_63 ( struct V_118 * V_119 , struct V_61 * V_62 )
{
struct V_5 * V_6 = F_48 ( V_119 ) ;
int V_4 , V_29 ;
if ( ( V_4 = F_57 ( V_6 , V_137 ) ) < 0 )
return V_4 ;
V_29 = V_4 & ~ 3 ;
V_29 |= ( V_62 -> V_63 . integer . V_63 [ 0 ] & 3 ) ;
if ( V_4 != V_29 ) {
F_42 ( V_6 , V_137 , ( unsigned char ) V_29 ) ;
return 1 ;
}
return 0 ;
}
static int F_64 ( struct V_5 * V_6 )
{
unsigned int V_138 ;
int V_80 ;
if ( V_6 -> V_96 == NULL ) {
V_80 = F_65 ( V_6 ) ;
if ( V_80 < 0 )
return V_80 ;
}
switch ( V_6 -> V_17 . V_18 ) {
case V_19 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_21 :
V_80 = F_66 ( V_6 ) ;
if ( V_80 < 0 )
return V_80 ;
break;
}
switch ( V_6 -> V_17 . V_18 ) {
case V_19 :
for ( V_138 = 0 ; V_138 < F_67 ( V_139 ) ; V_138 ++ ) {
V_80 = F_68 ( V_6 -> V_76 , F_69 ( & V_139 [ V_138 ] , V_6 ) ) ;
if ( V_80 < 0 )
return V_80 ;
}
break;
case V_53 :
case V_54 :
case V_55 :
case V_56 :
V_80 = F_68 ( V_6 -> V_76 , F_69 ( & V_140 , V_6 ) ) ;
if ( V_80 < 0 )
return V_80 ;
V_80 = F_68 ( V_6 -> V_76 , F_69 ( & V_141 , V_6 ) ) ;
if ( V_80 < 0 )
return V_80 ;
break;
case V_59 :
for ( V_138 = 0 ; V_138 < F_67 ( V_142 ) ; V_138 ++ ) {
V_80 = F_68 ( V_6 -> V_76 , F_69 ( & V_142 [ V_138 ] , V_6 ) ) ;
if ( V_80 < 0 )
return V_80 ;
}
break;
case V_21 :
for ( V_138 = 0 ; V_138 < F_67 ( V_143 ) ; V_138 ++ ) {
V_80 = F_68 ( V_6 -> V_76 , F_69 ( & V_143 [ V_138 ] , V_6 ) ) ;
if ( V_80 < 0 )
return V_80 ;
}
break;
}
return 0 ;
}
