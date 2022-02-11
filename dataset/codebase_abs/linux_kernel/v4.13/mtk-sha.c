static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline void F_5 ( struct V_6 * V_7 ,
struct V_8 * * V_9 ,
struct V_8 * * V_10 ,
int * V_11 )
{
* V_9 = V_7 -> V_12 ++ ;
* V_10 = V_7 -> V_13 ++ ;
( * V_11 ) ++ ;
if ( V_7 -> V_12 == V_7 -> V_14 + V_15 ) {
V_7 -> V_12 = V_7 -> V_14 ;
V_7 -> V_13 = V_7 -> V_16 ;
}
}
static struct V_1 * F_6 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = NULL ;
struct V_1 * V_19 ;
F_7 ( & V_20 . V_21 ) ;
if ( ! V_18 -> V_2 ) {
F_8 (tmp, &mtk_sha.dev_list, sha_list) {
V_2 = V_19 ;
break;
}
V_18 -> V_2 = V_2 ;
} else {
V_2 = V_18 -> V_2 ;
}
V_18 -> V_22 = V_2 -> V_23 ;
V_2 -> V_23 = ! V_2 -> V_23 ;
F_9 ( & V_20 . V_21 ) ;
return V_2 ;
}
static int F_10 ( struct V_24 * V_25 )
{
T_2 V_11 ;
while ( ( V_25 -> V_26 < V_27 ) && V_25 -> V_28 ) {
V_11 = F_11 ( V_25 -> V_29 -> V_30 - V_25 -> V_3 , V_25 -> V_28 ) ;
V_11 = F_11 ( V_11 , V_27 - V_25 -> V_26 ) ;
if ( V_11 <= 0 ) {
if ( ( V_25 -> V_29 -> V_30 == 0 ) && ! F_12 ( V_25 -> V_29 ) ) {
V_25 -> V_29 = F_13 ( V_25 -> V_29 ) ;
continue;
} else {
break;
}
}
F_14 ( V_25 -> V_31 + V_25 -> V_26 , V_25 -> V_29 ,
V_25 -> V_3 , V_11 , 0 ) ;
V_25 -> V_26 += V_11 ;
V_25 -> V_3 += V_11 ;
V_25 -> V_28 -= V_11 ;
if ( V_25 -> V_3 == V_25 -> V_29 -> V_30 ) {
V_25 -> V_29 = F_13 ( V_25 -> V_29 ) ;
if ( V_25 -> V_29 )
V_25 -> V_3 = 0 ;
else
V_25 -> V_28 = 0 ;
}
}
return 0 ;
}
static void F_15 ( struct V_24 * V_25 , T_1 V_32 )
{
T_1 V_33 , V_34 ;
T_3 V_35 [ 2 ] ;
T_3 V_36 = V_25 -> V_37 ;
V_36 += V_25 -> V_26 ;
V_36 += V_32 ;
V_35 [ 1 ] = F_16 ( V_36 << 3 ) ;
V_35 [ 0 ] = F_16 ( V_36 >> 61 ) ;
switch ( V_25 -> V_38 & V_39 ) {
case V_40 :
case V_41 :
V_33 = V_25 -> V_26 & 0x7f ;
V_34 = ( V_33 < 112 ) ? ( 112 - V_33 ) : ( ( 128 + 112 ) - V_33 ) ;
* ( V_25 -> V_31 + V_25 -> V_26 ) = 0x80 ;
memset ( V_25 -> V_31 + V_25 -> V_26 + 1 , 0 , V_34 - 1 ) ;
memcpy ( V_25 -> V_31 + V_25 -> V_26 + V_34 , V_35 , 16 ) ;
V_25 -> V_26 += V_34 + 16 ;
V_25 -> V_38 |= V_42 ;
break;
default:
V_33 = V_25 -> V_26 & 0x3f ;
V_34 = ( V_33 < 56 ) ? ( 56 - V_33 ) : ( ( 64 + 56 ) - V_33 ) ;
* ( V_25 -> V_31 + V_25 -> V_26 ) = 0x80 ;
memset ( V_25 -> V_31 + V_25 -> V_26 + 1 , 0 , V_34 - 1 ) ;
memcpy ( V_25 -> V_31 + V_25 -> V_26 + V_34 , & V_35 [ 1 ] , 8 ) ;
V_25 -> V_26 += V_34 + 8 ;
V_25 -> V_38 |= V_42 ;
break;
}
}
static void F_17 ( struct V_24 * V_25 )
{
struct V_43 * V_44 = & V_25 -> V_44 ;
V_25 -> V_45 = V_46 ;
V_25 -> V_47 = V_48 ;
V_44 -> V_49 [ 0 ] = V_50 | F_18 ( F_19 ( V_25 -> V_51 ) ) ;
switch ( V_25 -> V_38 & V_39 ) {
case V_52 :
V_44 -> V_49 [ 0 ] |= V_53 ;
break;
case V_54 :
V_44 -> V_49 [ 0 ] |= V_55 ;
break;
case V_56 :
V_44 -> V_49 [ 0 ] |= V_57 ;
break;
case V_40 :
V_44 -> V_49 [ 0 ] |= V_58 ;
break;
case V_41 :
V_44 -> V_49 [ 0 ] |= V_59 ;
break;
default:
return;
}
V_44 -> V_49 [ 1 ] = V_60 ;
V_44 -> V_61 [ 0 ] = V_44 -> V_49 [ 0 ] | V_62 | V_63 ;
V_44 -> V_61 [ 1 ] = V_44 -> V_49 [ 1 ] ;
V_44 -> V_64 [ 0 ] = V_65 ;
V_44 -> V_64 [ 1 ] = V_66 ;
V_44 -> V_64 [ 2 ] = V_67 | F_20 ( F_19 ( V_25 -> V_51 ) ) ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_68 * V_69 ,
T_2 V_70 , T_2 V_71 )
{
struct V_24 * V_25 = F_22 ( V_69 -> V_72 ) ;
struct V_43 * V_44 = & V_25 -> V_44 ;
V_25 -> V_45 &= ~ V_73 ;
V_25 -> V_45 |= F_23 ( V_70 + V_71 ) ;
V_44 -> V_64 [ 0 ] &= ~ V_73 ;
V_44 -> V_64 [ 0 ] |= F_23 ( V_70 + V_71 ) ;
if ( V_25 -> V_37 )
V_44 -> V_61 [ 0 ] &= ~ V_63 ;
V_25 -> V_37 += V_70 ;
V_25 -> V_74 = F_24 ( V_2 -> V_75 , V_44 , sizeof( * V_44 ) ,
V_76 ) ;
if ( F_25 ( F_26 ( V_2 -> V_75 , V_25 -> V_74 ) ) ) {
F_27 ( V_2 -> V_75 , L_1 , sizeof( * V_44 ) ) ;
return - V_77 ;
}
V_25 -> V_78 = V_25 -> V_74 + sizeof( V_44 -> V_61 ) + sizeof( V_44 -> V_64 ) ;
return 0 ;
}
static int F_28 ( struct V_79 * V_72 )
{
struct V_17 * V_18 = F_29 ( V_72 -> V_4 . V_49 ) ;
struct V_80 * V_81 = V_18 -> V_4 ;
struct V_24 * V_25 = F_22 ( V_72 ) ;
F_30 ( V_82 , V_81 -> V_82 ) ;
V_82 -> V_49 = V_81 -> V_82 ;
V_82 -> V_38 = 0 ;
return F_31 ( V_82 ) ? :
F_32 ( V_82 , V_81 -> V_83 , V_25 -> V_84 ) ? :
F_33 ( V_82 , V_72 -> V_85 , V_25 -> V_51 , V_72 -> V_85 ) ;
}
static int F_34 ( struct V_79 * V_72 )
{
struct V_86 * V_49 = F_35 ( V_72 ) ;
struct V_17 * V_18 = F_36 ( V_49 ) ;
struct V_24 * V_25 = F_22 ( V_72 ) ;
V_25 -> V_38 = 0 ;
V_25 -> V_51 = F_37 ( V_49 ) ;
switch ( V_25 -> V_51 ) {
case V_87 :
V_25 -> V_38 |= V_52 ;
V_25 -> V_84 = V_88 ;
break;
case V_89 :
V_25 -> V_38 |= V_54 ;
V_25 -> V_84 = V_90 ;
break;
case V_91 :
V_25 -> V_38 |= V_56 ;
V_25 -> V_84 = V_92 ;
break;
case V_93 :
V_25 -> V_38 |= V_40 ;
V_25 -> V_84 = V_94 ;
break;
case V_95 :
V_25 -> V_38 |= V_41 ;
V_25 -> V_84 = V_96 ;
break;
default:
return - V_77 ;
}
V_25 -> V_26 = 0 ;
V_25 -> V_37 = 0 ;
V_25 -> V_31 = V_18 -> V_97 ;
if ( V_18 -> V_38 & V_98 ) {
struct V_80 * V_81 = V_18 -> V_4 ;
memcpy ( V_25 -> V_31 , V_81 -> V_99 , V_25 -> V_84 ) ;
V_25 -> V_26 = V_25 -> V_84 ;
V_25 -> V_38 |= V_98 ;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 , struct V_68 * V_69 ,
T_4 V_100 , T_2 V_70 ,
T_4 V_101 , T_2 V_71 )
{
struct V_24 * V_25 = F_22 ( V_69 -> V_72 ) ;
struct V_6 * V_7 = V_2 -> V_7 [ V_69 -> V_22 ] ;
struct V_8 * V_64 , * V_102 ;
int V_103 , V_11 = 0 ;
V_103 = F_21 ( V_2 , V_69 , V_70 , V_71 ) ;
if ( V_103 )
return V_103 ;
F_5 ( V_7 , & V_64 , & V_102 , & V_11 ) ;
V_102 -> V_104 = V_105 | F_39 ( V_70 ) ;
V_64 -> V_104 = V_105 | F_39 ( V_70 ) |
F_40 ( V_25 -> V_47 ) ;
V_64 -> V_97 = F_23 ( V_100 ) ;
V_64 -> V_106 = F_23 ( V_25 -> V_74 ) ;
V_64 -> V_45 = V_25 -> V_45 ;
V_64 -> V_49 = F_23 ( V_25 -> V_78 ) ;
if ( V_71 ) {
F_5 ( V_7 , & V_64 , & V_102 , & V_11 ) ;
V_102 -> V_104 = F_39 ( V_71 ) ;
V_64 -> V_104 = F_39 ( V_71 ) ;
V_64 -> V_97 = F_23 ( V_101 ) ;
}
V_64 -> V_104 |= V_107 ;
V_102 -> V_104 |= V_107 ;
F_41 () ;
F_3 ( V_2 , F_42 ( V_69 -> V_22 ) , F_43 ( V_11 ) ) ;
F_3 ( V_2 , F_44 ( V_69 -> V_22 ) , F_43 ( V_11 ) ) ;
return - V_108 ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_68 * V_69 ,
struct V_24 * V_25 ,
T_2 V_11 )
{
V_25 -> V_109 = F_24 ( V_2 -> V_75 , V_25 -> V_31 ,
V_27 , V_110 ) ;
if ( F_25 ( F_26 ( V_2 -> V_75 , V_25 -> V_109 ) ) ) {
F_27 ( V_2 -> V_75 , L_2 ) ;
return - V_77 ;
}
V_25 -> V_38 &= ~ V_111 ;
return F_38 ( V_2 , V_69 , V_25 -> V_109 , V_11 , 0 , 0 ) ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_68 * V_69 )
{
struct V_24 * V_25 = F_22 ( V_69 -> V_72 ) ;
T_2 V_11 ;
T_1 V_112 ;
F_10 ( V_25 ) ;
V_112 = ( V_25 -> V_38 & V_113 ) && ! V_25 -> V_28 ;
F_47 ( V_2 -> V_75 , L_3 , V_25 -> V_26 ) ;
if ( V_112 ) {
V_69 -> V_38 |= V_114 ;
F_15 ( V_25 , 0 ) ;
}
if ( V_112 || ( V_25 -> V_26 == V_27 && V_25 -> V_28 ) ) {
V_11 = V_25 -> V_26 ;
V_25 -> V_26 = 0 ;
return F_45 ( V_2 , V_69 , V_25 , V_11 ) ;
}
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_68 * V_69 )
{
struct V_24 * V_25 = F_22 ( V_69 -> V_72 ) ;
T_1 V_32 , V_112 , V_115 ;
struct V_116 * V_29 ;
if ( ! V_25 -> V_28 )
return 0 ;
if ( V_25 -> V_26 || V_25 -> V_3 )
return F_46 ( V_2 , V_69 ) ;
V_29 = V_25 -> V_29 ;
if ( ! F_49 ( V_29 -> V_3 , sizeof( T_1 ) ) )
return F_46 ( V_2 , V_69 ) ;
if ( ! F_12 ( V_29 ) && ! F_49 ( V_29 -> V_30 , V_25 -> V_84 ) )
return F_46 ( V_2 , V_69 ) ;
V_32 = F_11 ( V_25 -> V_28 , V_29 -> V_30 ) ;
if ( F_12 ( V_29 ) ) {
if ( ! ( V_25 -> V_38 & V_113 ) ) {
V_115 = V_32 & ( V_25 -> V_84 - 1 ) ;
V_32 -= V_115 ;
}
}
V_25 -> V_28 -= V_32 ;
V_25 -> V_3 = V_32 ;
V_112 = ( V_25 -> V_38 & V_113 ) && ! V_25 -> V_28 ;
if ( V_112 ) {
T_2 V_11 ;
V_115 = V_32 & ( V_25 -> V_84 - 1 ) ;
V_32 -= V_115 ;
V_25 -> V_28 += V_115 ;
V_25 -> V_3 = V_32 ;
V_29 = V_25 -> V_29 ;
F_10 ( V_25 ) ;
F_15 ( V_25 , V_32 ) ;
V_25 -> V_109 = F_24 ( V_2 -> V_75 , V_25 -> V_31 ,
V_27 , V_110 ) ;
if ( F_25 ( F_26 ( V_2 -> V_75 , V_25 -> V_109 ) ) ) {
F_27 ( V_2 -> V_75 , L_4 ) ;
return - V_77 ;
}
V_69 -> V_38 |= V_114 ;
V_11 = V_25 -> V_26 ;
V_25 -> V_26 = 0 ;
if ( V_32 == 0 ) {
V_25 -> V_38 &= ~ V_111 ;
return F_38 ( V_2 , V_69 , V_25 -> V_109 ,
V_11 , 0 , 0 ) ;
} else {
V_25 -> V_29 = V_29 ;
if ( ! F_50 ( V_2 -> V_75 , V_25 -> V_29 , 1 , V_110 ) ) {
F_27 ( V_2 -> V_75 , L_5 ) ;
return - V_77 ;
}
V_25 -> V_38 |= V_111 ;
return F_38 ( V_2 , V_69 , F_51 ( V_25 -> V_29 ) ,
V_32 , V_25 -> V_109 , V_11 ) ;
}
}
if ( ! F_50 ( V_2 -> V_75 , V_25 -> V_29 , 1 , V_110 ) ) {
F_27 ( V_2 -> V_75 , L_6 ) ;
return - V_77 ;
}
V_25 -> V_38 |= V_111 ;
return F_38 ( V_2 , V_69 , F_51 ( V_25 -> V_29 ) ,
V_32 , 0 , 0 ) ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_68 * V_69 )
{
struct V_24 * V_25 = F_22 ( V_69 -> V_72 ) ;
T_2 V_11 ;
F_15 ( V_25 , 0 ) ;
V_69 -> V_38 |= V_114 ;
V_11 = V_25 -> V_26 ;
V_25 -> V_26 = 0 ;
return F_45 ( V_2 , V_69 , V_25 , V_11 ) ;
}
static int F_53 ( struct V_79 * V_72 )
{
struct V_24 * V_25 = F_22 ( V_72 ) ;
T_5 * V_117 = V_25 -> V_44 . V_117 ;
T_1 * V_85 = ( T_1 * ) V_72 -> V_85 ;
int V_118 ;
for ( V_118 = 0 ; V_118 < F_19 ( V_25 -> V_51 ) ; V_118 ++ )
V_85 [ V_118 ] = F_54 ( V_117 [ V_118 ] ) ;
if ( V_25 -> V_38 & V_98 )
return F_28 ( V_72 ) ;
return 0 ;
}
static void F_55 ( struct V_1 * V_2 ,
struct V_68 * V_69 ,
int V_103 )
{
if ( F_56 ( ! V_103 && ( V_114 & V_69 -> V_38 ) ) )
V_103 = F_53 ( V_69 -> V_72 ) ;
V_69 -> V_38 &= ~ ( V_119 | V_114 ) ;
V_69 -> V_72 -> V_4 . V_120 ( & V_69 -> V_72 -> V_4 , V_103 ) ;
F_57 ( & V_69 -> V_121 ) ;
}
static int F_58 ( struct V_1 * V_2 , T_6 V_22 ,
struct V_79 * V_72 )
{
struct V_68 * V_69 = V_2 -> V_69 [ V_22 ] ;
struct V_122 * V_123 , * V_124 ;
struct V_24 * V_25 ;
unsigned long V_38 ;
int V_103 = 0 , V_125 = 0 ;
F_59 ( & V_69 -> V_21 , V_38 ) ;
if ( V_72 )
V_125 = F_60 ( & V_69 -> V_126 , V_72 ) ;
if ( V_119 & V_69 -> V_38 ) {
F_61 ( & V_69 -> V_21 , V_38 ) ;
return V_125 ;
}
V_124 = F_62 ( & V_69 -> V_126 ) ;
V_123 = F_63 ( & V_69 -> V_126 ) ;
if ( V_123 )
V_69 -> V_38 |= V_119 ;
F_61 ( & V_69 -> V_21 , V_38 ) ;
if ( ! V_123 )
return V_125 ;
if ( V_124 )
V_124 -> V_120 ( V_124 , - V_108 ) ;
V_72 = F_64 ( V_123 ) ;
V_25 = F_22 ( V_72 ) ;
V_69 -> V_72 = V_72 ;
F_17 ( V_25 ) ;
if ( V_25 -> V_127 == V_128 ) {
V_103 = F_48 ( V_2 , V_69 ) ;
if ( V_103 != - V_108 && ( V_25 -> V_38 & V_113 ) )
V_103 = F_52 ( V_2 , V_69 ) ;
} else if ( V_25 -> V_127 == V_129 ) {
V_103 = F_52 ( V_2 , V_69 ) ;
}
if ( F_25 ( V_103 != - V_108 ) )
F_55 ( V_2 , V_69 , V_103 ) ;
return V_125 ;
}
static int F_65 ( struct V_79 * V_72 , T_1 V_127 )
{
struct V_24 * V_25 = F_22 ( V_72 ) ;
struct V_17 * V_18 = F_29 ( V_72 -> V_4 . V_49 ) ;
V_25 -> V_127 = V_127 ;
return F_58 ( V_18 -> V_2 , V_18 -> V_22 , V_72 ) ;
}
static void F_66 ( struct V_1 * V_2 , struct V_68 * V_69 )
{
struct V_24 * V_25 = F_22 ( V_69 -> V_72 ) ;
F_67 ( V_2 -> V_75 , V_25 -> V_74 , sizeof( V_25 -> V_44 ) ,
V_76 ) ;
if ( V_25 -> V_38 & V_111 ) {
F_68 ( V_2 -> V_75 , V_25 -> V_29 , 1 , V_110 ) ;
if ( V_25 -> V_29 -> V_30 == V_25 -> V_3 ) {
V_25 -> V_29 = F_13 ( V_25 -> V_29 ) ;
if ( V_25 -> V_29 )
V_25 -> V_3 = 0 ;
}
if ( V_25 -> V_38 & V_42 ) {
F_67 ( V_2 -> V_75 , V_25 -> V_109 ,
V_27 , V_110 ) ;
}
} else
F_67 ( V_2 -> V_75 , V_25 -> V_109 ,
V_27 , V_110 ) ;
}
static void F_69 ( struct V_1 * V_2 ,
struct V_68 * V_69 )
{
int V_103 = 0 ;
V_103 = F_48 ( V_2 , V_69 ) ;
if ( V_103 != - V_108 )
F_55 ( V_2 , V_69 , V_103 ) ;
}
static int F_70 ( struct V_79 * V_72 )
{
struct V_24 * V_25 = F_22 ( V_72 ) ;
V_25 -> V_28 = V_72 -> V_130 ;
V_25 -> V_29 = V_72 -> V_131 ;
V_25 -> V_3 = 0 ;
if ( ( V_25 -> V_26 + V_25 -> V_28 < V_27 ) &&
! ( V_25 -> V_38 & V_113 ) )
return F_10 ( V_25 ) ;
return F_65 ( V_72 , V_128 ) ;
}
static int F_71 ( struct V_79 * V_72 )
{
struct V_24 * V_25 = F_22 ( V_72 ) ;
V_25 -> V_38 |= V_113 ;
if ( V_25 -> V_38 & V_42 )
return F_53 ( V_72 ) ;
return F_65 ( V_72 , V_129 ) ;
}
static int F_72 ( struct V_79 * V_72 )
{
struct V_24 * V_25 = F_22 ( V_72 ) ;
int V_132 , V_133 ;
V_25 -> V_38 |= V_113 ;
V_132 = F_70 ( V_72 ) ;
if ( V_132 == - V_108 || V_132 == - V_134 )
return V_132 ;
V_133 = F_71 ( V_72 ) ;
return V_132 ? : V_133 ;
}
static int F_73 ( struct V_79 * V_72 )
{
return F_34 ( V_72 ) ? : F_72 ( V_72 ) ;
}
static int F_74 ( struct V_86 * V_49 , const T_6 * V_135 ,
T_1 V_136 )
{
struct V_17 * V_18 = F_36 ( V_49 ) ;
struct V_80 * V_81 = V_18 -> V_4 ;
T_2 V_84 = F_75 ( V_81 -> V_82 ) ;
T_2 V_51 = F_76 ( V_81 -> V_82 ) ;
int V_103 , V_118 ;
F_30 ( V_82 , V_81 -> V_82 ) ;
V_82 -> V_49 = V_81 -> V_82 ;
V_82 -> V_38 = F_77 ( V_81 -> V_82 ) &
V_137 ;
if ( V_136 > V_84 ) {
V_103 = F_78 ( V_82 , V_135 , V_136 , V_81 -> V_99 ) ;
if ( V_103 )
return V_103 ;
V_136 = V_51 ;
} else {
memcpy ( V_81 -> V_99 , V_135 , V_136 ) ;
}
memset ( V_81 -> V_99 + V_136 , 0 , V_84 - V_136 ) ;
memcpy ( V_81 -> V_83 , V_81 -> V_99 , V_84 ) ;
for ( V_118 = 0 ; V_118 < V_84 ; V_118 ++ ) {
V_81 -> V_99 [ V_118 ] ^= V_138 ;
V_81 -> V_83 [ V_118 ] ^= V_139 ;
}
return 0 ;
}
static int F_79 ( struct V_79 * V_72 , void * V_140 )
{
const struct V_24 * V_25 = F_22 ( V_72 ) ;
memcpy ( V_140 , V_25 , sizeof( * V_25 ) ) ;
return 0 ;
}
static int F_80 ( struct V_79 * V_72 , const void * V_141 )
{
struct V_24 * V_25 = F_22 ( V_72 ) ;
memcpy ( V_25 , V_141 , sizeof( * V_25 ) ) ;
return 0 ;
}
static int F_81 ( struct V_142 * V_49 ,
const char * V_143 )
{
struct V_17 * V_18 = F_29 ( V_49 ) ;
struct V_1 * V_2 = NULL ;
V_2 = F_6 ( V_18 ) ;
if ( ! V_2 )
return - V_144 ;
F_82 ( F_83 ( V_49 ) ,
sizeof( struct V_24 ) ) ;
if ( V_143 ) {
struct V_80 * V_81 = V_18 -> V_4 ;
V_18 -> V_38 |= V_98 ;
V_81 -> V_82 = F_84 ( V_143 , 0 ,
V_145 ) ;
if ( F_85 ( V_81 -> V_82 ) ) {
F_86 ( L_7 ,
V_143 ) ;
return F_87 ( V_81 -> V_82 ) ;
}
}
return 0 ;
}
static int F_88 ( struct V_142 * V_49 )
{
return F_81 ( V_49 , NULL ) ;
}
static int F_89 ( struct V_142 * V_49 )
{
return F_81 ( V_49 , L_8 ) ;
}
static int F_90 ( struct V_142 * V_49 )
{
return F_81 ( V_49 , L_9 ) ;
}
static int F_91 ( struct V_142 * V_49 )
{
return F_81 ( V_49 , L_10 ) ;
}
static int F_92 ( struct V_142 * V_49 )
{
return F_81 ( V_49 , L_11 ) ;
}
static int F_93 ( struct V_142 * V_49 )
{
return F_81 ( V_49 , L_12 ) ;
}
static void F_94 ( struct V_142 * V_49 )
{
struct V_17 * V_18 = F_29 ( V_49 ) ;
if ( V_18 -> V_38 & V_98 ) {
struct V_80 * V_81 = V_18 -> V_4 ;
F_95 ( V_81 -> V_82 ) ;
}
}
static void F_96 ( unsigned long V_146 )
{
struct V_68 * V_69 = (struct V_68 * ) V_146 ;
F_58 ( V_69 -> V_2 , V_69 -> V_22 - V_147 , NULL ) ;
}
static void F_97 ( unsigned long V_146 )
{
struct V_68 * V_69 = (struct V_68 * ) V_146 ;
struct V_1 * V_2 = V_69 -> V_2 ;
F_66 ( V_2 , V_69 ) ;
F_69 ( V_2 , V_69 ) ;
}
static T_7 F_98 ( int V_148 , void * V_149 )
{
struct V_68 * V_69 = (struct V_68 * ) V_149 ;
struct V_1 * V_2 = V_69 -> V_2 ;
T_1 V_150 = F_1 ( V_2 , F_99 ( V_69 -> V_22 ) ) ;
F_3 ( V_2 , F_99 ( V_69 -> V_22 ) , V_150 ) ;
if ( F_56 ( ( V_119 & V_69 -> V_38 ) ) ) {
F_3 ( V_2 , F_100 ( V_69 -> V_22 ) , V_151 ) ;
F_3 ( V_2 , F_101 ( V_69 -> V_22 ) ,
V_152 | V_153 ) ;
F_57 ( & V_69 -> V_154 ) ;
} else {
F_102 ( V_2 -> V_75 , L_13 ) ;
}
return V_155 ;
}
static int F_103 ( struct V_1 * V_2 )
{
struct V_68 * * V_69 = V_2 -> V_69 ;
int V_118 , V_103 = - V_156 ;
for ( V_118 = 0 ; V_118 < V_157 ; V_118 ++ ) {
V_69 [ V_118 ] = F_104 ( sizeof( * * V_69 ) , V_158 ) ;
if ( ! V_69 [ V_118 ] )
goto V_159;
V_69 [ V_118 ] -> V_2 = V_2 ;
F_105 ( & V_69 [ V_118 ] -> V_21 ) ;
F_106 ( & V_69 [ V_118 ] -> V_126 , V_160 ) ;
F_107 ( & V_69 [ V_118 ] -> V_121 , F_96 ,
( unsigned long ) V_69 [ V_118 ] ) ;
F_107 ( & V_69 [ V_118 ] -> V_154 , F_97 ,
( unsigned long ) V_69 [ V_118 ] ) ;
}
V_69 [ 0 ] -> V_22 = V_147 ;
V_69 [ 1 ] -> V_22 = V_161 ;
V_2 -> V_23 = 1 ;
return 0 ;
V_159:
for (; V_118 -- ; )
F_108 ( V_69 [ V_118 ] ) ;
return V_103 ;
}
static void F_109 ( struct V_1 * V_2 )
{
int V_118 ;
for ( V_118 = 0 ; V_118 < V_157 ; V_118 ++ ) {
F_110 ( & V_2 -> V_69 [ V_118 ] -> V_154 ) ;
F_110 ( & V_2 -> V_69 [ V_118 ] -> V_121 ) ;
F_108 ( V_2 -> V_69 [ V_118 ] ) ;
}
}
static void F_111 ( void )
{
int V_118 ;
for ( V_118 = 0 ; V_118 < F_112 ( V_162 ) ; V_118 ++ )
F_113 ( & V_162 [ V_118 ] ) ;
for ( V_118 = 0 ; V_118 < F_112 ( V_163 ) ; V_118 ++ )
F_113 ( & V_163 [ V_118 ] ) ;
}
static int F_114 ( void )
{
int V_103 , V_118 ;
for ( V_118 = 0 ; V_118 < F_112 ( V_162 ) ; V_118 ++ ) {
V_103 = F_115 ( & V_162 [ V_118 ] ) ;
if ( V_103 )
goto V_164;
}
for ( V_118 = 0 ; V_118 < F_112 ( V_163 ) ; V_118 ++ ) {
V_103 = F_115 ( & V_163 [ V_118 ] ) ;
if ( V_103 )
goto V_165;
}
return 0 ;
V_165:
for (; V_118 -- ; )
F_113 ( & V_163 [ V_118 ] ) ;
V_118 = F_112 ( V_162 ) ;
V_164:
for (; V_118 -- ; )
F_113 ( & V_162 [ V_118 ] ) ;
return V_103 ;
}
int F_116 ( struct V_1 * V_2 )
{
int V_103 ;
F_117 ( & V_2 -> V_166 ) ;
V_103 = F_103 ( V_2 ) ;
if ( V_103 )
goto V_167;
V_103 = F_118 ( V_2 -> V_75 , V_2 -> V_148 [ V_147 ] , F_98 ,
0 , L_14 , V_2 -> V_69 [ 0 ] ) ;
if ( V_103 ) {
F_27 ( V_2 -> V_75 , L_15 ) ;
goto V_168;
}
V_103 = F_118 ( V_2 -> V_75 , V_2 -> V_148 [ V_161 ] , F_98 ,
0 , L_14 , V_2 -> V_69 [ 1 ] ) ;
if ( V_103 ) {
F_27 ( V_2 -> V_75 , L_16 ) ;
goto V_168;
}
F_3 ( V_2 , F_119 ( V_147 ) , V_169 ) ;
F_3 ( V_2 , F_119 ( V_161 ) , V_170 ) ;
F_120 ( & V_20 . V_21 ) ;
F_121 ( & V_2 -> V_166 , & V_20 . V_171 ) ;
F_122 ( & V_20 . V_21 ) ;
V_103 = F_114 () ;
if ( V_103 )
goto V_172;
return 0 ;
V_172:
F_120 ( & V_20 . V_21 ) ;
F_123 ( & V_2 -> V_166 ) ;
F_122 ( & V_20 . V_21 ) ;
V_168:
F_109 ( V_2 ) ;
V_167:
F_27 ( V_2 -> V_75 , L_17 ) ;
return V_103 ;
}
void F_124 ( struct V_1 * V_2 )
{
F_120 ( & V_20 . V_21 ) ;
F_123 ( & V_2 -> V_166 ) ;
F_122 ( & V_20 . V_21 ) ;
F_111 () ;
F_109 ( V_2 ) ;
}
