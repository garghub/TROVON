static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline int F_5 ( struct V_1 * V_2 )
{
T_1 V_6 ;
return F_6 ( V_2 -> V_4 + V_7 , V_6 ,
! ( V_6 & V_8 ) , 10 , 10000 ) ;
}
static void F_7 ( struct V_1 * V_2 , int V_9 )
{
T_1 V_10 ;
V_10 = F_1 ( V_2 , V_11 ) ;
V_10 &= ~ ( V_12 ) ;
V_10 |= ( 8U * ( ( V_9 ) % 4U ) ) ;
F_3 ( V_2 , V_11 , V_10 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_9 ( V_2 -> V_15 ) ;
struct V_16 * V_17 = F_10 ( V_14 ) ;
T_1 V_10 ;
int V_18 = V_17 -> V_18 ;
void * V_19 = V_17 -> V_19 ;
if ( V_18 ) {
F_7 ( V_2 , V_18 ) ;
while ( V_18 > 0 ) {
F_3 ( V_2 , V_20 , * ( T_1 * ) V_19 ) ;
V_18 -= 4 ;
V_19 += 4 ;
}
V_10 = F_1 ( V_2 , V_11 ) ;
V_10 |= V_21 ;
F_3 ( V_2 , V_11 , V_10 ) ;
return - V_22 ;
}
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = F_12 ( V_2 -> V_15 ) ;
struct V_13 * V_14 = F_9 ( V_2 -> V_15 ) ;
struct V_16 * V_17 = F_10 ( V_14 ) ;
T_1 V_10 = V_25 ;
if ( ! ( V_2 -> V_26 & V_27 ) ) {
switch ( V_24 -> V_26 & V_28 ) {
case V_29 :
V_10 |= V_30 ;
break;
case V_31 :
V_10 |= V_32 ;
break;
case V_33 :
V_10 |= V_34 ;
break;
case V_35 :
V_10 |= V_36 ;
break;
default:
V_10 |= V_30 ;
}
V_10 |= ( V_24 -> V_37 << V_38 ) ;
if ( V_24 -> V_26 & V_39 ) {
V_2 -> V_26 |= V_39 ;
V_10 |= V_40 ;
if ( V_17 -> V_18 > V_41 )
V_10 |= V_42 ;
}
F_3 ( V_2 , V_43 , V_44 ) ;
F_3 ( V_2 , V_45 , V_10 ) ;
V_2 -> V_26 |= V_27 ;
F_13 ( V_2 -> V_46 , L_1 , V_10 ) ;
}
}
static void F_14 ( struct V_23 * V_24 )
{
T_2 V_47 ;
while ( ( V_24 -> V_48 < V_24 -> V_49 ) && V_24 -> V_50 ) {
V_47 = F_15 ( V_24 -> V_51 -> V_9 - V_24 -> V_3 , V_24 -> V_50 ) ;
V_47 = F_15 ( V_47 , V_24 -> V_49 - V_24 -> V_48 ) ;
if ( V_47 <= 0 ) {
if ( ( V_24 -> V_51 -> V_9 == 0 ) && ! F_16 ( V_24 -> V_51 ) ) {
V_24 -> V_51 = F_17 ( V_24 -> V_51 ) ;
continue;
} else {
break;
}
}
F_18 ( V_24 -> V_52 + V_24 -> V_48 , V_24 -> V_51 ,
V_24 -> V_3 , V_47 , 0 ) ;
V_24 -> V_48 += V_47 ;
V_24 -> V_3 += V_47 ;
V_24 -> V_50 -= V_47 ;
if ( V_24 -> V_3 == V_24 -> V_51 -> V_9 ) {
V_24 -> V_51 = F_17 ( V_24 -> V_51 ) ;
if ( V_24 -> V_51 )
V_24 -> V_3 = 0 ;
else
V_24 -> V_50 = 0 ;
}
}
}
static int F_19 ( struct V_1 * V_2 ,
const T_3 * V_53 , T_2 V_9 , int V_54 )
{
unsigned int V_47 , V_55 ;
const T_1 * V_52 = ( const T_1 * ) V_53 ;
T_1 V_10 ;
if ( V_54 )
V_2 -> V_26 |= V_56 ;
V_55 = F_20 ( V_9 , sizeof( T_1 ) ) ;
F_13 ( V_2 -> V_46 , L_2 ,
V_57 , V_9 , V_54 , V_55 ) ;
V_2 -> V_26 |= V_58 ;
F_11 ( V_2 ) ;
if ( F_5 ( V_2 ) )
return - V_59 ;
if ( ( V_2 -> V_26 & V_39 ) &&
( V_2 -> V_26 & ~ V_60 ) ) {
V_2 -> V_26 |= V_60 ;
F_8 ( V_2 ) ;
if ( F_5 ( V_2 ) )
return - V_59 ;
}
for ( V_47 = 0 ; V_47 < V_55 ; V_47 ++ )
F_3 ( V_2 , V_20 , V_52 [ V_47 ] ) ;
if ( V_54 ) {
F_7 ( V_2 , V_9 ) ;
V_10 = F_1 ( V_2 , V_11 ) ;
V_10 |= V_21 ;
F_3 ( V_2 , V_11 , V_10 ) ;
if ( V_2 -> V_26 & V_39 ) {
if ( F_5 ( V_2 ) )
return - V_59 ;
F_8 ( V_2 ) ;
}
return - V_22 ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = F_12 ( V_2 -> V_15 ) ;
int V_48 , V_61 = 0 , V_54 ;
F_13 ( V_2 -> V_46 , L_3 , V_57 , V_24 -> V_26 ) ;
V_54 = ( V_24 -> V_26 & V_62 ) ;
while ( ( V_24 -> V_50 >= V_24 -> V_49 ) ||
( V_24 -> V_48 + V_24 -> V_50 >= V_24 -> V_49 ) ) {
F_14 ( V_24 ) ;
V_48 = V_24 -> V_48 ;
V_24 -> V_48 = 0 ;
V_61 = F_19 ( V_2 , V_24 -> V_52 , V_48 , 0 ) ;
}
F_14 ( V_24 ) ;
if ( V_54 ) {
V_48 = V_24 -> V_48 ;
V_24 -> V_48 = 0 ;
V_61 = F_19 ( V_2 , V_24 -> V_52 , V_48 ,
( V_24 -> V_26 & V_62 ) ) ;
}
return V_61 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_63 * V_51 , int V_9 , int V_64 )
{
struct V_65 * V_66 ;
T_4 V_67 ;
T_1 V_10 ;
int V_61 ;
V_66 = F_23 ( V_2 -> V_68 , V_51 , 1 ,
V_69 , V_70 |
V_71 ) ;
if ( ! V_66 ) {
F_24 ( V_2 -> V_46 , L_4 ) ;
return - V_72 ;
}
F_25 ( & V_2 -> V_73 ) ;
V_66 -> V_74 = V_75 ;
V_66 -> V_76 = V_2 ;
V_2 -> V_26 |= V_56 ;
V_2 -> V_26 |= V_77 ;
V_10 = F_1 ( V_2 , V_45 ) ;
if ( V_64 )
V_10 |= V_78 ;
else
V_10 &= ~ V_78 ;
V_10 |= V_79 ;
F_3 ( V_2 , V_45 , V_10 ) ;
F_7 ( V_2 , V_9 ) ;
V_67 = F_26 ( V_66 ) ;
V_61 = F_27 ( V_67 ) ;
if ( V_61 )
return - V_72 ;
F_28 ( V_2 -> V_68 ) ;
if ( ! F_29 ( & V_2 -> V_73 ,
F_30 ( 100 ) ) )
V_61 = - V_59 ;
if ( F_31 ( V_2 -> V_68 , V_67 ,
NULL , NULL ) != V_80 )
V_61 = - V_59 ;
if ( V_61 ) {
F_24 ( V_2 -> V_46 , L_5 , V_61 ) ;
F_32 ( V_2 -> V_68 ) ;
return V_61 ;
}
return - V_22 ;
}
static void V_75 ( void * V_81 )
{
struct V_1 * V_2 = V_81 ;
F_33 ( & V_2 -> V_73 ) ;
V_2 -> V_26 |= V_82 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = F_12 ( V_2 -> V_15 ) ;
struct V_13 * V_14 = F_9 ( V_2 -> V_15 ) ;
struct V_16 * V_17 = F_10 ( V_14 ) ;
int V_61 ;
if ( V_17 -> V_18 < V_83 || ( V_2 -> V_84 == 1 ) ) {
V_61 = F_8 ( V_2 ) ;
if ( F_5 ( V_2 ) )
return - V_59 ;
} else {
if ( ! ( V_2 -> V_26 & V_60 ) )
F_35 ( & V_24 -> V_85 , V_17 -> V_19 ,
F_36 ( V_17 -> V_18 , sizeof( T_1 ) ) ) ;
V_24 -> V_86 = F_37 ( V_2 -> V_46 , & V_24 -> V_85 , 1 ,
V_87 ) ;
if ( V_24 -> V_86 == 0 ) {
F_24 ( V_2 -> V_46 , L_6 ) ;
return - V_72 ;
}
V_61 = F_22 ( V_2 , & V_24 -> V_85 , V_17 -> V_18 , 0 ) ;
F_38 ( V_2 -> V_46 , & V_24 -> V_85 , 1 , V_87 ) ;
}
return V_61 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_88 V_89 ;
int V_61 ;
memset ( & V_89 , 0 , sizeof( V_89 ) ) ;
V_89 . V_90 = V_69 ;
V_89 . V_91 = V_2 -> V_92 + V_20 ;
V_89 . V_93 = V_94 ;
V_89 . V_95 = V_2 -> V_96 ;
V_89 . V_97 = V_2 -> V_96 ;
V_89 . V_98 = false ;
V_2 -> V_68 = F_40 ( V_2 -> V_46 , L_7 ) ;
if ( ! V_2 -> V_68 ) {
F_24 ( V_2 -> V_46 , L_8 ) ;
return - V_99 ;
}
V_61 = F_41 ( V_2 -> V_68 , & V_89 ) ;
if ( V_61 ) {
F_42 ( V_2 -> V_68 ) ;
V_2 -> V_68 = NULL ;
F_24 ( V_2 -> V_46 , L_9 ) ;
return V_61 ;
}
F_43 ( & V_2 -> V_73 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = F_12 ( V_2 -> V_15 ) ;
struct V_63 V_51 [ 1 ] , * V_100 ;
int V_61 = 0 , V_101 = 0 , V_10 , V_102 = 0 ;
unsigned int V_103 ;
T_1 * V_52 = ( void * ) V_24 -> V_52 ;
V_24 -> V_51 = V_2 -> V_15 -> V_104 ;
V_24 -> V_50 = V_2 -> V_15 -> V_105 ;
V_24 -> V_106 = F_45 ( V_24 -> V_51 ) ;
if ( V_24 -> V_106 < 0 )
return - V_107 ;
F_11 ( V_2 ) ;
if ( V_2 -> V_26 & V_39 ) {
V_61 = F_34 ( V_2 ) ;
if ( V_61 != - V_22 )
return V_61 ;
}
F_46 (rctx->sg, tsg, rctx->nents, i) {
V_101 = V_51 -> V_9 ;
V_51 [ 0 ] = * V_100 ;
if ( F_16 ( V_51 ) ) {
if ( V_2 -> V_84 == 1 ) {
V_101 = ( F_36 ( V_51 -> V_9 , 16 ) - 16 ) ;
V_102 = F_47 (
V_24 -> V_51 , V_24 -> V_106 ,
V_24 -> V_52 , V_51 -> V_9 - V_101 ,
V_24 -> V_50 - V_51 -> V_9 + V_101 ) ;
V_51 -> V_9 = V_101 ;
} else {
if ( ! ( F_48 ( V_51 -> V_9 , sizeof( T_1 ) ) ) ) {
V_101 = V_51 -> V_9 ;
V_51 -> V_9 = F_36 ( V_51 -> V_9 ,
sizeof( T_1 ) ) ;
}
}
}
V_24 -> V_86 = F_37 ( V_2 -> V_46 , V_51 , 1 ,
V_87 ) ;
if ( V_24 -> V_86 == 0 ) {
F_24 ( V_2 -> V_46 , L_6 ) ;
return - V_72 ;
}
V_61 = F_22 ( V_2 , V_51 , V_101 ,
! F_16 ( V_51 ) ) ;
F_38 ( V_2 -> V_46 , V_51 , 1 , V_87 ) ;
if ( V_61 == - V_72 )
return V_61 ;
}
if ( V_2 -> V_84 == 1 ) {
if ( F_5 ( V_2 ) )
return - V_59 ;
V_10 = F_1 ( V_2 , V_45 ) ;
V_10 &= ~ V_79 ;
V_10 |= V_108 ;
F_3 ( V_2 , V_45 , V_10 ) ;
if ( V_102 ) {
memset ( V_52 + V_102 , 0 ,
F_20 ( V_102 , sizeof( T_1 ) ) - V_102 ) ;
F_49 ( V_2 -> V_4 + V_20 , V_52 ,
F_20 ( V_102 , sizeof( T_1 ) ) ) ;
}
F_7 ( V_2 , F_20 ( V_102 , sizeof( T_1 ) ) ) ;
V_10 = F_1 ( V_2 , V_11 ) ;
V_10 |= V_21 ;
F_3 ( V_2 , V_11 , V_10 ) ;
V_61 = - V_22 ;
}
if ( V_2 -> V_26 & V_39 ) {
if ( F_5 ( V_2 ) )
return - V_59 ;
V_61 = F_34 ( V_2 ) ;
}
return V_61 ;
}
static struct V_1 * F_50 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = NULL , * V_109 ;
F_51 ( & V_110 . V_111 ) ;
if ( ! V_17 -> V_2 ) {
F_52 (tmp, &stm32_hash.dev_list, list) {
V_2 = V_109 ;
break;
}
V_17 -> V_2 = V_2 ;
} else {
V_2 = V_17 -> V_2 ;
}
F_53 ( & V_110 . V_111 ) ;
return V_2 ;
}
static bool F_54 ( struct V_112 * V_15 )
{
struct V_63 * V_51 ;
struct V_16 * V_17 = F_10 ( F_9 ( V_15 ) ) ;
struct V_1 * V_2 = F_50 ( V_17 ) ;
int V_103 ;
if ( V_15 -> V_105 <= V_83 )
return false ;
if ( F_45 ( V_15 -> V_104 ) > 1 ) {
if ( V_2 -> V_84 == 1 )
return false ;
F_46 (req->src, sg, sg_nents(req->src), i) {
if ( ( ! F_48 ( V_51 -> V_9 , sizeof( T_1 ) ) ) &&
( ! F_16 ( V_51 ) ) )
return false ;
}
}
if ( V_15 -> V_104 -> V_3 % 4 )
return false ;
return true ;
}
static int F_55 ( struct V_112 * V_15 )
{
struct V_13 * V_14 = F_9 ( V_15 ) ;
struct V_16 * V_17 = F_10 ( V_14 ) ;
struct V_23 * V_24 = F_12 ( V_15 ) ;
struct V_1 * V_2 = F_50 ( V_17 ) ;
V_24 -> V_2 = V_2 ;
V_24 -> V_26 = V_58 ;
V_24 -> V_113 = F_56 ( V_14 ) ;
switch ( V_24 -> V_113 ) {
case V_114 :
V_24 -> V_26 |= V_29 ;
break;
case V_115 :
V_24 -> V_26 |= V_31 ;
break;
case V_116 :
V_24 -> V_26 |= V_33 ;
break;
case V_117 :
V_24 -> V_26 |= V_35 ;
break;
default:
return - V_107 ;
}
V_24 -> V_48 = 0 ;
V_24 -> V_49 = V_118 ;
V_24 -> V_50 = 0 ;
V_24 -> V_3 = 0 ;
V_24 -> V_37 = V_119 ;
memset ( V_24 -> V_52 , 0 , V_118 ) ;
if ( V_17 -> V_26 & V_39 )
V_24 -> V_26 |= V_39 ;
F_13 ( V_2 -> V_46 , L_10 , V_57 , V_24 -> V_26 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 )
{
return F_21 ( V_2 ) ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_112 * V_15 = V_2 -> V_15 ;
struct V_23 * V_24 = F_12 ( V_15 ) ;
int V_61 ;
if ( ! ( V_24 -> V_26 & V_58 ) )
V_61 = F_44 ( V_2 ) ;
else
V_61 = F_19 ( V_2 , V_24 -> V_52 , V_24 -> V_48 , 1 ) ;
V_24 -> V_48 = 0 ;
return V_61 ;
}
static void F_59 ( struct V_112 * V_15 )
{
struct V_23 * V_24 = F_12 ( V_15 ) ;
T_1 * V_120 = ( T_1 * ) V_24 -> V_121 ;
unsigned int V_103 , V_122 ;
switch ( V_24 -> V_26 & V_28 ) {
case V_29 :
V_122 = V_114 ;
break;
case V_31 :
V_122 = V_115 ;
break;
case V_33 :
V_122 = V_116 ;
break;
case V_35 :
V_122 = V_117 ;
break;
default:
return;
}
for ( V_103 = 0 ; V_103 < V_122 / sizeof( T_1 ) ; V_103 ++ )
V_120 [ V_103 ] = F_60 ( F_1 ( V_24 -> V_2 ,
F_61 ( V_103 ) ) ) ;
}
static int F_62 ( struct V_112 * V_15 )
{
struct V_23 * V_24 = F_12 ( V_15 ) ;
if ( ! V_15 -> V_123 )
return - V_107 ;
memcpy ( V_15 -> V_123 , V_24 -> V_121 , V_24 -> V_113 ) ;
return 0 ;
}
static void F_63 ( struct V_112 * V_15 , int V_61 )
{
struct V_23 * V_24 = F_12 ( V_15 ) ;
struct V_1 * V_2 = V_24 -> V_2 ;
if ( ! V_61 && ( V_56 & V_2 -> V_26 ) ) {
F_59 ( V_15 ) ;
V_61 = F_62 ( V_15 ) ;
V_2 -> V_26 &= ~ ( V_56 | V_58 |
V_27 | V_82 |
V_124 | V_39 |
V_125 | V_126 |
V_60 ) ;
} else {
V_24 -> V_26 |= V_127 ;
}
F_64 ( V_2 -> V_128 , V_15 , V_61 ) ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
if ( ! ( V_27 & V_2 -> V_26 ) ) {
F_3 ( V_2 , V_45 , V_25 ) ;
F_3 ( V_2 , V_11 , 0 ) ;
F_3 ( V_2 , V_20 , 0 ) ;
F_3 ( V_2 , V_43 , 0 ) ;
V_2 -> V_61 = 0 ;
}
return 0 ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_112 * V_15 )
{
return F_67 ( V_2 -> V_128 , V_15 ) ;
}
static int F_68 ( struct V_129 * V_128 ,
struct V_112 * V_15 )
{
struct V_16 * V_17 = F_10 ( F_9 ( V_15 ) ) ;
struct V_1 * V_2 = F_50 ( V_17 ) ;
struct V_23 * V_24 ;
if ( ! V_2 )
return - V_130 ;
V_2 -> V_15 = V_15 ;
V_24 = F_12 ( V_15 ) ;
F_13 ( V_2 -> V_46 , L_11 ,
V_24 -> V_131 , V_15 -> V_105 ) ;
return F_65 ( V_2 , V_24 ) ;
}
static int F_69 ( struct V_129 * V_128 ,
struct V_112 * V_15 )
{
struct V_16 * V_17 = F_10 ( F_9 ( V_15 ) ) ;
struct V_1 * V_2 = F_50 ( V_17 ) ;
struct V_23 * V_24 ;
int V_61 = 0 ;
if ( ! V_2 )
return - V_130 ;
V_2 -> V_15 = V_15 ;
V_24 = F_12 ( V_15 ) ;
if ( V_24 -> V_131 == V_132 )
V_61 = F_57 ( V_2 ) ;
else if ( V_24 -> V_131 == V_133 )
V_61 = F_58 ( V_2 ) ;
if ( V_61 != - V_22 )
F_63 ( V_15 , V_61 ) ;
return 0 ;
}
static int F_70 ( struct V_112 * V_15 , unsigned int V_131 )
{
struct V_23 * V_24 = F_12 ( V_15 ) ;
struct V_16 * V_17 = F_71 ( V_15 -> V_134 . V_14 ) ;
struct V_1 * V_2 = V_17 -> V_2 ;
V_24 -> V_131 = V_131 ;
return F_66 ( V_2 , V_15 ) ;
}
static int F_72 ( struct V_112 * V_15 )
{
struct V_23 * V_24 = F_12 ( V_15 ) ;
int V_135 ;
if ( ! V_15 -> V_105 || ! ( V_24 -> V_26 & V_58 ) )
return 0 ;
V_24 -> V_50 = V_15 -> V_105 ;
V_24 -> V_51 = V_15 -> V_104 ;
V_24 -> V_3 = 0 ;
if ( ( V_24 -> V_48 + V_24 -> V_50 < V_24 -> V_49 ) ) {
F_14 ( V_24 ) ;
return 0 ;
}
V_135 = F_70 ( V_15 , V_132 ) ;
if ( V_24 -> V_26 & V_62 )
return V_135 ;
return 0 ;
}
static int F_73 ( struct V_112 * V_15 )
{
struct V_23 * V_24 = F_12 ( V_15 ) ;
V_24 -> V_26 |= V_62 ;
return F_70 ( V_15 , V_133 ) ;
}
static int F_74 ( struct V_112 * V_15 )
{
struct V_23 * V_24 = F_12 ( V_15 ) ;
struct V_16 * V_17 = F_10 ( F_9 ( V_15 ) ) ;
struct V_1 * V_2 = F_50 ( V_17 ) ;
int V_136 , V_137 ;
V_24 -> V_26 |= V_62 ;
if ( V_2 -> V_68 && F_54 ( V_15 ) )
V_24 -> V_26 &= ~ V_58 ;
V_136 = F_72 ( V_15 ) ;
if ( V_136 == - V_22 || V_136 == - V_99 )
return V_136 ;
V_137 = F_73 ( V_15 ) ;
return V_136 ? : V_137 ;
}
static int F_75 ( struct V_112 * V_15 )
{
return F_55 ( V_15 ) ? : F_74 ( V_15 ) ;
}
static int F_76 ( struct V_112 * V_15 , void * V_138 )
{
struct V_23 * V_24 = F_12 ( V_15 ) ;
struct V_16 * V_17 = F_10 ( F_9 ( V_15 ) ) ;
struct V_1 * V_2 = F_50 ( V_17 ) ;
T_1 * V_139 ;
unsigned int V_103 ;
while ( ! ( F_1 ( V_2 , V_7 ) & V_140 ) )
F_77 () ;
V_24 -> V_141 = F_78 ( sizeof( T_1 ) * ( 3 + V_142 ) ,
V_143 ) ;
V_139 = V_24 -> V_141 ;
* V_139 ++ = F_1 ( V_2 , V_43 ) ;
* V_139 ++ = F_1 ( V_2 , V_11 ) ;
* V_139 ++ = F_1 ( V_2 , V_45 ) ;
for ( V_103 = 0 ; V_103 < V_142 ; V_103 ++ )
* V_139 ++ = F_1 ( V_2 , F_79 ( V_103 ) ) ;
memcpy ( V_138 , V_24 , sizeof( * V_24 ) ) ;
return 0 ;
}
static int F_80 ( struct V_112 * V_15 , const void * V_144 )
{
struct V_23 * V_24 = F_12 ( V_15 ) ;
struct V_16 * V_17 = F_10 ( F_9 ( V_15 ) ) ;
struct V_1 * V_2 = F_50 ( V_17 ) ;
const T_1 * V_139 = V_144 ;
T_1 V_10 ;
unsigned int V_103 ;
memcpy ( V_24 , V_144 , sizeof( * V_24 ) ) ;
V_139 = V_24 -> V_141 ;
F_3 ( V_2 , V_43 , * V_139 ++ ) ;
F_3 ( V_2 , V_11 , * V_139 ++ ) ;
F_3 ( V_2 , V_45 , * V_139 ) ;
V_10 = * V_139 ++ | V_25 ;
F_3 ( V_2 , V_45 , V_10 ) ;
for ( V_103 = 0 ; V_103 < V_142 ; V_103 ++ )
F_3 ( V_2 , F_79 ( V_103 ) , * V_139 ++ ) ;
F_81 ( V_24 -> V_141 ) ;
return 0 ;
}
static int F_82 ( struct V_13 * V_14 ,
const T_3 * V_19 , unsigned int V_18 )
{
struct V_16 * V_17 = F_10 ( V_14 ) ;
if ( V_18 <= V_145 ) {
memcpy ( V_17 -> V_19 , V_19 , V_18 ) ;
V_17 -> V_18 = V_18 ;
} else {
return - V_72 ;
}
return 0 ;
}
static int F_83 ( struct V_146 * V_14 ,
const char * V_147 )
{
struct V_16 * V_17 = F_71 ( V_14 ) ;
F_84 ( F_85 ( V_14 ) ,
sizeof( struct V_23 ) ) ;
V_17 -> V_18 = 0 ;
if ( V_147 )
V_17 -> V_26 |= V_39 ;
return 0 ;
}
static int F_86 ( struct V_146 * V_14 )
{
return F_83 ( V_14 , NULL ) ;
}
static int F_87 ( struct V_146 * V_14 )
{
return F_83 ( V_14 , L_12 ) ;
}
static int F_88 ( struct V_146 * V_14 )
{
return F_83 ( V_14 , L_13 ) ;
}
static int F_89 ( struct V_146 * V_14 )
{
return F_83 ( V_14 , L_14 ) ;
}
static int F_90 ( struct V_146 * V_14 )
{
return F_83 ( V_14 , L_15 ) ;
}
static T_5 F_91 ( int V_148 , void * V_149 )
{
struct V_1 * V_2 = V_149 ;
int V_61 ;
if ( V_58 & V_2 -> V_26 ) {
if ( V_124 & V_2 -> V_26 ) {
V_2 -> V_26 &= ~ V_124 ;
goto V_150;
}
} else if ( V_82 & V_2 -> V_26 ) {
if ( V_77 & V_2 -> V_26 ) {
V_2 -> V_26 &= ~ V_77 ;
goto V_150;
}
}
return V_151 ;
V_150:
F_63 ( V_2 -> V_15 , V_61 ) ;
return V_151 ;
}
static T_5 F_92 ( int V_148 , void * V_149 )
{
struct V_1 * V_2 = V_149 ;
T_1 V_10 ;
V_10 = F_1 ( V_2 , V_7 ) ;
if ( V_10 & V_152 ) {
V_10 &= ~ V_152 ;
F_3 ( V_2 , V_7 , V_10 ) ;
V_2 -> V_26 |= V_124 ;
return V_153 ;
}
return V_154 ;
}
static int F_93 ( struct V_1 * V_2 )
{
unsigned int V_103 , V_155 ;
int V_61 ;
for ( V_103 = 0 ; V_103 < V_2 -> V_156 -> V_157 ; V_103 ++ ) {
for ( V_155 = 0 ; V_155 < V_2 -> V_156 -> V_158 [ V_103 ] . V_159 ; V_155 ++ ) {
V_61 = F_94 (
& V_2 -> V_156 -> V_158 [ V_103 ] . V_160 [ V_155 ] ) ;
if ( V_61 )
goto V_161;
}
}
return 0 ;
V_161:
F_24 ( V_2 -> V_46 , L_16 , V_103 , V_155 ) ;
for (; V_103 -- ; ) {
for (; V_155 -- ; )
F_95 (
& V_2 -> V_156 -> V_158 [ V_103 ] . V_160 [ V_155 ] ) ;
}
return V_61 ;
}
static int F_96 ( struct V_1 * V_2 )
{
unsigned int V_103 , V_155 ;
for ( V_103 = 0 ; V_103 < V_2 -> V_156 -> V_157 ; V_103 ++ ) {
for ( V_155 = 0 ; V_155 < V_2 -> V_156 -> V_158 [ V_103 ] . V_159 ; V_155 ++ )
F_95 (
& V_2 -> V_156 -> V_158 [ V_103 ] . V_160 [ V_155 ] ) ;
}
return 0 ;
}
static int F_97 ( struct V_1 * V_2 ,
struct V_162 * V_46 )
{
const struct V_163 * V_164 ;
int V_61 ;
V_164 = F_98 ( V_165 , V_46 ) ;
if ( ! V_164 ) {
F_24 ( V_46 , L_17 ) ;
return - V_107 ;
}
V_61 = F_99 ( V_46 -> V_166 , L_18 ,
& V_2 -> V_96 ) ;
V_2 -> V_156 = V_164 -> V_167 ;
return V_61 ;
}
static int F_100 ( struct V_168 * V_169 )
{
struct V_1 * V_2 ;
struct V_162 * V_46 = & V_169 -> V_46 ;
struct V_170 * V_171 ;
int V_135 , V_148 ;
V_2 = F_101 ( V_46 , sizeof( * V_2 ) , V_143 ) ;
if ( ! V_2 )
return - V_72 ;
V_171 = F_102 ( V_169 , V_172 , 0 ) ;
V_2 -> V_4 = F_103 ( V_46 , V_171 ) ;
if ( F_104 ( V_2 -> V_4 ) )
return F_105 ( V_2 -> V_4 ) ;
V_2 -> V_92 = V_171 -> V_173 ;
V_135 = F_97 ( V_2 , V_46 ) ;
if ( V_135 )
return V_135 ;
V_148 = F_106 ( V_169 , 0 ) ;
if ( V_148 < 0 ) {
F_24 ( V_46 , L_19 ) ;
return V_148 ;
}
V_135 = F_107 ( V_46 , V_148 , F_92 ,
F_91 , V_174 ,
F_108 ( V_46 ) , V_2 ) ;
if ( V_135 ) {
F_24 ( V_46 , L_20 ) ;
return V_135 ;
}
V_2 -> V_175 = F_109 ( & V_169 -> V_46 , NULL ) ;
if ( F_104 ( V_2 -> V_175 ) ) {
F_24 ( V_46 , L_21 ,
F_105 ( V_2 -> V_175 ) ) ;
return F_105 ( V_2 -> V_175 ) ;
}
V_135 = F_110 ( V_2 -> V_175 ) ;
if ( V_135 ) {
F_24 ( V_46 , L_22 , V_135 ) ;
return V_135 ;
}
V_2 -> V_176 = F_111 ( & V_169 -> V_46 , NULL ) ;
if ( ! F_104 ( V_2 -> V_176 ) ) {
F_112 ( V_2 -> V_176 ) ;
F_113 ( 2 ) ;
F_114 ( V_2 -> V_176 ) ;
}
V_2 -> V_46 = V_46 ;
F_115 ( V_169 , V_2 ) ;
V_135 = F_39 ( V_2 ) ;
if ( V_135 )
F_13 ( V_46 , L_23 ) ;
F_116 ( & V_110 . V_111 ) ;
F_117 ( & V_2 -> V_177 , & V_110 . V_178 ) ;
F_118 ( & V_110 . V_111 ) ;
V_2 -> V_128 = F_119 ( V_46 , 1 ) ;
if ( ! V_2 -> V_128 ) {
V_135 = - V_72 ;
goto V_179;
}
V_2 -> V_128 -> V_180 = F_68 ;
V_2 -> V_128 -> V_181 = F_69 ;
V_135 = F_120 ( V_2 -> V_128 ) ;
if ( V_135 )
goto V_182;
V_2 -> V_84 = F_1 ( V_2 , V_183 ) ;
V_135 = F_93 ( V_2 ) ;
if ( V_135 )
goto V_161;
F_121 ( V_46 , L_24 ,
F_1 ( V_2 , V_184 ) , V_2 -> V_84 ) ;
return 0 ;
V_161:
V_182:
F_122 ( V_2 -> V_128 ) ;
V_179:
F_116 ( & V_110 . V_111 ) ;
F_123 ( & V_2 -> V_177 ) ;
F_118 ( & V_110 . V_111 ) ;
if ( V_2 -> V_68 )
F_42 ( V_2 -> V_68 ) ;
F_124 ( V_2 -> V_175 ) ;
return V_135 ;
}
static int F_125 ( struct V_168 * V_169 )
{
static struct V_1 * V_2 ;
V_2 = F_126 ( V_169 ) ;
if ( ! V_2 )
return - V_130 ;
F_96 ( V_2 ) ;
F_122 ( V_2 -> V_128 ) ;
F_116 ( & V_110 . V_111 ) ;
F_123 ( & V_2 -> V_177 ) ;
F_118 ( & V_110 . V_111 ) ;
if ( V_2 -> V_68 )
F_42 ( V_2 -> V_68 ) ;
F_124 ( V_2 -> V_175 ) ;
return 0 ;
}
