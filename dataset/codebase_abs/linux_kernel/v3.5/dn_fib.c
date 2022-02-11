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
T_1 F_16 ( struct V_29 * V_30 , int V_31 , int type )
{
while( F_17 ( V_30 , V_31 ) ) {
if ( V_30 -> V_32 == type )
return * ( T_1 * ) F_18 ( V_30 ) ;
V_30 = F_19 ( V_30 , V_31 ) ;
}
return 0 ;
}
static int F_20 ( struct V_29 * V_33 )
{
int V_34 = 0 ;
struct V_35 * V_36 = F_18 ( V_33 ) ;
int V_37 = F_21 ( V_33 ) ;
while( V_37 >= ( int ) sizeof( struct V_35 ) ) {
if ( ( V_37 -= V_36 -> V_38 ) < 0 )
return 0 ;
V_34 ++ ;
V_36 = F_22 ( V_36 ) ;
}
return V_34 ;
}
static int F_23 ( struct V_1 * V_2 , const struct V_29 * V_33 , const struct V_39 * V_40 )
{
struct V_35 * V_36 = F_18 ( V_33 ) ;
int V_37 = F_21 ( V_33 ) ;
F_3 (fi) {
int V_31 = V_37 - sizeof( struct V_35 ) ;
if ( V_31 < 0 || ( V_37 -= V_36 -> V_38 ) < 0 )
return - V_41 ;
V_5 -> V_20 = ( V_40 -> V_42 & ~ 0xFF ) | V_36 -> V_43 ;
V_5 -> V_16 = V_36 -> V_44 ;
V_5 -> V_19 = V_36 -> V_45 + 1 ;
if ( V_31 ) {
V_5 -> V_17 = F_16 ( F_24 ( V_36 ) , V_31 , V_46 ) ;
}
V_36 = F_22 ( V_36 ) ;
} F_5 ( V_2 ) ;
return 0 ;
}
static int F_25 ( const struct V_39 * V_40 , struct V_1 * V_2 , struct V_13 * V_5 )
{
int V_47 ;
if ( V_5 -> V_17 ) {
struct V_48 V_49 ;
struct V_50 V_51 ;
if ( V_5 -> V_20 & V_52 ) {
struct V_53 * V_54 ;
if ( V_40 -> V_55 >= V_56 )
return - V_41 ;
if ( F_26 ( V_5 -> V_17 ) != V_57 )
return - V_41 ;
if ( ( V_54 = F_27 ( & V_58 , V_5 -> V_16 ) ) == NULL )
return - V_59 ;
if ( ! ( V_54 -> V_60 & V_61 ) )
return - V_62 ;
V_5 -> V_6 = V_54 ;
F_28 ( V_54 ) ;
V_5 -> V_18 = V_56 ;
return 0 ;
}
memset ( & V_49 , 0 , sizeof( V_49 ) ) ;
V_49 . V_63 = V_5 -> V_17 ;
V_49 . V_64 = V_5 -> V_16 ;
V_49 . V_65 = V_40 -> V_55 + 1 ;
if ( V_49 . V_65 < V_56 )
V_49 . V_65 = V_56 ;
if ( ( V_47 = F_29 ( & V_49 , & V_51 ) ) != 0 )
return V_47 ;
V_47 = - V_41 ;
if ( V_51 . type != V_57 && V_51 . type != V_66 )
goto V_67;
V_5 -> V_18 = V_51 . V_68 ;
V_5 -> V_16 = F_30 ( V_51 ) ;
V_5 -> V_6 = F_31 ( V_51 ) ;
if ( V_5 -> V_6 == NULL )
goto V_67;
F_28 ( V_5 -> V_6 ) ;
V_47 = - V_62 ;
if ( ! ( V_5 -> V_6 -> V_60 & V_61 ) )
goto V_67;
V_47 = 0 ;
V_67:
F_32 ( & V_51 ) ;
return V_47 ;
} else {
struct V_53 * V_54 ;
if ( V_5 -> V_20 & ( V_69 | V_52 ) )
return - V_41 ;
V_54 = F_27 ( & V_58 , V_5 -> V_16 ) ;
if ( V_54 == NULL || V_54 -> V_70 == NULL )
return - V_59 ;
if ( ! ( V_54 -> V_60 & V_61 ) )
return - V_62 ;
V_5 -> V_6 = V_54 ;
F_28 ( V_5 -> V_6 ) ;
V_5 -> V_18 = V_71 ;
}
return 0 ;
}
struct V_1 * F_33 ( const struct V_39 * V_40 , struct V_72 * V_33 , const struct V_73 * V_74 , int * V_75 )
{
int V_47 ;
struct V_1 * V_2 = NULL ;
struct V_1 * V_12 ;
int V_34 = 1 ;
if ( V_40 -> V_76 > V_77 )
goto V_78;
if ( V_79 [ V_40 -> V_76 ] . V_68 > V_40 -> V_55 )
goto V_78;
if ( V_33 -> V_80 ) {
V_34 = F_20 ( V_33 -> V_80 ) ;
if ( V_34 == 0 )
goto V_78;
}
V_2 = F_34 ( sizeof( * V_2 ) + V_34 * sizeof( struct V_13 ) , V_81 ) ;
V_47 = - V_82 ;
if ( V_2 == NULL )
goto V_83;
V_2 -> V_24 = V_40 -> V_84 ;
V_2 -> V_23 = V_34 ;
V_2 -> V_28 = V_40 -> V_42 ;
if ( V_33 -> V_85 )
V_2 -> V_26 = * V_33 -> V_85 ;
if ( V_33 -> V_86 ) {
int V_31 = F_21 ( V_33 -> V_86 ) ;
struct V_29 * V_30 = F_18 ( V_33 -> V_86 ) ;
while( F_17 ( V_30 , V_31 ) ) {
unsigned int V_87 = V_30 -> V_32 ;
if ( V_87 ) {
if ( V_87 > V_88 )
goto V_78;
V_2 -> V_27 [ V_87 - 1 ] = * ( unsigned int * ) F_18 ( V_30 ) ;
}
V_30 = F_19 ( V_30 , V_31 ) ;
}
}
if ( V_33 -> V_89 )
memcpy ( & V_2 -> V_25 , V_33 -> V_89 , 2 ) ;
if ( V_33 -> V_80 ) {
if ( ( V_47 = F_23 ( V_2 , V_33 -> V_80 , V_40 ) ) != 0 )
goto V_83;
if ( V_33 -> V_90 && V_2 -> V_15 -> V_16 != * V_33 -> V_90 )
goto V_78;
if ( V_33 -> V_91 && memcmp ( & V_2 -> V_15 -> V_17 , V_33 -> V_91 , 2 ) )
goto V_78;
} else {
struct V_13 * V_5 = V_2 -> V_15 ;
if ( V_33 -> V_90 )
V_5 -> V_16 = * V_33 -> V_90 ;
if ( V_33 -> V_91 )
memcpy ( & V_5 -> V_17 , V_33 -> V_91 , 2 ) ;
V_5 -> V_20 = V_40 -> V_42 ;
V_5 -> V_19 = 1 ;
}
if ( V_40 -> V_76 == V_92 ) {
if ( V_33 -> V_91 == NULL || V_34 != 1 || V_33 -> V_90 )
goto V_78;
memcpy ( & V_2 -> V_15 -> V_17 , V_33 -> V_91 , 2 ) ;
goto V_93;
}
if ( V_79 [ V_40 -> V_76 ] . error ) {
if ( V_33 -> V_91 || V_33 -> V_90 || V_33 -> V_80 )
goto V_78;
goto V_93;
}
if ( V_40 -> V_55 > V_71 )
goto V_78;
if ( V_40 -> V_55 == V_71 ) {
struct V_13 * V_5 = V_2 -> V_15 ;
if ( V_34 != 1 || V_5 -> V_17 )
goto V_78;
V_5 -> V_18 = V_94 ;
V_5 -> V_6 = F_35 ( & V_58 , V_2 -> V_15 -> V_16 ) ;
V_47 = - V_59 ;
if ( V_5 -> V_6 == NULL )
goto V_83;
} else {
F_3 (fi) {
if ( ( V_47 = F_25 ( V_40 , V_2 , V_5 ) ) != 0 )
goto V_83;
} F_5 (fi)
}
if ( V_2 -> V_25 ) {
if ( V_40 -> V_76 != V_66 || V_33 -> V_95 == NULL ||
memcmp ( & V_2 -> V_25 , V_33 -> V_95 , 2 ) )
if ( F_26 ( V_2 -> V_25 ) != V_66 )
goto V_78;
}
V_93:
if ( ( V_12 = F_13 ( V_2 ) ) != NULL ) {
V_2 -> V_3 = 1 ;
F_1 ( V_2 ) ;
V_12 -> V_8 ++ ;
return V_12 ;
}
V_2 -> V_8 ++ ;
F_36 ( & V_2 -> V_96 ) ;
F_8 ( & V_7 ) ;
V_2 -> V_9 = V_11 ;
V_2 -> V_10 = NULL ;
if ( V_11 )
V_11 -> V_10 = V_2 ;
V_11 = V_2 ;
F_10 ( & V_7 ) ;
return V_2 ;
V_78:
V_47 = - V_41 ;
V_83:
* V_75 = V_47 ;
if ( V_2 ) {
V_2 -> V_3 = 1 ;
F_1 ( V_2 ) ;
}
return NULL ;
}
int F_37 ( int type , struct V_1 * V_2 , const struct V_48 * V_49 , struct V_50 * V_51 )
{
int V_47 = V_79 [ type ] . error ;
if ( V_47 == 0 ) {
if ( V_2 -> V_28 & V_21 )
return 1 ;
V_51 -> V_2 = V_2 ;
switch ( type ) {
case V_92 :
F_38 ( * V_51 ) ;
F_36 ( & V_2 -> V_96 ) ;
return 0 ;
case V_57 :
case V_66 :
F_12 (fi) {
if ( V_5 -> V_20 & V_21 )
continue;
if ( ! V_49 -> V_64 ||
V_49 -> V_64 == V_5 -> V_16 )
break;
}
if ( V_97 < V_2 -> V_23 ) {
V_51 -> V_98 = V_97 ;
F_36 ( & V_2 -> V_96 ) ;
return 0 ;
}
F_5 ( V_2 ) ;
V_51 -> V_2 = NULL ;
return 1 ;
default:
F_39 ( L_2 ,
type ) ;
V_51 -> V_2 = NULL ;
return - V_41 ;
}
}
return V_47 ;
}
void F_40 ( const struct V_48 * V_49 , struct V_50 * V_51 )
{
struct V_1 * V_2 = V_51 -> V_2 ;
int V_99 ;
F_41 ( & V_100 ) ;
if ( V_2 -> V_101 <= 0 ) {
int V_102 = 0 ;
F_3 (fi) {
if ( ! ( V_5 -> V_20 & V_21 ) ) {
V_102 += V_5 -> V_19 ;
V_5 -> V_103 = V_5 -> V_19 ;
}
} F_5 ( V_2 ) ;
V_2 -> V_101 = V_102 ;
if ( V_102 < 0 ) {
F_42 ( & V_100 ) ;
V_51 -> V_98 = 0 ;
return;
}
}
V_99 = V_104 % V_2 -> V_101 ;
F_3 (fi) {
if ( ! ( V_5 -> V_20 & V_21 ) && V_5 -> V_103 ) {
if ( ( V_99 -= V_5 -> V_103 ) <= 0 ) {
V_5 -> V_103 -- ;
V_2 -> V_101 -- ;
V_51 -> V_98 = V_97 ;
F_42 ( & V_100 ) ;
return;
}
}
} F_5 ( V_2 ) ;
V_51 -> V_98 = 0 ;
F_42 ( & V_100 ) ;
}
static int F_43 ( struct V_39 * V_40 , struct V_29 * * V_33 )
{
int V_105 ;
for( V_105 = 1 ; V_105 <= V_106 ; V_105 ++ ) {
struct V_29 * V_30 = V_33 [ V_105 - 1 ] ;
if ( V_30 ) {
if ( F_21 ( V_30 ) < 4 && F_21 ( V_30 ) != 2 )
return - V_41 ;
if ( V_105 != V_107 && V_105 != V_108 &&
V_105 != V_109 )
V_33 [ V_105 - 1 ] = (struct V_29 * ) F_18 ( V_30 ) ;
}
}
return 0 ;
}
static int F_44 ( struct V_110 * V_111 , struct V_73 * V_74 , void * V_112 )
{
struct V_113 * V_113 = F_45 ( V_111 -> V_114 ) ;
struct V_115 * V_116 ;
struct V_29 * * V_33 = V_112 ;
struct V_39 * V_40 = F_46 ( V_74 ) ;
if ( ! F_47 ( V_113 , & V_58 ) )
return - V_41 ;
if ( F_43 ( V_40 , V_33 ) )
return - V_41 ;
V_116 = F_48 ( F_49 ( V_33 , V_40 -> V_117 ) , 0 ) ;
if ( V_116 )
return V_116 -> V_118 ( V_116 , V_40 , (struct V_72 * ) V_33 , V_74 , & F_50 ( V_111 ) ) ;
return - V_119 ;
}
static int F_51 ( struct V_110 * V_111 , struct V_73 * V_74 , void * V_112 )
{
struct V_113 * V_113 = F_45 ( V_111 -> V_114 ) ;
struct V_115 * V_116 ;
struct V_29 * * V_33 = V_112 ;
struct V_39 * V_40 = F_46 ( V_74 ) ;
if ( ! F_47 ( V_113 , & V_58 ) )
return - V_41 ;
if ( F_43 ( V_40 , V_33 ) )
return - V_41 ;
V_116 = F_48 ( F_49 ( V_33 , V_40 -> V_117 ) , 1 ) ;
if ( V_116 )
return V_116 -> V_120 ( V_116 , V_40 , (struct V_72 * ) V_33 , V_74 , & F_50 ( V_111 ) ) ;
return - V_82 ;
}
static void F_52 ( int V_121 , int type , T_1 V_122 , int V_123 , struct V_124 * V_125 )
{
struct V_115 * V_116 ;
struct {
struct V_73 V_74 ;
struct V_39 V_126 ;
} V_127 ;
struct V_72 V_33 ;
memset ( & V_127 . V_126 , 0 , sizeof( V_127 . V_126 ) ) ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
if ( type == V_57 )
V_116 = F_48 ( V_128 , 1 ) ;
else
V_116 = F_48 ( V_129 , 1 ) ;
if ( V_116 == NULL )
return;
V_127 . V_74 . V_130 = sizeof( V_127 ) ;
V_127 . V_74 . V_131 = V_121 ;
V_127 . V_74 . V_132 = V_133 | V_134 | V_135 ;
V_127 . V_74 . V_136 = 0 ;
V_127 . V_74 . V_137 = 0 ;
V_127 . V_126 . V_138 = V_123 ;
V_127 . V_126 . V_117 = V_116 -> V_139 ;
V_127 . V_126 . V_84 = V_140 ;
V_127 . V_126 . V_55 = ( type != V_66 ? V_56 : V_71 ) ;
V_127 . V_126 . V_76 = type ;
V_33 . V_95 = & V_122 ;
V_33 . V_89 = & V_125 -> V_141 ;
V_33 . V_90 = & V_125 -> V_142 -> V_54 -> V_143 ;
if ( V_121 == V_144 )
V_116 -> V_120 ( V_116 , & V_127 . V_126 , & V_33 , & V_127 . V_74 , NULL ) ;
else
V_116 -> V_118 ( V_116 , & V_127 . V_126 , & V_33 , & V_127 . V_74 , NULL ) ;
}
static void F_53 ( struct V_124 * V_125 )
{
F_52 ( V_144 , V_66 , V_125 -> V_141 , 16 , V_125 ) ;
#if 0
if (!(dev->flags&IFF_UP))
return;
#endif
}
static void F_54 ( struct V_124 * V_125 )
{
int V_145 = 0 ;
struct V_53 * V_54 ;
struct V_146 * V_147 ;
struct V_124 * V_148 ;
F_55 () ;
F_56 () ;
F_57 (&init_net, dev) {
V_147 = F_58 ( V_54 -> V_70 ) ;
if ( V_147 == NULL )
continue;
for ( V_148 = F_58 ( V_147 -> V_149 ) ;
V_148 != NULL ;
V_148 = F_58 ( V_148 -> V_150 ) ) {
if ( V_148 -> V_141 == V_125 -> V_141 ) {
V_145 = 1 ;
break;
}
}
}
F_59 () ;
if ( V_145 == 0 ) {
F_52 ( V_151 , V_66 , V_125 -> V_141 , 16 , V_125 ) ;
if ( F_26 ( V_125 -> V_141 ) != V_66 ) {
if ( F_60 ( V_125 -> V_141 , NULL , 0 ) )
F_61 () ;
}
}
}
static void F_62 ( struct V_53 * V_54 , int V_152 )
{
if ( F_60 ( 0 , V_54 , V_152 ) )
F_61 () ;
F_63 ( 0 ) ;
F_64 ( & V_153 , V_54 ) ;
}
static int F_65 ( struct V_154 * V_155 , unsigned long V_156 , void * V_157 )
{
struct V_124 * V_125 = (struct V_124 * ) V_157 ;
switch ( V_156 ) {
case V_158 :
F_53 ( V_125 ) ;
F_66 ( V_125 -> V_142 -> V_54 ) ;
F_63 ( - 1 ) ;
break;
case V_159 :
F_54 ( V_125 ) ;
if ( V_125 -> V_142 && V_125 -> V_142 -> V_149 == NULL ) {
F_62 ( V_125 -> V_142 -> V_54 , 1 ) ;
} else {
F_63 ( - 1 ) ;
}
break;
}
return V_160 ;
}
static int F_60 ( T_1 V_161 , struct V_53 * V_54 , int V_152 )
{
int V_162 = 0 ;
int V_68 = V_94 ;
if ( V_152 )
V_68 = - 1 ;
F_14 () {
if ( V_161 && V_2 -> V_25 == V_161 ) {
V_2 -> V_28 |= V_21 ;
V_162 ++ ;
} else if ( V_54 && V_2 -> V_23 ) {
int V_163 = 0 ;
F_3 (fi) {
if ( V_5 -> V_20 & V_21 )
V_163 ++ ;
else if ( V_5 -> V_6 == V_54 &&
V_5 -> V_18 != V_68 ) {
F_41 ( & V_100 ) ;
V_5 -> V_20 |= V_21 ;
V_2 -> V_101 -= V_5 -> V_103 ;
V_5 -> V_103 = 0 ;
F_42 ( & V_100 ) ;
V_163 ++ ;
}
} F_5 (fi)
if ( V_163 == V_2 -> V_23 ) {
V_2 -> V_28 |= V_21 ;
V_162 ++ ;
}
}
} F_15 () ;
return V_162 ;
}
static int F_66 ( struct V_53 * V_54 )
{
int V_162 = 0 ;
if ( ! ( V_54 -> V_60 & V_61 ) )
return 0 ;
F_14 () {
int V_164 = 0 ;
F_3 (fi) {
if ( ! ( V_5 -> V_20 & V_21 ) ) {
V_164 ++ ;
continue;
}
if ( V_5 -> V_6 == NULL || ! ( V_5 -> V_6 -> V_60 & V_61 ) )
continue;
if ( V_5 -> V_6 != V_54 || V_54 -> V_70 == NULL )
continue;
V_164 ++ ;
F_41 ( & V_100 ) ;
V_5 -> V_103 = 0 ;
V_5 -> V_20 &= ~ V_21 ;
F_42 ( & V_100 ) ;
} F_5 ( V_2 ) ;
if ( V_164 > 0 ) {
V_2 -> V_28 &= ~ V_21 ;
V_162 ++ ;
}
} F_15 () ;
return V_162 ;
}
void T_2 F_67 ( void )
{
F_68 () ;
F_69 () ;
F_70 ( & V_165 ) ;
}
void T_3 F_71 ( void )
{
F_72 () ;
F_73 () ;
F_74 ( & V_165 ) ;
F_75 ( V_166 , V_144 , F_51 , NULL , NULL ) ;
F_75 ( V_166 , V_151 , F_44 , NULL , NULL ) ;
}
