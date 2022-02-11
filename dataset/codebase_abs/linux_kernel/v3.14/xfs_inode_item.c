static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
STATIC void
F_3 (
struct V_1 * V_5 ,
int * V_6 ,
int * V_7 )
{
struct V_8 * V_9 = V_5 -> V_10 ;
switch ( V_9 -> V_11 . V_12 ) {
case V_13 :
if ( ( V_5 -> V_14 & V_15 ) &&
V_9 -> V_11 . V_16 > 0 &&
V_9 -> V_17 . V_18 > 0 ) {
* V_7 += F_4 ( V_9 ) ;
* V_6 += 1 ;
}
break;
case V_19 :
if ( ( V_5 -> V_14 & V_20 ) &&
V_9 -> V_17 . V_21 > 0 ) {
* V_7 += V_9 -> V_17 . V_21 ;
* V_6 += 1 ;
}
break;
case V_22 :
if ( ( V_5 -> V_14 & V_23 ) &&
V_9 -> V_17 . V_18 > 0 ) {
* V_7 += F_5 ( V_9 -> V_17 . V_18 , 4 ) ;
* V_6 += 1 ;
}
break;
case V_24 :
case V_25 :
break;
default:
ASSERT ( 0 ) ;
break;
}
}
STATIC void
F_6 (
struct V_1 * V_5 ,
int * V_6 ,
int * V_7 )
{
struct V_8 * V_9 = V_5 -> V_10 ;
switch ( V_9 -> V_11 . V_26 ) {
case V_13 :
if ( ( V_5 -> V_14 & V_27 ) &&
V_9 -> V_11 . V_28 > 0 &&
V_9 -> V_29 -> V_18 > 0 ) {
* V_7 += F_7 ( V_9 ) ;
* V_6 += 1 ;
}
break;
case V_19 :
if ( ( V_5 -> V_14 & V_30 ) &&
V_9 -> V_29 -> V_21 > 0 ) {
* V_7 += V_9 -> V_29 -> V_21 ;
* V_6 += 1 ;
}
break;
case V_22 :
if ( ( V_5 -> V_14 & V_31 ) &&
V_9 -> V_29 -> V_18 > 0 ) {
* V_7 += F_5 ( V_9 -> V_29 -> V_18 , 4 ) ;
* V_6 += 1 ;
}
break;
default:
ASSERT ( 0 ) ;
break;
}
}
STATIC void
F_8 (
struct V_2 * V_3 ,
int * V_6 ,
int * V_7 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_8 * V_9 = V_5 -> V_10 ;
* V_6 += 2 ;
* V_7 += sizeof( struct V_32 ) +
F_9 ( V_9 -> V_11 . V_33 ) ;
F_3 ( V_5 , V_6 , V_7 ) ;
if ( F_10 ( V_9 ) )
F_6 ( V_5 , V_6 , V_7 ) ;
}
STATIC void
F_11 (
struct V_8 * V_9 )
{
if ( ! F_12 ( & V_9 -> V_34 -> V_35 ) ) {
ASSERT ( V_9 -> V_11 . V_36 <= V_37 ) ;
V_9 -> V_11 . V_38 = V_9 -> V_11 . V_36 ;
} else {
V_9 -> V_11 . V_33 = 2 ;
V_9 -> V_11 . V_38 = 0 ;
memset ( & ( V_9 -> V_11 . V_39 [ 0 ] ) , 0 , sizeof( V_9 -> V_11 . V_39 ) ) ;
}
}
STATIC void
F_13 (
struct V_1 * V_5 ,
struct V_32 * V_40 ,
struct V_41 * V_42 ,
struct V_43 * * V_44 )
{
struct V_8 * V_9 = V_5 -> V_10 ;
T_1 V_45 ;
switch ( V_9 -> V_11 . V_12 ) {
case V_13 :
V_5 -> V_14 &=
~ ( V_23 | V_20 |
V_46 | V_47 ) ;
if ( ( V_5 -> V_14 & V_15 ) &&
V_9 -> V_11 . V_16 > 0 &&
V_9 -> V_17 . V_18 > 0 ) {
struct V_48 * V_49 ;
ASSERT ( V_9 -> V_17 . V_50 . V_51 != NULL ) ;
ASSERT ( V_9 -> V_17 . V_18 / sizeof( V_52 ) > 0 ) ;
V_49 = F_14 ( V_42 , V_44 , V_53 ) ;
V_45 = F_15 ( V_9 , V_49 , V_54 ) ;
F_16 ( V_42 , * V_44 , V_45 ) ;
ASSERT ( V_45 <= V_9 -> V_17 . V_18 ) ;
V_40 -> V_55 = V_45 ;
V_40 -> V_56 ++ ;
} else {
V_5 -> V_14 &= ~ V_15 ;
}
break;
case V_19 :
V_5 -> V_14 &=
~ ( V_23 | V_15 |
V_46 | V_47 ) ;
if ( ( V_5 -> V_14 & V_20 ) &&
V_9 -> V_17 . V_21 > 0 ) {
ASSERT ( V_9 -> V_17 . V_57 != NULL ) ;
F_17 ( V_42 , V_44 , V_58 ,
V_9 -> V_17 . V_57 ,
V_9 -> V_17 . V_21 ) ;
V_40 -> V_55 = V_9 -> V_17 . V_21 ;
V_40 -> V_56 ++ ;
} else {
ASSERT ( ! ( V_5 -> V_14 &
V_20 ) ) ;
V_5 -> V_14 &= ~ V_20 ;
}
break;
case V_22 :
V_5 -> V_14 &=
~ ( V_15 | V_20 |
V_46 | V_47 ) ;
if ( ( V_5 -> V_14 & V_23 ) &&
V_9 -> V_17 . V_18 > 0 ) {
V_45 = F_5 ( V_9 -> V_17 . V_18 , 4 ) ;
ASSERT ( V_9 -> V_17 . V_59 == 0 ||
V_9 -> V_17 . V_59 == V_45 ) ;
ASSERT ( V_9 -> V_17 . V_50 . V_60 != NULL ) ;
ASSERT ( V_9 -> V_11 . V_61 > 0 ) ;
F_17 ( V_42 , V_44 , V_62 ,
V_9 -> V_17 . V_50 . V_60 , V_45 ) ;
V_40 -> V_55 = ( unsigned ) V_45 ;
V_40 -> V_56 ++ ;
} else {
V_5 -> V_14 &= ~ V_23 ;
}
break;
case V_24 :
V_5 -> V_14 &=
~ ( V_23 | V_20 |
V_15 | V_47 ) ;
if ( V_5 -> V_14 & V_46 )
V_40 -> V_63 . V_64 = V_9 -> V_17 . V_65 . V_66 ;
break;
case V_25 :
V_5 -> V_14 &=
~ ( V_23 | V_20 |
V_15 | V_46 ) ;
if ( V_5 -> V_14 & V_47 )
V_40 -> V_63 . V_67 = V_9 -> V_17 . V_65 . V_68 ;
break;
default:
ASSERT ( 0 ) ;
break;
}
}
STATIC void
F_18 (
struct V_1 * V_5 ,
struct V_32 * V_40 ,
struct V_41 * V_42 ,
struct V_43 * * V_44 )
{
struct V_8 * V_9 = V_5 -> V_10 ;
T_1 V_45 ;
switch ( V_9 -> V_11 . V_26 ) {
case V_13 :
V_5 -> V_14 &=
~ ( V_31 | V_30 ) ;
if ( ( V_5 -> V_14 & V_27 ) &&
V_9 -> V_11 . V_28 > 0 &&
V_9 -> V_29 -> V_18 > 0 ) {
struct V_48 * V_49 ;
ASSERT ( V_9 -> V_29 -> V_18 / sizeof( V_52 ) ==
V_9 -> V_11 . V_28 ) ;
ASSERT ( V_9 -> V_29 -> V_50 . V_51 != NULL ) ;
V_49 = F_14 ( V_42 , V_44 , V_69 ) ;
V_45 = F_15 ( V_9 , V_49 , V_70 ) ;
F_16 ( V_42 , * V_44 , V_45 ) ;
V_40 -> V_71 = V_45 ;
V_40 -> V_56 ++ ;
} else {
V_5 -> V_14 &= ~ V_27 ;
}
break;
case V_19 :
V_5 -> V_14 &=
~ ( V_31 | V_27 ) ;
if ( ( V_5 -> V_14 & V_30 ) &&
V_9 -> V_29 -> V_21 > 0 ) {
ASSERT ( V_9 -> V_29 -> V_57 != NULL ) ;
F_17 ( V_42 , V_44 , V_72 ,
V_9 -> V_29 -> V_57 ,
V_9 -> V_29 -> V_21 ) ;
V_40 -> V_71 = V_9 -> V_29 -> V_21 ;
V_40 -> V_56 ++ ;
} else {
V_5 -> V_14 &= ~ V_30 ;
}
break;
case V_22 :
V_5 -> V_14 &=
~ ( V_27 | V_30 ) ;
if ( ( V_5 -> V_14 & V_31 ) &&
V_9 -> V_29 -> V_18 > 0 ) {
V_45 = F_5 ( V_9 -> V_29 -> V_18 , 4 ) ;
ASSERT ( V_9 -> V_29 -> V_59 == 0 ||
V_9 -> V_29 -> V_59 == V_45 ) ;
ASSERT ( V_9 -> V_29 -> V_50 . V_60 != NULL ) ;
F_17 ( V_42 , V_44 , V_73 ,
V_9 -> V_29 -> V_50 . V_60 ,
V_45 ) ;
V_40 -> V_71 = ( unsigned ) V_45 ;
V_40 -> V_56 ++ ;
} else {
V_5 -> V_14 &= ~ V_31 ;
}
break;
default:
ASSERT ( 0 ) ;
break;
}
}
STATIC void
F_19 (
struct V_2 * V_3 ,
struct V_41 * V_42 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_8 * V_9 = V_5 -> V_10 ;
struct V_32 * V_40 ;
struct V_43 * V_44 = NULL ;
V_40 = F_14 ( V_42 , & V_44 , V_74 ) ;
V_40 -> V_75 = V_76 ;
V_40 -> V_77 = V_9 -> V_78 ;
V_40 -> V_79 = V_9 -> V_80 . V_81 ;
V_40 -> V_82 = V_9 -> V_80 . V_83 ;
V_40 -> V_84 = V_9 -> V_80 . V_85 ;
V_40 -> V_86 = V_87 ;
V_40 -> V_56 = 2 ;
F_16 ( V_42 , V_44 , sizeof( struct V_32 ) ) ;
if ( V_9 -> V_11 . V_33 == 1 )
F_11 ( V_9 ) ;
F_17 ( V_42 , & V_44 , V_88 ,
& V_9 -> V_11 ,
F_9 ( V_9 -> V_11 . V_33 ) ) ;
F_13 ( V_5 , V_40 , V_42 , & V_44 ) ;
if ( F_10 ( V_9 ) ) {
F_18 ( V_5 , V_40 , V_42 , & V_44 ) ;
} else {
V_5 -> V_14 &=
~ ( V_31 | V_30 | V_27 ) ;
}
V_40 -> V_86 |= ( V_5 -> V_14 & ~ V_89 ) ;
}
STATIC void
F_20 (
struct V_2 * V_3 )
{
struct V_8 * V_9 = F_1 ( V_3 ) -> V_10 ;
ASSERT ( F_21 ( V_9 , V_90 ) ) ;
F_22 ( V_9 , V_91 ) ;
F_23 ( & V_9 -> V_92 ) ;
}
STATIC void
F_24 (
struct V_2 * V_3 ,
int remove )
{
struct V_8 * V_9 = F_1 ( V_3 ) -> V_10 ;
F_25 ( V_9 , V_91 ) ;
ASSERT ( F_26 ( & V_9 -> V_92 ) > 0 ) ;
if ( F_27 ( & V_9 -> V_92 ) )
F_28 ( & V_9 -> V_93 , V_94 ) ;
}
STATIC T_2
F_29 (
struct V_2 * V_3 ,
struct V_95 * V_96 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_8 * V_9 = V_5 -> V_10 ;
struct V_97 * V_98 = NULL ;
T_2 V_99 = V_100 ;
int error ;
if ( F_30 ( V_9 ) > 0 )
return V_101 ;
if ( ! F_31 ( V_9 , V_102 ) )
return V_103 ;
if ( F_30 ( V_9 ) > 0 ) {
V_99 = V_101 ;
goto V_104;
}
if ( V_9 -> V_93 & V_105 ) {
V_99 = V_101 ;
goto V_104;
}
if ( ! F_32 ( V_9 ) ) {
V_99 = V_106 ;
goto V_104;
}
ASSERT ( V_5 -> V_14 != 0 || F_33 ( V_9 -> V_34 ) ) ;
ASSERT ( V_5 -> V_107 == 0 || F_33 ( V_9 -> V_34 ) ) ;
F_34 ( & V_3 -> V_108 -> V_109 ) ;
error = F_35 ( V_9 , & V_98 ) ;
if ( ! error ) {
if ( ! F_36 ( V_98 , V_96 ) )
V_99 = V_106 ;
F_37 ( V_98 ) ;
}
F_38 ( & V_3 -> V_108 -> V_109 ) ;
V_104:
F_39 ( V_9 , V_102 ) ;
return V_99 ;
}
STATIC void
F_40 (
struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_8 * V_9 = V_5 -> V_10 ;
unsigned short V_110 ;
ASSERT ( V_9 -> V_111 != NULL ) ;
ASSERT ( F_21 ( V_9 , V_90 ) ) ;
V_110 = V_5 -> V_112 ;
V_5 -> V_112 = 0 ;
if ( V_110 )
F_39 ( V_9 , V_110 ) ;
}
STATIC T_3
F_41 (
struct V_2 * V_3 ,
T_3 V_113 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_8 * V_9 = V_5 -> V_10 ;
if ( F_42 ( V_9 , V_105 ) ) {
F_24 ( V_3 , 0 ) ;
return - 1 ;
}
return V_113 ;
}
STATIC void
F_43 (
struct V_2 * V_3 ,
T_3 V_113 )
{
F_1 ( V_3 ) -> V_114 = V_113 ;
}
void
F_44 (
struct V_8 * V_9 ,
struct V_115 * V_116 )
{
struct V_1 * V_5 ;
ASSERT ( V_9 -> V_111 == NULL ) ;
V_5 = V_9 -> V_111 = F_45 ( V_117 , V_118 ) ;
V_5 -> V_10 = V_9 ;
F_46 ( V_116 , & V_5 -> V_4 , V_76 ,
& V_119 ) ;
}
void
F_47 (
T_4 * V_9 )
{
F_48 ( V_117 , V_9 -> V_111 ) ;
}
void
F_49 (
struct V_97 * V_98 ,
struct V_2 * V_3 )
{
struct V_1 * V_5 ;
struct V_2 * V_120 ;
struct V_2 * V_121 ;
struct V_2 * V_122 ;
struct V_123 * V_124 = V_3 -> V_108 ;
int V_125 = 0 ;
V_120 = V_98 -> V_126 ;
V_122 = NULL ;
while ( V_120 != NULL ) {
if ( V_3 -> V_127 != F_49 ) {
V_122 = V_120 ;
V_120 = V_120 -> V_128 ;
continue;
}
V_121 = V_120 -> V_128 ;
if ( ! V_122 ) {
V_98 -> V_126 = V_121 ;
} else {
V_122 -> V_128 = V_121 ;
}
V_120 -> V_128 = V_3 -> V_128 ;
V_3 -> V_128 = V_120 ;
V_5 = F_1 ( V_120 ) ;
if ( V_5 -> V_107 && V_120 -> V_129 == V_5 -> V_130 )
V_125 ++ ;
V_120 = V_121 ;
}
V_5 = F_1 ( V_3 ) ;
if ( V_5 -> V_107 && V_3 -> V_129 == V_5 -> V_130 )
V_125 ++ ;
if ( V_125 ) {
struct V_2 * V_131 [ V_125 ] ;
int V_132 = 0 ;
F_38 ( & V_124 -> V_109 ) ;
for ( V_120 = V_3 ; V_120 ; V_120 = V_120 -> V_128 ) {
V_5 = F_1 ( V_120 ) ;
if ( V_5 -> V_107 &&
V_120 -> V_129 == V_5 -> V_130 ) {
V_131 [ V_132 ++ ] = V_120 ;
}
ASSERT ( V_132 <= V_125 ) ;
}
F_50 ( V_124 , V_131 , V_132 ,
V_133 ) ;
}
for ( V_120 = V_3 ; V_120 ; V_120 = V_121 ) {
V_121 = V_120 -> V_128 ;
V_120 -> V_128 = NULL ;
V_5 = F_1 ( V_120 ) ;
V_5 -> V_107 = 0 ;
V_5 -> V_134 = 0 ;
F_51 ( V_5 -> V_10 ) ;
}
}
void
F_52 (
T_4 * V_9 ,
bool V_135 )
{
T_5 * V_5 = V_9 -> V_111 ;
if ( V_5 ) {
struct V_123 * V_124 = V_5 -> V_4 . V_108 ;
if ( V_5 -> V_4 . V_136 & V_137 ) {
F_38 ( & V_124 -> V_109 ) ;
if ( V_5 -> V_4 . V_136 & V_137 ) {
F_53 ( V_124 , & V_5 -> V_4 ,
V_135 ?
V_138 :
V_133 ) ;
} else
F_34 ( & V_124 -> V_109 ) ;
}
V_5 -> V_107 = 0 ;
V_5 -> V_134 = 0 ;
V_5 -> V_14 = 0 ;
}
F_51 ( V_9 ) ;
}
void
F_54 (
struct V_97 * V_98 ,
struct V_2 * V_3 )
{
F_52 ( F_1 ( V_3 ) -> V_10 , true ) ;
}
int
F_55 (
T_6 * V_139 ,
T_7 * V_140 )
{
if ( V_139 -> V_141 == sizeof( V_142 ) ) {
V_142 * V_143 = V_139 -> V_144 ;
V_140 -> V_75 = V_143 -> V_75 ;
V_140 -> V_56 = V_143 -> V_56 ;
V_140 -> V_86 = V_143 -> V_86 ;
V_140 -> V_71 = V_143 -> V_71 ;
V_140 -> V_55 = V_143 -> V_55 ;
V_140 -> V_77 = V_143 -> V_77 ;
memcpy ( V_140 -> V_63 . V_67 . V_145 ,
V_143 -> V_63 . V_67 . V_145 ,
sizeof( V_146 ) ) ;
V_140 -> V_79 = V_143 -> V_79 ;
V_140 -> V_82 = V_143 -> V_82 ;
V_140 -> V_84 = V_143 -> V_84 ;
return 0 ;
} else if ( V_139 -> V_141 == sizeof( V_147 ) ) {
V_147 * V_148 = V_139 -> V_144 ;
V_140 -> V_75 = V_148 -> V_75 ;
V_140 -> V_56 = V_148 -> V_56 ;
V_140 -> V_86 = V_148 -> V_86 ;
V_140 -> V_71 = V_148 -> V_71 ;
V_140 -> V_55 = V_148 -> V_55 ;
V_140 -> V_77 = V_148 -> V_77 ;
memcpy ( V_140 -> V_63 . V_67 . V_145 ,
V_148 -> V_63 . V_67 . V_145 ,
sizeof( V_146 ) ) ;
V_140 -> V_79 = V_148 -> V_79 ;
V_140 -> V_82 = V_148 -> V_82 ;
V_140 -> V_84 = V_148 -> V_84 ;
return 0 ;
}
return V_149 ;
}
