static inline int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == & V_4 ;
}
static inline void F_2 ( struct V_5 * V_6 ,
struct V_1 * V_1 , int V_7 )
{
V_6 -> V_1 = V_1 ;
V_6 -> V_7 = V_7 ;
}
static inline int F_3 ( struct V_5 * V_8 ,
struct V_5 * V_9 )
{
return ( V_8 -> V_1 > V_9 -> V_1 ? + 1 :
( V_8 -> V_1 < V_9 -> V_1 ? - 1 : V_8 -> V_7 - V_9 -> V_7 ) ) ;
}
static inline int F_4 ( struct V_10 * V_11 )
{
return ! F_5 ( V_11 ) ;
}
static inline struct V_12 * F_6 ( T_1 * V_11 )
{
return F_7 ( V_11 , struct V_12 , V_13 ) ;
}
static inline struct V_14 * F_8 ( T_1 * V_11 )
{
return F_7 ( V_11 , struct V_12 , V_13 ) -> V_15 ;
}
static inline struct V_14 * F_9 ( T_2 * V_11 )
{
return F_7 ( V_11 , struct V_16 , V_17 ) -> V_18 ;
}
static inline int F_10 ( int V_19 )
{
return V_19 != V_20 ;
}
static void F_11 ( struct V_21 * V_22 )
{
F_12 ( & V_22 -> V_23 ) ;
F_13 ( & V_22 -> V_24 ) ;
}
static inline int F_14 ( struct V_25 * V_26 )
{
return ! F_5 ( & V_26 -> V_27 ) || V_26 -> V_28 != V_29 ;
}
static bool F_15 ( void * V_11 , unsigned long V_30 )
{
struct V_25 * V_26 = V_11 ;
return F_14 ( V_26 ) || F_16 ( V_30 ) ;
}
static void F_17 ( struct V_25 * V_26 , int V_31 )
{
#ifdef F_18
unsigned int V_32 = F_19 ( V_26 -> V_32 ) ;
if ( ( V_32 >= V_33 ) && F_20 () )
F_21 ( V_32 , V_31 ? NULL : F_15 , V_26 ) ;
#endif
}
static inline void F_22 ( struct V_25 * V_26 )
{
#ifdef F_18
if ( V_26 -> V_32 )
V_26 -> V_32 = 0 ;
#endif
}
static inline void F_23 ( struct V_14 * V_18 )
{
#ifdef F_18
struct V_25 * V_26 ;
unsigned int V_32 ;
struct V_34 * V_35 ;
struct V_35 * V_36 ;
int V_37 ;
if ( ! F_20 () )
return;
V_35 = F_24 ( V_18 -> V_6 . V_1 , & V_37 ) ;
if ( ! V_35 )
return;
V_36 = V_35 -> V_36 ;
if ( ! V_36 )
return;
V_32 = F_19 ( V_36 -> V_38 ) ;
V_26 = V_18 -> V_26 ;
if ( V_32 < V_33 || V_32 == V_26 -> V_32 )
return;
V_26 -> V_32 = V_32 ;
#endif
}
static int F_25 ( struct V_21 * V_22 , int V_39 ,
int (* F_26)( void * , void * , int ) , void * V_40 ,
void * V_41 , void * V_42 )
{
int error , V_43 = 0 ;
unsigned long V_44 ;
struct V_10 * V_45 = & V_22 -> V_23 ;
struct V_46 * V_47 ;
struct V_46 V_48 ;
F_27 ( & V_22 -> V_24 , V_44 ) ;
F_28 (tncur, lsthead, llink) {
if ( V_47 -> V_42 == V_42 &&
( V_47 -> V_41 == V_41 || ++ V_43 > V_39 ) ) {
error = - 1 ;
goto V_49;
}
}
V_48 . V_42 = V_42 ;
V_48 . V_41 = V_41 ;
F_29 ( & V_48 . V_50 , V_45 ) ;
F_30 ( & V_22 -> V_24 , V_44 ) ;
error = (* F_26)( V_40 , V_41 , V_43 ) ;
F_27 ( & V_22 -> V_24 , V_44 ) ;
F_31 ( & V_48 . V_50 ) ;
V_49:
F_30 ( & V_22 -> V_24 , V_44 ) ;
return error ;
}
static inline void F_32 ( T_3 * V_51 ,
unsigned long V_52 , int V_53 )
{
unsigned long V_44 ;
F_33 ( & V_51 -> V_24 , V_44 , V_53 ) ;
F_34 ( V_51 , V_52 ) ;
F_30 ( & V_51 -> V_24 , V_44 ) ;
}
static inline void F_32 ( T_3 * V_51 ,
unsigned long V_52 , int V_53 )
{
F_35 ( V_51 , V_52 ) ;
}
static int F_36 ( void * V_40 , void * V_41 , int V_43 )
{
F_32 ( ( T_3 * ) V_41 , V_54 ,
1 + V_43 ) ;
return 0 ;
}
static void F_37 ( T_3 * V_55 )
{
int V_56 = F_38 () ;
F_25 ( & V_57 , V_58 ,
F_36 , NULL , V_55 , ( void * ) ( long ) V_56 ) ;
F_39 () ;
}
static void F_40 ( struct V_12 * V_59 )
{
T_3 * V_60 ;
F_41 () ;
V_60 = F_42 ( V_59 -> V_60 ) ;
if ( V_60 )
F_43 ( V_60 , & V_59 -> V_13 ) ;
F_44 () ;
}
static void F_45 ( struct V_25 * V_26 , struct V_14 * V_18 )
{
struct V_10 * V_45 = & V_18 -> V_61 ;
struct V_12 * V_59 ;
while ( ! F_5 ( V_45 ) ) {
V_59 = F_46 ( V_45 , struct V_12 , V_50 ) ;
F_31 ( & V_59 -> V_50 ) ;
F_40 ( V_59 ) ;
F_47 ( V_62 , V_59 ) ;
}
}
static inline struct V_63 * F_48 ( struct V_14 * V_18 )
{
return F_49 ( V_18 -> V_64 , F_50 ( & V_18 -> V_26 -> V_65 ) ) ;
}
static inline void F_51 ( struct V_14 * V_18 )
{
struct V_63 * V_64 = F_48 ( V_18 ) ;
if ( V_64 )
F_52 ( V_64 ) ;
}
static inline bool F_53 ( struct V_14 * V_18 )
{
return F_54 ( V_18 -> V_64 ) ? true : false ;
}
static inline void F_55 ( struct V_14 * V_18 )
{
struct V_63 * V_64 ;
F_41 () ;
V_64 = F_42 ( V_18 -> V_64 ) ;
if ( V_64 )
F_52 ( V_64 ) ;
F_44 () ;
}
static int F_56 ( struct V_25 * V_26 ,
int (* F_57)( struct V_25 * ,
struct V_10 * , void * ) ,
void * V_40 , int V_66 , bool V_67 )
{
int error , V_68 = 0 ;
unsigned long V_44 ;
struct V_14 * V_18 , * V_69 ;
F_58 ( V_70 ) ;
if ( ! V_67 )
F_59 ( & V_26 -> V_65 , V_66 ) ;
F_27 ( & V_26 -> V_24 , V_44 ) ;
F_60 ( & V_26 -> V_27 , & V_70 ) ;
V_26 -> V_28 = NULL ;
F_30 ( & V_26 -> V_24 , V_44 ) ;
error = (* F_57)( V_26 , & V_70 , V_40 ) ;
F_27 ( & V_26 -> V_24 , V_44 ) ;
for ( V_69 = V_26 -> V_28 ; ( V_18 = V_69 ) != NULL ;
V_69 = V_18 -> V_71 , V_18 -> V_71 = V_29 ) {
if ( ! F_4 ( & V_18 -> V_72 ) ) {
F_61 ( & V_18 -> V_72 , & V_26 -> V_27 ) ;
F_51 ( V_18 ) ;
}
}
V_26 -> V_28 = V_29 ;
F_62 ( & V_70 , & V_26 -> V_27 ) ;
F_63 ( V_26 -> V_64 ) ;
if ( ! F_5 ( & V_26 -> V_27 ) ) {
if ( F_64 ( & V_26 -> V_55 ) )
F_65 ( & V_26 -> V_55 ) ;
if ( F_64 ( & V_26 -> V_73 ) )
V_68 ++ ;
}
F_30 ( & V_26 -> V_24 , V_44 ) ;
if ( ! V_67 )
F_66 ( & V_26 -> V_65 ) ;
if ( V_68 )
F_37 ( & V_26 -> V_73 ) ;
return error ;
}
static void F_67 ( struct V_74 * V_75 )
{
struct V_14 * V_18 = F_7 ( V_75 , struct V_14 , V_76 ) ;
F_47 ( V_77 , V_18 ) ;
}
static int F_68 ( struct V_25 * V_26 , struct V_14 * V_18 )
{
unsigned long V_44 ;
struct V_1 * V_1 = V_18 -> V_6 . V_1 ;
F_45 ( V_26 , V_18 ) ;
F_69 ( & V_1 -> V_78 ) ;
F_70 ( & V_18 -> V_79 ) ;
F_71 ( & V_1 -> V_78 ) ;
F_72 ( & V_18 -> V_80 , & V_26 -> V_81 ) ;
F_27 ( & V_26 -> V_24 , V_44 ) ;
if ( F_4 ( & V_18 -> V_72 ) )
F_73 ( & V_18 -> V_72 ) ;
F_30 ( & V_26 -> V_24 , V_44 ) ;
F_74 ( F_48 ( V_18 ) ) ;
F_75 ( & V_18 -> V_76 , F_67 ) ;
F_76 ( & V_26 -> V_82 -> V_83 ) ;
return 0 ;
}
static void F_77 ( struct V_25 * V_26 )
{
struct V_84 * V_85 ;
struct V_14 * V_18 ;
if ( F_64 ( & V_26 -> V_73 ) )
F_37 ( & V_26 -> V_73 ) ;
F_78 ( & V_86 ) ;
for ( V_85 = F_79 ( & V_26 -> V_81 ) ; V_85 ; V_85 = F_80 ( V_85 ) ) {
V_18 = F_81 ( V_85 , struct V_14 , V_80 ) ;
F_45 ( V_26 , V_18 ) ;
F_82 () ;
}
F_78 ( & V_26 -> V_65 ) ;
while ( ( V_85 = F_79 ( & V_26 -> V_81 ) ) != NULL ) {
V_18 = F_81 ( V_85 , struct V_14 , V_80 ) ;
F_68 ( V_26 , V_18 ) ;
F_82 () ;
}
F_66 ( & V_26 -> V_65 ) ;
F_66 ( & V_86 ) ;
F_83 ( & V_26 -> V_65 ) ;
F_84 ( V_26 -> V_82 ) ;
F_74 ( V_26 -> V_64 ) ;
F_85 ( V_26 ) ;
}
static int F_86 ( struct V_87 * V_87 , struct V_1 * V_1 )
{
struct V_25 * V_26 = V_1 -> V_88 ;
if ( V_26 )
F_77 ( V_26 ) ;
return 0 ;
}
static inline unsigned int F_87 ( struct V_14 * V_18 , T_2 * V_17 )
{
V_17 -> V_89 = V_18 -> V_90 . V_52 ;
return V_18 -> V_6 . V_1 -> V_3 -> V_91 ( V_18 -> V_6 . V_1 , V_17 ) & V_18 -> V_90 . V_52 ;
}
static int F_88 ( struct V_25 * V_26 , struct V_10 * V_75 ,
void * V_40 )
{
struct V_14 * V_18 , * V_92 ;
T_2 V_17 ;
F_89 ( & V_17 , NULL ) ;
F_90 (epi, tmp, head, rdllink) {
if ( F_87 ( V_18 , & V_17 ) )
return V_54 | V_93 ;
else {
F_63 ( F_48 ( V_18 ) ) ;
F_73 ( & V_18 -> V_72 ) ;
}
}
return 0 ;
}
static int F_91 ( void * V_40 , void * V_41 , int V_43 )
{
struct V_94 * V_95 = V_40 ;
return F_56 ( V_95 -> V_26 , F_88 , NULL ,
V_43 + 1 , V_95 -> V_96 ) ;
}
static unsigned int F_92 ( struct V_1 * V_1 , T_2 * V_13 )
{
int V_97 ;
struct V_25 * V_26 = V_1 -> V_88 ;
struct V_94 V_95 ;
V_95 . V_96 = V_13 && ( V_13 -> V_98 == V_99 ) ;
V_95 . V_26 = V_26 ;
V_73 ( V_1 , & V_26 -> V_73 , V_13 ) ;
V_97 = F_25 ( & V_100 , V_58 ,
F_91 , & V_95 , V_26 , V_101 ) ;
return V_97 != - 1 ? V_97 : 0 ;
}
static void F_93 ( struct V_102 * V_103 , struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_88 ;
struct V_84 * V_85 ;
F_78 ( & V_26 -> V_65 ) ;
for ( V_85 = F_79 ( & V_26 -> V_81 ) ; V_85 ; V_85 = F_80 ( V_85 ) ) {
struct V_14 * V_18 = F_81 ( V_85 , struct V_14 , V_80 ) ;
F_94 ( V_103 , L_1 ,
V_18 -> V_6 . V_7 , V_18 -> V_90 . V_52 ,
( long long ) V_18 -> V_90 . V_104 ) ;
if ( F_95 ( V_103 ) )
break;
}
F_66 ( & V_26 -> V_65 ) ;
}
void F_96 ( struct V_1 * V_1 )
{
struct V_25 * V_26 ;
struct V_14 * V_18 , * V_71 ;
F_78 ( & V_86 ) ;
F_90 (epi, next, &file->f_ep_links, fllink) {
V_26 = V_18 -> V_26 ;
F_59 ( & V_26 -> V_65 , 0 ) ;
F_68 ( V_26 , V_18 ) ;
F_66 ( & V_26 -> V_65 ) ;
}
F_66 ( & V_86 ) ;
}
static int F_97 ( struct V_25 * * V_105 )
{
int error ;
struct V_106 * V_82 ;
struct V_25 * V_26 ;
V_82 = F_98 () ;
error = - V_107 ;
V_26 = F_99 ( sizeof( * V_26 ) , V_108 ) ;
if ( F_100 ( ! V_26 ) )
goto F_84;
F_13 ( & V_26 -> V_24 ) ;
F_101 ( & V_26 -> V_65 ) ;
F_102 ( & V_26 -> V_55 ) ;
F_102 ( & V_26 -> V_73 ) ;
F_12 ( & V_26 -> V_27 ) ;
V_26 -> V_81 = V_109 ;
V_26 -> V_28 = V_29 ;
V_26 -> V_82 = V_82 ;
* V_105 = V_26 ;
return 0 ;
F_84:
F_84 ( V_82 ) ;
return error ;
}
static struct V_14 * F_103 ( struct V_25 * V_26 , struct V_1 * V_1 , int V_7 )
{
int V_110 ;
struct V_84 * V_85 ;
struct V_14 * V_18 , * V_111 = NULL ;
struct V_5 V_6 ;
F_2 ( & V_6 , V_1 , V_7 ) ;
for ( V_85 = V_26 -> V_81 . V_84 ; V_85 ; ) {
V_18 = F_81 ( V_85 , struct V_14 , V_80 ) ;
V_110 = F_3 ( & V_6 , & V_18 -> V_6 ) ;
if ( V_110 > 0 )
V_85 = V_85 -> V_112 ;
else if ( V_110 < 0 )
V_85 = V_85 -> V_113 ;
else {
V_111 = V_18 ;
break;
}
}
return V_111 ;
}
static int F_104 ( T_1 * V_13 , unsigned V_114 , int V_115 , void * V_116 )
{
int V_68 = 0 ;
unsigned long V_44 ;
struct V_14 * V_18 = F_8 ( V_13 ) ;
struct V_25 * V_26 = V_18 -> V_26 ;
int V_117 = 0 ;
if ( ( unsigned long ) V_116 & V_118 ) {
F_6 ( V_13 ) -> V_60 = NULL ;
F_73 ( & V_13 -> V_119 ) ;
}
F_27 ( & V_26 -> V_24 , V_44 ) ;
F_23 ( V_18 ) ;
if ( ! ( V_18 -> V_90 . V_52 & ~ V_120 ) )
goto V_49;
if ( V_116 && ! ( ( unsigned long ) V_116 & V_18 -> V_90 . V_52 ) )
goto V_49;
if ( F_100 ( V_26 -> V_28 != V_29 ) ) {
if ( V_18 -> V_71 == V_29 ) {
V_18 -> V_71 = V_26 -> V_28 ;
V_26 -> V_28 = V_18 ;
if ( V_18 -> V_64 ) {
F_52 ( V_26 -> V_64 ) ;
}
}
goto V_49;
}
if ( ! F_4 ( & V_18 -> V_72 ) ) {
F_61 ( & V_18 -> V_72 , & V_26 -> V_27 ) ;
F_55 ( V_18 ) ;
}
if ( F_64 ( & V_26 -> V_55 ) ) {
if ( ( V_18 -> V_90 . V_52 & V_121 ) &&
! ( ( unsigned long ) V_116 & V_118 ) ) {
switch ( ( unsigned long ) V_116 & V_122 ) {
case V_54 :
if ( V_18 -> V_90 . V_52 & V_54 )
V_117 = 1 ;
break;
case V_123 :
if ( V_18 -> V_90 . V_52 & V_123 )
V_117 = 1 ;
break;
case 0 :
V_117 = 1 ;
break;
}
}
F_65 ( & V_26 -> V_55 ) ;
}
if ( F_64 ( & V_26 -> V_73 ) )
V_68 ++ ;
V_49:
F_30 ( & V_26 -> V_24 , V_44 ) ;
if ( V_68 )
F_37 ( & V_26 -> V_73 ) ;
if ( V_18 -> V_90 . V_52 & V_121 )
return V_117 ;
return 1 ;
}
static void V_99 ( struct V_1 * V_1 , T_3 * V_60 ,
T_2 * V_17 )
{
struct V_14 * V_18 = F_9 ( V_17 ) ;
struct V_12 * V_59 ;
if ( V_18 -> V_124 >= 0 && ( V_59 = F_105 ( V_62 , V_108 ) ) ) {
F_106 ( & V_59 -> V_13 , F_104 ) ;
V_59 -> V_60 = V_60 ;
V_59 -> V_15 = V_18 ;
if ( V_18 -> V_90 . V_52 & V_121 )
F_107 ( V_60 , & V_59 -> V_13 ) ;
else
F_108 ( V_60 , & V_59 -> V_13 ) ;
F_61 ( & V_59 -> V_50 , & V_18 -> V_61 ) ;
V_18 -> V_124 ++ ;
} else {
V_18 -> V_124 = - 1 ;
}
}
static void F_109 ( struct V_25 * V_26 , struct V_14 * V_18 )
{
int V_110 ;
struct V_84 * * V_11 = & V_26 -> V_81 . V_84 , * V_125 = NULL ;
struct V_14 * V_126 ;
while ( * V_11 ) {
V_125 = * V_11 ;
V_126 = F_81 ( V_125 , struct V_14 , V_80 ) ;
V_110 = F_3 ( & V_18 -> V_6 , & V_126 -> V_6 ) ;
if ( V_110 > 0 )
V_11 = & V_125 -> V_112 ;
else
V_11 = & V_125 -> V_113 ;
}
F_110 ( & V_18 -> V_80 , V_125 , V_11 ) ;
F_111 ( & V_18 -> V_80 , & V_26 -> V_81 ) ;
}
static int F_112 ( int V_127 )
{
if ( V_127 == 0 )
return 0 ;
if ( ++ V_128 [ V_127 ] > V_129 [ V_127 ] )
return - 1 ;
return 0 ;
}
static void F_113 ( void )
{
int V_130 ;
for ( V_130 = 0 ; V_130 < V_131 ; V_130 ++ )
V_128 [ V_130 ] = 0 ;
}
static int F_114 ( void * V_40 , void * V_41 , int V_43 )
{
int error = 0 ;
struct V_1 * V_1 = V_40 ;
struct V_1 * V_132 ;
struct V_14 * V_18 ;
F_41 () ;
F_115 (epi, &file->f_ep_links, fllink) {
V_132 = V_18 -> V_26 -> V_1 ;
if ( F_1 ( V_132 ) ) {
if ( F_5 ( & V_132 -> V_133 ) ) {
if ( F_112 ( V_43 ) ) {
error = - 1 ;
break;
}
} else {
error = F_25 ( & V_134 ,
V_58 ,
F_114 ,
V_132 , V_132 ,
V_101 ) ;
}
if ( error != 0 )
break;
} else {
F_116 ( V_135 L_2
L_3 ) ;
}
}
F_44 () ;
return error ;
}
static int F_117 ( void )
{
int error = 0 ;
struct V_1 * V_136 ;
F_28 (current_file, &tfile_check_list, f_tfile_llink) {
F_113 () ;
error = F_25 ( & V_134 , V_58 ,
F_114 , V_136 ,
V_136 , V_101 ) ;
if ( error )
break;
}
return error ;
}
static int F_118 ( struct V_14 * V_18 )
{
const char * V_137 ;
struct V_63 * V_64 ;
if ( ! V_18 -> V_26 -> V_64 ) {
V_18 -> V_26 -> V_64 = F_119 ( L_4 ) ;
if ( ! V_18 -> V_26 -> V_64 )
return - V_107 ;
}
V_137 = V_18 -> V_6 . V_1 -> V_138 . V_139 -> V_140 . V_137 ;
V_64 = F_119 ( V_137 ) ;
if ( ! V_64 )
return - V_107 ;
F_120 ( V_18 -> V_64 , V_64 ) ;
return 0 ;
}
static T_4 void F_121 ( struct V_14 * V_18 )
{
struct V_63 * V_64 = F_48 ( V_18 ) ;
F_122 ( V_18 -> V_64 , NULL ) ;
F_123 () ;
F_74 ( V_64 ) ;
}
static int F_124 ( struct V_25 * V_26 , struct V_141 * V_90 ,
struct V_1 * V_142 , int V_7 , int V_143 )
{
int error , V_144 , V_68 = 0 ;
unsigned long V_44 ;
long V_145 ;
struct V_14 * V_18 ;
struct V_16 V_146 ;
V_145 = F_125 ( & V_26 -> V_82 -> V_83 ) ;
if ( F_100 ( V_145 >= V_147 ) )
return - V_148 ;
if ( ! ( V_18 = F_105 ( V_77 , V_108 ) ) )
return - V_107 ;
F_12 ( & V_18 -> V_72 ) ;
F_12 ( & V_18 -> V_79 ) ;
F_12 ( & V_18 -> V_61 ) ;
V_18 -> V_26 = V_26 ;
F_2 ( & V_18 -> V_6 , V_142 , V_7 ) ;
V_18 -> V_90 = * V_90 ;
V_18 -> V_124 = 0 ;
V_18 -> V_71 = V_29 ;
if ( V_18 -> V_90 . V_52 & V_149 ) {
error = F_118 ( V_18 ) ;
if ( error )
goto V_150;
} else {
F_122 ( V_18 -> V_64 , NULL ) ;
}
V_146 . V_18 = V_18 ;
F_89 ( & V_146 . V_17 , V_99 ) ;
V_144 = F_87 ( V_18 , & V_146 . V_17 ) ;
error = - V_107 ;
if ( V_18 -> V_124 < 0 )
goto V_151;
F_69 ( & V_142 -> V_78 ) ;
F_126 ( & V_18 -> V_79 , & V_142 -> V_133 ) ;
F_71 ( & V_142 -> V_78 ) ;
F_109 ( V_26 , V_18 ) ;
error = - V_152 ;
if ( V_143 && F_117 () )
goto V_153;
F_27 ( & V_26 -> V_24 , V_44 ) ;
F_23 ( V_18 ) ;
if ( ( V_144 & V_90 -> V_52 ) && ! F_4 ( & V_18 -> V_72 ) ) {
F_61 ( & V_18 -> V_72 , & V_26 -> V_27 ) ;
F_51 ( V_18 ) ;
if ( F_64 ( & V_26 -> V_55 ) )
F_65 ( & V_26 -> V_55 ) ;
if ( F_64 ( & V_26 -> V_73 ) )
V_68 ++ ;
}
F_30 ( & V_26 -> V_24 , V_44 ) ;
F_127 ( & V_26 -> V_82 -> V_83 ) ;
if ( V_68 )
F_37 ( & V_26 -> V_73 ) ;
return 0 ;
V_153:
F_69 ( & V_142 -> V_78 ) ;
F_70 ( & V_18 -> V_79 ) ;
F_71 ( & V_142 -> V_78 ) ;
F_72 ( & V_18 -> V_80 , & V_26 -> V_81 ) ;
V_151:
F_45 ( V_26 , V_18 ) ;
F_27 ( & V_26 -> V_24 , V_44 ) ;
if ( F_4 ( & V_18 -> V_72 ) )
F_73 ( & V_18 -> V_72 ) ;
F_30 ( & V_26 -> V_24 , V_44 ) ;
F_74 ( F_48 ( V_18 ) ) ;
V_150:
F_47 ( V_77 , V_18 ) ;
return error ;
}
static int F_128 ( struct V_25 * V_26 , struct V_14 * V_18 , struct V_141 * V_90 )
{
int V_68 = 0 ;
unsigned int V_144 ;
T_2 V_17 ;
F_89 ( & V_17 , NULL ) ;
V_18 -> V_90 . V_52 = V_90 -> V_52 ;
V_18 -> V_90 . V_104 = V_90 -> V_104 ;
if ( V_18 -> V_90 . V_52 & V_149 ) {
if ( ! F_53 ( V_18 ) )
F_118 ( V_18 ) ;
} else if ( F_53 ( V_18 ) ) {
F_121 ( V_18 ) ;
}
F_129 () ;
V_144 = F_87 ( V_18 , & V_17 ) ;
if ( V_144 & V_90 -> V_52 ) {
F_130 ( & V_26 -> V_24 ) ;
if ( ! F_4 ( & V_18 -> V_72 ) ) {
F_61 ( & V_18 -> V_72 , & V_26 -> V_27 ) ;
F_51 ( V_18 ) ;
if ( F_64 ( & V_26 -> V_55 ) )
F_65 ( & V_26 -> V_55 ) ;
if ( F_64 ( & V_26 -> V_73 ) )
V_68 ++ ;
}
F_131 ( & V_26 -> V_24 ) ;
}
if ( V_68 )
F_37 ( & V_26 -> V_73 ) ;
return 0 ;
}
static int F_132 ( struct V_25 * V_26 , struct V_10 * V_75 ,
void * V_40 )
{
struct V_154 * V_155 = V_40 ;
int V_156 ;
unsigned int V_144 ;
struct V_14 * V_18 ;
struct V_141 T_5 * V_157 ;
struct V_63 * V_64 ;
T_2 V_17 ;
F_89 ( & V_17 , NULL ) ;
for ( V_156 = 0 , V_157 = V_155 -> V_52 ;
! F_5 ( V_75 ) && V_156 < V_155 -> V_158 ; ) {
V_18 = F_46 ( V_75 , struct V_14 , V_72 ) ;
V_64 = F_48 ( V_18 ) ;
if ( V_64 ) {
if ( V_64 -> V_159 )
F_52 ( V_26 -> V_64 ) ;
F_63 ( V_64 ) ;
}
F_73 ( & V_18 -> V_72 ) ;
V_144 = F_87 ( V_18 , & V_17 ) ;
if ( V_144 ) {
if ( F_133 ( V_144 , & V_157 -> V_52 ) ||
F_133 ( V_18 -> V_90 . V_104 , & V_157 -> V_104 ) ) {
F_29 ( & V_18 -> V_72 , V_75 ) ;
F_51 ( V_18 ) ;
return V_156 ? V_156 : - V_160 ;
}
V_156 ++ ;
V_157 ++ ;
if ( V_18 -> V_90 . V_52 & V_161 )
V_18 -> V_90 . V_52 &= V_120 ;
else if ( ! ( V_18 -> V_90 . V_52 & V_162 ) ) {
F_61 ( & V_18 -> V_72 , & V_26 -> V_27 ) ;
F_51 ( V_18 ) ;
}
}
}
return V_156 ;
}
static int F_134 ( struct V_25 * V_26 ,
struct V_141 T_5 * V_52 , int V_158 )
{
struct V_154 V_155 ;
V_155 . V_158 = V_158 ;
V_155 . V_52 = V_52 ;
return F_56 ( V_26 , F_132 , & V_155 , 0 , false ) ;
}
static inline struct V_163 F_135 ( long V_164 )
{
struct V_163 V_165 , V_166 = {
. V_167 = V_164 / V_168 ,
. V_169 = V_170 * ( V_164 % V_168 ) ,
} ;
F_136 ( & V_165 ) ;
return F_137 ( V_165 , V_166 ) ;
}
static int F_138 ( struct V_25 * V_26 , struct V_141 T_5 * V_52 ,
int V_158 , long V_171 )
{
int V_172 = 0 , V_173 , V_174 = 0 ;
unsigned long V_44 ;
T_6 V_175 = 0 ;
T_1 V_13 ;
T_7 V_176 , * V_177 = NULL ;
if ( V_171 > 0 ) {
struct V_163 V_178 = F_135 ( V_171 ) ;
V_175 = F_139 ( & V_178 ) ;
V_177 = & V_176 ;
* V_177 = F_140 ( V_178 ) ;
} else if ( V_171 == 0 ) {
V_174 = 1 ;
F_27 ( & V_26 -> V_24 , V_44 ) ;
goto V_179;
}
V_180:
if ( ! F_14 ( V_26 ) )
F_17 ( V_26 , V_174 ) ;
F_27 ( & V_26 -> V_24 , V_44 ) ;
if ( ! F_14 ( V_26 ) ) {
F_22 ( V_26 ) ;
F_141 ( & V_13 , V_101 ) ;
F_142 ( & V_26 -> V_55 , & V_13 ) ;
for (; ; ) {
F_143 ( V_181 ) ;
if ( F_14 ( V_26 ) || V_174 )
break;
if ( F_144 ( V_101 ) ) {
V_172 = - V_182 ;
break;
}
F_30 ( & V_26 -> V_24 , V_44 ) ;
if ( ! F_145 ( V_177 , V_175 , V_183 ) )
V_174 = 1 ;
F_27 ( & V_26 -> V_24 , V_44 ) ;
}
F_146 ( & V_26 -> V_55 , & V_13 ) ;
F_147 ( V_184 ) ;
}
V_179:
V_173 = F_14 ( V_26 ) ;
F_30 ( & V_26 -> V_24 , V_44 ) ;
if ( ! V_172 && V_173 &&
! ( V_172 = F_134 ( V_26 , V_52 , V_158 ) ) && ! V_174 )
goto V_180;
return V_172 ;
}
static int F_148 ( void * V_40 , void * V_41 , int V_43 )
{
int error = 0 ;
struct V_1 * V_1 = V_40 ;
struct V_25 * V_26 = V_1 -> V_88 ;
struct V_25 * V_185 ;
struct V_84 * V_85 ;
struct V_14 * V_18 ;
F_59 ( & V_26 -> V_65 , V_43 + 1 ) ;
V_26 -> V_186 = 1 ;
F_29 ( & V_26 -> V_187 , & V_188 ) ;
for ( V_85 = F_79 ( & V_26 -> V_81 ) ; V_85 ; V_85 = F_80 ( V_85 ) ) {
V_18 = F_81 ( V_85 , struct V_14 , V_80 ) ;
if ( F_100 ( F_1 ( V_18 -> V_6 . V_1 ) ) ) {
V_185 = V_18 -> V_6 . V_1 -> V_88 ;
if ( V_185 -> V_186 )
continue;
error = F_25 ( & V_134 , V_58 ,
F_148 , V_18 -> V_6 . V_1 ,
V_185 , V_101 ) ;
if ( error != 0 )
break;
} else {
if ( F_5 ( & V_18 -> V_6 . V_1 -> V_189 ) )
F_29 ( & V_18 -> V_6 . V_1 -> V_189 ,
& V_190 ) ;
}
}
F_66 ( & V_26 -> V_65 ) ;
return error ;
}
static int F_149 ( struct V_25 * V_26 , struct V_1 * V_1 )
{
int V_191 ;
struct V_25 * V_192 , * V_193 ;
V_191 = F_25 ( & V_134 , V_58 ,
F_148 , V_1 , V_26 , V_101 ) ;
F_90 (ep_cur, ep_next, &visited_list,
visited_list_link) {
V_192 -> V_186 = 0 ;
F_31 ( & V_192 -> V_187 ) ;
}
return V_191 ;
}
static void F_150 ( void )
{
struct V_1 * V_1 ;
while ( ! F_5 ( & V_190 ) ) {
V_1 = F_46 ( & V_190 , struct V_1 ,
V_189 ) ;
F_73 ( & V_1 -> V_189 ) ;
}
F_12 ( & V_190 ) ;
}
static int T_8 F_151 ( void )
{
struct V_194 V_195 ;
F_152 ( & V_195 ) ;
V_147 = ( ( ( V_195 . V_196 - V_195 . V_197 ) / 25 ) << V_198 ) /
V_199 ;
F_153 ( V_147 < 0 ) ;
F_11 ( & V_134 ) ;
F_11 ( & V_57 ) ;
F_11 ( & V_100 ) ;
F_154 ( sizeof( void * ) <= 8 && sizeof( struct V_14 ) > 128 ) ;
V_77 = F_155 ( L_5 , sizeof( struct V_14 ) ,
0 , V_200 | V_201 , NULL ) ;
V_62 = F_155 ( L_6 ,
sizeof( struct V_12 ) , 0 , V_201 , NULL ) ;
return 0 ;
}
