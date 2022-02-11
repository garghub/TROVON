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
F_5 ( V_9 -> V_16 , & V_11 -> V_16 ) ||
F_5 ( V_9 -> V_17 , & V_11 -> V_17 ) )
return - V_18 ;
if ( V_9 -> V_16 > 2048 )
return - V_19 ;
if ( V_9 -> V_16 ) {
struct V_20 T_1 * V_21 ;
struct V_22 T_1 * V_23 ;
int V_24 = V_9 -> V_16 ;
T_2 V_25 ;
if ( F_5 ( V_25 , & V_11 -> V_26 ) )
return - V_18 ;
V_21 = F_6 ( V_25 ) ;
V_23 = F_7 ( V_24 * sizeof( struct V_22 ) ) ;
V_9 -> V_26 = V_23 ;
while ( -- V_24 >= 0 ) {
if ( F_8 ( & V_23 -> V_27 , & V_21 -> V_27 , sizeof( V_21 -> V_27 ) ) )
return - V_18 ;
if ( F_9 ( V_24 ? V_23 + 1 : NULL , & V_23 -> V_28 ) )
return - V_18 ;
V_21 += 1 ;
V_23 += 1 ;
}
} else
V_9 -> V_26 = NULL ;
return 0 ;
}
static int F_10 ( struct V_8 * V_9 , struct V_10 T_1 * V_11 )
{
if ( F_11 ( & V_11 -> V_13 , & V_9 -> V_13 , sizeof( V_9 -> V_13 ) ) ||
F_9 ( V_9 -> V_14 , & V_11 -> V_14 ) ||
F_9 ( V_9 -> V_15 , & V_11 -> V_15 ) ||
F_9 ( V_9 -> V_16 , & V_11 -> V_16 ) ||
F_9 ( V_9 -> V_17 , & V_11 -> V_17 ) )
return - V_18 ;
return 0 ;
}
static inline int F_12 ( struct V_29 * V_9 , struct V_29 T_1 * V_11 )
{
if ( F_4 ( V_9 , V_11 , sizeof( struct V_29 ) ) )
return - V_18 ;
return 0 ;
}
static inline int F_13 ( struct V_30 * V_9 ,
struct V_30 T_1 * V_11 )
{
if ( F_4 ( V_9 , V_11 , sizeof( struct V_30 ) ) )
return - V_18 ;
return 0 ;
}
static inline int F_14 ( struct V_29 * V_9 , struct V_29 T_1 * V_11 )
{
if ( F_11 ( V_11 , V_9 , sizeof( struct V_29 ) ) )
return - V_18 ;
return 0 ;
}
static inline int F_15 ( struct V_30 * V_9 ,
struct V_30 T_1 * V_11 )
{
if ( F_11 ( V_11 , V_9 , sizeof( struct V_30 ) ) )
return - V_18 ;
return 0 ;
}
static inline int F_16 ( struct V_31 * V_9 , struct V_31 T_1 * V_11 )
{
if ( F_4 ( V_9 , V_11 , sizeof( struct V_31 ) ) )
return - V_18 ;
return 0 ;
}
static inline int F_17 ( struct V_31 * V_9 , struct V_31 T_1 * V_11 )
{
if ( F_11 ( V_11 , V_9 , sizeof( struct V_31 ) ) )
return - V_18 ;
return 0 ;
}
static inline int F_18 ( struct V_32 * V_9 , struct V_32 T_1 * V_11 )
{
if ( F_4 ( V_9 , V_11 , sizeof( struct V_32 ) ) )
return - V_18 ;
return 0 ;
}
static inline int F_19 ( struct V_32 * V_9 , struct V_32 T_1 * V_11 )
{
if ( F_11 ( V_11 , V_9 , sizeof( struct V_32 ) ) )
return - V_18 ;
return 0 ;
}
static inline int F_20 ( struct V_33 * V_9 , struct V_33 T_1 * V_11 )
{
if ( F_4 ( V_9 , V_11 , sizeof( struct V_33 ) ) )
return - V_18 ;
return 0 ;
}
static inline int F_21 ( struct V_33 * V_9 , struct V_33 T_1 * V_11 )
{
if ( F_11 ( V_11 , V_9 , sizeof( struct V_33 ) ) )
return - V_18 ;
return 0 ;
}
static inline int F_22 ( struct V_34 * V_9 , struct V_34 T_1 * V_11 )
{
if ( F_4 ( V_9 , V_11 , sizeof( struct V_34 ) ) )
return - V_18 ;
return 0 ;
}
static inline int F_23 ( struct V_34 * V_9 , struct V_34 T_1 * V_11 )
{
if ( F_11 ( V_11 , V_9 , sizeof( struct V_34 ) ) )
return - V_18 ;
return 0 ;
}
static int F_24 ( struct V_35 * V_9 , struct V_36 T_1 * V_11 )
{
if ( F_5 ( V_9 -> type , & V_11 -> type ) )
return - V_18 ;
switch ( V_9 -> type ) {
case V_37 :
case V_38 :
return F_12 ( & V_9 -> V_39 . V_40 , & V_11 -> V_39 . V_40 ) ;
case V_41 :
case V_42 :
return F_13 ( & V_9 -> V_39 . V_43 ,
& V_11 -> V_39 . V_43 ) ;
case V_44 :
case V_45 :
return F_2 ( & V_9 -> V_39 . V_46 , & V_11 -> V_39 . V_46 ) ;
case V_47 :
case V_48 :
return F_16 ( & V_9 -> V_39 . V_49 , & V_11 -> V_39 . V_49 ) ;
case V_50 :
case V_51 :
return F_18 ( & V_9 -> V_39 . V_52 , & V_11 -> V_39 . V_52 ) ;
case V_53 :
case V_54 :
return F_20 ( & V_9 -> V_39 . V_55 , & V_11 -> V_39 . V_55 ) ;
case V_56 :
return F_22 ( & V_9 -> V_39 . V_57 , & V_11 -> V_39 . V_57 ) ;
default:
F_25 ( L_1 ,
V_9 -> type ) ;
return - V_19 ;
}
}
static int F_26 ( struct V_35 * V_9 , struct V_36 T_1 * V_11 )
{
if ( ! F_3 ( V_12 , V_11 , sizeof( struct V_36 ) ) )
return - V_18 ;
return F_24 ( V_9 , V_11 ) ;
}
static int F_27 ( struct V_58 * V_9 , struct V_59 T_1 * V_11 )
{
if ( ! F_3 ( V_12 , V_11 , sizeof( struct V_59 ) ) ||
F_4 ( V_9 , V_11 , F_28 ( struct V_59 , V_60 ) ) )
return - V_18 ;
return F_24 ( & V_9 -> V_60 , & V_11 -> V_60 ) ;
}
static int F_29 ( struct V_35 * V_9 , struct V_36 T_1 * V_11 )
{
if ( F_9 ( V_9 -> type , & V_11 -> type ) )
return - V_18 ;
switch ( V_9 -> type ) {
case V_37 :
case V_38 :
return F_14 ( & V_9 -> V_39 . V_40 , & V_11 -> V_39 . V_40 ) ;
case V_41 :
case V_42 :
return F_15 ( & V_9 -> V_39 . V_43 ,
& V_11 -> V_39 . V_43 ) ;
case V_44 :
case V_45 :
return F_10 ( & V_9 -> V_39 . V_46 , & V_11 -> V_39 . V_46 ) ;
case V_47 :
case V_48 :
return F_17 ( & V_9 -> V_39 . V_49 , & V_11 -> V_39 . V_49 ) ;
case V_50 :
case V_51 :
return F_19 ( & V_9 -> V_39 . V_52 , & V_11 -> V_39 . V_52 ) ;
case V_53 :
case V_54 :
return F_21 ( & V_9 -> V_39 . V_55 , & V_11 -> V_39 . V_55 ) ;
case V_56 :
return F_23 ( & V_9 -> V_39 . V_57 , & V_11 -> V_39 . V_57 ) ;
default:
F_25 ( L_1 ,
V_9 -> type ) ;
return - V_19 ;
}
}
static int F_30 ( struct V_35 * V_9 , struct V_36 T_1 * V_11 )
{
if ( ! F_3 ( V_61 , V_11 , sizeof( struct V_36 ) ) )
return - V_18 ;
return F_29 ( V_9 , V_11 ) ;
}
static int F_31 ( struct V_58 * V_9 , struct V_59 T_1 * V_11 )
{
if ( ! F_3 ( V_61 , V_11 , sizeof( struct V_59 ) ) ||
F_11 ( V_11 , V_9 , F_28 ( struct V_59 , V_60 ) ) ||
F_11 ( V_11 -> V_62 , V_9 -> V_62 , sizeof( V_9 -> V_62 ) ) )
return - V_18 ;
return F_29 ( & V_9 -> V_60 , & V_11 -> V_60 ) ;
}
static int F_32 ( struct V_63 * V_9 , struct V_64 T_1 * V_11 )
{
if ( ! F_3 ( V_12 , V_11 , sizeof( struct V_64 ) ) ||
F_5 ( V_9 -> V_65 , & V_11 -> V_65 ) )
return - V_18 ;
return 0 ;
}
static int F_33 ( struct V_63 * V_9 , struct V_64 T_1 * V_11 )
{
if ( ! F_3 ( V_61 , V_11 , sizeof( struct V_64 ) ) ||
F_9 ( V_9 -> V_65 , & V_11 -> V_65 ) ||
F_9 ( V_9 -> V_66 , & V_11 -> V_66 ) ||
F_11 ( V_11 -> V_67 , V_9 -> V_67 , 24 ) ||
F_11 ( & V_11 -> V_68 , & V_9 -> V_68 , sizeof( V_9 -> V_68 ) ) ||
F_9 ( V_9 -> V_69 , & V_11 -> V_69 ) ||
F_11 ( V_11 -> V_62 , V_9 -> V_62 , 4 * sizeof( V_70 ) ) )
return - V_18 ;
return 0 ;
}
static int F_34 ( struct V_71 T_1 * V_11 , struct V_72 T_1 * V_73 ,
enum V_74 V_75 )
{
void T_1 * V_76 ;
T_3 V_25 ;
if ( F_8 ( V_11 , V_73 , 2 * sizeof( V_70 ) ) ||
F_8 ( & V_11 -> V_77 , & V_73 -> V_77 ,
sizeof( V_70 ) ) )
return - V_18 ;
if ( V_75 == V_78 ) {
if ( F_5 ( V_25 , & V_73 -> V_79 . V_80 ) )
return - V_18 ;
V_76 = F_6 ( V_25 ) ;
if ( F_9 ( ( unsigned long ) V_76 , & V_11 -> V_79 . V_80 ) )
return - V_18 ;
} else if ( V_75 == V_81 ) {
if ( F_8 ( & V_11 -> V_79 . V_82 , & V_73 -> V_79 . V_82 , sizeof( int ) ) )
return - V_18 ;
} else {
if ( F_8 ( & V_11 -> V_79 . V_83 , & V_73 -> V_79 . V_83 ,
sizeof( V_70 ) ) )
return - V_18 ;
}
return 0 ;
}
static int F_35 ( struct V_71 T_1 * V_11 , struct V_72 T_1 * V_73 ,
enum V_74 V_75 )
{
if ( F_8 ( V_73 , V_11 , 2 * sizeof( V_70 ) ) ||
F_8 ( & V_73 -> V_77 , & V_11 -> V_77 ,
sizeof( V_70 ) ) )
return - V_18 ;
if ( V_75 == V_84 )
if ( F_8 ( & V_73 -> V_79 . V_83 , & V_11 -> V_79 . V_83 ,
sizeof( V_70 ) ) )
return - V_18 ;
if ( V_75 == V_81 )
if ( F_8 ( & V_73 -> V_79 . V_82 , & V_11 -> V_79 . V_82 ,
sizeof( int ) ) )
return - V_18 ;
return 0 ;
}
static int F_36 ( struct V_85 * V_9 , struct V_86 T_1 * V_11 )
{
struct V_72 T_1 * V_87 ;
struct V_71 T_1 * V_88 ;
T_2 V_25 ;
int V_4 ;
if ( ! F_3 ( V_12 , V_11 , sizeof( struct V_86 ) ) ||
F_5 ( V_9 -> V_65 , & V_11 -> V_65 ) ||
F_5 ( V_9 -> type , & V_11 -> type ) ||
F_5 ( V_9 -> V_89 , & V_11 -> V_89 ) ||
F_5 ( V_9 -> V_75 , & V_11 -> V_75 ) ||
F_5 ( V_9 -> V_90 , & V_11 -> V_90 ) )
return - V_18 ;
if ( F_37 ( V_9 -> type ) )
if ( F_5 ( V_9 -> V_91 , & V_11 -> V_91 ) ||
F_5 ( V_9 -> V_14 , & V_11 -> V_14 ) ||
F_5 ( V_9 -> V_92 . V_93 , & V_11 -> V_92 . V_93 ) ||
F_5 ( V_9 -> V_92 . V_94 ,
& V_11 -> V_92 . V_94 ) )
return - V_18 ;
if ( F_38 ( V_9 -> type ) ) {
unsigned int V_95 ;
if ( V_9 -> V_90 == 0 ) {
V_9 -> V_79 . V_96 = NULL ;
return 0 ;
} else if ( V_9 -> V_90 > V_97 ) {
return - V_19 ;
}
if ( F_5 ( V_25 , & V_11 -> V_79 . V_96 ) )
return - V_18 ;
V_87 = F_6 ( V_25 ) ;
if ( ! F_3 ( V_12 , V_87 ,
V_9 -> V_90 * sizeof( struct V_72 ) ) )
return - V_18 ;
V_88 = F_7 ( V_9 -> V_90 *
sizeof( struct V_71 ) ) ;
V_9 -> V_79 . V_96 = ( V_98 struct V_71 * ) V_88 ;
for ( V_95 = 0 ; V_95 < V_9 -> V_90 ; V_95 ++ ) {
V_4 = F_34 ( V_88 , V_87 , V_9 -> V_75 ) ;
if ( V_4 )
return V_4 ;
++ V_88 ;
++ V_87 ;
}
} else {
switch ( V_9 -> V_75 ) {
case V_84 :
if ( F_5 ( V_9 -> V_79 . V_99 , & V_11 -> V_79 . V_99 ) )
return - V_18 ;
break;
case V_78 :
{
T_3 V_100 ;
if ( F_5 ( V_100 , & V_11 -> V_79 . V_80 ) )
return - V_18 ;
V_9 -> V_79 . V_80 = ( unsigned long ) F_6 ( V_100 ) ;
}
break;
case V_101 :
if ( F_5 ( V_9 -> V_79 . V_99 , & V_11 -> V_79 . V_99 ) )
return - V_18 ;
break;
case V_81 :
if ( F_5 ( V_9 -> V_79 . V_82 , & V_11 -> V_79 . V_82 ) )
return - V_18 ;
break;
}
}
return 0 ;
}
static int F_39 ( struct V_85 * V_9 , struct V_86 T_1 * V_11 )
{
struct V_72 T_1 * V_87 ;
struct V_71 T_1 * V_88 ;
T_2 V_25 ;
int V_95 ;
int V_4 ;
if ( ! F_3 ( V_61 , V_11 , sizeof( struct V_86 ) ) ||
F_9 ( V_9 -> V_65 , & V_11 -> V_65 ) ||
F_9 ( V_9 -> type , & V_11 -> type ) ||
F_9 ( V_9 -> V_89 , & V_11 -> V_89 ) ||
F_9 ( V_9 -> V_75 , & V_11 -> V_75 ) )
return - V_18 ;
if ( F_9 ( V_9 -> V_91 , & V_11 -> V_91 ) ||
F_9 ( V_9 -> V_14 , & V_11 -> V_14 ) ||
F_9 ( V_9 -> V_92 . V_93 , & V_11 -> V_92 . V_93 ) ||
F_9 ( V_9 -> V_92 . V_94 , & V_11 -> V_92 . V_94 ) ||
F_11 ( & V_11 -> V_102 , & V_9 -> V_102 , sizeof( struct V_103 ) ) ||
F_9 ( V_9 -> V_104 , & V_11 -> V_104 ) ||
F_9 ( V_9 -> V_105 , & V_11 -> V_105 ) ||
F_9 ( V_9 -> V_62 , & V_11 -> V_62 ) ||
F_9 ( V_9 -> V_90 , & V_11 -> V_90 ) )
return - V_18 ;
if ( F_38 ( V_9 -> type ) ) {
V_95 = V_9 -> V_90 ;
if ( V_95 == 0 )
return 0 ;
V_88 = ( V_98 struct V_71 T_1 * ) V_9 -> V_79 . V_96 ;
if ( F_5 ( V_25 , & V_11 -> V_79 . V_96 ) )
return - V_18 ;
V_87 = F_6 ( V_25 ) ;
while ( -- V_95 >= 0 ) {
V_4 = F_35 ( V_88 , V_87 , V_9 -> V_75 ) ;
if ( V_4 )
return V_4 ;
++ V_88 ;
++ V_87 ;
}
} else {
switch ( V_9 -> V_75 ) {
case V_84 :
if ( F_9 ( V_9 -> V_79 . V_99 , & V_11 -> V_79 . V_99 ) )
return - V_18 ;
break;
case V_78 :
if ( F_9 ( V_9 -> V_79 . V_80 , & V_11 -> V_79 . V_80 ) )
return - V_18 ;
break;
case V_101 :
if ( F_9 ( V_9 -> V_79 . V_99 , & V_11 -> V_79 . V_99 ) )
return - V_18 ;
break;
case V_81 :
if ( F_9 ( V_9 -> V_79 . V_82 , & V_11 -> V_79 . V_82 ) )
return - V_18 ;
break;
}
}
return 0 ;
}
static int F_40 ( struct V_106 * V_9 , struct V_107 T_1 * V_11 )
{
T_4 V_100 ;
if ( ! F_3 ( V_12 , V_11 , sizeof( struct V_107 ) ) ||
F_5 ( V_100 , & V_11 -> V_108 ) ||
F_5 ( V_9 -> V_109 , & V_11 -> V_109 ) ||
F_5 ( V_9 -> V_89 , & V_11 -> V_89 ) ||
F_4 ( & V_9 -> V_39 , & V_11 -> V_39 , sizeof( V_11 -> V_39 ) ) )
return - V_18 ;
V_9 -> V_108 = ( V_98 void * ) F_6 ( V_100 ) ;
return 0 ;
}
static int F_41 ( struct V_106 * V_9 , struct V_107 T_1 * V_11 )
{
T_4 V_100 = ( T_4 ) ( ( unsigned long ) V_9 -> V_108 ) ;
if ( ! F_3 ( V_61 , V_11 , sizeof( struct V_107 ) ) ||
F_9 ( V_100 , & V_11 -> V_108 ) ||
F_9 ( V_9 -> V_109 , & V_11 -> V_109 ) ||
F_9 ( V_9 -> V_89 , & V_11 -> V_89 ) ||
F_11 ( & V_11 -> V_39 , & V_9 -> V_39 , sizeof( V_11 -> V_39 ) ) )
return - V_18 ;
return 0 ;
}
static inline int F_42 ( struct V_110 * V_9 , struct V_111 T_1 * V_11 )
{
if ( F_4 ( V_9 , V_11 , sizeof( struct V_111 ) ) )
return - V_18 ;
return 0 ;
}
static inline int F_43 ( struct V_110 * V_9 , struct V_111 T_1 * V_11 )
{
if ( F_11 ( V_11 , V_9 , sizeof( struct V_111 ) ) )
return - V_18 ;
return 0 ;
}
static inline int F_44 ( T_4 V_66 )
{
switch ( V_66 ) {
case V_112 :
case V_113 :
return 1 ;
default:
return 0 ;
}
}
static int F_45 ( struct V_114 * V_9 , struct V_115 T_1 * V_11 )
{
struct V_116 T_1 * V_117 ;
struct V_118 T_1 * V_119 ;
unsigned int V_24 ;
T_2 V_25 ;
if ( ! F_3 ( V_12 , V_11 , sizeof( struct V_115 ) ) ||
F_5 ( V_9 -> V_120 , & V_11 -> V_120 ) ||
F_5 ( V_9 -> V_121 , & V_11 -> V_121 ) ||
F_5 ( V_9 -> V_122 , & V_11 -> V_122 ) ||
F_4 ( V_9 -> V_62 , V_11 -> V_62 ,
sizeof( V_9 -> V_62 ) ) )
return - V_18 ;
if ( V_9 -> V_121 == 0 ) {
V_9 -> V_123 = NULL ;
return 0 ;
} else if ( V_9 -> V_121 > V_124 ) {
return - V_19 ;
}
if ( F_5 ( V_25 , & V_11 -> V_123 ) )
return - V_18 ;
V_117 = F_6 ( V_25 ) ;
if ( ! F_3 ( V_12 , V_117 ,
V_9 -> V_121 * sizeof( struct V_116 ) ) )
return - V_18 ;
V_119 = F_7 ( V_9 -> V_121 *
sizeof( struct V_118 ) ) ;
V_9 -> V_123 = ( V_98 struct V_118 * ) V_119 ;
for ( V_24 = 0 ; V_24 < V_9 -> V_121 ; V_24 ++ ) {
T_4 V_66 ;
if ( F_8 ( V_119 , V_117 , sizeof( * V_117 ) ) )
return - V_18 ;
if ( F_5 ( V_66 , & V_119 -> V_66 ) )
return - V_18 ;
if ( F_44 ( V_66 ) ) {
void T_1 * V_125 ;
if ( F_5 ( V_25 , & V_117 -> string ) )
return - V_18 ;
V_125 = F_6 ( V_25 ) ;
if ( F_9 ( V_125 , & V_119 -> string ) )
return - V_18 ;
}
V_117 ++ ;
V_119 ++ ;
}
return 0 ;
}
static int F_46 ( struct V_114 * V_9 , struct V_115 T_1 * V_11 )
{
struct V_116 T_1 * V_117 ;
struct V_118 T_1 * V_119 =
( V_98 struct V_118 T_1 * ) V_9 -> V_123 ;
int V_24 = V_9 -> V_121 ;
T_2 V_25 ;
if ( ! F_3 ( V_61 , V_11 , sizeof( struct V_115 ) ) ||
F_9 ( V_9 -> V_120 , & V_11 -> V_120 ) ||
F_9 ( V_9 -> V_121 , & V_11 -> V_121 ) ||
F_9 ( V_9 -> V_122 , & V_11 -> V_122 ) ||
F_11 ( V_11 -> V_62 , V_9 -> V_62 , sizeof( V_11 -> V_62 ) ) )
return - V_18 ;
if ( ! V_9 -> V_121 )
return 0 ;
if ( F_5 ( V_25 , & V_11 -> V_123 ) )
return - V_18 ;
V_117 = F_6 ( V_25 ) ;
if ( ! F_3 ( V_61 , V_117 ,
V_24 * sizeof( struct V_116 ) ) )
return - V_18 ;
while ( -- V_24 >= 0 ) {
unsigned V_126 = sizeof( * V_117 ) ;
T_4 V_66 ;
if ( F_5 ( V_66 , & V_119 -> V_66 ) )
return - V_18 ;
if ( F_44 ( V_66 ) )
V_126 -= sizeof( V_117 -> V_127 ) ;
if ( F_8 ( V_117 , V_119 , V_126 ) )
return - V_18 ;
V_117 ++ ;
V_119 ++ ;
}
return 0 ;
}
static int F_47 ( struct V_128 * V_9 , struct V_129 T_1 * V_11 )
{
if ( ! F_3 ( V_61 , V_11 , sizeof( struct V_129 ) ) ||
F_9 ( V_9 -> type , & V_11 -> type ) ||
F_11 ( & V_11 -> V_130 , & V_9 -> V_130 , sizeof( V_9 -> V_130 ) ) ||
F_9 ( V_9 -> V_131 , & V_11 -> V_131 ) ||
F_9 ( V_9 -> V_104 , & V_11 -> V_104 ) ||
F_9 ( V_9 -> V_92 . V_93 , & V_11 -> V_92 . V_93 ) ||
F_9 ( V_9 -> V_92 . V_132 , & V_11 -> V_92 . V_132 ) ||
F_9 ( V_9 -> V_66 , & V_11 -> V_66 ) ||
F_11 ( V_11 -> V_62 , V_9 -> V_62 , 8 * sizeof( V_70 ) ) )
return - V_18 ;
return 0 ;
}
static int F_48 ( struct V_133 * V_9 , struct V_134 T_1 * V_11 )
{
T_4 V_100 ;
if ( ! F_3 ( V_12 , V_11 , sizeof( struct V_134 ) ) ||
F_5 ( V_9 -> V_135 , & V_11 -> V_135 ) ||
F_5 ( V_9 -> V_136 , & V_11 -> V_136 ) ||
F_5 ( V_9 -> V_137 , & V_11 -> V_137 ) ||
F_5 ( V_100 , & V_11 -> V_138 ) ||
F_4 ( V_9 -> V_62 , V_11 -> V_62 , sizeof( V_9 -> V_62 ) ) )
return - V_18 ;
V_9 -> V_138 = ( V_98 V_139 * ) F_6 ( V_100 ) ;
return 0 ;
}
static int F_49 ( struct V_133 * V_9 , struct V_134 T_1 * V_11 )
{
T_4 V_100 = ( T_4 ) ( ( unsigned long ) V_9 -> V_138 ) ;
if ( ! F_3 ( V_61 , V_11 , sizeof( struct V_134 ) ) ||
F_9 ( V_9 -> V_135 , & V_11 -> V_135 ) ||
F_9 ( V_9 -> V_136 , & V_11 -> V_136 ) ||
F_9 ( V_9 -> V_137 , & V_11 -> V_137 ) ||
F_9 ( V_100 , & V_11 -> V_138 ) ||
F_11 ( V_11 -> V_62 , V_9 -> V_62 , sizeof( V_11 -> V_62 ) ) )
return - V_18 ;
return 0 ;
}
static long F_50 ( struct V_1 * V_1 , unsigned int V_2 , unsigned long V_3 )
{
union {
struct V_35 V_140 ;
struct V_85 V_141 ;
struct V_106 V_142 ;
struct V_110 V_143 ;
struct V_63 V_144 ;
struct V_114 V_145 ;
struct V_128 V_146 ;
struct V_58 V_147 ;
struct V_133 V_148 ;
unsigned long V_149 ;
int V_150 ;
} V_151 ;
void T_1 * V_11 = F_6 ( V_3 ) ;
int V_152 = 1 ;
long V_153 = 0 ;
switch ( V_2 ) {
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
case V_202 : V_2 = V_203 ; break;
}
switch ( V_2 ) {
case V_183 :
case V_185 :
case V_187 :
case V_191 :
case V_195 :
V_153 = F_5 ( V_151 . V_150 , ( V_204 T_1 * ) V_11 ) ;
V_152 = 0 ;
break;
case V_189 :
case V_193 :
V_152 = 0 ;
break;
case V_201 :
case V_203 :
V_153 = F_48 ( & V_151 . V_148 , V_11 ) ;
V_152 = 0 ;
break;
case V_155 :
case V_157 :
case V_173 :
V_153 = F_26 ( & V_151 . V_140 , V_11 ) ;
V_152 = 0 ;
break;
case V_197 :
V_153 = F_27 ( & V_151 . V_147 , V_11 ) ;
V_152 = 0 ;
break;
case V_199 :
case V_159 :
case V_165 :
case V_167 :
V_153 = F_36 ( & V_151 . V_141 , V_11 ) ;
V_152 = 0 ;
break;
case V_163 :
V_153 = F_40 ( & V_151 . V_142 , V_11 ) ;
V_152 = 0 ;
break;
case V_161 :
V_152 = 0 ;
break;
case V_169 :
V_153 = F_32 ( & V_151 . V_144 , V_11 ) ;
V_152 = 0 ;
break;
case V_171 :
V_153 = F_42 ( & V_151 . V_143 , V_11 ) ;
V_152 = 0 ;
break;
case V_175 :
case V_177 :
case V_179 :
V_153 = F_45 ( & V_151 . V_145 , V_11 ) ;
V_152 = 0 ;
break;
case V_181 :
V_152 = 0 ;
break;
}
if ( V_153 )
return V_153 ;
if ( V_152 )
V_153 = F_1 ( V_1 , V_2 , ( unsigned long ) V_11 ) ;
else {
T_5 V_205 = F_51 () ;
F_52 ( V_206 ) ;
V_153 = F_1 ( V_1 , V_2 , ( unsigned long ) & V_151 ) ;
F_52 ( V_205 ) ;
}
switch ( V_2 ) {
case V_175 :
case V_177 :
case V_179 :
if ( F_46 ( & V_151 . V_145 , V_11 ) )
V_153 = - V_18 ;
break;
case V_203 :
if ( F_49 ( & V_151 . V_148 , V_11 ) )
V_153 = - V_18 ;
break;
}
if ( V_153 )
return V_153 ;
switch ( V_2 ) {
case V_191 :
case V_195 :
case V_189 :
case V_193 :
V_153 = F_9 ( ( ( V_204 ) V_151 . V_150 ) , ( V_204 T_1 * ) V_11 ) ;
break;
case V_161 :
V_153 = F_41 ( & V_151 . V_142 , V_11 ) ;
break;
case V_181 :
V_153 = F_47 ( & V_151 . V_146 , V_11 ) ;
break;
case V_201 :
V_153 = F_49 ( & V_151 . V_148 , V_11 ) ;
break;
case V_155 :
case V_157 :
case V_173 :
V_153 = F_30 ( & V_151 . V_140 , V_11 ) ;
break;
case V_197 :
V_153 = F_31 ( & V_151 . V_147 , V_11 ) ;
break;
case V_159 :
case V_165 :
case V_167 :
V_153 = F_39 ( & V_151 . V_141 , V_11 ) ;
break;
case V_169 :
V_153 = F_33 ( & V_151 . V_144 , V_11 ) ;
break;
case V_171 :
V_153 = F_43 ( & V_151 . V_143 , V_11 ) ;
break;
}
return V_153 ;
}
long F_53 ( struct V_1 * V_1 , unsigned int V_2 , unsigned long V_3 )
{
struct V_207 * V_208 = F_54 ( V_1 ) ;
long V_4 = - V_5 ;
if ( ! V_1 -> V_6 -> V_7 )
return V_4 ;
if ( F_55 ( V_2 ) == 'V' && F_56 ( V_2 ) < V_209 )
V_4 = F_50 ( V_1 , V_2 , V_3 ) ;
else if ( V_208 -> V_210 -> V_211 )
V_4 = V_208 -> V_210 -> V_211 ( V_1 , V_2 , V_3 ) ;
if ( V_4 == - V_5 )
F_57 ( L_2 ,
F_55 ( V_2 ) , F_58 ( V_2 ) , F_56 ( V_2 ) , V_2 ) ;
return V_4 ;
}
