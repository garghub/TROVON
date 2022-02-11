static inline bool F_1 ( int V_1 , int V_2 )
{
return F_2 ( V_1 ) == V_2 ;
}
void T_1 F_3 ( void )
{
F_4 ( V_3 L_1 ) ;
F_5 ( V_4 ) ;
V_5 -> V_6 -> V_7 =
V_5 -> V_8 -> V_7 ;
V_5 -> V_6 -> V_9 =
V_5 -> V_8 -> V_9 ;
V_5 -> V_6 -> V_10 =
V_5 -> V_8 -> V_10 ;
V_5 -> V_6 -> V_11 =
V_5 -> V_8 -> V_11 ;
}
static bool F_6 ( void )
{
if ( V_12 == V_13 ) {
if ( V_5 -> V_14 -> V_15 . V_16 ) {
V_5 -> V_14 -> V_17 . V_16 =
V_18 ;
F_4 ( V_3 L_2
L_3 ) ;
} else {
V_5 -> V_14 -> V_15 . V_16 =
V_18 ;
F_4 ( V_3 L_4
L_5 ) ;
}
} else if ( V_12 == V_19 ) {
V_5 -> V_14 -> V_15 . V_16 =
V_18 ;
V_5 -> V_14 -> V_17 . V_16 =
V_18 ;
F_4 ( V_3 L_6
L_7 ) ;
} else if ( V_12 != V_20 ) {
if ( ! V_5 -> V_14 -> V_15 . V_16 ) {
V_5 -> V_14 -> V_15 . V_16 =
V_18 ;
F_4 ( V_3 L_8 ) ;
}
} else {
V_5 -> V_14 -> V_15 . V_16 =
V_21 ;
F_4 ( V_3 L_9 ) ;
return false ;
}
return true ;
}
bool T_1 F_7 ( void )
{
if ( F_8 ( V_22 ) ) {
V_5 -> V_14 -> V_15 . V_23 = V_22 ;
F_4 ( V_3
L_10 ) ;
} else {
if ( F_8 ( V_24 ) ) {
V_5 -> V_14 -> V_15 . V_23 =
V_24 ;
F_4 ( V_3
L_11 ) ;
}
}
if ( V_5 -> V_14 -> V_25 == V_26 )
F_6 () ;
if ( V_5 -> V_14 -> V_15 . V_16 )
return true ;
V_5 -> V_14 -> V_15 . V_16 = V_27 ;
V_5 -> V_14 -> V_15 . V_28 =
V_29 ;
if ( F_1 ( V_30 , V_31 ) ) {
F_4 ( V_3 L_12 ) ;
F_4 ( V_3 L_13 ,
V_5 -> V_14 -> V_15 . V_16 ) ;
F_4 ( V_3 L_13 ,
V_5 -> V_14 -> V_15 . V_16 ) ;
return true ;
}
V_5 -> V_14 -> V_15 . V_16 =
V_21 ;
V_5 -> V_14 -> V_15 . V_28 =
V_29 ;
return false ;
}
static void T_1 F_5 ( int V_32 )
{
F_4 ( V_3 L_14 ) ;
if ( V_32 > V_33 )
V_4 = V_32 =
F_9 ( V_34 , V_35 ) & 0x0F ;
switch ( V_32 ) {
case 0x0 :
V_5 -> V_8 -> V_7 = 640 ;
V_5 -> V_8 -> V_9 = 480 ;
V_5 -> V_8 -> V_10 = 0 ;
V_5 -> V_8 -> V_11 = 1 ;
break;
case 0x1 :
V_5 -> V_8 -> V_7 = 800 ;
V_5 -> V_8 -> V_9 = 600 ;
V_5 -> V_8 -> V_10 = 0 ;
V_5 -> V_8 -> V_11 = 1 ;
break;
case 0x2 :
V_5 -> V_8 -> V_7 = 1024 ;
V_5 -> V_8 -> V_9 = 768 ;
V_5 -> V_8 -> V_10 = 0 ;
V_5 -> V_8 -> V_11 = 1 ;
break;
case 0x3 :
V_5 -> V_8 -> V_7 = 1280 ;
V_5 -> V_8 -> V_9 = 768 ;
V_5 -> V_8 -> V_10 = 0 ;
V_5 -> V_8 -> V_11 = 1 ;
break;
case 0x4 :
V_5 -> V_8 -> V_7 = 1280 ;
V_5 -> V_8 -> V_9 = 1024 ;
V_5 -> V_8 -> V_10 = 1 ;
V_5 -> V_8 -> V_11 = 1 ;
break;
case 0x5 :
V_5 -> V_8 -> V_7 = 1400 ;
V_5 -> V_8 -> V_9 = 1050 ;
V_5 -> V_8 -> V_10 = 1 ;
V_5 -> V_8 -> V_11 = 1 ;
break;
case 0x6 :
V_5 -> V_8 -> V_7 = 1600 ;
V_5 -> V_8 -> V_9 = 1200 ;
V_5 -> V_8 -> V_10 = 1 ;
V_5 -> V_8 -> V_11 = 1 ;
break;
case 0x8 :
V_5 -> V_8 -> V_7 = 800 ;
V_5 -> V_8 -> V_9 = 480 ;
V_5 -> V_8 -> V_10 = 0 ;
V_5 -> V_8 -> V_11 = 1 ;
break;
case 0x9 :
V_5 -> V_8 -> V_7 = 1024 ;
V_5 -> V_8 -> V_9 = 768 ;
V_5 -> V_8 -> V_10 = 1 ;
V_5 -> V_8 -> V_11 = 1 ;
break;
case 0xA :
V_5 -> V_8 -> V_7 = 1024 ;
V_5 -> V_8 -> V_9 = 768 ;
V_5 -> V_8 -> V_10 = 0 ;
V_5 -> V_8 -> V_11 = 0 ;
break;
case 0xB :
V_5 -> V_8 -> V_7 = 1024 ;
V_5 -> V_8 -> V_9 = 768 ;
V_5 -> V_8 -> V_10 = 1 ;
V_5 -> V_8 -> V_11 = 0 ;
break;
case 0xC :
V_5 -> V_8 -> V_7 = 1280 ;
V_5 -> V_8 -> V_9 = 768 ;
V_5 -> V_8 -> V_10 = 0 ;
V_5 -> V_8 -> V_11 = 0 ;
break;
case 0xD :
V_5 -> V_8 -> V_7 = 1280 ;
V_5 -> V_8 -> V_9 = 1024 ;
V_5 -> V_8 -> V_10 = 1 ;
V_5 -> V_8 -> V_11 = 0 ;
break;
case 0xE :
V_5 -> V_8 -> V_7 = 1400 ;
V_5 -> V_8 -> V_9 = 1050 ;
V_5 -> V_8 -> V_10 = 1 ;
V_5 -> V_8 -> V_11 = 0 ;
break;
case 0xF :
V_5 -> V_8 -> V_7 = 1600 ;
V_5 -> V_8 -> V_9 = 1200 ;
V_5 -> V_8 -> V_10 = 1 ;
V_5 -> V_8 -> V_11 = 0 ;
break;
case 0x10 :
V_5 -> V_8 -> V_7 = 1366 ;
V_5 -> V_8 -> V_9 = 768 ;
V_5 -> V_8 -> V_10 = 0 ;
V_5 -> V_8 -> V_11 = 0 ;
break;
case 0x11 :
V_5 -> V_8 -> V_7 = 1024 ;
V_5 -> V_8 -> V_9 = 600 ;
V_5 -> V_8 -> V_10 = 0 ;
V_5 -> V_8 -> V_11 = 1 ;
break;
case 0x12 :
V_5 -> V_8 -> V_7 = 1280 ;
V_5 -> V_8 -> V_9 = 768 ;
V_5 -> V_8 -> V_10 = 1 ;
V_5 -> V_8 -> V_11 = 1 ;
break;
case 0x13 :
V_5 -> V_8 -> V_7 = 1280 ;
V_5 -> V_8 -> V_9 = 800 ;
V_5 -> V_8 -> V_10 = 0 ;
V_5 -> V_8 -> V_11 = 1 ;
break;
case 0x14 :
V_5 -> V_8 -> V_7 = 1360 ;
V_5 -> V_8 -> V_9 = 768 ;
V_5 -> V_8 -> V_10 = 0 ;
V_5 -> V_8 -> V_11 = 0 ;
break;
case 0x15 :
V_5 -> V_8 -> V_7 = 1280 ;
V_5 -> V_8 -> V_9 = 768 ;
V_5 -> V_8 -> V_10 = 1 ;
V_5 -> V_8 -> V_11 = 0 ;
break;
case 0x16 :
V_5 -> V_8 -> V_7 = 480 ;
V_5 -> V_8 -> V_9 = 640 ;
V_5 -> V_8 -> V_10 = 0 ;
V_5 -> V_8 -> V_11 = 1 ;
break;
case 0x17 :
V_5 -> V_8 -> V_7 = 1200 ;
V_5 -> V_8 -> V_9 = 900 ;
V_5 -> V_8 -> V_10 = 0 ;
V_5 -> V_8 -> V_11 = 0 ;
break;
default:
V_5 -> V_8 -> V_7 = 800 ;
V_5 -> V_8 -> V_9 = 600 ;
V_5 -> V_8 -> V_10 = 0 ;
V_5 -> V_8 -> V_11 = 1 ;
}
}
static int F_2 ( int V_36 )
{
T_2 V_37 ;
F_10 ( V_24 ,
( T_2 ) V_5 -> V_14 -> V_15 . V_28 ,
( T_2 ) V_36 , & V_37 ) ;
return V_37 ;
}
static void F_11 ( int V_38 , int V_39 , int V_40 ,
int V_41 )
{
int V_42 = 0 ;
int V_43 ;
struct V_44 * V_45 = NULL ;
F_4 ( V_3 L_15 ) ;
F_12 ( V_46 , V_34 , 0x07 , V_47 + V_48 + V_49 ) ;
if ( V_38 < V_40 ) {
switch ( V_5 -> V_14 -> V_25 ) {
case V_50 :
case V_51 :
V_42 =
F_13 ( V_38 , V_40 ) ;
V_43 =
V_52 . V_53 .
V_54 ;
V_45 = V_52 . V_53 . V_45 ;
F_14 ( V_42 ,
V_43 , V_45 , V_34 ) ;
break;
case V_55 :
case V_56 :
case V_57 :
case V_26 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
V_42 =
F_15 ( V_38 , V_40 ) ;
F_12 ( V_65 , V_34 , 0xC0 , V_66 + V_67 ) ;
V_43 =
V_68 . V_53 . V_54 ;
V_45 = V_68 . V_53 . V_45 ;
F_14 ( V_42 ,
V_43 , V_45 , V_34 ) ;
break;
}
F_4 ( V_3 L_16 , V_42 ) ;
} else {
F_12 ( V_65 , V_34 , 0x00 , V_66 ) ;
}
if ( V_39 < V_41 ) {
switch ( V_5 -> V_14 -> V_25 ) {
case V_50 :
case V_51 :
V_42 =
F_16 ( V_39 , V_41 ) ;
V_43 =
V_52 . V_69 .
V_54 ;
V_45 = V_52 . V_69 . V_45 ;
F_14 ( V_42 ,
V_43 , V_45 , V_34 ) ;
break;
case V_55 :
case V_56 :
case V_57 :
case V_26 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
V_42 =
F_17 ( V_39 , V_41 ) ;
F_12 ( V_65 , V_34 , 0x08 , V_70 ) ;
V_43 =
V_68 . V_69 . V_54 ;
V_45 = V_68 . V_69 . V_45 ;
F_14 ( V_42 ,
V_43 , V_45 , V_34 ) ;
break;
}
F_4 ( V_3 L_17 , V_42 ) ;
} else {
F_12 ( V_65 , V_34 , 0x00 , V_70 ) ;
}
}
static void F_18 (
struct V_71 * V_72 ,
struct V_73
* V_74 )
{
unsigned char V_75 , V_76 , V_77 , V_78 , V_79 ;
unsigned long V_80 = 0 ;
unsigned long V_81 ;
V_81 = V_72 -> V_82 * ( V_72 -> V_83 >> 3 ) ;
if ( V_81 & 0x1F ) {
V_80 = ( ( V_81 + 31 ) & ~ 31 ) >> 3 ;
if ( V_72 -> V_84 == V_85 ) {
if ( V_72 -> V_83 > 8 ) {
V_78 = ( unsigned char ) ( V_80 & 0xFF ) ;
F_19 ( V_86 , V_34 , V_78 ) ;
V_79 = F_9 ( V_34 , V_87 ) & 0xFC ;
V_79 |=
( unsigned
char ) ( ( V_80 & 0x300 ) >> 8 ) ;
F_19 ( V_87 , V_34 , V_79 ) ;
}
V_79 = F_9 ( V_34 , V_87 ) & 0xF3 ;
V_79 |= ( unsigned char ) ( ( V_80 & 0x600 ) >> 7 ) ;
F_19 ( V_87 , V_34 , V_79 ) ;
V_77 = ( unsigned char ) ( ( V_80 >> 1 ) & 0xFF ) ;
V_77 += 2 ;
F_19 ( V_88 , V_34 , V_77 ) ;
} else {
if ( V_72 -> V_83 > 8 ) {
V_75 = ( unsigned char ) ( V_80 & 0xFF ) ;
F_19 ( V_89 , V_34 , V_75 ) ;
V_76 = F_9 ( V_34 , V_90 ) & 0x1F ;
V_76 |=
( unsigned
char ) ( ( V_80 & 0x700 ) >> 3 ) ;
F_19 ( V_90 , V_34 , V_76 ) ;
}
}
}
}
static void F_20 ( struct V_71
* V_72 ,
struct V_73 * V_74 )
{
if ( V_91 == V_74 -> V_16 ) {
switch ( V_5 -> V_14 -> V_25 ) {
case V_60 :
F_21 ( V_72 ,
V_74 ) ;
break;
case V_59 :
F_22 ( V_72 ,
V_74 ) ;
break;
}
}
}
static void F_23 ( struct V_71
* V_72 ,
struct V_73 * V_74 )
{
if ( V_91 == V_74 -> V_16 ) {
switch ( V_5 -> V_14 -> V_25 ) {
case V_26 :
F_24 ( V_72 ,
V_74 ) ;
break;
}
}
}
static void F_25 ( struct V_71
* V_72 , struct V_73 * V_74 )
{
F_4 ( V_3 L_18 ) ;
switch ( V_74 -> V_92 ) {
case V_93 :
F_20 ( V_72 , V_74 ) ;
break;
case V_94 :
F_23 ( V_72 , V_74 ) ;
break;
case V_95 :
if ( V_60 == V_5 -> V_14 -> V_25 ) {
F_12 ( V_96 , V_34 , 0x08 ,
V_47 + V_48 + V_49 + V_70 ) ;
}
break;
}
}
void F_26 ( struct V_97 * V_98 ,
struct V_71 * V_72 ,
struct V_73 * V_74 )
{
int V_99 = V_72 -> V_84 ;
int V_100 = V_72 -> V_83 ;
int V_38 = V_72 -> V_82 ;
int V_39 = V_72 -> V_101 ;
int V_40 = V_72 -> V_7 ;
int V_41 = V_72 -> V_9 ;
T_3 clock ;
struct V_102 V_103 , V_104 ;
struct V_97 * V_105 = NULL ;
struct V_106 * V_107 = F_27 ( V_40 ,
V_41 ) ;
F_4 ( V_3 L_19 ) ;
V_103 = V_98 -> V_108 ;
V_105 = V_107 -> V_108 ;
V_104 = V_105 -> V_108 ;
F_4 ( V_3 L_20 ) ;
if ( V_91 == V_74 -> V_16 )
F_28 ( V_72 , V_74 ) ;
clock = V_104 . V_109 * V_104 . V_110
* V_105 -> V_111 ;
V_72 -> V_112 = clock ;
if ( V_99 == V_113 ) {
F_29 ( F_30
( V_103 , V_104 ) , V_113 ) ;
} else {
if ( V_72 -> V_114 == V_115
&& ( V_38 < V_40 || V_39 < V_41 ) ) {
F_29 ( V_104 , V_85 ) ;
F_4 ( V_3 L_21 ) ;
F_11 ( V_38 , V_39 , V_40 ,
V_41 ) ;
F_4 ( V_3 L_22 ) ;
} else {
F_29 ( F_30
( V_103 , V_104 ) , V_85 ) ;
F_12 ( V_46 , V_34 , 0x00 ,
V_47 + V_48 + V_49 ) ;
}
}
F_31 ( V_38 , V_100 / 8 , V_99 ) ;
if ( ( V_5 -> V_14 -> V_25 != V_50 )
&& ( V_5 -> V_14 -> V_25 != V_51 ) )
F_32 ( V_99 , V_38 , V_39 ) ;
F_33 () ;
F_34 ( clock , V_99 ) ;
F_25 ( V_72 , V_74 ) ;
if ( ( V_5 -> V_14 -> V_25 == V_55 )
|| ( V_58 == V_5 -> V_14 -> V_25 ) )
F_12 ( V_116 , V_34 , 0x01 , V_47 ) ;
F_18 ( V_72 , V_74 ) ;
}
static void F_35 ( struct V_71
* V_72 ,
struct V_73 * V_74 )
{
bool V_117 = false ;
bool V_118 = false ;
if ( V_119 == V_74 -> V_92 )
V_117 = true ;
if ( V_120 == V_74 -> V_92 )
V_117 = true ;
if ( V_121 == V_74 -> V_92 )
V_118 = true ;
if ( V_118 ) {
F_12 ( V_122 , V_34 , 0 , V_48 ) ;
F_12 ( V_123 , V_34 , 0xC0 , V_67 + V_66 ) ;
}
if ( V_117 ) {
F_12 ( V_116 , V_34 , 0 , V_70 ) ;
F_12 ( V_124 , V_34 , 0xC0 , V_67 + V_66 ) ;
}
switch ( V_74 -> V_92 ) {
case V_120 :
{
F_12 ( V_125 , V_34 , 0x80 , V_66 ) ;
break;
}
case V_121 :
{
F_12 ( V_125 , V_34 , 0x40 , V_67 ) ;
break;
}
case V_119 :
{
F_12 ( V_125 , V_34 , 0xC0 , V_67 + V_66 ) ;
break;
}
}
}
static void F_36 ( struct V_71
* V_72 ,
struct V_73 * V_74 )
{
F_4 ( V_3 L_23 ,
V_74 -> V_92 ) ;
if ( V_72 -> V_126 == V_127 )
F_12 ( V_125 , V_34 , 0x00 , V_47 + V_48 ) ;
else
F_12 ( V_125 , V_34 , 0x03 , V_47 + V_48 ) ;
switch ( V_74 -> V_92 ) {
case V_119 :
case V_120 :
F_12 ( V_124 , V_34 , 0 , V_47 ) ;
F_12 ( V_124 , V_34 , 0 , V_67 + V_66 ) ;
F_12 ( V_116 , V_34 , 0x08 , V_70 ) ;
break;
case V_121 :
F_12 ( V_123 , V_34 , 0 , V_47 ) ;
F_12 ( V_123 , V_34 , 0 , V_67 + V_66 ) ;
F_12 ( V_122 , V_34 , 0x02 , V_48 ) ;
break;
}
switch ( V_74 -> V_92 ) {
case V_120 :
{
F_12 ( V_125 , V_34 , 0 , V_66 ) ;
break;
}
case V_121 :
{
F_12 ( V_125 , V_34 , 0 , V_67 ) ;
break;
}
case V_119 :
{
F_12 ( V_125 , V_34 , 0 , V_67 + V_66 ) ;
break;
}
}
}
void F_37 ( void )
{
if ( V_5 -> V_14 -> V_25 == V_50 ) {
F_38 () ;
F_12 ( V_128 , V_129 , 0x00 , 0x30 ) ;
} else if ( V_5 -> V_14 -> V_25 == V_26 ) {
if ( V_130
&& ( V_18 ==
V_5 -> V_14 -> V_17 . V_16 ) )
F_35 ( V_5 -> V_8 ,
& V_5 -> V_14 -> V_17 ) ;
if ( V_18 ==
V_5 -> V_14 -> V_15 . V_16 )
F_35 ( V_5 -> V_8 ,
& V_5 -> V_14 -> V_15 ) ;
if ( V_91 == V_5 -> V_14 ->
V_15 . V_16 )
F_39 ( V_5 -> V_8 ,
& V_5 -> V_14 -> V_15 ) ;
} else if ( V_91 ==
V_5 -> V_14 -> V_15 . V_16 ) {
F_39 ( V_5 -> V_8 ,
& V_5 -> V_14 -> V_15 ) ;
} else {
F_12 ( V_131 , V_129 , 0x00 , 0x20 ) ;
F_12 ( V_124 , V_34 , 0x80 , 0x80 ) ;
}
F_12 ( V_46 , V_34 , 0x00 , 0x01 ) ;
F_12 ( V_132 , V_34 , 0x00 , 0x08 ) ;
}
static void F_40 ( int V_99 , int V_92 )
{
switch ( V_92 ) {
case V_133 :
if ( ( V_58 == V_5 -> V_14 -> V_25 )
|| ( V_59 ==
V_5 -> V_14 -> V_25 ) )
F_12 ( V_134 , V_34 , 0x84 ,
V_66 + V_49 + V_48 + V_47 ) ;
case V_93 :
case V_94 :
case V_135 :
case V_95 :
if ( V_99 == V_85 )
F_19 ( V_124 , V_34 , 0x00 ) ;
break;
}
}
void F_41 ( void )
{
F_12 ( V_132 , V_34 , 0x00 , V_70 ) ;
F_12 ( V_116 , V_34 , 0x08 , V_70 ) ;
F_40 ( V_5 -> V_8 -> V_84 ,
V_5 -> V_14 -> V_15 . V_92 ) ;
if ( V_130 )
F_40 ( V_5 -> V_6 -> V_84 ,
V_5 -> V_14 ->
V_17 . V_92 ) ;
if ( V_5 -> V_14 -> V_25 == V_50 ) {
F_12 ( V_128 , V_129 , 0x30 , 0x30 ) ;
F_42 () ;
} else if ( V_5 -> V_14 -> V_25 == V_26 ) {
if ( V_130 && ( V_18 ==
V_5 -> V_14 -> V_17 . V_16 ) )
F_36 ( V_5 -> V_6 , \
& V_5 -> V_14 -> V_17 ) ;
if ( V_18 ==
V_5 -> V_14 -> V_15 . V_16 )
F_36 ( V_5 -> V_8 ,
& V_5 -> V_14 -> V_15 ) ;
if ( V_91 == V_5 -> V_14 ->
V_15 . V_16 )
F_43 ( V_5 ->
V_8 , & V_5 -> V_14 ->
V_15 ) ;
} else if ( V_91 ==
V_5 -> V_14 -> V_15 . V_16 ) {
F_43 ( V_5 -> V_8 ,
& V_5 -> V_14 -> V_15 ) ;
} else {
F_12 ( V_131 , V_129 , 0x20 , 0x20 ) ;
F_12 ( V_124 , V_34 , 0x00 , 0x80 ) ;
F_12 ( V_116 , V_34 , 0x48 , 0x48 ) ;
}
}
static void F_38 ( void )
{
int V_136 , V_137 , V_37 ;
F_12 ( V_124 , V_34 , 0x11 , 0x11 ) ;
for ( V_136 = 0 ; V_136 < 3 ; V_136 ++ ) {
V_137 = V_138 [ 0 ] [ V_136 ] ;
V_37 = V_138 [ 1 ] [ V_136 ] & V_137 ;
F_12 ( V_124 , V_34 , ( T_2 ) V_37 , ( T_2 ) V_137 ) ;
F_44 ( V_138 [ 2 ] [ V_136 ] ) ;
}
F_12 ( V_116 , V_34 , 0x00 , 0x08 ) ;
}
static void F_42 ( void )
{
int V_136 , V_137 , V_37 ;
F_12 ( V_124 , V_34 , 0x11 , 0x11 ) ;
F_12 ( V_116 , V_34 , 0x08 , 0x08 ) ;
for ( V_136 = 0 ; V_136 < 3 ; V_136 ++ ) {
V_137 = V_139 [ 0 ] [ V_136 ] ;
V_37 = V_139 [ 1 ] [ V_136 ] & V_137 ;
F_12 ( V_124 , V_34 , ( T_2 ) V_37 , ( T_2 ) V_137 ) ;
F_44 ( V_139 [ 2 ] [ V_136 ] ) ;
}
F_44 ( 1 ) ;
}
static void F_33 ( void )
{
T_2 V_140 = 0 , V_141 = 0 ;
if ( V_5 -> V_8 -> V_10 )
V_141 = V_142 ;
if ( V_5 -> V_8 -> V_11 )
V_140 = V_47 ;
F_12 ( V_143 , V_34 , ( V_140 | V_141 ) , V_142 + V_47 ) ;
}
static void F_45 (
struct V_73 * V_74 ,
struct V_71
* V_72 )
{
switch ( V_12 ) {
case V_144 :
{
if ( V_72 -> V_10 ) {
V_74 -> V_92 =
V_119 ;
} else {
V_74 -> V_92 =
V_120 ;
}
break;
}
case V_20 :
{
V_74 -> V_92 = V_145 ;
break;
}
case V_19 :
case V_13 :
{
V_74 -> V_92 =
V_119 ;
break;
}
case V_146 :
{
V_74 -> V_92 = V_121 ;
break;
}
default:
{
V_74 -> V_92 = V_121 ;
break;
}
}
F_4 ( V_3
L_24 ,
V_12 ,
V_74 -> V_92 ) ;
}
void T_1 F_46 ( struct V_73
* V_74 ,
struct V_71
* V_72 )
{
if ( V_145 != V_74 -> V_92 ) {
return;
}
switch ( V_74 -> V_16 ) {
case V_91 :
switch ( V_5 -> V_14 -> V_25 ) {
case V_26 :
V_74 -> V_92 = V_94 ;
break;
case V_57 :
V_74 -> V_92 = V_95 ;
break;
default:
V_74 -> V_92 = V_93 ;
break;
}
break;
case V_18 :
F_45 ( V_74 ,
V_72 ) ;
break;
default:
switch ( V_5 -> V_14 -> V_25 ) {
case V_58 :
case V_60 :
case V_59 :
V_74 -> V_92 = V_95 ;
break;
default:
V_74 -> V_92 = V_133 ;
break;
}
break;
}
}
static struct V_102 F_30 ( struct V_102
V_103 ,
struct V_102 V_104 )
{
struct V_102 V_147 ;
V_147 . V_109 = V_104 . V_109 ;
V_147 . V_148 = V_103 . V_148 ;
V_147 . V_149 =
( V_104 . V_148 - V_103 . V_148 ) / 2 +
V_147 . V_148 ;
V_147 . V_150 = V_104 . V_150 ;
V_147 . V_151 =
( V_104 . V_151 -
V_104 . V_149 ) + V_147 . V_149 ;
V_147 . V_152 = V_104 . V_152 ;
V_147 . V_110 = V_104 . V_110 ;
V_147 . V_153 = V_103 . V_153 ;
V_147 . V_154 =
( V_104 . V_153 - V_103 . V_153 ) / 2 +
V_147 . V_153 ;
V_147 . V_155 = V_104 . V_155 ;
V_147 . V_156 =
( V_104 . V_156 -
V_104 . V_154 ) + V_147 . V_154 ;
V_147 . V_157 = V_104 . V_157 ;
return V_147 ;
}
bool F_47 ( bool * V_158 )
{
unsigned char T_4 * V_159 , * V_160 , * V_161 ;
T_2 V_162 ;
const T_3 V_163 = 0x000C0000 ;
T_5 V_164 ;
V_161 = F_48 ( V_163 , 0x10000 ) ;
V_164 = F_49 ( V_161 ) ;
if ( V_164 == 0xAA55 ) {
V_159 = V_161 + 0x1B ;
V_160 = V_161 + F_49 ( V_159 ) ;
V_159 = V_160 + 18 ;
V_159 = V_161 + F_49 ( V_159 ) ;
V_159 += 41 ;
V_162 = F_50 ( V_159 ) ;
if ( V_162 & 0x8 )
* V_158 = false ;
else
* V_158 = true ;
F_51 ( V_161 ) ;
return true ;
} else {
F_51 ( V_161 ) ;
return false ;
}
}
