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
static int
F_8 ( char * V_12 , const struct V_13 * V_14 )
{
struct V_13 V_15 ;
struct V_16 V_17 ;
struct V_18 V_19 ;
int V_20 ;
F_9 ( L_1 ,
V_14 -> V_21 , V_14 -> V_22 ) ;
V_17 . V_23 = V_24 ;
V_17 . V_25 = F_10 ( L_2 , 0 , V_26 ) ;
if ( F_11 ( V_17 . V_25 ) ) {
V_20 = F_12 ( V_17 . V_25 ) ;
goto V_27;
}
V_15 . V_21 = F_13 ( V_17 . V_25 ) ;
V_15 . V_22 = F_14 ( V_15 . V_21 , V_28 ) ;
if ( V_15 . V_22 == NULL ) {
V_20 = - V_4 ;
goto V_8;
}
F_15 ( & V_19 , V_14 -> V_22 , V_14 -> V_21 ) ;
V_20 = F_16 ( & V_17 , & V_19 , V_19 . V_29 , V_15 . V_22 ) ;
if ( V_20 )
goto V_8;
F_7 ( V_12 , V_15 . V_22 ) ;
V_20 = 0 ;
V_8:
F_17 ( V_15 . V_22 ) ;
F_18 ( V_17 . V_25 ) ;
V_27:
return V_20 ;
}
static void
F_19 ( int error )
{
F_20 ( V_30 L_3
L_4 , error ) ;
if ( error == - V_31 ) {
F_20 ( V_30 L_5
L_6 ) ;
F_21 ( NULL ) ;
}
}
static void
F_22 ( struct V_32 * V_33 )
{
const struct V_1 * V_34 ;
char V_12 [ V_35 ] ;
struct V_36 * V_37 , * V_36 ;
struct V_38 * V_39 ;
int V_20 ;
struct V_40 * V_41 = F_23 ( V_33 -> V_42 , V_43 ) ;
F_9 ( L_7 , V_12 ) ;
if ( F_24 ( V_44 , & V_33 -> V_45 ) )
return;
if ( ! V_41 -> V_46 )
return;
V_20 = F_8 ( V_12 , & V_33 -> V_47 ) ;
if ( V_20 )
return F_19 ( V_20 ) ;
V_20 = F_1 ( & V_34 ) ;
if ( V_20 < 0 )
return;
V_20 = F_25 ( V_41 -> V_46 ) ;
if ( V_20 )
return;
V_37 = V_41 -> V_46 -> V_48 . V_36 ;
F_26 ( & V_37 -> V_49 -> V_50 ) ;
V_36 = F_27 ( V_12 , V_37 , V_35 - 1 ) ;
if ( F_11 ( V_36 ) ) {
V_20 = F_12 ( V_36 ) ;
goto V_51;
}
if ( V_36 -> V_49 )
goto V_52;
V_20 = F_28 ( V_37 -> V_49 , V_36 , V_53 ) ;
V_52:
F_29 ( V_36 ) ;
V_51:
F_30 ( & V_37 -> V_49 -> V_50 ) ;
if ( V_20 == 0 ) {
if ( V_41 -> V_54 ) {
V_39 = F_31 ( V_12 , V_41 ) ;
if ( V_39 )
V_39 -> V_55 = V_33 ;
}
F_32 ( V_41 -> V_46 , 0 ) ;
} else {
F_20 ( V_30 L_8
L_9
L_10 , V_20 ,
V_56 ) ;
}
F_33 ( V_41 -> V_46 ) ;
F_5 ( V_34 ) ;
}
static int
F_34 ( void * V_57 , const char * V_58 , int V_59 ,
T_1 V_60 , T_2 V_61 , unsigned int V_62 )
{
struct V_63 * V_64 = V_57 ;
struct V_65 * V_66 ;
if ( V_59 != V_35 - 1 )
return 0 ;
V_66 = F_14 ( sizeof( struct V_65 ) , V_28 ) ;
if ( V_66 == NULL )
return - V_4 ;
memcpy ( V_66 -> V_58 , V_58 , V_35 - 1 ) ;
V_66 -> V_58 [ V_35 - 1 ] = '\0' ;
F_35 ( & V_66 -> V_67 , V_64 ) ;
return 0 ;
}
static int
F_36 ( T_3 * V_68 , struct V_40 * V_41 )
{
const struct V_1 * V_34 ;
struct V_36 * V_37 = V_41 -> V_46 -> V_48 . V_36 ;
F_37 ( V_64 ) ;
int V_20 ;
V_20 = F_1 ( & V_34 ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 = F_38 ( V_41 -> V_46 , 0 , V_69 ) ;
if ( V_20 < 0 ) {
F_5 ( V_34 ) ;
return V_20 ;
}
V_20 = F_39 ( V_41 -> V_46 , F_34 , & V_64 ) ;
F_40 ( & V_37 -> V_49 -> V_50 , V_70 ) ;
while ( ! F_41 ( & V_64 ) ) {
struct V_65 * V_66 ;
V_66 = F_42 ( V_64 . V_71 , struct V_65 , V_67 ) ;
if ( ! V_20 ) {
struct V_36 * V_36 ;
V_36 = F_27 ( V_66 -> V_58 , V_37 , V_35 - 1 ) ;
if ( F_11 ( V_36 ) ) {
V_20 = F_12 ( V_36 ) ;
break;
}
V_20 = V_68 ( V_37 , V_36 , V_41 ) ;
F_29 ( V_36 ) ;
}
F_43 ( & V_66 -> V_67 ) ;
F_17 ( V_66 ) ;
}
F_30 ( & V_37 -> V_49 -> V_50 ) ;
F_5 ( V_34 ) ;
return V_20 ;
}
static int
F_44 ( char * V_58 , int V_59 , struct V_40 * V_41 )
{
struct V_36 * V_37 , * V_36 ;
int V_20 ;
F_9 ( L_11 , V_59 , V_58 ) ;
V_37 = V_41 -> V_46 -> V_48 . V_36 ;
F_40 ( & V_37 -> V_49 -> V_50 , V_70 ) ;
V_36 = F_27 ( V_58 , V_37 , V_59 ) ;
if ( F_11 ( V_36 ) ) {
V_20 = F_12 ( V_36 ) ;
goto V_51;
}
V_20 = - V_31 ;
if ( ! V_36 -> V_49 )
goto V_8;
V_20 = F_45 ( V_37 -> V_49 , V_36 ) ;
V_8:
F_29 ( V_36 ) ;
V_51:
F_30 ( & V_37 -> V_49 -> V_50 ) ;
return V_20 ;
}
static void
F_46 ( struct V_32 * V_33 )
{
const struct V_1 * V_34 ;
struct V_38 * V_39 ;
char V_12 [ V_35 ] ;
int V_20 ;
struct V_40 * V_41 = F_23 ( V_33 -> V_42 , V_43 ) ;
if ( ! V_41 -> V_46 || ! F_47 ( V_44 , & V_33 -> V_45 ) )
return;
V_20 = F_8 ( V_12 , & V_33 -> V_47 ) ;
if ( V_20 )
return F_19 ( V_20 ) ;
V_20 = F_25 ( V_41 -> V_46 ) ;
if ( V_20 )
goto V_8;
F_48 ( V_44 , & V_33 -> V_45 ) ;
V_20 = F_1 ( & V_34 ) ;
if ( V_20 < 0 )
goto V_72;
V_20 = F_44 ( V_12 , V_35 - 1 , V_41 ) ;
F_5 ( V_34 ) ;
if ( V_20 == 0 ) {
F_32 ( V_41 -> V_46 , 0 ) ;
if ( V_41 -> V_54 ) {
V_39 = F_49 ( V_12 , V_41 ) ;
if ( V_39 )
F_50 ( V_39 , V_41 ) ;
}
}
V_72:
F_33 ( V_41 -> V_46 ) ;
V_8:
if ( V_20 )
F_20 ( L_12
L_13 , V_35 , V_12 ) ;
}
static int
F_51 ( struct V_36 * V_73 , struct V_36 * V_74 , struct V_40 * V_41 )
{
int V_20 ;
if ( F_52 ( V_74 -> V_75 . V_58 , V_41 ) )
return 0 ;
V_20 = F_45 ( V_73 -> V_49 , V_74 ) ;
if ( V_20 )
F_20 ( L_14 ,
V_74 -> V_75 . V_58 ) ;
return 0 ;
}
static void
F_53 ( struct V_40 * V_41 , T_4 V_76 )
{
int V_20 ;
V_41 -> V_54 = false ;
if ( ! V_41 -> V_46 )
return;
V_20 = F_25 ( V_41 -> V_46 ) ;
if ( V_20 )
goto V_8;
V_20 = F_36 ( F_51 , V_41 ) ;
if ( V_20 == 0 )
F_32 ( V_41 -> V_46 , 0 ) ;
F_33 ( V_41 -> V_46 ) ;
V_8:
F_54 ( V_41 ) ;
if ( V_20 )
F_20 ( L_15
L_16 , V_41 -> V_46 -> V_48 . V_36 -> V_75 . V_58 ) ;
}
static int
F_55 ( struct V_36 * V_73 , struct V_36 * V_74 , struct V_40 * V_41 )
{
if ( V_74 -> V_75 . V_21 != V_35 - 1 ) {
F_20 ( L_17 ,
V_74 -> V_75 . V_58 ) ;
return 0 ;
}
F_31 ( V_74 -> V_75 . V_58 , V_41 ) ;
return 0 ;
}
static int
F_56 ( struct V_42 * V_42 ) {
int V_20 ;
struct V_40 * V_41 = F_23 ( V_42 , V_43 ) ;
if ( ! V_41 -> V_46 )
return 0 ;
V_20 = F_36 ( F_55 , V_41 ) ;
if ( V_20 )
F_20 ( L_18
L_16 , V_41 -> V_46 -> V_48 . V_36 -> V_75 . V_58 ) ;
return V_20 ;
}
static int
F_57 ( struct V_42 * V_42 )
{
struct V_40 * V_41 = F_23 ( V_42 , V_43 ) ;
const struct V_1 * V_34 ;
int V_20 ;
F_20 ( L_19 ,
V_56 ) ;
F_58 ( V_41 -> V_46 ) ;
V_20 = F_1 ( & V_34 ) ;
if ( V_20 < 0 ) {
F_20 ( L_20
L_21 ,
V_20 ) ;
return V_20 ;
}
V_41 -> V_46 = F_59 ( V_56 , V_77 | V_78 , 0 ) ;
if ( F_11 ( V_41 -> V_46 ) ) {
F_20 ( L_22 ,
V_56 ) ;
V_20 = F_12 ( V_41 -> V_46 ) ;
V_41 -> V_46 = NULL ;
}
F_5 ( V_34 ) ;
if ( ! V_20 )
V_41 -> V_54 = true ;
return V_20 ;
}
static int
F_60 ( struct V_42 * V_42 )
{
struct V_40 * V_41 = F_23 ( V_42 , V_43 ) ;
int V_10 ;
V_41 -> V_79 = F_14 ( sizeof( struct V_63 ) *
V_80 , V_28 ) ;
if ( ! V_41 -> V_79 )
return - V_4 ;
for ( V_10 = 0 ; V_10 < V_80 ; V_10 ++ )
F_61 ( & V_41 -> V_79 [ V_10 ] ) ;
V_41 -> V_81 = 0 ;
return 0 ;
}
static void
F_62 ( struct V_42 * V_42 )
{
struct V_40 * V_41 = F_23 ( V_42 , V_43 ) ;
F_17 ( V_41 -> V_79 ) ;
}
static int
F_63 ( struct V_42 * V_42 )
{
int V_20 ;
V_20 = F_57 ( V_42 ) ;
if ( ! V_20 )
V_20 = F_56 ( V_42 ) ;
if ( V_20 )
F_20 ( V_30 L_23 ) ;
return V_20 ;
}
static int
F_64 ( struct V_42 * V_42 )
{
int V_20 ;
if ( V_42 != & V_82 ) {
F_65 ( 1 , V_30 L_24
L_25 ) ;
return - V_83 ;
}
V_20 = F_60 ( V_42 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_63 ( V_42 ) ;
if ( V_20 )
goto V_84;
return 0 ;
V_84:
F_62 ( V_42 ) ;
return V_20 ;
}
static void
F_66 ( struct V_40 * V_41 )
{
if ( ! V_41 -> V_46 )
return;
F_67 ( V_41 -> V_46 ) ;
V_41 -> V_46 = NULL ;
}
static void
F_68 ( struct V_42 * V_42 )
{
struct V_40 * V_41 = F_23 ( V_42 , V_43 ) ;
F_54 ( V_41 ) ;
F_66 ( V_41 ) ;
F_62 ( V_42 ) ;
}
int
F_69 ( char * V_85 )
{
int V_20 ;
struct V_86 V_86 ;
V_20 = F_70 ( V_85 , V_87 , & V_86 ) ;
if ( V_20 )
return V_20 ;
V_20 = - V_88 ;
if ( F_71 ( V_86 . V_36 -> V_49 -> V_89 ) ) {
strcpy ( V_56 , V_85 ) ;
V_20 = 0 ;
}
F_72 ( & V_86 ) ;
return V_20 ;
}
char *
F_73 ( void )
{
return V_56 ;
}
static int
F_74 ( struct V_32 * V_33 )
{
int V_20 ;
char V_12 [ V_35 ] ;
struct V_38 * V_39 ;
struct V_40 * V_41 = F_23 ( V_33 -> V_42 , V_43 ) ;
if ( F_47 ( V_44 , & V_33 -> V_45 ) )
return 0 ;
V_20 = F_8 ( V_12 , & V_33 -> V_47 ) ;
if ( V_20 ) {
F_19 ( V_20 ) ;
return V_20 ;
}
V_39 = F_49 ( V_12 , V_41 ) ;
if ( V_39 ) {
F_75 ( V_44 , & V_33 -> V_45 ) ;
V_39 -> V_55 = V_33 ;
return 0 ;
}
return - V_31 ;
}
static int
F_76 ( struct V_90 * V_91 , struct V_92 * V_93 )
{
int V_94 ;
struct V_95 V_96 ;
memset ( & V_96 , 0 , sizeof( V_96 ) ) ;
V_96 . V_22 = V_93 ;
V_96 . V_21 = sizeof( * V_93 ) ;
F_77 ( V_97 ) ;
V_94 = F_78 ( V_91 , & V_96 ) ;
if ( V_94 < 0 ) {
F_77 ( V_98 ) ;
goto V_8;
}
F_79 () ;
F_77 ( V_98 ) ;
if ( V_96 . V_99 < 0 )
V_94 = V_96 . V_99 ;
V_8:
return V_94 ;
}
static int
F_80 ( struct V_90 * V_91 , struct V_92 * V_93 )
{
int V_94 ;
do {
V_94 = F_76 ( V_91 , V_93 ) ;
} while ( V_94 == - V_100 );
return V_94 ;
}
static T_5
F_81 ( struct V_101 * V_102 , const char T_6 * V_103 , T_7 V_104 )
{
struct V_105 * V_106 , * V_107 ;
struct V_92 T_6 * V_93 = (struct V_92 T_6 * ) V_103 ;
T_8 V_108 ;
struct V_40 * V_41 = F_23 ( V_102 -> V_109 -> V_110 -> V_111 ,
V_43 ) ;
struct V_112 * V_113 = V_41 -> V_112 ;
if ( V_104 != sizeof( * V_93 ) ) {
F_9 ( L_26 , V_114 , V_104 ,
sizeof( * V_93 ) ) ;
return - V_83 ;
}
if ( F_82 ( & V_108 , & V_93 -> V_115 , sizeof( V_108 ) ) != 0 ) {
F_9 ( L_27 , V_114 ) ;
return - V_116 ;
}
V_107 = NULL ;
F_83 ( & V_113 -> V_117 ) ;
F_84 (tmp, &cn->cn_list, cu_list) {
if ( F_85 ( & V_106 -> V_118 . V_115 ) == V_108 ) {
V_107 = V_106 ;
F_86 ( & V_107 -> V_119 ) ;
break;
}
}
F_87 ( & V_113 -> V_117 ) ;
if ( ! V_107 ) {
F_9 ( L_28 , V_114 , V_108 ) ;
return - V_83 ;
}
if ( F_82 ( & V_107 -> V_118 , V_103 , V_104 ) != 0 )
return - V_116 ;
F_88 ( V_107 -> V_120 ) ;
return V_104 ;
}
static void
F_89 ( struct V_95 * V_96 )
{
struct V_92 * V_93 = V_96 -> V_22 ;
struct V_105 * V_107 = F_90 ( V_93 , struct V_105 ,
V_118 ) ;
if ( V_96 -> V_99 >= 0 )
return;
F_88 ( V_107 -> V_120 ) ;
}
static struct V_36 *
F_91 ( struct V_121 * V_122 , struct V_90 * V_91 )
{
struct V_36 * V_37 , * V_36 ;
V_37 = F_92 ( V_122 , V_123 ) ;
if ( V_37 == NULL )
return F_93 ( - V_31 ) ;
V_36 = F_94 ( V_37 , V_124 , NULL , V_91 ) ;
F_29 ( V_37 ) ;
return V_36 ;
}
static void
F_95 ( struct V_90 * V_91 )
{
if ( V_91 -> V_36 )
F_96 ( V_91 -> V_36 ) ;
}
static struct V_36 *
F_97 ( struct V_42 * V_42 , struct V_90 * V_91 )
{
struct V_121 * V_122 ;
struct V_36 * V_36 ;
V_122 = F_98 ( V_42 ) ;
if ( ! V_122 )
return NULL ;
V_36 = F_91 ( V_122 , V_91 ) ;
F_99 ( V_42 ) ;
return V_36 ;
}
static void
F_100 ( struct V_42 * V_42 , struct V_90 * V_91 )
{
struct V_121 * V_122 ;
V_122 = F_98 ( V_42 ) ;
if ( V_122 ) {
F_95 ( V_91 ) ;
F_99 ( V_42 ) ;
}
}
static int
F_101 ( struct V_42 * V_42 )
{
int V_94 ;
struct V_36 * V_36 ;
struct V_40 * V_41 = F_23 ( V_42 , V_43 ) ;
struct V_112 * V_113 ;
if ( V_41 -> V_112 )
return 0 ;
V_113 = F_102 ( sizeof( * V_113 ) , V_28 ) ;
if ( ! V_113 ) {
V_94 = - V_4 ;
goto V_84;
}
V_113 -> V_125 = F_103 ( & V_126 , V_127 ) ;
if ( F_11 ( V_113 -> V_125 ) ) {
V_94 = F_12 ( V_113 -> V_125 ) ;
goto V_84;
}
F_104 ( & V_113 -> V_117 ) ;
F_61 ( & V_113 -> V_128 ) ;
V_36 = F_97 ( V_42 , V_113 -> V_125 ) ;
if ( F_11 ( V_36 ) ) {
V_94 = F_12 ( V_36 ) ;
goto V_129;
}
V_113 -> V_125 -> V_36 = V_36 ;
V_41 -> V_112 = V_113 ;
return 0 ;
V_129:
F_105 ( V_113 -> V_125 ) ;
V_84:
F_17 ( V_113 ) ;
F_20 ( V_30 L_29 ,
V_94 ) ;
return V_94 ;
}
static void
F_106 ( struct V_42 * V_42 )
{
struct V_40 * V_41 = F_23 ( V_42 , V_43 ) ;
struct V_112 * V_113 = V_41 -> V_112 ;
F_100 ( V_42 , V_113 -> V_125 ) ;
F_105 ( V_113 -> V_125 ) ;
F_17 ( V_41 -> V_112 ) ;
V_41 -> V_112 = NULL ;
}
static struct V_105 *
F_107 ( struct V_112 * V_113 )
{
struct V_105 * V_3 , * V_106 ;
V_3 = F_102 ( sizeof( * V_3 ) , V_28 ) ;
if ( ! V_3 )
return V_3 ;
V_130:
F_83 ( & V_113 -> V_117 ) ;
F_84 (tmp, &cn->cn_list, cu_list) {
if ( V_106 -> V_118 . V_115 == V_113 -> V_131 ) {
V_113 -> V_131 ++ ;
F_87 ( & V_113 -> V_117 ) ;
goto V_130;
}
}
V_3 -> V_120 = V_132 ;
V_3 -> V_118 . V_133 = V_134 ;
F_108 ( V_113 -> V_131 ++ , & V_3 -> V_118 . V_115 ) ;
V_3 -> V_135 = V_113 ;
F_35 ( & V_3 -> V_119 , & V_113 -> V_128 ) ;
F_87 ( & V_113 -> V_117 ) ;
F_9 ( L_30 , V_114 , V_3 -> V_118 . V_115 ) ;
return V_3 ;
}
static void
F_109 ( struct V_105 * V_136 )
{
struct V_112 * V_113 = V_136 -> V_135 ;
F_83 ( & V_113 -> V_117 ) ;
F_43 ( & V_136 -> V_119 ) ;
F_87 ( & V_113 -> V_117 ) ;
F_17 ( V_136 ) ;
}
static void
F_110 ( struct V_32 * V_33 )
{
int V_94 ;
struct V_105 * V_107 ;
struct V_40 * V_41 = F_23 ( V_33 -> V_42 , V_43 ) ;
struct V_112 * V_113 = V_41 -> V_112 ;
if ( F_47 ( V_44 , & V_33 -> V_45 ) )
return;
V_107 = F_107 ( V_113 ) ;
if ( ! V_107 ) {
V_94 = - V_4 ;
goto V_137;
}
V_107 -> V_118 . V_138 = V_139 ;
V_107 -> V_118 . V_140 . V_141 . V_142 = V_33 -> V_47 . V_21 ;
memcpy ( V_107 -> V_118 . V_140 . V_141 . V_143 , V_33 -> V_47 . V_22 ,
V_33 -> V_47 . V_21 ) ;
V_94 = F_80 ( V_113 -> V_125 , & V_107 -> V_118 ) ;
if ( ! V_94 ) {
V_94 = V_107 -> V_118 . V_144 ;
F_75 ( V_44 , & V_33 -> V_45 ) ;
}
F_109 ( V_107 ) ;
V_137:
if ( V_94 )
F_20 ( V_30 L_31
L_32 , V_94 ) ;
}
static void
F_111 ( struct V_32 * V_33 )
{
int V_94 ;
struct V_105 * V_107 ;
struct V_40 * V_41 = F_23 ( V_33 -> V_42 , V_43 ) ;
struct V_112 * V_113 = V_41 -> V_112 ;
if ( ! F_47 ( V_44 , & V_33 -> V_45 ) )
return;
V_107 = F_107 ( V_113 ) ;
if ( ! V_107 ) {
V_94 = - V_4 ;
goto V_137;
}
V_107 -> V_118 . V_138 = V_145 ;
V_107 -> V_118 . V_140 . V_141 . V_142 = V_33 -> V_47 . V_21 ;
memcpy ( V_107 -> V_118 . V_140 . V_141 . V_143 , V_33 -> V_47 . V_22 ,
V_33 -> V_47 . V_21 ) ;
V_94 = F_80 ( V_113 -> V_125 , & V_107 -> V_118 ) ;
if ( ! V_94 ) {
V_94 = V_107 -> V_118 . V_144 ;
F_48 ( V_44 , & V_33 -> V_45 ) ;
}
F_109 ( V_107 ) ;
V_137:
if ( V_94 )
F_20 ( V_30 L_33
L_34 , V_94 ) ;
}
static int
F_112 ( struct V_32 * V_33 )
{
int V_94 ;
struct V_105 * V_107 ;
struct V_40 * V_41 = F_23 ( V_33 -> V_42 , V_43 ) ;
struct V_112 * V_113 = V_41 -> V_112 ;
if ( F_47 ( V_44 , & V_33 -> V_45 ) )
return 0 ;
V_107 = F_107 ( V_113 ) ;
if ( ! V_107 ) {
F_20 ( V_30 L_35
L_36 , - V_4 ) ;
return - V_4 ;
}
V_107 -> V_118 . V_138 = V_146 ;
V_107 -> V_118 . V_140 . V_141 . V_142 = V_33 -> V_47 . V_21 ;
memcpy ( V_107 -> V_118 . V_140 . V_141 . V_143 , V_33 -> V_47 . V_22 ,
V_33 -> V_47 . V_21 ) ;
V_94 = F_80 ( V_113 -> V_125 , & V_107 -> V_118 ) ;
if ( ! V_94 ) {
V_94 = V_107 -> V_118 . V_144 ;
F_75 ( V_44 , & V_33 -> V_45 ) ;
}
F_109 ( V_107 ) ;
return V_94 ;
}
static void
F_113 ( struct V_40 * V_41 , T_4 V_76 )
{
int V_94 ;
struct V_105 * V_107 ;
struct V_112 * V_113 = V_41 -> V_112 ;
V_107 = F_107 ( V_113 ) ;
if ( ! V_107 ) {
V_94 = - V_4 ;
goto V_137;
}
V_107 -> V_118 . V_138 = V_147 ;
V_107 -> V_118 . V_140 . V_148 = ( V_149 ) V_76 ;
V_94 = F_80 ( V_113 -> V_125 , & V_107 -> V_118 ) ;
if ( ! V_94 )
V_94 = V_107 -> V_118 . V_144 ;
F_109 ( V_107 ) ;
V_137:
if ( V_94 )
F_20 ( V_30 L_37 , V_94 ) ;
}
static char *
F_114 ( void )
{
int V_150 ;
T_7 V_21 ;
char * V_151 ;
if ( V_152 )
return NULL ;
V_21 = strlen ( V_153 ) +
strlen ( F_73 () ) + 1 ;
V_151 = F_14 ( V_21 , V_28 ) ;
if ( ! V_151 )
return V_151 ;
V_150 = snprintf ( V_151 , V_21 , V_153 L_38 ,
F_73 () ) ;
if ( V_150 >= V_21 ) {
F_17 ( V_151 ) ;
return NULL ;
}
return V_151 ;
}
static char *
F_115 ( const struct V_13 * V_58 )
{
int V_150 ;
T_7 V_21 ;
char * V_151 ;
if ( V_152 )
return NULL ;
V_21 = strlen ( V_154 ) +
strlen ( F_73 () ) + 1 + V_35 ;
V_151 = F_14 ( V_21 , V_28 ) ;
if ( ! V_151 )
return V_151 ;
V_150 = snprintf ( V_151 , V_21 , V_154 L_39 ,
F_73 () ) ;
if ( V_150 > ( V_21 - V_35 ) ) {
F_17 ( V_151 ) ;
return NULL ;
}
V_150 = F_8 ( V_151 + V_150 , V_58 ) ;
if ( V_150 ) {
F_17 ( V_151 ) ;
return NULL ;
}
return V_151 ;
}
static int
F_116 ( char * V_155 , char * V_57 , char * V_156 )
{
char * V_157 [ 2 ] ;
char * V_158 [ 4 ] ;
int V_94 ;
if ( F_117 ( ! V_159 [ 0 ] ) ) {
F_9 ( L_40 , V_114 ) ;
return - V_160 ;
}
F_9 ( L_41 , V_114 , V_155 ) ;
F_9 ( L_42 , V_114 , V_57 ? V_57 : L_43 ) ;
F_9 ( L_44 , V_114 , V_156 ? V_156 : L_43 ) ;
V_157 [ 0 ] = V_156 ;
V_157 [ 1 ] = NULL ;
V_158 [ 0 ] = ( char * ) V_159 ;
V_158 [ 1 ] = V_155 ;
V_158 [ 2 ] = V_57 ;
V_158 [ 3 ] = NULL ;
V_94 = F_118 ( V_158 [ 0 ] , V_158 , V_157 , V_161 ) ;
if ( V_94 == - V_31 || V_94 == - V_160 ) {
F_9 ( L_45
L_46 ,
V_159 , V_94 ) ;
V_159 [ 0 ] = '\0' ;
}
F_9 ( L_47 , V_114 , V_159 , V_94 ) ;
return V_94 ;
}
static char *
F_119 ( const unsigned char * V_103 , int V_162 )
{
int V_10 ;
char * V_163 , * V_164 ;
V_163 = F_14 ( ( V_162 * 2 ) + 1 , V_28 ) ;
if ( ! V_163 )
return V_163 ;
V_164 = V_163 ;
for ( V_10 = 0 ; V_10 < V_162 ; V_10 ++ ) {
sprintf ( V_164 , L_48 , * V_103 ++ ) ;
V_164 += 2 ;
}
return V_163 ;
}
static void
F_120 ( struct V_32 * V_33 )
{
char * V_165 ;
V_165 = F_119 ( V_33 -> V_47 . V_22 , V_33 -> V_47 . V_21 ) ;
if ( ! V_165 ) {
F_9 ( L_49 , V_114 ) ;
return;
}
F_116 ( L_50 , V_165 , NULL ) ;
F_17 ( V_165 ) ;
}
static void
F_121 ( struct V_32 * V_33 )
{
char * V_165 ;
V_165 = F_119 ( V_33 -> V_47 . V_22 , V_33 -> V_47 . V_21 ) ;
if ( ! V_165 ) {
F_9 ( L_49 , V_114 ) ;
return;
}
F_116 ( L_51 , V_165 , NULL ) ;
F_17 ( V_165 ) ;
}
static int
F_122 ( struct V_32 * V_33 )
{
int V_94 ;
char * V_165 , * V_156 ;
V_165 = F_119 ( V_33 -> V_47 . V_22 , V_33 -> V_47 . V_21 ) ;
if ( ! V_165 ) {
F_9 ( L_49 , V_114 ) ;
return - V_4 ;
}
V_156 = F_115 ( & V_33 -> V_47 ) ;
V_94 = F_116 ( L_52 , V_165 , V_156 ) ;
F_17 ( V_156 ) ;
F_17 ( V_165 ) ;
return V_94 ;
}
int
F_123 ( struct V_42 * V_42 )
{
int V_20 ;
struct V_86 V_86 ;
struct V_40 * V_41 = F_23 ( V_42 , V_43 ) ;
if ( V_41 -> V_166 )
goto V_167;
V_41 -> V_166 = & V_168 ;
V_20 = V_41 -> V_166 -> V_169 ( V_42 ) ;
if ( ! V_20 )
return V_20 ;
V_41 -> V_166 = & V_170 ;
V_20 = F_70 ( F_73 () , V_87 , & V_86 ) ;
if ( ! V_20 ) {
V_20 = F_71 ( V_86 . V_36 -> V_49 -> V_89 ) ;
F_72 ( & V_86 ) ;
if ( V_20 )
goto V_167;
}
V_41 -> V_166 = & V_171 ;
F_20 ( V_172 L_53
L_54
L_55 ) ;
V_167:
V_20 = V_41 -> V_166 -> V_169 ( V_42 ) ;
if ( V_20 ) {
F_20 ( V_172 L_56
L_57 , V_20 ) ;
V_41 -> V_166 = NULL ;
}
return V_20 ;
}
void
F_21 ( struct V_42 * V_42 )
{
struct V_40 * V_41 = F_23 ( V_42 , V_43 ) ;
if ( V_41 -> V_166 ) {
if ( V_41 -> V_166 -> exit )
V_41 -> V_166 -> exit ( V_42 ) ;
V_41 -> V_166 = NULL ;
}
}
void
F_124 ( struct V_32 * V_33 )
{
struct V_40 * V_41 = F_23 ( V_33 -> V_42 , V_43 ) ;
if ( V_41 -> V_166 )
V_41 -> V_166 -> V_173 ( V_33 ) ;
}
void
F_125 ( struct V_32 * V_33 )
{
struct V_40 * V_41 = F_23 ( V_33 -> V_42 , V_43 ) ;
if ( V_41 -> V_166 )
V_41 -> V_166 -> remove ( V_33 ) ;
}
int
F_126 ( struct V_32 * V_33 )
{
struct V_40 * V_41 = F_23 ( V_33 -> V_42 , V_43 ) ;
if ( V_41 -> V_166 )
return V_41 -> V_166 -> V_174 ( V_33 ) ;
return - V_175 ;
}
void
F_127 ( struct V_40 * V_41 , T_4 V_76 )
{
if ( V_41 -> V_166 )
V_41 -> V_166 -> V_176 ( V_41 , V_76 ) ;
}
static int
F_128 ( struct V_177 * V_178 , unsigned long V_179 , void * V_180 )
{
struct V_121 * V_122 = V_180 ;
struct V_42 * V_42 = V_122 -> V_111 ;
struct V_40 * V_41 = F_23 ( V_42 , V_43 ) ;
struct V_112 * V_113 = V_41 -> V_112 ;
struct V_36 * V_36 ;
int V_94 = 0 ;
if ( ! F_129 ( V_181 ) )
return 0 ;
if ( ! V_113 ) {
F_130 ( V_181 ) ;
return 0 ;
}
switch ( V_179 ) {
case V_182 :
V_36 = F_91 ( V_122 , V_113 -> V_125 ) ;
if ( F_11 ( V_36 ) ) {
V_94 = F_12 ( V_36 ) ;
break;
}
V_113 -> V_125 -> V_36 = V_36 ;
break;
case V_183 :
if ( V_113 -> V_125 -> V_36 )
F_95 ( V_113 -> V_125 ) ;
break;
default:
V_94 = - V_184 ;
break;
}
F_130 ( V_181 ) ;
return V_94 ;
}
int
F_131 ( void )
{
return F_132 ( & V_185 ) ;
}
void
F_133 ( void )
{
F_134 ( & V_185 ) ;
}
