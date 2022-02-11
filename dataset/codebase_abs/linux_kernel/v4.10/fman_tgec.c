static void F_1 ( struct V_1 T_1 * V_2 , T_2 * V_3 )
{
T_3 V_4 , V_5 ;
V_4 = ( T_3 ) ( V_3 [ 0 ] | V_3 [ 1 ] << 8 | V_3 [ 2 ] << 16 | V_3 [ 3 ] << 24 ) ;
V_5 = ( T_3 ) ( V_3 [ 4 ] | V_3 [ 5 ] << 8 ) ;
F_2 ( V_4 , & V_2 -> V_6 ) ;
F_2 ( V_5 , & V_2 -> V_7 ) ;
}
static void F_3 ( struct V_8 * V_9 )
{
V_9 -> V_10 = false ;
V_9 -> V_11 = false ;
V_9 -> V_12 = V_13 ;
V_9 -> V_14 = V_15 ;
V_9 -> V_16 = V_17 ;
}
static int F_4 ( struct V_1 T_1 * V_2 , struct V_8 * V_9 ,
T_3 V_18 )
{
T_3 V_19 ;
V_19 = V_20 ;
if ( V_9 -> V_10 )
V_19 |= V_21 ;
if ( V_9 -> V_11 )
V_19 |= V_22 ;
V_19 |= V_23 ;
F_2 ( V_19 , & V_2 -> V_24 ) ;
F_2 ( ( T_3 ) V_9 -> V_14 , & V_2 -> V_25 ) ;
F_2 ( V_9 -> V_16 , & V_2 -> V_16 ) ;
F_2 ( 0xffffffff , & V_2 -> V_26 ) ;
F_2 ( F_5 ( & V_2 -> V_27 ) | V_18 , & V_2 -> V_27 ) ;
return 0 ;
}
static int F_6 ( struct V_28 * V_29 )
{
if ( V_29 -> V_30 < V_31 ) {
F_7 ( L_1 ) ;
return - V_32 ;
}
if ( V_29 -> V_33 == 0 ) {
F_7 ( L_2 ) ;
return - V_32 ;
}
if ( ! V_29 -> V_34 ) {
F_7 ( L_3 ) ;
return - V_32 ;
}
if ( ! V_29 -> V_35 ) {
F_7 ( L_4 ) ;
return - V_32 ;
}
return 0 ;
}
static int F_8 ( enum V_36 V_37 )
{
T_3 V_38 ;
switch ( V_37 ) {
case V_39 :
V_38 = V_40 ;
break;
case V_41 :
V_38 = V_42 ;
break;
case V_43 :
V_38 = V_44 ;
break;
case V_45 :
V_38 = V_46 ;
break;
case V_47 :
V_38 = V_48 ;
break;
case V_49 :
V_38 = V_50 ;
break;
case V_51 :
V_38 = V_52 ;
break;
case V_53 :
V_38 = V_54 ;
break;
case V_55 :
V_38 = V_56 ;
break;
case V_57 :
V_38 = V_58 ;
break;
case V_59 :
V_38 = V_60 ;
break;
case V_61 :
V_38 = V_62 ;
break;
case V_63 :
V_38 = V_64 ;
break;
case V_65 :
V_38 = V_66 ;
break;
case V_67 :
V_38 = V_68 ;
break;
case V_69 :
V_38 = V_70 ;
break;
case V_71 :
V_38 = V_72 ;
break;
default:
V_38 = 0 ;
break;
}
return V_38 ;
}
static void F_9 ( void * V_73 )
{
struct V_28 * V_29 = (struct V_28 * ) V_73 ;
struct V_1 T_1 * V_2 = V_29 -> V_2 ;
T_3 V_74 ;
V_74 = F_5 ( & V_2 -> V_26 ) &
~ ( V_40 |
V_42 ) ;
V_74 &= F_5 ( & V_2 -> V_27 ) ;
F_2 ( V_74 , & V_2 -> V_26 ) ;
if ( V_74 & V_44 )
V_29 -> V_34 ( V_29 -> V_75 , V_43 ) ;
if ( V_74 & V_46 )
V_29 -> V_34 ( V_29 -> V_75 , V_45 ) ;
if ( V_74 & V_48 )
V_29 -> V_34 ( V_29 -> V_75 , V_47 ) ;
if ( V_74 & V_50 )
V_29 -> V_34 ( V_29 -> V_75 , V_49 ) ;
if ( V_74 & V_52 )
V_29 -> V_34 ( V_29 -> V_75 , V_51 ) ;
if ( V_74 & V_54 )
V_29 -> V_34 ( V_29 -> V_75 , V_53 ) ;
if ( V_74 & V_56 )
V_29 -> V_34 ( V_29 -> V_75 , V_55 ) ;
if ( V_74 & V_58 )
V_29 -> V_34 ( V_29 -> V_75 , V_57 ) ;
if ( V_74 & V_60 )
V_29 -> V_34 ( V_29 -> V_75 , V_59 ) ;
if ( V_74 & V_62 )
V_29 -> V_34 ( V_29 -> V_75 , V_61 ) ;
if ( V_74 & V_64 )
V_29 -> V_34 ( V_29 -> V_75 , V_63 ) ;
if ( V_74 & V_66 )
V_29 -> V_34 ( V_29 -> V_75 , V_65 ) ;
if ( V_74 & V_68 )
V_29 -> V_34 ( V_29 -> V_75 , V_67 ) ;
if ( V_74 & V_70 )
V_29 -> V_34 ( V_29 -> V_75 , V_69 ) ;
if ( V_74 & V_72 )
V_29 -> V_34 ( V_29 -> V_75 , V_71 ) ;
}
static void F_10 ( struct V_28 * V_29 )
{
F_11 ( V_29 -> V_76 , V_77 , V_29 -> V_78 ,
V_79 ) ;
F_12 ( V_29 -> V_80 ) ;
V_29 -> V_80 = NULL ;
F_12 ( V_29 -> V_81 ) ;
V_29 -> V_81 = NULL ;
}
static bool F_13 ( struct V_8 * V_9 )
{
if ( ! V_9 )
return true ;
return false ;
}
int F_14 ( struct V_28 * V_29 , enum V_82 V_83 )
{
struct V_1 T_1 * V_2 = V_29 -> V_2 ;
T_3 V_19 ;
if ( ! F_13 ( V_29 -> V_9 ) )
return - V_32 ;
V_19 = F_5 ( & V_2 -> V_24 ) ;
if ( V_83 & V_84 )
V_19 |= V_85 ;
if ( V_83 & V_86 )
V_19 |= V_87 ;
F_2 ( V_19 , & V_2 -> V_24 ) ;
return 0 ;
}
int F_15 ( struct V_28 * V_29 , enum V_82 V_83 )
{
struct V_1 T_1 * V_2 = V_29 -> V_2 ;
T_3 V_19 ;
if ( ! F_13 ( V_29 -> V_9 ) )
return - V_32 ;
V_19 = F_5 ( & V_2 -> V_24 ) ;
if ( V_83 & V_84 )
V_19 &= ~ V_85 ;
if ( V_83 & V_86 )
V_19 &= ~ V_87 ;
F_2 ( V_19 , & V_2 -> V_24 ) ;
return 0 ;
}
int F_16 ( struct V_28 * V_29 , bool V_88 )
{
struct V_1 T_1 * V_2 = V_29 -> V_2 ;
T_3 V_19 ;
if ( ! F_13 ( V_29 -> V_9 ) )
return - V_32 ;
V_19 = F_5 ( & V_2 -> V_24 ) ;
if ( V_88 )
V_19 |= V_21 ;
else
V_19 &= ~ V_21 ;
F_2 ( V_19 , & V_2 -> V_24 ) ;
return 0 ;
}
int F_17 ( struct V_28 * V_29 , T_4 V_88 )
{
if ( F_13 ( V_29 -> V_9 ) )
return - V_32 ;
V_29 -> V_9 -> V_14 = V_88 ;
return 0 ;
}
int F_18 ( struct V_28 * V_29 , T_2 T_5 V_89 ,
T_4 V_90 , T_4 T_5 V_91 )
{
struct V_1 T_1 * V_2 = V_29 -> V_2 ;
if ( ! F_13 ( V_29 -> V_9 ) )
return - V_32 ;
F_2 ( ( T_3 ) V_90 , & V_2 -> V_16 ) ;
return 0 ;
}
int F_19 ( struct V_28 * V_29 , bool V_92 )
{
struct V_1 T_1 * V_2 = V_29 -> V_2 ;
T_3 V_19 ;
if ( ! F_13 ( V_29 -> V_9 ) )
return - V_32 ;
V_19 = F_5 ( & V_2 -> V_24 ) ;
if ( ! V_92 )
V_19 |= V_22 ;
else
V_19 &= ~ V_22 ;
F_2 ( V_19 , & V_2 -> V_24 ) ;
return 0 ;
}
int F_20 ( struct V_28 * V_29 , T_6 * V_93 )
{
if ( ! F_13 ( V_29 -> V_9 ) )
return - V_32 ;
V_29 -> V_33 = F_21 ( * V_93 ) ;
F_1 ( V_29 -> V_2 , ( T_2 * ) ( * V_93 ) ) ;
return 0 ;
}
int F_22 ( struct V_28 * V_29 , T_6 * V_94 )
{
struct V_1 T_1 * V_2 = V_29 -> V_2 ;
struct V_95 * V_96 ;
T_3 V_97 = 0xFFFFFFFF , V_98 ;
T_7 V_33 ;
if ( ! F_13 ( V_29 -> V_9 ) )
return - V_32 ;
V_33 = F_21 ( * V_94 ) ;
if ( ! ( V_33 & V_99 ) ) {
F_7 ( L_5 ) ;
return - V_32 ;
}
V_97 = F_23 ( V_97 , ( T_2 * ) V_94 , V_100 ) ;
V_97 = F_24 ( V_97 ) ;
V_98 = ( V_97 >> V_101 ) & V_102 ;
V_96 = F_25 ( sizeof( * V_96 ) , V_103 ) ;
if ( ! V_96 )
return - V_104 ;
V_96 -> V_33 = V_33 ;
F_26 ( & V_96 -> V_105 ) ;
F_27 ( & V_96 -> V_105 ,
& V_29 -> V_80 -> V_106 [ V_98 ] ) ;
F_2 ( ( V_98 | V_107 ) , & V_2 -> V_108 ) ;
return 0 ;
}
int F_28 ( struct V_28 * V_29 , T_6 * V_94 )
{
struct V_1 T_1 * V_2 = V_29 -> V_2 ;
struct V_95 * V_96 = NULL ;
struct V_109 * V_110 ;
T_3 V_97 = 0xFFFFFFFF , V_98 ;
T_7 V_33 ;
if ( ! F_13 ( V_29 -> V_9 ) )
return - V_32 ;
V_33 = ( ( * ( T_7 * ) V_94 ) >> 16 ) ;
V_97 = F_23 ( V_97 , ( T_2 * ) V_94 , V_100 ) ;
V_97 = F_24 ( V_97 ) ;
V_98 = ( V_97 >> V_101 ) & V_102 ;
F_29 (pos, &tgec->multicast_addr_hash->lsts[hash]) {
V_96 = F_30 ( V_110 ) ;
if ( V_96 -> V_33 == V_33 ) {
F_31 ( & V_96 -> V_105 ) ;
F_32 ( V_96 ) ;
break;
}
}
if ( F_33 ( & V_29 -> V_80 -> V_106 [ V_98 ] ) )
F_2 ( ( V_98 & ~ V_107 ) ,
& V_2 -> V_108 ) ;
return 0 ;
}
int F_34 ( struct V_28 * V_29 , T_3 * V_111 )
{
struct V_1 T_1 * V_2 = V_29 -> V_2 ;
if ( ! F_13 ( V_29 -> V_9 ) )
return - V_32 ;
* V_111 = F_5 ( & V_2 -> V_112 ) ;
return 0 ;
}
int F_35 ( struct V_28 * V_29 ,
enum V_36 V_37 , bool V_113 )
{
struct V_1 T_1 * V_2 = V_29 -> V_2 ;
T_3 V_38 = 0 ;
if ( ! F_13 ( V_29 -> V_9 ) )
return - V_32 ;
V_38 = F_8 ( V_37 ) ;
if ( V_38 ) {
if ( V_113 )
V_29 -> V_114 |= V_38 ;
else
V_29 -> V_114 &= ~ V_38 ;
} else {
F_7 ( L_6 ) ;
return - V_32 ;
}
if ( V_113 )
F_2 ( F_5 ( & V_2 -> V_27 ) | V_38 , & V_2 -> V_27 ) ;
else
F_2 ( F_5 ( & V_2 -> V_27 ) & ~ V_38 , & V_2 -> V_27 ) ;
return 0 ;
}
int F_36 ( struct V_28 * V_29 )
{
struct V_8 * V_9 ;
T_6 V_94 ;
int V_115 ;
if ( F_13 ( V_29 -> V_9 ) )
return - V_32 ;
if ( V_116 &&
( F_37 ( V_29 -> V_76 , V_29 -> V_78 ) != 0 ) ) {
F_7 ( L_7 ) ;
return - V_32 ;
}
V_115 = F_6 ( V_29 ) ;
if ( V_115 )
return V_115 ;
V_9 = V_29 -> V_9 ;
F_38 ( V_29 -> V_33 , V_94 ) ;
F_1 ( V_29 -> V_2 , ( T_2 * ) V_94 ) ;
if ( V_29 -> V_117 . V_118 <= 2 )
V_29 -> V_114 &= ~ ( V_44 |
V_46 ) ;
V_115 = F_4 ( V_29 -> V_2 , V_9 , V_29 -> V_114 ) ;
if ( V_115 ) {
F_10 ( V_29 ) ;
F_7 ( L_8 ) ;
return V_115 ;
}
V_115 = F_39 ( V_29 -> V_76 , V_29 -> V_78 ,
V_9 -> V_14 ) ;
if ( V_115 ) {
F_7 ( L_9 ) ;
F_10 ( V_29 ) ;
return - V_32 ;
}
if ( V_29 -> V_117 . V_118 == 2 ) {
struct V_1 T_1 * V_2 = V_29 -> V_2 ;
T_3 V_19 ;
V_19 = ( F_5 ( & V_2 -> V_119 ) &
~ V_120 ) | 12 ;
F_2 ( V_19 , & V_2 -> V_119 ) ;
}
V_29 -> V_80 = F_40 ( V_121 ) ;
if ( ! V_29 -> V_80 ) {
F_10 ( V_29 ) ;
F_7 ( L_10 ) ;
return - V_104 ;
}
V_29 -> V_81 = F_40 ( V_121 ) ;
if ( ! V_29 -> V_81 ) {
F_10 ( V_29 ) ;
F_7 ( L_10 ) ;
return - V_104 ;
}
F_41 ( V_29 -> V_76 , V_77 , V_29 -> V_78 ,
V_79 , F_9 , V_29 ) ;
F_32 ( V_9 ) ;
V_29 -> V_9 = NULL ;
return 0 ;
}
int F_42 ( struct V_28 * V_29 )
{
F_10 ( V_29 ) ;
F_32 ( V_29 -> V_9 ) ;
F_32 ( V_29 ) ;
return 0 ;
}
struct V_28 * F_43 ( struct V_122 * V_123 )
{
struct V_28 * V_29 ;
struct V_8 * V_9 ;
void T_1 * V_124 ;
V_124 = V_123 -> V_124 ;
V_29 = F_44 ( sizeof( * V_29 ) , V_103 ) ;
if ( ! V_29 )
return NULL ;
V_9 = F_44 ( sizeof( * V_9 ) , V_103 ) ;
if ( ! V_9 ) {
F_42 ( V_29 ) ;
return NULL ;
}
V_29 -> V_9 = V_9 ;
F_3 ( V_9 ) ;
V_29 -> V_2 = V_124 ;
V_29 -> V_33 = F_21 ( V_123 -> V_33 ) ;
V_29 -> V_30 = V_123 -> V_30 ;
V_29 -> V_78 = V_123 -> V_78 ;
V_29 -> V_114 = ( V_40 |
V_44 |
V_46 |
V_48 |
V_50 |
V_52 |
V_54 |
V_56 |
V_58 |
V_60 |
V_62 |
V_64 |
V_66 |
V_70 |
V_72 ) ;
V_29 -> V_34 = V_123 -> V_34 ;
V_29 -> V_35 = V_123 -> V_35 ;
V_29 -> V_75 = V_123 -> V_75 ;
V_29 -> V_76 = V_123 -> V_76 ;
F_45 ( V_29 -> V_76 , & V_29 -> V_117 ) ;
return V_29 ;
}
