static struct V_1 * F_1 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_1 ;
int V_7 ;
V_1 = F_3 ( V_8 , V_9 ) ;
if ( ! V_1 )
return NULL ;
V_1 -> V_2 = V_2 ;
V_1 -> V_5 = V_6 ;
V_1 -> V_10 = V_11 + F_4 ( V_12 ) ;
F_5 ( V_9 ) ;
F_6 ( & V_6 -> V_13 ) ;
V_7 = F_7 ( & V_6 -> V_14 , V_1 , 0 ,
V_15 , V_16 ) ;
F_8 ( & V_6 -> V_13 ) ;
F_9 () ;
if ( V_7 < 0 ) {
F_10 ( V_8 , V_1 ) ;
return NULL ;
}
V_1 -> V_7 = V_7 ;
return V_1 ;
}
static inline void F_11 ( void * V_17 , T_1 V_18 )
{
unsigned long V_19 = F_12 ( V_17 ) ;
V_18 = F_13 ( V_18 + V_19 , V_20 ) ;
V_17 -= V_19 ;
while ( V_18 ) {
F_14 ( F_15 ( V_17 ) ) ;
V_18 -= V_20 ;
}
}
static inline T_1 F_16 ( T_1 V_21 , T_1 V_22 , T_1 V_18 )
{
int V_23 = V_21 - V_22 ;
if ( V_23 >= 0 )
return V_23 ;
else
return V_18 + V_23 ;
}
static inline T_1 F_17 ( T_1 V_21 , T_1 V_22 , T_1 V_18 )
{
return ( V_18 - F_16 ( V_21 , V_22 , V_18 ) - 1 ) ;
}
static inline T_1 F_18 ( T_1 V_21 , T_1 V_18 )
{
return V_18 - V_21 ;
}
static inline void F_19 ( struct V_24 * * V_25 , int * V_26 ,
struct V_5 * V_6 )
{
struct V_24 * V_24 ;
if ( * V_26 != 0 )
( * V_25 ) ++ ;
( * V_26 ) ++ ;
V_24 = * V_25 ;
memset ( V_24 , 0 , sizeof( struct V_24 ) ) ;
}
static inline T_1 F_20 ( struct V_5 * V_27 ,
int V_28 , int V_29 )
{
return V_27 -> V_30 + V_28 * V_31 +
V_31 - V_29 ;
}
static inline T_1 F_21 ( struct V_5 * V_6 , struct V_24 * V_25 )
{
return ( T_1 ) V_25 -> V_32 + V_25 -> V_33 ;
}
static void F_22 ( struct V_5 * V_6 ,
struct V_34 * V_35 , unsigned int V_36 ,
struct V_24 * * V_25 , int * V_26 , bool V_37 )
{
int V_38 , V_28 ;
int V_39 = 0 ;
void * V_40 , * V_41 ;
T_1 V_42 , V_43 ;
struct V_34 * V_44 ;
F_23 (data_sg, sg, data_nents, i) {
int V_45 = V_44 -> V_46 ;
V_40 = F_24 ( F_25 ( V_44 ) ) + V_44 -> V_19 ;
while ( V_45 > 0 ) {
if ( V_39 == 0 ) {
V_28 = F_26 ( V_6 -> V_47 ,
V_48 ) ;
V_39 = V_31 ;
F_27 ( V_28 , V_6 -> V_47 ) ;
}
V_42 = F_28 ( T_1 , V_45 ,
V_39 ) ;
V_43 = F_20 ( V_6 , V_28 ,
V_39 ) ;
V_41 = ( void * ) V_6 -> V_49 + V_43 ;
if ( * V_26 != 0 &&
V_43 == F_21 ( V_6 , * V_25 ) ) {
( * V_25 ) -> V_33 += V_42 ;
} else {
F_19 ( V_25 , V_26 , V_6 ) ;
( * V_25 ) -> V_32 = ( void V_50 * ) V_43 ;
( * V_25 ) -> V_33 = V_42 ;
}
if ( V_37 ) {
memcpy ( V_41 , V_40 + V_44 -> V_46 - V_45 ,
V_42 ) ;
F_11 ( V_41 , V_42 ) ;
}
V_45 -= V_42 ;
V_39 -= V_42 ;
}
F_29 ( V_40 - V_44 -> V_19 ) ;
}
}
static void F_30 ( struct V_5 * V_6 , struct V_1 * V_51 )
{
F_31 ( V_6 -> V_47 , V_6 -> V_47 , V_51 -> V_47 ,
V_48 ) ;
}
static void F_32 ( struct V_5 * V_6 , unsigned long * V_52 ,
struct V_34 * V_35 , unsigned int V_36 )
{
int V_38 , V_28 ;
int V_39 = 0 ;
void * V_40 , * V_41 ;
T_1 V_42 , V_53 ;
struct V_34 * V_44 ;
F_23 (data_sg, sg, data_nents, i) {
int V_45 = V_44 -> V_46 ;
V_41 = F_24 ( F_25 ( V_44 ) ) + V_44 -> V_19 ;
while ( V_45 > 0 ) {
if ( V_39 == 0 ) {
V_28 = F_33 ( V_52 ,
V_48 ) ;
V_39 = V_31 ;
F_34 ( V_28 , V_52 ) ;
}
V_42 = F_28 ( T_1 , V_45 ,
V_39 ) ;
V_53 = F_20 ( V_6 , V_28 ,
V_39 ) ;
V_40 = ( void * ) V_6 -> V_49 + V_53 ;
F_11 ( V_40 , V_42 ) ;
memcpy ( V_41 + V_44 -> V_46 - V_45 , V_40 ,
V_42 ) ;
V_45 -= V_42 ;
V_39 -= V_42 ;
}
F_29 ( V_41 - V_44 -> V_19 ) ;
}
}
static inline T_1 F_35 ( unsigned long * V_54 )
{
return V_31 * ( V_48 -
F_36 ( V_54 , V_48 ) ) ;
}
static bool F_37 ( struct V_5 * V_6 , T_1 V_55 , T_1 V_56 )
{
struct V_57 * V_58 = V_6 -> V_49 ;
T_1 V_59 , V_60 ;
T_2 V_61 ;
F_11 ( V_58 , sizeof( * V_58 ) ) ;
V_61 = V_58 -> V_61 % V_6 -> V_62 ;
if ( F_18 ( V_61 , V_6 -> V_62 ) >= V_55 )
V_60 = V_55 ;
else
V_60 = V_55 + F_18 ( V_61 , V_6 -> V_62 ) ;
V_59 = F_17 ( V_61 , V_6 -> V_63 , V_6 -> V_62 ) ;
if ( V_59 < V_60 ) {
F_38 ( L_1 , V_61 ,
V_6 -> V_63 , V_6 -> V_62 ) ;
return false ;
}
V_59 = F_35 ( V_6 -> V_47 ) ;
if ( V_59 < V_56 ) {
F_38 ( L_2 ,
V_59 , V_56 ) ;
return false ;
}
return true ;
}
static int F_39 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_5 ;
struct V_2 * V_2 = V_1 -> V_2 ;
T_1 V_64 , V_65 ;
struct V_57 * V_58 ;
struct V_66 * V_67 ;
struct V_24 * V_25 ;
int V_26 ;
T_3 V_61 ;
T_4 V_68 ;
bool V_69 ;
T_1 V_70 ;
F_40 ( V_71 , V_48 ) ;
if ( F_41 ( V_72 , & V_6 -> V_73 ) )
return - V_74 ;
V_64 = F_42 ( F_43 ( struct V_66 ,
V_75 . V_25 [ V_2 -> V_76 +
V_2 -> V_77 ] ) ,
sizeof( struct V_66 ) ) ;
V_65 = V_64
+ F_13 ( F_44 ( V_2 -> V_78 ) , V_79 ) ;
F_45 ( V_65 & ( V_79 - 1 ) ) ;
F_6 ( & V_6 -> V_80 ) ;
V_58 = V_6 -> V_49 ;
V_61 = V_58 -> V_61 % V_6 -> V_62 ;
V_70 = V_2 -> V_70 ;
if ( V_2 -> V_81 & V_82 ) {
F_46 ( ! ( V_2 -> V_83 && V_2 -> V_76 ) ) ;
V_70 += V_2 -> V_83 -> V_46 ;
}
if ( ( V_65 > ( V_6 -> V_62 / 2 ) )
|| V_70 > V_6 -> V_84 )
F_47 ( L_3
L_4 , V_65 , V_70 ,
V_6 -> V_62 , V_6 -> V_84 ) ;
while ( ! F_37 ( V_6 , V_65 , V_70 ) ) {
int V_85 ;
F_48 ( V_86 ) ;
F_49 ( & V_6 -> V_87 , & V_86 , V_88 ) ;
F_38 ( L_5 ) ;
F_8 ( & V_6 -> V_80 ) ;
V_85 = F_50 ( F_4 ( V_12 ) ) ;
F_51 ( & V_6 -> V_87 , & V_86 ) ;
if ( ! V_85 ) {
F_47 ( L_6 ) ;
return - V_89 ;
}
F_6 ( & V_6 -> V_80 ) ;
V_61 = V_58 -> V_61 % V_6 -> V_62 ;
}
if ( F_18 ( V_61 , V_6 -> V_62 ) < V_65 ) {
T_1 V_90 = F_18 ( V_61 , V_6 -> V_62 ) ;
V_67 = ( void * ) V_58 + V_91 + V_61 ;
F_11 ( V_67 , sizeof( * V_67 ) ) ;
F_52 ( & V_67 -> V_92 . V_93 , V_94 ) ;
F_53 ( & V_67 -> V_92 . V_93 , V_90 ) ;
V_67 -> V_92 . V_7 = 0 ;
V_67 -> V_92 . V_95 = 0 ;
V_67 -> V_92 . V_96 = 0 ;
F_54 ( V_58 -> V_61 , V_90 , V_6 -> V_62 ) ;
V_61 = V_58 -> V_61 % V_6 -> V_62 ;
F_45 ( V_61 != 0 ) ;
}
V_67 = ( void * ) V_58 + V_91 + V_61 ;
F_11 ( V_67 , sizeof( * V_67 ) ) ;
F_52 ( & V_67 -> V_92 . V_93 , V_97 ) ;
F_53 ( & V_67 -> V_92 . V_93 , V_65 ) ;
V_67 -> V_92 . V_7 = V_1 -> V_7 ;
V_67 -> V_92 . V_95 = 0 ;
V_67 -> V_92 . V_96 = 0 ;
F_55 ( V_71 , V_6 -> V_47 , V_48 ) ;
V_25 = & V_67 -> V_75 . V_25 [ 0 ] ;
V_26 = 0 ;
V_69 = ( V_2 -> V_98 == V_99
|| V_2 -> V_81 & V_82 ) ;
F_22 ( V_6 , V_2 -> V_100 ,
V_2 -> V_77 , & V_25 , & V_26 , V_69 ) ;
V_67 -> V_75 . V_26 = V_26 ;
V_67 -> V_75 . V_101 = 0 ;
V_26 = 0 ;
F_22 ( V_6 , V_2 -> V_83 ,
V_2 -> V_76 , & V_25 , & V_26 , false ) ;
V_67 -> V_75 . V_102 = V_26 ;
F_31 ( V_1 -> V_47 , V_71 , V_6 -> V_47 ,
V_48 ) ;
V_68 = V_91 + V_61 + V_64 ;
memcpy ( ( void * ) V_58 + V_68 , V_2 -> V_78 , F_44 ( V_2 -> V_78 ) ) ;
V_67 -> V_75 . V_68 = V_68 ;
F_11 ( V_67 , sizeof( * V_67 ) ) ;
F_54 ( V_58 -> V_61 , V_65 , V_6 -> V_62 ) ;
F_11 ( V_58 , sizeof( * V_58 ) ) ;
F_8 ( & V_6 -> V_80 ) ;
F_56 ( & V_6 -> V_103 ) ;
F_57 ( & V_6 -> V_104 ,
F_58 ( V_11 + F_4 ( V_12 ) ) ) ;
return 0 ;
}
static int F_59 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_1 ;
int V_85 ;
V_1 = F_1 ( V_2 ) ;
if ( ! V_1 )
return - V_105 ;
V_85 = F_39 ( V_1 ) ;
if ( V_85 < 0 ) {
F_60 ( L_7 ) ;
F_6 ( & V_6 -> V_13 ) ;
F_61 ( & V_6 -> V_14 , V_1 -> V_7 ) ;
F_8 ( & V_6 -> V_13 ) ;
F_10 ( V_8 , V_1 ) ;
}
return V_85 ;
}
static void F_62 ( struct V_1 * V_51 , struct V_66 * V_67 )
{
struct V_2 * V_2 = V_51 -> V_2 ;
struct V_5 * V_6 = V_51 -> V_5 ;
if ( F_41 ( V_106 , & V_51 -> V_73 ) ) {
F_30 ( V_6 , V_51 ) ;
F_10 ( V_8 , V_51 ) ;
return;
}
if ( V_67 -> V_92 . V_96 & V_107 ) {
F_30 ( V_6 , V_51 ) ;
F_47 ( L_8 ,
V_51 -> V_2 ) ;
V_67 -> V_108 . V_109 = V_110 ;
} else if ( V_67 -> V_108 . V_109 == V_110 ) {
memcpy ( V_2 -> V_111 , V_67 -> V_108 . V_111 ,
V_2 -> V_112 ) ;
F_30 ( V_6 , V_51 ) ;
} else if ( V_2 -> V_81 & V_82 ) {
F_40 ( V_54 , V_48 ) ;
F_55 ( V_54 , V_51 -> V_47 , V_48 ) ;
F_32 ( V_6 , V_54 ,
V_2 -> V_83 , V_2 -> V_76 ) ;
F_30 ( V_6 , V_51 ) ;
} else if ( V_2 -> V_98 == V_113 ) {
F_40 ( V_54 , V_48 ) ;
F_55 ( V_54 , V_51 -> V_47 , V_48 ) ;
F_32 ( V_6 , V_54 ,
V_2 -> V_100 , V_2 -> V_77 ) ;
F_30 ( V_6 , V_51 ) ;
} else if ( V_2 -> V_98 == V_99 ) {
F_30 ( V_6 , V_51 ) ;
} else if ( V_2 -> V_98 != V_114 ) {
F_47 ( L_9 ,
V_2 -> V_98 ) ;
}
F_63 ( V_51 -> V_2 , V_67 -> V_108 . V_109 ) ;
V_51 -> V_2 = NULL ;
F_10 ( V_8 , V_51 ) ;
}
static unsigned int F_64 ( struct V_5 * V_6 )
{
struct V_57 * V_58 ;
unsigned long V_73 ;
int V_115 = 0 ;
if ( F_41 ( V_72 , & V_6 -> V_73 ) ) {
F_60 ( L_10 ) ;
return 0 ;
}
F_65 ( & V_6 -> V_80 , V_73 ) ;
V_58 = V_6 -> V_49 ;
F_11 ( V_58 , sizeof( * V_58 ) ) ;
while ( V_6 -> V_63 != F_66 ( V_58 -> V_116 ) ) {
struct V_66 * V_67 = ( void * ) V_58 + V_91 + V_6 -> V_63 ;
struct V_1 * V_51 ;
F_11 ( V_67 , sizeof( * V_67 ) ) ;
if ( F_67 ( V_67 -> V_92 . V_93 ) == V_94 ) {
F_54 ( V_6 -> V_63 ,
F_68 ( V_67 -> V_92 . V_93 ) ,
V_6 -> V_62 ) ;
continue;
}
F_45 ( F_67 ( V_67 -> V_92 . V_93 ) != V_97 ) ;
F_69 ( & V_6 -> V_13 ) ;
V_51 = F_70 ( & V_6 -> V_14 , V_67 -> V_92 . V_7 ) ;
if ( V_51 )
F_61 ( & V_6 -> V_14 , V_51 -> V_7 ) ;
F_71 ( & V_6 -> V_13 ) ;
if ( ! V_51 ) {
F_60 ( L_11 ) ;
F_27 ( V_72 , & V_6 -> V_73 ) ;
break;
}
F_62 ( V_51 , V_67 ) ;
F_54 ( V_6 -> V_63 ,
F_68 ( V_67 -> V_92 . V_93 ) ,
V_6 -> V_62 ) ;
V_115 ++ ;
}
if ( V_58 -> V_116 == V_58 -> V_61 )
F_72 ( & V_6 -> V_104 ) ;
F_73 ( & V_6 -> V_80 , V_73 ) ;
F_74 ( & V_6 -> V_87 ) ;
return V_115 ;
}
static int F_75 ( int V_117 , void * V_118 , void * V_119 )
{
struct V_1 * V_51 = V_118 ;
if ( F_41 ( V_106 , & V_51 -> V_73 ) )
return 0 ;
if ( ! F_76 ( V_11 , V_51 -> V_10 ) )
return 0 ;
F_27 ( V_106 , & V_51 -> V_73 ) ;
F_63 ( V_51 -> V_2 , V_110 ) ;
V_51 -> V_2 = NULL ;
F_10 ( V_8 , V_51 ) ;
return 0 ;
}
static void F_77 ( unsigned long V_119 )
{
struct V_5 * V_6 = (struct V_5 * ) V_119 ;
unsigned long V_73 ;
int V_115 ;
V_115 = F_64 ( V_6 ) ;
F_47 ( L_12 , V_115 ) ;
F_65 ( & V_6 -> V_13 , V_73 ) ;
F_78 ( & V_6 -> V_14 , F_75 , NULL ) ;
F_73 ( & V_6 -> V_13 , V_73 ) ;
}
static int F_79 ( struct V_120 * V_121 , T_2 V_122 )
{
struct V_123 * V_123 ;
V_123 = F_80 ( sizeof( struct V_123 ) , V_9 ) ;
if ( ! V_123 )
return - V_105 ;
V_123 -> V_122 = V_122 ;
V_121 -> V_124 = V_123 ;
return 0 ;
}
static void F_81 ( struct V_120 * V_121 )
{
F_82 ( V_121 -> V_124 ) ;
V_121 -> V_124 = NULL ;
}
static struct V_3 * F_83 ( struct V_120 * V_121 , const char * V_125 )
{
struct V_5 * V_6 ;
V_6 = F_80 ( sizeof( struct V_5 ) , V_9 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_125 = F_84 ( V_125 , V_9 ) ;
if ( ! V_6 -> V_125 ) {
F_82 ( V_6 ) ;
return NULL ;
}
V_6 -> V_121 = V_121 ;
F_85 ( & V_6 -> V_87 ) ;
F_86 ( & V_6 -> V_80 ) ;
F_87 ( & V_6 -> V_14 ) ;
F_86 ( & V_6 -> V_13 ) ;
F_88 ( & V_6 -> V_104 , F_77 ,
( unsigned long ) V_6 ) ;
return & V_6 -> V_4 ;
}
static int F_89 ( struct V_103 * V_126 , T_5 V_127 )
{
struct V_5 * V_5 = F_90 ( V_126 , struct V_5 , V_103 ) ;
F_64 ( V_5 ) ;
return 0 ;
}
static int F_91 ( struct V_128 * V_129 )
{
struct V_5 * V_6 = V_129 -> V_130 ;
struct V_103 * V_126 = & V_6 -> V_103 ;
if ( V_129 -> V_131 < V_132 ) {
if ( V_126 -> V_133 [ V_129 -> V_131 ] . V_18 == 0 )
return - 1 ;
return ( int ) V_129 -> V_131 ;
}
return - 1 ;
}
static int F_92 ( struct V_128 * V_129 , struct V_134 * V_135 )
{
struct V_5 * V_6 = V_129 -> V_130 ;
struct V_103 * V_126 = & V_6 -> V_103 ;
struct V_136 * V_136 ;
unsigned long V_19 ;
void * V_137 ;
int V_138 = F_91 ( V_129 ) ;
if ( V_138 < 0 )
return V_139 ;
V_19 = ( V_135 -> V_140 - V_138 ) << V_141 ;
V_137 = ( void * ) ( unsigned long ) V_126 -> V_133 [ V_138 ] . V_137 + V_19 ;
if ( V_126 -> V_133 [ V_138 ] . V_142 == V_143 )
V_136 = F_15 ( V_137 ) ;
else
V_136 = F_93 ( V_137 ) ;
F_94 ( V_136 ) ;
V_135 -> V_136 = V_136 ;
return 0 ;
}
static int F_95 ( struct V_103 * V_126 , struct V_128 * V_129 )
{
struct V_5 * V_6 = F_90 ( V_126 , struct V_5 , V_103 ) ;
V_129 -> V_144 |= V_145 | V_146 ;
V_129 -> V_147 = & V_148 ;
V_129 -> V_130 = V_6 ;
if ( F_96 ( V_129 ) != ( V_149 >> V_141 ) )
return - V_74 ;
return 0 ;
}
static int F_97 ( struct V_103 * V_126 , struct V_150 * V_150 )
{
struct V_5 * V_6 = F_90 ( V_126 , struct V_5 , V_103 ) ;
if ( F_98 ( V_151 , & V_6 -> V_73 ) )
return - V_152 ;
F_38 ( L_13 ) ;
return 0 ;
}
static int F_99 ( struct V_103 * V_126 , struct V_150 * V_150 )
{
struct V_5 * V_6 = F_90 ( V_126 , struct V_5 , V_103 ) ;
F_34 ( V_151 , & V_6 -> V_73 ) ;
F_38 ( L_14 ) ;
return 0 ;
}
static int F_100 ( enum V_153 V_51 , const char * V_125 , int V_154 )
{
struct V_155 * V_156 ;
void * V_157 ;
int V_85 = - V_105 ;
V_156 = F_101 ( V_158 , V_9 ) ;
if ( ! V_156 )
return V_85 ;
V_157 = F_102 ( V_156 , 0 , 0 , & V_159 , 0 , V_51 ) ;
if ( ! V_157 )
goto V_160;
V_85 = F_103 ( V_156 , V_161 , V_125 ) ;
if ( V_85 < 0 )
goto V_160;
V_85 = F_104 ( V_156 , V_162 , V_154 ) ;
if ( V_85 < 0 )
goto V_160;
F_105 ( V_156 , V_157 ) ;
V_85 = F_106 ( & V_159 , V_156 , 0 ,
V_163 , V_9 ) ;
if ( V_85 == - V_164 )
V_85 = 0 ;
return V_85 ;
V_160:
F_107 ( V_156 ) ;
return V_85 ;
}
static int F_108 ( struct V_3 * V_27 )
{
struct V_5 * V_6 = F_2 ( V_27 ) ;
struct V_123 * V_121 = V_6 -> V_121 -> V_124 ;
struct V_103 * V_126 ;
struct V_57 * V_58 ;
T_1 V_18 ;
T_1 V_165 ;
int V_85 = 0 ;
char * V_166 ;
V_126 = & V_6 -> V_103 ;
V_18 = snprintf ( NULL , 0 , L_15 , V_121 -> V_122 , V_6 -> V_125 ,
V_6 -> V_167 ) ;
V_18 += 1 ;
V_166 = F_109 ( V_18 , V_9 ) ;
if ( ! V_166 )
return - V_105 ;
V_165 = snprintf ( V_166 , V_18 , L_16 , V_121 -> V_122 , V_6 -> V_125 ) ;
if ( V_6 -> V_167 [ 0 ] )
snprintf ( V_166 + V_165 , V_18 - V_165 , L_17 , V_6 -> V_167 ) ;
V_126 -> V_125 = V_166 ;
V_6 -> V_49 = F_110 ( V_149 ) ;
if ( ! V_6 -> V_49 ) {
V_85 = - V_105 ;
goto V_168;
}
V_6 -> V_62 = V_169 - V_91 ;
V_6 -> V_30 = V_169 ;
V_6 -> V_84 = V_149 - V_169 ;
V_58 = V_6 -> V_49 ;
V_58 -> V_170 = V_171 ;
V_58 -> V_73 = V_172 ;
V_58 -> V_173 = V_91 ;
V_58 -> V_62 = V_6 -> V_62 ;
F_45 ( ! F_111 ( V_6 -> V_30 ) ) ;
F_45 ( V_6 -> V_84 % V_20 ) ;
F_45 ( V_6 -> V_84 % V_31 ) ;
V_126 -> V_170 = F_112 ( V_171 ) ;
V_126 -> V_133 [ 0 ] . V_125 = L_18 ;
V_126 -> V_133 [ 0 ] . V_137 = ( V_174 ) ( V_175 ) V_6 -> V_49 ;
V_126 -> V_133 [ 0 ] . V_18 = V_149 ;
V_126 -> V_133 [ 0 ] . V_142 = V_176 ;
V_126 -> V_177 = F_89 ;
V_126 -> V_178 = V_179 ;
V_126 -> V_180 = F_95 ;
V_126 -> V_181 = F_97 ;
V_126 -> V_182 = F_99 ;
V_85 = F_113 ( V_183 , V_126 ) ;
if ( V_85 )
goto V_184;
if ( V_27 -> V_185 . V_186 == 0 )
V_27 -> V_185 . V_186 = 512 ;
V_27 -> V_185 . V_187 = 128 ;
V_27 -> V_185 . V_188 = 128 ;
V_85 = F_100 ( V_189 , V_6 -> V_103 . V_125 ,
V_6 -> V_103 . V_190 -> V_154 ) ;
if ( V_85 )
goto V_191;
return 0 ;
V_191:
F_114 ( & V_6 -> V_103 ) ;
V_184:
F_115 ( V_6 -> V_49 ) ;
V_168:
F_82 ( V_126 -> V_125 ) ;
return V_85 ;
}
static int F_116 ( struct V_1 * V_51 )
{
if ( F_41 ( V_106 , & V_51 -> V_73 ) ) {
F_10 ( V_8 , V_51 ) ;
return 0 ;
}
return - V_74 ;
}
static void F_117 ( struct V_192 * V_118 )
{
struct V_3 * V_27 = F_90 ( V_118 , struct V_3 , V_192 ) ;
struct V_5 * V_6 = F_2 ( V_27 ) ;
F_82 ( V_6 ) ;
}
static void F_118 ( struct V_3 * V_27 )
{
struct V_5 * V_6 = F_2 ( V_27 ) ;
struct V_1 * V_51 ;
bool V_193 = true ;
int V_38 ;
F_119 ( & V_6 -> V_104 ) ;
F_115 ( V_6 -> V_49 ) ;
F_6 ( & V_6 -> V_13 ) ;
F_120 (&udev->commands, cmd, i) {
if ( F_116 ( V_51 ) != 0 )
V_193 = false ;
}
F_121 ( & V_6 -> V_14 ) ;
F_8 ( & V_6 -> V_13 ) ;
F_45 ( ! V_193 ) ;
if ( V_6 -> V_103 . V_190 ) {
F_100 ( V_194 , V_6 -> V_103 . V_125 ,
V_6 -> V_103 . V_190 -> V_154 ) ;
F_114 ( & V_6 -> V_103 ) ;
F_82 ( V_6 -> V_103 . V_125 ) ;
F_82 ( V_6 -> V_125 ) ;
}
F_122 ( & V_27 -> V_192 , F_117 ) ;
}
static T_6 F_123 ( struct V_3 * V_27 ,
const char * V_136 , T_6 V_195 )
{
struct V_5 * V_6 = F_2 ( V_27 ) ;
char * V_196 , * V_197 , * V_198 , * V_199 ;
T_7 args [ V_200 ] ;
int V_85 = 0 , V_201 ;
unsigned long V_202 ;
V_198 = F_84 ( V_136 , V_9 ) ;
if ( ! V_198 )
return - V_105 ;
V_196 = V_198 ;
while ( ( V_197 = F_124 ( & V_198 , L_19 ) ) != NULL ) {
if ( ! * V_197 )
continue;
V_201 = F_125 ( V_197 , V_203 , args ) ;
switch ( V_201 ) {
case V_204 :
if ( F_126 ( V_6 -> V_167 , & args [ 0 ] ,
V_205 ) == 0 ) {
V_85 = - V_74 ;
break;
}
F_38 ( L_20 , V_6 -> V_167 ) ;
break;
case V_206 :
V_199 = F_127 ( & args [ 0 ] ) ;
if ( ! V_199 ) {
V_85 = - V_105 ;
break;
}
V_85 = F_128 ( V_199 , 0 , ( unsigned long * ) & V_6 -> V_207 ) ;
F_82 ( V_199 ) ;
if ( V_85 < 0 )
F_60 ( L_21 ) ;
break;
case V_208 :
V_199 = F_127 ( & args [ 0 ] ) ;
if ( ! V_199 ) {
V_85 = - V_105 ;
break;
}
V_85 = F_128 ( V_199 , 0 , & V_202 ) ;
F_82 ( V_199 ) ;
if ( V_85 < 0 ) {
F_60 ( L_22 ) ;
break;
}
if ( ! V_202 ) {
F_60 ( L_23 ) ;
break;
}
V_27 -> V_185 . V_186 = V_202 ;
break;
default:
break;
}
}
F_82 ( V_196 ) ;
return ( ! V_85 ) ? V_195 : V_85 ;
}
static T_6 F_129 ( struct V_3 * V_27 , char * V_209 )
{
struct V_5 * V_6 = F_2 ( V_27 ) ;
T_6 V_210 = 0 ;
V_210 = sprintf ( V_209 + V_210 , L_24 ,
V_6 -> V_167 [ 0 ] ? V_6 -> V_167 : L_25 ) ;
V_210 += sprintf ( V_209 + V_210 , L_26 , V_6 -> V_207 ) ;
return V_210 ;
}
static T_8 F_130 ( struct V_3 * V_27 )
{
struct V_5 * V_6 = F_2 ( V_27 ) ;
return F_131 ( V_6 -> V_207 - V_27 -> V_185 . V_211 ,
V_27 -> V_185 . V_211 ) ;
}
static T_9
F_132 ( struct V_2 * V_2 )
{
int V_85 = F_59 ( V_2 ) ;
if ( V_85 != 0 )
return V_212 ;
else
return V_213 ;
}
static T_9
F_133 ( struct V_2 * V_51 )
{
return F_134 ( V_51 , F_132 ) ;
}
static int T_10 F_135 ( void )
{
int V_85 ;
F_136 ( ( sizeof( struct V_66 ) % V_79 ) != 0 ) ;
V_8 = F_137 ( L_27 ,
sizeof( struct V_1 ) ,
F_138 ( struct V_1 ) ,
0 , NULL ) ;
if ( ! V_8 )
return - V_105 ;
V_183 = F_139 ( L_28 ) ;
if ( F_140 ( V_183 ) ) {
V_85 = F_141 ( V_183 ) ;
goto V_214;
}
V_85 = F_142 ( & V_159 ) ;
if ( V_85 < 0 ) {
goto V_215;
}
V_85 = F_143 ( & V_216 ) ;
if ( V_85 )
goto V_217;
return 0 ;
V_217:
F_144 ( & V_159 ) ;
V_215:
F_145 ( V_183 ) ;
V_214:
F_146 ( V_8 ) ;
return V_85 ;
}
static void T_11 F_147 ( void )
{
F_148 ( & V_216 ) ;
F_144 ( & V_159 ) ;
F_145 ( V_183 ) ;
F_146 ( V_8 ) ;
}
