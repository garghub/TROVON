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
ASSERT ( V_7 -> V_22 . V_27 ==
F_4 ( V_7 ) / ( T_1 ) sizeof( V_28 ) ) ;
V_5 -> V_10 . V_11 &=
~ ( V_16 | V_20 |
V_18 | V_19 ) ;
if ( ( V_5 -> V_10 . V_11 & V_17 ) &&
( V_7 -> V_22 . V_29 > 0 ) ) {
ASSERT ( V_7 -> V_22 . V_30 != NULL ) ;
V_9 ++ ;
} else {
ASSERT ( ! ( V_5 -> V_10 . V_11 &
V_17 ) ) ;
#ifdef F_5
if ( V_5 -> V_31 > 0 ) {
ASSERT ( V_5 -> V_31 ==
V_7 -> V_22 . V_29 ) ;
ASSERT ( memcmp ( V_5 -> V_32 ,
V_7 -> V_22 . V_30 ,
V_5 -> V_31 ) == 0 ) ;
} else {
ASSERT ( V_7 -> V_22 . V_29 == 0 ) ;
}
#endif
V_5 -> V_10 . V_11 &= ~ V_17 ;
}
break;
case V_33 :
V_5 -> V_10 . V_11 &=
~ ( V_20 | V_17 |
V_18 | V_19 ) ;
if ( ( V_5 -> V_10 . V_11 & V_16 ) &&
( V_7 -> V_22 . V_23 > 0 ) ) {
ASSERT ( V_7 -> V_22 . V_24 . V_34 != NULL ) ;
ASSERT ( V_7 -> V_13 . V_35 > 0 ) ;
V_9 ++ ;
} else {
V_5 -> V_10 . V_11 &= ~ V_16 ;
}
break;
case V_36 :
V_5 -> V_10 . V_11 &=
~ ( V_16 | V_17 |
V_20 | V_19 ) ;
break;
case V_37 :
V_5 -> V_10 . V_11 &=
~ ( V_16 | V_17 |
V_20 | V_18 ) ;
break;
default:
ASSERT ( 0 ) ;
break;
}
if ( ! F_6 ( V_7 ) ) {
V_5 -> V_10 . V_11 &=
~ ( V_38 | V_39 | V_40 ) ;
return V_9 ;
}
switch ( V_7 -> V_13 . V_41 ) {
case V_15 :
V_5 -> V_10 . V_11 &=
~ ( V_38 | V_39 ) ;
if ( ( V_5 -> V_10 . V_11 & V_40 ) &&
( V_7 -> V_13 . V_42 > 0 ) &&
( V_7 -> V_43 -> V_23 > 0 ) ) {
ASSERT ( V_7 -> V_43 -> V_24 . V_25 != NULL ) ;
V_9 ++ ;
} else {
V_5 -> V_10 . V_11 &= ~ V_40 ;
}
break;
case V_26 :
V_5 -> V_10 . V_11 &=
~ ( V_38 | V_40 ) ;
if ( ( V_5 -> V_10 . V_11 & V_39 ) &&
( V_7 -> V_43 -> V_29 > 0 ) ) {
ASSERT ( V_7 -> V_43 -> V_30 != NULL ) ;
V_9 ++ ;
} else {
V_5 -> V_10 . V_11 &= ~ V_39 ;
}
break;
case V_33 :
V_5 -> V_10 . V_11 &=
~ ( V_40 | V_39 ) ;
if ( ( V_5 -> V_10 . V_11 & V_38 ) &&
( V_7 -> V_43 -> V_23 > 0 ) ) {
ASSERT ( V_7 -> V_43 -> V_24 . V_34 != NULL ) ;
V_9 ++ ;
} else {
V_5 -> V_10 . V_11 &= ~ V_38 ;
}
break;
default:
ASSERT ( 0 ) ;
break;
}
return V_9 ;
}
STATIC void
F_7 (
struct V_6 * V_7 ,
struct V_44 * V_45 ,
int V_46 ,
int type )
{
V_28 * V_47 ;
V_47 = F_8 ( F_9 ( V_7 , V_46 ) , V_48 ) ;
if ( V_46 == V_49 )
V_7 -> V_50 -> V_51 = V_47 ;
else
V_7 -> V_50 -> V_52 = V_47 ;
V_45 -> V_53 = V_47 ;
V_45 -> V_54 = F_10 ( V_7 , V_47 , V_46 ) ;
V_45 -> V_55 = type ;
}
STATIC void
F_11 (
struct V_2 * V_3 ,
struct V_44 * V_45 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
T_1 V_9 ;
T_2 V_56 ;
T_3 * V_57 ;
V_45 -> V_53 = & V_5 -> V_10 ;
V_45 -> V_54 = sizeof( V_58 ) ;
V_45 -> V_55 = V_59 ;
V_45 ++ ;
V_9 = 1 ;
if ( V_7 -> V_60 ) {
V_7 -> V_60 = 0 ;
F_12 () ;
}
F_13 ( V_7 ) ;
V_45 -> V_53 = & V_7 -> V_13 ;
V_45 -> V_54 = sizeof( struct V_61 ) ;
V_45 -> V_55 = V_62 ;
V_45 ++ ;
V_9 ++ ;
V_5 -> V_10 . V_11 |= V_12 ;
V_57 = V_7 -> V_63 ;
ASSERT ( V_7 -> V_13 . V_64 == 1 || F_14 ( & V_57 -> V_65 ) ) ;
if ( V_7 -> V_13 . V_64 == 1 ) {
if ( ! F_14 ( & V_57 -> V_65 ) ) {
ASSERT ( V_7 -> V_13 . V_66 <= V_67 ) ;
V_7 -> V_13 . V_68 = V_7 -> V_13 . V_66 ;
} else {
V_7 -> V_13 . V_64 = 2 ;
V_7 -> V_13 . V_68 = 0 ;
memset ( & ( V_7 -> V_13 . V_69 [ 0 ] ) , 0 , sizeof( V_7 -> V_13 . V_69 ) ) ;
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
ASSERT ( V_5 -> V_51 == NULL ) ;
ASSERT ( ( V_7 -> V_22 . V_23 /
( T_1 ) sizeof( V_28 ) ) > 0 ) ;
#ifdef F_15
if ( V_7 -> V_13 . V_21 == V_7 -> V_22 . V_23 /
( T_1 ) sizeof( V_28 ) ) {
V_45 -> V_53 = V_7 -> V_22 . V_24 . V_25 ;
V_45 -> V_54 = V_7 -> V_22 . V_23 ;
V_45 -> V_55 = V_70 ;
} else
#endif
{
F_7 ( V_7 , V_45 ,
V_49 , V_70 ) ;
}
ASSERT ( V_45 -> V_54 <= V_7 -> V_22 . V_23 ) ;
V_5 -> V_10 . V_71 = V_45 -> V_54 ;
V_45 ++ ;
V_9 ++ ;
}
break;
case V_26 :
ASSERT ( ! ( V_5 -> V_10 . V_11 &
( V_16 | V_20 |
V_18 | V_19 ) ) ) ;
if ( V_5 -> V_10 . V_11 & V_17 ) {
ASSERT ( V_7 -> V_22 . V_29 > 0 ) ;
ASSERT ( V_7 -> V_22 . V_30 != NULL ) ;
V_45 -> V_53 = V_7 -> V_22 . V_30 ;
V_45 -> V_54 = V_7 -> V_22 . V_29 ;
V_45 -> V_55 = V_72 ;
V_45 ++ ;
V_9 ++ ;
V_5 -> V_10 . V_71 = V_7 -> V_22 . V_29 ;
}
break;
case V_33 :
ASSERT ( ! ( V_5 -> V_10 . V_11 &
( V_17 | V_20 |
V_18 | V_19 ) ) ) ;
if ( V_5 -> V_10 . V_11 & V_16 ) {
ASSERT ( V_7 -> V_22 . V_23 > 0 ) ;
ASSERT ( V_7 -> V_22 . V_24 . V_34 != NULL ) ;
ASSERT ( V_7 -> V_13 . V_35 > 0 ) ;
V_45 -> V_53 = V_7 -> V_22 . V_24 . V_34 ;
V_56 = F_16 ( V_7 -> V_22 . V_23 , 4 ) ;
ASSERT ( ( V_7 -> V_22 . V_73 == 0 ) ||
( V_7 -> V_22 . V_73 == V_56 ) ) ;
V_45 -> V_54 = ( int ) V_56 ;
V_45 -> V_55 = V_74 ;
V_45 ++ ;
V_9 ++ ;
V_5 -> V_10 . V_71 = ( unsigned ) V_56 ;
}
break;
case V_36 :
ASSERT ( ! ( V_5 -> V_10 . V_11 &
( V_17 | V_20 |
V_16 | V_19 ) ) ) ;
if ( V_5 -> V_10 . V_11 & V_18 ) {
V_5 -> V_10 . V_75 . V_76 =
V_7 -> V_22 . V_77 . V_78 ;
}
break;
case V_37 :
ASSERT ( ! ( V_5 -> V_10 . V_11 &
( V_17 | V_20 |
V_16 | V_18 ) ) ) ;
if ( V_5 -> V_10 . V_11 & V_19 ) {
V_5 -> V_10 . V_75 . V_79 =
V_7 -> V_22 . V_77 . V_80 ;
}
break;
default:
ASSERT ( 0 ) ;
break;
}
if ( ! F_6 ( V_7 ) ) {
ASSERT ( V_9 == V_3 -> V_81 -> V_82 ) ;
V_5 -> V_10 . V_83 = V_9 ;
ASSERT ( ! ( V_5 -> V_10 . V_11 &
( V_38 | V_39 | V_40 ) ) ) ;
return;
}
switch ( V_7 -> V_13 . V_41 ) {
case V_15 :
ASSERT ( ! ( V_5 -> V_10 . V_11 &
( V_38 | V_39 ) ) ) ;
if ( V_5 -> V_10 . V_11 & V_40 ) {
#ifdef F_17
int V_84 = V_7 -> V_43 -> V_23 /
( T_1 ) sizeof( V_28 ) ;
ASSERT ( V_84 > 0 ) ;
ASSERT ( V_84 == V_7 -> V_13 . V_42 ) ;
ASSERT ( V_7 -> V_43 -> V_23 > 0 ) ;
ASSERT ( V_7 -> V_43 -> V_24 . V_25 != NULL ) ;
ASSERT ( V_7 -> V_13 . V_42 > 0 ) ;
#endif
#ifdef F_15
V_45 -> V_53 = V_7 -> V_43 -> V_24 . V_25 ;
V_45 -> V_54 = V_7 -> V_43 -> V_23 ;
V_45 -> V_55 = V_85 ;
#else
ASSERT ( V_5 -> V_52 == NULL ) ;
F_7 ( V_7 , V_45 ,
V_86 , V_85 ) ;
#endif
V_5 -> V_10 . V_87 = V_45 -> V_54 ;
V_45 ++ ;
V_9 ++ ;
}
break;
case V_26 :
ASSERT ( ! ( V_5 -> V_10 . V_11 &
( V_38 | V_40 ) ) ) ;
if ( V_5 -> V_10 . V_11 & V_39 ) {
ASSERT ( V_7 -> V_43 -> V_29 > 0 ) ;
ASSERT ( V_7 -> V_43 -> V_30 != NULL ) ;
V_45 -> V_53 = V_7 -> V_43 -> V_30 ;
V_45 -> V_54 = V_7 -> V_43 -> V_29 ;
V_45 -> V_55 = V_88 ;
V_45 ++ ;
V_9 ++ ;
V_5 -> V_10 . V_87 = V_7 -> V_43 -> V_29 ;
}
break;
case V_33 :
ASSERT ( ! ( V_5 -> V_10 . V_11 &
( V_39 | V_40 ) ) ) ;
if ( V_5 -> V_10 . V_11 & V_38 ) {
ASSERT ( V_7 -> V_43 -> V_23 > 0 ) ;
ASSERT ( V_7 -> V_43 -> V_24 . V_34 != NULL ) ;
V_45 -> V_53 = V_7 -> V_43 -> V_24 . V_34 ;
V_56 = F_16 ( V_7 -> V_43 -> V_23 , 4 ) ;
ASSERT ( ( V_7 -> V_43 -> V_73 == 0 ) ||
( V_7 -> V_43 -> V_73 == V_56 ) ) ;
V_45 -> V_54 = ( int ) V_56 ;
V_45 -> V_55 = V_89 ;
V_45 ++ ;
V_9 ++ ;
V_5 -> V_10 . V_87 = ( unsigned ) V_56 ;
}
break;
default:
ASSERT ( 0 ) ;
break;
}
ASSERT ( V_9 == V_3 -> V_81 -> V_82 ) ;
V_5 -> V_10 . V_83 = V_9 ;
}
STATIC void
F_18 (
struct V_2 * V_3 )
{
struct V_6 * V_7 = F_1 ( V_3 ) -> V_8 ;
ASSERT ( F_19 ( V_7 , V_90 ) ) ;
F_20 ( V_7 , V_91 ) ;
F_21 ( & V_7 -> V_92 ) ;
}
STATIC void
F_22 (
struct V_2 * V_3 ,
int remove )
{
struct V_6 * V_7 = F_1 ( V_3 ) -> V_8 ;
F_23 ( V_7 , V_91 ) ;
ASSERT ( F_24 ( & V_7 -> V_92 ) > 0 ) ;
if ( F_25 ( & V_7 -> V_92 ) )
F_26 ( & V_7 -> V_93 ) ;
}
STATIC T_1
F_27 (
struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
if ( F_28 ( V_7 ) > 0 )
return V_94 ;
if ( ! F_29 ( V_7 , V_95 ) )
return V_96 ;
if ( ! F_30 ( V_7 ) ) {
return V_97 ;
}
if ( V_7 -> V_98 & V_99 ) {
F_31 ( V_7 ) ;
F_32 ( V_7 , V_95 | V_100 ) ;
return V_94 ;
}
#ifdef F_17
if ( ! F_33 ( V_7 -> V_63 ) ) {
ASSERT ( V_5 -> V_10 . V_11 != 0 ) ;
ASSERT ( V_5 -> V_101 == 0 ) ;
ASSERT ( V_3 -> V_102 & V_103 ) ;
}
#endif
return V_104 ;
}
STATIC void
F_34 (
struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
unsigned short V_105 ;
ASSERT ( V_5 -> V_8 -> V_50 != NULL ) ;
ASSERT ( F_19 ( V_5 -> V_8 , V_90 ) ) ;
V_7 -> V_106 = NULL ;
if ( V_5 -> V_51 != NULL ) {
ASSERT ( V_7 -> V_13 . V_14 == V_15 ) ;
ASSERT ( V_7 -> V_13 . V_21 > 0 ) ;
ASSERT ( V_5 -> V_10 . V_11 & V_20 ) ;
ASSERT ( V_7 -> V_22 . V_23 > 0 ) ;
F_35 ( V_5 -> V_51 ) ;
V_5 -> V_51 = NULL ;
}
if ( V_5 -> V_52 != NULL ) {
ASSERT ( V_7 -> V_13 . V_41 == V_15 ) ;
ASSERT ( V_7 -> V_13 . V_42 > 0 ) ;
ASSERT ( V_5 -> V_10 . V_11 & V_40 ) ;
ASSERT ( V_7 -> V_43 -> V_23 > 0 ) ;
F_35 ( V_5 -> V_52 ) ;
V_5 -> V_52 = NULL ;
}
V_105 = V_5 -> V_107 ;
V_5 -> V_107 = 0 ;
if ( V_105 ) {
F_32 ( V_5 -> V_8 , V_105 ) ;
F_36 ( V_5 -> V_8 ) ;
}
}
STATIC T_4
F_37 (
struct V_2 * V_3 ,
T_4 V_108 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
if ( F_38 ( V_7 , V_99 ) ) {
F_22 ( V_3 , 0 ) ;
return - 1 ;
}
return V_108 ;
}
STATIC void
F_39 (
struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_109 * V_110 ;
ASSERT ( F_19 ( V_7 , V_95 ) ) ;
if ( F_40 ( & V_7 -> V_111 ) ||
! ( V_3 -> V_102 & V_103 ) ) {
F_32 ( V_7 , V_95 ) ;
return;
}
V_110 = F_41 ( V_7 -> V_63 -> V_112 , V_5 -> V_10 . V_113 ,
V_5 -> V_10 . V_114 , V_115 ) ;
F_32 ( V_7 , V_95 ) ;
if ( ! V_110 )
return;
if ( F_42 ( V_110 ) )
F_43 ( V_110 ) ;
F_44 ( V_110 ) ;
}
STATIC void
F_45 (
struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
ASSERT ( F_19 ( V_7 , V_95 ) ) ;
ASSERT ( ! F_40 ( & V_7 -> V_111 ) ) ;
ASSERT ( F_33 ( V_7 -> V_63 ) ||
V_5 -> V_10 . V_11 != 0 ) ;
( void ) F_46 ( V_7 , V_116 ) ;
F_32 ( V_7 , V_95 ) ;
}
STATIC void
F_47 (
struct V_2 * V_3 ,
T_4 V_108 )
{
F_1 ( V_3 ) -> V_117 = V_108 ;
}
void
F_48 (
struct V_6 * V_7 ,
struct V_118 * V_57 )
{
struct V_1 * V_5 ;
ASSERT ( V_7 -> V_50 == NULL ) ;
V_5 = V_7 -> V_50 = F_49 ( V_119 , V_48 ) ;
V_5 -> V_8 = V_7 ;
F_50 ( V_57 , & V_5 -> V_4 , V_120 ,
& V_121 ) ;
V_5 -> V_10 . V_122 = V_120 ;
V_5 -> V_10 . V_123 = V_7 -> V_124 ;
V_5 -> V_10 . V_113 = V_7 -> V_125 . V_126 ;
V_5 -> V_10 . V_114 = V_7 -> V_125 . V_127 ;
V_5 -> V_10 . V_128 = V_7 -> V_125 . V_129 ;
}
void
F_51 (
T_5 * V_7 )
{
#ifdef F_5
if ( V_7 -> V_50 -> V_31 != 0 ) {
F_35 ( V_7 -> V_50 -> V_32 ) ;
}
#endif
F_52 ( V_119 , V_7 -> V_50 ) ;
}
void
F_53 (
struct V_109 * V_110 ,
struct V_2 * V_3 )
{
struct V_1 * V_5 ;
struct V_2 * V_130 ;
struct V_2 * V_131 ;
struct V_2 * V_132 ;
struct V_133 * V_134 = V_3 -> V_135 ;
int V_136 = 0 ;
V_130 = F_54 ( V_110 , V_137 * ) ;
V_132 = NULL ;
while ( V_130 != NULL ) {
if ( V_3 -> V_138 != F_53 ) {
V_132 = V_130 ;
V_130 = V_130 -> V_139 ;
continue;
}
V_131 = V_130 -> V_139 ;
if ( ! V_132 ) {
F_55 ( V_110 , V_131 ) ;
} else {
V_132 -> V_139 = V_131 ;
}
V_130 -> V_139 = V_3 -> V_139 ;
V_3 -> V_139 = V_130 ;
V_5 = F_1 ( V_130 ) ;
if ( V_5 -> V_101 && V_130 -> V_140 == V_5 -> V_141 )
V_136 ++ ;
V_130 = V_131 ;
}
V_5 = F_1 ( V_3 ) ;
if ( V_5 -> V_101 && V_3 -> V_140 == V_5 -> V_141 )
V_136 ++ ;
if ( V_136 ) {
struct V_2 * V_142 [ V_136 ] ;
int V_143 = 0 ;
F_56 ( & V_134 -> V_144 ) ;
for ( V_130 = V_3 ; V_130 ; V_130 = V_130 -> V_139 ) {
V_5 = F_1 ( V_130 ) ;
if ( V_5 -> V_101 &&
V_130 -> V_140 == V_5 -> V_141 ) {
V_142 [ V_143 ++ ] = V_130 ;
}
ASSERT ( V_143 <= V_136 ) ;
}
F_57 ( V_134 , V_142 , V_143 ) ;
}
for ( V_130 = V_3 ; V_130 ; V_130 = V_131 ) {
V_131 = V_130 -> V_139 ;
V_130 -> V_139 = NULL ;
V_5 = F_1 ( V_130 ) ;
V_5 -> V_101 = 0 ;
V_5 -> V_145 = 0 ;
F_31 ( V_5 -> V_8 ) ;
}
}
void
F_58 (
T_5 * V_7 )
{
T_6 * V_5 = V_7 -> V_50 ;
if ( V_5 ) {
struct V_133 * V_134 = V_5 -> V_4 . V_135 ;
if ( V_5 -> V_4 . V_102 & V_103 ) {
F_56 ( & V_134 -> V_144 ) ;
if ( V_5 -> V_4 . V_102 & V_103 ) {
F_59 ( V_134 , ( V_137 * ) V_5 ) ;
} else
F_60 ( & V_134 -> V_144 ) ;
}
V_5 -> V_101 = 0 ;
V_5 -> V_145 = 0 ;
V_5 -> V_10 . V_11 = 0 ;
}
F_31 ( V_7 ) ;
}
void
F_61 (
struct V_109 * V_110 ,
struct V_2 * V_3 )
{
F_58 ( F_1 ( V_3 ) -> V_8 ) ;
}
int
F_62 (
T_7 * V_146 ,
V_58 * V_147 )
{
if ( V_146 -> V_54 == sizeof( V_148 ) ) {
V_148 * V_149 = V_146 -> V_53 ;
V_147 -> V_122 = V_149 -> V_122 ;
V_147 -> V_83 = V_149 -> V_83 ;
V_147 -> V_11 = V_149 -> V_11 ;
V_147 -> V_87 = V_149 -> V_87 ;
V_147 -> V_71 = V_149 -> V_71 ;
V_147 -> V_123 = V_149 -> V_123 ;
memcpy ( V_147 -> V_75 . V_79 . V_150 ,
V_149 -> V_75 . V_79 . V_150 ,
sizeof( V_151 ) ) ;
V_147 -> V_113 = V_149 -> V_113 ;
V_147 -> V_114 = V_149 -> V_114 ;
V_147 -> V_128 = V_149 -> V_128 ;
return 0 ;
} else if ( V_146 -> V_54 == sizeof( V_152 ) ) {
V_152 * V_153 = V_146 -> V_53 ;
V_147 -> V_122 = V_153 -> V_122 ;
V_147 -> V_83 = V_153 -> V_83 ;
V_147 -> V_11 = V_153 -> V_11 ;
V_147 -> V_87 = V_153 -> V_87 ;
V_147 -> V_71 = V_153 -> V_71 ;
V_147 -> V_123 = V_153 -> V_123 ;
memcpy ( V_147 -> V_75 . V_79 . V_150 ,
V_153 -> V_75 . V_79 . V_150 ,
sizeof( V_151 ) ) ;
V_147 -> V_113 = V_153 -> V_113 ;
V_147 -> V_114 = V_153 -> V_114 ;
V_147 -> V_128 = V_153 -> V_128 ;
return 0 ;
}
return V_154 ;
}
