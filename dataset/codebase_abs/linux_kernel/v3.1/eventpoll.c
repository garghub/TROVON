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
void * V_28 )
{
int error , V_51 = 0 ;
unsigned long V_32 ;
struct V_9 * V_15 , * V_52 ;
F_34 ( V_53 ) ;
F_35 ( & V_23 -> V_54 ) ;
F_15 ( & V_23 -> V_21 , V_32 ) ;
F_36 ( & V_23 -> V_24 , & V_53 ) ;
V_23 -> V_25 = NULL ;
F_18 ( & V_23 -> V_21 , V_32 ) ;
error = (* F_33)( V_23 , & V_53 , V_28 ) ;
F_15 ( & V_23 -> V_21 , V_32 ) ;
for ( V_52 = V_23 -> V_25 ; ( V_15 = V_52 ) != NULL ;
V_52 = V_15 -> V_55 , V_15 -> V_55 = V_26 ) {
if ( ! F_3 ( & V_15 -> V_56 ) )
F_37 ( & V_15 -> V_56 , & V_23 -> V_24 ) ;
}
V_23 -> V_25 = V_26 ;
F_38 ( & V_53 , & V_23 -> V_24 ) ;
if ( ! F_4 ( & V_23 -> V_24 ) ) {
if ( F_39 ( & V_23 -> V_43 ) )
F_40 ( & V_23 -> V_43 ) ;
if ( F_39 ( & V_23 -> V_57 ) )
V_51 ++ ;
}
F_18 ( & V_23 -> V_21 , V_32 ) ;
F_41 ( & V_23 -> V_54 ) ;
if ( V_51 )
F_25 ( & V_23 -> V_57 ) ;
return error ;
}
static int F_42 ( struct V_22 * V_23 , struct V_9 * V_15 )
{
unsigned long V_32 ;
struct V_3 * V_3 = V_15 -> V_2 . V_3 ;
F_28 ( V_23 , V_15 ) ;
F_43 ( & V_3 -> V_58 ) ;
if ( F_3 ( & V_15 -> V_59 ) )
F_44 ( & V_15 -> V_59 ) ;
F_45 ( & V_3 -> V_58 ) ;
F_46 ( & V_15 -> V_60 , & V_23 -> V_61 ) ;
F_15 ( & V_23 -> V_21 , V_32 ) ;
if ( F_3 ( & V_15 -> V_56 ) )
F_44 ( & V_15 -> V_56 ) ;
F_18 ( & V_23 -> V_21 , V_32 ) ;
F_31 ( V_62 , V_15 ) ;
F_47 ( & V_23 -> V_63 -> V_64 ) ;
return 0 ;
}
static void F_48 ( struct V_22 * V_23 )
{
struct V_65 * V_66 ;
struct V_9 * V_15 ;
if ( F_39 ( & V_23 -> V_57 ) )
F_25 ( & V_23 -> V_57 ) ;
F_35 ( & V_67 ) ;
for ( V_66 = F_49 ( & V_23 -> V_61 ) ; V_66 ; V_66 = F_50 ( V_66 ) ) {
V_15 = F_51 ( V_66 , struct V_9 , V_60 ) ;
F_28 ( V_23 , V_15 ) ;
}
while ( ( V_66 = F_49 ( & V_23 -> V_61 ) ) != NULL ) {
V_15 = F_51 ( V_66 , struct V_9 , V_60 ) ;
F_42 ( V_23 , V_15 ) ;
}
F_41 ( & V_67 ) ;
F_52 ( & V_23 -> V_54 ) ;
F_53 ( V_23 -> V_63 ) ;
F_54 ( V_23 ) ;
}
static int F_55 ( struct V_68 * V_68 , struct V_3 * V_3 )
{
struct V_22 * V_23 = V_3 -> V_69 ;
if ( V_23 )
F_48 ( V_23 ) ;
return 0 ;
}
static int F_56 ( struct V_22 * V_23 , struct V_7 * V_70 ,
void * V_28 )
{
struct V_9 * V_15 , * V_71 ;
F_57 (epi, tmp, head, rdllink) {
if ( V_15 -> V_2 . V_3 -> V_72 -> V_73 ( V_15 -> V_2 . V_3 , NULL ) &
V_15 -> V_74 . V_40 )
return V_42 | V_75 ;
else {
F_44 ( & V_15 -> V_56 ) ;
}
}
return 0 ;
}
static int F_58 ( void * V_28 , void * V_29 , int V_31 )
{
return F_32 ( V_28 , F_56 , NULL ) ;
}
static unsigned int F_59 ( struct V_3 * V_3 , T_2 * V_11 )
{
int V_76 ;
struct V_22 * V_23 = V_3 -> V_69 ;
V_57 ( V_3 , & V_23 -> V_57 , V_11 ) ;
V_76 = F_13 ( & V_77 , V_46 ,
F_58 , V_23 , V_23 , V_78 ) ;
return V_76 != - 1 ? V_76 : 0 ;
}
static inline int F_60 ( struct V_3 * V_79 )
{
return V_79 -> V_72 == & V_80 ;
}
void F_61 ( struct V_3 * V_3 )
{
struct V_7 * V_33 = & V_3 -> V_81 ;
struct V_22 * V_23 ;
struct V_9 * V_15 ;
F_35 ( & V_67 ) ;
while ( ! F_4 ( V_33 ) ) {
V_15 = F_29 ( V_33 , struct V_9 , V_59 ) ;
V_23 = V_15 -> V_23 ;
F_44 ( & V_15 -> V_59 ) ;
F_35 ( & V_23 -> V_54 ) ;
F_42 ( V_23 , V_15 ) ;
F_41 ( & V_23 -> V_54 ) ;
}
F_41 ( & V_67 ) ;
}
static int F_62 ( struct V_22 * * V_82 )
{
int error ;
struct V_83 * V_63 ;
struct V_22 * V_23 ;
V_63 = F_63 () ;
error = - V_84 ;
V_23 = F_64 ( sizeof( * V_23 ) , V_85 ) ;
if ( F_65 ( ! V_23 ) )
goto F_53;
F_11 ( & V_23 -> V_21 ) ;
F_66 ( & V_23 -> V_54 ) ;
F_67 ( & V_23 -> V_43 ) ;
F_67 ( & V_23 -> V_57 ) ;
F_10 ( & V_23 -> V_24 ) ;
V_23 -> V_61 = V_86 ;
V_23 -> V_25 = V_26 ;
V_23 -> V_63 = V_63 ;
* V_82 = V_23 ;
return 0 ;
F_53:
F_53 ( V_63 ) ;
return error ;
}
static struct V_9 * F_68 ( struct V_22 * V_23 , struct V_3 * V_3 , int V_4 )
{
int V_87 ;
struct V_65 * V_66 ;
struct V_9 * V_15 , * V_88 = NULL ;
struct V_1 V_2 ;
F_1 ( & V_2 , V_3 , V_4 ) ;
for ( V_66 = V_23 -> V_61 . V_65 ; V_66 ; ) {
V_15 = F_51 ( V_66 , struct V_9 , V_60 ) ;
V_87 = F_2 ( & V_2 , & V_15 -> V_2 ) ;
if ( V_87 > 0 )
V_66 = V_66 -> V_89 ;
else if ( V_87 < 0 )
V_66 = V_66 -> V_90 ;
else {
V_88 = V_15 ;
break;
}
}
return V_88 ;
}
static int F_69 ( T_1 * V_11 , unsigned V_91 , int V_92 , void * V_93 )
{
int V_51 = 0 ;
unsigned long V_32 ;
struct V_9 * V_15 = F_5 ( V_11 ) ;
struct V_22 * V_23 = V_15 -> V_23 ;
F_15 ( & V_23 -> V_21 , V_32 ) ;
if ( ! ( V_15 -> V_74 . V_40 & ~ V_94 ) )
goto V_37;
if ( V_93 && ! ( ( unsigned long ) V_93 & V_15 -> V_74 . V_40 ) )
goto V_37;
if ( F_65 ( V_23 -> V_25 != V_26 ) ) {
if ( V_15 -> V_55 == V_26 ) {
V_15 -> V_55 = V_23 -> V_25 ;
V_23 -> V_25 = V_15 ;
}
goto V_37;
}
if ( ! F_3 ( & V_15 -> V_56 ) )
F_37 ( & V_15 -> V_56 , & V_23 -> V_24 ) ;
if ( F_39 ( & V_23 -> V_43 ) )
F_40 ( & V_23 -> V_43 ) ;
if ( F_39 ( & V_23 -> V_57 ) )
V_51 ++ ;
V_37:
F_18 ( & V_23 -> V_21 , V_32 ) ;
if ( V_51 )
F_25 ( & V_23 -> V_57 ) ;
return 1 ;
}
static void F_70 ( struct V_3 * V_3 , T_3 * V_49 ,
T_2 * V_14 )
{
struct V_9 * V_15 = F_7 ( V_14 ) ;
struct V_10 * V_48 ;
if ( V_15 -> V_95 >= 0 && ( V_48 = F_71 ( V_50 , V_85 ) ) ) {
F_72 ( & V_48 -> V_11 , F_69 ) ;
V_48 -> V_49 = V_49 ;
V_48 -> V_12 = V_15 ;
F_73 ( V_49 , & V_48 -> V_11 ) ;
F_37 ( & V_48 -> V_38 , & V_15 -> V_47 ) ;
V_15 -> V_95 ++ ;
} else {
V_15 -> V_95 = - 1 ;
}
}
static void F_74 ( struct V_22 * V_23 , struct V_9 * V_15 )
{
int V_87 ;
struct V_65 * * V_8 = & V_23 -> V_61 . V_65 , * V_96 = NULL ;
struct V_9 * V_97 ;
while ( * V_8 ) {
V_96 = * V_8 ;
V_97 = F_51 ( V_96 , struct V_9 , V_60 ) ;
V_87 = F_2 ( & V_15 -> V_2 , & V_97 -> V_2 ) ;
if ( V_87 > 0 )
V_8 = & V_96 -> V_89 ;
else
V_8 = & V_96 -> V_90 ;
}
F_75 ( & V_15 -> V_60 , V_96 , V_8 ) ;
F_76 ( & V_15 -> V_60 , & V_23 -> V_61 ) ;
}
static int F_77 ( struct V_22 * V_23 , struct V_98 * V_74 ,
struct V_3 * V_99 , int V_4 )
{
int error , V_100 , V_51 = 0 ;
unsigned long V_32 ;
long V_101 ;
struct V_9 * V_15 ;
struct V_13 V_102 ;
V_101 = F_78 ( & V_23 -> V_63 -> V_64 ) ;
if ( F_65 ( V_101 >= V_103 ) )
return - V_104 ;
if ( ! ( V_15 = F_71 ( V_62 , V_85 ) ) )
return - V_84 ;
F_10 ( & V_15 -> V_56 ) ;
F_10 ( & V_15 -> V_59 ) ;
F_10 ( & V_15 -> V_47 ) ;
V_15 -> V_23 = V_23 ;
F_1 ( & V_15 -> V_2 , V_99 , V_4 ) ;
V_15 -> V_74 = * V_74 ;
V_15 -> V_95 = 0 ;
V_15 -> V_55 = V_26 ;
V_102 . V_15 = V_15 ;
F_79 ( & V_102 . V_14 , F_70 ) ;
V_100 = V_99 -> V_72 -> V_73 ( V_99 , & V_102 . V_14 ) ;
error = - V_84 ;
if ( V_15 -> V_95 < 0 )
goto V_105;
F_43 ( & V_99 -> V_58 ) ;
F_37 ( & V_15 -> V_59 , & V_99 -> V_81 ) ;
F_45 ( & V_99 -> V_58 ) ;
F_74 ( V_23 , V_15 ) ;
F_15 ( & V_23 -> V_21 , V_32 ) ;
if ( ( V_100 & V_74 -> V_40 ) && ! F_3 ( & V_15 -> V_56 ) ) {
F_37 ( & V_15 -> V_56 , & V_23 -> V_24 ) ;
if ( F_39 ( & V_23 -> V_43 ) )
F_40 ( & V_23 -> V_43 ) ;
if ( F_39 ( & V_23 -> V_57 ) )
V_51 ++ ;
}
F_18 ( & V_23 -> V_21 , V_32 ) ;
F_80 ( & V_23 -> V_63 -> V_64 ) ;
if ( V_51 )
F_25 ( & V_23 -> V_57 ) ;
return 0 ;
V_105:
F_28 ( V_23 , V_15 ) ;
F_15 ( & V_23 -> V_21 , V_32 ) ;
if ( F_3 ( & V_15 -> V_56 ) )
F_44 ( & V_15 -> V_56 ) ;
F_18 ( & V_23 -> V_21 , V_32 ) ;
F_31 ( V_62 , V_15 ) ;
return error ;
}
static int F_81 ( struct V_22 * V_23 , struct V_9 * V_15 , struct V_98 * V_74 )
{
int V_51 = 0 ;
unsigned int V_100 ;
V_15 -> V_74 . V_40 = V_74 -> V_40 ;
V_15 -> V_74 . V_106 = V_74 -> V_106 ;
V_100 = V_15 -> V_2 . V_3 -> V_72 -> V_73 ( V_15 -> V_2 . V_3 , NULL ) ;
if ( V_100 & V_74 -> V_40 ) {
F_82 ( & V_23 -> V_21 ) ;
if ( ! F_3 ( & V_15 -> V_56 ) ) {
F_37 ( & V_15 -> V_56 , & V_23 -> V_24 ) ;
if ( F_39 ( & V_23 -> V_43 ) )
F_40 ( & V_23 -> V_43 ) ;
if ( F_39 ( & V_23 -> V_57 ) )
V_51 ++ ;
}
F_83 ( & V_23 -> V_21 ) ;
}
if ( V_51 )
F_25 ( & V_23 -> V_57 ) ;
return 0 ;
}
static int F_84 ( struct V_22 * V_23 , struct V_7 * V_70 ,
void * V_28 )
{
struct V_107 * V_108 = V_28 ;
int V_109 ;
unsigned int V_100 ;
struct V_9 * V_15 ;
struct V_98 T_4 * V_110 ;
for ( V_109 = 0 , V_110 = V_108 -> V_40 ;
! F_4 ( V_70 ) && V_109 < V_108 -> V_111 ; ) {
V_15 = F_29 ( V_70 , struct V_9 , V_56 ) ;
F_44 ( & V_15 -> V_56 ) ;
V_100 = V_15 -> V_2 . V_3 -> V_72 -> V_73 ( V_15 -> V_2 . V_3 , NULL ) &
V_15 -> V_74 . V_40 ;
if ( V_100 ) {
if ( F_85 ( V_100 , & V_110 -> V_40 ) ||
F_85 ( V_15 -> V_74 . V_106 , & V_110 -> V_106 ) ) {
F_17 ( & V_15 -> V_56 , V_70 ) ;
return V_109 ? V_109 : - V_112 ;
}
V_109 ++ ;
V_110 ++ ;
if ( V_15 -> V_74 . V_40 & V_113 )
V_15 -> V_74 . V_40 &= V_94 ;
else if ( ! ( V_15 -> V_74 . V_40 & V_114 ) ) {
F_37 ( & V_15 -> V_56 , & V_23 -> V_24 ) ;
}
}
}
return V_109 ;
}
static int F_86 ( struct V_22 * V_23 ,
struct V_98 T_4 * V_40 , int V_111 )
{
struct V_107 V_108 ;
V_108 . V_111 = V_111 ;
V_108 . V_40 = V_40 ;
return F_32 ( V_23 , F_84 , & V_108 ) ;
}
static inline struct V_115 F_87 ( long V_116 )
{
struct V_115 V_117 , V_118 = {
. V_119 = V_116 / V_120 ,
. V_121 = V_122 * ( V_116 % V_120 ) ,
} ;
F_88 ( & V_117 ) ;
return F_89 ( V_117 , V_118 ) ;
}
static int F_90 ( struct V_22 * V_23 , struct V_98 T_4 * V_40 ,
int V_111 , long V_123 )
{
int V_124 = 0 , V_125 , V_126 = 0 ;
unsigned long V_32 ;
long V_127 = 0 ;
T_1 V_11 ;
T_5 V_128 , * V_129 = NULL ;
if ( V_123 > 0 ) {
struct V_115 V_130 = F_87 ( V_123 ) ;
V_127 = F_91 ( & V_130 ) ;
V_129 = & V_128 ;
* V_129 = F_92 ( V_130 ) ;
} else if ( V_123 == 0 ) {
V_126 = 1 ;
F_15 ( & V_23 -> V_21 , V_32 ) ;
goto V_131;
}
V_132:
F_15 ( & V_23 -> V_21 , V_32 ) ;
if ( ! F_12 ( V_23 ) ) {
F_93 ( & V_11 , V_78 ) ;
F_94 ( & V_23 -> V_43 , & V_11 ) ;
for (; ; ) {
F_95 ( V_133 ) ;
if ( F_12 ( V_23 ) || V_126 )
break;
if ( F_96 ( V_78 ) ) {
V_124 = - V_134 ;
break;
}
F_18 ( & V_23 -> V_21 , V_32 ) ;
if ( ! F_97 ( V_129 , V_127 , V_135 ) )
V_126 = 1 ;
F_15 ( & V_23 -> V_21 , V_32 ) ;
}
F_98 ( & V_23 -> V_43 , & V_11 ) ;
F_95 ( V_136 ) ;
}
V_131:
V_125 = F_12 ( V_23 ) ;
F_18 ( & V_23 -> V_21 , V_32 ) ;
if ( ! V_124 && V_125 &&
! ( V_124 = F_86 ( V_23 , V_40 , V_111 ) ) && ! V_126 )
goto V_132;
return V_124 ;
}
static int F_99 ( void * V_28 , void * V_29 , int V_31 )
{
int error = 0 ;
struct V_3 * V_3 = V_28 ;
struct V_22 * V_23 = V_3 -> V_69 ;
struct V_65 * V_66 ;
struct V_9 * V_15 ;
F_35 ( & V_23 -> V_54 ) ;
for ( V_66 = F_49 ( & V_23 -> V_61 ) ; V_66 ; V_66 = F_50 ( V_66 ) ) {
V_15 = F_51 ( V_66 , struct V_9 , V_60 ) ;
if ( F_65 ( F_60 ( V_15 -> V_2 . V_3 ) ) ) {
error = F_13 ( & V_137 , V_46 ,
F_99 , V_15 -> V_2 . V_3 ,
V_15 -> V_2 . V_3 -> V_69 , V_78 ) ;
if ( error != 0 )
break;
}
}
F_41 ( & V_23 -> V_54 ) ;
return error ;
}
static int F_100 ( struct V_22 * V_23 , struct V_3 * V_3 )
{
return F_13 ( & V_137 , V_46 ,
F_99 , V_3 , V_23 , V_78 ) ;
}
static int T_6 F_101 ( void )
{
struct V_138 V_139 ;
F_102 ( & V_139 ) ;
V_103 = ( ( ( V_139 . V_140 - V_139 . V_141 ) / 25 ) << V_142 ) /
V_143 ;
F_103 ( V_103 < 0 ) ;
F_9 ( & V_137 ) ;
F_9 ( & V_45 ) ;
F_9 ( & V_77 ) ;
V_62 = F_104 ( L_1 , sizeof( struct V_9 ) ,
0 , V_144 | V_145 , NULL ) ;
V_50 = F_104 ( L_2 ,
sizeof( struct V_10 ) , 0 , V_145 , NULL ) ;
return 0 ;
}
