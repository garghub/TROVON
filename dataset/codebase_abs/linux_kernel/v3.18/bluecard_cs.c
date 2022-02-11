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
if ( F_15 ( V_26 ) -> V_33 & 0x80 ) {
V_3 -> V_34 |= V_35 ;
F_3 ( V_3 -> V_34 , V_4 + V_36 ) ;
}
F_4 ( V_3 ) ;
V_16 = F_6 ( V_4 , V_14 , V_26 -> V_37 , V_26 -> V_16 ) ;
F_7 ( V_23 , V_4 + V_38 ) ;
F_12 ( V_24 , & ( V_3 -> V_20 ) ) ;
if ( F_15 ( V_26 ) -> V_33 & 0x80 ) {
F_16 ( V_39 ) ;
F_17 ( V_40 ) ;
unsigned char V_41 ;
switch ( F_15 ( V_26 ) -> V_33 ) {
case V_42 :
V_41 = V_43 ;
break;
case V_44 :
V_41 = V_45 ;
break;
case V_46 :
V_41 = V_47 ;
break;
case V_48 :
default:
V_41 = V_49 ;
break;
}
F_18 ( & V_39 , & V_40 , V_50 ) ;
F_19 ( V_13 / 10 ) ;
F_20 ( & V_39 , & V_40 ) ;
V_3 -> V_34 &= ~ 0x03 ;
V_3 -> V_34 |= V_41 ;
F_3 ( V_3 -> V_34 , V_4 + V_36 ) ;
V_3 -> V_34 &= ~ V_35 ;
F_3 ( V_3 -> V_34 , V_4 + V_36 ) ;
F_18 ( & V_39 , & V_40 , V_50 ) ;
F_19 ( V_13 ) ;
F_20 ( & V_39 , & V_40 ) ;
}
if ( V_16 == V_26 -> V_16 ) {
F_21 ( V_26 ) ;
} else {
F_22 ( V_26 , V_16 ) ;
F_23 ( & ( V_3 -> V_32 ) , V_26 ) ;
}
V_3 -> V_51 -> V_52 . V_53 += V_16 ;
F_24 ( V_27 , & ( V_3 -> V_20 ) ) ;
} while ( F_2 ( V_22 , & ( V_3 -> V_20 ) ) );
F_12 ( V_21 , & ( V_3 -> V_20 ) ) ;
}
static int F_25 ( unsigned int V_4 , unsigned int V_14 , T_2 * V_15 , int V_54 )
{
int V_17 , V_55 , V_16 ;
F_3 ( V_56 , V_4 + V_38 ) ;
V_16 = F_26 ( V_4 + V_14 ) ;
V_55 = 0 ;
V_17 = 1 ;
while ( V_55 < V_16 ) {
if ( V_17 == 16 ) {
F_3 ( V_57 , V_4 + V_38 ) ;
V_17 = 0 ;
}
V_15 [ V_55 ] = F_26 ( V_4 + V_14 + V_17 ) ;
V_55 ++ ;
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
if ( V_3 -> V_58 == NULL ) {
V_3 -> V_59 = V_60 ;
V_3 -> V_61 = 0 ;
V_3 -> V_58 = F_28 ( V_62 , V_63 ) ;
if ( ! V_3 -> V_58 ) {
F_9 ( L_2 ) ;
return;
}
}
if ( V_3 -> V_59 == V_60 ) {
F_15 ( V_3 -> V_58 ) -> V_33 = V_15 [ V_17 ] ;
switch ( F_15 ( V_3 -> V_58 ) -> V_33 ) {
case 0x00 :
if ( V_14 != 0x00 ) {
F_11 ( V_30 , & ( V_3 -> V_20 ) ) ;
F_11 ( V_28 , & ( V_3 -> V_20 ) ) ;
F_11 ( V_19 , & ( V_3 -> V_20 ) ) ;
F_8 ( V_3 ) ;
}
F_21 ( V_3 -> V_58 ) ;
V_3 -> V_58 = NULL ;
break;
case V_64 :
V_3 -> V_59 = V_65 ;
V_3 -> V_61 = V_66 ;
break;
case V_67 :
V_3 -> V_59 = V_68 ;
V_3 -> V_61 = V_69 ;
break;
case V_70 :
V_3 -> V_59 = V_71 ;
V_3 -> V_61 = V_72 ;
break;
default:
F_9 ( L_3 , F_15 ( V_3 -> V_58 ) -> V_33 ) ;
V_3 -> V_51 -> V_52 . V_73 ++ ;
F_21 ( V_3 -> V_58 ) ;
V_3 -> V_58 = NULL ;
break;
}
} else {
* F_29 ( V_3 -> V_58 , 1 ) = V_15 [ V_17 ] ;
V_3 -> V_61 -- ;
if ( V_3 -> V_61 == 0 ) {
int V_74 ;
struct V_75 * V_76 ;
struct V_77 * V_78 ;
struct V_79 * V_80 ;
switch ( V_3 -> V_59 ) {
case V_65 :
V_76 = V_75 ( V_3 -> V_58 ) ;
V_3 -> V_59 = V_81 ;
V_3 -> V_61 = V_76 -> V_82 ;
break;
case V_68 :
V_78 = V_77 ( V_3 -> V_58 ) ;
V_74 = F_30 ( V_78 -> V_74 ) ;
V_3 -> V_59 = V_81 ;
V_3 -> V_61 = V_74 ;
break;
case V_71 :
V_80 = V_79 ( V_3 -> V_58 ) ;
V_3 -> V_59 = V_81 ;
V_3 -> V_61 = V_80 -> V_74 ;
break;
case V_81 :
F_31 ( V_3 -> V_51 , V_3 -> V_58 ) ;
V_3 -> V_58 = NULL ;
break;
}
}
}
}
V_3 -> V_51 -> V_52 . V_83 += V_16 ;
}
static T_3 F_32 ( int V_84 , void * V_85 )
{
struct V_2 * V_3 = V_85 ;
unsigned int V_4 ;
unsigned char V_86 ;
if ( ! V_3 || ! V_3 -> V_51 )
return V_87 ;
if ( ! F_2 ( V_88 , & ( V_3 -> V_9 ) ) )
return V_89 ;
V_4 = V_3 -> V_5 -> V_6 [ 0 ] -> V_7 ;
F_33 ( & ( V_3 -> V_90 ) ) ;
V_3 -> V_34 &= ~ V_91 ;
F_3 ( V_3 -> V_34 , V_4 + V_36 ) ;
V_86 = F_26 ( V_4 + V_92 ) ;
if ( ( V_86 != 0x00 ) && ( V_86 != 0xff ) ) {
if ( V_86 & 0x04 ) {
F_27 ( V_3 , 0x00 ) ;
F_3 ( 0x04 , V_4 + V_92 ) ;
F_3 ( V_93 , V_4 + V_38 ) ;
}
if ( V_86 & 0x08 ) {
F_27 ( V_3 , 0x10 ) ;
F_3 ( 0x08 , V_4 + V_92 ) ;
F_3 ( V_94 , V_4 + V_38 ) ;
}
if ( V_86 & 0x01 ) {
F_11 ( V_30 , & ( V_3 -> V_20 ) ) ;
F_3 ( 0x01 , V_4 + V_92 ) ;
F_8 ( V_3 ) ;
}
if ( V_86 & 0x02 ) {
F_11 ( V_28 , & ( V_3 -> V_20 ) ) ;
F_3 ( 0x02 , V_4 + V_92 ) ;
F_8 ( V_3 ) ;
}
}
V_3 -> V_34 |= V_91 ;
F_3 ( V_3 -> V_34 , V_4 + V_36 ) ;
F_34 ( & ( V_3 -> V_90 ) ) ;
return V_89 ;
}
static int F_35 ( struct V_95 * V_51 , int V_96 )
{
struct V_2 * V_3 = F_36 ( V_51 ) ;
struct V_25 * V_26 ;
unsigned char V_97 [] = { V_98 , 0x09 , 0xfc , 0x01 , 0x03 } ;
V_26 = F_28 ( V_62 , V_63 ) ;
if ( ! V_26 ) {
F_9 ( L_2 ) ;
return - 1 ;
}
switch ( V_96 ) {
case 460800 :
V_97 [ 4 ] = 0x00 ;
F_15 ( V_26 ) -> V_33 = V_42 ;
break;
case 230400 :
V_97 [ 4 ] = 0x01 ;
F_15 ( V_26 ) -> V_33 = V_44 ;
break;
case 115200 :
V_97 [ 4 ] = 0x02 ;
F_15 ( V_26 ) -> V_33 = V_46 ;
break;
case 57600 :
default:
V_97 [ 4 ] = 0x03 ;
F_15 ( V_26 ) -> V_33 = V_48 ;
break;
}
memcpy ( F_29 ( V_26 , sizeof( V_97 ) ) , V_97 , sizeof( V_97 ) ) ;
F_37 ( & ( V_3 -> V_32 ) , V_26 ) ;
F_8 ( V_3 ) ;
return 0 ;
}
static int F_38 ( struct V_95 * V_51 )
{
struct V_2 * V_3 = F_36 ( V_51 ) ;
F_39 ( & ( V_3 -> V_32 ) ) ;
return 0 ;
}
static int F_40 ( struct V_95 * V_51 )
{
struct V_2 * V_3 = F_36 ( V_51 ) ;
if ( F_2 ( V_8 , & ( V_3 -> V_9 ) ) )
F_35 ( V_51 , V_99 ) ;
if ( F_10 ( V_100 , & ( V_51 -> V_101 ) ) )
return 0 ;
if ( F_2 ( V_8 , & ( V_3 -> V_9 ) ) ) {
unsigned int V_4 = V_3 -> V_5 -> V_6 [ 0 ] -> V_7 ;
F_3 ( 0x08 | 0x20 , V_4 + 0x30 ) ;
}
return 0 ;
}
static int F_41 ( struct V_95 * V_51 )
{
struct V_2 * V_3 = F_36 ( V_51 ) ;
if ( ! F_42 ( V_100 , & ( V_51 -> V_101 ) ) )
return 0 ;
F_38 ( V_51 ) ;
if ( F_2 ( V_8 , & ( V_3 -> V_9 ) ) ) {
unsigned int V_4 = V_3 -> V_5 -> V_6 [ 0 ] -> V_7 ;
F_3 ( 0x00 , V_4 + 0x30 ) ;
}
return 0 ;
}
static int F_43 ( struct V_95 * V_51 , struct V_25 * V_26 )
{
struct V_2 * V_3 = F_36 ( V_51 ) ;
switch ( F_15 ( V_26 ) -> V_33 ) {
case V_98 :
V_51 -> V_52 . V_102 ++ ;
break;
case V_67 :
V_51 -> V_52 . V_103 ++ ;
break;
case V_70 :
V_51 -> V_52 . V_104 ++ ;
break;
}
memcpy ( F_44 ( V_26 , 1 ) , & F_15 ( V_26 ) -> V_33 , 1 ) ;
F_37 ( & ( V_3 -> V_32 ) , V_26 ) ;
F_8 ( V_3 ) ;
return 0 ;
}
static int F_45 ( struct V_2 * V_3 )
{
unsigned int V_4 = V_3 -> V_5 -> V_6 [ 0 ] -> V_7 ;
struct V_95 * V_51 ;
unsigned char V_105 ;
F_46 ( & ( V_3 -> V_90 ) ) ;
F_47 ( & ( V_3 -> V_11 ) ) ;
V_3 -> V_11 . V_106 = & F_1 ;
V_3 -> V_11 . V_37 = ( T_1 ) V_3 ;
F_48 ( & ( V_3 -> V_32 ) ) ;
V_3 -> V_59 = V_60 ;
V_3 -> V_61 = 0 ;
V_3 -> V_58 = NULL ;
V_51 = F_49 () ;
if ( ! V_51 ) {
F_9 ( L_4 ) ;
return - V_107 ;
}
V_3 -> V_51 = V_51 ;
V_51 -> V_108 = V_109 ;
F_50 ( V_51 , V_3 ) ;
F_51 ( V_51 , & V_3 -> V_5 -> V_110 ) ;
V_51 -> V_111 = F_40 ;
V_51 -> V_112 = F_41 ;
V_51 -> V_113 = F_38 ;
V_51 -> V_114 = F_43 ;
V_105 = F_26 ( V_4 + 0x30 ) ;
if ( ( V_105 & 0x0f ) == 0x02 )
F_11 ( V_8 , & ( V_3 -> V_9 ) ) ;
if ( V_105 & 0x10 )
F_11 ( V_115 , & ( V_3 -> V_9 ) ) ;
if ( V_105 & 0x20 )
F_11 ( V_10 , & ( V_3 -> V_9 ) ) ;
V_3 -> V_34 = V_116 | V_117 ;
F_3 ( V_3 -> V_34 , V_4 + V_36 ) ;
F_3 ( 0x80 , V_4 + 0x30 ) ;
F_52 ( 10 ) ;
F_3 ( 0x00 , V_4 + 0x30 ) ;
V_3 -> V_34 = V_118 | V_119 ;
F_3 ( V_3 -> V_34 , V_4 + V_36 ) ;
F_3 ( 0xff , V_4 + V_92 ) ;
V_3 -> V_34 |= V_91 ;
F_3 ( V_3 -> V_34 , V_4 + V_36 ) ;
if ( ( V_105 & 0x0f ) == 0x03 ) {
V_3 -> V_34 |= V_35 ;
F_3 ( V_3 -> V_34 , V_4 + V_36 ) ;
V_3 -> V_34 |= 0x03 ;
F_3 ( V_3 -> V_34 , V_4 + V_36 ) ;
V_3 -> V_34 &= ~ V_35 ;
F_3 ( V_3 -> V_34 , V_4 + V_36 ) ;
F_11 ( V_30 , & ( V_3 -> V_20 ) ) ;
F_11 ( V_28 , & ( V_3 -> V_20 ) ) ;
F_11 ( V_19 , & ( V_3 -> V_20 ) ) ;
}
F_3 ( V_93 , V_4 + V_38 ) ;
F_3 ( V_94 , V_4 + V_38 ) ;
F_11 ( V_88 , & ( V_3 -> V_9 ) ) ;
F_39 ( & ( V_3 -> V_32 ) ) ;
F_3 ( ( 0x0f << V_120 ) | 1 , V_4 + V_121 ) ;
F_52 ( 1250 ) ;
if ( F_53 ( V_51 ) < 0 ) {
F_9 ( L_5 ) ;
V_3 -> V_51 = NULL ;
F_54 ( V_51 ) ;
return - V_122 ;
}
return 0 ;
}
static int F_55 ( struct V_2 * V_3 )
{
unsigned int V_4 = V_3 -> V_5 -> V_6 [ 0 ] -> V_7 ;
struct V_95 * V_51 = V_3 -> V_51 ;
if ( ! V_51 )
return - V_122 ;
F_41 ( V_51 ) ;
F_12 ( V_88 , & ( V_3 -> V_9 ) ) ;
V_3 -> V_34 = V_116 | V_117 ;
F_3 ( V_3 -> V_34 , V_4 + V_36 ) ;
F_3 ( 0x80 , V_4 + 0x30 ) ;
F_56 ( V_51 ) ;
F_54 ( V_51 ) ;
return 0 ;
}
static int F_57 ( struct V_123 * V_124 )
{
struct V_2 * V_3 ;
V_3 = F_58 ( & V_124 -> V_110 , sizeof( * V_3 ) , V_125 ) ;
if ( ! V_3 )
return - V_107 ;
V_3 -> V_5 = V_124 ;
V_124 -> V_126 = V_3 ;
V_124 -> V_127 |= V_128 ;
return F_59 ( V_124 ) ;
}
static void F_60 ( struct V_123 * V_124 )
{
F_61 ( V_124 ) ;
}
static int F_59 ( struct V_123 * V_124 )
{
struct V_2 * V_3 = V_124 -> V_126 ;
int V_17 , V_55 ;
V_124 -> V_129 = 0x20 ;
V_124 -> V_6 [ 0 ] -> V_101 |= V_130 ;
V_124 -> V_6 [ 0 ] -> V_131 = 64 ;
V_124 -> V_132 = 6 ;
for ( V_55 = 0 ; V_55 < 0x400 ; V_55 += 0x40 ) {
V_124 -> V_6 [ 0 ] -> V_7 = V_55 ^ 0x300 ;
V_17 = F_62 ( V_124 ) ;
if ( V_17 == 0 )
break;
}
if ( V_17 != 0 )
goto V_133;
V_17 = F_63 ( V_124 , F_32 ) ;
if ( V_17 != 0 )
goto V_133;
V_17 = F_64 ( V_124 ) ;
if ( V_17 != 0 )
goto V_133;
if ( F_45 ( V_3 ) != 0 )
goto V_133;
return 0 ;
V_133:
F_61 ( V_124 ) ;
return - V_122 ;
}
static void F_61 ( struct V_123 * V_124 )
{
struct V_2 * V_3 = V_124 -> V_126 ;
F_55 ( V_3 ) ;
F_65 ( & ( V_3 -> V_11 ) ) ;
F_66 ( V_124 ) ;
}
