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
static inline void
F_2 ( struct V_16 * V_17 ,
struct V_18 * V_19 ,
struct V_18 * V_20 ,
T_2 type ,
T_3 V_21 ,
T_3 V_22 ,
struct V_23 * V_24 ,
T_4 V_25 ,
struct V_26 V_27 )
{
V_17 -> V_28 . V_19 = F_3 ( V_29 ,
V_30 ) ;
V_17 -> V_28 . V_20 = F_3 ( V_20 -> V_31 ,
V_30 ) ;
V_17 -> V_28 . V_32 = sizeof( * V_17 ) - sizeof( V_17 -> V_28 ) ;
V_17 -> V_33 = V_34 ;
V_17 -> type = type ;
V_17 -> V_35 = V_19 -> V_36 ;
V_17 -> V_37 = V_20 -> V_36 ;
memset ( & V_17 -> V_25 , 0 , sizeof( V_17 -> V_25 ) ) ;
memset ( & V_17 -> V_38 , 0 , sizeof( V_17 -> V_38 ) ) ;
switch ( V_17 -> type ) {
case V_39 :
V_17 -> V_40 . V_21 = 0 ;
break;
case V_41 :
case V_42 :
V_17 -> V_40 . V_21 = V_21 ;
break;
case V_43 :
case V_44 :
V_17 -> V_40 . V_27 = V_27 ;
break;
case V_45 :
case V_46 :
case V_47 :
V_17 -> V_40 . V_21 = 0 ;
break;
case V_48 :
V_17 -> V_40 . V_22 = V_22 ;
break;
case V_49 :
case V_50 :
memcpy ( & V_17 -> V_40 . V_24 , V_24 , sizeof( V_17 -> V_40 . V_24 ) ) ;
break;
case V_51 :
case V_52 :
V_17 -> V_40 . V_21 = V_21 ;
V_17 -> V_25 = V_25 ;
break;
}
}
static inline void
F_4 ( struct V_16 * V_17 ,
struct V_18 * V_53 ,
struct V_18 * V_54 )
{
F_5 ( V_53 , V_17 -> V_28 . V_20 . V_55 , V_17 -> V_37 ) ;
F_5 ( V_54 , V_17 -> V_28 . V_19 . V_55 , V_17 -> V_35 ) ;
}
static int
F_6 ( struct V_16 * V_17 ,
struct V_18 * V_19 ,
struct V_18 * V_20 ,
enum V_56 type ,
T_3 V_21 ,
T_3 V_22 ,
struct V_23 * V_24 ,
T_4 V_25 ,
struct V_26 V_27 ,
bool V_57 )
{
int V_2 ;
F_2 ( V_17 , V_19 , V_20 , type , V_21 , V_22 , V_24 ,
V_25 , V_27 ) ;
V_2 = F_7 ( & V_17 -> V_28 ) ;
if ( V_57 && ( V_2 < 0 ) )
return F_1 ( V_2 ) ;
return V_2 ;
}
static int
F_8 ( struct V_16 * V_17 ,
enum V_56 type ,
T_3 V_21 ,
T_3 V_22 ,
struct V_23 * V_24 ,
struct V_26 V_27 )
{
struct V_16 V_58 ;
struct V_18 V_19 , V_20 ;
if ( V_17 -> type == V_47 ) {
return 0 ;
} else {
F_4 ( V_17 , & V_19 , & V_20 ) ;
return F_6 ( & V_58 , & V_19 , & V_20 ,
type ,
V_21 , V_22 , V_24 ,
V_59 ,
V_27 , true ) ;
}
}
static int
F_9 ( struct V_18 * V_19 ,
struct V_18 * V_20 ,
enum V_56 type ,
T_3 V_21 ,
T_3 V_22 ,
struct V_23 * V_24 ,
struct V_26 V_27 )
{
static struct V_16 V_17 ;
return F_6 ( & V_17 , V_19 , V_20 , type ,
V_21 , V_22 , V_24 ,
V_59 , V_27 ,
false ) ;
}
static int
F_10 ( struct V_60 * V_61 ,
enum V_56 type ,
T_3 V_21 ,
T_3 V_22 ,
struct V_23 * V_24 ,
T_4 V_25 ,
struct V_26 V_27 )
{
struct V_16 * V_17 ;
struct V_62 * V_63 ;
int V_2 ;
V_63 = F_11 ( V_61 ) ;
if ( ! F_12 ( & V_63 -> V_64 ) )
return - V_15 ;
if ( ! F_12 ( & V_63 -> V_65 ) )
return - V_15 ;
V_17 = F_13 ( sizeof( * V_17 ) , V_66 ) ;
if ( ! V_17 )
return - V_4 ;
V_2 = F_6 ( V_17 , & V_63 -> V_64 ,
& V_63 -> V_65 , type , V_21 ,
V_22 , V_24 , V_25 , V_27 ,
true ) ;
F_14 ( V_17 ) ;
return V_2 ;
}
static int F_15 ( struct V_18 * V_20 ,
struct V_18 * V_19 ,
struct V_16 * V_17 )
{
if ( V_17 -> type == V_47 )
return 0 ;
return F_9 (
V_20 , V_19 ,
V_47 , 0 ,
0 , NULL , V_67 ) ;
}
static int F_16 ( struct V_60 * V_61 ,
struct V_16 * V_17 )
{
if ( V_17 -> type == V_47 )
return 0 ;
return F_10 ( V_61 ,
V_47 ,
0 , 0 , NULL , V_59 ,
V_67 ) ;
}
static int F_17 ( struct V_60 * V_61 , T_5 V_21 )
{
return F_10 (
V_61 ,
V_42 ,
V_21 , 0 , NULL ,
V_59 ,
V_67 ) ;
}
static int F_18 ( struct V_60 * V_61 , T_5 V_21 ,
T_4 V_33 )
{
return F_10 (
V_61 ,
V_52 ,
V_21 , 0 , NULL , V_33 ,
V_67 ) ;
}
static int F_19 ( struct V_60 * V_61 ,
struct V_26 V_27 )
{
return F_10 (
V_61 , V_43 , 0 ,
0 , NULL ,
V_59 , V_27 ) ;
}
static int F_20 ( struct V_60 * V_61 ,
struct V_26 V_27 )
{
return F_10 (
V_61 , V_44 ,
0 , 0 , NULL , V_59 ,
V_27 ) ;
}
static int F_21 ( struct V_16 * V_17 )
{
return F_8 (
V_17 ,
V_47 ,
0 , 0 , NULL ,
V_67 ) ;
}
static int F_22 ( struct V_18 * V_20 ,
struct V_18 * V_19 )
{
return F_9 (
V_20 , V_19 ,
V_39 ,
0 , 0 , NULL , V_67 ) ;
}
int F_23 ( struct V_18 * V_20 ,
struct V_18 * V_19 )
{
return F_9 (
V_20 , V_19 ,
V_45 , 0 ,
0 , NULL , V_67 ) ;
}
int F_24 ( struct V_18 * V_20 ,
struct V_18 * V_19 )
{
return F_9 (
V_20 , V_19 ,
V_46 , 0 ,
0 , NULL , V_67 ) ;
}
int F_25 ( struct V_60 * V_61 )
{
return F_10 (
V_61 , V_45 , 0 ,
0 , NULL , V_59 ,
V_67 ) ;
}
int F_26 ( struct V_60 * V_61 )
{
return F_10 (
V_61 , V_46 , 0 ,
0 , NULL , V_59 ,
V_67 ) ;
}
int F_27 ( struct V_60 * V_61 ,
struct V_23 * V_24 )
{
return F_10 (
V_61 , V_50 ,
0 , 0 , V_24 , V_59 ,
V_67 ) ;
}
int F_28 ( struct V_60 * V_61 ,
struct V_23 * V_24 )
{
return F_10 (
V_61 , V_49 ,
0 , 0 , V_24 , V_59 ,
V_67 ) ;
}
static int F_29 ( struct V_62 * V_63 , int V_22 )
{
return F_10 (
& V_63 -> V_61 ,
V_48 ,
0 , V_22 , NULL ,
V_59 ,
V_67 ) ;
}
static int F_30 ( struct V_60 * V_61 , T_5 V_21 )
{
return F_10 ( V_61 ,
V_41 ,
V_21 , 0 , NULL ,
V_59 ,
V_67 ) ;
}
static int F_31 ( struct V_60 * V_61 , T_5 V_21 ,
T_4 V_33 )
{
return F_10 (
V_61 , V_51 ,
V_21 , 0 , NULL , V_33 ,
V_67 ) ;
}
static struct V_60 * F_32 (
struct V_60 * V_68 ,
struct V_16 * V_17 )
{
struct V_62 * V_69 ;
struct V_62 * V_70 ;
struct V_60 * V_71 ;
struct V_18 V_19 ;
F_5 ( & V_19 , V_17 -> V_28 . V_19 . V_55 , V_17 -> V_35 ) ;
V_69 = F_11 ( V_68 ) ;
F_33 (vpending, &vlistener->pending_links,
pending_links) {
if ( F_34 ( & V_19 , & V_70 -> V_65 ) &&
V_17 -> V_37 == V_70 -> V_64 . V_36 ) {
V_71 = F_35 ( V_70 ) ;
F_36 ( V_71 ) ;
goto V_72;
}
}
V_71 = NULL ;
V_72:
return V_71 ;
}
static void F_37 ( struct V_60 * V_71 )
{
F_38 ( V_71 ) ;
}
static bool F_39 ( struct V_62 * V_73 , T_6 V_74 )
{
return V_73 -> V_75 ||
F_40 ( V_74 , V_73 -> V_76 -> V_77 ) ;
}
static bool F_41 ( struct V_62 * V_73 , T_6 V_74 )
{
if ( V_73 -> V_78 != V_74 ) {
V_73 -> V_78 = V_74 ;
if ( ! F_39 ( V_73 , V_74 ) &&
( F_42 ( V_74 ) &
V_79 ) ) {
V_73 -> V_80 = false ;
} else {
V_73 -> V_80 = true ;
}
}
return V_73 -> V_80 ;
}
static int
F_43 ( struct V_81 * * V_82 ,
struct V_26 * V_27 ,
T_3 V_83 ,
T_3 V_84 ,
T_6 V_85 , T_6 V_86 , bool V_75 )
{
int V_2 = 0 ;
if ( V_75 ) {
V_2 = F_44 ( V_82 , V_27 , V_83 ,
V_84 ,
V_85 , V_86 ,
V_87 ) ;
if ( V_2 != V_8 )
goto V_88;
}
V_2 = F_44 ( V_82 , V_27 , V_83 , V_84 ,
V_85 , V_86 , V_89 ) ;
V_88:
if ( V_2 < 0 ) {
F_45 ( L_1 ,
V_2 ) ;
V_2 = F_1 ( V_2 ) ;
}
return V_2 ;
}
static int
F_46 ( T_6 V_90 ,
T_6 V_86 ,
T_7 V_91 ,
void * V_92 ,
struct V_26 * V_93 )
{
int V_2 = 0 ;
V_2 = F_47 ( V_90 , V_86 ,
V_87 ,
V_91 ,
V_92 , V_93 ) ;
if ( V_2 == V_8 )
V_2 = F_48 ( V_90 , V_86 ,
V_91 , V_92 ,
V_93 ) ;
return V_2 ;
}
static int F_49 ( void * V_94 , struct V_95 * V_28 )
{
struct V_60 * V_61 ;
T_5 V_21 ;
struct V_96 * V_97 ;
struct V_62 * V_63 ;
V_61 = (struct V_60 * ) V_94 ;
V_63 = F_11 ( V_61 ) ;
if ( ! F_41 ( V_63 , V_28 -> V_19 . V_55 ) )
return V_8 ;
V_21 = F_50 ( V_28 ) ;
V_97 = F_51 ( V_21 , V_98 ) ;
if ( V_97 ) {
F_36 ( V_61 ) ;
F_52 ( V_97 , V_21 ) ;
memcpy ( V_97 -> V_94 , V_28 , V_21 ) ;
F_53 ( V_61 , V_97 , 0 ) ;
}
return V_99 ;
}
static bool F_54 ( T_6 V_100 , T_6 V_101 )
{
static const T_6 V_102 [] = {
V_103 ,
V_104 ,
} ;
int V_105 ;
F_55 ( sizeof( V_100 ) != sizeof( * V_102 ) ) ;
for ( V_105 = 0 ; V_105 < F_56 ( V_102 ) ; V_105 ++ ) {
if ( V_100 == V_102 [ V_105 ] )
return false ;
}
return true ;
}
static int F_57 ( void * V_94 , struct V_95 * V_28 )
{
struct V_60 * V_61 ;
struct V_18 V_20 ;
struct V_18 V_19 ;
struct V_16 * V_17 ;
struct V_62 * V_63 ;
bool V_106 ;
int V_2 ;
V_61 = NULL ;
V_2 = V_99 ;
V_106 = false ;
if ( ! F_54 ( V_28 -> V_19 . V_55 , - 1 )
|| V_30 != V_28 -> V_19 . V_107 )
return V_8 ;
if ( F_50 ( V_28 ) < sizeof( * V_17 ) )
return V_14 ;
V_17 = (struct V_16 * ) V_28 ;
F_5 ( & V_19 , V_17 -> V_28 . V_19 . V_55 , V_17 -> V_35 ) ;
F_5 ( & V_20 , V_17 -> V_28 . V_20 . V_55 , V_17 -> V_37 ) ;
V_61 = F_58 ( & V_19 , & V_20 ) ;
if ( ! V_61 ) {
V_61 = F_59 ( & V_20 ) ;
if ( ! V_61 ) {
if ( F_15 ( & V_20 , & V_19 , V_17 ) < 0 )
F_45 ( L_2 ) ;
V_2 = V_108 ;
goto V_88;
}
}
if ( V_17 -> type >= V_109 ) {
F_22 ( & V_20 , & V_19 ) ;
V_2 = V_14 ;
goto V_88;
}
V_63 = F_11 ( V_61 ) ;
if ( ! F_41 ( V_63 , V_17 -> V_28 . V_19 . V_55 ) ) {
V_2 = V_8 ;
goto V_88;
}
F_60 ( V_61 ) ;
if ( ! F_61 ( V_61 ) ) {
V_63 -> V_64 . V_31 = V_20 . V_31 ;
if ( V_61 -> V_110 == V_111 )
F_62 ( V_63 ) -> V_112 -> V_113 (
V_61 , V_17 , true , & V_20 , & V_19 ,
& V_106 ) ;
}
F_63 ( V_61 ) ;
if ( ! V_106 ) {
struct V_114 * V_115 ;
V_115 = F_13 ( sizeof( * V_115 ) , V_98 ) ;
if ( ! V_115 ) {
if ( F_15 ( & V_20 , & V_19 , V_17 ) < 0 )
F_45 ( L_2 ) ;
V_2 = V_3 ;
goto V_88;
}
V_115 -> V_61 = V_61 ;
memcpy ( & V_115 -> V_17 , V_17 , sizeof( V_115 -> V_17 ) ) ;
F_64 ( & V_115 -> V_116 , V_117 ) ;
F_65 ( & V_115 -> V_116 ) ;
V_61 = NULL ;
}
V_88:
if ( V_61 )
F_38 ( V_61 ) ;
return V_2 ;
}
static void F_66 ( T_6 V_118 ,
const struct V_119 * V_120 ,
void * V_92 )
{
struct V_60 * V_61 = V_92 ;
const struct V_121 * V_122 ;
struct V_62 * V_63 ;
V_122 = F_67 ( V_120 ) ;
V_63 = F_11 ( V_61 ) ;
F_68 () ;
F_60 ( V_61 ) ;
if ( F_69 ( F_62 ( V_63 ) -> V_123 ,
V_122 -> V_27 ) ) {
goto V_88;
}
V_88:
F_63 ( V_61 ) ;
F_70 () ;
}
static void F_71 ( struct V_60 * V_61 )
{
struct V_62 * V_63 ;
V_63 = F_11 ( V_61 ) ;
if ( ! F_72 ( F_62 ( V_63 ) -> V_123 ) ) {
F_73 ( V_61 , V_124 ) ;
V_63 -> V_125 = V_126 ;
if ( F_74 ( V_63 ) <= 0 ) {
if ( V_61 -> V_110 == V_127 ) {
V_61 -> V_110 = V_128 ;
V_61 -> V_129 = V_130 ;
V_61 -> V_131 ( V_61 ) ;
return;
}
V_61 -> V_110 = V_128 ;
}
V_61 -> V_132 ( V_61 ) ;
}
}
static void F_75 ( T_6 V_118 ,
const struct V_119 * V_120 ,
void * V_92 )
{
struct V_60 * V_61 = V_92 ;
const struct V_121 * V_122 ;
struct V_62 * V_63 ;
V_122 = F_67 ( V_120 ) ;
V_63 = F_11 ( V_61 ) ;
if ( F_72 ( V_122 -> V_27 ) )
return;
F_68 () ;
F_60 ( V_61 ) ;
if ( F_69 ( F_62 ( V_63 ) -> V_123 ,
V_122 -> V_27 ) )
F_71 ( V_61 ) ;
F_63 ( V_61 ) ;
F_70 () ;
}
static void F_76 ( T_6 V_118 ,
const struct V_119 * V_120 ,
void * V_92 )
{
F_77 ( F_71 ) ;
}
static void V_117 ( struct V_133 * V_116 )
{
struct V_114 * V_115 ;
struct V_16 * V_17 ;
struct V_60 * V_61 ;
V_115 =
F_78 ( V_116 , struct V_114 , V_116 ) ;
V_61 = V_115 -> V_61 ;
V_17 = & V_115 -> V_17 ;
F_79 ( V_61 ) ;
F_11 ( V_61 ) -> V_64 . V_31 = V_17 -> V_28 . V_20 . V_55 ;
switch ( V_61 -> V_110 ) {
case V_134 :
F_80 ( V_61 , V_17 ) ;
break;
case V_127 :
F_81 ( V_61 , V_17 ) ;
break;
case V_111 :
F_82 ( V_61 , V_17 ) ;
break;
default:
F_16 ( V_61 , V_17 ) ;
goto V_88;
}
V_88:
F_83 ( V_61 ) ;
F_14 ( V_115 ) ;
F_38 ( V_61 ) ;
}
static int F_80 ( struct V_60 * V_61 ,
struct V_16 * V_17 )
{
struct V_60 * V_71 ;
struct V_62 * V_70 ;
int V_2 ;
T_3 V_135 ;
bool V_136 = false ;
bool V_137 = false ;
V_2 = 0 ;
V_71 = F_32 ( V_61 , V_17 ) ;
if ( V_71 ) {
F_79 ( V_71 ) ;
F_11 ( V_71 ) -> V_64 . V_31 = V_17 -> V_28 . V_20 . V_55 ;
switch ( V_71 -> V_110 ) {
case V_127 :
V_2 = F_84 ( V_61 ,
V_71 ,
V_17 ) ;
break;
default:
F_16 ( V_71 , V_17 ) ;
V_2 = - V_15 ;
}
if ( V_2 < 0 )
F_85 ( V_61 , V_71 ) ;
F_83 ( V_71 ) ;
F_37 ( V_71 ) ;
return V_2 ;
}
if ( ! ( V_17 -> type == V_41 ||
V_17 -> type == V_51 ) ) {
F_21 ( V_17 ) ;
return - V_15 ;
}
if ( V_17 -> V_40 . V_21 == 0 ) {
F_21 ( V_17 ) ;
return - V_15 ;
}
if ( V_61 -> V_138 >= V_61 -> V_139 ) {
F_21 ( V_17 ) ;
return - V_140 ;
}
V_71 = F_86 ( F_87 ( V_61 ) , NULL , V_61 , V_66 ,
V_61 -> V_141 ) ;
if ( ! V_71 ) {
F_16 ( V_61 , V_17 ) ;
return - V_4 ;
}
V_70 = F_11 ( V_71 ) ;
F_5 ( & V_70 -> V_64 , V_17 -> V_28 . V_20 . V_55 ,
V_17 -> V_37 ) ;
F_5 ( & V_70 -> V_65 , V_17 -> V_28 . V_19 . V_55 ,
V_17 -> V_35 ) ;
if ( V_17 -> V_40 . V_21 >= F_62 ( V_70 ) -> V_142 &&
V_17 -> V_40 . V_21 <= F_62 ( V_70 ) -> V_143 ) {
V_135 = V_17 -> V_40 . V_21 ;
} else {
V_135 = F_62 ( V_70 ) -> V_144 ;
}
if ( F_88 ( & V_137 ) ) {
V_136 = V_137 ;
} else {
if ( V_17 -> type == V_41 )
V_136 = true ;
else if ( V_17 -> type == V_51 )
V_136 = false ;
}
if ( V_136 ) {
T_4 V_33 = V_59 ;
if ( F_89 (
V_71 , & V_33 , true ) )
V_2 = F_17 ( V_71 , V_135 ) ;
else
V_2 = - V_15 ;
} else {
int V_145 = V_17 -> V_25 ;
int V_146 ;
T_4 V_147 = 0 ;
V_145 &= F_90 () ;
V_146 = F_91 ( V_145 ) ;
if ( V_146 ) {
V_147 = ( 1 << ( V_146 - 1 ) ) ;
if ( F_89 (
V_71 , & V_147 , false ) )
V_2 = F_18 ( V_71 ,
V_135 ,
V_147 ) ;
else
V_2 = - V_15 ;
} else {
V_2 = - V_15 ;
}
}
if ( V_2 < 0 ) {
F_16 ( V_61 , V_17 ) ;
F_38 ( V_71 ) ;
V_2 = F_1 ( V_2 ) ;
goto V_88;
}
F_92 ( V_61 , V_71 ) ;
V_61 -> V_138 ++ ;
V_71 -> V_110 = V_127 ;
F_62 ( V_70 ) -> V_83 =
F_62 ( V_70 ) -> V_84 = V_135 ;
F_62 ( V_70 ) -> V_144 = V_135 ;
F_62 ( V_70 ) -> V_112 -> V_148 ( V_71 ) ;
V_70 -> V_68 = V_61 ;
F_36 ( V_61 ) ;
F_36 ( V_71 ) ;
F_93 ( & V_70 -> V_149 , V_150 ) ;
F_94 ( & V_70 -> V_149 , V_151 ) ;
V_88:
return V_2 ;
}
static int
F_84 ( struct V_60 * V_68 ,
struct V_60 * V_71 ,
struct V_16 * V_17 )
{
struct V_62 * V_70 ;
struct V_26 V_27 ;
struct V_81 * V_82 ;
bool V_152 ;
T_6 V_86 ;
T_6 V_153 ;
int V_2 ;
int V_154 ;
V_70 = F_11 ( V_71 ) ;
V_153 = V_155 ;
switch ( V_17 -> type ) {
case V_43 :
if ( F_72 ( V_17 -> V_40 . V_27 ) ) {
F_16 ( V_71 , V_17 ) ;
V_154 = V_156 ;
V_2 = - V_15 ;
goto V_157;
}
break;
default:
F_16 ( V_71 , V_17 ) ;
V_154 = V_156 ;
V_2 = V_17 -> type == V_47 ? 0 : - V_15 ;
goto V_157;
}
V_2 = F_95 ( V_158 ,
F_75 ,
V_71 , & V_153 ) ;
if ( V_2 < V_99 ) {
F_16 ( V_71 , V_17 ) ;
V_2 = F_1 ( V_2 ) ;
V_154 = - V_2 ;
goto V_157;
}
F_62 ( V_70 ) -> V_153 = V_153 ;
V_27 = V_17 -> V_40 . V_27 ;
V_152 =
V_70 -> V_65 . V_31 == V_70 -> V_64 . V_31 ;
V_86 = V_159 ;
V_86 |= V_152 ? V_160 : 0 ;
V_2 = F_43 (
& V_82 ,
& V_27 ,
F_62 ( V_70 ) -> V_83 ,
F_62 ( V_70 ) -> V_84 ,
V_17 -> V_28 . V_19 . V_55 ,
V_86 ,
F_39 (
V_70 ,
V_70 -> V_65 . V_31 ) ) ;
if ( V_2 < 0 ) {
F_16 ( V_71 , V_17 ) ;
V_154 = - V_2 ;
goto V_157;
}
F_62 ( V_70 ) -> V_123 = V_27 ;
F_62 ( V_70 ) -> V_82 = V_82 ;
V_71 -> V_110 = V_111 ;
F_96 ( V_70 ) ;
V_2 = F_20 ( V_71 , V_27 ) ;
if ( V_2 < 0 ) {
F_97 ( V_70 ) ;
F_45 ( L_3 ) ;
F_16 ( V_71 , V_17 ) ;
V_2 = F_1 ( V_2 ) ;
V_154 = - V_2 ;
goto V_157;
}
F_85 ( V_68 , V_71 ) ;
F_98 ( V_68 , V_71 ) ;
V_68 -> V_132 ( V_68 ) ;
return 0 ;
V_157:
V_71 -> V_129 = V_154 ;
V_71 -> V_110 = V_128 ;
F_38 ( V_71 ) ;
return V_2 ;
}
static int
F_81 ( struct V_60 * V_61 ,
struct V_16 * V_17 )
{
struct V_62 * V_63 ;
int V_2 ;
int V_154 ;
V_63 = F_11 ( V_61 ) ;
switch ( V_17 -> type ) {
case V_44 :
if ( F_72 ( V_17 -> V_40 . V_27 ) ||
! F_69 ( V_17 -> V_40 . V_27 ,
F_62 ( V_63 ) -> V_123 ) ) {
V_154 = V_156 ;
V_2 = - V_15 ;
goto V_157;
}
V_61 -> V_110 = V_111 ;
V_61 -> V_161 -> V_162 = V_111 ;
F_96 ( V_63 ) ;
V_61 -> V_132 ( V_61 ) ;
break;
case V_42 :
case V_52 :
if ( V_17 -> V_40 . V_21 == 0
|| V_17 -> V_28 . V_19 . V_55 != V_63 -> V_65 . V_31
|| V_17 -> V_35 != V_63 -> V_65 . V_36
|| ! F_72 ( F_62 ( V_63 ) -> V_123 )
|| F_62 ( V_63 ) -> V_82
|| F_62 ( V_63 ) -> V_83 != 0
|| F_62 ( V_63 ) -> V_84 != 0
|| F_62 ( V_63 ) -> V_163 != V_155
|| F_62 ( V_63 ) -> V_153 != V_155 ) {
V_154 = V_156 ;
V_2 = - V_15 ;
goto V_157;
}
V_2 = F_99 ( V_61 , V_17 ) ;
if ( V_2 ) {
V_154 = - V_2 ;
goto V_157;
}
break;
case V_39 :
V_2 = F_100 ( V_61 , V_17 ) ;
if ( V_2 ) {
V_154 = - V_2 ;
goto V_157;
}
break;
case V_47 :
if ( V_63 -> V_164 ) {
V_63 -> V_164 = false ;
} else {
V_154 = V_130 ;
V_2 = 0 ;
goto V_157;
}
break;
default:
V_154 = V_156 ;
V_2 = - V_15 ;
goto V_157;
}
return 0 ;
V_157:
F_16 ( V_61 , V_17 ) ;
V_61 -> V_110 = V_128 ;
V_61 -> V_129 = V_154 ;
V_61 -> V_131 ( V_61 ) ;
return V_2 ;
}
static int F_99 (
struct V_60 * V_61 ,
struct V_16 * V_17 )
{
int V_2 ;
struct V_62 * V_63 ;
struct V_26 V_27 ;
struct V_81 * V_82 ;
T_6 V_163 ;
T_6 V_153 ;
bool V_152 ;
T_6 V_86 ;
bool V_165 = true ;
bool V_137 ;
T_4 V_33 ;
V_63 = F_11 ( V_61 ) ;
V_27 = V_67 ;
V_163 = V_155 ;
V_153 = V_155 ;
V_63 -> V_166 = false ;
V_63 -> V_164 = false ;
if ( V_17 -> V_40 . V_21 < F_62 ( V_63 ) -> V_142 ||
V_17 -> V_40 . V_21 > F_62 ( V_63 ) -> V_143 ) {
V_2 = - V_15 ;
goto V_157;
}
if ( V_63 -> V_64 . V_31 == V_29 )
V_63 -> V_64 . V_31 = V_17 -> V_28 . V_20 . V_55 ;
if ( F_88 ( & V_137 ) ) {
V_165 = V_137 ;
} else {
if ( V_17 -> type == V_42 )
V_165 = true ;
else if ( V_17 -> type == V_52 )
V_165 = false ;
}
if ( V_165 )
V_33 = V_59 ;
else
V_33 = V_17 -> V_25 ;
if ( ! F_89 ( V_61 , & V_33 , V_165 ) ) {
V_2 = - V_15 ;
goto V_157;
}
V_2 = F_95 ( V_167 ,
F_66 ,
V_61 , & V_163 ) ;
if ( V_2 < V_99 ) {
V_2 = F_1 ( V_2 ) ;
goto V_157;
}
V_2 = F_95 ( V_158 ,
F_75 ,
V_61 , & V_153 ) ;
if ( V_2 < V_99 ) {
V_2 = F_1 ( V_2 ) ;
goto V_157;
}
V_27 = V_67 ;
V_152 = V_63 -> V_65 . V_31 == V_63 -> V_64 . V_31 ;
V_86 = V_152 ? V_160 : 0 ;
V_2 = F_43 ( & V_82 ,
& V_27 ,
V_17 -> V_40 . V_21 ,
V_17 -> V_40 . V_21 ,
V_63 -> V_65 . V_31 ,
V_86 ,
F_39 (
V_63 ,
V_63 ->
V_65 . V_31 ) ) ;
if ( V_2 < 0 )
goto V_157;
V_2 = F_19 ( V_61 , V_27 ) ;
if ( V_2 < 0 ) {
V_2 = F_1 ( V_2 ) ;
goto V_157;
}
F_62 ( V_63 ) -> V_123 = V_27 ;
F_62 ( V_63 ) -> V_82 = V_82 ;
F_62 ( V_63 ) -> V_83 = F_62 ( V_63 ) -> V_84 =
V_17 -> V_40 . V_21 ;
F_62 ( V_63 ) -> V_163 = V_163 ;
F_62 ( V_63 ) -> V_153 = V_153 ;
F_62 ( V_63 ) -> V_112 -> V_168 ( V_61 ) ;
return 0 ;
V_157:
if ( V_163 != V_155 )
F_101 ( V_163 ) ;
if ( V_153 != V_155 )
F_101 ( V_153 ) ;
if ( ! F_72 ( V_27 ) )
F_102 ( & V_82 ) ;
return V_2 ;
}
static int
F_100 ( struct V_60 * V_61 ,
struct V_16 * V_17 )
{
int V_2 = 0 ;
struct V_62 * V_63 = F_11 ( V_61 ) ;
if ( V_63 -> V_166 ) {
V_63 -> V_166 = false ;
V_63 -> V_164 = true ;
V_2 = F_30 (
V_61 , F_62 ( V_63 ) -> V_144 ) ;
if ( V_2 < 0 )
V_2 = F_1 ( V_2 ) ;
else
V_2 = 0 ;
}
return V_2 ;
}
static int F_82 ( struct V_60 * V_61 ,
struct V_16 * V_17 )
{
struct V_62 * V_63 ;
bool V_169 = false ;
switch ( V_17 -> type ) {
case V_48 :
if ( V_17 -> V_40 . V_22 ) {
V_63 = F_11 ( V_61 ) ;
V_63 -> V_125 |= V_17 -> V_40 . V_22 ;
V_61 -> V_132 ( V_61 ) ;
}
break;
case V_47 :
V_63 = F_11 ( V_61 ) ;
F_73 ( V_61 , V_124 ) ;
V_63 -> V_125 = V_126 ;
if ( F_74 ( V_63 ) <= 0 )
V_61 -> V_110 = V_170 ;
V_61 -> V_132 ( V_61 ) ;
break;
default:
V_63 = F_11 ( V_61 ) ;
F_62 ( V_63 ) -> V_112 -> V_113 (
V_61 , V_17 , false , NULL , NULL ,
& V_169 ) ;
if ( ! V_169 )
return - V_15 ;
break;
}
return 0 ;
}
static int F_103 ( struct V_62 * V_63 ,
struct V_62 * V_171 )
{
V_63 -> V_172 = F_13 ( sizeof( struct V_173 ) , V_66 ) ;
if ( ! V_63 -> V_172 )
return - V_4 ;
F_62 ( V_63 ) -> V_174 = V_67 ;
F_62 ( V_63 ) -> V_123 = V_67 ;
F_62 ( V_63 ) -> V_82 = NULL ;
F_62 ( V_63 ) -> V_83 = F_62 ( V_63 ) -> V_84 = 0 ;
F_62 ( V_63 ) -> V_163 = F_62 ( V_63 ) -> V_153 =
V_155 ;
F_62 ( V_63 ) -> V_112 = NULL ;
if ( V_171 ) {
F_62 ( V_63 ) -> V_144 =
F_62 ( V_171 ) -> V_144 ;
F_62 ( V_63 ) -> V_142 =
F_62 ( V_171 ) -> V_142 ;
F_62 ( V_63 ) -> V_143 =
F_62 ( V_171 ) -> V_143 ;
} else {
F_62 ( V_63 ) -> V_144 =
V_175 ;
F_62 ( V_63 ) -> V_142 =
V_176 ;
F_62 ( V_63 ) -> V_143 =
V_177 ;
}
return 0 ;
}
static void F_104 ( struct V_62 * V_63 )
{
if ( F_62 ( V_63 ) -> V_163 != V_155 ) {
F_101 ( F_62 ( V_63 ) -> V_163 ) ;
F_62 ( V_63 ) -> V_163 = V_155 ;
}
if ( F_62 ( V_63 ) -> V_153 != V_155 ) {
F_101 ( F_62 ( V_63 ) -> V_153 ) ;
F_62 ( V_63 ) -> V_153 = V_155 ;
}
if ( ! F_72 ( F_62 ( V_63 ) -> V_123 ) ) {
F_102 ( & F_62 ( V_63 ) -> V_82 ) ;
F_62 ( V_63 ) -> V_123 = V_67 ;
F_62 ( V_63 ) -> V_83 = 0 ;
F_62 ( V_63 ) -> V_84 = 0 ;
}
if ( F_62 ( V_63 ) -> V_112 )
F_62 ( V_63 ) -> V_112 -> V_178 ( V_63 ) ;
F_14 ( V_63 -> V_172 ) ;
V_63 -> V_172 = NULL ;
}
static void F_105 ( struct V_62 * V_63 )
{
if ( ! F_72 ( F_62 ( V_63 ) -> V_174 ) ) {
F_106 ( F_62 ( V_63 ) -> V_174 ) ;
F_62 ( V_63 ) -> V_174 = V_67 ;
}
}
static int F_107 ( struct V_62 * V_63 ,
struct V_18 * V_179 )
{
T_6 V_101 ;
T_6 V_86 ;
int V_2 ;
V_101 = V_179 -> V_36 == V_180 ?
V_155 : V_179 -> V_36 ;
if ( V_101 <= V_181 && ! F_108 ( V_182 ) )
return - V_183 ;
V_86 = V_179 -> V_31 == V_29 ?
V_184 : 0 ;
V_2 = F_46 ( V_101 , V_86 ,
F_49 ,
& V_63 -> V_61 ,
& F_62 ( V_63 ) -> V_174 ) ;
if ( V_2 < V_99 )
return F_1 ( V_2 ) ;
F_5 ( & V_63 -> V_64 , V_179 -> V_31 ,
F_62 ( V_63 ) -> V_174 . V_107 ) ;
return 0 ;
}
static int F_109 (
struct V_62 * V_63 ,
struct V_18 * V_65 ,
struct V_185 * V_186 ,
T_5 V_187 )
{
int V_2 ;
struct V_95 * V_28 ;
if ( V_187 > V_188 )
return - V_189 ;
if ( ! F_41 ( V_63 , V_65 -> V_31 ) )
return - V_9 ;
V_28 = F_13 ( V_187 + sizeof( * V_28 ) , V_66 ) ;
if ( ! V_28 )
return - V_4 ;
F_110 ( F_111 ( V_28 ) , V_186 , V_187 ) ;
V_28 -> V_20 = F_3 ( V_65 -> V_31 ,
V_65 -> V_36 ) ;
V_28 -> V_19 = F_3 ( V_63 -> V_64 . V_31 ,
V_63 -> V_64 . V_36 ) ;
V_28 -> V_32 = V_187 ;
V_2 = F_7 ( V_28 ) ;
F_14 ( V_28 ) ;
if ( V_2 < 0 )
return F_1 ( V_2 ) ;
return V_2 - sizeof( * V_28 ) ;
}
static int F_112 ( struct V_190 * V_190 ,
struct V_62 * V_63 ,
struct V_191 * V_192 , T_5 V_187 ,
int V_86 )
{
int V_2 ;
int V_193 ;
struct V_95 * V_28 ;
T_5 V_194 ;
struct V_96 * V_97 ;
V_193 = V_86 & V_195 ;
if ( V_86 & V_196 || V_86 & V_197 )
return - V_198 ;
V_192 -> V_199 = 0 ;
V_2 = 0 ;
V_97 = F_113 ( & V_63 -> V_61 , V_86 , V_193 , & V_2 ) ;
if ( V_2 )
return V_2 ;
if ( ! V_97 )
return - V_200 ;
V_28 = (struct V_95 * ) V_97 -> V_94 ;
if ( ! V_28 )
goto V_88;
V_194 = V_28 -> V_32 ;
if ( V_194 != V_97 -> V_187 - sizeof( * V_28 ) ) {
V_2 = - V_15 ;
goto V_88;
}
if ( V_194 > V_187 ) {
V_194 = V_187 ;
V_192 -> V_201 |= V_202 ;
}
V_2 = F_114 ( V_97 , sizeof( * V_28 ) , V_192 -> V_203 ,
V_194 ) ;
if ( V_2 )
goto V_88;
if ( V_192 -> V_204 ) {
struct V_18 * V_205 ;
V_205 = (struct V_18 * ) V_192 -> V_204 ;
F_5 ( V_205 , V_28 -> V_19 . V_55 , V_28 -> V_19 . V_107 ) ;
V_192 -> V_199 = sizeof( * V_205 ) ;
}
V_2 = V_194 ;
V_88:
F_115 ( & V_63 -> V_61 , V_97 ) ;
return V_2 ;
}
static bool F_116 ( T_6 V_100 , T_6 V_101 )
{
if ( V_100 == V_103 ) {
return V_101 == V_206 ;
}
return true ;
}
static int F_117 ( struct V_62 * V_63 )
{
int V_2 ;
bool V_137 = false ;
struct V_60 * V_61 = & V_63 -> V_61 ;
if ( F_88 ( & V_137 ) &&
V_137 ) {
V_2 = F_30 (
V_61 , F_62 ( V_63 ) -> V_144 ) ;
if ( V_2 < 0 ) {
V_61 -> V_110 = V_128 ;
return V_2 ;
}
} else {
int V_207 =
F_90 () ;
V_2 = F_31 (
V_61 , F_62 ( V_63 ) -> V_144 ,
V_207 ) ;
if ( V_2 < 0 ) {
V_61 -> V_110 = V_128 ;
return V_2 ;
}
V_63 -> V_166 = true ;
}
return V_2 ;
}
static T_8 F_118 (
struct V_62 * V_63 ,
struct V_185 * V_186 ,
T_5 V_187 ,
int V_86 )
{
if ( V_86 & V_208 )
return F_119 ( F_62 ( V_63 ) -> V_82 , V_186 , V_187 , 0 ) ;
else
return F_120 ( F_62 ( V_63 ) -> V_82 , V_186 , V_187 , 0 ) ;
}
static T_8 F_121 (
struct V_62 * V_63 ,
struct V_185 * V_186 ,
T_5 V_187 )
{
return F_122 ( F_62 ( V_63 ) -> V_82 , V_186 , V_187 , 0 ) ;
}
static T_9 F_123 ( struct V_62 * V_63 )
{
return F_124 ( F_62 ( V_63 ) -> V_82 ) ;
}
static T_9 F_125 ( struct V_62 * V_63 )
{
return F_126 ( F_62 ( V_63 ) -> V_82 ) ;
}
static T_3 F_127 ( struct V_62 * V_63 )
{
return F_62 ( V_63 ) -> V_84 ;
}
static bool F_128 ( struct V_62 * V_63 )
{
return ! F_72 ( F_62 ( V_63 ) -> V_123 ) ;
}
static T_3 F_129 ( struct V_62 * V_63 )
{
return F_62 ( V_63 ) -> V_144 ;
}
static T_3 F_130 ( struct V_62 * V_63 )
{
return F_62 ( V_63 ) -> V_142 ;
}
static T_3 F_131 ( struct V_62 * V_63 )
{
return F_62 ( V_63 ) -> V_143 ;
}
static void F_132 ( struct V_62 * V_63 , T_3 V_209 )
{
if ( V_209 < F_62 ( V_63 ) -> V_142 )
F_62 ( V_63 ) -> V_142 = V_209 ;
if ( V_209 > F_62 ( V_63 ) -> V_143 )
F_62 ( V_63 ) -> V_143 = V_209 ;
F_62 ( V_63 ) -> V_144 = V_209 ;
}
static void F_133 ( struct V_62 * V_63 ,
T_3 V_209 )
{
if ( V_209 > F_62 ( V_63 ) -> V_144 )
F_62 ( V_63 ) -> V_144 = V_209 ;
F_62 ( V_63 ) -> V_142 = V_209 ;
}
static void F_134 ( struct V_62 * V_63 ,
T_3 V_209 )
{
if ( V_209 < F_62 ( V_63 ) -> V_144 )
F_62 ( V_63 ) -> V_144 = V_209 ;
F_62 ( V_63 ) -> V_143 = V_209 ;
}
static int F_135 (
struct V_62 * V_63 ,
T_5 V_210 ,
bool * V_211 )
{
return F_62 ( V_63 ) -> V_112 -> V_212 (
& V_63 -> V_61 , V_210 , V_211 ) ;
}
static int F_136 (
struct V_62 * V_63 ,
T_5 V_210 ,
bool * V_213 )
{
return F_62 ( V_63 ) -> V_112 -> V_214 (
& V_63 -> V_61 , V_210 , V_213 ) ;
}
static int F_137 (
struct V_62 * V_63 ,
T_5 V_210 ,
struct V_215 * V_94 )
{
return F_62 ( V_63 ) -> V_112 -> V_216 (
& V_63 -> V_61 , V_210 ,
(struct V_217 * ) V_94 ) ;
}
static int F_138 (
struct V_62 * V_63 ,
T_5 V_210 ,
struct V_215 * V_94 )
{
return F_62 ( V_63 ) -> V_112 -> V_218 (
& V_63 -> V_61 , V_210 ,
(struct V_217 * ) V_94 ) ;
}
static int F_139 (
struct V_62 * V_63 ,
T_5 V_210 ,
struct V_215 * V_94 )
{
return F_62 ( V_63 ) -> V_112 -> V_219 (
& V_63 -> V_61 , V_210 ,
(struct V_217 * ) V_94 ) ;
}
static int F_140 (
struct V_62 * V_63 ,
T_5 V_210 ,
T_8 V_220 ,
bool V_221 ,
struct V_215 * V_94 )
{
return F_62 ( V_63 ) -> V_112 -> V_222 (
& V_63 -> V_61 , V_210 , V_220 , V_221 ,
(struct V_217 * ) V_94 ) ;
}
static int F_141 (
struct V_62 * V_63 ,
struct V_223 * V_94 )
{
return F_62 ( V_63 ) -> V_112 -> V_224 (
& V_63 -> V_61 ,
(struct V_225 * ) V_94 ) ;
}
static int F_142 (
struct V_62 * V_63 ,
struct V_223 * V_94 )
{
return F_62 ( V_63 ) -> V_112 -> V_226 (
& V_63 -> V_61 ,
(struct V_225 * ) V_94 ) ;
}
static int F_143 (
struct V_62 * V_63 ,
struct V_223 * V_94 )
{
return F_62 ( V_63 ) -> V_112 -> V_227 (
& V_63 -> V_61 ,
(struct V_225 * ) V_94 ) ;
}
static int F_144 (
struct V_62 * V_63 ,
T_8 V_228 ,
struct V_223 * V_94 )
{
return F_62 ( V_63 ) -> V_112 -> V_229 (
& V_63 -> V_61 , V_228 ,
(struct V_225 * ) V_94 ) ;
}
static bool F_88 ( bool * V_137 )
{
if ( V_230 != - 1 ) {
if ( V_230 == 0 )
* V_137 = true ;
else
* V_137 = false ;
F_145 ( L_4 ) ;
return true ;
}
return false ;
}
static bool F_89 ( struct V_60 * V_61 ,
T_4 * V_25 ,
bool V_137 )
{
struct V_62 * V_63 = F_11 ( V_61 ) ;
if ( V_137 ) {
if ( * V_25 != V_59 ) {
F_45 ( L_5 ) ;
return false ;
}
F_62 ( V_63 ) -> V_112 = & V_231 ;
goto exit;
}
switch ( * V_25 ) {
case V_232 :
F_62 ( V_63 ) -> V_112 =
& V_233 ;
break;
default:
F_45 ( L_6 ) ;
return false ;
}
exit:
F_62 ( V_63 ) -> V_112 -> V_234 ( V_61 ) ;
return true ;
}
static T_4 F_90 ( void )
{
if ( V_230 != - 1 )
return V_230 ;
return V_235 ;
}
static T_6 F_146 ( void )
{
return F_147 () ;
}
static int T_10 F_148 ( void )
{
int V_2 ;
V_2 = F_46 ( V_30 ,
V_184 ,
F_57 ,
NULL ,
& V_236 ) ;
if ( V_2 < V_99 ) {
F_45 ( L_7 , V_2 ) ;
return F_1 ( V_2 ) ;
}
V_2 = F_95 ( V_237 ,
F_76 ,
NULL , & V_238 ) ;
if ( V_2 < V_99 ) {
F_45 ( L_8 , V_2 ) ;
V_2 = F_1 ( V_2 ) ;
V_238 = V_155 ;
goto V_239;
}
V_2 = F_149 ( & V_173 ) ;
if ( V_2 < 0 )
goto V_240;
return 0 ;
V_240:
F_101 ( V_238 ) ;
V_239:
F_106 ( V_236 ) ;
return V_2 ;
}
static void T_11 F_150 ( void )
{
if ( ! F_72 ( V_236 ) ) {
if ( F_106 (
V_236 ) != V_99 )
F_45 ( L_9 ) ;
V_236 = V_67 ;
}
if ( V_238 != V_155 ) {
F_101 ( V_238 ) ;
V_238 = V_155 ;
}
F_151 () ;
}
