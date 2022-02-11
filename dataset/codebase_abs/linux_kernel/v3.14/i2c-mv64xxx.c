static void
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 = 0 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_6 = 0 ;
V_2 -> V_7 = V_4 -> V_8 ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = 0 ;
V_2 -> V_11 = V_12 |
V_13 | V_14 ;
if ( V_4 -> V_15 & V_16 )
V_5 = 1 ;
if ( V_4 -> V_15 & V_17 ) {
V_2 -> V_18 = 0xf0 | ( ( ( T_1 ) V_4 -> V_19 & 0x300 ) >> 7 ) | V_5 ;
V_2 -> V_20 = ( T_1 ) V_4 -> V_19 & 0xff ;
} else {
V_2 -> V_18 = F_2 ( ( T_1 ) V_4 -> V_19 ) | V_5 ;
V_2 -> V_20 = 0 ;
}
}
static int F_3 ( struct V_1 * V_2 )
{
unsigned long V_21 = 0 ;
unsigned long V_22 = 0 ;
unsigned long V_23 ;
struct V_3 * V_4 = V_2 -> V_24 ;
if ( ! V_2 -> V_25 )
return - V_26 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_6 = 0 ;
V_2 -> V_7 = V_4 -> V_8 ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = 0 ;
if ( ( V_4 -> V_15 & ~ ( V_17 | V_16 ) ) != 0 )
return - V_27 ;
if ( V_4 -> V_8 < 1 || V_4 -> V_8 > 8 )
return - V_27 ;
V_23 = V_28 |
( V_4 -> V_19 << V_29 ) ;
if ( ( V_4 -> V_15 & V_17 ) != 0 )
V_23 |= V_30 ;
if ( ( V_4 -> V_15 & V_16 ) == 0 ) {
T_2 V_31 [ 8 ] = { 0 } ;
memcpy ( V_31 , V_4 -> V_32 , V_4 -> V_8 ) ;
V_22 = F_4 ( * ( ( T_1 * ) V_31 ) ) ;
V_21 = F_4 ( * ( ( T_1 * ) ( V_31 + 4 ) ) ) ;
V_23 |= V_33 |
( V_4 -> V_8 - 1 ) << V_34 ;
F_5 ( V_22 ,
V_2 -> V_35 + V_36 ) ;
F_5 ( V_21 ,
V_2 -> V_35 + V_37 ) ;
} else {
V_23 |= V_38 |
( V_4 -> V_8 - 1 ) << V_39 ;
}
F_5 ( V_23 , V_2 -> V_35 + V_40 ) ;
return 0 ;
}
static void
F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_15 & V_16 ) {
T_1 V_22 = F_7 ( V_2 -> V_35 +
V_41 ) ;
T_1 V_21 = F_7 ( V_2 -> V_35 +
V_42 ) ;
T_2 V_31 [ 8 ] = { 0 } ;
* ( ( T_1 * ) V_31 ) = F_8 ( V_22 ) ;
* ( ( T_1 * ) ( V_31 + 4 ) ) = F_8 ( V_21 ) ;
memcpy ( V_4 -> V_32 , V_31 , V_4 -> V_8 ) ;
}
}
static void
F_9 ( struct V_1 * V_2 )
{
if ( V_2 -> V_25 ) {
F_5 ( 0 , V_2 -> V_35 + V_40 ) ;
F_5 ( 0 , V_2 -> V_35 + V_43 ) ;
F_5 ( 0 , V_2 -> V_35 +
V_44 ) ;
F_5 ( 0 , V_2 -> V_35 +
V_45 ) ;
}
F_5 ( 0 , V_2 -> V_35 + V_2 -> V_46 . V_47 ) ;
F_5 ( F_10 ( V_2 -> V_48 ) | F_11 ( V_2 -> V_49 ) ,
V_2 -> V_35 + V_2 -> V_46 . clock ) ;
F_5 ( 0 , V_2 -> V_35 + V_2 -> V_46 . V_19 ) ;
F_5 ( 0 , V_2 -> V_35 + V_2 -> V_46 . V_50 ) ;
F_5 ( V_14 | V_51 ,
V_2 -> V_35 + V_2 -> V_46 . V_52 ) ;
V_2 -> V_53 = V_54 ;
}
static void
F_12 ( struct V_1 * V_2 , T_1 V_55 )
{
if ( V_2 -> V_53 == V_54 ) {
V_2 -> V_56 = V_57 ;
return;
}
switch ( V_55 ) {
case V_58 :
case V_59 :
V_2 -> V_56 = V_60 ;
V_2 -> V_53 = V_61 ;
break;
case V_62 :
if ( V_2 -> V_4 -> V_15 & V_17 ) {
V_2 -> V_56 = V_63 ;
V_2 -> V_53 =
V_64 ;
break;
}
case V_65 :
case V_66 :
if ( ( V_2 -> V_7 == 0 )
|| ( V_2 -> V_9
&& ( V_2 -> V_6 != 0 ) ) ) {
if ( V_2 -> V_67 || V_2 -> V_9 ) {
V_2 -> V_56 = V_57 ;
V_2 -> V_53 = V_54 ;
} else {
V_2 -> V_56 =
V_68 ;
V_2 -> V_53 =
V_69 ;
}
} else {
V_2 -> V_56 = V_70 ;
V_2 -> V_53 =
V_71 ;
V_2 -> V_7 -- ;
}
break;
case V_72 :
if ( V_2 -> V_4 -> V_15 & V_17 ) {
V_2 -> V_56 = V_63 ;
V_2 -> V_53 =
V_64 ;
break;
}
case V_73 :
if ( V_2 -> V_7 == 0 ) {
V_2 -> V_56 = V_57 ;
V_2 -> V_53 = V_54 ;
break;
}
case V_74 :
if ( V_55 != V_74 )
V_2 -> V_56 = V_75 ;
else {
V_2 -> V_56 = V_76 ;
V_2 -> V_7 -- ;
}
V_2 -> V_53 = V_77 ;
if ( ( V_2 -> V_7 == 1 ) || V_2 -> V_9 )
V_2 -> V_11 &= ~ V_12 ;
break;
case V_78 :
V_2 -> V_56 = V_79 ;
V_2 -> V_53 = V_54 ;
break;
case V_80 :
case V_81 :
case V_82 :
V_2 -> V_56 = V_57 ;
V_2 -> V_53 = V_54 ;
V_2 -> V_10 = - V_83 ;
break;
case V_84 :
if ( V_2 -> V_67 || V_2 -> V_9 ) {
V_2 -> V_56 = V_85 ;
V_2 -> V_53 = V_54 ;
} else {
V_2 -> V_56 = V_86 ;
V_2 -> V_53 = V_69 ;
}
break;
default:
F_13 ( & V_2 -> V_87 . V_88 ,
L_1
L_2 ,
V_2 -> V_53 , V_55 , V_2 -> V_4 -> V_19 ,
V_2 -> V_4 -> V_15 ) ;
V_2 -> V_56 = V_57 ;
F_9 ( V_2 ) ;
V_2 -> V_10 = - V_89 ;
}
}
static void
F_14 ( struct V_1 * V_2 )
{
switch( V_2 -> V_56 ) {
case V_86 :
F_6 ( V_2 ) ;
F_5 ( 0 , V_2 -> V_35 + V_40 ) ;
F_5 ( 0 , V_2 -> V_35 +
V_44 ) ;
case V_68 :
F_15 ( V_2 -> V_90 == 0 ) ;
V_2 -> V_24 ++ ;
V_2 -> V_90 -- ;
if ( F_3 ( V_2 ) < 0 ) {
V_2 -> V_11 |= V_91 ;
F_5 ( V_2 -> V_11 ,
V_2 -> V_35 + V_2 -> V_46 . V_52 ) ;
F_1 ( V_2 , V_2 -> V_24 ) ;
}
if ( V_2 -> V_92 )
F_16 ( 5 ) ;
V_2 -> V_67 = V_2 -> V_90 == 1 ;
break;
case V_75 :
F_5 ( V_2 -> V_11 ,
V_2 -> V_35 + V_2 -> V_46 . V_52 ) ;
break;
case V_93 :
if ( F_3 ( V_2 ) < 0 ) {
F_1 ( V_2 , V_2 -> V_24 ) ;
F_5 ( V_2 -> V_11 | V_91 ,
V_2 -> V_35 + V_2 -> V_46 . V_52 ) ;
}
break;
case V_60 :
F_5 ( V_2 -> V_18 ,
V_2 -> V_35 + V_2 -> V_46 . V_94 ) ;
F_5 ( V_2 -> V_11 ,
V_2 -> V_35 + V_2 -> V_46 . V_52 ) ;
break;
case V_63 :
F_5 ( V_2 -> V_20 ,
V_2 -> V_35 + V_2 -> V_46 . V_94 ) ;
F_5 ( V_2 -> V_11 ,
V_2 -> V_35 + V_2 -> V_46 . V_52 ) ;
break;
case V_70 :
F_5 ( V_2 -> V_4 -> V_32 [ V_2 -> V_6 ++ ] ,
V_2 -> V_35 + V_2 -> V_46 . V_94 ) ;
F_5 ( V_2 -> V_11 ,
V_2 -> V_35 + V_2 -> V_46 . V_52 ) ;
break;
case V_76 :
V_2 -> V_4 -> V_32 [ V_2 -> V_6 ++ ] =
F_7 ( V_2 -> V_35 + V_2 -> V_46 . V_94 ) ;
F_5 ( V_2 -> V_11 ,
V_2 -> V_35 + V_2 -> V_46 . V_52 ) ;
break;
case V_79 :
V_2 -> V_4 -> V_32 [ V_2 -> V_6 ++ ] =
F_7 ( V_2 -> V_35 + V_2 -> V_46 . V_94 ) ;
V_2 -> V_11 &= ~ V_13 ;
F_5 ( V_2 -> V_11 | V_51 ,
V_2 -> V_35 + V_2 -> V_46 . V_52 ) ;
V_2 -> V_95 = 0 ;
if ( V_2 -> V_92 )
F_16 ( 5 ) ;
F_17 ( & V_2 -> V_96 ) ;
break;
case V_97 :
default:
F_13 ( & V_2 -> V_87 . V_88 ,
L_3 ,
V_2 -> V_56 ) ;
V_2 -> V_10 = - V_89 ;
case V_57 :
V_2 -> V_11 &= ~ V_13 ;
F_5 ( V_2 -> V_11 | V_51 ,
V_2 -> V_35 + V_2 -> V_46 . V_52 ) ;
V_2 -> V_95 = 0 ;
F_17 ( & V_2 -> V_96 ) ;
break;
case V_85 :
F_6 ( V_2 ) ;
F_5 ( 0 , V_2 -> V_35 + V_40 ) ;
F_5 ( 0 , V_2 -> V_35 +
V_44 ) ;
V_2 -> V_95 = 0 ;
F_17 ( & V_2 -> V_96 ) ;
break;
}
}
static T_3
F_18 ( int V_98 , void * V_99 )
{
struct V_1 * V_2 = V_99 ;
unsigned long V_15 ;
T_1 V_55 ;
T_3 V_10 = V_100 ;
F_19 ( & V_2 -> V_101 , V_15 ) ;
if ( V_2 -> V_25 ) {
while ( F_7 ( V_2 -> V_35 +
V_44 ) ) {
int V_102 = F_7 ( V_2 -> V_35 +
V_103 ) ;
if ( V_102 & V_104 )
V_55 = V_105 ;
else
V_55 = V_84 ;
F_12 ( V_2 , V_55 ) ;
F_14 ( V_2 ) ;
V_10 = V_106 ;
}
}
while ( F_7 ( V_2 -> V_35 + V_2 -> V_46 . V_52 ) &
V_107 ) {
V_55 = F_7 ( V_2 -> V_35 + V_2 -> V_46 . V_55 ) ;
F_12 ( V_2 , V_55 ) ;
F_14 ( V_2 ) ;
V_10 = V_106 ;
}
F_20 ( & V_2 -> V_101 , V_15 ) ;
return V_10 ;
}
static void
F_21 ( struct V_1 * V_2 )
{
long V_108 ;
unsigned long V_15 ;
char abort = 0 ;
V_108 = F_22 ( V_2 -> V_96 ,
! V_2 -> V_95 , V_2 -> V_87 . V_109 ) ;
F_19 ( & V_2 -> V_101 , V_15 ) ;
if ( ! V_108 ) {
V_2 -> V_10 = - V_110 ;
abort = 1 ;
} else if ( V_108 < 0 ) {
V_2 -> V_10 = V_108 ;
abort = 1 ;
}
if ( abort && V_2 -> V_95 ) {
V_2 -> V_9 = 1 ;
F_20 ( & V_2 -> V_101 , V_15 ) ;
V_108 = F_22 ( V_2 -> V_96 ,
! V_2 -> V_95 , V_2 -> V_87 . V_109 ) ;
if ( ( V_108 <= 0 ) && V_2 -> V_95 ) {
V_2 -> V_53 = V_54 ;
F_13 ( & V_2 -> V_87 . V_88 ,
L_4
L_5 , V_2 -> V_95 ,
( int ) V_108 ) ;
F_9 ( V_2 ) ;
}
} else
F_20 ( & V_2 -> V_101 , V_15 ) ;
}
static int
F_23 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_111 )
{
unsigned long V_15 ;
F_19 ( & V_2 -> V_101 , V_15 ) ;
V_2 -> V_56 = V_93 ;
V_2 -> V_53 = V_112 ;
V_2 -> V_67 = V_111 ;
V_2 -> V_95 = 1 ;
F_14 ( V_2 ) ;
F_20 ( & V_2 -> V_101 , V_15 ) ;
F_21 ( V_2 ) ;
return V_2 -> V_10 ;
}
static T_1
F_24 ( struct V_113 * V_114 )
{
return V_115 | V_116 | V_117 ;
}
static int
F_25 ( struct V_113 * V_114 , struct V_3 V_24 [] , int V_118 )
{
struct V_1 * V_2 = F_26 ( V_114 ) ;
int V_10 , V_119 = V_118 ;
F_15 ( V_2 -> V_24 != NULL ) ;
V_2 -> V_24 = V_24 ;
V_2 -> V_90 = V_118 ;
V_10 = F_23 ( V_2 , & V_24 [ 0 ] , V_118 == 1 ) ;
if ( V_10 < 0 )
V_119 = V_10 ;
V_2 -> V_90 = 0 ;
V_2 -> V_24 = NULL ;
return V_119 ;
}
static int
F_27 ( const int V_120 , const int V_121 , const int V_122 )
{
return V_120 / ( 10 * ( V_122 + 1 ) * ( 2 << V_121 ) ) ;
}
static bool
F_28 ( const T_1 V_123 , const T_1 V_120 , T_1 * V_124 ,
T_1 * V_125 )
{
int V_126 , V_127 , V_128 = V_129 ;
int V_122 , V_121 ;
for ( V_121 = 0 ; V_121 <= 7 ; V_121 ++ )
for ( V_122 = 0 ; V_122 <= 15 ; V_122 ++ ) {
V_126 = F_27 ( V_120 , V_121 , V_122 ) ;
V_127 = V_123 - V_126 ;
if ( V_127 >= 0 && V_127 < V_128 ) {
* V_125 = V_122 ;
* V_124 = V_121 ;
V_128 = V_127 ;
}
if ( V_128 == 0 )
return true ;
}
if ( V_128 == V_129 )
return false ;
return true ;
}
static int
F_29 ( struct V_1 * V_2 ,
struct V_130 * V_88 )
{
#if ! F_30 ( V_131 )
return - V_132 ;
#else
const struct V_133 * V_130 ;
struct V_134 * V_135 = V_88 -> V_136 ;
T_1 V_137 , V_120 ;
int V_10 = 0 ;
if ( F_31 ( V_2 -> V_138 ) ) {
V_10 = - V_132 ;
goto V_139;
}
V_120 = F_32 ( V_2 -> V_138 ) ;
V_10 = F_33 ( V_135 , L_6 , & V_137 ) ;
if ( V_10 )
V_137 = 100000 ;
if ( ! F_28 ( V_137 , V_120 ,
& V_2 -> V_49 , & V_2 -> V_48 ) ) {
V_10 = - V_27 ;
goto V_139;
}
V_2 -> V_98 = F_34 ( V_135 , 0 ) ;
V_2 -> V_87 . V_109 = V_140 ;
V_130 = F_35 ( V_141 , V_88 ) ;
if ( ! V_130 )
return - V_132 ;
memcpy ( & V_2 -> V_46 , V_130 -> V_94 , sizeof( V_2 -> V_46 ) ) ;
if ( F_36 ( V_135 , L_7 ) ) {
V_2 -> V_25 = true ;
V_2 -> V_92 = true ;
}
if ( F_36 ( V_135 , L_8 ) ) {
V_2 -> V_25 = false ;
V_2 -> V_92 = true ;
}
V_139:
return V_10 ;
#endif
}
static int
F_29 ( struct V_1 * V_2 ,
struct V_130 * V_88 )
{
return - V_132 ;
}
static int
F_37 ( struct V_142 * V_143 )
{
struct V_1 * V_2 ;
struct V_144 * V_145 = F_38 ( & V_143 -> V_88 ) ;
struct V_146 * V_147 ;
int V_10 ;
if ( ( ! V_145 && ! V_143 -> V_88 . V_136 ) )
return - V_132 ;
V_2 = F_39 ( & V_143 -> V_88 , sizeof( struct V_1 ) ,
V_148 ) ;
if ( ! V_2 )
return - V_149 ;
V_147 = F_40 ( V_143 , V_150 , 0 ) ;
V_2 -> V_35 = F_41 ( & V_143 -> V_88 , V_147 ) ;
if ( F_31 ( V_2 -> V_35 ) )
return F_42 ( V_2 -> V_35 ) ;
F_43 ( V_2 -> V_87 . V_151 , V_152 L_9 ,
sizeof( V_2 -> V_87 . V_151 ) ) ;
F_44 ( & V_2 -> V_96 ) ;
F_45 ( & V_2 -> V_101 ) ;
#if F_30 ( V_131 )
V_2 -> V_138 = F_46 ( & V_143 -> V_88 , NULL ) ;
if ( ! F_31 ( V_2 -> V_138 ) ) {
F_47 ( V_2 -> V_138 ) ;
F_48 ( V_2 -> V_138 ) ;
}
#endif
if ( V_145 ) {
V_2 -> V_48 = V_145 -> V_48 ;
V_2 -> V_49 = V_145 -> V_49 ;
V_2 -> V_98 = F_49 ( V_143 , 0 ) ;
V_2 -> V_87 . V_109 = F_50 ( V_145 -> V_109 ) ;
V_2 -> V_25 = false ;
memcpy ( & V_2 -> V_46 , & V_153 , sizeof( V_2 -> V_46 ) ) ;
} else if ( V_143 -> V_88 . V_136 ) {
V_10 = F_29 ( V_2 , & V_143 -> V_88 ) ;
if ( V_10 )
goto V_154;
}
if ( V_2 -> V_98 < 0 ) {
V_10 = - V_83 ;
goto V_154;
}
V_2 -> V_87 . V_88 . V_155 = & V_143 -> V_88 ;
V_2 -> V_87 . V_156 = & V_157 ;
V_2 -> V_87 . V_158 = V_159 ;
V_2 -> V_87 . V_160 = V_161 | V_162 ;
V_2 -> V_87 . V_163 = V_143 -> V_164 ;
V_2 -> V_87 . V_88 . V_136 = V_143 -> V_88 . V_136 ;
F_51 ( V_143 , V_2 ) ;
F_52 ( & V_2 -> V_87 , V_2 ) ;
F_9 ( V_2 ) ;
V_10 = F_53 ( V_2 -> V_98 , F_18 , 0 ,
V_152 , V_2 ) ;
if ( V_10 ) {
F_13 ( & V_2 -> V_87 . V_88 ,
L_10 ,
V_2 -> V_98 , V_10 ) ;
goto V_154;
} else if ( ( V_10 = F_54 ( & V_2 -> V_87 ) ) != 0 ) {
F_13 ( & V_2 -> V_87 . V_88 ,
L_11 , - V_10 ) ;
goto V_165;
}
return 0 ;
V_165:
F_55 ( V_2 -> V_98 , V_2 ) ;
V_154:
#if F_30 ( V_131 )
if ( ! F_31 ( V_2 -> V_138 ) ) {
F_56 ( V_2 -> V_138 ) ;
F_57 ( V_2 -> V_138 ) ;
}
#endif
return V_10 ;
}
static int
F_58 ( struct V_142 * V_88 )
{
struct V_1 * V_2 = F_59 ( V_88 ) ;
F_60 ( & V_2 -> V_87 ) ;
F_55 ( V_2 -> V_98 , V_2 ) ;
#if F_30 ( V_131 )
if ( ! F_31 ( V_2 -> V_138 ) ) {
F_56 ( V_2 -> V_138 ) ;
F_57 ( V_2 -> V_138 ) ;
}
#endif
return 0 ;
}
