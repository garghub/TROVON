static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static struct V_1 * F_5 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = NULL ;
struct V_1 * V_8 ;
F_6 ( & V_9 . V_10 ) ;
if ( ! V_7 -> V_2 ) {
F_7 (tmp, &mtk_sha.dev_list, sha_list) {
V_2 = V_8 ;
break;
}
V_7 -> V_2 = V_2 ;
} else {
V_2 = V_7 -> V_2 ;
}
V_7 -> V_11 = V_2 -> V_12 ;
V_2 -> V_12 = ! V_2 -> V_12 ;
F_8 ( & V_9 . V_10 ) ;
return V_2 ;
}
static int F_9 ( struct V_13 * V_14 )
{
T_2 V_15 ;
while ( ( V_14 -> V_16 < V_17 ) && V_14 -> V_18 ) {
V_15 = F_10 ( V_14 -> V_19 -> V_20 - V_14 -> V_3 , V_14 -> V_18 ) ;
V_15 = F_10 ( V_15 , V_17 - V_14 -> V_16 ) ;
if ( V_15 <= 0 ) {
if ( ( V_14 -> V_19 -> V_20 == 0 ) && ! F_11 ( V_14 -> V_19 ) ) {
V_14 -> V_19 = F_12 ( V_14 -> V_19 ) ;
continue;
} else {
break;
}
}
F_13 ( V_14 -> V_21 + V_14 -> V_16 , V_14 -> V_19 ,
V_14 -> V_3 , V_15 , 0 ) ;
V_14 -> V_16 += V_15 ;
V_14 -> V_3 += V_15 ;
V_14 -> V_18 -= V_15 ;
if ( V_14 -> V_3 == V_14 -> V_19 -> V_20 ) {
V_14 -> V_19 = F_12 ( V_14 -> V_19 ) ;
if ( V_14 -> V_19 )
V_14 -> V_3 = 0 ;
else
V_14 -> V_18 = 0 ;
}
}
return 0 ;
}
static void F_14 ( struct V_13 * V_14 , T_1 V_22 )
{
T_1 V_23 , V_24 ;
T_3 V_25 [ 2 ] ;
T_3 V_26 = V_14 -> V_27 ;
V_26 += V_14 -> V_16 ;
V_26 += V_22 ;
V_25 [ 1 ] = F_15 ( V_26 << 3 ) ;
V_25 [ 0 ] = F_15 ( V_26 >> 61 ) ;
if ( V_14 -> V_28 & ( V_29 | V_30 ) ) {
V_23 = V_14 -> V_16 & 0x7f ;
V_24 = ( V_23 < 112 ) ? ( 112 - V_23 ) : ( ( 128 + 112 ) - V_23 ) ;
* ( V_14 -> V_21 + V_14 -> V_16 ) = 0x80 ;
memset ( V_14 -> V_21 + V_14 -> V_16 + 1 , 0 , V_24 - 1 ) ;
memcpy ( V_14 -> V_21 + V_14 -> V_16 + V_24 , V_25 , 16 ) ;
V_14 -> V_16 += V_24 + 16 ;
V_14 -> V_28 |= V_31 ;
} else {
V_23 = V_14 -> V_16 & 0x3f ;
V_24 = ( V_23 < 56 ) ? ( 56 - V_23 ) : ( ( 64 + 56 ) - V_23 ) ;
* ( V_14 -> V_21 + V_14 -> V_16 ) = 0x80 ;
memset ( V_14 -> V_21 + V_14 -> V_16 + 1 , 0 , V_24 - 1 ) ;
memcpy ( V_14 -> V_21 + V_14 -> V_16 + V_24 , & V_25 [ 1 ] , 8 ) ;
V_14 -> V_16 += V_24 + 8 ;
V_14 -> V_28 |= V_31 ;
}
}
static void F_16 ( struct V_13 * V_14 )
{
struct V_32 * V_33 = & V_14 -> V_34 . V_33 ;
struct V_35 * V_36 = & V_14 -> V_34 . V_36 ;
V_14 -> V_37 = V_38 ;
V_14 -> V_39 = V_40 ;
V_36 -> V_41 [ 0 ] = V_42 | V_43 |
F_17 ( F_18 ( V_14 -> V_44 ) ) ;
switch ( V_14 -> V_28 & V_45 ) {
case V_46 :
V_36 -> V_41 [ 0 ] |= V_47 ;
break;
case V_48 :
V_36 -> V_41 [ 0 ] |= V_49 ;
break;
case V_50 :
V_36 -> V_41 [ 0 ] |= V_51 ;
break;
case V_29 :
V_36 -> V_41 [ 0 ] |= V_52 ;
break;
case V_30 :
V_36 -> V_41 [ 0 ] |= V_53 ;
break;
default:
return;
}
V_36 -> V_41 [ 1 ] = V_54 ;
V_33 -> V_41 [ 0 ] = V_36 -> V_41 [ 0 ] | V_55 | V_56 ;
V_33 -> V_41 [ 1 ] = V_36 -> V_41 [ 1 ] ;
V_33 -> V_57 [ 0 ] = V_58 ;
V_33 -> V_57 [ 1 ] = V_59 ;
V_33 -> V_57 [ 2 ] = V_60 | F_19 ( F_18 ( V_14 -> V_44 ) ) ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_61 * V_62 ,
T_2 V_22 )
{
struct V_13 * V_14 = F_21 ( V_62 -> V_63 ) ;
struct V_64 * V_34 = & V_14 -> V_34 ;
struct V_32 * V_33 = & V_34 -> V_33 ;
if ( V_14 -> V_65 )
V_14 -> V_65 = false ;
else
V_33 -> V_41 [ 0 ] &= ~ V_56 ;
V_14 -> V_37 &= ~ V_66 ;
V_14 -> V_37 |= F_22 ( V_22 ) ;
V_33 -> V_57 [ 0 ] &= ~ V_66 ;
V_33 -> V_57 [ 0 ] |= F_22 ( V_22 ) ;
V_14 -> V_27 += V_22 ;
V_14 -> V_67 = F_23 ( V_2 -> V_68 , V_34 , sizeof( * V_34 ) ,
V_69 ) ;
if ( F_24 ( F_25 ( V_2 -> V_68 , V_14 -> V_67 ) ) ) {
F_26 ( V_2 -> V_68 , L_1 , sizeof( * V_34 ) ) ;
return - V_70 ;
}
V_14 -> V_71 = V_14 -> V_67 + sizeof( * V_33 ) ;
return 0 ;
}
static int F_27 ( struct V_72 * V_63 )
{
struct V_6 * V_7 = F_28 ( V_63 -> V_4 . V_36 ) ;
struct V_73 * V_74 = V_7 -> V_4 ;
struct V_13 * V_14 = F_21 ( V_63 ) ;
F_29 ( V_75 , V_74 -> V_75 ) ;
V_75 -> V_36 = V_74 -> V_75 ;
V_75 -> V_28 = 0 ;
return F_30 ( V_75 ) ? :
F_31 ( V_75 , V_74 -> V_76 , V_14 -> V_77 ) ? :
F_32 ( V_75 , V_63 -> V_78 , V_14 -> V_44 , V_63 -> V_78 ) ;
}
static int F_33 ( struct V_72 * V_63 )
{
struct V_79 * V_36 = F_34 ( V_63 ) ;
struct V_6 * V_7 = F_35 ( V_36 ) ;
struct V_13 * V_14 = F_21 ( V_63 ) ;
V_14 -> V_28 = 0 ;
V_14 -> V_44 = F_36 ( V_36 ) ;
switch ( V_14 -> V_44 ) {
case V_80 :
V_14 -> V_28 |= V_46 ;
V_14 -> V_77 = V_81 ;
break;
case V_82 :
V_14 -> V_28 |= V_48 ;
V_14 -> V_77 = V_83 ;
break;
case V_84 :
V_14 -> V_28 |= V_50 ;
V_14 -> V_77 = V_85 ;
break;
case V_86 :
V_14 -> V_28 |= V_29 ;
V_14 -> V_77 = V_87 ;
break;
case V_88 :
V_14 -> V_28 |= V_30 ;
V_14 -> V_77 = V_89 ;
break;
default:
return - V_70 ;
}
V_14 -> V_16 = 0 ;
V_14 -> V_27 = 0 ;
V_14 -> V_21 = V_7 -> V_90 ;
V_14 -> V_65 = true ;
if ( V_7 -> V_28 & V_91 ) {
struct V_73 * V_74 = V_7 -> V_4 ;
memcpy ( V_14 -> V_21 , V_74 -> V_92 , V_14 -> V_77 ) ;
V_14 -> V_16 = V_14 -> V_77 ;
V_14 -> V_28 |= V_91 ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 , struct V_61 * V_62 ,
T_4 V_93 , T_2 V_22 )
{
struct V_13 * V_14 = F_21 ( V_62 -> V_63 ) ;
struct V_94 * V_95 = V_2 -> V_95 [ V_62 -> V_11 ] ;
struct V_96 * V_57 = V_95 -> V_97 + V_95 -> V_98 ;
struct V_96 * V_99 = V_95 -> V_100 + V_95 -> V_101 ;
int V_102 ;
V_102 = F_20 ( V_2 , V_62 , V_22 ) ;
if ( V_102 )
return V_102 ;
V_99 -> V_103 = V_104 | V_105 | F_38 ( V_22 ) ;
V_99 -> V_90 = F_22 ( V_2 -> V_106 ) ;
V_57 -> V_103 = V_104 | V_105 | F_38 ( V_22 ) |
F_39 ( V_14 -> V_39 ) ;
V_57 -> V_90 = F_22 ( V_93 ) ;
V_57 -> V_33 = F_22 ( V_14 -> V_67 ) ;
V_57 -> V_37 = V_14 -> V_37 ;
V_57 -> V_36 = F_22 ( V_14 -> V_71 ) ;
if ( ++ V_95 -> V_98 == V_107 )
V_95 -> V_98 = 0 ;
V_95 -> V_101 = V_95 -> V_98 ;
F_40 () ;
F_3 ( V_2 , F_41 ( V_62 -> V_11 ) , F_42 ( 1 ) ) ;
F_3 ( V_2 , F_43 ( V_62 -> V_11 ) , F_42 ( 1 ) ) ;
return - V_108 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_61 * V_62 ,
struct V_13 * V_14 ,
T_2 V_109 , T_2 V_110 )
{
struct V_94 * V_95 = V_2 -> V_95 [ V_62 -> V_11 ] ;
struct V_96 * V_57 = V_95 -> V_97 + V_95 -> V_98 ;
struct V_96 * V_99 = V_95 -> V_100 + V_95 -> V_101 ;
int V_102 ;
V_102 = F_20 ( V_2 , V_62 , V_109 + V_110 ) ;
if ( V_102 )
return V_102 ;
V_99 -> V_103 = F_38 ( V_109 ) | V_104 ;
V_99 -> V_90 = F_22 ( V_2 -> V_106 ) ;
V_57 -> V_103 = F_38 ( V_109 ) | V_104 |
F_39 ( V_14 -> V_39 ) ;
V_57 -> V_90 = F_22 ( F_45 ( V_14 -> V_19 ) ) ;
V_57 -> V_33 = F_22 ( V_14 -> V_67 ) ;
V_57 -> V_37 = V_14 -> V_37 ;
V_57 -> V_36 = F_22 ( V_14 -> V_71 ) ;
if ( ++ V_95 -> V_98 == V_107 )
V_95 -> V_98 = 0 ;
V_95 -> V_101 = V_95 -> V_98 ;
V_57 = V_95 -> V_97 + V_95 -> V_98 ;
V_99 = V_95 -> V_100 + V_95 -> V_101 ;
V_99 -> V_103 = F_38 ( V_110 ) | V_105 ;
V_99 -> V_90 = F_22 ( V_2 -> V_106 ) ;
V_57 -> V_103 = F_38 ( V_110 ) | V_105 ;
V_57 -> V_90 = F_22 ( V_14 -> V_111 ) ;
if ( ++ V_95 -> V_98 == V_107 )
V_95 -> V_98 = 0 ;
V_95 -> V_101 = V_95 -> V_98 ;
F_40 () ;
F_3 ( V_2 , F_41 ( V_62 -> V_11 ) , F_42 ( 2 ) ) ;
F_3 ( V_2 , F_43 ( V_62 -> V_11 ) , F_42 ( 2 ) ) ;
return - V_108 ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_61 * V_62 ,
struct V_13 * V_14 ,
T_2 V_15 )
{
V_14 -> V_111 = F_23 ( V_2 -> V_68 , V_14 -> V_21 ,
V_17 , V_112 ) ;
if ( F_24 ( F_25 ( V_2 -> V_68 , V_14 -> V_111 ) ) ) {
F_26 ( V_2 -> V_68 , L_2 ) ;
return - V_70 ;
}
V_14 -> V_28 &= ~ V_113 ;
return F_37 ( V_2 , V_62 , V_14 -> V_111 , V_15 ) ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_61 * V_62 )
{
struct V_13 * V_14 = F_21 ( V_62 -> V_63 ) ;
T_2 V_15 ;
T_1 V_114 ;
F_9 ( V_14 ) ;
V_114 = ( V_14 -> V_28 & V_115 ) && ! V_14 -> V_18 ;
F_48 ( V_2 -> V_68 , L_3 , V_14 -> V_16 ) ;
if ( V_114 ) {
V_62 -> V_28 |= V_116 ;
F_14 ( V_14 , 0 ) ;
}
if ( V_114 || ( V_14 -> V_16 == V_17 && V_14 -> V_18 ) ) {
V_15 = V_14 -> V_16 ;
V_14 -> V_16 = 0 ;
return F_46 ( V_2 , V_62 , V_14 , V_15 ) ;
}
return 0 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_61 * V_62 )
{
struct V_13 * V_14 = F_21 ( V_62 -> V_63 ) ;
T_1 V_22 , V_114 , V_117 ;
struct V_118 * V_19 ;
if ( ! V_14 -> V_18 )
return 0 ;
if ( V_14 -> V_16 || V_14 -> V_3 )
return F_47 ( V_2 , V_62 ) ;
V_19 = V_14 -> V_19 ;
if ( ! F_50 ( V_19 -> V_3 , sizeof( T_1 ) ) )
return F_47 ( V_2 , V_62 ) ;
if ( ! F_11 ( V_19 ) && ! F_50 ( V_19 -> V_20 , V_14 -> V_77 ) )
return F_47 ( V_2 , V_62 ) ;
V_22 = F_10 ( V_14 -> V_18 , V_19 -> V_20 ) ;
if ( F_11 ( V_19 ) ) {
if ( ! ( V_14 -> V_28 & V_115 ) ) {
V_117 = V_22 & ( V_14 -> V_77 - 1 ) ;
V_22 -= V_117 ;
}
}
V_14 -> V_18 -= V_22 ;
V_14 -> V_3 = V_22 ;
V_114 = ( V_14 -> V_28 & V_115 ) && ! V_14 -> V_18 ;
if ( V_114 ) {
T_2 V_15 ;
V_117 = V_22 & ( V_14 -> V_77 - 1 ) ;
V_22 -= V_117 ;
V_14 -> V_18 += V_117 ;
V_14 -> V_3 = V_22 ;
V_19 = V_14 -> V_19 ;
F_9 ( V_14 ) ;
F_14 ( V_14 , V_22 ) ;
V_14 -> V_111 = F_23 ( V_2 -> V_68 , V_14 -> V_21 ,
V_17 , V_112 ) ;
if ( F_24 ( F_25 ( V_2 -> V_68 , V_14 -> V_111 ) ) ) {
F_26 ( V_2 -> V_68 , L_4 ) ;
return - V_70 ;
}
V_62 -> V_28 |= V_116 ;
V_15 = V_14 -> V_16 ;
V_14 -> V_16 = 0 ;
if ( V_22 == 0 ) {
V_14 -> V_28 &= ~ V_113 ;
return F_37 ( V_2 , V_62 , V_14 -> V_111 , V_15 ) ;
} else {
V_14 -> V_19 = V_19 ;
if ( ! F_51 ( V_2 -> V_68 , V_14 -> V_19 , 1 , V_112 ) ) {
F_26 ( V_2 -> V_68 , L_5 ) ;
return - V_70 ;
}
V_14 -> V_28 |= V_113 ;
return F_44 ( V_2 , V_62 , V_14 , V_22 , V_15 ) ;
}
}
if ( ! F_51 ( V_2 -> V_68 , V_14 -> V_19 , 1 , V_112 ) ) {
F_26 ( V_2 -> V_68 , L_6 ) ;
return - V_70 ;
}
V_14 -> V_28 |= V_113 ;
return F_37 ( V_2 , V_62 , F_45 ( V_14 -> V_19 ) , V_22 ) ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_61 * V_62 )
{
struct V_13 * V_14 = F_21 ( V_62 -> V_63 ) ;
T_2 V_15 ;
F_14 ( V_14 , 0 ) ;
V_62 -> V_28 |= V_116 ;
V_15 = V_14 -> V_16 ;
V_14 -> V_16 = 0 ;
return F_46 ( V_2 , V_62 , V_14 , V_15 ) ;
}
static int F_53 ( struct V_72 * V_63 )
{
struct V_13 * V_14 = F_21 ( V_63 ) ;
T_1 * V_119 = V_14 -> V_34 . V_36 . V_119 ;
T_1 * V_78 = ( T_1 * ) V_63 -> V_78 ;
int V_120 ;
for ( V_120 = 0 ; V_120 < F_18 ( V_14 -> V_44 ) ; V_120 ++ )
V_78 [ V_120 ] = F_54 ( V_119 [ V_120 ] ) ;
if ( V_14 -> V_28 & V_91 )
return F_27 ( V_63 ) ;
return 0 ;
}
static void F_55 ( struct V_1 * V_2 ,
struct V_61 * V_62 ,
int V_102 )
{
if ( F_56 ( ! V_102 && ( V_116 & V_62 -> V_28 ) ) )
V_102 = F_53 ( V_62 -> V_63 ) ;
V_62 -> V_28 &= ~ ( V_121 | V_116 ) ;
V_62 -> V_63 -> V_4 . V_122 ( & V_62 -> V_63 -> V_4 , V_102 ) ;
F_57 ( V_2 , V_62 -> V_11 - V_123 , NULL ) ;
}
static int F_57 ( struct V_1 * V_2 , T_5 V_11 ,
struct V_72 * V_63 )
{
struct V_61 * V_62 = V_2 -> V_62 [ V_11 ] ;
struct V_124 * V_125 , * V_126 ;
struct V_13 * V_14 ;
unsigned long V_28 ;
int V_102 = 0 , V_127 = 0 ;
F_58 ( & V_62 -> V_10 , V_28 ) ;
if ( V_63 )
V_127 = F_59 ( & V_62 -> V_128 , V_63 ) ;
if ( V_121 & V_62 -> V_28 ) {
F_60 ( & V_62 -> V_10 , V_28 ) ;
return V_127 ;
}
V_126 = F_61 ( & V_62 -> V_128 ) ;
V_125 = F_62 ( & V_62 -> V_128 ) ;
if ( V_125 )
V_62 -> V_28 |= V_121 ;
F_60 ( & V_62 -> V_10 , V_28 ) ;
if ( ! V_125 )
return V_127 ;
if ( V_126 )
V_126 -> V_122 ( V_126 , - V_108 ) ;
V_63 = F_63 ( V_125 ) ;
V_14 = F_21 ( V_63 ) ;
V_62 -> V_63 = V_63 ;
F_16 ( V_14 ) ;
if ( V_14 -> V_129 == V_130 ) {
V_102 = F_49 ( V_2 , V_62 ) ;
if ( V_102 != - V_108 && ( V_14 -> V_28 & V_115 ) )
V_102 = F_52 ( V_2 , V_62 ) ;
} else if ( V_14 -> V_129 == V_131 ) {
V_102 = F_52 ( V_2 , V_62 ) ;
}
if ( F_24 ( V_102 != - V_108 ) )
F_55 ( V_2 , V_62 , V_102 ) ;
return V_127 ;
}
static int F_64 ( struct V_72 * V_63 , T_1 V_129 )
{
struct V_13 * V_14 = F_21 ( V_63 ) ;
struct V_6 * V_7 = F_28 ( V_63 -> V_4 . V_36 ) ;
V_14 -> V_129 = V_129 ;
return F_57 ( V_7 -> V_2 , V_7 -> V_11 , V_63 ) ;
}
static void F_65 ( struct V_1 * V_2 , struct V_61 * V_62 )
{
struct V_13 * V_14 = F_21 ( V_62 -> V_63 ) ;
F_66 ( V_2 -> V_68 , V_14 -> V_67 , sizeof( V_14 -> V_34 ) ,
V_69 ) ;
if ( V_14 -> V_28 & V_113 ) {
F_67 ( V_2 -> V_68 , V_14 -> V_19 , 1 , V_112 ) ;
if ( V_14 -> V_19 -> V_20 == V_14 -> V_3 ) {
V_14 -> V_19 = F_12 ( V_14 -> V_19 ) ;
if ( V_14 -> V_19 )
V_14 -> V_3 = 0 ;
}
if ( V_14 -> V_28 & V_31 ) {
F_66 ( V_2 -> V_68 , V_14 -> V_111 ,
V_17 , V_112 ) ;
}
} else
F_66 ( V_2 -> V_68 , V_14 -> V_111 ,
V_17 , V_112 ) ;
}
static void F_68 ( struct V_1 * V_2 ,
struct V_61 * V_62 )
{
int V_102 = 0 ;
V_102 = F_49 ( V_2 , V_62 ) ;
if ( V_102 != - V_108 )
F_55 ( V_2 , V_62 , V_102 ) ;
}
static int F_69 ( struct V_72 * V_63 )
{
struct V_13 * V_14 = F_21 ( V_63 ) ;
V_14 -> V_18 = V_63 -> V_132 ;
V_14 -> V_19 = V_63 -> V_133 ;
V_14 -> V_3 = 0 ;
if ( ( V_14 -> V_16 + V_14 -> V_18 < V_17 ) &&
! ( V_14 -> V_28 & V_115 ) )
return F_9 ( V_14 ) ;
return F_64 ( V_63 , V_130 ) ;
}
static int F_70 ( struct V_72 * V_63 )
{
struct V_13 * V_14 = F_21 ( V_63 ) ;
V_14 -> V_28 |= V_115 ;
if ( V_14 -> V_28 & V_31 )
return F_53 ( V_63 ) ;
return F_64 ( V_63 , V_131 ) ;
}
static int F_71 ( struct V_72 * V_63 )
{
struct V_13 * V_14 = F_21 ( V_63 ) ;
int V_134 , V_135 ;
V_14 -> V_28 |= V_115 ;
V_134 = F_69 ( V_63 ) ;
if ( V_134 == - V_108 || V_134 == - V_136 )
return V_134 ;
V_135 = F_70 ( V_63 ) ;
return V_134 ? : V_135 ;
}
static int F_72 ( struct V_72 * V_63 )
{
return F_33 ( V_63 ) ? : F_71 ( V_63 ) ;
}
static int F_73 ( struct V_79 * V_36 , const T_5 * V_137 ,
T_1 V_138 )
{
struct V_6 * V_7 = F_35 ( V_36 ) ;
struct V_73 * V_74 = V_7 -> V_4 ;
T_2 V_77 = F_74 ( V_74 -> V_75 ) ;
T_2 V_44 = F_75 ( V_74 -> V_75 ) ;
int V_102 , V_120 ;
F_29 ( V_75 , V_74 -> V_75 ) ;
V_75 -> V_36 = V_74 -> V_75 ;
V_75 -> V_28 = F_76 ( V_74 -> V_75 ) &
V_139 ;
if ( V_138 > V_77 ) {
V_102 = F_77 ( V_75 , V_137 , V_138 , V_74 -> V_92 ) ;
if ( V_102 )
return V_102 ;
V_138 = V_44 ;
} else {
memcpy ( V_74 -> V_92 , V_137 , V_138 ) ;
}
memset ( V_74 -> V_92 + V_138 , 0 , V_77 - V_138 ) ;
memcpy ( V_74 -> V_76 , V_74 -> V_92 , V_77 ) ;
for ( V_120 = 0 ; V_120 < V_77 ; V_120 ++ ) {
V_74 -> V_92 [ V_120 ] ^= 0x36 ;
V_74 -> V_76 [ V_120 ] ^= 0x5c ;
}
return 0 ;
}
static int F_78 ( struct V_72 * V_63 , void * V_140 )
{
const struct V_13 * V_14 = F_21 ( V_63 ) ;
memcpy ( V_140 , V_14 , sizeof( * V_14 ) ) ;
return 0 ;
}
static int F_79 ( struct V_72 * V_63 , const void * V_141 )
{
struct V_13 * V_14 = F_21 ( V_63 ) ;
memcpy ( V_14 , V_141 , sizeof( * V_14 ) ) ;
return 0 ;
}
static int F_80 ( struct V_142 * V_36 ,
const char * V_143 )
{
struct V_6 * V_7 = F_28 ( V_36 ) ;
struct V_1 * V_2 = NULL ;
V_2 = F_5 ( V_7 ) ;
if ( ! V_2 )
return - V_144 ;
F_81 ( F_82 ( V_36 ) ,
sizeof( struct V_13 ) ) ;
if ( V_143 ) {
struct V_73 * V_74 = V_7 -> V_4 ;
V_7 -> V_28 |= V_91 ;
V_74 -> V_75 = F_83 ( V_143 , 0 ,
V_145 ) ;
if ( F_84 ( V_74 -> V_75 ) ) {
F_85 ( L_7 ,
V_143 ) ;
return F_86 ( V_74 -> V_75 ) ;
}
}
return 0 ;
}
static int F_87 ( struct V_142 * V_36 )
{
return F_80 ( V_36 , NULL ) ;
}
static int F_88 ( struct V_142 * V_36 )
{
return F_80 ( V_36 , L_8 ) ;
}
static int F_89 ( struct V_142 * V_36 )
{
return F_80 ( V_36 , L_9 ) ;
}
static int F_90 ( struct V_142 * V_36 )
{
return F_80 ( V_36 , L_10 ) ;
}
static int F_91 ( struct V_142 * V_36 )
{
return F_80 ( V_36 , L_11 ) ;
}
static int F_92 ( struct V_142 * V_36 )
{
return F_80 ( V_36 , L_12 ) ;
}
static void F_93 ( struct V_142 * V_36 )
{
struct V_6 * V_7 = F_28 ( V_36 ) ;
if ( V_7 -> V_28 & V_91 ) {
struct V_73 * V_74 = V_7 -> V_4 ;
F_94 ( V_74 -> V_75 ) ;
}
}
static void F_95 ( unsigned long V_146 )
{
struct V_1 * V_2 = (struct V_1 * ) V_146 ;
struct V_61 * V_62 = V_2 -> V_62 [ 0 ] ;
F_65 ( V_2 , V_62 ) ;
F_68 ( V_2 , V_62 ) ;
}
static void F_96 ( unsigned long V_146 )
{
struct V_1 * V_2 = (struct V_1 * ) V_146 ;
struct V_61 * V_62 = V_2 -> V_62 [ 1 ] ;
F_65 ( V_2 , V_62 ) ;
F_68 ( V_2 , V_62 ) ;
}
static T_6 F_97 ( int V_147 , void * V_148 )
{
struct V_1 * V_2 = (struct V_1 * ) V_148 ;
struct V_61 * V_62 = V_2 -> V_62 [ 0 ] ;
T_1 V_149 = F_1 ( V_2 , F_98 ( V_123 ) ) ;
F_3 ( V_2 , F_98 ( V_123 ) , V_149 ) ;
if ( F_56 ( ( V_121 & V_62 -> V_28 ) ) ) {
F_3 ( V_2 , F_99 ( V_123 ) , V_150 ) ;
F_3 ( V_2 , F_100 ( V_123 ) ,
V_151 | V_152 ) ;
F_101 ( & V_62 -> V_153 ) ;
} else {
F_102 ( V_2 -> V_68 , L_13 ) ;
}
return V_154 ;
}
static T_6 F_103 ( int V_147 , void * V_148 )
{
struct V_1 * V_2 = (struct V_1 * ) V_148 ;
struct V_61 * V_62 = V_2 -> V_62 [ 1 ] ;
T_1 V_149 = F_1 ( V_2 , F_98 ( V_155 ) ) ;
F_3 ( V_2 , F_98 ( V_155 ) , V_149 ) ;
if ( F_56 ( ( V_121 & V_62 -> V_28 ) ) ) {
F_3 ( V_2 , F_99 ( V_155 ) , V_150 ) ;
F_3 ( V_2 , F_100 ( V_155 ) ,
V_151 | V_152 ) ;
F_101 ( & V_62 -> V_153 ) ;
} else {
F_102 ( V_2 -> V_68 , L_13 ) ;
}
return V_154 ;
}
static int F_104 ( struct V_1 * V_2 )
{
struct V_61 * * V_62 = V_2 -> V_62 ;
int V_120 , V_102 = - V_156 ;
for ( V_120 = 0 ; V_120 < V_157 ; V_120 ++ ) {
V_62 [ V_120 ] = F_105 ( sizeof( * * V_62 ) , V_158 ) ;
if ( ! V_62 [ V_120 ] )
goto V_159;
V_62 [ V_120 ] -> V_11 = V_120 + V_123 ;
F_106 ( & V_62 [ V_120 ] -> V_10 ) ;
F_107 ( & V_62 [ V_120 ] -> V_128 , V_160 ) ;
}
F_108 ( & V_62 [ 0 ] -> V_153 , F_95 , ( unsigned long ) V_2 ) ;
F_108 ( & V_62 [ 1 ] -> V_153 , F_96 , ( unsigned long ) V_2 ) ;
V_2 -> V_12 = 1 ;
return 0 ;
V_159:
for (; V_120 -- ; )
F_109 ( V_62 [ V_120 ] ) ;
return V_102 ;
}
static void F_110 ( struct V_1 * V_2 )
{
int V_120 ;
for ( V_120 = 0 ; V_120 < V_157 ; V_120 ++ ) {
F_111 ( & V_2 -> V_62 [ V_120 ] -> V_153 ) ;
F_109 ( V_2 -> V_62 [ V_120 ] ) ;
}
}
static void F_112 ( void )
{
int V_120 ;
for ( V_120 = 0 ; V_120 < F_113 ( V_161 ) ; V_120 ++ )
F_114 ( & V_161 [ V_120 ] ) ;
for ( V_120 = 0 ; V_120 < F_113 ( V_162 ) ; V_120 ++ )
F_114 ( & V_162 [ V_120 ] ) ;
}
static int F_115 ( void )
{
int V_102 , V_120 ;
for ( V_120 = 0 ; V_120 < F_113 ( V_161 ) ; V_120 ++ ) {
V_102 = F_116 ( & V_161 [ V_120 ] ) ;
if ( V_102 )
goto V_163;
}
for ( V_120 = 0 ; V_120 < F_113 ( V_162 ) ; V_120 ++ ) {
V_102 = F_116 ( & V_162 [ V_120 ] ) ;
if ( V_102 )
goto V_164;
}
return 0 ;
V_164:
for (; V_120 -- ; )
F_114 ( & V_162 [ V_120 ] ) ;
V_120 = F_113 ( V_161 ) ;
V_163:
for (; V_120 -- ; )
F_114 ( & V_161 [ V_120 ] ) ;
return V_102 ;
}
int F_117 ( struct V_1 * V_2 )
{
int V_102 ;
F_118 ( & V_2 -> V_165 ) ;
V_102 = F_104 ( V_2 ) ;
if ( V_102 )
goto V_166;
V_102 = F_119 ( V_2 -> V_68 , V_2 -> V_147 [ V_123 ] ,
F_97 , V_167 ,
L_14 , V_2 ) ;
if ( V_102 ) {
F_26 ( V_2 -> V_68 , L_15 ) ;
goto V_168;
}
V_102 = F_119 ( V_2 -> V_68 , V_2 -> V_147 [ V_155 ] ,
F_103 , V_167 ,
L_14 , V_2 ) ;
if ( V_102 ) {
F_26 ( V_2 -> V_68 , L_16 ) ;
goto V_168;
}
F_3 ( V_2 , F_120 ( V_123 ) , V_169 ) ;
F_3 ( V_2 , F_120 ( V_155 ) , V_170 ) ;
V_2 -> V_8 = F_121 ( V_2 -> V_68 , V_171 ,
& V_2 -> V_106 , V_158 ) ;
if ( ! V_2 -> V_8 ) {
F_26 ( V_2 -> V_68 , L_17 ) ;
V_102 = - V_70 ;
goto V_168;
}
F_122 ( & V_9 . V_10 ) ;
F_123 ( & V_2 -> V_165 , & V_9 . V_172 ) ;
F_124 ( & V_9 . V_10 ) ;
V_102 = F_115 () ;
if ( V_102 )
goto V_173;
return 0 ;
V_173:
F_122 ( & V_9 . V_10 ) ;
F_125 ( & V_2 -> V_165 ) ;
F_124 ( & V_9 . V_10 ) ;
F_126 ( V_2 -> V_68 , V_171 ,
V_2 -> V_8 , V_2 -> V_106 ) ;
V_168:
F_110 ( V_2 ) ;
V_166:
F_26 ( V_2 -> V_68 , L_18 ) ;
return V_102 ;
}
void F_127 ( struct V_1 * V_2 )
{
F_122 ( & V_9 . V_10 ) ;
F_125 ( & V_2 -> V_165 ) ;
F_124 ( & V_9 . V_10 ) ;
F_112 () ;
F_126 ( V_2 -> V_68 , V_171 ,
V_2 -> V_8 , V_2 -> V_106 ) ;
F_110 ( V_2 ) ;
}
