static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
STATIC void
F_3 (
struct V_2 * V_3 ,
int * V_5 ,
int * V_6 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
* V_5 += 2 ;
* V_6 += sizeof( struct V_11 ) +
F_4 ( V_9 -> V_12 . V_13 ) ;
switch ( V_9 -> V_12 . V_14 ) {
case V_15 :
if ( ( V_7 -> V_16 & V_17 ) &&
V_9 -> V_12 . V_18 > 0 &&
V_9 -> V_19 . V_20 > 0 ) {
* V_6 += F_5 ( V_9 ) ;
* V_5 += 1 ;
}
break;
case V_21 :
if ( ( V_7 -> V_16 & V_22 ) &&
V_9 -> V_19 . V_23 > 0 ) {
* V_6 += V_9 -> V_19 . V_23 ;
* V_5 += 1 ;
}
break;
case V_24 :
if ( ( V_7 -> V_16 & V_25 ) &&
V_9 -> V_19 . V_20 > 0 ) {
* V_6 += F_6 ( V_9 -> V_19 . V_20 , 4 ) ;
* V_5 += 1 ;
}
break;
case V_26 :
case V_27 :
break;
default:
ASSERT ( 0 ) ;
break;
}
if ( ! F_7 ( V_9 ) )
return;
switch ( V_9 -> V_12 . V_28 ) {
case V_15 :
if ( ( V_7 -> V_16 & V_29 ) &&
V_9 -> V_12 . V_30 > 0 &&
V_9 -> V_31 -> V_20 > 0 ) {
* V_6 += F_8 ( V_9 ) ;
* V_5 += 1 ;
}
break;
case V_21 :
if ( ( V_7 -> V_16 & V_32 ) &&
V_9 -> V_31 -> V_23 > 0 ) {
* V_6 += V_9 -> V_31 -> V_23 ;
* V_5 += 1 ;
}
break;
case V_24 :
if ( ( V_7 -> V_16 & V_33 ) &&
V_9 -> V_31 -> V_20 > 0 ) {
* V_6 += F_6 ( V_9 -> V_31 -> V_20 , 4 ) ;
* V_5 += 1 ;
}
break;
default:
ASSERT ( 0 ) ;
break;
}
}
STATIC void
F_9 (
struct V_8 * V_9 ,
struct V_34 * V_35 ,
int V_36 ,
int type )
{
T_1 * V_37 ;
V_37 = F_10 ( F_11 ( V_9 , V_36 ) , V_38 ) ;
if ( V_36 == V_39 )
V_9 -> V_40 -> V_41 = V_37 ;
else
V_9 -> V_40 -> V_42 = V_37 ;
V_35 -> V_43 = V_37 ;
V_35 -> V_44 = F_12 ( V_9 , V_37 , V_36 ) ;
V_35 -> V_45 = type ;
}
STATIC void
F_13 (
struct V_2 * V_3 ,
struct V_34 * V_35 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
T_2 V_5 ;
T_3 V_46 ;
T_4 * V_47 ;
V_35 -> V_43 = & V_7 -> V_48 ;
V_35 -> V_44 = sizeof( V_49 ) ;
V_35 -> V_45 = V_50 ;
V_35 ++ ;
V_5 = 1 ;
V_35 -> V_43 = & V_9 -> V_12 ;
V_35 -> V_44 = F_4 ( V_9 -> V_12 . V_13 ) ;
V_35 -> V_45 = V_51 ;
V_35 ++ ;
V_5 ++ ;
V_47 = V_9 -> V_52 ;
ASSERT ( V_9 -> V_12 . V_13 == 1 || F_14 ( & V_47 -> V_53 ) ) ;
if ( V_9 -> V_12 . V_13 == 1 ) {
if ( ! F_14 ( & V_47 -> V_53 ) ) {
ASSERT ( V_9 -> V_12 . V_54 <= V_55 ) ;
V_9 -> V_12 . V_56 = V_9 -> V_12 . V_54 ;
} else {
V_9 -> V_12 . V_13 = 2 ;
V_9 -> V_12 . V_56 = 0 ;
memset ( & ( V_9 -> V_12 . V_57 [ 0 ] ) , 0 , sizeof( V_9 -> V_12 . V_57 ) ) ;
}
}
switch ( V_9 -> V_12 . V_14 ) {
case V_15 :
V_7 -> V_16 &=
~ ( V_25 | V_22 |
V_58 | V_59 ) ;
if ( ( V_7 -> V_16 & V_17 ) &&
V_9 -> V_12 . V_18 > 0 &&
V_9 -> V_19 . V_20 > 0 ) {
ASSERT ( V_9 -> V_19 . V_60 . V_61 != NULL ) ;
ASSERT ( V_9 -> V_19 . V_20 / sizeof( T_1 ) > 0 ) ;
ASSERT ( V_7 -> V_41 == NULL ) ;
#ifdef F_15
if ( V_9 -> V_12 . V_18 == V_9 -> V_19 . V_20 /
( T_2 ) sizeof( T_1 ) ) {
V_35 -> V_43 = V_9 -> V_19 . V_60 . V_61 ;
V_35 -> V_44 = V_9 -> V_19 . V_20 ;
V_35 -> V_45 = V_62 ;
} else
#endif
{
F_9 ( V_9 , V_35 ,
V_39 , V_62 ) ;
}
ASSERT ( V_35 -> V_44 <= V_9 -> V_19 . V_20 ) ;
V_7 -> V_48 . V_63 = V_35 -> V_44 ;
V_35 ++ ;
V_5 ++ ;
} else {
V_7 -> V_16 &= ~ V_17 ;
}
break;
case V_21 :
V_7 -> V_16 &=
~ ( V_25 | V_17 |
V_58 | V_59 ) ;
if ( ( V_7 -> V_16 & V_22 ) &&
V_9 -> V_19 . V_23 > 0 ) {
ASSERT ( V_9 -> V_19 . V_64 != NULL ) ;
V_35 -> V_43 = V_9 -> V_19 . V_64 ;
V_35 -> V_44 = V_9 -> V_19 . V_23 ;
V_35 -> V_45 = V_65 ;
V_35 ++ ;
V_5 ++ ;
V_7 -> V_48 . V_63 = V_9 -> V_19 . V_23 ;
} else {
ASSERT ( ! ( V_7 -> V_16 &
V_22 ) ) ;
V_7 -> V_16 &= ~ V_22 ;
}
break;
case V_24 :
V_7 -> V_16 &=
~ ( V_17 | V_22 |
V_58 | V_59 ) ;
if ( ( V_7 -> V_16 & V_25 ) &&
V_9 -> V_19 . V_20 > 0 ) {
ASSERT ( V_9 -> V_19 . V_60 . V_66 != NULL ) ;
ASSERT ( V_9 -> V_12 . V_67 > 0 ) ;
V_35 -> V_43 = V_9 -> V_19 . V_60 . V_66 ;
V_46 = F_6 ( V_9 -> V_19 . V_20 , 4 ) ;
ASSERT ( ( V_9 -> V_19 . V_68 == 0 ) ||
( V_9 -> V_19 . V_68 == V_46 ) ) ;
V_35 -> V_44 = ( int ) V_46 ;
V_35 -> V_45 = V_69 ;
V_35 ++ ;
V_5 ++ ;
V_7 -> V_48 . V_63 = ( unsigned ) V_46 ;
} else {
V_7 -> V_16 &= ~ V_25 ;
}
break;
case V_26 :
V_7 -> V_16 &=
~ ( V_25 | V_22 |
V_17 | V_59 ) ;
if ( V_7 -> V_16 & V_58 ) {
V_7 -> V_48 . V_70 . V_71 =
V_9 -> V_19 . V_72 . V_73 ;
}
break;
case V_27 :
V_7 -> V_16 &=
~ ( V_25 | V_22 |
V_17 | V_58 ) ;
if ( V_7 -> V_16 & V_59 ) {
V_7 -> V_48 . V_70 . V_74 =
V_9 -> V_19 . V_72 . V_75 ;
}
break;
default:
ASSERT ( 0 ) ;
break;
}
if ( ! F_7 ( V_9 ) ) {
V_7 -> V_16 &=
~ ( V_33 | V_32 | V_29 ) ;
goto V_76;
}
switch ( V_9 -> V_12 . V_28 ) {
case V_15 :
V_7 -> V_16 &=
~ ( V_33 | V_32 ) ;
if ( ( V_7 -> V_16 & V_29 ) &&
V_9 -> V_12 . V_30 > 0 &&
V_9 -> V_31 -> V_20 > 0 ) {
ASSERT ( V_9 -> V_31 -> V_20 / sizeof( T_1 ) ==
V_9 -> V_12 . V_30 ) ;
ASSERT ( V_9 -> V_31 -> V_60 . V_61 != NULL ) ;
#ifdef F_15
V_35 -> V_43 = V_9 -> V_31 -> V_60 . V_61 ;
V_35 -> V_44 = V_9 -> V_31 -> V_20 ;
V_35 -> V_45 = V_77 ;
#else
ASSERT ( V_7 -> V_42 == NULL ) ;
F_9 ( V_9 , V_35 ,
V_78 , V_77 ) ;
#endif
V_7 -> V_48 . V_79 = V_35 -> V_44 ;
V_35 ++ ;
V_5 ++ ;
} else {
V_7 -> V_16 &= ~ V_29 ;
}
break;
case V_21 :
V_7 -> V_16 &=
~ ( V_33 | V_29 ) ;
if ( ( V_7 -> V_16 & V_32 ) &&
V_9 -> V_31 -> V_23 > 0 ) {
ASSERT ( V_9 -> V_31 -> V_64 != NULL ) ;
V_35 -> V_43 = V_9 -> V_31 -> V_64 ;
V_35 -> V_44 = V_9 -> V_31 -> V_23 ;
V_35 -> V_45 = V_80 ;
V_35 ++ ;
V_5 ++ ;
V_7 -> V_48 . V_79 = V_9 -> V_31 -> V_23 ;
} else {
V_7 -> V_16 &= ~ V_32 ;
}
break;
case V_24 :
V_7 -> V_16 &=
~ ( V_29 | V_32 ) ;
if ( ( V_7 -> V_16 & V_33 ) &&
V_9 -> V_31 -> V_20 > 0 ) {
ASSERT ( V_9 -> V_31 -> V_60 . V_66 != NULL ) ;
V_35 -> V_43 = V_9 -> V_31 -> V_60 . V_66 ;
V_46 = F_6 ( V_9 -> V_31 -> V_20 , 4 ) ;
ASSERT ( ( V_9 -> V_31 -> V_68 == 0 ) ||
( V_9 -> V_31 -> V_68 == V_46 ) ) ;
V_35 -> V_44 = ( int ) V_46 ;
V_35 -> V_45 = V_81 ;
V_35 ++ ;
V_5 ++ ;
V_7 -> V_48 . V_79 = ( unsigned ) V_46 ;
} else {
V_7 -> V_16 &= ~ V_33 ;
}
break;
default:
ASSERT ( 0 ) ;
break;
}
V_76:
V_7 -> V_48 . V_82 = V_83 |
( V_7 -> V_16 & ~ V_84 ) ;
V_7 -> V_48 . V_85 = V_5 ;
}
STATIC void
F_16 (
struct V_2 * V_3 )
{
struct V_8 * V_9 = F_1 ( V_3 ) -> V_10 ;
ASSERT ( F_17 ( V_9 , V_86 ) ) ;
F_18 ( V_9 , V_87 ) ;
F_19 ( & V_9 -> V_88 ) ;
}
STATIC void
F_20 (
struct V_2 * V_3 ,
int remove )
{
struct V_8 * V_9 = F_1 ( V_3 ) -> V_10 ;
F_21 ( V_9 , V_87 ) ;
ASSERT ( F_22 ( & V_9 -> V_88 ) > 0 ) ;
if ( F_23 ( & V_9 -> V_88 ) )
F_24 ( & V_9 -> V_89 , V_90 ) ;
}
STATIC T_2
F_25 (
struct V_2 * V_3 ,
struct V_91 * V_92 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_93 * V_94 = NULL ;
T_2 V_95 = V_96 ;
int error ;
if ( F_26 ( V_9 ) > 0 )
return V_97 ;
if ( ! F_27 ( V_9 , V_98 ) )
return V_99 ;
if ( F_26 ( V_9 ) > 0 ) {
V_95 = V_97 ;
goto V_100;
}
if ( V_9 -> V_89 & V_101 ) {
V_95 = V_97 ;
goto V_100;
}
if ( ! F_28 ( V_9 ) ) {
V_95 = V_102 ;
goto V_100;
}
ASSERT ( V_7 -> V_16 != 0 || F_29 ( V_9 -> V_52 ) ) ;
ASSERT ( V_7 -> V_103 == 0 || F_29 ( V_9 -> V_52 ) ) ;
F_30 ( & V_3 -> V_104 -> V_105 ) ;
error = F_31 ( V_9 , & V_94 ) ;
if ( ! error ) {
if ( ! F_32 ( V_94 , V_92 ) )
V_95 = V_102 ;
F_33 ( V_94 ) ;
}
F_34 ( & V_3 -> V_104 -> V_105 ) ;
V_100:
F_35 ( V_9 , V_98 ) ;
return V_95 ;
}
STATIC void
F_36 (
struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
unsigned short V_106 ;
ASSERT ( V_9 -> V_40 != NULL ) ;
ASSERT ( F_17 ( V_9 , V_86 ) ) ;
if ( V_7 -> V_41 != NULL ) {
ASSERT ( V_9 -> V_12 . V_14 == V_15 ) ;
ASSERT ( V_9 -> V_12 . V_18 > 0 ) ;
ASSERT ( V_7 -> V_16 & V_17 ) ;
ASSERT ( V_9 -> V_19 . V_20 > 0 ) ;
F_37 ( V_7 -> V_41 ) ;
V_7 -> V_41 = NULL ;
}
if ( V_7 -> V_42 != NULL ) {
ASSERT ( V_9 -> V_12 . V_28 == V_15 ) ;
ASSERT ( V_9 -> V_12 . V_30 > 0 ) ;
ASSERT ( V_7 -> V_16 & V_29 ) ;
ASSERT ( V_9 -> V_31 -> V_20 > 0 ) ;
F_37 ( V_7 -> V_42 ) ;
V_7 -> V_42 = NULL ;
}
V_106 = V_7 -> V_107 ;
V_7 -> V_107 = 0 ;
if ( V_106 )
F_35 ( V_9 , V_106 ) ;
}
STATIC T_5
F_38 (
struct V_2 * V_3 ,
T_5 V_108 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
if ( F_39 ( V_9 , V_101 ) ) {
F_20 ( V_3 , 0 ) ;
return - 1 ;
}
return V_108 ;
}
STATIC void
F_40 (
struct V_2 * V_3 ,
T_5 V_108 )
{
F_1 ( V_3 ) -> V_109 = V_108 ;
}
void
F_41 (
struct V_8 * V_9 ,
struct V_110 * V_47 )
{
struct V_1 * V_7 ;
ASSERT ( V_9 -> V_40 == NULL ) ;
V_7 = V_9 -> V_40 = F_42 ( V_111 , V_38 ) ;
V_7 -> V_10 = V_9 ;
F_43 ( V_47 , & V_7 -> V_4 , V_112 ,
& V_113 ) ;
V_7 -> V_48 . V_114 = V_112 ;
V_7 -> V_48 . V_115 = V_9 -> V_116 ;
V_7 -> V_48 . V_117 = V_9 -> V_118 . V_119 ;
V_7 -> V_48 . V_120 = V_9 -> V_118 . V_121 ;
V_7 -> V_48 . V_122 = V_9 -> V_118 . V_123 ;
}
void
F_44 (
T_6 * V_9 )
{
F_45 ( V_111 , V_9 -> V_40 ) ;
}
void
F_46 (
struct V_93 * V_94 ,
struct V_2 * V_3 )
{
struct V_1 * V_7 ;
struct V_2 * V_124 ;
struct V_2 * V_125 ;
struct V_2 * V_126 ;
struct V_127 * V_128 = V_3 -> V_104 ;
int V_129 = 0 ;
V_124 = V_94 -> V_130 ;
V_126 = NULL ;
while ( V_124 != NULL ) {
if ( V_3 -> V_131 != F_46 ) {
V_126 = V_124 ;
V_124 = V_124 -> V_132 ;
continue;
}
V_125 = V_124 -> V_132 ;
if ( ! V_126 ) {
V_94 -> V_130 = V_125 ;
} else {
V_126 -> V_132 = V_125 ;
}
V_124 -> V_132 = V_3 -> V_132 ;
V_3 -> V_132 = V_124 ;
V_7 = F_1 ( V_124 ) ;
if ( V_7 -> V_103 && V_124 -> V_133 == V_7 -> V_134 )
V_129 ++ ;
V_124 = V_125 ;
}
V_7 = F_1 ( V_3 ) ;
if ( V_7 -> V_103 && V_3 -> V_133 == V_7 -> V_134 )
V_129 ++ ;
if ( V_129 ) {
struct V_2 * V_135 [ V_129 ] ;
int V_136 = 0 ;
F_34 ( & V_128 -> V_105 ) ;
for ( V_124 = V_3 ; V_124 ; V_124 = V_124 -> V_132 ) {
V_7 = F_1 ( V_124 ) ;
if ( V_7 -> V_103 &&
V_124 -> V_133 == V_7 -> V_134 ) {
V_135 [ V_136 ++ ] = V_124 ;
}
ASSERT ( V_136 <= V_129 ) ;
}
F_47 ( V_128 , V_135 , V_136 ,
V_137 ) ;
}
for ( V_124 = V_3 ; V_124 ; V_124 = V_125 ) {
V_125 = V_124 -> V_132 ;
V_124 -> V_132 = NULL ;
V_7 = F_1 ( V_124 ) ;
V_7 -> V_103 = 0 ;
V_7 -> V_138 = 0 ;
F_48 ( V_7 -> V_10 ) ;
}
}
void
F_49 (
T_6 * V_9 ,
bool V_139 )
{
T_7 * V_7 = V_9 -> V_40 ;
if ( V_7 ) {
struct V_127 * V_128 = V_7 -> V_4 . V_104 ;
if ( V_7 -> V_4 . V_140 & V_141 ) {
F_34 ( & V_128 -> V_105 ) ;
if ( V_7 -> V_4 . V_140 & V_141 ) {
F_50 ( V_128 , & V_7 -> V_4 ,
V_139 ?
V_142 :
V_137 ) ;
} else
F_30 ( & V_128 -> V_105 ) ;
}
V_7 -> V_103 = 0 ;
V_7 -> V_138 = 0 ;
V_7 -> V_16 = 0 ;
}
F_48 ( V_9 ) ;
}
void
F_51 (
struct V_93 * V_94 ,
struct V_2 * V_3 )
{
F_49 ( F_1 ( V_3 ) -> V_10 , true ) ;
}
int
F_52 (
T_8 * V_143 ,
V_49 * V_144 )
{
if ( V_143 -> V_44 == sizeof( V_145 ) ) {
V_145 * V_146 = V_143 -> V_43 ;
V_144 -> V_114 = V_146 -> V_114 ;
V_144 -> V_85 = V_146 -> V_85 ;
V_144 -> V_82 = V_146 -> V_82 ;
V_144 -> V_79 = V_146 -> V_79 ;
V_144 -> V_63 = V_146 -> V_63 ;
V_144 -> V_115 = V_146 -> V_115 ;
memcpy ( V_144 -> V_70 . V_74 . V_147 ,
V_146 -> V_70 . V_74 . V_147 ,
sizeof( V_148 ) ) ;
V_144 -> V_117 = V_146 -> V_117 ;
V_144 -> V_120 = V_146 -> V_120 ;
V_144 -> V_122 = V_146 -> V_122 ;
return 0 ;
} else if ( V_143 -> V_44 == sizeof( V_149 ) ) {
V_149 * V_150 = V_143 -> V_43 ;
V_144 -> V_114 = V_150 -> V_114 ;
V_144 -> V_85 = V_150 -> V_85 ;
V_144 -> V_82 = V_150 -> V_82 ;
V_144 -> V_79 = V_150 -> V_79 ;
V_144 -> V_63 = V_150 -> V_63 ;
V_144 -> V_115 = V_150 -> V_115 ;
memcpy ( V_144 -> V_70 . V_74 . V_147 ,
V_150 -> V_70 . V_74 . V_147 ,
sizeof( V_148 ) ) ;
V_144 -> V_117 = V_150 -> V_117 ;
V_144 -> V_120 = V_150 -> V_120 ;
V_144 -> V_122 = V_150 -> V_122 ;
return 0 ;
}
return V_151 ;
}
