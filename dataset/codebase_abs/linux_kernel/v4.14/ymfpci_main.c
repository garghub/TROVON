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
int V_67 ( struct V_1 * V_2 , int V_191 )
{
struct V_192 * V_52 ;
int V_116 ;
if ( ( V_116 = F_95 ( V_2 -> V_12 , L_2 , V_191 , 32 , 1 , & V_52 ) ) < 0 )
return V_116 ;
V_52 -> V_17 = V_2 ;
F_96 ( V_52 , V_193 , & V_194 ) ;
F_96 ( V_52 , V_195 , & V_196 ) ;
V_52 -> V_197 = 0 ;
strcpy ( V_52 -> V_198 , L_2 ) ;
V_2 -> V_52 = V_52 ;
F_97 ( V_52 , V_142 ,
F_51 ( V_2 -> V_143 ) , 64 * 1024 , 256 * 1024 ) ;
return F_98 ( V_52 , V_193 ,
V_199 , 2 , 0 , NULL ) ;
}
int F_99 ( struct V_1 * V_2 , int V_191 )
{
struct V_192 * V_52 ;
int V_116 ;
if ( ( V_116 = F_95 ( V_2 -> V_12 , L_3 , V_191 , 0 , 1 , & V_52 ) ) < 0 )
return V_116 ;
V_52 -> V_17 = V_2 ;
F_96 ( V_52 , V_195 , & V_200 ) ;
V_52 -> V_197 = 0 ;
sprintf ( V_52 -> V_198 , L_4 ,
V_2 -> V_23 == V_128 ? L_5 : L_6 ) ;
V_2 -> V_201 = V_52 ;
F_97 ( V_52 , V_142 ,
F_51 ( V_2 -> V_143 ) , 64 * 1024 , 256 * 1024 ) ;
return 0 ;
}
int F_100 ( struct V_1 * V_2 , int V_191 )
{
struct V_192 * V_52 ;
int V_116 ;
if ( ( V_116 = F_95 ( V_2 -> V_12 , L_7 , V_191 , 1 , 0 , & V_52 ) ) < 0 )
return V_116 ;
V_52 -> V_17 = V_2 ;
F_96 ( V_52 , V_193 , & V_202 ) ;
V_52 -> V_197 = 0 ;
strcpy ( V_52 -> V_198 , L_7 ) ;
V_2 -> V_203 = V_52 ;
F_97 ( V_52 , V_142 ,
F_51 ( V_2 -> V_143 ) , 64 * 1024 , 256 * 1024 ) ;
return 0 ;
}
int F_101 ( struct V_1 * V_2 , int V_191 )
{
struct V_192 * V_52 ;
int V_116 ;
if ( ( V_116 = F_95 ( V_2 -> V_12 , L_8 , V_191 , 1 , 0 , & V_52 ) ) < 0 )
return V_116 ;
V_52 -> V_17 = V_2 ;
F_96 ( V_52 , V_193 , & V_204 ) ;
V_52 -> V_197 = 0 ;
strcpy ( V_52 -> V_198 , L_9 ) ;
V_2 -> V_205 = V_52 ;
F_97 ( V_52 , V_142 ,
F_51 ( V_2 -> V_143 ) , 64 * 1024 , 256 * 1024 ) ;
return F_98 ( V_52 , V_193 ,
V_206 , 2 , 0 , NULL ) ;
}
static int F_102 ( struct V_97 * V_207 , struct V_208 * V_209 )
{
V_209 -> type = V_210 ;
V_209 -> V_211 = 1 ;
return 0 ;
}
static int F_103 ( struct V_97 * V_207 ,
struct V_212 * V_213 )
{
struct V_1 * V_2 = F_104 ( V_207 ) ;
F_52 ( & V_2 -> V_31 ) ;
V_213 -> V_214 . V_215 . V_163 [ 0 ] = ( V_2 -> V_185 >> 0 ) & 0xff ;
V_213 -> V_214 . V_215 . V_163 [ 1 ] = ( V_2 -> V_185 >> 8 ) & 0xff ;
V_213 -> V_214 . V_215 . V_163 [ 3 ] = V_216 ;
F_53 ( & V_2 -> V_31 ) ;
return 0 ;
}
static int F_105 ( struct V_97 * V_207 ,
struct V_212 * V_213 )
{
struct V_1 * V_2 = F_104 ( V_207 ) ;
unsigned int V_5 ;
int V_217 ;
V_5 = ( ( V_213 -> V_214 . V_215 . V_163 [ 0 ] & 0x3e ) << 0 ) |
( V_213 -> V_214 . V_215 . V_163 [ 1 ] << 8 ) ;
F_52 ( & V_2 -> V_31 ) ;
V_217 = V_2 -> V_185 != V_5 ;
V_2 -> V_185 = V_5 ;
if ( ( F_5 ( V_2 , V_183 ) & 1 ) && V_2 -> V_203 == NULL )
F_7 ( V_2 , V_186 , V_2 -> V_185 ) ;
F_53 ( & V_2 -> V_31 ) ;
return V_217 ;
}
static int F_106 ( struct V_97 * V_207 , struct V_208 * V_209 )
{
V_209 -> type = V_210 ;
V_209 -> V_211 = 1 ;
return 0 ;
}
static int F_107 ( struct V_97 * V_207 ,
struct V_212 * V_213 )
{
struct V_1 * V_2 = F_104 ( V_207 ) ;
F_52 ( & V_2 -> V_31 ) ;
V_213 -> V_214 . V_215 . V_163 [ 0 ] = 0x3e ;
V_213 -> V_214 . V_215 . V_163 [ 1 ] = 0xff ;
F_53 ( & V_2 -> V_31 ) ;
return 0 ;
}
static int F_108 ( struct V_97 * V_207 , struct V_208 * V_209 )
{
V_209 -> type = V_210 ;
V_209 -> V_211 = 1 ;
return 0 ;
}
static int F_109 ( struct V_97 * V_207 ,
struct V_212 * V_213 )
{
struct V_1 * V_2 = F_104 ( V_207 ) ;
F_52 ( & V_2 -> V_31 ) ;
V_213 -> V_214 . V_215 . V_163 [ 0 ] = ( V_2 -> V_184 >> 0 ) & 0xff ;
V_213 -> V_214 . V_215 . V_163 [ 1 ] = ( V_2 -> V_184 >> 8 ) & 0xff ;
V_213 -> V_214 . V_215 . V_163 [ 3 ] = V_216 ;
F_53 ( & V_2 -> V_31 ) ;
return 0 ;
}
static int F_110 ( struct V_97 * V_207 ,
struct V_212 * V_213 )
{
struct V_1 * V_2 = F_104 ( V_207 ) ;
unsigned int V_5 ;
int V_217 ;
V_5 = ( ( V_213 -> V_214 . V_215 . V_163 [ 0 ] & 0x3e ) << 0 ) |
( V_213 -> V_214 . V_215 . V_163 [ 1 ] << 8 ) ;
F_52 ( & V_2 -> V_31 ) ;
V_217 = V_2 -> V_184 != V_5 ;
V_2 -> V_184 = V_5 ;
if ( ( F_5 ( V_2 , V_183 ) & 2 ) )
F_7 ( V_2 , V_186 , V_2 -> V_184 ) ;
F_53 ( & V_2 -> V_31 ) ;
return V_217 ;
}
static int F_111 ( struct V_97 * V_207 , struct V_208 * V_218 )
{
static const char * const V_219 [ 3 ] = { L_6 , L_10 , L_11 } ;
return F_112 ( V_218 , 1 , 3 , V_219 ) ;
}
static int F_113 ( struct V_97 * V_207 , struct V_212 * V_214 )
{
struct V_1 * V_2 = F_104 ( V_207 ) ;
T_3 V_8 ;
F_52 ( & V_2 -> V_31 ) ;
V_8 = F_5 ( V_2 , V_220 ) ;
F_53 ( & V_2 -> V_31 ) ;
if ( ! ( V_8 & 0x100 ) )
V_214 -> V_214 . V_221 . V_222 [ 0 ] = 0 ;
else
V_214 -> V_214 . V_221 . V_222 [ 0 ] = 1 + ( ( V_8 & 0x200 ) != 0 ) ;
return 0 ;
}
static int F_114 ( struct V_97 * V_207 , struct V_212 * V_214 )
{
struct V_1 * V_2 = F_104 ( V_207 ) ;
T_3 V_8 , V_223 ;
F_52 ( & V_2 -> V_31 ) ;
V_223 = F_5 ( V_2 , V_220 ) ;
if ( V_214 -> V_214 . V_221 . V_222 [ 0 ] == 0 )
V_8 = V_223 & ~ 0x100 ;
else
V_8 = ( V_223 & ~ 0x300 ) | 0x100 | ( ( V_214 -> V_214 . V_221 . V_222 [ 0 ] == 2 ) << 9 ) ;
F_7 ( V_2 , V_220 , V_8 ) ;
F_53 ( & V_2 -> V_31 ) ;
return V_8 != V_223 ;
}
static int F_115 ( struct V_97 * V_207 ,
struct V_212 * V_213 )
{
struct V_1 * V_2 = F_104 ( V_207 ) ;
int V_8 = V_207 -> V_224 & 0xffff ;
unsigned int V_96 = ( V_207 -> V_224 >> 16 ) & 0xff ;
unsigned int V_225 = 1 ;
switch ( V_8 ) {
case V_183 : break;
case V_226 : break;
default: return - V_59 ;
}
V_213 -> V_214 . integer . V_214 [ 0 ] =
( F_9 ( V_2 , V_8 ) >> V_96 ) & V_225 ;
return 0 ;
}
static int F_116 ( struct V_97 * V_207 ,
struct V_212 * V_213 )
{
struct V_1 * V_2 = F_104 ( V_207 ) ;
int V_8 = V_207 -> V_224 & 0xffff ;
unsigned int V_96 = ( V_207 -> V_224 >> 16 ) & 0xff ;
unsigned int V_225 = 1 ;
int V_217 ;
unsigned int V_5 , V_227 ;
switch ( V_8 ) {
case V_183 : break;
case V_226 : break;
default: return - V_59 ;
}
V_5 = ( V_213 -> V_214 . integer . V_214 [ 0 ] & V_225 ) ;
V_5 <<= V_96 ;
F_52 ( & V_2 -> V_31 ) ;
V_227 = F_9 ( V_2 , V_8 ) ;
V_5 = ( V_227 & ~ ( V_225 << V_96 ) ) | V_5 ;
V_217 = V_5 != V_227 ;
F_11 ( V_2 , V_8 , V_5 ) ;
F_53 ( & V_2 -> V_31 ) ;
return V_217 ;
}
static int F_117 ( struct V_97 * V_207 , struct V_208 * V_209 )
{
unsigned int V_8 = V_207 -> V_224 ;
if ( V_8 < 0x80 || V_8 >= 0xc0 )
return - V_59 ;
V_209 -> type = V_228 ;
V_209 -> V_211 = 2 ;
V_209 -> V_214 . integer . V_229 = 0 ;
V_209 -> V_214 . integer . V_230 = 16383 ;
return 0 ;
}
static int F_118 ( struct V_97 * V_207 , struct V_212 * V_213 )
{
struct V_1 * V_2 = F_104 ( V_207 ) ;
unsigned int V_8 = V_207 -> V_224 ;
unsigned int V_231 = 0 , V_232 = 16 , V_225 = 16383 ;
unsigned int V_5 ;
if ( V_8 < 0x80 || V_8 >= 0xc0 )
return - V_59 ;
F_52 ( & V_2 -> V_31 ) ;
V_5 = F_9 ( V_2 , V_8 ) ;
F_53 ( & V_2 -> V_31 ) ;
V_213 -> V_214 . integer . V_214 [ 0 ] = ( V_5 >> V_231 ) & V_225 ;
V_213 -> V_214 . integer . V_214 [ 1 ] = ( V_5 >> V_232 ) & V_225 ;
return 0 ;
}
static int F_119 ( struct V_97 * V_207 , struct V_212 * V_213 )
{
struct V_1 * V_2 = F_104 ( V_207 ) ;
unsigned int V_8 = V_207 -> V_224 ;
unsigned int V_231 = 0 , V_232 = 16 , V_225 = 16383 ;
int V_217 ;
unsigned int V_233 , V_234 , V_227 ;
if ( V_8 < 0x80 || V_8 >= 0xc0 )
return - V_59 ;
V_233 = V_213 -> V_214 . integer . V_214 [ 0 ] & V_225 ;
V_234 = V_213 -> V_214 . integer . V_214 [ 1 ] & V_225 ;
V_233 <<= V_231 ;
V_234 <<= V_232 ;
F_52 ( & V_2 -> V_31 ) ;
V_227 = F_9 ( V_2 , V_8 ) ;
V_233 = ( V_227 & ~ ( ( V_225 << V_231 ) | ( V_225 << V_232 ) ) ) | V_233 | V_234 ;
V_217 = V_233 != V_227 ;
F_11 ( V_2 , V_8 , V_233 ) ;
F_53 ( & V_2 -> V_31 ) ;
return V_217 ;
}
static int F_120 ( struct V_97 * V_207 ,
struct V_212 * V_213 )
{
struct V_1 * V_2 = F_104 ( V_207 ) ;
unsigned int V_8 = V_235 ;
unsigned int V_236 = V_237 ;
int V_217 ;
unsigned int V_214 , V_227 ;
V_214 = V_213 -> V_214 . integer . V_214 [ 0 ] & 0x3fff ;
V_214 |= ( V_213 -> V_214 . integer . V_214 [ 1 ] & 0x3fff ) << 16 ;
F_52 ( & V_2 -> V_31 ) ;
V_227 = F_9 ( V_2 , V_8 ) ;
V_217 = V_214 != V_227 ;
F_11 ( V_2 , V_8 , V_214 ) ;
F_11 ( V_2 , V_236 , V_214 ) ;
F_53 ( & V_2 -> V_31 ) ;
return V_217 ;
}
static int F_121 ( struct V_97 * V_207 , struct V_212 * V_213 )
{
struct V_1 * V_2 = F_104 ( V_207 ) ;
V_213 -> V_214 . integer . V_214 [ 0 ] = V_2 -> V_182 ;
return 0 ;
}
static int F_122 ( struct V_97 * V_207 , struct V_212 * V_213 )
{
struct V_1 * V_2 = F_104 ( V_207 ) ;
int V_217 ;
V_217 = ( V_213 -> V_214 . integer . V_214 [ 0 ] != V_2 -> V_182 ) ;
if ( V_217 )
V_2 -> V_182 = ! ! V_213 -> V_214 . integer . V_214 [ 0 ] ;
return V_217 ;
}
static int F_123 ( struct V_1 * V_2 , int V_238 )
{
T_3 V_8 , V_164 ;
unsigned long V_30 ;
F_24 ( & V_2 -> V_31 , V_30 ) ;
V_8 = F_5 ( V_2 , V_239 ) ;
V_8 &= ~ ( 1 << ( V_238 + 8 ) ) ;
V_8 |= ( 1 << V_238 ) ;
F_7 ( V_2 , V_239 , V_8 ) ;
V_164 = F_5 ( V_2 , V_240 ) ;
V_164 &= ~ ( 3 << ( V_238 * 2 ) ) ;
F_7 ( V_2 , V_240 , V_164 ) ;
F_7 ( V_2 , V_239 , V_8 | ( 1 << ( V_238 + 8 ) ) ) ;
V_164 = F_5 ( V_2 , V_241 ) ;
F_25 ( & V_2 -> V_31 , V_30 ) ;
return ( V_164 >> V_238 ) & 1 ;
}
static int F_124 ( struct V_1 * V_2 , int V_238 , int V_242 )
{
T_3 V_8 ;
unsigned long V_30 ;
F_24 ( & V_2 -> V_31 , V_30 ) ;
V_8 = F_5 ( V_2 , V_239 ) ;
V_8 &= ~ ( 1 << V_238 ) ;
V_8 &= ~ ( 1 << ( V_238 + 8 ) ) ;
F_7 ( V_2 , V_239 , V_8 ) ;
F_7 ( V_2 , V_243 , V_242 << V_238 ) ;
F_7 ( V_2 , V_239 , V_8 | ( 1 << ( V_238 + 8 ) ) ) ;
F_25 ( & V_2 -> V_31 , V_30 ) ;
return 0 ;
}
static int F_125 ( struct V_97 * V_207 , struct V_212 * V_213 )
{
struct V_1 * V_2 = F_104 ( V_207 ) ;
int V_238 = ( int ) V_207 -> V_224 ;
V_213 -> V_214 . integer . V_214 [ 0 ] = F_123 ( V_2 , V_238 ) ;
return 0 ;
}
static int F_126 ( struct V_97 * V_207 , struct V_212 * V_213 )
{
struct V_1 * V_2 = F_104 ( V_207 ) ;
int V_238 = ( int ) V_207 -> V_224 ;
if ( F_123 ( V_2 , V_238 ) != V_213 -> V_214 . integer . V_214 [ 0 ] ) {
F_124 ( V_2 , V_238 , ! ! V_213 -> V_214 . integer . V_214 [ 0 ] ) ;
V_213 -> V_214 . integer . V_214 [ 0 ] = F_123 ( V_2 , V_238 ) ;
return 1 ;
}
return 0 ;
}
static int F_127 ( struct V_97 * V_207 ,
struct V_208 * V_209 )
{
V_209 -> type = V_228 ;
V_209 -> V_211 = 2 ;
V_209 -> V_214 . integer . V_229 = 0 ;
V_209 -> V_214 . integer . V_230 = 0x8000 ;
return 0 ;
}
static int F_128 ( struct V_97 * V_207 ,
struct V_212 * V_213 )
{
struct V_1 * V_2 = F_104 ( V_207 ) ;
unsigned int V_79 = V_207 -> V_113 . V_244 ;
V_213 -> V_214 . integer . V_214 [ 0 ] = V_2 -> V_83 [ V_79 ] . V_84 ;
V_213 -> V_214 . integer . V_214 [ 1 ] = V_2 -> V_83 [ V_79 ] . V_88 ;
return 0 ;
}
static int F_129 ( struct V_97 * V_207 ,
struct V_212 * V_213 )
{
struct V_1 * V_2 = F_104 ( V_207 ) ;
unsigned int V_79 = V_207 -> V_113 . V_244 ;
struct V_91 * V_70 ;
unsigned long V_30 ;
if ( V_213 -> V_214 . integer . V_214 [ 0 ] != V_2 -> V_83 [ V_79 ] . V_84 ||
V_213 -> V_214 . integer . V_214 [ 1 ] != V_2 -> V_83 [ V_79 ] . V_88 ) {
V_2 -> V_83 [ V_79 ] . V_84 = V_213 -> V_214 . integer . V_214 [ 0 ] ;
V_2 -> V_83 [ V_79 ] . V_88 = V_213 -> V_214 . integer . V_214 [ 1 ] ;
if ( V_2 -> V_83 [ V_79 ] . V_84 > 0x8000 )
V_2 -> V_83 [ V_79 ] . V_84 = 0x8000 ;
if ( V_2 -> V_83 [ V_79 ] . V_88 > 0x8000 )
V_2 -> V_83 [ V_79 ] . V_88 = 0x8000 ;
V_70 = (struct V_91 * ) V_207 -> V_224 ;
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
static void F_130 ( struct V_245 * V_246 )
{
struct V_1 * V_2 = V_246 -> V_17 ;
V_2 -> V_247 = NULL ;
}
static void F_131 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
V_2 -> V_16 = NULL ;
}
int F_132 ( struct V_1 * V_2 , int V_248 )
{
struct V_249 V_16 ;
struct V_97 * V_98 ;
struct V_91 * V_70 ;
unsigned int V_47 ;
int V_116 ;
static struct V_250 V_251 = {
. V_252 = F_18 ,
. V_253 = F_19 ,
} ;
if ( ( V_116 = V_245 ( V_2 -> V_12 , 0 , & V_251 , V_2 , & V_2 -> V_247 ) ) < 0 )
return V_116 ;
V_2 -> V_247 -> V_178 = F_130 ;
V_2 -> V_247 -> V_254 = 1 ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
V_16 . V_17 = V_2 ;
V_16 . V_178 = F_131 ;
if ( ( V_116 = F_133 ( V_2 -> V_247 , & V_16 , & V_2 -> V_16 ) ) < 0 )
return V_116 ;
F_134 ( V_2 -> V_16 , V_255 ,
V_256 | V_257 , 0 ) ;
for ( V_47 = 0 ; V_47 < F_135 ( V_258 ) ; V_47 ++ ) {
if ( ( V_116 = F_136 ( V_2 -> V_12 , F_137 ( & V_258 [ V_47 ] , V_2 ) ) ) < 0 )
return V_116 ;
}
if ( V_2 -> V_16 -> V_259 & V_260 ) {
V_98 = F_137 ( & V_261 , V_2 ) ;
V_116 = F_136 ( V_2 -> V_12 , V_98 ) ;
if ( V_116 < 0 )
return V_116 ;
}
if ( F_32 ( ! V_2 -> V_203 ) )
return - V_262 ;
if ( ( V_116 = F_136 ( V_2 -> V_12 , V_98 = F_137 ( & V_263 , V_2 ) ) ) < 0 )
return V_116 ;
V_98 -> V_113 . V_191 = V_2 -> V_203 -> V_191 ;
if ( ( V_116 = F_136 ( V_2 -> V_12 , V_98 = F_137 ( & V_264 , V_2 ) ) ) < 0 )
return V_116 ;
V_98 -> V_113 . V_191 = V_2 -> V_203 -> V_191 ;
if ( ( V_116 = F_136 ( V_2 -> V_12 , V_98 = F_137 ( & V_265 , V_2 ) ) ) < 0 )
return V_116 ;
V_98 -> V_113 . V_191 = V_2 -> V_203 -> V_191 ;
V_2 -> V_187 = V_98 ;
if ( V_2 -> V_23 == V_128 &&
( V_116 = F_136 ( V_2 -> V_12 , V_98 = F_137 ( & V_266 , V_2 ) ) ) < 0 )
return V_116 ;
if ( V_248 ) {
if ( ( V_116 = F_136 ( V_2 -> V_12 , F_137 ( & V_267 , V_2 ) ) ) < 0 )
return V_116 ;
}
V_70 = V_2 -> V_52 -> V_268 [ V_193 ] . V_70 ;
for ( V_47 = 0 ; V_47 < 32 ; ++ V_47 ) {
V_98 = F_137 ( & V_269 , V_2 ) ;
if ( ! V_98 )
return - V_57 ;
V_98 -> V_113 . V_191 = V_2 -> V_52 -> V_191 ;
V_98 -> V_113 . V_244 = V_47 ;
V_98 -> V_224 = ( unsigned long ) V_70 ;
if ( ( V_116 = F_136 ( V_2 -> V_12 , V_98 ) ) < 0 )
return V_116 ;
V_2 -> V_83 [ V_47 ] . V_84 = 0x8000 ;
V_2 -> V_83 [ V_47 ] . V_88 = 0x8000 ;
V_2 -> V_83 [ V_47 ] . V_106 = V_98 ;
V_70 = V_70 -> V_270 ;
}
return 0 ;
}
static int F_138 ( struct V_271 * V_168 )
{
struct V_1 * V_2 ;
unsigned long V_30 ;
unsigned int V_211 ;
V_2 = F_139 ( V_168 ) ;
F_24 ( & V_2 -> V_31 , V_30 ) ;
if ( V_168 -> V_272 > 1 ) {
V_2 -> V_169 = V_168 -> V_272 ;
V_211 = V_168 -> V_272 - 1 ;
} else {
V_2 -> V_169 = 2 ;
V_211 = 2 - 1 ;
}
F_7 ( V_2 , V_273 , V_211 ) ;
F_3 ( V_2 , V_274 , 0x03 ) ;
F_25 ( & V_2 -> V_31 , V_30 ) ;
return 0 ;
}
static int F_140 ( struct V_271 * V_168 )
{
struct V_1 * V_2 ;
unsigned long V_30 ;
V_2 = F_139 ( V_168 ) ;
F_24 ( & V_2 -> V_31 , V_30 ) ;
F_3 ( V_2 , V_274 , 0x00 ) ;
F_25 ( & V_2 -> V_31 , V_30 ) ;
return 0 ;
}
static int F_141 ( struct V_271 * V_168 ,
unsigned long * V_275 , unsigned long * V_276 )
{
* V_275 = 1 ;
* V_276 = 96000 ;
return 0 ;
}
int F_142 ( struct V_1 * V_2 , int V_191 )
{
struct V_271 * V_168 = NULL ;
struct V_277 V_278 ;
int V_116 ;
V_278 . V_279 = V_280 ;
V_278 . V_281 = V_282 ;
V_278 . V_12 = V_2 -> V_12 -> V_62 ;
V_278 . V_191 = V_191 ;
V_278 . V_244 = 0 ;
if ( ( V_116 = F_143 ( V_2 -> V_12 , L_2 , & V_278 , & V_168 ) ) >= 0 ) {
strcpy ( V_168 -> V_198 , L_12 ) ;
V_168 -> V_17 = V_2 ;
V_168 -> V_172 = V_283 ;
}
V_2 -> V_168 = V_168 ;
return V_116 ;
}
static void F_144 ( struct V_284 * V_285 ,
struct V_286 * V_287 )
{
struct V_1 * V_2 = V_285 -> V_17 ;
int V_26 ;
F_145 ( V_287 , L_13 ) ;
for ( V_26 = 0 ; V_26 <= V_288 ; V_26 += 4 )
F_145 ( V_287 , L_14 , V_26 , F_9 ( V_2 , V_26 ) ) ;
}
static int F_146 ( struct V_289 * V_12 , struct V_1 * V_2 )
{
struct V_284 * V_285 ;
if ( ! F_147 ( V_12 , L_15 , & V_285 ) )
F_148 ( V_285 , V_2 , F_144 ) ;
return 0 ;
}
static void F_149 ( struct V_290 * V_143 )
{
T_1 V_18 ;
F_150 ( V_143 , V_291 , & V_18 ) ;
#if 0
if (cmd & 0x03) {
#endif
F_151 ( V_143 , V_291 , V_18 & 0xfc ) ;
F_151 ( V_143 , V_291 , V_18 | 0x03 ) ;
F_151 ( V_143 , V_291 , V_18 & 0xfc ) ;
F_152 ( V_143 , V_292 , 0 ) ;
F_152 ( V_143 , V_293 , 0 ) ;
#if 0
}
#endif
}
static void F_153 ( struct V_1 * V_2 )
{
F_11 ( V_2 , V_294 , 0x00000001 ) ;
}
static void F_154 ( struct V_1 * V_2 )
{
T_2 V_5 ;
int V_37 = 1000 ;
V_5 = F_9 ( V_2 , V_294 ) ;
if ( V_5 )
F_11 ( V_2 , V_294 , 0x00000000 ) ;
while ( V_37 -- > 0 ) {
V_5 = F_9 ( V_2 , V_38 ) ;
if ( ( V_5 & 0x00000002 ) == 0 )
break;
}
}
static int F_155 ( struct V_1 * V_2 )
{
int V_116 , V_295 ;
const char * V_198 ;
V_116 = F_156 ( & V_2 -> V_296 , L_16 ,
& V_2 -> V_143 -> V_13 ) ;
if ( V_116 >= 0 ) {
if ( V_2 -> V_296 -> V_297 != V_298 ) {
F_17 ( V_2 -> V_12 -> V_13 ,
L_17 ) ;
V_116 = - V_59 ;
}
}
if ( V_116 < 0 )
return V_116 ;
V_295 = V_2 -> V_23 == V_299 ||
V_2 -> V_23 == V_300 ||
V_2 -> V_23 == V_24 ||
V_2 -> V_23 == V_128 ;
V_198 = V_295 ? L_18 : L_19 ;
V_116 = F_156 ( & V_2 -> V_301 , V_198 ,
& V_2 -> V_143 -> V_13 ) ;
if ( V_116 >= 0 ) {
if ( V_2 -> V_301 -> V_297 != V_302 ) {
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
T_3 V_303 ;
const T_7 * V_304 ;
F_11 ( V_2 , V_235 , 0x00000000 ) ;
F_154 ( V_2 ) ;
F_11 ( V_2 , V_34 , 0x00010000 ) ;
F_11 ( V_2 , V_34 , 0x00000000 ) ;
F_11 ( V_2 , V_115 , 0x00000000 ) ;
F_11 ( V_2 , V_147 , 0x00000000 ) ;
F_11 ( V_2 , V_305 , 0x00000000 ) ;
F_11 ( V_2 , V_306 , 0x00000000 ) ;
F_11 ( V_2 , V_307 , 0x00000000 ) ;
V_303 = F_5 ( V_2 , V_220 ) ;
F_7 ( V_2 , V_220 , V_303 & ~ 0x0007 ) ;
V_304 = ( const T_7 * ) V_2 -> V_296 -> V_308 ;
for ( V_26 = 0 ; V_26 < V_298 / 4 ; V_26 ++ )
F_11 ( V_2 , V_309 + ( V_26 << 2 ) ,
F_36 ( V_304 [ V_26 ] ) ) ;
V_304 = ( const T_7 * ) V_2 -> V_301 -> V_308 ;
for ( V_26 = 0 ; V_26 < V_302 / 4 ; V_26 ++ )
F_11 ( V_2 , V_310 + ( V_26 << 2 ) ,
F_36 ( V_304 [ V_26 ] ) ) ;
F_153 ( V_2 ) ;
}
static int F_158 ( struct V_1 * V_2 )
{
long V_297 , V_311 ;
int V_45 , V_72 , V_8 ;
T_1 * V_312 ;
T_8 V_313 ;
V_311 = 4 + 4 * V_48 ;
V_2 -> V_314 = F_9 ( V_2 , V_315 ) << 2 ;
V_2 -> V_316 = F_9 ( V_2 , V_317 ) << 2 ;
V_2 -> V_318 = F_9 ( V_2 , V_319 ) << 2 ;
V_2 -> V_320 = V_321 ;
V_297 = F_159 ( V_311 , 0x100 ) +
F_159 ( V_2 -> V_314 * 2 * V_48 , 0x100 ) +
F_159 ( V_2 -> V_316 * 2 * V_165 , 0x100 ) +
F_159 ( V_2 -> V_318 * 2 * V_322 , 0x100 ) +
V_2 -> V_320 ;
if ( F_50 ( V_142 , F_51 ( V_2 -> V_143 ) ,
V_297 , & V_2 -> V_323 ) < 0 )
return - V_57 ;
V_312 = V_2 -> V_323 . V_148 ;
V_313 = V_2 -> V_323 . V_146 ;
memset ( V_312 , 0 , V_297 ) ;
V_2 -> V_324 = V_312 ;
V_2 -> V_325 = V_313 ;
V_2 -> V_103 = ( T_2 * ) V_312 ;
V_2 -> V_103 [ 0 ] = F_40 ( V_48 ) ;
V_312 += F_159 ( V_311 , 0x100 ) ;
V_313 += F_159 ( V_311 , 0x100 ) ;
for ( V_45 = 0 ; V_45 < V_48 ; V_45 ++ ) {
V_2 -> V_49 [ V_45 ] . V_62 = V_45 ;
V_2 -> V_49 [ V_45 ] . V_72 = (struct V_81 * ) V_312 ;
V_2 -> V_49 [ V_45 ] . V_104 = V_313 ;
for ( V_72 = 0 ; V_72 < 2 ; V_72 ++ ) {
V_2 -> V_326 [ V_45 ] [ V_72 ] = (struct V_81 * ) V_312 ;
V_312 += V_2 -> V_314 ;
V_313 += V_2 -> V_314 ;
}
}
V_312 = ( char * ) F_159 ( ( unsigned long ) V_312 , 0x100 ) ;
V_313 = F_159 ( V_313 , 0x100 ) ;
V_2 -> V_327 = V_312 ;
V_2 -> V_328 = V_313 ;
for ( V_45 = 0 ; V_45 < V_165 ; V_45 ++ )
for ( V_72 = 0 ; V_72 < 2 ; V_72 ++ ) {
V_2 -> V_94 [ V_45 ] [ V_72 ] = (struct V_152 * ) V_312 ;
V_312 += V_2 -> V_316 ;
V_313 += V_2 -> V_316 ;
}
V_312 = ( char * ) F_159 ( ( unsigned long ) V_312 , 0x100 ) ;
V_313 = F_159 ( V_313 , 0x100 ) ;
V_2 -> V_329 = V_312 ;
V_2 -> V_330 = V_313 ;
for ( V_45 = 0 ; V_45 < V_322 ; V_45 ++ )
for ( V_72 = 0 ; V_72 < 2 ; V_72 ++ ) {
V_2 -> V_145 [ V_45 ] [ V_72 ] = (struct V_331 * ) V_312 ;
V_312 += V_2 -> V_318 ;
V_313 += V_2 -> V_318 ;
}
V_312 = ( char * ) F_159 ( ( unsigned long ) V_312 , 0x100 ) ;
V_313 = F_159 ( V_313 , 0x100 ) ;
V_2 -> V_332 = V_312 ;
V_2 -> V_333 = V_313 ;
F_32 ( V_312 + V_2 -> V_320 !=
V_2 -> V_323 . V_148 + V_2 -> V_323 . V_334 ) ;
F_11 ( V_2 , V_305 , V_2 -> V_325 ) ;
F_11 ( V_2 , V_306 , V_2 -> V_328 ) ;
F_11 ( V_2 , V_307 , V_2 -> V_330 ) ;
F_11 ( V_2 , V_288 , V_2 -> V_333 ) ;
F_11 ( V_2 , V_335 , V_2 -> V_320 >> 2 ) ;
V_2 -> V_185 = V_2 -> V_184 = V_336 & 0xffff ;
F_7 ( V_2 , V_183 , 0 ) ;
F_7 ( V_2 , V_186 , V_2 -> V_185 ) ;
F_7 ( V_2 , V_226 , 0 ) ;
for ( V_8 = 0x80 ; V_8 < 0xc0 ; V_8 += 4 )
F_11 ( V_2 , V_8 , 0 ) ;
F_11 ( V_2 , V_235 , 0x3fff3fff ) ;
F_11 ( V_2 , V_237 , 0x3fff3fff ) ;
F_11 ( V_2 , V_337 , 0x3fff3fff ) ;
F_11 ( V_2 , V_338 , 0x3fff3fff ) ;
F_11 ( V_2 , V_339 , 0x3fff3fff ) ;
F_11 ( V_2 , V_340 , 0x3fff3fff ) ;
F_11 ( V_2 , V_341 , 0x3fff3fff ) ;
F_11 ( V_2 , V_342 , 0x3fff3fff ) ;
return 0 ;
}
static int F_160 ( struct V_1 * V_2 )
{
T_3 V_303 ;
if ( F_32 ( ! V_2 ) )
return - V_59 ;
if ( V_2 -> V_343 ) {
F_11 ( V_2 , V_235 , 0 ) ;
F_11 ( V_2 , V_237 , 0 ) ;
F_11 ( V_2 , V_342 , 0 ) ;
F_11 ( V_2 , V_38 , ~ 0 ) ;
F_154 ( V_2 ) ;
F_11 ( V_2 , V_305 , 0 ) ;
F_11 ( V_2 , V_306 , 0 ) ;
F_11 ( V_2 , V_307 , 0 ) ;
F_11 ( V_2 , V_288 , 0 ) ;
F_11 ( V_2 , V_335 , 0 ) ;
V_303 = F_5 ( V_2 , V_220 ) ;
F_7 ( V_2 , V_220 , V_303 & ~ 0x0007 ) ;
}
F_54 ( V_2 ) ;
#if 0
pci_set_power_state(chip->pci, PCI_D3hot);
#endif
#ifdef F_161
F_77 ( V_2 -> V_344 ) ;
#endif
if ( V_2 -> V_161 >= 0 )
F_162 ( V_2 -> V_161 , V_2 ) ;
F_163 ( V_2 -> V_345 ) ;
F_163 ( V_2 -> V_346 ) ;
F_164 ( V_2 ) ;
F_165 ( V_2 -> V_4 ) ;
if ( V_2 -> V_323 . V_148 )
F_55 ( & V_2 -> V_323 ) ;
F_163 ( V_2 -> V_343 ) ;
F_152 ( V_2 -> V_143 , 0x40 , V_2 -> V_347 ) ;
F_166 ( V_2 -> V_143 ) ;
F_167 ( V_2 -> V_296 ) ;
F_167 ( V_2 -> V_301 ) ;
F_77 ( V_2 ) ;
return 0 ;
}
static int F_168 ( struct V_348 * V_191 )
{
struct V_1 * V_2 = V_191 -> V_349 ;
return F_160 ( V_2 ) ;
}
static int F_169 ( struct V_191 * V_13 )
{
struct V_289 * V_12 = F_170 ( V_13 ) ;
struct V_1 * V_2 = V_12 -> V_17 ;
unsigned int V_26 ;
F_171 ( V_12 , V_350 ) ;
F_172 ( V_2 -> V_52 ) ;
F_172 ( V_2 -> V_201 ) ;
F_172 ( V_2 -> V_203 ) ;
F_172 ( V_2 -> V_205 ) ;
F_173 ( V_2 -> V_16 ) ;
for ( V_26 = 0 ; V_26 < V_351 ; V_26 ++ )
V_2 -> V_344 [ V_26 ] = F_9 ( V_2 , V_352 [ V_26 ] ) ;
V_2 -> V_353 = F_9 ( V_2 , V_34 ) ;
F_174 ( V_2 -> V_143 , V_354 ,
& V_2 -> V_355 ) ;
F_174 ( V_2 -> V_143 , V_356 ,
& V_2 -> V_357 ) ;
F_11 ( V_2 , V_235 , 0 ) ;
F_11 ( V_2 , V_237 , 0 ) ;
F_154 ( V_2 ) ;
return 0 ;
}
static int F_175 ( struct V_191 * V_13 )
{
struct V_290 * V_143 = F_176 ( V_13 ) ;
struct V_289 * V_12 = F_170 ( V_13 ) ;
struct V_1 * V_2 = V_12 -> V_17 ;
unsigned int V_26 ;
F_149 ( V_143 ) ;
F_13 ( V_2 , 0 ) ;
F_157 ( V_2 ) ;
F_177 ( 100 ) ;
for ( V_26 = 0 ; V_26 < V_351 ; V_26 ++ )
F_11 ( V_2 , V_352 [ V_26 ] , V_2 -> V_344 [ V_26 ] ) ;
F_178 ( V_2 -> V_16 ) ;
F_152 ( V_2 -> V_143 , V_354 ,
V_2 -> V_355 ) ;
F_152 ( V_2 -> V_143 , V_356 ,
V_2 -> V_357 ) ;
if ( V_2 -> V_32 > 0 ) {
F_52 ( & V_2 -> V_31 ) ;
F_11 ( V_2 , V_34 , V_2 -> V_353 ) ;
V_2 -> V_35 = F_9 ( V_2 , V_36 ) ;
F_53 ( & V_2 -> V_31 ) ;
}
F_171 ( V_12 , V_358 ) ;
return 0 ;
}
int F_179 ( struct V_289 * V_12 ,
struct V_290 * V_143 ,
unsigned short V_347 ,
struct V_1 * * V_359 )
{
struct V_1 * V_2 ;
int V_116 ;
static struct V_360 V_251 = {
. V_361 = F_168 ,
} ;
* V_359 = NULL ;
if ( ( V_116 = F_180 ( V_143 ) ) < 0 )
return V_116 ;
V_2 = F_81 ( sizeof( * V_2 ) , V_176 ) ;
if ( V_2 == NULL ) {
F_166 ( V_143 ) ;
return - V_57 ;
}
V_2 -> V_347 = V_347 ;
F_181 ( & V_2 -> V_31 ) ;
F_181 ( & V_2 -> V_60 ) ;
F_182 ( & V_2 -> V_40 ) ;
F_28 ( & V_2 -> V_39 , 0 ) ;
V_2 -> V_12 = V_12 ;
V_2 -> V_143 = V_143 ;
V_2 -> V_161 = - 1 ;
V_2 -> V_23 = V_143 -> V_191 ;
V_2 -> V_25 = V_143 -> V_362 ;
V_2 -> V_363 = F_183 ( V_143 , 0 ) ;
V_2 -> V_4 = F_184 ( V_2 -> V_363 , 0x8000 ) ;
F_185 ( V_143 ) ;
V_2 -> V_63 = - 1 ;
if ( ( V_2 -> V_343 = F_186 ( V_2 -> V_363 , 0x8000 , L_2 ) ) == NULL ) {
F_17 ( V_2 -> V_12 -> V_13 ,
L_21 ,
V_2 -> V_363 , V_2 -> V_363 + 0x8000 - 1 ) ;
V_116 = - V_14 ;
goto V_364;
}
if ( F_187 ( V_143 -> V_161 , F_73 , V_365 ,
V_366 , V_2 ) ) {
F_17 ( V_2 -> V_12 -> V_13 , L_22 , V_143 -> V_161 ) ;
V_116 = - V_14 ;
goto V_364;
}
V_2 -> V_161 = V_143 -> V_161 ;
F_149 ( V_143 ) ;
if ( F_13 ( V_2 , 0 ) < 0 ) {
V_116 = - V_367 ;
goto V_364;
}
V_116 = F_155 ( V_2 ) ;
if ( V_116 < 0 ) {
F_17 ( V_2 -> V_12 -> V_13 , L_23 , V_116 ) ;
goto V_364;
}
F_157 ( V_2 ) ;
F_177 ( 100 ) ;
if ( F_158 ( V_2 ) < 0 ) {
V_116 = - V_367 ;
goto V_364;
}
V_116 = F_49 ( V_2 ) ;
if ( V_116 < 0 )
goto V_364;
#ifdef F_161
V_2 -> V_344 = F_188 ( V_351 * sizeof( T_2 ) ,
V_176 ) ;
if ( V_2 -> V_344 == NULL ) {
V_116 = - V_57 ;
goto V_364;
}
#endif
V_116 = F_189 ( V_12 , V_368 , V_2 , & V_251 ) ;
if ( V_116 < 0 )
goto V_364;
F_146 ( V_12 , V_2 ) ;
* V_359 = V_2 ;
return 0 ;
V_364:
F_160 ( V_2 ) ;
return V_116 ;
}
