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
F_19 ( V_6 -> V_35 -> V_36 ,
L_1 ) ;
return - V_37 ;
}
static void F_20 ( struct V_38 * V_39 , int V_40 )
{
struct V_5 * V_6 = V_39 -> V_7 [ 0 ] ;
unsigned char V_8 ;
if ( F_13 ( V_6 , ~ ( 1 << V_40 ) & 0x0f ) < 0 )
F_19 ( V_6 -> V_35 -> V_36 , L_2 ) ;
F_8 ( V_6 ) ;
V_8 = V_41 |
V_42 |
V_43 ;
F_2 ( V_6 , V_25 ,
V_6 -> V_23 . V_24 | V_8 ) ;
F_2 ( V_6 , V_14 , ~ V_8 ) ;
}
static void F_21 ( struct V_38 * V_39 , int V_40 )
{
struct V_5 * V_6 = V_39 -> V_7 [ 0 ] ;
F_11 ( V_6 ) ;
F_3 ( 1 ) ;
F_13 ( V_6 , 0x0f ) ;
}
static void F_22 ( struct V_38 * V_39 , int V_40 )
{
struct V_5 * V_6 = V_39 -> V_7 [ 0 ] ;
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
static void F_23 ( struct V_38 * V_39 , int V_40 )
{
struct V_44 * V_45 = ( void * ) V_39 -> V_46 [ 0 ] ;
struct V_5 * V_6 = V_39 -> V_7 [ 0 ] ;
unsigned char V_8 ;
F_8 ( V_6 ) ;
V_8 = V_45 -> V_47 = V_45 -> V_48 = ( 1 << V_40 ) & V_22 ;
V_8 |= V_49 |
V_50 |
V_51 ;
F_2 ( V_6 , V_25 ,
V_6 -> V_23 . V_24 | V_8 ) ;
F_2 ( V_6 , V_14 , ~ V_8 ) ;
}
static void F_24 ( struct V_5 * V_6 , unsigned char V_52 )
{
struct V_27 * V_28 = V_6 -> V_28 ;
unsigned char V_53 [ 2 ] ;
F_15 ( V_6 -> V_31 ) ;
switch ( V_6 -> V_17 . V_18 ) {
case V_54 :
case V_55 :
case V_56 :
case V_57 :
if ( F_17 ( V_28 -> V_32 [ V_58 ] , & V_52 , 1 )
!= 1 )
goto V_59;
break;
case V_60 :
if ( F_16 ( V_28 -> V_32 [ V_61 ] , V_53 , 2 )
!= 2 )
goto V_59;
if ( V_52 != V_53 [ 1 ] ) {
V_53 [ 1 ] = V_52 ;
if ( F_17 ( V_28 -> V_32 [ V_61 ] ,
V_53 , 2 ) != 2 )
goto V_59;
}
break;
}
V_59:
F_18 ( V_6 -> V_31 ) ;
}
static void F_25 ( struct V_5 * V_6 , struct V_62 * V_63 )
{
F_26 ( & V_63 -> V_64 . V_65 , V_6 -> V_66 . V_67 ) ;
}
static int F_27 ( struct V_5 * V_6 , struct V_62 * V_63 )
{
unsigned int V_68 ;
int V_69 ;
V_68 = F_28 ( & V_63 -> V_64 . V_65 ) ;
F_29 ( & V_6 -> V_70 ) ;
V_69 = V_6 -> V_66 . V_67 != V_68 ;
V_6 -> V_66 . V_67 = V_68 ;
if ( V_69 && V_6 -> V_71 == NULL ) {
F_30 ( & V_6 -> V_70 ) ;
F_24 ( V_6 , V_68 ) ;
} else {
F_30 ( & V_6 -> V_70 ) ;
}
return V_69 ;
}
static void F_31 ( struct V_5 * V_6 , struct V_62 * V_63 )
{
F_26 ( & V_63 -> V_64 . V_65 , V_6 -> V_66 . V_72 ) ;
}
static int F_32 ( struct V_5 * V_6 , struct V_62 * V_63 )
{
unsigned int V_68 ;
int V_69 ;
V_68 = F_28 ( & V_63 -> V_64 . V_65 ) ;
F_29 ( & V_6 -> V_70 ) ;
V_69 = V_6 -> V_66 . V_72 != V_68 ;
V_6 -> V_66 . V_72 = V_68 ;
if ( V_69 && V_6 -> V_71 != NULL ) {
F_30 ( & V_6 -> V_70 ) ;
F_24 ( V_6 , V_68 ) ;
} else {
F_30 ( & V_6 -> V_70 ) ;
}
return V_69 ;
}
static void F_33 ( struct V_5 * V_6 , struct V_73 * V_74 )
{
V_6 -> V_66 . V_72 = V_6 -> V_66 . V_67 ;
}
static void F_34 ( struct V_5 * V_6 , int V_75 )
{
unsigned long V_76 ;
unsigned char V_8 ;
int V_69 ;
F_35 ( & V_6 -> V_70 , V_76 ) ;
V_8 = V_6 -> V_66 . V_72 ;
if ( V_8 & 0x10 )
V_8 &= ( V_8 & 0x01 ) ? ~ 0x06 : ~ 0x60 ;
switch ( V_75 ) {
case 32000 : V_8 |= ( V_8 & 0x01 ) ? 0x02 : 0x00 ; break;
case 44100 : V_8 |= ( V_8 & 0x01 ) ? 0x06 : 0x40 ; break;
case 48000 : V_8 |= ( V_8 & 0x01 ) ? 0x04 : 0x20 ; break;
default: V_8 |= ( V_8 & 0x01 ) ? 0x06 : 0x40 ; break;
}
V_69 = V_6 -> V_66 . V_72 != V_8 ;
V_6 -> V_66 . V_72 = V_8 ;
F_36 ( & V_6 -> V_70 , V_76 ) ;
if ( V_69 )
F_37 ( V_6 -> V_35 , V_77 , & V_6 -> V_66 . V_78 -> V_79 ) ;
F_24 ( V_6 , V_8 ) ;
}
static int F_38 ( struct V_5 * V_6 )
{
int V_80 ;
struct V_38 * V_39 ;
struct V_27 * V_28 ;
switch ( V_6 -> V_17 . V_18 ) {
case V_19 :
V_6 -> V_81 = 2 ;
V_6 -> V_82 = 2 ;
break;
case V_54 :
case V_55 :
case V_56 :
case V_57 :
V_6 -> V_81 = 8 ;
V_6 -> V_82 = 8 ;
break;
case V_60 :
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
if ( ( V_80 = F_40 ( V_6 -> V_35 , L_3 , NULL , & V_6 -> V_31 ) ) < 0 ) {
F_19 ( V_6 -> V_35 -> V_36 , L_4 ) ;
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
F_19 ( V_6 -> V_35 -> V_36 ,
L_6 ) ;
return V_80 ;
}
F_42 ( V_6 , V_89 , 0x80 ) ;
break;
case V_54 :
case V_55 :
case V_56 :
case V_57 :
V_80 = F_41 ( V_6 -> V_31 , L_7 ,
V_90 ,
& V_28 -> V_32 [ V_58 ] ) ;
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
case V_60 :
V_80 = F_41 ( V_6 -> V_31 , L_10 ,
V_94 ,
& V_28 -> V_32 [ V_61 ] ) ;
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
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_60 :
V_6 -> V_66 . V_103 . V_104 = F_33 ;
V_6 -> V_66 . V_103 . V_105 = F_34 ;
V_6 -> V_66 . V_103 . V_106 = F_25 ;
V_6 -> V_66 . V_103 . V_107 = F_27 ;
V_6 -> V_66 . V_103 . V_108 = F_31 ;
V_6 -> V_66 . V_103 . V_109 = F_32 ;
F_24 ( V_6 , V_6 -> V_66 . V_67 ) ;
break;
}
switch ( V_6 -> V_17 . V_18 ) {
case V_60 :
return 0 ;
}
V_39 = V_6 -> V_110 = F_39 ( sizeof( struct V_38 ) , V_83 ) ;
if ( ! V_39 )
return - V_84 ;
V_6 -> V_111 = 1 ;
switch ( V_6 -> V_17 . V_18 ) {
case V_54 :
case V_55 :
case V_56 :
case V_57 :
V_80 = F_45 ( V_39 , & V_112 , & V_113 , V_6 ) ;
break;
case V_19 :
V_80 = F_45 ( V_39 , & V_114 , & V_115 , V_6 ) ;
break;
case V_21 :
V_80 = F_45 ( V_39 , & V_116 , & V_117 , V_6 ) ;
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
V_121 -> V_64 . V_125 . V_126 = 2 ;
if ( V_121 -> V_64 . V_125 . V_127 >= 2 )
V_121 -> V_64 . V_125 . V_127 = 1 ;
strcpy ( V_121 -> V_64 . V_125 . V_128 , V_122 [ V_121 -> V_64 . V_125 . V_127 ] ) ;
return 0 ;
}
static int F_47 ( struct V_118 * V_119 , struct V_62 * V_63 )
{
struct V_5 * V_6 = F_48 ( V_119 ) ;
unsigned char V_16 = V_119 -> V_46 & 0xff ;
F_8 ( V_6 ) ;
V_63 -> V_64 . V_125 . V_127 [ 0 ] = F_5 ( V_6 , V_11 ) & V_16 ? 1 : 0 ;
F_11 ( V_6 ) ;
return 0 ;
}
static int F_49 ( struct V_118 * V_119 , struct V_62 * V_63 )
{
struct V_5 * V_6 = F_48 ( V_119 ) ;
unsigned char V_16 = V_119 -> V_46 & 0xff ;
int V_68 , V_129 ;
if ( V_119 -> V_46 & ( 1 << 31 ) )
return - V_130 ;
V_129 = V_63 -> V_64 . V_125 . V_127 [ 0 ] ? V_16 : 0 ;
F_8 ( V_6 ) ;
V_68 = F_5 ( V_6 , V_11 ) ;
V_129 |= V_68 & ~ V_16 ;
F_2 ( V_6 , V_11 , V_129 ) ;
F_11 ( V_6 ) ;
return V_68 != V_129 ;
}
static int F_50 ( struct V_118 * V_119 , struct V_62 * V_63 )
{
struct V_5 * V_6 = F_48 ( V_119 ) ;
struct V_27 * V_28 = V_6 -> V_28 ;
unsigned char V_4 ;
F_15 ( V_6 -> V_31 ) ;
if ( F_16 ( V_28 -> V_32 [ V_33 ] , & V_4 , 1 ) != 1 ) {
F_18 ( V_6 -> V_31 ) ;
return - V_37 ;
}
F_18 ( V_6 -> V_31 ) ;
V_63 -> V_64 . V_125 . V_127 [ 0 ] = V_4 & V_131 ? 1 : 0 ;
return 0 ;
}
static int F_51 ( struct V_118 * V_119 , struct V_62 * V_63 )
{
struct V_5 * V_6 = F_48 ( V_119 ) ;
struct V_27 * V_28 = V_6 -> V_28 ;
unsigned char V_4 , V_29 ;
F_15 ( V_6 -> V_31 ) ;
if ( F_16 ( V_28 -> V_32 [ V_33 ] , & V_4 , 1 ) != 1 ) {
F_18 ( V_6 -> V_31 ) ;
return - V_37 ;
}
V_29 = ( V_4 & ~ V_131 ) | ( V_63 -> V_64 . V_125 . V_127 [ 0 ] ? V_131 : 0 ) ;
if ( V_29 != V_4 && F_17 ( V_28 -> V_32 [ V_33 ] ,
& V_29 , 1 ) != 1 ) {
F_18 ( V_6 -> V_31 ) ;
return - V_37 ;
}
F_18 ( V_6 -> V_31 ) ;
return V_29 != V_4 ;
}
static int F_52 ( struct V_118 * V_119 , struct V_62 * V_63 )
{
struct V_5 * V_6 = F_48 ( V_119 ) ;
struct V_27 * V_28 = V_6 -> V_28 ;
int V_132 = F_53 ( V_119 , & V_63 -> V_79 ) ;
unsigned char V_4 ;
if ( F_14 ( V_132 < 0 || V_132 > 7 ) )
return 0 ;
F_15 ( V_6 -> V_31 ) ;
if ( F_16 ( V_28 -> V_32 [ V_92 ] , & V_4 , 1 ) != 1 ) {
F_18 ( V_6 -> V_31 ) ;
return - V_37 ;
}
V_63 -> V_64 . V_125 . V_127 [ 0 ] = V_4 & ( 1 << V_132 ) ? 0 : 1 ;
F_18 ( V_6 -> V_31 ) ;
return 0 ;
}
static int F_54 ( struct V_118 * V_119 , struct V_62 * V_63 )
{
struct V_5 * V_6 = F_48 ( V_119 ) ;
struct V_27 * V_28 = V_6 -> V_28 ;
int V_132 = F_53 ( V_119 , & V_63 -> V_79 ) ;
unsigned char V_4 , V_29 ;
if ( F_14 ( V_132 < 0 || V_132 > 7 ) )
return 0 ;
F_15 ( V_6 -> V_31 ) ;
if ( F_16 ( V_28 -> V_32 [ V_92 ] , & V_4 , 1 ) != 1 ) {
F_18 ( V_6 -> V_31 ) ;
return - V_37 ;
}
V_29 = ( V_4 & ~ ( 1 << V_132 ) ) | ( V_63 -> V_64 . V_125 . V_127 [ 0 ] ? 0 : ( 1 << V_132 ) ) ;
if ( V_29 != V_4 && F_17 ( V_28 -> V_32 [ V_92 ] ,
& V_29 , 1 ) != 1 ) {
F_18 ( V_6 -> V_31 ) ;
return - V_37 ;
}
F_18 ( V_6 -> V_31 ) ;
return V_29 != V_4 ;
}
static int F_55 ( struct V_118 * V_119 , struct V_62 * V_63 )
{
struct V_5 * V_6 = F_48 ( V_119 ) ;
struct V_27 * V_28 = V_6 -> V_28 ;
int V_133 = V_119 -> V_46 & 0xff ;
int V_134 = ( V_119 -> V_46 >> 8 ) & 1 ;
unsigned char V_4 [ 2 ] ;
F_15 ( V_6 -> V_31 ) ;
if ( F_16 ( V_28 -> V_32 [ V_61 ] , V_4 , 2 ) != 2 ) {
F_18 ( V_6 -> V_31 ) ;
return - V_37 ;
}
F_18 ( V_6 -> V_31 ) ;
V_4 [ 0 ] = ( V_4 [ V_133 >> 3 ] >> ( V_133 & 7 ) ) & 0x01 ;
if ( V_134 )
V_4 [ 0 ] ^= 0x01 ;
V_63 -> V_64 . integer . V_64 [ 0 ] = V_4 [ 0 ] ;
return 0 ;
}
static int F_56 ( struct V_118 * V_119 , struct V_62 * V_63 )
{
struct V_5 * V_6 = F_48 ( V_119 ) ;
struct V_27 * V_28 = V_6 -> V_28 ;
int V_133 = V_119 -> V_46 & 0xff ;
int V_134 = ( V_119 -> V_46 >> 8 ) & 1 ;
unsigned char V_4 [ 2 ] , V_29 [ 2 ] ;
int V_69 ;
F_15 ( V_6 -> V_31 ) ;
if ( F_16 ( V_28 -> V_32 [ V_61 ] , V_4 , 2 ) != 2 ) {
F_18 ( V_6 -> V_31 ) ;
return - V_37 ;
}
V_29 [ V_133 >> 3 ] = V_4 [ V_133 >> 3 ] & ~ ( 1 << ( V_133 & 7 ) ) ;
if ( V_134 ) {
if ( ! V_63 -> V_64 . integer . V_64 [ 0 ] )
V_29 [ V_133 >> 3 ] |= ( 1 << ( V_133 & 7 ) ) ;
} else {
if ( V_63 -> V_64 . integer . V_64 [ 0 ] )
V_29 [ V_133 >> 3 ] |= ( 1 << ( V_133 & 7 ) ) ;
}
V_69 = ( V_4 [ V_133 >> 3 ] != V_29 [ V_133 >> 3 ] ) ;
if ( V_69 &&
F_17 ( V_28 -> V_32 [ V_61 ] , V_4 , 2 ) != 2 ) {
F_18 ( V_6 -> V_31 ) ;
return - V_37 ;
}
F_18 ( V_6 -> V_31 ) ;
return V_69 ;
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
F_19 ( V_6 -> V_35 -> V_36 , L_13 ) ;
return - V_37 ;
}
F_18 ( V_6 -> V_31 ) ;
return V_136 ;
}
static int F_42 ( struct V_5 * V_6 , unsigned char V_135 , unsigned char V_4 )
{
unsigned char V_53 [ 2 ] ;
struct V_27 * V_28 = V_6 -> V_28 ;
F_15 ( V_6 -> V_31 ) ;
V_53 [ 0 ] = V_135 ;
V_53 [ 1 ] = V_4 ;
if ( F_17 ( V_28 -> V_32 [ V_88 ] , V_53 , 2 ) != 2 ) {
F_18 ( V_6 -> V_31 ) ;
return - V_37 ;
}
F_18 ( V_6 -> V_31 ) ;
return 0 ;
}
static int F_58 ( struct V_118 * V_119 , struct V_62 * V_63 )
{
struct V_5 * V_6 = F_48 ( V_119 ) ;
int V_133 = V_119 -> V_46 & 0xff ;
int V_134 = ( V_119 -> V_46 >> 8 ) & 1 ;
int V_4 ;
if ( ( V_4 = F_57 ( V_6 , V_137 ) ) < 0 )
return V_4 ;
V_4 = ( V_4 >> V_133 ) & 1 ;
if ( V_134 )
V_4 ^= 1 ;
V_63 -> V_64 . integer . V_64 [ 0 ] = V_4 ;
return 0 ;
}
static int F_59 ( struct V_118 * V_119 , struct V_62 * V_63 )
{
struct V_5 * V_6 = F_48 ( V_119 ) ;
int V_133 = V_119 -> V_46 & 0xff ;
int V_134 = ( V_119 -> V_46 >> 8 ) & 1 ;
int V_4 , V_29 ;
if ( ( V_4 = F_57 ( V_6 , V_137 ) ) < 0 )
return V_4 ;
V_29 = V_4 & ~ ( 1 << V_133 ) ;
if ( V_63 -> V_64 . integer . V_64 [ 0 ] )
V_29 |= ( 1 << V_133 ) ;
if ( V_134 )
V_29 ^= ( 1 << V_133 ) ;
if ( V_4 != V_29 ) {
F_42 ( V_6 , V_137 , ( unsigned char ) V_29 ) ;
return 1 ;
}
return 0 ;
}
static int F_60 ( struct V_118 * V_119 , struct V_120 * V_121 )
{
static const char * const V_122 [ 4 ] = {
L_14 , L_15 , L_16 , L_17
} ;
V_121 -> type = V_123 ;
V_121 -> V_124 = 1 ;
V_121 -> V_64 . V_125 . V_126 = 4 ;
if ( V_121 -> V_64 . V_125 . V_127 >= 4 )
V_121 -> V_64 . V_125 . V_127 = 1 ;
strcpy ( V_121 -> V_64 . V_125 . V_128 , V_122 [ V_121 -> V_64 . V_125 . V_127 ] ) ;
return 0 ;
}
static int F_61 ( struct V_118 * V_119 , struct V_62 * V_63 )
{
struct V_5 * V_6 = F_48 ( V_119 ) ;
int V_4 ;
if ( ( V_4 = F_57 ( V_6 , V_137 ) ) < 0 )
return V_4 ;
V_63 -> V_64 . integer . V_64 [ 0 ] = V_4 & 3 ;
return 0 ;
}
static int F_62 ( struct V_118 * V_119 , struct V_62 * V_63 )
{
struct V_5 * V_6 = F_48 ( V_119 ) ;
int V_4 , V_29 ;
if ( ( V_4 = F_57 ( V_6 , V_137 ) ) < 0 )
return V_4 ;
V_29 = V_4 & ~ 3 ;
V_29 |= ( V_63 -> V_64 . integer . V_64 [ 0 ] & 3 ) ;
if ( V_4 != V_29 ) {
F_42 ( V_6 , V_137 , ( unsigned char ) V_29 ) ;
return 1 ;
}
return 0 ;
}
static int F_63 ( struct V_5 * V_6 )
{
unsigned int V_138 ;
int V_80 ;
if ( V_6 -> V_96 == NULL ) {
V_80 = F_64 ( V_6 ) ;
if ( V_80 < 0 )
return V_80 ;
}
switch ( V_6 -> V_17 . V_18 ) {
case V_19 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_21 :
V_80 = F_65 ( V_6 ) ;
if ( V_80 < 0 )
return V_80 ;
break;
}
switch ( V_6 -> V_17 . V_18 ) {
case V_19 :
for ( V_138 = 0 ; V_138 < F_66 ( V_139 ) ; V_138 ++ ) {
V_80 = F_67 ( V_6 -> V_35 , F_68 ( & V_139 [ V_138 ] , V_6 ) ) ;
if ( V_80 < 0 )
return V_80 ;
}
break;
case V_54 :
case V_55 :
case V_56 :
case V_57 :
V_80 = F_67 ( V_6 -> V_35 , F_68 ( & V_140 , V_6 ) ) ;
if ( V_80 < 0 )
return V_80 ;
V_80 = F_67 ( V_6 -> V_35 , F_68 ( & V_141 , V_6 ) ) ;
if ( V_80 < 0 )
return V_80 ;
break;
case V_60 :
for ( V_138 = 0 ; V_138 < F_66 ( V_142 ) ; V_138 ++ ) {
V_80 = F_67 ( V_6 -> V_35 , F_68 ( & V_142 [ V_138 ] , V_6 ) ) ;
if ( V_80 < 0 )
return V_80 ;
}
break;
case V_21 :
for ( V_138 = 0 ; V_138 < F_66 ( V_143 ) ; V_138 ++ ) {
V_80 = F_67 ( V_6 -> V_35 , F_68 ( & V_143 [ V_138 ] , V_6 ) ) ;
if ( V_80 < 0 )
return V_80 ;
}
break;
}
return 0 ;
}
