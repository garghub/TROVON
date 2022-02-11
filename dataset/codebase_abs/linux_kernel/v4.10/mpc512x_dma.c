static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_5 * F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
return F_2 ( V_6 , struct V_5 , V_7 [ V_3 -> V_8 ] ) ;
}
static void F_4 ( struct V_1 * V_6 )
{
struct V_5 * V_9 = F_3 ( & V_6 -> V_4 ) ;
struct V_10 * V_11 = NULL ;
struct V_10 * V_12 = NULL ;
struct V_10 * V_13 ;
int V_14 = V_6 -> V_4 . V_8 ;
while ( ! F_5 ( & V_6 -> V_15 ) ) {
V_13 = F_6 ( & V_6 -> V_15 ,
struct V_10 , V_16 ) ;
if ( V_13 -> V_17 ) {
if ( F_5 ( & V_6 -> V_18 ) )
F_7 ( & V_13 -> V_16 , & V_6 -> V_18 ) ;
break;
} else {
F_7 ( & V_13 -> V_16 , & V_6 -> V_18 ) ;
}
}
F_8 (mdesc, &mchan->active, node) {
if ( ! V_11 )
V_11 = V_13 ;
if ( ! V_12 ) {
V_12 = V_13 ;
continue;
}
V_12 -> V_19 -> V_20 = V_13 -> V_21 ;
V_12 -> V_19 -> V_22 = 1 ;
V_13 -> V_19 -> V_23 = 1 ;
V_12 = V_13 ;
}
V_12 -> V_19 -> V_24 = 1 ;
F_9 ( & V_9 -> V_19 [ V_14 ] , V_11 -> V_19 , sizeof( struct V_25 ) ) ;
if ( V_11 != V_12 )
V_9 -> V_19 [ V_14 ] . V_22 = 1 ;
if ( V_9 -> V_26 ) {
F_10 ( & V_9 -> V_27 -> V_28 , V_14 ) ;
} else if ( V_11 -> V_17 ) {
F_10 ( & V_9 -> V_27 -> V_29 , V_14 ) ;
} else {
F_10 ( & V_9 -> V_27 -> V_28 , V_14 ) ;
}
}
static void F_11 ( struct V_5 * V_9 , T_1 V_30 , T_1 V_31 , int V_32 )
{
struct V_1 * V_6 ;
struct V_10 * V_13 ;
T_1 V_33 = V_30 | V_31 ;
int V_34 ;
while ( ( V_34 = F_12 ( V_33 ) - 1 ) >= 0 ) {
V_33 &= ~ ( 1 << V_34 ) ;
V_6 = & V_9 -> V_7 [ V_34 + V_32 ] ;
F_13 ( & V_6 -> V_35 ) ;
F_10 ( & V_9 -> V_27 -> V_36 , V_34 + V_32 ) ;
F_10 ( & V_9 -> V_27 -> V_37 , V_34 + V_32 ) ;
if ( V_31 & ( 1 << V_34 ) )
F_8 (mdesc, &mchan->active, node)
V_13 -> error = - V_38 ;
F_14 ( & V_6 -> V_18 , & V_6 -> V_39 ) ;
if ( ! F_5 ( & V_6 -> V_15 ) )
F_4 ( V_6 ) ;
F_15 ( & V_6 -> V_35 ) ;
}
}
static T_2 F_16 ( int V_40 , void * V_41 )
{
struct V_5 * V_9 = V_41 ;
T_3 V_31 ;
V_31 = F_17 ( & V_9 -> V_27 -> V_42 ) ;
F_13 ( & V_9 -> V_43 ) ;
if ( ( V_31 & V_44 ) && V_9 -> V_45 == 0 )
V_9 -> V_45 = V_31 ;
F_15 ( & V_9 -> V_43 ) ;
if ( V_9 -> V_46 . V_47 > 32 ) {
F_11 ( V_9 , F_17 ( & V_9 -> V_27 -> V_48 ) ,
F_17 ( & V_9 -> V_27 -> V_49 ) , 32 ) ;
}
F_11 ( V_9 , F_17 ( & V_9 -> V_27 -> V_50 ) ,
F_17 ( & V_9 -> V_27 -> V_51 ) , 0 ) ;
F_18 ( & V_9 -> V_52 ) ;
return V_53 ;
}
static void F_19 ( struct V_5 * V_9 )
{
T_4 V_54 = 0 ;
struct V_1 * V_6 ;
struct V_10 * V_13 ;
struct V_55 * V_56 ;
unsigned long V_57 ;
F_20 ( V_58 ) ;
int V_59 ;
for ( V_59 = 0 ; V_59 < V_9 -> V_46 . V_47 ; V_59 ++ ) {
V_6 = & V_9 -> V_7 [ V_59 ] ;
F_21 ( & V_6 -> V_35 , V_57 ) ;
if ( ! F_5 ( & V_6 -> V_39 ) )
F_14 ( & V_6 -> V_39 , & V_58 ) ;
F_22 ( & V_6 -> V_35 , V_57 ) ;
if ( F_5 ( & V_58 ) )
continue;
F_8 (mdesc, &list, node) {
V_56 = & V_13 -> V_56 ;
F_23 ( V_56 , NULL ) ;
V_54 = V_56 -> V_60 ;
F_24 ( V_56 ) ;
}
F_21 ( & V_6 -> V_35 , V_57 ) ;
F_14 ( & V_58 , & V_6 -> free ) ;
V_6 -> V_4 . V_61 = V_54 ;
F_22 ( & V_6 -> V_35 , V_57 ) ;
}
}
static void F_25 ( unsigned long V_41 )
{
struct V_5 * V_9 = ( void * ) V_41 ;
unsigned long V_57 ;
T_3 V_31 ;
F_21 ( & V_9 -> V_43 , V_57 ) ;
V_31 = V_9 -> V_45 ;
V_9 -> V_45 = 0 ;
F_22 ( & V_9 -> V_43 , V_57 ) ;
if ( V_31 ) {
F_26 ( V_9 -> V_46 . V_62 ,
L_1 ,
F_27 ( V_31 ) ) ;
if ( V_31 & V_63 )
F_26 ( V_9 -> V_46 . V_62 , L_2 ) ;
if ( V_31 & V_64 )
F_26 ( V_9 -> V_46 . V_62 , L_3 ) ;
if ( V_31 & V_65 )
F_26 ( V_9 -> V_46 . V_62 , L_4 ) ;
if ( V_31 & V_66 )
F_26 ( V_9 -> V_46 . V_62 , L_5 ) ;
if ( V_31 & V_67 )
F_26 ( V_9 -> V_46 . V_62 , L_6 ) ;
if ( V_31 & V_68 )
F_26 ( V_9 -> V_46 . V_62 , L_7 ) ;
if ( V_31 & V_69 )
F_26 ( V_9 -> V_46 . V_62 , L_8 ) ;
if ( V_31 & V_70 )
F_26 ( V_9 -> V_46 . V_62 , L_9 ) ;
if ( V_31 & V_71 )
F_26 ( V_9 -> V_46 . V_62 , L_10 ) ;
if ( V_31 & V_72 )
F_26 ( V_9 -> V_46 . V_62 , L_11 ) ;
}
F_19 ( V_9 ) ;
}
static T_4 F_28 ( struct V_55 * V_73 )
{
struct V_1 * V_6 = F_1 ( V_73 -> V_4 ) ;
struct V_10 * V_13 ;
unsigned long V_57 ;
T_4 V_60 ;
V_13 = F_2 ( V_73 , struct V_10 , V_56 ) ;
F_21 ( & V_6 -> V_35 , V_57 ) ;
F_7 ( & V_13 -> V_16 , & V_6 -> V_15 ) ;
if ( F_5 ( & V_6 -> V_18 ) )
F_4 ( V_6 ) ;
V_60 = F_29 ( V_73 ) ;
F_22 ( & V_6 -> V_35 , V_57 ) ;
return V_60 ;
}
static int F_30 ( struct V_2 * V_4 )
{
struct V_5 * V_9 = F_3 ( V_4 ) ;
struct V_1 * V_6 = F_1 ( V_4 ) ;
struct V_10 * V_13 ;
struct V_25 * V_19 ;
T_5 V_21 ;
unsigned long V_57 ;
F_20 ( V_74 ) ;
int V_59 ;
V_19 = F_31 ( V_9 -> V_46 . V_62 ,
V_75 * sizeof( struct V_25 ) ,
& V_21 , V_76 ) ;
if ( ! V_19 )
return - V_77 ;
for ( V_59 = 0 ; V_59 < V_75 ; V_59 ++ ) {
V_13 = F_32 ( sizeof( struct V_10 ) , V_76 ) ;
if ( ! V_13 ) {
F_33 ( V_9 -> V_46 . V_62 ,
L_12 , V_59 ) ;
break;
}
F_34 ( & V_13 -> V_56 , V_4 ) ;
V_13 -> V_56 . V_57 = V_78 ;
V_13 -> V_56 . V_79 = F_28 ;
V_13 -> V_19 = & V_19 [ V_59 ] ;
V_13 -> V_21 = V_21 + ( V_59 * sizeof( struct V_25 ) ) ;
F_35 ( & V_13 -> V_16 , & V_74 ) ;
}
if ( V_59 == 0 ) {
F_36 ( V_9 -> V_46 . V_62 ,
V_75 * sizeof( struct V_25 ) ,
V_19 , V_21 ) ;
return - V_77 ;
}
F_21 ( & V_6 -> V_35 , V_57 ) ;
V_6 -> V_19 = V_19 ;
V_6 -> V_21 = V_21 ;
F_14 ( & V_74 , & V_6 -> free ) ;
F_22 ( & V_6 -> V_35 , V_57 ) ;
F_10 ( & V_9 -> V_27 -> V_80 , V_4 -> V_8 ) ;
return 0 ;
}
static void F_37 ( struct V_2 * V_4 )
{
struct V_5 * V_9 = F_3 ( V_4 ) ;
struct V_1 * V_6 = F_1 ( V_4 ) ;
struct V_10 * V_13 , * V_81 ;
struct V_25 * V_19 ;
T_5 V_21 ;
unsigned long V_57 ;
F_20 ( V_74 ) ;
F_21 ( & V_6 -> V_35 , V_57 ) ;
F_38 ( ! F_5 ( & V_6 -> V_82 ) ) ;
F_38 ( ! F_5 ( & V_6 -> V_15 ) ) ;
F_38 ( ! F_5 ( & V_6 -> V_18 ) ) ;
F_38 ( ! F_5 ( & V_6 -> V_39 ) ) ;
F_14 ( & V_6 -> free , & V_74 ) ;
V_19 = V_6 -> V_19 ;
V_21 = V_6 -> V_21 ;
F_22 ( & V_6 -> V_35 , V_57 ) ;
F_36 ( V_9 -> V_46 . V_62 ,
V_75 * sizeof( struct V_25 ) ,
V_19 , V_21 ) ;
F_39 (mdesc, tmp, &descs, node)
F_40 ( V_13 ) ;
F_10 ( & V_9 -> V_27 -> V_83 , V_4 -> V_8 ) ;
}
static void F_41 ( struct V_2 * V_4 )
{
}
static enum V_84
F_42 ( struct V_2 * V_4 , T_4 V_60 ,
struct V_85 * V_86 )
{
return F_43 ( V_4 , V_60 , V_86 ) ;
}
static struct V_55 *
F_44 ( struct V_2 * V_4 , T_5 V_87 , T_5 V_88 ,
T_6 V_89 , unsigned long V_57 )
{
struct V_5 * V_9 = F_3 ( V_4 ) ;
struct V_1 * V_6 = F_1 ( V_4 ) ;
struct V_10 * V_13 = NULL ;
struct V_25 * V_19 ;
unsigned long V_90 ;
F_21 ( & V_6 -> V_35 , V_90 ) ;
if ( ! F_5 ( & V_6 -> free ) ) {
V_13 = F_6 ( & V_6 -> free , struct V_10 ,
V_16 ) ;
F_45 ( & V_13 -> V_16 ) ;
}
F_22 ( & V_6 -> V_35 , V_90 ) ;
if ( ! V_13 ) {
F_19 ( V_9 ) ;
return NULL ;
}
V_13 -> error = 0 ;
V_13 -> V_17 = 0 ;
V_19 = V_13 -> V_19 ;
memset ( V_19 , 0 , sizeof( struct V_25 ) ) ;
if ( F_46 ( V_88 | V_87 | V_89 , 32 ) ) {
V_19 -> V_91 = V_92 ;
V_19 -> V_93 = V_92 ;
V_19 -> V_94 = 32 ;
V_19 -> V_95 = 32 ;
} else if ( ! V_9 -> V_26 && F_46 ( V_88 | V_87 | V_89 , 16 ) ) {
V_19 -> V_91 = V_96 ;
V_19 -> V_93 = V_96 ;
V_19 -> V_94 = 16 ;
V_19 -> V_95 = 16 ;
} else if ( F_46 ( V_88 | V_87 | V_89 , 4 ) ) {
V_19 -> V_91 = V_97 ;
V_19 -> V_93 = V_97 ;
V_19 -> V_94 = 4 ;
V_19 -> V_95 = 4 ;
} else if ( F_46 ( V_88 | V_87 | V_89 , 2 ) ) {
V_19 -> V_91 = V_98 ;
V_19 -> V_93 = V_98 ;
V_19 -> V_94 = 2 ;
V_19 -> V_95 = 2 ;
} else {
V_19 -> V_91 = V_99 ;
V_19 -> V_93 = V_99 ;
V_19 -> V_94 = 1 ;
V_19 -> V_95 = 1 ;
}
V_19 -> V_100 = V_88 ;
V_19 -> V_101 = V_87 ;
V_19 -> V_102 = V_89 ;
V_19 -> V_103 = 1 ;
V_19 -> V_104 = 1 ;
F_21 ( & V_6 -> V_35 , V_90 ) ;
F_35 ( & V_13 -> V_16 , & V_6 -> V_82 ) ;
F_22 ( & V_6 -> V_35 , V_90 ) ;
return & V_13 -> V_56 ;
}
inline T_7 F_47 ( T_7 V_105 )
{
T_7 V_106 ;
for ( V_106 = 0 ; V_105 > 1 ; V_105 /= 2 )
V_106 ++ ;
return V_106 ;
}
static struct V_55 *
F_48 ( struct V_2 * V_4 , struct V_107 * V_108 ,
unsigned int V_109 , enum V_110 V_111 ,
unsigned long V_57 , void * V_112 )
{
struct V_5 * V_9 = F_3 ( V_4 ) ;
struct V_1 * V_6 = F_1 ( V_4 ) ;
struct V_10 * V_13 = NULL ;
T_5 V_113 ;
T_1 V_114 ;
struct V_25 * V_19 ;
unsigned long V_90 ;
struct V_107 * V_115 ;
T_6 V_89 ;
int V_116 , V_59 ;
if ( V_109 != 1 )
return NULL ;
if ( ! F_49 ( V_111 ) )
return NULL ;
F_50 (sgl, sg, sg_len, i) {
F_21 ( & V_6 -> V_35 , V_90 ) ;
V_13 = F_6 ( & V_6 -> free ,
struct V_10 , V_16 ) ;
if ( ! V_13 ) {
F_22 ( & V_6 -> V_35 , V_90 ) ;
F_19 ( V_9 ) ;
return NULL ;
}
F_45 ( & V_13 -> V_16 ) ;
if ( V_111 == V_117 ) {
V_113 = V_6 -> V_118 ;
V_114 = V_6 -> V_119 ;
} else {
V_113 = V_6 -> V_120 ;
V_114 = V_6 -> V_121 ;
}
F_22 ( & V_6 -> V_35 , V_90 ) ;
if ( V_113 == 0 || V_114 == 0 )
goto V_122;
V_13 -> error = 0 ;
V_13 -> V_17 = 1 ;
V_19 = V_13 -> V_19 ;
memset ( V_19 , 0 , sizeof( struct V_25 ) ) ;
if ( V_111 == V_117 ) {
V_19 -> V_100 = V_113 ;
V_19 -> V_101 = F_51 ( V_115 ) ;
if ( ! F_46 ( F_51 ( V_115 ) , V_6 -> V_123 ) )
goto V_122;
V_19 -> V_94 = 0 ;
V_19 -> V_95 = V_6 -> V_123 ;
} else {
V_19 -> V_100 = F_51 ( V_115 ) ;
V_19 -> V_101 = V_113 ;
if ( ! F_46 ( F_51 ( V_115 ) , V_6 -> V_124 ) )
goto V_122;
V_19 -> V_94 = V_6 -> V_124 ;
V_19 -> V_95 = 0 ;
}
V_19 -> V_91 = F_47 ( V_6 -> V_124 ) ;
V_19 -> V_93 = F_47 ( V_6 -> V_123 ) ;
if ( V_9 -> V_26 ) {
V_19 -> V_102 = F_52 ( V_115 ) ;
if ( ! F_46 ( V_19 -> V_102 , V_6 -> V_124 ) )
goto V_122;
V_19 -> V_103 = 1 ;
V_19 -> V_104 = 1 ;
} else {
V_89 = F_52 ( V_115 ) ;
V_19 -> V_102 = V_114 * V_19 -> V_91 ;
if ( ! F_46 ( V_89 , V_19 -> V_102 ) )
goto V_122;
V_116 = V_89 / V_19 -> V_102 ;
if ( V_116 >= 1 << 15 ) {
goto V_122;
}
V_19 -> V_103 = V_116 & 0x1ff ;
V_19 -> V_125 = V_116 >> 9 ;
V_19 -> V_104 = V_19 -> V_103 ;
V_19 -> V_126 = V_19 -> V_125 ;
}
V_19 -> V_22 = 0 ;
V_19 -> V_127 = 1 ;
F_21 ( & V_6 -> V_35 , V_90 ) ;
F_35 ( & V_13 -> V_16 , & V_6 -> V_82 ) ;
F_22 ( & V_6 -> V_35 , V_90 ) ;
}
return & V_13 -> V_56 ;
V_122:
F_21 ( & V_6 -> V_35 , V_90 ) ;
F_35 ( & V_13 -> V_16 , & V_6 -> free ) ;
F_22 ( & V_6 -> V_35 , V_90 ) ;
return NULL ;
}
inline bool F_53 ( T_7 V_105 , bool V_26 )
{
switch ( V_105 ) {
case 16 :
if ( V_26 )
return false ;
case 1 :
case 2 :
case 4 :
case 32 :
break;
default:
return false ;
}
return true ;
}
static int F_54 ( struct V_2 * V_4 ,
struct V_128 * V_129 )
{
struct V_1 * V_6 = F_1 ( V_4 ) ;
struct V_5 * V_9 = F_3 ( & V_6 -> V_4 ) ;
unsigned long V_57 ;
if ( ! F_46 ( V_129 -> V_130 , V_129 -> V_131 ) ||
! F_46 ( V_129 -> V_132 , V_129 -> V_133 ) ) {
return - V_134 ;
}
if ( ! F_53 ( V_129 -> V_131 , V_9 -> V_26 ) ||
! F_53 ( V_129 -> V_133 , V_9 -> V_26 ) )
return - V_134 ;
F_21 ( & V_6 -> V_35 , V_57 ) ;
V_6 -> V_118 = V_129 -> V_130 ;
V_6 -> V_119 = V_129 -> V_135 ;
V_6 -> V_124 = V_129 -> V_131 ;
V_6 -> V_120 = V_129 -> V_132 ;
V_6 -> V_121 = V_129 -> V_136 ;
V_6 -> V_123 = V_129 -> V_133 ;
if ( V_6 -> V_119 == 0 )
V_6 -> V_119 = 1 ;
if ( V_6 -> V_121 == 0 )
V_6 -> V_121 = 1 ;
F_22 ( & V_6 -> V_35 , V_57 ) ;
return 0 ;
}
static int F_55 ( struct V_2 * V_4 )
{
struct V_1 * V_6 = F_1 ( V_4 ) ;
struct V_5 * V_9 = F_3 ( V_4 ) ;
unsigned long V_57 ;
F_21 ( & V_6 -> V_35 , V_57 ) ;
F_10 ( & V_9 -> V_27 -> V_137 , V_4 -> V_8 ) ;
F_14 ( & V_6 -> V_82 , & V_6 -> free ) ;
F_14 ( & V_6 -> V_15 , & V_6 -> free ) ;
F_14 ( & V_6 -> V_18 , & V_6 -> free ) ;
F_22 ( & V_6 -> V_35 , V_57 ) ;
return 0 ;
}
static int F_56 ( struct V_138 * V_139 )
{
struct V_140 * V_141 = V_139 -> V_62 . V_142 ;
struct V_143 * V_62 = & V_139 -> V_62 ;
struct V_144 * V_46 ;
struct V_5 * V_9 ;
struct V_1 * V_6 ;
struct V_145 V_106 ;
T_8 V_146 , V_147 ;
int V_148 , V_59 ;
T_7 V_47 ;
V_9 = F_57 ( V_62 , sizeof( struct V_5 ) , V_76 ) ;
if ( ! V_9 ) {
V_148 = - V_77 ;
goto V_149;
}
V_9 -> V_40 = F_58 ( V_141 , 0 ) ;
if ( ! V_9 -> V_40 ) {
F_26 ( V_62 , L_13 ) ;
V_148 = - V_134 ;
goto V_149;
}
if ( F_59 ( V_141 , L_14 ) ) {
V_9 -> V_26 = 1 ;
V_9 -> V_150 = F_58 ( V_141 , 1 ) ;
if ( ! V_9 -> V_150 ) {
F_26 ( V_62 , L_13 ) ;
V_148 = - V_134 ;
goto V_151;
}
}
V_148 = F_60 ( V_141 , 0 , & V_106 ) ;
if ( V_148 ) {
F_26 ( V_62 , L_15 ) ;
goto V_152;
}
V_146 = V_106 . V_23 ;
V_147 = F_61 ( & V_106 ) ;
if ( ! F_62 ( V_62 , V_146 , V_147 , V_153 ) ) {
F_26 ( V_62 , L_16 ) ;
V_148 = - V_154 ;
goto V_152;
}
V_9 -> V_27 = F_63 ( V_62 , V_146 , V_147 ) ;
if ( ! V_9 -> V_27 ) {
F_26 ( V_62 , L_17 ) ;
V_148 = - V_77 ;
goto V_152;
}
V_9 -> V_19 = (struct V_25 * ) ( ( T_7 * ) ( V_9 -> V_27 )
+ V_155 ) ;
V_148 = F_64 ( V_9 -> V_40 , & F_16 , 0 , V_153 , V_9 ) ;
if ( V_148 ) {
F_26 ( V_62 , L_18 ) ;
V_148 = - V_134 ;
goto V_152;
}
if ( V_9 -> V_26 ) {
V_148 = F_64 ( V_9 -> V_150 , & F_16 , 0 ,
V_153 , V_9 ) ;
if ( V_148 ) {
F_26 ( V_62 , L_19 ) ;
V_148 = - V_134 ;
goto V_156;
}
}
F_65 ( & V_9 -> V_43 ) ;
V_46 = & V_9 -> V_46 ;
V_46 -> V_62 = V_62 ;
V_46 -> V_157 = F_30 ;
V_46 -> V_158 = F_37 ;
V_46 -> V_159 = F_41 ;
V_46 -> V_160 = F_42 ;
V_46 -> V_161 = F_44 ;
V_46 -> V_162 = F_48 ;
V_46 -> V_163 = F_54 ;
V_46 -> V_164 = F_55 ;
F_66 ( & V_46 -> V_7 ) ;
F_67 ( V_165 , V_46 -> V_166 ) ;
F_67 ( V_167 , V_46 -> V_166 ) ;
if ( V_9 -> V_26 )
V_47 = V_168 ;
else
V_47 = V_169 ;
for ( V_59 = 0 ; V_59 < V_47 ; V_59 ++ ) {
V_6 = & V_9 -> V_7 [ V_59 ] ;
V_6 -> V_4 . V_143 = V_46 ;
F_68 ( & V_6 -> V_4 ) ;
F_66 ( & V_6 -> free ) ;
F_66 ( & V_6 -> V_82 ) ;
F_66 ( & V_6 -> V_15 ) ;
F_66 ( & V_6 -> V_18 ) ;
F_66 ( & V_6 -> V_39 ) ;
F_65 ( & V_6 -> V_35 ) ;
F_35 ( & V_6 -> V_4 . V_140 , & V_46 -> V_7 ) ;
}
F_69 ( & V_9 -> V_52 , F_25 , ( unsigned long ) V_9 ) ;
if ( V_9 -> V_26 ) {
F_70 ( & V_9 -> V_27 -> V_170 , V_171 ) ;
F_70 ( & V_9 -> V_27 -> V_172 , V_173 ) ;
F_70 ( & V_9 -> V_27 -> V_174 , 0 ) ;
F_70 ( & V_9 -> V_27 -> V_50 , 0xFFFF ) ;
F_70 ( & V_9 -> V_27 -> V_51 , 0xFFFF ) ;
} else {
F_70 ( & V_9 -> V_27 -> V_170 , V_175 |
V_176 |
V_171 ) ;
F_70 ( & V_9 -> V_27 -> V_177 , 0 ) ;
F_70 ( & V_9 -> V_27 -> V_178 , 0 ) ;
F_70 ( & V_9 -> V_27 -> V_179 , 0 ) ;
F_70 ( & V_9 -> V_27 -> V_174 , 0 ) ;
F_70 ( & V_9 -> V_27 -> V_48 , 0xFFFFFFFF ) ;
F_70 ( & V_9 -> V_27 -> V_50 , 0xFFFFFFFF ) ;
F_70 ( & V_9 -> V_27 -> V_49 , 0xFFFFFFFF ) ;
F_70 ( & V_9 -> V_27 -> V_51 , 0xFFFFFFFF ) ;
F_70 ( & V_9 -> V_27 -> V_180 , 0 ) ;
F_70 ( & V_9 -> V_27 -> V_181 , 0 ) ;
}
F_71 ( V_62 , V_9 ) ;
V_148 = F_72 ( V_46 ) ;
if ( V_148 )
goto V_182;
if ( V_62 -> V_142 ) {
V_148 = F_73 ( V_62 -> V_142 ,
V_183 , V_9 ) ;
if ( V_148 )
F_74 ( V_62 , L_20 ) ;
}
return 0 ;
V_182:
if ( V_9 -> V_26 )
F_75 ( V_9 -> V_150 , V_9 ) ;
V_156:
F_75 ( V_9 -> V_40 , V_9 ) ;
V_152:
if ( V_9 -> V_26 )
F_76 ( V_9 -> V_150 ) ;
V_151:
F_76 ( V_9 -> V_40 ) ;
V_149:
return V_148 ;
}
static int F_77 ( struct V_138 * V_139 )
{
struct V_143 * V_62 = & V_139 -> V_62 ;
struct V_5 * V_9 = F_78 ( V_62 ) ;
if ( V_62 -> V_142 )
F_79 ( V_62 -> V_142 ) ;
F_80 ( & V_9 -> V_46 ) ;
if ( V_9 -> V_26 ) {
F_75 ( V_9 -> V_150 , V_9 ) ;
F_76 ( V_9 -> V_150 ) ;
}
F_75 ( V_9 -> V_40 , V_9 ) ;
F_76 ( V_9 -> V_40 ) ;
F_81 ( & V_9 -> V_52 ) ;
return 0 ;
}
