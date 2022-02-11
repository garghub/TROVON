static void F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
struct V_3 * V_4 = V_1 -> V_3 ;
T_1 V_5 ;
for ( V_5 = 0 ; V_5 < V_2 ; V_5 ++ )
F_2 ( V_1 -> V_6 [ V_5 ] , V_4 -> V_7 ) ;
}
static inline bool F_3 ( struct V_3 * V_4 ,
struct V_1 * V_1 )
{
struct V_8 * V_8 ;
int V_9 , V_6 ;
V_6 = F_4 ( V_4 -> V_7 , V_4 -> V_10 ) ;
if ( V_6 == V_4 -> V_10 )
return false ;
V_8 = F_5 ( & V_4 -> V_11 , V_6 ) ;
if ( ! V_8 ) {
if ( F_6 ( 1 , & V_12 ) >
V_13 ) {
F_7 ( & V_12 ) ;
return false ;
}
V_8 = F_8 ( V_14 ) ;
if ( ! V_8 )
return false ;
V_9 = F_9 ( & V_4 -> V_11 , V_6 , V_8 ) ;
if ( V_9 ) {
F_10 ( V_8 ) ;
return false ;
}
}
if ( V_6 > V_4 -> V_15 )
V_4 -> V_15 = V_6 ;
F_11 ( V_6 , V_4 -> V_7 ) ;
F_12 ( V_1 , V_6 ) ;
return true ;
}
static bool F_13 ( struct V_3 * V_4 ,
struct V_1 * V_1 )
{
int V_5 ;
V_4 -> V_16 = false ;
for ( V_5 = V_1 -> V_17 ; V_5 < V_1 -> V_18 ; V_5 ++ ) {
if ( ! F_3 ( V_4 , V_1 ) )
goto V_19;
}
return true ;
V_19:
V_4 -> V_16 = true ;
F_14 ( & V_20 ) ;
return false ;
}
static inline struct V_8 *
F_15 ( struct V_3 * V_4 , T_1 V_6 )
{
return F_5 ( & V_4 -> V_11 , V_6 ) ;
}
static inline void F_16 ( struct V_1 * V_1 )
{
F_17 ( V_1 -> V_6 ) ;
F_18 ( V_21 , V_1 ) ;
}
static inline T_2 F_19 ( struct V_1 * V_1 )
{
struct V_22 * V_22 = V_1 -> V_22 ;
T_2 V_23 = F_20 ( V_22 -> V_23 , V_24 ) ;
if ( V_22 -> V_25 & V_26 ) {
F_21 ( ! ( V_22 -> V_27 && V_22 -> V_28 ) ) ;
V_23 += F_20 ( V_22 -> V_27 -> V_29 ,
V_24 ) ;
}
return V_23 ;
}
static inline T_1 F_22 ( struct V_1 * V_1 )
{
T_2 V_23 = F_19 ( V_1 ) ;
return V_23 / V_24 ;
}
static struct V_1 * F_23 ( struct V_22 * V_22 )
{
struct V_30 * V_31 = V_22 -> V_31 ;
struct V_3 * V_4 = F_24 ( V_31 ) ;
struct V_1 * V_1 ;
int V_32 ;
V_1 = F_25 ( V_21 , V_14 ) ;
if ( ! V_1 )
return NULL ;
V_1 -> V_22 = V_22 ;
V_1 -> V_3 = V_4 ;
if ( V_4 -> V_33 )
V_1 -> V_34 = V_35 +
F_26 ( V_4 -> V_33 ) ;
F_27 ( V_1 ) ;
V_1 -> V_18 = F_22 ( V_1 ) ;
V_1 -> V_6 = F_28 ( V_1 -> V_18 , sizeof( T_1 ) ,
V_14 ) ;
if ( ! V_1 -> V_6 ) {
F_18 ( V_21 , V_1 ) ;
return NULL ;
}
F_29 ( V_14 ) ;
F_30 ( & V_4 -> V_36 ) ;
V_32 = F_31 ( & V_4 -> V_37 , V_1 , 0 ,
V_38 , V_39 ) ;
F_32 ( & V_4 -> V_36 ) ;
F_33 () ;
if ( V_32 < 0 ) {
F_16 ( V_1 ) ;
return NULL ;
}
V_1 -> V_32 = V_32 ;
return V_1 ;
}
static inline void F_34 ( void * V_40 , T_2 V_41 )
{
unsigned long V_42 = F_35 ( V_40 ) ;
V_41 = F_20 ( V_41 + V_42 , V_43 ) ;
V_40 -= V_42 ;
while ( V_41 ) {
F_36 ( F_37 ( V_40 ) ) ;
V_41 -= V_43 ;
}
}
static inline T_2 F_38 ( T_2 V_44 , T_2 V_45 , T_2 V_41 )
{
int V_46 = V_44 - V_45 ;
if ( V_46 >= 0 )
return V_46 ;
else
return V_41 + V_46 ;
}
static inline T_2 F_39 ( T_2 V_44 , T_2 V_45 , T_2 V_41 )
{
return ( V_41 - F_38 ( V_44 , V_45 , V_41 ) - 1 ) ;
}
static inline T_2 F_40 ( T_2 V_44 , T_2 V_41 )
{
return V_41 - V_44 ;
}
static inline void F_41 ( struct V_47 * * V_48 , int * V_49 ,
struct V_3 * V_4 )
{
struct V_47 * V_47 ;
if ( * V_49 != 0 )
( * V_48 ) ++ ;
( * V_49 ) ++ ;
V_47 = * V_48 ;
memset ( V_47 , 0 , sizeof( struct V_47 ) ) ;
}
static inline T_2 F_42 ( struct V_3 * V_50 ,
int V_6 , int V_51 )
{
return V_50 -> V_52 + V_6 * V_24 +
V_24 - V_51 ;
}
static inline T_2 F_43 ( struct V_3 * V_4 , struct V_47 * V_48 )
{
return ( T_2 ) V_48 -> V_53 + V_48 -> V_54 ;
}
static int F_44 ( struct V_3 * V_4 ,
struct V_1 * V_1 , struct V_55 * V_56 ,
unsigned int V_57 , struct V_47 * * V_48 ,
int * V_49 , bool V_58 )
{
int V_5 , V_6 ;
int V_59 = 0 ;
void * V_60 , * V_61 = NULL ;
T_2 V_62 , V_63 , V_42 ;
struct V_55 * V_64 ;
struct V_8 * V_8 ;
F_45 (data_sg, sg, data_nents, i) {
int V_65 = V_64 -> V_29 ;
V_60 = F_46 ( F_47 ( V_64 ) ) + V_64 -> V_42 ;
while ( V_65 > 0 ) {
if ( V_59 == 0 ) {
if ( V_61 )
F_48 ( V_61 ) ;
V_59 = V_24 ;
V_6 = F_49 ( V_1 ) ;
V_8 = F_15 ( V_4 , V_6 ) ;
V_61 = F_46 ( V_8 ) ;
}
V_62 = F_50 ( T_2 , V_65 ,
V_59 ) ;
V_63 = F_42 ( V_4 , V_6 ,
V_59 ) ;
V_42 = V_24 - V_59 ;
V_61 = ( void * ) ( unsigned long ) V_61 + V_42 ;
if ( * V_49 != 0 &&
V_63 == F_43 ( V_4 , * V_48 ) ) {
( * V_48 ) -> V_54 += V_62 ;
} else {
F_41 ( V_48 , V_49 , V_4 ) ;
( * V_48 ) -> V_53 = ( void V_66 * ) V_63 ;
( * V_48 ) -> V_54 = V_62 ;
}
if ( V_58 ) {
memcpy ( V_61 , V_60 + V_64 -> V_29 - V_65 ,
V_62 ) ;
F_34 ( V_61 , V_62 ) ;
}
V_65 -= V_62 ;
V_59 -= V_62 ;
}
F_48 ( V_60 - V_64 -> V_42 ) ;
}
if ( V_61 )
F_48 ( V_61 ) ;
return 0 ;
}
static void F_51 ( struct V_3 * V_4 , struct V_1 * V_67 ,
bool V_68 )
{
struct V_22 * V_22 = V_67 -> V_22 ;
int V_5 , V_6 ;
int V_59 = 0 ;
void * V_60 = NULL , * V_61 ;
T_2 V_62 , V_42 ;
struct V_55 * V_64 , * V_56 ;
struct V_8 * V_8 ;
unsigned int V_57 ;
T_1 V_69 = 0 ;
if ( ! V_68 ) {
V_56 = V_22 -> V_70 ;
V_57 = V_22 -> V_71 ;
} else {
V_69 = F_52 ( V_22 -> V_23 , V_24 ) ;
V_56 = V_22 -> V_27 ;
V_57 = V_22 -> V_28 ;
}
F_53 ( V_67 , V_69 ) ;
F_45 (data_sg, sg, data_nents, i) {
int V_65 = V_64 -> V_29 ;
V_61 = F_46 ( F_47 ( V_64 ) ) + V_64 -> V_42 ;
while ( V_65 > 0 ) {
if ( V_59 == 0 ) {
if ( V_60 )
F_48 ( V_60 ) ;
V_59 = V_24 ;
V_6 = F_49 ( V_67 ) ;
V_8 = F_15 ( V_4 , V_6 ) ;
V_60 = F_46 ( V_8 ) ;
}
V_62 = F_50 ( T_2 , V_65 ,
V_59 ) ;
V_42 = V_24 - V_59 ;
V_60 = ( void * ) ( unsigned long ) V_60 + V_42 ;
F_34 ( V_60 , V_62 ) ;
memcpy ( V_61 + V_64 -> V_29 - V_65 , V_60 ,
V_62 ) ;
V_65 -= V_62 ;
V_59 -= V_62 ;
}
F_48 ( V_61 - V_64 -> V_42 ) ;
}
if ( V_60 )
F_48 ( V_60 ) ;
}
static inline T_2 F_54 ( unsigned long * V_72 , T_1 V_73 )
{
return V_24 * ( V_73 - F_55 ( V_72 , V_73 ) ) ;
}
static bool F_56 ( struct V_3 * V_4 , struct V_1 * V_67 ,
T_2 V_74 , T_2 V_75 )
{
struct V_76 * V_77 = V_4 -> V_78 ;
T_1 V_79 = ( V_75 + V_24 - 1 )
/ V_24 ;
T_2 V_80 , V_81 ;
T_3 V_82 ;
F_34 ( V_77 , sizeof( * V_77 ) ) ;
V_82 = V_77 -> V_82 % V_4 -> V_83 ;
if ( F_40 ( V_82 , V_4 -> V_83 ) >= V_74 )
V_81 = V_74 ;
else
V_81 = V_74 + F_40 ( V_82 , V_4 -> V_83 ) ;
V_80 = F_39 ( V_82 , V_4 -> V_84 , V_4 -> V_83 ) ;
if ( V_80 < V_81 ) {
F_57 ( L_1 , V_82 ,
V_4 -> V_84 , V_4 -> V_83 ) ;
return false ;
}
V_80 = F_54 ( V_4 -> V_7 , V_4 -> V_10 ) ;
if ( V_80 < V_75 ) {
unsigned long V_85 = V_86 - V_4 -> V_10 ;
unsigned long V_87 ;
if ( V_85 < V_79 ) {
F_57 ( L_2 ,
V_85 * V_24 ,
V_75 ) ;
return false ;
}
if ( ! V_4 -> V_10 ) {
T_1 V_88 = V_89 ;
V_4 -> V_10 = F_58 ( V_79 , V_88 ) ;
} else {
V_87 = F_58 ( V_79 , V_4 -> V_10 / 2 ) ;
V_4 -> V_10 += V_87 ;
if ( V_4 -> V_10 > V_86 )
V_4 -> V_10 = V_86 ;
}
}
if ( ! F_13 ( V_4 , V_67 ) )
return false ;
return true ;
}
static inline T_2 F_59 ( T_2 V_49 )
{
return F_58 ( F_60 ( struct V_90 , V_91 . V_48 [ V_49 ] ) ,
sizeof( struct V_90 ) ) ;
}
static inline T_2 F_61 ( struct V_1 * V_1 ,
T_2 V_92 )
{
struct V_22 * V_22 = V_1 -> V_22 ;
T_2 V_93 ;
V_93 = V_92 +
F_20 ( F_62 ( V_22 -> V_94 ) ,
V_95 ) ;
F_63 ( V_93 & ( V_95 - 1 ) ) ;
return V_93 ;
}
static T_4
F_64 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = V_1 -> V_3 ;
struct V_22 * V_22 = V_1 -> V_22 ;
T_2 V_92 , V_93 ;
struct V_76 * V_77 ;
struct V_90 * V_96 ;
struct V_47 * V_48 ;
int V_49 , V_9 ;
T_1 V_82 ;
T_5 V_97 ;
bool V_98 ;
T_2 V_23 = F_19 ( V_1 ) ;
if ( F_65 ( V_99 , & V_4 -> V_100 ) )
return V_101 ;
V_92 = F_59 ( V_1 -> V_18 ) ;
V_93 = F_61 ( V_1 , V_92 ) ;
F_66 ( & V_4 -> V_102 ) ;
V_77 = V_4 -> V_78 ;
V_82 = V_77 -> V_82 % V_4 -> V_83 ;
if ( ( V_93 > ( V_4 -> V_83 / 2 ) ) ||
V_23 > V_4 -> V_103 ) {
F_67 ( L_3
L_4 , V_93 , V_23 ,
V_4 -> V_83 , V_4 -> V_103 ) ;
F_68 ( & V_4 -> V_102 ) ;
return V_104 ;
}
while ( ! F_56 ( V_4 , V_1 , V_93 , V_23 ) ) {
int V_9 ;
F_69 ( V_105 ) ;
F_70 ( & V_4 -> V_106 , & V_105 , V_107 ) ;
F_57 ( L_5 ) ;
F_68 ( & V_4 -> V_102 ) ;
if ( V_4 -> V_33 )
V_9 = F_71 (
F_26 ( V_4 -> V_33 ) ) ;
else
V_9 = F_71 ( F_26 ( V_108 ) ) ;
F_72 ( & V_4 -> V_106 , & V_105 ) ;
if ( ! V_9 ) {
F_67 ( L_6 ) ;
return V_101 ;
}
F_66 ( & V_4 -> V_102 ) ;
V_82 = V_77 -> V_82 % V_4 -> V_83 ;
}
if ( F_40 ( V_82 , V_4 -> V_83 ) < V_93 ) {
T_2 V_109 = F_40 ( V_82 , V_4 -> V_83 ) ;
V_96 = ( void * ) V_77 + V_110 + V_82 ;
F_34 ( V_96 , sizeof( * V_96 ) ) ;
F_73 ( & V_96 -> V_111 . V_112 , V_113 ) ;
F_74 ( & V_96 -> V_111 . V_112 , V_109 ) ;
V_96 -> V_111 . V_32 = 0 ;
V_96 -> V_111 . V_114 = 0 ;
V_96 -> V_111 . V_115 = 0 ;
F_75 ( V_77 -> V_82 , V_109 , V_4 -> V_83 ) ;
V_82 = V_77 -> V_82 % V_4 -> V_83 ;
F_63 ( V_82 != 0 ) ;
}
V_96 = ( void * ) V_77 + V_110 + V_82 ;
F_34 ( V_96 , sizeof( * V_96 ) ) ;
F_73 ( & V_96 -> V_111 . V_112 , V_116 ) ;
V_96 -> V_111 . V_32 = V_1 -> V_32 ;
V_96 -> V_111 . V_114 = 0 ;
V_96 -> V_111 . V_115 = 0 ;
F_27 ( V_1 ) ;
V_48 = & V_96 -> V_91 . V_48 [ 0 ] ;
V_49 = 0 ;
V_98 = ( V_22 -> V_117 == V_118
|| V_22 -> V_25 & V_26 ) ;
V_9 = F_44 ( V_4 , V_1 , V_22 -> V_70 ,
V_22 -> V_71 , & V_48 , & V_49 ,
V_98 ) ;
if ( V_9 ) {
F_1 ( V_1 , V_1 -> V_18 ) ;
F_68 ( & V_4 -> V_102 ) ;
F_76 ( L_7 ) ;
return V_101 ;
}
V_96 -> V_91 . V_49 = V_49 ;
V_96 -> V_91 . V_119 = 0 ;
if ( V_22 -> V_25 & V_26 ) {
V_49 = 0 ;
V_48 ++ ;
V_9 = F_44 ( V_4 , V_1 ,
V_22 -> V_27 ,
V_22 -> V_28 ,
& V_48 , & V_49 , false ) ;
if ( V_9 ) {
F_1 ( V_1 , V_1 -> V_18 ) ;
F_68 ( & V_4 -> V_102 ) ;
F_76 ( L_8 ) ;
return V_101 ;
}
V_96 -> V_91 . V_120 = V_49 ;
}
V_92 = F_59 ( V_96 -> V_91 . V_49 +
V_96 -> V_91 . V_120 ) ;
V_93 = F_61 ( V_1 , V_92 ) ;
F_74 ( & V_96 -> V_111 . V_112 , V_93 ) ;
V_97 = V_110 + V_82 + V_92 ;
memcpy ( ( void * ) V_77 + V_97 , V_22 -> V_94 , F_62 ( V_22 -> V_94 ) ) ;
V_96 -> V_91 . V_97 = V_97 ;
F_34 ( V_96 , sizeof( * V_96 ) ) ;
F_75 ( V_77 -> V_82 , V_93 , V_4 -> V_83 ) ;
F_34 ( V_77 , sizeof( * V_77 ) ) ;
F_68 ( & V_4 -> V_102 ) ;
F_77 ( & V_4 -> V_121 ) ;
if ( V_4 -> V_33 )
F_78 ( & V_4 -> V_122 , F_79 ( V_35 +
F_26 ( V_4 -> V_33 ) ) ) ;
return V_123 ;
}
static T_4
F_80 ( struct V_22 * V_22 )
{
struct V_30 * V_31 = V_22 -> V_31 ;
struct V_3 * V_4 = F_24 ( V_31 ) ;
struct V_1 * V_1 ;
T_4 V_9 ;
V_1 = F_23 ( V_22 ) ;
if ( ! V_1 )
return V_101 ;
V_9 = F_64 ( V_1 ) ;
if ( V_9 != V_123 ) {
F_76 ( L_9 ) ;
F_30 ( & V_4 -> V_36 ) ;
F_81 ( & V_4 -> V_37 , V_1 -> V_32 ) ;
F_32 ( & V_4 -> V_36 ) ;
F_16 ( V_1 ) ;
}
return V_9 ;
}
static void F_82 ( struct V_1 * V_67 , struct V_90 * V_96 )
{
struct V_22 * V_22 = V_67 -> V_22 ;
struct V_3 * V_4 = V_67 -> V_3 ;
if ( F_65 ( V_124 , & V_67 -> V_100 ) )
goto V_125;
F_27 ( V_67 ) ;
if ( V_96 -> V_111 . V_115 & V_126 ) {
F_67 ( L_10 ,
V_67 -> V_22 ) ;
V_96 -> V_127 . V_128 = V_129 ;
} else if ( V_96 -> V_127 . V_128 == V_129 ) {
memcpy ( V_22 -> V_130 , V_96 -> V_127 . V_130 ,
V_22 -> V_131 ) ;
} else if ( V_22 -> V_25 & V_26 ) {
F_51 ( V_4 , V_67 , true ) ;
} else if ( V_22 -> V_117 == V_132 ) {
F_51 ( V_4 , V_67 , false ) ;
} else if ( V_22 -> V_117 == V_118 ) {
} else if ( V_22 -> V_117 != V_133 ) {
F_67 ( L_11 ,
V_22 -> V_117 ) ;
}
F_83 ( V_67 -> V_22 , V_96 -> V_127 . V_128 ) ;
V_125:
V_67 -> V_22 = NULL ;
F_1 ( V_67 , V_67 -> V_18 ) ;
F_16 ( V_67 ) ;
}
static unsigned int F_84 ( struct V_3 * V_4 )
{
struct V_76 * V_77 ;
int V_134 = 0 ;
if ( F_65 ( V_99 , & V_4 -> V_100 ) ) {
F_76 ( L_12 ) ;
return 0 ;
}
V_77 = V_4 -> V_78 ;
F_34 ( V_77 , sizeof( * V_77 ) ) ;
while ( V_4 -> V_84 != F_85 ( V_77 -> V_135 ) ) {
struct V_90 * V_96 = ( void * ) V_77 + V_110 + V_4 -> V_84 ;
struct V_1 * V_67 ;
F_34 ( V_96 , sizeof( * V_96 ) ) ;
if ( F_86 ( V_96 -> V_111 . V_112 ) == V_113 ) {
F_75 ( V_4 -> V_84 ,
F_87 ( V_96 -> V_111 . V_112 ) ,
V_4 -> V_83 ) ;
continue;
}
F_63 ( F_86 ( V_96 -> V_111 . V_112 ) != V_116 ) ;
F_88 ( & V_4 -> V_36 ) ;
V_67 = F_81 ( & V_4 -> V_37 , V_96 -> V_111 . V_32 ) ;
F_89 ( & V_4 -> V_36 ) ;
if ( ! V_67 ) {
F_76 ( L_13 ) ;
F_11 ( V_99 , & V_4 -> V_100 ) ;
break;
}
F_82 ( V_67 , V_96 ) ;
F_75 ( V_4 -> V_84 ,
F_87 ( V_96 -> V_111 . V_112 ) ,
V_4 -> V_83 ) ;
V_134 ++ ;
}
if ( V_77 -> V_135 == V_77 -> V_82 )
F_90 ( & V_4 -> V_122 ) ;
F_14 ( & V_4 -> V_106 ) ;
return V_134 ;
}
static int F_91 ( int V_136 , void * V_137 , void * V_138 )
{
struct V_1 * V_67 = V_137 ;
if ( F_65 ( V_124 , & V_67 -> V_100 ) )
return 0 ;
if ( ! F_92 ( V_35 , V_67 -> V_34 ) )
return 0 ;
F_11 ( V_124 , & V_67 -> V_100 ) ;
F_83 ( V_67 -> V_22 , V_129 ) ;
V_67 -> V_22 = NULL ;
return 0 ;
}
static void F_93 ( unsigned long V_138 )
{
struct V_3 * V_4 = (struct V_3 * ) V_138 ;
unsigned long V_100 ;
F_94 ( & V_4 -> V_36 , V_100 ) ;
F_95 ( & V_4 -> V_37 , F_91 , NULL ) ;
F_96 ( & V_4 -> V_36 , V_100 ) ;
F_14 ( & V_20 ) ;
}
static int F_97 ( struct V_139 * V_140 , T_3 V_141 )
{
struct V_142 * V_142 ;
V_142 = F_98 ( sizeof( struct V_142 ) , V_14 ) ;
if ( ! V_142 )
return - V_143 ;
V_142 -> V_141 = V_141 ;
V_140 -> V_144 = V_142 ;
return 0 ;
}
static void F_99 ( struct V_139 * V_140 )
{
F_17 ( V_140 -> V_144 ) ;
V_140 -> V_144 = NULL ;
}
static struct V_30 * F_100 ( struct V_139 * V_140 , const char * V_145 )
{
struct V_3 * V_4 ;
V_4 = F_98 ( sizeof( struct V_3 ) , V_14 ) ;
if ( ! V_4 )
return NULL ;
F_101 ( & V_4 -> V_146 ) ;
V_4 -> V_145 = F_102 ( V_145 , V_14 ) ;
if ( ! V_4 -> V_145 ) {
F_17 ( V_4 ) ;
return NULL ;
}
V_4 -> V_140 = V_140 ;
V_4 -> V_33 = V_108 ;
F_103 ( & V_4 -> V_106 ) ;
F_104 ( & V_4 -> V_102 ) ;
F_105 ( & V_4 -> V_37 ) ;
F_106 ( & V_4 -> V_36 ) ;
F_107 ( & V_4 -> V_122 , F_93 ,
( unsigned long ) V_4 ) ;
return & V_4 -> V_31 ;
}
static int F_108 ( struct V_121 * V_147 , T_6 V_148 )
{
struct V_3 * V_3 = F_109 ( V_147 , struct V_3 , V_121 ) ;
F_66 ( & V_3 -> V_102 ) ;
F_84 ( V_3 ) ;
F_68 ( & V_3 -> V_102 ) ;
return 0 ;
}
static int F_110 ( struct V_149 * V_150 )
{
struct V_3 * V_4 = V_150 -> V_151 ;
struct V_121 * V_147 = & V_4 -> V_121 ;
if ( V_150 -> V_152 < V_153 ) {
if ( V_147 -> V_154 [ V_150 -> V_152 ] . V_41 == 0 )
return - 1 ;
return ( int ) V_150 -> V_152 ;
}
return - 1 ;
}
static struct V_8 * F_111 ( struct V_3 * V_4 , T_1 V_6 )
{
struct V_8 * V_8 ;
int V_9 ;
F_66 ( & V_4 -> V_102 ) ;
V_8 = F_15 ( V_4 , V_6 ) ;
if ( F_112 ( V_8 ) ) {
F_68 ( & V_4 -> V_102 ) ;
return V_8 ;
}
F_67 ( L_14 , V_6 ) ;
F_67 ( L_15 ) ;
if ( V_6 >= V_4 -> V_10 ) {
V_4 -> V_10 = V_6 + 1 ;
V_4 -> V_15 = V_6 ;
}
V_8 = F_5 ( & V_4 -> V_11 , V_6 ) ;
if ( ! V_8 ) {
V_8 = F_8 ( V_14 | V_155 ) ;
if ( ! V_8 ) {
F_68 ( & V_4 -> V_102 ) ;
return NULL ;
}
V_9 = F_9 ( & V_4 -> V_11 , V_6 , V_8 ) ;
if ( V_9 ) {
F_68 ( & V_4 -> V_102 ) ;
F_10 ( V_8 ) ;
return NULL ;
}
F_113 ( & V_12 ) ;
}
F_68 ( & V_4 -> V_102 ) ;
return V_8 ;
}
static int F_114 ( struct V_156 * V_157 )
{
struct V_3 * V_4 = V_157 -> V_150 -> V_151 ;
struct V_121 * V_147 = & V_4 -> V_121 ;
struct V_8 * V_8 ;
unsigned long V_42 ;
void * V_158 ;
int V_159 = F_110 ( V_157 -> V_150 ) ;
if ( V_159 < 0 )
return V_160 ;
V_42 = ( V_157 -> V_161 - V_159 ) << V_162 ;
if ( V_42 < V_4 -> V_52 ) {
V_158 = ( void * ) ( unsigned long ) V_147 -> V_154 [ V_159 ] . V_158 + V_42 ;
V_8 = F_115 ( V_158 ) ;
} else {
T_1 V_6 ;
V_6 = ( V_42 - V_4 -> V_52 ) / V_24 ;
V_8 = F_111 ( V_4 , V_6 ) ;
if ( ! V_8 )
return V_163 ;
}
F_116 ( V_8 ) ;
V_157 -> V_8 = V_8 ;
return 0 ;
}
static int F_117 ( struct V_121 * V_147 , struct V_149 * V_150 )
{
struct V_3 * V_4 = F_109 ( V_147 , struct V_3 , V_121 ) ;
V_150 -> V_164 |= V_165 | V_166 ;
V_150 -> V_167 = & V_168 ;
V_150 -> V_151 = V_4 ;
if ( F_118 ( V_150 ) != ( V_169 >> V_162 ) )
return - V_170 ;
return 0 ;
}
static int F_119 ( struct V_121 * V_147 , struct V_171 * V_171 )
{
struct V_3 * V_4 = F_109 ( V_147 , struct V_3 , V_121 ) ;
if ( F_120 ( V_172 , & V_4 -> V_100 ) )
return - V_173 ;
V_4 -> V_171 = V_171 ;
F_57 ( L_16 ) ;
return 0 ;
}
static void F_121 ( struct V_174 * V_137 )
{
struct V_30 * V_50 = F_109 ( V_137 , struct V_30 , V_174 ) ;
struct V_3 * V_4 = F_24 ( V_50 ) ;
F_17 ( V_4 -> V_121 . V_145 ) ;
F_17 ( V_4 -> V_145 ) ;
F_17 ( V_4 ) ;
}
static void F_122 ( struct V_146 * V_146 )
{
struct V_3 * V_4 = F_109 ( V_146 , struct V_3 , V_146 ) ;
struct V_30 * V_50 = & V_4 -> V_31 ;
F_123 ( & V_50 -> V_174 , F_121 ) ;
}
static int F_124 ( struct V_121 * V_147 , struct V_171 * V_171 )
{
struct V_3 * V_4 = F_109 ( V_147 , struct V_3 , V_121 ) ;
F_2 ( V_172 , & V_4 -> V_100 ) ;
F_57 ( L_17 ) ;
F_125 ( & V_4 -> V_146 , F_122 ) ;
return 0 ;
}
static int F_126 ( enum V_175 V_67 , const char * V_145 , int V_176 )
{
struct V_177 * V_178 ;
void * V_179 ;
int V_9 = - V_143 ;
V_178 = F_127 ( V_180 , V_14 ) ;
if ( ! V_178 )
return V_9 ;
V_179 = F_128 ( V_178 , 0 , 0 , & V_181 , 0 , V_67 ) ;
if ( ! V_179 )
goto V_182;
V_9 = F_129 ( V_178 , V_183 , V_145 ) ;
if ( V_9 < 0 )
goto V_182;
V_9 = F_130 ( V_178 , V_184 , V_176 ) ;
if ( V_9 < 0 )
goto V_182;
F_131 ( V_178 , V_179 ) ;
V_9 = F_132 ( & V_181 , V_178 , 0 ,
V_185 , V_14 ) ;
if ( V_9 == - V_186 )
V_9 = 0 ;
return V_9 ;
V_182:
F_133 ( V_178 ) ;
return V_9 ;
}
static int F_134 ( struct V_30 * V_50 )
{
struct V_3 * V_4 = F_24 ( V_50 ) ;
struct V_142 * V_140 = V_4 -> V_140 -> V_144 ;
struct V_121 * V_147 ;
struct V_76 * V_77 ;
T_2 V_41 ;
T_2 V_187 ;
int V_9 = 0 ;
char * V_188 ;
V_147 = & V_4 -> V_121 ;
V_41 = snprintf ( NULL , 0 , L_18 , V_140 -> V_141 , V_4 -> V_145 ,
V_4 -> V_189 ) ;
V_41 += 1 ;
V_188 = F_135 ( V_41 , V_14 ) ;
if ( ! V_188 )
return - V_143 ;
V_187 = snprintf ( V_188 , V_41 , L_19 , V_140 -> V_141 , V_4 -> V_145 ) ;
if ( V_4 -> V_189 [ 0 ] )
snprintf ( V_188 + V_187 , V_41 - V_187 , L_20 , V_4 -> V_189 ) ;
V_147 -> V_145 = V_188 ;
V_4 -> V_78 = F_136 ( V_190 ) ;
if ( ! V_4 -> V_78 ) {
V_9 = - V_143 ;
goto V_191;
}
V_4 -> V_83 = V_190 - V_110 ;
V_4 -> V_52 = V_190 ;
V_4 -> V_103 = V_192 ;
V_4 -> V_10 = 0 ;
V_4 -> V_16 = false ;
V_77 = V_4 -> V_78 ;
V_77 -> V_193 = V_194 ;
V_77 -> V_100 = V_195 ;
V_77 -> V_196 = V_110 ;
V_77 -> V_83 = V_4 -> V_83 ;
F_63 ( ! F_137 ( V_4 -> V_52 ) ) ;
F_63 ( V_4 -> V_103 % V_43 ) ;
F_63 ( V_4 -> V_103 % V_24 ) ;
F_138 ( & V_4 -> V_11 , V_14 ) ;
V_147 -> V_193 = F_139 ( V_194 ) ;
V_147 -> V_154 [ 0 ] . V_145 = L_21 ;
V_147 -> V_154 [ 0 ] . V_158 = ( V_197 ) ( V_198 ) V_4 -> V_78 ;
V_147 -> V_154 [ 0 ] . V_41 = V_169 ;
V_147 -> V_154 [ 0 ] . V_199 = V_200 ;
V_147 -> V_201 = F_108 ;
V_147 -> V_202 = V_203 ;
V_147 -> V_204 = F_117 ;
V_147 -> V_205 = F_119 ;
V_147 -> V_206 = F_124 ;
V_9 = F_140 ( V_207 , V_147 ) ;
if ( V_9 )
goto V_208;
if ( V_50 -> V_209 . V_210 == 0 )
V_50 -> V_209 . V_210 = 512 ;
if ( ! V_50 -> V_209 . V_211 )
V_50 -> V_209 . V_211 = 128 ;
V_50 -> V_209 . V_212 = 128 ;
F_141 ( & V_4 -> V_146 ) ;
V_9 = F_126 ( V_213 , V_4 -> V_121 . V_145 ,
V_4 -> V_121 . V_214 -> V_176 ) ;
if ( V_9 )
goto V_215;
F_66 ( & V_216 ) ;
F_142 ( & V_4 -> V_217 , & V_218 ) ;
F_68 ( & V_216 ) ;
return 0 ;
V_215:
F_125 ( & V_4 -> V_146 , F_122 ) ;
F_143 ( & V_4 -> V_121 ) ;
V_208:
F_144 ( V_4 -> V_78 ) ;
V_191:
F_17 ( V_147 -> V_145 ) ;
V_147 -> V_145 = NULL ;
return V_9 ;
}
static int F_145 ( struct V_1 * V_67 )
{
if ( F_65 ( V_124 , & V_67 -> V_100 ) ) {
F_18 ( V_21 , V_67 ) ;
return 0 ;
}
return - V_170 ;
}
static bool F_146 ( struct V_3 * V_4 )
{
return V_4 -> V_121 . V_214 ? true : false ;
}
static void F_147 ( struct V_3 * V_4 )
{
int V_5 ;
struct V_8 * V_8 ;
F_66 ( & V_4 -> V_102 ) ;
for ( V_5 = 0 ; V_5 <= V_4 -> V_15 ; V_5 ++ ) {
V_8 = F_148 ( & V_4 -> V_11 , V_5 ) ;
if ( V_8 ) {
F_10 ( V_8 ) ;
F_7 ( & V_12 ) ;
}
}
F_68 ( & V_4 -> V_102 ) ;
}
static void F_149 ( struct V_30 * V_50 )
{
struct V_3 * V_4 = F_24 ( V_50 ) ;
struct V_1 * V_67 ;
bool V_219 = true ;
int V_5 ;
F_150 ( & V_4 -> V_122 ) ;
F_66 ( & V_216 ) ;
F_151 ( & V_4 -> V_217 ) ;
F_68 ( & V_216 ) ;
F_144 ( V_4 -> V_78 ) ;
F_30 ( & V_4 -> V_36 ) ;
F_152 (&udev->commands, cmd, i) {
if ( F_145 ( V_67 ) != 0 )
V_219 = false ;
}
F_153 ( & V_4 -> V_37 ) ;
F_32 ( & V_4 -> V_36 ) ;
F_63 ( ! V_219 ) ;
F_147 ( V_4 ) ;
if ( F_146 ( V_4 ) ) {
F_126 ( V_220 , V_4 -> V_121 . V_145 ,
V_4 -> V_121 . V_214 -> V_176 ) ;
F_143 ( & V_4 -> V_121 ) ;
}
F_125 ( & V_4 -> V_146 , F_122 ) ;
}
static int F_154 ( T_7 * V_221 , T_3 * V_209 )
{
unsigned long V_222 ;
char * V_223 ;
int V_9 ;
V_223 = F_155 ( V_221 ) ;
if ( ! V_223 )
return - V_143 ;
V_9 = F_156 ( V_223 , 0 , & V_222 ) ;
F_17 ( V_223 ) ;
if ( V_9 < 0 ) {
F_76 ( L_22 ) ;
return V_9 ;
}
if ( ! V_222 ) {
F_76 ( L_23 ) ;
return - V_170 ;
}
* V_209 = V_222 ;
return 0 ;
}
static T_8 F_157 ( struct V_30 * V_50 ,
const char * V_8 , T_8 V_69 )
{
struct V_3 * V_4 = F_24 ( V_50 ) ;
char * V_224 , * V_225 , * V_226 , * V_223 ;
T_7 args [ V_227 ] ;
int V_9 = 0 , V_228 ;
V_226 = F_102 ( V_8 , V_14 ) ;
if ( ! V_226 )
return - V_143 ;
V_224 = V_226 ;
while ( ( V_225 = F_158 ( & V_226 , L_24 ) ) != NULL ) {
if ( ! * V_225 )
continue;
V_228 = F_159 ( V_225 , V_229 , args ) ;
switch ( V_228 ) {
case V_230 :
if ( F_160 ( V_4 -> V_189 , & args [ 0 ] ,
V_231 ) == 0 ) {
V_9 = - V_170 ;
break;
}
F_57 ( L_25 , V_4 -> V_189 ) ;
break;
case V_232 :
V_223 = F_155 ( & args [ 0 ] ) ;
if ( ! V_223 ) {
V_9 = - V_143 ;
break;
}
V_9 = F_156 ( V_223 , 0 , ( unsigned long * ) & V_4 -> V_233 ) ;
F_17 ( V_223 ) ;
if ( V_9 < 0 )
F_76 ( L_26 ) ;
break;
case V_234 :
V_9 = F_154 ( & args [ 0 ] ,
& ( V_50 -> V_209 . V_210 ) ) ;
break;
case V_235 :
V_9 = F_154 ( & args [ 0 ] ,
& ( V_50 -> V_209 . V_211 ) ) ;
break;
default:
break;
}
if ( V_9 )
break;
}
F_17 ( V_224 ) ;
return ( ! V_9 ) ? V_69 : V_9 ;
}
static T_8 F_161 ( struct V_30 * V_50 , char * V_236 )
{
struct V_3 * V_4 = F_24 ( V_50 ) ;
T_8 V_237 = 0 ;
V_237 = sprintf ( V_236 + V_237 , L_27 ,
V_4 -> V_189 [ 0 ] ? V_4 -> V_189 : L_28 ) ;
V_237 += sprintf ( V_236 + V_237 , L_29 , V_4 -> V_233 ) ;
return V_237 ;
}
static T_9 F_162 ( struct V_30 * V_50 )
{
struct V_3 * V_4 = F_24 ( V_50 ) ;
return F_163 ( V_4 -> V_233 - V_50 -> V_209 . V_238 ,
V_50 -> V_209 . V_238 ) ;
}
static T_4
F_164 ( struct V_22 * V_67 )
{
return F_165 ( V_67 , F_80 ) ;
}
static T_8 F_166 ( struct V_239 * V_240 , char * V_8 )
{
struct V_241 * V_242 = F_109 ( F_167 ( V_240 ) ,
struct V_241 , V_243 ) ;
struct V_3 * V_4 = F_109 ( V_242 -> V_244 ,
struct V_3 , V_31 ) ;
return snprintf ( V_8 , V_43 , L_30 , V_4 -> V_33 / V_245 ) ;
}
static T_8 F_168 ( struct V_239 * V_240 , const char * V_8 ,
T_2 V_69 )
{
struct V_241 * V_242 = F_109 ( F_167 ( V_240 ) ,
struct V_241 , V_243 ) ;
struct V_3 * V_4 = F_109 ( V_242 -> V_244 ,
struct V_3 , V_31 ) ;
T_3 V_246 ;
int V_9 ;
if ( V_242 -> V_244 -> V_247 ) {
F_76 ( L_31 ) ;
return - V_170 ;
}
V_9 = F_169 ( V_8 , 0 , & V_246 ) ;
if ( V_9 < 0 )
return V_9 ;
V_4 -> V_33 = V_246 * V_245 ;
return V_69 ;
}
static int F_170 ( void * V_138 )
{
struct V_3 * V_4 ;
T_10 V_248 ;
T_1 V_249 , V_250 , V_251 ;
struct V_8 * V_8 ;
int V_5 ;
while ( 1 ) {
F_69 ( V_105 ) ;
F_70 ( & V_20 , & V_105 , V_107 ) ;
F_171 () ;
F_72 ( & V_20 , & V_105 ) ;
if ( F_172 () )
break;
F_66 ( & V_216 ) ;
F_173 (udev, &root_udev, node) {
F_66 ( & V_4 -> V_102 ) ;
F_84 ( V_4 ) ;
if ( V_4 -> V_16 || ! V_4 -> V_10 ) {
F_68 ( & V_4 -> V_102 ) ;
continue;
}
V_250 = V_4 -> V_15 + 1 ;
V_251 = F_174 ( V_4 -> V_7 , V_250 ) ;
if ( V_251 == V_4 -> V_15 ) {
F_68 ( & V_4 -> V_102 ) ;
continue;
} else if ( V_251 == V_250 ) {
V_4 -> V_10 = V_249 = 0 ;
V_4 -> V_15 = 0 ;
} else {
V_4 -> V_10 = V_249 = V_251 + 1 ;
V_4 -> V_15 = V_251 ;
}
V_248 = V_4 -> V_52 + V_249 * V_24 ;
F_175 ( V_4 -> V_171 -> V_252 , V_248 , 0 , 1 ) ;
for ( V_5 = V_249 ; V_5 < V_250 ; V_5 ++ ) {
V_8 = F_148 ( & V_4 -> V_11 , V_5 ) ;
if ( V_8 ) {
F_10 ( V_8 ) ;
F_7 ( & V_12 ) ;
}
}
F_68 ( & V_4 -> V_102 ) ;
}
F_173 (udev, &root_udev, node) {
if ( V_4 -> V_16 )
F_14 ( & V_4 -> V_106 ) ;
}
F_68 ( & V_216 ) ;
}
return 0 ;
}
static int T_11 F_176 ( void )
{
int V_9 , V_5 , V_2 = 0 ;
F_177 ( ( sizeof( struct V_90 ) % V_95 ) != 0 ) ;
V_21 = F_178 ( L_32 ,
sizeof( struct V_1 ) ,
F_179 ( struct V_1 ) ,
0 , NULL ) ;
if ( ! V_21 )
return - V_143 ;
V_207 = F_180 ( L_33 ) ;
if ( F_181 ( V_207 ) ) {
V_9 = F_182 ( V_207 ) ;
goto V_253;
}
V_9 = F_183 ( & V_181 ) ;
if ( V_9 < 0 ) {
goto V_254;
}
for ( V_5 = 0 ; V_255 [ V_5 ] != NULL ; V_5 ++ ) {
V_2 += sizeof( struct V_256 * ) ;
}
V_2 += sizeof( struct V_256 * ) * 2 ;
V_257 = F_98 ( V_2 , V_14 ) ;
if ( ! V_257 ) {
V_9 = - V_143 ;
goto V_258;
}
for ( V_5 = 0 ; V_255 [ V_5 ] != NULL ; V_5 ++ ) {
V_257 [ V_5 ] = V_255 [ V_5 ] ;
}
V_257 [ V_5 ] = & V_259 ;
V_260 . V_261 = V_257 ;
V_9 = F_184 ( & V_260 ) ;
if ( V_9 )
goto V_262;
F_103 ( & V_20 ) ;
V_263 = F_185 ( F_170 , NULL , L_34 ) ;
if ( F_181 ( V_263 ) ) {
V_9 = F_182 ( V_263 ) ;
goto V_264;
}
return 0 ;
V_264:
F_186 ( & V_260 ) ;
V_262:
F_17 ( V_257 ) ;
V_258:
F_187 ( & V_181 ) ;
V_254:
F_188 ( V_207 ) ;
V_253:
F_189 ( V_21 ) ;
return V_9 ;
}
static void T_12 F_190 ( void )
{
F_191 ( V_263 ) ;
F_186 ( & V_260 ) ;
F_17 ( V_257 ) ;
F_187 ( & V_181 ) ;
F_188 ( V_207 ) ;
F_189 ( V_21 ) ;
}
