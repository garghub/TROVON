void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_2 ( V_5 > 0 ) ;
F_2 ( V_2 ) ;
F_2 ( V_2 -> V_6 > 0 ) ;
V_4 = V_2 -> V_7 ;
V_2 -> V_6 -- ;
if ( V_2 -> V_6 == 0 ) {
if ( V_4 -> V_8 == V_2 )
V_4 -> V_8 = V_2 -> V_9 ;
if ( V_2 -> V_10 )
( V_2 -> V_10 ) -> V_9 = V_2 -> V_9 ;
if ( V_2 -> V_9 )
( V_2 -> V_9 ) -> V_10 = V_2 -> V_10 ;
F_3 ( V_2 ) ;
F_4 ( V_2 -> V_11 ) ;
if ( V_2 -> V_12 )
F_5 ( V_2 -> V_12 ) ;
F_4 ( V_2 ) ;
V_2 = NULL ;
}
}
int F_6 ( struct V_3 * * V_7 ,
struct V_13 * V_14 )
{
struct V_3 * V_15 ;
int V_16 = 0 ;
F_2 ( V_5 > 0 ) ;
F_2 ( V_14 != NULL ) ;
F_2 ( V_7 != NULL ) ;
V_15 = F_7 ( sizeof( struct V_3 ) , V_17 ) ;
if ( V_7 != NULL ) {
if ( V_15 == NULL ) {
* V_7 = NULL ;
V_16 = - V_18 ;
} else {
V_15 -> V_19 = * V_14 ;
* V_7 = (struct V_3 * ) V_15 ;
}
F_8 ( ( ! V_16 && * V_7 ) ||
( V_16 && * V_7 == NULL ) ) ;
}
return V_16 ;
}
void F_9 ( struct V_3 * V_20 )
{
struct V_3 * V_4 = (struct V_3 * ) V_20 ;
F_2 ( V_5 > 0 ) ;
F_2 ( V_4 ) ;
F_4 ( V_4 ) ;
}
void F_10 ( void )
{
F_2 ( V_5 > 0 ) ;
V_5 -- ;
if ( V_5 == 0 )
F_11 () ;
F_8 ( V_5 >= 0 ) ;
}
bool F_12 ( struct V_1 * V_2 , char * V_21 ,
struct V_22 * * V_23 )
{
struct V_24 * V_25 ;
bool V_16 = false ;
F_2 ( V_5 > 0 ) ;
F_2 ( V_2 ) ;
F_2 ( V_21 != NULL ) ;
F_2 ( V_23 != NULL ) ;
F_2 ( V_2 -> V_12 != NULL ) ;
V_25 = (struct V_24 * ) F_13 ( V_2 -> V_12 , V_21 ) ;
if ( V_25 != NULL ) {
* V_23 = & V_25 -> V_26 ;
V_16 = true ;
}
F_14 ( V_27 , L_1 ,
V_28 , V_2 , V_21 , V_23 , V_16 ) ;
return V_16 ;
}
void F_15 ( struct V_3 * V_20 , struct V_13 * V_14 )
{
struct V_3 * V_4 = (struct V_3 * ) V_20 ;
F_2 ( V_5 > 0 ) ;
F_2 ( V_4 ) ;
F_2 ( V_14 != NULL ) ;
if ( ( V_14 != NULL ) && ( V_4 != NULL ) )
* V_14 = V_4 -> V_19 ;
}
bool F_16 ( struct V_1 * V_2 , char * V_21 ,
struct V_22 * * V_23 )
{
struct V_24 * V_25 ;
char V_29 [ V_30 + 1 ] ;
bool V_16 = false ;
F_2 ( V_5 > 0 ) ;
F_2 ( V_2 ) ;
F_2 ( V_23 != NULL ) ;
F_2 ( V_2 -> V_12 != NULL ) ;
F_2 ( V_21 != NULL ) ;
V_29 [ 0 ] = '_' ;
strncpy ( V_29 + 1 , V_21 , sizeof( V_29 ) - 2 ) ;
V_29 [ V_30 ] = '\0' ;
V_25 = (struct V_24 * ) F_13 ( V_2 -> V_12 , V_29 ) ;
if ( V_25 != NULL ) {
* V_23 = & V_25 -> V_26 ;
V_16 = true ;
}
return V_16 ;
}
int F_17 ( struct V_1 * V_31 , char * V_21 , T_1 * V_32 ,
T_1 * V_33 )
{
T_1 V_34 ;
bool V_35 = false ;
const struct V_36 * V_37 = NULL ;
struct V_1 * V_2 = (struct V_1 * ) V_31 ;
int V_16 = 0 ;
F_2 ( V_5 > 0 ) ;
F_2 ( V_21 != NULL ) ;
F_2 ( V_32 != NULL ) ;
F_2 ( V_33 != NULL ) ;
F_2 ( V_2 ) ;
if ( V_2 != NULL ) {
if ( V_2 -> V_38 == NULL ) {
V_16 = F_18 ( V_2 ) ;
if ( ! V_16 )
V_35 = true ;
} else {
( * ( V_2 -> V_7 -> V_19 . fseek ) ) ( V_2 -> V_38 ,
V_2 -> V_39 ,
V_40 ) ;
}
} else {
V_16 = - V_41 ;
}
if ( ! V_16 ) {
V_34 = 1 ;
if ( F_19 ( V_2 -> V_42 , V_21 , & V_37 ) ) {
* V_32 = V_37 -> V_43 ;
* V_33 = V_37 -> V_44 * V_34 ;
if ( * V_33 % 2 )
( * V_33 ) ++ ;
* V_33 = F_20 ( * V_33 ) ;
} else {
V_16 = - V_45 ;
}
}
if ( V_35 ) {
F_3 ( V_2 ) ;
V_35 = false ;
}
F_14 ( V_27 , L_2
L_3 , V_28 , V_31 , V_21 , V_32 , V_33 , V_16 ) ;
return V_16 ;
}
bool F_21 ( void )
{
F_2 ( V_5 >= 0 ) ;
if ( V_5 == 0 )
F_22 () ;
V_5 ++ ;
return true ;
}
int F_23 ( struct V_1 * V_31 , T_2 V_46 ,
struct V_13 * V_19 , T_1 * V_47 )
{
struct V_1 * V_2 = (struct V_1 * ) V_31 ;
struct V_3 * V_48 ;
bool V_49 = true ;
T_3 V_50 ;
int V_16 = 0 ;
bool V_35 = false ;
F_2 ( V_5 > 0 ) ;
F_2 ( V_2 ) ;
F_2 ( V_47 != NULL ) ;
F_2 ( V_19 != NULL ) ;
if ( V_2 -> V_51 == 0 || ! ( V_46 & V_52 ) ) {
V_48 = V_2 -> V_7 ;
V_48 -> V_19 = * V_19 ;
if ( V_2 -> V_12 == NULL ) {
V_49 = false ;
V_2 -> V_12 = F_24 ( V_53 ,
sizeof( struct V_24 ) ,
V_54 ,
V_55 , V_56 ) ;
if ( V_2 -> V_12 == NULL )
V_16 = - V_18 ;
}
V_2 -> V_57 . V_58 . V_59 = V_60 ;
V_2 -> V_57 . V_58 . V_61 = V_62 ;
V_2 -> V_57 . V_31 = V_2 ;
V_2 -> V_63 . V_64 . V_65 =
V_66 ;
if ( V_49 ) {
V_2 -> V_63 . V_64 . V_67 =
V_68 ;
} else {
V_2 -> V_63 . V_64 . V_67 =
V_69 ;
}
V_2 -> V_63 . V_64 . V_70 =
V_71 ;
V_2 -> V_63 . V_64 . V_72 = V_73 ;
V_2 -> V_63 . V_64 . V_74 = V_75 ;
V_2 -> V_63 . V_64 . V_76 = V_77 ;
V_2 -> V_63 . V_31 = V_2 ;
V_2 -> V_73 . V_78 . V_72 = V_79 ;
V_2 -> V_73 . V_78 . V_74 = V_80 ;
V_2 -> V_73 . V_31 = V_2 ;
V_2 -> V_81 . V_82 . V_83 = V_83 ;
V_2 -> V_81 . V_82 . V_84 = V_85 ;
V_2 -> V_81 . V_82 . V_86 = V_87 ;
V_2 -> V_81 . V_82 . V_88 = V_89 ;
V_2 -> V_81 . V_82 . V_90 = V_90 ;
V_2 -> V_81 . V_82 . V_91 = V_91 ;
V_2 -> V_81 . V_31 = V_2 ;
if ( V_2 -> V_38 == NULL ) {
V_16 = F_18 ( V_2 ) ;
if ( ! V_16 )
V_35 = true ;
}
if ( ! V_16 ) {
V_2 -> V_39 = ( * ( V_2 -> V_7 -> V_19 . ftell ) )
( V_2 -> V_38 ) ;
( * ( V_2 -> V_7 -> V_19 . fseek ) ) ( V_2 -> V_38 ,
( long ) 0 ,
V_40 ) ;
V_92 = true ;
V_50 = F_25 ( & V_2 -> V_57 . V_58 ,
& V_2 -> V_63 . V_64 ,
& V_2 -> V_73 . V_78 ,
& V_2 -> V_81 . V_82 ,
V_93 ,
& V_2 -> V_94 ) ;
if ( V_50 != 0 ) {
V_16 = - V_95 ;
} else if ( V_96 ) {
V_2 -> V_51 ++ ;
F_26 ( V_2 , (struct V_13 * ) V_19 ) ;
V_96 = false ;
V_16 = - V_95 ;
} else {
* V_47 = V_2 -> V_47 ;
}
}
}
if ( ! V_16 )
V_2 -> V_51 ++ ;
if ( V_35 )
F_3 ( V_2 ) ;
F_8 ( V_16 || V_2 -> V_51 > 0 ) ;
F_14 ( V_27 , L_4 ,
V_28 , V_31 , V_46 , V_47 , V_16 ) ;
return V_16 ;
}
int F_27 ( struct V_3 * V_20 , char * V_97 , T_2 V_46 ,
struct V_1 * * V_98 )
{
struct V_3 * V_4 = (struct V_3 * ) V_20 ;
struct V_1 * V_2 = NULL ;
T_3 V_50 ;
int V_16 = 0 ;
F_2 ( V_5 > 0 ) ;
F_2 ( V_4 ) ;
F_2 ( V_4 -> V_19 . fopen != NULL ) ;
F_2 ( V_97 != NULL ) ;
F_2 ( V_98 != NULL ) ;
V_2 = V_4 -> V_8 ;
while ( V_2 != NULL ) {
if ( strcmp ( V_2 -> V_11 , V_97 ) == 0 ) {
V_2 -> V_6 ++ ;
break;
}
V_2 = V_2 -> V_9 ;
}
if ( V_2 == NULL ) {
V_2 = F_7 ( sizeof( struct V_1 ) , V_17 ) ;
if ( V_2 == NULL ) {
V_16 = - V_18 ;
} else {
V_2 -> V_39 = 0 ;
V_2 -> V_6 ++ ;
V_2 -> V_7 = V_4 ;
V_2 -> V_11 = F_7 ( strlen ( V_97 ) + 1 ,
V_17 ) ;
if ( V_2 -> V_11 == NULL ) {
V_16 = - V_18 ;
} else {
strncpy ( V_2 -> V_11 , V_97 ,
strlen ( V_97 ) + 1 ) ;
}
V_2 -> V_12 = NULL ;
}
}
if ( V_16 )
goto V_99;
V_2 -> V_57 . V_58 . V_59 = V_60 ;
V_2 -> V_57 . V_58 . V_61 = V_62 ;
V_2 -> V_57 . V_31 = V_2 ;
V_2 -> V_63 . V_64 . V_67 = V_69 ;
V_2 -> V_63 . V_64 . V_65 = V_66 ;
V_2 -> V_63 . V_64 . V_70 = V_71 ;
V_2 -> V_63 . V_64 . V_72 = V_73 ;
V_2 -> V_63 . V_64 . V_74 = V_75 ;
V_2 -> V_63 . V_64 . V_76 = V_77 ;
V_2 -> V_63 . V_31 = V_2 ;
V_2 -> V_73 . V_78 . V_72 = V_79 ;
V_2 -> V_73 . V_78 . V_74 = V_80 ;
V_2 -> V_73 . V_31 = V_2 ;
V_2 -> V_81 . V_82 . V_83 = V_83 ;
V_2 -> V_81 . V_82 . V_84 = V_85 ;
V_2 -> V_81 . V_82 . V_86 = V_87 ;
V_2 -> V_81 . V_82 . V_88 = V_89 ;
V_2 -> V_81 . V_82 . V_90 = V_90 ;
V_2 -> V_81 . V_82 . V_91 = V_91 ;
V_2 -> V_81 . V_31 = V_2 ;
if ( ! V_16 && V_2 -> V_38 == NULL )
V_16 = F_18 ( V_2 ) ;
V_2 -> V_39 = ( * ( V_2 -> V_7 -> V_19 . ftell ) ) ( V_2 -> V_38 ) ;
( * ( V_2 -> V_7 -> V_19 . fseek ) ) ( V_2 -> V_38 , ( long ) 0 , V_40 ) ;
if ( V_2 -> V_12 != NULL || ! ( V_46 & V_100 ) )
goto V_99;
V_2 -> V_12 =
F_24 ( V_53 , sizeof( struct V_24 ) , V_54 ,
V_55 , V_56 ) ;
if ( V_2 -> V_12 == NULL ) {
V_16 = - V_18 ;
} else {
V_2 -> V_81 . V_82 . V_86 = V_101 ;
V_50 = F_28 ( & V_2 -> V_57 . V_58 ,
& V_2 -> V_63 . V_64 ,
& V_2 -> V_73 . V_78 ,
& V_2 -> V_81 . V_82 , 0 ,
& V_2 -> V_94 ) ;
if ( V_50 != 0 ) {
V_16 = - V_95 ;
} else {
V_50 = F_29 ( V_2 -> V_94 ,
& V_2 -> V_63 . V_64 ,
& V_2 -> V_73 . V_78 ,
& V_2 -> V_81 . V_82 ) ;
if ( V_50 != 0 )
V_16 = - V_95 ;
V_2 -> V_94 = NULL ;
}
}
V_99:
if ( ! V_16 ) {
if ( V_2 -> V_6 == 1 ) {
if ( V_4 -> V_8 )
( V_4 -> V_8 ) -> V_10 = V_2 ;
V_2 -> V_10 = NULL ;
V_2 -> V_9 = V_4 -> V_8 ;
V_4 -> V_8 = V_2 ;
}
* V_98 = (struct V_1 * ) V_2 ;
} else {
* V_98 = NULL ;
if ( V_2 != NULL )
F_1 ( (struct V_1 * ) V_2 ) ;
}
F_8 ( ( ! V_16 && ( V_2 -> V_6 > 0 ) && * V_98 )
|| ( V_16 && * V_98 == NULL ) ) ;
F_14 ( V_27 , L_5 ,
V_28 , V_20 , V_97 , V_98 , V_16 ) ;
return V_16 ;
}
int F_30 ( struct V_1 * V_31 , char * V_21 ,
char * V_102 , T_1 V_44 )
{
struct V_1 * V_2 = (struct V_1 * ) V_31 ;
bool V_35 = false ;
T_1 V_34 ;
T_1 V_103 ;
const struct V_36 * V_37 = NULL ;
int V_16 = 0 ;
F_2 ( V_5 > 0 ) ;
F_2 ( V_2 ) ;
F_2 ( V_21 != NULL ) ;
F_2 ( V_102 != NULL ) ;
F_2 ( V_44 != 0 ) ;
if ( V_2 != NULL ) {
if ( V_2 -> V_38 == NULL ) {
V_16 = F_18 ( V_2 ) ;
if ( ! V_16 )
V_35 = true ;
} else {
( * ( V_2 -> V_7 -> V_19 . fseek ) ) ( V_2 -> V_38 ,
V_2 -> V_39 ,
V_40 ) ;
}
} else {
V_16 = - V_41 ;
}
if ( V_16 )
goto V_99;
V_34 = 1 ;
if ( ! F_19 ( V_2 -> V_42 , V_21 , & V_37 ) ) {
V_16 = - V_45 ;
goto V_99;
}
V_103 = V_37 -> V_44 * V_34 ;
if ( V_103 % 2 )
V_103 ++ ;
V_103 = F_20 ( V_103 ) ;
if ( V_103 > V_44 ) {
V_16 = - V_104 ;
} else {
if ( ! F_31 ( V_2 -> V_42 , V_37 , V_102 ) )
V_16 = - V_105 ;
}
V_99:
if ( V_35 ) {
F_3 ( V_2 ) ;
V_35 = false ;
}
F_14 ( V_27 , L_6
L_3 , V_28 , V_31 , V_21 , V_102 , V_44 , V_16 ) ;
return V_16 ;
}
void F_26 ( struct V_1 * V_31 , struct V_13 * V_19 )
{
struct V_1 * V_2 = (struct V_1 * ) V_31 ;
T_3 V_50 = 0 ;
F_2 ( V_5 > 0 ) ;
F_2 ( V_2 ) ;
F_2 ( V_2 -> V_51 > 0 ) ;
F_14 ( V_27 , L_7 , V_28 , V_31 ) ;
V_2 -> V_51 -- ;
if ( V_2 -> V_51 != 0 )
goto V_106;
V_2 -> V_7 -> V_19 = * V_19 ;
if ( V_2 -> V_94 ) {
V_50 = F_29 ( V_2 -> V_94 ,
& V_2 -> V_63 . V_64 ,
& V_2 -> V_73 . V_78 ,
& V_2 -> V_81 . V_82 ) ;
if ( V_50 != 0 )
F_14 ( V_27 , L_8 , V_28 , V_50 ) ;
}
if ( V_2 -> V_12 != NULL ) {
F_5 ( V_2 -> V_12 ) ;
V_2 -> V_12 = NULL ;
}
F_3 ( V_2 ) ;
V_106:
F_8 ( V_2 -> V_51 >= 0 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
if ( V_2 -> V_42 ) {
F_32 ( V_2 -> V_42 ) ;
V_2 -> V_42 = NULL ;
}
if ( V_2 -> V_38 ) {
( V_2 -> V_7 -> V_19 . fclose ) ( V_2 -> V_38 ) ;
V_2 -> V_38 = NULL ;
}
}
static int F_18 ( struct V_1 * V_2 )
{
void * V_107 = * ( V_2 -> V_7 -> V_19 . fopen ) ;
int V_16 = 0 ;
V_2 -> V_38 =
( void * ) ( ( V_108 ) ( V_107 ) ) ( V_2 -> V_11 , L_9 ) ;
if ( V_2 -> V_38 && V_2 -> V_42 == NULL ) {
( * ( V_2 -> V_7 -> V_19 . fseek ) ) ( V_2 -> V_38 , ( long ) 0 ,
V_40 ) ;
V_2 -> V_42 =
F_33 ( & V_2 -> V_57 . V_58 ,
& V_2 -> V_63 . V_64 ) ;
if ( V_2 -> V_42 == NULL ) {
( V_2 -> V_7 -> V_19 . fclose ) ( V_2 -> V_38 ) ;
V_2 -> V_38 = NULL ;
V_16 = - V_105 ;
}
} else {
V_16 = - V_105 ;
}
return V_16 ;
}
static T_4 V_54 ( void * V_109 , T_4 V_110 )
{
T_4 V_111 ;
T_4 V_112 ;
char * V_21 = ( char * ) V_109 ;
F_2 ( V_21 != NULL ) ;
V_112 = 0 ;
while ( * V_21 ) {
V_112 <<= 1 ;
V_112 ^= * V_21 ++ ;
}
V_111 = V_112 % V_110 ;
return V_111 ;
}
static bool V_55 ( void * V_109 , void * V_113 )
{
F_2 ( V_109 != NULL ) ;
F_2 ( V_113 != NULL ) ;
if ( ( V_109 != NULL ) && ( V_113 != NULL ) ) {
if ( strcmp ( ( char * ) V_109 , ( (struct V_24 * ) V_113 ) -> V_21 ) ==
0 )
return true ;
}
return false ;
}
static int V_101 ( struct V_114 * V_115 , void * V_116 ,
T_5 V_117 , struct V_36 * V_118 , unsigned V_119 )
{
return 1 ;
}
static void V_56 ( void * V_26 )
{
struct V_24 * V_113 = (struct V_24 * ) V_26 ;
F_4 ( V_113 -> V_21 ) ;
}
static int V_60 ( struct V_120 * V_121 , void * V_122 ,
unsigned V_123 )
{
struct V_124 * V_125 = (struct V_124 * ) V_121 ;
struct V_1 * V_31 ;
int V_126 = 0 ;
F_2 ( V_121 != NULL ) ;
V_31 = V_125 -> V_31 ;
F_2 ( V_31 ) ;
if ( V_31 != NULL ) {
V_126 =
( * ( V_31 -> V_7 -> V_19 . fread ) ) ( V_122 , 1 , V_123 ,
V_31 -> V_38 ) ;
}
return V_126 ;
}
static int V_62 ( struct V_120 * V_121 ,
unsigned int V_39 )
{
struct V_124 * V_125 = (struct V_124 * ) V_121 ;
struct V_1 * V_31 ;
int V_16 = 0 ;
F_2 ( V_121 != NULL ) ;
V_31 = V_125 -> V_31 ;
F_2 ( V_31 ) ;
if ( V_31 != NULL ) {
V_16 = ( * ( V_31 -> V_7 -> V_19 . fseek ) ) ( V_31 -> V_38 , ( long ) V_39 ,
V_40 ) ;
}
return V_16 ;
}
static struct V_127 * V_66 ( struct V_128 * V_121 ,
const char * V_21 )
{
struct V_127 * V_129 ;
struct V_130 * V_131 = (struct V_130 * ) V_121 ;
struct V_1 * V_31 ;
struct V_22 * V_132 = NULL ;
bool V_16 = false ;
F_2 ( V_121 != NULL ) ;
V_31 = V_131 -> V_31 ;
F_2 ( V_31 ) ;
if ( V_31 != NULL ) {
if ( V_31 -> V_7 -> V_19 . V_133 ) {
V_16 = ( * ( V_31 -> V_7 -> V_19 . V_133 ) )
( V_31 -> V_7 -> V_19 . V_134 ,
V_31 -> V_7 -> V_19 . V_135 ,
V_31 -> V_7 -> V_19 . V_136 , V_21 ,
& V_132 ) ;
} else {
V_16 = F_12 ( (struct V_1 * ) V_31 ,
( char * ) V_21 , & V_132 ) ;
if ( ! V_16 ) {
V_16 =
F_16 ( (struct V_1 * )
V_31 , ( char * ) V_21 ,
& V_132 ) ;
}
}
}
if ( ! V_16 && V_137 )
F_14 ( V_27 , L_10 , V_28 , V_21 ) ;
F_34 ( ( V_16 && ( V_132 != NULL ) )
|| ( ! V_16 && ( V_132 == NULL ) ) ) ;
V_129 = (struct V_127 * ) V_132 ;
return V_129 ;
}
static struct V_127 * V_68 ( struct V_128
* V_121 , const char * V_21 ,
unsigned V_138 )
{
struct V_127 * V_129 ;
struct V_130 * V_131 = (struct V_130 * ) V_121 ;
struct V_1 * V_31 ;
struct V_24 * V_25 ;
F_2 ( V_121 != NULL ) ;
V_31 = V_131 -> V_31 ;
F_2 ( V_31 ) ;
F_2 ( V_31 -> V_12 != NULL ) ;
V_25 = (struct V_24 * ) F_13 ( V_31 -> V_12 , ( char * ) V_21 ) ;
V_129 = (struct V_127 * ) & V_25 -> V_26 ;
return V_129 ;
}
static struct V_127 * V_69 ( struct V_128
* V_121 , const char * V_21 ,
unsigned V_139 )
{
struct V_24 * V_140 = NULL ;
struct V_24 V_63 ;
struct V_127 * V_132 = NULL ;
struct V_130 * V_131 = (struct V_130 * ) V_121 ;
struct V_1 * V_31 ;
struct V_127 * V_111 ;
F_2 ( V_121 != NULL ) ;
F_2 ( V_21 ) ;
V_31 = V_131 -> V_31 ;
F_2 ( V_31 ) ;
if ( ! ( V_31 -> V_7 -> V_19 . V_141 ) ) {
V_137 = false ;
V_132 = V_66 ( V_121 , V_21 ) ;
V_137 = true ;
if ( V_132 ) {
V_96 = true ;
F_14 ( V_27 , L_11 ,
V_21 ) ;
return NULL ;
}
}
V_63 . V_21 = F_7 ( strlen ( ( char * const ) V_21 ) + 1 , V_17 ) ;
if ( V_63 . V_21 == NULL )
return NULL ;
if ( V_63 . V_21 != NULL ) {
strncpy ( V_63 . V_21 , ( char * const ) V_21 ,
strlen ( ( char * const ) V_21 ) + 1 ) ;
V_140 =
(struct V_24 * ) F_35 ( V_31 -> V_12 , ( void * ) V_21 ,
( void * ) & V_63 ) ;
if ( V_140 == NULL )
F_4 ( V_63 . V_21 ) ;
}
if ( V_140 != NULL )
V_111 = (struct V_127 * ) & V_140 -> V_26 ;
else
V_111 = NULL ;
return V_111 ;
}
static void V_71 ( struct V_128 * V_121 ,
unsigned V_139 )
{
struct V_130 * V_131 = (struct V_130 * ) V_121 ;
struct V_1 * V_31 ;
F_2 ( V_121 != NULL ) ;
V_31 = V_131 -> V_31 ;
F_2 ( V_31 ) ;
}
static void * V_73 ( struct V_128 * V_121 , unsigned V_142 )
{
struct V_130 * V_131 = (struct V_130 * ) V_121 ;
struct V_1 * V_31 ;
void * V_102 ;
F_2 ( V_121 != NULL ) ;
V_31 = V_131 -> V_31 ;
F_2 ( V_31 ) ;
V_102 = F_7 ( V_142 , V_17 ) ;
return V_102 ;
}
static void V_75 ( struct V_128 * V_121 , void * V_143 )
{
struct V_130 * V_131 = (struct V_130 * ) V_121 ;
struct V_1 * V_31 ;
F_2 ( V_121 != NULL ) ;
V_31 = V_131 -> V_31 ;
F_2 ( V_31 ) ;
F_4 ( V_143 ) ;
}
static void V_77 ( struct V_128 * V_121 , const char * V_144 ,
T_6 args )
{
struct V_130 * V_131 = (struct V_130 * ) V_121 ;
struct V_1 * V_31 ;
char V_145 [ V_30 ] ;
F_2 ( V_121 != NULL ) ;
V_31 = V_131 -> V_31 ;
F_2 ( V_31 ) ;
vsnprintf ( ( char * ) V_145 , V_30 , ( char * ) V_144 , args ) ;
F_14 ( V_27 , L_12 , V_145 ) ;
}
static int V_79 ( struct V_146 * V_121 ,
struct V_36 * V_118 , unsigned V_147 )
{
struct V_148 * V_149 = (struct V_148 * ) V_121 ;
struct V_1 * V_31 ;
int V_16 = 0 ;
T_1 V_150 ;
struct V_151 V_152 ;
T_3 V_111 = true ;
unsigned V_153 = F_36 ( V_118 -> type ) ;
char * V_154 = NULL ;
char * V_155 = NULL ;
char * V_156 = NULL ;
char * V_157 = NULL ;
char * V_158 ;
T_3 V_159 = 0 ;
T_3 V_160 = - 1 ;
T_3 V_161 = - 1 ;
T_3 V_162 = 0 ;
T_1 V_163 = 0 ;
T_1 V_164 = 0 ;
F_2 ( V_121 != NULL ) ;
V_31 = V_149 -> V_31 ;
F_2 ( V_31 ) ;
V_150 =
( V_153 == V_165 ) ? V_166 : ( V_153 ==
V_167 ) ? V_168 :
V_169 ;
F_2 ( V_118 -> V_21 ) ;
V_159 = strlen ( ( char * ) ( V_118 -> V_21 ) ) + 1 ;
V_157 = F_7 ( V_159 , V_17 ) ;
V_156 = F_7 ( V_159 , V_17 ) ;
V_155 = F_7 ( V_159 , V_17 ) ;
if ( V_157 == NULL || V_155 == NULL ||
V_156 == NULL ) {
V_16 = - V_18 ;
goto V_99;
}
strncpy ( V_157 , ( char * ) ( V_118 -> V_21 ) , V_159 ) ;
V_158 = V_157 ;
while ( ( V_154 = F_37 ( & V_158 , L_13 ) ) && * V_154 != '\0' ) {
strncpy ( V_155 , V_156 ,
strlen ( V_156 ) + 1 ) ;
strncpy ( V_156 , V_154 , strlen ( V_154 ) + 1 ) ;
V_154 = F_37 ( & V_158 , L_13 ) ;
V_162 ++ ;
}
if ( V_162 >= 3 )
F_38 ( V_156 , 10 , ( long * ) & V_161 ) ;
if ( ( V_161 == 0 ) || ( V_161 == 1 ) ) {
if ( strcmp ( V_155 , L_14 ) == 0 ) {
V_160 = 0 ;
} else {
if ( strcmp ( V_155 , L_15 ) == 0 ) {
V_160 = 1 ;
} else {
if ( strcmp ( V_155 ,
L_16 ) == 0 )
V_160 = 2 ;
}
}
}
V_99:
F_4 ( V_157 ) ;
V_157 = NULL ;
F_4 ( V_156 ) ;
V_156 = NULL ;
F_4 ( V_155 ) ;
V_155 = NULL ;
if ( V_150 == V_166 )
V_163 = V_118 -> V_44 + V_170 ;
else
V_163 = V_118 -> V_44 ;
if ( V_118 -> V_43 != V_118 -> V_171 )
V_164 = 1 ;
if ( V_31 != NULL ) {
V_16 =
( V_31 -> V_7 -> V_19 . V_172 ) ( V_31 -> V_7 -> V_19 .
V_136 , V_150 ,
V_163 , V_147 ,
( T_1 * ) & V_152 ,
V_160 , V_161 , false ) ;
}
if ( V_16 ) {
V_111 = false ;
} else {
V_118 -> V_43 = V_152 . V_173 * V_174 ;
if ( ! V_164 )
V_118 -> V_171 = V_118 -> V_43 ;
V_118 -> V_175 = ( T_1 ) V_152 . V_176 ;
F_14 ( V_27 , L_17
L_18 ,
V_28 , V_118 -> V_21 , V_118 -> V_43 / V_174 ,
V_118 -> V_44 / V_174 , V_118 -> V_171 ,
V_118 -> V_43 ) ;
}
return V_111 ;
}
static void V_80 ( struct V_146 * V_121 ,
struct V_36 * V_118 )
{
struct V_148 * V_149 = (struct V_148 * ) V_121 ;
struct V_1 * V_31 ;
T_1 V_176 ;
int V_16 = 0 ;
unsigned V_153 = F_36 ( V_118 -> type ) ;
T_1 V_150 ;
T_1 V_177 = 0 ;
V_150 =
( V_153 == V_165 ) ? V_166 : ( V_153 ==
V_167 ) ? V_168 :
V_169 ;
F_2 ( V_121 != NULL ) ;
V_31 = V_149 -> V_31 ;
F_2 ( V_31 ) ;
V_176 = ( T_1 ) V_118 -> V_175 ;
if ( V_150 == V_166 )
V_177 = V_118 -> V_44 + V_170 ;
else
V_177 = V_118 -> V_44 ;
if ( V_31 != NULL ) {
V_16 =
( V_31 -> V_7 -> V_19 . free ) ( V_31 -> V_7 -> V_19 .
V_134 , V_176 ,
V_118 -> V_43 /
V_174 , V_177 ,
false ) ;
}
}
static int V_83 ( struct V_114 * V_121 )
{
return true ;
}
static int V_85 ( struct V_114 * V_121 , void * V_102 ,
T_5 V_173 , struct V_36 * V_118 ,
unsigned V_178 )
{
struct V_179 * V_180 = (struct V_179 * ) V_121 ;
struct V_1 * V_31 ;
int V_126 = 0 ;
F_2 ( V_121 != NULL ) ;
V_31 = V_180 -> V_31 ;
F_2 ( V_31 ) ;
return V_126 ;
}
static int V_87 ( struct V_114 * V_121 , void * V_102 ,
T_5 V_173 , struct V_36 * V_118 ,
unsigned V_181 )
{
struct V_179 * V_180 = (struct V_179 * ) V_121 ;
struct V_1 * V_31 ;
struct V_3 * V_7 ;
struct V_182 V_183 ;
T_1 V_150 ;
bool V_111 = true ;
F_2 ( V_121 != NULL ) ;
V_31 = V_180 -> V_31 ;
if ( ! V_31 )
return false ;
V_7 = V_31 -> V_7 ;
V_150 =
( F_36 ( V_118 -> type ) ==
V_165 ) ? V_166 : V_169 ;
if ( V_7 && V_7 -> V_19 . V_184 ) {
V_111 =
(* V_7 -> V_19 . V_184 ) ( V_7 -> V_19 . V_185 ,
V_173 , V_102 , V_181 ,
V_150 ) ;
if ( V_7 -> V_19 . V_186 ) {
V_183 . V_21 = V_118 -> V_21 ;
V_183 . V_187 = V_118 -> V_171 ;
V_183 . V_188 = V_118 -> V_43 ;
V_183 . V_44 = V_118 -> V_44 ;
V_183 . type = V_150 ;
(* V_7 -> V_19 . V_186 ) ( V_7 -> V_19 .
V_189 ,
& V_183 , V_173 ,
V_181 ) ;
}
}
return V_111 ;
}
static int V_89 ( struct V_114 * V_121 , T_5 V_173 ,
struct V_36 * V_118 , unsigned V_181 , unsigned V_190 )
{
bool V_111 = true ;
char * V_191 ;
struct V_1 * V_31 ;
struct V_179 * V_180 = (struct V_179 * ) V_121 ;
F_2 ( V_121 != NULL ) ;
V_31 = V_180 -> V_31 ;
V_191 = NULL ;
if ( ( V_31 -> V_7 -> V_19 . V_184 ) != ( V_192 ) V_101 )
V_87 ( V_121 , & V_191 , V_173 , V_118 , 0 ) ;
if ( V_191 )
memset ( V_191 , V_190 , V_181 ) ;
return V_111 ;
}
static int V_90 ( struct V_114 * V_121 , T_5 V_193 )
{
struct V_179 * V_180 = (struct V_179 * ) V_121 ;
struct V_1 * V_31 ;
bool V_111 = true ;
F_2 ( V_121 != NULL ) ;
V_31 = V_180 -> V_31 ;
F_2 ( V_31 ) ;
if ( V_31 != NULL )
V_31 -> V_47 = ( T_1 ) V_193 ;
return V_111 ;
}
static void V_91 ( struct V_114 * V_121 )
{
}
void F_39 ( void * V_194 , void * V_195 )
{
struct V_24 * V_63 = V_194 ;
struct V_196 * V_175 = V_195 ;
T_1 V_197 = V_63 -> V_26 . V_26 ;
T_1 V_198 = V_175 -> V_199 - V_197 ;
if ( V_175 -> V_199 >= V_197 && V_197 < ( T_1 ) - 1 &&
V_198 < V_175 -> V_200 ) {
V_175 -> V_200 = V_198 ;
V_175 -> V_201 = V_197 ;
strncpy ( V_175 -> V_21 , V_63 -> V_21 , sizeof( V_175 -> V_21 ) ) ;
}
return;
}
bool F_40 ( struct V_1 * V_2 , T_1 V_199 ,
T_1 V_202 , T_1 * V_203 ,
char * V_204 )
{
bool V_16 = false ;
struct V_196 V_175 ;
V_175 . V_199 = V_199 ;
V_175 . V_202 = V_202 ;
V_175 . V_200 = V_202 ;
V_175 . V_201 = 0 ;
V_175 . V_21 [ 0 ] = '\0' ;
F_41 ( V_2 -> V_12 , F_39 , & V_175 ) ;
if ( V_175 . V_21 [ 0 ] ) {
V_16 = true ;
strcpy ( V_204 , V_175 . V_21 ) ;
* V_203 = V_175 . V_201 ;
}
return V_16 ;
}
