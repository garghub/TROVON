static void F_1 ( T_1 V_1 )
{
T_2 * V_2 = ( T_2 * ) V_1 ;
unsigned int V_3 = V_2 -> V_4 -> V_5 [ 0 ] -> V_6 ;
if ( ! F_2 ( V_7 , & ( V_2 -> V_8 ) ) )
return;
if ( F_2 ( V_9 , & ( V_2 -> V_8 ) ) ) {
F_3 ( 0x08 | 0x20 , V_3 + 0x30 ) ;
} else {
F_3 ( 0x00 , V_3 + 0x30 ) ;
}
}
static void F_4 ( T_2 * V_2 )
{
unsigned int V_3 = V_2 -> V_4 -> V_5 [ 0 ] -> V_6 ;
if ( ! F_2 ( V_7 , & ( V_2 -> V_8 ) ) )
return;
if ( F_2 ( V_9 , & ( V_2 -> V_8 ) ) ) {
F_3 ( 0x10 | 0x40 , V_3 + 0x30 ) ;
F_5 ( & ( V_2 -> V_10 ) , V_11 + V_12 / 4 ) ;
} else {
F_3 ( 0x08 | 0x20 , V_3 + 0x30 ) ;
F_5 ( & ( V_2 -> V_10 ) , V_11 + V_12 / 2 ) ;
}
}
static int F_6 ( unsigned int V_3 , unsigned int V_13 , T_3 * V_14 , int V_15 )
{
int V_16 , V_17 ;
V_17 = ( V_15 > 15 ) ? 15 : V_15 ;
F_7 ( V_17 , V_3 + V_13 ) ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ )
F_7 ( V_14 [ V_16 ] , V_3 + V_13 + V_16 + 1 ) ;
return V_17 ;
}
static void F_8 ( T_2 * V_2 )
{
if ( ! V_2 ) {
F_9 ( L_1 ) ;
return;
}
if ( ! F_2 ( V_18 , & ( V_2 -> V_19 ) ) )
return;
if ( F_10 ( V_20 , & ( V_2 -> V_19 ) ) ) {
F_11 ( V_21 , & ( V_2 -> V_19 ) ) ;
return;
}
do {
unsigned int V_3 = V_2 -> V_4 -> V_5 [ 0 ] -> V_6 ;
unsigned int V_13 ;
unsigned char V_22 ;
unsigned long V_23 ;
register struct V_24 * V_25 ;
int V_15 ;
F_12 ( V_21 , & ( V_2 -> V_19 ) ) ;
if ( ! F_13 ( V_2 -> V_4 ) )
return;
if ( F_2 ( V_26 , & ( V_2 -> V_19 ) ) ) {
if ( ! F_2 ( V_27 , & ( V_2 -> V_19 ) ) )
break;
V_13 = 0x10 ;
V_22 = V_28 ;
V_23 = V_27 ;
} else {
if ( ! F_2 ( V_29 , & ( V_2 -> V_19 ) ) )
break;
V_13 = 0x00 ;
V_22 = V_30 ;
V_23 = V_29 ;
}
if ( ! ( V_25 = F_14 ( & ( V_2 -> V_31 ) ) ) )
break;
if ( F_15 ( V_25 ) -> V_32 & 0x80 ) {
V_2 -> V_33 |= V_34 ;
F_3 ( V_2 -> V_33 , V_3 + V_35 ) ;
}
F_4 ( V_2 ) ;
V_15 = F_6 ( V_3 , V_13 , V_25 -> V_36 , V_25 -> V_15 ) ;
F_7 ( V_22 , V_3 + V_37 ) ;
F_12 ( V_23 , & ( V_2 -> V_19 ) ) ;
if ( F_15 ( V_25 ) -> V_32 & 0x80 ) {
F_16 ( V_38 ) ;
F_17 ( V_39 ) ;
unsigned char V_40 ;
switch ( F_15 ( V_25 ) -> V_32 ) {
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
F_19 ( V_12 / 10 ) ;
F_20 ( & V_38 , & V_39 ) ;
V_2 -> V_33 &= ~ 0x03 ;
V_2 -> V_33 |= V_40 ;
F_3 ( V_2 -> V_33 , V_3 + V_35 ) ;
V_2 -> V_33 &= ~ V_34 ;
F_3 ( V_2 -> V_33 , V_3 + V_35 ) ;
F_18 ( & V_38 , & V_39 , V_49 ) ;
F_19 ( V_12 ) ;
F_20 ( & V_38 , & V_39 ) ;
}
if ( V_15 == V_25 -> V_15 ) {
F_21 ( V_25 ) ;
} else {
F_22 ( V_25 , V_15 ) ;
F_23 ( & ( V_2 -> V_31 ) , V_25 ) ;
}
V_2 -> V_50 -> V_51 . V_52 += V_15 ;
F_24 ( V_26 , & ( V_2 -> V_19 ) ) ;
} while ( F_2 ( V_21 , & ( V_2 -> V_19 ) ) );
F_12 ( V_20 , & ( V_2 -> V_19 ) ) ;
}
static int F_25 ( unsigned int V_3 , unsigned int V_13 , T_3 * V_14 , int V_53 )
{
int V_16 , V_54 , V_15 ;
F_3 ( V_55 , V_3 + V_37 ) ;
V_15 = F_26 ( V_3 + V_13 ) ;
V_54 = 0 ;
V_16 = 1 ;
while ( V_54 < V_15 ) {
if ( V_16 == 16 ) {
F_3 ( V_56 , V_3 + V_37 ) ;
V_16 = 0 ;
}
V_14 [ V_54 ] = F_26 ( V_3 + V_13 + V_16 ) ;
V_54 ++ ;
V_16 ++ ;
}
return V_15 ;
}
static void F_27 ( T_2 * V_2 , unsigned int V_13 )
{
unsigned int V_3 ;
unsigned char V_14 [ 31 ] ;
int V_16 , V_15 ;
if ( ! V_2 ) {
F_9 ( L_1 ) ;
return;
}
V_3 = V_2 -> V_4 -> V_5 [ 0 ] -> V_6 ;
if ( F_2 ( V_18 , & ( V_2 -> V_19 ) ) )
F_4 ( V_2 ) ;
V_15 = F_25 ( V_3 , V_13 , V_14 , sizeof( V_14 ) ) ;
for ( V_16 = 0 ; V_16 < V_15 ; V_16 ++ ) {
if ( V_2 -> V_57 == NULL ) {
V_2 -> V_58 = V_59 ;
V_2 -> V_60 = 0 ;
if ( ! ( V_2 -> V_57 = F_28 ( V_61 , V_62 ) ) ) {
F_9 ( L_2 ) ;
return;
}
}
if ( V_2 -> V_58 == V_59 ) {
F_15 ( V_2 -> V_57 ) -> V_32 = V_14 [ V_16 ] ;
switch ( F_15 ( V_2 -> V_57 ) -> V_32 ) {
case 0x00 :
if ( V_13 != 0x00 ) {
F_11 ( V_29 , & ( V_2 -> V_19 ) ) ;
F_11 ( V_27 , & ( V_2 -> V_19 ) ) ;
F_11 ( V_18 , & ( V_2 -> V_19 ) ) ;
F_8 ( V_2 ) ;
}
F_21 ( V_2 -> V_57 ) ;
V_2 -> V_57 = NULL ;
break;
case V_63 :
V_2 -> V_58 = V_64 ;
V_2 -> V_60 = V_65 ;
break;
case V_66 :
V_2 -> V_58 = V_67 ;
V_2 -> V_60 = V_68 ;
break;
case V_69 :
V_2 -> V_58 = V_70 ;
V_2 -> V_60 = V_71 ;
break;
default:
F_9 ( L_3 , F_15 ( V_2 -> V_57 ) -> V_32 ) ;
V_2 -> V_50 -> V_51 . V_72 ++ ;
F_21 ( V_2 -> V_57 ) ;
V_2 -> V_57 = NULL ;
break;
}
} else {
* F_29 ( V_2 -> V_57 , 1 ) = V_14 [ V_16 ] ;
V_2 -> V_60 -- ;
if ( V_2 -> V_60 == 0 ) {
int V_73 ;
struct V_74 * V_75 ;
struct V_76 * V_77 ;
struct V_78 * V_79 ;
switch ( V_2 -> V_58 ) {
case V_64 :
V_75 = V_74 ( V_2 -> V_57 ) ;
V_2 -> V_58 = V_80 ;
V_2 -> V_60 = V_75 -> V_81 ;
break;
case V_67 :
V_77 = V_76 ( V_2 -> V_57 ) ;
V_73 = F_30 ( V_77 -> V_73 ) ;
V_2 -> V_58 = V_80 ;
V_2 -> V_60 = V_73 ;
break;
case V_70 :
V_79 = V_78 ( V_2 -> V_57 ) ;
V_2 -> V_58 = V_80 ;
V_2 -> V_60 = V_79 -> V_73 ;
break;
case V_80 :
F_31 ( V_2 -> V_50 , V_2 -> V_57 ) ;
V_2 -> V_57 = NULL ;
break;
}
}
}
}
V_2 -> V_50 -> V_51 . V_82 += V_15 ;
}
static T_4 F_32 ( int V_83 , void * V_84 )
{
T_2 * V_2 = V_84 ;
unsigned int V_3 ;
unsigned char V_85 ;
if ( ! V_2 || ! V_2 -> V_50 )
return V_86 ;
if ( ! F_2 ( V_87 , & ( V_2 -> V_8 ) ) )
return V_88 ;
V_3 = V_2 -> V_4 -> V_5 [ 0 ] -> V_6 ;
F_33 ( & ( V_2 -> V_89 ) ) ;
V_2 -> V_33 &= ~ V_90 ;
F_3 ( V_2 -> V_33 , V_3 + V_35 ) ;
V_85 = F_26 ( V_3 + V_91 ) ;
if ( ( V_85 != 0x00 ) && ( V_85 != 0xff ) ) {
if ( V_85 & 0x04 ) {
F_27 ( V_2 , 0x00 ) ;
F_3 ( 0x04 , V_3 + V_91 ) ;
F_3 ( V_92 , V_3 + V_37 ) ;
}
if ( V_85 & 0x08 ) {
F_27 ( V_2 , 0x10 ) ;
F_3 ( 0x08 , V_3 + V_91 ) ;
F_3 ( V_93 , V_3 + V_37 ) ;
}
if ( V_85 & 0x01 ) {
F_11 ( V_29 , & ( V_2 -> V_19 ) ) ;
F_3 ( 0x01 , V_3 + V_91 ) ;
F_8 ( V_2 ) ;
}
if ( V_85 & 0x02 ) {
F_11 ( V_27 , & ( V_2 -> V_19 ) ) ;
F_3 ( 0x02 , V_3 + V_91 ) ;
F_8 ( V_2 ) ;
}
}
V_2 -> V_33 |= V_90 ;
F_3 ( V_2 -> V_33 , V_3 + V_35 ) ;
F_34 ( & ( V_2 -> V_89 ) ) ;
return V_88 ;
}
static int F_35 ( struct V_94 * V_50 , int V_95 )
{
T_2 * V_2 = F_36 ( V_50 ) ;
struct V_24 * V_25 ;
unsigned char V_96 [] = { V_97 , 0x09 , 0xfc , 0x01 , 0x03 } ;
if ( ! ( V_25 = F_28 ( V_61 , V_62 ) ) ) {
F_9 ( L_2 ) ;
return - 1 ;
}
switch ( V_95 ) {
case 460800 :
V_96 [ 4 ] = 0x00 ;
F_15 ( V_25 ) -> V_32 = V_41 ;
break;
case 230400 :
V_96 [ 4 ] = 0x01 ;
F_15 ( V_25 ) -> V_32 = V_43 ;
break;
case 115200 :
V_96 [ 4 ] = 0x02 ;
F_15 ( V_25 ) -> V_32 = V_45 ;
break;
case 57600 :
default:
V_96 [ 4 ] = 0x03 ;
F_15 ( V_25 ) -> V_32 = V_47 ;
break;
}
memcpy ( F_29 ( V_25 , sizeof( V_96 ) ) , V_96 , sizeof( V_96 ) ) ;
F_37 ( & ( V_2 -> V_31 ) , V_25 ) ;
F_8 ( V_2 ) ;
return 0 ;
}
static int F_38 ( struct V_94 * V_50 )
{
T_2 * V_2 = F_36 ( V_50 ) ;
F_39 ( & ( V_2 -> V_31 ) ) ;
return 0 ;
}
static int F_40 ( struct V_94 * V_50 )
{
T_2 * V_2 = F_36 ( V_50 ) ;
if ( F_2 ( V_7 , & ( V_2 -> V_8 ) ) )
F_35 ( V_50 , V_98 ) ;
if ( F_10 ( V_99 , & ( V_50 -> V_100 ) ) )
return 0 ;
if ( F_2 ( V_7 , & ( V_2 -> V_8 ) ) ) {
unsigned int V_3 = V_2 -> V_4 -> V_5 [ 0 ] -> V_6 ;
F_3 ( 0x08 | 0x20 , V_3 + 0x30 ) ;
}
return 0 ;
}
static int F_41 ( struct V_94 * V_50 )
{
T_2 * V_2 = F_36 ( V_50 ) ;
if ( ! F_42 ( V_99 , & ( V_50 -> V_100 ) ) )
return 0 ;
F_38 ( V_50 ) ;
if ( F_2 ( V_7 , & ( V_2 -> V_8 ) ) ) {
unsigned int V_3 = V_2 -> V_4 -> V_5 [ 0 ] -> V_6 ;
F_3 ( 0x00 , V_3 + 0x30 ) ;
}
return 0 ;
}
static int F_43 ( struct V_94 * V_50 , struct V_24 * V_25 )
{
T_2 * V_2 = F_36 ( V_50 ) ;
switch ( F_15 ( V_25 ) -> V_32 ) {
case V_97 :
V_50 -> V_51 . V_101 ++ ;
break;
case V_66 :
V_50 -> V_51 . V_102 ++ ;
break;
case V_69 :
V_50 -> V_51 . V_103 ++ ;
break;
}
memcpy ( F_44 ( V_25 , 1 ) , & F_15 ( V_25 ) -> V_32 , 1 ) ;
F_37 ( & ( V_2 -> V_31 ) , V_25 ) ;
F_8 ( V_2 ) ;
return 0 ;
}
static int F_45 ( T_2 * V_2 )
{
unsigned int V_3 = V_2 -> V_4 -> V_5 [ 0 ] -> V_6 ;
struct V_94 * V_50 ;
unsigned char V_104 ;
F_46 ( & ( V_2 -> V_89 ) ) ;
F_47 ( & ( V_2 -> V_10 ) ) ;
V_2 -> V_10 . V_105 = & F_1 ;
V_2 -> V_10 . V_36 = ( T_1 ) V_2 ;
F_48 ( & ( V_2 -> V_31 ) ) ;
V_2 -> V_58 = V_59 ;
V_2 -> V_60 = 0 ;
V_2 -> V_57 = NULL ;
V_50 = F_49 () ;
if ( ! V_50 ) {
F_9 ( L_4 ) ;
return - V_106 ;
}
V_2 -> V_50 = V_50 ;
V_50 -> V_107 = V_108 ;
F_50 ( V_50 , V_2 ) ;
F_51 ( V_50 , & V_2 -> V_4 -> V_109 ) ;
V_50 -> V_110 = F_40 ;
V_50 -> V_111 = F_41 ;
V_50 -> V_112 = F_38 ;
V_50 -> V_113 = F_43 ;
V_104 = F_26 ( V_3 + 0x30 ) ;
if ( ( V_104 & 0x0f ) == 0x02 )
F_11 ( V_7 , & ( V_2 -> V_8 ) ) ;
if ( V_104 & 0x10 )
F_11 ( V_114 , & ( V_2 -> V_8 ) ) ;
if ( V_104 & 0x20 )
F_11 ( V_9 , & ( V_2 -> V_8 ) ) ;
V_2 -> V_33 = V_115 | V_116 ;
F_3 ( V_2 -> V_33 , V_3 + V_35 ) ;
F_3 ( 0x80 , V_3 + 0x30 ) ;
F_52 ( 10 ) ;
F_3 ( 0x00 , V_3 + 0x30 ) ;
V_2 -> V_33 = V_117 | V_118 ;
F_3 ( V_2 -> V_33 , V_3 + V_35 ) ;
F_3 ( 0xff , V_3 + V_91 ) ;
V_2 -> V_33 |= V_90 ;
F_3 ( V_2 -> V_33 , V_3 + V_35 ) ;
if ( ( V_104 & 0x0f ) == 0x03 ) {
V_2 -> V_33 |= V_34 ;
F_3 ( V_2 -> V_33 , V_3 + V_35 ) ;
V_2 -> V_33 |= 0x03 ;
F_3 ( V_2 -> V_33 , V_3 + V_35 ) ;
V_2 -> V_33 &= ~ V_34 ;
F_3 ( V_2 -> V_33 , V_3 + V_35 ) ;
F_11 ( V_29 , & ( V_2 -> V_19 ) ) ;
F_11 ( V_27 , & ( V_2 -> V_19 ) ) ;
F_11 ( V_18 , & ( V_2 -> V_19 ) ) ;
}
F_3 ( V_92 , V_3 + V_37 ) ;
F_3 ( V_93 , V_3 + V_37 ) ;
F_11 ( V_87 , & ( V_2 -> V_8 ) ) ;
F_39 ( & ( V_2 -> V_31 ) ) ;
F_3 ( ( 0x0f << V_119 ) | 1 , V_3 + V_120 ) ;
F_52 ( 1250 ) ;
if ( F_53 ( V_50 ) < 0 ) {
F_9 ( L_5 ) ;
V_2 -> V_50 = NULL ;
F_54 ( V_50 ) ;
return - V_121 ;
}
return 0 ;
}
static int F_55 ( T_2 * V_2 )
{
unsigned int V_3 = V_2 -> V_4 -> V_5 [ 0 ] -> V_6 ;
struct V_94 * V_50 = V_2 -> V_50 ;
if ( ! V_50 )
return - V_121 ;
F_41 ( V_50 ) ;
F_12 ( V_87 , & ( V_2 -> V_8 ) ) ;
V_2 -> V_33 = V_115 | V_116 ;
F_3 ( V_2 -> V_33 , V_3 + V_35 ) ;
F_3 ( 0x80 , V_3 + 0x30 ) ;
F_56 ( V_50 ) ;
F_54 ( V_50 ) ;
return 0 ;
}
static int F_57 ( struct V_122 * V_123 )
{
T_2 * V_2 ;
V_2 = F_58 ( & V_123 -> V_109 , sizeof( * V_2 ) , V_124 ) ;
if ( ! V_2 )
return - V_106 ;
V_2 -> V_4 = V_123 ;
V_123 -> V_125 = V_2 ;
V_123 -> V_126 |= V_127 ;
return F_59 ( V_123 ) ;
}
static void F_60 ( struct V_122 * V_123 )
{
F_61 ( V_123 ) ;
}
static int F_59 ( struct V_122 * V_123 )
{
T_2 * V_2 = V_123 -> V_125 ;
int V_16 , V_54 ;
V_123 -> V_128 = 0x20 ;
V_123 -> V_5 [ 0 ] -> V_100 |= V_129 ;
V_123 -> V_5 [ 0 ] -> V_130 = 64 ;
V_123 -> V_131 = 6 ;
for ( V_54 = 0 ; V_54 < 0x400 ; V_54 += 0x40 ) {
V_123 -> V_5 [ 0 ] -> V_6 = V_54 ^ 0x300 ;
V_16 = F_62 ( V_123 ) ;
if ( V_16 == 0 )
break;
}
if ( V_16 != 0 )
goto V_132;
V_16 = F_63 ( V_123 , F_32 ) ;
if ( V_16 != 0 )
goto V_132;
V_16 = F_64 ( V_123 ) ;
if ( V_16 != 0 )
goto V_132;
if ( F_45 ( V_2 ) != 0 )
goto V_132;
return 0 ;
V_132:
F_61 ( V_123 ) ;
return - V_121 ;
}
static void F_61 ( struct V_122 * V_123 )
{
T_2 * V_2 = V_123 -> V_125 ;
F_55 ( V_2 ) ;
F_65 ( & ( V_2 -> V_10 ) ) ;
F_66 ( V_123 ) ;
}
