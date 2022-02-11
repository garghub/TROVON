void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 == 0 ) {
F_2 ( V_4 L_1 ) ;
return;
}
F_3 (fi) {
if ( V_5 -> V_6 )
F_4 ( V_5 -> V_6 ) ;
V_5 -> V_6 = NULL ;
} F_5 ( V_2 ) ;
F_6 ( V_2 ) ;
}
void F_7 ( struct V_1 * V_2 )
{
F_8 ( & V_7 ) ;
if ( V_2 && -- V_2 -> V_8 == 0 ) {
if ( V_2 -> V_9 )
V_2 -> V_9 -> V_10 = V_2 -> V_10 ;
if ( V_2 -> V_10 )
V_2 -> V_10 -> V_9 = V_2 -> V_9 ;
if ( V_2 == V_11 )
V_11 = V_2 -> V_9 ;
V_2 -> V_3 = 1 ;
F_9 ( V_2 ) ;
}
F_10 ( & V_7 ) ;
}
static inline int F_11 ( const struct V_1 * V_2 , const struct V_1 * V_12 )
{
const struct V_13 * V_14 = V_12 -> V_15 ;
F_12 (fi) {
if ( V_5 -> V_16 != V_14 -> V_16 ||
V_5 -> V_17 != V_14 -> V_17 ||
V_5 -> V_18 != V_14 -> V_18 ||
V_5 -> V_19 != V_14 -> V_19 ||
( ( V_5 -> V_20 ^ V_14 -> V_20 ) & ~ V_21 ) )
return - 1 ;
V_14 ++ ;
} F_5 ( V_2 ) ;
return 0 ;
}
static inline struct V_1 * F_13 ( const struct V_1 * V_22 )
{
F_14 () {
if ( V_2 -> V_23 != V_22 -> V_23 )
continue;
if ( V_22 -> V_24 == V_2 -> V_24 &&
V_22 -> V_25 == V_2 -> V_25 &&
V_22 -> V_26 == V_2 -> V_26 &&
memcmp ( V_22 -> V_27 , V_2 -> V_27 , sizeof( V_2 -> V_27 ) ) == 0 &&
( ( V_22 -> V_28 ^ V_2 -> V_28 ) & ~ V_21 ) == 0 &&
( V_22 -> V_23 == 0 || F_11 ( V_2 , V_22 ) == 0 ) )
return V_2 ;
} F_15 () ;
return NULL ;
}
static int F_16 ( const struct V_29 * V_30 )
{
struct V_31 * V_32 = F_17 ( V_30 ) ;
int V_33 = 0 , V_34 = F_18 ( V_30 ) ;
while ( F_19 ( V_32 , V_34 ) ) {
V_33 ++ ;
V_32 = F_20 ( V_32 , & V_34 ) ;
}
return V_34 > 0 ? 0 : V_33 ;
}
static int F_21 ( struct V_1 * V_2 , const struct V_29 * V_30 ,
const struct V_35 * V_36 )
{
struct V_31 * V_32 = F_17 ( V_30 ) ;
int V_34 = F_18 ( V_30 ) ;
F_3 (fi) {
int V_37 ;
if ( ! F_19 ( V_32 , V_34 ) )
return - V_38 ;
V_5 -> V_20 = ( V_36 -> V_39 & ~ 0xFF ) | V_32 -> V_40 ;
V_5 -> V_16 = V_32 -> V_41 ;
V_5 -> V_19 = V_32 -> V_42 + 1 ;
V_37 = F_22 ( V_32 ) ;
if ( V_37 > 0 ) {
struct V_29 * V_43 ;
V_43 = F_23 ( (struct V_29 * ) ( V_32 + 1 ) , V_37 , V_44 ) ;
V_5 -> V_17 = V_43 ? F_24 ( V_43 ) : 0 ;
}
V_32 = F_20 ( V_32 , & V_34 ) ;
} F_5 ( V_2 ) ;
return 0 ;
}
static int F_25 ( const struct V_35 * V_36 , struct V_1 * V_2 , struct V_13 * V_5 )
{
int V_45 ;
if ( V_5 -> V_17 ) {
struct V_46 V_47 ;
struct V_48 V_49 ;
if ( V_5 -> V_20 & V_50 ) {
struct V_51 * V_52 ;
if ( V_36 -> V_53 >= V_54 )
return - V_38 ;
if ( F_26 ( V_5 -> V_17 ) != V_55 )
return - V_38 ;
if ( ( V_52 = F_27 ( & V_56 , V_5 -> V_16 ) ) == NULL )
return - V_57 ;
if ( ! ( V_52 -> V_58 & V_59 ) )
return - V_60 ;
V_5 -> V_6 = V_52 ;
F_28 ( V_52 ) ;
V_5 -> V_18 = V_54 ;
return 0 ;
}
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
V_47 . V_61 = V_5 -> V_17 ;
V_47 . V_62 = V_5 -> V_16 ;
V_47 . V_63 = V_36 -> V_53 + 1 ;
if ( V_47 . V_63 < V_54 )
V_47 . V_63 = V_54 ;
if ( ( V_45 = F_29 ( & V_47 , & V_49 ) ) != 0 )
return V_45 ;
V_45 = - V_38 ;
if ( V_49 . type != V_55 && V_49 . type != V_64 )
goto V_65;
V_5 -> V_18 = V_49 . V_66 ;
V_5 -> V_16 = F_30 ( V_49 ) ;
V_5 -> V_6 = F_31 ( V_49 ) ;
if ( V_5 -> V_6 == NULL )
goto V_65;
F_28 ( V_5 -> V_6 ) ;
V_45 = - V_60 ;
if ( ! ( V_5 -> V_6 -> V_58 & V_59 ) )
goto V_65;
V_45 = 0 ;
V_65:
F_32 ( & V_49 ) ;
return V_45 ;
} else {
struct V_51 * V_52 ;
if ( V_5 -> V_20 & ( V_67 | V_50 ) )
return - V_38 ;
V_52 = F_27 ( & V_56 , V_5 -> V_16 ) ;
if ( V_52 == NULL || V_52 -> V_68 == NULL )
return - V_57 ;
if ( ! ( V_52 -> V_58 & V_59 ) )
return - V_60 ;
V_5 -> V_6 = V_52 ;
F_28 ( V_5 -> V_6 ) ;
V_5 -> V_18 = V_69 ;
}
return 0 ;
}
struct V_1 * F_33 ( const struct V_35 * V_36 , struct V_29 * V_70 [] ,
const struct V_71 * V_72 , int * V_73 )
{
int V_45 ;
struct V_1 * V_2 = NULL ;
struct V_1 * V_12 ;
int V_33 = 1 ;
if ( V_36 -> V_74 > V_75 )
goto V_76;
if ( V_77 [ V_36 -> V_74 ] . V_66 > V_36 -> V_53 )
goto V_76;
if ( V_70 [ V_78 ] &&
( V_33 = F_16 ( V_70 [ V_78 ] ) ) == 0 )
goto V_76;
V_2 = F_34 ( sizeof( * V_2 ) + V_33 * sizeof( struct V_13 ) , V_79 ) ;
V_45 = - V_80 ;
if ( V_2 == NULL )
goto V_81;
V_2 -> V_24 = V_36 -> V_82 ;
V_2 -> V_23 = V_33 ;
V_2 -> V_28 = V_36 -> V_39 ;
if ( V_70 [ V_83 ] )
V_2 -> V_26 = F_35 ( V_70 [ V_83 ] ) ;
if ( V_70 [ V_84 ] ) {
struct V_29 * V_30 ;
int V_85 ;
F_36 (attr, attrs[RTA_METRICS], rem) {
int type = F_37 ( V_30 ) ;
if ( type ) {
if ( type > V_86 || type == V_87 ||
F_18 ( V_30 ) < 4 )
goto V_76;
V_2 -> V_27 [ type - 1 ] = F_35 ( V_30 ) ;
}
}
}
if ( V_70 [ V_88 ] )
V_2 -> V_25 = F_24 ( V_70 [ V_88 ] ) ;
if ( V_70 [ V_78 ] ) {
if ( ( V_45 = F_21 ( V_2 , V_70 [ V_78 ] , V_36 ) ) != 0 )
goto V_81;
if ( V_70 [ V_89 ] &&
V_2 -> V_15 -> V_16 != F_35 ( V_70 [ V_89 ] ) )
goto V_76;
if ( V_70 [ V_44 ] &&
V_2 -> V_15 -> V_17 != F_24 ( V_70 [ V_44 ] ) )
goto V_76;
} else {
struct V_13 * V_5 = V_2 -> V_15 ;
if ( V_70 [ V_89 ] )
V_5 -> V_16 = F_35 ( V_70 [ V_89 ] ) ;
if ( V_70 [ V_44 ] )
V_5 -> V_17 = F_24 ( V_70 [ V_44 ] ) ;
V_5 -> V_20 = V_36 -> V_39 ;
V_5 -> V_19 = 1 ;
}
if ( V_36 -> V_74 == V_90 ) {
if ( ! V_70 [ V_44 ] || V_33 != 1 || V_70 [ V_89 ] )
goto V_76;
V_2 -> V_15 -> V_17 = F_24 ( V_70 [ V_44 ] ) ;
goto V_91;
}
if ( V_77 [ V_36 -> V_74 ] . error ) {
if ( V_70 [ V_44 ] || V_70 [ V_89 ] || V_70 [ V_78 ] )
goto V_76;
goto V_91;
}
if ( V_36 -> V_53 > V_69 )
goto V_76;
if ( V_36 -> V_53 == V_69 ) {
struct V_13 * V_5 = V_2 -> V_15 ;
if ( V_33 != 1 || V_5 -> V_17 )
goto V_76;
V_5 -> V_18 = V_92 ;
V_5 -> V_6 = F_38 ( & V_56 , V_2 -> V_15 -> V_16 ) ;
V_45 = - V_57 ;
if ( V_5 -> V_6 == NULL )
goto V_81;
} else {
F_3 (fi) {
if ( ( V_45 = F_25 ( V_36 , V_2 , V_5 ) ) != 0 )
goto V_81;
} F_5 (fi)
}
if ( V_2 -> V_25 ) {
if ( V_36 -> V_74 != V_64 || ! V_70 [ V_93 ] ||
V_2 -> V_25 != F_24 ( V_70 [ V_93 ] ) )
if ( F_26 ( V_2 -> V_25 ) != V_64 )
goto V_76;
}
V_91:
if ( ( V_12 = F_13 ( V_2 ) ) != NULL ) {
V_2 -> V_3 = 1 ;
F_1 ( V_2 ) ;
V_12 -> V_8 ++ ;
return V_12 ;
}
V_2 -> V_8 ++ ;
F_39 ( & V_2 -> V_94 ) ;
F_8 ( & V_7 ) ;
V_2 -> V_9 = V_11 ;
V_2 -> V_10 = NULL ;
if ( V_11 )
V_11 -> V_10 = V_2 ;
V_11 = V_2 ;
F_10 ( & V_7 ) ;
return V_2 ;
V_76:
V_45 = - V_38 ;
V_81:
* V_73 = V_45 ;
if ( V_2 ) {
V_2 -> V_3 = 1 ;
F_1 ( V_2 ) ;
}
return NULL ;
}
int F_40 ( int type , struct V_1 * V_2 , const struct V_46 * V_47 , struct V_48 * V_49 )
{
int V_45 = V_77 [ type ] . error ;
if ( V_45 == 0 ) {
if ( V_2 -> V_28 & V_21 )
return 1 ;
V_49 -> V_2 = V_2 ;
switch ( type ) {
case V_90 :
F_41 ( * V_49 ) ;
F_39 ( & V_2 -> V_94 ) ;
return 0 ;
case V_55 :
case V_64 :
F_12 (fi) {
if ( V_5 -> V_20 & V_21 )
continue;
if ( ! V_47 -> V_62 ||
V_47 -> V_62 == V_5 -> V_16 )
break;
}
if ( V_95 < V_2 -> V_23 ) {
V_49 -> V_96 = V_95 ;
F_39 ( & V_2 -> V_94 ) ;
return 0 ;
}
F_5 ( V_2 ) ;
V_49 -> V_2 = NULL ;
return 1 ;
default:
F_42 ( L_2 ,
type ) ;
V_49 -> V_2 = NULL ;
return - V_38 ;
}
}
return V_45 ;
}
void F_43 ( const struct V_46 * V_47 , struct V_48 * V_49 )
{
struct V_1 * V_2 = V_49 -> V_2 ;
int V_97 ;
F_44 ( & V_98 ) ;
if ( V_2 -> V_99 <= 0 ) {
int V_100 = 0 ;
F_3 (fi) {
if ( ! ( V_5 -> V_20 & V_21 ) ) {
V_100 += V_5 -> V_19 ;
V_5 -> V_101 = V_5 -> V_19 ;
}
} F_5 ( V_2 ) ;
V_2 -> V_99 = V_100 ;
if ( V_100 < 0 ) {
F_45 ( & V_98 ) ;
V_49 -> V_96 = 0 ;
return;
}
}
V_97 = V_102 % V_2 -> V_99 ;
F_3 (fi) {
if ( ! ( V_5 -> V_20 & V_21 ) && V_5 -> V_101 ) {
if ( ( V_97 -= V_5 -> V_101 ) <= 0 ) {
V_5 -> V_101 -- ;
V_2 -> V_99 -- ;
V_49 -> V_96 = V_95 ;
F_45 ( & V_98 ) ;
return;
}
}
} F_5 ( V_2 ) ;
V_49 -> V_96 = 0 ;
F_45 ( & V_98 ) ;
}
static inline T_1 F_46 ( struct V_29 * V_70 [] , T_2 V_103 )
{
if ( V_70 [ V_104 ] )
V_103 = F_35 ( V_70 [ V_104 ] ) ;
return V_103 ;
}
static int F_47 ( struct V_105 * V_106 , struct V_71 * V_72 )
{
struct V_107 * V_107 = F_48 ( V_106 -> V_108 ) ;
struct V_109 * V_110 ;
struct V_35 * V_36 = F_49 ( V_72 ) ;
struct V_29 * V_70 [ V_111 + 1 ] ;
int V_45 ;
if ( ! F_50 ( V_106 , V_112 ) )
return - V_113 ;
if ( ! F_51 ( V_107 , & V_56 ) )
return - V_38 ;
V_45 = F_52 ( V_72 , sizeof( * V_36 ) , V_70 , V_111 , V_114 ) ;
if ( V_45 < 0 )
return V_45 ;
V_110 = F_53 ( F_46 ( V_70 , V_36 -> V_115 ) , 0 ) ;
if ( ! V_110 )
return - V_116 ;
return V_110 -> V_117 ( V_110 , V_36 , V_70 , V_72 , & F_54 ( V_106 ) ) ;
}
static int F_55 ( struct V_105 * V_106 , struct V_71 * V_72 )
{
struct V_107 * V_107 = F_48 ( V_106 -> V_108 ) ;
struct V_109 * V_110 ;
struct V_35 * V_36 = F_49 ( V_72 ) ;
struct V_29 * V_70 [ V_111 + 1 ] ;
int V_45 ;
if ( ! F_50 ( V_106 , V_112 ) )
return - V_113 ;
if ( ! F_51 ( V_107 , & V_56 ) )
return - V_38 ;
V_45 = F_52 ( V_72 , sizeof( * V_36 ) , V_70 , V_111 , V_114 ) ;
if ( V_45 < 0 )
return V_45 ;
V_110 = F_53 ( F_46 ( V_70 , V_36 -> V_115 ) , 1 ) ;
if ( ! V_110 )
return - V_80 ;
return V_110 -> V_118 ( V_110 , V_36 , V_70 , V_72 , & F_54 ( V_106 ) ) ;
}
static void F_56 ( int V_119 , int type , T_3 V_120 , int V_121 , struct V_122 * V_123 )
{
struct V_109 * V_110 ;
struct {
struct V_71 V_72 ;
struct V_35 V_124 ;
} V_125 ;
struct {
struct V_29 V_126 ;
T_3 V_120 ;
} V_127 = {
. V_120 = V_120 ,
} ;
struct {
struct V_29 V_126 ;
T_3 V_128 ;
} V_129 = {
. V_128 = V_123 -> V_130 ,
} ;
struct {
struct V_29 V_126 ;
T_1 V_131 ;
} V_132 = {
. V_131 = V_123 -> V_133 -> V_52 -> V_134 ,
} ;
struct V_29 * V_70 [ V_111 + 1 ] = {
[ V_93 ] = (struct V_29 * ) & V_127 ,
[ V_88 ] = (struct V_29 * ) & V_129 ,
[ V_89 ] = (struct V_29 * ) & V_132 ,
} ;
memset ( & V_125 . V_124 , 0 , sizeof( V_125 . V_124 ) ) ;
if ( type == V_55 )
V_110 = F_53 ( V_135 , 1 ) ;
else
V_110 = F_53 ( V_136 , 1 ) ;
if ( V_110 == NULL )
return;
V_125 . V_72 . V_137 = sizeof( V_125 ) ;
V_125 . V_72 . V_138 = V_119 ;
V_125 . V_72 . V_139 = V_140 | V_141 | V_142 ;
V_125 . V_72 . V_143 = 0 ;
V_125 . V_72 . V_144 = 0 ;
V_125 . V_124 . V_145 = V_121 ;
V_125 . V_124 . V_115 = V_110 -> V_146 ;
V_125 . V_124 . V_82 = V_147 ;
V_125 . V_124 . V_53 = ( type != V_64 ? V_54 : V_69 ) ;
V_125 . V_124 . V_74 = type ;
if ( V_119 == V_148 )
V_110 -> V_118 ( V_110 , & V_125 . V_124 , V_70 , & V_125 . V_72 , NULL ) ;
else
V_110 -> V_117 ( V_110 , & V_125 . V_124 , V_70 , & V_125 . V_72 , NULL ) ;
}
static void F_57 ( struct V_122 * V_123 )
{
F_56 ( V_148 , V_64 , V_123 -> V_130 , 16 , V_123 ) ;
#if 0
if (!(dev->flags&IFF_UP))
return;
#endif
}
static void F_58 ( struct V_122 * V_123 )
{
int V_149 = 0 ;
struct V_51 * V_52 ;
struct V_150 * V_151 ;
struct V_122 * V_152 ;
F_59 () ;
F_60 () ;
F_61 (&init_net, dev) {
V_151 = F_62 ( V_52 -> V_68 ) ;
if ( V_151 == NULL )
continue;
for ( V_152 = F_62 ( V_151 -> V_153 ) ;
V_152 != NULL ;
V_152 = F_62 ( V_152 -> V_154 ) ) {
if ( V_152 -> V_130 == V_123 -> V_130 ) {
V_149 = 1 ;
break;
}
}
}
F_63 () ;
if ( V_149 == 0 ) {
F_56 ( V_155 , V_64 , V_123 -> V_130 , 16 , V_123 ) ;
if ( F_26 ( V_123 -> V_130 ) != V_64 ) {
if ( F_64 ( V_123 -> V_130 , NULL , 0 ) )
F_65 () ;
}
}
}
static void F_66 ( struct V_51 * V_52 , int V_156 )
{
if ( F_64 ( 0 , V_52 , V_156 ) )
F_65 () ;
F_67 ( 0 ) ;
F_68 ( & V_157 , V_52 ) ;
}
static int F_69 ( struct V_158 * V_159 , unsigned long V_160 , void * V_161 )
{
struct V_122 * V_123 = (struct V_122 * ) V_161 ;
switch ( V_160 ) {
case V_162 :
F_57 ( V_123 ) ;
F_70 ( V_123 -> V_133 -> V_52 ) ;
F_67 ( - 1 ) ;
break;
case V_163 :
F_58 ( V_123 ) ;
if ( V_123 -> V_133 && V_123 -> V_133 -> V_153 == NULL ) {
F_66 ( V_123 -> V_133 -> V_52 , 1 ) ;
} else {
F_67 ( - 1 ) ;
}
break;
}
return V_164 ;
}
static int F_64 ( T_3 V_165 , struct V_51 * V_52 , int V_156 )
{
int V_166 = 0 ;
int V_66 = V_92 ;
if ( V_156 )
V_66 = - 1 ;
F_14 () {
if ( V_165 && V_2 -> V_25 == V_165 ) {
V_2 -> V_28 |= V_21 ;
V_166 ++ ;
} else if ( V_52 && V_2 -> V_23 ) {
int V_167 = 0 ;
F_3 (fi) {
if ( V_5 -> V_20 & V_21 )
V_167 ++ ;
else if ( V_5 -> V_6 == V_52 &&
V_5 -> V_18 != V_66 ) {
F_44 ( & V_98 ) ;
V_5 -> V_20 |= V_21 ;
V_2 -> V_99 -= V_5 -> V_101 ;
V_5 -> V_101 = 0 ;
F_45 ( & V_98 ) ;
V_167 ++ ;
}
} F_5 (fi)
if ( V_167 == V_2 -> V_23 ) {
V_2 -> V_28 |= V_21 ;
V_166 ++ ;
}
}
} F_15 () ;
return V_166 ;
}
static int F_70 ( struct V_51 * V_52 )
{
int V_166 = 0 ;
if ( ! ( V_52 -> V_58 & V_59 ) )
return 0 ;
F_14 () {
int V_168 = 0 ;
F_3 (fi) {
if ( ! ( V_5 -> V_20 & V_21 ) ) {
V_168 ++ ;
continue;
}
if ( V_5 -> V_6 == NULL || ! ( V_5 -> V_6 -> V_58 & V_59 ) )
continue;
if ( V_5 -> V_6 != V_52 || V_52 -> V_68 == NULL )
continue;
V_168 ++ ;
F_44 ( & V_98 ) ;
V_5 -> V_101 = 0 ;
V_5 -> V_20 &= ~ V_21 ;
F_45 ( & V_98 ) ;
} F_5 ( V_2 ) ;
if ( V_168 > 0 ) {
V_2 -> V_28 &= ~ V_21 ;
V_166 ++ ;
}
} F_15 () ;
return V_166 ;
}
void T_4 F_71 ( void )
{
F_72 () ;
F_73 () ;
F_74 ( & V_169 ) ;
}
void T_5 F_75 ( void )
{
F_76 () ;
F_77 () ;
F_78 ( & V_169 ) ;
F_79 ( V_170 , V_148 , F_55 , NULL , NULL ) ;
F_79 ( V_170 , V_155 , F_47 , NULL , NULL ) ;
}
