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
V_32 -> V_41 = F_10 ( V_7 -> V_10 . V_48 ) ;
V_32 -> V_42 = V_49 ;
V_32 ++ ;
V_9 ++ ;
V_44 = V_7 -> V_50 ;
ASSERT ( V_7 -> V_10 . V_48 == 1 || F_11 ( & V_44 -> V_51 ) ) ;
if ( V_7 -> V_10 . V_48 == 1 ) {
if ( ! F_11 ( & V_44 -> V_51 ) ) {
ASSERT ( V_7 -> V_10 . V_52 <= V_53 ) ;
V_7 -> V_10 . V_54 = V_7 -> V_10 . V_52 ;
} else {
V_7 -> V_10 . V_48 = 2 ;
V_7 -> V_10 . V_54 = 0 ;
memset ( & ( V_7 -> V_10 . V_55 [ 0 ] ) , 0 , sizeof( V_7 -> V_10 . V_55 ) ) ;
}
}
switch ( V_7 -> V_10 . V_11 ) {
case V_12 :
V_5 -> V_13 &=
~ ( V_22 | V_19 |
V_56 | V_57 ) ;
if ( ( V_5 -> V_13 & V_14 ) &&
V_7 -> V_10 . V_15 > 0 &&
V_7 -> V_16 . V_17 > 0 ) {
ASSERT ( V_7 -> V_16 . V_58 . V_59 != NULL ) ;
ASSERT ( V_7 -> V_16 . V_17 / sizeof( T_2 ) > 0 ) ;
ASSERT ( V_5 -> V_38 == NULL ) ;
#ifdef F_12
if ( V_7 -> V_10 . V_15 == V_7 -> V_16 . V_17 /
( T_1 ) sizeof( T_2 ) ) {
V_32 -> V_40 = V_7 -> V_16 . V_58 . V_59 ;
V_32 -> V_41 = V_7 -> V_16 . V_17 ;
V_32 -> V_42 = V_60 ;
} else
#endif
{
F_5 ( V_7 , V_32 ,
V_36 , V_60 ) ;
}
ASSERT ( V_32 -> V_41 <= V_7 -> V_16 . V_17 ) ;
V_5 -> V_45 . V_61 = V_32 -> V_41 ;
V_32 ++ ;
V_9 ++ ;
} else {
V_5 -> V_13 &= ~ V_14 ;
}
break;
case V_18 :
V_5 -> V_13 &=
~ ( V_22 | V_14 |
V_56 | V_57 ) ;
if ( ( V_5 -> V_13 & V_19 ) &&
V_7 -> V_16 . V_20 > 0 ) {
ASSERT ( V_7 -> V_16 . V_62 != NULL ) ;
V_32 -> V_40 = V_7 -> V_16 . V_62 ;
V_32 -> V_41 = V_7 -> V_16 . V_20 ;
V_32 -> V_42 = V_63 ;
V_32 ++ ;
V_9 ++ ;
V_5 -> V_45 . V_61 = V_7 -> V_16 . V_20 ;
} else {
ASSERT ( ! ( V_5 -> V_13 &
V_19 ) ) ;
V_5 -> V_13 &= ~ V_19 ;
}
break;
case V_21 :
V_5 -> V_13 &=
~ ( V_14 | V_19 |
V_56 | V_57 ) ;
if ( ( V_5 -> V_13 & V_22 ) &&
V_7 -> V_16 . V_17 > 0 ) {
ASSERT ( V_7 -> V_16 . V_58 . V_64 != NULL ) ;
ASSERT ( V_7 -> V_10 . V_65 > 0 ) ;
V_32 -> V_40 = V_7 -> V_16 . V_58 . V_64 ;
V_43 = F_13 ( V_7 -> V_16 . V_17 , 4 ) ;
ASSERT ( ( V_7 -> V_16 . V_66 == 0 ) ||
( V_7 -> V_16 . V_66 == V_43 ) ) ;
V_32 -> V_41 = ( int ) V_43 ;
V_32 -> V_42 = V_67 ;
V_32 ++ ;
V_9 ++ ;
V_5 -> V_45 . V_61 = ( unsigned ) V_43 ;
} else {
V_5 -> V_13 &= ~ V_22 ;
}
break;
case V_23 :
V_5 -> V_13 &=
~ ( V_22 | V_19 |
V_14 | V_57 ) ;
if ( V_5 -> V_13 & V_56 ) {
V_5 -> V_45 . V_68 . V_69 =
V_7 -> V_16 . V_70 . V_71 ;
}
break;
case V_24 :
V_5 -> V_13 &=
~ ( V_22 | V_19 |
V_14 | V_56 ) ;
if ( V_5 -> V_13 & V_57 ) {
V_5 -> V_45 . V_68 . V_72 =
V_7 -> V_16 . V_70 . V_73 ;
}
break;
default:
ASSERT ( 0 ) ;
break;
}
if ( ! F_4 ( V_7 ) ) {
V_5 -> V_13 &=
~ ( V_30 | V_29 | V_26 ) ;
goto V_74;
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
ASSERT ( V_7 -> V_28 -> V_58 . V_59 != NULL ) ;
#ifdef F_12
V_32 -> V_40 = V_7 -> V_28 -> V_58 . V_59 ;
V_32 -> V_41 = V_7 -> V_28 -> V_17 ;
V_32 -> V_42 = V_75 ;
#else
ASSERT ( V_5 -> V_39 == NULL ) ;
F_5 ( V_7 , V_32 ,
V_76 , V_75 ) ;
#endif
V_5 -> V_45 . V_77 = V_32 -> V_41 ;
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
ASSERT ( V_7 -> V_28 -> V_62 != NULL ) ;
V_32 -> V_40 = V_7 -> V_28 -> V_62 ;
V_32 -> V_41 = V_7 -> V_28 -> V_20 ;
V_32 -> V_42 = V_78 ;
V_32 ++ ;
V_9 ++ ;
V_5 -> V_45 . V_77 = V_7 -> V_28 -> V_20 ;
} else {
V_5 -> V_13 &= ~ V_29 ;
}
break;
case V_21 :
V_5 -> V_13 &=
~ ( V_26 | V_29 ) ;
if ( ( V_5 -> V_13 & V_30 ) &&
V_7 -> V_28 -> V_17 > 0 ) {
ASSERT ( V_7 -> V_28 -> V_58 . V_64 != NULL ) ;
V_32 -> V_40 = V_7 -> V_28 -> V_58 . V_64 ;
V_43 = F_13 ( V_7 -> V_28 -> V_17 , 4 ) ;
ASSERT ( ( V_7 -> V_28 -> V_66 == 0 ) ||
( V_7 -> V_28 -> V_66 == V_43 ) ) ;
V_32 -> V_41 = ( int ) V_43 ;
V_32 -> V_42 = V_79 ;
V_32 ++ ;
V_9 ++ ;
V_5 -> V_45 . V_77 = ( unsigned ) V_43 ;
} else {
V_5 -> V_13 &= ~ V_30 ;
}
break;
default:
ASSERT ( 0 ) ;
break;
}
V_74:
V_5 -> V_45 . V_80 = V_81 |
( V_5 -> V_13 & ~ V_82 ) ;
V_5 -> V_45 . V_83 = V_9 ;
}
STATIC void
F_14 (
struct V_2 * V_3 )
{
struct V_6 * V_7 = F_1 ( V_3 ) -> V_8 ;
ASSERT ( F_15 ( V_7 , V_84 ) ) ;
F_16 ( V_7 , V_85 ) ;
F_17 ( & V_7 -> V_86 ) ;
}
STATIC void
F_18 (
struct V_2 * V_3 ,
int remove )
{
struct V_6 * V_7 = F_1 ( V_3 ) -> V_8 ;
F_19 ( V_7 , V_85 ) ;
ASSERT ( F_20 ( & V_7 -> V_86 ) > 0 ) ;
if ( F_21 ( & V_7 -> V_86 ) )
F_22 ( & V_7 -> V_87 , V_88 ) ;
}
STATIC T_1
F_23 (
struct V_2 * V_3 ,
struct V_89 * V_90 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_91 * V_92 = NULL ;
T_1 V_93 = V_94 ;
int error ;
if ( F_24 ( V_7 ) > 0 )
return V_95 ;
if ( ! F_25 ( V_7 , V_96 ) )
return V_97 ;
if ( F_24 ( V_7 ) > 0 ) {
V_93 = V_95 ;
goto V_98;
}
if ( V_7 -> V_87 & V_99 ) {
V_93 = V_95 ;
goto V_98;
}
if ( ! F_26 ( V_7 ) ) {
V_93 = V_100 ;
goto V_98;
}
ASSERT ( V_5 -> V_13 != 0 || F_27 ( V_7 -> V_50 ) ) ;
ASSERT ( V_5 -> V_101 == 0 || F_27 ( V_7 -> V_50 ) ) ;
F_28 ( & V_3 -> V_102 -> V_103 ) ;
error = F_29 ( V_7 , & V_92 ) ;
if ( ! error ) {
if ( ! F_30 ( V_92 , V_90 ) )
V_93 = V_100 ;
F_31 ( V_92 ) ;
}
F_32 ( & V_3 -> V_102 -> V_103 ) ;
V_98:
F_33 ( V_7 , V_96 ) ;
return V_93 ;
}
STATIC void
F_34 (
struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
unsigned short V_104 ;
ASSERT ( V_7 -> V_37 != NULL ) ;
ASSERT ( F_15 ( V_7 , V_84 ) ) ;
if ( V_5 -> V_38 != NULL ) {
ASSERT ( V_7 -> V_10 . V_11 == V_12 ) ;
ASSERT ( V_7 -> V_10 . V_15 > 0 ) ;
ASSERT ( V_5 -> V_13 & V_14 ) ;
ASSERT ( V_7 -> V_16 . V_17 > 0 ) ;
F_35 ( V_5 -> V_38 ) ;
V_5 -> V_38 = NULL ;
}
if ( V_5 -> V_39 != NULL ) {
ASSERT ( V_7 -> V_10 . V_25 == V_12 ) ;
ASSERT ( V_7 -> V_10 . V_27 > 0 ) ;
ASSERT ( V_5 -> V_13 & V_26 ) ;
ASSERT ( V_7 -> V_28 -> V_17 > 0 ) ;
F_35 ( V_5 -> V_39 ) ;
V_5 -> V_39 = NULL ;
}
V_104 = V_5 -> V_105 ;
V_5 -> V_105 = 0 ;
if ( V_104 )
F_33 ( V_7 , V_104 ) ;
}
STATIC T_5
F_36 (
struct V_2 * V_3 ,
T_5 V_106 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
if ( F_37 ( V_7 , V_99 ) ) {
F_18 ( V_3 , 0 ) ;
return - 1 ;
}
return V_106 ;
}
STATIC void
F_38 (
struct V_2 * V_3 ,
T_5 V_106 )
{
F_1 ( V_3 ) -> V_107 = V_106 ;
}
void
F_39 (
struct V_6 * V_7 ,
struct V_108 * V_44 )
{
struct V_1 * V_5 ;
ASSERT ( V_7 -> V_37 == NULL ) ;
V_5 = V_7 -> V_37 = F_40 ( V_109 , V_35 ) ;
V_5 -> V_8 = V_7 ;
F_41 ( V_44 , & V_5 -> V_4 , V_110 ,
& V_111 ) ;
V_5 -> V_45 . V_112 = V_110 ;
V_5 -> V_45 . V_113 = V_7 -> V_114 ;
V_5 -> V_45 . V_115 = V_7 -> V_116 . V_117 ;
V_5 -> V_45 . V_118 = V_7 -> V_116 . V_119 ;
V_5 -> V_45 . V_120 = V_7 -> V_116 . V_121 ;
}
void
F_42 (
T_6 * V_7 )
{
F_43 ( V_109 , V_7 -> V_37 ) ;
}
void
F_44 (
struct V_91 * V_92 ,
struct V_2 * V_3 )
{
struct V_1 * V_5 ;
struct V_2 * V_122 ;
struct V_2 * V_123 ;
struct V_2 * V_124 ;
struct V_125 * V_126 = V_3 -> V_102 ;
int V_127 = 0 ;
V_122 = V_92 -> V_128 ;
V_124 = NULL ;
while ( V_122 != NULL ) {
if ( V_3 -> V_129 != F_44 ) {
V_124 = V_122 ;
V_122 = V_122 -> V_130 ;
continue;
}
V_123 = V_122 -> V_130 ;
if ( ! V_124 ) {
V_92 -> V_128 = V_123 ;
} else {
V_124 -> V_130 = V_123 ;
}
V_122 -> V_130 = V_3 -> V_130 ;
V_3 -> V_130 = V_122 ;
V_5 = F_1 ( V_122 ) ;
if ( V_5 -> V_101 && V_122 -> V_131 == V_5 -> V_132 )
V_127 ++ ;
V_122 = V_123 ;
}
V_5 = F_1 ( V_3 ) ;
if ( V_5 -> V_101 && V_3 -> V_131 == V_5 -> V_132 )
V_127 ++ ;
if ( V_127 ) {
struct V_2 * V_133 [ V_127 ] ;
int V_134 = 0 ;
F_32 ( & V_126 -> V_103 ) ;
for ( V_122 = V_3 ; V_122 ; V_122 = V_122 -> V_130 ) {
V_5 = F_1 ( V_122 ) ;
if ( V_5 -> V_101 &&
V_122 -> V_131 == V_5 -> V_132 ) {
V_133 [ V_134 ++ ] = V_122 ;
}
ASSERT ( V_134 <= V_127 ) ;
}
F_45 ( V_126 , V_133 , V_134 ,
V_135 ) ;
}
for ( V_122 = V_3 ; V_122 ; V_122 = V_123 ) {
V_123 = V_122 -> V_130 ;
V_122 -> V_130 = NULL ;
V_5 = F_1 ( V_122 ) ;
V_5 -> V_101 = 0 ;
V_5 -> V_136 = 0 ;
F_46 ( V_5 -> V_8 ) ;
}
}
void
F_47 (
T_6 * V_7 ,
bool V_137 )
{
T_7 * V_5 = V_7 -> V_37 ;
if ( V_5 ) {
struct V_125 * V_126 = V_5 -> V_4 . V_102 ;
if ( V_5 -> V_4 . V_138 & V_139 ) {
F_32 ( & V_126 -> V_103 ) ;
if ( V_5 -> V_4 . V_138 & V_139 ) {
F_48 ( V_126 , & V_5 -> V_4 ,
V_137 ?
V_140 :
V_135 ) ;
} else
F_28 ( & V_126 -> V_103 ) ;
}
V_5 -> V_101 = 0 ;
V_5 -> V_136 = 0 ;
V_5 -> V_13 = 0 ;
}
F_46 ( V_7 ) ;
}
void
F_49 (
struct V_91 * V_92 ,
struct V_2 * V_3 )
{
F_47 ( F_1 ( V_3 ) -> V_8 , true ) ;
}
int
F_50 (
T_8 * V_141 ,
V_46 * V_142 )
{
if ( V_141 -> V_41 == sizeof( V_143 ) ) {
V_143 * V_144 = V_141 -> V_40 ;
V_142 -> V_112 = V_144 -> V_112 ;
V_142 -> V_83 = V_144 -> V_83 ;
V_142 -> V_80 = V_144 -> V_80 ;
V_142 -> V_77 = V_144 -> V_77 ;
V_142 -> V_61 = V_144 -> V_61 ;
V_142 -> V_113 = V_144 -> V_113 ;
memcpy ( V_142 -> V_68 . V_72 . V_145 ,
V_144 -> V_68 . V_72 . V_145 ,
sizeof( V_146 ) ) ;
V_142 -> V_115 = V_144 -> V_115 ;
V_142 -> V_118 = V_144 -> V_118 ;
V_142 -> V_120 = V_144 -> V_120 ;
return 0 ;
} else if ( V_141 -> V_41 == sizeof( V_147 ) ) {
V_147 * V_148 = V_141 -> V_40 ;
V_142 -> V_112 = V_148 -> V_112 ;
V_142 -> V_83 = V_148 -> V_83 ;
V_142 -> V_80 = V_148 -> V_80 ;
V_142 -> V_77 = V_148 -> V_77 ;
V_142 -> V_61 = V_148 -> V_61 ;
V_142 -> V_113 = V_148 -> V_113 ;
memcpy ( V_142 -> V_68 . V_72 . V_145 ,
V_148 -> V_68 . V_72 . V_145 ,
sizeof( V_146 ) ) ;
V_142 -> V_115 = V_148 -> V_115 ;
V_142 -> V_118 = V_148 -> V_118 ;
V_142 -> V_120 = V_148 -> V_120 ;
return 0 ;
}
return V_149 ;
}
