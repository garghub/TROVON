static bool
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_4 -> V_7 ) {
case V_8 :
if ( V_6 == NULL )
return false ;
return ( ( V_2 -> V_9 == V_4 -> V_9 ) &&
( V_2 -> V_10 == V_4 -> V_10 ) &&
( ( V_11 ) V_6 -> V_12 -> V_13 == V_4 -> V_14 ) ) ;
case V_15 :
return ( ( V_2 -> V_9 == V_4 -> V_9 ) &&
( V_2 -> V_10 == V_4 -> V_10 ) ) ;
case V_16 :
return ( V_2 -> V_9 == V_4 -> V_9 ) ;
case V_17 :
return true ;
default:
return false ;
}
}
static void
F_3 ( struct V_18 * V_19 ,
struct V_3 * V_4 ,
struct V_20 * V_21 )
{
struct V_20 * V_22 , * V_23 ;
if ( F_4 ( & V_19 -> V_24 ) )
return;
if ( V_4 -> V_7 == V_17 ) {
F_5 ( & V_19 -> V_24 , V_21 ) ;
return;
}
F_6 (tmp, next, &scm->active_q) {
if ( F_1 ( (struct V_1 * ) V_22 , V_4 ) ) {
F_7 ( V_22 ) ;
F_8 ( V_22 , V_21 ) ;
}
}
}
static inline bool
F_9 ( T_1 error )
{
switch ( error ) {
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
return 1 ;
}
return 0 ;
}
static inline void
F_10 ( struct V_1 * V_30 , void * V_31 )
{
struct V_32 * V_32 = (struct V_32 * ) V_31 ;
struct V_5 * V_6 = F_2 ( V_30 ) ;
if ( F_11 ( V_6 -> V_33 . V_34 == 0 ) ) {
F_12 ( V_6 -> V_12 -> V_13 , & V_32 -> V_35 ) ;
V_32 -> V_36 = 0 ;
V_32 -> V_37 = 0 ;
memcpy ( V_32 -> V_38 , V_6 -> V_39 , 16 ) ;
V_32 -> V_40 = V_41 ;
V_32 -> V_42 = F_13 ( F_14 ( V_6 ) ) ;
if ( V_30 -> V_43 )
if ( V_30 -> V_44 == V_45 )
V_32 -> V_46 = V_47 ;
else
V_32 -> V_46 = V_48 ;
else
V_32 -> V_46 = 0 ;
} else {
memset ( V_32 , 0 , sizeof( * V_32 ) ) ;
F_12 ( V_6 -> V_12 -> V_13 , & V_32 -> V_35 ) ;
V_32 -> V_36 = ( V_49 ) V_6 -> V_33 . V_34 ;
}
}
static inline void
F_15 ( struct V_1 * V_30 , void * V_31 , T_2 V_50 )
{
struct V_51 * V_52 = V_30 -> V_9 -> V_53 ;
struct V_54 * V_55 = V_30 -> V_10 ;
struct V_56 * V_57 = (struct V_56 * ) V_31 ;
struct V_58 * V_59 ;
V_49 V_60 = F_16 ( V_52 ) -> V_61 ;
V_57 -> V_62 = F_13 ( F_17 ( V_63 ) |
F_18 ( V_60 ) ) ;
V_57 -> V_64 = F_13 ( F_19 ( V_55 -> V_65 ) |
F_20 (
F_21 ( V_50 , 16 ) ) ) ;
V_57 -> V_66 = ( V_67 ) V_30 ;
V_57 -> V_68 = F_22 ( F_23 ( V_52 , V_30 -> V_69 ) ) ;
V_57 -> V_70 = ( V_49 ) V_30 -> V_71 ;
V_57 -> V_72 = 0 ;
memset ( & V_57 -> V_73 , 0 , 8 ) ;
V_59 = & V_30 -> V_59 ;
V_57 -> V_74 = F_13 ( V_59 -> V_75 ) ;
V_57 -> V_76 = F_24 ( V_59 -> V_77 ) ;
V_57 -> V_78 = 0 ;
V_57 -> V_79 . V_80 . V_81 = 0 ;
V_57 -> V_79 . V_80 . V_82 = 0 ;
V_57 -> V_79 . V_80 . V_83 [ 0 ] = 0 ;
V_57 -> V_79 . V_80 . V_83 [ 1 ] = 0 ;
F_10 ( V_30 , ( void * ) ( ( V_67 ) V_31 +
sizeof( struct V_56 ) ) ) ;
}
static inline void
F_25 ( struct V_1 * V_30 )
{
struct V_84 V_85 ;
struct V_51 * V_52 = V_30 -> V_9 -> V_53 ;
struct V_18 * V_86 = F_16 ( V_52 ) ;
T_2 V_50 = F_26 ( V_86 -> V_61 ) ;
V_30 -> V_87 = F_27 ( V_52 , V_30 -> V_88 , V_50 , & V_85 ) ;
if ( F_28 ( V_30 -> V_87 != 0 ) )
return;
if ( V_85 . V_89 >= V_50 ) {
F_15 ( V_30 , V_85 . V_90 , V_50 ) ;
} else {
V_49 * V_91 = F_29 ( V_52 , V_30 -> V_88 ) ;
F_15 ( V_30 , ( void * ) V_91 , V_50 ) ;
memcpy ( V_85 . V_90 , V_91 , V_85 . V_89 ) ;
memcpy ( V_85 . V_92 , V_91 + V_85 . V_89 , V_50 - V_85 . V_89 ) ;
}
}
static inline void
F_30 ( struct V_51 * V_52 , struct V_1 * V_30 ,
struct V_93 * V_94 )
{
struct V_95 * V_96 = NULL ;
struct V_97 * V_98 ;
T_2 V_99 = 0 ;
T_2 V_100 ;
struct V_20 * V_22 ;
struct V_58 * V_59 ;
struct V_5 * V_6 = F_2 ( V_30 ) ;
V_94 -> V_101 = F_31 ( F_32 ( V_102 ) | V_103 |
F_33 ( V_30 -> V_43 ) ) ;
if ( F_11 ( ! V_30 -> V_104 ) ) {
F_34 (scmnd, sgel, req->nsge, i) {
if ( V_99 == 0 ) {
V_94 -> V_105 = F_24 ( F_35 ( V_98 ) ) ;
V_94 -> V_106 = F_13 ( F_36 ( V_98 ) ) ;
V_96 = (struct V_95 * ) ( V_94 + 1 ) ;
continue;
}
if ( ( V_99 - 1 ) & 0x1 ) {
V_96 -> V_31 [ 1 ] = F_24 (
F_35 ( V_98 ) ) ;
V_96 -> V_75 [ 1 ] = F_13 (
F_36 ( V_98 ) ) ;
V_96 ++ ;
} else {
V_96 -> V_31 [ 0 ] = F_24 (
F_35 ( V_98 ) ) ;
V_96 -> V_75 [ 0 ] = F_13 (
F_36 ( V_98 ) ) ;
}
}
} else {
V_100 = F_14 ( V_6 ) ;
F_37 (tmp, &req->gen_list) {
V_59 = (struct V_58 * ) V_22 ;
if ( V_99 == 0 ) {
V_94 -> V_105 = F_24 ( V_59 -> V_77 ) ;
V_94 -> V_106 = F_13 (
F_38 ( V_100 , V_59 -> V_75 ) ) ;
V_96 = (struct V_95 * ) ( V_94 + 1 ) ;
} else if ( ( V_99 - 1 ) & 0x1 ) {
V_96 -> V_31 [ 1 ] = F_24 ( V_59 -> V_77 ) ;
V_96 -> V_75 [ 1 ] = F_13 (
F_38 ( V_100 , V_59 -> V_75 ) ) ;
V_96 ++ ;
} else {
V_96 -> V_31 [ 0 ] = F_24 ( V_59 -> V_77 ) ;
V_96 -> V_75 [ 0 ] = F_13 (
F_38 ( V_100 , V_59 -> V_75 ) ) ;
}
V_100 -= F_38 ( V_100 , V_59 -> V_75 ) ;
V_99 ++ ;
}
}
}
static inline void
F_39 ( struct V_1 * V_30 , void * V_85 , T_2 V_50 )
{
struct V_51 * V_52 = V_30 -> V_9 -> V_53 ;
struct V_54 * V_55 = V_30 -> V_10 ;
struct V_107 * V_57 = (struct V_107 * ) V_85 ;
struct V_93 * V_94 ;
struct V_58 * V_59 ;
V_49 V_60 = F_16 ( V_52 ) -> V_61 ;
struct V_5 * V_6 = F_2 ( V_30 ) ;
V_57 -> V_62 = F_13 ( F_17 ( V_108 ) |
F_40 ( V_60 ) ) ;
V_57 -> V_64 = F_13 ( F_19 ( V_55 -> V_65 ) |
F_20 ( F_21 ( V_50 , 16 ) ) ) ;
V_57 -> V_66 = ( V_67 ) V_30 ;
V_57 -> V_68 = F_22 ( F_23 ( V_52 , V_30 -> V_69 ) ) ;
V_57 -> V_70 = ( V_49 ) ( V_30 -> V_71 ) ;
V_57 -> V_109 = 1 ;
V_57 -> V_110 = F_13 ( F_14 ( V_6 ) ) ;
V_57 -> V_111 = F_13 ( F_14 ( V_6 ) ) ;
V_59 = & V_30 -> V_59 ;
V_57 -> V_74 = F_13 ( V_59 -> V_75 ) ;
V_57 -> V_76 = F_24 ( V_59 -> V_77 ) ;
V_57 -> V_112 = 0 ;
V_57 -> V_79 . V_80 . V_81 = 0 ;
V_57 -> V_79 . V_80 . V_82 = 0 ;
V_57 -> V_79 . V_80 . V_113 [ 0 ] = 0 ;
V_57 -> V_79 . V_80 . V_113 [ 1 ] = 0 ;
F_10 ( V_30 , ( void * ) ( ( V_67 ) V_85 +
sizeof( struct V_107 ) ) ) ;
V_94 = (struct V_93 * ) ( ( V_67 ) V_85 +
sizeof( struct V_107 ) + F_41 ( V_60 , 16 ) ) ;
F_30 ( V_52 , V_30 , V_94 ) ;
}
static inline void
F_42 ( struct V_1 * V_30 , void * V_85 , T_2 V_50 )
{
struct V_51 * V_52 = V_30 -> V_9 -> V_53 ;
struct V_54 * V_55 = V_30 -> V_10 ;
struct V_114 * V_57 = (struct V_114 * ) V_85 ;
struct V_93 * V_94 ;
struct V_58 * V_59 ;
V_49 V_60 = F_16 ( V_52 ) -> V_61 ;
struct V_5 * V_6 = F_2 ( V_30 ) ;
V_57 -> V_62 = F_13 ( F_17 ( V_115 ) |
F_43 ( V_60 ) ) ;
V_57 -> V_64 = F_13 ( F_19 ( V_55 -> V_65 ) |
F_20 ( F_21 ( V_50 , 16 ) ) ) ;
V_57 -> V_66 = ( V_67 ) V_30 ;
V_57 -> V_68 = F_22 ( F_23 ( V_52 , V_30 -> V_69 ) ) ;
V_57 -> V_70 = ( V_49 ) ( V_30 -> V_71 ) ;
V_57 -> V_109 = 1 ;
V_57 -> V_110 = F_13 ( F_14 ( V_6 ) ) ;
V_57 -> V_111 = F_13 ( F_14 ( V_6 ) ) ;
V_59 = & V_30 -> V_59 ;
V_57 -> V_74 = F_13 ( V_59 -> V_75 ) ;
V_57 -> V_76 = F_24 ( V_59 -> V_77 ) ;
V_57 -> V_112 = 0 ;
V_57 -> V_79 . V_80 . V_81 = 0 ;
V_57 -> V_79 . V_80 . V_82 = 0 ;
V_57 -> V_79 . V_80 . V_113 [ 0 ] = 0 ;
V_57 -> V_79 . V_80 . V_113 [ 1 ] = 0 ;
F_10 ( V_30 , ( void * ) ( ( V_67 ) V_85 +
sizeof( struct V_114 ) ) ) ;
V_94 = (struct V_93 * ) ( ( V_67 ) V_85 +
sizeof( struct V_114 ) + F_41 ( V_60 , 16 ) ) ;
F_30 ( V_52 , V_30 , V_94 ) ;
}
static inline void
F_44 ( struct V_1 * V_30 )
{
struct V_84 V_85 ;
T_2 V_50 ;
struct V_51 * V_52 = V_30 -> V_9 -> V_53 ;
struct V_18 * V_86 = F_16 ( V_52 ) ;
F_45 ( V_30 , V_116 , V_50 , V_86 -> V_61 ) ;
V_50 = F_41 ( V_50 , 16 ) ;
V_30 -> V_87 = F_27 ( V_52 , V_30 -> V_88 , V_50 , & V_85 ) ;
if ( F_11 ( V_30 -> V_87 == 0 ) ) {
if ( F_11 ( V_85 . V_89 >= V_50 ) ) {
F_39 ( V_30 , V_85 . V_90 , V_50 ) ;
} else {
V_49 * V_91 = F_29 ( V_52 , V_30 -> V_88 ) ;
F_39 ( V_30 , ( void * ) V_91 , V_50 ) ;
memcpy ( V_85 . V_90 , V_91 , V_85 . V_89 ) ;
memcpy ( V_85 . V_92 , V_91 + V_85 . V_89 , V_50 - V_85 . V_89 ) ;
}
}
}
static inline void
F_46 ( struct V_1 * V_30 )
{
struct V_84 V_85 ;
T_2 V_50 ;
struct V_51 * V_52 = V_30 -> V_9 -> V_53 ;
struct V_18 * V_86 = F_16 ( V_52 ) ;
F_45 ( V_30 , V_117 , V_50 , V_86 -> V_61 ) ;
V_50 = F_41 ( V_50 , 16 ) ;
V_30 -> V_87 = F_27 ( V_52 , V_30 -> V_88 , V_50 , & V_85 ) ;
if ( F_11 ( V_30 -> V_87 == 0 ) ) {
if ( F_11 ( V_85 . V_89 >= V_50 ) ) {
F_42 ( V_30 , V_85 . V_90 , V_50 ) ;
} else {
V_49 * V_91 = F_29 ( V_52 , V_30 -> V_88 ) ;
F_42 ( V_30 , ( void * ) V_91 , V_50 ) ;
memcpy ( V_85 . V_90 , V_91 , V_85 . V_89 ) ;
memcpy ( V_85 . V_92 , V_91 + V_85 . V_89 , V_50 - V_85 . V_89 ) ;
}
}
}
static inline void
F_47 ( struct V_18 * V_86 , struct V_1 * V_30 )
{
#ifdef F_48
struct V_51 * V_52 = V_30 -> V_9 -> V_53 ;
#endif
struct V_97 * V_98 = NULL ;
struct V_5 * V_6 = F_2 ( V_30 ) ;
V_11 V_118 = 0 ;
T_2 V_119 = 4096 ;
T_2 V_120 ;
struct V_58 * V_59 = NULL ;
T_2 V_121 = 0 ;
T_2 V_100 = 0 ;
T_2 V_122 = 0 ;
T_2 V_99 ;
F_34 (scmnd, sgel, req->nsge, i) {
V_118 = F_35 ( V_98 ) ;
V_122 = F_36 ( V_98 ) ;
V_120 = V_118 & ( V_119 - 1 ) ;
if ( V_99 != 0 && V_120 ) {
F_49 ( V_52 , L_1 ,
V_118 , V_122 ) ;
goto V_123;
}
if ( ( V_99 != ( V_30 -> V_43 - 1 ) ) &&
( ( V_120 + V_122 ) & ( V_119 - 1 ) ) ) {
F_49 ( V_52 ,
L_2
L_3 , V_118 , V_122 ) ;
goto V_123;
}
}
V_30 -> V_104 = 0 ;
F_44 ( V_30 ) ;
return;
V_123:
F_50 ( V_86 , V_124 ) ;
V_30 -> V_104 = 1 ;
F_51 ( & V_30 -> V_125 ) ;
V_100 = F_14 ( V_6 ) ;
V_99 = 0 ;
while ( V_121 < V_100 ) {
V_59 = F_52 ( V_86 ) ;
if ( V_59 == NULL || V_99 > V_86 -> V_126 ) {
V_30 -> V_87 = - V_127 ;
break;
}
V_121 += V_59 -> V_75 ;
F_8 ( & V_59 -> V_128 , & V_30 -> V_125 ) ;
V_99 ++ ;
}
if ( ! V_30 -> V_87 ) {
V_30 -> V_43 = V_99 ;
F_44 ( V_30 ) ;
return;
}
if ( V_99 > 0 )
F_53 ( V_86 , & V_30 -> V_125 , V_99 ) ;
}
static inline void
F_54 ( struct V_1 * V_30 , void * V_31 , T_2 V_50 ,
bool abort )
{
struct V_51 * V_52 = V_30 -> V_9 -> V_53 ;
struct V_54 * V_55 = V_30 -> V_10 ;
struct V_129 * V_57 = (struct V_129 * ) V_31 ;
V_57 -> V_62 = F_13 ( F_17 ( V_130 ) ) ;
V_57 -> V_64 = F_13 ( F_19 ( V_55 -> V_65 ) |
F_20 (
F_21 ( V_50 , 16 ) ) ) ;
V_57 -> V_66 = ( V_67 ) V_30 ;
V_57 -> V_68 = F_22 ( F_23 ( V_52 , V_30 -> V_69 ) ) ;
V_57 -> V_70 = ( V_49 ) V_30 -> V_71 ;
V_57 -> V_131 =
( F_55 ( abort ) |
F_56 ( 0 ) ) ;
V_57 -> V_72 [ 0 ] = 0 ;
V_57 -> V_72 [ 1 ] = 0 ;
V_57 -> V_72 [ 2 ] = 0 ;
V_57 -> V_72 [ 3 ] = 0 ;
V_57 -> V_132 = ( V_67 ) V_30 ;
}
static inline void
F_57 ( struct V_1 * V_30 , bool abort )
{
struct V_84 V_85 ;
struct V_51 * V_52 = V_30 -> V_9 -> V_53 ;
T_2 V_50 = F_41 ( sizeof( struct V_129 ) , 16 ) ;
V_30 -> V_87 = F_27 ( V_52 , V_30 -> V_88 , V_50 , & V_85 ) ;
if ( V_30 -> V_87 != 0 )
return;
if ( V_85 . V_89 >= V_50 ) {
F_54 ( V_30 , V_85 . V_90 , V_50 , abort ) ;
} else {
V_49 * V_91 = F_29 ( V_52 , V_30 -> V_88 ) ;
F_54 ( V_30 , ( void * ) V_91 , V_50 , abort ) ;
memcpy ( V_85 . V_90 , V_91 , V_85 . V_89 ) ;
memcpy ( V_85 . V_92 , V_91 + V_85 . V_89 , V_50 - V_85 . V_89 ) ;
}
}
static void
F_58 ( struct V_1 * V_30 , enum V_133 V_134 )
{
struct V_51 * V_52 = V_30 -> V_9 -> V_53 ;
struct V_18 * V_86 = F_16 ( V_52 ) ;
switch ( V_134 ) {
case V_135 :
if ( V_30 -> V_43 ) {
if ( V_30 -> V_44 == V_45 ) {
V_30 -> V_104 = 0 ;
F_46 ( V_30 ) ;
} else
F_47 ( V_86 , V_30 ) ;
} else {
F_25 ( V_30 ) ;
}
if ( F_11 ( V_30 -> V_87 == 0 ) ) {
F_59 ( & V_30 -> V_136 , V_137 ) ;
F_8 ( & V_30 -> V_136 . V_138 , & V_86 -> V_24 ) ;
F_60 ( V_52 , V_30 -> V_88 , false ) ;
F_50 ( V_86 , V_139 ) ;
return;
}
break;
case V_140 :
F_25 ( V_30 ) ;
if ( V_30 -> V_87 == 0 ) {
F_59 ( & V_30 -> V_136 , V_141 ) ;
F_8 ( & V_30 -> V_136 . V_138 , & V_86 -> V_24 ) ;
F_60 ( V_52 , V_30 -> V_88 , false ) ;
F_50 ( V_86 , V_142 ) ;
}
return;
case V_143 :
case V_144 :
V_30 -> V_87 = - V_145 ;
F_61 ( V_52 , L_4 , V_30 ) ;
break;
default:
F_49 ( V_52 , L_5 , V_134 , V_30 ) ;
F_62 ( 0 ) ;
}
}
static void
V_137 ( struct V_1 * V_30 , enum V_133 V_134 )
{
struct V_51 * V_52 = V_30 -> V_9 -> V_53 ;
struct V_18 * V_19 = F_16 ( V_52 ) ;
struct V_54 * V_55 ;
switch ( V_134 ) {
case V_146 :
F_63 ( V_19 , V_139 ) ;
F_7 ( & V_30 -> V_136 . V_138 ) ;
F_59 ( & V_30 -> V_136 , F_58 ) ;
if ( F_28 ( V_30 -> V_147 != V_148 ) ) {
V_55 = V_30 -> V_10 ;
if ( F_9 ( V_30 -> V_147 ) &&
F_64 ( V_55 ) ) {
F_59 ( & V_30 -> V_136 ,
V_149 ) ;
F_8 ( & V_30 -> V_136 . V_138 ,
& V_55 -> V_150 ) ;
}
}
break;
case V_143 :
F_57 ( V_30 , V_151 ) ;
if ( V_30 -> V_87 == 0 ) {
F_60 ( V_52 , V_30 -> V_88 , false ) ;
F_59 ( & V_30 -> V_136 , V_152 ) ;
}
break;
case V_144 :
F_57 ( V_30 , V_153 ) ;
if ( V_30 -> V_87 == 0 ) {
F_60 ( V_52 , V_30 -> V_88 , false ) ;
F_59 ( & V_30 -> V_136 , V_154 ) ;
}
break;
case V_155 :
V_30 -> V_147 = V_156 ;
F_63 ( V_19 , V_139 ) ;
F_59 ( & V_30 -> V_136 , F_58 ) ;
break;
default:
F_49 ( V_52 , L_5 , V_134 , V_30 ) ;
F_62 ( 0 ) ;
}
}
static void
V_141 ( struct V_1 * V_30 , enum V_133 V_134 )
{
struct V_51 * V_52 = V_30 -> V_9 -> V_53 ;
struct V_18 * V_19 = F_16 ( V_52 ) ;
switch ( V_134 ) {
case V_146 :
F_63 ( V_19 , V_142 ) ;
F_7 ( & V_30 -> V_136 . V_138 ) ;
F_59 ( & V_30 -> V_136 , F_58 ) ;
break;
case V_143 :
F_57 ( V_30 , V_151 ) ;
if ( V_30 -> V_87 == 0 ) {
F_60 ( V_52 , V_30 -> V_88 , false ) ;
F_59 ( & V_30 -> V_136 , V_152 ) ;
}
break;
case V_144 :
F_57 ( V_30 , V_153 ) ;
if ( V_30 -> V_87 == 0 ) {
F_60 ( V_52 , V_30 -> V_88 , false ) ;
F_59 ( & V_30 -> V_136 , V_154 ) ;
}
break;
case V_155 :
V_30 -> V_147 = V_156 ;
F_63 ( V_19 , V_142 ) ;
F_59 ( & V_30 -> V_136 , F_58 ) ;
break;
default:
F_49 ( V_52 , L_5 , V_134 , V_30 ) ;
F_62 ( 0 ) ;
}
}
static void
V_152 ( struct V_1 * V_30 , enum V_133 V_134 )
{
struct V_51 * V_52 = V_30 -> V_9 -> V_53 ;
struct V_18 * V_19 = F_16 ( V_52 ) ;
switch ( V_134 ) {
case V_146 :
F_49 ( V_52 ,
L_6
L_7 , V_30 , V_30 -> V_147 ) ;
V_30 -> V_87 = - V_157 ;
break;
case V_143 :
F_50 ( V_19 , V_158 ) ;
break;
case V_159 :
F_49 ( V_52 , L_8 ,
V_30 , V_30 -> V_147 , V_30 -> V_87 ) ;
if ( V_30 -> V_87 != - V_157 ) {
F_61 ( V_52 ,
L_9
L_10 , V_30 ) ;
F_62 ( 0 ) ;
}
if ( ( V_30 -> V_147 == V_148 ) ||
( V_30 -> V_147 == V_160 ) ||
F_9 ( V_30 -> V_147 ) )
V_30 -> V_147 = V_161 ;
F_63 ( V_19 , V_139 ) ;
F_7 ( & V_30 -> V_136 . V_138 ) ;
F_59 ( & V_30 -> V_136 , F_58 ) ;
break;
case V_155 :
V_30 -> V_147 = V_156 ;
F_63 ( V_19 , V_139 ) ;
F_59 ( & V_30 -> V_136 , F_58 ) ;
break;
case V_144 :
break;
default:
F_49 ( V_52 , L_5 , V_134 , V_30 ) ;
F_62 ( 0 ) ;
}
}
static void
V_154 ( struct V_1 * V_30 , enum V_133 V_134 )
{
struct V_51 * V_52 = V_30 -> V_9 -> V_53 ;
struct V_18 * V_19 = F_16 ( V_52 ) ;
switch ( V_134 ) {
case V_146 :
F_49 ( V_52 ,
L_6
L_11 , V_30 , V_30 -> V_147 ) ;
V_30 -> V_87 = - V_157 ;
break;
case V_162 :
if ( V_30 -> V_87 != - V_157 ) {
F_65 ( V_52 ,
L_12
L_10 , V_30 ) ;
F_62 ( 0 ) ;
}
F_62 ( ( V_30 -> V_147 == V_148 ) ||
( V_30 -> V_147 == V_160 ) ) ;
V_30 -> V_147 = V_163 ;
F_63 ( V_19 , V_139 ) ;
F_7 ( & V_30 -> V_136 . V_138 ) ;
F_59 ( & V_30 -> V_136 , F_58 ) ;
break;
case V_144 :
break;
case V_155 :
V_30 -> V_147 = V_156 ;
F_63 ( V_19 , V_139 ) ;
F_59 ( & V_30 -> V_136 , F_58 ) ;
break;
default:
F_49 ( V_52 , L_5 , V_134 , V_30 ) ;
F_62 ( 0 ) ;
}
}
static void
V_149 ( struct V_1 * V_30 , enum V_133 V_134 )
{
switch ( V_134 ) {
case V_143 :
case V_144 :
V_30 -> V_87 = 0 ;
break;
case V_155 :
F_59 ( & V_30 -> V_136 , F_58 ) ;
break;
default:
F_49 ( V_30 -> V_9 -> V_53 , L_5 ,
V_134 , V_30 ) ;
F_62 ( 0 ) ;
}
}
struct V_1 *
F_66 ( struct V_51 * V_52 , void * V_57 , T_2 V_75 ,
struct V_164 * V_165 , void * V_166 , V_49 * * V_167 )
{
struct V_1 * V_2 = NULL ;
struct V_168 * V_169 ;
V_49 * V_170 ;
V_49 V_171 ;
struct V_18 * V_19 = F_16 ( V_52 ) ;
V_169 = (struct V_168 * ) ( ( V_67 ) V_57 + sizeof( V_172 ) ) ;
if ( F_28 ( V_169 -> V_173 != V_174 ) ) {
F_61 ( V_52 , L_13 ,
V_169 -> V_173 ) ;
F_50 ( V_19 , V_175 ) ;
return NULL ;
}
V_170 = ( V_49 * ) ( V_169 -> V_176 ) ;
V_171 = F_67 ( V_170 ) ;
* V_167 = V_170 ;
if ( F_11 ( ( * V_170 == V_108 ) ||
( * V_170 == V_115 ) ||
( * V_170 == V_63 ) ) ) {
V_2 = (struct V_1 * ) ( ( V_67 )
( ( (struct V_107 * ) V_170 ) -> V_66 ) ) ;
F_62 ( F_68 ( V_2 ) ) ;
V_2 -> V_147 = V_171 ;
return V_2 ;
}
if ( * V_170 == V_130 ) {
V_2 = (struct V_1 * ) ( ( V_67 )
( ( (struct V_129 * ) V_170 ) -> V_66 ) ) ;
F_62 ( F_68 ( V_2 ) ) ;
V_2 -> V_147 = V_171 ;
return V_2 ;
}
F_61 ( V_52 , L_14 , * V_170 ) ;
F_50 ( V_19 , V_177 ) ;
return NULL ;
}
void
F_69 ( struct V_18 * V_19 , struct V_20 * V_178 )
{
struct V_51 * V_52 = V_19 -> V_52 ;
struct V_1 * V_2 ;
struct V_20 * V_22 , * V_23 ;
struct V_5 * V_6 ;
F_6 (tmp, next, q) {
V_2 = (struct V_1 * ) V_22 ;
F_70 ( V_2 ) ;
F_7 ( & V_2 -> V_136 . V_138 ) ;
V_6 = F_2 ( V_2 ) ;
F_71 ( & V_52 -> V_179 ) ;
if ( V_6 != NULL )
V_2 -> V_180 ( V_52 , V_2 ) ;
F_72 ( & V_19 -> V_181 ) ;
F_73 ( V_19 , V_2 ) ;
F_71 ( & V_19 -> V_181 ) ;
F_72 ( & V_52 -> V_179 ) ;
}
}
static void
F_74 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_182 * V_183 = V_2 -> V_9 ;
struct V_51 * V_52 = V_183 -> V_53 ;
int V_184 = 0 ;
struct V_18 * V_86 = F_16 ( V_52 ) ;
int V_185 ;
if ( F_2 ( V_2 ) != V_6 ) {
F_50 ( V_86 , V_186 ) ;
return;
}
V_184 = F_75 ( V_183 ) ;
V_185 = F_76 ( V_52 , V_2 , ( V_184 ? V_151 : V_153 ) ) ;
if ( V_185 != 0 ) {
if ( V_184 )
F_50 ( V_86 , V_187 ) ;
else
F_50 ( V_86 , V_188 ) ;
}
}
static int
F_77 ( struct V_18 * V_19 , struct V_20 * V_178 , T_2 V_71 )
{
struct V_51 * V_52 = V_19 -> V_52 ;
struct V_20 * V_22 , * V_23 ;
int V_189 = F_21 ( V_71 , V_190 ) ;
struct V_5 * V_6 ;
if ( F_4 ( V_178 ) )
return 0 ;
F_49 ( V_52 , L_15 ) ;
F_6 (tmp, next, q) {
V_6 = F_2 ( (struct V_1 * ) V_22 ) ;
F_74 ( (struct V_1 * ) V_22 , V_6 ) ;
}
while ( ! F_4 ( V_178 ) && V_189 -- ) {
F_71 ( & V_52 -> V_179 ) ;
F_78 ( V_190 ) ;
F_72 ( & V_52 -> V_179 ) ;
}
if ( F_4 ( V_178 ) )
return 0 ;
return - V_191 ;
}
int
F_79 ( struct V_18 * V_19 , bool abort )
{
struct V_51 * V_52 = V_19 -> V_52 ;
int V_185 = 0 ;
int V_189 = F_21 ( 60 * 1000 , V_190 ) ;
if ( F_4 ( & V_19 -> V_24 ) )
return 0 ;
while ( ! F_4 ( & V_19 -> V_24 ) && V_189 -- ) {
F_71 ( & V_52 -> V_179 ) ;
F_78 ( V_190 ) ;
F_72 ( & V_52 -> V_179 ) ;
}
if ( F_4 ( & V_19 -> V_24 ) )
return 0 ;
if ( abort ) {
V_185 = F_77 ( V_19 , & V_19 -> V_24 , 30000 ) ;
if ( V_185 == 0 )
return V_185 ;
F_49 ( V_52 , L_16 ) ;
}
F_69 ( V_19 , & V_19 -> V_24 ) ;
F_62 ( F_4 ( & V_19 -> V_24 ) ) ;
return V_185 ;
}
int
F_80 ( struct V_18 * V_19 , struct V_182 * V_183 )
{
struct V_51 * V_52 = V_19 -> V_52 ;
struct V_3 V_4 ;
int V_185 ;
int V_189 = F_21 ( 60 * 1000 , V_190 ) ;
F_49 ( V_52 , L_17 , V_183 ) ;
V_4 . V_7 = V_16 ;
V_4 . V_9 = V_183 ;
F_51 ( & V_183 -> V_192 ) ;
F_3 ( V_19 , & V_4 , & V_183 -> V_192 ) ;
if ( F_4 ( & V_183 -> V_192 ) )
return 0 ;
while ( ! F_4 ( & V_183 -> V_192 ) && V_189 -- ) {
F_71 ( & V_52 -> V_179 ) ;
F_78 ( V_190 ) ;
F_72 ( & V_52 -> V_179 ) ;
}
if ( F_4 ( & V_183 -> V_192 ) )
return 0 ;
F_49 ( V_52 , L_18 , V_183 ) ;
V_185 = F_77 ( V_19 , & V_183 -> V_192 , 30000 ) ;
if ( V_185 != 0 ) {
F_49 ( V_52 , L_16 ) ;
F_69 ( V_19 , & V_183 -> V_192 ) ;
}
F_62 ( F_4 ( & V_183 -> V_192 ) ) ;
return V_185 ;
}
static T_3
F_81 ( struct V_12 * V_193 ,
struct V_194 * V_195 , char * V_196 )
{
struct V_182 * V_183 = F_82 ( F_83 ( V_193 ) ) ;
struct V_51 * V_52 = F_84 ( V_183 ) ;
if ( F_85 ( V_52 ) )
return snprintf ( V_196 , V_197 , L_19 ) ;
else
return snprintf ( V_196 , V_197 , L_20 ) ;
}
static T_3
F_86 ( struct V_12 * V_193 ,
struct V_194 * V_195 , const char * V_196 , T_4 V_189 )
{
struct V_182 * V_183 = F_82 ( F_83 ( V_193 ) ) ;
struct V_51 * V_52 = F_84 ( V_183 ) ;
if ( * V_196 != '1' )
return - V_145 ;
F_87 ( V_52 , 1 ) ;
F_88 ( V_52 ) ;
F_72 ( & V_52 -> V_179 ) ;
F_89 ( V_52 ) ;
F_71 ( & V_52 -> V_179 ) ;
F_90 ( V_52 ) ;
return V_189 ;
}
static T_3
F_91 ( struct V_12 * V_193 ,
struct V_194 * V_195 , const char * V_196 , T_4 V_189 )
{
struct V_182 * V_183 = F_82 ( F_83 ( V_193 ) ) ;
struct V_51 * V_52 = F_84 ( V_183 ) ;
bool V_198 ;
if ( * V_196 == '1' || * V_196 == '0' )
V_198 = ( * V_196 == '1' ) ? true : false ;
else
return - V_145 ;
F_92 ( V_52 , V_183 -> V_199 ) ;
F_72 ( & V_52 -> V_179 ) ;
F_93 ( V_52 , V_183 -> V_199 , V_198 ) ;
F_71 ( & V_52 -> V_179 ) ;
F_94 ( V_52 , V_183 -> V_199 ) ;
return V_189 ;
}
static T_3
F_95 ( struct V_12 * V_193 ,
struct V_194 * V_195 , char * V_196 )
{
struct V_182 * V_183 = F_82 ( F_83 ( V_193 ) ) ;
return snprintf ( V_196 , V_197 , L_21 , V_183 -> V_200 . V_201 ) ;
}
static T_3
F_96 ( struct V_12 * V_193 ,
struct V_194 * V_195 , const char * V_196 , T_4 V_189 )
{
struct V_182 * V_183 = F_82 ( F_83 ( V_193 ) ) ;
struct V_51 * V_52 = F_84 ( V_183 ) ;
T_2 V_202 = 0 ;
if ( ! isdigit ( V_196 [ 0 ] ) )
return - V_145 ;
if ( sscanf ( V_196 , L_22 , & V_202 ) )
return - V_145 ;
V_183 -> V_200 . V_201 = V_202 ;
V_52 -> V_200 . V_201 = V_202 ;
return 0 ;
}
static T_3
F_97 ( struct V_12 * V_193 ,
struct V_194 * V_195 , char * V_196 )
{
struct V_182 * V_183 = F_82 ( F_83 ( V_193 ) ) ;
return snprintf ( V_196 , V_197 , L_23 , V_183 -> V_203 ) ;
}
static inline T_2
F_98 ( struct V_51 * V_52 , struct V_1 * V_30 )
{
struct V_5 * V_6 = (struct V_5 * ) F_2 ( V_30 ) ;
struct V_97 * V_204 ;
T_2 V_205 ;
T_2 V_206 ;
T_2 V_120 = 0 ;
T_2 V_207 = 0 ;
T_2 V_208 = 0 ;
void * V_118 ;
void * V_209 ;
struct V_58 * V_59 ;
V_205 = F_14 ( V_6 ) ;
V_204 = F_99 ( V_6 ) ;
V_59 = (struct V_58 * ) F_100 ( & V_30 -> V_125 ) ;
while ( V_205 > 0 && V_204 && V_59 ) {
if ( V_120 >= V_59 -> V_75 ) {
V_120 = 0 ;
V_59 = (struct V_58 * )
F_100 ( V_59 ) ;
continue;
}
if ( V_207 >= V_204 -> V_210 ) {
V_207 -= V_204 -> V_210 ;
V_204 = F_101 ( V_204 ) ;
continue;
}
V_209 = V_59 -> V_211 + V_120 ;
V_208 = V_204 -> V_212 + V_207 ;
V_206 = F_38 ( ( V_59 -> V_75 - V_120 ) ,
V_204 -> V_210 - V_207 ) ;
V_206 = F_38 ( ( T_2 ) ( V_197 - ( V_208 & ~ V_213 ) ) ,
V_206 ) ;
V_118 = F_102 ( F_103 ( V_204 ) + ( V_208 >> V_214 ) ) ;
if ( ! V_118 ) {
F_104 ( V_52 , L_24 ,
V_204 , V_30 ) ;
break;
}
F_49 ( V_52 , L_25 ,
V_118 , V_208 , V_209 , V_206 ) ;
memcpy ( V_118 + ( V_208 & ~ V_213 ) , V_209 , V_206 ) ;
F_105 ( V_118 ) ;
V_207 += V_206 ;
V_120 += V_206 ;
V_205 -= V_206 ;
}
if ( V_205 > 0 )
return V_215 ;
else
return V_216 ;
}
static inline void
F_106 ( struct V_51 * V_52 , struct V_1 * V_30 )
{
struct V_5 * V_39 = (struct V_5 * ) F_2 ( V_30 ) ;
struct V_18 * V_19 = F_16 ( V_52 ) ;
struct V_217 * V_218 ;
struct V_219 * V_220 ;
struct V_58 * V_59 ;
V_49 V_221 , V_222 = 0 ;
T_2 V_223 = V_216 ;
T_2 V_224 = 0 , V_225 = 0 ;
struct V_54 * V_55 = (struct V_54 * ) ( V_39 -> V_12 -> V_226 ) ;
switch ( V_30 -> V_147 ) {
case V_156 :
if ( F_28 ( ! F_85 ( V_52 ) ) )
return;
V_223 = V_215 ;
F_50 ( V_19 , V_227 ) ;
break;
case V_228 :
V_59 = & V_30 -> V_59 ;
V_218 = (struct V_217 * ) V_59 -> V_211 ;
V_220 = (struct V_219 * ) ( V_218 + 1 ) ;
V_221 = V_218 -> V_229 . V_230 ;
V_222 = V_218 -> V_229 . V_231 ;
if ( V_221 & V_232 ) {
V_224 = F_107 ( V_218 -> V_233 . V_234 ) ;
if ( ( V_224 != 0 && V_224 != 4 && V_224 != 8 ) ||
( V_220 -> V_235 != V_236 ) ) {
V_223 = V_215 ;
goto V_237;
}
}
if ( ( V_221 & V_238 ) && V_218 -> V_233 . V_239 ) {
V_225 = F_107 ( V_218 -> V_233 . V_239 ) ;
if ( V_225 > V_240 )
V_225 = V_240 ;
memcpy ( V_39 -> V_241 ,
& V_220 -> V_242 [ 0 ] + V_224 , V_225 ) ;
F_50 ( V_19 , V_243 ) ;
}
F_108 ( V_39 , 0 ) ;
if ( V_221 & V_244 ) {
F_108 ( V_39 ,
F_107 ( V_218 -> V_233 . V_245 ) ) ;
if ( ! ( V_221 & V_238 ) &&
( V_222 == V_246 ) &&
( ( F_14 ( V_39 ) - F_109 ( V_39 ) )
< V_39 -> V_247 ) )
V_223 = V_215 ;
} else if ( V_221 & V_248 )
V_223 = V_215 ;
F_50 ( V_19 , V_249 ) ;
break;
case V_250 :
F_61 ( V_52 ,
L_26
L_27 , V_39 -> V_39 [ 0 ] ,
F_14 ( V_39 ) , F_109 ( V_39 ) ) ;
V_223 = V_215 ;
F_50 ( V_19 , V_251 ) ;
break;
case V_252 :
F_61 ( V_52 ,
L_28
L_29 ,
V_39 -> V_39 [ 0 ] , F_14 ( V_39 ) ,
F_109 ( V_39 ) , V_39 -> V_12 -> V_13 ,
V_55 -> V_65 ) ;
V_223 = V_215 ;
F_50 ( V_19 , V_253 ) ;
break;
case V_161 :
case V_254 :
case V_163 :
F_49 ( V_52 , L_30 , V_30 , V_39 ,
V_39 -> V_39 [ 0 ] ,
( V_30 -> V_147 == V_163 ) ?
L_31 : L_32 ) ;
V_223 = V_255 ;
if ( V_30 -> V_147 == V_163 )
F_50 ( V_19 , V_256 ) ;
else
F_50 ( V_19 , V_257 ) ;
break;
case V_258 :
F_49 ( V_52 , L_33 ,
V_30 , V_39 , V_30 -> V_147 ) ;
V_223 = V_215 ;
F_50 ( V_19 , V_259 ) ;
break;
case V_26 :
F_50 ( V_19 , V_260 ) ;
V_223 = V_215 ;
break;
case V_27 :
F_50 ( V_19 , V_261 ) ;
V_223 = V_215 ;
break;
case V_28 :
F_50 ( V_19 , V_262 ) ;
V_223 = V_215 ;
break;
case V_29 :
V_223 = V_215 ;
break;
case V_25 :
F_50 ( V_19 , V_263 ) ;
V_223 = V_215 ;
break;
case V_264 :
F_50 ( V_19 , V_265 ) ;
V_223 = V_215 ;
break;
default:
F_104 ( V_52 , L_34 ,
V_30 -> V_147 , V_30 , V_39 ) ;
F_62 ( 0 ) ;
F_50 ( V_19 , V_266 ) ;
V_223 = V_215 ;
break;
}
V_237:
if ( V_30 -> V_43 > 0 )
F_110 ( V_39 ) ;
V_39 -> V_267 = ( ( ( V_223 ) << 16 ) | V_222 ) ;
V_39 -> V_268 ( V_39 ) ;
F_2 ( V_30 ) = NULL ;
F_111 ( & V_30 -> V_269 ) ;
}
static void
F_112 ( struct V_51 * V_52 , struct V_1 * V_30 )
{
struct V_5 * V_39 = (struct V_5 * ) F_2 ( V_30 ) ;
V_49 V_222 = V_246 ;
T_2 V_223 = V_216 ;
if ( F_11 ( V_30 -> V_147 == V_148 ) ) {
if ( V_30 -> V_43 > 0 ) {
F_110 ( V_39 ) ;
if ( V_30 -> V_104 )
V_223 = F_98 ( V_52 , V_30 ) ;
}
V_39 -> V_267 = ( ( ( V_223 ) << 16 ) | V_222 ) ;
V_39 -> V_268 ( V_39 ) ;
F_2 ( V_30 ) = NULL ;
F_50 ( F_16 ( V_52 ) , V_270 ) ;
} else {
F_106 ( V_52 , V_30 ) ;
}
}
static int
F_113 ( struct V_271 * V_272 , struct V_5 * V_39 )
{
struct V_182 * V_183 = F_82 ( V_272 ) ;
struct V_51 * V_52 = F_84 ( V_183 ) ;
struct V_18 * V_86 = F_16 ( V_52 ) ;
struct V_54 * V_55 = (struct V_54 * ) ( V_39 -> V_12 -> V_226 ) ;
struct V_1 * V_2 = NULL ;
unsigned long V_221 ;
int V_43 = 0 ;
int V_185 = V_273 , V_274 ;
int V_275 ;
int V_276 ;
struct V_277 * V_278 ;
struct V_279 * V_280 = F_114 ( F_115 ( V_39 -> V_12 ) ) ;
if ( ! F_116 ( V_39 -> V_281 ) )
V_276 = F_117 () ;
else
V_276 = V_39 -> V_281 -> V_276 ;
V_278 = & V_52 -> V_278 [ V_183 -> V_199 ] [ V_276 ] ;
V_274 = F_118 ( V_280 ) ;
if ( V_274 ) {
V_39 -> V_267 = V_274 ;
F_50 ( V_86 , V_282 ) ;
goto V_283;
}
if ( F_28 ( ! F_85 ( V_52 ) ) ) {
V_39 -> V_267 = ( V_255 << 16 ) ;
F_50 ( V_86 , V_284 ) ;
goto V_283;
}
V_43 = F_119 ( V_39 ) ;
if ( F_28 ( V_43 < 0 ) ) {
F_50 ( V_86 , V_285 ) ;
goto V_286;
}
if ( F_28 ( V_43 > V_86 -> V_126 ) ) {
F_61 ( V_52 ,
L_35
L_36 , V_43 , V_86 -> V_126 ) ;
F_50 ( V_86 , V_287 ) ;
goto V_288;
}
V_2 = F_120 ( V_52 , V_86 ) ;
if ( ! V_2 ) {
F_104 ( V_52 , L_37 ,
V_86 -> V_289 . V_139 ) ;
F_50 ( V_86 , V_290 ) ;
goto V_288;
}
V_2 -> V_43 = V_43 ;
V_2 -> V_9 = V_183 ;
V_2 -> V_10 = V_55 ;
V_2 -> V_69 = V_278 -> V_69 ;
V_2 -> V_88 = V_278 -> V_88 ;
V_2 -> V_147 = 0 ;
V_2 -> V_87 = 0 ;
F_2 ( V_2 ) = ( void * ) V_39 ;
V_2 -> V_71 = 0 ;
V_2 -> V_44 = V_39 -> V_291 ;
if ( V_39 -> V_291 == V_45 ) {
F_50 ( V_183 , V_292 ) ;
V_183 -> V_289 . V_293 += F_14 ( V_39 ) ;
} else if ( V_39 -> V_291 == V_294 ) {
F_50 ( V_183 , V_295 ) ;
V_183 -> V_289 . V_296 += F_14 ( V_39 ) ;
} else
F_50 ( V_183 , V_297 ) ;
V_2 -> V_180 = F_112 ;
V_39 -> V_298 = ( unsigned char * ) V_2 ;
V_39 -> V_33 . V_34 = 0 ;
F_121 ( & V_52 -> V_179 , V_221 ) ;
V_275 = F_122 ( V_2 ) ;
F_123 ( & V_52 -> V_179 , V_221 ) ;
if ( V_275 != 0 ) {
F_104 ( V_52 , L_38 ,
V_2 , V_275 ) ;
F_50 ( V_86 , V_299 ) ;
goto V_300;
}
return 0 ;
V_300:
F_124 ( V_52 , V_86 , V_2 ) ;
V_288:
if ( V_43 > 0 )
F_110 ( V_39 ) ;
V_286:
return V_185 ;
V_283:
V_39 -> V_268 ( V_39 ) ;
return 0 ;
}
static int
F_76 ( struct V_51 * V_52 , struct V_1 * V_2 , bool abort )
{
int V_185 ;
int V_276 = F_117 () ;
struct V_182 * V_183 = V_2 -> V_9 ;
struct V_277 * V_278 = & V_52 -> V_278 [ V_183 -> V_199 ] [ V_276 ] ;
V_2 -> V_71 = V_301 ;
V_2 -> V_88 = V_278 -> V_88 ;
if ( abort == V_151 )
V_185 = F_125 ( V_2 ) ;
else
V_185 = F_126 ( V_2 ) ;
return V_185 ;
}
static int
F_127 ( struct V_5 * V_39 )
{
struct V_1 * V_2 ;
struct V_182 * V_183 = F_82 ( V_39 -> V_12 -> V_272 ) ;
struct V_51 * V_52 = F_84 ( V_183 ) ;
struct V_18 * V_86 = F_16 ( V_52 ) ;
int V_184 = 0 , V_302 ;
unsigned long V_71 = 0 ;
int V_185 ;
struct V_54 * V_55 = (struct V_54 * ) ( V_39 -> V_12 -> V_226 ) ;
V_302 = F_128 ( V_39 ) ;
if ( V_302 )
return V_302 ;
V_2 = (struct V_1 * ) V_39 -> V_298 ;
if ( ! V_2 )
return V_303 ;
if ( ! V_55 )
return V_304 ;
F_49 ( V_52 ,
L_39
L_40 ,
V_2 , V_39 , * ( ( V_11 * ) V_39 -> V_39 ) , V_55 -> V_65 ,
V_39 -> V_12 -> V_13 , F_23 ( V_52 , V_2 -> V_69 ) ) ;
if ( ( (struct V_5 * ) F_2 ( V_2 ) ) != V_39 ) {
F_50 ( V_86 , V_186 ) ;
return V_303 ;
}
V_184 = F_75 ( V_183 ) ;
V_71 = V_301 ;
F_72 ( & V_52 -> V_179 ) ;
V_185 = F_76 ( V_52 , V_2 , ( V_184 ? V_151 : V_153 ) ) ;
F_71 ( & V_52 -> V_179 ) ;
if ( V_185 != 0 ) {
if ( V_185 == - V_145 ) {
return V_303 ;
}
if ( V_184 )
F_50 ( V_86 , V_187 ) ;
else
F_50 ( V_86 , V_188 ) ;
goto V_305;
}
F_129 ( & V_2 -> V_269 ) ;
F_130 ( & V_2 -> V_269 , F_131 ( V_71 ) ) ;
if ( ( (struct V_5 * ) F_2 ( V_2 ) ) == V_39 ) {
F_104 ( V_52 , L_41 , V_2 ) ;
F_50 ( V_86 , V_259 ) ;
V_305:
if ( V_2 -> V_43 > 0 )
F_110 ( V_39 ) ;
F_72 ( & V_52 -> V_179 ) ;
F_2 ( V_2 ) = NULL ;
F_71 ( & V_52 -> V_179 ) ;
V_39 -> V_267 = ( V_215 << 16 ) ;
V_39 -> V_268 ( V_39 ) ;
return V_304 ;
}
if ( F_132 ( V_39 -> V_267 ) == V_255 ) {
F_133 ( V_52 ,
L_42 ,
V_39 -> V_12 -> V_306 , V_39 -> V_12 -> V_13 ,
V_39 -> V_307 ) ;
return V_303 ;
} else {
F_133 ( V_52 ,
L_43 ,
V_39 -> V_12 -> V_306 , V_39 -> V_12 -> V_13 ,
V_39 -> V_307 ) ;
return V_304 ;
}
}
static void
F_134 ( struct V_51 * V_52 , struct V_1 * V_30 )
{
struct V_5 * V_39 = (struct V_5 * ) F_2 ( V_30 ) ;
struct V_58 * V_59 ;
V_49 V_221 = 0 ;
struct V_217 * V_218 ;
struct V_219 * V_220 ;
F_49 ( V_52 , L_44 ,
V_30 , V_30 -> V_147 ) ;
V_39 -> V_33 . V_308 = V_30 -> V_147 ;
if ( V_30 -> V_147 == V_228 ) {
V_59 = & V_30 -> V_59 ;
V_218 = (struct V_217 * ) V_59 -> V_211 ;
V_220 = (struct V_219 * ) ( V_218 + 1 ) ;
V_221 = V_218 -> V_229 . V_230 ;
if ( V_221 & V_232 )
if ( V_220 -> V_235 == V_236 )
V_39 -> V_33 . V_308 = V_148 ;
F_49 ( V_52 , L_45 , V_220 -> V_235 ) ;
}
F_2 ( V_30 ) = NULL ;
}
static int
F_135 ( struct V_5 * V_39 )
{
struct V_182 * V_183 = F_82 ( V_39 -> V_12 -> V_272 ) ;
struct V_51 * V_52 = F_84 ( V_183 ) ;
struct V_18 * V_86 = F_16 ( V_52 ) ;
struct V_54 * V_55 = (struct V_54 * ) ( V_39 -> V_12 -> V_226 ) ;
struct V_1 * V_2 = NULL ;
struct V_277 * V_278 ;
unsigned long V_221 ;
int V_275 ;
int V_189 , V_302 ;
F_136 ( V_309 ) ;
struct V_3 V_4 ;
if ( ! V_55 )
goto V_310;
F_49 ( V_52 , L_46 ,
V_39 -> V_12 -> V_13 , V_55 -> V_65 , V_55 -> V_311 ) ;
if ( ! F_75 ( V_183 ) ) {
F_104 ( V_52 ,
L_47
L_48 ,
V_183 -> V_312 , V_39 -> V_12 -> V_13 ) ;
goto V_310;
}
V_302 = F_128 ( V_39 ) ;
if ( V_302 )
return V_302 ;
if ( F_118 ( V_55 -> V_280 ) ) {
F_104 ( V_52 ,
L_47
L_49 ,
V_55 -> V_65 , V_39 -> V_12 -> V_13 ) ;
goto V_310;
}
V_2 = F_120 ( V_52 , V_86 ) ;
if ( ! V_2 ) {
F_104 ( V_52 , L_50 ,
V_86 -> V_289 . V_139 ) ;
goto V_310;
}
V_278 = & V_52 -> V_278 [ V_183 -> V_199 ] [ F_117 () ] ;
V_2 -> V_43 = 0 ;
V_2 -> V_9 = V_183 ;
V_2 -> V_10 = V_55 ;
V_2 -> V_69 = V_278 -> V_69 ;
V_2 -> V_88 = V_278 -> V_88 ;
F_2 ( V_2 ) = V_39 ;
V_39 -> V_298 = ( unsigned char * ) V_2 ;
V_39 -> V_33 . V_308 = 0 ;
V_39 -> V_33 . V_34 = V_313 ;
V_2 -> V_71 = V_314 / 1000 ;
V_189 = F_21 ( ( V_2 -> V_71 + 10 ) * 1000 , V_315 ) ;
V_2 -> V_180 = F_134 ;
V_4 . V_7 = V_8 ;
V_4 . V_9 = V_2 -> V_9 ;
V_4 . V_10 = V_2 -> V_10 ;
V_4 . V_14 = V_39 -> V_12 -> V_13 ;
F_121 ( & V_52 -> V_179 , V_221 ) ;
V_275 = F_137 ( V_2 ) ;
F_123 ( & V_52 -> V_179 , V_221 ) ;
if ( V_275 != 0 ) {
F_104 ( V_52 , L_51 ,
V_2 , V_275 ) ;
goto V_316;
}
F_49 ( V_52 , L_52 ,
V_189 * ( V_315 / 1000 ) ) ;
while ( ( ( (struct V_5 * ) F_2 ( V_2 ) ) == V_39 )
&& V_189 -- )
F_78 ( V_315 ) ;
if ( ( (struct V_5 * ) F_2 ( V_2 ) ) == V_39 ) {
F_104 ( V_52 , L_53 ,
V_39 -> V_12 -> V_306 , V_39 -> V_12 -> V_13 ) ;
F_72 ( & V_52 -> V_179 ) ;
F_70 ( V_2 ) ;
F_7 ( & V_2 -> V_136 . V_138 ) ;
F_71 ( & V_52 -> V_179 ) ;
goto V_316;
}
if ( V_39 -> V_33 . V_308 != V_148 ) {
F_104 ( V_52 , L_54 ,
V_39 -> V_12 -> V_306 , V_39 -> V_12 -> V_13 , V_39 -> V_33 . V_308 ) ;
goto V_310;
}
F_72 ( & V_52 -> V_179 ) ;
F_3 ( V_86 , & V_4 , & V_309 ) ;
V_275 = F_77 ( V_86 , & V_309 , 30000 ) ;
F_71 ( & V_52 -> V_179 ) ;
if ( V_275 != 0 ) {
F_104 ( V_52 ,
L_55
L_56 , V_39 -> V_12 -> V_13 , V_275 ) ;
F_72 ( & V_52 -> V_179 ) ;
F_5 ( & V_309 , & V_86 -> V_24 ) ;
F_71 ( & V_52 -> V_179 ) ;
goto V_310;
}
F_50 ( V_55 , V_317 ) ;
F_133 ( V_52 , L_57 ,
V_39 -> V_12 -> V_306 , V_39 -> V_12 -> V_13 ) ;
return V_303 ;
V_316:
F_124 ( V_52 , V_86 , V_2 ) ;
V_310:
F_50 ( V_55 , V_318 ) ;
return V_304 ;
}
static int
F_138 ( struct V_319 * V_320 )
{
struct V_279 * V_280 = F_114 ( F_115 ( V_320 ) ) ;
if ( ! V_280 || F_118 ( V_280 ) )
return - V_321 ;
V_320 -> V_226 = * ( (struct V_182 * * ) ( V_280 -> V_322 ) ) ;
return 0 ;
}
static int
F_139 ( struct V_319 * V_320 )
{
F_140 ( V_320 , V_323 ) ;
return 0 ;
}
static void
F_141 ( struct V_319 * V_320 )
{
V_320 -> V_226 = NULL ;
}
static int
F_142 ( struct V_271 * V_324 , unsigned long time )
{
struct V_182 * V_183 = F_82 ( V_324 ) ;
int V_185 = 1 ;
F_72 ( V_324 -> V_325 ) ;
if ( ! V_183 -> V_53 || F_143 ( & V_183 -> V_136 . V_138 ) )
goto V_237;
V_185 = F_144 ( V_183 , V_326 , time , V_327 * V_328 ,
V_329 * V_328 ) ;
V_237:
F_71 ( V_324 -> V_325 ) ;
return V_185 ;
}
static int
F_145 ( struct V_18 * V_19 , struct V_51 * V_52 ,
int V_330 , int V_331 )
{
int V_332 = 0 ;
struct V_20 * V_22 ;
struct V_58 * V_333 = NULL ;
T_2 V_334 = 0 ;
if ( ! V_331 )
return 0 ;
if ( ! V_330 )
return - V_145 ;
F_51 ( & V_19 -> V_335 ) ;
V_330 = ( V_330 + V_197 - 1 ) & V_213 ;
for ( V_332 = 0 ; V_332 < V_331 ; V_332 ++ ) {
V_334 = V_330 ;
V_333 = F_146 ( sizeof( struct V_58 ) , V_336 ) ;
if ( ! V_333 ) {
F_104 ( V_52 ,
L_58
L_59 ,
V_19 -> V_289 . V_337 ) ;
goto V_338;
}
V_333 -> V_211 = F_147 ( V_52 -> V_339 , V_334 ,
& V_333 -> V_77 ) ;
if ( ! V_333 -> V_211 ) {
F_104 ( V_52 ,
L_60
L_61 ) ;
F_148 ( V_333 ) ;
goto V_338;
}
V_333 -> V_75 = V_334 ;
F_8 ( & V_333 -> V_128 , & V_19 -> V_335 ) ;
F_50 ( V_19 , V_337 ) ;
}
return 0 ;
V_338:
F_37 (tmp, &scm->ddp_freelist) {
V_333 = (struct V_58 * ) V_22 ;
V_22 = F_149 ( V_22 ) ;
F_150 ( V_52 -> V_339 , V_333 -> V_75 , V_333 -> V_211 ,
V_333 -> V_77 ) ;
F_7 ( & V_333 -> V_128 ) ;
F_148 ( V_333 ) ;
}
V_19 -> V_289 . V_337 = 0 ;
return - V_340 ;
}
static void
F_151 ( struct V_18 * V_19 , struct V_51 * V_52 )
{
struct V_20 * V_22 ;
struct V_58 * V_333 ;
F_37 (tmp, &scm->ddp_freelist) {
V_333 = (struct V_58 * ) V_22 ;
V_22 = F_149 ( V_22 ) ;
F_150 ( V_52 -> V_339 , V_333 -> V_75 , V_333 -> V_211 ,
V_333 -> V_77 ) ;
F_7 ( & V_333 -> V_128 ) ;
F_148 ( V_333 ) ;
}
V_19 -> V_289 . V_337 = 0 ;
}
int
F_152 ( struct V_18 * V_19 , struct V_51 * V_52 )
{
int V_99 ;
struct V_1 * V_2 ;
struct V_58 * V_59 ;
F_51 ( & V_19 -> V_24 ) ;
V_19 -> V_52 = V_52 ;
V_19 -> V_61 = sizeof( struct V_32 ) ;
V_19 -> V_341 = V_342 ;
V_19 -> V_126 = V_343 ;
F_153 ( & V_19 -> V_181 ) ;
F_51 ( & V_19 -> V_344 ) ;
for ( V_99 = 0 ; V_99 < V_345 ; V_99 ++ ) {
V_2 = F_146 ( sizeof( struct V_1 ) , V_336 ) ;
if ( ! V_2 ) {
F_104 ( V_52 ,
L_62
L_59 ,
V_19 -> V_289 . V_346 ) ;
goto V_347;
}
V_59 = & V_2 -> V_59 ;
V_59 -> V_211 = F_154 ( V_52 -> V_348 , V_336 ,
& V_59 -> V_77 ) ;
if ( ! V_59 -> V_211 ) {
F_104 ( V_52 ,
L_63
L_61 ) ;
F_148 ( V_2 ) ;
goto V_347;
}
V_59 -> V_75 = V_19 -> V_341 ;
F_155 ( & V_2 -> V_136 , F_58 ) ;
F_51 ( & V_2 -> V_125 ) ;
F_129 ( & V_2 -> V_269 ) ;
F_8 ( & V_2 -> V_136 . V_138 , & V_19 -> V_344 ) ;
F_50 ( V_19 , V_346 ) ;
}
if ( F_145 ( V_19 , V_52 , V_197 , V_349 ) )
goto V_347;
return 0 ;
V_347:
while ( ! F_4 ( & V_19 -> V_344 ) ) {
struct V_350 * V_22 ;
V_22 = F_156 ( & V_19 -> V_344 ,
struct V_350 , V_138 ) ;
F_7 ( & V_22 -> V_138 ) ;
V_2 = (struct V_1 * ) V_22 ;
V_59 = & V_2 -> V_59 ;
F_157 ( V_52 -> V_348 , V_59 -> V_211 ,
V_59 -> V_77 ) ;
F_148 ( V_2 ) ;
}
V_19 -> V_289 . V_346 = 0 ;
return - V_340 ;
}
void
F_158 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
struct V_58 * V_59 ;
while ( ! F_4 ( & V_19 -> V_344 ) ) {
struct V_350 * V_22 ;
V_22 = F_156 ( & V_19 -> V_344 ,
struct V_350 , V_138 ) ;
F_7 ( & V_22 -> V_138 ) ;
V_2 = (struct V_1 * ) V_22 ;
V_59 = & V_2 -> V_59 ;
F_157 ( V_19 -> V_52 -> V_348 , V_59 -> V_211 ,
V_59 -> V_77 ) ;
F_148 ( V_2 ) ;
}
V_19 -> V_289 . V_346 = 0 ;
F_151 ( V_19 , V_19 -> V_52 ) ;
}
