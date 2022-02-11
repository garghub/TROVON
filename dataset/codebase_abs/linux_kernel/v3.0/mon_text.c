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
V_24 = V_24 * 1000000 + V_23 . V_26 ;
return V_24 ;
}
static void F_9 ( struct V_27 * V_28 , struct V_3 * V_3 ,
char V_4 , int V_29 )
{
struct V_1 * V_2 ;
unsigned int V_24 ;
struct V_30 * V_31 ;
struct V_32 * V_33 ;
int V_34 , V_35 ;
V_24 = F_7 () ;
if ( V_28 -> V_36 >= V_37 ||
( V_2 = F_10 ( V_28 -> V_38 , V_39 ) ) == NULL ) {
V_28 -> V_40 . V_41 -> V_42 ++ ;
return;
}
V_2 -> type = V_4 ;
V_2 -> V_43 = ( unsigned long ) V_3 ;
V_2 -> V_44 = V_3 -> V_45 -> V_46 -> V_44 ;
V_2 -> V_47 = V_3 -> V_45 -> V_47 ;
V_2 -> V_48 = F_11 ( & V_3 -> V_2 -> V_49 ) ;
V_2 -> V_7 = F_12 ( & V_3 -> V_2 -> V_49 ) ;
V_2 -> V_15 = F_13 ( V_3 ) ;
V_2 -> V_50 = V_24 ;
V_2 -> V_20 = ( V_4 == 'S' ) ?
V_3 -> V_51 : V_3 -> V_52 ;
V_2 -> V_29 = V_29 ;
if ( V_2 -> V_7 == V_53 ) {
V_2 -> V_54 = V_3 -> V_54 ;
} else if ( V_2 -> V_7 == V_55 ) {
V_2 -> V_54 = V_3 -> V_54 ;
V_2 -> V_56 = V_3 -> V_56 ;
V_2 -> V_57 = V_3 -> V_57 ;
}
V_2 -> V_58 = V_3 -> V_59 ;
if ( V_2 -> V_7 == V_55 &&
V_3 -> V_59 > 0 ) {
if ( ( V_35 = V_3 -> V_59 ) > V_60 )
V_35 = V_60 ;
V_31 = V_3 -> V_61 ;
V_33 = V_2 -> V_62 ;
for ( V_34 = 0 ; V_34 < V_35 ; V_34 ++ ) {
V_33 -> V_29 = V_31 -> V_29 ;
V_33 -> V_63 = V_31 -> V_63 ;
V_33 -> V_20 = ( V_4 == 'S' ) ?
V_31 -> V_20 : V_31 -> V_52 ;
V_31 ++ ;
V_33 ++ ;
}
if ( V_4 == 'C' )
V_2 -> V_20 = V_3 -> V_51 ;
}
V_2 -> V_64 = F_1 ( V_2 , V_3 , V_4 , V_28 -> V_40 . V_41 ) ;
V_2 -> V_65 = F_2 ( V_2 , V_3 , V_2 -> V_20 , V_4 ,
V_28 -> V_40 . V_41 ) ;
V_28 -> V_36 ++ ;
F_14 ( & V_2 -> V_66 , & V_28 -> V_67 ) ;
F_15 ( & V_28 -> V_68 ) ;
}
static void F_16 ( void * V_21 , struct V_3 * V_3 )
{
struct V_27 * V_28 = V_21 ;
F_9 ( V_28 , V_3 , 'S' , - V_69 ) ;
}
static void F_17 ( void * V_21 , struct V_3 * V_3 , int V_29 )
{
struct V_27 * V_28 = V_21 ;
F_9 ( V_28 , V_3 , 'C' , V_29 ) ;
}
static void F_18 ( void * V_21 , struct V_3 * V_3 , int error )
{
struct V_27 * V_28 = V_21 ;
struct V_1 * V_2 ;
if ( V_28 -> V_36 >= V_37 ||
( V_2 = F_10 ( V_28 -> V_38 , V_39 ) ) == NULL ) {
V_28 -> V_40 . V_41 -> V_42 ++ ;
return;
}
V_2 -> type = 'E' ;
V_2 -> V_43 = ( unsigned long ) V_3 ;
V_2 -> V_44 = V_3 -> V_45 -> V_46 -> V_44 ;
V_2 -> V_47 = V_3 -> V_45 -> V_47 ;
V_2 -> V_48 = F_11 ( & V_3 -> V_2 -> V_49 ) ;
V_2 -> V_7 = F_12 ( & V_3 -> V_2 -> V_49 ) ;
V_2 -> V_15 = F_13 ( V_3 ) ;
V_2 -> V_50 = F_7 () ;
V_2 -> V_20 = 0 ;
V_2 -> V_29 = error ;
V_2 -> V_64 = '-' ;
V_2 -> V_65 = 'E' ;
V_28 -> V_36 ++ ;
F_14 ( & V_2 -> V_66 , & V_28 -> V_67 ) ;
F_15 ( & V_28 -> V_68 ) ;
}
static struct V_1 * F_19 ( struct V_27 * V_28 ,
struct V_5 * V_6 )
{
struct V_70 * V_71 ;
unsigned long V_72 ;
F_20 ( & V_6 -> V_73 , V_72 ) ;
if ( F_21 ( & V_28 -> V_67 ) ) {
F_22 ( & V_6 -> V_73 , V_72 ) ;
return NULL ;
}
V_71 = V_28 -> V_67 . V_74 ;
F_23 ( V_71 ) ;
-- V_28 -> V_36 ;
F_22 ( & V_6 -> V_73 , V_72 ) ;
return F_24 ( V_71 , struct V_1 , V_66 ) ;
}
static int F_25 ( struct V_75 * V_75 , struct V_76 * V_76 )
{
struct V_5 * V_6 ;
struct V_27 * V_28 ;
int V_77 ;
F_26 ( & V_78 ) ;
V_6 = V_75 -> V_79 ;
V_28 = F_27 ( sizeof( struct V_27 ) , V_80 ) ;
if ( V_28 == NULL ) {
V_77 = - V_81 ;
goto V_82;
}
F_28 ( & V_28 -> V_67 ) ;
F_29 ( & V_28 -> V_68 ) ;
F_30 ( & V_28 -> V_83 ) ;
V_28 -> V_84 = V_85 ;
V_28 -> V_86 = F_31 ( V_28 -> V_84 , V_80 ) ;
if ( V_28 -> V_86 == NULL ) {
V_77 = - V_81 ;
goto V_87;
}
V_28 -> V_40 . V_41 = V_6 ;
V_28 -> V_40 . V_88 = V_28 ;
V_28 -> V_40 . V_89 = F_16 ;
V_28 -> V_40 . V_90 = F_18 ;
V_28 -> V_40 . V_91 = F_17 ;
snprintf ( V_28 -> V_92 , V_93 , L_1 , V_28 ) ;
V_28 -> V_38 = F_32 ( V_28 -> V_92 ,
sizeof( struct V_1 ) , sizeof( long ) , 0 ,
V_94 ) ;
if ( V_28 -> V_38 == NULL ) {
V_77 = - V_81 ;
goto V_95;
}
F_33 ( V_6 , & V_28 -> V_40 ) ;
V_76 -> V_96 = V_28 ;
F_34 ( & V_78 ) ;
return 0 ;
V_95:
F_35 ( V_28 -> V_86 ) ;
V_87:
F_35 ( V_28 ) ;
V_82:
F_34 ( & V_78 ) ;
return V_77 ;
}
static T_1 F_36 ( struct V_76 * V_76 , char T_2 * V_97 ,
T_3 V_98 , T_4 * V_99 )
{
struct V_27 * V_28 = V_76 -> V_96 ;
struct V_1 * V_2 ;
struct V_100 V_101 ;
if ( F_37 ( V_2 = F_38 ( V_28 , V_76 ) ) )
return F_39 ( V_2 ) ;
F_26 ( & V_28 -> V_83 ) ;
V_101 . V_102 = 0 ;
V_101 . V_103 = V_28 -> V_86 ;
V_101 . V_104 = V_28 -> V_84 ;
F_40 ( V_28 , & V_101 , V_2 ) ;
F_41 ( V_28 , & V_101 , V_2 ) ;
V_101 . V_102 += snprintf ( V_101 . V_103 + V_101 . V_102 , V_101 . V_104 - V_101 . V_102 ,
L_2 , V_2 -> V_20 ) ;
F_42 ( V_28 , & V_101 , V_2 ) ;
if ( F_43 ( V_97 , V_28 -> V_86 , V_101 . V_102 ) )
V_101 . V_102 = - V_105 ;
F_34 ( & V_28 -> V_83 ) ;
F_44 ( V_28 -> V_38 , V_2 ) ;
return V_101 . V_102 ;
}
static T_1 F_45 ( struct V_76 * V_76 , char T_2 * V_97 ,
T_3 V_98 , T_4 * V_99 )
{
struct V_27 * V_28 = V_76 -> V_96 ;
struct V_1 * V_2 ;
struct V_100 V_101 ;
if ( F_37 ( V_2 = F_38 ( V_28 , V_76 ) ) )
return F_39 ( V_2 ) ;
F_26 ( & V_28 -> V_83 ) ;
V_101 . V_102 = 0 ;
V_101 . V_103 = V_28 -> V_86 ;
V_101 . V_104 = V_28 -> V_84 ;
F_46 ( V_28 , & V_101 , V_2 ) ;
if ( V_2 -> type == 'E' ) {
F_41 ( V_28 , & V_101 , V_2 ) ;
} else if ( V_2 -> V_7 == V_55 ) {
F_47 ( V_28 , & V_101 , V_2 ) ;
F_48 ( V_28 , & V_101 , V_2 ) ;
} else if ( V_2 -> V_7 == V_53 ) {
F_49 ( V_28 , & V_101 , V_2 ) ;
} else {
F_41 ( V_28 , & V_101 , V_2 ) ;
}
V_101 . V_102 += snprintf ( V_101 . V_103 + V_101 . V_102 , V_101 . V_104 - V_101 . V_102 ,
L_2 , V_2 -> V_20 ) ;
F_42 ( V_28 , & V_101 , V_2 ) ;
if ( F_43 ( V_97 , V_28 -> V_86 , V_101 . V_102 ) )
V_101 . V_102 = - V_105 ;
F_34 ( & V_28 -> V_83 ) ;
F_44 ( V_28 -> V_38 , V_2 ) ;
return V_101 . V_102 ;
}
static struct V_1 * F_38 ( struct V_27 * V_28 ,
struct V_76 * V_76 )
{
struct V_5 * V_6 = V_28 -> V_40 . V_41 ;
F_50 ( V_106 , V_107 ) ;
struct V_1 * V_2 ;
F_51 ( & V_28 -> V_68 , & V_106 ) ;
F_52 ( V_108 ) ;
while ( ( V_2 = F_19 ( V_28 , V_6 ) ) == NULL ) {
if ( V_76 -> V_109 & V_110 ) {
F_52 ( V_111 ) ;
F_53 ( & V_28 -> V_68 , & V_106 ) ;
return F_54 ( - V_112 ) ;
}
F_55 () ;
if ( F_56 ( V_107 ) ) {
F_53 ( & V_28 -> V_68 , & V_106 ) ;
return F_54 ( - V_113 ) ;
}
F_52 ( V_108 ) ;
}
F_52 ( V_111 ) ;
F_53 ( & V_28 -> V_68 , & V_106 ) ;
return V_2 ;
}
static void F_40 ( struct V_27 * V_28 ,
struct V_100 * V_71 , const struct V_1 * V_2 )
{
char V_114 , V_115 ;
V_114 = ( V_2 -> V_15 ? 'i' : 'o' ) ;
switch ( V_2 -> V_7 ) {
case V_55 : V_115 = 'Z' ; break;
case V_53 : V_115 = 'I' ; break;
case V_8 : V_115 = 'C' ; break;
default: V_115 = 'B' ;
}
V_71 -> V_102 += snprintf ( V_71 -> V_103 + V_71 -> V_102 , V_71 -> V_104 - V_71 -> V_102 ,
L_3 ,
V_2 -> V_43 , V_2 -> V_50 , V_2 -> type ,
V_115 , V_114 , V_2 -> V_47 , V_2 -> V_48 ) ;
}
static void F_46 ( struct V_27 * V_28 ,
struct V_100 * V_71 , const struct V_1 * V_2 )
{
char V_114 , V_115 ;
V_114 = ( V_2 -> V_15 ? 'i' : 'o' ) ;
switch ( V_2 -> V_7 ) {
case V_55 : V_115 = 'Z' ; break;
case V_53 : V_115 = 'I' ; break;
case V_8 : V_115 = 'C' ; break;
default: V_115 = 'B' ;
}
V_71 -> V_102 += snprintf ( V_71 -> V_103 + V_71 -> V_102 , V_71 -> V_104 - V_71 -> V_102 ,
L_4 ,
V_2 -> V_43 , V_2 -> V_50 , V_2 -> type ,
V_115 , V_114 , V_2 -> V_44 , V_2 -> V_47 , V_2 -> V_48 ) ;
}
static void F_41 ( struct V_27 * V_28 ,
struct V_100 * V_71 , const struct V_1 * V_2 )
{
if ( V_2 -> V_64 == 0 ) {
V_71 -> V_102 += snprintf ( V_71 -> V_103 + V_71 -> V_102 , V_71 -> V_104 - V_71 -> V_102 ,
L_5 ,
V_2 -> V_10 [ 0 ] ,
V_2 -> V_10 [ 1 ] ,
( V_2 -> V_10 [ 3 ] << 8 ) | V_2 -> V_10 [ 2 ] ,
( V_2 -> V_10 [ 5 ] << 8 ) | V_2 -> V_10 [ 4 ] ,
( V_2 -> V_10 [ 7 ] << 8 ) | V_2 -> V_10 [ 6 ] ) ;
} else if ( V_2 -> V_64 != '-' ) {
V_71 -> V_102 += snprintf ( V_71 -> V_103 + V_71 -> V_102 , V_71 -> V_104 - V_71 -> V_102 ,
L_6 , V_2 -> V_64 ) ;
} else {
V_71 -> V_102 += snprintf ( V_71 -> V_103 + V_71 -> V_102 , V_71 -> V_104 - V_71 -> V_102 ,
L_2 , V_2 -> V_29 ) ;
}
}
static void F_49 ( struct V_27 * V_28 ,
struct V_100 * V_71 , const struct V_1 * V_2 )
{
V_71 -> V_102 += snprintf ( V_71 -> V_103 + V_71 -> V_102 , V_71 -> V_104 - V_71 -> V_102 ,
L_7 , V_2 -> V_29 , V_2 -> V_54 ) ;
}
static void F_47 ( struct V_27 * V_28 ,
struct V_100 * V_71 , const struct V_1 * V_2 )
{
if ( V_2 -> type == 'S' ) {
V_71 -> V_102 += snprintf ( V_71 -> V_103 + V_71 -> V_102 , V_71 -> V_104 - V_71 -> V_102 ,
L_8 , V_2 -> V_29 , V_2 -> V_54 , V_2 -> V_56 ) ;
} else {
V_71 -> V_102 += snprintf ( V_71 -> V_103 + V_71 -> V_102 , V_71 -> V_104 - V_71 -> V_102 ,
L_9 ,
V_2 -> V_29 , V_2 -> V_54 , V_2 -> V_56 , V_2 -> V_57 ) ;
}
}
static void F_48 ( struct V_27 * V_28 ,
struct V_100 * V_71 , const struct V_1 * V_2 )
{
int V_35 ;
int V_34 ;
const struct V_32 * V_33 ;
V_71 -> V_102 += snprintf ( V_71 -> V_103 + V_71 -> V_102 , V_71 -> V_104 - V_71 -> V_102 ,
L_2 , V_2 -> V_58 ) ;
V_35 = V_2 -> V_58 ;
if ( V_35 > V_60 )
V_35 = V_60 ;
if ( V_35 < 0 )
V_35 = 0 ;
V_33 = V_2 -> V_62 ;
for ( V_34 = 0 ; V_34 < V_35 ; V_34 ++ ) {
V_71 -> V_102 += snprintf ( V_71 -> V_103 + V_71 -> V_102 , V_71 -> V_104 - V_71 -> V_102 ,
L_10 , V_33 -> V_29 , V_33 -> V_63 , V_33 -> V_20 ) ;
V_33 ++ ;
}
}
static void F_42 ( struct V_27 * V_28 ,
struct V_100 * V_71 , const struct V_1 * V_2 )
{
int V_116 , V_34 ;
if ( ( V_116 = V_2 -> V_20 ) > 0 ) {
if ( V_2 -> V_65 == 0 ) {
V_71 -> V_102 += snprintf ( V_71 -> V_103 + V_71 -> V_102 , V_71 -> V_104 - V_71 -> V_102 ,
L_11 ) ;
if ( V_116 >= V_14 )
V_116 = V_14 ;
for ( V_34 = 0 ; V_34 < V_116 ; V_34 ++ ) {
if ( V_34 % 4 == 0 ) {
V_71 -> V_102 += snprintf ( V_71 -> V_103 + V_71 -> V_102 ,
V_71 -> V_104 - V_71 -> V_102 ,
L_12 ) ;
}
V_71 -> V_102 += snprintf ( V_71 -> V_103 + V_71 -> V_102 ,
V_71 -> V_104 - V_71 -> V_102 ,
L_13 , V_2 -> V_21 [ V_34 ] ) ;
}
V_71 -> V_102 += snprintf ( V_71 -> V_103 + V_71 -> V_102 , V_71 -> V_104 - V_71 -> V_102 ,
L_14 ) ;
} else {
V_71 -> V_102 += snprintf ( V_71 -> V_103 + V_71 -> V_102 , V_71 -> V_104 - V_71 -> V_102 ,
L_15 , V_2 -> V_65 ) ;
}
} else {
V_71 -> V_102 += snprintf ( V_71 -> V_103 + V_71 -> V_102 , V_71 -> V_104 - V_71 -> V_102 , L_14 ) ;
}
}
static int F_57 ( struct V_75 * V_75 , struct V_76 * V_76 )
{
struct V_27 * V_28 = V_76 -> V_96 ;
struct V_5 * V_6 ;
struct V_70 * V_71 ;
struct V_1 * V_2 ;
F_26 ( & V_78 ) ;
V_6 = V_75 -> V_79 ;
if ( V_6 -> V_117 <= 0 ) {
F_58 (KERN_ERR TAG L_16 ) ;
F_34 ( & V_78 ) ;
return 0 ;
}
F_59 ( V_6 , & V_28 -> V_40 ) ;
while ( ! F_21 ( & V_28 -> V_67 ) ) {
V_71 = V_28 -> V_67 . V_74 ;
V_2 = F_24 ( V_71 , struct V_1 , V_66 ) ;
F_23 ( V_71 ) ;
-- V_28 -> V_36 ;
F_44 ( V_28 -> V_38 , V_2 ) ;
}
F_60 ( V_28 -> V_38 ) ;
F_35 ( V_28 -> V_86 ) ;
F_35 ( V_28 ) ;
F_34 ( & V_78 ) ;
return 0 ;
}
int F_61 ( struct V_5 * V_6 , const struct V_118 * V_119 )
{
struct V_120 * V_121 ;
enum { V_122 = 10 };
char V_123 [ V_122 ] ;
int V_44 = V_119 ? V_119 -> V_44 : 0 ;
int V_77 ;
if ( V_119 != NULL ) {
V_77 = snprintf ( V_123 , V_122 , L_17 , V_44 ) ;
if ( V_77 <= 0 || V_77 >= V_122 )
goto V_124;
V_121 = F_62 ( V_123 , 0600 , V_125 , V_6 ,
& V_126 ) ;
if ( V_121 == NULL )
goto V_127;
V_6 -> V_128 = V_121 ;
}
V_77 = snprintf ( V_123 , V_122 , L_18 , V_44 ) ;
if ( V_77 <= 0 || V_77 >= V_122 )
goto V_129;
V_121 = F_62 ( V_123 , 0600 , V_125 , V_6 , & V_130 ) ;
if ( V_121 == NULL )
goto V_131;
V_6 -> V_132 = V_121 ;
V_77 = snprintf ( V_123 , V_122 , L_19 , V_44 ) ;
if ( V_77 <= 0 || V_77 >= V_122 )
goto V_133;
V_121 = F_62 ( V_123 , 0600 , V_125 , V_6 , & V_134 ) ;
if ( V_121 == NULL )
goto V_135;
V_6 -> V_136 = V_121 ;
return 1 ;
V_135:
V_133:
F_63 ( V_6 -> V_132 ) ;
V_6 -> V_132 = NULL ;
V_131:
V_129:
if ( V_119 != NULL ) {
F_63 ( V_6 -> V_128 ) ;
V_6 -> V_128 = NULL ;
}
V_127:
V_124:
return 0 ;
}
void F_64 ( struct V_5 * V_6 )
{
F_63 ( V_6 -> V_132 ) ;
if ( V_6 -> V_128 != NULL )
F_63 ( V_6 -> V_128 ) ;
F_63 ( V_6 -> V_136 ) ;
}
static void V_94 ( void * V_137 )
{
memset ( V_137 , 0xe5 , sizeof( struct V_1 ) ) ;
}
int T_5 F_65 ( void )
{
struct V_120 * V_138 ;
V_138 = F_66 ( L_20 , V_139 ) ;
if ( F_37 ( V_138 ) ) {
F_58 (KERN_NOTICE TAG L_21 ) ;
return - V_140 ;
}
if ( V_138 == NULL ) {
F_58 (KERN_NOTICE TAG L_22 ) ;
return - V_140 ;
}
V_125 = V_138 ;
return 0 ;
}
void F_67 ( void )
{
F_63 ( V_125 ) ;
}
