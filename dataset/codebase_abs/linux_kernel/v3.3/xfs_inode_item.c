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
V_5 -> V_10 . V_11 |= V_12 ;
switch ( V_7 -> V_13 . V_14 ) {
case V_15 :
V_5 -> V_10 . V_11 &=
~ ( V_16 | V_17 |
V_18 | V_19 ) ;
if ( ( V_5 -> V_10 . V_11 & V_20 ) &&
( V_7 -> V_13 . V_21 > 0 ) &&
( V_7 -> V_22 . V_23 > 0 ) ) {
ASSERT ( V_7 -> V_22 . V_24 . V_25 != NULL ) ;
V_9 ++ ;
} else {
V_5 -> V_10 . V_11 &= ~ V_20 ;
}
break;
case V_26 :
V_5 -> V_10 . V_11 &=
~ ( V_16 | V_20 |
V_18 | V_19 ) ;
if ( ( V_5 -> V_10 . V_11 & V_17 ) &&
( V_7 -> V_22 . V_27 > 0 ) ) {
ASSERT ( V_7 -> V_22 . V_28 != NULL ) ;
V_9 ++ ;
} else {
ASSERT ( ! ( V_5 -> V_10 . V_11 &
V_17 ) ) ;
#ifdef F_4
if ( V_5 -> V_29 > 0 ) {
ASSERT ( V_5 -> V_29 ==
V_7 -> V_22 . V_27 ) ;
ASSERT ( memcmp ( V_5 -> V_30 ,
V_7 -> V_22 . V_28 ,
V_5 -> V_29 ) == 0 ) ;
} else {
ASSERT ( V_7 -> V_22 . V_27 == 0 ) ;
}
#endif
V_5 -> V_10 . V_11 &= ~ V_17 ;
}
break;
case V_31 :
V_5 -> V_10 . V_11 &=
~ ( V_20 | V_17 |
V_18 | V_19 ) ;
if ( ( V_5 -> V_10 . V_11 & V_16 ) &&
( V_7 -> V_22 . V_23 > 0 ) ) {
ASSERT ( V_7 -> V_22 . V_24 . V_32 != NULL ) ;
ASSERT ( V_7 -> V_13 . V_33 > 0 ) ;
V_9 ++ ;
} else {
V_5 -> V_10 . V_11 &= ~ V_16 ;
}
break;
case V_34 :
V_5 -> V_10 . V_11 &=
~ ( V_16 | V_17 |
V_20 | V_19 ) ;
break;
case V_35 :
V_5 -> V_10 . V_11 &=
~ ( V_16 | V_17 |
V_20 | V_18 ) ;
break;
default:
ASSERT ( 0 ) ;
break;
}
if ( ! F_5 ( V_7 ) ) {
V_5 -> V_10 . V_11 &=
~ ( V_36 | V_37 | V_38 ) ;
return V_9 ;
}
switch ( V_7 -> V_13 . V_39 ) {
case V_15 :
V_5 -> V_10 . V_11 &=
~ ( V_36 | V_37 ) ;
if ( ( V_5 -> V_10 . V_11 & V_38 ) &&
( V_7 -> V_13 . V_40 > 0 ) &&
( V_7 -> V_41 -> V_23 > 0 ) ) {
ASSERT ( V_7 -> V_41 -> V_24 . V_25 != NULL ) ;
V_9 ++ ;
} else {
V_5 -> V_10 . V_11 &= ~ V_38 ;
}
break;
case V_26 :
V_5 -> V_10 . V_11 &=
~ ( V_36 | V_38 ) ;
if ( ( V_5 -> V_10 . V_11 & V_37 ) &&
( V_7 -> V_41 -> V_27 > 0 ) ) {
ASSERT ( V_7 -> V_41 -> V_28 != NULL ) ;
V_9 ++ ;
} else {
V_5 -> V_10 . V_11 &= ~ V_37 ;
}
break;
case V_31 :
V_5 -> V_10 . V_11 &=
~ ( V_38 | V_37 ) ;
if ( ( V_5 -> V_10 . V_11 & V_36 ) &&
( V_7 -> V_41 -> V_23 > 0 ) ) {
ASSERT ( V_7 -> V_41 -> V_24 . V_32 != NULL ) ;
V_9 ++ ;
} else {
V_5 -> V_10 . V_11 &= ~ V_36 ;
}
break;
default:
ASSERT ( 0 ) ;
break;
}
return V_9 ;
}
STATIC void
F_6 (
struct V_6 * V_7 ,
struct V_42 * V_43 ,
int V_44 ,
int type )
{
T_2 * V_45 ;
V_45 = F_7 ( F_8 ( V_7 , V_44 ) , V_46 ) ;
if ( V_44 == V_47 )
V_7 -> V_48 -> V_49 = V_45 ;
else
V_7 -> V_48 -> V_50 = V_45 ;
V_43 -> V_51 = V_45 ;
V_43 -> V_52 = F_9 ( V_7 , V_45 , V_44 ) ;
V_43 -> V_53 = type ;
}
STATIC void
F_10 (
struct V_2 * V_3 ,
struct V_42 * V_43 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
T_1 V_9 ;
T_3 V_54 ;
T_4 * V_55 ;
V_43 -> V_51 = & V_5 -> V_10 ;
V_43 -> V_52 = sizeof( V_56 ) ;
V_43 -> V_53 = V_57 ;
V_43 ++ ;
V_9 = 1 ;
if ( V_7 -> V_58 ) {
V_7 -> V_58 = 0 ;
F_11 () ;
}
F_12 ( V_7 ) ;
V_43 -> V_51 = & V_7 -> V_13 ;
V_43 -> V_52 = sizeof( struct V_59 ) ;
V_43 -> V_53 = V_60 ;
V_43 ++ ;
V_9 ++ ;
V_5 -> V_10 . V_11 |= V_12 ;
V_55 = V_7 -> V_61 ;
ASSERT ( V_7 -> V_13 . V_62 == 1 || F_13 ( & V_55 -> V_63 ) ) ;
if ( V_7 -> V_13 . V_62 == 1 ) {
if ( ! F_13 ( & V_55 -> V_63 ) ) {
ASSERT ( V_7 -> V_13 . V_64 <= V_65 ) ;
V_7 -> V_13 . V_66 = V_7 -> V_13 . V_64 ;
} else {
V_7 -> V_13 . V_62 = 2 ;
V_7 -> V_13 . V_66 = 0 ;
memset ( & ( V_7 -> V_13 . V_67 [ 0 ] ) , 0 , sizeof( V_7 -> V_13 . V_67 ) ) ;
}
}
switch ( V_7 -> V_13 . V_14 ) {
case V_15 :
ASSERT ( ! ( V_5 -> V_10 . V_11 &
( V_16 | V_17 |
V_18 | V_19 ) ) ) ;
if ( V_5 -> V_10 . V_11 & V_20 ) {
ASSERT ( V_7 -> V_22 . V_23 > 0 ) ;
ASSERT ( V_7 -> V_22 . V_24 . V_25 != NULL ) ;
ASSERT ( V_7 -> V_13 . V_21 > 0 ) ;
ASSERT ( V_5 -> V_49 == NULL ) ;
ASSERT ( ( V_7 -> V_22 . V_23 /
( T_1 ) sizeof( T_2 ) ) > 0 ) ;
#ifdef F_14
if ( V_7 -> V_13 . V_21 == V_7 -> V_22 . V_23 /
( T_1 ) sizeof( T_2 ) ) {
V_43 -> V_51 = V_7 -> V_22 . V_24 . V_25 ;
V_43 -> V_52 = V_7 -> V_22 . V_23 ;
V_43 -> V_53 = V_68 ;
} else
#endif
{
F_6 ( V_7 , V_43 ,
V_47 , V_68 ) ;
}
ASSERT ( V_43 -> V_52 <= V_7 -> V_22 . V_23 ) ;
V_5 -> V_10 . V_69 = V_43 -> V_52 ;
V_43 ++ ;
V_9 ++ ;
}
break;
case V_26 :
ASSERT ( ! ( V_5 -> V_10 . V_11 &
( V_16 | V_20 |
V_18 | V_19 ) ) ) ;
if ( V_5 -> V_10 . V_11 & V_17 ) {
ASSERT ( V_7 -> V_22 . V_27 > 0 ) ;
ASSERT ( V_7 -> V_22 . V_28 != NULL ) ;
V_43 -> V_51 = V_7 -> V_22 . V_28 ;
V_43 -> V_52 = V_7 -> V_22 . V_27 ;
V_43 -> V_53 = V_70 ;
V_43 ++ ;
V_9 ++ ;
V_5 -> V_10 . V_69 = V_7 -> V_22 . V_27 ;
}
break;
case V_31 :
ASSERT ( ! ( V_5 -> V_10 . V_11 &
( V_17 | V_20 |
V_18 | V_19 ) ) ) ;
if ( V_5 -> V_10 . V_11 & V_16 ) {
ASSERT ( V_7 -> V_22 . V_23 > 0 ) ;
ASSERT ( V_7 -> V_22 . V_24 . V_32 != NULL ) ;
ASSERT ( V_7 -> V_13 . V_33 > 0 ) ;
V_43 -> V_51 = V_7 -> V_22 . V_24 . V_32 ;
V_54 = F_15 ( V_7 -> V_22 . V_23 , 4 ) ;
ASSERT ( ( V_7 -> V_22 . V_71 == 0 ) ||
( V_7 -> V_22 . V_71 == V_54 ) ) ;
V_43 -> V_52 = ( int ) V_54 ;
V_43 -> V_53 = V_72 ;
V_43 ++ ;
V_9 ++ ;
V_5 -> V_10 . V_69 = ( unsigned ) V_54 ;
}
break;
case V_34 :
ASSERT ( ! ( V_5 -> V_10 . V_11 &
( V_17 | V_20 |
V_16 | V_19 ) ) ) ;
if ( V_5 -> V_10 . V_11 & V_18 ) {
V_5 -> V_10 . V_73 . V_74 =
V_7 -> V_22 . V_75 . V_76 ;
}
break;
case V_35 :
ASSERT ( ! ( V_5 -> V_10 . V_11 &
( V_17 | V_20 |
V_16 | V_18 ) ) ) ;
if ( V_5 -> V_10 . V_11 & V_19 ) {
V_5 -> V_10 . V_73 . V_77 =
V_7 -> V_22 . V_75 . V_78 ;
}
break;
default:
ASSERT ( 0 ) ;
break;
}
if ( ! F_5 ( V_7 ) ) {
V_5 -> V_10 . V_79 = V_9 ;
ASSERT ( ! ( V_5 -> V_10 . V_11 &
( V_36 | V_37 | V_38 ) ) ) ;
return;
}
switch ( V_7 -> V_13 . V_39 ) {
case V_15 :
ASSERT ( ! ( V_5 -> V_10 . V_11 &
( V_36 | V_37 ) ) ) ;
if ( V_5 -> V_10 . V_11 & V_38 ) {
#ifdef F_16
int V_80 = V_7 -> V_41 -> V_23 /
( T_1 ) sizeof( T_2 ) ;
ASSERT ( V_80 > 0 ) ;
ASSERT ( V_80 == V_7 -> V_13 . V_40 ) ;
ASSERT ( V_7 -> V_41 -> V_23 > 0 ) ;
ASSERT ( V_7 -> V_41 -> V_24 . V_25 != NULL ) ;
ASSERT ( V_7 -> V_13 . V_40 > 0 ) ;
#endif
#ifdef F_14
V_43 -> V_51 = V_7 -> V_41 -> V_24 . V_25 ;
V_43 -> V_52 = V_7 -> V_41 -> V_23 ;
V_43 -> V_53 = V_81 ;
#else
ASSERT ( V_5 -> V_50 == NULL ) ;
F_6 ( V_7 , V_43 ,
V_82 , V_81 ) ;
#endif
V_5 -> V_10 . V_83 = V_43 -> V_52 ;
V_43 ++ ;
V_9 ++ ;
}
break;
case V_26 :
ASSERT ( ! ( V_5 -> V_10 . V_11 &
( V_36 | V_38 ) ) ) ;
if ( V_5 -> V_10 . V_11 & V_37 ) {
ASSERT ( V_7 -> V_41 -> V_27 > 0 ) ;
ASSERT ( V_7 -> V_41 -> V_28 != NULL ) ;
V_43 -> V_51 = V_7 -> V_41 -> V_28 ;
V_43 -> V_52 = V_7 -> V_41 -> V_27 ;
V_43 -> V_53 = V_84 ;
V_43 ++ ;
V_9 ++ ;
V_5 -> V_10 . V_83 = V_7 -> V_41 -> V_27 ;
}
break;
case V_31 :
ASSERT ( ! ( V_5 -> V_10 . V_11 &
( V_37 | V_38 ) ) ) ;
if ( V_5 -> V_10 . V_11 & V_36 ) {
ASSERT ( V_7 -> V_41 -> V_23 > 0 ) ;
ASSERT ( V_7 -> V_41 -> V_24 . V_32 != NULL ) ;
V_43 -> V_51 = V_7 -> V_41 -> V_24 . V_32 ;
V_54 = F_15 ( V_7 -> V_41 -> V_23 , 4 ) ;
ASSERT ( ( V_7 -> V_41 -> V_71 == 0 ) ||
( V_7 -> V_41 -> V_71 == V_54 ) ) ;
V_43 -> V_52 = ( int ) V_54 ;
V_43 -> V_53 = V_85 ;
V_43 ++ ;
V_9 ++ ;
V_5 -> V_10 . V_83 = ( unsigned ) V_54 ;
}
break;
default:
ASSERT ( 0 ) ;
break;
}
V_5 -> V_10 . V_79 = V_9 ;
}
STATIC void
F_17 (
struct V_2 * V_3 )
{
struct V_6 * V_7 = F_1 ( V_3 ) -> V_8 ;
ASSERT ( F_18 ( V_7 , V_86 ) ) ;
F_19 ( V_7 , V_87 ) ;
F_20 ( & V_7 -> V_88 ) ;
}
STATIC void
F_21 (
struct V_2 * V_3 ,
int remove )
{
struct V_6 * V_7 = F_1 ( V_3 ) -> V_8 ;
F_22 ( V_7 , V_87 ) ;
ASSERT ( F_23 ( & V_7 -> V_88 ) > 0 ) ;
if ( F_24 ( & V_7 -> V_88 ) )
F_25 ( & V_7 -> V_89 , V_90 ) ;
}
STATIC T_1
F_26 (
struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
if ( F_27 ( V_7 ) > 0 )
return V_91 ;
if ( ! F_28 ( V_7 , V_92 ) )
return V_93 ;
if ( ! F_29 ( V_7 ) ) {
return V_94 ;
}
if ( V_7 -> V_89 & V_95 ) {
F_30 ( V_7 ) ;
F_31 ( V_7 , V_92 | V_96 ) ;
return V_91 ;
}
#ifdef F_16
if ( ! F_32 ( V_7 -> V_61 ) ) {
ASSERT ( V_5 -> V_10 . V_11 != 0 ) ;
ASSERT ( V_5 -> V_97 == 0 ) ;
ASSERT ( V_3 -> V_98 & V_99 ) ;
}
#endif
return V_100 ;
}
STATIC void
F_33 (
struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
unsigned short V_101 ;
ASSERT ( V_7 -> V_48 != NULL ) ;
ASSERT ( F_18 ( V_7 , V_86 ) ) ;
if ( V_5 -> V_49 != NULL ) {
ASSERT ( V_7 -> V_13 . V_14 == V_15 ) ;
ASSERT ( V_7 -> V_13 . V_21 > 0 ) ;
ASSERT ( V_5 -> V_10 . V_11 & V_20 ) ;
ASSERT ( V_7 -> V_22 . V_23 > 0 ) ;
F_34 ( V_5 -> V_49 ) ;
V_5 -> V_49 = NULL ;
}
if ( V_5 -> V_50 != NULL ) {
ASSERT ( V_7 -> V_13 . V_39 == V_15 ) ;
ASSERT ( V_7 -> V_13 . V_40 > 0 ) ;
ASSERT ( V_5 -> V_10 . V_11 & V_38 ) ;
ASSERT ( V_7 -> V_41 -> V_23 > 0 ) ;
F_34 ( V_5 -> V_50 ) ;
V_5 -> V_50 = NULL ;
}
V_101 = V_5 -> V_102 ;
V_5 -> V_102 = 0 ;
if ( V_101 )
F_31 ( V_7 , V_101 ) ;
}
STATIC T_5
F_35 (
struct V_2 * V_3 ,
T_5 V_103 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
if ( F_36 ( V_7 , V_95 ) ) {
F_21 ( V_3 , 0 ) ;
return - 1 ;
}
return V_103 ;
}
STATIC bool
F_37 (
struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_104 * V_105 ;
bool V_106 = true ;
ASSERT ( F_18 ( V_7 , V_92 ) ) ;
if ( ! F_38 ( V_7 ) ||
! ( V_3 -> V_98 & V_99 ) ) {
F_31 ( V_7 , V_92 ) ;
return true ;
}
V_105 = F_39 ( V_7 -> V_61 -> V_107 , V_5 -> V_10 . V_108 ,
V_5 -> V_10 . V_109 , V_110 ) ;
F_31 ( V_7 , V_92 ) ;
if ( ! V_105 )
return true ;
if ( F_40 ( V_105 ) )
F_41 ( V_105 ) ;
if ( F_42 ( V_105 ) )
V_106 = false ;
F_43 ( V_105 ) ;
return V_106 ;
}
STATIC void
F_44 (
struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
ASSERT ( F_18 ( V_7 , V_92 ) ) ;
ASSERT ( F_38 ( V_7 ) ) ;
ASSERT ( F_32 ( V_7 -> V_61 ) ||
V_5 -> V_10 . V_11 != 0 ) ;
( void ) F_45 ( V_7 , V_111 ) ;
F_31 ( V_7 , V_92 ) ;
}
STATIC void
F_46 (
struct V_2 * V_3 ,
T_5 V_103 )
{
F_1 ( V_3 ) -> V_112 = V_103 ;
}
void
F_47 (
struct V_6 * V_7 ,
struct V_113 * V_55 )
{
struct V_1 * V_5 ;
ASSERT ( V_7 -> V_48 == NULL ) ;
V_5 = V_7 -> V_48 = F_48 ( V_114 , V_46 ) ;
V_5 -> V_8 = V_7 ;
F_49 ( V_55 , & V_5 -> V_4 , V_115 ,
& V_116 ) ;
V_5 -> V_10 . V_117 = V_115 ;
V_5 -> V_10 . V_118 = V_7 -> V_119 ;
V_5 -> V_10 . V_108 = V_7 -> V_120 . V_121 ;
V_5 -> V_10 . V_109 = V_7 -> V_120 . V_122 ;
V_5 -> V_10 . V_123 = V_7 -> V_120 . V_124 ;
}
void
F_50 (
T_6 * V_7 )
{
#ifdef F_4
if ( V_7 -> V_48 -> V_29 != 0 ) {
F_34 ( V_7 -> V_48 -> V_30 ) ;
}
#endif
F_51 ( V_114 , V_7 -> V_48 ) ;
}
void
F_52 (
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
if ( V_3 -> V_133 != F_52 ) {
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
F_53 ( & V_129 -> V_139 ) ;
for ( V_125 = V_3 ; V_125 ; V_125 = V_125 -> V_134 ) {
V_5 = F_1 ( V_125 ) ;
if ( V_5 -> V_97 &&
V_125 -> V_135 == V_5 -> V_136 ) {
V_137 [ V_138 ++ ] = V_125 ;
}
ASSERT ( V_138 <= V_131 ) ;
}
F_54 ( V_129 , V_137 , V_138 ) ;
}
for ( V_125 = V_3 ; V_125 ; V_125 = V_126 ) {
V_126 = V_125 -> V_134 ;
V_125 -> V_134 = NULL ;
V_5 = F_1 ( V_125 ) ;
V_5 -> V_97 = 0 ;
V_5 -> V_140 = 0 ;
F_30 ( V_5 -> V_8 ) ;
}
}
void
F_55 (
T_6 * V_7 )
{
T_7 * V_5 = V_7 -> V_48 ;
if ( V_5 ) {
struct V_128 * V_129 = V_5 -> V_4 . V_130 ;
if ( V_5 -> V_4 . V_98 & V_99 ) {
F_53 ( & V_129 -> V_139 ) ;
if ( V_5 -> V_4 . V_98 & V_99 ) {
F_56 ( V_129 , ( V_141 * ) V_5 ) ;
} else
F_57 ( & V_129 -> V_139 ) ;
}
V_5 -> V_97 = 0 ;
V_5 -> V_140 = 0 ;
V_5 -> V_10 . V_11 = 0 ;
}
F_30 ( V_7 ) ;
}
void
F_58 (
struct V_104 * V_105 ,
struct V_2 * V_3 )
{
F_55 ( F_1 ( V_3 ) -> V_8 ) ;
}
int
F_59 (
T_8 * V_142 ,
V_56 * V_143 )
{
if ( V_142 -> V_52 == sizeof( V_144 ) ) {
V_144 * V_145 = V_142 -> V_51 ;
V_143 -> V_117 = V_145 -> V_117 ;
V_143 -> V_79 = V_145 -> V_79 ;
V_143 -> V_11 = V_145 -> V_11 ;
V_143 -> V_83 = V_145 -> V_83 ;
V_143 -> V_69 = V_145 -> V_69 ;
V_143 -> V_118 = V_145 -> V_118 ;
memcpy ( V_143 -> V_73 . V_77 . V_146 ,
V_145 -> V_73 . V_77 . V_146 ,
sizeof( V_147 ) ) ;
V_143 -> V_108 = V_145 -> V_108 ;
V_143 -> V_109 = V_145 -> V_109 ;
V_143 -> V_123 = V_145 -> V_123 ;
return 0 ;
} else if ( V_142 -> V_52 == sizeof( V_148 ) ) {
V_148 * V_149 = V_142 -> V_51 ;
V_143 -> V_117 = V_149 -> V_117 ;
V_143 -> V_79 = V_149 -> V_79 ;
V_143 -> V_11 = V_149 -> V_11 ;
V_143 -> V_83 = V_149 -> V_83 ;
V_143 -> V_69 = V_149 -> V_69 ;
V_143 -> V_118 = V_149 -> V_118 ;
memcpy ( V_143 -> V_73 . V_77 . V_146 ,
V_149 -> V_73 . V_77 . V_146 ,
sizeof( V_147 ) ) ;
V_143 -> V_108 = V_149 -> V_108 ;
V_143 -> V_109 = V_149 -> V_109 ;
V_143 -> V_123 = V_149 -> V_123 ;
return 0 ;
}
return V_150 ;
}
