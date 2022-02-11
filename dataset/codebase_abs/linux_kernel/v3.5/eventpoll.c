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
if ( ! F_4 ( & V_18 -> V_60 ) ) {
F_43 ( & V_18 -> V_60 , & V_26 -> V_27 ) ;
F_44 ( V_18 -> V_61 ) ;
}
}
V_26 -> V_28 = V_29 ;
F_45 ( & V_57 , & V_26 -> V_27 ) ;
F_46 ( V_26 -> V_61 ) ;
if ( ! F_5 ( & V_26 -> V_27 ) ) {
if ( F_47 ( & V_26 -> V_46 ) )
F_48 ( & V_26 -> V_46 ) ;
if ( F_47 ( & V_26 -> V_62 ) )
V_55 ++ ;
}
F_20 ( & V_26 -> V_24 , V_35 ) ;
F_49 ( & V_26 -> V_58 ) ;
if ( V_55 )
F_27 ( & V_26 -> V_62 ) ;
return error ;
}
static int F_50 ( struct V_25 * V_26 , struct V_14 * V_18 )
{
unsigned long V_35 ;
struct V_1 * V_1 = V_18 -> V_6 . V_1 ;
F_35 ( V_26 , V_18 ) ;
F_51 ( & V_1 -> V_63 ) ;
if ( F_4 ( & V_18 -> V_64 ) )
F_52 ( & V_18 -> V_64 ) ;
F_53 ( & V_1 -> V_63 ) ;
F_54 ( & V_18 -> V_65 , & V_26 -> V_66 ) ;
F_17 ( & V_26 -> V_24 , V_35 ) ;
if ( F_4 ( & V_18 -> V_60 ) )
F_52 ( & V_18 -> V_60 ) ;
F_20 ( & V_26 -> V_24 , V_35 ) ;
F_55 ( V_18 -> V_61 ) ;
F_37 ( V_67 , V_18 ) ;
F_56 ( & V_26 -> V_68 -> V_69 ) ;
return 0 ;
}
static void F_57 ( struct V_25 * V_26 )
{
struct V_70 * V_71 ;
struct V_14 * V_18 ;
if ( F_47 ( & V_26 -> V_62 ) )
F_27 ( & V_26 -> V_62 ) ;
F_58 ( & V_72 ) ;
for ( V_71 = F_59 ( & V_26 -> V_66 ) ; V_71 ; V_71 = F_60 ( V_71 ) ) {
V_18 = F_61 ( V_71 , struct V_14 , V_65 ) ;
F_35 ( V_26 , V_18 ) ;
}
while ( ( V_71 = F_59 ( & V_26 -> V_66 ) ) != NULL ) {
V_18 = F_61 ( V_71 , struct V_14 , V_65 ) ;
F_50 ( V_26 , V_18 ) ;
}
F_49 ( & V_72 ) ;
F_62 ( & V_26 -> V_58 ) ;
F_63 ( V_26 -> V_68 ) ;
F_55 ( V_26 -> V_61 ) ;
F_64 ( V_26 ) ;
}
static int F_65 ( struct V_73 * V_73 , struct V_1 * V_1 )
{
struct V_25 * V_26 = V_1 -> V_74 ;
if ( V_26 )
F_57 ( V_26 ) ;
return 0 ;
}
static int F_66 ( struct V_25 * V_26 , struct V_10 * V_75 ,
void * V_31 )
{
struct V_14 * V_18 , * V_76 ;
T_2 V_17 ;
F_67 ( & V_17 , NULL ) ;
F_68 (epi, tmp, head, rdllink) {
V_17 . V_77 = V_18 -> V_78 . V_43 ;
if ( V_18 -> V_6 . V_1 -> V_3 -> V_79 ( V_18 -> V_6 . V_1 , & V_17 ) &
V_18 -> V_78 . V_43 )
return V_45 | V_80 ;
else {
F_46 ( V_18 -> V_61 ) ;
F_52 ( & V_18 -> V_60 ) ;
}
}
return 0 ;
}
static int F_69 ( void * V_31 , void * V_32 , int V_34 )
{
return F_38 ( V_31 , F_66 , NULL , V_34 + 1 ) ;
}
static unsigned int F_70 ( struct V_1 * V_1 , T_2 * V_13 )
{
int V_81 ;
struct V_25 * V_26 = V_1 -> V_74 ;
V_62 ( V_1 , & V_26 -> V_62 , V_13 ) ;
V_81 = F_15 ( & V_82 , V_49 ,
F_69 , V_26 , V_26 , V_83 ) ;
return V_81 != - 1 ? V_81 : 0 ;
}
void F_71 ( struct V_1 * V_1 )
{
struct V_10 * V_36 = & V_1 -> V_84 ;
struct V_25 * V_26 ;
struct V_14 * V_18 ;
F_58 ( & V_72 ) ;
while ( ! F_5 ( V_36 ) ) {
V_18 = F_36 ( V_36 , struct V_14 , V_64 ) ;
V_26 = V_18 -> V_26 ;
F_52 ( & V_18 -> V_64 ) ;
F_41 ( & V_26 -> V_58 , 0 ) ;
F_50 ( V_26 , V_18 ) ;
F_49 ( & V_26 -> V_58 ) ;
}
F_49 ( & V_72 ) ;
}
static int F_72 ( struct V_25 * * V_85 )
{
int error ;
struct V_86 * V_68 ;
struct V_25 * V_26 ;
V_68 = F_73 () ;
error = - V_87 ;
V_26 = F_74 ( sizeof( * V_26 ) , V_88 ) ;
if ( F_75 ( ! V_26 ) )
goto F_63;
F_13 ( & V_26 -> V_24 ) ;
F_76 ( & V_26 -> V_58 ) ;
F_77 ( & V_26 -> V_46 ) ;
F_77 ( & V_26 -> V_62 ) ;
F_12 ( & V_26 -> V_27 ) ;
V_26 -> V_66 = V_89 ;
V_26 -> V_28 = V_29 ;
V_26 -> V_68 = V_68 ;
* V_85 = V_26 ;
return 0 ;
F_63:
F_63 ( V_68 ) ;
return error ;
}
static struct V_14 * F_78 ( struct V_25 * V_26 , struct V_1 * V_1 , int V_7 )
{
int V_90 ;
struct V_70 * V_71 ;
struct V_14 * V_18 , * V_91 = NULL ;
struct V_5 V_6 ;
F_2 ( & V_6 , V_1 , V_7 ) ;
for ( V_71 = V_26 -> V_66 . V_70 ; V_71 ; ) {
V_18 = F_61 ( V_71 , struct V_14 , V_65 ) ;
V_90 = F_3 ( & V_6 , & V_18 -> V_6 ) ;
if ( V_90 > 0 )
V_71 = V_71 -> V_92 ;
else if ( V_90 < 0 )
V_71 = V_71 -> V_93 ;
else {
V_91 = V_18 ;
break;
}
}
return V_91 ;
}
static int F_79 ( T_1 * V_13 , unsigned V_94 , int V_95 , void * V_96 )
{
int V_55 = 0 ;
unsigned long V_35 ;
struct V_14 * V_18 = F_8 ( V_13 ) ;
struct V_25 * V_26 = V_18 -> V_26 ;
if ( ( unsigned long ) V_96 & V_97 ) {
F_6 ( V_13 ) -> V_51 = NULL ;
F_52 ( & V_13 -> V_98 ) ;
}
F_17 ( & V_26 -> V_24 , V_35 ) ;
if ( ! ( V_18 -> V_78 . V_43 & ~ V_99 ) )
goto V_40;
if ( V_96 && ! ( ( unsigned long ) V_96 & V_18 -> V_78 . V_43 ) )
goto V_40;
if ( F_75 ( V_26 -> V_28 != V_29 ) ) {
if ( V_18 -> V_59 == V_29 ) {
V_18 -> V_59 = V_26 -> V_28 ;
V_26 -> V_28 = V_18 ;
if ( V_18 -> V_61 ) {
F_44 ( V_26 -> V_61 ) ;
}
}
goto V_40;
}
if ( ! F_4 ( & V_18 -> V_60 ) ) {
F_43 ( & V_18 -> V_60 , & V_26 -> V_27 ) ;
F_44 ( V_18 -> V_61 ) ;
}
if ( F_47 ( & V_26 -> V_46 ) )
F_48 ( & V_26 -> V_46 ) ;
if ( F_47 ( & V_26 -> V_62 ) )
V_55 ++ ;
V_40:
F_20 ( & V_26 -> V_24 , V_35 ) ;
if ( V_55 )
F_27 ( & V_26 -> V_62 ) ;
return 1 ;
}
static void F_80 ( struct V_1 * V_1 , T_3 * V_51 ,
T_2 * V_17 )
{
struct V_14 * V_18 = F_9 ( V_17 ) ;
struct V_12 * V_50 ;
if ( V_18 -> V_100 >= 0 && ( V_50 = F_81 ( V_53 , V_88 ) ) ) {
F_82 ( & V_50 -> V_13 , F_79 ) ;
V_50 -> V_51 = V_51 ;
V_50 -> V_15 = V_18 ;
F_83 ( V_51 , & V_50 -> V_13 ) ;
F_43 ( & V_50 -> V_41 , & V_18 -> V_52 ) ;
V_18 -> V_100 ++ ;
} else {
V_18 -> V_100 = - 1 ;
}
}
static void F_84 ( struct V_25 * V_26 , struct V_14 * V_18 )
{
int V_90 ;
struct V_70 * * V_11 = & V_26 -> V_66 . V_70 , * V_101 = NULL ;
struct V_14 * V_102 ;
while ( * V_11 ) {
V_101 = * V_11 ;
V_102 = F_61 ( V_101 , struct V_14 , V_65 ) ;
V_90 = F_3 ( & V_18 -> V_6 , & V_102 -> V_6 ) ;
if ( V_90 > 0 )
V_11 = & V_101 -> V_92 ;
else
V_11 = & V_101 -> V_93 ;
}
F_85 ( & V_18 -> V_65 , V_101 , V_11 ) ;
F_86 ( & V_18 -> V_65 , & V_26 -> V_66 ) ;
}
static int F_87 ( int V_103 )
{
if ( V_103 == 0 )
return 0 ;
if ( ++ V_104 [ V_103 ] > V_105 [ V_103 ] )
return - 1 ;
return 0 ;
}
static void F_88 ( void )
{
int V_106 ;
for ( V_106 = 0 ; V_106 < V_107 ; V_106 ++ )
V_104 [ V_106 ] = 0 ;
}
static int F_89 ( void * V_31 , void * V_32 , int V_34 )
{
int error = 0 ;
struct V_1 * V_1 = V_31 ;
struct V_1 * V_108 ;
struct V_14 * V_18 ;
F_18 (epi, &file->f_ep_links, fllink) {
V_108 = V_18 -> V_26 -> V_1 ;
if ( F_1 ( V_108 ) ) {
if ( F_5 ( & V_108 -> V_84 ) ) {
if ( F_87 ( V_34 ) ) {
error = - 1 ;
break;
}
} else {
error = F_15 ( & V_109 ,
V_49 ,
F_89 ,
V_108 , V_108 ,
V_83 ) ;
}
if ( error != 0 )
break;
} else {
F_90 ( V_110 L_1
L_2 ) ;
}
}
return error ;
}
static int F_91 ( void )
{
int error = 0 ;
struct V_1 * V_111 ;
F_18 (current_file, &tfile_check_list, f_tfile_llink) {
F_88 () ;
error = F_15 ( & V_109 , V_49 ,
F_89 , V_111 ,
V_111 , V_83 ) ;
if ( error )
break;
}
return error ;
}
static int F_92 ( struct V_14 * V_18 )
{
const char * V_112 ;
if ( ! V_18 -> V_26 -> V_61 ) {
V_18 -> V_26 -> V_61 = F_93 ( L_3 ) ;
if ( ! V_18 -> V_26 -> V_61 )
return - V_87 ;
}
V_112 = V_18 -> V_6 . V_1 -> V_113 . V_114 -> V_115 . V_112 ;
V_18 -> V_61 = F_93 ( V_112 ) ;
if ( ! V_18 -> V_61 )
return - V_87 ;
return 0 ;
}
static void F_94 ( struct V_14 * V_18 )
{
F_55 ( V_18 -> V_61 ) ;
V_18 -> V_61 = NULL ;
}
static int F_95 ( struct V_25 * V_26 , struct V_116 * V_78 ,
struct V_1 * V_117 , int V_7 )
{
int error , V_118 , V_55 = 0 ;
unsigned long V_35 ;
long V_119 ;
struct V_14 * V_18 ;
struct V_16 V_120 ;
V_119 = F_96 ( & V_26 -> V_68 -> V_69 ) ;
if ( F_75 ( V_119 >= V_121 ) )
return - V_122 ;
if ( ! ( V_18 = F_81 ( V_67 , V_88 ) ) )
return - V_87 ;
F_12 ( & V_18 -> V_60 ) ;
F_12 ( & V_18 -> V_64 ) ;
F_12 ( & V_18 -> V_52 ) ;
V_18 -> V_26 = V_26 ;
F_2 ( & V_18 -> V_6 , V_117 , V_7 ) ;
V_18 -> V_78 = * V_78 ;
V_18 -> V_100 = 0 ;
V_18 -> V_59 = V_29 ;
if ( V_18 -> V_78 . V_43 & V_123 ) {
error = F_92 ( V_18 ) ;
if ( error )
goto V_124;
} else {
V_18 -> V_61 = NULL ;
}
V_120 . V_18 = V_18 ;
F_67 ( & V_120 . V_17 , F_80 ) ;
V_120 . V_17 . V_77 = V_78 -> V_43 ;
V_118 = V_117 -> V_3 -> V_79 ( V_117 , & V_120 . V_17 ) ;
error = - V_87 ;
if ( V_18 -> V_100 < 0 )
goto V_125;
F_51 ( & V_117 -> V_63 ) ;
F_43 ( & V_18 -> V_64 , & V_117 -> V_84 ) ;
F_53 ( & V_117 -> V_63 ) ;
F_84 ( V_26 , V_18 ) ;
error = - V_126 ;
if ( F_91 () )
goto V_127;
F_17 ( & V_26 -> V_24 , V_35 ) ;
if ( ( V_118 & V_78 -> V_43 ) && ! F_4 ( & V_18 -> V_60 ) ) {
F_43 ( & V_18 -> V_60 , & V_26 -> V_27 ) ;
F_44 ( V_18 -> V_61 ) ;
if ( F_47 ( & V_26 -> V_46 ) )
F_48 ( & V_26 -> V_46 ) ;
if ( F_47 ( & V_26 -> V_62 ) )
V_55 ++ ;
}
F_20 ( & V_26 -> V_24 , V_35 ) ;
F_97 ( & V_26 -> V_68 -> V_69 ) ;
if ( V_55 )
F_27 ( & V_26 -> V_62 ) ;
return 0 ;
V_127:
F_51 ( & V_117 -> V_63 ) ;
if ( F_4 ( & V_18 -> V_64 ) )
F_52 ( & V_18 -> V_64 ) ;
F_53 ( & V_117 -> V_63 ) ;
F_54 ( & V_18 -> V_65 , & V_26 -> V_66 ) ;
V_125:
F_35 ( V_26 , V_18 ) ;
F_17 ( & V_26 -> V_24 , V_35 ) ;
if ( F_4 ( & V_18 -> V_60 ) )
F_52 ( & V_18 -> V_60 ) ;
F_20 ( & V_26 -> V_24 , V_35 ) ;
F_55 ( V_18 -> V_61 ) ;
V_124:
F_37 ( V_67 , V_18 ) ;
return error ;
}
static int F_98 ( struct V_25 * V_26 , struct V_14 * V_18 , struct V_116 * V_78 )
{
int V_55 = 0 ;
unsigned int V_118 ;
T_2 V_17 ;
F_67 ( & V_17 , NULL ) ;
V_18 -> V_78 . V_43 = V_78 -> V_43 ;
V_17 . V_77 = V_78 -> V_43 ;
V_18 -> V_78 . V_128 = V_78 -> V_128 ;
if ( V_18 -> V_78 . V_43 & V_123 ) {
if ( ! V_18 -> V_61 )
F_92 ( V_18 ) ;
} else if ( V_18 -> V_61 ) {
F_94 ( V_18 ) ;
}
V_118 = V_18 -> V_6 . V_1 -> V_3 -> V_79 ( V_18 -> V_6 . V_1 , & V_17 ) ;
if ( V_118 & V_78 -> V_43 ) {
F_99 ( & V_26 -> V_24 ) ;
if ( ! F_4 ( & V_18 -> V_60 ) ) {
F_43 ( & V_18 -> V_60 , & V_26 -> V_27 ) ;
F_44 ( V_18 -> V_61 ) ;
if ( F_47 ( & V_26 -> V_46 ) )
F_48 ( & V_26 -> V_46 ) ;
if ( F_47 ( & V_26 -> V_62 ) )
V_55 ++ ;
}
F_100 ( & V_26 -> V_24 ) ;
}
if ( V_55 )
F_27 ( & V_26 -> V_62 ) ;
return 0 ;
}
static int F_101 ( struct V_25 * V_26 , struct V_10 * V_75 ,
void * V_31 )
{
struct V_129 * V_130 = V_31 ;
int V_131 ;
unsigned int V_118 ;
struct V_14 * V_18 ;
struct V_116 T_4 * V_132 ;
T_2 V_17 ;
F_67 ( & V_17 , NULL ) ;
for ( V_131 = 0 , V_132 = V_130 -> V_43 ;
! F_5 ( V_75 ) && V_131 < V_130 -> V_133 ; ) {
V_18 = F_36 ( V_75 , struct V_14 , V_60 ) ;
if ( V_18 -> V_61 && V_18 -> V_61 -> V_134 )
F_44 ( V_26 -> V_61 ) ;
F_46 ( V_18 -> V_61 ) ;
F_52 ( & V_18 -> V_60 ) ;
V_17 . V_77 = V_18 -> V_78 . V_43 ;
V_118 = V_18 -> V_6 . V_1 -> V_3 -> V_79 ( V_18 -> V_6 . V_1 , & V_17 ) &
V_18 -> V_78 . V_43 ;
if ( V_118 ) {
if ( F_102 ( V_118 , & V_132 -> V_43 ) ||
F_102 ( V_18 -> V_78 . V_128 , & V_132 -> V_128 ) ) {
F_19 ( & V_18 -> V_60 , V_75 ) ;
F_44 ( V_18 -> V_61 ) ;
return V_131 ? V_131 : - V_135 ;
}
V_131 ++ ;
V_132 ++ ;
if ( V_18 -> V_78 . V_43 & V_136 )
V_18 -> V_78 . V_43 &= V_99 ;
else if ( ! ( V_18 -> V_78 . V_43 & V_137 ) ) {
F_43 ( & V_18 -> V_60 , & V_26 -> V_27 ) ;
F_44 ( V_18 -> V_61 ) ;
}
}
}
return V_131 ;
}
static int F_103 ( struct V_25 * V_26 ,
struct V_116 T_4 * V_43 , int V_133 )
{
struct V_129 V_130 ;
V_130 . V_133 = V_133 ;
V_130 . V_43 = V_43 ;
return F_38 ( V_26 , F_101 , & V_130 , 0 ) ;
}
static inline struct V_138 F_104 ( long V_139 )
{
struct V_138 V_140 , V_141 = {
. V_142 = V_139 / V_143 ,
. V_144 = V_145 * ( V_139 % V_143 ) ,
} ;
F_105 ( & V_140 ) ;
return F_106 ( V_140 , V_141 ) ;
}
static int F_107 ( struct V_25 * V_26 , struct V_116 T_4 * V_43 ,
int V_133 , long V_146 )
{
int V_147 = 0 , V_148 , V_149 = 0 ;
unsigned long V_35 ;
long V_150 = 0 ;
T_1 V_13 ;
T_5 V_151 , * V_152 = NULL ;
if ( V_146 > 0 ) {
struct V_138 V_153 = F_104 ( V_146 ) ;
V_150 = F_108 ( & V_153 ) ;
V_152 = & V_151 ;
* V_152 = F_109 ( V_153 ) ;
} else if ( V_146 == 0 ) {
V_149 = 1 ;
F_17 ( & V_26 -> V_24 , V_35 ) ;
goto V_154;
}
V_155:
F_17 ( & V_26 -> V_24 , V_35 ) ;
if ( ! F_14 ( V_26 ) ) {
F_110 ( & V_13 , V_83 ) ;
F_111 ( & V_26 -> V_46 , & V_13 ) ;
for (; ; ) {
F_112 ( V_156 ) ;
if ( F_14 ( V_26 ) || V_149 )
break;
if ( F_113 ( V_83 ) ) {
V_147 = - V_157 ;
break;
}
F_20 ( & V_26 -> V_24 , V_35 ) ;
if ( ! F_114 ( V_152 , V_150 , V_158 ) )
V_149 = 1 ;
F_17 ( & V_26 -> V_24 , V_35 ) ;
}
F_115 ( & V_26 -> V_46 , & V_13 ) ;
F_112 ( V_159 ) ;
}
V_154:
V_148 = F_14 ( V_26 ) ;
F_20 ( & V_26 -> V_24 , V_35 ) ;
if ( ! V_147 && V_148 &&
! ( V_147 = F_103 ( V_26 , V_43 , V_133 ) ) && ! V_149 )
goto V_155;
return V_147 ;
}
static int F_116 ( void * V_31 , void * V_32 , int V_34 )
{
int error = 0 ;
struct V_1 * V_1 = V_31 ;
struct V_25 * V_26 = V_1 -> V_74 ;
struct V_25 * V_160 ;
struct V_70 * V_71 ;
struct V_14 * V_18 ;
F_41 ( & V_26 -> V_58 , V_34 + 1 ) ;
V_26 -> V_161 = 1 ;
F_19 ( & V_26 -> V_162 , & V_163 ) ;
for ( V_71 = F_59 ( & V_26 -> V_66 ) ; V_71 ; V_71 = F_60 ( V_71 ) ) {
V_18 = F_61 ( V_71 , struct V_14 , V_65 ) ;
if ( F_75 ( F_1 ( V_18 -> V_6 . V_1 ) ) ) {
V_160 = V_18 -> V_6 . V_1 -> V_74 ;
if ( V_160 -> V_161 )
continue;
error = F_15 ( & V_109 , V_49 ,
F_116 , V_18 -> V_6 . V_1 ,
V_160 , V_83 ) ;
if ( error != 0 )
break;
} else {
if ( F_5 ( & V_18 -> V_6 . V_1 -> V_164 ) )
F_19 ( & V_18 -> V_6 . V_1 -> V_164 ,
& V_165 ) ;
}
}
F_49 ( & V_26 -> V_58 ) ;
return error ;
}
static int F_117 ( struct V_25 * V_26 , struct V_1 * V_1 )
{
int V_166 ;
struct V_25 * V_167 , * V_168 ;
V_166 = F_15 ( & V_109 , V_49 ,
F_116 , V_1 , V_26 , V_83 ) ;
F_68 (ep_cur, ep_next, &visited_list,
visited_list_link) {
V_167 -> V_161 = 0 ;
F_21 ( & V_167 -> V_162 ) ;
}
return V_166 ;
}
static void F_118 ( void )
{
struct V_1 * V_1 ;
while ( ! F_5 ( & V_165 ) ) {
V_1 = F_36 ( & V_165 , struct V_1 ,
V_164 ) ;
F_52 ( & V_1 -> V_164 ) ;
}
F_12 ( & V_165 ) ;
}
static int T_6 F_119 ( void )
{
struct V_169 V_170 ;
F_120 ( & V_170 ) ;
V_121 = ( ( ( V_170 . V_171 - V_170 . V_172 ) / 25 ) << V_173 ) /
V_174 ;
F_121 ( V_121 < 0 ) ;
F_11 ( & V_109 ) ;
F_11 ( & V_48 ) ;
F_11 ( & V_82 ) ;
V_67 = F_122 ( L_4 , sizeof( struct V_14 ) ,
0 , V_175 | V_176 , NULL ) ;
V_53 = F_122 ( L_5 ,
sizeof( struct V_12 ) , 0 , V_176 , NULL ) ;
return 0 ;
}
