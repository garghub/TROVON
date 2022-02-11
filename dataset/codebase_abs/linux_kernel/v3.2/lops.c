static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
F_2 ( ! V_7 -> V_8 ) ;
F_3 ( V_4 ) ;
if ( F_4 ( V_4 ) )
F_5 ( V_2 , 0 ) ;
if ( ! F_6 ( V_4 ) )
F_7 ( V_2 , V_4 ) ;
V_6 = V_4 -> V_9 ;
F_8 ( & V_2 -> V_10 ) ;
if ( V_6 -> V_11 )
F_9 ( & V_6 -> V_12 , & V_6 -> V_11 -> V_13 ) ;
F_10 ( & V_2 -> V_10 ) ;
F_11 ( V_4 ) ;
F_12 ( & V_2 -> V_14 ) ;
F_13 ( V_6 , 1 ) ;
}
static bool F_14 ( const struct V_5 * V_6 )
{
return V_6 -> V_15 -> V_16 . V_17 == V_18 ;
}
static void F_15 ( struct V_5 * V_6 )
{
struct V_19 * V_20 = V_6 -> V_15 ;
struct V_1 * V_2 = V_20 -> V_21 ;
struct V_22 * V_23 = V_20 -> V_24 ;
unsigned int V_25 = V_6 -> V_26 -> V_27 - V_20 -> V_16 . V_28 ;
struct V_29 * V_30 = V_23 -> V_31 + V_25 ;
if ( V_30 -> V_32 == 0 )
return;
if ( V_2 -> V_33 . V_34 )
F_16 ( V_2 , V_23 -> V_35 , V_6 -> V_26 , V_30 ) ;
memcpy ( V_30 -> V_32 + V_30 -> V_36 ,
V_6 -> V_26 -> V_37 + V_30 -> V_36 , V_30 -> V_38 ) ;
F_17 ( V_39 , & V_30 -> V_40 ) ;
V_23 -> V_41 = V_23 -> V_42 ;
}
static void F_18 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_43 * V_44 )
{
struct V_5 * V_6 = V_4 -> V_9 ;
F_2 ( ! F_6 ( V_4 ) ) ;
F_2 ( ! F_19 ( V_4 ) ) ;
F_20 ( V_4 ) ;
F_21 ( V_4 ) ;
F_22 ( V_4 ) ;
if ( F_14 ( V_6 ) )
F_15 ( V_6 ) ;
F_8 ( & V_2 -> V_10 ) ;
if ( V_6 -> V_11 ) {
F_23 ( & V_6 -> V_12 ) ;
F_24 ( V_4 ) ;
} else {
struct V_19 * V_20 = V_6 -> V_15 ;
F_25 ( & V_6 -> V_45 , & V_20 -> V_46 ) ;
F_12 ( & V_20 -> V_47 ) ;
}
V_6 -> V_11 = V_44 ;
F_25 ( & V_6 -> V_12 , & V_44 -> V_48 ) ;
F_10 ( & V_2 -> V_10 ) ;
F_17 ( V_49 , & V_6 -> V_15 -> V_50 ) ;
F_13 ( V_6 , 0 ) ;
F_26 ( V_4 ) ;
F_27 ( & V_2 -> V_14 ) ;
}
static inline struct V_51 * F_28 ( struct V_3 * V_4 )
{
return (struct V_51 * ) V_4 -> V_37 ;
}
static inline T_1 * F_29 ( struct V_3 * V_4 )
{
struct V_51 * V_52 = F_28 ( V_4 ) ;
return ( V_53 T_1 * ) ( V_52 + 1 ) ;
}
static inline T_1 * F_30 ( struct V_3 * V_4 )
{
return ( V_53 T_1 * ) ( V_4 -> V_37 + V_4 -> V_54 ) ;
}
static struct V_3 * F_31 ( struct V_1 * V_2 , T_2 V_55 )
{
struct V_3 * V_4 = F_32 ( V_2 ) ;
struct V_51 * V_52 = F_28 ( V_4 ) ;
V_52 -> V_56 . V_57 = F_33 ( V_58 ) ;
V_52 -> V_56 . V_59 = F_33 ( V_60 ) ;
V_52 -> V_56 . V_61 = F_33 ( V_62 ) ;
V_52 -> V_55 = F_33 ( V_55 ) ;
V_52 -> V_63 = 0 ;
V_52 -> V_64 = 0 ;
V_52 -> V_65 = 0 ;
memset ( V_52 -> V_66 , 0 , sizeof( V_52 -> V_66 ) ) ;
return V_4 ;
}
static void F_34 ( struct V_1 * V_2 , struct V_67 * V_68 )
{
struct V_5 * V_6 = F_35 ( V_68 , struct V_5 , V_69 ) ;
struct V_70 * V_71 ;
struct V_72 * V_73 ;
F_20 ( V_6 -> V_26 ) ;
F_36 ( V_2 ) ;
if ( ! F_37 ( & V_6 -> V_74 ) )
goto V_75;
V_73 = V_7 -> V_8 ;
V_73 -> V_76 = 1 ;
V_73 -> V_77 ++ ;
F_25 ( & V_6 -> V_74 , & V_73 -> V_78 ) ;
if ( ! F_37 ( & V_68 -> V_79 ) )
goto V_75;
F_38 ( V_49 , & V_6 -> V_15 -> V_50 ) ;
F_38 ( V_80 , & V_6 -> V_15 -> V_50 ) ;
F_39 ( V_2 , V_6 -> V_26 ) ;
F_1 ( V_2 , V_6 -> V_26 ) ;
V_71 = (struct V_70 * ) V_6 -> V_26 -> V_37 ;
V_71 -> V_81 = F_40 ( 0 ) ;
V_71 -> V_82 = F_33 ( V_2 -> V_83 -> V_84 ) ;
V_2 -> V_85 ++ ;
F_25 ( & V_68 -> V_79 , & V_2 -> V_86 ) ;
V_73 -> V_87 ++ ;
V_75:
F_41 ( V_2 ) ;
F_26 ( V_6 -> V_26 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_51 * V_52 ;
struct V_5 * V_88 = NULL , * V_89 ;
unsigned int V_90 ;
unsigned int V_91 ;
unsigned int V_92 ;
unsigned V_93 ;
T_1 * V_94 ;
V_91 = F_43 ( V_2 ) ;
F_36 ( V_2 ) ;
V_90 = V_2 -> V_85 ;
V_88 = V_89 = F_44 ( V_88 , & V_2 -> V_86 , V_69 . V_79 ) ;
while( V_90 ) {
V_92 = V_90 ;
if ( V_90 > V_91 )
V_92 = V_91 ;
F_41 ( V_2 ) ;
V_4 = F_31 ( V_2 , V_95 ) ;
F_36 ( V_2 ) ;
V_52 = F_28 ( V_4 ) ;
V_94 = F_29 ( V_4 ) ;
V_52 -> V_63 = F_33 ( V_92 + 1 ) ;
V_52 -> V_64 = F_33 ( V_92 ) ;
V_93 = 0 ;
F_45 (bd1, &sdp->sd_log_le_buf,
bd_le.le_list) {
* V_94 ++ = F_40 ( V_88 -> V_26 -> V_27 ) ;
if ( ++ V_93 >= V_92 )
break;
}
F_41 ( V_2 ) ;
F_46 ( V_96 , V_4 ) ;
F_36 ( V_2 ) ;
V_93 = 0 ;
F_45 (bd2, &sdp->sd_log_le_buf,
bd_le.le_list) {
F_11 ( V_89 -> V_26 ) ;
F_41 ( V_2 ) ;
F_20 ( V_89 -> V_26 ) ;
V_4 = F_47 ( V_2 , V_89 -> V_26 ) ;
F_46 ( V_96 , V_4 ) ;
F_36 ( V_2 ) ;
if ( ++ V_93 >= V_92 )
break;
}
F_2 ( V_90 < V_92 ) ;
V_90 -= V_92 ;
}
F_41 ( V_2 ) ;
}
static void F_48 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
struct V_97 * V_98 = & V_2 -> V_86 ;
struct V_5 * V_6 ;
while ( ! F_37 ( V_98 ) ) {
V_6 = F_49 ( V_98 -> V_99 , struct V_5 , V_69 . V_79 ) ;
F_50 ( & V_6 -> V_69 . V_79 ) ;
V_2 -> V_85 -- ;
F_18 ( V_2 , V_6 -> V_26 , V_44 ) ;
}
F_51 ( V_2 , ! V_2 -> V_85 ) ;
}
static void F_52 ( struct V_100 * V_101 ,
struct V_102 * V_98 , int V_103 )
{
struct V_1 * V_2 = F_53 ( V_101 -> V_104 ) ;
if ( V_103 != 0 )
return;
V_2 -> V_105 = 0 ;
V_2 -> V_106 = 0 ;
}
static int F_54 ( struct V_100 * V_101 , unsigned int V_107 ,
struct V_51 * V_52 , T_1 * V_94 ,
int V_103 )
{
struct V_108 * V_109 = F_55 ( V_101 -> V_104 ) ;
struct V_1 * V_2 = F_53 ( V_101 -> V_104 ) ;
struct V_19 * V_20 = V_109 -> V_110 ;
unsigned int V_111 = F_56 ( V_52 -> V_64 ) ;
struct V_3 * V_112 , * V_113 ;
T_3 V_114 ;
int error = 0 ;
if ( V_103 != 1 || F_56 ( V_52 -> V_55 ) != V_95 )
return 0 ;
F_57 ( V_2 , & V_107 ) ;
for (; V_111 ; F_57 ( V_2 , & V_107 ) , V_111 -- ) {
V_114 = F_58 ( * V_94 ++ ) ;
V_2 -> V_105 ++ ;
if ( F_59 ( V_2 , V_114 , V_107 ) )
continue;
error = F_60 ( V_101 , V_107 , & V_112 ) ;
if ( error )
return error ;
V_113 = F_61 ( V_20 , V_114 ) ;
memcpy ( V_113 -> V_37 , V_112 -> V_37 , V_112 -> V_54 ) ;
if ( F_39 ( V_2 , V_113 ) )
error = - V_115 ;
else
F_21 ( V_113 ) ;
F_24 ( V_112 ) ;
F_24 ( V_113 ) ;
if ( error )
break;
V_2 -> V_106 ++ ;
}
return error ;
}
static void F_62 ( struct V_100 * V_101 , int error , int V_103 )
{
struct V_108 * V_109 = F_55 ( V_101 -> V_104 ) ;
struct V_1 * V_2 = F_53 ( V_101 -> V_104 ) ;
if ( error ) {
F_63 ( V_109 -> V_110 ) ;
return;
}
if ( V_103 != 1 )
return;
F_63 ( V_109 -> V_110 ) ;
F_64 ( V_2 , L_1 ,
V_101 -> V_84 , V_2 -> V_106 , V_2 -> V_105 ) ;
}
static void F_65 ( struct V_1 * V_2 , struct V_67 * V_68 )
{
struct V_5 * V_6 = F_35 ( V_68 , struct V_5 , V_69 ) ;
struct V_19 * V_20 = V_6 -> V_15 ;
struct V_72 * V_73 ;
V_73 = V_7 -> V_8 ;
V_73 -> V_76 = 1 ;
V_73 -> V_116 ++ ;
V_2 -> V_117 ++ ;
F_12 ( & V_20 -> V_118 ) ;
F_38 ( V_49 , & V_20 -> V_50 ) ;
F_25 ( & V_68 -> V_79 , & V_2 -> V_119 ) ;
}
static void F_66 ( struct V_1 * V_2 )
{
struct V_51 * V_52 ;
struct V_70 * V_71 ;
struct V_3 * V_4 ;
unsigned int V_120 ;
struct V_97 * V_98 = & V_2 -> V_119 ;
struct V_5 * V_6 ;
if ( ! V_2 -> V_117 )
return;
V_4 = F_31 ( V_2 , V_121 ) ;
V_52 = F_28 ( V_4 ) ;
V_52 -> V_63 = F_33 ( F_67 ( V_2 , V_2 -> V_117 ,
sizeof( T_3 ) ) ) ;
V_52 -> V_64 = F_33 ( V_2 -> V_117 ) ;
V_120 = sizeof( struct V_51 ) ;
F_68 (bd, head, bd_le.le_list) {
V_2 -> V_117 -- ;
if ( V_120 + sizeof( T_3 ) > V_2 -> V_122 . V_123 ) {
F_46 ( V_96 , V_4 ) ;
V_4 = F_32 ( V_2 ) ;
V_71 = (struct V_70 * ) V_4 -> V_37 ;
V_71 -> V_57 = F_33 ( V_58 ) ;
V_71 -> V_59 = F_33 ( V_124 ) ;
V_71 -> V_61 = F_33 ( V_125 ) ;
V_120 = sizeof( struct V_70 ) ;
}
* ( T_1 * ) ( V_4 -> V_37 + V_120 ) = F_40 ( V_6 -> V_126 ) ;
V_120 += sizeof( T_3 ) ;
}
F_5 ( V_2 , ! V_2 -> V_117 ) ;
F_46 ( V_96 , V_4 ) ;
}
static void F_69 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
struct V_97 * V_98 = & V_2 -> V_119 ;
struct V_5 * V_6 ;
struct V_19 * V_20 ;
while ( ! F_37 ( V_98 ) ) {
V_6 = F_49 ( V_98 -> V_99 , struct V_5 , V_69 . V_79 ) ;
F_50 ( & V_6 -> V_69 . V_79 ) ;
V_20 = V_6 -> V_15 ;
F_27 ( & V_20 -> V_118 ) ;
F_17 ( V_49 , & V_20 -> V_50 ) ;
F_70 ( V_127 , V_6 ) ;
}
}
static void F_71 ( struct V_100 * V_101 ,
struct V_102 * V_98 , int V_103 )
{
struct V_1 * V_2 = F_53 ( V_101 -> V_104 ) ;
if ( V_103 != 0 )
return;
V_2 -> V_128 = 0 ;
V_2 -> V_129 = V_98 -> V_130 ;
}
static int F_72 ( struct V_100 * V_101 , unsigned int V_107 ,
struct V_51 * V_52 , T_1 * V_94 ,
int V_103 )
{
struct V_1 * V_2 = F_53 ( V_101 -> V_104 ) ;
unsigned int V_111 = F_56 ( V_52 -> V_63 ) ;
unsigned int V_131 = F_56 ( V_52 -> V_64 ) ;
struct V_3 * V_4 ;
unsigned int V_120 ;
T_3 V_114 ;
int V_132 = 1 ;
int error ;
if ( V_103 != 0 || F_56 ( V_52 -> V_55 ) != V_121 )
return 0 ;
V_120 = sizeof( struct V_51 ) ;
for (; V_111 ; F_57 ( V_2 , & V_107 ) , V_111 -- ) {
error = F_60 ( V_101 , V_107 , & V_4 ) ;
if ( error )
return error ;
if ( ! V_132 )
F_73 ( V_2 , V_4 , V_124 ) ;
while ( V_120 + sizeof( T_3 ) <= V_2 -> V_122 . V_123 ) {
V_114 = F_58 ( * ( T_1 * ) ( V_4 -> V_37 + V_120 ) ) ;
error = F_74 ( V_2 , V_114 , V_107 ) ;
if ( error < 0 ) {
F_24 ( V_4 ) ;
return error ;
}
else if ( error )
V_2 -> V_128 ++ ;
if ( ! -- V_131 )
break;
V_120 += sizeof( T_3 ) ;
}
F_24 ( V_4 ) ;
V_120 = sizeof( struct V_70 ) ;
V_132 = 0 ;
}
return 0 ;
}
static void F_75 ( struct V_100 * V_101 , int error , int V_103 )
{
struct V_1 * V_2 = F_53 ( V_101 -> V_104 ) ;
if ( error ) {
F_76 ( V_2 ) ;
return;
}
if ( V_103 != 1 )
return;
F_64 ( V_2 , L_2 ,
V_101 -> V_84 , V_2 -> V_128 ) ;
F_76 ( V_2 ) ;
}
static void F_77 ( struct V_1 * V_2 , struct V_67 * V_68 )
{
struct V_5 * V_6 = F_35 ( V_68 , struct V_5 , V_69 ) ;
struct V_72 * V_73 = V_7 -> V_8 ;
struct V_133 * V_134 = V_6 -> V_26 -> V_135 -> V_134 ;
struct V_108 * V_109 = F_55 ( V_134 -> V_136 ) ;
F_20 ( V_6 -> V_26 ) ;
F_36 ( V_2 ) ;
if ( V_73 ) {
if ( ! F_37 ( & V_6 -> V_74 ) )
goto V_75;
V_73 -> V_76 = 1 ;
if ( F_78 ( V_109 ) ) {
V_73 -> V_77 ++ ;
F_25 ( & V_6 -> V_74 , & V_73 -> V_78 ) ;
}
}
if ( ! F_37 ( & V_68 -> V_79 ) )
goto V_75;
F_38 ( V_49 , & V_6 -> V_15 -> V_50 ) ;
F_38 ( V_80 , & V_6 -> V_15 -> V_50 ) ;
if ( F_78 ( V_109 ) ) {
F_1 ( V_2 , V_6 -> V_26 ) ;
V_73 -> V_137 ++ ;
V_2 -> V_138 ++ ;
F_79 ( & V_68 -> V_79 , & V_2 -> V_139 ) ;
} else {
F_79 ( & V_68 -> V_79 , & V_2 -> V_140 ) ;
}
V_75:
F_41 ( V_2 ) ;
F_26 ( V_6 -> V_26 ) ;
}
static void F_80 ( struct V_3 * V_4 )
{
void * V_141 ;
T_4 * V_94 ;
F_81 ( V_4 ) ;
V_141 = F_82 ( V_4 -> V_135 , V_142 ) ;
V_94 = V_141 + F_83 ( V_4 ) ;
if ( * V_94 == F_33 ( V_58 ) )
F_84 ( V_4 ) ;
F_85 ( V_141 , V_142 ) ;
}
static void F_86 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_97 * V_143 , struct V_97 * V_144 ,
unsigned int V_93 )
{
struct V_3 * V_145 ;
struct V_51 * V_52 ;
struct V_5 * V_6 ;
T_1 * V_94 ;
if ( ! V_4 )
return;
V_52 = F_28 ( V_4 ) ;
V_52 -> V_63 = F_33 ( V_93 + 1 ) ;
V_52 -> V_64 = F_33 ( V_93 ) ;
V_94 = F_29 ( V_4 ) ;
F_11 ( V_4 ) ;
F_46 ( V_96 , V_4 ) ;
F_36 ( V_2 ) ;
while( ! F_37 ( V_143 ) ) {
V_6 = F_49 ( V_143 -> V_99 , struct V_5 , V_69 . V_79 ) ;
F_87 ( & V_6 -> V_69 . V_79 , V_144 ) ;
F_11 ( V_6 -> V_26 ) ;
while ( F_58 ( * V_94 ) != V_6 -> V_26 -> V_27 ) {
F_88 ( V_2 ) ;
V_94 += 2 ;
}
F_41 ( V_2 ) ;
F_20 ( V_6 -> V_26 ) ;
if ( F_89 ( V_6 -> V_26 ) ) {
void * V_141 ;
V_145 = F_32 ( V_2 ) ;
V_141 = F_82 ( V_6 -> V_26 -> V_135 , V_142 ) ;
memcpy ( V_145 -> V_37 , V_141 + F_83 ( V_6 -> V_26 ) ,
V_145 -> V_54 ) ;
F_85 ( V_141 , V_142 ) ;
* ( T_4 * ) V_145 -> V_37 = 0 ;
F_81 ( V_6 -> V_26 ) ;
F_26 ( V_6 -> V_26 ) ;
F_24 ( V_6 -> V_26 ) ;
} else {
V_145 = F_47 ( V_2 , V_6 -> V_26 ) ;
}
F_46 ( V_96 , V_145 ) ;
F_36 ( V_2 ) ;
V_94 += 2 ;
}
F_41 ( V_2 ) ;
F_24 ( V_4 ) ;
}
static void F_90 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = NULL ;
struct V_3 * V_4 = NULL ;
unsigned int V_93 = 0 ;
T_1 * V_94 = NULL , * V_146 = NULL ;
F_91 ( V_147 ) ;
F_91 ( V_148 ) ;
F_36 ( V_2 ) ;
while ( ! F_37 ( & V_2 -> V_139 ) ) {
if ( V_94 == V_146 ) {
F_41 ( V_2 ) ;
F_86 ( V_2 , V_4 , & V_148 , & V_147 , V_93 ) ;
V_93 = 0 ;
V_4 = F_31 ( V_2 , V_149 ) ;
V_94 = F_29 ( V_4 ) ;
V_146 = F_30 ( V_4 ) - 1 ;
F_36 ( V_2 ) ;
continue;
}
V_6 = F_49 ( V_2 -> V_139 . V_99 , struct V_5 , V_69 . V_79 ) ;
F_87 ( & V_6 -> V_69 . V_79 , & V_148 ) ;
F_80 ( V_6 -> V_26 ) ;
* V_94 ++ = F_40 ( V_6 -> V_26 -> V_27 ) ;
* V_94 ++ = F_40 ( F_89 ( V_4 ) ? 1 : 0 ) ;
V_93 ++ ;
}
F_41 ( V_2 ) ;
F_86 ( V_2 , V_4 , & V_148 , & V_147 , V_93 ) ;
F_36 ( V_2 ) ;
F_92 ( & V_147 , & V_2 -> V_139 ) ;
F_41 ( V_2 ) ;
}
static int F_93 ( struct V_100 * V_101 , unsigned int V_107 ,
struct V_51 * V_52 ,
T_1 * V_94 , int V_103 )
{
struct V_108 * V_109 = F_55 ( V_101 -> V_104 ) ;
struct V_1 * V_2 = F_53 ( V_101 -> V_104 ) ;
struct V_19 * V_20 = V_109 -> V_110 ;
unsigned int V_111 = F_56 ( V_52 -> V_64 ) ;
struct V_3 * V_112 , * V_113 ;
T_3 V_114 ;
T_3 V_150 ;
int error = 0 ;
if ( V_103 != 1 || F_56 ( V_52 -> V_55 ) != V_149 )
return 0 ;
F_57 ( V_2 , & V_107 ) ;
for (; V_111 ; F_57 ( V_2 , & V_107 ) , V_111 -- ) {
V_114 = F_58 ( * V_94 ++ ) ;
V_150 = F_58 ( * V_94 ++ ) ;
V_2 -> V_105 ++ ;
if ( F_59 ( V_2 , V_114 , V_107 ) )
continue;
error = F_60 ( V_101 , V_107 , & V_112 ) ;
if ( error )
return error ;
V_113 = F_61 ( V_20 , V_114 ) ;
memcpy ( V_113 -> V_37 , V_112 -> V_37 , V_112 -> V_54 ) ;
if ( V_150 ) {
T_4 * V_151 = ( T_4 * ) V_113 -> V_37 ;
* V_151 = F_33 ( V_58 ) ;
}
F_21 ( V_113 ) ;
F_24 ( V_112 ) ;
F_24 ( V_113 ) ;
V_2 -> V_106 ++ ;
}
return error ;
}
static void F_94 ( struct V_100 * V_101 , int error , int V_103 )
{
struct V_108 * V_109 = F_55 ( V_101 -> V_104 ) ;
struct V_1 * V_2 = F_53 ( V_101 -> V_104 ) ;
if ( error ) {
F_63 ( V_109 -> V_110 ) ;
return;
}
if ( V_103 != 1 )
return;
F_63 ( V_109 -> V_110 ) ;
F_64 ( V_2 , L_3 ,
V_101 -> V_84 , V_2 -> V_106 , V_2 -> V_105 ) ;
}
static void F_95 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
struct V_97 * V_98 = & V_2 -> V_139 ;
struct V_5 * V_6 ;
while ( ! F_37 ( V_98 ) ) {
V_6 = F_49 ( V_98 -> V_99 , struct V_5 , V_69 . V_79 ) ;
F_50 ( & V_6 -> V_69 . V_79 ) ;
V_2 -> V_138 -- ;
F_18 ( V_2 , V_6 -> V_26 , V_44 ) ;
}
F_51 ( V_2 , ! V_2 -> V_138 ) ;
}
