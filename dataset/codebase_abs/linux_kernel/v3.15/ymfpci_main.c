static inline T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_2 V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline T_3 F_5 ( struct V_1 * V_2 , T_2 V_3 )
{
return F_6 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_7 ( struct V_1 * V_2 , T_2 V_3 , T_3 V_5 )
{
F_8 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline T_2 F_9 ( struct V_1 * V_2 , T_2 V_3 )
{
return F_10 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_11 ( struct V_1 * V_2 , T_2 V_3 , T_2 V_5 )
{
F_12 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static int F_13 ( struct V_1 * V_2 , int V_6 )
{
unsigned long V_7 ;
T_2 V_8 = V_6 ? V_9 : V_10 ;
V_7 = V_11 + F_14 ( 750 ) ;
do {
if ( ( F_5 ( V_2 , V_8 ) & 0x8000 ) == 0 )
return 0 ;
F_15 ( 1 ) ;
} while ( F_16 ( V_11 , V_7 ) );
F_17 ( V_2 -> V_12 -> V_13 ,
L_1 ,
V_6 , F_5 ( V_2 , V_8 ) ) ;
return - V_14 ;
}
static void F_18 ( struct V_15 * V_16 , T_3 V_8 , T_3 V_5 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
T_2 V_18 ;
F_13 ( V_2 , 0 ) ;
V_18 = ( ( V_19 | V_8 ) << 16 ) | V_5 ;
F_11 ( V_2 , V_20 , V_18 ) ;
}
static T_3 F_19 ( struct V_15 * V_16 , T_3 V_8 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
if ( F_13 ( V_2 , 0 ) )
return ~ 0 ;
F_7 ( V_2 , V_21 , V_22 | V_8 ) ;
if ( F_13 ( V_2 , 0 ) )
return ~ 0 ;
if ( V_2 -> V_23 == V_24 && V_2 -> V_25 < 2 ) {
int V_26 ;
for ( V_26 = 0 ; V_26 < 600 ; V_26 ++ )
F_5 ( V_2 , V_27 ) ;
}
return F_5 ( V_2 , V_27 ) ;
}
static T_2 F_20 ( T_2 V_28 )
{
switch ( V_28 ) {
case 8000 : return 0x02aaab00 ;
case 11025 : return 0x03accd00 ;
case 16000 : return 0x05555500 ;
case 22050 : return 0x07599a00 ;
case 32000 : return 0x0aaaab00 ;
case 44100 : return 0x0eb33300 ;
default: return ( ( V_28 << 16 ) / 375 ) << 5 ;
}
}
static T_2 F_21 ( T_2 V_28 )
{
T_2 V_26 ;
static T_2 V_5 [ 8 ] = {
0x00570000 , 0x06AA0000 , 0x18B20000 , 0x20930000 ,
0x2B9A0000 , 0x35A10000 , 0x3EAA0000 , 0x40000000
} ;
if ( V_28 == 44100 )
return 0x40000000 ;
for ( V_26 = 0 ; V_26 < 8 ; V_26 ++ )
if ( V_28 <= V_29 [ V_26 ] )
return V_5 [ V_26 ] ;
return V_5 [ 0 ] ;
}
static T_2 F_22 ( T_2 V_28 )
{
T_2 V_26 ;
static T_2 V_5 [ 8 ] = {
0x35280000 , 0x34A70000 , 0x32020000 , 0x31770000 ,
0x31390000 , 0x31C90000 , 0x33D00000 , 0x40000000
} ;
if ( V_28 == 44100 )
return 0x370A0000 ;
for ( V_26 = 0 ; V_26 < 8 ; V_26 ++ )
if ( V_28 <= V_29 [ V_26 ] )
return V_5 [ V_26 ] ;
return V_5 [ 0 ] ;
}
static void F_23 ( struct V_1 * V_2 )
{
unsigned long V_30 ;
F_24 ( & V_2 -> V_31 , V_30 ) ;
if ( V_2 -> V_32 ++ > 0 )
goto V_33;
F_11 ( V_2 , V_34 ,
F_9 ( V_2 , V_34 ) | 3 ) ;
V_2 -> V_35 = F_9 ( V_2 , V_36 ) & 1 ;
V_33:
F_25 ( & V_2 -> V_31 , V_30 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
unsigned long V_30 ;
long V_37 = 1000 ;
F_24 ( & V_2 -> V_31 , V_30 ) ;
if ( -- V_2 -> V_32 > 0 )
goto V_33;
F_11 ( V_2 , V_34 ,
F_9 ( V_2 , V_34 ) & ~ 3 ) ;
while ( V_37 -- > 0 ) {
if ( ( F_9 ( V_2 , V_38 ) & 2 ) == 0 )
break;
}
if ( F_27 ( & V_2 -> V_39 ) ) {
F_28 ( & V_2 -> V_39 , 0 ) ;
F_29 ( & V_2 -> V_40 ) ;
}
V_33:
F_25 ( & V_2 -> V_31 , V_30 ) ;
}
static int F_30 ( struct V_1 * V_2 ,
enum V_41 type , int V_42 ,
struct V_43 * * V_44 )
{
struct V_43 * V_45 , * V_46 ;
int V_47 ;
* V_44 = NULL ;
for ( V_47 = 0 ; V_47 < V_48 ; V_47 += V_42 ? 2 : 1 ) {
V_45 = & V_2 -> V_49 [ V_47 ] ;
V_46 = V_42 ? & V_2 -> V_49 [ V_47 + 1 ] : NULL ;
if ( V_45 -> V_50 || ( V_46 && V_46 -> V_50 ) )
continue;
V_45 -> V_50 = 1 ;
if ( V_46 )
V_46 -> V_50 = 1 ;
switch ( type ) {
case V_51 :
V_45 -> V_52 = 1 ;
if ( V_46 )
V_46 -> V_52 = 1 ;
break;
case V_53 :
V_45 -> V_54 = 1 ;
break;
case V_55 :
V_45 -> V_56 = 1 ;
break;
}
F_23 ( V_2 ) ;
if ( V_46 )
F_23 ( V_2 ) ;
* V_44 = V_45 ;
return 0 ;
}
return - V_57 ;
}
static int F_31 ( struct V_1 * V_2 ,
enum V_41 type , int V_42 ,
struct V_43 * * V_44 )
{
unsigned long V_30 ;
int V_58 ;
if ( F_32 ( ! V_44 ) )
return - V_59 ;
if ( F_32 ( V_42 && type != V_51 ) )
return - V_59 ;
F_24 ( & V_2 -> V_60 , V_30 ) ;
for (; ; ) {
V_58 = F_30 ( V_2 , type , V_42 , V_44 ) ;
if ( V_58 == 0 || type != V_51 )
break;
break;
}
F_25 ( & V_2 -> V_60 , V_30 ) ;
return V_58 ;
}
static int F_33 ( struct V_1 * V_2 , struct V_43 * V_61 )
{
unsigned long V_30 ;
if ( F_32 ( ! V_61 ) )
return - V_59 ;
F_26 ( V_2 ) ;
F_24 ( & V_2 -> V_60 , V_30 ) ;
if ( V_61 -> V_62 == V_2 -> V_63 ) {
V_2 -> V_63 = - 1 ;
V_61 -> V_64 -> V_65 = 0 ;
}
V_61 -> V_50 = V_61 -> V_52 = V_61 -> V_54 = V_61 -> V_56 = 0 ;
V_61 -> V_64 = NULL ;
V_61 -> V_66 = NULL ;
F_25 ( & V_2 -> V_60 , V_30 ) ;
return 0 ;
}
static void F_34 ( struct V_1 * V_2 , struct V_43 * V_45 )
{
struct V_67 * V_64 ;
T_2 V_68 , V_69 ;
if ( ( V_64 = V_45 -> V_64 ) == NULL )
return;
if ( V_64 -> V_70 == NULL )
return;
F_35 ( & V_2 -> V_31 ) ;
if ( V_64 -> V_71 ) {
V_68 = F_36 ( V_45 -> V_72 [ V_2 -> V_35 ] . V_73 ) ;
if ( V_68 < V_64 -> V_74 )
V_69 = V_68 + ( V_64 -> V_75 - V_64 -> V_74 ) ;
else
V_69 = V_68 - V_64 -> V_74 ;
V_64 -> V_76 += V_69 ;
V_64 -> V_74 = V_68 ;
if ( V_64 -> V_76 >= V_64 -> V_77 ) {
V_64 -> V_76 %= V_64 -> V_77 ;
F_37 ( & V_2 -> V_31 ) ;
F_38 ( V_64 -> V_70 ) ;
F_35 ( & V_2 -> V_31 ) ;
}
if ( F_39 ( V_64 -> V_78 ) ) {
unsigned int V_79 = V_64 -> V_70 -> V_62 ;
unsigned int V_80 = 1 - V_2 -> V_35 ;
struct V_81 * V_72 ;
T_2 V_82 ;
V_72 = & V_45 -> V_72 [ V_80 ] ;
V_82 = F_40 ( V_2 -> V_83 [ V_79 ] . V_84 << 15 ) ;
V_72 -> V_85 = V_82 ;
if ( V_64 -> V_86 )
V_72 -> V_87 = V_82 ;
if ( V_64 -> V_49 [ 1 ] )
V_72 = & V_64 -> V_49 [ 1 ] -> V_72 [ V_80 ] ;
V_82 = F_40 ( V_2 -> V_83 [ V_79 ] . V_88 << 15 ) ;
V_72 -> V_89 = V_82 ;
if ( V_64 -> V_86 )
V_72 -> V_90 = V_82 ;
V_64 -> V_78 -- ;
}
}
F_37 ( & V_2 -> V_31 ) ;
}
static void F_41 ( struct V_91 * V_70 )
{
struct V_92 * V_93 = V_70 -> V_93 ;
struct V_67 * V_64 = V_93 -> V_17 ;
struct V_1 * V_2 = V_64 -> V_2 ;
T_2 V_68 , V_69 ;
F_35 ( & V_2 -> V_31 ) ;
if ( V_64 -> V_71 ) {
V_68 = F_36 ( V_2 -> V_94 [ V_64 -> V_95 ] [ V_2 -> V_35 ] -> V_73 ) >> V_64 -> V_96 ;
if ( V_68 < V_64 -> V_74 )
V_69 = V_68 + ( V_64 -> V_75 - V_64 -> V_74 ) ;
else
V_69 = V_68 - V_64 -> V_74 ;
V_64 -> V_76 += V_69 ;
V_64 -> V_74 = V_68 ;
if ( V_64 -> V_76 >= V_64 -> V_77 ) {
V_64 -> V_76 %= V_64 -> V_77 ;
F_37 ( & V_2 -> V_31 ) ;
F_38 ( V_70 ) ;
F_35 ( & V_2 -> V_31 ) ;
}
}
F_37 ( & V_2 -> V_31 ) ;
}
static int F_42 ( struct V_91 * V_70 ,
int V_18 )
{
struct V_1 * V_2 = F_43 ( V_70 ) ;
struct V_67 * V_64 = V_70 -> V_93 -> V_17 ;
struct V_97 * V_98 = NULL ;
int V_58 = 0 ;
F_35 ( & V_2 -> V_31 ) ;
if ( V_64 -> V_49 [ 0 ] == NULL ) {
V_58 = - V_59 ;
goto V_99;
}
switch ( V_18 ) {
case V_100 :
case V_101 :
case V_102 :
V_2 -> V_103 [ V_64 -> V_49 [ 0 ] -> V_62 + 1 ] = F_40 ( V_64 -> V_49 [ 0 ] -> V_104 ) ;
if ( V_64 -> V_49 [ 1 ] != NULL && ! V_64 -> V_65 )
V_2 -> V_103 [ V_64 -> V_49 [ 1 ] -> V_62 + 1 ] = F_40 ( V_64 -> V_49 [ 1 ] -> V_104 ) ;
V_64 -> V_71 = 1 ;
break;
case V_105 :
if ( V_70 -> V_52 == V_2 -> V_52 && ! V_64 -> V_65 ) {
V_98 = V_2 -> V_83 [ V_70 -> V_62 ] . V_106 ;
V_98 -> V_107 [ 0 ] . V_108 |= V_109 ;
}
case V_110 :
case V_111 :
V_2 -> V_103 [ V_64 -> V_49 [ 0 ] -> V_62 + 1 ] = 0 ;
if ( V_64 -> V_49 [ 1 ] != NULL && ! V_64 -> V_65 )
V_2 -> V_103 [ V_64 -> V_49 [ 1 ] -> V_62 + 1 ] = 0 ;
V_64 -> V_71 = 0 ;
break;
default:
V_58 = - V_59 ;
break;
}
V_99:
F_37 ( & V_2 -> V_31 ) ;
if ( V_98 )
F_44 ( V_2 -> V_12 , V_112 , & V_98 -> V_113 ) ;
return V_58 ;
}
static int F_45 ( struct V_91 * V_70 ,
int V_18 )
{
struct V_1 * V_2 = F_43 ( V_70 ) ;
struct V_67 * V_64 = V_70 -> V_93 -> V_17 ;
int V_58 = 0 ;
T_2 V_114 ;
F_35 ( & V_2 -> V_31 ) ;
switch ( V_18 ) {
case V_100 :
case V_101 :
case V_102 :
V_114 = F_9 ( V_2 , V_115 ) | ( 1 << V_64 -> V_95 ) ;
F_11 ( V_2 , V_115 , V_114 ) ;
V_64 -> V_71 = 1 ;
break;
case V_105 :
case V_110 :
case V_111 :
V_114 = F_9 ( V_2 , V_115 ) & ~ ( 1 << V_64 -> V_95 ) ;
F_11 ( V_2 , V_115 , V_114 ) ;
V_64 -> V_71 = 0 ;
break;
default:
V_58 = - V_59 ;
break;
}
F_37 ( & V_2 -> V_31 ) ;
return V_58 ;
}
static int F_46 ( struct V_67 * V_64 , int V_49 )
{
int V_116 ;
if ( V_64 -> V_49 [ 1 ] != NULL && V_49 < 2 ) {
F_33 ( V_64 -> V_2 , V_64 -> V_49 [ 1 ] ) ;
V_64 -> V_49 [ 1 ] = NULL ;
}
if ( V_49 == 1 && V_64 -> V_49 [ 0 ] != NULL )
return 0 ;
if ( V_49 == 2 && V_64 -> V_49 [ 0 ] != NULL && V_64 -> V_49 [ 1 ] != NULL )
return 0 ;
if ( V_49 > 1 ) {
if ( V_64 -> V_49 [ 0 ] != NULL && V_64 -> V_49 [ 1 ] == NULL ) {
F_33 ( V_64 -> V_2 , V_64 -> V_49 [ 0 ] ) ;
V_64 -> V_49 [ 0 ] = NULL ;
}
}
V_116 = F_31 ( V_64 -> V_2 , V_51 , V_49 > 1 , & V_64 -> V_49 [ 0 ] ) ;
if ( V_116 < 0 )
return V_116 ;
V_64 -> V_49 [ 0 ] -> V_64 = V_64 ;
V_64 -> V_49 [ 0 ] -> V_66 = F_34 ;
if ( V_49 > 1 ) {
V_64 -> V_49 [ 1 ] = & V_64 -> V_2 -> V_49 [ V_64 -> V_49 [ 0 ] -> V_62 + 1 ] ;
V_64 -> V_49 [ 1 ] -> V_64 = V_64 ;
}
return 0 ;
}
static void F_47 ( struct V_67 * V_64 , unsigned int V_117 ,
struct V_92 * V_93 ,
int V_118 )
{
struct V_43 * V_45 = V_64 -> V_49 [ V_117 ] ;
T_2 V_119 ;
T_2 V_69 = F_20 ( V_93 -> V_28 ) ;
T_2 V_120 = F_22 ( V_93 -> V_28 ) ;
T_2 V_121 = F_21 ( V_93 -> V_28 ) ;
struct V_81 * V_72 ;
unsigned int V_122 ;
T_2 V_123 , V_124 ;
T_1 V_125 , V_126 ;
unsigned long V_30 ;
if ( F_32 ( ! V_45 ) )
return;
if ( V_93 -> V_127 == 1 ) {
V_125 = 1 ;
V_126 = 1 ;
} else {
V_125 = ( V_117 & 1 ) == 0 ;
V_126 = ! V_125 ;
}
if ( V_118 ) {
V_123 = F_40 ( V_64 -> V_2 -> V_83
[ V_64 -> V_70 -> V_62 ] . V_84 << 15 ) ;
V_124 = F_40 ( V_64 -> V_2 -> V_83
[ V_64 -> V_70 -> V_62 ] . V_88 << 15 ) ;
} else {
V_123 = F_40 ( 0x40000000 ) ;
V_124 = F_40 ( 0x40000000 ) ;
}
F_24 ( & V_64 -> V_2 -> V_60 , V_30 ) ;
V_119 = V_93 -> V_127 == 2 ? 0x00010000 : 0 ;
if ( F_48 ( V_93 -> V_119 ) == 8 )
V_119 |= 0x80000000 ;
else if ( V_64 -> V_2 -> V_23 == V_128 &&
V_93 -> V_28 == 44100 && V_93 -> V_127 == 2 &&
V_117 == 0 && ( V_64 -> V_2 -> V_63 == - 1 ||
V_64 -> V_2 -> V_63 == V_45 -> V_62 ) ) {
V_64 -> V_2 -> V_63 = V_45 -> V_62 ;
V_64 -> V_65 = 1 ;
V_119 |= 0x10000000 ;
}
if ( V_64 -> V_2 -> V_63 == V_45 -> V_62 &&
( V_119 & 0x10000000 ) == 0 ) {
V_64 -> V_2 -> V_63 = - 1 ;
V_64 -> V_65 = 0 ;
}
if ( V_93 -> V_127 == 2 && ( V_117 & 1 ) != 0 )
V_119 |= 1 ;
F_25 ( & V_64 -> V_2 -> V_60 , V_30 ) ;
for ( V_122 = 0 ; V_122 < 2 ; V_122 ++ ) {
V_72 = & V_45 -> V_72 [ V_122 ] ;
memset ( V_72 , 0 , sizeof( * V_72 ) ) ;
V_72 -> V_119 = F_40 ( V_119 ) ;
V_72 -> V_129 = F_40 ( V_93 -> V_130 ) ;
V_72 -> V_131 = F_40 ( V_64 -> V_75 ) ;
V_72 -> V_120 = F_40 ( V_120 ) ;
V_72 -> V_69 =
V_72 -> V_132 = F_40 ( V_69 ) ;
V_72 -> V_121 =
V_72 -> V_133 = F_40 ( V_121 ) ;
V_72 -> V_134 =
V_72 -> V_135 = F_40 ( 0x40000000 ) ;
if ( V_64 -> V_136 ) {
if ( V_125 ) {
V_72 -> V_137 =
V_72 -> V_85 = V_123 ;
}
if ( V_126 ) {
V_72 -> V_138 =
V_72 -> V_89 = V_124 ;
}
}
if ( V_64 -> V_86 ) {
if ( ! V_64 -> V_139 ) {
if ( V_125 ) {
V_72 -> V_140 =
V_72 -> V_87 = V_123 ;
}
if ( V_126 ) {
V_72 -> V_141 =
V_72 -> V_90 = V_124 ;
}
} else {
if ( V_125 ) {
V_72 -> V_141 =
V_72 -> V_90 = V_123 ;
}
if ( V_126 ) {
V_72 -> V_140 =
V_72 -> V_87 = V_124 ;
}
}
}
}
}
static int F_49 ( struct V_1 * V_2 )
{
if ( F_50 ( V_142 , F_51 ( V_2 -> V_143 ) ,
4096 , & V_2 -> V_144 ) < 0 )
return - V_57 ;
V_2 -> V_145 [ 3 ] [ 0 ] -> V_129 =
V_2 -> V_145 [ 3 ] [ 1 ] -> V_129 = F_40 ( V_2 -> V_144 . V_146 ) ;
V_2 -> V_145 [ 3 ] [ 0 ] -> V_131 =
V_2 -> V_145 [ 3 ] [ 1 ] -> V_131 = F_40 ( 1024 ) ;
V_2 -> V_145 [ 4 ] [ 0 ] -> V_129 =
V_2 -> V_145 [ 4 ] [ 1 ] -> V_129 = F_40 ( V_2 -> V_144 . V_146 + 2048 ) ;
V_2 -> V_145 [ 4 ] [ 0 ] -> V_131 =
V_2 -> V_145 [ 4 ] [ 1 ] -> V_131 = F_40 ( 1024 ) ;
F_52 ( & V_2 -> V_31 ) ;
F_11 ( V_2 , V_147 ,
F_9 ( V_2 , V_147 ) | 3 << 3 ) ;
F_53 ( & V_2 -> V_31 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 )
{
F_52 ( & V_2 -> V_31 ) ;
F_11 ( V_2 , V_147 ,
F_9 ( V_2 , V_147 ) & ~ ( 3 << 3 ) ) ;
F_53 ( & V_2 -> V_31 ) ;
if ( V_2 -> V_144 . V_148 ) {
F_55 ( & V_2 -> V_144 ) ;
V_2 -> V_144 . V_148 = NULL ;
}
return 0 ;
}
static int F_56 ( struct V_91 * V_70 ,
struct V_149 * V_150 )
{
struct V_92 * V_93 = V_70 -> V_93 ;
struct V_67 * V_64 = V_93 -> V_17 ;
int V_116 ;
if ( ( V_116 = F_57 ( V_70 , F_58 ( V_150 ) ) ) < 0 )
return V_116 ;
if ( ( V_116 = F_46 ( V_64 , F_59 ( V_150 ) ) ) < 0 )
return V_116 ;
return 0 ;
}
static int F_60 ( struct V_91 * V_70 )
{
struct V_1 * V_2 = F_43 ( V_70 ) ;
struct V_92 * V_93 = V_70 -> V_93 ;
struct V_67 * V_64 ;
if ( V_93 -> V_17 == NULL )
return 0 ;
V_64 = V_93 -> V_17 ;
F_61 ( V_2 ) ;
F_62 ( V_70 ) ;
if ( V_64 -> V_49 [ 1 ] ) {
F_33 ( V_2 , V_64 -> V_49 [ 1 ] ) ;
V_64 -> V_49 [ 1 ] = NULL ;
}
if ( V_64 -> V_49 [ 0 ] ) {
F_33 ( V_2 , V_64 -> V_49 [ 0 ] ) ;
V_64 -> V_49 [ 0 ] = NULL ;
}
return 0 ;
}
static int F_63 ( struct V_91 * V_70 )
{
struct V_1 * V_2 = F_43 ( V_70 ) ;
struct V_92 * V_93 = V_70 -> V_93 ;
struct V_67 * V_64 = V_93 -> V_17 ;
struct V_97 * V_98 ;
unsigned int V_151 ;
V_64 -> V_77 = V_93 -> V_77 ;
V_64 -> V_75 = V_93 -> V_75 ;
V_64 -> V_76 = 0 ;
V_64 -> V_74 = 0 ;
for ( V_151 = 0 ; V_151 < V_93 -> V_127 ; V_151 ++ )
F_47 ( V_64 , V_151 , V_93 ,
V_70 -> V_52 == V_2 -> V_52 ) ;
if ( V_70 -> V_52 == V_2 -> V_52 && ! V_64 -> V_65 ) {
V_98 = V_2 -> V_83 [ V_70 -> V_62 ] . V_106 ;
V_98 -> V_107 [ 0 ] . V_108 &= ~ V_109 ;
F_44 ( V_2 -> V_12 , V_112 , & V_98 -> V_113 ) ;
}
return 0 ;
}
static int F_64 ( struct V_91 * V_70 ,
struct V_149 * V_150 )
{
return F_57 ( V_70 , F_58 ( V_150 ) ) ;
}
static int F_65 ( struct V_91 * V_70 )
{
struct V_1 * V_2 = F_43 ( V_70 ) ;
F_61 ( V_2 ) ;
return F_62 ( V_70 ) ;
}
static int F_66 ( struct V_91 * V_70 )
{
struct V_1 * V_2 = F_43 ( V_70 ) ;
struct V_92 * V_93 = V_70 -> V_93 ;
struct V_67 * V_64 = V_93 -> V_17 ;
struct V_152 * V_72 ;
int V_122 ;
T_2 V_28 , V_119 ;
V_64 -> V_77 = V_93 -> V_77 ;
V_64 -> V_75 = V_93 -> V_75 ;
V_64 -> V_76 = 0 ;
V_64 -> V_74 = 0 ;
V_64 -> V_96 = 0 ;
V_28 = ( ( 48000 * 4096 ) / V_93 -> V_28 ) - 1 ;
V_119 = 0 ;
if ( V_93 -> V_127 == 2 ) {
V_119 |= 2 ;
V_64 -> V_96 ++ ;
}
if ( F_48 ( V_93 -> V_119 ) == 8 )
V_119 |= 1 ;
else
V_64 -> V_96 ++ ;
switch ( V_64 -> V_95 ) {
case 0 :
F_11 ( V_2 , V_153 , V_119 ) ;
F_11 ( V_2 , V_154 , V_28 ) ;
break;
case 1 :
F_11 ( V_2 , V_155 , V_119 ) ;
F_11 ( V_2 , V_156 , V_28 ) ;
break;
}
for ( V_122 = 0 ; V_122 < 2 ; V_122 ++ ) {
V_72 = V_2 -> V_94 [ V_64 -> V_95 ] [ V_122 ] ;
V_72 -> V_129 = F_40 ( V_93 -> V_130 ) ;
V_72 -> V_131 = F_40 ( V_64 -> V_75 << V_64 -> V_96 ) ;
V_72 -> V_73 = 0 ;
V_72 -> V_157 = 0 ;
}
return 0 ;
}
static T_4 F_67 ( struct V_91 * V_70 )
{
struct V_1 * V_2 = F_43 ( V_70 ) ;
struct V_92 * V_93 = V_70 -> V_93 ;
struct V_67 * V_64 = V_93 -> V_17 ;
struct V_43 * V_45 = V_64 -> V_49 [ 0 ] ;
if ( ! ( V_64 -> V_71 && V_45 ) )
return 0 ;
return F_36 ( V_45 -> V_72 [ V_2 -> V_35 ] . V_73 ) ;
}
static T_4 F_68 ( struct V_91 * V_70 )
{
struct V_1 * V_2 = F_43 ( V_70 ) ;
struct V_92 * V_93 = V_70 -> V_93 ;
struct V_67 * V_64 = V_93 -> V_17 ;
if ( ! V_64 -> V_71 )
return 0 ;
return F_36 ( V_2 -> V_94 [ V_64 -> V_95 ] [ V_2 -> V_35 ] -> V_73 ) >> V_64 -> V_96 ;
}
static void F_61 ( struct V_1 * V_2 )
{
T_5 V_158 ;
int V_159 = 4 ;
while ( V_159 -- > 0 ) {
if ( ( F_9 ( V_2 , V_34 ) & 3 ) == 0 )
continue;
F_69 ( & V_158 , V_160 ) ;
F_70 ( & V_2 -> V_40 , & V_158 ) ;
F_71 ( & V_2 -> V_39 ) ;
F_15 ( F_14 ( 50 ) ) ;
F_72 ( & V_2 -> V_40 , & V_158 ) ;
}
}
static T_6 F_73 ( int V_161 , void * V_162 )
{
struct V_1 * V_2 = V_162 ;
T_2 V_163 , V_151 , V_164 ;
struct V_43 * V_45 ;
V_163 = F_9 ( V_2 , V_38 ) ;
if ( V_163 & 0x80000000 ) {
V_2 -> V_35 = F_9 ( V_2 , V_36 ) & 1 ;
F_35 ( & V_2 -> V_60 ) ;
for ( V_151 = 0 ; V_151 < V_48 ; V_151 ++ ) {
V_45 = & V_2 -> V_49 [ V_151 ] ;
if ( V_45 -> V_66 )
V_45 -> V_66 ( V_2 , V_45 ) ;
}
for ( V_151 = 0 ; V_151 < V_165 ; V_151 ++ ) {
if ( V_2 -> V_166 [ V_151 ] )
F_41 ( V_2 -> V_166 [ V_151 ] ) ;
}
#if 0
for (nvoice = 0; nvoice < YDSXG_EFFECT_VOICES; nvoice++) {
if (chip->effect_substream[nvoice])
snd_ymfpci_pcm_effect_interrupt(chip->effect_substream[nvoice]);
}
#endif
F_37 ( & V_2 -> V_60 ) ;
F_35 ( & V_2 -> V_31 ) ;
F_11 ( V_2 , V_38 , 0x80000000 ) ;
V_164 = F_9 ( V_2 , V_34 ) | 2 ;
F_11 ( V_2 , V_34 , V_164 ) ;
F_37 ( & V_2 -> V_31 ) ;
if ( F_27 ( & V_2 -> V_39 ) ) {
F_28 ( & V_2 -> V_39 , 0 ) ;
F_29 ( & V_2 -> V_40 ) ;
}
}
V_163 = F_5 ( V_2 , V_167 ) ;
if ( V_163 & 1 ) {
if ( V_2 -> V_168 )
F_74 ( V_2 -> V_168 , V_2 -> V_169 ) ;
}
F_7 ( V_2 , V_167 , V_163 ) ;
if ( V_2 -> V_170 )
F_75 ( V_161 , V_2 -> V_170 -> V_17 ) ;
return V_171 ;
}
static void F_76 ( struct V_92 * V_93 )
{
F_77 ( V_93 -> V_17 ) ;
}
static int F_78 ( struct V_91 * V_70 )
{
struct V_1 * V_2 = F_43 ( V_70 ) ;
struct V_92 * V_93 = V_70 -> V_93 ;
struct V_67 * V_64 ;
int V_116 ;
V_93 -> V_172 = V_173 ;
V_116 = F_79 ( V_93 ,
V_174 ,
5334 , V_175 ) ;
if ( V_116 < 0 )
return V_116 ;
V_116 = F_80 ( V_93 , 48000 ) ;
if ( V_116 < 0 )
return V_116 ;
V_64 = F_81 ( sizeof( * V_64 ) , V_176 ) ;
if ( V_64 == NULL )
return - V_57 ;
V_64 -> V_2 = V_2 ;
V_64 -> type = V_177 ;
V_64 -> V_70 = V_70 ;
V_93 -> V_17 = V_64 ;
V_93 -> V_178 = F_76 ;
return 0 ;
}
static void F_82 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_179 ) {
if ( ! V_2 -> V_180 )
F_11 ( V_2 , V_34 ,
F_9 ( V_2 , V_34 ) | ( 1 << 30 ) ) ;
F_7 ( V_2 , V_181 ,
( F_5 ( V_2 , V_181 ) & ~ 0x0330 ) | 0x0010 ) ;
}
}
static void F_83 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_179 ) {
if ( ! V_2 -> V_180 )
F_11 ( V_2 , V_34 ,
F_9 ( V_2 , V_34 ) & ~ ( 1 << 30 ) ) ;
F_7 ( V_2 , V_181 ,
( F_5 ( V_2 , V_181 ) & ~ 0x0330 ) & ~ 0x0010 ) ;
}
}
static int F_84 ( struct V_91 * V_70 )
{
struct V_1 * V_2 = F_43 ( V_70 ) ;
struct V_92 * V_93 = V_70 -> V_93 ;
struct V_67 * V_64 ;
int V_116 ;
if ( ( V_116 = F_78 ( V_70 ) ) < 0 )
return V_116 ;
V_64 = V_93 -> V_17 ;
V_64 -> V_136 = 1 ;
V_64 -> V_86 = V_2 -> V_182 ? 1 : 0 ;
V_64 -> V_139 = 0 ;
F_52 ( & V_2 -> V_31 ) ;
if ( V_64 -> V_86 ) {
F_82 ( V_2 ) ;
V_2 -> V_179 ++ ;
}
F_53 ( & V_2 -> V_31 ) ;
return 0 ;
}
static int F_85 ( struct V_91 * V_70 )
{
struct V_1 * V_2 = F_43 ( V_70 ) ;
struct V_92 * V_93 = V_70 -> V_93 ;
struct V_67 * V_64 ;
int V_116 ;
if ( ( V_116 = F_78 ( V_70 ) ) < 0 )
return V_116 ;
V_64 = V_93 -> V_17 ;
V_64 -> V_136 = 0 ;
V_64 -> V_86 = 1 ;
V_64 -> V_139 = 1 ;
F_52 ( & V_2 -> V_31 ) ;
F_7 ( V_2 , V_183 ,
F_5 ( V_2 , V_183 ) | 2 ) ;
F_82 ( V_2 ) ;
V_2 -> V_184 = V_2 -> V_185 ;
F_7 ( V_2 , V_186 , V_2 -> V_184 ) ;
V_2 -> V_180 ++ ;
F_53 ( & V_2 -> V_31 ) ;
V_2 -> V_187 -> V_107 [ 0 ] . V_108 &= ~ V_109 ;
F_44 ( V_2 -> V_12 , V_188 |
V_112 , & V_2 -> V_187 -> V_113 ) ;
return 0 ;
}
static int F_86 ( struct V_91 * V_70 )
{
struct V_1 * V_2 = F_43 ( V_70 ) ;
struct V_92 * V_93 = V_70 -> V_93 ;
struct V_67 * V_64 ;
int V_116 ;
if ( ( V_116 = F_78 ( V_70 ) ) < 0 )
return V_116 ;
V_64 = V_93 -> V_17 ;
V_64 -> V_136 = 0 ;
V_64 -> V_86 = 1 ;
V_64 -> V_139 = 0 ;
F_52 ( & V_2 -> V_31 ) ;
F_82 ( V_2 ) ;
V_2 -> V_179 ++ ;
F_53 ( & V_2 -> V_31 ) ;
return 0 ;
}
static int F_87 ( struct V_91 * V_70 ,
T_2 V_95 )
{
struct V_1 * V_2 = F_43 ( V_70 ) ;
struct V_92 * V_93 = V_70 -> V_93 ;
struct V_67 * V_64 ;
int V_116 ;
V_93 -> V_172 = V_189 ;
V_116 = F_79 ( V_93 ,
V_174 ,
5334 , V_175 ) ;
if ( V_116 < 0 )
return V_116 ;
V_116 = F_80 ( V_93 , 48000 ) ;
if ( V_116 < 0 )
return V_116 ;
V_64 = F_81 ( sizeof( * V_64 ) , V_176 ) ;
if ( V_64 == NULL )
return - V_57 ;
V_64 -> V_2 = V_2 ;
V_64 -> type = V_95 + V_190 ;
V_64 -> V_70 = V_70 ;
V_64 -> V_95 = V_95 ;
V_2 -> V_166 [ V_95 ] = V_70 ;
V_93 -> V_17 = V_64 ;
V_93 -> V_178 = F_76 ;
F_23 ( V_2 ) ;
return 0 ;
}
static int F_88 ( struct V_91 * V_70 )
{
return F_87 ( V_70 , 0 ) ;
}
static int F_89 ( struct V_91 * V_70 )
{
return F_87 ( V_70 , 1 ) ;
}
static int F_90 ( struct V_91 * V_70 )
{
return 0 ;
}
static int F_91 ( struct V_91 * V_70 )
{
struct V_1 * V_2 = F_43 ( V_70 ) ;
struct V_67 * V_64 = V_70 -> V_93 -> V_17 ;
F_52 ( & V_2 -> V_31 ) ;
if ( V_64 -> V_86 && V_2 -> V_179 > 0 ) {
V_2 -> V_179 -- ;
F_83 ( V_2 ) ;
}
F_53 ( & V_2 -> V_31 ) ;
return F_90 ( V_70 ) ;
}
static int F_92 ( struct V_91 * V_70 )
{
struct V_1 * V_2 = F_43 ( V_70 ) ;
F_52 ( & V_2 -> V_31 ) ;
V_2 -> V_180 = 0 ;
F_83 ( V_2 ) ;
F_7 ( V_2 , V_183 ,
F_5 ( V_2 , V_183 ) & ~ 2 ) ;
F_7 ( V_2 , V_186 , V_2 -> V_185 ) ;
F_53 ( & V_2 -> V_31 ) ;
V_2 -> V_187 -> V_107 [ 0 ] . V_108 |= V_109 ;
F_44 ( V_2 -> V_12 , V_188 |
V_112 , & V_2 -> V_187 -> V_113 ) ;
return F_90 ( V_70 ) ;
}
static int F_93 ( struct V_91 * V_70 )
{
struct V_1 * V_2 = F_43 ( V_70 ) ;
F_52 ( & V_2 -> V_31 ) ;
if ( V_2 -> V_179 > 0 ) {
V_2 -> V_179 -- ;
F_83 ( V_2 ) ;
}
F_53 ( & V_2 -> V_31 ) ;
return F_90 ( V_70 ) ;
}
static int F_94 ( struct V_91 * V_70 )
{
struct V_1 * V_2 = F_43 ( V_70 ) ;
struct V_92 * V_93 = V_70 -> V_93 ;
struct V_67 * V_64 = V_93 -> V_17 ;
if ( V_64 != NULL ) {
V_2 -> V_166 [ V_64 -> V_95 ] = NULL ;
F_26 ( V_2 ) ;
}
return 0 ;
}
int V_67 ( struct V_1 * V_2 , int V_191 , struct V_192 * * V_193 )
{
struct V_192 * V_52 ;
int V_116 ;
if ( V_193 )
* V_193 = NULL ;
if ( ( V_116 = F_95 ( V_2 -> V_12 , L_2 , V_191 , 32 , 1 , & V_52 ) ) < 0 )
return V_116 ;
V_52 -> V_17 = V_2 ;
F_96 ( V_52 , V_194 , & V_195 ) ;
F_96 ( V_52 , V_196 , & V_197 ) ;
V_52 -> V_198 = 0 ;
strcpy ( V_52 -> V_199 , L_2 ) ;
V_2 -> V_52 = V_52 ;
F_97 ( V_52 , V_142 ,
F_51 ( V_2 -> V_143 ) , 64 * 1024 , 256 * 1024 ) ;
V_116 = F_98 ( V_52 , V_194 ,
V_200 , 2 , 0 , NULL ) ;
if ( V_116 < 0 )
return V_116 ;
if ( V_193 )
* V_193 = V_52 ;
return 0 ;
}
int F_99 ( struct V_1 * V_2 , int V_191 , struct V_192 * * V_193 )
{
struct V_192 * V_52 ;
int V_116 ;
if ( V_193 )
* V_193 = NULL ;
if ( ( V_116 = F_95 ( V_2 -> V_12 , L_3 , V_191 , 0 , 1 , & V_52 ) ) < 0 )
return V_116 ;
V_52 -> V_17 = V_2 ;
F_96 ( V_52 , V_196 , & V_201 ) ;
V_52 -> V_198 = 0 ;
sprintf ( V_52 -> V_199 , L_4 ,
V_2 -> V_23 == V_128 ? L_5 : L_6 ) ;
V_2 -> V_202 = V_52 ;
F_97 ( V_52 , V_142 ,
F_51 ( V_2 -> V_143 ) , 64 * 1024 , 256 * 1024 ) ;
if ( V_193 )
* V_193 = V_52 ;
return 0 ;
}
int F_100 ( struct V_1 * V_2 , int V_191 ,
struct V_192 * * V_193 )
{
struct V_192 * V_52 ;
int V_116 ;
if ( V_193 )
* V_193 = NULL ;
if ( ( V_116 = F_95 ( V_2 -> V_12 , L_7 , V_191 , 1 , 0 , & V_52 ) ) < 0 )
return V_116 ;
V_52 -> V_17 = V_2 ;
F_96 ( V_52 , V_194 , & V_203 ) ;
V_52 -> V_198 = 0 ;
strcpy ( V_52 -> V_199 , L_7 ) ;
V_2 -> V_204 = V_52 ;
F_97 ( V_52 , V_142 ,
F_51 ( V_2 -> V_143 ) , 64 * 1024 , 256 * 1024 ) ;
if ( V_193 )
* V_193 = V_52 ;
return 0 ;
}
int F_101 ( struct V_1 * V_2 , int V_191 ,
struct V_192 * * V_193 )
{
struct V_192 * V_52 ;
int V_116 ;
if ( V_193 )
* V_193 = NULL ;
if ( ( V_116 = F_95 ( V_2 -> V_12 , L_8 , V_191 , 1 , 0 , & V_52 ) ) < 0 )
return V_116 ;
V_52 -> V_17 = V_2 ;
F_96 ( V_52 , V_194 , & V_205 ) ;
V_52 -> V_198 = 0 ;
strcpy ( V_52 -> V_199 , L_9 ) ;
V_2 -> V_206 = V_52 ;
F_97 ( V_52 , V_142 ,
F_51 ( V_2 -> V_143 ) , 64 * 1024 , 256 * 1024 ) ;
V_116 = F_98 ( V_52 , V_194 ,
V_207 , 2 , 0 , NULL ) ;
if ( V_116 < 0 )
return V_116 ;
if ( V_193 )
* V_193 = V_52 ;
return 0 ;
}
static int F_102 ( struct V_97 * V_208 , struct V_209 * V_210 )
{
V_210 -> type = V_211 ;
V_210 -> V_212 = 1 ;
return 0 ;
}
static int F_103 ( struct V_97 * V_208 ,
struct V_213 * V_214 )
{
struct V_1 * V_2 = F_104 ( V_208 ) ;
F_52 ( & V_2 -> V_31 ) ;
V_214 -> V_215 . V_216 . V_163 [ 0 ] = ( V_2 -> V_185 >> 0 ) & 0xff ;
V_214 -> V_215 . V_216 . V_163 [ 1 ] = ( V_2 -> V_185 >> 8 ) & 0xff ;
V_214 -> V_215 . V_216 . V_163 [ 3 ] = V_217 ;
F_53 ( & V_2 -> V_31 ) ;
return 0 ;
}
static int F_105 ( struct V_97 * V_208 ,
struct V_213 * V_214 )
{
struct V_1 * V_2 = F_104 ( V_208 ) ;
unsigned int V_5 ;
int V_218 ;
V_5 = ( ( V_214 -> V_215 . V_216 . V_163 [ 0 ] & 0x3e ) << 0 ) |
( V_214 -> V_215 . V_216 . V_163 [ 1 ] << 8 ) ;
F_52 ( & V_2 -> V_31 ) ;
V_218 = V_2 -> V_185 != V_5 ;
V_2 -> V_185 = V_5 ;
if ( ( F_5 ( V_2 , V_183 ) & 1 ) && V_2 -> V_204 == NULL )
F_7 ( V_2 , V_186 , V_2 -> V_185 ) ;
F_53 ( & V_2 -> V_31 ) ;
return V_218 ;
}
static int F_106 ( struct V_97 * V_208 , struct V_209 * V_210 )
{
V_210 -> type = V_211 ;
V_210 -> V_212 = 1 ;
return 0 ;
}
static int F_107 ( struct V_97 * V_208 ,
struct V_213 * V_214 )
{
struct V_1 * V_2 = F_104 ( V_208 ) ;
F_52 ( & V_2 -> V_31 ) ;
V_214 -> V_215 . V_216 . V_163 [ 0 ] = 0x3e ;
V_214 -> V_215 . V_216 . V_163 [ 1 ] = 0xff ;
F_53 ( & V_2 -> V_31 ) ;
return 0 ;
}
static int F_108 ( struct V_97 * V_208 , struct V_209 * V_210 )
{
V_210 -> type = V_211 ;
V_210 -> V_212 = 1 ;
return 0 ;
}
static int F_109 ( struct V_97 * V_208 ,
struct V_213 * V_214 )
{
struct V_1 * V_2 = F_104 ( V_208 ) ;
F_52 ( & V_2 -> V_31 ) ;
V_214 -> V_215 . V_216 . V_163 [ 0 ] = ( V_2 -> V_184 >> 0 ) & 0xff ;
V_214 -> V_215 . V_216 . V_163 [ 1 ] = ( V_2 -> V_184 >> 8 ) & 0xff ;
V_214 -> V_215 . V_216 . V_163 [ 3 ] = V_217 ;
F_53 ( & V_2 -> V_31 ) ;
return 0 ;
}
static int F_110 ( struct V_97 * V_208 ,
struct V_213 * V_214 )
{
struct V_1 * V_2 = F_104 ( V_208 ) ;
unsigned int V_5 ;
int V_218 ;
V_5 = ( ( V_214 -> V_215 . V_216 . V_163 [ 0 ] & 0x3e ) << 0 ) |
( V_214 -> V_215 . V_216 . V_163 [ 1 ] << 8 ) ;
F_52 ( & V_2 -> V_31 ) ;
V_218 = V_2 -> V_184 != V_5 ;
V_2 -> V_184 = V_5 ;
if ( ( F_5 ( V_2 , V_183 ) & 2 ) )
F_7 ( V_2 , V_186 , V_2 -> V_184 ) ;
F_53 ( & V_2 -> V_31 ) ;
return V_218 ;
}
static int F_111 ( struct V_97 * V_208 , struct V_209 * V_219 )
{
static const char * const V_220 [ 3 ] = { L_6 , L_10 , L_11 } ;
return F_112 ( V_219 , 1 , 3 , V_220 ) ;
}
static int F_113 ( struct V_97 * V_208 , struct V_213 * V_215 )
{
struct V_1 * V_2 = F_104 ( V_208 ) ;
T_3 V_8 ;
F_52 ( & V_2 -> V_31 ) ;
V_8 = F_5 ( V_2 , V_221 ) ;
F_53 ( & V_2 -> V_31 ) ;
if ( ! ( V_8 & 0x100 ) )
V_215 -> V_215 . V_222 . V_223 [ 0 ] = 0 ;
else
V_215 -> V_215 . V_222 . V_223 [ 0 ] = 1 + ( ( V_8 & 0x200 ) != 0 ) ;
return 0 ;
}
static int F_114 ( struct V_97 * V_208 , struct V_213 * V_215 )
{
struct V_1 * V_2 = F_104 ( V_208 ) ;
T_3 V_8 , V_224 ;
F_52 ( & V_2 -> V_31 ) ;
V_224 = F_5 ( V_2 , V_221 ) ;
if ( V_215 -> V_215 . V_222 . V_223 [ 0 ] == 0 )
V_8 = V_224 & ~ 0x100 ;
else
V_8 = ( V_224 & ~ 0x300 ) | 0x100 | ( ( V_215 -> V_215 . V_222 . V_223 [ 0 ] == 2 ) << 9 ) ;
F_7 ( V_2 , V_221 , V_8 ) ;
F_53 ( & V_2 -> V_31 ) ;
return V_8 != V_224 ;
}
static int F_115 ( struct V_97 * V_208 ,
struct V_213 * V_214 )
{
struct V_1 * V_2 = F_104 ( V_208 ) ;
int V_8 = V_208 -> V_225 & 0xffff ;
unsigned int V_96 = ( V_208 -> V_225 >> 16 ) & 0xff ;
unsigned int V_226 = 1 ;
switch ( V_8 ) {
case V_183 : break;
case V_227 : break;
default: return - V_59 ;
}
V_214 -> V_215 . integer . V_215 [ 0 ] =
( F_9 ( V_2 , V_8 ) >> V_96 ) & V_226 ;
return 0 ;
}
static int F_116 ( struct V_97 * V_208 ,
struct V_213 * V_214 )
{
struct V_1 * V_2 = F_104 ( V_208 ) ;
int V_8 = V_208 -> V_225 & 0xffff ;
unsigned int V_96 = ( V_208 -> V_225 >> 16 ) & 0xff ;
unsigned int V_226 = 1 ;
int V_218 ;
unsigned int V_5 , V_228 ;
switch ( V_8 ) {
case V_183 : break;
case V_227 : break;
default: return - V_59 ;
}
V_5 = ( V_214 -> V_215 . integer . V_215 [ 0 ] & V_226 ) ;
V_5 <<= V_96 ;
F_52 ( & V_2 -> V_31 ) ;
V_228 = F_9 ( V_2 , V_8 ) ;
V_5 = ( V_228 & ~ ( V_226 << V_96 ) ) | V_5 ;
V_218 = V_5 != V_228 ;
F_11 ( V_2 , V_8 , V_5 ) ;
F_53 ( & V_2 -> V_31 ) ;
return V_218 ;
}
static int F_117 ( struct V_97 * V_208 , struct V_209 * V_210 )
{
unsigned int V_8 = V_208 -> V_225 ;
if ( V_8 < 0x80 || V_8 >= 0xc0 )
return - V_59 ;
V_210 -> type = V_229 ;
V_210 -> V_212 = 2 ;
V_210 -> V_215 . integer . V_230 = 0 ;
V_210 -> V_215 . integer . V_231 = 16383 ;
return 0 ;
}
static int F_118 ( struct V_97 * V_208 , struct V_213 * V_214 )
{
struct V_1 * V_2 = F_104 ( V_208 ) ;
unsigned int V_8 = V_208 -> V_225 ;
unsigned int V_232 = 0 , V_233 = 16 , V_226 = 16383 ;
unsigned int V_5 ;
if ( V_8 < 0x80 || V_8 >= 0xc0 )
return - V_59 ;
F_52 ( & V_2 -> V_31 ) ;
V_5 = F_9 ( V_2 , V_8 ) ;
F_53 ( & V_2 -> V_31 ) ;
V_214 -> V_215 . integer . V_215 [ 0 ] = ( V_5 >> V_232 ) & V_226 ;
V_214 -> V_215 . integer . V_215 [ 1 ] = ( V_5 >> V_233 ) & V_226 ;
return 0 ;
}
static int F_119 ( struct V_97 * V_208 , struct V_213 * V_214 )
{
struct V_1 * V_2 = F_104 ( V_208 ) ;
unsigned int V_8 = V_208 -> V_225 ;
unsigned int V_232 = 0 , V_233 = 16 , V_226 = 16383 ;
int V_218 ;
unsigned int V_234 , V_235 , V_228 ;
if ( V_8 < 0x80 || V_8 >= 0xc0 )
return - V_59 ;
V_234 = V_214 -> V_215 . integer . V_215 [ 0 ] & V_226 ;
V_235 = V_214 -> V_215 . integer . V_215 [ 1 ] & V_226 ;
V_234 <<= V_232 ;
V_235 <<= V_233 ;
F_52 ( & V_2 -> V_31 ) ;
V_228 = F_9 ( V_2 , V_8 ) ;
V_234 = ( V_228 & ~ ( ( V_226 << V_232 ) | ( V_226 << V_233 ) ) ) | V_234 | V_235 ;
V_218 = V_234 != V_228 ;
F_11 ( V_2 , V_8 , V_234 ) ;
F_53 ( & V_2 -> V_31 ) ;
return V_218 ;
}
static int F_120 ( struct V_97 * V_208 ,
struct V_213 * V_214 )
{
struct V_1 * V_2 = F_104 ( V_208 ) ;
unsigned int V_8 = V_236 ;
unsigned int V_237 = V_238 ;
int V_218 ;
unsigned int V_215 , V_228 ;
V_215 = V_214 -> V_215 . integer . V_215 [ 0 ] & 0x3fff ;
V_215 |= ( V_214 -> V_215 . integer . V_215 [ 1 ] & 0x3fff ) << 16 ;
F_52 ( & V_2 -> V_31 ) ;
V_228 = F_9 ( V_2 , V_8 ) ;
V_218 = V_215 != V_228 ;
F_11 ( V_2 , V_8 , V_215 ) ;
F_11 ( V_2 , V_237 , V_215 ) ;
F_53 ( & V_2 -> V_31 ) ;
return V_218 ;
}
static int F_121 ( struct V_97 * V_208 , struct V_213 * V_214 )
{
struct V_1 * V_2 = F_104 ( V_208 ) ;
V_214 -> V_215 . integer . V_215 [ 0 ] = V_2 -> V_182 ;
return 0 ;
}
static int F_122 ( struct V_97 * V_208 , struct V_213 * V_214 )
{
struct V_1 * V_2 = F_104 ( V_208 ) ;
int V_218 ;
V_218 = ( V_214 -> V_215 . integer . V_215 [ 0 ] != V_2 -> V_182 ) ;
if ( V_218 )
V_2 -> V_182 = ! ! V_214 -> V_215 . integer . V_215 [ 0 ] ;
return V_218 ;
}
static int F_123 ( struct V_1 * V_2 , int V_239 )
{
T_3 V_8 , V_164 ;
unsigned long V_30 ;
F_24 ( & V_2 -> V_31 , V_30 ) ;
V_8 = F_5 ( V_2 , V_240 ) ;
V_8 &= ~ ( 1 << ( V_239 + 8 ) ) ;
V_8 |= ( 1 << V_239 ) ;
F_7 ( V_2 , V_240 , V_8 ) ;
V_164 = F_5 ( V_2 , V_241 ) ;
V_164 &= ~ ( 3 << ( V_239 * 2 ) ) ;
F_7 ( V_2 , V_241 , V_164 ) ;
F_7 ( V_2 , V_240 , V_8 | ( 1 << ( V_239 + 8 ) ) ) ;
V_164 = F_5 ( V_2 , V_242 ) ;
F_25 ( & V_2 -> V_31 , V_30 ) ;
return ( V_164 >> V_239 ) & 1 ;
}
static int F_124 ( struct V_1 * V_2 , int V_239 , int V_243 )
{
T_3 V_8 ;
unsigned long V_30 ;
F_24 ( & V_2 -> V_31 , V_30 ) ;
V_8 = F_5 ( V_2 , V_240 ) ;
V_8 &= ~ ( 1 << V_239 ) ;
V_8 &= ~ ( 1 << ( V_239 + 8 ) ) ;
F_7 ( V_2 , V_240 , V_8 ) ;
F_7 ( V_2 , V_244 , V_243 << V_239 ) ;
F_7 ( V_2 , V_240 , V_8 | ( 1 << ( V_239 + 8 ) ) ) ;
F_25 ( & V_2 -> V_31 , V_30 ) ;
return 0 ;
}
static int F_125 ( struct V_97 * V_208 , struct V_213 * V_214 )
{
struct V_1 * V_2 = F_104 ( V_208 ) ;
int V_239 = ( int ) V_208 -> V_225 ;
V_214 -> V_215 . integer . V_215 [ 0 ] = F_123 ( V_2 , V_239 ) ;
return 0 ;
}
static int F_126 ( struct V_97 * V_208 , struct V_213 * V_214 )
{
struct V_1 * V_2 = F_104 ( V_208 ) ;
int V_239 = ( int ) V_208 -> V_225 ;
if ( F_123 ( V_2 , V_239 ) != V_214 -> V_215 . integer . V_215 [ 0 ] ) {
F_124 ( V_2 , V_239 , ! ! V_214 -> V_215 . integer . V_215 [ 0 ] ) ;
V_214 -> V_215 . integer . V_215 [ 0 ] = F_123 ( V_2 , V_239 ) ;
return 1 ;
}
return 0 ;
}
static int F_127 ( struct V_97 * V_208 ,
struct V_209 * V_210 )
{
V_210 -> type = V_229 ;
V_210 -> V_212 = 2 ;
V_210 -> V_215 . integer . V_230 = 0 ;
V_210 -> V_215 . integer . V_231 = 0x8000 ;
return 0 ;
}
static int F_128 ( struct V_97 * V_208 ,
struct V_213 * V_214 )
{
struct V_1 * V_2 = F_104 ( V_208 ) ;
unsigned int V_79 = V_208 -> V_113 . V_245 ;
V_214 -> V_215 . integer . V_215 [ 0 ] = V_2 -> V_83 [ V_79 ] . V_84 ;
V_214 -> V_215 . integer . V_215 [ 1 ] = V_2 -> V_83 [ V_79 ] . V_88 ;
return 0 ;
}
static int F_129 ( struct V_97 * V_208 ,
struct V_213 * V_214 )
{
struct V_1 * V_2 = F_104 ( V_208 ) ;
unsigned int V_79 = V_208 -> V_113 . V_245 ;
struct V_91 * V_70 ;
unsigned long V_30 ;
if ( V_214 -> V_215 . integer . V_215 [ 0 ] != V_2 -> V_83 [ V_79 ] . V_84 ||
V_214 -> V_215 . integer . V_215 [ 1 ] != V_2 -> V_83 [ V_79 ] . V_88 ) {
V_2 -> V_83 [ V_79 ] . V_84 = V_214 -> V_215 . integer . V_215 [ 0 ] ;
V_2 -> V_83 [ V_79 ] . V_88 = V_214 -> V_215 . integer . V_215 [ 1 ] ;
if ( V_2 -> V_83 [ V_79 ] . V_84 > 0x8000 )
V_2 -> V_83 [ V_79 ] . V_84 = 0x8000 ;
if ( V_2 -> V_83 [ V_79 ] . V_88 > 0x8000 )
V_2 -> V_83 [ V_79 ] . V_88 = 0x8000 ;
V_70 = (struct V_91 * ) V_208 -> V_225 ;
F_24 ( & V_2 -> V_60 , V_30 ) ;
if ( V_70 -> V_93 && V_70 -> V_93 -> V_17 ) {
struct V_67 * V_64 = V_70 -> V_93 -> V_17 ;
if ( ! V_64 -> V_65 )
V_64 -> V_78 = 2 ;
}
F_25 ( & V_2 -> V_60 , V_30 ) ;
return 1 ;
}
return 0 ;
}
static void F_130 ( struct V_246 * V_247 )
{
struct V_1 * V_2 = V_247 -> V_17 ;
V_2 -> V_248 = NULL ;
}
static void F_131 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
V_2 -> V_16 = NULL ;
}
int F_132 ( struct V_1 * V_2 , int V_249 )
{
struct V_250 V_16 ;
struct V_97 * V_98 ;
struct V_91 * V_70 ;
unsigned int V_47 ;
int V_116 ;
static struct V_251 V_252 = {
. V_253 = F_18 ,
. V_254 = F_19 ,
} ;
if ( ( V_116 = V_246 ( V_2 -> V_12 , 0 , & V_252 , V_2 , & V_2 -> V_248 ) ) < 0 )
return V_116 ;
V_2 -> V_248 -> V_178 = F_130 ;
V_2 -> V_248 -> V_255 = 1 ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
V_16 . V_17 = V_2 ;
V_16 . V_178 = F_131 ;
if ( ( V_116 = F_133 ( V_2 -> V_248 , & V_16 , & V_2 -> V_16 ) ) < 0 )
return V_116 ;
F_134 ( V_2 -> V_16 , V_256 ,
V_257 | V_258 , 0 ) ;
for ( V_47 = 0 ; V_47 < F_135 ( V_259 ) ; V_47 ++ ) {
if ( ( V_116 = F_136 ( V_2 -> V_12 , F_137 ( & V_259 [ V_47 ] , V_2 ) ) ) < 0 )
return V_116 ;
}
if ( V_2 -> V_16 -> V_260 & V_261 ) {
V_98 = F_137 ( & V_262 , V_2 ) ;
V_116 = F_136 ( V_2 -> V_12 , V_98 ) ;
if ( V_116 < 0 )
return V_116 ;
}
if ( F_32 ( ! V_2 -> V_204 ) )
return - V_263 ;
if ( ( V_116 = F_136 ( V_2 -> V_12 , V_98 = F_137 ( & V_264 , V_2 ) ) ) < 0 )
return V_116 ;
V_98 -> V_113 . V_191 = V_2 -> V_204 -> V_191 ;
if ( ( V_116 = F_136 ( V_2 -> V_12 , V_98 = F_137 ( & V_265 , V_2 ) ) ) < 0 )
return V_116 ;
V_98 -> V_113 . V_191 = V_2 -> V_204 -> V_191 ;
if ( ( V_116 = F_136 ( V_2 -> V_12 , V_98 = F_137 ( & V_266 , V_2 ) ) ) < 0 )
return V_116 ;
V_98 -> V_113 . V_191 = V_2 -> V_204 -> V_191 ;
V_2 -> V_187 = V_98 ;
if ( V_2 -> V_23 == V_128 &&
( V_116 = F_136 ( V_2 -> V_12 , V_98 = F_137 ( & V_267 , V_2 ) ) ) < 0 )
return V_116 ;
if ( V_249 ) {
if ( ( V_116 = F_136 ( V_2 -> V_12 , F_137 ( & V_268 , V_2 ) ) ) < 0 )
return V_116 ;
}
V_70 = V_2 -> V_52 -> V_269 [ V_194 ] . V_70 ;
for ( V_47 = 0 ; V_47 < 32 ; ++ V_47 ) {
V_98 = F_137 ( & V_270 , V_2 ) ;
if ( ! V_98 )
return - V_57 ;
V_98 -> V_113 . V_191 = V_2 -> V_52 -> V_191 ;
V_98 -> V_113 . V_245 = V_47 ;
V_98 -> V_225 = ( unsigned long ) V_70 ;
if ( ( V_116 = F_136 ( V_2 -> V_12 , V_98 ) ) < 0 )
return V_116 ;
V_2 -> V_83 [ V_47 ] . V_84 = 0x8000 ;
V_2 -> V_83 [ V_47 ] . V_88 = 0x8000 ;
V_2 -> V_83 [ V_47 ] . V_106 = V_98 ;
V_70 = V_70 -> V_271 ;
}
return 0 ;
}
static int F_138 ( struct V_272 * V_168 )
{
struct V_1 * V_2 ;
unsigned long V_30 ;
unsigned int V_212 ;
V_2 = F_139 ( V_168 ) ;
F_24 ( & V_2 -> V_31 , V_30 ) ;
if ( V_168 -> V_273 > 1 ) {
V_2 -> V_169 = V_168 -> V_273 ;
V_212 = V_168 -> V_273 - 1 ;
} else {
V_2 -> V_169 = 2 ;
V_212 = 2 - 1 ;
}
F_7 ( V_2 , V_274 , V_212 ) ;
F_3 ( V_2 , V_275 , 0x03 ) ;
F_25 ( & V_2 -> V_31 , V_30 ) ;
return 0 ;
}
static int F_140 ( struct V_272 * V_168 )
{
struct V_1 * V_2 ;
unsigned long V_30 ;
V_2 = F_139 ( V_168 ) ;
F_24 ( & V_2 -> V_31 , V_30 ) ;
F_3 ( V_2 , V_275 , 0x00 ) ;
F_25 ( & V_2 -> V_31 , V_30 ) ;
return 0 ;
}
static int F_141 ( struct V_272 * V_168 ,
unsigned long * V_276 , unsigned long * V_277 )
{
* V_276 = 1 ;
* V_277 = 96000 ;
return 0 ;
}
int F_142 ( struct V_1 * V_2 , int V_191 )
{
struct V_272 * V_168 = NULL ;
struct V_278 V_279 ;
int V_116 ;
V_279 . V_280 = V_281 ;
V_279 . V_282 = V_283 ;
V_279 . V_12 = V_2 -> V_12 -> V_62 ;
V_279 . V_191 = V_191 ;
V_279 . V_245 = 0 ;
if ( ( V_116 = F_143 ( V_2 -> V_12 , L_2 , & V_279 , & V_168 ) ) >= 0 ) {
strcpy ( V_168 -> V_199 , L_12 ) ;
V_168 -> V_17 = V_2 ;
V_168 -> V_172 = V_284 ;
}
V_2 -> V_168 = V_168 ;
return V_116 ;
}
static void F_144 ( struct V_285 * V_286 ,
struct V_287 * V_288 )
{
struct V_1 * V_2 = V_286 -> V_17 ;
int V_26 ;
F_145 ( V_288 , L_13 ) ;
for ( V_26 = 0 ; V_26 <= V_289 ; V_26 += 4 )
F_145 ( V_288 , L_14 , V_26 , F_9 ( V_2 , V_26 ) ) ;
}
static int F_146 ( struct V_290 * V_12 , struct V_1 * V_2 )
{
struct V_285 * V_286 ;
if ( ! F_147 ( V_12 , L_15 , & V_286 ) )
F_148 ( V_286 , V_2 , F_144 ) ;
return 0 ;
}
static void F_149 ( struct V_291 * V_143 )
{
T_1 V_18 ;
F_150 ( V_143 , V_292 , & V_18 ) ;
#if 0
if (cmd & 0x03) {
#endif
F_151 ( V_143 , V_292 , V_18 & 0xfc ) ;
F_151 ( V_143 , V_292 , V_18 | 0x03 ) ;
F_151 ( V_143 , V_292 , V_18 & 0xfc ) ;
F_152 ( V_143 , V_293 , 0 ) ;
F_152 ( V_143 , V_294 , 0 ) ;
#if 0
}
#endif
}
static void F_153 ( struct V_1 * V_2 )
{
F_11 ( V_2 , V_295 , 0x00000001 ) ;
}
static void F_154 ( struct V_1 * V_2 )
{
T_2 V_5 ;
int V_37 = 1000 ;
V_5 = F_9 ( V_2 , V_295 ) ;
if ( V_5 )
F_11 ( V_2 , V_295 , 0x00000000 ) ;
while ( V_37 -- > 0 ) {
V_5 = F_9 ( V_2 , V_38 ) ;
if ( ( V_5 & 0x00000002 ) == 0 )
break;
}
}
static int F_155 ( struct V_1 * V_2 )
{
int V_116 , V_296 ;
const char * V_199 ;
V_116 = F_156 ( & V_2 -> V_297 , L_16 ,
& V_2 -> V_143 -> V_13 ) ;
if ( V_116 >= 0 ) {
if ( V_2 -> V_297 -> V_298 != V_299 ) {
F_17 ( V_2 -> V_12 -> V_13 ,
L_17 ) ;
V_116 = - V_59 ;
}
}
if ( V_116 < 0 )
return V_116 ;
V_296 = V_2 -> V_23 == V_300 ||
V_2 -> V_23 == V_301 ||
V_2 -> V_23 == V_24 ||
V_2 -> V_23 == V_128 ;
V_199 = V_296 ? L_18 : L_19 ;
V_116 = F_156 ( & V_2 -> V_302 , V_199 ,
& V_2 -> V_143 -> V_13 ) ;
if ( V_116 >= 0 ) {
if ( V_2 -> V_302 -> V_298 != V_303 ) {
F_17 ( V_2 -> V_12 -> V_13 ,
L_20 ) ;
V_116 = - V_59 ;
}
}
if ( V_116 < 0 )
return V_116 ;
return 0 ;
}
static void F_157 ( struct V_1 * V_2 )
{
int V_26 ;
T_3 V_304 ;
const T_7 * V_305 ;
F_11 ( V_2 , V_236 , 0x00000000 ) ;
F_154 ( V_2 ) ;
F_11 ( V_2 , V_34 , 0x00010000 ) ;
F_11 ( V_2 , V_34 , 0x00000000 ) ;
F_11 ( V_2 , V_115 , 0x00000000 ) ;
F_11 ( V_2 , V_147 , 0x00000000 ) ;
F_11 ( V_2 , V_306 , 0x00000000 ) ;
F_11 ( V_2 , V_307 , 0x00000000 ) ;
F_11 ( V_2 , V_308 , 0x00000000 ) ;
V_304 = F_5 ( V_2 , V_221 ) ;
F_7 ( V_2 , V_221 , V_304 & ~ 0x0007 ) ;
V_305 = ( const T_7 * ) V_2 -> V_297 -> V_309 ;
for ( V_26 = 0 ; V_26 < V_299 / 4 ; V_26 ++ )
F_11 ( V_2 , V_310 + ( V_26 << 2 ) ,
F_36 ( V_305 [ V_26 ] ) ) ;
V_305 = ( const T_7 * ) V_2 -> V_302 -> V_309 ;
for ( V_26 = 0 ; V_26 < V_303 / 4 ; V_26 ++ )
F_11 ( V_2 , V_311 + ( V_26 << 2 ) ,
F_36 ( V_305 [ V_26 ] ) ) ;
F_153 ( V_2 ) ;
}
static int F_158 ( struct V_1 * V_2 )
{
long V_298 , V_312 ;
int V_45 , V_72 , V_8 ;
T_1 * V_313 ;
T_8 V_314 ;
V_312 = 4 + 4 * V_48 ;
V_2 -> V_315 = F_9 ( V_2 , V_316 ) << 2 ;
V_2 -> V_317 = F_9 ( V_2 , V_318 ) << 2 ;
V_2 -> V_319 = F_9 ( V_2 , V_320 ) << 2 ;
V_2 -> V_321 = V_322 ;
V_298 = F_159 ( V_312 , 0x100 ) +
F_159 ( V_2 -> V_315 * 2 * V_48 , 0x100 ) +
F_159 ( V_2 -> V_317 * 2 * V_165 , 0x100 ) +
F_159 ( V_2 -> V_319 * 2 * V_323 , 0x100 ) +
V_2 -> V_321 ;
if ( F_50 ( V_142 , F_51 ( V_2 -> V_143 ) ,
V_298 , & V_2 -> V_324 ) < 0 )
return - V_57 ;
V_313 = V_2 -> V_324 . V_148 ;
V_314 = V_2 -> V_324 . V_146 ;
memset ( V_313 , 0 , V_298 ) ;
V_2 -> V_325 = V_313 ;
V_2 -> V_326 = V_314 ;
V_2 -> V_103 = ( T_2 * ) V_313 ;
V_2 -> V_103 [ 0 ] = F_40 ( V_48 ) ;
V_313 += F_159 ( V_312 , 0x100 ) ;
V_314 += F_159 ( V_312 , 0x100 ) ;
for ( V_45 = 0 ; V_45 < V_48 ; V_45 ++ ) {
V_2 -> V_49 [ V_45 ] . V_62 = V_45 ;
V_2 -> V_49 [ V_45 ] . V_72 = (struct V_81 * ) V_313 ;
V_2 -> V_49 [ V_45 ] . V_104 = V_314 ;
for ( V_72 = 0 ; V_72 < 2 ; V_72 ++ ) {
V_2 -> V_327 [ V_45 ] [ V_72 ] = (struct V_81 * ) V_313 ;
V_313 += V_2 -> V_315 ;
V_314 += V_2 -> V_315 ;
}
}
V_313 = ( char * ) F_159 ( ( unsigned long ) V_313 , 0x100 ) ;
V_314 = F_159 ( V_314 , 0x100 ) ;
V_2 -> V_328 = V_313 ;
V_2 -> V_329 = V_314 ;
for ( V_45 = 0 ; V_45 < V_165 ; V_45 ++ )
for ( V_72 = 0 ; V_72 < 2 ; V_72 ++ ) {
V_2 -> V_94 [ V_45 ] [ V_72 ] = (struct V_152 * ) V_313 ;
V_313 += V_2 -> V_317 ;
V_314 += V_2 -> V_317 ;
}
V_313 = ( char * ) F_159 ( ( unsigned long ) V_313 , 0x100 ) ;
V_314 = F_159 ( V_314 , 0x100 ) ;
V_2 -> V_330 = V_313 ;
V_2 -> V_331 = V_314 ;
for ( V_45 = 0 ; V_45 < V_323 ; V_45 ++ )
for ( V_72 = 0 ; V_72 < 2 ; V_72 ++ ) {
V_2 -> V_145 [ V_45 ] [ V_72 ] = (struct V_332 * ) V_313 ;
V_313 += V_2 -> V_319 ;
V_314 += V_2 -> V_319 ;
}
V_313 = ( char * ) F_159 ( ( unsigned long ) V_313 , 0x100 ) ;
V_314 = F_159 ( V_314 , 0x100 ) ;
V_2 -> V_333 = V_313 ;
V_2 -> V_334 = V_314 ;
F_32 ( V_313 + V_2 -> V_321 !=
V_2 -> V_324 . V_148 + V_2 -> V_324 . V_335 ) ;
F_11 ( V_2 , V_306 , V_2 -> V_326 ) ;
F_11 ( V_2 , V_307 , V_2 -> V_329 ) ;
F_11 ( V_2 , V_308 , V_2 -> V_331 ) ;
F_11 ( V_2 , V_289 , V_2 -> V_334 ) ;
F_11 ( V_2 , V_336 , V_2 -> V_321 >> 2 ) ;
V_2 -> V_185 = V_2 -> V_184 = V_337 & 0xffff ;
F_7 ( V_2 , V_183 , 0 ) ;
F_7 ( V_2 , V_186 , V_2 -> V_185 ) ;
F_7 ( V_2 , V_227 , 0 ) ;
for ( V_8 = 0x80 ; V_8 < 0xc0 ; V_8 += 4 )
F_11 ( V_2 , V_8 , 0 ) ;
F_11 ( V_2 , V_236 , 0x3fff3fff ) ;
F_11 ( V_2 , V_238 , 0x3fff3fff ) ;
F_11 ( V_2 , V_338 , 0x3fff3fff ) ;
F_11 ( V_2 , V_339 , 0x3fff3fff ) ;
F_11 ( V_2 , V_340 , 0x3fff3fff ) ;
F_11 ( V_2 , V_341 , 0x3fff3fff ) ;
F_11 ( V_2 , V_342 , 0x3fff3fff ) ;
F_11 ( V_2 , V_343 , 0x3fff3fff ) ;
return 0 ;
}
static int F_160 ( struct V_1 * V_2 )
{
T_3 V_304 ;
if ( F_32 ( ! V_2 ) )
return - V_59 ;
if ( V_2 -> V_344 ) {
F_11 ( V_2 , V_236 , 0 ) ;
F_11 ( V_2 , V_238 , 0 ) ;
F_11 ( V_2 , V_343 , 0 ) ;
F_11 ( V_2 , V_38 , ~ 0 ) ;
F_154 ( V_2 ) ;
F_11 ( V_2 , V_306 , 0 ) ;
F_11 ( V_2 , V_307 , 0 ) ;
F_11 ( V_2 , V_308 , 0 ) ;
F_11 ( V_2 , V_289 , 0 ) ;
F_11 ( V_2 , V_336 , 0 ) ;
V_304 = F_5 ( V_2 , V_221 ) ;
F_7 ( V_2 , V_221 , V_304 & ~ 0x0007 ) ;
}
F_54 ( V_2 ) ;
#if 0
pci_set_power_state(chip->pci, PCI_D3hot);
#endif
#ifdef F_161
F_77 ( V_2 -> V_345 ) ;
#endif
if ( V_2 -> V_161 >= 0 )
F_162 ( V_2 -> V_161 , V_2 ) ;
F_163 ( V_2 -> V_346 ) ;
F_163 ( V_2 -> V_347 ) ;
F_164 ( V_2 ) ;
if ( V_2 -> V_4 )
F_165 ( V_2 -> V_4 ) ;
if ( V_2 -> V_324 . V_148 )
F_55 ( & V_2 -> V_324 ) ;
F_163 ( V_2 -> V_344 ) ;
F_152 ( V_2 -> V_143 , 0x40 , V_2 -> V_348 ) ;
F_166 ( V_2 -> V_143 ) ;
F_167 ( V_2 -> V_297 ) ;
F_167 ( V_2 -> V_302 ) ;
F_77 ( V_2 ) ;
return 0 ;
}
static int F_168 ( struct V_349 * V_191 )
{
struct V_1 * V_2 = V_191 -> V_350 ;
return F_160 ( V_2 ) ;
}
static int F_169 ( struct V_191 * V_13 )
{
struct V_291 * V_143 = F_170 ( V_13 ) ;
struct V_290 * V_12 = F_171 ( V_13 ) ;
struct V_1 * V_2 = V_12 -> V_17 ;
unsigned int V_26 ;
F_172 ( V_12 , V_351 ) ;
F_173 ( V_2 -> V_52 ) ;
F_173 ( V_2 -> V_202 ) ;
F_173 ( V_2 -> V_204 ) ;
F_173 ( V_2 -> V_206 ) ;
F_174 ( V_2 -> V_16 ) ;
for ( V_26 = 0 ; V_26 < V_352 ; V_26 ++ )
V_2 -> V_345 [ V_26 ] = F_9 ( V_2 , V_353 [ V_26 ] ) ;
V_2 -> V_354 = F_9 ( V_2 , V_34 ) ;
F_175 ( V_2 -> V_143 , V_355 ,
& V_2 -> V_356 ) ;
F_175 ( V_2 -> V_143 , V_357 ,
& V_2 -> V_358 ) ;
F_11 ( V_2 , V_236 , 0 ) ;
F_11 ( V_2 , V_238 , 0 ) ;
F_154 ( V_2 ) ;
F_166 ( V_143 ) ;
F_176 ( V_143 ) ;
F_177 ( V_143 , V_359 ) ;
return 0 ;
}
static int F_178 ( struct V_191 * V_13 )
{
struct V_291 * V_143 = F_170 ( V_13 ) ;
struct V_290 * V_12 = F_171 ( V_13 ) ;
struct V_1 * V_2 = V_12 -> V_17 ;
unsigned int V_26 ;
F_177 ( V_143 , V_360 ) ;
F_179 ( V_143 ) ;
if ( F_180 ( V_143 ) < 0 ) {
F_17 ( V_13 , L_21 ) ;
F_181 ( V_12 ) ;
return - V_361 ;
}
F_182 ( V_143 ) ;
F_149 ( V_143 ) ;
F_13 ( V_2 , 0 ) ;
F_157 ( V_2 ) ;
F_183 ( 100 ) ;
for ( V_26 = 0 ; V_26 < V_352 ; V_26 ++ )
F_11 ( V_2 , V_353 [ V_26 ] , V_2 -> V_345 [ V_26 ] ) ;
F_184 ( V_2 -> V_16 ) ;
F_152 ( V_2 -> V_143 , V_355 ,
V_2 -> V_356 ) ;
F_152 ( V_2 -> V_143 , V_357 ,
V_2 -> V_358 ) ;
if ( V_2 -> V_32 > 0 ) {
F_52 ( & V_2 -> V_31 ) ;
F_11 ( V_2 , V_34 , V_2 -> V_354 ) ;
V_2 -> V_35 = F_9 ( V_2 , V_36 ) ;
F_53 ( & V_2 -> V_31 ) ;
}
F_172 ( V_12 , V_362 ) ;
return 0 ;
}
int F_185 ( struct V_290 * V_12 ,
struct V_291 * V_143 ,
unsigned short V_348 ,
struct V_1 * * V_363 )
{
struct V_1 * V_2 ;
int V_116 ;
static struct V_364 V_252 = {
. V_365 = F_168 ,
} ;
* V_363 = NULL ;
if ( ( V_116 = F_180 ( V_143 ) ) < 0 )
return V_116 ;
V_2 = F_81 ( sizeof( * V_2 ) , V_176 ) ;
if ( V_2 == NULL ) {
F_166 ( V_143 ) ;
return - V_57 ;
}
V_2 -> V_348 = V_348 ;
F_186 ( & V_2 -> V_31 ) ;
F_186 ( & V_2 -> V_60 ) ;
F_187 ( & V_2 -> V_40 ) ;
F_28 ( & V_2 -> V_39 , 0 ) ;
V_2 -> V_12 = V_12 ;
V_2 -> V_143 = V_143 ;
V_2 -> V_161 = - 1 ;
V_2 -> V_23 = V_143 -> V_191 ;
V_2 -> V_25 = V_143 -> V_366 ;
V_2 -> V_367 = F_188 ( V_143 , 0 ) ;
V_2 -> V_4 = F_189 ( V_2 -> V_367 , 0x8000 ) ;
F_182 ( V_143 ) ;
V_2 -> V_63 = - 1 ;
if ( ( V_2 -> V_344 = F_190 ( V_2 -> V_367 , 0x8000 , L_2 ) ) == NULL ) {
F_17 ( V_2 -> V_12 -> V_13 ,
L_22 ,
V_2 -> V_367 , V_2 -> V_367 + 0x8000 - 1 ) ;
F_160 ( V_2 ) ;
return - V_14 ;
}
if ( F_191 ( V_143 -> V_161 , F_73 , V_368 ,
V_369 , V_2 ) ) {
F_17 ( V_2 -> V_12 -> V_13 , L_23 , V_143 -> V_161 ) ;
F_160 ( V_2 ) ;
return - V_14 ;
}
V_2 -> V_161 = V_143 -> V_161 ;
F_149 ( V_143 ) ;
if ( F_13 ( V_2 , 0 ) < 0 ) {
F_160 ( V_2 ) ;
return - V_361 ;
}
V_116 = F_155 ( V_2 ) ;
if ( V_116 < 0 ) {
F_17 ( V_2 -> V_12 -> V_13 , L_24 , V_116 ) ;
F_160 ( V_2 ) ;
return V_116 ;
}
F_157 ( V_2 ) ;
F_183 ( 100 ) ;
if ( F_158 ( V_2 ) < 0 ) {
F_160 ( V_2 ) ;
return - V_361 ;
}
if ( ( V_116 = F_49 ( V_2 ) ) < 0 ) {
F_160 ( V_2 ) ;
return V_116 ;
}
#ifdef F_161
V_2 -> V_345 = F_192 ( V_352 * sizeof( T_2 ) ,
V_176 ) ;
if ( V_2 -> V_345 == NULL ) {
F_160 ( V_2 ) ;
return - V_57 ;
}
#endif
if ( ( V_116 = F_193 ( V_12 , V_370 , V_2 , & V_252 ) ) < 0 ) {
F_160 ( V_2 ) ;
return V_116 ;
}
F_146 ( V_12 , V_2 ) ;
* V_363 = V_2 ;
return 0 ;
}
