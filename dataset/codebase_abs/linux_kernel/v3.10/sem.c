void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_4 ;
V_2 -> V_5 = V_6 ;
V_2 -> V_7 = V_8 ;
V_2 -> V_9 = V_10 ;
V_2 -> V_11 = 0 ;
F_2 ( & V_2 -> V_12 [ V_13 ] ) ;
}
void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 , & F_5 ( V_2 ) , V_14 ) ;
F_6 ( & V_2 -> V_12 [ V_13 ] . V_15 ) ;
}
void T_1 F_7 ( void )
{
F_1 ( & V_16 ) ;
F_8 ( L_1 ,
L_2 ,
V_13 , V_17 ) ;
}
static inline int F_9 ( struct V_18 * V_19 , struct V_20 * V_21 ,
int V_22 )
{
int V_23 ;
V_24:
if ( V_22 == 1 && ! V_19 -> V_25 ) {
struct V_26 * V_26 = V_19 -> V_27 + V_21 -> V_28 ;
F_10 ( & V_26 -> V_29 ) ;
if ( F_11 ( V_19 -> V_25 ) ) {
F_12 ( & V_26 -> V_29 ) ;
goto V_30;
}
if ( F_11 ( F_13 ( & V_19 -> V_31 . V_29 ) ) ) {
F_12 ( & V_26 -> V_29 ) ;
F_14 ( & V_19 -> V_31 . V_29 ) ;
goto V_24;
}
V_23 = V_21 -> V_28 ;
} else {
int V_32 ;
V_30:
F_10 ( & V_19 -> V_31 . V_29 ) ;
for ( V_32 = 0 ; V_32 < V_19 -> V_33 ; V_32 ++ ) {
struct V_26 * V_26 = V_19 -> V_27 + V_32 ;
F_14 ( & V_26 -> V_29 ) ;
}
V_23 = - 1 ;
}
return V_23 ;
}
static inline void F_15 ( struct V_18 * V_19 , int V_23 )
{
if ( V_23 == - 1 ) {
F_12 ( & V_19 -> V_31 . V_29 ) ;
} else {
struct V_26 * V_26 = V_19 -> V_27 + V_23 ;
F_12 ( & V_26 -> V_29 ) ;
}
}
static inline struct V_18 * F_16 ( struct V_1 * V_2 ,
int V_34 , struct V_20 * V_21 , int V_22 , int * V_23 )
{
struct V_35 * V_36 ;
struct V_18 * V_19 ;
V_36 = F_17 ( & F_5 ( V_2 ) , V_34 ) ;
if ( F_18 ( V_36 ) )
return F_19 ( V_36 ) ;
V_19 = F_20 ( V_36 , struct V_18 , V_31 ) ;
* V_23 = F_9 ( V_19 , V_21 , V_22 ) ;
if ( ! V_36 -> V_37 )
return F_20 ( V_36 , struct V_18 , V_31 ) ;
F_15 ( V_19 , * V_23 ) ;
return F_21 ( - V_38 ) ;
}
static inline struct V_18 * F_22 ( struct V_1 * V_2 , int V_34 )
{
struct V_35 * V_36 = F_17 ( & F_5 ( V_2 ) , V_34 ) ;
if ( F_18 ( V_36 ) )
return F_19 ( V_36 ) ;
return F_20 ( V_36 , struct V_18 , V_31 ) ;
}
static inline struct V_18 * F_23 ( struct V_1 * V_2 ,
int V_34 )
{
struct V_35 * V_36 = F_24 ( & F_5 ( V_2 ) , V_34 ) ;
if ( F_18 ( V_36 ) )
return F_19 ( V_36 ) ;
return F_20 ( V_36 , struct V_18 , V_31 ) ;
}
static inline void F_25 ( struct V_18 * V_19 )
{
F_9 ( V_19 , NULL , - 1 ) ;
F_26 ( V_19 ) ;
}
static inline void F_27 ( struct V_18 * V_19 )
{
F_26 ( V_19 ) ;
}
static inline void F_28 ( struct V_1 * V_2 , struct V_18 * V_39 )
{
F_29 ( & F_5 ( V_2 ) , & V_39 -> V_31 ) ;
}
static int F_30 ( struct V_1 * V_2 , struct V_40 * V_41 )
{
int V_34 ;
int V_42 ;
struct V_18 * V_19 ;
int V_43 ;
T_2 V_44 = V_41 -> V_44 ;
int V_45 = V_41 -> V_46 . V_45 ;
int V_47 = V_41 -> V_48 ;
int V_32 ;
if ( ! V_45 )
return - V_38 ;
if ( V_2 -> V_11 + V_45 > V_2 -> V_5 )
return - V_49 ;
V_43 = sizeof ( * V_19 ) + V_45 * sizeof ( struct V_26 ) ;
V_19 = F_31 ( V_43 ) ;
if ( ! V_19 ) {
return - V_50 ;
}
memset ( V_19 , 0 , V_43 ) ;
V_19 -> V_31 . V_51 = ( V_47 & V_52 ) ;
V_19 -> V_31 . V_44 = V_44 ;
V_19 -> V_31 . V_53 = NULL ;
V_42 = F_32 ( V_19 ) ;
if ( V_42 ) {
F_26 ( V_19 ) ;
return V_42 ;
}
V_34 = F_33 ( & F_5 ( V_2 ) , & V_19 -> V_31 , V_2 -> V_9 ) ;
if ( V_34 < 0 ) {
F_34 ( V_19 ) ;
F_26 ( V_19 ) ;
return V_34 ;
}
V_2 -> V_11 += V_45 ;
V_19 -> V_27 = (struct V_26 * ) & V_19 [ 1 ] ;
for ( V_32 = 0 ; V_32 < V_45 ; V_32 ++ ) {
F_35 ( & V_19 -> V_27 [ V_32 ] . V_54 ) ;
F_36 ( & V_19 -> V_27 [ V_32 ] . V_29 ) ;
}
V_19 -> V_25 = 0 ;
F_35 ( & V_19 -> V_54 ) ;
F_35 ( & V_19 -> V_55 ) ;
V_19 -> V_33 = V_45 ;
V_19 -> V_56 = F_37 () ;
F_15 ( V_19 , - 1 ) ;
F_38 () ;
return V_19 -> V_31 . V_34 ;
}
static inline int F_39 ( struct V_35 * V_36 , int V_47 )
{
struct V_18 * V_19 ;
V_19 = F_20 ( V_36 , struct V_18 , V_31 ) ;
return F_40 ( V_19 , V_47 ) ;
}
static inline int F_41 ( struct V_35 * V_36 ,
struct V_40 * V_41 )
{
struct V_18 * V_19 ;
V_19 = F_20 ( V_36 , struct V_18 , V_31 ) ;
if ( V_41 -> V_46 . V_45 > V_19 -> V_33 )
return - V_38 ;
return 0 ;
}
static int F_42 ( struct V_18 * V_19 , struct V_20 * V_21 ,
int V_22 , struct V_57 * V_58 , int V_59 )
{
int V_60 , V_61 ;
struct V_20 * V_62 ;
struct V_26 * V_63 ;
for ( V_62 = V_21 ; V_62 < V_21 + V_22 ; V_62 ++ ) {
V_63 = V_19 -> V_27 + V_62 -> V_28 ;
V_61 = V_62 -> V_61 ;
V_60 = V_63 -> V_64 ;
if ( ! V_61 && V_60 )
goto V_65;
V_60 += V_61 ;
if ( V_60 < 0 )
goto V_65;
if ( V_60 > V_66 )
goto V_67;
if ( V_62 -> V_68 & V_69 ) {
int V_70 = V_58 -> V_71 [ V_62 -> V_28 ] - V_61 ;
if ( V_70 < ( - V_72 - 1 ) || V_70 > V_72 )
goto V_67;
}
V_63 -> V_64 = V_60 ;
}
V_62 -- ;
while ( V_62 >= V_21 ) {
V_19 -> V_27 [ V_62 -> V_28 ] . V_73 = V_59 ;
if ( V_62 -> V_68 & V_69 )
V_58 -> V_71 [ V_62 -> V_28 ] -= V_62 -> V_61 ;
V_62 -- ;
}
return 0 ;
V_67:
V_60 = - V_74 ;
goto V_70;
V_65:
if ( V_62 -> V_68 & V_75 )
V_60 = - V_76 ;
else
V_60 = 1 ;
V_70:
V_62 -- ;
while ( V_62 >= V_21 ) {
V_19 -> V_27 [ V_62 -> V_28 ] . V_64 -= V_62 -> V_61 ;
V_62 -- ;
}
return V_60 ;
}
static void F_43 ( struct V_77 * V_78 ,
struct V_79 * V_80 , int error )
{
if ( F_44 ( V_78 ) ) {
F_45 () ;
}
V_80 -> V_81 = V_82 ;
V_80 -> V_59 = error ;
F_46 ( & V_80 -> V_83 , V_78 ) ;
}
static void F_47 ( struct V_77 * V_78 )
{
struct V_79 * V_80 , * V_84 ;
int V_85 ;
V_85 = ! F_44 ( V_78 ) ;
F_48 (q, t, pt, list) {
F_49 ( V_80 -> V_86 ) ;
F_50 () ;
V_80 -> V_81 = V_80 -> V_59 ;
}
if ( V_85 )
F_51 () ;
}
static void F_52 ( struct V_18 * V_19 , struct V_79 * V_80 )
{
F_53 ( & V_80 -> V_83 ) ;
if ( V_80 -> V_22 > 1 )
V_19 -> V_25 -- ;
}
static int F_54 ( struct V_18 * V_19 , struct V_79 * V_80 )
{
struct V_26 * V_63 ;
struct V_79 * V_87 ;
if ( V_80 -> V_88 == 0 )
return 0 ;
if ( V_19 -> V_25 )
return 1 ;
if ( V_80 -> V_22 > 1 )
return 1 ;
V_63 = V_19 -> V_27 + V_80 -> V_21 [ 0 ] . V_28 ;
if ( F_44 ( & V_63 -> V_54 ) )
return 0 ;
if ( V_63 -> V_64 ) {
F_55 ( V_80 -> V_21 [ 0 ] . V_61 >= 0 ) ;
return 0 ;
}
V_87 = F_56 ( & V_63 -> V_54 , struct V_79 , V_83 ) ;
F_55 ( V_87 -> V_22 != 1 ) ;
F_55 ( V_87 -> V_21 [ 0 ] . V_28 != V_80 -> V_21 [ 0 ] . V_28 ) ;
if ( V_87 -> V_21 [ 0 ] . V_61 == 0 )
return 1 ;
return 0 ;
}
static int F_57 ( struct V_18 * V_19 , int V_89 , struct V_77 * V_78 )
{
struct V_79 * V_80 ;
struct V_77 * V_90 ;
struct V_77 * V_91 ;
int V_92 = 0 ;
if ( V_89 == - 1 )
V_91 = & V_19 -> V_54 ;
else
V_91 = & V_19 -> V_27 [ V_89 ] . V_54 ;
V_24:
V_90 = V_91 -> V_93 ;
while ( V_90 != V_91 ) {
int error , V_94 ;
V_80 = F_20 ( V_90 , struct V_79 , V_83 ) ;
V_90 = V_90 -> V_93 ;
if ( V_89 != - 1 && V_19 -> V_27 [ V_89 ] . V_64 == 0 &&
V_80 -> V_88 )
break;
error = F_42 ( V_19 , V_80 -> V_21 , V_80 -> V_22 ,
V_80 -> V_70 , V_80 -> V_59 ) ;
if ( error > 0 )
continue;
F_52 ( V_19 , V_80 ) ;
if ( error ) {
V_94 = 0 ;
} else {
V_92 = 1 ;
V_94 = F_54 ( V_19 , V_80 ) ;
}
F_43 ( V_78 , V_80 , error ) ;
if ( V_94 )
goto V_24;
}
return V_92 ;
}
static void F_58 ( struct V_18 * V_19 , struct V_20 * V_21 , int V_22 ,
int V_95 , struct V_77 * V_78 )
{
int V_32 ;
int V_96 ;
V_96 = 1 ;
V_97:
if ( V_19 -> V_25 ) {
if ( F_57 ( V_19 , - 1 , V_78 ) ) {
V_96 = 1 ;
V_95 = 1 ;
V_21 = NULL ;
}
}
if ( ! V_96 )
goto V_98;
if ( ! V_21 ) {
for ( V_32 = 0 ; V_32 < V_19 -> V_33 ; V_32 ++ ) {
if ( F_57 ( V_19 , V_32 , V_78 ) ) {
V_95 = 1 ;
V_96 = 1 ;
}
}
goto V_99;
}
for ( V_32 = 0 ; V_32 < V_22 ; V_32 ++ ) {
if ( V_21 [ V_32 ] . V_61 > 0 ||
( V_21 [ V_32 ] . V_61 < 0 &&
V_19 -> V_27 [ V_21 [ V_32 ] . V_28 ] . V_64 == 0 ) )
if ( F_57 ( V_19 , V_21 [ V_32 ] . V_28 , V_78 ) ) {
V_95 = 1 ;
V_96 = 1 ;
}
}
V_99:
if ( V_96 ) {
V_96 = 0 ;
goto V_97;
}
V_98:
if ( V_95 )
V_19 -> V_100 = F_37 () ;
}
static int F_59 ( struct V_18 * V_19 , T_3 V_89 )
{
int V_101 ;
struct V_79 * V_80 ;
V_101 = 0 ;
F_60 (q, &sma->sem_base[semnum].sem_pending, list) {
struct V_20 * V_21 = V_80 -> V_21 ;
F_55 ( V_21 -> V_28 != V_89 ) ;
if ( ( V_21 -> V_61 < 0 ) && ! ( V_21 -> V_68 & V_75 ) )
V_101 ++ ;
}
F_60 (q, &sma->sem_pending, list) {
struct V_20 * V_21 = V_80 -> V_21 ;
int V_22 = V_80 -> V_22 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_22 ; V_32 ++ )
if ( V_21 [ V_32 ] . V_28 == V_89
&& ( V_21 [ V_32 ] . V_61 < 0 )
&& ! ( V_21 [ V_32 ] . V_68 & V_75 ) )
V_101 ++ ;
}
return V_101 ;
}
static int F_61 ( struct V_18 * V_19 , T_3 V_89 )
{
int V_102 ;
struct V_79 * V_80 ;
V_102 = 0 ;
F_60 (q, &sma->sem_base[semnum].sem_pending, list) {
struct V_20 * V_21 = V_80 -> V_21 ;
F_55 ( V_21 -> V_28 != V_89 ) ;
if ( ( V_21 -> V_61 == 0 ) && ! ( V_21 -> V_68 & V_75 ) )
V_102 ++ ;
}
F_60 (q, &sma->sem_pending, list) {
struct V_20 * V_21 = V_80 -> V_21 ;
int V_22 = V_80 -> V_22 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_22 ; V_32 ++ )
if ( V_21 [ V_32 ] . V_28 == V_89
&& ( V_21 [ V_32 ] . V_61 == 0 )
&& ! ( V_21 [ V_32 ] . V_68 & V_75 ) )
V_102 ++ ;
}
return V_102 ;
}
static void V_14 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
struct V_57 * V_58 , * V_103 ;
struct V_79 * V_80 , * V_104 ;
struct V_18 * V_19 = F_20 ( V_36 , struct V_18 , V_31 ) ;
struct V_77 V_105 ;
int V_32 ;
F_62 ( & V_19 -> V_31 . V_29 ) ;
F_48 (un, tu, &sma->list_id, list_id) {
F_53 ( & V_58 -> V_55 ) ;
F_10 ( & V_58 -> V_106 -> V_29 ) ;
V_58 -> V_107 = - 1 ;
F_63 ( & V_58 -> V_108 ) ;
F_12 ( & V_58 -> V_106 -> V_29 ) ;
F_64 ( V_58 , V_109 ) ;
}
F_35 ( & V_105 ) ;
F_48 (q, tq, &sma->sem_pending, list) {
F_52 ( V_19 , V_80 ) ;
F_43 ( & V_105 , V_80 , - V_110 ) ;
}
for ( V_32 = 0 ; V_32 < V_19 -> V_33 ; V_32 ++ ) {
struct V_26 * V_26 = V_19 -> V_27 + V_32 ;
F_48 (q, tq, &sem->sem_pending, list) {
F_52 ( V_19 , V_80 ) ;
F_43 ( & V_105 , V_80 , - V_110 ) ;
}
}
F_28 ( V_2 , V_19 ) ;
F_15 ( V_19 , - 1 ) ;
F_38 () ;
F_47 ( & V_105 ) ;
V_2 -> V_11 -= V_19 -> V_33 ;
F_34 ( V_19 ) ;
F_26 ( V_19 ) ;
}
static unsigned long F_65 ( void T_4 * V_111 , struct V_112 * V_113 , int V_114 )
{
switch( V_114 ) {
case V_115 :
return F_66 ( V_111 , V_113 , sizeof( * V_113 ) ) ;
case V_116 :
{
struct V_117 V_118 ;
memset ( & V_118 , 0 , sizeof( V_118 ) ) ;
F_67 ( & V_113 -> V_31 , & V_118 . V_31 ) ;
V_118 . V_100 = V_113 -> V_100 ;
V_118 . V_56 = V_113 -> V_56 ;
V_118 . V_33 = V_113 -> V_33 ;
return F_66 ( V_111 , & V_118 , sizeof( V_118 ) ) ;
}
default:
return - V_38 ;
}
}
static int F_68 ( struct V_1 * V_2 , int V_107 ,
int V_119 , int V_114 , void T_4 * V_120 )
{
int V_121 ;
struct V_18 * V_19 ;
switch( V_119 ) {
case V_122 :
case V_123 :
{
struct V_124 V_124 ;
int V_125 ;
V_121 = F_69 ( NULL , V_119 ) ;
if ( V_121 )
return V_121 ;
memset ( & V_124 , 0 , sizeof( V_124 ) ) ;
V_124 . V_126 = V_2 -> V_9 ;
V_124 . V_127 = V_2 -> V_5 ;
V_124 . V_128 = V_2 -> V_3 ;
V_124 . V_129 = V_2 -> V_7 ;
V_124 . V_130 = V_66 ;
V_124 . V_131 = V_132 ;
V_124 . V_133 = V_134 ;
V_124 . V_135 = V_136 ;
F_70 ( & F_5 ( V_2 ) . V_137 ) ;
if ( V_119 == V_123 ) {
V_124 . V_138 = F_5 ( V_2 ) . V_139 ;
V_124 . V_140 = V_2 -> V_11 ;
} else {
V_124 . V_138 = V_141 ;
V_124 . V_140 = V_72 ;
}
V_125 = F_71 ( & F_5 ( V_2 ) ) ;
F_72 ( & F_5 ( V_2 ) . V_137 ) ;
if ( F_66 ( V_120 , & V_124 , sizeof( struct V_124 ) ) )
return - V_142 ;
return ( V_125 < 0 ) ? 0 : V_125 ;
}
case V_143 :
case V_144 :
{
struct V_112 V_145 ;
int V_34 = 0 ;
memset ( & V_145 , 0 , sizeof( V_145 ) ) ;
F_73 () ;
if ( V_119 == V_144 ) {
V_19 = F_22 ( V_2 , V_107 ) ;
if ( F_18 ( V_19 ) ) {
V_121 = F_74 ( V_19 ) ;
goto V_146;
}
V_34 = V_19 -> V_31 . V_34 ;
} else {
V_19 = F_23 ( V_2 , V_107 ) ;
if ( F_18 ( V_19 ) ) {
V_121 = F_74 ( V_19 ) ;
goto V_146;
}
}
V_121 = - V_147 ;
if ( F_75 ( V_2 , & V_19 -> V_31 , V_148 ) )
goto V_146;
V_121 = F_69 ( V_19 , V_119 ) ;
if ( V_121 )
goto V_146;
F_76 ( & V_19 -> V_31 , & V_145 . V_31 ) ;
V_145 . V_100 = V_19 -> V_100 ;
V_145 . V_56 = V_19 -> V_56 ;
V_145 . V_33 = V_19 -> V_33 ;
F_38 () ;
if ( F_65 ( V_120 , & V_145 , V_114 ) )
return - V_142 ;
return V_34 ;
}
default:
return - V_38 ;
}
V_146:
F_38 () ;
return V_121 ;
}
static int F_77 ( struct V_1 * V_2 , int V_107 , int V_89 ,
unsigned long V_149 )
{
struct V_57 * V_58 ;
struct V_18 * V_19 ;
struct V_26 * V_63 ;
int V_121 ;
struct V_77 V_105 ;
int V_150 ;
#if F_78 ( V_151 ) && F_78 ( V_152 )
V_150 = V_149 >> 32 ;
#else
V_150 = V_149 ;
#endif
if ( V_150 > V_66 || V_150 < 0 )
return - V_74 ;
F_35 ( & V_105 ) ;
F_73 () ;
V_19 = F_23 ( V_2 , V_107 ) ;
if ( F_18 ( V_19 ) ) {
F_38 () ;
return F_74 ( V_19 ) ;
}
if ( V_89 < 0 || V_89 >= V_19 -> V_33 ) {
F_38 () ;
return - V_38 ;
}
if ( F_75 ( V_2 , & V_19 -> V_31 , V_153 ) ) {
F_38 () ;
return - V_147 ;
}
V_121 = F_69 ( V_19 , V_154 ) ;
if ( V_121 ) {
F_38 () ;
return - V_147 ;
}
F_9 ( V_19 , NULL , - 1 ) ;
V_63 = & V_19 -> V_27 [ V_89 ] ;
F_62 ( & V_19 -> V_31 . V_29 ) ;
F_60 (un, &sma->list_id, list_id)
V_58 -> V_71 [ V_89 ] = 0 ;
V_63 -> V_64 = V_150 ;
V_63 -> V_73 = F_79 ( V_155 ) ;
V_19 -> V_56 = F_37 () ;
F_58 ( V_19 , NULL , 0 , 0 , & V_105 ) ;
F_15 ( V_19 , - 1 ) ;
F_38 () ;
F_47 ( & V_105 ) ;
return 0 ;
}
static int F_80 ( struct V_1 * V_2 , int V_107 , int V_89 ,
int V_119 , void T_4 * V_120 )
{
struct V_18 * V_19 ;
struct V_26 * V_63 ;
int V_121 , V_45 ;
T_3 V_156 [ V_157 ] ;
T_3 * V_158 = V_156 ;
struct V_77 V_105 ;
F_35 ( & V_105 ) ;
F_73 () ;
V_19 = F_23 ( V_2 , V_107 ) ;
if ( F_18 ( V_19 ) ) {
F_38 () ;
return F_74 ( V_19 ) ;
}
V_45 = V_19 -> V_33 ;
V_121 = - V_147 ;
if ( F_75 ( V_2 , & V_19 -> V_31 , V_119 == V_159 ? V_153 : V_148 ) )
goto V_160;
V_121 = F_69 ( V_19 , V_119 ) ;
if ( V_121 )
goto V_160;
V_121 = - V_147 ;
switch ( V_119 ) {
case V_161 :
{
T_3 T_4 * V_162 = V_120 ;
int V_32 ;
F_9 ( V_19 , NULL , - 1 ) ;
if( V_45 > V_157 ) {
if ( ! F_81 ( V_19 ) ) {
F_15 ( V_19 , - 1 ) ;
F_38 () ;
V_121 = - V_110 ;
goto V_163;
}
F_15 ( V_19 , - 1 ) ;
F_38 () ;
V_158 = F_82 ( sizeof( T_3 ) * V_45 ) ;
if( V_158 == NULL ) {
F_27 ( V_19 ) ;
return - V_50 ;
}
F_73 () ;
F_25 ( V_19 ) ;
if ( V_19 -> V_31 . V_37 ) {
F_15 ( V_19 , - 1 ) ;
F_38 () ;
V_121 = - V_110 ;
goto V_163;
}
}
for ( V_32 = 0 ; V_32 < V_19 -> V_33 ; V_32 ++ )
V_158 [ V_32 ] = V_19 -> V_27 [ V_32 ] . V_64 ;
F_15 ( V_19 , - 1 ) ;
F_38 () ;
V_121 = 0 ;
if( F_66 ( V_162 , V_158 , V_45 * sizeof( T_3 ) ) )
V_121 = - V_142 ;
goto V_163;
}
case V_159 :
{
int V_32 ;
struct V_57 * V_58 ;
if ( ! F_81 ( V_19 ) ) {
F_38 () ;
return - V_110 ;
}
F_38 () ;
if( V_45 > V_157 ) {
V_158 = F_82 ( sizeof( T_3 ) * V_45 ) ;
if( V_158 == NULL ) {
F_27 ( V_19 ) ;
return - V_50 ;
}
}
if ( F_83 ( V_158 , V_120 , V_45 * sizeof( T_3 ) ) ) {
F_27 ( V_19 ) ;
V_121 = - V_142 ;
goto V_163;
}
for ( V_32 = 0 ; V_32 < V_45 ; V_32 ++ ) {
if ( V_158 [ V_32 ] > V_66 ) {
F_27 ( V_19 ) ;
V_121 = - V_74 ;
goto V_163;
}
}
F_73 () ;
F_25 ( V_19 ) ;
if ( V_19 -> V_31 . V_37 ) {
F_15 ( V_19 , - 1 ) ;
F_38 () ;
V_121 = - V_110 ;
goto V_163;
}
for ( V_32 = 0 ; V_32 < V_45 ; V_32 ++ )
V_19 -> V_27 [ V_32 ] . V_64 = V_158 [ V_32 ] ;
F_62 ( & V_19 -> V_31 . V_29 ) ;
F_60 (un, &sma->list_id, list_id) {
for ( V_32 = 0 ; V_32 < V_45 ; V_32 ++ )
V_58 -> V_71 [ V_32 ] = 0 ;
}
V_19 -> V_56 = F_37 () ;
F_58 ( V_19 , NULL , 0 , 0 , & V_105 ) ;
V_121 = 0 ;
goto V_146;
}
}
V_121 = - V_38 ;
if ( V_89 < 0 || V_89 >= V_45 )
goto V_160;
F_9 ( V_19 , NULL , - 1 ) ;
V_63 = & V_19 -> V_27 [ V_89 ] ;
switch ( V_119 ) {
case V_164 :
V_121 = V_63 -> V_64 ;
goto V_146;
case V_165 :
V_121 = V_63 -> V_73 ;
goto V_146;
case V_166 :
V_121 = F_59 ( V_19 , V_89 ) ;
goto V_146;
case V_167 :
V_121 = F_61 ( V_19 , V_89 ) ;
goto V_146;
}
V_146:
F_15 ( V_19 , - 1 ) ;
V_160:
F_38 () ;
F_47 ( & V_105 ) ;
V_163:
if( V_158 != V_156 )
F_84 ( V_158 , sizeof( T_3 ) * V_45 ) ;
return V_121 ;
}
static inline unsigned long
F_85 ( struct V_112 * V_118 , void T_4 * V_111 , int V_114 )
{
switch( V_114 ) {
case V_115 :
if ( F_83 ( V_118 , V_111 , sizeof( * V_118 ) ) )
return - V_142 ;
return 0 ;
case V_116 :
{
struct V_117 V_168 ;
if( F_83 ( & V_168 , V_111 , sizeof( V_168 ) ) )
return - V_142 ;
V_118 -> V_31 . V_169 = V_168 . V_31 . V_169 ;
V_118 -> V_31 . V_170 = V_168 . V_31 . V_170 ;
V_118 -> V_31 . V_51 = V_168 . V_31 . V_51 ;
return 0 ;
}
default:
return - V_38 ;
}
}
static int F_86 ( struct V_1 * V_2 , int V_107 ,
int V_119 , int V_114 , void T_4 * V_120 )
{
struct V_18 * V_19 ;
int V_121 ;
struct V_112 V_171 ;
struct V_35 * V_36 ;
if( V_119 == V_172 ) {
if ( F_85 ( & V_171 , V_120 , V_114 ) )
return - V_142 ;
}
V_36 = F_87 ( V_2 , & F_5 ( V_2 ) , V_107 , V_119 ,
& V_171 . V_31 , 0 ) ;
if ( F_18 ( V_36 ) )
return F_74 ( V_36 ) ;
V_19 = F_20 ( V_36 , struct V_18 , V_31 ) ;
V_121 = F_69 ( V_19 , V_119 ) ;
if ( V_121 ) {
F_38 () ;
goto V_173;
}
switch( V_119 ) {
case V_174 :
F_9 ( V_19 , NULL , - 1 ) ;
V_14 ( V_2 , V_36 ) ;
goto V_173;
case V_172 :
F_9 ( V_19 , NULL , - 1 ) ;
V_121 = F_88 ( & V_171 . V_31 , V_36 ) ;
if ( V_121 )
goto V_146;
V_19 -> V_56 = F_37 () ;
break;
default:
F_38 () ;
V_121 = - V_38 ;
goto V_173;
}
V_146:
F_15 ( V_19 , - 1 ) ;
F_38 () ;
V_173:
F_89 ( & F_5 ( V_2 ) . V_137 ) ;
return V_121 ;
}
static inline int F_90 ( struct V_175 * * V_176 )
{
struct V_175 * V_177 ;
V_177 = V_155 -> V_178 . V_177 ;
if ( ! V_177 ) {
V_177 = F_91 ( sizeof( * V_177 ) , V_179 ) ;
if ( V_177 == NULL )
return - V_50 ;
F_36 ( & V_177 -> V_29 ) ;
F_92 ( & V_177 -> V_180 , 1 ) ;
F_35 ( & V_177 -> V_108 ) ;
V_155 -> V_178 . V_177 = V_177 ;
}
* V_176 = V_177 ;
return 0 ;
}
static struct V_57 * F_93 ( struct V_175 * V_106 , int V_107 )
{
struct V_57 * V_58 ;
F_94 (un, &ulp->list_proc, list_proc) {
if ( V_58 -> V_107 == V_107 )
return V_58 ;
}
return NULL ;
}
static struct V_57 * F_95 ( struct V_175 * V_106 , int V_107 )
{
struct V_57 * V_58 ;
F_62 ( & V_106 -> V_29 ) ;
V_58 = F_93 ( V_106 , V_107 ) ;
if ( V_58 ) {
F_63 ( & V_58 -> V_108 ) ;
F_96 ( & V_58 -> V_108 , & V_106 -> V_108 ) ;
}
return V_58 ;
}
static struct V_57 * F_97 ( struct V_1 * V_2 , int V_107 )
{
struct V_18 * V_19 ;
struct V_175 * V_106 ;
struct V_57 * V_58 , * V_181 ;
int V_45 , error ;
error = F_90 ( & V_106 ) ;
if ( error )
return F_21 ( error ) ;
F_73 () ;
F_10 ( & V_106 -> V_29 ) ;
V_58 = F_95 ( V_106 , V_107 ) ;
F_12 ( & V_106 -> V_29 ) ;
if ( F_98 ( V_58 != NULL ) )
goto V_118;
V_19 = F_23 ( V_2 , V_107 ) ;
if ( F_18 ( V_19 ) ) {
F_38 () ;
return F_19 ( V_19 ) ;
}
V_45 = V_19 -> V_33 ;
if ( ! F_81 ( V_19 ) ) {
F_38 () ;
V_58 = F_21 ( - V_110 ) ;
goto V_118;
}
F_38 () ;
V_181 = F_91 ( sizeof( struct V_57 ) + sizeof( short ) * V_45 , V_179 ) ;
if ( ! V_181 ) {
F_27 ( V_19 ) ;
return F_21 ( - V_50 ) ;
}
F_73 () ;
F_25 ( V_19 ) ;
if ( V_19 -> V_31 . V_37 ) {
F_15 ( V_19 , - 1 ) ;
F_38 () ;
F_99 ( V_181 ) ;
V_58 = F_21 ( - V_110 ) ;
goto V_118;
}
F_10 ( & V_106 -> V_29 ) ;
V_58 = F_95 ( V_106 , V_107 ) ;
if ( V_58 ) {
F_99 ( V_181 ) ;
goto V_182;
}
V_181 -> V_71 = ( short * ) & V_181 [ 1 ] ;
V_181 -> V_106 = V_106 ;
V_181 -> V_107 = V_107 ;
F_62 ( & V_106 -> V_29 ) ;
F_96 ( & V_181 -> V_108 , & V_106 -> V_108 ) ;
F_62 ( & V_19 -> V_31 . V_29 ) ;
F_100 ( & V_181 -> V_55 , & V_19 -> V_55 ) ;
V_58 = V_181 ;
V_182:
F_12 ( & V_106 -> V_29 ) ;
F_15 ( V_19 , - 1 ) ;
V_118:
return V_58 ;
}
static int F_101 ( struct V_79 * V_80 )
{
int error ;
error = V_80 -> V_81 ;
while ( F_11 ( error == V_82 ) ) {
F_102 () ;
error = V_80 -> V_81 ;
}
return error ;
}
int F_103 ( unsigned long V_183 , struct V_184 * V_185 )
{
struct V_175 * V_177 ;
int error ;
if ( V_183 & V_186 ) {
error = F_90 ( & V_177 ) ;
if ( error )
return error ;
F_104 ( & V_177 -> V_180 ) ;
V_185 -> V_178 . V_177 = V_177 ;
} else
V_185 -> V_178 . V_177 = NULL ;
return 0 ;
}
void F_105 ( struct V_184 * V_185 )
{
struct V_175 * V_106 ;
V_106 = V_185 -> V_178 . V_177 ;
if ( ! V_106 )
return;
V_185 -> V_178 . V_177 = NULL ;
if ( ! F_106 ( & V_106 -> V_180 ) )
return;
for (; ; ) {
struct V_18 * V_19 ;
struct V_57 * V_58 ;
struct V_77 V_105 ;
int V_107 , V_32 ;
F_73 () ;
V_58 = F_107 ( V_106 -> V_108 . V_93 ,
struct V_57 , V_108 ) ;
if ( & V_58 -> V_108 == & V_106 -> V_108 )
V_107 = - 1 ;
else
V_107 = V_58 -> V_107 ;
if ( V_107 == - 1 ) {
F_38 () ;
break;
}
V_19 = F_23 ( V_185 -> V_187 -> V_188 , V_58 -> V_107 ) ;
if ( F_18 ( V_19 ) ) {
F_38 () ;
continue;
}
F_9 ( V_19 , NULL , - 1 ) ;
V_58 = F_93 ( V_106 , V_107 ) ;
if ( V_58 == NULL ) {
F_15 ( V_19 , - 1 ) ;
F_38 () ;
continue;
}
F_62 ( & V_19 -> V_31 . V_29 ) ;
F_53 ( & V_58 -> V_55 ) ;
F_10 ( & V_106 -> V_29 ) ;
F_63 ( & V_58 -> V_108 ) ;
F_12 ( & V_106 -> V_29 ) ;
for ( V_32 = 0 ; V_32 < V_19 -> V_33 ; V_32 ++ ) {
struct V_26 * V_189 = & V_19 -> V_27 [ V_32 ] ;
if ( V_58 -> V_71 [ V_32 ] ) {
V_189 -> V_64 += V_58 -> V_71 [ V_32 ] ;
if ( V_189 -> V_64 < 0 )
V_189 -> V_64 = 0 ;
if ( V_189 -> V_64 > V_66 )
V_189 -> V_64 = V_66 ;
V_189 -> V_73 = F_79 ( V_155 ) ;
}
}
F_35 ( & V_105 ) ;
F_58 ( V_19 , NULL , 0 , 1 , & V_105 ) ;
F_15 ( V_19 , - 1 ) ;
F_38 () ;
F_47 ( & V_105 ) ;
F_64 ( V_58 , V_109 ) ;
}
F_99 ( V_106 ) ;
}
static int V_17 ( struct V_190 * V_39 , void * V_191 )
{
struct V_192 * V_193 = F_108 ( V_39 ) ;
struct V_18 * V_19 = V_191 ;
return F_109 ( V_39 ,
L_3 ,
V_19 -> V_31 . V_44 ,
V_19 -> V_31 . V_34 ,
V_19 -> V_31 . V_51 ,
V_19 -> V_33 ,
F_110 ( V_193 , V_19 -> V_31 . V_169 ) ,
F_111 ( V_193 , V_19 -> V_31 . V_170 ) ,
F_110 ( V_193 , V_19 -> V_31 . V_194 ) ,
F_111 ( V_193 , V_19 -> V_31 . V_195 ) ,
V_19 -> V_100 ,
V_19 -> V_56 ) ;
}
