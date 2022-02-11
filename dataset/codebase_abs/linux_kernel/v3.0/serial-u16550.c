static inline void F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 ) {
V_2 -> V_4 . V_5 = V_6 + ( V_7 + 255 ) / 256 ;
V_2 -> V_3 = 1 ;
F_2 ( & V_2 -> V_4 ) ;
}
}
static inline void F_3 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 ) {
F_4 ( & V_2 -> V_4 ) ;
V_2 -> V_3 = 0 ;
}
}
static inline void F_5 ( struct V_1 * V_2 )
{
unsigned short V_8 = V_2 -> V_8 ;
if ( V_2 -> V_9 > 0 ) {
F_6 ( V_2 -> V_10 [ V_8 ] , V_2 -> V_11 + V_12 ) ;
V_2 -> V_13 ++ ;
V_8 ++ ;
V_8 &= V_14 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_9 -- ;
}
}
static void F_7 ( struct V_1 * V_2 )
{
unsigned char V_15 , V_16 ;
int V_17 ;
V_17 = V_2 -> V_18 ;
while ( ( V_16 = F_8 ( V_2 -> V_11 + V_19 ) ) & V_20 ) {
V_15 = F_8 ( V_2 -> V_11 + V_21 ) ;
if ( V_15 & 0x80 )
V_2 -> V_22 = V_15 ;
if ( V_2 -> V_23 == V_24 ) {
if ( V_2 -> V_22 == 0xf5 ) {
if ( V_15 <= V_25 && V_15 > 0 )
V_17 = V_15 - 1 ;
if ( V_15 != 0xf5 )
V_2 -> V_22 = 0 ;
} else if ( ( V_2 -> V_26 & V_27 )
&& V_2 -> V_28 [ V_17 ] )
F_9 ( V_2 -> V_28 [ V_17 ] ,
& V_15 , 1 ) ;
} else if ( ( V_2 -> V_26 & V_27 ) &&
V_2 -> V_28 [ V_17 ] )
F_9 ( V_2 -> V_28 [ V_17 ] , & V_15 , 1 ) ;
if ( V_16 & V_29 )
F_10 ( V_30
L_1 ,
V_2 -> V_31 -> V_32 , V_2 -> V_11 ) ;
}
V_2 -> V_18 = V_17 ;
if ( V_16 & V_33 )
V_2 -> V_13 = 0 ;
if ( V_2 -> V_23 == V_34
|| V_2 -> V_23 == V_24 ) {
V_16 = F_8 ( V_2 -> V_11 + V_35 ) ;
while ( V_2 -> V_13 == 0 && ( V_16 & V_36 ) &&
V_2 -> V_9 > 0 ) {
F_5 ( V_2 ) ;
V_16 = F_8 ( V_2 -> V_11 + V_35 ) ;
}
} else {
while ( V_2 -> V_13 < V_2 -> V_37
&& V_2 -> V_9 > 0 )
F_5 ( V_2 ) ;
}
if ( V_2 -> V_38 < 0 && V_2 -> V_9 > 0 )
F_1 ( V_2 ) ;
}
static T_1 F_11 ( int V_38 , void * V_39 )
{
struct V_1 * V_2 ;
V_2 = V_39 ;
F_12 ( & V_2 -> V_40 ) ;
if ( V_2 -> V_26 == V_41 ) {
F_13 ( & V_2 -> V_40 ) ;
return V_42 ;
}
F_8 ( V_2 -> V_11 + V_43 ) ;
F_7 ( V_2 ) ;
F_13 ( & V_2 -> V_40 ) ;
return V_44 ;
}
static void F_14 ( unsigned long V_45 )
{
unsigned long V_46 ;
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) V_45 ;
F_15 ( & V_2 -> V_40 , V_46 ) ;
F_3 ( V_2 ) ;
F_7 ( V_2 ) ;
F_16 ( & V_2 -> V_40 , V_46 ) ;
}
static int T_2 F_17 ( struct V_1 * V_2 )
{
unsigned long V_47 = V_2 -> V_11 ;
int V_48 ;
unsigned char V_15 ;
if ( V_47 == 0 || V_47 == V_49 ) {
return - V_50 ;
}
V_2 -> V_51 = F_18 ( V_47 , 8 , L_2 ) ;
if ( V_2 -> V_51 == NULL ) {
F_10 ( V_52 L_3 , V_47 ) ;
return - V_53 ;
}
V_48 = 1 ;
F_6 ( V_54 , V_47 + V_55 ) ;
V_15 = F_8 ( V_47 + V_56 ) ;
if ( ( V_15 & 0xf0 ) != 0 )
V_48 = 0 ;
F_6 ( 0xaa , V_47 + V_57 ) ;
V_15 = F_8 ( V_47 + V_57 ) ;
if ( V_15 != 0xaa )
V_48 = 0 ;
F_6 ( 0x55 , V_47 + V_57 ) ;
V_15 = F_8 ( V_47 + V_57 ) ;
if ( V_15 != 0x55 )
V_48 = 0 ;
return V_48 ;
}
static void F_19 ( struct V_1 * V_2 )
{
char V_58 ;
V_2 -> V_9 = 0 ;
V_2 -> V_59 = 0 ;
V_2 -> V_8 = 0 ;
V_2 -> V_37 = 1 ;
V_2 -> V_13 = 0 ;
V_2 -> V_3 = 0 ;
F_6 ( V_60
| V_61
| V_62
| V_63
, V_2 -> V_11 + V_64 ) ;
if ( ( F_8 ( V_2 -> V_11 + V_43 ) & 0xf0 ) == 0xc0 )
V_2 -> V_37 = 16 ;
if ( V_2 -> V_65 != 0 ) {
V_2 -> V_66 = F_8 ( V_2 -> V_11 + V_55 ) ;
F_6 ( V_67
, V_2 -> V_11 + V_55 ) ;
V_2 -> V_68 = F_8 ( V_2 -> V_11 + V_69 ) ;
V_2 -> V_70 = F_8 ( V_2 -> V_11 + V_71 ) ;
F_6 ( V_2 -> V_65
, V_2 -> V_11 + V_69 ) ;
F_6 ( 0
, V_2 -> V_11 + V_71 ) ;
}
F_6 ( V_54
| 0
| 0
| 0
, V_2 -> V_11 + V_55 ) ;
switch ( V_2 -> V_23 ) {
default:
F_6 ( V_72
| V_73
| V_74
, V_2 -> V_11 + V_75 ) ;
break;
case V_34 :
case V_76 :
F_6 ( V_72 | ( 0 & V_73 ) | V_74 ,
V_2 -> V_11 + V_75 ) ;
break;
case V_77 :
F_6 ( V_72 | V_73 | V_74 ,
V_2 -> V_11 + V_75 ) ;
break;
}
if ( V_2 -> V_38 < 0 ) {
V_58 = ( 0 & V_78 )
| ( 0 & V_79 )
;
} else if ( V_2 -> V_23 == V_34 ) {
V_58 = V_78
| V_80
;
} else if ( V_2 -> V_23 == V_24 ) {
V_58 = V_78
| V_80
| V_79
;
} else {
V_58 = V_78
| V_79
;
}
F_6 ( V_58 , V_2 -> V_11 + V_56 ) ;
F_8 ( V_2 -> V_11 + V_19 ) ;
F_8 ( V_2 -> V_11 + V_43 ) ;
F_8 ( V_2 -> V_11 + V_21 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
if ( V_2 -> V_38 < 0 )
F_3 ( V_2 ) ;
F_6 ( ( 0 & V_78 )
| ( 0 & V_79 )
, V_2 -> V_11 + V_56 ) ;
switch ( V_2 -> V_23 ) {
default:
F_6 ( ( 0 & V_72 )
| ( 0 & V_73 )
| ( 0 & V_74 )
, V_2 -> V_11 + V_75 ) ;
break;
case V_34 :
case V_76 :
F_6 ( V_72 | ( 0 & V_73 ) | ( 0 & V_74 ) ,
V_2 -> V_11 + V_75 ) ;
break;
case V_77 :
F_6 ( V_72 | V_73 | ( 0 & V_74 ) ,
V_2 -> V_11 + V_75 ) ;
break;
}
F_8 ( V_2 -> V_11 + V_43 ) ;
if ( V_2 -> V_65 != 0 ) {
F_6 ( V_67
, V_2 -> V_11 + V_55 ) ;
F_6 ( V_2 -> V_68
, V_2 -> V_11 + V_69 ) ;
F_6 ( V_2 -> V_70
, V_2 -> V_11 + V_71 ) ;
F_6 ( V_2 -> V_66
, V_2 -> V_11 + V_55 ) ;
}
}
static int F_21 ( struct V_81 * V_17 )
{
unsigned long V_46 ;
struct V_1 * V_2 = V_17 -> V_31 -> V_82 ;
F_15 ( & V_2 -> V_40 , V_46 ) ;
if ( V_2 -> V_26 == V_41 )
F_19 ( V_2 ) ;
V_2 -> V_26 |= V_27 ;
V_2 -> V_28 [ V_17 -> V_83 ] = V_17 ;
F_16 ( & V_2 -> V_40 , V_46 ) ;
return 0 ;
}
static int F_22 ( struct V_81 * V_17 )
{
unsigned long V_46 ;
struct V_1 * V_2 = V_17 -> V_31 -> V_82 ;
F_15 ( & V_2 -> V_40 , V_46 ) ;
V_2 -> V_26 &= ~ V_27 ;
V_2 -> V_28 [ V_17 -> V_83 ] = NULL ;
if ( V_2 -> V_26 == V_41 )
F_20 ( V_2 ) ;
F_16 ( & V_2 -> V_40 , V_46 ) ;
return 0 ;
}
static void F_23 ( struct V_81 * V_17 ,
int V_84 )
{
unsigned long V_46 ;
struct V_1 * V_2 = V_17 -> V_31 -> V_82 ;
F_15 ( & V_2 -> V_40 , V_46 ) ;
if ( V_84 )
V_2 -> V_26 |= V_85 ;
else
V_2 -> V_26 &= ~ V_85 ;
F_16 ( & V_2 -> V_40 , V_46 ) ;
}
static int F_24 ( struct V_81 * V_17 )
{
unsigned long V_46 ;
struct V_1 * V_2 = V_17 -> V_31 -> V_82 ;
F_15 ( & V_2 -> V_40 , V_46 ) ;
if ( V_2 -> V_26 == V_41 )
F_19 ( V_2 ) ;
V_2 -> V_26 |= V_86 ;
V_2 -> V_87 [ V_17 -> V_83 ] = V_17 ;
F_16 ( & V_2 -> V_40 , V_46 ) ;
return 0 ;
}
static int F_25 ( struct V_81 * V_17 )
{
unsigned long V_46 ;
struct V_1 * V_2 = V_17 -> V_31 -> V_82 ;
F_15 ( & V_2 -> V_40 , V_46 ) ;
V_2 -> V_26 &= ~ V_86 ;
V_2 -> V_87 [ V_17 -> V_83 ] = NULL ;
if ( V_2 -> V_26 == V_41 )
F_20 ( V_2 ) ;
F_16 ( & V_2 -> V_40 , V_46 ) ;
return 0 ;
}
static inline int F_26 ( struct V_1 * V_2 ,
int V_88 )
{
if ( V_2 -> V_9 + V_88 < V_89 )
return 1 ;
else
return 0 ;
}
static inline int F_27 ( struct V_1 * V_2 ,
unsigned char V_58 )
{
unsigned short V_59 = V_2 -> V_59 ;
if ( V_2 -> V_9 < V_89 ) {
V_2 -> V_10 [ V_59 ] = V_58 ;
V_59 ++ ;
V_59 &= V_14 ;
V_2 -> V_59 = V_59 ;
V_2 -> V_9 ++ ;
if ( V_2 -> V_38 < 0 )
F_1 ( V_2 ) ;
return 1 ;
} else
return 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_81 * V_17 ,
unsigned char V_90 )
{
if ( V_2 -> V_9 == 0
&& ( ( V_2 -> V_23 != V_34 &&
V_2 -> V_23 != V_24 ) ||
( V_2 -> V_13 == 0
&& ( F_8 ( V_2 -> V_11 + V_35 ) & V_36 ) ) ) ) {
if ( ( F_8 ( V_2 -> V_11 + V_19 ) & V_33 ) != 0 ) {
V_2 -> V_13 = 1 ;
F_6 ( V_90 , V_2 -> V_11 + V_12 ) ;
} else {
if ( V_2 -> V_13 < V_2 -> V_37 ) {
V_2 -> V_13 ++ ;
F_6 ( V_90 , V_2 -> V_11 + V_12 ) ;
} else {
F_27 ( V_2 , V_90 ) ;
}
}
} else {
if ( ! F_27 ( V_2 , V_90 ) ) {
F_10 ( V_30
L_4 ,
V_2 -> V_31 -> V_32 , V_2 -> V_11 ) ;
return 0 ;
}
}
return 1 ;
}
static void F_29 ( struct V_81 * V_17 )
{
unsigned long V_46 ;
unsigned char V_90 , V_91 ;
struct V_1 * V_2 = V_17 -> V_31 -> V_82 ;
char V_92 ;
static unsigned long V_93 = 0 ;
F_15 ( & V_2 -> V_40 , V_46 ) ;
if ( V_2 -> V_38 < 0 )
F_7 ( V_2 ) ;
if ( V_2 -> V_23 == V_76 ) {
while ( 1 ) {
if ( V_2 -> V_9 > V_89 - 2 )
break;
if ( F_30 ( V_17 , & V_90 , 1 ) != 1 )
break;
#ifdef F_31
V_91 = ( 1 << ( V_17 -> V_83 + 4 ) ) | 0x08 ;
#else
V_91 = ( V_17 -> V_83 << 4 ) | 0x08 ;
if ( V_91 == 0x08 )
V_91 = 0xf8 ;
#endif
F_28 ( V_2 , V_17 , V_91 ) ;
F_28 ( V_2 , V_17 , V_90 ) ;
}
} else {
V_92 = 0 ;
while ( F_32 ( V_17 , & V_90 , 1 ) == 1 ) {
if ( V_92 == 0 &&
( V_2 -> V_23 == V_94 ||
V_2 -> V_23 == V_24 ) &&
( V_2 -> V_95 != V_17 -> V_83 ||
F_33 ( V_6 , V_93 + 3 * V_7 ) ) ) {
if ( F_26 ( V_2 , 3 ) ) {
V_2 -> V_95 = V_17 -> V_83 ;
F_28 ( V_2 , V_17 ,
0xf5 ) ;
F_28 ( V_2 , V_17 ,
V_2 -> V_95 + 1 ) ;
if ( V_90 < 0x80 &&
V_2 -> V_23 == V_94 )
F_28 ( V_2 , V_17 , V_2 -> V_96 [ V_2 -> V_95 ] ) ;
} else if ( ! V_2 -> V_97 )
break;
}
if ( ! F_28 ( V_2 , V_17 , V_90 ) &&
! V_2 -> V_97 )
break;
if ( V_90 >= 0x80 && V_90 < 0xf0 )
V_2 -> V_96 [ V_2 -> V_95 ] = V_90 ;
V_92 = 1 ;
F_34 ( V_17 , 1 ) ;
}
V_93 = V_6 ;
}
F_16 ( & V_2 -> V_40 , V_46 ) ;
}
static void F_35 ( struct V_81 * V_17 ,
int V_84 )
{
unsigned long V_46 ;
struct V_1 * V_2 = V_17 -> V_31 -> V_82 ;
F_15 ( & V_2 -> V_40 , V_46 ) ;
if ( V_84 )
V_2 -> V_26 |= V_98 ;
else
V_2 -> V_26 &= ~ V_98 ;
F_16 ( & V_2 -> V_40 , V_46 ) ;
if ( V_84 )
F_29 ( V_17 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
if ( V_2 -> V_38 >= 0 )
F_37 ( V_2 -> V_38 , V_2 ) ;
F_38 ( V_2 -> V_51 ) ;
F_39 ( V_2 ) ;
return 0 ;
}
static int F_40 ( struct V_99 * V_100 )
{
struct V_1 * V_2 = V_100 -> V_101 ;
return F_36 ( V_2 ) ;
}
static int T_2 F_41 ( struct V_102 * V_103 ,
unsigned long V_104 ,
int V_38 ,
unsigned int V_105 ,
unsigned int V_11 ,
int V_23 ,
int V_106 ,
struct V_1 * * V_107 )
{
static struct V_108 V_109 = {
. V_110 = F_40 ,
} ;
struct V_1 * V_2 ;
int V_111 ;
if ( ( V_2 = F_42 ( sizeof( * V_2 ) , V_112 ) ) == NULL )
return - V_113 ;
V_2 -> V_23 = V_23 ;
V_2 -> V_103 = V_103 ;
F_43 ( & V_2 -> V_40 ) ;
V_2 -> V_38 = - 1 ;
V_2 -> V_11 = V_104 ;
V_2 -> V_97 = V_106 ;
if ( ( V_111 = F_17 ( V_2 ) ) <= 0 ) {
F_44 ( V_52 L_5 , V_104 ) ;
F_36 ( V_2 ) ;
return - V_50 ;
}
if ( V_38 >= 0 && V_38 != V_114 ) {
if ( F_45 ( V_38 , F_11 ,
V_115 , L_2 , V_2 ) ) {
F_10 ( V_30
L_6 , V_38 ) ;
} else {
V_2 -> V_38 = V_38 ;
}
}
V_2 -> V_65 = V_11 / V_105 ;
V_2 -> V_105 = V_11 / ( unsigned int ) V_2 -> V_65 ;
V_2 -> V_116 = V_11 ;
V_2 -> V_95 = - 1 ;
V_2 -> V_18 = 0 ;
V_2 -> V_22 = 0 ;
memset ( V_2 -> V_96 , 0x80 , sizeof( unsigned char ) * V_117 ) ;
F_46 ( & V_2 -> V_4 ) ;
V_2 -> V_4 . V_118 = F_14 ;
V_2 -> V_4 . V_45 = ( unsigned long ) V_2 ;
V_2 -> V_3 = 0 ;
if ( ( V_111 = F_47 ( V_103 , V_119 , V_2 , & V_109 ) ) < 0 ) {
F_36 ( V_2 ) ;
return V_111 ;
}
switch ( V_2 -> V_23 ) {
case V_34 :
case V_76 :
F_6 ( V_72 | ( 0 & V_73 ) , V_2 -> V_11 + V_75 ) ;
break;
case V_77 :
F_6 ( V_72 | V_73 , V_2 -> V_11 + V_75 ) ;
break;
default:
break;
}
if ( V_107 )
* V_107 = V_2 ;
return 0 ;
}
static void T_2 F_48 ( struct V_120 * V_121 )
{
struct V_81 * V_17 ;
F_49 (substream, &stream->substreams, list) {
sprintf ( V_17 -> V_32 , L_7 , V_17 -> V_83 + 1 ) ;
}
}
static int T_2 F_50 ( struct V_1 * V_2 , int V_100 ,
int V_122 , int V_123 ,
struct V_124 * * V_31 )
{
struct V_124 * V_125 ;
int V_111 ;
V_111 = F_51 ( V_2 -> V_103 , L_8 , V_100 ,
V_122 , V_123 , & V_125 ) ;
if ( V_111 < 0 )
return V_111 ;
F_52 ( V_125 , V_126 ,
& V_127 ) ;
F_52 ( V_125 , V_128 ,
& V_129 ) ;
strcpy ( V_125 -> V_32 , L_2 ) ;
F_48 ( & V_125 -> V_130 [ V_128 ] ) ;
F_48 ( & V_125 -> V_130 [ V_126 ] ) ;
V_125 -> V_131 = V_132 |
V_133 |
V_134 ;
V_125 -> V_82 = V_2 ;
if ( V_31 )
* V_31 = V_125 ;
return 0 ;
}
static int T_2 F_53 ( struct V_135 * V_136 )
{
struct V_102 * V_103 ;
struct V_1 * V_2 ;
int V_111 ;
int V_137 = V_136 -> V_138 ;
switch ( V_23 [ V_137 ] ) {
case V_94 :
V_123 [ V_137 ] = 1 ;
break;
case V_77 :
case V_34 :
V_122 [ V_137 ] = 1 ;
V_123 [ V_137 ] = 1 ;
break;
case V_76 :
V_122 [ V_137 ] = 16 ;
V_123 [ V_137 ] = 1 ;
break;
case V_24 :
break;
default:
F_10 ( V_52
L_9 ,
V_139 , V_23 [ V_137 ] ) ;
return - V_50 ;
}
if ( V_122 [ V_137 ] < 1 || V_122 [ V_137 ] > V_117 ) {
F_10 ( V_52
L_10 ,
V_117 , V_122 [ V_137 ] ) ;
return - V_50 ;
}
if ( V_123 [ V_137 ] < 1 || V_123 [ V_137 ] > V_25 ) {
F_10 ( V_52
L_11 ,
V_25 , V_123 [ V_137 ] ) ;
return - V_50 ;
}
V_111 = F_54 ( V_140 [ V_137 ] , V_138 [ V_137 ] , V_141 , 0 , & V_103 ) ;
if ( V_111 < 0 )
return V_111 ;
strcpy ( V_103 -> V_142 , L_12 ) ;
strcpy ( V_103 -> V_143 , L_13 ) ;
if ( ( V_111 = F_41 ( V_103 ,
V_144 [ V_137 ] ,
V_38 [ V_137 ] ,
V_105 [ V_137 ] ,
V_11 [ V_137 ] ,
V_23 [ V_137 ] ,
V_106 [ V_137 ] ,
& V_2 ) ) < 0 )
goto V_145;
V_111 = F_50 ( V_2 , 0 , V_122 [ V_137 ] , V_123 [ V_137 ] , & V_2 -> V_31 ) ;
if ( V_111 < 0 )
goto V_145;
sprintf ( V_103 -> V_146 , L_14 ,
V_103 -> V_143 ,
V_147 [ V_2 -> V_23 ] ,
V_2 -> V_11 ,
V_2 -> V_38 ) ;
F_55 ( V_103 , & V_136 -> V_137 ) ;
if ( ( V_111 = F_56 ( V_103 ) ) < 0 )
goto V_145;
F_57 ( V_136 , V_103 ) ;
return 0 ;
V_145:
F_58 ( V_103 ) ;
return V_111 ;
}
static int T_3 F_59 ( struct V_135 * V_136 )
{
F_58 ( F_60 ( V_136 ) ) ;
F_57 ( V_136 , NULL ) ;
return 0 ;
}
static void F_61 ( void )
{
int V_148 ;
for ( V_148 = 0 ; V_148 < F_62 ( V_149 ) ; ++ V_148 )
F_63 ( V_149 [ V_148 ] ) ;
F_64 ( & V_150 ) ;
}
static int T_4 F_65 ( void )
{
int V_148 , V_151 , V_111 ;
if ( ( V_111 = F_66 ( & V_150 ) ) < 0 )
return V_111 ;
V_151 = 0 ;
for ( V_148 = 0 ; V_148 < V_152 ; V_148 ++ ) {
struct V_135 * V_100 ;
if ( ! V_153 [ V_148 ] )
continue;
V_100 = F_67 ( V_154 ,
V_148 , NULL , 0 ) ;
if ( F_68 ( V_100 ) )
continue;
if ( ! F_60 ( V_100 ) ) {
F_63 ( V_100 ) ;
continue;
}
V_149 [ V_148 ] = V_100 ;
V_151 ++ ;
}
if ( ! V_151 ) {
#ifdef F_69
F_44 ( V_52 L_15 ) ;
#endif
F_61 () ;
return - V_50 ;
}
return 0 ;
}
static void T_5 F_70 ( void )
{
F_61 () ;
}
