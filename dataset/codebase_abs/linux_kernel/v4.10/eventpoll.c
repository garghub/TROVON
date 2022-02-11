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
static int F_15 ( struct V_21 * V_22 , int V_30 ,
int (* F_16)( void * , void * , int ) , void * V_31 ,
void * V_32 , void * V_33 )
{
int error , V_34 = 0 ;
unsigned long V_35 ;
struct V_10 * V_36 = & V_22 -> V_23 ;
struct V_37 * V_38 ;
struct V_37 V_39 ;
F_17 ( & V_22 -> V_24 , V_35 ) ;
F_18 (tncur, lsthead, llink) {
if ( V_38 -> V_33 == V_33 &&
( V_38 -> V_32 == V_32 || ++ V_34 > V_30 ) ) {
error = - 1 ;
goto V_40;
}
}
V_39 . V_33 = V_33 ;
V_39 . V_32 = V_32 ;
F_19 ( & V_39 . V_41 , V_36 ) ;
F_20 ( & V_22 -> V_24 , V_35 ) ;
error = (* F_16)( V_31 , V_32 , V_34 ) ;
F_17 ( & V_22 -> V_24 , V_35 ) ;
F_21 ( & V_39 . V_41 ) ;
V_40:
F_20 ( & V_22 -> V_24 , V_35 ) ;
return error ;
}
static inline void F_22 ( T_3 * V_42 ,
unsigned long V_43 , int V_44 )
{
unsigned long V_35 ;
F_23 ( & V_42 -> V_24 , V_35 , V_44 ) ;
F_24 ( V_42 , V_43 ) ;
F_20 ( & V_42 -> V_24 , V_35 ) ;
}
static inline void F_22 ( T_3 * V_42 ,
unsigned long V_43 , int V_44 )
{
F_25 ( V_42 , V_43 ) ;
}
static int F_26 ( void * V_31 , void * V_32 , int V_34 )
{
F_22 ( ( T_3 * ) V_32 , V_45 ,
1 + V_34 ) ;
return 0 ;
}
static void F_27 ( T_3 * V_46 )
{
int V_47 = F_28 () ;
F_15 ( & V_48 , V_49 ,
F_26 , NULL , V_46 , ( void * ) ( long ) V_47 ) ;
F_29 () ;
}
static void F_30 ( struct V_12 * V_50 )
{
T_3 * V_51 ;
F_31 () ;
V_51 = F_32 ( V_50 -> V_51 ) ;
if ( V_51 )
F_33 ( V_51 , & V_50 -> V_13 ) ;
F_34 () ;
}
static void F_35 ( struct V_25 * V_26 , struct V_14 * V_18 )
{
struct V_10 * V_36 = & V_18 -> V_52 ;
struct V_12 * V_50 ;
while ( ! F_5 ( V_36 ) ) {
V_50 = F_36 ( V_36 , struct V_12 , V_41 ) ;
F_21 ( & V_50 -> V_41 ) ;
F_30 ( V_50 ) ;
F_37 ( V_53 , V_50 ) ;
}
}
static inline struct V_54 * F_38 ( struct V_14 * V_18 )
{
return F_39 ( V_18 -> V_55 , F_40 ( & V_18 -> V_26 -> V_56 ) ) ;
}
static inline void F_41 ( struct V_14 * V_18 )
{
struct V_54 * V_55 = F_38 ( V_18 ) ;
if ( V_55 )
F_42 ( V_55 ) ;
}
static inline bool F_43 ( struct V_14 * V_18 )
{
return F_44 ( V_18 -> V_55 ) ? true : false ;
}
static inline void F_45 ( struct V_14 * V_18 )
{
struct V_54 * V_55 ;
F_31 () ;
V_55 = F_32 ( V_18 -> V_55 ) ;
if ( V_55 )
F_42 ( V_55 ) ;
F_34 () ;
}
static int F_46 ( struct V_25 * V_26 ,
int (* F_47)( struct V_25 * ,
struct V_10 * , void * ) ,
void * V_31 , int V_57 , bool V_58 )
{
int error , V_59 = 0 ;
unsigned long V_35 ;
struct V_14 * V_18 , * V_60 ;
F_48 ( V_61 ) ;
if ( ! V_58 )
F_49 ( & V_26 -> V_56 , V_57 ) ;
F_17 ( & V_26 -> V_24 , V_35 ) ;
F_50 ( & V_26 -> V_27 , & V_61 ) ;
V_26 -> V_28 = NULL ;
F_20 ( & V_26 -> V_24 , V_35 ) ;
error = (* F_47)( V_26 , & V_61 , V_31 ) ;
F_17 ( & V_26 -> V_24 , V_35 ) ;
for ( V_60 = V_26 -> V_28 ; ( V_18 = V_60 ) != NULL ;
V_60 = V_18 -> V_62 , V_18 -> V_62 = V_29 ) {
if ( ! F_4 ( & V_18 -> V_63 ) ) {
F_51 ( & V_18 -> V_63 , & V_26 -> V_27 ) ;
F_41 ( V_18 ) ;
}
}
V_26 -> V_28 = V_29 ;
F_52 ( & V_61 , & V_26 -> V_27 ) ;
F_53 ( V_26 -> V_55 ) ;
if ( ! F_5 ( & V_26 -> V_27 ) ) {
if ( F_54 ( & V_26 -> V_46 ) )
F_55 ( & V_26 -> V_46 ) ;
if ( F_54 ( & V_26 -> V_64 ) )
V_59 ++ ;
}
F_20 ( & V_26 -> V_24 , V_35 ) ;
if ( ! V_58 )
F_56 ( & V_26 -> V_56 ) ;
if ( V_59 )
F_27 ( & V_26 -> V_64 ) ;
return error ;
}
static void F_57 ( struct V_65 * V_66 )
{
struct V_14 * V_18 = F_7 ( V_66 , struct V_14 , V_67 ) ;
F_37 ( V_68 , V_18 ) ;
}
static int F_58 ( struct V_25 * V_26 , struct V_14 * V_18 )
{
unsigned long V_35 ;
struct V_1 * V_1 = V_18 -> V_6 . V_1 ;
F_35 ( V_26 , V_18 ) ;
F_59 ( & V_1 -> V_69 ) ;
F_60 ( & V_18 -> V_70 ) ;
F_61 ( & V_1 -> V_69 ) ;
F_62 ( & V_18 -> V_71 , & V_26 -> V_72 ) ;
F_17 ( & V_26 -> V_24 , V_35 ) ;
if ( F_4 ( & V_18 -> V_63 ) )
F_63 ( & V_18 -> V_63 ) ;
F_20 ( & V_26 -> V_24 , V_35 ) ;
F_64 ( F_38 ( V_18 ) ) ;
F_65 ( & V_18 -> V_67 , F_57 ) ;
F_66 ( & V_26 -> V_73 -> V_74 ) ;
return 0 ;
}
static void F_67 ( struct V_25 * V_26 )
{
struct V_75 * V_76 ;
struct V_14 * V_18 ;
if ( F_54 ( & V_26 -> V_64 ) )
F_27 ( & V_26 -> V_64 ) ;
F_68 ( & V_77 ) ;
for ( V_76 = F_69 ( & V_26 -> V_72 ) ; V_76 ; V_76 = F_70 ( V_76 ) ) {
V_18 = F_71 ( V_76 , struct V_14 , V_71 ) ;
F_35 ( V_26 , V_18 ) ;
F_72 () ;
}
F_68 ( & V_26 -> V_56 ) ;
while ( ( V_76 = F_69 ( & V_26 -> V_72 ) ) != NULL ) {
V_18 = F_71 ( V_76 , struct V_14 , V_71 ) ;
F_58 ( V_26 , V_18 ) ;
F_72 () ;
}
F_56 ( & V_26 -> V_56 ) ;
F_56 ( & V_77 ) ;
F_73 ( & V_26 -> V_56 ) ;
F_74 ( V_26 -> V_73 ) ;
F_64 ( V_26 -> V_55 ) ;
F_75 ( V_26 ) ;
}
static int F_76 ( struct V_78 * V_78 , struct V_1 * V_1 )
{
struct V_25 * V_26 = V_1 -> V_79 ;
if ( V_26 )
F_67 ( V_26 ) ;
return 0 ;
}
static inline unsigned int F_77 ( struct V_14 * V_18 , T_2 * V_17 )
{
V_17 -> V_80 = V_18 -> V_81 . V_43 ;
return V_18 -> V_6 . V_1 -> V_3 -> V_82 ( V_18 -> V_6 . V_1 , V_17 ) & V_18 -> V_81 . V_43 ;
}
static int F_78 ( struct V_25 * V_26 , struct V_10 * V_66 ,
void * V_31 )
{
struct V_14 * V_18 , * V_83 ;
T_2 V_17 ;
F_79 ( & V_17 , NULL ) ;
F_80 (epi, tmp, head, rdllink) {
if ( F_77 ( V_18 , & V_17 ) )
return V_45 | V_84 ;
else {
F_53 ( F_38 ( V_18 ) ) ;
F_63 ( & V_18 -> V_63 ) ;
}
}
return 0 ;
}
static int F_81 ( void * V_31 , void * V_32 , int V_34 )
{
struct V_85 * V_86 = V_31 ;
return F_46 ( V_86 -> V_26 , F_78 , NULL ,
V_34 + 1 , V_86 -> V_87 ) ;
}
static unsigned int F_82 ( struct V_1 * V_1 , T_2 * V_13 )
{
int V_88 ;
struct V_25 * V_26 = V_1 -> V_79 ;
struct V_85 V_86 ;
V_86 . V_87 = V_13 && ( V_13 -> V_89 == V_90 ) ;
V_86 . V_26 = V_26 ;
V_64 ( V_1 , & V_26 -> V_64 , V_13 ) ;
V_88 = F_15 ( & V_91 , V_49 ,
F_81 , & V_86 , V_26 , V_92 ) ;
return V_88 != - 1 ? V_88 : 0 ;
}
static void F_83 ( struct V_93 * V_94 , struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_79 ;
struct V_75 * V_76 ;
F_68 ( & V_26 -> V_56 ) ;
for ( V_76 = F_69 ( & V_26 -> V_72 ) ; V_76 ; V_76 = F_70 ( V_76 ) ) {
struct V_14 * V_18 = F_71 ( V_76 , struct V_14 , V_71 ) ;
F_84 ( V_94 , L_1 ,
V_18 -> V_6 . V_7 , V_18 -> V_81 . V_43 ,
( long long ) V_18 -> V_81 . V_95 ) ;
if ( F_85 ( V_94 ) )
break;
}
F_56 ( & V_26 -> V_56 ) ;
}
void F_86 ( struct V_1 * V_1 )
{
struct V_25 * V_26 ;
struct V_14 * V_18 , * V_62 ;
F_68 ( & V_77 ) ;
F_80 (epi, next, &file->f_ep_links, fllink) {
V_26 = V_18 -> V_26 ;
F_49 ( & V_26 -> V_56 , 0 ) ;
F_58 ( V_26 , V_18 ) ;
F_56 ( & V_26 -> V_56 ) ;
}
F_56 ( & V_77 ) ;
}
static int F_87 ( struct V_25 * * V_96 )
{
int error ;
struct V_97 * V_73 ;
struct V_25 * V_26 ;
V_73 = F_88 () ;
error = - V_98 ;
V_26 = F_89 ( sizeof( * V_26 ) , V_99 ) ;
if ( F_90 ( ! V_26 ) )
goto F_74;
F_13 ( & V_26 -> V_24 ) ;
F_91 ( & V_26 -> V_56 ) ;
F_92 ( & V_26 -> V_46 ) ;
F_92 ( & V_26 -> V_64 ) ;
F_12 ( & V_26 -> V_27 ) ;
V_26 -> V_72 = V_100 ;
V_26 -> V_28 = V_29 ;
V_26 -> V_73 = V_73 ;
* V_96 = V_26 ;
return 0 ;
F_74:
F_74 ( V_73 ) ;
return error ;
}
static struct V_14 * F_93 ( struct V_25 * V_26 , struct V_1 * V_1 , int V_7 )
{
int V_101 ;
struct V_75 * V_76 ;
struct V_14 * V_18 , * V_102 = NULL ;
struct V_5 V_6 ;
F_2 ( & V_6 , V_1 , V_7 ) ;
for ( V_76 = V_26 -> V_72 . V_75 ; V_76 ; ) {
V_18 = F_71 ( V_76 , struct V_14 , V_71 ) ;
V_101 = F_3 ( & V_6 , & V_18 -> V_6 ) ;
if ( V_101 > 0 )
V_76 = V_76 -> V_103 ;
else if ( V_101 < 0 )
V_76 = V_76 -> V_104 ;
else {
V_102 = V_18 ;
break;
}
}
return V_102 ;
}
static int F_94 ( T_1 * V_13 , unsigned V_105 , int V_106 , void * V_107 )
{
int V_59 = 0 ;
unsigned long V_35 ;
struct V_14 * V_18 = F_8 ( V_13 ) ;
struct V_25 * V_26 = V_18 -> V_26 ;
int V_108 = 0 ;
if ( ( unsigned long ) V_107 & V_109 ) {
F_6 ( V_13 ) -> V_51 = NULL ;
F_63 ( & V_13 -> V_110 ) ;
}
F_17 ( & V_26 -> V_24 , V_35 ) ;
if ( ! ( V_18 -> V_81 . V_43 & ~ V_111 ) )
goto V_40;
if ( V_107 && ! ( ( unsigned long ) V_107 & V_18 -> V_81 . V_43 ) )
goto V_40;
if ( F_90 ( V_26 -> V_28 != V_29 ) ) {
if ( V_18 -> V_62 == V_29 ) {
V_18 -> V_62 = V_26 -> V_28 ;
V_26 -> V_28 = V_18 ;
if ( V_18 -> V_55 ) {
F_42 ( V_26 -> V_55 ) ;
}
}
goto V_40;
}
if ( ! F_4 ( & V_18 -> V_63 ) ) {
F_51 ( & V_18 -> V_63 , & V_26 -> V_27 ) ;
F_45 ( V_18 ) ;
}
if ( F_54 ( & V_26 -> V_46 ) ) {
if ( ( V_18 -> V_81 . V_43 & V_112 ) &&
! ( ( unsigned long ) V_107 & V_109 ) ) {
switch ( ( unsigned long ) V_107 & V_113 ) {
case V_45 :
if ( V_18 -> V_81 . V_43 & V_45 )
V_108 = 1 ;
break;
case V_114 :
if ( V_18 -> V_81 . V_43 & V_114 )
V_108 = 1 ;
break;
case 0 :
V_108 = 1 ;
break;
}
}
F_55 ( & V_26 -> V_46 ) ;
}
if ( F_54 ( & V_26 -> V_64 ) )
V_59 ++ ;
V_40:
F_20 ( & V_26 -> V_24 , V_35 ) ;
if ( V_59 )
F_27 ( & V_26 -> V_64 ) ;
if ( V_18 -> V_81 . V_43 & V_112 )
return V_108 ;
return 1 ;
}
static void V_90 ( struct V_1 * V_1 , T_3 * V_51 ,
T_2 * V_17 )
{
struct V_14 * V_18 = F_9 ( V_17 ) ;
struct V_12 * V_50 ;
if ( V_18 -> V_115 >= 0 && ( V_50 = F_95 ( V_53 , V_99 ) ) ) {
F_96 ( & V_50 -> V_13 , F_94 ) ;
V_50 -> V_51 = V_51 ;
V_50 -> V_15 = V_18 ;
if ( V_18 -> V_81 . V_43 & V_112 )
F_97 ( V_51 , & V_50 -> V_13 ) ;
else
F_98 ( V_51 , & V_50 -> V_13 ) ;
F_51 ( & V_50 -> V_41 , & V_18 -> V_52 ) ;
V_18 -> V_115 ++ ;
} else {
V_18 -> V_115 = - 1 ;
}
}
static void F_99 ( struct V_25 * V_26 , struct V_14 * V_18 )
{
int V_101 ;
struct V_75 * * V_11 = & V_26 -> V_72 . V_75 , * V_116 = NULL ;
struct V_14 * V_117 ;
while ( * V_11 ) {
V_116 = * V_11 ;
V_117 = F_71 ( V_116 , struct V_14 , V_71 ) ;
V_101 = F_3 ( & V_18 -> V_6 , & V_117 -> V_6 ) ;
if ( V_101 > 0 )
V_11 = & V_116 -> V_103 ;
else
V_11 = & V_116 -> V_104 ;
}
F_100 ( & V_18 -> V_71 , V_116 , V_11 ) ;
F_101 ( & V_18 -> V_71 , & V_26 -> V_72 ) ;
}
static int F_102 ( int V_118 )
{
if ( V_118 == 0 )
return 0 ;
if ( ++ V_119 [ V_118 ] > V_120 [ V_118 ] )
return - 1 ;
return 0 ;
}
static void F_103 ( void )
{
int V_121 ;
for ( V_121 = 0 ; V_121 < V_122 ; V_121 ++ )
V_119 [ V_121 ] = 0 ;
}
static int F_104 ( void * V_31 , void * V_32 , int V_34 )
{
int error = 0 ;
struct V_1 * V_1 = V_31 ;
struct V_1 * V_123 ;
struct V_14 * V_18 ;
F_31 () ;
F_105 (epi, &file->f_ep_links, fllink) {
V_123 = V_18 -> V_26 -> V_1 ;
if ( F_1 ( V_123 ) ) {
if ( F_5 ( & V_123 -> V_124 ) ) {
if ( F_102 ( V_34 ) ) {
error = - 1 ;
break;
}
} else {
error = F_15 ( & V_125 ,
V_49 ,
F_104 ,
V_123 , V_123 ,
V_92 ) ;
}
if ( error != 0 )
break;
} else {
F_106 ( V_126 L_2
L_3 ) ;
}
}
F_34 () ;
return error ;
}
static int F_107 ( void )
{
int error = 0 ;
struct V_1 * V_127 ;
F_18 (current_file, &tfile_check_list, f_tfile_llink) {
F_103 () ;
error = F_15 ( & V_125 , V_49 ,
F_104 , V_127 ,
V_127 , V_92 ) ;
if ( error )
break;
}
return error ;
}
static int F_108 ( struct V_14 * V_18 )
{
const char * V_128 ;
struct V_54 * V_55 ;
if ( ! V_18 -> V_26 -> V_55 ) {
V_18 -> V_26 -> V_55 = F_109 ( L_4 ) ;
if ( ! V_18 -> V_26 -> V_55 )
return - V_98 ;
}
V_128 = V_18 -> V_6 . V_1 -> V_129 . V_130 -> V_131 . V_128 ;
V_55 = F_109 ( V_128 ) ;
if ( ! V_55 )
return - V_98 ;
F_110 ( V_18 -> V_55 , V_55 ) ;
return 0 ;
}
static T_4 void F_111 ( struct V_14 * V_18 )
{
struct V_54 * V_55 = F_38 ( V_18 ) ;
F_112 ( V_18 -> V_55 , NULL ) ;
F_113 () ;
F_64 ( V_55 ) ;
}
static int F_114 ( struct V_25 * V_26 , struct V_132 * V_81 ,
struct V_1 * V_133 , int V_7 , int V_134 )
{
int error , V_135 , V_59 = 0 ;
unsigned long V_35 ;
long V_136 ;
struct V_14 * V_18 ;
struct V_16 V_137 ;
V_136 = F_115 ( & V_26 -> V_73 -> V_74 ) ;
if ( F_90 ( V_136 >= V_138 ) )
return - V_139 ;
if ( ! ( V_18 = F_95 ( V_68 , V_99 ) ) )
return - V_98 ;
F_12 ( & V_18 -> V_63 ) ;
F_12 ( & V_18 -> V_70 ) ;
F_12 ( & V_18 -> V_52 ) ;
V_18 -> V_26 = V_26 ;
F_2 ( & V_18 -> V_6 , V_133 , V_7 ) ;
V_18 -> V_81 = * V_81 ;
V_18 -> V_115 = 0 ;
V_18 -> V_62 = V_29 ;
if ( V_18 -> V_81 . V_43 & V_140 ) {
error = F_108 ( V_18 ) ;
if ( error )
goto V_141;
} else {
F_112 ( V_18 -> V_55 , NULL ) ;
}
V_137 . V_18 = V_18 ;
F_79 ( & V_137 . V_17 , V_90 ) ;
V_135 = F_77 ( V_18 , & V_137 . V_17 ) ;
error = - V_98 ;
if ( V_18 -> V_115 < 0 )
goto V_142;
F_59 ( & V_133 -> V_69 ) ;
F_116 ( & V_18 -> V_70 , & V_133 -> V_124 ) ;
F_61 ( & V_133 -> V_69 ) ;
F_99 ( V_26 , V_18 ) ;
error = - V_143 ;
if ( V_134 && F_107 () )
goto V_144;
F_17 ( & V_26 -> V_24 , V_35 ) ;
if ( ( V_135 & V_81 -> V_43 ) && ! F_4 ( & V_18 -> V_63 ) ) {
F_51 ( & V_18 -> V_63 , & V_26 -> V_27 ) ;
F_41 ( V_18 ) ;
if ( F_54 ( & V_26 -> V_46 ) )
F_55 ( & V_26 -> V_46 ) ;
if ( F_54 ( & V_26 -> V_64 ) )
V_59 ++ ;
}
F_20 ( & V_26 -> V_24 , V_35 ) ;
F_117 ( & V_26 -> V_73 -> V_74 ) ;
if ( V_59 )
F_27 ( & V_26 -> V_64 ) ;
return 0 ;
V_144:
F_59 ( & V_133 -> V_69 ) ;
F_60 ( & V_18 -> V_70 ) ;
F_61 ( & V_133 -> V_69 ) ;
F_62 ( & V_18 -> V_71 , & V_26 -> V_72 ) ;
V_142:
F_35 ( V_26 , V_18 ) ;
F_17 ( & V_26 -> V_24 , V_35 ) ;
if ( F_4 ( & V_18 -> V_63 ) )
F_63 ( & V_18 -> V_63 ) ;
F_20 ( & V_26 -> V_24 , V_35 ) ;
F_64 ( F_38 ( V_18 ) ) ;
V_141:
F_37 ( V_68 , V_18 ) ;
return error ;
}
static int F_118 ( struct V_25 * V_26 , struct V_14 * V_18 , struct V_132 * V_81 )
{
int V_59 = 0 ;
unsigned int V_135 ;
T_2 V_17 ;
F_79 ( & V_17 , NULL ) ;
V_18 -> V_81 . V_43 = V_81 -> V_43 ;
V_18 -> V_81 . V_95 = V_81 -> V_95 ;
if ( V_18 -> V_81 . V_43 & V_140 ) {
if ( ! F_43 ( V_18 ) )
F_108 ( V_18 ) ;
} else if ( F_43 ( V_18 ) ) {
F_111 ( V_18 ) ;
}
F_119 () ;
V_135 = F_77 ( V_18 , & V_17 ) ;
if ( V_135 & V_81 -> V_43 ) {
F_120 ( & V_26 -> V_24 ) ;
if ( ! F_4 ( & V_18 -> V_63 ) ) {
F_51 ( & V_18 -> V_63 , & V_26 -> V_27 ) ;
F_41 ( V_18 ) ;
if ( F_54 ( & V_26 -> V_46 ) )
F_55 ( & V_26 -> V_46 ) ;
if ( F_54 ( & V_26 -> V_64 ) )
V_59 ++ ;
}
F_121 ( & V_26 -> V_24 ) ;
}
if ( V_59 )
F_27 ( & V_26 -> V_64 ) ;
return 0 ;
}
static int F_122 ( struct V_25 * V_26 , struct V_10 * V_66 ,
void * V_31 )
{
struct V_145 * V_146 = V_31 ;
int V_147 ;
unsigned int V_135 ;
struct V_14 * V_18 ;
struct V_132 T_5 * V_148 ;
struct V_54 * V_55 ;
T_2 V_17 ;
F_79 ( & V_17 , NULL ) ;
for ( V_147 = 0 , V_148 = V_146 -> V_43 ;
! F_5 ( V_66 ) && V_147 < V_146 -> V_149 ; ) {
V_18 = F_36 ( V_66 , struct V_14 , V_63 ) ;
V_55 = F_38 ( V_18 ) ;
if ( V_55 ) {
if ( V_55 -> V_150 )
F_42 ( V_26 -> V_55 ) ;
F_53 ( V_55 ) ;
}
F_63 ( & V_18 -> V_63 ) ;
V_135 = F_77 ( V_18 , & V_17 ) ;
if ( V_135 ) {
if ( F_123 ( V_135 , & V_148 -> V_43 ) ||
F_123 ( V_18 -> V_81 . V_95 , & V_148 -> V_95 ) ) {
F_19 ( & V_18 -> V_63 , V_66 ) ;
F_41 ( V_18 ) ;
return V_147 ? V_147 : - V_151 ;
}
V_147 ++ ;
V_148 ++ ;
if ( V_18 -> V_81 . V_43 & V_152 )
V_18 -> V_81 . V_43 &= V_111 ;
else if ( ! ( V_18 -> V_81 . V_43 & V_153 ) ) {
F_51 ( & V_18 -> V_63 , & V_26 -> V_27 ) ;
F_41 ( V_18 ) ;
}
}
}
return V_147 ;
}
static int F_124 ( struct V_25 * V_26 ,
struct V_132 T_5 * V_43 , int V_149 )
{
struct V_145 V_146 ;
V_146 . V_149 = V_149 ;
V_146 . V_43 = V_43 ;
return F_46 ( V_26 , F_122 , & V_146 , 0 , false ) ;
}
static inline struct V_154 F_125 ( long V_155 )
{
struct V_154 V_156 , V_157 = {
. V_158 = V_155 / V_159 ,
. V_160 = V_161 * ( V_155 % V_159 ) ,
} ;
F_126 ( & V_156 ) ;
return F_127 ( V_156 , V_157 ) ;
}
static int F_128 ( struct V_25 * V_26 , struct V_132 T_5 * V_43 ,
int V_149 , long V_162 )
{
int V_163 = 0 , V_164 , V_165 = 0 ;
unsigned long V_35 ;
T_6 V_166 = 0 ;
T_1 V_13 ;
T_7 V_167 , * V_168 = NULL ;
if ( V_162 > 0 ) {
struct V_154 V_169 = F_125 ( V_162 ) ;
V_166 = F_129 ( & V_169 ) ;
V_168 = & V_167 ;
* V_168 = F_130 ( V_169 ) ;
} else if ( V_162 == 0 ) {
V_165 = 1 ;
F_17 ( & V_26 -> V_24 , V_35 ) ;
goto V_170;
}
V_171:
F_17 ( & V_26 -> V_24 , V_35 ) ;
if ( ! F_14 ( V_26 ) ) {
F_131 ( & V_13 , V_92 ) ;
F_132 ( & V_26 -> V_46 , & V_13 ) ;
for (; ; ) {
F_133 ( V_172 ) ;
if ( F_14 ( V_26 ) || V_165 )
break;
if ( F_134 ( V_92 ) ) {
V_163 = - V_173 ;
break;
}
F_20 ( & V_26 -> V_24 , V_35 ) ;
if ( ! F_135 ( V_168 , V_166 , V_174 ) )
V_165 = 1 ;
F_17 ( & V_26 -> V_24 , V_35 ) ;
}
F_136 ( & V_26 -> V_46 , & V_13 ) ;
F_137 ( V_175 ) ;
}
V_170:
V_164 = F_14 ( V_26 ) ;
F_20 ( & V_26 -> V_24 , V_35 ) ;
if ( ! V_163 && V_164 &&
! ( V_163 = F_124 ( V_26 , V_43 , V_149 ) ) && ! V_165 )
goto V_171;
return V_163 ;
}
static int F_138 ( void * V_31 , void * V_32 , int V_34 )
{
int error = 0 ;
struct V_1 * V_1 = V_31 ;
struct V_25 * V_26 = V_1 -> V_79 ;
struct V_25 * V_176 ;
struct V_75 * V_76 ;
struct V_14 * V_18 ;
F_49 ( & V_26 -> V_56 , V_34 + 1 ) ;
V_26 -> V_177 = 1 ;
F_19 ( & V_26 -> V_178 , & V_179 ) ;
for ( V_76 = F_69 ( & V_26 -> V_72 ) ; V_76 ; V_76 = F_70 ( V_76 ) ) {
V_18 = F_71 ( V_76 , struct V_14 , V_71 ) ;
if ( F_90 ( F_1 ( V_18 -> V_6 . V_1 ) ) ) {
V_176 = V_18 -> V_6 . V_1 -> V_79 ;
if ( V_176 -> V_177 )
continue;
error = F_15 ( & V_125 , V_49 ,
F_138 , V_18 -> V_6 . V_1 ,
V_176 , V_92 ) ;
if ( error != 0 )
break;
} else {
if ( F_5 ( & V_18 -> V_6 . V_1 -> V_180 ) )
F_19 ( & V_18 -> V_6 . V_1 -> V_180 ,
& V_181 ) ;
}
}
F_56 ( & V_26 -> V_56 ) ;
return error ;
}
static int F_139 ( struct V_25 * V_26 , struct V_1 * V_1 )
{
int V_182 ;
struct V_25 * V_183 , * V_184 ;
V_182 = F_15 ( & V_125 , V_49 ,
F_138 , V_1 , V_26 , V_92 ) ;
F_80 (ep_cur, ep_next, &visited_list,
visited_list_link) {
V_183 -> V_177 = 0 ;
F_21 ( & V_183 -> V_178 ) ;
}
return V_182 ;
}
static void F_140 ( void )
{
struct V_1 * V_1 ;
while ( ! F_5 ( & V_181 ) ) {
V_1 = F_36 ( & V_181 , struct V_1 ,
V_180 ) ;
F_63 ( & V_1 -> V_180 ) ;
}
F_12 ( & V_181 ) ;
}
static int T_8 F_141 ( void )
{
struct V_185 V_186 ;
F_142 ( & V_186 ) ;
V_138 = ( ( ( V_186 . V_187 - V_186 . V_188 ) / 25 ) << V_189 ) /
V_190 ;
F_143 ( V_138 < 0 ) ;
F_11 ( & V_125 ) ;
F_11 ( & V_48 ) ;
F_11 ( & V_91 ) ;
F_144 ( sizeof( void * ) <= 8 && sizeof( struct V_14 ) > 128 ) ;
V_68 = F_145 ( L_5 , sizeof( struct V_14 ) ,
0 , V_191 | V_192 , NULL ) ;
V_53 = F_145 ( L_6 ,
sizeof( struct V_12 ) , 0 , V_192 , NULL ) ;
return 0 ;
}
