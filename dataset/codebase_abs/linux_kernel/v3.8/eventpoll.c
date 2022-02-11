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
static int F_71 ( struct V_84 * V_85 , struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_74 ;
struct V_70 * V_71 ;
int V_86 = 0 ;
F_58 ( & V_26 -> V_58 ) ;
for ( V_71 = F_59 ( & V_26 -> V_66 ) ; V_71 ; V_71 = F_60 ( V_71 ) ) {
struct V_14 * V_18 = F_61 ( V_71 , struct V_14 , V_65 ) ;
V_86 = F_72 ( V_85 , L_1 ,
V_18 -> V_6 . V_7 , V_18 -> V_78 . V_43 ,
( long long ) V_18 -> V_78 . V_87 ) ;
if ( V_86 )
break;
}
F_49 ( & V_26 -> V_58 ) ;
return V_86 ;
}
void F_73 ( struct V_1 * V_1 )
{
struct V_10 * V_36 = & V_1 -> V_88 ;
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
static int F_74 ( struct V_25 * * V_89 )
{
int error ;
struct V_90 * V_68 ;
struct V_25 * V_26 ;
V_68 = F_75 () ;
error = - V_91 ;
V_26 = F_76 ( sizeof( * V_26 ) , V_92 ) ;
if ( F_77 ( ! V_26 ) )
goto F_63;
F_13 ( & V_26 -> V_24 ) ;
F_78 ( & V_26 -> V_58 ) ;
F_79 ( & V_26 -> V_46 ) ;
F_79 ( & V_26 -> V_62 ) ;
F_12 ( & V_26 -> V_27 ) ;
V_26 -> V_66 = V_93 ;
V_26 -> V_28 = V_29 ;
V_26 -> V_68 = V_68 ;
* V_89 = V_26 ;
return 0 ;
F_63:
F_63 ( V_68 ) ;
return error ;
}
static struct V_14 * F_80 ( struct V_25 * V_26 , struct V_1 * V_1 , int V_7 )
{
int V_94 ;
struct V_70 * V_71 ;
struct V_14 * V_18 , * V_95 = NULL ;
struct V_5 V_6 ;
F_2 ( & V_6 , V_1 , V_7 ) ;
for ( V_71 = V_26 -> V_66 . V_70 ; V_71 ; ) {
V_18 = F_61 ( V_71 , struct V_14 , V_65 ) ;
V_94 = F_3 ( & V_6 , & V_18 -> V_6 ) ;
if ( V_94 > 0 )
V_71 = V_71 -> V_96 ;
else if ( V_94 < 0 )
V_71 = V_71 -> V_97 ;
else {
V_95 = V_18 ;
break;
}
}
return V_95 ;
}
static int F_81 ( T_1 * V_13 , unsigned V_98 , int V_99 , void * V_100 )
{
int V_55 = 0 ;
unsigned long V_35 ;
struct V_14 * V_18 = F_8 ( V_13 ) ;
struct V_25 * V_26 = V_18 -> V_26 ;
if ( ( unsigned long ) V_100 & V_101 ) {
F_6 ( V_13 ) -> V_51 = NULL ;
F_52 ( & V_13 -> V_102 ) ;
}
F_17 ( & V_26 -> V_24 , V_35 ) ;
if ( ! ( V_18 -> V_78 . V_43 & ~ V_103 ) )
goto V_40;
if ( V_100 && ! ( ( unsigned long ) V_100 & V_18 -> V_78 . V_43 ) )
goto V_40;
if ( F_77 ( V_26 -> V_28 != V_29 ) ) {
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
static void F_82 ( struct V_1 * V_1 , T_3 * V_51 ,
T_2 * V_17 )
{
struct V_14 * V_18 = F_9 ( V_17 ) ;
struct V_12 * V_50 ;
if ( V_18 -> V_104 >= 0 && ( V_50 = F_83 ( V_53 , V_92 ) ) ) {
F_84 ( & V_50 -> V_13 , F_81 ) ;
V_50 -> V_51 = V_51 ;
V_50 -> V_15 = V_18 ;
F_85 ( V_51 , & V_50 -> V_13 ) ;
F_43 ( & V_50 -> V_41 , & V_18 -> V_52 ) ;
V_18 -> V_104 ++ ;
} else {
V_18 -> V_104 = - 1 ;
}
}
static void F_86 ( struct V_25 * V_26 , struct V_14 * V_18 )
{
int V_94 ;
struct V_70 * * V_11 = & V_26 -> V_66 . V_70 , * V_105 = NULL ;
struct V_14 * V_106 ;
while ( * V_11 ) {
V_105 = * V_11 ;
V_106 = F_61 ( V_105 , struct V_14 , V_65 ) ;
V_94 = F_3 ( & V_18 -> V_6 , & V_106 -> V_6 ) ;
if ( V_94 > 0 )
V_11 = & V_105 -> V_96 ;
else
V_11 = & V_105 -> V_97 ;
}
F_87 ( & V_18 -> V_65 , V_105 , V_11 ) ;
F_88 ( & V_18 -> V_65 , & V_26 -> V_66 ) ;
}
static int F_89 ( int V_107 )
{
if ( V_107 == 0 )
return 0 ;
if ( ++ V_108 [ V_107 ] > V_109 [ V_107 ] )
return - 1 ;
return 0 ;
}
static void F_90 ( void )
{
int V_110 ;
for ( V_110 = 0 ; V_110 < V_111 ; V_110 ++ )
V_108 [ V_110 ] = 0 ;
}
static int F_91 ( void * V_31 , void * V_32 , int V_34 )
{
int error = 0 ;
struct V_1 * V_1 = V_31 ;
struct V_1 * V_112 ;
struct V_14 * V_18 ;
F_18 (epi, &file->f_ep_links, fllink) {
V_112 = V_18 -> V_26 -> V_1 ;
if ( F_1 ( V_112 ) ) {
if ( F_5 ( & V_112 -> V_88 ) ) {
if ( F_89 ( V_34 ) ) {
error = - 1 ;
break;
}
} else {
error = F_15 ( & V_113 ,
V_49 ,
F_91 ,
V_112 , V_112 ,
V_83 ) ;
}
if ( error != 0 )
break;
} else {
F_92 ( V_114 L_2
L_3 ) ;
}
}
return error ;
}
static int F_93 ( void )
{
int error = 0 ;
struct V_1 * V_115 ;
F_18 (current_file, &tfile_check_list, f_tfile_llink) {
F_90 () ;
error = F_15 ( & V_113 , V_49 ,
F_91 , V_115 ,
V_115 , V_83 ) ;
if ( error )
break;
}
return error ;
}
static int F_94 ( struct V_14 * V_18 )
{
const char * V_116 ;
if ( ! V_18 -> V_26 -> V_61 ) {
V_18 -> V_26 -> V_61 = F_95 ( L_4 ) ;
if ( ! V_18 -> V_26 -> V_61 )
return - V_91 ;
}
V_116 = V_18 -> V_6 . V_1 -> V_117 . V_118 -> V_119 . V_116 ;
V_18 -> V_61 = F_95 ( V_116 ) ;
if ( ! V_18 -> V_61 )
return - V_91 ;
return 0 ;
}
static void F_96 ( struct V_14 * V_18 )
{
F_55 ( V_18 -> V_61 ) ;
V_18 -> V_61 = NULL ;
}
static int F_97 ( struct V_25 * V_26 , struct V_120 * V_78 ,
struct V_1 * V_121 , int V_7 )
{
int error , V_122 , V_55 = 0 ;
unsigned long V_35 ;
long V_123 ;
struct V_14 * V_18 ;
struct V_16 V_124 ;
V_123 = F_98 ( & V_26 -> V_68 -> V_69 ) ;
if ( F_77 ( V_123 >= V_125 ) )
return - V_126 ;
if ( ! ( V_18 = F_83 ( V_67 , V_92 ) ) )
return - V_91 ;
F_12 ( & V_18 -> V_60 ) ;
F_12 ( & V_18 -> V_64 ) ;
F_12 ( & V_18 -> V_52 ) ;
V_18 -> V_26 = V_26 ;
F_2 ( & V_18 -> V_6 , V_121 , V_7 ) ;
V_18 -> V_78 = * V_78 ;
V_18 -> V_104 = 0 ;
V_18 -> V_59 = V_29 ;
if ( V_18 -> V_78 . V_43 & V_127 ) {
error = F_94 ( V_18 ) ;
if ( error )
goto V_128;
} else {
V_18 -> V_61 = NULL ;
}
V_124 . V_18 = V_18 ;
F_67 ( & V_124 . V_17 , F_82 ) ;
V_124 . V_17 . V_77 = V_78 -> V_43 ;
V_122 = V_121 -> V_3 -> V_79 ( V_121 , & V_124 . V_17 ) ;
error = - V_91 ;
if ( V_18 -> V_104 < 0 )
goto V_129;
F_51 ( & V_121 -> V_63 ) ;
F_43 ( & V_18 -> V_64 , & V_121 -> V_88 ) ;
F_53 ( & V_121 -> V_63 ) ;
F_86 ( V_26 , V_18 ) ;
error = - V_130 ;
if ( F_93 () )
goto V_131;
F_17 ( & V_26 -> V_24 , V_35 ) ;
if ( ( V_122 & V_78 -> V_43 ) && ! F_4 ( & V_18 -> V_60 ) ) {
F_43 ( & V_18 -> V_60 , & V_26 -> V_27 ) ;
F_44 ( V_18 -> V_61 ) ;
if ( F_47 ( & V_26 -> V_46 ) )
F_48 ( & V_26 -> V_46 ) ;
if ( F_47 ( & V_26 -> V_62 ) )
V_55 ++ ;
}
F_20 ( & V_26 -> V_24 , V_35 ) ;
F_99 ( & V_26 -> V_68 -> V_69 ) ;
if ( V_55 )
F_27 ( & V_26 -> V_62 ) ;
return 0 ;
V_131:
F_51 ( & V_121 -> V_63 ) ;
if ( F_4 ( & V_18 -> V_64 ) )
F_52 ( & V_18 -> V_64 ) ;
F_53 ( & V_121 -> V_63 ) ;
F_54 ( & V_18 -> V_65 , & V_26 -> V_66 ) ;
V_129:
F_35 ( V_26 , V_18 ) ;
F_17 ( & V_26 -> V_24 , V_35 ) ;
if ( F_4 ( & V_18 -> V_60 ) )
F_52 ( & V_18 -> V_60 ) ;
F_20 ( & V_26 -> V_24 , V_35 ) ;
F_55 ( V_18 -> V_61 ) ;
V_128:
F_37 ( V_67 , V_18 ) ;
return error ;
}
static int F_100 ( struct V_25 * V_26 , struct V_14 * V_18 , struct V_120 * V_78 )
{
int V_55 = 0 ;
unsigned int V_122 ;
T_2 V_17 ;
F_67 ( & V_17 , NULL ) ;
V_18 -> V_78 . V_43 = V_78 -> V_43 ;
V_17 . V_77 = V_78 -> V_43 ;
V_18 -> V_78 . V_87 = V_78 -> V_87 ;
if ( V_18 -> V_78 . V_43 & V_127 ) {
if ( ! V_18 -> V_61 )
F_94 ( V_18 ) ;
} else if ( V_18 -> V_61 ) {
F_96 ( V_18 ) ;
}
F_101 () ;
V_122 = V_18 -> V_6 . V_1 -> V_3 -> V_79 ( V_18 -> V_6 . V_1 , & V_17 ) ;
if ( V_122 & V_78 -> V_43 ) {
F_102 ( & V_26 -> V_24 ) ;
if ( ! F_4 ( & V_18 -> V_60 ) ) {
F_43 ( & V_18 -> V_60 , & V_26 -> V_27 ) ;
F_44 ( V_18 -> V_61 ) ;
if ( F_47 ( & V_26 -> V_46 ) )
F_48 ( & V_26 -> V_46 ) ;
if ( F_47 ( & V_26 -> V_62 ) )
V_55 ++ ;
}
F_103 ( & V_26 -> V_24 ) ;
}
if ( V_55 )
F_27 ( & V_26 -> V_62 ) ;
return 0 ;
}
static int F_104 ( struct V_25 * V_26 , struct V_10 * V_75 ,
void * V_31 )
{
struct V_132 * V_133 = V_31 ;
int V_134 ;
unsigned int V_122 ;
struct V_14 * V_18 ;
struct V_120 T_4 * V_135 ;
T_2 V_17 ;
F_67 ( & V_17 , NULL ) ;
for ( V_134 = 0 , V_135 = V_133 -> V_43 ;
! F_5 ( V_75 ) && V_134 < V_133 -> V_136 ; ) {
V_18 = F_36 ( V_75 , struct V_14 , V_60 ) ;
if ( V_18 -> V_61 && V_18 -> V_61 -> V_137 )
F_44 ( V_26 -> V_61 ) ;
F_46 ( V_18 -> V_61 ) ;
F_52 ( & V_18 -> V_60 ) ;
V_17 . V_77 = V_18 -> V_78 . V_43 ;
V_122 = V_18 -> V_6 . V_1 -> V_3 -> V_79 ( V_18 -> V_6 . V_1 , & V_17 ) &
V_18 -> V_78 . V_43 ;
if ( V_122 ) {
if ( F_105 ( V_122 , & V_135 -> V_43 ) ||
F_105 ( V_18 -> V_78 . V_87 , & V_135 -> V_87 ) ) {
F_19 ( & V_18 -> V_60 , V_75 ) ;
F_44 ( V_18 -> V_61 ) ;
return V_134 ? V_134 : - V_138 ;
}
V_134 ++ ;
V_135 ++ ;
if ( V_18 -> V_78 . V_43 & V_139 )
V_18 -> V_78 . V_43 &= V_103 ;
else if ( ! ( V_18 -> V_78 . V_43 & V_140 ) ) {
F_43 ( & V_18 -> V_60 , & V_26 -> V_27 ) ;
F_44 ( V_18 -> V_61 ) ;
}
}
}
return V_134 ;
}
static int F_106 ( struct V_25 * V_26 ,
struct V_120 T_4 * V_43 , int V_136 )
{
struct V_132 V_133 ;
V_133 . V_136 = V_136 ;
V_133 . V_43 = V_43 ;
return F_38 ( V_26 , F_104 , & V_133 , 0 ) ;
}
static inline struct V_141 F_107 ( long V_142 )
{
struct V_141 V_143 , V_144 = {
. V_145 = V_142 / V_146 ,
. V_147 = V_148 * ( V_142 % V_146 ) ,
} ;
F_108 ( & V_143 ) ;
return F_109 ( V_143 , V_144 ) ;
}
static int F_110 ( struct V_25 * V_26 , struct V_120 T_4 * V_43 ,
int V_136 , long V_149 )
{
int V_150 = 0 , V_151 , V_152 = 0 ;
unsigned long V_35 ;
long V_153 = 0 ;
T_1 V_13 ;
T_5 V_154 , * V_155 = NULL ;
if ( V_149 > 0 ) {
struct V_141 V_156 = F_107 ( V_149 ) ;
V_153 = F_111 ( & V_156 ) ;
V_155 = & V_154 ;
* V_155 = F_112 ( V_156 ) ;
} else if ( V_149 == 0 ) {
V_152 = 1 ;
F_17 ( & V_26 -> V_24 , V_35 ) ;
goto V_157;
}
V_158:
F_17 ( & V_26 -> V_24 , V_35 ) ;
if ( ! F_14 ( V_26 ) ) {
F_113 ( & V_13 , V_83 ) ;
F_114 ( & V_26 -> V_46 , & V_13 ) ;
for (; ; ) {
F_115 ( V_159 ) ;
if ( F_14 ( V_26 ) || V_152 )
break;
if ( F_116 ( V_83 ) ) {
V_150 = - V_160 ;
break;
}
F_20 ( & V_26 -> V_24 , V_35 ) ;
if ( ! F_117 ( V_155 , V_153 , V_161 ) )
V_152 = 1 ;
F_17 ( & V_26 -> V_24 , V_35 ) ;
}
F_118 ( & V_26 -> V_46 , & V_13 ) ;
F_115 ( V_162 ) ;
}
V_157:
V_151 = F_14 ( V_26 ) ;
F_20 ( & V_26 -> V_24 , V_35 ) ;
if ( ! V_150 && V_151 &&
! ( V_150 = F_106 ( V_26 , V_43 , V_136 ) ) && ! V_152 )
goto V_158;
return V_150 ;
}
static int F_119 ( void * V_31 , void * V_32 , int V_34 )
{
int error = 0 ;
struct V_1 * V_1 = V_31 ;
struct V_25 * V_26 = V_1 -> V_74 ;
struct V_25 * V_163 ;
struct V_70 * V_71 ;
struct V_14 * V_18 ;
F_41 ( & V_26 -> V_58 , V_34 + 1 ) ;
V_26 -> V_164 = 1 ;
F_19 ( & V_26 -> V_165 , & V_166 ) ;
for ( V_71 = F_59 ( & V_26 -> V_66 ) ; V_71 ; V_71 = F_60 ( V_71 ) ) {
V_18 = F_61 ( V_71 , struct V_14 , V_65 ) ;
if ( F_77 ( F_1 ( V_18 -> V_6 . V_1 ) ) ) {
V_163 = V_18 -> V_6 . V_1 -> V_74 ;
if ( V_163 -> V_164 )
continue;
error = F_15 ( & V_113 , V_49 ,
F_119 , V_18 -> V_6 . V_1 ,
V_163 , V_83 ) ;
if ( error != 0 )
break;
} else {
if ( F_5 ( & V_18 -> V_6 . V_1 -> V_167 ) )
F_19 ( & V_18 -> V_6 . V_1 -> V_167 ,
& V_168 ) ;
}
}
F_49 ( & V_26 -> V_58 ) ;
return error ;
}
static int F_120 ( struct V_25 * V_26 , struct V_1 * V_1 )
{
int V_86 ;
struct V_25 * V_169 , * V_170 ;
V_86 = F_15 ( & V_113 , V_49 ,
F_119 , V_1 , V_26 , V_83 ) ;
F_68 (ep_cur, ep_next, &visited_list,
visited_list_link) {
V_169 -> V_164 = 0 ;
F_21 ( & V_169 -> V_165 ) ;
}
return V_86 ;
}
static void F_121 ( void )
{
struct V_1 * V_1 ;
while ( ! F_5 ( & V_168 ) ) {
V_1 = F_36 ( & V_168 , struct V_1 ,
V_167 ) ;
F_52 ( & V_1 -> V_167 ) ;
}
F_12 ( & V_168 ) ;
}
static int T_6 F_122 ( void )
{
struct V_171 V_172 ;
F_123 ( & V_172 ) ;
V_125 = ( ( ( V_172 . V_173 - V_172 . V_174 ) / 25 ) << V_175 ) /
V_176 ;
F_124 ( V_125 < 0 ) ;
F_11 ( & V_113 ) ;
F_11 ( & V_48 ) ;
F_11 ( & V_82 ) ;
V_67 = F_125 ( L_5 , sizeof( struct V_14 ) ,
0 , V_177 | V_178 , NULL ) ;
V_53 = F_125 ( L_6 ,
sizeof( struct V_12 ) , 0 , V_178 , NULL ) ;
return 0 ;
}
