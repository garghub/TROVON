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
F_26 ( & V_40 -> V_52 -> V_53 ) ;
V_39 = F_27 ( V_14 , V_40 , V_38 - 1 ) ;
if ( F_11 ( V_39 ) ) {
V_22 = F_12 ( V_39 ) ;
goto V_54;
}
if ( V_39 -> V_52 )
goto V_55;
V_22 = F_28 ( V_40 -> V_52 , V_39 , V_56 ) ;
V_55:
F_29 ( V_39 ) ;
V_54:
F_30 ( & V_40 -> V_52 -> V_53 ) ;
if ( V_22 == 0 ) {
if ( V_44 -> V_57 ) {
V_42 = F_31 ( V_14 , V_44 ) ;
if ( V_42 )
V_42 -> V_58 = V_33 ;
}
F_32 ( V_44 -> V_48 , 0 ) ;
} else {
F_20 ( V_34 L_7
L_8
L_9 , V_22 ,
V_59 ) ;
}
F_33 ( V_44 -> V_48 ) ;
V_50:
F_5 ( V_37 ) ;
}
static int
F_34 ( void * V_60 , const char * V_61 , int V_62 ,
T_1 V_63 , T_2 V_64 , unsigned int V_65 )
{
struct V_66 * V_67 = V_60 ;
struct V_68 * V_69 ;
if ( V_62 != V_38 - 1 )
return 0 ;
V_69 = F_14 ( sizeof( struct V_68 ) , V_30 ) ;
if ( V_69 == NULL )
return - V_4 ;
memcpy ( V_69 -> V_61 , V_61 , V_38 - 1 ) ;
V_69 -> V_61 [ V_38 - 1 ] = '\0' ;
F_35 ( & V_69 -> V_70 , & V_67 -> V_71 ) ;
return 0 ;
}
static int
F_36 ( T_3 * V_72 , struct V_43 * V_44 )
{
const struct V_1 * V_37 ;
struct V_39 * V_40 = V_44 -> V_48 -> V_51 . V_39 ;
struct V_66 V_67 = {
. V_67 . V_73 = F_34 ,
. V_71 = F_37 (ctx.names)
} ;
int V_22 ;
V_22 = F_1 ( & V_37 ) ;
if ( V_22 < 0 )
return V_22 ;
V_22 = F_38 ( V_44 -> V_48 , 0 , V_74 ) ;
if ( V_22 < 0 ) {
F_5 ( V_37 ) ;
return V_22 ;
}
V_22 = F_39 ( V_44 -> V_48 , & V_67 . V_67 ) ;
F_40 ( & V_40 -> V_52 -> V_53 , V_75 ) ;
while ( ! F_41 ( & V_67 . V_71 ) ) {
struct V_68 * V_69 ;
V_69 = F_42 ( V_67 . V_71 . V_76 , struct V_68 , V_70 ) ;
if ( ! V_22 ) {
struct V_39 * V_39 ;
V_39 = F_27 ( V_69 -> V_61 , V_40 , V_38 - 1 ) ;
if ( F_11 ( V_39 ) ) {
V_22 = F_12 ( V_39 ) ;
break;
}
V_22 = V_72 ( V_40 , V_39 , V_44 ) ;
F_29 ( V_39 ) ;
}
F_43 ( & V_69 -> V_70 ) ;
F_17 ( V_69 ) ;
}
F_30 ( & V_40 -> V_52 -> V_53 ) ;
F_5 ( V_37 ) ;
return V_22 ;
}
static int
F_44 ( char * V_61 , int V_62 , struct V_43 * V_44 )
{
struct V_39 * V_40 , * V_39 ;
int V_22 ;
F_9 ( L_10 , V_62 , V_61 ) ;
V_40 = V_44 -> V_48 -> V_51 . V_39 ;
F_40 ( & V_40 -> V_52 -> V_53 , V_75 ) ;
V_39 = F_27 ( V_61 , V_40 , V_62 ) ;
if ( F_11 ( V_39 ) ) {
V_22 = F_12 ( V_39 ) ;
goto V_54;
}
V_22 = - V_35 ;
if ( ! V_39 -> V_52 )
goto V_10;
V_22 = F_45 ( V_40 -> V_52 , V_39 ) ;
V_10:
F_29 ( V_39 ) ;
V_54:
F_30 ( & V_40 -> V_52 -> V_53 ) ;
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
goto V_77;
V_22 = F_44 ( V_14 , V_38 - 1 , V_44 ) ;
F_5 ( V_37 ) ;
if ( V_22 == 0 ) {
F_32 ( V_44 -> V_48 , 0 ) ;
if ( V_44 -> V_57 ) {
V_42 = F_49 ( V_14 , V_44 ) ;
if ( V_42 )
F_50 ( V_42 , V_44 ) ;
}
}
V_77:
F_33 ( V_44 -> V_48 ) ;
V_10:
if ( V_22 )
F_20 ( L_11
L_12 , V_38 , V_14 ) ;
}
static int
F_51 ( struct V_39 * V_78 , struct V_39 * V_79 , struct V_43 * V_44 )
{
int V_22 ;
if ( F_52 ( V_79 -> V_80 . V_61 , V_44 ) )
return 0 ;
V_22 = F_45 ( V_78 -> V_52 , V_79 ) ;
if ( V_22 )
F_20 ( L_13 ,
V_79 ) ;
return 0 ;
}
static void
F_53 ( struct V_43 * V_44 )
{
int V_22 ;
V_44 -> V_57 = false ;
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
F_20 ( L_14
L_15 , V_44 -> V_48 ) ;
}
static int
F_55 ( struct V_39 * V_78 , struct V_39 * V_79 , struct V_43 * V_44 )
{
if ( V_79 -> V_80 . V_23 != V_38 - 1 ) {
F_20 ( L_16 ,
V_79 ) ;
return 0 ;
}
F_31 ( V_79 -> V_80 . V_61 , V_44 ) ;
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
F_20 ( L_17
L_15 , V_44 -> V_48 ) ;
return V_22 ;
}
static int
F_57 ( struct V_36 * V_36 )
{
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
const struct V_1 * V_37 ;
int V_22 ;
F_20 ( L_18 ,
V_59 ) ;
F_58 ( V_44 -> V_48 ) ;
V_22 = F_1 ( & V_37 ) ;
if ( V_22 < 0 ) {
F_20 ( L_19
L_20 ,
V_22 ) ;
return V_22 ;
}
V_44 -> V_48 = F_59 ( V_59 , V_81 | V_82 , 0 ) ;
if ( F_11 ( V_44 -> V_48 ) ) {
F_20 ( L_21 ,
V_59 ) ;
V_22 = F_12 ( V_44 -> V_48 ) ;
V_44 -> V_48 = NULL ;
}
F_5 ( V_37 ) ;
if ( ! V_22 )
V_44 -> V_57 = true ;
return V_22 ;
}
static void
F_60 ( struct V_36 * V_36 )
{
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
if ( ! V_44 -> V_48 )
return;
F_61 ( V_44 -> V_48 ) ;
V_44 -> V_48 = NULL ;
}
static int
F_62 ( struct V_36 * V_36 )
{
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
int V_12 ;
V_44 -> V_83 = F_14 ( sizeof( struct V_84 ) *
V_85 , V_30 ) ;
if ( ! V_44 -> V_83 )
return - V_4 ;
for ( V_12 = 0 ; V_12 < V_85 ; V_12 ++ )
F_63 ( & V_44 -> V_83 [ V_12 ] ) ;
V_44 -> V_86 = 0 ;
return 0 ;
}
static void
F_64 ( struct V_36 * V_36 )
{
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
F_17 ( V_44 -> V_83 ) ;
}
static int
F_65 ( struct V_36 * V_36 )
{
int V_22 ;
V_22 = F_57 ( V_36 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_56 ( V_36 ) ;
if ( V_22 )
F_60 ( V_36 ) ;
return V_22 ;
}
static int
F_66 ( struct V_36 * V_36 )
{
int V_22 ;
if ( V_36 != & V_87 ) {
F_67 ( 1 , V_34 L_22
L_23 ) ;
return - V_88 ;
}
V_22 = F_62 ( V_36 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_65 ( V_36 ) ;
if ( V_22 )
goto V_89;
return 0 ;
V_89:
F_64 ( V_36 ) ;
return V_22 ;
}
static void
F_68 ( struct V_36 * V_36 )
{
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
F_54 ( V_44 ) ;
F_60 ( V_36 ) ;
F_64 ( V_36 ) ;
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
if ( F_71 ( V_91 . V_39 -> V_52 -> V_94 ) ) {
strcpy ( V_59 , V_90 ) ;
V_22 = 0 ;
}
F_72 ( & V_91 ) ;
return V_22 ;
}
char *
F_73 ( void )
{
return V_59 ;
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
V_42 -> V_58 = V_33 ;
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
static T_4
F_81 ( struct V_106 * V_107 , const char T_5 * V_108 , T_6 V_109 )
{
struct V_110 * V_111 , * V_112 ;
struct V_97 T_5 * V_98 = (struct V_97 T_5 * ) V_108 ;
T_7 V_113 ;
struct V_43 * V_44 = F_23 ( V_107 -> V_114 -> V_115 -> V_116 ,
V_45 ) ;
struct V_117 * V_118 = V_44 -> V_117 ;
if ( V_109 != sizeof( * V_98 ) ) {
F_9 ( L_24 , V_119 , V_109 ,
sizeof( * V_98 ) ) ;
return - V_88 ;
}
if ( F_82 ( & V_113 , & V_98 -> V_120 , sizeof( V_113 ) ) != 0 ) {
F_9 ( L_25 , V_119 ) ;
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
F_9 ( L_26 , V_119 , V_113 ) ;
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
F_63 ( & V_118 -> V_133 ) ;
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
F_20 ( V_34 L_27 ,
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
F_9 ( L_28 , V_119 , V_3 -> V_123 . V_120 ) ;
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
F_20 ( V_34 L_29
L_30 , V_99 ) ;
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
F_20 ( V_34 L_31
L_32 , V_99 ) ;
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
F_20 ( V_34 L_33
L_34 , - V_4 ) ;
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
F_113 ( struct V_43 * V_44 )
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
V_112 -> V_123 . V_145 . V_153 = ( V_154 ) V_44 -> V_155 ;
V_99 = F_80 ( V_118 -> V_130 , & V_112 -> V_123 ) ;
if ( ! V_99 )
V_99 = V_112 -> V_123 . V_149 ;
F_109 ( V_112 ) ;
V_142:
if ( V_99 )
F_20 ( V_34 L_35 , V_99 ) ;
}
static char *
F_114 ( void )
{
int V_156 ;
T_6 V_23 ;
char * V_157 ;
if ( V_158 )
return NULL ;
V_23 = strlen ( V_159 ) +
strlen ( F_73 () ) + 1 ;
V_157 = F_14 ( V_23 , V_30 ) ;
if ( ! V_157 )
return V_157 ;
V_156 = snprintf ( V_157 , V_23 , V_159 L_36 ,
F_73 () ) ;
if ( V_156 >= V_23 ) {
F_17 ( V_157 ) ;
return NULL ;
}
return V_157 ;
}
static char *
F_115 ( const struct V_15 * V_61 )
{
int V_156 ;
T_6 V_23 ;
char * V_157 ;
if ( V_158 )
return NULL ;
V_23 = strlen ( V_160 ) +
strlen ( F_73 () ) + 1 + V_38 ;
V_157 = F_14 ( V_23 , V_30 ) ;
if ( ! V_157 )
return V_157 ;
V_156 = snprintf ( V_157 , V_23 , V_160 L_37 ,
F_73 () ) ;
if ( V_156 > ( V_23 - V_38 ) ) {
F_17 ( V_157 ) ;
return NULL ;
}
V_156 = F_8 ( V_157 + V_156 , V_61 ) ;
if ( V_156 ) {
F_17 ( V_157 ) ;
return NULL ;
}
return V_157 ;
}
static char *
F_116 ( struct V_32 * V_33 )
{
int V_156 ;
T_6 V_23 ;
char * V_157 ;
V_23 = strlen ( V_161 ) + 1 + 1 ;
V_157 = F_14 ( V_23 , V_30 ) ;
if ( ! V_157 )
return V_157 ;
V_156 = snprintf ( V_157 , V_23 , V_161 L_38 ,
V_33 -> V_162 ? 'Y' : 'N' ) ;
if ( V_156 >= V_23 ) {
F_17 ( V_157 ) ;
return NULL ;
}
return V_157 ;
}
static char *
F_117 ( T_8 V_163 )
{
int V_156 ;
T_6 V_23 ;
char * V_157 ;
V_23 = strlen ( V_164 ) + 22 + 1 ;
V_157 = F_14 ( V_23 , V_30 ) ;
if ( ! V_157 )
return V_157 ;
V_156 = snprintf ( V_157 , V_23 , V_164 L_39 ,
V_163 ) ;
if ( V_156 >= V_23 ) {
F_17 ( V_157 ) ;
return NULL ;
}
return V_157 ;
}
static int
F_118 ( char * V_165 , char * V_60 , char * V_166 , char * V_167 )
{
char * V_168 [ 3 ] ;
char * V_169 [ 4 ] ;
int V_99 ;
if ( F_119 ( ! V_170 [ 0 ] ) ) {
F_9 ( L_40 , V_119 ) ;
return - V_171 ;
}
F_9 ( L_41 , V_119 , V_165 ) ;
F_9 ( L_42 , V_119 , V_60 ? V_60 : L_43 ) ;
F_9 ( L_44 , V_119 , V_166 ? V_166 : L_43 ) ;
F_9 ( L_45 , V_119 , V_167 ? V_167 : L_43 ) ;
V_168 [ 0 ] = V_166 ;
V_168 [ 1 ] = V_167 ;
V_168 [ 2 ] = NULL ;
V_169 [ 0 ] = ( char * ) V_170 ;
V_169 [ 1 ] = V_165 ;
V_169 [ 2 ] = V_60 ;
V_169 [ 3 ] = NULL ;
V_99 = F_120 ( V_169 [ 0 ] , V_169 , V_168 , V_172 ) ;
if ( V_99 == - V_35 || V_99 == - V_171 ) {
F_9 ( L_46
L_47 ,
V_170 , V_99 ) ;
V_170 [ 0 ] = '\0' ;
}
F_9 ( L_48 , V_119 , V_170 , V_99 ) ;
return V_99 ;
}
static char *
F_121 ( const unsigned char * V_108 , int V_173 )
{
int V_12 ;
char * V_174 , * V_175 ;
V_174 = F_14 ( ( V_173 * 2 ) + 1 , V_30 ) ;
if ( ! V_174 )
return V_174 ;
V_175 = V_174 ;
for ( V_12 = 0 ; V_12 < V_173 ; V_12 ++ ) {
sprintf ( V_175 , L_49 , * V_108 ++ ) ;
V_175 += 2 ;
}
return V_174 ;
}
static int
F_122 ( struct V_36 * V_36 )
{
int V_99 ;
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
char * V_163 = F_117 ( V_44 -> V_155 ) ;
if ( V_36 != & V_87 ) {
F_67 ( 1 , V_34 L_50
L_23 ) ;
return - V_88 ;
}
V_99 = F_118 ( L_51 , NULL , V_163 , NULL ) ;
F_17 ( V_163 ) ;
return V_99 ;
}
static void
F_123 ( struct V_32 * V_33 )
{
F_124 ( & V_33 -> V_47 , V_176 ,
V_102 ) ;
}
static void
F_125 ( struct V_32 * V_33 )
{
F_126 () ;
F_48 ( V_176 , & V_33 -> V_47 ) ;
F_127 () ;
F_128 ( & V_33 -> V_47 , V_176 ) ;
}
static void
F_129 ( struct V_32 * V_33 )
{
char * V_177 , * V_178 , * V_163 ;
struct V_43 * V_44 = F_23 ( V_33 -> V_36 , V_45 ) ;
if ( V_33 -> V_162 == 0 &&
F_47 ( V_46 , & V_33 -> V_47 ) )
return;
V_177 = F_121 ( V_33 -> V_49 . V_24 , V_33 -> V_49 . V_23 ) ;
if ( ! V_177 ) {
F_9 ( L_52 , V_119 ) ;
return;
}
V_178 = F_116 ( V_33 ) ;
V_163 = F_117 ( V_44 -> V_155 ) ;
F_123 ( V_33 ) ;
if ( ! F_118 ( L_53 , V_177 , V_178 , V_163 ) )
F_75 ( V_46 , & V_33 -> V_47 ) ;
F_125 ( V_33 ) ;
F_17 ( V_178 ) ;
F_17 ( V_163 ) ;
F_17 ( V_177 ) ;
}
static void
F_130 ( struct V_32 * V_33 )
{
char * V_177 ;
if ( ! F_47 ( V_46 , & V_33 -> V_47 ) )
return;
V_177 = F_121 ( V_33 -> V_49 . V_24 , V_33 -> V_49 . V_23 ) ;
if ( ! V_177 ) {
F_9 ( L_52 , V_119 ) ;
return;
}
F_123 ( V_33 ) ;
if ( F_47 ( V_46 , & V_33 -> V_47 ) &&
F_118 ( L_54 , V_177 , NULL , NULL ) == 0 )
F_48 ( V_46 , & V_33 -> V_47 ) ;
F_125 ( V_33 ) ;
F_17 ( V_177 ) ;
}
static int
F_131 ( struct V_32 * V_33 )
{
int V_99 ;
char * V_177 , * V_178 , * V_179 ;
if ( F_47 ( V_46 , & V_33 -> V_47 ) )
return 0 ;
V_177 = F_121 ( V_33 -> V_49 . V_24 , V_33 -> V_49 . V_23 ) ;
if ( ! V_177 ) {
F_9 ( L_52 , V_119 ) ;
return - V_4 ;
}
V_178 = F_116 ( V_33 ) ;
V_179 = F_115 ( & V_33 -> V_49 ) ;
F_123 ( V_33 ) ;
if ( F_47 ( V_46 , & V_33 -> V_47 ) ) {
V_99 = 0 ;
} else {
V_99 = F_118 ( L_55 , V_177 , V_178 , V_179 ) ;
if ( V_99 == 0 )
F_75 ( V_46 , & V_33 -> V_47 ) ;
}
F_125 ( V_33 ) ;
F_17 ( V_178 ) ;
F_17 ( V_179 ) ;
F_17 ( V_177 ) ;
return V_99 ;
}
static void
F_132 ( struct V_43 * V_44 )
{
char * V_179 ;
char V_180 [ 22 ] ;
sprintf ( V_180 , L_39 , V_44 -> V_155 ) ;
V_179 = F_114 () ;
F_118 ( L_56 , V_180 , V_179 , NULL ) ;
F_17 ( V_179 ) ;
}
int
F_133 ( struct V_36 * V_36 )
{
int V_22 ;
struct V_91 V_91 ;
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
if ( V_44 -> V_181 )
goto V_182;
V_44 -> V_181 = & V_183 ;
V_22 = V_44 -> V_181 -> V_184 ( V_36 ) ;
if ( ! V_22 )
return V_22 ;
V_44 -> V_181 = & V_185 ;
V_22 = F_70 ( F_73 () , V_92 , & V_91 ) ;
if ( ! V_22 ) {
V_22 = F_71 ( V_91 . V_39 -> V_52 -> V_94 ) ;
F_72 ( & V_91 ) ;
if ( V_22 )
goto V_182;
}
V_44 -> V_181 = & V_186 ;
F_20 ( V_187 L_57
L_58
L_59 ) ;
V_182:
V_22 = V_44 -> V_181 -> V_184 ( V_36 ) ;
if ( V_22 ) {
F_20 ( V_187 L_60
L_61 , V_22 ) ;
V_44 -> V_181 = NULL ;
}
return V_22 ;
}
void
F_21 ( struct V_36 * V_36 )
{
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
if ( V_44 -> V_181 ) {
if ( V_44 -> V_181 -> exit )
V_44 -> V_181 -> exit ( V_36 ) ;
V_44 -> V_181 = NULL ;
}
}
void
F_134 ( struct V_32 * V_33 )
{
struct V_43 * V_44 = F_23 ( V_33 -> V_36 , V_45 ) ;
if ( V_44 -> V_181 )
V_44 -> V_181 -> V_188 ( V_33 ) ;
}
void
F_135 ( struct V_32 * V_33 )
{
struct V_43 * V_44 = F_23 ( V_33 -> V_36 , V_45 ) ;
if ( V_44 -> V_181 )
V_44 -> V_181 -> remove ( V_33 ) ;
}
int
F_136 ( struct V_32 * V_33 )
{
struct V_43 * V_44 = F_23 ( V_33 -> V_36 , V_45 ) ;
if ( V_44 -> V_181 )
return V_44 -> V_181 -> V_189 ( V_33 ) ;
return - V_190 ;
}
void
F_137 ( struct V_43 * V_44 )
{
if ( V_44 -> V_181 )
V_44 -> V_181 -> V_191 ( V_44 ) ;
}
static int
F_138 ( struct V_192 * V_193 , unsigned long V_194 , void * V_195 )
{
struct V_126 * V_127 = V_195 ;
struct V_36 * V_36 = V_127 -> V_116 ;
struct V_43 * V_44 = F_23 ( V_36 , V_45 ) ;
struct V_117 * V_118 = V_44 -> V_117 ;
struct V_39 * V_39 ;
int V_99 = 0 ;
if ( ! F_139 ( V_196 ) )
return 0 ;
if ( ! V_118 ) {
F_140 ( V_196 ) ;
return 0 ;
}
switch ( V_194 ) {
case V_197 :
V_39 = F_91 ( V_127 , V_118 -> V_130 ) ;
if ( F_11 ( V_39 ) ) {
V_99 = F_12 ( V_39 ) ;
break;
}
V_118 -> V_130 -> V_39 = V_39 ;
break;
case V_198 :
if ( V_118 -> V_130 -> V_39 )
F_95 ( V_118 -> V_130 ) ;
break;
default:
V_99 = - V_199 ;
break;
}
F_140 ( V_196 ) ;
return V_99 ;
}
int
F_141 ( void )
{
return F_142 ( & V_200 ) ;
}
void
F_143 ( void )
{
F_144 ( & V_200 ) ;
}
