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
V_5 -> V_13 &= ~ V_19 ;
}
break;
case V_21 :
V_5 -> V_13 &=
~ ( V_14 | V_19 |
V_57 | V_58 ) ;
if ( ( V_5 -> V_13 & V_22 ) &&
V_7 -> V_16 . V_17 > 0 ) {
ASSERT ( V_7 -> V_16 . V_59 . V_65 != NULL ) ;
ASSERT ( V_7 -> V_10 . V_66 > 0 ) ;
V_32 -> V_40 = V_7 -> V_16 . V_59 . V_65 ;
V_43 = F_12 ( V_7 -> V_16 . V_17 , 4 ) ;
ASSERT ( ( V_7 -> V_16 . V_67 == 0 ) ||
( V_7 -> V_16 . V_67 == V_43 ) ) ;
V_32 -> V_41 = ( int ) V_43 ;
V_32 -> V_42 = V_68 ;
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
V_5 -> V_45 . V_69 . V_70 =
V_7 -> V_16 . V_71 . V_72 ;
}
break;
case V_24 :
V_5 -> V_13 &=
~ ( V_22 | V_19 |
V_14 | V_57 ) ;
if ( V_5 -> V_13 & V_58 ) {
V_5 -> V_45 . V_69 . V_73 =
V_7 -> V_16 . V_71 . V_74 ;
}
break;
default:
ASSERT ( 0 ) ;
break;
}
if ( ! F_4 ( V_7 ) ) {
V_5 -> V_13 &=
~ ( V_30 | V_29 | V_26 ) ;
goto V_75;
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
V_32 -> V_42 = V_76 ;
#else
ASSERT ( V_5 -> V_39 == NULL ) ;
F_5 ( V_7 , V_32 ,
V_77 , V_76 ) ;
#endif
V_5 -> V_45 . V_78 = V_32 -> V_41 ;
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
V_32 -> V_42 = V_79 ;
V_32 ++ ;
V_9 ++ ;
V_5 -> V_45 . V_78 = V_7 -> V_28 -> V_20 ;
} else {
V_5 -> V_13 &= ~ V_29 ;
}
break;
case V_21 :
V_5 -> V_13 &=
~ ( V_26 | V_29 ) ;
if ( ( V_5 -> V_13 & V_30 ) &&
V_7 -> V_28 -> V_17 > 0 ) {
ASSERT ( V_7 -> V_28 -> V_59 . V_65 != NULL ) ;
V_32 -> V_40 = V_7 -> V_28 -> V_59 . V_65 ;
V_43 = F_12 ( V_7 -> V_28 -> V_17 , 4 ) ;
ASSERT ( ( V_7 -> V_28 -> V_67 == 0 ) ||
( V_7 -> V_28 -> V_67 == V_43 ) ) ;
V_32 -> V_41 = ( int ) V_43 ;
V_32 -> V_42 = V_80 ;
V_32 ++ ;
V_9 ++ ;
V_5 -> V_45 . V_78 = ( unsigned ) V_43 ;
} else {
V_5 -> V_13 &= ~ V_30 ;
}
break;
default:
ASSERT ( 0 ) ;
break;
}
V_75:
V_5 -> V_45 . V_81 = V_82 |
( V_5 -> V_13 & ~ V_83 ) ;
V_5 -> V_45 . V_84 = V_9 ;
}
STATIC void
F_13 (
struct V_2 * V_3 )
{
struct V_6 * V_7 = F_1 ( V_3 ) -> V_8 ;
ASSERT ( F_14 ( V_7 , V_85 ) ) ;
F_15 ( V_7 , V_86 ) ;
F_16 ( & V_7 -> V_87 ) ;
}
STATIC void
F_17 (
struct V_2 * V_3 ,
int remove )
{
struct V_6 * V_7 = F_1 ( V_3 ) -> V_8 ;
F_18 ( V_7 , V_86 ) ;
ASSERT ( F_19 ( & V_7 -> V_87 ) > 0 ) ;
if ( F_20 ( & V_7 -> V_87 ) )
F_21 ( & V_7 -> V_88 , V_89 ) ;
}
STATIC T_1
F_22 (
struct V_2 * V_3 ,
struct V_90 * V_91 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_92 * V_93 = NULL ;
T_1 V_94 = V_95 ;
int error ;
if ( F_23 ( V_7 ) > 0 )
return V_96 ;
if ( ! F_24 ( V_7 , V_97 ) )
return V_98 ;
if ( F_23 ( V_7 ) > 0 ) {
V_94 = V_96 ;
goto V_99;
}
if ( V_7 -> V_88 & V_100 ) {
V_94 = V_96 ;
goto V_99;
}
if ( ! F_25 ( V_7 ) ) {
V_94 = V_101 ;
goto V_99;
}
ASSERT ( V_5 -> V_13 != 0 || F_26 ( V_7 -> V_50 ) ) ;
ASSERT ( V_5 -> V_102 == 0 || F_26 ( V_7 -> V_50 ) ) ;
F_27 ( & V_3 -> V_103 -> V_104 ) ;
error = F_28 ( V_7 , & V_93 ) ;
if ( ! error ) {
if ( ! F_29 ( V_93 , V_91 ) )
V_94 = V_101 ;
F_30 ( V_93 ) ;
}
F_31 ( & V_3 -> V_103 -> V_104 ) ;
V_99:
F_32 ( V_7 , V_97 ) ;
return V_94 ;
}
STATIC void
F_33 (
struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
unsigned short V_105 ;
ASSERT ( V_7 -> V_37 != NULL ) ;
ASSERT ( F_14 ( V_7 , V_85 ) ) ;
if ( V_5 -> V_38 != NULL ) {
ASSERT ( V_7 -> V_10 . V_11 == V_12 ) ;
ASSERT ( V_7 -> V_10 . V_15 > 0 ) ;
ASSERT ( V_5 -> V_13 & V_14 ) ;
ASSERT ( V_7 -> V_16 . V_17 > 0 ) ;
F_34 ( V_5 -> V_38 ) ;
V_5 -> V_38 = NULL ;
}
if ( V_5 -> V_39 != NULL ) {
ASSERT ( V_7 -> V_10 . V_25 == V_12 ) ;
ASSERT ( V_7 -> V_10 . V_27 > 0 ) ;
ASSERT ( V_5 -> V_13 & V_26 ) ;
ASSERT ( V_7 -> V_28 -> V_17 > 0 ) ;
F_34 ( V_5 -> V_39 ) ;
V_5 -> V_39 = NULL ;
}
V_105 = V_5 -> V_106 ;
V_5 -> V_106 = 0 ;
if ( V_105 )
F_32 ( V_7 , V_105 ) ;
}
STATIC T_5
F_35 (
struct V_2 * V_3 ,
T_5 V_107 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
if ( F_36 ( V_7 , V_100 ) ) {
F_17 ( V_3 , 0 ) ;
return - 1 ;
}
return V_107 ;
}
STATIC void
F_37 (
struct V_2 * V_3 ,
T_5 V_107 )
{
F_1 ( V_3 ) -> V_108 = V_107 ;
}
void
F_38 (
struct V_6 * V_7 ,
struct V_109 * V_44 )
{
struct V_1 * V_5 ;
ASSERT ( V_7 -> V_37 == NULL ) ;
V_5 = V_7 -> V_37 = F_39 ( V_110 , V_35 ) ;
V_5 -> V_8 = V_7 ;
F_40 ( V_44 , & V_5 -> V_4 , V_111 ,
& V_112 ) ;
V_5 -> V_45 . V_113 = V_111 ;
V_5 -> V_45 . V_114 = V_7 -> V_115 ;
V_5 -> V_45 . V_116 = V_7 -> V_117 . V_118 ;
V_5 -> V_45 . V_119 = V_7 -> V_117 . V_120 ;
V_5 -> V_45 . V_121 = V_7 -> V_117 . V_122 ;
}
void
F_41 (
T_6 * V_7 )
{
F_42 ( V_110 , V_7 -> V_37 ) ;
}
void
F_43 (
struct V_92 * V_93 ,
struct V_2 * V_3 )
{
struct V_1 * V_5 ;
struct V_2 * V_123 ;
struct V_2 * V_124 ;
struct V_2 * V_125 ;
struct V_126 * V_127 = V_3 -> V_103 ;
int V_128 = 0 ;
V_123 = V_93 -> V_129 ;
V_125 = NULL ;
while ( V_123 != NULL ) {
if ( V_3 -> V_130 != F_43 ) {
V_125 = V_123 ;
V_123 = V_123 -> V_131 ;
continue;
}
V_124 = V_123 -> V_131 ;
if ( ! V_125 ) {
V_93 -> V_129 = V_124 ;
} else {
V_125 -> V_131 = V_124 ;
}
V_123 -> V_131 = V_3 -> V_131 ;
V_3 -> V_131 = V_123 ;
V_5 = F_1 ( V_123 ) ;
if ( V_5 -> V_102 && V_123 -> V_132 == V_5 -> V_133 )
V_128 ++ ;
V_123 = V_124 ;
}
V_5 = F_1 ( V_3 ) ;
if ( V_5 -> V_102 && V_3 -> V_132 == V_5 -> V_133 )
V_128 ++ ;
if ( V_128 ) {
struct V_2 * V_134 [ V_128 ] ;
int V_135 = 0 ;
F_31 ( & V_127 -> V_104 ) ;
for ( V_123 = V_3 ; V_123 ; V_123 = V_123 -> V_131 ) {
V_5 = F_1 ( V_123 ) ;
if ( V_5 -> V_102 &&
V_123 -> V_132 == V_5 -> V_133 ) {
V_134 [ V_135 ++ ] = V_123 ;
}
ASSERT ( V_135 <= V_128 ) ;
}
F_44 ( V_127 , V_134 , V_135 ,
V_136 ) ;
}
for ( V_123 = V_3 ; V_123 ; V_123 = V_124 ) {
V_124 = V_123 -> V_131 ;
V_123 -> V_131 = NULL ;
V_5 = F_1 ( V_123 ) ;
V_5 -> V_102 = 0 ;
V_5 -> V_137 = 0 ;
F_45 ( V_5 -> V_8 ) ;
}
}
void
F_46 (
T_6 * V_7 ,
bool V_138 )
{
T_7 * V_5 = V_7 -> V_37 ;
if ( V_5 ) {
struct V_126 * V_127 = V_5 -> V_4 . V_103 ;
if ( V_5 -> V_4 . V_139 & V_140 ) {
F_31 ( & V_127 -> V_104 ) ;
if ( V_5 -> V_4 . V_139 & V_140 ) {
F_47 ( V_127 , & V_5 -> V_4 ,
V_138 ?
V_141 :
V_136 ) ;
} else
F_27 ( & V_127 -> V_104 ) ;
}
V_5 -> V_102 = 0 ;
V_5 -> V_137 = 0 ;
V_5 -> V_13 = 0 ;
}
F_45 ( V_7 ) ;
}
void
F_48 (
struct V_92 * V_93 ,
struct V_2 * V_3 )
{
F_46 ( F_1 ( V_3 ) -> V_8 , true ) ;
}
int
F_49 (
T_8 * V_142 ,
V_46 * V_143 )
{
if ( V_142 -> V_41 == sizeof( V_144 ) ) {
V_144 * V_145 = V_142 -> V_40 ;
V_143 -> V_113 = V_145 -> V_113 ;
V_143 -> V_84 = V_145 -> V_84 ;
V_143 -> V_81 = V_145 -> V_81 ;
V_143 -> V_78 = V_145 -> V_78 ;
V_143 -> V_62 = V_145 -> V_62 ;
V_143 -> V_114 = V_145 -> V_114 ;
memcpy ( V_143 -> V_69 . V_73 . V_146 ,
V_145 -> V_69 . V_73 . V_146 ,
sizeof( V_147 ) ) ;
V_143 -> V_116 = V_145 -> V_116 ;
V_143 -> V_119 = V_145 -> V_119 ;
V_143 -> V_121 = V_145 -> V_121 ;
return 0 ;
} else if ( V_142 -> V_41 == sizeof( V_148 ) ) {
V_148 * V_149 = V_142 -> V_40 ;
V_143 -> V_113 = V_149 -> V_113 ;
V_143 -> V_84 = V_149 -> V_84 ;
V_143 -> V_81 = V_149 -> V_81 ;
V_143 -> V_78 = V_149 -> V_78 ;
V_143 -> V_62 = V_149 -> V_62 ;
V_143 -> V_114 = V_149 -> V_114 ;
memcpy ( V_143 -> V_69 . V_73 . V_146 ,
V_149 -> V_69 . V_73 . V_146 ,
sizeof( V_147 ) ) ;
V_143 -> V_116 = V_149 -> V_116 ;
V_143 -> V_119 = V_149 -> V_119 ;
V_143 -> V_121 = V_149 -> V_121 ;
return 0 ;
}
return V_150 ;
}
