static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 -> V_4 ;
int V_5 = V_1 -> V_5 ;
if ( V_5 < 0 )
F_2 ( & V_1 -> V_6 -> V_6 , L_1 , V_7 , V_5 ) ;
F_3 ( V_3 ) ;
F_4 ( V_1 ) ;
}
static int F_5 ( T_1 * V_8 , T_2 V_9 , T_2 V_10 , void * V_11 )
{
int V_12 ;
V_12 = F_6 ( V_8 -> V_13 , F_7 ( V_8 -> V_13 , 0 ) ,
V_14 , V_15 , 0 ,
V_9 , V_11 , V_10 , 1000 ) ;
if ( V_12 < 0 )
F_8 ( V_8 , V_16 , V_8 -> V_17 ,
L_2 , V_7 , V_12 ) ;
return V_12 ;
}
static int F_9 ( T_1 * V_8 , T_2 V_9 , T_2 V_10 , void * V_11 )
{
int V_12 ;
V_12 = F_6 ( V_8 -> V_13 , F_10 ( V_8 -> V_13 , 0 ) ,
V_18 , V_19 , 0 ,
V_9 , V_11 , V_10 , 100 ) ;
if ( V_12 < 0 )
F_8 ( V_8 , V_16 , V_8 -> V_17 ,
L_2 , V_7 , V_12 ) ;
return V_12 ;
}
static int F_11 ( T_1 * V_8 , T_2 V_9 , T_3 V_11 )
{
int V_12 ;
V_12 = F_6 ( V_8 -> V_13 , F_10 ( V_8 -> V_13 , 0 ) ,
V_20 , V_19 , V_11 ,
V_9 , & V_11 , 1 , 1000 ) ;
if ( V_12 < 0 )
F_8 ( V_8 , V_16 , V_8 -> V_17 ,
L_2 , V_7 , V_12 ) ;
return V_12 ;
}
static int F_12 ( T_1 * V_8 )
{
int V_12 = - V_21 ;
struct V_1 * V_22 ;
struct V_2 * V_3 ;
V_3 = F_13 ( sizeof( struct V_2 ) , V_23 ) ;
if ( V_3 == NULL )
return V_12 ;
V_22 = F_14 ( 0 , V_23 ) ;
if ( V_22 == NULL ) {
F_3 ( V_3 ) ;
return V_12 ;
}
V_3 -> V_24 = V_19 ;
V_3 -> V_25 = V_18 ;
V_3 -> V_26 = F_15 ( 0 ) ;
V_3 -> V_27 = F_15 ( V_28 ) ;
V_3 -> V_29 = F_15 ( 3 ) ;
F_16 ( V_22 , V_8 -> V_13 ,
F_10 ( V_8 -> V_13 , 0 ) , ( void * ) V_3 ,
V_8 -> V_30 , 3 , F_1 , V_3 ) ;
V_12 = F_17 ( V_22 , V_23 ) ;
if ( V_12 ) {
if ( V_12 == - V_31 )
F_18 ( V_8 -> V_17 ) ;
F_19 ( V_8 , V_16 , V_8 -> V_17 ,
L_2 , V_7 , V_12 ) ;
}
return V_12 ;
}
static int F_20 ( T_1 * V_32 , T_3 V_33 , T_3 V_9 , T_2 * V_34 , T_3 V_35 )
{
int V_36 ;
T_3 V_11 [ 4 ] = { V_33 , 0 , 0 , V_9 } ;
T_4 V_37 ;
int V_12 = - V_38 ;
if ( V_35 & V_39 ) {
T_4 * V_40 = ( T_4 * ) & V_11 [ 1 ] ;
* V_40 = F_15 ( * V_34 ) ;
}
F_11 ( V_32 , V_41 , 0 ) ;
F_9 ( V_32 , V_42 , sizeof( V_11 ) , V_11 ) ;
F_11 ( V_32 , V_41 , ( V_9 | V_35 ) ) ;
for ( V_36 = 0 ; V_36 < V_43 ; V_36 ++ ) {
V_12 = F_5 ( V_32 , V_41 , 1 , V_11 ) ;
if ( V_12 < 0 )
goto V_44;
if ( V_11 [ 0 ] & V_45 )
break;
}
if ( V_36 >= V_43 )
goto V_44;
if ( V_35 & V_46 ) {
V_12 = F_5 ( V_32 , V_47 , 2 , & V_37 ) ;
* V_34 = F_21 ( V_37 ) ;
return V_12 ;
}
return 0 ;
V_44:
F_8 ( V_32 , V_16 , V_32 -> V_17 , L_3 , V_7 ) ;
return V_12 ;
}
static int F_22 ( T_1 * V_8 , T_3 V_33 , T_3 V_9 , T_2 * V_34 )
{
return F_20 ( V_8 , V_33 , V_9 , V_34 , V_46 ) ;
}
static int F_23 ( T_1 * V_8 , T_3 V_33 , T_3 V_9 , T_2 * V_34 )
{
return F_20 ( V_8 , V_33 , V_9 , V_34 , V_39 ) ;
}
static int F_24 ( struct V_48 * V_6 , int V_49 , int V_50 )
{
T_1 * V_8 = F_25 ( V_6 ) ;
T_5 V_51 ;
F_22 ( V_8 , V_49 , V_50 , & V_51 ) ;
return ( int ) V_51 ;
}
static void F_26 ( struct V_48 * V_6 , int V_49 , int V_50 , int V_52 )
{
T_1 * V_8 = F_25 ( V_6 ) ;
T_5 V_11 = V_52 ;
F_23 ( V_8 , V_49 , V_50 , & V_11 ) ;
}
static int F_27 ( T_1 * V_8 , T_3 V_53 , T_2 * V_54 )
{
int V_36 ;
T_3 V_55 ;
T_4 V_56 ;
int V_12 ;
F_11 ( V_8 , V_57 , 0 ) ;
F_11 ( V_8 , V_58 , V_53 ) ;
F_11 ( V_8 , V_57 , V_59 ) ;
for ( V_36 = 0 ; V_36 < V_43 ; V_36 ++ ) {
V_12 = F_5 ( V_8 , V_57 , 1 , & V_55 ) ;
if ( V_55 & V_60 )
break;
if ( V_12 == - V_61 )
goto V_44;
}
if ( V_36 >= V_43 )
goto V_44;
V_12 = F_5 ( V_8 , V_62 , 2 , & V_56 ) ;
* V_54 = F_21 ( V_56 ) ;
return V_12 ;
V_44:
F_28 ( V_8 , V_16 , V_8 -> V_17 , L_3 , V_7 ) ;
return - V_38 ;
}
static inline void F_29 ( T_1 * V_8 )
{
T_3 V_55 ;
F_5 ( V_8 , V_63 , 1 , & V_55 ) ;
F_11 ( V_8 , V_63 , V_55 | V_64 ) ;
}
static inline void F_30 ( T_1 * V_8 )
{
T_3 V_55 ;
F_5 ( V_8 , V_63 , 1 , & V_55 ) ;
F_11 ( V_8 , V_57 , 0 ) ;
F_11 ( V_8 , V_63 , V_55 & ~ V_64 ) ;
}
static int F_31 ( T_1 * V_8 , T_3 V_53 , T_2 V_11 )
{
int V_36 ;
T_3 V_55 , V_65 [ 4 ] = { 0x3f , 0 , 0 , V_66 } ;
int V_12 ;
T_4 V_67 = F_15 ( V_11 ) ;
F_9 ( V_8 , V_58 , 4 , V_65 ) ;
F_29 ( V_8 ) ;
F_11 ( V_8 , V_58 , V_53 ) ;
F_9 ( V_8 , V_62 , 2 , & V_67 ) ;
F_11 ( V_8 , V_57 , V_66 ) ;
for ( V_36 = 0 ; V_36 < V_43 ; V_36 ++ ) {
V_12 = F_5 ( V_8 , V_57 , 1 , & V_55 ) ;
if ( V_12 == - V_61 )
goto V_44;
if ( V_55 & V_60 )
break;
}
F_30 ( V_8 ) ;
if ( V_36 >= V_43 )
goto V_44;
return V_12 ;
V_44:
F_28 ( V_8 , V_16 , V_8 -> V_17 , L_3 , V_7 ) ;
return - V_38 ;
}
static inline void F_32 ( T_1 * V_8 , T_3 * V_68 )
{
int V_36 ;
T_2 V_69 ;
for ( V_36 = 0 ; V_36 < 3 ; V_36 ++ ) {
F_27 ( V_8 , V_36 , & V_69 ) ;
( ( T_4 * ) V_68 ) [ V_36 ] = F_15 ( V_69 ) ;
}
}
static void F_33 ( T_1 * V_8 )
{
T_3 V_70 [ 6 ] ;
if ( V_8 -> V_71 & V_72 ) {
F_5 ( V_8 , 0x10 , sizeof( V_70 ) , V_70 ) ;
} else {
F_32 ( V_8 , V_70 ) ;
F_9 ( V_8 , V_73 , sizeof( V_70 ) , V_70 ) ;
}
memcpy ( V_8 -> V_17 -> V_74 , V_70 , sizeof( V_70 ) ) ;
}
static inline int F_34 ( T_1 * V_8 )
{
T_3 V_11 = 0x8 ;
int V_36 ;
F_11 ( V_8 , V_75 , V_11 ) ;
for ( V_36 = 0 ; V_36 < V_43 ; V_36 ++ ) {
F_5 ( V_8 , V_75 , 1 , & V_11 ) ;
if ( ~ V_11 & 0x08 ) {
if ( V_76 )
break;
if ( V_77 && ( V_8 -> V_71 & V_78 ) )
F_11 ( V_8 , V_79 , 0x34 ) ;
else
F_11 ( V_8 , V_79 , 0x26 ) ;
F_11 ( V_8 , V_80 , V_8 -> V_71 ) ;
F_11 ( V_8 , V_80 , V_81 ) ;
break;
}
}
if ( V_36 == V_43 )
return - V_38 ;
if ( V_82 [ V_8 -> V_83 ] . V_84 == V_85 ||
V_82 [ V_8 -> V_83 ] . V_84 == V_86 ) {
F_11 ( V_8 , V_80 , 0x24 ) ;
F_11 ( V_8 , V_80 , 0x26 ) ;
}
if ( V_82 [ V_8 -> V_83 ] . V_84 == V_87 ) {
T_2 V_88 ;
F_22 ( V_8 , 3 , 0x1b , & V_88 ) ;
V_88 |= 4 ;
F_23 ( V_8 , 3 , 0x1b , & V_88 ) ;
}
return 0 ;
}
static int F_35 ( struct V_48 * V_6 , struct V_89 * V_13 )
{
T_2 V_90 ;
T_3 V_11 [ 4 ] ;
T_1 * V_8 = F_25 ( V_6 ) ;
int V_12 ;
F_22 ( V_8 , V_8 -> V_33 , V_91 , & V_90 ) ;
V_11 [ 0 ] = 0xc8 ;
V_11 [ 1 ] = 0 ;
if ( V_90 & ( V_92 | V_93 ) )
V_11 [ 1 ] |= 0x20 ;
if ( V_90 & ( V_92 | V_94 ) )
V_11 [ 1 ] |= 0x10 ;
if ( V_77 )
V_11 [ 1 ] = 0 ;
V_11 [ 2 ] = V_76 ? 0x09 : 0x01 ;
memcpy ( V_8 -> V_30 , V_11 , sizeof( V_11 ) ) ;
V_12 = F_9 ( V_8 , V_28 , 3 , V_11 ) ;
if ( V_82 [ V_8 -> V_83 ] . V_84 == V_85 ||
V_82 [ V_8 -> V_83 ] . V_84 == V_95 ||
V_82 [ V_8 -> V_83 ] . V_84 == V_86 ) {
T_5 V_88 ;
F_22 ( V_8 , 0 , 0x1b , & V_88 ) ;
V_88 |= 4 ;
F_23 ( V_8 , 0 , 0x1b , & V_88 ) ;
}
return V_12 ;
}
static void F_36 ( struct V_1 * V_1 )
{
T_1 * V_8 = V_1 -> V_4 ;
struct V_48 * V_17 ;
int V_96 , V_97 = V_1 -> V_98 ;
int V_5 = V_1 -> V_5 ;
T_6 * V_99 = V_1 -> V_100 ;
T_2 V_101 ;
if ( ! V_8 )
return;
V_17 = V_8 -> V_17 ;
if ( ! F_37 ( V_17 ) || ! F_38 ( V_17 ) )
return;
switch ( V_5 ) {
case 0 :
break;
case - V_102 :
F_8 ( V_8 , V_103 , V_17 , L_4 ) ;
V_8 -> V_104 &= ~ V_105 ;
break;
case - V_106 :
F_28 ( V_8 , V_103 , V_17 , L_5 ) ;
return;
case - V_107 :
case - V_108 :
case - V_61 :
F_8 ( V_8 , V_109 , V_17 , L_6 , V_5 ) ;
return;
default:
F_8 ( V_8 , V_103 , V_17 , L_7 , V_5 ) ;
goto V_110;
}
if ( V_97 < 4 )
goto V_110;
V_96 = V_99 [ V_97 - 2 ] ;
if ( V_96 & 0x1e ) {
F_8 ( V_8 , V_103 , V_17 ,
L_8 , V_96 ) ;
V_8 -> V_111 . V_112 ++ ;
if ( V_96 & 0x06 )
V_8 -> V_111 . V_113 ++ ;
if ( V_96 & 0x08 )
V_8 -> V_111 . V_114 ++ ;
if ( V_96 & 0x10 )
V_8 -> V_111 . V_115 ++ ;
goto V_110;
}
if ( V_8 -> V_116 == 0x8513 ) {
V_101 = F_39 ( * ( V_117 * ) V_1 -> V_100 ) ;
V_101 &= 0x0fff ;
V_8 -> V_118 -> V_11 += 2 ;
} else {
V_101 = V_99 [ V_97 - 3 ] << 8 ;
V_101 += V_99 [ V_97 - 4 ] ;
V_101 &= 0xfff ;
V_101 -= 4 ;
}
if ( V_101 > V_119 )
goto V_110;
F_40 ( V_8 -> V_118 , V_101 ) ;
V_8 -> V_118 -> V_120 = F_41 ( V_8 -> V_118 , V_17 ) ;
F_42 ( V_8 -> V_118 ) ;
V_8 -> V_111 . V_121 ++ ;
V_8 -> V_111 . V_122 += V_101 ;
if ( V_8 -> V_104 & V_123 )
return;
V_8 -> V_118 = F_43 ( V_8 -> V_17 , V_119 ,
V_23 ) ;
if ( V_8 -> V_118 == NULL )
goto V_124;
V_110:
F_44 ( V_8 -> V_125 , V_8 -> V_13 ,
F_45 ( V_8 -> V_13 , 1 ) ,
V_8 -> V_118 -> V_11 , V_119 ,
F_36 , V_8 ) ;
V_96 = F_17 ( V_8 -> V_125 , V_23 ) ;
if ( V_96 == - V_31 )
F_18 ( V_8 -> V_17 ) ;
else if ( V_96 ) {
V_8 -> V_104 |= V_126 ;
goto V_124;
} else {
V_8 -> V_104 &= ~ V_126 ;
}
return;
V_124:
F_46 ( & V_8 -> V_127 ) ;
}
static void F_47 ( unsigned long V_11 )
{
T_1 * V_8 ;
int V_5 ;
V_8 = ( T_1 * ) V_11 ;
if ( V_8 -> V_104 & V_123 )
return;
if ( V_8 -> V_104 & V_126 )
if ( V_8 -> V_118 )
goto V_128;
if ( V_8 -> V_118 == NULL )
V_8 -> V_118 = F_43 ( V_8 -> V_17 ,
V_119 ,
V_23 ) ;
if ( V_8 -> V_118 == NULL ) {
F_28 ( V_8 , V_103 , V_8 -> V_17 , L_9 ) ;
F_46 ( & V_8 -> V_127 ) ;
return;
}
F_44 ( V_8 -> V_125 , V_8 -> V_13 ,
F_45 ( V_8 -> V_13 , 1 ) ,
V_8 -> V_118 -> V_11 , V_119 ,
F_36 , V_8 ) ;
V_128:
V_5 = F_17 ( V_8 -> V_125 , V_23 ) ;
if ( V_5 == - V_31 )
F_18 ( V_8 -> V_17 ) ;
else if ( V_5 ) {
V_8 -> V_104 |= V_126 ;
F_46 ( & V_8 -> V_127 ) ;
} else {
V_8 -> V_104 &= ~ V_126 ;
}
}
static void F_48 ( struct V_1 * V_1 )
{
T_1 * V_8 = V_1 -> V_4 ;
struct V_48 * V_17 ;
int V_5 = V_1 -> V_5 ;
if ( ! V_8 )
return;
V_17 = V_8 -> V_17 ;
if ( ! F_37 ( V_17 ) || ! F_38 ( V_17 ) )
return;
switch ( V_5 ) {
case - V_106 :
F_49 ( V_17 ) ;
F_28 ( V_8 , V_129 , V_17 , L_10 ) ;
return;
case - V_107 :
case - V_108 :
case - V_61 :
F_8 ( V_8 , V_109 , V_17 , L_11 , V_5 ) ;
return;
default:
F_50 ( V_8 , V_129 , V_17 , L_12 , V_5 ) ;
case 0 :
break;
}
F_51 ( V_17 ) ;
F_52 ( V_17 ) ;
}
static void F_53 ( struct V_1 * V_1 )
{
T_1 * V_8 = V_1 -> V_4 ;
struct V_48 * V_17 ;
int V_51 , V_5 = V_1 -> V_5 ;
if ( ! V_8 )
return;
V_17 = V_8 -> V_17 ;
switch ( V_5 ) {
case 0 :
break;
case - V_108 :
case - V_107 :
case - V_61 :
return;
default:
F_8 ( V_8 , V_130 , V_17 , L_13 , V_5 ) ;
}
if ( V_1 -> V_98 >= 6 ) {
T_6 * V_65 = V_1 -> V_100 ;
if ( V_65 [ 0 ] & ( V_131 | V_132
| V_133 | V_134 ) ) {
V_8 -> V_111 . V_135 ++ ;
if ( V_65 [ 0 ] & V_131 )
V_8 -> V_111 . V_136 ++ ;
if ( V_65 [ 0 ] & ( V_132 | V_134 ) )
V_8 -> V_111 . V_137 ++ ;
if ( V_65 [ 0 ] & V_133 )
V_8 -> V_111 . V_138 ++ ;
}
V_8 -> V_111 . V_139 += ( ( V_65 [ 3 ] & 0x7f ) << 8 ) | V_65 [ 4 ] ;
}
V_51 = F_17 ( V_1 , V_23 ) ;
if ( V_51 == - V_31 )
F_18 ( V_8 -> V_17 ) ;
if ( V_51 )
F_19 ( V_8 , V_130 , V_17 ,
L_14 , V_51 ) ;
}
static void F_54 ( struct V_48 * V_17 )
{
T_1 * V_8 = F_25 ( V_17 ) ;
F_28 ( V_8 , V_130 , V_17 , L_15 ) ;
F_55 ( V_8 -> V_140 ) ;
V_8 -> V_111 . V_135 ++ ;
}
static T_7 F_56 ( struct V_141 * V_142 ,
struct V_48 * V_17 )
{
T_1 * V_8 = F_25 ( V_17 ) ;
int V_97 = ( ( V_142 -> V_143 + 2 ) & 0x3f ) ? V_142 -> V_143 + 2 : V_142 -> V_143 + 3 ;
int V_51 ;
T_2 V_144 = V_142 -> V_143 ;
F_49 ( V_17 ) ;
( ( T_4 * ) V_8 -> V_145 ) [ 0 ] = F_15 ( V_144 ) ;
F_57 ( V_142 , V_8 -> V_145 + 2 , V_142 -> V_143 ) ;
F_44 ( V_8 -> V_140 , V_8 -> V_13 ,
F_58 ( V_8 -> V_13 , 2 ) ,
V_8 -> V_145 , V_97 ,
F_48 , V_8 ) ;
if ( ( V_51 = F_17 ( V_8 -> V_140 , V_23 ) ) ) {
F_28 ( V_8 , V_129 , V_17 , L_16 , V_51 ) ;
switch ( V_51 ) {
case - V_106 :
break;
case - V_31 :
case - V_146 :
F_18 ( V_8 -> V_17 ) ;
break;
default:
V_8 -> V_111 . V_135 ++ ;
F_59 ( V_17 ) ;
}
} else {
V_8 -> V_111 . V_147 ++ ;
V_8 -> V_111 . V_148 += V_142 -> V_143 ;
}
F_60 ( V_142 ) ;
return V_149 ;
}
static struct V_150 * F_61 ( struct V_48 * V_6 )
{
return & ( ( T_1 * ) F_25 ( V_6 ) ) -> V_111 ;
}
static inline void F_62 ( T_1 * V_8 )
{
T_4 V_55 = F_15 ( 0 ) ;
F_9 ( V_8 , V_28 , sizeof( V_55 ) , & V_55 ) ;
}
static inline void F_63 ( T_1 * V_8 )
{
T_5 V_11 ;
T_6 V_151 ;
F_27 ( V_8 , 4 , & V_11 ) ;
V_151 = V_11 >> 8 ;
if ( V_8 -> V_13 -> V_152 != V_153 ) {
if ( V_151 < 0x80 ) {
F_50 ( V_8 , V_130 , V_8 -> V_17 ,
L_17 ,
V_151 , 0x80 ) ;
V_151 = 0x80 ;
V_11 = ( V_11 & 0x00FF ) | ( ( T_5 ) V_151 << 8 ) ;
#ifdef F_64
F_31 ( V_8 , 4 , V_11 ) ;
#endif
}
}
V_8 -> V_154 = V_151 ;
}
static void F_65 ( struct V_48 * V_17 )
{
T_1 * V_8 = F_25 ( V_17 ) ;
T_5 V_55 ;
if ( F_22 ( V_8 , V_8 -> V_33 , V_155 , & V_55 ) )
return;
if ( V_55 & V_156 )
F_66 ( V_17 ) ;
else
F_67 ( V_17 ) ;
}
static void F_68 ( T_1 * V_8 )
{
F_4 ( V_8 -> V_157 ) ;
F_4 ( V_8 -> V_140 ) ;
F_4 ( V_8 -> V_125 ) ;
}
static void F_69 ( T_1 * V_8 )
{
F_70 ( V_8 -> V_157 ) ;
F_70 ( V_8 -> V_140 ) ;
F_70 ( V_8 -> V_125 ) ;
}
static int F_71 ( T_1 * V_8 )
{
int V_51 = - V_21 ;
V_8 -> V_125 = F_14 ( 0 , V_158 ) ;
if ( ! V_8 -> V_125 ) {
return V_51 ;
}
V_8 -> V_140 = F_14 ( 0 , V_158 ) ;
if ( ! V_8 -> V_140 ) {
F_4 ( V_8 -> V_125 ) ;
return V_51 ;
}
V_8 -> V_157 = F_14 ( 0 , V_158 ) ;
if ( ! V_8 -> V_157 ) {
F_4 ( V_8 -> V_140 ) ;
F_4 ( V_8 -> V_125 ) ;
return V_51 ;
}
return 0 ;
}
static int F_72 ( struct V_48 * V_17 )
{
T_1 * V_8 = F_25 ( V_17 ) ;
int V_51 = - V_21 ;
if ( V_8 -> V_118 == NULL )
V_8 -> V_118 = F_43 ( V_8 -> V_17 ,
V_119 ,
V_158 ) ;
if ( ! V_8 -> V_118 )
goto exit;
V_51 = F_9 ( V_8 , V_73 , 6 , V_17 -> V_74 ) ;
F_44 ( V_8 -> V_125 , V_8 -> V_13 ,
F_45 ( V_8 -> V_13 , 1 ) ,
V_8 -> V_118 -> V_11 , V_119 ,
F_36 , V_8 ) ;
if ( ( V_51 = F_17 ( V_8 -> V_125 , V_158 ) ) ) {
if ( V_51 == - V_31 )
F_18 ( V_8 -> V_17 ) ;
F_8 ( V_8 , V_159 , V_17 , L_18 , V_51 ) ;
goto exit;
}
F_73 ( V_8 -> V_157 , V_8 -> V_13 ,
F_74 ( V_8 -> V_13 , 3 ) ,
V_8 -> V_160 , sizeof( V_8 -> V_160 ) ,
F_53 , V_8 , V_8 -> V_154 ) ;
if ( ( V_51 = F_17 ( V_8 -> V_157 , V_158 ) ) ) {
if ( V_51 == - V_31 )
F_18 ( V_8 -> V_17 ) ;
F_8 ( V_8 , V_159 , V_17 , L_19 , V_51 ) ;
F_70 ( V_8 -> V_125 ) ;
goto exit;
}
V_51 = F_35 ( V_17 , V_8 -> V_13 ) ;
if ( V_51 < 0 ) {
F_8 ( V_8 , V_159 , V_17 ,
L_20 , V_51 ) ;
V_51 = - V_161 ;
F_70 ( V_8 -> V_125 ) ;
F_70 ( V_8 -> V_157 ) ;
goto exit;
}
F_65 ( V_17 ) ;
F_59 ( V_17 ) ;
F_8 ( V_8 , V_159 , V_17 , L_21 ) ;
V_51 = 0 ;
exit:
return V_51 ;
}
static int F_75 ( struct V_48 * V_17 )
{
T_1 * V_8 = F_25 ( V_17 ) ;
F_49 ( V_17 ) ;
if ( ! ( V_8 -> V_104 & V_123 ) )
F_62 ( V_8 ) ;
F_76 ( & V_8 -> V_127 ) ;
F_69 ( V_8 ) ;
return 0 ;
}
static void F_77 ( struct V_48 * V_6 ,
struct V_162 * V_163 )
{
T_1 * V_8 = F_25 ( V_6 ) ;
F_78 ( V_163 -> V_164 , V_165 , sizeof( V_163 -> V_164 ) ) ;
F_78 ( V_163 -> V_166 , V_167 , sizeof( V_163 -> V_166 ) ) ;
F_79 ( V_8 -> V_13 , V_163 -> V_168 , sizeof( V_163 -> V_168 ) ) ;
}
static void
F_80 ( struct V_48 * V_6 , struct V_169 * V_170 )
{
T_1 * V_8 = F_25 ( V_6 ) ;
V_170 -> V_171 = V_172 | V_173 ;
V_170 -> V_174 = V_8 -> V_174 ;
}
static int
F_81 ( struct V_48 * V_6 , struct V_169 * V_170 )
{
T_1 * V_8 = F_25 ( V_6 ) ;
T_6 V_175 = 0x04 ;
int V_12 ;
if ( V_170 -> V_174 & ~ V_176 )
return - V_177 ;
if ( V_170 -> V_174 & V_172 )
V_175 |= 0x80 ;
if ( V_170 -> V_174 & V_173 )
V_175 |= 0x40 ;
if ( V_170 -> V_174 )
V_8 -> V_30 [ 0 ] |= 0x10 ;
else
V_8 -> V_30 [ 0 ] &= ~ 0x10 ;
V_8 -> V_174 = V_170 -> V_174 ;
V_12 = F_11 ( V_8 , V_178 , V_175 ) ;
if ( ! V_12 )
V_12 = F_82 ( & V_8 -> V_13 -> V_6 ,
V_170 -> V_174 ) ;
return V_12 ;
}
static inline void F_83 ( struct V_48 * V_6 )
{
struct V_169 V_170 ;
memset ( & V_170 , 0 , sizeof V_170 ) ;
( void ) F_81 ( V_6 , & V_170 ) ;
}
static int
F_84 ( struct V_48 * V_6 , struct V_179 * V_180 )
{
T_1 * V_8 ;
V_8 = F_25 ( V_6 ) ;
F_85 ( & V_8 -> V_181 , V_180 ) ;
return 0 ;
}
static int
F_86 ( struct V_48 * V_6 , struct V_179 * V_180 )
{
T_1 * V_8 = F_25 ( V_6 ) ;
return F_87 ( & V_8 -> V_181 , V_180 ) ;
}
static int F_88 ( struct V_48 * V_6 )
{
T_1 * V_8 = F_25 ( V_6 ) ;
return F_89 ( & V_8 -> V_181 ) ;
}
static T_8 F_90 ( struct V_48 * V_6 )
{
T_1 * V_8 = F_25 ( V_6 ) ;
return F_91 ( & V_8 -> V_181 ) ;
}
static T_8 F_92 ( struct V_48 * V_6 )
{
T_1 * V_8 = F_25 ( V_6 ) ;
return V_8 -> V_182 ;
}
static void F_93 ( struct V_48 * V_6 , T_8 V_183 )
{
T_1 * V_8 = F_25 ( V_6 ) ;
V_8 -> V_182 = V_183 ;
}
static int F_94 ( struct V_48 * V_17 , struct V_184 * V_185 , int V_35 )
{
T_2 * V_11 = ( T_2 * ) & V_185 -> V_186 ;
T_1 * V_8 = F_25 ( V_17 ) ;
int V_51 ;
switch ( V_35 ) {
case V_187 :
V_11 [ 0 ] = V_8 -> V_33 ;
case V_187 + 1 :
F_22 ( V_8 , V_11 [ 0 ] , V_11 [ 1 ] & 0x1f , & V_11 [ 3 ] ) ;
V_51 = 0 ;
break;
case V_187 + 2 :
if ( ! F_95 ( V_188 ) )
return - V_146 ;
F_23 ( V_8 , V_8 -> V_33 , V_11 [ 1 ] & 0x1f , & V_11 [ 2 ] ) ;
V_51 = 0 ;
break;
default:
V_51 = - V_189 ;
}
return V_51 ;
}
static void F_96 ( struct V_48 * V_17 )
{
T_1 * V_8 = F_25 ( V_17 ) ;
if ( V_17 -> V_104 & V_190 ) {
V_8 -> V_30 [ V_63 ] |= V_191 ;
F_50 ( V_8 , V_192 , V_17 , L_22 ) ;
} else if ( ! F_97 ( V_17 ) || ( V_17 -> V_104 & V_193 ) ) {
V_8 -> V_30 [ V_28 ] |= V_194 ;
V_8 -> V_30 [ V_63 ] &= ~ V_191 ;
F_8 ( V_8 , V_192 , V_17 , L_23 ) ;
} else {
V_8 -> V_30 [ V_28 ] &= ~ V_194 ;
V_8 -> V_30 [ V_63 ] &= ~ V_191 ;
}
F_12 ( V_8 ) ;
}
static T_3 F_98 ( T_1 * V_8 )
{
int V_36 ;
T_2 V_55 ;
for ( V_36 = 0 ; V_36 < 32 ; V_36 ++ ) {
F_22 ( V_8 , V_36 , V_155 , & V_55 ) ;
if ( V_55 == 0 || V_55 == 0xffff || ( V_55 & V_195 ) == 0 )
continue;
else
return V_36 ;
}
return 0xff ;
}
static inline void F_99 ( T_1 * V_8 )
{
T_3 V_11 = 0xa5 ;
F_11 ( V_8 , V_196 , 0 ) ;
F_11 ( V_8 , V_197 , 1 ) ;
F_100 ( 100 ) ;
if ( ( V_8 -> V_71 & V_78 ) && V_77 )
F_11 ( V_8 , V_197 , 0 ) ;
else
F_11 ( V_8 , V_197 , 2 ) ;
F_11 ( V_8 , 0x83 , V_11 ) ;
F_5 ( V_8 , 0x83 , 1 , & V_11 ) ;
if ( V_11 == 0xa5 )
V_8 -> V_116 = 0x8513 ;
else
V_8 -> V_116 = 0 ;
F_11 ( V_8 , 0x80 , 0xc0 ) ;
F_11 ( V_8 , 0x83 , 0xff ) ;
F_11 ( V_8 , 0x84 , 0x01 ) ;
if ( V_8 -> V_71 & V_78 && V_77 )
F_11 ( V_8 , V_198 , 6 ) ;
else
F_11 ( V_8 , V_198 , 2 ) ;
}
static void F_101 ( struct V_199 * V_200 )
{
T_1 * V_8 = F_102 ( V_200 , T_1 , V_201 . V_200 ) ;
F_65 ( V_8 -> V_17 ) ;
if ( ! ( V_8 -> V_104 & V_123 ) ) {
F_103 ( V_202 , & V_8 -> V_201 ,
V_203 ) ;
}
}
static int F_104 ( struct V_89 * V_204 )
{
struct V_205 * V_206 = & V_204 -> V_207 ;
if ( ( V_206 -> V_208 == F_15 ( V_209 ) ) &&
( V_206 -> V_210 == F_15 ( 0x0121 ) ) &&
( V_206 -> V_211 == V_212 ) &&
( V_206 -> V_213 == 1 ) )
return 1 ;
return 0 ;
}
static void F_105 ( void )
{
V_214 -- ;
if ( V_214 == 0 ) {
F_106 ( V_202 ) ;
V_202 = NULL ;
}
}
static int F_107 ( struct V_215 * V_216 ,
const struct V_217 * V_68 )
{
struct V_89 * V_6 = F_108 ( V_216 ) ;
struct V_48 * V_17 ;
T_1 * V_8 ;
int V_83 = V_68 - V_218 ;
int V_51 = - V_21 ;
if ( F_104 ( V_6 ) )
return - V_31 ;
if ( V_214 == 0 ) {
V_202 = F_109 ( L_24 ) ;
if ( ! V_202 )
return - V_21 ;
}
V_214 ++ ;
V_17 = F_110 ( sizeof( struct V_8 ) ) ;
if ( ! V_17 )
goto V_219;
V_8 = F_25 ( V_17 ) ;
V_8 -> V_83 = V_83 ;
V_51 = F_71 ( V_8 ) ;
if ( V_51 < 0 ) {
F_111 ( & V_216 -> V_6 , L_25 , L_26 ) ;
goto V_220;
}
F_112 ( & V_8 -> V_127 , F_47 , ( unsigned long ) V_8 ) ;
F_113 ( & V_8 -> V_201 , F_101 ) ;
V_8 -> V_216 = V_216 ;
V_8 -> V_13 = V_6 ;
V_8 -> V_17 = V_17 ;
V_17 -> V_221 = V_222 ;
V_17 -> V_223 = & V_224 ;
V_17 -> V_225 = & V_226 ;
V_8 -> V_181 . V_6 = V_17 ;
V_8 -> V_181 . F_24 = F_24 ;
V_8 -> V_181 . F_26 = F_26 ;
V_8 -> V_181 . V_227 = 0x1f ;
V_8 -> V_181 . V_228 = 0x1f ;
V_8 -> V_182 = F_114 ( V_229 , V_230
| V_231 | V_232 ) ;
V_8 -> V_71 = V_82 [ V_83 ] . V_233 ;
F_63 ( V_8 ) ;
if ( F_34 ( V_8 ) ) {
F_111 ( & V_216 -> V_6 , L_27 ) ;
V_51 = - V_161 ;
goto V_234;
}
F_33 ( V_8 ) ;
if ( V_8 -> V_71 & V_72 ) {
F_115 ( & V_216 -> V_6 , L_28 ) ;
F_99 ( V_8 ) ;
}
V_8 -> V_33 = F_98 ( V_8 ) ;
if ( V_8 -> V_33 == 0xff ) {
F_116 ( & V_216 -> V_6 , L_29 ) ;
V_8 -> V_33 = 1 ;
}
V_8 -> V_181 . V_49 = V_8 -> V_33 ;
F_117 ( V_216 , V_8 ) ;
F_118 ( V_17 , & V_216 -> V_6 ) ;
F_83 ( V_17 ) ;
V_51 = F_119 ( V_17 ) ;
if ( V_51 )
goto V_235;
F_103 ( V_202 , & V_8 -> V_201 ,
V_203 ) ;
F_115 ( & V_216 -> V_6 , L_30 , V_17 -> V_236 ,
V_82 [ V_83 ] . V_236 , V_17 -> V_74 ) ;
return 0 ;
V_235:
F_117 ( V_216 , NULL ) ;
V_234:
F_68 ( V_8 ) ;
V_220:
F_120 ( V_17 ) ;
V_219:
F_105 () ;
return V_51 ;
}
static void F_121 ( struct V_215 * V_216 )
{
struct V_8 * V_8 = F_122 ( V_216 ) ;
F_117 ( V_216 , NULL ) ;
if ( ! V_8 ) {
F_2 ( & V_216 -> V_6 , L_31 ) ;
return;
}
V_8 -> V_104 |= V_123 ;
F_123 ( & V_8 -> V_201 ) ;
F_124 ( V_8 -> V_17 ) ;
F_69 ( V_8 ) ;
F_68 ( V_8 ) ;
if ( V_8 -> V_118 != NULL ) {
F_60 ( V_8 -> V_118 ) ;
V_8 -> V_118 = NULL ;
}
F_120 ( V_8 -> V_17 ) ;
F_105 () ;
}
static int F_125 ( struct V_215 * V_216 , T_9 V_237 )
{
struct V_8 * V_8 = F_122 ( V_216 ) ;
F_18 ( V_8 -> V_17 ) ;
F_123 ( & V_8 -> V_201 ) ;
if ( F_38 ( V_8 -> V_17 ) ) {
F_70 ( V_8 -> V_125 ) ;
F_70 ( V_8 -> V_157 ) ;
}
return 0 ;
}
static int F_126 ( struct V_215 * V_216 )
{
struct V_8 * V_8 = F_122 ( V_216 ) ;
F_127 ( V_8 -> V_17 ) ;
if ( F_38 ( V_8 -> V_17 ) ) {
V_8 -> V_125 -> V_5 = 0 ;
V_8 -> V_125 -> V_98 = 0 ;
F_36 ( V_8 -> V_125 ) ;
V_8 -> V_157 -> V_5 = 0 ;
V_8 -> V_157 -> V_98 = 0 ;
F_53 ( V_8 -> V_157 ) ;
}
F_103 ( V_202 , & V_8 -> V_201 ,
V_203 ) ;
return 0 ;
}
static void T_10 F_128 ( char * V_68 )
{
unsigned int V_238 = 0 , V_239 = 0 , V_104 = 0 , V_36 = 0 ;
char * V_240 , * V_236 = NULL ;
if ( ( V_240 = F_129 ( & V_68 , L_32 ) ) != NULL )
V_236 = V_240 ;
if ( ( V_240 = F_129 ( & V_68 , L_32 ) ) != NULL )
V_238 = F_130 ( V_240 , NULL , 16 ) ;
if ( ( V_240 = F_129 ( & V_68 , L_32 ) ) != NULL )
V_239 = F_130 ( V_240 , NULL , 16 ) ;
V_104 = F_130 ( V_68 , NULL , 16 ) ;
F_131 ( L_33 ,
V_165 , V_236 , V_238 , V_239 , V_104 ) ;
if ( V_238 > 0x10000 || V_238 == 0 )
return;
if ( V_239 > 0x10000 || V_239 == 0 )
return;
for ( V_36 = 0 ; V_82 [ V_36 ] . V_236 ; V_36 ++ ) ;
V_82 [ V_36 ] . V_236 = V_236 ;
V_82 [ V_36 ] . V_84 = V_238 ;
V_82 [ V_36 ] . V_241 = V_239 ;
V_82 [ V_36 ] . V_233 = V_104 ;
V_218 [ V_36 ] . V_242 = V_243 ;
V_218 [ V_36 ] . V_208 = V_238 ;
V_218 [ V_36 ] . V_210 = V_239 ;
}
static int T_10 F_132 ( void )
{
F_131 ( L_34 V_244 L_35 , V_165 , V_167 ) ;
if ( V_245 )
F_128 ( V_245 ) ;
return F_133 ( & V_246 ) ;
}
static void T_11 F_134 ( void )
{
F_135 ( & V_246 ) ;
}
