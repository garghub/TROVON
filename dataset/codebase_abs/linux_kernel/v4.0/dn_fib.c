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
while( V_34 >= ( int ) sizeof( struct V_31 ) ) {
if ( ( V_34 -= V_32 -> V_35 ) < 0 )
return 0 ;
V_33 ++ ;
V_32 = F_19 ( V_32 ) ;
}
return V_33 ;
}
static int F_20 ( struct V_1 * V_2 , const struct V_29 * V_30 ,
const struct V_36 * V_37 )
{
struct V_31 * V_32 = F_17 ( V_30 ) ;
int V_34 = F_18 ( V_30 ) ;
F_3 (fi) {
int V_38 = V_34 - sizeof( struct V_31 ) ;
if ( V_38 < 0 || ( V_34 -= V_32 -> V_35 ) < 0 )
return - V_39 ;
V_5 -> V_20 = ( V_37 -> V_40 & ~ 0xFF ) | V_32 -> V_41 ;
V_5 -> V_16 = V_32 -> V_42 ;
V_5 -> V_19 = V_32 -> V_43 + 1 ;
if ( V_38 ) {
struct V_29 * V_44 ;
V_44 = F_21 ( (struct V_29 * ) ( V_32 + 1 ) , V_38 , V_45 ) ;
V_5 -> V_17 = V_44 ? F_22 ( V_44 ) : 0 ;
}
V_32 = F_19 ( V_32 ) ;
} F_5 ( V_2 ) ;
return 0 ;
}
static int F_23 ( const struct V_36 * V_37 , struct V_1 * V_2 , struct V_13 * V_5 )
{
int V_46 ;
if ( V_5 -> V_17 ) {
struct V_47 V_48 ;
struct V_49 V_50 ;
if ( V_5 -> V_20 & V_51 ) {
struct V_52 * V_53 ;
if ( V_37 -> V_54 >= V_55 )
return - V_39 ;
if ( F_24 ( V_5 -> V_17 ) != V_56 )
return - V_39 ;
if ( ( V_53 = F_25 ( & V_57 , V_5 -> V_16 ) ) == NULL )
return - V_58 ;
if ( ! ( V_53 -> V_59 & V_60 ) )
return - V_61 ;
V_5 -> V_6 = V_53 ;
F_26 ( V_53 ) ;
V_5 -> V_18 = V_55 ;
return 0 ;
}
memset ( & V_48 , 0 , sizeof( V_48 ) ) ;
V_48 . V_62 = V_5 -> V_17 ;
V_48 . V_63 = V_5 -> V_16 ;
V_48 . V_64 = V_37 -> V_54 + 1 ;
if ( V_48 . V_64 < V_55 )
V_48 . V_64 = V_55 ;
if ( ( V_46 = F_27 ( & V_48 , & V_50 ) ) != 0 )
return V_46 ;
V_46 = - V_39 ;
if ( V_50 . type != V_56 && V_50 . type != V_65 )
goto V_66;
V_5 -> V_18 = V_50 . V_67 ;
V_5 -> V_16 = F_28 ( V_50 ) ;
V_5 -> V_6 = F_29 ( V_50 ) ;
if ( V_5 -> V_6 == NULL )
goto V_66;
F_26 ( V_5 -> V_6 ) ;
V_46 = - V_61 ;
if ( ! ( V_5 -> V_6 -> V_59 & V_60 ) )
goto V_66;
V_46 = 0 ;
V_66:
F_30 ( & V_50 ) ;
return V_46 ;
} else {
struct V_52 * V_53 ;
if ( V_5 -> V_20 & ( V_68 | V_51 ) )
return - V_39 ;
V_53 = F_25 ( & V_57 , V_5 -> V_16 ) ;
if ( V_53 == NULL || V_53 -> V_69 == NULL )
return - V_58 ;
if ( ! ( V_53 -> V_59 & V_60 ) )
return - V_61 ;
V_5 -> V_6 = V_53 ;
F_26 ( V_5 -> V_6 ) ;
V_5 -> V_18 = V_70 ;
}
return 0 ;
}
struct V_1 * F_31 ( const struct V_36 * V_37 , struct V_29 * V_71 [] ,
const struct V_72 * V_73 , int * V_74 )
{
int V_46 ;
struct V_1 * V_2 = NULL ;
struct V_1 * V_12 ;
int V_33 = 1 ;
if ( V_37 -> V_75 > V_76 )
goto V_77;
if ( V_78 [ V_37 -> V_75 ] . V_67 > V_37 -> V_54 )
goto V_77;
if ( V_71 [ V_79 ] &&
( V_33 = F_16 ( V_71 [ V_79 ] ) ) == 0 )
goto V_77;
V_2 = F_32 ( sizeof( * V_2 ) + V_33 * sizeof( struct V_13 ) , V_80 ) ;
V_46 = - V_81 ;
if ( V_2 == NULL )
goto V_82;
V_2 -> V_24 = V_37 -> V_83 ;
V_2 -> V_23 = V_33 ;
V_2 -> V_28 = V_37 -> V_40 ;
if ( V_71 [ V_84 ] )
V_2 -> V_26 = F_33 ( V_71 [ V_84 ] ) ;
if ( V_71 [ V_85 ] ) {
struct V_29 * V_30 ;
int V_86 ;
F_34 (attr, attrs[RTA_METRICS], rem) {
int type = F_35 ( V_30 ) ;
if ( type ) {
if ( type > V_87 || type == V_88 ||
F_18 ( V_30 ) < 4 )
goto V_77;
V_2 -> V_27 [ type - 1 ] = F_33 ( V_30 ) ;
}
}
}
if ( V_71 [ V_89 ] )
V_2 -> V_25 = F_22 ( V_71 [ V_89 ] ) ;
if ( V_71 [ V_79 ] ) {
if ( ( V_46 = F_20 ( V_2 , V_71 [ V_79 ] , V_37 ) ) != 0 )
goto V_82;
if ( V_71 [ V_90 ] &&
V_2 -> V_15 -> V_16 != F_33 ( V_71 [ V_90 ] ) )
goto V_77;
if ( V_71 [ V_45 ] &&
V_2 -> V_15 -> V_17 != F_22 ( V_71 [ V_45 ] ) )
goto V_77;
} else {
struct V_13 * V_5 = V_2 -> V_15 ;
if ( V_71 [ V_90 ] )
V_5 -> V_16 = F_33 ( V_71 [ V_90 ] ) ;
if ( V_71 [ V_45 ] )
V_5 -> V_17 = F_22 ( V_71 [ V_45 ] ) ;
V_5 -> V_20 = V_37 -> V_40 ;
V_5 -> V_19 = 1 ;
}
if ( V_37 -> V_75 == V_91 ) {
if ( ! V_71 [ V_45 ] || V_33 != 1 || V_71 [ V_90 ] )
goto V_77;
V_2 -> V_15 -> V_17 = F_22 ( V_71 [ V_45 ] ) ;
goto V_92;
}
if ( V_78 [ V_37 -> V_75 ] . error ) {
if ( V_71 [ V_45 ] || V_71 [ V_90 ] || V_71 [ V_79 ] )
goto V_77;
goto V_92;
}
if ( V_37 -> V_54 > V_70 )
goto V_77;
if ( V_37 -> V_54 == V_70 ) {
struct V_13 * V_5 = V_2 -> V_15 ;
if ( V_33 != 1 || V_5 -> V_17 )
goto V_77;
V_5 -> V_18 = V_93 ;
V_5 -> V_6 = F_36 ( & V_57 , V_2 -> V_15 -> V_16 ) ;
V_46 = - V_58 ;
if ( V_5 -> V_6 == NULL )
goto V_82;
} else {
F_3 (fi) {
if ( ( V_46 = F_23 ( V_37 , V_2 , V_5 ) ) != 0 )
goto V_82;
} F_5 (fi)
}
if ( V_2 -> V_25 ) {
if ( V_37 -> V_75 != V_65 || ! V_71 [ V_94 ] ||
V_2 -> V_25 != F_22 ( V_71 [ V_94 ] ) )
if ( F_24 ( V_2 -> V_25 ) != V_65 )
goto V_77;
}
V_92:
if ( ( V_12 = F_13 ( V_2 ) ) != NULL ) {
V_2 -> V_3 = 1 ;
F_1 ( V_2 ) ;
V_12 -> V_8 ++ ;
return V_12 ;
}
V_2 -> V_8 ++ ;
F_37 ( & V_2 -> V_95 ) ;
F_8 ( & V_7 ) ;
V_2 -> V_9 = V_11 ;
V_2 -> V_10 = NULL ;
if ( V_11 )
V_11 -> V_10 = V_2 ;
V_11 = V_2 ;
F_10 ( & V_7 ) ;
return V_2 ;
V_77:
V_46 = - V_39 ;
V_82:
* V_74 = V_46 ;
if ( V_2 ) {
V_2 -> V_3 = 1 ;
F_1 ( V_2 ) ;
}
return NULL ;
}
int F_38 ( int type , struct V_1 * V_2 , const struct V_47 * V_48 , struct V_49 * V_50 )
{
int V_46 = V_78 [ type ] . error ;
if ( V_46 == 0 ) {
if ( V_2 -> V_28 & V_21 )
return 1 ;
V_50 -> V_2 = V_2 ;
switch ( type ) {
case V_91 :
F_39 ( * V_50 ) ;
F_37 ( & V_2 -> V_95 ) ;
return 0 ;
case V_56 :
case V_65 :
F_12 (fi) {
if ( V_5 -> V_20 & V_21 )
continue;
if ( ! V_48 -> V_63 ||
V_48 -> V_63 == V_5 -> V_16 )
break;
}
if ( V_96 < V_2 -> V_23 ) {
V_50 -> V_97 = V_96 ;
F_37 ( & V_2 -> V_95 ) ;
return 0 ;
}
F_5 ( V_2 ) ;
V_50 -> V_2 = NULL ;
return 1 ;
default:
F_40 ( L_2 ,
type ) ;
V_50 -> V_2 = NULL ;
return - V_39 ;
}
}
return V_46 ;
}
void F_41 ( const struct V_47 * V_48 , struct V_49 * V_50 )
{
struct V_1 * V_2 = V_50 -> V_2 ;
int V_98 ;
F_42 ( & V_99 ) ;
if ( V_2 -> V_100 <= 0 ) {
int V_101 = 0 ;
F_3 (fi) {
if ( ! ( V_5 -> V_20 & V_21 ) ) {
V_101 += V_5 -> V_19 ;
V_5 -> V_102 = V_5 -> V_19 ;
}
} F_5 ( V_2 ) ;
V_2 -> V_100 = V_101 ;
if ( V_101 < 0 ) {
F_43 ( & V_99 ) ;
V_50 -> V_97 = 0 ;
return;
}
}
V_98 = V_103 % V_2 -> V_100 ;
F_3 (fi) {
if ( ! ( V_5 -> V_20 & V_21 ) && V_5 -> V_102 ) {
if ( ( V_98 -= V_5 -> V_102 ) <= 0 ) {
V_5 -> V_102 -- ;
V_2 -> V_100 -- ;
V_50 -> V_97 = V_96 ;
F_43 ( & V_99 ) ;
return;
}
}
} F_5 ( V_2 ) ;
V_50 -> V_97 = 0 ;
F_43 ( & V_99 ) ;
}
static inline T_1 F_44 ( struct V_29 * V_71 [] , T_2 V_104 )
{
if ( V_71 [ V_105 ] )
V_104 = F_33 ( V_71 [ V_105 ] ) ;
return V_104 ;
}
static int F_45 ( struct V_106 * V_107 , struct V_72 * V_73 )
{
struct V_108 * V_108 = F_46 ( V_107 -> V_109 ) ;
struct V_110 * V_111 ;
struct V_36 * V_37 = F_47 ( V_73 ) ;
struct V_29 * V_71 [ V_112 + 1 ] ;
int V_46 ;
if ( ! F_48 ( V_107 , V_113 ) )
return - V_114 ;
if ( ! F_49 ( V_108 , & V_57 ) )
return - V_39 ;
V_46 = F_50 ( V_73 , sizeof( * V_37 ) , V_71 , V_112 , V_115 ) ;
if ( V_46 < 0 )
return V_46 ;
V_111 = F_51 ( F_44 ( V_71 , V_37 -> V_116 ) , 0 ) ;
if ( ! V_111 )
return - V_117 ;
return V_111 -> V_118 ( V_111 , V_37 , V_71 , V_73 , & F_52 ( V_107 ) ) ;
}
static int F_53 ( struct V_106 * V_107 , struct V_72 * V_73 )
{
struct V_108 * V_108 = F_46 ( V_107 -> V_109 ) ;
struct V_110 * V_111 ;
struct V_36 * V_37 = F_47 ( V_73 ) ;
struct V_29 * V_71 [ V_112 + 1 ] ;
int V_46 ;
if ( ! F_48 ( V_107 , V_113 ) )
return - V_114 ;
if ( ! F_49 ( V_108 , & V_57 ) )
return - V_39 ;
V_46 = F_50 ( V_73 , sizeof( * V_37 ) , V_71 , V_112 , V_115 ) ;
if ( V_46 < 0 )
return V_46 ;
V_111 = F_51 ( F_44 ( V_71 , V_37 -> V_116 ) , 1 ) ;
if ( ! V_111 )
return - V_81 ;
return V_111 -> V_119 ( V_111 , V_37 , V_71 , V_73 , & F_52 ( V_107 ) ) ;
}
static void F_54 ( int V_120 , int type , T_3 V_121 , int V_122 , struct V_123 * V_124 )
{
struct V_110 * V_111 ;
struct {
struct V_72 V_73 ;
struct V_36 V_125 ;
} V_126 ;
struct {
struct V_29 V_127 ;
T_3 V_121 ;
} V_128 = {
. V_121 = V_121 ,
} ;
struct {
struct V_29 V_127 ;
T_3 V_129 ;
} V_130 = {
. V_129 = V_124 -> V_131 ,
} ;
struct {
struct V_29 V_127 ;
T_1 V_132 ;
} V_133 = {
. V_132 = V_124 -> V_134 -> V_53 -> V_135 ,
} ;
struct V_29 * V_71 [ V_112 + 1 ] = {
[ V_94 ] = (struct V_29 * ) & V_128 ,
[ V_89 ] = (struct V_29 * ) & V_130 ,
[ V_90 ] = (struct V_29 * ) & V_133 ,
} ;
memset ( & V_126 . V_125 , 0 , sizeof( V_126 . V_125 ) ) ;
if ( type == V_56 )
V_111 = F_51 ( V_136 , 1 ) ;
else
V_111 = F_51 ( V_137 , 1 ) ;
if ( V_111 == NULL )
return;
V_126 . V_73 . V_138 = sizeof( V_126 ) ;
V_126 . V_73 . V_139 = V_120 ;
V_126 . V_73 . V_140 = V_141 | V_142 | V_143 ;
V_126 . V_73 . V_144 = 0 ;
V_126 . V_73 . V_145 = 0 ;
V_126 . V_125 . V_146 = V_122 ;
V_126 . V_125 . V_116 = V_111 -> V_147 ;
V_126 . V_125 . V_83 = V_148 ;
V_126 . V_125 . V_54 = ( type != V_65 ? V_55 : V_70 ) ;
V_126 . V_125 . V_75 = type ;
if ( V_120 == V_149 )
V_111 -> V_119 ( V_111 , & V_126 . V_125 , V_71 , & V_126 . V_73 , NULL ) ;
else
V_111 -> V_118 ( V_111 , & V_126 . V_125 , V_71 , & V_126 . V_73 , NULL ) ;
}
static void F_55 ( struct V_123 * V_124 )
{
F_54 ( V_149 , V_65 , V_124 -> V_131 , 16 , V_124 ) ;
#if 0
if (!(dev->flags&IFF_UP))
return;
#endif
}
static void F_56 ( struct V_123 * V_124 )
{
int V_150 = 0 ;
struct V_52 * V_53 ;
struct V_151 * V_152 ;
struct V_123 * V_153 ;
F_57 () ;
F_58 () ;
F_59 (&init_net, dev) {
V_152 = F_60 ( V_53 -> V_69 ) ;
if ( V_152 == NULL )
continue;
for ( V_153 = F_60 ( V_152 -> V_154 ) ;
V_153 != NULL ;
V_153 = F_60 ( V_153 -> V_155 ) ) {
if ( V_153 -> V_131 == V_124 -> V_131 ) {
V_150 = 1 ;
break;
}
}
}
F_61 () ;
if ( V_150 == 0 ) {
F_54 ( V_156 , V_65 , V_124 -> V_131 , 16 , V_124 ) ;
if ( F_24 ( V_124 -> V_131 ) != V_65 ) {
if ( F_62 ( V_124 -> V_131 , NULL , 0 ) )
F_63 () ;
}
}
}
static void F_64 ( struct V_52 * V_53 , int V_157 )
{
if ( F_62 ( 0 , V_53 , V_157 ) )
F_63 () ;
F_65 ( 0 ) ;
F_66 ( & V_158 , V_53 ) ;
}
static int F_67 ( struct V_159 * V_160 , unsigned long V_161 , void * V_162 )
{
struct V_123 * V_124 = (struct V_123 * ) V_162 ;
switch ( V_161 ) {
case V_163 :
F_55 ( V_124 ) ;
F_68 ( V_124 -> V_134 -> V_53 ) ;
F_65 ( - 1 ) ;
break;
case V_164 :
F_56 ( V_124 ) ;
if ( V_124 -> V_134 && V_124 -> V_134 -> V_154 == NULL ) {
F_64 ( V_124 -> V_134 -> V_53 , 1 ) ;
} else {
F_65 ( - 1 ) ;
}
break;
}
return V_165 ;
}
static int F_62 ( T_3 V_166 , struct V_52 * V_53 , int V_157 )
{
int V_167 = 0 ;
int V_67 = V_93 ;
if ( V_157 )
V_67 = - 1 ;
F_14 () {
if ( V_166 && V_2 -> V_25 == V_166 ) {
V_2 -> V_28 |= V_21 ;
V_167 ++ ;
} else if ( V_53 && V_2 -> V_23 ) {
int V_168 = 0 ;
F_3 (fi) {
if ( V_5 -> V_20 & V_21 )
V_168 ++ ;
else if ( V_5 -> V_6 == V_53 &&
V_5 -> V_18 != V_67 ) {
F_42 ( & V_99 ) ;
V_5 -> V_20 |= V_21 ;
V_2 -> V_100 -= V_5 -> V_102 ;
V_5 -> V_102 = 0 ;
F_43 ( & V_99 ) ;
V_168 ++ ;
}
} F_5 (fi)
if ( V_168 == V_2 -> V_23 ) {
V_2 -> V_28 |= V_21 ;
V_167 ++ ;
}
}
} F_15 () ;
return V_167 ;
}
static int F_68 ( struct V_52 * V_53 )
{
int V_167 = 0 ;
if ( ! ( V_53 -> V_59 & V_60 ) )
return 0 ;
F_14 () {
int V_169 = 0 ;
F_3 (fi) {
if ( ! ( V_5 -> V_20 & V_21 ) ) {
V_169 ++ ;
continue;
}
if ( V_5 -> V_6 == NULL || ! ( V_5 -> V_6 -> V_59 & V_60 ) )
continue;
if ( V_5 -> V_6 != V_53 || V_53 -> V_69 == NULL )
continue;
V_169 ++ ;
F_42 ( & V_99 ) ;
V_5 -> V_102 = 0 ;
V_5 -> V_20 &= ~ V_21 ;
F_43 ( & V_99 ) ;
} F_5 ( V_2 ) ;
if ( V_169 > 0 ) {
V_2 -> V_28 &= ~ V_21 ;
V_167 ++ ;
}
} F_15 () ;
return V_167 ;
}
void T_4 F_69 ( void )
{
F_70 () ;
F_71 () ;
F_72 ( & V_170 ) ;
}
void T_5 F_73 ( void )
{
F_74 () ;
F_75 () ;
F_76 ( & V_170 ) ;
F_77 ( V_171 , V_149 , F_53 , NULL , NULL ) ;
F_77 ( V_171 , V_156 , F_45 , NULL , NULL ) ;
}
