static inline void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_3 , int V_4 )
{
V_2 -> V_3 = V_3 ;
V_2 -> V_4 = V_4 ;
}
static inline int F_2 ( struct V_1 * V_5 ,
struct V_1 * V_6 )
{
return ( V_5 -> V_3 > V_6 -> V_3 ? + 1 :
( V_5 -> V_3 < V_6 -> V_3 ? - 1 : V_5 -> V_4 - V_6 -> V_4 ) ) ;
}
static inline int F_3 ( struct V_7 * V_8 )
{
return ! F_4 ( V_8 ) ;
}
static inline struct V_9 * F_5 ( T_1 * V_8 )
{
return F_6 ( V_8 , struct V_10 , V_11 ) -> V_12 ;
}
static inline struct V_9 * F_7 ( T_2 * V_8 )
{
return F_6 ( V_8 , struct V_13 , V_14 ) -> V_15 ;
}
static inline int F_8 ( int V_16 )
{
return V_16 != V_17 ;
}
static void F_9 ( struct V_18 * V_19 )
{
F_10 ( & V_19 -> V_20 ) ;
F_11 ( & V_19 -> V_21 ) ;
}
static inline int F_12 ( struct V_22 * V_23 )
{
return ! F_4 ( & V_23 -> V_24 ) || V_23 -> V_25 != V_26 ;
}
static int F_13 ( struct V_18 * V_19 , int V_27 ,
int (* F_14)( void * , void * , int ) , void * V_28 ,
void * V_29 , void * V_30 )
{
int error , V_31 = 0 ;
unsigned long V_32 ;
struct V_7 * V_33 = & V_19 -> V_20 ;
struct V_34 * V_35 ;
struct V_34 V_36 ;
F_15 ( & V_19 -> V_21 , V_32 ) ;
F_16 (tncur, lsthead, llink) {
if ( V_35 -> V_30 == V_30 &&
( V_35 -> V_29 == V_29 || ++ V_31 > V_27 ) ) {
error = - 1 ;
goto V_37;
}
}
V_36 . V_30 = V_30 ;
V_36 . V_29 = V_29 ;
F_17 ( & V_36 . V_38 , V_33 ) ;
F_18 ( & V_19 -> V_21 , V_32 ) ;
error = (* F_14)( V_28 , V_29 , V_31 ) ;
F_15 ( & V_19 -> V_21 , V_32 ) ;
F_19 ( & V_36 . V_38 ) ;
V_37:
F_18 ( & V_19 -> V_21 , V_32 ) ;
return error ;
}
static inline void F_20 ( T_3 * V_39 ,
unsigned long V_40 , int V_41 )
{
unsigned long V_32 ;
F_21 ( & V_39 -> V_21 , V_32 , V_41 ) ;
F_22 ( V_39 , V_40 ) ;
F_18 ( & V_39 -> V_21 , V_32 ) ;
}
static inline void F_20 ( T_3 * V_39 ,
unsigned long V_40 , int V_41 )
{
F_23 ( V_39 , V_40 ) ;
}
static int F_24 ( void * V_28 , void * V_29 , int V_31 )
{
F_20 ( ( T_3 * ) V_29 , V_42 ,
1 + V_31 ) ;
return 0 ;
}
static void F_25 ( T_3 * V_43 )
{
int V_44 = F_26 () ;
F_13 ( & V_45 , V_46 ,
F_24 , NULL , V_43 , ( void * ) ( long ) V_44 ) ;
F_27 () ;
}
static void F_28 ( struct V_22 * V_23 , struct V_9 * V_15 )
{
struct V_7 * V_33 = & V_15 -> V_47 ;
struct V_10 * V_48 ;
while ( ! F_4 ( V_33 ) ) {
V_48 = F_29 ( V_33 , struct V_10 , V_38 ) ;
F_19 ( & V_48 -> V_38 ) ;
F_30 ( V_48 -> V_49 , & V_48 -> V_11 ) ;
F_31 ( V_50 , V_48 ) ;
}
}
static int F_32 ( struct V_22 * V_23 ,
int (* F_33)( struct V_22 * ,
struct V_7 * , void * ) ,
void * V_28 ,
int V_51 )
{
int error , V_52 = 0 ;
unsigned long V_32 ;
struct V_9 * V_15 , * V_53 ;
F_34 ( V_54 ) ;
F_35 ( & V_23 -> V_55 , V_51 ) ;
F_15 ( & V_23 -> V_21 , V_32 ) ;
F_36 ( & V_23 -> V_24 , & V_54 ) ;
V_23 -> V_25 = NULL ;
F_18 ( & V_23 -> V_21 , V_32 ) ;
error = (* F_33)( V_23 , & V_54 , V_28 ) ;
F_15 ( & V_23 -> V_21 , V_32 ) ;
for ( V_53 = V_23 -> V_25 ; ( V_15 = V_53 ) != NULL ;
V_53 = V_15 -> V_56 , V_15 -> V_56 = V_26 ) {
if ( ! F_3 ( & V_15 -> V_57 ) )
F_37 ( & V_15 -> V_57 , & V_23 -> V_24 ) ;
}
V_23 -> V_25 = V_26 ;
F_38 ( & V_54 , & V_23 -> V_24 ) ;
if ( ! F_4 ( & V_23 -> V_24 ) ) {
if ( F_39 ( & V_23 -> V_43 ) )
F_40 ( & V_23 -> V_43 ) ;
if ( F_39 ( & V_23 -> V_58 ) )
V_52 ++ ;
}
F_18 ( & V_23 -> V_21 , V_32 ) ;
F_41 ( & V_23 -> V_55 ) ;
if ( V_52 )
F_25 ( & V_23 -> V_58 ) ;
return error ;
}
static int F_42 ( struct V_22 * V_23 , struct V_9 * V_15 )
{
unsigned long V_32 ;
struct V_3 * V_3 = V_15 -> V_2 . V_3 ;
F_28 ( V_23 , V_15 ) ;
F_43 ( & V_3 -> V_59 ) ;
if ( F_3 ( & V_15 -> V_60 ) )
F_44 ( & V_15 -> V_60 ) ;
F_45 ( & V_3 -> V_59 ) ;
F_46 ( & V_15 -> V_61 , & V_23 -> V_62 ) ;
F_15 ( & V_23 -> V_21 , V_32 ) ;
if ( F_3 ( & V_15 -> V_57 ) )
F_44 ( & V_15 -> V_57 ) ;
F_18 ( & V_23 -> V_21 , V_32 ) ;
F_31 ( V_63 , V_15 ) ;
F_47 ( & V_23 -> V_64 -> V_65 ) ;
return 0 ;
}
static void F_48 ( struct V_22 * V_23 )
{
struct V_66 * V_67 ;
struct V_9 * V_15 ;
if ( F_39 ( & V_23 -> V_58 ) )
F_25 ( & V_23 -> V_58 ) ;
F_49 ( & V_68 ) ;
for ( V_67 = F_50 ( & V_23 -> V_62 ) ; V_67 ; V_67 = F_51 ( V_67 ) ) {
V_15 = F_52 ( V_67 , struct V_9 , V_61 ) ;
F_28 ( V_23 , V_15 ) ;
}
while ( ( V_67 = F_50 ( & V_23 -> V_62 ) ) != NULL ) {
V_15 = F_52 ( V_67 , struct V_9 , V_61 ) ;
F_42 ( V_23 , V_15 ) ;
}
F_41 ( & V_68 ) ;
F_53 ( & V_23 -> V_55 ) ;
F_54 ( V_23 -> V_64 ) ;
F_55 ( V_23 ) ;
}
static int F_56 ( struct V_69 * V_69 , struct V_3 * V_3 )
{
struct V_22 * V_23 = V_3 -> V_70 ;
if ( V_23 )
F_48 ( V_23 ) ;
return 0 ;
}
static int F_57 ( struct V_22 * V_23 , struct V_7 * V_71 ,
void * V_28 )
{
struct V_9 * V_15 , * V_72 ;
F_58 (epi, tmp, head, rdllink) {
if ( V_15 -> V_2 . V_3 -> V_73 -> V_74 ( V_15 -> V_2 . V_3 , NULL ) &
V_15 -> V_75 . V_40 )
return V_42 | V_76 ;
else {
F_44 ( & V_15 -> V_57 ) ;
}
}
return 0 ;
}
static int F_59 ( void * V_28 , void * V_29 , int V_31 )
{
return F_32 ( V_28 , F_57 , NULL , V_31 + 1 ) ;
}
static unsigned int F_60 ( struct V_3 * V_3 , T_2 * V_11 )
{
int V_77 ;
struct V_22 * V_23 = V_3 -> V_70 ;
V_58 ( V_3 , & V_23 -> V_58 , V_11 ) ;
V_77 = F_13 ( & V_78 , V_46 ,
F_59 , V_23 , V_23 , V_79 ) ;
return V_77 != - 1 ? V_77 : 0 ;
}
static inline int F_61 ( struct V_3 * V_80 )
{
return V_80 -> V_73 == & V_81 ;
}
void F_62 ( struct V_3 * V_3 )
{
struct V_7 * V_33 = & V_3 -> V_82 ;
struct V_22 * V_23 ;
struct V_9 * V_15 ;
F_49 ( & V_68 ) ;
while ( ! F_4 ( V_33 ) ) {
V_15 = F_29 ( V_33 , struct V_9 , V_60 ) ;
V_23 = V_15 -> V_23 ;
F_44 ( & V_15 -> V_60 ) ;
F_35 ( & V_23 -> V_55 , 0 ) ;
F_42 ( V_23 , V_15 ) ;
F_41 ( & V_23 -> V_55 ) ;
}
F_41 ( & V_68 ) ;
}
static int F_63 ( struct V_22 * * V_83 )
{
int error ;
struct V_84 * V_64 ;
struct V_22 * V_23 ;
V_64 = F_64 () ;
error = - V_85 ;
V_23 = F_65 ( sizeof( * V_23 ) , V_86 ) ;
if ( F_66 ( ! V_23 ) )
goto F_54;
F_11 ( & V_23 -> V_21 ) ;
F_67 ( & V_23 -> V_55 ) ;
F_68 ( & V_23 -> V_43 ) ;
F_68 ( & V_23 -> V_58 ) ;
F_10 ( & V_23 -> V_24 ) ;
V_23 -> V_62 = V_87 ;
V_23 -> V_25 = V_26 ;
V_23 -> V_64 = V_64 ;
* V_83 = V_23 ;
return 0 ;
F_54:
F_54 ( V_64 ) ;
return error ;
}
static struct V_9 * F_69 ( struct V_22 * V_23 , struct V_3 * V_3 , int V_4 )
{
int V_88 ;
struct V_66 * V_67 ;
struct V_9 * V_15 , * V_89 = NULL ;
struct V_1 V_2 ;
F_1 ( & V_2 , V_3 , V_4 ) ;
for ( V_67 = V_23 -> V_62 . V_66 ; V_67 ; ) {
V_15 = F_52 ( V_67 , struct V_9 , V_61 ) ;
V_88 = F_2 ( & V_2 , & V_15 -> V_2 ) ;
if ( V_88 > 0 )
V_67 = V_67 -> V_90 ;
else if ( V_88 < 0 )
V_67 = V_67 -> V_91 ;
else {
V_89 = V_15 ;
break;
}
}
return V_89 ;
}
static int F_70 ( T_1 * V_11 , unsigned V_92 , int V_93 , void * V_94 )
{
int V_52 = 0 ;
unsigned long V_32 ;
struct V_9 * V_15 = F_5 ( V_11 ) ;
struct V_22 * V_23 = V_15 -> V_23 ;
F_15 ( & V_23 -> V_21 , V_32 ) ;
if ( ! ( V_15 -> V_75 . V_40 & ~ V_95 ) )
goto V_37;
if ( V_94 && ! ( ( unsigned long ) V_94 & V_15 -> V_75 . V_40 ) )
goto V_37;
if ( F_66 ( V_23 -> V_25 != V_26 ) ) {
if ( V_15 -> V_56 == V_26 ) {
V_15 -> V_56 = V_23 -> V_25 ;
V_23 -> V_25 = V_15 ;
}
goto V_37;
}
if ( ! F_3 ( & V_15 -> V_57 ) )
F_37 ( & V_15 -> V_57 , & V_23 -> V_24 ) ;
if ( F_39 ( & V_23 -> V_43 ) )
F_40 ( & V_23 -> V_43 ) ;
if ( F_39 ( & V_23 -> V_58 ) )
V_52 ++ ;
V_37:
F_18 ( & V_23 -> V_21 , V_32 ) ;
if ( V_52 )
F_25 ( & V_23 -> V_58 ) ;
return 1 ;
}
static void F_71 ( struct V_3 * V_3 , T_3 * V_49 ,
T_2 * V_14 )
{
struct V_9 * V_15 = F_7 ( V_14 ) ;
struct V_10 * V_48 ;
if ( V_15 -> V_96 >= 0 && ( V_48 = F_72 ( V_50 , V_86 ) ) ) {
F_73 ( & V_48 -> V_11 , F_70 ) ;
V_48 -> V_49 = V_49 ;
V_48 -> V_12 = V_15 ;
F_74 ( V_49 , & V_48 -> V_11 ) ;
F_37 ( & V_48 -> V_38 , & V_15 -> V_47 ) ;
V_15 -> V_96 ++ ;
} else {
V_15 -> V_96 = - 1 ;
}
}
static void F_75 ( struct V_22 * V_23 , struct V_9 * V_15 )
{
int V_88 ;
struct V_66 * * V_8 = & V_23 -> V_62 . V_66 , * V_97 = NULL ;
struct V_9 * V_98 ;
while ( * V_8 ) {
V_97 = * V_8 ;
V_98 = F_52 ( V_97 , struct V_9 , V_61 ) ;
V_88 = F_2 ( & V_15 -> V_2 , & V_98 -> V_2 ) ;
if ( V_88 > 0 )
V_8 = & V_97 -> V_90 ;
else
V_8 = & V_97 -> V_91 ;
}
F_76 ( & V_15 -> V_61 , V_97 , V_8 ) ;
F_77 ( & V_15 -> V_61 , & V_23 -> V_62 ) ;
}
static int F_78 ( struct V_22 * V_23 , struct V_99 * V_75 ,
struct V_3 * V_100 , int V_4 )
{
int error , V_101 , V_52 = 0 ;
unsigned long V_32 ;
long V_102 ;
struct V_9 * V_15 ;
struct V_13 V_103 ;
V_102 = F_79 ( & V_23 -> V_64 -> V_65 ) ;
if ( F_66 ( V_102 >= V_104 ) )
return - V_105 ;
if ( ! ( V_15 = F_72 ( V_63 , V_86 ) ) )
return - V_85 ;
F_10 ( & V_15 -> V_57 ) ;
F_10 ( & V_15 -> V_60 ) ;
F_10 ( & V_15 -> V_47 ) ;
V_15 -> V_23 = V_23 ;
F_1 ( & V_15 -> V_2 , V_100 , V_4 ) ;
V_15 -> V_75 = * V_75 ;
V_15 -> V_96 = 0 ;
V_15 -> V_56 = V_26 ;
V_103 . V_15 = V_15 ;
F_80 ( & V_103 . V_14 , F_71 ) ;
V_101 = V_100 -> V_73 -> V_74 ( V_100 , & V_103 . V_14 ) ;
error = - V_85 ;
if ( V_15 -> V_96 < 0 )
goto V_106;
F_43 ( & V_100 -> V_59 ) ;
F_37 ( & V_15 -> V_60 , & V_100 -> V_82 ) ;
F_45 ( & V_100 -> V_59 ) ;
F_75 ( V_23 , V_15 ) ;
F_15 ( & V_23 -> V_21 , V_32 ) ;
if ( ( V_101 & V_75 -> V_40 ) && ! F_3 ( & V_15 -> V_57 ) ) {
F_37 ( & V_15 -> V_57 , & V_23 -> V_24 ) ;
if ( F_39 ( & V_23 -> V_43 ) )
F_40 ( & V_23 -> V_43 ) ;
if ( F_39 ( & V_23 -> V_58 ) )
V_52 ++ ;
}
F_18 ( & V_23 -> V_21 , V_32 ) ;
F_81 ( & V_23 -> V_64 -> V_65 ) ;
if ( V_52 )
F_25 ( & V_23 -> V_58 ) ;
return 0 ;
V_106:
F_28 ( V_23 , V_15 ) ;
F_15 ( & V_23 -> V_21 , V_32 ) ;
if ( F_3 ( & V_15 -> V_57 ) )
F_44 ( & V_15 -> V_57 ) ;
F_18 ( & V_23 -> V_21 , V_32 ) ;
F_31 ( V_63 , V_15 ) ;
return error ;
}
static int F_82 ( struct V_22 * V_23 , struct V_9 * V_15 , struct V_99 * V_75 )
{
int V_52 = 0 ;
unsigned int V_101 ;
V_15 -> V_75 . V_40 = V_75 -> V_40 ;
V_15 -> V_75 . V_107 = V_75 -> V_107 ;
V_101 = V_15 -> V_2 . V_3 -> V_73 -> V_74 ( V_15 -> V_2 . V_3 , NULL ) ;
if ( V_101 & V_75 -> V_40 ) {
F_83 ( & V_23 -> V_21 ) ;
if ( ! F_3 ( & V_15 -> V_57 ) ) {
F_37 ( & V_15 -> V_57 , & V_23 -> V_24 ) ;
if ( F_39 ( & V_23 -> V_43 ) )
F_40 ( & V_23 -> V_43 ) ;
if ( F_39 ( & V_23 -> V_58 ) )
V_52 ++ ;
}
F_84 ( & V_23 -> V_21 ) ;
}
if ( V_52 )
F_25 ( & V_23 -> V_58 ) ;
return 0 ;
}
static int F_85 ( struct V_22 * V_23 , struct V_7 * V_71 ,
void * V_28 )
{
struct V_108 * V_109 = V_28 ;
int V_110 ;
unsigned int V_101 ;
struct V_9 * V_15 ;
struct V_99 T_4 * V_111 ;
for ( V_110 = 0 , V_111 = V_109 -> V_40 ;
! F_4 ( V_71 ) && V_110 < V_109 -> V_112 ; ) {
V_15 = F_29 ( V_71 , struct V_9 , V_57 ) ;
F_44 ( & V_15 -> V_57 ) ;
V_101 = V_15 -> V_2 . V_3 -> V_73 -> V_74 ( V_15 -> V_2 . V_3 , NULL ) &
V_15 -> V_75 . V_40 ;
if ( V_101 ) {
if ( F_86 ( V_101 , & V_111 -> V_40 ) ||
F_86 ( V_15 -> V_75 . V_107 , & V_111 -> V_107 ) ) {
F_17 ( & V_15 -> V_57 , V_71 ) ;
return V_110 ? V_110 : - V_113 ;
}
V_110 ++ ;
V_111 ++ ;
if ( V_15 -> V_75 . V_40 & V_114 )
V_15 -> V_75 . V_40 &= V_95 ;
else if ( ! ( V_15 -> V_75 . V_40 & V_115 ) ) {
F_37 ( & V_15 -> V_57 , & V_23 -> V_24 ) ;
}
}
}
return V_110 ;
}
static int F_87 ( struct V_22 * V_23 ,
struct V_99 T_4 * V_40 , int V_112 )
{
struct V_108 V_109 ;
V_109 . V_112 = V_112 ;
V_109 . V_40 = V_40 ;
return F_32 ( V_23 , F_85 , & V_109 , 0 ) ;
}
static inline struct V_116 F_88 ( long V_117 )
{
struct V_116 V_118 , V_119 = {
. V_120 = V_117 / V_121 ,
. V_122 = V_123 * ( V_117 % V_121 ) ,
} ;
F_89 ( & V_118 ) ;
return F_90 ( V_118 , V_119 ) ;
}
static int F_91 ( struct V_22 * V_23 , struct V_99 T_4 * V_40 ,
int V_112 , long V_124 )
{
int V_125 = 0 , V_126 , V_127 = 0 ;
unsigned long V_32 ;
long V_128 = 0 ;
T_1 V_11 ;
T_5 V_129 , * V_130 = NULL ;
if ( V_124 > 0 ) {
struct V_116 V_131 = F_88 ( V_124 ) ;
V_128 = F_92 ( & V_131 ) ;
V_130 = & V_129 ;
* V_130 = F_93 ( V_131 ) ;
} else if ( V_124 == 0 ) {
V_127 = 1 ;
F_15 ( & V_23 -> V_21 , V_32 ) ;
goto V_132;
}
V_133:
F_15 ( & V_23 -> V_21 , V_32 ) ;
if ( ! F_12 ( V_23 ) ) {
F_94 ( & V_11 , V_79 ) ;
F_95 ( & V_23 -> V_43 , & V_11 ) ;
for (; ; ) {
F_96 ( V_134 ) ;
if ( F_12 ( V_23 ) || V_127 )
break;
if ( F_97 ( V_79 ) ) {
V_125 = - V_135 ;
break;
}
F_18 ( & V_23 -> V_21 , V_32 ) ;
if ( ! F_98 ( V_130 , V_128 , V_136 ) )
V_127 = 1 ;
F_15 ( & V_23 -> V_21 , V_32 ) ;
}
F_99 ( & V_23 -> V_43 , & V_11 ) ;
F_96 ( V_137 ) ;
}
V_132:
V_126 = F_12 ( V_23 ) ;
F_18 ( & V_23 -> V_21 , V_32 ) ;
if ( ! V_125 && V_126 &&
! ( V_125 = F_87 ( V_23 , V_40 , V_112 ) ) && ! V_127 )
goto V_133;
return V_125 ;
}
static int F_100 ( void * V_28 , void * V_29 , int V_31 )
{
int error = 0 ;
struct V_3 * V_3 = V_28 ;
struct V_22 * V_23 = V_3 -> V_70 ;
struct V_66 * V_67 ;
struct V_9 * V_15 ;
F_35 ( & V_23 -> V_55 , V_31 + 1 ) ;
for ( V_67 = F_50 ( & V_23 -> V_62 ) ; V_67 ; V_67 = F_51 ( V_67 ) ) {
V_15 = F_52 ( V_67 , struct V_9 , V_61 ) ;
if ( F_66 ( F_61 ( V_15 -> V_2 . V_3 ) ) ) {
error = F_13 ( & V_138 , V_46 ,
F_100 , V_15 -> V_2 . V_3 ,
V_15 -> V_2 . V_3 -> V_70 , V_79 ) ;
if ( error != 0 )
break;
}
}
F_41 ( & V_23 -> V_55 ) ;
return error ;
}
static int F_101 ( struct V_22 * V_23 , struct V_3 * V_3 )
{
return F_13 ( & V_138 , V_46 ,
F_100 , V_3 , V_23 , V_79 ) ;
}
static int T_6 F_102 ( void )
{
struct V_139 V_140 ;
F_103 ( & V_140 ) ;
V_104 = ( ( ( V_140 . V_141 - V_140 . V_142 ) / 25 ) << V_143 ) /
V_144 ;
F_104 ( V_104 < 0 ) ;
F_9 ( & V_138 ) ;
F_9 ( & V_45 ) ;
F_9 ( & V_78 ) ;
V_63 = F_105 ( L_1 , sizeof( struct V_9 ) ,
0 , V_145 | V_146 , NULL ) ;
V_50 = F_105 ( L_2 ,
sizeof( struct V_10 ) , 0 , V_146 , NULL ) ;
return 0 ;
}
