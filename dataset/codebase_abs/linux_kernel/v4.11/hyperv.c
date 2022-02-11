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
static int F_38 ( struct V_1 * V_2 , T_2 V_3 )
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
V_69 . V_72 = V_73 ;
V_69 . V_74 = V_75 ;
V_69 . V_76 = V_77 ;
V_69 . V_7 = V_7 ;
V_69 . V_78 = 1 ;
V_56 = F_39 ( V_18 -> V_15 , V_18 -> V_49 . V_79 , & V_69 , NULL ) ;
F_40 ( V_18 -> V_16 , V_3 , V_69 . V_7 , V_56 ) ;
return V_56 ;
}
int F_41 ( struct V_15 * V_15 , T_2 V_16 , T_2 V_3 )
{
struct V_1 * V_2 ;
V_2 = F_13 ( V_15 , V_16 ) ;
if ( ! V_2 )
return - V_70 ;
return F_38 ( V_2 , V_3 ) ;
}
void F_42 ( struct V_17 * V_18 , int V_7 )
{
struct V_1 * V_2 = F_16 ( V_18 ) ;
int V_8 ;
F_43 ( V_18 -> V_16 , V_7 ) ;
for ( V_8 = 0 ; V_8 < F_5 ( V_2 -> V_3 ) ; V_8 ++ )
if ( F_3 ( F_1 ( V_2 , V_8 ) ) == V_7 )
F_25 ( V_18 , V_8 ) ;
}
static int F_44 ( struct V_15 * V_15 , T_2 V_16 , T_2 V_3 , int V_37 )
{
struct V_1 * V_2 ;
V_2 = F_13 ( V_15 , V_16 ) ;
if ( ! V_2 )
return - V_70 ;
if ( V_3 >= F_5 ( V_2 -> V_47 ) )
return - V_70 ;
F_45 ( & V_2 -> V_47 [ V_3 ] , V_37 ) ;
return 0 ;
}
void F_46 ( struct V_15 * V_15 )
{
struct V_80 * V_81 ;
struct V_82 * V_83 ;
T_2 V_37 ;
V_81 = F_47 ( V_15 -> V_84 , & V_15 -> V_46 ,
F_48 ( & V_15 -> V_85 ) ) ;
for ( V_37 = 0 ; V_37 < V_81 -> V_86 ; V_37 ++ ) {
F_49 (e, &irq_rt->map[gsi], link) {
if ( V_83 -> type == V_87 )
F_44 ( V_15 , V_83 -> V_88 . V_18 ,
V_83 -> V_88 . V_3 , V_37 ) ;
}
}
}
static void F_50 ( struct V_1 * V_2 )
{
int V_8 ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_59 = V_89 ;
for ( V_8 = 0 ; V_8 < F_5 ( V_2 -> V_3 ) ; V_8 ++ ) {
F_8 ( & V_2 -> V_3 [ V_8 ] , V_5 ) ;
F_45 ( & V_2 -> V_47 [ V_8 ] , - 1 ) ;
}
}
static T_1 F_51 ( struct V_15 * V_15 )
{
struct V_90 * V_91 = & V_15 -> V_49 . V_50 ;
struct V_17 * V_18 ;
T_1 V_92 ;
if ( ! V_91 -> V_93 . V_94 )
return F_52 ( F_53 ( V_15 ) , 100 ) ;
V_18 = F_15 ( V_15 , 0 ) ;
V_92 = F_54 ( V_18 , F_55 () ) ;
return F_56 ( V_92 , V_91 -> V_93 . V_95 , 64 )
+ V_91 -> V_93 . V_96 ;
}
static void F_57 ( struct V_35 * V_36 ,
bool V_97 )
{
struct V_17 * V_18 = F_58 ( V_36 ) ;
F_29 ( V_36 -> V_43 ,
F_26 ( V_18 ) -> V_44 ) ;
F_11 ( V_45 , V_18 ) ;
if ( V_97 )
F_59 ( V_18 ) ;
}
static void F_60 ( struct V_35 * V_36 )
{
struct V_17 * V_18 = F_58 ( V_36 ) ;
F_61 ( F_58 ( V_36 ) -> V_16 ,
V_36 -> V_43 ) ;
F_62 ( & V_36 -> V_98 ) ;
F_63 ( V_36 -> V_43 ,
F_26 ( V_18 ) -> V_44 ) ;
V_36 -> V_32 = false ;
V_36 -> V_99 = 0 ;
}
static enum V_100 F_64 ( struct V_101 * V_98 )
{
struct V_35 * V_36 ;
V_36 = F_65 ( V_98 , struct V_35 , V_98 ) ;
F_66 ( F_58 ( V_36 ) -> V_16 ,
V_36 -> V_43 ) ;
F_57 ( V_36 , true ) ;
return V_102 ;
}
static int F_67 ( struct V_35 * V_36 )
{
T_1 V_103 ;
T_4 V_104 ;
V_103 = F_51 ( F_58 ( V_36 ) -> V_15 ) ;
V_104 = F_68 () ;
if ( V_36 -> V_41 & V_105 ) {
if ( V_36 -> V_99 ) {
if ( V_103 >= V_36 -> V_99 ) {
T_1 V_106 ;
F_69 ( V_103 - V_36 -> V_99 ,
V_36 -> V_107 , & V_106 ) ;
V_36 -> V_99 =
V_103 + ( V_36 -> V_107 - V_106 ) ;
}
} else
V_36 -> V_99 = V_103 + V_36 -> V_107 ;
F_70 (
F_58 ( V_36 ) -> V_16 ,
V_36 -> V_43 ,
V_103 , V_36 -> V_99 ) ;
F_71 ( & V_36 -> V_98 ,
F_72 ( V_104 ,
100 * ( V_36 -> V_99 - V_103 ) ) ,
V_108 ) ;
return 0 ;
}
V_36 -> V_99 = V_36 -> V_107 ;
if ( V_103 >= V_36 -> V_107 ) {
F_57 ( V_36 , false ) ;
return 0 ;
}
F_73 ( F_58 ( V_36 ) -> V_16 ,
V_36 -> V_43 ,
V_103 , V_36 -> V_107 ) ;
F_71 ( & V_36 -> V_98 ,
F_72 ( V_104 , 100 * ( V_36 -> V_107 - V_103 ) ) ,
V_108 ) ;
return 0 ;
}
static int F_74 ( struct V_35 * V_36 , T_1 V_41 ,
bool V_11 )
{
F_75 ( F_58 ( V_36 ) -> V_16 ,
V_36 -> V_43 , V_41 , V_11 ) ;
F_60 ( V_36 ) ;
if ( ( V_36 -> V_41 & V_42 ) && F_28 ( V_41 ) == 0 )
V_41 &= ~ V_42 ;
V_36 -> V_41 = V_41 ;
F_57 ( V_36 , false ) ;
return 0 ;
}
static int F_76 ( struct V_35 * V_36 , T_1 V_107 ,
bool V_11 )
{
F_77 ( F_58 ( V_36 ) -> V_16 ,
V_36 -> V_43 , V_107 , V_11 ) ;
F_60 ( V_36 ) ;
V_36 -> V_107 = V_107 ;
if ( V_36 -> V_107 == 0 )
V_36 -> V_41 &= ~ V_42 ;
else if ( V_36 -> V_41 & V_109 )
V_36 -> V_41 |= V_42 ;
F_57 ( V_36 , false ) ;
return 0 ;
}
static int F_78 ( struct V_35 * V_36 , T_1 * V_110 )
{
* V_110 = V_36 -> V_41 ;
return 0 ;
}
static int F_79 ( struct V_35 * V_36 , T_1 * V_111 )
{
* V_111 = V_36 -> V_107 ;
return 0 ;
}
static int F_80 ( struct V_1 * V_2 , T_2 V_3 ,
struct V_23 * V_112 )
{
struct V_17 * V_18 = F_12 ( V_2 ) ;
struct V_21 * V_21 ;
T_3 V_22 ;
struct V_23 * V_113 ;
int V_114 ;
struct V_25 * V_26 ;
if ( ! ( V_2 -> V_26 & V_40 ) )
return - V_71 ;
V_22 = V_2 -> V_26 & V_27 ;
V_21 = F_18 ( V_18 , V_22 >> V_28 ) ;
if ( F_19 ( V_21 ) )
return - V_115 ;
V_26 = F_21 ( V_21 ) ;
V_113 = & V_26 -> V_29 [ V_3 ] ;
if ( F_81 ( & V_113 -> V_30 . V_116 , V_117 ,
V_112 -> V_30 . V_116 ) != V_117 ) {
V_113 -> V_30 . V_31 . V_32 = 1 ;
V_114 = - V_118 ;
} else {
memcpy ( & V_113 -> V_52 . V_119 , & V_112 -> V_52 . V_119 ,
V_112 -> V_30 . V_120 ) ;
V_113 -> V_30 . V_116 = V_112 -> V_30 . V_116 ;
V_113 -> V_30 . V_120 = V_112 -> V_30 . V_120 ;
V_114 = F_38 ( V_2 , V_3 ) ;
if ( V_114 >= 1 )
V_114 = 0 ;
else if ( V_114 == 0 )
V_114 = - V_115 ;
}
F_22 ( V_26 ) ;
F_23 ( V_21 ) ;
F_24 ( V_18 , V_22 >> V_28 ) ;
return V_114 ;
}
static int F_82 ( struct V_35 * V_36 )
{
struct V_17 * V_18 = F_58 ( V_36 ) ;
struct V_23 * V_24 = & V_36 -> V_24 ;
struct V_121 * V_119 =
(struct V_121 * ) & V_24 -> V_52 . V_119 ;
V_119 -> V_122 = V_36 -> V_99 ;
V_119 -> V_123 = F_51 ( V_18 -> V_15 ) ;
return F_80 ( F_16 ( V_18 ) ,
F_28 ( V_36 -> V_41 ) , V_24 ) ;
}
static void F_83 ( struct V_35 * V_36 )
{
int V_114 ;
V_36 -> V_32 = true ;
V_114 = F_82 ( V_36 ) ;
F_84 ( F_58 ( V_36 ) -> V_16 ,
V_36 -> V_43 , V_114 ) ;
if ( ! V_114 ) {
V_36 -> V_32 = false ;
if ( ! ( V_36 -> V_41 & V_105 ) )
V_36 -> V_41 &= ~ V_42 ;
}
}
void F_85 ( struct V_17 * V_18 )
{
struct V_33 * V_34 = F_26 ( V_18 ) ;
struct V_35 * V_36 ;
T_1 V_103 , V_99 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < F_5 ( V_34 -> V_36 ) ; V_8 ++ )
if ( F_86 ( V_8 , V_34 -> V_44 ) ) {
V_36 = & V_34 -> V_36 [ V_8 ] ;
if ( V_36 -> V_41 & V_42 ) {
V_99 = V_36 -> V_99 ;
if ( V_99 ) {
V_103 =
F_51 ( V_18 -> V_15 ) ;
if ( V_103 >= V_99 )
F_83 ( V_36 ) ;
}
if ( ( V_36 -> V_41 & V_42 ) &&
V_36 -> V_107 )
F_67 ( V_36 ) ;
else
F_60 ( V_36 ) ;
}
}
}
void F_87 ( struct V_17 * V_18 )
{
struct V_33 * V_34 = F_26 ( V_18 ) ;
int V_8 ;
for ( V_8 = 0 ; V_8 < F_5 ( V_34 -> V_36 ) ; V_8 ++ )
F_60 ( & V_34 -> V_36 [ V_8 ] ) ;
}
static void F_88 ( struct V_35 * V_36 )
{
struct V_23 * V_24 = & V_36 -> V_24 ;
struct V_121 * V_119 =
(struct V_121 * ) & V_24 -> V_52 . V_119 ;
memset ( & V_24 -> V_30 , 0 , sizeof( V_24 -> V_30 ) ) ;
V_24 -> V_30 . V_116 = V_124 ;
V_24 -> V_30 . V_120 = sizeof( * V_119 ) ;
V_119 -> V_125 = V_36 -> V_43 ;
V_119 -> V_122 = 0 ;
V_119 -> V_123 = 0 ;
}
static void F_89 ( struct V_35 * V_36 , int V_125 )
{
memset ( V_36 , 0 , sizeof( * V_36 ) ) ;
V_36 -> V_43 = V_125 ;
F_90 ( & V_36 -> V_98 , V_126 , V_108 ) ;
V_36 -> V_98 . V_127 = F_64 ;
F_88 ( V_36 ) ;
}
void F_91 ( struct V_17 * V_18 )
{
struct V_33 * V_34 = F_26 ( V_18 ) ;
int V_8 ;
F_50 ( & V_34 -> V_2 ) ;
F_92 ( V_34 -> V_44 , V_128 ) ;
for ( V_8 = 0 ; V_8 < F_5 ( V_34 -> V_36 ) ; V_8 ++ )
F_89 ( & V_34 -> V_36 [ V_8 ] , V_8 ) ;
}
int F_93 ( struct V_17 * V_18 )
{
F_94 ( V_18 ) ;
F_16 ( V_18 ) -> V_20 = true ;
return 0 ;
}
static bool F_95 ( T_2 V_48 )
{
bool V_114 = false ;
switch ( V_48 ) {
case V_129 :
case V_130 :
case V_131 :
case V_132 :
case V_133 :
case V_134 ... V_135 :
case V_136 :
V_114 = true ;
break;
}
return V_114 ;
}
static int F_96 ( struct V_17 * V_18 ,
T_2 V_43 , T_1 * V_67 )
{
struct V_90 * V_91 = & V_18 -> V_15 -> V_49 . V_50 ;
if ( F_97 ( V_43 >= F_5 ( V_91 -> V_137 ) ) )
return - V_70 ;
* V_67 = V_91 -> V_137 [ V_43 ] ;
return 0 ;
}
static int F_98 ( struct V_17 * V_18 , T_1 * V_67 )
{
struct V_90 * V_91 = & V_18 -> V_15 -> V_49 . V_50 ;
* V_67 = V_91 -> V_138 ;
return 0 ;
}
static int F_99 ( struct V_17 * V_18 , T_1 V_10 , bool V_11 )
{
struct V_90 * V_91 = & V_18 -> V_15 -> V_49 . V_50 ;
if ( V_11 )
V_91 -> V_138 = V_10 & V_139 ;
if ( ! V_11 && ( V_10 & V_139 ) ) {
F_100 ( V_18 , L_2 ,
V_91 -> V_137 [ 0 ] ,
V_91 -> V_137 [ 1 ] ,
V_91 -> V_137 [ 2 ] ,
V_91 -> V_137 [ 3 ] ,
V_91 -> V_137 [ 4 ] ) ;
F_11 ( V_140 , V_18 ) ;
}
return 0 ;
}
static int F_101 ( struct V_17 * V_18 ,
T_2 V_43 , T_1 V_10 )
{
struct V_90 * V_91 = & V_18 -> V_15 -> V_49 . V_50 ;
if ( F_97 ( V_43 >= F_5 ( V_91 -> V_137 ) ) )
return - V_70 ;
V_91 -> V_137 [ V_43 ] = V_10 ;
return 0 ;
}
static bool F_102 ( struct V_141 * V_142 ,
T_5 * V_93 )
{
T_1 V_143 ;
if ( ! ( V_142 -> V_144 & V_145 ) )
return false ;
V_143 = 100ull << ( 32 - V_142 -> V_146 ) ;
if ( V_142 -> V_147 >= V_143 )
return false ;
V_93 -> V_95 =
F_103 ( 1ULL << ( 32 + V_142 -> V_146 ) ,
V_142 -> V_147 ,
100 ) ;
V_93 -> V_96 = V_142 -> V_148 ;
F_104 ( V_93 -> V_96 , 100 ) ;
V_93 -> V_96 -=
F_56 ( V_142 -> V_149 , V_93 -> V_95 , 64 ) ;
return true ;
}
void F_105 ( struct V_15 * V_15 ,
struct V_141 * V_142 )
{
struct V_90 * V_91 = & V_15 -> V_49 . V_50 ;
T_2 V_150 ;
T_1 V_151 ;
F_106 ( sizeof( V_150 ) != sizeof( V_91 -> V_93 . V_94 ) ) ;
F_106 ( F_107 ( T_5 , V_94 ) != 0 ) ;
if ( ! ( V_91 -> V_152 & V_153 ) )
return;
F_108 ( & V_15 -> V_49 . V_50 . V_154 ) ;
if ( ! ( V_91 -> V_152 & V_153 ) )
goto V_155;
V_151 = V_91 -> V_152 >> V_156 ;
if ( F_109 ( F_110 ( V_15 , F_111 ( V_151 ) ,
& V_150 , sizeof( V_150 ) ) ) )
goto V_155;
V_91 -> V_93 . V_94 = 0 ;
if ( F_112 ( V_15 , F_111 ( V_151 ) ,
& V_91 -> V_93 , sizeof( V_91 -> V_93 . V_94 ) ) )
goto V_155;
if ( ! F_102 ( V_142 , & V_91 -> V_93 ) )
goto V_155;
F_113 () ;
if ( F_112 ( V_15 , F_111 ( V_151 ) , & V_91 -> V_93 , sizeof( V_91 -> V_93 ) ) )
goto V_155;
V_150 ++ ;
if ( V_150 == 0xFFFFFFFF || V_150 == 0 )
V_150 = 1 ;
F_113 () ;
V_91 -> V_93 . V_94 = V_150 ;
F_112 ( V_15 , F_111 ( V_151 ) ,
& V_91 -> V_93 , sizeof( V_91 -> V_93 . V_94 ) ) ;
V_155:
F_114 ( & V_15 -> V_49 . V_50 . V_154 ) ;
}
static int F_115 ( struct V_17 * V_18 , T_2 V_48 , T_1 V_10 ,
bool V_11 )
{
struct V_15 * V_15 = V_18 -> V_15 ;
struct V_90 * V_91 = & V_15 -> V_49 . V_50 ;
switch ( V_48 ) {
case V_129 :
V_91 -> V_157 = V_10 ;
if ( ! V_91 -> V_157 )
V_91 -> V_158 &= ~ V_159 ;
break;
case V_130 : {
T_1 V_151 ;
unsigned long V_160 ;
T_6 V_161 [ 4 ] ;
if ( ! V_91 -> V_157 )
break;
if ( ! ( V_10 & V_159 ) ) {
V_91 -> V_158 = V_10 ;
break;
}
V_151 = V_10 >> V_162 ;
V_160 = F_116 ( V_15 , V_151 ) ;
if ( F_117 ( V_160 ) )
return 1 ;
V_163 -> V_164 ( V_18 , V_161 ) ;
( ( unsigned char * ) V_161 ) [ 3 ] = 0xc3 ;
if ( F_118 ( ( void V_165 * ) V_160 , V_161 , 4 ) )
return 1 ;
V_91 -> V_158 = V_10 ;
F_119 ( V_15 , V_151 ) ;
break;
}
case V_131 :
V_91 -> V_152 = V_10 ;
if ( V_91 -> V_152 & V_153 )
F_11 ( V_166 , V_18 ) ;
break;
case V_134 ... V_135 :
return F_101 ( V_18 ,
V_48 - V_134 ,
V_10 ) ;
case V_133 :
return F_99 ( V_18 , V_10 , V_11 ) ;
case V_136 :
if ( V_10 == 1 ) {
F_100 ( V_18 , L_3 ) ;
F_11 ( V_167 , V_18 ) ;
}
break;
default:
F_120 ( V_18 , L_4 ,
V_48 , V_10 ) ;
return 1 ;
}
return 0 ;
}
static T_1 F_121 ( void )
{
T_1 V_168 , V_169 ;
F_122 ( V_170 , & V_168 , & V_169 ) ;
return F_52 ( V_168 + V_169 , 100 ) ;
}
static int F_123 ( struct V_17 * V_18 , T_2 V_48 , T_1 V_10 , bool V_11 )
{
struct V_33 * V_91 = & V_18 -> V_49 . V_50 ;
switch ( V_48 ) {
case V_171 : {
T_1 V_151 ;
unsigned long V_160 ;
if ( ! ( V_10 & V_172 ) ) {
V_91 -> V_173 = V_10 ;
if ( F_124 ( V_18 , 0 ) )
return 1 ;
break;
}
V_151 = V_10 >> V_174 ;
V_160 = F_125 ( V_18 , V_151 ) ;
if ( F_117 ( V_160 ) )
return 1 ;
if ( F_126 ( ( void V_165 * ) V_160 , V_62 ) )
return 1 ;
V_91 -> V_173 = V_10 ;
F_24 ( V_18 , V_151 ) ;
if ( F_124 ( V_18 ,
F_111 ( V_151 ) | V_175 ) )
return 1 ;
break;
}
case V_176 :
return F_127 ( V_18 , V_177 , V_10 ) ;
case V_178 :
return F_127 ( V_18 , V_179 , V_10 ) ;
case V_180 :
return F_127 ( V_18 , V_181 , V_10 ) ;
case V_182 :
if ( ! V_11 )
return 1 ;
V_91 -> V_183 = V_10 - F_121 () ;
break;
case V_57 :
case V_58 :
case V_60 :
case V_63 :
case V_64 :
case V_65 ... V_66 :
return F_34 ( F_16 ( V_18 ) , V_48 , V_10 , V_11 ) ;
case V_184 :
case V_185 :
case V_186 :
case V_187 : {
int V_125 = ( V_48 - V_184 ) / 2 ;
return F_74 ( F_128 ( V_18 , V_125 ) ,
V_10 , V_11 ) ;
}
case V_188 :
case V_189 :
case V_190 :
case V_191 : {
int V_125 = ( V_48 - V_188 ) / 2 ;
return F_76 ( F_128 ( V_18 , V_125 ) ,
V_10 , V_11 ) ;
}
default:
F_120 ( V_18 , L_4 ,
V_48 , V_10 ) ;
return 1 ;
}
return 0 ;
}
static int F_129 ( struct V_17 * V_18 , T_2 V_48 , T_1 * V_67 )
{
T_1 V_10 = 0 ;
struct V_15 * V_15 = V_18 -> V_15 ;
struct V_90 * V_91 = & V_15 -> V_49 . V_50 ;
switch ( V_48 ) {
case V_129 :
V_10 = V_91 -> V_157 ;
break;
case V_130 :
V_10 = V_91 -> V_158 ;
break;
case V_132 :
V_10 = F_51 ( V_15 ) ;
break;
case V_131 :
V_10 = V_91 -> V_152 ;
break;
case V_134 ... V_135 :
return F_96 ( V_18 ,
V_48 - V_134 ,
V_67 ) ;
case V_133 :
return F_98 ( V_18 , V_67 ) ;
case V_136 :
V_10 = 0 ;
break;
default:
F_120 ( V_18 , L_5 , V_48 ) ;
return 1 ;
}
* V_67 = V_10 ;
return 0 ;
}
static int F_130 ( struct V_17 * V_18 , T_2 V_48 , T_1 * V_67 )
{
T_1 V_10 = 0 ;
struct V_33 * V_91 = & V_18 -> V_49 . V_50 ;
switch ( V_48 ) {
case V_192 : {
int V_114 ;
struct V_17 * V_193 ;
F_131 (r, v, vcpu->kvm) {
if ( V_193 == V_18 ) {
V_10 = V_114 ;
break;
}
}
break;
}
case V_176 :
return F_132 ( V_18 , V_177 , V_67 ) ;
case V_178 :
return F_132 ( V_18 , V_179 , V_67 ) ;
case V_180 :
return F_132 ( V_18 , V_181 , V_67 ) ;
case V_171 :
V_10 = V_91 -> V_173 ;
break;
case V_182 :
V_10 = F_121 () + V_91 -> V_183 ;
break;
case V_57 :
case V_58 :
case V_60 :
case V_63 :
case V_64 :
case V_65 ... V_66 :
return F_37 ( F_16 ( V_18 ) , V_48 , V_67 ) ;
case V_184 :
case V_185 :
case V_186 :
case V_187 : {
int V_125 = ( V_48 - V_184 ) / 2 ;
return F_78 ( F_128 ( V_18 , V_125 ) ,
V_67 ) ;
}
case V_188 :
case V_189 :
case V_190 :
case V_191 : {
int V_125 = ( V_48 - V_188 ) / 2 ;
return F_79 ( F_128 ( V_18 , V_125 ) ,
V_67 ) ;
}
default:
F_120 ( V_18 , L_5 , V_48 ) ;
return 1 ;
}
* V_67 = V_10 ;
return 0 ;
}
int F_133 ( struct V_17 * V_18 , T_2 V_48 , T_1 V_10 , bool V_11 )
{
if ( F_95 ( V_48 ) ) {
int V_114 ;
F_108 ( & V_18 -> V_15 -> V_49 . V_50 . V_154 ) ;
V_114 = F_115 ( V_18 , V_48 , V_10 , V_11 ) ;
F_114 ( & V_18 -> V_15 -> V_49 . V_50 . V_154 ) ;
return V_114 ;
} else
return F_123 ( V_18 , V_48 , V_10 , V_11 ) ;
}
int F_134 ( struct V_17 * V_18 , T_2 V_48 , T_1 * V_67 )
{
if ( F_95 ( V_48 ) ) {
int V_114 ;
F_108 ( & V_18 -> V_15 -> V_49 . V_50 . V_154 ) ;
V_114 = F_129 ( V_18 , V_48 , V_67 ) ;
F_114 ( & V_18 -> V_15 -> V_49 . V_50 . V_154 ) ;
return V_114 ;
} else
return F_130 ( V_18 , V_48 , V_67 ) ;
}
bool F_135 ( struct V_15 * V_15 )
{
return F_136 ( V_15 -> V_49 . V_50 . V_158 ) & V_159 ;
}
static void F_137 ( struct V_17 * V_18 , T_1 V_194 )
{
bool V_195 ;
V_195 = F_138 ( V_18 ) ;
if ( V_195 )
F_139 ( V_18 , V_196 , V_194 ) ;
else {
F_139 ( V_18 , V_197 , V_194 >> 32 ) ;
F_139 ( V_18 , V_196 , V_194 & 0xffffffff ) ;
}
}
static int F_140 ( struct V_17 * V_18 )
{
struct V_198 * V_199 = V_18 -> V_199 ;
F_137 ( V_18 , V_199 -> V_50 . V_52 . V_200 . V_194 ) ;
return 1 ;
}
int F_141 ( struct V_17 * V_18 )
{
T_1 V_201 , V_202 , V_203 , V_56 ;
T_7 V_204 , V_205 , V_206 , V_207 = V_208 , V_209 = 0 ;
bool V_210 , V_195 ;
if ( V_163 -> V_211 ( V_18 ) != 0 || ! F_142 ( V_18 ) ) {
F_143 ( V_18 , V_212 ) ;
return 1 ;
}
V_195 = F_138 ( V_18 ) ;
if ( ! V_195 ) {
V_201 = ( ( T_1 ) F_144 ( V_18 , V_197 ) << 32 ) |
( F_144 ( V_18 , V_196 ) & 0xffffffff ) ;
V_202 = ( ( T_1 ) F_144 ( V_18 , V_213 ) << 32 ) |
( F_144 ( V_18 , V_214 ) & 0xffffffff ) ;
V_203 = ( ( T_1 ) F_144 ( V_18 , V_215 ) << 32 ) |
( F_144 ( V_18 , V_216 ) & 0xffffffff ) ;
}
#ifdef F_145
else {
V_201 = F_144 ( V_18 , V_214 ) ;
V_202 = F_144 ( V_18 , V_197 ) ;
V_203 = F_144 ( V_18 , V_217 ) ;
}
#endif
V_204 = V_201 & 0xffff ;
V_210 = ( V_201 >> 16 ) & 0x1 ;
V_206 = ( V_201 >> 32 ) & 0xfff ;
V_205 = ( V_201 >> 48 ) & 0xfff ;
F_146 ( V_204 , V_210 , V_206 , V_205 , V_202 , V_203 ) ;
if ( V_206 || V_205 ) {
V_207 = V_218 ;
goto V_219;
}
switch ( V_204 ) {
case V_220 :
F_147 ( V_18 ) ;
break;
case V_221 :
case V_222 :
if ( ! F_16 ( V_18 ) -> V_20 ) {
V_207 = V_218 ;
break;
}
V_18 -> V_199 -> V_223 = V_224 ;
V_18 -> V_199 -> V_50 . type = V_225 ;
V_18 -> V_199 -> V_50 . V_52 . V_200 . V_226 = V_201 ;
V_18 -> V_199 -> V_50 . V_52 . V_200 . V_227 [ 0 ] = V_202 ;
V_18 -> V_199 -> V_50 . V_52 . V_200 . V_227 [ 1 ] = V_203 ;
V_18 -> V_49 . V_228 =
F_140 ;
return 0 ;
default:
V_207 = V_218 ;
break;
}
V_219:
V_56 = V_207 | ( ( ( T_1 ) V_209 & 0xfff ) << 32 ) ;
F_137 ( V_18 , V_56 ) ;
return 1 ;
}
