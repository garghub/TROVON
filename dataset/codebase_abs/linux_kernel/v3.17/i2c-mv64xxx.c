static void
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 = 0 ;
V_2 -> V_6 = V_7 |
V_8 | V_9 ;
if ( V_4 -> V_10 & V_11 )
V_5 = 1 ;
if ( V_4 -> V_10 & V_12 ) {
V_2 -> V_13 = 0xf0 | ( ( ( T_1 ) V_4 -> V_14 & 0x300 ) >> 7 ) | V_5 ;
V_2 -> V_15 = ( T_1 ) V_4 -> V_14 & 0xff ;
} else {
V_2 -> V_13 = F_2 ( ( T_1 ) V_4 -> V_14 ) | V_5 ;
V_2 -> V_15 = 0 ;
}
}
static int F_3 ( struct V_1 * V_2 )
{
unsigned long V_16 = 0 ;
unsigned long V_17 = 0 ;
unsigned long V_18 ;
struct V_3 * V_4 = V_2 -> V_19 ;
if ( ! V_2 -> V_20 )
return - V_21 ;
if ( ( V_4 -> V_10 & ~ ( V_12 | V_11 ) ) != 0 )
return - V_22 ;
if ( V_4 -> V_23 < 1 || V_4 -> V_23 > 8 )
return - V_22 ;
V_18 = V_24 |
( V_4 -> V_14 << V_25 ) ;
if ( ( V_4 -> V_10 & V_12 ) != 0 )
V_18 |= V_26 ;
if ( ( V_4 -> V_10 & V_11 ) == 0 ) {
T_2 V_27 [ 8 ] = { 0 } ;
memcpy ( V_27 , V_4 -> V_28 , V_4 -> V_23 ) ;
V_17 = F_4 ( * ( ( T_1 * ) V_27 ) ) ;
V_16 = F_4 ( * ( ( T_1 * ) ( V_27 + 4 ) ) ) ;
V_18 |= V_29 |
( V_4 -> V_23 - 1 ) << V_30 ;
F_5 ( V_17 ,
V_2 -> V_31 + V_32 ) ;
F_5 ( V_16 ,
V_2 -> V_31 + V_33 ) ;
} else {
V_18 |= V_34 |
( V_4 -> V_23 - 1 ) << V_35 ;
}
F_5 ( V_18 , V_2 -> V_31 + V_36 ) ;
return 0 ;
}
static void
F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_10 & V_11 ) {
T_1 V_17 = F_7 ( V_2 -> V_31 +
V_37 ) ;
T_1 V_16 = F_7 ( V_2 -> V_31 +
V_38 ) ;
T_2 V_27 [ 8 ] = { 0 } ;
* ( ( T_1 * ) V_27 ) = F_8 ( V_17 ) ;
* ( ( T_1 * ) ( V_27 + 4 ) ) = F_8 ( V_16 ) ;
memcpy ( V_4 -> V_28 , V_27 , V_4 -> V_23 ) ;
}
}
static void
F_9 ( struct V_1 * V_2 )
{
if ( V_2 -> V_20 ) {
F_5 ( 0 , V_2 -> V_31 + V_36 ) ;
F_5 ( 0 , V_2 -> V_31 + V_39 ) ;
F_5 ( 0 , V_2 -> V_31 +
V_40 ) ;
F_5 ( 0 , V_2 -> V_31 +
V_41 ) ;
}
F_5 ( 0 , V_2 -> V_31 + V_2 -> V_42 . V_43 ) ;
F_5 ( F_10 ( V_2 -> V_44 ) | F_11 ( V_2 -> V_45 ) ,
V_2 -> V_31 + V_2 -> V_42 . clock ) ;
F_5 ( 0 , V_2 -> V_31 + V_2 -> V_42 . V_14 ) ;
F_5 ( 0 , V_2 -> V_31 + V_2 -> V_42 . V_46 ) ;
F_5 ( V_9 | V_47 ,
V_2 -> V_31 + V_2 -> V_42 . V_48 ) ;
V_2 -> V_49 = V_50 ;
}
static void
F_12 ( struct V_1 * V_2 , T_1 V_51 )
{
if ( V_2 -> V_49 == V_50 ) {
V_2 -> V_52 = V_53 ;
return;
}
switch ( V_51 ) {
case V_54 :
case V_55 :
V_2 -> V_52 = V_56 ;
V_2 -> V_49 = V_57 ;
break;
case V_58 :
if ( V_2 -> V_4 -> V_10 & V_12 ) {
V_2 -> V_52 = V_59 ;
V_2 -> V_49 =
V_60 ;
break;
}
case V_61 :
case V_62 :
if ( ( V_2 -> V_63 == 0 )
|| ( V_2 -> V_64
&& ( V_2 -> V_65 != 0 ) ) ) {
if ( V_2 -> V_66 || V_2 -> V_64 ) {
V_2 -> V_52 = V_53 ;
V_2 -> V_49 = V_50 ;
} else {
V_2 -> V_52 =
V_67 ;
V_2 -> V_49 =
V_68 ;
}
} else {
V_2 -> V_52 = V_69 ;
V_2 -> V_49 =
V_70 ;
V_2 -> V_63 -- ;
}
break;
case V_71 :
if ( V_2 -> V_4 -> V_10 & V_12 ) {
V_2 -> V_52 = V_59 ;
V_2 -> V_49 =
V_60 ;
break;
}
case V_72 :
if ( V_2 -> V_63 == 0 ) {
V_2 -> V_52 = V_53 ;
V_2 -> V_49 = V_50 ;
break;
}
case V_73 :
if ( V_51 != V_73 )
V_2 -> V_52 = V_74 ;
else {
V_2 -> V_52 = V_75 ;
V_2 -> V_63 -- ;
}
V_2 -> V_49 = V_76 ;
if ( ( V_2 -> V_63 == 1 ) || V_2 -> V_64 )
V_2 -> V_6 &= ~ V_7 ;
break;
case V_77 :
V_2 -> V_52 = V_78 ;
V_2 -> V_49 = V_50 ;
break;
case V_79 :
case V_80 :
case V_81 :
V_2 -> V_52 = V_53 ;
V_2 -> V_49 = V_50 ;
V_2 -> V_82 = - V_83 ;
break;
case V_84 :
if ( V_2 -> V_66 || V_2 -> V_64 ) {
V_2 -> V_52 = V_85 ;
V_2 -> V_49 = V_50 ;
} else {
V_2 -> V_52 = V_86 ;
V_2 -> V_49 = V_68 ;
}
break;
default:
F_13 ( & V_2 -> V_87 . V_88 ,
L_1
L_2 ,
V_2 -> V_49 , V_51 , V_2 -> V_4 -> V_14 ,
V_2 -> V_4 -> V_10 ) ;
V_2 -> V_52 = V_53 ;
F_9 ( V_2 ) ;
V_2 -> V_82 = - V_89 ;
}
}
static void F_14 ( struct V_1 * V_2 )
{
V_2 -> V_4 = V_2 -> V_19 ;
V_2 -> V_65 = 0 ;
V_2 -> V_63 = V_2 -> V_4 -> V_23 ;
V_2 -> V_64 = 0 ;
V_2 -> V_82 = 0 ;
if ( F_3 ( V_2 ) < 0 ) {
F_1 ( V_2 , V_2 -> V_19 ) ;
F_5 ( V_2 -> V_6 | V_90 ,
V_2 -> V_31 + V_2 -> V_42 . V_48 ) ;
}
}
static void
F_15 ( struct V_1 * V_2 )
{
switch( V_2 -> V_52 ) {
case V_86 :
F_6 ( V_2 ) ;
F_5 ( 0 , V_2 -> V_31 + V_36 ) ;
F_5 ( 0 , V_2 -> V_31 +
V_40 ) ;
case V_67 :
F_16 ( V_2 -> V_91 == 0 ) ;
V_2 -> V_19 ++ ;
V_2 -> V_91 -- ;
F_14 ( V_2 ) ;
if ( V_2 -> V_92 )
F_17 ( 5 ) ;
V_2 -> V_66 = V_2 -> V_91 == 1 ;
break;
case V_74 :
F_5 ( V_2 -> V_6 ,
V_2 -> V_31 + V_2 -> V_42 . V_48 ) ;
break;
case V_56 :
F_5 ( V_2 -> V_13 ,
V_2 -> V_31 + V_2 -> V_42 . V_93 ) ;
F_5 ( V_2 -> V_6 ,
V_2 -> V_31 + V_2 -> V_42 . V_48 ) ;
break;
case V_59 :
F_5 ( V_2 -> V_15 ,
V_2 -> V_31 + V_2 -> V_42 . V_93 ) ;
F_5 ( V_2 -> V_6 ,
V_2 -> V_31 + V_2 -> V_42 . V_48 ) ;
break;
case V_69 :
F_5 ( V_2 -> V_4 -> V_28 [ V_2 -> V_65 ++ ] ,
V_2 -> V_31 + V_2 -> V_42 . V_93 ) ;
F_5 ( V_2 -> V_6 ,
V_2 -> V_31 + V_2 -> V_42 . V_48 ) ;
break;
case V_75 :
V_2 -> V_4 -> V_28 [ V_2 -> V_65 ++ ] =
F_7 ( V_2 -> V_31 + V_2 -> V_42 . V_93 ) ;
F_5 ( V_2 -> V_6 ,
V_2 -> V_31 + V_2 -> V_42 . V_48 ) ;
break;
case V_78 :
V_2 -> V_4 -> V_28 [ V_2 -> V_65 ++ ] =
F_7 ( V_2 -> V_31 + V_2 -> V_42 . V_93 ) ;
V_2 -> V_6 &= ~ V_8 ;
F_5 ( V_2 -> V_6 | V_47 ,
V_2 -> V_31 + V_2 -> V_42 . V_48 ) ;
V_2 -> V_94 = 0 ;
if ( V_2 -> V_92 )
F_17 ( 5 ) ;
F_18 ( & V_2 -> V_95 ) ;
break;
case V_96 :
default:
F_13 ( & V_2 -> V_87 . V_88 ,
L_3 ,
V_2 -> V_52 ) ;
V_2 -> V_82 = - V_89 ;
case V_53 :
V_2 -> V_6 &= ~ V_8 ;
F_5 ( V_2 -> V_6 | V_47 ,
V_2 -> V_31 + V_2 -> V_42 . V_48 ) ;
V_2 -> V_94 = 0 ;
F_18 ( & V_2 -> V_95 ) ;
break;
case V_85 :
F_6 ( V_2 ) ;
F_5 ( 0 , V_2 -> V_31 + V_36 ) ;
F_5 ( 0 , V_2 -> V_31 +
V_40 ) ;
V_2 -> V_94 = 0 ;
F_18 ( & V_2 -> V_95 ) ;
break;
}
}
static T_3
F_19 ( int V_97 , void * V_98 )
{
struct V_1 * V_2 = V_98 ;
unsigned long V_10 ;
T_1 V_51 ;
T_3 V_82 = V_99 ;
F_20 ( & V_2 -> V_100 , V_10 ) ;
if ( V_2 -> V_20 ) {
while ( F_7 ( V_2 -> V_31 +
V_40 ) ) {
int V_101 = F_7 ( V_2 -> V_31 +
V_102 ) ;
if ( V_101 & V_103 )
V_51 = V_104 ;
else
V_51 = V_84 ;
F_12 ( V_2 , V_51 ) ;
F_15 ( V_2 ) ;
V_82 = V_105 ;
}
}
while ( F_7 ( V_2 -> V_31 + V_2 -> V_42 . V_48 ) &
V_106 ) {
V_51 = F_7 ( V_2 -> V_31 + V_2 -> V_42 . V_51 ) ;
F_12 ( V_2 , V_51 ) ;
F_15 ( V_2 ) ;
if ( V_2 -> V_107 )
F_5 ( V_2 -> V_6 | V_106 ,
V_2 -> V_31 + V_2 -> V_42 . V_48 ) ;
V_82 = V_105 ;
}
F_21 ( & V_2 -> V_100 , V_10 ) ;
return V_82 ;
}
static void
F_22 ( struct V_1 * V_2 )
{
long V_108 ;
unsigned long V_10 ;
char abort = 0 ;
V_108 = F_23 ( V_2 -> V_95 ,
! V_2 -> V_94 , V_2 -> V_87 . V_109 ) ;
F_20 ( & V_2 -> V_100 , V_10 ) ;
if ( ! V_108 ) {
V_2 -> V_82 = - V_110 ;
abort = 1 ;
} else if ( V_108 < 0 ) {
V_2 -> V_82 = V_108 ;
abort = 1 ;
}
if ( abort && V_2 -> V_94 ) {
V_2 -> V_64 = 1 ;
F_21 ( & V_2 -> V_100 , V_10 ) ;
V_108 = F_23 ( V_2 -> V_95 ,
! V_2 -> V_94 , V_2 -> V_87 . V_109 ) ;
if ( ( V_108 <= 0 ) && V_2 -> V_94 ) {
V_2 -> V_49 = V_50 ;
F_13 ( & V_2 -> V_87 . V_88 ,
L_4
L_5 , V_2 -> V_94 ,
( int ) V_108 ) ;
F_9 ( V_2 ) ;
}
} else
F_21 ( & V_2 -> V_100 , V_10 ) ;
}
static int
F_24 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_111 )
{
unsigned long V_10 ;
F_20 ( & V_2 -> V_100 , V_10 ) ;
V_2 -> V_49 = V_112 ;
V_2 -> V_66 = V_111 ;
V_2 -> V_94 = 1 ;
F_14 ( V_2 ) ;
F_21 ( & V_2 -> V_100 , V_10 ) ;
F_22 ( V_2 ) ;
return V_2 -> V_82 ;
}
static T_1
F_25 ( struct V_113 * V_114 )
{
return V_115 | V_116 | V_117 ;
}
static int
F_26 ( struct V_113 * V_114 , struct V_3 V_19 [] , int V_118 )
{
struct V_1 * V_2 = F_27 ( V_114 ) ;
int V_82 , V_119 = V_118 ;
F_16 ( V_2 -> V_19 != NULL ) ;
V_2 -> V_19 = V_19 ;
V_2 -> V_91 = V_118 ;
V_82 = F_24 ( V_2 , & V_19 [ 0 ] , V_118 == 1 ) ;
if ( V_82 < 0 )
V_119 = V_82 ;
V_2 -> V_91 = 0 ;
V_2 -> V_19 = NULL ;
return V_119 ;
}
static int
F_28 ( const int V_120 , const int V_121 , const int V_122 )
{
return V_120 / ( 10 * ( V_122 + 1 ) * ( 2 << V_121 ) ) ;
}
static bool
F_29 ( const T_1 V_123 , const T_1 V_120 , T_1 * V_124 ,
T_1 * V_125 )
{
int V_126 , V_127 , V_128 = V_129 ;
int V_122 , V_121 ;
for ( V_121 = 0 ; V_121 <= 7 ; V_121 ++ )
for ( V_122 = 0 ; V_122 <= 15 ; V_122 ++ ) {
V_126 = F_28 ( V_120 , V_121 , V_122 ) ;
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
F_30 ( struct V_1 * V_2 ,
struct V_130 * V_88 )
{
#if ! F_31 ( V_131 )
return - V_132 ;
#else
const struct V_133 * V_130 ;
struct V_134 * V_135 = V_88 -> V_136 ;
T_1 V_137 , V_120 ;
int V_82 = 0 ;
if ( F_32 ( V_2 -> V_138 ) ) {
V_82 = - V_132 ;
goto V_139;
}
V_120 = F_33 ( V_2 -> V_138 ) ;
if ( F_34 ( V_135 , L_6 , & V_137 ) )
V_137 = 100000 ;
if ( ! F_29 ( V_137 , V_120 ,
& V_2 -> V_45 , & V_2 -> V_44 ) ) {
V_82 = - V_22 ;
goto V_139;
}
V_2 -> V_97 = F_35 ( V_135 , 0 ) ;
V_2 -> V_140 = F_36 ( V_88 , NULL ) ;
if ( F_32 ( V_2 -> V_140 ) ) {
if ( F_37 ( V_2 -> V_140 ) == - V_141 ) {
V_82 = - V_141 ;
goto V_139;
}
} else {
F_38 ( V_2 -> V_140 ) ;
}
V_2 -> V_87 . V_109 = V_142 ;
V_130 = F_39 ( V_143 , V_88 ) ;
if ( ! V_130 )
return - V_132 ;
memcpy ( & V_2 -> V_42 , V_130 -> V_93 , sizeof( V_2 -> V_42 ) ) ;
if ( F_40 ( V_135 , L_7 ) ) {
V_2 -> V_20 = true ;
V_2 -> V_92 = true ;
}
if ( F_40 ( V_135 , L_8 ) ) {
V_2 -> V_20 = false ;
V_2 -> V_92 = true ;
}
if ( F_40 ( V_135 , L_9 ) )
V_2 -> V_107 = true ;
V_139:
return V_82 ;
#endif
}
static int
F_30 ( struct V_1 * V_2 ,
struct V_130 * V_88 )
{
return - V_132 ;
}
static int
F_41 ( struct V_144 * V_145 )
{
struct V_1 * V_2 ;
struct V_146 * V_147 = F_42 ( & V_145 -> V_88 ) ;
struct V_148 * V_149 ;
int V_82 ;
if ( ( ! V_147 && ! V_145 -> V_88 . V_136 ) )
return - V_132 ;
V_2 = F_43 ( & V_145 -> V_88 , sizeof( struct V_1 ) ,
V_150 ) ;
if ( ! V_2 )
return - V_151 ;
V_149 = F_44 ( V_145 , V_152 , 0 ) ;
V_2 -> V_31 = F_45 ( & V_145 -> V_88 , V_149 ) ;
if ( F_32 ( V_2 -> V_31 ) )
return F_37 ( V_2 -> V_31 ) ;
F_46 ( V_2 -> V_87 . V_153 , V_154 L_10 ,
sizeof( V_2 -> V_87 . V_153 ) ) ;
F_47 ( & V_2 -> V_95 ) ;
F_48 ( & V_2 -> V_100 ) ;
#if F_31 ( V_131 )
V_2 -> V_138 = F_49 ( & V_145 -> V_88 , NULL ) ;
if ( ! F_32 ( V_2 -> V_138 ) ) {
F_50 ( V_2 -> V_138 ) ;
F_51 ( V_2 -> V_138 ) ;
}
#endif
if ( V_147 ) {
V_2 -> V_44 = V_147 -> V_44 ;
V_2 -> V_45 = V_147 -> V_45 ;
V_2 -> V_97 = F_52 ( V_145 , 0 ) ;
V_2 -> V_87 . V_109 = F_53 ( V_147 -> V_109 ) ;
V_2 -> V_20 = false ;
memcpy ( & V_2 -> V_42 , & V_155 , sizeof( V_2 -> V_42 ) ) ;
} else if ( V_145 -> V_88 . V_136 ) {
V_82 = F_30 ( V_2 , & V_145 -> V_88 ) ;
if ( V_82 )
goto V_156;
}
if ( V_2 -> V_97 < 0 ) {
V_82 = - V_83 ;
goto V_157;
}
V_2 -> V_87 . V_88 . V_158 = & V_145 -> V_88 ;
V_2 -> V_87 . V_159 = & V_160 ;
V_2 -> V_87 . V_161 = V_162 ;
V_2 -> V_87 . V_163 = V_164 ;
V_2 -> V_87 . V_165 = V_145 -> V_166 ;
V_2 -> V_87 . V_88 . V_136 = V_145 -> V_88 . V_136 ;
F_54 ( V_145 , V_2 ) ;
F_55 ( & V_2 -> V_87 , V_2 ) ;
F_9 ( V_2 ) ;
V_82 = F_56 ( V_2 -> V_97 , F_19 , 0 ,
V_154 , V_2 ) ;
if ( V_82 ) {
F_13 ( & V_2 -> V_87 . V_88 ,
L_11 ,
V_2 -> V_97 , V_82 ) ;
goto V_157;
} else if ( ( V_82 = F_57 ( & V_2 -> V_87 ) ) != 0 ) {
F_13 ( & V_2 -> V_87 . V_88 ,
L_12 , - V_82 ) ;
goto V_167;
}
return 0 ;
V_167:
F_58 ( V_2 -> V_97 , V_2 ) ;
V_157:
if ( ! F_59 ( V_2 -> V_140 ) )
F_60 ( V_2 -> V_140 ) ;
V_156:
#if F_31 ( V_131 )
if ( ! F_32 ( V_2 -> V_138 ) ) {
F_61 ( V_2 -> V_138 ) ;
F_62 ( V_2 -> V_138 ) ;
}
#endif
return V_82 ;
}
static int
F_63 ( struct V_144 * V_88 )
{
struct V_1 * V_2 = F_64 ( V_88 ) ;
F_65 ( & V_2 -> V_87 ) ;
F_58 ( V_2 -> V_97 , V_2 ) ;
if ( ! F_59 ( V_2 -> V_140 ) )
F_60 ( V_2 -> V_140 ) ;
#if F_31 ( V_131 )
if ( ! F_32 ( V_2 -> V_138 ) ) {
F_61 ( V_2 -> V_138 ) ;
F_62 ( V_2 -> V_138 ) ;
}
#endif
return 0 ;
}
