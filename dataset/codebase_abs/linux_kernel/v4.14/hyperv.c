static inline T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( & V_2 -> V_3 [ V_3 ] ) ;
}
static inline int F_3 ( T_1 V_4 )
{
if ( V_4 & V_5 )
return - 1 ;
return V_4 & V_6 ;
}
static bool F_4 ( struct V_1 * V_2 ,
int V_7 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < F_5 ( V_2 -> V_3 ) ; V_8 ++ ) {
if ( F_3 ( F_1 ( V_2 , V_8 ) ) == V_7 )
return true ;
}
return false ;
}
static bool F_6 ( struct V_1 * V_2 ,
int V_7 )
{
int V_8 ;
T_1 V_4 ;
for ( V_8 = 0 ; V_8 < F_5 ( V_2 -> V_3 ) ; V_8 ++ ) {
V_4 = F_1 ( V_2 , V_8 ) ;
if ( F_3 ( V_4 ) == V_7 &&
V_4 & V_9 )
return true ;
}
return false ;
}
static int F_7 ( struct V_1 * V_2 , int V_3 ,
T_1 V_10 , bool V_11 )
{
int V_7 ;
V_7 = V_10 & V_6 ;
if ( V_7 < 16 && ! V_11 )
return 1 ;
F_8 ( & V_2 -> V_3 [ V_3 ] , V_10 ) ;
if ( F_4 ( V_2 , V_7 ) )
F_9 ( V_7 , V_2 -> V_12 ) ;
else
F_10 ( V_7 , V_2 -> V_12 ) ;
if ( F_6 ( V_2 , V_7 ) )
F_9 ( V_7 , V_2 -> V_13 ) ;
else
F_10 ( V_7 , V_2 -> V_13 ) ;
F_11 ( V_14 , F_12 ( V_2 ) ) ;
return 0 ;
}
static struct V_15 * F_13 ( struct V_16 * V_16 , T_2 V_17 )
{
struct V_15 * V_18 = NULL ;
int V_8 ;
if ( V_17 < V_19 )
V_18 = F_14 ( V_16 , V_17 ) ;
if ( V_18 && F_15 ( V_18 ) -> V_20 == V_17 )
return V_18 ;
F_16 (i, vcpu, kvm)
if ( F_15 ( V_18 ) -> V_20 == V_17 )
return V_18 ;
return NULL ;
}
static struct V_1 * F_17 ( struct V_16 * V_16 , T_2 V_17 )
{
struct V_15 * V_18 ;
struct V_1 * V_2 ;
V_18 = F_13 ( V_16 , V_17 ) ;
if ( ! V_18 )
return NULL ;
V_2 = F_18 ( V_18 ) ;
return ( V_2 -> V_21 ) ? V_2 : NULL ;
}
static void F_19 ( struct V_1 * V_2 ,
T_2 V_3 )
{
struct V_15 * V_18 = F_12 ( V_2 ) ;
struct V_22 * V_22 ;
T_3 V_23 ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
V_23 = V_2 -> V_27 & V_28 ;
V_22 = F_20 ( V_18 , V_23 >> V_29 ) ;
if ( F_21 ( V_22 ) ) {
F_22 ( V_18 , L_1 ,
V_23 ) ;
return;
}
V_27 = F_23 ( V_22 ) ;
V_25 = & V_27 -> V_30 [ V_3 ] ;
V_25 -> V_31 . V_32 . V_33 = 0 ;
F_24 ( V_27 ) ;
F_25 ( V_22 ) ;
F_26 ( V_18 , V_23 >> V_29 ) ;
}
static void F_27 ( struct V_15 * V_18 , T_2 V_3 )
{
struct V_16 * V_16 = V_18 -> V_16 ;
struct V_1 * V_2 = F_18 ( V_18 ) ;
struct V_34 * V_35 = F_15 ( V_18 ) ;
struct V_36 * V_37 ;
int V_38 , V_39 , V_40 ;
F_28 ( V_18 -> V_41 , V_3 ) ;
if ( V_2 -> V_27 & V_42 )
F_19 ( V_2 , V_3 ) ;
V_40 = 0 ;
for ( V_39 = 0 ; V_39 < F_5 ( V_35 -> V_37 ) ; V_39 ++ ) {
V_37 = & V_35 -> V_37 [ V_39 ] ;
if ( V_37 -> V_33 &&
( V_37 -> V_43 & V_44 ) &&
F_29 ( V_37 -> V_43 ) == V_3 ) {
F_30 ( V_37 -> V_45 ,
V_35 -> V_46 ) ;
V_40 ++ ;
}
}
if ( V_40 )
F_11 ( V_47 , V_18 ) ;
V_39 = F_31 ( & V_16 -> V_48 ) ;
V_38 = F_32 ( & V_2 -> V_49 [ V_3 ] ) ;
if ( V_38 != - 1 )
F_33 ( V_16 , V_38 ) ;
F_34 ( & V_16 -> V_48 , V_39 ) ;
}
static void F_35 ( struct V_1 * V_2 , T_2 V_50 )
{
struct V_15 * V_18 = F_12 ( V_2 ) ;
struct V_34 * V_35 = & V_18 -> V_51 . V_52 ;
V_35 -> exit . type = V_53 ;
V_35 -> exit . V_54 . V_2 . V_50 = V_50 ;
V_35 -> exit . V_54 . V_2 . V_55 = V_2 -> V_55 ;
V_35 -> exit . V_54 . V_2 . V_56 = V_2 -> V_56 ;
V_35 -> exit . V_54 . V_2 . V_27 = V_2 -> V_27 ;
F_11 ( V_57 , V_18 ) ;
}
static int F_36 ( struct V_1 * V_2 ,
T_2 V_50 , T_1 V_10 , bool V_11 )
{
struct V_15 * V_18 = F_12 ( V_2 ) ;
int V_58 ;
if ( ! V_2 -> V_21 )
return 1 ;
F_37 ( V_18 -> V_41 , V_50 , V_10 , V_11 ) ;
V_58 = 0 ;
switch ( V_50 ) {
case V_59 :
V_2 -> V_55 = V_10 ;
if ( ! V_11 )
F_35 ( V_2 , V_50 ) ;
break;
case V_60 :
if ( ! V_11 ) {
V_58 = 1 ;
break;
}
V_2 -> V_61 = V_10 ;
break;
case V_62 :
if ( ( V_10 & V_63 ) && ! V_11 &&
! V_2 -> V_64 )
if ( F_38 ( V_18 -> V_16 ,
V_10 & V_28 , V_65 ) ) {
V_58 = 1 ;
break;
}
V_2 -> V_56 = V_10 ;
if ( ! V_11 )
F_35 ( V_2 , V_50 ) ;
break;
case V_66 :
if ( ( V_10 & V_42 ) && ! V_11 &&
! V_2 -> V_64 )
if ( F_38 ( V_18 -> V_16 ,
V_10 & V_28 , V_65 ) ) {
V_58 = 1 ;
break;
}
V_2 -> V_27 = V_10 ;
if ( ! V_11 )
F_35 ( V_2 , V_50 ) ;
break;
case V_67 : {
int V_8 ;
for ( V_8 = 0 ; V_8 < F_5 ( V_2 -> V_3 ) ; V_8 ++ )
F_27 ( V_18 , V_8 ) ;
break;
}
case V_68 ... V_69 :
V_58 = F_7 ( V_2 , V_50 - V_68 , V_10 , V_11 ) ;
break;
default:
V_58 = 1 ;
break;
}
return V_58 ;
}
static int F_39 ( struct V_1 * V_2 , T_2 V_50 , T_1 * V_70 )
{
int V_58 ;
if ( ! V_2 -> V_21 )
return 1 ;
V_58 = 0 ;
switch ( V_50 ) {
case V_59 :
* V_70 = V_2 -> V_55 ;
break;
case V_60 :
* V_70 = V_2 -> V_61 ;
break;
case V_62 :
* V_70 = V_2 -> V_56 ;
break;
case V_66 :
* V_70 = V_2 -> V_27 ;
break;
case V_67 :
* V_70 = 0 ;
break;
case V_68 ... V_69 :
* V_70 = F_2 ( & V_2 -> V_3 [ V_50 - V_68 ] ) ;
break;
default:
V_58 = 1 ;
break;
}
return V_58 ;
}
static int F_40 ( struct V_1 * V_2 , T_2 V_3 )
{
struct V_15 * V_18 = F_12 ( V_2 ) ;
struct V_71 V_72 ;
int V_58 , V_7 ;
if ( V_3 >= F_5 ( V_2 -> V_3 ) )
return - V_73 ;
V_7 = F_3 ( F_1 ( V_2 , V_3 ) ) ;
if ( V_7 < 0 )
return - V_74 ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
V_72 . V_75 = V_76 ;
V_72 . V_77 = V_78 ;
V_72 . V_79 = V_80 ;
V_72 . V_7 = V_7 ;
V_72 . V_81 = 1 ;
V_58 = F_41 ( V_18 -> V_16 , V_18 -> V_51 . V_82 , & V_72 , NULL ) ;
F_42 ( V_18 -> V_41 , V_3 , V_72 . V_7 , V_58 ) ;
return V_58 ;
}
int F_43 ( struct V_16 * V_16 , T_2 V_17 , T_2 V_3 )
{
struct V_1 * V_2 ;
V_2 = F_17 ( V_16 , V_17 ) ;
if ( ! V_2 )
return - V_73 ;
return F_40 ( V_2 , V_3 ) ;
}
void F_44 ( struct V_15 * V_18 , int V_7 )
{
struct V_1 * V_2 = F_18 ( V_18 ) ;
int V_8 ;
F_45 ( V_18 -> V_41 , V_7 ) ;
for ( V_8 = 0 ; V_8 < F_5 ( V_2 -> V_3 ) ; V_8 ++ )
if ( F_3 ( F_1 ( V_2 , V_8 ) ) == V_7 )
F_27 ( V_18 , V_8 ) ;
}
static int F_46 ( struct V_16 * V_16 , T_2 V_17 , T_2 V_3 , int V_38 )
{
struct V_1 * V_2 ;
V_2 = F_17 ( V_16 , V_17 ) ;
if ( ! V_2 )
return - V_73 ;
if ( V_3 >= F_5 ( V_2 -> V_49 ) )
return - V_73 ;
F_47 ( & V_2 -> V_49 [ V_3 ] , V_38 ) ;
return 0 ;
}
void F_48 ( struct V_16 * V_16 )
{
struct V_83 * V_84 ;
struct V_85 * V_86 ;
T_2 V_38 ;
V_84 = F_49 ( V_16 -> V_87 , & V_16 -> V_48 ,
F_50 ( & V_16 -> V_88 ) ) ;
for ( V_38 = 0 ; V_38 < V_84 -> V_89 ; V_38 ++ ) {
F_51 (e, &irq_rt->map[gsi], link) {
if ( V_86 -> type == V_90 )
F_46 ( V_16 , V_86 -> V_91 . V_18 ,
V_86 -> V_91 . V_3 , V_38 ) ;
}
}
}
static void F_52 ( struct V_1 * V_2 )
{
int V_8 ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_61 = V_92 ;
for ( V_8 = 0 ; V_8 < F_5 ( V_2 -> V_3 ) ; V_8 ++ ) {
F_8 ( & V_2 -> V_3 [ V_8 ] , V_5 ) ;
F_47 ( & V_2 -> V_49 [ V_8 ] , - 1 ) ;
}
}
static T_1 F_53 ( struct V_16 * V_16 )
{
struct V_93 * V_94 = & V_16 -> V_51 . V_52 ;
struct V_15 * V_18 ;
T_1 V_95 ;
if ( ! V_94 -> V_96 . V_97 )
return F_54 ( F_55 ( V_16 ) , 100 ) ;
V_18 = F_14 ( V_16 , 0 ) ;
V_95 = F_56 ( V_18 , F_57 () ) ;
return F_58 ( V_95 , V_94 -> V_96 . V_98 , 64 )
+ V_94 -> V_96 . V_99 ;
}
static void F_59 ( struct V_36 * V_37 ,
bool V_100 )
{
struct V_15 * V_18 = F_60 ( V_37 ) ;
F_30 ( V_37 -> V_45 ,
F_15 ( V_18 ) -> V_46 ) ;
F_11 ( V_47 , V_18 ) ;
if ( V_100 )
F_61 ( V_18 ) ;
}
static void F_62 ( struct V_36 * V_37 )
{
struct V_15 * V_18 = F_60 ( V_37 ) ;
F_63 ( F_60 ( V_37 ) -> V_41 ,
V_37 -> V_45 ) ;
F_64 ( & V_37 -> V_101 ) ;
F_65 ( V_37 -> V_45 ,
F_15 ( V_18 ) -> V_46 ) ;
V_37 -> V_33 = false ;
V_37 -> V_102 = 0 ;
}
static enum V_103 F_66 ( struct V_104 * V_101 )
{
struct V_36 * V_37 ;
V_37 = F_67 ( V_101 , struct V_36 , V_101 ) ;
F_68 ( F_60 ( V_37 ) -> V_41 ,
V_37 -> V_45 ) ;
F_59 ( V_37 , true ) ;
return V_105 ;
}
static int F_69 ( struct V_36 * V_37 )
{
T_1 V_106 ;
T_4 V_107 ;
V_106 = F_53 ( F_60 ( V_37 ) -> V_16 ) ;
V_107 = F_70 () ;
if ( V_37 -> V_43 & V_108 ) {
if ( V_37 -> V_102 ) {
if ( V_106 >= V_37 -> V_102 ) {
T_1 V_109 ;
F_71 ( V_106 - V_37 -> V_102 ,
V_37 -> V_110 , & V_109 ) ;
V_37 -> V_102 =
V_106 + ( V_37 -> V_110 - V_109 ) ;
}
} else
V_37 -> V_102 = V_106 + V_37 -> V_110 ;
F_72 (
F_60 ( V_37 ) -> V_41 ,
V_37 -> V_45 ,
V_106 , V_37 -> V_102 ) ;
F_73 ( & V_37 -> V_101 ,
F_74 ( V_107 ,
100 * ( V_37 -> V_102 - V_106 ) ) ,
V_111 ) ;
return 0 ;
}
V_37 -> V_102 = V_37 -> V_110 ;
if ( V_106 >= V_37 -> V_110 ) {
F_59 ( V_37 , false ) ;
return 0 ;
}
F_75 ( F_60 ( V_37 ) -> V_41 ,
V_37 -> V_45 ,
V_106 , V_37 -> V_110 ) ;
F_73 ( & V_37 -> V_101 ,
F_74 ( V_107 , 100 * ( V_37 -> V_110 - V_106 ) ) ,
V_111 ) ;
return 0 ;
}
static int F_76 ( struct V_36 * V_37 , T_1 V_43 ,
bool V_11 )
{
F_77 ( F_60 ( V_37 ) -> V_41 ,
V_37 -> V_45 , V_43 , V_11 ) ;
F_62 ( V_37 ) ;
if ( ( V_37 -> V_43 & V_44 ) && F_29 ( V_43 ) == 0 )
V_43 &= ~ V_44 ;
V_37 -> V_43 = V_43 ;
F_59 ( V_37 , false ) ;
return 0 ;
}
static int F_78 ( struct V_36 * V_37 , T_1 V_110 ,
bool V_11 )
{
F_79 ( F_60 ( V_37 ) -> V_41 ,
V_37 -> V_45 , V_110 , V_11 ) ;
F_62 ( V_37 ) ;
V_37 -> V_110 = V_110 ;
if ( V_37 -> V_110 == 0 )
V_37 -> V_43 &= ~ V_44 ;
else if ( V_37 -> V_43 & V_112 )
V_37 -> V_43 |= V_44 ;
F_59 ( V_37 , false ) ;
return 0 ;
}
static int F_80 ( struct V_36 * V_37 , T_1 * V_113 )
{
* V_113 = V_37 -> V_43 ;
return 0 ;
}
static int F_81 ( struct V_36 * V_37 , T_1 * V_114 )
{
* V_114 = V_37 -> V_110 ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 , T_2 V_3 ,
struct V_24 * V_115 )
{
struct V_15 * V_18 = F_12 ( V_2 ) ;
struct V_22 * V_22 ;
T_3 V_23 ;
struct V_24 * V_116 ;
int V_117 ;
struct V_26 * V_27 ;
if ( ! ( V_2 -> V_27 & V_42 ) )
return - V_74 ;
V_23 = V_2 -> V_27 & V_28 ;
V_22 = F_20 ( V_18 , V_23 >> V_29 ) ;
if ( F_21 ( V_22 ) )
return - V_118 ;
V_27 = F_23 ( V_22 ) ;
V_116 = & V_27 -> V_30 [ V_3 ] ;
if ( F_83 ( & V_116 -> V_31 . V_119 , V_120 ,
V_115 -> V_31 . V_119 ) != V_120 ) {
V_116 -> V_31 . V_32 . V_33 = 1 ;
V_117 = - V_121 ;
} else {
memcpy ( & V_116 -> V_54 . V_122 , & V_115 -> V_54 . V_122 ,
V_115 -> V_31 . V_123 ) ;
V_116 -> V_31 . V_119 = V_115 -> V_31 . V_119 ;
V_116 -> V_31 . V_123 = V_115 -> V_31 . V_123 ;
V_117 = F_40 ( V_2 , V_3 ) ;
if ( V_117 >= 1 )
V_117 = 0 ;
else if ( V_117 == 0 )
V_117 = - V_118 ;
}
F_24 ( V_27 ) ;
F_25 ( V_22 ) ;
F_26 ( V_18 , V_23 >> V_29 ) ;
return V_117 ;
}
static int F_84 ( struct V_36 * V_37 )
{
struct V_15 * V_18 = F_60 ( V_37 ) ;
struct V_24 * V_25 = & V_37 -> V_25 ;
struct V_124 * V_122 =
(struct V_124 * ) & V_25 -> V_54 . V_122 ;
V_122 -> V_125 = V_37 -> V_102 ;
V_122 -> V_126 = F_53 ( V_18 -> V_16 ) ;
return F_82 ( F_18 ( V_18 ) ,
F_29 ( V_37 -> V_43 ) , V_25 ) ;
}
static void F_85 ( struct V_36 * V_37 )
{
int V_117 ;
V_37 -> V_33 = true ;
V_117 = F_84 ( V_37 ) ;
F_86 ( F_60 ( V_37 ) -> V_41 ,
V_37 -> V_45 , V_117 ) ;
if ( ! V_117 ) {
V_37 -> V_33 = false ;
if ( ! ( V_37 -> V_43 & V_108 ) )
V_37 -> V_43 &= ~ V_44 ;
}
}
void F_87 ( struct V_15 * V_18 )
{
struct V_34 * V_35 = F_15 ( V_18 ) ;
struct V_36 * V_37 ;
T_1 V_106 , V_102 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < F_5 ( V_35 -> V_37 ) ; V_8 ++ )
if ( F_88 ( V_8 , V_35 -> V_46 ) ) {
V_37 = & V_35 -> V_37 [ V_8 ] ;
if ( V_37 -> V_43 & V_44 ) {
V_102 = V_37 -> V_102 ;
if ( V_102 ) {
V_106 =
F_53 ( V_18 -> V_16 ) ;
if ( V_106 >= V_102 )
F_85 ( V_37 ) ;
}
if ( ( V_37 -> V_43 & V_44 ) &&
V_37 -> V_110 ) {
if ( ! V_37 -> V_33 )
F_69 ( V_37 ) ;
} else
F_62 ( V_37 ) ;
}
}
}
void F_89 ( struct V_15 * V_18 )
{
struct V_34 * V_35 = F_15 ( V_18 ) ;
int V_8 ;
for ( V_8 = 0 ; V_8 < F_5 ( V_35 -> V_37 ) ; V_8 ++ )
F_62 ( & V_35 -> V_37 [ V_8 ] ) ;
}
static void F_90 ( struct V_36 * V_37 )
{
struct V_24 * V_25 = & V_37 -> V_25 ;
struct V_124 * V_122 =
(struct V_124 * ) & V_25 -> V_54 . V_122 ;
memset ( & V_25 -> V_31 , 0 , sizeof( V_25 -> V_31 ) ) ;
V_25 -> V_31 . V_119 = V_127 ;
V_25 -> V_31 . V_123 = sizeof( * V_122 ) ;
V_122 -> V_128 = V_37 -> V_45 ;
V_122 -> V_125 = 0 ;
V_122 -> V_126 = 0 ;
}
static void F_91 ( struct V_36 * V_37 , int V_128 )
{
memset ( V_37 , 0 , sizeof( * V_37 ) ) ;
V_37 -> V_45 = V_128 ;
F_92 ( & V_37 -> V_101 , V_129 , V_111 ) ;
V_37 -> V_101 . V_130 = F_66 ;
F_90 ( V_37 ) ;
}
void F_93 ( struct V_15 * V_18 )
{
struct V_34 * V_35 = F_15 ( V_18 ) ;
int V_8 ;
F_52 ( & V_35 -> V_2 ) ;
F_94 ( V_35 -> V_46 , V_131 ) ;
for ( V_8 = 0 ; V_8 < F_5 ( V_35 -> V_37 ) ; V_8 ++ )
F_91 ( & V_35 -> V_37 [ V_8 ] , V_8 ) ;
}
void F_95 ( struct V_15 * V_18 )
{
struct V_34 * V_35 = F_15 ( V_18 ) ;
V_35 -> V_20 = F_96 ( V_18 ) ;
}
int F_97 ( struct V_15 * V_18 , bool V_64 )
{
struct V_1 * V_2 = F_18 ( V_18 ) ;
F_98 ( V_18 ) ;
V_2 -> V_21 = true ;
V_2 -> V_64 = V_64 ;
return 0 ;
}
static bool F_99 ( T_2 V_50 )
{
bool V_117 = false ;
switch ( V_50 ) {
case V_132 :
case V_133 :
case V_134 :
case V_135 :
case V_136 :
case V_137 ... V_138 :
case V_139 :
V_117 = true ;
break;
}
return V_117 ;
}
static int F_100 ( struct V_15 * V_18 ,
T_2 V_45 , T_1 * V_70 )
{
struct V_93 * V_94 = & V_18 -> V_16 -> V_51 . V_52 ;
if ( F_101 ( V_45 >= F_5 ( V_94 -> V_140 ) ) )
return - V_73 ;
* V_70 = V_94 -> V_140 [ V_45 ] ;
return 0 ;
}
static int F_102 ( struct V_15 * V_18 , T_1 * V_70 )
{
struct V_93 * V_94 = & V_18 -> V_16 -> V_51 . V_52 ;
* V_70 = V_94 -> V_141 ;
return 0 ;
}
static int F_103 ( struct V_15 * V_18 , T_1 V_10 , bool V_11 )
{
struct V_93 * V_94 = & V_18 -> V_16 -> V_51 . V_52 ;
if ( V_11 )
V_94 -> V_141 = V_10 & V_142 ;
if ( ! V_11 && ( V_10 & V_142 ) ) {
F_104 ( V_18 , L_2 ,
V_94 -> V_140 [ 0 ] ,
V_94 -> V_140 [ 1 ] ,
V_94 -> V_140 [ 2 ] ,
V_94 -> V_140 [ 3 ] ,
V_94 -> V_140 [ 4 ] ) ;
F_11 ( V_143 , V_18 ) ;
}
return 0 ;
}
static int F_105 ( struct V_15 * V_18 ,
T_2 V_45 , T_1 V_10 )
{
struct V_93 * V_94 = & V_18 -> V_16 -> V_51 . V_52 ;
if ( F_101 ( V_45 >= F_5 ( V_94 -> V_140 ) ) )
return - V_73 ;
V_94 -> V_140 [ V_45 ] = V_10 ;
return 0 ;
}
static bool F_106 ( struct V_144 * V_145 ,
T_5 * V_96 )
{
T_1 V_146 ;
if ( ! ( V_145 -> V_147 & V_148 ) )
return false ;
V_146 = 100ull << ( 32 - V_145 -> V_149 ) ;
if ( V_145 -> V_150 >= V_146 )
return false ;
V_96 -> V_98 =
F_107 ( 1ULL << ( 32 + V_145 -> V_149 ) ,
V_145 -> V_150 ,
100 ) ;
V_96 -> V_99 = V_145 -> V_151 ;
F_108 ( V_96 -> V_99 , 100 ) ;
V_96 -> V_99 -=
F_58 ( V_145 -> V_152 , V_96 -> V_98 , 64 ) ;
return true ;
}
void F_109 ( struct V_16 * V_16 ,
struct V_144 * V_145 )
{
struct V_93 * V_94 = & V_16 -> V_51 . V_52 ;
T_2 V_153 ;
T_1 V_154 ;
F_110 ( sizeof( V_153 ) != sizeof( V_94 -> V_96 . V_97 ) ) ;
F_110 ( F_111 ( T_5 , V_97 ) != 0 ) ;
if ( ! ( V_94 -> V_155 & V_156 ) )
return;
F_112 ( & V_16 -> V_51 . V_52 . V_157 ) ;
if ( ! ( V_94 -> V_155 & V_156 ) )
goto V_158;
V_154 = V_94 -> V_155 >> V_159 ;
if ( F_113 ( F_114 ( V_16 , F_115 ( V_154 ) ,
& V_153 , sizeof( V_153 ) ) ) )
goto V_158;
V_94 -> V_96 . V_97 = 0 ;
if ( F_116 ( V_16 , F_115 ( V_154 ) ,
& V_94 -> V_96 , sizeof( V_94 -> V_96 . V_97 ) ) )
goto V_158;
if ( ! F_106 ( V_145 , & V_94 -> V_96 ) )
goto V_158;
F_117 () ;
if ( F_116 ( V_16 , F_115 ( V_154 ) , & V_94 -> V_96 , sizeof( V_94 -> V_96 ) ) )
goto V_158;
V_153 ++ ;
if ( V_153 == 0xFFFFFFFF || V_153 == 0 )
V_153 = 1 ;
F_117 () ;
V_94 -> V_96 . V_97 = V_153 ;
F_116 ( V_16 , F_115 ( V_154 ) ,
& V_94 -> V_96 , sizeof( V_94 -> V_96 . V_97 ) ) ;
V_158:
F_118 ( & V_16 -> V_51 . V_52 . V_157 ) ;
}
static int F_119 ( struct V_15 * V_18 , T_2 V_50 , T_1 V_10 ,
bool V_11 )
{
struct V_16 * V_16 = V_18 -> V_16 ;
struct V_93 * V_94 = & V_16 -> V_51 . V_52 ;
switch ( V_50 ) {
case V_132 :
V_94 -> V_160 = V_10 ;
if ( ! V_94 -> V_160 )
V_94 -> V_161 &= ~ V_162 ;
break;
case V_133 : {
T_1 V_154 ;
unsigned long V_163 ;
T_6 V_164 [ 4 ] ;
if ( ! V_94 -> V_160 )
break;
if ( ! ( V_10 & V_162 ) ) {
V_94 -> V_161 = V_10 ;
break;
}
V_154 = V_10 >> V_165 ;
V_163 = F_120 ( V_16 , V_154 ) ;
if ( F_121 ( V_163 ) )
return 1 ;
V_166 -> V_167 ( V_18 , V_164 ) ;
( ( unsigned char * ) V_164 ) [ 3 ] = 0xc3 ;
if ( F_122 ( ( void V_168 * ) V_163 , V_164 , 4 ) )
return 1 ;
V_94 -> V_161 = V_10 ;
F_123 ( V_16 , V_154 ) ;
break;
}
case V_134 :
V_94 -> V_155 = V_10 ;
if ( V_94 -> V_155 & V_156 )
F_11 ( V_169 , V_18 ) ;
break;
case V_137 ... V_138 :
return F_105 ( V_18 ,
V_50 - V_137 ,
V_10 ) ;
case V_136 :
return F_103 ( V_18 , V_10 , V_11 ) ;
case V_139 :
if ( V_10 == 1 ) {
F_104 ( V_18 , L_3 ) ;
F_11 ( V_170 , V_18 ) ;
}
break;
default:
F_124 ( V_18 , L_4 ,
V_50 , V_10 ) ;
return 1 ;
}
return 0 ;
}
static T_1 F_125 ( void )
{
T_1 V_171 , V_172 ;
F_126 ( V_173 , & V_171 , & V_172 ) ;
return F_54 ( V_171 + V_172 , 100 ) ;
}
static int F_127 ( struct V_15 * V_18 , T_2 V_50 , T_1 V_10 , bool V_11 )
{
struct V_34 * V_94 = & V_18 -> V_51 . V_52 ;
switch ( V_50 ) {
case V_174 :
if ( ! V_11 )
return 1 ;
V_94 -> V_20 = ( T_2 ) V_10 ;
break;
case V_175 : {
T_1 V_154 ;
unsigned long V_163 ;
if ( ! ( V_10 & V_176 ) ) {
V_94 -> V_177 = V_10 ;
if ( F_128 ( V_18 , 0 ) )
return 1 ;
break;
}
V_154 = V_10 >> V_178 ;
V_163 = F_129 ( V_18 , V_154 ) ;
if ( F_121 ( V_163 ) )
return 1 ;
if ( F_130 ( ( void V_168 * ) V_163 , V_65 ) )
return 1 ;
V_94 -> V_177 = V_10 ;
F_26 ( V_18 , V_154 ) ;
if ( F_128 ( V_18 ,
F_115 ( V_154 ) | V_179 ) )
return 1 ;
break;
}
case V_180 :
return F_131 ( V_18 , V_181 , V_10 ) ;
case V_182 :
return F_131 ( V_18 , V_183 , V_10 ) ;
case V_184 :
return F_131 ( V_18 , V_185 , V_10 ) ;
case V_186 :
if ( ! V_11 )
return 1 ;
V_94 -> V_187 = V_10 - F_125 () ;
break;
case V_59 :
case V_60 :
case V_62 :
case V_66 :
case V_67 :
case V_68 ... V_69 :
return F_36 ( F_18 ( V_18 ) , V_50 , V_10 , V_11 ) ;
case V_188 :
case V_189 :
case V_190 :
case V_191 : {
int V_128 = ( V_50 - V_188 ) / 2 ;
return F_76 ( F_132 ( V_18 , V_128 ) ,
V_10 , V_11 ) ;
}
case V_192 :
case V_193 :
case V_194 :
case V_195 : {
int V_128 = ( V_50 - V_192 ) / 2 ;
return F_78 ( F_132 ( V_18 , V_128 ) ,
V_10 , V_11 ) ;
}
default:
F_124 ( V_18 , L_4 ,
V_50 , V_10 ) ;
return 1 ;
}
return 0 ;
}
static int F_133 ( struct V_15 * V_18 , T_2 V_50 , T_1 * V_70 )
{
T_1 V_10 = 0 ;
struct V_16 * V_16 = V_18 -> V_16 ;
struct V_93 * V_94 = & V_16 -> V_51 . V_52 ;
switch ( V_50 ) {
case V_132 :
V_10 = V_94 -> V_160 ;
break;
case V_133 :
V_10 = V_94 -> V_161 ;
break;
case V_135 :
V_10 = F_53 ( V_16 ) ;
break;
case V_134 :
V_10 = V_94 -> V_155 ;
break;
case V_137 ... V_138 :
return F_100 ( V_18 ,
V_50 - V_137 ,
V_70 ) ;
case V_136 :
return F_102 ( V_18 , V_70 ) ;
case V_139 :
V_10 = 0 ;
break;
default:
F_124 ( V_18 , L_5 , V_50 ) ;
return 1 ;
}
* V_70 = V_10 ;
return 0 ;
}
static int F_134 ( struct V_15 * V_18 , T_2 V_50 , T_1 * V_70 )
{
T_1 V_10 = 0 ;
struct V_34 * V_94 = & V_18 -> V_51 . V_52 ;
switch ( V_50 ) {
case V_174 :
V_10 = V_94 -> V_20 ;
break;
case V_180 :
return F_135 ( V_18 , V_181 , V_70 ) ;
case V_182 :
return F_135 ( V_18 , V_183 , V_70 ) ;
case V_184 :
return F_135 ( V_18 , V_185 , V_70 ) ;
case V_175 :
V_10 = V_94 -> V_177 ;
break;
case V_186 :
V_10 = F_125 () + V_94 -> V_187 ;
break;
case V_59 :
case V_60 :
case V_62 :
case V_66 :
case V_67 :
case V_68 ... V_69 :
return F_39 ( F_18 ( V_18 ) , V_50 , V_70 ) ;
case V_188 :
case V_189 :
case V_190 :
case V_191 : {
int V_128 = ( V_50 - V_188 ) / 2 ;
return F_80 ( F_132 ( V_18 , V_128 ) ,
V_70 ) ;
}
case V_192 :
case V_193 :
case V_194 :
case V_195 : {
int V_128 = ( V_50 - V_192 ) / 2 ;
return F_81 ( F_132 ( V_18 , V_128 ) ,
V_70 ) ;
}
case V_196 :
V_10 = ( T_1 ) V_18 -> V_51 . V_197 * 1000 ;
break;
case V_198 :
V_10 = V_199 ;
break;
default:
F_124 ( V_18 , L_5 , V_50 ) ;
return 1 ;
}
* V_70 = V_10 ;
return 0 ;
}
int F_136 ( struct V_15 * V_18 , T_2 V_50 , T_1 V_10 , bool V_11 )
{
if ( F_99 ( V_50 ) ) {
int V_117 ;
F_112 ( & V_18 -> V_16 -> V_51 . V_52 . V_157 ) ;
V_117 = F_119 ( V_18 , V_50 , V_10 , V_11 ) ;
F_118 ( & V_18 -> V_16 -> V_51 . V_52 . V_157 ) ;
return V_117 ;
} else
return F_127 ( V_18 , V_50 , V_10 , V_11 ) ;
}
int F_137 ( struct V_15 * V_18 , T_2 V_50 , T_1 * V_70 )
{
if ( F_99 ( V_50 ) ) {
int V_117 ;
F_112 ( & V_18 -> V_16 -> V_51 . V_52 . V_157 ) ;
V_117 = F_133 ( V_18 , V_50 , V_70 ) ;
F_118 ( & V_18 -> V_16 -> V_51 . V_52 . V_157 ) ;
return V_117 ;
} else
return F_134 ( V_18 , V_50 , V_70 ) ;
}
bool F_138 ( struct V_16 * V_16 )
{
return F_139 ( V_16 -> V_51 . V_52 . V_161 ) & V_162 ;
}
static void F_140 ( struct V_15 * V_18 , T_1 V_200 )
{
bool V_201 ;
V_201 = F_141 ( V_18 ) ;
if ( V_201 )
F_142 ( V_18 , V_202 , V_200 ) ;
else {
F_142 ( V_18 , V_203 , V_200 >> 32 ) ;
F_142 ( V_18 , V_202 , V_200 & 0xffffffff ) ;
}
}
static int F_143 ( struct V_15 * V_18 )
{
struct V_204 * V_205 = V_18 -> V_205 ;
F_140 ( V_18 , V_205 -> V_52 . V_54 . V_206 . V_200 ) ;
return 1 ;
}
int F_144 ( struct V_15 * V_18 )
{
T_1 V_207 , V_208 , V_209 , V_58 ;
T_7 V_210 , V_211 , V_212 , V_213 = V_214 , V_215 = 0 ;
bool V_216 , V_201 ;
if ( V_166 -> V_217 ( V_18 ) != 0 || ! F_145 ( V_18 ) ) {
F_146 ( V_18 , V_218 ) ;
return 1 ;
}
V_201 = F_141 ( V_18 ) ;
if ( ! V_201 ) {
V_207 = ( ( T_1 ) F_147 ( V_18 , V_203 ) << 32 ) |
( F_147 ( V_18 , V_202 ) & 0xffffffff ) ;
V_208 = ( ( T_1 ) F_147 ( V_18 , V_219 ) << 32 ) |
( F_147 ( V_18 , V_220 ) & 0xffffffff ) ;
V_209 = ( ( T_1 ) F_147 ( V_18 , V_221 ) << 32 ) |
( F_147 ( V_18 , V_222 ) & 0xffffffff ) ;
}
#ifdef F_148
else {
V_207 = F_147 ( V_18 , V_220 ) ;
V_208 = F_147 ( V_18 , V_203 ) ;
V_209 = F_147 ( V_18 , V_223 ) ;
}
#endif
V_210 = V_207 & 0xffff ;
V_216 = ( V_207 >> 16 ) & 0x1 ;
V_212 = ( V_207 >> 32 ) & 0xfff ;
V_211 = ( V_207 >> 48 ) & 0xfff ;
F_149 ( V_210 , V_216 , V_212 , V_211 , V_208 , V_209 ) ;
if ( V_212 || V_211 ) {
V_213 = V_224 ;
goto V_225;
}
switch ( V_210 ) {
case V_226 :
F_150 ( V_18 , true ) ;
break;
case V_227 :
case V_228 :
if ( ! F_18 ( V_18 ) -> V_21 ) {
V_213 = V_224 ;
break;
}
V_18 -> V_205 -> V_229 = V_230 ;
V_18 -> V_205 -> V_52 . type = V_231 ;
V_18 -> V_205 -> V_52 . V_54 . V_206 . V_232 = V_207 ;
V_18 -> V_205 -> V_52 . V_54 . V_206 . V_233 [ 0 ] = V_208 ;
V_18 -> V_205 -> V_52 . V_54 . V_206 . V_233 [ 1 ] = V_209 ;
V_18 -> V_51 . V_234 =
F_143 ;
return 0 ;
default:
V_213 = V_224 ;
break;
}
V_225:
V_58 = V_213 | ( ( ( T_1 ) V_215 & 0xfff ) << 32 ) ;
F_140 ( V_18 , V_58 ) ;
return 1 ;
}
