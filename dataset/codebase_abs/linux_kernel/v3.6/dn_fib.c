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
static inline T_2 F_44 ( struct V_29 * * V_33 , T_3 V_110 )
{
if ( V_33 [ V_109 - 1 ] )
V_110 = F_45 ( (struct V_111 * ) V_33 [ V_109 - 1 ] ) ;
return V_110 ;
}
static int F_46 ( struct V_112 * V_113 , struct V_73 * V_74 , void * V_114 )
{
struct V_115 * V_115 = F_47 ( V_113 -> V_116 ) ;
struct V_117 * V_118 ;
struct V_29 * * V_33 = V_114 ;
struct V_39 * V_40 = F_48 ( V_74 ) ;
if ( ! F_49 ( V_115 , & V_58 ) )
return - V_41 ;
if ( F_43 ( V_40 , V_33 ) )
return - V_41 ;
V_118 = F_50 ( F_44 ( V_33 , V_40 -> V_119 ) , 0 ) ;
if ( V_118 )
return V_118 -> V_120 ( V_118 , V_40 , (struct V_72 * ) V_33 , V_74 , & F_51 ( V_113 ) ) ;
return - V_121 ;
}
static int F_52 ( struct V_112 * V_113 , struct V_73 * V_74 , void * V_114 )
{
struct V_115 * V_115 = F_47 ( V_113 -> V_116 ) ;
struct V_117 * V_118 ;
struct V_29 * * V_33 = V_114 ;
struct V_39 * V_40 = F_48 ( V_74 ) ;
if ( ! F_49 ( V_115 , & V_58 ) )
return - V_41 ;
if ( F_43 ( V_40 , V_33 ) )
return - V_41 ;
V_118 = F_50 ( F_44 ( V_33 , V_40 -> V_119 ) , 1 ) ;
if ( V_118 )
return V_118 -> V_122 ( V_118 , V_40 , (struct V_72 * ) V_33 , V_74 , & F_51 ( V_113 ) ) ;
return - V_82 ;
}
static void F_53 ( int V_123 , int type , T_1 V_124 , int V_125 , struct V_126 * V_127 )
{
struct V_117 * V_118 ;
struct {
struct V_73 V_74 ;
struct V_39 V_128 ;
} V_129 ;
struct V_72 V_33 ;
memset ( & V_129 . V_128 , 0 , sizeof( V_129 . V_128 ) ) ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
if ( type == V_57 )
V_118 = F_50 ( V_130 , 1 ) ;
else
V_118 = F_50 ( V_131 , 1 ) ;
if ( V_118 == NULL )
return;
V_129 . V_74 . V_132 = sizeof( V_129 ) ;
V_129 . V_74 . V_133 = V_123 ;
V_129 . V_74 . V_134 = V_135 | V_136 | V_137 ;
V_129 . V_74 . V_138 = 0 ;
V_129 . V_74 . V_139 = 0 ;
V_129 . V_128 . V_140 = V_125 ;
V_129 . V_128 . V_119 = V_118 -> V_141 ;
V_129 . V_128 . V_84 = V_142 ;
V_129 . V_128 . V_55 = ( type != V_66 ? V_56 : V_71 ) ;
V_129 . V_128 . V_76 = type ;
V_33 . V_95 = & V_124 ;
V_33 . V_89 = & V_127 -> V_143 ;
V_33 . V_90 = & V_127 -> V_144 -> V_54 -> V_145 ;
if ( V_123 == V_146 )
V_118 -> V_122 ( V_118 , & V_129 . V_128 , & V_33 , & V_129 . V_74 , NULL ) ;
else
V_118 -> V_120 ( V_118 , & V_129 . V_128 , & V_33 , & V_129 . V_74 , NULL ) ;
}
static void F_54 ( struct V_126 * V_127 )
{
F_53 ( V_146 , V_66 , V_127 -> V_143 , 16 , V_127 ) ;
#if 0
if (!(dev->flags&IFF_UP))
return;
#endif
}
static void F_55 ( struct V_126 * V_127 )
{
int V_147 = 0 ;
struct V_53 * V_54 ;
struct V_148 * V_149 ;
struct V_126 * V_150 ;
F_56 () ;
F_57 () ;
F_58 (&init_net, dev) {
V_149 = F_59 ( V_54 -> V_70 ) ;
if ( V_149 == NULL )
continue;
for ( V_150 = F_59 ( V_149 -> V_151 ) ;
V_150 != NULL ;
V_150 = F_59 ( V_150 -> V_152 ) ) {
if ( V_150 -> V_143 == V_127 -> V_143 ) {
V_147 = 1 ;
break;
}
}
}
F_60 () ;
if ( V_147 == 0 ) {
F_53 ( V_153 , V_66 , V_127 -> V_143 , 16 , V_127 ) ;
if ( F_26 ( V_127 -> V_143 ) != V_66 ) {
if ( F_61 ( V_127 -> V_143 , NULL , 0 ) )
F_62 () ;
}
}
}
static void F_63 ( struct V_53 * V_54 , int V_154 )
{
if ( F_61 ( 0 , V_54 , V_154 ) )
F_62 () ;
F_64 ( 0 ) ;
F_65 ( & V_155 , V_54 ) ;
}
static int F_66 ( struct V_156 * V_157 , unsigned long V_158 , void * V_159 )
{
struct V_126 * V_127 = (struct V_126 * ) V_159 ;
switch ( V_158 ) {
case V_160 :
F_54 ( V_127 ) ;
F_67 ( V_127 -> V_144 -> V_54 ) ;
F_64 ( - 1 ) ;
break;
case V_161 :
F_55 ( V_127 ) ;
if ( V_127 -> V_144 && V_127 -> V_144 -> V_151 == NULL ) {
F_63 ( V_127 -> V_144 -> V_54 , 1 ) ;
} else {
F_64 ( - 1 ) ;
}
break;
}
return V_162 ;
}
static int F_61 ( T_1 V_163 , struct V_53 * V_54 , int V_154 )
{
int V_164 = 0 ;
int V_68 = V_94 ;
if ( V_154 )
V_68 = - 1 ;
F_14 () {
if ( V_163 && V_2 -> V_25 == V_163 ) {
V_2 -> V_28 |= V_21 ;
V_164 ++ ;
} else if ( V_54 && V_2 -> V_23 ) {
int V_165 = 0 ;
F_3 (fi) {
if ( V_5 -> V_20 & V_21 )
V_165 ++ ;
else if ( V_5 -> V_6 == V_54 &&
V_5 -> V_18 != V_68 ) {
F_41 ( & V_100 ) ;
V_5 -> V_20 |= V_21 ;
V_2 -> V_101 -= V_5 -> V_103 ;
V_5 -> V_103 = 0 ;
F_42 ( & V_100 ) ;
V_165 ++ ;
}
} F_5 (fi)
if ( V_165 == V_2 -> V_23 ) {
V_2 -> V_28 |= V_21 ;
V_164 ++ ;
}
}
} F_15 () ;
return V_164 ;
}
static int F_67 ( struct V_53 * V_54 )
{
int V_164 = 0 ;
if ( ! ( V_54 -> V_60 & V_61 ) )
return 0 ;
F_14 () {
int V_166 = 0 ;
F_3 (fi) {
if ( ! ( V_5 -> V_20 & V_21 ) ) {
V_166 ++ ;
continue;
}
if ( V_5 -> V_6 == NULL || ! ( V_5 -> V_6 -> V_60 & V_61 ) )
continue;
if ( V_5 -> V_6 != V_54 || V_54 -> V_70 == NULL )
continue;
V_166 ++ ;
F_41 ( & V_100 ) ;
V_5 -> V_103 = 0 ;
V_5 -> V_20 &= ~ V_21 ;
F_42 ( & V_100 ) ;
} F_5 ( V_2 ) ;
if ( V_166 > 0 ) {
V_2 -> V_28 &= ~ V_21 ;
V_164 ++ ;
}
} F_15 () ;
return V_164 ;
}
void T_4 F_68 ( void )
{
F_69 () ;
F_70 () ;
F_71 ( & V_167 ) ;
}
void T_5 F_72 ( void )
{
F_73 () ;
F_74 () ;
F_75 ( & V_167 ) ;
F_76 ( V_168 , V_146 , F_52 , NULL , NULL ) ;
F_76 ( V_168 , V_153 , F_46 , NULL , NULL ) ;
}
