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
static void
F_3 ( struct V_1 * V_2 )
{
if ( V_2 -> V_16 ) {
F_4 ( 0 , V_2 -> V_17 + V_18 ) ;
F_4 ( 0 , V_2 -> V_17 + V_19 ) ;
F_4 ( 0 , V_2 -> V_17 +
V_20 ) ;
F_4 ( 0 , V_2 -> V_17 +
V_21 ) ;
}
F_4 ( 0 , V_2 -> V_17 + V_2 -> V_22 . V_23 ) ;
F_4 ( F_5 ( V_2 -> V_24 ) | F_6 ( V_2 -> V_25 ) ,
V_2 -> V_17 + V_2 -> V_22 . clock ) ;
F_4 ( 0 , V_2 -> V_17 + V_2 -> V_22 . V_14 ) ;
F_4 ( 0 , V_2 -> V_17 + V_2 -> V_22 . V_26 ) ;
F_4 ( V_9 | V_27 ,
V_2 -> V_17 + V_2 -> V_22 . V_28 ) ;
V_2 -> V_29 = V_30 ;
}
static void
F_7 ( struct V_1 * V_2 , T_1 V_31 )
{
if ( V_2 -> V_29 == V_30 ) {
V_2 -> V_32 = V_33 ;
return;
}
switch ( V_31 ) {
case V_34 :
case V_35 :
V_2 -> V_32 = V_36 ;
V_2 -> V_29 = V_37 ;
break;
case V_38 :
if ( V_2 -> V_4 -> V_10 & V_12 ) {
V_2 -> V_32 = V_39 ;
V_2 -> V_29 =
V_40 ;
break;
}
case V_41 :
case V_42 :
if ( ( V_2 -> V_43 == 0 )
|| ( V_2 -> V_44
&& ( V_2 -> V_45 != 0 ) ) ) {
if ( V_2 -> V_46 || V_2 -> V_44 ) {
V_2 -> V_32 = V_33 ;
V_2 -> V_29 = V_30 ;
} else {
V_2 -> V_32 =
V_47 ;
V_2 -> V_29 =
V_48 ;
}
} else {
V_2 -> V_32 = V_49 ;
V_2 -> V_29 =
V_50 ;
V_2 -> V_43 -- ;
}
break;
case V_51 :
if ( V_2 -> V_4 -> V_10 & V_12 ) {
V_2 -> V_32 = V_39 ;
V_2 -> V_29 =
V_40 ;
break;
}
case V_52 :
if ( V_2 -> V_43 == 0 ) {
V_2 -> V_32 = V_33 ;
V_2 -> V_29 = V_30 ;
break;
}
case V_53 :
if ( V_31 != V_53 )
V_2 -> V_32 = V_54 ;
else {
V_2 -> V_32 = V_55 ;
V_2 -> V_43 -- ;
}
V_2 -> V_29 = V_56 ;
if ( ( V_2 -> V_43 == 1 ) || V_2 -> V_44 )
V_2 -> V_6 &= ~ V_7 ;
break;
case V_57 :
V_2 -> V_32 = V_58 ;
V_2 -> V_29 = V_30 ;
break;
case V_59 :
case V_60 :
case V_61 :
V_2 -> V_32 = V_33 ;
V_2 -> V_29 = V_30 ;
V_2 -> V_62 = - V_63 ;
break;
default:
F_8 ( & V_2 -> V_64 . V_65 ,
L_1
L_2 ,
V_2 -> V_29 , V_31 , V_2 -> V_4 -> V_14 ,
V_2 -> V_4 -> V_10 ) ;
V_2 -> V_32 = V_33 ;
F_3 ( V_2 ) ;
V_2 -> V_62 = - V_66 ;
}
}
static void F_9 ( struct V_1 * V_2 )
{
V_2 -> V_4 = V_2 -> V_67 ;
V_2 -> V_45 = 0 ;
V_2 -> V_43 = V_2 -> V_4 -> V_68 ;
V_2 -> V_44 = 0 ;
V_2 -> V_62 = 0 ;
F_1 ( V_2 , V_2 -> V_67 ) ;
F_4 ( V_2 -> V_6 | V_69 ,
V_2 -> V_17 + V_2 -> V_22 . V_28 ) ;
}
static void
F_10 ( struct V_1 * V_2 )
{
switch( V_2 -> V_32 ) {
case V_47 :
F_11 ( V_2 -> V_70 == 0 ) ;
V_2 -> V_67 ++ ;
V_2 -> V_70 -- ;
F_9 ( V_2 ) ;
if ( V_2 -> V_71 )
F_12 ( 5 ) ;
V_2 -> V_46 = V_2 -> V_70 == 1 ;
break;
case V_54 :
F_4 ( V_2 -> V_6 ,
V_2 -> V_17 + V_2 -> V_22 . V_28 ) ;
break;
case V_36 :
F_4 ( V_2 -> V_13 ,
V_2 -> V_17 + V_2 -> V_22 . V_72 ) ;
F_4 ( V_2 -> V_6 ,
V_2 -> V_17 + V_2 -> V_22 . V_28 ) ;
break;
case V_39 :
F_4 ( V_2 -> V_15 ,
V_2 -> V_17 + V_2 -> V_22 . V_72 ) ;
F_4 ( V_2 -> V_6 ,
V_2 -> V_17 + V_2 -> V_22 . V_28 ) ;
break;
case V_49 :
F_4 ( V_2 -> V_4 -> V_73 [ V_2 -> V_45 ++ ] ,
V_2 -> V_17 + V_2 -> V_22 . V_72 ) ;
F_4 ( V_2 -> V_6 ,
V_2 -> V_17 + V_2 -> V_22 . V_28 ) ;
break;
case V_55 :
V_2 -> V_4 -> V_73 [ V_2 -> V_45 ++ ] =
F_13 ( V_2 -> V_17 + V_2 -> V_22 . V_72 ) ;
F_4 ( V_2 -> V_6 ,
V_2 -> V_17 + V_2 -> V_22 . V_28 ) ;
break;
case V_58 :
V_2 -> V_4 -> V_73 [ V_2 -> V_45 ++ ] =
F_13 ( V_2 -> V_17 + V_2 -> V_22 . V_72 ) ;
V_2 -> V_6 &= ~ V_8 ;
F_4 ( V_2 -> V_6 | V_27 ,
V_2 -> V_17 + V_2 -> V_22 . V_28 ) ;
V_2 -> V_74 = 0 ;
if ( V_2 -> V_71 )
F_12 ( 5 ) ;
F_14 ( & V_2 -> V_75 ) ;
break;
case V_76 :
default:
F_8 ( & V_2 -> V_64 . V_65 ,
L_3 ,
V_2 -> V_32 ) ;
V_2 -> V_62 = - V_66 ;
case V_33 :
V_2 -> V_6 &= ~ V_8 ;
F_4 ( V_2 -> V_6 | V_27 ,
V_2 -> V_17 + V_2 -> V_22 . V_28 ) ;
V_2 -> V_74 = 0 ;
F_14 ( & V_2 -> V_75 ) ;
break;
}
}
static void
F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_73 [ 2 ] ;
V_73 [ 0 ] = F_13 ( V_2 -> V_17 + V_77 ) ;
V_73 [ 1 ] = F_13 ( V_2 -> V_17 + V_78 ) ;
memcpy ( V_4 -> V_73 , V_73 , V_4 -> V_68 ) ;
}
static int
F_16 ( struct V_1 * V_2 )
{
T_1 V_79 , V_31 ;
V_79 = F_13 ( V_2 -> V_17 +
V_20 ) ;
if ( ! V_79 )
return V_80 ;
V_31 = F_13 ( V_2 -> V_17 +
V_81 ) ;
if ( V_31 & V_82 ) {
V_2 -> V_62 = - V_66 ;
goto V_83;
}
V_2 -> V_62 = 0 ;
if ( V_2 -> V_70 == 1 && V_2 -> V_67 [ 0 ] . V_10 & V_11 ) {
F_15 ( V_2 , V_2 -> V_67 ) ;
V_2 -> V_67 ++ ;
V_2 -> V_70 -- ;
}
else if ( V_2 -> V_70 == 2 &&
! ( V_2 -> V_67 [ 0 ] . V_10 & V_11 ) &&
V_2 -> V_67 [ 1 ] . V_10 & V_11 ) {
F_15 ( V_2 , V_2 -> V_67 + 1 ) ;
V_2 -> V_67 += 2 ;
V_2 -> V_70 -= 2 ;
}
V_83:
F_4 ( 0 , V_2 -> V_17 + V_18 ) ;
F_4 ( 0 , V_2 -> V_17 +
V_20 ) ;
V_2 -> V_74 = 0 ;
F_14 ( & V_2 -> V_75 ) ;
return V_84 ;
}
static T_2
F_17 ( int V_85 , void * V_86 )
{
struct V_1 * V_2 = V_86 ;
unsigned long V_10 ;
T_1 V_31 ;
T_2 V_62 = V_80 ;
F_18 ( & V_2 -> V_87 , V_10 ) ;
if ( V_2 -> V_16 )
V_62 = F_16 ( V_2 ) ;
while ( F_13 ( V_2 -> V_17 + V_2 -> V_22 . V_28 ) &
V_88 ) {
V_31 = F_13 ( V_2 -> V_17 + V_2 -> V_22 . V_31 ) ;
F_7 ( V_2 , V_31 ) ;
F_10 ( V_2 ) ;
if ( V_2 -> V_89 )
F_4 ( V_2 -> V_6 | V_88 ,
V_2 -> V_17 + V_2 -> V_22 . V_28 ) ;
V_62 = V_84 ;
}
F_19 ( & V_2 -> V_87 , V_10 ) ;
return V_62 ;
}
static void
F_20 ( struct V_1 * V_2 )
{
long V_90 ;
unsigned long V_10 ;
char abort = 0 ;
V_90 = F_21 ( V_2 -> V_75 ,
! V_2 -> V_74 , V_2 -> V_64 . V_91 ) ;
F_18 ( & V_2 -> V_87 , V_10 ) ;
if ( ! V_90 ) {
V_2 -> V_62 = - V_92 ;
abort = 1 ;
} else if ( V_90 < 0 ) {
V_2 -> V_62 = V_90 ;
abort = 1 ;
}
if ( abort && V_2 -> V_74 ) {
V_2 -> V_44 = 1 ;
F_19 ( & V_2 -> V_87 , V_10 ) ;
V_90 = F_21 ( V_2 -> V_75 ,
! V_2 -> V_74 , V_2 -> V_64 . V_91 ) ;
if ( ( V_90 <= 0 ) && V_2 -> V_74 ) {
V_2 -> V_29 = V_30 ;
F_8 ( & V_2 -> V_64 . V_65 ,
L_4
L_5 , V_2 -> V_74 ,
( int ) V_90 ) ;
F_3 ( V_2 ) ;
}
} else
F_19 ( & V_2 -> V_87 , V_10 ) ;
}
static int
F_22 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_93 )
{
unsigned long V_10 ;
F_18 ( & V_2 -> V_87 , V_10 ) ;
V_2 -> V_29 = V_94 ;
V_2 -> V_46 = V_93 ;
V_2 -> V_74 = 1 ;
F_9 ( V_2 ) ;
F_19 ( & V_2 -> V_87 , V_10 ) ;
F_20 ( V_2 ) ;
return V_2 -> V_62 ;
}
static void
F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_67 ;
T_1 V_73 [ 2 ] ;
memcpy ( V_73 , V_4 -> V_73 , V_4 -> V_68 ) ;
F_4 ( V_73 [ 0 ] , V_2 -> V_17 + V_95 ) ;
F_4 ( V_73 [ 1 ] , V_2 -> V_17 + V_96 ) ;
}
static int
F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_67 = V_2 -> V_67 ;
int V_97 = V_2 -> V_70 ;
unsigned long V_98 ;
unsigned long V_10 ;
F_18 ( & V_2 -> V_87 , V_10 ) ;
V_98 = V_99 |
( V_67 [ 0 ] . V_14 << V_100 ) ;
if ( V_67 [ 0 ] . V_10 & V_12 )
V_98 |= V_101 ;
if ( V_97 == 1 && ! ( V_67 [ 0 ] . V_10 & V_11 ) ) {
T_3 V_68 = V_67 [ 0 ] . V_68 - 1 ;
V_98 |= V_102 |
( V_68 << V_103 ) ;
F_23 ( V_2 ) ;
}
else if ( V_97 == 1 && V_67 [ 0 ] . V_10 & V_11 ) {
T_3 V_68 = V_67 [ 0 ] . V_68 - 1 ;
V_98 |= V_104 |
( V_68 << V_105 ) ;
}
else if ( V_97 == 2 ) {
T_3 V_106 = V_67 [ 0 ] . V_68 - 1 ;
T_3 V_107 = V_67 [ 1 ] . V_68 - 1 ;
V_98 |=
V_104 |
V_102 |
( V_106 << V_103 ) |
( V_107 << V_105 ) |
V_108 ;
F_23 ( V_2 ) ;
}
V_2 -> V_74 = 1 ;
F_4 ( V_98 , V_2 -> V_17 + V_18 ) ;
F_19 ( & V_2 -> V_87 , V_10 ) ;
F_20 ( V_2 ) ;
return V_2 -> V_62 ;
}
static bool
F_25 ( struct V_3 * V_4 )
{
return V_4 -> V_68 <= 8 && V_4 -> V_68 >= 1 ;
}
static bool
F_26 ( struct V_1 * V_2 )
{
struct V_3 * V_67 = V_2 -> V_67 ;
int V_97 = V_2 -> V_70 ;
return false ;
if ( ! V_2 -> V_16 )
return false ;
if ( V_97 == 1 && F_25 ( V_67 ) )
return true ;
if ( V_97 == 2 &&
F_25 ( V_67 ) &&
F_25 ( V_67 + 1 ) &&
! ( V_67 [ 0 ] . V_10 & V_11 ) &&
V_67 [ 1 ] . V_10 & V_11 )
return true ;
return false ;
}
static T_1
F_27 ( struct V_109 * V_110 )
{
return V_111 | V_112 | V_113 ;
}
static int
F_28 ( struct V_109 * V_110 , struct V_3 V_67 [] , int V_97 )
{
struct V_1 * V_2 = F_29 ( V_110 ) ;
int V_62 , V_114 = V_97 ;
F_11 ( V_2 -> V_67 != NULL ) ;
V_2 -> V_67 = V_67 ;
V_2 -> V_70 = V_97 ;
if ( F_26 ( V_2 ) )
V_62 = F_24 ( V_2 ) ;
else
V_62 = F_22 ( V_2 , & V_67 [ 0 ] , V_97 == 1 ) ;
if ( V_62 < 0 )
V_114 = V_62 ;
V_2 -> V_70 = 0 ;
V_2 -> V_67 = NULL ;
return V_114 ;
}
static int
F_30 ( const int V_115 , const int V_116 , const int V_117 )
{
return V_115 / ( 10 * ( V_117 + 1 ) * ( 2 << V_116 ) ) ;
}
static bool
F_31 ( const T_1 V_118 , const T_1 V_115 , T_1 * V_119 ,
T_1 * V_120 )
{
int V_121 , V_122 , V_123 = V_124 ;
int V_117 , V_116 ;
for ( V_116 = 0 ; V_116 <= 7 ; V_116 ++ )
for ( V_117 = 0 ; V_117 <= 15 ; V_117 ++ ) {
V_121 = F_30 ( V_115 , V_116 , V_117 ) ;
V_122 = V_118 - V_121 ;
if ( V_122 >= 0 && V_122 < V_123 ) {
* V_120 = V_117 ;
* V_119 = V_116 ;
V_123 = V_122 ;
}
if ( V_123 == 0 )
return true ;
}
if ( V_123 == V_124 )
return false ;
return true ;
}
static int
F_32 ( struct V_1 * V_2 ,
struct V_125 * V_65 )
{
#if ! F_33 ( V_126 )
return - V_127 ;
#else
const struct V_128 * V_125 ;
struct V_129 * V_130 = V_65 -> V_131 ;
T_1 V_132 , V_115 ;
int V_62 = 0 ;
if ( F_34 ( V_2 -> V_133 ) ) {
V_62 = - V_127 ;
goto V_83;
}
V_115 = F_35 ( V_2 -> V_133 ) ;
if ( F_36 ( V_130 , L_6 , & V_132 ) )
V_132 = 100000 ;
if ( ! F_31 ( V_132 , V_115 ,
& V_2 -> V_25 , & V_2 -> V_24 ) ) {
V_62 = - V_134 ;
goto V_83;
}
V_2 -> V_85 = F_37 ( V_130 , 0 ) ;
V_2 -> V_135 = F_38 ( V_65 , NULL ) ;
if ( F_34 ( V_2 -> V_135 ) ) {
if ( F_39 ( V_2 -> V_135 ) == - V_136 ) {
V_62 = - V_136 ;
goto V_83;
}
} else {
F_40 ( V_2 -> V_135 ) ;
}
V_2 -> V_64 . V_91 = V_137 ;
V_125 = F_41 ( V_138 , V_65 ) ;
if ( ! V_125 )
return - V_127 ;
memcpy ( & V_2 -> V_22 , V_125 -> V_72 , sizeof( V_2 -> V_22 ) ) ;
if ( F_42 ( V_130 , L_7 ) ) {
V_2 -> V_16 = true ;
V_2 -> V_71 = true ;
}
if ( F_42 ( V_130 , L_8 ) ) {
V_2 -> V_16 = false ;
V_2 -> V_71 = true ;
}
if ( F_42 ( V_130 , L_9 ) )
V_2 -> V_89 = true ;
V_83:
return V_62 ;
#endif
}
static int
F_32 ( struct V_1 * V_2 ,
struct V_125 * V_65 )
{
return - V_127 ;
}
static int
F_43 ( struct V_139 * V_140 )
{
struct V_1 * V_2 ;
struct V_141 * V_142 = F_44 ( & V_140 -> V_65 ) ;
struct V_143 * V_144 ;
int V_62 ;
if ( ( ! V_142 && ! V_140 -> V_65 . V_131 ) )
return - V_127 ;
V_2 = F_45 ( & V_140 -> V_65 , sizeof( struct V_1 ) ,
V_145 ) ;
if ( ! V_2 )
return - V_146 ;
V_144 = F_46 ( V_140 , V_147 , 0 ) ;
V_2 -> V_17 = F_47 ( & V_140 -> V_65 , V_144 ) ;
if ( F_34 ( V_2 -> V_17 ) )
return F_39 ( V_2 -> V_17 ) ;
F_48 ( V_2 -> V_64 . V_148 , V_149 L_10 ,
sizeof( V_2 -> V_64 . V_148 ) ) ;
F_49 ( & V_2 -> V_75 ) ;
F_50 ( & V_2 -> V_87 ) ;
#if F_33 ( V_126 )
V_2 -> V_133 = F_51 ( & V_140 -> V_65 , NULL ) ;
if ( ! F_34 ( V_2 -> V_133 ) ) {
F_52 ( V_2 -> V_133 ) ;
F_53 ( V_2 -> V_133 ) ;
}
#endif
if ( V_142 ) {
V_2 -> V_24 = V_142 -> V_24 ;
V_2 -> V_25 = V_142 -> V_25 ;
V_2 -> V_85 = F_54 ( V_140 , 0 ) ;
V_2 -> V_64 . V_91 = F_55 ( V_142 -> V_91 ) ;
V_2 -> V_16 = false ;
memcpy ( & V_2 -> V_22 , & V_150 , sizeof( V_2 -> V_22 ) ) ;
} else if ( V_140 -> V_65 . V_131 ) {
V_62 = F_32 ( V_2 , & V_140 -> V_65 ) ;
if ( V_62 )
goto V_151;
}
if ( V_2 -> V_85 < 0 ) {
V_62 = - V_63 ;
goto V_152;
}
V_2 -> V_64 . V_65 . V_153 = & V_140 -> V_65 ;
V_2 -> V_64 . V_154 = & V_155 ;
V_2 -> V_64 . V_156 = V_157 ;
V_2 -> V_64 . V_158 = V_159 ;
V_2 -> V_64 . V_160 = V_140 -> V_161 ;
V_2 -> V_64 . V_65 . V_131 = V_140 -> V_65 . V_131 ;
F_56 ( V_140 , V_2 ) ;
F_57 ( & V_2 -> V_64 , V_2 ) ;
F_3 ( V_2 ) ;
V_62 = F_58 ( V_2 -> V_85 , F_17 , 0 ,
V_149 , V_2 ) ;
if ( V_62 ) {
F_8 ( & V_2 -> V_64 . V_65 ,
L_11 ,
V_2 -> V_85 , V_62 ) ;
goto V_152;
} else if ( ( V_62 = F_59 ( & V_2 -> V_64 ) ) != 0 ) {
F_8 ( & V_2 -> V_64 . V_65 ,
L_12 , - V_62 ) ;
goto V_162;
}
return 0 ;
V_162:
F_60 ( V_2 -> V_85 , V_2 ) ;
V_152:
if ( ! F_61 ( V_2 -> V_135 ) )
F_62 ( V_2 -> V_135 ) ;
V_151:
#if F_33 ( V_126 )
if ( ! F_34 ( V_2 -> V_133 ) ) {
F_63 ( V_2 -> V_133 ) ;
F_64 ( V_2 -> V_133 ) ;
}
#endif
return V_62 ;
}
static int
F_65 ( struct V_139 * V_65 )
{
struct V_1 * V_2 = F_66 ( V_65 ) ;
F_67 ( & V_2 -> V_64 ) ;
F_60 ( V_2 -> V_85 , V_2 ) ;
if ( ! F_61 ( V_2 -> V_135 ) )
F_62 ( V_2 -> V_135 ) ;
#if F_33 ( V_126 )
if ( ! F_34 ( V_2 -> V_133 ) ) {
F_63 ( V_2 -> V_133 ) ;
F_64 ( V_2 -> V_133 ) ;
}
#endif
return 0 ;
}
