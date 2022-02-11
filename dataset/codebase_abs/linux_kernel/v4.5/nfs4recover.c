static int
F_1 ( const struct V_1 * * V_2 )
{
struct V_1 * V_3 ;
V_3 = F_2 () ;
if ( ! V_3 )
return - V_4 ;
V_3 -> V_5 = V_6 ;
V_3 -> V_7 = V_8 ;
* V_2 = F_3 ( V_3 ) ;
F_4 ( V_3 ) ;
return 0 ;
}
static void
F_5 ( const struct V_1 * V_9 )
{
F_6 ( V_9 ) ;
}
static void
F_7 ( char * V_10 , char * V_11 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < 16 ; V_12 ++ ) {
unsigned char V_13 = V_11 [ V_12 ] ;
* V_10 ++ = '0' + ( ( V_13 & 0xf0 ) >> 4 ) + ( V_13 >= 0xa0 ) * ( 'a' - '9' - 1 ) ;
* V_10 ++ = '0' + ( V_13 & 0x0f ) + ( ( V_13 & 0x0f ) >= 0x0a ) * ( 'a' - '9' - 1 ) ;
}
* V_10 = '\0' ;
}
static int
F_8 ( char * V_14 , const struct V_15 * V_16 )
{
struct V_15 V_17 ;
struct V_18 V_19 ;
struct V_20 V_21 ;
int V_22 ;
F_9 ( L_1 ,
V_16 -> V_23 , V_16 -> V_24 ) ;
V_19 . V_25 = V_26 ;
V_19 . V_27 = F_10 ( L_2 , 0 , V_28 ) ;
if ( F_11 ( V_19 . V_27 ) ) {
V_22 = F_12 ( V_19 . V_27 ) ;
goto V_29;
}
V_17 . V_23 = F_13 ( V_19 . V_27 ) ;
V_17 . V_24 = F_14 ( V_17 . V_23 , V_30 ) ;
if ( V_17 . V_24 == NULL ) {
V_22 = - V_4 ;
goto V_10;
}
F_15 ( & V_21 , V_16 -> V_24 , V_16 -> V_23 ) ;
V_22 = F_16 ( & V_19 , & V_21 , V_21 . V_31 , V_17 . V_24 ) ;
if ( V_22 )
goto V_10;
F_7 ( V_14 , V_17 . V_24 ) ;
V_22 = 0 ;
V_10:
F_17 ( V_17 . V_24 ) ;
F_18 ( V_19 . V_27 ) ;
V_29:
return V_22 ;
}
static void
F_19 ( struct V_32 * V_33 , int error )
{
F_20 ( V_34 L_3
L_4 , error ) ;
if ( error == - V_35 ) {
F_20 ( V_34 L_5
L_6 ) ;
F_21 ( V_33 -> V_36 ) ;
}
}
static void
F_22 ( struct V_32 * V_33 )
{
const struct V_1 * V_37 ;
char V_14 [ V_38 ] ;
struct V_39 * V_40 , * V_39 ;
struct V_41 * V_42 ;
int V_22 ;
struct V_43 * V_44 = F_23 ( V_33 -> V_36 , V_45 ) ;
if ( F_24 ( V_46 , & V_33 -> V_47 ) )
return;
if ( ! V_44 -> V_48 )
return;
V_22 = F_8 ( V_14 , & V_33 -> V_49 ) ;
if ( V_22 )
return F_19 ( V_33 , V_22 ) ;
V_22 = F_1 ( & V_37 ) ;
if ( V_22 < 0 )
return;
V_22 = F_25 ( V_44 -> V_48 ) ;
if ( V_22 )
goto V_50;
V_40 = V_44 -> V_48 -> V_51 . V_39 ;
F_26 ( F_27 ( V_40 ) ) ;
V_39 = F_28 ( V_14 , V_40 , V_38 - 1 ) ;
if ( F_11 ( V_39 ) ) {
V_22 = F_12 ( V_39 ) ;
goto V_52;
}
if ( F_29 ( V_39 ) )
goto V_53;
V_22 = F_30 ( F_27 ( V_40 ) , V_39 , V_54 ) ;
V_53:
F_31 ( V_39 ) ;
V_52:
F_32 ( F_27 ( V_40 ) ) ;
if ( V_22 == 0 ) {
if ( V_44 -> V_55 ) {
V_42 = F_33 ( V_14 , V_44 ) ;
if ( V_42 )
V_42 -> V_56 = V_33 ;
}
F_34 ( V_44 -> V_48 , 0 ) ;
} else {
F_20 ( V_34 L_7
L_8
L_9 , V_22 ,
V_57 ) ;
}
F_35 ( V_44 -> V_48 ) ;
V_50:
F_5 ( V_37 ) ;
}
static int
F_36 ( struct V_58 * V_59 , const char * V_60 , int V_61 ,
T_1 V_62 , T_2 V_63 , unsigned int V_64 )
{
struct V_65 * V_66 =
F_37 ( V_59 , struct V_65 , V_66 ) ;
struct V_67 * V_68 ;
if ( V_61 != V_38 - 1 )
return 0 ;
V_68 = F_14 ( sizeof( struct V_67 ) , V_30 ) ;
if ( V_68 == NULL )
return - V_4 ;
memcpy ( V_68 -> V_60 , V_60 , V_38 - 1 ) ;
V_68 -> V_60 [ V_38 - 1 ] = '\0' ;
F_38 ( & V_68 -> V_69 , & V_66 -> V_70 ) ;
return 0 ;
}
static int
F_39 ( T_3 * V_71 , struct V_43 * V_44 )
{
const struct V_1 * V_37 ;
struct V_39 * V_40 = V_44 -> V_48 -> V_51 . V_39 ;
struct V_65 V_66 = {
. V_66 . V_72 = F_36 ,
. V_70 = F_40 (ctx.names)
} ;
struct V_67 * V_68 , * V_73 ;
int V_22 ;
V_22 = F_1 ( & V_37 ) ;
if ( V_22 < 0 )
return V_22 ;
V_22 = F_41 ( V_44 -> V_48 , 0 , V_74 ) ;
if ( V_22 < 0 ) {
F_5 ( V_37 ) ;
return V_22 ;
}
V_22 = F_42 ( V_44 -> V_48 , & V_66 . V_66 ) ;
F_43 ( F_27 ( V_40 ) , V_75 ) ;
F_44 (entry, tmp, &ctx.names, list) {
if ( ! V_22 ) {
struct V_39 * V_39 ;
V_39 = F_28 ( V_68 -> V_60 , V_40 , V_38 - 1 ) ;
if ( F_11 ( V_39 ) ) {
V_22 = F_12 ( V_39 ) ;
break;
}
V_22 = V_71 ( V_40 , V_39 , V_44 ) ;
F_31 ( V_39 ) ;
}
F_45 ( & V_68 -> V_69 ) ;
F_17 ( V_68 ) ;
}
F_32 ( F_27 ( V_40 ) ) ;
F_5 ( V_37 ) ;
F_44 (entry, tmp, &ctx.names, list) {
F_9 ( L_10 , V_76 , V_68 -> V_60 ) ;
F_45 ( & V_68 -> V_69 ) ;
F_17 ( V_68 ) ;
}
return V_22 ;
}
static int
F_46 ( char * V_60 , int V_61 , struct V_43 * V_44 )
{
struct V_39 * V_40 , * V_39 ;
int V_22 ;
F_9 ( L_11 , V_61 , V_60 ) ;
V_40 = V_44 -> V_48 -> V_51 . V_39 ;
F_43 ( F_27 ( V_40 ) , V_75 ) ;
V_39 = F_28 ( V_60 , V_40 , V_61 ) ;
if ( F_11 ( V_39 ) ) {
V_22 = F_12 ( V_39 ) ;
goto V_52;
}
V_22 = - V_35 ;
if ( F_47 ( V_39 ) )
goto V_10;
V_22 = F_48 ( F_27 ( V_40 ) , V_39 ) ;
V_10:
F_31 ( V_39 ) ;
V_52:
F_32 ( F_27 ( V_40 ) ) ;
return V_22 ;
}
static void
F_49 ( struct V_32 * V_33 )
{
const struct V_1 * V_37 ;
struct V_41 * V_42 ;
char V_14 [ V_38 ] ;
int V_22 ;
struct V_43 * V_44 = F_23 ( V_33 -> V_36 , V_45 ) ;
if ( ! V_44 -> V_48 || ! F_50 ( V_46 , & V_33 -> V_47 ) )
return;
V_22 = F_8 ( V_14 , & V_33 -> V_49 ) ;
if ( V_22 )
return F_19 ( V_33 , V_22 ) ;
V_22 = F_25 ( V_44 -> V_48 ) ;
if ( V_22 )
goto V_10;
F_51 ( V_46 , & V_33 -> V_47 ) ;
V_22 = F_1 ( & V_37 ) ;
if ( V_22 < 0 )
goto V_77;
V_22 = F_46 ( V_14 , V_38 - 1 , V_44 ) ;
F_5 ( V_37 ) ;
if ( V_22 == 0 ) {
F_34 ( V_44 -> V_48 , 0 ) ;
if ( V_44 -> V_55 ) {
V_42 = F_52 ( V_14 , V_44 ) ;
if ( V_42 )
F_53 ( V_42 , V_44 ) ;
}
}
V_77:
F_35 ( V_44 -> V_48 ) ;
V_10:
if ( V_22 )
F_20 ( L_12
L_13 , V_38 , V_14 ) ;
}
static int
F_54 ( struct V_39 * V_78 , struct V_39 * V_79 , struct V_43 * V_44 )
{
int V_22 ;
if ( F_55 ( V_79 -> V_80 . V_60 , V_44 ) )
return 0 ;
V_22 = F_48 ( F_27 ( V_78 ) , V_79 ) ;
if ( V_22 )
F_20 ( L_14 ,
V_79 ) ;
return 0 ;
}
static void
F_56 ( struct V_43 * V_44 )
{
int V_22 ;
V_44 -> V_55 = false ;
if ( ! V_44 -> V_48 )
return;
V_22 = F_25 ( V_44 -> V_48 ) ;
if ( V_22 )
goto V_10;
V_22 = F_39 ( F_54 , V_44 ) ;
if ( V_22 == 0 )
F_34 ( V_44 -> V_48 , 0 ) ;
F_35 ( V_44 -> V_48 ) ;
V_10:
F_57 ( V_44 ) ;
if ( V_22 )
F_20 ( L_15
L_16 , V_44 -> V_48 ) ;
}
static int
F_58 ( struct V_39 * V_78 , struct V_39 * V_79 , struct V_43 * V_44 )
{
if ( V_79 -> V_80 . V_23 != V_38 - 1 ) {
F_20 ( L_17 ,
V_79 ) ;
return 0 ;
}
F_33 ( V_79 -> V_80 . V_60 , V_44 ) ;
return 0 ;
}
static int
F_59 ( struct V_36 * V_36 ) {
int V_22 ;
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
if ( ! V_44 -> V_48 )
return 0 ;
V_22 = F_39 ( F_58 , V_44 ) ;
if ( V_22 )
F_20 ( L_18
L_16 , V_44 -> V_48 ) ;
return V_22 ;
}
static int
F_60 ( struct V_36 * V_36 )
{
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
const struct V_1 * V_37 ;
int V_22 ;
F_20 ( L_19 ,
V_57 ) ;
F_61 ( V_44 -> V_48 ) ;
V_22 = F_1 ( & V_37 ) ;
if ( V_22 < 0 ) {
F_20 ( L_20
L_21 ,
V_22 ) ;
return V_22 ;
}
V_44 -> V_48 = F_62 ( V_57 , V_81 | V_82 , 0 ) ;
if ( F_11 ( V_44 -> V_48 ) ) {
F_20 ( L_22 ,
V_57 ) ;
V_22 = F_12 ( V_44 -> V_48 ) ;
V_44 -> V_48 = NULL ;
}
F_5 ( V_37 ) ;
if ( ! V_22 )
V_44 -> V_55 = true ;
return V_22 ;
}
static void
F_63 ( struct V_36 * V_36 )
{
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
if ( ! V_44 -> V_48 )
return;
F_64 ( V_44 -> V_48 ) ;
V_44 -> V_48 = NULL ;
}
static int
F_65 ( struct V_36 * V_36 )
{
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
int V_12 ;
V_44 -> V_83 = F_14 ( sizeof( struct V_84 ) *
V_85 , V_30 ) ;
if ( ! V_44 -> V_83 )
return - V_4 ;
for ( V_12 = 0 ; V_12 < V_85 ; V_12 ++ )
F_66 ( & V_44 -> V_83 [ V_12 ] ) ;
V_44 -> V_86 = 0 ;
return 0 ;
}
static void
F_67 ( struct V_36 * V_36 )
{
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
F_17 ( V_44 -> V_83 ) ;
}
static int
F_68 ( struct V_36 * V_36 )
{
int V_22 ;
V_22 = F_60 ( V_36 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_59 ( V_36 ) ;
if ( V_22 )
F_63 ( V_36 ) ;
return V_22 ;
}
static int
F_69 ( struct V_36 * V_36 )
{
int V_22 ;
if ( V_36 != & V_87 ) {
F_70 ( L_23 ) ;
return - V_88 ;
}
V_22 = F_65 ( V_36 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_68 ( V_36 ) ;
if ( V_22 )
goto V_89;
return 0 ;
V_89:
F_67 ( V_36 ) ;
return V_22 ;
}
static void
F_71 ( struct V_36 * V_36 )
{
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
F_57 ( V_44 ) ;
F_63 ( V_36 ) ;
F_67 ( V_36 ) ;
}
int
F_72 ( char * V_90 )
{
int V_22 ;
struct V_91 V_91 ;
V_22 = F_73 ( V_90 , V_92 , & V_91 ) ;
if ( V_22 )
return V_22 ;
V_22 = - V_93 ;
if ( F_74 ( V_91 . V_39 ) ) {
strcpy ( V_57 , V_90 ) ;
V_22 = 0 ;
}
F_75 ( & V_91 ) ;
return V_22 ;
}
char *
F_76 ( void )
{
return V_57 ;
}
static int
F_77 ( struct V_32 * V_33 )
{
int V_22 ;
char V_14 [ V_38 ] ;
struct V_41 * V_42 ;
struct V_43 * V_44 = F_23 ( V_33 -> V_36 , V_45 ) ;
if ( F_50 ( V_46 , & V_33 -> V_47 ) )
return 0 ;
V_22 = F_8 ( V_14 , & V_33 -> V_49 ) ;
if ( V_22 ) {
F_19 ( V_33 , V_22 ) ;
return V_22 ;
}
V_42 = F_52 ( V_14 , V_44 ) ;
if ( V_42 ) {
F_78 ( V_46 , & V_33 -> V_47 ) ;
V_42 -> V_56 = V_33 ;
return 0 ;
}
return - V_35 ;
}
static int
F_79 ( struct V_94 * V_95 , struct V_96 * V_97 )
{
int V_98 ;
struct V_99 V_100 ;
memset ( & V_100 , 0 , sizeof( V_100 ) ) ;
V_100 . V_24 = V_97 ;
V_100 . V_23 = sizeof( * V_97 ) ;
F_80 ( V_101 ) ;
V_98 = F_81 ( V_95 , & V_100 ) ;
if ( V_98 < 0 ) {
F_80 ( V_102 ) ;
goto V_10;
}
F_82 () ;
if ( V_100 . V_103 < 0 )
V_98 = V_100 . V_103 ;
V_10:
return V_98 ;
}
static int
F_83 ( struct V_94 * V_95 , struct V_96 * V_97 )
{
int V_98 ;
do {
V_98 = F_79 ( V_95 , V_97 ) ;
} while ( V_98 == - V_104 );
return V_98 ;
}
static T_4
F_84 ( struct V_105 * V_106 , const char T_5 * V_107 , T_6 V_108 )
{
struct V_109 * V_73 , * V_110 ;
struct V_96 T_5 * V_97 = (struct V_96 T_5 * ) V_107 ;
T_7 V_111 ;
struct V_43 * V_44 = F_23 ( F_85 ( V_106 ) -> V_112 -> V_113 ,
V_45 ) ;
struct V_114 * V_115 = V_44 -> V_114 ;
if ( V_108 != sizeof( * V_97 ) ) {
F_9 ( L_24 , V_76 , V_108 ,
sizeof( * V_97 ) ) ;
return - V_88 ;
}
if ( F_86 ( & V_111 , & V_97 -> V_116 , sizeof( V_111 ) ) != 0 ) {
F_9 ( L_25 , V_76 ) ;
return - V_117 ;
}
V_110 = NULL ;
F_87 ( & V_115 -> V_118 ) ;
F_88 (tmp, &cn->cn_list, cu_list) {
if ( F_89 ( & V_73 -> V_119 . V_116 ) == V_111 ) {
V_110 = V_73 ;
F_90 ( & V_110 -> V_120 ) ;
break;
}
}
F_91 ( & V_115 -> V_118 ) ;
if ( ! V_110 ) {
F_9 ( L_26 , V_76 , V_111 ) ;
return - V_88 ;
}
if ( F_86 ( & V_110 -> V_119 , V_107 , V_108 ) != 0 )
return - V_117 ;
F_92 ( V_110 -> V_121 ) ;
return V_108 ;
}
static void
F_93 ( struct V_99 * V_100 )
{
struct V_96 * V_97 = V_100 -> V_24 ;
struct V_109 * V_110 = F_37 ( V_97 , struct V_109 ,
V_119 ) ;
if ( V_100 -> V_103 >= 0 )
return;
F_92 ( V_110 -> V_121 ) ;
}
static struct V_39 *
F_94 ( struct V_122 * V_123 , struct V_94 * V_95 )
{
struct V_39 * V_40 , * V_39 ;
V_40 = F_95 ( V_123 , V_124 ) ;
if ( V_40 == NULL )
return F_96 ( - V_35 ) ;
V_39 = F_97 ( V_40 , V_125 , NULL , V_95 ) ;
F_31 ( V_40 ) ;
return V_39 ;
}
static void
F_98 ( struct V_94 * V_95 )
{
if ( V_95 -> V_39 )
F_99 ( V_95 -> V_39 ) ;
}
static struct V_39 *
F_100 ( struct V_36 * V_36 , struct V_94 * V_95 )
{
struct V_122 * V_123 ;
struct V_39 * V_39 ;
V_123 = F_101 ( V_36 ) ;
if ( ! V_123 )
return NULL ;
V_39 = F_94 ( V_123 , V_95 ) ;
F_102 ( V_36 ) ;
return V_39 ;
}
static void
F_103 ( struct V_36 * V_36 , struct V_94 * V_95 )
{
struct V_122 * V_123 ;
V_123 = F_101 ( V_36 ) ;
if ( V_123 ) {
F_98 ( V_95 ) ;
F_102 ( V_36 ) ;
}
}
static int
F_104 ( struct V_36 * V_36 )
{
int V_98 ;
struct V_39 * V_39 ;
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
struct V_114 * V_115 ;
if ( V_44 -> V_114 )
return 0 ;
V_115 = F_105 ( sizeof( * V_115 ) , V_30 ) ;
if ( ! V_115 ) {
V_98 = - V_4 ;
goto V_89;
}
V_115 -> V_126 = F_106 ( & V_127 , V_128 ) ;
if ( F_11 ( V_115 -> V_126 ) ) {
V_98 = F_12 ( V_115 -> V_126 ) ;
goto V_89;
}
F_107 ( & V_115 -> V_118 ) ;
F_66 ( & V_115 -> V_129 ) ;
V_39 = F_100 ( V_36 , V_115 -> V_126 ) ;
if ( F_11 ( V_39 ) ) {
V_98 = F_12 ( V_39 ) ;
goto V_130;
}
V_115 -> V_126 -> V_39 = V_39 ;
V_44 -> V_114 = V_115 ;
return 0 ;
V_130:
F_108 ( V_115 -> V_126 ) ;
V_89:
F_17 ( V_115 ) ;
F_20 ( V_34 L_27 ,
V_98 ) ;
return V_98 ;
}
static void
F_109 ( struct V_36 * V_36 )
{
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
struct V_114 * V_115 = V_44 -> V_114 ;
F_103 ( V_36 , V_115 -> V_126 ) ;
F_108 ( V_115 -> V_126 ) ;
F_17 ( V_44 -> V_114 ) ;
V_44 -> V_114 = NULL ;
}
static struct V_109 *
F_110 ( struct V_114 * V_115 )
{
struct V_109 * V_3 , * V_73 ;
V_3 = F_105 ( sizeof( * V_3 ) , V_30 ) ;
if ( ! V_3 )
return V_3 ;
V_131:
F_87 ( & V_115 -> V_118 ) ;
F_88 (tmp, &cn->cn_list, cu_list) {
if ( V_73 -> V_119 . V_116 == V_115 -> V_132 ) {
V_115 -> V_132 ++ ;
F_91 ( & V_115 -> V_118 ) ;
goto V_131;
}
}
V_3 -> V_121 = V_133 ;
V_3 -> V_119 . V_134 = V_135 ;
F_111 ( V_115 -> V_132 ++ , & V_3 -> V_119 . V_116 ) ;
V_3 -> V_136 = V_115 ;
F_38 ( & V_3 -> V_120 , & V_115 -> V_129 ) ;
F_91 ( & V_115 -> V_118 ) ;
F_9 ( L_28 , V_76 , V_3 -> V_119 . V_116 ) ;
return V_3 ;
}
static void
F_112 ( struct V_109 * V_137 )
{
struct V_114 * V_115 = V_137 -> V_136 ;
F_87 ( & V_115 -> V_118 ) ;
F_45 ( & V_137 -> V_120 ) ;
F_91 ( & V_115 -> V_118 ) ;
F_17 ( V_137 ) ;
}
static void
F_113 ( struct V_32 * V_33 )
{
int V_98 ;
struct V_109 * V_110 ;
struct V_43 * V_44 = F_23 ( V_33 -> V_36 , V_45 ) ;
struct V_114 * V_115 = V_44 -> V_114 ;
if ( F_50 ( V_46 , & V_33 -> V_47 ) )
return;
V_110 = F_110 ( V_115 ) ;
if ( ! V_110 ) {
V_98 = - V_4 ;
goto V_138;
}
V_110 -> V_119 . V_139 = V_140 ;
V_110 -> V_119 . V_141 . V_142 . V_143 = V_33 -> V_49 . V_23 ;
memcpy ( V_110 -> V_119 . V_141 . V_142 . V_144 , V_33 -> V_49 . V_24 ,
V_33 -> V_49 . V_23 ) ;
V_98 = F_83 ( V_115 -> V_126 , & V_110 -> V_119 ) ;
if ( ! V_98 ) {
V_98 = V_110 -> V_119 . V_145 ;
F_78 ( V_46 , & V_33 -> V_47 ) ;
}
F_112 ( V_110 ) ;
V_138:
if ( V_98 )
F_20 ( V_34 L_29
L_30 , V_98 ) ;
}
static void
F_114 ( struct V_32 * V_33 )
{
int V_98 ;
struct V_109 * V_110 ;
struct V_43 * V_44 = F_23 ( V_33 -> V_36 , V_45 ) ;
struct V_114 * V_115 = V_44 -> V_114 ;
if ( ! F_50 ( V_46 , & V_33 -> V_47 ) )
return;
V_110 = F_110 ( V_115 ) ;
if ( ! V_110 ) {
V_98 = - V_4 ;
goto V_138;
}
V_110 -> V_119 . V_139 = V_146 ;
V_110 -> V_119 . V_141 . V_142 . V_143 = V_33 -> V_49 . V_23 ;
memcpy ( V_110 -> V_119 . V_141 . V_142 . V_144 , V_33 -> V_49 . V_24 ,
V_33 -> V_49 . V_23 ) ;
V_98 = F_83 ( V_115 -> V_126 , & V_110 -> V_119 ) ;
if ( ! V_98 ) {
V_98 = V_110 -> V_119 . V_145 ;
F_51 ( V_46 , & V_33 -> V_47 ) ;
}
F_112 ( V_110 ) ;
V_138:
if ( V_98 )
F_20 ( V_34 L_31
L_32 , V_98 ) ;
}
static int
F_115 ( struct V_32 * V_33 )
{
int V_98 ;
struct V_109 * V_110 ;
struct V_43 * V_44 = F_23 ( V_33 -> V_36 , V_45 ) ;
struct V_114 * V_115 = V_44 -> V_114 ;
if ( F_50 ( V_46 , & V_33 -> V_47 ) )
return 0 ;
V_110 = F_110 ( V_115 ) ;
if ( ! V_110 ) {
F_20 ( V_34 L_33
L_34 , - V_4 ) ;
return - V_4 ;
}
V_110 -> V_119 . V_139 = V_147 ;
V_110 -> V_119 . V_141 . V_142 . V_143 = V_33 -> V_49 . V_23 ;
memcpy ( V_110 -> V_119 . V_141 . V_142 . V_144 , V_33 -> V_49 . V_24 ,
V_33 -> V_49 . V_23 ) ;
V_98 = F_83 ( V_115 -> V_126 , & V_110 -> V_119 ) ;
if ( ! V_98 ) {
V_98 = V_110 -> V_119 . V_145 ;
F_78 ( V_46 , & V_33 -> V_47 ) ;
}
F_112 ( V_110 ) ;
return V_98 ;
}
static void
F_116 ( struct V_43 * V_44 )
{
int V_98 ;
struct V_109 * V_110 ;
struct V_114 * V_115 = V_44 -> V_114 ;
V_110 = F_110 ( V_115 ) ;
if ( ! V_110 ) {
V_98 = - V_4 ;
goto V_138;
}
V_110 -> V_119 . V_139 = V_148 ;
V_110 -> V_119 . V_141 . V_149 = ( V_150 ) V_44 -> V_151 ;
V_98 = F_83 ( V_115 -> V_126 , & V_110 -> V_119 ) ;
if ( ! V_98 )
V_98 = V_110 -> V_119 . V_145 ;
F_112 ( V_110 ) ;
V_138:
if ( V_98 )
F_20 ( V_34 L_35 , V_98 ) ;
}
static char *
F_117 ( void )
{
int V_152 ;
T_6 V_23 ;
char * V_153 ;
if ( V_154 )
return NULL ;
V_23 = strlen ( V_155 ) +
strlen ( F_76 () ) + 1 ;
V_153 = F_14 ( V_23 , V_30 ) ;
if ( ! V_153 )
return V_153 ;
V_152 = snprintf ( V_153 , V_23 , V_155 L_36 ,
F_76 () ) ;
if ( V_152 >= V_23 ) {
F_17 ( V_153 ) ;
return NULL ;
}
return V_153 ;
}
static char *
F_118 ( const struct V_15 * V_60 )
{
int V_152 ;
T_6 V_23 ;
char * V_153 ;
if ( V_154 )
return NULL ;
V_23 = strlen ( V_156 ) +
strlen ( F_76 () ) + 1 + V_38 ;
V_153 = F_14 ( V_23 , V_30 ) ;
if ( ! V_153 )
return V_153 ;
V_152 = snprintf ( V_153 , V_23 , V_156 L_37 ,
F_76 () ) ;
if ( V_152 > ( V_23 - V_38 ) ) {
F_17 ( V_153 ) ;
return NULL ;
}
V_152 = F_8 ( V_153 + V_152 , V_60 ) ;
if ( V_152 ) {
F_17 ( V_153 ) ;
return NULL ;
}
return V_153 ;
}
static char *
F_119 ( struct V_32 * V_33 )
{
int V_152 ;
T_6 V_23 ;
char * V_153 ;
V_23 = strlen ( V_157 ) + 1 + 1 ;
V_153 = F_14 ( V_23 , V_30 ) ;
if ( ! V_153 )
return V_153 ;
V_152 = snprintf ( V_153 , V_23 , V_157 L_38 ,
V_33 -> V_158 ? 'Y' : 'N' ) ;
if ( V_152 >= V_23 ) {
F_17 ( V_153 ) ;
return NULL ;
}
return V_153 ;
}
static char *
F_120 ( T_8 V_159 )
{
int V_152 ;
T_6 V_23 ;
char * V_153 ;
V_23 = strlen ( V_160 ) + 22 + 1 ;
V_153 = F_14 ( V_23 , V_30 ) ;
if ( ! V_153 )
return V_153 ;
V_152 = snprintf ( V_153 , V_23 , V_160 L_39 ,
V_159 ) ;
if ( V_152 >= V_23 ) {
F_17 ( V_153 ) ;
return NULL ;
}
return V_153 ;
}
static int
F_121 ( char * V_161 , char * V_162 , char * V_163 , char * V_164 )
{
char * V_165 [ 3 ] ;
char * V_166 [ 4 ] ;
int V_98 ;
if ( F_122 ( ! V_167 [ 0 ] ) ) {
F_9 ( L_40 , V_76 ) ;
return - V_168 ;
}
F_9 ( L_41 , V_76 , V_161 ) ;
F_9 ( L_42 , V_76 , V_162 ? V_162 : L_43 ) ;
F_9 ( L_44 , V_76 , V_163 ? V_163 : L_43 ) ;
F_9 ( L_45 , V_76 , V_164 ? V_164 : L_43 ) ;
V_165 [ 0 ] = V_163 ;
V_165 [ 1 ] = V_164 ;
V_165 [ 2 ] = NULL ;
V_166 [ 0 ] = ( char * ) V_167 ;
V_166 [ 1 ] = V_161 ;
V_166 [ 2 ] = V_162 ;
V_166 [ 3 ] = NULL ;
V_98 = F_123 ( V_166 [ 0 ] , V_166 , V_165 , V_169 ) ;
if ( V_98 == - V_35 || V_98 == - V_168 ) {
F_9 ( L_46
L_47 ,
V_167 , V_98 ) ;
V_167 [ 0 ] = '\0' ;
}
F_9 ( L_48 , V_76 , V_167 , V_98 ) ;
return V_98 ;
}
static char *
F_124 ( const unsigned char * V_107 , int V_170 )
{
int V_12 ;
char * V_171 , * V_172 ;
V_171 = F_14 ( ( V_170 * 2 ) + 1 , V_30 ) ;
if ( ! V_171 )
return V_171 ;
V_172 = V_171 ;
for ( V_12 = 0 ; V_12 < V_170 ; V_12 ++ ) {
sprintf ( V_172 , L_49 , * V_107 ++ ) ;
V_172 += 2 ;
}
return V_171 ;
}
static int
F_125 ( struct V_36 * V_36 )
{
int V_98 ;
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
char * V_159 = F_120 ( V_44 -> V_151 ) ;
if ( V_36 != & V_87 ) {
F_70 ( L_50 ) ;
return - V_88 ;
}
V_98 = F_121 ( L_51 , NULL , V_159 , NULL ) ;
F_17 ( V_159 ) ;
return V_98 ;
}
static void
F_126 ( struct V_32 * V_33 )
{
F_127 ( & V_33 -> V_47 , V_173 ,
V_101 ) ;
}
static void
F_128 ( struct V_32 * V_33 )
{
F_129 () ;
F_51 ( V_173 , & V_33 -> V_47 ) ;
F_130 () ;
F_131 ( & V_33 -> V_47 , V_173 ) ;
}
static void
F_132 ( struct V_32 * V_33 )
{
char * V_174 , * V_175 , * V_159 ;
struct V_43 * V_44 = F_23 ( V_33 -> V_36 , V_45 ) ;
if ( V_33 -> V_158 == 0 &&
F_50 ( V_46 , & V_33 -> V_47 ) )
return;
V_174 = F_124 ( V_33 -> V_49 . V_24 , V_33 -> V_49 . V_23 ) ;
if ( ! V_174 ) {
F_9 ( L_52 , V_76 ) ;
return;
}
V_175 = F_119 ( V_33 ) ;
V_159 = F_120 ( V_44 -> V_151 ) ;
F_126 ( V_33 ) ;
if ( ! F_121 ( L_53 , V_174 , V_175 , V_159 ) )
F_78 ( V_46 , & V_33 -> V_47 ) ;
F_128 ( V_33 ) ;
F_17 ( V_175 ) ;
F_17 ( V_159 ) ;
F_17 ( V_174 ) ;
}
static void
F_133 ( struct V_32 * V_33 )
{
char * V_174 ;
if ( ! F_50 ( V_46 , & V_33 -> V_47 ) )
return;
V_174 = F_124 ( V_33 -> V_49 . V_24 , V_33 -> V_49 . V_23 ) ;
if ( ! V_174 ) {
F_9 ( L_52 , V_76 ) ;
return;
}
F_126 ( V_33 ) ;
if ( F_50 ( V_46 , & V_33 -> V_47 ) &&
F_121 ( L_54 , V_174 , NULL , NULL ) == 0 )
F_51 ( V_46 , & V_33 -> V_47 ) ;
F_128 ( V_33 ) ;
F_17 ( V_174 ) ;
}
static int
F_134 ( struct V_32 * V_33 )
{
int V_98 ;
char * V_174 , * V_175 , * V_176 ;
if ( F_50 ( V_46 , & V_33 -> V_47 ) )
return 0 ;
V_174 = F_124 ( V_33 -> V_49 . V_24 , V_33 -> V_49 . V_23 ) ;
if ( ! V_174 ) {
F_9 ( L_52 , V_76 ) ;
return - V_4 ;
}
V_175 = F_119 ( V_33 ) ;
V_176 = F_118 ( & V_33 -> V_49 ) ;
F_126 ( V_33 ) ;
if ( F_50 ( V_46 , & V_33 -> V_47 ) ) {
V_98 = 0 ;
} else {
V_98 = F_121 ( L_55 , V_174 , V_175 , V_176 ) ;
if ( V_98 == 0 )
F_78 ( V_46 , & V_33 -> V_47 ) ;
}
F_128 ( V_33 ) ;
F_17 ( V_175 ) ;
F_17 ( V_176 ) ;
F_17 ( V_174 ) ;
return V_98 ;
}
static void
F_135 ( struct V_43 * V_44 )
{
char * V_176 ;
char V_177 [ 22 ] ;
sprintf ( V_177 , L_39 , V_44 -> V_151 ) ;
V_176 = F_117 () ;
F_121 ( L_56 , V_177 , V_176 , NULL ) ;
F_17 ( V_176 ) ;
}
int
F_136 ( struct V_36 * V_36 )
{
int V_22 ;
struct V_91 V_91 ;
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
if ( V_44 -> V_178 )
goto V_179;
V_44 -> V_178 = & V_180 ;
V_22 = V_44 -> V_178 -> V_181 ( V_36 ) ;
if ( ! V_22 )
return V_22 ;
V_44 -> V_178 = & V_182 ;
V_22 = F_73 ( F_76 () , V_92 , & V_91 ) ;
if ( ! V_22 ) {
V_22 = F_74 ( V_91 . V_39 ) ;
F_75 ( & V_91 ) ;
if ( V_22 )
goto V_179;
}
V_44 -> V_178 = & V_183 ;
F_20 ( V_184 L_57
L_58
L_59 ) ;
V_179:
V_22 = V_44 -> V_178 -> V_181 ( V_36 ) ;
if ( V_22 ) {
F_20 ( V_184 L_60
L_61 , V_22 ) ;
V_44 -> V_178 = NULL ;
}
return V_22 ;
}
void
F_21 ( struct V_36 * V_36 )
{
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
if ( V_44 -> V_178 ) {
if ( V_44 -> V_178 -> exit )
V_44 -> V_178 -> exit ( V_36 ) ;
V_44 -> V_178 = NULL ;
}
}
void
F_137 ( struct V_32 * V_33 )
{
struct V_43 * V_44 = F_23 ( V_33 -> V_36 , V_45 ) ;
if ( V_44 -> V_178 )
V_44 -> V_178 -> V_185 ( V_33 ) ;
}
void
F_138 ( struct V_32 * V_33 )
{
struct V_43 * V_44 = F_23 ( V_33 -> V_36 , V_45 ) ;
if ( V_44 -> V_178 )
V_44 -> V_178 -> remove ( V_33 ) ;
}
int
F_139 ( struct V_32 * V_33 )
{
struct V_43 * V_44 = F_23 ( V_33 -> V_36 , V_45 ) ;
if ( V_44 -> V_178 )
return V_44 -> V_178 -> V_186 ( V_33 ) ;
return - V_187 ;
}
void
F_140 ( struct V_43 * V_44 )
{
if ( V_44 -> V_178 )
V_44 -> V_178 -> V_188 ( V_44 ) ;
}
static int
F_141 ( struct V_189 * V_190 , unsigned long V_191 , void * V_192 )
{
struct V_122 * V_123 = V_192 ;
struct V_36 * V_36 = V_123 -> V_113 ;
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
struct V_114 * V_115 = V_44 -> V_114 ;
struct V_39 * V_39 ;
int V_98 = 0 ;
if ( ! F_142 ( V_193 ) )
return 0 ;
if ( ! V_115 ) {
F_143 ( V_193 ) ;
return 0 ;
}
switch ( V_191 ) {
case V_194 :
V_39 = F_94 ( V_123 , V_115 -> V_126 ) ;
if ( F_11 ( V_39 ) ) {
V_98 = F_12 ( V_39 ) ;
break;
}
V_115 -> V_126 -> V_39 = V_39 ;
break;
case V_195 :
if ( V_115 -> V_126 -> V_39 )
F_98 ( V_115 -> V_126 ) ;
break;
default:
V_98 = - V_196 ;
break;
}
F_143 ( V_193 ) ;
return V_98 ;
}
int
F_144 ( void )
{
return F_145 ( & V_197 ) ;
}
void
F_146 ( void )
{
F_147 ( & V_197 ) ;
}
