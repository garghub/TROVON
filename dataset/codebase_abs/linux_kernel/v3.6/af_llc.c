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
if ( ! F_16 ( V_33 ) )
return - V_34 ;
if ( ! F_17 ( V_29 , & V_35 ) )
return - V_36 ;
if ( F_18 ( V_8 -> type == V_37 || V_8 -> type == V_15 ) ) {
V_10 = - V_38 ;
V_9 = F_19 ( V_29 , V_39 , V_40 , & V_41 ) ;
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
goto V_42;
F_21 ( V_9 ) ;
F_22 ( V_9 ) ;
V_21 = F_7 ( V_9 ) ;
F_23 ( L_1 , V_43 ,
V_21 -> V_44 . V_45 , V_21 -> V_46 . V_45 ) ;
if ( ! F_24 ( V_9 ) )
F_25 ( V_9 , V_9 -> V_47 ) ;
if ( ! F_26 ( V_9 , V_48 ) )
F_27 ( V_21 -> V_1 , V_9 ) ;
F_28 ( V_9 ) ;
if ( V_21 -> V_49 )
F_29 ( V_21 -> V_49 ) ;
F_30 ( V_9 ) ;
F_31 ( V_9 ) ;
V_42:
return 0 ;
}
static int F_32 ( void )
{
struct V_50 * V_1 ;
int V_51 , V_52 = 0 ;
while ( V_52 < V_53 ) {
for ( V_51 = V_54 ;
V_51 < V_55 ; V_51 += 2 ) {
V_1 = F_33 ( V_51 ) ;
if ( ! V_1 ) {
V_54 = V_51 + 2 ;
goto V_42;
}
F_34 ( V_1 ) ;
}
V_54 = V_56 ;
V_52 ++ ;
}
V_51 = 0 ;
V_42:
return V_51 ;
}
static int F_35 ( struct V_26 * V_8 , struct V_5 * V_6 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_20 * V_21 = F_7 ( V_9 ) ;
struct V_50 * V_1 ;
int V_10 = - V_57 ;
if ( ! F_26 ( V_9 , V_48 ) )
goto V_42;
V_10 = - V_58 ;
if ( V_9 -> V_59 ) {
V_21 -> V_49 = F_36 ( & V_35 , V_9 -> V_59 ) ;
if ( V_21 -> V_49 && V_6 -> V_60 != V_21 -> V_49 -> type ) {
F_29 ( V_21 -> V_49 ) ;
V_21 -> V_49 = NULL ;
}
} else
V_21 -> V_49 = F_37 ( & V_35 , V_6 -> V_60 ) ;
if ( ! V_21 -> V_49 )
goto V_42;
V_10 = - V_61 ;
V_21 -> V_44 . V_45 = F_32 () ;
if ( ! V_21 -> V_44 . V_45 )
goto V_42;
V_10 = - V_62 ;
V_1 = F_38 ( V_21 -> V_44 . V_45 , NULL ) ;
if ( ! V_1 )
goto V_42;
memcpy ( V_21 -> V_44 . V_63 , V_21 -> V_49 -> V_64 , V_65 ) ;
memcpy ( & V_21 -> V_6 , V_6 , sizeof( V_21 -> V_6 ) ) ;
F_39 ( V_1 , V_9 ) ;
F_40 ( V_9 , V_48 ) ;
V_10 = 0 ;
V_42:
return V_10 ;
}
static int F_41 ( struct V_26 * V_8 , struct V_66 * V_67 , int V_68 )
{
struct V_5 * V_6 = (struct V_5 * ) V_67 ;
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_20 * V_21 = F_7 ( V_9 ) ;
struct V_50 * V_1 ;
int V_10 = - V_57 ;
F_23 ( L_2 , V_43 , V_6 -> V_69 ) ;
if ( F_8 ( ! F_26 ( V_9 , V_48 ) || V_68 != sizeof( * V_6 ) ) )
goto V_42;
V_10 = - V_36 ;
if ( F_8 ( V_6 -> V_70 != V_71 ) )
goto V_42;
V_10 = - V_58 ;
F_42 () ;
if ( V_9 -> V_59 ) {
V_21 -> V_49 = F_43 ( & V_35 , V_9 -> V_59 ) ;
if ( V_21 -> V_49 ) {
if ( ! V_6 -> V_60 )
V_6 -> V_60 = V_21 -> V_49 -> type ;
if ( F_44 ( V_6 -> V_72 ) )
memcpy ( V_6 -> V_72 , V_21 -> V_49 -> V_64 ,
V_65 ) ;
if ( V_6 -> V_60 != V_21 -> V_49 -> type ||
! F_45 ( V_6 -> V_72 ,
V_21 -> V_49 -> V_64 ) ) {
V_10 = - V_57 ;
V_21 -> V_49 = NULL ;
}
}
} else
V_21 -> V_49 = F_46 ( & V_35 , V_6 -> V_60 ,
V_6 -> V_72 ) ;
if ( V_21 -> V_49 )
F_47 ( V_21 -> V_49 ) ;
F_48 () ;
if ( ! V_21 -> V_49 )
goto V_42;
if ( ! V_6 -> V_69 ) {
V_10 = - V_61 ;
V_6 -> V_69 = F_32 () ;
if ( ! V_6 -> V_69 )
goto V_42;
}
V_1 = F_33 ( V_6 -> V_69 ) ;
if ( ! V_1 ) {
V_1 = F_38 ( V_6 -> V_69 , NULL ) ;
V_10 = - V_62 ;
if ( ! V_1 )
goto V_42;
} else {
struct V_73 V_44 , V_46 ;
struct V_8 * V_74 ;
memset ( & V_44 , 0 , sizeof( V_44 ) ) ;
memset ( & V_46 , 0 , sizeof( V_46 ) ) ;
memcpy ( V_44 . V_63 , V_6 -> V_72 , V_65 ) ;
V_44 . V_45 = V_6 -> V_69 ;
V_10 = - V_75 ;
V_74 = F_49 ( V_1 , & V_46 , & V_44 ) ;
if ( V_74 ) {
F_30 ( V_74 ) ;
goto V_76;
}
}
V_21 -> V_44 . V_45 = V_6 -> V_69 ;
memcpy ( V_21 -> V_44 . V_63 , V_6 -> V_72 , V_65 ) ;
memcpy ( & V_21 -> V_6 , V_6 , sizeof( V_21 -> V_6 ) ) ;
F_39 ( V_1 , V_9 ) ;
F_40 ( V_9 , V_48 ) ;
V_10 = 0 ;
V_76:
F_34 ( V_1 ) ;
V_42:
return V_10 ;
}
static int F_50 ( struct V_26 * V_8 , int V_77 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
int V_10 = - V_78 ;
F_22 ( V_9 ) ;
if ( F_8 ( V_9 -> V_79 != V_80 ) )
goto V_42;
V_10 = - V_57 ;
if ( V_77 != 2 )
goto V_42;
V_10 = F_24 ( V_9 ) ;
if ( ! V_10 )
V_10 = F_25 ( V_9 , V_9 -> V_47 ) ;
V_9 -> V_81 ( V_9 ) ;
V_42:
F_28 ( V_9 ) ;
return V_10 ;
}
static int F_51 ( struct V_26 * V_8 , struct V_66 * V_67 ,
int V_68 , int V_82 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_20 * V_21 = F_7 ( V_9 ) ;
struct V_5 * V_6 = (struct V_5 * ) V_67 ;
int V_10 = - V_57 ;
F_22 ( V_9 ) ;
if ( F_8 ( V_68 != sizeof( * V_6 ) ) )
goto V_42;
V_10 = - V_36 ;
if ( F_8 ( V_6 -> V_70 != V_71 ) )
goto V_42;
if ( F_8 ( V_9 -> V_14 != V_15 ) )
goto V_42;
V_10 = - V_83 ;
if ( F_8 ( V_8 -> V_22 == V_84 ) )
goto V_42;
if ( F_26 ( V_9 , V_48 ) ) {
V_10 = F_35 ( V_8 , V_6 ) ;
if ( V_10 )
goto V_42;
}
V_21 -> V_46 . V_45 = V_6 -> V_69 ;
memcpy ( V_21 -> V_46 . V_63 , V_6 -> V_72 , V_65 ) ;
V_8 -> V_22 = V_84 ;
V_9 -> V_79 = V_85 ;
V_21 -> V_86 = F_1 ( V_21 -> V_1 -> V_44 . V_45 ) ;
V_10 = F_52 ( V_9 , V_21 -> V_49 -> V_64 ,
V_6 -> V_72 , V_6 -> V_69 ) ;
if ( V_10 ) {
F_23 ( L_3 , V_43 ) ;
V_8 -> V_22 = V_87 ;
V_9 -> V_79 = V_88 ;
goto V_42;
}
if ( V_9 -> V_79 == V_85 ) {
const long V_89 = F_10 ( V_9 , V_82 & V_90 ) ;
if ( ! V_89 || ! F_53 ( V_9 , V_89 ) )
goto V_42;
V_10 = F_54 ( V_89 ) ;
if ( F_55 ( V_91 ) )
goto V_42;
}
if ( V_9 -> V_79 == V_88 )
goto V_92;
V_8 -> V_22 = V_93 ;
V_10 = 0 ;
V_42:
F_28 ( V_9 ) ;
return V_10 ;
V_92:
V_10 = V_92 ( V_9 ) ? : - V_94 ;
V_8 -> V_22 = V_87 ;
goto V_42;
}
static int F_56 ( struct V_26 * V_8 , int V_95 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
int V_10 = - V_57 ;
F_22 ( V_9 ) ;
if ( F_8 ( V_8 -> V_22 != V_87 ) )
goto V_42;
V_10 = - V_96 ;
if ( F_8 ( V_9 -> V_14 != V_15 ) )
goto V_42;
V_10 = - V_97 ;
if ( F_26 ( V_9 , V_48 ) )
goto V_42;
V_10 = 0 ;
if ( ! ( unsigned int ) V_95 )
V_95 = 1 ;
V_9 -> V_98 = V_95 ;
if ( V_9 -> V_79 != V_99 ) {
V_9 -> V_100 = 0 ;
V_9 -> V_79 = V_99 ;
}
V_9 -> V_101 -> V_82 |= V_102 ;
V_42:
F_28 ( V_9 ) ;
return V_10 ;
}
static int F_25 ( struct V_8 * V_9 , long V_25 )
{
F_57 ( V_103 ) ;
int V_10 = 0 ;
while ( 1 ) {
F_58 ( F_59 ( V_9 ) , & V_103 , V_104 ) ;
if ( F_60 ( V_9 , & V_25 , V_9 -> V_79 == V_88 ) )
break;
V_10 = - V_105 ;
if ( F_55 ( V_91 ) )
break;
V_10 = - V_97 ;
if ( ! V_25 )
break;
V_10 = 0 ;
}
F_61 ( F_59 ( V_9 ) , & V_103 ) ;
return V_10 ;
}
static int F_53 ( struct V_8 * V_9 , long V_25 )
{
F_57 ( V_103 ) ;
while ( 1 ) {
F_58 ( F_59 ( V_9 ) , & V_103 , V_104 ) ;
if ( F_60 ( V_9 , & V_25 , V_9 -> V_79 != V_85 ) )
break;
if ( F_55 ( V_91 ) || ! V_25 )
break;
}
F_61 ( F_59 ( V_9 ) , & V_103 ) ;
return V_25 ;
}
static int F_11 ( struct V_8 * V_9 , long V_25 )
{
F_57 ( V_103 ) ;
struct V_20 * V_21 = F_7 ( V_9 ) ;
int V_10 ;
while ( 1 ) {
F_58 ( F_59 ( V_9 ) , & V_103 , V_104 ) ;
V_10 = 0 ;
if ( F_60 ( V_9 , & V_25 ,
( V_9 -> V_106 & V_107 ) ||
( ! F_9 ( V_21 -> V_22 ) &&
! V_21 -> V_23 &&
! V_21 -> V_24 ) ) )
break;
V_10 = - V_105 ;
if ( F_55 ( V_91 ) )
break;
V_10 = - V_97 ;
if ( ! V_25 )
break;
}
F_61 ( F_59 ( V_9 ) , & V_103 ) ;
return V_10 ;
}
static int F_62 ( struct V_8 * V_9 , long V_89 )
{
int V_10 ;
while ( 1 ) {
V_10 = V_92 ( V_9 ) ;
if ( V_10 )
break;
V_10 = 0 ;
if ( V_9 -> V_106 & V_107 )
break;
V_10 = - V_97 ;
if ( ! V_89 )
break;
V_10 = F_54 ( V_89 ) ;
if ( F_55 ( V_91 ) )
break;
V_10 = 0 ;
if ( F_63 ( V_9 , & V_89 ) )
break;
}
return V_10 ;
}
static void F_64 ( struct V_108 * V_109 , struct V_17 * V_18 )
{
struct V_20 * V_21 = F_7 ( V_18 -> V_9 ) ;
if ( V_21 -> V_110 & V_111 ) {
struct V_112 V_113 ;
V_113 . V_114 = F_7 ( V_18 -> V_9 ) -> V_49 -> V_115 ;
F_65 ( V_18 , & V_113 . V_116 ) ;
F_66 ( V_18 , V_113 . V_117 ) ;
F_67 ( V_109 , V_118 , V_119 , sizeof( V_113 ) , & V_113 ) ;
}
}
static int F_68 ( struct V_26 * V_8 , struct V_26 * V_120 , int V_82 )
{
struct V_8 * V_9 = V_8 -> V_9 , * V_121 ;
struct V_20 * V_21 , * V_122 ;
struct V_17 * V_18 ;
int V_10 = - V_96 ;
F_23 ( L_4 , V_43 ,
F_7 ( V_9 ) -> V_44 . V_45 ) ;
F_22 ( V_9 ) ;
if ( F_8 ( V_9 -> V_14 != V_15 ) )
goto V_42;
V_10 = - V_57 ;
if ( F_8 ( V_8 -> V_22 != V_87 ||
V_9 -> V_79 != V_99 ) )
goto V_42;
if ( F_69 ( & V_9 -> V_123 ) ) {
V_10 = F_62 ( V_9 , V_9 -> V_47 ) ;
if ( V_10 )
goto V_42;
}
F_23 ( L_5 , V_43 ,
F_7 ( V_9 ) -> V_44 . V_45 ) ;
V_18 = F_70 ( & V_9 -> V_123 ) ;
V_10 = - V_57 ;
if ( ! V_18 -> V_9 )
goto V_124;
V_10 = 0 ;
V_121 = V_18 -> V_9 ;
F_13 ( V_120 , V_121 ) ;
F_40 ( V_121 , V_48 ) ;
V_121 -> V_79 = V_80 ;
V_120 -> V_22 = V_93 ;
V_21 = F_7 ( V_9 ) ;
V_122 = F_7 ( V_121 ) ;
memcpy ( & V_122 -> V_6 , & V_21 -> V_6 , sizeof( V_122 -> V_6 ) ) ;
V_122 -> V_86 = F_1 ( V_122 -> V_44 . V_45 ) ;
V_9 -> V_79 = V_99 ;
V_9 -> V_100 -- ;
F_23 ( L_6 , V_43 ,
F_7 ( V_9 ) -> V_6 . V_69 , V_122 -> V_46 . V_45 ) ;
V_124:
F_71 ( V_18 ) ;
V_42:
F_28 ( V_9 ) ;
return V_10 ;
}
static int F_72 ( struct V_125 * V_126 , struct V_26 * V_8 ,
struct V_108 * V_109 , T_4 V_127 , int V_82 )
{
struct V_5 * V_67 = (struct V_5 * ) V_109 -> V_128 ;
const int V_129 = V_82 & V_130 ;
struct V_17 * V_18 = NULL ;
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_20 * V_21 = F_7 ( V_9 ) ;
unsigned long V_131 ;
T_4 V_132 = 0 ;
T_5 V_133 = 0 ;
T_5 * V_134 ;
unsigned long V_135 ;
int V_136 ;
long V_89 ;
F_22 ( V_9 ) ;
V_132 = - V_78 ;
if ( F_8 ( V_9 -> V_14 == V_15 && V_9 -> V_79 == V_99 ) )
goto V_42;
V_89 = F_73 ( V_9 , V_129 ) ;
V_134 = & V_21 -> V_137 ;
if ( V_82 & V_138 ) {
V_133 = V_21 -> V_137 ;
V_134 = & V_133 ;
}
V_136 = F_74 ( V_9 , V_82 & V_139 , V_127 ) ;
V_132 = 0 ;
do {
T_5 V_140 ;
if ( F_55 ( V_91 ) ) {
if ( V_132 )
break;
V_132 = V_89 ? F_54 ( V_89 ) : - V_97 ;
break;
}
V_18 = F_75 ( & V_9 -> V_123 ) ;
if ( V_18 ) {
V_140 = * V_134 ;
goto V_141;
}
if ( V_132 >= V_136 && ! V_9 -> V_142 . V_143 )
break;
if ( V_132 ) {
if ( V_9 -> V_144 ||
V_9 -> V_79 == V_88 ||
( V_9 -> V_106 & V_107 ) ||
! V_89 ||
( V_82 & V_138 ) )
break;
} else {
if ( F_26 ( V_9 , V_145 ) )
break;
if ( V_9 -> V_144 ) {
V_132 = V_92 ( V_9 ) ;
break;
}
if ( V_9 -> V_106 & V_107 )
break;
if ( V_9 -> V_14 == V_15 && V_9 -> V_79 == V_88 ) {
if ( ! F_26 ( V_9 , V_145 ) ) {
V_132 = - V_78 ;
break;
}
break;
}
if ( ! V_89 ) {
V_132 = - V_97 ;
break;
}
}
if ( V_132 >= V_136 ) {
F_28 ( V_9 ) ;
F_22 ( V_9 ) ;
} else
F_63 ( V_9 , & V_89 ) ;
if ( ( V_82 & V_138 ) && V_133 != V_21 -> V_137 ) {
F_76 ( L_7 ,
V_91 -> V_146 ,
F_77 ( V_91 ) ) ;
V_133 = V_21 -> V_137 ;
}
continue;
V_141:
V_135 = V_18 -> V_127 - V_140 ;
if ( V_127 < V_135 )
V_135 = V_127 ;
if ( ! ( V_82 & V_147 ) ) {
int V_10 = F_78 ( V_18 , V_140 ,
V_109 -> V_148 , V_135 ) ;
if ( V_10 ) {
if ( ! V_132 )
V_132 = - V_149 ;
break;
}
}
* V_134 += V_135 ;
V_132 += V_135 ;
V_127 -= V_135 ;
if ( V_9 -> V_14 != V_15 )
goto V_150;
if ( ! ( V_82 & V_138 ) ) {
F_79 ( & V_9 -> V_123 . V_151 , V_131 ) ;
F_80 ( V_9 , V_18 , false ) ;
F_81 ( & V_9 -> V_123 . V_151 , V_131 ) ;
* V_134 = 0 ;
}
if ( V_135 + V_140 < V_18 -> V_127 )
continue;
} while ( V_127 > 0 );
V_42:
F_28 ( V_9 ) ;
return V_132 ;
V_150:
if ( V_67 != NULL && V_18 != NULL ) {
memcpy ( V_67 , F_82 ( V_18 ) , sizeof( * V_67 ) ) ;
V_109 -> V_152 = sizeof( * V_67 ) ;
}
if ( F_7 ( V_9 ) -> V_110 )
F_64 ( V_109 , V_18 ) ;
if ( ! ( V_82 & V_138 ) ) {
F_79 ( & V_9 -> V_123 . V_151 , V_131 ) ;
F_80 ( V_9 , V_18 , false ) ;
F_81 ( & V_9 -> V_123 . V_151 , V_131 ) ;
* V_134 = 0 ;
}
goto V_42;
}
static int F_83 ( struct V_125 * V_126 , struct V_26 * V_8 ,
struct V_108 * V_109 , T_4 V_127 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_20 * V_21 = F_7 ( V_9 ) ;
struct V_5 * V_6 = (struct V_5 * ) V_109 -> V_128 ;
int V_82 = V_109 -> V_153 ;
int V_19 = V_82 & V_130 ;
struct V_17 * V_18 ;
T_4 V_154 = 0 ;
int V_10 = - V_57 , V_132 = 0 , V_155 ;
F_23 ( L_8 , V_43 ,
V_21 -> V_44 . V_45 , V_21 -> V_46 . V_45 ) ;
F_22 ( V_9 ) ;
if ( V_6 ) {
if ( V_109 -> V_152 < sizeof( * V_6 ) )
goto V_156;
} else {
if ( F_4 ( & V_21 -> V_6 ) )
goto V_156;
V_6 = & V_21 -> V_6 ;
}
if ( F_26 ( V_9 , V_48 ) ) {
V_10 = F_35 ( V_8 , V_6 ) ;
if ( V_10 )
goto V_156;
}
V_155 = V_21 -> V_49 -> V_157 + F_5 ( V_9 , V_6 ) ;
V_154 = V_155 + V_127 ;
if ( V_154 > V_21 -> V_49 -> V_158 )
V_154 = V_21 -> V_49 -> V_158 ;
V_132 = V_154 - V_155 ;
F_28 ( V_9 ) ;
V_18 = F_84 ( V_9 , V_154 , V_19 , & V_10 ) ;
F_22 ( V_9 ) ;
if ( ! V_18 )
goto V_156;
V_18 -> V_49 = V_21 -> V_49 ;
V_18 -> V_30 = F_2 ( V_6 -> V_60 ) ;
F_85 ( V_18 , V_155 ) ;
V_10 = F_86 ( F_87 ( V_18 , V_132 ) , V_109 -> V_148 , V_132 ) ;
if ( V_10 )
goto V_42;
if ( V_9 -> V_14 == V_37 || V_6 -> V_159 ) {
F_88 ( V_21 -> V_1 , V_18 , V_6 -> V_72 ,
V_6 -> V_69 ) ;
goto V_42;
}
if ( V_6 -> V_12 ) {
F_89 ( V_21 -> V_1 , V_18 , V_6 -> V_72 ,
V_6 -> V_69 ) ;
goto V_42;
}
if ( V_6 -> V_13 ) {
F_90 ( V_21 -> V_1 , V_18 , V_6 -> V_72 ,
V_6 -> V_69 ) ;
goto V_42;
}
V_10 = - V_160 ;
if ( ! ( V_9 -> V_14 == V_15 && ! V_6 -> V_159 ) )
goto V_42;
V_10 = F_6 ( V_9 , V_18 , V_19 ) ;
V_42:
if ( V_10 ) {
F_71 ( V_18 ) ;
V_156:
F_23 ( L_9 ,
V_43 , V_21 -> V_44 . V_45 , V_21 -> V_46 . V_45 , V_10 ) ;
}
F_28 ( V_9 ) ;
return V_10 ? : V_132 ;
}
static int F_91 ( struct V_26 * V_8 , struct V_66 * V_67 ,
int * V_161 , int V_162 )
{
struct V_5 V_163 ;
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_20 * V_21 = F_7 ( V_9 ) ;
int V_10 = - V_164 ;
memset ( & V_163 , 0 , sizeof( V_163 ) ) ;
F_22 ( V_9 ) ;
if ( F_26 ( V_9 , V_48 ) )
goto V_42;
* V_161 = sizeof( V_163 ) ;
if ( V_162 ) {
V_10 = - V_78 ;
if ( V_9 -> V_79 != V_80 )
goto V_42;
if( V_21 -> V_49 )
V_163 . V_60 = V_21 -> V_49 -> type ;
V_163 . V_69 = V_21 -> V_46 . V_45 ;
memcpy ( & V_163 . V_72 , & V_21 -> V_46 . V_63 , V_65 ) ;
} else {
V_10 = - V_57 ;
if ( ! V_21 -> V_1 )
goto V_42;
V_163 . V_69 = V_21 -> V_1 -> V_44 . V_45 ;
if ( V_21 -> V_49 ) {
V_163 . V_60 = V_21 -> V_49 -> type ;
memcpy ( & V_163 . V_72 , V_21 -> V_49 -> V_64 ,
V_65 ) ;
}
}
V_10 = 0 ;
V_163 . V_70 = V_71 ;
memcpy ( V_67 , & V_163 , sizeof( V_163 ) ) ;
V_42:
F_28 ( V_9 ) ;
return V_10 ;
}
static int F_92 ( struct V_26 * V_8 , unsigned int V_165 ,
unsigned long V_166 )
{
return - V_167 ;
}
static int F_93 ( struct V_26 * V_8 , int V_168 , int V_169 ,
char T_6 * V_170 , unsigned int V_171 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_20 * V_21 = F_7 ( V_9 ) ;
unsigned int V_172 ;
int V_10 = - V_57 ;
F_22 ( V_9 ) ;
if ( F_8 ( V_168 != V_118 || V_171 != sizeof( int ) ) )
goto V_42;
V_10 = F_94 ( V_172 , ( int T_6 * ) V_170 ) ;
if ( V_10 )
goto V_42;
V_10 = - V_57 ;
switch ( V_169 ) {
case V_173 :
if ( V_172 > V_174 )
goto V_42;
V_21 -> V_175 = V_172 ;
break;
case V_176 :
if ( V_172 > V_177 )
goto V_42;
V_21 -> V_178 = V_172 ;
break;
case V_179 :
if ( V_172 > V_180 )
goto V_42;
V_21 -> V_181 . V_182 = V_172 * V_183 ;
break;
case V_184 :
if ( V_172 > V_185 )
goto V_42;
V_21 -> V_186 . V_182 = V_172 * V_183 ;
break;
case V_187 :
if ( V_172 > V_188 )
goto V_42;
V_21 -> V_189 . V_182 = V_172 * V_183 ;
break;
case V_190 :
if ( V_172 > V_191 )
goto V_42;
V_21 -> V_192 . V_182 = V_172 * V_183 ;
break;
case V_193 :
if ( V_172 > V_194 )
goto V_42;
V_21 -> V_195 = V_172 ;
break;
case V_196 :
if ( V_172 > V_194 )
goto V_42;
V_21 -> V_197 = V_172 ;
break;
case V_119 :
if ( V_172 )
V_21 -> V_110 |= V_111 ;
else
V_21 -> V_110 &= ~ V_111 ;
break;
default:
V_10 = - V_160 ;
goto V_42;
}
V_10 = 0 ;
V_42:
F_28 ( V_9 ) ;
return V_10 ;
}
static int F_95 ( struct V_26 * V_8 , int V_168 , int V_169 ,
char T_6 * V_170 , int T_6 * V_171 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_20 * V_21 = F_7 ( V_9 ) ;
int V_198 = 0 , V_127 = 0 , V_10 = - V_57 ;
F_22 ( V_9 ) ;
if ( F_8 ( V_168 != V_118 ) )
goto V_42;
V_10 = F_94 ( V_127 , V_171 ) ;
if ( V_10 )
goto V_42;
V_10 = - V_57 ;
if ( V_127 != sizeof( int ) )
goto V_42;
switch ( V_169 ) {
case V_173 :
V_198 = V_21 -> V_175 ; break;
case V_176 :
V_198 = V_21 -> V_178 ; break;
case V_179 :
V_198 = V_21 -> V_181 . V_182 / V_183 ; break;
case V_184 :
V_198 = V_21 -> V_186 . V_182 / V_183 ; break;
case V_187 :
V_198 = V_21 -> V_189 . V_182 / V_183 ; break;
case V_190 :
V_198 = V_21 -> V_192 . V_182 / V_183 ; break;
case V_193 :
V_198 = V_21 -> V_195 ; break;
case V_196 :
V_198 = V_21 -> V_197 ; break;
case V_119 :
V_198 = ( V_21 -> V_110 & V_111 ) != 0 ;
break;
default:
V_10 = - V_160 ;
goto V_42;
}
V_10 = 0 ;
if ( F_96 ( V_127 , V_171 ) || F_97 ( V_170 , & V_198 , V_127 ) )
V_10 = - V_149 ;
V_42:
F_28 ( V_9 ) ;
return V_10 ;
}
static int T_7 F_98 ( void )
{
int V_10 = F_99 ( & V_41 , 0 ) ;
if ( V_10 != 0 )
goto V_42;
F_100 () ;
F_101 () ;
V_54 = V_56 ;
V_10 = F_102 () ;
if ( V_10 != 0 ) {
F_103 ( V_199 ) ;
goto V_200;
}
V_10 = F_104 () ;
if ( V_10 ) {
F_103 ( V_201 ) ;
goto V_202;
}
V_10 = F_105 ( & V_203 ) ;
if ( V_10 ) {
F_103 ( V_204 ) ;
goto V_205;
}
F_106 ( V_206 , V_207 ) ;
F_106 ( V_208 , V_209 ) ;
V_42:
return V_10 ;
V_205:
F_107 () ;
V_202:
F_108 () ;
V_200:
F_109 () ;
F_110 ( & V_41 ) ;
goto V_42;
}
static void T_8 F_111 ( void )
{
F_109 () ;
F_112 ( V_206 ) ;
F_112 ( V_208 ) ;
F_113 ( V_39 ) ;
F_108 () ;
F_107 () ;
F_110 ( & V_41 ) ;
}
