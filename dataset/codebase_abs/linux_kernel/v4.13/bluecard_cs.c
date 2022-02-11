static void F_1 ( T_1 V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
unsigned int V_4 = V_3 -> V_5 -> V_6 [ 0 ] -> V_7 ;
if ( ! F_2 ( V_8 , & ( V_3 -> V_9 ) ) )
return;
if ( F_2 ( V_10 , & ( V_3 -> V_9 ) ) ) {
F_3 ( 0x08 | 0x20 , V_4 + 0x30 ) ;
} else {
F_3 ( 0x00 , V_4 + 0x30 ) ;
}
}
static void F_4 ( struct V_2 * V_3 )
{
unsigned int V_4 = V_3 -> V_5 -> V_6 [ 0 ] -> V_7 ;
if ( ! F_2 ( V_8 , & ( V_3 -> V_9 ) ) )
return;
if ( F_2 ( V_10 , & ( V_3 -> V_9 ) ) ) {
F_3 ( 0x10 | 0x40 , V_4 + 0x30 ) ;
F_5 ( & ( V_3 -> V_11 ) , V_12 + V_13 / 4 ) ;
} else {
F_3 ( 0x08 | 0x20 , V_4 + 0x30 ) ;
F_5 ( & ( V_3 -> V_11 ) , V_12 + V_13 / 2 ) ;
}
}
static int F_6 ( unsigned int V_4 , unsigned int V_14 , T_2 * V_15 , int V_16 )
{
int V_17 , V_18 ;
V_18 = ( V_16 > 15 ) ? 15 : V_16 ;
F_7 ( V_18 , V_4 + V_14 ) ;
for ( V_17 = 0 ; V_17 < V_18 ; V_17 ++ )
F_7 ( V_15 [ V_17 ] , V_4 + V_14 + V_17 + 1 ) ;
return V_18 ;
}
static void F_8 ( struct V_2 * V_3 )
{
if ( ! V_3 ) {
F_9 ( L_1 ) ;
return;
}
if ( ! F_2 ( V_19 , & ( V_3 -> V_20 ) ) )
return;
if ( F_10 ( V_21 , & ( V_3 -> V_20 ) ) ) {
F_11 ( V_22 , & ( V_3 -> V_20 ) ) ;
return;
}
do {
unsigned int V_4 = V_3 -> V_5 -> V_6 [ 0 ] -> V_7 ;
unsigned int V_14 ;
unsigned char V_23 ;
unsigned long V_24 ;
register struct V_25 * V_26 ;
int V_16 ;
F_12 ( V_22 , & ( V_3 -> V_20 ) ) ;
if ( ! F_13 ( V_3 -> V_5 ) )
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
V_26 = F_14 ( & ( V_3 -> V_32 ) ) ;
if ( ! V_26 )
break;
if ( F_15 ( V_26 ) & 0x80 ) {
V_3 -> V_33 |= V_34 ;
F_3 ( V_3 -> V_33 , V_4 + V_35 ) ;
}
F_4 ( V_3 ) ;
V_16 = F_6 ( V_4 , V_14 , V_26 -> V_36 , V_26 -> V_16 ) ;
F_7 ( V_23 , V_4 + V_37 ) ;
F_12 ( V_24 , & ( V_3 -> V_20 ) ) ;
if ( F_15 ( V_26 ) & 0x80 ) {
F_16 ( V_38 ) ;
F_17 ( V_39 ) ;
unsigned char V_40 ;
switch ( F_15 ( V_26 ) ) {
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
F_18 ( & V_38 , & V_39 , V_49 ) ;
F_19 ( V_13 / 10 ) ;
F_20 ( & V_38 , & V_39 ) ;
V_3 -> V_33 &= ~ 0x03 ;
V_3 -> V_33 |= V_40 ;
F_3 ( V_3 -> V_33 , V_4 + V_35 ) ;
V_3 -> V_33 &= ~ V_34 ;
F_3 ( V_3 -> V_33 , V_4 + V_35 ) ;
F_18 ( & V_38 , & V_39 , V_49 ) ;
F_19 ( V_13 ) ;
F_20 ( & V_38 , & V_39 ) ;
}
if ( V_16 == V_26 -> V_16 ) {
F_21 ( V_26 ) ;
} else {
F_22 ( V_26 , V_16 ) ;
F_23 ( & ( V_3 -> V_32 ) , V_26 ) ;
}
V_3 -> V_50 -> V_51 . V_52 += V_16 ;
F_24 ( V_27 , & ( V_3 -> V_20 ) ) ;
} while ( F_2 ( V_22 , & ( V_3 -> V_20 ) ) );
F_12 ( V_21 , & ( V_3 -> V_20 ) ) ;
}
static int F_25 ( unsigned int V_4 , unsigned int V_14 , T_2 * V_15 , int V_53 )
{
int V_17 , V_54 , V_16 ;
F_3 ( V_55 , V_4 + V_37 ) ;
V_16 = F_26 ( V_4 + V_14 ) ;
V_54 = 0 ;
V_17 = 1 ;
while ( V_54 < V_16 ) {
if ( V_17 == 16 ) {
F_3 ( V_56 , V_4 + V_37 ) ;
V_17 = 0 ;
}
V_15 [ V_54 ] = F_26 ( V_4 + V_14 + V_17 ) ;
V_54 ++ ;
V_17 ++ ;
}
return V_16 ;
}
static void F_27 ( struct V_2 * V_3 ,
unsigned int V_14 )
{
unsigned int V_4 ;
unsigned char V_15 [ 31 ] ;
int V_17 , V_16 ;
if ( ! V_3 ) {
F_9 ( L_1 ) ;
return;
}
V_4 = V_3 -> V_5 -> V_6 [ 0 ] -> V_7 ;
if ( F_2 ( V_19 , & ( V_3 -> V_20 ) ) )
F_4 ( V_3 ) ;
V_16 = F_25 ( V_4 , V_14 , V_15 , sizeof( V_15 ) ) ;
for ( V_17 = 0 ; V_17 < V_16 ; V_17 ++ ) {
if ( ! V_3 -> V_57 ) {
V_3 -> V_58 = V_59 ;
V_3 -> V_60 = 0 ;
V_3 -> V_57 = F_28 ( V_61 , V_62 ) ;
if ( ! V_3 -> V_57 ) {
F_9 ( L_2 ) ;
return;
}
}
if ( V_3 -> V_58 == V_59 ) {
F_15 ( V_3 -> V_57 ) = V_15 [ V_17 ] ;
switch ( F_15 ( V_3 -> V_57 ) ) {
case 0x00 :
if ( V_14 != 0x00 ) {
F_11 ( V_30 , & ( V_3 -> V_20 ) ) ;
F_11 ( V_28 , & ( V_3 -> V_20 ) ) ;
F_11 ( V_19 , & ( V_3 -> V_20 ) ) ;
F_8 ( V_3 ) ;
}
F_21 ( V_3 -> V_57 ) ;
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
F_9 ( L_3 ,
F_15 ( V_3 -> V_57 ) ) ;
V_3 -> V_50 -> V_51 . V_72 ++ ;
F_21 ( V_3 -> V_57 ) ;
V_3 -> V_57 = NULL ;
break;
}
} else {
F_29 ( V_3 -> V_57 , V_15 [ V_17 ] ) ;
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
V_73 = F_30 ( V_77 -> V_73 ) ;
V_3 -> V_58 = V_80 ;
V_3 -> V_60 = V_73 ;
break;
case V_70 :
V_79 = V_78 ( V_3 -> V_57 ) ;
V_3 -> V_58 = V_80 ;
V_3 -> V_60 = V_79 -> V_73 ;
break;
case V_80 :
F_31 ( V_3 -> V_50 , V_3 -> V_57 ) ;
V_3 -> V_57 = NULL ;
break;
}
}
}
}
V_3 -> V_50 -> V_51 . V_82 += V_16 ;
}
static T_3 F_32 ( int V_83 , void * V_84 )
{
struct V_2 * V_3 = V_84 ;
unsigned int V_4 ;
unsigned char V_85 ;
if ( ! V_3 || ! V_3 -> V_50 )
return V_86 ;
if ( ! F_2 ( V_87 , & ( V_3 -> V_9 ) ) )
return V_88 ;
V_4 = V_3 -> V_5 -> V_6 [ 0 ] -> V_7 ;
F_33 ( & ( V_3 -> V_89 ) ) ;
V_3 -> V_33 &= ~ V_90 ;
F_3 ( V_3 -> V_33 , V_4 + V_35 ) ;
V_85 = F_26 ( V_4 + V_91 ) ;
if ( ( V_85 != 0x00 ) && ( V_85 != 0xff ) ) {
if ( V_85 & 0x04 ) {
F_27 ( V_3 , 0x00 ) ;
F_3 ( 0x04 , V_4 + V_91 ) ;
F_3 ( V_92 , V_4 + V_37 ) ;
}
if ( V_85 & 0x08 ) {
F_27 ( V_3 , 0x10 ) ;
F_3 ( 0x08 , V_4 + V_91 ) ;
F_3 ( V_93 , V_4 + V_37 ) ;
}
if ( V_85 & 0x01 ) {
F_11 ( V_30 , & ( V_3 -> V_20 ) ) ;
F_3 ( 0x01 , V_4 + V_91 ) ;
F_8 ( V_3 ) ;
}
if ( V_85 & 0x02 ) {
F_11 ( V_28 , & ( V_3 -> V_20 ) ) ;
F_3 ( 0x02 , V_4 + V_91 ) ;
F_8 ( V_3 ) ;
}
}
V_3 -> V_33 |= V_90 ;
F_3 ( V_3 -> V_33 , V_4 + V_35 ) ;
F_34 ( & ( V_3 -> V_89 ) ) ;
return V_88 ;
}
static int F_35 ( struct V_94 * V_50 , int V_95 )
{
struct V_2 * V_3 = F_36 ( V_50 ) ;
struct V_25 * V_26 ;
unsigned char V_96 [] = { V_97 , 0x09 , 0xfc , 0x01 , 0x03 } ;
V_26 = F_28 ( V_61 , V_62 ) ;
if ( ! V_26 ) {
F_9 ( L_2 ) ;
return - 1 ;
}
switch ( V_95 ) {
case 460800 :
V_96 [ 4 ] = 0x00 ;
F_15 ( V_26 ) = V_41 ;
break;
case 230400 :
V_96 [ 4 ] = 0x01 ;
F_15 ( V_26 ) = V_43 ;
break;
case 115200 :
V_96 [ 4 ] = 0x02 ;
F_15 ( V_26 ) = V_45 ;
break;
case 57600 :
default:
V_96 [ 4 ] = 0x03 ;
F_15 ( V_26 ) = V_47 ;
break;
}
F_37 ( V_26 , V_96 , sizeof( V_96 ) ) ;
F_38 ( & ( V_3 -> V_32 ) , V_26 ) ;
F_8 ( V_3 ) ;
return 0 ;
}
static int F_39 ( struct V_94 * V_50 )
{
struct V_2 * V_3 = F_36 ( V_50 ) ;
F_40 ( & ( V_3 -> V_32 ) ) ;
return 0 ;
}
static int F_41 ( struct V_94 * V_50 )
{
struct V_2 * V_3 = F_36 ( V_50 ) ;
if ( F_2 ( V_8 , & ( V_3 -> V_9 ) ) )
F_35 ( V_50 , V_98 ) ;
if ( F_2 ( V_8 , & ( V_3 -> V_9 ) ) ) {
unsigned int V_4 = V_3 -> V_5 -> V_6 [ 0 ] -> V_7 ;
F_3 ( 0x08 | 0x20 , V_4 + 0x30 ) ;
}
return 0 ;
}
static int F_42 ( struct V_94 * V_50 )
{
struct V_2 * V_3 = F_36 ( V_50 ) ;
F_39 ( V_50 ) ;
if ( F_2 ( V_8 , & ( V_3 -> V_9 ) ) ) {
unsigned int V_4 = V_3 -> V_5 -> V_6 [ 0 ] -> V_7 ;
F_3 ( 0x00 , V_4 + 0x30 ) ;
}
return 0 ;
}
static int F_43 ( struct V_94 * V_50 , struct V_25 * V_26 )
{
struct V_2 * V_3 = F_36 ( V_50 ) ;
switch ( F_15 ( V_26 ) ) {
case V_97 :
V_50 -> V_51 . V_99 ++ ;
break;
case V_66 :
V_50 -> V_51 . V_100 ++ ;
break;
case V_69 :
V_50 -> V_51 . V_101 ++ ;
break;
}
memcpy ( F_44 ( V_26 , 1 ) , & F_15 ( V_26 ) , 1 ) ;
F_38 ( & ( V_3 -> V_32 ) , V_26 ) ;
F_8 ( V_3 ) ;
return 0 ;
}
static int F_45 ( struct V_2 * V_3 )
{
unsigned int V_4 = V_3 -> V_5 -> V_6 [ 0 ] -> V_7 ;
struct V_94 * V_50 ;
unsigned char V_102 ;
F_46 ( & ( V_3 -> V_89 ) ) ;
F_47 ( & ( V_3 -> V_11 ) , & F_1 ,
( T_1 ) V_3 ) ;
F_48 ( & ( V_3 -> V_32 ) ) ;
V_3 -> V_58 = V_59 ;
V_3 -> V_60 = 0 ;
V_3 -> V_57 = NULL ;
V_50 = F_49 () ;
if ( ! V_50 ) {
F_9 ( L_4 ) ;
return - V_103 ;
}
V_3 -> V_50 = V_50 ;
V_50 -> V_104 = V_105 ;
F_50 ( V_50 , V_3 ) ;
F_51 ( V_50 , & V_3 -> V_5 -> V_106 ) ;
V_50 -> V_107 = F_41 ;
V_50 -> V_108 = F_42 ;
V_50 -> V_109 = F_39 ;
V_50 -> V_110 = F_43 ;
V_102 = F_26 ( V_4 + 0x30 ) ;
if ( ( V_102 & 0x0f ) == 0x02 )
F_11 ( V_8 , & ( V_3 -> V_9 ) ) ;
if ( V_102 & 0x10 )
F_11 ( V_111 , & ( V_3 -> V_9 ) ) ;
if ( V_102 & 0x20 )
F_11 ( V_10 , & ( V_3 -> V_9 ) ) ;
V_3 -> V_33 = V_112 | V_113 ;
F_3 ( V_3 -> V_33 , V_4 + V_35 ) ;
F_3 ( 0x80 , V_4 + 0x30 ) ;
F_52 ( 10 ) ;
F_3 ( 0x00 , V_4 + 0x30 ) ;
V_3 -> V_33 = V_114 | V_115 ;
F_3 ( V_3 -> V_33 , V_4 + V_35 ) ;
F_3 ( 0xff , V_4 + V_91 ) ;
V_3 -> V_33 |= V_90 ;
F_3 ( V_3 -> V_33 , V_4 + V_35 ) ;
if ( ( V_102 & 0x0f ) == 0x03 ) {
V_3 -> V_33 |= V_34 ;
F_3 ( V_3 -> V_33 , V_4 + V_35 ) ;
V_3 -> V_33 |= 0x03 ;
F_3 ( V_3 -> V_33 , V_4 + V_35 ) ;
V_3 -> V_33 &= ~ V_34 ;
F_3 ( V_3 -> V_33 , V_4 + V_35 ) ;
F_11 ( V_30 , & ( V_3 -> V_20 ) ) ;
F_11 ( V_28 , & ( V_3 -> V_20 ) ) ;
F_11 ( V_19 , & ( V_3 -> V_20 ) ) ;
}
F_3 ( V_92 , V_4 + V_37 ) ;
F_3 ( V_93 , V_4 + V_37 ) ;
F_11 ( V_87 , & ( V_3 -> V_9 ) ) ;
F_40 ( & ( V_3 -> V_32 ) ) ;
F_3 ( ( 0x0f << V_116 ) | 1 , V_4 + V_117 ) ;
F_52 ( 1250 ) ;
if ( F_53 ( V_50 ) < 0 ) {
F_9 ( L_5 ) ;
V_3 -> V_50 = NULL ;
F_54 ( V_50 ) ;
return - V_118 ;
}
return 0 ;
}
static int F_55 ( struct V_2 * V_3 )
{
unsigned int V_4 = V_3 -> V_5 -> V_6 [ 0 ] -> V_7 ;
struct V_94 * V_50 = V_3 -> V_50 ;
if ( ! V_50 )
return - V_118 ;
F_42 ( V_50 ) ;
F_12 ( V_87 , & ( V_3 -> V_9 ) ) ;
V_3 -> V_33 = V_112 | V_113 ;
F_3 ( V_3 -> V_33 , V_4 + V_35 ) ;
F_3 ( 0x80 , V_4 + 0x30 ) ;
F_56 ( V_50 ) ;
F_54 ( V_50 ) ;
return 0 ;
}
static int F_57 ( struct V_119 * V_120 )
{
struct V_2 * V_3 ;
V_3 = F_58 ( & V_120 -> V_106 , sizeof( * V_3 ) , V_121 ) ;
if ( ! V_3 )
return - V_103 ;
V_3 -> V_5 = V_120 ;
V_120 -> V_122 = V_3 ;
V_120 -> V_123 |= V_124 ;
return F_59 ( V_120 ) ;
}
static void F_60 ( struct V_119 * V_120 )
{
F_61 ( V_120 ) ;
}
static int F_59 ( struct V_119 * V_120 )
{
struct V_2 * V_3 = V_120 -> V_122 ;
int V_17 , V_54 ;
V_120 -> V_125 = 0x20 ;
V_120 -> V_6 [ 0 ] -> V_126 |= V_127 ;
V_120 -> V_6 [ 0 ] -> V_128 = 64 ;
V_120 -> V_129 = 6 ;
for ( V_54 = 0 ; V_54 < 0x400 ; V_54 += 0x40 ) {
V_120 -> V_6 [ 0 ] -> V_7 = V_54 ^ 0x300 ;
V_17 = F_62 ( V_120 ) ;
if ( V_17 == 0 )
break;
}
if ( V_17 != 0 )
goto V_130;
V_17 = F_63 ( V_120 , F_32 ) ;
if ( V_17 != 0 )
goto V_130;
V_17 = F_64 ( V_120 ) ;
if ( V_17 != 0 )
goto V_130;
if ( F_45 ( V_3 ) != 0 )
goto V_130;
return 0 ;
V_130:
F_61 ( V_120 ) ;
return - V_118 ;
}
static void F_61 ( struct V_119 * V_120 )
{
struct V_2 * V_3 = V_120 -> V_122 ;
F_55 ( V_3 ) ;
F_65 ( & ( V_3 -> V_11 ) ) ;
F_66 ( V_120 ) ;
}
