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
F_17 ( V_12 L_1 , V_6 , F_5 ( V_2 , V_8 ) ) ;
return - V_13 ;
}
static void F_18 ( struct V_14 * V_15 , T_3 V_8 , T_3 V_5 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
T_2 V_17 ;
F_13 ( V_2 , 0 ) ;
V_17 = ( ( V_18 | V_8 ) << 16 ) | V_5 ;
F_11 ( V_2 , V_19 , V_17 ) ;
}
static T_3 F_19 ( struct V_14 * V_15 , T_3 V_8 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
if ( F_13 ( V_2 , 0 ) )
return ~ 0 ;
F_7 ( V_2 , V_20 , V_21 | V_8 ) ;
if ( F_13 ( V_2 , 0 ) )
return ~ 0 ;
if ( V_2 -> V_22 == V_23 && V_2 -> V_24 < 2 ) {
int V_25 ;
for ( V_25 = 0 ; V_25 < 600 ; V_25 ++ )
F_5 ( V_2 , V_26 ) ;
}
return F_5 ( V_2 , V_26 ) ;
}
static T_2 F_20 ( T_2 V_27 )
{
switch ( V_27 ) {
case 8000 : return 0x02aaab00 ;
case 11025 : return 0x03accd00 ;
case 16000 : return 0x05555500 ;
case 22050 : return 0x07599a00 ;
case 32000 : return 0x0aaaab00 ;
case 44100 : return 0x0eb33300 ;
default: return ( ( V_27 << 16 ) / 375 ) << 5 ;
}
}
static T_2 F_21 ( T_2 V_27 )
{
T_2 V_25 ;
static T_2 V_5 [ 8 ] = {
0x00570000 , 0x06AA0000 , 0x18B20000 , 0x20930000 ,
0x2B9A0000 , 0x35A10000 , 0x3EAA0000 , 0x40000000
} ;
if ( V_27 == 44100 )
return 0x40000000 ;
for ( V_25 = 0 ; V_25 < 8 ; V_25 ++ )
if ( V_27 <= V_28 [ V_25 ] )
return V_5 [ V_25 ] ;
return V_5 [ 0 ] ;
}
static T_2 F_22 ( T_2 V_27 )
{
T_2 V_25 ;
static T_2 V_5 [ 8 ] = {
0x35280000 , 0x34A70000 , 0x32020000 , 0x31770000 ,
0x31390000 , 0x31C90000 , 0x33D00000 , 0x40000000
} ;
if ( V_27 == 44100 )
return 0x370A0000 ;
for ( V_25 = 0 ; V_25 < 8 ; V_25 ++ )
if ( V_27 <= V_28 [ V_25 ] )
return V_5 [ V_25 ] ;
return V_5 [ 0 ] ;
}
static void F_23 ( struct V_1 * V_2 )
{
unsigned long V_29 ;
F_24 ( & V_2 -> V_30 , V_29 ) ;
if ( V_2 -> V_31 ++ > 0 )
goto V_32;
F_11 ( V_2 , V_33 ,
F_9 ( V_2 , V_33 ) | 3 ) ;
V_2 -> V_34 = F_9 ( V_2 , V_35 ) & 1 ;
V_32:
F_25 ( & V_2 -> V_30 , V_29 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
unsigned long V_29 ;
long V_36 = 1000 ;
F_24 ( & V_2 -> V_30 , V_29 ) ;
if ( -- V_2 -> V_31 > 0 )
goto V_32;
F_11 ( V_2 , V_33 ,
F_9 ( V_2 , V_33 ) & ~ 3 ) ;
while ( V_36 -- > 0 ) {
if ( ( F_9 ( V_2 , V_37 ) & 2 ) == 0 )
break;
}
if ( F_27 ( & V_2 -> V_38 ) ) {
F_28 ( & V_2 -> V_38 , 0 ) ;
F_29 ( & V_2 -> V_39 ) ;
}
V_32:
F_25 ( & V_2 -> V_30 , V_29 ) ;
}
static int F_30 ( struct V_1 * V_2 ,
enum V_40 type , int V_41 ,
struct V_42 * * V_43 )
{
struct V_42 * V_44 , * V_45 ;
int V_46 ;
* V_43 = NULL ;
for ( V_46 = 0 ; V_46 < V_47 ; V_46 += V_41 ? 2 : 1 ) {
V_44 = & V_2 -> V_48 [ V_46 ] ;
V_45 = V_41 ? & V_2 -> V_48 [ V_46 + 1 ] : NULL ;
if ( V_44 -> V_49 || ( V_45 && V_45 -> V_49 ) )
continue;
V_44 -> V_49 = 1 ;
if ( V_45 )
V_45 -> V_49 = 1 ;
switch ( type ) {
case V_50 :
V_44 -> V_51 = 1 ;
if ( V_45 )
V_45 -> V_51 = 1 ;
break;
case V_52 :
V_44 -> V_53 = 1 ;
break;
case V_54 :
V_44 -> V_55 = 1 ;
break;
}
F_23 ( V_2 ) ;
if ( V_45 )
F_23 ( V_2 ) ;
* V_43 = V_44 ;
return 0 ;
}
return - V_56 ;
}
static int F_31 ( struct V_1 * V_2 ,
enum V_40 type , int V_41 ,
struct V_42 * * V_43 )
{
unsigned long V_29 ;
int V_57 ;
if ( F_32 ( ! V_43 ) )
return - V_58 ;
if ( F_32 ( V_41 && type != V_50 ) )
return - V_58 ;
F_24 ( & V_2 -> V_59 , V_29 ) ;
for (; ; ) {
V_57 = F_30 ( V_2 , type , V_41 , V_43 ) ;
if ( V_57 == 0 || type != V_50 )
break;
break;
}
F_25 ( & V_2 -> V_59 , V_29 ) ;
return V_57 ;
}
static int F_33 ( struct V_1 * V_2 , struct V_42 * V_60 )
{
unsigned long V_29 ;
if ( F_32 ( ! V_60 ) )
return - V_58 ;
F_26 ( V_2 ) ;
F_24 ( & V_2 -> V_59 , V_29 ) ;
if ( V_60 -> V_61 == V_2 -> V_62 ) {
V_2 -> V_62 = - 1 ;
V_60 -> V_63 -> V_64 = 0 ;
}
V_60 -> V_49 = V_60 -> V_51 = V_60 -> V_53 = V_60 -> V_55 = 0 ;
V_60 -> V_63 = NULL ;
V_60 -> V_65 = NULL ;
F_25 ( & V_2 -> V_59 , V_29 ) ;
return 0 ;
}
static void F_34 ( struct V_1 * V_2 , struct V_42 * V_44 )
{
struct V_66 * V_63 ;
T_2 V_67 , V_68 ;
if ( ( V_63 = V_44 -> V_63 ) == NULL )
return;
if ( V_63 -> V_69 == NULL )
return;
F_35 ( & V_2 -> V_30 ) ;
if ( V_63 -> V_70 ) {
V_67 = F_36 ( V_44 -> V_71 [ V_2 -> V_34 ] . V_72 ) ;
if ( V_67 < V_63 -> V_73 )
V_68 = V_67 + ( V_63 -> V_74 - V_63 -> V_73 ) ;
else
V_68 = V_67 - V_63 -> V_73 ;
V_63 -> V_75 += V_68 ;
V_63 -> V_73 = V_67 ;
if ( V_63 -> V_75 >= V_63 -> V_76 ) {
V_63 -> V_75 %= V_63 -> V_76 ;
F_37 ( & V_2 -> V_30 ) ;
F_38 ( V_63 -> V_69 ) ;
F_35 ( & V_2 -> V_30 ) ;
}
if ( F_39 ( V_63 -> V_77 ) ) {
unsigned int V_78 = V_63 -> V_69 -> V_61 ;
unsigned int V_79 = 1 - V_2 -> V_34 ;
struct V_80 * V_71 ;
T_2 V_81 ;
V_71 = & V_44 -> V_71 [ V_79 ] ;
V_81 = F_40 ( V_2 -> V_82 [ V_78 ] . V_83 << 15 ) ;
V_71 -> V_84 = V_81 ;
if ( V_63 -> V_85 )
V_71 -> V_86 = V_81 ;
if ( V_63 -> V_48 [ 1 ] )
V_71 = & V_63 -> V_48 [ 1 ] -> V_71 [ V_79 ] ;
V_81 = F_40 ( V_2 -> V_82 [ V_78 ] . V_87 << 15 ) ;
V_71 -> V_88 = V_81 ;
if ( V_63 -> V_85 )
V_71 -> V_89 = V_81 ;
V_63 -> V_77 -- ;
}
}
F_37 ( & V_2 -> V_30 ) ;
}
static void F_41 ( struct V_90 * V_69 )
{
struct V_91 * V_92 = V_69 -> V_92 ;
struct V_66 * V_63 = V_92 -> V_16 ;
struct V_1 * V_2 = V_63 -> V_2 ;
T_2 V_67 , V_68 ;
F_35 ( & V_2 -> V_30 ) ;
if ( V_63 -> V_70 ) {
V_67 = F_36 ( V_2 -> V_93 [ V_63 -> V_94 ] [ V_2 -> V_34 ] -> V_72 ) >> V_63 -> V_95 ;
if ( V_67 < V_63 -> V_73 )
V_68 = V_67 + ( V_63 -> V_74 - V_63 -> V_73 ) ;
else
V_68 = V_67 - V_63 -> V_73 ;
V_63 -> V_75 += V_68 ;
V_63 -> V_73 = V_67 ;
if ( V_63 -> V_75 >= V_63 -> V_76 ) {
V_63 -> V_75 %= V_63 -> V_76 ;
F_37 ( & V_2 -> V_30 ) ;
F_38 ( V_69 ) ;
F_35 ( & V_2 -> V_30 ) ;
}
}
F_37 ( & V_2 -> V_30 ) ;
}
static int F_42 ( struct V_90 * V_69 ,
int V_17 )
{
struct V_1 * V_2 = F_43 ( V_69 ) ;
struct V_66 * V_63 = V_69 -> V_92 -> V_16 ;
struct V_96 * V_97 = NULL ;
int V_57 = 0 ;
F_35 ( & V_2 -> V_30 ) ;
if ( V_63 -> V_48 [ 0 ] == NULL ) {
V_57 = - V_58 ;
goto V_98;
}
switch ( V_17 ) {
case V_99 :
case V_100 :
case V_101 :
V_2 -> V_102 [ V_63 -> V_48 [ 0 ] -> V_61 + 1 ] = F_40 ( V_63 -> V_48 [ 0 ] -> V_103 ) ;
if ( V_63 -> V_48 [ 1 ] != NULL && ! V_63 -> V_64 )
V_2 -> V_102 [ V_63 -> V_48 [ 1 ] -> V_61 + 1 ] = F_40 ( V_63 -> V_48 [ 1 ] -> V_103 ) ;
V_63 -> V_70 = 1 ;
break;
case V_104 :
if ( V_69 -> V_51 == V_2 -> V_51 && ! V_63 -> V_64 ) {
V_97 = V_2 -> V_82 [ V_69 -> V_61 ] . V_105 ;
V_97 -> V_106 [ 0 ] . V_107 |= V_108 ;
}
case V_109 :
case V_110 :
V_2 -> V_102 [ V_63 -> V_48 [ 0 ] -> V_61 + 1 ] = 0 ;
if ( V_63 -> V_48 [ 1 ] != NULL && ! V_63 -> V_64 )
V_2 -> V_102 [ V_63 -> V_48 [ 1 ] -> V_61 + 1 ] = 0 ;
V_63 -> V_70 = 0 ;
break;
default:
V_57 = - V_58 ;
break;
}
V_98:
F_37 ( & V_2 -> V_30 ) ;
if ( V_97 )
F_44 ( V_2 -> V_111 , V_112 , & V_97 -> V_113 ) ;
return V_57 ;
}
static int F_45 ( struct V_90 * V_69 ,
int V_17 )
{
struct V_1 * V_2 = F_43 ( V_69 ) ;
struct V_66 * V_63 = V_69 -> V_92 -> V_16 ;
int V_57 = 0 ;
T_2 V_114 ;
F_35 ( & V_2 -> V_30 ) ;
switch ( V_17 ) {
case V_99 :
case V_100 :
case V_101 :
V_114 = F_9 ( V_2 , V_115 ) | ( 1 << V_63 -> V_94 ) ;
F_11 ( V_2 , V_115 , V_114 ) ;
V_63 -> V_70 = 1 ;
break;
case V_104 :
case V_109 :
case V_110 :
V_114 = F_9 ( V_2 , V_115 ) & ~ ( 1 << V_63 -> V_94 ) ;
F_11 ( V_2 , V_115 , V_114 ) ;
V_63 -> V_70 = 0 ;
break;
default:
V_57 = - V_58 ;
break;
}
F_37 ( & V_2 -> V_30 ) ;
return V_57 ;
}
static int F_46 ( struct V_66 * V_63 , int V_48 )
{
int V_116 ;
if ( V_63 -> V_48 [ 1 ] != NULL && V_48 < 2 ) {
F_33 ( V_63 -> V_2 , V_63 -> V_48 [ 1 ] ) ;
V_63 -> V_48 [ 1 ] = NULL ;
}
if ( V_48 == 1 && V_63 -> V_48 [ 0 ] != NULL )
return 0 ;
if ( V_48 == 2 && V_63 -> V_48 [ 0 ] != NULL && V_63 -> V_48 [ 1 ] != NULL )
return 0 ;
if ( V_48 > 1 ) {
if ( V_63 -> V_48 [ 0 ] != NULL && V_63 -> V_48 [ 1 ] == NULL ) {
F_33 ( V_63 -> V_2 , V_63 -> V_48 [ 0 ] ) ;
V_63 -> V_48 [ 0 ] = NULL ;
}
}
V_116 = F_31 ( V_63 -> V_2 , V_50 , V_48 > 1 , & V_63 -> V_48 [ 0 ] ) ;
if ( V_116 < 0 )
return V_116 ;
V_63 -> V_48 [ 0 ] -> V_63 = V_63 ;
V_63 -> V_48 [ 0 ] -> V_65 = F_34 ;
if ( V_48 > 1 ) {
V_63 -> V_48 [ 1 ] = & V_63 -> V_2 -> V_48 [ V_63 -> V_48 [ 0 ] -> V_61 + 1 ] ;
V_63 -> V_48 [ 1 ] -> V_63 = V_63 ;
}
return 0 ;
}
static void F_47 ( struct V_66 * V_63 , unsigned int V_117 ,
struct V_91 * V_92 ,
int V_118 )
{
struct V_42 * V_44 = V_63 -> V_48 [ V_117 ] ;
T_2 V_119 ;
T_2 V_68 = F_20 ( V_92 -> V_27 ) ;
T_2 V_120 = F_22 ( V_92 -> V_27 ) ;
T_2 V_121 = F_21 ( V_92 -> V_27 ) ;
struct V_80 * V_71 ;
unsigned int V_122 ;
T_2 V_123 , V_124 ;
T_1 V_125 , V_126 ;
unsigned long V_29 ;
if ( F_32 ( ! V_44 ) )
return;
if ( V_92 -> V_127 == 1 ) {
V_125 = 1 ;
V_126 = 1 ;
} else {
V_125 = ( V_117 & 1 ) == 0 ;
V_126 = ! V_125 ;
}
if ( V_118 ) {
V_123 = F_40 ( V_63 -> V_2 -> V_82
[ V_63 -> V_69 -> V_61 ] . V_83 << 15 ) ;
V_124 = F_40 ( V_63 -> V_2 -> V_82
[ V_63 -> V_69 -> V_61 ] . V_87 << 15 ) ;
} else {
V_123 = F_40 ( 0x40000000 ) ;
V_124 = F_40 ( 0x40000000 ) ;
}
F_24 ( & V_63 -> V_2 -> V_59 , V_29 ) ;
V_119 = V_92 -> V_127 == 2 ? 0x00010000 : 0 ;
if ( F_48 ( V_92 -> V_119 ) == 8 )
V_119 |= 0x80000000 ;
else if ( V_63 -> V_2 -> V_22 == V_128 &&
V_92 -> V_27 == 44100 && V_92 -> V_127 == 2 &&
V_117 == 0 && ( V_63 -> V_2 -> V_62 == - 1 ||
V_63 -> V_2 -> V_62 == V_44 -> V_61 ) ) {
V_63 -> V_2 -> V_62 = V_44 -> V_61 ;
V_63 -> V_64 = 1 ;
V_119 |= 0x10000000 ;
}
if ( V_63 -> V_2 -> V_62 == V_44 -> V_61 &&
( V_119 & 0x10000000 ) == 0 ) {
V_63 -> V_2 -> V_62 = - 1 ;
V_63 -> V_64 = 0 ;
}
if ( V_92 -> V_127 == 2 && ( V_117 & 1 ) != 0 )
V_119 |= 1 ;
F_25 ( & V_63 -> V_2 -> V_59 , V_29 ) ;
for ( V_122 = 0 ; V_122 < 2 ; V_122 ++ ) {
V_71 = & V_44 -> V_71 [ V_122 ] ;
memset ( V_71 , 0 , sizeof( * V_71 ) ) ;
V_71 -> V_119 = F_40 ( V_119 ) ;
V_71 -> V_129 = F_40 ( V_92 -> V_130 ) ;
V_71 -> V_131 = F_40 ( V_63 -> V_74 ) ;
V_71 -> V_120 = F_40 ( V_120 ) ;
V_71 -> V_68 =
V_71 -> V_132 = F_40 ( V_68 ) ;
V_71 -> V_121 =
V_71 -> V_133 = F_40 ( V_121 ) ;
V_71 -> V_134 =
V_71 -> V_135 = F_40 ( 0x40000000 ) ;
if ( V_63 -> V_136 ) {
if ( V_125 ) {
V_71 -> V_137 =
V_71 -> V_84 = V_123 ;
}
if ( V_126 ) {
V_71 -> V_138 =
V_71 -> V_88 = V_124 ;
}
}
if ( V_63 -> V_85 ) {
if ( ! V_63 -> V_139 ) {
if ( V_125 ) {
V_71 -> V_140 =
V_71 -> V_86 = V_123 ;
}
if ( V_126 ) {
V_71 -> V_141 =
V_71 -> V_89 = V_124 ;
}
} else {
if ( V_125 ) {
V_71 -> V_141 =
V_71 -> V_89 = V_123 ;
}
if ( V_126 ) {
V_71 -> V_140 =
V_71 -> V_86 = V_124 ;
}
}
}
}
}
static int T_4 F_49 ( struct V_1 * V_2 )
{
if ( F_50 ( V_142 , F_51 ( V_2 -> V_143 ) ,
4096 , & V_2 -> V_144 ) < 0 )
return - V_56 ;
V_2 -> V_145 [ 3 ] [ 0 ] -> V_129 =
V_2 -> V_145 [ 3 ] [ 1 ] -> V_129 = F_40 ( V_2 -> V_144 . V_146 ) ;
V_2 -> V_145 [ 3 ] [ 0 ] -> V_131 =
V_2 -> V_145 [ 3 ] [ 1 ] -> V_131 = F_40 ( 1024 ) ;
V_2 -> V_145 [ 4 ] [ 0 ] -> V_129 =
V_2 -> V_145 [ 4 ] [ 1 ] -> V_129 = F_40 ( V_2 -> V_144 . V_146 + 2048 ) ;
V_2 -> V_145 [ 4 ] [ 0 ] -> V_131 =
V_2 -> V_145 [ 4 ] [ 1 ] -> V_131 = F_40 ( 1024 ) ;
F_52 ( & V_2 -> V_30 ) ;
F_11 ( V_2 , V_147 ,
F_9 ( V_2 , V_147 ) | 3 << 3 ) ;
F_53 ( & V_2 -> V_30 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 )
{
F_52 ( & V_2 -> V_30 ) ;
F_11 ( V_2 , V_147 ,
F_9 ( V_2 , V_147 ) & ~ ( 3 << 3 ) ) ;
F_53 ( & V_2 -> V_30 ) ;
if ( V_2 -> V_144 . V_148 ) {
F_55 ( & V_2 -> V_144 ) ;
V_2 -> V_144 . V_148 = NULL ;
}
return 0 ;
}
static int F_56 ( struct V_90 * V_69 ,
struct V_149 * V_150 )
{
struct V_91 * V_92 = V_69 -> V_92 ;
struct V_66 * V_63 = V_92 -> V_16 ;
int V_116 ;
if ( ( V_116 = F_57 ( V_69 , F_58 ( V_150 ) ) ) < 0 )
return V_116 ;
if ( ( V_116 = F_46 ( V_63 , F_59 ( V_150 ) ) ) < 0 )
return V_116 ;
return 0 ;
}
static int F_60 ( struct V_90 * V_69 )
{
struct V_1 * V_2 = F_43 ( V_69 ) ;
struct V_91 * V_92 = V_69 -> V_92 ;
struct V_66 * V_63 ;
if ( V_92 -> V_16 == NULL )
return 0 ;
V_63 = V_92 -> V_16 ;
F_61 ( V_2 ) ;
F_62 ( V_69 ) ;
if ( V_63 -> V_48 [ 1 ] ) {
F_33 ( V_2 , V_63 -> V_48 [ 1 ] ) ;
V_63 -> V_48 [ 1 ] = NULL ;
}
if ( V_63 -> V_48 [ 0 ] ) {
F_33 ( V_2 , V_63 -> V_48 [ 0 ] ) ;
V_63 -> V_48 [ 0 ] = NULL ;
}
return 0 ;
}
static int F_63 ( struct V_90 * V_69 )
{
struct V_1 * V_2 = F_43 ( V_69 ) ;
struct V_91 * V_92 = V_69 -> V_92 ;
struct V_66 * V_63 = V_92 -> V_16 ;
struct V_96 * V_97 ;
unsigned int V_151 ;
V_63 -> V_76 = V_92 -> V_76 ;
V_63 -> V_74 = V_92 -> V_74 ;
V_63 -> V_75 = 0 ;
V_63 -> V_73 = 0 ;
for ( V_151 = 0 ; V_151 < V_92 -> V_127 ; V_151 ++ )
F_47 ( V_63 , V_151 , V_92 ,
V_69 -> V_51 == V_2 -> V_51 ) ;
if ( V_69 -> V_51 == V_2 -> V_51 && ! V_63 -> V_64 ) {
V_97 = V_2 -> V_82 [ V_69 -> V_61 ] . V_105 ;
V_97 -> V_106 [ 0 ] . V_107 &= ~ V_108 ;
F_44 ( V_2 -> V_111 , V_112 , & V_97 -> V_113 ) ;
}
return 0 ;
}
static int F_64 ( struct V_90 * V_69 ,
struct V_149 * V_150 )
{
return F_57 ( V_69 , F_58 ( V_150 ) ) ;
}
static int F_65 ( struct V_90 * V_69 )
{
struct V_1 * V_2 = F_43 ( V_69 ) ;
F_61 ( V_2 ) ;
return F_62 ( V_69 ) ;
}
static int F_66 ( struct V_90 * V_69 )
{
struct V_1 * V_2 = F_43 ( V_69 ) ;
struct V_91 * V_92 = V_69 -> V_92 ;
struct V_66 * V_63 = V_92 -> V_16 ;
struct V_152 * V_71 ;
int V_122 ;
T_2 V_27 , V_119 ;
V_63 -> V_76 = V_92 -> V_76 ;
V_63 -> V_74 = V_92 -> V_74 ;
V_63 -> V_75 = 0 ;
V_63 -> V_73 = 0 ;
V_63 -> V_95 = 0 ;
V_27 = ( ( 48000 * 4096 ) / V_92 -> V_27 ) - 1 ;
V_119 = 0 ;
if ( V_92 -> V_127 == 2 ) {
V_119 |= 2 ;
V_63 -> V_95 ++ ;
}
if ( F_48 ( V_92 -> V_119 ) == 8 )
V_119 |= 1 ;
else
V_63 -> V_95 ++ ;
switch ( V_63 -> V_94 ) {
case 0 :
F_11 ( V_2 , V_153 , V_119 ) ;
F_11 ( V_2 , V_154 , V_27 ) ;
break;
case 1 :
F_11 ( V_2 , V_155 , V_119 ) ;
F_11 ( V_2 , V_156 , V_27 ) ;
break;
}
for ( V_122 = 0 ; V_122 < 2 ; V_122 ++ ) {
V_71 = V_2 -> V_93 [ V_63 -> V_94 ] [ V_122 ] ;
V_71 -> V_129 = F_40 ( V_92 -> V_130 ) ;
V_71 -> V_131 = F_40 ( V_63 -> V_74 << V_63 -> V_95 ) ;
V_71 -> V_72 = 0 ;
V_71 -> V_157 = 0 ;
}
return 0 ;
}
static T_5 F_67 ( struct V_90 * V_69 )
{
struct V_1 * V_2 = F_43 ( V_69 ) ;
struct V_91 * V_92 = V_69 -> V_92 ;
struct V_66 * V_63 = V_92 -> V_16 ;
struct V_42 * V_44 = V_63 -> V_48 [ 0 ] ;
if ( ! ( V_63 -> V_70 && V_44 ) )
return 0 ;
return F_36 ( V_44 -> V_71 [ V_2 -> V_34 ] . V_72 ) ;
}
static T_5 F_68 ( struct V_90 * V_69 )
{
struct V_1 * V_2 = F_43 ( V_69 ) ;
struct V_91 * V_92 = V_69 -> V_92 ;
struct V_66 * V_63 = V_92 -> V_16 ;
if ( ! V_63 -> V_70 )
return 0 ;
return F_36 ( V_2 -> V_93 [ V_63 -> V_94 ] [ V_2 -> V_34 ] -> V_72 ) >> V_63 -> V_95 ;
}
static void F_61 ( struct V_1 * V_2 )
{
T_6 V_158 ;
int V_159 = 4 ;
while ( V_159 -- > 0 ) {
if ( ( F_9 ( V_2 , V_33 ) & 3 ) == 0 )
continue;
F_69 ( & V_158 , V_160 ) ;
F_70 ( & V_2 -> V_39 , & V_158 ) ;
F_71 ( & V_2 -> V_38 ) ;
F_15 ( F_14 ( 50 ) ) ;
F_72 ( & V_2 -> V_39 , & V_158 ) ;
}
}
static T_7 F_73 ( int V_161 , void * V_162 )
{
struct V_1 * V_2 = V_162 ;
T_2 V_163 , V_151 , V_164 ;
struct V_42 * V_44 ;
V_163 = F_9 ( V_2 , V_37 ) ;
if ( V_163 & 0x80000000 ) {
V_2 -> V_34 = F_9 ( V_2 , V_35 ) & 1 ;
F_35 ( & V_2 -> V_59 ) ;
for ( V_151 = 0 ; V_151 < V_47 ; V_151 ++ ) {
V_44 = & V_2 -> V_48 [ V_151 ] ;
if ( V_44 -> V_65 )
V_44 -> V_65 ( V_2 , V_44 ) ;
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
F_37 ( & V_2 -> V_59 ) ;
F_35 ( & V_2 -> V_30 ) ;
F_11 ( V_2 , V_37 , 0x80000000 ) ;
V_164 = F_9 ( V_2 , V_33 ) | 2 ;
F_11 ( V_2 , V_33 , V_164 ) ;
F_37 ( & V_2 -> V_30 ) ;
if ( F_27 ( & V_2 -> V_38 ) ) {
F_28 ( & V_2 -> V_38 , 0 ) ;
F_29 ( & V_2 -> V_39 ) ;
}
}
V_163 = F_5 ( V_2 , V_167 ) ;
if ( V_163 & 1 ) {
if ( V_2 -> V_168 )
F_74 ( V_2 -> V_168 , V_2 -> V_169 ) ;
}
F_7 ( V_2 , V_167 , V_163 ) ;
if ( V_2 -> V_170 )
F_75 ( V_161 , V_2 -> V_170 -> V_16 ) ;
return V_171 ;
}
static void F_76 ( struct V_91 * V_92 )
{
F_77 ( V_92 -> V_16 ) ;
}
static int F_78 ( struct V_90 * V_69 )
{
struct V_1 * V_2 = F_43 ( V_69 ) ;
struct V_91 * V_92 = V_69 -> V_92 ;
struct V_66 * V_63 ;
int V_116 ;
V_92 -> V_172 = V_173 ;
V_116 = F_79 ( V_92 ,
V_174 ,
5334 , V_175 ) ;
if ( V_116 < 0 )
return V_116 ;
V_116 = F_80 ( V_92 , 48000 ) ;
if ( V_116 < 0 )
return V_116 ;
V_63 = F_81 ( sizeof( * V_63 ) , V_176 ) ;
if ( V_63 == NULL )
return - V_56 ;
V_63 -> V_2 = V_2 ;
V_63 -> type = V_177 ;
V_63 -> V_69 = V_69 ;
V_92 -> V_16 = V_63 ;
V_92 -> V_178 = F_76 ;
return 0 ;
}
static void F_82 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_179 ) {
if ( ! V_2 -> V_180 )
F_11 ( V_2 , V_33 ,
F_9 ( V_2 , V_33 ) | ( 1 << 30 ) ) ;
F_7 ( V_2 , V_181 ,
( F_5 ( V_2 , V_181 ) & ~ 0x0330 ) | 0x0010 ) ;
}
}
static void F_83 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_179 ) {
if ( ! V_2 -> V_180 )
F_11 ( V_2 , V_33 ,
F_9 ( V_2 , V_33 ) & ~ ( 1 << 30 ) ) ;
F_7 ( V_2 , V_181 ,
( F_5 ( V_2 , V_181 ) & ~ 0x0330 ) & ~ 0x0010 ) ;
}
}
static int F_84 ( struct V_90 * V_69 )
{
struct V_1 * V_2 = F_43 ( V_69 ) ;
struct V_91 * V_92 = V_69 -> V_92 ;
struct V_66 * V_63 ;
int V_116 ;
if ( ( V_116 = F_78 ( V_69 ) ) < 0 )
return V_116 ;
V_63 = V_92 -> V_16 ;
V_63 -> V_136 = 1 ;
V_63 -> V_85 = V_2 -> V_182 ? 1 : 0 ;
V_63 -> V_139 = 0 ;
F_52 ( & V_2 -> V_30 ) ;
if ( V_63 -> V_85 ) {
F_82 ( V_2 ) ;
V_2 -> V_179 ++ ;
}
F_53 ( & V_2 -> V_30 ) ;
return 0 ;
}
static int F_85 ( struct V_90 * V_69 )
{
struct V_1 * V_2 = F_43 ( V_69 ) ;
struct V_91 * V_92 = V_69 -> V_92 ;
struct V_66 * V_63 ;
int V_116 ;
if ( ( V_116 = F_78 ( V_69 ) ) < 0 )
return V_116 ;
V_63 = V_92 -> V_16 ;
V_63 -> V_136 = 0 ;
V_63 -> V_85 = 1 ;
V_63 -> V_139 = 1 ;
F_52 ( & V_2 -> V_30 ) ;
F_7 ( V_2 , V_183 ,
F_5 ( V_2 , V_183 ) | 2 ) ;
F_82 ( V_2 ) ;
V_2 -> V_184 = V_2 -> V_185 ;
F_7 ( V_2 , V_186 , V_2 -> V_184 ) ;
V_2 -> V_180 ++ ;
F_53 ( & V_2 -> V_30 ) ;
V_2 -> V_187 -> V_106 [ 0 ] . V_107 &= ~ V_108 ;
F_44 ( V_2 -> V_111 , V_188 |
V_112 , & V_2 -> V_187 -> V_113 ) ;
return 0 ;
}
static int F_86 ( struct V_90 * V_69 )
{
struct V_1 * V_2 = F_43 ( V_69 ) ;
struct V_91 * V_92 = V_69 -> V_92 ;
struct V_66 * V_63 ;
int V_116 ;
if ( ( V_116 = F_78 ( V_69 ) ) < 0 )
return V_116 ;
V_63 = V_92 -> V_16 ;
V_63 -> V_136 = 0 ;
V_63 -> V_85 = 1 ;
V_63 -> V_139 = 0 ;
F_52 ( & V_2 -> V_30 ) ;
F_82 ( V_2 ) ;
V_2 -> V_179 ++ ;
F_53 ( & V_2 -> V_30 ) ;
return 0 ;
}
static int F_87 ( struct V_90 * V_69 ,
T_2 V_94 )
{
struct V_1 * V_2 = F_43 ( V_69 ) ;
struct V_91 * V_92 = V_69 -> V_92 ;
struct V_66 * V_63 ;
int V_116 ;
V_92 -> V_172 = V_189 ;
V_116 = F_79 ( V_92 ,
V_174 ,
5334 , V_175 ) ;
if ( V_116 < 0 )
return V_116 ;
V_116 = F_80 ( V_92 , 48000 ) ;
if ( V_116 < 0 )
return V_116 ;
V_63 = F_81 ( sizeof( * V_63 ) , V_176 ) ;
if ( V_63 == NULL )
return - V_56 ;
V_63 -> V_2 = V_2 ;
V_63 -> type = V_94 + V_190 ;
V_63 -> V_69 = V_69 ;
V_63 -> V_94 = V_94 ;
V_2 -> V_166 [ V_94 ] = V_69 ;
V_92 -> V_16 = V_63 ;
V_92 -> V_178 = F_76 ;
F_23 ( V_2 ) ;
return 0 ;
}
static int F_88 ( struct V_90 * V_69 )
{
return F_87 ( V_69 , 0 ) ;
}
static int F_89 ( struct V_90 * V_69 )
{
return F_87 ( V_69 , 1 ) ;
}
static int F_90 ( struct V_90 * V_69 )
{
return 0 ;
}
static int F_91 ( struct V_90 * V_69 )
{
struct V_1 * V_2 = F_43 ( V_69 ) ;
struct V_66 * V_63 = V_69 -> V_92 -> V_16 ;
F_52 ( & V_2 -> V_30 ) ;
if ( V_63 -> V_85 && V_2 -> V_179 > 0 ) {
V_2 -> V_179 -- ;
F_83 ( V_2 ) ;
}
F_53 ( & V_2 -> V_30 ) ;
return F_90 ( V_69 ) ;
}
static int F_92 ( struct V_90 * V_69 )
{
struct V_1 * V_2 = F_43 ( V_69 ) ;
F_52 ( & V_2 -> V_30 ) ;
V_2 -> V_180 = 0 ;
F_83 ( V_2 ) ;
F_7 ( V_2 , V_183 ,
F_5 ( V_2 , V_183 ) & ~ 2 ) ;
F_7 ( V_2 , V_186 , V_2 -> V_185 ) ;
F_53 ( & V_2 -> V_30 ) ;
V_2 -> V_187 -> V_106 [ 0 ] . V_107 |= V_108 ;
F_44 ( V_2 -> V_111 , V_188 |
V_112 , & V_2 -> V_187 -> V_113 ) ;
return F_90 ( V_69 ) ;
}
static int F_93 ( struct V_90 * V_69 )
{
struct V_1 * V_2 = F_43 ( V_69 ) ;
F_52 ( & V_2 -> V_30 ) ;
if ( V_2 -> V_179 > 0 ) {
V_2 -> V_179 -- ;
F_83 ( V_2 ) ;
}
F_53 ( & V_2 -> V_30 ) ;
return F_90 ( V_69 ) ;
}
static int F_94 ( struct V_90 * V_69 )
{
struct V_1 * V_2 = F_43 ( V_69 ) ;
struct V_91 * V_92 = V_69 -> V_92 ;
struct V_66 * V_63 = V_92 -> V_16 ;
if ( V_63 != NULL ) {
V_2 -> V_166 [ V_63 -> V_94 ] = NULL ;
F_26 ( V_2 ) ;
}
return 0 ;
}
int T_4 V_66 ( struct V_1 * V_2 , int V_191 , struct V_192 * * V_193 )
{
struct V_192 * V_51 ;
int V_116 ;
if ( V_193 )
* V_193 = NULL ;
if ( ( V_116 = F_95 ( V_2 -> V_111 , L_2 , V_191 , 32 , 1 , & V_51 ) ) < 0 )
return V_116 ;
V_51 -> V_16 = V_2 ;
F_96 ( V_51 , V_194 , & V_195 ) ;
F_96 ( V_51 , V_196 , & V_197 ) ;
V_51 -> V_198 = 0 ;
strcpy ( V_51 -> V_199 , L_2 ) ;
V_2 -> V_51 = V_51 ;
F_97 ( V_51 , V_142 ,
F_51 ( V_2 -> V_143 ) , 64 * 1024 , 256 * 1024 ) ;
if ( V_193 )
* V_193 = V_51 ;
return 0 ;
}
int T_4 F_98 ( struct V_1 * V_2 , int V_191 , struct V_192 * * V_193 )
{
struct V_192 * V_51 ;
int V_116 ;
if ( V_193 )
* V_193 = NULL ;
if ( ( V_116 = F_95 ( V_2 -> V_111 , L_3 , V_191 , 0 , 1 , & V_51 ) ) < 0 )
return V_116 ;
V_51 -> V_16 = V_2 ;
F_96 ( V_51 , V_196 , & V_200 ) ;
V_51 -> V_198 = 0 ;
sprintf ( V_51 -> V_199 , L_4 ,
V_2 -> V_22 == V_128 ? L_5 : L_6 ) ;
V_2 -> V_201 = V_51 ;
F_97 ( V_51 , V_142 ,
F_51 ( V_2 -> V_143 ) , 64 * 1024 , 256 * 1024 ) ;
if ( V_193 )
* V_193 = V_51 ;
return 0 ;
}
int T_4 F_99 ( struct V_1 * V_2 , int V_191 , struct V_192 * * V_193 )
{
struct V_192 * V_51 ;
int V_116 ;
if ( V_193 )
* V_193 = NULL ;
if ( ( V_116 = F_95 ( V_2 -> V_111 , L_7 , V_191 , 1 , 0 , & V_51 ) ) < 0 )
return V_116 ;
V_51 -> V_16 = V_2 ;
F_96 ( V_51 , V_194 , & V_202 ) ;
V_51 -> V_198 = 0 ;
strcpy ( V_51 -> V_199 , L_7 ) ;
V_2 -> V_203 = V_51 ;
F_97 ( V_51 , V_142 ,
F_51 ( V_2 -> V_143 ) , 64 * 1024 , 256 * 1024 ) ;
if ( V_193 )
* V_193 = V_51 ;
return 0 ;
}
int T_4 F_100 ( struct V_1 * V_2 , int V_191 , struct V_192 * * V_193 )
{
struct V_192 * V_51 ;
int V_116 ;
if ( V_193 )
* V_193 = NULL ;
if ( ( V_116 = F_95 ( V_2 -> V_111 , L_8 , V_191 , 1 , 0 , & V_51 ) ) < 0 )
return V_116 ;
V_51 -> V_16 = V_2 ;
F_96 ( V_51 , V_194 , & V_204 ) ;
V_51 -> V_198 = 0 ;
strcpy ( V_51 -> V_199 , L_9 ) ;
V_2 -> V_205 = V_51 ;
F_97 ( V_51 , V_142 ,
F_51 ( V_2 -> V_143 ) , 64 * 1024 , 256 * 1024 ) ;
if ( V_193 )
* V_193 = V_51 ;
return 0 ;
}
static int F_101 ( struct V_96 * V_206 , struct V_207 * V_208 )
{
V_208 -> type = V_209 ;
V_208 -> V_210 = 1 ;
return 0 ;
}
static int F_102 ( struct V_96 * V_206 ,
struct V_211 * V_212 )
{
struct V_1 * V_2 = F_103 ( V_206 ) ;
F_52 ( & V_2 -> V_30 ) ;
V_212 -> V_213 . V_214 . V_163 [ 0 ] = ( V_2 -> V_185 >> 0 ) & 0xff ;
V_212 -> V_213 . V_214 . V_163 [ 1 ] = ( V_2 -> V_185 >> 8 ) & 0xff ;
V_212 -> V_213 . V_214 . V_163 [ 3 ] = V_215 ;
F_53 ( & V_2 -> V_30 ) ;
return 0 ;
}
static int F_104 ( struct V_96 * V_206 ,
struct V_211 * V_212 )
{
struct V_1 * V_2 = F_103 ( V_206 ) ;
unsigned int V_5 ;
int V_216 ;
V_5 = ( ( V_212 -> V_213 . V_214 . V_163 [ 0 ] & 0x3e ) << 0 ) |
( V_212 -> V_213 . V_214 . V_163 [ 1 ] << 8 ) ;
F_52 ( & V_2 -> V_30 ) ;
V_216 = V_2 -> V_185 != V_5 ;
V_2 -> V_185 = V_5 ;
if ( ( F_5 ( V_2 , V_183 ) & 1 ) && V_2 -> V_203 == NULL )
F_7 ( V_2 , V_186 , V_2 -> V_185 ) ;
F_53 ( & V_2 -> V_30 ) ;
return V_216 ;
}
static int F_105 ( struct V_96 * V_206 , struct V_207 * V_208 )
{
V_208 -> type = V_209 ;
V_208 -> V_210 = 1 ;
return 0 ;
}
static int F_106 ( struct V_96 * V_206 ,
struct V_211 * V_212 )
{
struct V_1 * V_2 = F_103 ( V_206 ) ;
F_52 ( & V_2 -> V_30 ) ;
V_212 -> V_213 . V_214 . V_163 [ 0 ] = 0x3e ;
V_212 -> V_213 . V_214 . V_163 [ 1 ] = 0xff ;
F_53 ( & V_2 -> V_30 ) ;
return 0 ;
}
static int F_107 ( struct V_96 * V_206 , struct V_207 * V_208 )
{
V_208 -> type = V_209 ;
V_208 -> V_210 = 1 ;
return 0 ;
}
static int F_108 ( struct V_96 * V_206 ,
struct V_211 * V_212 )
{
struct V_1 * V_2 = F_103 ( V_206 ) ;
F_52 ( & V_2 -> V_30 ) ;
V_212 -> V_213 . V_214 . V_163 [ 0 ] = ( V_2 -> V_184 >> 0 ) & 0xff ;
V_212 -> V_213 . V_214 . V_163 [ 1 ] = ( V_2 -> V_184 >> 8 ) & 0xff ;
V_212 -> V_213 . V_214 . V_163 [ 3 ] = V_215 ;
F_53 ( & V_2 -> V_30 ) ;
return 0 ;
}
static int F_109 ( struct V_96 * V_206 ,
struct V_211 * V_212 )
{
struct V_1 * V_2 = F_103 ( V_206 ) ;
unsigned int V_5 ;
int V_216 ;
V_5 = ( ( V_212 -> V_213 . V_214 . V_163 [ 0 ] & 0x3e ) << 0 ) |
( V_212 -> V_213 . V_214 . V_163 [ 1 ] << 8 ) ;
F_52 ( & V_2 -> V_30 ) ;
V_216 = V_2 -> V_184 != V_5 ;
V_2 -> V_184 = V_5 ;
if ( ( F_5 ( V_2 , V_183 ) & 2 ) )
F_7 ( V_2 , V_186 , V_2 -> V_184 ) ;
F_53 ( & V_2 -> V_30 ) ;
return V_216 ;
}
static int F_110 ( struct V_96 * V_206 , struct V_207 * V_217 )
{
static const char * const V_218 [ 3 ] = { L_6 , L_10 , L_11 } ;
return F_111 ( V_217 , 1 , 3 , V_218 ) ;
}
static int F_112 ( struct V_96 * V_206 , struct V_211 * V_213 )
{
struct V_1 * V_2 = F_103 ( V_206 ) ;
T_3 V_8 ;
F_52 ( & V_2 -> V_30 ) ;
V_8 = F_5 ( V_2 , V_219 ) ;
F_53 ( & V_2 -> V_30 ) ;
if ( ! ( V_8 & 0x100 ) )
V_213 -> V_213 . V_220 . V_221 [ 0 ] = 0 ;
else
V_213 -> V_213 . V_220 . V_221 [ 0 ] = 1 + ( ( V_8 & 0x200 ) != 0 ) ;
return 0 ;
}
static int F_113 ( struct V_96 * V_206 , struct V_211 * V_213 )
{
struct V_1 * V_2 = F_103 ( V_206 ) ;
T_3 V_8 , V_222 ;
F_52 ( & V_2 -> V_30 ) ;
V_222 = F_5 ( V_2 , V_219 ) ;
if ( V_213 -> V_213 . V_220 . V_221 [ 0 ] == 0 )
V_8 = V_222 & ~ 0x100 ;
else
V_8 = ( V_222 & ~ 0x300 ) | 0x100 | ( ( V_213 -> V_213 . V_220 . V_221 [ 0 ] == 2 ) << 9 ) ;
F_7 ( V_2 , V_219 , V_8 ) ;
F_53 ( & V_2 -> V_30 ) ;
return V_8 != V_222 ;
}
static int F_114 ( struct V_96 * V_206 ,
struct V_211 * V_212 )
{
struct V_1 * V_2 = F_103 ( V_206 ) ;
int V_8 = V_206 -> V_223 & 0xffff ;
unsigned int V_95 = ( V_206 -> V_223 >> 16 ) & 0xff ;
unsigned int V_224 = 1 ;
switch ( V_8 ) {
case V_183 : break;
case V_225 : break;
default: return - V_58 ;
}
V_212 -> V_213 . integer . V_213 [ 0 ] =
( F_9 ( V_2 , V_8 ) >> V_95 ) & V_224 ;
return 0 ;
}
static int F_115 ( struct V_96 * V_206 ,
struct V_211 * V_212 )
{
struct V_1 * V_2 = F_103 ( V_206 ) ;
int V_8 = V_206 -> V_223 & 0xffff ;
unsigned int V_95 = ( V_206 -> V_223 >> 16 ) & 0xff ;
unsigned int V_224 = 1 ;
int V_216 ;
unsigned int V_5 , V_226 ;
switch ( V_8 ) {
case V_183 : break;
case V_225 : break;
default: return - V_58 ;
}
V_5 = ( V_212 -> V_213 . integer . V_213 [ 0 ] & V_224 ) ;
V_5 <<= V_95 ;
F_52 ( & V_2 -> V_30 ) ;
V_226 = F_9 ( V_2 , V_8 ) ;
V_5 = ( V_226 & ~ ( V_224 << V_95 ) ) | V_5 ;
V_216 = V_5 != V_226 ;
F_11 ( V_2 , V_8 , V_5 ) ;
F_53 ( & V_2 -> V_30 ) ;
return V_216 ;
}
static int F_116 ( struct V_96 * V_206 , struct V_207 * V_208 )
{
unsigned int V_8 = V_206 -> V_223 ;
if ( V_8 < 0x80 || V_8 >= 0xc0 )
return - V_58 ;
V_208 -> type = V_227 ;
V_208 -> V_210 = 2 ;
V_208 -> V_213 . integer . V_228 = 0 ;
V_208 -> V_213 . integer . V_229 = 16383 ;
return 0 ;
}
static int F_117 ( struct V_96 * V_206 , struct V_211 * V_212 )
{
struct V_1 * V_2 = F_103 ( V_206 ) ;
unsigned int V_8 = V_206 -> V_223 ;
unsigned int V_230 = 0 , V_231 = 16 , V_224 = 16383 ;
unsigned int V_5 ;
if ( V_8 < 0x80 || V_8 >= 0xc0 )
return - V_58 ;
F_52 ( & V_2 -> V_30 ) ;
V_5 = F_9 ( V_2 , V_8 ) ;
F_53 ( & V_2 -> V_30 ) ;
V_212 -> V_213 . integer . V_213 [ 0 ] = ( V_5 >> V_230 ) & V_224 ;
V_212 -> V_213 . integer . V_213 [ 1 ] = ( V_5 >> V_231 ) & V_224 ;
return 0 ;
}
static int F_118 ( struct V_96 * V_206 , struct V_211 * V_212 )
{
struct V_1 * V_2 = F_103 ( V_206 ) ;
unsigned int V_8 = V_206 -> V_223 ;
unsigned int V_230 = 0 , V_231 = 16 , V_224 = 16383 ;
int V_216 ;
unsigned int V_232 , V_233 , V_226 ;
if ( V_8 < 0x80 || V_8 >= 0xc0 )
return - V_58 ;
V_232 = V_212 -> V_213 . integer . V_213 [ 0 ] & V_224 ;
V_233 = V_212 -> V_213 . integer . V_213 [ 1 ] & V_224 ;
V_232 <<= V_230 ;
V_233 <<= V_231 ;
F_52 ( & V_2 -> V_30 ) ;
V_226 = F_9 ( V_2 , V_8 ) ;
V_232 = ( V_226 & ~ ( ( V_224 << V_230 ) | ( V_224 << V_231 ) ) ) | V_232 | V_233 ;
V_216 = V_232 != V_226 ;
F_11 ( V_2 , V_8 , V_232 ) ;
F_53 ( & V_2 -> V_30 ) ;
return V_216 ;
}
static int F_119 ( struct V_96 * V_206 ,
struct V_211 * V_212 )
{
struct V_1 * V_2 = F_103 ( V_206 ) ;
unsigned int V_8 = V_234 ;
unsigned int V_235 = V_236 ;
int V_216 ;
unsigned int V_213 , V_226 ;
V_213 = V_212 -> V_213 . integer . V_213 [ 0 ] & 0x3fff ;
V_213 |= ( V_212 -> V_213 . integer . V_213 [ 1 ] & 0x3fff ) << 16 ;
F_52 ( & V_2 -> V_30 ) ;
V_226 = F_9 ( V_2 , V_8 ) ;
V_216 = V_213 != V_226 ;
F_11 ( V_2 , V_8 , V_213 ) ;
F_11 ( V_2 , V_235 , V_213 ) ;
F_53 ( & V_2 -> V_30 ) ;
return V_216 ;
}
static int F_120 ( struct V_96 * V_206 , struct V_211 * V_212 )
{
struct V_1 * V_2 = F_103 ( V_206 ) ;
V_212 -> V_213 . integer . V_213 [ 0 ] = V_2 -> V_182 ;
return 0 ;
}
static int F_121 ( struct V_96 * V_206 , struct V_211 * V_212 )
{
struct V_1 * V_2 = F_103 ( V_206 ) ;
int V_216 ;
V_216 = ( V_212 -> V_213 . integer . V_213 [ 0 ] != V_2 -> V_182 ) ;
if ( V_216 )
V_2 -> V_182 = ! ! V_212 -> V_213 . integer . V_213 [ 0 ] ;
return V_216 ;
}
static int F_122 ( struct V_1 * V_2 , int V_237 )
{
T_3 V_8 , V_164 ;
unsigned long V_29 ;
F_24 ( & V_2 -> V_30 , V_29 ) ;
V_8 = F_5 ( V_2 , V_238 ) ;
V_8 &= ~ ( 1 << ( V_237 + 8 ) ) ;
V_8 |= ( 1 << V_237 ) ;
F_7 ( V_2 , V_238 , V_8 ) ;
V_164 = F_5 ( V_2 , V_239 ) ;
V_164 &= ~ ( 3 << ( V_237 * 2 ) ) ;
F_7 ( V_2 , V_239 , V_164 ) ;
F_7 ( V_2 , V_238 , V_8 | ( 1 << ( V_237 + 8 ) ) ) ;
V_164 = F_5 ( V_2 , V_240 ) ;
F_25 ( & V_2 -> V_30 , V_29 ) ;
return ( V_164 >> V_237 ) & 1 ;
}
static int F_123 ( struct V_1 * V_2 , int V_237 , int V_241 )
{
T_3 V_8 ;
unsigned long V_29 ;
F_24 ( & V_2 -> V_30 , V_29 ) ;
V_8 = F_5 ( V_2 , V_238 ) ;
V_8 &= ~ ( 1 << V_237 ) ;
V_8 &= ~ ( 1 << ( V_237 + 8 ) ) ;
F_7 ( V_2 , V_238 , V_8 ) ;
F_7 ( V_2 , V_242 , V_241 << V_237 ) ;
F_7 ( V_2 , V_238 , V_8 | ( 1 << ( V_237 + 8 ) ) ) ;
F_25 ( & V_2 -> V_30 , V_29 ) ;
return 0 ;
}
static int F_124 ( struct V_96 * V_206 , struct V_211 * V_212 )
{
struct V_1 * V_2 = F_103 ( V_206 ) ;
int V_237 = ( int ) V_206 -> V_223 ;
V_212 -> V_213 . integer . V_213 [ 0 ] = F_122 ( V_2 , V_237 ) ;
return 0 ;
}
static int F_125 ( struct V_96 * V_206 , struct V_211 * V_212 )
{
struct V_1 * V_2 = F_103 ( V_206 ) ;
int V_237 = ( int ) V_206 -> V_223 ;
if ( F_122 ( V_2 , V_237 ) != V_212 -> V_213 . integer . V_213 [ 0 ] ) {
F_123 ( V_2 , V_237 , ! ! V_212 -> V_213 . integer . V_213 [ 0 ] ) ;
V_212 -> V_213 . integer . V_213 [ 0 ] = F_122 ( V_2 , V_237 ) ;
return 1 ;
}
return 0 ;
}
static int F_126 ( struct V_96 * V_206 ,
struct V_207 * V_208 )
{
V_208 -> type = V_227 ;
V_208 -> V_210 = 2 ;
V_208 -> V_213 . integer . V_228 = 0 ;
V_208 -> V_213 . integer . V_229 = 0x8000 ;
return 0 ;
}
static int F_127 ( struct V_96 * V_206 ,
struct V_211 * V_212 )
{
struct V_1 * V_2 = F_103 ( V_206 ) ;
unsigned int V_78 = V_206 -> V_113 . V_243 ;
V_212 -> V_213 . integer . V_213 [ 0 ] = V_2 -> V_82 [ V_78 ] . V_83 ;
V_212 -> V_213 . integer . V_213 [ 1 ] = V_2 -> V_82 [ V_78 ] . V_87 ;
return 0 ;
}
static int F_128 ( struct V_96 * V_206 ,
struct V_211 * V_212 )
{
struct V_1 * V_2 = F_103 ( V_206 ) ;
unsigned int V_78 = V_206 -> V_113 . V_243 ;
struct V_90 * V_69 ;
unsigned long V_29 ;
if ( V_212 -> V_213 . integer . V_213 [ 0 ] != V_2 -> V_82 [ V_78 ] . V_83 ||
V_212 -> V_213 . integer . V_213 [ 1 ] != V_2 -> V_82 [ V_78 ] . V_87 ) {
V_2 -> V_82 [ V_78 ] . V_83 = V_212 -> V_213 . integer . V_213 [ 0 ] ;
V_2 -> V_82 [ V_78 ] . V_87 = V_212 -> V_213 . integer . V_213 [ 1 ] ;
if ( V_2 -> V_82 [ V_78 ] . V_83 > 0x8000 )
V_2 -> V_82 [ V_78 ] . V_83 = 0x8000 ;
if ( V_2 -> V_82 [ V_78 ] . V_87 > 0x8000 )
V_2 -> V_82 [ V_78 ] . V_87 = 0x8000 ;
V_69 = (struct V_90 * ) V_206 -> V_223 ;
F_24 ( & V_2 -> V_59 , V_29 ) ;
if ( V_69 -> V_92 && V_69 -> V_92 -> V_16 ) {
struct V_66 * V_63 = V_69 -> V_92 -> V_16 ;
if ( ! V_63 -> V_64 )
V_63 -> V_77 = 2 ;
}
F_25 ( & V_2 -> V_59 , V_29 ) ;
return 1 ;
}
return 0 ;
}
static void F_129 ( struct V_244 * V_245 )
{
struct V_1 * V_2 = V_245 -> V_16 ;
V_2 -> V_246 = NULL ;
}
static void F_130 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
V_2 -> V_15 = NULL ;
}
int T_4 F_131 ( struct V_1 * V_2 , int V_247 )
{
struct V_248 V_15 ;
struct V_96 * V_97 ;
struct V_90 * V_69 ;
unsigned int V_46 ;
int V_116 ;
static struct V_249 V_250 = {
. V_251 = F_18 ,
. V_252 = F_19 ,
} ;
if ( ( V_116 = V_244 ( V_2 -> V_111 , 0 , & V_250 , V_2 , & V_2 -> V_246 ) ) < 0 )
return V_116 ;
V_2 -> V_246 -> V_178 = F_129 ;
V_2 -> V_246 -> V_253 = 1 ;
memset ( & V_15 , 0 , sizeof( V_15 ) ) ;
V_15 . V_16 = V_2 ;
V_15 . V_178 = F_130 ;
if ( ( V_116 = F_132 ( V_2 -> V_246 , & V_15 , & V_2 -> V_15 ) ) < 0 )
return V_116 ;
F_133 ( V_2 -> V_15 , V_254 ,
V_255 | V_256 , 0 ) ;
for ( V_46 = 0 ; V_46 < F_134 ( V_257 ) ; V_46 ++ ) {
if ( ( V_116 = F_135 ( V_2 -> V_111 , F_136 ( & V_257 [ V_46 ] , V_2 ) ) ) < 0 )
return V_116 ;
}
if ( F_32 ( ! V_2 -> V_203 ) )
return - V_258 ;
if ( ( V_116 = F_135 ( V_2 -> V_111 , V_97 = F_136 ( & V_259 , V_2 ) ) ) < 0 )
return V_116 ;
V_97 -> V_113 . V_191 = V_2 -> V_203 -> V_191 ;
if ( ( V_116 = F_135 ( V_2 -> V_111 , V_97 = F_136 ( & V_260 , V_2 ) ) ) < 0 )
return V_116 ;
V_97 -> V_113 . V_191 = V_2 -> V_203 -> V_191 ;
if ( ( V_116 = F_135 ( V_2 -> V_111 , V_97 = F_136 ( & V_261 , V_2 ) ) ) < 0 )
return V_116 ;
V_97 -> V_113 . V_191 = V_2 -> V_203 -> V_191 ;
V_2 -> V_187 = V_97 ;
if ( V_2 -> V_22 == V_128 &&
( V_116 = F_135 ( V_2 -> V_111 , V_97 = F_136 ( & V_262 , V_2 ) ) ) < 0 )
return V_116 ;
if ( V_247 ) {
if ( ( V_116 = F_135 ( V_2 -> V_111 , F_136 ( & V_263 , V_2 ) ) ) < 0 )
return V_116 ;
}
V_69 = V_2 -> V_51 -> V_264 [ V_194 ] . V_69 ;
for ( V_46 = 0 ; V_46 < 32 ; ++ V_46 ) {
V_97 = F_136 ( & V_265 , V_2 ) ;
if ( ! V_97 )
return - V_56 ;
V_97 -> V_113 . V_191 = V_2 -> V_51 -> V_191 ;
V_97 -> V_113 . V_243 = V_46 ;
V_97 -> V_223 = ( unsigned long ) V_69 ;
if ( ( V_116 = F_135 ( V_2 -> V_111 , V_97 ) ) < 0 )
return V_116 ;
V_2 -> V_82 [ V_46 ] . V_83 = 0x8000 ;
V_2 -> V_82 [ V_46 ] . V_87 = 0x8000 ;
V_2 -> V_82 [ V_46 ] . V_105 = V_97 ;
V_69 = V_69 -> V_266 ;
}
return 0 ;
}
static int F_137 ( struct V_267 * V_168 )
{
struct V_1 * V_2 ;
unsigned long V_29 ;
unsigned int V_210 ;
V_2 = F_138 ( V_168 ) ;
F_24 ( & V_2 -> V_30 , V_29 ) ;
if ( V_168 -> V_268 > 1 ) {
V_2 -> V_169 = V_168 -> V_268 ;
V_210 = V_168 -> V_268 - 1 ;
} else {
V_2 -> V_169 = 2 ;
V_210 = 2 - 1 ;
}
F_7 ( V_2 , V_269 , V_210 ) ;
F_3 ( V_2 , V_270 , 0x03 ) ;
F_25 ( & V_2 -> V_30 , V_29 ) ;
return 0 ;
}
static int F_139 ( struct V_267 * V_168 )
{
struct V_1 * V_2 ;
unsigned long V_29 ;
V_2 = F_138 ( V_168 ) ;
F_24 ( & V_2 -> V_30 , V_29 ) ;
F_3 ( V_2 , V_270 , 0x00 ) ;
F_25 ( & V_2 -> V_30 , V_29 ) ;
return 0 ;
}
static int F_140 ( struct V_267 * V_168 ,
unsigned long * V_271 , unsigned long * V_272 )
{
* V_271 = 1 ;
* V_272 = 96000 ;
return 0 ;
}
int T_4 F_141 ( struct V_1 * V_2 , int V_191 )
{
struct V_267 * V_168 = NULL ;
struct V_273 V_274 ;
int V_116 ;
V_274 . V_275 = V_276 ;
V_274 . V_277 = V_278 ;
V_274 . V_111 = V_2 -> V_111 -> V_61 ;
V_274 . V_191 = V_191 ;
V_274 . V_243 = 0 ;
if ( ( V_116 = F_142 ( V_2 -> V_111 , L_2 , & V_274 , & V_168 ) ) >= 0 ) {
strcpy ( V_168 -> V_199 , L_12 ) ;
V_168 -> V_16 = V_2 ;
V_168 -> V_172 = V_279 ;
}
V_2 -> V_168 = V_168 ;
return V_116 ;
}
static void F_143 ( struct V_280 * V_281 ,
struct V_282 * V_283 )
{
struct V_1 * V_2 = V_281 -> V_16 ;
int V_25 ;
F_144 ( V_283 , L_13 ) ;
for ( V_25 = 0 ; V_25 <= V_284 ; V_25 += 4 )
F_144 ( V_283 , L_14 , V_25 , F_9 ( V_2 , V_25 ) ) ;
}
static int T_4 F_145 ( struct V_285 * V_111 , struct V_1 * V_2 )
{
struct V_280 * V_281 ;
if ( ! F_146 ( V_111 , L_15 , & V_281 ) )
F_147 ( V_281 , V_2 , F_143 ) ;
return 0 ;
}
static void F_148 ( struct V_286 * V_143 )
{
T_1 V_17 ;
F_149 ( V_143 , V_287 , & V_17 ) ;
#if 0
if (cmd & 0x03) {
#endif
F_150 ( V_143 , V_287 , V_17 & 0xfc ) ;
F_150 ( V_143 , V_287 , V_17 | 0x03 ) ;
F_150 ( V_143 , V_287 , V_17 & 0xfc ) ;
F_151 ( V_143 , V_288 , 0 ) ;
F_151 ( V_143 , V_289 , 0 ) ;
#if 0
}
#endif
}
static void F_152 ( struct V_1 * V_2 )
{
F_11 ( V_2 , V_290 , 0x00000001 ) ;
}
static void F_153 ( struct V_1 * V_2 )
{
T_2 V_5 ;
int V_36 = 1000 ;
V_5 = F_9 ( V_2 , V_290 ) ;
if ( V_5 )
F_11 ( V_2 , V_290 , 0x00000000 ) ;
while ( V_36 -- > 0 ) {
V_5 = F_9 ( V_2 , V_37 ) ;
if ( ( V_5 & 0x00000002 ) == 0 )
break;
}
}
static int F_154 ( struct V_1 * V_2 )
{
int V_116 , V_291 ;
const char * V_199 ;
V_116 = F_155 ( & V_2 -> V_292 , L_16 ,
& V_2 -> V_143 -> V_293 ) ;
if ( V_116 >= 0 ) {
if ( V_2 -> V_292 -> V_294 != V_295 ) {
F_17 ( V_12 L_17 ) ;
V_116 = - V_58 ;
}
}
if ( V_116 < 0 )
return V_116 ;
V_291 = V_2 -> V_22 == V_296 ||
V_2 -> V_22 == V_297 ||
V_2 -> V_22 == V_23 ||
V_2 -> V_22 == V_128 ;
V_199 = V_291 ? L_18 : L_19 ;
V_116 = F_155 ( & V_2 -> V_298 , V_199 ,
& V_2 -> V_143 -> V_293 ) ;
if ( V_116 >= 0 ) {
if ( V_2 -> V_298 -> V_294 != V_299 ) {
F_17 ( V_12 L_20
L_21 ) ;
V_116 = - V_58 ;
}
}
if ( V_116 < 0 )
return V_116 ;
return 0 ;
}
static void F_156 ( struct V_1 * V_2 )
{
int V_25 ;
T_3 V_300 ;
const T_8 * V_301 ;
F_11 ( V_2 , V_234 , 0x00000000 ) ;
F_153 ( V_2 ) ;
F_11 ( V_2 , V_33 , 0x00010000 ) ;
F_11 ( V_2 , V_33 , 0x00000000 ) ;
F_11 ( V_2 , V_115 , 0x00000000 ) ;
F_11 ( V_2 , V_147 , 0x00000000 ) ;
F_11 ( V_2 , V_302 , 0x00000000 ) ;
F_11 ( V_2 , V_303 , 0x00000000 ) ;
F_11 ( V_2 , V_304 , 0x00000000 ) ;
V_300 = F_5 ( V_2 , V_219 ) ;
F_7 ( V_2 , V_219 , V_300 & ~ 0x0007 ) ;
V_301 = ( const T_8 * ) V_2 -> V_292 -> V_305 ;
for ( V_25 = 0 ; V_25 < V_295 / 4 ; V_25 ++ )
F_11 ( V_2 , V_306 + ( V_25 << 2 ) ,
F_36 ( V_301 [ V_25 ] ) ) ;
V_301 = ( const T_8 * ) V_2 -> V_298 -> V_305 ;
for ( V_25 = 0 ; V_25 < V_299 / 4 ; V_25 ++ )
F_11 ( V_2 , V_307 + ( V_25 << 2 ) ,
F_36 ( V_301 [ V_25 ] ) ) ;
F_152 ( V_2 ) ;
}
static int T_4 F_157 ( struct V_1 * V_2 )
{
long V_294 , V_308 ;
int V_44 , V_71 , V_8 ;
T_1 * V_309 ;
T_9 V_310 ;
V_308 = 4 + 4 * V_47 ;
V_2 -> V_311 = F_9 ( V_2 , V_312 ) << 2 ;
V_2 -> V_313 = F_9 ( V_2 , V_314 ) << 2 ;
V_2 -> V_315 = F_9 ( V_2 , V_316 ) << 2 ;
V_2 -> V_317 = V_318 ;
V_294 = F_158 ( V_308 , 0x100 ) +
F_158 ( V_2 -> V_311 * 2 * V_47 , 0x100 ) +
F_158 ( V_2 -> V_313 * 2 * V_165 , 0x100 ) +
F_158 ( V_2 -> V_315 * 2 * V_319 , 0x100 ) +
V_2 -> V_317 ;
if ( F_50 ( V_142 , F_51 ( V_2 -> V_143 ) ,
V_294 , & V_2 -> V_320 ) < 0 )
return - V_56 ;
V_309 = V_2 -> V_320 . V_148 ;
V_310 = V_2 -> V_320 . V_146 ;
memset ( V_309 , 0 , V_294 ) ;
V_2 -> V_321 = V_309 ;
V_2 -> V_322 = V_310 ;
V_2 -> V_102 = ( T_2 * ) V_309 ;
V_2 -> V_102 [ 0 ] = F_40 ( V_47 ) ;
V_309 += F_158 ( V_308 , 0x100 ) ;
V_310 += F_158 ( V_308 , 0x100 ) ;
for ( V_44 = 0 ; V_44 < V_47 ; V_44 ++ ) {
V_2 -> V_48 [ V_44 ] . V_61 = V_44 ;
V_2 -> V_48 [ V_44 ] . V_71 = (struct V_80 * ) V_309 ;
V_2 -> V_48 [ V_44 ] . V_103 = V_310 ;
for ( V_71 = 0 ; V_71 < 2 ; V_71 ++ ) {
V_2 -> V_323 [ V_44 ] [ V_71 ] = (struct V_80 * ) V_309 ;
V_309 += V_2 -> V_311 ;
V_310 += V_2 -> V_311 ;
}
}
V_309 = ( char * ) F_158 ( ( unsigned long ) V_309 , 0x100 ) ;
V_310 = F_158 ( V_310 , 0x100 ) ;
V_2 -> V_324 = V_309 ;
V_2 -> V_325 = V_310 ;
for ( V_44 = 0 ; V_44 < V_165 ; V_44 ++ )
for ( V_71 = 0 ; V_71 < 2 ; V_71 ++ ) {
V_2 -> V_93 [ V_44 ] [ V_71 ] = (struct V_152 * ) V_309 ;
V_309 += V_2 -> V_313 ;
V_310 += V_2 -> V_313 ;
}
V_309 = ( char * ) F_158 ( ( unsigned long ) V_309 , 0x100 ) ;
V_310 = F_158 ( V_310 , 0x100 ) ;
V_2 -> V_326 = V_309 ;
V_2 -> V_327 = V_310 ;
for ( V_44 = 0 ; V_44 < V_319 ; V_44 ++ )
for ( V_71 = 0 ; V_71 < 2 ; V_71 ++ ) {
V_2 -> V_145 [ V_44 ] [ V_71 ] = (struct V_328 * ) V_309 ;
V_309 += V_2 -> V_315 ;
V_310 += V_2 -> V_315 ;
}
V_309 = ( char * ) F_158 ( ( unsigned long ) V_309 , 0x100 ) ;
V_310 = F_158 ( V_310 , 0x100 ) ;
V_2 -> V_329 = V_309 ;
V_2 -> V_330 = V_310 ;
F_32 ( V_309 + V_2 -> V_317 !=
V_2 -> V_320 . V_148 + V_2 -> V_320 . V_331 ) ;
F_11 ( V_2 , V_302 , V_2 -> V_322 ) ;
F_11 ( V_2 , V_303 , V_2 -> V_325 ) ;
F_11 ( V_2 , V_304 , V_2 -> V_327 ) ;
F_11 ( V_2 , V_284 , V_2 -> V_330 ) ;
F_11 ( V_2 , V_332 , V_2 -> V_317 >> 2 ) ;
V_2 -> V_185 = V_2 -> V_184 = V_333 & 0xffff ;
F_7 ( V_2 , V_183 , 0 ) ;
F_7 ( V_2 , V_186 , V_2 -> V_185 ) ;
F_7 ( V_2 , V_225 , 0 ) ;
for ( V_8 = 0x80 ; V_8 < 0xc0 ; V_8 += 4 )
F_11 ( V_2 , V_8 , 0 ) ;
F_11 ( V_2 , V_234 , 0x3fff3fff ) ;
F_11 ( V_2 , V_236 , 0x3fff3fff ) ;
F_11 ( V_2 , V_334 , 0x3fff3fff ) ;
F_11 ( V_2 , V_335 , 0x3fff3fff ) ;
F_11 ( V_2 , V_336 , 0x3fff3fff ) ;
F_11 ( V_2 , V_337 , 0x3fff3fff ) ;
F_11 ( V_2 , V_338 , 0x3fff3fff ) ;
F_11 ( V_2 , V_339 , 0x3fff3fff ) ;
return 0 ;
}
static int F_159 ( struct V_1 * V_2 )
{
T_3 V_300 ;
if ( F_32 ( ! V_2 ) )
return - V_58 ;
if ( V_2 -> V_340 ) {
F_11 ( V_2 , V_234 , 0 ) ;
F_11 ( V_2 , V_236 , 0 ) ;
F_11 ( V_2 , V_339 , 0 ) ;
F_11 ( V_2 , V_37 , ~ 0 ) ;
F_153 ( V_2 ) ;
F_11 ( V_2 , V_302 , 0 ) ;
F_11 ( V_2 , V_303 , 0 ) ;
F_11 ( V_2 , V_304 , 0 ) ;
F_11 ( V_2 , V_284 , 0 ) ;
F_11 ( V_2 , V_332 , 0 ) ;
V_300 = F_5 ( V_2 , V_219 ) ;
F_7 ( V_2 , V_219 , V_300 & ~ 0x0007 ) ;
}
F_54 ( V_2 ) ;
#if 0
pci_set_power_state(chip->pci, 3);
#endif
#ifdef F_160
F_161 ( V_2 -> V_341 ) ;
#endif
if ( V_2 -> V_161 >= 0 )
F_162 ( V_2 -> V_161 , V_2 ) ;
F_163 ( V_2 -> V_342 ) ;
F_163 ( V_2 -> V_343 ) ;
F_164 ( V_2 ) ;
if ( V_2 -> V_4 )
F_165 ( V_2 -> V_4 ) ;
if ( V_2 -> V_320 . V_148 )
F_55 ( & V_2 -> V_320 ) ;
F_163 ( V_2 -> V_340 ) ;
F_151 ( V_2 -> V_143 , 0x40 , V_2 -> V_344 ) ;
F_166 ( V_2 -> V_143 ) ;
F_167 ( V_2 -> V_292 ) ;
F_167 ( V_2 -> V_298 ) ;
F_77 ( V_2 ) ;
return 0 ;
}
static int F_168 ( struct V_345 * V_191 )
{
struct V_1 * V_2 = V_191 -> V_346 ;
return F_159 ( V_2 ) ;
}
int F_169 ( struct V_286 * V_143 , T_10 V_347 )
{
struct V_285 * V_111 = F_170 ( V_143 ) ;
struct V_1 * V_2 = V_111 -> V_16 ;
unsigned int V_25 ;
F_171 ( V_111 , V_348 ) ;
F_172 ( V_2 -> V_51 ) ;
F_172 ( V_2 -> V_201 ) ;
F_172 ( V_2 -> V_203 ) ;
F_172 ( V_2 -> V_205 ) ;
F_173 ( V_2 -> V_15 ) ;
for ( V_25 = 0 ; V_25 < V_349 ; V_25 ++ )
V_2 -> V_341 [ V_25 ] = F_9 ( V_2 , V_350 [ V_25 ] ) ;
V_2 -> V_351 = F_9 ( V_2 , V_33 ) ;
F_11 ( V_2 , V_234 , 0 ) ;
F_11 ( V_2 , V_236 , 0 ) ;
F_153 ( V_2 ) ;
F_166 ( V_143 ) ;
F_174 ( V_143 ) ;
F_175 ( V_143 , F_176 ( V_143 , V_347 ) ) ;
return 0 ;
}
int F_177 ( struct V_286 * V_143 )
{
struct V_285 * V_111 = F_170 ( V_143 ) ;
struct V_1 * V_2 = V_111 -> V_16 ;
unsigned int V_25 ;
F_175 ( V_143 , V_352 ) ;
F_178 ( V_143 ) ;
if ( F_179 ( V_143 ) < 0 ) {
F_180 ( V_12 L_22
L_23 ) ;
F_181 ( V_111 ) ;
return - V_353 ;
}
F_182 ( V_143 ) ;
F_148 ( V_143 ) ;
F_13 ( V_2 , 0 ) ;
F_156 ( V_2 ) ;
F_183 ( 100 ) ;
for ( V_25 = 0 ; V_25 < V_349 ; V_25 ++ )
F_11 ( V_2 , V_350 [ V_25 ] , V_2 -> V_341 [ V_25 ] ) ;
F_184 ( V_2 -> V_15 ) ;
if ( V_2 -> V_31 > 0 ) {
F_52 ( & V_2 -> V_30 ) ;
F_11 ( V_2 , V_33 , V_2 -> V_351 ) ;
V_2 -> V_34 = F_9 ( V_2 , V_35 ) ;
F_53 ( & V_2 -> V_30 ) ;
}
F_171 ( V_111 , V_354 ) ;
return 0 ;
}
int T_4 F_185 ( struct V_285 * V_111 ,
struct V_286 * V_143 ,
unsigned short V_344 ,
struct V_1 * * V_355 )
{
struct V_1 * V_2 ;
int V_116 ;
static struct V_356 V_250 = {
. V_357 = F_168 ,
} ;
* V_355 = NULL ;
if ( ( V_116 = F_179 ( V_143 ) ) < 0 )
return V_116 ;
V_2 = F_81 ( sizeof( * V_2 ) , V_176 ) ;
if ( V_2 == NULL ) {
F_166 ( V_143 ) ;
return - V_56 ;
}
V_2 -> V_344 = V_344 ;
F_186 ( & V_2 -> V_30 ) ;
F_186 ( & V_2 -> V_59 ) ;
F_187 ( & V_2 -> V_39 ) ;
F_28 ( & V_2 -> V_38 , 0 ) ;
V_2 -> V_111 = V_111 ;
V_2 -> V_143 = V_143 ;
V_2 -> V_161 = - 1 ;
V_2 -> V_22 = V_143 -> V_191 ;
V_2 -> V_24 = V_143 -> V_358 ;
V_2 -> V_359 = F_188 ( V_143 , 0 ) ;
V_2 -> V_4 = F_189 ( V_2 -> V_359 , 0x8000 ) ;
F_182 ( V_143 ) ;
V_2 -> V_62 = - 1 ;
if ( ( V_2 -> V_340 = F_190 ( V_2 -> V_359 , 0x8000 , L_2 ) ) == NULL ) {
F_17 ( V_12 L_24 , V_2 -> V_359 , V_2 -> V_359 + 0x8000 - 1 ) ;
F_159 ( V_2 ) ;
return - V_13 ;
}
if ( F_191 ( V_143 -> V_161 , F_73 , V_360 ,
V_361 , V_2 ) ) {
F_17 ( V_12 L_25 , V_143 -> V_161 ) ;
F_159 ( V_2 ) ;
return - V_13 ;
}
V_2 -> V_161 = V_143 -> V_161 ;
F_148 ( V_143 ) ;
if ( F_13 ( V_2 , 0 ) < 0 ) {
F_159 ( V_2 ) ;
return - V_353 ;
}
V_116 = F_154 ( V_2 ) ;
if ( V_116 < 0 ) {
F_17 ( V_12 L_26 , V_116 ) ;
F_159 ( V_2 ) ;
return V_116 ;
}
F_156 ( V_2 ) ;
F_183 ( 100 ) ;
if ( F_157 ( V_2 ) < 0 ) {
F_159 ( V_2 ) ;
return - V_353 ;
}
if ( ( V_116 = F_49 ( V_2 ) ) < 0 ) {
F_159 ( V_2 ) ;
return V_116 ;
}
#ifdef F_160
V_2 -> V_341 = F_192 ( V_349 * sizeof( T_2 ) ) ;
if ( V_2 -> V_341 == NULL ) {
F_159 ( V_2 ) ;
return - V_56 ;
}
#endif
if ( ( V_116 = F_193 ( V_111 , V_362 , V_2 , & V_250 ) ) < 0 ) {
F_159 ( V_2 ) ;
return V_116 ;
}
F_145 ( V_111 , V_2 ) ;
F_194 ( V_111 , & V_143 -> V_293 ) ;
* V_355 = V_2 ;
return 0 ;
}
