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
static void F_18 ( int V_71 , int V_72 , int V_73 )
{
unsigned char V_74 , V_75 , V_76 , V_77 , V_78 ;
unsigned long V_79 = 0 ;
unsigned long V_80 ;
V_80 = V_72 * ( V_73 >> 3 ) ;
if ( V_80 & 0x1F ) {
V_79 = ( ( V_80 + 31 ) & ~ 31 ) >> 3 ;
if ( V_71 == V_81 ) {
if ( V_73 > 8 ) {
V_77 = ( unsigned char ) ( V_79 & 0xFF ) ;
F_19 ( V_82 , V_34 , V_77 ) ;
V_78 = F_9 ( V_34 , V_83 ) & 0xFC ;
V_78 |=
( unsigned
char ) ( ( V_79 & 0x300 ) >> 8 ) ;
F_19 ( V_83 , V_34 , V_78 ) ;
}
V_78 = F_9 ( V_34 , V_83 ) & 0xF3 ;
V_78 |= ( unsigned char ) ( ( V_79 & 0x600 ) >> 7 ) ;
F_19 ( V_83 , V_34 , V_78 ) ;
V_76 = ( unsigned char ) ( ( V_79 >> 1 ) & 0xFF ) ;
V_76 += 2 ;
F_19 ( V_84 , V_34 , V_76 ) ;
} else {
if ( V_73 > 8 ) {
V_74 = ( unsigned char ) ( V_79 & 0xFF ) ;
F_19 ( V_85 , V_34 , V_74 ) ;
V_75 = F_9 ( V_34 , V_86 ) & 0x1F ;
V_75 |=
( unsigned
char ) ( ( V_79 & 0x700 ) >> 3 ) ;
F_19 ( V_86 , V_34 , V_75 ) ;
}
}
}
}
static void F_20 ( struct V_87
* V_88 ,
struct V_89 * V_90 )
{
if ( V_91 == V_90 -> V_16 ) {
switch ( V_5 -> V_14 -> V_25 ) {
case V_60 :
F_21 ( V_88 ,
V_90 ) ;
break;
case V_59 :
F_22 ( V_88 ,
V_90 ) ;
break;
}
}
}
static void F_23 ( struct V_87
* V_88 ,
struct V_89 * V_90 )
{
if ( V_91 == V_90 -> V_16 ) {
switch ( V_5 -> V_14 -> V_25 ) {
case V_26 :
F_24 ( V_88 ,
V_90 ) ;
break;
}
}
}
static void F_25 ( struct V_87
* V_88 , struct V_89 * V_90 )
{
F_4 ( V_3 L_18 ) ;
switch ( V_90 -> V_92 ) {
case V_93 :
F_20 ( V_88 , V_90 ) ;
break;
case V_94 :
F_23 ( V_88 , V_90 ) ;
break;
case V_95 :
if ( V_60 == V_5 -> V_14 -> V_25 ) {
F_12 ( V_96 , V_34 , 0x08 ,
V_47 + V_48 + V_49 + V_70 ) ;
}
break;
}
}
void F_26 ( const struct V_97 * V_98 , T_3 V_99 ,
T_3 V_100 , struct V_87 * V_88 ,
struct V_89 * V_90 )
{
int V_101 = V_88 -> V_71 ;
int V_102 = V_98 -> V_103 ;
int V_38 = V_99 ? V_99 : V_98 -> V_104 ;
int V_39 = V_100 ? V_100 : V_98 -> V_105 ;
int V_40 = V_88 -> V_7 ;
int V_41 = V_88 -> V_9 ;
T_4 clock ;
struct V_106 V_107 ;
struct V_97 V_108 ;
const struct V_109 * V_110 , * V_111 ;
F_4 ( V_3 L_19 ) ;
V_110 = F_27 ( V_38 , V_39 , 60 ) ;
V_111 = F_27 ( V_40 , V_41 , 60 ) ;
F_28 ( & V_108 , V_111 ) ;
F_4 ( V_3 L_20 ) ;
if ( V_91 == V_90 -> V_16 )
F_29 ( V_88 , V_90 ) ;
clock = F_30 ( V_111 -> V_112 ) * 1000 ;
V_88 -> V_113 = clock ;
if ( V_101 == V_81 && ( V_38 < V_40 || V_39 < V_41 )
&& V_88 -> V_114 == V_115 ) {
V_107 = F_31 ( & V_108 , V_40 , V_41 ) ;
F_11 ( V_38 , V_39 , V_40 , V_41 ) ;
} else {
V_107 = F_31 ( & V_108 , V_38 , V_39 ) ;
if ( V_101 == V_81 )
F_32 ( V_34 , 0x79 , 0x00 ,
V_47 + V_48 + V_49 ) ;
}
if ( V_101 == V_116 )
F_33 ( & V_107 ) ;
else if ( V_101 == V_81 )
F_34 ( & V_107 ) ;
F_35 ( V_38 , V_102 / 8 , V_101 ) ;
if ( ( V_5 -> V_14 -> V_25 != V_50 )
&& ( V_5 -> V_14 -> V_25 != V_51 ) )
F_36 ( V_101 , V_38 , V_39 ) ;
F_37 () ;
F_38 ( clock , V_101 ) ;
F_25 ( V_88 , V_90 ) ;
if ( ( V_5 -> V_14 -> V_25 == V_55 )
|| ( V_58 == V_5 -> V_14 -> V_25 ) )
F_12 ( V_117 , V_34 , 0x01 , V_47 ) ;
F_18 ( V_88 -> V_71 , V_38 ,
V_98 -> V_103 ) ;
}
static void F_39 ( struct V_87
* V_88 ,
struct V_89 * V_90 )
{
bool V_118 = false ;
bool V_119 = false ;
if ( V_120 == V_90 -> V_92 )
V_118 = true ;
if ( V_121 == V_90 -> V_92 )
V_118 = true ;
if ( V_122 == V_90 -> V_92 )
V_119 = true ;
if ( V_119 ) {
F_12 ( V_123 , V_34 , 0 , V_48 ) ;
F_12 ( V_124 , V_34 , 0xC0 , V_67 + V_66 ) ;
}
if ( V_118 ) {
F_12 ( V_117 , V_34 , 0 , V_70 ) ;
F_12 ( V_125 , V_34 , 0xC0 , V_67 + V_66 ) ;
}
switch ( V_90 -> V_92 ) {
case V_121 :
{
F_12 ( V_126 , V_34 , 0x80 , V_66 ) ;
break;
}
case V_122 :
{
F_12 ( V_126 , V_34 , 0x40 , V_67 ) ;
break;
}
case V_120 :
{
F_12 ( V_126 , V_34 , 0xC0 , V_67 + V_66 ) ;
break;
}
}
}
static void F_40 ( struct V_87
* V_88 ,
struct V_89 * V_90 )
{
F_4 ( V_3 L_21 ,
V_90 -> V_92 ) ;
if ( V_88 -> V_127 == V_128 )
F_12 ( V_126 , V_34 , 0x00 , V_47 + V_48 ) ;
else
F_12 ( V_126 , V_34 , 0x03 , V_47 + V_48 ) ;
switch ( V_90 -> V_92 ) {
case V_120 :
case V_121 :
F_12 ( V_125 , V_34 , 0 , V_47 ) ;
F_12 ( V_125 , V_34 , 0 , V_67 + V_66 ) ;
F_12 ( V_117 , V_34 , 0x08 , V_70 ) ;
break;
case V_122 :
F_12 ( V_124 , V_34 , 0 , V_47 ) ;
F_12 ( V_124 , V_34 , 0 , V_67 + V_66 ) ;
F_12 ( V_123 , V_34 , 0x02 , V_48 ) ;
break;
}
switch ( V_90 -> V_92 ) {
case V_121 :
{
F_12 ( V_126 , V_34 , 0 , V_66 ) ;
break;
}
case V_122 :
{
F_12 ( V_126 , V_34 , 0 , V_67 ) ;
break;
}
case V_120 :
{
F_12 ( V_126 , V_34 , 0 , V_67 + V_66 ) ;
break;
}
}
}
void F_41 ( void )
{
if ( V_5 -> V_14 -> V_25 == V_50 ) {
F_42 () ;
F_12 ( V_129 , V_130 , 0x00 , 0x30 ) ;
} else if ( V_5 -> V_14 -> V_25 == V_26 ) {
if ( V_131
&& ( V_18 ==
V_5 -> V_14 -> V_17 . V_16 ) )
F_39 ( V_5 -> V_8 ,
& V_5 -> V_14 -> V_17 ) ;
if ( V_18 ==
V_5 -> V_14 -> V_15 . V_16 )
F_39 ( V_5 -> V_8 ,
& V_5 -> V_14 -> V_15 ) ;
if ( V_91 == V_5 -> V_14 ->
V_15 . V_16 )
F_43 ( V_5 -> V_8 ,
& V_5 -> V_14 -> V_15 ) ;
} else if ( V_91 ==
V_5 -> V_14 -> V_15 . V_16 ) {
F_43 ( V_5 -> V_8 ,
& V_5 -> V_14 -> V_15 ) ;
} else {
F_12 ( V_132 , V_130 , 0x00 , 0x20 ) ;
F_12 ( V_125 , V_34 , 0x80 , 0x80 ) ;
}
F_12 ( V_46 , V_34 , 0x00 , 0x01 ) ;
F_12 ( V_133 , V_34 , 0x00 , 0x08 ) ;
}
static void F_44 ( int V_101 , int V_92 )
{
switch ( V_92 ) {
case V_134 :
if ( ( V_58 == V_5 -> V_14 -> V_25 )
|| ( V_59 ==
V_5 -> V_14 -> V_25 ) )
F_12 ( V_135 , V_34 , 0x84 ,
V_66 + V_49 + V_48 + V_47 ) ;
case V_93 :
case V_94 :
case V_136 :
case V_95 :
if ( V_101 == V_81 )
F_19 ( V_125 , V_34 , 0x00 ) ;
break;
}
}
void F_45 ( void )
{
F_12 ( V_133 , V_34 , 0x00 , V_70 ) ;
F_12 ( V_117 , V_34 , 0x08 , V_70 ) ;
F_44 ( V_5 -> V_8 -> V_71 ,
V_5 -> V_14 -> V_15 . V_92 ) ;
if ( V_131 )
F_44 ( V_5 -> V_6 -> V_71 ,
V_5 -> V_14 ->
V_17 . V_92 ) ;
if ( V_5 -> V_14 -> V_25 == V_50 ) {
F_12 ( V_129 , V_130 , 0x30 , 0x30 ) ;
F_46 () ;
} else if ( V_5 -> V_14 -> V_25 == V_26 ) {
if ( V_131 && ( V_18 ==
V_5 -> V_14 -> V_17 . V_16 ) )
F_40 ( V_5 -> V_6 , \
& V_5 -> V_14 -> V_17 ) ;
if ( V_18 ==
V_5 -> V_14 -> V_15 . V_16 )
F_40 ( V_5 -> V_8 ,
& V_5 -> V_14 -> V_15 ) ;
if ( V_91 == V_5 -> V_14 ->
V_15 . V_16 )
F_47 ( V_5 ->
V_8 , & V_5 -> V_14 ->
V_15 ) ;
} else if ( V_91 ==
V_5 -> V_14 -> V_15 . V_16 ) {
F_47 ( V_5 -> V_8 ,
& V_5 -> V_14 -> V_15 ) ;
} else {
F_12 ( V_132 , V_130 , 0x20 , 0x20 ) ;
F_12 ( V_125 , V_34 , 0x00 , 0x80 ) ;
F_12 ( V_117 , V_34 , 0x48 , 0x48 ) ;
}
}
static void F_42 ( void )
{
int V_137 , V_138 , V_37 ;
F_12 ( V_125 , V_34 , 0x11 , 0x11 ) ;
for ( V_137 = 0 ; V_137 < 3 ; V_137 ++ ) {
V_138 = V_139 [ 0 ] [ V_137 ] ;
V_37 = V_139 [ 1 ] [ V_137 ] & V_138 ;
F_12 ( V_125 , V_34 , ( T_2 ) V_37 , ( T_2 ) V_138 ) ;
F_48 ( V_139 [ 2 ] [ V_137 ] ) ;
}
F_12 ( V_117 , V_34 , 0x00 , 0x08 ) ;
}
static void F_46 ( void )
{
int V_137 , V_138 , V_37 ;
F_12 ( V_125 , V_34 , 0x11 , 0x11 ) ;
F_12 ( V_117 , V_34 , 0x08 , 0x08 ) ;
for ( V_137 = 0 ; V_137 < 3 ; V_137 ++ ) {
V_138 = V_140 [ 0 ] [ V_137 ] ;
V_37 = V_140 [ 1 ] [ V_137 ] & V_138 ;
F_12 ( V_125 , V_34 , ( T_2 ) V_37 , ( T_2 ) V_138 ) ;
F_48 ( V_140 [ 2 ] [ V_137 ] ) ;
}
F_48 ( 1 ) ;
}
static void F_37 ( void )
{
T_2 V_141 = 0 , V_142 = 0 ;
if ( V_5 -> V_8 -> V_10 )
V_142 = V_143 ;
if ( V_5 -> V_8 -> V_11 )
V_141 = V_47 ;
F_12 ( V_144 , V_34 , ( V_141 | V_142 ) , V_143 + V_47 ) ;
}
static void F_49 (
struct V_89 * V_90 ,
struct V_87
* V_88 )
{
switch ( V_12 ) {
case V_145 :
{
if ( V_88 -> V_10 ) {
V_90 -> V_92 =
V_120 ;
} else {
V_90 -> V_92 =
V_121 ;
}
break;
}
case V_20 :
{
V_90 -> V_92 = V_146 ;
break;
}
case V_19 :
case V_13 :
{
V_90 -> V_92 =
V_120 ;
break;
}
case V_147 :
{
V_90 -> V_92 = V_122 ;
break;
}
default:
{
V_90 -> V_92 = V_122 ;
break;
}
}
F_4 ( V_3
L_22 ,
V_12 ,
V_90 -> V_92 ) ;
}
void T_1 F_50 ( struct V_89
* V_90 ,
struct V_87
* V_88 )
{
if ( V_146 != V_90 -> V_92 ) {
return;
}
switch ( V_90 -> V_16 ) {
case V_91 :
switch ( V_5 -> V_14 -> V_25 ) {
case V_26 :
V_90 -> V_92 = V_94 ;
break;
case V_57 :
V_90 -> V_92 = V_95 ;
break;
default:
V_90 -> V_92 = V_93 ;
break;
}
break;
case V_18 :
F_49 ( V_90 ,
V_88 ) ;
break;
default:
switch ( V_5 -> V_14 -> V_25 ) {
case V_58 :
case V_60 :
case V_59 :
V_90 -> V_92 = V_95 ;
break;
default:
V_90 -> V_92 = V_134 ;
break;
}
break;
}
}
bool F_51 ( bool * V_148 )
{
unsigned char T_5 * V_149 , * V_150 , * V_151 ;
T_2 V_152 ;
const T_4 V_153 = 0x000C0000 ;
T_3 V_154 ;
V_151 = F_52 ( V_153 , 0x10000 ) ;
V_154 = F_53 ( V_151 ) ;
if ( V_154 == 0xAA55 ) {
V_149 = V_151 + 0x1B ;
V_150 = V_151 + F_53 ( V_149 ) ;
V_149 = V_150 + 18 ;
V_149 = V_151 + F_53 ( V_149 ) ;
V_149 += 41 ;
V_152 = F_54 ( V_149 ) ;
if ( V_152 & 0x8 )
* V_148 = false ;
else
* V_148 = true ;
F_55 ( V_151 ) ;
return true ;
} else {
F_55 ( V_151 ) ;
return false ;
}
}
