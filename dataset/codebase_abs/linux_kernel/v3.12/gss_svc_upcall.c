T_1 F_1 ( void )
{
T_1 V_1 ;
F_2 ( & V_2 ) ;
V_1 = V_3 ++ ;
F_3 ( & V_2 ) ;
return V_1 ;
}
static inline unsigned long F_4 ( char * V_4 , int V_5 , int V_6 )
{
unsigned long V_7 = 0 ;
unsigned long V_8 = 0 ;
int V_9 = 0 ;
unsigned char V_10 ;
do {
if ( V_9 == V_5 ) {
V_10 = ( char ) V_9 ;
V_9 = - 1 ;
} else
V_10 = * V_4 ++ ;
V_8 = ( V_8 << 8 ) | V_10 ;
V_9 ++ ;
if ( ( V_9 & ( V_11 / 8 - 1 ) ) == 0 )
V_7 = F_5 ( V_7 ^ V_8 , V_11 ) ;
} while ( V_9 );
return V_7 >> ( V_11 - V_6 ) ;
}
static inline int F_6 ( struct V_12 * V_13 )
{
return F_4 ( ( char * ) V_13 -> V_14 . V_15 , V_13 -> V_14 . V_9 ,
V_16 ) ^
F_4 ( ( char * ) V_13 -> V_17 . V_15 , V_13 -> V_17 . V_9 ,
V_16 ) ;
}
static inline int F_7 ( struct V_12 * V_13 , struct V_12 * V_18 )
{
return ( F_8 ( & V_13 -> V_14 , & V_18 -> V_14 ) &&
F_8 ( & V_13 -> V_17 , & V_18 -> V_17 ) ) ;
}
static void F_9 ( struct V_12 * V_12 )
{
F_10 ( & V_12 -> V_14 ) ;
F_10 ( & V_12 -> V_17 ) ;
F_10 ( & V_12 -> V_19 ) ;
F_10 ( & V_12 -> V_20 ) ;
}
static void F_11 ( struct V_21 * V_22 ,
struct V_23 * V_24 ,
char * * V_25 , int * V_26 )
{
struct V_12 * V_12 = F_12 ( V_24 , struct V_12 , V_24 ) ;
T_1 V_27 = 0 ;
if ( V_12 -> V_14 . V_9 == 0 )
V_27 = F_1 () ;
F_13 ( V_25 , V_26 , ( char * ) & V_12 -> V_28 ,
sizeof( V_12 -> V_28 ) ) ;
F_13 ( V_25 , V_26 , ( char * ) & V_12 -> V_29 , sizeof( V_12 -> V_29 ) ) ;
F_13 ( V_25 , V_26 , ( char * ) & V_27 , sizeof( V_27 ) ) ;
F_13 ( V_25 , V_26 , V_12 -> V_14 . V_15 , V_12 -> V_14 . V_9 ) ;
F_13 ( V_25 , V_26 , V_12 -> V_17 . V_15 , V_12 -> V_17 . V_9 ) ;
( * V_25 ) [ - 1 ] = '\n' ;
}
static int F_14 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
return F_15 ( V_22 , V_24 , F_11 ) ;
}
static inline void F_16 ( struct V_12 * V_30 , struct V_12 * V_13 )
{
V_30 -> V_19 = V_31 ;
V_30 -> V_20 = V_31 ;
V_30 -> V_14 = V_13 -> V_14 ;
V_13 -> V_14 = V_31 ;
V_30 -> V_17 = V_13 -> V_17 ;
V_13 -> V_17 = V_31 ;
V_30 -> V_28 = V_13 -> V_28 ;
V_30 -> V_29 = V_13 -> V_29 ;
F_17 ( & V_30 -> V_32 ) ;
}
static inline void F_18 ( struct V_12 * V_30 , struct V_12 * V_13 )
{
F_19 ( V_30 -> V_19 . V_9 == 0 ) ;
F_19 ( V_30 -> V_20 . V_9 == 0 ) ;
V_30 -> V_19 = V_13 -> V_19 ;
V_13 -> V_19 = V_31 ;
V_30 -> V_20 = V_13 -> V_20 ;
V_13 -> V_20 = V_31 ;
V_30 -> V_33 = V_13 -> V_33 ;
V_30 -> V_34 = V_13 -> V_34 ;
}
static void F_20 ( struct V_35 * V_36 )
{
struct V_12 * V_12 = F_12 ( V_36 , struct V_12 , V_24 . V_36 ) ;
F_19 ( V_12 -> V_24 . V_37 == NULL ) ;
F_9 ( V_12 ) ;
F_21 ( V_12 ) ;
}
static int F_22 ( struct V_23 * V_38 , struct V_23 * V_39 )
{
struct V_12 * V_13 = F_12 ( V_38 , struct V_12 , V_24 ) ;
struct V_12 * V_18 = F_12 ( V_39 , struct V_12 , V_24 ) ;
return F_7 ( V_13 , V_18 ) ;
}
static void F_23 ( struct V_23 * V_40 , struct V_23 * V_41 )
{
struct V_12 * V_30 = F_12 ( V_40 , struct V_12 , V_24 ) ;
struct V_12 * V_13 = F_12 ( V_41 , struct V_12 , V_24 ) ;
F_16 ( V_30 , V_13 ) ;
}
static void F_24 ( struct V_23 * V_40 , struct V_23 * V_41 )
{
struct V_12 * V_30 = F_12 ( V_40 , struct V_12 , V_24 ) ;
struct V_12 * V_13 = F_12 ( V_41 , struct V_12 , V_24 ) ;
F_18 ( V_30 , V_13 ) ;
}
static struct V_23 * F_25 ( void )
{
struct V_12 * V_12 ;
F_26 ( V_12 ) ;
if ( V_12 )
return & V_12 -> V_24 ;
else
return NULL ;
}
static int F_27 ( struct V_21 * V_22 , char * V_42 , int V_43 )
{
char * V_4 = V_42 ;
char * V_44 ;
int V_9 ;
struct V_12 V_45 , * V_46 = NULL ;
T_2 V_47 ;
int V_48 = - V_49 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_9 = F_28 ( & V_42 , V_4 , V_43 ) ;
if ( V_9 < 0 )
goto V_50;
if ( F_29 ( & V_45 . V_14 , V_4 , V_9 ) ) {
V_48 = - V_51 ;
goto V_50;
}
V_9 = F_28 ( & V_42 , V_4 , V_43 ) ;
if ( V_9 < 0 )
goto V_50;
if ( F_29 ( & V_45 . V_17 , V_4 , V_9 ) ) {
V_48 = - V_51 ;
goto V_50;
}
V_46 = F_30 ( & V_45 ) ;
if ( ! V_46 )
goto V_50;
V_45 . V_24 . V_52 = 0 ;
V_47 = F_31 ( & V_42 ) ;
if ( V_47 == 0 )
goto V_50;
V_9 = F_28 ( & V_42 , V_4 , V_43 ) ;
if ( V_9 <= 0 )
goto V_50;
V_45 . V_33 = F_32 ( V_4 , & V_44 , 10 ) ;
if ( * V_44 )
goto V_50;
V_9 = F_28 ( & V_42 , V_4 , V_43 ) ;
if ( V_9 <= 0 )
goto V_50;
V_45 . V_34 = F_32 ( V_4 , & V_44 , 10 ) ;
if ( * V_44 )
goto V_50;
V_9 = F_28 ( & V_42 , V_4 , V_43 ) ;
if ( V_9 < 0 )
goto V_50;
if ( F_29 ( & V_45 . V_19 , V_4 , V_9 ) ) {
V_48 = - V_51 ;
goto V_50;
}
V_9 = F_28 ( & V_42 , V_4 , V_43 ) ;
if ( V_9 < 0 )
goto V_50;
if ( F_29 ( & V_45 . V_20 , V_4 , V_9 ) ) {
V_48 = - V_51 ;
goto V_50;
}
V_45 . V_24 . V_53 = V_47 ;
V_46 = F_33 ( & V_45 , V_46 ) ;
V_48 = 0 ;
V_50:
F_9 ( & V_45 ) ;
if ( V_46 ) {
F_34 ( & V_46 -> V_32 ) ;
F_35 ( & V_46 -> V_24 , & V_54 ) ;
} else {
V_48 = - V_51 ;
}
if ( V_48 )
F_36 ( L_1 , V_48 ) ;
return V_48 ;
}
static struct V_12 * F_30 ( struct V_12 * V_13 )
{
struct V_23 * V_55 ;
int V_7 = F_6 ( V_13 ) ;
V_55 = F_37 ( & V_54 , & V_13 -> V_24 , V_7 ) ;
if ( V_55 )
return F_12 ( V_55 , struct V_12 , V_24 ) ;
else
return NULL ;
}
static struct V_12 * F_33 ( struct V_12 * V_30 , struct V_12 * V_56 )
{
struct V_23 * V_55 ;
int V_7 = F_6 ( V_30 ) ;
V_55 = F_38 ( & V_54 , & V_30 -> V_24 , & V_56 -> V_24 , V_7 ) ;
if ( V_55 )
return F_12 ( V_55 , struct V_12 , V_24 ) ;
else
return NULL ;
}
static void F_39 ( struct V_57 * V_58 )
{
F_10 ( & V_58 -> V_59 ) ;
F_10 ( & V_58 -> V_60 . V_61 ) ;
F_40 ( & V_58 -> V_60 . V_62 ) ;
}
static inline int F_41 ( struct V_57 * V_58 )
{
return F_4 ( ( char * ) V_58 -> V_59 . V_15 ,
V_58 -> V_59 . V_9 , V_63 ) ;
}
static inline int F_42 ( struct V_57 * V_30 , struct V_57 * V_18 )
{
return F_8 ( & V_30 -> V_59 , & V_18 -> V_59 ) ;
}
static inline void F_43 ( struct V_57 * V_30 , struct V_57 * V_18 )
{
V_30 -> V_59 = V_18 -> V_59 ;
V_18 -> V_59 = V_31 ;
V_30 -> V_64 = NULL ;
memset ( & V_30 -> V_60 , 0 , sizeof( V_30 -> V_60 ) ) ;
V_30 -> V_60 . V_61 = V_31 ;
}
static inline void F_44 ( struct V_57 * V_30 , struct V_57 * V_18 )
{
V_30 -> V_60 = V_18 -> V_60 ;
V_18 -> V_60 . V_61 = V_31 ;
V_18 -> V_60 . V_62 = NULL ;
memset ( & V_30 -> V_60 . V_65 , 0 , sizeof( V_30 -> V_60 . V_65 ) ) ;
F_45 ( & V_30 -> V_60 . V_65 . V_66 ) ;
}
static void F_46 ( struct V_35 * V_36 )
{
struct V_57 * V_58 = F_12 ( V_36 , struct V_57 , V_24 . V_36 ) ;
F_19 ( V_58 -> V_24 . V_37 == NULL ) ;
F_39 ( V_58 ) ;
F_21 ( V_58 ) ;
}
static int F_47 ( struct V_23 * V_38 , struct V_23 * V_39 )
{
struct V_57 * V_30 = F_12 ( V_38 , struct V_57 , V_24 ) ;
struct V_57 * V_18 = F_12 ( V_39 , struct V_57 , V_24 ) ;
return F_42 ( V_30 , V_18 ) ;
}
static void F_48 ( struct V_23 * V_40 , struct V_23 * V_67 )
{
struct V_57 * V_30 = F_12 ( V_40 , struct V_57 , V_24 ) ;
struct V_57 * V_18 = F_12 ( V_67 , struct V_57 , V_24 ) ;
F_43 ( V_30 , V_18 ) ;
}
static void F_49 ( struct V_23 * V_40 , struct V_23 * V_67 )
{
struct V_57 * V_30 = F_12 ( V_40 , struct V_57 , V_24 ) ;
struct V_57 * V_18 = F_12 ( V_67 , struct V_57 , V_24 ) ;
F_44 ( V_30 , V_18 ) ;
}
static struct V_23 * F_50 ( void )
{
struct V_57 * V_57 ;
F_26 ( V_57 ) ;
if ( V_57 )
return & V_57 -> V_24 ;
else
return NULL ;
}
static int F_51 ( struct V_21 * V_22 , char * V_42 , int V_43 )
{
char * V_4 = V_42 ;
int V_9 , V_68 , V_69 ;
struct V_57 V_58 , * V_70 = NULL ;
T_2 V_47 ;
int V_48 = - V_49 ;
struct V_71 * V_72 = NULL ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_9 = F_28 ( & V_42 , V_4 , V_43 ) ;
if ( V_9 < 0 ) goto V_50;
V_48 = - V_51 ;
if ( F_29 ( & V_58 . V_59 , V_4 , V_9 ) )
goto V_50;
V_58 . V_24 . V_52 = 0 ;
V_47 = F_31 ( & V_42 ) ;
V_48 = - V_49 ;
if ( V_47 == 0 )
goto V_50;
V_68 = F_52 ( & V_42 , & V_69 ) ;
if ( V_68 ) {
F_36 ( L_2 ) ;
goto V_50;
}
V_58 . V_60 . V_73 = ( V_69 != 0 ) ;
V_68 = F_52 ( & V_42 , & V_69 ) ;
if ( V_68 ) {
F_36 ( L_3 ) ;
goto V_50;
}
V_58 . V_60 . V_74 = ( V_69 != 0 ) ;
V_68 = F_52 ( & V_42 , & V_69 ) ;
if ( V_68 ) {
F_36 ( L_4 ) ;
goto V_50;
}
V_58 . V_60 . V_75 = ( V_69 != 0 ) ;
V_68 = F_52 ( & V_42 , & V_69 ) ;
if ( V_68 ) {
F_36 ( L_3 ) ;
goto V_50;
}
V_58 . V_60 . V_76 = ( V_69 != 0 ) ;
V_68 = F_52 ( & V_42 , ( int * ) & V_58 . V_60 . V_77 ) ;
if ( V_68 ) {
F_36 ( L_5 ) ;
goto V_50;
}
V_70 = F_53 ( & V_58 ) ;
if ( ! V_70 )
goto V_50;
V_68 = F_52 ( & V_42 , ( int * ) & V_58 . V_60 . V_78 ) ;
if ( V_68 == - V_49 )
goto V_50;
if ( V_68 == - V_79 ) {
F_36 ( L_6 ) ;
F_54 ( V_80 , & V_58 . V_24 . V_52 ) ;
} else {
T_3 V_81 ;
unsigned long V_82 ;
if ( F_52 ( & V_42 , ( int * ) & V_58 . V_60 . V_83 ) )
goto V_50;
V_9 = F_28 ( & V_42 , V_4 , V_43 ) ;
if ( V_9 < 0 )
goto V_50;
V_72 = F_55 ( V_4 ) ;
V_48 = - V_84 ;
if ( ! V_72 )
goto V_50;
V_48 = - V_49 ;
V_9 = F_28 ( & V_42 , V_4 , V_43 ) ;
if ( V_9 < 0 )
goto V_50;
V_81 . V_9 = V_9 ;
V_81 . V_15 = ( unsigned char * ) V_4 ;
if ( F_56 ( & V_81 , V_72 ,
& V_58 . V_60 . V_62 ) )
goto V_50;
if ( F_57 ( V_58 . V_60 . V_62 , & V_82 ) ) {
F_36 ( L_7 ) ;
goto V_50;
}
V_47 = ( T_2 ) V_82 ;
}
V_58 . V_24 . V_53 = V_47 ;
V_70 = F_58 ( & V_58 , V_70 ) ;
V_48 = 0 ;
V_50:
if ( V_72 )
F_59 ( V_72 ) ;
F_39 ( & V_58 ) ;
if ( V_70 )
F_35 ( & V_70 -> V_24 , & V_85 ) ;
else
V_48 = - V_51 ;
if ( V_48 )
F_36 ( L_8 , V_48 ) ;
return V_48 ;
}
static struct V_57 * F_53 ( struct V_57 * V_13 )
{
struct V_23 * V_55 ;
int V_7 = F_41 ( V_13 ) ;
V_55 = F_37 ( & V_85 , & V_13 -> V_24 , V_7 ) ;
if ( V_55 )
return F_12 ( V_55 , struct V_57 , V_24 ) ;
else
return NULL ;
}
static struct V_57 * F_58 ( struct V_57 * V_30 , struct V_57 * V_56 )
{
struct V_23 * V_55 ;
int V_7 = F_41 ( V_30 ) ;
V_55 = F_38 ( & V_85 , & V_30 -> V_24 , & V_56 -> V_24 , V_7 ) ;
if ( V_55 )
return F_12 ( V_55 , struct V_57 , V_24 ) ;
else
return NULL ;
}
static void F_60 ( T_4 * V_86 , long V_15 )
{
struct V_23 * * V_55 ;
struct V_57 * V_70 ;
int V_87 ;
F_61 ( & V_85 . V_88 ) ;
for ( V_87 = 0 ; V_87 < V_89 ; V_87 ++ ) {
for ( V_55 = & V_85 . V_90 [ V_87 ] ; * V_55 ; ) {
V_70 = F_12 ( * V_55 , struct V_57 , V_24 ) ;
if ( ! V_86 ( V_70 , V_15 ) ) {
V_55 = & ( ( * V_55 ) -> V_37 ) ;
continue;
}
* V_55 = ( * V_55 ) -> V_37 ;
V_70 -> V_24 . V_37 = NULL ;
F_62 ( & V_70 -> V_24 ) ;
F_54 ( V_80 , & V_70 -> V_24 . V_52 ) ;
F_63 ( & V_70 -> V_24 , & V_85 ) ;
V_85 . V_91 -- ;
}
}
F_64 ( & V_85 . V_88 ) ;
}
static int F_65 ( struct V_57 * V_70 , long V_92 )
{
if ( ( int ) V_92 == - 1 )
return 1 ;
return ( ( int ) V_70 -> V_60 . V_78 == ( int ) V_92 ) ;
}
static int F_66 ( struct V_57 * V_70 , long V_64 )
{
return ( V_70 -> V_64 == (struct V_93 * ) V_64 ) ;
}
static inline void F_67 ( int V_92 )
{
if ( V_92 == - 1 )
F_68 ( L_9 ) ;
F_60 ( F_65 , ( long ) V_92 ) ;
}
static inline void F_69 ( struct V_93 * V_64 )
{
F_60 ( F_66 , ( long ) V_64 ) ;
}
void F_70 ( struct V_93 * V_64 )
{
F_69 ( V_64 ) ;
}
static struct V_57 * F_71 ( T_3 * V_59 )
{
struct V_57 V_58 ;
struct V_57 * V_94 ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
if ( F_72 ( & V_58 . V_59 , V_59 ) )
return NULL ;
V_94 = F_53 ( & V_58 ) ;
F_39 ( & V_58 ) ;
if ( ! V_94 )
return NULL ;
if ( F_73 ( & V_85 , & V_94 -> V_24 , NULL ) )
return NULL ;
return V_94 ;
}
int F_74 ( struct V_95 * V_96 ,
struct V_97 * V_98 ,
struct V_99 * V_100 )
{
struct V_57 V_58 , * V_70 = NULL ;
unsigned long V_82 ;
T_5 V_101 ;
int V_102 ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
if ( F_29 ( & V_58 . V_59 , ( char * ) & V_98 -> V_103 ,
sizeof( V_98 -> V_103 ) ) )
GOTO ( V_50 , V_102 = - V_51 ) ;
V_70 = F_53 ( & V_58 ) ;
if ( V_70 == NULL )
GOTO ( V_50 , V_102 = - V_51 ) ;
V_101 = F_75 ( V_100 -> V_104 ,
& V_58 . V_60 . V_62 ) ;
if ( V_101 != V_105 )
GOTO ( V_50 , V_102 = - V_51 ) ;
if ( F_57 ( V_58 . V_60 . V_62 , & V_82 ) ) {
F_36 ( L_7 ) ;
GOTO ( V_50 , V_102 = - V_49 ) ;
}
V_58 . V_24 . V_53 = ( T_2 ) V_82 ;
if ( strcmp ( V_96 -> V_106 -> V_107 -> V_108 , V_109 ) == 0 )
V_58 . V_60 . V_75 = 1 ;
else if ( strcmp ( V_96 -> V_106 -> V_107 -> V_108 , V_110 ) == 0 )
V_58 . V_60 . V_76 = 1 ;
else
V_58 . V_60 . V_74 = 1 ;
V_70 = F_58 ( & V_58 , V_70 ) ;
if ( V_70 == NULL )
GOTO ( V_50 , V_102 = - V_51 ) ;
V_70 -> V_64 = V_96 -> V_106 ;
F_72 ( & V_100 -> V_111 , & V_70 -> V_59 ) ;
F_68 ( L_10 V_112 L_11 ,
& V_70 -> V_60 , F_76 ( V_96 -> V_106 ) , V_98 -> V_103 ) ;
V_102 = 0 ;
V_50:
if ( V_70 )
F_35 ( & V_70 -> V_24 , & V_85 ) ;
F_39 ( & V_58 ) ;
if ( V_102 )
F_36 ( L_12 V_112 L_13 ,
V_98 -> V_103 , V_102 ) ;
return V_102 ;
}
int F_77 ( T_3 * V_59 )
{
const T_6 V_113 = 20 ;
struct V_57 * V_70 ;
V_70 = F_71 ( V_59 ) ;
if ( V_70 ) {
F_78 ( V_114 , L_14 ,
& V_70 -> V_60 , V_70 ) ;
V_70 -> V_24 . V_53 = F_79 () + V_113 ;
F_63 ( & V_70 -> V_24 , & V_85 ) ;
}
return 0 ;
}
int F_80 ( T_3 * V_59 , struct V_115 * V_60 )
{
struct V_57 * V_70 = F_12 ( V_60 , struct V_57 , V_60 ) ;
return F_72 ( V_59 , & V_70 -> V_59 ) ;
}
int F_81 ( T_3 * V_59 , T_5 V_116 )
{
struct V_57 * V_70 ;
V_70 = F_71 ( V_59 ) ;
if ( V_70 ) {
F_78 ( V_114 , L_15 ,
& V_70 -> V_60 , V_70 , V_116 + 1 ) ;
V_70 -> V_60 . V_117 = V_116 + 1 ;
F_63 ( & V_70 -> V_24 , & V_85 ) ;
}
return 0 ;
}
static struct V_118 * F_82 ( struct V_119 * V_120 )
{
return NULL ;
}
int F_83 ( struct V_121 * V_120 ,
struct V_122 * V_123 ,
struct V_124 * V_125 ,
struct V_93 * V_64 ,
T_5 V_28 ,
T_3 * V_126 ,
T_3 * V_17 )
{
struct V_127 * V_128 ;
struct V_57 * V_58 = NULL ;
struct V_12 * V_46 = NULL , V_129 ;
T_7 V_130 ;
int V_131 = sizeof( struct V_132 ) ;
struct V_133 * V_134 ;
int V_135 = 1 ;
int V_102 = V_136 ;
memset ( & V_129 , 0 , sizeof( V_129 ) ) ;
V_129 . V_28 = V_28 ;
V_129 . V_29 = ( T_1 ) V_120 -> V_137 . V_29 ;
if ( F_72 ( & V_129 . V_14 , & V_125 -> V_138 ) ) {
F_36 ( L_16 ) ;
GOTO ( V_50 , V_102 ) ;
}
if ( F_72 ( & V_129 . V_17 , V_17 ) ) {
F_36 ( L_17 ) ;
F_10 ( & V_129 . V_14 ) ;
GOTO ( V_50 , V_102 ) ;
}
V_46 = F_30 ( & V_129 ) ;
F_9 ( & V_129 ) ;
if ( ! V_46 ) {
F_36 ( L_18 ) ;
if ( ! F_84 ( V_120 , V_139 , 0 ) )
V_102 = V_140 ;
GOTO ( V_50 , V_102 ) ;
}
F_62 ( & V_46 -> V_24 ) ;
F_17 ( & V_46 -> V_32 ) ;
F_85 ( & V_130 ) ;
F_86 ( & V_46 -> V_32 , & V_130 ) ;
F_73:
V_102 = F_73 ( & V_54 , & V_46 -> V_24 , & V_141 ) ;
switch ( V_102 ) {
case - V_142 : {
int V_143 ;
if ( V_135 ) {
V_135 = 0 ;
F_87 ( & V_54 . V_88 ) ;
V_143 = F_88 ( V_144 , & V_46 -> V_24 . V_52 ) ;
if ( V_143 == 0 )
F_89 ( V_145 ) ;
F_90 ( & V_54 . V_88 ) ;
if ( V_143 == 0 )
F_91 ( V_146 *
V_147 ) ;
F_62 ( & V_46 -> V_24 ) ;
goto F_73;
}
F_68 ( L_19 , V_146 ) ;
break;
}
case - V_79 :
F_68 ( L_20 ) ;
break;
case 0 :
if ( ! V_135 )
F_35 ( & V_46 -> V_24 , & V_54 ) ;
F_78 ( V_114 , L_21 ) ;
break;
}
F_92 ( & V_46 -> V_32 , & V_130 ) ;
F_35 ( & V_46 -> V_24 , & V_54 ) ;
if ( V_102 )
GOTO ( V_50 , V_102 = V_136 ) ;
V_102 = V_136 ;
V_58 = F_71 ( & V_46 -> V_19 ) ;
if ( ! V_58 ) {
F_36 ( L_22 ) ;
if ( ! F_84 ( V_120 , V_139 , 0 ) )
V_102 = V_140 ;
GOTO ( V_50 , V_102 ) ;
} else {
F_62 ( & V_58 -> V_24 ) ;
V_123 -> V_148 = & V_58 -> V_60 ;
}
if ( F_72 ( & V_58 -> V_60 . V_61 , V_126 ) ) {
F_36 ( L_23 ) ;
GOTO ( V_50 , V_102 ) ;
}
V_58 -> V_64 = V_64 ;
F_78 ( V_114 , L_24 ,
V_58 , V_58 -> V_60 . V_78 , F_93 ( V_120 -> V_137 . V_29 ) ) ;
if ( V_46 -> V_19 . V_9 > V_149 ) {
F_36 ( L_25 , V_46 -> V_19 . V_9 ) ;
GOTO ( V_50 , V_102 = V_136 ) ;
}
V_123 -> V_150 = 1 ;
V_123 -> V_151 = F_94 ( V_46 -> V_20 . V_9 ) ;
V_102 = F_95 ( V_120 , 1 , & V_131 , NULL , 0 ) ;
if ( V_102 ) {
F_36 ( L_26 , V_102 ) ;
GOTO ( V_50 , V_102 = V_136 ) ;
}
V_128 = V_120 -> V_152 ;
F_19 ( V_128 -> V_153 -> V_154 == 3 ) ;
F_19 ( V_128 -> V_153 -> V_155 [ 0 ] >=
sizeof( * V_134 ) + V_46 -> V_19 . V_9 ) ;
F_19 ( V_128 -> V_153 -> V_155 [ 2 ] >= V_46 -> V_20 . V_9 ) ;
V_134 = F_96 ( V_128 -> V_153 , 0 , 0 ) ;
V_134 -> V_156 = V_157 ;
V_134 -> V_158 = 0 ;
V_134 -> V_159 = V_160 ;
V_134 -> V_161 = V_46 -> V_33 ;
V_134 -> V_162 = V_46 -> V_34 ;
V_134 -> V_163 = V_164 ;
V_134 -> V_165 . V_9 = V_46 -> V_19 . V_9 ;
memcpy ( V_134 -> V_165 . V_15 , V_46 -> V_19 . V_15 ,
V_46 -> V_19 . V_9 ) ;
memcpy ( F_96 ( V_128 -> V_153 , 2 , 0 ) , V_46 -> V_20 . V_15 ,
V_46 -> V_20 . V_9 ) ;
V_128 -> V_166 = F_97 ( V_128 -> V_153 , 2 ,
V_46 -> V_20 . V_9 , 0 ) ;
V_102 = V_167 ;
V_50:
#if 0
if (rsip)
rsi_put(&rsip->h, &rsi_cache);
#endif
if ( V_58 ) {
if ( V_102 != V_167 )
F_54 ( V_80 , & V_58 -> V_24 . V_52 ) ;
else
F_78 ( V_114 , L_27 V_112 L_11 ,
F_98 ( & V_58 -> V_59 ) ) ;
F_63 ( & V_58 -> V_24 , & V_85 ) ;
}
return V_102 ;
}
struct V_115 * F_99 ( struct V_121 * V_120 ,
struct V_124 * V_125 )
{
struct V_57 * V_57 ;
V_57 = F_71 ( & V_125 -> V_138 ) ;
if ( ! V_57 ) {
F_68 ( L_28 V_112 L_29 ,
F_98 ( & V_125 -> V_138 ) ,
F_93 ( V_120 -> V_137 . V_29 ) ) ;
return NULL ;
}
return & V_57 -> V_60 ;
}
void F_100 ( struct V_115 * V_60 )
{
struct V_57 * V_57 = F_12 ( V_60 , struct V_57 , V_60 ) ;
F_63 ( & V_57 -> V_24 , & V_85 ) ;
}
void F_101 ( struct V_115 * V_60 )
{
struct V_57 * V_57 = F_12 ( V_60 , struct V_57 , V_60 ) ;
F_54 ( V_80 , & V_57 -> V_24 . V_52 ) ;
V_57 -> V_24 . V_53 = 1 ;
}
int T_8 F_102 ( void )
{
int V_168 ;
F_45 ( & V_2 ) ;
F_103 ( & V_3 , sizeof( V_3 ) ) ;
F_104 ( & V_54 ) ;
F_104 ( & V_85 ) ;
for ( V_168 = 0 ; V_168 < 6 ; V_168 ++ ) {
if ( F_105 ( & V_54 . V_169 ) > 0 )
break;
F_89 ( V_170 ) ;
F_19 ( V_147 >= 4 ) ;
F_91 ( V_147 / 4 ) ;
}
if ( F_105 ( & V_54 . V_169 ) == 0 )
F_68 ( L_30
L_31 ) ;
return 0 ;
}
void T_9 F_106 ( void )
{
F_107 ( & V_54 ) ;
F_108 ( & V_54 ) ;
F_107 ( & V_85 ) ;
F_108 ( & V_85 ) ;
}
