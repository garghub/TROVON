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
F_9 ( L_7 , V_14 ) ;
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
return;
V_40 = V_44 -> V_48 -> V_50 . V_39 ;
F_26 ( & V_40 -> V_51 -> V_52 ) ;
V_39 = F_27 ( V_14 , V_40 , V_38 - 1 ) ;
if ( F_11 ( V_39 ) ) {
V_22 = F_12 ( V_39 ) ;
goto V_53;
}
if ( V_39 -> V_51 )
goto V_54;
V_22 = F_28 ( V_40 -> V_51 , V_39 , V_55 ) ;
V_54:
F_29 ( V_39 ) ;
V_53:
F_30 ( & V_40 -> V_51 -> V_52 ) ;
if ( V_22 == 0 ) {
if ( V_44 -> V_56 ) {
V_42 = F_31 ( V_14 , V_44 ) ;
if ( V_42 )
V_42 -> V_57 = V_33 ;
}
F_32 ( V_44 -> V_48 , 0 ) ;
} else {
F_20 ( V_34 L_8
L_9
L_10 , V_22 ,
V_58 ) ;
}
F_33 ( V_44 -> V_48 ) ;
F_5 ( V_37 ) ;
}
static int
F_34 ( void * V_59 , const char * V_60 , int V_61 ,
T_1 V_62 , T_2 V_63 , unsigned int V_64 )
{
struct V_65 * V_66 = V_59 ;
struct V_67 * V_68 ;
if ( V_61 != V_38 - 1 )
return 0 ;
V_68 = F_14 ( sizeof( struct V_67 ) , V_30 ) ;
if ( V_68 == NULL )
return - V_4 ;
memcpy ( V_68 -> V_60 , V_60 , V_38 - 1 ) ;
V_68 -> V_60 [ V_38 - 1 ] = '\0' ;
F_35 ( & V_68 -> V_69 , & V_66 -> V_70 ) ;
return 0 ;
}
static int
F_36 ( T_3 * V_71 , struct V_43 * V_44 )
{
const struct V_1 * V_37 ;
struct V_39 * V_40 = V_44 -> V_48 -> V_50 . V_39 ;
struct V_65 V_66 = {
. V_66 . V_72 = F_34 ,
. V_70 = F_37 (ctx.names)
} ;
int V_22 ;
V_22 = F_1 ( & V_37 ) ;
if ( V_22 < 0 )
return V_22 ;
V_22 = F_38 ( V_44 -> V_48 , 0 , V_73 ) ;
if ( V_22 < 0 ) {
F_5 ( V_37 ) ;
return V_22 ;
}
V_22 = F_39 ( V_44 -> V_48 , & V_66 . V_66 ) ;
F_40 ( & V_40 -> V_51 -> V_52 , V_74 ) ;
while ( ! F_41 ( & V_66 . V_70 ) ) {
struct V_67 * V_68 ;
V_68 = F_42 ( V_66 . V_70 . V_75 , struct V_67 , V_69 ) ;
if ( ! V_22 ) {
struct V_39 * V_39 ;
V_39 = F_27 ( V_68 -> V_60 , V_40 , V_38 - 1 ) ;
if ( F_11 ( V_39 ) ) {
V_22 = F_12 ( V_39 ) ;
break;
}
V_22 = V_71 ( V_40 , V_39 , V_44 ) ;
F_29 ( V_39 ) ;
}
F_43 ( & V_68 -> V_69 ) ;
F_17 ( V_68 ) ;
}
F_30 ( & V_40 -> V_51 -> V_52 ) ;
F_5 ( V_37 ) ;
return V_22 ;
}
static int
F_44 ( char * V_60 , int V_61 , struct V_43 * V_44 )
{
struct V_39 * V_40 , * V_39 ;
int V_22 ;
F_9 ( L_11 , V_61 , V_60 ) ;
V_40 = V_44 -> V_48 -> V_50 . V_39 ;
F_40 ( & V_40 -> V_51 -> V_52 , V_74 ) ;
V_39 = F_27 ( V_60 , V_40 , V_61 ) ;
if ( F_11 ( V_39 ) ) {
V_22 = F_12 ( V_39 ) ;
goto V_53;
}
V_22 = - V_35 ;
if ( ! V_39 -> V_51 )
goto V_10;
V_22 = F_45 ( V_40 -> V_51 , V_39 ) ;
V_10:
F_29 ( V_39 ) ;
V_53:
F_30 ( & V_40 -> V_51 -> V_52 ) ;
return V_22 ;
}
static void
F_46 ( struct V_32 * V_33 )
{
const struct V_1 * V_37 ;
struct V_41 * V_42 ;
char V_14 [ V_38 ] ;
int V_22 ;
struct V_43 * V_44 = F_23 ( V_33 -> V_36 , V_45 ) ;
if ( ! V_44 -> V_48 || ! F_47 ( V_46 , & V_33 -> V_47 ) )
return;
V_22 = F_8 ( V_14 , & V_33 -> V_49 ) ;
if ( V_22 )
return F_19 ( V_33 , V_22 ) ;
V_22 = F_25 ( V_44 -> V_48 ) ;
if ( V_22 )
goto V_10;
F_48 ( V_46 , & V_33 -> V_47 ) ;
V_22 = F_1 ( & V_37 ) ;
if ( V_22 < 0 )
goto V_76;
V_22 = F_44 ( V_14 , V_38 - 1 , V_44 ) ;
F_5 ( V_37 ) ;
if ( V_22 == 0 ) {
F_32 ( V_44 -> V_48 , 0 ) ;
if ( V_44 -> V_56 ) {
V_42 = F_49 ( V_14 , V_44 ) ;
if ( V_42 )
F_50 ( V_42 , V_44 ) ;
}
}
V_76:
F_33 ( V_44 -> V_48 ) ;
V_10:
if ( V_22 )
F_20 ( L_12
L_13 , V_38 , V_14 ) ;
}
static int
F_51 ( struct V_39 * V_77 , struct V_39 * V_78 , struct V_43 * V_44 )
{
int V_22 ;
if ( F_52 ( V_78 -> V_79 . V_60 , V_44 ) )
return 0 ;
V_22 = F_45 ( V_77 -> V_51 , V_78 ) ;
if ( V_22 )
F_20 ( L_14 ,
V_78 -> V_79 . V_60 ) ;
return 0 ;
}
static void
F_53 ( struct V_43 * V_44 , T_4 V_80 )
{
int V_22 ;
V_44 -> V_56 = false ;
if ( ! V_44 -> V_48 )
return;
V_22 = F_25 ( V_44 -> V_48 ) ;
if ( V_22 )
goto V_10;
V_22 = F_36 ( F_51 , V_44 ) ;
if ( V_22 == 0 )
F_32 ( V_44 -> V_48 , 0 ) ;
F_33 ( V_44 -> V_48 ) ;
V_10:
F_54 ( V_44 ) ;
if ( V_22 )
F_20 ( L_15
L_16 , V_44 -> V_48 -> V_50 . V_39 -> V_79 . V_60 ) ;
}
static int
F_55 ( struct V_39 * V_77 , struct V_39 * V_78 , struct V_43 * V_44 )
{
if ( V_78 -> V_79 . V_23 != V_38 - 1 ) {
F_20 ( L_17 ,
V_78 -> V_79 . V_60 ) ;
return 0 ;
}
F_31 ( V_78 -> V_79 . V_60 , V_44 ) ;
return 0 ;
}
static int
F_56 ( struct V_36 * V_36 ) {
int V_22 ;
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
if ( ! V_44 -> V_48 )
return 0 ;
V_22 = F_36 ( F_55 , V_44 ) ;
if ( V_22 )
F_20 ( L_18
L_16 , V_44 -> V_48 -> V_50 . V_39 -> V_79 . V_60 ) ;
return V_22 ;
}
static int
F_57 ( struct V_36 * V_36 )
{
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
const struct V_1 * V_37 ;
int V_22 ;
F_20 ( L_19 ,
V_58 ) ;
F_58 ( V_44 -> V_48 ) ;
V_22 = F_1 ( & V_37 ) ;
if ( V_22 < 0 ) {
F_20 ( L_20
L_21 ,
V_22 ) ;
return V_22 ;
}
V_44 -> V_48 = F_59 ( V_58 , V_81 | V_82 , 0 ) ;
if ( F_11 ( V_44 -> V_48 ) ) {
F_20 ( L_22 ,
V_58 ) ;
V_22 = F_12 ( V_44 -> V_48 ) ;
V_44 -> V_48 = NULL ;
}
F_5 ( V_37 ) ;
if ( ! V_22 )
V_44 -> V_56 = true ;
return V_22 ;
}
static int
F_60 ( struct V_36 * V_36 )
{
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
int V_12 ;
V_44 -> V_83 = F_14 ( sizeof( struct V_84 ) *
V_85 , V_30 ) ;
if ( ! V_44 -> V_83 )
return - V_4 ;
for ( V_12 = 0 ; V_12 < V_85 ; V_12 ++ )
F_61 ( & V_44 -> V_83 [ V_12 ] ) ;
V_44 -> V_86 = 0 ;
return 0 ;
}
static void
F_62 ( struct V_36 * V_36 )
{
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
F_17 ( V_44 -> V_83 ) ;
}
static int
F_63 ( struct V_36 * V_36 )
{
int V_22 ;
V_22 = F_57 ( V_36 ) ;
if ( ! V_22 )
V_22 = F_56 ( V_36 ) ;
if ( V_22 )
F_20 ( V_34 L_23 ) ;
return V_22 ;
}
static int
F_64 ( struct V_36 * V_36 )
{
int V_22 ;
if ( V_36 != & V_87 ) {
F_65 ( 1 , V_34 L_24
L_25 ) ;
return - V_88 ;
}
V_22 = F_60 ( V_36 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_63 ( V_36 ) ;
if ( V_22 )
goto V_89;
return 0 ;
V_89:
F_62 ( V_36 ) ;
return V_22 ;
}
static void
F_66 ( struct V_43 * V_44 )
{
if ( ! V_44 -> V_48 )
return;
F_67 ( V_44 -> V_48 ) ;
V_44 -> V_48 = NULL ;
}
static void
F_68 ( struct V_36 * V_36 )
{
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
F_54 ( V_44 ) ;
F_66 ( V_44 ) ;
F_62 ( V_36 ) ;
}
int
F_69 ( char * V_90 )
{
int V_22 ;
struct V_91 V_91 ;
V_22 = F_70 ( V_90 , V_92 , & V_91 ) ;
if ( V_22 )
return V_22 ;
V_22 = - V_93 ;
if ( F_71 ( V_91 . V_39 -> V_51 -> V_94 ) ) {
strcpy ( V_58 , V_90 ) ;
V_22 = 0 ;
}
F_72 ( & V_91 ) ;
return V_22 ;
}
char *
F_73 ( void )
{
return V_58 ;
}
static int
F_74 ( struct V_32 * V_33 )
{
int V_22 ;
char V_14 [ V_38 ] ;
struct V_41 * V_42 ;
struct V_43 * V_44 = F_23 ( V_33 -> V_36 , V_45 ) ;
if ( F_47 ( V_46 , & V_33 -> V_47 ) )
return 0 ;
V_22 = F_8 ( V_14 , & V_33 -> V_49 ) ;
if ( V_22 ) {
F_19 ( V_33 , V_22 ) ;
return V_22 ;
}
V_42 = F_49 ( V_14 , V_44 ) ;
if ( V_42 ) {
F_75 ( V_46 , & V_33 -> V_47 ) ;
V_42 -> V_57 = V_33 ;
return 0 ;
}
return - V_35 ;
}
static int
F_76 ( struct V_95 * V_96 , struct V_97 * V_98 )
{
int V_99 ;
struct V_100 V_101 ;
memset ( & V_101 , 0 , sizeof( V_101 ) ) ;
V_101 . V_24 = V_98 ;
V_101 . V_23 = sizeof( * V_98 ) ;
F_77 ( V_102 ) ;
V_99 = F_78 ( V_96 , & V_101 ) ;
if ( V_99 < 0 ) {
F_77 ( V_103 ) ;
goto V_10;
}
F_79 () ;
F_77 ( V_103 ) ;
if ( V_101 . V_104 < 0 )
V_99 = V_101 . V_104 ;
V_10:
return V_99 ;
}
static int
F_80 ( struct V_95 * V_96 , struct V_97 * V_98 )
{
int V_99 ;
do {
V_99 = F_76 ( V_96 , V_98 ) ;
} while ( V_99 == - V_105 );
return V_99 ;
}
static T_5
F_81 ( struct V_106 * V_107 , const char T_6 * V_108 , T_7 V_109 )
{
struct V_110 * V_111 , * V_112 ;
struct V_97 T_6 * V_98 = (struct V_97 T_6 * ) V_108 ;
T_8 V_113 ;
struct V_43 * V_44 = F_23 ( V_107 -> V_114 -> V_115 -> V_116 ,
V_45 ) ;
struct V_117 * V_118 = V_44 -> V_117 ;
if ( V_109 != sizeof( * V_98 ) ) {
F_9 ( L_26 , V_119 , V_109 ,
sizeof( * V_98 ) ) ;
return - V_88 ;
}
if ( F_82 ( & V_113 , & V_98 -> V_120 , sizeof( V_113 ) ) != 0 ) {
F_9 ( L_27 , V_119 ) ;
return - V_121 ;
}
V_112 = NULL ;
F_83 ( & V_118 -> V_122 ) ;
F_84 (tmp, &cn->cn_list, cu_list) {
if ( F_85 ( & V_111 -> V_123 . V_120 ) == V_113 ) {
V_112 = V_111 ;
F_86 ( & V_112 -> V_124 ) ;
break;
}
}
F_87 ( & V_118 -> V_122 ) ;
if ( ! V_112 ) {
F_9 ( L_28 , V_119 , V_113 ) ;
return - V_88 ;
}
if ( F_82 ( & V_112 -> V_123 , V_108 , V_109 ) != 0 )
return - V_121 ;
F_88 ( V_112 -> V_125 ) ;
return V_109 ;
}
static void
F_89 ( struct V_100 * V_101 )
{
struct V_97 * V_98 = V_101 -> V_24 ;
struct V_110 * V_112 = F_90 ( V_98 , struct V_110 ,
V_123 ) ;
if ( V_101 -> V_104 >= 0 )
return;
F_88 ( V_112 -> V_125 ) ;
}
static struct V_39 *
F_91 ( struct V_126 * V_127 , struct V_95 * V_96 )
{
struct V_39 * V_40 , * V_39 ;
V_40 = F_92 ( V_127 , V_128 ) ;
if ( V_40 == NULL )
return F_93 ( - V_35 ) ;
V_39 = F_94 ( V_40 , V_129 , NULL , V_96 ) ;
F_29 ( V_40 ) ;
return V_39 ;
}
static void
F_95 ( struct V_95 * V_96 )
{
if ( V_96 -> V_39 )
F_96 ( V_96 -> V_39 ) ;
}
static struct V_39 *
F_97 ( struct V_36 * V_36 , struct V_95 * V_96 )
{
struct V_126 * V_127 ;
struct V_39 * V_39 ;
V_127 = F_98 ( V_36 ) ;
if ( ! V_127 )
return NULL ;
V_39 = F_91 ( V_127 , V_96 ) ;
F_99 ( V_36 ) ;
return V_39 ;
}
static void
F_100 ( struct V_36 * V_36 , struct V_95 * V_96 )
{
struct V_126 * V_127 ;
V_127 = F_98 ( V_36 ) ;
if ( V_127 ) {
F_95 ( V_96 ) ;
F_99 ( V_36 ) ;
}
}
static int
F_101 ( struct V_36 * V_36 )
{
int V_99 ;
struct V_39 * V_39 ;
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
struct V_117 * V_118 ;
if ( V_44 -> V_117 )
return 0 ;
V_118 = F_102 ( sizeof( * V_118 ) , V_30 ) ;
if ( ! V_118 ) {
V_99 = - V_4 ;
goto V_89;
}
V_118 -> V_130 = F_103 ( & V_131 , V_132 ) ;
if ( F_11 ( V_118 -> V_130 ) ) {
V_99 = F_12 ( V_118 -> V_130 ) ;
goto V_89;
}
F_104 ( & V_118 -> V_122 ) ;
F_61 ( & V_118 -> V_133 ) ;
V_39 = F_97 ( V_36 , V_118 -> V_130 ) ;
if ( F_11 ( V_39 ) ) {
V_99 = F_12 ( V_39 ) ;
goto V_134;
}
V_118 -> V_130 -> V_39 = V_39 ;
V_44 -> V_117 = V_118 ;
return 0 ;
V_134:
F_105 ( V_118 -> V_130 ) ;
V_89:
F_17 ( V_118 ) ;
F_20 ( V_34 L_29 ,
V_99 ) ;
return V_99 ;
}
static void
F_106 ( struct V_36 * V_36 )
{
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
struct V_117 * V_118 = V_44 -> V_117 ;
F_100 ( V_36 , V_118 -> V_130 ) ;
F_105 ( V_118 -> V_130 ) ;
F_17 ( V_44 -> V_117 ) ;
V_44 -> V_117 = NULL ;
}
static struct V_110 *
F_107 ( struct V_117 * V_118 )
{
struct V_110 * V_3 , * V_111 ;
V_3 = F_102 ( sizeof( * V_3 ) , V_30 ) ;
if ( ! V_3 )
return V_3 ;
V_135:
F_83 ( & V_118 -> V_122 ) ;
F_84 (tmp, &cn->cn_list, cu_list) {
if ( V_111 -> V_123 . V_120 == V_118 -> V_136 ) {
V_118 -> V_136 ++ ;
F_87 ( & V_118 -> V_122 ) ;
goto V_135;
}
}
V_3 -> V_125 = V_137 ;
V_3 -> V_123 . V_138 = V_139 ;
F_108 ( V_118 -> V_136 ++ , & V_3 -> V_123 . V_120 ) ;
V_3 -> V_140 = V_118 ;
F_35 ( & V_3 -> V_124 , & V_118 -> V_133 ) ;
F_87 ( & V_118 -> V_122 ) ;
F_9 ( L_30 , V_119 , V_3 -> V_123 . V_120 ) ;
return V_3 ;
}
static void
F_109 ( struct V_110 * V_141 )
{
struct V_117 * V_118 = V_141 -> V_140 ;
F_83 ( & V_118 -> V_122 ) ;
F_43 ( & V_141 -> V_124 ) ;
F_87 ( & V_118 -> V_122 ) ;
F_17 ( V_141 ) ;
}
static void
F_110 ( struct V_32 * V_33 )
{
int V_99 ;
struct V_110 * V_112 ;
struct V_43 * V_44 = F_23 ( V_33 -> V_36 , V_45 ) ;
struct V_117 * V_118 = V_44 -> V_117 ;
if ( F_47 ( V_46 , & V_33 -> V_47 ) )
return;
V_112 = F_107 ( V_118 ) ;
if ( ! V_112 ) {
V_99 = - V_4 ;
goto V_142;
}
V_112 -> V_123 . V_143 = V_144 ;
V_112 -> V_123 . V_145 . V_146 . V_147 = V_33 -> V_49 . V_23 ;
memcpy ( V_112 -> V_123 . V_145 . V_146 . V_148 , V_33 -> V_49 . V_24 ,
V_33 -> V_49 . V_23 ) ;
V_99 = F_80 ( V_118 -> V_130 , & V_112 -> V_123 ) ;
if ( ! V_99 ) {
V_99 = V_112 -> V_123 . V_149 ;
F_75 ( V_46 , & V_33 -> V_47 ) ;
}
F_109 ( V_112 ) ;
V_142:
if ( V_99 )
F_20 ( V_34 L_31
L_32 , V_99 ) ;
}
static void
F_111 ( struct V_32 * V_33 )
{
int V_99 ;
struct V_110 * V_112 ;
struct V_43 * V_44 = F_23 ( V_33 -> V_36 , V_45 ) ;
struct V_117 * V_118 = V_44 -> V_117 ;
if ( ! F_47 ( V_46 , & V_33 -> V_47 ) )
return;
V_112 = F_107 ( V_118 ) ;
if ( ! V_112 ) {
V_99 = - V_4 ;
goto V_142;
}
V_112 -> V_123 . V_143 = V_150 ;
V_112 -> V_123 . V_145 . V_146 . V_147 = V_33 -> V_49 . V_23 ;
memcpy ( V_112 -> V_123 . V_145 . V_146 . V_148 , V_33 -> V_49 . V_24 ,
V_33 -> V_49 . V_23 ) ;
V_99 = F_80 ( V_118 -> V_130 , & V_112 -> V_123 ) ;
if ( ! V_99 ) {
V_99 = V_112 -> V_123 . V_149 ;
F_48 ( V_46 , & V_33 -> V_47 ) ;
}
F_109 ( V_112 ) ;
V_142:
if ( V_99 )
F_20 ( V_34 L_33
L_34 , V_99 ) ;
}
static int
F_112 ( struct V_32 * V_33 )
{
int V_99 ;
struct V_110 * V_112 ;
struct V_43 * V_44 = F_23 ( V_33 -> V_36 , V_45 ) ;
struct V_117 * V_118 = V_44 -> V_117 ;
if ( F_47 ( V_46 , & V_33 -> V_47 ) )
return 0 ;
V_112 = F_107 ( V_118 ) ;
if ( ! V_112 ) {
F_20 ( V_34 L_35
L_36 , - V_4 ) ;
return - V_4 ;
}
V_112 -> V_123 . V_143 = V_151 ;
V_112 -> V_123 . V_145 . V_146 . V_147 = V_33 -> V_49 . V_23 ;
memcpy ( V_112 -> V_123 . V_145 . V_146 . V_148 , V_33 -> V_49 . V_24 ,
V_33 -> V_49 . V_23 ) ;
V_99 = F_80 ( V_118 -> V_130 , & V_112 -> V_123 ) ;
if ( ! V_99 ) {
V_99 = V_112 -> V_123 . V_149 ;
F_75 ( V_46 , & V_33 -> V_47 ) ;
}
F_109 ( V_112 ) ;
return V_99 ;
}
static void
F_113 ( struct V_43 * V_44 , T_4 V_80 )
{
int V_99 ;
struct V_110 * V_112 ;
struct V_117 * V_118 = V_44 -> V_117 ;
V_112 = F_107 ( V_118 ) ;
if ( ! V_112 ) {
V_99 = - V_4 ;
goto V_142;
}
V_112 -> V_123 . V_143 = V_152 ;
V_112 -> V_123 . V_145 . V_153 = ( V_154 ) V_80 ;
V_99 = F_80 ( V_118 -> V_130 , & V_112 -> V_123 ) ;
if ( ! V_99 )
V_99 = V_112 -> V_123 . V_149 ;
F_109 ( V_112 ) ;
V_142:
if ( V_99 )
F_20 ( V_34 L_37 , V_99 ) ;
}
static char *
F_114 ( void )
{
int V_155 ;
T_7 V_23 ;
char * V_156 ;
if ( V_157 )
return NULL ;
V_23 = strlen ( V_158 ) +
strlen ( F_73 () ) + 1 ;
V_156 = F_14 ( V_23 , V_30 ) ;
if ( ! V_156 )
return V_156 ;
V_155 = snprintf ( V_156 , V_23 , V_158 L_38 ,
F_73 () ) ;
if ( V_155 >= V_23 ) {
F_17 ( V_156 ) ;
return NULL ;
}
return V_156 ;
}
static char *
F_115 ( const struct V_15 * V_60 )
{
int V_155 ;
T_7 V_23 ;
char * V_156 ;
if ( V_157 )
return NULL ;
V_23 = strlen ( V_159 ) +
strlen ( F_73 () ) + 1 + V_38 ;
V_156 = F_14 ( V_23 , V_30 ) ;
if ( ! V_156 )
return V_156 ;
V_155 = snprintf ( V_156 , V_23 , V_159 L_39 ,
F_73 () ) ;
if ( V_155 > ( V_23 - V_38 ) ) {
F_17 ( V_156 ) ;
return NULL ;
}
V_155 = F_8 ( V_156 + V_155 , V_60 ) ;
if ( V_155 ) {
F_17 ( V_156 ) ;
return NULL ;
}
return V_156 ;
}
static int
F_116 ( char * V_160 , char * V_59 , char * V_161 )
{
char * V_162 [ 2 ] ;
char * V_163 [ 4 ] ;
int V_99 ;
if ( F_117 ( ! V_164 [ 0 ] ) ) {
F_9 ( L_40 , V_119 ) ;
return - V_165 ;
}
F_9 ( L_41 , V_119 , V_160 ) ;
F_9 ( L_42 , V_119 , V_59 ? V_59 : L_43 ) ;
F_9 ( L_44 , V_119 , V_161 ? V_161 : L_43 ) ;
V_162 [ 0 ] = V_161 ;
V_162 [ 1 ] = NULL ;
V_163 [ 0 ] = ( char * ) V_164 ;
V_163 [ 1 ] = V_160 ;
V_163 [ 2 ] = V_59 ;
V_163 [ 3 ] = NULL ;
V_99 = F_118 ( V_163 [ 0 ] , V_163 , V_162 , V_166 ) ;
if ( V_99 == - V_35 || V_99 == - V_165 ) {
F_9 ( L_45
L_46 ,
V_164 , V_99 ) ;
V_164 [ 0 ] = '\0' ;
}
F_9 ( L_47 , V_119 , V_164 , V_99 ) ;
return V_99 ;
}
static char *
F_119 ( const unsigned char * V_108 , int V_167 )
{
int V_12 ;
char * V_168 , * V_169 ;
V_168 = F_14 ( ( V_167 * 2 ) + 1 , V_30 ) ;
if ( ! V_168 )
return V_168 ;
V_169 = V_168 ;
for ( V_12 = 0 ; V_12 < V_167 ; V_12 ++ ) {
sprintf ( V_169 , L_48 , * V_108 ++ ) ;
V_169 += 2 ;
}
return V_168 ;
}
static void
F_120 ( struct V_32 * V_33 )
{
char * V_170 ;
V_170 = F_119 ( V_33 -> V_49 . V_24 , V_33 -> V_49 . V_23 ) ;
if ( ! V_170 ) {
F_9 ( L_49 , V_119 ) ;
return;
}
F_116 ( L_50 , V_170 , NULL ) ;
F_17 ( V_170 ) ;
}
static void
F_121 ( struct V_32 * V_33 )
{
char * V_170 ;
V_170 = F_119 ( V_33 -> V_49 . V_24 , V_33 -> V_49 . V_23 ) ;
if ( ! V_170 ) {
F_9 ( L_49 , V_119 ) ;
return;
}
F_116 ( L_51 , V_170 , NULL ) ;
F_17 ( V_170 ) ;
}
static int
F_122 ( struct V_32 * V_33 )
{
int V_99 ;
char * V_170 , * V_161 ;
V_170 = F_119 ( V_33 -> V_49 . V_24 , V_33 -> V_49 . V_23 ) ;
if ( ! V_170 ) {
F_9 ( L_49 , V_119 ) ;
return - V_4 ;
}
V_161 = F_115 ( & V_33 -> V_49 ) ;
V_99 = F_116 ( L_52 , V_170 , V_161 ) ;
F_17 ( V_161 ) ;
F_17 ( V_170 ) ;
return V_99 ;
}
int
F_123 ( struct V_36 * V_36 )
{
int V_22 ;
struct V_91 V_91 ;
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
if ( V_44 -> V_171 )
goto V_172;
V_44 -> V_171 = & V_173 ;
V_22 = V_44 -> V_171 -> V_174 ( V_36 ) ;
if ( ! V_22 )
return V_22 ;
V_44 -> V_171 = & V_175 ;
V_22 = F_70 ( F_73 () , V_92 , & V_91 ) ;
if ( ! V_22 ) {
V_22 = F_71 ( V_91 . V_39 -> V_51 -> V_94 ) ;
F_72 ( & V_91 ) ;
if ( V_22 )
goto V_172;
}
V_44 -> V_171 = & V_176 ;
F_20 ( V_177 L_53
L_54
L_55 ) ;
V_172:
V_22 = V_44 -> V_171 -> V_174 ( V_36 ) ;
if ( V_22 ) {
F_20 ( V_177 L_56
L_57 , V_22 ) ;
V_44 -> V_171 = NULL ;
}
return V_22 ;
}
void
F_21 ( struct V_36 * V_36 )
{
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
if ( V_44 -> V_171 ) {
if ( V_44 -> V_171 -> exit )
V_44 -> V_171 -> exit ( V_36 ) ;
V_44 -> V_171 = NULL ;
}
}
void
F_124 ( struct V_32 * V_33 )
{
struct V_43 * V_44 = F_23 ( V_33 -> V_36 , V_45 ) ;
if ( V_44 -> V_171 )
V_44 -> V_171 -> V_178 ( V_33 ) ;
}
void
F_125 ( struct V_32 * V_33 )
{
struct V_43 * V_44 = F_23 ( V_33 -> V_36 , V_45 ) ;
if ( V_44 -> V_171 )
V_44 -> V_171 -> remove ( V_33 ) ;
}
int
F_126 ( struct V_32 * V_33 )
{
struct V_43 * V_44 = F_23 ( V_33 -> V_36 , V_45 ) ;
if ( V_44 -> V_171 )
return V_44 -> V_171 -> V_179 ( V_33 ) ;
return - V_180 ;
}
void
F_127 ( struct V_43 * V_44 , T_4 V_80 )
{
if ( V_44 -> V_171 )
V_44 -> V_171 -> V_181 ( V_44 , V_80 ) ;
}
static int
F_128 ( struct V_182 * V_183 , unsigned long V_184 , void * V_185 )
{
struct V_126 * V_127 = V_185 ;
struct V_36 * V_36 = V_127 -> V_116 ;
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
struct V_117 * V_118 = V_44 -> V_117 ;
struct V_39 * V_39 ;
int V_99 = 0 ;
if ( ! F_129 ( V_186 ) )
return 0 ;
if ( ! V_118 ) {
F_130 ( V_186 ) ;
return 0 ;
}
switch ( V_184 ) {
case V_187 :
V_39 = F_91 ( V_127 , V_118 -> V_130 ) ;
if ( F_11 ( V_39 ) ) {
V_99 = F_12 ( V_39 ) ;
break;
}
V_118 -> V_130 -> V_39 = V_39 ;
break;
case V_188 :
if ( V_118 -> V_130 -> V_39 )
F_95 ( V_118 -> V_130 ) ;
break;
default:
V_99 = - V_189 ;
break;
}
F_130 ( V_186 ) ;
return V_99 ;
}
int
F_131 ( void )
{
return F_132 ( & V_190 ) ;
}
void
F_133 ( void )
{
F_134 ( & V_190 ) ;
}
