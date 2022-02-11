void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = V_2 -> V_5 ;
V_2 -> V_6 -- ;
if ( V_2 -> V_6 == 0 ) {
if ( V_4 -> V_7 == V_2 )
V_4 -> V_7 = V_2 -> V_8 ;
if ( V_2 -> V_9 )
( V_2 -> V_9 ) -> V_8 = V_2 -> V_8 ;
if ( V_2 -> V_8 )
( V_2 -> V_8 ) -> V_9 = V_2 -> V_9 ;
F_2 ( V_2 ) ;
F_3 ( V_2 -> V_10 ) ;
if ( V_2 -> V_11 )
F_4 ( V_2 -> V_11 ) ;
F_3 ( V_2 ) ;
V_2 = NULL ;
}
}
int F_5 ( struct V_3 * * V_5 ,
struct V_12 * V_13 )
{
struct V_3 * V_14 ;
int V_15 = 0 ;
V_14 = F_6 ( sizeof( struct V_3 ) , V_16 ) ;
if ( V_5 != NULL ) {
if ( V_14 == NULL ) {
* V_5 = NULL ;
V_15 = - V_17 ;
} else {
V_14 -> V_18 = * V_13 ;
* V_5 = (struct V_3 * ) V_14 ;
}
}
return V_15 ;
}
void F_7 ( struct V_3 * V_19 )
{
struct V_3 * V_4 = (struct V_3 * ) V_19 ;
F_3 ( V_4 ) ;
}
void F_8 ( void )
{
}
bool F_9 ( struct V_1 * V_2 , char * V_20 ,
struct V_21 * * V_22 )
{
struct V_23 * V_24 ;
V_24 = (struct V_23 * ) F_10 ( V_2 -> V_11 , V_20 ) ;
if ( F_11 ( V_24 ) )
return false ;
* V_22 = & V_24 -> V_25 ;
F_12 ( V_26 , L_1 ,
V_27 , V_2 , V_20 , V_22 ) ;
return true ;
}
void F_13 ( struct V_3 * V_19 , struct V_12 * V_13 )
{
struct V_3 * V_4 = (struct V_3 * ) V_19 ;
if ( ( V_13 != NULL ) && ( V_4 != NULL ) )
* V_13 = V_4 -> V_18 ;
}
bool F_14 ( struct V_1 * V_2 , char * V_20 ,
struct V_21 * * V_22 )
{
struct V_23 * V_24 ;
char V_28 [ V_29 + 1 ] ;
V_28 [ 0 ] = '_' ;
strncpy ( V_28 + 1 , V_20 , sizeof( V_28 ) - 2 ) ;
V_28 [ V_29 ] = '\0' ;
V_24 = (struct V_23 * ) F_10 ( V_2 -> V_11 , V_28 ) ;
if ( F_11 ( V_24 ) )
return false ;
* V_22 = & V_24 -> V_25 ;
return true ;
}
int F_15 ( struct V_1 * V_30 , char * V_20 , T_1 * V_31 ,
T_1 * V_32 )
{
T_1 V_33 ;
bool V_34 = false ;
const struct V_35 * V_36 = NULL ;
struct V_1 * V_2 = (struct V_1 * ) V_30 ;
int V_15 = 0 ;
if ( V_2 != NULL ) {
if ( V_2 -> V_37 == NULL ) {
V_15 = F_16 ( V_2 ) ;
if ( ! V_15 )
V_34 = true ;
} else {
( * ( V_2 -> V_5 -> V_18 . fseek ) ) ( V_2 -> V_37 ,
V_2 -> V_38 ,
V_39 ) ;
}
} else {
V_15 = - V_40 ;
}
if ( ! V_15 ) {
V_33 = 1 ;
if ( F_17 ( V_2 -> V_41 , V_20 , & V_36 ) ) {
* V_31 = V_36 -> V_42 ;
* V_32 = V_36 -> V_43 * V_33 ;
if ( * V_32 % 2 )
( * V_32 ) ++ ;
* V_32 = F_18 ( * V_32 ) ;
} else {
V_15 = - V_44 ;
}
}
if ( V_34 ) {
F_2 ( V_2 ) ;
V_34 = false ;
}
F_12 ( V_26 , L_2 ,
V_27 , V_30 , V_20 , V_31 , V_32 , V_15 ) ;
return V_15 ;
}
bool F_19 ( void )
{
return true ;
}
int F_20 ( struct V_1 * V_30 , T_2 V_45 ,
struct V_12 * V_18 , T_1 * V_46 )
{
struct V_1 * V_2 = (struct V_1 * ) V_30 ;
struct V_3 * V_47 ;
bool V_48 = true ;
T_3 V_49 ;
int V_15 = 0 ;
bool V_34 = false ;
if ( V_2 -> V_50 == 0 || ! ( V_45 & V_51 ) ) {
V_47 = V_2 -> V_5 ;
V_47 -> V_18 = * V_18 ;
if ( V_2 -> V_11 == NULL ) {
V_48 = false ;
V_2 -> V_11 = F_21 ( sizeof( struct V_23 ) ,
V_52 ,
V_53 , V_54 ) ;
if ( F_11 ( V_2 -> V_11 ) ) {
V_15 = F_22 ( V_2 -> V_11 ) ;
V_2 -> V_11 = NULL ;
}
}
V_2 -> V_55 . V_56 . V_57 = V_58 ;
V_2 -> V_55 . V_56 . V_59 = V_60 ;
V_2 -> V_55 . V_30 = V_2 ;
V_2 -> V_61 . V_62 . V_63 =
V_64 ;
if ( V_48 ) {
V_2 -> V_61 . V_62 . V_65 =
V_66 ;
} else {
V_2 -> V_61 . V_62 . V_65 =
V_67 ;
}
V_2 -> V_61 . V_62 . V_68 =
V_69 ;
V_2 -> V_61 . V_62 . V_70 = V_71 ;
V_2 -> V_61 . V_62 . V_72 = V_73 ;
V_2 -> V_61 . V_62 . V_74 = V_75 ;
V_2 -> V_61 . V_30 = V_2 ;
V_2 -> V_71 . V_76 . V_70 = V_77 ;
V_2 -> V_71 . V_76 . V_72 = V_78 ;
V_2 -> V_71 . V_30 = V_2 ;
V_2 -> V_79 . V_80 . V_81 = V_81 ;
V_2 -> V_79 . V_80 . V_82 = V_83 ;
V_2 -> V_79 . V_80 . V_84 = V_85 ;
V_2 -> V_79 . V_80 . V_86 = V_87 ;
V_2 -> V_79 . V_80 . V_88 = V_88 ;
V_2 -> V_79 . V_80 . V_89 = V_89 ;
V_2 -> V_79 . V_30 = V_2 ;
if ( V_2 -> V_37 == NULL ) {
V_15 = F_16 ( V_2 ) ;
if ( ! V_15 )
V_34 = true ;
}
if ( ! V_15 ) {
V_2 -> V_38 = ( * ( V_2 -> V_5 -> V_18 . ftell ) )
( V_2 -> V_37 ) ;
( * ( V_2 -> V_5 -> V_18 . fseek ) ) ( V_2 -> V_37 ,
( long ) 0 ,
V_39 ) ;
V_90 = true ;
V_49 = F_23 ( & V_2 -> V_55 . V_56 ,
& V_2 -> V_61 . V_62 ,
& V_2 -> V_71 . V_76 ,
& V_2 -> V_79 . V_80 ,
V_91 ,
& V_2 -> V_92 ) ;
if ( V_49 != 0 ) {
V_15 = - V_93 ;
} else if ( V_94 ) {
V_2 -> V_50 ++ ;
F_24 ( V_2 , (struct V_12 * ) V_18 ) ;
V_94 = false ;
V_15 = - V_93 ;
} else {
* V_46 = V_2 -> V_46 ;
}
}
}
if ( ! V_15 )
V_2 -> V_50 ++ ;
if ( V_34 )
F_2 ( V_2 ) ;
F_12 ( V_26 , L_3 ,
V_27 , V_30 , V_45 , V_46 , V_15 ) ;
return V_15 ;
}
int F_25 ( struct V_3 * V_19 , char * V_95 , T_2 V_45 ,
struct V_1 * * V_96 )
{
struct V_3 * V_4 = (struct V_3 * ) V_19 ;
struct V_1 * V_2 = NULL ;
T_3 V_49 ;
int V_15 = 0 ;
V_2 = V_4 -> V_7 ;
while ( V_2 != NULL ) {
if ( strcmp ( V_2 -> V_10 , V_95 ) == 0 ) {
V_2 -> V_6 ++ ;
break;
}
V_2 = V_2 -> V_8 ;
}
if ( V_2 == NULL ) {
V_2 = F_6 ( sizeof( struct V_1 ) , V_16 ) ;
if ( V_2 == NULL ) {
V_15 = - V_17 ;
} else {
V_2 -> V_38 = 0 ;
V_2 -> V_6 ++ ;
V_2 -> V_5 = V_4 ;
V_2 -> V_10 = F_6 ( strlen ( V_95 ) + 1 ,
V_16 ) ;
if ( V_2 -> V_10 == NULL ) {
V_15 = - V_17 ;
} else {
strncpy ( V_2 -> V_10 , V_95 ,
strlen ( V_95 ) + 1 ) ;
}
V_2 -> V_11 = NULL ;
}
}
if ( V_15 )
goto V_97;
V_2 -> V_55 . V_56 . V_57 = V_58 ;
V_2 -> V_55 . V_56 . V_59 = V_60 ;
V_2 -> V_55 . V_30 = V_2 ;
V_2 -> V_61 . V_62 . V_65 = V_67 ;
V_2 -> V_61 . V_62 . V_63 = V_64 ;
V_2 -> V_61 . V_62 . V_68 = V_69 ;
V_2 -> V_61 . V_62 . V_70 = V_71 ;
V_2 -> V_61 . V_62 . V_72 = V_73 ;
V_2 -> V_61 . V_62 . V_74 = V_75 ;
V_2 -> V_61 . V_30 = V_2 ;
V_2 -> V_71 . V_76 . V_70 = V_77 ;
V_2 -> V_71 . V_76 . V_72 = V_78 ;
V_2 -> V_71 . V_30 = V_2 ;
V_2 -> V_79 . V_80 . V_81 = V_81 ;
V_2 -> V_79 . V_80 . V_82 = V_83 ;
V_2 -> V_79 . V_80 . V_84 = V_85 ;
V_2 -> V_79 . V_80 . V_86 = V_87 ;
V_2 -> V_79 . V_80 . V_88 = V_88 ;
V_2 -> V_79 . V_80 . V_89 = V_89 ;
V_2 -> V_79 . V_30 = V_2 ;
if ( ! V_15 && V_2 -> V_37 == NULL )
V_15 = F_16 ( V_2 ) ;
V_2 -> V_38 = ( * ( V_2 -> V_5 -> V_18 . ftell ) ) ( V_2 -> V_37 ) ;
( * ( V_2 -> V_5 -> V_18 . fseek ) ) ( V_2 -> V_37 , ( long ) 0 , V_39 ) ;
if ( V_2 -> V_11 != NULL || ! ( V_45 & V_98 ) )
goto V_97;
V_2 -> V_11 =
F_21 ( sizeof( struct V_23 ) , V_52 , V_53 ,
V_54 ) ;
if ( F_11 ( V_2 -> V_11 ) ) {
V_15 = F_22 ( V_2 -> V_11 ) ;
V_2 -> V_11 = NULL ;
} else {
V_2 -> V_79 . V_80 . V_84 = V_99 ;
V_49 = F_26 ( & V_2 -> V_55 . V_56 ,
& V_2 -> V_61 . V_62 ,
& V_2 -> V_71 . V_76 ,
& V_2 -> V_79 . V_80 , 0 ,
& V_2 -> V_92 ) ;
if ( V_49 != 0 ) {
V_15 = - V_93 ;
} else {
V_49 = F_27 ( V_2 -> V_92 ,
& V_2 -> V_61 . V_62 ,
& V_2 -> V_71 . V_76 ,
& V_2 -> V_79 . V_80 ) ;
if ( V_49 != 0 )
V_15 = - V_93 ;
V_2 -> V_92 = NULL ;
}
}
V_97:
if ( ! V_15 ) {
if ( V_2 -> V_6 == 1 ) {
if ( V_4 -> V_7 )
( V_4 -> V_7 ) -> V_9 = V_2 ;
V_2 -> V_9 = NULL ;
V_2 -> V_8 = V_4 -> V_7 ;
V_4 -> V_7 = V_2 ;
}
* V_96 = (struct V_1 * ) V_2 ;
} else {
* V_96 = NULL ;
if ( V_2 != NULL )
F_1 ( (struct V_1 * ) V_2 ) ;
}
F_12 ( V_26 , L_4 ,
V_27 , V_19 , V_95 , V_96 , V_15 ) ;
return V_15 ;
}
int F_28 ( struct V_1 * V_30 , char * V_20 ,
char * V_100 , T_1 V_43 )
{
struct V_1 * V_2 = (struct V_1 * ) V_30 ;
bool V_34 = false ;
T_1 V_33 ;
T_1 V_101 ;
const struct V_35 * V_36 = NULL ;
int V_15 = 0 ;
if ( V_2 != NULL ) {
if ( V_2 -> V_37 == NULL ) {
V_15 = F_16 ( V_2 ) ;
if ( ! V_15 )
V_34 = true ;
} else {
( * ( V_2 -> V_5 -> V_18 . fseek ) ) ( V_2 -> V_37 ,
V_2 -> V_38 ,
V_39 ) ;
}
} else {
V_15 = - V_40 ;
}
if ( V_15 )
goto V_97;
V_33 = 1 ;
if ( ! F_17 ( V_2 -> V_41 , V_20 , & V_36 ) ) {
V_15 = - V_44 ;
goto V_97;
}
V_101 = V_36 -> V_43 * V_33 ;
if ( V_101 % 2 )
V_101 ++ ;
V_101 = F_18 ( V_101 ) ;
if ( V_101 > V_43 ) {
V_15 = - V_102 ;
} else {
if ( ! F_29 ( V_2 -> V_41 , V_36 , V_100 ) )
V_15 = - V_103 ;
}
V_97:
if ( V_34 ) {
F_2 ( V_2 ) ;
V_34 = false ;
}
F_12 ( V_26 , L_5 ,
V_27 , V_30 , V_20 , V_100 , V_43 , V_15 ) ;
return V_15 ;
}
void F_24 ( struct V_1 * V_30 , struct V_12 * V_18 )
{
struct V_1 * V_2 = (struct V_1 * ) V_30 ;
T_3 V_49 = 0 ;
F_12 ( V_26 , L_6 , V_27 , V_30 ) ;
V_2 -> V_50 -- ;
if ( V_2 -> V_50 != 0 )
return;
V_2 -> V_5 -> V_18 = * V_18 ;
if ( V_2 -> V_92 ) {
V_49 = F_27 ( V_2 -> V_92 ,
& V_2 -> V_61 . V_62 ,
& V_2 -> V_71 . V_76 ,
& V_2 -> V_79 . V_80 ) ;
if ( V_49 != 0 )
F_12 ( V_26 , L_7 , V_27 , V_49 ) ;
}
if ( V_2 -> V_11 != NULL ) {
F_4 ( V_2 -> V_11 ) ;
V_2 -> V_11 = NULL ;
}
F_2 ( V_2 ) ;
}
static void F_2 ( struct V_1 * V_2 )
{
if ( V_2 -> V_41 ) {
F_30 ( V_2 -> V_41 ) ;
V_2 -> V_41 = NULL ;
}
if ( V_2 -> V_37 ) {
( V_2 -> V_5 -> V_18 . fclose ) ( V_2 -> V_37 ) ;
V_2 -> V_37 = NULL ;
}
}
static int F_16 ( struct V_1 * V_2 )
{
void * V_104 = * ( V_2 -> V_5 -> V_18 . fopen ) ;
int V_15 = 0 ;
V_2 -> V_37 =
( void * ) ( ( V_105 ) ( V_104 ) ) ( V_2 -> V_10 , L_8 ) ;
if ( V_2 -> V_37 && V_2 -> V_41 == NULL ) {
( * ( V_2 -> V_5 -> V_18 . fseek ) ) ( V_2 -> V_37 , ( long ) 0 ,
V_39 ) ;
V_2 -> V_41 =
F_31 ( & V_2 -> V_55 . V_56 ,
& V_2 -> V_61 . V_62 ) ;
if ( V_2 -> V_41 == NULL ) {
( V_2 -> V_5 -> V_18 . fclose ) ( V_2 -> V_37 ) ;
V_2 -> V_37 = NULL ;
V_15 = - V_103 ;
}
} else {
V_15 = - V_103 ;
}
return V_15 ;
}
static T_1 V_52 ( const void * V_106 )
{
T_1 V_107 ;
const char * V_20 = V_106 ;
V_107 = 0 ;
while ( * V_20 ) {
V_107 <<= 1 ;
V_107 ^= * V_20 ++ ;
}
return V_107 ;
}
static bool V_53 ( const void * V_106 , const void * V_108 )
{
if ( ( V_106 != NULL ) && ( V_108 != NULL ) ) {
if ( strcmp ( V_106 , ( (struct V_23 * ) V_108 ) -> V_20 ) == 0 )
return true ;
}
return false ;
}
static int V_99 ( struct V_109 * V_110 , void * V_111 ,
T_4 V_112 , struct V_35 * V_113 , unsigned V_114 )
{
return 1 ;
}
static void V_54 ( void * V_25 )
{
struct V_23 * V_108 = (struct V_23 * ) V_25 ;
F_3 ( V_108 -> V_20 ) ;
}
static int V_58 ( struct V_115 * V_116 , void * V_117 ,
unsigned V_118 )
{
struct V_119 * V_120 = (struct V_119 * ) V_116 ;
struct V_1 * V_30 ;
int V_121 = 0 ;
V_30 = V_120 -> V_30 ;
if ( V_30 != NULL ) {
V_121 =
( * ( V_30 -> V_5 -> V_18 . fread ) ) ( V_117 , 1 , V_118 ,
V_30 -> V_37 ) ;
}
return V_121 ;
}
static int V_60 ( struct V_115 * V_116 ,
unsigned int V_38 )
{
struct V_119 * V_120 = (struct V_119 * ) V_116 ;
struct V_1 * V_30 ;
int V_15 = 0 ;
V_30 = V_120 -> V_30 ;
if ( V_30 != NULL ) {
V_15 = ( * ( V_30 -> V_5 -> V_18 . fseek ) ) ( V_30 -> V_37 , ( long ) V_38 ,
V_39 ) ;
}
return V_15 ;
}
static struct V_122 * V_64 ( struct V_123 * V_116 ,
const char * V_20 )
{
struct V_122 * V_124 ;
struct V_125 * V_126 = (struct V_125 * ) V_116 ;
struct V_1 * V_30 ;
struct V_21 * V_127 = NULL ;
bool V_15 = false ;
V_30 = V_126 -> V_30 ;
if ( V_30 != NULL ) {
if ( V_30 -> V_5 -> V_18 . V_128 ) {
V_15 = ( * ( V_30 -> V_5 -> V_18 . V_128 ) )
( V_30 -> V_5 -> V_18 . V_129 ,
V_30 -> V_5 -> V_18 . V_130 ,
V_30 -> V_5 -> V_18 . V_131 , V_20 ,
& V_127 ) ;
} else {
V_15 = F_9 ( (struct V_1 * ) V_30 ,
( char * ) V_20 , & V_127 ) ;
if ( ! V_15 ) {
V_15 = F_14 (
(struct V_1 * )
V_30 , ( char * ) V_20 ,
& V_127 ) ;
}
}
}
if ( ! V_15 && V_132 )
F_12 ( V_26 , L_9 , V_27 , V_20 ) ;
V_124 = (struct V_122 * ) V_127 ;
return V_124 ;
}
static struct V_122 * V_66 ( struct V_123
* V_116 , const char * V_20 ,
unsigned V_133 )
{
struct V_125 * V_126 = (struct V_125 * ) V_116 ;
struct V_1 * V_30 ;
struct V_23 * V_24 ;
V_30 = V_126 -> V_30 ;
V_24 = (struct V_23 * ) F_10 ( V_30 -> V_11 , ( char * ) V_20 ) ;
if ( F_11 ( V_24 ) )
return NULL ;
return (struct V_122 * ) & V_24 -> V_25 ;
}
static struct V_122 * V_67 ( struct V_123
* V_116 , const char * V_20 ,
unsigned V_134 )
{
struct V_23 * V_135 = NULL ;
struct V_23 V_61 ;
struct V_122 * V_127 = NULL ;
struct V_125 * V_126 = (struct V_125 * ) V_116 ;
struct V_1 * V_30 ;
struct V_122 * V_136 ;
V_30 = V_126 -> V_30 ;
if ( ! ( V_30 -> V_5 -> V_18 . V_137 ) ) {
V_132 = false ;
V_127 = V_64 ( V_116 , V_20 ) ;
V_132 = true ;
if ( V_127 ) {
V_94 = true ;
F_12 ( V_26 , L_10 ,
V_20 ) ;
return NULL ;
}
}
V_61 . V_20 = F_6 ( strlen ( ( char * const ) V_20 ) + 1 , V_16 ) ;
if ( V_61 . V_20 == NULL )
return NULL ;
if ( V_61 . V_20 != NULL ) {
strncpy ( V_61 . V_20 , ( char * const ) V_20 ,
strlen ( ( char * const ) V_20 ) + 1 ) ;
V_135 =
(struct V_23 * ) F_32 ( V_30 -> V_11 , ( void * ) V_20 ,
( void * ) & V_61 ) ;
if ( F_11 ( V_135 ) ) {
F_3 ( V_61 . V_20 ) ;
V_135 = NULL ;
}
}
if ( V_135 != NULL )
V_136 = (struct V_122 * ) & V_135 -> V_25 ;
else
V_136 = NULL ;
return V_136 ;
}
static void V_69 ( struct V_123 * V_116 ,
unsigned V_134 )
{
struct V_125 * V_126 = (struct V_125 * ) V_116 ;
struct V_1 * V_30 ;
V_30 = V_126 -> V_30 ;
}
static void * V_71 ( struct V_123 * V_116 , unsigned V_138 )
{
struct V_125 * V_126 = (struct V_125 * ) V_116 ;
struct V_1 * V_30 ;
void * V_100 ;
V_30 = V_126 -> V_30 ;
V_100 = F_6 ( V_138 , V_16 ) ;
return V_100 ;
}
static void V_73 ( struct V_123 * V_116 , void * V_139 )
{
struct V_125 * V_126 = (struct V_125 * ) V_116 ;
struct V_1 * V_30 ;
V_30 = V_126 -> V_30 ;
F_3 ( V_139 ) ;
}
static void V_75 ( struct V_123 * V_116 , const char * V_140 ,
T_5 args )
{
struct V_125 * V_126 = (struct V_125 * ) V_116 ;
struct V_1 * V_30 ;
char V_141 [ V_29 ] ;
V_30 = V_126 -> V_30 ;
vsnprintf ( ( char * ) V_141 , V_29 , ( char * ) V_140 , args ) ;
F_12 ( V_26 , L_11 , V_141 ) ;
}
static int V_77 ( struct V_142 * V_116 ,
struct V_35 * V_113 , unsigned V_143 )
{
struct V_144 * V_145 = (struct V_144 * ) V_116 ;
struct V_1 * V_30 ;
int V_15 = 0 ;
T_1 V_146 ;
struct V_147 V_148 ;
T_3 V_136 = true ;
unsigned V_149 = F_33 ( V_113 -> type ) ;
char * V_150 = NULL ;
char * V_151 = NULL ;
char * V_152 = NULL ;
char * V_153 = NULL ;
char * V_154 ;
T_3 V_155 = 0 ;
T_3 V_156 = - 1 ;
T_3 V_157 = - 1 ;
T_3 V_158 = 0 ;
T_1 V_159 = 0 ;
T_1 V_160 = 0 ;
V_30 = V_145 -> V_30 ;
V_146 =
( V_149 == V_161 ) ? V_162 : ( V_149 ==
V_163 ) ? V_164 :
V_165 ;
V_155 = strlen ( ( char * ) ( V_113 -> V_20 ) ) + 1 ;
V_153 = F_6 ( V_155 , V_16 ) ;
V_152 = F_6 ( V_155 , V_16 ) ;
V_151 = F_6 ( V_155 , V_16 ) ;
if ( V_153 == NULL || V_151 == NULL ||
V_152 == NULL ) {
V_15 = - V_17 ;
goto V_97;
}
strncpy ( V_153 , ( char * ) ( V_113 -> V_20 ) , V_155 ) ;
V_154 = V_153 ;
while ( ( V_150 = F_34 ( & V_154 , L_12 ) ) && * V_150 != '\0' ) {
strncpy ( V_151 , V_152 ,
strlen ( V_152 ) + 1 ) ;
strncpy ( V_152 , V_150 , strlen ( V_150 ) + 1 ) ;
V_150 = F_34 ( & V_154 , L_12 ) ;
V_158 ++ ;
}
if ( V_158 >= 3 ) {
V_15 = F_35 ( V_152 , 10 , & V_157 ) ;
if ( V_15 )
goto V_97;
}
if ( ( V_157 == 0 ) || ( V_157 == 1 ) ) {
if ( strcmp ( V_151 , L_13 ) == 0 ) {
V_156 = 0 ;
} else {
if ( strcmp ( V_151 , L_14 ) == 0 ) {
V_156 = 1 ;
} else {
if ( strcmp ( V_151 ,
L_15 ) == 0 )
V_156 = 2 ;
}
}
}
V_97:
F_3 ( V_153 ) ;
V_153 = NULL ;
F_3 ( V_152 ) ;
V_152 = NULL ;
F_3 ( V_151 ) ;
V_151 = NULL ;
if ( V_146 == V_162 )
V_159 = V_113 -> V_43 + V_166 ;
else
V_159 = V_113 -> V_43 ;
if ( V_113 -> V_42 != V_113 -> V_167 )
V_160 = 1 ;
if ( V_30 != NULL ) {
V_15 =
( V_30 -> V_5 -> V_18 . V_168 ) ( V_30 -> V_5 -> V_18 .
V_131 , V_146 ,
V_159 , V_143 ,
( T_1 * ) & V_148 ,
V_156 , V_157 , false ) ;
}
if ( V_15 ) {
V_136 = false ;
} else {
V_113 -> V_42 = V_148 . V_169 * V_170 ;
if ( ! V_160 )
V_113 -> V_167 = V_113 -> V_42 ;
V_113 -> V_171 = ( T_1 ) V_148 . V_172 ;
F_12 ( V_26 , L_16 ,
V_27 , V_113 -> V_20 , V_113 -> V_42 / V_170 ,
V_113 -> V_43 / V_170 , V_113 -> V_167 ,
V_113 -> V_42 ) ;
}
return V_136 ;
}
static void V_78 ( struct V_142 * V_116 ,
struct V_35 * V_113 )
{
struct V_144 * V_145 = (struct V_144 * ) V_116 ;
struct V_1 * V_30 ;
T_1 V_172 ;
int V_15 = 0 ;
unsigned V_149 = F_33 ( V_113 -> type ) ;
T_1 V_146 ;
T_1 V_173 = 0 ;
V_146 =
( V_149 == V_161 ) ? V_162 : ( V_149 ==
V_163 ) ? V_164 :
V_165 ;
V_30 = V_145 -> V_30 ;
V_172 = ( T_1 ) V_113 -> V_171 ;
if ( V_146 == V_162 )
V_173 = V_113 -> V_43 + V_166 ;
else
V_173 = V_113 -> V_43 ;
if ( V_30 != NULL ) {
V_15 =
( V_30 -> V_5 -> V_18 . free ) ( V_30 -> V_5 -> V_18 .
V_129 , V_172 ,
V_113 -> V_42 /
V_170 , V_173 ,
false ) ;
}
}
static int V_81 ( struct V_109 * V_116 )
{
return true ;
}
static int V_83 ( struct V_109 * V_116 , void * V_100 ,
T_4 V_169 , struct V_35 * V_113 ,
unsigned V_174 )
{
struct V_175 * V_176 = (struct V_175 * ) V_116 ;
struct V_1 * V_30 ;
int V_121 = 0 ;
V_30 = V_176 -> V_30 ;
return V_121 ;
}
static int V_85 ( struct V_109 * V_116 , void * V_100 ,
T_4 V_169 , struct V_35 * V_113 ,
unsigned V_177 )
{
struct V_175 * V_176 = (struct V_175 * ) V_116 ;
struct V_1 * V_30 ;
struct V_3 * V_5 ;
struct V_178 V_179 ;
T_1 V_146 ;
bool V_136 = true ;
V_30 = V_176 -> V_30 ;
if ( ! V_30 )
return false ;
V_5 = V_30 -> V_5 ;
V_146 =
( F_33 ( V_113 -> type ) ==
V_161 ) ? V_162 : V_165 ;
if ( V_5 && V_5 -> V_18 . V_180 ) {
V_136 =
(* V_5 -> V_18 . V_180 ) ( V_5 -> V_18 . V_181 ,
V_169 , V_100 , V_177 ,
V_146 ) ;
if ( V_5 -> V_18 . V_182 ) {
V_179 . V_20 = V_113 -> V_20 ;
V_179 . V_183 = V_113 -> V_167 ;
V_179 . V_184 = V_113 -> V_42 ;
V_179 . V_43 = V_113 -> V_43 ;
V_179 . type = V_146 ;
(* V_5 -> V_18 . V_182 ) ( V_5 -> V_18 .
V_185 ,
& V_179 , V_169 ,
V_177 ) ;
}
}
return V_136 ;
}
static int V_87 ( struct V_109 * V_116 , T_4 V_169 ,
struct V_35 * V_113 , unsigned V_177 , unsigned V_186 )
{
bool V_136 = true ;
char * V_187 ;
struct V_1 * V_30 ;
struct V_175 * V_176 = (struct V_175 * ) V_116 ;
V_30 = V_176 -> V_30 ;
V_187 = NULL ;
if ( ( V_30 -> V_5 -> V_18 . V_180 ) != ( V_188 ) V_99 )
V_85 ( V_116 , & V_187 , V_169 , V_113 , 0 ) ;
if ( V_187 )
memset ( V_187 , V_186 , V_177 ) ;
return V_136 ;
}
static int V_88 ( struct V_109 * V_116 , T_4 V_189 )
{
struct V_175 * V_176 = (struct V_175 * ) V_116 ;
struct V_1 * V_30 ;
bool V_136 = true ;
V_30 = V_176 -> V_30 ;
if ( V_30 != NULL )
V_30 -> V_46 = ( T_1 ) V_189 ;
return V_136 ;
}
static void V_89 ( struct V_109 * V_116 )
{
}
void F_36 ( void * V_190 , void * V_191 )
{
struct V_23 * V_61 = V_190 ;
struct V_192 * V_171 = V_191 ;
T_1 V_193 = V_61 -> V_25 . V_25 ;
T_1 V_194 = V_171 -> V_195 - V_193 ;
if ( V_171 -> V_195 >= V_193 && V_193 < ( T_1 ) - 1 &&
V_194 < V_171 -> V_196 ) {
V_171 -> V_196 = V_194 ;
V_171 -> V_197 = V_193 ;
F_37 ( V_171 -> V_20 , V_61 -> V_20 , sizeof( V_171 -> V_20 ) ) ;
}
return;
}
bool F_38 ( struct V_1 * V_2 , T_1 V_195 ,
T_1 V_198 , T_1 * V_199 ,
char * V_200 )
{
bool V_15 = false ;
struct V_192 V_171 ;
V_171 . V_195 = V_195 ;
V_171 . V_198 = V_198 ;
V_171 . V_196 = V_198 ;
V_171 . V_197 = 0 ;
V_171 . V_20 [ 0 ] = '\0' ;
F_39 ( V_2 -> V_11 , F_36 , & V_171 ) ;
if ( V_171 . V_20 [ 0 ] ) {
V_15 = true ;
strcpy ( V_200 , V_171 . V_20 ) ;
* V_199 = V_171 . V_197 ;
}
return V_15 ;
}
