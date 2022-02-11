static bool F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_3 ;
struct V_4 * V_4 ;
struct V_5 * V_6 ;
if ( ! V_3 )
return false ;
V_4 = V_3 -> V_7 ;
V_6 = F_2 ( V_4 ) ;
if ( V_4 -> V_8 == F_3 ( V_6 ) ||
V_4 -> V_8 == F_4 ( V_6 ) ||
F_5 ( V_4 -> V_9 ) ||
F_6 ( V_1 ) )
return true ;
return false ;
}
static void F_7 ( struct V_10 * V_10 )
{
struct V_11 * V_12 ;
int V_13 ;
#ifdef F_8
if ( F_9 ( F_10 ( V_10 -> V_14 -> V_15 ) , V_16 ) ) {
F_11 ( V_16 ) ;
V_10 -> V_17 = V_18 ;
}
#endif
if ( F_12 ( V_10 ) ) {
if ( V_10 -> V_17 ) {
F_13 ( V_10 -> V_19 ) ;
} else {
F_14 ( V_10 -> V_19 , V_10 ) ;
return;
}
}
F_15 (bvec, bio, i) {
struct V_1 * V_1 = V_12 -> V_15 ;
if ( ! V_10 -> V_17 ) {
if ( ! F_16 ( V_1 ) )
F_17 ( V_1 ) ;
} else {
F_18 ( V_1 ) ;
F_19 ( V_1 ) ;
}
F_20 ( V_1 ) ;
}
F_21 ( V_10 ) ;
}
static void F_22 ( struct V_10 * V_10 )
{
struct V_5 * V_6 = V_10 -> V_19 ;
struct V_11 * V_12 ;
int V_13 ;
F_15 (bvec, bio, i) {
struct V_1 * V_1 = V_12 -> V_15 ;
enum V_20 type = F_23 ( V_1 ) ;
if ( F_24 ( V_1 ) ) {
F_25 ( V_1 , ( unsigned long ) NULL ) ;
F_26 ( V_1 ) ;
F_20 ( V_1 ) ;
F_27 ( V_1 , V_6 -> V_21 ) ;
if ( F_28 ( V_10 -> V_17 ) )
F_29 ( V_6 , true ) ;
continue;
}
F_30 ( & V_1 , true ) ;
if ( F_28 ( V_10 -> V_17 ) ) {
F_31 ( V_1 -> V_3 , - V_22 ) ;
F_29 ( V_6 , true ) ;
}
F_32 ( V_6 , type ) ;
F_33 ( V_1 ) ;
F_34 ( V_1 ) ;
}
if ( ! F_35 ( V_6 , V_23 ) &&
F_36 ( & V_6 -> V_24 ) )
F_37 ( & V_6 -> V_24 ) ;
F_21 ( V_10 ) ;
}
struct V_25 * F_38 ( struct V_5 * V_6 ,
T_1 V_26 , struct V_10 * V_10 )
{
struct V_25 * V_27 = V_6 -> V_28 -> V_29 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_6 -> V_30 ; V_13 ++ ) {
if ( F_39 ( V_13 ) . V_31 <= V_26 &&
F_39 ( V_13 ) . V_32 >= V_26 ) {
V_26 -= F_39 ( V_13 ) . V_31 ;
V_27 = F_39 ( V_13 ) . V_27 ;
break;
}
}
if ( V_10 ) {
V_10 -> V_33 = V_27 ;
V_10 -> V_34 . V_35 = F_40 ( V_26 ) ;
}
return V_27 ;
}
int F_41 ( struct V_5 * V_6 , T_1 V_36 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_6 -> V_30 ; V_13 ++ )
if ( F_39 ( V_13 ) . V_31 <= V_36 && F_39 ( V_13 ) . V_32 >= V_36 )
return V_13 ;
return 0 ;
}
static bool F_42 ( struct V_5 * V_6 ,
T_1 V_26 , struct V_10 * V_10 )
{
return F_38 ( V_6 , V_26 , NULL ) == V_10 -> V_33 ;
}
static struct V_10 * F_43 ( struct V_5 * V_6 , T_1 V_26 ,
int V_37 , bool V_38 )
{
struct V_10 * V_10 ;
V_10 = F_44 ( V_37 ) ;
F_38 ( V_6 , V_26 , V_10 ) ;
V_10 -> V_39 = V_38 ? F_7 : F_22 ;
V_10 -> V_19 = V_38 ? NULL : V_6 ;
return V_10 ;
}
static inline void F_45 ( struct V_5 * V_6 ,
struct V_10 * V_10 , enum V_40 type )
{
if ( ! F_46 ( F_47 ( V_10 ) ) ) {
unsigned int V_41 ;
if ( F_48 ( V_6 -> V_28 ) &&
V_42 -> V_43 && ( type == V_44 || type == V_45 ) )
F_49 ( V_42 -> V_43 ) ;
if ( type != V_44 && type != V_45 )
goto V_46;
V_41 = V_10 -> V_34 . V_47 >> V_48 ;
V_41 %= F_50 ( V_6 ) ;
if ( V_41 == 0 )
goto V_46;
for (; V_41 < F_50 ( V_6 ) ; V_41 ++ ) {
struct V_1 * V_1 =
F_51 ( V_6 -> V_21 ,
V_49 | V_50 | V_51 ) ;
F_52 ( V_6 , ! V_1 ) ;
F_53 ( V_1 ) ;
F_25 ( V_1 , ( unsigned long ) V_52 ) ;
F_54 ( V_1 ) ;
if ( F_55 ( V_10 , V_1 , V_53 , 0 ) < V_53 )
F_52 ( V_6 , 1 ) ;
}
if ( type == V_45 )
F_56 ( V_6 , V_54 ) ;
}
V_46:
if ( F_46 ( F_47 ( V_10 ) ) )
F_57 ( V_6 -> V_28 , type , V_10 ) ;
else
F_58 ( V_6 -> V_28 , type , V_10 ) ;
F_59 ( V_10 ) ;
}
static void F_60 ( struct V_55 * V_56 )
{
struct V_57 * V_58 = & V_56 -> V_58 ;
if ( ! V_56 -> V_10 )
return;
F_61 ( V_56 -> V_10 , V_58 -> V_59 , V_58 -> V_60 ) ;
if ( F_46 ( V_58 -> V_59 ) )
F_62 ( V_56 -> V_6 -> V_28 , V_58 -> type , V_56 -> V_10 ) ;
else
F_63 ( V_56 -> V_6 -> V_28 , V_58 -> type , V_56 -> V_10 ) ;
F_45 ( V_56 -> V_6 , V_56 -> V_10 , V_58 -> type ) ;
V_56 -> V_10 = NULL ;
}
static bool F_64 ( struct V_55 * V_56 ,
struct V_4 * V_4 , T_2 V_61 , T_3 V_62 )
{
struct V_11 * V_12 ;
struct V_1 * V_63 ;
int V_13 ;
if ( ! V_56 -> V_10 )
return false ;
if ( ! V_4 && ! V_61 )
return true ;
F_15 (bvec, io->bio, i) {
if ( V_12 -> V_15 -> V_3 )
V_63 = V_12 -> V_15 ;
else
V_63 = F_65 ( V_12 -> V_15 ) ;
if ( V_62 != V_63 -> V_64 )
continue;
if ( V_4 && V_4 == V_63 -> V_3 -> V_7 )
return true ;
if ( V_61 && V_61 == F_66 ( V_63 ) )
return true ;
}
return false ;
}
static bool F_67 ( struct V_5 * V_6 , struct V_4 * V_4 ,
T_2 V_61 , T_3 V_62 , enum V_40 type )
{
enum V_40 V_65 = F_68 ( type ) ;
enum V_66 V_67 ;
struct V_55 * V_56 ;
bool V_68 = false ;
for ( V_67 = V_69 ; V_67 < V_70 ; V_67 ++ ) {
V_56 = V_6 -> V_71 [ V_65 ] + V_67 ;
F_69 ( & V_56 -> V_72 ) ;
V_68 = F_64 ( V_56 , V_4 , V_61 , V_62 ) ;
F_70 ( & V_56 -> V_72 ) ;
if ( V_68 || V_65 == V_73 )
break;
}
return V_68 ;
}
static void F_71 ( struct V_5 * V_6 ,
enum V_40 type , enum V_66 V_67 )
{
enum V_40 V_65 = F_68 ( type ) ;
struct V_55 * V_56 = V_6 -> V_71 [ V_65 ] + V_67 ;
F_72 ( & V_56 -> V_72 ) ;
if ( type >= V_74 ) {
V_56 -> V_58 . type = V_74 ;
V_56 -> V_58 . V_59 = V_75 ;
V_56 -> V_58 . V_60 = V_76 | V_77 | V_78 ;
if ( ! F_73 ( V_6 , V_79 ) )
V_56 -> V_58 . V_60 |= V_80 | V_81 ;
}
F_60 ( V_56 ) ;
F_74 ( & V_56 -> V_72 ) ;
}
static void F_75 ( struct V_5 * V_6 ,
struct V_4 * V_4 , T_2 V_61 , T_3 V_62 ,
enum V_40 type , bool V_82 )
{
enum V_66 V_67 ;
if ( ! V_82 && ! F_67 ( V_6 , V_4 , V_61 , V_62 , type ) )
return;
for ( V_67 = V_69 ; V_67 < V_70 ; V_67 ++ ) {
F_71 ( V_6 , type , V_67 ) ;
if ( type >= V_73 )
break;
}
}
void F_76 ( struct V_5 * V_6 , enum V_40 type )
{
F_75 ( V_6 , NULL , 0 , 0 , type , true ) ;
}
void F_77 ( struct V_5 * V_6 ,
struct V_4 * V_4 , T_2 V_61 , T_3 V_62 ,
enum V_40 type )
{
F_75 ( V_6 , V_4 , V_61 , V_62 , type , false ) ;
}
void F_78 ( struct V_5 * V_6 )
{
F_76 ( V_6 , V_44 ) ;
F_76 ( V_6 , V_45 ) ;
F_76 ( V_6 , V_73 ) ;
}
int F_79 ( struct V_57 * V_58 )
{
struct V_10 * V_10 ;
struct V_1 * V_1 = V_58 -> V_83 ?
V_58 -> V_83 : V_58 -> V_1 ;
F_80 ( V_1 , V_58 ) ;
F_81 ( V_58 , 0 ) ;
V_10 = F_43 ( V_58 -> V_6 , V_58 -> V_84 , 1 , F_46 ( V_58 -> V_59 ) ) ;
if ( F_55 ( V_10 , V_1 , V_53 , 0 ) < V_53 ) {
F_21 ( V_10 ) ;
return - V_85 ;
}
F_61 ( V_10 , V_58 -> V_59 , V_58 -> V_60 ) ;
F_45 ( V_58 -> V_6 , V_10 , V_58 -> type ) ;
if ( ! F_46 ( V_58 -> V_59 ) )
F_82 ( V_58 -> V_6 , F_23 ( V_58 -> V_1 ) ) ;
return 0 ;
}
int F_83 ( struct V_57 * V_58 )
{
struct V_5 * V_6 = V_58 -> V_6 ;
enum V_40 V_65 = F_68 ( V_58 -> type ) ;
struct V_55 * V_56 = V_6 -> V_71 [ V_65 ] + V_58 -> V_67 ;
struct V_1 * V_86 ;
int V_87 = 0 ;
F_52 ( V_6 , F_46 ( V_58 -> V_59 ) ) ;
F_72 ( & V_56 -> V_72 ) ;
V_88:
if ( V_58 -> V_89 ) {
F_84 ( & V_56 -> V_90 ) ;
if ( F_85 ( & V_56 -> V_91 ) ) {
F_86 ( & V_56 -> V_90 ) ;
goto V_92;
}
V_58 = F_87 ( & V_56 -> V_91 ,
struct V_57 , V_93 ) ;
F_88 ( & V_58 -> V_93 ) ;
F_86 ( & V_56 -> V_90 ) ;
}
if ( V_58 -> V_94 != V_95 )
F_89 ( V_6 , V_58 -> V_94 ) ;
F_89 ( V_6 , V_58 -> V_84 ) ;
V_86 = V_58 -> V_83 ? V_58 -> V_83 : V_58 -> V_1 ;
V_58 -> V_96 = 1 ;
F_82 ( V_6 , F_23 ( V_86 ) ) ;
if ( V_56 -> V_10 && ( V_56 -> V_97 != V_58 -> V_84 - 1 ||
( V_56 -> V_58 . V_59 != V_58 -> V_59 || V_56 -> V_58 . V_60 != V_58 -> V_60 ) ||
! F_42 ( V_6 , V_58 -> V_84 , V_56 -> V_10 ) ) )
F_60 ( V_56 ) ;
V_98:
if ( V_56 -> V_10 == NULL ) {
if ( ( V_58 -> type == V_44 || V_58 -> type == V_45 ) &&
V_58 -> V_84 & F_90 ( V_6 ) ) {
V_87 = - V_99 ;
F_32 ( V_6 , F_23 ( V_86 ) ) ;
goto V_92;
}
V_56 -> V_10 = F_43 ( V_6 , V_58 -> V_84 ,
V_100 , false ) ;
V_56 -> V_58 = * V_58 ;
}
if ( F_55 ( V_56 -> V_10 , V_86 , V_53 , 0 ) < V_53 ) {
F_60 ( V_56 ) ;
goto V_98;
}
V_56 -> V_97 = V_58 -> V_84 ;
F_81 ( V_58 , 0 ) ;
F_91 ( V_58 -> V_1 , V_58 ) ;
if ( V_58 -> V_89 )
goto V_88;
V_92:
F_74 ( & V_56 -> V_72 ) ;
return V_87 ;
}
static void F_92 ( struct V_101 * V_102 )
{
struct V_103 * V_104 = F_93 ( V_102 -> V_105 ) ;
T_4 * V_106 ;
V_106 = F_94 ( V_104 ) ;
V_106 [ V_102 -> V_107 ] = F_95 ( V_102 -> V_108 ) ;
}
void F_96 ( struct V_101 * V_102 )
{
F_97 ( V_102 -> V_105 , V_45 , true ) ;
F_92 ( V_102 ) ;
if ( F_98 ( V_102 -> V_105 ) )
V_102 -> V_109 = true ;
}
void F_99 ( struct V_101 * V_102 , T_1 V_36 )
{
V_102 -> V_108 = V_36 ;
F_96 ( V_102 ) ;
F_100 ( V_102 ) ;
}
int F_101 ( struct V_101 * V_102 , T_5 V_110 )
{
struct V_5 * V_6 = F_2 ( V_102 -> V_4 ) ;
int V_87 ;
if ( ! V_110 )
return 0 ;
if ( F_28 ( F_102 ( V_102 -> V_4 , V_111 ) ) )
return - V_112 ;
if ( F_28 ( ( V_87 = F_103 ( V_6 , V_102 -> V_4 , & V_110 ) ) ) )
return V_87 ;
F_104 ( V_102 -> V_4 , V_102 -> V_113 ,
V_102 -> V_107 , V_110 ) ;
F_97 ( V_102 -> V_105 , V_45 , true ) ;
for (; V_110 > 0 ; V_102 -> V_107 ++ ) {
T_1 V_36 =
F_105 ( V_102 -> V_105 , V_102 -> V_107 ) ;
if ( V_36 == V_114 ) {
V_102 -> V_108 = V_95 ;
F_92 ( V_102 ) ;
V_110 -- ;
}
}
if ( F_98 ( V_102 -> V_105 ) )
V_102 -> V_109 = true ;
return 0 ;
}
int F_106 ( struct V_101 * V_102 )
{
unsigned int V_107 = V_102 -> V_107 ;
int V_68 ;
V_68 = F_101 ( V_102 , 1 ) ;
V_102 -> V_107 = V_107 ;
return V_68 ;
}
int F_107 ( struct V_101 * V_102 , T_3 V_64 )
{
bool V_115 = V_102 -> V_116 ? false : true ;
int V_87 ;
V_87 = F_108 ( V_102 , V_64 , V_117 ) ;
if ( V_87 )
return V_87 ;
if ( V_102 -> V_108 == V_114 )
V_87 = F_106 ( V_102 ) ;
if ( V_87 || V_115 )
F_109 ( V_102 ) ;
return V_87 ;
}
int F_110 ( struct V_101 * V_102 , T_3 V_64 )
{
struct V_118 V_119 = { 0 , 0 , 0 } ;
struct V_4 * V_4 = V_102 -> V_4 ;
if ( F_111 ( V_4 , V_64 , & V_119 ) ) {
V_102 -> V_108 = V_119 . V_120 + V_64 - V_119 . V_121 ;
return 0 ;
}
return F_107 ( V_102 , V_64 ) ;
}
struct V_1 * F_112 ( struct V_4 * V_4 , T_3 V_64 ,
int V_60 , bool V_122 )
{
struct V_2 * V_3 = V_4 -> V_123 ;
struct V_101 V_102 ;
struct V_1 * V_1 ;
struct V_118 V_119 = { 0 , 0 , 0 } ;
int V_87 ;
struct V_57 V_58 = {
. V_6 = F_2 ( V_4 ) ,
. type = V_44 ,
. V_59 = V_124 ,
. V_60 = V_60 ,
. V_83 = NULL ,
} ;
if ( F_113 ( V_4 ) && F_114 ( V_4 -> V_9 ) )
return F_115 ( V_3 , V_64 , NULL ) ;
V_1 = F_116 ( V_3 , V_64 , V_122 ) ;
if ( ! V_1 )
return F_117 ( - V_125 ) ;
if ( F_111 ( V_4 , V_64 , & V_119 ) ) {
V_102 . V_108 = V_119 . V_120 + V_64 - V_119 . V_121 ;
goto V_126;
}
F_118 ( & V_102 , V_4 , NULL , NULL , 0 ) ;
V_87 = F_108 ( & V_102 , V_64 , V_127 ) ;
if ( V_87 )
goto V_128;
F_109 ( & V_102 ) ;
if ( F_28 ( V_102 . V_108 == V_114 ) ) {
V_87 = - V_129 ;
goto V_128;
}
V_126:
if ( F_16 ( V_1 ) ) {
F_20 ( V_1 ) ;
return V_1 ;
}
if ( V_102 . V_108 == V_95 ) {
F_119 ( V_1 , 0 , V_53 ) ;
if ( ! F_16 ( V_1 ) )
F_17 ( V_1 ) ;
F_20 ( V_1 ) ;
return V_1 ;
}
V_58 . V_84 = V_58 . V_94 = V_102 . V_108 ;
V_58 . V_1 = V_1 ;
V_87 = F_79 ( & V_58 ) ;
if ( V_87 )
goto V_128;
return V_1 ;
V_128:
F_120 ( V_1 , 1 ) ;
return F_117 ( V_87 ) ;
}
struct V_1 * F_121 ( struct V_4 * V_4 , T_3 V_64 )
{
struct V_2 * V_3 = V_4 -> V_123 ;
struct V_1 * V_1 ;
V_1 = F_122 ( V_3 , V_64 ) ;
if ( V_1 && F_16 ( V_1 ) )
return V_1 ;
F_120 ( V_1 , 0 ) ;
V_1 = F_112 ( V_4 , V_64 , 0 , false ) ;
if ( F_123 ( V_1 ) )
return V_1 ;
if ( F_16 ( V_1 ) )
return V_1 ;
F_124 ( V_1 ) ;
if ( F_28 ( ! F_16 ( V_1 ) ) ) {
F_120 ( V_1 , 0 ) ;
return F_117 ( - V_22 ) ;
}
return V_1 ;
}
struct V_1 * F_125 ( struct V_4 * V_4 , T_3 V_64 ,
bool V_122 )
{
struct V_2 * V_3 = V_4 -> V_123 ;
struct V_1 * V_1 ;
V_130:
V_1 = F_112 ( V_4 , V_64 , 0 , V_122 ) ;
if ( F_123 ( V_1 ) )
return V_1 ;
F_54 ( V_1 ) ;
if ( F_28 ( V_1 -> V_3 != V_3 ) ) {
F_120 ( V_1 , 1 ) ;
goto V_130;
}
if ( F_28 ( ! F_16 ( V_1 ) ) ) {
F_120 ( V_1 , 1 ) ;
return F_117 ( - V_22 ) ;
}
return V_1 ;
}
struct V_1 * F_126 ( struct V_4 * V_4 ,
struct V_1 * V_131 , T_3 V_64 , bool V_132 )
{
struct V_2 * V_3 = V_4 -> V_123 ;
struct V_1 * V_1 ;
struct V_101 V_102 ;
int V_87 ;
V_1 = F_116 ( V_3 , V_64 , true ) ;
if ( ! V_1 ) {
F_120 ( V_131 , 1 ) ;
return F_117 ( - V_125 ) ;
}
F_118 ( & V_102 , V_4 , V_131 , NULL , 0 ) ;
V_87 = F_107 ( & V_102 , V_64 ) ;
if ( V_87 ) {
F_120 ( V_1 , 1 ) ;
return F_117 ( V_87 ) ;
}
if ( ! V_131 )
F_109 ( & V_102 ) ;
if ( F_16 ( V_1 ) )
goto V_126;
if ( V_102 . V_108 == V_95 ) {
F_119 ( V_1 , 0 , V_53 ) ;
if ( ! F_16 ( V_1 ) )
F_17 ( V_1 ) ;
} else {
F_120 ( V_1 , 1 ) ;
F_52 ( F_2 ( V_4 ) , V_131 ) ;
V_1 = F_125 ( V_4 , V_64 , true ) ;
if ( F_123 ( V_1 ) )
return V_1 ;
}
V_126:
if ( V_132 && F_127 ( V_4 ) <
( ( V_133 ) ( V_64 + 1 ) << V_134 ) )
F_128 ( V_4 , ( ( V_133 ) ( V_64 + 1 ) << V_134 ) ) ;
return V_1 ;
}
static int F_129 ( struct V_101 * V_102 )
{
struct V_5 * V_6 = F_2 ( V_102 -> V_4 ) ;
struct V_135 V_136 ;
struct V_137 V_138 ;
T_3 V_121 ;
T_5 V_110 = 1 ;
int V_87 ;
if ( F_28 ( F_102 ( V_102 -> V_4 , V_111 ) ) )
return - V_112 ;
V_102 -> V_108 = F_105 ( V_102 -> V_105 , V_102 -> V_107 ) ;
if ( V_102 -> V_108 == V_95 )
goto V_139;
if ( F_28 ( ( V_87 = F_103 ( V_6 , V_102 -> V_4 , & V_110 ) ) ) )
return V_87 ;
V_139:
F_130 ( V_6 , V_102 -> V_113 , & V_138 ) ;
F_131 ( & V_136 , V_102 -> V_113 , V_102 -> V_107 , V_138 . V_140 ) ;
F_132 ( V_6 , NULL , V_102 -> V_108 , & V_102 -> V_108 ,
& V_136 , V_141 , NULL , false ) ;
F_96 ( V_102 ) ;
V_121 = F_133 ( F_134 ( V_102 -> V_105 ) , V_102 -> V_4 ) +
V_102 -> V_107 ;
if ( F_127 ( V_102 -> V_4 ) < ( ( V_133 ) ( V_121 + 1 ) << V_134 ) )
F_128 ( V_102 -> V_4 ,
( ( V_133 ) ( V_121 + 1 ) << V_134 ) ) ;
return 0 ;
}
static inline bool F_135 ( struct V_4 * V_4 , int V_142 )
{
return ( ( F_113 ( V_4 ) && F_114 ( V_4 -> V_9 ) ) ||
( V_142 == V_143 && F_73 ( F_2 ( V_4 ) , V_144 ) ) ||
F_2 ( V_4 ) -> V_30 ) ;
}
int F_136 ( struct V_145 * V_146 , struct V_147 * V_148 )
{
struct V_4 * V_4 = F_137 ( V_146 -> V_149 ) ;
struct V_150 V_151 ;
int V_87 = 0 ;
if ( F_102 ( V_4 , V_152 ) )
return 0 ;
V_151 . V_153 = F_138 ( V_146 -> V_154 ) ;
V_151 . V_155 = F_139 ( V_146 -> V_154 + F_140 ( V_148 ) ) ;
if ( V_151 . V_155 > V_151 . V_153 )
V_151 . V_155 -= V_151 . V_153 ;
else
V_151 . V_155 = 0 ;
V_151 . V_156 = NULL ;
if ( V_146 -> V_157 & V_158 ) {
V_87 = F_141 ( V_4 ) ;
if ( V_87 )
return V_87 ;
return V_150 ( V_4 , & V_151 , 1 ,
F_135 ( V_4 , V_143 ) ?
V_159 :
V_160 ) ;
}
if ( V_146 -> V_154 + F_140 ( V_148 ) > V_161 ) {
V_87 = F_141 ( V_4 ) ;
if ( V_87 )
return V_87 ;
}
if ( ! F_142 ( V_4 ) )
return V_150 ( V_4 , & V_151 , 1 , V_159 ) ;
return V_87 ;
}
static inline void F_143 ( struct V_5 * V_6 , int V_162 , bool V_163 )
{
if ( V_162 == V_159 ) {
if ( V_163 )
F_69 ( & V_6 -> V_164 ) ;
else
F_70 ( & V_6 -> V_164 ) ;
} else {
if ( V_163 )
F_144 ( V_6 ) ;
else
F_145 ( V_6 ) ;
}
}
int V_150 ( struct V_4 * V_4 , struct V_150 * V_151 ,
int V_165 , int V_162 )
{
unsigned int V_166 = V_151 -> V_155 ;
struct V_101 V_102 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
int V_167 = V_165 ? V_117 : V_127 ;
T_3 V_168 , V_169 , V_170 ;
int V_87 = 0 , V_171 = 1 ;
unsigned int V_107 , V_172 ;
T_5 V_173 ;
struct V_118 V_119 = { 0 , 0 , 0 } ;
T_1 V_36 ;
if ( ! V_166 )
return 0 ;
V_151 -> V_155 = 0 ;
V_151 -> V_174 = 0 ;
V_168 = ( T_3 ) V_151 -> V_153 ;
V_170 = V_168 + V_166 ;
if ( ! V_165 && F_111 ( V_4 , V_168 , & V_119 ) ) {
V_151 -> V_175 = V_119 . V_120 + V_168 - V_119 . V_121 ;
V_151 -> V_155 = F_146 ( ( T_3 ) V_166 , V_119 . V_121 + V_119 . V_176 - V_168 ) ;
V_151 -> V_174 = V_177 ;
goto V_178;
}
V_179:
if ( V_165 )
F_143 ( V_6 , V_162 , true ) ;
F_118 ( & V_102 , V_4 , NULL , NULL , 0 ) ;
V_87 = F_108 ( & V_102 , V_168 , V_167 ) ;
if ( V_87 ) {
if ( V_162 == V_180 )
V_151 -> V_175 = 0 ;
if ( V_87 == - V_129 ) {
V_87 = 0 ;
if ( V_151 -> V_156 )
* V_151 -> V_156 =
F_147 ( & V_102 , V_168 ) ;
}
goto V_181;
}
V_173 = 0 ;
V_172 = V_107 = V_102 . V_107 ;
V_169 = F_148 ( V_102 . V_105 , V_4 ) ;
V_182:
V_36 = F_105 ( V_102 . V_105 , V_102 . V_107 ) ;
if ( V_36 == V_95 || V_36 == V_114 ) {
if ( V_165 ) {
if ( F_28 ( F_149 ( V_6 ) ) ) {
V_87 = - V_22 ;
goto V_183;
}
if ( V_162 == V_159 ) {
if ( V_36 == V_114 ) {
V_173 ++ ;
V_172 = V_102 . V_107 ;
}
} else {
V_87 = F_129 ( & V_102 ) ;
if ( ! V_87 )
F_150 ( V_4 , V_184 ) ;
}
if ( V_87 )
goto V_183;
V_151 -> V_174 |= V_185 ;
V_36 = V_102 . V_108 ;
} else {
if ( V_162 == V_180 ) {
V_151 -> V_175 = 0 ;
goto V_183;
}
if ( V_162 == V_186 &&
V_36 == V_114 ) {
if ( V_151 -> V_156 )
* V_151 -> V_156 = V_168 + 1 ;
}
if ( V_162 != V_186 ||
V_36 != V_95 )
goto V_183;
}
}
if ( V_162 == V_159 )
goto V_187;
if ( V_151 -> V_155 == 0 ) {
if ( V_36 == V_95 )
V_151 -> V_174 |= V_188 ;
V_151 -> V_174 |= V_177 ;
V_151 -> V_175 = V_36 ;
V_151 -> V_155 = 1 ;
} else if ( ( V_151 -> V_175 != V_95 &&
V_36 == ( V_151 -> V_175 + V_171 ) ) ||
( V_151 -> V_175 == V_95 && V_36 == V_95 ) ||
V_162 == V_160 ) {
V_171 ++ ;
V_151 -> V_155 ++ ;
} else {
goto V_183;
}
V_187:
V_102 . V_107 ++ ;
V_168 ++ ;
if ( V_162 == V_159 &&
( V_168 == V_170 || V_102 . V_107 == V_169 ) ) {
V_102 . V_107 = V_107 ;
V_87 = F_101 ( & V_102 , V_173 ) ;
if ( V_87 )
goto V_183;
V_151 -> V_155 += V_102 . V_107 - V_107 ;
if ( V_173 && V_102 . V_107 != V_172 + 1 ) {
V_87 = - V_189 ;
goto V_183;
}
V_102 . V_107 = V_169 ;
}
if ( V_168 >= V_170 )
goto V_183;
else if ( V_102 . V_107 < V_169 )
goto V_182;
F_109 ( & V_102 ) ;
if ( V_165 ) {
F_143 ( V_6 , V_162 , false ) ;
F_151 ( V_6 , V_102 . V_109 ) ;
}
goto V_179;
V_183:
F_109 ( & V_102 ) ;
V_181:
if ( V_165 ) {
F_143 ( V_6 , V_162 , false ) ;
F_151 ( V_6 , V_102 . V_109 ) ;
}
V_178:
F_152 ( V_4 , V_151 , V_87 ) ;
return V_87 ;
}
static int F_153 ( struct V_4 * V_4 , T_6 V_190 ,
struct V_191 * V_192 , int V_165 , int V_162 ,
T_3 * V_193 )
{
struct V_150 V_151 ;
int V_87 ;
V_151 . V_153 = V_190 ;
V_151 . V_155 = V_192 -> V_194 >> V_4 -> V_195 ;
V_151 . V_156 = V_193 ;
V_87 = V_150 ( V_4 , & V_151 , V_165 , V_162 ) ;
if ( ! V_87 ) {
F_154 ( V_192 , V_4 -> V_196 , V_151 . V_175 ) ;
V_192 -> V_197 = ( V_192 -> V_197 & ~ V_198 ) | V_151 . V_174 ;
V_192 -> V_194 = ( V_199 ) V_151 . V_155 << V_4 -> V_195 ;
}
return V_87 ;
}
static int F_155 ( struct V_4 * V_4 , T_6 V_190 ,
struct V_191 * V_200 , int V_165 , int V_162 ,
T_3 * V_193 )
{
return F_153 ( V_4 , V_190 , V_200 , V_165 ,
V_162 , V_193 ) ;
}
static int F_156 ( struct V_4 * V_4 , T_6 V_190 ,
struct V_191 * V_200 , int V_165 )
{
return F_153 ( V_4 , V_190 , V_200 , V_165 ,
V_201 , NULL ) ;
}
static int F_157 ( struct V_4 * V_4 , T_6 V_190 ,
struct V_191 * V_200 , int V_165 )
{
if ( F_28 ( V_190 >= F_2 ( V_4 ) -> V_202 ) )
return - V_203 ;
return F_153 ( V_4 , V_190 , V_200 , V_165 ,
V_180 , NULL ) ;
}
static inline T_6 F_158 ( struct V_4 * V_4 , V_133 V_204 )
{
return ( V_204 >> V_4 -> V_195 ) ;
}
static inline V_133 F_159 ( struct V_4 * V_4 , T_6 V_120 )
{
return ( V_120 << V_4 -> V_195 ) ;
}
int F_160 ( struct V_4 * V_4 , struct V_205 * V_206 ,
V_199 V_41 , V_199 V_176 )
{
struct V_191 F_154 ;
T_6 V_31 , V_207 ;
T_3 V_193 ;
V_199 V_208 = 0 , V_209 = 0 , V_210 = 0 ;
T_7 V_211 = 0 ;
int V_68 = 0 ;
V_68 = F_161 ( V_206 , V_212 ) ;
if ( V_68 )
return V_68 ;
if ( F_142 ( V_4 ) ) {
V_68 = F_162 ( V_4 , V_206 , V_41 , V_176 ) ;
if ( V_68 != - V_99 )
return V_68 ;
}
F_163 ( V_4 ) ;
if ( F_158 ( V_4 , V_176 ) == 0 )
V_176 = F_159 ( V_4 , 1 ) ;
V_31 = F_158 ( V_4 , V_41 ) ;
V_207 = F_158 ( V_4 , V_41 + V_176 - 1 ) ;
V_88:
memset ( & F_154 , 0 , sizeof( struct V_191 ) ) ;
F_154 . V_194 = V_176 ;
V_68 = F_155 ( V_4 , V_31 , & F_154 , 0 ,
V_186 , & V_193 ) ;
if ( V_68 )
goto V_178;
if ( ! F_164 ( & F_154 ) ) {
V_31 = V_193 ;
if ( F_159 ( V_4 , V_31 ) < F_159 ( V_4 ,
F_2 ( V_4 ) -> V_202 ) )
goto V_213;
V_211 |= V_214 ;
}
if ( V_210 ) {
if ( F_113 ( V_4 ) )
V_211 |= V_215 ;
V_68 = F_165 ( V_206 , V_208 ,
V_209 , V_210 , V_211 ) ;
}
if ( V_31 > V_207 || V_68 )
goto V_178;
V_208 = F_159 ( V_4 , V_31 ) ;
V_209 = F_159 ( V_4 , F_154 . V_216 ) ;
V_210 = F_154 . V_194 ;
V_211 = 0 ;
if ( F_166 ( & F_154 ) )
V_211 = V_217 ;
V_31 += F_158 ( V_4 , V_210 ) ;
V_213:
F_167 () ;
if ( F_168 ( V_42 ) )
V_68 = - V_218 ;
else
goto V_88;
V_178:
if ( V_68 == 1 )
V_68 = 0 ;
F_169 ( V_4 ) ;
return V_68 ;
}
static struct V_10 * F_170 ( struct V_4 * V_4 , T_1 V_36 ,
unsigned V_219 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_220 * V_221 = NULL ;
struct V_10 * V_10 ;
if ( F_113 ( V_4 ) && F_114 ( V_4 -> V_9 ) ) {
V_221 = F_171 ( V_4 , V_222 ) ;
if ( F_123 ( V_221 ) )
return F_172 ( V_221 ) ;
F_173 ( V_6 , V_36 ) ;
}
V_10 = F_174 ( V_223 , F_175 ( int , V_219 , V_100 ) ) ;
if ( ! V_10 ) {
if ( V_221 )
F_13 ( V_221 ) ;
return F_117 ( - V_125 ) ;
}
F_38 ( V_6 , V_36 , V_10 ) ;
V_10 -> V_39 = F_7 ;
V_10 -> V_19 = V_221 ;
return V_10 ;
}
static int F_176 ( struct V_2 * V_3 ,
struct V_224 * V_225 , struct V_1 * V_1 ,
unsigned V_219 )
{
struct V_10 * V_10 = NULL ;
unsigned V_226 ;
T_6 V_97 = 0 ;
struct V_4 * V_4 = V_3 -> V_7 ;
const unsigned V_227 = V_4 -> V_195 ;
const unsigned V_228 = 1 << V_227 ;
T_6 V_229 ;
T_6 V_230 ;
T_6 V_231 ;
T_6 V_232 ;
struct V_150 V_151 ;
V_151 . V_175 = 0 ;
V_151 . V_153 = 0 ;
V_151 . V_155 = 0 ;
V_151 . V_174 = 0 ;
V_151 . V_156 = NULL ;
for ( V_226 = 0 ; V_219 ; V_226 ++ , V_219 -- ) {
if ( V_225 ) {
V_1 = F_177 ( V_225 , struct V_1 , V_233 ) ;
F_178 ( & V_1 -> V_211 ) ;
F_88 ( & V_1 -> V_233 ) ;
if ( F_179 ( V_1 , V_3 ,
V_1 -> V_64 ,
F_180 ( V_3 ) ) )
goto V_234;
}
V_229 = ( T_6 ) V_1 -> V_64 ;
V_230 = V_229 + V_219 ;
V_231 = ( F_127 ( V_4 ) + V_228 - 1 ) >>
V_227 ;
if ( V_230 > V_231 )
V_230 = V_231 ;
if ( ( V_151 . V_174 & V_177 ) &&
V_229 > V_151 . V_153 &&
V_229 < ( V_151 . V_153 + V_151 . V_155 ) )
goto V_126;
V_151 . V_174 = 0 ;
if ( V_229 < V_230 ) {
V_151 . V_153 = V_229 ;
V_151 . V_155 = V_230 - V_229 ;
if ( V_150 ( V_4 , & V_151 , 0 ,
V_235 ) )
goto V_236;
}
V_126:
if ( ( V_151 . V_174 & V_177 ) ) {
V_232 = V_151 . V_175 + V_229 - V_151 . V_153 ;
F_181 ( V_1 ) ;
if ( ! F_16 ( V_1 ) && ! F_182 ( V_1 ) ) {
F_17 ( V_1 ) ;
goto V_237;
}
} else {
F_119 ( V_1 , 0 , V_53 ) ;
if ( ! F_16 ( V_1 ) )
F_17 ( V_1 ) ;
F_20 ( V_1 ) ;
goto V_234;
}
if ( V_10 && ( V_97 != V_232 - 1 ||
! F_42 ( F_2 ( V_4 ) , V_232 , V_10 ) ) ) {
V_238:
F_45 ( F_2 ( V_4 ) , V_10 , V_44 ) ;
V_10 = NULL ;
}
if ( V_10 == NULL ) {
V_10 = F_170 ( V_4 , V_232 , V_219 ) ;
if ( F_123 ( V_10 ) ) {
V_10 = NULL ;
goto V_236;
}
F_61 ( V_10 , V_124 , 0 ) ;
}
if ( F_55 ( V_10 , V_1 , V_228 , 0 ) < V_228 )
goto V_238;
V_97 = V_232 ;
goto V_234;
V_236:
F_19 ( V_1 ) ;
F_119 ( V_1 , 0 , V_53 ) ;
F_20 ( V_1 ) ;
goto V_234;
V_237:
if ( V_10 ) {
F_45 ( F_2 ( V_4 ) , V_10 , V_44 ) ;
V_10 = NULL ;
}
F_20 ( V_1 ) ;
V_234:
if ( V_225 )
F_183 ( V_1 ) ;
}
F_184 ( V_225 && ! F_85 ( V_225 ) ) ;
if ( V_10 )
F_45 ( F_2 ( V_4 ) , V_10 , V_44 ) ;
return 0 ;
}
static int F_185 ( struct V_239 * V_239 , struct V_1 * V_1 )
{
struct V_4 * V_4 = V_1 -> V_3 -> V_7 ;
int V_68 = - V_99 ;
F_186 ( V_1 , V_44 ) ;
if ( F_142 ( V_4 ) )
V_68 = F_187 ( V_4 , V_1 ) ;
if ( V_68 == - V_99 )
V_68 = F_176 ( V_1 -> V_3 , NULL , V_1 , 1 ) ;
return V_68 ;
}
static int F_188 ( struct V_239 * V_239 ,
struct V_2 * V_3 ,
struct V_224 * V_225 , unsigned V_219 )
{
struct V_4 * V_4 = V_239 -> V_240 -> V_7 ;
struct V_1 * V_1 = F_177 ( V_225 , struct V_1 , V_233 ) ;
F_189 ( V_4 , V_1 , V_219 ) ;
if ( F_142 ( V_4 ) )
return 0 ;
return F_176 ( V_3 , V_225 , NULL , V_219 ) ;
}
static int F_190 ( struct V_57 * V_58 )
{
struct V_4 * V_4 = V_58 -> V_1 -> V_3 -> V_7 ;
T_8 V_241 = V_222 ;
if ( ! F_113 ( V_4 ) || ! F_114 ( V_4 -> V_9 ) )
return 0 ;
F_173 ( V_58 -> V_6 , V_58 -> V_94 ) ;
V_242:
V_58 -> V_83 = F_191 ( V_4 , V_58 -> V_1 ,
V_53 , 0 , V_58 -> V_1 -> V_64 , V_241 ) ;
if ( ! F_123 ( V_58 -> V_83 ) )
return 0 ;
if ( F_192 ( V_58 -> V_83 ) == - V_125 ) {
F_78 ( V_58 -> V_6 ) ;
F_193 ( V_243 , V_244 / 50 ) ;
V_241 |= V_51 ;
goto V_242;
}
return F_192 ( V_58 -> V_83 ) ;
}
static inline bool F_194 ( struct V_57 * V_58 )
{
struct V_4 * V_4 = V_58 -> V_1 -> V_3 -> V_7 ;
if ( F_5 ( V_4 -> V_9 ) || F_195 ( V_4 ) )
return false ;
if ( F_6 ( V_58 -> V_1 ) )
return false ;
if ( F_196 ( V_58 -> V_1 ) )
return false ;
return F_197 ( V_4 , V_58 ) ;
}
static inline bool F_198 ( struct V_57 * V_58 )
{
if ( V_58 -> V_94 == V_95 )
return false ;
if ( V_58 -> V_94 == V_114 )
return false ;
return true ;
}
int F_199 ( struct V_57 * V_58 )
{
struct V_1 * V_1 = V_58 -> V_1 ;
struct V_4 * V_4 = V_1 -> V_3 -> V_7 ;
struct V_101 V_102 ;
struct V_118 V_119 = { 0 , 0 , 0 } ;
bool V_245 = false ;
int V_87 = 0 ;
F_118 ( & V_102 , V_4 , NULL , NULL , 0 ) ;
if ( F_194 ( V_58 ) &&
F_111 ( V_4 , V_1 -> V_64 , & V_119 ) ) {
V_58 -> V_94 = V_119 . V_120 + V_1 -> V_64 - V_119 . V_121 ;
if ( F_198 ( V_58 ) ) {
V_245 = true ;
V_58 -> V_246 = V_247 ;
goto V_126;
}
}
if ( V_58 -> V_246 == V_248 && ! F_200 ( V_58 -> V_6 ) )
return - V_99 ;
V_87 = F_108 ( & V_102 , V_1 -> V_64 , V_127 ) ;
if ( V_87 )
goto V_178;
V_58 -> V_94 = V_102 . V_108 ;
if ( V_58 -> V_94 == V_114 ) {
F_18 ( V_1 ) ;
goto V_249;
}
V_126:
if ( V_245 || ( F_198 ( V_58 ) && F_194 ( V_58 ) ) ) {
V_87 = F_190 ( V_58 ) ;
if ( V_87 )
goto V_249;
F_201 ( V_1 ) ;
F_109 ( & V_102 ) ;
if ( V_58 -> V_246 == V_248 )
F_145 ( V_58 -> V_6 ) ;
V_87 = F_202 ( V_58 ) ;
F_203 ( V_58 -> V_1 , V_250 ) ;
F_150 ( V_4 , V_251 ) ;
return V_87 ;
}
if ( V_58 -> V_246 == V_252 ) {
if ( ! F_200 ( V_58 -> V_6 ) ) {
V_87 = - V_99 ;
goto V_249;
}
V_58 -> V_246 = V_248 ;
}
V_87 = F_190 ( V_58 ) ;
if ( V_87 )
goto V_249;
F_201 ( V_1 ) ;
F_204 ( & V_102 , V_58 ) ;
F_203 ( V_1 , V_253 ) ;
F_150 ( V_4 , V_184 ) ;
if ( V_1 -> V_64 == 0 )
F_150 ( V_4 , V_254 ) ;
V_249:
F_109 ( & V_102 ) ;
V_178:
if ( V_58 -> V_246 == V_248 )
F_145 ( V_58 -> V_6 ) ;
return V_87 ;
}
static int F_205 ( struct V_1 * V_1 , bool * V_96 ,
struct V_255 * V_256 )
{
struct V_4 * V_4 = V_1 -> V_3 -> V_7 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
V_133 V_257 = F_127 ( V_4 ) ;
const T_3 V_258 = ( ( unsigned long long ) V_257 )
>> V_134 ;
V_133 V_259 = ( V_1 -> V_64 + 1 ) << V_134 ;
unsigned V_204 = 0 ;
bool V_260 = false ;
int V_87 = 0 ;
struct V_57 V_58 = {
. V_6 = V_6 ,
. type = V_44 ,
. V_59 = V_75 ,
. V_60 = F_206 ( V_256 ) ,
. V_94 = V_114 ,
. V_1 = V_1 ,
. V_83 = NULL ,
. V_96 = false ,
. V_246 = V_252 ,
} ;
F_207 ( V_1 , V_44 ) ;
if ( F_28 ( F_208 ( V_6 , V_261 ) ) )
goto V_262;
if ( V_1 -> V_64 < V_258 )
goto V_263;
V_204 = V_257 & ( V_53 - 1 ) ;
if ( ( V_1 -> V_64 >= V_258 + 1 ) || ! V_204 )
goto V_178;
F_119 ( V_1 , V_204 , V_53 ) ;
V_263:
if ( F_209 ( V_4 ) )
goto V_178;
if ( F_210 ( V_4 ) && ( ! V_1 -> V_64 ||
( ! V_256 -> V_264 &&
F_211 ( V_6 , V_265 ) ) ) )
goto V_262;
if ( F_28 ( F_149 ( V_6 ) ) ) {
F_31 ( V_1 -> V_3 , - V_22 ) ;
goto V_178;
}
if ( F_5 ( V_4 -> V_9 ) ) {
V_58 . V_246 = V_247 ;
V_87 = F_199 ( & V_58 ) ;
goto V_266;
}
if ( ! V_256 -> V_264 )
V_260 = true ;
else if ( F_212 ( V_6 , 0 , 0 ) )
goto V_262;
else
F_150 ( V_4 , V_267 ) ;
V_87 = - V_99 ;
if ( F_142 ( V_4 ) ) {
V_87 = F_213 ( V_4 , V_1 ) ;
if ( ! V_87 )
goto V_178;
}
if ( V_87 == - V_99 ) {
V_87 = F_199 ( & V_58 ) ;
if ( V_87 == - V_99 ) {
V_58 . V_246 = V_248 ;
V_87 = F_199 ( & V_58 ) ;
}
}
if ( F_214 ( V_4 ) -> V_268 < V_259 )
F_214 ( V_4 ) -> V_268 = V_259 ;
V_266:
if ( V_87 && V_87 != - V_129 )
goto V_262;
V_178:
F_215 ( V_4 ) ;
if ( V_87 )
F_18 ( V_1 ) ;
if ( V_256 -> V_264 ) {
F_77 ( V_6 , V_4 , 0 , V_1 -> V_64 , V_44 ) ;
F_216 ( V_4 , V_267 ) ;
F_217 ( V_4 ) ;
V_96 = NULL ;
}
F_20 ( V_1 ) ;
if ( ! F_5 ( V_4 -> V_9 ) )
F_151 ( V_6 , V_260 ) ;
if ( F_28 ( F_149 ( V_6 ) ) ) {
F_76 ( V_6 , V_44 ) ;
V_96 = NULL ;
}
if ( V_96 )
* V_96 = V_58 . V_96 ;
return 0 ;
V_262:
F_218 ( V_256 , V_1 ) ;
if ( ! V_87 )
return V_269 ;
F_20 ( V_1 ) ;
return V_87 ;
}
static int F_219 ( struct V_1 * V_1 ,
struct V_255 * V_256 )
{
return F_205 ( V_1 , NULL , V_256 ) ;
}
static int F_220 ( struct V_2 * V_3 ,
struct V_255 * V_256 )
{
int V_68 = 0 ;
int V_266 = 0 ;
struct V_270 V_271 ;
int V_219 ;
T_3 V_272 ( V_273 ) ;
T_3 V_64 ;
T_3 V_170 ;
T_3 V_274 ;
T_3 V_275 = V_276 ;
int V_277 ;
int V_278 = 0 ;
int V_279 ;
F_221 ( & V_271 , 0 ) ;
if ( F_222 ( V_3 -> V_7 ) <=
F_223 ( F_224 ( V_3 ) ) -> V_280 )
F_150 ( V_3 -> V_7 , V_267 ) ;
else
F_216 ( V_3 -> V_7 , V_267 ) ;
if ( V_256 -> V_281 ) {
V_273 = V_3 -> V_273 ;
V_64 = V_273 ;
if ( V_64 == 0 )
V_277 = 1 ;
else
V_277 = 0 ;
V_170 = - 1 ;
} else {
V_64 = V_256 -> V_282 >> V_134 ;
V_170 = V_256 -> V_283 >> V_134 ;
if ( V_256 -> V_282 == 0 && V_256 -> V_283 == V_284 )
V_278 = 1 ;
V_277 = 1 ;
}
if ( V_256 -> V_285 == V_286 || V_256 -> V_287 )
V_279 = V_288 ;
else
V_279 = V_289 ;
V_290:
if ( V_256 -> V_285 == V_286 || V_256 -> V_287 )
F_225 ( V_3 , V_64 , V_170 ) ;
V_274 = V_64 ;
while ( ! V_266 && ( V_64 <= V_170 ) ) {
int V_13 ;
V_219 = F_226 ( & V_271 , V_3 , & V_64 , V_279 ,
F_146 ( V_170 - V_64 , ( T_3 ) V_291 - 1 ) + 1 ) ;
if ( V_219 == 0 )
break;
for ( V_13 = 0 ; V_13 < V_219 ; V_13 ++ ) {
struct V_1 * V_1 = V_271 . V_225 [ V_13 ] ;
bool V_96 = false ;
if ( V_1 -> V_64 > V_170 ) {
V_266 = 1 ;
break;
}
V_274 = V_1 -> V_64 ;
V_292:
F_54 ( V_1 ) ;
if ( F_28 ( V_1 -> V_3 != V_3 ) ) {
V_293:
F_20 ( V_1 ) ;
continue;
}
if ( ! F_227 ( V_1 ) ) {
goto V_293;
}
if ( F_228 ( V_1 ) ) {
if ( V_256 -> V_285 != V_294 )
F_97 ( V_1 ,
V_44 , true ) ;
else
goto V_293;
}
F_184 ( F_228 ( V_1 ) ) ;
if ( ! F_229 ( V_1 ) )
goto V_293;
V_68 = F_205 ( V_1 , & V_96 , V_256 ) ;
if ( F_28 ( V_68 ) ) {
if ( V_68 == V_269 ) {
F_20 ( V_1 ) ;
V_68 = 0 ;
continue;
} else if ( V_68 == - V_99 ) {
V_68 = 0 ;
if ( V_256 -> V_285 == V_286 ) {
F_167 () ;
F_193 ( V_243 ,
V_244 / 50 ) ;
goto V_292;
}
continue;
}
V_274 = V_1 -> V_64 + 1 ;
V_266 = 1 ;
break;
} else if ( V_96 ) {
V_275 = V_1 -> V_64 ;
}
if ( ( F_230 ( & F_224 ( V_3 ) -> V_295 ) ||
-- V_256 -> V_296 <= 0 ) &&
V_256 -> V_285 == V_294 ) {
V_266 = 1 ;
break;
}
}
F_231 ( & V_271 ) ;
F_167 () ;
}
if ( ! V_277 && ! V_266 ) {
V_277 = 1 ;
V_64 = 0 ;
V_170 = V_273 - 1 ;
goto V_290;
}
if ( V_256 -> V_281 || ( V_278 && V_256 -> V_296 > 0 ) )
V_3 -> V_273 = V_274 ;
if ( V_275 != V_276 )
F_77 ( F_224 ( V_3 ) , V_3 -> V_7 ,
0 , V_275 , V_44 ) ;
return V_68 ;
}
static int F_232 ( struct V_2 * V_3 ,
struct V_255 * V_256 )
{
struct V_4 * V_4 = V_3 -> V_7 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_297 V_43 ;
int V_68 ;
if ( ! V_3 -> V_298 -> V_299 )
return 0 ;
if ( ! F_222 ( V_4 ) && V_256 -> V_285 == V_294 )
return 0 ;
if ( F_28 ( F_208 ( V_6 , V_261 ) ) )
goto V_300;
if ( F_5 ( V_4 -> V_9 ) && V_256 -> V_285 == V_294 &&
F_222 ( V_4 ) < F_233 ( V_6 , V_44 ) &&
F_211 ( V_6 , V_301 ) )
goto V_300;
if ( F_102 ( V_4 , V_302 ) )
goto V_300;
F_234 ( V_3 -> V_7 , V_256 , V_44 ) ;
if ( V_256 -> V_285 == V_286 )
F_235 ( & V_6 -> V_295 ) ;
else if ( F_230 ( & V_6 -> V_295 ) )
goto V_300;
F_236 ( & V_43 ) ;
V_68 = F_220 ( V_3 , V_256 ) ;
F_49 ( & V_43 ) ;
if ( V_256 -> V_285 == V_286 )
F_237 ( & V_6 -> V_295 ) ;
F_217 ( V_4 ) ;
return V_68 ;
V_300:
V_256 -> V_303 += F_222 ( V_4 ) ;
F_234 ( V_3 -> V_7 , V_256 , V_44 ) ;
return 0 ;
}
static void F_238 ( struct V_2 * V_3 , V_133 V_304 )
{
struct V_4 * V_4 = V_3 -> V_7 ;
V_133 V_257 = F_127 ( V_4 ) ;
if ( V_304 > V_257 ) {
F_72 ( & F_214 ( V_4 ) -> V_305 ) ;
F_239 ( V_4 , V_257 ) ;
F_240 ( V_4 , V_257 , true ) ;
F_74 ( & F_214 ( V_4 ) -> V_305 ) ;
}
}
static int F_241 ( struct V_5 * V_6 ,
struct V_1 * V_1 , V_133 V_306 , unsigned V_176 ,
T_1 * V_26 , bool * V_109 )
{
struct V_4 * V_4 = V_1 -> V_3 -> V_7 ;
T_3 V_64 = V_1 -> V_64 ;
struct V_101 V_102 ;
struct V_1 * V_131 ;
bool V_307 = false ;
struct V_118 V_119 = { 0 , 0 , 0 } ;
int V_87 = 0 ;
if ( ! F_142 ( V_4 ) && V_176 == V_53 &&
! F_102 ( V_4 , V_152 ) )
return 0 ;
if ( F_142 ( V_4 ) ||
( V_306 & V_308 ) >= F_127 ( V_4 ) ) {
F_143 ( V_6 , V_159 , true ) ;
V_307 = true ;
}
V_309:
V_131 = F_242 ( V_6 , V_4 -> V_8 ) ;
if ( F_123 ( V_131 ) ) {
V_87 = F_192 ( V_131 ) ;
goto V_181;
}
F_118 ( & V_102 , V_4 , V_131 , V_131 , 0 ) ;
if ( F_142 ( V_4 ) ) {
if ( V_306 + V_176 <= V_161 ) {
F_243 ( V_1 , V_131 ) ;
F_150 ( V_4 , V_310 ) ;
if ( V_4 -> V_311 )
F_244 ( V_131 ) ;
} else {
V_87 = F_245 ( & V_102 , V_1 ) ;
if ( V_87 )
goto V_178;
if ( V_102 . V_108 == V_114 )
V_87 = F_110 ( & V_102 , V_64 ) ;
}
} else if ( V_307 ) {
V_87 = F_110 ( & V_102 , V_64 ) ;
} else {
if ( F_111 ( V_4 , V_64 , & V_119 ) ) {
V_102 . V_108 = V_119 . V_120 + V_64 - V_119 . V_121 ;
} else {
V_87 = F_108 ( & V_102 , V_64 , V_127 ) ;
if ( V_87 || V_102 . V_108 == V_114 ) {
F_109 ( & V_102 ) ;
F_143 ( V_6 , V_159 ,
true ) ;
V_307 = true ;
goto V_309;
}
}
}
* V_26 = V_102 . V_108 ;
* V_109 = V_102 . V_109 ;
V_178:
F_109 ( & V_102 ) ;
V_181:
if ( V_307 )
F_143 ( V_6 , V_159 , false ) ;
return V_87 ;
}
static int F_246 ( struct V_239 * V_239 , struct V_2 * V_3 ,
V_133 V_306 , unsigned V_176 , unsigned V_211 ,
struct V_1 * * V_312 , void * * V_313 )
{
struct V_4 * V_4 = V_3 -> V_7 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_1 = NULL ;
T_3 V_64 = ( ( unsigned long long ) V_306 ) >> V_134 ;
bool V_314 = false ;
T_1 V_36 = V_114 ;
int V_87 = 0 ;
F_247 ( V_4 , V_306 , V_176 , V_211 ) ;
if ( V_64 != 0 ) {
V_87 = F_141 ( V_4 ) ;
if ( V_87 )
goto V_315;
}
V_130:
V_1 = F_248 ( V_3 , V_64 ,
V_316 | V_317 | V_318 , V_222 ) ;
if ( ! V_1 ) {
V_87 = - V_125 ;
goto V_315;
}
* V_312 = V_1 ;
V_87 = F_241 ( V_6 , V_1 , V_306 , V_176 ,
& V_36 , & V_314 ) ;
if ( V_87 )
goto V_315;
if ( V_314 && F_212 ( V_6 , 0 , 0 ) ) {
F_20 ( V_1 ) ;
F_151 ( V_6 , true ) ;
F_54 ( V_1 ) ;
if ( V_1 -> V_3 != V_3 ) {
F_120 ( V_1 , 1 ) ;
goto V_130;
}
}
F_97 ( V_1 , V_44 , false ) ;
if ( F_113 ( V_4 ) && F_114 ( V_4 -> V_9 ) )
F_173 ( V_6 , V_36 ) ;
if ( V_176 == V_53 || F_16 ( V_1 ) )
return 0 ;
if ( ! ( V_306 & ( V_53 - 1 ) ) && ( V_306 + V_176 ) >= F_127 ( V_4 ) ) {
F_119 ( V_1 , V_176 , V_53 ) ;
return 0 ;
}
if ( V_36 == V_95 ) {
F_119 ( V_1 , 0 , V_53 ) ;
F_17 ( V_1 ) ;
} else {
struct V_10 * V_10 ;
V_10 = F_170 ( V_4 , V_36 , 1 ) ;
if ( F_123 ( V_10 ) ) {
V_87 = F_192 ( V_10 ) ;
goto V_315;
}
V_10 -> V_319 = V_124 ;
if ( F_55 ( V_10 , V_1 , V_53 , 0 ) < V_53 ) {
F_21 ( V_10 ) ;
V_87 = - V_85 ;
goto V_315;
}
F_45 ( V_6 , V_10 , V_44 ) ;
F_54 ( V_1 ) ;
if ( F_28 ( V_1 -> V_3 != V_3 ) ) {
F_120 ( V_1 , 1 ) ;
goto V_130;
}
if ( F_28 ( ! F_16 ( V_1 ) ) ) {
V_87 = - V_22 ;
goto V_315;
}
}
return 0 ;
V_315:
F_120 ( V_1 , 1 ) ;
F_238 ( V_3 , V_306 + V_176 ) ;
return V_87 ;
}
static int F_249 ( struct V_239 * V_239 ,
struct V_2 * V_3 ,
V_133 V_306 , unsigned V_176 , unsigned V_320 ,
struct V_1 * V_1 , void * V_313 )
{
struct V_4 * V_4 = V_1 -> V_3 -> V_7 ;
F_250 ( V_4 , V_306 , V_176 , V_320 ) ;
if ( ! F_16 ( V_1 ) ) {
if ( F_28 ( V_320 != V_176 ) )
V_320 = 0 ;
else
F_17 ( V_1 ) ;
}
if ( ! V_320 )
goto V_181;
F_98 ( V_1 ) ;
if ( V_306 + V_320 > F_127 ( V_4 ) )
F_128 ( V_4 , V_306 + V_320 ) ;
V_181:
F_120 ( V_1 , 1 ) ;
F_251 ( F_2 ( V_4 ) , V_321 ) ;
return V_320 ;
}
static int F_252 ( struct V_4 * V_4 , struct V_147 * V_322 ,
V_133 V_204 )
{
unsigned V_323 = V_4 -> V_196 -> V_324 - 1 ;
if ( V_204 & V_323 )
return - V_325 ;
if ( F_253 ( V_322 ) & V_323 )
return - V_325 ;
return 0 ;
}
static T_9 F_254 ( struct V_145 * V_146 , struct V_147 * V_322 )
{
struct V_2 * V_3 = V_146 -> V_149 -> V_240 ;
struct V_4 * V_4 = V_3 -> V_7 ;
T_10 V_110 = F_140 ( V_322 ) ;
V_133 V_204 = V_146 -> V_154 ;
int V_142 = F_255 ( V_322 ) ;
int V_87 ;
V_87 = F_252 ( V_4 , V_322 , V_204 ) ;
if ( V_87 )
return V_87 ;
if ( F_135 ( V_4 , V_142 ) )
return 0 ;
F_256 ( V_4 , V_204 , V_110 , V_142 ) ;
F_69 ( & F_214 ( V_4 ) -> V_326 [ V_142 ] ) ;
V_87 = F_257 ( V_146 , V_4 , V_322 , F_156 ) ;
F_70 ( & F_214 ( V_4 ) -> V_326 [ V_142 ] ) ;
if ( V_142 == V_143 ) {
if ( V_87 > 0 )
F_150 ( V_4 , V_251 ) ;
else if ( V_87 < 0 )
F_238 ( V_3 , V_204 + V_110 ) ;
}
F_258 ( V_4 , V_204 , V_110 , V_142 , V_87 ) ;
return V_87 ;
}
void F_259 ( struct V_1 * V_1 , unsigned int V_204 ,
unsigned int V_327 )
{
struct V_4 * V_4 = V_1 -> V_3 -> V_7 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
if ( V_4 -> V_8 >= F_260 ( V_6 ) &&
( V_204 % V_53 || V_327 != V_53 ) )
return;
if ( F_227 ( V_1 ) ) {
if ( V_4 -> V_8 == F_3 ( V_6 ) ) {
F_32 ( V_6 , V_328 ) ;
} else if ( V_4 -> V_8 == F_4 ( V_6 ) ) {
F_32 ( V_6 , V_329 ) ;
} else {
F_215 ( V_4 ) ;
F_217 ( V_4 ) ;
}
}
if ( F_196 ( V_1 ) )
return F_261 ( V_4 , V_1 ) ;
F_25 ( V_1 , 0 ) ;
F_26 ( V_1 ) ;
}
int F_262 ( struct V_1 * V_1 , T_8 V_330 )
{
if ( F_227 ( V_1 ) )
return 0 ;
if ( F_196 ( V_1 ) )
return 0 ;
F_25 ( V_1 , 0 ) ;
F_26 ( V_1 ) ;
return 1 ;
}
void F_263 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_3 ;
unsigned long V_211 ;
if ( F_28 ( ! V_3 ) )
return;
F_84 ( & V_3 -> V_331 ) ;
F_264 ( V_1 ) ;
F_265 ( V_1 ) ;
F_86 ( & V_3 -> V_331 ) ;
F_266 ( & V_3 -> V_332 , V_211 ) ;
F_267 ( ! F_16 ( V_1 ) ) ;
F_268 ( V_1 , V_3 ) ;
F_269 ( & V_3 -> V_333 ,
F_270 ( V_1 ) , V_289 ) ;
F_271 ( & V_3 -> V_332 , V_211 ) ;
F_272 ( V_1 ) ;
F_273 ( V_3 -> V_7 , V_334 ) ;
return;
}
static int F_274 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_3 ;
struct V_4 * V_4 = V_3 -> V_7 ;
F_275 ( V_1 , V_44 ) ;
if ( ! F_16 ( V_1 ) )
F_17 ( V_1 ) ;
if ( F_195 ( V_4 ) && ! F_276 ( V_4 ) ) {
if ( ! F_196 ( V_1 ) ) {
F_277 ( V_4 , V_1 ) ;
return 1 ;
}
return 0 ;
}
if ( ! F_227 ( V_1 ) ) {
F_263 ( V_1 ) ;
F_278 ( V_4 , V_1 ) ;
return 1 ;
}
return 0 ;
}
static T_6 F_279 ( struct V_2 * V_3 , T_6 V_335 )
{
struct V_4 * V_4 = V_3 -> V_7 ;
if ( F_142 ( V_4 ) )
return 0 ;
if ( F_280 ( V_3 , V_289 ) )
F_281 ( V_3 ) ;
return F_282 ( V_3 , V_335 , F_157 ) ;
}
int F_283 ( struct V_2 * V_3 ,
struct V_1 * V_336 , struct V_1 * V_1 , enum V_337 V_167 )
{
int V_338 , V_339 ;
struct V_340 * V_341 = F_214 ( V_3 -> V_7 ) ;
bool V_342 = F_196 ( V_1 ) ;
F_184 ( F_228 ( V_1 ) ) ;
if ( V_342 ) {
if ( V_167 != V_343 )
return - V_344 ;
if ( ! F_284 ( & V_341 -> V_345 ) )
return - V_99 ;
}
V_339 = ( V_342 ? 1 : 0 ) - F_285 ( V_1 ) ;
V_338 = F_286 ( V_3 , V_336 ,
V_1 , NULL , V_167 , V_339 ) ;
if ( V_338 != V_346 ) {
if ( V_342 )
F_287 ( & V_341 -> V_345 ) ;
return V_338 ;
}
if ( V_342 ) {
struct V_347 * V_348 ;
F_288 (cur, &fi->inmem_pages, list)
if ( V_348 -> V_1 == V_1 ) {
V_348 -> V_1 = V_336 ;
break;
}
F_287 ( & V_341 -> V_345 ) ;
F_183 ( V_1 ) ;
F_289 ( V_336 ) ;
}
if ( F_290 ( V_1 ) )
F_53 ( V_336 ) ;
F_25 ( V_336 , F_291 ( V_1 ) ) ;
F_292 ( V_336 , V_1 ) ;
return V_346 ;
}
