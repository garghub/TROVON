static struct V_1 * F_1 ( struct V_2 * V_2 )
{
return F_2 ( V_2 , V_3 ) ;
}
static inline T_1 F_3 ( T_2 V_4 )
{
return ( ( V_4 >> 8 ) ^ V_4 ) % V_5 ;
}
static struct V_6 *
F_4 ( struct V_1 * V_7 , T_2 V_4 )
{
struct V_8 * V_9 ;
struct V_6 * V_10 ;
V_9 = & V_7 -> V_11 [ F_3 ( V_4 ) ] ;
F_5 (inst, head, hlist) {
if ( V_10 -> V_4 == V_4 )
return V_10 ;
}
return NULL ;
}
static struct V_6 *
F_6 ( struct V_1 * V_7 , T_2 V_4 ,
int V_12 )
{
struct V_6 * V_10 ;
unsigned int V_13 ;
int V_14 ;
F_7 ( & V_7 -> V_15 ) ;
if ( F_4 ( V_7 , V_4 ) ) {
V_14 = - V_16 ;
goto V_17;
}
V_10 = F_8 ( sizeof( * V_10 ) , V_18 ) ;
if ( ! V_10 ) {
V_14 = - V_19 ;
goto V_17;
}
V_10 -> V_4 = V_4 ;
V_10 -> V_20 = V_12 ;
V_10 -> V_21 = V_22 ;
V_10 -> V_23 = 0xffff ;
V_10 -> V_24 = V_25 ;
F_9 ( & V_10 -> V_26 ) ;
F_10 ( & V_10 -> V_27 ) ;
if ( ! F_11 ( V_28 ) ) {
V_14 = - V_29 ;
goto V_30;
}
V_13 = F_3 ( V_4 ) ;
F_12 ( & V_10 -> V_31 , & V_7 -> V_11 [ V_13 ] ) ;
F_13 ( & V_7 -> V_15 ) ;
return V_10 ;
V_30:
F_14 ( V_10 ) ;
V_17:
F_13 ( & V_7 -> V_15 ) ;
return F_15 ( V_14 ) ;
}
static void
F_16 ( struct V_32 * V_9 )
{
struct V_6 * V_10 = F_17 ( V_9 , struct V_6 ,
V_33 ) ;
F_18 ( V_10 , NULL , 0 ) ;
F_14 ( V_10 ) ;
F_19 ( V_28 ) ;
}
static void
F_20 ( struct V_6 * V_10 )
{
F_21 ( & V_10 -> V_31 ) ;
F_22 ( & V_10 -> V_33 , F_16 ) ;
}
static void
F_23 ( struct V_1 * V_7 , struct V_6 * V_10 )
{
F_7 ( & V_7 -> V_15 ) ;
F_20 ( V_10 ) ;
F_13 ( & V_7 -> V_15 ) ;
}
static inline void
F_24 ( struct V_6 * V_34 , struct V_35 * V_36 )
{
F_25 ( & V_36 -> V_37 , & V_34 -> V_27 ) ;
V_34 -> V_38 ++ ;
}
static void
F_26 ( struct V_6 * V_34 , struct V_35 * V_36 )
{
F_27 ( & V_36 -> V_37 ) ;
V_34 -> V_38 -- ;
}
static struct V_35 *
F_28 ( struct V_6 * V_34 , unsigned int V_39 )
{
struct V_35 * V_36 = NULL , * V_40 ;
F_29 ( & V_34 -> V_26 ) ;
F_30 (i, &queue->queue_list, list) {
if ( V_40 -> V_39 == V_39 ) {
V_36 = V_40 ;
break;
}
}
if ( V_36 )
F_26 ( V_34 , V_36 ) ;
F_31 ( & V_34 -> V_26 ) ;
return V_36 ;
}
static void
F_18 ( struct V_6 * V_34 , T_3 V_41 , unsigned long V_42 )
{
struct V_35 * V_36 , * V_43 ;
F_29 ( & V_34 -> V_26 ) ;
F_32 (entry, next, &queue->queue_list, list) {
if ( ! V_41 || V_41 ( V_36 , V_42 ) ) {
F_27 ( & V_36 -> V_37 ) ;
V_34 -> V_38 -- ;
F_33 ( V_36 , V_44 ) ;
}
}
F_31 ( & V_34 -> V_26 ) ;
}
static void
F_34 ( struct V_45 * V_46 , const struct V_45 * V_47 , int V_48 , int V_49 )
{
int V_40 , V_50 = 0 ;
int V_51 = 0 ;
struct V_52 * V_52 ;
unsigned int V_53 ;
if ( V_48 <= F_35 ( V_46 ) ) {
F_36 ( V_47 , 0 , F_37 ( V_46 , V_48 ) , V_48 ) ;
return;
}
if ( V_49 ) {
F_36 ( V_47 , 0 , F_37 ( V_46 , V_49 ) , V_49 ) ;
V_48 -= V_49 ;
} else {
V_51 = F_38 ( int , F_39 ( V_47 ) , V_48 ) ;
if ( V_51 ) {
V_52 = F_40 ( V_47 -> V_9 ) ;
V_53 = V_47 -> V_42 - ( unsigned char * ) F_41 ( V_52 ) ;
F_42 ( V_46 , 0 , V_52 , V_53 , V_51 ) ;
F_43 ( V_52 ) ;
V_50 = 1 ;
V_48 -= V_51 ;
}
}
V_46 -> V_54 += V_48 + V_51 ;
V_46 -> V_48 += V_48 + V_51 ;
V_46 -> V_55 += V_48 + V_51 ;
for ( V_40 = 0 ; V_40 < F_44 ( V_47 ) -> V_56 ; V_40 ++ ) {
if ( ! V_48 )
break;
F_44 ( V_46 ) -> V_57 [ V_50 ] = F_44 ( V_47 ) -> V_57 [ V_40 ] ;
F_44 ( V_46 ) -> V_57 [ V_50 ] . V_58 = F_38 ( int , F_44 ( V_46 ) -> V_57 [ V_50 ] . V_58 , V_48 ) ;
V_48 -= F_44 ( V_46 ) -> V_57 [ V_50 ] . V_58 ;
F_45 ( V_46 , V_50 ) ;
V_50 ++ ;
}
F_44 ( V_46 ) -> V_56 = V_50 ;
}
static int F_46 ( struct V_45 * V_59 , struct V_45 * V_60 )
{
T_4 V_61 = 0 ;
if ( V_60 -> V_62 == V_63 )
V_61 = V_64 ;
if ( F_47 ( V_60 ) )
V_61 |= V_65 ;
return V_61 ? F_48 ( V_59 , V_66 , F_49 ( V_61 ) ) : 0 ;
}
static struct V_45 *
F_50 ( struct V_6 * V_34 ,
struct V_35 * V_36 ,
T_5 * * V_67 )
{
T_6 V_58 ;
T_6 V_55 = 0 , V_68 = 0 ;
int V_49 = 0 ;
struct V_45 * V_69 ;
struct V_70 * V_71 ;
struct V_72 * V_73 ;
struct V_74 * V_75 ;
struct V_76 * V_77 ;
struct V_45 * V_78 = V_36 -> V_69 ;
struct V_79 * V_80 ;
struct V_79 * V_81 ;
struct V_82 * V_83 = NULL ;
enum V_84 V_85 ( V_86 ) ;
V_58 = F_51 ( sizeof( struct V_76 ) )
+ F_52 ( sizeof( struct V_72 ) )
+ F_52 ( sizeof( V_87 ) )
+ F_52 ( sizeof( V_87 ) )
#ifdef F_53
+ F_52 ( sizeof( V_87 ) )
+ F_52 ( sizeof( V_87 ) )
#endif
+ F_52 ( sizeof( V_87 ) )
+ F_52 ( sizeof( struct V_88 ) )
+ F_52 ( sizeof( V_87 ) )
+ F_52 ( sizeof( V_87 ) ) ;
if ( V_78 -> V_89 . V_90 )
V_58 += F_52 ( sizeof( struct V_91 ) ) ;
V_81 = V_36 -> V_81 ;
switch ( (enum V_92 ) F_54 ( V_34 -> V_24 ) ) {
case V_93 :
case V_25 :
break;
case V_94 :
if ( ! ( V_34 -> V_61 & V_95 ) &&
V_78 -> V_62 == V_63 &&
F_55 ( V_78 ) )
return NULL ;
V_55 = F_54 ( V_34 -> V_23 ) ;
if ( V_55 == 0 || V_55 > V_78 -> V_48 )
V_55 = V_78 -> V_48 ;
if ( ! V_78 -> V_96 ||
F_39 ( V_78 ) < V_97 ||
F_44 ( V_78 ) -> V_56 >= V_98 )
V_49 = F_39 ( V_78 ) ;
if ( F_56 ( V_78 ) )
V_49 = V_78 -> V_48 ;
V_49 = F_38 ( int , V_55 , V_49 ) ;
V_58 += sizeof( struct V_70 ) + V_49 ;
V_68 = V_78 -> V_48 ;
break;
}
if ( V_34 -> V_61 & V_99 )
V_83 = F_57 ( V_78 , & V_58 , & V_86 ) ;
V_69 = F_58 ( & V_100 , V_58 , V_34 -> V_20 ,
V_18 ) ;
if ( ! V_69 )
return NULL ;
V_75 = F_59 ( V_69 , 0 , 0 ,
V_101 << 8 | V_102 ,
sizeof( struct V_76 ) , 0 ) ;
if ( ! V_75 ) {
F_60 ( V_69 ) ;
return NULL ;
}
V_77 = F_61 ( V_75 ) ;
V_77 -> V_103 = V_36 -> V_104 ;
V_77 -> V_105 = V_106 ;
V_77 -> V_107 = F_62 ( V_34 -> V_4 ) ;
V_71 = F_63 ( V_69 , V_108 , sizeof( * V_73 ) ) ;
V_73 = F_64 ( V_71 ) ;
V_73 -> V_109 = V_78 -> V_110 ;
V_73 -> V_111 = V_36 -> V_111 ;
* V_67 = & V_73 -> V_112 ;
V_80 = V_36 -> V_80 ;
if ( V_80 ) {
#ifndef F_53
if ( F_48 ( V_69 , V_113 , F_49 ( V_80 -> V_114 ) ) )
goto V_115;
#else
if ( V_36 -> V_104 == V_116 ) {
if ( F_48 ( V_69 , V_117 ,
F_49 ( V_80 -> V_114 ) ) ||
F_48 ( V_69 , V_113 ,
F_49 ( F_65 ( V_80 ) -> V_118 -> V_119 -> V_114 ) ) )
goto V_115;
} else {
if ( F_48 ( V_69 , V_113 ,
F_49 ( V_80 -> V_114 ) ) )
goto V_115;
if ( V_78 -> V_120 && V_78 -> V_120 -> V_121 &&
F_48 ( V_69 , V_117 ,
F_49 ( V_78 -> V_120 -> V_121 -> V_114 ) ) )
goto V_115;
}
#endif
}
if ( V_81 ) {
#ifndef F_53
if ( F_48 ( V_69 , V_122 , F_49 ( V_81 -> V_114 ) ) )
goto V_115;
#else
if ( V_36 -> V_104 == V_116 ) {
if ( F_48 ( V_69 , V_123 ,
F_49 ( V_81 -> V_114 ) ) ||
F_48 ( V_69 , V_122 ,
F_49 ( F_65 ( V_81 ) -> V_118 -> V_119 -> V_114 ) ) )
goto V_115;
} else {
if ( F_48 ( V_69 , V_122 ,
F_49 ( V_81 -> V_114 ) ) )
goto V_115;
if ( V_78 -> V_120 && V_78 -> V_120 -> V_124 &&
F_48 ( V_69 , V_123 ,
F_49 ( V_78 -> V_120 -> V_124 -> V_114 ) ) )
goto V_115;
}
#endif
}
if ( V_78 -> V_125 &&
F_48 ( V_69 , V_126 , F_49 ( V_78 -> V_125 ) ) )
goto V_115;
if ( V_80 && V_78 -> V_119 &&
V_78 -> V_127 != V_78 -> V_128 ) {
struct V_88 V_129 ;
int V_48 = F_66 ( V_78 , V_129 . V_130 ) ;
if ( V_48 ) {
V_129 . V_131 = F_62 ( V_48 ) ;
if ( F_67 ( V_69 , V_132 , sizeof( V_129 ) , & V_129 ) )
goto V_115;
}
}
if ( V_78 -> V_89 . V_90 ) {
struct V_91 V_133 ;
struct V_134 V_135 = F_68 ( V_78 -> V_89 ) ;
V_133 . V_136 = F_69 ( V_135 . V_137 ) ;
V_133 . V_138 = F_69 ( V_135 . V_139 ) ;
if ( F_67 ( V_69 , V_140 , sizeof( V_133 ) , & V_133 ) )
goto V_115;
}
if ( V_83 && F_70 ( V_69 , V_83 , V_86 ) < 0 )
goto V_115;
if ( V_68 > 0 && F_48 ( V_69 , V_141 , F_49 ( V_68 ) ) )
goto V_115;
if ( F_46 ( V_69 , V_78 ) )
goto V_115;
if ( V_55 ) {
struct V_70 * V_71 ;
if ( F_35 ( V_69 ) < sizeof( * V_71 ) + V_49 )
goto V_115;
V_71 = (struct V_70 * ) F_37 ( V_69 , sizeof( * V_71 ) ) ;
V_71 -> V_142 = V_143 ;
V_71 -> V_144 = F_71 ( V_55 ) ;
F_34 ( V_69 , V_78 , V_55 , V_49 ) ;
}
V_75 -> V_145 = V_69 -> V_48 ;
return V_69 ;
V_115:
F_60 ( V_69 ) ;
F_72 ( L_1 ) ;
return NULL ;
}
static int
F_73 ( struct V_2 * V_2 , struct V_6 * V_34 ,
struct V_35 * V_36 )
{
struct V_45 * V_146 ;
int V_14 = - V_147 ;
T_5 * V_67 ;
int V_148 = 0 ;
V_146 = F_50 ( V_34 , V_36 , & V_67 ) ;
if ( V_146 == NULL ) {
V_14 = - V_19 ;
goto V_149;
}
F_29 ( & V_34 -> V_26 ) ;
if ( ! V_34 -> V_20 ) {
V_14 = - V_150 ;
goto V_151;
}
if ( V_34 -> V_38 >= V_34 -> V_21 ) {
if ( V_34 -> V_61 & V_152 ) {
V_148 = 1 ;
V_14 = 0 ;
} else {
V_34 -> V_153 ++ ;
F_74 ( L_2 ,
V_34 -> V_38 ) ;
}
goto V_151;
}
V_36 -> V_39 = ++ V_34 -> V_154 ;
* V_67 = F_49 ( V_36 -> V_39 ) ;
V_14 = F_75 ( V_146 , V_2 , V_34 -> V_20 , V_155 ) ;
if ( V_14 < 0 ) {
V_34 -> V_156 ++ ;
goto V_157;
}
F_24 ( V_34 , V_36 ) ;
F_31 ( & V_34 -> V_26 ) ;
return 0 ;
V_151:
F_60 ( V_146 ) ;
V_157:
F_31 ( & V_34 -> V_26 ) ;
if ( V_148 )
F_33 ( V_36 , V_158 ) ;
V_149:
return V_14 ;
}
static struct V_35 *
F_76 ( struct V_35 * V_159 )
{
struct V_35 * V_36 = F_77 ( V_159 , V_159 -> V_58 , V_18 ) ;
if ( V_36 ) {
if ( F_78 ( V_36 ) )
return V_36 ;
F_14 ( V_36 ) ;
}
return NULL ;
}
static void F_79 ( struct V_45 * V_69 )
{
if ( V_69 -> V_120 )
F_80 ( V_69 , V_69 -> V_128 - V_69 -> V_127 ) ;
}
static void F_81 ( struct V_45 * V_69 )
{
if ( V_69 -> V_120 )
F_82 ( V_69 , V_69 -> V_128 - V_69 -> V_127 ) ;
}
static void F_83 ( struct V_35 * V_36 )
{
F_84 ( V_36 ) ;
F_14 ( V_36 ) ;
}
static int
F_85 ( struct V_2 * V_2 , struct V_6 * V_34 ,
struct V_45 * V_69 , struct V_35 * V_36 )
{
int V_160 = - V_19 ;
struct V_35 * V_161 ;
F_81 ( V_69 ) ;
if ( V_69 -> V_43 == NULL ) {
struct V_45 * V_162 = V_36 -> V_69 ;
V_36 -> V_69 = V_69 ;
V_160 = F_73 ( V_2 , V_34 , V_36 ) ;
if ( V_160 )
V_36 -> V_69 = V_162 ;
return V_160 ;
}
V_69 -> V_43 = NULL ;
V_161 = F_76 ( V_36 ) ;
if ( V_161 ) {
V_161 -> V_69 = V_69 ;
V_160 = F_73 ( V_2 , V_34 , V_161 ) ;
if ( V_160 )
F_83 ( V_161 ) ;
}
return V_160 ;
}
static int
F_86 ( struct V_35 * V_36 , unsigned int V_163 )
{
unsigned int V_164 ;
struct V_6 * V_34 ;
struct V_45 * V_69 , * V_165 ;
int V_14 = - V_147 ;
struct V_2 * V_2 = F_87 ( V_36 -> V_80 ?
V_36 -> V_80 : V_36 -> V_81 ) ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
V_34 = F_4 ( V_7 , V_163 ) ;
if ( ! V_34 )
return - V_166 ;
if ( V_34 -> V_24 == V_25 )
return - V_150 ;
V_69 = V_36 -> V_69 ;
switch ( V_36 -> V_104 ) {
case V_167 :
V_69 -> V_110 = F_62 ( V_168 ) ;
break;
case V_169 :
V_69 -> V_110 = F_62 ( V_170 ) ;
break;
}
if ( ( V_34 -> V_61 & V_95 ) || ! F_47 ( V_69 ) )
return F_73 ( V_2 , V_34 , V_36 ) ;
F_79 ( V_69 ) ;
V_165 = F_88 ( V_69 , 0 ) ;
if ( F_89 ( V_165 ) )
goto V_171;
V_164 = 0 ;
V_14 = 0 ;
do {
struct V_45 * V_146 = V_165 -> V_43 ;
if ( V_14 == 0 )
V_14 = F_85 ( V_2 , V_34 ,
V_165 , V_36 ) ;
if ( V_14 == 0 )
V_164 ++ ;
else
F_60 ( V_165 ) ;
V_165 = V_146 ;
} while ( V_165 );
if ( V_164 ) {
if ( V_14 )
F_83 ( V_36 ) ;
F_60 ( V_69 ) ;
return 0 ;
}
V_171:
F_81 ( V_69 ) ;
return V_14 ;
}
static int
F_90 ( void * V_42 , int V_55 , struct V_35 * V_159 , int V_172 )
{
struct V_45 * V_146 ;
if ( V_172 < 0 ) {
if ( F_91 ( V_159 -> V_69 , V_55 ) )
return - V_19 ;
} else if ( V_172 > 0 ) {
if ( V_55 > 0xFFFF )
return - V_150 ;
if ( V_172 > F_35 ( V_159 -> V_69 ) ) {
V_146 = F_92 ( V_159 -> V_69 , F_93 ( V_159 -> V_69 ) ,
V_172 , V_18 ) ;
if ( ! V_146 ) {
F_94 ( V_173 L_3
L_4 ) ;
return - V_19 ;
}
F_60 ( V_159 -> V_69 ) ;
V_159 -> V_69 = V_146 ;
}
F_37 ( V_159 -> V_69 , V_172 ) ;
}
if ( ! F_95 ( V_159 -> V_69 , V_55 ) )
return - V_19 ;
F_96 ( V_159 -> V_69 , V_42 , V_55 ) ;
V_159 -> V_69 -> V_62 = V_174 ;
return 0 ;
}
static int
F_97 ( struct V_6 * V_34 ,
unsigned char V_175 , unsigned int V_176 )
{
int V_177 = 0 ;
F_29 ( & V_34 -> V_26 ) ;
switch ( V_175 ) {
case V_25 :
case V_93 :
V_34 -> V_24 = V_175 ;
V_34 -> V_23 = 0 ;
break;
case V_94 :
V_34 -> V_24 = V_175 ;
if ( V_176 > 0xffff - V_178 )
V_34 -> V_23 = 0xffff - V_178 ;
else
V_34 -> V_23 = V_176 ;
break;
default:
V_177 = - V_150 ;
}
F_31 ( & V_34 -> V_26 ) ;
return V_177 ;
}
static int
F_98 ( struct V_35 * V_36 , unsigned long V_114 )
{
if ( V_36 -> V_80 )
if ( V_36 -> V_80 -> V_114 == V_114 )
return 1 ;
if ( V_36 -> V_81 )
if ( V_36 -> V_81 -> V_114 == V_114 )
return 1 ;
#ifdef F_53
if ( V_36 -> V_69 -> V_120 ) {
if ( V_36 -> V_69 -> V_120 -> V_121 &&
V_36 -> V_69 -> V_120 -> V_121 -> V_114 == V_114 )
return 1 ;
if ( V_36 -> V_69 -> V_120 -> V_124 &&
V_36 -> V_69 -> V_120 -> V_124 -> V_114 == V_114 )
return 1 ;
}
#endif
return 0 ;
}
static void
F_99 ( struct V_2 * V_2 , int V_114 )
{
int V_40 ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
F_100 () ;
for ( V_40 = 0 ; V_40 < V_5 ; V_40 ++ ) {
struct V_6 * V_10 ;
struct V_8 * V_9 = & V_7 -> V_11 [ V_40 ] ;
F_5 (inst, head, hlist)
F_18 ( V_10 , F_98 , V_114 ) ;
}
F_101 () ;
}
static int
F_102 ( struct V_179 * V_180 ,
unsigned long V_181 , void * V_182 )
{
struct V_79 * V_119 = V_182 ;
if ( V_181 == V_183 )
F_99 ( F_87 ( V_119 ) , V_119 -> V_114 ) ;
return V_184 ;
}
static int
F_103 ( struct V_179 * V_180 ,
unsigned long V_181 , void * V_182 )
{
struct V_185 * V_186 = V_182 ;
struct V_1 * V_7 = F_1 ( V_186 -> V_2 ) ;
if ( V_181 == V_187 && V_186 -> V_110 == V_188 ) {
int V_40 ;
F_7 ( & V_7 -> V_15 ) ;
for ( V_40 = 0 ; V_40 < V_5 ; V_40 ++ ) {
struct V_189 * V_190 ;
struct V_6 * V_10 ;
struct V_8 * V_9 = & V_7 -> V_11 [ V_40 ] ;
F_104 (inst, t2, head, hlist) {
if ( V_186 -> V_12 == V_10 -> V_20 )
F_20 ( V_10 ) ;
}
}
F_13 ( & V_7 -> V_15 ) ;
}
return V_184 ;
}
static struct V_6 *
F_105 ( struct V_1 * V_7 , T_7 V_4 , int V_191 )
{
struct V_6 * V_34 ;
V_34 = F_4 ( V_7 , V_4 ) ;
if ( ! V_34 )
return F_15 ( - V_192 ) ;
if ( V_34 -> V_20 != V_191 )
return F_15 ( - V_193 ) ;
return V_34 ;
}
static struct V_194 *
F_106 ( const struct V_70 * const V_195 [] )
{
struct V_194 * V_196 ;
unsigned int V_197 ;
if ( ! V_195 [ V_198 ] )
return NULL ;
V_196 = F_64 ( V_195 [ V_198 ] ) ;
V_197 = F_107 ( V_196 -> V_197 ) & V_199 ;
if ( V_197 > V_200 || V_197 == V_201 )
return NULL ;
return V_196 ;
}
static int F_108 ( unsigned int V_39 , unsigned int V_202 )
{
return ( int ) ( V_39 - V_202 ) > 0 ;
}
static int
F_109 ( struct V_203 * V_204 , struct V_45 * V_69 ,
const struct V_74 * V_75 ,
const struct V_70 * const V_195 [] )
{
struct V_76 * V_77 = F_61 ( V_75 ) ;
struct V_35 * V_36 , * V_205 ;
unsigned int V_197 , V_206 ;
struct V_194 * V_196 ;
struct V_6 * V_34 ;
F_110 ( V_207 ) ;
T_7 V_4 = F_111 ( V_77 -> V_107 ) ;
struct V_2 * V_2 = F_112 ( V_204 ) ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
V_34 = F_105 ( V_7 , V_4 ,
F_113 ( V_69 ) . V_12 ) ;
if ( F_89 ( V_34 ) )
return F_114 ( V_34 ) ;
V_196 = F_106 ( V_195 ) ;
if ( ! V_196 )
return - V_150 ;
V_197 = F_107 ( V_196 -> V_197 ) ;
V_206 = F_107 ( V_196 -> V_39 ) ;
F_29 ( & V_34 -> V_26 ) ;
F_32 (entry, tmp, &queue->queue_list, list) {
if ( F_108 ( V_36 -> V_39 , V_206 ) )
break;
F_26 ( V_34 , V_36 ) ;
F_25 ( & V_36 -> V_37 , & V_207 ) ;
}
F_31 ( & V_34 -> V_26 ) ;
if ( F_115 ( & V_207 ) )
return - V_208 ;
F_32 (entry, tmp, &batch_list, list) {
if ( V_195 [ V_126 ] )
V_36 -> V_69 -> V_125 = F_107 ( F_116 ( V_195 [ V_126 ] ) ) ;
F_33 ( V_36 , V_197 ) ;
}
return 0 ;
}
static int
F_117 ( struct V_203 * V_204 , struct V_45 * V_69 ,
const struct V_74 * V_75 ,
const struct V_70 * const V_195 [] )
{
struct V_76 * V_77 = F_61 ( V_75 ) ;
T_2 V_4 = F_111 ( V_77 -> V_107 ) ;
struct V_194 * V_196 ;
struct V_6 * V_34 ;
unsigned int V_197 ;
struct V_35 * V_36 ;
enum V_84 V_85 ( V_86 ) ;
struct V_82 * V_83 = NULL ;
struct V_2 * V_2 = F_112 ( V_204 ) ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
V_34 = F_4 ( V_7 , V_4 ) ;
if ( ! V_34 )
V_34 = F_105 ( V_7 , V_4 ,
F_113 ( V_69 ) . V_12 ) ;
if ( F_89 ( V_34 ) )
return F_114 ( V_34 ) ;
V_196 = F_106 ( V_195 ) ;
if ( ! V_196 )
return - V_150 ;
V_197 = F_107 ( V_196 -> V_197 ) ;
V_36 = F_28 ( V_34 , F_107 ( V_196 -> V_39 ) ) ;
if ( V_36 == NULL )
return - V_208 ;
F_100 () ;
if ( V_195 [ V_209 ] && ( V_34 -> V_61 & V_99 ) )
V_83 = F_118 ( V_36 -> V_69 , V_195 [ V_209 ] , & V_86 ) ;
if ( V_195 [ V_143 ] ) {
T_7 V_210 = V_144 ( V_195 [ V_143 ] ) ;
int V_172 = V_210 - V_36 -> V_69 -> V_48 ;
if ( F_90 ( F_64 ( V_195 [ V_143 ] ) ,
V_210 , V_36 , V_172 ) < 0 )
V_197 = V_44 ;
if ( V_83 )
F_119 ( V_69 , V_83 , V_86 , V_172 ) ;
}
F_101 () ;
if ( V_195 [ V_126 ] )
V_36 -> V_69 -> V_125 = F_107 ( F_116 ( V_195 [ V_126 ] ) ) ;
F_33 ( V_36 , V_197 ) ;
return 0 ;
}
static int
F_120 ( struct V_203 * V_204 , struct V_45 * V_69 ,
const struct V_74 * V_75 ,
const struct V_70 * const V_195 [] )
{
return - V_211 ;
}
static int
F_121 ( struct V_203 * V_204 , struct V_45 * V_69 ,
const struct V_74 * V_75 ,
const struct V_70 * const V_195 [] )
{
struct V_76 * V_77 = F_61 ( V_75 ) ;
T_2 V_4 = F_111 ( V_77 -> V_107 ) ;
struct V_6 * V_34 ;
struct V_212 * V_213 = NULL ;
struct V_2 * V_2 = F_112 ( V_204 ) ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
int V_160 = 0 ;
if ( V_195 [ V_214 ] ) {
V_213 = F_64 ( V_195 [ V_214 ] ) ;
switch ( V_213 -> V_215 ) {
case V_216 : return 0 ;
case V_217 : return 0 ;
}
}
F_100 () ;
V_34 = F_4 ( V_7 , V_4 ) ;
if ( V_34 && V_34 -> V_20 != F_113 ( V_69 ) . V_12 ) {
V_160 = - V_193 ;
goto V_157;
}
if ( V_213 != NULL ) {
switch ( V_213 -> V_215 ) {
case V_218 :
if ( V_34 ) {
V_160 = - V_219 ;
goto V_157;
}
V_34 = F_6 ( V_7 , V_4 ,
F_113 ( V_69 ) . V_12 ) ;
if ( F_89 ( V_34 ) ) {
V_160 = F_114 ( V_34 ) ;
goto V_157;
}
break;
case V_220 :
if ( ! V_34 ) {
V_160 = - V_192 ;
goto V_157;
}
F_23 ( V_7 , V_34 ) ;
break;
case V_216 :
case V_217 :
break;
default:
V_160 = - V_211 ;
break;
}
}
if ( V_195 [ V_221 ] ) {
struct V_222 * V_223 ;
if ( ! V_34 ) {
V_160 = - V_192 ;
goto V_157;
}
V_223 = F_64 ( V_195 [ V_221 ] ) ;
F_97 ( V_34 , V_223 -> V_24 ,
F_107 ( V_223 -> V_23 ) ) ;
}
if ( V_195 [ V_224 ] ) {
T_5 * V_21 ;
if ( ! V_34 ) {
V_160 = - V_192 ;
goto V_157;
}
V_21 = F_64 ( V_195 [ V_224 ] ) ;
F_29 ( & V_34 -> V_26 ) ;
V_34 -> V_21 = F_107 ( * V_21 ) ;
F_31 ( & V_34 -> V_26 ) ;
}
if ( V_195 [ V_225 ] ) {
T_4 V_61 , V_226 ;
if ( ! V_34 ) {
V_160 = - V_192 ;
goto V_157;
}
if ( ! V_195 [ V_227 ] ) {
V_160 = - V_150 ;
goto V_157;
}
V_61 = F_107 ( F_116 ( V_195 [ V_225 ] ) ) ;
V_226 = F_107 ( F_116 ( V_195 [ V_227 ] ) ) ;
if ( V_61 >= V_228 ) {
V_160 = - V_229 ;
goto V_157;
}
F_29 ( & V_34 -> V_26 ) ;
V_34 -> V_61 &= ~ V_226 ;
V_34 -> V_61 |= V_61 & V_226 ;
F_31 ( & V_34 -> V_26 ) ;
}
V_157:
F_101 () ;
return V_160 ;
}
static struct V_189 * F_122 ( struct V_230 * V_231 )
{
struct V_232 * V_233 = V_231 -> V_234 ;
struct V_2 * V_2 ;
struct V_1 * V_7 ;
if ( ! V_233 )
return NULL ;
V_2 = F_123 ( V_231 ) ;
V_7 = F_1 ( V_2 ) ;
for ( V_233 -> V_235 = 0 ; V_233 -> V_235 < V_5 ; V_233 -> V_235 ++ ) {
if ( ! F_124 ( & V_7 -> V_11 [ V_233 -> V_235 ] ) )
return V_7 -> V_11 [ V_233 -> V_235 ] . V_236 ;
}
return NULL ;
}
static struct V_189 * F_125 ( struct V_230 * V_231 , struct V_189 * V_13 )
{
struct V_232 * V_233 = V_231 -> V_234 ;
struct V_2 * V_2 = F_123 ( V_231 ) ;
V_13 = V_13 -> V_43 ;
while ( ! V_13 ) {
struct V_1 * V_7 ;
if ( ++ V_233 -> V_235 >= V_5 )
return NULL ;
V_7 = F_1 ( V_2 ) ;
V_13 = V_7 -> V_11 [ V_233 -> V_235 ] . V_236 ;
}
return V_13 ;
}
static struct V_189 * F_126 ( struct V_230 * V_231 , T_8 V_237 )
{
struct V_189 * V_9 ;
V_9 = F_122 ( V_231 ) ;
if ( V_9 )
while ( V_237 && ( V_9 = F_125 ( V_231 , V_9 ) ) )
V_237 -- ;
return V_237 ? NULL : V_9 ;
}
static void * F_127 ( struct V_230 * V_238 , T_8 * V_237 )
__acquires( nfnl_queue_pernet( seq_file_net( V_238 )
static void * F_128 ( struct V_230 * V_238 , void * V_239 , T_8 * V_237 )
{
( * V_237 ) ++ ;
return F_125 ( V_238 , V_239 ) ;
}
static void F_129 ( struct V_230 * V_238 , void * V_239 )
__releases( nfnl_queue_pernet( seq_file_net( V_238 )
static int F_130 ( struct V_230 * V_238 , void * V_239 )
{
const struct V_6 * V_10 = V_239 ;
return F_131 ( V_238 , L_5 ,
V_10 -> V_4 ,
V_10 -> V_20 , V_10 -> V_38 ,
V_10 -> V_24 , V_10 -> V_23 ,
V_10 -> V_153 , V_10 -> V_156 ,
V_10 -> V_154 , 1 ) ;
}
static int F_132 ( struct V_240 * V_240 , struct V_241 * V_241 )
{
return F_133 ( V_240 , V_241 , & V_242 ,
sizeof( struct V_232 ) ) ;
}
static int T_9 F_134 ( struct V_2 * V_2 )
{
unsigned int V_40 ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
for ( V_40 = 0 ; V_40 < V_5 ; V_40 ++ )
F_135 ( & V_7 -> V_11 [ V_40 ] ) ;
F_9 ( & V_7 -> V_15 ) ;
#ifdef F_136
if ( ! F_137 ( L_6 , 0440 ,
V_2 -> V_243 . V_244 , & V_245 ) )
return - V_19 ;
#endif
return 0 ;
}
static void T_10 F_138 ( struct V_2 * V_2 )
{
#ifdef F_136
F_139 ( L_6 , V_2 -> V_243 . V_244 ) ;
#endif
}
static int T_11 F_140 ( void )
{
int V_177 = - V_19 ;
F_141 ( & V_246 ) ;
V_177 = F_142 ( & V_247 ) ;
if ( V_177 < 0 ) {
F_143 ( L_7 ) ;
goto V_248;
}
V_177 = F_144 ( & V_249 ) ;
if ( V_177 < 0 ) {
F_143 ( L_8 ) ;
goto V_250;
}
F_145 ( & V_251 ) ;
F_146 ( & V_252 ) ;
return V_177 ;
V_250:
F_147 ( & V_247 ) ;
V_248:
F_148 ( & V_246 ) ;
return V_177 ;
}
static void T_12 F_149 ( void )
{
F_150 () ;
F_151 ( & V_251 ) ;
F_152 ( & V_249 ) ;
F_147 ( & V_247 ) ;
F_148 ( & V_246 ) ;
F_153 () ;
}
