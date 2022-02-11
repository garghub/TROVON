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
bool V_15 = false ;
V_24 = (struct V_23 * ) F_10 ( V_2 -> V_11 , V_20 ) ;
if ( V_24 != NULL ) {
* V_22 = & V_24 -> V_25 ;
V_15 = true ;
}
F_11 ( V_26 , L_1 ,
V_27 , V_2 , V_20 , V_22 , V_15 ) ;
return V_15 ;
}
void F_12 ( struct V_3 * V_19 , struct V_12 * V_13 )
{
struct V_3 * V_4 = (struct V_3 * ) V_19 ;
if ( ( V_13 != NULL ) && ( V_4 != NULL ) )
* V_13 = V_4 -> V_18 ;
}
bool F_13 ( struct V_1 * V_2 , char * V_20 ,
struct V_21 * * V_22 )
{
struct V_23 * V_24 ;
char V_28 [ V_29 + 1 ] ;
bool V_15 = false ;
V_28 [ 0 ] = '_' ;
strncpy ( V_28 + 1 , V_20 , sizeof( V_28 ) - 2 ) ;
V_28 [ V_29 ] = '\0' ;
V_24 = (struct V_23 * ) F_10 ( V_2 -> V_11 , V_28 ) ;
if ( V_24 != NULL ) {
* V_22 = & V_24 -> V_25 ;
V_15 = true ;
}
return V_15 ;
}
int F_14 ( struct V_1 * V_30 , char * V_20 , T_1 * V_31 ,
T_1 * V_32 )
{
T_1 V_33 ;
bool V_34 = false ;
const struct V_35 * V_36 = NULL ;
struct V_1 * V_2 = (struct V_1 * ) V_30 ;
int V_15 = 0 ;
if ( V_2 != NULL ) {
if ( V_2 -> V_37 == NULL ) {
V_15 = F_15 ( V_2 ) ;
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
if ( F_16 ( V_2 -> V_41 , V_20 , & V_36 ) ) {
* V_31 = V_36 -> V_42 ;
* V_32 = V_36 -> V_43 * V_33 ;
if ( * V_32 % 2 )
( * V_32 ) ++ ;
* V_32 = F_17 ( * V_32 ) ;
} else {
V_15 = - V_44 ;
}
}
if ( V_34 ) {
F_2 ( V_2 ) ;
V_34 = false ;
}
F_11 ( V_26 , L_2
L_3 , V_27 , V_30 , V_20 , V_31 , V_32 , V_15 ) ;
return V_15 ;
}
bool F_18 ( void )
{
return true ;
}
int F_19 ( struct V_1 * V_30 , T_2 V_45 ,
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
V_2 -> V_11 = F_20 ( V_52 ,
sizeof( struct V_23 ) ,
V_53 ,
V_54 , V_55 ) ;
if ( V_2 -> V_11 == NULL )
V_15 = - V_17 ;
}
V_2 -> V_56 . V_57 . V_58 = V_59 ;
V_2 -> V_56 . V_57 . V_60 = V_61 ;
V_2 -> V_56 . V_30 = V_2 ;
V_2 -> V_62 . V_63 . V_64 =
V_65 ;
if ( V_48 ) {
V_2 -> V_62 . V_63 . V_66 =
V_67 ;
} else {
V_2 -> V_62 . V_63 . V_66 =
V_68 ;
}
V_2 -> V_62 . V_63 . V_69 =
V_70 ;
V_2 -> V_62 . V_63 . V_71 = V_72 ;
V_2 -> V_62 . V_63 . V_73 = V_74 ;
V_2 -> V_62 . V_63 . V_75 = V_76 ;
V_2 -> V_62 . V_30 = V_2 ;
V_2 -> V_72 . V_77 . V_71 = V_78 ;
V_2 -> V_72 . V_77 . V_73 = V_79 ;
V_2 -> V_72 . V_30 = V_2 ;
V_2 -> V_80 . V_81 . V_82 = V_82 ;
V_2 -> V_80 . V_81 . V_83 = V_84 ;
V_2 -> V_80 . V_81 . V_85 = V_86 ;
V_2 -> V_80 . V_81 . V_87 = V_88 ;
V_2 -> V_80 . V_81 . V_89 = V_89 ;
V_2 -> V_80 . V_81 . V_90 = V_90 ;
V_2 -> V_80 . V_30 = V_2 ;
if ( V_2 -> V_37 == NULL ) {
V_15 = F_15 ( V_2 ) ;
if ( ! V_15 )
V_34 = true ;
}
if ( ! V_15 ) {
V_2 -> V_38 = ( * ( V_2 -> V_5 -> V_18 . ftell ) )
( V_2 -> V_37 ) ;
( * ( V_2 -> V_5 -> V_18 . fseek ) ) ( V_2 -> V_37 ,
( long ) 0 ,
V_39 ) ;
V_91 = true ;
V_49 = F_21 ( & V_2 -> V_56 . V_57 ,
& V_2 -> V_62 . V_63 ,
& V_2 -> V_72 . V_77 ,
& V_2 -> V_80 . V_81 ,
V_92 ,
& V_2 -> V_93 ) ;
if ( V_49 != 0 ) {
V_15 = - V_94 ;
} else if ( V_95 ) {
V_2 -> V_50 ++ ;
F_22 ( V_2 , (struct V_12 * ) V_18 ) ;
V_95 = false ;
V_15 = - V_94 ;
} else {
* V_46 = V_2 -> V_46 ;
}
}
}
if ( ! V_15 )
V_2 -> V_50 ++ ;
if ( V_34 )
F_2 ( V_2 ) ;
F_11 ( V_26 , L_4 ,
V_27 , V_30 , V_45 , V_46 , V_15 ) ;
return V_15 ;
}
int F_23 ( struct V_3 * V_19 , char * V_96 , T_2 V_45 ,
struct V_1 * * V_97 )
{
struct V_3 * V_4 = (struct V_3 * ) V_19 ;
struct V_1 * V_2 = NULL ;
T_3 V_49 ;
int V_15 = 0 ;
V_2 = V_4 -> V_7 ;
while ( V_2 != NULL ) {
if ( strcmp ( V_2 -> V_10 , V_96 ) == 0 ) {
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
V_2 -> V_10 = F_6 ( strlen ( V_96 ) + 1 ,
V_16 ) ;
if ( V_2 -> V_10 == NULL ) {
V_15 = - V_17 ;
} else {
strncpy ( V_2 -> V_10 , V_96 ,
strlen ( V_96 ) + 1 ) ;
}
V_2 -> V_11 = NULL ;
}
}
if ( V_15 )
goto V_98;
V_2 -> V_56 . V_57 . V_58 = V_59 ;
V_2 -> V_56 . V_57 . V_60 = V_61 ;
V_2 -> V_56 . V_30 = V_2 ;
V_2 -> V_62 . V_63 . V_66 = V_68 ;
V_2 -> V_62 . V_63 . V_64 = V_65 ;
V_2 -> V_62 . V_63 . V_69 = V_70 ;
V_2 -> V_62 . V_63 . V_71 = V_72 ;
V_2 -> V_62 . V_63 . V_73 = V_74 ;
V_2 -> V_62 . V_63 . V_75 = V_76 ;
V_2 -> V_62 . V_30 = V_2 ;
V_2 -> V_72 . V_77 . V_71 = V_78 ;
V_2 -> V_72 . V_77 . V_73 = V_79 ;
V_2 -> V_72 . V_30 = V_2 ;
V_2 -> V_80 . V_81 . V_82 = V_82 ;
V_2 -> V_80 . V_81 . V_83 = V_84 ;
V_2 -> V_80 . V_81 . V_85 = V_86 ;
V_2 -> V_80 . V_81 . V_87 = V_88 ;
V_2 -> V_80 . V_81 . V_89 = V_89 ;
V_2 -> V_80 . V_81 . V_90 = V_90 ;
V_2 -> V_80 . V_30 = V_2 ;
if ( ! V_15 && V_2 -> V_37 == NULL )
V_15 = F_15 ( V_2 ) ;
V_2 -> V_38 = ( * ( V_2 -> V_5 -> V_18 . ftell ) ) ( V_2 -> V_37 ) ;
( * ( V_2 -> V_5 -> V_18 . fseek ) ) ( V_2 -> V_37 , ( long ) 0 , V_39 ) ;
if ( V_2 -> V_11 != NULL || ! ( V_45 & V_99 ) )
goto V_98;
V_2 -> V_11 =
F_20 ( V_52 , sizeof( struct V_23 ) , V_53 ,
V_54 , V_55 ) ;
if ( V_2 -> V_11 == NULL ) {
V_15 = - V_17 ;
} else {
V_2 -> V_80 . V_81 . V_85 = V_100 ;
V_49 = F_24 ( & V_2 -> V_56 . V_57 ,
& V_2 -> V_62 . V_63 ,
& V_2 -> V_72 . V_77 ,
& V_2 -> V_80 . V_81 , 0 ,
& V_2 -> V_93 ) ;
if ( V_49 != 0 ) {
V_15 = - V_94 ;
} else {
V_49 = F_25 ( V_2 -> V_93 ,
& V_2 -> V_62 . V_63 ,
& V_2 -> V_72 . V_77 ,
& V_2 -> V_80 . V_81 ) ;
if ( V_49 != 0 )
V_15 = - V_94 ;
V_2 -> V_93 = NULL ;
}
}
V_98:
if ( ! V_15 ) {
if ( V_2 -> V_6 == 1 ) {
if ( V_4 -> V_7 )
( V_4 -> V_7 ) -> V_9 = V_2 ;
V_2 -> V_9 = NULL ;
V_2 -> V_8 = V_4 -> V_7 ;
V_4 -> V_7 = V_2 ;
}
* V_97 = (struct V_1 * ) V_2 ;
} else {
* V_97 = NULL ;
if ( V_2 != NULL )
F_1 ( (struct V_1 * ) V_2 ) ;
}
F_11 ( V_26 , L_5 ,
V_27 , V_19 , V_96 , V_97 , V_15 ) ;
return V_15 ;
}
int F_26 ( struct V_1 * V_30 , char * V_20 ,
char * V_101 , T_1 V_43 )
{
struct V_1 * V_2 = (struct V_1 * ) V_30 ;
bool V_34 = false ;
T_1 V_33 ;
T_1 V_102 ;
const struct V_35 * V_36 = NULL ;
int V_15 = 0 ;
if ( V_2 != NULL ) {
if ( V_2 -> V_37 == NULL ) {
V_15 = F_15 ( V_2 ) ;
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
goto V_98;
V_33 = 1 ;
if ( ! F_16 ( V_2 -> V_41 , V_20 , & V_36 ) ) {
V_15 = - V_44 ;
goto V_98;
}
V_102 = V_36 -> V_43 * V_33 ;
if ( V_102 % 2 )
V_102 ++ ;
V_102 = F_17 ( V_102 ) ;
if ( V_102 > V_43 ) {
V_15 = - V_103 ;
} else {
if ( ! F_27 ( V_2 -> V_41 , V_36 , V_101 ) )
V_15 = - V_104 ;
}
V_98:
if ( V_34 ) {
F_2 ( V_2 ) ;
V_34 = false ;
}
F_11 ( V_26 , L_6
L_3 , V_27 , V_30 , V_20 , V_101 , V_43 , V_15 ) ;
return V_15 ;
}
void F_22 ( struct V_1 * V_30 , struct V_12 * V_18 )
{
struct V_1 * V_2 = (struct V_1 * ) V_30 ;
T_3 V_49 = 0 ;
F_11 ( V_26 , L_7 , V_27 , V_30 ) ;
V_2 -> V_50 -- ;
if ( V_2 -> V_50 != 0 )
return;
V_2 -> V_5 -> V_18 = * V_18 ;
if ( V_2 -> V_93 ) {
V_49 = F_25 ( V_2 -> V_93 ,
& V_2 -> V_62 . V_63 ,
& V_2 -> V_72 . V_77 ,
& V_2 -> V_80 . V_81 ) ;
if ( V_49 != 0 )
F_11 ( V_26 , L_8 , V_27 , V_49 ) ;
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
F_28 ( V_2 -> V_41 ) ;
V_2 -> V_41 = NULL ;
}
if ( V_2 -> V_37 ) {
( V_2 -> V_5 -> V_18 . fclose ) ( V_2 -> V_37 ) ;
V_2 -> V_37 = NULL ;
}
}
static int F_15 ( struct V_1 * V_2 )
{
void * V_105 = * ( V_2 -> V_5 -> V_18 . fopen ) ;
int V_15 = 0 ;
V_2 -> V_37 =
( void * ) ( ( V_106 ) ( V_105 ) ) ( V_2 -> V_10 , L_9 ) ;
if ( V_2 -> V_37 && V_2 -> V_41 == NULL ) {
( * ( V_2 -> V_5 -> V_18 . fseek ) ) ( V_2 -> V_37 , ( long ) 0 ,
V_39 ) ;
V_2 -> V_41 =
F_29 ( & V_2 -> V_56 . V_57 ,
& V_2 -> V_62 . V_63 ) ;
if ( V_2 -> V_41 == NULL ) {
( V_2 -> V_5 -> V_18 . fclose ) ( V_2 -> V_37 ) ;
V_2 -> V_37 = NULL ;
V_15 = - V_104 ;
}
} else {
V_15 = - V_104 ;
}
return V_15 ;
}
static T_4 V_53 ( void * V_107 , T_4 V_108 )
{
T_4 V_109 ;
T_4 V_110 ;
char * V_20 = ( char * ) V_107 ;
V_110 = 0 ;
while ( * V_20 ) {
V_110 <<= 1 ;
V_110 ^= * V_20 ++ ;
}
V_109 = V_110 % V_108 ;
return V_109 ;
}
static bool V_54 ( void * V_107 , void * V_111 )
{
if ( ( V_107 != NULL ) && ( V_111 != NULL ) ) {
if ( strcmp ( ( char * ) V_107 , ( (struct V_23 * ) V_111 ) -> V_20 ) ==
0 )
return true ;
}
return false ;
}
static int V_100 ( struct V_112 * V_113 , void * V_114 ,
T_5 V_115 , struct V_35 * V_116 , unsigned V_117 )
{
return 1 ;
}
static void V_55 ( void * V_25 )
{
struct V_23 * V_111 = (struct V_23 * ) V_25 ;
F_3 ( V_111 -> V_20 ) ;
}
static int V_59 ( struct V_118 * V_119 , void * V_120 ,
unsigned V_121 )
{
struct V_122 * V_123 = (struct V_122 * ) V_119 ;
struct V_1 * V_30 ;
int V_124 = 0 ;
V_30 = V_123 -> V_30 ;
if ( V_30 != NULL ) {
V_124 =
( * ( V_30 -> V_5 -> V_18 . fread ) ) ( V_120 , 1 , V_121 ,
V_30 -> V_37 ) ;
}
return V_124 ;
}
static int V_61 ( struct V_118 * V_119 ,
unsigned int V_38 )
{
struct V_122 * V_123 = (struct V_122 * ) V_119 ;
struct V_1 * V_30 ;
int V_15 = 0 ;
V_30 = V_123 -> V_30 ;
if ( V_30 != NULL ) {
V_15 = ( * ( V_30 -> V_5 -> V_18 . fseek ) ) ( V_30 -> V_37 , ( long ) V_38 ,
V_39 ) ;
}
return V_15 ;
}
static struct V_125 * V_65 ( struct V_126 * V_119 ,
const char * V_20 )
{
struct V_125 * V_127 ;
struct V_128 * V_129 = (struct V_128 * ) V_119 ;
struct V_1 * V_30 ;
struct V_21 * V_130 = NULL ;
bool V_15 = false ;
V_30 = V_129 -> V_30 ;
if ( V_30 != NULL ) {
if ( V_30 -> V_5 -> V_18 . V_131 ) {
V_15 = ( * ( V_30 -> V_5 -> V_18 . V_131 ) )
( V_30 -> V_5 -> V_18 . V_132 ,
V_30 -> V_5 -> V_18 . V_133 ,
V_30 -> V_5 -> V_18 . V_134 , V_20 ,
& V_130 ) ;
} else {
V_15 = F_9 ( (struct V_1 * ) V_30 ,
( char * ) V_20 , & V_130 ) ;
if ( ! V_15 ) {
V_15 =
F_13 ( (struct V_1 * )
V_30 , ( char * ) V_20 ,
& V_130 ) ;
}
}
}
if ( ! V_15 && V_135 )
F_11 ( V_26 , L_10 , V_27 , V_20 ) ;
V_127 = (struct V_125 * ) V_130 ;
return V_127 ;
}
static struct V_125 * V_67 ( struct V_126
* V_119 , const char * V_20 ,
unsigned V_136 )
{
struct V_125 * V_127 ;
struct V_128 * V_129 = (struct V_128 * ) V_119 ;
struct V_1 * V_30 ;
struct V_23 * V_24 ;
V_30 = V_129 -> V_30 ;
V_24 = (struct V_23 * ) F_10 ( V_30 -> V_11 , ( char * ) V_20 ) ;
V_127 = (struct V_125 * ) & V_24 -> V_25 ;
return V_127 ;
}
static struct V_125 * V_68 ( struct V_126
* V_119 , const char * V_20 ,
unsigned V_137 )
{
struct V_23 * V_138 = NULL ;
struct V_23 V_62 ;
struct V_125 * V_130 = NULL ;
struct V_128 * V_129 = (struct V_128 * ) V_119 ;
struct V_1 * V_30 ;
struct V_125 * V_109 ;
V_30 = V_129 -> V_30 ;
if ( ! ( V_30 -> V_5 -> V_18 . V_139 ) ) {
V_135 = false ;
V_130 = V_65 ( V_119 , V_20 ) ;
V_135 = true ;
if ( V_130 ) {
V_95 = true ;
F_11 ( V_26 , L_11 ,
V_20 ) ;
return NULL ;
}
}
V_62 . V_20 = F_6 ( strlen ( ( char * const ) V_20 ) + 1 , V_16 ) ;
if ( V_62 . V_20 == NULL )
return NULL ;
if ( V_62 . V_20 != NULL ) {
strncpy ( V_62 . V_20 , ( char * const ) V_20 ,
strlen ( ( char * const ) V_20 ) + 1 ) ;
V_138 =
(struct V_23 * ) F_30 ( V_30 -> V_11 , ( void * ) V_20 ,
( void * ) & V_62 ) ;
if ( V_138 == NULL )
F_3 ( V_62 . V_20 ) ;
}
if ( V_138 != NULL )
V_109 = (struct V_125 * ) & V_138 -> V_25 ;
else
V_109 = NULL ;
return V_109 ;
}
static void V_70 ( struct V_126 * V_119 ,
unsigned V_137 )
{
struct V_128 * V_129 = (struct V_128 * ) V_119 ;
struct V_1 * V_30 ;
V_30 = V_129 -> V_30 ;
}
static void * V_72 ( struct V_126 * V_119 , unsigned V_140 )
{
struct V_128 * V_129 = (struct V_128 * ) V_119 ;
struct V_1 * V_30 ;
void * V_101 ;
V_30 = V_129 -> V_30 ;
V_101 = F_6 ( V_140 , V_16 ) ;
return V_101 ;
}
static void V_74 ( struct V_126 * V_119 , void * V_141 )
{
struct V_128 * V_129 = (struct V_128 * ) V_119 ;
struct V_1 * V_30 ;
V_30 = V_129 -> V_30 ;
F_3 ( V_141 ) ;
}
static void V_76 ( struct V_126 * V_119 , const char * V_142 ,
T_6 args )
{
struct V_128 * V_129 = (struct V_128 * ) V_119 ;
struct V_1 * V_30 ;
char V_143 [ V_29 ] ;
V_30 = V_129 -> V_30 ;
vsnprintf ( ( char * ) V_143 , V_29 , ( char * ) V_142 , args ) ;
F_11 ( V_26 , L_12 , V_143 ) ;
}
static int V_78 ( struct V_144 * V_119 ,
struct V_35 * V_116 , unsigned V_145 )
{
struct V_146 * V_147 = (struct V_146 * ) V_119 ;
struct V_1 * V_30 ;
int V_15 = 0 ;
T_1 V_148 ;
struct V_149 V_150 ;
T_3 V_109 = true ;
unsigned V_151 = F_31 ( V_116 -> type ) ;
char * V_152 = NULL ;
char * V_153 = NULL ;
char * V_154 = NULL ;
char * V_155 = NULL ;
char * V_156 ;
T_3 V_157 = 0 ;
T_3 V_158 = - 1 ;
T_3 V_159 = - 1 ;
T_3 V_160 = 0 ;
T_1 V_161 = 0 ;
T_1 V_162 = 0 ;
V_30 = V_147 -> V_30 ;
V_148 =
( V_151 == V_163 ) ? V_164 : ( V_151 ==
V_165 ) ? V_166 :
V_167 ;
V_157 = strlen ( ( char * ) ( V_116 -> V_20 ) ) + 1 ;
V_155 = F_6 ( V_157 , V_16 ) ;
V_154 = F_6 ( V_157 , V_16 ) ;
V_153 = F_6 ( V_157 , V_16 ) ;
if ( V_155 == NULL || V_153 == NULL ||
V_154 == NULL ) {
V_15 = - V_17 ;
goto V_98;
}
strncpy ( V_155 , ( char * ) ( V_116 -> V_20 ) , V_157 ) ;
V_156 = V_155 ;
while ( ( V_152 = F_32 ( & V_156 , L_13 ) ) && * V_152 != '\0' ) {
strncpy ( V_153 , V_154 ,
strlen ( V_154 ) + 1 ) ;
strncpy ( V_154 , V_152 , strlen ( V_152 ) + 1 ) ;
V_152 = F_32 ( & V_156 , L_13 ) ;
V_160 ++ ;
}
if ( V_160 >= 3 )
F_33 ( V_154 , 10 , ( long * ) & V_159 ) ;
if ( ( V_159 == 0 ) || ( V_159 == 1 ) ) {
if ( strcmp ( V_153 , L_14 ) == 0 ) {
V_158 = 0 ;
} else {
if ( strcmp ( V_153 , L_15 ) == 0 ) {
V_158 = 1 ;
} else {
if ( strcmp ( V_153 ,
L_16 ) == 0 )
V_158 = 2 ;
}
}
}
V_98:
F_3 ( V_155 ) ;
V_155 = NULL ;
F_3 ( V_154 ) ;
V_154 = NULL ;
F_3 ( V_153 ) ;
V_153 = NULL ;
if ( V_148 == V_164 )
V_161 = V_116 -> V_43 + V_168 ;
else
V_161 = V_116 -> V_43 ;
if ( V_116 -> V_42 != V_116 -> V_169 )
V_162 = 1 ;
if ( V_30 != NULL ) {
V_15 =
( V_30 -> V_5 -> V_18 . V_170 ) ( V_30 -> V_5 -> V_18 .
V_134 , V_148 ,
V_161 , V_145 ,
( T_1 * ) & V_150 ,
V_158 , V_159 , false ) ;
}
if ( V_15 ) {
V_109 = false ;
} else {
V_116 -> V_42 = V_150 . V_171 * V_172 ;
if ( ! V_162 )
V_116 -> V_169 = V_116 -> V_42 ;
V_116 -> V_173 = ( T_1 ) V_150 . V_174 ;
F_11 ( V_26 , L_17
L_18 ,
V_27 , V_116 -> V_20 , V_116 -> V_42 / V_172 ,
V_116 -> V_43 / V_172 , V_116 -> V_169 ,
V_116 -> V_42 ) ;
}
return V_109 ;
}
static void V_79 ( struct V_144 * V_119 ,
struct V_35 * V_116 )
{
struct V_146 * V_147 = (struct V_146 * ) V_119 ;
struct V_1 * V_30 ;
T_1 V_174 ;
int V_15 = 0 ;
unsigned V_151 = F_31 ( V_116 -> type ) ;
T_1 V_148 ;
T_1 V_175 = 0 ;
V_148 =
( V_151 == V_163 ) ? V_164 : ( V_151 ==
V_165 ) ? V_166 :
V_167 ;
V_30 = V_147 -> V_30 ;
V_174 = ( T_1 ) V_116 -> V_173 ;
if ( V_148 == V_164 )
V_175 = V_116 -> V_43 + V_168 ;
else
V_175 = V_116 -> V_43 ;
if ( V_30 != NULL ) {
V_15 =
( V_30 -> V_5 -> V_18 . free ) ( V_30 -> V_5 -> V_18 .
V_132 , V_174 ,
V_116 -> V_42 /
V_172 , V_175 ,
false ) ;
}
}
static int V_82 ( struct V_112 * V_119 )
{
return true ;
}
static int V_84 ( struct V_112 * V_119 , void * V_101 ,
T_5 V_171 , struct V_35 * V_116 ,
unsigned V_176 )
{
struct V_177 * V_178 = (struct V_177 * ) V_119 ;
struct V_1 * V_30 ;
int V_124 = 0 ;
V_30 = V_178 -> V_30 ;
return V_124 ;
}
static int V_86 ( struct V_112 * V_119 , void * V_101 ,
T_5 V_171 , struct V_35 * V_116 ,
unsigned V_179 )
{
struct V_177 * V_178 = (struct V_177 * ) V_119 ;
struct V_1 * V_30 ;
struct V_3 * V_5 ;
struct V_180 V_181 ;
T_1 V_148 ;
bool V_109 = true ;
V_30 = V_178 -> V_30 ;
if ( ! V_30 )
return false ;
V_5 = V_30 -> V_5 ;
V_148 =
( F_31 ( V_116 -> type ) ==
V_163 ) ? V_164 : V_167 ;
if ( V_5 && V_5 -> V_18 . V_182 ) {
V_109 =
(* V_5 -> V_18 . V_182 ) ( V_5 -> V_18 . V_183 ,
V_171 , V_101 , V_179 ,
V_148 ) ;
if ( V_5 -> V_18 . V_184 ) {
V_181 . V_20 = V_116 -> V_20 ;
V_181 . V_185 = V_116 -> V_169 ;
V_181 . V_186 = V_116 -> V_42 ;
V_181 . V_43 = V_116 -> V_43 ;
V_181 . type = V_148 ;
(* V_5 -> V_18 . V_184 ) ( V_5 -> V_18 .
V_187 ,
& V_181 , V_171 ,
V_179 ) ;
}
}
return V_109 ;
}
static int V_88 ( struct V_112 * V_119 , T_5 V_171 ,
struct V_35 * V_116 , unsigned V_179 , unsigned V_188 )
{
bool V_109 = true ;
char * V_189 ;
struct V_1 * V_30 ;
struct V_177 * V_178 = (struct V_177 * ) V_119 ;
V_30 = V_178 -> V_30 ;
V_189 = NULL ;
if ( ( V_30 -> V_5 -> V_18 . V_182 ) != ( V_190 ) V_100 )
V_86 ( V_119 , & V_189 , V_171 , V_116 , 0 ) ;
if ( V_189 )
memset ( V_189 , V_188 , V_179 ) ;
return V_109 ;
}
static int V_89 ( struct V_112 * V_119 , T_5 V_191 )
{
struct V_177 * V_178 = (struct V_177 * ) V_119 ;
struct V_1 * V_30 ;
bool V_109 = true ;
V_30 = V_178 -> V_30 ;
if ( V_30 != NULL )
V_30 -> V_46 = ( T_1 ) V_191 ;
return V_109 ;
}
static void V_90 ( struct V_112 * V_119 )
{
}
void F_34 ( void * V_192 , void * V_193 )
{
struct V_23 * V_62 = V_192 ;
struct V_194 * V_173 = V_193 ;
T_1 V_195 = V_62 -> V_25 . V_25 ;
T_1 V_196 = V_173 -> V_197 - V_195 ;
if ( V_173 -> V_197 >= V_195 && V_195 < ( T_1 ) - 1 &&
V_196 < V_173 -> V_198 ) {
V_173 -> V_198 = V_196 ;
V_173 -> V_199 = V_195 ;
F_35 ( V_173 -> V_20 , V_62 -> V_20 , sizeof( V_173 -> V_20 ) ) ;
}
return;
}
bool F_36 ( struct V_1 * V_2 , T_1 V_197 ,
T_1 V_200 , T_1 * V_201 ,
char * V_202 )
{
bool V_15 = false ;
struct V_194 V_173 ;
V_173 . V_197 = V_197 ;
V_173 . V_200 = V_200 ;
V_173 . V_198 = V_200 ;
V_173 . V_199 = 0 ;
V_173 . V_20 [ 0 ] = '\0' ;
F_37 ( V_2 -> V_11 , F_34 , & V_173 ) ;
if ( V_173 . V_20 [ 0 ] ) {
V_15 = true ;
strcpy ( V_202 , V_173 . V_20 ) ;
* V_201 = V_173 . V_199 ;
}
return V_15 ;
}
