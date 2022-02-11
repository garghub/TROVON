static inline void F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 ) {
F_2 ( & V_2 -> V_4 , V_5 + ( V_6 + 255 ) / 256 ) ;
V_2 -> V_3 = 1 ;
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
unsigned short V_7 = V_2 -> V_7 ;
if ( V_2 -> V_8 > 0 ) {
F_6 ( V_2 -> V_9 [ V_7 ] , V_2 -> V_10 + V_11 ) ;
V_2 -> V_12 ++ ;
V_7 ++ ;
V_7 &= V_13 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_8 -- ;
}
}
static void F_7 ( struct V_1 * V_2 )
{
unsigned char V_14 , V_15 ;
int V_16 ;
V_16 = V_2 -> V_17 ;
while ( ( V_15 = F_8 ( V_2 -> V_10 + V_18 ) ) & V_19 ) {
V_14 = F_8 ( V_2 -> V_10 + V_20 ) ;
if ( V_14 & 0x80 )
V_2 -> V_21 = V_14 ;
if ( V_2 -> V_22 == V_23 ) {
if ( V_2 -> V_21 == 0xf5 ) {
if ( V_14 <= V_24 && V_14 > 0 )
V_16 = V_14 - 1 ;
if ( V_14 != 0xf5 )
V_2 -> V_21 = 0 ;
} else if ( ( V_2 -> V_25 & V_26 )
&& V_2 -> V_27 [ V_16 ] )
F_9 ( V_2 -> V_27 [ V_16 ] ,
& V_14 , 1 ) ;
} else if ( ( V_2 -> V_25 & V_26 ) &&
V_2 -> V_27 [ V_16 ] )
F_9 ( V_2 -> V_27 [ V_16 ] , & V_14 , 1 ) ;
if ( V_15 & V_28 )
F_10 ( V_29
L_1 ,
V_2 -> V_30 -> V_31 , V_2 -> V_10 ) ;
}
V_2 -> V_17 = V_16 ;
if ( V_15 & V_32 )
V_2 -> V_12 = 0 ;
if ( V_2 -> V_22 == V_33
|| V_2 -> V_22 == V_23 ) {
V_15 = F_8 ( V_2 -> V_10 + V_34 ) ;
while ( V_2 -> V_12 == 0 && ( V_15 & V_35 ) &&
V_2 -> V_8 > 0 ) {
F_5 ( V_2 ) ;
V_15 = F_8 ( V_2 -> V_10 + V_34 ) ;
}
} else {
while ( V_2 -> V_12 < V_2 -> V_36
&& V_2 -> V_8 > 0 )
F_5 ( V_2 ) ;
}
if ( V_2 -> V_37 < 0 && V_2 -> V_8 > 0 )
F_1 ( V_2 ) ;
}
static T_1 F_11 ( int V_37 , void * V_38 )
{
struct V_1 * V_2 ;
V_2 = V_38 ;
F_12 ( & V_2 -> V_39 ) ;
if ( V_2 -> V_25 == V_40 ) {
F_13 ( & V_2 -> V_39 ) ;
return V_41 ;
}
F_8 ( V_2 -> V_10 + V_42 ) ;
F_7 ( V_2 ) ;
F_13 ( & V_2 -> V_39 ) ;
return V_43 ;
}
static void F_14 ( unsigned long V_44 )
{
unsigned long V_45 ;
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) V_44 ;
F_15 ( & V_2 -> V_39 , V_45 ) ;
F_3 ( V_2 ) ;
F_7 ( V_2 ) ;
F_16 ( & V_2 -> V_39 , V_45 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
unsigned long V_46 = V_2 -> V_10 ;
int V_47 ;
unsigned char V_14 ;
if ( V_46 == 0 || V_46 == V_48 ) {
return - V_49 ;
}
V_2 -> V_50 = F_18 ( V_46 , 8 , L_2 ) ;
if ( V_2 -> V_50 == NULL ) {
F_10 ( V_51 L_3 , V_46 ) ;
return - V_52 ;
}
V_47 = 1 ;
F_6 ( V_53 , V_46 + V_54 ) ;
V_14 = F_8 ( V_46 + V_55 ) ;
if ( ( V_14 & 0xf0 ) != 0 )
V_47 = 0 ;
F_6 ( 0xaa , V_46 + V_56 ) ;
V_14 = F_8 ( V_46 + V_56 ) ;
if ( V_14 != 0xaa )
V_47 = 0 ;
F_6 ( 0x55 , V_46 + V_56 ) ;
V_14 = F_8 ( V_46 + V_56 ) ;
if ( V_14 != 0x55 )
V_47 = 0 ;
return V_47 ;
}
static void F_19 ( struct V_1 * V_2 )
{
char V_57 ;
V_2 -> V_8 = 0 ;
V_2 -> V_58 = 0 ;
V_2 -> V_7 = 0 ;
V_2 -> V_36 = 1 ;
V_2 -> V_12 = 0 ;
V_2 -> V_3 = 0 ;
F_6 ( V_59
| V_60
| V_61
| V_62
, V_2 -> V_10 + V_63 ) ;
if ( ( F_8 ( V_2 -> V_10 + V_42 ) & 0xf0 ) == 0xc0 )
V_2 -> V_36 = 16 ;
if ( V_2 -> V_64 != 0 ) {
V_2 -> V_65 = F_8 ( V_2 -> V_10 + V_54 ) ;
F_6 ( V_66
, V_2 -> V_10 + V_54 ) ;
V_2 -> V_67 = F_8 ( V_2 -> V_10 + V_68 ) ;
V_2 -> V_69 = F_8 ( V_2 -> V_10 + V_70 ) ;
F_6 ( V_2 -> V_64
, V_2 -> V_10 + V_68 ) ;
F_6 ( 0
, V_2 -> V_10 + V_70 ) ;
}
F_6 ( V_53
| 0
| 0
| 0
, V_2 -> V_10 + V_54 ) ;
switch ( V_2 -> V_22 ) {
default:
F_6 ( V_71
| V_72
| V_73
, V_2 -> V_10 + V_74 ) ;
break;
case V_33 :
case V_75 :
F_6 ( V_71 | ( 0 & V_72 ) | V_73 ,
V_2 -> V_10 + V_74 ) ;
break;
case V_76 :
F_6 ( V_71 | V_72 | V_73 ,
V_2 -> V_10 + V_74 ) ;
break;
}
if ( V_2 -> V_37 < 0 ) {
V_57 = ( 0 & V_77 )
| ( 0 & V_78 )
;
} else if ( V_2 -> V_22 == V_33 ) {
V_57 = V_77
| V_79
;
} else if ( V_2 -> V_22 == V_23 ) {
V_57 = V_77
| V_79
| V_78
;
} else {
V_57 = V_77
| V_78
;
}
F_6 ( V_57 , V_2 -> V_10 + V_55 ) ;
F_8 ( V_2 -> V_10 + V_18 ) ;
F_8 ( V_2 -> V_10 + V_42 ) ;
F_8 ( V_2 -> V_10 + V_20 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
if ( V_2 -> V_37 < 0 )
F_3 ( V_2 ) ;
F_6 ( ( 0 & V_77 )
| ( 0 & V_78 )
, V_2 -> V_10 + V_55 ) ;
switch ( V_2 -> V_22 ) {
default:
F_6 ( ( 0 & V_71 )
| ( 0 & V_72 )
| ( 0 & V_73 )
, V_2 -> V_10 + V_74 ) ;
break;
case V_33 :
case V_75 :
F_6 ( V_71 | ( 0 & V_72 ) | ( 0 & V_73 ) ,
V_2 -> V_10 + V_74 ) ;
break;
case V_76 :
F_6 ( V_71 | V_72 | ( 0 & V_73 ) ,
V_2 -> V_10 + V_74 ) ;
break;
}
F_8 ( V_2 -> V_10 + V_42 ) ;
if ( V_2 -> V_64 != 0 ) {
F_6 ( V_66
, V_2 -> V_10 + V_54 ) ;
F_6 ( V_2 -> V_67
, V_2 -> V_10 + V_68 ) ;
F_6 ( V_2 -> V_69
, V_2 -> V_10 + V_70 ) ;
F_6 ( V_2 -> V_65
, V_2 -> V_10 + V_54 ) ;
}
}
static int F_21 ( struct V_80 * V_16 )
{
unsigned long V_45 ;
struct V_1 * V_2 = V_16 -> V_30 -> V_81 ;
F_15 ( & V_2 -> V_39 , V_45 ) ;
if ( V_2 -> V_25 == V_40 )
F_19 ( V_2 ) ;
V_2 -> V_25 |= V_26 ;
V_2 -> V_27 [ V_16 -> V_82 ] = V_16 ;
F_16 ( & V_2 -> V_39 , V_45 ) ;
return 0 ;
}
static int F_22 ( struct V_80 * V_16 )
{
unsigned long V_45 ;
struct V_1 * V_2 = V_16 -> V_30 -> V_81 ;
F_15 ( & V_2 -> V_39 , V_45 ) ;
V_2 -> V_25 &= ~ V_26 ;
V_2 -> V_27 [ V_16 -> V_82 ] = NULL ;
if ( V_2 -> V_25 == V_40 )
F_20 ( V_2 ) ;
F_16 ( & V_2 -> V_39 , V_45 ) ;
return 0 ;
}
static void F_23 ( struct V_80 * V_16 ,
int V_83 )
{
unsigned long V_45 ;
struct V_1 * V_2 = V_16 -> V_30 -> V_81 ;
F_15 ( & V_2 -> V_39 , V_45 ) ;
if ( V_83 )
V_2 -> V_25 |= V_84 ;
else
V_2 -> V_25 &= ~ V_84 ;
F_16 ( & V_2 -> V_39 , V_45 ) ;
}
static int F_24 ( struct V_80 * V_16 )
{
unsigned long V_45 ;
struct V_1 * V_2 = V_16 -> V_30 -> V_81 ;
F_15 ( & V_2 -> V_39 , V_45 ) ;
if ( V_2 -> V_25 == V_40 )
F_19 ( V_2 ) ;
V_2 -> V_25 |= V_85 ;
V_2 -> V_86 [ V_16 -> V_82 ] = V_16 ;
F_16 ( & V_2 -> V_39 , V_45 ) ;
return 0 ;
}
static int F_25 ( struct V_80 * V_16 )
{
unsigned long V_45 ;
struct V_1 * V_2 = V_16 -> V_30 -> V_81 ;
F_15 ( & V_2 -> V_39 , V_45 ) ;
V_2 -> V_25 &= ~ V_85 ;
V_2 -> V_86 [ V_16 -> V_82 ] = NULL ;
if ( V_2 -> V_25 == V_40 )
F_20 ( V_2 ) ;
F_16 ( & V_2 -> V_39 , V_45 ) ;
return 0 ;
}
static inline int F_26 ( struct V_1 * V_2 ,
int V_87 )
{
if ( V_2 -> V_8 + V_87 < V_88 )
return 1 ;
else
return 0 ;
}
static inline int F_27 ( struct V_1 * V_2 ,
unsigned char V_57 )
{
unsigned short V_58 = V_2 -> V_58 ;
if ( V_2 -> V_8 < V_88 ) {
V_2 -> V_9 [ V_58 ] = V_57 ;
V_58 ++ ;
V_58 &= V_13 ;
V_2 -> V_58 = V_58 ;
V_2 -> V_8 ++ ;
if ( V_2 -> V_37 < 0 )
F_1 ( V_2 ) ;
return 1 ;
} else
return 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_80 * V_16 ,
unsigned char V_89 )
{
if ( V_2 -> V_8 == 0
&& ( ( V_2 -> V_22 != V_33 &&
V_2 -> V_22 != V_23 ) ||
( V_2 -> V_12 == 0
&& ( F_8 ( V_2 -> V_10 + V_34 ) & V_35 ) ) ) ) {
if ( ( F_8 ( V_2 -> V_10 + V_18 ) & V_32 ) != 0 ) {
V_2 -> V_12 = 1 ;
F_6 ( V_89 , V_2 -> V_10 + V_11 ) ;
} else {
if ( V_2 -> V_12 < V_2 -> V_36 ) {
V_2 -> V_12 ++ ;
F_6 ( V_89 , V_2 -> V_10 + V_11 ) ;
} else {
F_27 ( V_2 , V_89 ) ;
}
}
} else {
if ( ! F_27 ( V_2 , V_89 ) ) {
F_10 ( V_29
L_4 ,
V_2 -> V_30 -> V_31 , V_2 -> V_10 ) ;
return 0 ;
}
}
return 1 ;
}
static void F_29 ( struct V_80 * V_16 )
{
unsigned long V_45 ;
unsigned char V_89 , V_90 ;
struct V_1 * V_2 = V_16 -> V_30 -> V_81 ;
char V_91 ;
static unsigned long V_92 = 0 ;
F_15 ( & V_2 -> V_39 , V_45 ) ;
if ( V_2 -> V_37 < 0 )
F_7 ( V_2 ) ;
if ( V_2 -> V_22 == V_75 ) {
while ( 1 ) {
if ( V_2 -> V_8 > V_88 - 2 )
break;
if ( F_30 ( V_16 , & V_89 , 1 ) != 1 )
break;
#ifdef F_31
V_90 = ( 1 << ( V_16 -> V_82 + 4 ) ) | 0x08 ;
#else
V_90 = ( V_16 -> V_82 << 4 ) | 0x08 ;
if ( V_90 == 0x08 )
V_90 = 0xf8 ;
#endif
F_28 ( V_2 , V_16 , V_90 ) ;
F_28 ( V_2 , V_16 , V_89 ) ;
}
} else {
V_91 = 0 ;
while ( F_32 ( V_16 , & V_89 , 1 ) == 1 ) {
if ( V_91 == 0 &&
( V_2 -> V_22 == V_93 ||
V_2 -> V_22 == V_23 ) &&
( V_2 -> V_94 != V_16 -> V_82 ||
F_33 ( V_5 , V_92 + 3 * V_6 ) ) ) {
if ( F_26 ( V_2 , 3 ) ) {
V_2 -> V_94 = V_16 -> V_82 ;
F_28 ( V_2 , V_16 ,
0xf5 ) ;
F_28 ( V_2 , V_16 ,
V_2 -> V_94 + 1 ) ;
if ( V_89 < 0x80 &&
V_2 -> V_22 == V_93 )
F_28 ( V_2 , V_16 , V_2 -> V_95 [ V_2 -> V_94 ] ) ;
} else if ( ! V_2 -> V_96 )
break;
}
if ( ! F_28 ( V_2 , V_16 , V_89 ) &&
! V_2 -> V_96 )
break;
if ( V_89 >= 0x80 && V_89 < 0xf0 )
V_2 -> V_95 [ V_2 -> V_94 ] = V_89 ;
V_91 = 1 ;
F_34 ( V_16 , 1 ) ;
}
V_92 = V_5 ;
}
F_16 ( & V_2 -> V_39 , V_45 ) ;
}
static void F_35 ( struct V_80 * V_16 ,
int V_83 )
{
unsigned long V_45 ;
struct V_1 * V_2 = V_16 -> V_30 -> V_81 ;
F_15 ( & V_2 -> V_39 , V_45 ) ;
if ( V_83 )
V_2 -> V_25 |= V_97 ;
else
V_2 -> V_25 &= ~ V_97 ;
F_16 ( & V_2 -> V_39 , V_45 ) ;
if ( V_83 )
F_29 ( V_16 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
if ( V_2 -> V_37 >= 0 )
F_37 ( V_2 -> V_37 , V_2 ) ;
F_38 ( V_2 -> V_50 ) ;
F_39 ( V_2 ) ;
return 0 ;
}
static int F_40 ( struct V_98 * V_99 )
{
struct V_1 * V_2 = V_99 -> V_100 ;
return F_36 ( V_2 ) ;
}
static int F_41 ( struct V_101 * V_102 ,
unsigned long V_103 ,
int V_37 ,
unsigned int V_104 ,
unsigned int V_10 ,
int V_22 ,
int V_105 ,
struct V_1 * * V_106 )
{
static struct V_107 V_108 = {
. V_109 = F_40 ,
} ;
struct V_1 * V_2 ;
int V_110 ;
if ( ( V_2 = F_42 ( sizeof( * V_2 ) , V_111 ) ) == NULL )
return - V_112 ;
V_2 -> V_22 = V_22 ;
V_2 -> V_102 = V_102 ;
F_43 ( & V_2 -> V_39 ) ;
V_2 -> V_37 = - 1 ;
V_2 -> V_10 = V_103 ;
V_2 -> V_96 = V_105 ;
if ( ( V_110 = F_17 ( V_2 ) ) <= 0 ) {
F_44 ( V_51 L_5 , V_103 ) ;
F_36 ( V_2 ) ;
return - V_49 ;
}
if ( V_37 >= 0 && V_37 != V_113 ) {
if ( F_45 ( V_37 , F_11 ,
0 , L_2 , V_2 ) ) {
F_10 ( V_29
L_6 , V_37 ) ;
} else {
V_2 -> V_37 = V_37 ;
}
}
V_2 -> V_64 = V_10 / V_104 ;
V_2 -> V_104 = V_10 / ( unsigned int ) V_2 -> V_64 ;
V_2 -> V_114 = V_10 ;
V_2 -> V_94 = - 1 ;
V_2 -> V_17 = 0 ;
V_2 -> V_21 = 0 ;
memset ( V_2 -> V_95 , 0x80 , sizeof( unsigned char ) * V_115 ) ;
F_46 ( & V_2 -> V_4 , F_14 ,
( unsigned long ) V_2 ) ;
V_2 -> V_3 = 0 ;
if ( ( V_110 = F_47 ( V_102 , V_116 , V_2 , & V_108 ) ) < 0 ) {
F_36 ( V_2 ) ;
return V_110 ;
}
switch ( V_2 -> V_22 ) {
case V_33 :
case V_75 :
F_6 ( V_71 | ( 0 & V_72 ) , V_2 -> V_10 + V_74 ) ;
break;
case V_76 :
F_6 ( V_71 | V_72 , V_2 -> V_10 + V_74 ) ;
break;
default:
break;
}
if ( V_106 )
* V_106 = V_2 ;
return 0 ;
}
static void F_48 ( struct V_117 * V_118 )
{
struct V_80 * V_16 ;
F_49 (substream, &stream->substreams, list) {
sprintf ( V_16 -> V_31 , L_7 , V_16 -> V_82 + 1 ) ;
}
}
static int F_50 ( struct V_1 * V_2 , int V_99 ,
int V_119 , int V_120 ,
struct V_121 * * V_30 )
{
struct V_121 * V_122 ;
int V_110 ;
V_110 = F_51 ( V_2 -> V_102 , L_8 , V_99 ,
V_119 , V_120 , & V_122 ) ;
if ( V_110 < 0 )
return V_110 ;
F_52 ( V_122 , V_123 ,
& V_124 ) ;
F_52 ( V_122 , V_125 ,
& V_126 ) ;
strcpy ( V_122 -> V_31 , L_2 ) ;
F_48 ( & V_122 -> V_127 [ V_125 ] ) ;
F_48 ( & V_122 -> V_127 [ V_123 ] ) ;
V_122 -> V_128 = V_129 |
V_130 |
V_131 ;
V_122 -> V_81 = V_2 ;
if ( V_30 )
* V_30 = V_122 ;
return 0 ;
}
static int F_53 ( struct V_132 * V_133 )
{
struct V_101 * V_102 ;
struct V_1 * V_2 ;
int V_110 ;
int V_134 = V_133 -> V_135 ;
switch ( V_22 [ V_134 ] ) {
case V_93 :
V_120 [ V_134 ] = 1 ;
break;
case V_76 :
case V_33 :
V_119 [ V_134 ] = 1 ;
V_120 [ V_134 ] = 1 ;
break;
case V_75 :
V_119 [ V_134 ] = 16 ;
V_120 [ V_134 ] = 1 ;
break;
case V_23 :
break;
default:
F_10 ( V_51
L_9 ,
V_136 , V_22 [ V_134 ] ) ;
return - V_49 ;
}
if ( V_119 [ V_134 ] < 1 || V_119 [ V_134 ] > V_115 ) {
F_10 ( V_51
L_10 ,
V_115 , V_119 [ V_134 ] ) ;
return - V_49 ;
}
if ( V_120 [ V_134 ] < 1 || V_120 [ V_134 ] > V_24 ) {
F_10 ( V_51
L_11 ,
V_24 , V_120 [ V_134 ] ) ;
return - V_49 ;
}
V_110 = F_54 ( & V_133 -> V_134 , V_137 [ V_134 ] , V_135 [ V_134 ] , V_138 ,
0 , & V_102 ) ;
if ( V_110 < 0 )
return V_110 ;
strcpy ( V_102 -> V_139 , L_12 ) ;
strcpy ( V_102 -> V_140 , L_13 ) ;
if ( ( V_110 = F_41 ( V_102 ,
V_141 [ V_134 ] ,
V_37 [ V_134 ] ,
V_104 [ V_134 ] ,
V_10 [ V_134 ] ,
V_22 [ V_134 ] ,
V_105 [ V_134 ] ,
& V_2 ) ) < 0 )
goto V_142;
V_110 = F_50 ( V_2 , 0 , V_119 [ V_134 ] , V_120 [ V_134 ] , & V_2 -> V_30 ) ;
if ( V_110 < 0 )
goto V_142;
sprintf ( V_102 -> V_143 , L_14 ,
V_102 -> V_140 ,
V_144 [ V_2 -> V_22 ] ,
V_2 -> V_10 ,
V_2 -> V_37 ) ;
if ( ( V_110 = F_55 ( V_102 ) ) < 0 )
goto V_142;
F_56 ( V_133 , V_102 ) ;
return 0 ;
V_142:
F_57 ( V_102 ) ;
return V_110 ;
}
static int F_58 ( struct V_132 * V_133 )
{
F_57 ( F_59 ( V_133 ) ) ;
return 0 ;
}
static void F_60 ( void )
{
int V_145 ;
for ( V_145 = 0 ; V_145 < F_61 ( V_146 ) ; ++ V_145 )
F_62 ( V_146 [ V_145 ] ) ;
F_63 ( & V_147 ) ;
}
static int T_2 F_64 ( void )
{
int V_145 , V_148 , V_110 ;
if ( ( V_110 = F_65 ( & V_147 ) ) < 0 )
return V_110 ;
V_148 = 0 ;
for ( V_145 = 0 ; V_145 < V_149 ; V_145 ++ ) {
struct V_132 * V_99 ;
if ( ! V_150 [ V_145 ] )
continue;
V_99 = F_66 ( V_151 ,
V_145 , NULL , 0 ) ;
if ( F_67 ( V_99 ) )
continue;
if ( ! F_59 ( V_99 ) ) {
F_62 ( V_99 ) ;
continue;
}
V_146 [ V_145 ] = V_99 ;
V_148 ++ ;
}
if ( ! V_148 ) {
#ifdef F_68
F_44 ( V_51 L_15 ) ;
#endif
F_60 () ;
return - V_49 ;
}
return 0 ;
}
static void T_3 F_69 ( void )
{
F_60 () ;
}
