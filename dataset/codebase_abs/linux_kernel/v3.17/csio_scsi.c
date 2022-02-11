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
F_10 ( struct V_5 * V_6 , T_2 * V_30 , T_2 V_31 ,
T_2 V_32 , T_2 V_33 )
{
char V_34 [ 2 ] ;
if ( F_11 ( V_6 , V_34 ) ) {
switch ( V_34 [ 0 ] ) {
case V_35 :
* V_30 = V_31 ;
break;
case V_36 :
* V_30 = V_32 ;
break;
default:
* V_30 = V_33 ;
break;
}
} else
* V_30 = 0 ;
}
static inline void
F_12 ( struct V_1 * V_37 , void * V_38 )
{
struct V_39 * V_39 = (struct V_39 * ) V_38 ;
struct V_5 * V_6 = F_2 ( V_37 ) ;
if ( F_13 ( V_6 -> V_40 . V_41 == 0 ) ) {
F_14 ( V_6 -> V_12 -> V_13 , & V_39 -> V_42 ) ;
V_39 -> V_43 = 0 ;
V_39 -> V_44 = 0 ;
V_39 -> V_45 = 0 ;
memcpy ( V_39 -> V_46 , V_6 -> V_47 , 16 ) ;
F_10 ( V_6 , & V_39 -> V_45 ,
V_48 , V_49 , V_50 ) ;
V_39 -> V_51 = F_15 ( F_16 ( V_6 ) ) ;
if ( V_37 -> V_52 )
if ( V_37 -> V_53 == V_54 )
V_39 -> V_55 = V_56 ;
else
V_39 -> V_55 = V_57 ;
else
V_39 -> V_55 = 0 ;
} else {
memset ( V_39 , 0 , sizeof( * V_39 ) ) ;
F_14 ( V_6 -> V_12 -> V_13 , & V_39 -> V_42 ) ;
V_39 -> V_43 = ( T_2 ) V_6 -> V_40 . V_41 ;
}
}
static inline void
F_17 ( struct V_1 * V_37 , void * V_38 , T_3 V_58 )
{
struct V_59 * V_60 = V_37 -> V_9 -> V_61 ;
struct V_62 * V_63 = V_37 -> V_10 ;
struct V_64 * V_65 = (struct V_64 * ) V_38 ;
struct V_66 * V_67 ;
T_2 V_68 = F_18 ( V_60 ) -> V_69 ;
V_65 -> V_70 = F_15 ( F_19 ( V_71 ) |
F_20 ( V_68 ) ) ;
V_65 -> V_72 = F_15 ( F_21 ( V_63 -> V_73 ) |
F_22 (
F_23 ( V_58 , 16 ) ) ) ;
V_65 -> V_74 = ( V_75 ) V_37 ;
V_65 -> V_76 = F_24 ( F_25 ( V_60 , V_37 -> V_77 ) ) ;
V_65 -> V_78 = ( T_2 ) V_37 -> V_79 ;
V_65 -> V_80 = 0 ;
memset ( & V_65 -> V_81 , 0 , 8 ) ;
V_67 = & V_37 -> V_67 ;
V_65 -> V_82 = F_15 ( V_67 -> V_83 ) ;
V_65 -> V_84 = F_26 ( V_67 -> V_85 ) ;
V_65 -> V_86 = 0 ;
V_65 -> V_87 . V_88 . V_89 = 0 ;
V_65 -> V_87 . V_88 . V_90 = 0 ;
V_65 -> V_87 . V_88 . V_91 [ 0 ] = 0 ;
V_65 -> V_87 . V_88 . V_91 [ 1 ] = 0 ;
F_12 ( V_37 , ( void * ) ( ( V_75 ) V_38 +
sizeof( struct V_64 ) ) ) ;
}
static inline void
F_27 ( struct V_1 * V_37 )
{
struct V_92 V_93 ;
struct V_59 * V_60 = V_37 -> V_9 -> V_61 ;
struct V_18 * V_94 = F_18 ( V_60 ) ;
T_3 V_58 = F_28 ( V_94 -> V_69 ) ;
V_37 -> V_95 = F_29 ( V_60 , V_37 -> V_96 , V_58 , & V_93 ) ;
if ( F_30 ( V_37 -> V_95 != 0 ) )
return;
if ( V_93 . V_97 >= V_58 ) {
F_17 ( V_37 , V_93 . V_98 , V_58 ) ;
} else {
T_2 * V_99 = F_31 ( V_60 , V_37 -> V_96 ) ;
F_17 ( V_37 , ( void * ) V_99 , V_58 ) ;
memcpy ( V_93 . V_98 , V_99 , V_93 . V_97 ) ;
memcpy ( V_93 . V_100 , V_99 + V_93 . V_97 , V_58 - V_93 . V_97 ) ;
}
}
static inline void
F_32 ( struct V_59 * V_60 , struct V_1 * V_37 ,
struct V_101 * V_102 )
{
struct V_103 * V_104 = NULL ;
struct V_105 * V_106 ;
T_3 V_107 = 0 ;
T_3 V_108 ;
struct V_20 * V_22 ;
struct V_66 * V_67 ;
struct V_5 * V_6 = F_2 ( V_37 ) ;
V_102 -> V_109 = F_33 ( F_34 ( V_110 ) | V_111 |
F_35 ( V_37 -> V_52 ) ) ;
if ( F_13 ( ! V_37 -> V_112 ) ) {
F_36 (scmnd, sgel, req->nsge, i) {
if ( V_107 == 0 ) {
V_102 -> V_113 = F_26 ( F_37 ( V_106 ) ) ;
V_102 -> V_114 = F_15 ( F_38 ( V_106 ) ) ;
V_104 = (struct V_103 * ) ( V_102 + 1 ) ;
continue;
}
if ( ( V_107 - 1 ) & 0x1 ) {
V_104 -> V_38 [ 1 ] = F_26 (
F_37 ( V_106 ) ) ;
V_104 -> V_83 [ 1 ] = F_15 (
F_38 ( V_106 ) ) ;
V_104 ++ ;
} else {
V_104 -> V_38 [ 0 ] = F_26 (
F_37 ( V_106 ) ) ;
V_104 -> V_83 [ 0 ] = F_15 (
F_38 ( V_106 ) ) ;
}
}
} else {
V_108 = F_16 ( V_6 ) ;
F_39 (tmp, &req->gen_list) {
V_67 = (struct V_66 * ) V_22 ;
if ( V_107 == 0 ) {
V_102 -> V_113 = F_26 ( V_67 -> V_85 ) ;
V_102 -> V_114 = F_15 (
F_40 ( V_108 , V_67 -> V_83 ) ) ;
V_104 = (struct V_103 * ) ( V_102 + 1 ) ;
} else if ( ( V_107 - 1 ) & 0x1 ) {
V_104 -> V_38 [ 1 ] = F_26 ( V_67 -> V_85 ) ;
V_104 -> V_83 [ 1 ] = F_15 (
F_40 ( V_108 , V_67 -> V_83 ) ) ;
V_104 ++ ;
} else {
V_104 -> V_38 [ 0 ] = F_26 ( V_67 -> V_85 ) ;
V_104 -> V_83 [ 0 ] = F_15 (
F_40 ( V_108 , V_67 -> V_83 ) ) ;
}
V_108 -= F_40 ( V_108 , V_67 -> V_83 ) ;
V_107 ++ ;
}
}
}
static inline void
F_41 ( struct V_1 * V_37 , void * V_93 , T_3 V_58 )
{
struct V_59 * V_60 = V_37 -> V_9 -> V_61 ;
struct V_62 * V_63 = V_37 -> V_10 ;
struct V_115 * V_65 = (struct V_115 * ) V_93 ;
struct V_101 * V_102 ;
struct V_66 * V_67 ;
T_2 V_68 = F_18 ( V_60 ) -> V_69 ;
struct V_5 * V_6 = F_2 ( V_37 ) ;
V_65 -> V_70 = F_15 ( F_19 ( V_116 ) |
F_42 ( V_68 ) ) ;
V_65 -> V_72 = F_15 ( F_21 ( V_63 -> V_73 ) |
F_22 ( F_23 ( V_58 , 16 ) ) ) ;
V_65 -> V_74 = ( V_75 ) V_37 ;
V_65 -> V_76 = F_24 ( F_25 ( V_60 , V_37 -> V_77 ) ) ;
V_65 -> V_78 = ( T_2 ) ( V_37 -> V_79 ) ;
V_65 -> V_117 = 1 ;
V_65 -> V_118 = F_15 ( F_16 ( V_6 ) ) ;
V_65 -> V_119 = F_15 ( F_16 ( V_6 ) ) ;
V_67 = & V_37 -> V_67 ;
V_65 -> V_82 = F_15 ( V_67 -> V_83 ) ;
V_65 -> V_84 = F_26 ( V_67 -> V_85 ) ;
V_65 -> V_120 = 0 ;
V_65 -> V_87 . V_88 . V_89 = 0 ;
V_65 -> V_87 . V_88 . V_90 = 0 ;
V_65 -> V_87 . V_88 . V_121 [ 0 ] = 0 ;
V_65 -> V_87 . V_88 . V_121 [ 1 ] = 0 ;
F_12 ( V_37 , ( void * ) ( ( V_75 ) V_93 +
sizeof( struct V_115 ) ) ) ;
V_102 = (struct V_101 * ) ( ( V_75 ) V_93 +
sizeof( struct V_115 ) + F_43 ( V_68 , 16 ) ) ;
F_32 ( V_60 , V_37 , V_102 ) ;
}
static inline void
F_44 ( struct V_1 * V_37 , void * V_93 , T_3 V_58 )
{
struct V_59 * V_60 = V_37 -> V_9 -> V_61 ;
struct V_62 * V_63 = V_37 -> V_10 ;
struct V_122 * V_65 = (struct V_122 * ) V_93 ;
struct V_101 * V_102 ;
struct V_66 * V_67 ;
T_2 V_68 = F_18 ( V_60 ) -> V_69 ;
struct V_5 * V_6 = F_2 ( V_37 ) ;
V_65 -> V_70 = F_15 ( F_19 ( V_123 ) |
F_45 ( V_68 ) ) ;
V_65 -> V_72 = F_15 ( F_21 ( V_63 -> V_73 ) |
F_22 ( F_23 ( V_58 , 16 ) ) ) ;
V_65 -> V_74 = ( V_75 ) V_37 ;
V_65 -> V_76 = F_24 ( F_25 ( V_60 , V_37 -> V_77 ) ) ;
V_65 -> V_78 = ( T_2 ) ( V_37 -> V_79 ) ;
V_65 -> V_117 = 1 ;
V_65 -> V_118 = F_15 ( F_16 ( V_6 ) ) ;
V_65 -> V_119 = F_15 ( F_16 ( V_6 ) ) ;
V_67 = & V_37 -> V_67 ;
V_65 -> V_82 = F_15 ( V_67 -> V_83 ) ;
V_65 -> V_84 = F_26 ( V_67 -> V_85 ) ;
V_65 -> V_120 = 0 ;
V_65 -> V_87 . V_88 . V_89 = 0 ;
V_65 -> V_87 . V_88 . V_90 = 0 ;
V_65 -> V_87 . V_88 . V_121 [ 0 ] = 0 ;
V_65 -> V_87 . V_88 . V_121 [ 1 ] = 0 ;
F_12 ( V_37 , ( void * ) ( ( V_75 ) V_93 +
sizeof( struct V_122 ) ) ) ;
V_102 = (struct V_101 * ) ( ( V_75 ) V_93 +
sizeof( struct V_122 ) + F_43 ( V_68 , 16 ) ) ;
F_32 ( V_60 , V_37 , V_102 ) ;
}
static inline void
F_46 ( struct V_1 * V_37 )
{
struct V_92 V_93 ;
T_3 V_58 ;
struct V_59 * V_60 = V_37 -> V_9 -> V_61 ;
struct V_18 * V_94 = F_18 ( V_60 ) ;
F_47 ( V_37 , V_124 , V_58 , V_94 -> V_69 ) ;
V_58 = F_43 ( V_58 , 16 ) ;
V_37 -> V_95 = F_29 ( V_60 , V_37 -> V_96 , V_58 , & V_93 ) ;
if ( F_13 ( V_37 -> V_95 == 0 ) ) {
if ( F_13 ( V_93 . V_97 >= V_58 ) ) {
F_41 ( V_37 , V_93 . V_98 , V_58 ) ;
} else {
T_2 * V_99 = F_31 ( V_60 , V_37 -> V_96 ) ;
F_41 ( V_37 , ( void * ) V_99 , V_58 ) ;
memcpy ( V_93 . V_98 , V_99 , V_93 . V_97 ) ;
memcpy ( V_93 . V_100 , V_99 + V_93 . V_97 , V_58 - V_93 . V_97 ) ;
}
}
}
static inline void
F_48 ( struct V_1 * V_37 )
{
struct V_92 V_93 ;
T_3 V_58 ;
struct V_59 * V_60 = V_37 -> V_9 -> V_61 ;
struct V_18 * V_94 = F_18 ( V_60 ) ;
F_47 ( V_37 , V_125 , V_58 , V_94 -> V_69 ) ;
V_58 = F_43 ( V_58 , 16 ) ;
V_37 -> V_95 = F_29 ( V_60 , V_37 -> V_96 , V_58 , & V_93 ) ;
if ( F_13 ( V_37 -> V_95 == 0 ) ) {
if ( F_13 ( V_93 . V_97 >= V_58 ) ) {
F_44 ( V_37 , V_93 . V_98 , V_58 ) ;
} else {
T_2 * V_99 = F_31 ( V_60 , V_37 -> V_96 ) ;
F_44 ( V_37 , ( void * ) V_99 , V_58 ) ;
memcpy ( V_93 . V_98 , V_99 , V_93 . V_97 ) ;
memcpy ( V_93 . V_100 , V_99 + V_93 . V_97 , V_58 - V_93 . V_97 ) ;
}
}
}
static inline void
F_49 ( struct V_18 * V_94 , struct V_1 * V_37 )
{
#ifdef F_50
struct V_59 * V_60 = V_37 -> V_9 -> V_61 ;
#endif
struct V_105 * V_106 = NULL ;
struct V_5 * V_6 = F_2 ( V_37 ) ;
V_11 V_126 = 0 ;
T_3 V_127 = 4096 ;
T_3 V_128 ;
struct V_66 * V_67 = NULL ;
T_3 V_129 = 0 ;
T_3 V_108 = 0 ;
T_3 V_130 = 0 ;
T_3 V_107 ;
F_36 (scmnd, sgel, req->nsge, i) {
V_126 = F_37 ( V_106 ) ;
V_130 = F_38 ( V_106 ) ;
V_128 = V_126 & ( V_127 - 1 ) ;
if ( V_107 != 0 && V_128 ) {
F_51 ( V_60 , L_1 ,
V_126 , V_130 ) ;
goto V_131;
}
if ( ( V_107 != ( V_37 -> V_52 - 1 ) ) &&
( ( V_128 + V_130 ) & ( V_127 - 1 ) ) ) {
F_51 ( V_60 ,
L_2
L_3 , V_126 , V_130 ) ;
goto V_131;
}
}
V_37 -> V_112 = 0 ;
F_46 ( V_37 ) ;
return;
V_131:
F_52 ( V_94 , V_132 ) ;
V_37 -> V_112 = 1 ;
F_53 ( & V_37 -> V_133 ) ;
V_108 = F_16 ( V_6 ) ;
V_107 = 0 ;
while ( V_129 < V_108 ) {
V_67 = F_54 ( V_94 ) ;
if ( V_67 == NULL || V_107 > V_94 -> V_134 ) {
V_37 -> V_95 = - V_135 ;
break;
}
V_129 += V_67 -> V_83 ;
F_8 ( & V_67 -> V_136 , & V_37 -> V_133 ) ;
V_107 ++ ;
}
if ( ! V_37 -> V_95 ) {
V_37 -> V_52 = V_107 ;
F_46 ( V_37 ) ;
return;
}
if ( V_107 > 0 )
F_55 ( V_94 , & V_37 -> V_133 , V_107 ) ;
}
static inline void
F_56 ( struct V_1 * V_37 , void * V_38 , T_3 V_58 ,
bool abort )
{
struct V_59 * V_60 = V_37 -> V_9 -> V_61 ;
struct V_62 * V_63 = V_37 -> V_10 ;
struct V_137 * V_65 = (struct V_137 * ) V_38 ;
V_65 -> V_70 = F_15 ( F_19 ( V_138 ) ) ;
V_65 -> V_72 = F_15 ( F_21 ( V_63 -> V_73 ) |
F_22 (
F_23 ( V_58 , 16 ) ) ) ;
V_65 -> V_74 = ( V_75 ) V_37 ;
V_65 -> V_76 = F_24 ( F_25 ( V_60 , V_37 -> V_77 ) ) ;
V_65 -> V_78 = ( T_2 ) V_37 -> V_79 ;
V_65 -> V_139 =
( F_57 ( abort ) |
F_58 ( 0 ) ) ;
V_65 -> V_80 [ 0 ] = 0 ;
V_65 -> V_80 [ 1 ] = 0 ;
V_65 -> V_80 [ 2 ] = 0 ;
V_65 -> V_80 [ 3 ] = 0 ;
V_65 -> V_140 = ( V_75 ) V_37 ;
}
static inline void
F_59 ( struct V_1 * V_37 , bool abort )
{
struct V_92 V_93 ;
struct V_59 * V_60 = V_37 -> V_9 -> V_61 ;
T_3 V_58 = F_43 ( sizeof( struct V_137 ) , 16 ) ;
V_37 -> V_95 = F_29 ( V_60 , V_37 -> V_96 , V_58 , & V_93 ) ;
if ( V_37 -> V_95 != 0 )
return;
if ( V_93 . V_97 >= V_58 ) {
F_56 ( V_37 , V_93 . V_98 , V_58 , abort ) ;
} else {
T_2 * V_99 = F_31 ( V_60 , V_37 -> V_96 ) ;
F_56 ( V_37 , ( void * ) V_99 , V_58 , abort ) ;
memcpy ( V_93 . V_98 , V_99 , V_93 . V_97 ) ;
memcpy ( V_93 . V_100 , V_99 + V_93 . V_97 , V_58 - V_93 . V_97 ) ;
}
}
static void
F_60 ( struct V_1 * V_37 , enum V_141 V_142 )
{
struct V_59 * V_60 = V_37 -> V_9 -> V_61 ;
struct V_18 * V_94 = F_18 ( V_60 ) ;
switch ( V_142 ) {
case V_143 :
if ( V_37 -> V_52 ) {
if ( V_37 -> V_53 == V_54 ) {
V_37 -> V_112 = 0 ;
F_48 ( V_37 ) ;
} else
F_49 ( V_94 , V_37 ) ;
} else {
F_27 ( V_37 ) ;
}
if ( F_13 ( V_37 -> V_95 == 0 ) ) {
F_61 ( & V_37 -> V_144 , V_145 ) ;
F_8 ( & V_37 -> V_144 . V_146 , & V_94 -> V_24 ) ;
F_62 ( V_60 , V_37 -> V_96 , false ) ;
F_52 ( V_94 , V_147 ) ;
return;
}
break;
case V_148 :
F_27 ( V_37 ) ;
if ( V_37 -> V_95 == 0 ) {
F_61 ( & V_37 -> V_144 , V_149 ) ;
F_8 ( & V_37 -> V_144 . V_146 , & V_94 -> V_24 ) ;
F_62 ( V_60 , V_37 -> V_96 , false ) ;
F_52 ( V_94 , V_150 ) ;
}
return;
case V_151 :
case V_152 :
V_37 -> V_95 = - V_153 ;
F_63 ( V_60 , L_4 , V_37 ) ;
break;
default:
F_51 ( V_60 , L_5 , V_142 , V_37 ) ;
F_64 ( 0 ) ;
}
}
static void
V_145 ( struct V_1 * V_37 , enum V_141 V_142 )
{
struct V_59 * V_60 = V_37 -> V_9 -> V_61 ;
struct V_18 * V_19 = F_18 ( V_60 ) ;
struct V_62 * V_63 ;
switch ( V_142 ) {
case V_154 :
F_65 ( V_19 , V_147 ) ;
F_7 ( & V_37 -> V_144 . V_146 ) ;
F_61 ( & V_37 -> V_144 , F_60 ) ;
if ( F_30 ( V_37 -> V_155 != V_156 ) ) {
V_63 = V_37 -> V_10 ;
if ( F_9 ( V_37 -> V_155 ) &&
F_66 ( V_63 ) ) {
F_61 ( & V_37 -> V_144 ,
V_157 ) ;
F_8 ( & V_37 -> V_144 . V_146 ,
& V_63 -> V_158 ) ;
}
}
break;
case V_151 :
F_59 ( V_37 , V_159 ) ;
if ( V_37 -> V_95 == 0 ) {
F_62 ( V_60 , V_37 -> V_96 , false ) ;
F_61 ( & V_37 -> V_144 , V_160 ) ;
}
break;
case V_152 :
F_59 ( V_37 , V_161 ) ;
if ( V_37 -> V_95 == 0 ) {
F_62 ( V_60 , V_37 -> V_96 , false ) ;
F_61 ( & V_37 -> V_144 , V_162 ) ;
}
break;
case V_163 :
V_37 -> V_155 = V_164 ;
F_65 ( V_19 , V_147 ) ;
F_61 ( & V_37 -> V_144 , F_60 ) ;
break;
default:
F_51 ( V_60 , L_5 , V_142 , V_37 ) ;
F_64 ( 0 ) ;
}
}
static void
V_149 ( struct V_1 * V_37 , enum V_141 V_142 )
{
struct V_59 * V_60 = V_37 -> V_9 -> V_61 ;
struct V_18 * V_19 = F_18 ( V_60 ) ;
switch ( V_142 ) {
case V_154 :
F_65 ( V_19 , V_150 ) ;
F_7 ( & V_37 -> V_144 . V_146 ) ;
F_61 ( & V_37 -> V_144 , F_60 ) ;
break;
case V_151 :
F_59 ( V_37 , V_159 ) ;
if ( V_37 -> V_95 == 0 ) {
F_62 ( V_60 , V_37 -> V_96 , false ) ;
F_61 ( & V_37 -> V_144 , V_160 ) ;
}
break;
case V_152 :
F_59 ( V_37 , V_161 ) ;
if ( V_37 -> V_95 == 0 ) {
F_62 ( V_60 , V_37 -> V_96 , false ) ;
F_61 ( & V_37 -> V_144 , V_162 ) ;
}
break;
case V_163 :
V_37 -> V_155 = V_164 ;
F_65 ( V_19 , V_150 ) ;
F_61 ( & V_37 -> V_144 , F_60 ) ;
break;
default:
F_51 ( V_60 , L_5 , V_142 , V_37 ) ;
F_64 ( 0 ) ;
}
}
static void
V_160 ( struct V_1 * V_37 , enum V_141 V_142 )
{
struct V_59 * V_60 = V_37 -> V_9 -> V_61 ;
struct V_18 * V_19 = F_18 ( V_60 ) ;
switch ( V_142 ) {
case V_154 :
F_51 ( V_60 ,
L_6
L_7 , V_37 , V_37 -> V_155 ) ;
V_37 -> V_95 = - V_165 ;
break;
case V_151 :
F_52 ( V_19 , V_166 ) ;
break;
case V_167 :
F_51 ( V_60 , L_8 ,
V_37 , V_37 -> V_155 , V_37 -> V_95 ) ;
if ( V_37 -> V_95 != - V_165 ) {
F_63 ( V_60 ,
L_9
L_10 , V_37 ) ;
F_64 ( 0 ) ;
}
if ( ( V_37 -> V_155 == V_156 ) ||
( V_37 -> V_155 == V_168 ) ||
F_9 ( V_37 -> V_155 ) )
V_37 -> V_155 = V_169 ;
F_65 ( V_19 , V_147 ) ;
F_7 ( & V_37 -> V_144 . V_146 ) ;
F_61 ( & V_37 -> V_144 , F_60 ) ;
break;
case V_163 :
V_37 -> V_155 = V_164 ;
F_65 ( V_19 , V_147 ) ;
F_61 ( & V_37 -> V_144 , F_60 ) ;
break;
case V_152 :
break;
default:
F_51 ( V_60 , L_5 , V_142 , V_37 ) ;
F_64 ( 0 ) ;
}
}
static void
V_162 ( struct V_1 * V_37 , enum V_141 V_142 )
{
struct V_59 * V_60 = V_37 -> V_9 -> V_61 ;
struct V_18 * V_19 = F_18 ( V_60 ) ;
switch ( V_142 ) {
case V_154 :
F_51 ( V_60 ,
L_6
L_11 , V_37 , V_37 -> V_155 ) ;
V_37 -> V_95 = - V_165 ;
break;
case V_170 :
if ( V_37 -> V_95 != - V_165 ) {
F_67 ( V_60 ,
L_12
L_10 , V_37 ) ;
F_64 ( 0 ) ;
}
F_64 ( ( V_37 -> V_155 == V_156 ) ||
( V_37 -> V_155 == V_168 ) ) ;
V_37 -> V_155 = V_171 ;
F_65 ( V_19 , V_147 ) ;
F_7 ( & V_37 -> V_144 . V_146 ) ;
F_61 ( & V_37 -> V_144 , F_60 ) ;
break;
case V_152 :
break;
case V_163 :
V_37 -> V_155 = V_164 ;
F_65 ( V_19 , V_147 ) ;
F_61 ( & V_37 -> V_144 , F_60 ) ;
break;
default:
F_51 ( V_60 , L_5 , V_142 , V_37 ) ;
F_64 ( 0 ) ;
}
}
static void
V_157 ( struct V_1 * V_37 , enum V_141 V_142 )
{
switch ( V_142 ) {
case V_151 :
case V_152 :
V_37 -> V_95 = 0 ;
break;
case V_163 :
F_61 ( & V_37 -> V_144 , F_60 ) ;
break;
default:
F_51 ( V_37 -> V_9 -> V_61 , L_5 ,
V_142 , V_37 ) ;
F_64 ( 0 ) ;
}
}
struct V_1 *
F_68 ( struct V_59 * V_60 , void * V_65 , T_3 V_83 ,
struct V_172 * V_173 , void * V_174 , T_2 * * V_175 )
{
struct V_1 * V_2 = NULL ;
struct V_176 * V_177 ;
T_2 * V_178 ;
T_2 V_179 ;
struct V_18 * V_19 = F_18 ( V_60 ) ;
V_177 = (struct V_176 * ) ( ( V_75 ) V_65 + sizeof( V_180 ) ) ;
if ( F_30 ( V_177 -> V_181 != V_182 ) ) {
F_63 ( V_60 , L_13 ,
V_177 -> V_181 ) ;
F_52 ( V_19 , V_183 ) ;
return NULL ;
}
V_178 = ( T_2 * ) ( V_177 -> V_184 ) ;
V_179 = F_69 ( V_178 ) ;
* V_175 = V_178 ;
if ( F_13 ( ( * V_178 == V_116 ) ||
( * V_178 == V_123 ) ||
( * V_178 == V_71 ) ) ) {
V_2 = (struct V_1 * ) ( ( V_75 )
( ( (struct V_115 * ) V_178 ) -> V_74 ) ) ;
F_64 ( F_70 ( V_2 ) ) ;
V_2 -> V_155 = V_179 ;
return V_2 ;
}
if ( * V_178 == V_138 ) {
V_2 = (struct V_1 * ) ( ( V_75 )
( ( (struct V_137 * ) V_178 ) -> V_74 ) ) ;
F_64 ( F_70 ( V_2 ) ) ;
V_2 -> V_155 = V_179 ;
return V_2 ;
}
F_63 ( V_60 , L_14 , * V_178 ) ;
F_52 ( V_19 , V_185 ) ;
return NULL ;
}
void
F_71 ( struct V_18 * V_19 , struct V_20 * V_186 )
{
struct V_59 * V_60 = V_19 -> V_60 ;
struct V_1 * V_2 ;
struct V_20 * V_22 , * V_23 ;
struct V_5 * V_6 ;
F_6 (tmp, next, q) {
V_2 = (struct V_1 * ) V_22 ;
F_72 ( V_2 ) ;
F_7 ( & V_2 -> V_144 . V_146 ) ;
V_6 = F_2 ( V_2 ) ;
F_73 ( & V_60 -> V_187 ) ;
if ( V_6 != NULL )
V_2 -> V_188 ( V_60 , V_2 ) ;
F_74 ( & V_19 -> V_189 ) ;
F_75 ( V_19 , V_2 ) ;
F_73 ( & V_19 -> V_189 ) ;
F_74 ( & V_60 -> V_187 ) ;
}
}
static void
F_76 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_190 * V_191 = V_2 -> V_9 ;
struct V_59 * V_60 = V_191 -> V_61 ;
int V_192 = 0 ;
struct V_18 * V_94 = F_18 ( V_60 ) ;
int V_193 ;
if ( F_2 ( V_2 ) != V_6 ) {
F_52 ( V_94 , V_194 ) ;
return;
}
V_192 = F_77 ( V_191 ) ;
V_193 = F_78 ( V_60 , V_2 , ( V_192 ? V_159 : V_161 ) ) ;
if ( V_193 != 0 ) {
if ( V_192 )
F_52 ( V_94 , V_195 ) ;
else
F_52 ( V_94 , V_196 ) ;
}
}
static int
F_79 ( struct V_18 * V_19 , struct V_20 * V_186 , T_3 V_79 )
{
struct V_59 * V_60 = V_19 -> V_60 ;
struct V_20 * V_22 , * V_23 ;
int V_197 = F_23 ( V_79 , V_198 ) ;
struct V_5 * V_6 ;
if ( F_4 ( V_186 ) )
return 0 ;
F_51 ( V_60 , L_15 ) ;
F_6 (tmp, next, q) {
V_6 = F_2 ( (struct V_1 * ) V_22 ) ;
F_76 ( (struct V_1 * ) V_22 , V_6 ) ;
}
while ( ! F_4 ( V_186 ) && V_197 -- ) {
F_73 ( & V_60 -> V_187 ) ;
F_80 ( V_198 ) ;
F_74 ( & V_60 -> V_187 ) ;
}
if ( F_4 ( V_186 ) )
return 0 ;
return - V_199 ;
}
int
F_81 ( struct V_18 * V_19 , bool abort )
{
struct V_59 * V_60 = V_19 -> V_60 ;
int V_193 = 0 ;
int V_197 = F_23 ( 60 * 1000 , V_198 ) ;
if ( F_4 ( & V_19 -> V_24 ) )
return 0 ;
while ( ! F_4 ( & V_19 -> V_24 ) && V_197 -- ) {
F_73 ( & V_60 -> V_187 ) ;
F_80 ( V_198 ) ;
F_74 ( & V_60 -> V_187 ) ;
}
if ( F_4 ( & V_19 -> V_24 ) )
return 0 ;
if ( abort ) {
V_193 = F_79 ( V_19 , & V_19 -> V_24 , 30000 ) ;
if ( V_193 == 0 )
return V_193 ;
F_51 ( V_60 , L_16 ) ;
}
F_71 ( V_19 , & V_19 -> V_24 ) ;
F_64 ( F_4 ( & V_19 -> V_24 ) ) ;
return V_193 ;
}
int
F_82 ( struct V_18 * V_19 , struct V_190 * V_191 )
{
struct V_59 * V_60 = V_19 -> V_60 ;
struct V_3 V_4 ;
int V_193 ;
int V_197 = F_23 ( 60 * 1000 , V_198 ) ;
F_51 ( V_60 , L_17 , V_191 ) ;
V_4 . V_7 = V_16 ;
V_4 . V_9 = V_191 ;
F_53 ( & V_191 -> V_200 ) ;
F_3 ( V_19 , & V_4 , & V_191 -> V_200 ) ;
if ( F_4 ( & V_191 -> V_200 ) )
return 0 ;
while ( ! F_4 ( & V_191 -> V_200 ) && V_197 -- ) {
F_73 ( & V_60 -> V_187 ) ;
F_80 ( V_198 ) ;
F_74 ( & V_60 -> V_187 ) ;
}
if ( F_4 ( & V_191 -> V_200 ) )
return 0 ;
F_51 ( V_60 , L_18 , V_191 ) ;
V_193 = F_79 ( V_19 , & V_191 -> V_200 , 30000 ) ;
if ( V_193 != 0 ) {
F_51 ( V_60 , L_16 ) ;
F_71 ( V_19 , & V_191 -> V_200 ) ;
}
F_64 ( F_4 ( & V_191 -> V_200 ) ) ;
return V_193 ;
}
static T_4
F_83 ( struct V_12 * V_201 ,
struct V_202 * V_203 , char * V_204 )
{
struct V_190 * V_191 = F_84 ( F_85 ( V_201 ) ) ;
struct V_59 * V_60 = F_86 ( V_191 ) ;
if ( F_87 ( V_60 ) )
return snprintf ( V_204 , V_205 , L_19 ) ;
else
return snprintf ( V_204 , V_205 , L_20 ) ;
}
static T_4
F_88 ( struct V_12 * V_201 ,
struct V_202 * V_203 , const char * V_204 , T_5 V_197 )
{
struct V_190 * V_191 = F_84 ( F_85 ( V_201 ) ) ;
struct V_59 * V_60 = F_86 ( V_191 ) ;
if ( * V_204 != '1' )
return - V_153 ;
F_89 ( V_60 , 1 ) ;
F_90 ( V_60 ) ;
F_74 ( & V_60 -> V_187 ) ;
F_91 ( V_60 ) ;
F_73 ( & V_60 -> V_187 ) ;
F_92 ( V_60 ) ;
return V_197 ;
}
static T_4
F_93 ( struct V_12 * V_201 ,
struct V_202 * V_203 , const char * V_204 , T_5 V_197 )
{
struct V_190 * V_191 = F_84 ( F_85 ( V_201 ) ) ;
struct V_59 * V_60 = F_86 ( V_191 ) ;
bool V_206 ;
if ( * V_204 == '1' || * V_204 == '0' )
V_206 = ( * V_204 == '1' ) ? true : false ;
else
return - V_153 ;
F_94 ( V_60 , V_191 -> V_207 ) ;
F_74 ( & V_60 -> V_187 ) ;
F_95 ( V_60 , V_191 -> V_207 , V_206 ) ;
F_73 ( & V_60 -> V_187 ) ;
F_96 ( V_60 , V_191 -> V_207 ) ;
return V_197 ;
}
static T_4
F_97 ( struct V_12 * V_201 ,
struct V_202 * V_203 , char * V_204 )
{
struct V_190 * V_191 = F_84 ( F_85 ( V_201 ) ) ;
return snprintf ( V_204 , V_205 , L_21 , V_191 -> V_208 . V_209 ) ;
}
static T_4
F_98 ( struct V_12 * V_201 ,
struct V_202 * V_203 , const char * V_204 , T_5 V_197 )
{
struct V_190 * V_191 = F_84 ( F_85 ( V_201 ) ) ;
struct V_59 * V_60 = F_86 ( V_191 ) ;
T_3 V_210 = 0 ;
if ( ! isdigit ( V_204 [ 0 ] ) )
return - V_153 ;
if ( sscanf ( V_204 , L_22 , & V_210 ) )
return - V_153 ;
V_191 -> V_208 . V_209 = V_210 ;
V_60 -> V_208 . V_209 = V_210 ;
return 0 ;
}
static T_4
F_99 ( struct V_12 * V_201 ,
struct V_202 * V_203 , char * V_204 )
{
struct V_190 * V_191 = F_84 ( F_85 ( V_201 ) ) ;
return snprintf ( V_204 , V_205 , L_23 , V_191 -> V_211 ) ;
}
static inline T_3
F_100 ( struct V_59 * V_60 , struct V_1 * V_37 )
{
struct V_5 * V_6 = (struct V_5 * ) F_2 ( V_37 ) ;
struct V_105 * V_212 ;
T_3 V_213 ;
T_3 V_214 ;
T_3 V_128 = 0 ;
T_3 V_215 = 0 ;
T_3 V_216 = 0 ;
void * V_126 ;
void * V_217 ;
struct V_66 * V_67 ;
V_213 = F_16 ( V_6 ) ;
V_212 = F_101 ( V_6 ) ;
V_67 = (struct V_66 * ) F_102 ( & V_37 -> V_133 ) ;
while ( V_213 > 0 && V_212 && V_67 ) {
if ( V_128 >= V_67 -> V_83 ) {
V_128 = 0 ;
V_67 = (struct V_66 * )
F_102 ( V_67 ) ;
continue;
}
if ( V_215 >= V_212 -> V_218 ) {
V_215 -= V_212 -> V_218 ;
V_212 = F_103 ( V_212 ) ;
continue;
}
V_217 = V_67 -> V_219 + V_128 ;
V_216 = V_212 -> V_220 + V_215 ;
V_214 = F_40 ( ( V_67 -> V_83 - V_128 ) ,
V_212 -> V_218 - V_215 ) ;
V_214 = F_40 ( ( T_3 ) ( V_205 - ( V_216 & ~ V_221 ) ) ,
V_214 ) ;
V_126 = F_104 ( F_105 ( V_212 ) + ( V_216 >> V_222 ) ) ;
if ( ! V_126 ) {
F_106 ( V_60 , L_24 ,
V_212 , V_37 ) ;
break;
}
F_51 ( V_60 , L_25 ,
V_126 , V_216 , V_217 , V_214 ) ;
memcpy ( V_126 + ( V_216 & ~ V_221 ) , V_217 , V_214 ) ;
F_107 ( V_126 ) ;
V_215 += V_214 ;
V_128 += V_214 ;
V_213 -= V_214 ;
}
if ( V_213 > 0 )
return V_223 ;
else
return V_224 ;
}
static inline void
F_108 ( struct V_59 * V_60 , struct V_1 * V_37 )
{
struct V_5 * V_47 = (struct V_5 * ) F_2 ( V_37 ) ;
struct V_18 * V_19 = F_18 ( V_60 ) ;
struct V_225 * V_226 ;
struct V_227 * V_228 ;
struct V_66 * V_67 ;
T_2 V_229 , V_230 = 0 ;
T_3 V_231 = V_224 ;
T_3 V_232 = 0 , V_233 = 0 ;
struct V_62 * V_63 = (struct V_62 * ) ( V_47 -> V_12 -> V_234 ) ;
switch ( V_37 -> V_155 ) {
case V_164 :
if ( F_30 ( ! F_87 ( V_60 ) ) )
return;
V_231 = V_223 ;
F_52 ( V_19 , V_235 ) ;
break;
case V_236 :
V_67 = & V_37 -> V_67 ;
V_226 = (struct V_225 * ) V_67 -> V_219 ;
V_228 = (struct V_227 * ) ( V_226 + 1 ) ;
V_229 = V_226 -> V_237 . V_238 ;
V_230 = V_226 -> V_237 . V_239 ;
if ( V_229 & V_240 ) {
V_232 = F_109 ( V_226 -> V_241 . V_242 ) ;
if ( ( V_232 != 0 && V_232 != 4 && V_232 != 8 ) ||
( V_228 -> V_243 != V_244 ) ) {
V_231 = V_223 ;
goto V_245;
}
}
if ( ( V_229 & V_246 ) && V_226 -> V_241 . V_247 ) {
V_233 = F_109 ( V_226 -> V_241 . V_247 ) ;
if ( V_233 > V_248 )
V_233 = V_248 ;
memcpy ( V_47 -> V_249 ,
& V_228 -> V_250 [ 0 ] + V_232 , V_233 ) ;
F_52 ( V_19 , V_251 ) ;
}
F_110 ( V_47 , 0 ) ;
if ( V_229 & V_252 ) {
F_110 ( V_47 ,
F_109 ( V_226 -> V_241 . V_253 ) ) ;
if ( ! ( V_229 & V_246 ) &&
( V_230 == V_254 ) &&
( ( F_16 ( V_47 ) - F_111 ( V_47 ) )
< V_47 -> V_255 ) )
V_231 = V_223 ;
} else if ( V_229 & V_256 )
V_231 = V_223 ;
F_52 ( V_19 , V_257 ) ;
break;
case V_258 :
F_63 ( V_60 ,
L_26
L_27 , V_47 -> V_47 [ 0 ] ,
F_16 ( V_47 ) , F_111 ( V_47 ) ) ;
V_231 = V_223 ;
F_52 ( V_19 , V_259 ) ;
break;
case V_260 :
F_63 ( V_60 ,
L_28
L_29 ,
V_47 -> V_47 [ 0 ] , F_16 ( V_47 ) ,
F_111 ( V_47 ) , V_47 -> V_12 -> V_13 ,
V_63 -> V_73 ) ;
V_231 = V_223 ;
F_52 ( V_19 , V_261 ) ;
break;
case V_169 :
case V_262 :
case V_171 :
F_51 ( V_60 , L_30 , V_37 , V_47 ,
V_47 -> V_47 [ 0 ] ,
( V_37 -> V_155 == V_171 ) ?
L_31 : L_32 ) ;
V_231 = V_263 ;
if ( V_37 -> V_155 == V_171 )
F_52 ( V_19 , V_264 ) ;
else
F_52 ( V_19 , V_265 ) ;
break;
case V_266 :
F_51 ( V_60 , L_33 ,
V_37 , V_47 , V_37 -> V_155 ) ;
V_231 = V_223 ;
F_52 ( V_19 , V_267 ) ;
break;
case V_26 :
F_52 ( V_19 , V_268 ) ;
V_231 = V_223 ;
break;
case V_27 :
F_52 ( V_19 , V_269 ) ;
V_231 = V_223 ;
break;
case V_28 :
F_52 ( V_19 , V_270 ) ;
V_231 = V_223 ;
break;
case V_29 :
V_231 = V_223 ;
break;
case V_25 :
F_52 ( V_19 , V_271 ) ;
V_231 = V_223 ;
break;
case V_272 :
F_52 ( V_19 , V_273 ) ;
V_231 = V_223 ;
break;
default:
F_106 ( V_60 , L_34 ,
V_37 -> V_155 , V_37 , V_47 ) ;
F_64 ( 0 ) ;
F_52 ( V_19 , V_274 ) ;
V_231 = V_223 ;
break;
}
V_245:
if ( V_37 -> V_52 > 0 )
F_112 ( V_47 ) ;
V_47 -> V_275 = ( ( ( V_231 ) << 16 ) | V_230 ) ;
V_47 -> V_276 ( V_47 ) ;
F_2 ( V_37 ) = NULL ;
F_113 ( & V_37 -> V_277 ) ;
}
static void
F_114 ( struct V_59 * V_60 , struct V_1 * V_37 )
{
struct V_5 * V_47 = (struct V_5 * ) F_2 ( V_37 ) ;
T_2 V_230 = V_254 ;
T_3 V_231 = V_224 ;
if ( F_13 ( V_37 -> V_155 == V_156 ) ) {
if ( V_37 -> V_52 > 0 ) {
F_112 ( V_47 ) ;
if ( V_37 -> V_112 )
V_231 = F_100 ( V_60 , V_37 ) ;
}
V_47 -> V_275 = ( ( ( V_231 ) << 16 ) | V_230 ) ;
V_47 -> V_276 ( V_47 ) ;
F_2 ( V_37 ) = NULL ;
F_52 ( F_18 ( V_60 ) , V_278 ) ;
} else {
F_108 ( V_60 , V_37 ) ;
}
}
static int
F_115 ( struct V_279 * V_280 , struct V_5 * V_47 )
{
struct V_190 * V_191 = F_84 ( V_280 ) ;
struct V_59 * V_60 = F_86 ( V_191 ) ;
struct V_18 * V_94 = F_18 ( V_60 ) ;
struct V_62 * V_63 = (struct V_62 * ) ( V_47 -> V_12 -> V_234 ) ;
struct V_1 * V_2 = NULL ;
unsigned long V_229 ;
int V_52 = 0 ;
int V_193 = V_281 , V_282 ;
int V_283 ;
int V_284 ;
struct V_285 * V_286 ;
struct V_287 * V_288 = F_116 ( F_117 ( V_47 -> V_12 ) ) ;
if ( ! F_118 ( V_47 -> V_289 ) )
V_284 = F_119 () ;
else
V_284 = V_47 -> V_289 -> V_284 ;
V_286 = & V_60 -> V_286 [ V_191 -> V_207 ] [ V_284 ] ;
V_282 = F_120 ( V_288 ) ;
if ( V_282 ) {
V_47 -> V_275 = V_282 ;
F_52 ( V_94 , V_290 ) ;
goto V_291;
}
if ( F_30 ( ! F_87 ( V_60 ) ) ) {
V_47 -> V_275 = ( V_263 << 16 ) ;
F_52 ( V_94 , V_292 ) ;
goto V_291;
}
V_52 = F_121 ( V_47 ) ;
if ( F_30 ( V_52 < 0 ) ) {
F_52 ( V_94 , V_293 ) ;
goto V_294;
}
if ( F_30 ( V_52 > V_94 -> V_134 ) ) {
F_63 ( V_60 ,
L_35
L_36 , V_52 , V_94 -> V_134 ) ;
F_52 ( V_94 , V_295 ) ;
goto V_296;
}
V_2 = F_122 ( V_60 , V_94 ) ;
if ( ! V_2 ) {
F_106 ( V_60 , L_37 ,
V_94 -> V_297 . V_147 ) ;
F_52 ( V_94 , V_298 ) ;
goto V_296;
}
V_2 -> V_52 = V_52 ;
V_2 -> V_9 = V_191 ;
V_2 -> V_10 = V_63 ;
V_2 -> V_77 = V_286 -> V_77 ;
V_2 -> V_96 = V_286 -> V_96 ;
V_2 -> V_155 = 0 ;
V_2 -> V_95 = 0 ;
F_2 ( V_2 ) = ( void * ) V_47 ;
V_2 -> V_79 = 0 ;
V_2 -> V_53 = V_47 -> V_299 ;
if ( V_47 -> V_299 == V_54 ) {
F_52 ( V_191 , V_300 ) ;
V_191 -> V_297 . V_301 += F_16 ( V_47 ) ;
} else if ( V_47 -> V_299 == V_302 ) {
F_52 ( V_191 , V_303 ) ;
V_191 -> V_297 . V_304 += F_16 ( V_47 ) ;
} else
F_52 ( V_191 , V_305 ) ;
V_2 -> V_188 = F_114 ;
V_47 -> V_306 = ( unsigned char * ) V_2 ;
V_47 -> V_40 . V_41 = 0 ;
F_123 ( & V_60 -> V_187 , V_229 ) ;
V_283 = F_124 ( V_2 ) ;
F_125 ( & V_60 -> V_187 , V_229 ) ;
if ( V_283 != 0 ) {
F_106 ( V_60 , L_38 ,
V_2 , V_283 ) ;
F_52 ( V_94 , V_307 ) ;
goto V_308;
}
return 0 ;
V_308:
F_126 ( V_60 , V_94 , V_2 ) ;
V_296:
if ( V_52 > 0 )
F_112 ( V_47 ) ;
V_294:
return V_193 ;
V_291:
V_47 -> V_276 ( V_47 ) ;
return 0 ;
}
static int
F_78 ( struct V_59 * V_60 , struct V_1 * V_2 , bool abort )
{
int V_193 ;
int V_284 = F_119 () ;
struct V_190 * V_191 = V_2 -> V_9 ;
struct V_285 * V_286 = & V_60 -> V_286 [ V_191 -> V_207 ] [ V_284 ] ;
V_2 -> V_79 = V_309 ;
V_2 -> V_96 = V_286 -> V_96 ;
if ( abort == V_159 )
V_193 = F_127 ( V_2 ) ;
else
V_193 = F_128 ( V_2 ) ;
return V_193 ;
}
static int
F_129 ( struct V_5 * V_47 )
{
struct V_1 * V_2 ;
struct V_190 * V_191 = F_84 ( V_47 -> V_12 -> V_280 ) ;
struct V_59 * V_60 = F_86 ( V_191 ) ;
struct V_18 * V_94 = F_18 ( V_60 ) ;
int V_192 = 0 , V_310 ;
unsigned long V_79 = 0 ;
int V_193 ;
struct V_62 * V_63 = (struct V_62 * ) ( V_47 -> V_12 -> V_234 ) ;
V_310 = F_130 ( V_47 ) ;
if ( V_310 )
return V_310 ;
V_2 = (struct V_1 * ) V_47 -> V_306 ;
if ( ! V_2 )
return V_311 ;
if ( ! V_63 )
return V_312 ;
F_51 ( V_60 ,
L_39
L_40 ,
V_2 , V_47 , * ( ( V_11 * ) V_47 -> V_47 ) , V_63 -> V_73 ,
V_47 -> V_12 -> V_13 , F_25 ( V_60 , V_2 -> V_77 ) ) ;
if ( ( (struct V_5 * ) F_2 ( V_2 ) ) != V_47 ) {
F_52 ( V_94 , V_194 ) ;
return V_311 ;
}
V_192 = F_77 ( V_191 ) ;
V_79 = V_309 ;
F_74 ( & V_60 -> V_187 ) ;
V_193 = F_78 ( V_60 , V_2 , ( V_192 ? V_159 : V_161 ) ) ;
F_73 ( & V_60 -> V_187 ) ;
if ( V_193 != 0 ) {
if ( V_193 == - V_153 ) {
return V_311 ;
}
if ( V_192 )
F_52 ( V_94 , V_195 ) ;
else
F_52 ( V_94 , V_196 ) ;
goto V_313;
}
F_131 ( & V_2 -> V_277 ) ;
F_132 ( & V_2 -> V_277 , F_133 ( V_79 ) ) ;
if ( ( (struct V_5 * ) F_2 ( V_2 ) ) == V_47 ) {
F_106 ( V_60 , L_41 , V_2 ) ;
F_52 ( V_94 , V_267 ) ;
V_313:
if ( V_2 -> V_52 > 0 )
F_112 ( V_47 ) ;
F_74 ( & V_60 -> V_187 ) ;
F_2 ( V_2 ) = NULL ;
F_73 ( & V_60 -> V_187 ) ;
V_47 -> V_275 = ( V_223 << 16 ) ;
V_47 -> V_276 ( V_47 ) ;
return V_312 ;
}
if ( F_134 ( V_47 -> V_275 ) == V_263 ) {
F_135 ( V_60 ,
L_42 ,
V_47 -> V_12 -> V_314 , V_47 -> V_12 -> V_13 ,
V_47 -> V_315 ) ;
return V_311 ;
} else {
F_135 ( V_60 ,
L_43 ,
V_47 -> V_12 -> V_314 , V_47 -> V_12 -> V_13 ,
V_47 -> V_315 ) ;
return V_312 ;
}
}
static void
F_136 ( struct V_59 * V_60 , struct V_1 * V_37 )
{
struct V_5 * V_47 = (struct V_5 * ) F_2 ( V_37 ) ;
struct V_66 * V_67 ;
T_2 V_229 = 0 ;
struct V_225 * V_226 ;
struct V_227 * V_228 ;
F_51 ( V_60 , L_44 ,
V_37 , V_37 -> V_155 ) ;
V_47 -> V_40 . V_316 = V_37 -> V_155 ;
if ( V_37 -> V_155 == V_236 ) {
V_67 = & V_37 -> V_67 ;
V_226 = (struct V_225 * ) V_67 -> V_219 ;
V_228 = (struct V_227 * ) ( V_226 + 1 ) ;
V_229 = V_226 -> V_237 . V_238 ;
if ( V_229 & V_240 )
if ( V_228 -> V_243 == V_244 )
V_47 -> V_40 . V_316 = V_156 ;
F_51 ( V_60 , L_45 , V_228 -> V_243 ) ;
}
F_2 ( V_37 ) = NULL ;
}
static int
F_137 ( struct V_5 * V_47 )
{
struct V_190 * V_191 = F_84 ( V_47 -> V_12 -> V_280 ) ;
struct V_59 * V_60 = F_86 ( V_191 ) ;
struct V_18 * V_94 = F_18 ( V_60 ) ;
struct V_62 * V_63 = (struct V_62 * ) ( V_47 -> V_12 -> V_234 ) ;
struct V_1 * V_2 = NULL ;
struct V_285 * V_286 ;
unsigned long V_229 ;
int V_283 ;
int V_197 , V_310 ;
F_138 ( V_317 ) ;
struct V_3 V_4 ;
if ( ! V_63 )
goto V_318;
F_51 ( V_60 , L_46 ,
V_47 -> V_12 -> V_13 , V_63 -> V_73 , V_63 -> V_319 ) ;
if ( ! F_77 ( V_191 ) ) {
F_106 ( V_60 ,
L_47
L_48 ,
V_191 -> V_320 , V_47 -> V_12 -> V_13 ) ;
goto V_318;
}
V_310 = F_130 ( V_47 ) ;
if ( V_310 )
return V_310 ;
if ( F_120 ( V_63 -> V_288 ) ) {
F_106 ( V_60 ,
L_47
L_49 ,
V_63 -> V_73 , V_47 -> V_12 -> V_13 ) ;
goto V_318;
}
V_2 = F_122 ( V_60 , V_94 ) ;
if ( ! V_2 ) {
F_106 ( V_60 , L_50 ,
V_94 -> V_297 . V_147 ) ;
goto V_318;
}
V_286 = & V_60 -> V_286 [ V_191 -> V_207 ] [ F_119 () ] ;
V_2 -> V_52 = 0 ;
V_2 -> V_9 = V_191 ;
V_2 -> V_10 = V_63 ;
V_2 -> V_77 = V_286 -> V_77 ;
V_2 -> V_96 = V_286 -> V_96 ;
F_2 ( V_2 ) = V_47 ;
V_47 -> V_306 = ( unsigned char * ) V_2 ;
V_47 -> V_40 . V_316 = 0 ;
V_47 -> V_40 . V_41 = V_321 ;
V_2 -> V_79 = V_322 / 1000 ;
V_197 = F_23 ( ( V_2 -> V_79 + 10 ) * 1000 , V_323 ) ;
V_2 -> V_188 = F_136 ;
V_4 . V_7 = V_8 ;
V_4 . V_9 = V_2 -> V_9 ;
V_4 . V_10 = V_2 -> V_10 ;
V_4 . V_14 = V_47 -> V_12 -> V_13 ;
F_123 ( & V_60 -> V_187 , V_229 ) ;
V_283 = F_139 ( V_2 ) ;
F_125 ( & V_60 -> V_187 , V_229 ) ;
if ( V_283 != 0 ) {
F_106 ( V_60 , L_51 ,
V_2 , V_283 ) ;
goto V_324;
}
F_51 ( V_60 , L_52 ,
V_197 * ( V_323 / 1000 ) ) ;
while ( ( ( (struct V_5 * ) F_2 ( V_2 ) ) == V_47 )
&& V_197 -- )
F_80 ( V_323 ) ;
if ( ( (struct V_5 * ) F_2 ( V_2 ) ) == V_47 ) {
F_106 ( V_60 , L_53 ,
V_47 -> V_12 -> V_314 , V_47 -> V_12 -> V_13 ) ;
F_74 ( & V_60 -> V_187 ) ;
F_72 ( V_2 ) ;
F_7 ( & V_2 -> V_144 . V_146 ) ;
F_73 ( & V_60 -> V_187 ) ;
goto V_324;
}
if ( V_47 -> V_40 . V_316 != V_156 ) {
F_106 ( V_60 , L_54 ,
V_47 -> V_12 -> V_314 , V_47 -> V_12 -> V_13 , V_47 -> V_40 . V_316 ) ;
goto V_318;
}
F_74 ( & V_60 -> V_187 ) ;
F_3 ( V_94 , & V_4 , & V_317 ) ;
V_283 = F_79 ( V_94 , & V_317 , 30000 ) ;
F_73 ( & V_60 -> V_187 ) ;
if ( V_283 != 0 ) {
F_106 ( V_60 ,
L_55
L_56 , V_47 -> V_12 -> V_13 , V_283 ) ;
F_74 ( & V_60 -> V_187 ) ;
F_5 ( & V_317 , & V_94 -> V_24 ) ;
F_73 ( & V_60 -> V_187 ) ;
goto V_318;
}
F_52 ( V_63 , V_325 ) ;
F_135 ( V_60 , L_57 ,
V_47 -> V_12 -> V_314 , V_47 -> V_12 -> V_13 ) ;
return V_311 ;
V_324:
F_126 ( V_60 , V_94 , V_2 ) ;
V_318:
F_52 ( V_63 , V_326 ) ;
return V_312 ;
}
static int
F_140 ( struct V_327 * V_328 )
{
struct V_287 * V_288 = F_116 ( F_117 ( V_328 ) ) ;
if ( ! V_288 || F_120 ( V_288 ) )
return - V_329 ;
V_328 -> V_234 = * ( (struct V_190 * * ) ( V_288 -> V_330 ) ) ;
return 0 ;
}
static int
F_141 ( struct V_327 * V_328 )
{
if ( V_328 -> V_331 )
F_142 ( V_328 , V_332 ) ;
else
F_143 ( V_328 , V_332 ) ;
return 0 ;
}
static void
F_144 ( struct V_327 * V_328 )
{
V_328 -> V_234 = NULL ;
}
static int
F_145 ( struct V_279 * V_333 , unsigned long time )
{
struct V_190 * V_191 = F_84 ( V_333 ) ;
int V_193 = 1 ;
F_74 ( V_333 -> V_334 ) ;
if ( ! V_191 -> V_61 || F_146 ( & V_191 -> V_144 . V_146 ) )
goto V_245;
V_193 = F_147 ( V_191 , V_335 , time , V_336 * V_337 ,
V_338 * V_337 ) ;
V_245:
F_73 ( V_333 -> V_334 ) ;
return V_193 ;
}
static int
F_148 ( struct V_18 * V_19 , struct V_59 * V_60 ,
int V_339 , int V_340 )
{
int V_341 = 0 ;
struct V_20 * V_22 ;
struct V_66 * V_342 = NULL ;
T_3 V_343 = 0 ;
if ( ! V_340 )
return 0 ;
if ( ! V_339 )
return - V_153 ;
F_53 ( & V_19 -> V_344 ) ;
V_339 = ( V_339 + V_205 - 1 ) & V_221 ;
for ( V_341 = 0 ; V_341 < V_340 ; V_341 ++ ) {
V_343 = V_339 ;
V_342 = F_149 ( sizeof( struct V_66 ) , V_345 ) ;
if ( ! V_342 ) {
F_106 ( V_60 ,
L_58
L_59 ,
V_19 -> V_297 . V_346 ) ;
goto V_347;
}
V_342 -> V_219 = F_150 ( V_60 -> V_348 , V_343 ,
& V_342 -> V_85 ) ;
if ( ! V_342 -> V_219 ) {
F_106 ( V_60 ,
L_60
L_61 ) ;
F_151 ( V_342 ) ;
goto V_347;
}
V_342 -> V_83 = V_343 ;
F_8 ( & V_342 -> V_136 , & V_19 -> V_344 ) ;
F_52 ( V_19 , V_346 ) ;
}
return 0 ;
V_347:
F_39 (tmp, &scm->ddp_freelist) {
V_342 = (struct V_66 * ) V_22 ;
V_22 = F_152 ( V_22 ) ;
F_153 ( V_60 -> V_348 , V_342 -> V_83 , V_342 -> V_219 ,
V_342 -> V_85 ) ;
F_7 ( & V_342 -> V_136 ) ;
F_151 ( V_342 ) ;
}
V_19 -> V_297 . V_346 = 0 ;
return - V_349 ;
}
static void
F_154 ( struct V_18 * V_19 , struct V_59 * V_60 )
{
struct V_20 * V_22 ;
struct V_66 * V_342 ;
F_39 (tmp, &scm->ddp_freelist) {
V_342 = (struct V_66 * ) V_22 ;
V_22 = F_152 ( V_22 ) ;
F_153 ( V_60 -> V_348 , V_342 -> V_83 , V_342 -> V_219 ,
V_342 -> V_85 ) ;
F_7 ( & V_342 -> V_136 ) ;
F_151 ( V_342 ) ;
}
V_19 -> V_297 . V_346 = 0 ;
}
int
F_155 ( struct V_18 * V_19 , struct V_59 * V_60 )
{
int V_107 ;
struct V_1 * V_2 ;
struct V_66 * V_67 ;
F_53 ( & V_19 -> V_24 ) ;
V_19 -> V_60 = V_60 ;
V_19 -> V_69 = sizeof( struct V_39 ) ;
V_19 -> V_350 = V_351 ;
V_19 -> V_134 = V_352 ;
F_156 ( & V_19 -> V_189 ) ;
F_53 ( & V_19 -> V_353 ) ;
for ( V_107 = 0 ; V_107 < V_354 ; V_107 ++ ) {
V_2 = F_149 ( sizeof( struct V_1 ) , V_345 ) ;
if ( ! V_2 ) {
F_106 ( V_60 ,
L_62
L_59 ,
V_19 -> V_297 . V_355 ) ;
goto V_356;
}
V_67 = & V_2 -> V_67 ;
V_67 -> V_219 = F_157 ( V_60 -> V_357 , V_345 ,
& V_67 -> V_85 ) ;
if ( ! V_67 -> V_219 ) {
F_106 ( V_60 ,
L_63
L_61 ) ;
F_151 ( V_2 ) ;
goto V_356;
}
V_67 -> V_83 = V_19 -> V_350 ;
F_158 ( & V_2 -> V_144 , F_60 ) ;
F_53 ( & V_2 -> V_133 ) ;
F_131 ( & V_2 -> V_277 ) ;
F_8 ( & V_2 -> V_144 . V_146 , & V_19 -> V_353 ) ;
F_52 ( V_19 , V_355 ) ;
}
if ( F_148 ( V_19 , V_60 , V_205 , V_358 ) )
goto V_356;
return 0 ;
V_356:
while ( ! F_4 ( & V_19 -> V_353 ) ) {
struct V_359 * V_22 ;
V_22 = F_159 ( & V_19 -> V_353 ,
struct V_359 , V_146 ) ;
F_7 ( & V_22 -> V_146 ) ;
V_2 = (struct V_1 * ) V_22 ;
V_67 = & V_2 -> V_67 ;
F_160 ( V_60 -> V_357 , V_67 -> V_219 ,
V_67 -> V_85 ) ;
F_151 ( V_2 ) ;
}
V_19 -> V_297 . V_355 = 0 ;
return - V_349 ;
}
void
F_161 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
struct V_66 * V_67 ;
while ( ! F_4 ( & V_19 -> V_353 ) ) {
struct V_359 * V_22 ;
V_22 = F_159 ( & V_19 -> V_353 ,
struct V_359 , V_146 ) ;
F_7 ( & V_22 -> V_146 ) ;
V_2 = (struct V_1 * ) V_22 ;
V_67 = & V_2 -> V_67 ;
F_160 ( V_19 -> V_60 -> V_357 , V_67 -> V_219 ,
V_67 -> V_85 ) ;
F_151 ( V_2 ) ;
}
V_19 -> V_297 . V_355 = 0 ;
F_154 ( V_19 , V_19 -> V_60 ) ;
}
