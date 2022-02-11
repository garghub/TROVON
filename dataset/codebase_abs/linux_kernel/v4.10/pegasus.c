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
T_3 * V_12 ;
int V_13 ;
V_12 = F_6 ( V_10 , V_14 ) ;
if ( ! V_12 )
return - V_15 ;
V_13 = F_7 ( V_8 -> V_16 , F_8 ( V_8 -> V_16 , 0 ) ,
V_17 , V_18 , 0 ,
V_9 , V_12 , V_10 , 1000 ) ;
if ( V_13 < 0 )
F_9 ( V_8 , V_19 , V_8 -> V_20 ,
L_2 , V_7 , V_13 ) ;
else if ( V_13 <= V_10 )
memcpy ( V_11 , V_12 , V_13 ) ;
F_3 ( V_12 ) ;
return V_13 ;
}
static int F_10 ( T_1 * V_8 , T_2 V_9 , T_2 V_10 ,
const void * V_11 )
{
T_3 * V_12 ;
int V_13 ;
V_12 = F_11 ( V_11 , V_10 , V_14 ) ;
if ( ! V_12 )
return - V_15 ;
V_13 = F_7 ( V_8 -> V_16 , F_12 ( V_8 -> V_16 , 0 ) ,
V_21 , V_22 , 0 ,
V_9 , V_12 , V_10 , 100 ) ;
if ( V_13 < 0 )
F_9 ( V_8 , V_19 , V_8 -> V_20 ,
L_2 , V_7 , V_13 ) ;
F_3 ( V_12 ) ;
return V_13 ;
}
static int F_13 ( T_1 * V_8 , T_2 V_9 , T_4 V_11 )
{
T_3 * V_12 ;
int V_13 ;
V_12 = F_11 ( & V_11 , 1 , V_14 ) ;
if ( ! V_12 )
return - V_15 ;
V_13 = F_7 ( V_8 -> V_16 , F_12 ( V_8 -> V_16 , 0 ) ,
V_23 , V_22 , V_11 ,
V_9 , V_12 , 1 , 1000 ) ;
if ( V_13 < 0 )
F_9 ( V_8 , V_19 , V_8 -> V_20 ,
L_2 , V_7 , V_13 ) ;
F_3 ( V_12 ) ;
return V_13 ;
}
static int F_14 ( T_1 * V_8 )
{
int V_13 = - V_15 ;
struct V_1 * V_24 ;
struct V_2 * V_3 ;
V_3 = F_6 ( sizeof( struct V_2 ) , V_25 ) ;
if ( V_3 == NULL )
return V_13 ;
V_24 = F_15 ( 0 , V_25 ) ;
if ( V_24 == NULL ) {
F_3 ( V_3 ) ;
return V_13 ;
}
V_3 -> V_26 = V_22 ;
V_3 -> V_27 = V_21 ;
V_3 -> V_28 = F_16 ( 0 ) ;
V_3 -> V_29 = F_16 ( V_30 ) ;
V_3 -> V_31 = F_16 ( 3 ) ;
F_17 ( V_24 , V_8 -> V_16 ,
F_12 ( V_8 -> V_16 , 0 ) , ( void * ) V_3 ,
V_8 -> V_32 , 3 , F_1 , V_3 ) ;
V_13 = F_18 ( V_24 , V_25 ) ;
if ( V_13 ) {
if ( V_13 == - V_33 )
F_19 ( V_8 -> V_20 ) ;
F_20 ( V_8 , V_19 , V_8 -> V_20 ,
L_2 , V_7 , V_13 ) ;
}
return V_13 ;
}
static int F_21 ( T_1 * V_34 , T_4 V_35 , T_4 V_9 , T_2 * V_36 , T_4 V_37 )
{
int V_38 ;
T_4 V_11 [ 4 ] = { V_35 , 0 , 0 , V_9 } ;
T_5 V_39 ;
int V_13 = - V_40 ;
if ( V_37 & V_41 ) {
T_5 * V_42 = ( T_5 * ) & V_11 [ 1 ] ;
* V_42 = F_16 ( * V_36 ) ;
}
F_13 ( V_34 , V_43 , 0 ) ;
F_10 ( V_34 , V_44 , sizeof( V_11 ) , V_11 ) ;
F_13 ( V_34 , V_43 , ( V_9 | V_37 ) ) ;
for ( V_38 = 0 ; V_38 < V_45 ; V_38 ++ ) {
V_13 = F_5 ( V_34 , V_43 , 1 , V_11 ) ;
if ( V_13 < 0 )
goto V_46;
if ( V_11 [ 0 ] & V_47 )
break;
}
if ( V_38 >= V_45 )
goto V_46;
if ( V_37 & V_48 ) {
V_13 = F_5 ( V_34 , V_49 , 2 , & V_39 ) ;
* V_36 = F_22 ( V_39 ) ;
return V_13 ;
}
return 0 ;
V_46:
F_9 ( V_34 , V_19 , V_34 -> V_20 , L_3 , V_7 ) ;
return V_13 ;
}
static int F_23 ( T_1 * V_8 , T_4 V_35 , T_4 V_9 , T_2 * V_36 )
{
return F_21 ( V_8 , V_35 , V_9 , V_36 , V_48 ) ;
}
static int F_24 ( T_1 * V_8 , T_4 V_35 , T_4 V_9 , T_2 * V_36 )
{
return F_21 ( V_8 , V_35 , V_9 , V_36 , V_41 ) ;
}
static int F_25 ( struct V_50 * V_6 , int V_51 , int V_52 )
{
T_1 * V_8 = F_26 ( V_6 ) ;
T_6 V_53 ;
F_23 ( V_8 , V_51 , V_52 , & V_53 ) ;
return ( int ) V_53 ;
}
static void F_27 ( struct V_50 * V_6 , int V_51 , int V_52 , int V_54 )
{
T_1 * V_8 = F_26 ( V_6 ) ;
T_6 V_11 = V_54 ;
F_24 ( V_8 , V_51 , V_52 , & V_11 ) ;
}
static int F_28 ( T_1 * V_8 , T_4 V_55 , T_2 * V_56 )
{
int V_38 ;
T_4 V_57 ;
T_5 V_58 ;
int V_13 ;
F_13 ( V_8 , V_59 , 0 ) ;
F_13 ( V_8 , V_60 , V_55 ) ;
F_13 ( V_8 , V_59 , V_61 ) ;
for ( V_38 = 0 ; V_38 < V_45 ; V_38 ++ ) {
V_13 = F_5 ( V_8 , V_59 , 1 , & V_57 ) ;
if ( V_57 & V_62 )
break;
if ( V_13 == - V_63 )
goto V_46;
}
if ( V_38 >= V_45 )
goto V_46;
V_13 = F_5 ( V_8 , V_64 , 2 , & V_58 ) ;
* V_56 = F_22 ( V_58 ) ;
return V_13 ;
V_46:
F_29 ( V_8 , V_19 , V_8 -> V_20 , L_3 , V_7 ) ;
return - V_40 ;
}
static inline void F_30 ( T_1 * V_8 )
{
T_4 V_57 ;
F_5 ( V_8 , V_65 , 1 , & V_57 ) ;
F_13 ( V_8 , V_65 , V_57 | V_66 ) ;
}
static inline void F_31 ( T_1 * V_8 )
{
T_4 V_57 ;
F_5 ( V_8 , V_65 , 1 , & V_57 ) ;
F_13 ( V_8 , V_59 , 0 ) ;
F_13 ( V_8 , V_65 , V_57 & ~ V_66 ) ;
}
static int F_32 ( T_1 * V_8 , T_4 V_55 , T_2 V_11 )
{
int V_38 ;
T_4 V_57 , V_67 [ 4 ] = { 0x3f , 0 , 0 , V_68 } ;
int V_13 ;
T_5 V_69 = F_16 ( V_11 ) ;
F_10 ( V_8 , V_60 , 4 , V_67 ) ;
F_30 ( V_8 ) ;
F_13 ( V_8 , V_60 , V_55 ) ;
F_10 ( V_8 , V_64 , 2 , & V_69 ) ;
F_13 ( V_8 , V_59 , V_68 ) ;
for ( V_38 = 0 ; V_38 < V_45 ; V_38 ++ ) {
V_13 = F_5 ( V_8 , V_59 , 1 , & V_57 ) ;
if ( V_13 == - V_63 )
goto V_46;
if ( V_57 & V_62 )
break;
}
F_31 ( V_8 ) ;
if ( V_38 >= V_45 )
goto V_46;
return V_13 ;
V_46:
F_29 ( V_8 , V_19 , V_8 -> V_20 , L_3 , V_7 ) ;
return - V_40 ;
}
static inline void F_33 ( T_1 * V_8 , T_4 * V_70 )
{
int V_38 ;
T_2 V_71 ;
for ( V_38 = 0 ; V_38 < 3 ; V_38 ++ ) {
F_28 ( V_8 , V_38 , & V_71 ) ;
( ( T_5 * ) V_70 ) [ V_38 ] = F_16 ( V_71 ) ;
}
}
static void F_34 ( T_1 * V_8 )
{
T_4 V_72 [ 6 ] ;
if ( V_8 -> V_73 & V_74 ) {
F_5 ( V_8 , 0x10 , sizeof( V_72 ) , V_72 ) ;
} else {
F_33 ( V_8 , V_72 ) ;
F_10 ( V_8 , V_75 , sizeof( V_72 ) , V_72 ) ;
}
memcpy ( V_8 -> V_20 -> V_76 , V_72 , sizeof( V_72 ) ) ;
}
static inline int F_35 ( T_1 * V_8 )
{
T_4 V_11 = 0x8 ;
int V_38 ;
F_13 ( V_8 , V_77 , V_11 ) ;
for ( V_38 = 0 ; V_38 < V_45 ; V_38 ++ ) {
F_5 ( V_8 , V_77 , 1 , & V_11 ) ;
if ( ~ V_11 & 0x08 ) {
if ( V_78 )
break;
if ( V_79 && ( V_8 -> V_73 & V_80 ) )
F_13 ( V_8 , V_81 , 0x34 ) ;
else
F_13 ( V_8 , V_81 , 0x26 ) ;
F_13 ( V_8 , V_82 , V_8 -> V_73 ) ;
F_13 ( V_8 , V_82 , V_83 ) ;
break;
}
}
if ( V_38 == V_45 )
return - V_40 ;
if ( V_84 [ V_8 -> V_85 ] . V_86 == V_87 ||
V_84 [ V_8 -> V_85 ] . V_86 == V_88 ) {
F_13 ( V_8 , V_82 , 0x24 ) ;
F_13 ( V_8 , V_82 , 0x26 ) ;
}
if ( V_84 [ V_8 -> V_85 ] . V_86 == V_89 ) {
T_2 V_90 ;
F_23 ( V_8 , 3 , 0x1b , & V_90 ) ;
V_90 |= 4 ;
F_24 ( V_8 , 3 , 0x1b , & V_90 ) ;
}
return 0 ;
}
static int F_36 ( struct V_50 * V_6 , struct V_91 * V_16 )
{
T_2 V_92 ;
T_4 V_11 [ 4 ] ;
T_1 * V_8 = F_26 ( V_6 ) ;
int V_13 ;
F_23 ( V_8 , V_8 -> V_35 , V_93 , & V_92 ) ;
V_11 [ 0 ] = 0xc8 ;
V_11 [ 1 ] = 0 ;
if ( V_92 & ( V_94 | V_95 ) )
V_11 [ 1 ] |= 0x20 ;
if ( V_92 & ( V_94 | V_96 ) )
V_11 [ 1 ] |= 0x10 ;
if ( V_79 )
V_11 [ 1 ] = 0 ;
V_11 [ 2 ] = V_78 ? 0x09 : 0x01 ;
memcpy ( V_8 -> V_32 , V_11 , sizeof( V_11 ) ) ;
V_13 = F_10 ( V_8 , V_30 , 3 , V_11 ) ;
if ( V_84 [ V_8 -> V_85 ] . V_86 == V_87 ||
V_84 [ V_8 -> V_85 ] . V_86 == V_97 ||
V_84 [ V_8 -> V_85 ] . V_86 == V_88 ) {
T_6 V_90 ;
F_23 ( V_8 , 0 , 0x1b , & V_90 ) ;
V_90 |= 4 ;
F_24 ( V_8 , 0 , 0x1b , & V_90 ) ;
}
return V_13 ;
}
static void F_37 ( struct V_1 * V_1 )
{
T_1 * V_8 = V_1 -> V_4 ;
struct V_50 * V_20 ;
int V_98 , V_99 = V_1 -> V_100 ;
int V_5 = V_1 -> V_5 ;
T_3 * V_12 = V_1 -> V_101 ;
T_2 V_102 ;
if ( ! V_8 )
return;
V_20 = V_8 -> V_20 ;
if ( ! F_38 ( V_20 ) || ! F_39 ( V_20 ) )
return;
switch ( V_5 ) {
case 0 :
break;
case - V_103 :
F_9 ( V_8 , V_104 , V_20 , L_4 ) ;
V_8 -> V_105 &= ~ V_106 ;
break;
case - V_107 :
F_29 ( V_8 , V_104 , V_20 , L_5 ) ;
return;
case - V_108 :
case - V_109 :
case - V_63 :
F_9 ( V_8 , V_110 , V_20 , L_6 , V_5 ) ;
return;
default:
F_9 ( V_8 , V_104 , V_20 , L_7 , V_5 ) ;
goto V_111;
}
if ( V_99 < 4 )
goto V_111;
V_98 = V_12 [ V_99 - 2 ] ;
if ( V_98 & 0x1e ) {
F_9 ( V_8 , V_104 , V_20 ,
L_8 , V_98 ) ;
V_8 -> V_112 . V_113 ++ ;
if ( V_98 & 0x06 )
V_8 -> V_112 . V_114 ++ ;
if ( V_98 & 0x08 )
V_8 -> V_112 . V_115 ++ ;
if ( V_98 & 0x10 )
V_8 -> V_112 . V_116 ++ ;
goto V_111;
}
if ( V_8 -> V_117 == 0x8513 ) {
V_102 = F_40 ( * ( V_118 * ) V_1 -> V_101 ) ;
V_102 &= 0x0fff ;
V_8 -> V_119 -> V_11 += 2 ;
} else {
V_102 = V_12 [ V_99 - 3 ] << 8 ;
V_102 += V_12 [ V_99 - 4 ] ;
V_102 &= 0xfff ;
V_102 -= 4 ;
}
if ( V_102 > V_120 )
goto V_111;
F_41 ( V_8 -> V_119 , V_102 ) ;
V_8 -> V_119 -> V_121 = F_42 ( V_8 -> V_119 , V_20 ) ;
F_43 ( V_8 -> V_119 ) ;
V_8 -> V_112 . V_122 ++ ;
V_8 -> V_112 . V_123 += V_102 ;
if ( V_8 -> V_105 & V_124 )
return;
V_8 -> V_119 = F_44 ( V_8 -> V_20 , V_120 ,
V_25 ) ;
if ( V_8 -> V_119 == NULL )
goto V_125;
V_111:
F_45 ( V_8 -> V_126 , V_8 -> V_16 ,
F_46 ( V_8 -> V_16 , 1 ) ,
V_8 -> V_119 -> V_11 , V_120 ,
F_37 , V_8 ) ;
V_98 = F_18 ( V_8 -> V_126 , V_25 ) ;
if ( V_98 == - V_33 )
F_19 ( V_8 -> V_20 ) ;
else if ( V_98 ) {
V_8 -> V_105 |= V_127 ;
goto V_125;
} else {
V_8 -> V_105 &= ~ V_127 ;
}
return;
V_125:
F_47 ( & V_8 -> V_128 ) ;
}
static void F_48 ( unsigned long V_11 )
{
T_1 * V_8 ;
int V_5 ;
V_8 = ( T_1 * ) V_11 ;
if ( V_8 -> V_105 & V_124 )
return;
if ( V_8 -> V_105 & V_127 )
if ( V_8 -> V_119 )
goto V_129;
if ( V_8 -> V_119 == NULL )
V_8 -> V_119 = F_44 ( V_8 -> V_20 ,
V_120 ,
V_25 ) ;
if ( V_8 -> V_119 == NULL ) {
F_29 ( V_8 , V_104 , V_8 -> V_20 , L_9 ) ;
F_47 ( & V_8 -> V_128 ) ;
return;
}
F_45 ( V_8 -> V_126 , V_8 -> V_16 ,
F_46 ( V_8 -> V_16 , 1 ) ,
V_8 -> V_119 -> V_11 , V_120 ,
F_37 , V_8 ) ;
V_129:
V_5 = F_18 ( V_8 -> V_126 , V_25 ) ;
if ( V_5 == - V_33 )
F_19 ( V_8 -> V_20 ) ;
else if ( V_5 ) {
V_8 -> V_105 |= V_127 ;
F_47 ( & V_8 -> V_128 ) ;
} else {
V_8 -> V_105 &= ~ V_127 ;
}
}
static void F_49 ( struct V_1 * V_1 )
{
T_1 * V_8 = V_1 -> V_4 ;
struct V_50 * V_20 ;
int V_5 = V_1 -> V_5 ;
if ( ! V_8 )
return;
V_20 = V_8 -> V_20 ;
if ( ! F_38 ( V_20 ) || ! F_39 ( V_20 ) )
return;
switch ( V_5 ) {
case - V_107 :
F_50 ( V_20 ) ;
F_29 ( V_8 , V_130 , V_20 , L_10 ) ;
return;
case - V_108 :
case - V_109 :
case - V_63 :
F_9 ( V_8 , V_110 , V_20 , L_11 , V_5 ) ;
return;
default:
F_51 ( V_8 , V_130 , V_20 , L_12 , V_5 ) ;
case 0 :
break;
}
F_52 ( V_20 ) ;
F_53 ( V_20 ) ;
}
static void F_54 ( struct V_1 * V_1 )
{
T_1 * V_8 = V_1 -> V_4 ;
struct V_50 * V_20 ;
int V_53 , V_5 = V_1 -> V_5 ;
if ( ! V_8 )
return;
V_20 = V_8 -> V_20 ;
switch ( V_5 ) {
case 0 :
break;
case - V_109 :
case - V_108 :
case - V_63 :
return;
default:
F_9 ( V_8 , V_131 , V_20 , L_13 , V_5 ) ;
}
if ( V_1 -> V_100 >= 6 ) {
T_3 * V_67 = V_1 -> V_101 ;
if ( V_67 [ 0 ] & ( V_132 | V_133
| V_134 | V_135 ) ) {
V_8 -> V_112 . V_136 ++ ;
if ( V_67 [ 0 ] & V_132 )
V_8 -> V_112 . V_137 ++ ;
if ( V_67 [ 0 ] & ( V_133 | V_135 ) )
V_8 -> V_112 . V_138 ++ ;
if ( V_67 [ 0 ] & V_134 )
V_8 -> V_112 . V_139 ++ ;
}
V_8 -> V_112 . V_140 += ( ( V_67 [ 3 ] & 0x7f ) << 8 ) | V_67 [ 4 ] ;
}
V_53 = F_18 ( V_1 , V_25 ) ;
if ( V_53 == - V_33 )
F_19 ( V_8 -> V_20 ) ;
if ( V_53 )
F_20 ( V_8 , V_131 , V_20 ,
L_14 , V_53 ) ;
}
static void F_55 ( struct V_50 * V_20 )
{
T_1 * V_8 = F_26 ( V_20 ) ;
F_29 ( V_8 , V_131 , V_20 , L_15 ) ;
F_56 ( V_8 -> V_141 ) ;
V_8 -> V_112 . V_136 ++ ;
}
static T_7 F_57 ( struct V_142 * V_143 ,
struct V_50 * V_20 )
{
T_1 * V_8 = F_26 ( V_20 ) ;
int V_99 = ( ( V_143 -> V_144 + 2 ) & 0x3f ) ? V_143 -> V_144 + 2 : V_143 -> V_144 + 3 ;
int V_53 ;
T_2 V_145 = V_143 -> V_144 ;
F_50 ( V_20 ) ;
( ( T_5 * ) V_8 -> V_146 ) [ 0 ] = F_16 ( V_145 ) ;
F_58 ( V_143 , V_8 -> V_146 + 2 , V_143 -> V_144 ) ;
F_45 ( V_8 -> V_141 , V_8 -> V_16 ,
F_59 ( V_8 -> V_16 , 2 ) ,
V_8 -> V_146 , V_99 ,
F_49 , V_8 ) ;
if ( ( V_53 = F_18 ( V_8 -> V_141 , V_25 ) ) ) {
F_29 ( V_8 , V_130 , V_20 , L_16 , V_53 ) ;
switch ( V_53 ) {
case - V_107 :
break;
case - V_33 :
case - V_147 :
F_19 ( V_8 -> V_20 ) ;
break;
default:
V_8 -> V_112 . V_136 ++ ;
F_60 ( V_20 ) ;
}
} else {
V_8 -> V_112 . V_148 ++ ;
V_8 -> V_112 . V_149 += V_143 -> V_144 ;
}
F_61 ( V_143 ) ;
return V_150 ;
}
static struct V_151 * F_62 ( struct V_50 * V_6 )
{
return & ( ( T_1 * ) F_26 ( V_6 ) ) -> V_112 ;
}
static inline void F_63 ( T_1 * V_8 )
{
T_5 V_57 = F_16 ( 0 ) ;
F_10 ( V_8 , V_30 , sizeof( V_57 ) , & V_57 ) ;
}
static inline void F_64 ( T_1 * V_8 )
{
T_6 V_11 ;
T_3 V_152 ;
F_28 ( V_8 , 4 , & V_11 ) ;
V_152 = V_11 >> 8 ;
if ( V_8 -> V_16 -> V_153 != V_154 ) {
if ( V_152 < 0x80 ) {
F_51 ( V_8 , V_131 , V_8 -> V_20 ,
L_17 ,
V_152 , 0x80 ) ;
V_152 = 0x80 ;
V_11 = ( V_11 & 0x00FF ) | ( ( T_6 ) V_152 << 8 ) ;
#ifdef F_65
F_32 ( V_8 , 4 , V_11 ) ;
#endif
}
}
V_8 -> V_155 = V_152 ;
}
static void F_66 ( struct V_50 * V_20 )
{
T_1 * V_8 = F_26 ( V_20 ) ;
T_6 V_57 ;
if ( F_23 ( V_8 , V_8 -> V_35 , V_156 , & V_57 ) )
return;
if ( V_57 & V_157 )
F_67 ( V_20 ) ;
else
F_68 ( V_20 ) ;
}
static void F_69 ( T_1 * V_8 )
{
F_4 ( V_8 -> V_158 ) ;
F_4 ( V_8 -> V_141 ) ;
F_4 ( V_8 -> V_126 ) ;
}
static void F_70 ( T_1 * V_8 )
{
F_71 ( V_8 -> V_158 ) ;
F_71 ( V_8 -> V_141 ) ;
F_71 ( V_8 -> V_126 ) ;
}
static int F_72 ( T_1 * V_8 )
{
int V_53 = - V_15 ;
V_8 -> V_126 = F_15 ( 0 , V_159 ) ;
if ( ! V_8 -> V_126 ) {
return V_53 ;
}
V_8 -> V_141 = F_15 ( 0 , V_159 ) ;
if ( ! V_8 -> V_141 ) {
F_4 ( V_8 -> V_126 ) ;
return V_53 ;
}
V_8 -> V_158 = F_15 ( 0 , V_159 ) ;
if ( ! V_8 -> V_158 ) {
F_4 ( V_8 -> V_141 ) ;
F_4 ( V_8 -> V_126 ) ;
return V_53 ;
}
return 0 ;
}
static int F_73 ( struct V_50 * V_20 )
{
T_1 * V_8 = F_26 ( V_20 ) ;
int V_53 = - V_15 ;
if ( V_8 -> V_119 == NULL )
V_8 -> V_119 = F_44 ( V_8 -> V_20 ,
V_120 ,
V_159 ) ;
if ( ! V_8 -> V_119 )
goto exit;
V_53 = F_10 ( V_8 , V_75 , 6 , V_20 -> V_76 ) ;
F_45 ( V_8 -> V_126 , V_8 -> V_16 ,
F_46 ( V_8 -> V_16 , 1 ) ,
V_8 -> V_119 -> V_11 , V_120 ,
F_37 , V_8 ) ;
if ( ( V_53 = F_18 ( V_8 -> V_126 , V_159 ) ) ) {
if ( V_53 == - V_33 )
F_19 ( V_8 -> V_20 ) ;
F_9 ( V_8 , V_160 , V_20 , L_18 , V_53 ) ;
goto exit;
}
F_74 ( V_8 -> V_158 , V_8 -> V_16 ,
F_75 ( V_8 -> V_16 , 3 ) ,
V_8 -> V_161 , sizeof( V_8 -> V_161 ) ,
F_54 , V_8 , V_8 -> V_155 ) ;
if ( ( V_53 = F_18 ( V_8 -> V_158 , V_159 ) ) ) {
if ( V_53 == - V_33 )
F_19 ( V_8 -> V_20 ) ;
F_9 ( V_8 , V_160 , V_20 , L_19 , V_53 ) ;
F_71 ( V_8 -> V_126 ) ;
goto exit;
}
V_53 = F_36 ( V_20 , V_8 -> V_16 ) ;
if ( V_53 < 0 ) {
F_9 ( V_8 , V_160 , V_20 ,
L_20 , V_53 ) ;
V_53 = - V_162 ;
F_71 ( V_8 -> V_126 ) ;
F_71 ( V_8 -> V_158 ) ;
goto exit;
}
F_66 ( V_20 ) ;
F_60 ( V_20 ) ;
F_9 ( V_8 , V_160 , V_20 , L_21 ) ;
V_53 = 0 ;
exit:
return V_53 ;
}
static int F_76 ( struct V_50 * V_20 )
{
T_1 * V_8 = F_26 ( V_20 ) ;
F_50 ( V_20 ) ;
if ( ! ( V_8 -> V_105 & V_124 ) )
F_63 ( V_8 ) ;
F_77 ( & V_8 -> V_128 ) ;
F_70 ( V_8 ) ;
return 0 ;
}
static void F_78 ( struct V_50 * V_6 ,
struct V_163 * V_164 )
{
T_1 * V_8 = F_26 ( V_6 ) ;
F_79 ( V_164 -> V_165 , V_166 , sizeof( V_164 -> V_165 ) ) ;
F_79 ( V_164 -> V_167 , V_168 , sizeof( V_164 -> V_167 ) ) ;
F_80 ( V_8 -> V_16 , V_164 -> V_169 , sizeof( V_164 -> V_169 ) ) ;
}
static void
F_81 ( struct V_50 * V_6 , struct V_170 * V_171 )
{
T_1 * V_8 = F_26 ( V_6 ) ;
V_171 -> V_172 = V_173 | V_174 ;
V_171 -> V_175 = V_8 -> V_175 ;
}
static int
F_82 ( struct V_50 * V_6 , struct V_170 * V_171 )
{
T_1 * V_8 = F_26 ( V_6 ) ;
T_3 V_176 = 0x04 ;
int V_13 ;
if ( V_171 -> V_175 & ~ V_177 )
return - V_178 ;
if ( V_171 -> V_175 & V_173 )
V_176 |= 0x80 ;
if ( V_171 -> V_175 & V_174 )
V_176 |= 0x40 ;
if ( V_171 -> V_175 )
V_8 -> V_32 [ 0 ] |= 0x10 ;
else
V_8 -> V_32 [ 0 ] &= ~ 0x10 ;
V_8 -> V_175 = V_171 -> V_175 ;
V_13 = F_13 ( V_8 , V_179 , V_176 ) ;
if ( ! V_13 )
V_13 = F_83 ( & V_8 -> V_16 -> V_6 ,
V_171 -> V_175 ) ;
return V_13 ;
}
static inline void F_84 ( struct V_50 * V_6 )
{
struct V_170 V_171 ;
memset ( & V_171 , 0 , sizeof V_171 ) ;
( void ) F_82 ( V_6 , & V_171 ) ;
}
static int
F_85 ( struct V_50 * V_6 , struct V_180 * V_181 )
{
T_1 * V_8 ;
V_8 = F_26 ( V_6 ) ;
F_86 ( & V_8 -> V_182 , V_181 ) ;
return 0 ;
}
static int
F_87 ( struct V_50 * V_6 , struct V_180 * V_181 )
{
T_1 * V_8 = F_26 ( V_6 ) ;
return F_88 ( & V_8 -> V_182 , V_181 ) ;
}
static int F_89 ( struct V_50 * V_6 )
{
T_1 * V_8 = F_26 ( V_6 ) ;
return F_90 ( & V_8 -> V_182 ) ;
}
static T_8 F_91 ( struct V_50 * V_6 )
{
T_1 * V_8 = F_26 ( V_6 ) ;
return F_92 ( & V_8 -> V_182 ) ;
}
static T_8 F_93 ( struct V_50 * V_6 )
{
T_1 * V_8 = F_26 ( V_6 ) ;
return V_8 -> V_183 ;
}
static void F_94 ( struct V_50 * V_6 , T_8 V_184 )
{
T_1 * V_8 = F_26 ( V_6 ) ;
V_8 -> V_183 = V_184 ;
}
static int F_95 ( struct V_50 * V_20 , struct V_185 * V_186 , int V_37 )
{
T_2 * V_11 = ( T_2 * ) & V_186 -> V_187 ;
T_1 * V_8 = F_26 ( V_20 ) ;
int V_53 ;
switch ( V_37 ) {
case V_188 :
V_11 [ 0 ] = V_8 -> V_35 ;
case V_188 + 1 :
F_23 ( V_8 , V_11 [ 0 ] , V_11 [ 1 ] & 0x1f , & V_11 [ 3 ] ) ;
V_53 = 0 ;
break;
case V_188 + 2 :
if ( ! F_96 ( V_189 ) )
return - V_147 ;
F_24 ( V_8 , V_8 -> V_35 , V_11 [ 1 ] & 0x1f , & V_11 [ 2 ] ) ;
V_53 = 0 ;
break;
default:
V_53 = - V_190 ;
}
return V_53 ;
}
static void F_97 ( struct V_50 * V_20 )
{
T_1 * V_8 = F_26 ( V_20 ) ;
if ( V_20 -> V_105 & V_191 ) {
V_8 -> V_32 [ V_65 ] |= V_192 ;
F_51 ( V_8 , V_193 , V_20 , L_22 ) ;
} else if ( ! F_98 ( V_20 ) || ( V_20 -> V_105 & V_194 ) ) {
V_8 -> V_32 [ V_30 ] |= V_195 ;
V_8 -> V_32 [ V_65 ] &= ~ V_192 ;
F_9 ( V_8 , V_193 , V_20 , L_23 ) ;
} else {
V_8 -> V_32 [ V_30 ] &= ~ V_195 ;
V_8 -> V_32 [ V_65 ] &= ~ V_192 ;
}
F_14 ( V_8 ) ;
}
static T_4 F_99 ( T_1 * V_8 )
{
int V_38 ;
T_2 V_57 ;
for ( V_38 = 0 ; V_38 < 32 ; V_38 ++ ) {
F_23 ( V_8 , V_38 , V_156 , & V_57 ) ;
if ( V_57 == 0 || V_57 == 0xffff || ( V_57 & V_196 ) == 0 )
continue;
else
return V_38 ;
}
return 0xff ;
}
static inline void F_100 ( T_1 * V_8 )
{
T_4 V_11 = 0xa5 ;
F_13 ( V_8 , V_197 , 0 ) ;
F_13 ( V_8 , V_198 , 1 ) ;
F_101 ( 100 ) ;
if ( ( V_8 -> V_73 & V_80 ) && V_79 )
F_13 ( V_8 , V_198 , 0 ) ;
else
F_13 ( V_8 , V_198 , 2 ) ;
F_13 ( V_8 , 0x83 , V_11 ) ;
F_5 ( V_8 , 0x83 , 1 , & V_11 ) ;
if ( V_11 == 0xa5 )
V_8 -> V_117 = 0x8513 ;
else
V_8 -> V_117 = 0 ;
F_13 ( V_8 , 0x80 , 0xc0 ) ;
F_13 ( V_8 , 0x83 , 0xff ) ;
F_13 ( V_8 , 0x84 , 0x01 ) ;
if ( V_8 -> V_73 & V_80 && V_79 )
F_13 ( V_8 , V_199 , 6 ) ;
else
F_13 ( V_8 , V_199 , 2 ) ;
}
static void F_102 ( struct V_200 * V_201 )
{
T_1 * V_8 = F_103 ( V_201 , T_1 , V_202 . V_201 ) ;
F_66 ( V_8 -> V_20 ) ;
if ( ! ( V_8 -> V_105 & V_124 ) ) {
F_104 ( V_203 , & V_8 -> V_202 ,
V_204 ) ;
}
}
static int F_105 ( struct V_91 * V_205 )
{
struct V_206 * V_207 = & V_205 -> V_208 ;
if ( ( V_207 -> V_209 == F_16 ( V_210 ) ) &&
( V_207 -> V_211 == F_16 ( 0x0121 ) ) &&
( V_207 -> V_212 == V_213 ) &&
( V_207 -> V_214 == 1 ) )
return 1 ;
return 0 ;
}
static void F_106 ( void )
{
V_215 -- ;
if ( V_215 == 0 ) {
F_107 ( V_203 ) ;
V_203 = NULL ;
}
}
static int F_108 ( struct V_216 * V_217 ,
const struct V_218 * V_70 )
{
struct V_91 * V_6 = F_109 ( V_217 ) ;
struct V_50 * V_20 ;
T_1 * V_8 ;
int V_85 = V_70 - V_219 ;
int V_53 = - V_15 ;
if ( F_105 ( V_6 ) )
return - V_33 ;
if ( V_215 == 0 ) {
V_203 = F_110 ( L_24 , V_220 ,
0 ) ;
if ( ! V_203 )
return - V_15 ;
}
V_215 ++ ;
V_20 = F_111 ( sizeof( struct V_8 ) ) ;
if ( ! V_20 )
goto V_221;
V_8 = F_26 ( V_20 ) ;
V_8 -> V_85 = V_85 ;
V_53 = F_72 ( V_8 ) ;
if ( V_53 < 0 ) {
F_112 ( & V_217 -> V_6 , L_25 , L_26 ) ;
goto V_222;
}
F_113 ( & V_8 -> V_128 , F_48 , ( unsigned long ) V_8 ) ;
F_114 ( & V_8 -> V_202 , F_102 ) ;
V_8 -> V_217 = V_217 ;
V_8 -> V_16 = V_6 ;
V_8 -> V_20 = V_20 ;
V_20 -> V_223 = V_224 ;
V_20 -> V_225 = & V_226 ;
V_20 -> V_227 = & V_228 ;
V_8 -> V_182 . V_6 = V_20 ;
V_8 -> V_182 . F_25 = F_25 ;
V_8 -> V_182 . F_27 = F_27 ;
V_8 -> V_182 . V_229 = 0x1f ;
V_8 -> V_182 . V_230 = 0x1f ;
V_8 -> V_183 = F_115 ( V_231 , V_232
| V_233 | V_234 ) ;
V_8 -> V_73 = V_84 [ V_85 ] . V_235 ;
F_64 ( V_8 ) ;
if ( F_35 ( V_8 ) ) {
F_112 ( & V_217 -> V_6 , L_27 ) ;
V_53 = - V_162 ;
goto V_236;
}
F_34 ( V_8 ) ;
if ( V_8 -> V_73 & V_74 ) {
F_116 ( & V_217 -> V_6 , L_28 ) ;
F_100 ( V_8 ) ;
}
V_8 -> V_35 = F_99 ( V_8 ) ;
if ( V_8 -> V_35 == 0xff ) {
F_117 ( & V_217 -> V_6 , L_29 ) ;
V_8 -> V_35 = 1 ;
}
V_8 -> V_182 . V_51 = V_8 -> V_35 ;
F_118 ( V_217 , V_8 ) ;
F_119 ( V_20 , & V_217 -> V_6 ) ;
F_84 ( V_20 ) ;
V_53 = F_120 ( V_20 ) ;
if ( V_53 )
goto V_237;
F_104 ( V_203 , & V_8 -> V_202 ,
V_204 ) ;
F_116 ( & V_217 -> V_6 , L_30 , V_20 -> V_238 ,
V_84 [ V_85 ] . V_238 , V_20 -> V_76 ) ;
return 0 ;
V_237:
F_118 ( V_217 , NULL ) ;
V_236:
F_69 ( V_8 ) ;
V_222:
F_121 ( V_20 ) ;
V_221:
F_106 () ;
return V_53 ;
}
static void F_122 ( struct V_216 * V_217 )
{
struct V_8 * V_8 = F_123 ( V_217 ) ;
F_118 ( V_217 , NULL ) ;
if ( ! V_8 ) {
F_2 ( & V_217 -> V_6 , L_31 ) ;
return;
}
V_8 -> V_105 |= V_124 ;
F_124 ( & V_8 -> V_202 ) ;
F_125 ( V_8 -> V_20 ) ;
F_70 ( V_8 ) ;
F_69 ( V_8 ) ;
if ( V_8 -> V_119 != NULL ) {
F_61 ( V_8 -> V_119 ) ;
V_8 -> V_119 = NULL ;
}
F_121 ( V_8 -> V_20 ) ;
F_106 () ;
}
static int F_126 ( struct V_216 * V_217 , T_9 V_239 )
{
struct V_8 * V_8 = F_123 ( V_217 ) ;
F_19 ( V_8 -> V_20 ) ;
F_124 ( & V_8 -> V_202 ) ;
if ( F_39 ( V_8 -> V_20 ) ) {
F_71 ( V_8 -> V_126 ) ;
F_71 ( V_8 -> V_158 ) ;
}
return 0 ;
}
static int F_127 ( struct V_216 * V_217 )
{
struct V_8 * V_8 = F_123 ( V_217 ) ;
F_128 ( V_8 -> V_20 ) ;
if ( F_39 ( V_8 -> V_20 ) ) {
V_8 -> V_126 -> V_5 = 0 ;
V_8 -> V_126 -> V_100 = 0 ;
F_37 ( V_8 -> V_126 ) ;
V_8 -> V_158 -> V_5 = 0 ;
V_8 -> V_158 -> V_100 = 0 ;
F_54 ( V_8 -> V_158 ) ;
}
F_104 ( V_203 , & V_8 -> V_202 ,
V_204 ) ;
return 0 ;
}
static void T_10 F_129 ( char * V_70 )
{
unsigned int V_240 = 0 , V_241 = 0 , V_105 = 0 , V_38 = 0 ;
char * V_242 , * V_238 = NULL ;
if ( ( V_242 = F_130 ( & V_70 , L_32 ) ) != NULL )
V_238 = V_242 ;
if ( ( V_242 = F_130 ( & V_70 , L_32 ) ) != NULL )
V_240 = F_131 ( V_242 , NULL , 16 ) ;
if ( ( V_242 = F_130 ( & V_70 , L_32 ) ) != NULL )
V_241 = F_131 ( V_242 , NULL , 16 ) ;
V_105 = F_131 ( V_70 , NULL , 16 ) ;
F_132 ( L_33 ,
V_166 , V_238 , V_240 , V_241 , V_105 ) ;
if ( V_240 > 0x10000 || V_240 == 0 )
return;
if ( V_241 > 0x10000 || V_241 == 0 )
return;
for ( V_38 = 0 ; V_84 [ V_38 ] . V_238 ; V_38 ++ ) ;
V_84 [ V_38 ] . V_238 = V_238 ;
V_84 [ V_38 ] . V_86 = V_240 ;
V_84 [ V_38 ] . V_243 = V_241 ;
V_84 [ V_38 ] . V_235 = V_105 ;
V_219 [ V_38 ] . V_244 = V_245 ;
V_219 [ V_38 ] . V_209 = V_240 ;
V_219 [ V_38 ] . V_211 = V_241 ;
}
static int T_10 F_133 ( void )
{
F_132 ( L_34 V_246 L_35 , V_166 , V_168 ) ;
if ( V_247 )
F_129 ( V_247 ) ;
return F_134 ( & V_248 ) ;
}
static void T_11 F_135 ( void )
{
F_136 ( & V_248 ) ;
}
