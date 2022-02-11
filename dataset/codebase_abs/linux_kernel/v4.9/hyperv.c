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
static struct V_1 * F_13 ( struct V_15 * V_15 , T_2 V_16 )
{
struct V_17 * V_18 ;
struct V_1 * V_2 ;
if ( V_16 >= F_14 ( & V_15 -> V_19 ) )
return NULL ;
V_18 = F_15 ( V_15 , V_16 ) ;
if ( ! V_18 )
return NULL ;
V_2 = F_16 ( V_18 ) ;
return ( V_2 -> V_20 ) ? V_2 : NULL ;
}
static void F_17 ( struct V_1 * V_2 ,
T_2 V_3 )
{
struct V_17 * V_18 = F_12 ( V_2 ) ;
struct V_21 * V_21 ;
T_3 V_22 ;
struct V_23 * V_24 ;
struct V_25 * V_26 ;
V_22 = V_2 -> V_26 & V_27 ;
V_21 = F_18 ( V_18 , V_22 >> V_28 ) ;
if ( F_19 ( V_21 ) ) {
F_20 ( V_18 , L_1 ,
V_22 ) ;
return;
}
V_26 = F_21 ( V_21 ) ;
V_24 = & V_26 -> V_29 [ V_3 ] ;
V_24 -> V_30 . V_31 . V_32 = 0 ;
F_22 ( V_26 ) ;
F_23 ( V_21 ) ;
F_24 ( V_18 , V_22 >> V_28 ) ;
}
static void F_25 ( struct V_17 * V_18 , T_2 V_3 )
{
struct V_15 * V_15 = V_18 -> V_15 ;
struct V_1 * V_2 = F_16 ( V_18 ) ;
struct V_33 * V_34 = F_26 ( V_18 ) ;
struct V_35 * V_36 ;
int V_37 , V_38 , V_39 ;
F_27 ( V_18 -> V_16 , V_3 ) ;
if ( V_2 -> V_26 & V_40 )
F_17 ( V_2 , V_3 ) ;
V_39 = 0 ;
for ( V_38 = 0 ; V_38 < F_5 ( V_34 -> V_36 ) ; V_38 ++ ) {
V_36 = & V_34 -> V_36 [ V_38 ] ;
if ( V_36 -> V_32 &&
( V_36 -> V_41 & V_42 ) &&
F_28 ( V_36 -> V_41 ) == V_3 ) {
F_29 ( V_36 -> V_43 ,
V_34 -> V_44 ) ;
V_39 ++ ;
}
}
if ( V_39 )
F_11 ( V_45 , V_18 ) ;
V_38 = F_30 ( & V_15 -> V_46 ) ;
V_37 = F_14 ( & V_2 -> V_47 [ V_3 ] ) ;
if ( V_37 != - 1 )
F_31 ( V_15 , V_37 ) ;
F_32 ( & V_15 -> V_46 , V_38 ) ;
}
static void F_33 ( struct V_1 * V_2 , T_2 V_48 )
{
struct V_17 * V_18 = F_12 ( V_2 ) ;
struct V_33 * V_34 = & V_18 -> V_49 . V_50 ;
V_34 -> exit . type = V_51 ;
V_34 -> exit . V_52 . V_2 . V_48 = V_48 ;
V_34 -> exit . V_52 . V_2 . V_53 = V_2 -> V_53 ;
V_34 -> exit . V_52 . V_2 . V_54 = V_2 -> V_54 ;
V_34 -> exit . V_52 . V_2 . V_26 = V_2 -> V_26 ;
F_11 ( V_55 , V_18 ) ;
}
static int F_34 ( struct V_1 * V_2 ,
T_2 V_48 , T_1 V_10 , bool V_11 )
{
struct V_17 * V_18 = F_12 ( V_2 ) ;
int V_56 ;
if ( ! V_2 -> V_20 )
return 1 ;
F_35 ( V_18 -> V_16 , V_48 , V_10 , V_11 ) ;
V_56 = 0 ;
switch ( V_48 ) {
case V_57 :
V_2 -> V_53 = V_10 ;
if ( ! V_11 )
F_33 ( V_2 , V_48 ) ;
break;
case V_58 :
if ( ! V_11 ) {
V_56 = 1 ;
break;
}
V_2 -> V_59 = V_10 ;
break;
case V_60 :
if ( V_10 & V_61 )
if ( F_36 ( V_18 -> V_15 ,
V_10 & V_27 , V_62 ) ) {
V_56 = 1 ;
break;
}
V_2 -> V_54 = V_10 ;
if ( ! V_11 )
F_33 ( V_2 , V_48 ) ;
break;
case V_63 :
if ( V_10 & V_40 )
if ( F_36 ( V_18 -> V_15 ,
V_10 & V_27 , V_62 ) ) {
V_56 = 1 ;
break;
}
V_2 -> V_26 = V_10 ;
if ( ! V_11 )
F_33 ( V_2 , V_48 ) ;
break;
case V_64 : {
int V_8 ;
for ( V_8 = 0 ; V_8 < F_5 ( V_2 -> V_3 ) ; V_8 ++ )
F_25 ( V_18 , V_8 ) ;
break;
}
case V_65 ... V_66 :
V_56 = F_7 ( V_2 , V_48 - V_65 , V_10 , V_11 ) ;
break;
default:
V_56 = 1 ;
break;
}
return V_56 ;
}
static int F_37 ( struct V_1 * V_2 , T_2 V_48 , T_1 * V_67 )
{
int V_56 ;
if ( ! V_2 -> V_20 )
return 1 ;
V_56 = 0 ;
switch ( V_48 ) {
case V_57 :
* V_67 = V_2 -> V_53 ;
break;
case V_58 :
* V_67 = V_2 -> V_59 ;
break;
case V_60 :
* V_67 = V_2 -> V_54 ;
break;
case V_63 :
* V_67 = V_2 -> V_26 ;
break;
case V_64 :
* V_67 = 0 ;
break;
case V_65 ... V_66 :
* V_67 = F_2 ( & V_2 -> V_3 [ V_48 - V_65 ] ) ;
break;
default:
V_56 = 1 ;
break;
}
return V_56 ;
}
int F_38 ( struct V_1 * V_2 , T_2 V_3 )
{
struct V_17 * V_18 = F_12 ( V_2 ) ;
struct V_68 V_69 ;
int V_56 , V_7 ;
if ( V_3 >= F_5 ( V_2 -> V_3 ) )
return - V_70 ;
V_7 = F_3 ( F_1 ( V_2 , V_3 ) ) ;
if ( V_7 < 0 )
return - V_71 ;
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
V_69 . V_72 = F_39 ( V_18 -> V_49 . V_73 ) ;
V_69 . V_74 = V_75 ;
V_69 . V_76 = V_77 ;
V_69 . V_7 = V_7 ;
V_69 . V_78 = 1 ;
V_56 = F_40 ( V_18 -> V_15 , NULL , & V_69 , NULL ) ;
F_41 ( V_18 -> V_16 , V_3 , V_69 . V_7 , V_56 ) ;
return V_56 ;
}
int F_42 ( struct V_15 * V_15 , T_2 V_16 , T_2 V_3 )
{
struct V_1 * V_2 ;
V_2 = F_13 ( V_15 , V_16 ) ;
if ( ! V_2 )
return - V_70 ;
return F_38 ( V_2 , V_3 ) ;
}
void F_43 ( struct V_17 * V_18 , int V_7 )
{
struct V_1 * V_2 = F_16 ( V_18 ) ;
int V_8 ;
F_44 ( V_18 -> V_16 , V_7 ) ;
for ( V_8 = 0 ; V_8 < F_5 ( V_2 -> V_3 ) ; V_8 ++ )
if ( F_3 ( F_1 ( V_2 , V_8 ) ) == V_7 )
F_25 ( V_18 , V_8 ) ;
}
static int F_45 ( struct V_15 * V_15 , T_2 V_16 , T_2 V_3 , int V_37 )
{
struct V_1 * V_2 ;
V_2 = F_13 ( V_15 , V_16 ) ;
if ( ! V_2 )
return - V_70 ;
if ( V_3 >= F_5 ( V_2 -> V_47 ) )
return - V_70 ;
F_46 ( & V_2 -> V_47 [ V_3 ] , V_37 ) ;
return 0 ;
}
void F_47 ( struct V_15 * V_15 )
{
struct V_79 * V_80 ;
struct V_81 * V_82 ;
T_2 V_37 ;
V_80 = F_48 ( V_15 -> V_83 , & V_15 -> V_46 ,
F_49 ( & V_15 -> V_84 ) ) ;
for ( V_37 = 0 ; V_37 < V_80 -> V_85 ; V_37 ++ ) {
F_50 (e, &irq_rt->map[gsi], link) {
if ( V_82 -> type == V_86 )
F_45 ( V_15 , V_82 -> V_87 . V_18 ,
V_82 -> V_87 . V_3 , V_37 ) ;
}
}
}
static void F_51 ( struct V_1 * V_2 )
{
int V_8 ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_59 = V_88 ;
for ( V_8 = 0 ; V_8 < F_5 ( V_2 -> V_3 ) ; V_8 ++ ) {
F_8 ( & V_2 -> V_3 [ V_8 ] , V_5 ) ;
F_46 ( & V_2 -> V_47 [ V_8 ] , - 1 ) ;
}
}
static T_1 F_52 ( struct V_15 * V_15 )
{
struct V_89 * V_90 = & V_15 -> V_49 . V_50 ;
struct V_17 * V_18 ;
T_1 V_91 ;
if ( ! V_90 -> V_92 . V_93 )
return F_53 ( F_54 ( V_15 ) , 100 ) ;
V_18 = F_15 ( V_15 , 0 ) ;
V_91 = F_55 ( V_18 , F_56 () ) ;
return F_57 ( V_91 , V_90 -> V_92 . V_94 , 64 )
+ V_90 -> V_92 . V_95 ;
}
static void F_58 ( struct V_35 * V_36 ,
bool V_96 )
{
struct V_17 * V_18 = F_59 ( V_36 ) ;
F_29 ( V_36 -> V_43 ,
F_26 ( V_18 ) -> V_44 ) ;
F_11 ( V_45 , V_18 ) ;
if ( V_96 )
F_60 ( V_18 ) ;
}
static void F_61 ( struct V_35 * V_36 )
{
struct V_17 * V_18 = F_59 ( V_36 ) ;
F_62 ( F_59 ( V_36 ) -> V_16 ,
V_36 -> V_43 ) ;
F_63 ( & V_36 -> V_97 ) ;
F_64 ( V_36 -> V_43 ,
F_26 ( V_18 ) -> V_44 ) ;
V_36 -> V_32 = false ;
V_36 -> V_98 = 0 ;
}
static enum V_99 F_65 ( struct V_100 * V_97 )
{
struct V_35 * V_36 ;
V_36 = F_66 ( V_97 , struct V_35 , V_97 ) ;
F_67 ( F_59 ( V_36 ) -> V_16 ,
V_36 -> V_43 ) ;
F_58 ( V_36 , true ) ;
return V_101 ;
}
static int F_68 ( struct V_35 * V_36 )
{
T_1 V_102 ;
T_4 V_103 ;
V_102 = F_52 ( F_59 ( V_36 ) -> V_15 ) ;
V_103 = F_69 () ;
if ( V_36 -> V_41 & V_104 ) {
if ( V_36 -> V_98 ) {
if ( V_102 >= V_36 -> V_98 ) {
T_1 V_105 ;
F_70 ( V_102 - V_36 -> V_98 ,
V_36 -> V_106 , & V_105 ) ;
V_36 -> V_98 =
V_102 + ( V_36 -> V_106 - V_105 ) ;
}
} else
V_36 -> V_98 = V_102 + V_36 -> V_106 ;
F_71 (
F_59 ( V_36 ) -> V_16 ,
V_36 -> V_43 ,
V_102 , V_36 -> V_98 ) ;
F_72 ( & V_36 -> V_97 ,
F_73 ( V_103 ,
100 * ( V_36 -> V_98 - V_102 ) ) ,
V_107 ) ;
return 0 ;
}
V_36 -> V_98 = V_36 -> V_106 ;
if ( V_102 >= V_36 -> V_106 ) {
F_58 ( V_36 , false ) ;
return 0 ;
}
F_74 ( F_59 ( V_36 ) -> V_16 ,
V_36 -> V_43 ,
V_102 , V_36 -> V_106 ) ;
F_72 ( & V_36 -> V_97 ,
F_73 ( V_103 , 100 * ( V_36 -> V_106 - V_102 ) ) ,
V_107 ) ;
return 0 ;
}
static int F_75 ( struct V_35 * V_36 , T_1 V_41 ,
bool V_11 )
{
F_76 ( F_59 ( V_36 ) -> V_16 ,
V_36 -> V_43 , V_41 , V_11 ) ;
F_61 ( V_36 ) ;
if ( ( V_36 -> V_41 & V_42 ) && F_28 ( V_41 ) == 0 )
V_41 &= ~ V_42 ;
V_36 -> V_41 = V_41 ;
F_58 ( V_36 , false ) ;
return 0 ;
}
static int F_77 ( struct V_35 * V_36 , T_1 V_106 ,
bool V_11 )
{
F_78 ( F_59 ( V_36 ) -> V_16 ,
V_36 -> V_43 , V_106 , V_11 ) ;
F_61 ( V_36 ) ;
V_36 -> V_106 = V_106 ;
if ( V_36 -> V_106 == 0 )
V_36 -> V_41 &= ~ V_42 ;
else if ( V_36 -> V_41 & V_108 )
V_36 -> V_41 |= V_42 ;
F_58 ( V_36 , false ) ;
return 0 ;
}
static int F_79 ( struct V_35 * V_36 , T_1 * V_109 )
{
* V_109 = V_36 -> V_41 ;
return 0 ;
}
static int F_80 ( struct V_35 * V_36 , T_1 * V_110 )
{
* V_110 = V_36 -> V_106 ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 , T_2 V_3 ,
struct V_23 * V_111 )
{
struct V_17 * V_18 = F_12 ( V_2 ) ;
struct V_21 * V_21 ;
T_3 V_22 ;
struct V_23 * V_112 ;
int V_113 ;
struct V_25 * V_26 ;
if ( ! ( V_2 -> V_26 & V_40 ) )
return - V_71 ;
V_22 = V_2 -> V_26 & V_27 ;
V_21 = F_18 ( V_18 , V_22 >> V_28 ) ;
if ( F_19 ( V_21 ) )
return - V_114 ;
V_26 = F_21 ( V_21 ) ;
V_112 = & V_26 -> V_29 [ V_3 ] ;
if ( F_82 ( & V_112 -> V_30 . V_115 , V_116 ,
V_111 -> V_30 . V_115 ) != V_116 ) {
V_112 -> V_30 . V_31 . V_32 = 1 ;
V_113 = - V_117 ;
} else {
memcpy ( & V_112 -> V_52 . V_118 , & V_111 -> V_52 . V_118 ,
V_111 -> V_30 . V_119 ) ;
V_112 -> V_30 . V_115 = V_111 -> V_30 . V_115 ;
V_112 -> V_30 . V_119 = V_111 -> V_30 . V_119 ;
V_113 = F_38 ( V_2 , V_3 ) ;
if ( V_113 >= 1 )
V_113 = 0 ;
else if ( V_113 == 0 )
V_113 = - V_114 ;
}
F_22 ( V_26 ) ;
F_23 ( V_21 ) ;
F_24 ( V_18 , V_22 >> V_28 ) ;
return V_113 ;
}
static int F_83 ( struct V_35 * V_36 )
{
struct V_17 * V_18 = F_59 ( V_36 ) ;
struct V_23 * V_24 = & V_36 -> V_24 ;
struct V_120 * V_118 =
(struct V_120 * ) & V_24 -> V_52 . V_118 ;
V_118 -> V_121 = V_36 -> V_98 ;
V_118 -> V_122 = F_52 ( V_18 -> V_15 ) ;
return F_81 ( F_16 ( V_18 ) ,
F_28 ( V_36 -> V_41 ) , V_24 ) ;
}
static void F_84 ( struct V_35 * V_36 )
{
int V_113 ;
V_36 -> V_32 = true ;
V_113 = F_83 ( V_36 ) ;
F_85 ( F_59 ( V_36 ) -> V_16 ,
V_36 -> V_43 , V_113 ) ;
if ( ! V_113 ) {
V_36 -> V_32 = false ;
if ( ! ( V_36 -> V_41 & V_104 ) )
V_36 -> V_41 &= ~ V_42 ;
}
}
void F_86 ( struct V_17 * V_18 )
{
struct V_33 * V_34 = F_26 ( V_18 ) ;
struct V_35 * V_36 ;
T_1 V_102 , V_98 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < F_5 ( V_34 -> V_36 ) ; V_8 ++ )
if ( F_87 ( V_8 , V_34 -> V_44 ) ) {
V_36 = & V_34 -> V_36 [ V_8 ] ;
if ( V_36 -> V_41 & V_42 ) {
V_98 = V_36 -> V_98 ;
if ( V_98 ) {
V_102 =
F_52 ( V_18 -> V_15 ) ;
if ( V_102 >= V_98 )
F_84 ( V_36 ) ;
}
if ( ( V_36 -> V_41 & V_42 ) &&
V_36 -> V_106 )
F_68 ( V_36 ) ;
else
F_61 ( V_36 ) ;
}
}
}
void F_88 ( struct V_17 * V_18 )
{
struct V_33 * V_34 = F_26 ( V_18 ) ;
int V_8 ;
for ( V_8 = 0 ; V_8 < F_5 ( V_34 -> V_36 ) ; V_8 ++ )
F_61 ( & V_34 -> V_36 [ V_8 ] ) ;
}
static void F_89 ( struct V_35 * V_36 )
{
struct V_23 * V_24 = & V_36 -> V_24 ;
struct V_120 * V_118 =
(struct V_120 * ) & V_24 -> V_52 . V_118 ;
memset ( & V_24 -> V_30 , 0 , sizeof( V_24 -> V_30 ) ) ;
V_24 -> V_30 . V_115 = V_123 ;
V_24 -> V_30 . V_119 = sizeof( * V_118 ) ;
V_118 -> V_124 = V_36 -> V_43 ;
V_118 -> V_121 = 0 ;
V_118 -> V_122 = 0 ;
}
static void F_90 ( struct V_35 * V_36 , int V_124 )
{
memset ( V_36 , 0 , sizeof( * V_36 ) ) ;
V_36 -> V_43 = V_124 ;
F_91 ( & V_36 -> V_97 , V_125 , V_107 ) ;
V_36 -> V_97 . V_126 = F_65 ;
F_89 ( V_36 ) ;
}
void F_92 ( struct V_17 * V_18 )
{
struct V_33 * V_34 = F_26 ( V_18 ) ;
int V_8 ;
F_51 ( & V_34 -> V_2 ) ;
F_93 ( V_34 -> V_44 , V_127 ) ;
for ( V_8 = 0 ; V_8 < F_5 ( V_34 -> V_36 ) ; V_8 ++ )
F_90 ( & V_34 -> V_36 [ V_8 ] , V_8 ) ;
}
int F_94 ( struct V_17 * V_18 )
{
F_95 ( V_18 ) ;
F_16 ( V_18 ) -> V_20 = true ;
return 0 ;
}
static bool F_96 ( T_2 V_48 )
{
bool V_113 = false ;
switch ( V_48 ) {
case V_128 :
case V_129 :
case V_130 :
case V_131 :
case V_132 :
case V_133 ... V_134 :
case V_135 :
V_113 = true ;
break;
}
return V_113 ;
}
static int F_97 ( struct V_17 * V_18 ,
T_2 V_43 , T_1 * V_67 )
{
struct V_89 * V_90 = & V_18 -> V_15 -> V_49 . V_50 ;
if ( F_98 ( V_43 >= F_5 ( V_90 -> V_136 ) ) )
return - V_70 ;
* V_67 = V_90 -> V_136 [ V_43 ] ;
return 0 ;
}
static int F_99 ( struct V_17 * V_18 , T_1 * V_67 )
{
struct V_89 * V_90 = & V_18 -> V_15 -> V_49 . V_50 ;
* V_67 = V_90 -> V_137 ;
return 0 ;
}
static int F_100 ( struct V_17 * V_18 , T_1 V_10 , bool V_11 )
{
struct V_89 * V_90 = & V_18 -> V_15 -> V_49 . V_50 ;
if ( V_11 )
V_90 -> V_137 = V_10 & V_138 ;
if ( ! V_11 && ( V_10 & V_138 ) ) {
F_101 ( V_18 , L_2 ,
V_90 -> V_136 [ 0 ] ,
V_90 -> V_136 [ 1 ] ,
V_90 -> V_136 [ 2 ] ,
V_90 -> V_136 [ 3 ] ,
V_90 -> V_136 [ 4 ] ) ;
F_11 ( V_139 , V_18 ) ;
}
return 0 ;
}
static int F_102 ( struct V_17 * V_18 ,
T_2 V_43 , T_1 V_10 )
{
struct V_89 * V_90 = & V_18 -> V_15 -> V_49 . V_50 ;
if ( F_98 ( V_43 >= F_5 ( V_90 -> V_136 ) ) )
return - V_70 ;
V_90 -> V_136 [ V_43 ] = V_10 ;
return 0 ;
}
static bool F_103 ( struct V_140 * V_141 ,
T_5 * V_92 )
{
T_1 V_142 ;
if ( ! ( V_141 -> V_143 & V_144 ) )
return false ;
V_142 = 100ull << ( 32 - V_141 -> V_145 ) ;
if ( V_141 -> V_146 >= V_142 )
return false ;
V_92 -> V_94 =
F_104 ( 1ULL << ( 32 + V_141 -> V_145 ) ,
V_141 -> V_146 ,
100 ) ;
V_92 -> V_95 = V_141 -> V_147 ;
F_105 ( V_92 -> V_95 , 100 ) ;
V_92 -> V_95 -=
F_57 ( V_141 -> V_148 , V_92 -> V_94 , 64 ) ;
return true ;
}
void F_106 ( struct V_15 * V_15 ,
struct V_140 * V_141 )
{
struct V_89 * V_90 = & V_15 -> V_49 . V_50 ;
T_2 V_149 ;
T_1 V_150 ;
F_107 ( sizeof( V_149 ) != sizeof( V_90 -> V_92 . V_93 ) ) ;
F_107 ( F_108 ( T_5 , V_93 ) != 0 ) ;
if ( ! ( V_90 -> V_151 & V_152 ) )
return;
V_150 = V_90 -> V_151 >> V_153 ;
if ( F_109 ( F_110 ( V_15 , F_111 ( V_150 ) ,
& V_149 , sizeof( V_149 ) ) ) )
return;
V_90 -> V_92 . V_93 = 0 ;
if ( F_112 ( V_15 , F_111 ( V_150 ) ,
& V_90 -> V_92 , sizeof( V_90 -> V_92 . V_93 ) ) )
return;
if ( ! F_103 ( V_141 , & V_90 -> V_92 ) )
return;
F_113 () ;
if ( F_112 ( V_15 , F_111 ( V_150 ) , & V_90 -> V_92 , sizeof( V_90 -> V_92 ) ) )
return;
V_149 ++ ;
if ( V_149 == 0xFFFFFFFF || V_149 == 0 )
V_149 = 1 ;
F_113 () ;
V_90 -> V_92 . V_93 = V_149 ;
F_112 ( V_15 , F_111 ( V_150 ) ,
& V_90 -> V_92 , sizeof( V_90 -> V_92 . V_93 ) ) ;
}
static int F_114 ( struct V_17 * V_18 , T_2 V_48 , T_1 V_10 ,
bool V_11 )
{
struct V_15 * V_15 = V_18 -> V_15 ;
struct V_89 * V_90 = & V_15 -> V_49 . V_50 ;
switch ( V_48 ) {
case V_128 :
V_90 -> V_154 = V_10 ;
if ( ! V_90 -> V_154 )
V_90 -> V_155 &= ~ V_156 ;
break;
case V_129 : {
T_1 V_150 ;
unsigned long V_157 ;
T_6 V_158 [ 4 ] ;
if ( ! V_90 -> V_154 )
break;
if ( ! ( V_10 & V_156 ) ) {
V_90 -> V_155 = V_10 ;
break;
}
V_150 = V_10 >> V_159 ;
V_157 = F_115 ( V_15 , V_150 ) ;
if ( F_116 ( V_157 ) )
return 1 ;
V_160 -> V_161 ( V_18 , V_158 ) ;
( ( unsigned char * ) V_158 ) [ 3 ] = 0xc3 ;
if ( F_117 ( ( void V_162 * ) V_157 , V_158 , 4 ) )
return 1 ;
V_90 -> V_155 = V_10 ;
F_118 ( V_15 , V_150 ) ;
break;
}
case V_130 :
V_90 -> V_151 = V_10 ;
if ( V_90 -> V_151 & V_152 )
F_11 ( V_163 , V_18 ) ;
break;
case V_133 ... V_134 :
return F_102 ( V_18 ,
V_48 - V_133 ,
V_10 ) ;
case V_132 :
return F_100 ( V_18 , V_10 , V_11 ) ;
case V_135 :
if ( V_10 == 1 ) {
F_101 ( V_18 , L_3 ) ;
F_11 ( V_164 , V_18 ) ;
}
break;
default:
F_119 ( V_18 , L_4 ,
V_48 , V_10 ) ;
return 1 ;
}
return 0 ;
}
static T_1 F_120 ( void )
{
T_7 V_165 , V_166 ;
F_121 ( V_167 , & V_165 , & V_166 ) ;
return F_53 ( F_122 ( V_165 + V_166 ) , 100 ) ;
}
static int F_123 ( struct V_17 * V_18 , T_2 V_48 , T_1 V_10 , bool V_11 )
{
struct V_33 * V_90 = & V_18 -> V_49 . V_50 ;
switch ( V_48 ) {
case V_168 : {
T_1 V_150 ;
unsigned long V_157 ;
if ( ! ( V_10 & V_169 ) ) {
V_90 -> V_170 = V_10 ;
if ( F_124 ( V_18 , 0 ) )
return 1 ;
break;
}
V_150 = V_10 >> V_171 ;
V_157 = F_125 ( V_18 , V_150 ) ;
if ( F_116 ( V_157 ) )
return 1 ;
if ( F_126 ( ( void V_162 * ) V_157 , V_62 ) )
return 1 ;
V_90 -> V_170 = V_10 ;
F_24 ( V_18 , V_150 ) ;
if ( F_124 ( V_18 ,
F_111 ( V_150 ) | V_172 ) )
return 1 ;
break;
}
case V_173 :
return F_127 ( V_18 , V_174 , V_10 ) ;
case V_175 :
return F_127 ( V_18 , V_176 , V_10 ) ;
case V_177 :
return F_127 ( V_18 , V_178 , V_10 ) ;
case V_179 :
if ( ! V_11 )
return 1 ;
V_90 -> V_180 = V_10 - F_120 () ;
break;
case V_57 :
case V_58 :
case V_60 :
case V_63 :
case V_64 :
case V_65 ... V_66 :
return F_34 ( F_16 ( V_18 ) , V_48 , V_10 , V_11 ) ;
case V_181 :
case V_182 :
case V_183 :
case V_184 : {
int V_124 = ( V_48 - V_181 ) / 2 ;
return F_75 ( F_128 ( V_18 , V_124 ) ,
V_10 , V_11 ) ;
}
case V_185 :
case V_186 :
case V_187 :
case V_188 : {
int V_124 = ( V_48 - V_185 ) / 2 ;
return F_77 ( F_128 ( V_18 , V_124 ) ,
V_10 , V_11 ) ;
}
default:
F_119 ( V_18 , L_4 ,
V_48 , V_10 ) ;
return 1 ;
}
return 0 ;
}
static int F_129 ( struct V_17 * V_18 , T_2 V_48 , T_1 * V_67 )
{
T_1 V_10 = 0 ;
struct V_15 * V_15 = V_18 -> V_15 ;
struct V_89 * V_90 = & V_15 -> V_49 . V_50 ;
switch ( V_48 ) {
case V_128 :
V_10 = V_90 -> V_154 ;
break;
case V_129 :
V_10 = V_90 -> V_155 ;
break;
case V_131 :
V_10 = F_52 ( V_15 ) ;
break;
case V_130 :
V_10 = V_90 -> V_151 ;
break;
case V_133 ... V_134 :
return F_97 ( V_18 ,
V_48 - V_133 ,
V_67 ) ;
case V_132 :
return F_99 ( V_18 , V_67 ) ;
case V_135 :
V_10 = 0 ;
break;
default:
F_119 ( V_18 , L_5 , V_48 ) ;
return 1 ;
}
* V_67 = V_10 ;
return 0 ;
}
static int F_130 ( struct V_17 * V_18 , T_2 V_48 , T_1 * V_67 )
{
T_1 V_10 = 0 ;
struct V_33 * V_90 = & V_18 -> V_49 . V_50 ;
switch ( V_48 ) {
case V_189 : {
int V_113 ;
struct V_17 * V_190 ;
F_131 (r, v, vcpu->kvm) {
if ( V_190 == V_18 ) {
V_10 = V_113 ;
break;
}
}
break;
}
case V_173 :
return F_132 ( V_18 , V_174 , V_67 ) ;
case V_175 :
return F_132 ( V_18 , V_176 , V_67 ) ;
case V_177 :
return F_132 ( V_18 , V_178 , V_67 ) ;
case V_168 :
V_10 = V_90 -> V_170 ;
break;
case V_179 :
V_10 = F_120 () + V_90 -> V_180 ;
break;
case V_57 :
case V_58 :
case V_60 :
case V_63 :
case V_64 :
case V_65 ... V_66 :
return F_37 ( F_16 ( V_18 ) , V_48 , V_67 ) ;
case V_181 :
case V_182 :
case V_183 :
case V_184 : {
int V_124 = ( V_48 - V_181 ) / 2 ;
return F_79 ( F_128 ( V_18 , V_124 ) ,
V_67 ) ;
}
case V_185 :
case V_186 :
case V_187 :
case V_188 : {
int V_124 = ( V_48 - V_185 ) / 2 ;
return F_80 ( F_128 ( V_18 , V_124 ) ,
V_67 ) ;
}
default:
F_119 ( V_18 , L_5 , V_48 ) ;
return 1 ;
}
* V_67 = V_10 ;
return 0 ;
}
int F_133 ( struct V_17 * V_18 , T_2 V_48 , T_1 V_10 , bool V_11 )
{
if ( F_96 ( V_48 ) ) {
int V_113 ;
F_134 ( & V_18 -> V_15 -> V_191 ) ;
V_113 = F_114 ( V_18 , V_48 , V_10 , V_11 ) ;
F_135 ( & V_18 -> V_15 -> V_191 ) ;
return V_113 ;
} else
return F_123 ( V_18 , V_48 , V_10 , V_11 ) ;
}
int F_136 ( struct V_17 * V_18 , T_2 V_48 , T_1 * V_67 )
{
if ( F_96 ( V_48 ) ) {
int V_113 ;
F_134 ( & V_18 -> V_15 -> V_191 ) ;
V_113 = F_129 ( V_18 , V_48 , V_67 ) ;
F_135 ( & V_18 -> V_15 -> V_191 ) ;
return V_113 ;
} else
return F_130 ( V_18 , V_48 , V_67 ) ;
}
bool F_137 ( struct V_15 * V_15 )
{
return V_15 -> V_49 . V_50 . V_155 & V_156 ;
}
static void F_138 ( struct V_17 * V_18 , T_1 V_192 )
{
bool V_193 ;
V_193 = F_139 ( V_18 ) ;
if ( V_193 )
F_140 ( V_18 , V_194 , V_192 ) ;
else {
F_140 ( V_18 , V_195 , V_192 >> 32 ) ;
F_140 ( V_18 , V_194 , V_192 & 0xffffffff ) ;
}
}
static int F_141 ( struct V_17 * V_18 )
{
struct V_196 * V_197 = V_18 -> V_197 ;
F_138 ( V_18 , V_197 -> V_50 . V_52 . V_198 . V_192 ) ;
return 1 ;
}
int F_142 ( struct V_17 * V_18 )
{
T_1 V_199 , V_200 , V_201 , V_56 ;
T_8 V_202 , V_203 , V_204 , V_205 = V_206 , V_207 = 0 ;
bool V_208 , V_193 ;
if ( V_160 -> V_209 ( V_18 ) != 0 || ! F_143 ( V_18 ) ) {
F_144 ( V_18 , V_210 ) ;
return 1 ;
}
V_193 = F_139 ( V_18 ) ;
if ( ! V_193 ) {
V_199 = ( ( T_1 ) F_145 ( V_18 , V_195 ) << 32 ) |
( F_145 ( V_18 , V_194 ) & 0xffffffff ) ;
V_200 = ( ( T_1 ) F_145 ( V_18 , V_211 ) << 32 ) |
( F_145 ( V_18 , V_212 ) & 0xffffffff ) ;
V_201 = ( ( T_1 ) F_145 ( V_18 , V_213 ) << 32 ) |
( F_145 ( V_18 , V_214 ) & 0xffffffff ) ;
}
#ifdef F_146
else {
V_199 = F_145 ( V_18 , V_212 ) ;
V_200 = F_145 ( V_18 , V_195 ) ;
V_201 = F_145 ( V_18 , V_215 ) ;
}
#endif
V_202 = V_199 & 0xffff ;
V_208 = ( V_199 >> 16 ) & 0x1 ;
V_204 = ( V_199 >> 32 ) & 0xfff ;
V_203 = ( V_199 >> 48 ) & 0xfff ;
F_147 ( V_202 , V_208 , V_204 , V_203 , V_200 , V_201 ) ;
if ( V_204 || V_203 ) {
V_205 = V_216 ;
goto V_217;
}
switch ( V_202 ) {
case V_218 :
F_148 ( V_18 ) ;
break;
case V_219 :
case V_220 :
if ( ! F_16 ( V_18 ) -> V_20 ) {
V_205 = V_216 ;
break;
}
V_18 -> V_197 -> V_221 = V_222 ;
V_18 -> V_197 -> V_50 . type = V_223 ;
V_18 -> V_197 -> V_50 . V_52 . V_198 . V_224 = V_199 ;
V_18 -> V_197 -> V_50 . V_52 . V_198 . V_225 [ 0 ] = V_200 ;
V_18 -> V_197 -> V_50 . V_52 . V_198 . V_225 [ 1 ] = V_201 ;
V_18 -> V_49 . V_226 =
F_141 ;
return 0 ;
default:
V_205 = V_216 ;
break;
}
V_217:
V_56 = V_205 | ( ( ( T_1 ) V_207 & 0xfff ) << 32 ) ;
F_138 ( V_18 , V_56 ) ;
return 1 ;
}
