static long F_1 ( struct V_1 * V_1 , unsigned int V_2 , unsigned long V_3 )
{
long V_4 = - V_5 ;
if ( V_1 -> V_6 -> V_7 )
V_4 = V_1 -> V_6 -> V_7 ( V_1 , V_2 , V_3 ) ;
return V_4 ;
}
static int F_2 ( struct V_8 * V_9 , struct V_10 T_1 * V_11 )
{
if ( ! F_3 ( V_12 , V_11 , sizeof( struct V_10 ) ) ||
F_4 ( & V_9 -> V_13 , & V_11 -> V_13 , sizeof( V_11 -> V_13 ) ) ||
F_5 ( V_9 -> V_14 , & V_11 -> V_14 ) ||
F_5 ( V_9 -> V_15 , & V_11 -> V_15 ) ||
F_5 ( V_9 -> V_16 , & V_11 -> V_16 ) )
return - V_17 ;
if ( V_9 -> V_16 > 2048 )
return - V_18 ;
if ( V_9 -> V_16 ) {
struct V_19 T_1 * V_20 ;
struct V_21 T_1 * V_22 ;
int V_23 = V_9 -> V_16 ;
T_2 V_24 ;
if ( F_5 ( V_24 , & V_11 -> V_25 ) )
return - V_17 ;
V_20 = F_6 ( V_24 ) ;
V_22 = F_7 ( V_23 * sizeof( struct V_21 ) ) ;
V_9 -> V_25 = V_22 ;
while ( -- V_23 >= 0 ) {
if ( F_8 ( & V_22 -> V_26 , & V_20 -> V_26 , sizeof( V_20 -> V_26 ) ) )
return - V_17 ;
if ( F_9 ( V_23 ? V_22 + 1 : NULL , & V_22 -> V_27 ) )
return - V_17 ;
V_20 += 1 ;
V_22 += 1 ;
}
} else
V_9 -> V_25 = NULL ;
return 0 ;
}
static int F_10 ( struct V_8 * V_9 , struct V_10 T_1 * V_11 )
{
if ( F_11 ( & V_11 -> V_13 , & V_9 -> V_13 , sizeof( V_9 -> V_13 ) ) ||
F_9 ( V_9 -> V_14 , & V_11 -> V_14 ) ||
F_9 ( V_9 -> V_15 , & V_11 -> V_15 ) ||
F_9 ( V_9 -> V_16 , & V_11 -> V_16 ) )
return - V_17 ;
return 0 ;
}
static inline int F_12 ( struct V_28 * V_9 , struct V_28 T_1 * V_11 )
{
if ( F_4 ( V_9 , V_11 , sizeof( struct V_28 ) ) )
return - V_17 ;
return 0 ;
}
static inline int F_13 ( struct V_29 * V_9 ,
struct V_29 T_1 * V_11 )
{
if ( F_4 ( V_9 , V_11 , sizeof( struct V_29 ) ) )
return - V_17 ;
return 0 ;
}
static inline int F_14 ( struct V_28 * V_9 , struct V_28 T_1 * V_11 )
{
if ( F_11 ( V_11 , V_9 , sizeof( struct V_28 ) ) )
return - V_17 ;
return 0 ;
}
static inline int F_15 ( struct V_29 * V_9 ,
struct V_29 T_1 * V_11 )
{
if ( F_11 ( V_11 , V_9 , sizeof( struct V_29 ) ) )
return - V_17 ;
return 0 ;
}
static inline int F_16 ( struct V_30 * V_9 , struct V_30 T_1 * V_11 )
{
if ( F_4 ( V_9 , V_11 , sizeof( struct V_30 ) ) )
return - V_17 ;
return 0 ;
}
static inline int F_17 ( struct V_30 * V_9 , struct V_30 T_1 * V_11 )
{
if ( F_11 ( V_11 , V_9 , sizeof( struct V_30 ) ) )
return - V_17 ;
return 0 ;
}
static inline int F_18 ( struct V_31 * V_9 , struct V_31 T_1 * V_11 )
{
if ( F_4 ( V_9 , V_11 , sizeof( struct V_31 ) ) )
return - V_17 ;
return 0 ;
}
static inline int F_19 ( struct V_31 * V_9 , struct V_31 T_1 * V_11 )
{
if ( F_11 ( V_11 , V_9 , sizeof( struct V_31 ) ) )
return - V_17 ;
return 0 ;
}
static int F_20 ( struct V_32 * V_9 , struct V_33 T_1 * V_11 )
{
switch ( V_9 -> type ) {
case V_34 :
case V_35 :
return F_12 ( & V_9 -> V_36 . V_37 , & V_11 -> V_36 . V_37 ) ;
case V_38 :
case V_39 :
return F_13 ( & V_9 -> V_36 . V_40 ,
& V_11 -> V_36 . V_40 ) ;
case V_41 :
case V_42 :
return F_2 ( & V_9 -> V_36 . V_43 , & V_11 -> V_36 . V_43 ) ;
case V_44 :
case V_45 :
return F_16 ( & V_9 -> V_36 . V_46 , & V_11 -> V_36 . V_46 ) ;
case V_47 :
case V_48 :
return F_18 ( & V_9 -> V_36 . V_49 , & V_11 -> V_36 . V_49 ) ;
case V_50 :
if ( F_4 ( V_9 , V_11 , sizeof( V_9 -> V_36 . V_51 ) ) )
return - V_17 ;
return 0 ;
default:
F_21 ( V_52 L_1 ,
V_9 -> type ) ;
return - V_18 ;
}
}
static int F_22 ( struct V_32 * V_9 , struct V_33 T_1 * V_11 )
{
if ( ! F_3 ( V_12 , V_11 , sizeof( struct V_33 ) ) ||
F_5 ( V_9 -> type , & V_11 -> type ) )
return - V_17 ;
return F_20 ( V_9 , V_11 ) ;
}
static int F_23 ( struct V_53 * V_9 , struct V_54 T_1 * V_11 )
{
if ( ! F_3 ( V_12 , V_11 , sizeof( struct V_54 ) ) ||
F_4 ( V_9 , V_11 , F_24 ( struct V_54 , V_55 . V_36 ) ) )
return - V_17 ;
return F_20 ( & V_9 -> V_55 , & V_11 -> V_55 ) ;
}
static int F_25 ( struct V_32 * V_9 , struct V_33 T_1 * V_11 )
{
switch ( V_9 -> type ) {
case V_34 :
case V_35 :
return F_14 ( & V_9 -> V_36 . V_37 , & V_11 -> V_36 . V_37 ) ;
case V_38 :
case V_39 :
return F_15 ( & V_9 -> V_36 . V_40 ,
& V_11 -> V_36 . V_40 ) ;
case V_41 :
case V_42 :
return F_10 ( & V_9 -> V_36 . V_43 , & V_11 -> V_36 . V_43 ) ;
case V_44 :
case V_45 :
return F_17 ( & V_9 -> V_36 . V_46 , & V_11 -> V_36 . V_46 ) ;
case V_47 :
case V_48 :
return F_19 ( & V_9 -> V_36 . V_49 , & V_11 -> V_36 . V_49 ) ;
case V_50 :
if ( F_11 ( V_11 , V_9 , sizeof( V_11 -> V_36 . V_51 ) ) )
return - V_17 ;
return 0 ;
default:
F_21 ( V_52 L_1 ,
V_9 -> type ) ;
return - V_18 ;
}
}
static int F_26 ( struct V_32 * V_9 , struct V_33 T_1 * V_11 )
{
if ( ! F_3 ( V_56 , V_11 , sizeof( struct V_33 ) ) ||
F_9 ( V_9 -> type , & V_11 -> type ) )
return - V_17 ;
return F_25 ( V_9 , V_11 ) ;
}
static int F_27 ( struct V_53 * V_9 , struct V_54 T_1 * V_11 )
{
if ( ! F_3 ( V_56 , V_11 , sizeof( struct V_54 ) ) ||
F_11 ( V_11 , V_9 , F_24 ( struct V_54 , V_55 . V_36 ) ) )
return - V_17 ;
return F_25 ( & V_9 -> V_55 , & V_11 -> V_55 ) ;
}
static int F_28 ( struct V_57 * V_9 , struct V_58 T_1 * V_11 )
{
if ( ! F_3 ( V_12 , V_11 , sizeof( struct V_58 ) ) ||
F_5 ( V_9 -> V_59 , & V_11 -> V_59 ) )
return - V_17 ;
return 0 ;
}
static int F_29 ( struct V_57 * V_9 , struct V_58 T_1 * V_11 )
{
if ( ! F_3 ( V_56 , V_11 , sizeof( struct V_58 ) ) ||
F_9 ( V_9 -> V_59 , & V_11 -> V_59 ) ||
F_11 ( V_11 -> V_60 , & V_9 -> V_60 , sizeof( V_61 ) ) ||
F_11 ( V_11 -> V_62 , V_9 -> V_62 , 24 ) ||
F_11 ( & V_11 -> V_63 , & V_9 -> V_63 , sizeof( V_9 -> V_63 ) ) ||
F_9 ( V_9 -> V_64 , & V_11 -> V_64 ) ||
F_11 ( V_11 -> V_65 , V_9 -> V_65 , 4 * sizeof( V_66 ) ) )
return - V_17 ;
return 0 ;
}
static int F_30 ( struct V_67 * V_11 , struct V_68 * V_69 ,
enum V_70 V_71 )
{
void T_1 * V_72 ;
T_3 V_24 ;
if ( F_8 ( V_11 , V_69 , 2 * sizeof( V_66 ) ) ||
F_8 ( & V_11 -> V_73 , & V_69 -> V_73 ,
sizeof( V_66 ) ) )
return - V_17 ;
if ( V_71 == V_74 ) {
if ( F_5 ( V_24 , & V_69 -> V_75 . V_76 ) )
return - V_17 ;
V_72 = F_6 ( V_24 ) ;
if ( F_9 ( ( unsigned long ) V_72 , & V_11 -> V_75 . V_76 ) )
return - V_17 ;
} else {
if ( F_8 ( & V_11 -> V_75 . V_77 , & V_69 -> V_75 . V_77 ,
sizeof( V_66 ) ) )
return - V_17 ;
}
return 0 ;
}
static int F_31 ( struct V_67 * V_11 , struct V_68 * V_69 ,
enum V_70 V_71 )
{
if ( F_8 ( V_69 , V_11 , 2 * sizeof( V_66 ) ) ||
F_8 ( & V_69 -> V_73 , & V_11 -> V_73 ,
sizeof( V_66 ) ) )
return - V_17 ;
if ( V_71 == V_78 )
if ( F_8 ( & V_69 -> V_75 . V_77 , & V_11 -> V_75 . V_77 ,
sizeof( V_66 ) ) )
return - V_17 ;
return 0 ;
}
static int F_32 ( struct V_79 * V_9 , struct V_80 T_1 * V_11 )
{
struct V_68 T_1 * V_81 ;
struct V_67 T_1 * V_82 ;
T_2 V_24 ;
int V_83 ;
int V_4 ;
if ( ! F_3 ( V_12 , V_11 , sizeof( struct V_80 ) ) ||
F_5 ( V_9 -> V_59 , & V_11 -> V_59 ) ||
F_5 ( V_9 -> type , & V_11 -> type ) ||
F_5 ( V_9 -> V_84 , & V_11 -> V_84 ) ||
F_5 ( V_9 -> V_71 , & V_11 -> V_71 ) ||
F_5 ( V_9 -> V_85 , & V_11 -> V_85 ) )
return - V_17 ;
if ( F_33 ( V_9 -> type ) )
if ( F_5 ( V_9 -> V_86 , & V_11 -> V_86 ) ||
F_5 ( V_9 -> V_14 , & V_11 -> V_14 ) ||
F_5 ( V_9 -> V_87 . V_88 , & V_11 -> V_87 . V_88 ) ||
F_5 ( V_9 -> V_87 . V_89 ,
& V_11 -> V_87 . V_89 ) )
return - V_17 ;
if ( F_34 ( V_9 -> type ) ) {
if ( F_5 ( V_9 -> V_90 , & V_11 -> V_90 ) )
return - V_17 ;
V_83 = V_9 -> V_90 ;
if ( V_83 == 0 ) {
V_9 -> V_75 . V_91 = NULL ;
return 0 ;
}
if ( F_5 ( V_24 , & V_11 -> V_75 . V_91 ) )
return - V_17 ;
V_81 = F_6 ( V_24 ) ;
if ( ! F_3 ( V_12 , V_81 ,
V_83 * sizeof( struct V_68 ) ) )
return - V_17 ;
V_82 = F_7 ( V_83 *
sizeof( struct V_67 ) ) ;
V_9 -> V_75 . V_91 = V_82 ;
while ( -- V_83 >= 0 ) {
V_4 = F_30 ( V_82 , V_81 , V_9 -> V_71 ) ;
if ( V_4 )
return V_4 ;
++ V_82 ;
++ V_81 ;
}
} else {
switch ( V_9 -> V_71 ) {
case V_78 :
if ( F_5 ( V_9 -> V_90 , & V_11 -> V_90 ) ||
F_5 ( V_9 -> V_75 . V_92 , & V_11 -> V_75 . V_92 ) )
return - V_17 ;
break;
case V_74 :
{
T_3 V_93 ;
if ( F_5 ( V_9 -> V_90 , & V_11 -> V_90 ) ||
F_5 ( V_93 , & V_11 -> V_75 . V_76 ) )
return - V_17 ;
V_9 -> V_75 . V_76 = ( unsigned long ) F_6 ( V_93 ) ;
}
break;
case V_94 :
if ( F_5 ( V_9 -> V_75 . V_92 , & V_11 -> V_75 . V_92 ) )
return - V_17 ;
break;
}
}
return 0 ;
}
static int F_35 ( struct V_79 * V_9 , struct V_80 T_1 * V_11 )
{
struct V_68 T_1 * V_81 ;
struct V_67 T_1 * V_82 ;
T_2 V_24 ;
int V_83 ;
int V_4 ;
if ( ! F_3 ( V_56 , V_11 , sizeof( struct V_80 ) ) ||
F_9 ( V_9 -> V_59 , & V_11 -> V_59 ) ||
F_9 ( V_9 -> type , & V_11 -> type ) ||
F_9 ( V_9 -> V_84 , & V_11 -> V_84 ) ||
F_9 ( V_9 -> V_71 , & V_11 -> V_71 ) ||
F_9 ( V_9 -> V_85 , & V_11 -> V_85 ) )
return - V_17 ;
if ( F_9 ( V_9 -> V_86 , & V_11 -> V_86 ) ||
F_9 ( V_9 -> V_14 , & V_11 -> V_14 ) ||
F_9 ( V_9 -> V_87 . V_88 , & V_11 -> V_87 . V_88 ) ||
F_9 ( V_9 -> V_87 . V_89 , & V_11 -> V_87 . V_89 ) ||
F_11 ( & V_11 -> V_95 , & V_9 -> V_95 , sizeof( struct V_96 ) ) ||
F_9 ( V_9 -> V_97 , & V_11 -> V_97 ) ||
F_9 ( V_9 -> V_65 , & V_11 -> V_65 ) )
return - V_17 ;
if ( F_34 ( V_9 -> type ) ) {
V_83 = V_9 -> V_90 ;
if ( V_83 == 0 )
return 0 ;
V_82 = V_9 -> V_75 . V_91 ;
if ( F_5 ( V_24 , & V_11 -> V_75 . V_91 ) )
return - V_17 ;
V_81 = F_6 ( V_24 ) ;
while ( -- V_83 >= 0 ) {
V_4 = F_31 ( V_82 , V_81 , V_9 -> V_71 ) ;
if ( V_4 )
return V_4 ;
++ V_82 ;
++ V_81 ;
}
} else {
switch ( V_9 -> V_71 ) {
case V_78 :
if ( F_9 ( V_9 -> V_90 , & V_11 -> V_90 ) ||
F_9 ( V_9 -> V_75 . V_92 , & V_11 -> V_75 . V_92 ) )
return - V_17 ;
break;
case V_74 :
if ( F_9 ( V_9 -> V_90 , & V_11 -> V_90 ) ||
F_9 ( V_9 -> V_75 . V_76 , & V_11 -> V_75 . V_76 ) )
return - V_17 ;
break;
case V_94 :
if ( F_9 ( V_9 -> V_75 . V_92 , & V_11 -> V_75 . V_92 ) )
return - V_17 ;
break;
}
}
return 0 ;
}
static int F_36 ( struct V_98 * V_9 , struct V_99 T_1 * V_11 )
{
T_4 V_93 ;
if ( ! F_3 ( V_12 , V_11 , sizeof( struct V_99 ) ) ||
F_5 ( V_93 , & V_11 -> V_100 ) ||
F_5 ( V_9 -> V_101 , & V_11 -> V_101 ) ||
F_5 ( V_9 -> V_84 , & V_11 -> V_84 ) )
return - V_17 ;
V_9 -> V_100 = F_6 ( V_93 ) ;
F_12 ( & V_9 -> V_36 , & V_11 -> V_36 ) ;
return 0 ;
}
static int F_37 ( struct V_98 * V_9 , struct V_99 T_1 * V_11 )
{
T_4 V_93 = ( T_4 ) ( ( unsigned long ) V_9 -> V_100 ) ;
if ( ! F_3 ( V_56 , V_11 , sizeof( struct V_99 ) ) ||
F_9 ( V_93 , & V_11 -> V_100 ) ||
F_9 ( V_9 -> V_101 , & V_11 -> V_101 ) ||
F_9 ( V_9 -> V_84 , & V_11 -> V_84 ) )
return - V_17 ;
F_14 ( & V_9 -> V_36 , & V_11 -> V_36 ) ;
return 0 ;
}
static inline int F_38 ( struct V_102 * V_9 , struct V_103 T_1 * V_11 )
{
if ( F_4 ( V_9 , V_11 , sizeof( struct V_103 ) ) )
return - V_17 ;
return 0 ;
}
static inline int F_39 ( struct V_102 * V_9 , struct V_103 T_1 * V_11 )
{
if ( F_11 ( V_11 , V_9 , sizeof( struct V_103 ) ) )
return - V_17 ;
return 0 ;
}
static inline int F_40 ( T_4 V_60 )
{
switch ( V_60 ) {
case V_104 :
case V_105 :
return 1 ;
default:
return 0 ;
}
}
static int F_41 ( struct V_106 * V_9 , struct V_107 T_1 * V_11 )
{
struct V_108 T_1 * V_109 ;
struct V_110 T_1 * V_111 ;
int V_23 ;
T_2 V_24 ;
if ( ! F_3 ( V_12 , V_11 , sizeof( struct V_107 ) ) ||
F_5 ( V_9 -> V_112 , & V_11 -> V_112 ) ||
F_5 ( V_9 -> V_113 , & V_11 -> V_113 ) ||
F_5 ( V_9 -> V_114 , & V_11 -> V_114 ) ||
F_4 ( V_9 -> V_65 , V_11 -> V_65 , sizeof( V_9 -> V_65 ) ) )
return - V_17 ;
V_23 = V_9 -> V_113 ;
if ( V_23 == 0 ) {
V_9 -> V_115 = NULL ;
return 0 ;
}
if ( F_5 ( V_24 , & V_11 -> V_115 ) )
return - V_17 ;
V_109 = F_6 ( V_24 ) ;
if ( ! F_3 ( V_12 , V_109 ,
V_23 * sizeof( struct V_108 ) ) )
return - V_17 ;
V_111 = F_7 ( V_23 * sizeof( struct V_110 ) ) ;
V_9 -> V_115 = V_111 ;
while ( -- V_23 >= 0 ) {
if ( F_8 ( V_111 , V_109 , sizeof( * V_109 ) ) )
return - V_17 ;
if ( F_40 ( V_111 -> V_60 ) ) {
void T_1 * V_116 ;
if ( F_5 ( V_24 , & V_109 -> string ) )
return - V_17 ;
V_116 = F_6 ( V_24 ) ;
if ( F_9 ( V_116 , & V_111 -> string ) )
return - V_17 ;
}
V_109 ++ ;
V_111 ++ ;
}
return 0 ;
}
static int F_42 ( struct V_106 * V_9 , struct V_107 T_1 * V_11 )
{
struct V_108 T_1 * V_109 ;
struct V_110 T_1 * V_111 = V_9 -> V_115 ;
int V_23 = V_9 -> V_113 ;
T_2 V_24 ;
if ( ! F_3 ( V_56 , V_11 , sizeof( struct V_107 ) ) ||
F_9 ( V_9 -> V_112 , & V_11 -> V_112 ) ||
F_9 ( V_9 -> V_113 , & V_11 -> V_113 ) ||
F_9 ( V_9 -> V_114 , & V_11 -> V_114 ) ||
F_11 ( V_11 -> V_65 , V_9 -> V_65 , sizeof( V_11 -> V_65 ) ) )
return - V_17 ;
if ( ! V_9 -> V_113 )
return 0 ;
if ( F_5 ( V_24 , & V_11 -> V_115 ) )
return - V_17 ;
V_109 = F_6 ( V_24 ) ;
if ( ! F_3 ( V_56 , V_109 ,
V_23 * sizeof( struct V_108 ) ) )
return - V_17 ;
while ( -- V_23 >= 0 ) {
unsigned V_117 = sizeof( * V_109 ) ;
if ( F_40 ( V_111 -> V_60 ) )
V_117 -= sizeof( V_109 -> V_118 ) ;
if ( F_8 ( V_109 , V_111 , V_117 ) )
return - V_17 ;
V_109 ++ ;
V_111 ++ ;
}
return 0 ;
}
static int F_43 ( struct V_119 * V_9 , struct V_120 T_1 * V_11 )
{
if ( ! F_3 ( V_56 , V_11 , sizeof( struct V_120 ) ) ||
F_9 ( V_9 -> type , & V_11 -> type ) ||
F_11 ( & V_11 -> V_121 , & V_9 -> V_121 , sizeof( V_9 -> V_121 ) ) ||
F_9 ( V_9 -> V_122 , & V_11 -> V_122 ) ||
F_9 ( V_9 -> V_97 , & V_11 -> V_97 ) ||
F_44 ( & V_9 -> V_87 , & V_11 -> V_87 ) ||
F_9 ( V_9 -> V_60 , & V_11 -> V_60 ) ||
F_11 ( V_11 -> V_65 , V_9 -> V_65 , 8 * sizeof( V_66 ) ) )
return - V_17 ;
return 0 ;
}
static long F_45 ( struct V_1 * V_1 , unsigned int V_2 , unsigned long V_3 )
{
union {
struct V_32 V_123 ;
struct V_79 V_124 ;
struct V_98 V_125 ;
struct V_102 V_126 ;
struct V_57 V_127 ;
struct V_106 V_128 ;
struct V_119 V_129 ;
struct V_53 V_130 ;
unsigned long V_131 ;
int V_132 ;
} V_133 ;
void T_1 * V_11 = F_6 ( V_3 ) ;
int V_134 = 1 ;
long V_135 = 0 ;
switch ( V_2 ) {
case V_136 : V_2 = V_137 ; break;
case V_138 : V_2 = V_139 ; break;
case V_140 : V_2 = V_141 ; break;
case V_142 : V_2 = V_143 ; break;
case V_144 : V_2 = V_145 ; break;
case V_146 : V_2 = V_147 ; break;
case V_148 : V_2 = V_149 ; break;
case V_150 : V_2 = V_151 ; break;
case V_152 : V_2 = V_153 ; break;
case V_154 : V_2 = V_155 ; break;
case V_156 : V_2 = V_157 ; break;
case V_158 : V_2 = V_159 ; break;
case V_160 : V_2 = V_161 ; break;
case V_162 : V_2 = V_163 ; break;
case V_164 : V_2 = V_165 ; break;
case V_166 : V_2 = V_167 ; break;
case V_168 : V_2 = V_169 ; break;
case V_170 : V_2 = V_171 ; break;
case V_172 : V_2 = V_173 ; break;
case V_174 : V_2 = V_175 ; break;
case V_176 : V_2 = V_177 ; break;
case V_178 : V_2 = V_179 ; break;
case V_180 : V_2 = V_181 ; break;
}
switch ( V_2 ) {
case V_165 :
case V_167 :
case V_169 :
case V_173 :
case V_177 :
V_135 = F_5 ( V_133 . V_132 , ( V_182 T_1 * ) V_11 ) ;
V_134 = 0 ;
break;
case V_171 :
case V_175 :
V_134 = 0 ;
break;
case V_137 :
case V_139 :
case V_155 :
V_135 = F_22 ( & V_133 . V_123 , V_11 ) ;
V_134 = 0 ;
break;
case V_179 :
V_135 = F_23 ( & V_133 . V_130 , V_11 ) ;
V_134 = 0 ;
break;
case V_181 :
case V_141 :
case V_147 :
case V_149 :
V_135 = F_32 ( & V_133 . V_124 , V_11 ) ;
V_134 = 0 ;
break;
case V_145 :
V_135 = F_36 ( & V_133 . V_125 , V_11 ) ;
V_134 = 0 ;
break;
case V_143 :
V_134 = 0 ;
break;
case V_151 :
V_135 = F_28 ( & V_133 . V_127 , V_11 ) ;
V_134 = 0 ;
break;
case V_153 :
V_135 = F_38 ( & V_133 . V_126 , V_11 ) ;
V_134 = 0 ;
break;
case V_157 :
case V_159 :
case V_161 :
V_135 = F_41 ( & V_133 . V_128 , V_11 ) ;
V_134 = 0 ;
break;
case V_163 :
V_134 = 0 ;
break;
}
if ( V_135 )
return V_135 ;
if ( V_134 )
V_135 = F_1 ( V_1 , V_2 , ( unsigned long ) V_11 ) ;
else {
T_5 V_183 = F_46 () ;
F_47 ( V_184 ) ;
V_135 = F_1 ( V_1 , V_2 , ( unsigned long ) & V_133 ) ;
F_47 ( V_183 ) ;
}
switch ( V_2 ) {
case V_157 :
case V_159 :
case V_161 :
if ( F_42 ( & V_133 . V_128 , V_11 ) )
V_135 = - V_17 ;
break;
}
if ( V_135 )
return V_135 ;
switch ( V_2 ) {
case V_173 :
case V_177 :
case V_171 :
case V_175 :
V_135 = F_9 ( ( ( V_182 ) V_133 . V_132 ) , ( V_182 T_1 * ) V_11 ) ;
break;
case V_143 :
V_135 = F_37 ( & V_133 . V_125 , V_11 ) ;
break;
case V_163 :
V_135 = F_43 ( & V_133 . V_129 , V_11 ) ;
break;
case V_137 :
case V_139 :
case V_155 :
V_135 = F_26 ( & V_133 . V_123 , V_11 ) ;
break;
case V_179 :
V_135 = F_27 ( & V_133 . V_130 , V_11 ) ;
break;
case V_141 :
case V_147 :
case V_149 :
V_135 = F_35 ( & V_133 . V_124 , V_11 ) ;
break;
case V_151 :
V_135 = F_29 ( & V_133 . V_127 , V_11 ) ;
break;
case V_153 :
V_135 = F_39 ( & V_133 . V_126 , V_11 ) ;
break;
}
return V_135 ;
}
long F_48 ( struct V_1 * V_1 , unsigned int V_2 , unsigned long V_3 )
{
long V_4 = - V_5 ;
if ( ! V_1 -> V_6 -> V_7 )
return V_4 ;
switch ( V_2 ) {
case V_185 :
case V_186 :
case V_187 :
case V_136 :
case V_138 :
case V_188 :
case V_140 :
case V_142 :
case V_144 :
case V_164 :
case V_146 :
case V_148 :
case V_166 :
case V_168 :
case V_189 :
case V_190 :
case V_191 :
case V_192 :
case V_150 :
case V_152 :
case V_193 :
case V_194 :
case V_195 :
case V_196 :
case V_197 :
case V_198 :
case V_199 :
case V_200 :
case V_170 :
case V_172 :
case V_174 :
case V_176 :
case V_201 :
case V_202 :
case V_203 :
case V_204 :
case V_205 :
case V_206 :
case V_207 :
case V_208 :
case V_209 :
case V_210 :
case V_211 :
case V_212 :
case V_213 :
case V_214 :
case V_215 :
case V_154 :
case V_216 :
case V_217 :
case V_218 :
case V_219 :
case V_220 :
case V_221 :
case V_156 :
case V_158 :
case V_160 :
case V_222 :
case V_223 :
case V_224 :
case V_225 :
case V_226 :
case V_227 :
case V_228 :
case V_229 :
case V_230 :
case V_231 :
case V_232 :
case V_233 :
case V_234 :
case V_235 :
case V_236 :
case V_163 :
case V_162 :
case V_237 :
case V_238 :
case V_178 :
case V_180 :
V_4 = F_45 ( V_1 , V_2 , V_3 ) ;
break;
default:
F_21 ( V_239 L_2
L_3 ,
F_49 ( V_2 ) , F_50 ( V_2 ) , F_51 ( V_2 ) , V_2 ) ;
break;
}
return V_4 ;
}
