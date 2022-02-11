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
struct V_1 * V_5 ,
struct V_32 * V_34 ,
struct V_35 * V_36 ,
struct V_37 * * V_38 )
{
struct V_8 * V_9 = V_5 -> V_10 ;
T_1 V_39 ;
switch ( V_9 -> V_11 . V_12 ) {
case V_13 :
V_5 -> V_14 &=
~ ( V_23 | V_20 |
V_40 | V_41 ) ;
if ( ( V_5 -> V_14 & V_15 ) &&
V_9 -> V_11 . V_16 > 0 &&
V_9 -> V_17 . V_18 > 0 ) {
struct V_42 * V_43 ;
ASSERT ( V_9 -> V_17 . V_44 . V_45 != NULL ) ;
ASSERT ( V_9 -> V_17 . V_18 / sizeof( V_46 ) > 0 ) ;
V_43 = F_12 ( V_36 , V_38 , V_47 ) ;
V_39 = F_13 ( V_9 , V_43 , V_48 ) ;
F_14 ( V_36 , * V_38 , V_39 ) ;
ASSERT ( V_39 <= V_9 -> V_17 . V_18 ) ;
V_34 -> V_49 = V_39 ;
V_34 -> V_50 ++ ;
} else {
V_5 -> V_14 &= ~ V_15 ;
}
break;
case V_19 :
V_5 -> V_14 &=
~ ( V_23 | V_15 |
V_40 | V_41 ) ;
if ( ( V_5 -> V_14 & V_20 ) &&
V_9 -> V_17 . V_21 > 0 ) {
ASSERT ( V_9 -> V_17 . V_51 != NULL ) ;
F_15 ( V_36 , V_38 , V_52 ,
V_9 -> V_17 . V_51 ,
V_9 -> V_17 . V_21 ) ;
V_34 -> V_49 = V_9 -> V_17 . V_21 ;
V_34 -> V_50 ++ ;
} else {
ASSERT ( ! ( V_5 -> V_14 &
V_20 ) ) ;
V_5 -> V_14 &= ~ V_20 ;
}
break;
case V_22 :
V_5 -> V_14 &=
~ ( V_15 | V_20 |
V_40 | V_41 ) ;
if ( ( V_5 -> V_14 & V_23 ) &&
V_9 -> V_17 . V_18 > 0 ) {
V_39 = F_5 ( V_9 -> V_17 . V_18 , 4 ) ;
ASSERT ( V_9 -> V_17 . V_53 == 0 ||
V_9 -> V_17 . V_53 == V_39 ) ;
ASSERT ( V_9 -> V_17 . V_44 . V_54 != NULL ) ;
ASSERT ( V_9 -> V_11 . V_55 > 0 ) ;
F_15 ( V_36 , V_38 , V_56 ,
V_9 -> V_17 . V_44 . V_54 , V_39 ) ;
V_34 -> V_49 = ( unsigned ) V_39 ;
V_34 -> V_50 ++ ;
} else {
V_5 -> V_14 &= ~ V_23 ;
}
break;
case V_24 :
V_5 -> V_14 &=
~ ( V_23 | V_20 |
V_15 | V_41 ) ;
if ( V_5 -> V_14 & V_40 )
V_34 -> V_57 . V_58 = V_9 -> V_17 . V_59 . V_60 ;
break;
case V_25 :
V_5 -> V_14 &=
~ ( V_23 | V_20 |
V_15 | V_40 ) ;
if ( V_5 -> V_14 & V_41 )
V_34 -> V_57 . V_61 = V_9 -> V_17 . V_59 . V_62 ;
break;
default:
ASSERT ( 0 ) ;
break;
}
}
STATIC void
F_16 (
struct V_1 * V_5 ,
struct V_32 * V_34 ,
struct V_35 * V_36 ,
struct V_37 * * V_38 )
{
struct V_8 * V_9 = V_5 -> V_10 ;
T_1 V_39 ;
switch ( V_9 -> V_11 . V_26 ) {
case V_13 :
V_5 -> V_14 &=
~ ( V_31 | V_30 ) ;
if ( ( V_5 -> V_14 & V_27 ) &&
V_9 -> V_11 . V_28 > 0 &&
V_9 -> V_29 -> V_18 > 0 ) {
struct V_42 * V_43 ;
ASSERT ( V_9 -> V_29 -> V_18 / sizeof( V_46 ) ==
V_9 -> V_11 . V_28 ) ;
ASSERT ( V_9 -> V_29 -> V_44 . V_45 != NULL ) ;
V_43 = F_12 ( V_36 , V_38 , V_63 ) ;
V_39 = F_13 ( V_9 , V_43 , V_64 ) ;
F_14 ( V_36 , * V_38 , V_39 ) ;
V_34 -> V_65 = V_39 ;
V_34 -> V_50 ++ ;
} else {
V_5 -> V_14 &= ~ V_27 ;
}
break;
case V_19 :
V_5 -> V_14 &=
~ ( V_31 | V_27 ) ;
if ( ( V_5 -> V_14 & V_30 ) &&
V_9 -> V_29 -> V_21 > 0 ) {
ASSERT ( V_9 -> V_29 -> V_51 != NULL ) ;
F_15 ( V_36 , V_38 , V_66 ,
V_9 -> V_29 -> V_51 ,
V_9 -> V_29 -> V_21 ) ;
V_34 -> V_65 = V_9 -> V_29 -> V_21 ;
V_34 -> V_50 ++ ;
} else {
V_5 -> V_14 &= ~ V_30 ;
}
break;
case V_22 :
V_5 -> V_14 &=
~ ( V_27 | V_30 ) ;
if ( ( V_5 -> V_14 & V_31 ) &&
V_9 -> V_29 -> V_18 > 0 ) {
V_39 = F_5 ( V_9 -> V_29 -> V_18 , 4 ) ;
ASSERT ( V_9 -> V_29 -> V_53 == 0 ||
V_9 -> V_29 -> V_53 == V_39 ) ;
ASSERT ( V_9 -> V_29 -> V_44 . V_54 != NULL ) ;
F_15 ( V_36 , V_38 , V_67 ,
V_9 -> V_29 -> V_44 . V_54 ,
V_39 ) ;
V_34 -> V_65 = ( unsigned ) V_39 ;
V_34 -> V_50 ++ ;
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
F_17 (
struct V_2 * V_3 ,
struct V_35 * V_36 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_8 * V_9 = V_5 -> V_10 ;
struct V_32 * V_34 ;
struct V_37 * V_38 = NULL ;
ASSERT ( V_9 -> V_11 . V_33 > 1 ) ;
V_34 = F_12 ( V_36 , & V_38 , V_68 ) ;
V_34 -> V_69 = V_70 ;
V_34 -> V_71 = V_9 -> V_72 ;
V_34 -> V_73 = V_9 -> V_74 . V_75 ;
V_34 -> V_76 = V_9 -> V_74 . V_77 ;
V_34 -> V_78 = V_9 -> V_74 . V_79 ;
V_34 -> V_80 = V_81 ;
V_34 -> V_50 = 2 ;
F_14 ( V_36 , V_38 , sizeof( struct V_32 ) ) ;
F_15 ( V_36 , & V_38 , V_82 ,
& V_9 -> V_11 ,
F_9 ( V_9 -> V_11 . V_33 ) ) ;
F_11 ( V_5 , V_34 , V_36 , & V_38 ) ;
if ( F_10 ( V_9 ) ) {
F_16 ( V_5 , V_34 , V_36 , & V_38 ) ;
} else {
V_5 -> V_14 &=
~ ( V_31 | V_30 | V_27 ) ;
}
V_34 -> V_80 |= ( V_5 -> V_14 & ~ V_83 ) ;
}
STATIC void
F_18 (
struct V_2 * V_3 )
{
struct V_8 * V_9 = F_1 ( V_3 ) -> V_10 ;
ASSERT ( F_19 ( V_9 , V_84 ) ) ;
F_20 ( V_9 , V_85 ) ;
F_21 ( & V_9 -> V_86 ) ;
}
STATIC void
F_22 (
struct V_2 * V_3 ,
int remove )
{
struct V_8 * V_9 = F_1 ( V_3 ) -> V_10 ;
F_23 ( V_9 , V_85 ) ;
ASSERT ( F_24 ( & V_9 -> V_86 ) > 0 ) ;
if ( F_25 ( & V_9 -> V_86 ) )
F_26 ( & V_9 -> V_87 , V_88 ) ;
}
STATIC T_2
F_27 (
struct V_2 * V_3 ,
struct V_89 * V_90 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_8 * V_9 = V_5 -> V_10 ;
struct V_91 * V_92 = NULL ;
T_2 V_93 = V_94 ;
int error ;
if ( F_28 ( V_9 ) > 0 )
return V_95 ;
if ( ! F_29 ( V_9 , V_96 ) )
return V_97 ;
if ( F_28 ( V_9 ) > 0 ) {
V_93 = V_95 ;
goto V_98;
}
if ( V_9 -> V_87 & V_99 ) {
V_93 = V_95 ;
goto V_98;
}
if ( ! F_30 ( V_9 ) ) {
V_93 = V_100 ;
goto V_98;
}
ASSERT ( V_5 -> V_14 != 0 || F_31 ( V_9 -> V_101 ) ) ;
ASSERT ( V_5 -> V_102 == 0 || F_31 ( V_9 -> V_101 ) ) ;
F_32 ( & V_3 -> V_103 -> V_104 ) ;
error = F_33 ( V_9 , & V_92 ) ;
if ( ! error ) {
if ( ! F_34 ( V_92 , V_90 ) )
V_93 = V_100 ;
F_35 ( V_92 ) ;
}
F_36 ( & V_3 -> V_103 -> V_104 ) ;
V_98:
F_37 ( V_9 , V_96 ) ;
return V_93 ;
}
STATIC void
F_38 (
struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_8 * V_9 = V_5 -> V_10 ;
unsigned short V_105 ;
ASSERT ( V_9 -> V_106 != NULL ) ;
ASSERT ( F_19 ( V_9 , V_84 ) ) ;
V_105 = V_5 -> V_107 ;
V_5 -> V_107 = 0 ;
if ( V_105 )
F_37 ( V_9 , V_105 ) ;
}
STATIC T_3
F_39 (
struct V_2 * V_3 ,
T_3 V_108 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_8 * V_9 = V_5 -> V_10 ;
if ( F_40 ( V_9 , V_99 ) ) {
F_22 ( V_3 , 0 ) ;
return - 1 ;
}
return V_108 ;
}
STATIC void
F_41 (
struct V_2 * V_3 ,
T_3 V_108 )
{
F_1 ( V_3 ) -> V_109 = V_108 ;
}
void
F_42 (
struct V_8 * V_9 ,
struct V_110 * V_111 )
{
struct V_1 * V_5 ;
ASSERT ( V_9 -> V_106 == NULL ) ;
V_5 = V_9 -> V_106 = F_43 ( V_112 , V_113 ) ;
V_5 -> V_10 = V_9 ;
F_44 ( V_111 , & V_5 -> V_4 , V_70 ,
& V_114 ) ;
}
void
F_45 (
T_4 * V_9 )
{
F_46 ( V_112 , V_9 -> V_106 ) ;
}
void
F_47 (
struct V_91 * V_92 ,
struct V_2 * V_3 )
{
struct V_1 * V_5 ;
struct V_2 * V_115 ;
struct V_2 * V_116 ;
struct V_2 * V_117 ;
struct V_118 * V_119 = V_3 -> V_103 ;
int V_120 = 0 ;
V_115 = V_92 -> V_121 ;
V_117 = NULL ;
while ( V_115 != NULL ) {
if ( V_115 -> V_122 != F_47 ) {
V_117 = V_115 ;
V_115 = V_115 -> V_123 ;
continue;
}
V_116 = V_115 -> V_123 ;
if ( ! V_117 ) {
V_92 -> V_121 = V_116 ;
} else {
V_117 -> V_123 = V_116 ;
}
V_115 -> V_123 = V_3 -> V_123 ;
V_3 -> V_123 = V_115 ;
V_5 = F_1 ( V_115 ) ;
if ( V_5 -> V_102 && V_115 -> V_124 == V_5 -> V_125 )
V_120 ++ ;
V_115 = V_116 ;
}
V_5 = F_1 ( V_3 ) ;
if ( V_5 -> V_102 && V_3 -> V_124 == V_5 -> V_125 )
V_120 ++ ;
if ( V_120 ) {
struct V_2 * V_126 [ V_120 ] ;
int V_127 = 0 ;
F_36 ( & V_119 -> V_104 ) ;
for ( V_115 = V_3 ; V_115 ; V_115 = V_115 -> V_123 ) {
V_5 = F_1 ( V_115 ) ;
if ( V_5 -> V_102 &&
V_115 -> V_124 == V_5 -> V_125 ) {
V_126 [ V_127 ++ ] = V_115 ;
}
ASSERT ( V_127 <= V_120 ) ;
}
F_48 ( V_119 , V_126 , V_127 ,
V_128 ) ;
}
for ( V_115 = V_3 ; V_115 ; V_115 = V_116 ) {
V_116 = V_115 -> V_123 ;
V_115 -> V_123 = NULL ;
V_5 = F_1 ( V_115 ) ;
V_5 -> V_102 = 0 ;
V_5 -> V_129 = 0 ;
F_49 ( V_5 -> V_10 ) ;
}
}
void
F_50 (
T_4 * V_9 ,
bool V_130 )
{
T_5 * V_5 = V_9 -> V_106 ;
if ( V_5 ) {
if ( V_5 -> V_4 . V_131 & V_132 ) {
F_51 ( & V_5 -> V_4 ,
V_130 ? V_133 :
V_128 ) ;
}
V_5 -> V_102 = 0 ;
V_5 -> V_129 = 0 ;
V_5 -> V_14 = 0 ;
V_5 -> V_134 = 0 ;
}
F_49 ( V_9 ) ;
}
void
F_52 (
struct V_91 * V_92 ,
struct V_2 * V_3 )
{
F_50 ( F_1 ( V_3 ) -> V_10 , true ) ;
}
int
F_53 (
T_6 * V_135 ,
T_7 * V_136 )
{
if ( V_135 -> V_137 == sizeof( V_138 ) ) {
V_138 * V_139 = V_135 -> V_140 ;
V_136 -> V_69 = V_139 -> V_69 ;
V_136 -> V_50 = V_139 -> V_50 ;
V_136 -> V_80 = V_139 -> V_80 ;
V_136 -> V_65 = V_139 -> V_65 ;
V_136 -> V_49 = V_139 -> V_49 ;
V_136 -> V_71 = V_139 -> V_71 ;
memcpy ( V_136 -> V_57 . V_61 . V_141 ,
V_139 -> V_57 . V_61 . V_141 ,
sizeof( V_142 ) ) ;
V_136 -> V_73 = V_139 -> V_73 ;
V_136 -> V_76 = V_139 -> V_76 ;
V_136 -> V_78 = V_139 -> V_78 ;
return 0 ;
} else if ( V_135 -> V_137 == sizeof( V_143 ) ) {
V_143 * V_144 = V_135 -> V_140 ;
V_136 -> V_69 = V_144 -> V_69 ;
V_136 -> V_50 = V_144 -> V_50 ;
V_136 -> V_80 = V_144 -> V_80 ;
V_136 -> V_65 = V_144 -> V_65 ;
V_136 -> V_49 = V_144 -> V_49 ;
V_136 -> V_71 = V_144 -> V_71 ;
memcpy ( V_136 -> V_57 . V_61 . V_141 ,
V_144 -> V_57 . V_61 . V_141 ,
sizeof( V_142 ) ) ;
V_136 -> V_73 = V_144 -> V_73 ;
V_136 -> V_76 = V_144 -> V_76 ;
V_136 -> V_78 = V_144 -> V_78 ;
return 0 ;
}
return - V_145 ;
}
