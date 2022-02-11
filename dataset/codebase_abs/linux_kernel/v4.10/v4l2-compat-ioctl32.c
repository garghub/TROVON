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
static int F_22 ( struct V_33 * V_9 , struct V_34 T_1 * V_11 )
{
if ( F_5 ( V_9 -> type , & V_11 -> type ) )
return - V_17 ;
switch ( V_9 -> type ) {
case V_35 :
case V_36 :
return F_12 ( & V_9 -> V_37 . V_38 , & V_11 -> V_37 . V_38 ) ;
case V_39 :
case V_40 :
return F_13 ( & V_9 -> V_37 . V_41 ,
& V_11 -> V_37 . V_41 ) ;
case V_42 :
case V_43 :
return F_2 ( & V_9 -> V_37 . V_44 , & V_11 -> V_37 . V_44 ) ;
case V_45 :
case V_46 :
return F_16 ( & V_9 -> V_37 . V_47 , & V_11 -> V_37 . V_47 ) ;
case V_48 :
case V_49 :
return F_18 ( & V_9 -> V_37 . V_50 , & V_11 -> V_37 . V_50 ) ;
case V_51 :
case V_52 :
return F_20 ( & V_9 -> V_37 . V_53 , & V_11 -> V_37 . V_53 ) ;
default:
F_23 ( L_1 ,
V_9 -> type ) ;
return - V_18 ;
}
}
static int F_24 ( struct V_33 * V_9 , struct V_34 T_1 * V_11 )
{
if ( ! F_3 ( V_12 , V_11 , sizeof( struct V_34 ) ) )
return - V_17 ;
return F_22 ( V_9 , V_11 ) ;
}
static int F_25 ( struct V_54 * V_9 , struct V_55 T_1 * V_11 )
{
if ( ! F_3 ( V_12 , V_11 , sizeof( struct V_55 ) ) ||
F_4 ( V_9 , V_11 , F_26 ( struct V_55 , V_56 ) ) )
return - V_17 ;
return F_22 ( & V_9 -> V_56 , & V_11 -> V_56 ) ;
}
static int F_27 ( struct V_33 * V_9 , struct V_34 T_1 * V_11 )
{
if ( F_9 ( V_9 -> type , & V_11 -> type ) )
return - V_17 ;
switch ( V_9 -> type ) {
case V_35 :
case V_36 :
return F_14 ( & V_9 -> V_37 . V_38 , & V_11 -> V_37 . V_38 ) ;
case V_39 :
case V_40 :
return F_15 ( & V_9 -> V_37 . V_41 ,
& V_11 -> V_37 . V_41 ) ;
case V_42 :
case V_43 :
return F_10 ( & V_9 -> V_37 . V_44 , & V_11 -> V_37 . V_44 ) ;
case V_45 :
case V_46 :
return F_17 ( & V_9 -> V_37 . V_47 , & V_11 -> V_37 . V_47 ) ;
case V_48 :
case V_49 :
return F_19 ( & V_9 -> V_37 . V_50 , & V_11 -> V_37 . V_50 ) ;
case V_51 :
case V_52 :
return F_21 ( & V_9 -> V_37 . V_53 , & V_11 -> V_37 . V_53 ) ;
default:
F_23 ( L_1 ,
V_9 -> type ) ;
return - V_18 ;
}
}
static int F_28 ( struct V_33 * V_9 , struct V_34 T_1 * V_11 )
{
if ( ! F_3 ( V_57 , V_11 , sizeof( struct V_34 ) ) )
return - V_17 ;
return F_27 ( V_9 , V_11 ) ;
}
static int F_29 ( struct V_54 * V_9 , struct V_55 T_1 * V_11 )
{
if ( ! F_3 ( V_57 , V_11 , sizeof( struct V_55 ) ) ||
F_11 ( V_11 , V_9 , F_26 ( struct V_55 , V_56 ) ) ||
F_11 ( V_11 -> V_58 , V_9 -> V_58 , sizeof( V_9 -> V_58 ) ) )
return - V_17 ;
return F_27 ( & V_9 -> V_56 , & V_11 -> V_56 ) ;
}
static int F_30 ( struct V_59 * V_9 , struct V_60 T_1 * V_11 )
{
if ( ! F_3 ( V_12 , V_11 , sizeof( struct V_60 ) ) ||
F_5 ( V_9 -> V_61 , & V_11 -> V_61 ) )
return - V_17 ;
return 0 ;
}
static int F_31 ( struct V_59 * V_9 , struct V_60 T_1 * V_11 )
{
if ( ! F_3 ( V_57 , V_11 , sizeof( struct V_60 ) ) ||
F_9 ( V_9 -> V_61 , & V_11 -> V_61 ) ||
F_9 ( V_9 -> V_62 , & V_11 -> V_62 ) ||
F_11 ( V_11 -> V_63 , V_9 -> V_63 , 24 ) ||
F_11 ( & V_11 -> V_64 , & V_9 -> V_64 , sizeof( V_9 -> V_64 ) ) ||
F_9 ( V_9 -> V_65 , & V_11 -> V_65 ) ||
F_11 ( V_11 -> V_58 , V_9 -> V_58 , 4 * sizeof( V_66 ) ) )
return - V_17 ;
return 0 ;
}
static int F_32 ( struct V_67 T_1 * V_11 , struct V_68 T_1 * V_69 ,
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
} else if ( V_71 == V_77 ) {
if ( F_8 ( & V_11 -> V_75 . V_78 , & V_69 -> V_75 . V_78 , sizeof( int ) ) )
return - V_17 ;
} else {
if ( F_8 ( & V_11 -> V_75 . V_79 , & V_69 -> V_75 . V_79 ,
sizeof( V_66 ) ) )
return - V_17 ;
}
return 0 ;
}
static int F_33 ( struct V_67 T_1 * V_11 , struct V_68 T_1 * V_69 ,
enum V_70 V_71 )
{
if ( F_8 ( V_69 , V_11 , 2 * sizeof( V_66 ) ) ||
F_8 ( & V_69 -> V_73 , & V_11 -> V_73 ,
sizeof( V_66 ) ) )
return - V_17 ;
if ( V_71 == V_80 )
if ( F_8 ( & V_69 -> V_75 . V_79 , & V_11 -> V_75 . V_79 ,
sizeof( V_66 ) ) )
return - V_17 ;
if ( V_71 == V_77 )
if ( F_8 ( & V_69 -> V_75 . V_78 , & V_11 -> V_75 . V_78 ,
sizeof( int ) ) )
return - V_17 ;
return 0 ;
}
static int F_34 ( struct V_81 * V_9 , struct V_82 T_1 * V_11 )
{
struct V_68 T_1 * V_83 ;
struct V_67 T_1 * V_84 ;
T_2 V_24 ;
int V_4 ;
if ( ! F_3 ( V_12 , V_11 , sizeof( struct V_82 ) ) ||
F_5 ( V_9 -> V_61 , & V_11 -> V_61 ) ||
F_5 ( V_9 -> type , & V_11 -> type ) ||
F_5 ( V_9 -> V_85 , & V_11 -> V_85 ) ||
F_5 ( V_9 -> V_71 , & V_11 -> V_71 ) ||
F_5 ( V_9 -> V_86 , & V_11 -> V_86 ) )
return - V_17 ;
if ( F_35 ( V_9 -> type ) )
if ( F_5 ( V_9 -> V_87 , & V_11 -> V_87 ) ||
F_5 ( V_9 -> V_14 , & V_11 -> V_14 ) ||
F_5 ( V_9 -> V_88 . V_89 , & V_11 -> V_88 . V_89 ) ||
F_5 ( V_9 -> V_88 . V_90 ,
& V_11 -> V_88 . V_90 ) )
return - V_17 ;
if ( F_36 ( V_9 -> type ) ) {
unsigned int V_91 ;
if ( V_9 -> V_86 == 0 ) {
V_9 -> V_75 . V_92 = NULL ;
return 0 ;
} else if ( V_9 -> V_86 > V_93 ) {
return - V_18 ;
}
if ( F_5 ( V_24 , & V_11 -> V_75 . V_92 ) )
return - V_17 ;
V_83 = F_6 ( V_24 ) ;
if ( ! F_3 ( V_12 , V_83 ,
V_9 -> V_86 * sizeof( struct V_68 ) ) )
return - V_17 ;
V_84 = F_7 ( V_9 -> V_86 *
sizeof( struct V_67 ) ) ;
V_9 -> V_75 . V_92 = ( V_94 struct V_67 * ) V_84 ;
for ( V_91 = 0 ; V_91 < V_9 -> V_86 ; V_91 ++ ) {
V_4 = F_32 ( V_84 , V_83 , V_9 -> V_71 ) ;
if ( V_4 )
return V_4 ;
++ V_84 ;
++ V_83 ;
}
} else {
switch ( V_9 -> V_71 ) {
case V_80 :
if ( F_5 ( V_9 -> V_75 . V_95 , & V_11 -> V_75 . V_95 ) )
return - V_17 ;
break;
case V_74 :
{
T_3 V_96 ;
if ( F_5 ( V_96 , & V_11 -> V_75 . V_76 ) )
return - V_17 ;
V_9 -> V_75 . V_76 = ( unsigned long ) F_6 ( V_96 ) ;
}
break;
case V_97 :
if ( F_5 ( V_9 -> V_75 . V_95 , & V_11 -> V_75 . V_95 ) )
return - V_17 ;
break;
case V_77 :
if ( F_5 ( V_9 -> V_75 . V_78 , & V_11 -> V_75 . V_78 ) )
return - V_17 ;
break;
}
}
return 0 ;
}
static int F_37 ( struct V_81 * V_9 , struct V_82 T_1 * V_11 )
{
struct V_68 T_1 * V_83 ;
struct V_67 T_1 * V_84 ;
T_2 V_24 ;
int V_91 ;
int V_4 ;
if ( ! F_3 ( V_57 , V_11 , sizeof( struct V_82 ) ) ||
F_9 ( V_9 -> V_61 , & V_11 -> V_61 ) ||
F_9 ( V_9 -> type , & V_11 -> type ) ||
F_9 ( V_9 -> V_85 , & V_11 -> V_85 ) ||
F_9 ( V_9 -> V_71 , & V_11 -> V_71 ) )
return - V_17 ;
if ( F_9 ( V_9 -> V_87 , & V_11 -> V_87 ) ||
F_9 ( V_9 -> V_14 , & V_11 -> V_14 ) ||
F_9 ( V_9 -> V_88 . V_89 , & V_11 -> V_88 . V_89 ) ||
F_9 ( V_9 -> V_88 . V_90 , & V_11 -> V_88 . V_90 ) ||
F_11 ( & V_11 -> V_98 , & V_9 -> V_98 , sizeof( struct V_99 ) ) ||
F_9 ( V_9 -> V_100 , & V_11 -> V_100 ) ||
F_9 ( V_9 -> V_101 , & V_11 -> V_101 ) ||
F_9 ( V_9 -> V_58 , & V_11 -> V_58 ) ||
F_9 ( V_9 -> V_86 , & V_11 -> V_86 ) )
return - V_17 ;
if ( F_36 ( V_9 -> type ) ) {
V_91 = V_9 -> V_86 ;
if ( V_91 == 0 )
return 0 ;
V_84 = ( V_94 struct V_67 T_1 * ) V_9 -> V_75 . V_92 ;
if ( F_5 ( V_24 , & V_11 -> V_75 . V_92 ) )
return - V_17 ;
V_83 = F_6 ( V_24 ) ;
while ( -- V_91 >= 0 ) {
V_4 = F_33 ( V_84 , V_83 , V_9 -> V_71 ) ;
if ( V_4 )
return V_4 ;
++ V_84 ;
++ V_83 ;
}
} else {
switch ( V_9 -> V_71 ) {
case V_80 :
if ( F_9 ( V_9 -> V_75 . V_95 , & V_11 -> V_75 . V_95 ) )
return - V_17 ;
break;
case V_74 :
if ( F_9 ( V_9 -> V_75 . V_76 , & V_11 -> V_75 . V_76 ) )
return - V_17 ;
break;
case V_97 :
if ( F_9 ( V_9 -> V_75 . V_95 , & V_11 -> V_75 . V_95 ) )
return - V_17 ;
break;
case V_77 :
if ( F_9 ( V_9 -> V_75 . V_78 , & V_11 -> V_75 . V_78 ) )
return - V_17 ;
break;
}
}
return 0 ;
}
static int F_38 ( struct V_102 * V_9 , struct V_103 T_1 * V_11 )
{
T_4 V_96 ;
if ( ! F_3 ( V_12 , V_11 , sizeof( struct V_103 ) ) ||
F_5 ( V_96 , & V_11 -> V_104 ) ||
F_5 ( V_9 -> V_105 , & V_11 -> V_105 ) ||
F_5 ( V_9 -> V_85 , & V_11 -> V_85 ) ||
F_4 ( & V_9 -> V_37 , & V_11 -> V_37 , sizeof( V_11 -> V_37 ) ) )
return - V_17 ;
V_9 -> V_104 = ( V_94 void * ) F_6 ( V_96 ) ;
return 0 ;
}
static int F_39 ( struct V_102 * V_9 , struct V_103 T_1 * V_11 )
{
T_4 V_96 = ( T_4 ) ( ( unsigned long ) V_9 -> V_104 ) ;
if ( ! F_3 ( V_57 , V_11 , sizeof( struct V_103 ) ) ||
F_9 ( V_96 , & V_11 -> V_104 ) ||
F_9 ( V_9 -> V_105 , & V_11 -> V_105 ) ||
F_9 ( V_9 -> V_85 , & V_11 -> V_85 ) ||
F_11 ( & V_11 -> V_37 , & V_9 -> V_37 , sizeof( V_11 -> V_37 ) ) )
return - V_17 ;
return 0 ;
}
static inline int F_40 ( struct V_106 * V_9 , struct V_107 T_1 * V_11 )
{
if ( F_4 ( V_9 , V_11 , sizeof( struct V_107 ) ) )
return - V_17 ;
return 0 ;
}
static inline int F_41 ( struct V_106 * V_9 , struct V_107 T_1 * V_11 )
{
if ( F_11 ( V_11 , V_9 , sizeof( struct V_107 ) ) )
return - V_17 ;
return 0 ;
}
static inline int F_42 ( T_4 V_62 )
{
switch ( V_62 ) {
case V_108 :
case V_109 :
return 1 ;
default:
return 0 ;
}
}
static int F_43 ( struct V_110 * V_9 , struct V_111 T_1 * V_11 )
{
struct V_112 T_1 * V_113 ;
struct V_114 T_1 * V_115 ;
unsigned int V_23 ;
T_2 V_24 ;
if ( ! F_3 ( V_12 , V_11 , sizeof( struct V_111 ) ) ||
F_5 ( V_9 -> V_116 , & V_11 -> V_116 ) ||
F_5 ( V_9 -> V_117 , & V_11 -> V_117 ) ||
F_5 ( V_9 -> V_118 , & V_11 -> V_118 ) ||
F_4 ( V_9 -> V_58 , V_11 -> V_58 ,
sizeof( V_9 -> V_58 ) ) )
return - V_17 ;
if ( V_9 -> V_117 == 0 ) {
V_9 -> V_119 = NULL ;
return 0 ;
} else if ( V_9 -> V_117 > V_120 ) {
return - V_18 ;
}
if ( F_5 ( V_24 , & V_11 -> V_119 ) )
return - V_17 ;
V_113 = F_6 ( V_24 ) ;
if ( ! F_3 ( V_12 , V_113 ,
V_9 -> V_117 * sizeof( struct V_112 ) ) )
return - V_17 ;
V_115 = F_7 ( V_9 -> V_117 *
sizeof( struct V_114 ) ) ;
V_9 -> V_119 = ( V_94 struct V_114 * ) V_115 ;
for ( V_23 = 0 ; V_23 < V_9 -> V_117 ; V_23 ++ ) {
T_4 V_62 ;
if ( F_8 ( V_115 , V_113 , sizeof( * V_113 ) ) )
return - V_17 ;
if ( F_5 ( V_62 , & V_115 -> V_62 ) )
return - V_17 ;
if ( F_42 ( V_62 ) ) {
void T_1 * V_121 ;
if ( F_5 ( V_24 , & V_113 -> string ) )
return - V_17 ;
V_121 = F_6 ( V_24 ) ;
if ( F_9 ( V_121 , & V_115 -> string ) )
return - V_17 ;
}
V_113 ++ ;
V_115 ++ ;
}
return 0 ;
}
static int F_44 ( struct V_110 * V_9 , struct V_111 T_1 * V_11 )
{
struct V_112 T_1 * V_113 ;
struct V_114 T_1 * V_115 =
( V_94 struct V_114 T_1 * ) V_9 -> V_119 ;
int V_23 = V_9 -> V_117 ;
T_2 V_24 ;
if ( ! F_3 ( V_57 , V_11 , sizeof( struct V_111 ) ) ||
F_9 ( V_9 -> V_116 , & V_11 -> V_116 ) ||
F_9 ( V_9 -> V_117 , & V_11 -> V_117 ) ||
F_9 ( V_9 -> V_118 , & V_11 -> V_118 ) ||
F_11 ( V_11 -> V_58 , V_9 -> V_58 , sizeof( V_11 -> V_58 ) ) )
return - V_17 ;
if ( ! V_9 -> V_117 )
return 0 ;
if ( F_5 ( V_24 , & V_11 -> V_119 ) )
return - V_17 ;
V_113 = F_6 ( V_24 ) ;
if ( ! F_3 ( V_57 , V_113 ,
V_23 * sizeof( struct V_112 ) ) )
return - V_17 ;
while ( -- V_23 >= 0 ) {
unsigned V_122 = sizeof( * V_113 ) ;
T_4 V_62 ;
if ( F_5 ( V_62 , & V_115 -> V_62 ) )
return - V_17 ;
if ( F_42 ( V_62 ) )
V_122 -= sizeof( V_113 -> V_123 ) ;
if ( F_8 ( V_113 , V_115 , V_122 ) )
return - V_17 ;
V_113 ++ ;
V_115 ++ ;
}
return 0 ;
}
static int F_45 ( struct V_124 * V_9 , struct V_125 T_1 * V_11 )
{
if ( ! F_3 ( V_57 , V_11 , sizeof( struct V_125 ) ) ||
F_9 ( V_9 -> type , & V_11 -> type ) ||
F_11 ( & V_11 -> V_126 , & V_9 -> V_126 , sizeof( V_9 -> V_126 ) ) ||
F_9 ( V_9 -> V_127 , & V_11 -> V_127 ) ||
F_9 ( V_9 -> V_100 , & V_11 -> V_100 ) ||
F_46 ( & V_9 -> V_88 , & V_11 -> V_88 ) ||
F_9 ( V_9 -> V_62 , & V_11 -> V_62 ) ||
F_11 ( V_11 -> V_58 , V_9 -> V_58 , 8 * sizeof( V_66 ) ) )
return - V_17 ;
return 0 ;
}
static int F_47 ( struct V_128 * V_9 , struct V_129 T_1 * V_11 )
{
T_4 V_96 ;
if ( ! F_3 ( V_12 , V_11 , sizeof( struct V_129 ) ) ||
F_5 ( V_9 -> V_130 , & V_11 -> V_130 ) ||
F_5 ( V_9 -> V_131 , & V_11 -> V_131 ) ||
F_5 ( V_9 -> V_132 , & V_11 -> V_132 ) ||
F_5 ( V_96 , & V_11 -> V_133 ) ||
F_4 ( V_9 -> V_58 , V_11 -> V_58 , sizeof( V_9 -> V_58 ) ) )
return - V_17 ;
V_9 -> V_133 = ( V_94 V_134 * ) F_6 ( V_96 ) ;
return 0 ;
}
static int F_48 ( struct V_128 * V_9 , struct V_129 T_1 * V_11 )
{
T_4 V_96 = ( T_4 ) ( ( unsigned long ) V_9 -> V_133 ) ;
if ( ! F_3 ( V_57 , V_11 , sizeof( struct V_129 ) ) ||
F_9 ( V_9 -> V_130 , & V_11 -> V_130 ) ||
F_9 ( V_9 -> V_131 , & V_11 -> V_131 ) ||
F_9 ( V_9 -> V_132 , & V_11 -> V_132 ) ||
F_9 ( V_96 , & V_11 -> V_133 ) ||
F_11 ( V_11 -> V_58 , V_9 -> V_58 , sizeof( V_11 -> V_58 ) ) )
return - V_17 ;
return 0 ;
}
static long F_49 ( struct V_1 * V_1 , unsigned int V_2 , unsigned long V_3 )
{
union {
struct V_33 V_135 ;
struct V_81 V_136 ;
struct V_102 V_137 ;
struct V_106 V_138 ;
struct V_59 V_139 ;
struct V_110 V_140 ;
struct V_124 V_141 ;
struct V_54 V_142 ;
struct V_128 V_143 ;
unsigned long V_144 ;
int V_145 ;
} V_146 ;
void T_1 * V_11 = F_6 ( V_3 ) ;
int V_147 = 1 ;
long V_148 = 0 ;
switch ( V_2 ) {
case V_149 : V_2 = V_150 ; break;
case V_151 : V_2 = V_152 ; break;
case V_153 : V_2 = V_154 ; break;
case V_155 : V_2 = V_156 ; break;
case V_157 : V_2 = V_158 ; break;
case V_159 : V_2 = V_160 ; break;
case V_161 : V_2 = V_162 ; break;
case V_163 : V_2 = V_164 ; break;
case V_165 : V_2 = V_166 ; break;
case V_167 : V_2 = V_168 ; break;
case V_169 : V_2 = V_170 ; break;
case V_171 : V_2 = V_172 ; break;
case V_173 : V_2 = V_174 ; break;
case V_175 : V_2 = V_176 ; break;
case V_177 : V_2 = V_178 ; break;
case V_179 : V_2 = V_180 ; break;
case V_181 : V_2 = V_182 ; break;
case V_183 : V_2 = V_184 ; break;
case V_185 : V_2 = V_186 ; break;
case V_187 : V_2 = V_188 ; break;
case V_189 : V_2 = V_190 ; break;
case V_191 : V_2 = V_192 ; break;
case V_193 : V_2 = V_194 ; break;
case V_195 : V_2 = V_196 ; break;
case V_197 : V_2 = V_198 ; break;
}
switch ( V_2 ) {
case V_178 :
case V_180 :
case V_182 :
case V_186 :
case V_190 :
V_148 = F_5 ( V_146 . V_145 , ( V_199 T_1 * ) V_11 ) ;
V_147 = 0 ;
break;
case V_184 :
case V_188 :
V_147 = 0 ;
break;
case V_196 :
case V_198 :
V_148 = F_47 ( & V_146 . V_143 , V_11 ) ;
V_147 = 0 ;
break;
case V_150 :
case V_152 :
case V_168 :
V_148 = F_24 ( & V_146 . V_135 , V_11 ) ;
V_147 = 0 ;
break;
case V_192 :
V_148 = F_25 ( & V_146 . V_142 , V_11 ) ;
V_147 = 0 ;
break;
case V_194 :
case V_154 :
case V_160 :
case V_162 :
V_148 = F_34 ( & V_146 . V_136 , V_11 ) ;
V_147 = 0 ;
break;
case V_158 :
V_148 = F_38 ( & V_146 . V_137 , V_11 ) ;
V_147 = 0 ;
break;
case V_156 :
V_147 = 0 ;
break;
case V_164 :
V_148 = F_30 ( & V_146 . V_139 , V_11 ) ;
V_147 = 0 ;
break;
case V_166 :
V_148 = F_40 ( & V_146 . V_138 , V_11 ) ;
V_147 = 0 ;
break;
case V_170 :
case V_172 :
case V_174 :
V_148 = F_43 ( & V_146 . V_140 , V_11 ) ;
V_147 = 0 ;
break;
case V_176 :
V_147 = 0 ;
break;
}
if ( V_148 )
return V_148 ;
if ( V_147 )
V_148 = F_1 ( V_1 , V_2 , ( unsigned long ) V_11 ) ;
else {
T_5 V_200 = F_50 () ;
F_51 ( V_201 ) ;
V_148 = F_1 ( V_1 , V_2 , ( unsigned long ) & V_146 ) ;
F_51 ( V_200 ) ;
}
switch ( V_2 ) {
case V_170 :
case V_172 :
case V_174 :
if ( F_44 ( & V_146 . V_140 , V_11 ) )
V_148 = - V_17 ;
break;
}
if ( V_148 )
return V_148 ;
switch ( V_2 ) {
case V_186 :
case V_190 :
case V_184 :
case V_188 :
V_148 = F_9 ( ( ( V_199 ) V_146 . V_145 ) , ( V_199 T_1 * ) V_11 ) ;
break;
case V_156 :
V_148 = F_39 ( & V_146 . V_137 , V_11 ) ;
break;
case V_176 :
V_148 = F_45 ( & V_146 . V_141 , V_11 ) ;
break;
case V_196 :
case V_198 :
V_148 = F_48 ( & V_146 . V_143 , V_11 ) ;
break;
case V_150 :
case V_152 :
case V_168 :
V_148 = F_28 ( & V_146 . V_135 , V_11 ) ;
break;
case V_192 :
V_148 = F_29 ( & V_146 . V_142 , V_11 ) ;
break;
case V_154 :
case V_160 :
case V_162 :
V_148 = F_37 ( & V_146 . V_136 , V_11 ) ;
break;
case V_164 :
V_148 = F_31 ( & V_146 . V_139 , V_11 ) ;
break;
case V_166 :
V_148 = F_41 ( & V_146 . V_138 , V_11 ) ;
break;
}
return V_148 ;
}
long F_52 ( struct V_1 * V_1 , unsigned int V_2 , unsigned long V_3 )
{
struct V_202 * V_203 = F_53 ( V_1 ) ;
long V_4 = - V_5 ;
if ( ! V_1 -> V_6 -> V_7 )
return V_4 ;
if ( F_54 ( V_2 ) == 'V' && F_55 ( V_2 ) < V_204 )
V_4 = F_49 ( V_1 , V_2 , V_3 ) ;
else if ( V_203 -> V_205 -> V_206 )
V_4 = V_203 -> V_205 -> V_206 ( V_1 , V_2 , V_3 ) ;
if ( V_4 == - V_5 )
F_56 ( L_2 ,
F_54 ( V_2 ) , F_57 ( V_2 ) , F_55 ( V_2 ) , V_2 ) ;
return V_4 ;
}
