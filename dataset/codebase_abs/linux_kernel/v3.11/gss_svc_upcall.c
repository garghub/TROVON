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
V_50 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_9 = F_28 ( & V_42 , V_4 , V_43 ) ;
if ( V_9 < 0 )
goto V_51;
if ( F_29 ( & V_45 . V_14 , V_4 , V_9 ) ) {
V_48 = - V_52 ;
goto V_51;
}
V_9 = F_28 ( & V_42 , V_4 , V_43 ) ;
if ( V_9 < 0 )
goto V_51;
if ( F_29 ( & V_45 . V_17 , V_4 , V_9 ) ) {
V_48 = - V_52 ;
goto V_51;
}
V_46 = F_30 ( & V_45 ) ;
if ( ! V_46 )
goto V_51;
V_45 . V_24 . V_53 = 0 ;
V_47 = F_31 ( & V_42 ) ;
if ( V_47 == 0 )
goto V_51;
V_9 = F_28 ( & V_42 , V_4 , V_43 ) ;
if ( V_9 <= 0 )
goto V_51;
V_45 . V_33 = F_32 ( V_4 , & V_44 , 10 ) ;
if ( * V_44 )
goto V_51;
V_9 = F_28 ( & V_42 , V_4 , V_43 ) ;
if ( V_9 <= 0 )
goto V_51;
V_45 . V_34 = F_32 ( V_4 , & V_44 , 10 ) ;
if ( * V_44 )
goto V_51;
V_9 = F_28 ( & V_42 , V_4 , V_43 ) ;
if ( V_9 < 0 )
goto V_51;
if ( F_29 ( & V_45 . V_19 , V_4 , V_9 ) ) {
V_48 = - V_52 ;
goto V_51;
}
V_9 = F_28 ( & V_42 , V_4 , V_43 ) ;
if ( V_9 < 0 )
goto V_51;
if ( F_29 ( & V_45 . V_20 , V_4 , V_9 ) ) {
V_48 = - V_52 ;
goto V_51;
}
V_45 . V_24 . V_54 = V_47 ;
V_46 = F_33 ( & V_45 , V_46 ) ;
V_48 = 0 ;
V_51:
F_9 ( & V_45 ) ;
if ( V_46 ) {
F_34 ( & V_46 -> V_32 ) ;
F_35 ( & V_46 -> V_24 , & V_55 ) ;
} else {
V_48 = - V_52 ;
}
if ( V_48 )
F_36 ( L_1 , V_48 ) ;
RETURN ( V_48 ) ;
}
static struct V_12 * F_30 ( struct V_12 * V_13 )
{
struct V_23 * V_56 ;
int V_7 = F_6 ( V_13 ) ;
V_56 = F_37 ( & V_55 , & V_13 -> V_24 , V_7 ) ;
if ( V_56 )
return F_12 ( V_56 , struct V_12 , V_24 ) ;
else
return NULL ;
}
static struct V_12 * F_33 ( struct V_12 * V_30 , struct V_12 * V_57 )
{
struct V_23 * V_56 ;
int V_7 = F_6 ( V_30 ) ;
V_56 = F_38 ( & V_55 , & V_30 -> V_24 , & V_57 -> V_24 , V_7 ) ;
if ( V_56 )
return F_12 ( V_56 , struct V_12 , V_24 ) ;
else
return NULL ;
}
static void F_39 ( struct V_58 * V_59 )
{
F_10 ( & V_59 -> V_60 ) ;
F_10 ( & V_59 -> V_61 . V_62 ) ;
F_40 ( & V_59 -> V_61 . V_63 ) ;
}
static inline int F_41 ( struct V_58 * V_59 )
{
return F_4 ( ( char * ) V_59 -> V_60 . V_15 ,
V_59 -> V_60 . V_9 , V_64 ) ;
}
static inline int F_42 ( struct V_58 * V_30 , struct V_58 * V_18 )
{
return F_8 ( & V_30 -> V_60 , & V_18 -> V_60 ) ;
}
static inline void F_43 ( struct V_58 * V_30 , struct V_58 * V_18 )
{
V_30 -> V_60 = V_18 -> V_60 ;
V_18 -> V_60 = V_31 ;
V_30 -> V_65 = NULL ;
memset ( & V_30 -> V_61 , 0 , sizeof( V_30 -> V_61 ) ) ;
V_30 -> V_61 . V_62 = V_31 ;
}
static inline void F_44 ( struct V_58 * V_30 , struct V_58 * V_18 )
{
V_30 -> V_61 = V_18 -> V_61 ;
V_18 -> V_61 . V_62 = V_31 ;
V_18 -> V_61 . V_63 = NULL ;
memset ( & V_30 -> V_61 . V_66 , 0 , sizeof( V_30 -> V_61 . V_66 ) ) ;
F_45 ( & V_30 -> V_61 . V_66 . V_67 ) ;
}
static void F_46 ( struct V_35 * V_36 )
{
struct V_58 * V_59 = F_12 ( V_36 , struct V_58 , V_24 . V_36 ) ;
F_19 ( V_59 -> V_24 . V_37 == NULL ) ;
F_39 ( V_59 ) ;
F_21 ( V_59 ) ;
}
static int F_47 ( struct V_23 * V_38 , struct V_23 * V_39 )
{
struct V_58 * V_30 = F_12 ( V_38 , struct V_58 , V_24 ) ;
struct V_58 * V_18 = F_12 ( V_39 , struct V_58 , V_24 ) ;
return F_42 ( V_30 , V_18 ) ;
}
static void F_48 ( struct V_23 * V_40 , struct V_23 * V_68 )
{
struct V_58 * V_30 = F_12 ( V_40 , struct V_58 , V_24 ) ;
struct V_58 * V_18 = F_12 ( V_68 , struct V_58 , V_24 ) ;
F_43 ( V_30 , V_18 ) ;
}
static void F_49 ( struct V_23 * V_40 , struct V_23 * V_68 )
{
struct V_58 * V_30 = F_12 ( V_40 , struct V_58 , V_24 ) ;
struct V_58 * V_18 = F_12 ( V_68 , struct V_58 , V_24 ) ;
F_44 ( V_30 , V_18 ) ;
}
static struct V_23 * F_50 ( void )
{
struct V_58 * V_58 ;
F_26 ( V_58 ) ;
if ( V_58 )
return & V_58 -> V_24 ;
else
return NULL ;
}
static int F_51 ( struct V_21 * V_22 , char * V_42 , int V_43 )
{
char * V_4 = V_42 ;
int V_9 , V_69 , V_70 ;
struct V_58 V_59 , * V_71 = NULL ;
T_2 V_47 ;
int V_48 = - V_49 ;
struct V_72 * V_73 = NULL ;
memset ( & V_59 , 0 , sizeof( V_59 ) ) ;
V_9 = F_28 ( & V_42 , V_4 , V_43 ) ;
if ( V_9 < 0 ) goto V_51;
V_48 = - V_52 ;
if ( F_29 ( & V_59 . V_60 , V_4 , V_9 ) )
goto V_51;
V_59 . V_24 . V_53 = 0 ;
V_47 = F_31 ( & V_42 ) ;
V_48 = - V_49 ;
if ( V_47 == 0 )
goto V_51;
V_69 = F_52 ( & V_42 , & V_70 ) ;
if ( V_69 ) {
F_36 ( L_2 ) ;
goto V_51;
}
V_59 . V_61 . V_74 = ( V_70 != 0 ) ;
V_69 = F_52 ( & V_42 , & V_70 ) ;
if ( V_69 ) {
F_36 ( L_3 ) ;
goto V_51;
}
V_59 . V_61 . V_75 = ( V_70 != 0 ) ;
V_69 = F_52 ( & V_42 , & V_70 ) ;
if ( V_69 ) {
F_36 ( L_4 ) ;
goto V_51;
}
V_59 . V_61 . V_76 = ( V_70 != 0 ) ;
V_69 = F_52 ( & V_42 , & V_70 ) ;
if ( V_69 ) {
F_36 ( L_3 ) ;
goto V_51;
}
V_59 . V_61 . V_77 = ( V_70 != 0 ) ;
V_69 = F_52 ( & V_42 , ( int * ) & V_59 . V_61 . V_78 ) ;
if ( V_69 ) {
F_36 ( L_5 ) ;
goto V_51;
}
V_71 = F_53 ( & V_59 ) ;
if ( ! V_71 )
goto V_51;
V_69 = F_52 ( & V_42 , ( int * ) & V_59 . V_61 . V_79 ) ;
if ( V_69 == - V_49 )
goto V_51;
if ( V_69 == - V_80 ) {
F_36 ( L_6 ) ;
F_54 ( V_81 , & V_59 . V_24 . V_53 ) ;
} else {
T_3 V_82 ;
unsigned long V_83 ;
if ( F_52 ( & V_42 , ( int * ) & V_59 . V_61 . V_84 ) )
goto V_51;
V_9 = F_28 ( & V_42 , V_4 , V_43 ) ;
if ( V_9 < 0 )
goto V_51;
V_73 = F_55 ( V_4 ) ;
V_48 = - V_85 ;
if ( ! V_73 )
goto V_51;
V_48 = - V_49 ;
V_9 = F_28 ( & V_42 , V_4 , V_43 ) ;
if ( V_9 < 0 )
goto V_51;
V_82 . V_9 = V_9 ;
V_82 . V_15 = ( unsigned char * ) V_4 ;
if ( F_56 ( & V_82 , V_73 ,
& V_59 . V_61 . V_63 ) )
goto V_51;
if ( F_57 ( V_59 . V_61 . V_63 , & V_83 ) ) {
F_36 ( L_7 ) ;
goto V_51;
}
V_47 = ( T_2 ) V_83 ;
}
V_59 . V_24 . V_54 = V_47 ;
V_71 = F_58 ( & V_59 , V_71 ) ;
V_48 = 0 ;
V_51:
if ( V_73 )
F_59 ( V_73 ) ;
F_39 ( & V_59 ) ;
if ( V_71 )
F_35 ( & V_71 -> V_24 , & V_86 ) ;
else
V_48 = - V_52 ;
if ( V_48 )
F_36 ( L_8 , V_48 ) ;
return V_48 ;
}
static struct V_58 * F_53 ( struct V_58 * V_13 )
{
struct V_23 * V_56 ;
int V_7 = F_41 ( V_13 ) ;
V_56 = F_37 ( & V_86 , & V_13 -> V_24 , V_7 ) ;
if ( V_56 )
return F_12 ( V_56 , struct V_58 , V_24 ) ;
else
return NULL ;
}
static struct V_58 * F_58 ( struct V_58 * V_30 , struct V_58 * V_57 )
{
struct V_23 * V_56 ;
int V_7 = F_41 ( V_30 ) ;
V_56 = F_38 ( & V_86 , & V_30 -> V_24 , & V_57 -> V_24 , V_7 ) ;
if ( V_56 )
return F_12 ( V_56 , struct V_58 , V_24 ) ;
else
return NULL ;
}
static void F_60 ( T_4 * V_87 , long V_15 )
{
struct V_23 * * V_56 ;
struct V_58 * V_71 ;
int V_88 ;
V_50 ;
F_61 ( & V_86 . V_89 ) ;
for ( V_88 = 0 ; V_88 < V_90 ; V_88 ++ ) {
for ( V_56 = & V_86 . V_91 [ V_88 ] ; * V_56 ; ) {
V_71 = F_12 ( * V_56 , struct V_58 , V_24 ) ;
if ( ! V_87 ( V_71 , V_15 ) ) {
V_56 = & ( ( * V_56 ) -> V_37 ) ;
continue;
}
* V_56 = ( * V_56 ) -> V_37 ;
V_71 -> V_24 . V_37 = NULL ;
F_62 ( & V_71 -> V_24 ) ;
F_54 ( V_81 , & V_71 -> V_24 . V_53 ) ;
F_63 ( & V_71 -> V_24 , & V_86 ) ;
V_86 . V_92 -- ;
}
}
F_64 ( & V_86 . V_89 ) ;
EXIT ;
}
static int F_65 ( struct V_58 * V_71 , long V_93 )
{
if ( ( int ) V_93 == - 1 )
return 1 ;
return ( ( int ) V_71 -> V_61 . V_79 == ( int ) V_93 ) ;
}
static int F_66 ( struct V_58 * V_71 , long V_65 )
{
return ( V_71 -> V_65 == (struct V_94 * ) V_65 ) ;
}
static inline void F_67 ( int V_93 )
{
if ( V_93 == - 1 )
F_68 ( L_9 ) ;
F_60 ( F_65 , ( long ) V_93 ) ;
}
static inline void F_69 ( struct V_94 * V_65 )
{
F_60 ( F_66 , ( long ) V_65 ) ;
}
void F_70 ( struct V_94 * V_65 )
{
F_69 ( V_65 ) ;
}
static struct V_58 * F_71 ( T_3 * V_60 )
{
struct V_58 V_59 ;
struct V_58 * V_95 ;
memset ( & V_59 , 0 , sizeof( V_59 ) ) ;
if ( F_72 ( & V_59 . V_60 , V_60 ) )
return NULL ;
V_95 = F_53 ( & V_59 ) ;
F_39 ( & V_59 ) ;
if ( ! V_95 )
return NULL ;
if ( F_73 ( & V_86 , & V_95 -> V_24 , NULL ) )
return NULL ;
return V_95 ;
}
int F_74 ( struct V_96 * V_97 ,
struct V_98 * V_99 ,
struct V_100 * V_101 )
{
struct V_58 V_59 , * V_71 = NULL ;
unsigned long V_83 ;
T_5 V_102 ;
int V_103 ;
V_50 ;
memset ( & V_59 , 0 , sizeof( V_59 ) ) ;
if ( F_29 ( & V_59 . V_60 , ( char * ) & V_99 -> V_104 ,
sizeof( V_99 -> V_104 ) ) )
GOTO ( V_51 , V_103 = - V_52 ) ;
V_71 = F_53 ( & V_59 ) ;
if ( V_71 == NULL )
GOTO ( V_51 , V_103 = - V_52 ) ;
V_102 = F_75 ( V_101 -> V_105 ,
& V_59 . V_61 . V_63 ) ;
if ( V_102 != V_106 )
GOTO ( V_51 , V_103 = - V_52 ) ;
if ( F_57 ( V_59 . V_61 . V_63 , & V_83 ) ) {
F_36 ( L_7 ) ;
GOTO ( V_51 , V_103 = - V_49 ) ;
}
V_59 . V_24 . V_54 = ( T_2 ) V_83 ;
if ( strcmp ( V_97 -> V_107 -> V_108 -> V_109 , V_110 ) == 0 )
V_59 . V_61 . V_76 = 1 ;
else if ( strcmp ( V_97 -> V_107 -> V_108 -> V_109 , V_111 ) == 0 )
V_59 . V_61 . V_77 = 1 ;
else
V_59 . V_61 . V_75 = 1 ;
V_71 = F_58 ( & V_59 , V_71 ) ;
if ( V_71 == NULL )
GOTO ( V_51 , V_103 = - V_52 ) ;
V_71 -> V_65 = V_97 -> V_107 ;
F_72 ( & V_101 -> V_112 , & V_71 -> V_60 ) ;
F_68 ( L_10 V_113 L_11 ,
& V_71 -> V_61 , F_76 ( V_97 -> V_107 ) , V_99 -> V_104 ) ;
V_103 = 0 ;
V_51:
if ( V_71 )
F_35 ( & V_71 -> V_24 , & V_86 ) ;
F_39 ( & V_59 ) ;
if ( V_103 )
F_36 ( L_12 V_113 L_13 ,
V_99 -> V_104 , V_103 ) ;
RETURN ( V_103 ) ;
}
int F_77 ( T_3 * V_60 )
{
const T_6 V_114 = 20 ;
struct V_58 * V_71 ;
V_71 = F_71 ( V_60 ) ;
if ( V_71 ) {
F_78 ( V_115 , L_14 ,
& V_71 -> V_61 , V_71 ) ;
V_71 -> V_24 . V_54 = F_79 () + V_114 ;
F_63 ( & V_71 -> V_24 , & V_86 ) ;
}
return 0 ;
}
int F_80 ( T_3 * V_60 , struct V_116 * V_61 )
{
struct V_58 * V_71 = F_12 ( V_61 , struct V_58 , V_61 ) ;
return F_72 ( V_60 , & V_71 -> V_60 ) ;
}
int F_81 ( T_3 * V_60 , T_5 V_117 )
{
struct V_58 * V_71 ;
V_71 = F_71 ( V_60 ) ;
if ( V_71 ) {
F_78 ( V_115 , L_15 ,
& V_71 -> V_61 , V_71 , V_117 + 1 ) ;
V_71 -> V_61 . V_118 = V_117 + 1 ;
F_63 ( & V_71 -> V_24 , & V_86 ) ;
}
return 0 ;
}
static struct V_119 * F_82 ( struct V_120 * V_121 )
{
return NULL ;
}
int F_83 ( struct V_122 * V_121 ,
struct V_123 * V_124 ,
struct V_125 * V_126 ,
struct V_94 * V_65 ,
T_5 V_28 ,
T_3 * V_127 ,
T_3 * V_17 )
{
struct V_128 * V_129 ;
struct V_58 * V_59 = NULL ;
struct V_12 * V_46 = NULL , V_130 ;
T_7 V_131 ;
int V_132 = sizeof( struct V_133 ) ;
struct V_134 * V_135 ;
int V_136 = 1 ;
int V_103 = V_137 ;
V_50 ;
memset ( & V_130 , 0 , sizeof( V_130 ) ) ;
V_130 . V_28 = V_28 ;
V_130 . V_29 = ( T_1 ) V_121 -> V_138 . V_29 ;
if ( F_72 ( & V_130 . V_14 , & V_126 -> V_139 ) ) {
F_36 ( L_16 ) ;
GOTO ( V_51 , V_103 ) ;
}
if ( F_72 ( & V_130 . V_17 , V_17 ) ) {
F_36 ( L_17 ) ;
F_10 ( & V_130 . V_14 ) ;
GOTO ( V_51 , V_103 ) ;
}
V_46 = F_30 ( & V_130 ) ;
F_9 ( & V_130 ) ;
if ( ! V_46 ) {
F_36 ( L_18 ) ;
if ( ! F_84 ( V_121 , V_140 , 0 ) )
V_103 = V_141 ;
GOTO ( V_51 , V_103 ) ;
}
F_62 ( & V_46 -> V_24 ) ;
F_17 ( & V_46 -> V_32 ) ;
F_85 ( & V_131 ) ;
F_86 ( & V_46 -> V_32 , & V_131 ) ;
F_73:
V_103 = F_73 ( & V_55 , & V_46 -> V_24 , & V_142 ) ;
switch ( V_103 ) {
case - V_143 : {
int V_144 ;
if ( V_136 ) {
V_136 = 0 ;
F_87 ( & V_55 . V_89 ) ;
V_144 = F_88 ( V_145 , & V_46 -> V_24 . V_53 ) ;
if ( V_144 == 0 )
F_89 ( V_146 ) ;
F_90 ( & V_55 . V_89 ) ;
if ( V_144 == 0 )
F_91 ( V_147 *
V_148 ) ;
F_62 ( & V_46 -> V_24 ) ;
goto F_73;
}
F_68 ( L_19 , V_147 ) ;
break;
}
case - V_80 :
F_68 ( L_20 ) ;
break;
case 0 :
if ( ! V_136 )
F_35 ( & V_46 -> V_24 , & V_55 ) ;
F_78 ( V_115 , L_21 ) ;
break;
}
F_92 ( & V_46 -> V_32 , & V_131 ) ;
F_35 ( & V_46 -> V_24 , & V_55 ) ;
if ( V_103 )
GOTO ( V_51 , V_103 = V_137 ) ;
V_103 = V_137 ;
V_59 = F_71 ( & V_46 -> V_19 ) ;
if ( ! V_59 ) {
F_36 ( L_22 ) ;
if ( ! F_84 ( V_121 , V_140 , 0 ) )
V_103 = V_141 ;
GOTO ( V_51 , V_103 ) ;
} else {
F_62 ( & V_59 -> V_24 ) ;
V_124 -> V_149 = & V_59 -> V_61 ;
}
if ( F_72 ( & V_59 -> V_61 . V_62 , V_127 ) ) {
F_36 ( L_23 ) ;
GOTO ( V_51 , V_103 ) ;
}
V_59 -> V_65 = V_65 ;
F_78 ( V_115 , L_24 ,
V_59 , V_59 -> V_61 . V_79 , F_93 ( V_121 -> V_138 . V_29 ) ) ;
if ( V_46 -> V_19 . V_9 > V_150 ) {
F_36 ( L_25 , V_46 -> V_19 . V_9 ) ;
GOTO ( V_51 , V_103 = V_137 ) ;
}
V_124 -> V_151 = 1 ;
V_124 -> V_152 = F_94 ( V_46 -> V_20 . V_9 ) ;
V_103 = F_95 ( V_121 , 1 , & V_132 , NULL , 0 ) ;
if ( V_103 ) {
F_36 ( L_26 , V_103 ) ;
GOTO ( V_51 , V_103 = V_137 ) ;
}
V_129 = V_121 -> V_153 ;
F_19 ( V_129 -> V_154 -> V_155 == 3 ) ;
F_19 ( V_129 -> V_154 -> V_156 [ 0 ] >=
sizeof( * V_135 ) + V_46 -> V_19 . V_9 ) ;
F_19 ( V_129 -> V_154 -> V_156 [ 2 ] >= V_46 -> V_20 . V_9 ) ;
V_135 = F_96 ( V_129 -> V_154 , 0 , 0 ) ;
V_135 -> V_157 = V_158 ;
V_135 -> V_159 = 0 ;
V_135 -> V_160 = V_161 ;
V_135 -> V_162 = V_46 -> V_33 ;
V_135 -> V_163 = V_46 -> V_34 ;
V_135 -> V_164 = V_165 ;
V_135 -> V_166 . V_9 = V_46 -> V_19 . V_9 ;
memcpy ( V_135 -> V_166 . V_15 , V_46 -> V_19 . V_15 ,
V_46 -> V_19 . V_9 ) ;
memcpy ( F_96 ( V_129 -> V_154 , 2 , 0 ) , V_46 -> V_20 . V_15 ,
V_46 -> V_20 . V_9 ) ;
V_129 -> V_167 = F_97 ( V_129 -> V_154 , 2 ,
V_46 -> V_20 . V_9 , 0 ) ;
V_103 = V_168 ;
V_51:
#if 0
if (rsip)
rsi_put(&rsip->h, &rsi_cache);
#endif
if ( V_59 ) {
if ( V_103 != V_168 )
F_54 ( V_81 , & V_59 -> V_24 . V_53 ) ;
else
F_78 ( V_115 , L_27 V_113 L_11 ,
F_98 ( & V_59 -> V_60 ) ) ;
F_63 ( & V_59 -> V_24 , & V_86 ) ;
}
RETURN ( V_103 ) ;
}
struct V_116 * F_99 ( struct V_122 * V_121 ,
struct V_125 * V_126 )
{
struct V_58 * V_58 ;
V_58 = F_71 ( & V_126 -> V_139 ) ;
if ( ! V_58 ) {
F_68 ( L_28 V_113 L_29 ,
F_98 ( & V_126 -> V_139 ) ,
F_93 ( V_121 -> V_138 . V_29 ) ) ;
return NULL ;
}
return & V_58 -> V_61 ;
}
void F_100 ( struct V_116 * V_61 )
{
struct V_58 * V_58 = F_12 ( V_61 , struct V_58 , V_61 ) ;
F_63 ( & V_58 -> V_24 , & V_86 ) ;
}
void F_101 ( struct V_116 * V_61 )
{
struct V_58 * V_58 = F_12 ( V_61 , struct V_58 , V_61 ) ;
F_54 ( V_81 , & V_58 -> V_24 . V_53 ) ;
V_58 -> V_24 . V_54 = 1 ;
}
int T_8 F_102 ( void )
{
int V_169 ;
F_45 ( & V_2 ) ;
F_103 ( & V_3 , sizeof( V_3 ) ) ;
F_104 ( & V_55 ) ;
F_104 ( & V_86 ) ;
for ( V_169 = 0 ; V_169 < 6 ; V_169 ++ ) {
if ( F_105 ( & V_55 . V_170 ) > 0 )
break;
F_89 ( V_171 ) ;
F_19 ( V_148 >= 4 ) ;
F_91 ( V_148 / 4 ) ;
}
if ( F_105 ( & V_55 . V_170 ) == 0 )
F_68 ( L_30
L_31 ) ;
return 0 ;
}
void T_9 F_106 ( void )
{
F_107 ( & V_55 ) ;
F_108 ( & V_55 ) ;
F_107 ( & V_86 ) ;
F_108 ( & V_86 ) ;
}
