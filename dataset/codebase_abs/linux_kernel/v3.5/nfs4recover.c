static int
F_1 ( const struct V_1 * * V_2 )
{
struct V_1 * V_3 ;
V_3 = F_2 () ;
if ( ! V_3 )
return - V_4 ;
V_3 -> V_5 = 0 ;
V_3 -> V_6 = 0 ;
* V_2 = F_3 ( V_3 ) ;
F_4 ( V_3 ) ;
return 0 ;
}
static void
F_5 ( const struct V_1 * V_7 )
{
F_6 ( V_7 ) ;
}
static void
F_7 ( char * V_8 , char * V_9 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < 16 ; V_10 ++ ) {
unsigned char V_11 = V_9 [ V_10 ] ;
* V_8 ++ = '0' + ( ( V_11 & 0xf0 ) >> 4 ) + ( V_11 >= 0xa0 ) * ( 'a' - '9' - 1 ) ;
* V_8 ++ = '0' + ( V_11 & 0x0f ) + ( ( V_11 & 0x0f ) >= 0x0a ) * ( 'a' - '9' - 1 ) ;
}
* V_8 = '\0' ;
}
T_1
F_8 ( char * V_12 , struct V_13 * V_14 )
{
struct V_13 V_15 ;
struct V_16 V_17 ;
struct V_18 V_19 ;
T_1 V_20 = V_21 ;
F_9 ( L_1 ,
V_14 -> V_22 , V_14 -> V_23 ) ;
V_17 . V_24 = V_25 ;
V_17 . V_26 = F_10 ( L_2 , 0 , V_27 ) ;
if ( F_11 ( V_17 . V_26 ) )
goto V_28;
V_15 . V_22 = F_12 ( V_17 . V_26 ) ;
V_15 . V_23 = F_13 ( V_15 . V_22 , V_29 ) ;
if ( V_15 . V_23 == NULL )
goto V_8;
F_14 ( & V_19 , V_14 -> V_23 , V_14 -> V_22 ) ;
if ( F_15 ( & V_17 , & V_19 , V_19 . V_30 , V_15 . V_23 ) )
goto V_8;
F_7 ( V_12 , V_15 . V_23 ) ;
V_20 = V_31 ;
V_8:
F_16 ( V_15 . V_23 ) ;
F_17 ( V_17 . V_26 ) ;
V_28:
return V_20 ;
}
static void
F_18 ( struct V_32 * V_33 )
{
const struct V_1 * V_34 ;
char * V_12 = V_33 -> V_35 ;
struct V_36 * V_37 , * V_36 ;
int V_20 ;
F_9 ( L_3 , V_12 ) ;
if ( F_19 ( V_38 , & V_33 -> V_39 ) )
return;
if ( ! V_40 )
return;
V_20 = F_1 ( & V_34 ) ;
if ( V_20 < 0 )
return;
V_37 = V_40 -> V_41 . V_36 ;
F_20 ( & V_37 -> V_42 -> V_43 ) ;
V_36 = F_21 ( V_12 , V_37 , V_44 - 1 ) ;
if ( F_11 ( V_36 ) ) {
V_20 = F_22 ( V_36 ) ;
goto V_45;
}
if ( V_36 -> V_42 )
goto V_46;
V_20 = F_23 ( V_40 ) ;
if ( V_20 )
goto V_46;
V_20 = F_24 ( V_37 -> V_42 , V_36 , V_47 ) ;
F_25 ( V_40 ) ;
V_46:
F_26 ( V_36 ) ;
V_45:
F_27 ( & V_37 -> V_42 -> V_43 ) ;
if ( V_20 == 0 )
F_28 ( V_40 , 0 ) ;
else
F_29 ( V_48 L_4
L_5
L_6 , V_20 ,
V_49 ) ;
F_5 ( V_34 ) ;
}
static int
F_30 ( void * V_50 , const char * V_51 , int V_52 ,
T_2 V_53 , T_3 V_54 , unsigned int V_55 )
{
struct V_56 * V_57 = V_50 ;
struct V_58 * V_59 ;
if ( V_52 != V_44 - 1 )
return 0 ;
V_59 = F_13 ( sizeof( struct V_58 ) , V_29 ) ;
if ( V_59 == NULL )
return - V_4 ;
memcpy ( V_59 -> V_51 , V_51 , V_44 - 1 ) ;
V_59 -> V_51 [ V_44 - 1 ] = '\0' ;
F_31 ( & V_59 -> V_60 , V_57 ) ;
return 0 ;
}
static int
F_32 ( T_4 * V_61 )
{
const struct V_1 * V_34 ;
struct V_36 * V_37 = V_40 -> V_41 . V_36 ;
F_33 ( V_57 ) ;
int V_20 ;
V_20 = F_1 ( & V_34 ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 = F_34 ( V_40 , 0 , V_62 ) ;
if ( V_20 < 0 ) {
F_5 ( V_34 ) ;
return V_20 ;
}
V_20 = F_35 ( V_40 , F_30 , & V_57 ) ;
F_36 ( & V_37 -> V_42 -> V_43 , V_63 ) ;
while ( ! F_37 ( & V_57 ) ) {
struct V_58 * V_59 ;
V_59 = F_38 ( V_57 . V_64 , struct V_58 , V_60 ) ;
if ( ! V_20 ) {
struct V_36 * V_36 ;
V_36 = F_21 ( V_59 -> V_51 , V_37 , V_44 - 1 ) ;
if ( F_11 ( V_36 ) ) {
V_20 = F_22 ( V_36 ) ;
break;
}
V_20 = V_61 ( V_37 , V_36 ) ;
F_26 ( V_36 ) ;
}
F_39 ( & V_59 -> V_60 ) ;
F_16 ( V_59 ) ;
}
F_27 ( & V_37 -> V_42 -> V_43 ) ;
F_5 ( V_34 ) ;
return V_20 ;
}
static int
F_40 ( char * V_51 , int V_52 )
{
struct V_36 * V_37 , * V_36 ;
int V_20 ;
F_9 ( L_7 , V_52 , V_51 ) ;
V_37 = V_40 -> V_41 . V_36 ;
F_36 ( & V_37 -> V_42 -> V_43 , V_63 ) ;
V_36 = F_21 ( V_51 , V_37 , V_52 ) ;
if ( F_11 ( V_36 ) ) {
V_20 = F_22 ( V_36 ) ;
goto V_45;
}
V_20 = - V_65 ;
if ( ! V_36 -> V_42 )
goto V_8;
V_20 = F_41 ( V_37 -> V_42 , V_36 ) ;
V_8:
F_26 ( V_36 ) ;
V_45:
F_27 ( & V_37 -> V_42 -> V_43 ) ;
return V_20 ;
}
static void
F_42 ( struct V_32 * V_33 )
{
const struct V_1 * V_34 ;
int V_20 ;
if ( ! V_40 || ! F_43 ( V_38 , & V_33 -> V_39 ) )
return;
V_20 = F_23 ( V_40 ) ;
if ( V_20 )
goto V_8;
F_44 ( V_38 , & V_33 -> V_39 ) ;
V_20 = F_1 ( & V_34 ) ;
if ( V_20 < 0 )
goto V_8;
V_20 = F_40 ( V_33 -> V_35 , V_44 - 1 ) ;
F_5 ( V_34 ) ;
if ( V_20 == 0 )
F_28 ( V_40 , 0 ) ;
F_25 ( V_40 ) ;
V_8:
if ( V_20 )
F_29 ( L_8
L_9 , V_44 , V_33 -> V_35 ) ;
}
static int
F_45 ( struct V_36 * V_66 , struct V_36 * V_67 )
{
int V_20 ;
if ( F_46 ( V_67 -> V_68 . V_51 , false ) )
return 0 ;
V_20 = F_41 ( V_66 -> V_42 , V_67 ) ;
if ( V_20 )
F_29 ( L_10 ,
V_67 -> V_68 . V_51 ) ;
return 0 ;
}
static void
F_47 ( struct V_69 * V_69 , T_5 V_70 )
{
int V_20 ;
if ( ! V_40 )
return;
V_20 = F_23 ( V_40 ) ;
if ( V_20 )
goto V_8;
V_20 = F_32 ( F_45 ) ;
if ( V_20 == 0 )
F_28 ( V_40 , 0 ) ;
F_25 ( V_40 ) ;
V_8:
if ( V_20 )
F_29 ( L_11
L_12 , V_40 -> V_41 . V_36 -> V_68 . V_51 ) ;
}
static int
F_48 ( struct V_36 * V_66 , struct V_36 * V_67 )
{
if ( V_67 -> V_68 . V_22 != V_44 - 1 ) {
F_29 ( L_13 ,
V_67 -> V_68 . V_51 ) ;
return 0 ;
}
F_49 ( V_67 -> V_68 . V_51 ) ;
return 0 ;
}
static int
F_50 ( void ) {
int V_20 ;
if ( ! V_40 )
return 0 ;
V_20 = F_32 ( F_48 ) ;
if ( V_20 )
F_29 ( L_14
L_12 , V_40 -> V_41 . V_36 -> V_68 . V_51 ) ;
return V_20 ;
}
static int
F_51 ( void )
{
const struct V_1 * V_34 ;
int V_20 ;
F_29 ( L_15 ,
V_49 ) ;
F_52 ( V_40 ) ;
V_20 = F_1 ( & V_34 ) ;
if ( V_20 < 0 ) {
F_29 ( L_16
L_17 ,
V_20 ) ;
return V_20 ;
}
V_40 = F_53 ( V_49 , V_71 | V_72 , 0 ) ;
if ( F_11 ( V_40 ) ) {
F_29 ( L_18 ,
V_49 ) ;
V_20 = F_22 ( V_40 ) ;
V_40 = NULL ;
}
F_5 ( V_34 ) ;
return V_20 ;
}
static int
F_54 ( struct V_69 * V_69 )
{
int V_20 ;
if ( V_69 != & V_73 ) {
F_55 ( 1 , V_48 L_19
L_20 ) ;
return - V_74 ;
}
F_56 () ;
V_20 = F_51 () ;
if ( ! V_20 )
V_20 = F_50 () ;
F_57 () ;
if ( V_20 )
F_29 ( V_48 L_21 ) ;
return V_20 ;
}
static void
F_58 ( void )
{
if ( ! V_40 )
return;
F_59 ( V_40 ) ;
V_40 = NULL ;
}
static void
F_60 ( struct V_69 * V_69 )
{
F_61 () ;
F_58 () ;
}
int
F_62 ( char * V_75 )
{
int V_20 ;
struct V_76 V_76 ;
V_20 = F_63 ( V_75 , V_77 , & V_76 ) ;
if ( V_20 )
return V_20 ;
V_20 = - V_78 ;
if ( F_64 ( V_76 . V_36 -> V_42 -> V_79 ) ) {
strcpy ( V_49 , V_75 ) ;
V_20 = 0 ;
}
F_65 ( & V_76 ) ;
return V_20 ;
}
char *
F_66 ( void )
{
return V_49 ;
}
static int
F_67 ( struct V_32 * V_33 )
{
if ( F_43 ( V_38 , & V_33 -> V_39 ) )
return 0 ;
if ( F_68 ( V_33 ) ) {
F_69 ( V_38 , & V_33 -> V_39 ) ;
return 0 ;
}
return - V_65 ;
}
static int
F_70 ( struct V_80 * V_81 , struct V_82 * V_83 )
{
int V_84 ;
struct V_85 V_86 ;
memset ( & V_86 , 0 , sizeof( V_86 ) ) ;
V_86 . V_23 = V_83 ;
V_86 . V_22 = sizeof( * V_83 ) ;
F_71 ( V_87 ) ;
V_84 = F_72 ( V_81 , & V_86 ) ;
if ( V_84 < 0 ) {
F_71 ( V_88 ) ;
goto V_8;
}
F_73 () ;
F_71 ( V_88 ) ;
if ( V_86 . V_89 < 0 )
V_84 = V_86 . V_89 ;
V_8:
return V_84 ;
}
static int
F_74 ( struct V_80 * V_81 , struct V_82 * V_83 )
{
int V_84 ;
do {
V_84 = F_70 ( V_81 , V_83 ) ;
} while ( V_84 == - V_90 );
return V_84 ;
}
static T_6
F_75 ( struct V_91 * V_92 , const char T_7 * V_93 , T_8 V_94 )
{
struct V_95 * V_96 , * V_97 ;
struct V_82 T_7 * V_83 = (struct V_82 T_7 * ) V_93 ;
T_9 V_98 ;
struct V_99 * V_100 = F_76 ( V_92 -> V_101 -> V_102 -> V_103 ,
V_104 ) ;
struct V_105 * V_106 = V_100 -> V_105 ;
if ( V_94 != sizeof( * V_83 ) ) {
F_9 ( L_22 , V_107 , V_94 ,
sizeof( * V_83 ) ) ;
return - V_74 ;
}
if ( F_77 ( & V_98 , & V_83 -> V_108 , sizeof( V_98 ) ) != 0 ) {
F_9 ( L_23 , V_107 ) ;
return - V_109 ;
}
V_97 = NULL ;
F_78 ( & V_106 -> V_110 ) ;
F_79 (tmp, &cn->cn_list, cu_list) {
if ( F_80 ( & V_96 -> V_111 . V_108 ) == V_98 ) {
V_97 = V_96 ;
F_81 ( & V_97 -> V_112 ) ;
break;
}
}
F_82 ( & V_106 -> V_110 ) ;
if ( ! V_97 ) {
F_9 ( L_24 , V_107 , V_98 ) ;
return - V_74 ;
}
if ( F_77 ( & V_97 -> V_111 , V_93 , V_94 ) != 0 )
return - V_109 ;
F_83 ( V_97 -> V_113 ) ;
return V_94 ;
}
static void
F_84 ( struct V_85 * V_86 )
{
struct V_82 * V_83 = V_86 -> V_23 ;
struct V_95 * V_97 = F_85 ( V_83 , struct V_95 ,
V_111 ) ;
if ( V_86 -> V_89 >= 0 )
return;
F_83 ( V_97 -> V_113 ) ;
}
static struct V_36 *
F_86 ( struct V_114 * V_115 , struct V_80 * V_81 )
{
struct V_36 * V_37 , * V_36 ;
V_37 = F_87 ( V_115 , V_116 ) ;
if ( V_37 == NULL )
return F_88 ( - V_65 ) ;
V_36 = F_89 ( V_37 , V_117 , NULL , V_81 ) ;
F_26 ( V_37 ) ;
return V_36 ;
}
static void
F_90 ( struct V_80 * V_81 )
{
if ( V_81 -> V_36 )
F_91 ( V_81 -> V_36 ) ;
}
static struct V_36 *
F_92 ( struct V_69 * V_69 , struct V_80 * V_81 )
{
struct V_114 * V_115 ;
struct V_36 * V_36 ;
V_115 = F_93 ( V_69 ) ;
if ( ! V_115 )
return NULL ;
V_36 = F_86 ( V_115 , V_81 ) ;
F_94 ( V_69 ) ;
return V_36 ;
}
static void
F_95 ( struct V_69 * V_69 , struct V_80 * V_81 )
{
struct V_114 * V_115 ;
V_115 = F_93 ( V_69 ) ;
if ( V_115 ) {
F_90 ( V_81 ) ;
F_94 ( V_69 ) ;
}
}
static int
F_96 ( struct V_69 * V_69 )
{
int V_84 ;
struct V_36 * V_36 ;
struct V_99 * V_100 = F_76 ( V_69 , V_104 ) ;
struct V_105 * V_106 ;
if ( V_100 -> V_105 )
return 0 ;
V_106 = F_97 ( sizeof( * V_106 ) , V_29 ) ;
if ( ! V_106 ) {
V_84 = - V_4 ;
goto V_118;
}
V_106 -> V_119 = F_98 ( & V_120 , V_121 ) ;
if ( F_11 ( V_106 -> V_119 ) ) {
V_84 = F_22 ( V_106 -> V_119 ) ;
goto V_118;
}
F_99 ( & V_106 -> V_110 ) ;
F_100 ( & V_106 -> V_122 ) ;
V_36 = F_92 ( V_69 , V_106 -> V_119 ) ;
if ( F_11 ( V_36 ) ) {
V_84 = F_22 ( V_36 ) ;
goto V_123;
}
V_106 -> V_119 -> V_36 = V_36 ;
V_100 -> V_105 = V_106 ;
return 0 ;
V_123:
F_101 ( V_106 -> V_119 ) ;
V_118:
F_16 ( V_106 ) ;
F_29 ( V_48 L_25 ,
V_84 ) ;
return V_84 ;
}
static void
F_102 ( struct V_69 * V_69 )
{
struct V_99 * V_100 = F_76 ( V_69 , V_104 ) ;
struct V_105 * V_106 = V_100 -> V_105 ;
F_95 ( V_69 , V_106 -> V_119 ) ;
F_101 ( V_106 -> V_119 ) ;
F_16 ( V_100 -> V_105 ) ;
V_100 -> V_105 = NULL ;
}
static struct V_95 *
F_103 ( struct V_105 * V_106 )
{
struct V_95 * V_3 , * V_96 ;
V_3 = F_97 ( sizeof( * V_3 ) , V_29 ) ;
if ( ! V_3 )
return V_3 ;
V_124:
F_78 ( & V_106 -> V_110 ) ;
F_79 (tmp, &cn->cn_list, cu_list) {
if ( V_96 -> V_111 . V_108 == V_106 -> V_125 ) {
V_106 -> V_125 ++ ;
F_82 ( & V_106 -> V_110 ) ;
goto V_124;
}
}
V_3 -> V_113 = V_126 ;
V_3 -> V_111 . V_127 = V_128 ;
F_104 ( V_106 -> V_125 ++ , & V_3 -> V_111 . V_108 ) ;
V_3 -> V_129 = V_106 ;
F_31 ( & V_3 -> V_112 , & V_106 -> V_122 ) ;
F_82 ( & V_106 -> V_110 ) ;
F_9 ( L_26 , V_107 , V_3 -> V_111 . V_108 ) ;
return V_3 ;
}
static void
F_105 ( struct V_95 * V_130 )
{
struct V_105 * V_106 = V_130 -> V_129 ;
F_78 ( & V_106 -> V_110 ) ;
F_39 ( & V_130 -> V_112 ) ;
F_82 ( & V_106 -> V_110 ) ;
F_16 ( V_130 ) ;
}
static void
F_106 ( struct V_32 * V_33 )
{
int V_84 ;
struct V_95 * V_97 ;
struct V_99 * V_100 = F_76 ( & V_73 , V_104 ) ;
struct V_105 * V_106 = V_100 -> V_105 ;
if ( F_43 ( V_38 , & V_33 -> V_39 ) )
return;
V_97 = F_103 ( V_106 ) ;
if ( ! V_97 ) {
V_84 = - V_4 ;
goto V_131;
}
V_97 -> V_111 . V_132 = V_133 ;
V_97 -> V_111 . V_134 . V_135 . V_136 = V_33 -> V_137 . V_22 ;
memcpy ( V_97 -> V_111 . V_134 . V_135 . V_138 , V_33 -> V_137 . V_23 ,
V_33 -> V_137 . V_22 ) ;
V_84 = F_74 ( V_106 -> V_119 , & V_97 -> V_111 ) ;
if ( ! V_84 ) {
V_84 = V_97 -> V_111 . V_139 ;
F_69 ( V_38 , & V_33 -> V_39 ) ;
}
F_105 ( V_97 ) ;
V_131:
if ( V_84 )
F_29 ( V_48 L_27
L_28 , V_84 ) ;
}
static void
F_107 ( struct V_32 * V_33 )
{
int V_84 ;
struct V_95 * V_97 ;
struct V_99 * V_100 = F_76 ( & V_73 , V_104 ) ;
struct V_105 * V_106 = V_100 -> V_105 ;
if ( ! F_43 ( V_38 , & V_33 -> V_39 ) )
return;
V_97 = F_103 ( V_106 ) ;
if ( ! V_97 ) {
V_84 = - V_4 ;
goto V_131;
}
V_97 -> V_111 . V_132 = V_140 ;
V_97 -> V_111 . V_134 . V_135 . V_136 = V_33 -> V_137 . V_22 ;
memcpy ( V_97 -> V_111 . V_134 . V_135 . V_138 , V_33 -> V_137 . V_23 ,
V_33 -> V_137 . V_22 ) ;
V_84 = F_74 ( V_106 -> V_119 , & V_97 -> V_111 ) ;
if ( ! V_84 ) {
V_84 = V_97 -> V_111 . V_139 ;
F_44 ( V_38 , & V_33 -> V_39 ) ;
}
F_105 ( V_97 ) ;
V_131:
if ( V_84 )
F_29 ( V_48 L_29
L_30 , V_84 ) ;
}
static int
F_108 ( struct V_32 * V_33 )
{
int V_84 ;
struct V_95 * V_97 ;
struct V_99 * V_100 = F_76 ( & V_73 , V_104 ) ;
struct V_105 * V_106 = V_100 -> V_105 ;
if ( F_43 ( V_38 , & V_33 -> V_39 ) )
return 0 ;
V_97 = F_103 ( V_106 ) ;
if ( ! V_97 ) {
F_29 ( V_48 L_31
L_32 , - V_4 ) ;
return - V_4 ;
}
V_97 -> V_111 . V_132 = V_141 ;
V_97 -> V_111 . V_134 . V_135 . V_136 = V_33 -> V_137 . V_22 ;
memcpy ( V_97 -> V_111 . V_134 . V_135 . V_138 , V_33 -> V_137 . V_23 ,
V_33 -> V_137 . V_22 ) ;
V_84 = F_74 ( V_106 -> V_119 , & V_97 -> V_111 ) ;
if ( ! V_84 ) {
V_84 = V_97 -> V_111 . V_139 ;
F_69 ( V_38 , & V_33 -> V_39 ) ;
}
F_105 ( V_97 ) ;
return V_84 ;
}
static void
F_109 ( struct V_69 * V_69 , T_5 V_70 )
{
int V_84 ;
struct V_95 * V_97 ;
struct V_99 * V_100 = F_76 ( V_69 , V_104 ) ;
struct V_105 * V_106 = V_100 -> V_105 ;
V_97 = F_103 ( V_106 ) ;
if ( ! V_97 ) {
V_84 = - V_4 ;
goto V_131;
}
V_97 -> V_111 . V_132 = V_142 ;
V_97 -> V_111 . V_134 . V_143 = ( V_144 ) V_70 ;
V_84 = F_74 ( V_106 -> V_119 , & V_97 -> V_111 ) ;
if ( ! V_84 )
V_84 = V_97 -> V_111 . V_139 ;
F_105 ( V_97 ) ;
V_131:
if ( V_84 )
F_29 ( V_48 L_33 , V_84 ) ;
}
int
F_110 ( struct V_69 * V_69 )
{
int V_20 ;
struct V_76 V_76 ;
if ( ! V_145 ) {
V_145 = & V_146 ;
V_20 = F_63 ( F_66 () , V_77 , & V_76 ) ;
if ( ! V_20 ) {
if ( F_64 ( V_76 . V_36 -> V_42 -> V_79 ) )
V_145 =
& V_147 ;
F_65 ( & V_76 ) ;
}
}
V_20 = V_145 -> V_148 ( V_69 ) ;
if ( V_20 ) {
F_29 ( V_149 L_34
L_35 , V_20 ) ;
V_145 = NULL ;
}
return V_20 ;
}
void
F_111 ( struct V_69 * V_69 )
{
if ( V_145 ) {
V_145 -> exit ( V_69 ) ;
V_145 = NULL ;
}
}
void
F_112 ( struct V_32 * V_33 )
{
if ( V_145 )
V_145 -> V_150 ( V_33 ) ;
}
void
F_113 ( struct V_32 * V_33 )
{
if ( V_145 )
V_145 -> remove ( V_33 ) ;
}
int
F_114 ( struct V_32 * V_33 )
{
if ( V_145 )
return V_145 -> V_151 ( V_33 ) ;
return - V_152 ;
}
void
F_115 ( struct V_69 * V_69 , T_5 V_70 )
{
if ( V_145 )
V_145 -> V_153 ( V_69 , V_70 ) ;
}
static int
F_116 ( struct V_154 * V_155 , unsigned long V_156 , void * V_157 )
{
struct V_114 * V_115 = V_157 ;
struct V_69 * V_69 = V_115 -> V_103 ;
struct V_99 * V_100 = F_76 ( V_69 , V_104 ) ;
struct V_105 * V_106 = V_100 -> V_105 ;
struct V_36 * V_36 ;
int V_84 = 0 ;
if ( ! F_117 ( V_158 ) )
return 0 ;
if ( ! V_106 ) {
F_118 ( V_158 ) ;
return 0 ;
}
switch ( V_156 ) {
case V_159 :
V_36 = F_86 ( V_115 , V_106 -> V_119 ) ;
if ( F_11 ( V_36 ) ) {
V_84 = F_22 ( V_36 ) ;
break;
}
V_106 -> V_119 -> V_36 = V_36 ;
break;
case V_160 :
if ( V_106 -> V_119 -> V_36 )
F_90 ( V_106 -> V_119 ) ;
break;
default:
V_84 = - V_161 ;
break;
}
F_118 ( V_158 ) ;
return V_84 ;
}
int
F_119 ( void )
{
return F_120 ( & V_162 ) ;
}
void
F_121 ( void )
{
F_122 ( & V_162 ) ;
}
