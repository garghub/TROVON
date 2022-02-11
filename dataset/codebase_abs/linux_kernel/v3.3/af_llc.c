static inline T_1 F_1 ( int V_1 )
{
return V_2 [ V_1 ] ++ ;
}
static inline T_2 F_2 ( T_1 V_3 )
{
return V_3 == V_4 ?
F_3 ( V_5 ) : F_3 ( V_6 ) ;
}
static inline T_3 F_4 ( struct V_7 * V_8 )
{
return ! memcmp ( V_8 , & V_9 , sizeof( * V_8 ) ) ;
}
static inline T_3 F_5 ( struct V_10 * V_11 , struct V_7 * V_8 )
{
T_3 V_12 = V_13 ;
if ( V_8 -> V_14 || V_8 -> V_15 )
V_12 = V_13 ;
else if ( V_11 -> V_16 == V_17 )
V_12 = V_18 ;
return V_12 ;
}
static int F_6 ( struct V_10 * V_11 , struct V_19 * V_20 , int V_21 )
{
struct V_22 * V_23 = F_7 ( V_11 ) ;
int V_12 = 0 ;
if ( F_8 ( F_9 ( V_23 -> V_24 ) ||
V_23 -> V_25 ||
V_23 -> V_26 ) ) {
long V_27 = F_10 ( V_11 , V_21 ) ;
V_12 = F_11 ( V_11 , V_27 ) ;
}
if ( F_8 ( ! V_12 ) )
V_12 = F_12 ( V_11 , V_20 ) ;
return V_12 ;
}
static void F_13 ( struct V_28 * V_10 , struct V_10 * V_11 )
{
F_14 ( V_11 , V_10 ) ;
V_11 -> V_16 = V_10 -> type ;
V_10 -> V_29 = & V_30 ;
}
static int F_15 ( struct V_31 * V_31 , struct V_28 * V_10 , int V_32 ,
int V_33 )
{
struct V_10 * V_11 ;
int V_12 = - V_34 ;
if ( ! F_16 ( V_35 ) )
return - V_36 ;
if ( ! F_17 ( V_31 , & V_37 ) )
return - V_38 ;
if ( F_18 ( V_10 -> type == V_39 || V_10 -> type == V_17 ) ) {
V_12 = - V_40 ;
V_11 = F_19 ( V_31 , V_41 , V_42 , & V_43 ) ;
if ( V_11 ) {
V_12 = 0 ;
F_13 ( V_10 , V_11 ) ;
}
}
return V_12 ;
}
static int F_20 ( struct V_28 * V_10 )
{
struct V_10 * V_11 = V_10 -> V_11 ;
struct V_22 * V_23 ;
if ( F_8 ( V_11 == NULL ) )
goto V_44;
F_21 ( V_11 ) ;
F_22 ( V_11 ) ;
V_23 = F_7 ( V_11 ) ;
F_23 ( L_1 , V_45 ,
V_23 -> V_46 . V_47 , V_23 -> V_48 . V_47 ) ;
if ( ! F_24 ( V_11 ) )
F_25 ( V_11 , V_11 -> V_49 ) ;
if ( ! F_26 ( V_11 , V_50 ) )
F_27 ( V_23 -> V_1 , V_11 ) ;
F_28 ( V_11 ) ;
if ( V_23 -> V_51 )
F_29 ( V_23 -> V_51 ) ;
F_30 ( V_11 ) ;
F_31 ( V_11 ) ;
V_44:
return 0 ;
}
static int F_32 ( void )
{
struct V_52 * V_1 ;
int V_53 , V_54 = 0 ;
while ( V_54 < V_55 ) {
for ( V_53 = V_56 ;
V_53 < V_57 ; V_53 += 2 ) {
V_1 = F_33 ( V_53 ) ;
if ( ! V_1 ) {
V_56 = V_53 + 2 ;
goto V_44;
}
F_34 ( V_1 ) ;
}
V_56 = V_58 ;
V_54 ++ ;
}
V_53 = 0 ;
V_44:
return V_53 ;
}
static int F_35 ( struct V_28 * V_10 , struct V_7 * V_8 )
{
struct V_10 * V_11 = V_10 -> V_11 ;
struct V_22 * V_23 = F_7 ( V_11 ) ;
struct V_52 * V_1 ;
int V_12 = - V_59 ;
if ( ! F_26 ( V_11 , V_50 ) )
goto V_44;
V_12 = - V_60 ;
if ( V_11 -> V_61 ) {
V_23 -> V_51 = F_36 ( & V_37 , V_11 -> V_61 ) ;
if ( V_23 -> V_51 && V_8 -> V_62 != V_23 -> V_51 -> type ) {
F_29 ( V_23 -> V_51 ) ;
V_23 -> V_51 = NULL ;
}
} else
V_23 -> V_51 = F_37 ( & V_37 , V_8 -> V_62 ) ;
if ( ! V_23 -> V_51 )
goto V_44;
V_12 = - V_63 ;
V_23 -> V_46 . V_47 = F_32 () ;
if ( ! V_23 -> V_46 . V_47 )
goto V_44;
V_12 = - V_64 ;
V_1 = F_38 ( V_23 -> V_46 . V_47 , NULL ) ;
if ( ! V_1 )
goto V_44;
memcpy ( V_23 -> V_46 . V_65 , V_23 -> V_51 -> V_66 , V_67 ) ;
memcpy ( & V_23 -> V_8 , V_8 , sizeof( V_23 -> V_8 ) ) ;
F_39 ( V_1 , V_11 ) ;
F_40 ( V_11 , V_50 ) ;
V_12 = 0 ;
V_44:
return V_12 ;
}
static int F_41 ( struct V_28 * V_10 , struct V_68 * V_69 , int V_70 )
{
struct V_7 * V_8 = (struct V_7 * ) V_69 ;
struct V_10 * V_11 = V_10 -> V_11 ;
struct V_22 * V_23 = F_7 ( V_11 ) ;
struct V_52 * V_1 ;
int V_12 = - V_59 ;
F_23 ( L_2 , V_45 , V_8 -> V_71 ) ;
if ( F_8 ( ! F_26 ( V_11 , V_50 ) || V_70 != sizeof( * V_8 ) ) )
goto V_44;
V_12 = - V_38 ;
if ( F_8 ( V_8 -> V_72 != V_73 ) )
goto V_44;
V_12 = - V_60 ;
F_42 () ;
if ( V_11 -> V_61 ) {
V_23 -> V_51 = F_43 ( & V_37 , V_11 -> V_61 ) ;
if ( V_23 -> V_51 ) {
if ( ! V_8 -> V_62 )
V_8 -> V_62 = V_23 -> V_51 -> type ;
if ( F_44 ( V_8 -> V_74 ) )
memcpy ( V_8 -> V_74 , V_23 -> V_51 -> V_66 ,
V_67 ) ;
if ( V_8 -> V_62 != V_23 -> V_51 -> type ||
! F_45 ( V_8 -> V_74 ,
V_23 -> V_51 -> V_66 ) ) {
V_12 = - V_59 ;
V_23 -> V_51 = NULL ;
}
}
} else
V_23 -> V_51 = F_46 ( & V_37 , V_8 -> V_62 ,
V_8 -> V_74 ) ;
if ( V_23 -> V_51 )
F_47 ( V_23 -> V_51 ) ;
F_48 () ;
if ( ! V_23 -> V_51 )
goto V_44;
if ( ! V_8 -> V_71 ) {
V_12 = - V_63 ;
V_8 -> V_71 = F_32 () ;
if ( ! V_8 -> V_71 )
goto V_44;
}
V_1 = F_33 ( V_8 -> V_71 ) ;
if ( ! V_1 ) {
V_1 = F_38 ( V_8 -> V_71 , NULL ) ;
V_12 = - V_64 ;
if ( ! V_1 )
goto V_44;
} else {
struct V_75 V_46 , V_48 ;
struct V_10 * V_76 ;
memset ( & V_46 , 0 , sizeof( V_46 ) ) ;
memset ( & V_48 , 0 , sizeof( V_48 ) ) ;
memcpy ( V_46 . V_65 , V_8 -> V_74 , V_67 ) ;
V_46 . V_47 = V_8 -> V_71 ;
V_12 = - V_77 ;
V_76 = F_49 ( V_1 , & V_48 , & V_46 ) ;
if ( V_76 ) {
F_30 ( V_76 ) ;
goto V_78;
}
}
V_23 -> V_46 . V_47 = V_8 -> V_71 ;
memcpy ( V_23 -> V_46 . V_65 , V_8 -> V_74 , V_67 ) ;
memcpy ( & V_23 -> V_8 , V_8 , sizeof( V_23 -> V_8 ) ) ;
F_39 ( V_1 , V_11 ) ;
F_40 ( V_11 , V_50 ) ;
V_12 = 0 ;
V_78:
F_34 ( V_1 ) ;
V_44:
return V_12 ;
}
static int F_50 ( struct V_28 * V_10 , int V_79 )
{
struct V_10 * V_11 = V_10 -> V_11 ;
int V_12 = - V_80 ;
F_22 ( V_11 ) ;
if ( F_8 ( V_11 -> V_81 != V_82 ) )
goto V_44;
V_12 = - V_59 ;
if ( V_79 != 2 )
goto V_44;
V_12 = F_24 ( V_11 ) ;
if ( ! V_12 )
V_12 = F_25 ( V_11 , V_11 -> V_49 ) ;
V_11 -> V_83 ( V_11 ) ;
V_44:
F_28 ( V_11 ) ;
return V_12 ;
}
static int F_51 ( struct V_28 * V_10 , struct V_68 * V_69 ,
int V_70 , int V_84 )
{
struct V_10 * V_11 = V_10 -> V_11 ;
struct V_22 * V_23 = F_7 ( V_11 ) ;
struct V_7 * V_8 = (struct V_7 * ) V_69 ;
int V_12 = - V_59 ;
F_22 ( V_11 ) ;
if ( F_8 ( V_70 != sizeof( * V_8 ) ) )
goto V_44;
V_12 = - V_38 ;
if ( F_8 ( V_8 -> V_72 != V_73 ) )
goto V_44;
if ( F_8 ( V_11 -> V_16 != V_17 ) )
goto V_44;
V_12 = - V_85 ;
if ( F_8 ( V_10 -> V_24 == V_86 ) )
goto V_44;
if ( F_26 ( V_11 , V_50 ) ) {
V_12 = F_35 ( V_10 , V_8 ) ;
if ( V_12 )
goto V_44;
}
V_23 -> V_48 . V_47 = V_8 -> V_71 ;
memcpy ( V_23 -> V_48 . V_65 , V_8 -> V_74 , V_67 ) ;
V_10 -> V_24 = V_86 ;
V_11 -> V_81 = V_87 ;
V_23 -> V_88 = F_1 ( V_23 -> V_1 -> V_46 . V_47 ) ;
V_12 = F_52 ( V_11 , V_23 -> V_51 -> V_66 ,
V_8 -> V_74 , V_8 -> V_71 ) ;
if ( V_12 ) {
F_23 ( L_3 , V_45 ) ;
V_10 -> V_24 = V_89 ;
V_11 -> V_81 = V_90 ;
goto V_44;
}
if ( V_11 -> V_81 == V_87 ) {
const long V_91 = F_10 ( V_11 , V_84 & V_92 ) ;
if ( ! V_91 || ! F_53 ( V_11 , V_91 ) )
goto V_44;
V_12 = F_54 ( V_91 ) ;
if ( F_55 ( V_93 ) )
goto V_44;
}
if ( V_11 -> V_81 == V_90 )
goto V_94;
V_10 -> V_24 = V_95 ;
V_12 = 0 ;
V_44:
F_28 ( V_11 ) ;
return V_12 ;
V_94:
V_12 = V_94 ( V_11 ) ? : - V_96 ;
V_10 -> V_24 = V_89 ;
goto V_44;
}
static int F_56 ( struct V_28 * V_10 , int V_97 )
{
struct V_10 * V_11 = V_10 -> V_11 ;
int V_12 = - V_59 ;
F_22 ( V_11 ) ;
if ( F_8 ( V_10 -> V_24 != V_89 ) )
goto V_44;
V_12 = - V_98 ;
if ( F_8 ( V_11 -> V_16 != V_17 ) )
goto V_44;
V_12 = - V_99 ;
if ( F_26 ( V_11 , V_50 ) )
goto V_44;
V_12 = 0 ;
if ( ! ( unsigned ) V_97 )
V_97 = 1 ;
V_11 -> V_100 = V_97 ;
if ( V_11 -> V_81 != V_101 ) {
V_11 -> V_102 = 0 ;
V_11 -> V_81 = V_101 ;
}
V_11 -> V_103 -> V_84 |= V_104 ;
V_44:
F_28 ( V_11 ) ;
return V_12 ;
}
static int F_25 ( struct V_10 * V_11 , long V_27 )
{
F_57 ( V_105 ) ;
int V_12 = 0 ;
while ( 1 ) {
F_58 ( F_59 ( V_11 ) , & V_105 , V_106 ) ;
if ( F_60 ( V_11 , & V_27 , V_11 -> V_81 == V_90 ) )
break;
V_12 = - V_107 ;
if ( F_55 ( V_93 ) )
break;
V_12 = - V_99 ;
if ( ! V_27 )
break;
V_12 = 0 ;
}
F_61 ( F_59 ( V_11 ) , & V_105 ) ;
return V_12 ;
}
static int F_53 ( struct V_10 * V_11 , long V_27 )
{
F_57 ( V_105 ) ;
while ( 1 ) {
F_58 ( F_59 ( V_11 ) , & V_105 , V_106 ) ;
if ( F_60 ( V_11 , & V_27 , V_11 -> V_81 != V_87 ) )
break;
if ( F_55 ( V_93 ) || ! V_27 )
break;
}
F_61 ( F_59 ( V_11 ) , & V_105 ) ;
return V_27 ;
}
static int F_11 ( struct V_10 * V_11 , long V_27 )
{
F_57 ( V_105 ) ;
struct V_22 * V_23 = F_7 ( V_11 ) ;
int V_12 ;
while ( 1 ) {
F_58 ( F_59 ( V_11 ) , & V_105 , V_106 ) ;
V_12 = 0 ;
if ( F_60 ( V_11 , & V_27 ,
( V_11 -> V_108 & V_109 ) ||
( ! F_9 ( V_23 -> V_24 ) &&
! V_23 -> V_25 &&
! V_23 -> V_26 ) ) )
break;
V_12 = - V_107 ;
if ( F_55 ( V_93 ) )
break;
V_12 = - V_99 ;
if ( ! V_27 )
break;
}
F_61 ( F_59 ( V_11 ) , & V_105 ) ;
return V_12 ;
}
static int F_62 ( struct V_10 * V_11 , long V_91 )
{
int V_12 ;
while ( 1 ) {
V_12 = V_94 ( V_11 ) ;
if ( V_12 )
break;
V_12 = 0 ;
if ( V_11 -> V_108 & V_109 )
break;
V_12 = - V_99 ;
if ( ! V_91 )
break;
V_12 = F_54 ( V_91 ) ;
if ( F_55 ( V_93 ) )
break;
V_12 = 0 ;
if ( F_63 ( V_11 , & V_91 ) )
break;
}
return V_12 ;
}
static void F_64 ( struct V_110 * V_111 , struct V_19 * V_20 )
{
struct V_22 * V_23 = F_7 ( V_20 -> V_11 ) ;
if ( V_23 -> V_112 & V_113 ) {
struct V_114 V_115 ;
V_115 . V_116 = F_7 ( V_20 -> V_11 ) -> V_51 -> V_117 ;
F_65 ( V_20 , & V_115 . V_118 ) ;
F_66 ( V_20 , V_115 . V_119 ) ;
F_67 ( V_111 , V_120 , V_121 , sizeof( V_115 ) , & V_115 ) ;
}
}
static int F_68 ( struct V_28 * V_10 , struct V_28 * V_122 , int V_84 )
{
struct V_10 * V_11 = V_10 -> V_11 , * V_123 ;
struct V_22 * V_23 , * V_124 ;
struct V_19 * V_20 ;
int V_12 = - V_98 ;
F_23 ( L_4 , V_45 ,
F_7 ( V_11 ) -> V_46 . V_47 ) ;
F_22 ( V_11 ) ;
if ( F_8 ( V_11 -> V_16 != V_17 ) )
goto V_44;
V_12 = - V_59 ;
if ( F_8 ( V_10 -> V_24 != V_89 ||
V_11 -> V_81 != V_101 ) )
goto V_44;
if ( F_69 ( & V_11 -> V_125 ) ) {
V_12 = F_62 ( V_11 , V_11 -> V_49 ) ;
if ( V_12 )
goto V_44;
}
F_23 ( L_5 , V_45 ,
F_7 ( V_11 ) -> V_46 . V_47 ) ;
V_20 = F_70 ( & V_11 -> V_125 ) ;
V_12 = - V_59 ;
if ( ! V_20 -> V_11 )
goto V_126;
V_12 = 0 ;
V_123 = V_20 -> V_11 ;
F_13 ( V_122 , V_123 ) ;
F_40 ( V_123 , V_50 ) ;
V_123 -> V_81 = V_82 ;
V_122 -> V_24 = V_95 ;
V_23 = F_7 ( V_11 ) ;
V_124 = F_7 ( V_123 ) ;
memcpy ( & V_124 -> V_8 , & V_23 -> V_8 , sizeof( V_124 -> V_8 ) ) ;
V_124 -> V_88 = F_1 ( V_124 -> V_46 . V_47 ) ;
V_11 -> V_81 = V_101 ;
V_11 -> V_102 -- ;
F_23 ( L_6 , V_45 ,
F_7 ( V_11 ) -> V_8 . V_71 , V_124 -> V_48 . V_47 ) ;
V_126:
F_71 ( V_20 ) ;
V_44:
F_28 ( V_11 ) ;
return V_12 ;
}
static int F_72 ( struct V_127 * V_128 , struct V_28 * V_10 ,
struct V_110 * V_111 , T_4 V_129 , int V_84 )
{
struct V_7 * V_69 = (struct V_7 * ) V_111 -> V_130 ;
const int V_131 = V_84 & V_132 ;
struct V_19 * V_20 = NULL ;
struct V_10 * V_11 = V_10 -> V_11 ;
struct V_22 * V_23 = F_7 ( V_11 ) ;
unsigned long V_133 ;
T_4 V_134 = 0 ;
T_5 V_135 = 0 ;
T_5 * V_136 ;
unsigned long V_137 ;
int V_138 ;
long V_91 ;
F_22 ( V_11 ) ;
V_134 = - V_80 ;
if ( F_8 ( V_11 -> V_16 == V_17 && V_11 -> V_81 == V_101 ) )
goto V_44;
V_91 = F_73 ( V_11 , V_131 ) ;
V_136 = & V_23 -> V_139 ;
if ( V_84 & V_140 ) {
V_135 = V_23 -> V_139 ;
V_136 = & V_135 ;
}
V_138 = F_74 ( V_11 , V_84 & V_141 , V_129 ) ;
V_134 = 0 ;
do {
T_5 V_142 ;
if ( F_55 ( V_93 ) ) {
if ( V_134 )
break;
V_134 = V_91 ? F_54 ( V_91 ) : - V_99 ;
break;
}
V_20 = F_75 ( & V_11 -> V_125 ) ;
if ( V_20 ) {
V_142 = * V_136 ;
goto V_143;
}
if ( V_134 >= V_138 && ! V_11 -> V_144 . V_145 )
break;
if ( V_134 ) {
if ( V_11 -> V_146 ||
V_11 -> V_81 == V_90 ||
( V_11 -> V_108 & V_109 ) ||
! V_91 ||
( V_84 & V_140 ) )
break;
} else {
if ( F_26 ( V_11 , V_147 ) )
break;
if ( V_11 -> V_146 ) {
V_134 = V_94 ( V_11 ) ;
break;
}
if ( V_11 -> V_108 & V_109 )
break;
if ( V_11 -> V_16 == V_17 && V_11 -> V_81 == V_90 ) {
if ( ! F_26 ( V_11 , V_147 ) ) {
V_134 = - V_80 ;
break;
}
break;
}
if ( ! V_91 ) {
V_134 = - V_99 ;
break;
}
}
if ( V_134 >= V_138 ) {
F_28 ( V_11 ) ;
F_22 ( V_11 ) ;
} else
F_63 ( V_11 , & V_91 ) ;
if ( ( V_84 & V_140 ) && V_135 != V_23 -> V_139 ) {
if ( F_76 () )
F_77 ( V_148 L_7
L_8 ,
V_93 -> V_149 , F_78 ( V_93 ) ) ;
V_135 = V_23 -> V_139 ;
}
continue;
V_143:
V_137 = V_20 -> V_129 - V_142 ;
if ( V_129 < V_137 )
V_137 = V_129 ;
if ( ! ( V_84 & V_150 ) ) {
int V_12 = F_79 ( V_20 , V_142 ,
V_111 -> V_151 , V_137 ) ;
if ( V_12 ) {
if ( ! V_134 )
V_134 = - V_152 ;
break;
}
}
* V_136 += V_137 ;
V_134 += V_137 ;
V_129 -= V_137 ;
if ( V_11 -> V_16 != V_17 )
goto V_153;
if ( ! ( V_84 & V_140 ) ) {
F_80 ( & V_11 -> V_125 . V_154 , V_133 ) ;
F_81 ( V_11 , V_20 , 0 ) ;
F_82 ( & V_11 -> V_125 . V_154 , V_133 ) ;
* V_136 = 0 ;
}
if ( V_137 + V_142 < V_20 -> V_129 )
continue;
} while ( V_129 > 0 );
V_44:
F_28 ( V_11 ) ;
return V_134 ;
V_153:
if ( V_69 != NULL && V_20 != NULL ) {
memcpy ( V_69 , F_83 ( V_20 ) , sizeof( * V_69 ) ) ;
V_111 -> V_155 = sizeof( * V_69 ) ;
}
if ( F_7 ( V_11 ) -> V_112 )
F_64 ( V_111 , V_20 ) ;
if ( ! ( V_84 & V_140 ) ) {
F_80 ( & V_11 -> V_125 . V_154 , V_133 ) ;
F_81 ( V_11 , V_20 , 0 ) ;
F_82 ( & V_11 -> V_125 . V_154 , V_133 ) ;
* V_136 = 0 ;
}
goto V_44;
}
static int F_84 ( struct V_127 * V_128 , struct V_28 * V_10 ,
struct V_110 * V_111 , T_4 V_129 )
{
struct V_10 * V_11 = V_10 -> V_11 ;
struct V_22 * V_23 = F_7 ( V_11 ) ;
struct V_7 * V_8 = (struct V_7 * ) V_111 -> V_130 ;
int V_84 = V_111 -> V_156 ;
int V_21 = V_84 & V_132 ;
struct V_19 * V_20 ;
T_4 V_157 = 0 ;
int V_12 = - V_59 , V_134 = 0 , V_158 ;
F_23 ( L_9 , V_45 ,
V_23 -> V_46 . V_47 , V_23 -> V_48 . V_47 ) ;
F_22 ( V_11 ) ;
if ( V_8 ) {
if ( V_111 -> V_155 < sizeof( * V_8 ) )
goto V_159;
} else {
if ( F_4 ( & V_23 -> V_8 ) )
goto V_159;
V_8 = & V_23 -> V_8 ;
}
if ( F_26 ( V_11 , V_50 ) ) {
V_12 = F_35 ( V_10 , V_8 ) ;
if ( V_12 )
goto V_159;
}
V_158 = V_23 -> V_51 -> V_160 + F_5 ( V_11 , V_8 ) ;
V_157 = V_158 + V_129 ;
if ( V_157 > V_23 -> V_51 -> V_161 )
V_157 = V_23 -> V_51 -> V_161 ;
V_134 = V_157 - V_158 ;
F_28 ( V_11 ) ;
V_20 = F_85 ( V_11 , V_157 , V_21 , & V_12 ) ;
F_22 ( V_11 ) ;
if ( ! V_20 )
goto V_159;
V_20 -> V_51 = V_23 -> V_51 ;
V_20 -> V_32 = F_2 ( V_8 -> V_62 ) ;
F_86 ( V_20 , V_158 ) ;
V_12 = F_87 ( F_88 ( V_20 , V_134 ) , V_111 -> V_151 , V_134 ) ;
if ( V_12 )
goto V_44;
if ( V_11 -> V_16 == V_39 || V_8 -> V_162 ) {
F_89 ( V_23 -> V_1 , V_20 , V_8 -> V_74 ,
V_8 -> V_71 ) ;
goto V_44;
}
if ( V_8 -> V_14 ) {
F_90 ( V_23 -> V_1 , V_20 , V_8 -> V_74 ,
V_8 -> V_71 ) ;
goto V_44;
}
if ( V_8 -> V_15 ) {
F_91 ( V_23 -> V_1 , V_20 , V_8 -> V_74 ,
V_8 -> V_71 ) ;
goto V_44;
}
V_12 = - V_163 ;
if ( ! ( V_11 -> V_16 == V_17 && ! V_8 -> V_162 ) )
goto V_44;
V_12 = F_6 ( V_11 , V_20 , V_21 ) ;
V_44:
if ( V_12 ) {
F_71 ( V_20 ) ;
V_159:
F_23 ( L_10 ,
V_45 , V_23 -> V_46 . V_47 , V_23 -> V_48 . V_47 , V_12 ) ;
}
F_28 ( V_11 ) ;
return V_12 ? : V_134 ;
}
static int F_92 ( struct V_28 * V_10 , struct V_68 * V_69 ,
int * V_164 , int V_165 )
{
struct V_7 V_166 ;
struct V_10 * V_11 = V_10 -> V_11 ;
struct V_22 * V_23 = F_7 ( V_11 ) ;
int V_12 = 0 ;
memset ( & V_166 , 0 , sizeof( V_166 ) ) ;
F_22 ( V_11 ) ;
if ( F_26 ( V_11 , V_50 ) )
goto V_44;
* V_164 = sizeof( V_166 ) ;
memset ( V_69 , 0 , * V_164 ) ;
if ( V_165 ) {
V_12 = - V_80 ;
if ( V_11 -> V_81 != V_82 )
goto V_44;
if( V_23 -> V_51 )
V_166 . V_62 = V_23 -> V_51 -> type ;
V_166 . V_71 = V_23 -> V_48 . V_47 ;
memcpy ( & V_166 . V_74 , & V_23 -> V_48 . V_65 , V_67 ) ;
} else {
V_12 = - V_59 ;
if ( ! V_23 -> V_1 )
goto V_44;
V_166 . V_71 = V_23 -> V_1 -> V_46 . V_47 ;
if ( V_23 -> V_51 ) {
V_166 . V_62 = V_23 -> V_51 -> type ;
memcpy ( & V_166 . V_74 , V_23 -> V_51 -> V_66 ,
V_67 ) ;
}
}
V_12 = 0 ;
V_166 . V_72 = V_73 ;
memcpy ( V_69 , & V_166 , sizeof( V_166 ) ) ;
V_44:
F_28 ( V_11 ) ;
return V_12 ;
}
static int F_93 ( struct V_28 * V_10 , unsigned int V_167 ,
unsigned long V_168 )
{
return - V_169 ;
}
static int F_94 ( struct V_28 * V_10 , int V_170 , int V_171 ,
char T_6 * V_172 , unsigned int V_173 )
{
struct V_10 * V_11 = V_10 -> V_11 ;
struct V_22 * V_23 = F_7 ( V_11 ) ;
unsigned int V_174 ;
int V_12 = - V_59 ;
F_22 ( V_11 ) ;
if ( F_8 ( V_170 != V_120 || V_173 != sizeof( int ) ) )
goto V_44;
V_12 = F_95 ( V_174 , ( int T_6 * ) V_172 ) ;
if ( V_12 )
goto V_44;
V_12 = - V_59 ;
switch ( V_171 ) {
case V_175 :
if ( V_174 > V_176 )
goto V_44;
V_23 -> V_177 = V_174 ;
break;
case V_178 :
if ( V_174 > V_179 )
goto V_44;
V_23 -> V_180 = V_174 ;
break;
case V_181 :
if ( V_174 > V_182 )
goto V_44;
V_23 -> V_183 . V_184 = V_174 * V_185 ;
break;
case V_186 :
if ( V_174 > V_187 )
goto V_44;
V_23 -> V_188 . V_184 = V_174 * V_185 ;
break;
case V_189 :
if ( V_174 > V_190 )
goto V_44;
V_23 -> V_191 . V_184 = V_174 * V_185 ;
break;
case V_192 :
if ( V_174 > V_193 )
goto V_44;
V_23 -> V_194 . V_184 = V_174 * V_185 ;
break;
case V_195 :
if ( V_174 > V_196 )
goto V_44;
V_23 -> V_197 = V_174 ;
break;
case V_198 :
if ( V_174 > V_196 )
goto V_44;
V_23 -> V_199 = V_174 ;
break;
case V_121 :
if ( V_174 )
V_23 -> V_112 |= V_113 ;
else
V_23 -> V_112 &= ~ V_113 ;
break;
default:
V_12 = - V_163 ;
goto V_44;
}
V_12 = 0 ;
V_44:
F_28 ( V_11 ) ;
return V_12 ;
}
static int F_96 ( struct V_28 * V_10 , int V_170 , int V_171 ,
char T_6 * V_172 , int T_6 * V_173 )
{
struct V_10 * V_11 = V_10 -> V_11 ;
struct V_22 * V_23 = F_7 ( V_11 ) ;
int V_200 = 0 , V_129 = 0 , V_12 = - V_59 ;
F_22 ( V_11 ) ;
if ( F_8 ( V_170 != V_120 ) )
goto V_44;
V_12 = F_95 ( V_129 , V_173 ) ;
if ( V_12 )
goto V_44;
V_12 = - V_59 ;
if ( V_129 != sizeof( int ) )
goto V_44;
switch ( V_171 ) {
case V_175 :
V_200 = V_23 -> V_177 ; break;
case V_178 :
V_200 = V_23 -> V_180 ; break;
case V_181 :
V_200 = V_23 -> V_183 . V_184 / V_185 ; break;
case V_186 :
V_200 = V_23 -> V_188 . V_184 / V_185 ; break;
case V_189 :
V_200 = V_23 -> V_191 . V_184 / V_185 ; break;
case V_192 :
V_200 = V_23 -> V_194 . V_184 / V_185 ; break;
case V_195 :
V_200 = V_23 -> V_197 ; break;
case V_198 :
V_200 = V_23 -> V_199 ; break;
case V_121 :
V_200 = ( V_23 -> V_112 & V_113 ) != 0 ;
break;
default:
V_12 = - V_163 ;
goto V_44;
}
V_12 = 0 ;
if ( F_97 ( V_129 , V_173 ) || F_98 ( V_172 , & V_200 , V_129 ) )
V_12 = - V_152 ;
V_44:
F_28 ( V_11 ) ;
return V_12 ;
}
static int T_7 F_99 ( void )
{
int V_12 = F_100 ( & V_43 , 0 ) ;
if ( V_12 != 0 )
goto V_44;
F_101 () ;
F_102 () ;
V_56 = V_58 ;
V_12 = F_103 () ;
if ( V_12 != 0 ) {
F_77 ( V_201 ) ;
goto V_202;
}
V_12 = F_104 () ;
if ( V_12 ) {
F_77 ( V_203 ) ;
goto V_204;
}
V_12 = F_105 ( & V_205 ) ;
if ( V_12 ) {
F_77 ( V_206 ) ;
goto V_207;
}
F_106 ( V_208 , V_209 ) ;
F_106 ( V_210 , V_211 ) ;
V_44:
return V_12 ;
V_207:
F_107 () ;
V_204:
F_108 () ;
V_202:
F_109 ( & V_43 ) ;
goto V_44;
}
static void T_8 F_110 ( void )
{
F_111 () ;
F_112 ( V_208 ) ;
F_112 ( V_210 ) ;
F_113 ( V_41 ) ;
F_108 () ;
F_107 () ;
F_109 ( & V_43 ) ;
}
