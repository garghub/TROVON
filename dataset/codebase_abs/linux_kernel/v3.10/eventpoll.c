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
void * V_31 ,
int V_57 )
{
int error , V_58 = 0 ;
unsigned long V_35 ;
struct V_14 * V_18 , * V_59 ;
F_48 ( V_60 ) ;
F_49 ( & V_26 -> V_56 , V_57 ) ;
F_17 ( & V_26 -> V_24 , V_35 ) ;
F_50 ( & V_26 -> V_27 , & V_60 ) ;
V_26 -> V_28 = NULL ;
F_20 ( & V_26 -> V_24 , V_35 ) ;
error = (* F_47)( V_26 , & V_60 , V_31 ) ;
F_17 ( & V_26 -> V_24 , V_35 ) ;
for ( V_59 = V_26 -> V_28 ; ( V_18 = V_59 ) != NULL ;
V_59 = V_18 -> V_61 , V_18 -> V_61 = V_29 ) {
if ( ! F_4 ( & V_18 -> V_62 ) ) {
F_51 ( & V_18 -> V_62 , & V_26 -> V_27 ) ;
F_41 ( V_18 ) ;
}
}
V_26 -> V_28 = V_29 ;
F_52 ( & V_60 , & V_26 -> V_27 ) ;
F_53 ( V_26 -> V_55 ) ;
if ( ! F_5 ( & V_26 -> V_27 ) ) {
if ( F_54 ( & V_26 -> V_46 ) )
F_55 ( & V_26 -> V_46 ) ;
if ( F_54 ( & V_26 -> V_63 ) )
V_58 ++ ;
}
F_20 ( & V_26 -> V_24 , V_35 ) ;
F_56 ( & V_26 -> V_56 ) ;
if ( V_58 )
F_27 ( & V_26 -> V_63 ) ;
return error ;
}
static int F_57 ( struct V_25 * V_26 , struct V_14 * V_18 )
{
unsigned long V_35 ;
struct V_1 * V_1 = V_18 -> V_6 . V_1 ;
F_35 ( V_26 , V_18 ) ;
F_58 ( & V_1 -> V_64 ) ;
if ( F_4 ( & V_18 -> V_65 ) )
F_59 ( & V_18 -> V_65 ) ;
F_60 ( & V_1 -> V_64 ) ;
F_61 ( & V_18 -> V_66 , & V_26 -> V_67 ) ;
F_17 ( & V_26 -> V_24 , V_35 ) ;
if ( F_4 ( & V_18 -> V_62 ) )
F_59 ( & V_18 -> V_62 ) ;
F_20 ( & V_26 -> V_24 , V_35 ) ;
F_62 ( F_38 ( V_18 ) ) ;
F_37 ( V_68 , V_18 ) ;
F_63 ( & V_26 -> V_69 -> V_70 ) ;
return 0 ;
}
static void F_64 ( struct V_25 * V_26 )
{
struct V_71 * V_72 ;
struct V_14 * V_18 ;
if ( F_54 ( & V_26 -> V_63 ) )
F_27 ( & V_26 -> V_63 ) ;
F_65 ( & V_73 ) ;
for ( V_72 = F_66 ( & V_26 -> V_67 ) ; V_72 ; V_72 = F_67 ( V_72 ) ) {
V_18 = F_68 ( V_72 , struct V_14 , V_66 ) ;
F_35 ( V_26 , V_18 ) ;
}
F_65 ( & V_26 -> V_56 ) ;
while ( ( V_72 = F_66 ( & V_26 -> V_67 ) ) != NULL ) {
V_18 = F_68 ( V_72 , struct V_14 , V_66 ) ;
F_57 ( V_26 , V_18 ) ;
}
F_56 ( & V_26 -> V_56 ) ;
F_56 ( & V_73 ) ;
F_69 ( & V_26 -> V_56 ) ;
F_70 ( V_26 -> V_69 ) ;
F_62 ( V_26 -> V_55 ) ;
F_71 ( V_26 ) ;
}
static int F_72 ( struct V_74 * V_74 , struct V_1 * V_1 )
{
struct V_25 * V_26 = V_1 -> V_75 ;
if ( V_26 )
F_64 ( V_26 ) ;
return 0 ;
}
static inline unsigned int F_73 ( struct V_14 * V_18 , T_2 * V_17 )
{
V_17 -> V_76 = V_18 -> V_77 . V_43 ;
return V_18 -> V_6 . V_1 -> V_3 -> V_78 ( V_18 -> V_6 . V_1 , V_17 ) & V_18 -> V_77 . V_43 ;
}
static int F_74 ( struct V_25 * V_26 , struct V_10 * V_79 ,
void * V_31 )
{
struct V_14 * V_18 , * V_80 ;
T_2 V_17 ;
F_75 ( & V_17 , NULL ) ;
F_76 (epi, tmp, head, rdllink) {
if ( F_73 ( V_18 , & V_17 ) )
return V_45 | V_81 ;
else {
F_53 ( F_38 ( V_18 ) ) ;
F_59 ( & V_18 -> V_62 ) ;
}
}
return 0 ;
}
static int F_77 ( void * V_31 , void * V_32 , int V_34 )
{
return F_46 ( V_31 , F_74 , NULL , V_34 + 1 ) ;
}
static unsigned int F_78 ( struct V_1 * V_1 , T_2 * V_13 )
{
int V_82 ;
struct V_25 * V_26 = V_1 -> V_75 ;
V_63 ( V_1 , & V_26 -> V_63 , V_13 ) ;
V_82 = F_15 ( & V_83 , V_49 ,
F_77 , V_26 , V_26 , V_84 ) ;
return V_82 != - 1 ? V_82 : 0 ;
}
static int F_79 ( struct V_85 * V_86 , struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_75 ;
struct V_71 * V_72 ;
int V_87 = 0 ;
F_65 ( & V_26 -> V_56 ) ;
for ( V_72 = F_66 ( & V_26 -> V_67 ) ; V_72 ; V_72 = F_67 ( V_72 ) ) {
struct V_14 * V_18 = F_68 ( V_72 , struct V_14 , V_66 ) ;
V_87 = F_80 ( V_86 , L_1 ,
V_18 -> V_6 . V_7 , V_18 -> V_77 . V_43 ,
( long long ) V_18 -> V_77 . V_88 ) ;
if ( V_87 )
break;
}
F_56 ( & V_26 -> V_56 ) ;
return V_87 ;
}
void F_81 ( struct V_1 * V_1 )
{
struct V_10 * V_36 = & V_1 -> V_89 ;
struct V_25 * V_26 ;
struct V_14 * V_18 ;
F_65 ( & V_73 ) ;
while ( ! F_5 ( V_36 ) ) {
V_18 = F_36 ( V_36 , struct V_14 , V_65 ) ;
V_26 = V_18 -> V_26 ;
F_59 ( & V_18 -> V_65 ) ;
F_49 ( & V_26 -> V_56 , 0 ) ;
F_57 ( V_26 , V_18 ) ;
F_56 ( & V_26 -> V_56 ) ;
}
F_56 ( & V_73 ) ;
}
static int F_82 ( struct V_25 * * V_90 )
{
int error ;
struct V_91 * V_69 ;
struct V_25 * V_26 ;
V_69 = F_83 () ;
error = - V_92 ;
V_26 = F_84 ( sizeof( * V_26 ) , V_93 ) ;
if ( F_85 ( ! V_26 ) )
goto F_70;
F_13 ( & V_26 -> V_24 ) ;
F_86 ( & V_26 -> V_56 ) ;
F_87 ( & V_26 -> V_46 ) ;
F_87 ( & V_26 -> V_63 ) ;
F_12 ( & V_26 -> V_27 ) ;
V_26 -> V_67 = V_94 ;
V_26 -> V_28 = V_29 ;
V_26 -> V_69 = V_69 ;
* V_90 = V_26 ;
return 0 ;
F_70:
F_70 ( V_69 ) ;
return error ;
}
static struct V_14 * F_88 ( struct V_25 * V_26 , struct V_1 * V_1 , int V_7 )
{
int V_95 ;
struct V_71 * V_72 ;
struct V_14 * V_18 , * V_96 = NULL ;
struct V_5 V_6 ;
F_2 ( & V_6 , V_1 , V_7 ) ;
for ( V_72 = V_26 -> V_67 . V_71 ; V_72 ; ) {
V_18 = F_68 ( V_72 , struct V_14 , V_66 ) ;
V_95 = F_3 ( & V_6 , & V_18 -> V_6 ) ;
if ( V_95 > 0 )
V_72 = V_72 -> V_97 ;
else if ( V_95 < 0 )
V_72 = V_72 -> V_98 ;
else {
V_96 = V_18 ;
break;
}
}
return V_96 ;
}
static int F_89 ( T_1 * V_13 , unsigned V_99 , int V_100 , void * V_101 )
{
int V_58 = 0 ;
unsigned long V_35 ;
struct V_14 * V_18 = F_8 ( V_13 ) ;
struct V_25 * V_26 = V_18 -> V_26 ;
if ( ( unsigned long ) V_101 & V_102 ) {
F_6 ( V_13 ) -> V_51 = NULL ;
F_59 ( & V_13 -> V_103 ) ;
}
F_17 ( & V_26 -> V_24 , V_35 ) ;
if ( ! ( V_18 -> V_77 . V_43 & ~ V_104 ) )
goto V_40;
if ( V_101 && ! ( ( unsigned long ) V_101 & V_18 -> V_77 . V_43 ) )
goto V_40;
if ( F_85 ( V_26 -> V_28 != V_29 ) ) {
if ( V_18 -> V_61 == V_29 ) {
V_18 -> V_61 = V_26 -> V_28 ;
V_26 -> V_28 = V_18 ;
if ( V_18 -> V_55 ) {
F_42 ( V_26 -> V_55 ) ;
}
}
goto V_40;
}
if ( ! F_4 ( & V_18 -> V_62 ) ) {
F_51 ( & V_18 -> V_62 , & V_26 -> V_27 ) ;
F_45 ( V_18 ) ;
}
if ( F_54 ( & V_26 -> V_46 ) )
F_55 ( & V_26 -> V_46 ) ;
if ( F_54 ( & V_26 -> V_63 ) )
V_58 ++ ;
V_40:
F_20 ( & V_26 -> V_24 , V_35 ) ;
if ( V_58 )
F_27 ( & V_26 -> V_63 ) ;
return 1 ;
}
static void F_90 ( struct V_1 * V_1 , T_3 * V_51 ,
T_2 * V_17 )
{
struct V_14 * V_18 = F_9 ( V_17 ) ;
struct V_12 * V_50 ;
if ( V_18 -> V_105 >= 0 && ( V_50 = F_91 ( V_53 , V_93 ) ) ) {
F_92 ( & V_50 -> V_13 , F_89 ) ;
V_50 -> V_51 = V_51 ;
V_50 -> V_15 = V_18 ;
F_93 ( V_51 , & V_50 -> V_13 ) ;
F_51 ( & V_50 -> V_41 , & V_18 -> V_52 ) ;
V_18 -> V_105 ++ ;
} else {
V_18 -> V_105 = - 1 ;
}
}
static void F_94 ( struct V_25 * V_26 , struct V_14 * V_18 )
{
int V_95 ;
struct V_71 * * V_11 = & V_26 -> V_67 . V_71 , * V_106 = NULL ;
struct V_14 * V_107 ;
while ( * V_11 ) {
V_106 = * V_11 ;
V_107 = F_68 ( V_106 , struct V_14 , V_66 ) ;
V_95 = F_3 ( & V_18 -> V_6 , & V_107 -> V_6 ) ;
if ( V_95 > 0 )
V_11 = & V_106 -> V_97 ;
else
V_11 = & V_106 -> V_98 ;
}
F_95 ( & V_18 -> V_66 , V_106 , V_11 ) ;
F_96 ( & V_18 -> V_66 , & V_26 -> V_67 ) ;
}
static int F_97 ( int V_108 )
{
if ( V_108 == 0 )
return 0 ;
if ( ++ V_109 [ V_108 ] > V_110 [ V_108 ] )
return - 1 ;
return 0 ;
}
static void F_98 ( void )
{
int V_111 ;
for ( V_111 = 0 ; V_111 < V_112 ; V_111 ++ )
V_109 [ V_111 ] = 0 ;
}
static int F_99 ( void * V_31 , void * V_32 , int V_34 )
{
int error = 0 ;
struct V_1 * V_1 = V_31 ;
struct V_1 * V_113 ;
struct V_14 * V_18 ;
F_18 (epi, &file->f_ep_links, fllink) {
V_113 = V_18 -> V_26 -> V_1 ;
if ( F_1 ( V_113 ) ) {
if ( F_5 ( & V_113 -> V_89 ) ) {
if ( F_97 ( V_34 ) ) {
error = - 1 ;
break;
}
} else {
error = F_15 ( & V_114 ,
V_49 ,
F_99 ,
V_113 , V_113 ,
V_84 ) ;
}
if ( error != 0 )
break;
} else {
F_100 ( V_115 L_2
L_3 ) ;
}
}
return error ;
}
static int F_101 ( void )
{
int error = 0 ;
struct V_1 * V_116 ;
F_18 (current_file, &tfile_check_list, f_tfile_llink) {
F_98 () ;
error = F_15 ( & V_114 , V_49 ,
F_99 , V_116 ,
V_116 , V_84 ) ;
if ( error )
break;
}
return error ;
}
static int F_102 ( struct V_14 * V_18 )
{
const char * V_117 ;
struct V_54 * V_55 ;
if ( ! V_18 -> V_26 -> V_55 ) {
V_18 -> V_26 -> V_55 = F_103 ( L_4 ) ;
if ( ! V_18 -> V_26 -> V_55 )
return - V_92 ;
}
V_117 = V_18 -> V_6 . V_1 -> V_118 . V_119 -> V_120 . V_117 ;
V_55 = F_103 ( V_117 ) ;
if ( ! V_55 )
return - V_92 ;
F_104 ( V_18 -> V_55 , V_55 ) ;
return 0 ;
}
static T_4 void F_105 ( struct V_14 * V_18 )
{
struct V_54 * V_55 = F_38 ( V_18 ) ;
F_106 ( V_18 -> V_55 , NULL ) ;
F_107 () ;
F_62 ( V_55 ) ;
}
static int F_108 ( struct V_25 * V_26 , struct V_121 * V_77 ,
struct V_1 * V_122 , int V_7 )
{
int error , V_123 , V_58 = 0 ;
unsigned long V_35 ;
long V_124 ;
struct V_14 * V_18 ;
struct V_16 V_125 ;
V_124 = F_109 ( & V_26 -> V_69 -> V_70 ) ;
if ( F_85 ( V_124 >= V_126 ) )
return - V_127 ;
if ( ! ( V_18 = F_91 ( V_68 , V_93 ) ) )
return - V_92 ;
F_12 ( & V_18 -> V_62 ) ;
F_12 ( & V_18 -> V_65 ) ;
F_12 ( & V_18 -> V_52 ) ;
V_18 -> V_26 = V_26 ;
F_2 ( & V_18 -> V_6 , V_122 , V_7 ) ;
V_18 -> V_77 = * V_77 ;
V_18 -> V_105 = 0 ;
V_18 -> V_61 = V_29 ;
if ( V_18 -> V_77 . V_43 & V_128 ) {
error = F_102 ( V_18 ) ;
if ( error )
goto V_129;
} else {
F_106 ( V_18 -> V_55 , NULL ) ;
}
V_125 . V_18 = V_18 ;
F_75 ( & V_125 . V_17 , F_90 ) ;
V_123 = F_73 ( V_18 , & V_125 . V_17 ) ;
error = - V_92 ;
if ( V_18 -> V_105 < 0 )
goto V_130;
F_58 ( & V_122 -> V_64 ) ;
F_51 ( & V_18 -> V_65 , & V_122 -> V_89 ) ;
F_60 ( & V_122 -> V_64 ) ;
F_94 ( V_26 , V_18 ) ;
error = - V_131 ;
if ( F_101 () )
goto V_132;
F_17 ( & V_26 -> V_24 , V_35 ) ;
if ( ( V_123 & V_77 -> V_43 ) && ! F_4 ( & V_18 -> V_62 ) ) {
F_51 ( & V_18 -> V_62 , & V_26 -> V_27 ) ;
F_41 ( V_18 ) ;
if ( F_54 ( & V_26 -> V_46 ) )
F_55 ( & V_26 -> V_46 ) ;
if ( F_54 ( & V_26 -> V_63 ) )
V_58 ++ ;
}
F_20 ( & V_26 -> V_24 , V_35 ) ;
F_110 ( & V_26 -> V_69 -> V_70 ) ;
if ( V_58 )
F_27 ( & V_26 -> V_63 ) ;
return 0 ;
V_132:
F_58 ( & V_122 -> V_64 ) ;
if ( F_4 ( & V_18 -> V_65 ) )
F_59 ( & V_18 -> V_65 ) ;
F_60 ( & V_122 -> V_64 ) ;
F_61 ( & V_18 -> V_66 , & V_26 -> V_67 ) ;
V_130:
F_35 ( V_26 , V_18 ) ;
F_17 ( & V_26 -> V_24 , V_35 ) ;
if ( F_4 ( & V_18 -> V_62 ) )
F_59 ( & V_18 -> V_62 ) ;
F_20 ( & V_26 -> V_24 , V_35 ) ;
F_62 ( F_38 ( V_18 ) ) ;
V_129:
F_37 ( V_68 , V_18 ) ;
return error ;
}
static int F_111 ( struct V_25 * V_26 , struct V_14 * V_18 , struct V_121 * V_77 )
{
int V_58 = 0 ;
unsigned int V_123 ;
T_2 V_17 ;
F_75 ( & V_17 , NULL ) ;
V_18 -> V_77 . V_43 = V_77 -> V_43 ;
V_18 -> V_77 . V_88 = V_77 -> V_88 ;
if ( V_18 -> V_77 . V_43 & V_128 ) {
if ( ! F_43 ( V_18 ) )
F_102 ( V_18 ) ;
} else if ( F_43 ( V_18 ) ) {
F_105 ( V_18 ) ;
}
F_112 () ;
V_123 = F_73 ( V_18 , & V_17 ) ;
if ( V_123 & V_77 -> V_43 ) {
F_113 ( & V_26 -> V_24 ) ;
if ( ! F_4 ( & V_18 -> V_62 ) ) {
F_51 ( & V_18 -> V_62 , & V_26 -> V_27 ) ;
F_41 ( V_18 ) ;
if ( F_54 ( & V_26 -> V_46 ) )
F_55 ( & V_26 -> V_46 ) ;
if ( F_54 ( & V_26 -> V_63 ) )
V_58 ++ ;
}
F_114 ( & V_26 -> V_24 ) ;
}
if ( V_58 )
F_27 ( & V_26 -> V_63 ) ;
return 0 ;
}
static int F_115 ( struct V_25 * V_26 , struct V_10 * V_79 ,
void * V_31 )
{
struct V_133 * V_134 = V_31 ;
int V_135 ;
unsigned int V_123 ;
struct V_14 * V_18 ;
struct V_121 T_5 * V_136 ;
struct V_54 * V_55 ;
T_2 V_17 ;
F_75 ( & V_17 , NULL ) ;
for ( V_135 = 0 , V_136 = V_134 -> V_43 ;
! F_5 ( V_79 ) && V_135 < V_134 -> V_137 ; ) {
V_18 = F_36 ( V_79 , struct V_14 , V_62 ) ;
V_55 = F_38 ( V_18 ) ;
if ( V_55 ) {
if ( V_55 -> V_138 )
F_42 ( V_26 -> V_55 ) ;
F_53 ( V_55 ) ;
}
F_59 ( & V_18 -> V_62 ) ;
V_123 = F_73 ( V_18 , & V_17 ) ;
if ( V_123 ) {
if ( F_116 ( V_123 , & V_136 -> V_43 ) ||
F_116 ( V_18 -> V_77 . V_88 , & V_136 -> V_88 ) ) {
F_19 ( & V_18 -> V_62 , V_79 ) ;
F_41 ( V_18 ) ;
return V_135 ? V_135 : - V_139 ;
}
V_135 ++ ;
V_136 ++ ;
if ( V_18 -> V_77 . V_43 & V_140 )
V_18 -> V_77 . V_43 &= V_104 ;
else if ( ! ( V_18 -> V_77 . V_43 & V_141 ) ) {
F_51 ( & V_18 -> V_62 , & V_26 -> V_27 ) ;
F_41 ( V_18 ) ;
}
}
}
return V_135 ;
}
static int F_117 ( struct V_25 * V_26 ,
struct V_121 T_5 * V_43 , int V_137 )
{
struct V_133 V_134 ;
V_134 . V_137 = V_137 ;
V_134 . V_43 = V_43 ;
return F_46 ( V_26 , F_115 , & V_134 , 0 ) ;
}
static inline struct V_142 F_118 ( long V_143 )
{
struct V_142 V_144 , V_145 = {
. V_146 = V_143 / V_147 ,
. V_148 = V_149 * ( V_143 % V_147 ) ,
} ;
F_119 ( & V_144 ) ;
return F_120 ( V_144 , V_145 ) ;
}
static int F_121 ( struct V_25 * V_26 , struct V_121 T_5 * V_43 ,
int V_137 , long V_150 )
{
int V_151 = 0 , V_152 , V_153 = 0 ;
unsigned long V_35 ;
long V_154 = 0 ;
T_1 V_13 ;
T_6 V_155 , * V_156 = NULL ;
if ( V_150 > 0 ) {
struct V_142 V_157 = F_118 ( V_150 ) ;
V_154 = F_122 ( & V_157 ) ;
V_156 = & V_155 ;
* V_156 = F_123 ( V_157 ) ;
} else if ( V_150 == 0 ) {
V_153 = 1 ;
F_17 ( & V_26 -> V_24 , V_35 ) ;
goto V_158;
}
V_159:
F_17 ( & V_26 -> V_24 , V_35 ) ;
if ( ! F_14 ( V_26 ) ) {
F_124 ( & V_13 , V_84 ) ;
F_125 ( & V_26 -> V_46 , & V_13 ) ;
for (; ; ) {
F_126 ( V_160 ) ;
if ( F_14 ( V_26 ) || V_153 )
break;
if ( F_127 ( V_84 ) ) {
V_151 = - V_161 ;
break;
}
F_20 ( & V_26 -> V_24 , V_35 ) ;
if ( ! F_128 ( V_156 , V_154 , V_162 ) )
V_153 = 1 ;
F_17 ( & V_26 -> V_24 , V_35 ) ;
}
F_129 ( & V_26 -> V_46 , & V_13 ) ;
F_126 ( V_163 ) ;
}
V_158:
V_152 = F_14 ( V_26 ) ;
F_20 ( & V_26 -> V_24 , V_35 ) ;
if ( ! V_151 && V_152 &&
! ( V_151 = F_117 ( V_26 , V_43 , V_137 ) ) && ! V_153 )
goto V_159;
return V_151 ;
}
static int F_130 ( void * V_31 , void * V_32 , int V_34 )
{
int error = 0 ;
struct V_1 * V_1 = V_31 ;
struct V_25 * V_26 = V_1 -> V_75 ;
struct V_25 * V_164 ;
struct V_71 * V_72 ;
struct V_14 * V_18 ;
F_49 ( & V_26 -> V_56 , V_34 + 1 ) ;
V_26 -> V_165 = 1 ;
F_19 ( & V_26 -> V_166 , & V_167 ) ;
for ( V_72 = F_66 ( & V_26 -> V_67 ) ; V_72 ; V_72 = F_67 ( V_72 ) ) {
V_18 = F_68 ( V_72 , struct V_14 , V_66 ) ;
if ( F_85 ( F_1 ( V_18 -> V_6 . V_1 ) ) ) {
V_164 = V_18 -> V_6 . V_1 -> V_75 ;
if ( V_164 -> V_165 )
continue;
error = F_15 ( & V_114 , V_49 ,
F_130 , V_18 -> V_6 . V_1 ,
V_164 , V_84 ) ;
if ( error != 0 )
break;
} else {
if ( F_5 ( & V_18 -> V_6 . V_1 -> V_168 ) )
F_19 ( & V_18 -> V_6 . V_1 -> V_168 ,
& V_169 ) ;
}
}
F_56 ( & V_26 -> V_56 ) ;
return error ;
}
static int F_131 ( struct V_25 * V_26 , struct V_1 * V_1 )
{
int V_87 ;
struct V_25 * V_170 , * V_171 ;
V_87 = F_15 ( & V_114 , V_49 ,
F_130 , V_1 , V_26 , V_84 ) ;
F_76 (ep_cur, ep_next, &visited_list,
visited_list_link) {
V_170 -> V_165 = 0 ;
F_21 ( & V_170 -> V_166 ) ;
}
return V_87 ;
}
static void F_132 ( void )
{
struct V_1 * V_1 ;
while ( ! F_5 ( & V_169 ) ) {
V_1 = F_36 ( & V_169 , struct V_1 ,
V_168 ) ;
F_59 ( & V_1 -> V_168 ) ;
}
F_12 ( & V_169 ) ;
}
static int T_7 F_133 ( void )
{
struct V_172 V_173 ;
F_134 ( & V_173 ) ;
V_126 = ( ( ( V_173 . V_174 - V_173 . V_175 ) / 25 ) << V_176 ) /
V_177 ;
F_135 ( V_126 < 0 ) ;
F_11 ( & V_114 ) ;
F_11 ( & V_48 ) ;
F_11 ( & V_83 ) ;
F_136 ( sizeof( void * ) <= 8 && sizeof( struct V_14 ) > 128 ) ;
V_68 = F_137 ( L_5 , sizeof( struct V_14 ) ,
0 , V_178 | V_179 , NULL ) ;
V_53 = F_137 ( L_6 ,
sizeof( struct V_12 ) , 0 , V_179 , NULL ) ;
return 0 ;
}
