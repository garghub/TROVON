static void F_1 ( T_1 V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
unsigned int V_4 = V_3 -> V_5 -> V_6 [ 0 ] -> V_7 ;
if ( F_2 ( V_8 , & ( V_3 -> V_9 ) ) ) {
F_3 ( V_8 , & ( V_3 -> V_9 ) ) ;
F_4 ( & ( V_3 -> V_10 ) , V_11 + V_12 / 10 ) ;
}
F_5 ( 0x08 | 0x20 , V_4 + 0x30 ) ;
}
static void F_6 ( struct V_2 * V_3 )
{
unsigned int V_4 = V_3 -> V_5 -> V_6 [ 0 ] -> V_7 ;
if ( F_7 ( & ( V_3 -> V_10 ) ) )
return;
F_8 ( V_8 , & ( V_3 -> V_9 ) ) ;
if ( F_2 ( V_13 , & ( V_3 -> V_9 ) ) ) {
F_5 ( 0x18 | 0x60 , V_4 + 0x30 ) ;
} else {
F_5 ( 0x00 , V_4 + 0x30 ) ;
}
F_4 ( & ( V_3 -> V_10 ) , V_11 + V_12 / 10 ) ;
}
static int F_9 ( unsigned int V_4 , unsigned int V_14 , T_2 * V_15 , int V_16 )
{
int V_17 , V_18 ;
V_18 = ( V_16 > 15 ) ? 15 : V_16 ;
F_10 ( V_18 , V_4 + V_14 ) ;
for ( V_17 = 0 ; V_17 < V_18 ; V_17 ++ )
F_10 ( V_15 [ V_17 ] , V_4 + V_14 + V_17 + 1 ) ;
return V_18 ;
}
static void F_11 ( struct V_2 * V_3 )
{
if ( ! V_3 ) {
F_12 ( L_1 ) ;
return;
}
if ( ! F_2 ( V_19 , & ( V_3 -> V_20 ) ) )
return;
if ( F_13 ( V_21 , & ( V_3 -> V_20 ) ) ) {
F_8 ( V_22 , & ( V_3 -> V_20 ) ) ;
return;
}
do {
unsigned int V_4 = V_3 -> V_5 -> V_6 [ 0 ] -> V_7 ;
unsigned int V_14 ;
unsigned char V_23 ;
unsigned long V_24 ;
register struct V_25 * V_26 ;
int V_16 ;
F_3 ( V_22 , & ( V_3 -> V_20 ) ) ;
if ( ! F_14 ( V_3 -> V_5 ) )
return;
if ( F_2 ( V_27 , & ( V_3 -> V_20 ) ) ) {
if ( ! F_2 ( V_28 , & ( V_3 -> V_20 ) ) )
break;
V_14 = 0x10 ;
V_23 = V_29 ;
V_24 = V_28 ;
} else {
if ( ! F_2 ( V_30 , & ( V_3 -> V_20 ) ) )
break;
V_14 = 0x00 ;
V_23 = V_31 ;
V_24 = V_30 ;
}
V_26 = F_15 ( & ( V_3 -> V_32 ) ) ;
if ( ! V_26 )
break;
if ( F_16 ( V_26 ) & 0x80 ) {
V_3 -> V_33 |= V_34 ;
F_5 ( V_3 -> V_33 , V_4 + V_35 ) ;
}
F_6 ( V_3 ) ;
V_16 = F_9 ( V_4 , V_14 , V_26 -> V_36 , V_26 -> V_16 ) ;
F_10 ( V_23 , V_4 + V_37 ) ;
F_3 ( V_24 , & ( V_3 -> V_20 ) ) ;
if ( F_16 ( V_26 ) & 0x80 ) {
F_17 ( V_38 ) ;
F_18 ( V_39 ) ;
unsigned char V_40 ;
switch ( F_16 ( V_26 ) ) {
case V_41 :
V_40 = V_42 ;
break;
case V_43 :
V_40 = V_44 ;
break;
case V_45 :
V_40 = V_46 ;
break;
case V_47 :
default:
V_40 = V_48 ;
break;
}
F_19 ( & V_38 , & V_39 , V_49 ) ;
F_20 ( V_12 / 10 ) ;
F_21 ( & V_38 , & V_39 ) ;
V_3 -> V_33 &= ~ 0x03 ;
V_3 -> V_33 |= V_40 ;
F_5 ( V_3 -> V_33 , V_4 + V_35 ) ;
V_3 -> V_33 &= ~ V_34 ;
F_5 ( V_3 -> V_33 , V_4 + V_35 ) ;
F_19 ( & V_38 , & V_39 , V_49 ) ;
F_20 ( V_12 ) ;
F_21 ( & V_38 , & V_39 ) ;
}
if ( V_16 == V_26 -> V_16 ) {
F_22 ( V_26 ) ;
} else {
F_23 ( V_26 , V_16 ) ;
F_24 ( & ( V_3 -> V_32 ) , V_26 ) ;
}
V_3 -> V_50 -> V_51 . V_52 += V_16 ;
F_25 ( V_27 , & ( V_3 -> V_20 ) ) ;
} while ( F_2 ( V_22 , & ( V_3 -> V_20 ) ) );
F_3 ( V_21 , & ( V_3 -> V_20 ) ) ;
}
static int F_26 ( unsigned int V_4 , unsigned int V_14 , T_2 * V_15 , int V_53 )
{
int V_17 , V_54 , V_16 ;
F_5 ( V_55 , V_4 + V_37 ) ;
V_16 = F_27 ( V_4 + V_14 ) ;
V_54 = 0 ;
V_17 = 1 ;
while ( V_54 < V_16 ) {
if ( V_17 == 16 ) {
F_5 ( V_56 , V_4 + V_37 ) ;
V_17 = 0 ;
}
V_15 [ V_54 ] = F_27 ( V_4 + V_14 + V_17 ) ;
V_54 ++ ;
V_17 ++ ;
}
return V_16 ;
}
static void F_28 ( struct V_2 * V_3 ,
unsigned int V_14 )
{
unsigned int V_4 ;
unsigned char V_15 [ 31 ] ;
int V_17 , V_16 ;
if ( ! V_3 ) {
F_12 ( L_1 ) ;
return;
}
V_4 = V_3 -> V_5 -> V_6 [ 0 ] -> V_7 ;
if ( F_2 ( V_19 , & ( V_3 -> V_20 ) ) )
F_6 ( V_3 ) ;
V_16 = F_26 ( V_4 , V_14 , V_15 , sizeof( V_15 ) ) ;
for ( V_17 = 0 ; V_17 < V_16 ; V_17 ++ ) {
if ( ! V_3 -> V_57 ) {
V_3 -> V_58 = V_59 ;
V_3 -> V_60 = 0 ;
V_3 -> V_57 = F_29 ( V_61 , V_62 ) ;
if ( ! V_3 -> V_57 ) {
F_12 ( L_2 ) ;
return;
}
}
if ( V_3 -> V_58 == V_59 ) {
F_16 ( V_3 -> V_57 ) = V_15 [ V_17 ] ;
switch ( F_16 ( V_3 -> V_57 ) ) {
case 0x00 :
if ( V_14 != 0x00 ) {
F_8 ( V_30 , & ( V_3 -> V_20 ) ) ;
F_8 ( V_28 , & ( V_3 -> V_20 ) ) ;
F_8 ( V_19 , & ( V_3 -> V_20 ) ) ;
F_11 ( V_3 ) ;
}
F_22 ( V_3 -> V_57 ) ;
V_3 -> V_57 = NULL ;
break;
case V_63 :
V_3 -> V_58 = V_64 ;
V_3 -> V_60 = V_65 ;
break;
case V_66 :
V_3 -> V_58 = V_67 ;
V_3 -> V_60 = V_68 ;
break;
case V_69 :
V_3 -> V_58 = V_70 ;
V_3 -> V_60 = V_71 ;
break;
default:
F_12 ( L_3 ,
F_16 ( V_3 -> V_57 ) ) ;
V_3 -> V_50 -> V_51 . V_72 ++ ;
F_22 ( V_3 -> V_57 ) ;
V_3 -> V_57 = NULL ;
break;
}
} else {
F_30 ( V_3 -> V_57 , V_15 [ V_17 ] ) ;
V_3 -> V_60 -- ;
if ( V_3 -> V_60 == 0 ) {
int V_73 ;
struct V_74 * V_75 ;
struct V_76 * V_77 ;
struct V_78 * V_79 ;
switch ( V_3 -> V_58 ) {
case V_64 :
V_75 = V_74 ( V_3 -> V_57 ) ;
V_3 -> V_58 = V_80 ;
V_3 -> V_60 = V_75 -> V_81 ;
break;
case V_67 :
V_77 = V_76 ( V_3 -> V_57 ) ;
V_73 = F_31 ( V_77 -> V_73 ) ;
V_3 -> V_58 = V_80 ;
V_3 -> V_60 = V_73 ;
break;
case V_70 :
V_79 = V_78 ( V_3 -> V_57 ) ;
V_3 -> V_58 = V_80 ;
V_3 -> V_60 = V_79 -> V_73 ;
break;
case V_80 :
F_32 ( V_3 -> V_50 , V_3 -> V_57 ) ;
V_3 -> V_57 = NULL ;
break;
}
}
}
}
V_3 -> V_50 -> V_51 . V_82 += V_16 ;
}
static T_3 F_33 ( int V_83 , void * V_84 )
{
struct V_2 * V_3 = V_84 ;
unsigned int V_4 ;
unsigned char V_85 ;
if ( ! V_3 || ! V_3 -> V_50 )
return V_86 ;
if ( ! F_2 ( V_87 , & ( V_3 -> V_9 ) ) )
return V_88 ;
V_4 = V_3 -> V_5 -> V_6 [ 0 ] -> V_7 ;
F_34 ( & ( V_3 -> V_89 ) ) ;
V_3 -> V_33 &= ~ V_90 ;
F_5 ( V_3 -> V_33 , V_4 + V_35 ) ;
V_85 = F_27 ( V_4 + V_91 ) ;
if ( ( V_85 != 0x00 ) && ( V_85 != 0xff ) ) {
if ( V_85 & 0x04 ) {
F_28 ( V_3 , 0x00 ) ;
F_5 ( 0x04 , V_4 + V_91 ) ;
F_5 ( V_92 , V_4 + V_37 ) ;
}
if ( V_85 & 0x08 ) {
F_28 ( V_3 , 0x10 ) ;
F_5 ( 0x08 , V_4 + V_91 ) ;
F_5 ( V_93 , V_4 + V_37 ) ;
}
if ( V_85 & 0x01 ) {
F_8 ( V_30 , & ( V_3 -> V_20 ) ) ;
F_5 ( 0x01 , V_4 + V_91 ) ;
F_11 ( V_3 ) ;
}
if ( V_85 & 0x02 ) {
F_8 ( V_28 , & ( V_3 -> V_20 ) ) ;
F_5 ( 0x02 , V_4 + V_91 ) ;
F_11 ( V_3 ) ;
}
}
V_3 -> V_33 |= V_90 ;
F_5 ( V_3 -> V_33 , V_4 + V_35 ) ;
F_35 ( & ( V_3 -> V_89 ) ) ;
return V_88 ;
}
static int F_36 ( struct V_94 * V_50 , int V_95 )
{
struct V_2 * V_3 = F_37 ( V_50 ) ;
struct V_25 * V_26 ;
unsigned char V_96 [] = { V_97 , 0x09 , 0xfc , 0x01 , 0x03 } ;
V_26 = F_29 ( V_61 , V_62 ) ;
if ( ! V_26 ) {
F_12 ( L_2 ) ;
return - 1 ;
}
switch ( V_95 ) {
case 460800 :
V_96 [ 4 ] = 0x00 ;
F_16 ( V_26 ) = V_41 ;
break;
case 230400 :
V_96 [ 4 ] = 0x01 ;
F_16 ( V_26 ) = V_43 ;
break;
case 115200 :
V_96 [ 4 ] = 0x02 ;
F_16 ( V_26 ) = V_45 ;
break;
case 57600 :
default:
V_96 [ 4 ] = 0x03 ;
F_16 ( V_26 ) = V_47 ;
break;
}
F_38 ( V_26 , V_96 , sizeof( V_96 ) ) ;
F_39 ( & ( V_3 -> V_32 ) , V_26 ) ;
F_11 ( V_3 ) ;
return 0 ;
}
static int F_40 ( struct V_94 * V_50 )
{
struct V_2 * V_3 = F_37 ( V_50 ) ;
F_41 ( & ( V_3 -> V_32 ) ) ;
return 0 ;
}
static int F_42 ( struct V_94 * V_50 )
{
struct V_2 * V_3 = F_37 ( V_50 ) ;
unsigned int V_4 = V_3 -> V_5 -> V_6 [ 0 ] -> V_7 ;
if ( F_2 ( V_98 , & ( V_3 -> V_9 ) ) )
F_36 ( V_50 , V_99 ) ;
F_5 ( 0x08 | 0x20 , V_4 + 0x30 ) ;
return 0 ;
}
static int F_43 ( struct V_94 * V_50 )
{
struct V_2 * V_3 = F_37 ( V_50 ) ;
unsigned int V_4 = V_3 -> V_5 -> V_6 [ 0 ] -> V_7 ;
F_40 ( V_50 ) ;
F_44 ( & ( V_3 -> V_10 ) ) ;
F_5 ( 0x00 , V_4 + 0x30 ) ;
return 0 ;
}
static int F_45 ( struct V_94 * V_50 , struct V_25 * V_26 )
{
struct V_2 * V_3 = F_37 ( V_50 ) ;
switch ( F_16 ( V_26 ) ) {
case V_97 :
V_50 -> V_51 . V_100 ++ ;
break;
case V_66 :
V_50 -> V_51 . V_101 ++ ;
break;
case V_69 :
V_50 -> V_51 . V_102 ++ ;
break;
}
memcpy ( F_46 ( V_26 , 1 ) , & F_16 ( V_26 ) , 1 ) ;
F_39 ( & ( V_3 -> V_32 ) , V_26 ) ;
F_11 ( V_3 ) ;
return 0 ;
}
static int F_47 ( struct V_2 * V_3 )
{
unsigned int V_4 = V_3 -> V_5 -> V_6 [ 0 ] -> V_7 ;
struct V_94 * V_50 ;
unsigned char V_103 ;
F_48 ( & ( V_3 -> V_89 ) ) ;
F_49 ( & ( V_3 -> V_10 ) , & F_1 ,
( T_1 ) V_3 ) ;
F_50 ( & ( V_3 -> V_32 ) ) ;
V_3 -> V_58 = V_59 ;
V_3 -> V_60 = 0 ;
V_3 -> V_57 = NULL ;
V_50 = F_51 () ;
if ( ! V_50 ) {
F_12 ( L_4 ) ;
return - V_104 ;
}
V_3 -> V_50 = V_50 ;
V_50 -> V_105 = V_106 ;
F_52 ( V_50 , V_3 ) ;
F_53 ( V_50 , & V_3 -> V_5 -> V_107 ) ;
V_50 -> V_108 = F_42 ;
V_50 -> V_109 = F_43 ;
V_50 -> V_110 = F_40 ;
V_50 -> V_111 = F_45 ;
V_103 = F_27 ( V_4 + 0x30 ) ;
if ( ( V_103 & 0x0f ) == 0x02 )
F_8 ( V_98 , & ( V_3 -> V_9 ) ) ;
if ( V_103 & 0x10 )
F_8 ( V_112 , & ( V_3 -> V_9 ) ) ;
if ( V_103 & 0x20 )
F_8 ( V_13 , & ( V_3 -> V_9 ) ) ;
V_3 -> V_33 = V_113 | V_114 ;
F_5 ( V_3 -> V_33 , V_4 + V_35 ) ;
F_5 ( 0x80 , V_4 + 0x30 ) ;
F_54 ( 10 ) ;
F_5 ( 0x00 , V_4 + 0x30 ) ;
V_3 -> V_33 = V_115 | V_116 ;
F_5 ( V_3 -> V_33 , V_4 + V_35 ) ;
F_5 ( 0xff , V_4 + V_91 ) ;
V_3 -> V_33 |= V_90 ;
F_5 ( V_3 -> V_33 , V_4 + V_35 ) ;
if ( ( V_103 & 0x0f ) == 0x03 ) {
V_3 -> V_33 |= V_34 ;
F_5 ( V_3 -> V_33 , V_4 + V_35 ) ;
V_3 -> V_33 |= 0x03 ;
F_5 ( V_3 -> V_33 , V_4 + V_35 ) ;
V_3 -> V_33 &= ~ V_34 ;
F_5 ( V_3 -> V_33 , V_4 + V_35 ) ;
F_8 ( V_30 , & ( V_3 -> V_20 ) ) ;
F_8 ( V_28 , & ( V_3 -> V_20 ) ) ;
F_8 ( V_19 , & ( V_3 -> V_20 ) ) ;
}
F_5 ( V_92 , V_4 + V_37 ) ;
F_5 ( V_93 , V_4 + V_37 ) ;
F_8 ( V_87 , & ( V_3 -> V_9 ) ) ;
F_41 ( & ( V_3 -> V_32 ) ) ;
F_5 ( ( 0x0f << V_117 ) | 1 , V_4 + V_118 ) ;
F_54 ( 1250 ) ;
if ( F_55 ( V_50 ) < 0 ) {
F_12 ( L_5 ) ;
V_3 -> V_50 = NULL ;
F_56 ( V_50 ) ;
return - V_119 ;
}
return 0 ;
}
static int F_57 ( struct V_2 * V_3 )
{
unsigned int V_4 = V_3 -> V_5 -> V_6 [ 0 ] -> V_7 ;
struct V_94 * V_50 = V_3 -> V_50 ;
if ( ! V_50 )
return - V_119 ;
F_43 ( V_50 ) ;
F_3 ( V_87 , & ( V_3 -> V_9 ) ) ;
V_3 -> V_33 = V_113 | V_114 ;
F_5 ( V_3 -> V_33 , V_4 + V_35 ) ;
F_5 ( 0x80 , V_4 + 0x30 ) ;
F_58 ( V_50 ) ;
F_56 ( V_50 ) ;
return 0 ;
}
static int F_59 ( struct V_120 * V_121 )
{
struct V_2 * V_3 ;
V_3 = F_60 ( & V_121 -> V_107 , sizeof( * V_3 ) , V_122 ) ;
if ( ! V_3 )
return - V_104 ;
V_3 -> V_5 = V_121 ;
V_121 -> V_123 = V_3 ;
V_121 -> V_124 |= V_125 ;
return F_61 ( V_121 ) ;
}
static void F_62 ( struct V_120 * V_121 )
{
F_63 ( V_121 ) ;
}
static int F_61 ( struct V_120 * V_121 )
{
struct V_2 * V_3 = V_121 -> V_123 ;
int V_17 , V_54 ;
V_121 -> V_126 = 0x20 ;
V_121 -> V_6 [ 0 ] -> V_127 |= V_128 ;
V_121 -> V_6 [ 0 ] -> V_129 = 64 ;
V_121 -> V_130 = 6 ;
for ( V_54 = 0 ; V_54 < 0x400 ; V_54 += 0x40 ) {
V_121 -> V_6 [ 0 ] -> V_7 = V_54 ^ 0x300 ;
V_17 = F_64 ( V_121 ) ;
if ( V_17 == 0 )
break;
}
if ( V_17 != 0 )
goto V_131;
V_17 = F_65 ( V_121 , F_33 ) ;
if ( V_17 != 0 )
goto V_131;
V_17 = F_66 ( V_121 ) ;
if ( V_17 != 0 )
goto V_131;
if ( F_47 ( V_3 ) != 0 )
goto V_131;
return 0 ;
V_131:
F_63 ( V_121 ) ;
return - V_119 ;
}
static void F_63 ( struct V_120 * V_121 )
{
struct V_2 * V_3 = V_121 -> V_123 ;
F_57 ( V_3 ) ;
F_44 ( & ( V_3 -> V_10 ) ) ;
F_67 ( V_121 ) ;
}
