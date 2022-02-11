static T_1 F_1 ( T_1 V_1 )
{
int V_2 ;
switch ( V_1 ) {
case V_3 :
V_2 = V_4 ;
break;
case V_5 :
case V_6 :
V_2 = V_7 ;
break;
case V_8 :
V_2 = V_9 ;
break;
case V_10 :
V_2 = V_11 ;
break;
case V_12 :
V_2 = V_13 ;
break;
case V_14 :
default:
V_2 = V_15 ;
}
return V_2 > 0 ? - V_2 : V_2 ;
}
static T_2 F_2 ( T_2 V_16 )
{
if ( V_17 == V_16 )
return V_18 ;
return V_19 ;
}
static inline void
F_3 ( struct V_20 * V_21 ,
struct V_22 * V_23 ,
struct V_22 * V_24 ,
T_3 type ,
T_4 V_25 ,
T_4 V_26 ,
struct V_27 * V_28 ,
T_5 V_29 ,
struct V_30 V_31 )
{
V_21 -> V_32 . V_23 = F_4 ( V_33 ,
V_19 ) ;
V_21 -> V_32 . V_24 = F_4 ( V_24 -> V_34 ,
F_2 ( V_24 -> V_34 ) ) ;
V_21 -> V_32 . V_35 = sizeof( * V_21 ) - sizeof( V_21 -> V_32 ) ;
V_21 -> V_36 = V_37 ;
V_21 -> type = type ;
V_21 -> V_38 = V_23 -> V_39 ;
V_21 -> V_40 = V_24 -> V_39 ;
memset ( & V_21 -> V_29 , 0 , sizeof( V_21 -> V_29 ) ) ;
memset ( & V_21 -> V_41 , 0 , sizeof( V_21 -> V_41 ) ) ;
switch ( V_21 -> type ) {
case V_42 :
V_21 -> V_43 . V_25 = 0 ;
break;
case V_44 :
case V_45 :
V_21 -> V_43 . V_25 = V_25 ;
break;
case V_46 :
case V_47 :
V_21 -> V_43 . V_31 = V_31 ;
break;
case V_48 :
case V_49 :
case V_50 :
V_21 -> V_43 . V_25 = 0 ;
break;
case V_51 :
V_21 -> V_43 . V_26 = V_26 ;
break;
case V_52 :
case V_53 :
memcpy ( & V_21 -> V_43 . V_28 , V_28 , sizeof( V_21 -> V_43 . V_28 ) ) ;
break;
case V_54 :
case V_55 :
V_21 -> V_43 . V_25 = V_25 ;
V_21 -> V_29 = V_29 ;
break;
}
}
static inline void
F_5 ( struct V_20 * V_21 ,
struct V_22 * V_56 ,
struct V_22 * V_57 )
{
F_6 ( V_56 , V_21 -> V_32 . V_24 . V_58 , V_21 -> V_40 ) ;
F_6 ( V_57 , V_21 -> V_32 . V_23 . V_58 , V_21 -> V_38 ) ;
}
static int
F_7 ( struct V_20 * V_21 ,
struct V_22 * V_23 ,
struct V_22 * V_24 ,
enum V_59 type ,
T_4 V_25 ,
T_4 V_26 ,
struct V_27 * V_28 ,
T_5 V_29 ,
struct V_30 V_31 ,
bool V_60 )
{
int V_2 ;
F_3 ( V_21 , V_23 , V_24 , type , V_25 , V_26 , V_28 ,
V_29 , V_31 ) ;
V_2 = F_8 ( & V_21 -> V_32 ) ;
if ( V_60 && ( V_2 < 0 ) )
return F_1 ( V_2 ) ;
return V_2 ;
}
static int
F_9 ( struct V_20 * V_21 ,
enum V_59 type ,
T_4 V_25 ,
T_4 V_26 ,
struct V_27 * V_28 ,
struct V_30 V_31 )
{
struct V_20 V_61 ;
struct V_22 V_23 , V_24 ;
if ( V_21 -> type == V_50 ) {
return 0 ;
} else {
F_5 ( V_21 , & V_23 , & V_24 ) ;
return F_7 ( & V_61 , & V_23 , & V_24 ,
type ,
V_25 , V_26 , V_28 ,
V_62 ,
V_31 , true ) ;
}
}
static int
F_10 ( struct V_22 * V_23 ,
struct V_22 * V_24 ,
enum V_59 type ,
T_4 V_25 ,
T_4 V_26 ,
struct V_27 * V_28 ,
struct V_30 V_31 )
{
static struct V_20 V_21 ;
return F_7 ( & V_21 , V_23 , V_24 , type ,
V_25 , V_26 , V_28 ,
V_62 , V_31 ,
false ) ;
}
static int
F_11 ( struct V_63 * V_64 ,
enum V_59 type ,
T_4 V_25 ,
T_4 V_26 ,
struct V_27 * V_28 ,
T_5 V_29 ,
struct V_30 V_31 )
{
struct V_20 * V_21 ;
struct V_65 * V_66 ;
int V_2 ;
V_66 = F_12 ( V_64 ) ;
if ( ! F_13 ( & V_66 -> V_67 ) )
return - V_15 ;
if ( ! F_13 ( & V_66 -> V_68 ) )
return - V_15 ;
V_21 = F_14 ( sizeof( * V_21 ) , V_69 ) ;
if ( ! V_21 )
return - V_4 ;
V_2 = F_7 ( V_21 , & V_66 -> V_67 ,
& V_66 -> V_68 , type , V_25 ,
V_26 , V_28 , V_29 , V_31 ,
true ) ;
F_15 ( V_21 ) ;
return V_2 ;
}
static int F_16 ( struct V_22 * V_24 ,
struct V_22 * V_23 ,
struct V_20 * V_21 )
{
if ( V_21 -> type == V_50 )
return 0 ;
return F_10 (
V_24 , V_23 ,
V_50 , 0 ,
0 , NULL , V_70 ) ;
}
static int F_17 ( struct V_63 * V_64 ,
struct V_20 * V_21 )
{
if ( V_21 -> type == V_50 )
return 0 ;
return F_11 ( V_64 ,
V_50 ,
0 , 0 , NULL , V_62 ,
V_70 ) ;
}
static int F_18 ( struct V_63 * V_64 , T_6 V_25 )
{
return F_11 (
V_64 ,
V_45 ,
V_25 , 0 , NULL ,
V_62 ,
V_70 ) ;
}
static int F_19 ( struct V_63 * V_64 , T_6 V_25 ,
T_5 V_36 )
{
return F_11 (
V_64 ,
V_55 ,
V_25 , 0 , NULL , V_36 ,
V_70 ) ;
}
static int F_20 ( struct V_63 * V_64 ,
struct V_30 V_31 )
{
return F_11 (
V_64 , V_46 , 0 ,
0 , NULL ,
V_62 , V_31 ) ;
}
static int F_21 ( struct V_63 * V_64 ,
struct V_30 V_31 )
{
return F_11 (
V_64 , V_47 ,
0 , 0 , NULL , V_62 ,
V_31 ) ;
}
static int F_22 ( struct V_20 * V_21 )
{
return F_9 (
V_21 ,
V_50 ,
0 , 0 , NULL ,
V_70 ) ;
}
static int F_23 ( struct V_22 * V_24 ,
struct V_22 * V_23 )
{
return F_10 (
V_24 , V_23 ,
V_42 ,
0 , 0 , NULL , V_70 ) ;
}
int F_24 ( struct V_22 * V_24 ,
struct V_22 * V_23 )
{
return F_10 (
V_24 , V_23 ,
V_48 , 0 ,
0 , NULL , V_70 ) ;
}
int F_25 ( struct V_22 * V_24 ,
struct V_22 * V_23 )
{
return F_10 (
V_24 , V_23 ,
V_49 , 0 ,
0 , NULL , V_70 ) ;
}
int F_26 ( struct V_63 * V_64 )
{
return F_11 (
V_64 , V_48 , 0 ,
0 , NULL , V_62 ,
V_70 ) ;
}
int F_27 ( struct V_63 * V_64 )
{
return F_11 (
V_64 , V_49 , 0 ,
0 , NULL , V_62 ,
V_70 ) ;
}
int F_28 ( struct V_63 * V_64 ,
struct V_27 * V_28 )
{
return F_11 (
V_64 , V_53 ,
0 , 0 , V_28 , V_62 ,
V_70 ) ;
}
int F_29 ( struct V_63 * V_64 ,
struct V_27 * V_28 )
{
return F_11 (
V_64 , V_52 ,
0 , 0 , V_28 , V_62 ,
V_70 ) ;
}
static int F_30 ( struct V_65 * V_66 , int V_26 )
{
return F_11 (
& V_66 -> V_64 ,
V_51 ,
0 , V_26 , NULL ,
V_62 ,
V_70 ) ;
}
static int F_31 ( struct V_63 * V_64 , T_6 V_25 )
{
return F_11 ( V_64 ,
V_44 ,
V_25 , 0 , NULL ,
V_62 ,
V_70 ) ;
}
static int F_32 ( struct V_63 * V_64 , T_6 V_25 ,
T_5 V_36 )
{
return F_11 (
V_64 , V_54 ,
V_25 , 0 , NULL , V_36 ,
V_70 ) ;
}
static struct V_63 * F_33 (
struct V_63 * V_71 ,
struct V_20 * V_21 )
{
struct V_65 * V_72 ;
struct V_65 * V_73 ;
struct V_63 * V_74 ;
struct V_22 V_23 ;
F_6 ( & V_23 , V_21 -> V_32 . V_23 . V_58 , V_21 -> V_38 ) ;
V_72 = F_12 ( V_71 ) ;
F_34 (vpending, &vlistener->pending_links,
pending_links) {
if ( F_35 ( & V_23 , & V_73 -> V_68 ) &&
V_21 -> V_40 == V_73 -> V_67 . V_39 ) {
V_74 = F_36 ( V_73 ) ;
F_37 ( V_74 ) ;
goto V_75;
}
}
V_74 = NULL ;
V_75:
return V_74 ;
}
static void F_38 ( struct V_63 * V_74 )
{
F_39 ( V_74 ) ;
}
static bool F_40 ( struct V_65 * V_76 , T_2 V_16 )
{
return V_76 -> V_77 ||
F_41 ( V_16 , V_76 -> V_78 -> V_79 ) ;
}
static bool F_42 ( struct V_65 * V_76 , T_2 V_16 )
{
if ( V_17 == V_16 )
return true ;
if ( V_76 -> V_80 != V_16 ) {
V_76 -> V_80 = V_16 ;
if ( ! F_40 ( V_76 , V_16 ) &&
( F_43 ( V_16 ) &
V_81 ) ) {
V_76 -> V_82 = false ;
} else {
V_76 -> V_82 = true ;
}
}
return V_76 -> V_82 ;
}
static int
F_44 ( struct V_83 * * V_84 ,
struct V_30 * V_31 ,
T_4 V_85 ,
T_4 V_86 ,
T_2 V_87 , T_2 V_88 , bool V_77 )
{
int V_2 = 0 ;
if ( V_77 ) {
V_2 = F_45 ( V_84 , V_31 , V_85 ,
V_86 ,
V_87 , V_88 ,
V_89 ) ;
if ( V_2 != V_8 )
goto V_90;
}
V_2 = F_45 ( V_84 , V_31 , V_85 , V_86 ,
V_87 , V_88 , V_91 ) ;
V_90:
if ( V_2 < 0 ) {
F_46 ( L_1 ,
V_2 ) ;
V_2 = F_1 ( V_2 ) ;
}
return V_2 ;
}
static int
F_47 ( T_2 V_92 ,
T_2 V_88 ,
T_7 V_93 ,
void * V_94 ,
struct V_30 * V_95 )
{
int V_2 = 0 ;
V_2 = F_48 ( V_92 , V_88 ,
V_89 ,
V_93 ,
V_94 , V_95 ) ;
if ( V_2 == V_8 )
V_2 = F_49 ( V_92 , V_88 ,
V_93 , V_94 ,
V_95 ) ;
return V_2 ;
}
static int F_50 ( void * V_96 , struct V_97 * V_32 )
{
struct V_63 * V_64 ;
T_6 V_25 ;
struct V_98 * V_99 ;
struct V_65 * V_66 ;
V_64 = (struct V_63 * ) V_96 ;
V_66 = F_12 ( V_64 ) ;
if ( ! F_42 ( V_66 , V_32 -> V_23 . V_58 ) )
return V_8 ;
V_25 = F_51 ( V_32 ) ;
V_99 = F_52 ( V_25 , V_100 ) ;
if ( ! V_99 )
return V_3 ;
F_37 ( V_64 ) ;
F_53 ( V_99 , V_25 ) ;
memcpy ( V_99 -> V_96 , V_32 , V_25 ) ;
F_54 ( V_64 , V_99 , 0 ) ;
return V_101 ;
}
static bool F_55 ( T_2 V_102 , T_2 V_103 )
{
static const T_2 V_104 [] = {
V_105 ,
} ;
int V_106 ;
F_56 ( sizeof( V_102 ) != sizeof( * V_104 ) ) ;
for ( V_106 = 0 ; V_106 < F_57 ( V_104 ) ; V_106 ++ ) {
if ( V_102 == V_104 [ V_106 ] )
return false ;
}
return true ;
}
static int F_58 ( void * V_96 , struct V_97 * V_32 )
{
struct V_63 * V_64 ;
struct V_22 V_24 ;
struct V_22 V_23 ;
struct V_20 * V_21 ;
struct V_65 * V_66 ;
bool V_107 ;
int V_2 ;
V_64 = NULL ;
V_2 = V_101 ;
V_107 = false ;
if ( ! F_55 ( V_32 -> V_23 . V_58 , - 1 )
|| F_2 ( V_32 -> V_23 . V_58 ) != V_32 -> V_23 . V_108 )
return V_8 ;
if ( F_51 ( V_32 ) < sizeof( * V_21 ) )
return V_14 ;
V_21 = (struct V_20 * ) V_32 ;
F_6 ( & V_23 , V_21 -> V_32 . V_23 . V_58 , V_21 -> V_38 ) ;
F_6 ( & V_24 , V_21 -> V_32 . V_24 . V_58 , V_21 -> V_40 ) ;
V_64 = F_59 ( & V_23 , & V_24 ) ;
if ( ! V_64 ) {
V_64 = F_60 ( & V_24 ) ;
if ( ! V_64 ) {
if ( F_16 ( & V_24 , & V_23 , V_21 ) < 0 )
F_46 ( L_2 ) ;
V_2 = V_109 ;
goto V_90;
}
}
if ( V_21 -> type >= V_110 ) {
F_23 ( & V_24 , & V_23 ) ;
V_2 = V_14 ;
goto V_90;
}
V_66 = F_12 ( V_64 ) ;
if ( ! F_42 ( V_66 , V_21 -> V_32 . V_23 . V_58 ) ) {
V_2 = V_8 ;
goto V_90;
}
F_61 ( V_64 ) ;
if ( ! F_62 ( V_64 ) ) {
V_66 -> V_67 . V_34 = V_24 . V_34 ;
if ( V_64 -> V_111 == V_112 )
F_63 ( V_66 ) -> V_113 -> V_114 (
V_64 , V_21 , true , & V_24 , & V_23 ,
& V_107 ) ;
}
F_64 ( V_64 ) ;
if ( ! V_107 ) {
struct V_115 * V_116 ;
V_116 = F_14 ( sizeof( * V_116 ) , V_100 ) ;
if ( ! V_116 ) {
if ( F_16 ( & V_24 , & V_23 , V_21 ) < 0 )
F_46 ( L_2 ) ;
V_2 = V_3 ;
goto V_90;
}
V_116 -> V_64 = V_64 ;
memcpy ( & V_116 -> V_21 , V_21 , sizeof( V_116 -> V_21 ) ) ;
F_65 ( & V_116 -> V_117 , V_118 ) ;
F_66 ( & V_116 -> V_117 ) ;
V_64 = NULL ;
}
V_90:
if ( V_64 )
F_39 ( V_64 ) ;
return V_2 ;
}
static void F_67 ( struct V_63 * V_64 )
{
struct V_65 * V_66 ;
V_66 = F_12 ( V_64 ) ;
if ( ! F_68 ( F_63 ( V_66 ) -> V_119 ) ) {
F_69 ( V_64 , V_120 ) ;
V_66 -> V_121 = V_122 ;
if ( F_70 ( V_66 ) <= 0 ) {
if ( V_64 -> V_111 == V_123 ) {
V_64 -> V_111 = V_124 ;
V_64 -> V_125 = V_126 ;
V_64 -> V_127 ( V_64 ) ;
return;
}
V_64 -> V_111 = V_124 ;
}
V_64 -> V_128 ( V_64 ) ;
}
}
static void F_71 ( T_2 V_129 ,
const struct V_130 * V_131 ,
void * V_94 )
{
struct V_132 * V_133 = V_94 ;
const struct V_134 * V_135 ;
V_135 = F_72 ( V_131 ) ;
if ( F_68 ( V_135 -> V_31 ) ||
! F_73 ( V_133 -> V_119 , V_135 -> V_31 ) )
return;
F_74 ( & V_133 -> V_136 ) ;
if ( ! V_133 -> V_64 )
goto V_90;
F_61 ( V_133 -> V_64 ) ;
F_67 ( V_133 -> V_64 ) ;
F_64 ( V_133 -> V_64 ) ;
V_90:
F_75 ( & V_133 -> V_136 ) ;
}
static void F_76 ( T_2 V_129 ,
const struct V_130 * V_131 ,
void * V_94 )
{
F_77 ( F_67 ) ;
}
static void V_118 ( struct V_137 * V_117 )
{
struct V_115 * V_116 ;
struct V_20 * V_21 ;
struct V_63 * V_64 ;
V_116 =
F_78 ( V_117 , struct V_115 , V_117 ) ;
V_64 = V_116 -> V_64 ;
V_21 = & V_116 -> V_21 ;
F_79 ( V_64 ) ;
F_12 ( V_64 ) -> V_67 . V_34 = V_21 -> V_32 . V_24 . V_58 ;
switch ( V_64 -> V_111 ) {
case V_138 :
F_80 ( V_64 , V_21 ) ;
break;
case V_123 :
F_81 ( V_64 , V_21 ) ;
break;
case V_112 :
F_82 ( V_64 , V_21 ) ;
break;
default:
F_17 ( V_64 , V_21 ) ;
break;
}
F_83 ( V_64 ) ;
F_15 ( V_116 ) ;
F_39 ( V_64 ) ;
}
static int F_80 ( struct V_63 * V_64 ,
struct V_20 * V_21 )
{
struct V_63 * V_74 ;
struct V_65 * V_73 ;
int V_2 ;
T_4 V_139 ;
bool V_140 = false ;
bool V_141 = false ;
V_2 = 0 ;
V_74 = F_33 ( V_64 , V_21 ) ;
if ( V_74 ) {
F_79 ( V_74 ) ;
F_12 ( V_74 ) -> V_67 . V_34 = V_21 -> V_32 . V_24 . V_58 ;
switch ( V_74 -> V_111 ) {
case V_123 :
V_2 = F_84 ( V_64 ,
V_74 ,
V_21 ) ;
break;
default:
F_17 ( V_74 , V_21 ) ;
V_2 = - V_15 ;
}
if ( V_2 < 0 )
F_85 ( V_64 , V_74 ) ;
F_83 ( V_74 ) ;
F_38 ( V_74 ) ;
return V_2 ;
}
if ( ! ( V_21 -> type == V_44 ||
V_21 -> type == V_54 ) ) {
F_22 ( V_21 ) ;
return - V_15 ;
}
if ( V_21 -> V_43 . V_25 == 0 ) {
F_22 ( V_21 ) ;
return - V_15 ;
}
if ( V_64 -> V_142 >= V_64 -> V_143 ) {
F_22 ( V_21 ) ;
return - V_144 ;
}
V_74 = F_86 ( F_87 ( V_64 ) , NULL , V_64 , V_69 ,
V_64 -> V_145 , 0 ) ;
if ( ! V_74 ) {
F_17 ( V_64 , V_21 ) ;
return - V_4 ;
}
V_73 = F_12 ( V_74 ) ;
F_6 ( & V_73 -> V_67 , V_21 -> V_32 . V_24 . V_58 ,
V_21 -> V_40 ) ;
F_6 ( & V_73 -> V_68 , V_21 -> V_32 . V_23 . V_58 ,
V_21 -> V_38 ) ;
if ( V_21 -> V_43 . V_25 >= F_63 ( V_73 ) -> V_146 &&
V_21 -> V_43 . V_25 <= F_63 ( V_73 ) -> V_147 ) {
V_139 = V_21 -> V_43 . V_25 ;
} else {
V_139 = F_63 ( V_73 ) -> V_148 ;
}
if ( F_88 ( & V_141 ) ) {
V_140 = V_141 ;
} else {
if ( V_21 -> type == V_44 )
V_140 = true ;
else if ( V_21 -> type == V_54 )
V_140 = false ;
}
if ( V_140 ) {
T_5 V_36 = V_62 ;
if ( F_89 (
V_74 , & V_36 , true ) )
V_2 = F_18 ( V_74 , V_139 ) ;
else
V_2 = - V_15 ;
} else {
int V_149 = V_21 -> V_29 ;
int V_150 ;
T_5 V_151 = 0 ;
V_149 &= F_90 () ;
V_150 = F_91 ( V_149 ) ;
if ( V_150 ) {
V_151 = ( 1 << ( V_150 - 1 ) ) ;
if ( F_89 (
V_74 , & V_151 , false ) )
V_2 = F_19 ( V_74 ,
V_139 ,
V_151 ) ;
else
V_2 = - V_15 ;
} else {
V_2 = - V_15 ;
}
}
if ( V_2 < 0 ) {
F_17 ( V_64 , V_21 ) ;
F_39 ( V_74 ) ;
V_2 = F_1 ( V_2 ) ;
goto V_90;
}
F_92 ( V_64 , V_74 ) ;
V_64 -> V_142 ++ ;
V_74 -> V_111 = V_123 ;
F_63 ( V_73 ) -> V_85 =
F_63 ( V_73 ) -> V_86 = V_139 ;
F_63 ( V_73 ) -> V_148 = V_139 ;
F_63 ( V_73 ) -> V_113 -> V_152 ( V_74 ) ;
V_73 -> V_71 = V_64 ;
F_37 ( V_64 ) ;
F_37 ( V_74 ) ;
F_93 ( & V_73 -> V_153 , V_154 ) ;
F_94 ( & V_73 -> V_153 , V_155 ) ;
V_90:
return V_2 ;
}
static int
F_84 ( struct V_63 * V_71 ,
struct V_63 * V_74 ,
struct V_20 * V_21 )
{
struct V_65 * V_73 ;
struct V_30 V_31 ;
struct V_83 * V_84 ;
bool V_156 ;
T_2 V_88 ;
T_2 V_157 ;
int V_2 ;
int V_158 ;
V_73 = F_12 ( V_74 ) ;
V_157 = V_159 ;
switch ( V_21 -> type ) {
case V_46 :
if ( F_68 ( V_21 -> V_43 . V_31 ) ) {
F_17 ( V_74 , V_21 ) ;
V_158 = V_160 ;
V_2 = - V_15 ;
goto V_161;
}
break;
default:
F_17 ( V_74 , V_21 ) ;
V_158 = V_160 ;
V_2 = V_21 -> type == V_50 ? 0 : - V_15 ;
goto V_161;
}
V_2 = F_95 ( V_162 ,
F_71 ,
F_63 ( V_73 ) , & V_157 ) ;
if ( V_2 < V_101 ) {
F_17 ( V_74 , V_21 ) ;
V_2 = F_1 ( V_2 ) ;
V_158 = - V_2 ;
goto V_161;
}
F_63 ( V_73 ) -> V_157 = V_157 ;
V_31 = V_21 -> V_43 . V_31 ;
V_156 =
V_73 -> V_68 . V_34 == V_73 -> V_67 . V_34 ;
V_88 = V_163 ;
V_88 |= V_156 ? V_164 : 0 ;
V_2 = F_44 (
& V_84 ,
& V_31 ,
F_63 ( V_73 ) -> V_85 ,
F_63 ( V_73 ) -> V_86 ,
V_21 -> V_32 . V_23 . V_58 ,
V_88 ,
F_40 (
V_73 ,
V_73 -> V_68 . V_34 ) ) ;
if ( V_2 < 0 ) {
F_17 ( V_74 , V_21 ) ;
V_158 = - V_2 ;
goto V_161;
}
F_63 ( V_73 ) -> V_119 = V_31 ;
F_63 ( V_73 ) -> V_84 = V_84 ;
V_74 -> V_111 = V_112 ;
F_96 ( V_73 ) ;
V_2 = F_21 ( V_74 , V_31 ) ;
if ( V_2 < 0 ) {
F_97 ( V_73 ) ;
F_46 ( L_3 ) ;
F_17 ( V_74 , V_21 ) ;
V_2 = F_1 ( V_2 ) ;
V_158 = - V_2 ;
goto V_161;
}
F_85 ( V_71 , V_74 ) ;
F_98 ( V_71 , V_74 ) ;
V_71 -> V_165 ( V_71 ) ;
return 0 ;
V_161:
V_74 -> V_125 = V_158 ;
V_74 -> V_111 = V_124 ;
F_39 ( V_74 ) ;
return V_2 ;
}
static int
F_81 ( struct V_63 * V_64 ,
struct V_20 * V_21 )
{
struct V_65 * V_66 ;
int V_2 ;
int V_158 ;
V_66 = F_12 ( V_64 ) ;
switch ( V_21 -> type ) {
case V_47 :
if ( F_68 ( V_21 -> V_43 . V_31 ) ||
! F_73 ( V_21 -> V_43 . V_31 ,
F_63 ( V_66 ) -> V_119 ) ) {
V_158 = V_160 ;
V_2 = - V_15 ;
goto V_161;
}
V_64 -> V_111 = V_112 ;
V_64 -> V_166 -> V_167 = V_112 ;
F_96 ( V_66 ) ;
V_64 -> V_128 ( V_64 ) ;
break;
case V_45 :
case V_55 :
if ( V_21 -> V_43 . V_25 == 0
|| V_21 -> V_32 . V_23 . V_58 != V_66 -> V_68 . V_34
|| V_21 -> V_38 != V_66 -> V_68 . V_39
|| ! F_68 ( F_63 ( V_66 ) -> V_119 )
|| F_63 ( V_66 ) -> V_84
|| F_63 ( V_66 ) -> V_85 != 0
|| F_63 ( V_66 ) -> V_86 != 0
|| F_63 ( V_66 ) -> V_157 != V_159 ) {
V_158 = V_160 ;
V_2 = - V_15 ;
goto V_161;
}
V_2 = F_99 ( V_64 , V_21 ) ;
if ( V_2 ) {
V_158 = - V_2 ;
goto V_161;
}
break;
case V_42 :
V_2 = F_100 ( V_64 , V_21 ) ;
if ( V_2 ) {
V_158 = - V_2 ;
goto V_161;
}
break;
case V_50 :
if ( V_66 -> V_168 ) {
V_66 -> V_168 = false ;
} else {
V_158 = V_126 ;
V_2 = 0 ;
goto V_161;
}
break;
default:
V_158 = V_160 ;
V_2 = - V_15 ;
goto V_161;
}
return 0 ;
V_161:
F_17 ( V_64 , V_21 ) ;
V_64 -> V_111 = V_124 ;
V_64 -> V_125 = V_158 ;
V_64 -> V_127 ( V_64 ) ;
return V_2 ;
}
static int F_99 (
struct V_63 * V_64 ,
struct V_20 * V_21 )
{
int V_2 ;
struct V_65 * V_66 ;
struct V_30 V_31 ;
struct V_83 * V_84 ;
T_2 V_157 ;
bool V_156 ;
T_2 V_88 ;
bool V_169 = true ;
bool V_141 ;
T_5 V_36 ;
V_66 = F_12 ( V_64 ) ;
V_31 = V_70 ;
V_157 = V_159 ;
V_66 -> V_170 = false ;
V_66 -> V_168 = false ;
if ( V_21 -> V_43 . V_25 < F_63 ( V_66 ) -> V_146 ||
V_21 -> V_43 . V_25 > F_63 ( V_66 ) -> V_147 ) {
V_2 = - V_15 ;
goto V_161;
}
if ( V_66 -> V_67 . V_34 == V_33 )
V_66 -> V_67 . V_34 = V_21 -> V_32 . V_24 . V_58 ;
if ( F_88 ( & V_141 ) ) {
V_169 = V_141 ;
} else {
if ( V_21 -> type == V_45 )
V_169 = true ;
else if ( V_21 -> type == V_55 )
V_169 = false ;
}
if ( V_169 )
V_36 = V_62 ;
else
V_36 = V_21 -> V_29 ;
if ( ! F_89 ( V_64 , & V_36 , V_169 ) ) {
V_2 = - V_15 ;
goto V_161;
}
V_2 = F_95 ( V_162 ,
F_71 ,
F_63 ( V_66 ) , & V_157 ) ;
if ( V_2 < V_101 ) {
V_2 = F_1 ( V_2 ) ;
goto V_161;
}
V_31 = V_70 ;
V_156 = V_66 -> V_68 . V_34 == V_66 -> V_67 . V_34 ;
V_88 = V_156 ? V_164 : 0 ;
V_2 = F_44 ( & V_84 ,
& V_31 ,
V_21 -> V_43 . V_25 ,
V_21 -> V_43 . V_25 ,
V_66 -> V_68 . V_34 ,
V_88 ,
F_40 (
V_66 ,
V_66 ->
V_68 . V_34 ) ) ;
if ( V_2 < 0 )
goto V_161;
V_2 = F_20 ( V_64 , V_31 ) ;
if ( V_2 < 0 ) {
V_2 = F_1 ( V_2 ) ;
goto V_161;
}
F_63 ( V_66 ) -> V_119 = V_31 ;
F_63 ( V_66 ) -> V_84 = V_84 ;
F_63 ( V_66 ) -> V_85 = F_63 ( V_66 ) -> V_86 =
V_21 -> V_43 . V_25 ;
F_63 ( V_66 ) -> V_157 = V_157 ;
F_63 ( V_66 ) -> V_113 -> V_171 ( V_64 ) ;
return 0 ;
V_161:
if ( V_157 != V_159 )
F_101 ( V_157 ) ;
if ( ! F_68 ( V_31 ) )
F_102 ( & V_84 ) ;
return V_2 ;
}
static int
F_100 ( struct V_63 * V_64 ,
struct V_20 * V_21 )
{
int V_2 = 0 ;
struct V_65 * V_66 = F_12 ( V_64 ) ;
if ( V_66 -> V_170 ) {
V_66 -> V_170 = false ;
V_66 -> V_168 = true ;
V_2 = F_31 (
V_64 , F_63 ( V_66 ) -> V_148 ) ;
if ( V_2 < 0 )
V_2 = F_1 ( V_2 ) ;
else
V_2 = 0 ;
}
return V_2 ;
}
static int F_82 ( struct V_63 * V_64 ,
struct V_20 * V_21 )
{
struct V_65 * V_66 ;
bool V_172 = false ;
switch ( V_21 -> type ) {
case V_51 :
if ( V_21 -> V_43 . V_26 ) {
V_66 = F_12 ( V_64 ) ;
V_66 -> V_121 |= V_21 -> V_43 . V_26 ;
V_64 -> V_128 ( V_64 ) ;
}
break;
case V_50 :
V_66 = F_12 ( V_64 ) ;
F_69 ( V_64 , V_120 ) ;
V_66 -> V_121 = V_122 ;
if ( F_70 ( V_66 ) <= 0 )
V_64 -> V_111 = V_173 ;
V_64 -> V_128 ( V_64 ) ;
break;
default:
V_66 = F_12 ( V_64 ) ;
F_63 ( V_66 ) -> V_113 -> V_114 (
V_64 , V_21 , false , NULL , NULL ,
& V_172 ) ;
if ( ! V_172 )
return - V_15 ;
break;
}
return 0 ;
}
static int F_103 ( struct V_65 * V_66 ,
struct V_65 * V_174 )
{
V_66 -> V_133 = F_14 ( sizeof( struct V_132 ) , V_69 ) ;
if ( ! V_66 -> V_133 )
return - V_4 ;
F_63 ( V_66 ) -> V_175 = V_70 ;
F_63 ( V_66 ) -> V_119 = V_70 ;
F_63 ( V_66 ) -> V_84 = NULL ;
F_63 ( V_66 ) -> V_85 = F_63 ( V_66 ) -> V_86 = 0 ;
F_63 ( V_66 ) -> V_157 = V_159 ;
F_63 ( V_66 ) -> V_113 = NULL ;
F_104 ( & F_63 ( V_66 ) -> V_176 ) ;
F_63 ( V_66 ) -> V_64 = & V_66 -> V_64 ;
F_105 ( & F_63 ( V_66 ) -> V_136 ) ;
if ( V_174 ) {
F_63 ( V_66 ) -> V_148 =
F_63 ( V_174 ) -> V_148 ;
F_63 ( V_66 ) -> V_146 =
F_63 ( V_174 ) -> V_146 ;
F_63 ( V_66 ) -> V_147 =
F_63 ( V_174 ) -> V_147 ;
} else {
F_63 ( V_66 ) -> V_148 =
V_177 ;
F_63 ( V_66 ) -> V_146 =
V_178 ;
F_63 ( V_66 ) -> V_147 =
V_179 ;
}
return 0 ;
}
static void F_106 ( struct V_180 * V_181 )
{
while ( ! F_107 ( V_181 ) ) {
struct V_132 * V_182 =
F_108 ( V_181 , struct V_132 ,
V_176 ) ;
F_109 ( & V_182 -> V_176 ) ;
if ( V_182 -> V_157 != V_159 ) {
F_101 ( V_182 -> V_157 ) ;
V_182 -> V_157 = V_159 ;
}
if ( ! F_68 ( V_182 -> V_119 ) ) {
F_102 ( & V_182 -> V_84 ) ;
V_182 -> V_119 = V_70 ;
V_182 -> V_85 = 0 ;
V_182 -> V_86 = 0 ;
}
F_15 ( V_182 ) ;
}
}
static void F_110 ( struct V_137 * V_117 )
{
F_111 ( V_74 ) ;
F_74 ( & V_183 ) ;
F_112 ( & V_184 , & V_74 ) ;
F_75 ( & V_183 ) ;
F_106 ( & V_74 ) ;
}
static void F_113 ( struct V_65 * V_66 )
{
F_74 ( & F_63 ( V_66 ) -> V_136 ) ;
F_63 ( V_66 ) -> V_64 = NULL ;
F_75 ( & F_63 ( V_66 ) -> V_136 ) ;
if ( F_63 ( V_66 ) -> V_113 )
F_63 ( V_66 ) -> V_113 -> V_185 ( V_66 ) ;
F_74 ( & V_183 ) ;
F_114 ( & F_63 ( V_66 ) -> V_176 , & V_184 ) ;
F_75 ( & V_183 ) ;
F_66 ( & V_186 ) ;
V_66 -> V_133 = NULL ;
}
static void F_115 ( struct V_65 * V_66 )
{
if ( ! F_68 ( F_63 ( V_66 ) -> V_175 ) ) {
F_116 ( F_63 ( V_66 ) -> V_175 ) ;
F_63 ( V_66 ) -> V_175 = V_70 ;
}
}
static int F_117 ( struct V_65 * V_66 ,
struct V_22 * V_187 )
{
T_2 V_103 ;
T_2 V_88 ;
int V_2 ;
V_103 = V_187 -> V_39 == V_188 ?
V_159 : V_187 -> V_39 ;
if ( V_103 <= V_189 && ! F_118 ( V_190 ) )
return - V_191 ;
V_88 = V_187 -> V_34 == V_33 ?
V_192 : 0 ;
V_2 = F_47 ( V_103 , V_88 ,
F_50 ,
& V_66 -> V_64 ,
& F_63 ( V_66 ) -> V_175 ) ;
if ( V_2 < V_101 )
return F_1 ( V_2 ) ;
F_6 ( & V_66 -> V_67 , V_187 -> V_34 ,
F_63 ( V_66 ) -> V_175 . V_108 ) ;
return 0 ;
}
static int F_119 (
struct V_65 * V_66 ,
struct V_22 * V_68 ,
struct V_193 * V_194 ,
T_6 V_195 )
{
int V_2 ;
struct V_97 * V_32 ;
if ( V_195 > V_196 )
return - V_197 ;
if ( ! F_42 ( V_66 , V_68 -> V_34 ) )
return - V_9 ;
V_32 = F_14 ( V_195 + sizeof( * V_32 ) , V_69 ) ;
if ( ! V_32 )
return - V_4 ;
F_120 ( F_121 ( V_32 ) , V_194 , V_195 ) ;
V_32 -> V_24 = F_4 ( V_68 -> V_34 ,
V_68 -> V_39 ) ;
V_32 -> V_23 = F_4 ( V_66 -> V_67 . V_34 ,
V_66 -> V_67 . V_39 ) ;
V_32 -> V_35 = V_195 ;
V_2 = F_8 ( V_32 ) ;
F_15 ( V_32 ) ;
if ( V_2 < 0 )
return F_1 ( V_2 ) ;
return V_2 - sizeof( * V_32 ) ;
}
static int F_122 ( struct V_65 * V_66 ,
struct V_193 * V_194 , T_6 V_195 ,
int V_88 )
{
int V_2 ;
int V_198 ;
struct V_97 * V_32 ;
T_6 V_199 ;
struct V_98 * V_99 ;
V_198 = V_88 & V_200 ;
if ( V_88 & V_201 || V_88 & V_202 )
return - V_203 ;
V_2 = 0 ;
V_99 = F_123 ( & V_66 -> V_64 , V_88 , V_198 , & V_2 ) ;
if ( ! V_99 )
return V_2 ;
V_32 = (struct V_97 * ) V_99 -> V_96 ;
if ( ! V_32 )
goto V_90;
V_199 = V_32 -> V_35 ;
if ( V_199 != V_99 -> V_195 - sizeof( * V_32 ) ) {
V_2 = - V_15 ;
goto V_90;
}
if ( V_199 > V_195 ) {
V_199 = V_195 ;
V_194 -> V_204 |= V_205 ;
}
V_2 = F_124 ( V_99 , sizeof( * V_32 ) , V_194 , V_199 ) ;
if ( V_2 )
goto V_90;
if ( V_194 -> V_206 ) {
F_125 ( struct V_22 * , V_207 , V_194 -> V_206 ) ;
F_6 ( V_207 , V_32 -> V_23 . V_58 , V_32 -> V_23 . V_108 ) ;
V_194 -> V_208 = sizeof( * V_207 ) ;
}
V_2 = V_199 ;
V_90:
F_126 ( & V_66 -> V_64 , V_99 ) ;
return V_2 ;
}
static bool F_127 ( T_2 V_102 , T_2 V_103 )
{
if ( V_102 == V_17 ) {
return V_103 == V_209 ;
}
return true ;
}
static int F_128 ( struct V_65 * V_66 )
{
int V_2 ;
bool V_141 = false ;
struct V_63 * V_64 = & V_66 -> V_64 ;
if ( F_88 ( & V_141 ) &&
V_141 ) {
V_2 = F_31 (
V_64 , F_63 ( V_66 ) -> V_148 ) ;
if ( V_2 < 0 ) {
V_64 -> V_111 = V_124 ;
return V_2 ;
}
} else {
int V_210 =
F_90 () ;
V_2 = F_32 (
V_64 , F_63 ( V_66 ) -> V_148 ,
V_210 ) ;
if ( V_2 < 0 ) {
V_64 -> V_111 = V_124 ;
return V_2 ;
}
V_66 -> V_170 = true ;
}
return V_2 ;
}
static T_8 F_129 (
struct V_65 * V_66 ,
struct V_193 * V_194 ,
T_6 V_195 ,
int V_88 )
{
if ( V_88 & V_211 )
return F_130 ( F_63 ( V_66 ) -> V_84 , V_194 , V_195 , 0 ) ;
else
return F_131 ( F_63 ( V_66 ) -> V_84 , V_194 , V_195 , 0 ) ;
}
static T_8 F_132 (
struct V_65 * V_66 ,
struct V_193 * V_194 ,
T_6 V_195 )
{
return F_133 ( F_63 ( V_66 ) -> V_84 , V_194 , V_195 , 0 ) ;
}
static T_9 F_134 ( struct V_65 * V_66 )
{
return F_135 ( F_63 ( V_66 ) -> V_84 ) ;
}
static T_9 F_136 ( struct V_65 * V_66 )
{
return F_137 ( F_63 ( V_66 ) -> V_84 ) ;
}
static T_4 F_138 ( struct V_65 * V_66 )
{
return F_63 ( V_66 ) -> V_86 ;
}
static bool F_139 ( struct V_65 * V_66 )
{
return ! F_68 ( F_63 ( V_66 ) -> V_119 ) ;
}
static T_4 F_140 ( struct V_65 * V_66 )
{
return F_63 ( V_66 ) -> V_148 ;
}
static T_4 F_141 ( struct V_65 * V_66 )
{
return F_63 ( V_66 ) -> V_146 ;
}
static T_4 F_142 ( struct V_65 * V_66 )
{
return F_63 ( V_66 ) -> V_147 ;
}
static void F_143 ( struct V_65 * V_66 , T_4 V_212 )
{
if ( V_212 < F_63 ( V_66 ) -> V_146 )
F_63 ( V_66 ) -> V_146 = V_212 ;
if ( V_212 > F_63 ( V_66 ) -> V_147 )
F_63 ( V_66 ) -> V_147 = V_212 ;
F_63 ( V_66 ) -> V_148 = V_212 ;
}
static void F_144 ( struct V_65 * V_66 ,
T_4 V_212 )
{
if ( V_212 > F_63 ( V_66 ) -> V_148 )
F_63 ( V_66 ) -> V_148 = V_212 ;
F_63 ( V_66 ) -> V_146 = V_212 ;
}
static void F_145 ( struct V_65 * V_66 ,
T_4 V_212 )
{
if ( V_212 < F_63 ( V_66 ) -> V_148 )
F_63 ( V_66 ) -> V_148 = V_212 ;
F_63 ( V_66 ) -> V_147 = V_212 ;
}
static int F_146 (
struct V_65 * V_66 ,
T_6 V_213 ,
bool * V_214 )
{
return F_63 ( V_66 ) -> V_113 -> V_215 (
& V_66 -> V_64 , V_213 , V_214 ) ;
}
static int F_147 (
struct V_65 * V_66 ,
T_6 V_213 ,
bool * V_216 )
{
return F_63 ( V_66 ) -> V_113 -> V_217 (
& V_66 -> V_64 , V_213 , V_216 ) ;
}
static int F_148 (
struct V_65 * V_66 ,
T_6 V_213 ,
struct V_218 * V_96 )
{
return F_63 ( V_66 ) -> V_113 -> V_219 (
& V_66 -> V_64 , V_213 ,
(struct V_220 * ) V_96 ) ;
}
static int F_149 (
struct V_65 * V_66 ,
T_6 V_213 ,
struct V_218 * V_96 )
{
return F_63 ( V_66 ) -> V_113 -> V_221 (
& V_66 -> V_64 , V_213 ,
(struct V_220 * ) V_96 ) ;
}
static int F_150 (
struct V_65 * V_66 ,
T_6 V_213 ,
struct V_218 * V_96 )
{
return F_63 ( V_66 ) -> V_113 -> V_222 (
& V_66 -> V_64 , V_213 ,
(struct V_220 * ) V_96 ) ;
}
static int F_151 (
struct V_65 * V_66 ,
T_6 V_213 ,
T_8 V_223 ,
bool V_224 ,
struct V_218 * V_96 )
{
return F_63 ( V_66 ) -> V_113 -> V_225 (
& V_66 -> V_64 , V_213 , V_223 , V_224 ,
(struct V_220 * ) V_96 ) ;
}
static int F_152 (
struct V_65 * V_66 ,
struct V_226 * V_96 )
{
return F_63 ( V_66 ) -> V_113 -> V_227 (
& V_66 -> V_64 ,
(struct V_228 * ) V_96 ) ;
}
static int F_153 (
struct V_65 * V_66 ,
struct V_226 * V_96 )
{
return F_63 ( V_66 ) -> V_113 -> V_229 (
& V_66 -> V_64 ,
(struct V_228 * ) V_96 ) ;
}
static int F_154 (
struct V_65 * V_66 ,
struct V_226 * V_96 )
{
return F_63 ( V_66 ) -> V_113 -> V_230 (
& V_66 -> V_64 ,
(struct V_228 * ) V_96 ) ;
}
static int F_155 (
struct V_65 * V_66 ,
T_8 V_231 ,
struct V_226 * V_96 )
{
return F_63 ( V_66 ) -> V_113 -> V_232 (
& V_66 -> V_64 , V_231 ,
(struct V_228 * ) V_96 ) ;
}
static bool F_88 ( bool * V_141 )
{
if ( V_233 != - 1 ) {
if ( V_233 == 0 )
* V_141 = true ;
else
* V_141 = false ;
F_156 ( L_4 ) ;
return true ;
}
return false ;
}
static bool F_89 ( struct V_63 * V_64 ,
T_5 * V_29 ,
bool V_141 )
{
struct V_65 * V_66 = F_12 ( V_64 ) ;
if ( V_141 ) {
if ( * V_29 != V_62 ) {
F_46 ( L_5 ) ;
return false ;
}
F_63 ( V_66 ) -> V_113 = & V_234 ;
goto exit;
}
switch ( * V_29 ) {
case V_235 :
F_63 ( V_66 ) -> V_113 =
& V_236 ;
break;
default:
F_46 ( L_6 ) ;
return false ;
}
exit:
F_63 ( V_66 ) -> V_113 -> V_237 ( V_64 ) ;
return true ;
}
static T_5 F_90 ( void )
{
if ( V_233 != - 1 )
return V_233 ;
return V_238 ;
}
static T_2 F_157 ( void )
{
return F_158 () ;
}
static int T_10 F_159 ( void )
{
int V_2 ;
V_2 = F_47 ( V_19 ,
V_192 ,
F_58 ,
NULL ,
& V_239 ) ;
if ( V_2 < V_101 ) {
F_46 ( L_7 , V_2 ) ;
return F_1 ( V_2 ) ;
}
V_2 = F_95 ( V_240 ,
F_76 ,
NULL , & V_241 ) ;
if ( V_2 < V_101 ) {
F_46 ( L_8 , V_2 ) ;
V_2 = F_1 ( V_2 ) ;
V_241 = V_159 ;
goto V_242;
}
V_2 = F_160 ( & V_132 ) ;
if ( V_2 < 0 )
goto V_243;
return 0 ;
V_243:
F_101 ( V_241 ) ;
V_242:
F_116 ( V_239 ) ;
return V_2 ;
}
static void T_11 F_161 ( void )
{
F_162 ( & V_186 ) ;
F_106 ( & V_184 ) ;
if ( ! F_68 ( V_239 ) ) {
if ( F_116 (
V_239 ) != V_101 )
F_46 ( L_9 ) ;
V_239 = V_70 ;
}
if ( V_241 != V_159 ) {
F_101 ( V_241 ) ;
V_241 = V_159 ;
}
F_163 () ;
}
