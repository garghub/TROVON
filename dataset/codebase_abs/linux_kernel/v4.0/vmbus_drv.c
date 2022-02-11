static int F_1 ( void )
{
if ( V_1 == NULL )
return - V_2 ;
return 0 ;
}
static void F_2 ( struct V_3 * V_4 , char * V_5 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 += 2 )
sprintf ( & V_5 [ V_6 ] , L_1 , V_4 -> V_8 . V_9 [ V_6 / 2 ] ) ;
}
static T_1 F_3 ( struct V_10 * V_11 )
{
return ( T_1 ) V_11 -> V_12 . V_13 / 32 ;
}
static T_1 F_4 ( struct V_10 * V_11 )
{
return ( T_1 ) V_11 -> V_12 . V_13 % 32 ;
}
static T_2 F_5 ( struct V_10 * V_11 ,
struct V_14 * V_15 )
{
T_1 V_16 = F_3 ( V_11 ) ;
return V_15 -> V_17 [ V_16 ] . V_18 ;
}
static T_2 F_6 ( struct V_10 * V_11 ,
struct V_14 * V_15 )
{
T_1 V_16 = F_3 ( V_11 ) ;
T_1 V_19 = F_4 ( V_11 ) ;
return V_15 -> V_20 [ V_16 ] [ V_19 ] ;
}
static T_2 F_7 ( struct V_10 * V_11 ,
struct V_14 * V_15 )
{
T_1 V_16 = F_3 ( V_11 ) ;
T_1 V_19 = F_4 ( V_11 ) ;
return V_15 -> V_21 [ V_16 ] [ V_19 ] . V_22 . V_23 . V_24 ;
}
static T_3 F_8 ( struct V_25 * V_26 , struct V_27 * V_28 ,
char * V_29 )
{
struct V_3 * V_4 = F_9 ( V_26 ) ;
if ( ! V_4 -> V_11 )
return - V_2 ;
return sprintf ( V_29 , L_2 , V_4 -> V_11 -> V_12 . V_30 ) ;
}
static T_3 F_10 ( struct V_25 * V_26 , struct V_27 * V_28 ,
char * V_29 )
{
struct V_3 * V_4 = F_9 ( V_26 ) ;
if ( ! V_4 -> V_11 )
return - V_2 ;
return sprintf ( V_29 , L_2 , V_4 -> V_11 -> V_31 ) ;
}
static T_3 F_11 ( struct V_25 * V_26 ,
struct V_27 * V_28 , char * V_29 )
{
struct V_3 * V_4 = F_9 ( V_26 ) ;
if ( ! V_4 -> V_11 )
return - V_2 ;
return sprintf ( V_29 , L_2 , V_4 -> V_11 -> V_12 . V_13 ) ;
}
static T_3 F_12 ( struct V_25 * V_26 ,
struct V_27 * V_28 , char * V_29 )
{
struct V_3 * V_4 = F_9 ( V_26 ) ;
if ( ! V_4 -> V_11 )
return - V_2 ;
return sprintf ( V_29 , L_3 ,
V_4 -> V_11 -> V_12 . V_32 . V_33 . V_9 ) ;
}
static T_3 F_13 ( struct V_25 * V_26 ,
struct V_27 * V_28 , char * V_29 )
{
struct V_3 * V_4 = F_9 ( V_26 ) ;
if ( ! V_4 -> V_11 )
return - V_2 ;
return sprintf ( V_29 , L_3 ,
V_4 -> V_11 -> V_12 . V_32 . V_34 . V_9 ) ;
}
static T_3 F_14 ( struct V_25 * V_26 ,
struct V_27 * V_28 , char * V_29 )
{
struct V_3 * V_4 = F_9 ( V_26 ) ;
char V_5 [ V_7 + 1 ] ;
F_2 ( V_4 , V_5 ) ;
return sprintf ( V_29 , L_4 , V_5 ) ;
}
static T_3 F_15 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
char * V_29 )
{
struct V_3 * V_4 = F_9 ( V_26 ) ;
if ( ! V_4 -> V_11 )
return - V_2 ;
return sprintf ( V_29 , L_2 ,
F_5 ( V_4 -> V_11 ,
V_35 . V_36 [ 1 ] ) ) ;
}
static T_3 F_16 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
char * V_29 )
{
struct V_3 * V_4 = F_9 ( V_26 ) ;
if ( ! V_4 -> V_11 )
return - V_2 ;
return sprintf ( V_29 , L_2 ,
F_5 ( V_4 -> V_11 ,
V_35 . V_36 [ 1 ] ) ) ;
}
static T_3 F_17 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
char * V_29 )
{
struct V_3 * V_4 = F_9 ( V_26 ) ;
if ( ! V_4 -> V_11 )
return - V_2 ;
return sprintf ( V_29 , L_2 ,
F_6 ( V_4 -> V_11 ,
V_35 . V_36 [ 0 ] ) ) ;
}
static T_3 F_18 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
char * V_29 )
{
struct V_3 * V_4 = F_9 ( V_26 ) ;
if ( ! V_4 -> V_11 )
return - V_2 ;
return sprintf ( V_29 , L_2 ,
F_6 ( V_4 -> V_11 ,
V_35 . V_36 [ 1 ] ) ) ;
}
static T_3 F_19 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
char * V_29 )
{
struct V_3 * V_4 = F_9 ( V_26 ) ;
if ( ! V_4 -> V_11 )
return - V_2 ;
return sprintf ( V_29 , L_2 ,
F_7 ( V_4 -> V_11 ,
V_35 . V_36 [ 0 ] ) ) ;
}
static T_3 F_20 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
char * V_29 )
{
struct V_3 * V_4 = F_9 ( V_26 ) ;
if ( ! V_4 -> V_11 )
return - V_2 ;
return sprintf ( V_29 , L_2 ,
F_7 ( V_4 -> V_11 ,
V_35 . V_36 [ 1 ] ) ) ;
}
static T_3 F_21 ( struct V_25 * V_26 ,
struct V_27 * V_28 , char * V_29 )
{
struct V_3 * V_4 = F_9 ( V_26 ) ;
struct V_37 V_38 ;
if ( ! V_4 -> V_11 )
return - V_2 ;
F_22 ( & V_4 -> V_11 -> V_38 , & V_38 ) ;
return sprintf ( V_29 , L_2 , V_38 . V_39 ) ;
}
static T_3 F_23 ( struct V_25 * V_26 ,
struct V_27 * V_28 , char * V_29 )
{
struct V_3 * V_4 = F_9 ( V_26 ) ;
struct V_37 V_38 ;
if ( ! V_4 -> V_11 )
return - V_2 ;
F_22 ( & V_4 -> V_11 -> V_38 , & V_38 ) ;
return sprintf ( V_29 , L_2 , V_38 . V_40 ) ;
}
static T_3 F_24 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
char * V_29 )
{
struct V_3 * V_4 = F_9 ( V_26 ) ;
struct V_37 V_38 ;
if ( ! V_4 -> V_11 )
return - V_2 ;
F_22 ( & V_4 -> V_11 -> V_38 , & V_38 ) ;
return sprintf ( V_29 , L_2 , V_38 . V_41 ) ;
}
static T_3 F_25 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
char * V_29 )
{
struct V_3 * V_4 = F_9 ( V_26 ) ;
struct V_37 V_38 ;
if ( ! V_4 -> V_11 )
return - V_2 ;
F_22 ( & V_4 -> V_11 -> V_38 , & V_38 ) ;
return sprintf ( V_29 , L_2 , V_38 . V_42 ) ;
}
static T_3 F_26 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
char * V_29 )
{
struct V_3 * V_4 = F_9 ( V_26 ) ;
struct V_37 V_38 ;
if ( ! V_4 -> V_11 )
return - V_2 ;
F_22 ( & V_4 -> V_11 -> V_38 , & V_38 ) ;
return sprintf ( V_29 , L_2 , V_38 . V_43 ) ;
}
static T_3 F_27 ( struct V_25 * V_26 ,
struct V_27 * V_28 , char * V_29 )
{
struct V_3 * V_4 = F_9 ( V_26 ) ;
struct V_37 V_44 ;
if ( ! V_4 -> V_11 )
return - V_2 ;
F_22 ( & V_4 -> V_11 -> V_44 , & V_44 ) ;
return sprintf ( V_29 , L_2 , V_44 . V_39 ) ;
}
static T_3 F_28 ( struct V_25 * V_26 ,
struct V_27 * V_28 , char * V_29 )
{
struct V_3 * V_4 = F_9 ( V_26 ) ;
struct V_37 V_44 ;
if ( ! V_4 -> V_11 )
return - V_2 ;
F_22 ( & V_4 -> V_11 -> V_44 , & V_44 ) ;
return sprintf ( V_29 , L_2 , V_44 . V_40 ) ;
}
static T_3 F_29 ( struct V_25 * V_26 ,
struct V_27 * V_28 , char * V_29 )
{
struct V_3 * V_4 = F_9 ( V_26 ) ;
struct V_37 V_44 ;
if ( ! V_4 -> V_11 )
return - V_2 ;
F_22 ( & V_4 -> V_11 -> V_44 , & V_44 ) ;
return sprintf ( V_29 , L_2 , V_44 . V_41 ) ;
}
static T_3 F_30 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
char * V_29 )
{
struct V_3 * V_4 = F_9 ( V_26 ) ;
struct V_37 V_44 ;
if ( ! V_4 -> V_11 )
return - V_2 ;
F_22 ( & V_4 -> V_11 -> V_44 , & V_44 ) ;
return sprintf ( V_29 , L_2 , V_44 . V_42 ) ;
}
static T_3 F_31 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
char * V_29 )
{
struct V_3 * V_4 = F_9 ( V_26 ) ;
struct V_37 V_44 ;
if ( ! V_4 -> V_11 )
return - V_2 ;
F_22 ( & V_4 -> V_11 -> V_44 , & V_44 ) ;
return sprintf ( V_29 , L_2 , V_44 . V_43 ) ;
}
static int F_32 ( struct V_25 * V_25 , struct V_45 * V_46 )
{
struct V_3 * V_26 = F_9 ( V_25 ) ;
int V_47 ;
char V_5 [ V_7 + 1 ] ;
F_2 ( V_26 , V_5 ) ;
V_47 = F_33 ( V_46 , L_5 , V_5 ) ;
return V_47 ;
}
static inline bool F_34 ( const T_4 * V_48 )
{
if ( memcmp ( V_48 , & V_49 , sizeof( V_50 ) ) )
return false ;
return true ;
}
static const struct V_51 * F_35 (
const struct V_51 * V_24 ,
const T_4 * V_48 )
{
for (; ! F_34 ( V_24 -> V_48 ) ; V_24 ++ )
if ( ! memcmp ( & V_24 -> V_48 , V_48 , sizeof( V_50 ) ) )
return V_24 ;
return NULL ;
}
static int F_36 ( struct V_25 * V_25 , struct V_52 * V_53 )
{
struct V_54 * V_55 = F_37 ( V_53 ) ;
struct V_3 * V_4 = F_9 ( V_25 ) ;
if ( F_35 ( V_55 -> V_56 , V_4 -> V_8 . V_9 ) )
return 1 ;
return 0 ;
}
static int F_38 ( struct V_25 * V_57 )
{
int V_47 = 0 ;
struct V_54 * V_55 =
F_37 ( V_57 -> V_53 ) ;
struct V_3 * V_26 = F_9 ( V_57 ) ;
const struct V_51 * V_58 ;
V_58 = F_35 ( V_55 -> V_56 , V_26 -> V_8 . V_9 ) ;
if ( V_55 -> V_59 ) {
V_47 = V_55 -> V_59 ( V_26 , V_58 ) ;
if ( V_47 != 0 )
F_39 ( L_6 ,
F_40 ( V_57 ) , V_47 ) ;
} else {
F_39 ( L_7 ,
F_40 ( V_57 ) ) ;
V_47 = - V_2 ;
}
return V_47 ;
}
static int F_41 ( struct V_25 * V_57 )
{
struct V_54 * V_55 = F_37 ( V_57 -> V_53 ) ;
struct V_3 * V_26 = F_9 ( V_57 ) ;
if ( V_55 -> remove )
V_55 -> remove ( V_26 ) ;
else
F_39 ( L_8 ,
F_40 ( V_57 ) ) ;
return 0 ;
}
static void F_42 ( struct V_25 * V_57 )
{
struct V_54 * V_55 ;
struct V_3 * V_26 = F_9 ( V_57 ) ;
if ( ! V_57 -> V_53 )
return;
V_55 = F_37 ( V_57 -> V_53 ) ;
if ( V_55 -> V_60 )
V_55 -> V_60 ( V_26 ) ;
return;
}
static void F_43 ( struct V_25 * V_25 )
{
struct V_3 * V_4 = F_9 ( V_25 ) ;
F_44 ( V_4 ) ;
}
static void F_45 ( struct V_61 * V_62 )
{
struct V_63 * V_64 ;
V_64 = F_46 ( V_62 , struct V_63 ,
V_62 ) ;
F_47 ( & V_64 -> V_65 ) ;
F_44 ( V_64 ) ;
}
static void F_48 ( struct V_66 * V_65 , int V_67 )
{
struct V_68 * V_26 = V_69 . V_70 [ V_67 ] ;
if ( V_26 -> V_71 )
V_26 -> V_71 ( V_26 ) ;
V_65 -> V_72 . V_73 = V_74 ;
F_49 () ;
if ( V_65 -> V_72 . V_75 . V_76 ) {
F_50 ( V_77 , 0 ) ;
}
}
static void F_51 ( unsigned long V_78 )
{
int V_67 = F_52 () ;
void * V_79 = V_69 . V_80 [ V_67 ] ;
struct V_66 * V_65 = (struct V_66 * ) V_79 +
V_81 ;
struct V_63 * V_64 ;
while ( 1 ) {
if ( V_65 -> V_72 . V_73 == V_74 ) {
break;
} else {
V_64 = F_53 ( sizeof( * V_64 ) , V_82 ) ;
if ( V_64 == NULL )
continue;
F_54 ( & V_64 -> V_62 , F_45 ) ;
memcpy ( & V_64 -> V_65 , V_65 , sizeof( * V_65 ) ) ;
F_55 ( V_35 . V_83 , & V_64 -> V_62 ) ;
}
V_65 -> V_72 . V_73 = V_74 ;
F_49 () ;
if ( V_65 -> V_72 . V_75 . V_76 ) {
F_50 ( V_77 , 0 ) ;
}
}
}
static void F_56 ( void )
{
int V_67 = F_52 () ;
void * V_79 ;
struct V_66 * V_65 ;
union V_84 * V_85 ;
bool V_86 = false ;
V_79 = V_69 . V_87 [ V_67 ] ;
if ( V_79 == NULL )
return;
V_85 = (union V_84 * ) V_79 +
V_81 ;
if ( ( V_88 == V_89 ) ||
( V_88 == V_90 ) ) {
if ( F_57 ( 0 ,
( unsigned long * ) & V_85 -> V_91 [ 0 ] ) ) {
V_86 = true ;
}
} else {
V_86 = true ;
}
if ( V_86 )
F_58 ( V_69 . V_92 [ V_67 ] ) ;
V_79 = V_69 . V_80 [ V_67 ] ;
V_65 = (struct V_66 * ) V_79 + V_81 ;
if ( V_65 -> V_72 . V_73 != V_74 ) {
if ( V_65 -> V_72 . V_73 == V_93 )
F_48 ( V_65 , V_67 ) ;
else
F_58 ( & V_94 ) ;
}
}
static int F_59 ( int V_95 )
{
int V_47 ;
V_47 = F_60 () ;
if ( V_47 != 0 ) {
F_39 ( L_9 , V_47 ) ;
return V_47 ;
}
F_61 ( & V_94 , F_51 , 0 ) ;
V_47 = F_62 ( & V_96 ) ;
if ( V_47 )
goto V_97;
F_63 ( F_56 ) ;
V_47 = F_64 () ;
if ( V_47 )
goto V_98;
F_65 ( V_99 , NULL , 1 ) ;
V_47 = F_66 () ;
if ( V_47 )
goto V_98;
F_67 () ;
return 0 ;
V_98:
F_68 () ;
F_69 () ;
F_70 ( & V_96 ) ;
V_97:
F_71 () ;
return V_47 ;
}
int F_72 ( struct V_54 * V_54 , struct V_100 * V_101 , const char * V_102 )
{
int V_47 ;
F_73 ( L_10 , V_54 -> V_103 ) ;
V_47 = F_1 () ;
if ( V_47 < 0 )
return V_47 ;
V_54 -> V_53 . V_103 = V_54 -> V_103 ;
V_54 -> V_53 . V_101 = V_101 ;
V_54 -> V_53 . V_102 = V_102 ;
V_54 -> V_53 . V_104 = & V_96 ;
V_47 = F_74 ( & V_54 -> V_53 ) ;
return V_47 ;
}
void F_75 ( struct V_54 * V_54 )
{
F_73 ( L_11 , V_54 -> V_103 ) ;
if ( ! F_1 () )
F_76 ( & V_54 -> V_53 ) ;
}
struct V_3 * F_77 ( const V_50 * type ,
const V_50 * V_105 ,
struct V_10 * V_11 )
{
struct V_3 * V_106 ;
V_106 = F_78 ( sizeof( struct V_3 ) , V_107 ) ;
if ( ! V_106 ) {
F_39 ( L_12 ) ;
return NULL ;
}
V_106 -> V_11 = V_11 ;
memcpy ( & V_106 -> V_8 , type , sizeof( V_50 ) ) ;
memcpy ( & V_106 -> V_108 , V_105 ,
sizeof( V_50 ) ) ;
return V_106 ;
}
int F_79 ( struct V_3 * V_106 )
{
int V_47 = 0 ;
static T_5 V_109 = F_80 ( 0 ) ;
F_81 ( & V_106 -> V_25 , L_13 ,
F_82 ( & V_109 ) ) ;
V_106 -> V_25 . V_104 = & V_96 ;
V_106 -> V_25 . V_110 = & V_1 -> V_26 ;
V_106 -> V_25 . V_111 = F_43 ;
V_47 = F_83 ( & V_106 -> V_25 ) ;
if ( V_47 )
F_39 ( L_14 ) ;
else
F_84 ( L_15 ,
F_40 ( & V_106 -> V_25 ) ) ;
return V_47 ;
}
void F_85 ( struct V_3 * V_112 )
{
F_84 ( L_16 ,
F_40 ( & V_112 -> V_25 ) ) ;
F_86 ( & V_112 -> V_25 ) ;
}
static T_6 F_87 ( struct V_113 * V_114 , void * V_64 )
{
switch ( V_114 -> type ) {
case V_115 :
V_95 = V_114 -> V_78 . V_95 . V_116 [ 0 ] ;
break;
case V_117 :
V_118 . V_119 = V_114 -> V_78 . V_120 . V_121 . V_122 ;
V_118 . V_123 = V_114 -> V_78 . V_120 . V_121 . V_124 ;
break;
}
return V_125 ;
}
static int F_88 ( struct V_126 * V_25 )
{
T_6 V_127 ;
int V_128 = - V_2 ;
V_1 = V_25 ;
V_127 = F_89 ( V_25 -> V_129 , V_130 ,
F_87 , NULL ) ;
if ( F_90 ( V_127 ) )
goto V_131;
if ( V_25 -> V_110 ) {
V_127 = F_89 ( V_25 -> V_110 -> V_129 ,
V_130 ,
F_87 , NULL ) ;
if ( F_90 ( V_127 ) )
goto V_131;
if ( V_118 . V_119 && V_118 . V_123 )
F_91 ( & V_132 , & V_118 ) ;
}
V_128 = 0 ;
V_131:
F_92 ( & V_133 ) ;
return V_128 ;
}
static int T_7 F_93 ( void )
{
int V_47 , V_134 ;
if ( V_135 != & V_136 )
return - V_2 ;
F_94 ( & V_133 ) ;
V_47 = F_95 ( & V_137 ) ;
if ( V_47 )
return V_47 ;
V_134 = F_96 ( & V_133 , 5 * V_138 ) ;
if ( V_134 == 0 ) {
V_47 = - V_139 ;
goto V_140;
}
if ( V_95 <= 0 ) {
V_47 = - V_2 ;
goto V_140;
}
V_47 = F_59 ( V_95 ) ;
if ( V_47 )
goto V_140;
return 0 ;
V_140:
F_97 ( & V_137 ) ;
V_1 = NULL ;
return V_47 ;
}
static void T_8 F_98 ( void )
{
F_69 () ;
F_99 () ;
F_70 ( & V_96 ) ;
F_71 () ;
F_97 ( & V_137 ) ;
}
