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
static inline int F_20 ( struct V_32 * V_9 , struct V_32 T_1 * V_11 )
{
if ( F_4 ( V_9 , V_11 , sizeof( struct V_32 ) ) )
return - V_17 ;
return 0 ;
}
static inline int F_21 ( struct V_32 * V_9 , struct V_32 T_1 * V_11 )
{
if ( F_11 ( V_11 , V_9 , sizeof( struct V_32 ) ) )
return - V_17 ;
return 0 ;
}
static inline int F_22 ( struct V_33 * V_9 , struct V_33 T_1 * V_11 )
{
if ( F_4 ( V_9 , V_11 , sizeof( struct V_33 ) ) )
return - V_17 ;
return 0 ;
}
static inline int F_23 ( struct V_33 * V_9 , struct V_33 T_1 * V_11 )
{
if ( F_11 ( V_11 , V_9 , sizeof( struct V_33 ) ) )
return - V_17 ;
return 0 ;
}
static int F_24 ( struct V_34 * V_9 , struct V_35 T_1 * V_11 )
{
if ( F_5 ( V_9 -> type , & V_11 -> type ) )
return - V_17 ;
switch ( V_9 -> type ) {
case V_36 :
case V_37 :
return F_12 ( & V_9 -> V_38 . V_39 , & V_11 -> V_38 . V_39 ) ;
case V_40 :
case V_41 :
return F_13 ( & V_9 -> V_38 . V_42 ,
& V_11 -> V_38 . V_42 ) ;
case V_43 :
case V_44 :
return F_2 ( & V_9 -> V_38 . V_45 , & V_11 -> V_38 . V_45 ) ;
case V_46 :
case V_47 :
return F_16 ( & V_9 -> V_38 . V_48 , & V_11 -> V_38 . V_48 ) ;
case V_49 :
case V_50 :
return F_18 ( & V_9 -> V_38 . V_51 , & V_11 -> V_38 . V_51 ) ;
case V_52 :
case V_53 :
return F_20 ( & V_9 -> V_38 . V_54 , & V_11 -> V_38 . V_54 ) ;
case V_55 :
return F_22 ( & V_9 -> V_38 . V_56 , & V_11 -> V_38 . V_56 ) ;
default:
F_25 ( L_1 ,
V_9 -> type ) ;
return - V_18 ;
}
}
static int F_26 ( struct V_34 * V_9 , struct V_35 T_1 * V_11 )
{
if ( ! F_3 ( V_12 , V_11 , sizeof( struct V_35 ) ) )
return - V_17 ;
return F_24 ( V_9 , V_11 ) ;
}
static int F_27 ( struct V_57 * V_9 , struct V_58 T_1 * V_11 )
{
if ( ! F_3 ( V_12 , V_11 , sizeof( struct V_58 ) ) ||
F_4 ( V_9 , V_11 , F_28 ( struct V_58 , V_59 ) ) )
return - V_17 ;
return F_24 ( & V_9 -> V_59 , & V_11 -> V_59 ) ;
}
static int F_29 ( struct V_34 * V_9 , struct V_35 T_1 * V_11 )
{
if ( F_9 ( V_9 -> type , & V_11 -> type ) )
return - V_17 ;
switch ( V_9 -> type ) {
case V_36 :
case V_37 :
return F_14 ( & V_9 -> V_38 . V_39 , & V_11 -> V_38 . V_39 ) ;
case V_40 :
case V_41 :
return F_15 ( & V_9 -> V_38 . V_42 ,
& V_11 -> V_38 . V_42 ) ;
case V_43 :
case V_44 :
return F_10 ( & V_9 -> V_38 . V_45 , & V_11 -> V_38 . V_45 ) ;
case V_46 :
case V_47 :
return F_17 ( & V_9 -> V_38 . V_48 , & V_11 -> V_38 . V_48 ) ;
case V_49 :
case V_50 :
return F_19 ( & V_9 -> V_38 . V_51 , & V_11 -> V_38 . V_51 ) ;
case V_52 :
case V_53 :
return F_21 ( & V_9 -> V_38 . V_54 , & V_11 -> V_38 . V_54 ) ;
case V_55 :
return F_23 ( & V_9 -> V_38 . V_56 , & V_11 -> V_38 . V_56 ) ;
default:
F_25 ( L_1 ,
V_9 -> type ) ;
return - V_18 ;
}
}
static int F_30 ( struct V_34 * V_9 , struct V_35 T_1 * V_11 )
{
if ( ! F_3 ( V_60 , V_11 , sizeof( struct V_35 ) ) )
return - V_17 ;
return F_29 ( V_9 , V_11 ) ;
}
static int F_31 ( struct V_57 * V_9 , struct V_58 T_1 * V_11 )
{
if ( ! F_3 ( V_60 , V_11 , sizeof( struct V_58 ) ) ||
F_11 ( V_11 , V_9 , F_28 ( struct V_58 , V_59 ) ) ||
F_11 ( V_11 -> V_61 , V_9 -> V_61 , sizeof( V_9 -> V_61 ) ) )
return - V_17 ;
return F_29 ( & V_9 -> V_59 , & V_11 -> V_59 ) ;
}
static int F_32 ( struct V_62 * V_9 , struct V_63 T_1 * V_11 )
{
if ( ! F_3 ( V_12 , V_11 , sizeof( struct V_63 ) ) ||
F_5 ( V_9 -> V_64 , & V_11 -> V_64 ) )
return - V_17 ;
return 0 ;
}
static int F_33 ( struct V_62 * V_9 , struct V_63 T_1 * V_11 )
{
if ( ! F_3 ( V_60 , V_11 , sizeof( struct V_63 ) ) ||
F_9 ( V_9 -> V_64 , & V_11 -> V_64 ) ||
F_9 ( V_9 -> V_65 , & V_11 -> V_65 ) ||
F_11 ( V_11 -> V_66 , V_9 -> V_66 , 24 ) ||
F_11 ( & V_11 -> V_67 , & V_9 -> V_67 , sizeof( V_9 -> V_67 ) ) ||
F_9 ( V_9 -> V_68 , & V_11 -> V_68 ) ||
F_11 ( V_11 -> V_61 , V_9 -> V_61 , 4 * sizeof( V_69 ) ) )
return - V_17 ;
return 0 ;
}
static int F_34 ( struct V_70 T_1 * V_11 , struct V_71 T_1 * V_72 ,
enum V_73 V_74 )
{
void T_1 * V_75 ;
T_3 V_24 ;
if ( F_8 ( V_11 , V_72 , 2 * sizeof( V_69 ) ) ||
F_8 ( & V_11 -> V_76 , & V_72 -> V_76 ,
sizeof( V_69 ) ) )
return - V_17 ;
if ( V_74 == V_77 ) {
if ( F_5 ( V_24 , & V_72 -> V_78 . V_79 ) )
return - V_17 ;
V_75 = F_6 ( V_24 ) ;
if ( F_9 ( ( unsigned long ) V_75 , & V_11 -> V_78 . V_79 ) )
return - V_17 ;
} else if ( V_74 == V_80 ) {
if ( F_8 ( & V_11 -> V_78 . V_81 , & V_72 -> V_78 . V_81 , sizeof( int ) ) )
return - V_17 ;
} else {
if ( F_8 ( & V_11 -> V_78 . V_82 , & V_72 -> V_78 . V_82 ,
sizeof( V_69 ) ) )
return - V_17 ;
}
return 0 ;
}
static int F_35 ( struct V_70 T_1 * V_11 , struct V_71 T_1 * V_72 ,
enum V_73 V_74 )
{
if ( F_8 ( V_72 , V_11 , 2 * sizeof( V_69 ) ) ||
F_8 ( & V_72 -> V_76 , & V_11 -> V_76 ,
sizeof( V_69 ) ) )
return - V_17 ;
if ( V_74 == V_83 )
if ( F_8 ( & V_72 -> V_78 . V_82 , & V_11 -> V_78 . V_82 ,
sizeof( V_69 ) ) )
return - V_17 ;
if ( V_74 == V_80 )
if ( F_8 ( & V_72 -> V_78 . V_81 , & V_11 -> V_78 . V_81 ,
sizeof( int ) ) )
return - V_17 ;
return 0 ;
}
static int F_36 ( struct V_84 * V_9 , struct V_85 T_1 * V_11 )
{
struct V_71 T_1 * V_86 ;
struct V_70 T_1 * V_87 ;
T_2 V_24 ;
int V_4 ;
if ( ! F_3 ( V_12 , V_11 , sizeof( struct V_85 ) ) ||
F_5 ( V_9 -> V_64 , & V_11 -> V_64 ) ||
F_5 ( V_9 -> type , & V_11 -> type ) ||
F_5 ( V_9 -> V_88 , & V_11 -> V_88 ) ||
F_5 ( V_9 -> V_74 , & V_11 -> V_74 ) ||
F_5 ( V_9 -> V_89 , & V_11 -> V_89 ) )
return - V_17 ;
if ( F_37 ( V_9 -> type ) )
if ( F_5 ( V_9 -> V_90 , & V_11 -> V_90 ) ||
F_5 ( V_9 -> V_14 , & V_11 -> V_14 ) ||
F_5 ( V_9 -> V_91 . V_92 , & V_11 -> V_91 . V_92 ) ||
F_5 ( V_9 -> V_91 . V_93 ,
& V_11 -> V_91 . V_93 ) )
return - V_17 ;
if ( F_38 ( V_9 -> type ) ) {
unsigned int V_94 ;
if ( V_9 -> V_89 == 0 ) {
V_9 -> V_78 . V_95 = NULL ;
return 0 ;
} else if ( V_9 -> V_89 > V_96 ) {
return - V_18 ;
}
if ( F_5 ( V_24 , & V_11 -> V_78 . V_95 ) )
return - V_17 ;
V_86 = F_6 ( V_24 ) ;
if ( ! F_3 ( V_12 , V_86 ,
V_9 -> V_89 * sizeof( struct V_71 ) ) )
return - V_17 ;
V_87 = F_7 ( V_9 -> V_89 *
sizeof( struct V_70 ) ) ;
V_9 -> V_78 . V_95 = ( V_97 struct V_70 * ) V_87 ;
for ( V_94 = 0 ; V_94 < V_9 -> V_89 ; V_94 ++ ) {
V_4 = F_34 ( V_87 , V_86 , V_9 -> V_74 ) ;
if ( V_4 )
return V_4 ;
++ V_87 ;
++ V_86 ;
}
} else {
switch ( V_9 -> V_74 ) {
case V_83 :
if ( F_5 ( V_9 -> V_78 . V_98 , & V_11 -> V_78 . V_98 ) )
return - V_17 ;
break;
case V_77 :
{
T_3 V_99 ;
if ( F_5 ( V_99 , & V_11 -> V_78 . V_79 ) )
return - V_17 ;
V_9 -> V_78 . V_79 = ( unsigned long ) F_6 ( V_99 ) ;
}
break;
case V_100 :
if ( F_5 ( V_9 -> V_78 . V_98 , & V_11 -> V_78 . V_98 ) )
return - V_17 ;
break;
case V_80 :
if ( F_5 ( V_9 -> V_78 . V_81 , & V_11 -> V_78 . V_81 ) )
return - V_17 ;
break;
}
}
return 0 ;
}
static int F_39 ( struct V_84 * V_9 , struct V_85 T_1 * V_11 )
{
struct V_71 T_1 * V_86 ;
struct V_70 T_1 * V_87 ;
T_2 V_24 ;
int V_94 ;
int V_4 ;
if ( ! F_3 ( V_60 , V_11 , sizeof( struct V_85 ) ) ||
F_9 ( V_9 -> V_64 , & V_11 -> V_64 ) ||
F_9 ( V_9 -> type , & V_11 -> type ) ||
F_9 ( V_9 -> V_88 , & V_11 -> V_88 ) ||
F_9 ( V_9 -> V_74 , & V_11 -> V_74 ) )
return - V_17 ;
if ( F_9 ( V_9 -> V_90 , & V_11 -> V_90 ) ||
F_9 ( V_9 -> V_14 , & V_11 -> V_14 ) ||
F_9 ( V_9 -> V_91 . V_92 , & V_11 -> V_91 . V_92 ) ||
F_9 ( V_9 -> V_91 . V_93 , & V_11 -> V_91 . V_93 ) ||
F_11 ( & V_11 -> V_101 , & V_9 -> V_101 , sizeof( struct V_102 ) ) ||
F_9 ( V_9 -> V_103 , & V_11 -> V_103 ) ||
F_9 ( V_9 -> V_104 , & V_11 -> V_104 ) ||
F_9 ( V_9 -> V_61 , & V_11 -> V_61 ) ||
F_9 ( V_9 -> V_89 , & V_11 -> V_89 ) )
return - V_17 ;
if ( F_38 ( V_9 -> type ) ) {
V_94 = V_9 -> V_89 ;
if ( V_94 == 0 )
return 0 ;
V_87 = ( V_97 struct V_70 T_1 * ) V_9 -> V_78 . V_95 ;
if ( F_5 ( V_24 , & V_11 -> V_78 . V_95 ) )
return - V_17 ;
V_86 = F_6 ( V_24 ) ;
while ( -- V_94 >= 0 ) {
V_4 = F_35 ( V_87 , V_86 , V_9 -> V_74 ) ;
if ( V_4 )
return V_4 ;
++ V_87 ;
++ V_86 ;
}
} else {
switch ( V_9 -> V_74 ) {
case V_83 :
if ( F_9 ( V_9 -> V_78 . V_98 , & V_11 -> V_78 . V_98 ) )
return - V_17 ;
break;
case V_77 :
if ( F_9 ( V_9 -> V_78 . V_79 , & V_11 -> V_78 . V_79 ) )
return - V_17 ;
break;
case V_100 :
if ( F_9 ( V_9 -> V_78 . V_98 , & V_11 -> V_78 . V_98 ) )
return - V_17 ;
break;
case V_80 :
if ( F_9 ( V_9 -> V_78 . V_81 , & V_11 -> V_78 . V_81 ) )
return - V_17 ;
break;
}
}
return 0 ;
}
static int F_40 ( struct V_105 * V_9 , struct V_106 T_1 * V_11 )
{
T_4 V_99 ;
if ( ! F_3 ( V_12 , V_11 , sizeof( struct V_106 ) ) ||
F_5 ( V_99 , & V_11 -> V_107 ) ||
F_5 ( V_9 -> V_108 , & V_11 -> V_108 ) ||
F_5 ( V_9 -> V_88 , & V_11 -> V_88 ) ||
F_4 ( & V_9 -> V_38 , & V_11 -> V_38 , sizeof( V_11 -> V_38 ) ) )
return - V_17 ;
V_9 -> V_107 = ( V_97 void * ) F_6 ( V_99 ) ;
return 0 ;
}
static int F_41 ( struct V_105 * V_9 , struct V_106 T_1 * V_11 )
{
T_4 V_99 = ( T_4 ) ( ( unsigned long ) V_9 -> V_107 ) ;
if ( ! F_3 ( V_60 , V_11 , sizeof( struct V_106 ) ) ||
F_9 ( V_99 , & V_11 -> V_107 ) ||
F_9 ( V_9 -> V_108 , & V_11 -> V_108 ) ||
F_9 ( V_9 -> V_88 , & V_11 -> V_88 ) ||
F_11 ( & V_11 -> V_38 , & V_9 -> V_38 , sizeof( V_11 -> V_38 ) ) )
return - V_17 ;
return 0 ;
}
static inline int F_42 ( struct V_109 * V_9 , struct V_110 T_1 * V_11 )
{
if ( F_4 ( V_9 , V_11 , sizeof( struct V_110 ) ) )
return - V_17 ;
return 0 ;
}
static inline int F_43 ( struct V_109 * V_9 , struct V_110 T_1 * V_11 )
{
if ( F_11 ( V_11 , V_9 , sizeof( struct V_110 ) ) )
return - V_17 ;
return 0 ;
}
static inline int F_44 ( T_4 V_65 )
{
switch ( V_65 ) {
case V_111 :
case V_112 :
return 1 ;
default:
return 0 ;
}
}
static int F_45 ( struct V_113 * V_9 , struct V_114 T_1 * V_11 )
{
struct V_115 T_1 * V_116 ;
struct V_117 T_1 * V_118 ;
unsigned int V_23 ;
T_2 V_24 ;
if ( ! F_3 ( V_12 , V_11 , sizeof( struct V_114 ) ) ||
F_5 ( V_9 -> V_119 , & V_11 -> V_119 ) ||
F_5 ( V_9 -> V_120 , & V_11 -> V_120 ) ||
F_5 ( V_9 -> V_121 , & V_11 -> V_121 ) ||
F_4 ( V_9 -> V_61 , V_11 -> V_61 ,
sizeof( V_9 -> V_61 ) ) )
return - V_17 ;
if ( V_9 -> V_120 == 0 ) {
V_9 -> V_122 = NULL ;
return 0 ;
} else if ( V_9 -> V_120 > V_123 ) {
return - V_18 ;
}
if ( F_5 ( V_24 , & V_11 -> V_122 ) )
return - V_17 ;
V_116 = F_6 ( V_24 ) ;
if ( ! F_3 ( V_12 , V_116 ,
V_9 -> V_120 * sizeof( struct V_115 ) ) )
return - V_17 ;
V_118 = F_7 ( V_9 -> V_120 *
sizeof( struct V_117 ) ) ;
V_9 -> V_122 = ( V_97 struct V_117 * ) V_118 ;
for ( V_23 = 0 ; V_23 < V_9 -> V_120 ; V_23 ++ ) {
T_4 V_65 ;
if ( F_8 ( V_118 , V_116 , sizeof( * V_116 ) ) )
return - V_17 ;
if ( F_5 ( V_65 , & V_118 -> V_65 ) )
return - V_17 ;
if ( F_44 ( V_65 ) ) {
void T_1 * V_124 ;
if ( F_5 ( V_24 , & V_116 -> string ) )
return - V_17 ;
V_124 = F_6 ( V_24 ) ;
if ( F_9 ( V_124 , & V_118 -> string ) )
return - V_17 ;
}
V_116 ++ ;
V_118 ++ ;
}
return 0 ;
}
static int F_46 ( struct V_113 * V_9 , struct V_114 T_1 * V_11 )
{
struct V_115 T_1 * V_116 ;
struct V_117 T_1 * V_118 =
( V_97 struct V_117 T_1 * ) V_9 -> V_122 ;
int V_23 = V_9 -> V_120 ;
T_2 V_24 ;
if ( ! F_3 ( V_60 , V_11 , sizeof( struct V_114 ) ) ||
F_9 ( V_9 -> V_119 , & V_11 -> V_119 ) ||
F_9 ( V_9 -> V_120 , & V_11 -> V_120 ) ||
F_9 ( V_9 -> V_121 , & V_11 -> V_121 ) ||
F_11 ( V_11 -> V_61 , V_9 -> V_61 , sizeof( V_11 -> V_61 ) ) )
return - V_17 ;
if ( ! V_9 -> V_120 )
return 0 ;
if ( F_5 ( V_24 , & V_11 -> V_122 ) )
return - V_17 ;
V_116 = F_6 ( V_24 ) ;
if ( ! F_3 ( V_60 , V_116 ,
V_23 * sizeof( struct V_115 ) ) )
return - V_17 ;
while ( -- V_23 >= 0 ) {
unsigned V_125 = sizeof( * V_116 ) ;
T_4 V_65 ;
if ( F_5 ( V_65 , & V_118 -> V_65 ) )
return - V_17 ;
if ( F_44 ( V_65 ) )
V_125 -= sizeof( V_116 -> V_126 ) ;
if ( F_8 ( V_116 , V_118 , V_125 ) )
return - V_17 ;
V_116 ++ ;
V_118 ++ ;
}
return 0 ;
}
static int F_47 ( struct V_127 * V_9 , struct V_128 T_1 * V_11 )
{
if ( ! F_3 ( V_60 , V_11 , sizeof( struct V_128 ) ) ||
F_9 ( V_9 -> type , & V_11 -> type ) ||
F_11 ( & V_11 -> V_129 , & V_9 -> V_129 , sizeof( V_9 -> V_129 ) ) ||
F_9 ( V_9 -> V_130 , & V_11 -> V_130 ) ||
F_9 ( V_9 -> V_103 , & V_11 -> V_103 ) ||
F_48 ( & V_9 -> V_91 , & V_11 -> V_91 ) ||
F_9 ( V_9 -> V_65 , & V_11 -> V_65 ) ||
F_11 ( V_11 -> V_61 , V_9 -> V_61 , 8 * sizeof( V_69 ) ) )
return - V_17 ;
return 0 ;
}
static int F_49 ( struct V_131 * V_9 , struct V_132 T_1 * V_11 )
{
T_4 V_99 ;
if ( ! F_3 ( V_12 , V_11 , sizeof( struct V_132 ) ) ||
F_5 ( V_9 -> V_133 , & V_11 -> V_133 ) ||
F_5 ( V_9 -> V_134 , & V_11 -> V_134 ) ||
F_5 ( V_9 -> V_135 , & V_11 -> V_135 ) ||
F_5 ( V_99 , & V_11 -> V_136 ) ||
F_4 ( V_9 -> V_61 , V_11 -> V_61 , sizeof( V_9 -> V_61 ) ) )
return - V_17 ;
V_9 -> V_136 = ( V_97 V_137 * ) F_6 ( V_99 ) ;
return 0 ;
}
static int F_50 ( struct V_131 * V_9 , struct V_132 T_1 * V_11 )
{
T_4 V_99 = ( T_4 ) ( ( unsigned long ) V_9 -> V_136 ) ;
if ( ! F_3 ( V_60 , V_11 , sizeof( struct V_132 ) ) ||
F_9 ( V_9 -> V_133 , & V_11 -> V_133 ) ||
F_9 ( V_9 -> V_134 , & V_11 -> V_134 ) ||
F_9 ( V_9 -> V_135 , & V_11 -> V_135 ) ||
F_9 ( V_99 , & V_11 -> V_136 ) ||
F_11 ( V_11 -> V_61 , V_9 -> V_61 , sizeof( V_11 -> V_61 ) ) )
return - V_17 ;
return 0 ;
}
static long F_51 ( struct V_1 * V_1 , unsigned int V_2 , unsigned long V_3 )
{
union {
struct V_34 V_138 ;
struct V_84 V_139 ;
struct V_105 V_140 ;
struct V_109 V_141 ;
struct V_62 V_142 ;
struct V_113 V_143 ;
struct V_127 V_144 ;
struct V_57 V_145 ;
struct V_131 V_146 ;
unsigned long V_147 ;
int V_148 ;
} V_149 ;
void T_1 * V_11 = F_6 ( V_3 ) ;
int V_150 = 1 ;
long V_151 = 0 ;
switch ( V_2 ) {
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
case V_182 : V_2 = V_183 ; break;
case V_184 : V_2 = V_185 ; break;
case V_186 : V_2 = V_187 ; break;
case V_188 : V_2 = V_189 ; break;
case V_190 : V_2 = V_191 ; break;
case V_192 : V_2 = V_193 ; break;
case V_194 : V_2 = V_195 ; break;
case V_196 : V_2 = V_197 ; break;
case V_198 : V_2 = V_199 ; break;
case V_200 : V_2 = V_201 ; break;
}
switch ( V_2 ) {
case V_181 :
case V_183 :
case V_185 :
case V_189 :
case V_193 :
V_151 = F_5 ( V_149 . V_148 , ( V_202 T_1 * ) V_11 ) ;
V_150 = 0 ;
break;
case V_187 :
case V_191 :
V_150 = 0 ;
break;
case V_199 :
case V_201 :
V_151 = F_49 ( & V_149 . V_146 , V_11 ) ;
V_150 = 0 ;
break;
case V_153 :
case V_155 :
case V_171 :
V_151 = F_26 ( & V_149 . V_138 , V_11 ) ;
V_150 = 0 ;
break;
case V_195 :
V_151 = F_27 ( & V_149 . V_145 , V_11 ) ;
V_150 = 0 ;
break;
case V_197 :
case V_157 :
case V_163 :
case V_165 :
V_151 = F_36 ( & V_149 . V_139 , V_11 ) ;
V_150 = 0 ;
break;
case V_161 :
V_151 = F_40 ( & V_149 . V_140 , V_11 ) ;
V_150 = 0 ;
break;
case V_159 :
V_150 = 0 ;
break;
case V_167 :
V_151 = F_32 ( & V_149 . V_142 , V_11 ) ;
V_150 = 0 ;
break;
case V_169 :
V_151 = F_42 ( & V_149 . V_141 , V_11 ) ;
V_150 = 0 ;
break;
case V_173 :
case V_175 :
case V_177 :
V_151 = F_45 ( & V_149 . V_143 , V_11 ) ;
V_150 = 0 ;
break;
case V_179 :
V_150 = 0 ;
break;
}
if ( V_151 )
return V_151 ;
if ( V_150 )
V_151 = F_1 ( V_1 , V_2 , ( unsigned long ) V_11 ) ;
else {
T_5 V_203 = F_52 () ;
F_53 ( V_204 ) ;
V_151 = F_1 ( V_1 , V_2 , ( unsigned long ) & V_149 ) ;
F_53 ( V_203 ) ;
}
switch ( V_2 ) {
case V_173 :
case V_175 :
case V_177 :
if ( F_46 ( & V_149 . V_143 , V_11 ) )
V_151 = - V_17 ;
break;
case V_201 :
if ( F_50 ( & V_149 . V_146 , V_11 ) )
V_151 = - V_17 ;
break;
}
if ( V_151 )
return V_151 ;
switch ( V_2 ) {
case V_189 :
case V_193 :
case V_187 :
case V_191 :
V_151 = F_9 ( ( ( V_202 ) V_149 . V_148 ) , ( V_202 T_1 * ) V_11 ) ;
break;
case V_159 :
V_151 = F_41 ( & V_149 . V_140 , V_11 ) ;
break;
case V_179 :
V_151 = F_47 ( & V_149 . V_144 , V_11 ) ;
break;
case V_199 :
V_151 = F_50 ( & V_149 . V_146 , V_11 ) ;
break;
case V_153 :
case V_155 :
case V_171 :
V_151 = F_30 ( & V_149 . V_138 , V_11 ) ;
break;
case V_195 :
V_151 = F_31 ( & V_149 . V_145 , V_11 ) ;
break;
case V_157 :
case V_163 :
case V_165 :
V_151 = F_39 ( & V_149 . V_139 , V_11 ) ;
break;
case V_167 :
V_151 = F_33 ( & V_149 . V_142 , V_11 ) ;
break;
case V_169 :
V_151 = F_43 ( & V_149 . V_141 , V_11 ) ;
break;
}
return V_151 ;
}
long F_54 ( struct V_1 * V_1 , unsigned int V_2 , unsigned long V_3 )
{
struct V_205 * V_206 = F_55 ( V_1 ) ;
long V_4 = - V_5 ;
if ( ! V_1 -> V_6 -> V_7 )
return V_4 ;
if ( F_56 ( V_2 ) == 'V' && F_57 ( V_2 ) < V_207 )
V_4 = F_51 ( V_1 , V_2 , V_3 ) ;
else if ( V_206 -> V_208 -> V_209 )
V_4 = V_206 -> V_208 -> V_209 ( V_1 , V_2 , V_3 ) ;
if ( V_4 == - V_5 )
F_58 ( L_2 ,
F_56 ( V_2 ) , F_59 ( V_2 ) , F_57 ( V_2 ) , V_2 ) ;
return V_4 ;
}
