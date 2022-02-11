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
return F_53 ( F_54 () + V_15 -> V_49 . V_89 , 100 ) ;
}
static void F_55 ( struct V_35 * V_36 ,
bool V_90 )
{
struct V_17 * V_18 = F_56 ( V_36 ) ;
F_29 ( V_36 -> V_43 ,
F_26 ( V_18 ) -> V_44 ) ;
F_11 ( V_45 , V_18 ) ;
if ( V_90 )
F_57 ( V_18 ) ;
}
static void F_58 ( struct V_35 * V_36 )
{
struct V_17 * V_18 = F_56 ( V_36 ) ;
F_59 ( F_56 ( V_36 ) -> V_16 ,
V_36 -> V_43 ) ;
F_60 ( & V_36 -> V_91 ) ;
F_61 ( V_36 -> V_43 ,
F_26 ( V_18 ) -> V_44 ) ;
V_36 -> V_32 = false ;
V_36 -> V_92 = 0 ;
}
static enum V_93 F_62 ( struct V_94 * V_91 )
{
struct V_35 * V_36 ;
V_36 = F_63 ( V_91 , struct V_35 , V_91 ) ;
F_64 ( F_56 ( V_36 ) -> V_16 ,
V_36 -> V_43 ) ;
F_55 ( V_36 , true ) ;
return V_95 ;
}
static int F_65 ( struct V_35 * V_36 )
{
T_1 V_96 ;
T_4 V_97 ;
V_96 = F_52 ( F_56 ( V_36 ) -> V_15 ) ;
V_97 = F_66 () ;
if ( V_36 -> V_41 & V_98 ) {
if ( V_36 -> V_92 ) {
if ( V_96 >= V_36 -> V_92 ) {
T_1 V_99 ;
F_67 ( V_96 - V_36 -> V_92 ,
V_36 -> V_100 , & V_99 ) ;
V_36 -> V_92 =
V_96 + ( V_36 -> V_100 - V_99 ) ;
}
} else
V_36 -> V_92 = V_96 + V_36 -> V_100 ;
F_68 (
F_56 ( V_36 ) -> V_16 ,
V_36 -> V_43 ,
V_96 , V_36 -> V_92 ) ;
F_69 ( & V_36 -> V_91 ,
F_70 ( V_97 ,
100 * ( V_36 -> V_92 - V_96 ) ) ,
V_101 ) ;
return 0 ;
}
V_36 -> V_92 = V_36 -> V_100 ;
if ( V_96 >= V_36 -> V_100 ) {
F_55 ( V_36 , false ) ;
return 0 ;
}
F_71 ( F_56 ( V_36 ) -> V_16 ,
V_36 -> V_43 ,
V_96 , V_36 -> V_100 ) ;
F_69 ( & V_36 -> V_91 ,
F_70 ( V_97 , 100 * ( V_36 -> V_100 - V_96 ) ) ,
V_101 ) ;
return 0 ;
}
static int F_72 ( struct V_35 * V_36 , T_1 V_41 ,
bool V_11 )
{
F_73 ( F_56 ( V_36 ) -> V_16 ,
V_36 -> V_43 , V_41 , V_11 ) ;
F_58 ( V_36 ) ;
if ( ( V_36 -> V_41 & V_42 ) && F_28 ( V_41 ) == 0 )
V_41 &= ~ V_42 ;
V_36 -> V_41 = V_41 ;
F_55 ( V_36 , false ) ;
return 0 ;
}
static int F_74 ( struct V_35 * V_36 , T_1 V_100 ,
bool V_11 )
{
F_75 ( F_56 ( V_36 ) -> V_16 ,
V_36 -> V_43 , V_100 , V_11 ) ;
F_58 ( V_36 ) ;
V_36 -> V_100 = V_100 ;
if ( V_36 -> V_100 == 0 )
V_36 -> V_41 &= ~ V_42 ;
else if ( V_36 -> V_41 & V_102 )
V_36 -> V_41 |= V_42 ;
F_55 ( V_36 , false ) ;
return 0 ;
}
static int F_76 ( struct V_35 * V_36 , T_1 * V_103 )
{
* V_103 = V_36 -> V_41 ;
return 0 ;
}
static int F_77 ( struct V_35 * V_36 , T_1 * V_104 )
{
* V_104 = V_36 -> V_100 ;
return 0 ;
}
static int F_78 ( struct V_1 * V_2 , T_2 V_3 ,
struct V_23 * V_105 )
{
struct V_17 * V_18 = F_12 ( V_2 ) ;
struct V_21 * V_21 ;
T_3 V_22 ;
struct V_23 * V_106 ;
int V_107 ;
struct V_25 * V_26 ;
if ( ! ( V_2 -> V_26 & V_40 ) )
return - V_71 ;
V_22 = V_2 -> V_26 & V_27 ;
V_21 = F_18 ( V_18 , V_22 >> V_28 ) ;
if ( F_19 ( V_21 ) )
return - V_108 ;
V_26 = F_21 ( V_21 ) ;
V_106 = & V_26 -> V_29 [ V_3 ] ;
if ( F_79 ( & V_106 -> V_30 . V_109 , V_110 ,
V_105 -> V_30 . V_109 ) != V_110 ) {
V_106 -> V_30 . V_31 . V_32 = 1 ;
V_107 = - V_111 ;
} else {
memcpy ( & V_106 -> V_52 . V_112 , & V_105 -> V_52 . V_112 ,
V_105 -> V_30 . V_113 ) ;
V_106 -> V_30 . V_109 = V_105 -> V_30 . V_109 ;
V_106 -> V_30 . V_113 = V_105 -> V_30 . V_113 ;
V_107 = F_38 ( V_2 , V_3 ) ;
if ( V_107 >= 1 )
V_107 = 0 ;
else if ( V_107 == 0 )
V_107 = - V_108 ;
}
F_22 ( V_26 ) ;
F_23 ( V_21 ) ;
F_24 ( V_18 , V_22 >> V_28 ) ;
return V_107 ;
}
static int F_80 ( struct V_35 * V_36 )
{
struct V_17 * V_18 = F_56 ( V_36 ) ;
struct V_23 * V_24 = & V_36 -> V_24 ;
struct V_114 * V_112 =
(struct V_114 * ) & V_24 -> V_52 . V_112 ;
V_112 -> V_115 = V_36 -> V_92 ;
V_112 -> V_116 = F_52 ( V_18 -> V_15 ) ;
return F_78 ( F_16 ( V_18 ) ,
F_28 ( V_36 -> V_41 ) , V_24 ) ;
}
static void F_81 ( struct V_35 * V_36 )
{
int V_107 ;
V_36 -> V_32 = true ;
V_107 = F_80 ( V_36 ) ;
F_82 ( F_56 ( V_36 ) -> V_16 ,
V_36 -> V_43 , V_107 ) ;
if ( ! V_107 ) {
V_36 -> V_32 = false ;
if ( ! ( V_36 -> V_41 & V_98 ) )
V_36 -> V_41 &= ~ V_42 ;
}
}
void F_83 ( struct V_17 * V_18 )
{
struct V_33 * V_34 = F_26 ( V_18 ) ;
struct V_35 * V_36 ;
T_1 V_96 , V_92 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < F_5 ( V_34 -> V_36 ) ; V_8 ++ )
if ( F_84 ( V_8 , V_34 -> V_44 ) ) {
V_36 = & V_34 -> V_36 [ V_8 ] ;
if ( V_36 -> V_41 & V_42 ) {
V_92 = V_36 -> V_92 ;
if ( V_92 ) {
V_96 =
F_52 ( V_18 -> V_15 ) ;
if ( V_96 >= V_92 )
F_81 ( V_36 ) ;
}
if ( ( V_36 -> V_41 & V_42 ) &&
V_36 -> V_100 )
F_65 ( V_36 ) ;
else
F_58 ( V_36 ) ;
}
}
}
void F_85 ( struct V_17 * V_18 )
{
struct V_33 * V_34 = F_26 ( V_18 ) ;
int V_8 ;
for ( V_8 = 0 ; V_8 < F_5 ( V_34 -> V_36 ) ; V_8 ++ )
F_58 ( & V_34 -> V_36 [ V_8 ] ) ;
}
static void F_86 ( struct V_35 * V_36 )
{
struct V_23 * V_24 = & V_36 -> V_24 ;
struct V_114 * V_112 =
(struct V_114 * ) & V_24 -> V_52 . V_112 ;
memset ( & V_24 -> V_30 , 0 , sizeof( V_24 -> V_30 ) ) ;
V_24 -> V_30 . V_109 = V_117 ;
V_24 -> V_30 . V_113 = sizeof( * V_112 ) ;
V_112 -> V_118 = V_36 -> V_43 ;
V_112 -> V_115 = 0 ;
V_112 -> V_116 = 0 ;
}
static void F_87 ( struct V_35 * V_36 , int V_118 )
{
memset ( V_36 , 0 , sizeof( * V_36 ) ) ;
V_36 -> V_43 = V_118 ;
F_88 ( & V_36 -> V_91 , V_119 , V_101 ) ;
V_36 -> V_91 . V_120 = F_62 ;
F_86 ( V_36 ) ;
}
void F_89 ( struct V_17 * V_18 )
{
struct V_33 * V_34 = F_26 ( V_18 ) ;
int V_8 ;
F_51 ( & V_34 -> V_2 ) ;
F_90 ( V_34 -> V_44 , V_121 ) ;
for ( V_8 = 0 ; V_8 < F_5 ( V_34 -> V_36 ) ; V_8 ++ )
F_87 ( & V_34 -> V_36 [ V_8 ] , V_8 ) ;
}
int F_91 ( struct V_17 * V_18 )
{
F_92 ( V_18 ) ;
F_16 ( V_18 ) -> V_20 = true ;
return 0 ;
}
static bool F_93 ( T_2 V_48 )
{
bool V_107 = false ;
switch ( V_48 ) {
case V_122 :
case V_123 :
case V_124 :
case V_125 :
case V_126 :
case V_127 ... V_128 :
case V_129 :
V_107 = true ;
break;
}
return V_107 ;
}
static int F_94 ( struct V_17 * V_18 ,
T_2 V_43 , T_1 * V_67 )
{
struct V_130 * V_131 = & V_18 -> V_15 -> V_49 . V_50 ;
if ( F_95 ( V_43 >= F_5 ( V_131 -> V_132 ) ) )
return - V_70 ;
* V_67 = V_131 -> V_132 [ V_43 ] ;
return 0 ;
}
static int F_96 ( struct V_17 * V_18 , T_1 * V_67 )
{
struct V_130 * V_131 = & V_18 -> V_15 -> V_49 . V_50 ;
* V_67 = V_131 -> V_133 ;
return 0 ;
}
static int F_97 ( struct V_17 * V_18 , T_1 V_10 , bool V_11 )
{
struct V_130 * V_131 = & V_18 -> V_15 -> V_49 . V_50 ;
if ( V_11 )
V_131 -> V_133 = V_10 & V_134 ;
if ( ! V_11 && ( V_10 & V_134 ) ) {
F_98 ( V_18 , L_2 ,
V_131 -> V_132 [ 0 ] ,
V_131 -> V_132 [ 1 ] ,
V_131 -> V_132 [ 2 ] ,
V_131 -> V_132 [ 3 ] ,
V_131 -> V_132 [ 4 ] ) ;
F_11 ( V_135 , V_18 ) ;
}
return 0 ;
}
static int F_99 ( struct V_17 * V_18 ,
T_2 V_43 , T_1 V_10 )
{
struct V_130 * V_131 = & V_18 -> V_15 -> V_49 . V_50 ;
if ( F_95 ( V_43 >= F_5 ( V_131 -> V_132 ) ) )
return - V_70 ;
V_131 -> V_132 [ V_43 ] = V_10 ;
return 0 ;
}
static int F_100 ( struct V_17 * V_18 , T_2 V_48 , T_1 V_10 ,
bool V_11 )
{
struct V_15 * V_15 = V_18 -> V_15 ;
struct V_130 * V_131 = & V_15 -> V_49 . V_50 ;
switch ( V_48 ) {
case V_122 :
V_131 -> V_136 = V_10 ;
if ( ! V_131 -> V_136 )
V_131 -> V_137 &= ~ V_138 ;
break;
case V_123 : {
T_1 V_139 ;
unsigned long V_140 ;
T_5 V_141 [ 4 ] ;
if ( ! V_131 -> V_136 )
break;
if ( ! ( V_10 & V_138 ) ) {
V_131 -> V_137 = V_10 ;
break;
}
V_139 = V_10 >> V_142 ;
V_140 = F_101 ( V_15 , V_139 ) ;
if ( F_102 ( V_140 ) )
return 1 ;
V_143 -> V_144 ( V_18 , V_141 ) ;
( ( unsigned char * ) V_141 ) [ 3 ] = 0xc3 ;
if ( F_103 ( ( void V_145 * ) V_140 , V_141 , 4 ) )
return 1 ;
V_131 -> V_137 = V_10 ;
F_104 ( V_15 , V_139 ) ;
break;
}
case V_124 : {
T_1 V_139 ;
T_6 V_146 ;
memset ( & V_146 , 0 , sizeof( V_146 ) ) ;
V_131 -> V_147 = V_10 ;
if ( ! ( V_10 & V_148 ) )
break;
V_139 = V_10 >> V_149 ;
if ( F_105 (
V_15 ,
V_139 << V_149 ,
& V_146 , sizeof( V_146 ) ) )
return 1 ;
F_104 ( V_15 , V_139 ) ;
break;
}
case V_127 ... V_128 :
return F_99 ( V_18 ,
V_48 - V_127 ,
V_10 ) ;
case V_126 :
return F_97 ( V_18 , V_10 , V_11 ) ;
case V_129 :
if ( V_10 == 1 ) {
F_98 ( V_18 , L_3 ) ;
F_11 ( V_150 , V_18 ) ;
}
break;
default:
F_106 ( V_18 , L_4 ,
V_48 , V_10 ) ;
return 1 ;
}
return 0 ;
}
static T_1 F_107 ( void )
{
T_7 V_151 , V_152 ;
F_108 ( V_153 , & V_151 , & V_152 ) ;
return F_53 ( F_109 ( V_151 + V_152 ) , 100 ) ;
}
static int F_110 ( struct V_17 * V_18 , T_2 V_48 , T_1 V_10 , bool V_11 )
{
struct V_33 * V_131 = & V_18 -> V_49 . V_50 ;
switch ( V_48 ) {
case V_154 : {
T_1 V_139 ;
unsigned long V_140 ;
if ( ! ( V_10 & V_155 ) ) {
V_131 -> V_156 = V_10 ;
if ( F_111 ( V_18 , 0 ) )
return 1 ;
break;
}
V_139 = V_10 >> V_157 ;
V_140 = F_112 ( V_18 , V_139 ) ;
if ( F_102 ( V_140 ) )
return 1 ;
if ( F_113 ( ( void V_145 * ) V_140 , V_62 ) )
return 1 ;
V_131 -> V_156 = V_10 ;
F_24 ( V_18 , V_139 ) ;
if ( F_111 ( V_18 ,
F_114 ( V_139 ) | V_158 ) )
return 1 ;
break;
}
case V_159 :
return F_115 ( V_18 , V_160 , V_10 ) ;
case V_161 :
return F_115 ( V_18 , V_162 , V_10 ) ;
case V_163 :
return F_115 ( V_18 , V_164 , V_10 ) ;
case V_165 :
if ( ! V_11 )
return 1 ;
V_131 -> V_166 = V_10 - F_107 () ;
break;
case V_57 :
case V_58 :
case V_60 :
case V_63 :
case V_64 :
case V_65 ... V_66 :
return F_34 ( F_16 ( V_18 ) , V_48 , V_10 , V_11 ) ;
case V_167 :
case V_168 :
case V_169 :
case V_170 : {
int V_118 = ( V_48 - V_167 ) / 2 ;
return F_72 ( F_116 ( V_18 , V_118 ) ,
V_10 , V_11 ) ;
}
case V_171 :
case V_172 :
case V_173 :
case V_174 : {
int V_118 = ( V_48 - V_171 ) / 2 ;
return F_74 ( F_116 ( V_18 , V_118 ) ,
V_10 , V_11 ) ;
}
default:
F_106 ( V_18 , L_4 ,
V_48 , V_10 ) ;
return 1 ;
}
return 0 ;
}
static int F_117 ( struct V_17 * V_18 , T_2 V_48 , T_1 * V_67 )
{
T_1 V_10 = 0 ;
struct V_15 * V_15 = V_18 -> V_15 ;
struct V_130 * V_131 = & V_15 -> V_49 . V_50 ;
switch ( V_48 ) {
case V_122 :
V_10 = V_131 -> V_136 ;
break;
case V_123 :
V_10 = V_131 -> V_137 ;
break;
case V_125 :
V_10 = F_52 ( V_15 ) ;
break;
case V_124 :
V_10 = V_131 -> V_147 ;
break;
case V_127 ... V_128 :
return F_94 ( V_18 ,
V_48 - V_127 ,
V_67 ) ;
case V_126 :
return F_96 ( V_18 , V_67 ) ;
case V_129 :
V_10 = 0 ;
break;
default:
F_106 ( V_18 , L_5 , V_48 ) ;
return 1 ;
}
* V_67 = V_10 ;
return 0 ;
}
static int F_118 ( struct V_17 * V_18 , T_2 V_48 , T_1 * V_67 )
{
T_1 V_10 = 0 ;
struct V_33 * V_131 = & V_18 -> V_49 . V_50 ;
switch ( V_48 ) {
case V_175 : {
int V_107 ;
struct V_17 * V_176 ;
F_119 (r, v, vcpu->kvm) {
if ( V_176 == V_18 ) {
V_10 = V_107 ;
break;
}
}
break;
}
case V_159 :
return F_120 ( V_18 , V_160 , V_67 ) ;
case V_161 :
return F_120 ( V_18 , V_162 , V_67 ) ;
case V_163 :
return F_120 ( V_18 , V_164 , V_67 ) ;
case V_154 :
V_10 = V_131 -> V_156 ;
break;
case V_165 :
V_10 = F_107 () + V_131 -> V_166 ;
break;
case V_57 :
case V_58 :
case V_60 :
case V_63 :
case V_64 :
case V_65 ... V_66 :
return F_37 ( F_16 ( V_18 ) , V_48 , V_67 ) ;
case V_167 :
case V_168 :
case V_169 :
case V_170 : {
int V_118 = ( V_48 - V_167 ) / 2 ;
return F_76 ( F_116 ( V_18 , V_118 ) ,
V_67 ) ;
}
case V_171 :
case V_172 :
case V_173 :
case V_174 : {
int V_118 = ( V_48 - V_171 ) / 2 ;
return F_77 ( F_116 ( V_18 , V_118 ) ,
V_67 ) ;
}
default:
F_106 ( V_18 , L_5 , V_48 ) ;
return 1 ;
}
* V_67 = V_10 ;
return 0 ;
}
int F_121 ( struct V_17 * V_18 , T_2 V_48 , T_1 V_10 , bool V_11 )
{
if ( F_93 ( V_48 ) ) {
int V_107 ;
F_122 ( & V_18 -> V_15 -> V_177 ) ;
V_107 = F_100 ( V_18 , V_48 , V_10 , V_11 ) ;
F_123 ( & V_18 -> V_15 -> V_177 ) ;
return V_107 ;
} else
return F_110 ( V_18 , V_48 , V_10 , V_11 ) ;
}
int F_124 ( struct V_17 * V_18 , T_2 V_48 , T_1 * V_67 )
{
if ( F_93 ( V_48 ) ) {
int V_107 ;
F_122 ( & V_18 -> V_15 -> V_177 ) ;
V_107 = F_117 ( V_18 , V_48 , V_67 ) ;
F_123 ( & V_18 -> V_15 -> V_177 ) ;
return V_107 ;
} else
return F_118 ( V_18 , V_48 , V_67 ) ;
}
bool F_125 ( struct V_15 * V_15 )
{
return V_15 -> V_49 . V_50 . V_137 & V_138 ;
}
static void F_126 ( struct V_17 * V_18 , T_1 V_178 )
{
bool V_179 ;
V_179 = F_127 ( V_18 ) ;
if ( V_179 )
F_128 ( V_18 , V_180 , V_178 ) ;
else {
F_128 ( V_18 , V_181 , V_178 >> 32 ) ;
F_128 ( V_18 , V_180 , V_178 & 0xffffffff ) ;
}
}
static int F_129 ( struct V_17 * V_18 )
{
struct V_182 * V_183 = V_18 -> V_183 ;
F_126 ( V_18 , V_183 -> V_50 . V_52 . V_184 . V_178 ) ;
return 1 ;
}
int F_130 ( struct V_17 * V_18 )
{
T_1 V_185 , V_186 , V_187 , V_56 ;
T_8 V_188 , V_189 , V_190 , V_191 = V_192 , V_193 = 0 ;
bool V_194 , V_179 ;
if ( V_143 -> V_195 ( V_18 ) != 0 || ! F_131 ( V_18 ) ) {
F_132 ( V_18 , V_196 ) ;
return 1 ;
}
V_179 = F_127 ( V_18 ) ;
if ( ! V_179 ) {
V_185 = ( ( T_1 ) F_133 ( V_18 , V_181 ) << 32 ) |
( F_133 ( V_18 , V_180 ) & 0xffffffff ) ;
V_186 = ( ( T_1 ) F_133 ( V_18 , V_197 ) << 32 ) |
( F_133 ( V_18 , V_198 ) & 0xffffffff ) ;
V_187 = ( ( T_1 ) F_133 ( V_18 , V_199 ) << 32 ) |
( F_133 ( V_18 , V_200 ) & 0xffffffff ) ;
}
#ifdef F_134
else {
V_185 = F_133 ( V_18 , V_198 ) ;
V_186 = F_133 ( V_18 , V_181 ) ;
V_187 = F_133 ( V_18 , V_201 ) ;
}
#endif
V_188 = V_185 & 0xffff ;
V_194 = ( V_185 >> 16 ) & 0x1 ;
V_190 = ( V_185 >> 32 ) & 0xfff ;
V_189 = ( V_185 >> 48 ) & 0xfff ;
F_135 ( V_188 , V_194 , V_190 , V_189 , V_186 , V_187 ) ;
if ( V_190 || V_189 ) {
V_191 = V_202 ;
goto V_203;
}
switch ( V_188 ) {
case V_204 :
F_136 ( V_18 ) ;
break;
case V_205 :
case V_206 :
if ( ! F_16 ( V_18 ) -> V_20 ) {
V_191 = V_202 ;
break;
}
V_18 -> V_183 -> V_207 = V_208 ;
V_18 -> V_183 -> V_50 . type = V_209 ;
V_18 -> V_183 -> V_50 . V_52 . V_184 . V_210 = V_185 ;
V_18 -> V_183 -> V_50 . V_52 . V_184 . V_211 [ 0 ] = V_186 ;
V_18 -> V_183 -> V_50 . V_52 . V_184 . V_211 [ 1 ] = V_187 ;
V_18 -> V_49 . V_212 =
F_129 ;
return 0 ;
default:
V_191 = V_202 ;
break;
}
V_203:
V_56 = V_191 | ( ( ( T_1 ) V_193 & 0xfff ) << 32 ) ;
F_126 ( V_18 , V_56 ) ;
return 1 ;
}
