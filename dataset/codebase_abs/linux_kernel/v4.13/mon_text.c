static inline char F_1 ( struct V_1 * V_2 ,
struct V_3 * V_3 , char V_4 , struct V_5 * V_6 )
{
if ( V_2 -> V_7 != V_8 || V_4 != 'S' )
return '-' ;
if ( V_3 -> V_9 == NULL )
return 'Z' ;
memcpy ( V_2 -> V_10 , V_3 -> V_9 , V_11 ) ;
return 0 ;
}
static inline char F_2 ( struct V_1 * V_2 , struct V_3 * V_3 ,
int V_12 , char V_4 , struct V_5 * V_6 )
{
void * V_13 ;
if ( V_12 <= 0 )
return 'L' ;
if ( V_12 >= V_14 )
V_12 = V_14 ;
if ( V_2 -> V_15 ) {
if ( V_4 != 'C' )
return '<' ;
} else {
if ( V_4 != 'S' )
return '>' ;
}
if ( V_3 -> V_16 == 0 ) {
V_13 = V_3 -> V_17 ;
if ( V_13 == NULL )
return 'Z' ;
} else {
struct V_18 * V_19 = V_3 -> V_19 ;
if ( F_3 ( F_4 ( V_19 ) ) )
return 'D' ;
V_12 = F_5 ( int , V_19 -> V_20 , V_12 ) ;
V_13 = F_6 ( V_19 ) ;
}
memcpy ( V_2 -> V_21 , V_13 , V_12 ) ;
return 0 ;
}
static inline unsigned int F_7 ( void )
{
struct V_22 V_23 ;
unsigned int V_24 ;
F_8 ( & V_23 ) ;
V_24 = V_23 . V_25 & 0xFFF ;
V_24 = V_24 * V_26 + V_23 . V_27 / V_28 ;
return V_24 ;
}
static void F_9 ( struct V_29 * V_30 , struct V_3 * V_3 ,
char V_4 , int V_31 )
{
struct V_1 * V_2 ;
unsigned int V_24 ;
struct V_32 * V_33 ;
struct V_34 * V_35 ;
int V_36 , V_37 ;
V_24 = F_7 () ;
if ( V_30 -> V_38 >= V_39 ||
( V_2 = F_10 ( V_30 -> V_40 , V_41 ) ) == NULL ) {
V_30 -> V_42 . V_43 -> V_44 ++ ;
return;
}
V_2 -> type = V_4 ;
V_2 -> V_45 = ( unsigned long ) V_3 ;
V_2 -> V_46 = V_3 -> V_47 -> V_48 -> V_46 ;
V_2 -> V_49 = V_3 -> V_47 -> V_49 ;
V_2 -> V_50 = F_11 ( & V_3 -> V_2 -> V_51 ) ;
V_2 -> V_7 = F_12 ( & V_3 -> V_2 -> V_51 ) ;
V_2 -> V_15 = F_13 ( V_3 ) ;
V_2 -> V_52 = V_24 ;
V_2 -> V_20 = ( V_4 == 'S' ) ?
V_3 -> V_53 : V_3 -> V_54 ;
V_2 -> V_31 = V_31 ;
if ( V_2 -> V_7 == V_55 ) {
V_2 -> V_56 = V_3 -> V_56 ;
} else if ( V_2 -> V_7 == V_57 ) {
V_2 -> V_56 = V_3 -> V_56 ;
V_2 -> V_58 = V_3 -> V_58 ;
V_2 -> V_59 = V_3 -> V_59 ;
}
V_2 -> V_60 = V_3 -> V_61 ;
if ( V_2 -> V_7 == V_57 &&
V_3 -> V_61 > 0 ) {
if ( ( V_37 = V_3 -> V_61 ) > V_62 )
V_37 = V_62 ;
V_33 = V_3 -> V_63 ;
V_35 = V_2 -> V_64 ;
for ( V_36 = 0 ; V_36 < V_37 ; V_36 ++ ) {
V_35 -> V_31 = V_33 -> V_31 ;
V_35 -> V_65 = V_33 -> V_65 ;
V_35 -> V_20 = ( V_4 == 'S' ) ?
V_33 -> V_20 : V_33 -> V_54 ;
V_33 ++ ;
V_35 ++ ;
}
if ( V_4 == 'C' )
V_2 -> V_20 = V_3 -> V_53 ;
}
V_2 -> V_66 = F_1 ( V_2 , V_3 , V_4 , V_30 -> V_42 . V_43 ) ;
V_2 -> V_67 = F_2 ( V_2 , V_3 , V_2 -> V_20 , V_4 ,
V_30 -> V_42 . V_43 ) ;
V_30 -> V_38 ++ ;
F_14 ( & V_2 -> V_68 , & V_30 -> V_69 ) ;
F_15 ( & V_30 -> V_70 ) ;
}
static void F_16 ( void * V_21 , struct V_3 * V_3 )
{
struct V_29 * V_30 = V_21 ;
F_9 ( V_30 , V_3 , 'S' , - V_71 ) ;
}
static void F_17 ( void * V_21 , struct V_3 * V_3 , int V_31 )
{
struct V_29 * V_30 = V_21 ;
F_9 ( V_30 , V_3 , 'C' , V_31 ) ;
}
static void F_18 ( void * V_21 , struct V_3 * V_3 , int error )
{
struct V_29 * V_30 = V_21 ;
struct V_1 * V_2 ;
if ( V_30 -> V_38 >= V_39 ||
( V_2 = F_10 ( V_30 -> V_40 , V_41 ) ) == NULL ) {
V_30 -> V_42 . V_43 -> V_44 ++ ;
return;
}
V_2 -> type = 'E' ;
V_2 -> V_45 = ( unsigned long ) V_3 ;
V_2 -> V_46 = V_3 -> V_47 -> V_48 -> V_46 ;
V_2 -> V_49 = V_3 -> V_47 -> V_49 ;
V_2 -> V_50 = F_11 ( & V_3 -> V_2 -> V_51 ) ;
V_2 -> V_7 = F_12 ( & V_3 -> V_2 -> V_51 ) ;
V_2 -> V_15 = F_13 ( V_3 ) ;
V_2 -> V_52 = F_7 () ;
V_2 -> V_20 = 0 ;
V_2 -> V_31 = error ;
V_2 -> V_66 = '-' ;
V_2 -> V_67 = 'E' ;
V_30 -> V_38 ++ ;
F_14 ( & V_2 -> V_68 , & V_30 -> V_69 ) ;
F_15 ( & V_30 -> V_70 ) ;
}
static struct V_1 * F_19 ( struct V_29 * V_30 ,
struct V_5 * V_6 )
{
struct V_72 * V_73 ;
unsigned long V_74 ;
F_20 ( & V_6 -> V_75 , V_74 ) ;
if ( F_21 ( & V_30 -> V_69 ) ) {
F_22 ( & V_6 -> V_75 , V_74 ) ;
return NULL ;
}
V_73 = V_30 -> V_69 . V_76 ;
F_23 ( V_73 ) ;
-- V_30 -> V_38 ;
F_22 ( & V_6 -> V_75 , V_74 ) ;
return F_24 ( V_73 , struct V_1 , V_68 ) ;
}
static int F_25 ( struct V_77 * V_77 , struct V_78 * V_78 )
{
struct V_5 * V_6 ;
struct V_29 * V_30 ;
int V_79 ;
F_26 ( & V_80 ) ;
V_6 = V_77 -> V_81 ;
V_30 = F_27 ( sizeof( struct V_29 ) , V_82 ) ;
if ( V_30 == NULL ) {
V_79 = - V_83 ;
goto V_84;
}
F_28 ( & V_30 -> V_69 ) ;
F_29 ( & V_30 -> V_70 ) ;
F_30 ( & V_30 -> V_85 ) ;
V_30 -> V_86 = V_87 ;
V_30 -> V_88 = F_31 ( V_30 -> V_86 , V_82 ) ;
if ( V_30 -> V_88 == NULL ) {
V_79 = - V_83 ;
goto V_89;
}
V_30 -> V_42 . V_43 = V_6 ;
V_30 -> V_42 . V_90 = V_30 ;
V_30 -> V_42 . V_91 = F_16 ;
V_30 -> V_42 . V_92 = F_18 ;
V_30 -> V_42 . V_93 = F_17 ;
snprintf ( V_30 -> V_94 , V_95 , L_1 , V_30 ) ;
V_30 -> V_40 = F_32 ( V_30 -> V_94 ,
sizeof( struct V_1 ) , sizeof( long ) , 0 ,
V_96 ) ;
if ( V_30 -> V_40 == NULL ) {
V_79 = - V_83 ;
goto V_97;
}
F_33 ( V_6 , & V_30 -> V_42 ) ;
V_78 -> V_98 = V_30 ;
F_34 ( & V_80 ) ;
return 0 ;
V_97:
F_35 ( V_30 -> V_88 ) ;
V_89:
F_35 ( V_30 ) ;
V_84:
F_34 ( & V_80 ) ;
return V_79 ;
}
static T_1 F_36 ( struct V_78 * V_78 , char T_2 * V_99 ,
T_3 V_100 , T_4 * V_101 )
{
struct V_29 * V_30 = V_78 -> V_98 ;
struct V_1 * V_2 ;
struct V_102 V_103 ;
V_2 = F_37 ( V_30 , V_78 ) ;
if ( F_38 ( V_2 ) )
return F_39 ( V_2 ) ;
F_26 ( & V_30 -> V_85 ) ;
V_103 . V_104 = 0 ;
V_103 . V_105 = V_30 -> V_88 ;
V_103 . V_106 = V_30 -> V_86 ;
F_40 ( V_30 , & V_103 , V_2 ) ;
F_41 ( V_30 , & V_103 , V_2 ) ;
V_103 . V_104 += snprintf ( V_103 . V_105 + V_103 . V_104 , V_103 . V_106 - V_103 . V_104 ,
L_2 , V_2 -> V_20 ) ;
F_42 ( V_30 , & V_103 , V_2 ) ;
if ( F_43 ( V_99 , V_30 -> V_88 , V_103 . V_104 ) )
V_103 . V_104 = - V_107 ;
F_34 ( & V_30 -> V_85 ) ;
F_44 ( V_30 -> V_40 , V_2 ) ;
return V_103 . V_104 ;
}
static T_1 F_45 ( struct V_78 * V_78 , char T_2 * V_99 ,
T_3 V_100 , T_4 * V_101 )
{
struct V_29 * V_30 = V_78 -> V_98 ;
struct V_1 * V_2 ;
struct V_102 V_103 ;
V_2 = F_37 ( V_30 , V_78 ) ;
if ( F_38 ( V_2 ) )
return F_39 ( V_2 ) ;
F_26 ( & V_30 -> V_85 ) ;
V_103 . V_104 = 0 ;
V_103 . V_105 = V_30 -> V_88 ;
V_103 . V_106 = V_30 -> V_86 ;
F_46 ( V_30 , & V_103 , V_2 ) ;
if ( V_2 -> type == 'E' ) {
F_41 ( V_30 , & V_103 , V_2 ) ;
} else if ( V_2 -> V_7 == V_57 ) {
F_47 ( V_30 , & V_103 , V_2 ) ;
F_48 ( V_30 , & V_103 , V_2 ) ;
} else if ( V_2 -> V_7 == V_55 ) {
F_49 ( V_30 , & V_103 , V_2 ) ;
} else {
F_41 ( V_30 , & V_103 , V_2 ) ;
}
V_103 . V_104 += snprintf ( V_103 . V_105 + V_103 . V_104 , V_103 . V_106 - V_103 . V_104 ,
L_2 , V_2 -> V_20 ) ;
F_42 ( V_30 , & V_103 , V_2 ) ;
if ( F_43 ( V_99 , V_30 -> V_88 , V_103 . V_104 ) )
V_103 . V_104 = - V_107 ;
F_34 ( & V_30 -> V_85 ) ;
F_44 ( V_30 -> V_40 , V_2 ) ;
return V_103 . V_104 ;
}
static struct V_1 * F_37 ( struct V_29 * V_30 ,
struct V_78 * V_78 )
{
struct V_5 * V_6 = V_30 -> V_42 . V_43 ;
F_50 ( V_108 , V_109 ) ;
struct V_1 * V_2 ;
F_51 ( & V_30 -> V_70 , & V_108 ) ;
F_52 ( V_110 ) ;
while ( ( V_2 = F_19 ( V_30 , V_6 ) ) == NULL ) {
if ( V_78 -> V_111 & V_112 ) {
F_52 ( V_113 ) ;
F_53 ( & V_30 -> V_70 , & V_108 ) ;
return F_54 ( - V_114 ) ;
}
F_55 () ;
if ( F_56 ( V_109 ) ) {
F_53 ( & V_30 -> V_70 , & V_108 ) ;
return F_54 ( - V_115 ) ;
}
F_52 ( V_110 ) ;
}
F_52 ( V_113 ) ;
F_53 ( & V_30 -> V_70 , & V_108 ) ;
return V_2 ;
}
static void F_40 ( struct V_29 * V_30 ,
struct V_102 * V_73 , const struct V_1 * V_2 )
{
char V_116 , V_117 ;
V_116 = ( V_2 -> V_15 ? 'i' : 'o' ) ;
switch ( V_2 -> V_7 ) {
case V_57 : V_117 = 'Z' ; break;
case V_55 : V_117 = 'I' ; break;
case V_8 : V_117 = 'C' ; break;
default: V_117 = 'B' ;
}
V_73 -> V_104 += snprintf ( V_73 -> V_105 + V_73 -> V_104 , V_73 -> V_106 - V_73 -> V_104 ,
L_3 ,
V_2 -> V_45 , V_2 -> V_52 , V_2 -> type ,
V_117 , V_116 , V_2 -> V_49 , V_2 -> V_50 ) ;
}
static void F_46 ( struct V_29 * V_30 ,
struct V_102 * V_73 , const struct V_1 * V_2 )
{
char V_116 , V_117 ;
V_116 = ( V_2 -> V_15 ? 'i' : 'o' ) ;
switch ( V_2 -> V_7 ) {
case V_57 : V_117 = 'Z' ; break;
case V_55 : V_117 = 'I' ; break;
case V_8 : V_117 = 'C' ; break;
default: V_117 = 'B' ;
}
V_73 -> V_104 += snprintf ( V_73 -> V_105 + V_73 -> V_104 , V_73 -> V_106 - V_73 -> V_104 ,
L_4 ,
V_2 -> V_45 , V_2 -> V_52 , V_2 -> type ,
V_117 , V_116 , V_2 -> V_46 , V_2 -> V_49 , V_2 -> V_50 ) ;
}
static void F_41 ( struct V_29 * V_30 ,
struct V_102 * V_73 , const struct V_1 * V_2 )
{
if ( V_2 -> V_66 == 0 ) {
V_73 -> V_104 += snprintf ( V_73 -> V_105 + V_73 -> V_104 , V_73 -> V_106 - V_73 -> V_104 ,
L_5 ,
V_2 -> V_10 [ 0 ] ,
V_2 -> V_10 [ 1 ] ,
( V_2 -> V_10 [ 3 ] << 8 ) | V_2 -> V_10 [ 2 ] ,
( V_2 -> V_10 [ 5 ] << 8 ) | V_2 -> V_10 [ 4 ] ,
( V_2 -> V_10 [ 7 ] << 8 ) | V_2 -> V_10 [ 6 ] ) ;
} else if ( V_2 -> V_66 != '-' ) {
V_73 -> V_104 += snprintf ( V_73 -> V_105 + V_73 -> V_104 , V_73 -> V_106 - V_73 -> V_104 ,
L_6 , V_2 -> V_66 ) ;
} else {
V_73 -> V_104 += snprintf ( V_73 -> V_105 + V_73 -> V_104 , V_73 -> V_106 - V_73 -> V_104 ,
L_2 , V_2 -> V_31 ) ;
}
}
static void F_49 ( struct V_29 * V_30 ,
struct V_102 * V_73 , const struct V_1 * V_2 )
{
V_73 -> V_104 += snprintf ( V_73 -> V_105 + V_73 -> V_104 , V_73 -> V_106 - V_73 -> V_104 ,
L_7 , V_2 -> V_31 , V_2 -> V_56 ) ;
}
static void F_47 ( struct V_29 * V_30 ,
struct V_102 * V_73 , const struct V_1 * V_2 )
{
if ( V_2 -> type == 'S' ) {
V_73 -> V_104 += snprintf ( V_73 -> V_105 + V_73 -> V_104 , V_73 -> V_106 - V_73 -> V_104 ,
L_8 , V_2 -> V_31 , V_2 -> V_56 , V_2 -> V_58 ) ;
} else {
V_73 -> V_104 += snprintf ( V_73 -> V_105 + V_73 -> V_104 , V_73 -> V_106 - V_73 -> V_104 ,
L_9 ,
V_2 -> V_31 , V_2 -> V_56 , V_2 -> V_58 , V_2 -> V_59 ) ;
}
}
static void F_48 ( struct V_29 * V_30 ,
struct V_102 * V_73 , const struct V_1 * V_2 )
{
int V_37 ;
int V_36 ;
const struct V_34 * V_35 ;
V_73 -> V_104 += snprintf ( V_73 -> V_105 + V_73 -> V_104 , V_73 -> V_106 - V_73 -> V_104 ,
L_2 , V_2 -> V_60 ) ;
V_37 = V_2 -> V_60 ;
if ( V_37 > V_62 )
V_37 = V_62 ;
if ( V_37 < 0 )
V_37 = 0 ;
V_35 = V_2 -> V_64 ;
for ( V_36 = 0 ; V_36 < V_37 ; V_36 ++ ) {
V_73 -> V_104 += snprintf ( V_73 -> V_105 + V_73 -> V_104 , V_73 -> V_106 - V_73 -> V_104 ,
L_10 , V_35 -> V_31 , V_35 -> V_65 , V_35 -> V_20 ) ;
V_35 ++ ;
}
}
static void F_42 ( struct V_29 * V_30 ,
struct V_102 * V_73 , const struct V_1 * V_2 )
{
int V_118 , V_36 ;
if ( ( V_118 = V_2 -> V_20 ) > 0 ) {
if ( V_2 -> V_67 == 0 ) {
V_73 -> V_104 += snprintf ( V_73 -> V_105 + V_73 -> V_104 , V_73 -> V_106 - V_73 -> V_104 ,
L_11 ) ;
if ( V_118 >= V_14 )
V_118 = V_14 ;
for ( V_36 = 0 ; V_36 < V_118 ; V_36 ++ ) {
if ( V_36 % 4 == 0 ) {
V_73 -> V_104 += snprintf ( V_73 -> V_105 + V_73 -> V_104 ,
V_73 -> V_106 - V_73 -> V_104 ,
L_12 ) ;
}
V_73 -> V_104 += snprintf ( V_73 -> V_105 + V_73 -> V_104 ,
V_73 -> V_106 - V_73 -> V_104 ,
L_13 , V_2 -> V_21 [ V_36 ] ) ;
}
V_73 -> V_104 += snprintf ( V_73 -> V_105 + V_73 -> V_104 , V_73 -> V_106 - V_73 -> V_104 ,
L_14 ) ;
} else {
V_73 -> V_104 += snprintf ( V_73 -> V_105 + V_73 -> V_104 , V_73 -> V_106 - V_73 -> V_104 ,
L_15 , V_2 -> V_67 ) ;
}
} else {
V_73 -> V_104 += snprintf ( V_73 -> V_105 + V_73 -> V_104 , V_73 -> V_106 - V_73 -> V_104 , L_14 ) ;
}
}
static int F_57 ( struct V_77 * V_77 , struct V_78 * V_78 )
{
struct V_29 * V_30 = V_78 -> V_98 ;
struct V_5 * V_6 ;
struct V_72 * V_73 ;
struct V_1 * V_2 ;
F_26 ( & V_80 ) ;
V_6 = V_77 -> V_81 ;
if ( V_6 -> V_119 <= 0 ) {
F_58 (KERN_ERR TAG L_16 ) ;
F_34 ( & V_80 ) ;
return 0 ;
}
F_59 ( V_6 , & V_30 -> V_42 ) ;
while ( ! F_21 ( & V_30 -> V_69 ) ) {
V_73 = V_30 -> V_69 . V_76 ;
V_2 = F_24 ( V_73 , struct V_1 , V_68 ) ;
F_23 ( V_73 ) ;
-- V_30 -> V_38 ;
F_44 ( V_30 -> V_40 , V_2 ) ;
}
F_60 ( V_30 -> V_40 ) ;
F_35 ( V_30 -> V_88 ) ;
F_35 ( V_30 ) ;
F_34 ( & V_80 ) ;
return 0 ;
}
int F_61 ( struct V_5 * V_6 , const struct V_120 * V_121 )
{
struct V_122 * V_123 ;
enum { V_124 = 10 };
char V_125 [ V_124 ] ;
int V_46 = V_121 ? V_121 -> V_46 : 0 ;
int V_79 ;
if ( V_126 == NULL )
return 0 ;
if ( V_121 != NULL ) {
V_79 = snprintf ( V_125 , V_124 , L_17 , V_46 ) ;
if ( V_79 <= 0 || V_79 >= V_124 )
goto V_127;
V_123 = F_62 ( V_125 , 0600 , V_126 , V_6 ,
& V_128 ) ;
if ( V_123 == NULL )
goto V_129;
V_6 -> V_130 = V_123 ;
}
V_79 = snprintf ( V_125 , V_124 , L_18 , V_46 ) ;
if ( V_79 <= 0 || V_79 >= V_124 )
goto V_131;
V_123 = F_62 ( V_125 , 0600 , V_126 , V_6 , & V_132 ) ;
if ( V_123 == NULL )
goto V_133;
V_6 -> V_134 = V_123 ;
V_79 = snprintf ( V_125 , V_124 , L_19 , V_46 ) ;
if ( V_79 <= 0 || V_79 >= V_124 )
goto V_135;
V_123 = F_62 ( V_125 , 0600 , V_126 , V_6 , & V_136 ) ;
if ( V_123 == NULL )
goto V_137;
V_6 -> V_138 = V_123 ;
return 1 ;
V_137:
V_135:
F_63 ( V_6 -> V_134 ) ;
V_6 -> V_134 = NULL ;
V_133:
V_131:
if ( V_121 != NULL ) {
F_63 ( V_6 -> V_130 ) ;
V_6 -> V_130 = NULL ;
}
V_129:
V_127:
return 0 ;
}
void F_64 ( struct V_5 * V_6 )
{
F_63 ( V_6 -> V_134 ) ;
if ( V_6 -> V_130 != NULL )
F_63 ( V_6 -> V_130 ) ;
F_63 ( V_6 -> V_138 ) ;
}
static void V_96 ( void * V_139 )
{
memset ( V_139 , 0xe5 , sizeof( struct V_1 ) ) ;
}
int T_5 F_65 ( void )
{
struct V_122 * V_140 ;
V_140 = F_66 ( L_20 , V_141 ) ;
if ( F_38 ( V_140 ) ) {
return 0 ;
}
if ( V_140 == NULL ) {
F_58 (KERN_NOTICE TAG L_21 ) ;
return - V_83 ;
}
V_126 = V_140 ;
return 0 ;
}
void F_67 ( void )
{
F_63 ( V_126 ) ;
}
