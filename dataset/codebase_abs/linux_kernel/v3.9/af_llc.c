static inline T_1 F_1 ( int V_1 )
{
return V_2 [ V_1 ] ++ ;
}
static inline T_2 F_2 ( T_1 V_3 )
{
return F_3 ( V_4 ) ;
}
static inline T_3 F_4 ( struct V_5 * V_6 )
{
return ! memcmp ( V_6 , & V_7 , sizeof( * V_6 ) ) ;
}
static inline T_3 F_5 ( struct V_8 * V_9 , struct V_5 * V_6 )
{
T_3 V_10 = V_11 ;
if ( V_6 -> V_12 || V_6 -> V_13 )
V_10 = V_11 ;
else if ( V_9 -> V_14 == V_15 )
V_10 = V_16 ;
return V_10 ;
}
static int F_6 ( struct V_8 * V_9 , struct V_17 * V_18 , int V_19 )
{
struct V_20 * V_21 = F_7 ( V_9 ) ;
int V_10 = 0 ;
if ( F_8 ( F_9 ( V_21 -> V_22 ) ||
V_21 -> V_23 ||
V_21 -> V_24 ) ) {
long V_25 = F_10 ( V_9 , V_19 ) ;
V_10 = F_11 ( V_9 , V_25 ) ;
}
if ( F_8 ( ! V_10 ) )
V_10 = F_12 ( V_9 , V_18 ) ;
return V_10 ;
}
static void F_13 ( struct V_26 * V_8 , struct V_8 * V_9 )
{
F_14 ( V_9 , V_8 ) ;
V_9 -> V_14 = V_8 -> type ;
V_8 -> V_27 = & V_28 ;
}
static int F_15 ( struct V_29 * V_29 , struct V_26 * V_8 , int V_30 ,
int V_31 )
{
struct V_8 * V_9 ;
int V_10 = - V_32 ;
if ( ! F_16 ( V_29 -> V_33 , V_34 ) )
return - V_35 ;
if ( ! F_17 ( V_29 , & V_36 ) )
return - V_37 ;
if ( F_18 ( V_8 -> type == V_38 || V_8 -> type == V_15 ) ) {
V_10 = - V_39 ;
V_9 = F_19 ( V_29 , V_40 , V_41 , & V_42 ) ;
if ( V_9 ) {
V_10 = 0 ;
F_13 ( V_8 , V_9 ) ;
}
}
return V_10 ;
}
static int F_20 ( struct V_26 * V_8 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_20 * V_21 ;
if ( F_8 ( V_9 == NULL ) )
goto V_43;
F_21 ( V_9 ) ;
F_22 ( V_9 ) ;
V_21 = F_7 ( V_9 ) ;
F_23 ( L_1 , V_44 ,
V_21 -> V_45 . V_46 , V_21 -> V_47 . V_46 ) ;
if ( ! F_24 ( V_9 ) )
F_25 ( V_9 , V_9 -> V_48 ) ;
if ( ! F_26 ( V_9 , V_49 ) )
F_27 ( V_21 -> V_1 , V_9 ) ;
F_28 ( V_9 ) ;
if ( V_21 -> V_50 )
F_29 ( V_21 -> V_50 ) ;
F_30 ( V_9 ) ;
F_31 ( V_9 ) ;
V_43:
return 0 ;
}
static int F_32 ( void )
{
struct V_51 * V_1 ;
int V_52 , V_53 = 0 ;
while ( V_53 < V_54 ) {
for ( V_52 = V_55 ;
V_52 < V_56 ; V_52 += 2 ) {
V_1 = F_33 ( V_52 ) ;
if ( ! V_1 ) {
V_55 = V_52 + 2 ;
goto V_43;
}
F_34 ( V_1 ) ;
}
V_55 = V_57 ;
V_53 ++ ;
}
V_52 = 0 ;
V_43:
return V_52 ;
}
static int F_35 ( struct V_26 * V_8 , struct V_5 * V_6 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_20 * V_21 = F_7 ( V_9 ) ;
struct V_51 * V_1 ;
int V_10 = - V_58 ;
if ( ! F_26 ( V_9 , V_49 ) )
goto V_43;
V_10 = - V_59 ;
if ( V_9 -> V_60 ) {
V_21 -> V_50 = F_36 ( & V_36 , V_9 -> V_60 ) ;
if ( V_21 -> V_50 && V_6 -> V_61 != V_21 -> V_50 -> type ) {
F_29 ( V_21 -> V_50 ) ;
V_21 -> V_50 = NULL ;
}
} else
V_21 -> V_50 = F_37 ( & V_36 , V_6 -> V_61 ) ;
if ( ! V_21 -> V_50 )
goto V_43;
V_10 = - V_62 ;
V_21 -> V_45 . V_46 = F_32 () ;
if ( ! V_21 -> V_45 . V_46 )
goto V_43;
V_10 = - V_63 ;
V_1 = F_38 ( V_21 -> V_45 . V_46 , NULL ) ;
if ( ! V_1 )
goto V_43;
memcpy ( V_21 -> V_45 . V_64 , V_21 -> V_50 -> V_65 , V_66 ) ;
memcpy ( & V_21 -> V_6 , V_6 , sizeof( V_21 -> V_6 ) ) ;
F_39 ( V_1 , V_9 ) ;
F_40 ( V_9 , V_49 ) ;
V_10 = 0 ;
V_43:
return V_10 ;
}
static int F_41 ( struct V_26 * V_8 , struct V_67 * V_68 , int V_69 )
{
struct V_5 * V_6 = (struct V_5 * ) V_68 ;
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_20 * V_21 = F_7 ( V_9 ) ;
struct V_51 * V_1 ;
int V_10 = - V_58 ;
F_23 ( L_2 , V_44 , V_6 -> V_70 ) ;
if ( F_8 ( ! F_26 ( V_9 , V_49 ) || V_69 != sizeof( * V_6 ) ) )
goto V_43;
V_10 = - V_37 ;
if ( F_8 ( V_6 -> V_71 != V_72 ) )
goto V_43;
V_10 = - V_59 ;
F_42 () ;
if ( V_9 -> V_60 ) {
V_21 -> V_50 = F_43 ( & V_36 , V_9 -> V_60 ) ;
if ( V_21 -> V_50 ) {
if ( ! V_6 -> V_61 )
V_6 -> V_61 = V_21 -> V_50 -> type ;
if ( F_44 ( V_6 -> V_73 ) )
memcpy ( V_6 -> V_73 , V_21 -> V_50 -> V_65 ,
V_66 ) ;
if ( V_6 -> V_61 != V_21 -> V_50 -> type ||
! F_45 ( V_6 -> V_73 ,
V_21 -> V_50 -> V_65 ) ) {
V_10 = - V_58 ;
V_21 -> V_50 = NULL ;
}
}
} else
V_21 -> V_50 = F_46 ( & V_36 , V_6 -> V_61 ,
V_6 -> V_73 ) ;
if ( V_21 -> V_50 )
F_47 ( V_21 -> V_50 ) ;
F_48 () ;
if ( ! V_21 -> V_50 )
goto V_43;
if ( ! V_6 -> V_70 ) {
V_10 = - V_62 ;
V_6 -> V_70 = F_32 () ;
if ( ! V_6 -> V_70 )
goto V_43;
}
V_1 = F_33 ( V_6 -> V_70 ) ;
if ( ! V_1 ) {
V_1 = F_38 ( V_6 -> V_70 , NULL ) ;
V_10 = - V_63 ;
if ( ! V_1 )
goto V_43;
} else {
struct V_74 V_45 , V_47 ;
struct V_8 * V_75 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
memcpy ( V_45 . V_64 , V_6 -> V_73 , V_66 ) ;
V_45 . V_46 = V_6 -> V_70 ;
V_10 = - V_76 ;
V_75 = F_49 ( V_1 , & V_47 , & V_45 ) ;
if ( V_75 ) {
F_30 ( V_75 ) ;
goto V_77;
}
}
V_21 -> V_45 . V_46 = V_6 -> V_70 ;
memcpy ( V_21 -> V_45 . V_64 , V_6 -> V_73 , V_66 ) ;
memcpy ( & V_21 -> V_6 , V_6 , sizeof( V_21 -> V_6 ) ) ;
F_39 ( V_1 , V_9 ) ;
F_40 ( V_9 , V_49 ) ;
V_10 = 0 ;
V_77:
F_34 ( V_1 ) ;
V_43:
return V_10 ;
}
static int F_50 ( struct V_26 * V_8 , int V_78 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
int V_10 = - V_79 ;
F_22 ( V_9 ) ;
if ( F_8 ( V_9 -> V_80 != V_81 ) )
goto V_43;
V_10 = - V_58 ;
if ( V_78 != 2 )
goto V_43;
V_10 = F_24 ( V_9 ) ;
if ( ! V_10 )
V_10 = F_25 ( V_9 , V_9 -> V_48 ) ;
V_9 -> V_82 ( V_9 ) ;
V_43:
F_28 ( V_9 ) ;
return V_10 ;
}
static int F_51 ( struct V_26 * V_8 , struct V_67 * V_68 ,
int V_69 , int V_83 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_20 * V_21 = F_7 ( V_9 ) ;
struct V_5 * V_6 = (struct V_5 * ) V_68 ;
int V_10 = - V_58 ;
F_22 ( V_9 ) ;
if ( F_8 ( V_69 != sizeof( * V_6 ) ) )
goto V_43;
V_10 = - V_37 ;
if ( F_8 ( V_6 -> V_71 != V_72 ) )
goto V_43;
if ( F_8 ( V_9 -> V_14 != V_15 ) )
goto V_43;
V_10 = - V_84 ;
if ( F_8 ( V_8 -> V_22 == V_85 ) )
goto V_43;
if ( F_26 ( V_9 , V_49 ) ) {
V_10 = F_35 ( V_8 , V_6 ) ;
if ( V_10 )
goto V_43;
}
V_21 -> V_47 . V_46 = V_6 -> V_70 ;
memcpy ( V_21 -> V_47 . V_64 , V_6 -> V_73 , V_66 ) ;
V_8 -> V_22 = V_85 ;
V_9 -> V_80 = V_86 ;
V_21 -> V_87 = F_1 ( V_21 -> V_1 -> V_45 . V_46 ) ;
V_10 = F_52 ( V_9 , V_21 -> V_50 -> V_65 ,
V_6 -> V_73 , V_6 -> V_70 ) ;
if ( V_10 ) {
F_23 ( L_3 , V_44 ) ;
V_8 -> V_22 = V_88 ;
V_9 -> V_80 = V_89 ;
goto V_43;
}
if ( V_9 -> V_80 == V_86 ) {
const long V_90 = F_10 ( V_9 , V_83 & V_91 ) ;
if ( ! V_90 || ! F_53 ( V_9 , V_90 ) )
goto V_43;
V_10 = F_54 ( V_90 ) ;
if ( F_55 ( V_92 ) )
goto V_43;
}
if ( V_9 -> V_80 == V_89 )
goto V_93;
V_8 -> V_22 = V_94 ;
V_10 = 0 ;
V_43:
F_28 ( V_9 ) ;
return V_10 ;
V_93:
V_10 = V_93 ( V_9 ) ? : - V_95 ;
V_8 -> V_22 = V_88 ;
goto V_43;
}
static int F_56 ( struct V_26 * V_8 , int V_96 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
int V_10 = - V_58 ;
F_22 ( V_9 ) ;
if ( F_8 ( V_8 -> V_22 != V_88 ) )
goto V_43;
V_10 = - V_97 ;
if ( F_8 ( V_9 -> V_14 != V_15 ) )
goto V_43;
V_10 = - V_98 ;
if ( F_26 ( V_9 , V_49 ) )
goto V_43;
V_10 = 0 ;
if ( ! ( unsigned int ) V_96 )
V_96 = 1 ;
V_9 -> V_99 = V_96 ;
if ( V_9 -> V_80 != V_100 ) {
V_9 -> V_101 = 0 ;
V_9 -> V_80 = V_100 ;
}
V_9 -> V_102 -> V_83 |= V_103 ;
V_43:
F_28 ( V_9 ) ;
return V_10 ;
}
static int F_25 ( struct V_8 * V_9 , long V_25 )
{
F_57 ( V_104 ) ;
int V_10 = 0 ;
while ( 1 ) {
F_58 ( F_59 ( V_9 ) , & V_104 , V_105 ) ;
if ( F_60 ( V_9 , & V_25 , V_9 -> V_80 == V_89 ) )
break;
V_10 = - V_106 ;
if ( F_55 ( V_92 ) )
break;
V_10 = - V_98 ;
if ( ! V_25 )
break;
V_10 = 0 ;
}
F_61 ( F_59 ( V_9 ) , & V_104 ) ;
return V_10 ;
}
static int F_53 ( struct V_8 * V_9 , long V_25 )
{
F_57 ( V_104 ) ;
while ( 1 ) {
F_58 ( F_59 ( V_9 ) , & V_104 , V_105 ) ;
if ( F_60 ( V_9 , & V_25 , V_9 -> V_80 != V_86 ) )
break;
if ( F_55 ( V_92 ) || ! V_25 )
break;
}
F_61 ( F_59 ( V_9 ) , & V_104 ) ;
return V_25 ;
}
static int F_11 ( struct V_8 * V_9 , long V_25 )
{
F_57 ( V_104 ) ;
struct V_20 * V_21 = F_7 ( V_9 ) ;
int V_10 ;
while ( 1 ) {
F_58 ( F_59 ( V_9 ) , & V_104 , V_105 ) ;
V_10 = 0 ;
if ( F_60 ( V_9 , & V_25 ,
( V_9 -> V_107 & V_108 ) ||
( ! F_9 ( V_21 -> V_22 ) &&
! V_21 -> V_23 &&
! V_21 -> V_24 ) ) )
break;
V_10 = - V_106 ;
if ( F_55 ( V_92 ) )
break;
V_10 = - V_98 ;
if ( ! V_25 )
break;
}
F_61 ( F_59 ( V_9 ) , & V_104 ) ;
return V_10 ;
}
static int F_62 ( struct V_8 * V_9 , long V_90 )
{
int V_10 ;
while ( 1 ) {
V_10 = V_93 ( V_9 ) ;
if ( V_10 )
break;
V_10 = 0 ;
if ( V_9 -> V_107 & V_108 )
break;
V_10 = - V_98 ;
if ( ! V_90 )
break;
V_10 = F_54 ( V_90 ) ;
if ( F_55 ( V_92 ) )
break;
V_10 = 0 ;
if ( F_63 ( V_9 , & V_90 ) )
break;
}
return V_10 ;
}
static void F_64 ( struct V_109 * V_110 , struct V_17 * V_18 )
{
struct V_20 * V_21 = F_7 ( V_18 -> V_9 ) ;
if ( V_21 -> V_111 & V_112 ) {
struct V_113 V_114 ;
V_114 . V_115 = F_7 ( V_18 -> V_9 ) -> V_50 -> V_116 ;
F_65 ( V_18 , & V_114 . V_117 ) ;
F_66 ( V_18 , V_114 . V_118 ) ;
F_67 ( V_110 , V_119 , V_120 , sizeof( V_114 ) , & V_114 ) ;
}
}
static int F_68 ( struct V_26 * V_8 , struct V_26 * V_121 , int V_83 )
{
struct V_8 * V_9 = V_8 -> V_9 , * V_122 ;
struct V_20 * V_21 , * V_123 ;
struct V_17 * V_18 ;
int V_10 = - V_97 ;
F_23 ( L_4 , V_44 ,
F_7 ( V_9 ) -> V_45 . V_46 ) ;
F_22 ( V_9 ) ;
if ( F_8 ( V_9 -> V_14 != V_15 ) )
goto V_43;
V_10 = - V_58 ;
if ( F_8 ( V_8 -> V_22 != V_88 ||
V_9 -> V_80 != V_100 ) )
goto V_43;
if ( F_69 ( & V_9 -> V_124 ) ) {
V_10 = F_62 ( V_9 , V_9 -> V_48 ) ;
if ( V_10 )
goto V_43;
}
F_23 ( L_5 , V_44 ,
F_7 ( V_9 ) -> V_45 . V_46 ) ;
V_18 = F_70 ( & V_9 -> V_124 ) ;
V_10 = - V_58 ;
if ( ! V_18 -> V_9 )
goto V_125;
V_10 = 0 ;
V_122 = V_18 -> V_9 ;
F_13 ( V_121 , V_122 ) ;
F_40 ( V_122 , V_49 ) ;
V_122 -> V_80 = V_81 ;
V_121 -> V_22 = V_94 ;
V_21 = F_7 ( V_9 ) ;
V_123 = F_7 ( V_122 ) ;
memcpy ( & V_123 -> V_6 , & V_21 -> V_6 , sizeof( V_123 -> V_6 ) ) ;
V_123 -> V_87 = F_1 ( V_123 -> V_45 . V_46 ) ;
V_9 -> V_80 = V_100 ;
V_9 -> V_101 -- ;
F_23 ( L_6 , V_44 ,
F_7 ( V_9 ) -> V_6 . V_70 , V_123 -> V_47 . V_46 ) ;
V_125:
F_71 ( V_18 ) ;
V_43:
F_28 ( V_9 ) ;
return V_10 ;
}
static int F_72 ( struct V_126 * V_127 , struct V_26 * V_8 ,
struct V_109 * V_110 , T_4 V_128 , int V_83 )
{
struct V_5 * V_68 = (struct V_5 * ) V_110 -> V_129 ;
const int V_130 = V_83 & V_131 ;
struct V_17 * V_18 = NULL ;
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_20 * V_21 = F_7 ( V_9 ) ;
unsigned long V_132 ;
T_4 V_133 = 0 ;
T_5 V_134 = 0 ;
T_5 * V_135 ;
unsigned long V_136 ;
int V_137 ;
long V_90 ;
V_110 -> V_138 = 0 ;
F_22 ( V_9 ) ;
V_133 = - V_79 ;
if ( F_8 ( V_9 -> V_14 == V_15 && V_9 -> V_80 == V_100 ) )
goto V_43;
V_90 = F_73 ( V_9 , V_130 ) ;
V_135 = & V_21 -> V_139 ;
if ( V_83 & V_140 ) {
V_134 = V_21 -> V_139 ;
V_135 = & V_134 ;
}
V_137 = F_74 ( V_9 , V_83 & V_141 , V_128 ) ;
V_133 = 0 ;
do {
T_5 V_142 ;
if ( F_55 ( V_92 ) ) {
if ( V_133 )
break;
V_133 = V_90 ? F_54 ( V_90 ) : - V_98 ;
break;
}
V_18 = F_75 ( & V_9 -> V_124 ) ;
if ( V_18 ) {
V_142 = * V_135 ;
goto V_143;
}
if ( V_133 >= V_137 && ! V_9 -> V_144 . V_145 )
break;
if ( V_133 ) {
if ( V_9 -> V_146 ||
V_9 -> V_80 == V_89 ||
( V_9 -> V_107 & V_108 ) ||
! V_90 ||
( V_83 & V_140 ) )
break;
} else {
if ( F_26 ( V_9 , V_147 ) )
break;
if ( V_9 -> V_146 ) {
V_133 = V_93 ( V_9 ) ;
break;
}
if ( V_9 -> V_107 & V_108 )
break;
if ( V_9 -> V_14 == V_15 && V_9 -> V_80 == V_89 ) {
if ( ! F_26 ( V_9 , V_147 ) ) {
V_133 = - V_79 ;
break;
}
break;
}
if ( ! V_90 ) {
V_133 = - V_98 ;
break;
}
}
if ( V_133 >= V_137 ) {
F_28 ( V_9 ) ;
F_22 ( V_9 ) ;
} else
F_63 ( V_9 , & V_90 ) ;
if ( ( V_83 & V_140 ) && V_134 != V_21 -> V_139 ) {
F_76 ( L_7 ,
V_92 -> V_148 ,
F_77 ( V_92 ) ) ;
V_134 = V_21 -> V_139 ;
}
continue;
V_143:
V_136 = V_18 -> V_128 - V_142 ;
if ( V_128 < V_136 )
V_136 = V_128 ;
if ( ! ( V_83 & V_149 ) ) {
int V_10 = F_78 ( V_18 , V_142 ,
V_110 -> V_150 , V_136 ) ;
if ( V_10 ) {
if ( ! V_133 )
V_133 = - V_151 ;
break;
}
}
* V_135 += V_136 ;
V_133 += V_136 ;
V_128 -= V_136 ;
if ( V_9 -> V_14 != V_15 )
goto V_152;
if ( ! ( V_83 & V_140 ) ) {
F_79 ( & V_9 -> V_124 . V_153 , V_132 ) ;
F_80 ( V_9 , V_18 , false ) ;
F_81 ( & V_9 -> V_124 . V_153 , V_132 ) ;
* V_135 = 0 ;
}
if ( V_136 + V_142 < V_18 -> V_128 )
continue;
} while ( V_128 > 0 );
V_43:
F_28 ( V_9 ) ;
return V_133 ;
V_152:
if ( V_68 != NULL && V_18 != NULL ) {
memcpy ( V_68 , F_82 ( V_18 ) , sizeof( * V_68 ) ) ;
V_110 -> V_138 = sizeof( * V_68 ) ;
}
if ( F_7 ( V_9 ) -> V_111 )
F_64 ( V_110 , V_18 ) ;
if ( ! ( V_83 & V_140 ) ) {
F_79 ( & V_9 -> V_124 . V_153 , V_132 ) ;
F_80 ( V_9 , V_18 , false ) ;
F_81 ( & V_9 -> V_124 . V_153 , V_132 ) ;
* V_135 = 0 ;
}
goto V_43;
}
static int F_83 ( struct V_126 * V_127 , struct V_26 * V_8 ,
struct V_109 * V_110 , T_4 V_128 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_20 * V_21 = F_7 ( V_9 ) ;
struct V_5 * V_6 = (struct V_5 * ) V_110 -> V_129 ;
int V_83 = V_110 -> V_154 ;
int V_19 = V_83 & V_131 ;
struct V_17 * V_18 ;
T_4 V_155 = 0 ;
int V_10 = - V_58 , V_133 = 0 , V_156 ;
F_23 ( L_8 , V_44 ,
V_21 -> V_45 . V_46 , V_21 -> V_47 . V_46 ) ;
F_22 ( V_9 ) ;
if ( V_6 ) {
if ( V_110 -> V_138 < sizeof( * V_6 ) )
goto V_157;
} else {
if ( F_4 ( & V_21 -> V_6 ) )
goto V_157;
V_6 = & V_21 -> V_6 ;
}
if ( F_26 ( V_9 , V_49 ) ) {
V_10 = F_35 ( V_8 , V_6 ) ;
if ( V_10 )
goto V_157;
}
V_156 = V_21 -> V_50 -> V_158 + F_5 ( V_9 , V_6 ) ;
V_155 = V_156 + V_128 ;
if ( V_155 > V_21 -> V_50 -> V_159 )
V_155 = V_21 -> V_50 -> V_159 ;
V_133 = V_155 - V_156 ;
F_28 ( V_9 ) ;
V_18 = F_84 ( V_9 , V_155 , V_19 , & V_10 ) ;
F_22 ( V_9 ) ;
if ( ! V_18 )
goto V_157;
V_18 -> V_50 = V_21 -> V_50 ;
V_18 -> V_30 = F_2 ( V_6 -> V_61 ) ;
F_85 ( V_18 , V_156 ) ;
V_10 = F_86 ( F_87 ( V_18 , V_133 ) , V_110 -> V_150 , V_133 ) ;
if ( V_10 )
goto V_43;
if ( V_9 -> V_14 == V_38 || V_6 -> V_160 ) {
F_88 ( V_21 -> V_1 , V_18 , V_6 -> V_73 ,
V_6 -> V_70 ) ;
goto V_43;
}
if ( V_6 -> V_12 ) {
F_89 ( V_21 -> V_1 , V_18 , V_6 -> V_73 ,
V_6 -> V_70 ) ;
goto V_43;
}
if ( V_6 -> V_13 ) {
F_90 ( V_21 -> V_1 , V_18 , V_6 -> V_73 ,
V_6 -> V_70 ) ;
goto V_43;
}
V_10 = - V_161 ;
if ( ! ( V_9 -> V_14 == V_15 && ! V_6 -> V_160 ) )
goto V_43;
V_10 = F_6 ( V_9 , V_18 , V_19 ) ;
V_43:
if ( V_10 ) {
F_71 ( V_18 ) ;
V_157:
F_23 ( L_9 ,
V_44 , V_21 -> V_45 . V_46 , V_21 -> V_47 . V_46 , V_10 ) ;
}
F_28 ( V_9 ) ;
return V_10 ? : V_133 ;
}
static int F_91 ( struct V_26 * V_8 , struct V_67 * V_68 ,
int * V_162 , int V_163 )
{
struct V_5 V_164 ;
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_20 * V_21 = F_7 ( V_9 ) ;
int V_10 = - V_165 ;
memset ( & V_164 , 0 , sizeof( V_164 ) ) ;
F_22 ( V_9 ) ;
if ( F_26 ( V_9 , V_49 ) )
goto V_43;
* V_162 = sizeof( V_164 ) ;
if ( V_163 ) {
V_10 = - V_79 ;
if ( V_9 -> V_80 != V_81 )
goto V_43;
if( V_21 -> V_50 )
V_164 . V_61 = V_21 -> V_50 -> type ;
V_164 . V_70 = V_21 -> V_47 . V_46 ;
memcpy ( & V_164 . V_73 , & V_21 -> V_47 . V_64 , V_66 ) ;
} else {
V_10 = - V_58 ;
if ( ! V_21 -> V_1 )
goto V_43;
V_164 . V_70 = V_21 -> V_1 -> V_45 . V_46 ;
if ( V_21 -> V_50 ) {
V_164 . V_61 = V_21 -> V_50 -> type ;
memcpy ( & V_164 . V_73 , V_21 -> V_50 -> V_65 ,
V_66 ) ;
}
}
V_10 = 0 ;
V_164 . V_71 = V_72 ;
memcpy ( V_68 , & V_164 , sizeof( V_164 ) ) ;
V_43:
F_28 ( V_9 ) ;
return V_10 ;
}
static int F_92 ( struct V_26 * V_8 , unsigned int V_166 ,
unsigned long V_167 )
{
return - V_168 ;
}
static int F_93 ( struct V_26 * V_8 , int V_169 , int V_170 ,
char T_6 * V_171 , unsigned int V_172 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_20 * V_21 = F_7 ( V_9 ) ;
unsigned int V_173 ;
int V_10 = - V_58 ;
F_22 ( V_9 ) ;
if ( F_8 ( V_169 != V_119 || V_172 != sizeof( int ) ) )
goto V_43;
V_10 = F_94 ( V_173 , ( int T_6 * ) V_171 ) ;
if ( V_10 )
goto V_43;
V_10 = - V_58 ;
switch ( V_170 ) {
case V_174 :
if ( V_173 > V_175 )
goto V_43;
V_21 -> V_176 = V_173 ;
break;
case V_177 :
if ( V_173 > V_178 )
goto V_43;
V_21 -> V_179 = V_173 ;
break;
case V_180 :
if ( V_173 > V_181 )
goto V_43;
V_21 -> V_182 . V_183 = V_173 * V_184 ;
break;
case V_185 :
if ( V_173 > V_186 )
goto V_43;
V_21 -> V_187 . V_183 = V_173 * V_184 ;
break;
case V_188 :
if ( V_173 > V_189 )
goto V_43;
V_21 -> V_190 . V_183 = V_173 * V_184 ;
break;
case V_191 :
if ( V_173 > V_192 )
goto V_43;
V_21 -> V_193 . V_183 = V_173 * V_184 ;
break;
case V_194 :
if ( V_173 > V_195 )
goto V_43;
V_21 -> V_196 = V_173 ;
break;
case V_197 :
if ( V_173 > V_195 )
goto V_43;
V_21 -> V_198 = V_173 ;
break;
case V_120 :
if ( V_173 )
V_21 -> V_111 |= V_112 ;
else
V_21 -> V_111 &= ~ V_112 ;
break;
default:
V_10 = - V_161 ;
goto V_43;
}
V_10 = 0 ;
V_43:
F_28 ( V_9 ) ;
return V_10 ;
}
static int F_95 ( struct V_26 * V_8 , int V_169 , int V_170 ,
char T_6 * V_171 , int T_6 * V_172 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_20 * V_21 = F_7 ( V_9 ) ;
int V_199 = 0 , V_128 = 0 , V_10 = - V_58 ;
F_22 ( V_9 ) ;
if ( F_8 ( V_169 != V_119 ) )
goto V_43;
V_10 = F_94 ( V_128 , V_172 ) ;
if ( V_10 )
goto V_43;
V_10 = - V_58 ;
if ( V_128 != sizeof( int ) )
goto V_43;
switch ( V_170 ) {
case V_174 :
V_199 = V_21 -> V_176 ; break;
case V_177 :
V_199 = V_21 -> V_179 ; break;
case V_180 :
V_199 = V_21 -> V_182 . V_183 / V_184 ; break;
case V_185 :
V_199 = V_21 -> V_187 . V_183 / V_184 ; break;
case V_188 :
V_199 = V_21 -> V_190 . V_183 / V_184 ; break;
case V_191 :
V_199 = V_21 -> V_193 . V_183 / V_184 ; break;
case V_194 :
V_199 = V_21 -> V_196 ; break;
case V_197 :
V_199 = V_21 -> V_198 ; break;
case V_120 :
V_199 = ( V_21 -> V_111 & V_112 ) != 0 ;
break;
default:
V_10 = - V_161 ;
goto V_43;
}
V_10 = 0 ;
if ( F_96 ( V_128 , V_172 ) || F_97 ( V_171 , & V_199 , V_128 ) )
V_10 = - V_151 ;
V_43:
F_28 ( V_9 ) ;
return V_10 ;
}
static int T_7 F_98 ( void )
{
int V_10 = F_99 ( & V_42 , 0 ) ;
if ( V_10 != 0 )
goto V_43;
F_100 () ;
F_101 () ;
V_55 = V_57 ;
V_10 = F_102 () ;
if ( V_10 != 0 ) {
F_103 ( V_200 ) ;
goto V_201;
}
V_10 = F_104 () ;
if ( V_10 ) {
F_103 ( V_202 ) ;
goto V_203;
}
V_10 = F_105 ( & V_204 ) ;
if ( V_10 ) {
F_103 ( V_205 ) ;
goto V_206;
}
F_106 ( V_207 , V_208 ) ;
F_106 ( V_209 , V_210 ) ;
V_43:
return V_10 ;
V_206:
F_107 () ;
V_203:
F_108 () ;
V_201:
F_109 () ;
F_110 ( & V_42 ) ;
goto V_43;
}
static void T_8 F_111 ( void )
{
F_109 () ;
F_112 ( V_207 ) ;
F_112 ( V_209 ) ;
F_113 ( V_40 ) ;
F_108 () ;
F_107 () ;
F_110 ( & V_42 ) ;
}
