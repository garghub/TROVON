static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
STATIC T_1
F_3 (
struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
T_1 V_9 = 2 ;
switch ( V_7 -> V_10 . V_11 ) {
case V_12 :
if ( ( V_5 -> V_13 & V_14 ) &&
V_7 -> V_10 . V_15 > 0 &&
V_7 -> V_16 . V_17 > 0 )
V_9 ++ ;
break;
case V_18 :
if ( ( V_5 -> V_13 & V_19 ) &&
V_7 -> V_16 . V_20 > 0 )
V_9 ++ ;
break;
case V_21 :
if ( ( V_5 -> V_13 & V_22 ) &&
V_7 -> V_16 . V_17 > 0 )
V_9 ++ ;
break;
case V_23 :
case V_24 :
break;
default:
ASSERT ( 0 ) ;
break;
}
if ( ! F_4 ( V_7 ) )
return V_9 ;
switch ( V_7 -> V_10 . V_25 ) {
case V_12 :
if ( ( V_5 -> V_13 & V_26 ) &&
V_7 -> V_10 . V_27 > 0 &&
V_7 -> V_28 -> V_17 > 0 )
V_9 ++ ;
break;
case V_18 :
if ( ( V_5 -> V_13 & V_29 ) &&
V_7 -> V_28 -> V_20 > 0 )
V_9 ++ ;
break;
case V_21 :
if ( ( V_5 -> V_13 & V_30 ) &&
V_7 -> V_28 -> V_17 > 0 )
V_9 ++ ;
break;
default:
ASSERT ( 0 ) ;
break;
}
return V_9 ;
}
STATIC void
F_5 (
struct V_6 * V_7 ,
struct V_31 * V_32 ,
int V_33 ,
int type )
{
T_2 * V_34 ;
V_34 = F_6 ( F_7 ( V_7 , V_33 ) , V_35 ) ;
if ( V_33 == V_36 )
V_7 -> V_37 -> V_38 = V_34 ;
else
V_7 -> V_37 -> V_39 = V_34 ;
V_32 -> V_40 = V_34 ;
V_32 -> V_41 = F_8 ( V_7 , V_34 , V_33 ) ;
V_32 -> V_42 = type ;
}
STATIC void
F_9 (
struct V_2 * V_3 ,
struct V_31 * V_32 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
T_1 V_9 ;
T_3 V_43 ;
T_4 * V_44 ;
V_32 -> V_40 = & V_5 -> V_45 ;
V_32 -> V_41 = sizeof( V_46 ) ;
V_32 -> V_42 = V_47 ;
V_32 ++ ;
V_9 = 1 ;
V_32 -> V_40 = & V_7 -> V_10 ;
V_32 -> V_41 = sizeof( struct V_48 ) ;
V_32 -> V_42 = V_49 ;
V_32 ++ ;
V_9 ++ ;
V_44 = V_7 -> V_50 ;
ASSERT ( V_7 -> V_10 . V_51 == 1 || F_10 ( & V_44 -> V_52 ) ) ;
if ( V_7 -> V_10 . V_51 == 1 ) {
if ( ! F_10 ( & V_44 -> V_52 ) ) {
ASSERT ( V_7 -> V_10 . V_53 <= V_54 ) ;
V_7 -> V_10 . V_55 = V_7 -> V_10 . V_53 ;
} else {
V_7 -> V_10 . V_51 = 2 ;
V_7 -> V_10 . V_55 = 0 ;
memset ( & ( V_7 -> V_10 . V_56 [ 0 ] ) , 0 , sizeof( V_7 -> V_10 . V_56 ) ) ;
}
}
switch ( V_7 -> V_10 . V_11 ) {
case V_12 :
V_5 -> V_13 &=
~ ( V_22 | V_19 |
V_57 | V_58 ) ;
if ( ( V_5 -> V_13 & V_14 ) &&
V_7 -> V_10 . V_15 > 0 &&
V_7 -> V_16 . V_17 > 0 ) {
ASSERT ( V_7 -> V_16 . V_59 . V_60 != NULL ) ;
ASSERT ( V_7 -> V_16 . V_17 / sizeof( T_2 ) > 0 ) ;
ASSERT ( V_5 -> V_38 == NULL ) ;
#ifdef F_11
if ( V_7 -> V_10 . V_15 == V_7 -> V_16 . V_17 /
( T_1 ) sizeof( T_2 ) ) {
V_32 -> V_40 = V_7 -> V_16 . V_59 . V_60 ;
V_32 -> V_41 = V_7 -> V_16 . V_17 ;
V_32 -> V_42 = V_61 ;
} else
#endif
{
F_5 ( V_7 , V_32 ,
V_36 , V_61 ) ;
}
ASSERT ( V_32 -> V_41 <= V_7 -> V_16 . V_17 ) ;
V_5 -> V_45 . V_62 = V_32 -> V_41 ;
V_32 ++ ;
V_9 ++ ;
} else {
V_5 -> V_13 &= ~ V_14 ;
}
break;
case V_18 :
V_5 -> V_13 &=
~ ( V_22 | V_14 |
V_57 | V_58 ) ;
if ( ( V_5 -> V_13 & V_19 ) &&
V_7 -> V_16 . V_20 > 0 ) {
ASSERT ( V_7 -> V_16 . V_63 != NULL ) ;
V_32 -> V_40 = V_7 -> V_16 . V_63 ;
V_32 -> V_41 = V_7 -> V_16 . V_20 ;
V_32 -> V_42 = V_64 ;
V_32 ++ ;
V_9 ++ ;
V_5 -> V_45 . V_62 = V_7 -> V_16 . V_20 ;
} else {
ASSERT ( ! ( V_5 -> V_13 &
V_19 ) ) ;
#ifdef F_12
if ( V_5 -> V_65 > 0 ) {
ASSERT ( V_5 -> V_65 ==
V_7 -> V_16 . V_20 ) ;
ASSERT ( memcmp ( V_5 -> V_66 ,
V_7 -> V_16 . V_63 ,
V_5 -> V_65 ) == 0 ) ;
} else {
ASSERT ( V_7 -> V_16 . V_20 == 0 ) ;
}
#endif
V_5 -> V_13 &= ~ V_19 ;
}
break;
case V_21 :
V_5 -> V_13 &=
~ ( V_14 | V_19 |
V_57 | V_58 ) ;
if ( ( V_5 -> V_13 & V_22 ) &&
V_7 -> V_16 . V_17 > 0 ) {
ASSERT ( V_7 -> V_16 . V_59 . V_67 != NULL ) ;
ASSERT ( V_7 -> V_10 . V_68 > 0 ) ;
V_32 -> V_40 = V_7 -> V_16 . V_59 . V_67 ;
V_43 = F_13 ( V_7 -> V_16 . V_17 , 4 ) ;
ASSERT ( ( V_7 -> V_16 . V_69 == 0 ) ||
( V_7 -> V_16 . V_69 == V_43 ) ) ;
V_32 -> V_41 = ( int ) V_43 ;
V_32 -> V_42 = V_70 ;
V_32 ++ ;
V_9 ++ ;
V_5 -> V_45 . V_62 = ( unsigned ) V_43 ;
} else {
V_5 -> V_13 &= ~ V_22 ;
}
break;
case V_23 :
V_5 -> V_13 &=
~ ( V_22 | V_19 |
V_14 | V_58 ) ;
if ( V_5 -> V_13 & V_57 ) {
V_5 -> V_45 . V_71 . V_72 =
V_7 -> V_16 . V_73 . V_74 ;
}
break;
case V_24 :
V_5 -> V_13 &=
~ ( V_22 | V_19 |
V_14 | V_57 ) ;
if ( V_5 -> V_13 & V_58 ) {
V_5 -> V_45 . V_71 . V_75 =
V_7 -> V_16 . V_73 . V_76 ;
}
break;
default:
ASSERT ( 0 ) ;
break;
}
if ( ! F_4 ( V_7 ) ) {
V_5 -> V_13 &=
~ ( V_30 | V_29 | V_26 ) ;
goto V_77;
}
switch ( V_7 -> V_10 . V_25 ) {
case V_12 :
V_5 -> V_13 &=
~ ( V_30 | V_29 ) ;
if ( ( V_5 -> V_13 & V_26 ) &&
V_7 -> V_10 . V_27 > 0 &&
V_7 -> V_28 -> V_17 > 0 ) {
ASSERT ( V_7 -> V_28 -> V_17 / sizeof( T_2 ) ==
V_7 -> V_10 . V_27 ) ;
ASSERT ( V_7 -> V_28 -> V_59 . V_60 != NULL ) ;
#ifdef F_11
V_32 -> V_40 = V_7 -> V_28 -> V_59 . V_60 ;
V_32 -> V_41 = V_7 -> V_28 -> V_17 ;
V_32 -> V_42 = V_78 ;
#else
ASSERT ( V_5 -> V_39 == NULL ) ;
F_5 ( V_7 , V_32 ,
V_79 , V_78 ) ;
#endif
V_5 -> V_45 . V_80 = V_32 -> V_41 ;
V_32 ++ ;
V_9 ++ ;
} else {
V_5 -> V_13 &= ~ V_26 ;
}
break;
case V_18 :
V_5 -> V_13 &=
~ ( V_30 | V_26 ) ;
if ( ( V_5 -> V_13 & V_29 ) &&
V_7 -> V_28 -> V_20 > 0 ) {
ASSERT ( V_7 -> V_28 -> V_63 != NULL ) ;
V_32 -> V_40 = V_7 -> V_28 -> V_63 ;
V_32 -> V_41 = V_7 -> V_28 -> V_20 ;
V_32 -> V_42 = V_81 ;
V_32 ++ ;
V_9 ++ ;
V_5 -> V_45 . V_80 = V_7 -> V_28 -> V_20 ;
} else {
V_5 -> V_13 &= ~ V_29 ;
}
break;
case V_21 :
V_5 -> V_13 &=
~ ( V_26 | V_29 ) ;
if ( ( V_5 -> V_13 & V_30 ) &&
V_7 -> V_28 -> V_17 > 0 ) {
ASSERT ( V_7 -> V_28 -> V_59 . V_67 != NULL ) ;
V_32 -> V_40 = V_7 -> V_28 -> V_59 . V_67 ;
V_43 = F_13 ( V_7 -> V_28 -> V_17 , 4 ) ;
ASSERT ( ( V_7 -> V_28 -> V_69 == 0 ) ||
( V_7 -> V_28 -> V_69 == V_43 ) ) ;
V_32 -> V_41 = ( int ) V_43 ;
V_32 -> V_42 = V_82 ;
V_32 ++ ;
V_9 ++ ;
V_5 -> V_45 . V_80 = ( unsigned ) V_43 ;
} else {
V_5 -> V_13 &= ~ V_30 ;
}
break;
default:
ASSERT ( 0 ) ;
break;
}
V_77:
V_5 -> V_45 . V_83 = V_84 |
( V_5 -> V_13 & ~ V_85 ) ;
V_5 -> V_45 . V_86 = V_9 ;
}
STATIC void
F_14 (
struct V_2 * V_3 )
{
struct V_6 * V_7 = F_1 ( V_3 ) -> V_8 ;
ASSERT ( F_15 ( V_7 , V_87 ) ) ;
F_16 ( V_7 , V_88 ) ;
F_17 ( & V_7 -> V_89 ) ;
}
STATIC void
F_18 (
struct V_2 * V_3 ,
int remove )
{
struct V_6 * V_7 = F_1 ( V_3 ) -> V_8 ;
F_19 ( V_7 , V_88 ) ;
ASSERT ( F_20 ( & V_7 -> V_89 ) > 0 ) ;
if ( F_21 ( & V_7 -> V_89 ) )
F_22 ( & V_7 -> V_90 , V_91 ) ;
}
STATIC T_1
F_23 (
struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
if ( F_24 ( V_7 ) > 0 )
return V_92 ;
if ( ! F_25 ( V_7 , V_93 ) )
return V_94 ;
if ( ! F_26 ( V_7 ) ) {
return V_95 ;
}
if ( V_7 -> V_90 & V_96 ) {
F_27 ( V_7 ) ;
F_28 ( V_7 , V_93 ) ;
return V_92 ;
}
#ifdef F_29
if ( ! F_30 ( V_7 -> V_50 ) ) {
ASSERT ( V_5 -> V_13 != 0 ) ;
ASSERT ( V_5 -> V_97 == 0 ) ;
ASSERT ( V_3 -> V_98 & V_99 ) ;
}
#endif
return V_100 ;
}
STATIC void
F_31 (
struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
unsigned short V_101 ;
ASSERT ( V_7 -> V_37 != NULL ) ;
ASSERT ( F_15 ( V_7 , V_87 ) ) ;
if ( V_5 -> V_38 != NULL ) {
ASSERT ( V_7 -> V_10 . V_11 == V_12 ) ;
ASSERT ( V_7 -> V_10 . V_15 > 0 ) ;
ASSERT ( V_5 -> V_13 & V_14 ) ;
ASSERT ( V_7 -> V_16 . V_17 > 0 ) ;
F_32 ( V_5 -> V_38 ) ;
V_5 -> V_38 = NULL ;
}
if ( V_5 -> V_39 != NULL ) {
ASSERT ( V_7 -> V_10 . V_25 == V_12 ) ;
ASSERT ( V_7 -> V_10 . V_27 > 0 ) ;
ASSERT ( V_5 -> V_13 & V_26 ) ;
ASSERT ( V_7 -> V_28 -> V_17 > 0 ) ;
F_32 ( V_5 -> V_39 ) ;
V_5 -> V_39 = NULL ;
}
V_101 = V_5 -> V_102 ;
V_5 -> V_102 = 0 ;
if ( V_101 )
F_28 ( V_7 , V_101 ) ;
}
STATIC T_5
F_33 (
struct V_2 * V_3 ,
T_5 V_103 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
if ( F_34 ( V_7 , V_96 ) ) {
F_18 ( V_3 , 0 ) ;
return - 1 ;
}
return V_103 ;
}
STATIC bool
F_35 (
struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_104 * V_105 ;
bool V_106 = true ;
ASSERT ( F_15 ( V_7 , V_93 ) ) ;
if ( ! F_36 ( V_7 ) ||
! ( V_3 -> V_98 & V_99 ) ) {
F_28 ( V_7 , V_93 ) ;
return true ;
}
V_105 = F_37 ( V_7 -> V_50 -> V_107 , V_5 -> V_45 . V_108 ,
V_5 -> V_45 . V_109 , V_110 ) ;
F_28 ( V_7 , V_93 ) ;
if ( ! V_105 )
return true ;
if ( F_38 ( V_105 ) )
F_39 ( V_105 ) ;
if ( F_40 ( V_105 ) )
V_106 = false ;
F_41 ( V_105 ) ;
return V_106 ;
}
STATIC void
F_42 (
struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
ASSERT ( F_15 ( V_7 , V_93 ) ) ;
ASSERT ( F_36 ( V_7 ) ) ;
ASSERT ( F_30 ( V_7 -> V_50 ) || V_5 -> V_13 != 0 ) ;
( void ) F_43 ( V_7 , V_111 ) ;
F_28 ( V_7 , V_93 ) ;
}
STATIC void
F_44 (
struct V_2 * V_3 ,
T_5 V_103 )
{
F_1 ( V_3 ) -> V_112 = V_103 ;
}
void
F_45 (
struct V_6 * V_7 ,
struct V_113 * V_44 )
{
struct V_1 * V_5 ;
ASSERT ( V_7 -> V_37 == NULL ) ;
V_5 = V_7 -> V_37 = F_46 ( V_114 , V_35 ) ;
V_5 -> V_8 = V_7 ;
F_47 ( V_44 , & V_5 -> V_4 , V_115 ,
& V_116 ) ;
V_5 -> V_45 . V_117 = V_115 ;
V_5 -> V_45 . V_118 = V_7 -> V_119 ;
V_5 -> V_45 . V_108 = V_7 -> V_120 . V_121 ;
V_5 -> V_45 . V_109 = V_7 -> V_120 . V_122 ;
V_5 -> V_45 . V_123 = V_7 -> V_120 . V_124 ;
}
void
F_48 (
T_6 * V_7 )
{
#ifdef F_12
if ( V_7 -> V_37 -> V_65 != 0 ) {
F_32 ( V_7 -> V_37 -> V_66 ) ;
}
#endif
F_49 ( V_114 , V_7 -> V_37 ) ;
}
void
F_50 (
struct V_104 * V_105 ,
struct V_2 * V_3 )
{
struct V_1 * V_5 ;
struct V_2 * V_125 ;
struct V_2 * V_126 ;
struct V_2 * V_127 ;
struct V_128 * V_129 = V_3 -> V_130 ;
int V_131 = 0 ;
V_125 = V_105 -> V_132 ;
V_127 = NULL ;
while ( V_125 != NULL ) {
if ( V_3 -> V_133 != F_50 ) {
V_127 = V_125 ;
V_125 = V_125 -> V_134 ;
continue;
}
V_126 = V_125 -> V_134 ;
if ( ! V_127 ) {
V_105 -> V_132 = V_126 ;
} else {
V_127 -> V_134 = V_126 ;
}
V_125 -> V_134 = V_3 -> V_134 ;
V_3 -> V_134 = V_125 ;
V_5 = F_1 ( V_125 ) ;
if ( V_5 -> V_97 && V_125 -> V_135 == V_5 -> V_136 )
V_131 ++ ;
V_125 = V_126 ;
}
V_5 = F_1 ( V_3 ) ;
if ( V_5 -> V_97 && V_3 -> V_135 == V_5 -> V_136 )
V_131 ++ ;
if ( V_131 ) {
struct V_2 * V_137 [ V_131 ] ;
int V_138 = 0 ;
F_51 ( & V_129 -> V_139 ) ;
for ( V_125 = V_3 ; V_125 ; V_125 = V_125 -> V_134 ) {
V_5 = F_1 ( V_125 ) ;
if ( V_5 -> V_97 &&
V_125 -> V_135 == V_5 -> V_136 ) {
V_137 [ V_138 ++ ] = V_125 ;
}
ASSERT ( V_138 <= V_131 ) ;
}
F_52 ( V_129 , V_137 , V_138 ) ;
}
for ( V_125 = V_3 ; V_125 ; V_125 = V_126 ) {
V_126 = V_125 -> V_134 ;
V_125 -> V_134 = NULL ;
V_5 = F_1 ( V_125 ) ;
V_5 -> V_97 = 0 ;
V_5 -> V_140 = 0 ;
F_27 ( V_5 -> V_8 ) ;
}
}
void
F_53 (
T_6 * V_7 )
{
T_7 * V_5 = V_7 -> V_37 ;
if ( V_5 ) {
struct V_128 * V_129 = V_5 -> V_4 . V_130 ;
if ( V_5 -> V_4 . V_98 & V_99 ) {
F_51 ( & V_129 -> V_139 ) ;
if ( V_5 -> V_4 . V_98 & V_99 ) {
F_54 ( V_129 , ( V_141 * ) V_5 ) ;
} else
F_55 ( & V_129 -> V_139 ) ;
}
V_5 -> V_97 = 0 ;
V_5 -> V_140 = 0 ;
V_5 -> V_13 = 0 ;
}
F_27 ( V_7 ) ;
}
void
F_56 (
struct V_104 * V_105 ,
struct V_2 * V_3 )
{
F_53 ( F_1 ( V_3 ) -> V_8 ) ;
}
int
F_57 (
T_8 * V_142 ,
V_46 * V_143 )
{
if ( V_142 -> V_41 == sizeof( V_144 ) ) {
V_144 * V_145 = V_142 -> V_40 ;
V_143 -> V_117 = V_145 -> V_117 ;
V_143 -> V_86 = V_145 -> V_86 ;
V_143 -> V_83 = V_145 -> V_83 ;
V_143 -> V_80 = V_145 -> V_80 ;
V_143 -> V_62 = V_145 -> V_62 ;
V_143 -> V_118 = V_145 -> V_118 ;
memcpy ( V_143 -> V_71 . V_75 . V_146 ,
V_145 -> V_71 . V_75 . V_146 ,
sizeof( V_147 ) ) ;
V_143 -> V_108 = V_145 -> V_108 ;
V_143 -> V_109 = V_145 -> V_109 ;
V_143 -> V_123 = V_145 -> V_123 ;
return 0 ;
} else if ( V_142 -> V_41 == sizeof( V_148 ) ) {
V_148 * V_149 = V_142 -> V_40 ;
V_143 -> V_117 = V_149 -> V_117 ;
V_143 -> V_86 = V_149 -> V_86 ;
V_143 -> V_83 = V_149 -> V_83 ;
V_143 -> V_80 = V_149 -> V_80 ;
V_143 -> V_62 = V_149 -> V_62 ;
V_143 -> V_118 = V_149 -> V_118 ;
memcpy ( V_143 -> V_71 . V_75 . V_146 ,
V_149 -> V_71 . V_75 . V_146 ,
sizeof( V_147 ) ) ;
V_143 -> V_108 = V_149 -> V_108 ;
V_143 -> V_109 = V_149 -> V_109 ;
V_143 -> V_123 = V_149 -> V_123 ;
return 0 ;
}
return V_150 ;
}
