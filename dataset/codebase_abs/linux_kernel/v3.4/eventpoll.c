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
static int F_38 ( struct V_25 * V_26 ,
int (* F_39)( struct V_25 * ,
struct V_10 * , void * ) ,
void * V_31 ,
int V_54 )
{
int error , V_55 = 0 ;
unsigned long V_35 ;
struct V_14 * V_18 , * V_56 ;
F_40 ( V_57 ) ;
F_41 ( & V_26 -> V_58 , V_54 ) ;
F_17 ( & V_26 -> V_24 , V_35 ) ;
F_42 ( & V_26 -> V_27 , & V_57 ) ;
V_26 -> V_28 = NULL ;
F_20 ( & V_26 -> V_24 , V_35 ) ;
error = (* F_39)( V_26 , & V_57 , V_31 ) ;
F_17 ( & V_26 -> V_24 , V_35 ) ;
for ( V_56 = V_26 -> V_28 ; ( V_18 = V_56 ) != NULL ;
V_56 = V_18 -> V_59 , V_18 -> V_59 = V_29 ) {
if ( ! F_4 ( & V_18 -> V_60 ) )
F_43 ( & V_18 -> V_60 , & V_26 -> V_27 ) ;
}
V_26 -> V_28 = V_29 ;
F_44 ( & V_57 , & V_26 -> V_27 ) ;
if ( ! F_5 ( & V_26 -> V_27 ) ) {
if ( F_45 ( & V_26 -> V_46 ) )
F_46 ( & V_26 -> V_46 ) ;
if ( F_45 ( & V_26 -> V_61 ) )
V_55 ++ ;
}
F_20 ( & V_26 -> V_24 , V_35 ) ;
F_47 ( & V_26 -> V_58 ) ;
if ( V_55 )
F_27 ( & V_26 -> V_61 ) ;
return error ;
}
static int F_48 ( struct V_25 * V_26 , struct V_14 * V_18 )
{
unsigned long V_35 ;
struct V_1 * V_1 = V_18 -> V_6 . V_1 ;
F_35 ( V_26 , V_18 ) ;
F_49 ( & V_1 -> V_62 ) ;
if ( F_4 ( & V_18 -> V_63 ) )
F_50 ( & V_18 -> V_63 ) ;
F_51 ( & V_1 -> V_62 ) ;
F_52 ( & V_18 -> V_64 , & V_26 -> V_65 ) ;
F_17 ( & V_26 -> V_24 , V_35 ) ;
if ( F_4 ( & V_18 -> V_60 ) )
F_50 ( & V_18 -> V_60 ) ;
F_20 ( & V_26 -> V_24 , V_35 ) ;
F_37 ( V_66 , V_18 ) ;
F_53 ( & V_26 -> V_67 -> V_68 ) ;
return 0 ;
}
static void F_54 ( struct V_25 * V_26 )
{
struct V_69 * V_70 ;
struct V_14 * V_18 ;
if ( F_45 ( & V_26 -> V_61 ) )
F_27 ( & V_26 -> V_61 ) ;
F_55 ( & V_71 ) ;
for ( V_70 = F_56 ( & V_26 -> V_65 ) ; V_70 ; V_70 = F_57 ( V_70 ) ) {
V_18 = F_58 ( V_70 , struct V_14 , V_64 ) ;
F_35 ( V_26 , V_18 ) ;
}
while ( ( V_70 = F_56 ( & V_26 -> V_65 ) ) != NULL ) {
V_18 = F_58 ( V_70 , struct V_14 , V_64 ) ;
F_48 ( V_26 , V_18 ) ;
}
F_47 ( & V_71 ) ;
F_59 ( & V_26 -> V_58 ) ;
F_60 ( V_26 -> V_67 ) ;
F_61 ( V_26 ) ;
}
static int F_62 ( struct V_72 * V_72 , struct V_1 * V_1 )
{
struct V_25 * V_26 = V_1 -> V_73 ;
if ( V_26 )
F_54 ( V_26 ) ;
return 0 ;
}
static int F_63 ( struct V_25 * V_26 , struct V_10 * V_74 ,
void * V_31 )
{
struct V_14 * V_18 , * V_75 ;
T_2 V_17 ;
F_64 ( & V_17 , NULL ) ;
F_65 (epi, tmp, head, rdllink) {
V_17 . V_76 = V_18 -> V_77 . V_43 ;
if ( V_18 -> V_6 . V_1 -> V_3 -> V_78 ( V_18 -> V_6 . V_1 , & V_17 ) &
V_18 -> V_77 . V_43 )
return V_45 | V_79 ;
else {
F_50 ( & V_18 -> V_60 ) ;
}
}
return 0 ;
}
static int F_66 ( void * V_31 , void * V_32 , int V_34 )
{
return F_38 ( V_31 , F_63 , NULL , V_34 + 1 ) ;
}
static unsigned int F_67 ( struct V_1 * V_1 , T_2 * V_13 )
{
int V_80 ;
struct V_25 * V_26 = V_1 -> V_73 ;
V_61 ( V_1 , & V_26 -> V_61 , V_13 ) ;
V_80 = F_15 ( & V_81 , V_49 ,
F_66 , V_26 , V_26 , V_82 ) ;
return V_80 != - 1 ? V_80 : 0 ;
}
void F_68 ( struct V_1 * V_1 )
{
struct V_10 * V_36 = & V_1 -> V_83 ;
struct V_25 * V_26 ;
struct V_14 * V_18 ;
F_55 ( & V_71 ) ;
while ( ! F_5 ( V_36 ) ) {
V_18 = F_36 ( V_36 , struct V_14 , V_63 ) ;
V_26 = V_18 -> V_26 ;
F_50 ( & V_18 -> V_63 ) ;
F_41 ( & V_26 -> V_58 , 0 ) ;
F_48 ( V_26 , V_18 ) ;
F_47 ( & V_26 -> V_58 ) ;
}
F_47 ( & V_71 ) ;
}
static int F_69 ( struct V_25 * * V_84 )
{
int error ;
struct V_85 * V_67 ;
struct V_25 * V_26 ;
V_67 = F_70 () ;
error = - V_86 ;
V_26 = F_71 ( sizeof( * V_26 ) , V_87 ) ;
if ( F_72 ( ! V_26 ) )
goto F_60;
F_13 ( & V_26 -> V_24 ) ;
F_73 ( & V_26 -> V_58 ) ;
F_74 ( & V_26 -> V_46 ) ;
F_74 ( & V_26 -> V_61 ) ;
F_12 ( & V_26 -> V_27 ) ;
V_26 -> V_65 = V_88 ;
V_26 -> V_28 = V_29 ;
V_26 -> V_67 = V_67 ;
* V_84 = V_26 ;
return 0 ;
F_60:
F_60 ( V_67 ) ;
return error ;
}
static struct V_14 * F_75 ( struct V_25 * V_26 , struct V_1 * V_1 , int V_7 )
{
int V_89 ;
struct V_69 * V_70 ;
struct V_14 * V_18 , * V_90 = NULL ;
struct V_5 V_6 ;
F_2 ( & V_6 , V_1 , V_7 ) ;
for ( V_70 = V_26 -> V_65 . V_69 ; V_70 ; ) {
V_18 = F_58 ( V_70 , struct V_14 , V_64 ) ;
V_89 = F_3 ( & V_6 , & V_18 -> V_6 ) ;
if ( V_89 > 0 )
V_70 = V_70 -> V_91 ;
else if ( V_89 < 0 )
V_70 = V_70 -> V_92 ;
else {
V_90 = V_18 ;
break;
}
}
return V_90 ;
}
static int F_76 ( T_1 * V_13 , unsigned V_93 , int V_94 , void * V_95 )
{
int V_55 = 0 ;
unsigned long V_35 ;
struct V_14 * V_18 = F_8 ( V_13 ) ;
struct V_25 * V_26 = V_18 -> V_26 ;
if ( ( unsigned long ) V_95 & V_96 ) {
F_6 ( V_13 ) -> V_51 = NULL ;
F_50 ( & V_13 -> V_97 ) ;
}
F_17 ( & V_26 -> V_24 , V_35 ) ;
if ( ! ( V_18 -> V_77 . V_43 & ~ V_98 ) )
goto V_40;
if ( V_95 && ! ( ( unsigned long ) V_95 & V_18 -> V_77 . V_43 ) )
goto V_40;
if ( F_72 ( V_26 -> V_28 != V_29 ) ) {
if ( V_18 -> V_59 == V_29 ) {
V_18 -> V_59 = V_26 -> V_28 ;
V_26 -> V_28 = V_18 ;
}
goto V_40;
}
if ( ! F_4 ( & V_18 -> V_60 ) )
F_43 ( & V_18 -> V_60 , & V_26 -> V_27 ) ;
if ( F_45 ( & V_26 -> V_46 ) )
F_46 ( & V_26 -> V_46 ) ;
if ( F_45 ( & V_26 -> V_61 ) )
V_55 ++ ;
V_40:
F_20 ( & V_26 -> V_24 , V_35 ) ;
if ( V_55 )
F_27 ( & V_26 -> V_61 ) ;
return 1 ;
}
static void F_77 ( struct V_1 * V_1 , T_3 * V_51 ,
T_2 * V_17 )
{
struct V_14 * V_18 = F_9 ( V_17 ) ;
struct V_12 * V_50 ;
if ( V_18 -> V_99 >= 0 && ( V_50 = F_78 ( V_53 , V_87 ) ) ) {
F_79 ( & V_50 -> V_13 , F_76 ) ;
V_50 -> V_51 = V_51 ;
V_50 -> V_15 = V_18 ;
F_80 ( V_51 , & V_50 -> V_13 ) ;
F_43 ( & V_50 -> V_41 , & V_18 -> V_52 ) ;
V_18 -> V_99 ++ ;
} else {
V_18 -> V_99 = - 1 ;
}
}
static void F_81 ( struct V_25 * V_26 , struct V_14 * V_18 )
{
int V_89 ;
struct V_69 * * V_11 = & V_26 -> V_65 . V_69 , * V_100 = NULL ;
struct V_14 * V_101 ;
while ( * V_11 ) {
V_100 = * V_11 ;
V_101 = F_58 ( V_100 , struct V_14 , V_64 ) ;
V_89 = F_3 ( & V_18 -> V_6 , & V_101 -> V_6 ) ;
if ( V_89 > 0 )
V_11 = & V_100 -> V_91 ;
else
V_11 = & V_100 -> V_92 ;
}
F_82 ( & V_18 -> V_64 , V_100 , V_11 ) ;
F_83 ( & V_18 -> V_64 , & V_26 -> V_65 ) ;
}
static int F_84 ( int V_102 )
{
if ( V_102 == 0 )
return 0 ;
if ( ++ V_103 [ V_102 ] > V_104 [ V_102 ] )
return - 1 ;
return 0 ;
}
static void F_85 ( void )
{
int V_105 ;
for ( V_105 = 0 ; V_105 < V_106 ; V_105 ++ )
V_103 [ V_105 ] = 0 ;
}
static int F_86 ( void * V_31 , void * V_32 , int V_34 )
{
int error = 0 ;
struct V_1 * V_1 = V_31 ;
struct V_1 * V_107 ;
struct V_14 * V_18 ;
F_18 (epi, &file->f_ep_links, fllink) {
V_107 = V_18 -> V_26 -> V_1 ;
if ( F_1 ( V_107 ) ) {
if ( F_5 ( & V_107 -> V_83 ) ) {
if ( F_84 ( V_34 ) ) {
error = - 1 ;
break;
}
} else {
error = F_15 ( & V_108 ,
V_49 ,
F_86 ,
V_107 , V_107 ,
V_82 ) ;
}
if ( error != 0 )
break;
} else {
F_87 ( V_109 L_1
L_2 ) ;
}
}
return error ;
}
static int F_88 ( void )
{
int error = 0 ;
struct V_1 * V_110 ;
F_18 (current_file, &tfile_check_list, f_tfile_llink) {
F_85 () ;
error = F_15 ( & V_108 , V_49 ,
F_86 , V_110 ,
V_110 , V_82 ) ;
if ( error )
break;
}
return error ;
}
static int F_89 ( struct V_25 * V_26 , struct V_111 * V_77 ,
struct V_1 * V_112 , int V_7 )
{
int error , V_113 , V_55 = 0 ;
unsigned long V_35 ;
long V_114 ;
struct V_14 * V_18 ;
struct V_16 V_115 ;
V_114 = F_90 ( & V_26 -> V_67 -> V_68 ) ;
if ( F_72 ( V_114 >= V_116 ) )
return - V_117 ;
if ( ! ( V_18 = F_78 ( V_66 , V_87 ) ) )
return - V_86 ;
F_12 ( & V_18 -> V_60 ) ;
F_12 ( & V_18 -> V_63 ) ;
F_12 ( & V_18 -> V_52 ) ;
V_18 -> V_26 = V_26 ;
F_2 ( & V_18 -> V_6 , V_112 , V_7 ) ;
V_18 -> V_77 = * V_77 ;
V_18 -> V_99 = 0 ;
V_18 -> V_59 = V_29 ;
V_115 . V_18 = V_18 ;
F_64 ( & V_115 . V_17 , F_77 ) ;
V_115 . V_17 . V_76 = V_77 -> V_43 ;
V_113 = V_112 -> V_3 -> V_78 ( V_112 , & V_115 . V_17 ) ;
error = - V_86 ;
if ( V_18 -> V_99 < 0 )
goto V_118;
F_49 ( & V_112 -> V_62 ) ;
F_43 ( & V_18 -> V_63 , & V_112 -> V_83 ) ;
F_51 ( & V_112 -> V_62 ) ;
F_81 ( V_26 , V_18 ) ;
error = - V_119 ;
if ( F_88 () )
goto V_120;
F_17 ( & V_26 -> V_24 , V_35 ) ;
if ( ( V_113 & V_77 -> V_43 ) && ! F_4 ( & V_18 -> V_60 ) ) {
F_43 ( & V_18 -> V_60 , & V_26 -> V_27 ) ;
if ( F_45 ( & V_26 -> V_46 ) )
F_46 ( & V_26 -> V_46 ) ;
if ( F_45 ( & V_26 -> V_61 ) )
V_55 ++ ;
}
F_20 ( & V_26 -> V_24 , V_35 ) ;
F_91 ( & V_26 -> V_67 -> V_68 ) ;
if ( V_55 )
F_27 ( & V_26 -> V_61 ) ;
return 0 ;
V_120:
F_49 ( & V_112 -> V_62 ) ;
if ( F_4 ( & V_18 -> V_63 ) )
F_50 ( & V_18 -> V_63 ) ;
F_51 ( & V_112 -> V_62 ) ;
F_52 ( & V_18 -> V_64 , & V_26 -> V_65 ) ;
V_118:
F_35 ( V_26 , V_18 ) ;
F_17 ( & V_26 -> V_24 , V_35 ) ;
if ( F_4 ( & V_18 -> V_60 ) )
F_50 ( & V_18 -> V_60 ) ;
F_20 ( & V_26 -> V_24 , V_35 ) ;
F_37 ( V_66 , V_18 ) ;
return error ;
}
static int F_92 ( struct V_25 * V_26 , struct V_14 * V_18 , struct V_111 * V_77 )
{
int V_55 = 0 ;
unsigned int V_113 ;
T_2 V_17 ;
F_64 ( & V_17 , NULL ) ;
V_18 -> V_77 . V_43 = V_77 -> V_43 ;
V_17 . V_76 = V_77 -> V_43 ;
V_18 -> V_77 . V_121 = V_77 -> V_121 ;
V_113 = V_18 -> V_6 . V_1 -> V_3 -> V_78 ( V_18 -> V_6 . V_1 , & V_17 ) ;
if ( V_113 & V_77 -> V_43 ) {
F_93 ( & V_26 -> V_24 ) ;
if ( ! F_4 ( & V_18 -> V_60 ) ) {
F_43 ( & V_18 -> V_60 , & V_26 -> V_27 ) ;
if ( F_45 ( & V_26 -> V_46 ) )
F_46 ( & V_26 -> V_46 ) ;
if ( F_45 ( & V_26 -> V_61 ) )
V_55 ++ ;
}
F_94 ( & V_26 -> V_24 ) ;
}
if ( V_55 )
F_27 ( & V_26 -> V_61 ) ;
return 0 ;
}
static int F_95 ( struct V_25 * V_26 , struct V_10 * V_74 ,
void * V_31 )
{
struct V_122 * V_123 = V_31 ;
int V_124 ;
unsigned int V_113 ;
struct V_14 * V_18 ;
struct V_111 T_4 * V_125 ;
T_2 V_17 ;
F_64 ( & V_17 , NULL ) ;
for ( V_124 = 0 , V_125 = V_123 -> V_43 ;
! F_5 ( V_74 ) && V_124 < V_123 -> V_126 ; ) {
V_18 = F_36 ( V_74 , struct V_14 , V_60 ) ;
F_50 ( & V_18 -> V_60 ) ;
V_17 . V_76 = V_18 -> V_77 . V_43 ;
V_113 = V_18 -> V_6 . V_1 -> V_3 -> V_78 ( V_18 -> V_6 . V_1 , & V_17 ) &
V_18 -> V_77 . V_43 ;
if ( V_113 ) {
if ( F_96 ( V_113 , & V_125 -> V_43 ) ||
F_96 ( V_18 -> V_77 . V_121 , & V_125 -> V_121 ) ) {
F_19 ( & V_18 -> V_60 , V_74 ) ;
return V_124 ? V_124 : - V_127 ;
}
V_124 ++ ;
V_125 ++ ;
if ( V_18 -> V_77 . V_43 & V_128 )
V_18 -> V_77 . V_43 &= V_98 ;
else if ( ! ( V_18 -> V_77 . V_43 & V_129 ) ) {
F_43 ( & V_18 -> V_60 , & V_26 -> V_27 ) ;
}
}
}
return V_124 ;
}
static int F_97 ( struct V_25 * V_26 ,
struct V_111 T_4 * V_43 , int V_126 )
{
struct V_122 V_123 ;
V_123 . V_126 = V_126 ;
V_123 . V_43 = V_43 ;
return F_38 ( V_26 , F_95 , & V_123 , 0 ) ;
}
static inline struct V_130 F_98 ( long V_131 )
{
struct V_130 V_132 , V_133 = {
. V_134 = V_131 / V_135 ,
. V_136 = V_137 * ( V_131 % V_135 ) ,
} ;
F_99 ( & V_132 ) ;
return F_100 ( V_132 , V_133 ) ;
}
static int F_101 ( struct V_25 * V_26 , struct V_111 T_4 * V_43 ,
int V_126 , long V_138 )
{
int V_139 = 0 , V_140 , V_141 = 0 ;
unsigned long V_35 ;
long V_142 = 0 ;
T_1 V_13 ;
T_5 V_143 , * V_144 = NULL ;
if ( V_138 > 0 ) {
struct V_130 V_145 = F_98 ( V_138 ) ;
V_142 = F_102 ( & V_145 ) ;
V_144 = & V_143 ;
* V_144 = F_103 ( V_145 ) ;
} else if ( V_138 == 0 ) {
V_141 = 1 ;
F_17 ( & V_26 -> V_24 , V_35 ) ;
goto V_146;
}
V_147:
F_17 ( & V_26 -> V_24 , V_35 ) ;
if ( ! F_14 ( V_26 ) ) {
F_104 ( & V_13 , V_82 ) ;
F_105 ( & V_26 -> V_46 , & V_13 ) ;
for (; ; ) {
F_106 ( V_148 ) ;
if ( F_14 ( V_26 ) || V_141 )
break;
if ( F_107 ( V_82 ) ) {
V_139 = - V_149 ;
break;
}
F_20 ( & V_26 -> V_24 , V_35 ) ;
if ( ! F_108 ( V_144 , V_142 , V_150 ) )
V_141 = 1 ;
F_17 ( & V_26 -> V_24 , V_35 ) ;
}
F_109 ( & V_26 -> V_46 , & V_13 ) ;
F_106 ( V_151 ) ;
}
V_146:
V_140 = F_14 ( V_26 ) ;
F_20 ( & V_26 -> V_24 , V_35 ) ;
if ( ! V_139 && V_140 &&
! ( V_139 = F_97 ( V_26 , V_43 , V_126 ) ) && ! V_141 )
goto V_147;
return V_139 ;
}
static int F_110 ( void * V_31 , void * V_32 , int V_34 )
{
int error = 0 ;
struct V_1 * V_1 = V_31 ;
struct V_25 * V_26 = V_1 -> V_73 ;
struct V_25 * V_152 ;
struct V_69 * V_70 ;
struct V_14 * V_18 ;
F_41 ( & V_26 -> V_58 , V_34 + 1 ) ;
V_26 -> V_153 = 1 ;
F_19 ( & V_26 -> V_154 , & V_155 ) ;
for ( V_70 = F_56 ( & V_26 -> V_65 ) ; V_70 ; V_70 = F_57 ( V_70 ) ) {
V_18 = F_58 ( V_70 , struct V_14 , V_64 ) ;
if ( F_72 ( F_1 ( V_18 -> V_6 . V_1 ) ) ) {
V_152 = V_18 -> V_6 . V_1 -> V_73 ;
if ( V_152 -> V_153 )
continue;
error = F_15 ( & V_108 , V_49 ,
F_110 , V_18 -> V_6 . V_1 ,
V_152 , V_82 ) ;
if ( error != 0 )
break;
} else {
if ( F_5 ( & V_18 -> V_6 . V_1 -> V_156 ) )
F_19 ( & V_18 -> V_6 . V_1 -> V_156 ,
& V_157 ) ;
}
}
F_47 ( & V_26 -> V_58 ) ;
return error ;
}
static int F_111 ( struct V_25 * V_26 , struct V_1 * V_1 )
{
int V_158 ;
struct V_25 * V_159 , * V_160 ;
V_158 = F_15 ( & V_108 , V_49 ,
F_110 , V_1 , V_26 , V_82 ) ;
F_65 (ep_cur, ep_next, &visited_list,
visited_list_link) {
V_159 -> V_153 = 0 ;
F_21 ( & V_159 -> V_154 ) ;
}
return V_158 ;
}
static void F_112 ( void )
{
struct V_1 * V_1 ;
while ( ! F_5 ( & V_157 ) ) {
V_1 = F_36 ( & V_157 , struct V_1 ,
V_156 ) ;
F_50 ( & V_1 -> V_156 ) ;
}
F_12 ( & V_157 ) ;
}
static int T_6 F_113 ( void )
{
struct V_161 V_162 ;
F_114 ( & V_162 ) ;
V_116 = ( ( ( V_162 . V_163 - V_162 . V_164 ) / 25 ) << V_165 ) /
V_166 ;
F_115 ( V_116 < 0 ) ;
F_11 ( & V_108 ) ;
F_11 ( & V_48 ) ;
F_11 ( & V_81 ) ;
V_66 = F_116 ( L_3 , sizeof( struct V_14 ) ,
0 , V_167 | V_168 , NULL ) ;
V_53 = F_116 ( L_4 ,
sizeof( struct V_12 ) , 0 , V_168 , NULL ) ;
return 0 ;
}
